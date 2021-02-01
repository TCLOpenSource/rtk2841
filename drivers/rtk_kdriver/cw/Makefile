#
# Makefile for the Realtek mcp drivers.
#
CONFIG_RTK_KDRV_CW=y
CONFIG_RTK_KDRV_CW_SIGNEL_CPU=y
KBUILD_CPPFLAGS += -I ./
obj-$(CONFIG_RTK_KDRV_CW) += rtk_cw_dev.o  rtk_cw_util.o
obj-$(CONFIG_RTK_KDRV_CW_SIGNEL_CPU) += scpu/rtk_cw_adapter_scpu.o

