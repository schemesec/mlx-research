# Tested State

This repository is experimental and was created with AI assistance for testing
only. Do not treat this as production-ready driver packaging.

## pvs3

- Date checked: 2026-05-17
- Host: `pvs3`
- Kernel: `7.0.2-2-pve`
- Repo commit: `e09d07f`
- CX3 Pro firmware: `2.42.5000`
- PF: `enp23s0`
- VFs: `8`
- VF VLAN: `20`
- PF VLAN IPs:
  - `enp23s0.10`: `192.168.10.56/24`
  - `enp23s0.20`: `192.168.20.56/24`

Validated outcomes:

- `verify-pve7.sh`: `PASS`
- `mlx4_core`, `mlx4_en`, `mlx4_ib`, `ib_core`, `rdma_cm`, and `ib_uverbs`
  resolve to `/lib/modules/7.0.2-2-pve/updates/mlnx-ofed-cx3`.
- `mlx4_core` live parameters:
  - `roce_mode=2`
  - `ud_gid_type=2`
  - `num_vfs=8,0,0`
  - `probe_vf=8,0,0`
  - `port_type_array=2,2`
- PF and VLAN interfaces expose nonzero RoCE v2 GIDs.
- Proxmox services remain active.
- PF RDMA device is active.
- Host-owned VFs expose host RDMA devices; VFs assigned to `vfio-pci` are
  treated as VM passthrough and are not expected to have host netdevs.
- VF netdev MACs are stable after reboot:
  - `02:9a:0a:d0:90:00` through `02:9a:0a:d0:90:07`
- All VFs are assigned VLAN 20.
- Bounded kernel warning scan is clean for:
  `BUG`, `Oops`, `WARNING`, `Call Trace`, `Unknown symbol`, `disagrees`,
  `__warn`, `fortify`, and `objtool`.

Manual VF RoCEv2 test:

- Temporary VF IP: `enp23s0v0 = 192.168.20.156/24`
- Server: `ib_write_bw -d mlx4_1 -x 3`
- Client: `ib_write_bw -d rocep23s0 -x 5 192.168.20.156`
- Result: about `48.44 Gb/sec`
