# mlx-research

Port of the MLNX_OFED ConnectX-3/mlx4 driver stack for Proxmox VE 7 kernel
`7.0.2-2-pve`.

## Fresh Proxmox Install

Install matching headers and build tools, then run the installer from this repo:

```bash
apt update
apt install -y git build-essential pve-headers-$(uname -r)
git clone https://github.com/schemesec/mlx-research.git
cd mlx-research
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

The installer builds with the retpoline-safe flags required by the Proxmox 7
kernel, installs the known-good mlx4/RDMA module set into
`/lib/modules/$(uname -r)/updates/mlnx-ofed-cx3`, disables the dummy
`xprtrdma.ko` and `svcrdma.ko` module names if present, and runs `depmod`.

For a build-only validation run:

```bash
./install-pve7.sh --build-only
```
