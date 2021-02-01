#
# Makefile for the linux kernel.
#
KBUILD_CPPFLAGS += -I drivers/rtk_kdriver/include/
KBUILD_CPPFLAGS += -I drivers/rtk_kdriver/include/rtk_kdriver
KBUILD_CPPFLAGS += -I drivers/rtk_kdriver/ir/inc
KBUILD_CPPFLAGS += -I drivers/rtk_kdriver
# Inpute device
obj-$(CONFIG_RTK_KDRV_IR) += irrc_dev.o irrc_core.o irrc_sysfs.o
obj-$(CONFIG_RTK_KDRV_RAW_MODE) += irrc_raw.o
obj-$(CONFIG_RTK_KDRV_INPUT_DEVICE) += ir_input.o
obj-$(CONFIG_RTK_KDRV_RECORD_KEY) += irrc_record.o
obj-$(CONFIG_RTK_KDRV_IR_MOD_KEY_TOOL) += irrc_modulate.o
obj-$(CONFIG_RTK_KDRV_SUPPORT_ALC_COMMAND) += rtk_voice_dev.o
#obj-y += rtk_joystick_dev.o
