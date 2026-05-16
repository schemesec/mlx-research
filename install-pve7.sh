#!/usr/bin/env bash
set -euo pipefail

SUPPORTED_KERNEL="7.0.2-2-pve"
KVER="${KVER:-$(uname -r)}"
JOBS="${JOBS:-$(nproc)}"
INSTALL_DIR="${INSTALL_DIR:-/lib/modules/${KVER}/updates/mlnx-ofed-cx3}"
BUILD_ONLY=0
NO_BUILD=0
FORCE_KERNEL=0

usage() {
	cat <<EOF
Usage: $0 [options]

Build and install the ported MLNX_OFED CX3/mlx4 modules for Proxmox VE 7.

Options:
  --build-only       Build modules but do not install into /lib/modules.
  --no-build         Install previously built modules from this tree.
  --force-kernel     Allow kernels other than ${SUPPORTED_KERNEL}.
  -h, --help         Show this help.

Environment:
  KVER=...           Kernel release to build/install for. Default: uname -r.
  JOBS=...           Parallel build jobs. Default: nproc.
  INSTALL_DIR=...    Module install directory. Default:
                     /lib/modules/\$KVER/updates/mlnx-ofed-cx3
EOF
}

while [ "$#" -gt 0 ]; do
	case "$1" in
	--build-only)
		BUILD_ONLY=1
		;;
	--no-build)
		NO_BUILD=1
		;;
	--force-kernel)
		FORCE_KERNEL=1
		;;
	-h|--help)
		usage
		exit 0
		;;
	*)
		echo "error: unknown option: $1" >&2
		usage >&2
		exit 2
		;;
	esac
	shift
done

REPO_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
LOG_DIR="${REPO_ROOT}/logs"
TS="$(date +%Y%m%d-%H%M%S)"
LOG="${LOG_DIR}/install-${TS}.log"

log() {
	printf '%s\n' "$*" | tee -a "$LOG"
}

run() {
	log "+ $*"
	"$@" 2>&1 | tee -a "$LOG"
	local rc=${PIPESTATUS[0]}
	if [ "$rc" -ne 0 ]; then
		log "error: command failed with rc=${rc}"
		exit "$rc"
	fi
}

need_file() {
	if [ ! -f "$1" ]; then
		log "error: missing required file after build: $1"
		exit 1
	fi
}

install_module() {
	local src="$1"
	local dst="${INSTALL_DIR}/$(basename "$src")"
	need_file "$src"
	run install -m 0644 "$src" "$dst"
}

mkdir -p "$LOG_DIR"
cd "$REPO_ROOT"

log "=== mlx-research Proxmox 7 installer ==="
log "repo=${REPO_ROOT}"
log "kernel=${KVER}"
log "jobs=${JOBS}"
log "install_dir=${INSTALL_DIR}"
log "log=${LOG}"
log

if [ "$KVER" != "$SUPPORTED_KERNEL" ] && [ "$FORCE_KERNEL" -ne 1 ]; then
	log "error: this port is validated for ${SUPPORTED_KERNEL}, current target is ${KVER}"
	log "rerun with --force-kernel only if you are intentionally testing another kernel"
	exit 1
fi

if [ ! -d "/lib/modules/${KVER}/build" ]; then
	log "error: missing kernel build directory: /lib/modules/${KVER}/build"
	log "install the matching pve-headers package before running this script"
	exit 1
fi

if [ "$BUILD_ONLY" -ne 1 ] && [ "$(id -u)" -ne 0 ]; then
	log "error: installing modules requires root"
	exit 1
fi

if [ "$NO_BUILD" -eq 0 ]; then
	log "=== build base mlx4/RDMA modules ==="
	run make "CWD=${REPO_ROOT}" CFLAGS_RETPOLINE= CONFIG_RETPOLINE=y "-j${JOBS}"
	log

	log "=== build NFS/RDMA module ==="
	run make -f _makefile_ \
		"OFADIR=${REPO_ROOT}" \
		"OFA_DIR=${REPO_ROOT}" \
		"SRC_DIR=${REPO_ROOT}" \
		"KVER=${KVER}" \
		-C net/sunrpc/xprtrdma
	log

	log "=== build iSER module ==="
	run make -f _makefile_ \
		"OFADIR=${REPO_ROOT}" \
		"OFA_DIR=${REPO_ROOT}" \
		"SRC_DIR=${REPO_ROOT}" \
		"KVER=${KVER}" \
		-C drivers/infiniband/ulp/iser
	log
else
	log "=== skipping build by request ==="
fi

MODULES=(
	compat/mlx_compat.ko
	drivers/infiniband/core/ib_core.ko
	drivers/infiniband/core/ib_cm.ko
	drivers/infiniband/core/iw_cm.ko
	drivers/infiniband/core/rdma_cm.ko
	drivers/infiniband/core/rdma_ucm.ko
	drivers/infiniband/core/ib_ucm.ko
	drivers/infiniband/core/ib_umad.ko
	drivers/infiniband/core/ib_uverbs.ko
	drivers/net/ethernet/mellanox/mlx4/mlx4_core.ko
	drivers/net/ethernet/mellanox/mlx4/mlx4_en.ko
	drivers/infiniband/hw/mlx4/mlx4_ib.ko
	net/sunrpc/xprtrdma/rpcrdma.ko
	drivers/infiniband/ulp/iser/ib_iser.ko
)

for module in "${MODULES[@]}"; do
	need_file "$module"
done

if [ "$BUILD_ONLY" -eq 1 ]; then
	log "build-only complete"
	log "log=${LOG}"
	exit 0
fi

log "=== install modules ==="
run mkdir -p "$INSTALL_DIR"
for module in "${MODULES[@]}"; do
	install_module "$module"
done
log

log "=== disable dummy module names if present ==="
for dummy in xprtrdma svcrdma; do
	if [ -f "${INSTALL_DIR}/${dummy}.ko" ]; then
		run mv -f "${INSTALL_DIR}/${dummy}.ko" "${INSTALL_DIR}/${dummy}.ko.disabled"
	fi
done
log

log "=== update module dependency database ==="
run depmod "$KVER"
log

log "=== dependency check ==="
run modprobe --show-depends -S "$KVER" mlx4_core
run modprobe --show-depends -S "$KVER" xprtrdma
run modprobe --show-depends -S "$KVER" ib_iser
log

log "install complete"
log "reboot into ${KVER}, then verify with:"
log "  journalctl -k -b -g 'BUG|Oops|WARNING|Call Trace|mlx4|rpcrdma|svc_rdma|sysctl table check failed' --no-pager"
log "  systemctl is-active pveproxy pvedaemon pvestatd pve-cluster pve-firewall"
log "log=${LOG}"
