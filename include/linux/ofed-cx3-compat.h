#ifndef _OFED_CX3_COMPAT_H
#define _OFED_CX3_COMPAT_H

#include <linux/string.h>

/*
 * Linux removed strlcpy from newer kernel headers. OFED 4.9 still uses it.
 * strscpy is the modern kernel helper with safer truncation behavior.
 */
#ifndef strlcpy
#define strlcpy(dst, src, size) strscpy(dst, src, size)
#endif


#include <linux/container_of.h>
#include <linux/timer.h>

/*
 * OFED_CX3_COMPAT_TIMER_API
 *
 * Newer kernels changed some timer helper names. MLNX_OFED 4.9 still uses
 * from_timer(), del_timer(), and del_timer_sync().
 */
#ifndef from_timer
#define from_timer(var, callback_timer, timer_fieldname) \
	container_of(callback_timer, typeof(*var), timer_fieldname)
#endif

#ifndef del_timer
#define del_timer(timer) timer_delete(timer)
#endif

#ifndef del_timer_sync
#define del_timer_sync(timer) timer_delete_sync(timer)
#endif

#endif
