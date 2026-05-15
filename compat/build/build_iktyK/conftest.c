/* confdefs.h.  */
/* confdefs.h */
#define PACKAGE_NAME "compat_mlnx"
#define PACKAGE_TARNAME "compat_mlnx"
#define PACKAGE_VERSION "2.3"
#define PACKAGE_STRING "compat_mlnx 2.3"
#define PACKAGE_BUGREPORT "http://support.mellanox.com/SupportWeb/service_center/SelfService"
#define PACKAGE_URL ""
#define PACKAGE "compat_mlnx"
#define VERSION "2.3"
#define STDC_HEADERS 1
#define HAVE_SYS_TYPES_H 1
#define HAVE_SYS_STAT_H 1
#define HAVE_STDLIB_H 1
#define HAVE_STRING_H 1
#define HAVE_MEMORY_H 1
#define HAVE_STRINGS_H 1
#define HAVE_INTTYPES_H 1
#define HAVE_STDINT_H 1
#define HAVE_UNISTD_H 1
#define SIZEOF_UNSIGNED_LONG_LONG 8
#define HAVE_UNPIN_USER_PAGES_DIRTY_LOCK_EXPORTED 1
#define HAVE_GET_NET_NS_BY_FD_EXPORTED 1
#define HAVE_FLOW_RULE_MATCH_CVLAN 1
#define HAVE_SPLIT_PAGE_EXPORTED 1
#define HAVE_IP6_DST_HOPLIMIT 1
#define HAVE_UDP4_HWCSUM 1
#define HAVE___IP_DEV_FIND 1
#define HAVE_INET_CONFIRM_ADDR_EXPORTED 1
#define HAVE_PM_QOS_UPDATE_USER_LATENCY_TOLERANCE_EXPORTED 1
#define HAVE_ELFCOREHDR_ADDR_EXPORTED 1
#define HAVE_IDR_GET_NEXT_UL_EXPORTED 1
#define HAVE_IDR_GET_NEXT_EXPORTED 1
#define HAVE_TCF_EXTS_NUM_ACTIONS 1
#define HAVE_NETPOLL_POLL_DEV_EXPORTED 1
#define HAVE_BPF_PROG_INC_EXPORTED 1
#define HAVE_PUT_TASK_STRUCT_EXPORTED 1
#define HAVE_GET_PID_TASK_EXPORTED 1
#define HAVE_GET_TASK_PID_EXPORTED 1
#define HAVE_IDR_PRELOAD_EXPORTED 1
#define HAVE_RADIX_TREE_ITER_DELETE_EXPORTED 1
#define HAVE_KOBJ_NS_GRAB_CURRENT_EXPORTED 1
/* end confdefs.h.  */

#include <linux/kernel.h>

		#include <linux/sunrpc/svc.h>

int
main (void)
{

		return svc_fill_write_vector(NULL, NULL, NULL, 0);

  ;
  return 0;
}
