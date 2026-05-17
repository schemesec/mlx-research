# Feature Status

This project is intended to become a full-featured Proxmox VE 7 port of the
MLNX_OFED ConnectX-3 Pro stack, not only a narrow RoCE traffic smoke test.

The current tested state is narrower than that goal. Anything in this file that
is marked missing or unvalidated should be treated as not supported by this port
until it is built, installed, and tested against the ported RDMA core.

## Current Validated Scope

The following pieces are built, installed from
`/lib/modules/7.0.2-2-pve/updates/mlnx-ofed-cx3`, and validated on `pvs3`:

- `mlx_compat.ko`
- `ib_core.ko`
- `ib_cm.ko`
- `iw_cm.ko`
- `rdma_cm.ko`
- `rdma_ucm.ko`
- `ib_ucm.ko`
- `ib_umad.ko`
- `ib_uverbs.ko`
- `mlx4_core.ko`
- `mlx4_en.ko`
- `mlx4_ib.ko`
- `rpcrdma.ko`
- `ib_iser.ko`

Validated behavior:

- CX3 Pro firmware `2.42.5000`
- mlx4 RoCEv2 default via `roce_mode=2` and `ud_gid_type=2`
- PF RoCEv2 GIDs
- host-owned VF RoCEv2 GIDs
- SR-IOV VF VLAN assignment
- stable VF MAC assignment
- local PF-to-VF `ib_write_bw`
- cross-host PF RoCEv2 `ib_write_bw`
- cross-host VF RoCEv2 `ib_write_bw`
- clean bounded boot/runtime warning scan after the validated install path

## Required But Not Yet Ported

These are required for the full project goal and currently do not work as part
of the port.

| Feature | Current status | Required next step |
| --- | --- | --- |
| NVMe/RDMA host | Stock `nvme-rdma.ko` fails against the ported RDMA core with symbol-version and missing-symbol errors. | Build and install matching OFED `nvme-core.ko`, `nvme-fabrics.ko`, and `nvme-rdma.ko`. |
| NVMe/RDMA target | Stock `nvmet-rdma.ko` fails against the ported RDMA core with symbol-version and missing-symbol errors. | Build and install matching OFED `nvmet.ko` and `nvmet-rdma.ko`. |
| IPoIB | Not installed from this port. Stock `ib_ipoib.ko` is intentionally blocked because it does not match the ported `ib_core`. | Port, build, install, and test matching `ib_ipoib.ko`. |
| SRP initiator | Stock `ib_srp.ko` is still the module selected by `modinfo`. | Build and test matching OFED `ib_srp.ko` if SRP is needed. |
| SRP target | Not built or installed from this port. | Build and test `ib_srpt.ko` if SRP target mode is needed. |
| iSER target | Stock `ib_isert.ko` is still the module selected by `modinfo`. | Build and test matching OFED `ib_isert.ko` if iSER target mode is needed. |
| RXE | Stock `rdma_rxe.ko` is still the module selected by `modinfo`. | Usually not needed for CX3 Pro hardware RoCE, but build/test matching OFED RXE if required. |
| NFS/RDMA server | `rpcrdma.ko` is installed, but server-side `svcrdma.ko` currently aliases to that installed module path and has not been separately validated. | Confirm expected OFED module naming and test NFS/RDMA server mode before claiming support. |

## Flow Steering And Offloads

Current live mlx4 module parameters on `pvs3` after the validated setup:

- `log_num_mgm_entry_size=-7`
- `high_rate_steer=0`
- `enable_qos=N`
- `enable_vfs_qos=N`
- `use_prio=N`
- `log_num_vlan=0`

Current live private flags showed:

- `mlx4_flow_steering_ethernet_l2: on`
- `mlx4_flow_steering_ipv4: off`
- `mlx4_flow_steering_tcp: off`
- `mlx4_flow_steering_udp: off`

The mlx4 source exposes module parameters and paths for DMFS, optimized
steering, QoS, VF QoS, VLAN priority steering, VLAN table sizing, and VXLAN
offload controls. These have not yet been tuned or validated for this port.

Next flow-steering/offload work:

- test `log_num_mgm_entry_size` DMFS bit combinations from the mlx4 parameter
  description
- test `enable_qos=1`
- test `enable_vfs_qos=1`
- test `use_prio=1` only if VLAN priority steering is specifically needed
- test a nonzero `log_num_vlan` if larger VLAN table resources are needed
- verify private flow steering flags after reboot
- verify `ethtool -n` and `ethtool -N` behavior
- verify no boot/runtime warnings after each option change

Some modern `ethtool -k` names are not realistic ConnectX-3 Pro targets. TLS,
IPsec, and `hw-tc-offload` style features are primarily mlx5/newer-kernel
features unless Mellanox documentation or firmware capability output proves
otherwise for this hardware.

## Known Bad Compatibility

Do not load stock Proxmox RDMA upper-layer modules against the ported OFED
`ib_core` unless they have been explicitly tested. The stock NVMe/RDMA modules
already proved incompatible with this port.

Known failing stock modules:

- `/lib/modules/7.0.2-2-pve/kernel/drivers/nvme/host/nvme-rdma.ko`
- `/lib/modules/7.0.2-2-pve/kernel/drivers/nvme/target/nvmet-rdma.ko`

The observed failure is real: `Unknown symbol` and `disagrees about version of
symbol` errors against the ported RDMA core. Those errors must be fixed by
building matching modules, not hidden by verifier filtering.
