#
# Makefile for the kernel mmc device drivers.
#

#kdriver support
ifdef CONFIG_RTK_KDRIVER_SUPPORT
KBUILD_CPPFLAGS += -I drivers/rtk_kdriver/include/
KBUILD_CPPFLAGS += -I drivers/rtk_kdriver/include/rtk_kdriver
KBUILD_CPPFLAGS += -I drivers/rtk_kdriver

endif


subdir-ccflags-$(CONFIG_MMC_DEBUG) := -DDEBUG

obj-$(CONFIG_MMC)		+= core/
obj-$(CONFIG_MMC)		+= card/
obj-$(subst m,y,$(CONFIG_MMC))	+= host/
