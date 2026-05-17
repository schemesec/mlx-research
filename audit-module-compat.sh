#!/usr/bin/env bash
set -euo pipefail

KVER="${KVER:-$(uname -r)}"
OFED_SYMVERS="${OFED_SYMVERS:-$(pwd)/Module.symvers}"
KERNEL_SYMVERS="${KERNEL_SYMVERS:-/lib/modules/${KVER}/build/Module.symvers}"

usage() {
	cat <<EOF
Usage: $0 <module.ko> [module.ko ...]

Compare a stock module's imported RDMA symbols against the current kernel
headers and this tree's OFED Module.symvers.

Environment:
  KVER=...              Kernel release. Default: uname -r.
  OFED_SYMVERS=...      OFED Module.symvers. Default: ./Module.symvers.
  KERNEL_SYMVERS=...    Kernel Module.symvers. Default:
                        /lib/modules/\$KVER/build/Module.symvers.
EOF
}

if [ "$#" -eq 0 ]; then
	usage >&2
	exit 2
fi

if [ ! -f "$OFED_SYMVERS" ]; then
	echo "error: missing OFED symvers: ${OFED_SYMVERS}" >&2
	exit 1
fi

if [ ! -f "$KERNEL_SYMVERS" ]; then
	echo "error: missing kernel symvers: ${KERNEL_SYMVERS}" >&2
	exit 1
fi

tmpdir="$(mktemp -d)"
trap 'rm -rf "$tmpdir"' EXIT

for module in "$@"; do
	if [ ! -f "$module" ]; then
		echo "error: missing module: ${module}" >&2
		exit 1
	fi

	base="$(basename "$module")"
	needed="${tmpdir}/${base}.needed"

	modprobe --dump-modversions "$module" |
		awk '$2 ~ /^(ib_|rdma_|__ib_|__rdma_|cma_)/ { print $2 "\t" $1 }' |
		sort -u >"$needed"

	echo "=== ${module} ==="
	printf '%-36s %-12s %-12s %-12s %s\n' \
		"symbol" "module" "kernel" "ofed" "status"

	while IFS=$'\t' read -r sym mod_crc; do
		kernel_crc="$(awk -v s="$sym" '$2 == s { print $1; exit }' "$KERNEL_SYMVERS")"
		ofed_crc="$(awk -v s="$sym" '$2 == s { print $1; exit }' "$OFED_SYMVERS")"

		if [ -z "$ofed_crc" ]; then
			status="missing-from-ofed"
		elif [ "$mod_crc" = "$ofed_crc" ]; then
			status="ok"
		else
			status="crc-mismatch"
		fi

		printf '%-36s %-12s %-12s %-12s %s\n' \
			"$sym" "$mod_crc" "${kernel_crc:--}" "${ofed_crc:--}" "$status"
	done <"$needed"
	echo
done
