#if 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#endif
#include <rbus/dma_vgip_reg.h>
#include <rbus/h3ddma_rgb2yuv_dither_4xxto4xx_reg.h>
#include <rbus/h3ddma_reg.h>
#include <rbus/h3ddma_hsd_reg.h>
#include <rbus/scaleup_reg.h>
//#include <rbus/scaler/rbusPpOverlayReg.h>
#include <rbus/mdomain_cap_reg.h>
#include <rbus/mdomain_disp_reg.h>
//#include <rbus/scaler/rbusPpOverlayReg.h>
#include <rbus/ppoverlay_reg.h>


#include <generated/autoconf.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/slab.h>
#include <linux/fs.h>
#include <linux/platform_device.h>
#include <linux/mtd/mtd.h>
#include <asm/uaccess.h>
#include <asm/cacheflush.h>
#include <linux/pageremap.h>

//#include <mach/video_driver.h>
#include <rtk_kdriver/RPCDriver.h>


#include <uapi/linux/const.h>
#include <linux/mm.h>


#include <tvscalercontrol/i3ddma/i3ddma.h>
#include <tvscalercontrol/i3ddma/i3ddma_drv.h>
#include <tvscalercontrol/i3ddma/i3ddma_uzd.h>
#include <tvscalercontrol/scaler/modeState.h>
//#include <tvscalercontrol/scaler/scalerlib.h>
#include <tvscalercontrol/vip/ultrazoom.h>
#include <tvscalercontrol/panel/panelapi.h>
#include <tvscalercontrol/adcsource/vga.h>
#include <tvscalercontrol/adcsource/adcctrl.h>
#include <tvscalercontrol/scaler_vfedev.h>
//#ifdef DTV_SCART_OUT_ENABLE
#include "tvscalercontrol/tve/tve.h"
#include <rbus/dma_vgip_reg.h>
#include <scalercommon/scalerDrvCommon.h>
#include <scalercommon/scalerCommon.h>
//#endif
#include <rbus/dc2h_dma_reg.h>
#include <tvscalercontrol/scalerdrv/scaler_i2rnd.h>
#include <rtk_kdriver/rpc/VideoRPC_System.h>
#include <rtk_kdriver/rpc/VideoRPC_System_data.h>
//#include <tvscalercontrol/hdmirx/hdmiInternal.h>

extern I3DDMA_3DDMA_CTRL_T i3ddmaCtrl;
I3DDMA_TIMING_T       inputTiming;
I3DDMA_TIMING_T       genTiming;

#define UNCAC_BASE		_AC(0xa0000000, UL)

#include <mach/rtk_log.h>
#define TAG_NAME_VSC "VSC"	//log tag

void drvif_I3DDMA_Init(void)
{

	i3ddmaCtrl.hw_dither12x10_enable = 0;
	i3ddmaCtrl.hw_i3ddma_dma = I3DDMA_3D_OPMODE_HW;

// [HDMI-DMA] HDMI-DMA capture enable for 4k2k video timing
#ifdef ENABLE_HDMI_DMA_FOR_4K2K
	i3ddmaCtrl.force_all_3d_disable = 0;
	i3ddmaCtrl.force_2dto3d_enable = 1;
/* not defined
#elif ENABLE_DRIVER_I3DDMA
	i3ddmaCtrl.force_all_3d_disable = 0;
	i3ddmaCtrl.force_2dto3d_enable = 1;
*/
#else
	i3ddmaCtrl.force_all_3d_disable = 1;
	i3ddmaCtrl.force_2dto3d_enable = 0;
#endif

	i3ddmaCtrl.force_3dto2d_enable = 0;
	i3ddmaCtrl.force_2dto3d_mode = I3DDMA_2D_ONLY;
#ifndef CONFIG_FORCE_RUN_I3DDMA
	i3ddmaCtrl.i3ddma_3d_capability = 0;
#endif
	i3ddmaCtrl.enable_3ddma = 1;

//#ifdef HDMI_HAVE_HDMI_DMA
#ifndef CONFIG_FORCE_RUN_I3DDMA
	i3ddmaCtrl.hw_dither10x8_enable = 0;
	i3ddmaCtrl.hw_4xxto4xx_enable = 0;
	i3ddmaCtrl.hw_rgbtoyuv_enable = 0;
	i3ddmaCtrl.cap_buffer[0].cache = NULL;
    i3ddmaCtrl.cap_buffer[1].cache = NULL;
	i3ddmaCtrl.cap_buffer[2].cache = NULL;
	i3ddmaCtrl.cap_buffer[3].cache = NULL;
#endif

//#ifdef HDMI_HAVE_HDMI_3D_TG

	memset((void*) &inputTiming, 0, sizeof(I3DDMA_TIMING_T));
	memset((void*) &genTiming, 0, sizeof(I3DDMA_TIMING_T));
	i3ddmaCtrl.ptx_timing = &inputTiming;
	i3ddmaCtrl.pgen_timing = &genTiming;

	// [IDMA] allocate/release IDMA memory dynamic
	if(I3DDMA_Get3DAllocReleaseMemoryDynamic() == FALSE)
	I3DDMA_3DDMAInit();

	return;
}



void drvif_I3DDMA_DeInit(void)
{
	I3DDMA_3DDMADeInit();
}



void drvif_I3DDMA_Set_Input_Info_Vaule(I3DDMA_INFO_LIST input_type, UINT32 value)
{
	switch(input_type)
	{
		case I3DDMA_INFO_HW_I3DDMA_DMA:
			i3ddmaCtrl.hw_i3ddma_dma = (I3DDMA_3D_OPMODE_T) value;
		break;

		case I3DDMA_INFO_HW_DITHER12X10_ENABLE:
			i3ddmaCtrl.hw_dither12x10_enable= value;
		break;

		case I3DDMA_INFO_HW_DITHER10x8_ENABLE:
			i3ddmaCtrl.hw_dither10x8_enable= value;
		break;

		case I3DDMA_INFO_HW_4XXTO4XX_ENABLE:
			i3ddmaCtrl.hw_4xxto4xx_enable= value;
		break;

		case I3DDMA_INFO_HW_RGBTOYUV_ENABLE:
			i3ddmaCtrl.hw_rgbtoyuv_enable= value;
		break;

		case I3DDMA_INFO_INPUT_TIMING:
			memcpy((void*) i3ddmaCtrl.ptx_timing, (void*) value, sizeof(I3DDMA_TIMING_T));
		break;

		case I3DDMA_INFO_GEN_TIMING:
			memcpy((void*) i3ddmaCtrl.pgen_timing, (void*) value, sizeof(I3DDMA_TIMING_T));
		break;

		case I3DDMA_INFO_FRAMERATE_X2:
			i3ddmaCtrl.frame_rate_x2= value;
		break;

		case I3DDMA_INFO_HW_HSD_ENABLE:
			i3ddmaCtrl.hw_hsd_enable = value;
		break;

		case I3DDMA_INFO_INPUT_SRC_IDX:
			i3ddmaCtrl.input_src_idx= value;
		break;

		case I3DDMA_INFO_INPUT_SRC_TYPE:
			i3ddmaCtrl.input_src_type= value;
		break;

		case I3DDMA_INFO_INPUT_SRC_FROM:
			i3ddmaCtrl.input_src_from= value;
		break;

		case I3DDMA_INFO_INPUT_MODE_CURR:
			i3ddmaCtrl.input_src_mode= value;
		break;

		case I3DDMA_INFO_INPUT_H_COUNT:
			i3ddmaCtrl.input_h_Count= value;
		break;

		case I3DDMA_INFO_INPUT_H_SIZE:
			i3ddmaCtrl.input_h_size= value;
		break;

		case I3DDMA_INFO_OUTPUT_H_SIZE:
			i3ddmaCtrl.output_h_size= value;
		break;

		case I3DDMA_INFO_TARGET_DEPTH:
			i3ddmaCtrl.targetDepth= (I3DDMA_COLOR_DEPTH_T) value;
		break;

		case I3DDMA_INFO_TARGET_COLOR:
			i3ddmaCtrl.targetColor= (I3DDMA_COLOR_SPACE_T) value;
		break;


		default:

			break;

	};

}


UINT32 drvif_I3DDMA_Get_Input_Info_Vaule(I3DDMA_INFO_LIST input_type)
{
	switch(input_type)
	{
		case I3DDMA_INFO_HW_I3DDMA_DMA:
			return (UINT32) i3ddmaCtrl.hw_i3ddma_dma;
		break;

		case I3DDMA_INFO_HW_DITHER12X10_ENABLE:
			return i3ddmaCtrl.hw_dither12x10_enable;
		break;

		case I3DDMA_INFO_HW_DITHER10x8_ENABLE:
			return i3ddmaCtrl.hw_dither10x8_enable;
		break;

		case I3DDMA_INFO_HW_4XXTO4XX_ENABLE:
			return i3ddmaCtrl.hw_4xxto4xx_enable;
		break;

		case I3DDMA_INFO_HW_RGBTOYUV_ENABLE:
			return i3ddmaCtrl.hw_rgbtoyuv_enable;
		break;

		case I3DDMA_INFO_INPUT_TIMING:
			return (UINT32) i3ddmaCtrl.ptx_timing;
		break;

		case I3DDMA_INFO_GEN_TIMING:
			return (UINT32) i3ddmaCtrl.pgen_timing;
		break;

		case I3DDMA_INFO_FRAMERATE_X2:
			return i3ddmaCtrl.frame_rate_x2;
		break;

		case I3DDMA_INFO_ENABLE_3DDMA:
			return i3ddmaCtrl.enable_3ddma;
		break;

		case I3DDMA_INFO_HW_HSD_ENABLE:
			return i3ddmaCtrl.hw_hsd_enable;
		break;

		case I3DDMA_INFO_INPUT_SRC_IDX:
			return i3ddmaCtrl.input_src_idx;
		break;

		case I3DDMA_INFO_INPUT_SRC_TYPE:
			return i3ddmaCtrl.input_src_type;
		break;

		case I3DDMA_INFO_INPUT_SRC_FROM:
			return i3ddmaCtrl.input_src_from;
		break;

		case I3DDMA_INFO_INPUT_MODE_CURR:
			return i3ddmaCtrl.input_src_mode;
		break;

		case I3DDMA_INFO_INPUT_H_COUNT:
			return i3ddmaCtrl.input_h_Count;
		break;

		case I3DDMA_INFO_INPUT_H_SIZE:
			return i3ddmaCtrl.input_h_size;
		break;

		case I3DDMA_INFO_OUTPUT_H_SIZE:
			return i3ddmaCtrl.output_h_size;
		break;

		case I3DDMA_INFO_TARGET_DEPTH:
			return i3ddmaCtrl.targetDepth;
		break;

		case I3DDMA_INFO_TARGET_COLOR:
			return i3ddmaCtrl.targetColor;
		break;

		default:
			break;

	};

	return 0;
}



char drvif_I3DDMA_3D_FeatureEnable(char enable) {
	static char curEnStatus=0;

#ifndef ENABLE_HDMI_DMA_FOR_4K2K
	i3ddmaCtrl.force_all_3d_disable = enable == 0;
#endif
	if (i3ddmaCtrl.force_all_3d_disable) {
		I3DDMA_3DDMADeInit();
	} else {
		// [IDMA] allocate/release IDMA memory dynamic
		if(I3DDMA_Get3DAllocReleaseMemoryDynamic() == FALSE)
		I3DDMA_3DDMAInit();
	}

	if(enable != curEnStatus)
		i3ddmaCtrl.resume = 1;
	curEnStatus = enable;

	pr_debug("hdmi.force = %d %d\n", i3ddmaCtrl.force_all_3d_disable, enable);
	return TRUE;

}

extern unsigned char get_i3dma_uzd(void);
extern unsigned char Get_Factory_SelfDiagnosis_Mode(void);
void drv_I3DDMA_ApplySetting()
{

#if 0
	if(i3ddmaCtrl.hw_hsd_enable == 1){
		I3DDMA_ultrazoom_config_h_scaling_down(i3ddmaCtrl.input_h_size, i3ddmaCtrl.output_h_size, 0);
		i3ddmaCtrl.ptx_timing->h_act_len = i3ddmaCtrl.output_h_size;
	}
#endif

	I3DDMA_Get3DGenTiming(i3ddmaCtrl.ptx_timing, i3ddmaCtrl.pgen_timing);
#ifdef CONFIG_I2RND_ENABLE
	if(Scaler_I2rnd_get_enable() && (i3ddmaCtrl.ptx_timing->h_act_len > 1920)){
		printk(KERN_EMERG"[I2RND]IDMA uzd to 2k1k\n");
		SIZE insize,outsize;
		insize.nLength = i3ddmaCtrl.ptx_timing->v_act_len;
		insize.nWidth = i3ddmaCtrl.ptx_timing->h_act_len;
		outsize.nLength = 1080;
		outsize.nWidth = 1920;
		i3ddmaCtrl.pgen_timing->h_act_len = 1920;
		i3ddmaCtrl.pgen_timing->v_act_len = 1080;
		I3DDMA_ultrazoom_config_scaling_down(&insize, &outsize, 1);
	}
	else
#endif
	if(((i3ddmaCtrl.ptx_timing->h_act_len > 1920)||(i3ddmaCtrl.ptx_timing->v_act_len > 1080)) && get_i3dma_uzd())
	{
		printk(KERN_EMERG"[MAC5P]IDMA always uzd to 2k1k\n");
		SIZE insize,outsize;
		insize.nLength = i3ddmaCtrl.ptx_timing->v_act_len;
		insize.nWidth = i3ddmaCtrl.ptx_timing->h_act_len;
		if(i3ddmaCtrl.ptx_timing->h_act_len > 1920)
		{
			outsize.nWidth = 1920;
			i3ddmaCtrl.pgen_timing->h_act_len = 1920;
		}
		else
		{
			outsize.nWidth = i3ddmaCtrl.ptx_timing->h_act_len;
			i3ddmaCtrl.pgen_timing->h_act_len = i3ddmaCtrl.ptx_timing->h_act_len;
		}
		if(i3ddmaCtrl.ptx_timing->v_act_len > 1080)
		{
			outsize.nLength = 1080;
			i3ddmaCtrl.pgen_timing->v_act_len = 1080;
		}
		else
		{
			outsize.nLength = i3ddmaCtrl.ptx_timing->v_act_len;
			i3ddmaCtrl.pgen_timing->v_act_len = i3ddmaCtrl.ptx_timing->v_act_len;
		}
		I3DDMA_ultrazoom_config_scaling_down(&insize, &outsize, 1);
	}
#ifdef CONFIG_FORCE_RUN_I3DDMA
	else if((i3ddmaCtrl.ptx_timing->h_act_len ==1440) && (DMA_VGIP_DMA_VGIP_CTRL_get_dma_in_sel(rtd_inl(DMA_VGIP_DMA_VGIP_CTRL_reg)) == VGIP_SRC_ATV))
	{
		pr_debug("av source,1440->960\n");
		SIZE insize,outsize;
		insize.nLength = i3ddmaCtrl.ptx_timing->v_act_len;
		insize.nWidth = i3ddmaCtrl.ptx_timing->h_act_len;
		outsize.nLength = i3ddmaCtrl.ptx_timing->v_act_len;

#ifdef CONFIG_ENABLE_VD_27MHZ_MODE
		//self-dianosis AV source force to 704, rzhen@2016-09-01
		if((Get_DisplayMode_Src(SLR_MAIN_DISPLAY) == VSC_INPUTSRC_AVD)
			&& Get_Factory_SelfDiagnosis_Mode()){
			outsize.nWidth = 704;
			i3ddmaCtrl.pgen_timing->h_act_len = 704;
		}
		else
#endif
		{
			outsize.nWidth = 960;
			i3ddmaCtrl.pgen_timing->h_act_len = 960;
		}

		I3DDMA_ultrazoom_config_scaling_down(&insize, &outsize, 1);
	}
#endif
	else
	{
		h3ddma_hsd_i3ddma_hsd_ctrl0_RBUS i3ddma_hsd_ctrl0_reg;
		i3ddma_hsd_ctrl0_reg.regValue = IoReg_Read32(H3DDMA_HSD_I3DDMA_HSD_Ctrl0_reg);
		i3ddma_hsd_ctrl0_reg.h_zoom_en = 0;
		IoReg_Write32(H3DDMA_HSD_I3DDMA_HSD_Ctrl0_reg, i3ddma_hsd_ctrl0_reg.regValue);

		//reset v-scale down buffer mode @Crixus 20160804
		h3ddma_hsd_i3ddma_vsd_ctrl0_RBUS i3ddma_vsd_ctrl0_reg;
		i3ddma_vsd_ctrl0_reg.regValue = IoReg_Read32(H3DDMA_HSD_I3DDMA_VSD_Ctrl0_reg);
		i3ddma_vsd_ctrl0_reg.v_zoom_en = 0;
		i3ddma_vsd_ctrl0_reg.buffer_mode = 0;
		IoReg_Write32(H3DDMA_HSD_I3DDMA_VSD_Ctrl0_reg, i3ddma_vsd_ctrl0_reg.regValue);
	}

	I3DDMA_BandWidth_Control(i3ddmaCtrl.ptx_timing, i3ddmaCtrl.pgen_timing);
	I3DDMA_Dithering12to10(i3ddmaCtrl.ptx_timing->depth, i3ddmaCtrl.pgen_timing->depth);
	I3DDMA_4xxto4xx_Downsample(i3ddmaCtrl.ptx_timing->color, i3ddmaCtrl.pgen_timing->color);



	switch (i3ddmaCtrl.hw_i3ddma_dma) {

		case I3DDMA_3D_OPMODE_HW_2DONLY_L:
			  I3DDMA_Setup3DDMA(&i3ddmaCtrl, I3DDMA_3D_OPMODE_HW_2DONLY_L);
			  I3DDMA_ForceVODMA2D(1, 1);
		break;
		case I3DDMA_3D_OPMODE_HW_2DONLY_R:
			  I3DDMA_Setup3DDMA(&i3ddmaCtrl, I3DDMA_3D_OPMODE_HW_2DONLY_R);
			  I3DDMA_ForceVODMA2D(1, 0);
		break;
		case I3DDMA_3D_OPMODE_HW:
			  I3DDMA_Setup3DDMA(&i3ddmaCtrl, I3DDMA_3D_OPMODE_HW);
			  I3DDMA_ForceVODMA2D(0, 0);
		break;

		case I3DDMA_3D_OPMODE_DISABLE:
			I3DDMA_Setup3DDMA(&i3ddmaCtrl, I3DDMA_3D_OPMODE_DISABLE);
		break;
		case I3DDMA_3D_OPMODE_HW_NODMA:
			I3DDMA_Setup3DDMA(&i3ddmaCtrl, I3DDMA_3D_OPMODE_HW_NODMA);
		break;
		default:
				pr_debug("unknow HDMI 3D DMA mode\n");
		break;

	}

}

void drvif_I3DDMA_set_3ddma_hwMode(unsigned char enable)
{
	if(enable){
		I3DDMA_Setup3DDMA(&i3ddmaCtrl, I3DDMA_3D_OPMODE_HW);
		I3DDMA_ForceVODMA2D(0, 0);
	}else{
		// Stop HDMI DMA & VO DMA
//		I3DDMA_ResetVODMA4K2K();
		I3DDMA_Setup3DDMA(&i3ddmaCtrl, I3DDMA_3D_OPMODE_DISABLE);
		// wait DMA write done
		msleep(100);
	}
	return;
}




void drvif_I3DDMA_Enable_Vgip(void)
{
	//dma_vgip_ctrl_RBUS dma_vgip_chn1_ctrl_reg;
	dma_vgip_dma_vgip_ctrl_RBUS dma_vgip_chn1_ctrl_reg;

	dma_vgip_chn1_ctrl_reg.regValue = IoReg_Read32(DMA_VGIP_DMA_VGIP_CTRL_reg);
	dma_vgip_chn1_ctrl_reg.dma_ivrun = 1;
	dma_vgip_chn1_ctrl_reg.dma_in_clk_en = 1;
	IoReg_Write32(DMA_VGIP_DMA_VGIP_CTRL_reg, dma_vgip_chn1_ctrl_reg.regValue);

	return;
}



void drvif_I3DDMA_Disable_Vgip(void)
{
	//dma_vgip_ctrl_RBUS dma_vgip_chn1_ctrl_reg;
	dma_vgip_dma_vgip_ctrl_RBUS dma_vgip_chn1_ctrl_reg;

	dma_vgip_chn1_ctrl_reg.regValue = IoReg_Read32(DMA_VGIP_DMA_VGIP_CTRL_reg);
	dma_vgip_chn1_ctrl_reg.dma_ivrun = 0;
	dma_vgip_chn1_ctrl_reg.dma_in_clk_en = 0;
	IoReg_Write32(DMA_VGIP_DMA_VGIP_CTRL_reg, dma_vgip_chn1_ctrl_reg.regValue);

	return;
}

void drvif_I3DDMA_freeze_enable(unsigned char enable)
{
	h3ddma_cap_ctl0_RBUS cap_ctl0_reg;

	cap_ctl0_reg.regValue = IoReg_Read32(H3DDMA_Cap_CTL0_reg);
	if(enable)
		cap_ctl0_reg.freeze_en = 1;
	else
		cap_ctl0_reg.freeze_en = 0;
	IoReg_Write32(H3DDMA_Cap_CTL0_reg, cap_ctl0_reg.regValue);

	return;
}

//extern "C"
//{
extern unsigned int Get_DISP_DEN_STA_HPOS(void);
extern unsigned int Get_DISP_DEN_STA_VPOS(void);
//}
static void I3DDMA_Set_Vgip(unsigned char src, DISPD_CAP_SRC dispD_sel, unsigned char mode)
{
	//dma_vgip_ctrl_RBUS dma_vgip_chn1_ctrl_reg;
	dma_vgip_dma_vgip_ctrl_RBUS dma_vgip_chn1_ctrl_reg;
	//dma_vgip_act_hsta_width_RBUS    dma_vgip_chn1_act_hsta_width_reg;
	dma_vgip_dma_vgip_act_hsta_width_RBUS dma_vgip_chn1_act_hsta_width_reg;
	//dma_vgip_act_vsta_length_RBUS   dma_vgip_chn1_act_vsta_length_reg;
	dma_vgip_dma_vgip_act_vsta_length_RBUS dma_vgip_chn1_act_vsta_length_reg;
	//dma_vgip_delay_RBUS dma_vgip_chn1_delay_reg;
	dma_vgip_dma_vgip_delay_RBUS  dma_vgip_chn1_delay_reg;
	//dma_vgip_cts_fifo_ctl_RBUS 			 	 dma_cts_fifo_ctl_reg;
	dma_vgip_dma_vgip_cts_fifo_ctl_RBUS  dma_cts_fifo_ctl_reg;
	//int dispD_hstaOffset=0;

	dma_vgip_chn1_ctrl_reg.regValue = IoReg_Read32(DMA_VGIP_DMA_VGIP_CTRL_reg);
	dma_vgip_chn1_ctrl_reg.dma_in_clk_en = 0;
	IoReg_Write32(DMA_VGIP_DMA_VGIP_CTRL_reg, dma_vgip_chn1_ctrl_reg.regValue);

	dma_vgip_chn1_ctrl_reg.regValue = IoReg_Read32(DMA_VGIP_DMA_VGIP_CTRL_reg);
	dma_vgip_chn1_ctrl_reg.dma_in_sel = src;
	dma_vgip_chn1_ctrl_reg.dma_digital_mode = mode;

	if(dispD_sel == SCART_OUT_DTV)
		dma_vgip_chn1_ctrl_reg.dma_field_det_en = 0;
	else
		dma_vgip_chn1_ctrl_reg.dma_field_det_en = 1;

	dma_vgip_chn1_ctrl_reg.dma_field_inv = 1;
	IoReg_Write32(DMA_VGIP_DMA_VGIP_CTRL_reg, dma_vgip_chn1_ctrl_reg.regValue);

	dma_vgip_chn1_ctrl_reg.regValue = IoReg_Read32(DMA_VGIP_DMA_VGIP_CTRL_reg);
	dma_vgip_chn1_ctrl_reg.dma_in_clk_en = 1;
	IoReg_Write32(DMA_VGIP_DMA_VGIP_CTRL_reg, dma_vgip_chn1_ctrl_reg.regValue);


	dma_vgip_chn1_ctrl_reg.regValue = IoReg_Read32(DMA_VGIP_DMA_VGIP_CTRL_reg);
	dma_vgip_chn1_ctrl_reg.dma_ivrun = 1;
	IoReg_Write32(DMA_VGIP_DMA_VGIP_CTRL_reg, dma_vgip_chn1_ctrl_reg.regValue);


	dma_vgip_chn1_act_hsta_width_reg.regValue = IoReg_Read32(DMA_VGIP_DMA_VGIP_ACT_HSTA_Width_reg);
	dma_vgip_chn1_act_vsta_length_reg.regValue = IoReg_Read32(DMA_VGIP_DMA_VGIP_ACT_VSTA_Length_reg);

#if 0
	// [FIX-ME] unknown DispD horizontal offset
	switch(dispD_sel){
	  case CAP_SRC_SUBTITLE:
		dispD_hstaOffset = -2;
		break;
	  case CAP_SRC_OSD:
		dispD_hstaOffset = 11;
		break;
	  default:
		break;
	}
#endif

	#ifdef HDMI_4K2K_I3DDMA
	if(Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE) == HDMI_4K2K_TIMING_WIDTH && Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN_PRE) == HDMI_4K2K_TIMING_LENGTH)//for 4k2k
	{
		dma_vgip_chn1_act_hsta_width_reg.dma_ih_act_sta = Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_STA_PRE);
		dma_vgip_chn1_act_hsta_width_reg.dma_ih_act_wid = Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE);
		dma_vgip_chn1_act_vsta_length_reg.dma_iv_act_sta = Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_STA_PRE);
		dma_vgip_chn1_act_vsta_length_reg.dma_iv_act_len= Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN_PRE);
	}
	#endif

	//change this item
	if(dispD_sel == SCART_OUT_DTV){
		dma_vgip_chn1_act_hsta_width_reg.dma_ih_act_sta = Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_STA_PRE);
		dma_vgip_chn1_act_hsta_width_reg.dma_ih_act_wid = Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE);
		dma_vgip_chn1_act_vsta_length_reg.dma_iv_act_sta = Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_STA_PRE);
		if((Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN_PRE) < 288 ) && Scaler_DispGetStatus(SLR_MAIN_DISPLAY, SLR_DISP_THRIP))//SE do scaling up to 720x288 interlace
			dma_vgip_chn1_act_vsta_length_reg.dma_iv_act_len= 288;
		else if((Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN_PRE) < 576)  && !Scaler_DispGetStatus(SLR_MAIN_DISPLAY, SLR_DISP_THRIP))//SE do scaling up to 720x576 prograssive
			dma_vgip_chn1_act_vsta_length_reg.dma_iv_act_len= 576;
		else
			dma_vgip_chn1_act_vsta_length_reg.dma_iv_act_len= Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN_PRE);
		if(Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE) < 720)
			dma_vgip_chn1_act_hsta_width_reg.dma_ih_act_wid = 720;
		else
			dma_vgip_chn1_act_hsta_width_reg.dma_ih_act_wid = Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE);
	}
	else{
		if(dispD_sel == CAP_SRC_SUBTITLE || dispD_sel == CAP_SRC_OSD ||dispD_sel == CAP_SRC_DITHER)
	 	{
	  		pr_debug("[dsip2tve]CAP_SRC_SUBTITLE||CAP_SRC_OSD||CAP_SRC_DITHER..._DISP_WID=%x,_DISP_LEN=%x\n",_DISP_WID,_DISP_LEN);
	  		dma_vgip_chn1_act_hsta_width_reg.dma_ih_act_sta = Get_DISP_DEN_STA_HPOS();// + dispD_hstaOffset;
	  		dma_vgip_chn1_act_hsta_width_reg.dma_ih_act_wid = Get_DISP_ACT_END_HPOS();
	  		dma_vgip_chn1_act_vsta_length_reg.dma_iv_act_sta = Get_DISP_DEN_STA_VPOS();
	  		dma_vgip_chn1_act_vsta_length_reg.dma_iv_act_len= Get_DISP_ACT_END_VPOS();
	 	}
	 		else if(dispD_sel == CAP_SRC_UZU)
			{
				dma_vgip_chn1_act_hsta_width_reg.dma_ih_act_sta = Get_DISP_DEN_STA_HPOS();
			  	dma_vgip_chn1_act_hsta_width_reg.dma_ih_act_wid = Scaler_DispGetInputInfo(SLR_INPUT_DISP_WID);
			  	dma_vgip_chn1_act_vsta_length_reg.dma_iv_act_sta = Get_DISP_DEN_STA_VPOS();
			  	dma_vgip_chn1_act_vsta_length_reg.dma_iv_act_len= Scaler_DispGetInputInfo(SLR_INPUT_DISP_LEN);
			}
	}

	IoReg_Write32(DMA_VGIP_DMA_VGIP_ACT_HSTA_Width_reg, dma_vgip_chn1_act_hsta_width_reg.regValue);
	IoReg_Write32(DMA_VGIP_DMA_VGIP_ACT_VSTA_Length_reg, dma_vgip_chn1_act_vsta_length_reg.regValue);

	// IHS/IVS delay
	dma_vgip_chn1_delay_reg.regValue = IoReg_Read32(DMA_VGIP_DMA_VGIP_DELAY_reg);
	dma_vgip_chn1_delay_reg.dma_ihs_dly = 0;
	dma_vgip_chn1_delay_reg.dma_ivs_dly = 0;
	IoReg_Write32(DMA_VGIP_DMA_VGIP_DELAY_reg, dma_vgip_chn1_delay_reg.regValue);

	dma_cts_fifo_ctl_reg.regValue = IoReg_Read32(DMA_VGIP_DMA_VGIP_CTS_FIFO_CTL_reg);
	dma_cts_fifo_ctl_reg.dma_en_ctsfifo_vsrst_vgip = 1;
	dma_cts_fifo_ctl_reg.dma_force_ctsfifo_rstn_vgip = 1;
	dma_cts_fifo_ctl_reg.dma_force_ctsfifo_rstn_sdnr = 1;
	dma_cts_fifo_ctl_reg.dma_en_ctsfifo_vsrst_sdnr = 0;
	IoReg_Write32(DMA_VGIP_DMA_VGIP_CTS_FIFO_CTL_reg, dma_cts_fifo_ctl_reg.regValue);

	return;
}



static void  drvif_I3DDMA_Set_ViCapture(SIZE outsize)
{
#define CAP_LEN 32
#define CAP_REM 12

	unsigned int num, rem;
//fixed me, remove in mag2 @ Crixus 0305 i3ddma_rgb2yuv_dither_4xxto4xx_hdmi_4xxto4xx_ctrl_RBUS hdmi_4xxto4xx_ctrl_reg;
	//lr_separate_ctrl1_RBUS lr_separate_ctrl1_reg;
	h3ddma_lr_separate_ctrl1_RBUS lr_separate_ctrl1_reg;
	 //cap_ctl1_RBUS cap_ctl1;
	 h3ddma_cap_ctl1_RBUS cap_ctl1_reg;
	 //cap_ctl0_RBUS cap_ctl0;
	 h3ddma_cap_ctl0_RBUS cap_ctl0_reg;

	h3ddma_cap_l1_start_RBUS cap_l1_start_reg;
	h3ddma_cap_l2_start_RBUS cap_l2_start_reg;
	h3ddma_cap_r1_start_RBUS cap_r1_start_reg;
	h3ddma_cap_r2_start_RBUS cap_r2_start_reg;

	h3ddma_tg_v1_end_RBUS tg_v1_end_reg;
	h3ddma_i3ddma_byte_channel_swap_RBUS i3ddma_byte_channel_swap_reg;
	h3ddma_i3ddma_enable_RBUS i3ddma_enable_reg;
	/*if(get_vt_function() == TRUE)
	{
		// alloc capture buffer
		I3DDMA_3DDMAInit_VT();
	} else */{
		I3DDMA_3DDMAInit();
	}

#if 0//fixed me, remove in mag2 @ Crixus 0305
	// 444 to 422 convert in IDMA UZD
	hdmi_4xxto4xx_ctrl_reg.regValue = IoReg_Read32(I3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_4XXTO4XX_CTRL_VADDR);
	hdmi_4xxto4xx_ctrl_reg.yuv_4xxto4xx_sel = 0; //  don't convert
	IoReg_Write32(I3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_4XXTO4XX_CTRL_VADDR, hdmi_4xxto4xx_ctrl_reg.regValue);
#endif
	// IDMA LR separate control
	lr_separate_ctrl1_reg.regValue = IoReg_Read32(H3DDMA_LR_Separate_CTRL1_reg);
	//lr_separate_ctrl1_reg.chess_board_format = 0;
	lr_separate_ctrl1_reg.hdmi_3d_sel = 0;
	lr_separate_ctrl1_reg.vs_inv = 0;
	lr_separate_ctrl1_reg.hs_inv = 0;
	lr_separate_ctrl1_reg.progressive = 1;
	lr_separate_ctrl1_reg.hdmi_3d_structure = 0xa; // frame 2D
	IoReg_Write32(H3DDMA_LR_Separate_CTRL1_reg, lr_separate_ctrl1_reg.regValue);

	// IDMA capture FIFO setting
	num = (outsize.nWidth - CAP_REM) / CAP_LEN;
	rem = ((outsize.nWidth - CAP_REM) % CAP_LEN) + CAP_REM;

	cap_ctl0_reg.regValue = IoReg_Read32(H3DDMA_Cap_CTL0_reg);
	cap_ctl0_reg.triple_buf_en = 0;
	cap_ctl0_reg.quad_buf_en = 0;
	cap_ctl0_reg.freeze_en = 0;
	cap_ctl0_reg.bit_sel = 1; 			// 10bit (display output 10bit)
	cap_ctl0_reg.pixel_encoding = 1; 	// 422 format (VI input format support 420 or 422)
	cap_ctl0_reg.cap_write_len = CAP_LEN;
	cap_ctl0_reg.cap_write_rem = rem;
	IoReg_Write32(H3DDMA_Cap_CTL0_reg, cap_ctl0_reg.regValue);

	cap_ctl1_reg.regValue = IoReg_Read32(H3DDMA_Cap_CTL1_reg);
	cap_ctl1_reg.cap_water_lv = CAP_LEN;
	cap_ctl1_reg.cap_write_num = num;
	IoReg_Write32(H3DDMA_Cap_CTL1_reg, cap_ctl1_reg.regValue);

	i3ddma_byte_channel_swap_reg.regValue = IoReg_Read32(H3DDMA_I3DDMA_byte_channel_swap_reg);
	i3ddma_byte_channel_swap_reg.dma_1byte_swap = 0;
	i3ddma_byte_channel_swap_reg.dma_2byte_swap = 1;
	i3ddma_byte_channel_swap_reg.dma_4byte_swap = 1;
	i3ddma_byte_channel_swap_reg.dma_8byte_swap = 1;
	IoReg_Write32(H3DDMA_I3DDMA_byte_channel_swap_reg, i3ddma_byte_channel_swap_reg.regValue);

	/*if(get_vt_function() == TRUE)
	{
		cap_l1_start_reg.cap_l1_start = (UINT32)i3ddmaCtrl_VT.cap_buffer[0].phyaddr >> 3;
		cap_r1_start_reg.cap_r1_start = (UINT32)i3ddmaCtrl_VT.cap_buffer[0].phyaddr >> 3;
		cap_l2_start_reg.cap_l2_start = (UINT32)i3ddmaCtrl_VT.cap_buffer[1].phyaddr >> 3;
		cap_r2_start_reg.cap_r2_start = (UINT32)i3ddmaCtrl_VT.cap_buffer[1].phyaddr >> 3;
		IoReg_Write32(H3DDMA_Cap_L1_Start_reg,	cap_l1_start_reg.regValue);  // block0, DDR buffer L1 start address
		IoReg_Write32(H3DDMA_Cap_R1_Start_reg,	cap_r1_start_reg.regValue);  // block0, DDR buffer R1 start address
		IoReg_Write32(H3DDMA_Cap_L2_Start_reg,	cap_l2_start_reg.regValue);  // block0, DDR buffer L2 start address
		IoReg_Write32(H3DDMA_Cap_R2_Start_reg,	cap_r2_start_reg.regValue);  // block0, DDR buffer R1 start address
	} else */{
		cap_l1_start_reg.cap_l1_start = (UINT32)i3ddmaCtrl.cap_buffer[0].phyaddr >> 3;
		cap_r1_start_reg.cap_r1_start = (UINT32)i3ddmaCtrl.cap_buffer[0].phyaddr >> 3;
		cap_l2_start_reg.cap_l2_start = (UINT32)i3ddmaCtrl.cap_buffer[1].phyaddr >> 3;
		cap_r2_start_reg.cap_r2_start = (UINT32)i3ddmaCtrl.cap_buffer[1].phyaddr >> 3;
		IoReg_Write32(H3DDMA_Cap_L1_Start_reg,  cap_l1_start_reg.regValue);  // block0, DDR buffer L1 start address
		IoReg_Write32(H3DDMA_Cap_R1_Start_reg,  cap_r1_start_reg.regValue);  // block0, DDR buffer R1 start address
		IoReg_Write32(H3DDMA_Cap_L2_Start_reg,  cap_l2_start_reg.regValue);  // block0, DDR buffer L2 start address
		IoReg_Write32(H3DDMA_Cap_R2_Start_reg,  cap_r2_start_reg.regValue);  // block0, DDR buffer R1 start address
	}


	tg_v1_end_reg.regValue = IoReg_Read32(H3DDMA_TG_v1_end_reg);
	tg_v1_end_reg.pullup_en = 0;
	tg_v1_end_reg.tg_hend1 = 2;
	tg_v1_end_reg.tg_vend1 = 2;
	IoReg_Write32(H3DDMA_TG_v1_end_reg, tg_v1_end_reg.regValue );

	// IDMA timeing gen enable
	i3ddma_enable_reg.regValue = IoReg_Read32(H3DDMA_I3DDMA_enable_reg);
	i3ddma_enable_reg.frc_en = 0;
	i3ddma_enable_reg.lr_separate_en = 1;
	i3ddma_enable_reg.tg_en = 1;
	i3ddma_enable_reg.cap_en = 0; // disable IDMA capture before VI capture enable
	IoReg_Write32(H3DDMA_I3DDMA_enable_reg, i3ddma_enable_reg.regValue );

	return;
}

#if 1

unsigned char drvif_I3DDMA_StartCaptureRpc(int width /* = 720 */, int height /* = 480*/, DISPD_CAP_SRC mode /* = SUB_MIXER */)
{
#ifdef CONFIG_RTK_KDRV_RPC
	unsigned long ret;
#endif

	VIDEO_RPC_CAP_START_CAPTURE *start;
//		unsigned long ret;
	unsigned int  vir_addr, vir_addr_noncache;
	unsigned int  phy_addr;
	vir_addr = (unsigned int)dvr_malloc_uncached_specific(sizeof(VIDEO_RPC_CAP_START_CAPTURE), GFP_DCU1, (void*)&vir_addr_noncache);
	//phy_addr = (unsigned int)virt_to_phys((void*)vir_addr);
	phy_addr = (unsigned int)dvr_to_phys((void*)vir_addr);


	start = (VIDEO_RPC_CAP_START_CAPTURE *)vir_addr_noncache;
	start->instanceID = 0;
	start->instanceID = htonl(start->instanceID);
	start->startMode = mode;
	start->startMode = htonl(start->startMode);
	start->cap_width = width;
	start->cap_width = htonl(start->cap_width);
	start->cap_height = height;
	start->cap_height = htonl(start->cap_height);
#ifdef CONFIG_RTK_KDRV_RPC

	if (send_rpc_command(RPC_VIDEO, VIDEO_RPC_CAP_ToAgent_StartCapture, phy_addr, 0, &ret))
	{
		pr_debug("RPC fail!!\n");
		dvr_free((void*)vir_addr);
		return FALSE;
	}
#endif
	dvr_free((void*)vir_addr);

	return TRUE;
}

unsigned char drvif_I3DDMA_StopCaptureRpc(void)
{
#ifdef CONFIG_RTK_KDRV_RPC
	unsigned long ret;
#endif

	VIDEO_RPC_CAP_STOP_CAPTURE *stop;
//		unsigned long ret;
	unsigned int  vir_addr, vir_addr_noncache;
	unsigned int  phy_addr;
	vir_addr = (unsigned int)dvr_malloc_uncached_specific(sizeof(VIDEO_RPC_CAP_STOP_CAPTURE), GFP_DCU1, (void*)&vir_addr_noncache);
	//phy_addr = (unsigned int)virt_to_phys((void*)vir_addr);
	phy_addr = (unsigned int)dvr_to_phys((void*)vir_addr);

	stop = (VIDEO_RPC_CAP_STOP_CAPTURE *)vir_addr_noncache;
	stop->instanceID = 0;
	stop->instanceID = htonl(stop->instanceID);
#ifdef CONFIG_RTK_KDRV_RPC

	if (send_rpc_command(RPC_VIDEO, VIDEO_RPC_CAP_ToAgent_StopCapture, phy_addr, 0, &ret))
	{
		pr_debug("RPC fail!!\n");
		dvr_free((void*)vir_addr);
		return 1;
	}
#endif
	dvr_free((void*)vir_addr);
	return TRUE;
}

#endif

static void  drvif_I3DDMA_Enable_ViCapture(unsigned char enable, IDMA_DISPD_CAPTURE_INFO *capInfo)
{


	if(enable){
		// Enable VI capture state machine
		pr_debug("[kernel] drvif_I3DDMA_StartCaptureRpcdrvif_I3DDMA_StartCaptureRpc start\n");
		drvif_I3DDMA_StartCaptureRpc(capInfo->capWid, capInfo->capLen, capInfo->capSrc);
		pr_debug("[kernel] drvif_I3DDMA_StartCaptureRpcdrvif_I3DDMA_StartCaptureRpc end\n");
	}else{
		// Disable VI capture state machine
		pr_debug("[kernel] drvif_I3DDMA_StopCaptureRpcdrvif_I3DDMA_StopCaptureRpc start\n");
		drvif_I3DDMA_StopCaptureRpc();
		pr_debug("[kernel] drvif_I3DDMA_StopCaptureRpcdrvif_I3DDMA_StopCaptureRpc end\n");

		/*if(get_vt_function() == TRUE)
		{
			// IDMA timeing gen disable
			i3ddma_enable_RBUS i3ddma_enable_reg;
			i3ddma_enable_reg.regValue = IoReg_Read32(H3DDMA_I3DDMA_enable_reg);
			i3ddma_enable_reg.frc_en = 0;
			i3ddma_enable_reg.lr_separate_en = 0;
			i3ddma_enable_reg.tg_en = 0;
			i3ddma_enable_reg.cap_en = 0; // disable IDMA capture before VI capture enable
			IoReg_Write32(H3DDMA_I3DDMA_enable_reg, i3ddma_enable_reg.regValue );

			// release capture buffer
			I3DDMA_3DDMADeInit_VT();
		} else */{
			I3DDMA_3DDMADeInit();
		}
	}

	return;
}

void drvif_I3DDMA_dispD_to_IdmaVI_idmaConfig(IDMA_DISPD_CAPTURE_INFO capInfo)
{
	//static unsigned char curCapEnable=FALSE;
	SIZE inSize, outSize;

	pr_debug("[IDMA] DispD capture %s\n", (capInfo.enable? "ENABLE": "DISABLE"));
	pr_debug("[IDMA] DispD capture %s\n", (capInfo.enable? "ENABLE": "DISABLE"));
	pr_debug("[IDMA] DispD capture %s\n", (capInfo.enable? "ENABLE": "DISABLE"));
	// IDMA capture enable
	if(capInfo.enable == TRUE){
		//if(curCapEnable == FALSE)
		{
			// IDMA VGIP init
			I3DDMA_Set_Vgip(VGIP_SRC_DISPD, capInfo.capSrc, VGIP_MODE_ANALOG);

			inSize.nWidth = Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_DISP_WID);
			inSize.nLength = Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_DISP_LEN);


			outSize.nWidth = capInfo.capWid;
			outSize.nLength = capInfo.capLen;

			if((outSize.nWidth == 0 ) || (outSize.nLength == 0)){
				outSize.nWidth = inSize.nWidth;
				outSize.nLength = inSize.nLength;
			}
#if 0
			pr_debug("[IVI] Capture Src/H/V=%d/%d/%d\n", capInfo.capSrc, outSize.nWidth, outSize.nLength);
			Scaler_DispSetScaleStatus(SLR_SUB_DISPLAY, SLR_SCALE_H_DOWN, (inSize.nWidth > outSize.nWidth)?true:false);
			Scaler_DispSetScaleStatus(SLR_SUB_DISPLAY, SLR_SCALE_V_DOWN, (inSize.nLength > outSize.nLength)?true:false);
			Scaler_DispSetStatus(SLR_SUB_DISPLAY, SLR_DISP_422CAP, true); 	// VI input support 420/422, so need convert input video to 422 format in UZD
			Scaler_DispSetStatus(SLR_SUB_DISPLAY, SLR_DISP_10BIT, true);
			Scaler_DispSetStatus(SLR_SUB_DISPLAY, SLR_DISP_FSYNC_VUZD, 0x2);
			Scaler_DispSetStatus(SLR_SUB_DISPLAY, SLR_DISP_COMP, false);
#endif
			// IDMA color conversion
			I3DDMA_color_colorspacergb2yuvtransfer(capInfo.capSrc);

			// IDMA scaling down setup
			I3DDMA_ultrazoom_config_scaling_down(&inSize, &outSize, 1);

			// IDMA capture setup
			drvif_I3DDMA_Set_ViCapture(outSize);
		}

		// enable IDMA capture
		drvif_I3DDMA_Enable_ViCapture(TRUE, &capInfo);

		//curCapEnable = TRUE;
	} else{ // IDMA capture disable
		// disable IDMA & release allocated memory
		drvif_I3DDMA_Enable_ViCapture(FALSE, (IDMA_DISPD_CAPTURE_INFO*)NULL);
		// disable DMA VGIP when disable IDMA capture
		drvif_I3DDMA_Disable_Vgip();
		//curCapEnable = FALSE;
	}


	return;
}


void  drvif_I3DDMA_set_capture_for2D(SIZE *outsize)
{
	unsigned int num;
	unsigned int len;
	unsigned int rem;
	unsigned int lineunits;

	 //lr_separate_ctrl1_RBUS lr_separate_ctrl1;
	 h3ddma_lr_separate_ctrl1_RBUS lr_separate_ctrl1;
	 //lr_separate_ctrl2_RBUS lr_separate_ctrl2;
	 h3ddma_lr_separate_ctrl2_RBUS lr_separate_ctrl2;
	 //cap_ctl1_RBUS cap_ctl1;
	 h3ddma_cap_ctl1_RBUS cap_ctl1;
	 //cap_ctl0_RBUS cap_ctl0;
	 h3ddma_cap_ctl0_RBUS cap_ctl0;
	 //tg_v1_end_RBUS tg_v1_end;
	 h3ddma_tg_v1_end_RBUS tg_v1_end;
	 //i3ddma_enable_RBUS i3ddma_enable;
	 h3ddma_i3ddma_enable_RBUS i3ddma_enable;
//	 i3ddma_i3ddma_byte_channel_swap_RBUS  i3ddma_byte_channel_swap;

	I3DDMA_disp2tve_CapBufInit();

	// dispi hdmi_3ddma
	 lr_separate_ctrl1.regValue = IoReg_Read32(H3DDMA_LR_Separate_CTRL1_reg);
	 lr_separate_ctrl1.hdmi_3d_structure = 0x0a;
 	 lr_separate_ctrl1.progressive = 1;
	 lr_separate_ctrl1.hdmi_3d_sel = 0;
 	 IoReg_Write32(H3DDMA_LR_Separate_CTRL1_reg,lr_separate_ctrl1.regValue);

	lr_separate_ctrl2.regValue = IoReg_Read32(H3DDMA_LR_Separate_CTRL2_reg);
	lr_separate_ctrl2.hact = outsize->nWidth;
	lr_separate_ctrl2.vact = outsize->nLength;
       IoReg_Write32(H3DDMA_LR_Separate_CTRL2_reg,lr_separate_ctrl2.regValue);

	//Capture
	//check this item
	pr_debug("[scart out]I3DDMA: 422cap = %d, 8bit=%d\n",Scaler_DispGetStatus(SLR_SUB_DISPLAY,SLR_DISP_422CAP), !Scaler_DispGetStatus(SLR_SUB_DISPLAY,SLR_DISP_10BIT));
	if(Scaler_DispGetStatus(SLR_SUB_DISPLAY,SLR_DISP_422CAP)) //422
		lineunits = (outsize->nWidth * 8 * 2) /128;
	else   //444
		lineunits = (outsize->nWidth * 8 * 3) /128;
	len = 32;
	num = (unsigned int)(lineunits / len);
	rem = (unsigned int)(lineunits % len);

	cap_ctl1.regValue = IoReg_Read32(H3DDMA_Cap_CTL1_reg);
	cap_ctl1.cap_write_num = num;
	cap_ctl1.cap_water_lv = len;
	IoReg_Write32(H3DDMA_Cap_CTL1_reg,cap_ctl1.regValue);

	cap_ctl0.regValue = IoReg_Read32(H3DDMA_Cap_CTL0_reg);
	cap_ctl0.cap_write_rem = rem;
	cap_ctl0.cap_write_len = len;
	cap_ctl0.auto_block_sel_en = 1;
	cap_ctl0.vs_fall_rst_en = 1;
	cap_ctl0.quad_buf_en = 0;

	if (scaler_dispDtoI3ddma_get_enable() == TRUE) {
		cap_ctl0.triple_buf_en= 1;//tve use 3-buffer //scart out use 3-buffer
	} else {
	if(Scaler_DispGetStatus(SLR_MAIN_DISPLAY, SLR_DISP_THRIP))
		cap_ctl0.quad_buf_en= 1;//interlaced use 4-buffer to jump even and odd field
	else
		cap_ctl0.triple_buf_en= 1;//tve use 3-buffer //scart out use 3-buffer
	}

	if(Scaler_DispGetStatus(SLR_SUB_DISPLAY,SLR_DISP_422CAP)) //422
 	{
 		cap_ctl0.pixel_encoding = 1;
		cap_ctl0.bit_sel = 0;
	 }
	 else   //444
 	{
  		cap_ctl0.pixel_encoding = 0;
		cap_ctl0.bit_sel = 0;
 	}

 	IoReg_Write32(H3DDMA_Cap_CTL0_reg,cap_ctl0.regValue);
	// why enable tripple buffer?, reset FIFO address at VS fall, HW auto set memory address, pixel encode 422,
	// length of data to fill in DDR LEN= 32, remaining part REM= 26

	// 2:2 pull up disable, first VS falling edge pixel num = 2, first VS falling edge line num = 2
	 tg_v1_end.regValue = IoReg_Read32(H3DDMA_TG_v1_end_reg);
	 tg_v1_end.tg_vend1= 2;
 	 tg_v1_end.tg_hend1= 2;
	 tg_v1_end.pullup_en = 0;
	 IoReg_Write32(H3DDMA_TG_v1_end_reg,tg_v1_end.regValue);
	// because input is a 2D signal, the value here is important here, just don't be equal to 0?
	  i3ddma_enable.regValue = IoReg_Read32(H3DDMA_I3DDMA_enable_reg);
	 i3ddma_enable.cap_en = 1;
	 i3ddma_enable.lr_separate_en =1;
	 i3ddma_enable.tg_en =1;
	 i3ddma_enable.frc_en = 1;
 	IoReg_Write32(H3DDMA_I3DDMA_enable_reg,i3ddma_enable.regValue);// FRC, timing gen, 3D LR separate, Capture enable

	// 8-byte swap
	IoReg_Mask32(H3DDMA_I3DDMA_byte_channel_swap_reg, ~H3DDMA_I3DDMA_byte_channel_swap_dma_8byte_swap_mask, H3DDMA_I3DDMA_byte_channel_swap_dma_8byte_swap(0x1));

	//scart out use 3-buffer
	IoReg_Write32(H3DDMA_Cap_L1_Start_reg, idma_cap_buf[0].phyaddr);  // block0, DDR buffer L1 start address
	IoReg_Write32(H3DDMA_Cap_L2_Start_reg,  idma_cap_buf[1].phyaddr);  // block1, DDR buffer L2 start address
	IoReg_Write32(H3DDMA_Cap_L3_Start_reg,  idma_cap_buf[2].phyaddr);  // block2, DDR buffer L3 start address
	IoReg_Write32(H3DDMA_Cap_L4_Start_reg,  idma_cap_buf[3].phyaddr);  // block3, DDR buffer L4 start address

}
extern void CVoSqmodeTVERpc(int width , int height , unsigned int framerate);
#if 0//not use
static void  drvif_I3DDMA_Enable_SqCapture(unsigned char enable, IDMA_DISPD_CAPTURE_INFO *capInfo)
{
	i3ddma_i3ddma_enable_RBUS i3ddma_enable_reg;

	if(enable){
		// Enable Sq capture state machine
	/*//[mark by crixus-mac3 linux based]
	if(capInfo->capSrc == CAP_SRC_UZU )
		CVoSqmodeTVERpc(capInfo->capWid, capInfo->capLen, Scaler_DispGetInputInfo(SLR_INPUT_V_FREQ));
	else
		CVoSqmodeTVERpc(capInfo->capWid, capInfo->capLen,600);
	*/
	}else{
		// Disable Sq capture state machine
		//drvif_I3DDMA_StopCaptureRpc();

		// IDMA timeing gen disable
		i3ddma_enable_reg.regValue = IoReg_Read32(I3DDMA_I3DDMA_ENABLE_VADDR);
		i3ddma_enable_reg.frc_en = 0;
		i3ddma_enable_reg.lr_separate_en = 0;
		i3ddma_enable_reg.tg_en = 0;
		i3ddma_enable_reg.cap_en = 0; // disable IDMA capture before VI capture enable
		IoReg_Write32(I3DDMA_I3DDMA_ENABLE_VADDR, i3ddma_enable_reg.regValue );

		// alloc capture buffer
		I3DDMA_3DDMADeInit();
	}

	return;
}


void drvif_I3DDMA_dispDtoI3ddma_TVE(IDMA_DISPD_CAPTURE_INFO capInfo)
{
	SIZE inSize,outSize;
	ppoverlay_display_timing_ctrl2_RBUS display_timing_ctrl2_reg;

// IDMA capture enable
	if(capInfo.enable == TRUE){

		// enable DMA VGIP
		I3DDMA_Set_Vgip(VGIP_SRC_DISPD,capInfo.capSrc, VGIP_MODE_ANALOG);


		inSize.nWidth = Scaler_DispGetInputInfo(SLR_INPUT_DISP_WID);
		inSize.nLength = Scaler_DispGetInputInfo(SLR_INPUT_DISP_LEN);
		if(capInfo.capSrc == CAP_SRC_SUBTITLE ||capInfo.capSrc == CAP_SRC_OSD )
		{
			inSize.nWidth  = Get_DISP_ACT_END_HPOS();
			inSize.nLength = Get_DISP_ACT_END_VPOS();
		}
		outSize.nWidth = capInfo.capWid;
		outSize.nLength = capInfo.capLen;
		if((outSize.nWidth == 0 ) || (outSize.nLength == 0)){
			outSize.nWidth = inSize.nWidth;
			outSize.nLength = inSize.nLength;
		}

		Scaler_DispSetScaleStatus(SLR_SUB_DISPLAY, SLR_SCALE_H_DOWN, (inSize.nWidth > outSize.nWidth)?true:false);
		Scaler_DispSetScaleStatus(SLR_SUB_DISPLAY, SLR_SCALE_V_DOWN, (inSize.nLength > outSize.nLength)?true:false);
		Scaler_DispSetStatus(SLR_SUB_DISPLAY, SLR_DISP_422CAP, true);
		Scaler_DispSetStatus(SLR_SUB_DISPLAY, SLR_DISP_10BIT, false);
		Scaler_DispSetStatus(SLR_SUB_DISPLAY, SLR_DISP_FSYNC_VUZD, 0x2);
		Scaler_DispSetStatus(SLR_SUB_DISPLAY, SLR_DISP_COMP, false);

		// IDMA color conversion
		I3DDMA_color_colorspacergb2yuvtransfer(capInfo.capSrc);

		// IDMA scaling down setup
		I3DDMA_ultrazoom_config_scaling_down(&inSize, &outSize, 1);


		display_timing_ctrl2_reg.regValue = IoReg_Read32(PPOVERLAY_Display_Timing_CTRL2_reg);
		display_timing_ctrl2_reg.frc2fsync_protection = _ENABLE;
		//display_timing_ctrl2_reg.d2i3ddma_en_ctsfifo_vsrst_i3= _ENABLE;
		//display_timing_ctrl2_reg.d2i3ddma_force_ctsfifo_rstn_i3 = _ENABLE;
		display_timing_ctrl2_reg.d2i3ddma_en_ctsfifo_vsrst_i2 =_ENABLE;
		display_timing_ctrl2_reg.d2i3ddma_force_ctsfifo_rstn_i2 = _ENABLE;
		display_timing_ctrl2_reg.d2i3ddma_src_sel = capInfo.capSrc;
		display_timing_ctrl2_reg.repeat_flag_mode = 0x3;
		IoReg_Write32(PPOVERLAY_Display_Timing_CTRL2_reg, display_timing_ctrl2_reg.regValue);

		//IoReg_Mask32(PPOVERLAY_Display_Timing_CTRL2_reg, ~_BIT16, capInfo.capSrc<<16);   //Dispd to i3ddma src sel
		IoReg_Write32(SCALEUP_D_UZU_GLOBLE_CTRL_VADDR, 0x00000032); 	// D-domain to SUB
		IoReg_Write32(SCALEUP_D_UZU_PATGEN_FRAME_TOGGLE_VADDR, 0x000000EF); 	// D-domain Pattern Gen Color-Bar Width
		printk("I3DDMA:src = %d, insize.width = %d, insize.len = %d, outsize.width = %d, outsize.len = %d\n", capInfo.capSrc, inSize.nWidth, inSize.nLength,outSize.nWidth, outSize.nLength);

		// IDMA capture setup
		drvif_I3DDMA_set_capture_for2D(&outSize);

		// enable IDMA capture
		drvif_I3DDMA_Enable_SqCapture(TRUE, &capInfo);

	}
	else{
		// disable DMA VGIP
		drvif_I3DDMA_Disable_Vgip();

		// disable IDMA & release allocated memory
		drvif_I3DDMA_Enable_SqCapture(FALSE, (IDMA_DISPD_CAPTURE_INFO*)NULL);
	}

}
#endif

//#ifdef DTV_SCART_OUT_ENABLE
//static bool bVodma2I3Dma;
extern void  drvif_I3DDMA_set_capture(SIZE *outsize,unsigned char capformat422);
extern void drvif_module_tve_interrupt(int enable);
#if 0
static IDMA_VGIP2_CTRL_INFO imdavgip2CtrlInfo = {(SRC_TYPE)0, 0, 0, {0,0,0,0,0,0}};

unsigned int scaler_vodmatoI3ddma_get_vgip2IhWidth(void)
{
	return imdavgip2CtrlInfo.srcInfo.width;
}

unsigned int scaler_vodmatoI3ddma_get_vgip2IhCount(void)
{
	return imdavgip2CtrlInfo.srcInfo.ihCount;
}

unsigned int scaler_vodmatoI3ddma_get_vgip2IvFreq(void)
{
	return imdavgip2CtrlInfo.srcInfo.frame_rate;
}

unsigned int scaler_vodmatoI3ddma_get_vgip2IvHeight(void)
{
	return imdavgip2CtrlInfo.srcInfo.height;
}

unsigned char scaler_vodmatoI3ddma_get_vgip2SrcFrom(void)
{
	return imdavgip2CtrlInfo.srcFrom;
}

unsigned int scaler_vodmatoI3ddma_get_vgip2SrcInterlaced(void)
{
	return imdavgip2CtrlInfo.srcInfo.interlacedVideo;
}

unsigned char scaler_vodmatoI3ddma_get_vgip2SrcIndex(void)
{
	return imdavgip2CtrlInfo.srcIndex;
}

bool scaler_vodmatoI3ddma_get_vgip2CaptFormat(void)
{
	return imdavgip2CtrlInfo.srcInfo.chroma_422Cap;
}

static void scaler_vodmatoI3ddma_save_vgip1Info(void)
{
	imdavgip2CtrlInfo.srcType				= (SRC_TYPE)Scaler_InputSrcGetMainChType();
	imdavgip2CtrlInfo.srcFrom				= Scaler_InputSrcGetMainChFrom();
	imdavgip2CtrlInfo.srcIndex				= Scaler_DispGetInputInfo(SLR_INPUT_INPUT_SRC);
	imdavgip2CtrlInfo.srcInfo.videoMode		= Scaler_DispGetInputInfo(SLR_INPUT_MODE_CURR);
	imdavgip2CtrlInfo.srcInfo.width			= Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE);
	imdavgip2CtrlInfo.srcInfo.height		= Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN_PRE);
	imdavgip2CtrlInfo.srcInfo.ihCount		= Scaler_DispGetInputInfo(SLR_INPUT_H_LEN);
	imdavgip2CtrlInfo.srcInfo.ihCount_offLine	= Scaler_DispGetInputInfo(SLR_INPUT_H_COUNT);
	imdavgip2CtrlInfo.srcInfo.ivCount		= Scaler_DispGetInputInfo(SLR_INPUT_V_LEN);
	imdavgip2CtrlInfo.srcInfo.chroma_422Cap= Scaler_DispGetStatus((SCALER_DISP_CHANNEL)_CHANNEL1, SLR_DISP_422CAP);
	imdavgip2CtrlInfo.srcInfo.frame_rate		= Scaler_DispGetInputInfo(SLR_INPUT_V_FREQ);
	imdavgip2CtrlInfo.srcInfo.interlacedVideo	= Scaler_DispGetStatus((SCALER_DISP_CHANNEL)_CHANNEL1, SLR_DISP_INTERLACE);

	printk("[vodmatoI3ddma] VGIP1 type/from/Idx/mode, wid/len/Fr[%d/%d/%d/%d, %d/%d/%d]\n",
		imdavgip2CtrlInfo.srcType, imdavgip2CtrlInfo.srcFrom, imdavgip2CtrlInfo.srcIndex, imdavgip2CtrlInfo.srcInfo.videoMode,
		imdavgip2CtrlInfo.srcInfo.width, imdavgip2CtrlInfo.srcInfo.height, imdavgip2CtrlInfo.srcInfo.frame_rate);
}

static void VodmatoI3ddma_Set_Vgip(unsigned char src, unsigned char mode)
{
	dma_vgip_ctrl_RBUS 				dma_vgip_chn1_ctrl_reg;
	dma_vgip_act_hsta_width_RBUS		dma_vgip_chn1_act_hsta_width_reg;
	dma_vgip_act_vsta_length_RBUS   	dma_vgip_chn1_act_vsta_length_reg;
	dma_vgip_cts_fifo_ctl_RBUS					dma_cts_fifo_ctl_reg;

	dma_vgip_chn1_ctrl_reg.regValue = IoReg_Read32(DMA_VGIP_DMA_VGIP_CTRL_reg);
	dma_vgip_chn1_ctrl_reg.dma_in_clk_en = 0;
	IoReg_Write32(DMA_VGIP_DMA_VGIP_CTRL_reg, dma_vgip_chn1_ctrl_reg.regValue);

	dma_vgip_chn1_ctrl_reg.regValue = IoReg_Read32(DMA_VGIP_DMA_VGIP_CTRL_reg);
	dma_vgip_chn1_ctrl_reg.dma_in_sel = src;
	dma_vgip_chn1_ctrl_reg.dma_digital_mode = mode;
	//dma_vgip_chn1_ctrl_reg.dma_odd_det_en = 0;
	//dma_vgip_chn1_ctrl_reg.dma_odd_inv = 1;
	IoReg_Write32(DMA_VGIP_DMA_VGIP_CTRL_reg, dma_vgip_chn1_ctrl_reg.regValue);

	dma_vgip_chn1_ctrl_reg.regValue = IoReg_Read32(DMA_VGIP_DMA_VGIP_CTRL_reg);
	dma_vgip_chn1_ctrl_reg.dma_in_clk_en = 1;
	IoReg_Write32(DMA_VGIP_DMA_VGIP_CTRL_reg, dma_vgip_chn1_ctrl_reg.regValue);


	dma_vgip_chn1_ctrl_reg.regValue = IoReg_Read32(DMA_VGIP_DMA_VGIP_CTRL_reg);
	dma_vgip_chn1_ctrl_reg.dma_ivrun = 1;
	IoReg_Write32(DMA_VGIP_DMA_VGIP_CTRL_reg, dma_vgip_chn1_ctrl_reg.regValue);


	dma_vgip_chn1_act_hsta_width_reg.regValue = IoReg_Read32(DMA_VGIP_DMA_VGIP_ACT_HSTA_Width_reg);
	dma_vgip_chn1_act_vsta_length_reg.regValue = IoReg_Read32(DMA_VGIP_DMA_VGIP_ACT_VSTA_Length_reg);

	dma_vgip_chn1_act_hsta_width_reg.dma_ih_act_sta = Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_STA_PRE);
	dma_vgip_chn1_act_hsta_width_reg.dma_ih_act_wid = Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE);
	dma_vgip_chn1_act_vsta_length_reg.dma_iv_act_sta = Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_STA_PRE);
	dma_vgip_chn1_act_vsta_length_reg.dma_iv_act_len= Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN_PRE);

	IoReg_Write32(DMA_VGIP_DMA_VGIP_ACT_HSTA_Width_reg, dma_vgip_chn1_act_hsta_width_reg.regValue);
	IoReg_Write32(DMA_VGIP_DMA_VGIP_ACT_VSTA_Length_reg, dma_vgip_chn1_act_vsta_length_reg.regValue);

	dma_cts_fifo_ctl_reg.regValue = IoReg_Read32(DMA_VGIP_DMA_VGIP_CTS_FIFO_CTL_reg);
	dma_cts_fifo_ctl_reg.dma_en_ctsfifo_vsrst_vgip = 1;
	dma_cts_fifo_ctl_reg.dma_force_ctsfifo_rstn_vgip = 1;
	dma_cts_fifo_ctl_reg.dma_force_ctsfifo_rstn_sdnr = 1;
	dma_cts_fifo_ctl_reg.dma_en_ctsfifo_vsrst_sdnr = 0;
	IoReg_Write32(DMA_VGIP_DMA_VGIP_CTS_FIFO_CTL_reg, dma_cts_fifo_ctl_reg.regValue);

}
#endif
void scaler_vodmatoI3ddma_vgip2_config(SIZE outsize)
{
	unsigned char nMode;
//	int srcIdx;
	unsigned char source;
	unsigned char mode;
	SIZE insize;

	StructDisplayInfo *info;
	pr_debug("[scart out]###############%s~~1\n",__FUNCTION__);

	// keep the current VGIP1 input source information
	//scaler_vodmatoI3ddma_save_vgip1Info();//this can delete function

	// VGIP2 parameters setup sync from VGIP1
	//scaler_MaincvtSub_config_sync_vgip();
#if 0
	if(Scaler_InputSrcGetMainChType() == _SRC_HDMI)
		source = VGIP_SRC_TMDS;
	else if(Scaler_InputSrcGetMainChType() == _SRC_VO)
		source = VGIP_SRC_VODMA1;
	else
		source = VGIP_SRC_ADC;
#endif

	//LGE WebOS Project - only DTV using
	source = VGIP_SRC_VODMA1;

	mode = VGIP_MODE_ANALOG;

	pr_debug("[scart out]input source = %d\n",source);

	//VodmatoI3ddma_Set_Vgip(source, mode);
	I3DDMA_Set_Vgip(source,SCART_OUT_DTV, mode);

	// VGIP2 color format configure
	info = Scaler_DispGetInfoPtr();
	nMode = (info->IPV_ACT_LEN > 480? 1: 0);

	I3DDMA_ColorSpacergb2yuvtransfer(Scaler_InputSrcGetType(SLR_MAIN_DISPLAY), nMode, 0);

	insize.nWidth = Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE);
	insize.nLength = Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN_PRE);

	//check this item
	if(insize.nWidth < 720){//if width < 720, must be the same with input, else always output 720x576
		outsize.nWidth = 720;//insize.nWidth;
	}

	pr_debug("[scart out]insize.nWidth = %d\n",insize.nWidth);
	pr_debug("[scart out]insize.nLength = %d\n",insize.nLength);
	pr_debug("[scart out]outsize.nWidth = %d\n",outsize.nWidth);
	pr_debug("[scart out]outsize.nLength = %d\n",outsize.nLength);

	if(Scaler_DispGetStatus(SLR_MAIN_DISPLAY, SLR_DISP_THRIP))
	{

		outsize.nLength /=2;
		pr_debug("[scart out]enter DI, nLength = %d\n",outsize.nLength);
		//if(TRUE ==  fwif_scaler_decide_display_cut4line(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY)))// for delete 4 lines (Up 2 line and down 2 line)
		//	insize.nLength = insize.nLength -4;
	}

	Scaler_DispSetScaleStatus(SLR_SUB_DISPLAY, SLR_SCALE_H_DOWN, (insize.nWidth > outsize.nWidth)?true:false);
	Scaler_DispSetScaleStatus(SLR_SUB_DISPLAY, SLR_SCALE_V_DOWN, (insize.nLength > outsize.nLength)?true:false);

	Scaler_DispSetStatus(SLR_SUB_DISPLAY, SLR_DISP_10BIT, false);
	Scaler_DispSetStatus(SLR_SUB_DISPLAY, SLR_DISP_FSYNC_VUZD, 0x2);
	Scaler_DispSetStatus(SLR_SUB_DISPLAY, SLR_DISP_COMP, false);
	Scaler_DispSetStatus(SLR_SUB_DISPLAY, SLR_DISP_422CAP, true);
	I3DDMA_ultrazoom_config_scaling_down(&insize, &outsize, 1);

	drvif_I3DDMA_set_capture_for2D(&outsize);
}

void drvif_i3ddma_vactive_end_irq(int enable)
{
	if(enable)
		IoReg_Mask32(DMA_VGIP_DMA_VGIP_CTRL_reg , ~_BIT25, _BIT25);	//enable VSync end interrupt
	else
		IoReg_Mask32(DMA_VGIP_DMA_VGIP_CTRL_reg , ~_BIT25, 0);	//disable VSync end interrupt
}

void disable_I3DDMA_dispDtoSub(void)
{

	// IDMA timeing gen disable
       IoReg_Mask32(H3DDMA_I3DDMA_enable_reg, ~(H3DDMA_I3DDMA_enable_cap_en_mask|H3DDMA_I3DDMA_enable_lr_separate_en_mask
                               |H3DDMA_I3DDMA_enable_tg_en_mask|H3DDMA_I3DDMA_enable_frc_en_mask), H3DDMA_I3DDMA_enable_cap_en(0)
                               |H3DDMA_I3DDMA_enable_lr_separate_en(0)|H3DDMA_I3DDMA_enable_tg_en(0)
                               |H3DDMA_I3DDMA_enable_frc_en(0));// FRC, timing gen, 3D LR separate, Capture disable

	// release capture buffer
	I3DDMA_disp2tve_CapBufDeInit();

	// disable DMA VGIP when disable IDMA capture
	drvif_I3DDMA_Disable_Vgip();

	//Not to disable DAC power in based driver - LGE Project @ Crixus 20141110
	//drvif_module_tve_AVout_Enable(TVE_AVOUT_DISABLE);

	 drvif_i3ddma_vactive_end_irq(false);

	 drvif_module_tve_interrupt(false);

	 //bVodma2I3Dma = false;
}

UINT8 tve_vflip_en_g = false;
static UINT8 fenable_dispDtoI3ddma;
static UINT8 fScartOut_isr_Enable;
static UINT8 fScartOut_VO_clock_check;
static UINT8 fScartOut_VO_scaling_enable;



unsigned char scaler_dispDtoI3ddma_get_enable(void)
{
	return fenable_dispDtoI3ddma;
}
void scaler_dispDtoI3ddma_set_enable(unsigned char enable)
{
	fenable_dispDtoI3ddma=enable;
}
unsigned char scaler_get_tve_vflip_enable(void)
{
	return tve_vflip_en_g;
}
void scaler_set_tve_vflip_enable(unsigned char enable)
{
	tve_vflip_en_g = enable;
}
unsigned char scaler_scart_out_isr_get_enable(void)
{
	return fScartOut_isr_Enable;
}
void scaler_scart_out_isr_set_enable(unsigned char enable)
{
	fScartOut_isr_Enable=enable;
}

void scaler_vodmatoI3ddma_prog(TVE_VIDEO_MODE_SEL tve_mode, UINT8 tve_vflip_en)
{

	SIZE tve_outsize;
//	UINT32 i3ddmaCapAddr;
	//UINT8 tve_vflip_en = 1;

    	//if (bVodma2I3Dma == true)
    	//{
  	//	return;
    	//}

	if (tve_mode == TVE_NTSC) {
		tve_outsize.nWidth = 720;
		tve_outsize.nLength = 480;
	}
	else if (tve_mode == TVE_PAL_I) {
		tve_outsize.nWidth = 720;
		tve_outsize.nLength = 576;
	} else {
            pr_debug("wrong params  tve_mode=%d\n",(int)tve_mode);
            return ;
       }
	/*not to run dispD to i3ddma path*/
       	scaler_dispDtoI3ddma_set_enable(FALSE);

	disable_I3DDMA_dispDtoSub();
	//msleep(20);//why add this delay?
	scaler_vodmatoI3ddma_vgip2_config(tve_outsize);
	//Not to do initial in based driver - LGE Project @ Crixus 20141110
	//drvif_module_tve_init();
	drvif_module_tve_set_mode(tve_mode);
	drvif_module_tve_video_memory_setting(tve_vflip_en);
	drvif_module_tve_change_memory_setting(Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE),tve_vflip_en);

	//small than 576p should send RPC
	if(Scaler_DispGetStatus(SLR_MAIN_DISPLAY, SLR_DISP_THRIP)){
		scaler_scart_out_isr_set_enable(TRUE);
	}else{
		scaler_scart_out_isr_set_enable(FALSE);
	}
	pr_debug("[scart out]fScartOut_isr_Enable = %x\n",fScartOut_isr_Enable);

	//VODMA clock fine tune
	if((Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE) <= 720) && (Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN_PRE) <= 576)){
		fScartOut_VO_clock_check = TRUE;
		//SE scaling up
		if((Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE) < 720) || (Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN_PRE) < 576))
			fScartOut_VO_scaling_enable = TRUE;
		else
			fScartOut_VO_scaling_enable = FALSE;
	}else{
		fScartOut_VO_clock_check = FALSE;
	}

	scaler_set_tve_vflip_enable(tve_vflip_en);

   	 //bVodma2I3Dma = true;
#if 0//M-disp debug using
	//M-domain Disp verify
	IoReg_ClearBits(MDOMAIN_DISP_DDR_MainSubCtrl_reg,_BIT1); //clear double buffer
	IoReg_ClearBits(MDOMAIN_DISP_DDR_MainCtrl_reg,MDOMAIN_DISP_DDR_MainCtrl_main_double_en_mask); //use single buffer. [9:8] = 0 use buffer 0,
									   // [9:8] = 1 use buffer 1
	i3ddmaCapAddr = IoReg_Read32(I3DDMA_CAP_L1_START_VADDR); //capture Buf L1
	//UINT32 i3ddmaCapAddr = IoReg_Read32(I3DDMA_CAP_L2_START_VADDR); //capture Buf L2
	pr_debug("##### i3ddmaCapAddr : %x ##### \n", i3ddmaCapAddr);  //capture Buf L
	IoReg_Write32(MDOMAIN_DISP_DDR_MainAddr_reg, i3ddmaCapAddr); //M-Disp Buffer0 use capture Buf
#endif
}

void scaler_scart_out_tve_prog(TVE_VIDEO_MODE_SEL mode, UINT32 width){
	pr_debug("[scart out]@@@@@@%s\n",__FUNCTION__);

	//@ Crixus 20141202
	drvif_module_tve_init();
	drvif_module_tve_set_mode(mode);
	drvif_module_tve_video_memory_setting(scaler_get_tve_vflip_enable());
	drvif_module_tve_change_memory_setting(width, scaler_get_tve_vflip_enable());
}

extern void I3DDMA_color_colorspacergb2yuvtransfer_dispDtoI3ddma(IDMA_DISPD_CAPTURE_INFO cap_info);
#define FHD_SIZE_H_WID 1920
#define FHD_SIZE_V_LEN 1080
void scaler_dispDtoI3ddma_prog(TVE_VIDEO_MODE_SEL tve_mode)
{
	UINT16 tve_outsize_width = 0;
	UINT16 tve_outsize_length = 0;
	IDMA_DISPD_CAPTURE_INFO capInfo;
	SIZE inSize,outSize;
	//unsigned char nMode;
	//StructDisplayInfo *info;
	SIZE tve_outsize;
	//display_timing_ctrl2_RBUS display_timing_ctrl2_reg;
	ppoverlay_display_timing_ctrl2_RBUS display_timing_ctrl2_reg;

	pr_debug("[scart out]@@@@@@%s[%d]\n",__FUNCTION__,__LINE__);

	if((tve_mode == TVE_NTSC) || (tve_mode == TVE_PAL_I)){
		if(tve_mode == TVE_NTSC){
			tve_outsize_width = 720;
			tve_outsize_length = 480;
		}
		else if(tve_mode == TVE_PAL_I){
			tve_outsize_width = 720;
			tve_outsize_length = 576;
		}

		tve_outsize.nWidth = tve_outsize_width;
		tve_outsize.nLength = tve_outsize_length;

		capInfo.enable = TRUE;
		capInfo.capSrc = CAP_SRC_UZU;
		capInfo.capMode = CAP_MODE_SEQ;
		capInfo.capFmt = CAP_422;
		capInfo.capWid = tve_outsize_width;
		capInfo.capLen = tve_outsize_length;

		/*enable DMA VGIP*/
		I3DDMA_Set_Vgip(VGIP_SRC_DISPD,capInfo.capSrc, VGIP_MODE_ANALOG);

		inSize.nWidth = Scaler_DispGetInputInfo(SLR_INPUT_DISP_WID);
		inSize.nLength = Scaler_DispGetInputInfo(SLR_INPUT_DISP_LEN);
		outSize.nWidth = tve_outsize_width;
		outSize.nLength = tve_outsize_length;

		pr_debug("[scart out]inSize.nWidth = %d\n", inSize.nWidth);
		pr_debug("[scart out]inSize.nLength = %d\n", inSize.nLength);
		pr_debug("[scart out]outSize.nWidth = %d\n", outSize.nWidth);
		pr_debug("[scart out]outSize.nWidth = %d\n", outSize.nLength);

		if((inSize.nWidth == 0) || (inSize.nLength == 0)){
			pr_debug("[scart out][ERROR]Input size error!! Please call scart out after display is ready!!Not to call early!!\n");
			/*not to run dispD to i3ddma path*/
			scaler_dispDtoI3ddma_set_enable(FALSE);
			return;
		}

		/*enable dispD to i3ddma flag*/
		scaler_dispDtoI3ddma_set_enable(TRUE);
		scaler_set_tve_vflip_enable(Get_PANEL_VFLIP_ENABLE());

		/*use disp-D size 1920x1080 in sirius (CVT project)*/
		/*
		if((inSize.nWidth != FHD_SIZE_H_WID) || (inSize.nLength != FHD_SIZE_V_LEN)){
			inSize.nWidth = FHD_SIZE_H_WID;
			inSize.nLength = FHD_SIZE_V_LEN;
		}
		*/

		Scaler_DispSetScaleStatus(SLR_SUB_DISPLAY, SLR_SCALE_H_DOWN, (inSize.nWidth > outSize.nWidth)?true:false);
		Scaler_DispSetScaleStatus(SLR_SUB_DISPLAY, SLR_SCALE_V_DOWN, (inSize.nLength > outSize.nLength)?true:false);
		Scaler_DispSetStatus(SLR_SUB_DISPLAY, SLR_DISP_422CAP, true);
		Scaler_DispSetStatus(SLR_SUB_DISPLAY, SLR_DISP_10BIT, false);
		Scaler_DispSetStatus(SLR_SUB_DISPLAY, SLR_DISP_FSYNC_VUZD, 0x2);
		Scaler_DispSetStatus(SLR_SUB_DISPLAY, SLR_DISP_COMP, false);

		/*IDMA color conversion*/
		I3DDMA_color_colorspacergb2yuvtransfer_dispDtoI3ddma(capInfo);

		/*IDMA scaling down setup*/
		I3DDMA_ultrazoom_config_scaling_down(&inSize, &outSize, 1);


		display_timing_ctrl2_reg.regValue = IoReg_Read32(PPOVERLAY_Display_Timing_CTRL2_reg);
		display_timing_ctrl2_reg.frc2fsync_protection = _ENABLE;
		/*display_timing_ctrl2_reg.d2i3ddma_en_ctsfifo_vsrst_i3= _ENABLE;*/
		/*display_timing_ctrl2_reg.d2i3ddma_force_ctsfifo_rstn_i3 = _ENABLE;*/
		/*display_timing_ctrl2_reg.d2i3ddma_en_ctsfifo_vsrst_i2 =_ENABLE;*/
		/*display_timing_ctrl2_reg.d2i3ddma_force_ctsfifo_rstn_i2 = _ENABLE;*/
		display_timing_ctrl2_reg.d2i3ddma_src_sel = capInfo.capSrc;
		display_timing_ctrl2_reg.repeat_flag_mode = 0x3;
		IoReg_Write32(PPOVERLAY_Display_Timing_CTRL2_reg, display_timing_ctrl2_reg.regValue);

		/*IDMA capture setup*/
		drvif_I3DDMA_set_capture_for2D(&outSize);

		/*tve process*/
		scaler_scart_out_tve_prog(tve_mode, outSize.nWidth);
	}
       else
       {
            	pr_debug("[scart out]wrong params  tve_mode=%d\n",(int)tve_mode);
	/*not to run dispD to i3ddma path*/
	scaler_dispDtoI3ddma_set_enable(FALSE);
            	return ;
       }
	pr_debug("[scart out]@@@@@@@@@@SCART_OUT_INIT_READY!!\n");
}






//#ifdef DTV_SCART_OUT_ENABLE
static unsigned char vo_se_stretch_scaling_enable=FALSE;
extern unsigned int tve_new_linestep;

unsigned char vo_se_scaling_get_enable(void)
{
	return vo_se_stretch_scaling_enable;
}
void vo_se_scaling_set_enable(unsigned char enable)
{
	vo_se_stretch_scaling_enable=enable;
}

void VO_SE_Scaling(bool enable)
{
#if 0
	SCALER_DISPLAY_WINDOW *display_window;
	//unsigned int *pulTemp = NULL;
	unsigned int ulCount = 0;//, i = 0;
	int ret;

	pr_debug("[scart out]###############%s~~1 \n",__FUNCTION__);

	vo_se_scaling_set_enable(enable);

	display_window = (SCALER_DISPLAY_WINDOW *)Scaler_GetShareMemVirAddr(SCALERIOC_VO_SE_SCALING_ENABLE);
	ulCount = sizeof(SCALER_DISPLAY_WINDOW) / sizeof(unsigned int);

	display_window->outputWidth=720;
    	display_window->outputHeight=576;
	display_window->tve_linestep = tve_new_linestep;
	display_window->vo_scaling_enable = 0;//fScartOut_VO_scaling_enable;
	display_window->vo_scaling_alloc_mem_enable= enable;
	display_window->tve_vflip_en = scaler_get_tve_vflip_enable();
        	display_window->vo_clock_modify = fScartOut_VO_clock_check;
	display_window->scart_isr_enable = scaler_scart_out_isr_get_enable();

	//change endian
	display_window->outputWidth = htonl(display_window->outputWidth);
	display_window->outputHeight = htonl(display_window->outputHeight);
	display_window->tve_linestep = htonl(display_window->tve_linestep);
	display_window->vo_scaling_enable = htonl(display_window->vo_scaling_enable);
	display_window->vo_scaling_alloc_mem_enable = htonl(display_window->vo_scaling_alloc_mem_enable);
	display_window->tve_vflip_en = htonl(display_window->tve_vflip_en);
	display_window->vo_clock_modify = htonl(display_window->vo_clock_modify);
	display_window->scart_isr_enable = htonl(display_window->scart_isr_enable);

	if (0 != (ret = Scaler_SendRPC(SCALERIOC_VO_SE_SCALING_ENABLE,0,0))){
		pr_debug("[scart out]ret=%d, Deinit VO ROTATE fail !!!\n", ret);
	}
#endif
	//tve isr is not ready @ 20140930
	if(Scaler_DispGetStatus(SLR_MAIN_DISPLAY, SLR_DISP_THRIP)){
		drvif_i3ddma_vactive_end_irq(true);
		drvif_module_tve_interrupt(true);
	}
	pr_debug("[scart out]###############%s~~3\n",__FUNCTION__);
}

void vo_se_scaling_ctrl(int enable)
{
    	VO_SE_Scaling(enable);
}

#ifdef CONFIG_DTV_SCART_OUT_ENABLE_444_FORMAT
long Scaler_VO_Set_VoForce422_enable(unsigned char bEnable)
{
	long ret = 0;

	pr_debug("[scart out]###############%s\n",__FUNCTION__);
#ifdef CONFIG_RTK_KDRV_RPC
	if (send_rpc_command(RPC_VIDEO, VIDEO_RPC_VOUT_ToAgent_Force_VO_Chroma_422, bEnable, 0, &ret))
		pr_debug("RPC fail!!\n");
#endif
	return ret;
}
#endif



//#endif

static void I3DDMA_Set_MHL_Vgip(unsigned char src,  unsigned char mode)
{
	//dma_vgip_ctrl_RBUS dma_vgip_chn1_ctrl_reg;
	dma_vgip_dma_vgip_ctrl_RBUS dma_vgip_chn1_ctrl_reg;
	//dma_vgip_act_hsta_width_RBUS    dma_vgip_chn1_act_hsta_width_reg;
	dma_vgip_dma_vgip_act_hsta_width_RBUS dma_vgip_chn1_act_hsta_width_reg;
	//dma_vgip_act_vsta_length_RBUS   dma_vgip_chn1_act_vsta_length_reg;
	dma_vgip_dma_vgip_act_vsta_length_RBUS dma_vgip_chn1_act_vsta_length_reg;
	//dma_vgip_delay_RBUS dma_vgip_chn1_delay_reg;
	dma_vgip_dma_vgip_delay_RBUS  dma_vgip_chn1_delay_reg;
	//dma_vgip_cts_fifo_ctl_RBUS 			 	 dma_cts_fifo_ctl_reg;
	dma_vgip_dma_vgip_cts_fifo_ctl_RBUS  dma_cts_fifo_ctl_reg;
	//int dispD_hstaOffset=0;

	dma_vgip_chn1_ctrl_reg.regValue = IoReg_Read32(DMA_VGIP_DMA_VGIP_CTRL_reg);
	dma_vgip_chn1_ctrl_reg.dma_in_clk_en = 0;
	IoReg_Write32(DMA_VGIP_DMA_VGIP_CTRL_reg, dma_vgip_chn1_ctrl_reg.regValue);

	dma_vgip_chn1_ctrl_reg.regValue = IoReg_Read32(DMA_VGIP_DMA_VGIP_CTRL_reg);
	dma_vgip_chn1_ctrl_reg.dma_in_sel = src;
	dma_vgip_chn1_ctrl_reg.dma_digital_mode = mode;

	dma_vgip_chn1_ctrl_reg.dma_field_det_en = 0;

	dma_vgip_chn1_ctrl_reg.dma_field_inv = 1;
	IoReg_Write32(DMA_VGIP_DMA_VGIP_CTRL_reg, dma_vgip_chn1_ctrl_reg.regValue);

	dma_vgip_chn1_ctrl_reg.regValue = IoReg_Read32(DMA_VGIP_DMA_VGIP_CTRL_reg);
	dma_vgip_chn1_ctrl_reg.dma_in_clk_en = 1;
	IoReg_Write32(DMA_VGIP_DMA_VGIP_CTRL_reg, dma_vgip_chn1_ctrl_reg.regValue);


	dma_vgip_chn1_ctrl_reg.regValue = IoReg_Read32(DMA_VGIP_DMA_VGIP_CTRL_reg);
	dma_vgip_chn1_ctrl_reg.dma_ivrun = 1;
	IoReg_Write32(DMA_VGIP_DMA_VGIP_CTRL_reg, dma_vgip_chn1_ctrl_reg.regValue);


	dma_vgip_chn1_act_hsta_width_reg.regValue = IoReg_Read32(DMA_VGIP_DMA_VGIP_ACT_HSTA_Width_reg);
	dma_vgip_chn1_act_vsta_length_reg.regValue = IoReg_Read32(DMA_VGIP_DMA_VGIP_ACT_VSTA_Length_reg);

	dma_vgip_chn1_act_hsta_width_reg.dma_ih_act_sta = Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_STA_PRE);
	dma_vgip_chn1_act_hsta_width_reg.dma_ih_act_wid = Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE);
	dma_vgip_chn1_act_vsta_length_reg.dma_iv_act_sta = Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_STA_PRE);
	dma_vgip_chn1_act_vsta_length_reg.dma_iv_act_len= Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN_PRE);

	IoReg_Write32(DMA_VGIP_DMA_VGIP_ACT_HSTA_Width_reg, dma_vgip_chn1_act_hsta_width_reg.regValue);
	IoReg_Write32(DMA_VGIP_DMA_VGIP_ACT_VSTA_Length_reg, dma_vgip_chn1_act_vsta_length_reg.regValue);

	// IHS/IVS delay
	dma_vgip_chn1_delay_reg.regValue = IoReg_Read32(DMA_VGIP_DMA_VGIP_DELAY_reg);
	dma_vgip_chn1_delay_reg.dma_ihs_dly = 0;
	dma_vgip_chn1_delay_reg.dma_ivs_dly = 0;
	IoReg_Write32(DMA_VGIP_DMA_VGIP_DELAY_reg, dma_vgip_chn1_delay_reg.regValue);

	dma_cts_fifo_ctl_reg.regValue = IoReg_Read32(DMA_VGIP_DMA_VGIP_CTS_FIFO_CTL_reg);
	dma_cts_fifo_ctl_reg.dma_en_ctsfifo_vsrst_vgip = 1;
	dma_cts_fifo_ctl_reg.dma_force_ctsfifo_rstn_vgip = 1;
	dma_cts_fifo_ctl_reg.dma_force_ctsfifo_rstn_sdnr = 1;
	dma_cts_fifo_ctl_reg.dma_en_ctsfifo_vsrst_sdnr = 0;
	IoReg_Write32(DMA_VGIP_DMA_VGIP_CTS_FIFO_CTL_reg, dma_cts_fifo_ctl_reg.regValue);

	return;
}

unsigned char I3DDMA_MHL_CapBufInit(void) {

	unsigned int size = 1920*1080*4;

	if(idma_cap_buf[0].phyaddr == 0)
	{
			/*Use pli memory allocation @Crixus 20150801*/
			unsigned int malloccacheaddr  = (unsigned int)dvr_malloc_uncached_specific(size*2, GFP_DCU2_FIRST, NULL);

			if (malloccacheaddr == (unsigned int)NULL) {
				pr_debug("malloc idma buffer fail .......................................\n");
				return 1;
			}
			idma_cap_buf[0].size = size;
			idma_cap_buf[0].cache = (void*)(malloccacheaddr);
			idma_cap_buf[0].phyaddr = (unsigned long)dvr_to_phys((void*)idma_cap_buf[0].cache);

			pr_debug("[idma-cap-buf] buf[0]=%x(%d KB), phy(%x) \n", (UINT32)idma_cap_buf[0].cache, idma_cap_buf[0].size >> 10, (UINT32)idma_cap_buf[0].phyaddr);

			idma_cap_buf[1].size = size;
			idma_cap_buf[1].cache = (void*)(malloccacheaddr + size);
			idma_cap_buf[1].phyaddr = (unsigned long)dvr_to_phys((void*)idma_cap_buf[1].cache);
			pr_debug("[idma-cap-buf] buf[1]=%x(%d KB), phy(%x) \n", (UINT32)idma_cap_buf[1].cache, idma_cap_buf[1].size >> 10, (UINT32)idma_cap_buf[1].phyaddr);

			rtd_outl(H3DDMA_Cap_BoundaryAddr2_reg, idma_cap_buf[0].phyaddr );
			rtd_outl(H3DDMA_Cap_BoundaryAddr1_reg, idma_cap_buf[1].phyaddr + idma_cap_buf[1].size);
	}
	return 0;
}

void  drvif_I3DDMA_set_capture_Mhl(SIZE *outsize)
{
	unsigned int num;
	unsigned int len;
	unsigned int rem;
	unsigned int lineunits;

	 //lr_separate_ctrl1_RBUS lr_separate_ctrl1;
	 h3ddma_lr_separate_ctrl1_RBUS lr_separate_ctrl1;
	 //lr_separate_ctrl2_RBUS lr_separate_ctrl2;
	 h3ddma_lr_separate_ctrl2_RBUS lr_separate_ctrl2;
	 //cap_ctl1_RBUS cap_ctl1;
	 h3ddma_cap_ctl1_RBUS cap_ctl1;
	 //cap_ctl0_RBUS cap_ctl0;
	 h3ddma_cap_ctl0_RBUS cap_ctl0;
	 //tg_v1_end_RBUS tg_v1_end;
	 h3ddma_tg_v1_end_RBUS tg_v1_end;
	 //i3ddma_enable_RBUS i3ddma_enable;
	 h3ddma_i3ddma_enable_RBUS i3ddma_enable;
//	 i3ddma_i3ddma_byte_channel_swap_RBUS  i3ddma_byte_channel_swap;

	I3DDMA_MHL_CapBufInit();

	// dispi hdmi_3ddma
	 lr_separate_ctrl1.regValue = IoReg_Read32(H3DDMA_LR_Separate_CTRL1_reg);
	 lr_separate_ctrl1.hdmi_3d_structure = 0x0a;
 	 lr_separate_ctrl1.progressive = 1;
	 lr_separate_ctrl1.hdmi_3d_sel = 0;
 	 IoReg_Write32(H3DDMA_LR_Separate_CTRL1_reg,lr_separate_ctrl1.regValue);

	lr_separate_ctrl2.regValue = IoReg_Read32(H3DDMA_LR_Separate_CTRL2_reg);
	lr_separate_ctrl2.hact = outsize->nWidth;
	lr_separate_ctrl2.vact = outsize->nLength;
       IoReg_Write32(H3DDMA_LR_Separate_CTRL2_reg,lr_separate_ctrl2.regValue);

	//Capture
	//check this item
	//printk("[scart out]I3DDMA: 422cap = %d, 8bit=%d\n",Scaler_DispGetStatus(SLR_SUB_DISPLAY,SLR_DISP_422CAP), !Scaler_DispGetStatus(SLR_SUB_DISPLAY,SLR_DISP_10BIT));
	if(Scaler_DispGetStatus(SLR_SUB_DISPLAY,SLR_DISP_422CAP)) //422
		lineunits = (outsize->nWidth * 8 * 2) /128;
	else   //444
		lineunits = (outsize->nWidth * 8 * 3) /128;
	len = 32;
	num = (unsigned int)(lineunits / len);
	rem = (unsigned int)(lineunits % len);
	if(rem == 0)
	{
		num -= 1;
		rem = 32;
	}

	cap_ctl1.regValue = IoReg_Read32(H3DDMA_Cap_CTL1_reg);
	cap_ctl1.cap_write_num = num;
	cap_ctl1.cap_water_lv = len;
	IoReg_Write32(H3DDMA_Cap_CTL1_reg,cap_ctl1.regValue);

	cap_ctl0.regValue = IoReg_Read32(H3DDMA_Cap_CTL0_reg);
	cap_ctl0.cap_write_rem = rem;
	cap_ctl0.cap_write_len = len;
	cap_ctl0.auto_block_sel_en = 1;
	cap_ctl0.vs_fall_rst_en = 1;
	cap_ctl0.quad_buf_en = 0;

	cap_ctl0.triple_buf_en= 0;

	if(Scaler_DispGetStatus(SLR_SUB_DISPLAY,SLR_DISP_422CAP)) //422
 	{
 		cap_ctl0.pixel_encoding = 1;
		cap_ctl0.bit_sel = 0;
	 }
	 else   //444
 	{
  		cap_ctl0.pixel_encoding = 0;
		cap_ctl0.bit_sel = 0;
 	}

 	IoReg_Write32(H3DDMA_Cap_CTL0_reg,cap_ctl0.regValue);
	// why enable tripple buffer?, reset FIFO address at VS fall, HW auto set memory address, pixel encode 422,
	// length of data to fill in DDR LEN= 32, remaining part REM= 26

	// 2:2 pull up disable, first VS falling edge pixel num = 2, first VS falling edge line num = 2
	 tg_v1_end.regValue = IoReg_Read32(H3DDMA_TG_v1_end_reg);
	 tg_v1_end.tg_vend1= 2;
 	 tg_v1_end.tg_hend1= 2;
	 tg_v1_end.pullup_en = 0;
	 IoReg_Write32(H3DDMA_TG_v1_end_reg,tg_v1_end.regValue);
	// because input is a 2D signal, the value here is important here, just don't be equal to 0?
	  i3ddma_enable.regValue = IoReg_Read32(H3DDMA_I3DDMA_enable_reg);
	 i3ddma_enable.cap_en = 1;
	 i3ddma_enable.lr_separate_en =1;
	 i3ddma_enable.tg_en =1;
	 i3ddma_enable.frc_en = 1;
 	IoReg_Write32(H3DDMA_I3DDMA_enable_reg,i3ddma_enable.regValue);// FRC, timing gen, 3D LR separate, Capture enable

	// 8-byte swap
	//IoReg_Mask32(H3DDMA_I3DDMA_byte_channel_swap_reg, ~H3DDMA_I3DDMA_byte_channel_swap_dma_8byte_swap_mask, H3DDMA_I3DDMA_byte_channel_swap_dma_8byte_swap(0x1));

	//scart out use 3-buffer
	IoReg_Write32(H3DDMA_Cap_L1_Start_reg, idma_cap_buf[0].phyaddr);  // block0, DDR buffer L1 start address
	IoReg_Write32(H3DDMA_Cap_L2_Start_reg,  idma_cap_buf[1].phyaddr);  // block1, DDR buffer L2 start address
	//IoReg_Write32(H3DDMA_Cap_L3_Start_reg,  idma_cap_buf[2].phyaddr);  // block2, DDR buffer L3 start address
	//IoReg_Write32(H3DDMA_Cap_L4_Start_reg,  idma_cap_buf[3].phyaddr);  // block3, DDR buffer L4 start address

}

unsigned char drvif_rpc_confighdmi(void)
{
#ifdef CONFIG_RTK_KDRV_RPC
	unsigned long result = 0;
#endif
	VIDEO_RPC_VOUT_CONFIG_HDMI_3D *config_data;

	//struct page *page = 0;
	//page = alloc_page(GFP_KERNEL);
	//config_datatmp = (VIDEO_RPC_VOUT_SET_3D_MODE *)page_address(page);
	unsigned int vir_addr, vir_addr_noncache;
	unsigned int phy_addr;

	vir_addr = (unsigned int)dvr_malloc_uncached_specific(sizeof(VIDEO_RPC_VOUT_CONFIG_HDMI_3D), GFP_DCU1, (void **)&vir_addr_noncache);
	//phy_addr = (unsigned int)virt_to_phys((void*)vir_addr);
	phy_addr = (unsigned int)dvr_to_phys((void*)vir_addr);

	config_data = (VIDEO_RPC_VOUT_CONFIG_HDMI_3D *)vir_addr_noncache;

	memset(config_data, 0, sizeof(VIDEO_RPC_VOUT_CONFIG_HDMI_3D));
	config_data->width = Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE);
	config_data->height = Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN_PRE);
	config_data->chroma_fmt = VO_CHROMA_YUV422;//(vgip2CtrlInfo.srcInfo.chroma_422Cap? VO_CHROMA_YUV422: VO_CHROMA_YUV444);
	config_data->data_bit_width = 8;
	config_data->framerate =  Scaler_DispGetInputInfo(SLR_INPUT_V_FREQ) * 100;
	config_data->progressive = Scaler_DispGetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY),SLR_DISP_INTERLACE)?0:1;
	config_data->l1_st_adr = rtd_inl(H3DDMA_Cap_L1_Start_reg);
	config_data->r1_st_adr = rtd_inl(H3DDMA_Cap_L1_Start_reg);
	config_data->l2_st_adr = rtd_inl(H3DDMA_Cap_L2_Start_reg);
	config_data->r2_st_adr = rtd_inl(H3DDMA_Cap_L2_Start_reg);
	config_data->hw_auto_mode = 1;
	config_data->quincunx_en = 0;
	config_data->videoPlane = VO_VIDEO_PLANE_V1;

	config_data->width = htonl(config_data->width);
	config_data->height = htonl(config_data->height);
	config_data->chroma_fmt = htonl(config_data->chroma_fmt);
	config_data->data_bit_width = htonl(config_data->data_bit_width);
	config_data->framerate =  htonl(config_data->framerate);
	config_data->progressive = htonl(config_data->progressive);
	config_data->l1_st_adr = htonl(config_data->l1_st_adr);
	config_data->r1_st_adr = htonl(config_data->r1_st_adr);
	config_data->l2_st_adr = htonl(config_data->l2_st_adr);
	config_data->r2_st_adr = htonl(config_data->r2_st_adr);
	config_data->hw_auto_mode = htonl(config_data->hw_auto_mode);
	config_data->quincunx_en = htonl(config_data->quincunx_en);
	config_data->videoPlane = htonl(config_data->videoPlane);

#ifdef CONFIG_RTK_KDRV_RPC
	if (RPC_FAIL==send_rpc_command(RPC_VIDEO, VIDEO_RPC_VOUT_ToAgent_ConfigHDMI_3D,phy_addr, 0, &result))
	{
		pr_debug(KERN_INFO "RPC fail!!\n");
		dvr_free((void *)vir_addr);
		return FALSE;
	}
#endif
	dvr_free((void *)vir_addr);
	return TRUE;
}

void scaler_mhl_i3ddma_config(void)
{
	unsigned char nMode;
	unsigned char source;
	unsigned char mode;
	SIZE insize;
	SIZE outsize;
	StructDisplayInfo *info;

	source = VGIP_SRC_TMDS;
	mode = 0;

	I3DDMA_Set_MHL_Vgip(source, mode);

	// VGIP2 color format configure
	info = Scaler_DispGetInfoPtr();
	nMode = (info->IPV_ACT_LEN > 480? 1: 0);

	insize.nWidth = Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE);
	insize.nLength = Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN_PRE);
	outsize.nWidth = Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE);
	outsize.nLength = Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN_PRE);

	Scaler_DispSetScaleStatus(SLR_SUB_DISPLAY, SLR_SCALE_H_DOWN, (insize.nWidth > outsize.nWidth)?true:false);
	Scaler_DispSetScaleStatus(SLR_SUB_DISPLAY, SLR_SCALE_V_DOWN, (insize.nLength > outsize.nLength)?true:false);

	Scaler_DispSetStatus(SLR_SUB_DISPLAY, SLR_DISP_10BIT, false);
	Scaler_DispSetStatus(SLR_SUB_DISPLAY, SLR_DISP_FSYNC_VUZD, 0x2);
	Scaler_DispSetStatus(SLR_SUB_DISPLAY, SLR_DISP_COMP, false);
	Scaler_DispSetStatus(SLR_SUB_DISPLAY, SLR_DISP_422CAP, true);

//@@@@@@@@@@@@@@@@@@@@@ MUST FIX ME @@@@@@@
/*	if(GET_HDMI_COLOR_SPACE() == COLOR_RGB)
		I3DDMA_ColorSpacergb2yuvtransfer(_SRC_HDMI, nMode, 0);
*/
//@@@@@@@@@@@@@@@@@@@@@ MUST FIX ME @@@@@@@
	I3DDMA_ultrazoom_config_scaling_down(&insize, &outsize, 1);

	drvif_I3DDMA_set_capture_Mhl(&outsize);

	drvif_rpc_confighdmi();
	return;
}

void I3DDMA_Set_HDMI3D_Vgip(void)
{
	//dma_vgip_ctrl_RBUS dma_vgip_chn1_ctrl_reg;
	dma_vgip_dma_vgip_ctrl_RBUS dma_vgip_chn1_ctrl_reg;
	//dma_vgip_act_hsta_width_RBUS    dma_vgip_chn1_act_hsta_width_reg;
	dma_vgip_dma_vgip_act_hsta_width_RBUS dma_vgip_chn1_act_hsta_width_reg;
	//dma_vgip_act_vsta_length_RBUS   dma_vgip_chn1_act_vsta_length_reg;
	dma_vgip_dma_vgip_act_vsta_length_RBUS dma_vgip_chn1_act_vsta_length_reg;
	//dma_vgip_delay_RBUS dma_vgip_chn1_delay_reg;
	dma_vgip_dma_vgip_delay_RBUS  dma_vgip_chn1_delay_reg;
	//dma_vgip_cts_fifo_ctl_RBUS 			 	 dma_cts_fifo_ctl_reg;
	dma_vgip_dma_vgip_cts_fifo_ctl_RBUS  dma_cts_fifo_ctl_reg;
	//int dispD_hstaOffset=0;

	unsigned char mode =VGIP_MODE_ANALOG;
	unsigned char src =VGIP_SRC_TMDS;

	dma_vgip_chn1_ctrl_reg.regValue = IoReg_Read32(DMA_VGIP_DMA_VGIP_CTRL_reg);
	dma_vgip_chn1_ctrl_reg.dma_in_clk_en = 0;
	IoReg_Write32(DMA_VGIP_DMA_VGIP_CTRL_reg, dma_vgip_chn1_ctrl_reg.regValue);

	dma_vgip_chn1_ctrl_reg.regValue = IoReg_Read32(DMA_VGIP_DMA_VGIP_CTRL_reg);
	dma_vgip_chn1_ctrl_reg.dma_in_sel = src;
	dma_vgip_chn1_ctrl_reg.dma_digital_mode = mode;

	dma_vgip_chn1_ctrl_reg.dma_field_det_en = 0;

	dma_vgip_chn1_ctrl_reg.dma_field_inv = 1;
	IoReg_Write32(DMA_VGIP_DMA_VGIP_CTRL_reg, dma_vgip_chn1_ctrl_reg.regValue);

	dma_vgip_chn1_ctrl_reg.regValue = IoReg_Read32(DMA_VGIP_DMA_VGIP_CTRL_reg);
	dma_vgip_chn1_ctrl_reg.dma_in_clk_en = 1;
	IoReg_Write32(DMA_VGIP_DMA_VGIP_CTRL_reg, dma_vgip_chn1_ctrl_reg.regValue);


	dma_vgip_chn1_ctrl_reg.regValue = IoReg_Read32(DMA_VGIP_DMA_VGIP_CTRL_reg);
	dma_vgip_chn1_ctrl_reg.dma_ivrun = 1;
	IoReg_Write32(DMA_VGIP_DMA_VGIP_CTRL_reg, dma_vgip_chn1_ctrl_reg.regValue);

	// enable IDMA VGIP data end interrupt
	if(get_HDMI_HDR_mode() == HDR_DOLBY_HDMI){
		dma_vgip_chn1_ctrl_reg.regValue = IoReg_Read32(DMA_VGIP_DMA_VGIP_CTRL_reg);
		dma_vgip_chn1_ctrl_reg.dma_vact_end_ie= 1;
		IoReg_Write32(DMA_VGIP_DMA_VGIP_CTRL_reg, dma_vgip_chn1_ctrl_reg.regValue);
	}

	dma_vgip_chn1_act_hsta_width_reg.regValue = IoReg_Read32(DMA_VGIP_DMA_VGIP_ACT_HSTA_Width_reg);
	dma_vgip_chn1_act_vsta_length_reg.regValue = IoReg_Read32(DMA_VGIP_DMA_VGIP_ACT_VSTA_Length_reg);

	dma_vgip_chn1_act_hsta_width_reg.dma_ih_act_sta = Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_STA_PRE);
	dma_vgip_chn1_act_hsta_width_reg.dma_ih_act_wid = Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE);
	dma_vgip_chn1_act_vsta_length_reg.dma_iv_act_sta = Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_STA_PRE);
	dma_vgip_chn1_act_vsta_length_reg.dma_iv_act_len= Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN_PRE);

	IoReg_Write32(DMA_VGIP_DMA_VGIP_ACT_HSTA_Width_reg, dma_vgip_chn1_act_hsta_width_reg.regValue);
	IoReg_Write32(DMA_VGIP_DMA_VGIP_ACT_VSTA_Length_reg, dma_vgip_chn1_act_vsta_length_reg.regValue);

	// IHS/IVS delay
	dma_vgip_chn1_delay_reg.regValue = IoReg_Read32(DMA_VGIP_DMA_VGIP_DELAY_reg);
	dma_vgip_chn1_delay_reg.dma_ihs_dly = 0;
	dma_vgip_chn1_delay_reg.dma_ivs_dly = 0;
	IoReg_Write32(DMA_VGIP_DMA_VGIP_DELAY_reg, dma_vgip_chn1_delay_reg.regValue);

	dma_cts_fifo_ctl_reg.regValue = IoReg_Read32(DMA_VGIP_DMA_VGIP_CTS_FIFO_CTL_reg);
	dma_cts_fifo_ctl_reg.dma_en_ctsfifo_vsrst_vgip = 1;
	dma_cts_fifo_ctl_reg.dma_force_ctsfifo_rstn_vgip = 1;
	dma_cts_fifo_ctl_reg.dma_force_ctsfifo_rstn_sdnr = 1;
	dma_cts_fifo_ctl_reg.dma_en_ctsfifo_vsrst_sdnr = 0;
	IoReg_Write32(DMA_VGIP_DMA_VGIP_CTS_FIFO_CTL_reg, dma_cts_fifo_ctl_reg.regValue);

	return;
}


void I3DDMA_Set_Metadata_Vgip(unsigned char enable)
{
	//dma_vgip_ctrl_RBUS dma_vgip_chn1_ctrl_reg;
	dma_vgip_dma_vgip_ctrl_RBUS     dma_vgip_chn1_ctrl_reg;
	//dma_vgip_act_hsta_width_RBUS    dma_vgip_chn1_act_hsta_width_reg;
	dma_vgip_dma_vgip_act_hsta_width_RBUS dma_vgip_chn1_act_hsta_width_reg;
	//dma_vgip_act_vsta_length_RBUS   dma_vgip_chn1_act_vsta_length_reg;
	dma_vgip_dma_vgip_act_vsta_length_RBUS dma_vgip_chn1_act_vsta_length_reg;
	//dma_vgip_delay_RBUS dma_vgip_chn1_delay_reg;
	dma_vgip_dma_vgip_delay_RBUS  dma_vgip_chn1_delay_reg;
	//dma_vgip_cts_fifo_ctl_RBUS 			 	 dma_cts_fifo_ctl_reg;
	dma_vgip_dma_vgip_cts_fifo_ctl_RBUS  dma_cts_fifo_ctl_reg;
	//int dispD_hstaOffset=0;

	unsigned char mode =VGIP_MODE_ANALOG;
	unsigned char src =VGIP_SRC_TMDS;

	dma_vgip_chn1_ctrl_reg.regValue = IoReg_Read32(DMA_VGIP_DMA_VGIP_CTRL_reg);
	dma_vgip_chn1_ctrl_reg.dma_in_clk_en = 0;
	IoReg_Write32(DMA_VGIP_DMA_VGIP_CTRL_reg, dma_vgip_chn1_ctrl_reg.regValue);

	dma_vgip_chn1_ctrl_reg.regValue = IoReg_Read32(DMA_VGIP_DMA_VGIP_CTRL_reg);
	dma_vgip_chn1_ctrl_reg.dma_in_sel = src;
	dma_vgip_chn1_ctrl_reg.dma_digital_mode = mode;

	dma_vgip_chn1_ctrl_reg.dma_field_det_en = 0;

	dma_vgip_chn1_ctrl_reg.dma_field_inv = 1;
	IoReg_Write32(DMA_VGIP_DMA_VGIP_CTRL_reg, dma_vgip_chn1_ctrl_reg.regValue);

	dma_vgip_chn1_ctrl_reg.regValue = IoReg_Read32(DMA_VGIP_DMA_VGIP_CTRL_reg);
	dma_vgip_chn1_ctrl_reg.dma_in_clk_en = 1;
	IoReg_Write32(DMA_VGIP_DMA_VGIP_CTRL_reg, dma_vgip_chn1_ctrl_reg.regValue);


	dma_vgip_chn1_ctrl_reg.regValue = IoReg_Read32(DMA_VGIP_DMA_VGIP_CTRL_reg);
	dma_vgip_chn1_ctrl_reg.dma_ivrun = 1;
	IoReg_Write32(DMA_VGIP_DMA_VGIP_CTRL_reg, dma_vgip_chn1_ctrl_reg.regValue);

	// enable IDMA VGIP data end interrupt
	if(get_HDMI_HDR_mode() == HDR_DOLBY_HDMI){
		dma_vgip_chn1_ctrl_reg.regValue = IoReg_Read32(DMA_VGIP_DMA_VGIP_CTRL_reg);
		dma_vgip_chn1_ctrl_reg.dma_vact_end_ie= 1;
		IoReg_Write32(DMA_VGIP_DMA_VGIP_CTRL_reg, dma_vgip_chn1_ctrl_reg.regValue);
	}

	dma_vgip_chn1_act_hsta_width_reg.regValue = IoReg_Read32(DMA_VGIP_DMA_VGIP_ACT_HSTA_Width_reg);
	dma_vgip_chn1_act_vsta_length_reg.regValue = IoReg_Read32(DMA_VGIP_DMA_VGIP_ACT_VSTA_Length_reg);
//@@@@@@@MUST FIX ME@@@@@@@@@@@@@@@@@@@
	//dma_vgip_chn1_act_hsta_width_reg.dma_ih_act_sta = GET_MODE_IHSTA();//Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_STA_PRE);
	//dma_vgip_chn1_act_hsta_width_reg.dma_ih_act_wid = GET_MODE_IHWIDTH();//Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE);
	//dma_vgip_chn1_act_vsta_length_reg.dma_iv_act_sta = GET_MODE_IVSTA();//Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_STA_PRE);
	//dma_vgip_chn1_act_vsta_length_reg.dma_iv_act_len= GET_MODE_IVHEIGHT();//Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN_PRE);

	//IoReg_Write32(DMA_VGIP_DMA_VGIP_ACT_HSTA_Width_reg, dma_vgip_chn1_act_hsta_width_reg.regValue);
	//IoReg_Write32(DMA_VGIP_DMA_VGIP_ACT_VSTA_Length_reg, dma_vgip_chn1_act_vsta_length_reg.regValue);
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	// IHS/IVS delay
	dma_vgip_chn1_delay_reg.regValue = IoReg_Read32(DMA_VGIP_DMA_VGIP_DELAY_reg);
	dma_vgip_chn1_delay_reg.dma_ihs_dly = 0;
	dma_vgip_chn1_delay_reg.dma_ivs_dly = 0;
	IoReg_Write32(DMA_VGIP_DMA_VGIP_DELAY_reg, dma_vgip_chn1_delay_reg.regValue);

	dma_cts_fifo_ctl_reg.regValue = IoReg_Read32(DMA_VGIP_DMA_VGIP_CTS_FIFO_CTL_reg);
	dma_cts_fifo_ctl_reg.dma_en_ctsfifo_vsrst_vgip = 1;
	dma_cts_fifo_ctl_reg.dma_force_ctsfifo_rstn_vgip = 1;
	dma_cts_fifo_ctl_reg.dma_force_ctsfifo_rstn_sdnr = 1;
	dma_cts_fifo_ctl_reg.dma_en_ctsfifo_vsrst_sdnr = 0;
	IoReg_Write32(DMA_VGIP_DMA_VGIP_CTS_FIFO_CTL_reg, dma_cts_fifo_ctl_reg.regValue);

	return;
}

void I3DDMA_Parse_HDMI3D_pattern(void)
{
       unsigned char nMode;
       SIZE insize;
       SIZE outsize;
       StructDisplayInfo *info;

       I3DDMA_Set_HDMI3D_Vgip();

       // VGIP2 color format configure
       info = Scaler_DispGetInfoPtr();
       nMode = (info->IPV_ACT_LEN > 480? 1: 0);

       insize.nWidth = Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE);
       insize.nLength = Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN_PRE);
       outsize.nWidth = Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE);
       outsize.nLength = Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN_PRE);

       Scaler_DispSetScaleStatus(SLR_SUB_DISPLAY, SLR_SCALE_H_DOWN, (insize.nWidth > outsize.nWidth)?true:false);
       Scaler_DispSetScaleStatus(SLR_SUB_DISPLAY, SLR_SCALE_V_DOWN, (insize.nLength > outsize.nLength)?true:false);

       Scaler_DispSetStatus(SLR_SUB_DISPLAY, SLR_DISP_10BIT, false);
       Scaler_DispSetStatus(SLR_SUB_DISPLAY, SLR_DISP_FSYNC_VUZD, 0x2);
       Scaler_DispSetStatus(SLR_SUB_DISPLAY, SLR_DISP_COMP, false);
       Scaler_DispSetStatus(SLR_SUB_DISPLAY, SLR_DISP_422CAP, true);

//@@@@@@@@@@@@@@@@@@@@@ MUST FIX ME @@@@@@@
/*       if(GET_HDMI_COLOR_SPACE() == COLOR_RGB)
               I3DDMA_ColorSpacergb2yuvtransfer(_SRC_HDMI, nMode, 0);
   */
//@@@@@@@@@@@@@@@@@@@@@ MUST FIX ME @@@@@@@

       I3DDMA_ultrazoom_config_scaling_down(&insize, &outsize, 1);

       drvif_I3DDMA_set_capture_Mhl(&outsize);

       return;
}

#ifdef CONFIG_FORCE_RUN_I3DDMA
void fw_i3ddma_set_vgip(unsigned char src, unsigned char mode)
{
	dma_vgip_dma_vgip_ctrl_RBUS dma_vgip_chn1_ctrl_reg;
	dma_vgip_dma_vgip_act_hsta_width_RBUS    dma_vgip_chn1_act_hsta_width_reg;
	dma_vgip_dma_vgip_act_vsta_length_RBUS   dma_vgip_chn1_act_vsta_length_reg;
	dma_vgip_dma_vgip_delay_RBUS dma_vgip_chn1_delay_reg;
	dma_vgip_dma_vgip_cts_fifo_ctl_RBUS 			 	 dma_cts_fifo_ctl_reg;
	dma_vgip_dma_vgip_misc_RBUS dma_vgip_dma_vgip_misc_reg;
	//int dispD_hstaOffset=0;
	RBus_UInt32 u32_cal_ivs_dly= 2;	// according liyu chen suggestion for Mac5 20170103

	StructDisplayInfo *p_dispinfo;
	p_dispinfo = Get_ADC_Dispinfo();

	if(p_dispinfo ==NULL){
		printk(KERN_ERR "#####[%s(%d)] error must connect ADC!!!", __FUNCTION__, __LINE__);
		return ;
	}

	dma_vgip_chn1_ctrl_reg.regValue = IoReg_Read32(DMA_VGIP_DMA_VGIP_CTRL_reg);
	dma_vgip_chn1_ctrl_reg.dma_in_clk_en = 0;
	IoReg_Write32(DMA_VGIP_DMA_VGIP_CTRL_reg, dma_vgip_chn1_ctrl_reg.regValue);

	dma_vgip_chn1_ctrl_reg.regValue = IoReg_Read32(DMA_VGIP_DMA_VGIP_CTRL_reg);
	dma_vgip_chn1_ctrl_reg.dma_in_sel = src;
	dma_vgip_chn1_ctrl_reg.dma_digital_mode = mode;

	//modify the field setting by liyu chen suggestion
	if ((Get_DisplayMode_Src(SLR_MAIN_DISPLAY) == VSC_INPUTSRC_ADC) && (get_ADC_Input_Source() == _SRC_VGA) && Scaler_DispGetStatus(SLR_MAIN_DISPLAY, SLR_DISP_INTERLACE))
		dma_vgip_chn1_ctrl_reg.dma_field_det_en = 1; //bit16
	else
		dma_vgip_chn1_ctrl_reg.dma_field_det_en = 0; //bit16
		
	dma_vgip_chn1_ctrl_reg.dma_field_sync_edge = 0;	//bit17	// according liyu chen suggestion for Mac5 20170103
	dma_vgip_chn1_ctrl_reg.dma_field_inv = 0;		//bit18


	IoReg_Write32(DMA_VGIP_DMA_VGIP_CTRL_reg, dma_vgip_chn1_ctrl_reg.regValue);

	dma_vgip_chn1_ctrl_reg.regValue = IoReg_Read32(DMA_VGIP_DMA_VGIP_CTRL_reg);
	dma_vgip_chn1_ctrl_reg.dma_in_clk_en = 1;
	IoReg_Write32(DMA_VGIP_DMA_VGIP_CTRL_reg, dma_vgip_chn1_ctrl_reg.regValue);


	dma_vgip_chn1_ctrl_reg.regValue = IoReg_Read32(DMA_VGIP_DMA_VGIP_CTRL_reg);
	dma_vgip_chn1_ctrl_reg.dma_ivrun = 1;
	IoReg_Write32(DMA_VGIP_DMA_VGIP_CTRL_reg, dma_vgip_chn1_ctrl_reg.regValue);

	// enable IDMA VGIP data end interrupt
	if(get_HDMI_HDR_mode() == HDR_DOLBY_HDMI){
		dma_vgip_chn1_ctrl_reg.regValue = IoReg_Read32(DMA_VGIP_DMA_VGIP_CTRL_reg);
		dma_vgip_chn1_ctrl_reg.dma_vact_end_ie= 1;
		IoReg_Write32(DMA_VGIP_DMA_VGIP_CTRL_reg, dma_vgip_chn1_ctrl_reg.regValue);
	}

	dma_vgip_chn1_act_hsta_width_reg.regValue = IoReg_Read32(DMA_VGIP_DMA_VGIP_ACT_HSTA_Width_reg);
	dma_vgip_chn1_act_vsta_length_reg.regValue = IoReg_Read32(DMA_VGIP_DMA_VGIP_ACT_VSTA_Length_reg);
	dma_vgip_chn1_act_hsta_width_reg.dma_ih_act_sta = (mode == VGIP_MODE_ANALOG) ? Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPH_ACT_STA_PRE) : 0;
	dma_vgip_chn1_act_hsta_width_reg.dma_ih_act_wid = Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPH_ACT_WID_PRE);
	dma_vgip_dma_vgip_misc_reg.regValue = IoReg_Read32(DMA_VGIP_DMA_VGIP_MISC_reg);
	if(dma_vgip_chn1_ctrl_reg.dma_digital_mode == 0)
	{
		if(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPV_ACT_STA_PRE)>=u32_cal_ivs_dly)	// according liyu chen suggestion
		{
			dma_vgip_chn1_act_vsta_length_reg.dma_iv_act_sta= Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPV_ACT_STA_PRE)-u32_cal_ivs_dly;
		}
		else
		{
			dma_vgip_chn1_act_vsta_length_reg.dma_iv_act_sta= Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPV_ACT_STA_PRE);
			rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "Warning: i3ddma active start(%d) is smaller than %d\n", dma_vgip_chn1_act_vsta_length_reg.dma_iv_act_sta, u32_cal_ivs_dly);
		}
		dma_vgip_dma_vgip_misc_reg.dma_hporch_num = 0;
	}else {//digital mode vstart need to be 0
		dma_vgip_chn1_act_vsta_length_reg.dma_iv_act_sta = 0;
		dma_vgip_dma_vgip_misc_reg.dma_hporch_num = Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPH_ACT_STA_PRE);	//digital mode need h proch number		
    }
	dma_vgip_chn1_act_vsta_length_reg.dma_iv_act_len= Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPV_ACT_LEN_PRE);

	//v start lenght keeps no change, if digital mode.	

	dma_vgip_dma_vgip_misc_reg.dma_vs_dly_1hs = 1;// ECN-221

	IoReg_Write32(DMA_VGIP_DMA_VGIP_ACT_HSTA_Width_reg, dma_vgip_chn1_act_hsta_width_reg.regValue);
	IoReg_Write32(DMA_VGIP_DMA_VGIP_ACT_VSTA_Length_reg, dma_vgip_chn1_act_vsta_length_reg.regValue);
	IoReg_Write32(DMA_VGIP_DMA_VGIP_MISC_reg, dma_vgip_dma_vgip_misc_reg.regValue);

	// IHS/IVS delay
	dma_vgip_chn1_delay_reg.regValue = IoReg_Read32(DMA_VGIP_DMA_VGIP_DELAY_reg);
	if((Get_DisplayMode_Src(SLR_MAIN_DISPLAY) == VSC_INPUTSRC_ADC) && (get_ADC_Input_Source() == _SRC_VGA))
		dma_vgip_chn1_delay_reg.dma_ihs_dly = FIX_VGIP_H_DELAY;
	else
		dma_vgip_chn1_delay_reg.dma_ihs_dly = 0;
	dma_vgip_chn1_delay_reg.dma_ivs_dly = u32_cal_ivs_dly;	// according liyu chen suggestion
	IoReg_Write32(DMA_VGIP_DMA_VGIP_DELAY_reg, dma_vgip_chn1_delay_reg.regValue);

	if(src == VGIP_SRC_ATV)
	{
		dma_vgip_chn1_delay_reg.regValue = IoReg_Read32(DMA_VGIP_DMA_VGIP_DELAY_reg);
		if(VD_27M_OFF != fw_video_get_27mhz_mode((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY)))
		{
			dma_vgip_chn1_delay_reg.dma_ihs_dly = _H_POSITION_MOVE_TOLERANCE * 2;
		}
		else
		{
			dma_vgip_chn1_delay_reg.dma_ihs_dly = _H_POSITION_MOVE_TOLERANCE;
		}
		IoReg_Write32(DMA_VGIP_DMA_VGIP_DELAY_reg, dma_vgip_chn1_delay_reg.regValue);

		dma_vgip_chn1_act_hsta_width_reg.regValue = IoReg_Read32(DMA_VGIP_DMA_VGIP_ACT_HSTA_Width_reg);
		dma_vgip_chn1_act_hsta_width_reg.dma_ih_act_sta = dma_vgip_chn1_act_hsta_width_reg.dma_ih_act_sta - dma_vgip_chn1_delay_reg.dma_ihs_dly;
		IoReg_Write32(DMA_VGIP_DMA_VGIP_ACT_HSTA_Width_reg, dma_vgip_chn1_act_hsta_width_reg.regValue);
	}

	if ((Get_DisplayMode_Src(SLR_MAIN_DISPLAY) == VSC_INPUTSRC_ADC) && (get_ADC_Input_Source() == _SRC_VGA)){
		Scaler_SetHPosition(Scaler_GetHPosition());
		Scaler_SetVPosition(Scaler_GetVPosition());
/*		
		dma_vgip_chn1_act_hsta_width_reg.regValue = IoReg_Read32(DMA_VGIP_DMA_VGIP_ACT_HSTA_Width_reg);
		dma_vgip_chn1_act_hsta_width_reg.dma_ih_act_sta = p_dispinfo->IPH_ACT_STA + (0x32-Scaler_GetHPosition());
		IoReg_Write32(DMA_VGIP_DMA_VGIP_ACT_HSTA_Width_reg, dma_vgip_chn1_act_hsta_width_reg.regValue);

		dma_vgip_chn1_delay_reg.regValue = IoReg_Read32(DMA_VGIP_DMA_VGIP_DELAY_reg);
		dma_vgip_chn1_act_vsta_length_reg.regValue = IoReg_Read32(DMA_VGIP_DMA_VGIP_ACT_VSTA_Length_reg);
		dma_vgip_chn1_act_vsta_length_reg.dma_iv_act_sta = p_dispinfo->IPV_ACT_STA + (0x32-Scaler_GetVPosition()) - dma_vgip_chn1_delay_reg.dma_ivs_dly;
		IoReg_Write32(DMA_VGIP_DMA_VGIP_ACT_VSTA_Length_reg, dma_vgip_chn1_act_vsta_length_reg.regValue);
*/
	}

	dma_cts_fifo_ctl_reg.regValue = IoReg_Read32(DMA_VGIP_DMA_VGIP_CTS_FIFO_CTL_reg);
	dma_cts_fifo_ctl_reg.dma_en_ctsfifo_vsrst_vgip = 1;
	dma_cts_fifo_ctl_reg.dma_force_ctsfifo_rstn_vgip = 1;
	dma_cts_fifo_ctl_reg.dma_force_ctsfifo_rstn_sdnr = 1;
	dma_cts_fifo_ctl_reg.dma_en_ctsfifo_vsrst_sdnr = 0;
	IoReg_Write32(DMA_VGIP_DMA_VGIP_CTS_FIFO_CTL_reg, dma_cts_fifo_ctl_reg.regValue);

	return;
}
#endif

