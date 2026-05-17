# SPDX-License-Identifier: GPL-2.0-only
obj-$(CONFIG_MLX4_INFINIBAND)	+= mlx4_ib.o
OBJECT_FILES_NON_STANDARD := y

mlx4_ib-y :=	ah.o cq.o doorbell.o mad.o main.o mr.o qp.o srq.o mcg.o cm.o alias_GUID.o sysfs.o

ifneq ($(CONFIG_MLX4_IB_STOCK_RDMA_ABI),y)
mlx4_ib-y +=	main_exp.o mr_exp.o cq_exp.o qp_exp.o
else
ccflags-y += -DCONFIG_MLX4_IB_STOCK_RDMA_ABI
endif

mlx4_ib-$(CONFIG_MLX4_IB_DEBUG_FS) += debugfs.o
mlx4_ib-$(CONFIG_MLX4_IB_DEBUG_FS) += ecn.o
