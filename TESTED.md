# Tested State

This repository is experimental and was created with AI assistance for testing
only. Do not treat this as production-ready driver packaging.

## pvs3

- Date checked: 2026-05-17
- Host: `pvs3`
- Kernel: `7.0.2-2-pve`
- Repo commit: `d101c78`
- CX3 Pro firmware: `2.42.5000`
- PF: `enp23s0`
- VFs: `8`
- VF VLAN: `20`
- PF VLAN IPs:
  - `enp23s0.10`: `192.168.10.56/24`
  - `enp23s0.20`: `192.168.20.56/24`
- Full rollback validation: repo was absent after rollback, then freshly cloned
  and installed through `cx3pro-install`, `install-pve7.sh`, reboot,
  `sriov_setup`, reboot, `rocesetup`, and `verify-pve7.sh`.

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
- All 8 VFs are host-owned after reboot and expose host RDMA devices.
- VF netdev MACs are stable after reboot:
  - `02:9a:0a:d0:90:00` through `02:9a:0a:d0:90:07`
- All VFs are assigned VLAN 20.
- Bounded kernel warning scan is clean for:
  `BUG`, `Oops`, `WARNING`, `Call Trace`, `Unknown symbol`, `disagrees`,
  `__warn`, `fortify`, and `objtool`.

Local VF RoCEv2 `ib_write_bw` test:

- Temporary VF IP: `enp23s0v0 = 192.168.20.156/24`
- Server: `ib_write_bw -d mlx4_1 -i 1 -R -x 1 -F --report_gbits`
- Client:
  `ib_write_bw -d rocep23s0 -i 1 -R -x 5 -F --report_gbits 192.168.20.156`
- Result: `48.35 Gb/sec` average.

Cross-host PF RoCEv2 `ib_write_bw` test:

- Peer host: `pvs1`
- pvs1 VLAN20 IP/GID: `192.168.20.50`, `mlx4_0`, GID index `5`
- pvs3 VLAN20 IP/GID: `192.168.20.56`, `rocep23s0`, GID index `5`
- pvs3 server:
  `ib_write_bw -d rocep23s0 -i 1 -R -x 5 -F --report_gbits -s 65536`
- pvs1 client:
  `ib_write_bw -d mlx4_0 -i 1 -R -x 5 -F --report_gbits -s 65536 192.168.20.56`
- Result: `49.56 Gb/sec` average.

Cross-host VF RoCEv2 `ib_write_bw` test:

- Peer host: `pvs1`
- Temporary pvs3 VF IP: `enp23s0v0 = 192.168.20.156/24`
- pvs1 VLAN20 IP/GID: `192.168.20.50`, `mlx4_0`, GID index `5`
- pvs3 VF IP/GID: `192.168.20.156`, `mlx4_1`, GID index `3`
- pvs3 VF server:
  `ib_write_bw -d mlx4_1 -i 1 -R -x 3 -F --report_gbits -s 65536`
- pvs1 client:
  `ib_write_bw -d mlx4_0 -i 1 -R -x 5 -F --report_gbits -s 65536 192.168.20.156`
- Result: `49.65 Gb/sec` average.

Stock-RDMA ABI build probe:

- Date checked: 2026-05-18
- Repo commit under test: local changes after `37983f3`
- Command:
  `PROBE_DIR=/tmp/mlx-research-stock-rdma-script-test ./build-stock-rdma-probe.sh`
- Result: `PASS`
- Built, but did not install:
  - `mlx_compat.ko`
  - `mlx4_core.ko`
  - `mlx4_en.ko`
  - `mlx4_ib.ko` with `CONFIG_MLX4_IB_STOCK_RDMA_ABI=y`
- Probe log on pvs3:
  `/root/mlx-research/logs/stock-rdma-probe-20260518-003153.log`

## Explicitly Not Validated

The current tested state does not claim full MLNX_OFED feature parity. See
`FEATURES.md` for the live feature inventory.

Important known gap:

- Stock Proxmox `nvme-rdma.ko` and `nvmet-rdma.ko` do not work with the ported
  OFED RDMA core. A direct `modprobe` test produced real symbol-version and
  missing-symbol failures.
- A stock-RDMA ABI direction is now build-proven for the matched
  `mlx_compat`/`mlx4_core`/`mlx4_en`/`mlx4_ib` module set, but it has not been
  installed or boot-tested. That direction is the preferred path for using stock
  Proxmox upper modules such as `nvme-rdma`, `nvmet-rdma`, and `ib_ipoib`.
