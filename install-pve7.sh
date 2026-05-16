#!/usr/bin/env bash
set -euo pipefail

SUPPORTED_KERNEL="7.0.2-2-pve"
KVER="${KVER:-$(uname -r)}"
JOBS="${JOBS:-$(nproc)}"
INSTALL_DIR="${INSTALL_DIR:-/lib/modules/${KVER}/updates/mlnx-ofed-cx3}"
MLNX_PYTHON="${MLNX_PYTHON:-}"
MODULE_KCFLAGS="-mindirect-branch=keep -mfunction-return=keep"
BACKUP_DIR="${BACKUP_DIR:-}"
BUILD_ONLY=0
NO_BUILD=0
FORCE_KERNEL=0
NO_BACKUP=0

usage() {
	cat <<EOF
Usage: $0 [options]

Build and install the ported MLNX_OFED CX3/mlx4 modules for Proxmox VE 7.

Options:
  --build-only       Build modules but do not install into /lib/modules.
  --no-build         Install previously built modules from this tree.
  --no-backup        Do not back up the current installed module directory.
  --force-kernel     Allow kernels other than ${SUPPORTED_KERNEL}.
  -h, --help         Show this help.

Environment:
  KVER=...           Kernel release to build/install for. Default: uname -r.
  JOBS=...           Parallel build jobs. Default: nproc.
  MLNX_PYTHON=...    Python executable for legacy OFED scripts.
                     Default: python if present, otherwise python3.
  INSTALL_DIR=...    Module install directory. Default:
                     /lib/modules/\$KVER/updates/mlnx-ofed-cx3
  BACKUP_DIR=...     Backup directory for the previous installed modules.
                     Default: ./module-backups/\$KVER/mlnx-ofed-cx3.backup-<timestamp>
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
	--no-backup)
		NO_BACKUP=1
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

ensure_initramfs_modules() {
	local modules_file="/etc/initramfs-tools/modules"
	local begin="# mlx-research begin"
	local end="# mlx-research end"

	if [ ! -f "$modules_file" ]; then
		run touch "$modules_file"
	fi

	if grep -q "^${begin}$" "$modules_file"; then
		run sed -i "/^${begin}$/,/^${end}$/d" "$modules_file"
	fi

	{
		printf '%s\n' "$begin"
		printf '%s\n' mlx_compat
		printf '%s\n' ib_core
		printf '%s\n' mlx4_core
		printf '%s\n' mlx4_en
		printf '%s\n' mlx4_ib
		printf '%s\n' "$end"
	} >>"$modules_file"
	log "initramfs modules pinned in ${modules_file}"
}

ensure_module_blacklist() {
	local blacklist_file="/etc/modprobe.d/mlx-research-cx3.conf"

	cat >"$blacklist_file" <<'EOF'
# mlx-research CX3 OFED port
#
# This tree installs a ported ib_core/mlx4 stack, but does not install a
# matching ib_ipoib module. Prevent the stock kernel ib_ipoib from loading
# against the ported ib_core and producing symbol-version failures at boot.
blacklist ib_ipoib
install ib_ipoib /bin/false
EOF
	log "module blacklist written to ${blacklist_file}"
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

if [ -z "$MLNX_PYTHON" ]; then
	if command -v python >/dev/null 2>&1; then
		MLNX_PYTHON=python
	elif command -v python3 >/dev/null 2>&1; then
		MLNX_PYTHON=python3
	else
		log "error: neither python nor python3 is available"
		exit 1
	fi
fi
log "mlnx_python=${MLNX_PYTHON}"
log

if [ ! -f compat/config.h ]; then
	log "error: missing generated compat/config.h"
	log "run git pull to fetch tracked OFED build metadata before installing"
	exit 1
fi
if [ ! -f include/linux/version.h ]; then
	log "error: missing generated include/linux/version.h"
	log "run git pull to fetch tracked OFED build metadata before installing"
	exit 1
fi

if [ "$BUILD_ONLY" -ne 1 ] && [ "$(id -u)" -ne 0 ]; then
	log "error: installing modules requires root"
	exit 1
fi

if [ "$NO_BUILD" -eq 0 ]; then
	log "=== clean prior build outputs ==="
	run make -C "/lib/modules/${KVER}/build" "M=${REPO_ROOT}" clean
	run make -C "/lib/modules/${KVER}/build" "M=${REPO_ROOT}/net/sunrpc/xprtrdma" clean
	run make -C "/lib/modules/${KVER}/build" "M=${REPO_ROOT}/drivers/infiniband/ulp/iser" clean
	log

	log "=== build base mlx4/RDMA modules ==="
	run make "CWD=${REPO_ROOT}" "MLNX_PYTHON=${MLNX_PYTHON}" \
		MLNX_CFLAGS= "KCFLAGS=${MODULE_KCFLAGS}" \
		CFLAGS_RETPOLINE= CONFIG_RETPOLINE=y \
		CONFIG_INFINIBAND_USER_MAD=m \
		"-j${JOBS}"
	log

	log "=== build NFS/RDMA module ==="
	run make -f _makefile_ \
		"OFADIR=${REPO_ROOT}" \
		"OFA_DIR=${REPO_ROOT}" \
		"SRC_DIR=${REPO_ROOT}" \
		"KVER=${KVER}" \
		"KCFLAGS=${MODULE_KCFLAGS}" \
		-C net/sunrpc/xprtrdma
	log

	log "=== build iSER module ==="
	run make -f _makefile_ \
		"OFADIR=${REPO_ROOT}" \
		"OFA_DIR=${REPO_ROOT}" \
		"SRC_DIR=${REPO_ROOT}" \
		"KVER=${KVER}" \
		"KCFLAGS=${MODULE_KCFLAGS}" \
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

if [ -z "$BACKUP_DIR" ]; then
	BACKUP_DIR="${REPO_ROOT}/module-backups/${KVER}/mlx-ofed-cx3.backup-${TS}"
fi

if [ "$NO_BACKUP" -eq 0 ] && [ -d "$INSTALL_DIR" ]; then
	log "=== backup current installed modules ==="
	run mkdir -p "$(dirname "$BACKUP_DIR")"
	run cp -a "$INSTALL_DIR" "$BACKUP_DIR"
	log "backup_dir=${BACKUP_DIR}"
	log
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

log "=== update initramfs module list ==="
ensure_initramfs_modules
ensure_module_blacklist
run update-initramfs -u -k "$KVER"
log

log "=== dependency check ==="
run modprobe --show-depends -S "$KVER" mlx4_core
run modprobe --show-depends -S "$KVER" xprtrdma
run modprobe --show-depends -S "$KVER" ib_iser
log

log "install complete"
if [ "$NO_BACKUP" -eq 0 ] && [ -d "$BACKUP_DIR" ]; then
	log "rollback command:"
	log "  ./rollback-pve7.sh ${BACKUP_DIR}"
fi
log "reboot into ${KVER}, then verify with:"
log "  journalctl -k -b -g 'BUG|Oops|WARNING|Call Trace|mlx4|rpcrdma|svc_rdma|sysctl table check failed|__warn_thunk' --no-pager"
log "  systemctl is-active pveproxy pvedaemon pvestatd pve-cluster pve-firewall"
log "log=${LOG}"
