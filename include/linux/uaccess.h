#ifndef COMPAT_UACCESS_H
#define COMPAT_UACCESS_H

#include "../../compat/config.h"

#include_next <linux/uaccess.h>

#ifndef uaccess_kernel
/*
 * OFED_CX3_COMPAT_UACCESS_KERNEL
 *
 * Newer kernels removed get_fs(), set_fs(), and KERNEL_DS. The old
 * uaccess_kernel() check was used to detect kernel address-limit context.
 * Since modern kernels removed that address-limit switching model, treat
 * this as false for OFED's safe-file-access check.
 */
#define uaccess_kernel() 0
#endif

#endif /* COMPAT_UACCESS_H */
