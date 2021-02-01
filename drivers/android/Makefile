ccflags-y += -I$(src)			# needed for trace events

ifeq ($(CONFIG_USE_ANDROID_O_DRIVER), y)
obj-$(CONFIG_ANDROID_BINDER_IPC)    += o/binder.o o/binder_alloc.o
obj-y								+= o/sbinder.o
else
obj-$(CONFIG_ANDROID_BINDER_IPC)    += n/binder.o
endif

obj-$(CONFIG_ANDROID_BINDER_IPC_SELFTEST) += o/binder_alloc_selftest.o
