#!/usr/bin/env bash
set -u

LOGDIR="$PWD/logs"
mkdir -p "$LOGDIR"

TS="$(date +%Y%m%d-%H%M%S)"
LOG="$LOGDIR/build-$TS.log"

export KVERSION="$(uname -r)"
export KLIB="/lib/modules/$KVERSION"
export KLIB_BUILD="/lib/modules/$KVERSION/build"

echo "=== build started: $TS ===" | tee "$LOG"
echo "PWD=$PWD" | tee -a "$LOG"
echo "KVERSION=$KVERSION" | tee -a "$LOG"
echo "KLIB=$KLIB" | tee -a "$LOG"
echo "KLIB_BUILD=$KLIB_BUILD" | tee -a "$LOG"
echo | tee -a "$LOG"

echo "=== kernel build dir ===" | tee -a "$LOG"
ls -ld "$KLIB_BUILD" 2>&1 | tee -a "$LOG"
readlink -f "$KLIB_BUILD" 2>&1 | tee -a "$LOG"
echo | tee -a "$LOG"

echo "=== source tree state ===" | tee -a "$LOG"
git status --short 2>&1 | tee -a "$LOG"
echo | tee -a "$LOG"

echo "=== git diff before build ===" | tee -a "$LOG"
git diff 2>&1 | tee -a "$LOG"
echo | tee -a "$LOG"

echo "=== build command ===" | tee -a "$LOG"
DEFAULT_BUILD_CMD="make CWD=\"$PWD\" -j$(nproc)"
echo "${BUILD_CMD:-$DEFAULT_BUILD_CMD}" | tee -a "$LOG"
echo | tee -a "$LOG"

bash -lc "${BUILD_CMD:-$DEFAULT_BUILD_CMD}" 2>&1 | tee -a "$LOG"
BUILD_RC=${PIPESTATUS[0]}

echo | tee -a "$LOG"
echo "=== result ===" | tee -a "$LOG"
echo "build rc=$BUILD_RC" | tee -a "$LOG"
echo "log=$LOG" | tee -a "$LOG"

exit "$BUILD_RC"
