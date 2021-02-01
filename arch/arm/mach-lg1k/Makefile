#
# Makefile for the linux kernel.
#

obj-y				+= mach.o
obj-y 				+= firmware.o
obj-$(CONFIG_SMP)		+= smp.o headsmp.o
obj-$(CONFIG_USB)		+= usb.o
obj-$(CONFIG_CACHE_L2X0)	+= l2cc.o
obj-y				+= smc.o headsmc.o
obj-y				+= eth.o
obj-$(CONFIG_SERIAL_AMBA_PL011)	+= uart.o
obj-$(CONFIG_PM)		+= pm.o
obj-$(CONFIG_ION_LG115X)	+= ion.o
obj-$(CONFIG_SPI_PL022)		+= spi.o
obj-y				+= ksyms.o
obj-y				+= pms.o
obj-y				+= sram.o
obj-$(CONFIG_AMBA_PL08X)        += dmac.o
obj-y				+= kmsg.o
