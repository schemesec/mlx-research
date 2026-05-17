#!/usr/bin/env bash
set -euo pipefail

PF="${PF:-enp23s0}"
NUM_VFS="${NUM_VFS:-8}"
VF_VLAN="${VF_VLAN:-20}"
INSTALL_DIR="${INSTALL_DIR:-/lib/modules/$(uname -r)/updates/mlnx-ofed-cx3}"
FW_PREFIX="${FW_PREFIX:-2.42.5}"
CHECK_VLAN_IPS="${CHECK_VLAN_IPS:-1}"
VLAN10_IF="${VLAN10_IF:-${PF}.10}"
VLAN20_IF="${VLAN20_IF:-${PF}.20}"
VLAN10_IP="${VLAN10_IP:-}"
VLAN20_IP="${VLAN20_IP:-}"

failures=0

section() {
       printf '\n=== %s ===\n' "$*"
}

pass() {
       printf 'PASS: %s\n' "$*"
}

warn() {
       printf 'WARN: %s\n' "$*" >&2
}

fail() {
       printf 'FAIL: %s\n' "$*" >&2
       failures=$((failures + 1))
}

need_cmd() {
       if ! command -v "$1" >/dev/null 2>&1; then
               fail "missing command: $1"
               return 1
       fi
}

vf_mac_from_pf() {
       local pf="$1"
       local idx="$2"
       local pf_mac
       local o1 o2 o3 o4 o5 o6

       pf_mac="$(cat "/sys/class/net/${pf}/address")"
       IFS=: read -r o1 o2 o3 o4 o5 o6 <<EOF_MAC
${pf_mac}
EOF_MAC
       printf '02:%s:%s:%s:%s:%02x\n' "$o3" "$o4" "$o5" "$o6" "$idx"
}

vf_netdev() {
       local idx="$1"
       local vf_link="/sys/class/net/${PF}/device/virtfn${idx}"
       local vf_bdf

       [ -e "$vf_link" ] || return 1
       vf_bdf="$(basename "$(readlink -f "$vf_link")")"
       ls "/sys/bus/pci/devices/${vf_bdf}/net" 2>/dev/null | head -1
}

check_module_path() {
       local module="$1"

       if modprobe --show-depends "$module" | grep -q "$INSTALL_DIR"; then
               pass "$module resolves to $INSTALL_DIR"
       else
               fail "$module does not resolve to $INSTALL_DIR"
               modprobe --show-depends "$module" || true
       fi
}

section "host"
hostname
uname -r
uptime -s || true

section "commands"
need_cmd ip
need_cmd modprobe
need_cmd journalctl
need_cmd systemctl
need_cmd rdma
need_cmd ibv_devices
need_cmd ibv_devinfo

section "proxmox services"
for service in pveproxy pvedaemon pvestatd pve-cluster pve-firewall; do
       if systemctl is-active --quiet "$service"; then
               pass "$service active"
       else
               fail "$service not active"
       fi
done

section "mlx-research module resolution"
for module in mlx4_core mlx4_en mlx4_ib ib_core rdma_cm ib_uverbs; do
       check_module_path "$module"
done

section "firmware and RDMA devices"
if ibv_devinfo -d rocep23s0 2>/dev/null | grep -q "fw_ver:[[:space:]]*${FW_PREFIX}"; then
       pass "rocep23s0 firmware matches ${FW_PREFIX}x"
else
       fail "rocep23s0 firmware does not match ${FW_PREFIX}x"
       ibv_devinfo -d rocep23s0 2>/dev/null | grep 'fw_ver:' || true
fi

ibv_devices || true
if ibv_devices | awk '{print $1}' | grep -qx rocep23s0; then
       pass "PF RDMA device rocep23s0 present"
else
       fail "PF RDMA device rocep23s0 missing"
fi

vf_rdma_count="$(ibv_devices | awk '$1 ~ /^mlx4_[0-9]+$/ {count++} END {print count + 0}')"
if [ "$vf_rdma_count" -eq "$NUM_VFS" ]; then
       pass "$NUM_VFS VF RDMA devices present"
else
       fail "expected $NUM_VFS VF RDMA devices, found $vf_rdma_count"
fi

rdma link show || true
if rdma link show | grep -q "rocep23s0/1 state ACTIVE"; then
       pass "PF RDMA port is active"
else
       fail "PF RDMA port is not active"
fi

section "SR-IOV service"
if systemctl is-active --quiet cx3pro-sriov-vfs.service; then
       pass "cx3pro-sriov-vfs.service active"
else
       fail "cx3pro-sriov-vfs.service not active"
fi
systemctl status cx3pro-sriov-vfs.service --no-pager --lines=20 || true

section "VF MAC and VLAN"
if ! ip link show "$PF" >/dev/null 2>&1; then
       fail "PF netdev missing: $PF"
else
       pass "PF netdev present: $PF"
       ip -d link show "$PF"
fi

for i in $(seq 0 $((NUM_VFS - 1))); do
       vf="$(vf_netdev "$i" || true)"
       expected_mac="$(vf_mac_from_pf "$PF" "$i")"
       actual_mac=""

       if [ -z "$vf" ]; then
               fail "vf $i netdev missing"
               continue
       fi

       if [ -e "/sys/class/net/${vf}/address" ]; then
               actual_mac="$(cat "/sys/class/net/${vf}/address")"
       fi

       if [ "$actual_mac" = "$expected_mac" ]; then
               pass "$vf MAC is stable: $actual_mac"
       else
               fail "$vf MAC mismatch: expected $expected_mac, got ${actual_mac:-missing}"
       fi

       if ip -d link show "$PF" | grep -q "vf $i .*vlan $VF_VLAN"; then
               pass "$vf is assigned VLAN $VF_VLAN"
       else
               fail "$vf is not assigned VLAN $VF_VLAN"
       fi
done

section "PF VLAN interfaces"
for netdev in "$PF" "$VLAN10_IF" "$VLAN20_IF"; do
       ip -br addr show "$netdev" 2>/dev/null || true
done

for vlan_if in "$VLAN10_IF" "$VLAN20_IF"; do
       if ip link show "$vlan_if" >/dev/null 2>&1; then
               pass "$vlan_if exists"
       else
               fail "$vlan_if missing"
       fi
done

if [ "$CHECK_VLAN_IPS" = "1" ]; then
       if [ -n "$VLAN10_IP" ]; then
               ip -br addr show "$VLAN10_IF" | grep -q "$VLAN10_IP" && pass "$VLAN10_IF has $VLAN10_IP" || fail "$VLAN10_IF missing $VLAN10_IP"
       else
               warn "VLAN10_IP not set; only checking that $VLAN10_IF exists"
       fi

       if [ -n "$VLAN20_IP" ]; then
               ip -br addr show "$VLAN20_IF" | grep -q "$VLAN20_IP" && pass "$VLAN20_IF has $VLAN20_IP" || fail "$VLAN20_IF missing $VLAN20_IP"
       else
               warn "VLAN20_IP not set; only checking that $VLAN20_IF exists"
       fi
fi

section "kernel warning scan"
if journalctl -k -b -g 'BUG|Oops|WARNING|Call Trace|Unknown symbol|disagrees|__warn|fortify|objtool' --no-pager | grep -v '^-- No entries --'; then
       fail "kernel warning scan found entries"
else
       pass "kernel warning scan has no matching entries"
fi

section "summary"
if [ "$failures" -eq 0 ]; then
       echo "verify-pve7: PASS"
       exit 0
fi

echo "verify-pve7: FAIL ($failures failures)"
exit 1
