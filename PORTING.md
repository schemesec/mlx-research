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

## Next Implementation Direction

Create a deliberate stock-RDMA-ABI build mode instead of continuing with ad hoc
include path probes.

That build mode should:

1. Use OFED/backport kernel compatibility headers where needed for mlx4 source.
2. Use OFED `linux/mlx4` headers for the matched OFED mlx4 family.
3. Use stock Proxmox `include/rdma/*` headers for `mlx4_ib` so the module is
   built against the stock RDMA ABI.
4. Build `mlx4_core`, `mlx4_en`, and `mlx4_ib` together.
5. Install only the mlx4 family at first, leaving stock `ib_core`, `rdma_cm`,
   `ib_uverbs`, and upper-layer modules in place.
6. Test whether stock `nvme-rdma`, `nvmet-rdma`, `ib_ipoib`, and other upper
   modules load without ABI conflicts.

If this direction fails because OFED RoCEv2 support requires RDMA core changes
that cannot be isolated to `mlx4_ib`, then the fallback is Option A: build and
install the matching OFED upper-layer modules as a replacement stack.
