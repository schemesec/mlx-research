#!/usr/bin/env bash
set -euo pipefail

repo="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
kernel="${KVERSION:-$(uname -r)}"
kbuild="${KLIB_BUILD:-/lib/modules/$kernel/build}"
probe_dir="${PROBE_DIR:-/tmp/mlx-research-stock-rdma}"
jobs="${JOBS:-$(nproc)}"
log_dir="$repo/logs"
ts="$(date +%Y%m%d-%H%M%S)"
log="$log_dir/stock-rdma-probe-$ts.log"

mkdir -p "$log_dir"

if [[ ! -d "$kbuild" ]]; then
	echo "missing kernel build directory: $kbuild" | tee "$log"
	exit 1
fi

echo "=== stock RDMA mlx4 probe build ===" | tee "$log"
echo "repo=$repo" | tee -a "$log"
echo "kernel=$kernel" | tee -a "$log"
echo "kbuild=$kbuild" | tee -a "$log"
echo "probe_dir=$probe_dir" | tee -a "$log"
echo "jobs=$jobs" | tee -a "$log"
echo "log=$log" | tee -a "$log"
echo | tee -a "$log"

rm -rf "$probe_dir"
mkdir -p "$probe_dir"
tar -C "$repo" --exclude .git --exclude logs -cf - . | tar -C "$probe_dir" -xf -

rm -rf "$probe_dir/include/rdma" "$probe_dir/include/uapi/rdma"
cp -a "$kbuild/include/rdma" "$probe_dir/include/rdma"
mkdir -p "$probe_dir/include/uapi"
cp -a "$kbuild/include/uapi/rdma" "$probe_dir/include/uapi/rdma"

autoconf="$(ls -1 "$kbuild"/include/*/autoconf.h 2>/dev/null | head -1)"
kconfig="$(ls -1 "$kbuild"/include/*/kconfig.h 2>/dev/null | head -1)"

compat_base="$(<"$probe_dir/compat_base")"
compat_base_tree="$(<"$probe_dir/compat_base_tree")"
compat_base_tree_version="$(<"$probe_dir/compat_base_tree_version")"
compat_version="$(<"$probe_dir/compat_version")"

linuxinclude=(
	-DCOMPAT_BASE="\\\"$compat_base\\\""
	-DCOMPAT_BASE_TREE="\\\"$compat_base_tree\\\""
	-DCOMPAT_BASE_TREE_VERSION="\\\"$compat_base_tree_version\\\""
	-DCOMPAT_PROJECT="\\\"Compat-mlnx-ofed\\\""
	-DCOMPAT_VERSION="\\\"$compat_version\\\""
	-D__OFED_BUILD__
	-D__KERNEL__
	-include "$autoconf"
	-include "$kconfig"
	-include "$probe_dir/include/linux/compat-2.6.h"
	-I"$probe_dir/include"
	-I"$probe_dir/include/uapi"
	-I"$probe_dir/drivers/infiniband/debug"
	-I"$probe_dir/drivers/net/ethernet/mellanox/mlx4"
	-I"$probe_dir/drivers/infiniband/hw/mlx4"
	'-I$(srctree)/arch/$(SRCARCH)/include'
	'-Iarch/$(SRCARCH)/include/generated'
	-Iinclude
	'-I$(srctree)/arch/$(SRCARCH)/include/uapi'
	'-Iarch/$(SRCARCH)/include/generated/uapi'
	'-I$(srctree)/include'
	'-I$(srctree)/include/uapi'
	-Iinclude/generated/uapi
	'-I$(srctree)/arch/$(SRCARCH)/include'
	'-Iarch/$(SRCARCH)/include/generated'
)

linuxinclude_string="${linuxinclude[*]}"

run_make() {
	local label="$1"
	local module_dir="$2"
	shift 2

	echo "=== build $label ===" | tee -a "$log"
	make -C "$kbuild" M="$module_dir" CWD="$probe_dir" -j"$jobs" \
		LINUXINCLUDE="$linuxinclude_string" V=0 "$@" modules 2>&1 | tee -a "$log"
	echo | tee -a "$log"
}

run_make "mlx_compat" "$probe_dir/compat"

run_make "mlx4_core/mlx4_en" "$probe_dir/drivers/net/ethernet/mellanox/mlx4" \
	CONFIG_MLX4_CORE=m \
	CONFIG_MLX4_CORE_GEN2=y \
	CONFIG_MLX4_EN=m \
	CONFIG_MLX4_EN_DCB=y \
	CONFIG_COMPAT_EN_SYSFS=y \
	CONFIG_MLX4_DEBUG= \
	CONFIG_MLX4_FC= \
	KBUILD_EXTRA_SYMBOLS="$probe_dir/compat/Module.symvers"

extra_symbols="$probe_dir/compat/Module.symvers $probe_dir/drivers/net/ethernet/mellanox/mlx4/Module.symvers"

run_make "mlx4_ib stock RDMA ABI" "$probe_dir/drivers/infiniband/hw/mlx4" \
	CONFIG_MLX4_INFINIBAND=m \
	CONFIG_MLX4_IB_DEBUG_FS=y \
	CONFIG_MLX4_IB_STOCK_RDMA_ABI=y \
	KBUILD_EXTRA_SYMBOLS="$extra_symbols"

echo "=== built modules ===" | tee -a "$log"
ls -l \
	"$probe_dir/compat/mlx_compat.ko" \
	"$probe_dir/drivers/net/ethernet/mellanox/mlx4/mlx4_core.ko" \
	"$probe_dir/drivers/net/ethernet/mellanox/mlx4/mlx4_en.ko" \
	"$probe_dir/drivers/infiniband/hw/mlx4/mlx4_ib.ko" | tee -a "$log"

echo | tee -a "$log"
echo "probe build complete; no modules were installed" | tee -a "$log"
