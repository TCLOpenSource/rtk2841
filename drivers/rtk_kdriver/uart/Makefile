obj-$(CONFIG_RTK_KDRV_SERIAL_8250)		+= rtk_8250.o rtk_8250_base.o
rtk_8250-y					:= 8250_core.o
rtk_8250_base-y				:= 8250_port.o
rtk_8250_base-$(CONFIG_RTK_KDRV_SERIAL_8250_UART_DMA)		+= 8250_rtk_uart_dma.o
obj-$(CONFIG_RTK_KDRV_SERIAL_8250_CONSOLE)	+= 8250_early.o

