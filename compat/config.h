/* config.h.  Generated from config.h.in by configure.  */
/* config.h.in.  Generated from configure.ac by autoheader.  */

/* .ndo_select_queue has 3 parameters */
#define HAVE_3_PARAMS_FOR_NDO_SELECT_QUEUE 1

/* __vlan_hwaccel_put_tag has 3 parameters */
#define HAVE_3_PARAMS_FOR_VLAN_HWACCEL_PUT_TAG 1

/* access_okhas 3 parameters */
/* #undef HAVE_ACCESS_OK_HAS_3_PARAMS */

/* addrconf_addr_eui48 is defined */
#define HAVE_ADDRCONF_ADDR_EUI48 1

/* addrconf_ifid_eui48 is defined */
#define HAVE_ADDRCONF_IFID_EUI48 1

/* alloc_etherdev_mq is defined */
#define HAVE_ALLOC_ETHERDEV_MQ 1

/* alloc_netdev_mqs has 5 params */
/* #undef HAVE_ALLOC_NETDEV_MQS_5_PARAMS */

/* alloc_netdev_mq has 4 params */
/* #undef HAVE_ALLOC_NETDEV_MQ_4_PARAMS */

/* alloc_workqueue is defined */
#define HAVE_ALLOC_WORKQUEUE 1

/* array_index_nospec is defined */
#define HAVE_ARRAY_INDEX_NOSPEC 1

/* atomic_fetch_add_unless is defined */
#define HAVE_ATOMIC_FETCH_ADD_UNLESS 1

/* atomic_pinned_vm is defined */
#define HAVE_ATOMIC_PINNED_VM 1

/* attr_is_visible returns umode_t */
#define HAVE_ATTR_IS_VISIBLE_RET_UMODE_T 1

/* linux/compiler.h barrier_data is defined */
#define HAVE_BARRIER_DATA 1

/* bdev_write_zeroes_sectors is defined */
#define HAVE_BDEV_WRITE_ZEROES_SECTORS 1

/* linux/bio.h has bip_get_seed */
/* #undef HAVE_BIO_BIP_GET_SEED */

/* struct bio has member bi_disk */
/* #undef HAVE_BIO_BI_DISK */

/* linux/bio.h bio_endio has 1 parameter */
#define HAVE_BIO_ENDIO_1_PARAM 1

/* bio.h bio_init has 3 parameters */
/* #undef HAVE_BIO_INIT_3_PARAMS */

/* bio_integrity_payload has members bip_iter */
/* #undef HAVE_BIO_INTEGRITY_PYLD_BIP_ITER */

/* bitmap_free is defined */
#define HAVE_BITMAP_FREE 1

/* bitmap_from_arr32 is defined */
#define HAVE_BITMAP_FROM_ARR32 1

/* bitmap_kzalloc is defined */
#define HAVE_BITMAP_KZALLOC 1

/* include/linux/bits.h exists */
#define HAVE_BITS_H 1

/* blist_flags_t is defined */
#define HAVE_BLIST_FLAGS_T 1

/* dma_map_bvec exist */
#define HAVE_BLKDEV_DMA_MAP_BVEC 1

/* blkdev_issue_flush has 1 params */
#define HAVE_BLKDEV_ISSUE_FLUSH_1_PARAM 1

/* blkdev_issue_flush has 2 params */
/* #undef HAVE_BLKDEV_ISSUE_FLUSH_2_PARAM */

/* __blkdev_issue_zeroout exist */
#define HAVE_BLKDEV_ISSUE_ZEROOUT 1

/* linux/blkdev.h has QUEUE_FLAG_QUIESCED */
#define HAVE_BLKDEV_QUEUE_FLAG_QUIESCED 1

/* linux/blkdev.h has req_bvec */
/* #undef HAVE_BLKDEV_REQ_BVEC */

/* REQ_TYPE_DRV_PRIV is defined */
/* #undef HAVE_BLKDEV_REQ_TYPE_DRV_PRIV */

/* blkdev.h blk_add_request_payload has 4 parameters */
/* #undef HAVE_BLK_ADD_REQUEST_PAYLOAD_HAS_4_PARAMS */

/* blk_alloc_queue_node has 3 args */
/* #undef HAVE_BLK_ALLOC_QUEUE_NODE_3_ARGS */

/* linux/blkdev.h has blk_alloc_queue_rh */
/* #undef HAVE_BLK_ALLOC_QUEUE_RH */

/* BLK_EH_DONE is defined */
/* #undef HAVE_BLK_EH_DONE */

/* blk_freeze_queue_start is defined */
#define HAVE_BLK_FREEZE_QUEUE_START 1

/* blk_init_request_from_bio is defined */
/* #undef HAVE_BLK_INIT_REQUEST_FROM_BIO */

/* BLK_INTEGRITY_DEVICE_CAPABLE is defined */
/* #undef HAVE_BLK_INTEGRITY_DEVICE_CAPABLE */

/* struct blk_integrity has sector_size */
/* #undef HAVE_BLK_INTEGRITY_SECTOR_SIZE */

/* BLK_MAX_WRITE_HINTS is defined */
/* #undef HAVE_BLK_MAX_WRITE_HINTS */

/* linux/blk-mq.h blk_mq_alloc_request has 3 parameters */
#define HAVE_BLK_MQ_ALLOC_REQUEST_HAS_3_PARAMS 1

/* linux/blk-mq.h has blk_mq_alloc_request_hctx */
#define HAVE_BLK_MQ_ALLOC_REQUEST_HCTX 1

/* blk_mq_all_tag_busy_iter is defined */
/* #undef HAVE_BLK_MQ_ALL_TAG_BUSY_ITER */

/* linux/blk-mq.h has busy_tag_iter_fn return bool */
/* #undef HAVE_BLK_MQ_BUSY_TAG_ITER_FN_BOOL */

/* linux/blk-mq.h blk_mq_complete_request has 2 parameters */
/* #undef HAVE_BLK_MQ_COMPLETE_REQUEST_HAS_2_PARAMS */

/* blk-mq.h has blk_mq_complete_request_sync */
/* #undef HAVE_BLK_MQ_COMPLETE_REQUEST_SYNC */

/* blk_mq_delay_kick_requeue_list is defined */
#define HAVE_BLK_MQ_DELAY_KICK_REQUEUE_LIST 1

/* blk_mq_end_request accepts blk_status_t as second parameter */
#define HAVE_BLK_MQ_END_REQUEST_TAKES_BLK_STATUS_T 1

/* blk_mq_freeze_queue_wait is defined */
#define HAVE_BLK_MQ_FREEZE_QUEUE_WAIT 1

/* blk_mq_freeze_queue_wait_timeout is defined */
#define HAVE_BLK_MQ_FREEZE_QUEUE_WAIT_TIMEOUT 1

/* BLK_MQ_F_NO_SCHED is defined */
/* #undef HAVE_BLK_MQ_F_NO_SCHED */

/* blk-mq.h has enum hctx_type */
#define HAVE_BLK_MQ_HCTX_TYPE 1

/* blk_mq_map_queues is defined */
#define HAVE_BLK_MQ_MAP_QUEUES 1

/* struct blk_mq_ops has commit_rqs */
#define HAVE_BLK_MQ_OPS_COMMIT_RQS 1

/* linux/blk-mq.h blk_mq_ops exit_request has 3 parameters */
#define HAVE_BLK_MQ_OPS_EXIT_REQUEST_HAS_3_PARAMS 1

/* linux/blk-mq.h blk_mq_ops init_request has 4 parameters */
#define HAVE_BLK_MQ_OPS_INIT_REQUEST_HAS_4_PARAMS 1

/* struct blk_mq_ops has map_queue */
/* #undef HAVE_BLK_MQ_OPS_MAP_QUEUE */

/* struct blk_mq_ops has map_queues */
#define HAVE_BLK_MQ_OPS_MAP_QUEUES 1

/* struct blk_mq_ops has poll */
#define HAVE_BLK_MQ_OPS_POLL 1

/* include/linux/blk-mq-pci.h exists */
/* #undef HAVE_BLK_MQ_PCI_H */

/* blk_mq_pci_map_queues is defined */
/* #undef HAVE_BLK_MQ_PCI_MAP_QUEUES_3_ARGS */

/* linux/blk-mq.h has poll_fn 1 arg */
/* #undef HAVE_BLK_MQ_POLL_FN_1_ARG */

/* linux/blk-mq.h has struct blk_mq_queue_map */
#define HAVE_BLK_MQ_QUEUE_MAP 1

/* blk_mq_quiesce_queue exist */
#define HAVE_BLK_MQ_QUIESCE_QUEUE 1

/* linux/blk-mq-rdma.h has blk_mq_rdma_map_queues with map */
/* #undef HAVE_BLK_MQ_RDMA_MAP_QUEUES_MAP */

/* linux/blk-mq.h has blk_mq_request_completed */
#define HAVE_BLK_MQ_REQUEST_COMPLETED 1

/* blk-mq.h blk_mq_requeue_request has 2 parameters */
#define HAVE_BLK_MQ_REQUEUE_REQUEST_2_PARAMS 1

/* blk_mq_req_flags_t is defined */
#define HAVE_BLK_MQ_REQ_FLAGS_T 1

/* blk_mq_tagset_busy_iter is defined */
/* #undef HAVE_BLK_MQ_TAGSET_BUSY_ITER */

/* linux/blk-mq.h has blk_mq_tagset_wait_completed_request */
#define HAVE_BLK_MQ_TAGSET_WAIT_COMPLETED_REQUEST 1

/* blk_mq_tag_set member ops is const */
#define HAVE_BLK_MQ_TAG_SET_HAS_CONST_OPS 1

/* blk_mq_tag_set has member map */
#define HAVE_BLK_MQ_TAG_SET_HAS_MAP 1

/* blk_mq_unique_tag exist */
#define HAVE_BLK_MQ_UNIQUE_TAG 1

/* blk_mq_unquiesce_queue is defined */
#define HAVE_BLK_MQ_UNQUIESCE_QUEUE 1

/* blk_mq_update_nr_hw_queues is defined */
#define HAVE_BLK_MQ_UPDATE_NR_HW_QUEUES 1

/* blk_path_error is defined */
#define HAVE_BLK_PATH_ERROR 1

/* blk_queue_flag_set is defined */
#define HAVE_BLK_QUEUE_FLAG_SET 1

/* blk_queue_make_request existing */
/* #undef HAVE_BLK_QUEUE_MAKE_REQUEST */

/* blk_queue_max_write_zeroes_sectors is defined */
/* #undef HAVE_BLK_QUEUE_MAX_WRITE_ZEROES_SECTORS */

/* blk_queue_split has 1 param */
/* #undef HAVE_BLK_QUEUE_SPLIT_1_PARAM */

/* blk_queue_virt_boundary exist */
/* #undef HAVE_BLK_QUEUE_VIRT_BOUNDARY */

/* blkdev.h has blk_queue_write_cache */
/* #undef HAVE_BLK_QUEUE_WRITE_CACHE */

/* blk_rq_append_bio is defined */
/* #undef HAVE_BLK_RQ_APPEND_BIO */

/* blk_rq_is_passthrough is defined */
/* #undef HAVE_BLK_RQ_IS_PASSTHROUGH */

/* blk_rq_nr_discard_segments is defined */
/* #undef HAVE_BLK_RQ_NR_DISCARD_SEGMENTS */

/* blk_rq_payload_bytes exist */
/* #undef HAVE_BLK_RQ_NR_PAYLOAD_BYTES */

/* blk_rq_nr_phys_segments exist */
/* #undef HAVE_BLK_RQ_NR_PHYS_SEGMENTS */

/* blk_status_t is defined */
#define HAVE_BLK_STATUS_T 1

/* REQ_DRV is defined */
#define HAVE_BLK_TYPES_REQ_DRV 1

/* REQ_HIPRI is defined */
/* #undef HAVE_BLK_TYPES_REQ_HIPRI */

/* REQ_INTEGRITY is defined */
#define HAVE_BLK_TYPES_REQ_INTEGRITY 1

/* REQ_OP_DISCARD is defined */
#define HAVE_BLK_TYPES_REQ_OP_DISCARD 1

/* REQ_OP_DRV_OUT is defined */
/* #undef HAVE_BLK_TYPES_REQ_OP_DRV_OUT */

/* REQ_OP_FLUSH is defined */
#define HAVE_BLK_TYPES_REQ_OP_FLUSH 1

/* struct block_device_operations has submit_bio */
#define HAVE_BLOCK_DEVICE_OPERATIONS_SUBMIT_BIO 1

/* include/net/bonding.h exists */
#define HAVE_BONDING_H 1

/* bpf_prog_add\bfs_prog_inc functions return struct */
/* #undef HAVE_BPF_PROG_ADD_RET_STRUCT */

/* bpf_prog_aux has feild id */
#define HAVE_BPF_PROG_AUX_FEILD_ID 1

/* bpf_prog_inc is exported by the kernel */
#define HAVE_BPF_PROG_INC_EXPORTED 1

/* netdev_bpf has prog_attached */
/* #undef HAVE_BPF_PROG_PROG_ATTACHED */

/* bpf_prog_sub is defined */
#define HAVE_BPF_PROG_SUB 1

/* filter.h has bpf_warn_invalid_xdp_action get 3 params */
#define HAVE_BPF_WARN_IVALID_XDP_ACTION_GET_3_PARAMS 1

/* include/linux/build_bug.h exists */
#define HAVE_BUILD_BUG_H 1

/* build_skb is defined */
#define HAVE_BUILD_SKB 1

/* linux/srcu.h call_srcu is defined */
#define HAVE_CALL_SRCU 1

/* linux/cdev.h has cdev_set_parent */
#define HAVE_CDEV_SET_PARENT 1

/* __cgroup_bpf_run_filter_sysctl have 7 parameters */
#define HAVE_CGROUP_BPF_RUN_FILTER_SYSCTL_7_PARAMETERS 1

/* linux/cgroup_rdma exists */
#define HAVE_CGROUP_RDMA_H 1

/* CLASS_ATTR_STRING is defined */
#define HAVE_CLASS_ATTR_STRING 1

/* class devnode gets umode_t */
/* #undef HAVE_CLASS_DEVNODE_UMODE_T */

/* struct class has class_groups */
#define HAVE_CLASS_GROUPS 1

/* linux/srcu.h cleanup_srcu_struct_quiesced is defined */
/* #undef HAVE_CLEANUP_SRCU_STRUCT_QUIESCED */

/* cycle_t is defined in linux/clocksource.h */
/* #undef HAVE_CLOCKSOURCE_CYCLE_T */

/* default_groups is list_head */
#define HAVE_CONFIGFS_DEFAULT_GROUPS_LIST 1

/* if configfs_item_operations drop_link returns int */
/* #undef HAVE_CONFIGFS_DROP_LINK_RETURNS_INT */

/* argument 3 of config_group_init_type_name should const */
/* #undef HAVE_CONFIG_GROUP_INIT_TYPE_NAME_PARAM_3_IS_CONST */

/* const __read_once_size exist */
/* #undef HAVE_CONST_READ_ONCE_SIZE */

/* cpumask_available is defined */
#define HAVE_CPUMASK_AVAILABLE 1

/* cyclecounter_cyc2ns has 4 parameters */
#define HAVE_CYCLECOUNTER_CYC2NS_4_PARAMS 1

/* struct dcbnl_rtnl_ops has dcbnl_get/set buffer */
#define HAVE_DCBNL_GETBUFFER 1

/* struct dcbnl_rtnl_ops_ext is defined */
/* #undef HAVE_DCBNL_RTNL_OPS_EXTENDED */

/* getnumtcs returns int */
#define HAVE_DCBNL_RTNL_OPS_GETNUMTCS_RET_INT 1

/* debugfs_create_u8 function returns struct */
/* #undef HAVE_DEBUGFS_CREATE_U8_RET_STRUCT */

/* genhd.h has device_add_disk */
/* #undef HAVE_DEVICE_ADD_DISK */

/* genhd.h has device_add_disk */
/* #undef HAVE_DEVICE_ADD_DISK_3_ARGS */

/* struct device has dma_ops */
#define HAVE_DEVICE_DMA_OPS 1

/* device.h has device_remove_file_self */
#define HAVE_DEVICE_REMOVE_FILE_SELF 1

/* devlink.h has devlink_alloc get 3 params */
#define HAVE_DEVLINK_ALLOC_GET_3_PARAMS 1

/* devlink_param_driverinit_value_get exist */
/* #undef HAVE_DEVLINK_DRIVERINIT_VAL */

/* struct devlink_ops.eswitch_mode_set has extack */
#define HAVE_DEVLINK_ESWITCH_MODE_SET_EXTACK 1

/* devlink_flash_update_params has struct firmware fw */
#define HAVE_DEVLINK_FLASH_UPDATE_PARAMS_HAS_STRUCT_FW 1

/* devlink_fmsg_binary_pair_put exists */
/* #undef HAVE_DEVLINK_FMSG_BINARY_PAIR_PUT_ARG_U32 */

/* devlink_fmsg_binary_put exists */
/* #undef HAVE_DEVLINK_FMSG_BINARY_PUT */

/* include/net/devlink.h exists */
#define HAVE_DEVLINK_H 1

/* eswitch_encap_mode_set/get is defined */
#define HAVE_DEVLINK_HAS_ESWITCH_ENCAP_MODE_SET 1

/* eswitch_encap_mode_set/get is defined with enum */
#define HAVE_DEVLINK_HAS_ESWITCH_ENCAP_MODE_SET_GET_WITH_ENUM 1

/* eswitch_inline_mode_get/set is defined */
#define HAVE_DEVLINK_HAS_ESWITCH_INLINE_MODE_GET_SET 1

/* eswitch_mode_get/set is defined */
#define HAVE_DEVLINK_HAS_ESWITCH_MODE_GET_SET 1

/* flash_update is defined */
#define HAVE_DEVLINK_HAS_FLASH_UPDATE 1

/* info_get is defined */
#define HAVE_DEVLINK_HAS_INFO_GET 1

/* devlink_ops.reload is defined */
/* #undef HAVE_DEVLINK_HAS_RELOAD */

/* reload_up/down is defined */
#define HAVE_DEVLINK_HAS_RELOAD_UP_DOWN 1

/* devlink_health_reporter_state_update exist */
#define HAVE_DEVLINK_HEALTH_REPORTER_STATE_UPDATE 1

/* structs devlink_health_reporter & devlink_fmsg exist */
/* #undef HAVE_DEVLINK_HEALTH_REPORT_SUPPORT */

/* devlink_info_version_fixed_put exist */
#define HAVE_DEVLINK_INFO_VERSION_FIXED_PUT 1

/* devlink_net exist */
#define HAVE_DEVLINK_NET 1

/* struct devlink_ops has reload_up */
#define HAVE_DEVLINK_OPS_RELOAD_UP 1

/* struct devlink_param exist */
#define HAVE_DEVLINK_PARAM 1

/* devlink_params_publish is exported by the kernel */
/* #undef HAVE_DEVLINK_PARAMS_PUBLISHED */

/* struct devlink_param exist */
#define HAVE_DEVLINK_PARAM_GENERIC_ID_ENABLE_ROCE 1

/* struct devlink_param exist */
#define HAVE_DEVLINK_PARAM_GENERIC_ID_REGION_SNAPSHOT 1

/* struct devlink_region_ops is exists */
#define HAVE_DEVLINK_REGION_OPS 1

/* devlink_region_snapshot_create has 4 parameters */
/* #undef HAVE_DEVLINK_REGION_SNAPSHOT_CREATE_4_PARAM */

/* devlink_region_snapshot_id_get exists */
/* #undef HAVE_DEVLINK_REGION_SNAPSHOT_EXISTS */

/* devlink.h has devlink_register get 1 params */
#define HAVE_DEVLINK_REGISTER_GET_1_PARAMS 1

/* devlink_reload_disable exist */
/* #undef HAVE_DEVLINK_RELOAD_DISABLE */

/* reload_down has 3 params */
/* #undef HAVE_DEVLINK_RELOAD_DOWN_HAS_3_PARAMS */

/* reload_down has 5 params */
#define HAVE_DEVLINK_RELOAD_DOWN_SUPPORT_RELOAD_ACTION 1

/* devlink_reload_enable exist */
/* #undef HAVE_DEVLINK_RELOAD_ENABLE */

/* struct devlink_ops.reload has extack */
/* #undef HAVE_DEVLINK_RELOAD_HAS_EXTACK */

/* devlink.h has devlink_set_features */
/* #undef HAVE_DEVLINK_SET_FEATURES */

/* dev_alloc_page is defined */
#define HAVE_DEV_ALLOC_PAGE 1

/* dev_alloc_pages is defined */
#define HAVE_DEV_ALLOC_PAGES 1

/* if device.h(ppc) has struct dev_archdata with dma_data union and dma_offset
   in it */
/* #undef HAVE_DEV_ARCHDATA_DMA_OFFSET_IN_DMA_DATA_UNION */

/* device.h(ppc) has struct dev_arch_dmadata */
/* #undef HAVE_DEV_ARCH_DMADATA_DMA_OFFSET */

/* dev_change_flags has 3 parameters */
#define HAVE_DEV_CHANGE_FLAGS_HAS_3_PARAMS 1

/* struct class has dev_groups */
#define HAVE_DEV_GROUPS 1

/* dev_mc_del is defined */
#define HAVE_DEV_MC_DEL 1

/* set_latency_tolerance is defined */
#define HAVE_DEV_PM_INFO_SET_LATENCY_TOLERANCE 1

/* DEV_PM_QOS_LATENCY_TOLERANCE is defined */
#define HAVE_DEV_PM_QOS_LATENCY_TOLERANCE 1

/* DEV_PM_QOS_RESUME_LATENCY is defined */
#define HAVE_DEV_PM_QOS_RESUME_LATENCY 1

/* device.h has dev_vprintk_emit */
#define HAVE_DEV_PRINTK_EMIT 1

/* dev_uc_del is defined */
#define HAVE_DEV_UC_DEL 1

/* dev_xdp_prog_id is defined */
#define HAVE_DEV_XDP_PROG_ID 1

/* dma-attrs.h has struct dma_attrs */
/* #undef HAVE_DMA_ATTRS */

/* DMA_ATTR_NO_WARN is defined */
#define HAVE_DMA_ATTR_NO_WARN 1

/* struct dma_map_ops has cache_sync */
/* #undef HAVE_DMA_MAP_OPS_CACHE_SYNC */

/* struct dma_map_ops has map_resource */
/* #undef HAVE_DMA_MAP_OPS_MAP_RESOURCE */

/* dma_map_page_attrs is defined */
#define HAVE_DMA_MAP_PAGE_ATTRS 1

/* dma_pool_zalloc is defined */
#define HAVE_DMA_POOL_ZALLOC 1

/* dma_alloc_attrs takes unsigned long attrs */
#define HAVE_DMA_SET_ATTR_TAKES_UNSIGNED_LONG_ATTRS 1

/* dma-mapping.h has dma_zalloc_coherent function */
/* #undef HAVE_DMA_ZALLOC_COHERENT */

/* dst_get_neighbour is defined */
/* #undef HAVE_DST_GET_NEIGHBOUR */

/* dst_neigh_lookup is defined */
#define HAVE_DST_NEIGH_LOOKUP 1

/* elfcorehdr_addr is exported by the kernel */
#define HAVE_ELFCOREHDR_ADDR_EXPORTED 1

/* enum scsi_scan_mode is defined */
#define HAVE_ENUM_SCSI_SCAN_MODE 1

/* esp_output_fill_trailer is defined */
#define HAVE_ESP_OUTPUT_FILL_TRAILER 1

/* ether_addr_copy is defined */
#define HAVE_ETHER_ADDR_COPY 1

/* ethtool supprts 25G,50G,100G link speeds */
#define HAVE_ETHTOOL_25G_50G_100G_SPEEDS 1

/* ethtool supprts 50G-pre-lane link modes */
#define HAVE_ETHTOOL_50G_PER_LANE_LINK_MODES 1

/* struct ethtool_flow_ext is defined */
#define HAVE_ETHTOOL_FLOW_EXT 1

/* ethtool_flow_ext has h_dest */
#define HAVE_ETHTOOL_FLOW_EXT_H_DEST 1

/* union ethtool_flow_union is defined */
#define HAVE_ETHTOOL_FLOW_UNION 1

/* get/set_settings is defined */
/* #undef HAVE_ETHTOOL_GET_SET_SETTINGS */

/* struct ethtool_ops_ext is defined */
/* #undef HAVE_ETHTOOL_OPS_EXT */

/* ethtool_ops get_rxnfc gets u32 *rule_locs */
#define HAVE_ETHTOOL_OPS_GET_RXNFC_U32_RULE_LOCS 1

/* ETHTOOL_xLINKSETTINGS API is defined */
#define HAVE_ETHTOOL_xLINKSETTINGS 1

/* eth_get_headlen is defined with 2 params */
/* #undef HAVE_ETH_GET_HEADLEN_2_PARAMS */

/* eth_get_headlen is defined with 3 params */
#define HAVE_ETH_GET_HEADLEN_3_PARAMS 1

/* ETH_MIN_MTU exists */
#define HAVE_ETH_MIN_MTU 1

/* ETH_P_8021AD exists */
#define HAVE_ETH_P_8021AD 1

/* ETH_P_IBOE exists */
#define HAVE_ETH_P_IBOE 1

/* eth_random_addr is defined */
#define HAVE_ETH_RANDOM_ADDR 1

/* ETH_SS_RSS_HASH_FUNCS is defined */
#define HAVE_ETH_SS_RSS_HASH_FUNCS 1

/* fdget is defined */
#define HAVE_FDGET 1

/* function fib_info_nh exists */
#define HAVE_FIB_INFO_NH 1

/* fib_lookup has 4 params */
#define HAVE_FIB_LOOKUP_4_PARAMS 1

/* fib_lookup is exported by the kernel */
/* #undef HAVE_FIB_LOOKUP_EXPORTED */

/* fib_nh has fib_nh_dev */
#define HAVE_FIB_NH_DEV 1

/* fib_nh_notifier_info is defined */
#define HAVE_FIB_NH_NOTIFIER_INFO 1

/* fib_res_put */
/* #undef HAVE_FIB_RES_PUT */

/* struct devlink_ops flash_update get 3 params */
#define HAVE_FLASH_UPDATE_GET_3_PARAMS 1

/* tcf_queue_work has 2 params per prio */
#define HAVE_FLOWER_MULTI_MASK 1

/* flowi4, flowi6 is defined */
#define HAVE_FLOWI_AF_SPECIFIC_INSTANCES 1

/* struct flow_block_offload exists */
#define HAVE_FLOW_BLOCK_OFFLOAD 1

/* struct flow_cls_offload exists */
#define HAVE_FLOW_CLS_OFFLOAD 1

/* FLOW_DISSECTOR_KEY_CVLAN is defined */
#define HAVE_FLOW_DISSECTOR_KEY_CVLAN 1

/* FLOW_DISSECTOR_KEY_ENC_IP is defined */
#define HAVE_FLOW_DISSECTOR_KEY_ENC_IP 1

/* flow_dissector.h has FLOW_DISSECTOR_KEY_ENC_KEYID */
#define HAVE_FLOW_DISSECTOR_KEY_ENC_KEYID 1

/* FLOW_DISSECTOR_KEY_ENC_OPTS is defined */
#define HAVE_FLOW_DISSECTOR_KEY_ENC_OPTS 1

/* FLOW_DISSECTOR_KEY_IP is defined */
#define HAVE_FLOW_DISSECTOR_KEY_IP 1

/* FLOW_DISSECTOR_KEY_MPLS is defined */
#define HAVE_FLOW_DISSECTOR_KEY_MPLS 1

/* FLOW_DISSECTOR_KEY_TCP is defined */
#define HAVE_FLOW_DISSECTOR_KEY_TCP 1

/* FLOW_DISSECTOR_KEY_VLAN is defined */
#define HAVE_FLOW_DISSECTOR_KEY_VLAN 1

/* HAVE_FLOW_DISSECTOR_KEY_VLAN_TPID is defined */
#define HAVE_FLOW_DISSECTOR_KEY_VLAN_TPID 1

/* flow_dissector.h has dissector_uses_key */
#define HAVE_FLOW_DISSECTOR_USES_KEY 1

/* flow_indr_dev_setup_offload is defined */
/* #undef HAVE_FLOW_INDR_DEV_SETUP_OFFLOAD */

/* flow_rule_match_cvlan is exported by the kernel */
#define HAVE_FLOW_RULE_MATCH_CVLAN 1

/* FOLL_LONGTERM is defined */
#define HAVE_FOLL_LONGTERM 1

/* for_ifa defined */
/* #undef HAVE_FOR_IFA */

/* struct kiocb is defined in linux/fs.h */
#define HAVE_FS_HAS_KIOCB 1

/* gettimex64 is defined */
#define HAVE_GETTIMEX64 1

/* HAVE_GET_MODULE_EEPROM is defined */
#define HAVE_GET_MODULE_EEPROM 1

/* HAVE_GET_MODULE_EEPROM_EXT is defined */
/* #undef HAVE_GET_MODULE_EEPROM_EXT */

/* get_net_ns_by_fd is exported by the kernel */
#define HAVE_GET_NET_NS_BY_FD_EXPORTED 1

/* get_pid_task is exported by the kernel */
#define HAVE_GET_PID_TASK_EXPORTED 1

/* ndo_get_ringparam get 4 parameters */
#define HAVE_GET_RINGPARAM_GET_4_PARAMS 1

/* get/set_channels is defined */
#define HAVE_GET_SET_CHANNELS 1

/* get/set_channels is defined in ethtool_ops_ext */
/* #undef HAVE_GET_SET_CHANNELS_EXT */

/* HAVE_GET_SET_DUMP is defined */
#define HAVE_GET_SET_DUMP 1

/* get/set_fecparam is defined */
#define HAVE_GET_SET_FECPARAM 1

/* get/set_flags is defined */
/* #undef HAVE_GET_SET_FLAGS */

/* get/set_link_ksettings is defined */
#define HAVE_GET_SET_LINK_KSETTINGS 1

/* get/set_msglevel is defined */
#define HAVE_GET_SET_MSGLEVEL 1

/* get/set_priv_flags is defined */
#define HAVE_GET_SET_PRIV_FLAGS 1

/* get/set_rxfh is defined */
#define HAVE_GET_SET_RXFH 1

/* get/set_rxfh_indir is defined */
/* #undef HAVE_GET_SET_RXFH_INDIR */

/* get/set_rxfh_indir is defined */
/* #undef HAVE_GET_SET_RXFH_INDIR_EXT */

/* get/set_rx_csum is defined */
/* #undef HAVE_GET_SET_RX_CSUM */

/* get/set_sg is defined */
/* #undef HAVE_GET_SET_SG */

/* get/set_tso is defined */
/* #undef HAVE_GET_SET_TSO */

/* get/set_tunable is defined */
#define HAVE_GET_SET_TUNABLE 1

/* get/set_tx_csum is defined */
/* #undef HAVE_GET_SET_TX_CSUM */

/* get_task_comm is exported by the kernel */
/* #undef HAVE_GET_TASK_COMM_EXPORTED */

/* get_task_pid is exported by the kernel */
#define HAVE_GET_TASK_PID_EXPORTED 1

/* get_ts_info is defined */
#define HAVE_GET_TS_INFO 1

/* get_ts_info is defined in ethtool_ops_ext */
/* #undef HAVE_GET_TS_INFO_EXT */

/* GET_UNUSED_FD_FLAGS is defined */
#define HAVE_GET_UNUSED_FD_FLAGS 1

/* get_user_pages has 7 params */
/* #undef HAVE_GET_USER_PAGES_7_PARAMS */

/* get_user_pages has 8 params */
/* #undef HAVE_GET_USER_PAGES_8_PARAMS */

/* NESTED: get_user_pages uses gup_flags */
/* #undef HAVE_GET_USER_PAGES_GUP_FLAGS */

/* get_user_pages_longterm is defined */
/* #undef HAVE_GET_USER_PAGES_LONGTERM */

/* get_user_pages_remote is defined with 7 parameters */
/* #undef HAVE_GET_USER_PAGES_REMOTE_7_PARAMS */

/* get_user_pages_remote is defined with 8 parameters */
/* #undef HAVE_GET_USER_PAGES_REMOTE_8_PARAMS */

/* get_user_pages_remote is defined with 8 parameters with locked */
/* #undef HAVE_GET_USER_PAGES_REMOTE_8_PARAMS_W_LOCKED */

/* gfpflags_allow_blocking is defined */
#define HAVE_GFPFLAGES_ALLOW_BLOCKING 1

/* __GFP_DIRECT_RECLAIM is defined */
#define HAVE_GFP_DIRECT_RECLAIM 1

/* guid_parse is defined */
#define HAVE_GUID_PARSE 1

/* devlink_health_reporter_ops.recover has extack */
#define HAVE_HEALTH_REPORTER_RECOVER_HAS_EXTACK 1

/* hex2bin return value exists */
/* #undef HAVE_HEX2BIN_NOT_VOID */

/* hlist_for_each_entry has 3 params */
#define HAVE_HLIST_FOR_EACH_ENTRY_3_PARAMS 1

/* HWTSTAMP_FILTER_NTP_ALL is defined */
#define HAVE_HWTSTAMP_FILTER_NTP_ALL 1

/* icmpv6_send has 4 parameters */
#define HAVE_ICMPV6_SEND_4_PARAMS 1

/* ida_alloc is defined */
#define HAVE_IDA_ALLOC 1

/* ida_alloc_max is defined */
#define HAVE_IDA_ALLOC_MAX 1

/* ida_is_empty is defined */
#define HAVE_IDA_IS_EMPTY 1

/* ida_simple_get is defined */
/* #undef HAVE_IDA_SIMPLE_GET */

/* idr_alloc is defined */
#define HAVE_IDR_ALLOC 1

/* idr_for_each_entry is defined */
#define HAVE_IDR_FOR_EACH_ENTRY 1

/* idr_get_next is exported by the kernel */
#define HAVE_IDR_GET_NEXT_EXPORTED 1

/* idr_get_next_ul is exported by the kernel */
#define HAVE_IDR_GET_NEXT_UL_EXPORTED 1

/* idr_is_empty is defined */
/* #undef HAVE_IDR_IS_EMPTY */

/* idr_preload_end is defined */
#define HAVE_IDR_PRELOAD_END 1

/* idr_preload is exported by the kernel */
#define HAVE_IDR_PRELOAD_EXPORTED 1

/* idr_remove return value exists */
#define HAVE_IDR_REMOVE_RETURN_VALUE 1

/* struct idr has idr_rt */
#define HAVE_IDR_RT 1

/* ieee_getets/ieee_setets is defined and dcbnl defined */
#define HAVE_IEEE_DCBNL_ETS 1

/* ieee_getqcn is defined */
#define HAVE_IEEE_GETQCN 1

/* ieee_getmaxrate/ieee_setmaxrate is defined */
#define HAVE_IEEE_GET_SET_MAXRATE 1

/* trust is defined */
#define HAVE_IFLA_VF_IB_NODE_PORT_GUID 1

/* struct ifla_vf_info is defined */
#define HAVE_IFLA_VF_INFO 1

/* struct ifla_vf_stats is defined */
#define HAVE_IFLA_VF_STATS 1

/* if_list is defined */
#define HAVE_INET6_IF_LIST 1

/* inet_addr_is_any is defined */
#define HAVE_INET_ADDR_IS_ANY 1

/* inet_confirm_addr has 5 parameters */
#define HAVE_INET_CONFIRM_ADDR_5_PARAMS 1

/* inet_confirm_addr is exported by the kernel */
#define HAVE_INET_CONFIRM_ADDR_EXPORTED 1

/* inet_get_local_port_range has 3 parameters */
#define HAVE_INET_GET_LOCAL_PORT_RANGE_3_PARAMS 1

/* include/linux/inet_lro.h exists */
/* #undef HAVE_INET_LRO_H */

/* inet_pton_with_scope is defined */
#define HAVE_INET_PTON_WITH_SCOPE 1

/* include/linux/interval_tree_generic.h exists */
#define HAVE_INTERVAL_TREE_GENERIC_H 1

/* INTERVAL_TREE takes rb_root */
/* #undef HAVE_INTERVAL_TREE_TAKES_RB_ROOT */

/* Define to 1 if you have the <inttypes.h> header file. */
#define HAVE_INTTYPES_H 1

/* invalidate_page defined */
/* #undef HAVE_INVALIDATE_PAGE */

/* fs.h has IOCB_NOWAIT */
#define HAVE_IOCB_NOWAIT 1

/* struct iova_rcache is defined in iova.h */
#define HAVE_IOVA_RCACHE 1

/* linux/io-64-nonatomic-lo-hi.h exists */
#define HAVE_IO_64_NONATOMIC_LO_HI_H 1

/* io_mapping_map_wc has 3 params */
#define HAVE_IO_MAPPING_MAP_WC_3_PARAMS 1

/* ip4_dst_hoplimit is defined */
#define HAVE_IP4_DST_HOPLIMIT 1

/* ip6_dst_hoplimit is exported by the kernel */
#define HAVE_IP6_DST_HOPLIMIT 1

/* ip6_make_flowinfo is defined */
#define HAVE_IP6_MAKE_FLOWINFO 1

/* ip6_rt_put is defined */
#define HAVE_IP6_RT_PUT 1

/* IP6_ECN_set_ce has 2 parameters */
#define HAVE_IP6_SET_CE_2_PARAMS 1

/* ipv6_addr_copy is defined */
/* #undef HAVE_IPV6_ADDR_COPY */

/* ipv6_chk_addr accepts a const second parameter */
#define HAVE_IPV6_CHK_ADDR_TAKES_CONST 1

/* if ipv6_stub has ipv6_dst_lookup_flow */
/* #undef HAVE_IPV6_DST_LOOKUP_FLOW */

/* ipv6_dst_lookup takes net */
/* #undef HAVE_IPV6_DST_LOOKUP_TAKES_NET */

/* ipv6_mod_enabled is defined */
#define HAVE_IPV6_MOD_ENABLED 1

/* ipv6_stub is defined */
/* #undef HAVE_IPV6_STUB */

/* net/ipv6_stubs.h exists */
#define HAVE_IPV6_STUBS_H 1

/* uapi ethtool has IPV6_USER_FLOW */
#define HAVE_IPV6_USER_FLOW 1

/* struct ip_tunnel_info is defined */
#define HAVE_IP_TUNNEL_INFO 1

/* struct irq_affinity has priv */
#define HAVE_IRQ_AFFINITY_PRIV 1

/* irq_calc_affinity_vectors is defined */
#define HAVE_IRQ_CALC_AFFINITY_VECTORS_3_ARGS 1

/* irq_data member affinity is defined */
/* #undef HAVE_IRQ_DATA_AFFINITY */

/* irq_desc_get_irq_data is defined */
#define HAVE_IRQ_DESC_GET_IRQ_DATA 1

/* include/linux/irq_poll.h exists */
#define HAVE_IRQ_POLL_H 1

/* irq_set_affinity_hint is defined */
#define HAVE_IRQ_SET_AFFINITY_HINT 1

/* irq_to_desc is exported by the kernel */
/* #undef HAVE_IRQ_TO_DESC_EXPORTED */

/* iscsit_find_cmd_from_itt is defined */
#define HAVE_ISCSIT_FIND_CMD_FROM_ITT 1

/* iscsit_set_unsolicited_dataout is defined */
#define HAVE_ISCSIT_SET_UNSOLICITED_DATAOUT 1

/* iscsit_transport has member iscsit_get_sup_prot_ops */
/* #undef HAVE_ISCSIT_TRANSPORT_HAS_GET_SUP_PROT_OPS */

/* iscsit_get_rx_pdu is defined */
/* #undef HAVE_ISCSIT_TRANSPORT_ISCSIT_GET_RX_PDU */

/* rdma_shutdown is defined */
#define HAVE_ISCSIT_TRANSPORT_RDMA_SHUTDOWN 1

/* attr_is_visible is defined */
#define HAVE_ISCSI_ATTR_IS_VISIBLE 1

/* iscsi_proto.h has structure iscsi_cmd */
/* #undef HAVE_ISCSI_CMD */

/* iscsi_conn has members local_sockaddr */
/* #undef HAVE_ISCSI_CONN_LOCAL_SOCKADDR */

/* iscsi_conn has member login_sockaddr */
/* #undef HAVE_ISCSI_CONN_LOGIN_SOCKADDR */

/* iscsi_conn_unbind is defined */
#define HAVE_ISCSI_CONN_UNBIND 1

/* struct iscsi_session has discovery_sess */
#define HAVE_ISCSI_DISCOVERY_SESSION 1

/* iscsi_eh_cmd_timed_out is defined */
/* #undef HAVE_ISCSI_EH_CMD_TIMED_OUT */

/* get_ep_param is defined */
#define HAVE_ISCSI_GET_EP_PARAM 1

/* libiscsi.h iscsi_host_remove has 2 parameters */
#define HAVE_ISCSI_HOST_REMOVE_2_PARAMS 1

/* iscsi_target_core.h and iscsi_target_stat.h are under include/ */
#define HAVE_ISCSI_TARGET_CORE_ISCSI_TARGET_STAT_H 1

/* check_protection is defined */
#define HAVE_ISCSI_TRANSPORT_CHECK_PROTECTION 1

/* is_pci_p2pdma_page is defined */
#define HAVE_IS_PCI_P2PDMA_PAGE 1

/* is_tcf_csum is defined */
/* #undef HAVE_IS_TCF_CSUM */

/* __is_tcf_gact_act is defined with 3 variables */
#define HAVE_IS_TCF_GACT_ACT 1

/* __is_tcf_gact_act is defined with 2 variables */
/* #undef HAVE_IS_TCF_GACT_ACT_OLD */

/* is_tcf_gact_goto_chain is defined */
#define HAVE_IS_TCF_GACT_GOTO_CHAIN 1

/* is_tcf_gact_ok is defined */
#define HAVE_IS_TCF_GACT_OK 1

/* is_tcf_gact_shot is defined */
#define HAVE_IS_TCF_GACT_SHOT 1

/* is_tcf_mirred_egress_mirror is defined */
#define HAVE_IS_TCF_MIRRED_EGRESS_MIRROR 1

/* is_tcf_mirred_egress_redirect is defined */
#define HAVE_IS_TCF_MIRRED_EGRESS_REDIRECT 1

/* is_tcf_mirred_mirror is defined */
/* #undef HAVE_IS_TCF_MIRRED_MIRROR */

/* is_tcf_mirred_redirect is defined */
/* #undef HAVE_IS_TCF_MIRRED_REDIRECT */

/* is_tcf_police is defined */
/* #undef HAVE_IS_TCF_POLICE */

/* is_tcf_skbedit_mark is defined */
#define HAVE_IS_TCF_SKBEDIT_MARK 1

/* is_tcf_tunnel_set and is_tcf_tunnel_release are defined */
#define HAVE_IS_TCF_TUNNEL 1

/* is_tcf_vlan is defined */
/* #undef HAVE_IS_TCF_VLAN */

/* is_vlan_dev is defined */
#define HAVE_IS_VLAN_DEV 1

/* is_vlan_dev get const */
#define HAVE_IS_VLAN_DEV_CONST 1

/* kcalloc_node is defined */
#define HAVE_KCALLOC_NODE 1

/* linux/net.h has kernel_getsockname 2 parameters */
#define HAVE_KERNEL_GETSOCKNAME_2_PARAMS 1

/* kfree_const is defined */
#define HAVE_KFREE_CONST 1

/* kmalloc_array is defined */
#define HAVE_KMALLOC_ARRAY 1

/* kmalloc_array_node is defined */
#define HAVE_KMALLOC_ARRAY_NODE 1

/* highmem.h has kmap_atomic function with km_type */
/* #undef HAVE_KM_TYPE */

/* kobj_ns_grab_current is exported by the kernel */
#define HAVE_KOBJ_NS_GRAB_CURRENT_EXPORTED 1

/* kref_get_unless_zero is defined */
#define HAVE_KREF_GET_UNLESS_ZERO 1

/* kref_read is defined */
#define HAVE_KREF_READ 1

/* kstrtobool is defined */
#define HAVE_KSTRTOBOOL 1

/* kthread_queue_work is defined */
#define HAVE_KTHREAD_QUEUE_WORK 1

/* struct kthread_work is defined */
#define HAVE_KTHREAD_WORK 1

/* ktime_get_boot_ns is defined */
/* #undef HAVE_KTIME_GET_BOOT_NS */

/* ktime_get_ns defined */
#define HAVE_KTIME_GET_NS 1

/* ktime_get_real_ns is defined */
#define HAVE_KTIME_GET_REAL_NS 1

/* ktime is union and has tv64 */
/* #undef HAVE_KTIME_UNION_TV64 */

/* ktls related structs exists */
#define HAVE_KTLS_STRUCTS 1

/* kvcalloc is defined */
#define HAVE_KVCALLOC 1

/* kvfree is defined */
#define HAVE_KVFREE 1

/* kvmalloc is defined */
#define HAVE_KVMALLOC 1

/* kvmalloc_array is defined */
#define HAVE_KVMALLOC_ARRAY 1

/* kvmalloc_node is defined */
#define HAVE_KVMALLOC_NODE 1

/* kvzalloc is defined */
#define HAVE_KVZALLOC 1

/* kvzalloc_node is defined */
#define HAVE_KVZALLOC_NODE 1

/* enum netdev_lag_tx_type is defined */
#define HAVE_LAG_TX_TYPE 1

/* linux/lightnvm.h exists */
/* #undef HAVE_LIGHTNVM_H */

/* linkstate is defined */
#define HAVE_LINKSTATE 1

/* uapi/bpf.h exists */
#define HAVE_LINUX_BPF_H 1

/* linux/bpf_trace exists */
#define HAVE_LINUX_BPF_TRACE_H 1

/* linux/hashtable.h exists */
#define HAVE_LINUX_HASHTABLE_H 1

/* linux/nvme-fc-driver.h exists */
#define HAVE_LINUX_NVME_FC_DRIVER_H 1

/* linux/overflow.h is defined */
#define HAVE_LINUX_OVERFLOW_H 1

/* linux/printk.h is defined */
#define HAVE_LINUX_PRINTK_H 1

/* linux/sed-opal.h exists */
/* #undef HAVE_LINUX_SED_OPAL_H */

/* include/linux/siphash.h exists */
#define HAVE_LINUX_SIPHASH_H 1

/* linux/xz.h exists */
#define HAVE_LINUX_XZ_H 1

/* linux/lockdep.h has lockdep_assert_held_exclusive */
/* #undef HAVE_LOCKUP_ASSERT_HELD_EXCLUSIVE */

/* linux/lockdep.h has lockdep_assert_held_write */
#define HAVE_LOCKUP_ASSERT_HELD_WRITE 1

/* memalloc_noio_save is defined */
#define HAVE_MEMALLOC_NOIO_SAVE 1

/* memchr_inv is defined */
#define HAVE_MEMCHR_INV 1

/* memcpy_and_pad is defined */
#define HAVE_MEMCPY_AND_PAD 1

/* memdup_user_nul is defined */
#define HAVE_MEMDUP_USER_NUL 1

/* Define to 1 if you have the <memory.h> header file. */
#define HAVE_MEMORY_H 1

/* linux/string.h memzero_explicit is defined */
#define HAVE_MEMZERO_EXPLICIT 1

/* miniflow exists */
/* #undef HAVE_MINIFLOW */

/* mmget is defined */
#define HAVE_MMGET 1

/* NESTED: mmget_not_zero is defined */
#define HAVE_MMGET_NOT_ZERO 1

/* mmget_still_valid is defined */
/* #undef HAVE_MMGET_STILL_VALID */

/* mmget_still_valid is defined in linux/mm.h */
/* #undef HAVE_MMGET_STILL_VALID_IN_MM_H */

/* mmget_still_valid is defined in linux/sched.h */
/* #undef HAVE_MMGET_STILL_VALID_IN_SCHED_H */

/* mmgrab is defined */
#define HAVE_MMGRAB 1

/* mmu_notifier_call_srcu defined */
/* #undef HAVE_MMU_NOTIFIER_CALL_SRCU */

/* mmu_notifier_mm has lock */
/* #undef HAVE_MMU_NOTIFIER_HAS_LOCK */

/* mmu_notifier_range_blockable defined */
#define HAVE_MMU_NOTIFIER_RANGE_BLOCKABLE 1

/* ib_umem_notifier_invalidate_range_start get struct mmu_notifier_range */
#define HAVE_MMU_NOTIFIER_RANGE_STRUCT 1

/* mmu_notifier_unregister_no_release defined */
/* #undef HAVE_MMU_NOTIFIER_UNREGISTER_NO_RELEASE */

/* mm_context_add_copro is defined */
/* #undef HAVE_MM_CONTEXT_ADD_COPRO */

/* struct page has _count */
/* #undef HAVE_MM_PAGE__COUNT */

/* mm_types.h struct mm_struct has free_area_cache */
/* #undef HAVE_MM_STRUCT_FREE_AREA_CACHE */

/* struct mm_struct has member notifier_subscriptions */
#define HAVE_MM_STRUCT_HAS_NOTIFIER_SUBSCRIPTION 1

/* moduleparam.h has kernel_param_ops */
#define HAVE_MODULEPARAM_KERNEL_PARAM_OPS 1

/* mq_rq_state is defined */
/* #undef HAVE_MQ_RQ_STATE */

/* napi_alloc_skb is defined */
#define HAVE_NAPI_ALLOC_SKB 1

/* napi_complete_done is defined */
#define HAVE_NAPI_COMPLETE_DONE 1

/* napi_consume_skb is defined */
#define HAVE_NAPI_CONSUME_SKB 1

/* napi_gro_flush has 2 parameters */
/* #undef HAVE_NAPI_GRO_FLUSH_2_PARAMS */

/* napi_schedule_irqoff is defined */
#define HAVE_NAPI_SCHEDULE_IRQOFF 1

/* NAPI_STATE_MISSED is defined */
#define HAVE_NAPI_STATE_MISSED 1

/* NAPI_STATE_NO_BUSY_POLL is defined */
#define HAVE_NAPI_STATE_NO_BUSY_POLL 1

/* ndo_add_vxlan_port is defined */
/* #undef HAVE_NDO_ADD_VXLAN_PORT */

/* ndo_bridge_getlink is defined */
/* #undef HAVE_NDO_BRIDGE_GETLINK */

/* ndo_bridge_getlink is defined */
#define HAVE_NDO_BRIDGE_GETLINK_NLFLAGS 1

/* ndo_bridge_setlink is defined */
/* #undef HAVE_NDO_BRIDGE_SETLINK */

/* ndo_bridge_setlink is defined */
#define HAVE_NDO_BRIDGE_SETLINK_EXTACK 1

/* ndo_busy_poll is defined */
/* #undef HAVE_NDO_BUSY_POLL */

/* extended ndo_change_mtu is defined */
/* #undef HAVE_NDO_CHANGE_MTU_EXTENDED */

/* extended ndo_change_mtu_rh74 is defined */
/* #undef HAVE_NDO_CHANGE_MTU_RH74 */

/* ndo_dflt_bridge_getlink is defined */
/* #undef HAVE_NDO_DFLT_BRIDGE_GETLINK */

/* ndo_dflt_bridge_getlink is defined */
/* #undef HAVE_NDO_DFLT_BRIDGE_GETLINK_FLAG_MASK */

/* ndo_dflt_bridge_getlink is defined */
/* #undef HAVE_NDO_DFLT_BRIDGE_GETLINK_FLAG_MASK_NFLAGS */

/* ndo_dflt_bridge_getlink is defined */
#define HAVE_NDO_DFLT_BRIDGE_GETLINK_FLAG_MASK_NFLAGS_FILTER 1

/* ndo_fix_features is defined */
#define HAVE_NDO_FIX_FEATURES 1

/* if getapp returns int */
#define HAVE_NDO_GETAPP_RETURNS_INT 1

/* if getnumtcs returns int */
#define HAVE_NDO_GETNUMTCS_RETURNS_INT 1

/* ndo_get_coalesce get 4 parameters */
#define HAVE_NDO_GET_COALESCE_GET_4_PARAMS 1

/* ndo_get_iflink is defined */
#define HAVE_NDO_GET_IFLINK 1

/* ndo_get_offload_stats is defined */
#define HAVE_NDO_GET_OFFLOAD_STATS 1

/* extended ndo_get_offload_stats is defined */
/* #undef HAVE_NDO_GET_OFFLOAD_STATS_EXTENDED */

/* ndo_get_phys_port_name is defined */
#define HAVE_NDO_GET_PHYS_PORT_NAME 1

/* is defined */
/* #undef HAVE_NDO_GET_PHYS_PORT_NAME_EXTENDED */

/* HAVE_NDO_GET_PORT_PARENT_ID is defined */
#define HAVE_NDO_GET_PORT_PARENT_ID 1

/* ndo_get_stats64 is defined */
/* #undef HAVE_NDO_GET_STATS64 */

/* ndo_get_stats64 is defined and returns void */
#define HAVE_NDO_GET_STATS64_RET_VOID 1

/* ndo_get_vf_stats is defined */
#define HAVE_NDO_GET_VF_STATS 1

/* ndo_gso_check is defined */
/* #undef HAVE_NDO_GSO_CHECK */

/* ndo_has_offload_stats gets net_device */
/* #undef HAVE_NDO_HAS_OFFLOAD_STATS_EXTENDED */

/* ndo_has_offload_stats gets net_device */
#define HAVE_NDO_HAS_OFFLOAD_STATS_GETS_NET_DEVICE 1

/* ndo_vlan_rx_add_vid has 2 parameters and returns int */
/* #undef HAVE_NDO_RX_ADD_VID_HAS_2_PARAMS_RET_INT */

/* ndo_vlan_rx_add_vid has 3 parameters */
#define HAVE_NDO_RX_ADD_VID_HAS_3_PARAMS 1

/* ndo_rx_flow_steer is defined */
#define HAVE_NDO_RX_FLOW_STEER 1

/* ndo_select_queue has 3 params with no fallback */
#define HAVE_NDO_SELECT_QUEUE_HAS_3_PARMS_NO_FALLBACK 1

/* ndo_select_queue has accel_priv */
/* #undef HAVE_NDO_SELECT_QUEUE_HAS_ACCEL_PRIV */

/* if setapp returns int */
#define HAVE_NDO_SETAPP_RETURNS_INT 1

/* ndo_setup_tc is defined */
#define HAVE_NDO_SETUP_TC 1

/* ndo_setup_tc takes 4 parameters */
/* #undef HAVE_NDO_SETUP_TC_4_PARAMS */

/* ndo_setup_tc_rh is defined */
/* #undef HAVE_NDO_SETUP_TC_RH_EXTENDED */

/* ndo_setup_tc takes chain_index */
/* #undef HAVE_NDO_SETUP_TC_TAKES_CHAIN_INDEX */

/* ndo_setup_tc takes tc_setup_type */
#define HAVE_NDO_SETUP_TC_TAKES_TC_SETUP_TYPE 1

/* ndo_set_features is defined */
#define HAVE_NDO_SET_FEATURES 1

/* ndo_set_tx_maxrate is defined */
#define HAVE_NDO_SET_TX_MAXRATE 1

/* extended ndo_set_tx_maxrate is defined */
/* #undef HAVE_NDO_SET_TX_MAXRATE_EXTENDED */

/* ndo_set_vf_guid is defined */
#define HAVE_NDO_SET_VF_GUID 1

/* ndo_set_vf_mac is defined */
#define HAVE_NDO_SET_VF_MAC 1

/* ndo_set_vf_vlan is defined in net_device_ops */
#define HAVE_NDO_SET_VF_VLAN 1

/* ndo_set_vf_vlan is defined in net_device_ops_extended */
/* #undef HAVE_NDO_SET_VF_VLAN_EXTENDED */

/* ndo_tx_timeout get 2 params */
#define HAVE_NDO_TX_TIMEOUT_GET_2_PARAMS 1

/* ndo_add_vxlan_port is defined */
/* #undef HAVE_NDO_UDP_TUNNEL_ADD */

/* extended ndo_add_vxlan_port is defined */
/* #undef HAVE_NDO_UDP_TUNNEL_ADD_EXTENDED */

/* net_device_ops has ndo_xdp is defined */
#define HAVE_NDO_XDP 1

/* extended ndo_xdp is defined */
/* #undef HAVE_NDO_XDP_EXTENDED */

/* ndo_xdp_flush is defined */
/* #undef HAVE_NDO_XDP_FLUSH */

/* net_device_ops has ndo_xdp_xmit is defined */
#define HAVE_NDO_XDP_XMIT 1

/* netdev_bonding_info is defined */
#define HAVE_NETDEV_BONDING_INFO 1

/* is defined */
/* #undef HAVE_NETDEV_EXTENDED_DEV_PORT */

/* is defined */
/* #undef HAVE_NETDEV_EXTENDED_HW_FEATURES */

/* is defined */
/* #undef HAVE_NETDEV_EXTENDED_NDO_BUSY_POLL */

/* is defined */
/* #undef HAVE_NETDEV_EXTENDED_WANTED_FEATURES */

/* ndo_get_phys_port_id is defined */
/* #undef HAVE_NETDEV_EXT_NDO_GET_PHYS_PORT_ID */

/* netdev_features_t is defined */
#define HAVE_NETDEV_FEATURES_T 1

/* netdev_master_upper_dev_get_rcu is defined */
/* #undef HAVE_NETDEV_FOR_EACH_ALL_UPPER_DEV_RCU */

/* netdev_for_each_lower_dev is defined */
#define HAVE_NETDEV_FOR_EACH_LOWER_DEV 1

/* netdev_for_each_mc_addr is defined */
#define HAVE_NETDEV_FOR_EACH_MC_ADDR 1

/* netdev_get_num_tc is defined */
#define HAVE_NETDEV_GET_NUM_TC 1

/* netdev_get_tx_queue is defined */
#define HAVE_NETDEV_GET_TX_QUEUE 1

/* netdev_has_upper_dev_all_rcu is defined */
#define HAVE_NETDEV_HAS_UPPER_DEV_ALL_RCU 1

/* hw_enc_features is defined */
#define HAVE_NETDEV_HW_ENC_FEATURES 1

/* hw_features is defined */
#define HAVE_NETDEV_HW_FEATURES 1

/* IFF_LIVE_ADDR_CHANGE is defined */
#define HAVE_NETDEV_IFF_LIVE_ADDR_CHANGE 1

/* IFF_UNICAST_FLT is defined */
#define HAVE_NETDEV_IFF_UNICAST_FLT 1

/* netdev_master_upper_dev_get is defined */
#define HAVE_NETDEV_MASTER_UPPER_DEV_GET 1

/* netdev_master_upper_dev_get_rcu is defined */
#define HAVE_NETDEV_MASTER_UPPER_DEV_GET_RCU 1

/* netdev_master_upper_dev_link gets 4 parameters */
/* #undef HAVE_NETDEV_MASTER_UPPER_DEV_LINK_4_PARAMS */

/* netdev_master_upper_dev_link gets 5 parameters */
#define HAVE_NETDEV_MASTER_UPPER_DEV_LINK_5_PARAMS 1

/* mpls_features is defined */
#define HAVE_NETDEV_MPLS_FEATURES 1

/* is defined */
/* #undef HAVE_NETDEV_NDO_GET_PHYS_PORT_ID */

/* netdev_notifier_changeupper_info is defined */
#define HAVE_NETDEV_NOTIFIER_CHANGEUPPER_INFO 1

/* struct netdev_notifier_changeupper_info has upper_info */
#define HAVE_NETDEV_NOTIFIER_CHANGEUPPER_INFO_UPPER_INFO 1

/* struct netdev_notifier_info is defined */
#define HAVE_NETDEV_NOTIFIER_INFO 1

/* netdev_notifier_info_to_dev is defined */
#define HAVE_NETDEV_NOTIFIER_INFO_TO_DEV 1

/* ndo_fix_features is defined in net_device_ops_ext */
/* #undef HAVE_NETDEV_OPS_EXT_NDO_FIX_FEATURES */

/* ndo_set_features is defined in net_device_ops_ext */
/* #undef HAVE_NETDEV_OPS_EXT_NDO_SET_FEATURES */

/* ndo_set_vf_link_state is defined */
/* #undef HAVE_NETDEV_OPS_EXT_NDO_SET_VF_LINK_STATE */

/* ndo_set_vf_spoofchk is defined in net_device_ops_ext */
/* #undef HAVE_NETDEV_OPS_EXT_NDO_SET_VF_SPOOFCHK */

/* ndo_set_vf_link_state is defined in net_device_ops */
#define HAVE_NETDEV_OPS_NDO_SET_VF_LINK_STATE 1

/* ndo_set_vf_spoofchk is defined in net_device_ops */
#define HAVE_NETDEV_OPS_NDO_SET_VF_SPOOFCHK 1

/* ndo_set_vf_trust is defined in net_device_ops */
#define HAVE_NETDEV_OPS_NDO_SET_VF_TRUST 1

/* extended ndo_set_vf_trust is defined */
/* #undef HAVE_NETDEV_OPS_NDO_SET_VF_TRUST_EXTENDED */

/* netdev_phys_item_id is defined */
#define HAVE_NETDEV_PHYS_ITEM_ID 1

/* netdev_port_same_parent_id is defined */
#define HAVE_NETDEV_PORT_SAME_PARENT_ID 1

/* rx_queue_attribute is defined in netdevice.h */
/* #undef HAVE_NETDEV_QUEUE_SYSFS */

/* netdev queue sysfs has attribute */
/* #undef HAVE_NETDEV_QUEUE_SYSFS_ATTRIBUTE */

/* netdev_reg_state is defined */
#define HAVE_NETDEV_REG_STATE 1

/* netdev_reset_tc is defined */
#define HAVE_NETDEV_RESET_TC 1

/* netdev_rss_key_fill is defined */
#define HAVE_NETDEV_RSS_KEY_FILL 1

/* rx_cpu_rmap is defined */
#define HAVE_NETDEV_RX_CPU_RMAP 1

/* netdev_rx_handler_register is defined */
#define HAVE_NETDEV_RX_HANDLER_REGISTER 1

/* netdev_set_num_tc is defined */
#define HAVE_NETDEV_SET_NUM_TC 1

/* netdev_set_tc_queue is defined */
#define HAVE_NETDEV_SET_TC_QUEUE 1

/* netdev_stats_to_stats64 is defined */
#define HAVE_NETDEV_STATS_TO_STATS64 1

/* netdev_txq_bql_complete_prefetchw is defined */
#define HAVE_NETDEV_TXQ_BQL_PREFETCHW 1

/* __netdev_tx_sent_queue is defined */
#define HAVE_NETDEV_TX_SEND_QUEUE 1

/* is defined */
#define HAVE_NETDEV_UPDATE_FEATURES 1

/* netdev_walk_all_lower_dev_rcu is defined */
/* #undef HAVE_NETDEV_WALK_ALL_LOWER_DEV_RCU */

/* netdev_walk_all_upper_dev_rcu is defined */
/* #undef HAVE_NETDEV_WALK_ALL_UPPER_DEV_RCU */

/* wanted_features is defined */
#define HAVE_NETDEV_WANTED_FEATURES 1

/* struct netdev_xdp is defined */
/* #undef HAVE_NETDEV_XDP */

/* netdev_xmit_more is defined */
#define HAVE_NETDEV_XMIT_MORE 1

/* NETIF_F_GRO_HW is defined in netdev_features.h */
#define HAVE_NETIF_F_GRO_HW 1

/* NETIF_F_GSO_GRE_CSUM is defined in netdev_features.h */
#define HAVE_NETIF_F_GSO_GRE_CSUM 1

/* NETIF_F_GSO_PARTIAL is defined in netdev_features.h */
#define HAVE_NETIF_F_GSO_PARTIAL 1

/* HAVE_NETIF_F_GSO_UDP_L4 is defined in netdev_features.h */
#define HAVE_NETIF_F_GSO_UDP_L4 1

/* NETIF_F_GSO_UDP_TUNNEL is defined in netdev_features.h */
#define HAVE_NETIF_F_GSO_UDP_TUNNEL 1

/* NETIF_F_GSO_UDP_TUNNEL_CSUM is defined in netdev_features.h */
#define HAVE_NETIF_F_GSO_UDP_TUNNEL_CSUM 1

/* NETIF_F_HW_TLS_RX is defined in netdev_features.h */
#define HAVE_NETIF_F_HW_TLS_RX 1

/* NETIF_F_HW_VLAN_STAG_RX is defined in netdev_features.h */
#define HAVE_NETIF_F_HW_VLAN_STAG_RX 1

/* NETIF_F_RXALL is defined in netdev_features.h */
#define HAVE_NETIF_F_RXALL 1

/* NETIF_F_RXFCS is defined in netdev_features.h */
#define HAVE_NETIF_F_RXFCS 1

/* NETIF_F_RXHASH is defined in netdev_features.h */
#define HAVE_NETIF_F_RXHASH 1

/* NETIF_IS_BOND_MASTER is defined in netdev_features.h */
#define HAVE_NETIF_IS_BOND_MASTER 1

/* netif_is_geneve is defined */
#define HAVE_NETIF_IS_GENEVE 1

/* netif_is_gretap is defined */
#define HAVE_NETIF_IS_GRETAP 1

/* NETIF_IS_LAG_MASTER is defined in netdevice.h */
#define HAVE_NETIF_IS_LAG_MASTER 1

/* NETIF_IS_LAG_PORT is defined in netdevice.h */
#define HAVE_NETIF_IS_LAG_PORT 1

/* netif_is_rxfh_configured is defined */
#define HAVE_NETIF_IS_RXFH_CONFIGURED 1

/* netif_is_vxlan is defined */
#define HAVE_NETIF_IS_VXLAN 1

/* netif_keep_dst is defined */
#define HAVE_NETIF_KEEP_DST 1

/* netif_napi_add get 3 params */
#define HAVE_NETIF_NAPI_ADD_GET_3_PARAMS 1

/* netif_napi_add_tx is defined */
#define HAVE_NETIF_NAPI_ADD_TX 1

/* netdevice.h has netif_napi_add_weight */
#define HAVE_NETIF_NAPI_ADD_WEIGHT 1

/* netif_set_real_num_rx_queues is defined */
#define HAVE_NETIF_SET_REAL_NUM_RX_QUEUES 1

/* netif_set_real_num_tx_queues is defined */
#define HAVE_NETIF_SET_REAL_NUM_TX_QUEUES 1

/* netif_set_real_num_tx_queues return value exists */
#define HAVE_NETIF_SET_REAL_NUM_TX_QUEUES_NOT_VOID 1

/* is defined */
#define HAVE_NETIF_SET_XPS_QUEUE 1

/* netif_trans_update is defined */
#define HAVE_NETIF_TRANS_UPDATE 1

/* netif_tx_napi_add is defined */
/* #undef HAVE_NETIF_TX_NAPI_ADD */

/* netif_tx_queue_stopped is defined */
#define HAVE_NETIF_TX_QUEUE_STOPPED 1

/* netif_xmit_stopped is defined */
#define HAVE_NETIF_XMIT_STOPPED 1

/* netlink_capable is defined */
#define HAVE_NETLINK_CAPABLE 1

/* netlink_dump_control dump is defined */
#define HAVE_NETLINK_DUMP_CONTROL_DUMP 1

/* netlink_dump_start has 5 parameters */
/* #undef HAVE_NETLINK_DUMP_START_5P */

/* struct netlink_ext_ack exists */
#define HAVE_NETLINK_EXTACK 1

/* struct netlink_ext_ack is defined */
#define HAVE_NETLINK_EXT_ACK 1

/* netlink_kernel_cfg input is defined */
#define HAVE_NETLINK_KERNEL_CFG_INPUT 1

/* netlink_kernel_create has 3 params */
#define HAVE_NETLINK_KERNEL_CREATE_3_PARAMS 1

/* netlink_ns_capable is defined */
#define HAVE_NETLINK_NS_CAPABLE 1

/* struct netlink_skb_parms has portid */
#define HAVE_NETLINK_SKB_PARMS_PORTID 1

/* netlink_skb_params has sk */
#define HAVE_NETLINK_SKB_PARMS_SK 1

/* struct netns_frags has rhashtable */
/* #undef HAVE_NETNS_FRAGS_RHASHTABLE */

/* netpoll_poll_dev is exported by the kernel */
#define HAVE_NETPOLL_POLL_DEV_EXPORTED 1

/* dev_port is defined */
#define HAVE_NET_DEVICE_DEV_PORT 1

/* is defined */
/* #undef HAVE_NET_DEVICE_EXTENDED_TX_EXT */

/* net_device close_list is defined */
#define HAVE_NET_DEVICE_HAS_CLOSE_LIST 1

/* net_device min/max is defined */
#define HAVE_NET_DEVICE_MIN_MAX_MTU 1

/* extended min/max_mtu is defined */
/* #undef HAVE_NET_DEVICE_MIN_MAX_MTU_EXTENDED */

/* net_device needs_free_netdev is defined */
#define HAVE_NET_DEVICE_NEEDS_FREE_NETDEV 1

/* neigh_priv_len is defined */
#define HAVE_NET_DEVICE_NEIGH_PRIV_LEN 1

/* net_device num_rx_queues is defined */
#define HAVE_NET_DEVICE_NUM_RX_QUEUES 1

/* struct net_device_ops_ext is defined */
/* #undef HAVE_NET_DEVICE_OPS_EXT */

/* struct net_device_ops_extended is defined */
/* #undef HAVE_NET_DEVICE_OPS_EXTENDED */

/* net_device real_num_rx_queues is defined */
#define HAVE_NET_DEVICE_REAL_NUM_RX_QUEUES 1

/* net/flow_keys.h exists */
/* #undef HAVE_NET_FLOW_KEYS_H */

/* net/geneve.h is defined */
#define HAVE_NET_GENEVE_H 1

/* net/page_pool.h is defined */
/* #undef HAVE_NET_PAGE_POOL_H */

/* net/tc_act/tc_mirred.h exists */
#define HAVE_NET_TC_ACT_TC_MIRRED_H 1

/* net/tc_act/tc_tunnel_key.h exists */
#define HAVE_NET_TC_ACT_TC_TUNNEL_KEY_H 1

/* net/tls.h exists */
#define HAVE_NET_TLS_H 1

/* include/net/vxlan.h exists */
#define HAVE_NET_VXLAN_H 1

/* NESTED: net/xdp.h is defined workaround for 5.4.17-2011.1.2.el8uek.x86_64
   */
#define HAVE_NET_XDP_H 1

/* alloc_etherdev_mqs, alloc_etherdev_mqs, num_tc is defined */
#define HAVE_NEW_TX_RING_SCHEME 1

/* nla_nest_start_noflag exist */
#define HAVE_NLA_NEST_START_NOFLAG 1

/* nla_parse takes 6 parameters */
#define HAVE_NLA_PARSE_6_PARAMS 1

/* nla_parse_deprecated exist */
#define HAVE_NLA_PARSE_DEPRECATED 1

/* nla_put_u64_64bit is defined */
#define HAVE_NLA_PUT_U64_64BIT 1

/* NLA_S32 is defined */
#define HAVE_NLA_S32 1

/* nla_strscpy exist */
#define HAVE_NLA_STRSCPY 1

/* nlmsg_parse_deprecated exist */
#define HAVE_NLMSG_PARSE_DEPRECATED 1

/* nlmsg_validate_deprecated exist */
#define HAVE_NLMSG_VALIDATE_DEPRECATED 1

/* current_link_speed/width not exposed */
/* #undef HAVE_NO_LINKSTA_SYSFS */

/* numa_mem_id is defined */
#define HAVE_NUMA_MEM_ID 1

/* nvm_alloc_dev is exported by the kernel */
/* #undef HAVE_NVM_ALLOC_DEV_EXPORTED */

/* struct nvm_user_vio is defined */
/* #undef HAVE_NVM_USER_VIO */

/* N_MEMORY is defined */
#define HAVE_N_MEMORY 1

/* include/linux/once.h exists */
#define HAVE_ONCE_H 1

/* op_is_write is defined */
#define HAVE_OP_IS_WRITE 1

/* page_is_pfmemalloc is defined */
#define HAVE_PAGE_IS_PFMEMALLOC 1

/* pfmemalloc is defined */
/* #undef HAVE_PAGE_PFMEMALLOC */

/* net/page_pool.h has page_pool_release_page */
/* #undef HAVE_PAGE_POOL_RELEASE_PAGE */

/* page_ref_count/add/sub/inc defined */
#define HAVE_PAGE_REF_COUNT_ADD_SUB_INC 1

/* param_ops_ullong is defined */
#define HAVE_PARAM_OPS_ULLONG 1

/* part_stat.h exists */
#define HAVE_PART_STAT_H 1

/* pat.h has pat_enabled as a function */
/* #undef HAVE_PAT_ENABLED_AS_FUNCTION */

/* pcie_get_minimum_link is defined */
/* #undef HAVE_PCIE_GET_MINIMUM_LINK */

/* pcie_link_width is defined */
#define HAVE_PCIE_LINK_WIDTH 1

/* pcie_print_link_status is defined */
#define HAVE_PCIE_PRINT_LINK_STATUS 1

/* pci_bus_addr_t is defined */
#define HAVE_PCI_BUS_ADDR_T 1

/* pci_bus_speed is defined */
#define HAVE_PCI_BUS_SPEED 1

/* pci_cfg_access_lock is defined */
#define HAVE_PCI_CFG_ACCESS_LOCK 1

/* PCI_CLASS_STORAGE_EXPRESS is defined */
#define HAVE_PCI_CLASS_STORAGE_EXPRESS 1

/* PCI_DEV_FLAGS_ASSIGNED is defined */
#define HAVE_PCI_DEV_FLAGS_ASSIGNED 1

/* pcie_mpss is defined */
#define HAVE_PCI_DEV_PCIE_MPSS 1

/* pci_driver sriov_configure is defined */
#define HAVE_PCI_DRIVER_SRIOV_CONFIGURE 1

/* pci_enable_atomic_ops_to_root is defined */
#define HAVE_PCI_ENABLE_ATOMIC_OPS_TO_ROOT 1

/* pci_enable_msix_range is defined */
#define HAVE_PCI_ENABLE_MSIX_RANGE 1

/* pci.h struct pci_error_handlers has reset_done */
#define HAVE_PCI_ERROR_HANDLERS_RESET_DONE 1

/* pci.h struct pci_error_handlers has reset_notify */
/* #undef HAVE_PCI_ERROR_HANDLERS_RESET_NOTIFY */

/* pci.h struct pci_error_handlers has reset_prepare */
#define HAVE_PCI_ERROR_HANDLERS_RESET_PREPARE 1

/* linux/pci.h has pci_free_irq */
#define HAVE_PCI_FREE_IRQ 1

/* linux/pci.h has pci_irq_vector, pci_free_irq_vectors, pci_alloc_irq_vectors
   */
#define HAVE_PCI_IRQ_API 1

/* pci_irq_get_affinity is defined */
#define HAVE_PCI_IRQ_GET_AFFINITY 1

/* pci_irq_get_node is defined */
/* #undef HAVE_PCI_IRQ_GET_NODE */

/* pci_num_vf is defined */
#define HAVE_PCI_NUM_VF 1

/* linux/pci-p2pdma.h exists */
#define HAVE_PCI_P2PDMA_H 1

/* pci_physfn is defined */
#define HAVE_PCI_PHYSFN 1

/* pci_pool_zalloc is defined */
/* #undef HAVE_PCI_POOL_ZALLOC */

/* pci_release_mem_regions is defined */
#define HAVE_PCI_RELEASE_MEM_REGIONS 1

/* pci_request_mem_regions is defined */
#define HAVE_PCI_REQUEST_MEM_REGIONS 1

/* pci_sriov_get_totalvfs is defined */
#define HAVE_PCI_SRIOV_GET_TOTALVFS 1

/* pci_upstream_bridge is defined */
#define HAVE_PCI_UPSTREAM_BRIDGE 1

/* pci_vfs_assigned is defined */
#define HAVE_PCI_VFS_ASSIGNED 1

/* PDE_DATA is defined */
/* #undef HAVE_PDE_DATA */

/* pernet_operations_id is defined */
#define HAVE_PERENT_OPERATIONS_ID 1

/* pinned_vm is defined */
/* #undef HAVE_PINNED_VM */

/* PM_QOS_LATENCY_TOLERANCE_NO_CONSTRAINT is defined */
#define HAVE_PM_QOS_LATENCY_TOLERANCE_NO_CONSTRAINT 1

/* dev_pm_qos_update_user_latency_tolerance is exported by the kernel */
#define HAVE_PM_QOS_UPDATE_USER_LATENCY_TOLERANCE_EXPORTED 1

/* pnv-pci.h has pnv_pci_enable_tunnel */
/* #undef HAVE_PNV_PCI_AS_NOTIFY */

/* pnv-pci.h has pnv_pci_set_p2p */
/* #undef HAVE_PNV_PCI_SET_P2P */

/* possible_net_t is defined */
#define HAVE_POSSIBLE_NET_T 1

/* prandom_u32 is defined */
/* #undef HAVE_PRANDOM_U32 */

/* print_hex_dump_debug is defined */
#define HAVE_PRINT_HEX_DUMP_DEBUG 1

/* pr_debug_ratelimited is defined */
#define HAVE_PR_DEBUG_RATELIMITED 1

/* linux/pr.h exists */
#define HAVE_PR_H 1

/* ptp_clock_info is defined */
#define HAVE_PTP_CLOCK_INFO 1

/* gettime 32bit is defined */
/* #undef HAVE_PTP_CLOCK_INFO_GETTIME_32BIT */

/* n_pins is defined */
#define HAVE_PTP_CLOCK_INFO_N_PINS 1

/* ptp_clock_register has 2 params is defined */
#define HAVE_PTP_CLOCK_REGISTER_2_PARAMS 1

/* ptp_find_pin_unlocked is defined */
#define HAVE_PTP_FIND_PIN_UNLOCK 1

/* __put_task_struct is exported by the kernel */
#define HAVE_PUT_TASK_STRUCT_EXPORTED 1

/* put_unaligned_le24 existing */
/* #undef HAVE_PUT_UNALIGNED_LE24 */

/* struct Qdisc_ops has ingress_block_set */
#define HAVE_QDISC_SUPPORTS_BLOCK_SHARING 1

/* QUEUE_FLAG_PCI_P2PDMA is defined */
/* #undef HAVE_QUEUE_FLAG_PCI_P2PDMA */

/* QUEUE_FLAG_WC_FUA is defined */
/* #undef HAVE_QUEUE_FLAG_WC_FUA */

/* radix_tree_is_internal_node is defined */
#define HAVE_RADIX_TREE_IS_INTERNAL 1

/* radix_tree_iter_delete is defined */
#define HAVE_RADIX_TREE_ITER_DELETE 1

/* radix_tree_iter_delete is exported by the kernel */
#define HAVE_RADIX_TREE_ITER_DELETE_EXPORTED 1

/* radix_tree_iter_lookup is defined */
#define HAVE_RADIX_TREE_ITER_LOOKUP 1

/* radix_tree_next_chunk is defined */
#define HAVE_RADIX_TREE_NEXT_CHUNK 1

/* struct radix_tree_node is defined */
#define HAVE_RADIX_TREE_NODE 1

/* rb_first_postorder is defined */
#define HAVE_RB_FIRST_POSTORDER 1

/* struct rb_root_cached is defined */
#define HAVE_RB_ROOT_CACHED 1

/* reciprocal_scale is defined */
#define HAVE_RECIPROCAL_SCALE 1

/* refcount.h exists */
#define HAVE_REFCOUNT 1

/* register_fib_notifier has 4 params */
#define HAVE_REGISTER_FIB_NOTIFIER_HAS_4_PARAMS 1

/* linux/security.h has register_lsm_notifier */
/* #undef HAVE_REGISTER_LSM_NOTIFIER */

/* register_netdevice_notifier_rh is defined */
/* #undef HAVE_REGISTER_NETDEVICE_NOTIFIER_RH */

/* register_net_sysctl is defined */
/* #undef HAVE_REGISTER_NET_SYSCTL */

/* release_pages is defined */
#define HAVE_RELEASE_PAGES 1

/* request_firmware_direct is defined */
#define HAVE_REQUEST_FIRMWARE_DIRECT 1

/* blkdev.h struct request has mq_hctx */
/* #undef HAVE_REQUEST_MQ_HCTX */

/* struct request_queue has integrity */
/* #undef HAVE_REQUEST_QUEUE_INTEGRITY */

/* struct request_queue has q_usage_counter */
#define HAVE_REQUEST_QUEUE_Q_USAGE_COUNTER 1

/* blkdev.h struct request_queue has timeout_work */
#define HAVE_REQUEST_QUEUE_TIMEOUT_WORK 1

/* blkdev.h struct request has rq_flags */
/* #undef HAVE_REQUEST_RQ_FLAGS */

/* linux/blk-mq.h has request_to_qc_t */
/* #undef HAVE_REQUEST_TO_QC_T */

/* blk_types.h has REQ_IDLE */
#define HAVE_REQ_IDLE 1

/* req_op exist */
/* #undef HAVE_REQ_OP */

/* genhd.h has revalidate_disk */
/* #undef HAVE_REVALIDATE_DISK */

/* struct bio_aux is defined */
/* #undef HAVE_RH7_STRUCT_BIO_AUX */

/* struct rhashtable_params has insecure_elasticity */
/* #undef HAVE_RHASHTABLE_INSECURE_ELASTICITY */

/* struct rhashtable_params has insecure_max_entries */
/* #undef HAVE_RHASHTABLE_INSECURE_MAX_ENTRIES */

/* struct rhashtable has max_elems */
/* #undef HAVE_RHASHTABLE_MAX_ELEMS */

/* file rhashtable-types exists */
#define HAVE_RHASHTABLE_TYPES 1

/* struct rhltable is defined */
/* #undef HAVE_RHLTABLE */

/* rpc reply expected */
#define HAVE_RPC_REPLY_EXPECTED 1

/* struct rpc_xprt_ops has 'bc_num_slots' field */
#define HAVE_RPC_XPRT_OPS_BC_NUM_SLOTS 1

/* struct rpc_xprt_ops has 'bc_up' field */
/* #undef HAVE_RPC_XPRT_OPS_BC_UP */

/* struct rpc_xprt_ops *ops' field is const inside 'struct rpc_xprt' */
#define HAVE_RPC_XPRT_OPS_CONST 1

/* struct rpc_xprt_ops has 'free_slot' field */
#define HAVE_RPC_XPRT_OPS_FREE_SLOT 1

/* struct rpc_xprt_ops has 'set_retrans_timeout' field */
/* #undef HAVE_RPC_XPRT_OPS_SET_RETRANS_TIMEOUT */

/* struct rpc_xprt_ops has 'wait_for_reply_request' field */
#define HAVE_RPC_XPRT_OPS_WAIT_FOR_REPLY_REQUEST 1

/* struct rpc_xprt has 'recv_lock' field */
/* #undef HAVE_RPC_XPRT_RECV_LOCK */

/* rt6_lookup takes 6 params */
#define HAVE_RT6_LOOKUP_TAKES_6_PARAMS 1

/* linux/rtnetlink.h has net_rwsem */
#define HAVE_RTNETLINK_NET_RWSEM 1

/* newlink has 4 paramters */
/* #undef HAVE_RTNL_LINK_OPS_NEWLINK_4_PARAMS */

/* newlink has 5 paramters */
/* #undef HAVE_RTNL_LINK_OPS_NEWLINK_5_PARAMS */

/* rtnl_link_stats64 is defined */
#define HAVE_RTNL_LINK_STATS64 1

/* rtble has direct dst */
#define HAVE_RT_DIRECT_DST 1

/* rt_gw_family is defined */
#define HAVE_RT_GW_FAMILY 1

/* rt_uses_gateway is defined */
#define HAVE_RT_USES_GATEWAY 1

/* get_rxfh_indir_size is defined */
#define HAVE_RXFH_INDIR_SIZE 1

/* get_rxfh_indir_size is defined in ethtool_ops_ext */
/* #undef HAVE_RXFH_INDIR_SIZE_EXT */

/* linux/sched.h exists */
#define HAVE_SCHED_H 1

/* linux/sched/mm.h exists */
#define HAVE_SCHED_MM_H 1

/* linux/sched/signal.h exists */
#define HAVE_SCHED_SIGNAL_H 1

/* linux/sched/task.h exists */
#define HAVE_SCHED_TASK_H 1

/* scsi_change_queue_depth exist */
#define HAVE_SCSI_CHANGE_QUEUE_DEPTH 1

/* scsi_cmnd has members prot_flags */
#define HAVE_SCSI_CMND_PROT_FLAGS 1

/* scsi_device.h has function scsi_internal_device_block */
/* #undef HAVE_SCSI_DEVICE_SCSI_INTERNAL_DEVICE_BLOCK */

/* scsi_device.h struct scsi_device has member state_mutex */
#define HAVE_SCSI_DEVICE_STATE_MUTEX 1

/* Scsi_Host has members max_segment_size */
#define HAVE_SCSI_HOST_MAX_SEGMENT_SIZE 1

/* Scsi_Host has members nr_hw_queues */
#define HAVE_SCSI_HOST_NR_HW_QUEUES 1

/* scsi_host_template has members change_queue_type */
/* #undef HAVE_SCSI_HOST_TEMPLATE_CHANGE_QUEUE_TYPE */

/* scsi_host_template has members lockless */
/* #undef HAVE_SCSI_HOST_TEMPLATE_LOCKLESS */

/* scsi_host_template has members track_queue_depth */
#define HAVE_SCSI_HOST_TEMPLATE_TRACK_QUEUE_DEPTH 1

/* scsi_host_template has members use_blk_tags */
/* #undef HAVE_SCSI_HOST_TEMPLATE_USE_BLK_TAGS */

/* scsi_host_template has members use_host_wide_tags */
/* #undef HAVE_SCSI_HOST_TEMPLATE_USE_HOST_WIDE_TAGS */

/* Scsi_Host has members virt_boundary_mask */
#define HAVE_SCSI_HOST_VIRT_BOUNDARY_MASK 1

/* SCSI_MAX_SG_SEGMENTS is defined */
/* #undef HAVE_SCSI_MAX_SG_SEGMENTS */

/* SCSI_SCAN_INITIAL is defined */
#define HAVE_SCSI_SCAN_INITIAL 1

/* scsi_transfer_length is defined */
#define HAVE_SCSI_TRANSFER_LENGTH 1

/* scsi/scsi_transport_fc.h has FC_PORT_ROLE_NVME_TARGET */
#define HAVE_SCSI_TRANSPORT_FC_FC_PORT_ROLE_NVME_TARGET 1

/* if secpath_set returns struct sec_path * */
#define HAVE_SECPATH_SET_RETURN_POINTER 1

/* select_queue_fallback_t is defined */
#define HAVE_SELECT_QUEUE_FALLBACK_T 1

/* select_queue_fallback_t has third parameter */
#define HAVE_SELECT_QUEUE_FALLBACK_T_3_PARAMS 1

/* ndo_select_queue has a second net_device parameter */
/* #undef HAVE_SELECT_QUEUE_NET_DEVICE */

/* set_dma_ops is defined */
/* #undef HAVE_SET_DMA_OPS */

/* is defined */
/* #undef HAVE_SET_NETDEV_HW_FEATURES */

/* set_phys_id is defined */
#define HAVE_SET_PHYS_ID 1

/* set_phys_id is defined in ethtool_ops_ext */
/* #undef HAVE_SET_PHYS_ID_EXT */

/* struct se_cmd has member prot_checks */
#define HAVE_SE_CMD_HAS_PROT_CHECKS 1

/* struct se_cmd has member sense_info */
#define HAVE_SE_CMD_HAS_SENSE_INFO 1

/* target_core_base.h se_cmd transport_complete_callback has three params */
#define HAVE_SE_CMD_TRANSPORT_COMPLETE_CALLBACK_HAS_THREE_PARAM 1

/* sgl_alloc is defined */
#define HAVE_SGL_ALLOC 1

/* sgl_free is defined */
#define HAVE_SGL_FREE 1

/* sg_alloc_table_chained has 3 parameters */
/* #undef HAVE_SG_ALLOC_TABLE_CHAINED_3_PARAMS */

/* sg_alloc_table_chained has 4 parameters */
/* #undef HAVE_SG_ALLOC_TABLE_CHAINED_4_PARAMS */

/* sg_alloc_table_chained has 4 params */
/* #undef HAVE_SG_ALLOC_TABLE_CHAINED_GFP_MASK */

/* sg_alloc_table_chained has nents_first_chunk parameter */
#define HAVE_SG_ALLOC_TABLE_CHAINED_NENTS_FIRST_CHUNK_PARAM 1

/* SG_MAX_SEGMENTS is defined */
/* #undef HAVE_SG_MAX_SEGMENTS */

/* sg_page_iter is defined */
#define HAVE_SG_PAGE_ITER 1

/* sg_zero_buffer is defined */
#define HAVE_SG_ZERO_BUFFER 1

/* SIOCGHWTSTAMP is defined */
#define HAVE_SIOCGHWTSTAMP 1

/* include/linux/sizes.h exists */
#define HAVE_SIZES_H 1

/* skb_add_rx_frag has 5 params */
/* #undef HAVE_SKB_ADD_RX_FRAG_5_PARAMS */

/* skb_clear_hash is defined */
#define HAVE_SKB_CLEAR_HASH 1

/* skb_dst_update_pmtu is defined */
#define HAVE_SKB_DST_UPDATE_PMTU 1

/* skb_flow_dissect is defined */
#define HAVE_SKB_FLOW_DISSECT 1

/* skb_flow_dissect_flow_keys has 3 parameters */
#define HAVE_SKB_FLOW_DISSECT_FLOW_KEYS_HAS_3_PARAMS 1

/* skb_frag_off is defined */
#define HAVE_SKB_FRAG_OFF 1

/* linux/skbuff.h skb_frag_off_add is defined */
#define HAVE_SKB_FRAG_OFF_ADD 1

/* skb_inner_network_header is defined */
#define HAVE_SKB_INNER_NETWORK_HEADER 1

/* skb_inner_transport_header is defined */
#define HAVE_SKB_INNER_TRANSPORT_HEADER 1

/* skb_inner_transport_offset is defined */
#define HAVE_SKB_INNER_TRANSPORT_OFFSET 1

/* sk_buff has member l4_rxhash */
/* #undef HAVE_SKB_L4_RXHASH */

/* skb_pull_inline is defined */
#define HAVE_SKB_PULL_INLINE 1

/* skb_put_zero is defined */
#define HAVE_SKB_PUT_ZERO 1

/* sk_buff has member rxhash */
/* #undef HAVE_SKB_RXHASH */

/* skb_set_hash is defined */
#define HAVE_SKB_SET_HASH 1

/* skb_shared_info has union tx_flags */
/* #undef HAVE_SKB_SHARED_INFO_UNION_TX_FLAGS */

/* sk_buff has member sw_hash */
#define HAVE_SKB_SWHASH 1

/* skb_transport_header_was_set is defined */
#define HAVE_SKB_TRANSPORT_HEADER_WAS_SET 1

/* skb_vlan_pop is defined */
#define HAVE_SKB_VLAN_POP 1

/* skwq_has_sleeper is defined */
#define HAVE_SKWQ_HAS_SLEEPER 1

/* csum_level is defined */
#define HAVE_SK_BUFF_CSUM_LEVEL 1

/* decrypted is defined */
#define HAVE_SK_BUFF_DECRYPTED 1

/* encapsulation is defined */
#define HAVE_SK_BUFF_ENCAPSULATION 1

/* struct sock sk is defined */
#define HAVE_SK_BUFF_STRUCT_SOCK_SK 1

/* xmit_more is defined */
/* #undef HAVE_SK_BUFF_XMIT_MORE */

/* sk_clone_lock is defined */
#define HAVE_SK_CLONE_LOCK 1

/* sk_data_ready has 2 params */
/* #undef HAVE_SK_DATA_READY_2_PARAMS */

/* sk_wait_data has 3 params */
#define HAVE_SK_WAIT_DATA_3_PARAMS 1

/* smp_load_acquire is defined */
#define HAVE_SMP_LOAD_ACQUIRE 1

/* sock_create_kern has 5 params is defined */
#define HAVE_SOCK_CREATE_KERN_5_PARAMS 1

/* split_page is exported by the kernel */
#define HAVE_SPLIT_PAGE_EXPORTED 1

/* build_bug.h has static_assert */
#define HAVE_STATIC_ASSERT 1

/* Define to 1 if you have the <stdint.h> header file. */
#define HAVE_STDINT_H 1

/* Define to 1 if you have the <stdlib.h> header file. */
#define HAVE_STDLIB_H 1

/* fs.h has stream_open */
#define HAVE_STREAM_OPEN 1

/* Define to 1 if you have the <strings.h> header file. */
#define HAVE_STRINGS_H 1

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H 1

/* strnicmp is defined */
/* #undef HAVE_STRNICMP */

/* strscpy is defined */
#define HAVE_STRSCPY 1

/* strscpy_pad is defined */
#define HAVE_STRSCPY_PAD 1

/* struct bio has member bi_error */
/* #undef HAVE_STRUCT_BIO_BI_ERROR */

/* struct bio has member bi_iter */
#define HAVE_STRUCT_BIO_BI_ITER 1

/* struct bio has member bi_opf */
#define HAVE_STRUCT_BIO_BI_OPF 1

/* struct class has member ns_type */
#define HAVE_STRUCT_CLASS_NS_TYPE 1

/* struct dma_attrs is defined */
/* #undef HAVE_STRUCT_DMA_ATTRS */

/* ieee_pfc is defined */
#define HAVE_STRUCT_IEEE_PFC 1

/* ieee_qcn is defined */
#define HAVE_STRUCT_IEEE_QCN 1

/* struct ifla_vf_stats has memebers rx_dropped and tx_dropped */
#define HAVE_STRUCT_IFLA_VF_STATS_RX_TX_DROPPED 1

/* struct ifla_vf_stats has member tx_broadcast */
/* #undef HAVE_STRUCT_IFLA_VF_STATS_TX_BROADCAST */

/* linux/bio.h submit_bio has 1 parameter */
#define HAVE_SUBMIT_BIO_1_PARAM 1

/* submit_bio_noacct exist */
#define HAVE_SUBMIT_BIO_NOACCT 1

/* supported_coalesce_params is defined */
#define HAVE_SUPPORTED_COALESCE_PARAM 1

/* struct svcxprt_rdma has 'sc_pending_recvs' field */
#define HAVE_SVCXPRT_RDMA_SC_PENDING_RECVS 1

/* NESTED: svc_fill_write_vector use 3 params */
/* #undef HAVE_SVC_FILL_WRITE_VECTOR */

/* struct svc_rdma_pcl exists */
#define HAVE_SVC_RDMA_PCL 1

/* struct svc_rdma_recv_ctxt has 'rc_stream' field */
#define HAVE_SVC_RDMA_RECV_CTXT_RC_STREAM 1

/* svc_rdma_release_rqst has externed */
/* #undef HAVE_SVC_RDMA_RELEASE_RQST */

/* 'struct svc_xprt_ops *xcl_ops' field is const inside 'struct
   svc_xprt_class' */
#define HAVE_SVC_XPRT_CLASS_XCL_OPS_CONST 1

/* svc_xprt_deferred_close is exported by the sunrpc core */
#define HAVE_SVC_XPRT_DEFERRED_CLOSE 1

/* svc_xprt_is_dead has defined */
#define HAVE_SVC_XPRT_IS_DEAD 1

/* svc_xprt_received is exported by the sunrpc core */
#define HAVE_SVC_XPRT_RECEIVED 1

/* struct svc_xprt_ops 'xpo_prep_reply_hdr' field */
/* #undef HAVE_SVC_XPRT_XPO_PREP_REPLY_HDR */

/* struct svc_xprt has 'xpt_remotebuf' field */
#define HAVE_SVC_XPRT_XPT_REMOTEBUF 1

/* include/net/switchdev.h exists */
#define HAVE_SWITCHDEV_H 1

/* HAVE_SWITCHDEV_OPS is defined */
/* #undef HAVE_SWITCHDEV_OPS */

/* switchdev_port_same_parent_id is defined */
/* #undef HAVE_SWITCHDEV_PORT_SAME_PARENT_ID */

/* linux/sysctl.h has SYSCTL_ZERO defined */
#define HAVE_SYSCTL_ZERO_ENABLED 1

/* Define to 1 if you have the <sys/stat.h> header file. */
#define HAVE_SYS_STAT_H 1

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H 1

/* enum t10_dif_type is defined */
#define HAVE_T10_DIF_TYPE 1

/* linux/t10-pi.h exists */
#define HAVE_T10_PI_H 1

/* t10_pi_prepare is defined */
/* #undef HAVE_T10_PI_PREPARE */

/* t10_pi_ref_tag() exists */
#define HAVE_T10_PI_REF_TAG 1

/* target_core_fabric.h has target_reverse_dma_direction function */
#define HAVE_TARGET_FABRIC_HAS_TARGET_REVERSE_DMA_DIRECTION 1

/* target_put_sess_cmd in target_core_fabric.h has 1 parameter */
#define HAVE_TARGET_PUT_SESS_CMD_HAS_1_PARAM 1

/* target_stop_session is defined */
#define HAVE_TARGET_STOP_SESSION 1

/* target_core_base.h se_cmd supports compare_and_write */
#define HAVE_TARGET_SUPPORT_COMPARE_AND_WRITE 1

/* TCA_CSUM_UPDATE_FLAG_IPV4HDR is defined */
#define HAVE_TCA_CSUM_UPDATE_FLAG_IPV4HDR 1

/* TCA_FLOWER_KEY_CVLAN_ID is defined */
#define HAVE_TCA_FLOWER_KEY_CVLAN_ID 1

/* TCA_FLOWER_KEY_FLAGS_FRAG_IS_FIRST is defined */
#define HAVE_TCA_FLOWER_KEY_FLAGS_FRAG_IS_FIRST 1

/* TCA_FLOWER_KEY_FLAGS_IS_FRAGMENT is defined */
#define HAVE_TCA_FLOWER_KEY_FLAGS_IS_FRAGMENT 1

/* TCA_FLOWER_KEY_MPLS_TTL is defined */
#define HAVE_TCA_FLOWER_KEY_MPLS_TTL 1

/* TCA_FLOWER_KEY_SCTP_SRC_MASK is defined */
#define HAVE_TCA_FLOWER_KEY_SCTP_SRC_MASK 1

/* TCA_TUNNEL_KEY_ENC_DST_PORT is defined */
#define HAVE_TCA_TUNNEL_KEY_ENC_DST_PORT 1

/* TCA_TUNNEL_KEY_ENC_TOS is defined */
#define HAVE_TCA_TUNNEL_KEY_ENC_TOS 1

/* TCA_VLAN_ACT_MODIFY exists */
#define HAVE_TCA_VLAN_ACT_MODIFY 1

/* tc_action_stats_update is defined */
/* #undef HAVE_TCF_ACTION_STATS_UPDATE */

/* struct tcf_common is defined */
/* #undef HAVE_TCF_COMMON */

/* tcf_exts_get_dev is defined */
/* #undef HAVE_TCF_EXTS_GET_DEV */

/* struct tcf_exts has actions as array */
#define HAVE_TCF_EXTS_HAS_ARRAY_ACTIONS 1

/* tcf_exts_init is defined */
/* #undef HAVE_TCF_EXTS_INIT */

/* tcf_exts_num_actions is exported by the kernel */
#define HAVE_TCF_EXTS_NUM_ACTIONS 1

/* tcf_exts_stats_update is defined */
/* #undef HAVE_TCF_EXTS_STATS_UPDATE */

/* tcf_exts_to_list is defined */
/* #undef HAVE_TCF_EXTS_TO_LIST */

/* tcf_hash helper functions have tcf_hashinfo parameter */
/* #undef HAVE_TCF_HASH_WITH_HASHINFO */

/* tcf_mirred_dev is defined */
#define HAVE_TCF_MIRRED_DEV 1

/* tcf_mirred_ifindex is defined */
/* #undef HAVE_TCF_MIRRED_IFINDEX */

/* tcf_pedit_nkeys is defined */
#define HAVE_TCF_PEDIT_NKEYS 1

/* struct tcf_pedit has member tcfp_keys_ex */
/* #undef HAVE_TCF_PEDIT_TCFP_KEYS_EX */

/* tcf_police_burst is defined */
#define HAVE_TCF_POLICE_BURST 1

/* tcf_queue_work is defined */
/* #undef HAVE_TCF_QUEUE_WORK */

/* tcf_tunnel_info is defined */
#define HAVE_TCF_TUNNEL_INFO 1

/* tcf_vlan_push_prio is defined */
#define HAVE_TCF_VLAN_PUSH_PRIO 1

/* struct tc_action_ops has id */
#define HAVE_TC_ACTION_OPS_HAS_ID 1

/* struct tc_block_offload is defined */
/* #undef HAVE_TC_BLOCK_OFFLOAD */

/* struct tc_block_offload has extack */
/* #undef HAVE_TC_BLOCK_OFFLOAD_EXTACK */

/* HAVE_TC_CLSFLOWER_STATS is defined */
/* #undef HAVE_TC_CLSFLOWER_STATS */

/* tc_cls_can_offload_and_chain0 is defined */
#define HAVE_TC_CLS_CAN_OFFLOAD_AND_CHAIN0 1

/* struct tc_cls_flower_offload has common */
/* #undef HAVE_TC_CLS_FLOWER_OFFLOAD_COMMON */

/* struct tc_cls_flower_offload has egress_dev */
/* #undef HAVE_TC_CLS_FLOWER_OFFLOAD_EGRESS_DEV */

/* HAVE_TC_CLS_FLOWER_OFFLOAD_HAS_STATS_FIELD is defined */
/* #undef HAVE_TC_CLS_FLOWER_OFFLOAD_HAS_STATS_FIELD */

/* struct tc_cls_common_offload has extack */
/* #undef HAVE_TC_CLS_OFFLOAD_EXTACK */

/* struct tc_cls_common_offload has handle */
/* #undef HAVE_TC_CLS_OFFLOAD_HANDLE */

/* tc_ct_offload has member nat */
/* #undef HAVE_TC_CT_OFFLOAD_NAT */

/* struct tc_cls_flower_offload is defined */
/* #undef HAVE_TC_FLOWER_OFFLOAD */

/* tc_gact.h exists */
#define HAVE_TC_GACT_H 1

/* tc_setup_cb_egdev_register is defined */
/* #undef HAVE_TC_SETUP_CB_EGDEV_REGISTER */

/* tc_setup_flow_action is defined */
/* #undef HAVE_TC_SETUP_FLOW_ACTION */

/* tc_setup_flow_action is defined */
/* #undef HAVE_TC_SETUP_FLOW_ACTION_FUNC */

/* tc_setup_flow_action has rtnl_held */
/* #undef HAVE_TC_SETUP_FLOW_ACTION_WITH_RTNL_HELD */

/* tc_setup_offload_action is defined */
/* #undef HAVE_TC_SETUP_OFFLOAD_ACTION_FUNC */

/* tc_setup_offload_action is defined and get 3 param */
#define HAVE_TC_SETUP_OFFLOAD_ACTION_FUNC_HAS_3_PARAM 1

/* TC_SETUP_QDISC_MQPRIO is defined */
#define HAVE_TC_SETUP_QDISC_MQPRIO 1

/* TC_SETUP_TYPE is defined */
#define HAVE_TC_SETUP_TYPE 1

/* struct tc_to_netdev has egress_dev */
/* #undef HAVE_TC_TO_NETDEV_EGRESS_DEV */

/* struct tc_to_netdev has tc */
/* #undef HAVE_TC_TO_NETDEV_TC */

/* timecounter_adjtime is defined */
#define HAVE_TIMECOUNTER_ADJTIME 1

/* linux/timecounter.h exists */
#define HAVE_TIMECOUNTER_H 1

/* timer_setup is defined */
#define HAVE_TIMER_SETUP 1

/* struct tlsdev_ops has tls_dev_resync_rx */
/* #undef HAVE_TLSDEV_OPS_HAS_TLS_DEV_RESYNC_RX */

/* net/tls.h has tls_offload_context_rx */
#define HAVE_TLS_OFFLOAD_CONTEXT_RX_STRUCT 1

/* net/tls.h has tls_offload_context_tx */
#define HAVE_TLS_OFFLOAD_CONTEXT_TX_STRUCT 1

/* net/tls.h has tls_offload_rx_resync_request */
#define HAVE_TLS_OFFLOAD_RX_RESYNC_REQUEST 1

/* include/trace/trace_events.h exists */
#define HAVE_TRACE_EVENTS_H 1

/* rpcrdma.h exists */
/* #undef HAVE_TRACE_RPCRDMA_H */

/* trace_seq_buffer_ptr is defined */
#define HAVE_TRACE_SEQ_BUFFER_PTR 1

/* trace_xdp_exception is defined */
#define HAVE_TRACE_XDP_EXCEPTION 1

/* type cycle_t is defined in linux/types.h */
/* #undef HAVE_TYPE_CYCLE_T */

/* type __poll_t is defined */
#define HAVE_TYPE___POLL_T 1

/* uapi/linux/if_bonding.h exists */
#define HAVE_UAPI_IF_BONDING_H 1

/* uapi/linux/eventpoll.h exists */
#define HAVE_UAPI_LINUX_EVENTPOLL_H 1

/* uapi/linux/if_ether.h exist */
#define HAVE_UAPI_LINUX_IF_ETHER_H 1

/* uapi/linux/netlink.h exists */
#define HAVE_UAPI_LINUX_NETLINK_H 1

/* uapi/linux/nvme_ioctl.h exists */
#define HAVE_UAPI_LINUX_NVME_IOCTL_H 1

/* uapi/linux/nvme_ioctl.h has NVME_IOCTL_RESCAN */
#define HAVE_UAPI_LINUX_NVME_IOCTL_RESCAN 1

/* uapi/linux/tls.h exists */
#define HAVE_UAPI_LINUX_TLS_H 1

/* udp4_hwcsum is exported by the kernel */
#define HAVE_UDP4_HWCSUM 1

/* ib_umem_notifier_invalidate_range_start has parameter blockable */
/* #undef HAVE_UMEM_NOTIFIER_PARAM_BLOCKABLE */

/* Define to 1 if you have the <unistd.h> header file. */
#define HAVE_UNISTD_H 1

/* struct flow_block_offload has unlocked_driver_cb */
#define HAVE_UNLOCKED_DRIVER_CB 1

/* unpin_user_pages_dirty_lock is exported by the kernel */
#define HAVE_UNPIN_USER_PAGES_DIRTY_LOCK_EXPORTED 1

/* update_pmtu has 4 paramters */
/* #undef HAVE_UPDATE_PMTU_4_PARAMS */

/* include/generated/utsrelease.h exists */
#define HAVE_UTSRELEASE_H 1

/* uuid_be_to_bin is defined */
/* #undef HAVE_UUID_BE_TO_BIN */

/* uuid_equal is defined */
#define HAVE_UUID_EQUAL 1

/* uuid_gen is defined */
#define HAVE_UUID_GEN 1

/* uuid_is_null is defined */
#define HAVE_UUID_IS_NULL 1

/* va_format is defined */
#define HAVE_VA_FORMAT 1

/* vfs_getattr has 4 params */
#define HAVE_VFS_GETATTR_HAS_4_PARAMS 1

/* spoofchk is defined */
#define HAVE_VF_INFO_SPOOFCHK 1

/* trust is defined */
#define HAVE_VF_INFO_TRUST 1

/* tx_rate is defined */
/* #undef HAVE_VF_TX_RATE */

/* min_tx_rate is defined */
#define HAVE_VF_TX_RATE_LIMITS 1

/* vlan_proto is defined */
#define HAVE_VF_VLAN_PROTO 1

/* vlan_dev_get_egress_qos_mask is defined */
#define HAVE_VLAN_DEV_GET_EGRESS_QOS_MASK 1

/* vlan_features_check is defined */
#define HAVE_VLAN_FEATURES_CHECK 1

/* vlan_get_encap_level is defined */
/* #undef HAVE_VLAN_GET_ENCAP_LEVEL */

/* __vlan_get_protocol defined */
#define HAVE_VLAN_GET_PROTOCOL 1

/* vlan_gro_frags is defined in if_vlan.h */
/* #undef HAVE_VLAN_GRO_FRAGS */

/* vlan_gro_receive is defined in if_vlan.h */
/* #undef HAVE_VLAN_GRO_RECEIVE */

/* vlan_hwaccel_do_receive have *skb in if_vlan.h */
/* #undef HAVE_VLAN_HWACCEL_DO_RECEIVE_SKB_PTR */

/* vlan_hwaccel_rx is defined in if_vlan.h */
/* #undef HAVE_VLAN_HWACCEL_RX */

/* vm_fault_t is defined */
#define HAVE_VM_FAULT_T 1

/* vm_operations_struct has .fault */
/* #undef HAVE_VM_OPERATIONS_STRUCT_HAS_FAULT */

/* vxlan_features_check is defined */
#define HAVE_VXLAN_FEATURES_CHECK 1

/* vxlan_gso_check is defined */
/* #undef HAVE_VXLAN_GSO_CHECK */

/* vxlan_vni_field is defined */
#define HAVE_VXLAN_VNI_FIELD 1

/* WQ_HIGHPRI is defined */
#define HAVE_WQ_HIGHPRI 1

/* WQ_MEM_RECLAIM is defined */
#define HAVE_WQ_MEM_RECLAIM 1

/* WQ_NON_REENTRANT is defined */
/* #undef HAVE_WQ_NON_REENTRANT */

/* WQ_SYSFS is defined */
#define HAVE_WQ_SYSFS 1

/* WQ_UNBOUND is defined */
#define HAVE_WQ_UNBOUND 1

/* WQ_UNBOUND_MAX_ACTIVE is defined */
#define HAVE_WQ_UNBOUND_MAX_ACTIVE 1

/* xa_array is defined */
#define HAVE_XARRAY 1

/* struct xfrmdev_ops has member xdo_dev_state_advance_esn */
#define HAVE_XDO_DEV_STATE_ADVANCE_ESN 1

/* xdp is defined */
/* #undef HAVE_XDP_BUFF */

/* xdp_buff data_hard_start is defined */
/* #undef HAVE_XDP_BUFF_DATA_HARD_START */

/* net/xdp.h has xdp_convert_buff_to_frame */
#define HAVE_XDP_CONVERT_BUFF_TO_FRAME 1

/* NESTED: net/xdp.h has convert_to_xdp_frame workaround for
   5.4.17-2011.1.2.el8uek.x86_64 */
/* #undef HAVE_XDP_CONVERT_TO_XDP_FRAME */

/* NESTED: struct xdp_frame is defined in 5.4.17-2011.1.2.el8uek.x86_64 */
#define HAVE_XDP_FRAME 1

/* XDP_REDIRECT is defined */
#define HAVE_XDP_REDIRECT 1

/* xdp_rxq_info_reg get 4 params */
#define HAVE_XDP_RXQ_INFO_REG_GET_4_PARAMS 1

/* NESTED: net/xdp.h has xdp_rxq_info_reg_mem_model workaround for
   5.4.17-2011.1.2.el8uek.x86_64 */
#define HAVE_XDP_RXQ_INFO_REG_MEM_MODEL 1

/* xdp_set_data_meta_invalid is defined */
/* #undef HAVE_XDP_SET_DATA_META_INVALID */

/* XDRBUF_SPARSE_PAGES has defined in linux/sunrpc/xdr.h */
#define HAVE_XDRBUF_SPARSE_PAGES 1

/* xdr_buf_subsegment get const */
#define HAVE_XDR_BUF_SUBSEGMENT_CONST 1

/* xdr_decode_rdma_segment has defined */
#define HAVE_XDR_DECODE_RDMA_SEGMENT 1

/* xdr_encode_rdma_segment has defined */
#define HAVE_XDR_ENCODE_RDMA_SEGMENT 1

/* xdr_init_decode has rqst as a parameter */
#define HAVE_XDR_INIT_DECODE_RQST_ARG 1

/* xdr_init_encode has rqst as a parameter */
#define HAVE_XDR_INIT_ENCODE_RQST_ARG 1

/* xdr_item_is_absent has defined */
#define HAVE_XDR_ITEM_IS_ABSENT 1

/* xdr_stream_encode_item_absent has defined */
#define HAVE_XDR_STREAM_ENCODE_ITEM_ABSENT 1

/* xdr_stream_remaining function definition */
#define HAVE_XDR_STREAM_REMAINING 1

/* struct svc_xprt_ops has 'xpo_read_payload' field */
/* #undef HAVE_XPO_READ_PAYLOAD */

/* struct svc_xprt_ops has 'xpo_result_payload' field */
#define HAVE_XPO_RESULT_PAYLOAD 1

/* xpo_secure_port is defined and returns void */
/* #undef HAVE_XPO_SECURE_PORT_NO_RETURN */

/* xprt_add_backlog is exported by the sunrpc core */
#define HAVE_XPRT_ADD_BACKLOG 1

/* struct xprt_class has 'netid' field */
#define HAVE_XPRT_CLASS_NETID 1

/* *send_request has 'struct rpc_rqst *req' as a param */
#define HAVE_XPRT_OPS_SEND_REQUEST_RQST_ARG 1

/* xprt_pin_rqst is exported by the sunrpc core */
#define HAVE_XPRT_PIN_RQST 1

/* struct rpc_xprt has 'queue_lock' field */
#define HAVE_XPRT_QUEUE_LOCK 1

/* xprt_reconnect_delay is exported by the kernel */
#define HAVE_XPRT_RECONNECT_DELAY 1

/* get cong request */
#define HAVE_XPRT_REQUEST_GET_CONG 1

/* xprt_wait_for_buffer_space has xprt as a parameter */
#define HAVE_XPRT_WAIT_FOR_BUFFER_SPACE_RQST_ARG 1

/* struct xps_map is defined */
#define HAVE_XPS_MAP 1

/* __vlan_hwaccel_clear_tag defined */
#define HAVE__VLAN_HWACCEL_CLEAR_TAG 1

/* __atomic_add_unless is defined */
/* #undef HAVE___ATOMIC_ADD_UNLESS */

/* __blkdev_issue_discard is defined */
/* #undef HAVE___BLKDEV_ISSUE_DISCARD */

/* __cancel_delayed_work is defined */
/* #undef HAVE___CANCEL_DELAYED_WORK */

/* __ethtool_get_link_ksettings is defined */
#define HAVE___ETHTOOL_GET_LINK_KSETTINGS 1

/* __flow_indr_block_cb_register is defined */
/* #undef HAVE___FLOW_INDR_BLOCK_CB_REGISTER */

/* __get_task_comm is exported by the kernel */
/* #undef HAVE___GET_TASK_COMM_EXPORTED */

/* __inet6_lookup_established has 7 params */
/* #undef HAVE___INET6_LOOKUP_ESTABLISHED_HAS_7_PARAMS */

/* HAVE___IP_DEV_FIND is exported by the kernel */
#define HAVE___IP_DEV_FIND 1

/* netdevice.h has __netdev_tx_sent_queue */
#define HAVE___NETDEV_TX_SENT_QUEUE 1

/* __tc_indr_block_cb_register is defined */
/* #undef HAVE___TC_INDR_BLOCK_CB_REGISTER */

/* Name of package */

/* Define to the address where bug reports for this package should be sent. */

/* Define to the full name of this package. */

/* Define to the full name and version of this package. */

/* Define to the one symbol short name of this package. */

/* Define to the home page for this package. */

/* Define to the version of this package. */

/* The size of `unsigned long long', as computed by sizeof. */
#define SIZEOF_UNSIGNED_LONG_LONG 8

/* Define to 1 if you have the ANSI C header files. */
#define STDC_HEADERS 1

/* Version number of package */

/* Make sure LINUX_BACKPORT macro is defined for all external users */
#ifndef LINUX_BACKPORT
#define LINUX_BACKPORT(__sym) backport_ ##__sym
#endif

