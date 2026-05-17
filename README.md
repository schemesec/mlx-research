# mlx-research

## Warning

This repository was created with AI assistance for testing and research only.
Do not use it on production systems or systems you cannot afford to reinstall
or roll back.

Port of the MLNX_OFED ConnectX-3/mlx4 driver stack for Proxmox VE 7 kernel
`7.0.2-2-pve`.

## Fresh Proxmox Install

The intended outcome from a fresh Proxmox install is:

- install MST/MFT tooling
- verify the CX3 Pro firmware candidate/current PSID and 2.42.5x firmware
- install the local mlx-research mlx4/RDMA kernel modules
- enable SR-IOV VFs with RoCEv2 boot parameters
- configure VLAN RoCEv2 interfaces and use RoCEv2 from both the PF and VFs

Install matching headers and build tools, then clone this repo:

```bash
apt update
apt install -y git build-essential pve-headers-$(uname -r)
git clone https://github.com/schemesec/mlx-research.git
cd mlx-research
```

Run the setup in this order from a fresh install or rollback.

1. Install MST/MFT tooling and check the CX3 Pro firmware. By default this
   checks the current and candidate firmware versions/PSIDs but does not flash
   firmware:

```bash
./cx3pro-install
```

2. Build and install the ported mlx4/RDMA kernel modules, then reboot:

```bash
./install-pve7.sh
reboot
```

3. Configure SR-IOV boot parameters and the VF VLAN/MAC service, then reboot.
   This does not reboot unless `--auto-reboot` is passed:

```bash
PF=enp23s0 NUM_VFS=8 VF_VLAN=20 ./sriov_setup
reboot
```

4. Configure PF VLAN interfaces for RoCEv2 testing. Replace these IPs for hosts
   other than pvs3:

```bash
VLAN10_IP=192.168.10.56/24 VLAN20_IP=192.168.20.56/24 ./rocesetup
```

By default, `sriov_setup` assigns stable locally administered VF MAC addresses
derived from the PF MAC, sets each VF to VLAN 20, and rebinds the PF-owned VF
PCI functions so the VF netdevs pick up those stable MAC addresses. To provide
explicit MACs, pass a comma-separated list:

```bash
VF_MACS=02:9a:0a:d0:90:00,02:9a:0a:d0:90:01 ./sriov_setup
```

Set `REPROBE_VFS=0` only when running the helper on a live host where VFs are
already assigned to guests and must not be rebound.

`rocesetup` writes a marked block into `/etc/network/interfaces` by default so
the VLAN interfaces are persistent and visible to Proxmox networking tools. Set
`PERSIST_INTERFACES=0` to only configure the live runtime interfaces.

Run the verifier after setup:

```bash
PF=enp23s0 NUM_VFS=8 VF_VLAN=20 \
VLAN10_IP=192.168.10.56/24 VLAN20_IP=192.168.20.56/24 \
./verify-pve7.sh
```

The validated pvs3 outcome is:

- Proxmox services stay active.
- `mlx4_core`, `mlx4_en`, `mlx4_ib`, and RDMA core modules resolve to
  `/lib/modules/$(uname -r)/updates/mlnx-ofed-cx3`.
- CX3 Pro firmware is `2.42.5x`.
- mlx4 is configured as `roce_mode=2` so RoCE v1 and v2 GIDs are exposed, and
  RDMA-CM `default_roce_mode` is set to `RoCE v2`.
- PF RoCE device `rocep23s0` is active.
- 8 VF RDMA devices are present.
- VF netdev MACs are stable after reboot.
- all VFs are assigned VLAN 20.
- `enp23s0.10` and `enp23s0.20` have the configured IPs.
- bounded kernel warning scans have no `WARNING`, `Call Trace`,
  `Unknown symbol`, `disagrees`, `__warn`, fortify, or objtool entries.

The installer builds with the retpoline-safe flags required by the Proxmox 7
kernel, installs the known-good mlx4/RDMA module set into
`/lib/modules/$(uname -r)/updates/mlnx-ofed-cx3`, disables the dummy
`xprtrdma.ko` and `svcrdma.ko` module names if present, and runs `depmod`.

For a build-only validation run:

```bash
./install-pve7.sh --build-only
```
