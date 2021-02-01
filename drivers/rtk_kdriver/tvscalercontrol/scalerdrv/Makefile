# Makefile for the Realtek scaler related drivers.
#
obj-y := mode.o framesync.o power.o scalerdrv.o scalerclock.o scalerdisplay.o scalerip.o scalermemory.o conversion_2d_3d.o scaler_2dcvt3d_ctrl.o inprocvga.o inprocypbpr.o adjust.o syncproc.o auto.o inprocvideo.o zoom_smoothtoggle.o zoom_smoothtoggle_lib.o pipmp.o overscanTable.o
obj-y += scaler_i2rnd.o
obj-y += scaler_pst.o

#ifeq ($(CONFIG_ENABLE_DOLBY_VISION_HDMI_AUTO_DETECT),y)
obj-y += scaler_hdr_rpc.o scaler_hdr_ctrl.o
#endif

#ifeq ($(CONFIG_ENABLE_HDR10_HDMI_AUTO_DETECT),y)
#obj-y += scaler_hdr_ctrl.o
#endif

#obj-y :=