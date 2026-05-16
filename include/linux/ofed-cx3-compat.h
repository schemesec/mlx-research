#ifndef _OFED_CX3_COMPAT_H
#define _OFED_CX3_COMPAT_H

#include <linux/string.h>
#include <linux/version.h>
#include <linux/random.h>
#include <linux/mmzone.h>
#include <linux/dma-mapping.h>
#include <linux/file.h>
#if LINUX_VERSION_CODE >= KERNEL_VERSION(6,12,0)
#include <linux/skbuff_ref.h>
#endif

/*
 * Linux 7.x svc_rdma_recv_ctxt has the modern single-buffer Receive
 * layout used by the PCL code path. The MLNX_OFED feature probe misses
 * that on Proxmox 7.0.2 headers, which otherwise leaves xprtrdma trying
 * to compile legacy rc_pages/rc_sges receive handling against the modern
 * structure.
 */
#if LINUX_VERSION_CODE >= KERNEL_VERSION(7, 0, 0) && \
	defined(HAVE_SVC_RDMA_PCL) && !defined(HAVE_SVC_FILL_WRITE_VECTOR)
#define HAVE_SVC_FILL_WRITE_VECTOR 1
#endif

/*
 * Linux removed strlcpy from newer kernel headers. OFED 4.9 still uses it.
 * strscpy is the modern kernel helper with safer truncation behavior.
 */
#ifndef strlcpy
#define strlcpy(dst, src, size) strscpy(dst, src, size)
#endif

#ifndef prandom_u32
#define prandom_u32() get_random_u32()
#endif

#ifndef uninitialized_var
#define uninitialized_var(x) x = x
#endif

#ifndef no_llseek
#define no_llseek noop_llseek
#endif

#ifndef PCI_DMA_TODEVICE
#define PCI_DMA_TODEVICE DMA_TO_DEVICE
#endif

#ifndef PCI_DMA_FROMDEVICE
#define PCI_DMA_FROMDEVICE DMA_FROM_DEVICE
#endif

#ifndef napi_reschedule
#define napi_reschedule napi_schedule
#endif

#ifndef fd_file
#define fd_file(f) ((f).file)
#endif

#ifndef MAX_ORDER
#define MAX_ORDER MAX_PAGE_ORDER
#endif

#ifndef pci_set_dma_mask
#define pci_set_dma_mask(pdev, mask) dma_set_mask(&(pdev)->dev, mask)
#endif

#ifndef pci_set_consistent_dma_mask
#define pci_set_consistent_dma_mask(pdev, mask) \
	dma_set_coherent_mask(&(pdev)->dev, mask)
#endif

#if LINUX_VERSION_CODE >= KERNEL_VERSION(5,8,0)
#define mmap_sem mmap_lock
#endif

#if LINUX_VERSION_CODE >= KERNEL_VERSION(6,4,0)
#define class_create(owner, name) class_create(name)
#endif

#if LINUX_VERSION_CODE >= KERNEL_VERSION(3,5,0)
#ifndef HAVE_REGISTER_NET_SYSCTL
#define HAVE_REGISTER_NET_SYSCTL 1
#endif
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
#ifdef timer_container_of
#define from_timer(var, callback_timer, timer_fieldname) \
	timer_container_of(var, callback_timer, timer_fieldname)
#else
#define from_timer(var, callback_timer, timer_fieldname) \
	container_of(callback_timer, typeof(*var), timer_fieldname)
#endif
#endif

#ifndef del_timer
#define del_timer(timer) timer_delete(timer)
#endif

#ifndef del_timer_sync
#define del_timer_sync(timer) timer_delete_sync(timer)
#endif

#endif
