#!/usr/bin/env bash
set -euo pipefail

SUPPORTED_KERNEL="7.0.2-2-pve"
KVER="${KVER:-$(uname -r)}"
INSTALL_DIR="${INSTALL_DIR:-/lib/modules/${KVER}/updates/mlnx-ofed-cx3}"
BACKUP_DIR="${1:-}"

usage() {
	cat <<EOF
Usage: $0 [backup-dir]

Restore a previous mlx-research module install backup and refresh depmod.

If backup-dir is omitted, the newest sibling backup matching:
  ${INSTALL_DIR}.backup-*
is used.

Environment:
  KVER=...           Kernel release. Default: uname -r.
  INSTALL_DIR=...    Installed module directory. Default:
                     /lib/modules/\$KVER/updates/mlnx-ofed-cx3
EOF
}

if [ "${1:-}" = "-h" ] || [ "${1:-}" = "--help" ]; then
	usage
	exit 0
fi

if [ "$KVER" != "$SUPPORTED_KERNEL" ]; then
	echo "error: this rollback script is validated for ${SUPPORTED_KERNEL}, current target is ${KVER}" >&2
	exit 1
fi

if [ "$(id -u)" -ne 0 ]; then
	echo "error: rollback requires root" >&2
	exit 1
fi

if [ -z "$BACKUP_DIR" ]; then
	BACKUP_DIR="$(find "$(dirname "$INSTALL_DIR")" -maxdepth 1 -type d \
		-name "$(basename "$INSTALL_DIR").backup-*" -printf '%T@ %p\n' |
		sort -nr | awk 'NR == 1 {print $2}')"
fi

if [ -z "$BACKUP_DIR" ] || [ ! -d "$BACKUP_DIR" ]; then
	echo "error: backup directory not found: ${BACKUP_DIR:-<none>}" >&2
	exit 1
fi

TS="$(date +%Y%m%d-%H%M%S)"
FAILED_DIR="${INSTALL_DIR}.failed-${TS}"

echo "restore_from=${BACKUP_DIR}"
echo "install_dir=${INSTALL_DIR}"
if [ -d "$INSTALL_DIR" ]; then
	echo "saving_current=${FAILED_DIR}"
	mv "$INSTALL_DIR" "$FAILED_DIR"
fi

cp -a "$BACKUP_DIR" "$INSTALL_DIR"
depmod "$KVER"

echo "rollback complete"
echo "current install restored from ${BACKUP_DIR}"
