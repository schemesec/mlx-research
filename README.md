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

Install MST/MFT tooling and check the CX3 Pro firmware. By default this checks
the current and candidate firmware versions/PSIDs but does not flash firmware:

```bash
./cx3pro-install
```

Then build and install the ported mlx4/RDMA kernel modules:

```bash
./install-pve7.sh
reboot
```

After reboot, verify the OFED modules are being used:

```bash
modprobe --show-depends mlx4_core
modprobe --show-depends xprtrdma
modprobe --show-depends ib_iser
journalctl -k -b -g 'BUG|Oops|WARNING|Call Trace|mlx4|rpcrdma|svc_rdma|sysctl table check failed' --no-pager
systemctl is-active pveproxy pvedaemon pvestatd pve-cluster pve-firewall
```

Configure SR-IOV boot parameters and VF VLAN setup. This does not reboot unless
`--auto-reboot` is passed:

```bash
./sriov_setup
reboot
```

After the SR-IOV reboot, configure PF VLAN interfaces for RoCEv2 testing and
print the dynamic RoCEv2 GID indices to use with perftest:

```bash
./rocesetup
```

The installer builds with the retpoline-safe flags required by the Proxmox 7
kernel, installs the known-good mlx4/RDMA module set into
`/lib/modules/$(uname -r)/updates/mlnx-ofed-cx3`, disables the dummy
`xprtrdma.ko` and `svcrdma.ko` module names if present, and runs `depmod`.

For a build-only validation run:

```bash
./install-pve7.sh --build-only
```
