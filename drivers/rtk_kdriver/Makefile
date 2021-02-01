###################################################################
# Setup Include Path
###################################################################
KBUILD_CPPFLAGS += -I drivers/rtk_kdriver/include/
KBUILD_CPPFLAGS += -I drivers/rtk_kdriver/include/rtk_kdriver
KBUILD_CPPFLAGS += -I drivers/rtk_kdriver

KBUILD_CPPFLAGS += -DLITTLE_ENDIAN
KBUILD_CFLAGS += -fno-unsigned-char

###################################################################
# Must have
###################################################################
obj-$(CONFIG_RTK_KDRIVER_SUPPORT) += crt/

###################################################################
# Generic drivers
###################################################################
#PCBMGR
obj-$(CONFIG_REALTEK_PCBMGR) += pcbmgr/

# RPC
obj-$(CONFIG_RTK_KDRV_RPC) += RPC.o
RPC-objs := RPCDriver.o RPCintr.o RPCpoll.o RPCkern.o RPClog.o

# AVCPU
obj-$(CONFIG_RTK_KDRV_AVCPU) += rtk_avcpu.o

# rtk_semaphore
obj-$(CONFIG_RTK_SEMAPHORE) += rtk_semaphore.o
obj-$(CONFIG_RTK_SEMAPHORE_TEST) += rtk_semaphore_test.o

# AMP init driver
# Please notice that this is only for REALTEK_AMP_TAS5711 & REALTEK_AMP_ACL1310
# If use different IC, please change this.
obj-$(CONFIG_RTK_KDRV_AMP) += amp/
# EMCU
obj-$(CONFIG_RTK_KDRV_EMCU) += rtk_emcu.o
obj-$(CONFIG_RTK_KDRV_EMCU) += emcu/

# RTD LOGBUF
obj-$(CONFIG_REALTEK_LOGBUF) += rtd_logger.o

# SB2
obj-$(CONFIG_RTK_KDRV_SB2) += rtk_sb2.o rtk_busto.o

#DBG HELP
obj-$(CONFIG_RTK_ONLINE_HELP) += rtk_online_help.o

# SWITCH
obj-$(CONFIG_RTK_KDRV_SWITCH) += switch/

# GPIO
obj-$(CONFIG_RTK_KDRV_GPIO) += gpio/

#obj-$(CONFIG_RTK_KDRV_GPIO) += lnbgpio/

# PWM
obj-$(CONFIG_RTK_KDRV_PWM) += pwm/
# PCMCIA
obj-$(CONFIG_RTK_KDRV_PCMCIA) += pcmcia/rtk_pcmcia.o

# SMARTCARD
obj-$(CONFIG_RTK_KDRV_SMARTCARD) += smartcard/

# CEC
obj-$(CONFIG_RTK_KDRV_CEC) += cec/

# DDC
obj-$(CONFIG_RTK_KDRV_DDC) += ddc/
# CP
obj-$(CONFIG_RTK_KDRV_MCP) += mcp/

# CW
obj-$(CONFIG_RTK_KDRV_CW) += cw/

# OTP
obj-$(CONFIG_RTK_KDRV_OTP) += otp/
obj-$(CONFIG_RTK_KDRV_HDCP_KEY_FROM_OTP) += rtk_hdcp_otp_util.o

# RNG
obj-$(CONFIG_RTK_KDRV_RNG) += rtk_rng.o

# DV
ifeq ($(CONFIG_SUPPORT_SCALER),y)
obj-$(CONFIG_RTK_KDRV_DV) += dolby_IDK_1_4_3/
else
#obj-$(CONFIG_RTK_KDRV_DV) += dolbyvision_edr/
endif

#USBDUMP
obj-$(CONFIG_RTK_USBDUMP_ENABLE) += rtk_usbdump.o

# MD
obj-$(CONFIG_RTK_KDRV_MD) += md/

# LSADC
obj-$(CONFIG_RTK_KDRV_LSADC) += lsadc/

# UART
obj-$(CONFIG_RTK_KDRV_SERIAL_8250) += uart/

# RTC
obj-$(CONFIG_RTK_KDRV_RTC) += rtk_rtc.o

# Watch Dog
obj-$(CONFIG_RTK_KDRV_WATCHDOG) += rtk_watchdog.o

# Thermal Sensor
obj-$(CONFIG_RTK_KDRV_THERMAL_SENSOR) += thermal/

# CPU Freq
obj-$(CONFIG_RTK_KDRV_CPU_FREQUENCY) += rtk_clock.o

# ARM wrapper monitor
obj-$(CONFIG_REALTEK_ARM_WRAPPER) += arm_wrapper.o

# DCU Memory Trash Detector
obj-$(CONFIG_RTK_KDRV_DC_MEMORY_TRASH_DETCTER) += rtk_dc_mt.o
obj-y += rtk_dc_simulator.o

# QoS
obj-$(CONFIG_RTK_KDRV_QOS_CONTROL) += rtk_qos.o

# HW Watchpoint
obj-$(CONFIG_RTK_KDRV_WATCHPOINT) += rtk_venus_watch.o

# Frame Buffer
obj-$(CONFIG_RTK_KDRV_VENUS_FB) += rtk_venusfb.o

# RTICE Driver
obj-$(CONFIG_RTK_KDRV_RTICE) += rtice/

# IRDA Driver
obj-$(CONFIG_RTK_KDRV_IR) += ir/

# VGIP ISR Driver
obj-$(CONFIG_RTK_KDEV_VGIP_INTERRUPT) += rtk_vgip_isr.o
obj-$(CONFIG_RTK_KDEV_VGIP_INTERRUPT) += vgip_isr/

# MEMC ISR Driver
obj-$(CONFIG_RTK_KDEV_MEMC_INTERRUPT) += rtk_memc_isr.o
obj-$(CONFIG_RTK_KDEV_MEMC_INTERRUPT) += memc_isr/

# SCALER
obj-$(CONFIG_SUPPORT_SCALER) += tvscalercontrol/

# LG BOARD
obj-$(CONFIG_RTK_KDRV_LG_BOARD) += rtk_lg_board.o

# LNB Uart patch
#obj-$(CONFIG_RTK_KDRV_LNB_UART) += lnbuart/

# DISEQC
obj-$(CONFIG_RTK_KDRV_DISEQC) += diseqc/

# Pinmux Driver
obj-$(CONFIG_RTK_KDRV_PINMUX) += rtk_pinmux.o

# GAL Driver
obj-$(CONFIG_RTK_KDRV_SE) += gal/
obj-$(CONFIG_RTK_KDRV_GDMA) += gal/
obj-$(CONFIG_CUSTOMER_TV006) += gal/

# Misc Driver
obj-$(CONFIG_RTK_KDRV_MISC_DEV) += misc.o
# MMC/Card-Reafder
ifeq (y,$(filter y, $(CONFIG_ARCH_RTK284X)))
obj-$(CONFIG_MMC_RTKEMMC_PLUS) += mmc/
endif

# ETN Driver
obj-$(CONFIG_RTK_KDRV_R8168) += rtk_8168.o
# I2C Driver
obj-$(CONFIG_RTK_KDRV_I2C) += i2c/

# Audio HW Driver
obj-$(CONFIG_RTK_KDRV_AUDIO_HW) += audio_hw/

# USB host controller
obj-$(CONFIG_RTK_KDRV_USB) += usb/


# DDR DM scan 
obj-y += rtk_scan.o

# Keypad Driver
obj-$(CONFIG_RTK_KDRV_KEYPAD) += keypad/

###################################################################
# DTV Related drivers
###################################################################

#K3L use external ademod
#ADEMOD Kernel driver
#obj-$(CONFIG_RTK_KDRV_ADEMOD) += ademod/

#DEMOD Kernel driver
obj-$(CONFIG_RTK_KDRV_DEMOD) += demod/

#TP Kernel driver
obj-$(CONFIG_RTK_KDRV_TP) += tp/

#ATSC3 DMX
obj-$(CONFIG_RTK_KDRV_ATSC3_DMX) += atsc3_dmx/

###################################################################
# HAL Related drivers
###################################################################

# CRM
obj-$(CONFIG_RTK_KDRV_CRM) += crm/

# OMX
obj-$(CONFIG_RTK_KDRV_OMX) += omx/

# Demux HAL Driver
ifeq (y,$(filter y, $(CONFIG_CUSTOMER_TV006)))
obj-$(CONFIG_RTK_KDRV_DEMUX) += demux/
else
obj-$(CONFIG_RTK_KDRV_DEMUX) += demux_tv001/
endif
obj-$(CONFIG_RTK_KDRV_AUDIO) += audio/
obj-$(CONFIG_RTK_KDRV_VDEC) += vdec/

obj-$(CONFIG_RTK_KDRV_TEEPROXY) += teeproxy/

