obj-$(CONFIG_TEE) += tee.o
tee-objs += tee_core.o
tee-objs += tee_shm.o
tee-objs += tee_shm_pool.o
obj-$(CONFIG_OPTEE) += optee/

TOP_DIR_OPTEE_DRIVER = $(shell pwd)/drivers/tee
export TOP_DIR_OPTEE_DRIVER
ccflags-y += -include $(TOP_DIR_OPTEE_DRIVER)/rtk_conf.h
