#
# Makefile for the Realtek network device drivers.
#
#kdriver support
ifdef CONFIG_RTK_KDRIVER_SUPPORT
KBUILD_CPPFLAGS += -Idrivers/rtk_kdriver/include
endif

obj-$(CONFIG_8139CP) += 8139cp.o
obj-$(CONFIG_8139TOO) += 8139too.o
obj-$(CONFIG_ATP) += atp.o
obj-$(CONFIG_R8169) += r8169.o
obj-$(CONFIG_R8168) += rtk_8168.o
