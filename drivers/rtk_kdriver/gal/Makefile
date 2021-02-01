KBUILD_CPPFLAGS += -Idrivers/rtk_kdriver/include/rtk_kdriver
KBUILD_CPPFLAGS += -Idrivers/rtk_kdriver/include
KBUILD_CPPFLAGS += -Idrivers/staging/android/ion
KBUILD_CPPFLAGS += -Idrivers/rtk_kdriver/gal

#KBUILD_CFLAGS += -Werror

# SE
obj-$(CONFIG_RTK_KDRV_SE) += rtk_se_driver.o rtk_se_lib.o rtk_kadp_se.o rtk_se_stch.o

# GDMA Driver
obj-$(CONFIG_RTK_KDRV_GDMA)     += rtk_gdma.o rtk_osd_sr_driver.o osd_dump_agent.o

# GAL Driver
obj-$(CONFIG_RTK_KDRV_GAL)    += rtk_kadp_gal_gfx.o rtk_kadp_gdma_hal_gal.o rtk_kadp_hal_gal_surface.o
