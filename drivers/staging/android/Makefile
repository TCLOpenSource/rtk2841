ccflags-y += -I$(src)			# needed for trace events

obj-y					+= ion/

obj-$(CONFIG_SYNC)			+= sync.o sync_debug.o
obj-$(CONFIG_SW_SYNC)			+= sw_sync.o

ifeq ($(CONFIG_USE_ANDROID_O_DRIVER), y)
obj-$(CONFIG_FIQ_DEBUGGER)      += fiq_debugger/

obj-$(CONFIG_ASHMEM)            += o/ashmem.o
obj-$(CONFIG_ANDROID_TIMED_OUTPUT)  += o/timed_output.o
obj-$(CONFIG_ANDROID_TIMED_GPIO)    += o/timed_gpio.o
obj-$(CONFIG_ANDROID_LOW_MEMORY_KILLER) += o/lowmemorykiller.o
obj-$(CONFIG_ANDROID_LOGGER)            += o/logger.o
else
obj-$(CONFIG_ASHMEM)                   += n/ashmem.o
obj-$(CONFIG_ANDROID_TIMED_OUTPUT)     += n/timed_output.o
obj-$(CONFIG_ANDROID_TIMED_GPIO)       += n/timed_gpio.o
obj-$(CONFIG_ANDROID_LOW_MEMORY_KILLER)        += n/lowmemorykiller.o
endif

