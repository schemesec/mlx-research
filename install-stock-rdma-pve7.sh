#!/usr/bin/env bash
set -euo pipefail

SUPPORTED_KERNEL="7.0.2-2-pve"
KVER="${KVER:-$(uname -r)}"
JOBS="${JOBS:-$(nproc)}"
INSTALL_DIR="${INSTALL_DIR:-/lib/modules/${KVER}/updates/mlx-research-stock-rdma}"
CONFLICT_DIR="${CONFLICT_DIR:-/lib/modules/${KVER}/updates/mlnx-ofed-cx3}"
PROBE_DIR="${PROBE_DIR:-/tmp/mlx-research-stock-rdma-install}"
BACKUP_DIR="${BACKUP_DIR:-}"
CONFLICT_BACKUP_DIR="${CONFLICT_BACKUP_DIR:-}"
BUILD_ONLY=0
NO_BUILD=0
NO_BACKUP=0
FORCE_KERNEL=0

usage() {
	cat <<EOF
Usage: $0 [options]

Build and install the experimental stock-RDMA ABI mlx4 module set for
Proxmox VE 7. This installs only mlx_compat/mlx4 modules and leaves stock
ib_core, rdma_cm, ib_uverbs, ib_ipoib, nvme-rdma, and nvmet-rdma in place.

WARNING: this installer is blocked by default. On pvs3 it installed and passed
module dependency checks, but the next boot hung during mlx4 VF bring-up.
Use build-stock-rdma-probe.sh for compile testing.

Options:
  --build-only       Build modules but do not install into /lib/modules.
  --no-build         Install previously built modules from PROBE_DIR.
  --no-backup        Do not back up existing install/conflict directories.
  --force-kernel     Allow kernels other than ${SUPPORTED_KERNEL}.
  -h, --help         Show this help.

Environment:
  KVER=...           Kernel release to build/install for. Default: uname -r.
  JOBS=...           Parallel build jobs. Default: nproc.
  PROBE_DIR=...      Throwaway stock-RDMA build tree. Default:
                     /tmp/mlx-research-stock-rdma-install
  MLX_RESEARCH_ALLOW_BROKEN_STOCK_RDMA_INSTALL=1
                     Required for any non-build-only install attempt.
  INSTALL_DIR=...    Module install directory. Default:
                     /lib/modules/\$KVER/updates/mlx-research-stock-rdma
  CONFLICT_DIR=...   Existing full-OFED install directory to move aside.
                     Default: /lib/modules/\$KVER/updates/mlnx-ofed-cx3
  BACKUP_DIR=...     Backup directory for previous INSTALL_DIR.
  CONFLICT_BACKUP_DIR=...
                     Backup directory for previous CONFLICT_DIR.
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
LOG="${LOG_DIR}/install-stock-rdma-${TS}.log"

mkdir -p "$LOG_DIR"

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
		log "error: missing required file: $1"
		exit 1
	fi
}

install_module() {
	local src="$1"
	local dst="${INSTALL_DIR}/$(basename "$src")"

	need_file "$src"
	run install -m 0644 "$src" "$dst"
}

remove_old_full_ofed_blacklist() {
	local blacklist_file="/etc/modprobe.d/mlx-research-cx3.conf"

	if [ -f "$blacklist_file" ] &&
	   grep -q "mlx-research CX3 OFED port" "$blacklist_file"; then
		run mv -f "$blacklist_file" "${blacklist_file}.disabled-${TS}"
		log "disabled old full-OFED blacklist: ${blacklist_file}"
	fi
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
		printf '%s\n' mlx4_core
		printf '%s\n' mlx4_en
		printf '%s\n' mlx4_ib
		printf '%s\n' "$end"
	} >>"$modules_file"
	log "initramfs modules pinned in ${modules_file}"
}

cd "$REPO_ROOT"

log "=== mlx-research stock-RDMA Proxmox 7 installer ==="
log "repo=${REPO_ROOT}"
log "kernel=${KVER}"
log "jobs=${JOBS}"
log "probe_dir=${PROBE_DIR}"
log "install_dir=${INSTALL_DIR}"
log "conflict_dir=${CONFLICT_DIR}"
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

if [ "$BUILD_ONLY" -ne 1 ] &&
   [ "${MLX_RESEARCH_ALLOW_BROKEN_STOCK_RDMA_INSTALL:-0}" != "1" ]; then
	log "error: stock-RDMA install is blocked by default"
	log "reason: the first pvs3 boot test hung during mlx4 VF bring-up"
	log "use ./build-stock-rdma-probe.sh for compile-only testing"
	log "to override intentionally, set:"
	log "  MLX_RESEARCH_ALLOW_BROKEN_STOCK_RDMA_INSTALL=1"
	exit 1
fi

if [ "$NO_BUILD" -eq 0 ]; then
	run env "KVERSION=${KVER}" "JOBS=${JOBS}" "PROBE_DIR=${PROBE_DIR}" \
		"${REPO_ROOT}/build-stock-rdma-probe.sh"
else
	log "=== skipping build by request ==="
fi

MODULES=(
	"${PROBE_DIR}/compat/mlx_compat.ko"
	"${PROBE_DIR}/drivers/net/ethernet/mellanox/mlx4/mlx4_core.ko"
	"${PROBE_DIR}/drivers/net/ethernet/mellanox/mlx4/mlx4_en.ko"
	"${PROBE_DIR}/drivers/infiniband/hw/mlx4/mlx4_ib.ko"
)

for module in "${MODULES[@]}"; do
	need_file "$module"
done

if [ "$BUILD_ONLY" -eq 1 ]; then
	log "build-only complete"
	log "log=${LOG}"
	exit 0
fi

if [ "$NO_BACKUP" -eq 0 ]; then
	if [ -z "$BACKUP_DIR" ]; then
		BACKUP_DIR="${REPO_ROOT}/module-backups/${KVER}/stock-rdma.backup-${TS}"
	fi
	if [ -z "$CONFLICT_BACKUP_DIR" ]; then
		CONFLICT_BACKUP_DIR="${REPO_ROOT}/module-backups/${KVER}/full-ofed.disabled-${TS}"
	fi

	if [ -d "$INSTALL_DIR" ]; then
		log "=== backup current stock-RDMA install ==="
		run mkdir -p "$(dirname "$BACKUP_DIR")"
		run cp -a "$INSTALL_DIR" "$BACKUP_DIR"
		run rm -rf "$INSTALL_DIR"
		log "backup_dir=${BACKUP_DIR}"
		log
	fi

	if [ "$CONFLICT_DIR" != "$INSTALL_DIR" ] && [ -d "$CONFLICT_DIR" ]; then
		log "=== move full-OFED install out of module search path ==="
		run mkdir -p "$(dirname "$CONFLICT_BACKUP_DIR")"
		run mv "$CONFLICT_DIR" "$CONFLICT_BACKUP_DIR"
		log "conflict_backup_dir=${CONFLICT_BACKUP_DIR}"
		log
	fi
fi

log "=== install stock-RDMA mlx4 modules ==="
run mkdir -p "$INSTALL_DIR"
for module in "${MODULES[@]}"; do
	install_module "$module"
done
log

log "=== remove old full-OFED ib_ipoib blacklist ==="
remove_old_full_ofed_blacklist
log

log "=== update module dependency database ==="
run depmod "$KVER"
log

log "=== update initramfs module list ==="
ensure_initramfs_modules
run update-initramfs -u -k "$KVER"
log

log "=== dependency check ==="
run modprobe --show-depends -S "$KVER" mlx4_core
run modprobe --show-depends -S "$KVER" mlx4_en
run modprobe --show-depends -S "$KVER" mlx4_ib
run modprobe --show-depends -S "$KVER" ib_ipoib
run modprobe --show-depends -S "$KVER" nvme-rdma
run modprobe --show-depends -S "$KVER" nvmet-rdma
log

log "install complete"
log "reboot into ${KVER}, then verify stock upper modules still resolve outside ${INSTALL_DIR}:"
log "  modprobe --show-depends ib_ipoib nvme-rdma nvmet-rdma"
log "  journalctl -k -b -g 'BUG|Oops|WARNING|Call Trace|mlx4|Unknown symbol|disagrees|__warn' --no-pager"
log "log=${LOG}"
