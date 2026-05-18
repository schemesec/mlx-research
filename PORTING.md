# Porting Notes

The goal is a Proxmox VE 7 ConnectX-3 Pro / MLNX_OFED port that keeps the
surrounding Proxmox kernel driver stack usable wherever possible.

## Current Architecture Problem

The current installer builds and installs a matched OFED RDMA stack:

- OFED `ib_core`
- OFED `rdma_cm`
- OFED `ib_uverbs`
- OFED `mlx4_core`
- OFED `mlx4_en`
- OFED `mlx4_ib`

That works for the validated RoCEv2 PF/VF tests, but it changes the public RDMA
kernel ABI. Stock Proxmox upper-layer modules such as `nvme-rdma`, `nvmet-rdma`,
`ib_ipoib`, `ib_srp`, and `ib_isert` were built against the stock Proxmox RDMA
ABI and therefore do not load cleanly against the OFED `ib_core`/`rdma_cm`.

The preferred direction is not to hide those failures and not to immediately
replace every upper-layer module. The preferred direction is to keep the stock
Proxmox RDMA core ABI where feasible and port the CX3/mlx4 driver pieces to
that ABI.

## Architecture Options

### Option A: Replacement OFED Stack

Build and install the whole OFED stack, including RDMA core and upper-layer
modules.

Pros:

- closest to standard MLNX_OFED packaging
- easiest way to get matching symbol CRCs within the OFED module family

Cons:

- replaces a large part of the Proxmox RDMA stack
- requires matching OFED `nvme-rdma`, `nvmet-rdma`, `ib_ipoib`, `ib_srp`,
  `ib_isert`, and related modules
- less compatible with stock Proxmox modules

### Option B: Stock RDMA ABI With Ported mlx4

Keep stock Proxmox RDMA core modules and build a matched OFED mlx4 driver set
against that ABI:

- OFED `mlx4_core`
- OFED `mlx4_en`
- OFED `mlx4_ib`
- stock `ib_core`
- stock `rdma_cm`
- stock upper-layer modules where possible

Pros:

- best match for the project goal
- preserves stock `nvme-rdma`, `nvmet-rdma`, `ib_ipoib`, `ib_srp`, etc. if the
  port is successful
- keeps the blast radius smaller than a full RDMA core replacement

Cons:

- harder driver port
- OFED mlx4 source expects OFED/backport headers
- `mlx4_ib` must be adapted to the stock Proxmox RDMA public API
- `mlx4_core` and `mlx4_ib` must remain mutually ABI-compatible with each other

## Probe Results

### Stock Upper Modules Against Current OFED Core

`audit-module-compat.sh` shows broad RDMA ABI conflicts, not just a single
missing helper. Examples:

- stock `nvme-rdma` / `nvmet-rdma`: 66 conflicts
- stock `ib_ipoib`: 48 conflicts
- stock `ib_srp`: 37 conflicts
- stock `ib_isert`: 27 conflicts
- stock `rdma_rxe`: 27 conflicts

Most are symbol CRC mismatches, which means the public prototypes or types seen
by module versioning do not match. Wrappers can fix missing exports, but not
CRC mismatches unless the exported ABI is made genuinely compatible.

### Stock ABI Build Probe

An experimental compile of OFED `mlx4_core`/`mlx4_en` against stock kernel
headers reached source compilation only after forcing OFED `linux/mlx4` headers
ahead of the stock headers. Without the OFED mlx4 headers, the build fails on
type/prototype mismatches such as:

- missing `enum mlx4_roce_gid_type`
- missing RoCE GID table structures
- incompatible `mlx4_buf_alloc`
- incompatible `mlx4_db_alloc`
- incompatible `mlx4_buf_write_mtt`

Adding OFED compatibility headers fixes some old/new kernel API issues, but a
simple include overlay is not enough. It creates other header-order problems.

Replacing both `include/rdma` and `include/uapi/rdma` with the stock Proxmox
header trees lets the OFED `mlx4_core` and `mlx4_en` objects compile and link in
a throwaway tree, but the full top-level build still fails because it tries to
compile OFED `ib_core` against stock RDMA headers. That is expected for Option
B: the stock-RDMA build mode must avoid building OFED RDMA core.

An isolated `mlx4_ib` build with `CONFIG_MLX4_IB_STOCK_RDMA_ABI=y` now gets past
the first OFED experimental verbs include failure. The next known stock-RDMA ABI
gaps are in `mlx4_ib.h`:

- `struct ib_fmr` / `struct mlx4_fmr` assumptions
- `IB_QP_CREATE_USE_GFP_NOIO`
- `enum ib_qpg_type`

Those are OFED-era interfaces that need to be gated, mapped to stock Proxmox
equivalents, or removed from the stock-RDMA build mode.

After gating those interfaces and adding stock-RDMA mappings for CQ and
doorbell user-memory handling, the isolated `mlx4_ib` build reaches `mad.o`.
The current blocker is the mlx4 counter/stat API used by `mad.c`
(`mlx4_counter.basic/ext`, `MLX4_IF_CNT_MODE_*`, `struct mlx4_if_stat_*`) plus
`mlx4_vlan_blocked`.

That blocker also shows that the isolated `M=drivers/infiniband/hw/mlx4` probe
is still resolving some stock kernel `linux/mlx4` headers. The intended Option B
shape is not "OFED mlx4_ib against stock mlx4_core"; it is the matched OFED
`mlx4_core`/`mlx4_en`/`mlx4_ib` family against the stock Proxmox RDMA public
ABI. The build mode therefore needs to force the matched OFED `linux/mlx4`
headers while using stock `include/rdma` and `include/uapi/rdma`.

Re-running the isolated `mlx4_ib` build with OFED mlx4 include ordering confirms
that `mad.o` compiles. The next failures are real stock RDMA core API drift in
`main.c`, mainly:

- `ib_device_ops` callback signatures that changed from `u8` port numbers to
  `u32` port numbers
- stock `process_mad` signature differences
- stock registration metadata living in `ib_device_ops` instead of direct
  `struct ib_device` fields such as `owner`, `driver_id`, and `uverbs_abi_ver`
- missing OFED-only `uverbs_ex_cmd_mask` and experimental userspace verbs fields
- stock `ib_register_device()` requiring the DMA parent device argument

These are compatibility adapter work items. They should be fixed by mapping the
OFED mlx4 implementation onto the stock Proxmox RDMA API, not by suppressing
warnings or disabling error paths.

The next adapter pass started moving `mlx4_ib` toward the stock RDMA object
model:

- `ib_device_ops` metadata is populated in the ops table for stock-RDMA mode
- port-number callbacks use stock `u32` signatures
- `mlx4_ib_create_ah()` uses `struct rdma_ah_init_attr` in stock-RDMA mode
- `mlx4_ib_create_cq()` uses the stock core-owned CQ object model in
  stock-RDMA mode
- `mlx4_ib_dealloc_pd()` returns an error code as expected by stock RDMA core

After those changes, the isolated build gets past `ah.c` and `cq.c`. The
remaining compile blockers are concentrated in:

- flow steering field/domain API drift (`struct ib_flow_ib_filter`,
  `IB_FLOW_DOMAIN_*`)
- hardware stats API drift (`alloc_hw_port_stats` /
  `alloc_hw_device_stats`, `struct rdma_stat_desc`)
- MAD processing signature drift
- `rereg_user_mr` return type drift
- stock core-owned object allocation for RWQ indirection tables and XRCDs
- `create_flow` signature drift

The next stock-RDMA adapter pass moved the isolated `mlx4_ib` build through
those blockers in the throwaway probe tree:

- flow steering creation now maps the OFED fields/domains onto the stock RDMA
  flow API where the public structures differ
- hardware stats allocation now uses stock `alloc_hw_device_stats` /
  `alloc_hw_port_stats` and `struct rdma_stat_desc`
- MAD, memory region, memory window, XRCD, RWQ indirection table, SRQ, and QP
  callbacks now have stock-RDMA signatures under `CONFIG_MLX4_IB_STOCK_RDMA_ABI`
- user memory pinning paths use the stock `ib_umem_get()` /
  `ib_umem_num_dma_blocks()` API in stock-RDMA mode
- the SA alias GUID query call is mapped to the stock
  `ib_sa_guid_info_rec_query()` signature

With those local changes copied into `/tmp/mlx-research-stock-rdma3` on pvs3,
the isolated stock-RDMA `mlx4_ib.ko` build completed. A follow-up clean probe in
`/tmp/mlx-research-stock-rdma4` then built the matched driver family:

- `mlx_compat.ko`
- `mlx4_core.ko`
- `mlx4_en.ko`
- `mlx4_ib.ko` with `CONFIG_MLX4_IB_STOCK_RDMA_ABI=y`

The matched-family build requires `mlx_compat.ko` because the OFED backport
headers intentionally add a module dependency through
`backport_dependency_symbol`. It also requires `CONFIG_COMPAT_EN_SYSFS=y` so
`mlx4_en` links the sysfs implementation that its source references. The
remaining output from that probe was non-fatal missing-prototype / indentation
warnings plus the expected BTF skip because the Proxmox header package does not
provide `vmlinux`.

The manual probe has been captured as `build-stock-rdma-probe.sh`. It creates a
throwaway build tree, overlays stock Proxmox RDMA headers, preserves the matched
OFED mlx4 headers, and builds the stock-RDMA mlx4 module set without installing
anything.

This is still only a build probe. It has not been installed or boot-tested in
the stock-RDMA architecture, and RSS/QP-group experimental verbs are currently
not wired into the stock-RDMA object model.

## Next Implementation Direction

Create a deliberate stock-RDMA-ABI build mode instead of continuing with ad hoc
include path probes.

That build mode should:

1. Use OFED/backport kernel compatibility headers where needed for mlx4 source.
2. Use OFED `linux/mlx4` headers for the matched OFED mlx4 family.
3. Use stock Proxmox `include/rdma/*` headers for `mlx4_ib` so the module is
   built against the stock RDMA ABI.
4. Build `mlx_compat`, `mlx4_core`, `mlx4_en`, and `mlx4_ib` together.
5. Install only that mlx4/backport set at first, leaving stock `ib_core`, `rdma_cm`,
   `ib_uverbs`, and upper-layer modules in place.
6. Test whether stock `nvme-rdma`, `nvmet-rdma`, `ib_ipoib`, and other upper
   modules load without ABI conflicts.

If this direction fails because OFED RoCEv2 support requires RDMA core changes
that cannot be isolated to `mlx4_ib`, then the fallback is Option A: build and
install the matching OFED upper-layer modules as a replacement stack.
