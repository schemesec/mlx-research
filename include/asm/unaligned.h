#ifndef _COMPAT_ASM_UNALIGNED_H
#define _COMPAT_ASM_UNALIGNED_H

#include <linux/version.h>

#if LINUX_VERSION_CODE >= KERNEL_VERSION(6,12,0)
#include <linux/unaligned.h>
#else
#include_next <asm/unaligned.h>
#endif

#endif /* _COMPAT_ASM_UNALIGNED_H */
