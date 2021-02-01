#
# Makefile for the linux kernel.
#

obj-y				+= core.o
obj-$(CONFIG_AMBA_PL08X)	+= dmac.o
obj-$(CONFIG_MMC_SDHCI_LG115X)	+= emmc.o
obj-y				+= ether.o
obj-$(CONFIG_CACHE_L2X0)	+= l2cc.o
obj-$(CONFIG_CPU_HAS_PMU)	+= pmu.o
obj-$(CONFIG_SPI_PL022)		+= spi.o
obj-y				+= time.o
obj-$(CONFIG_SERIAL_AMBA_PL011)	+= uart.o
obj-$(CONFIG_USB)		+= usb.o
obj-y				+= wdog.o
obj-$(CONFIG_LG_XIP)		+= xip.o
obj-$(CONFIG_HOTPLUG_CPU)	+= hotplug.o
obj-$(CONFIG_SMP)		+= headsmp.o
obj-$(CONFIG_SMP)		+= platsmp.o
obj-$(CONFIG_SMP)		+= smp.o
obj-$(CONFIG_PM)		+= pm.o
obj-y					+= headsmc.o
obj-y					+= smc.o
obj-y					+= firmware.o
obj-$(CONFIG_ION_LG115X)	+= ion.o
obj-y				+= ksyms.o
