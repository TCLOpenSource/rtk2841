/*==========================================================================
  * Copyright (c)      Realtek Semiconductor Corporation, 2006
  * All rights reserved.
  * ========================================================================*/

/*================= File Description =======================================*/
/**
 * @file
 * 	This file is for color related functions.
 *
 * @author 	$Author$
 * @date 	$Date$
 * @version 	$Revision$
 */

/**
 * @addtogroup color
 * @{
 */


#if CONFIG_FIRMWARE_IN_KERNEL
/*============================ Module dependency  ===========================*/
#include <linux/string.h>
#include <linux/hrtimer.h>
#include <linux/semaphore.h>
//#include <mach/io.h>
#include <tvscalercontrol/io/ioregdrv.h>
#include <rbus/sb2_reg.h>
#include <tvscalercontrol/scaler/scalerstruct.h>
#include <tvscalercontrol/scaler/scalercolorlib.h>
#include <tvscalercontrol/scaler/source.h>
#include <tvscalercontrol/scalerdrv/mode.h>
#include <tvscalercontrol/vip/vip_reg_def.h>
#include <tvscalercontrol/vip/color.h>
#include <tvscalercontrol/vip/peaking.h>
#include <tvscalercontrol/vip/nr.h>
#include <tvscalercontrol/hdmirx/hdmifun.h>
#include <tvscalercontrol/scalerdrv/scalerdrv.h>
#include <scalercommon/scalerCommon.h>
#include <tvscalercontrol/vip/gibi_od.h>
#include <tvscalercontrol/vip/scalerColor.h>
#include <tvscalercontrol/panel/panelapi.h>
#include <tvscalercontrol/scalerdrv/scalerdisplay.h>
//#include "rbus/dtg_reg.h"
#include <rbus/ppoverlay_reg.h>
#include "rbus/vdtop_reg.h"
#include <rbus/dm_reg.h>
#include <rbus/dolby_v_top_reg.h>
#include <rbus/dhdr_v_composer_reg.h>
#include <rbus/vodma_reg.h>
//#include <rbus/rbusMain_DitherReg.h>
#include <rbus/h3ddma_rgb2yuv_dither_4xxto4xx_reg.h>
#include <rbus/h3ddma_hsd_reg.h>
#include <tvscalercontrol/vdc/video.h>
#include <rtk_kdriver/rtk_crt.h>
#include <rbus/sys_reg_reg.h>
#include <mach/rtk_log.h>
#define TAG_NAME "VPQ"
#include <tvscalercontrol/scaler_vscdev.h>	//for uc4_get_main_dispwin_value


#include <rbus/sys_reg_reg.h> /*jyyang 20160624*/
#include <rbus/memc_mux_reg.h>
#include <tvscalercontrol/scalerdrv/scaler_i2rnd.h>
#include <rbus/dmato3dtable_reg.h>
#include <rbus/timer_reg.h>

// for register dump
#include <tvscalercontrol/io/ioregdrv.h>
#undef rtd_outl
#define rtd_outl(x, y)     								IoReg_Write32(x,y)
#undef rtd_inl
#define rtd_inl(x)     									IoReg_Read32(x)
#undef rtd_maskl
#define rtd_maskl(x, y, z)     							IoReg_Mask32(x,y,z)
#undef rtd_setbits
#define rtd_setbits(offset, Mask) rtd_outl(offset, (rtd_inl(offset) | Mask))
#undef rtd_clearbits
#define rtd_clearbits(offset, Mask) rtd_outl(offset, ((rtd_inl(offset) & ~(Mask))))

#else
#include <linux/semaphore.h>
#include <unistd.h>			// 'close()'
#include <fcntl.h>			// 'open()'
#include <stdio.h>
#include <sys/ioctl.h>

//#include "rtd_regs.h"
//#include <Rtd_types.h>
//#include <rbusRgb2yuvReg.h>
//#include <rbusYuv2rgbReg.h>
//#include <rbusPpOverlayReg.h>
//#include <rbusDitherReg.h>
//#include <rbusCon_briReg.h>
//#include <rbusColorReg.h>
//#include <rbusColor_dlctiReg.h>
//#include <rbusHDMIReg.h>
//#include <rbusSRGBReg.h>
//#include <rbusDFILTERReg.h>
//#include <rbusHdmi_ditherReg.h>
//#include <rbusSD_DitherReg.h>
//#include <dtg_reg.h>
#include <Platform_Lib/TVScalerControl/io/ioRegDrv.h>
#include <Platform_Lib/TVScalerControl/vip/sb2_reg.h>

//#include <Application/AppClass/TvControl/Utils/RtSystem.h>
#include <Platform_Lib/TVScalerControl/scaler/scalerStruct.h>
#include <Platform_Lib/TVScalerControl/scaler/scalerLib.h>
#include <Platform_Lib/TVScalerControl/scaler/scalerColorLib.h>

#include <Platform_Lib/TVScalerControl/scaler/source.h>
#include <Platform_Lib/TVScalerControl/scalerDrv/mode.h>
#include <Platform_Lib/TVScalerControl/vip/VIP_reg_def.h>
#include <Platform_Lib/TVScalerControl/vip/color.h>
#include <Platform_Lib/TVScalerControl/vip/peaking.h>
#include <Platform_Lib/TVScalerControl/vip/nr.h>
#include <Platform_Lib/TVScalerControl/hdmiRx/hdmiFun.h>
#include <Platform_Lib/TVScalerControl/scalerDrv/scalerDrv.h>
//#include <Platform_Lib/TVScalerControl/scalerCommon.h>
#include <scaler/scalerCommon.h>
#include <Application/AppClass/SetupClass.h>

#include <Platform_Lib/TVScalerControl/vip/gibi_od.h>

#include <rbus/dtg_reg.h>
#include <rbus/ppoverlay_reg.h>

//#include "rbusOutput_gammaReg.h"
//#include "rbusInv_gammaReg.h"
#endif

#if CONFIG_FIRMWARE_IN_KERNEL
#define VIPprintf(fmt, args...)	rtd_printk(KERN_DEBUG, TAG_NAME, fmt, ##args)//printk(KERN_DEBUG fmt, ##args)
#define VIPprintf1(fmt, args...)	/*printk(fmt, ##args)*/
#else
#define VIPprintf(fmt, args...)	printf(fmt, ##args)
#endif


/* henry @ mac5 170315 d-domain write enable bit */
void  IoReg_D_domain_SetBits(unsigned int addr, unsigned int Mask) {

	switch(Mask)
	{
		case COLOR_D_VC_Global_CTRL_dcc_en_mask:
			IoReg_Write32(addr, IoReg_Read32(addr) | Mask | COLOR_D_VC_Global_CTRL_write_enable_1_mask);
			break;
		case COLOR_D_VC_Global_CTRL_m_dcti_en_mask:
			IoReg_Write32(addr, IoReg_Read32(addr) | Mask | COLOR_D_VC_Global_CTRL_write_enable_2_mask);
			break;
		case COLOR_D_VC_Global_CTRL_m_icm_en_mask:
			IoReg_Write32(addr, IoReg_Read32(addr) | Mask | COLOR_D_VC_Global_CTRL_write_enable_3_mask);
			break;
		case COLOR_D_VC_Global_CTRL_m_sharp_en_mask:
			IoReg_Write32(addr, IoReg_Read32(addr) | Mask | COLOR_D_VC_Global_CTRL_write_enable_4_mask);
			break;
		case COLOR_D_VC_Global_CTRL_m_edgesmooth_en_mask:
			IoReg_Write32(addr, IoReg_Read32(addr) | Mask | COLOR_D_VC_Global_CTRL_write_enable_5_mask);
			break;
		case COLOR_D_VC_Global_CTRL_reg_bypass_pq_mask:
			IoReg_Write32(addr, IoReg_Read32(addr) | Mask | COLOR_D_VC_Global_CTRL_write_enable_6_mask);
			break;
		case COLOR_D_VC_Global_CTRL_icm_dcc_swap_mask:
			IoReg_Write32(addr, IoReg_Read32(addr) | Mask | COLOR_D_VC_Global_CTRL_write_enable_9_mask);
			break;
		case COLOR_D_VC_Global_CTRL_m_lc_comp_en_mask:
			IoReg_Write32(addr, IoReg_Read32(addr) | Mask | COLOR_D_VC_Global_CTRL_write_enable_12_mask);
			break;
		case COLOR_D_VC_Global_CTRL_m_vc_en_mask:
			IoReg_Write32(addr, IoReg_Read32(addr) | Mask | COLOR_D_VC_Global_CTRL_write_enable_11_mask);
			break;
		default:
			IoReg_Write32(addr, IoReg_Read32(addr) | Mask);
			break;
	}
}

void  IoReg_D_domain_ClearBits(unsigned int addr, unsigned int Mask) {

	switch(Mask)
	{
		case COLOR_D_VC_Global_CTRL_dcc_en_mask:
			IoReg_Write32(addr, (IoReg_Read32(addr) & ~(Mask)) | COLOR_D_VC_Global_CTRL_write_enable_1_mask);
			break;
		case COLOR_D_VC_Global_CTRL_m_dcti_en_mask:
			IoReg_Write32(addr, (IoReg_Read32(addr) & ~(Mask)) | COLOR_D_VC_Global_CTRL_write_enable_2_mask);
			break;
		case COLOR_D_VC_Global_CTRL_m_icm_en_mask:
			IoReg_Write32(addr, (IoReg_Read32(addr) & ~(Mask)) | COLOR_D_VC_Global_CTRL_write_enable_3_mask);
			break;
		case COLOR_D_VC_Global_CTRL_m_sharp_en_mask:
			IoReg_Write32(addr, (IoReg_Read32(addr) & ~(Mask)) | COLOR_D_VC_Global_CTRL_write_enable_4_mask);
			break;
		case COLOR_D_VC_Global_CTRL_m_edgesmooth_en_mask:
			IoReg_Write32(addr, (IoReg_Read32(addr) & ~(Mask)) | COLOR_D_VC_Global_CTRL_write_enable_5_mask);
			break;
		case COLOR_D_VC_Global_CTRL_reg_bypass_pq_mask:
			IoReg_Write32(addr, (IoReg_Read32(addr) & ~(Mask)) | COLOR_D_VC_Global_CTRL_write_enable_6_mask);
			break;
		case COLOR_D_VC_Global_CTRL_icm_dcc_swap_mask:
			IoReg_Write32(addr, (IoReg_Read32(addr) & ~(Mask)) | COLOR_D_VC_Global_CTRL_write_enable_9_mask);
			break;
		case COLOR_D_VC_Global_CTRL_m_lc_comp_en_mask:
			IoReg_Write32(addr, (IoReg_Read32(addr) & ~(Mask)) | COLOR_D_VC_Global_CTRL_write_enable_12_mask);
			break;
		case COLOR_D_VC_Global_CTRL_m_vc_en_mask:
			IoReg_Write32(addr, (IoReg_Read32(addr) & ~(Mask)) | COLOR_D_VC_Global_CTRL_write_enable_11_mask);
			break;
		default:
			IoReg_Write32(addr, (IoReg_Read32(addr) & ~(Mask)));
			break;
	}
}

/*====== xvYcc ====*/
#ifndef complement2
#define complement2(arg) (((~arg)&0x7FF)+1)
#endif
/*======xvYcc ====*/

#if 0
#include "Dragon.h"
#include "scaler/Mode.h"
#include "scaler/color.h"
#include "scaler/source.h"
#include "scaler/peaking.h"
#include "scaler/dcc.h"
#include "scaler/icm.h"
#include "Scaler_display.h"
#include "Misc.h"
#include "global.h"
#include "scaler.h"
#include "auto.h"
#include "VIP/VIP_reg_def.h"
#include "hdmi/hdmi_reg.h" /*for ColorSpaceRGB2YUVTransfer to read HDMI register*/
#include "scaler/nr.h"
#include "hdmi/hdmi_fun.h"
#include "scaler/scalerdef.h"
#include "audio/audio_api.h"
#include "scaler/video_quality.h"
#endif

/*#define TEST_GIVE_DEFAULT_DITHER_LUT 0		*/ /* dither table is ready, don't use it anymore*/
/*#define TEST_SKIP_WRITE_GAMMA 0			*/ /* gamma table is ready, don't use it anymore*/

unsigned int RGB2YUV_Y_Gain = 1024;
unsigned char RGB2YUV_if_RGB_mode = FALSE;
unsigned int lastCoef9=0xffffffff;

static UINT8 ucHighLightwindow_EnableFlag = _DISABLE;
/*static UINT8 HDMI_RGB_Range_Mode = 0;*/
static INT8 cDisplayStatusSave = -1;
static INT8 bWD_status_backup = -1;

unsigned short *HDR_SDR_SEAMLESS_PQ_index = NULL;

/*USER: Vincent_Lee  DATE: 2011/8/26  TODO: Add YUV2RGB_tab1 buffer*/
yuv2rgb_d_yuv2rgb_tab1_data_0_RBUS	yuv2rgb_tab1_data0_buffer;
yuv2rgb_d_yuv2rgb_tab1_data_1_RBUS	yuv2rgb_tab1_data1_buffer;

/* Hawaii add for new AutoView 20131001*/
unsigned char Ambient_light_type; /* Parameter description : This parameter is used to save the OSD value*/

#ifdef CONFIG_HDR_SDR_SEAMLESS
extern HDR_SDR_SEAMLESS_PQ_STRUCT HDR_SDR_SEAMLESS_PQ;
#endif
#define    dimC1 24
#define    dimC2 24
#define    dimC3 24

yuvdata table[dimC1*dimC2*dimC3];
yuvdata DDR_TABLE[dimC1*dimC2*dimC3];
yuvdata Domain_3DLUT_16[17*17*17]={0};
yuvdata temp_Domain_3DLUT_16[17*17*17]={0};

/*===================================  Types ================================*/

/*================================== Variables ==============================*/
/*extern unsigned char tDITHER_SEQUENCE[3][32] ;
extern unsigned char tDITHER_TEMPORAL[16] ;
extern  unsigned char tDITHER_LUT[3][4][4] ;*/

static unsigned short tYUV2RGB_COEF_601_YCbCr[] = {

	0x0100, /* k11*/
	0x0000, /* k12*/
	0x0166, /* k13*/
	0x7a8,/*0x0058, */ /* k22*/
	0x74a,/*0x00b6, */ /* k23*/
	0x01c5, /* k32*/
	0x0000, /* k33*/
	0x0000, /* R-offset*/
	0x0000, /* G-offset*/
	0x0000, /* B-offset*/
	0x0001, /* Y Clamp (Y-16)*/
	0x0001, /* UV Clamp (UV-512)*/
};

static unsigned short tYUV2RGB_COEF_601_YCbCr_limit2full_range[] = {
	0x012B, /* k11*/
	0x0000, /* k12*/
	0x0199, /* k13*/
	0x7a9,/*0x0057, */ /* k22*/
	0x730,/*0x00d0, */ /* k23*/
	0x0205, /* k32*/
	0x0000, /* k33*/
	0x0000, /* R-offset*/
	0x0000, /* G-offset*/
	0x0000, /* B-offset*/
	0x0001, /* Y Clamp (Y-16)*/
	0x0001, /* UV Clamp (UV-512)*/
};

unsigned char shd_IDCTI_COEF[2][10] = {
/*    Data_sel,  maxlen, psmth, lpmode, EngDiv, offDiv, uvGain, Dcti_mode, cur_sel, Dcti_en*/
	{0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x16, 0x00, 0x00, 0x01},	/* 1*/
	{0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x01},	/* 2*/
};


static unsigned char tDITHER_SEQUENCE[3][16] = {
	{0xAD, 0x80, 0xE6, 0xA3, 0x9E, 0x47, 0x2D, 0xB9, 0x12, 0x74, 0x1C, 0x5F, 0xF3, 0xB0, 0x6C, 0x85},
	{0x2D, 0xB9, 0x12, 0x74, 0x1C, 0x5F, 0xF3, 0xB0, 0x6C, 0x85, 0x0A, 0x68, 0x3E, 0xEA, 0x79, 0xD4},
	{0xAD, 0x80, 0xE6, 0xF3, 0xB0, 0x6C, 0x85, 0xEA, 0x79, 0xD4, 0x92, 0x2B, 0x41, 0xC7, 0xF1, 0x35}
	};

/*static unsigned char tDITHER_TEMPORAL[16] = { 0, 3, 2, 1, 2, 1, 3, 0, 3, 0, 1, 2, 1, 2, 0, 3 };*/
static unsigned char tDITHER_TEMPORAL[16] = { 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3 };


static unsigned char tDITHER_LUT[3][16][4] = {
	{
		{0x00, 0x30, 0x20, 0x10}, {0x29, 0x19, 0x39, 0x09}, {0x3E, 0x0E, 0x1E, 0x2E}, {0x17, 0x27, 0x07, 0x37},
		{0x0C, 0x3C, 0x2C, 0x1C}, {0x25, 0x15, 0x35, 0x05}, {0x32, 0x02, 0x12, 0x22}, {0x1B, 0x2B, 0x0B, 0x3B},
		{0x08, 0x38, 0x28, 0x18}, {0x2D, 0x1D, 0x3D, 0x0D}, {0x36, 0x06, 0x16, 0x26}, {0x13, 0x23, 0x03, 0x33},
		{0x04, 0x34, 0x24, 0x14}, {0x21, 0x11, 0x31, 0x01}, {0x3A, 0x0A, 0x1A, 0x2A}, {0x1F, 0x2F, 0x0F, 0x3F}
	},
	{
		{0x28, 0x18, 0x38, 0x08}, {0x3D, 0x0D, 0x1D, 0x2D}, {0x16, 0x26, 0x06, 0x36}, {0x03, 0x33, 0x23, 0x13},
		{0x24, 0x14, 0x34, 0x04}, {0x31, 0x01, 0x11, 0x21}, {0x1A, 0x2A, 0x0A, 0x3A}, {0x0F, 0x3F, 0x2F, 0x1F},
		{0x2C, 0x1C, 0x3C, 0x0C}, {0x35, 0x05, 0x15, 0x25}, {0x12, 0x22, 0x02, 0x32}, {0x0B, 0x3B, 0x2B, 0x1B},
		{0x20, 0x10, 0x30, 0x00}, {0x39, 0x09, 0x19, 0x29}, {0x1E, 0x2E, 0x0E, 0x3E}, {0x07, 0x37, 0x27, 0x17},
	},
	{
		{0x3C, 0x0C, 0x1C, 0x2C}, {0x15, 0x25, 0x05, 0x35}, {0x02, 0x32, 0x22, 0x12}, {0x2B, 0x1B, 0x3B, 0x0B},
		{0x30, 0x00, 0x10, 0x20}, {0x19, 0x29, 0x09, 0x39}, {0x0E, 0x3E, 0x2E, 0x1E}, {0x27, 0x17, 0x37, 0x07},
		{0x34, 0x04, 0x14, 0x24}, {0x11, 0x21, 0x01, 0x31}, {0x0A, 0x3A, 0x2A, 0x1A}, {0x2F, 0x1F, 0x3F, 0x0F},
		{0x38, 0x08, 0x18, 0x28}, {0x1D, 0x2D, 0x0D, 0x3D}, {0x06, 0x36, 0x26, 0x16}, {0x23, 0x13, 0x33, 0x03},
	}
	};


unsigned char sRGB_Debug_Level = 16;

unsigned int sGAMMA_R[512], sGAMMA_G[512], sGAMMA_B[512]; /* Num of index: Mac2 = 128, Sirius = 512 (jyyang_2013/12/30)*/

unsigned char mode_state_flag = 1;
unsigned int orign_Yo_reg;
unsigned char Panel_Bit;  /* Erin 100312*/

unsigned short orign_gain , orign_offset;

/*static unsigned int *tYUV2RGB_UV_OFFSET_BY_Y = NULL;*/
/*static unsigned int *tYUV2RGB_COEF_BY_Y = NULL;*/

dm_dm_submodule_enable_RBUS dm_submodule_temp = {0};

static unsigned char tDDither_Coef[VIP_DYNAMIC_DITHERING_TABLE_MAX][15] = {
/*dd_r_0_th, dd_r_1_th, dd_r_b0_type, dd_r_b1_type, dd_r_b2_type, dd_g_0_th, dd_g_1_th, dd_g_b0_type, dd_g_b1_type, dd_g_b2_type, dd_b_0_th, dd_b_1_th, dd_b_b0_type, dd_b_b1_type, dd_b_b2_type*/
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
};


/*================================ Definitions ==============================*/





#define _RGB_VIDEO_CONTRAST    (50)

#define _C9300R ((_D9300R*100+127)/255)	/* rescale*/
#define _C9300G ((_D9300G*100+127)/255)	/* rescale*/
#define _C9300B ((_D9300B*100+127)/255)	/* rescale*/

#define _C6500R ((_D6500R*100+127)/255)	/* rescale*/
#define _C6500G ((_D6500G*100+127)/255)	/* rescale*/
#define _C6500B ((_D6500B*100+127)/255)	/* rescale*/

#define _C5000R ((_D5000R*100+127)/255)	/* rescale*/
#define _C5000G ((_D5000G*100+127)/255)	/* rescale*/
#define _C5000B ((_D5000B*100+127)/255)	/* rescale*/
/*================================== Function ===============================*/

/*============================================================================*/
/**
 * ColorSpaceTransfer
 * Set Color space rgb2yuv conversion matrix
 * for source CCIR 601 YCbCr: Bypass RGB2YUV
 * for source CCIR 601 RGB: Use Tab-1 as ccir601 RGB2YUV
 * for source CCIR 709 YPbPr: overwrite Tab-2 as ccir709 YPbPr to 601 YCbCr
 * for source CCIR 709 RGB: overwrite Tab-2 as ccir709 RGB to 601 YCbCr
 */
void drvif_color_colorspacergb2yuvtransfer(unsigned char channel, unsigned short *table_index)
{
	rgb2yuv_ich1_rgb2yuv_ctrl_RBUS  ich1_RGB2YUV_CTRL_REG;

	rgb2yuv_tab1_m11_m12_RBUS tab1_m11_m12_reg;
	rgb2yuv_tab1_m13_m21_RBUS tab1_m13_m21_reg;
	rgb2yuv_tab1_m22_m23_RBUS tab1_m22_m23_reg;
	rgb2yuv_tab1_m31_m32_RBUS tab1_m31_m32_reg;
	rgb2yuv_tab1_m33_ygain_RBUS tab1_m33_ygain_reg;
	rgb2yuv_tab1_yo_RBUS tab1_yo_reg;

#if 1/*def VIP_CONFIG_DUAL_CHENNEL*/
#ifdef VIP_CONFIG_DUAL_CHANNEL // henry 161214
	rgb2yuv_ich2_rgb2yuv_ctrl_RBUS	ich2_RGB2YUV_CTRL_REG;

	rgb2yuv_tab2_m11_m12_RBUS tab2_m11_m12_reg;
	rgb2yuv_tab2_m13_m21_RBUS tab2_m13_m21_reg;
	rgb2yuv_tab2_m22_m23_RBUS tab2_m22_m23_reg;
	rgb2yuv_tab2_m31_m32_RBUS tab2_m31_m32_reg;
	rgb2yuv_tab2_m33_y_gain_RBUS tab2_m33_ygain_reg;
	rgb2yuv_tab2_yo_RBUS tab2_yo_reg;
#endif
#endif

	RGB2YUV_if_RGB_mode = FALSE;

	if (channel == _CHANNEL1)  { /*main always access tab-1*/
		ich1_RGB2YUV_CTRL_REG.regValue = IoReg_Read32(RGB2YUV_ICH1_RGB2YUV_CTRL_reg);

		ich1_RGB2YUV_CTRL_REG.sel_table = 0;
		ich1_RGB2YUV_CTRL_REG.en_rgb2yuv = 0;
		ich1_RGB2YUV_CTRL_REG.sel_y_gain = 1;
#ifdef RUN_ON_TVBOX
		ich1_RGB2YUV_CTRL_REG.sel_2x_gain = 1;
#endif


		IoReg_Write32(RGB2YUV_ICH1_RGB2YUV_CTRL_reg, ich1_RGB2YUV_CTRL_REG.regValue);
		#ifdef CONFIG_SOURCE_ROTATE_ENABLE
		if (Scaler_Get_Rotate_Enable()) {
			return;
		}
		#endif

		/*main  all tab-1*/
		tab1_m11_m12_reg.m11 = table_index[_RGB2YUV_m11];
		tab1_m11_m12_reg.m12 = table_index[_RGB2YUV_m12];
		IoReg_Write32(RGB2YUV_Tab1_M11_M12_reg, tab1_m11_m12_reg.regValue);
		tab1_m13_m21_reg.m13 = table_index[_RGB2YUV_m13];
		tab1_m13_m21_reg.m21 = table_index[_RGB2YUV_m21];
		IoReg_Write32(RGB2YUV_Tab1_M13_M21_reg, tab1_m13_m21_reg.regValue);
		tab1_m22_m23_reg.m22 = table_index[_RGB2YUV_m22];
		tab1_m22_m23_reg.m23 = table_index[_RGB2YUV_m23];
		IoReg_Write32(RGB2YUV_Tab1_M22_M23_reg, tab1_m22_m23_reg.regValue);
		tab1_m31_m32_reg.m31 = table_index[_RGB2YUV_m31];
		tab1_m31_m32_reg.m32 = table_index[_RGB2YUV_m32];
		IoReg_Write32(RGB2YUV_Tab1_M31_M32_reg, tab1_m31_m32_reg.regValue);
		tab1_m33_ygain_reg.m33 = table_index[_RGB2YUV_m33];
		tab1_m33_ygain_reg.y_gain = table_index[_RGB2YUV_Y_gain];
		IoReg_Write32(RGB2YUV_Tab1_M33_YGain_reg, tab1_m33_ygain_reg.regValue);

		tab1_yo_reg.yo_even = table_index[_RGB2YUV_Yo_even];
		tab1_yo_reg.yo_odd = table_index[_RGB2YUV_Yo_odd];
		IoReg_Write32(RGB2YUV_Tab1_Yo_reg, tab1_yo_reg.regValue);

		VIPprintf("@@@ RGB2YUV =%x\n", tab1_m33_ygain_reg.y_gain);
		orign_gain  = table_index[_RGB2YUV_Y_gain];
		orign_offset = table_index[_RGB2YUV_Yo_odd];
		orign_Yo_reg = tab1_yo_reg.regValue;
		RGB2YUV_Y_Gain = table_index[_RGB2YUV_Y_gain];

		ich1_RGB2YUV_CTRL_REG.sel_rgb = table_index[_RGB2YUV_sel_RGB];
		ich1_RGB2YUV_CTRL_REG.set_r_in_offset = table_index[_RGB2YUV_set_Yin_offset];
		ich1_RGB2YUV_CTRL_REG.set_uv_out_offset = table_index[_RGB2YUV_set_UV_out_offset];
		ich1_RGB2YUV_CTRL_REG.sel_uv_off = table_index[_RGB2YUV_sel_UV_off];
		ich1_RGB2YUV_CTRL_REG.matrix_bypass = table_index[_RGB2YUV_Matrix_bypass];
		ich1_RGB2YUV_CTRL_REG.sel_y_gain = table_index[_RGB2YUV_Enable_Y_gain];

		ich1_RGB2YUV_CTRL_REG.sel_table = 0;
		ich1_RGB2YUV_CTRL_REG.en_rgb2yuv = 1;

		/*ich1_RGB2YUV_CTRL_REG.sel_y_gain = 1;*/
		IoReg_Write32(RGB2YUV_ICH1_RGB2YUV_CTRL_reg, ich1_RGB2YUV_CTRL_REG.regValue);
		/*VIPprintf("SLR_MAIN_DISPLAY %d\n", which_tab);*/

	}
#if 1/*def VIP_CONFIG_DUAL_CHENNEL*/
#ifdef VIP_CONFIG_DUAL_CHANNEL // henry 161214
	else {
		ich2_RGB2YUV_CTRL_REG.regValue = IoReg_Read32(RGB2YUV_ICH2_RGB2YUV_CTRL_reg);
		ich2_RGB2YUV_CTRL_REG.sel_table = 1;
		ich2_RGB2YUV_CTRL_REG.en_rgb2yuv = 0;
		IoReg_Write32(RGB2YUV_ICH2_RGB2YUV_CTRL_reg, ich2_RGB2YUV_CTRL_REG.regValue);

		/*sub  all tab-2*/
		tab2_m11_m12_reg.m11 = table_index[_RGB2YUV_m11];
		tab2_m11_m12_reg.m12 = table_index[_RGB2YUV_m12];
		IoReg_Write32(RGB2YUV_Tab2_M11_M12_reg, tab2_m11_m12_reg.regValue);
		tab2_m13_m21_reg.m13 = table_index[_RGB2YUV_m13];
		tab2_m13_m21_reg.m21 = table_index[_RGB2YUV_m21];
		IoReg_Write32(RGB2YUV_Tab2_M13_M21_reg, tab2_m13_m21_reg.regValue);
		tab2_m22_m23_reg.m22 = table_index[_RGB2YUV_m22];
		tab2_m22_m23_reg.m23 = table_index[_RGB2YUV_m23];
		IoReg_Write32(RGB2YUV_Tab2_M22_M23_reg, tab2_m22_m23_reg.regValue);
		tab2_m31_m32_reg.m31 = table_index[_RGB2YUV_m31];
		tab2_m31_m32_reg.m32 = table_index[_RGB2YUV_m32];
		IoReg_Write32(RGB2YUV_Tab2_M31_M32_reg, tab2_m31_m32_reg.regValue);
		tab2_m33_ygain_reg.m33 = table_index[_RGB2YUV_m33];
		tab2_m33_ygain_reg.y_gain = table_index[_RGB2YUV_Y_gain];
		IoReg_Write32(RGB2YUV_Tab2_M33_Y_Gain_reg, tab2_m33_ygain_reg.regValue);

		tab2_yo_reg.yo_even = table_index[_RGB2YUV_Yo_even];
		tab2_yo_reg.yo_odd = table_index[_RGB2YUV_Yo_odd];
		IoReg_Write32(RGB2YUV_Tab2_Yo_reg, tab2_yo_reg.regValue);

		ich2_RGB2YUV_CTRL_REG.sel_rgb = table_index[_RGB2YUV_sel_RGB];
		ich2_RGB2YUV_CTRL_REG.set_r_in_offset = table_index[_RGB2YUV_set_Yin_offset];
		ich2_RGB2YUV_CTRL_REG.set_uv_out_offset = table_index[_RGB2YUV_set_UV_out_offset];
		ich2_RGB2YUV_CTRL_REG.sel_uv_off = table_index[_RGB2YUV_sel_UV_off];
		ich2_RGB2YUV_CTRL_REG.matrix_bypass = table_index[_RGB2YUV_Matrix_bypass];
		ich2_RGB2YUV_CTRL_REG.sel_y_gain = table_index[_RGB2YUV_Enable_Y_gain];

		ich2_RGB2YUV_CTRL_REG.sel_table = 1;
		ich2_RGB2YUV_CTRL_REG.en_rgb2yuv = 1;

		IoReg_Write32(RGB2YUV_ICH2_RGB2YUV_CTRL_reg, ich2_RGB2YUV_CTRL_REG.regValue);

		/*VIPprintf("_SUB_DISPLAY %d\n", which_tab);*/
	}
#endif
#endif
}

void drvif_color_get_rgb2yuvtransfer(unsigned char channel, unsigned short *table_index)
{
	if (channel == _CHANNEL1)  { /*main always access tab-1*/
		rgb2yuv_ich1_rgb2yuv_ctrl_RBUS	ich1_RGB2YUV_CTRL_REG;

		rgb2yuv_tab1_m11_m12_RBUS tab1_m11_m12_reg;
		rgb2yuv_tab1_m13_m21_RBUS tab1_m13_m21_reg;
		rgb2yuv_tab1_m22_m23_RBUS tab1_m22_m23_reg;
		rgb2yuv_tab1_m31_m32_RBUS tab1_m31_m32_reg;
		rgb2yuv_tab1_m33_ygain_RBUS tab1_m33_ygain_reg;
		rgb2yuv_tab1_yo_RBUS tab1_yo_reg;

		ich1_RGB2YUV_CTRL_REG.regValue = IoReg_Read32(RGB2YUV_ICH1_RGB2YUV_CTRL_reg);
		tab1_m11_m12_reg.regValue = IoReg_Read32(RGB2YUV_Tab1_M11_M12_reg);
		tab1_m13_m21_reg.regValue = IoReg_Read32(RGB2YUV_Tab1_M13_M21_reg);
		tab1_m22_m23_reg.regValue = IoReg_Read32(RGB2YUV_Tab1_M22_M23_reg);
		tab1_m31_m32_reg.regValue = IoReg_Read32(RGB2YUV_Tab1_M31_M32_reg);
		tab1_m33_ygain_reg.regValue= IoReg_Read32(RGB2YUV_Tab1_M33_YGain_reg);
		tab1_yo_reg.regValue = IoReg_Read32(RGB2YUV_Tab1_Yo_reg);

		/*main  all tab-1*/
		table_index[_RGB2YUV_m11] = tab1_m11_m12_reg.m11;
		table_index[_RGB2YUV_m12] = tab1_m11_m12_reg.m12;
		table_index[_RGB2YUV_m13] = tab1_m13_m21_reg.m13;
		table_index[_RGB2YUV_m21] = tab1_m13_m21_reg.m21;
		table_index[_RGB2YUV_m22] = tab1_m22_m23_reg.m22;
		table_index[_RGB2YUV_m23] = tab1_m22_m23_reg.m23;
		table_index[_RGB2YUV_m31] = tab1_m31_m32_reg.m31;
		table_index[_RGB2YUV_m32] = tab1_m31_m32_reg.m32;
		table_index[_RGB2YUV_m33] = tab1_m33_ygain_reg.m33;
		table_index[_RGB2YUV_Y_gain] = tab1_m33_ygain_reg.y_gain;

		table_index[_RGB2YUV_Yo_even] = tab1_yo_reg.yo_even;
		table_index[_RGB2YUV_Yo_odd] = tab1_yo_reg.yo_odd;

		table_index[_RGB2YUV_sel_RGB] = ich1_RGB2YUV_CTRL_REG.sel_rgb;
		table_index[_RGB2YUV_set_Yin_offset] = ich1_RGB2YUV_CTRL_REG.set_r_in_offset;
		table_index[_RGB2YUV_set_UV_out_offset] = ich1_RGB2YUV_CTRL_REG.set_uv_out_offset;
		table_index[_RGB2YUV_sel_UV_off] = ich1_RGB2YUV_CTRL_REG.sel_uv_off;
		table_index[_RGB2YUV_Matrix_bypass] = ich1_RGB2YUV_CTRL_REG.matrix_bypass;
		table_index[_RGB2YUV_Enable_Y_gain] = ich1_RGB2YUV_CTRL_REG.sel_y_gain;
	}
#if 1/*def VIP_CONFIG_DUAL_CHENNEL*/
#ifdef VIP_CONFIG_DUAL_CHANNEL // henry 161214
	else {
		rgb2yuv_ich2_rgb2yuv_ctrl_RBUS	ich2_RGB2YUV_CTRL_REG;
		rgb2yuv_tab2_m11_m12_RBUS tab2_m11_m12_reg;
		rgb2yuv_tab2_m13_m21_RBUS tab2_m13_m21_reg;
		rgb2yuv_tab2_m22_m23_RBUS tab2_m22_m23_reg;
		rgb2yuv_tab2_m31_m32_RBUS tab2_m31_m32_reg;
		rgb2yuv_tab2_m33_y_gain_RBUS tab2_m33_ygain_reg;
		rgb2yuv_tab2_yo_RBUS tab2_yo_reg;

		ich2_RGB2YUV_CTRL_REG.regValue = IoReg_Read32(RGB2YUV_ICH2_RGB2YUV_CTRL_reg);
		tab2_m11_m12_reg.regValue = IoReg_Read32(RGB2YUV_Tab2_M11_M12_reg);
		tab2_m13_m21_reg.regValue = IoReg_Read32(RGB2YUV_Tab2_M13_M21_reg);
		tab2_m22_m23_reg.regValue = IoReg_Read32(RGB2YUV_Tab2_M22_M23_reg);
		tab2_m31_m32_reg.regValue = IoReg_Read32(RGB2YUV_Tab2_M31_M32_reg);
		tab2_m33_ygain_reg.regValue= IoReg_Read32(RGB2YUV_Tab2_M33_Y_Gain_reg);
		tab2_yo_reg.regValue = IoReg_Read32(RGB2YUV_Tab2_Yo_reg);


		/*sub  all tab-2*/
		table_index[_RGB2YUV_m11] = tab2_m11_m12_reg.m11;
		table_index[_RGB2YUV_m12] = tab2_m11_m12_reg.m12;
		table_index[_RGB2YUV_m13] = tab2_m13_m21_reg.m13;
		table_index[_RGB2YUV_m21] = tab2_m13_m21_reg.m21;
		table_index[_RGB2YUV_m22] = tab2_m22_m23_reg.m22;
		table_index[_RGB2YUV_m23] = tab2_m22_m23_reg.m23;
		table_index[_RGB2YUV_m31] = tab2_m31_m32_reg.m31;
		table_index[_RGB2YUV_m32] = tab2_m31_m32_reg.m32;
		table_index[_RGB2YUV_m33] = tab2_m33_ygain_reg.m33;
		table_index[_RGB2YUV_Y_gain] = tab2_m33_ygain_reg.y_gain;

		table_index[_RGB2YUV_Yo_even] = tab2_yo_reg.yo_even;
		table_index[_RGB2YUV_Yo_odd] = tab2_yo_reg.yo_odd;

		table_index[_RGB2YUV_sel_RGB] = ich2_RGB2YUV_CTRL_REG.sel_rgb;
		table_index[_RGB2YUV_set_Yin_offset] = ich2_RGB2YUV_CTRL_REG.set_r_in_offset;
		table_index[_RGB2YUV_set_UV_out_offset] = ich2_RGB2YUV_CTRL_REG.set_uv_out_offset;
		table_index[_RGB2YUV_sel_UV_off] = ich2_RGB2YUV_CTRL_REG.sel_uv_off;
		table_index[_RGB2YUV_Matrix_bypass] = ich2_RGB2YUV_CTRL_REG.matrix_bypass;
		table_index[_RGB2YUV_Enable_Y_gain] = ich2_RGB2YUV_CTRL_REG.sel_y_gain;
	}
#endif
#endif
}

/*============================================================================*/
/**
 * ColorSpaceTransfer
 * Set Color space yuv2rgb conversion matrix
 * for source CCIR 601 YCbCr: Use Tab-1 as ccir601 YPbPr to 601 RGB
 * for source CCIR 709 YPbPr: Use Tab-2 as ccir709 YPbPr to 601 RGB

 */

/*using drvif_color_setYUV2RGB_CSMatrix instead, elieli*/
/*============================================================================*/
/**
 * ColorSetYDLTI
 * Set DLTI of Y path
 *
 * @param < display> {main/sub display}
 * @param <HF_Enable> {HF enable control}
 * @param <HF_TH> {HF threshold value}
 * @param <Gain> {Gain}
 * @param <Gain_th> {Gain_th}
 * @param <AdvanceDelay> {AdvanceDelay control}
 * @param <Long> {Long control}
 * @param <Near> {Near control}
 * @param <Contour_enable> {contour control}
 * @param <Contour_th> {contour threshold value}
 * @return {none}
 *
 */
 void drvif_color_colorsetydlti(unsigned char display, unsigned char HF_Enable, unsigned char HF_Th,  unsigned char Gain, unsigned char Gain_th, unsigned char  AdvanceDelay, unsigned char Long, unsigned char Near, unsigned char Contour_enable, unsigned char Contour_th)
{
	/*unsigned int options = 0;*/

	/*options = (HF_Enable << 15) + (HF_Th << 8) + (AdvanceDelay << 7) + (Long << 6) + (Near << 5) + (Contour_enable << 4) + (Contour_th&0x0f);*/
	#if 0
	if (display == SLR_MAIN_DISPLAY) {
		dm_dlti_options_RBUS dm_dlti_options_REG;
		dm_dlti_options_REG.advance_delay = AdvanceDelay;
		dm_dlti_options_REG.hf_th_enabled = HF_Enable;
		dm_dlti_options_REG.hf_th_value = HF_Th;
		dm_dlti_options_REG.prevent_contour = Contour_enable;
		dm_dlti_options_REG.prevent_contour_th = Contour_th;
		dm_dlti_options_REG.prevent_long = Long;
		dm_dlti_options_REG.prevent_near = Near;
		IoReg_Write32(COLOR_DLCTI_DM_DLTI_OPTIONS_VADDR, dm_dlti_options_REG.regValue);

		dm_dlti_value_RBUS dm_dlti_value_REG;
		dm_dlti_value_REG.gain_value = Gain;
		dm_dlti_value_REG.th_value = Gain_th;
		IoReg_Write32(COLOR_DLCTI_DM_DLTI_VALUE_VADDR, dm_dlti_value_REG.regValue);

	}
	#endif

}




/*============================================================================*/
/**
 * ColorSetCDCTI
 * Set DCTI of C path
 *
 * @param <display> {main/sub display}
 * @param <Prevent_PE> {Phase Error Control}
 * @param <S_DCTI_Enable> {2nd DCTi Control}
 * @param <F_Gain> {First_Gain}
 * @param <F_th> {First_th}
 * @param <S_Gain> {Second_Gain}
 * @param <S_th> {Second_th}
 * @return {none}
 *
 */

#if 0
  void drvif_color_colorsetcdcti(unsigned char display, unsigned char Prevent_PE,  unsigned char F_Gain, unsigned char F_th, unsigned char S_DCTI_Enable, unsigned char S_Gain, unsigned char S_Th)
{

	if (display == SLR_MAIN_DISPLAY) {
		dm_dcti_1st_value_RBUS dm_dcti_1st_value_REG;
		dm_dcti_1st_value_REG.gain_value = F_Gain;
		dm_dcti_1st_value_REG.th_value = F_th;
		IoReg_Write32(COLOR_DLCTI_DM_DCTI_1ST_VALUE_VADDR, dm_dcti_1st_value_REG.regValue);

		dm_dcti_2nd_value_RBUS dm_dcti_2nd_value_REG;
		dm_dcti_2nd_value_REG.gain_value = S_Gain;
		dm_dcti_2nd_value_REG.th_value = S_Th;
		IoReg_Write32(COLOR_DLCTI_DM_DCTI_2ND_VALUE_VADDR, dm_dcti_2nd_value_REG.regValue);


		dm_dcti_options_RBUS dm_dcti_options_REG;
		dm_dcti_options_REG.enabled = S_DCTI_Enable;
		dm_dcti_options_REG.prevent_pe = Prevent_PE;
		IoReg_Write32(COLOR_DLCTI_DM_DCTI_OPTIONS_VADDR, dm_dcti_options_REG.regValue);


	}
#ifdef CONFIG_DUAL_CHANNEL
	else {
		ds_dcti_1st_value_RBUS ds_dcti_1st_value_REG;
		ds_dcti_1st_value_REG.gain_value = F_Gain;
		ds_dcti_1st_value_REG.th_value = F_th;
		IoReg_Write32(COLOR_DLCTI_DS_DCTI_1ST_VALUE_VADDR, ds_dcti_1st_value_REG.regValue);

		ds_dcti_2nd_value_RBUS ds_dcti_2nd_value_REG;
		ds_dcti_2nd_value_REG.gain_value = S_Gain;
		ds_dcti_2nd_value_REG.th_value = S_Th;
		IoReg_Write32(COLOR_DLCTI_DS_DCTI_2ND_VALUE_VADDR, ds_dcti_2nd_value_REG.regValue);


		ds_dcti_options_RBUS ds_dcti_options_REG;
		ds_dcti_options_REG.enabled = S_DCTI_Enable;
		ds_dcti_options_REG.prevent_pe = Prevent_PE;
		IoReg_Write32(COLOR_DLCTI_DS_DCTI_OPTIONS_VADDR, ds_dcti_options_REG.regValue);

	}
#endif
	/*Color_ProcessAccessCtrl(display);*/
	/*Rspi_SetBits(_P5_01_VC_BLK_ENABLE,   _BIT3|_BIT7);*/
	/*Rspi_WriteByte(_P5_14_DCTI_1ST_GAIN,  (Prevent_PE << 7)  + (F_Gain&0x1f));*/
	/*Rspi_WriteByte(_P5_15_DCTI_1ST_TH,  F_th&0x3f);*/
	/*Rspi_WriteByte(_P5_16_DCTI_2ND_GAIN, (S_DCTI_Enable << 5) + (S_Gain&0x1f));*/
	/*Rspi_WriteByte(_P5_17_DCTI_2ND_TH,  S_Th&0x3f);*/

}
#endif

/*============================================================================*/
/**
 * ColorSetYDLTI
 * Set DLTI of Y path
 *
 * @param <display> {main/sub display}
 * @param <Level> {Level control 0~11, 0:0ff, 1~10 = level}
 */

 void drvif_color_setydlti(unsigned char display, unsigned char Level)
{
	/*unsigned char ii = 0;*/
	return;
#if 0
	color_d_vc_global_ctrl_RBUS d_vc_global_ctrl_REG;
	d_vc_global_ctrl_REG.regValue = IoReg_Read32(COLOR_D_VC_GLOBAL_CTRL_VADDR);


	if (Level != 0) {
		Level = Level-1;
/*		VIPprintf("DLTi Level = %d\n", Level);*/
		drvif_color_colorsetydlti(display,
					tDLTI_COEF[Level][0],
					tDLTI_COEF[Level][1],
					tDLTI_COEF[Level][2],
					tDLTI_COEF[Level][3],
					tDLTI_COEF[Level][4],
					tDLTI_COEF[Level][5],
					tDLTI_COEF[Level][6],
					tDLTI_COEF[Level][7],
					tDLTI_COEF[Level][8]);

		if (display == SLR_MAIN_DISPLAY)
			d_vc_global_ctrl_REG.m_dlti_en = 1;

	} else {


		if (display == SLR_MAIN_DISPLAY)
			d_vc_global_ctrl_REG.m_dlti_en = 0;

	}


	/*frank@1002 workaround for s_huesat_en be set when DCC debug mode open*/
	/* marked following line for s_hue & sat table finished.*/
	/*d_vc_global_ctrl_REG.s_huesat_en = 0;*/
	/*VIPprintf("DLTi Level = %d, dlti_enable = %d, reg_enable = %d\n", Level, d_vc_global_ctrl_REG.m_dlti_en, d_vc_global_ctrl_REG.regValue);*/
	IoReg_Write32(COLOR_D_VC_GLOBAL_CTRL_VADDR, d_vc_global_ctrl_REG.regValue);
#endif
}

/*============================================================================*/
/**
 * ColorSetCDCTI
 * Set DCTI of C path
 *
 * @param <display> {main/sub display}
 * @param <Level> {Level control 0~10, 0:0ff, 1~9 = level}
 */

/*JZ Mac3*/
void drvif_color_dnewdcti_table(DRV_VipNewDDcti_Table *ptr)
{
	if (!ptr)
		return;

/*ctl1*/
	{
	color_sharp_shp_dcti_ctrl_1_RBUS dm_dcti_REG_1;
	color_d_vc_global_ctrl_RBUS d_vc_global_ctrl_Reg;

	dm_dcti_REG_1.regValue = IoReg_Read32(COLOR_SHARP_SHP_DCTI_CTRL_1_reg);
	d_vc_global_ctrl_Reg.regValue = IoReg_Read32(COLOR_D_VC_Global_CTRL_reg);

	dm_dcti_REG_1.data_sel = ptr->VipNewDDcti_ctl1.data_sel;
	dm_dcti_REG_1.maxlen = ptr->VipNewDDcti_ctl1.maxlen;
	dm_dcti_REG_1.psmth = ptr->VipNewDDcti_ctl1.psmth;
	dm_dcti_REG_1.lpmode = ptr->VipNewDDcti_ctl1.lp_mode;
	dm_dcti_REG_1.engdiv = ptr->VipNewDDcti_ctl1.engdiv;
	dm_dcti_REG_1.offdiv = ptr->VipNewDDcti_ctl1.offdiv;
	dm_dcti_REG_1.uvgain = ptr->VipNewDDcti_ctl1.uvgain;
	dm_dcti_REG_1.dcti_mode = ptr->VipNewDDcti_ctl1.dcti_mode;
	dm_dcti_REG_1.uvalign_en = ptr->VipNewDDcti_ctl1.uvalign_en;
	dm_dcti_REG_1.cur_sel = ptr->VipNewDDcti_ctl1.cur_sel;
	d_vc_global_ctrl_Reg.m_dcti_en = ptr->VipNewDDcti_ctl1.dcti_en;
	d_vc_global_ctrl_Reg.write_enable_2= 1;

	//d_vc_global_ctrl_Reg.regValue = d_vc_global_ctrl_Reg.regValue | COLOR_D_VC_Global_CTRL_write_enable_2_mask;


	IoReg_Write32(COLOR_SHARP_SHP_DCTI_CTRL_1_reg, dm_dcti_REG_1.regValue);
	IoReg_Write32(COLOR_D_VC_Global_CTRL_reg, d_vc_global_ctrl_Reg.regValue);
	}
/*ctl2*/
	{
	color_sharp_shp_dcti_ctrl_2_RBUS dm_dcti_REG_2;
	dm_dcti_REG_2.regValue = IoReg_Read32(COLOR_SHARP_SHP_DCTI_CTRL_2_reg);

	dm_dcti_REG_2.uvsync_en = ptr->VipNewDDcti_ctl2.uvsync_en;
	dm_dcti_REG_2.tran_mode = ptr->VipNewDDcti_ctl2.tran_mode;
	dm_dcti_REG_2.rate_steep = ptr->VipNewDDcti_ctl2.rate_steep;
	dm_dcti_REG_2.th_steep = ptr->VipNewDDcti_ctl2.th_steep;
	dm_dcti_REG_2.th_coring = ptr->VipNewDDcti_ctl2.th_coring;
	dm_dcti_REG_2.steep_mode = ptr->VipNewDDcti_ctl2.steep_mode;
	dm_dcti_REG_2.hp_mode = ptr->VipNewDDcti_ctl2.hp_mode;
	dm_dcti_REG_2.vlp_mode = ptr->VipNewDDcti_ctl2.vlp_mode;
	dm_dcti_REG_2.median_mode = ptr->VipNewDDcti_ctl2.median_mode;
	dm_dcti_REG_2.blending_mode = ptr->VipNewDDcti_ctl2.blending_mode;

	IoReg_Write32(COLOR_SHARP_SHP_DCTI_CTRL_2_reg, dm_dcti_REG_2.regValue);
	}
/*ctl3*/
	{
	color_sharp_shp_dcti_ctrl_3_RBUS dm_dcti_REG_3;
	dm_dcti_REG_3.regValue = IoReg_Read32(COLOR_SHARP_SHP_DCTI_CTRL_3_reg);

	dm_dcti_REG_3.maxminlen = ptr->VipNewDDcti_ctl3.maxminlen;
	dm_dcti_REG_3.rate_tran = ptr->VipNewDDcti_ctl3.rate_tran;
	dm_dcti_REG_3.th_tran = ptr->VipNewDDcti_ctl3.th_tran;
	dm_dcti_REG_3.region_mode = ptr->VipNewDDcti_ctl3.region_mode;
	dm_dcti_REG_3.rate_smooth = ptr->VipNewDDcti_ctl3.rate_smooth;
	dm_dcti_REG_3.th_smooth = ptr->VipNewDDcti_ctl3.th_smooth;

	IoReg_Write32(COLOR_SHARP_SHP_DCTI_CTRL_3_reg, dm_dcti_REG_3.regValue);
	}
/*ctl4*/
	{
	color_sharp_shp_dcti_ctrl_4_RBUS dm_dcti_REG_4;
	dm_dcti_REG_4.regValue = IoReg_Read32(COLOR_SHARP_SHP_DCTI_CTRL_4_reg);

	dm_dcti_REG_4.rate_align_weight = ptr->VipNewDDcti_ctl4.rate_align_weight;
	dm_dcti_REG_4.rate_align = ptr->VipNewDDcti_ctl4.rate_align;
	dm_dcti_REG_4.th_align = ptr->VipNewDDcti_ctl4.th_align;
	dm_dcti_REG_4.align_mingain = ptr->VipNewDDcti_ctl4.align_mingain;
	dm_dcti_REG_4.th_gtran = ptr->VipNewDDcti_ctl4.th_gtran;

	IoReg_Write32(COLOR_SHARP_SHP_DCTI_CTRL_4_reg, dm_dcti_REG_4.regValue);
	}
/*ctl5*/
	{
	color_sharp_shp_dcti_ctrl_5_RBUS dm_dcti_REG_5;
	dm_dcti_REG_5.regValue = IoReg_Read32(COLOR_SHARP_SHP_DCTI_CTRL_5_reg);

	dm_dcti_REG_5.th_uvmindiff = ptr->VipNewDDcti_ctl5.th_uvmindiff;
	dm_dcti_REG_5.rate_stair2 = ptr->VipNewDDcti_ctl5.rate_stair2;
	dm_dcti_REG_5.rate_stair1 = ptr->VipNewDDcti_ctl5.rate_stair1;
	dm_dcti_REG_5.th_stair = ptr->VipNewDDcti_ctl5.th_stair;
	dm_dcti_REG_5.th_align_weight = ptr->VipNewDDcti_ctl5.th_align_weight;

	IoReg_Write32(COLOR_SHARP_SHP_DCTI_CTRL_5_reg, dm_dcti_REG_5.regValue);
	}
/*ctl6*/
	{
	color_sharp_shp_dcti_ctrl_6_RBUS dm_dcti_REG_6;
	dm_dcti_REG_6.regValue = IoReg_Read32(COLOR_SHARP_SHP_DCTI_CTRL_6_reg);

	dm_dcti_REG_6.rate_engsync = ptr->VipNewDDcti_ctl6.rate_engsync;
	dm_dcti_REG_6.rate_uvmindiff = ptr->VipNewDDcti_ctl6.rate_uvmindiff;
	dm_dcti_REG_6.th_engsync = ptr->VipNewDDcti_ctl6.th_engsync;

	IoReg_Write32(COLOR_SHARP_SHP_DCTI_CTRL_6_reg, dm_dcti_REG_6.regValue);
	}
/*ctl7*/
	{
	color_sharp_shp_dcti_ctrl_7_RBUS dm_dcti_REG_7;
	dm_dcti_REG_7.regValue = IoReg_Read32(COLOR_SHARP_SHP_DCTI_CTRL_7_reg);
	dm_dcti_REG_7.debug_shiftbit = ptr->VipNewDDcti_ctl7.debug_shiftbit;
	dm_dcti_REG_7.debug_mode = ptr->VipNewDDcti_ctl7.debug_mode;

	IoReg_Write32(COLOR_SHARP_SHP_DCTI_CTRL_7_reg, dm_dcti_REG_7.regValue);
	}

}

/*============================================================================*/
/**
 * ColorSet422To444
 * Set 4:2:2 to 4:4:4 interpolation of C path
 * @param <info> {disp-info structure}
 * @return {none}
 *
 */
 void drvif_color_set422to444(unsigned char channel, unsigned char bEnable)
{
	rgb2yuv_ich1_422to444_ctrl_RBUS ich1_422to444_CTRL_REG;
#if 1/*def VIP_CONFIG_DUAL_CHENNEL*/
#ifdef VIP_CONFIG_DUAL_CHANNEL // henry 161214
	rgb2yuv_ich2_422to444_ctrl_RBUS ich2_422to444_CTRL_REG;
#endif
#endif

	ich1_422to444_CTRL_REG.dup = 0;
	ich1_422to444_CTRL_REG.cr_dly_cb = 0;
#if 1/*def VIP_CONFIG_DUAL_CHENNEL*/
#ifdef VIP_CONFIG_DUAL_CHANNEL // henry 161214
	ich2_422to444_CTRL_REG.dup = 0;
	ich2_422to444_CTRL_REG.cr_dly_cb = 0;
#endif
#endif

	if (channel == _CHANNEL1) {

		if (bEnable)
			ich1_422to444_CTRL_REG.en_422to444 = 1;
		else
			ich1_422to444_CTRL_REG.en_422to444 = 0;

		//20150912 roger, LGE HDR flow not perfect, so using flag to control
		{
		//_system_setting_info *VIP_system_info_structure_table = (_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_system_info_structure);
		_RPC_system_setting_info *VIP_RPC_system_info_structure_table = NULL;
		VIP_RPC_system_info_structure_table = (_RPC_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_RPC_system_info_structure);
		if(VIP_RPC_system_info_structure_table == NULL){
			VIPprintf("[%s:%d] Warning here!! RPC_system_info=NULL! \n",__FILE__, __LINE__);
			return;
		}

		if (VIP_RPC_system_info_structure_table->HDR_info.Ctrl_Item[TV006_HDR_En])
			ich1_422to444_CTRL_REG.en_422to444 = 0;
		}

		IoReg_Write32(RGB2YUV_ICH1_422to444_CTRL_reg, ich1_422to444_CTRL_REG.regValue);

	}
#if 1/*def VIP_CONFIG_DUAL_CHENNEL*/
#ifdef VIP_CONFIG_DUAL_CHANNEL // henry 161214
	else {
		if (bEnable)
			ich2_422to444_CTRL_REG.en_422to444 = 1;
		else
			ich2_422to444_CTRL_REG.en_422to444 = 0;

		IoReg_Write32(RGB2YUV_ICH2_422to444_CTRL_reg, ich2_422to444_CTRL_REG.regValue);

	}
#endif
#endif
}

/*============================================================================*/
/**
 * Color_Write_output_Gamma, inv_output_Gamma, RGBW
 * This function is used to write output gamma table in single channel
 *
 * @param <pArray> 	{ gamma table lut}
 * @return 			{ void }
 *
 */

void drvif_color_colorwrite_output_gamma(UINT32 *pArray, VIP_GAMMA_CHANNEL_RGB RGB_chanel_idx)
{
#if 1/*Elsie 20140729: Mac3 no output gamma.*/ /*jyyang: Merlin2 has output gamma(20160616)*/
	/*VIPprintf("drvif_color_colorwrite_output_gamma start ===================\n");*/
	unsigned short ii, cnt = 10000;
	outputgamma_out_gamma_port_RBUS out_gamma_port_REG;
	outputgamma_out_gamma_ctrl_1_RBUS out_gamma_ctrl_1_REG;
	unsigned char status = 1;

	/*Thur modified for compile 20090113*/
	/*IoReg_BusyCheckRegBit(DDOMAIN_MAIN_DISPLAY_CONTROL_RSV_VADDR,_BIT10, 0x0001FFFF);*/
	/*frank@0902 mark to speed code */ /*IoReg_BusyCheckRegBit(PPOVERLAY_Main_Display_Control_RSV_reg,_BIT10, 0x0001FFFF);*/
	/*ROS_ENTER_CRITICAL();*/

	if(Get_DISPLAY_PANEL_TYPE() == P_VBY1_TO_LVDS_2K){
		return;
	}

	out_gamma_ctrl_1_REG.regValue = IoReg_Read32(OUTPUTGAMMA_OUT_GAMMA_CTRL_1_reg);
	out_gamma_ctrl_1_REG.out_gamma_ax_rw_sel = 1; // enable write (0:disable, 1:Write, 2:Read)
	out_gamma_ctrl_1_REG.out_gamma_ax_ch_sel = RGB_chanel_idx; // 0:R, 1:G, 2:B, 3:RGB, 4:W
	IoReg_Write32(OUTPUTGAMMA_OUT_GAMMA_CTRL_1_reg, out_gamma_ctrl_1_REG.regValue);

	for (ii = 0; ii < (Bin_Num_Output_InvOutput_Gamma>>1); ii++) {

		status = 1;
		cnt = 10000;

		out_gamma_port_REG.regValue = pArray[ii];
		/*VIPprintf("=====================%d ==== 6\n", pArray[ii]);*/
		IoReg_Write32(OUTPUTGAMMA_OUT_GAMMA_PORT_reg, out_gamma_port_REG.regValue);

		while ((cnt--) && (status) && ((ii % 16) == 15)) {/*20071217 jason(jeffery) modified*/
			out_gamma_ctrl_1_REG.regValue = IoReg_Read32(OUTPUTGAMMA_OUT_GAMMA_PORT_reg);
			status =  (out_gamma_ctrl_1_REG.out_gamma_fifo_empty == 1) ? 0 : 1;
		}
	}
	/*VIPprintf("gamma end ===================\n");*/
	/*ROS_EXIT_CRITICAL();*/

	out_gamma_ctrl_1_REG.regValue = IoReg_Read32(OUTPUTGAMMA_OUT_GAMMA_CTRL_1_reg);
	out_gamma_ctrl_1_REG.out_gamma_ax_rw_sel = 0; // disable write
	IoReg_Write32(OUTPUTGAMMA_OUT_GAMMA_CTRL_1_reg, out_gamma_ctrl_1_REG.regValue);
#endif
}
#if 0 //jyyang20161215
void drvif_color_colorwrite_inv_output_gamma(UINT32 *pArray, VIP_GAMMA_CHANNEL_RGB RGB_chanel_idx)
{
	/*jyyang: Merlin2 has inv output gamma (20160616)*/
	unsigned short ii, cnt = 10000;
	invoutputgamma_inv_out_gamma_port_RBUS inv_out_gamma_port_REG;
	invoutputgamma_inv_out_gamma_ctrl_1_RBUS inv_out_gamma_ctrl_1_REG;
	unsigned char status = 1;

	inv_out_gamma_ctrl_1_REG.regValue = IoReg_Read32(INVOUTPUTGAMMA_INV_OUT_GAMMA_CTRL_1_reg);
	inv_out_gamma_ctrl_1_REG.inv_out_gamma_ax_rw_sel = 1; // enable write (0:disable, 1:Write, 2:Read)
	inv_out_gamma_ctrl_1_REG.inv_out_gamma_ax_ch_sel = RGB_chanel_idx; // 0:R, 1:G, 2:B, 3:RGB
	IoReg_Write32(INVOUTPUTGAMMA_INV_OUT_GAMMA_CTRL_1_reg, inv_out_gamma_ctrl_1_REG.regValue);

	for (ii = 0; ii < (Bin_Num_Output_InvOutput_Gamma>>1); ii++) {

		status = 1;
		cnt = 10000;

		inv_out_gamma_port_REG.regValue = pArray[ii];
		IoReg_Write32(INVOUTPUTGAMMA_INV_OUT_GAMMA_PORT_reg, inv_out_gamma_port_REG.regValue);

		while ((cnt--) && (status) && ((ii % 16) == 15)) {/*20071217 jason(jeffery) modified*/
			inv_out_gamma_ctrl_1_REG.regValue = IoReg_Read32(INVOUTPUTGAMMA_INV_OUT_GAMMA_PORT_reg);
			status =  (inv_out_gamma_ctrl_1_REG.inv_out_gamma_fifo_empty == 1) ? 0 : 1;
		}
	}

	inv_out_gamma_ctrl_1_REG.regValue = IoReg_Read32(INVOUTPUTGAMMA_INV_OUT_GAMMA_CTRL_1_reg);
	inv_out_gamma_ctrl_1_REG.inv_out_gamma_ax_rw_sel = 0; // disable write
	IoReg_Write32(INVOUTPUTGAMMA_INV_OUT_GAMMA_CTRL_1_reg, inv_out_gamma_ctrl_1_REG.regValue);
}
void drvif_color_colorwrite_inv_output_gamma_Enable(unsigned char Enable)
{
	invoutputgamma_inv_out_gamma_ctrl_1_RBUS inv_out_gamma_ctrl_1_REG;

	inv_out_gamma_ctrl_1_REG.regValue = IoReg_Read32(INVOUTPUTGAMMA_INV_OUT_GAMMA_CTRL_1_reg);
	inv_out_gamma_ctrl_1_REG.inv_out_gamma_en = Enable;

	IoReg_Write32(INVOUTPUTGAMMA_INV_OUT_GAMMA_CTRL_1_reg, inv_out_gamma_ctrl_1_REG.regValue);

}

#endif

void drvif_color_set_output_gamma_format(unsigned char Enable, unsigned char fmt, unsigned char loc, unsigned char ch_order)
{
	/* jyyang: add for Merlin2 RGBW (20160616) */
	// fmt = format,  0:RGB, 1:RGBW
	// loc = location,  0: After Demura (RGB),	1: After HCIC/FCIC (RGB or RGBW)
	// ch_order = channel order, only available when (fmt=1 && loc=1)
	#if 0 // mac5 no W channel
	unsigned char order_lst[2][8] = {
	// 0:even_R, 1:even_G, 2:even_B, 3:even_W, 4:odd_R, 5:odd_G, 6:odd_B, 7:odd_W,
	/*0*/{ 0, 1, 2, 3, 2, 3, 0, 1,}, // hw default
	/*1*/{ 2, 3, 0, 1, 0, 1, 2, 3,},
	};
	unsigned char order_sel[8];
	memcpy(order_sel, &order_lst[ch_order][0], sizeof(order_sel));

	if(Get_DISPLAY_PANEL_TYPE() == P_VBY1_TO_LVDS_2K){
		return;
	}
	#endif
	outputgamma_out_gamma_ctrl_1_RBUS outputgamma_out_gamma_ctrl_1_reg;
	outputgamma_out_gamma_ctrl_1_reg.regValue = IoReg_Read32(OUTPUTGAMMA_OUT_GAMMA_CTRL_1_reg);
	outputgamma_out_gamma_ctrl_1_reg.out_gamma_en = Enable;
	IoReg_Write32(OUTPUTGAMMA_OUT_GAMMA_CTRL_1_reg, outputgamma_out_gamma_ctrl_1_reg.regValue);
	#if 0 // mac5 no W channel
	outputgamma_out_gamma_ctrl_2_RBUS out_gamma_ctrl_2_REG;
	out_gamma_ctrl_2_REG.regValue = IoReg_Read32(OUTPUTGAMMA_OUT_GAMMA_CTRL_2_reg);
	out_gamma_ctrl_2_REG.out_gamma_format =  fmt; // 0:RGB, 1:RGBW
	out_gamma_ctrl_2_REG.out_gamma_location =  loc; // 0: After Demura (RGB),	1: After HCIC/FCIC (RGB or RGBW)
	out_gamma_ctrl_2_REG.even_ch_r =  order_sel[0];
	out_gamma_ctrl_2_REG.even_ch_g = order_sel[1] ;
	out_gamma_ctrl_2_REG.even_ch_b =  order_sel[2];
	out_gamma_ctrl_2_REG.even_ch_w =  order_sel[3];
	out_gamma_ctrl_2_REG.odd_ch_r =  order_sel[4];
	out_gamma_ctrl_2_REG.odd_ch_g =  order_sel[5];
	out_gamma_ctrl_2_REG.odd_ch_b =  order_sel[6];
	out_gamma_ctrl_2_REG.odd_ch_w =  order_sel[7];

	IoReg_Write32(OUTPUTGAMMA_OUT_GAMMA_CTRL_2_reg, out_gamma_ctrl_2_REG.regValue);
	#endif
}

#ifdef MAC5_NO_RGBW
unsigned char drvif_color_Get_RGBW_Mode(void)
{
	char ret;
	ppoverlay_display_timing_ctrl2_RBUS display_timing_ctrl2_REG;
	display_timing_ctrl2_REG.regValue = IoReg_Read32(PPOVERLAY_Display_Timing_CTRL2_reg);
	ret = display_timing_ctrl2_REG.mplus_rgbw_en; /* use rgbw of 0:disable, 1:M+, 2:RTK, 4: BOE*/
	return ret;
}

void drvif_color_set_RGBW_cpc_be(unsigned char level1, unsigned char level2)
{
	// level1: cpc and be setting
	// level2: Log curve seeting
	int i;
	unsigned int tmp;
	short set1_lst[2][17] = {
	// 0:walpha_min, 1:walpha_max, 2:wlimit, 3:r_satalpha, 4:g_satalpha, 5:b_satalpha, 6:satalpha_offset, 7:saliency_alpha, 8:saliency_offset,
	//9:coef_a, 10:coef_b, 11:coef_c, 12:coef_d, 13:brightness_gain, 14:brightness_offset, 15:enhance_strength_gain, 16:enhance_strength_offset,
	/*0*/{ 16, 16, 0x3FF, 12, 24, 5, 0, 64, 0, 	8, -9, 0, 1, 24, 128, 32, 0,}, // hw default
	/*1*/{ 16, 16, 0x3FF, 12, 24, 5, 0, 64, 0, 	8, -1, 0, 1, 24, 128, 32, 0,},
	};
	unsigned int Log_curve_lst[2][39] = {
	// 0~7:log_sub_0~7, 8~38:log_main_2~32
	/*0*/{ 0x0, 0x92, 0xE8, 0x125, 0x154, 0x17A, 0x19B, 0x1B7, 0x1D0, 0x21D, 0x256, 0x283, 0x2A7, 0x2C7, 0x2E2, 0x2FA, 0x310, 0x323, 0x335, 0x346, 0x355, 0x364, 0x371, 0x37E, 0x389, 0x395, 0x39F, 0x3AA, 0x3B3, 0x3BD, 0x3C5, 0x3CE, 0x3D6, 0x3DE, 0x3E6, 0x3ED, 0x3F4, 0x3FB, 0x3FF,}, // hw default
	/*1*/{ 0x0, 0x92, 0xE8, 0x125, 0x154, 0x17A, 0x19B, 0x1B7, 0x1D0, 0x21D, 0x256, 0x283, 0x2A7, 0x2C7, 0x2E2, 0x2FA, 0x310, 0x323, 0x335, 0x346, 0x355, 0x364, 0x371, 0x37E, 0x389, 0x395, 0x39F, 0x3AA, 0x3B3, 0x3BD, 0x3C5, 0x3CE, 0x3D6, 0x3DE, 0x3E6, 0x3ED, 0x3F4, 0x3FB, 0x3FF,},
	};

	short set1_sel[17];
	memcpy(set1_sel, &set1_lst[level1][0], sizeof(set1_sel));

	rgbw_d_rgbw_cpc_1_RBUS rgbw_d_rgbw_cpc_1_REG;
	rgbw_d_rgbw_cpc_2_RBUS rgbw_d_rgbw_cpc_2_REG;
	rgbw_d_rgbw_cpc_3_RBUS rgbw_d_rgbw_cpc_3_REG;
	rgbw_d_rgbw_cpc_4_RBUS rgbw_d_rgbw_cpc_4_REG;
	rgbw_d_rgbw_be_1_RBUS rgbw_d_rgbw_be_1_REG;
	rgbw_d_rgbw_be_2_RBUS rgbw_d_rgbw_be_2_REG;

	rgbw_d_rgbw_cpc_1_REG.regValue= IoReg_Read32(RGBW_D_RGBW_CPC_1_reg);
	rgbw_d_rgbw_cpc_2_REG.regValue = IoReg_Read32(RGBW_D_RGBW_CPC_2_reg);
	rgbw_d_rgbw_cpc_3_REG.regValue = IoReg_Read32(RGBW_D_RGBW_CPC_3_reg);
	rgbw_d_rgbw_cpc_4_REG.regValue = IoReg_Read32(RGBW_D_RGBW_CPC_4_reg);
	rgbw_d_rgbw_be_1_REG.regValue = IoReg_Read32(RGBW_D_RGBW_BE_1_reg);
	rgbw_d_rgbw_be_2_REG.regValue = IoReg_Read32(RGBW_D_RGBW_BE_2_reg);

	rgbw_d_rgbw_cpc_1_REG.cpc_walpha_min = set1_sel[0];
	rgbw_d_rgbw_cpc_1_REG.cpc_walpha_max = set1_sel[1];
	rgbw_d_rgbw_cpc_2_REG.cpc_wlimit = set1_sel[2];
	rgbw_d_rgbw_cpc_1_REG.cpc_r_satalpha = set1_sel[3];
	rgbw_d_rgbw_cpc_1_REG.cpc_g_satalpha = set1_sel[4];
	rgbw_d_rgbw_cpc_2_REG.cpc_b_satalpha = set1_sel[5];
	rgbw_d_rgbw_cpc_2_REG.cpc_satalpha_offset = set1_sel[6];
	rgbw_d_rgbw_cpc_3_REG.cpc_saliency_alpha = set1_sel[7];
	rgbw_d_rgbw_cpc_3_REG.cpc_saliency_offset = set1_sel[8];
	rgbw_d_rgbw_cpc_4_REG.cpc_coef_a = set1_sel[9]&0x1f;
	rgbw_d_rgbw_cpc_4_REG.cpc_coef_b = set1_sel[10]&0x1f; // (c<15)?c:c-32;
	rgbw_d_rgbw_cpc_4_REG.cpc_coef_c = set1_sel[11]&0x1f;
	rgbw_d_rgbw_cpc_4_REG.cpc_coef_d = set1_sel[12]&0x1f;
	rgbw_d_rgbw_be_1_REG.brightness_gain = set1_sel[13];
	rgbw_d_rgbw_be_1_REG.brightness_offset = set1_sel[14];
	rgbw_d_rgbw_be_2_REG.enhance_strength_gain = set1_sel[15];
	rgbw_d_rgbw_be_2_REG.enhance_strength_offset = set1_sel[16];

	IoReg_Write32(RGBW_D_RGBW_CPC_1_reg, rgbw_d_rgbw_cpc_1_REG.regValue);
	IoReg_Write32(RGBW_D_RGBW_CPC_2_reg, rgbw_d_rgbw_cpc_2_REG.regValue);
	IoReg_Write32(RGBW_D_RGBW_CPC_3_reg, rgbw_d_rgbw_cpc_3_REG.regValue);
	IoReg_Write32(RGBW_D_RGBW_CPC_4_reg, rgbw_d_rgbw_cpc_4_REG.regValue);
	IoReg_Write32(RGBW_D_RGBW_BE_1_reg, rgbw_d_rgbw_be_1_REG.regValue);
	IoReg_Write32(RGBW_D_RGBW_BE_2_reg, rgbw_d_rgbw_be_2_REG.regValue);

	for(i = 0; i<13; i++)
	{
		tmp = ((Log_curve_lst[level2][i*3]&0x3FF)<<20)+((Log_curve_lst[level2][i*3+1]&0x3FF)<<10)+(Log_curve_lst[level2][i*3+2]&0x3FF);
		IoReg_Write32(RGBW_D_RGBW_LOG_CURVE_1_reg + 4*i, tmp);
	}
}
void drvif_color_set_RGBW_coef(unsigned char mode, unsigned char ch_order)
{
	int i;
	unsigned int tmp1, tmp2;
	unsigned char order_lst[2][8] = {
	// 0:even_R, 1:even_G, 2:even_B, 3:even_W, 4:odd_R, 5:odd_G, 6:odd_B, 7:odd_W,
	/*0*/{ 0, 1, 2, 3, 2, 3, 0, 1,}, // hw default
	/*1*/{ 2, 3, 0, 1, 0, 1, 2, 3,},
	};

	short rgbw_spr_coef_default[3][8] = {
		{ -1, 4, -15, 52, 103, -21, 8, -2,},
		{ 0, 0, 0, 0, 128, 0, 0, 0,},
		{ -2, 8, -21, 103, 52, -15, 4, -1,},
	};

	unsigned char order_sel[8];
	memcpy(order_sel, &order_lst[ch_order][0], sizeof(order_sel));

	short rgbw_spr_coef_sel[3][8];
	memcpy(rgbw_spr_coef_sel, rgbw_spr_coef_default, sizeof(rgbw_spr_coef_sel));

	rgbw_d_rgbw_spr_order_RBUS rgbw_d_rgbw_spr_order_REG;

	rgbw_d_rgbw_spr_order_REG.regValue = IoReg_Read32(RGBW_D_RGBW_SPR_ORDER_reg);

	rgbw_d_rgbw_spr_order_REG.spr_coef_mode = mode; // 0:spatial mode, 1:color mode
	rgbw_d_rgbw_spr_order_REG.even_ch_r =  order_sel[0];
	rgbw_d_rgbw_spr_order_REG.even_ch_g = order_sel[1] ;
	rgbw_d_rgbw_spr_order_REG.even_ch_b =  order_sel[2];
	rgbw_d_rgbw_spr_order_REG.even_ch_w =  order_sel[3];
	rgbw_d_rgbw_spr_order_REG.odd_ch_r =  order_sel[4];
	rgbw_d_rgbw_spr_order_REG.odd_ch_g =  order_sel[5];
	rgbw_d_rgbw_spr_order_REG.odd_ch_b =  order_sel[6];
	rgbw_d_rgbw_spr_order_REG.odd_ch_w =  order_sel[7];

	IoReg_Write32(RGBW_D_RGBW_SPR_ORDER_reg, rgbw_d_rgbw_spr_order_REG.regValue);

	for(i = 0; i < 12; i++) // sub_pos = 0~11
	{
		tmp1 = (rgbw_spr_coef_sel[i%3][0]&0xFF<<24)+(rgbw_spr_coef_sel[i%3][1]&0xFF<<16)+(rgbw_spr_coef_sel[i%3][2]&0xFF<<8)+(rgbw_spr_coef_sel[i%3][3]&0xFF);
		tmp2 = (rgbw_spr_coef_sel[i%3][4]&0xFF<<24)+(rgbw_spr_coef_sel[i%3][5]&0xFF<<16)+(rgbw_spr_coef_sel[i%3][6]&0xFF<<8)+(rgbw_spr_coef_sel[i%3][7]&0xFF);
		IoReg_Write32(RGBW_D_RGBW_SPR_Ss0_COEF_0_reg+i*8, tmp1);
		IoReg_Write32(RGBW_D_RGBW_SPR_Ss0_COEF_1_reg+i*8, tmp2);
	}

}
void drvif_color_set_RGBW(void)
{
	/* jyyang: add for Merlin2 RGBW (20160616) */
	// Set RTK-RGBW
	drvif_color_set_RGBW_cpc_be(0, 0);
	drvif_color_set_RGBW_coef(0, 0);
	// Enable RTK-RGBW
	ppoverlay_display_timing_ctrl2_RBUS display_timing_ctrl2_REG;
	display_timing_ctrl2_REG.regValue = IoReg_Read32(PPOVERLAY_Display_Timing_CTRL2_reg);
	display_timing_ctrl2_REG.mplus_rgbw_en = 2; // use rgbw of 0:disable, 1:M+, 2:RTK, 4: BOE
	IoReg_Write32(PPOVERLAY_Display_Timing_CTRL2_reg, display_timing_ctrl2_REG.regValue);
}
void drvif_color_set_BOE_RGBW(unsigned short *ptr_tab, int w_rate)
{
	// w_rate = 0:addr +1, 1:addr +2, 2:addr +4
	/* jyyang: add for Merlin2 BOE-RGBW (20160624) */
	short i, cnt;
	dispd_boe_rgbw_mcu_control_RBUS dispd_boe_rgbw_mcu_control_REG;
	dispd_boe_rgbw_mcu_st_RBUS dispd_boe_rgbw_mcu_st_RBEG;
	ppoverlay_display_timing_ctrl1_RBUS display_timing_ctrl1_REG;
	ppoverlay_display_timing_ctrl2_RBUS display_timing_ctrl2_REG;
	dispd_boe_rgbw_apb_latency_RBUS dispd_boe_rgbw_apb_latency_REG;
	od_dma_oddma_pq_cmp_pair_RBUS od_dma_oddma_pq_cmp_pair_REG;
	dispd_boe_rgbw_apb_w_control_RBUS dispd_boe_rgbw_apb_w_control_REG;
	dispd_boe_rgbw_apb_w_data_RBUS dispd_boe_rgbw_apb_w_data_REG;
	sys_reg_sys_srst3_RBUS sys_reg_sys_srst3_REG;
	sys_reg_sys_clken3_RBUS sys_reg_sys_clken3_REG;

	// === Interrupt Trigger=== (Start)
		// 0xC008 = 0x10(MCU Suspend On)
	dispd_boe_rgbw_apb_w_control_REG.regValue = IoReg_Read32(DISPD_BOE_RGBW_APB_w_control_reg);
	dispd_boe_rgbw_apb_w_data_REG.regValue = IoReg_Read32(DISPD_BOE_RGBW_APB_w_data_reg);

	dispd_boe_rgbw_apb_w_control_REG.apb_w_mode = 0; //	0:addr +1, 1:addr +2, 2:addr +4
	dispd_boe_rgbw_apb_w_control_REG.apb_w_addr= 0xc008;
	dispd_boe_rgbw_apb_w_data_REG.apb_w_data0 = 0x10;
	IoReg_Write32(DISPD_BOE_RGBW_APB_w_control_reg, dispd_boe_rgbw_apb_w_control_REG.regValue);
	IoReg_Write32(DISPD_BOE_RGBW_APB_w_data_reg, dispd_boe_rgbw_apb_w_data_REG.regValue);

		// int_in=0 -> wait status=1 -> int_in=1
	dispd_boe_rgbw_mcu_control_REG.regValue = IoReg_Read32(DISPD_BOE_RGBW_mcu_control_reg);
	dispd_boe_rgbw_mcu_control_REG.mcu_int_in = 0;
	IoReg_Write32(DISPD_BOE_RGBW_mcu_control_reg, dispd_boe_rgbw_mcu_control_REG.regValue);
	cnt = 10000;
	do{ // wait b802EC20[24]=1
		dispd_boe_rgbw_mcu_st_RBEG.regValue = IoReg_Read32(DISPD_BOE_RGBW_mcu_st_reg);
	}while((cnt--) && dispd_boe_rgbw_mcu_st_RBEG.mcu_int_st == 0);
	dispd_boe_rgbw_mcu_control_REG.mcu_int_in = 1;
	IoReg_Write32(DISPD_BOE_RGBW_mcu_control_reg, dispd_boe_rgbw_mcu_control_REG.regValue);

		// 0xC008 = 0x10(MCU Suspend Off)
	dispd_boe_rgbw_apb_w_control_REG.regValue = IoReg_Read32(DISPD_BOE_RGBW_APB_w_control_reg);
	dispd_boe_rgbw_apb_w_data_REG.regValue = IoReg_Read32(DISPD_BOE_RGBW_APB_w_data_reg);

	dispd_boe_rgbw_apb_w_control_REG.apb_w_mode = 0; //	0:addr +1, 1:addr +2, 2:addr +4
	dispd_boe_rgbw_apb_w_control_REG.apb_w_addr= 0xc008;
	dispd_boe_rgbw_apb_w_data_REG.apb_w_data0 = 0x00;
	IoReg_Write32(DISPD_BOE_RGBW_APB_w_control_reg, dispd_boe_rgbw_apb_w_control_REG.regValue);
	IoReg_Write32(DISPD_BOE_RGBW_APB_w_data_reg, dispd_boe_rgbw_apb_w_data_REG.regValue);
	// === Interrupt Trigger=== (End)

	// === CRT reset off===
	/*
	sys_reg_sys_srst3_REG.regValue = IoReg_Read32(SYS_REG_SYS_SRST3_reg);
	sys_reg_sys_clken3_REG.regValue = IoReg_Read32(SYS_REG_SYS_CLKEN3_reg);
		// flow: clk_on -> rst_off -> clk_off -> rst_on -> clk_on
	sys_reg_sys_clken3_REG.clken_d_boe_rgbw_mcu = 1;
	sys_reg_sys_clken3_REG.write_data = 1;
	IoReg_Write32(SYS_REG_SYS_CLKEN3_reg, sys_reg_sys_clken3_REG.regValue);
	sys_reg_sys_srst3_REG.rstn_d_boe_rgbw_mcu = 1;
	sys_reg_sys_srst3_REG.write_data = 0;
	IoReg_Write32(SYS_REG_SYS_SRST3_reg, sys_reg_sys_srst3_REG.regValue);
	sys_reg_sys_clken3_REG.clken_d_boe_rgbw_mcu = 1;
	sys_reg_sys_clken3_REG.write_data = 0;
	IoReg_Write32(SYS_REG_SYS_CLKEN3_reg, sys_reg_sys_clken3_REG.regValue);
	*/
	rtd_outl(SYS_REG_SYS_CLKEN3_reg, SYS_REG_SYS_CLKEN3_clken_d_boe_rgbw_mcu_mask | SYS_REG_SYS_CLKEN3_write_data_mask);
	rtd_outl(SYS_REG_SYS_SRST3_reg, SYS_REG_SYS_SRST3_rstn_d_boe_rgbw_mcu_mask);
	rtd_outl(SYS_REG_SYS_CLKEN3_reg, SYS_REG_SYS_CLKEN3_clken_d_boe_rgbw_mcu_mask);

	// === Enable BOE-RGBW ===
	display_timing_ctrl1_REG.regValue = IoReg_Read32(PPOVERLAY_Display_Timing_CTRL1_reg);
	display_timing_ctrl2_REG.regValue = IoReg_Read32(PPOVERLAY_Display_Timing_CTRL2_reg);
	dispd_boe_rgbw_apb_latency_REG.regValue = IoReg_Read32(DISPD_BOE_RGBW_APB_latency_reg);
	od_dma_oddma_pq_cmp_pair_REG.regValue = IoReg_Read32(OD_DMA_ODDMA_PQ_CMP_PAIR);

		// flow: disp_en off -> eco_clk on ->rgbw_en on -> self latency check on -> disp_en on
	display_timing_ctrl1_REG.disp_en = 0;
	IoReg_Write32(PPOVERLAY_Display_Timing_CTRL1_reg, display_timing_ctrl1_REG.regValue);

	od_dma_oddma_pq_cmp_pair_REG.eco_reg_boe_clk_inv = 1;
	IoReg_Write32(OD_DMA_ODDMA_PQ_CMP_PAIR, od_dma_oddma_pq_cmp_pair_REG.regValue);

	display_timing_ctrl2_REG.mplus_rgbw_en = 4; // use rgbw of 0:disable, 1:M+, 2:RTK, 4: BOE
	IoReg_Write32(PPOVERLAY_Display_Timing_CTRL2_reg, display_timing_ctrl2_REG.regValue);

	dispd_boe_rgbw_apb_latency_REG.self_deno_chk_en = 1;
	dispd_boe_rgbw_apb_latency_REG.latency_golden= 0x31;
	IoReg_Write32(DISPD_BOE_RGBW_APB_latency_reg, dispd_boe_rgbw_apb_latency_REG.regValue);

	display_timing_ctrl1_REG.disp_en = 1;
	IoReg_Write32(PPOVERLAY_Display_Timing_CTRL1_reg, display_timing_ctrl1_REG.regValue);

	// === MCU <-> SoC ===
	dispd_boe_rgbw_apb_w_control_REG.regValue = IoReg_Read32(DISPD_BOE_RGBW_APB_w_control_reg);
	dispd_boe_rgbw_apb_w_data_REG.regValue = IoReg_Read32(DISPD_BOE_RGBW_APB_w_data_reg);
		// 0xC000 = 0x0(Reset MCU)
	dispd_boe_rgbw_apb_w_control_REG.apb_w_mode = 0; //	0:addr +1, 1:addr +2, 2:addr +4
	dispd_boe_rgbw_apb_w_control_REG.apb_w_addr= 0xc000;
	dispd_boe_rgbw_apb_w_data_REG.apb_w_data0 = 0;
	IoReg_Write32(DISPD_BOE_RGBW_APB_w_control_reg, dispd_boe_rgbw_apb_w_control_REG.regValue);
	IoReg_Write32(DISPD_BOE_RGBW_APB_w_data_reg, dispd_boe_rgbw_apb_w_data_REG.regValue);
		// 0xC001 = 0x0(Control to SOC)
	dispd_boe_rgbw_apb_w_control_REG.apb_w_mode = 0; //	0:addr +1, 1:addr +2, 2:addr +4
	dispd_boe_rgbw_apb_w_control_REG.apb_w_addr= 0xc001;
	dispd_boe_rgbw_apb_w_data_REG.apb_w_data0 = 0;
	IoReg_Write32(DISPD_BOE_RGBW_APB_w_control_reg, dispd_boe_rgbw_apb_w_control_REG.regValue);
	IoReg_Write32(DISPD_BOE_RGBW_APB_w_data_reg, dispd_boe_rgbw_apb_w_data_REG.regValue);

	// === write table 0~0x7dff ===
	dispd_boe_rgbw_apb_w_control_REG.apb_w_mode = w_rate; //	0:addr +1, 1:addr +2, 2:addr +4
	dispd_boe_rgbw_apb_w_control_REG.apb_w_addr= 0x0000;
	IoReg_Write32(DISPD_BOE_RGBW_APB_w_control_reg, dispd_boe_rgbw_apb_w_control_REG.regValue);
	if(w_rate == 1)
	{
		for(i = 0; i < 16128; i++)
		{
			dispd_boe_rgbw_apb_w_data_REG.apb_w_data0 = ptr_tab[i]&0xff;
			dispd_boe_rgbw_apb_w_data_REG.apb_w_data1 = (ptr_tab[i]>>8)&0xff;
			IoReg_Write32(DISPD_BOE_RGBW_APB_w_data_reg, dispd_boe_rgbw_apb_w_data_REG.regValue);
		}
	}
	else if(w_rate == 2)
	{
		for(i = 0; i < 8064; i++)
		{
			dispd_boe_rgbw_apb_w_data_REG.apb_w_data0 = ptr_tab[2*i]&0xff;
			dispd_boe_rgbw_apb_w_data_REG.apb_w_data1 = (ptr_tab[2*i]>>8)&0xff;
			dispd_boe_rgbw_apb_w_data_REG.apb_w_data2 = ptr_tab[2*i+1]&0xff;
			dispd_boe_rgbw_apb_w_data_REG.apb_w_data3 = (ptr_tab[2*i+1]>>8)&0xff;
			IoReg_Write32(DISPD_BOE_RGBW_APB_w_data_reg, dispd_boe_rgbw_apb_w_data_REG.regValue);
		}
	}

	// === MCU <-> SoC ===
		// C001 = 7; (Control to MCU)
	dispd_boe_rgbw_apb_w_control_REG.apb_w_mode = 0; //	0:addr +1, 1:addr +2, 2:addr +4
	dispd_boe_rgbw_apb_w_control_REG.apb_w_addr= 0xc001;
	dispd_boe_rgbw_apb_w_data_REG.apb_w_data0 = 7;
	IoReg_Write32(DISPD_BOE_RGBW_APB_w_control_reg, dispd_boe_rgbw_apb_w_control_REG.regValue);
	IoReg_Write32(DISPD_BOE_RGBW_APB_w_data_reg, dispd_boe_rgbw_apb_w_data_REG.regValue);
		// wait V-blank
		// C000 = 1; (Reset MCU)
	dispd_boe_rgbw_apb_w_control_REG.apb_w_mode = 0; //	0:addr +1, 1:addr +2, 2:addr +4
	dispd_boe_rgbw_apb_w_control_REG.apb_w_addr= 0xc000;
	dispd_boe_rgbw_apb_w_data_REG.apb_w_data0 = 1;
	IoReg_Write32(DISPD_BOE_RGBW_APB_w_control_reg, dispd_boe_rgbw_apb_w_control_REG.regValue);
	IoReg_Write32(DISPD_BOE_RGBW_APB_w_data_reg, dispd_boe_rgbw_apb_w_data_REG.regValue);

	// === CRT reset on===
	/*
	sys_reg_sys_srst3_REG.regValue = IoReg_Read32(SYS_REG_SYS_SRST3_reg);
	sys_reg_sys_clken3_REG.regValue = IoReg_Read32(SYS_REG_SYS_CLKEN3_reg);

		// flow: rst_on -> clk_on
	sys_reg_sys_srst3_REG.rstn_d_boe_rgbw_mcu = 1;
	sys_reg_sys_srst3_REG.write_data = 1;
	IoReg_Write32(SYS_REG_SYS_SRST3_reg, sys_reg_sys_srst3_REG.regValue);
	sys_reg_sys_clken3_REG.clken_d_boe_rgbw_mcu = 1;
	sys_reg_sys_clken3_REG.write_data = 1;
	IoReg_Write32(SYS_REG_SYS_CLKEN3_reg, sys_reg_sys_clken3_REG.regValue);
	*/

	rtd_outl(SYS_REG_SYS_SRST3_reg, SYS_REG_SYS_SRST3_rstn_d_boe_rgbw_mcu_mask | SYS_REG_SYS_SRST3_write_data_mask);
	rtd_outl(SYS_REG_SYS_CLKEN3_reg, SYS_REG_SYS_CLKEN3_clken_d_boe_rgbw_mcu_mask | SYS_REG_SYS_CLKEN3_write_data_mask);


}
#endif

/*============================================================================*/
/**
 * Color_WriteGamma
 * This function is used to write gamma table in single channel
 *
 * @param <pArray> 	{ gamma table lut}
 * @return 			{ void }
 *
 */

void drvif_color_colorwritegamma(unsigned int *pArray)
{
#ifdef TEST_SKIP_WRITE_GAMMA
	return;
#endif
	/*VIPprintf("gamma start ===================\n");*/
	unsigned short ii, cnt = 10000;
	gamma_gamma_port_RBUS gamma_port_REG;
	gamma_gamma_ctrl_1_RBUS gamma_ctrl_1_REG;
	unsigned char status = 1;

	/*Thur modified for compile 20090113*/
	/*IoReg_BusyCheckRegBit(DDOMAIN_MAIN_DISPLAY_CONTROL_RSV_VADDR,_BIT10, 0x0001FFFF);*/
	/*frank@0902 mark to speed code */ /*IoReg_BusyCheckRegBit(PPOVERLAY_Main_Display_Control_RSV_reg,_BIT10, 0x0001FFFF);*/
	/*ROS_ENTER_CRITICAL();*/

	/*rtdf_clearBits(GAMMA_GAMMA_CTRL_1_reg, _BIT6);*/
	gamma_ctrl_1_REG.regValue = IoReg_Read32(GAMMA_GAMMA_CTRL_1_reg);
	/*gamma_ctrl_1_REG.gamma_ax_tab_sel = 0;*/ /* write table1 [jyyang@ Mac3] only main channel and one 512 table*/
	IoReg_Write32(GAMMA_GAMMA_CTRL_1_reg, gamma_ctrl_1_REG.regValue);

	for (ii = 0; ii < 512; ii++) { /* Num of index: Mac2 = 128, Sirius = 512 (jyyang_2013/12/25)*/

		#if 0
		if (ii == 256) {
			gamma_ctrl_1_REG.regValue = IoReg_Read32(GAMMA_GAMMA_CTRL_1_reg);
			gamma_ctrl_1_REG.gamma_ax_tab_sel = 1;/* write table2*/
			IoReg_Write32(GAMMA_GAMMA_CTRL_1_reg, gamma_ctrl_1_REG.regValue);
		} /*[jyyang@ Mac3] only main channel and one 512 table*/
		#endif
		status = 1;
		cnt = 10000;
		/*
		gamma_port_REG.index 	= (pArray[ii*3] << 2) + ((pArray[ii*3 + 1] >> 6)&0x03);
		gamma_port_REG.d0 		= pArray[ii*3 + 1]&0x1f;
		gamma_port_REG.d1 		= pArray[ii*3 + 2]&0x1f;
		*/
		gamma_port_REG.regValue = pArray[ii];
		/*if (ii % 31 == 0)*/
			/*VIPprintf("GAMMA[%d] = 0x%x\n", ii, pArray[ii]);*/
		IoReg_Write32(GAMMA_GAMMA_PORT_reg, gamma_port_REG.regValue);

		while ((cnt--) && (status) && ((ii % 16) == 15)) { /*20071217 jason(jeffery) modified*/

			gamma_ctrl_1_REG.regValue = IoReg_Read32(GAMMA_GAMMA_CTRL_1_reg);
			status =  (gamma_ctrl_1_REG.gamma_fifo_empty == 1) ? 0 : 1;
		}
	}
	/*VIPprintf("gamma end ===================\n");*/
	/*ROS_EXIT_CRITICAL();*/
}

void drvif_color_colorwrite_gamma_HDR(unsigned int *pArray, unsigned int channel) // Merlin jyyang 20150616
{
	// pArray: unsigned int grids[1025] (decode HDR data)
	// channel: 0:R, 1:G, 2:B, 3:All
#ifdef TEST_SKIP_WRITE_GAMMA
	return;
#endif
	unsigned short ii, jj, cnt = 10000;
	gamma_gamma_port_RBUS gamma_port_REG;
	gamma_gamma_ctrl_1_RBUS gamma_ctrl_1_REG;
	gamma_gamma_ctrl_2_RBUS gamma_ctrl_2_REG;
	gamma_gamma_ctrl_3_RBUS gamma_ctrl_3_REG;
	unsigned char status = 1;
	int i0, d0, d1, ecData;
	int d0msb;

	// Enable Write
	gamma_ctrl_1_REG.regValue = IoReg_Read32(GAMMA_GAMMA_CTRL_1_reg);
	gamma_ctrl_2_REG.regValue = IoReg_Read32(GAMMA_GAMMA_CTRL_2_reg);
	gamma_ctrl_1_REG.gamma_ax_ch_sel = channel; // 0:R, 1:G, 2:B, 3:All
	gamma_ctrl_1_REG.gamma_ax_rw_sel= 1; // 0:x, 1:w, 2:r
	gamma_ctrl_2_REG.gamma_m_tab_sel= 0;
	//gamma_ctrl_2_REG.gamma_tab_size_sel= 0; // 0:512, 1:256 //jyyang20161215
	IoReg_Write32(GAMMA_GAMMA_CTRL_1_reg, gamma_ctrl_1_REG.regValue);
	IoReg_Write32(GAMMA_GAMMA_CTRL_2_reg, gamma_ctrl_2_REG.regValue);

	d0msb = pArray[1]-pArray[0];
	if(d0msb > 0)
		d0msb = d0msb >> 8;
	else
		d0msb = 0;

	for (ii = 0; ii < 512; ii++) {

		// Encode Data
		jj = ii*2;
		i0 = pArray[jj];
		d0 = pArray[jj+1]-pArray[jj];
		d1 = pArray[jj+2]-pArray[jj+1];

		if(ii == 0)
			d0 = d0 - d0msb*256;

		if(d0 < 0)
			d0 = 0;
		else if(d0 > 255)
			d0 = 255;
		if(d1 < 0)
			d1 = 0;
		else if(d1 > 255)
			d1 = 255;

		ecData = (i0 << 16) + (d0 << 8) + d1;

		status = 1;
		cnt = 10000;

		gamma_port_REG.regValue = ecData;

		IoReg_Write32(GAMMA_GAMMA_PORT_reg, gamma_port_REG.regValue);

		while ((cnt--) && (status) && ((ii % 16) == 15)) { /*20071217 jason(jeffery) modified*/

			gamma_ctrl_1_REG.regValue = IoReg_Read32(GAMMA_GAMMA_CTRL_1_reg);
			status =  (gamma_ctrl_1_REG.gamma_fifo_empty == 1) ? 0 : 1;
		}
	}

	gamma_ctrl_3_REG.regValue = IoReg_Read32(GAMMA_GAMMA_CTRL_3_reg);
	if(channel == 0)
		gamma_ctrl_3_REG.gamma_msb_d0_r = d0msb;
	else if(channel == 1)
		gamma_ctrl_3_REG.gamma_msb_d0_g = d0msb;
	else if(channel == 2)
		gamma_ctrl_3_REG.gamma_msb_d0_b = d0msb;
	else if(channel == 3) // All channel
	{
		gamma_ctrl_3_REG.gamma_msb_d0_r = d0msb;
		gamma_ctrl_3_REG.gamma_msb_d0_g = d0msb;
		gamma_ctrl_3_REG.gamma_msb_d0_b = d0msb;
	}
	IoReg_Write32(GAMMA_GAMMA_CTRL_3_reg, gamma_ctrl_3_REG.regValue);

	// Disable Write
	gamma_ctrl_1_REG.regValue = IoReg_Read32(GAMMA_GAMMA_CTRL_1_reg);
	gamma_ctrl_1_REG.gamma_ax_rw_sel= 0; // 0:x, 1:w, 2:r
	IoReg_Write32(GAMMA_GAMMA_CTRL_1_reg, gamma_ctrl_1_REG.regValue);
}
void drvif_color_colorwrite_invGamma(unsigned int *pArray) /*add for Sirius (jyyang_2013/12/25)*/
{
#ifdef TEST_SKIP_WRITE_GAMMA
	return;
#endif
	/*VIPprintf("gamma start ===================\n");*/
	unsigned short ii, cnt = 10000;
	inv_gamma_inv_gamma_port_RBUS inv_gamma_port_REG;
	inv_gamma_inv_gamma_ctrl_1_RBUS inv_gamma_ctrl_1_REG;
	unsigned char status = 1;

	inv_gamma_ctrl_1_REG.regValue = IoReg_Read32(INV_GAMMA_INV_GAMMA_CTRL_1_reg);
	/* inv_gamma_ctrl_1_REG.inv_gamma_ax_tab_sel = 0;*/ /* write table1  [jyyang@ Mac3] only main channel and one 512 table*/
	IoReg_Write32(INV_GAMMA_INV_GAMMA_CTRL_1_reg, inv_gamma_ctrl_1_REG.regValue);

	for (ii = 0; ii < 512; ii++) { /* Num of index: Mac2 = 128, Sirius = 512 (jyyang_2013/12/25)*/
		#if 0
		if (ii == 256) {
			inv_gamma_ctrl_1_REG.regValue = IoReg_Read32(INV_GAMMA_INV_GAMMA_CTRL_1_reg);
			inv_gamma_ctrl_1_REG.inv_gamma_ax_tab_sel = 1;/* write table2*/
			IoReg_Write32(INV_GAMMA_INV_GAMMA_CTRL_1_reg, inv_gamma_ctrl_1_REG.regValue);
		} /*  [jyyang@ Mac3] only main channel and one 512 table*/
		#endif
		status = 1;
		cnt = 10000;
		inv_gamma_port_REG.regValue = pArray[ii];
		/*VIPprintf("=====================%d ==== 6\n", pArray[ii]);*/
		IoReg_Write32(INV_GAMMA_INV_GAMMA_PORT_reg, inv_gamma_port_REG.regValue);

		while ((cnt--) && (status) && ((ii % 16) == 15)) {/*20071217 jason(jeffery) modified*/
			inv_gamma_ctrl_1_REG.regValue = IoReg_Read32(INV_GAMMA_INV_GAMMA_CTRL_1_reg);
			status =  (inv_gamma_ctrl_1_REG.inv_gamma_fifo_empty == 1) ? 0 : 1;
		}
	}

	/*VIPprintf("gamma end ===================\n");*/
	/*ROS_EXIT_CRITICAL();*/
}

void drvif_color_setinvGamma_xvYCC(unsigned char display, unsigned char Mode)
{
	static UINT32 invGammaFull_xvycc[512] = {
		0x00001313, 0x00261313, 0x004c1313, 0x00721313, 0x00981312, 0x00bd1312, 0x00e21312, 0x01071213,
		0x012c1212, 0x01501212, 0x01741212, 0x01981212, 0x01bc1112, 0x01df1211, 0x02021211, 0x02251211,
		0x02481111, 0x026a1111, 0x028c1111, 0x02ae1111, 0x02d01110, 0x02f11111, 0x03131011, 0x03341010,
		0x03541110, 0x03751010, 0x03951010, 0x03b51010, 0x03d5100f, 0x03f41010, 0x04140f10, 0x04330f10,
		0x04520f0f, 0x04700f0f, 0x048e100f, 0x04ad0f0e, 0x04ca0f0f, 0x04e80f0e, 0x05050f0f, 0x05230e0f,
		0x05400e0e, 0x055c0f0e, 0x05790e0e, 0x05950e0e, 0x05b10e0e, 0x05cd0e0d, 0x05e80e0e, 0x06040d0e,
		0x061f0d0d, 0x06390e0d, 0x06540d0d, 0x066e0d0e, 0x06890d0c, 0x06a20d0d, 0x06bc0d0d, 0x06d60c0d,
		0x06ef0c0d, 0x07080c0d, 0x07210c0c, 0x07390c0c, 0x07510c0c, 0x07690c0c, 0x07810c0c, 0x07990c0b,
		0x07b00c0b, 0x07c70c0b, 0x07de0c0b, 0x07f50b0c, 0x080c0b0b, 0x08220b0b, 0x08380b0b, 0x084e0b0a,
		0x08630b0b, 0x08790a0b, 0x088e0a0b, 0x08a30a0b, 0x08b80a0a, 0x08cc0a0a, 0x08e00a0a, 0x08f40a0a,
		0x09080a0a, 0x091c0a09, 0x092f0a09, 0x09420a09, 0x09550a09, 0x0968090a, 0x097b0909, 0x098d0909,
		0x099f0909, 0x09b10909, 0x09c30809, 0x09d40908, 0x09e50908, 0x09f60908, 0x0a070908, 0x0a180808,
		0x0a280808, 0x0a380808, 0x0a480808, 0x0a580808, 0x0a680708, 0x0a770807, 0x0a860807, 0x0a950708,
		0x0aa40707, 0x0ab20708, 0x0ac10707, 0x0acf0707, 0x0add0607, 0x0aea0707, 0x0af80607, 0x0b050706,
		0x0b120607, 0x0b1f0607, 0x0b2c0606, 0x0b380606, 0x0b440606, 0x0b500606, 0x0b5c0606, 0x0b680605,
		0x0b730606, 0x0b7f0506, 0x0b8a0506, 0x0b950505, 0x0b9f0506, 0x0baa0505, 0x0bb40505, 0x0bbe0505,
		0x0bc80505, 0x0bd20405, 0x0bdb0504, 0x0be40505, 0x0bee0405, 0x0bf70404, 0x0bff0504, 0x0c080404,
		0x0c100404, 0x0c180404, 0x0c200404, 0x0c280404, 0x0c300403, 0x0c370404, 0x0c3f0304, 0x0c460304,
		0x0c4d0303, 0x0c530403, 0x0c5a0303, 0x0c600303, 0x0c660303, 0x0c6c0303, 0x0c720303, 0x0c780302,
		0x0c7d0303, 0x0c830203, 0x0c880203, 0x0c8d0203, 0x0c920202, 0x0c960203, 0x0c9b0202, 0x0c9f0202,
		0x0ca30202, 0x0ca70202, 0x0cab0202, 0x0caf0202, 0x0cb30201, 0x0cb60202, 0x0cba0202, 0x0cbe0202,
		0x0cc20202, 0x0cc60202, 0x0cca0202, 0x0cce0202, 0x0cd20202, 0x0cd60202, 0x0cda0202, 0x0cde0102,
		0x0ce10202, 0x0ce50202, 0x0ce90202, 0x0ced0202, 0x0cf10202, 0x0cf50202, 0x0cf90202, 0x0cfd0202,
		0x0d010202, 0x0d050201, 0x0d080202, 0x0d0c0202, 0x0d100202, 0x0d140203, 0x0d190202, 0x0d1d0203,
		0x0d220202, 0x0d260302, 0x0d2b0302, 0x0d300303, 0x0d360203, 0x0d3b0303, 0x0d410303, 0x0d470303,
		0x0d4d0303, 0x0d530303, 0x0d590304, 0x0d600303, 0x0d660403, 0x0d6d0403, 0x0d740403, 0x0d7b0404,
		0x0d830404, 0x0d8b0304, 0x0d920404, 0x0d9a0404, 0x0da20504, 0x0dab0404, 0x0db30504, 0x0dbc0405,
		0x0dc50405, 0x0dce0504, 0x0dd70505, 0x0de10505, 0x0deb0405, 0x0df40505, 0x0dfe0605, 0x0e090505,
		0x0e130506, 0x0e1e0506, 0x0e290506, 0x0e340506, 0x0e3f0605, 0x0e4a0606, 0x0e560606, 0x0e620606,
		0x0e6e0606, 0x0e7a0607, 0x0e870606, 0x0e930706, 0x0ea00706, 0x0ead0706, 0x0eba0707, 0x0ec80706,
		0x0ed50707, 0x0ee30707, 0x0ef10708, 0x0f000707, 0x0f0e0708, 0x0f1d0708, 0x0f2c0708, 0x0f3b0708,
		0x0f4a0808, 0x0f5a0708, 0x0f690808, 0x0f790808, 0x0f890908, 0x0f9a0808, 0x0faa0908, 0x0fbb0908,
		0x0fcc0908, 0x0fdd0909, 0x0fef0908, 0x10000909, 0x10120909, 0x1024090a, 0x10370909, 0x1049090a,
		0x105c090a, 0x106f090a, 0x10820a09, 0x10950a0a, 0x10a90a0a, 0x10bd0a0a, 0x10d10a0a, 0x10e50a0a,
		0x10f90b0a, 0x110e0b0a, 0x11230b0a, 0x11380b0a, 0x114d0b0b, 0x11630b0b, 0x11790b0b, 0x118f0b0b,
		0x11a50b0c, 0x11bc0b0b, 0x11d20c0b, 0x11e90c0b, 0x12000c0c, 0x12180b0c, 0x122f0c0c, 0x12470c0c,
		0x125f0c0c, 0x12770d0c, 0x12900c0d, 0x12a90c0d, 0x12c20c0d, 0x12db0d0c, 0x12f40d0d, 0x130e0d0d,
		0x13280d0d, 0x13420d0d, 0x135c0d0e, 0x13770d0e, 0x13920d0e, 0x13ad0d0e, 0x13c80e0d, 0x13e30e0e,
		0x13ff0e0e, 0x141b0e0e, 0x14370e0f, 0x14540e0e, 0x14700f0e, 0x148d0f0e, 0x14aa0f0f, 0x14c80e0f,
		0x14e50f0f, 0x15030f0f, 0x15210f10, 0x15400f0f, 0x155e0f10, 0x157d0f10, 0x159c0f10, 0x15bb1010,
		0x15db0f10, 0x15fa1010, 0x161a1011, 0x163b1010, 0x165b1011, 0x167c1011, 0x169d1011, 0x16be1110,
		0x16df1111, 0x17011111, 0x17231111, 0x17451111, 0x17671211, 0x178a1112, 0x17ad1112, 0x17d01211,
		0x17f31212, 0x18171212, 0x183b1212, 0x185f1212, 0x18831213, 0x18a81213, 0x18cd1213, 0x18f21213,
		0x19171312, 0x193c1313, 0x19621313, 0x19881314, 0x19af1313, 0x19d51413, 0x19fc1314, 0x1a231413,
		0x1a4a1414, 0x1a721414, 0x1a9a1414, 0x1ac21414, 0x1aea1414, 0x1b121514, 0x1b3b1514, 0x1b641515,
		0x1b8e1415, 0x1bb71515, 0x1be11515, 0x1c0b1515, 0x1c351516, 0x1c601515, 0x1c8a1616, 0x1cb61516,
		0x1ce11615, 0x1d0c1616, 0x1d381616, 0x1d641617, 0x1d911616, 0x1dbd1617, 0x1dea1617, 0x1e171716,
		0x1e441717, 0x1e721717, 0x1ea01717, 0x1ece1717, 0x1efc1718, 0x1f2b1718, 0x1f5a1718, 0x1f891718,
		0x1fb81818, 0x1fe81818, 0x20181818, 0x20481818, 0x20781819, 0x20a91819, 0x20da1819, 0x210b1918,
		0x213c1919, 0x216e1919, 0x21a01919, 0x21d2191a, 0x22051919, 0x22371a19, 0x226a1a1a, 0x229e191a,
		0x22d11a1a, 0x23051a1a, 0x23391a1a, 0x236d1a1b, 0x23a21a1a, 0x23d61b1b, 0x240c1a1b, 0x24411b1b,
		0x24771a1b, 0x24ac1b1b, 0x24e21c1b, 0x25191b1c, 0x25501b1b, 0x25861c1c, 0x25be1b1c, 0x25f51c1c,
		0x262d1c1c, 0x26651c1c, 0x269d1c1c, 0x26d51d1c, 0x270e1d1c, 0x27471d1d, 0x27811c1d, 0x27ba1d1d,
		0x27f41d1d, 0x282e1d1d, 0x28681e1d, 0x28a31e1d, 0x28de1e1d, 0x29191e1e, 0x29551d1e, 0x29901e1e,
		0x29cc1e1e, 0x2a081f1e, 0x2a451e1f, 0x2a821e1f, 0x2abf1e1f, 0x2afc1f1f, 0x2b3a1f1f, 0x2b781f1f,
		0x2bb61f1f, 0x2bf41f20, 0x2c331f20, 0x2c721f20, 0x2cb1201f, 0x2cf02020, 0x2d302020, 0x2d702020,
		0x2db02120, 0x2df12021, 0x2e322021, 0x2e732021, 0x2eb42121, 0x2ef62121, 0x2f382121, 0x2f7a2121,
		0x2fbc2221, 0x2fff2221, 0x30422221, 0x30852222, 0x30c92222, 0x310d2222, 0x31512222, 0x31952322,
		0x31da2223, 0x321f2223, 0x32642323, 0x32aa2223, 0x32ef2323, 0x33352324, 0x337c2323, 0x33c22423,
		0x34092423, 0x34502424, 0x34982324, 0x34df2424, 0x35272425, 0x35702424, 0x35b82425, 0x36012425,
		0x364a2524, 0x36932525, 0x36dd2525, 0x37272525, 0x37712525, 0x37bb2625, 0x38062625, 0x38512626,
		0x389d2526, 0x38e82626, 0x39342626, 0x39802627, 0x39cd2626, 0x3a192726, 0x3a662726, 0x3ab32727,
		0x3b012727, 0x3b4f2727, 0x3b9d2727, 0x3beb2827, 0x3c3a2728, 0x3c892827, 0x3cd82828, 0x3d282827,
		0x3d772829, 0x3dc82828, 0x3e182829, 0x3e692828, 0x3eb92929, 0x3f0b2829, 0x3f5c2929, 0x3fae2929,
	};
	#if 0
	UINT32 invGammaHalf_xvycc[256] = {
		0x00262626, 0x00722626, 0x00bd2525, 0x01072525, 0x01502424, 0x01982424, 0x01df2323, 0x02252323,
		0x026a2222, 0x02ae2222, 0x02f12122, 0x03342120, 0x03752120, 0x03b52020, 0x03f41f20, 0x04331f1f,
		0x04701e1e, 0x04ad1f1d, 0x04e81e1d, 0x05231e1d, 0x055c1c1d, 0x05951c1c, 0x05cd1c1b, 0x06041c1b,
		0x06391a1b, 0x066e1a1b, 0x06a2191a, 0x06d61a19, 0x07081919, 0x07391818, 0x07691818, 0x07991817,
		0x07c71717, 0x07f51717, 0x08221616, 0x084e1615, 0x08791615, 0x08a31515, 0x08cc1414, 0x08f41414,
		0x091c1413, 0x09421313, 0x09681313, 0x098d1212, 0x09b11212, 0x09d41111, 0x09f61111, 0x0a181110,
		0x0a381010, 0x0a581010, 0x0a770f0f, 0x0a950f0f, 0x0ab20e0f, 0x0acf0e0e, 0x0aea0d0e, 0x0b050d0d,
		0x0b1f0d0d, 0x0b380c0c, 0x0b500c0c, 0x0b680c0b, 0x0b7f0c0b, 0x0b950b0a, 0x0baa0b0a, 0x0bbe0a0a,
		0x0bd20a09, 0x0be4090a, 0x0bf70908, 0x0c080908, 0x0c180808, 0x0c280808, 0x0c370708, 0x0c460707,
		0x0c530607, 0x0c600606, 0x0c6c0606, 0x0c780605, 0x0c830605, 0x0c8d0505, 0x0c960405, 0x0c9f0404,
		0x0ca70404, 0x0caf0404, 0x0cb60304, 0x0cbe0404, 0x0cc60404, 0x0cce0404, 0x0cd60404, 0x0cde0403,
		0x0ce50404, 0x0ced0404, 0x0cf50404, 0x0cfd0404, 0x0d050403, 0x0d0c0404, 0x0d140405, 0x0d1d0405,
		0x0d260405, 0x0d300506, 0x0d3b0506, 0x0d470606, 0x0d530606, 0x0d600706, 0x0d6d0707, 0x0d7b0708,
		0x0d8b0807, 0x0d9a0808, 0x0dab0908, 0x0dbc0909, 0x0dce0909, 0x0de10a0a, 0x0df4090a, 0x0e090b0a,
		0x0e1e0b0b, 0x0e340b0b, 0x0e4a0b0c, 0x0e620c0c, 0x0e7a0c0d, 0x0e930c0d, 0x0ead0d0d, 0x0ec80e0d,
		0x0ee30e0e, 0x0f000f0e, 0x0f1d0f0f, 0x0f3b0f0f, 0x0f5a100f, 0x0f791010, 0x0f9a1110, 0x0fbb1111,
		0x0fdd1112, 0x10001112, 0x10241213, 0x10491213, 0x106f1313, 0x10951314, 0x10bd1414, 0x10e51414,
		0x110e1515, 0x11381515, 0x11631616, 0x118f1616, 0x11bc1716, 0x11e91717, 0x12181817, 0x12471818,
		0x12771819, 0x12a91919, 0x12db1919, 0x130e1a1a, 0x13421a1a, 0x13771b1b, 0x13ad1b1b, 0x13e31b1c,
		0x141b1c1c, 0x14541d1c, 0x148d1d1d, 0x14c81e1d, 0x15031e1e, 0x15401f1e, 0x157d1f1f, 0x15bb1f20,
		0x15fa1f20, 0x163b2120, 0x167c2121, 0x16be2121, 0x17012222, 0x17452222, 0x178a2323, 0x17d02323,
		0x18172424, 0x185f2424, 0x18a82525, 0x18f22525, 0x193c2526, 0x19882627, 0x19d52627, 0x1a232727,
		0x1a722828, 0x1ac22828, 0x1b122829, 0x1b64292a, 0x1bb7292a, 0x1c0b2a2a, 0x1c602b2a, 0x1cb62c2b,
		0x1d0c2b2c, 0x1d642c2d, 0x1dbd2c2d, 0x1e172d2d, 0x1e722e2e, 0x1ece2e2e, 0x1f2b2f2f, 0x1f892f2f,
		0x1fe83030, 0x20483030, 0x20a93131, 0x210b3131, 0x216e3232, 0x21d23233, 0x22373233, 0x229e3433,
		0x23053434, 0x236d3435, 0x23d63436, 0x24413536, 0x24ac3536, 0x25193737, 0x25863638, 0x25f53738,
		0x26653838, 0x26d53839, 0x2747393a, 0x27ba393a, 0x282e3a3a, 0x28a33b3b, 0x29193b3c, 0x29903b3c,
		0x2a083c3d, 0x2a823d3d, 0x2afc3d3e, 0x2b783e3e, 0x2bf43e3f, 0x2c723f3f, 0x2cf03f40, 0x2d704040,
		0x2df14141, 0x2e734141, 0x2ef64242, 0x2f7a4242, 0x2fff4343, 0x30854344, 0x310d4444, 0x31954445,
		0x321f4545, 0x32aa4645, 0x33354647, 0x33c24647, 0x34504748, 0x34df4748, 0x35704948, 0x36014949,
		0x3693494a, 0x37274a4a, 0x37bb4a4b, 0x38514b4c, 0x38e84b4c, 0x39804c4d, 0x3a194c4d, 0x3ab34d4e,
		0x3b4f4e4e, 0x3beb4e4f, 0x3c894f4f, 0x3d28504f, 0x3dc85150, 0x3e695150, 0x3f0b5251, 0x3fae5252,
	};
	#endif

	inv_gamma_inv_gamma_ctrl_1_RBUS inv_gamma_ctrl_1_REG;
	inv_gamma_inv_gamma_ctrl_2_RBUS inv_gamma_ctrl_2_REG;

	int i;
	for (i = 0; i < 512; i++) {
		  sGAMMA_R[i] = invGammaFull_xvycc[i];
		  sGAMMA_G[i] = invGammaFull_xvycc[i];
		  sGAMMA_B[i] = invGammaFull_xvycc[i];
	}

	inv_gamma_ctrl_1_REG.regValue = IoReg_Read32(INV_GAMMA_INV_GAMMA_CTRL_1_reg);
	inv_gamma_ctrl_2_REG.regValue = IoReg_Read32(INV_GAMMA_INV_GAMMA_CTRL_2_reg);

	if (display  == SLR_MAIN_DISPLAY) {
		/*inv_gamma_ctrl_1_REG.inv_gamma_ax_type_sel = _Gamma_Full;*/
		inv_gamma_ctrl_1_REG.inv_gamma_ax_rw_sel = 1; /* writing table*/
	}
#if 0 /* #ifdef CONFIG_DUAL_CHANNEL*/
	else {
		inv_gamma_ctrl_1_REG.inv_gamma_ax_type_sel = _Gamma_Full;
		inv_gamma_ctrl_1_REG.inv_gamma_ax_rw_sel = 1; /* writing table*/
	}
#endif

	/* inv_gamma_ctrl_2_REG.inv_gamma_tab_size_sel = 0; */ /* table size = 0:512, 1:256  [jyyang@ Mac3] only main channel and one 512 table*/
	IoReg_Write32(INV_GAMMA_INV_GAMMA_CTRL_2_reg, inv_gamma_ctrl_2_REG.regValue);

	/* write invGamma table*/
	inv_gamma_ctrl_1_REG.inv_gamma_ax_ch_sel = 0;
	IoReg_Write32(INV_GAMMA_INV_GAMMA_CTRL_1_reg, inv_gamma_ctrl_1_REG.regValue);
	drvif_color_colorwrite_invGamma(sGAMMA_R);

	inv_gamma_ctrl_1_REG.inv_gamma_ax_ch_sel = 1;
	IoReg_Write32(INV_GAMMA_INV_GAMMA_CTRL_1_reg, inv_gamma_ctrl_1_REG.regValue);
	drvif_color_colorwrite_invGamma(sGAMMA_G);

	inv_gamma_ctrl_1_REG.inv_gamma_ax_ch_sel = 2;
	IoReg_Write32(INV_GAMMA_INV_GAMMA_CTRL_1_reg, inv_gamma_ctrl_1_REG.regValue);
	drvif_color_colorwrite_invGamma(sGAMMA_B);


	if (Mode != 0) { /* not bypass*/

		if (display  == SLR_MAIN_DISPLAY) {
			inv_gamma_ctrl_1_REG.inv_gamma_ax_rw_sel = 0; /* disable writing table*/
			inv_gamma_ctrl_2_REG.inv_gamma_m_tab_sel = 1; /* use tab-1*/
			/*gamma_ctrl_2_REG.gamma_overlap = 0; */ /* use main as overlay*/
		}
#ifdef CONFIG_DUAL_CHANNEL
#ifdef VIP_CONFIG_DUAL_CHANNEL // henry 161214
		else {
			inv_gamma_ctrl_1_REG.inv_gamma_ax_rw_sel = 0; /* disable writing table*/
			/*gamma_ctrl_2_REG.gamma_overlap = 1; */ /* use sub as overlay*/
			//inv_gamma_ctrl_2_REG.inv_gamma_s_tab_sel = 1;  /* sub gamma use tab-1 same to m_tab	rock_rau 2015/09/17 [WOSQRTK-1187]*///jyyang20161215
		}
#endif
#endif

	} else { /*  bypass*/
		if (display  == SLR_MAIN_DISPLAY) {
			inv_gamma_ctrl_2_REG.inv_gamma_m_tab_sel = 0; /* use tab-1*/
			/*gamma_ctrl_2_REG.gamma_overlap = 0; */ /* use main as overlay*/
		}
#ifdef CONFIG_DUAL_CHANNEL
#ifdef VIP_CONFIG_DUAL_CHANNEL // henry 161214
		else {
			//inv_gamma_ctrl_2_REG.inv_gamma_s_tab_sel = 0;  /* use tab-2*/ //jyyang20161215
			/*gamma_ctrl_2_REG.gamma_overlap = 1; */ /* use sub as overlay*/
		}
#endif
#endif
	}
	IoReg_Write32(INV_GAMMA_INV_GAMMA_CTRL_1_reg, inv_gamma_ctrl_1_REG.regValue);
	IoReg_Write32(INV_GAMMA_INV_GAMMA_CTRL_2_reg, inv_gamma_ctrl_2_REG.regValue);

};

void drvif_color_setGamma_HDR(unsigned char display, unsigned char mode) // Merlin jyyang 20150622
{
	// mode = [0]disable, [1]SMPTE, [2]BBC

	static UINT32 invGamma_Encode_SMPTE[512] = {
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000100,0x00010000,0x00010000,0x00010000,0x00010000,0x00010000,0x00010000,0x00010000,0x00010000,0x00010000,0x00010000,0x00010000,0x00010000,0x00010000,
	0x00010000,0x00010000,0x00010000,0x00010000,0x00010000,0x00010000,0x00010000,0x00010000,0x00010000,0x00010000,0x00010100,0x00020000,0x00020000,0x00020000,0x00020000,0x00020000,0x00020000,0x00020000,0x00020000,0x00020000,0x00020000,0x00020000,0x00020000,0x00020000,0x00020100,0x00030000,0x00030000,0x00030000,0x00030000,0x00030000,0x00030000,0x00030000,0x00030000,0x00030000,0x00030100,0x00040000,0x00040000,0x00040000,0x00040000,0x00040000,0x00040000,0x00040000,0x00040100,0x00050000,0x00050000,0x00050000,0x00050000,0x00050000,0x00050001,0x00060000,0x00060000,0x00060000,0x00060000,0x00060000,0x00060001,0x00070000,0x00070000,0x00070000,0x00070000,0x00070001,0x00080000,0x00080000,0x00080000,0x00080000,
	0x00080100,0x00090000,0x00090000,0x00090000,0x00090100,0x000a0000,0x000a0000,0x000a0000,0x000a0100,0x000b0000,0x000b0000,0x000b0001,0x000c0000,0x000c0000,0x000c0001,0x000d0000,0x000d0000,0x000d0001,0x000e0000,0x000e0000,0x000e0001,0x000f0000,0x000f0000,0x000f0100,0x00100000,0x00100001,0x00110000,0x00110000,0x00110100,0x00120000,0x00120100,0x00130000,0x00130001,0x00140000,0x00140001,0x00150000,0x00150001,0x00160000,0x00160001,0x00170000,0x00170100,0x00180000,0x00180100,0x00190001,0x001a0000,0x001a0001,0x001b0000,0x001b0100,0x001c0001,0x001d0000,0x001d0100,0x001e0001,0x001f0000,0x001f0100,0x00200100,0x00210001,0x00220000,0x00220100,0x00230100,0x00240001,0x00250001,0x00260001,0x00270000,0x00270100,
	0x00280100,0x00290100,0x002a0100,0x002b0001,0x002c0001,0x002d0001,0x002e0001,0x002f0001,0x00300001,0x00310100,0x00320100,0x00330100,0x00340100,0x00350101,0x00370001,0x00380001,0x00390100,0x003a0100,0x003b0101,0x003d0001,0x003e0100,0x003f0101,0x00410001,0x00420100,0x00430101,0x00450100,0x00460101,0x00480001,0x00490101,0x004b0100,0x004c0101,0x004e0101,0x00500001,0x00510101,0x00530101,0x00550001,0x00560101,0x00580101,0x005a0101,0x005c0101,0x005e0101,0x00600101,0x00620101,0x00640101,0x00660101,0x00680101,0x006a0101,0x006c0101,0x006e0101,0x00700102,0x00730101,0x00750101,0x00770102,0x007a0101,0x007c0102,0x007f0101,0x00810102,0x00840101,0x00860201,0x00890102,0x008c0102,0x008f0101,0x00910201,0x00940201,
	0x00970201,0x009a0201,0x009d0201,0x00a00201,0x00a30202,0x00a70102,0x00aa0201,0x00ad0202,0x00b10102,0x00b40202,0x00b80102,0x00bb0202,0x00bf0201,0x00c20202,0x00c60202,0x00ca0202,0x00ce0202,0x00d20202,0x00d60202,0x00da0202,0x00de0302,0x00e30202,0x00e70203,0x00ec0202,0x00f00203,0x00f50202,0x00f90302,0x00fe0302,0x01030203,0x01080203,0x010d0203,0x01120302,0x01170303,0x011d0203,0x01220302,0x01270303,0x012d0303,0x01330303,0x01390303,0x013f0303,0x01450303,0x014b0303,0x01510303,0x01570304,0x015e0303,0x01640403,0x016b0304,0x01720304,0x01790304,0x01800304,0x01870403,0x018e0404,0x01960403,0x019d0404,0x01a50404,0x01ad0404,0x01b50404,0x01bd0404,0x01c50504,0x01ce0404,0x01d60504,0x01df0504,0x01e80405,0x01f10504,
	0x01fa0505,0x02040405,0x020d0505,0x02170505,0x02210505,0x022b0505,0x02350506,0x02400505,0x024a0605,0x02550506,0x02600605,0x026b0606,0x02770506,0x02820606,0x028e0606,0x029a0606,0x02a60607,0x02b30606,0x02bf0706,0x02cc0706,0x02d90707,0x02e70607,0x02f40707,0x03020707,0x03100708,0x031f0707,0x032d0807,0x033c0708,0x034b0807,0x035a0808,0x036a0808,0x037a0808,0x038a0908,0x039b0809,0x03ac0809,0x03bd0809,0x03ce0909,0x03e00909,0x03f20909,0x04040a09,0x0417090a,0x042a0a09,0x043d0a0a,0x04510a0a,0x04650a0b,0x047a0a0a,0x048e0b0b,0x04a40a0b,0x04b90b0b,0x04cf0b0b,0x04e50c0b,0x04fc0c0b,0x05130c0c,0x052b0c0c,0x05430c0c,0x055b0c0d,0x05740c0d,0x058d0d0d,0x05a70d0d,0x05c10d0e,0x05dc0d0e,0x05f70e0d,0x06120e0f,0x062f0e0e,
	0x064b0f0e,0x06680f0f,0x06860f0f,0x06a40f10,0x06c30f10,0x06e21010,0x07021010,0x07221110,0x07431111,0x07651111,0x07871211,0x07aa1211,0x07cd1213,0x07f21212,0x08161313,0x083c1313,0x08621313,0x08881414,0x08b01414,0x08d81415,0x09011515,0x092b1515,0x09551516,0x09801616,0x09ac1617,0x09d91617,0x0a061718,0x0a351718,0x0a641818,0x0a941819,0x0ac51919,0x0af71919,0x0b291a1a,0x0b5d1a1b,0x0b921a1b,0x0bc71b1c,0x0bfe1b1c,0x0c351c1d,0x0c6e1c1d,0x0ca71d1e,0x0ce21e1e,0x0d1e1e1e,0x0d5a1f1f,0x0d98201f,0x0dd72020,0x0e172121,0x0e592121,0x0e9b2222,0x0edf2223,0x0f242323,0x0f6a2424,0x0fb22425,0x0ffb2525,0x10452625,0x10902726,0x10dd2728,0x112c2828,0x117c2829,0x11cd292a,0x12202a2a,0x12742b2b,0x12ca2b2c,0x13212d2d,0x137b2d2d,
	0x13d52e2f,0x14322f2f,0x14903030,0x14f03031,0x15513232,0x15b53233,0x161a3334,0x16813534,0x16ea3636,0x17563637,0x17c33738,0x18323839,0x18a3393a,0x19163b3b,0x198c3b3c,0x1a033d3d,0x1a7d3e3e,0x1af93f40,0x1b784041,0x1bf94142,0x1c7c4343,0x1d024444,0x1d8a4546,0x1e154747,0x1ea34749,0x1f33494a,0x1fc64a4b,0x205b4c4d,0x20f44d4e,0x218f4f50,0x222e5051,0x22cf5252,0x23735454,0x241b5555,0x24c55757,0x25735959,0x2625595b,0x26d95c5c,0x27915e5e,0x284d5f60,0x290c6162,0x29cf6363,0x2a956566,0x2b606668,0x2c2e6969,0x2d006b6b,0x2dd66d6e,0x2eb16f6f,0x2f8f7172,0x30727375,0x315a7576,0x32457879,0x3336797b,0x342a7d7d,0x35247f80,0x36238182,0x37268485,0x382f8687,0x393c898a,0x3a4f8b8d,0x3b678e90,0x3c859192,0x3da89495,0x3ed19798,
	};
	static UINT32 invGamma_Encode_BBC[512] = {
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000100,0x00010000,0x00010000,0x00010000,0x00010000,0x00010000,0x00010000,0x00010000,0x00010100,0x00020000,0x00020000,0x00020000,0x00020000,0x00020100,0x00030000,0x00030000,0x00030000,0x00030100,0x00040000,0x00040000,0x00040001,0x00050000,0x00050000,0x00050001,0x00060000,0x00060000,0x00060100,0x00070000,0x00070001,0x00080000,0x00080001,0x00090000,0x00090001,0x000a0000,0x000a0001,0x000b0000,0x000b0001,0x000c0000,0x000c0100,0x000d0000,0x000d0100,0x000e0001,0x000f0000,0x000f0100,0x00100001,0x00110000,0x00110100,0x00120001,0x00130001,0x00140000,0x00140100,
	0x00150100,0x00160001,0x00170001,0x00180000,0x00180100,0x00190100,0x001a0100,0x001b0100,0x001c0001,0x001d0001,0x001e0001,0x001f0001,0x00200001,0x00210001,0x00220001,0x00230100,0x00240100,0x00250100,0x00260100,0x00270101,0x00290001,0x002a0001,0x002b0100,0x002c0100,0x002d0101,0x002f0001,0x00300001,0x00310100,0x00320101,0x00340001,0x00350100,0x00360101,0x00380100,0x00390101,0x003b0001,0x003c0101,0x003e0001,0x003f0101,0x00410001,0x00420101,0x00440001,0x00450101,0x00470100,0x00480101,0x004a0101,0x004c0100,0x004d0101,0x004f0101,0x00510101,0x00530001,0x00540101,0x00560101,0x00580101,0x005a0101,0x005c0101,0x005e0001,0x005f0101,0x00610101,0x00630101,0x00650101,0x00670101,0x00690101,0x006b0101,0x006d0101,
	0x006f0102,0x00720101,0x00740101,0x00760101,0x00780101,0x007a0101,0x007c0102,0x007f0101,0x00810101,0x00830101,0x00850201,0x00880101,0x008a0102,0x008d0101,0x008f0101,0x00910201,0x00940101,0x00960201,0x00990101,0x009b0201,0x009e0101,0x00a00201,0x00a30102,0x00a60101,0x00a80201,0x00ab0102,0x00ae0101,0x00b00201,0x00b30201,0x00b60102,0x00b90102,0x00bc0101,0x00be0201,0x00c10201,0x00c40201,0x00c70201,0x00ca0102,0x00cd0102,0x00d00102,0x00d30102,0x00d60201,0x00d90201,0x00dc0201,0x00df0201,0x00e20202,0x00e60102,0x00e90102,0x00ec0201,0x00ef0202,0x00f30102,0x00f60201,0x00f90202,0x00fd0102,0x01000201,0x01030202,0x01070102,0x010a0202,0x010e0102,0x01110202,0x01150201,0x01180202,0x011c0202,0x01200102,0x01230202,
	0x01270202,0x012b0102,0x012e0202,0x01320202,0x01360202,0x013a0202,0x013e0202,0x01420202,0x01460202,0x014a0202,0x014e0203,0x01530202,0x01570202,0x015b0203,0x01600202,0x01640202,0x01680302,0x016d0203,0x01720202,0x01760302,0x017b0203,0x01800203,0x01850203,0x018a0203,0x018f0203,0x01940203,0x01990203,0x019e0203,0x01a30302,0x01a80303,0x01ae0203,0x01b30303,0x01b90203,0x01be0303,0x01c40303,0x01ca0203,0x01cf0303,0x01d50303,0x01db0303,0x01e10303,0x01e70303,0x01ed0304,0x01f40303,0x01fa0303,0x02000403,0x02070303,0x020d0403,0x02140304,0x021b0304,0x02220303,0x02280403,0x022f0403,0x02360404,0x023e0304,0x02450403,0x024c0404,0x02540304,0x025b0404,0x02630403,0x026a0404,0x02720404,0x027a0404,0x02820404,0x028a0405,
	0x02930404,0x029b0404,0x02a30504,0x02ac0404,0x02b40504,0x02bd0504,0x02c60504,0x02cf0504,0x02d80504,0x02e10505,0x02eb0405,0x02f40505,0x02fe0405,0x03070505,0x03110505,0x031b0505,0x03250505,0x032f0506,0x033a0505,0x03440506,0x034f0505,0x03590605,0x03640605,0x036f0605,0x037a0605,0x03850606,0x03910506,0x039c0606,0x03a80606,0x03b40606,0x03c00606,0x03cc0606,0x03d80607,0x03e50606,0x03f10706,0x03fe0607,0x040b0607,0x04180706,0x04250707,0x04330607,0x04400707,0x044e0707,0x045c0707,0x046a0707,0x04780708,0x04870707,0x04950807,0x04a40807,0x04b30807,0x04c20808,0x04d20708,0x04e10808,0x04f10808,0x05010808,0x05110809,0x05220808,0x05320908,0x05430908,0x05540908,0x05650909,0x05770908,0x05880909,0x059a0909,0x05ac0a09,
	0x05bf0909,0x05d10a09,0x05e40a09,0x05f70a0a,0x060b090a,0x061e0a0a,0x06320a0a,0x06460a0a,0x065a0a0b,0x066f0a0b,0x06840a0b,0x06990a0b,0x06ae0b0b,0x06c40a0b,0x06d90b0c,0x06f00b0b,0x07060b0c,0x071d0b0c,0x07340b0c,0x074b0c0c,0x07630b0c,0x077a0d0c,0x07930c0c,0x07ab0d0c,0x07c40c0d,0x07dd0d0c,0x07f60d0d,0x08100d0d,0x082a0d0e,0x08450d0d,0x085f0e0e,0x087b0d0e,0x08960e0e,0x08b20e0e,0x08ce0e0e,0x08ea0f0e,0x09070f0e,0x09240f0f,0x09420f0f,0x09600f0f,0x097e100f,0x099d0f10,0x09bc100f,0x09db1010,0x09fb1011,0x0a1c1010,0x0a3c1110,0x0a5d1111,0x0a7f1111,0x0aa11111,0x0ac31211,0x0ae61211,0x0b091212,0x0b2d1212,0x0b511213,0x0b761213,0x0b9b1312,0x0bc01313,0x0be61413,0x0c0d1314,0x0c341413,0x0c5b1414,0x0c831415,0x0cac1415,
	0x0cd51415,0x0cfe1515,0x0d281516,0x0d531516,0x0d7e1616,0x0daa1616,0x0dd61617,0x0e031617,0x0e301717,0x0e5e1717,0x0e8c1817,0x0ebb1818,0x0eeb1818,0x0f1b1819,0x0f4c1918,0x0f7d191a,0x0fb01919,0x0fe21a1a,0x10161a1a,0x104a1a1a,0x107e1b1b,0x10b41b1b,0x10ea1b1b,0x11201c1c,0x11581c1c,0x11901c1d,0x11c91c1d,0x12021d1d,0x123c1e1d,0x12771e1e,0x12b31e1f,0x12f01e1f,0x132d1f1f,0x136b1f20,0x13aa1f20,0x13e92021,0x142a2021,0x146b2121,0x14ad2122,0x14f02222,0x15342222,0x15782323,0x15be2323,0x16042324,0x164b2424,0x16932524,0x16dc2525,0x17262526,0x17712626,0x17bd2627,0x180a2627,0x18572827,0x18a62828,0x18f62828,0x19462929,0x19982a29,0x19eb2a2a,0x1a3f2a2b,0x1a942b2b,0x1aea2b2c,0x1b412c2c,0x1b992c2d,0x1bf22d2e,0x1c4d2d2e,
	0x1ca82e2f,0x1d052f2f,0x1d632f30,0x1dc23030,0x1e223031,0x1e833231,0x1ee63232,0x1f4a3233,0x1faf3334,0x20163334,0x207d3534,0x20e63635,0x21513636,0x21bd3637,0x222a3737,0x22983838,0x23083938,0x23793a39,0x23ec3a3a,0x24603b3b,0x24d63b3c,0x254d3c3d,0x25c63d3d,0x26403e3e,0x26bc3e3f,0x27393f40,0x27b84040,0x28384141,0x28ba4242,0x293e4342,0x29c34444,0x2a4b4444,0x2ad34546,0x2b5e4646,0x2bea4747,0x2c784848,0x2d084949,0x2d9a494a,0x2e2d4b4a,0x2ec24c4c,0x2f5a4c4d,0x2ff34d4e,0x308e4e4f,0x312b4f50,0x31ca5051,0x326b5152,0x330e5253,0x33b35453,0x345a5555,0x35045556,0x35af5757,0x365d5759,0x370d585a,0x37bf5a5a,0x38735b5c,0x392a5c5c,0x39e25e5e,0x3a9e5e5f,0x3b5b6060,0x3c1b6162,0x3cde6262,0x3da26464,0x3e6a6466,0x3f346666,
	};
	static UINT32 Gamma_SMPTE[1025] = {
	   0,1220,1454,1600,1708,1794,1866,1927,1980,2028,2071,2111,2147,2180,2211,2240,2267,2293,2317,2340,2362,2383,2403,2422,2440,2458,2475,2491,2507,2522,2537,2551,2565,2578,2591,2604,2616,2628,2640,2651,2663,2673,2684,2694,2704,2714,2724,2734,2743,2752,2761,2770,2778,2787,2795,2803,2811,2819,2826,2834,2842,2849,2856,2863,2870,2877,2884,2890,2897,2904,2910,2916,2922,2929,2935,2941,2947,2952,2958,2964,2969,2975,2980,2986,2991,2996,3002,3007,3012,3017,3022,3027,3032,3037,3041,3046,3051,3055,3060,3064,3069,3073,3078,3082,3086,3091,3095,3099,3103,3107,3111,3116,3120,3123,3127,3131,3135,3139,3143,3147,3150,3154,3158,3161,3165,3169,3172,3176,
	3179,3183,3186,3190,3193,3196,3200,3203,3206,3210,3213,3216,3219,3222,3226,3229,3232,3235,3238,3241,3244,3247,3250,3253,3256,3259,3262,3265,3268,3270,3273,3276,3279,3282,3284,3287,3290,3293,3295,3298,3301,3303,3306,3309,3311,3314,3316,3319,3321,3324,3327,3329,3332,3334,3336,3339,3341,3344,3346,3349,3351,3353,3356,3358,3360,3363,3365,3367,3370,3372,3374,3376,3379,3381,3383,3385,3387,3390,3392,3394,3396,3398,3400,3402,3405,3407,3409,3411,3413,3415,3417,3419,3421,3423,3425,3427,3429,3431,3433,3435,3437,3439,3441,3443,3445,3447,3449,3450,3452,3454,3456,3458,3460,3462,3464,3465,3467,3469,3471,3473,3474,3476,3478,3480,3482,3483,3485,3487,
	3489,3490,3492,3494,3495,3497,3499,3501,3502,3504,3506,3507,3509,3511,3512,3514,3516,3517,3519,3520,3522,3524,3525,3527,3528,3530,3532,3533,3535,3536,3538,3539,3541,3542,3544,3546,3547,3549,3550,3552,3553,3555,3556,3558,3559,3561,3562,3563,3565,3566,3568,3569,3571,3572,3574,3575,3576,3578,3579,3581,3582,3584,3585,3586,3588,3589,3590,3592,3593,3595,3596,3597,3599,3600,3601,3603,3604,3605,3607,3608,3609,3611,3612,3613,3615,3616,3617,3618,3620,3621,3622,3624,3625,3626,3627,3629,3630,3631,3632,3634,3635,3636,3637,3639,3640,3641,3642,3644,3645,3646,3647,3648,3650,3651,3652,3653,3654,3656,3657,3658,3659,3660,3661,3663,3664,3665,3666,3667,
	3668,3670,3671,3672,3673,3674,3675,3676,3678,3679,3680,3681,3682,3683,3684,3685,3686,3688,3689,3690,3691,3692,3693,3694,3695,3696,3697,3698,3700,3701,3702,3703,3704,3705,3706,3707,3708,3709,3710,3711,3712,3713,3714,3715,3716,3717,3718,3719,3720,3721,3722,3723,3724,3725,3726,3727,3729,3730,3730,3731,3732,3733,3734,3735,3736,3737,3738,3739,3740,3741,3742,3743,3744,3745,3746,3747,3748,3749,3750,3751,3752,3753,3754,3755,3756,3757,3758,3758,3759,3760,3761,3762,3763,3764,3765,3766,3767,3768,3769,3770,3770,3771,3772,3773,3774,3775,3776,3777,3778,3779,3779,3780,3781,3782,3783,3784,3785,3786,3786,3787,3788,3789,3790,3791,3792,3793,3793,3794,
	3795,3796,3797,3798,3799,3799,3800,3801,3802,3803,3804,3804,3805,3806,3807,3808,3809,3809,3810,3811,3812,3813,3814,3814,3815,3816,3817,3818,3818,3819,3820,3821,3822,3823,3823,3824,3825,3826,3827,3827,3828,3829,3830,3830,3831,3832,3833,3834,3834,3835,3836,3837,3838,3838,3839,3840,3841,3841,3842,3843,3844,3844,3845,3846,3847,3847,3848,3849,3850,3851,3851,3852,3853,3854,3854,3855,3856,3856,3857,3858,3859,3859,3860,3861,3862,3862,3863,3864,3865,3865,3866,3867,3867,3868,3869,3870,3870,3871,3872,3873,3873,3874,3875,3875,3876,3877,3877,3878,3879,3880,3880,3881,3882,3882,3883,3884,3884,3885,3886,3887,3887,3888,3889,3889,3890,3891,3891,3892,
	3893,3893,3894,3895,3895,3896,3897,3897,3898,3899,3899,3900,3901,3902,3902,3903,3904,3904,3905,3905,3906,3907,3907,3908,3909,3909,3910,3911,3911,3912,3913,3913,3914,3915,3915,3916,3917,3917,3918,3919,3919,3920,3920,3921,3922,3922,3923,3924,3924,3925,3925,3926,3927,3927,3928,3929,3929,3930,3931,3931,3932,3932,3933,3934,3934,3935,3935,3936,3937,3937,3938,3939,3939,3940,3940,3941,3942,3942,3943,3943,3944,3945,3945,3946,3946,3947,3948,3948,3949,3949,3950,3951,3951,3952,3952,3953,3954,3954,3955,3955,3956,3956,3957,3958,3958,3959,3959,3960,3961,3961,3962,3962,3963,3963,3964,3965,3965,3966,3966,3967,3967,3968,3969,3969,3970,3970,3971,3971,
	3972,3973,3973,3974,3974,3975,3975,3976,3976,3977,3978,3978,3979,3979,3980,3980,3981,3981,3982,3983,3983,3984,3984,3985,3985,3986,3986,3987,3987,3988,3989,3989,3990,3990,3991,3991,3992,3992,3993,3993,3994,3995,3995,3996,3996,3997,3997,3998,3998,3999,3999,4000,4000,4001,4001,4002,4002,4003,4003,4004,4005,4005,4006,4006,4007,4007,4008,4008,4009,4009,4010,4010,4011,4011,4012,4012,4013,4013,4014,4014,4015,4015,4016,4016,4017,4017,4018,4018,4019,4019,4020,4020,4021,4021,4022,4022,4023,4023,4024,4024,4025,4025,4026,4026,4027,4027,4028,4028,4029,4029,4030,4030,4031,4031,4032,4032,4033,4033,4034,4034,4035,4035,4036,4036,4037,4037,4038,4038,
	4039,4039,4040,4040,4041,4041,4041,4042,4042,4043,4043,4044,4044,4045,4045,4046,4046,4047,4047,4048,4048,4049,4049,4050,4050,4050,4051,4051,4052,4052,4053,4053,4054,4054,4055,4055,4056,4056,4056,4057,4057,4058,4058,4059,4059,4060,4060,4061,4061,4062,4062,4062,4063,4063,4064,4064,4065,4065,4066,4066,4067,4067,4067,4068,4068,4069,4069,4070,4070,4071,4071,4071,4072,4072,4073,4073,4074,4074,4075,4075,4075,4076,4076,4077,4077,4078,4078,4078,4079,4079,4080,4080,4081,4081,4082,4082,4082,4083,4083,4084,4084,4085,4085,4085,4086,4086,4087,4087,4088,4088,4088,4089,4089,4090,4090,4091,4091,4091,4092,4092,4093,4093,4093,4094,4094,4095,4095,4096,
	4096,};
	static UINT32 Gamma_BBC[1025] = {
	   0, 173, 244, 299, 345, 386, 423, 457, 488, 518, 546, 573, 598, 623, 646, 669, 691, 712, 733, 753, 772, 791, 810, 828, 846, 863, 881, 897, 914, 930, 946, 962, 977, 992,1007,1022,1036,1050,1065,1078,1092,1106,1119,1132,1146,1158,1171,1184,1196,1209,1221,1233,1245,1257,1269,1281,1292,1304,1315,1327,1338,1349,1360,1371,1382,1392,1403,1414,1424,1435,1445,1455,1465,1476,1486,1496,1506,1515,1525,1535,1545,1554,1564,1573,1583,1592,1602,1611,1620,1629,1638,1647,1656,1665,1674,1683,1692,1701,1710,1718,1727,1736,1744,1753,1761,1770,1778,1786,1795,1803,1811,1819,1828,1836,1844,1852,1860,1868,1876,1884,1892,1900,1908,1915,1923,1931,1939,1946,
	1954,1961,1969,1977,1984,1992,1999,2007,2014,2021,2029,2036,2043,2051,2058,2065,2072,2079,2087,2094,2101,2108,2114,2121,2128,2135,2142,2148,2155,2162,2168,2175,2181,2187,2194,2200,2207,2213,2219,2225,2231,2238,2244,2250,2256,2262,2268,2273,2279,2285,2291,2297,2303,2308,2314,2320,2325,2331,2336,2342,2347,2353,2358,2364,2369,2375,2380,2385,2390,2396,2401,2406,2411,2416,2422,2427,2432,2437,2442,2447,2452,2457,2462,2466,2471,2476,2481,2486,2491,2495,2500,2505,2510,2514,2519,2524,2528,2533,2537,2542,2546,2551,2555,2560,2564,2569,2573,2578,2582,2586,2591,2595,2599,2604,2608,2612,2616,2621,2625,2629,2633,2637,2641,2646,2650,2654,2658,2662,
	2666,2670,2674,2678,2682,2686,2690,2694,2698,2702,2705,2709,2713,2717,2721,2725,2728,2732,2736,2740,2744,2747,2751,2755,2758,2762,2766,2769,2773,2777,2780,2784,2787,2791,2795,2798,2802,2805,2809,2812,2816,2819,2823,2826,2830,2833,2836,2840,2843,2847,2850,2853,2857,2860,2863,2867,2870,2873,2877,2880,2883,2886,2890,2893,2896,2899,2903,2906,2909,2912,2915,2918,2922,2925,2928,2931,2934,2937,2940,2943,2946,2950,2953,2956,2959,2962,2965,2968,2971,2974,2977,2980,2983,2986,2989,2992,2994,2997,3000,3003,3006,3009,3012,3015,3018,3021,3023,3026,3029,3032,3035,3038,3040,3043,3046,3049,3051,3054,3057,3060,3063,3065,3068,3071,3073,3076,3079,3082,
	3084,3087,3090,3092,3095,3098,3100,3103,3106,3108,3111,3113,3116,3119,3121,3124,3126,3129,3132,3134,3137,3139,3142,3144,3147,3149,3152,3154,3157,3159,3162,3164,3167,3169,3172,3174,3177,3179,3182,3184,3186,3189,3191,3194,3196,3199,3201,3203,3206,3208,3211,3213,3215,3218,3220,3222,3225,3227,3229,3232,3234,3236,3239,3241,3243,3246,3248,3250,3252,3255,3257,3259,3262,3264,3266,3268,3271,3273,3275,3277,3279,3282,3284,3286,3288,3291,3293,3295,3297,3299,3301,3304,3306,3308,3310,3312,3314,3317,3319,3321,3323,3325,3327,3329,3332,3334,3336,3338,3340,3342,3344,3346,3348,3350,3352,3354,3357,3359,3361,3363,3365,3367,3369,3371,3373,3375,3377,3379,
	3381,3383,3385,3387,3389,3391,3393,3395,3397,3399,3401,3403,3405,3407,3409,3411,3413,3415,3417,3419,3421,3423,3424,3426,3428,3430,3432,3434,3436,3438,3440,3442,3444,3445,3447,3449,3451,3453,3455,3457,3459,3461,3462,3464,3466,3468,3470,3472,3473,3475,3477,3479,3481,3483,3484,3486,3488,3490,3492,3494,3495,3497,3499,3501,3503,3504,3506,3508,3510,3511,3513,3515,3517,3519,3520,3522,3524,3526,3527,3529,3531,3533,3534,3536,3538,3539,3541,3543,3545,3546,3548,3550,3552,3553,3555,3557,3558,3560,3562,3563,3565,3567,3568,3570,3572,3573,3575,3577,3578,3580,3582,3583,3585,3587,3588,3590,3592,3593,3595,3597,3598,3600,3602,3603,3605,3606,3608,3610,
	3611,3613,3614,3616,3618,3619,3621,3622,3624,3626,3627,3629,3630,3632,3634,3635,3637,3638,3640,3641,3643,3645,3646,3648,3649,3651,3652,3654,3655,3657,3659,3660,3662,3663,3665,3666,3668,3669,3671,3672,3674,3675,3677,3678,3680,3681,3683,3684,3686,3687,3689,3690,3692,3693,3695,3696,3698,3699,3701,3702,3704,3705,3707,3708,3710,3711,3712,3714,3715,3717,3718,3720,3721,3723,3724,3726,3727,3728,3730,3731,3733,3734,3736,3737,3738,3740,3741,3743,3744,3746,3747,3748,3750,3751,3753,3754,3755,3757,3758,3760,3761,3762,3764,3765,3767,3768,3769,3771,3772,3773,3775,3776,3778,3779,3780,3782,3783,3784,3786,3787,3789,3790,3791,3793,3794,3795,3797,3798,
	3799,3801,3802,3803,3805,3806,3807,3809,3810,3811,3813,3814,3815,3817,3818,3819,3821,3822,3823,3825,3826,3827,3828,3830,3831,3832,3834,3835,3836,3838,3839,3840,3841,3843,3844,3845,3847,3848,3849,3850,3852,3853,3854,3856,3857,3858,3859,3861,3862,3863,3864,3866,3867,3868,3869,3871,3872,3873,3874,3876,3877,3878,3879,3881,3882,3883,3884,3886,3887,3888,3889,3891,3892,3893,3894,3895,3897,3898,3899,3900,3902,3903,3904,3905,3906,3908,3909,3910,3911,3912,3914,3915,3916,3917,3918,3920,3921,3922,3923,3924,3926,3927,3928,3929,3930,3932,3933,3934,3935,3936,3937,3939,3940,3941,3942,3943,3944,3946,3947,3948,3949,3950,3951,3953,3954,3955,3956,3957,
	3958,3960,3961,3962,3963,3964,3965,3966,3968,3969,3970,3971,3972,3973,3974,3975,3977,3978,3979,3980,3981,3982,3983,3985,3986,3987,3988,3989,3990,3991,3992,3993,3995,3996,3997,3998,3999,4000,4001,4002,4003,4005,4006,4007,4008,4009,4010,4011,4012,4013,4014,4015,4017,4018,4019,4020,4021,4022,4023,4024,4025,4026,4027,4028,4030,4031,4032,4033,4034,4035,4036,4037,4038,4039,4040,4041,4042,4043,4044,4046,4047,4048,4049,4050,4051,4052,4053,4054,4055,4056,4057,4058,4059,4060,4061,4062,4063,4064,4065,4066,4068,4069,4070,4071,4072,4073,4074,4075,4076,4077,4078,4079,4080,4081,4082,4083,4084,4085,4086,4087,4088,4089,4090,4091,4092,4093,4094,4095,
	4096,};

	if(mode == 0)
		return;
	else if(mode == 1) // SMPTE
	{
		drvif_color_Inv_Gamma_Curve_Write(invGamma_Encode_SMPTE, VIP_GAMMA_CHANNEL_RGB_MAX);
		drvif_color_colorwrite_gamma_HDR(Gamma_SMPTE, VIP_GAMMA_CHANNEL_RGB_MAX);
	}
	else if(mode == 2) // BBC
	{
		drvif_color_Inv_Gamma_Curve_Write(invGamma_Encode_BBC, VIP_GAMMA_CHANNEL_RGB_MAX);
		drvif_color_colorwrite_gamma_HDR(Gamma_BBC, VIP_GAMMA_CHANNEL_RGB_MAX);
	}
}
/*============================================================================*/
/**
 * Color_SetGamma
 * This function is used to set gamma table
 *
 * @param <display>	{ specify main/sub to set gamma }
 * @param <mode> 	{ gamma table type}
 * @return 			{ void }

 * Mode = 0 Gamma off
 * Mode = 1 always in Tab-1, rewrite Tab-1 for tGAMMA_1_R, tGAMMA_1_G, tGAMMA_1_B
 * Mode = 2 always in Tab-1, rewrite Tab-1 for tGAMMA_2_R, tGAMMA_2_G, tGAMMA_2_B
 * Mode = 3 always in Tab-2, rewrite Tab-2 for tGAMMA_3_R, tGAMMA_3_G, tGAMMA_3_B

 */
void drvif_color_setgamma(unsigned char display, unsigned char Mode, VIP_Gamma *ptr)
{
	gamma_gamma_ctrl_1_RBUS gamma_ctrl_1_REG;
	gamma_gamma_ctrl_2_RBUS gamma_ctrl_2_REG;

	if (!ptr)
		return;
	if (Mode > 3) /* added by Jerry, for reducing code size*/
		return;

	gamma_ctrl_1_REG.regValue = IoReg_Read32(GAMMA_GAMMA_CTRL_1_reg);
	gamma_ctrl_2_REG.regValue = IoReg_Read32(GAMMA_GAMMA_CTRL_2_reg);

	if (display  == SLR_MAIN_DISPLAY) {
		/*gamma_ctrl_2_REG.main_tab_sel = 0;	*/ /* disable main gamma*/
		/* remove "disable gamma" for PIP sub flash when TV scan channel start & end , 20071228 Jerry Wu*/
		/*gamma_ctrl_1_REG.gamma_ax_type_sel = _Gamma_Full;*/
		/*gamma_ctrl_1_REG.gamma_ax_tab_sel = 0; */ /* tab-1*/
		gamma_ctrl_1_REG.gamma_ax_rw_sel = 1; /* writing table*/

	}

	/*IoReg_Write32(GAMMA_GAMMA_CTRL_2_reg, gamma_ctrl_2_REG.regValue);*/

	/*IoReg_Write32(GAMMA_GAMMA_CTRL_1_reg, gamma_ctrl_1_REG.regValue);*/

	if (Mode != 0) {
		if (Mode == 1) {
			/*
			gamma_ctrl_1_REG.color_channel = 3;
			IoReg_Write32(GAMMA_GAMMA_CTRL_1_reg, gamma_ctrl_1_REG.regValue);
			drvif_color_colorwritegamma(tGAMMA_1_R);
			*/
			gamma_ctrl_1_REG.gamma_ax_ch_sel = 0;
			IoReg_Write32(GAMMA_GAMMA_CTRL_1_reg, gamma_ctrl_1_REG.regValue);
			drvif_color_colorwritegamma(ptr->R);
			gamma_ctrl_1_REG.gamma_ax_ch_sel = 1;
			IoReg_Write32(GAMMA_GAMMA_CTRL_1_reg, gamma_ctrl_1_REG.regValue);
			drvif_color_colorwritegamma(ptr->G);
			gamma_ctrl_1_REG.gamma_ax_ch_sel = 2;
			IoReg_Write32(GAMMA_GAMMA_CTRL_1_reg, gamma_ctrl_1_REG.regValue);
			drvif_color_colorwritegamma(ptr->B);

		} else if (Mode == 2) {
		/*	VIPprintf("write gamma 2\n");*/
			gamma_ctrl_1_REG.gamma_ax_ch_sel = 0;
			IoReg_Write32(GAMMA_GAMMA_CTRL_1_reg, gamma_ctrl_1_REG.regValue);
			drvif_color_colorwritegamma(ptr->R);
			gamma_ctrl_1_REG.gamma_ax_ch_sel = 1;
			IoReg_Write32(GAMMA_GAMMA_CTRL_1_reg, gamma_ctrl_1_REG.regValue);
			drvif_color_colorwritegamma(ptr->G);
			gamma_ctrl_1_REG.gamma_ax_ch_sel = 2;
			IoReg_Write32(GAMMA_GAMMA_CTRL_1_reg, gamma_ctrl_1_REG.regValue);
			drvif_color_colorwritegamma(ptr->B);
		}
	}

	if (Mode != 0) { /* not bypass*/

		if (display  == SLR_MAIN_DISPLAY) {
			gamma_ctrl_1_REG.gamma_ax_rw_sel = 0; /* writing table*/
			gamma_ctrl_2_REG.gamma_m_tab_sel = 1; /* use tab-1*/
			/*gamma_ctrl_2_REG.gamma_overlap = 0; */ /* use main as overlay*/

		}
#ifdef CONFIG_DUAL_CHANNEL
#ifdef VIP_CONFIG_DUAL_CHANNEL // henry 161214
		else {
			gamma_ctrl_1_REG.gamma_ax_rw_sel = 0; /* disable writing table*/
			/*gamma_ctrl_2_REG.gamma_overlap = 1; */ /* use sub as overlay*/
			gamma_ctrl_2_REG.gamma_s_tab_sel = 1;  /* sub gamma use tab-1 same to m_tab	rock_rau 2015/09/17 [WOSQRTK-1187]*/
		}
#endif
#endif
	} else { /*  bypass*/
		if (display  == SLR_MAIN_DISPLAY) {
			gamma_ctrl_2_REG.gamma_m_tab_sel = 0; /* use tab-1*/
			/*gamma_ctrl_2_REG.gamma_overlap = 0; */ /* use main as overlay*/
		}
#ifdef CONFIG_DUAL_CHANNEL
#ifdef VIP_CONFIG_DUAL_CHANNEL // henry 161214
		else {
			gamma_ctrl_2_REG.gamma_s_tab_sel = 0;  /* use tab-2*/
			/*gamma_ctrl_2_REG.gamma_overlap = 1; */ /* use sub as overlay*/
		}
#endif
#endif
	}
	IoReg_Write32(GAMMA_GAMMA_CTRL_1_reg, gamma_ctrl_1_REG.regValue);/*20071217 jason for high level (white changes to megenta)*/
	IoReg_Write32(GAMMA_GAMMA_CTRL_2_reg, gamma_ctrl_2_REG.regValue);
}

/* Function description : This function is used to write the encoded gamma curve to register for one channel*/
void drvif_color_Gamma_Curve_Write(unsigned int *Gamma_Encode, VIP_GAMMA_CHANNEL_RGB RGB_chanel_idx)
{
	gamma_gamma_ctrl_1_RBUS gamma_ctrl_1_REG;
	gamma_ctrl_1_REG.regValue = IoReg_Read32(GAMMA_GAMMA_CTRL_1_reg);
	gamma_ctrl_1_REG.gamma_ax_ch_sel = RGB_chanel_idx;
	IoReg_Write32(GAMMA_GAMMA_CTRL_1_reg, gamma_ctrl_1_REG.regValue);
	drvif_color_colorwritegamma(Gamma_Encode);
}

unsigned char drvif_color_Gamma_Read_Write_Check(void)
{
	unsigned char ret = 0, count = 0;
	gamma_gamma_ctrl_1_RBUS gamma_ctrl_1_REG;
	struct timespec timeout;
	timeout = ns_to_timespec(500 * 1000);

	gamma_ctrl_1_REG.regValue = IoReg_Read32(GAMMA_GAMMA_CTRL_1_reg);

	while (gamma_ctrl_1_REG.gamma_ax_rw_sel == 1 || gamma_ctrl_1_REG.gamma_ax_rw_sel != 2 && count++ < 12) {
		hrtimer_nanosleep(&timeout, NULL, HRTIMER_MODE_REL, CLOCK_MONOTONIC);
		gamma_ctrl_1_REG.regValue = IoReg_Read32(GAMMA_GAMMA_CTRL_1_reg);
	}

	return gamma_ctrl_1_REG.gamma_ax_rw_sel;
}

/*============================================================================*/
/**
 * Color_SetYContrastBrightness
 * Set contrast & brightness of Y path
 *
 * @param <Contrast> 	{ Y Contrast}
 * @param <Brightness> 	{ Y brightness}
 * @return 			{ void }
 *
 */
void drvif_color_setycontrastbrightness_new(unsigned char display, unsigned char Contrast, unsigned char Brightness, unsigned char csp_control)
{
	//this funnction only used by tv05
	/*	unsigned short K11;*/
	/*unsigned short temp_value;*/
	/*unsigned char osdSat = 0;*/
	unsigned short new_K11;
	unsigned short buffer_status_count = 0;
	signed short new_RGB_offset;
	/* 1. access tab-1 & 2*/
	/* 2. use both tab-1 & 2's k11 for Y contrast*/
	/* 3. use both tab-1 & 2's RGB contrast as Y Brightness.*/
	yuv2rgb_d_yuv2rgb_tab1_data_0_RBUS yuv2rgb_d_yuv2rgb_tab1_data_0_REG;
//	yuv2rgb_d_yuv2rgb_tab2_data_0_RBUS d_yuv2rgb_tab2_data_0_REG; //juwen, remove

	yuv2rgb_d_yuv2rgb_tab1_data_4_RBUS yuv2rgb_d_yuv2rgb_tab1_data_4_REG;
	yuv2rgb_d_yuv2rgb_tab1_data_5_RBUS yuv2rgb_d_yuv2rgb_tab1_data_5_REG;
	yuv2rgb_d_yuv2rgb_tab1_data_6_RBUS yuv2rgb_d_yuv2rgb_tab1_data_6_REG;

	yuv2rgb_d_yuv2rgb_tab1_data_clamp_RBUS yuv2rgb_d_yuv2rgb_tab1_data_clamp_reg;

	yuv2rgb_d_yuv2rgb_control_1_RBUS d_yuv2rgb_control_1_reg;
	yuv2rgb_d_yuv2rgb_control_RBUS d_yuv2rgb_control_REG;

	d_yuv2rgb_control_REG.regValue = IoReg_Read32(YUV2RGB_D_YUV2RGB_Control_reg);
	d_yuv2rgb_control_1_reg.regValue = IoReg_Read32(YUV2RGB_D_YUV2RGB_Control_1_reg);
	/*d_yuv2rgb_control_REG.yuv2rgb_overlay = 1;  */ /*overlap is according sub*/
	/*USER: Vincent_Lee  DATE: 2011/10/12  TODO: fixed high-light window bug for magic function*/

//	d_yuv2rgb_control_REG.yuv2rgb_overlay = 0;//juwen, remove
	IoReg_Write32(YUV2RGB_D_YUV2RGB_Control_reg, d_yuv2rgb_control_REG.regValue);

	yuv2rgb_d_yuv2rgb_tab1_data_0_REG.regValue = IoReg_Read32(YUV2RGB_D_YUV2RGB_Tab1_Data_0_reg);
//	d_yuv2rgb_tab2_data_0_REG.regValue = IoReg_Read32(YUV2RGB_D_YUV2RGB_Tab2_Data_0_reg); //juwen, remove

	/*20140220 roger for new mode START ================================*/
	yuv2rgb_d_yuv2rgb_tab1_data_clamp_reg.regValue = IoReg_Read32(YUV2RGB_D_YUV2RGB_Tab1_Data_Clamp_reg);

#ifdef CONFIG_HDR_DEMO
#else
	if (csp_control == RGB2YUV_OUT_DATA_16_235) {
		if (Contrast < (255 - 21))
			Contrast = Contrast + 21;
		else
			Contrast = 255;
		yuv2rgb_d_yuv2rgb_tab1_data_clamp_reg.y_clamp = 1;
	} else {
		yuv2rgb_d_yuv2rgb_tab1_data_clamp_reg.y_clamp = 0;
	}
#endif
	IoReg_Write32(YUV2RGB_D_YUV2RGB_Tab1_Data_Clamp_reg, yuv2rgb_d_yuv2rgb_tab1_data_clamp_reg.regValue);
	/*20140220 roger for new mode END ================================*/


	/*new_K11 = ((2056 * Contrast) >> 10) & 0x1ff;*/ /*20100120 jerry wu for gray lose*/
	new_K11 = (2 * Contrast) & 0x1ff;	/*20140219 roger, back the coef first*/

#if 0	/*#ifdef CONFIG_DUAL_CHANNEL*/
	d_yuv2rgb_tab2_data_4_RBUS d_yuv2rgb_tab2_data_4_REG;
	d_yuv2rgb_tab2_data_5_RBUS d_yuv2rgb_tab2_data_5_REG;
	d_yuv2rgb_tab2_data_6_RBUS d_yuv2rgb_tab2_data_6_REG;
#endif

	/*Thur modified for compile 20090113*/
	/*IoReg_BusyCheckRegBit(DDOMAIN_MAIN_DISPLAY_CONTROL_RSV_VADDR,_BIT10, 0x0001FFFF);*/
	/*IoReg_BusyCheckRegBit(PPOVERLAY_Main_Display_Control_RSV_reg,_BIT10, 0x0001FFFF);*/

	/*WaitFor_DEN_STOP();  */ /*zhiling_xiao 101014 for gabige by adjust contrast*/


	/*====== planck add for osd con and bri getting down, sat must be down.20101019 <start>=================*/
#if 0	/*#if !CONFIG_AT_TV013_1_BOARD_296C	*/ /*USER: Vincent_Lee  DATE: 2011/01/07  TODO: change saturation value when contrast or brightness changed.*/
	temp_value = MAX(Contrast, Brightness);

	/*osdSat = fwif_color_get_saturation(Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display, SLR_INPUT_DATA_ARRAY_IDX));*/
	osdSat = 50;

	if (temp_value < 128) {
		osdSat = (temp_value * osdSat)/128;
	}

	if (osdSat >= 50)
		osdSat = 50;

	/*drvif_color_setuv_sat(display, sat);*/
	if (Scaler_GetSignalStatus() == SCALER_SIGNAL_DISPLAY)
		drvif_sRGB_SetHueSat(display, 0, osdSat);
	VIPprintf("== temp_value =%d ==\n", temp_value);
	if (temp_value == 0) {
		drvif_color_setuv_sat(display, 0);
	} else if (temp_value <= 2) {
		osdSat = fwif_color_get_saturation(Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display, SLR_INPUT_DATA_ARRAY_IDX));
		osdSat = (osdSat*2.55);
		drvif_color_setuv_sat(display, osdSat);
	}
#endif
	/*====== planck add for osd con and bri getting down, sat must be down.20101019 <end>=================*/

	yuv2rgb_d_yuv2rgb_tab1_data_0_REG.regValue = IoReg_Read32(YUV2RGB_D_YUV2RGB_Tab1_Data_0_reg);
	if (display  == SLR_MAIN_DISPLAY) {
		/*WaitFor_DEN_STOP();*/
		/*USER: Vincent_Lee  DATE: 2011/8/26  TODO: Add YUV2RGB_tab1 buffer*/
		yuv2rgb_tab1_data0_buffer.k11 = new_K11;
		IoReg_Write32(YUV2RGB_D_YUV2RGB_Tab1_Data_0_reg, yuv2rgb_tab1_data0_buffer.regValue);

		/*new_RGB_offset = ((Brightness -128) << 5)&0x1fff; */ /* old shift:3, modified by Jerry Wu 20071012*/
		/*new_RGB_offset = ((Brightness-128) << 7) & 0x1ffff;*/ /*modified by Flora, for Sirius; re-modified by Elsie 20140205*/
		new_RGB_offset = ((Brightness-128) << 5) & 0x1ffff;	/*20140220 roger for sync the brightness step with Mac, Magellen		*/ /*modified by Flora, for Sirius; re-modified by Elsie 20140205*/

		yuv2rgb_d_yuv2rgb_tab1_data_4_REG.roffset = new_RGB_offset;
		yuv2rgb_d_yuv2rgb_tab1_data_5_REG.goffset = new_RGB_offset;
		yuv2rgb_d_yuv2rgb_tab1_data_6_REG.boffset = new_RGB_offset;

		IoReg_Write32(YUV2RGB_D_YUV2RGB_Tab1_Data_4_reg, yuv2rgb_d_yuv2rgb_tab1_data_4_REG.regValue);
		IoReg_Write32(YUV2RGB_D_YUV2RGB_Tab1_Data_5_reg, yuv2rgb_d_yuv2rgb_tab1_data_5_REG.regValue);
		IoReg_Write32(YUV2RGB_D_YUV2RGB_Tab1_Data_6_reg, yuv2rgb_d_yuv2rgb_tab1_data_6_REG.regValue);

		/*VIPprintf("YUV2RGB_D_YUV2RGB_Tab1_Data_0_reg:0x%x\n", yuv2rgb_d_yuv2rgb_tab1_data_0_REG.regValue);*/ /*planck*/
		/*VIPprintf("YUV2RGB_D_YUV2RGB_Tab1_Data_2_reg:0x%x\n", yuv2rgb_d_yuv2rgb_tab1_data_2_REG.regValue);*/ /*planck*/
		/*VIPprintf("YUV2RGB_D_YUV2RGB_Tab1_Data_3_reg:0x%x\n", yuv2rgb_d_yuv2rgb_tab1_data_3_REG.regValue);*/ /*planck*/

	}
#if 0	/*#ifdef CONFIG_DUAL_CHANNEL*/
	else {
		d_yuv2rgb_tab2_data_0_REG.k11 = new_K11;
		IoReg_Write32(YUV2RGB_D_YUV2RGB_Tab2_Data_0_reg, d_yuv2rgb_tab2_data_0_REG.regValue);

		/*new_RGB_offset = ((Brightness -128) << 5)&0x1fff; */ /*  old shift:3, modified by Jerry Wu 20071105*/
		/*new_RGB_offset = ((Brightness-128) << 7) & 0x1ffff;	*/ /*20140219 roger sync from main*/
		new_RGB_offset = ((Brightness-128) << 5) & 0x1ffff;	/*20140220 roger for sync the brightness step with Mac, Magellen		*/ /*modified by Flora, for Sirius; re-modified by Elsie 20140205*/

		d_yuv2rgb_tab2_data_4_REG.roffset = new_RGB_offset;
		d_yuv2rgb_tab2_data_5_REG.goffset = new_RGB_offset;
		d_yuv2rgb_tab2_data_6_REG.boffset = new_RGB_offset;
		IoReg_Write32(YUV2RGB_D_YUV2RGB_Tab2_Data_4_reg, d_yuv2rgb_tab2_data_4_REG.regValue);
		IoReg_Write32(YUV2RGB_D_YUV2RGB_Tab2_Data_5_reg, d_yuv2rgb_tab2_data_5_REG.regValue);
		IoReg_Write32(YUV2RGB_D_YUV2RGB_Tab2_Data_6_reg, d_yuv2rgb_tab2_data_6_REG.regValue);

	}
#endif

		/*======== planck add for update Brightness and contrast double buffer reg.20100823 ===============*/
		IoReg_Write32(YUV2RGB_D_YUV2RGB_Control_reg, d_yuv2rgb_control_REG.regValue);
		d_yuv2rgb_control_1_reg.yuv2rgb_db_apply = 1;  /* 20100811, double buffer en , csfanchiang*/
		IoReg_Write32(YUV2RGB_D_YUV2RGB_Control_1_reg, d_yuv2rgb_control_1_reg.regValue);
		/*======================================================================*/
		/*VIPprintf("buffer_status_count!!\n");*/
		/*VIPprintf("buffer_status_count!!\n");*/
		/*VIPprintf("buffer_status_count!!\n");*/
		/*WaitFor_DEN_STOP();*/
	VIPprintf("$$$check yuv2rgb double buffer buffer_status =%d!!", d_yuv2rgb_control_1_reg.yuv2rgb_db_apply);
	/*WaitFor_DEN_STOP();*/
	do {/* check double buffer status complete*/
		d_yuv2rgb_control_1_reg.regValue = IoReg_Read32(YUV2RGB_D_YUV2RGB_Control_1_reg);
		/*VIPprintf("@@@@buffer_status_count =%d, double_buffer_reg =%d\n", buffer_status_count, d_yuv2rgb_control_REG.yuv2rgb_db_apply);*/
		buffer_status_count++;
	} while (d_yuv2rgb_control_1_reg.yuv2rgb_db_apply != 0 && buffer_status_count < 300);
	VIPprintf("$$$check YUV2RGB double buffer buffer_status =%d!!", d_yuv2rgb_control_1_reg.yuv2rgb_db_apply);

}

void drvif_color_setYUV2RGB_CSMatrix(DRV_VIP_YUV2RGB_CSMatrix *ptr, VIP_CSMatrix_WriteType WriteMode, VIP_YUV2RGB_Y_SEG seg,
unsigned char display, VIP_Table_Select tbl)
{
	SCALER_DISP_CHANNEL ch;
	unsigned char i;
	unsigned short buffer_status_count, buffer_status_count_th = 300;
	yuv2rgb_d_yuv2rgb_control_RBUS d_yuv2rgb_control_REG;
	yuv2rgb_d_yuv2rgb_control_1_RBUS d_yuv2rgb_control_1_reg;
	yuv2rgb_d_yuv2rgb_tab1_data_clamp_RBUS yuv2rgb_d_yuv2rgb_tab1_data_clamp_REG;
//	yuv2rgb_d_yuv2rgb_tab2_data_clamp_RBUS yuv2rgb_d_yuv2rgb_tab2_data_clamp_REG;// juwen, remove
	yuv2rgb_d_yuv2rgbbyy_control_RBUS d_yuv2rgbbyy_control_REG;
	yuv2rgb_d_uvoffsetbyy_control_RBUS d_uvoffsetbyy_control_REG;
	yuv2rgb_d_yuv2rgb_tab1_data_0_RBUS yuv2rgb_d_yuv2rgb_tab1_data_0_REG;
	yuv2rgb_d_yuv2rgb_tab1_data_1_RBUS yuv2rgb_d_yuv2rgb_tab1_data_1_REG;
	yuv2rgb_d_yuv2rgb_tab1_data_2_RBUS yuv2rgb_d_yuv2rgb_tab1_data_2_REG;
	yuv2rgb_d_yuv2rgb_tab1_data_3_RBUS yuv2rgb_d_yuv2rgb_tab1_data_3_REG;
	yuv2rgb_d_yuv2rgb_tab1_data_4_RBUS yuv2rgb_d_yuv2rgb_tab1_data_4_REG;
	yuv2rgb_d_yuv2rgb_tab1_data_5_RBUS yuv2rgb_d_yuv2rgb_tab1_data_5_REG;
	yuv2rgb_d_yuv2rgb_tab1_data_6_RBUS yuv2rgb_d_yuv2rgb_tab1_data_6_REG;
	yuv2rgb_d_uvoffsetbyy_u_tab_data_1_RBUS yuv2rgb_d_uvoffsetbyy_u_tab_data_1_REG;
	yuv2rgb_d_uvoffsetbyy_u_tab_data_2_RBUS yuv2rgb_d_uvoffsetbyy_u_tab_data_2_REG;
	yuv2rgb_d_uvoffsetbyy_u_tab_data_3_RBUS yuv2rgb_d_uvoffsetbyy_u_tab_data_3_REG;
	yuv2rgb_d_uvoffsetbyy_u_tab_data_4_RBUS yuv2rgb_d_uvoffsetbyy_u_tab_data_4_REG;
	yuv2rgb_d_uvoffsetbyy_u_tab_data_5_RBUS yuv2rgb_d_uvoffsetbyy_u_tab_data_5_REG;
	yuv2rgb_d_uvoffsetbyy_v_tab_data_1_RBUS yuv2rgb_d_uvoffsetbyy_v_tab_data_1_REG;
	yuv2rgb_d_uvoffsetbyy_v_tab_data_2_RBUS yuv2rgb_d_uvoffsetbyy_v_tab_data_2_REG;
	yuv2rgb_d_uvoffsetbyy_v_tab_data_3_RBUS yuv2rgb_d_uvoffsetbyy_v_tab_data_3_REG;
	yuv2rgb_d_uvoffsetbyy_v_tab_data_4_RBUS yuv2rgb_d_uvoffsetbyy_v_tab_data_4_REG;
	yuv2rgb_d_uvoffsetbyy_v_tab_data_5_RBUS yuv2rgb_d_uvoffsetbyy_v_tab_data_5_REG;
	yuv2rgb_d_uvoffsetbyy_u_tab_step_1_RBUS yuv2rgb_d_uvoffsetbyy_u_tab_step_1_REG;
	yuv2rgb_d_uvoffsetbyy_u_tab_step_2_RBUS yuv2rgb_d_uvoffsetbyy_u_tab_step_2_REG;
	yuv2rgb_d_uvoffsetbyy_u_tab_step_3_RBUS yuv2rgb_d_uvoffsetbyy_u_tab_step_3_REG;
	yuv2rgb_d_uvoffsetbyy_u_tab_step_4_RBUS yuv2rgb_d_uvoffsetbyy_u_tab_step_4_REG;
	yuv2rgb_d_uvoffsetbyy_u_tab_step_5_RBUS yuv2rgb_d_uvoffsetbyy_u_tab_step_5_REG;
	yuv2rgb_d_uvoffsetbyy_v_tab_step_1_RBUS yuv2rgb_d_uvoffsetbyy_v_tab_step_1_REG;
	yuv2rgb_d_uvoffsetbyy_v_tab_step_2_RBUS yuv2rgb_d_uvoffsetbyy_v_tab_step_2_REG;
	yuv2rgb_d_uvoffsetbyy_v_tab_step_3_RBUS yuv2rgb_d_uvoffsetbyy_v_tab_step_3_REG;
	yuv2rgb_d_uvoffsetbyy_v_tab_step_4_RBUS yuv2rgb_d_uvoffsetbyy_v_tab_step_4_REG;
	yuv2rgb_d_uvoffsetbyy_v_tab_step_5_RBUS yuv2rgb_d_uvoffsetbyy_v_tab_step_5_REG;

	yuv2rgb_d_coefbyy_nonlinear_0_RBUS yuv2rgb_d_coefbyy_nonlinear_0_REG;			/* Mac3 add by chris @20140721*/
	yuv2rgb_d_offsetbyy_nonlinear_0_RBUS yuv2rgb_d_offsetbyy_nonlinear_0_REG;		/* Mac3 add by chris @20140721*/

//	yuv2rgb_d_yuv2rgb_tab1_data_7_RBUS yuv2rgb_d_yuv2rgb_tab1_data_7_REG;// juwen, remove
//	yuv2rgb_d_yuv2rgb_tab2_data_7_RBUS yuv2rgb_d_yuv2rgb_tab2_data_7_REG;// juwen, remove

#ifdef CONFIG_HDR_DEMO
	_system_setting_info *VIP_system_info_structure_table=NULL;
	VIP_system_info_structure_table = (_system_setting_info*)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_system_info_structure);
#endif
	d_yuv2rgb_control_1_reg.regValue = IoReg_Read32(YUV2RGB_D_YUV2RGB_Control_1_reg);
	d_yuv2rgb_control_1_reg.yuv2rgb_db_en = 1;
	d_yuv2rgb_control_1_reg.yuv2rgb_db_read_level = 1;
	IoReg_Write32(YUV2RGB_D_YUV2RGB_Control_1_reg, d_yuv2rgb_control_1_reg.regValue);

	buffer_status_count = buffer_status_count_th;

	ch = (SCALER_DISP_CHANNEL)display;

	switch (WriteMode) {
	case VIP_CSMatrix_YUV2RGB_Base_Ctrl:
		d_yuv2rgb_control_REG.regValue = IoReg_Read32(YUV2RGB_D_YUV2RGB_Control_reg);
		yuv2rgb_d_yuv2rgb_tab1_data_clamp_REG.regValue = IoReg_Read32(YUV2RGB_D_YUV2RGB_Tab1_Data_Clamp_reg);
//		yuv2rgb_d_yuv2rgb_tab2_data_clamp_REG.regValue = IoReg_Read32(YUV2RGB_D_YUV2RGB_Tab2_Data_Clamp_reg);// juwen, remove
		if ((ch > SLR_SUB_DISPLAY) || (tbl > VIP_Table_Select_2)) {
			VIPprintf("~~drvif_color_setYUV2RGB_CSMatrix Error, CH or tbl select error, CH = %d, TBL = %d~~\n ", ch, tbl);
			return;
		}
		if (ch == SLR_MAIN_DISPLAY) {
//			d_yuv2rgb_control_REG.yuv2rgb_overlay = ptr->CTRL_ITEM.Overlay;// juwen, remove
			d_yuv2rgb_control_REG.yuv2rgb_main_en = ptr->CTRL_ITEM.YUV2RGB_Enable_Main;
			d_yuv2rgb_control_REG.yuv2rgb_main_tab_sel = ptr->CTRL_ITEM.Table_Select_Main;
			d_yuv2rgb_control_REG.yuv2rgb_main_out_shift = ptr->CTRL_ITEM.OutShift_En_Main;
		}
#if 1/*def VIP_CONFIG_DUAL_CHENNEL*/
#ifdef VIP_CONFIG_DUAL_CHANNEL // henry 161214
		else {
			d_yuv2rgb_control_REG.yuv2rgb_overlay = ptr->CTRL_ITEM.Overlay;
			d_yuv2rgb_control_REG.yuv2rgb_sub_en = ptr->CTRL_ITEM.YUV2RGB_Enable_Sub;
			d_yuv2rgb_control_REG.yuv2rgb_sub_tab_sel = ptr->CTRL_ITEM.Table_Select_Sub;
			d_yuv2rgb_control_REG.yuv2rgb_sub_out_shift = ptr->CTRL_ITEM.OutShift_En_Sub;
		}
#endif
#endif
//		if (tbl == VIP_Table_Select_1)
//			yuv2rgb_d_yuv2rgb_tab1_data_clamp_REG.bt2020_en = ptr->CTRL_ITEM.Bt2020_En_TBL1;//juwen, remove
//		else
//			yuv2rgb_d_yuv2rgb_tab2_data_clamp_REG.bt2020_en = ptr->CTRL_ITEM.Bt2020_En_TBL2;//juwen, remove
		/* TBL1 and 2 is same for CbCr Clamp*/
		yuv2rgb_d_yuv2rgb_tab1_data_clamp_REG.cb_cr_clamp = ptr->CTRL_ITEM.CbCr_Clamp;
//		yuv2rgb_d_yuv2rgb_tab2_data_clamp_REG.cb_cr_clamp = ptr->CTRL_ITEM.CbCr_Clamp;//juwen, remove
		IoReg_Write32(YUV2RGB_D_YUV2RGB_Tab1_Data_Clamp_reg, yuv2rgb_d_yuv2rgb_tab1_data_clamp_REG.regValue);
		IoReg_Write32(YUV2RGB_D_YUV2RGB_Control_reg, d_yuv2rgb_control_REG.regValue);
//		IoReg_Write32(YUV2RGB_D_YUV2RGB_Tab2_Data_Clamp_reg, yuv2rgb_d_yuv2rgb_tab2_data_clamp_REG.regValue);//juwen, remove
		break;

	case VIP_CSMatrix_Coef_Y_Only:
		if (seg == VIP_YUV2RGB_Y_Seg_0) {
			yuv2rgb_d_yuv2rgb_tab1_data_0_REG.k11 = ptr->COEF_By_Y.K11[seg];
			if (tbl == VIP_Table_Select_1) {
				IoReg_WriteWord1(YUV2RGB_D_YUV2RGB_Tab1_Data_0_reg, yuv2rgb_d_yuv2rgb_tab1_data_0_REG.k11);
			} else if (tbl == VIP_Table_Select_2) {
//				IoReg_WriteWord1(YUV2RGB_D_YUV2RGB_Tab2_Data_0_reg, yuv2rgb_d_yuv2rgb_tab1_data_0_REG.k11);//juwen, remove
			} else {
				VIPprintf("~~drvif_color_setYUV2RGB_CSMatrix Error, Table2 can't set matrix by Y~~\n ");
				return;
			}
		} else if (seg == VIP_YUV2RGB_Y_Seg_Max) {
			if (tbl != VIP_Table_Select_1) {
				VIPprintf("~~drvif_color_setYUV2RGB_CSMatrix Error, TBL selec error~~\n ");
				return;
			}
			for (i = 0; i < VIP_YUV2RGB_Y_Seg_Max; i++) {
				yuv2rgb_d_yuv2rgb_tab1_data_0_REG.k11 = ptr->COEF_By_Y.K11[i];
				if (i == VIP_YUV2RGB_Y_Seg_0) {
					IoReg_WriteWord1(YUV2RGB_D_YUV2RGB_Tab1_Data_0_reg, yuv2rgb_d_yuv2rgb_tab1_data_0_REG.k11);
				} else if (i < VIP_YUV2RGB_Y_Seg_5) {
					IoReg_WriteWord1(YUV2RGB_D_YUV2RGBBYY_Tab_Data_1_0_reg+((i-1)*4*4), yuv2rgb_d_yuv2rgb_tab1_data_0_REG.k11);
				} else {
					IoReg_WriteWord1(YUV2RGB_D_YUV2RGBBYY_Tab_Data_5_0_reg+((i-5)*4*4), yuv2rgb_d_yuv2rgb_tab1_data_0_REG.k11);
				}
			}
		} else {
			if (tbl != VIP_Table_Select_1) {
				VIPprintf("~~drvif_color_setYUV2RGB_CSMatrix Error, Table2 can't set matrix by Y~~\n ");
				return;
			}
			yuv2rgb_d_yuv2rgb_tab1_data_0_REG.k11 = ptr->COEF_By_Y.K11[seg];
			if (seg < VIP_YUV2RGB_Y_Seg_5) {
				IoReg_WriteWord1(YUV2RGB_D_YUV2RGBBYY_Tab_Data_1_0_reg+((seg-1)*4*4), yuv2rgb_d_yuv2rgb_tab1_data_0_REG.k11);
			} else {
				IoReg_WriteWord1(YUV2RGB_D_YUV2RGBBYY_Tab_Data_5_0_reg+((seg-5)*4*4), yuv2rgb_d_yuv2rgb_tab1_data_0_REG.k11);
			}
		}
		buffer_status_count = 0;
		break;

	case VIP_CSMatrix_Coef_C_Only:
		if (seg == VIP_YUV2RGB_Y_Seg_0) {
			yuv2rgb_d_yuv2rgb_tab1_data_0_REG.k12 = ptr->COEF_By_Y.K12[seg];
			yuv2rgb_d_yuv2rgb_tab1_data_1_REG.k13 = ptr->COEF_By_Y.K13[seg];
			yuv2rgb_d_yuv2rgb_tab1_data_2_REG.k22 = ptr->COEF_By_Y.K22[seg];
			yuv2rgb_d_yuv2rgb_tab1_data_2_REG.k23 = ptr->COEF_By_Y.K23[seg];
			yuv2rgb_d_yuv2rgb_tab1_data_3_REG.k32 = ptr->COEF_By_Y.K32[seg];
			yuv2rgb_d_yuv2rgb_tab1_data_3_REG.k33 = ptr->COEF_By_Y.K33[seg];
			if (tbl == VIP_Table_Select_1) {
				IoReg_WriteWord0(YUV2RGB_D_YUV2RGB_Tab1_Data_0_reg, yuv2rgb_d_yuv2rgb_tab1_data_0_REG.k12);
				IoReg_Write32(YUV2RGB_D_YUV2RGB_Tab1_Data_1_reg, yuv2rgb_d_yuv2rgb_tab1_data_1_REG.regValue);
				IoReg_Write32(YUV2RGB_D_YUV2RGB_Tab1_Data_2_reg, yuv2rgb_d_yuv2rgb_tab1_data_2_REG.regValue);
				IoReg_Write32(YUV2RGB_D_YUV2RGB_Tab1_Data_3_reg, yuv2rgb_d_yuv2rgb_tab1_data_3_REG.regValue);
			} else if (tbl == VIP_Table_Select_2) {
#if 0 //juwen, remove
				IoReg_WriteWord0(YUV2RGB_D_YUV2RGB_Tab2_Data_0_reg, yuv2rgb_d_yuv2rgb_tab1_data_0_REG.k12);
				IoReg_Write32(YUV2RGB_D_YUV2RGB_Tab2_Data_1_reg, yuv2rgb_d_yuv2rgb_tab1_data_1_REG.regValue);
				IoReg_Write32(YUV2RGB_D_YUV2RGB_Tab2_Data_2_reg, yuv2rgb_d_yuv2rgb_tab1_data_2_REG.regValue);
				IoReg_Write32(YUV2RGB_D_YUV2RGB_Tab2_Data_3_reg, yuv2rgb_d_yuv2rgb_tab1_data_3_REG.regValue);
#endif
			} else {
				VIPprintf("~~drvif_color_setYUV2RGB_CSMatrix Error, TBL selec error~~\n ");
				return;
			}
		} else if (seg == VIP_YUV2RGB_Y_Seg_Max) {
			if (tbl != VIP_Table_Select_1) {
				VIPprintf("~~drvif_color_setYUV2RGB_CSMatrix Error, Table2 can't set matrix by Y~~\n ");
				return;
			}
			for (i = 0; i < VIP_YUV2RGB_Y_Seg_Max; i++) {
				yuv2rgb_d_yuv2rgb_tab1_data_0_REG.k12 = ptr->COEF_By_Y.K12[i];
				yuv2rgb_d_yuv2rgb_tab1_data_1_REG.k13 = ptr->COEF_By_Y.K13[i];
				yuv2rgb_d_yuv2rgb_tab1_data_2_REG.k22 = ptr->COEF_By_Y.K22[i];
				yuv2rgb_d_yuv2rgb_tab1_data_2_REG.k23 = ptr->COEF_By_Y.K23[i];
				yuv2rgb_d_yuv2rgb_tab1_data_3_REG.k32 = ptr->COEF_By_Y.K32[i];
				yuv2rgb_d_yuv2rgb_tab1_data_3_REG.k33 = ptr->COEF_By_Y.K33[i];
				if (i == VIP_YUV2RGB_Y_Seg_0) {
					IoReg_WriteWord0(YUV2RGB_D_YUV2RGB_Tab1_Data_0_reg, yuv2rgb_d_yuv2rgb_tab1_data_0_REG.k12);
					IoReg_Write32(YUV2RGB_D_YUV2RGB_Tab1_Data_1_reg, yuv2rgb_d_yuv2rgb_tab1_data_1_REG.regValue);
					IoReg_Write32(YUV2RGB_D_YUV2RGB_Tab1_Data_2_reg, yuv2rgb_d_yuv2rgb_tab1_data_2_REG.regValue);
					IoReg_Write32(YUV2RGB_D_YUV2RGB_Tab1_Data_3_reg, yuv2rgb_d_yuv2rgb_tab1_data_3_REG.regValue);
				} else if (i < VIP_YUV2RGB_Y_Seg_4) {
					IoReg_WriteWord0(YUV2RGB_D_YUV2RGBBYY_Tab_Data_1_0_reg+((i-1)*4*4), yuv2rgb_d_yuv2rgb_tab1_data_0_REG.k12);
					IoReg_Write32(YUV2RGB_D_YUV2RGBBYY_Tab_Data_1_1_reg+((i-1)*4*4), yuv2rgb_d_yuv2rgb_tab1_data_1_REG.regValue);
					IoReg_Write32(YUV2RGB_D_YUV2RGBBYY_Tab_Data_1_2_reg+((i-1)*4*4), yuv2rgb_d_yuv2rgb_tab1_data_2_REG.regValue);
					IoReg_Write32(YUV2RGB_D_YUV2RGBBYY_Tab_Data_1_3_reg+((i-1)*4*4), yuv2rgb_d_yuv2rgb_tab1_data_3_REG.regValue);
				} else if (i == VIP_YUV2RGB_Y_Seg_4) {
					IoReg_WriteWord0(YUV2RGB_D_YUV2RGBBYY_Tab_Data_4_0_reg, yuv2rgb_d_yuv2rgb_tab1_data_0_REG.k12);
					IoReg_Write32(YUV2RGB_D_YUV2RGBBYY_Tab_Data_4_1_reg, yuv2rgb_d_yuv2rgb_tab1_data_1_REG.regValue);
					IoReg_Write32(YUV2RGB_D_YUV2RGBBYY_Tab_Data_4_2_reg, yuv2rgb_d_yuv2rgb_tab1_data_2_REG.regValue);
					IoReg_Write32(YUV2RGB_D_YUV2RGBBYY_Tab_Data_4_3_reg, yuv2rgb_d_yuv2rgb_tab1_data_3_REG.regValue);
				} else {
					IoReg_WriteWord0(YUV2RGB_D_YUV2RGBBYY_Tab_Data_5_0_reg+((i-5)*4*4), yuv2rgb_d_yuv2rgb_tab1_data_0_REG.k12);
					IoReg_Write32(YUV2RGB_D_YUV2RGBBYY_Tab_Data_5_1_reg+((i-5)*4*4), yuv2rgb_d_yuv2rgb_tab1_data_1_REG.regValue);
					IoReg_Write32(YUV2RGB_D_YUV2RGBBYY_Tab_Data_5_2_reg+((i-5)*4*4), yuv2rgb_d_yuv2rgb_tab1_data_2_REG.regValue);
					IoReg_Write32(YUV2RGB_D_YUV2RGBBYY_Tab_Data_5_3_reg+((i-5)*4*4), yuv2rgb_d_yuv2rgb_tab1_data_3_REG.regValue);
				}
			}
		} else {
			if (tbl != VIP_Table_Select_1) {
				VIPprintf("~~drvif_color_setYUV2RGB_CSMatrix Error, Table2 can't set matrix by Y~~\n ");
				return;
			}
			yuv2rgb_d_yuv2rgb_tab1_data_0_REG.k12 = ptr->COEF_By_Y.K12[seg];
			yuv2rgb_d_yuv2rgb_tab1_data_1_REG.k13 = ptr->COEF_By_Y.K13[seg];
			yuv2rgb_d_yuv2rgb_tab1_data_2_REG.k22 = ptr->COEF_By_Y.K22[seg];
			yuv2rgb_d_yuv2rgb_tab1_data_2_REG.k23 = ptr->COEF_By_Y.K23[seg];
			yuv2rgb_d_yuv2rgb_tab1_data_3_REG.k32 = ptr->COEF_By_Y.K32[seg];
			yuv2rgb_d_yuv2rgb_tab1_data_3_REG.k33 = ptr->COEF_By_Y.K33[seg];
			if (seg < VIP_YUV2RGB_Y_Seg_4) {
				IoReg_WriteWord0(YUV2RGB_D_YUV2RGBBYY_Tab_Data_1_0_reg+((seg-1)*4*4), yuv2rgb_d_yuv2rgb_tab1_data_0_REG.k12);
				IoReg_Write32(YUV2RGB_D_YUV2RGBBYY_Tab_Data_1_1_reg+((seg-1)*4*4), yuv2rgb_d_yuv2rgb_tab1_data_1_REG.regValue);
				IoReg_Write32(YUV2RGB_D_YUV2RGBBYY_Tab_Data_1_2_reg+((seg-1)*4*4), yuv2rgb_d_yuv2rgb_tab1_data_2_REG.regValue);
				IoReg_Write32(YUV2RGB_D_YUV2RGBBYY_Tab_Data_1_3_reg+((seg-1)*4*4), yuv2rgb_d_yuv2rgb_tab1_data_3_REG.regValue);
			} else if (seg == VIP_YUV2RGB_Y_Seg_4) {
				IoReg_WriteWord0(YUV2RGB_D_YUV2RGBBYY_Tab_Data_4_0_reg, yuv2rgb_d_yuv2rgb_tab1_data_0_REG.k12);
				IoReg_Write32(YUV2RGB_D_YUV2RGBBYY_Tab_Data_4_1_reg, yuv2rgb_d_yuv2rgb_tab1_data_1_REG.regValue);
				IoReg_Write32(YUV2RGB_D_YUV2RGBBYY_Tab_Data_4_2_reg, yuv2rgb_d_yuv2rgb_tab1_data_2_REG.regValue);
				IoReg_Write32(YUV2RGB_D_YUV2RGBBYY_Tab_Data_4_3_reg, yuv2rgb_d_yuv2rgb_tab1_data_3_REG.regValue);
			} else {
				IoReg_WriteWord0(YUV2RGB_D_YUV2RGBBYY_Tab_Data_5_0_reg+((seg-5)*4*4), yuv2rgb_d_yuv2rgb_tab1_data_0_REG.k12);
				IoReg_Write32(YUV2RGB_D_YUV2RGBBYY_Tab_Data_5_1_reg+((seg-5)*4*4), yuv2rgb_d_yuv2rgb_tab1_data_1_REG.regValue);
				IoReg_Write32(YUV2RGB_D_YUV2RGBBYY_Tab_Data_5_2_reg+((seg-5)*4*4), yuv2rgb_d_yuv2rgb_tab1_data_2_REG.regValue);
				IoReg_Write32(YUV2RGB_D_YUV2RGBBYY_Tab_Data_5_3_reg+((seg-5)*4*4), yuv2rgb_d_yuv2rgb_tab1_data_3_REG.regValue);
			}
		}
		buffer_status_count = 0;
		break;

	case VIP_CSMatrix_Offset_Only:
		yuv2rgb_d_yuv2rgb_tab1_data_4_REG.roffset = ptr->RGB_Offset.R_offset;
		yuv2rgb_d_yuv2rgb_tab1_data_5_REG.goffset = ptr->RGB_Offset.G_offset;
		yuv2rgb_d_yuv2rgb_tab1_data_6_REG.boffset = ptr->RGB_Offset.B_offset;
		if (tbl == VIP_Table_Select_1) {
			IoReg_Write32(YUV2RGB_D_YUV2RGB_Tab1_Data_4_reg, yuv2rgb_d_yuv2rgb_tab1_data_4_REG.regValue);
			IoReg_Write32(YUV2RGB_D_YUV2RGB_Tab1_Data_5_reg, yuv2rgb_d_yuv2rgb_tab1_data_5_REG.regValue);
			IoReg_Write32(YUV2RGB_D_YUV2RGB_Tab1_Data_6_reg, yuv2rgb_d_yuv2rgb_tab1_data_6_REG.regValue);
		} else if (tbl == VIP_Table_Select_2) {
#if 0 // juwen, remove
			IoReg_Write32(YUV2RGB_D_YUV2RGB_Tab2_Data_4_reg, yuv2rgb_d_yuv2rgb_tab1_data_4_REG.regValue);
			IoReg_Write32(YUV2RGB_D_YUV2RGB_Tab2_Data_5_reg, yuv2rgb_d_yuv2rgb_tab1_data_5_REG.regValue);
			IoReg_Write32(YUV2RGB_D_YUV2RGB_Tab2_Data_6_reg, yuv2rgb_d_yuv2rgb_tab1_data_6_REG.regValue);
#endif
		} else {
			VIPprintf("~~drvif_color_setYUV2RGB_CSMatrix Error, TBL selec error~~\n ");
			return;
		}
		buffer_status_count = 0;
		break;

	case VIP_CSMatrix_Y_Clamp:
		yuv2rgb_d_yuv2rgb_tab1_data_clamp_REG.regValue = IoReg_Read32(YUV2RGB_D_YUV2RGB_Tab1_Data_Clamp_reg);
		yuv2rgb_d_yuv2rgb_tab1_data_clamp_REG.y_clamp = ptr->CTRL_ITEM.Y_Clamp;
		if (tbl == VIP_Table_Select_1)
			IoReg_Write32(YUV2RGB_D_YUV2RGB_Tab1_Data_Clamp_reg, yuv2rgb_d_yuv2rgb_tab1_data_clamp_REG.regValue);
		else if (tbl == VIP_Table_Select_2){}
//			IoReg_Write32(YUV2RGB_D_YUV2RGB_Tab2_Data_Clamp_reg, yuv2rgb_d_yuv2rgb_tab1_data_clamp_REG.regValue);//juwen, remove
		else {
			VIPprintf("~~drvif_color_setYUV2RGB_CSMatrix Error, TBL selec error~~\n ");
			return;
		}
		break;

	case VIP_CSMatrix_CoefByY_ctrl:
		d_yuv2rgbbyy_control_REG.regValue = IoReg_Read32(YUV2RGB_D_YUV2RGBBYY_CONTROL_reg);
		d_yuv2rgbbyy_control_REG.yuv2rgbbymode_main_en = ptr->CTRL_ITEM.CoefByY_En;
		/*d_yuv2rgbbyy_control_REG.yuv2rgbbyy_sub_en = ptr->CoefByY_En;*/

		/*	add coef by saturation from Mag2 - chris 20150304*/
		d_yuv2rgbbyy_control_REG.yuv2rgb_coef_by_sat_mode = ptr->CTRL_ITEM.CoefBySat_mode;
		d_yuv2rgbbyy_control_REG.yuv2rgb_coef_by_sat_gain = ptr->CTRL_ITEM.CoefBySat_gain;

		IoReg_Write32(YUV2RGB_D_YUV2RGBBYY_CONTROL_reg, d_yuv2rgbbyy_control_REG.regValue);
		buffer_status_count = 0;
		break;
	case VIP_CSMatrix_UVOffset_ctrl:
		d_uvoffsetbyy_control_REG.regValue = IoReg_Read32(YUV2RGB_D_UVOFFSETBYY_CONTROL_reg);
		d_uvoffsetbyy_control_REG.uvoffsetbyy_main_en = ptr->CTRL_ITEM.UVOffset_En;
		d_uvoffsetbyy_control_REG.uvoffsetbyy_mode = ptr->CTRL_ITEM.UVOffset_Mode_Ctrl;
		IoReg_Write32(YUV2RGB_D_UVOFFSETBYY_CONTROL_reg, d_uvoffsetbyy_control_REG.regValue);
		buffer_status_count = 0;
		break;

	case VIP_CSMatrix_UVOffset_Coef:
		yuv2rgb_d_uvoffsetbyy_u_tab_data_1_REG.uoffset_m0 = ptr->UV_Offset.Uoffset[0];
		yuv2rgb_d_uvoffsetbyy_u_tab_data_1_REG.uoffset_m1 = ptr->UV_Offset.Uoffset[1];
		yuv2rgb_d_uvoffsetbyy_u_tab_data_1_REG.uoffset_m2 = ptr->UV_Offset.Uoffset[2];
		yuv2rgb_d_uvoffsetbyy_u_tab_data_1_REG.uoffset_m3 = ptr->UV_Offset.Uoffset[3];
		yuv2rgb_d_uvoffsetbyy_u_tab_data_2_REG.uoffset_m4 = ptr->UV_Offset.Uoffset[4];
		yuv2rgb_d_uvoffsetbyy_u_tab_data_2_REG.uoffset_m5 = ptr->UV_Offset.Uoffset[5];
		yuv2rgb_d_uvoffsetbyy_u_tab_data_2_REG.uoffset_m6 = ptr->UV_Offset.Uoffset[6];
		yuv2rgb_d_uvoffsetbyy_u_tab_data_2_REG.uoffset_m7 = ptr->UV_Offset.Uoffset[7];
		yuv2rgb_d_uvoffsetbyy_u_tab_data_3_REG.uoffset_m8 = ptr->UV_Offset.Uoffset[8];
		yuv2rgb_d_uvoffsetbyy_u_tab_data_3_REG.uoffset_m9 = ptr->UV_Offset.Uoffset[9];
		yuv2rgb_d_uvoffsetbyy_u_tab_data_3_REG.uoffset_m10 = ptr->UV_Offset.Uoffset[10];
		yuv2rgb_d_uvoffsetbyy_u_tab_data_3_REG.uoffset_m11 = ptr->UV_Offset.Uoffset[11];
		yuv2rgb_d_uvoffsetbyy_u_tab_data_4_REG.uoffset_m12 = ptr->UV_Offset.Uoffset[12];
		yuv2rgb_d_uvoffsetbyy_u_tab_data_4_REG.uoffset_m13 = ptr->UV_Offset.Uoffset[13];
		yuv2rgb_d_uvoffsetbyy_u_tab_data_4_REG.uoffset_m14 = ptr->UV_Offset.Uoffset[14];
		yuv2rgb_d_uvoffsetbyy_u_tab_data_4_REG.uoffset_m15 = ptr->UV_Offset.Uoffset[15];
		yuv2rgb_d_uvoffsetbyy_u_tab_data_5_REG.uoffset_m16 = ptr->UV_Offset.Uoffset[16];
		yuv2rgb_d_uvoffsetbyy_v_tab_data_1_REG.voffset_m0 =  ptr->UV_Offset.Voffset[0];
		yuv2rgb_d_uvoffsetbyy_v_tab_data_1_REG.voffset_m1 =  ptr->UV_Offset.Voffset[1];
		yuv2rgb_d_uvoffsetbyy_v_tab_data_1_REG.voffset_m2 =  ptr->UV_Offset.Voffset[2];
		yuv2rgb_d_uvoffsetbyy_v_tab_data_1_REG.voffset_m3 =  ptr->UV_Offset.Voffset[3];
		yuv2rgb_d_uvoffsetbyy_v_tab_data_2_REG.voffset_m4 =  ptr->UV_Offset.Voffset[4];
		yuv2rgb_d_uvoffsetbyy_v_tab_data_2_REG.voffset_m5 =  ptr->UV_Offset.Voffset[5];
		yuv2rgb_d_uvoffsetbyy_v_tab_data_2_REG.voffset_m6 =  ptr->UV_Offset.Voffset[6];
		yuv2rgb_d_uvoffsetbyy_v_tab_data_2_REG.voffset_m7 =  ptr->UV_Offset.Voffset[7];
		yuv2rgb_d_uvoffsetbyy_v_tab_data_3_REG.voffset_m8 =  ptr->UV_Offset.Voffset[8];
		yuv2rgb_d_uvoffsetbyy_v_tab_data_3_REG.voffset_m9 =  ptr->UV_Offset.Voffset[9];
		yuv2rgb_d_uvoffsetbyy_v_tab_data_3_REG.voffset_m10 = ptr->UV_Offset.Voffset[10];
		yuv2rgb_d_uvoffsetbyy_v_tab_data_3_REG.voffset_m11 = ptr->UV_Offset.Voffset[11];
		yuv2rgb_d_uvoffsetbyy_v_tab_data_4_REG.voffset_m12 = ptr->UV_Offset.Voffset[12];
		yuv2rgb_d_uvoffsetbyy_v_tab_data_4_REG.voffset_m13 = ptr->UV_Offset.Voffset[13];
		yuv2rgb_d_uvoffsetbyy_v_tab_data_4_REG.voffset_m14 = ptr->UV_Offset.Voffset[14];
		yuv2rgb_d_uvoffsetbyy_v_tab_data_4_REG.voffset_m15 = ptr->UV_Offset.Voffset[15];
		yuv2rgb_d_uvoffsetbyy_v_tab_data_5_REG.voffset_m16 = ptr->UV_Offset.Voffset[16];
		yuv2rgb_d_uvoffsetbyy_u_tab_step_1_REG.ustep_m0 =	 ptr->UV_Offset.Ustep[0];
		yuv2rgb_d_uvoffsetbyy_u_tab_step_1_REG.ustep_m1 =	 ptr->UV_Offset.Ustep[1];
		yuv2rgb_d_uvoffsetbyy_u_tab_step_1_REG.ustep_m2 =	 ptr->UV_Offset.Ustep[2];
		yuv2rgb_d_uvoffsetbyy_u_tab_step_1_REG.ustep_m3 =	 ptr->UV_Offset.Ustep[3];
		yuv2rgb_d_uvoffsetbyy_u_tab_step_2_REG.ustep_m4 =	 ptr->UV_Offset.Ustep[4];
		yuv2rgb_d_uvoffsetbyy_u_tab_step_2_REG.ustep_m5 =	 ptr->UV_Offset.Ustep[5];
		yuv2rgb_d_uvoffsetbyy_u_tab_step_2_REG.ustep_m6 =	 ptr->UV_Offset.Ustep[6];
		yuv2rgb_d_uvoffsetbyy_u_tab_step_2_REG.ustep_m7 =	 ptr->UV_Offset.Ustep[7];
		yuv2rgb_d_uvoffsetbyy_u_tab_step_3_REG.ustep_m8 =	 ptr->UV_Offset.Ustep[8];
		yuv2rgb_d_uvoffsetbyy_u_tab_step_3_REG.ustep_m9 =	 ptr->UV_Offset.Ustep[9];
		yuv2rgb_d_uvoffsetbyy_u_tab_step_3_REG.ustep_m10 =	 ptr->UV_Offset.Ustep[10];
		yuv2rgb_d_uvoffsetbyy_u_tab_step_3_REG.ustep_m11 =	 ptr->UV_Offset.Ustep[11];
		yuv2rgb_d_uvoffsetbyy_u_tab_step_4_REG.ustep_m12 =	 ptr->UV_Offset.Ustep[12];
		yuv2rgb_d_uvoffsetbyy_u_tab_step_4_REG.ustep_m13 =	 ptr->UV_Offset.Ustep[13];
		yuv2rgb_d_uvoffsetbyy_u_tab_step_4_REG.ustep_m14 =	 ptr->UV_Offset.Ustep[14];
		yuv2rgb_d_uvoffsetbyy_u_tab_step_4_REG.ustep_m15 =	 ptr->UV_Offset.Ustep[15];
		yuv2rgb_d_uvoffsetbyy_u_tab_step_5_REG.ustep_m16 =	 ptr->UV_Offset.Ustep[16];
		yuv2rgb_d_uvoffsetbyy_v_tab_step_1_REG.vstep_m0 =	 ptr->UV_Offset.Vstep[0];
		yuv2rgb_d_uvoffsetbyy_v_tab_step_1_REG.vstep_m1 =	 ptr->UV_Offset.Vstep[1];
		yuv2rgb_d_uvoffsetbyy_v_tab_step_1_REG.vstep_m2 =	 ptr->UV_Offset.Vstep[2];
		yuv2rgb_d_uvoffsetbyy_v_tab_step_1_REG.vstep_m3 =	 ptr->UV_Offset.Vstep[3];
		yuv2rgb_d_uvoffsetbyy_v_tab_step_2_REG.vstep_m4 =	 ptr->UV_Offset.Vstep[4];
		yuv2rgb_d_uvoffsetbyy_v_tab_step_2_REG.vstep_m5 =	 ptr->UV_Offset.Vstep[5];
		yuv2rgb_d_uvoffsetbyy_v_tab_step_2_REG.vstep_m6 =	 ptr->UV_Offset.Vstep[6];
		yuv2rgb_d_uvoffsetbyy_v_tab_step_2_REG.vstep_m7 =	 ptr->UV_Offset.Vstep[7];
		yuv2rgb_d_uvoffsetbyy_v_tab_step_3_REG.vstep_m8 =	 ptr->UV_Offset.Vstep[8];
		yuv2rgb_d_uvoffsetbyy_v_tab_step_3_REG.vstep_m9 =	 ptr->UV_Offset.Vstep[9];
		yuv2rgb_d_uvoffsetbyy_v_tab_step_3_REG.vstep_m10 =	 ptr->UV_Offset.Vstep[10];
		yuv2rgb_d_uvoffsetbyy_v_tab_step_3_REG.vstep_m11 =	 ptr->UV_Offset.Vstep[11];
		yuv2rgb_d_uvoffsetbyy_v_tab_step_4_REG.vstep_m12 =	 ptr->UV_Offset.Vstep[12];
		yuv2rgb_d_uvoffsetbyy_v_tab_step_4_REG.vstep_m13 =	 ptr->UV_Offset.Vstep[13];
		yuv2rgb_d_uvoffsetbyy_v_tab_step_4_REG.vstep_m14 =	 ptr->UV_Offset.Vstep[14];
		yuv2rgb_d_uvoffsetbyy_v_tab_step_4_REG.vstep_m15 =	 ptr->UV_Offset.Vstep[15];
		yuv2rgb_d_uvoffsetbyy_v_tab_step_5_REG.vstep_m16 =	 ptr->UV_Offset.Vstep[16];

		IoReg_Write32(YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_1_reg, yuv2rgb_d_uvoffsetbyy_u_tab_data_1_REG.regValue);
		IoReg_Write32(YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_2_reg, yuv2rgb_d_uvoffsetbyy_u_tab_data_2_REG.regValue);
		IoReg_Write32(YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_3_reg, yuv2rgb_d_uvoffsetbyy_u_tab_data_3_REG.regValue);
		IoReg_Write32(YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_4_reg, yuv2rgb_d_uvoffsetbyy_u_tab_data_4_REG.regValue);
		IoReg_Write32(YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_5_reg, yuv2rgb_d_uvoffsetbyy_u_tab_data_5_REG.regValue);
		IoReg_Write32(YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_1_reg, yuv2rgb_d_uvoffsetbyy_v_tab_data_1_REG.regValue);
		IoReg_Write32(YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_2_reg, yuv2rgb_d_uvoffsetbyy_v_tab_data_2_REG.regValue);
		IoReg_Write32(YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_3_reg, yuv2rgb_d_uvoffsetbyy_v_tab_data_3_REG.regValue);
		IoReg_Write32(YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_4_reg, yuv2rgb_d_uvoffsetbyy_v_tab_data_4_REG.regValue);
		IoReg_Write32(YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_5_reg, yuv2rgb_d_uvoffsetbyy_v_tab_data_5_REG.regValue);
		IoReg_Write32(YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_1_reg, yuv2rgb_d_uvoffsetbyy_u_tab_step_1_REG.regValue);
		IoReg_Write32(YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_2_reg, yuv2rgb_d_uvoffsetbyy_u_tab_step_2_REG.regValue);
		IoReg_Write32(YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_3_reg, yuv2rgb_d_uvoffsetbyy_u_tab_step_3_REG.regValue);
		IoReg_Write32(YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_4_reg, yuv2rgb_d_uvoffsetbyy_u_tab_step_4_REG.regValue);
		IoReg_Write32(YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_5_reg, yuv2rgb_d_uvoffsetbyy_u_tab_step_5_REG.regValue);
		IoReg_Write32(YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_1_reg, yuv2rgb_d_uvoffsetbyy_v_tab_step_1_REG.regValue);
		IoReg_Write32(YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_2_reg, yuv2rgb_d_uvoffsetbyy_v_tab_step_2_REG.regValue);
		IoReg_Write32(YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_3_reg, yuv2rgb_d_uvoffsetbyy_v_tab_step_3_REG.regValue);
		IoReg_Write32(YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_4_reg, yuv2rgb_d_uvoffsetbyy_v_tab_step_4_REG.regValue);
		IoReg_Write32(YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_5_reg, yuv2rgb_d_uvoffsetbyy_v_tab_step_5_REG.regValue);
		buffer_status_count = 0;
		break;
	case VIP_CSMatrix_CoefByY_Index:		/* Mac3 add by chris @20140721*/
		if (tbl != VIP_Table_Select_1) {
			VIPprintf("~~drvif_color_setYUV2RGB_CSMatrix Error, Table2 can't set matrix by Y~~\n ");
			return;
		}
		for (i = 0; i < VIP_YUV2RGB_Y_Seg_Max-1; i += 4) {
			yuv2rgb_d_coefbyy_nonlinear_0_REG.index_1 = ptr->COEF_By_Y.Y_index[i];
			yuv2rgb_d_coefbyy_nonlinear_0_REG.index_2 = ptr->COEF_By_Y.Y_index[i+1];
			yuv2rgb_d_coefbyy_nonlinear_0_REG.index_3 = ptr->COEF_By_Y.Y_index[i+2];
			yuv2rgb_d_coefbyy_nonlinear_0_REG.index_4 = ptr->COEF_By_Y.Y_index[i+3];
			IoReg_Write32(YUV2RGB_D_COEFBYY_NONLINEAR_0_reg+i, yuv2rgb_d_coefbyy_nonlinear_0_REG.regValue);
		}
		buffer_status_count = 0;
		break;

	case VIP_CSMatrix_UVOffset_Index:		/* Mac3 add by chris @20140721*/
		if (tbl != VIP_Table_Select_1) {
			VIPprintf("~~drvif_color_setYUV2RGB_CSMatrix Error, Table2 can't set matrix by Y~~\n ");
			return;
		}
		for (i = 0; i < VIP_YUV2RGB_Y_Seg_Max-1; i += 4) {
			yuv2rgb_d_offsetbyy_nonlinear_0_REG.index_1 = ptr->UV_Offset.UV_index[i];
			yuv2rgb_d_offsetbyy_nonlinear_0_REG.index_2 = ptr->UV_Offset.UV_index[i+1];
			yuv2rgb_d_offsetbyy_nonlinear_0_REG.index_3 = ptr->UV_Offset.UV_index[i+2];
			yuv2rgb_d_offsetbyy_nonlinear_0_REG.index_4 = ptr->UV_Offset.UV_index[i+3];
			IoReg_Write32(YUV2RGB_D_OFFSETBYY_NONLINEAR_0_reg+i, yuv2rgb_d_offsetbyy_nonlinear_0_REG.regValue);
		}
		buffer_status_count = 0;
		break;

	case VIP_CSMatrix_Coef_BT2020_Only:
		if (tbl == VIP_Table_Select_1) {
#if 0 // juwen, remove
			yuv2rgb_d_yuv2rgb_tab1_data_7_REG.regValue = IoReg_Read32(YUV2RGB_D_YUV2RGB_Tab1_Data_7_reg);
			yuv2rgb_d_yuv2rgb_tab1_data_7_REG.k132 = ptr->COEF_By_Y.bt2020_K13;
			yuv2rgb_d_yuv2rgb_tab1_data_7_REG.k322 = ptr->COEF_By_Y.bt2020_K32;
			IoReg_Write32(YUV2RGB_D_YUV2RGB_Tab1_Data_7_reg, yuv2rgb_d_yuv2rgb_tab1_data_7_REG.regValue);
#endif
		} else if (tbl == VIP_Table_Select_2) {
#if 0 // juwen, remove
			yuv2rgb_d_yuv2rgb_tab2_data_7_REG.regValue = IoReg_Read32(YUV2RGB_D_YUV2RGB_Tab2_Data_7_reg);
			yuv2rgb_d_yuv2rgb_tab2_data_7_REG.k132 = ptr->COEF_By_Y.bt2020_K13;
			yuv2rgb_d_yuv2rgb_tab2_data_7_REG.k322 = ptr->COEF_By_Y.bt2020_K32;
			IoReg_Write32(YUV2RGB_D_YUV2RGB_Tab2_Data_7_reg, yuv2rgb_d_yuv2rgb_tab1_data_7_REG.regValue);
#endif
		} else {
			VIPprintf("~~drvif_color_setYUV2RGB_CSMatrix Error, Table select Error~~\n ");
		}
		buffer_status_count = 0;
		break;

	default:
		VIPprintf("~~drvif_color_setYUV2RGB_CSMatrix, WriteMode Error, WriteMode =%d~~\n ", WriteMode);
		return;
	}

	/* double buffer check,*/
	if (buffer_status_count == 0) {
		d_yuv2rgb_control_1_reg.yuv2rgb_db_apply = 1;  /* 20100811, double buffer en , csfanchiang*/
		IoReg_Write32(YUV2RGB_D_YUV2RGB_Control_1_reg, d_yuv2rgb_control_1_reg.regValue);
		#if 0
		do {/* check double buffer status complete*/
			d_yuv2rgb_control_1_reg.regValue	 = IoReg_Read32(YUV2RGB_D_YUV2RGB_Control_1_reg);
			buffer_status_count++;
		} while (d_yuv2rgb_control_1_reg.yuv2rgb_db_apply != 0 && buffer_status_count < buffer_status_count_th);
		#endif
	}
}


/*============================================================================*/
/**
 * Color_GetYContrast
 * Get contrast & brightness of Y path
 *
 * @param
 * @param
 * @return 			{ contrast value }
 *
 */
 unsigned char drvif_color_getycontrast(unsigned char display)
{
/*	unsigned short K11;*/
	unsigned short new_K11 = 0;
	/*unsigned char ii;*/
	/*short new_RGB_offset;*/
/* 1. access tab-1 & 2*/
/* 2. use both tab-1 & 2's k11 for Y contrast*/
/* 3. use both tab-1 & 2's RGB contrast as Y Brightness.*/
	/*RTD_Log(LOGGER_INFO,"Color_SetYContrastBrightness:%d %d\n", Contrast, Brightness);*/

	yuv2rgb_d_yuv2rgb_tab1_data_0_RBUS yuv2rgb_d_yuv2rgb_tab1_data_0_REG;
	#ifdef CONFIG_DUAL_CHANNEL
	#ifdef VIP_CONFIG_DUAL_CHANNEL // henry 161214
	yuv2rgb_d_yuv2rgb_tab2_data_0_RBUS d_yuv2rgb_tab2_data_0_REG;
	#endif
	#endif



	if (display  == SLR_MAIN_DISPLAY) {
		yuv2rgb_d_yuv2rgb_tab1_data_0_REG.regValue = IoReg_Read32(YUV2RGB_D_YUV2RGB_Tab1_Data_0_reg);
		new_K11 = (yuv2rgb_d_yuv2rgb_tab1_data_0_REG.k11 >> 1) & 0x1ff;


	}
#ifdef CONFIG_DUAL_CHANNEL
#ifdef VIP_CONFIG_DUAL_CHANNEL // henry 161214

	else {
		d_yuv2rgb_tab2_data_0_REG.regValue = IoReg_Read32(YUV2RGB_D_YUV2RGB_Tab2_Data_0_reg);
		new_K11 = (d_yuv2rgb_tab2_data_0_REG.k11 >> 1) & 0x1ff;

	}
#endif
#endif


return new_K11;

}


/*============================================================================*/
/**
 * Color_GetYBrightness
 * Get contrast & brightness of Y path
 *
 * @param
 * @param
 * @return 			{ brightness }
 *
 */
unsigned char drvif_color_getybrightness(unsigned char display)
{
	signed short new_RGB_offset = 0;
	unsigned int temp_value = 0;
	/* 1. access tab-1 & 2*/
	/* 2. use both tab-1 & 2's k11 for Y contrast*/
	/* 3. use both tab-1 & 2's RGB contrast as Y Brightness.*/
	/*RTD_Log(LOGGER_INFO,"Color_SetYContrastBrightness:%d %d\n", Contrast, Brightness);*/


	yuv2rgb_d_yuv2rgb_tab1_data_6_RBUS yuv2rgb_d_yuv2rgb_tab1_data_6_REG;
#if 0/*#ifdef CONFIG_DUAL_CHANNEL*/
	d_yuv2rgb_tab2_data_6_RBUS d_yuv2rgb_tab2_data_6_REG;
#endif


	if (display  == SLR_MAIN_DISPLAY) {

		yuv2rgb_d_yuv2rgb_tab1_data_6_REG.regValue = IoReg_Read32(YUV2RGB_D_YUV2RGB_Tab1_Data_3_reg);
		temp_value = yuv2rgb_d_yuv2rgb_tab1_data_6_REG.boffset ;
		if (((temp_value >> 12) & 0x01) == 0x01)
			new_RGB_offset = 128 + (signed int)((temp_value >> 5) - 256);
		else
			new_RGB_offset = 128 + (temp_value >> 5);




	}
#if 0/*#ifdef CONFIG_DUAL_CHANNEL*/
	else {
		d_yuv2rgb_tab2_data_6_REG.regValue = IoReg_Read32(YUV2RGB_D_YUV2RGB_Tab2_Data_6_reg);

		temp_value = d_yuv2rgb_tab2_data_6_REG.boffset ;
		if (((temp_value >> 12) & 0x01) == 0x01)
			new_RGB_offset = 128 +  (signed int)((temp_value >> 5) - 256);
		else
			new_RGB_offset = 128 +  (temp_value >> 5);
	}
#endif


return new_RGB_offset;

}

/*============================================================================*/
/**
 * Color_SetYContrastBrightness
 * Set contrast & brightness of Y path
 *
 * @param <Contrast> 	{ Y Contrast}
 * @param <Brightness> 	{ Y brightness}
 * @return 			{ void }
 *
 */

unsigned int drvif_color_coef_sat(unsigned short coef, unsigned char Sat)/*for Sirius, negative coef*/
{
	 bool neg = 0;
	 unsigned int new_coeffs;

	 if (coef > 0x3ff) {/*negative value*/
		 coef = 0x800 - coef;
		 neg = 1;
	 }

	 new_coeffs = (coef * Sat) >> 7;
	 if (new_coeffs > 0x3ff)
		 new_coeffs = 0x3ff;

	 if (neg)
		 new_coeffs = 0x800 - new_coeffs;

	 if (new_coeffs > 0x7ff)
		 new_coeffs = 0x7ff;

	 return new_coeffs;
}

void drvif_color_setuv_sat(unsigned char display, unsigned char Sat)
{
	/*unsigned int new_coeffs;*/
	unsigned short *table_index = 0;
	unsigned short buffer_status_count = 0;
	/* 1. access tab-1 & 2*/

	yuv2rgb_d_yuv2rgb_tab1_data_0_RBUS yuv2rgb_d_yuv2rgb_tab1_data_0_REG;
	yuv2rgb_d_yuv2rgb_tab1_data_1_RBUS yuv2rgb_d_yuv2rgb_tab1_data_1_REG;
	yuv2rgb_d_yuv2rgb_tab1_data_2_RBUS yuv2rgb_d_yuv2rgb_tab1_data_2_REG;
	yuv2rgb_d_yuv2rgb_tab1_data_3_RBUS yuv2rgb_d_yuv2rgb_tab1_data_3_REG;

#if 0 /*#ifdef CONFIG_DUAL_CHANNEL*/
	yuv2rgb_d_yuv2rgb_tab2_data_0_RBUS d_yuv2rgb_tab2_data_0_REG;
	d_yuv2rgb_tab2_data_1_RBUS d_yuv2rgb_tab2_data_1_REG;
	d_yuv2rgb_tab2_data_2_RBUS d_yuv2rgb_tab2_data_2_REG;
	d_yuv2rgb_tab2_data_3_RBUS d_yuv2rgb_tab2_data_3_REG;
#endif

	/*yuv2rgb_d_yuv2rgb_tab2_data_0_RBUS d_yuv2rgb_tab2_data_0_REG;*/
	/*d_yuv2rgb_tab2_data_1_RBUS d_yuv2rgb_tab2_data_1_REG;*/
	/*yuv2rgb_d_yuv2rgb_control_RBUS	    d_yuv2rgb_control_REG;*/
	yuv2rgb_d_yuv2rgb_control_1_RBUS		d_yuv2rgb_control_1_reg;

	VIPprintf("Color_SetUV_Sat =%d\n", Sat);
	table_index = tYUV2RGB_COEF_601_YCbCr;

	/*d_yuv2rgb_control_REG.regValue 	 = IoReg_Read32(YUV2RGB_D_YUV2RGB_Control_reg);*/
	d_yuv2rgb_control_1_reg.regValue 	 = IoReg_Read32(YUV2RGB_D_YUV2RGB_Control_1_reg);

	yuv2rgb_d_yuv2rgb_tab1_data_0_REG.regValue = IoReg_Read32(YUV2RGB_D_YUV2RGB_Tab1_Data_0_reg);
	yuv2rgb_d_yuv2rgb_tab1_data_1_REG.regValue = IoReg_Read32(YUV2RGB_D_YUV2RGB_Tab1_Data_1_reg);
	/*yuv2rgb_d_yuv2rgb_tab1_data_0_REG.k13 =(IoReg_Read32(YUV2RGB_D_YUV2RGB_Tab1_Data_0_reg)&0x1ff);*/
	yuv2rgb_d_yuv2rgb_tab1_data_2_REG.regValue = IoReg_Read32(YUV2RGB_D_YUV2RGB_Tab1_Data_2_reg);
	yuv2rgb_d_yuv2rgb_tab1_data_3_REG.regValue = IoReg_Read32(YUV2RGB_D_YUV2RGB_Tab1_Data_3_reg);
	/*d_yuv2rgb_tab2_data_0_REG.regValue = IoReg_Read32(YUV2RGB_D_YUV2RGB_Tab2_Data_0_reg);*/
	/*d_yuv2rgb_tab2_data_1_REG.regValue = IoReg_Read32(YUV2RGB_D_YUV2RGB_Tab2_Data_1_reg);*/

	VIPprintf("=== UV test reg. K13 =%x ===\n ", IoReg_Read32(YUV2RGB_D_YUV2RGB_Tab1_Data_0_reg)&0x1ff);
	VIPprintf("=== UV test reg. K11 =%x ===\n ", (IoReg_Read32(YUV2RGB_D_YUV2RGB_Tab1_Data_0_reg)&0x7fe00)>>8);


	/*Sat = (Sat > 128)  ? 128+ ((53)  * (Sat -128) /128) : Sat;*/
	Sat = (Sat > 128) ?  75+(Sat*53/128) : Sat;

	/*WaitFor_DEN_STOP();*/ /* 20100730, csfanchiang set sat uv flash*/
	/*d_yuv2rgb_control_REG.yuv2rgb_db_en = 1; */ /* 20100811, double buffer en , csfanchiang*/
	/*IoReg_Write32(YUV2RGB_D_YUV2RGB_Control_reg, d_yuv2rgb_control_REG.regValue);*/

	if (display  == SLR_MAIN_DISPLAY) {
		yuv2rgb_d_yuv2rgb_tab1_data_0_REG.k12 = drvif_color_coef_sat(table_index[_YUV2RGB_k12], Sat);
		IoReg_Write32(YUV2RGB_D_YUV2RGB_Tab1_Data_0_reg, yuv2rgb_d_yuv2rgb_tab1_data_0_REG.regValue);

		/*new_coeffs = (unsigned int)((double) table_index[_YUV2RGB_k13] * Sat);*/
		/*new_coeffs = (new_coeffs >> 7);*/
		/*yuv2rgb_d_yuv2rgb_tab1_data_1_REG.k13 = (new_coeffs > 0x1ff) ? 0x1ff: new_coeffs;*/
		yuv2rgb_d_yuv2rgb_tab1_data_1_REG.k13 = drvif_color_coef_sat(table_index[_YUV2RGB_k13], Sat);
		IoReg_Write32(YUV2RGB_D_YUV2RGB_Tab1_Data_1_reg, yuv2rgb_d_yuv2rgb_tab1_data_1_REG.regValue);

		yuv2rgb_d_yuv2rgb_tab1_data_2_REG.k22 = drvif_color_coef_sat(table_index[_YUV2RGB_k22], Sat);
		yuv2rgb_d_yuv2rgb_tab1_data_2_REG.k23 = drvif_color_coef_sat(table_index[_YUV2RGB_k23], Sat);
		IoReg_Write32(YUV2RGB_D_YUV2RGB_Tab1_Data_2_reg, yuv2rgb_d_yuv2rgb_tab1_data_2_REG.regValue);

		yuv2rgb_d_yuv2rgb_tab1_data_3_REG.k32 = drvif_color_coef_sat(table_index[_YUV2RGB_k32], Sat);
		yuv2rgb_d_yuv2rgb_tab1_data_3_REG.k33 = drvif_color_coef_sat(table_index[_YUV2RGB_k33], Sat);
		IoReg_Write32(YUV2RGB_D_YUV2RGB_Tab1_Data_3_reg, yuv2rgb_d_yuv2rgb_tab1_data_3_REG.regValue);

	}
#if 0 /*#ifdef CONFIG_DUAL_CHANNEL*/
	else {
		d_yuv2rgb_tab2_data_0_REG.k12 = drvif_color_coef_sat(table_index[_YUV2RGB_k12], Sat);
		IoReg_Write32(YUV2RGB_D_YUV2RGB_Tab2_Data_0_reg, d_yuv2rgb_tab2_data_0_REG.regValue);

		d_yuv2rgb_tab2_data_1_REG.k13 = drvif_color_coef_sat(table_index[_YUV2RGB_k13], Sat);
		IoReg_Write32(YUV2RGB_D_YUV2RGB_Tab2_Data_1_reg, d_yuv2rgb_tab2_data_1_REG.regValue);

		d_yuv2rgb_tab2_data_2_REG.k22 = drvif_color_coef_sat(table_index[_YUV2RGB_k22], Sat);
		d_yuv2rgb_tab2_data_2_REG.k23 = drvif_color_coef_sat(table_index[_YUV2RGB_k23], Sat);
		IoReg_Write32(YUV2RGB_D_YUV2RGB_Tab2_Data_2_reg, d_yuv2rgb_tab2_data_2_REG.regValue);

		d_yuv2rgb_tab2_data_3_REG.k32 = drvif_color_coef_sat(table_index[_YUV2RGB_k32], Sat);
		d_yuv2rgb_tab2_data_3_REG.k33 = drvif_color_coef_sat(table_index[_YUV2RGB_k33], Sat);
		IoReg_Write32(YUV2RGB_D_YUV2RGB_Tab2_Data_3_reg, d_yuv2rgb_tab2_data_3_REG.regValue);
	}
#endif

	d_yuv2rgb_control_1_reg.yuv2rgb_db_apply = 1;  /* 20100811, double buffer en , csfanchiang*/
	IoReg_Write32(YUV2RGB_D_YUV2RGB_Control_1_reg, d_yuv2rgb_control_1_reg.regValue);
	VIPprintf("$$$check YUV2RGB double buffer buffer_status =%d!!", d_yuv2rgb_control_1_reg.yuv2rgb_db_apply);
	/*WaitFor_DEN_STOP();*/
	do {/* check double buffer status complete*/
		d_yuv2rgb_control_1_reg.regValue 	 = IoReg_Read32(YUV2RGB_D_YUV2RGB_Control_1_reg);
		/*VIPprintf("@@@@buffer_status_count =%d, double_buffer_reg =%d\n", buffer_status_count, d_yuv2rgb_control_REG.yuv2rgb_db_apply);*/
		buffer_status_count++;
	} while (d_yuv2rgb_control_1_reg.yuv2rgb_db_apply != 0 && buffer_status_count < 300);
	VIPprintf("$$$check YUV2RGB double buffer buffer_status =%d!!", d_yuv2rgb_control_1_reg.yuv2rgb_db_apply);


}

/*============================================================================*/
/**
 * Color_SetRgbContrast
 * Set contrast of RGB path
 * @param <display>	{ specify main/sub to set RgbContrastBrightness }
 * @param <Red> 		{ Red Contrast, Range: 0x00(0)~0x80(1)~0xff(2)}
 * @param <Green> 	{ Green Contrast, Range: 0x00(0)~0x80(1)~0xff(2)}
 * @param <Blue> 	{ Blue Contrast, Range: 0x00(0)~0x80(1)~0xff(2)}
 * @return 			{ void }
*/
void drvif_color_setrgbcontrast(unsigned char display, unsigned short Red, unsigned short Green, unsigned short Blue, unsigned char  BlendRatio, unsigned char Overlay)
{
 	//return;
	//mac5 dcc remove, no exist
 	/*
	con_bri_dm_contrast_a2b_RBUS		dm_contrast_a2b_REG;
	con_bri_dm_contrast_b2a_RBUS		dm_contrast_b2a_REG;
	con_bri_dm_contrast_b2b_RBUS		dm_contrast_b2b_REG;
	con_bri_ds_contrast_a2b_RBUS		ds_contrast_a2b_REG;
	con_bri_ds_contrast_b2a_RBUS		ds_contrast_b2a_REG;
	con_bri_ds_contrast_b2b_RBUS		ds_contrast_b2b_REG;
	*/
#ifdef VIP_CONFIG_DUAL_CHANNEL
	con_bri_ds_contrast_a_RBUS		ds_contrast_a_REG; //mac5 dcc no sub
#endif

	/*VIPprintf("drvif_color_setrgbcontrast, display = %d, Red = %d, Green = %d, Blue = %d, BlendRatio = %d, Overlay = %d\n", display, Red, Green, Blue, BlendRatio, Overlay);*/

	if (display == SLR_MAIN_DISPLAY) {
		con_bri_dm_color_rgb_ctrl_RBUS	dm_color_rgb_ctrl_REG;
		con_bri_dm_contrast_a_RBUS		dm_contrast_a_REG;

		dm_color_rgb_ctrl_REG.regValue =  IoReg_Read32(CON_BRI_DM_COLOR_RGB_CTRL_reg);
		dm_contrast_a_REG.regValue	= IoReg_Read32(CON_BRI_DM_CONTRAST_A_reg);
		dm_color_rgb_ctrl_REG.m_con_en = 1;
		dm_contrast_a_REG.m_con_a_r	= Red;
		dm_contrast_a_REG.m_con_a_g	= Green;
		dm_contrast_a_REG.m_con_a_b	= Blue;
		IoReg_Write32(CON_BRI_DM_COLOR_RGB_CTRL_reg, dm_color_rgb_ctrl_REG.regValue);
		IoReg_Write32(CON_BRI_DM_CONTRAST_A_reg, dm_contrast_a_REG.regValue);
	}

#if 1//def CONFIG_DUAL_CHANNEL
#ifdef VIP_CONFIG_DUAL_CHANNEL // henry 161214
	//mac5 dcc remove, no sub
	/*
	else {
		con_bri_ds_color_rgb_ctrl_RBUS			ds_color_rgb_ctrl_REG;
		con_bri_ds_contrast_a_RBUS			ds_contrast_a_REG;
		con_bri_d_overlay_contrast_a2a_RBUS	d_overlay_contrast_a2a_REG;

		ds_color_rgb_ctrl_REG.regValue = IoReg_Read32(CON_BRI_DS_COLOR_RGB_CTRL_reg);
		ds_contrast_a_REG.regValue	= IoReg_Read32(CON_BRI_DS_CONTRAST_A_reg);
		d_overlay_contrast_a2a_REG.regValue = IoReg_Read32(CON_BRI_D_Overlay_CONTRAST_A2A_reg);
		ds_color_rgb_ctrl_REG.s_con_en = 1;
		if (Overlay) {
			ds_contrast_a_REG.s_con_a_r	= Red;
			ds_contrast_a_REG.s_con_a_g	= Green;
			ds_contrast_a_REG.s_con_a_b	= Blue;

			d_overlay_contrast_a2a_REG.v_con_a2a_r = Red;
			d_overlay_contrast_a2a_REG.v_con_a2a_g = Green;
			d_overlay_contrast_a2a_REG.v_con_a2a_b = Blue;
		} else {
			ds_contrast_a_REG.s_con_a_r	= Red;
			ds_contrast_a_REG.s_con_a_g	= Green;
			ds_contrast_a_REG.s_con_a_b	= Blue;
			d_overlay_contrast_a2a_REG.v_con_a2a_r = 128;
			d_overlay_contrast_a2a_REG.v_con_a2a_g = 128;
			d_overlay_contrast_a2a_REG.v_con_a2a_b = 128;
		}
		IoReg_Write32(CON_BRI_DS_COLOR_RGB_CTRL_reg, ds_color_rgb_ctrl_REG.regValue);
		IoReg_Write32(CON_BRI_DS_CONTRAST_A_reg, ds_contrast_a_REG.regValue);
		IoReg_Write32(CON_BRI_D_Overlay_CONTRAST_A2A_reg, d_overlay_contrast_a2a_REG.regValue);
	}

	drvif_color_setpiprgbcontrastbrightness(BlendRatio);
	dm_contrast_a2b_REG.regValue = IoReg_Read32(CON_BRI_DM_CONTRAST_A2B_reg);
	dm_contrast_b2a_REG.regValue = IoReg_Read32(CON_BRI_DM_CONTRAST_B2A_reg);
	dm_contrast_b2b_REG.regValue = IoReg_Read32(CON_BRI_DM_CONTRAST_B2B_reg);
	ds_contrast_a2b_REG.regValue = IoReg_Read32(CON_BRI_DS_CONTRAST_A2B_reg);
	ds_contrast_b2a_REG.regValue = IoReg_Read32(CON_BRI_DS_CONTRAST_B2A_reg);
	ds_contrast_b2b_REG.regValue = IoReg_Read32(CON_BRI_DS_CONTRAST_B2B_reg);

	ds_contrast_a_REG.regValue = IoReg_Read32(CON_BRI_DS_CONTRAST_A_reg);
	dm_contrast_a2b_REG.m_con_a2b_r = 0;
	dm_contrast_a2b_REG.m_con_a2b_g = 0;
	dm_contrast_a2b_REG.m_con_a2b_b = 0;
	dm_contrast_b2a_REG.m_con_b2a_r = 0;
	dm_contrast_b2a_REG.m_con_b2a_g = 0;
	dm_contrast_b2a_REG.m_con_b2a_b = 0;
	dm_contrast_b2b_REG.m_con_b2b_r = 0;
	dm_contrast_b2b_REG.m_con_b2b_g = 0;
	dm_contrast_b2b_REG.m_con_b2b_b = 0;

	ds_contrast_a2b_REG.s_con_a2b_r = ds_contrast_a_REG.s_con_a_r;
	ds_contrast_a2b_REG.s_con_a2b_g = ds_contrast_a_REG.s_con_a_g;
	ds_contrast_a2b_REG.s_con_a2b_b = ds_contrast_a_REG.s_con_a_b;
	ds_contrast_b2a_REG.s_con_b2a_r = 128;
	ds_contrast_b2a_REG.s_con_b2a_g = 128;
	ds_contrast_b2a_REG.s_con_b2a_b = 128;
	ds_contrast_b2b_REG.s_con_b2b_r = 128;
	ds_contrast_b2b_REG.s_con_b2b_g = 128;
	ds_contrast_b2b_REG.s_con_b2b_b = 128;
	IoReg_Write32(CON_BRI_DM_CONTRAST_A2B_reg, dm_contrast_a2b_REG.regValue);
	IoReg_Write32(CON_BRI_DM_CONTRAST_B2A_reg, dm_contrast_b2a_REG.regValue);
	IoReg_Write32(CON_BRI_DM_CONTRAST_B2B_reg, dm_contrast_b2b_REG.regValue);
	IoReg_Write32(CON_BRI_DS_CONTRAST_A2B_reg, ds_contrast_a2b_REG.regValue);
	IoReg_Write32(CON_BRI_DS_CONTRAST_B2A_reg, ds_contrast_b2a_REG.regValue);
	IoReg_Write32(CON_BRI_DS_CONTRAST_B2B_reg, ds_contrast_b2b_REG.regValue);*/
	#endif
	#endif
}

/*============================================================================*/
/**
 * Color_SetRgbBrightness
 * Set brightness of RGB path
 * @param <display>	{ specify main/sub to set RgbContrastBrightness }
 * @param <Red> 		{ Red brightness, Range: 0x000(-512)~0x200(0)~0x3ff(512)}
 * @param <Green> 	{ Green brightness , Range: 0x000(-512)~0x200(0)~0x3ff(512)}
 * @param <Blue> 	{ Blue brightness , Range: 0x000(-512)~0x200(0)~0x3ff(512)}
 * @return 			{ void }
*/

 void drvif_color_setrgbbrightness(unsigned char display, unsigned short Red, unsigned short Green, unsigned short Blue)
 {
 /*VIPprintf("Enter Set drvif_color_setrgbbrightness()\n");*/ /*planck*/

	if (display == SLR_MAIN_DISPLAY) {
		con_bri_dm_color_rgb_ctrl_RBUS	dm_color_rgb_ctrl_REG;
		con_bri_dm_brightness_1_RBUS		dm_brightness_1_REG;

		dm_color_rgb_ctrl_REG.regValue =  IoReg_Read32(CON_BRI_DM_COLOR_RGB_CTRL_reg);
		dm_brightness_1_REG.regValue	= IoReg_Read32(CON_BRI_DM_Brightness_1_reg);

		dm_color_rgb_ctrl_REG.m_bri_en = 1;
		dm_brightness_1_REG.m_bri1_r = Red;/*20080113 Thur modified for compile*/
		dm_brightness_1_REG.m_bri1_g = Green;/*20080113 Thur modified for compile*/
		dm_brightness_1_REG.m_bri1_b = Blue;/*20080113 Thur modified for compile*/
		IoReg_Write32(CON_BRI_DM_COLOR_RGB_CTRL_reg, dm_color_rgb_ctrl_REG.regValue);
		IoReg_Write32(CON_BRI_DM_Brightness_1_reg, dm_brightness_1_REG.regValue);
	}
#ifdef CONFIG_DUAL_CHANNEL
#ifdef VIP_CONFIG_DUAL_CHANNEL // henry 161214
	else {
		con_bri_ds_color_rgb_ctrl_RBUS		ds_color_rgb_ctrl_REG;
		con_bri_ds_brightness_1_RBUS		ds_brightness_1_REG;
		ds_color_rgb_ctrl_REG.regValue =  IoReg_Read32(CON_BRI_DS_COLOR_RGB_CTRL_reg);
		ds_brightness_1_REG.regValue	= IoReg_Read32(CON_BRI_DM_Brightness_1_reg);
		ds_color_rgb_ctrl_REG.s_bri_en = 1;
		ds_brightness_1_REG.s_bri1_r = Red;
		ds_brightness_1_REG.s_bri1_g = Green;
		ds_brightness_1_REG.s_bri1_b = Blue;
		IoReg_Write32(CON_BRI_DS_COLOR_RGB_CTRL_reg, ds_color_rgb_ctrl_REG.regValue);
		IoReg_Write32(CON_BRI_DS_Brightness_1_reg, ds_brightness_1_REG.regValue);
	}
#endif
#endif
 }



/**
 * drvif_color_setpiprgbcontrastbrightness
 * Set blending ratio for PIP
 * @param <BlendRatio>	{ main's blending ratio: 0~16 on viking and pacific. Furthermore, 0 means all sub and max value means all main. }
 * @return 				{ void }
 */
void drvif_color_setpiprgbcontrastbrightness(unsigned char BlendRatio)
 {
	con_bri_dm_color_rgb_ctrl_RBUS dm_color_rgb_ctrl_REG;
	dm_color_rgb_ctrl_REG.regValue =  IoReg_Read32(CON_BRI_DM_COLOR_RGB_CTRL_reg);
	if (BlendRatio > 16) {
/*		RTD_Log(LOGGER_INFO, "out of range blending ratio: %d\n", BlendRatio);*/
		BlendRatio = 16;
	}

	dm_color_rgb_ctrl_REG.m_con_en = 1;
//	dm_color_rgb_ctrl_REG.m_con_toggle = 1;// mac5 dcc remove
//	dm_color_rgb_ctrl_REG.m_blending_factor = BlendRatio;// mac5 dcc remove
	IoReg_Write32(CON_BRI_DM_COLOR_RGB_CTRL_reg, dm_color_rgb_ctrl_REG.regValue);
}

/*
*name:drvif_color_setBrightnessDualplayOverlay
*param:BlendValue ,display
*function: set blending factor for main and sub in overlay area;
*/
void drvif_color_setBrightnessDualplayOverlay(unsigned int BlendValue,unsigned char display)
{
	con_bri_dm_color_rgb_ctrl_RBUS dm_color_rgb_ctrl_REG;
//	con_bri_dm_color_rgb_ctrl1_RBUS dm_color_rgb_ctrl1_REG;// mac5 dcc remove
//	con_bri_dm_double_buffer_ctrl_RBUS dm_double_buffer_ctrl_REG;// mac5 dcc remove

	dm_color_rgb_ctrl_REG.regValue =  IoReg_Read32(CON_BRI_DM_COLOR_RGB_CTRL_reg);
//	dm_color_rgb_ctrl1_REG.regValue = IoReg_Read32(CON_BRI_DM_COLOR_RGB_CTRL1_reg);// mac5 dcc remove
//	dm_double_buffer_ctrl_REG.regValue = IoReg_Read32(CON_BRI_DM_Double_Buffer_CTRL_reg);// mac5 dcc remove

	if(BlendValue > 256)
	    BlendValue %= 256;
#ifndef CONFIG_DUAL_CHANNEL
	display = SLR_MAIN_DISPLAY;
#endif

//	dm_double_buffer_ctrl_REG.conbri_dbuf_en = 1;//double buffer enable// mac5 dcc remove
//	IoReg_Write32(CON_BRI_DM_Double_Buffer_CTRL_reg,dm_double_buffer_ctrl_REG.regValue);// mac5 dcc remove

//	dm_color_rgb_ctrl1_REG.blending_mode_sel = 1;// new mode(two blending factor for main/sub)// mac5 dcc remove
//	if(SLR_MAIN_DISPLAY == display){
//	    dm_color_rgb_ctrl1_REG.new_m_blending_factor = BlendValue;// mac5 dcc remove
//	}
//	else{
//	    dm_color_rgb_ctrl1_REG.new_s_blending_factor = BlendValue;// mac5 dcc remove
//	}
//	IoReg_Write32(CON_BRI_DM_COLOR_RGB_CTRL1_reg,dm_color_rgb_ctrl1_REG.regValue);// mac5 dcc remove

	dm_color_rgb_ctrl_REG.m_con_en = 1;
//	dm_color_rgb_ctrl_REG.m_con_toggle = 1;// mac5 dcc remove
//	dm_color_rgb_ctrl_REG.m_blending_factor = 0;// mac5 dcc remove
	IoReg_Write32(CON_BRI_DM_COLOR_RGB_CTRL_reg, dm_color_rgb_ctrl_REG.regValue);

//	dm_double_buffer_ctrl_REG.conbri_dbuf_set = 1;//apply doubler buffer// mac5 dcc remove
//	IoReg_Write32(CON_BRI_DM_Double_Buffer_CTRL_reg,dm_double_buffer_ctrl_REG.regValue);// mac5 dcc remove
}

void drvif_color_gamma_control_front(unsigned char display)
{
	gamma_gamma_ctrl_1_RBUS gamma_ctrl_1_REG;
	gamma_gamma_ctrl_2_RBUS gamma_ctrl_2_REG;

	gamma_ctrl_1_REG.regValue = IoReg_Read32(GAMMA_GAMMA_CTRL_1_reg);
	gamma_ctrl_2_REG.regValue = IoReg_Read32(GAMMA_GAMMA_CTRL_2_reg);

	if (display	== SLR_MAIN_DISPLAY) {
		/*gamma_ctrl_2_REG.gamma_m_tab_sel = 0; */ /* disable main gamma*/
		/* remove "disable gamma" for PIP sub flash when TV scan channel start & end , 20071228 Jerry Wu*/
		/* gamma_ctrl_1_REG.gamma_ax_type_sel = _Gamma_Full;*/
		gamma_ctrl_1_REG.res1 = 0; /* reserved*/
		gamma_ctrl_1_REG.gamma_ax_rw_sel = 1; /* writing table*/
		/*gamma_ctrl_2_REG.gamma_m_tab_sel = 0; */ /* don't mark this line, because it cause screen flash problem, Jerry Wu 20101118*/
		/*gamma_ctrl_2_REG.gamma_tab_size_sel = 0;  */ /*[jyyang@ Mac3] only main channel and one 512 table*/

	}
	#if 0 /* #ifdef CONFIG_DUAL_CHANNEL*/
	else {
		/*gamma_ctrl_2_REG.sub_tab_sel = 0; */ /* disable sub gamma*/
		/* remove "disable gamma" for PIP sub flash when TV scan channel start & end , 20071228 Jerry Wu*/
		gamma_ctrl_1_REG.gamma_ax_type_sel = _Gamma_Full;
		gamma_ctrl_1_REG.res1 = 1; /*  reserved*/
		gamma_ctrl_1_REG.gamma_ax_rw_sel = 1; /* writing table*/
		/*gamma_ctrl_2_REG.gamma_s_tab_sel = 0;*/ /* don't mark this line, because it cause screen flash problem, Jerry Wu 20101118*/

	}
	#endif

	IoReg_Write32(GAMMA_GAMMA_CTRL_1_reg, gamma_ctrl_1_REG.regValue);
	IoReg_Write32(GAMMA_GAMMA_CTRL_2_reg, gamma_ctrl_2_REG.regValue);

}

void drvif_color_gamma_control_back(unsigned char display, unsigned char ucWriteEnable)
{
  	//_system_setting_info *VIP_system_info_structure_table = (_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_system_info_structure);
  	_RPC_system_setting_info *VIP_RPC_system_info_structure_table = NULL;
  	VIP_RPC_system_info_structure_table = (_RPC_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_RPC_system_info_structure);
	gamma_gamma_ctrl_1_RBUS gamma_ctrl_1_REG;
	gamma_gamma_ctrl_2_RBUS gamma_ctrl_2_REG;

	if(VIP_RPC_system_info_structure_table == NULL){
		VIPprintf("[%s:%d] Warning here!! RPC_system_info=NULL! \n",__FILE__, __LINE__);
		return;
	}

	if (VIP_RPC_system_info_structure_table->HDR_info.Ctrl_Item[TV006_HDR_DEMO_EN] == 1)
		return;

	gamma_ctrl_1_REG.regValue = IoReg_Read32(GAMMA_GAMMA_CTRL_1_reg);
	gamma_ctrl_2_REG.regValue = IoReg_Read32(GAMMA_GAMMA_CTRL_2_reg);

	if (display == SLR_MAIN_DISPLAY) {

		gamma_ctrl_1_REG.gamma_ax_rw_sel = 0; /* writing table*/
		gamma_ctrl_2_REG.gamma_m_tab_sel = 1; /* use tab-1*/
		#if 0  /* There are two channels*/
		gamma_ctrl_2_REG.gamma_overlap = 0; /* use main as overlay*/
		#endif
	}
#ifdef CONFIG_DUAL_CHANNEL
#ifdef VIP_CONFIG_DUAL_CHANNEL // henry 161214
	else {
		gamma_ctrl_1_REG.gamma_ax_rw_sel = 0; /* disable writing table*/
		/*gamma_ctrl_2_REG.gamma_overlap = 1;*/ /* use sub as overlay*/
		// gamma_ctrl_2_REG.gamma_s_tab_sel = 1; /* sub gamma use tab-1 same to m_tab	rock_rau 2015/09/17 [WOSQRTK-1187]*/ //jyyang20161215
	}
#endif
#endif

	IoReg_Write32(GAMMA_GAMMA_CTRL_1_reg, gamma_ctrl_1_REG.regValue);
	if (ucWriteEnable)
		IoReg_Write32(GAMMA_GAMMA_CTRL_2_reg, gamma_ctrl_2_REG.regValue);


}


/*============================================================================*/
/**
 * Color_SetDithering
 * This function is used to insert dither tables, including SEQ table & dither table
 *
 * @param <void>		{ void }
 * @return 			{ void }
 *
 */
void drvif_color_setdithering(void)
{

	dither_dithering_ctrl_RBUS	dithering_ctrl_reg;

/*	dithering_SEQUENCE_TABLE_Red_00_07_RBUS	dithering_SEQUENCE_TABLE_Red_00_07_reg;*/
/*	dithering_SEQUENCE_TABLE_Red_08_15_RBUS	dithering_SEQUENCE_TABLE_Red_08_15_reg;*/
/*	dithering_SEQUENCE_TABLE_Red_16_23_RBUS	dithering_SEQUENCE_TABLE_Red_16_23_reg;*/
/*	dithering_SEQUENCE_TABLE_Red_24_31_RBUS	dithering_SEQUENCE_TABLE_Red_24_31_reg;*/
/**/
/*	dithering_SEQUENCE_TABLE_Green_00_07_RBUS	dithering_SEQUENCE_TABLE_Green_00_07_reg;*/
/*	dithering_SEQUENCE_TABLE_Green_08_15_RBUS	dithering_SEQUENCE_TABLE_Green_08_15_reg;*/
/*	dithering_SEQUENCE_TABLE_Green_16_23_RBUS	dithering_SEQUENCE_TABLE_Green_16_23_reg;*/
/*	dithering_SEQUENCE_TABLE_Green_24_31_RBUS	dithering_SEQUENCE_TABLE_Green_24_31_reg;*/
/**/
/*	dithering_SEQUENCE_TABLE_Blue_00_07_RBUS	dithering_SEQUENCE_TABLE_Blue_00_07_reg;*/
/*	dithering_SEQUENCE_TABLE_Blue_08_15_RBUS	dithering_SEQUENCE_TABLE_Blue_08_15_reg;*/
/*	dithering_SEQUENCE_TABLE_Blue_16_23_RBUS	dithering_SEQUENCE_TABLE_Blue_16_23_reg;*/
/*	dithering_SEQUENCE_TABLE_Blue_24_31_RBUS	dithering_SEQUENCE_TABLE_Blue_24_31_reg;*/

	dither_temporal_offset_RBUS	temporal_offset_reg;


	unsigned int dither_32BIT_DATA = 0;
	unsigned short ii, jj, kk, data_shift = 0;

	/*VIPprintf("Panel_Dither_bit = %d\n\n\n\n\n\n\n\n\n\n", Panel_Bit);*/

	if ((Panel_Bit == 3)||(Get_DISPLAY_PANEL_TYPE() == P_VBY1_TO_LVDS_2K)) {/*panel 12bit*/
		dithering_ctrl_reg.function_enable = 0;
		IoReg_Write32(DITHER_DITHERING_CTRL_reg, dithering_ctrl_reg.regValue);
		return;
	}


	for (ii = 0; ii < 3; ii++) {/* rgb order*/

		for (jj = 0; jj < 16; jj++) {
			if ((jj == 0) || (jj == 4) || (jj == 8) || (jj == 12)) {
				dither_32BIT_DATA = 0;
				data_shift = 0;
			}

			/* KWarning: checked ok by allen_zhang*/
			dither_32BIT_DATA += tDITHER_SEQUENCE[ii][jj] << data_shift ;
			data_shift += 8;

			if (jj == 3) {
				switch (ii) {
				case 0:/* red*/
						IoReg_Write32(DITHER_DITHERING_SEQUENCE_TABLE_Red_00_07_reg, dither_32BIT_DATA);
						break;
				case 1:/* green*/
						IoReg_Write32(DITHER_DITHERING_SEQUENCE_TABLE_Green_00_07_reg, dither_32BIT_DATA);
						break;
				case 2:/* blue*/
						IoReg_Write32(DITHER_DITHERING_SEQUENCE_TABLE_Blue_00_07_reg, dither_32BIT_DATA);
						break;
				}

			}

			if (jj == 7) {
				switch (ii) {
				case 0:/* red*/
						IoReg_Write32(DITHER_DITHERING_SEQUENCE_TABLE_Red_08_15_reg, dither_32BIT_DATA);
						break;
				case 1:/* green*/
						IoReg_Write32(DITHER_DITHERING_SEQUENCE_TABLE_Green_08_15_reg, dither_32BIT_DATA);
						break;
				case 2:/* blue*/
						IoReg_Write32(DITHER_DITHERING_SEQUENCE_TABLE_Blue_08_15_reg, dither_32BIT_DATA);
						break;
				}

			}
			if (jj == 11) {
				switch (ii) {
				case 0:/* red*/
						IoReg_Write32(DITHER_DITHERING_SEQUENCE_TABLE_Red_16_23_reg, dither_32BIT_DATA);
						break;
				case 1:/* green*/
						IoReg_Write32(DITHER_DITHERING_SEQUENCE_TABLE_Green_16_23_reg, dither_32BIT_DATA);
						break;
				case 2:/* blue*/
						IoReg_Write32(DITHER_DITHERING_SEQUENCE_TABLE_Blue_16_23_reg, dither_32BIT_DATA);
						break;
				}

			}
			if (jj == 15) {
				switch (ii) {
				case 0:/* red*/
						IoReg_Write32(DITHER_DITHERING_SEQUENCE_TABLE_Red_24_31_reg, dither_32BIT_DATA);
						break;
				case 1:/* green*/
						IoReg_Write32(DITHER_DITHERING_SEQUENCE_TABLE_Green_24_31_reg, dither_32BIT_DATA);
						break;
				case 2:/* blue*/
						IoReg_Write32(DITHER_DITHERING_SEQUENCE_TABLE_Blue_24_31_reg, dither_32BIT_DATA);
						break;
				}

			}


		}
	}

	for (ii = 0; ii < VIP_DITHERLUT_ROW_MAX; ii++) {
		for (jj = 0; jj < VIP_DITHERLUT_COL_MAX; jj++) {

			dither_32BIT_DATA = 0;
			data_shift = 0;

			for (kk = 0; kk < VIP_DITHERLUT_DEP_MAX; kk++) {
				/* KWarning: checked ok by allen_zhang*/
				dither_32BIT_DATA += (tDITHER_LUT[ii][jj][kk] >> (Panel_Bit*2)) << data_shift;
				data_shift += 6;
			}

			switch (ii) {
			case 0: /* red*/
					IoReg_Write32(DITHER_DITHERING_Dither_TABLE_Red_00_reg+4*jj, dither_32BIT_DATA);
					break;
			case 1: /* green*/
					IoReg_Write32(DITHER_DITHERING_Dither_TABLE_Green_00_reg+4*jj, dither_32BIT_DATA);
					break;
			case 2: /* blue*/
					IoReg_Write32(DITHER_DITHERING_Dither_TABLE_Blue_00_reg+4*jj, dither_32BIT_DATA);
					break;
			}
		}
	}


	dither_32BIT_DATA = 0;

	for (ii = 0; ii < 16; ii++) {
		dither_32BIT_DATA += tDITHER_TEMPORAL[ii] << (ii * 2);
	}

	temporal_offset_reg.regValue = dither_32BIT_DATA;
	IoReg_Write32(DITHER_Temporal_offset_reg, temporal_offset_reg.regValue);

	dithering_ctrl_reg.regValue = 0;
	dithering_ctrl_reg.function_enable = 1;
	dithering_ctrl_reg.temporal_enable = 1;
	#if defined(CONFIG_PANEL_TPT_216B1)
	dithering_ctrl_reg.temporal_enable = 0; /*fix noise bug*/
	#endif

	IoReg_Write32(DITHER_DITHERING_CTRL_reg, dithering_ctrl_reg.regValue);

}

void drvif_color_set_main_dither(unsigned char enable)
{
	/* turn on dither t1*/
	/*IoReg_SetBits(0xb8022600, _BIT5);*/
	main_dither_i_main_dither_ctrl1_RBUS main_dither_i_main_dither_ctrl1_reg;
	di_color_recovery_option_RBUS di_color_recovery_option_reg;
	di_color_recovery_option_reg.regValue = IoReg_Read32(DI_Color_Recovery_Option_reg);
	if (enable ==1) {		/* for VO and HDMI*/
		if(di_color_recovery_option_reg.y10bitsin == 1) {		// 10 bit
			rtd_outl(0xb8022600, 0x00000438);
			rtd_outl(0xb8022604, 0x3705a2e4);
			rtd_outl(0xb8022608, 0xcb6931f6);
			rtd_outl(0xb802260c, 0xe6b0d21f);
			rtd_outl(0xb8022610, 0xc6871b45);
			rtd_outl(0xb8022614, 0x38c6b49e);
			rtd_outl(0xb8022618, 0x1b12dbd4);
			rtd_outl(0xb802261c, 0x01231230);
			rtd_outl(0xb8022620, 0x23013012);
			rtd_outl(0xb8022624, 0x01231230);
			rtd_outl(0xb8022628, 0x23013012);
			rtd_outl(0xb802262c, 0x01231230);
			rtd_outl(0xb8022630, 0x23013012);
			rtd_outl(0xb8022634, 0xe4e4e4e4);
		} else {		// 8 bit
			rtd_outl(0xb8022600, 0x00000428);
			rtd_outl(0xb8022604, 0x3705a2e4);
			rtd_outl(0xb8022608, 0xcb6931f6);
			rtd_outl(0xb802260c, 0xe6b0d21f);
			rtd_outl(0xb8022610, 0xc6871b45);
			rtd_outl(0xb8022614, 0x38c6b49e);
			rtd_outl(0xb8022618, 0x1b12dbd4);
			rtd_outl(0xb802261c, 0xe1968f70);
			rtd_outl(0xb8022620, 0x4b3c25da);
			rtd_outl(0xb8022624, 0x4b3c25da);
			rtd_outl(0xb8022628, 0xe1968f70);
			rtd_outl(0xb802262c, 0xe19625da);
			rtd_outl(0xb8022630, 0x8f704b3c);
			rtd_outl(0xb8022634, 0xc993366c);
		}
	} else if (enable ==2) {	/* for cp */
		if(di_color_recovery_option_reg.y10bitsin == 1) {		// 10 bit
			rtd_outl(0xb8022600, 0x00000438);
			rtd_outl(0xb8022604, 0x3705a2e4);
			rtd_outl(0xb8022608, 0xcb6931f6);
			rtd_outl(0xb802260c, 0xe6b0d21f);
			rtd_outl(0xb8022610, 0xc6871b45);
			rtd_outl(0xb8022614, 0x38c6b49e);
			rtd_outl(0xb8022618, 0x1b12dbd4);
			rtd_outl(0xb802261c, 0x01231230);
			rtd_outl(0xb8022620, 0x23013012);
			rtd_outl(0xb8022624, 0x01231230);
			rtd_outl(0xb8022628, 0x23013012);
			rtd_outl(0xb802262c, 0x01231230);
			rtd_outl(0xb8022630, 0x23013012);
			rtd_outl(0xb8022634, 0xe4e4e4e4);
		} else {		// 8 bit
			rtd_outl(0xb8022600, 0x00000438);
			rtd_outl(0xb8022604, 0x3705a2e4);
			rtd_outl(0xb8022608, 0xcb6931f6);
			rtd_outl(0xb802260c, 0xe6b0d21f);
			rtd_outl(0xb8022610, 0xc6871b45);
			rtd_outl(0xb8022614, 0x38c6b49e);
			rtd_outl(0xb8022618, 0x1b12dbd4);
			rtd_outl(0xb802261c, 0x9d51c840);
			rtd_outl(0xb8022620, 0xfb73ea62);
			rtd_outl(0xb8022624, 0x9d51c840);
			rtd_outl(0xb8022628, 0xfb73ea62);
			rtd_outl(0xb802262c, 0x9d51c840);
			rtd_outl(0xb8022630, 0xfb73ea62);
			rtd_outl(0xb8022634, 0xe4e4e4e4);
		}
	} else {
		main_dither_i_main_dither_ctrl1_reg.regValue = IoReg_Read32(MAIN_DITHER_I_Main_DITHER_CTRL1_reg);
		main_dither_i_main_dither_ctrl1_reg.ch1_dithering_table_select = 0;
		/*main_dither_i_main_dither_ctrl1_reg.ch1_value_sign = 1;*/
		main_dither_i_main_dither_ctrl1_reg.ch1_temporal_enable = 0;
		IoReg_Write32(MAIN_DITHER_I_Main_DITHER_CTRL1_reg, main_dither_i_main_dither_ctrl1_reg.regValue);
	}

}


/*============================================================================*/
/**
 * Color_Hdmi_SetDithering
 * This function is used to insert hdmi dither tables, including SEQ table & dither table
 *
 * @param <void>		{ void }
 * @return 			{ void }
 *
 */

#if 0
void drvif_color_hdmi_setdithering(unsigned char display)
{
	ctrl1_RBUS	ctrl1_REG;


	ctrl1_REG.regValue = IoReg_Read32(HDMI_DITHER_CTRL1_VADDR);

	hdmi_temporal_offset_tab1_RBUS	hdmi_temporal_offset_tab1_REG;
	hdmi_temporal_offset_tab2_RBUS hdmi_temporal_offset_tab2_REG;

	unsigned int dither_32BIT_DATA = 0;
	unsigned short ii, jj, kk, data_shift = 0, shift_bit = 0;


	/*RTD_Log(LOGGER_INFO, "Panel_Bit = %d\n", Panel_Bit);*/

	if (display == SLR_MAIN_DISPLAY) {  /* 0: 8bits ; 1: 10bits ;2: 12 bits 3: 16bits*/
		if (drvif_Hdmi_GetColorDepth() == 2) {
			shift_bit = 4; /*12bits ->10bits*/
		} else {
			return; /* 8 bits 10 bits 16 bits*/
		}
	} else {
		if (drvif_Hdmi_GetColorDepth() == 1) {
			shift_bit = 2; /*12bits ->8bits*/
		} else if (drvif_Hdmi_GetColorDepth() == 2) {
			shift_bit = 4; /*10bits ->8bits*/
		} else {
			return;/* 8 bits  16 bits*/
		}
	}


	for (ii = 0; ii < 3; ii++) /* rgb order*/ {
		for (jj = 0; jj < 16; jj++) {
			if ((jj == 0) || (jj == 8)) {
				dither_32BIT_DATA = 0;
				data_shift = 0;
			}
			dither_32BIT_DATA += (tDITHER_SEQUENCE[ii][jj]%16) << data_shift ;
			data_shift += 4;

			if (jj == 7) {
				switch (ii) {
				case 0:/* red*/
						IoReg_Write32(HDMI_DITHER_SEQUENCE_TABLE_RED_00_15_VADDR, dither_32BIT_DATA);
						break;
				case 1:/* green*/
						IoReg_Write32(HDMI_DITHER_SEQUENCE_TABLE_GREEN_00_07_VADDR, dither_32BIT_DATA);
						break;
				case 2:/* blue*/
						IoReg_Write32(HDMI_DITHER_SEQUENCE_TABLE_BLUE_00_15_VADDR, dither_32BIT_DATA);
						break;
				}
			}

			if (jj == 15) {
				switch (ii) {
				case 0: /* red*/
						IoReg_Write32(HDMI_DITHER_SEQUENCE_TABLE_RED_16_31_VADDR, dither_32BIT_DATA);
						break;
				case 1: /* green*/
						IoReg_Write32(HDMI_DITHER_SEQUENCE_TABLE_GREEN_16_31_VADDR, dither_32BIT_DATA);
						break;
				case 2: /* blue*/
						IoReg_Write32(HDMI_DITHER_SEQUENCE_TABLE_BLUE_16_31_VADDR, dither_32BIT_DATA);
						break;
				}
			}
		}
	}

	if (display == SLR_MAIN_DISPLAY) {
		for (ii = 0; ii < VIP_DITHERLUT_ROW_MAX; ii++) {
			for (jj = 0; jj < VIP_HDMI_DITHERLUT_COL_MAX; jj++) {
				if ((jj == 0) || (jj == 2)) {
					dither_32BIT_DATA = 0;
					data_shift = 0;
				}

				for (kk = 0; kk < 4; kk++) {
					dither_32BIT_DATA += (tDITHER_LUT[ii][jj][kk] >> shift_bit) << data_shift;
					data_shift += VIP_HDMI_DITHERLUT_DEP_MAX;
				}

				if (jj == 1) {
					switch (ii) {
					case 0: /* red*/
							IoReg_Write32(HDMI_DITHER_TAB1DITHER_TABLE_RED_00_VADDR, dither_32BIT_DATA);
							break;
					case 1: /* green*/
							IoReg_Write32(HDMI_DITHER_TAB1_DITHER_TABLE_GREEN_00_VADDR, dither_32BIT_DATA);
							break;
					case 2: /* blue*/
							IoReg_Write32(HDMI_DITHER_TAB1_DITHER_TABLE_BLUE_00_VADDR, dither_32BIT_DATA);
							break;
					}
				}

				if (jj == 3) {
					switch (ii) {
					case 0: /* red*/
							IoReg_Write32(HDMI_DITHER_TAB1_DITHER_TABLE_RED_02_VADDR, dither_32BIT_DATA);
							break;
					case 1: /* green*/
							IoReg_Write32(HDMI_DITHER_TAB1_DITHER_TABLE_GREEN_02_VADDR, dither_32BIT_DATA);
							break;
					case 2: /* blue*/
							IoReg_Write32(HDMI_DITHER_TAB1_DITHER_TABLE_BLUE_02_VADDR, dither_32BIT_DATA);
							break;
					}
				}


			}
		}

		dither_32BIT_DATA = 0;
		for (ii = 0; ii < 16; ii++) {
			dither_32BIT_DATA += tDITHER_TEMPORAL[ii] << (ii * 2);
		}

		hdmi_temporal_offset_tab1_REG.regValue = dither_32BIT_DATA;
		IoReg_Write32(HDMI_DITHER_HDMI_TEMPORAL_OFFSET_TAB1_VADDR, hdmi_temporal_offset_tab1_REG.regValue);

		ctrl1_REG.ch1_field_odd_temporal_offset_select = 0;
		ctrl1_REG.ch1_field_even_temporal_offset_select = 0;
		ctrl1_REG.ch1_dithering_table_select = 0x01;/*enable*/
		ctrl1_REG.ch1_temporal_enable = 1;
		IoReg_Write32(HDMI_DITHER_CTRL1_VADDR, ctrl1_REG.regValue);
	} else {
		for (ii = 0; ii < VIP_DITHERLUT_ROW_MAX; ii++) {
			for (jj = 0; jj < VIP_HDMI_DITHERLUT_COL_MAX; jj++) {
				if ((jj == 0) || (jj == 2)) {
					dither_32BIT_DATA = 0;
					data_shift = 0;
				}

				for (kk = 0; kk < 4; kk++) {
					dither_32BIT_DATA += (tDITHER_LUT[ii][jj][kk] >> shift_bit) << data_shift;
					data_shift += VIP_HDMI_DITHERLUT_DEP_MAX;
				}

				if (jj == 1) {
					switch (ii) {
					case 0: /* red*/
							IoReg_Write32(HDMI_DITHER_TAB2_DITHER_TABLE_RED_00_VADDR, dither_32BIT_DATA);
							break;
					case 1: /* green*/
							IoReg_Write32(HDMI_DITHER_TAB2_DITHER_TABLE_GREEN_00_VADDR, dither_32BIT_DATA);
							break;
					case 2: /* blue*/
							IoReg_Write32(HDMI_DITHER_TAB2_DITHER_TABLE_BLUE_00_VADDR, dither_32BIT_DATA);
							break;
					}
				}

				if (jj == 3) {
					switch (ii) {
					case 0: /* red*/
							IoReg_Write32(HDMI_DITHER_TAB2_DITHER_TABLE_RED_02_VADDR, dither_32BIT_DATA);
							break;
					case 1: /* green*/
							IoReg_Write32(HDMI_DITHER_TAB2_DITHER_TABLE_GREEN_02_VADDR, dither_32BIT_DATA);
							break;
					case 2: /* blue*/
							IoReg_Write32(HDMI_DITHER_TAB2_DITHER_TABLE_BLUE_02_VADDR, dither_32BIT_DATA);
							break;
					}
				}
			}
		}

		dither_32BIT_DATA = 0;
		for (ii = 0; ii < 16; ii++) {
			dither_32BIT_DATA += tDITHER_TEMPORAL[ii] << (ii * 2);
		}

		hdmi_temporal_offset_tab2_REG.regValue = dither_32BIT_DATA;
		IoReg_Write32(HDMI_DITHER_HDMI_TEMPORAL_OFFSET_TAB2_VADDR, hdmi_temporal_offset_tab2_REG.regValue);

		ctrl1_REG.ch2_field_odd_temporal_offset_select = 1;
		ctrl1_REG.ch2_field_even_temporal_offset_select = 1;
		ctrl1_REG.ch2_dithering_table_select = 2;
		ctrl1_REG.ch2_temporal_enable = 1;

		IoReg_Write32(HDMI_DITHER_CTRL1_VADDR, ctrl1_REG.regValue);
	}

}

#endif
/*============================================================================*/
/**
 * Color_Set Scale Down Dithering
 * This function is used to insert dither tables, including SEQ table & dither table
 *
 * @param <void>		{ void }
 * @return 			{ void }
 *
 */
void drvif_color_setSD_dithering(unsigned char enable)
{
	hsd_dither_sd_dither_ctrl1_RBUS	sd_dither_ctrl1_reg;
	unsigned int dither_32BIT_DATA = 0;
	unsigned short ii;


	hsd_dither_sd_dither_temporal_offset_tab_1_RBUS	sd_dither_temporal_offset_tab_1_reg;
	hsd_dither_sd_dither_temporal_offset_tab_2_RBUS	sd_dither_temporal_offset_tab_2_reg;



	if (enable == FALSE) {/* turn off SD Dither*/
		sd_dither_ctrl1_reg.ch1_dithering_table_select = 0;
		IoReg_Write32(HSD_DITHER_SD_Dither_CTRL1_reg, sd_dither_ctrl1_reg.regValue);
		return;
	}


	dither_32BIT_DATA = 0;

	for (ii = 0; ii < 16; ii++) {
		dither_32BIT_DATA += tDITHER_TEMPORAL[ii] << (ii * 2);
	}

	sd_dither_temporal_offset_tab_1_reg.regValue = dither_32BIT_DATA;
	IoReg_Write32(HSD_DITHER_SD_Dither_Temporal_offset_Tab_1_reg, sd_dither_temporal_offset_tab_1_reg.regValue);

	sd_dither_temporal_offset_tab_2_reg.regValue = dither_32BIT_DATA;
	IoReg_Write32(HSD_DITHER_SD_Dither_Temporal_offset_Tab_2_reg, sd_dither_temporal_offset_tab_2_reg.regValue);

	sd_dither_ctrl1_reg.regValue = 0; /* force all value = 0;*/
	sd_dither_ctrl1_reg.ch1_dithering_table_select = 1; /* enable dither*/
	sd_dither_ctrl1_reg.ch1_temporal_enable = 1; /* enable temporal dither*/
	sd_dither_ctrl1_reg.ch1_dithering_mode = 0; /* use New mode as dither*/
	sd_dither_ctrl1_reg.ch1_field_even_temporal_offset_select = 0; /* 0: even field use temporal table -1, 1: even field use temporal table -2*/
	sd_dither_ctrl1_reg.ch1_field_odd_temporal_offset_select = 1;	 /* 0: odd field use temporal table -1, 1: odd field use temporal table -2*/
	sd_dither_ctrl1_reg.ch1_temporal_offset_separate_mode = 0; /* 0: both even and odd field use the same temporal table, 1: use diffenent by table select*/
	/*sd_dither_ctrl1_reg.ch1_value_sign = 1; */ /* 0: RGB mode can use unsigned mode,  1:YUV mode use sign mode to prevent addition on single side.*/
	if (RGB2YUV_if_RGB_mode)
	sd_dither_ctrl1_reg.ch1_value_sign = 0; /* for prevent gray hue shift problem, this value must be 0 for unsigned mode. */ /* modified by Jerry Wu 20100111*/
	else
		sd_dither_ctrl1_reg.ch1_value_sign = 1; /* 1:YUV mode use sign mode to prevent addition on single side., */ /* modified by Jerry Wu 20100208*/


	IoReg_Write32(HSD_DITHER_SD_Dither_CTRL1_reg, sd_dither_ctrl1_reg.regValue);
}

/*============================================================================*/
/**
 * Color_SetDynamicDithering
 * This function is used to set dynamic dithering.
 *
 * @param <void>		{ void }
 * @return 			{ void }
 *
 */
void drvif_color_SetDynamicDithering(unsigned char src_idx, unsigned char value)
{
	dither_dithering_dd_th_g_RBUS dithering_dd_th_g_reg;
	dither_dithering_dd_th_r_RBUS dithering_dd_th_r_reg;
	dither_dithering_dd_th_b_RBUS dithering_dd_th_b_reg;
	if (value >= VIP_DYNAMIC_DITHERING_TABLE_MAX) {
		VIPprintf("[Warning] Invalid table ID, skip dynamic dithering...\n");
		return;
	}

	dithering_dd_th_g_reg.regValue = rtd_inl(DITHER_DITHERING_DD_TH_G_reg);
	dithering_dd_th_r_reg.regValue = rtd_inl(DITHER_DITHERING_DD_TH_R_reg);
	dithering_dd_th_b_reg.regValue = rtd_inl(DITHER_DITHERING_DD_TH_B_reg);

	dithering_dd_th_b_reg.dd_en = 1;

	/*R*/
	dithering_dd_th_r_reg.dd_r_0_th = tDDither_Coef[value][0];
	dithering_dd_th_r_reg.dd_r_1_th = tDDither_Coef[value][1];
	dithering_dd_th_r_reg.dd_r_b0_type = tDDither_Coef[value][2];	/*0:8bit, 1:7bit, 2:6bit*/
	dithering_dd_th_r_reg.dd_r_b1_type = tDDither_Coef[value][3];
	dithering_dd_th_r_reg.dd_r_b2_type = tDDither_Coef[value][4];

	/*G*/
	dithering_dd_th_g_reg.dd_g_0_th = tDDither_Coef[value][5];
	dithering_dd_th_g_reg.dd_g_1_th = tDDither_Coef[value][6];
	dithering_dd_th_g_reg.dd_g_b0_type = tDDither_Coef[value][7];
	dithering_dd_th_g_reg.dd_g_b1_type = tDDither_Coef[value][8];
	dithering_dd_th_g_reg.dd_g_b2_type = tDDither_Coef[value][9];

	/*B*/
	dithering_dd_th_b_reg.dd_b_0_th = tDDither_Coef[value][10];
	dithering_dd_th_b_reg.dd_b_1_th = tDDither_Coef[value][11];
	dithering_dd_th_b_reg.dd_b_b0_type = tDDither_Coef[value][12];
	dithering_dd_th_b_reg.dd_b_b1_type = tDDither_Coef[value][13];
	dithering_dd_th_b_reg.dd_b_b2_type = tDDither_Coef[value][14];

	rtd_outl(DITHER_DITHERING_DD_TH_R_reg, dithering_dd_th_r_reg.regValue);
	rtd_outl(DITHER_DITHERING_DD_TH_G_reg, dithering_dd_th_g_reg.regValue);
	rtd_outl(DITHER_DITHERING_DD_TH_B_reg, dithering_dd_th_b_reg.regValue);

}

/*============================================================================*/
/**
 * Color_SetHighlightWindow
 * Set HighlightWindow
 *
 * @param <Ena_bit> {Enable bit}
 * @param <HSTA> {H start}
 * @param <VSTA> {V start}
 * @param <HEND> {H end}
 * @param <VEND> {V end}
 *
 * @return 			{ void }
 *
 */
void drvif_color_sethighlightwindowstep(unsigned short hstep, unsigned short wstep, unsigned short vstep, unsigned short lstep)
{
return;
#if 0 // mac5 fix me
	ppoverlay_highlight_window_update_step_RBUS window_step_reg;
	window_step_reg.regValue = IoReg_Read32(PPOVERLAY_Highlight_window_update_step_reg);
	window_step_reg.hlw_h_sta_step = hstep;
	window_step_reg.hlw_v_sta_step = vstep;
	window_step_reg.hlw_width_step = wstep;
	window_step_reg.hlw_height_step = lstep;
	IoReg_Write32(PPOVERLAY_Highlight_window_update_step_reg, window_step_reg.regValue);/*set heightlight window step*/
#endif
}


void drvif_color_set_sethighlightwindowmin(unsigned short minwidth, unsigned short minlen)
{return;
#if 0 // mac5 fix me
	/*set heightlight window min window*/
	ppoverlay_highlight_window_min_status_RBUS window_min_status_reg;
	window_min_status_reg.regValue = IoReg_Read32(PPOVERLAY_Highlight_window_min_status_reg);
	window_min_status_reg.hlw_min_width = minwidth;
	window_min_status_reg.hlw_min_height = minlen;
	IoReg_Write32(PPOVERLAY_Highlight_window_min_status_reg, window_min_status_reg.regValue);
#endif
}

void drvif_color_sethighlightwindow(unsigned char Ena_bit, unsigned short HSTA, unsigned short VSTA, unsigned short HEND, unsigned short VEND, unsigned short Border)
{
return;
#if 0 // mac5 fix me
	/*color_d_vc_global_ctrl_RBUS vc_reg;*/ /*Thur modified for compile 20090113*/
	ppoverlay_highlight_window_control_RBUS vc_reg;
	ppoverlay_highlight_window_h_initial_start_width_RBUS window_h_reg;
	ppoverlay_highlight_window_v_initial_start_height_RBUS window_v_reg;
	ppoverlay_highlight_window_h_boundary_RBUS window_h_boundry_reg;
	ppoverlay_highlight_window_v_boundary_RBUS window_v_boundry_reg;
	UINT16 MAIN_Active_H_Start = 0, MAIN_Active_H_End = 0;
	UINT16 MAIN_Active_V_Start = 0, MAIN_Active_V_End = 0;

	/*WaitFor_DEN_STOP();*/
	if (Ena_bit) {

		VIPprintf("Enable Highlight window x1:%d y1:%d x2:%d y2:%d\n", HSTA, VSTA, HEND, VEND);

		/*set heightlight window mode*/
		vc_reg.regValue = IoReg_Read32(PPOVERLAY_Highlight_window_control_reg);
		vc_reg.hlw_en = 1;
		vc_reg.hlw_mode = 0;
		IoReg_Write32(PPOVERLAY_Highlight_window_control_reg, vc_reg.regValue);/* enable highlight window*/

		MAIN_Active_H_Start = Scaler_GetMAG_H_Region_Start();
		MAIN_Active_H_End = Scaler_GetMAG_H_Region_End();
		MAIN_Active_V_Start = Scaler_GetMAG_V_Region_Start();
		MAIN_Active_V_End = Scaler_GetMAG_V_Region_End();
#if 1
		/*USER:LewisLee DATE:2010/10/06*/
		/*to prevent after execute zoom function, the magic picture abnormal*/
		/*set heightlight window boundry*/
		window_h_boundry_reg.regValue = IoReg_Read32(PPOVERLAY_Highlight_window_H_boundary_reg);
		window_v_boundry_reg.regValue = IoReg_Read32(PPOVERLAY_Highlight_window_V_boundary_reg);
		window_h_boundry_reg.hlw_h_bd_sta = MAIN_Active_H_Start;
		window_h_boundry_reg.hlw_h_bd_end = MAIN_Active_H_End;
		window_v_boundry_reg.hlw_v_bd_sta = MAIN_Active_V_Start;
		window_v_boundry_reg.hlw_v_bd_end = MAIN_Active_V_End;
		IoReg_Write32(PPOVERLAY_Highlight_window_H_boundary_reg, window_h_boundry_reg.regValue);
		IoReg_Write32(PPOVERLAY_Highlight_window_V_boundary_reg, window_v_boundry_reg.regValue);
#else /*#if 1*/
		/*set heightlight window boundry*/
		window_h_boundry_reg.regValue = IoReg_Read32(PPOVERLAY_Highlight_window_H_boundary_reg);
		window_v_boundry_reg.regValue = IoReg_Read32(PPOVERLAY_Highlight_window_V_boundary_reg);
		window_h_boundry_reg.hlw_h_bd_sta = 0 ;
		window_h_boundry_reg.hlw_h_bd_end = _DISP_WID;
		window_v_boundry_reg.hlw_v_bd_sta = 0;
		window_v_boundry_reg.hlw_v_bd_end = _DISP_LEN;
		IoReg_Write32(PPOVERLAY_Highlight_window_H_boundary_reg, window_h_boundry_reg.regValue);
		IoReg_Write32(PPOVERLAY_Highlight_window_V_boundary_reg, window_v_boundry_reg.regValue);
#endif /*#if 1*/

		/*USER:LewisLee DATE:2010/12/30*/
		/*to prevent start/end position large than active window*/
		/*the magic picture will fail*/
		if (HSTA < MAIN_Active_H_Start)
			HSTA = MAIN_Active_H_Start;

		if (HEND > MAIN_Active_H_End)
			HEND = MAIN_Active_H_End;

		if (VSTA < MAIN_Active_V_Start)
			VSTA = MAIN_Active_V_Start;

		if (VEND > MAIN_Active_V_End)
			VEND = MAIN_Active_V_End;

		/* set heightlight window init value*/
		window_h_reg.regValue = IoReg_Read32(PPOVERLAY_Highlight_window_H_initial_start_width_reg);
		window_h_reg.hlw_h_ini_sta = HSTA & 0xFFF;
		window_h_reg.hlw_ini_width = (HEND - HSTA) & 0xFFF;
		if (HEND - HSTA < Border) {
			VIPprintf("Enable Highlight Window Position Error\n");
			ucHighLightwindow_EnableFlag = _DISABLE;
			return;
		}

		ucHighLightwindow_EnableFlag = _ENABLE;

		IoReg_Write32(PPOVERLAY_Highlight_window_H_initial_start_width_reg, window_h_reg.regValue);

		window_v_reg.regValue = IoReg_Read32(PPOVERLAY_Highlight_window_V_initial_start_height_reg);
		window_v_reg.hlw_v_ini_sta = VSTA & 0x870;
		window_v_reg.hlw_ini_height = (VEND - VSTA) & 0x870;
		IoReg_Write32(PPOVERLAY_Highlight_window_V_initial_start_height_reg, window_v_reg.regValue);

		/*enable double buffer*/
		IoReg_Write32(PPOVERLAY_Highlight_window_DB_CTRL_reg, 0x1);
	} else{
		/*VIPprintf("Disable Highlight window\n");*/
		vc_reg.regValue = IoReg_Read32(PPOVERLAY_Highlight_window_control_reg);
		vc_reg.hlw_en = 0;
		IoReg_Write32(PPOVERLAY_Highlight_window_H_initial_start_width_reg, 0x0);
		IoReg_Write32(PPOVERLAY_Highlight_window_V_initial_start_height_reg, 0x0);
		IoReg_Write32(PPOVERLAY_Highlight_window_boundary_condition_reg, 0x3f0);
		IoReg_Write32(PPOVERLAY_Highlight_window_control_reg, vc_reg.regValue);/* disable highlight window*/
		IoReg_Write32(PPOVERLAY_Highlight_window_DB_CTRL_reg, 0x1);
	}
	/*WaitFor_DEN_STOP();*/
#endif
}

/*USER:LewisLee DATE:2011/04/16*/
/*check HW highlight window function enable*/
/*to prevent power on/off curtain mode*/
/*hang-up for a long time*/
UINT8 drvif_color_gethighlightwindow_enable(void)
{
#if 0
	highlight_window_control_RBUS highlight_window_control_reg;

	highlight_window_control_reg.regValue = IoReg_Read32(PPOVERLAY_Highlight_window_control_reg);

	if (_ENABLE == highlight_window_control_reg.hlw_en)
		return _ENABLE;

	return _DISABLE;
#else /*#if 0*/
	return ucHighLightwindow_EnableFlag;
#endif /*#if 0*/
}

void drvif_color_sethighlightwindowborder(unsigned char Border, unsigned char BorderType)
{
	unsigned char Top = 0, Bottom = 0, Left = 0, Right = 0;

	switch (BorderType) {
	case BORDERSTYLE_NONE:
/*		Inaccuracy = 1;*/
		break;
	case BORDERSTYLE_TOP: /*up*/
		Top = Border;
		break;
	case BORDERSTYLE_BOTTOM: /*down*/
		Bottom = Border;
		break;
	case BORDERSTYLE_LEFT: /*left*/
		Left = Border;
		break;
	case BORDERSTYLE_RIGHT: /*right*/
		Right = Border;
		break;
	case BORDERSTYLE_ALL: /*all*/
	default:
		Top = Border;
		Bottom = Border;
		Left = Border;
		Right = Border;
		break;
	}
	return;
#if 0 // mac5 fix me
	IoReg_Write32(PPOVERLAY_Highlight_window_border_width_reg, ((Top & 0x3f) << 24) | ((Bottom & 0x3f) << 16) | ((Left & 0x3f) << 8) | ((Right & 0x3f)));
	IoReg_Write32(PPOVERLAY_Highlight_window_DB_CTRL_reg, 0x1);
#endif
}

void drvif_color_set_ygain_level(unsigned char display, unsigned char level)
{

#if 0
	tab1_yo_and_y_gain_RBUS tab1_Yo_and_Y_Gain_REG;

/* Level: 0~4, use 1~4 as 0.9~0.6*/
	if (display == _SUB_DISPLAY)
		return;

	unsigned short New_Y_Ratio = 1024;
	unsigned int New_Y_Value = 1024;


	switch (level) {
	case 0:
			New_Y_Ratio = 256;
			break;
	case 1:
			New_Y_Ratio = 214;/*240;*/
			break;
	case 2:
			New_Y_Ratio = 240;/*214;*/
			break;
	case 3:
			New_Y_Ratio = 184;/*200;*/
			break;
	case 4:
			New_Y_Ratio = 200;/*184;*/
			break;

	default:
			New_Y_Ratio = 256;
			break;

	}

	New_Y_Value = (RGB2YUV_Y_Gain * New_Y_Ratio) >> 8;

	tab1_Yo_and_Y_Gain_REG.regValue = IoReg_Read32(RGB2YUV_TAB1_YO_AND_Y_GAIN_ADDR);
	tab1_Yo_and_Y_Gain_REG.y_gain = (New_Y_Value > 511) ? 511 : (New_Y_Value < 0) ? 0 : New_Y_Value; /* clamp 9-bit*/
	VIPprintf("<<<<<<<<<<<<<<<<<<<<< Scene Level = %d, Ratio Value = %d <<<<<<<<<<<<<<<<<<<<<)\n", level, New_Y_Value);

	IoReg_Write32(RGB2YUV_TAB1_YO_AND_Y_GAIN_ADDR, tab1_Yo_and_Y_Gain_REG.regValue);


#endif
}

void wait_for_sRGB_fifo_empty(void)
{

	srgb_srgb_access_ctrl_RBUS  SRGB_access_ctrl_reg;

	signed short fifo_count = 5000;
	unsigned char status = 1;

	do {

		SRGB_access_ctrl_reg.regValue = IoReg_Read32(SRGB_sRGB_Access_CTRL_reg);
		if (SRGB_access_ctrl_reg.srgb_fifo_empty == 1)
			status = 0;
		else {
			fifo_count--;
			/*VIPprintf("[sRGB] SRGB_access_ctrl_reg.srgb_fifo_empty == 0 !!!");*/
		}


	} while ((fifo_count > 0) && (status));
	if (status)
		VIPprintf("sRGB Control write fifo error\n");

}

/*lewis 20091126, when we force to background, we need set it to bypass*/
void drvif_color_sRGB_TableSelEnable(unsigned char display, unsigned char Enable)
{
	srgb_srgb_ctrl_RBUS srgb_ctrl_reg;

	if (SLR_MAIN_DISPLAY == display) {
		if (TRUE == Enable) {
			srgb_ctrl_reg.regValue = IoReg_Read32(SRGB_sRGB_CTRL_reg);
			srgb_ctrl_reg.srgb_m_tab_sel = _SRGB_MAIN_TABLE_SEL;
			IoReg_Write32(SRGB_sRGB_CTRL_reg, srgb_ctrl_reg.regValue);
		} else {/* if (_DISABLE == Enable)*/

			srgb_ctrl_reg.regValue = IoReg_Read32(SRGB_sRGB_CTRL_reg);
			srgb_ctrl_reg.srgb_m_tab_sel = _SRGB_TABLE_BYPASS;
			IoReg_Write32(SRGB_sRGB_CTRL_reg, srgb_ctrl_reg.regValue);
		}
	}
#ifdef CONFIG_DUAL_CHANNEL
#ifdef VIP_CONFIG_DUAL_CHANNEL // henry 161214

	else {/* if (SLR_SUB_DISPLAY == display)*/
		if (TRUE == Enable) {
			srgb_ctrl_reg.regValue = IoReg_Read32(SRGB_sRGB_CTRL_reg);
			/*srgb_ctrl_reg.srgb_s_tab_sel = _SRGB_SUB_TABLE_SEL;*/
			IoReg_Write32(SRGB_sRGB_CTRL_reg, srgb_ctrl_reg.regValue);
		} else {/* if (_DISABLE == Enable)*/

			srgb_ctrl_reg.regValue = IoReg_Read32(SRGB_sRGB_CTRL_reg);
			/*srgb_ctrl_reg.srgb_s_tab_sel = _SRGB_TABLE_BYPASS;*/
			IoReg_Write32(SRGB_sRGB_CTRL_reg, srgb_ctrl_reg.regValue);
		}
	}
#endif
#endif
}

void drvif_color_sRGB_ByPass(void)
{/*bypass sRGB*/
	srgb_srgb_ctrl_RBUS	SRGB_ctrl_reg;
	SRGB_ctrl_reg.regValue = IoReg_Read32(SRGB_sRGB_CTRL_reg);
	SRGB_ctrl_reg.srgb_m_tab_sel = _SRGB_TABLE_BYPASS;
	/*SRGB_ctrl_reg.srgb_s_tab_sel = _SRGB_TABLE_BYPASS;*/
	IoReg_Write32(SRGB_sRGB_CTRL_reg, SRGB_ctrl_reg.regValue);
}

void scalerVIP_sRGB_Write_FullSize_rgbChange(int color_change)
{
	srgb_srgb_ctrl_RBUS  SRGB_ctrl_reg;
	srgb_srgb_access_ctrl_RBUS  SRGB_access_ctrl_reg;
	srgb_srgb_access_port_RBUS	 SRGB_access_port_reg;
	signed short ii, jj, mm;/*, kk;*/
	/*signed short index_gain[2];*/
	VIPprintf("[sRGB] scalerVIP_sRGB_Write_Full_rgbChange\n");

	for (mm = 0; mm < 3; mm++) {
		VIPprintf("========== [sRGB_write] mm =%d ==========\n", mm);
		/* channel switch  SRGB_ACCESS_CTRL_reg*/
		SRGB_access_ctrl_reg.regValue = rtd_inl(SRGB_sRGB_Access_CTRL_reg);
		switch (mm) {
		case 0:  /* start with RR, GR, BR channels*/
			SRGB_access_ctrl_reg.srgb_rgb_sel = 1;
			break;
		case 1:  /* start with RG, GG, BG channels*/
			SRGB_access_ctrl_reg.srgb_rgb_sel = 2;
			break;
		case 2:  /* start with RB, GB, BB channels*/
			SRGB_access_ctrl_reg.srgb_rgb_sel = 3;
			break;
		}
		/*SRGB_access_ctrl_reg.srgb_tab_sel = 0; */ /* write in table1 */ /* [jyyang@ Mac3] only main channel and one table*/
		rtd_outl(SRGB_sRGB_Access_CTRL_reg, SRGB_access_ctrl_reg.regValue);

		for (ii = 0; ii < 128; ii++) {
			#if 0
			if (ii == 64) {
				SRGB_access_ctrl_reg.regValue = rtd_inl(SRGB_sRGB_Access_CTRL_reg);
				SRGB_access_ctrl_reg.srgb_tab_sel = 1; /* write in table2*/
				rtd_outl(SRGB_sRGB_Access_CTRL_reg, SRGB_access_ctrl_reg.regValue);
			} /* [jyyang@ Mac3] only main channel and one table*/
			#endif
			wait_for_sRGB_fifo_empty();

			for (jj = mm*3; jj < (mm*3 + 3); jj++) {
				if (((jj+color_change)%3) == mm) {
					SRGB_access_port_reg.srgb_index = 128*ii;
					SRGB_access_port_reg.srgb_gain = 32;
				} else {
					SRGB_access_port_reg.srgb_index = 0;
					SRGB_access_port_reg.srgb_gain = 0;
				}
				/*RTD_Log(LOGGER_INFO,"sRGB =============%x\n", SRGB_access_port_reg.regValue);*/
				rtd_outl(SRGB_sRGB_ACCESS_PORT_reg, SRGB_access_port_reg.regValue);
			}

		}
		wait_for_sRGB_fifo_empty();
	}

	/* close table access*/
	SRGB_access_ctrl_reg.regValue = rtd_inl(SRGB_sRGB_Access_CTRL_reg);
	SRGB_access_ctrl_reg.srgb_rgb_sel = 0;
	rtd_outl(SRGB_sRGB_Access_CTRL_reg, SRGB_access_ctrl_reg.regValue);

	/* enable sRGB  SRGB_CTRL_reg*/
	SRGB_ctrl_reg.regValue = rtd_inl(SRGB_sRGB_CTRL_reg);
	/* SRGB_ctrl_reg.srgb_tab_size_sel = 0; */ /* [0] tab_size = 128; [1] tab_size = 64; */ /* [jyyang@ Mac3] only main channel and one table*/
	SRGB_ctrl_reg.srgb_m_tab_sel = 1; /* main always tab-1*/
	rtd_outl(SRGB_sRGB_CTRL_reg, SRGB_ctrl_reg.regValue);

}

#if 0 /* [jyyang@ Mac3] only main channel and one table*/
void scalerVIP_sRGB_Write_HalfSize_rgbChange(int table_sel, int color_change)
{
	srgb_srgb_ctrl_RBUS  SRGB_ctrl_reg;
	srgb_srgb_access_ctrl_RBUS  SRGB_access_ctrl_reg;
	srgb_srgb_access_port_RBUS	 SRGB_access_port_reg;
	signed short ii, jj, kk, mm;
	signed short index_gain[2];
	VIPprintf("[sRGB] scalerVIP_sRGB_Write_Half_rgbChange\n");

	for (mm = 0; mm < 3; mm++) {
		VIPprintf("========== [sRGB_write] mm =%d (table%d) ==========\n", mm, table_sel+1);
		/* channel switch  SRGB_ACCESS_CTRL_reg*/
		SRGB_access_ctrl_reg.regValue = rtd_inl(SRGB_sRGB_Access_CTRL_reg);
		switch (mm) {
		case 0:  /* start with RR, GR, BR channels*/
			SRGB_access_ctrl_reg.srgb_rgb_sel = 1;
			break;
		case 1:  /* start with RG, GG, BG channels*/
			SRGB_access_ctrl_reg.srgb_rgb_sel = 2;
			break;
		case 2:  /* start with RB, GB, BB channels*/
			SRGB_access_ctrl_reg.srgb_rgb_sel = 3;
			break;
		}
		SRGB_access_ctrl_reg.srgb_tab_sel = table_sel; /* [0] table1, [1] table2*/
		rtd_outl(SRGB_sRGB_Access_CTRL_reg, SRGB_access_ctrl_reg.regValue);

		for (ii = 0; ii < 64; ii++) {
			wait_for_sRGB_fifo_empty();
			for (jj = mm*3; jj < (mm*3 + 3); jj++) {
				if (((jj+color_change)%3) == mm) {
					SRGB_access_port_reg.srgb_index = 256*ii;
					SRGB_access_port_reg.srgb_gain = 32;
				} else {
					SRGB_access_port_reg.srgb_index = 0;
					SRGB_access_port_reg.srgb_gain = 0;
				}
				/*RTD_Log(LOGGER_INFO,"sRGB =============%x\n", SRGB_access_port_reg.regValue);*/
				rtd_outl(SRGB_sRGB_ACCESS_PORT_reg, SRGB_access_port_reg.regValue);

			}

		}
		wait_for_sRGB_fifo_empty();
	}

	/* close table access*/
	SRGB_access_ctrl_reg.regValue = rtd_inl(SRGB_sRGB_Access_CTRL_reg);
	SRGB_access_ctrl_reg.srgb_rgb_sel = 0;
	rtd_outl(SRGB_sRGB_Access_CTRL_reg, SRGB_access_ctrl_reg.regValue);

	/* enable sRGB  SRGB_CTRL_reg*/
	SRGB_ctrl_reg.regValue = rtd_inl(SRGB_sRGB_CTRL_reg);
	SRGB_ctrl_reg.srgb_tab_size_sel = 1; /* [0] tab_size = 128; [1] tab_size = 64;*/
	SRGB_ctrl_reg.srgb_m_tab_sel = table_sel+1; /* main always tab-1*/
	rtd_outl(SRGB_sRGB_CTRL_reg, SRGB_ctrl_reg.regValue);

}
#endif

void scalerVIP_sRGB_Read_FullSize(void)
{
	/*srgb_srgb_ctrl_RBUS  SRGB_ctrl_reg;*/
	srgb_srgb_access_ctrl_RBUS  SRGB_access_ctrl_reg;
	srgb_srgb_access_port_RBUS	 SRGB_access_port_reg;
	signed short ii, jj, mm; /*, kk;*/
	/*signed short index_gain[2];*/
	VIPprintf("[sRGB] scalerVIP_sRGB_HueSat_Read_jyyang\n");


	for (mm = 0; mm < 3; mm++) {
		/* channel switch  SRGB_ACCESS_CTRL_reg*/
		VIPprintf("========== [sRGB_Read] mm =%d ==========\n", mm);
		SRGB_access_ctrl_reg.regValue = rtd_inl(SRGB_sRGB_Access_CTRL_reg);
		switch (mm) {
		case 0:  /* start with RR, GR, BR channels*/
			SRGB_access_ctrl_reg.srgb_rgb_sel = 1;
			break;
		case 1:  /* start with RG, GG, BG channels*/
			SRGB_access_ctrl_reg.srgb_rgb_sel = 2;
			break;
		case 2:  /* start with RB, GB, BB channels*/
			SRGB_access_ctrl_reg.srgb_rgb_sel = 3;
			break;
		}
		/* SRGB_access_ctrl_reg.srgb_tab_sel = 0; */ /* write in table1 */ /* [jyyang@ Mac3] only main channel and one table*/
		rtd_outl(SRGB_sRGB_Access_CTRL_reg, SRGB_access_ctrl_reg.regValue);

		for (ii = 0; ii < 128; ii++) {
			#if 0
			if (ii == 64) {
				SRGB_access_ctrl_reg.regValue = rtd_inl(SRGB_sRGB_Access_CTRL_reg);
				SRGB_access_ctrl_reg.srgb_tab_sel = 1; /* write in table2*/
				rtd_outl(SRGB_sRGB_Access_CTRL_reg, SRGB_access_ctrl_reg.regValue);
			} /*[jyyang@ Mac3] only main channel and one table*/
			#endif
			wait_for_sRGB_fifo_empty();

			VIPprintf("[sRGB] ii =%03d: value =", ii);
			for (jj = mm*3; jj < (mm*3 + 3); jj++) {
				 SRGB_access_port_reg.regValue = rtd_inl(SRGB_sRGB_ACCESS_PORT_reg);
				 VIPprintf("%08x ", SRGB_access_port_reg.regValue);
			}
			VIPprintf("\n");
		}
	}

	/* close table access*/
	SRGB_access_ctrl_reg.regValue = rtd_inl(SRGB_sRGB_Access_CTRL_reg);
	SRGB_access_ctrl_reg.srgb_rgb_sel = 0;
	rtd_outl(SRGB_sRGB_Access_CTRL_reg, SRGB_access_ctrl_reg.regValue);

	/* enable sRGB  SRGB_CTRL_reg*/
	#if 0
	SRGB_ctrl_reg.regValue = rtd_inl(SRGB_sRGB_CTRL_reg);
	SRGB_ctrl_reg.srgb_tab_size_sel = 0; /* [0] tab_size = 128; [1] tab_size = 64;*/
	SRGB_ctrl_reg.srgb_m_tab_sel = 1; /* main always tab-1*/
	rtd_outl(SRGB_sRGB_CTRL_reg, SRGB_ctrl_reg.regValue);
	#endif

}





void drvif_sRGB_SetGrid(unsigned char display, signed int *sRGB_grid)
{
#if 1	/*Elsie 20131025: move writing table to video firmware to guarantee writing table at D-domain porch*/
	int ret;
	static int TempTable[9][Bin_Num_sRGB+1];
	int ii, jj;

	for (ii = 0; ii < 9; ii++) {
		for (jj = 0; jj < (Bin_Num_sRGB+1); jj++) {
			TempTable[ii][jj] = (int)fwif_color_ChangeOneUINT32Endian((unsigned int)*(sRGB_grid+ii*(Bin_Num_sRGB+1)+jj), 1);	//sRGB run to d domain isr need enfian
			/*VIPprintf("%d\t", TempTable[ii][jj]);*/
		}
		/*VIPprintf("\n");*/
	}
	memcpy((int *)Scaler_GetShareMemVirAddr(SCALERIOC_SET_SRGB_HUE_SAT), TempTable, sizeof(int)*9*(Bin_Num_sRGB+1));
	ret = Scaler_SendRPC(SCALERIOC_SET_SRGB_HUE_SAT, 0, 0);
	if (ret < 0) {
		VIPprintf("ret = %d, update sRGB_Hue_Sat to driver fail !!!\n", ret);
	}

#else
	srgb_srgb_ctrl_RBUS  SRGB_ctrl_reg;
	srgb_srgb_access_ctrl_RBUS  SRGB_access_ctrl_reg;
	srgb_srgb_access_port_RBUS	 SRGB_access_port_reg;
	static unsigned char m_table;
	int ii, jj, mm, kk;
	signed short index_gain[2];

/*	Scaler_WaitForEvent(_D_DOMAIN, _BIT10);*/
/*	ROS_ENTER_CRITICAL();*/
	WaitFor_DEN_STOP();
	/*ROS_EXIT_CRITICAL();*/

	SRGB_access_ctrl_reg.regValue = IoReg_Read32(SRGB_sRGB_Access_CTRL_reg);
	SRGB_ctrl_reg.regValue = IoReg_Read32(SRGB_sRGB_CTRL_reg);
	if (display  == SLR_MAIN_DISPLAY) {
		/*table select 1   SRGB_ACCESS_CTRL_reg*/
		/*SRGB_access_ctrl_reg.srgb_tab_sel = 0;*/
		SRGB_ctrl_reg.srgb_m_tab_sel = 0;
		/*s_table = SRGB_ctrl_reg.srgb_s_tab_sel;*/
		/*SRGB_ctrl_reg.srgb_s_tab_sel = 0;*/
	} else {
		 /*table select 2*/
		/*SRGB_access_ctrl_reg.srgb_tab_sel = 1;*/
		 m_table = SRGB_ctrl_reg.srgb_m_tab_sel;
		 SRGB_ctrl_reg.srgb_m_tab_sel = 0;
		/*SRGB_ctrl_reg.srgb_s_tab_sel = 0;*/
	}

	IoReg_Write32(SRGB_sRGB_Access_CTRL_reg, SRGB_access_ctrl_reg.regValue);
	IoReg_Write32(SRGB_sRGB_CTRL_reg, SRGB_ctrl_reg.regValue);

	for (mm = 0; mm < 3; mm++) {
		/* channel switch  SRGB_ACCESS_CTRL_reg*/
		SRGB_access_ctrl_reg.regValue = IoReg_Read32(SRGB_sRGB_Access_CTRL_reg);
		switch (mm) {
		case 0:  /* start with RR, GR, BR channels*/
			SRGB_access_ctrl_reg.srgb_rgb_sel = 1;
			break;
		case 1:  /* start with RG, GG, BG channels*/
			SRGB_access_ctrl_reg.srgb_rgb_sel = 2;
			break;
		case 2:  /* start with RB, GB, BB channels*/
			SRGB_access_ctrl_reg.srgb_rgb_sel = 3;
			break;
		}
		SRGB_access_ctrl_reg.srgb_tab_sel = 0; /* write table1*/
		IoReg_Write32(SRGB_sRGB_Access_CTRL_reg, SRGB_access_ctrl_reg.regValue);

		for (ii = 0; ii < Bin_Num_sRGB; ii++) {
			if (ii == Bin_Num_sRGB/2) {
				SRGB_access_ctrl_reg.regValue = IoReg_Read32(SRGB_sRGB_Access_CTRL_reg);
				SRGB_access_ctrl_reg.srgb_tab_sel = 1; /* write table2*/
				IoReg_Write32(SRGB_sRGB_Access_CTRL_reg, SRGB_access_ctrl_reg.regValue);
			}

			 /* check fifo status*/
			/*if ((ii == 4)||(ii == 8)||(ii == 12))*/
				wait_for_sRGB_fifo_empty();

			for (jj = mm*3; jj < (mm*3 + 3); jj++) {
				index_gain[0] = ((signed int) sRGB_grid[jj][ii]);/* & 0xfff00 ; */ /* RR GR BR RG GG BG RB GB BB*/
				kk = sRGB_grid[jj][ii+1] - sRGB_grid[jj][ii]; /* grid distance  = 256 (8-bit), gain = >> 8  << 5*/
				index_gain[1] = kk >> 2; /* 3 -> 2 fix bit error by March 20090629;*/
				index_gain[1] &= 0x3ff;
			/*	index_gain[1] = 0;*/
				/*index_gain[0] = 0;*/

				/* write fifo  SRGB_ACCESS_PORT_reg*/

				SRGB_access_port_reg.srgb_index = index_gain[0];
				SRGB_access_port_reg.srgb_gain = index_gain[1];
				/*RTD_Log(LOGGER_INFO,"sRGB =============%x\n", SRGB_access_port_reg.regValue);*/
				IoReg_Write32(SRGB_sRGB_ACCESS_PORT_reg, SRGB_access_port_reg.regValue);
			}

			/*if ((ii  % 16) == 15) */ /**/
			/*{*/
			/*	wait_for_sRGB_fifo_empty();*/
			/*}*/

		}

	}

	/* close table access*/
	SRGB_access_ctrl_reg.regValue = IoReg_Read32(SRGB_sRGB_Access_CTRL_reg);
	SRGB_access_ctrl_reg.srgb_rgb_sel = 0;
	IoReg_Write32(SRGB_sRGB_Access_CTRL_reg, SRGB_access_ctrl_reg.regValue);

	/* enable sRGB  SRGB_CTRL_reg*/
	SRGB_ctrl_reg.regValue = IoReg_Read32(SRGB_sRGB_CTRL_reg);
	/*SRGB_access_ctrl_reg = IoReg_Read32(SRGB_ACCESS_CTRL_reg);*/
	if (display  == SLR_MAIN_DISPLAY) {
		/* main always tab-1*/
		SRGB_ctrl_reg.srgb_m_tab_sel = 1;
		/*SRGB_ctrl_reg.srgb_s_tab_sel = s_table;*/
		/*SRGB_ctrl_reg.srgb_overlap = 1;*/
	} else {
		/* sub always tab-2, overlay = sub*/
		/*SRGB_ctrl_reg.srgb_s_tab_sel = 2;*/
		/*SRGB_ctrl_reg.srgb_overlap = 1;*/
		SRGB_ctrl_reg.srgb_m_tab_sel = m_table;
	}

	IoReg_Write32(SRGB_sRGB_CTRL_reg, SRGB_ctrl_reg.regValue);
#endif
}

void drvif_color_chroma_coring(unsigned char display, unsigned char domain, unsigned char Level)
{
/*Elsie 20130318: According to spec, C-coring is removed.*/
	VIPprintf("[Warning] C-coring is a deprecated function and will do nothing.\n");
#if 0
	c_coring_data_1_I_RBUS	c_coring_data_1_I_reg;
	c_coring_data_2_I_RBUS	c_coring_data_2_I_reg;
	c_coring_data_3_I_RBUS	c_coring_data_3_I_reg;
	c_coring_data_4_I_RBUS	c_coring_data_4_I_reg;
#if 0
	c_coring_data_1_D_RBUS	c_coring_data_1_D_reg;
	c_coring_data_2_D_RBUS	c_coring_data_2_D_reg;
	c_coring_data_3_D_RBUS	c_coring_data_3_D_reg;
	c_coring_data_4_D_RBUS	c_coring_data_4_D_reg;
#endif
	c_coring_data_1_I_reg.regValue = IoReg_Read32(RGB2YUV_C_CORING_DATA_1_I_VADDR);
	c_coring_data_2_I_reg.regValue = IoReg_Read32(RGB2YUV_C_CORING_DATA_2_I_VADDR);
	c_coring_data_3_I_reg.regValue = IoReg_Read32(RGB2YUV_C_CORING_DATA_3_I_VADDR);
	c_coring_data_4_I_reg.regValue = IoReg_Read32(RGB2YUV_C_CORING_DATA_4_I_VADDR);
#if 0
	c_coring_data_1_D_reg.regValue = IoReg_Read32(YUV2RGB_C_CORING_DATA_1_D_VADDR);
	c_coring_data_2_D_reg.regValue = IoReg_Read32(YUV2RGB_C_CORING_DATA_2_D_VADDR);
	c_coring_data_3_D_reg.regValue = IoReg_Read32(YUV2RGB_C_CORING_DATA_3_D_VADDR);
	c_coring_data_4_D_reg.regValue = IoReg_Read32(YUV2RGB_C_CORING_DATA_4_D_VADDR);
#endif

	if (Level > 10)
		Level = 10;

	if (display == 0) {/*main*/
		if (domain == 0) {/*main I_domain*/
			if (Level == 0) {
				c_coring_data_1_I_reg.i_m_enable = 0;
			} else {
				c_coring_data_1_I_reg.i_m_enable = 1;

				if (Level < 6) {
					c_coring_data_1_I_reg.i_m_threashold = 16;
					c_coring_data_1_I_reg.i_m_boundary = 8;
					c_coring_data_1_I_reg.i_m_mapping = 7-Level;

					c_coring_data_2_I_reg.i_m_slope0 = (c_coring_data_1_I_reg.i_m_mapping << 5)/c_coring_data_1_I_reg.i_m_boundary;
					c_coring_data_2_I_reg.i_m_slope1 = ((c_coring_data_1_I_reg.i_m_threashold - c_coring_data_1_I_reg.i_m_mapping) << 5)/(c_coring_data_1_I_reg.i_m_threashold - c_coring_data_1_I_reg.i_m_boundary);

				} else {
					Level -= 5;
					c_coring_data_1_I_reg.i_m_threashold = 32;
					c_coring_data_1_I_reg.i_m_boundary = 16;
					c_coring_data_1_I_reg.i_m_mapping = 16-Level*3;

					c_coring_data_2_I_reg.i_m_slope0 = (c_coring_data_1_I_reg.i_m_mapping << 5)/c_coring_data_1_I_reg.i_m_boundary;
					c_coring_data_2_I_reg.i_m_slope1 = ((c_coring_data_1_I_reg.i_m_threashold - c_coring_data_1_I_reg.i_m_mapping) << 5)/(c_coring_data_1_I_reg.i_m_threashold - c_coring_data_1_I_reg.i_m_boundary);
				}
			}

			IoReg_Write32(RGB2YUV_C_CORING_DATA_1_I_VADDR, c_coring_data_1_I_reg.regValue);
			IoReg_Write32(RGB2YUV_C_CORING_DATA_2_I_VADDR, c_coring_data_2_I_reg.regValue);
		}
#if 0
		else {/*main D_domain*/
			if (Level == 0) {
				c_coring_data_1_D_reg.d_m_enable = 0;
			} else {
				c_coring_data_1_D_reg.d_m_enable = 1;

				if (Level < 6) {
					c_coring_data_1_D_reg.d_m_threashold = 16;
					c_coring_data_1_D_reg.d_m_boundary = 8;
					c_coring_data_1_D_reg.d_m_mapping = 7-Level;

					c_coring_data_2_D_reg.d_m_slope0 = (c_coring_data_1_D_reg.d_m_mapping << 5)/c_coring_data_1_D_reg.d_m_boundary;
					c_coring_data_2_D_reg.d_m_slope1 = ((c_coring_data_1_D_reg.d_m_threashold - c_coring_data_1_D_reg.d_m_mapping) << 5)/(c_coring_data_1_D_reg.d_m_threashold - c_coring_data_1_D_reg.d_m_boundary);

				} else {
					Level -= 5;
					c_coring_data_1_D_reg.d_m_threashold = 32;
					c_coring_data_1_D_reg.d_m_boundary = 16;
					c_coring_data_1_D_reg.d_m_mapping = 16-Level*3;

					c_coring_data_2_D_reg.d_m_slope0 = (c_coring_data_1_D_reg.d_m_mapping << 5)/c_coring_data_1_D_reg.d_m_boundary;
					c_coring_data_2_D_reg.d_m_slope1 = ((c_coring_data_1_D_reg.d_m_threashold - c_coring_data_1_D_reg.d_m_mapping) << 5)/(c_coring_data_1_D_reg.d_m_threashold - c_coring_data_1_D_reg.d_m_boundary);
				}
			}

			IoReg_Write32(YUV2RGB_C_CORING_DATA_1_D_VADDR, c_coring_data_1_D_reg.regValue);
			IoReg_Write32(YUV2RGB_C_CORING_DATA_2_D_VADDR, c_coring_data_2_D_reg.regValue);
		}
#endif
	} else {/*sub*/
		if (domain == 0) {/*sub I_domain*/
			if (Level == 0) {
				c_coring_data_3_I_reg.i_s_enable = 0;
			} else {
				c_coring_data_3_I_reg.i_s_enable = 1;

				if (Level < 6) {
					c_coring_data_3_I_reg.i_s_threashold = 8;
					c_coring_data_3_I_reg.i_s_boundary = 4;
					c_coring_data_3_I_reg.i_s_mapping = 4-(Level+1)/2;

					c_coring_data_4_I_reg.i_s_slope0 = (c_coring_data_3_I_reg.i_s_mapping << 5)/c_coring_data_3_I_reg.i_s_boundary;
					c_coring_data_4_I_reg.i_s_slope1 = ((c_coring_data_3_I_reg.i_s_threashold - c_coring_data_3_I_reg.i_s_mapping) << 5)/(c_coring_data_3_I_reg.i_s_threashold - c_coring_data_3_I_reg.i_s_boundary);
				} else {
					Level -= 5;
					c_coring_data_3_I_reg.i_s_threashold = 16;
					c_coring_data_3_I_reg.i_s_boundary = 8;
					c_coring_data_3_I_reg.i_s_mapping = 7-Level;

					c_coring_data_4_I_reg.i_s_slope0 = (c_coring_data_3_I_reg.i_s_mapping << 5)/c_coring_data_3_I_reg.i_s_boundary;
					c_coring_data_4_I_reg.i_s_slope1 = ((c_coring_data_3_I_reg.i_s_threashold - c_coring_data_3_I_reg.i_s_mapping) << 5)/(c_coring_data_3_I_reg.i_s_threashold - c_coring_data_3_I_reg.i_s_boundary);
				}

			}

			IoReg_Write32(RGB2YUV_C_CORING_DATA_3_I_VADDR, c_coring_data_3_I_reg.regValue);
			IoReg_Write32(RGB2YUV_C_CORING_DATA_4_I_VADDR, c_coring_data_4_I_reg.regValue);
		}
#if 0
		else {/*sub D_domain*/

			if (Level == 0) {
				c_coring_data_3_D_reg.d_s_enable = 0;
			} else {
				c_coring_data_3_D_reg.d_s_enable = 1;

				if (Level < 6) {
					c_coring_data_3_D_reg.d_s_threashold = 8;
					c_coring_data_3_D_reg.d_s_boundary = 4;
					c_coring_data_3_D_reg.d_s_mapping = 4-(Level+1)/2;

					c_coring_data_4_D_reg.d_s_slope0 = (c_coring_data_3_D_reg.d_s_mapping << 5)/c_coring_data_3_D_reg.d_s_boundary;
					c_coring_data_4_D_reg.d_s_slope1 = ((c_coring_data_3_D_reg.d_s_threashold - c_coring_data_3_D_reg.d_s_mapping) << 5)/(c_coring_data_3_D_reg.d_s_threashold - c_coring_data_3_D_reg.d_s_boundary);
				} else {
					Level -= 5;
					c_coring_data_3_D_reg.d_s_threashold = 16;
					c_coring_data_3_D_reg.d_s_boundary = 8;
					c_coring_data_3_D_reg.d_s_mapping = 7-Level;

					c_coring_data_4_D_reg.d_s_slope0 = (c_coring_data_3_D_reg.d_s_mapping << 5)/c_coring_data_3_D_reg.d_s_boundary;
					c_coring_data_4_D_reg.d_s_slope1 = ((c_coring_data_3_D_reg.d_s_threashold - c_coring_data_3_D_reg.d_s_mapping) << 5)/(c_coring_data_3_D_reg.d_s_threashold - c_coring_data_3_D_reg.d_s_boundary);
				}


			}

			IoReg_Write32(YUV2RGB_C_CORING_DATA_3_D_VADDR, c_coring_data_3_D_reg.regValue);
			IoReg_Write32(YUV2RGB_C_CORING_DATA_4_D_VADDR, c_coring_data_4_D_reg.regValue);
		}
#endif
	}
#endif
}

/**
 *small-DCTI
 * @param < display> {main/sub display}
 * @param < Prevent_PE> {Phase Error Control}
 * @param < S_DCTI_Enable> {2nd DCTi Control}
 * @param < F_Gain> {First_Gain}
 * @param < F_th> {First_th}
 * @param < S_Gain> {Second_Gain}
 * @param < S_th> {Second_th}
 * @return {none}
 *
 */

unsigned char bNeedRestoreActWnd = FALSE;
UINT16 g_DispHSta, g_DispHEnd, g_DispVSta, g_DispVEnd;
UINT16 g_BgDispHSta = 0, g_BgDispHEnd = 0, g_BgDispVSta = 0, g_BgDispVEnd = 0;
void drvif_color_get_main_act_window(UINT16 *pDispHSta, UINT16 *pDispHEnd, UINT16 *pDispVSta, UINT16 *pDispVEnd)
{
	ppoverlay_main_active_h_start_end_RBUS main_active_h_start_end_reg;
	ppoverlay_main_active_v_start_end_RBUS main_active_v_start_end_reg;

	// Main Active H pos
	main_active_h_start_end_reg.regValue = IoReg_Read32(PPOVERLAY_MAIN_Active_H_Start_End_reg);
	*pDispHSta = main_active_h_start_end_reg.mh_act_sta - Get_DISP_ACT_STA_BIOS();
	*pDispHEnd = main_active_h_start_end_reg.mh_act_end - Get_DISP_ACT_STA_BIOS();

	// Main Active V pos
	main_active_v_start_end_reg.regValue = IoReg_Read32(PPOVERLAY_MAIN_Active_V_Start_End_reg);
	*pDispVSta = main_active_v_start_end_reg.mv_act_sta;
	*pDispVEnd = main_active_v_start_end_reg.mv_act_end;
}

UINT8 drvif_color_check_4k_input(void)
{

	unsigned short mode = Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_MODE_CURR);
	switch (mode)
	{
	case _MODE_4k2kI30:
	case _MODE_4k2kP30:
	case _MODE_4k2kP24:
	case _MODE_4k2kP25:
	case _MODE_4k2kP48:
	case _MODE_4k2kP50:
	case _MODE_4k2kP60:

		return 1;
		break;
	default:
		return 0;
		break;
	}

}

UINT8 g_bWBPattern_ForceBGSave = 0;
void drvif_color_set_WB_pattern_setup(void)
{
	ppoverlay_dh_den_start_end_RBUS dh_den_start_end_reg;
	scaleup_d_uzu_globle_ctrl_RBUS d_uzu_Globle_Ctrl_reg;
	scaleup_dm_uzu_ctrl_RBUS dm_uzu_Ctrl_reg;
	scaleup_d_uzu_patgen_frame_toggle_RBUS d_uzu_patgen_frame_toggle_reg;
	ppoverlay_main_display_control_rsv_RBUS main_display_control_rsv_reg;
	ppoverlay_main_background_h_start_end_RBUS main_background_h_start_end_reg;
	ppoverlay_main_background_v_start_end_RBUS main_background_v_start_end_reg;
	unsigned char check_size = 0;
	unsigned char bOnOff = TRUE;
	unsigned char ret;
	unsigned long flags;//for spin_lock_irqsave

	if (0 != (ret = Scaler_SendRPC(SCALERIOC_WB_MODE_FLAG, bOnOff, 1))){	//info video fw enter WB mode
		pr_err("ret=%d, SCALERIOC_WB_MODE_FLAG RPC fail !!!\n", ret);
	}

	dh_den_start_end_reg.regValue = rtd_inl(PPOVERLAY_DH_DEN_Start_End_reg);
	/*show pattern*/
	d_uzu_Globle_Ctrl_reg.regValue = rtd_inl(SCALEUP_D_UZU_Globle_Ctrl_reg);
	/*rtd_log(_LOGGER_INFO," SCALEUP_D_UZU_Globle_Ctrl_reg_in = %x\n", d_uzu_Globle_Ctrl_reg.regValue);*/

	main_display_control_rsv_reg.regValue = rtd_inl(PPOVERLAY_Main_Display_Control_RSV_reg);
	if (cDisplayStatusSave == -1)
		cDisplayStatusSave = main_display_control_rsv_reg.m_disp_en;
	if (bWD_status_backup == -1)
		bWD_status_backup = main_display_control_rsv_reg.main_wd_to_background;	//backup wd. KTASKWBS-4356



	main_background_h_start_end_reg.regValue = IoReg_Read32(PPOVERLAY_MAIN_Background_H_Start_End_reg);	//backup
	g_BgDispHSta = main_background_h_start_end_reg.mh_bg_sta;
	g_BgDispHEnd = main_background_h_start_end_reg.mh_bg_end;
	main_background_v_start_end_reg.regValue = IoReg_Read32(PPOVERLAY_MAIN_Background_V_Start_End_reg);
	g_BgDispVSta = main_background_v_start_end_reg.mv_bg_sta;
	g_BgDispVEnd = main_background_v_start_end_reg.mv_bg_end;


	if (d_uzu_Globle_Ctrl_reg.patgen_sel == 0) {
		fwif_color_WaitFor_SYNC_START_UZUDTG();
		down(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
		//main_display_control_rsv_reg.m_disp_en = 0;
		main_display_control_rsv_reg.m_force_bg = 1;
		rtd_outl(PPOVERLAY_Main_Display_Control_RSV_reg, main_display_control_rsv_reg.regValue);
		up(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
		drvif_color_get_main_act_window(&g_DispHSta, &g_DispHEnd, &g_DispVSta, &g_DispVEnd);
		//WaitFor_DEN_START();
		check_size = 1;
	}
	//fwif_color_WaitFor_DEN_STOP_UZUDTG();

	if (Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE) == _MODE_STATE_ACTIVE) {
		d_uzu_Globle_Ctrl_reg.patgen_sync = 1; /*fix USB JPEG recover fail issue, 150917*/
	} else {
		d_uzu_Globle_Ctrl_reg.patgen_sync = 0; /*fix no signal can't trigger  issue, 151002*/
	}

#if IRE_PATTERN_USE_3D_PTG
	d_uzu_Globle_Ctrl_reg.patgen_sel = 3;
#else
	d_uzu_Globle_Ctrl_reg.patgen_sel = 1;
#endif
	d_uzu_Globle_Ctrl_reg.patgen_mode = 4;
	/*d_uzu_Globle_Ctrl_reg.patgen_width = 100;*/
	/*rtd_log(_LOGGER_INFO," SCALEUP_D_UZU_Globle_Ctrl_reg_out = %x\n", d_uzu_Globle_Ctrl_reg.regValue);*/
	if (check_size == 0)
		fwif_color_WaitFor_SYNC_START_UZUDTG();
	rtd_outl(SCALEUP_D_UZU_Globle_Ctrl_reg, d_uzu_Globle_Ctrl_reg.regValue);


	if (check_size == 1) {
		if (g_DispHEnd != Get_DISP_ACT_END_HPOS() || g_DispVEnd != Get_DISP_ACT_END_VPOS()) {
			drvif_scalerdisplay_set_dbuffer_en(SLR_MAIN_DISPLAY, TRUE);

			unsigned short time_out = 0;
			ppoverlay_main_active_h_start_end_RBUS main_active_h_start_end_reg;
			ppoverlay_main_active_v_start_end_RBUS main_active_v_start_end_reg;
			UINT16 DispHSta = Get_DISP_ACT_STA_HPOS();
			UINT16 DispHEnd = Get_DISP_ACT_END_HPOS();
			UINT16 DispVSta = Get_DISP_ACT_STA_VPOS();
			UINT16 DispVEnd = Get_DISP_ACT_END_VPOS();

			DispHSta += Get_DISP_ACT_STA_BIOS();
			DispHEnd += Get_DISP_ACT_STA_BIOS();

			// Main Active H pos
			main_active_h_start_end_reg.regValue = IoReg_Read32(PPOVERLAY_MAIN_Active_H_Start_End_reg);
			main_active_h_start_end_reg.mh_act_sta = (DispHSta & 0x0fff);
			main_active_h_start_end_reg.mh_act_end = (DispHEnd & 0x0fff);
			IoReg_Write32(PPOVERLAY_MAIN_Active_H_Start_End_reg, main_active_h_start_end_reg.regValue);

			// Main Active V pos
			main_active_v_start_end_reg.regValue = IoReg_Read32(PPOVERLAY_MAIN_Active_V_Start_End_reg);
			main_active_v_start_end_reg.mv_act_sta = DispVSta & 0x0fff;
			main_active_v_start_end_reg.mv_act_end = DispVEnd & 0x0fff;
			IoReg_Write32(PPOVERLAY_MAIN_Active_V_Start_End_reg, main_active_v_start_end_reg.regValue);

			if(((IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL_reg)&_BIT2)>>2) == 1){
				down(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
				spin_lock_irqsave(get_DBreg_spinlock(SLR_MAIN_DISPLAY), flags);//lock double buffer spinlock
				IoReg_SetBits(PPOVERLAY_Double_Buffer_CTRL_reg, _BIT0);
				spin_unlock_irqrestore(get_DBreg_spinlock(SLR_MAIN_DISPLAY), flags);//unlock double buffer spinlock
				up(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
				while((IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL_reg)&_BIT0) && time_out < 10000){
					//msleep(1);
					time_out++;
				}
			}
			drvif_scalerdisplay_set_dbuffer_en(SLR_MAIN_DISPLAY, FALSE);
		}
		bNeedRestoreActWnd = TRUE;
	}

	dm_uzu_Ctrl_reg.regValue = rtd_inl(SCALEUP_DM_UZU_Ctrl_reg);
	dm_uzu_Ctrl_reg.in_fmt_conv = 0;
	rtd_outl(SCALEUP_DM_UZU_Ctrl_reg, dm_uzu_Ctrl_reg.regValue);

	d_uzu_patgen_frame_toggle_reg.regValue = rtd_inl(SCALEUP_D_UZU_PATGEN_FRAME_TOGGLE_reg);
	d_uzu_patgen_frame_toggle_reg.patgen_width = (dh_den_start_end_reg.dh_den_end-dh_den_start_end_reg.dh_den_sta)>>3;
	rtd_outl(SCALEUP_D_UZU_PATGEN_FRAME_TOGGLE_reg, d_uzu_patgen_frame_toggle_reg.regValue);

	/*20120817 roger, DISABLE force BG*/

	if (check_size == 1) {
		WaitFor_DEN_START();
		fwif_color_WaitFor_SYNC_START_UZUDTG();
	}
	down(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
	main_display_control_rsv_reg.m_disp_en = 1;
	main_display_control_rsv_reg.m_force_bg = 0;
	main_display_control_rsv_reg.main_wd_to_background = 0; //disable wd to always show WB to prevent mute by AV online measure status error. KTASKWBS-4356
	rtd_outl(PPOVERLAY_Main_Display_Control_RSV_reg, main_display_control_rsv_reg.regValue);
	spin_lock_irqsave(get_DBreg_spinlock(SLR_MAIN_DISPLAY), flags);//lock double buffer spinlock
	IoReg_SetBits(PPOVERLAY_Double_Buffer_CTRL_reg, _BIT0);//Aplly double buffer
	spin_unlock_irqrestore(get_DBreg_spinlock(SLR_MAIN_DISPLAY), flags);//unlock double buffer spinlock
	up(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
}
extern StructSrcRect main_dispwin;
void drvif_color_set_WB_pattern_off(unsigned char bForceBG, unsigned char b422Format)
{
	scaleup_d_uzu_globle_ctrl_RBUS d_uzu_Globle_Ctrl_reg;
	scaleup_dm_uzu_ctrl_RBUS dm_uzu_Ctrl_reg;
	ppoverlay_main_display_control_rsv_RBUS main_display_control_rsv_reg;
	UINT8 bIsOffAction = 0;
	ppoverlay_double_buffer_ctrl_RBUS ppoverlay_double_buffer_ctrl_Reg;
	unsigned int timeout=0x3fffff;
	unsigned char bOnOff = FALSE;
	unsigned char ret;
	unsigned long flags;//for spin_lock_irqsave
	down(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
	main_display_control_rsv_reg.regValue = rtd_inl(PPOVERLAY_Main_Display_Control_RSV_reg);
	if (cDisplayStatusSave != -1) {
		main_display_control_rsv_reg.m_disp_en = cDisplayStatusSave;
		cDisplayStatusSave = -1;
	}
	if ((Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE) != _MODE_STATE_ACTIVE)
		|| Check_AP_Set_Enable_ForceBG(SLR_MAIN_DISPLAY))
		main_display_control_rsv_reg.m_force_bg = 1;
	else
	{
		main_display_control_rsv_reg.m_force_bg = 0;
		if(bWD_status_backup!= -1){
			main_display_control_rsv_reg.main_wd_to_background = bWD_status_backup;	//recover wd. KTASKWBS-4356
		}
		bWD_status_backup = -1;
	}



	/*main_display_control_rsv_reg.main_wd_to_background = 0;*/
	rtd_outl(PPOVERLAY_Main_Display_Control_RSV_reg, main_display_control_rsv_reg.regValue);
	up(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
	do{
		ppoverlay_double_buffer_ctrl_Reg.regValue = IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL_reg);
	}while((ppoverlay_double_buffer_ctrl_Reg.dreg_dbuf_set==1) && (--timeout));


	fwif_color_WaitFor_SYNC_START_UZUDTG();

	if (bNeedRestoreActWnd) {
		unsigned short u16_output_region_act_window_x;
		unsigned short u16_output_region_act_window_y;
		unsigned short u16_output_region_act_window_wid;
		unsigned short u16_output_region_act_window_height;

		if(uc4_get_main_dispwin_value(&u16_output_region_act_window_x, &u16_output_region_act_window_y, &u16_output_region_act_window_wid, &u16_output_region_act_window_height) == 0 ) //success
		{
			scalerdisplay_set_main_act_window(u16_output_region_act_window_x, u16_output_region_act_window_x + u16_output_region_act_window_wid, u16_output_region_act_window_y,  u16_output_region_act_window_y + u16_output_region_act_window_height);
		}
		else	//fail
		{
			//can not recover act window
		}
	}

	//restore
	if(g_BgDispHSta + g_BgDispHEnd + g_BgDispVSta + g_BgDispVEnd)
	{
		ppoverlay_main_background_h_start_end_RBUS main_background_h_start_end_reg;
		ppoverlay_main_background_v_start_end_RBUS main_background_v_start_end_reg;
		main_background_h_start_end_reg.mh_bg_sta = g_BgDispHSta;
		main_background_h_start_end_reg.mh_bg_end = g_BgDispHEnd;
		IoReg_Write32(PPOVERLAY_MAIN_Background_H_Start_End_reg, main_background_h_start_end_reg.regValue);
		main_background_v_start_end_reg.mv_bg_sta = g_BgDispVSta;
		main_background_v_start_end_reg.mv_bg_end = g_BgDispVEnd;
		IoReg_Write32(PPOVERLAY_MAIN_Background_V_Start_End_reg, main_background_v_start_end_reg.regValue);
	}

	/*show pattern*/
	d_uzu_Globle_Ctrl_reg.regValue = rtd_inl(SCALEUP_D_UZU_Globle_Ctrl_reg);
	bIsOffAction = d_uzu_Globle_Ctrl_reg.patgen_sel?1:0;
	/*rtd_log(_LOGGER_INFO," SCALEUP_D_UZU_Globle_Ctrl_reg_in = %x\n", d_uzu_Globle_Ctrl_reg.regValue);*/
	d_uzu_Globle_Ctrl_reg.patgen_sel = 0;
	/*rtd_log(_LOGGER_INFO," SCALEUP_D_UZU_Globle_Ctrl_reg_out = %x\n", d_uzu_Globle_Ctrl_reg.regValue);*/
	rtd_outl(SCALEUP_D_UZU_Globle_Ctrl_reg, d_uzu_Globle_Ctrl_reg.regValue);

	dm_uzu_Ctrl_reg.regValue = rtd_inl(SCALEUP_DM_UZU_Ctrl_reg);
	dm_uzu_Ctrl_reg.in_fmt_conv = b422Format ? 1 : 0;
	rtd_outl(SCALEUP_DM_UZU_Ctrl_reg, dm_uzu_Ctrl_reg.regValue);

	down(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
	spin_lock_irqsave(get_DBreg_spinlock(SLR_MAIN_DISPLAY), flags);//lock double buffer spinlock
	IoReg_SetBits(PPOVERLAY_Double_Buffer_CTRL_reg, _BIT0);//Apply double buffer
	spin_unlock_irqrestore(get_DBreg_spinlock(SLR_MAIN_DISPLAY), flags);//unlock double buffer spinlock
	up(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/

	if (0 != (ret = Scaler_SendRPC(SCALERIOC_WB_MODE_FLAG, bOnOff, 1))){	//info video fw enter WB mode
		pr_err("ret=%d, SCALERIOC_WB_MODE_FLAG RPC fail !!!\n", ret);
	}


	bNeedRestoreActWnd = FALSE;
	g_bWBPattern_ForceBGSave = 0;
}

#if IRE_PATTERN_USE_3D_PTG
void drvif_color_set_WB_pattern_RGB(unsigned char R, unsigned char G, unsigned char B)
{
	scaleup_left_3d_ptg_ctrl3_RBUS left_3d_ptg_ctrl3_reg;
	scaleup_left_3d_ptg_ctrl5_RBUS left_3d_ptg_ctrl5_reg;
	scaleup_right_3d_ptg_ctrl1_RBUS right_3d_ptg_ctrl1_reg;
	scaleup_right_3d_ptg_ctrl3_RBUS right_3d_ptg_ctrl3_reg;
	scaleup_ptg_3d_ctr1_RBUS ptg_3d_ctr1_reg;

	left_3d_ptg_ctrl5_reg.regValue = rtd_inl(SCALEUP_LEFT_3D_PTG_Ctrl5_reg);
	right_3d_ptg_ctrl3_reg.regValue = rtd_inl(SCALEUP_RIGHT_3D_PTG_Ctrl3_reg);

	left_3d_ptg_ctrl5_reg.left_hsize = 1;
	left_3d_ptg_ctrl5_reg.left_vsize = 1;
	left_3d_ptg_ctrl5_reg.see_sadr_only_l = 1;
	right_3d_ptg_ctrl3_reg.right_hsize = 1;
	right_3d_ptg_ctrl3_reg.right_vsize = 1;
	right_3d_ptg_ctrl3_reg.see_sadr_only_r = 1;

	rtd_outl(SCALEUP_LEFT_3D_PTG_Ctrl5_reg, left_3d_ptg_ctrl5_reg.regValue);
	rtd_outl(SCALEUP_RIGHT_3D_PTG_Ctrl3_reg, left_3d_ptg_ctrl5_reg.regValue);

	fwif_color_WaitFor_SYNC_START_UZUDTG();

	left_3d_ptg_ctrl3_reg.left_ydi = right_3d_ptg_ctrl1_reg.right_ydi = ptg_3d_ctr1_reg.ptg_bg_ydi = G;
	left_3d_ptg_ctrl3_reg.left_udi = right_3d_ptg_ctrl1_reg.right_udi = ptg_3d_ctr1_reg.ptg_bg_udi = B;
	left_3d_ptg_ctrl3_reg.left_vdi = right_3d_ptg_ctrl1_reg.right_vdi = ptg_3d_ctr1_reg.ptg_bg_vdi = R;
	left_3d_ptg_ctrl3_reg.res1 = right_3d_ptg_ctrl1_reg.res1 = ptg_3d_ctr1_reg.res1 = 0;

	rtd_outl(SCALEUP_LEFT_3D_PTG_Ctrl3_reg, left_3d_ptg_ctrl3_reg.regValue);
	rtd_outl(SCALEUP_RIGHT_3D_PTG_Ctrl1_reg, right_3d_ptg_ctrl1_reg.regValue);
	rtd_outl(SCALEUP_PTG_3D_Ctr1_reg, ptg_3d_ctr1_reg.regValue);
}
#else
void drvif_color_set_WB_pattern_RGB(unsigned char R, unsigned char G, unsigned char B)
{
	fwif_color_WaitFor_SYNC_START_UZUDTG();
	/*adjust the YCbCr0*/
	{
	scaleup_d_uzu_patgen_color0_RBUS d_uzu_PATGEN_COLOR0_reg;
	d_uzu_PATGEN_COLOR0_reg.regValue = rtd_inl(SCALEUP_D_UZU_PATGEN_COLOR0_reg);
	/*rtd_log(_LOGGER_INFO," SCALEUP_D_UZU_PATGEN_COLOR0_reg_in = %x\n", d_uzu_PATGEN_COLOR0_reg.regValue);*/
	d_uzu_PATGEN_COLOR0_reg.patgen_c0_y = G;
	d_uzu_PATGEN_COLOR0_reg.patgen_c0_cr = R;
	d_uzu_PATGEN_COLOR0_reg.patgen_c0_cb = B;

	/*rtd_log(_LOGGER_INFO," SCALEUP_D_UZU_PATGEN_COLOR0_reg_out = %x\n", d_uzu_PATGEN_COLOR0_reg.regValue);*/
	rtd_outl(SCALEUP_D_UZU_PATGEN_COLOR0_reg, d_uzu_PATGEN_COLOR0_reg.regValue);
	}

	/*adjust the YCbCr1*/
	{
	scaleup_d_uzu_patgen_color1_RBUS d_uzu_PATGEN_COLOR1_reg;
	d_uzu_PATGEN_COLOR1_reg.regValue = rtd_inl(SCALEUP_D_UZU_PATGEN_COLOR1_reg);
	/*rtd_log(_LOGGER_INFO," SCALEUP_D_UZU_PATGEN_COLOR1_reg_in = %x\n", d_uzu_PATGEN_COLOR1_reg.regValue);*/
	d_uzu_PATGEN_COLOR1_reg.patgen_c1_y = G;
	d_uzu_PATGEN_COLOR1_reg.patgen_c1_cr = R;
	d_uzu_PATGEN_COLOR1_reg.patgen_c1_cb = B;
	/*rtd_log(_LOGGER_INFO," SCALEUP_D_UZU_PATGEN_COLOR1_reg_out = %x\n", d_uzu_PATGEN_COLOR1_reg.regValue);*/
	rtd_outl(SCALEUP_D_UZU_PATGEN_COLOR1_reg, d_uzu_PATGEN_COLOR1_reg.regValue);
	}

	/*adjust the YCbCr2*/
	{
	scaleup_d_uzu_patgen_color2_RBUS d_uzu_PATGEN_COLOR2_reg;
	d_uzu_PATGEN_COLOR2_reg.regValue = rtd_inl(SCALEUP_D_UZU_PATGEN_COLOR2_reg);
	/*rtd_log(_LOGGER_INFO," SCALEUP_D_UZU_PATGEN_COLOR2_reg_in = %x\n", d_uzu_PATGEN_COLOR2_reg.regValue);*/
	d_uzu_PATGEN_COLOR2_reg.patgen_c2_y = G;
	d_uzu_PATGEN_COLOR2_reg.patgen_c2_cr = R;
	d_uzu_PATGEN_COLOR2_reg.patgen_c2_cb = B;
	/*rtd_log(_LOGGER_INFO," SCALEUP_D_UZU_PATGEN_COLOR2_reg_out = %x\n", d_uzu_PATGEN_COLOR2_reg.regValue);*/
	rtd_outl(SCALEUP_D_UZU_PATGEN_COLOR2_reg, d_uzu_PATGEN_COLOR2_reg.regValue);
	}

	/*adjust the YCbCr3*/
	{
	scaleup_d_uzu_patgen_color3_RBUS d_uzu_PATGEN_COLOR3_reg;
	d_uzu_PATGEN_COLOR3_reg.regValue = rtd_inl(SCALEUP_D_UZU_PATGEN_COLOR3_reg);
	/*rtd_log(_LOGGER_INFO," SCALEUP_D_UZU_PATGEN_COLOR3_reg_in = %x\n", d_uzu_PATGEN_COLOR3_reg.regValue);*/
	d_uzu_PATGEN_COLOR3_reg.patgen_c3_y = G;
	d_uzu_PATGEN_COLOR3_reg.patgen_c3_cr = R;
	d_uzu_PATGEN_COLOR3_reg.patgen_c3_cb = B;
	/*rtd_log(_LOGGER_INFO," SCALEUP_D_UZU_PATGEN_COLOR3_reg_out = %x\n", d_uzu_PATGEN_COLOR3_reg.regValue);*/
	rtd_outl(SCALEUP_D_UZU_PATGEN_COLOR3_reg, d_uzu_PATGEN_COLOR3_reg.regValue);
	}
}
#endif
unsigned char drvif_color_get_WB_pattern_on(void)
{
	scaleup_d_uzu_globle_ctrl_RBUS d_uzu_Globle_Ctrl_reg;
	d_uzu_Globle_Ctrl_reg.regValue = rtd_inl(SCALEUP_D_UZU_Globle_Ctrl_reg);
	return d_uzu_Globle_Ctrl_reg.patgen_sel;
}

#if 0
void drvif_color_set_Gamma_pattern_setup(unsigned char display, unsigned short R, unsigned short G, unsigned short B)
{
	unsigned char i;
	unsigned int gammaMatrixR[128], gammaMatrixG[128], gammaMatrixB[128];
	gamma_gamma_ctrl_1_RBUS gamma_ctrl_1_REG;
	gamma_gamma_ctrl_2_RBUS gamma_ctrl_2_REG;
	gamma_ctrl_1_REG.regValue = IoReg_Read32(GAMMA_GAMMA_CTRL_1_reg);
	gamma_ctrl_2_REG.regValue = IoReg_Read32(GAMMA_GAMMA_CTRL_2_reg);

	if (display	== SLR_MAIN_DISPLAY) {
		gamma_ctrl_1_REG.gamma_ax_type_sel = _Gamma_Full;
		gamma_ctrl_1_REG.res1 = 0; /* reserved*/
		gamma_ctrl_1_REG.gamma_ax_rw_sel = 1; /* writing table*/

	}

	for (i = 0; i < 128; i++) {
		gammaMatrixR[i] = (R << 16);
		gammaMatrixG[i] = (G << 16);
		gammaMatrixB[i] = (B << 16);
	}

	gamma_ctrl_1_REG.gamma_ax_ch_sel = 0;
	IoReg_Write32(GAMMA_GAMMA_CTRL_1_reg, gamma_ctrl_1_REG.regValue);
	drvif_color_colorwritegamma(&gammaMatrixR[0]);
	gamma_ctrl_1_REG.gamma_ax_ch_sel = 1;
	IoReg_Write32(GAMMA_GAMMA_CTRL_1_reg, gamma_ctrl_1_REG.regValue);
	drvif_color_colorwritegamma(&gammaMatrixG[0]);
	gamma_ctrl_1_REG.gamma_ax_ch_sel = 2;
	IoReg_Write32(GAMMA_GAMMA_CTRL_1_reg, gamma_ctrl_1_REG.regValue);
	drvif_color_colorwritegamma(&gammaMatrixB[0]);

	gamma_ctrl_1_REG.gamma_ax_rw_sel = 0; /* writing table*/
	gamma_ctrl_2_REG.gamma_m_tab_sel = 1; /* use tab-1*/


	IoReg_Write32(GAMMA_GAMMA_CTRL_1_reg, gamma_ctrl_1_REG.regValue);
	IoReg_Write32(GAMMA_GAMMA_CTRL_2_reg, gamma_ctrl_2_REG.regValue);

}

void drvif_color_set_Gamma_pattern_off(unsigned char display, unsigned int *pArrayGammaR, unsigned int *pArrayGammaG, unsigned int *pArrayGammaB)
{
	/*unsigned char i;*/
	/*static unsigned int *gammaMatrixR, *gammaMatrixG, *gammaMatrixB;*/
	gamma_gamma_ctrl_1_RBUS gamma_ctrl_1_REG;
	gamma_gamma_ctrl_2_RBUS gamma_ctrl_2_REG;
	gamma_ctrl_1_REG.regValue = IoReg_Read32(GAMMA_GAMMA_CTRL_1_reg);
	gamma_ctrl_2_REG.regValue = IoReg_Read32(GAMMA_GAMMA_CTRL_2_reg);

	if (display	== SLR_MAIN_DISPLAY) {
		/*gamma_ctrl_1_REG.gamma_ax_type_sel = _Gamma_Full;*/
		gamma_ctrl_1_REG.res1 = 0; /* reserved*/
		gamma_ctrl_1_REG.gamma_ax_rw_sel = 1; /* writing table*/

	}

	/*gammaMatrixR = tGAMMA_1_R;*/
	/*gammaMatrixR = tGAMMA_1_G;*/
	/*gammaMatrixB = tGAMMA_1_B;*/

	gamma_ctrl_1_REG.gamma_ax_ch_sel = 0;
	IoReg_Write32(GAMMA_GAMMA_CTRL_1_reg, gamma_ctrl_1_REG.regValue);
	drvif_color_colorwritegamma(pArrayGammaR);
	gamma_ctrl_1_REG.gamma_ax_ch_sel = 1;
	IoReg_Write32(GAMMA_GAMMA_CTRL_1_reg, gamma_ctrl_1_REG.regValue);
	drvif_color_colorwritegamma(pArrayGammaG);
	gamma_ctrl_1_REG.gamma_ax_ch_sel = 2;
	IoReg_Write32(GAMMA_GAMMA_CTRL_1_reg, gamma_ctrl_1_REG.regValue);
	drvif_color_colorwritegamma(pArrayGammaB);

	gamma_ctrl_1_REG.gamma_ax_rw_sel = 0; /* writing table*/
	gamma_ctrl_2_REG.gamma_m_tab_sel = 1; /* use tab-1*/

	IoReg_Write32(GAMMA_GAMMA_CTRL_1_reg, gamma_ctrl_1_REG.regValue);
	IoReg_Write32(GAMMA_GAMMA_CTRL_2_reg, gamma_ctrl_2_REG.regValue);

}
#endif
/*
#define byPass_Num 13
void drvif_color_set_PQ_byPass(unsigned char display, unsigned char flag)
{
	static unsigned char status_ch[byPass_Num]={0};
	static unsigned char bit_ch[byPass_Num]={0, 26, 0, 31, 0, 0, 0, 16, 4, 24, 28, 8, 28};
	static unsigned int addr_ch[byPass_Num]={0xb8025100, 0xb8023100, 0xb8023170, 0xb8023118, 0xb8023118, 0xb80231f8, 0xb802a034, 0xb8029038, 0xb8029040,
		 0xb80290c4, 0xb802a588, 0xb802aa00, 0xb802aa14};

	if (flag == 1)
	{

	}
	else
	{
	}
}
*/

void drvif_color_set_YUV2RGB_byPass(unsigned char display, unsigned char flag)
{
	static unsigned short *table_index;

	unsigned short buffer_status_count = 0;
	yuv2rgb_d_yuv2rgb_control_RBUS d_yuv2rgb_control_REG;
	yuv2rgb_d_yuv2rgb_control_1_RBUS d_yuv2rgb_control_1_reg;

	yuv2rgb_d_yuv2rgb_tab1_data_clamp_RBUS yuv2rgb_d_yuv2rgb_tab1_data_clamp_REG;
	yuv2rgb_d_yuv2rgb_tab1_data_0_RBUS yuv2rgb_d_yuv2rgb_tab1_data_0_REG;
	yuv2rgb_d_yuv2rgb_tab1_data_1_RBUS yuv2rgb_d_yuv2rgb_tab1_data_1_REG;
	yuv2rgb_d_yuv2rgb_tab1_data_2_RBUS yuv2rgb_d_yuv2rgb_tab1_data_2_REG;
	yuv2rgb_d_yuv2rgb_tab1_data_3_RBUS yuv2rgb_d_yuv2rgb_tab1_data_3_REG;
	yuv2rgb_d_yuv2rgb_tab1_data_4_RBUS yuv2rgb_d_yuv2rgb_tab1_data_4_REG;
	yuv2rgb_d_yuv2rgb_tab1_data_5_RBUS yuv2rgb_d_yuv2rgb_tab1_data_5_REG;
	yuv2rgb_d_yuv2rgb_tab1_data_6_RBUS yuv2rgb_d_yuv2rgb_tab1_data_6_REG;

	d_yuv2rgb_control_1_reg.regValue = IoReg_Read32(YUV2RGB_D_YUV2RGB_Control_reg);

	d_yuv2rgb_control_REG.regValue = IoReg_Read32(YUV2RGB_D_YUV2RGB_Control_reg);
	d_yuv2rgb_control_REG.yuv2rgb_main_en = 0;
	/*d_yuv2rgb_control_REG.yuv2rgb_main_tab_sel = 0;*/
	IoReg_Write32(YUV2RGB_D_YUV2RGB_Control_reg, d_yuv2rgb_control_REG.regValue);

	if (flag == 1)
		table_index = tYUV2RGB_COEF_601_YCbCr_limit2full_range;
	else
		table_index = tYUV2RGB_COEF_601_YCbCr;

	yuv2rgb_d_yuv2rgb_tab1_data_clamp_REG.y_clamp = table_index[_YUV2RGB_Y_Clamp];
	yuv2rgb_d_yuv2rgb_tab1_data_clamp_REG.cb_cr_clamp = table_index[_YUV2RGB_UV_Clamp];
	IoReg_Write32(YUV2RGB_D_YUV2RGB_Tab1_Data_Clamp_reg, yuv2rgb_d_yuv2rgb_tab1_data_clamp_REG.regValue);

	yuv2rgb_d_yuv2rgb_tab1_data_0_REG.k11 = table_index[_YUV2RGB_k11];
	yuv2rgb_d_yuv2rgb_tab1_data_0_REG.k12 = table_index[_YUV2RGB_k12];

	/*USER: Vincent_Lee  DATE: 2011/8/26  TODO: Add YUV2RGB_tab1 buffer*/
	yuv2rgb_tab1_data0_buffer.regValue = yuv2rgb_d_yuv2rgb_tab1_data_0_REG.regValue;
	IoReg_Write32(YUV2RGB_D_YUV2RGB_Tab1_Data_0_reg, yuv2rgb_tab1_data0_buffer.regValue);

	yuv2rgb_d_yuv2rgb_tab1_data_1_REG.k13 = table_index[_YUV2RGB_k13];
	IoReg_Write32(YUV2RGB_D_YUV2RGB_Tab1_Data_1_reg, yuv2rgb_d_yuv2rgb_tab1_data_1_REG.regValue);

	yuv2rgb_d_yuv2rgb_tab1_data_2_REG.k22 = table_index[_YUV2RGB_k23];
	yuv2rgb_d_yuv2rgb_tab1_data_2_REG.k23 = table_index[_YUV2RGB_k32];
	IoReg_Write32(YUV2RGB_D_YUV2RGB_Tab1_Data_2_reg, yuv2rgb_d_yuv2rgb_tab1_data_2_REG.regValue);

	yuv2rgb_d_yuv2rgb_tab1_data_3_REG.k32 = table_index[_YUV2RGB_k32];
	yuv2rgb_d_yuv2rgb_tab1_data_3_REG.k33 = table_index[_YUV2RGB_k33];
	IoReg_Write32(YUV2RGB_D_YUV2RGB_Tab1_Data_3_reg, yuv2rgb_d_yuv2rgb_tab1_data_3_REG.regValue);


	yuv2rgb_d_yuv2rgb_tab1_data_4_REG.roffset = table_index[_YUV2RGB_Roffset] << 2;
	IoReg_Write32(YUV2RGB_D_YUV2RGB_Tab1_Data_4_reg, yuv2rgb_d_yuv2rgb_tab1_data_4_REG.regValue);

	yuv2rgb_d_yuv2rgb_tab1_data_5_REG.goffset = table_index[_YUV2RGB_Goffset] << 2;
	IoReg_Write32(YUV2RGB_D_YUV2RGB_Tab1_Data_5_reg, yuv2rgb_d_yuv2rgb_tab1_data_5_REG.regValue);

	yuv2rgb_d_yuv2rgb_tab1_data_6_REG.boffset = table_index[_YUV2RGB_Boffset] << 2;
	IoReg_Write32(YUV2RGB_D_YUV2RGB_Tab1_Data_6_reg, yuv2rgb_d_yuv2rgb_tab1_data_6_REG.regValue);

	d_yuv2rgb_control_REG.yuv2rgb_main_en = 1;
	/*d_yuv2rgb_control_REG.yuv2rgb_main_tab_sel = 0;*/
	IoReg_Write32(YUV2RGB_D_YUV2RGB_Control_reg, d_yuv2rgb_control_REG.regValue);
	/*======== planck add for update Brightness and contrast double buffer reg.20100823 ===============*/
	d_yuv2rgb_control_1_reg.yuv2rgb_db_apply = 1;  /* 20100811, double buffer en , csfanchiang*/
	IoReg_Write32(YUV2RGB_D_YUV2RGB_Control_1_reg, d_yuv2rgb_control_1_reg.regValue);
	/*======================================================================*/
	/*VIPprintf("$$$check YUV2RGB double buffer buffer_status =%d!!\n", d_yuv2rgb_control_1_reg.yuv2rgb_db_apply);*/
	/*WaitFor_DEN_STOP();*/
	do {/* check double buffer status complete*/
		d_yuv2rgb_control_1_reg.regValue = IoReg_Read32(YUV2RGB_D_YUV2RGB_Control_1_reg);
		/*VIPprintf("@@@@buffer_status_count =%d, double_buffer_reg =%d\n", buffer_status_count, d_yuv2rgb_control_REG.yuv2rgb_db_apply);*/
		buffer_status_count++;
	} while (d_yuv2rgb_control_1_reg.yuv2rgb_db_apply != 0 && buffer_status_count < 300);
	/*VIPprintf("$$$check YUV2RGB double buffer buffer_status =%d,%d!!\n", d_yuv2rgb_control_1_reg.yuv2rgb_db_apply, buffer_status_count);*/

}

/*#endif*/
/*
void drvif_color_idcti_set(unsigned char display, unsigned char Prevent_PE,  unsigned char F_Gain, unsigned char F_th, unsigned char S_DCTI_Enable, unsigned char S_Gain, unsigned char S_Th)
{
	if (display == SLR_MAIN_DISPLAY)
	{
		ich1_dcti_1st_value_RBUS ich1_dcti_1st_value_reg;
		ich1_dcti_1st_value_reg.gain_value = F_Gain;
		ich1_dcti_1st_value_reg.th_value = F_th;
		IoReg_Write32(PEAKING_ICH1_DCTI_1ST_VALUE_VADDR, ich1_dcti_1st_value_reg.regValue);

		ich1_dcti_2nd_value_RBUS ich1_dcti_2nd_value_reg;
		ich1_dcti_2nd_value_reg.gain_value = S_Gain;
		ich1_dcti_2nd_value_reg.th_value = S_Th;
		IoReg_Write32(PEAKING_ICH1_DCTI_2ND_VALUE_VADDR, ich1_dcti_2nd_value_reg.regValue);


		ich1_dcti_options_RBUS ich1_dcti_options_reg;
		ich1_dcti_options_reg.enabled = S_DCTI_Enable;
		ich1_dcti_options_reg.prevent_pe = Prevent_PE;
		IoReg_Write32(PEAKING_ICH1_DCTI_OPTIONS_VADDR, ich1_dcti_options_reg.regValue);
	}

}
*/
/**
 * ColorSetC I-DCTI
 * Set I-DCTI of C path
 *
 * @param < display> {ch1/ch2 display}
 * @param < Level> {Level control 0~11, 0:0ff, 1~10 = level}
 */


/**
*	Set I-Digital Filtering
*	(refer to Monitor's firmware)
* 	only vga and ypbpr need to set digital filter
*
*	@param < display> {ch1/ch2 display}
**/

/**
 * ColorSetC I-DCTI
 * Set I-DCTI of C path
 *
 * @param < display> {ch1/ch2 display}
 * @param < Level> {Level control 0~10, 0:0ff, 1~9 = level}
 */

/* JZ for Mac3 i-domain dcti*/
void drvif_color_inewdcti_table(DRV_VipNewIDcti_Table *ptr)
{
	if (!ptr)
		return;

/*Ctl1*/
	{
	idcti_i_dcti_ctrl_1_RBUS ich1_newdcti_reg_1;
	ich1_newdcti_reg_1.regValue = IoReg_Read32(IDCTI_I_DCTI_CTRL_1_reg);

	ich1_newdcti_reg_1.data_sel = ptr->VipNewIDcti_ctl1.data_sel;
	ich1_newdcti_reg_1.maxlen = ptr->VipNewIDcti_ctl1.maxlen;
	ich1_newdcti_reg_1.psmth = ptr->VipNewIDcti_ctl1.psmth;
	ich1_newdcti_reg_1.lp_mode = ptr->VipNewIDcti_ctl1.lp_mode;
	ich1_newdcti_reg_1.engdiv = ptr->VipNewIDcti_ctl1.engdiv;
	ich1_newdcti_reg_1.offdiv = ptr->VipNewIDcti_ctl1.offdiv;
	ich1_newdcti_reg_1.uvgain = ptr->VipNewIDcti_ctl1.uvgain;
	ich1_newdcti_reg_1.dcti_mode = ptr->VipNewIDcti_ctl1.dcti_mode;
	ich1_newdcti_reg_1.uvalign_en = ptr->VipNewIDcti_ctl1.uvalign_en;
	ich1_newdcti_reg_1.cur_sel = ptr->VipNewIDcti_ctl1.cur_sel;
	ich1_newdcti_reg_1.dcti_en = ptr->VipNewIDcti_ctl1.dcti_en;

	IoReg_Write32(IDCTI_I_DCTI_CTRL_1_reg, ich1_newdcti_reg_1.regValue);
	}
/*Ctl2*/
	{
	idcti_i_dcti_ctrl_2_RBUS ich1_newdcti_reg_2;
	ich1_newdcti_reg_2.regValue = IoReg_Read32(IDCTI_I_DCTI_CTRL_2_reg);

	ich1_newdcti_reg_2.uvsync_en = ptr->VipNewIDcti_ctl2.uvsync_en;
	ich1_newdcti_reg_2.tran_mode = ptr->VipNewIDcti_ctl2.tran_mode;
	ich1_newdcti_reg_2.rate_steep = ptr->VipNewIDcti_ctl2.rate_steep;
	ich1_newdcti_reg_2.th_steep = ptr->VipNewIDcti_ctl2.th_steep;
	ich1_newdcti_reg_2.th_coring = ptr->VipNewIDcti_ctl2.th_coring;
	ich1_newdcti_reg_2.steep_mode = ptr->VipNewIDcti_ctl2.steep_mode;
	ich1_newdcti_reg_2.hp_mode = ptr->VipNewIDcti_ctl2.hp_mode;
	ich1_newdcti_reg_2.vlp_mode = ptr->VipNewIDcti_ctl2.vlp_mode;
	ich1_newdcti_reg_2.median_mode = ptr->VipNewIDcti_ctl2.median_mode;
	ich1_newdcti_reg_2.blending_mode = ptr->VipNewIDcti_ctl2.blending_mode;

	IoReg_Write32(IDCTI_I_DCTI_CTRL_2_reg, ich1_newdcti_reg_2.regValue);
	}
/*Ctl3*/
	{
	idcti_i_dcti_ctrl_3_RBUS ich1_newdcti_reg_3;
	ich1_newdcti_reg_3.regValue = IoReg_Read32(IDCTI_I_DCTI_CTRL_3_reg);

	ich1_newdcti_reg_3.maxminlen = ptr->VipNewIDcti_ctl3.maxminlen;
	ich1_newdcti_reg_3.rate_tran = ptr->VipNewIDcti_ctl3.rate_tran;
	ich1_newdcti_reg_3.th_tran = ptr->VipNewIDcti_ctl3.th_tran;
	ich1_newdcti_reg_3.region_mode = ptr->VipNewIDcti_ctl3.region_mode;
	ich1_newdcti_reg_3.rate_smooth = ptr->VipNewIDcti_ctl3.rate_smooth;
	ich1_newdcti_reg_3.th_smooth = ptr->VipNewIDcti_ctl3.th_smooth;

	IoReg_Write32(IDCTI_I_DCTI_CTRL_3_reg, ich1_newdcti_reg_3.regValue);
	}
/*Ctl4*/
	{
	idcti_i_dcti_ctrl_4_RBUS ich1_newdcti_reg_4;
	ich1_newdcti_reg_4.regValue = IoReg_Read32(IDCTI_I_DCTI_CTRL_4_reg);

	ich1_newdcti_reg_4.rate_align_weight = ptr->VipNewIDcti_ctl4.rate_align_weight;
	ich1_newdcti_reg_4.rate_align = ptr->VipNewIDcti_ctl4.rate_align;
	ich1_newdcti_reg_4.th_align = ptr->VipNewIDcti_ctl4.th_align;
	ich1_newdcti_reg_4.align_mingain = ptr->VipNewIDcti_ctl4.align_mingain;
	ich1_newdcti_reg_4.th_gtran = ptr->VipNewIDcti_ctl4.th_gtran;

	IoReg_Write32(IDCTI_I_DCTI_CTRL_4_reg, ich1_newdcti_reg_4.regValue);
	}
/*Ctl5*/
	{
	idcti_i_dcti_ctrl_5_RBUS ich1_newdcti_reg_5;
	ich1_newdcti_reg_5.regValue = IoReg_Read32(IDCTI_I_DCTI_CTRL_5_reg);

	ich1_newdcti_reg_5.statistic_en = ptr->VipNewIDcti_ctl5.statistic_en;
	ich1_newdcti_reg_5.th_uvmindiff = ptr->VipNewIDcti_ctl5.th_uvmindiff;
	ich1_newdcti_reg_5.rate_stair2 = ptr->VipNewIDcti_ctl5.rate_stair2;
	ich1_newdcti_reg_5.rate_stair1 = ptr->VipNewIDcti_ctl5.rate_stair1;
	ich1_newdcti_reg_5.th_stair = ptr->VipNewIDcti_ctl5.th_stair;
	ich1_newdcti_reg_5.th_align_weight = ptr->VipNewIDcti_ctl5.th_align_weight;

	IoReg_Write32(IDCTI_I_DCTI_CTRL_5_reg, ich1_newdcti_reg_5.regValue);
	}
/*Ctl6*/
	{
	idcti_i_dcti_ctrl_6_RBUS ich1_newdcti_reg_6;
	ich1_newdcti_reg_6.regValue = IoReg_Read32(IDCTI_I_DCTI_CTRL_6_reg);

	ich1_newdcti_reg_6.statistic_hist = ptr->VipNewIDcti_ctl6.statistic_hist;
	ich1_newdcti_reg_6.rate_engsync = ptr->VipNewIDcti_ctl6.rate_engsync;
	ich1_newdcti_reg_6.rate_uvmindiff = ptr->VipNewIDcti_ctl6.rate_uvmindiff;
	ich1_newdcti_reg_6.th_engsync = ptr->VipNewIDcti_ctl6.th_engsync;

	IoReg_Write32(IDCTI_I_DCTI_CTRL_6_reg, ich1_newdcti_reg_6.regValue);
	}
/*Ctl7*/
	{
	idcti_i_dcti_ctrl_7_RBUS ich1_newdcti_reg_7;
	ich1_newdcti_reg_7.regValue = IoReg_Read32(IDCTI_I_DCTI_CTRL_7_reg);

	ich1_newdcti_reg_7.debug_shiftbit = ptr->VipNewIDcti_ctl7.debug_shiftbit;
	ich1_newdcti_reg_7.debug_mode = ptr->VipNewIDcti_ctl7.debug_mode;
	ich1_newdcti_reg_7.high_bound = ptr->VipNewIDcti_ctl7.high_bound;
	ich1_newdcti_reg_7.low_bound = ptr->VipNewIDcti_ctl7.low_bound;

	IoReg_Write32(IDCTI_I_DCTI_CTRL_7_reg, ich1_newdcti_reg_7.regValue);
	}
}


void drvif_color_digital_filter_set(unsigned char Access, unsigned char Offset, unsigned char Div, unsigned char Enable, SCALER_DISP_CHANNEL Display)
{

	if (Display == SLR_MAIN_DISPLAY) {
		dfilter_ich1_dfilter_ph_smr_pring_RBUS ich1_dfilter_ph_smr_pring_reg ;
		dfilter_ich1_dfilter_nring_mis_nos_ypbpr_RBUS ich1_dfilter_nring_mis_nos_ypbpr_reg ;

		ich1_dfilter_ph_smr_pring_reg.regValue = IoReg_Read32(DFILTER_ICH1_DFILTER_PH_SMR_PRING_reg);
		ich1_dfilter_nring_mis_nos_ypbpr_reg.regValue = IoReg_Read32(DFILTER_ICH1_DFILTER_NRING_MIS_NOS_YPBPR_reg);

		switch (Access) {
		case _YPBPR_ACCESS_PORT:
			ich1_dfilter_nring_mis_nos_ypbpr_reg.ch1_y_en = 0x1;
			ich1_dfilter_nring_mis_nos_ypbpr_reg.ch1_pb_en = 0x1;
			ich1_dfilter_nring_mis_nos_ypbpr_reg.ch1_pr_en = 0x1;
			break;
		case _PHASE_ACCESS_PORT:
			ich1_dfilter_ph_smr_pring_reg.ch1_ph_en = Enable;
			ich1_dfilter_ph_smr_pring_reg.ch1_thd_ph = Offset;
			ich1_dfilter_ph_smr_pring_reg.ch1_ph_div = Div;
			break;
		case _NEG_SMEAR_ACCESS_PORT:
			ich1_dfilter_ph_smr_pring_reg.ch1_nsmr_en = Enable;
			ich1_dfilter_ph_smr_pring_reg.ch1_thd_nsmr = Offset;
			ich1_dfilter_ph_smr_pring_reg.ch1_nsmr_div = Div;
			break;
		case _MISMATCH_ACCESS_PORT:
			ich1_dfilter_nring_mis_nos_ypbpr_reg.ch1_mis_en = Enable;
			ich1_dfilter_nring_mis_nos_ypbpr_reg.ch1_thd_mis = Offset;
			break;
		case _NOISE_REDUCTION_PORT:
			ich1_dfilter_nring_mis_nos_ypbpr_reg.ch1_nos_en = Enable;
			ich1_dfilter_nring_mis_nos_ypbpr_reg.ch1_thd_nos = Offset;
			break;

		}

		IoReg_Write32(DFILTER_ICH1_DFILTER_PH_SMR_PRING_reg, ich1_dfilter_ph_smr_pring_reg.regValue);
		IoReg_Write32(DFILTER_ICH1_DFILTER_NRING_MIS_NOS_YPBPR_reg, ich1_dfilter_nring_mis_nos_ypbpr_reg.regValue);

	}
#ifdef CONFIG_DUAL_CHANNEL
#ifdef VIP_CONFIG_DUAL_CHANNEL // henry 161214
	else {
		dfilter_ich2_dfilter_ph_smr_pring_RBUS ich2_dfilter_ph_smr_pring_reg;
		dfilter_ich2_dfilter_nring_mis_nos_ypbpr_RBUS ich2_dfilter_nring_mis_nos_ypbpr_reg;

		ich2_dfilter_ph_smr_pring_reg.regValue = IoReg_Read32(DFILTER_ICH2_DFILTER_PH_SMR_PRING_reg);
		ich2_dfilter_nring_mis_nos_ypbpr_reg.regValue = IoReg_Read32(DFILTER_ICH2_DFILTER_NRING_MIS_NOS_YPBPR_reg);

		switch (Access) {
		case _YPBPR_ACCESS_PORT:
			ich2_dfilter_nring_mis_nos_ypbpr_reg.ch2_y_en = 0x1;
			ich2_dfilter_nring_mis_nos_ypbpr_reg.ch2_pb_en = 0x1;
			ich2_dfilter_nring_mis_nos_ypbpr_reg.ch2_pr_en = 0x1;
			break;
		case _PHASE_ACCESS_PORT:
			ich2_dfilter_ph_smr_pring_reg.ch2_ph_en = Enable;
			ich2_dfilter_ph_smr_pring_reg.ch2_thd_ph = Offset;
			ich2_dfilter_ph_smr_pring_reg.ch2_ph_div = Div;
			break;
		case _NEG_SMEAR_ACCESS_PORT:
			ich2_dfilter_ph_smr_pring_reg.ch2_nsmr_en = Enable;
			ich2_dfilter_ph_smr_pring_reg.ch2_thd_nsmr = Offset;
			ich2_dfilter_ph_smr_pring_reg.ch2_nsmr_div = Div;
			break;
		case _MISMATCH_ACCESS_PORT:
			ich2_dfilter_nring_mis_nos_ypbpr_reg.ch2_mis_en = Enable;
			ich2_dfilter_nring_mis_nos_ypbpr_reg.ch2_thd_mis = Offset;
			break;
		case _NOISE_REDUCTION_PORT:
			ich2_dfilter_nring_mis_nos_ypbpr_reg.ch2_nos_en = Enable;
			ich2_dfilter_nring_mis_nos_ypbpr_reg.ch2_thd_nos = Offset;
			break;

		}

		IoReg_Write32(DFILTER_ICH2_DFILTER_PH_SMR_PRING_reg, ich2_dfilter_ph_smr_pring_reg.regValue);
		IoReg_Write32(DFILTER_ICH2_DFILTER_NRING_MIS_NOS_YPBPR_reg, ich2_dfilter_nring_mis_nos_ypbpr_reg.regValue);

	}
#endif
#endif
 }





void drvif_color_digital_filter_config(SCALER_DISP_CHANNEL display, unsigned char Enable)
{
#ifdef CONFIG_DUAL_CHANNEL
#ifdef VIP_CONFIG_DUAL_CHANNEL // henry 161214
	IoReg_ClearBits(DFILTER_ICH2_DFILTER_PH_SMR_PRING_reg, 0x01010101);
	IoReg_ClearBits(DFILTER_ICH2_DFILTER_NRING_MIS_NOS_YPBPR_reg, 0x00771101);
#endif
#endif

	if (display == SLR_MAIN_DISPLAY) {
		drvif_color_digital_filter_set(_PHASE_ACCESS_PORT, _PHASE_THD_0, _DIV_VALUE_2, Enable, SLR_MAIN_DISPLAY);
		drvif_color_digital_filter_set(_NEG_SMEAR_ACCESS_PORT, _SMEAR_RING_THD_4, _DIV_VALUE_1, Enable, SLR_MAIN_DISPLAY);
		drvif_color_digital_filter_set(_MISMATCH_ACCESS_PORT, _MISMATCH_THD_0, _DIV_VALUE_0, Enable, SLR_MAIN_DISPLAY);
		drvif_color_digital_filter_set(_NOISE_REDUCTION_PORT, 	_NOISE_REDUCTION_THD_7, _DIV_VALUE_0, Enable, SLR_MAIN_DISPLAY);

		drvif_color_digital_filter_set(_YPBPR_ACCESS_PORT, _YPBPR_ENABLE, _DIV_VALUE_0, Enable, SLR_MAIN_DISPLAY);
	}
#ifdef CONFIG_DUAL_CHANNEL
#ifdef VIP_CONFIG_DUAL_CHANNEL // henry 161214
	else {
		drvif_color_digital_filter_set(_PHASE_ACCESS_PORT, _PHASE_THD_0, _DIV_VALUE_2, Enable, SLR_SUB_DISPLAY);
		drvif_color_digital_filter_set(_NEG_SMEAR_ACCESS_PORT, _SMEAR_RING_THD_4, _DIV_VALUE_1, Enable, SLR_SUB_DISPLAY);
		drvif_color_digital_filter_set(_MISMATCH_ACCESS_PORT, _MISMATCH_THD_0, _DIV_VALUE_0, Enable, SLR_SUB_DISPLAY);
		drvif_color_digital_filter_set(_NOISE_REDUCTION_PORT, 	_NOISE_REDUCTION_THD_7, _DIV_VALUE_0, Enable, SLR_SUB_DISPLAY);

		drvif_color_digital_filter_set(_YPBPR_ACCESS_PORT, _YPBPR_ENABLE, _DIV_VALUE_0, Enable, SLR_SUB_DISPLAY);
	}
#endif
#endif

}


void drvif_color_digital_filtering_init(SCALER_DISP_CHANNEL display)
{
	_system_setting_info *VIP_system_info_structure_table = (_system_setting_info*)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_system_info_structure);
	if(VIP_system_info_structure_table == NULL){
		VIPprintf("[%s:%d] Warning here!! system_info=NULL! \n",__FILE__, __LINE__);
		return;
	}
//	if ((VIP_system_info_structure_table->Input_src_Type) == _SRC_YPBPR || (VIP_system_info_structure_table->Input_src_Type) == _SRC_VGA)
	if ((VIP_system_info_structure_table->Input_src_Type) == _SRC_VGA)		// YPP don't use noise reduction filter
		drvif_color_digital_filter_config(display, TRUE);
	else
		drvif_color_digital_filter_config(display, FALSE);
}


/*Input domain DLTI
*  only ch1
*
*
*/
/*     this is old I-DLti, no longer used since Darwin
void drvif_color_idlti(unsigned char display, unsigned char Level)
{
	i_dlti_ctrl_RBUS i_dlti_ctrl_reg;
	ich1_dlti_th_RBUS ich1_dlti_th_reg;
	scaledown_ich1_uzd_ctrl0_RBUS ich1_uzd_Ctrl0_reg ;
	i_dlti_ctrl_reg.regValue = IoReg_Read32(PEAKING_I_DLTI_CTRL_VADDR);
	ich1_dlti_th_reg.regValue = IoReg_Read32(PEAKING_ICH1_DLTI_TH_VADDR);
	ich1_uzd_Ctrl0_reg.regValue = IoReg_Read32(SCALEDOWN_ICH1_UZD_CTRL0_VADDR);

	if (Level >10)
		Level = 10;

	if (display ==_CHANNEL1) {
		if (Level == 0 || ich1_uzd_Ctrl0_reg.h_zoom_en == 1) {
			i_dlti_ctrl_reg.ch1_dlti_en = 0;
		} else {
			i_dlti_ctrl_reg.ch1_dlti_en = 1;
			i_dlti_ctrl_reg.ch1_dlti_gain =(unsigned char)(1*Level);
			i_dlti_ctrl_reg.new_function_blend = 1;
			ich1_dlti_th_reg.ch1_upper_th = 0x190;
			ich1_dlti_th_reg.ch1_lower_th = 0x78;
		}

		IoReg_Write32(PEAKING_I_DLTI_CTRL_VADDR, i_dlti_ctrl_reg.regValue);
		IoReg_Write32(PEAKING_ICH1_DLTI_TH_VADDR, ich1_dlti_th_reg.regValue);
	}

}
*/
/*======================== End of File =======================================*/
/**
 *
 * @}
 */



void drvif_color_Setditherbit(VIP_PANEL_BIT default_vip_panel_bit)
{

	switch (default_vip_panel_bit) {
	case VIP_PANEL_BIT6:
	 Panel_Bit = 0;
	/* VIPprintf("bit6");*/
	break;

	case VIP_PANEL_BIT8:
	 Panel_Bit = 1;
	/*  VIPprintf("bit8");*/
	break;

	case VIP_PANEL_BIT10:
	 Panel_Bit = 2;
	/*  VIPprintf("bit10");*/
	break;

	case VIP_PANEL_BIT_OTHERS:
	 Panel_Bit = 3;
	/*  VIPprintf("bit_other");*/
	break;
	}
}

void drvif_color_UV_Delay_Enable(VIP_UV_DELAY_ENABLE on_off)
{
	color_dlcti_uv_delay_RBUS uv_delay_reg;
	uv_delay_reg.regValue = IoReg_Read32(COLOR_DLCTI_UV_Delay_reg);

	if (on_off >= 255)
		on_off = VIP_UV_DELAY_OFF;

	uv_delay_reg.uv_delay_en = on_off;

	IoReg_Write32(COLOR_DLCTI_UV_Delay_reg, uv_delay_reg.regValue);

}


unsigned char drvif_color_Get_Color_UV_Delay_Enable()
{
	color_dlcti_uv_delay_RBUS uv_delay_reg;
	uv_delay_reg.regValue = IoReg_Read32(COLOR_DLCTI_UV_Delay_reg);
	return uv_delay_reg.uv_delay_en;
}

void drvif_color_Get_UV_Delay(DRV_VipUV_Delay *ptr)
{
	color_dlcti_uv_delay_RBUS uv_delay_reg;
	uv_delay_reg.regValue = IoReg_Read32(COLOR_DLCTI_UV_Delay_reg);
	ptr->u_delay = uv_delay_reg.u_delay;
	ptr->v_delay = uv_delay_reg.v_delay;
}

void drvif_color_Set_UV_Delay(DRV_VipUV_Delay *ptr)
{

	color_dlcti_uv_delay_RBUS uv_delay_reg;
	uv_delay_reg.regValue = IoReg_Read32(COLOR_DLCTI_UV_Delay_reg);

	uv_delay_reg.u_delay = ptr->u_delay;
	uv_delay_reg.v_delay = ptr->v_delay;

	IoReg_Write32(COLOR_DLCTI_UV_Delay_reg, uv_delay_reg.regValue);
}

void drvif_color_Set_UV_Delay_TOP(DRV_VipUV_Delay_TOP_Table *ptr)
{
	//Ctl1

	vdtop_output_control_RBUS output_control_reg;
	vdtop_chroma_delay_ctrl_RBUS chroma_delay_ctrl_reg;
	//vdtop_auto_pos_ctrl_RBUS auto_pos_ctrl_reg;

	if(!ptr)
		return;

	output_control_reg.regValue = vdcf_inl(VDTOP_OUTPUT_CONTROL_reg);
	output_control_reg.yc_delay = ptr->VipUV_Delay_TOP.yc_delay;
	vdcf_outl(VDTOP_OUTPUT_CONTROL_reg, output_control_reg.regValue);

	chroma_delay_ctrl_reg.regValue = vdcf_inl(VDTOP_CHROMA_DELAY_CTRL_reg);
	chroma_delay_ctrl_reg.cb_delay = ptr->VipUV_Delay_TOP.cb_delay;
	chroma_delay_ctrl_reg.cr_delay = ptr->VipUV_Delay_TOP.cr_delay;
	vdcf_outl(VDTOP_CHROMA_DELAY_CTRL_reg, chroma_delay_ctrl_reg.regValue);
}

void drvif_color_set_Adaptive_Gamma(DRV_Adaptive_Gamma_Ctrl *ptr)
{
	gamma_adapt_gamma_RBUS adapt_gamma_reg;

	IoReg_Read32(GAMMA_ADAPT_GAMMA_reg);

	adapt_gamma_reg.gamma_adapt_en = ptr->gamma_adapt_en;
	adapt_gamma_reg.sat_thl = ptr->sat_thl;
	adapt_gamma_reg.sat_thl_mul = ptr->sat_thl_mul;

	IoReg_Write32(GAMMA_ADAPT_GAMMA_reg, adapt_gamma_reg.regValue);

}


#if 0
void drvif_color_reg_YUV2RGB_COEF_BY_Y_Table(unsigned int *table)
{
	if (!table)
		return;

	tYUV2RGB_COEF_BY_Y = table;
}

void drvif_color_reg_YUV2RGB_UV_OFFSET_BY_Y_Table(unsigned int *table)
{
	if (!table)
		return;

	tYUV2RGB_UV_OFFSET_BY_Y = table;
}
#endif

#if defined (ENABLE_HDMI_RGB_RANGE)
unsigned char fwif_color_get_HDMI_RGB_Range_Mode()
{
	return HDMI_RGB_Range_Mode;
}
void fwif_color_set_HDMI_RGB_Range_Mode(unsigned char src_idx)
{
	HDMI_RGB_Range_Mode = src_idx;
}
#endif

#if 0 //jyyang20161215 // Dstat is remoived since mac5
int drvif_color_get_rgb_pixel_info(RGB_pixel_info *data)
{
	if (!data)
		return -1;

	/* set control bits*/
	{

	gamma_dstat_ctrl_r_RBUS dstat_ctrl_r_reg;
	gamma_dstat_ctrl_g_RBUS dstat_ctrl_g_reg;
	gamma_dstat_ctrl_b_RBUS dstat_ctrl_b_reg;
	dstat_ctrl_r_reg.regValue = IoReg_Read32(GAMMA_Dstat_CTRL_R_reg);
	dstat_ctrl_g_reg.regValue = IoReg_Read32(GAMMA_Dstat_CTRL_G_reg);
	dstat_ctrl_b_reg.regValue = IoReg_Read32(GAMMA_Dstat_CTRL_B_reg);

	dstat_ctrl_r_reg.d_stat_srcsel = 1;
	dstat_ctrl_r_reg.r_high = 16383;	/*14 bit*/
	dstat_ctrl_r_reg.r_low = 0;
	dstat_ctrl_g_reg.g_high = 16383;
	dstat_ctrl_g_reg.g_low = 0;
	dstat_ctrl_b_reg.b_high = 16383;
	dstat_ctrl_b_reg.b_low = 0;
	IoReg_Write32(GAMMA_Dstat_CTRL_R_reg, dstat_ctrl_r_reg.regValue);
	IoReg_Write32(GAMMA_Dstat_CTRL_G_reg, dstat_ctrl_g_reg.regValue);
	IoReg_Write32(GAMMA_Dstat_CTRL_B_reg, dstat_ctrl_b_reg.regValue);
	}

	IoReg_SetBits(GAMMA_Dstat_CTRL_R_reg, _BIT31);	/* enable dstat*/

	/*read information*/
	{
	gamma_dstat_o_r1_RBUS dstat_o_r1_reg;
	gamma_dstat_o_r2_RBUS dstat_o_r2_reg;
	gamma_dstat_o_g1_RBUS dstat_o_g1_reg;
	gamma_dstat_o_g2_RBUS dstat_o_g2_reg;
	gamma_dstat_o_b1_RBUS dstat_o_b1_reg;
	gamma_dstat_o_b2_RBUS dstat_o_b2_reg;
	dstat_o_r1_reg.regValue = IoReg_Read32(GAMMA_DSTAT_O_R1_reg);
	dstat_o_r2_reg.regValue = IoReg_Read32(GAMMA_DSTAT_O_R2_reg);
	dstat_o_g1_reg.regValue = IoReg_Read32(GAMMA_DSTAT_O_G1_reg);
	dstat_o_g2_reg.regValue = IoReg_Read32(GAMMA_DSTAT_O_G2_reg);
	dstat_o_b1_reg.regValue = IoReg_Read32(GAMMA_DSTAT_O_B1_reg);
	dstat_o_b2_reg.regValue = IoReg_Read32(GAMMA_DSTAT_O_B2_reg);
	data->RSum = (dstat_o_r1_reg.r_cnt)>>6;
	data->RMax = (dstat_o_r2_reg.r_max)>>6;
	data->RMin = (dstat_o_r2_reg.r_min)>>6;
	data->GSum = (dstat_o_g1_reg.g_cnt)>>6;
	data->GMax = (dstat_o_g2_reg.g_max)>>6;
	data->GMin = (dstat_o_g2_reg.g_min)>>6;
	data->BSum = (dstat_o_b1_reg.b_cnt)>>6;
	data->BMax = (dstat_o_b2_reg.b_max)>>6;
	data->BMin = (dstat_o_b2_reg.b_min)>>6;
	}

	return 0;
}
#endif

void drvif_color_bypass(Color_Fun_Bypass *ptr, unsigned char ipNum)
{
	int i;
	color_d_vc_global_ctrl_RBUS d_vc_global_ctrl_Reg;
	con_bri_dm_color_rgb_ctrl_RBUS	dm_color_rgb_ctrl_REG;
	gamma_gamma_ctrl_2_RBUS gamma_ctrl_2_REG;
	dither_dithering_ctrl_RBUS	dithering_ctrl_reg;
	srgb_srgb_ctrl_RBUS srgb_ctrl_reg;
	rgb2yuv_ich1_rgb2yuv_ctrl_RBUS  ich1_RGB2YUV_CTRL_REG;
	yuv2rgb_d_yuv2rgb_control_RBUS d_yuv2rgb_control_REG;

	for (i = 0; i < ipNum; i++) {
		switch (ptr[i].idIP) {
		case BYPASS_VIVID_COLOR:
			d_vc_global_ctrl_Reg.regValue = IoReg_Read32(COLOR_D_VC_Global_CTRL_reg);
			d_vc_global_ctrl_Reg.m_vc_en = ptr[i].bypass_switch;
			d_vc_global_ctrl_Reg.write_enable_11 = 1;
			IoReg_Write32(COLOR_D_VC_Global_CTRL_reg, d_vc_global_ctrl_Reg.regValue);
			break;
		case BYPASS_RGB_CON:
			dm_color_rgb_ctrl_REG.regValue = IoReg_Read32(CON_BRI_DM_COLOR_RGB_CTRL_reg);
			dm_color_rgb_ctrl_REG.m_con_en = ptr[i].bypass_switch;
			IoReg_Write32(CON_BRI_DM_COLOR_RGB_CTRL_reg, dm_color_rgb_ctrl_REG.regValue);
			break;
		case BYPASS_RGB_BRI:
			dm_color_rgb_ctrl_REG.regValue = IoReg_Read32(CON_BRI_DM_COLOR_RGB_CTRL_reg);
			dm_color_rgb_ctrl_REG.m_bri_en = ptr[i].bypass_switch;
			IoReg_Write32(CON_BRI_DM_COLOR_RGB_CTRL_reg, dm_color_rgb_ctrl_REG.regValue);
			break;
		case BYPASS_GAMMA:
			gamma_ctrl_2_REG.regValue = IoReg_Read32(GAMMA_GAMMA_CTRL_2_reg);
			gamma_ctrl_2_REG.gamma_m_tab_sel = ptr[i].bypass_switch;
			IoReg_Write32(GAMMA_GAMMA_CTRL_2_reg, gamma_ctrl_2_REG.regValue);
			break;
		case BYPASS_D_DITHER:
			dithering_ctrl_reg.regValue = IoReg_Read32(DITHER_DITHERING_CTRL_reg);
			dithering_ctrl_reg.function_enable = ptr[i].bypass_switch;
			IoReg_Write32(DITHER_DITHERING_CTRL_reg, dithering_ctrl_reg.regValue);
			break;
		case BYPASS_SRGB:
			srgb_ctrl_reg.regValue = IoReg_Read32(SRGB_sRGB_CTRL_reg);
			srgb_ctrl_reg.srgb_m_tab_sel = ptr[i].bypass_switch;
			IoReg_Write32(SRGB_sRGB_CTRL_reg, srgb_ctrl_reg.regValue);
			break;
		case BYPASS_RGB2YUV_MATRIX:
			ich1_RGB2YUV_CTRL_REG.regValue = IoReg_Read32(RGB2YUV_ICH1_RGB2YUV_CTRL_reg);
			ich1_RGB2YUV_CTRL_REG.matrix_bypass = !ptr[i].bypass_switch;
			IoReg_Write32(RGB2YUV_ICH1_RGB2YUV_CTRL_reg, ich1_RGB2YUV_CTRL_REG.regValue);
			break;
		case BYPASS_YUV2RGB_MATRIX:
			d_yuv2rgb_control_REG.regValue = IoReg_Read32(YUV2RGB_D_YUV2RGB_Control_reg);
			d_yuv2rgb_control_REG.yuv2rgb_main_en = ptr[i].bypass_switch;
			IoReg_Write32(YUV2RGB_D_YUV2RGB_Control_reg, d_yuv2rgb_control_REG.regValue);
			break;
		}
	}
}

void drvif_color_dither_mode(unsigned char mode)
{
	dither_dithering_ctrl_RBUS dithering_ctrl_reg;
	dithering_ctrl_reg.regValue = IoReg_Read32(DITHER_DITHERING_CTRL_reg);
	dithering_ctrl_reg.value_sign = mode;	/*0: truncation mode 1: round mode*/
	IoReg_Write32(DITHER_DITHERING_CTRL_reg, dithering_ctrl_reg.regValue);
}
void drvif_color_inv_gamma_init()
{
	inv_gamma_inv_gamma_ctrl_1_RBUS inv_gamma_ctrl_1_REG;
	inv_gamma_inv_gamma_ctrl_2_RBUS inv_gamma_ctrl_2_REG;

	inv_gamma_ctrl_1_REG.regValue = IoReg_Read32(INV_GAMMA_INV_GAMMA_CTRL_1_reg);
	inv_gamma_ctrl_2_REG.regValue = IoReg_Read32(INV_GAMMA_INV_GAMMA_CTRL_2_reg);

	inv_gamma_ctrl_1_REG.inv_gamma_ax_rw_sel = 0; /* writing table*/
	inv_gamma_ctrl_2_REG.inv_gamma_m_tab_sel = 0; /* use tab-1*/
	//inv_gamma_ctrl_2_REG.inv_gamma_overlap = 0; /* use main as overlay*/ //jyyang20161215

	inv_gamma_ctrl_1_REG.inv_gamma_ax_rw_sel = 0; /* disable writing table*/
	//inv_gamma_ctrl_2_REG.inv_gamma_overlap = 0; /* use sub as overlay*/ //jyyang20161215
	//inv_gamma_ctrl_2_REG.inv_gamma_s_tab_sel = 0; /* use tab-2*/ //jyyang20161215


	IoReg_Write32(INV_GAMMA_INV_GAMMA_CTRL_1_reg, inv_gamma_ctrl_1_REG.regValue);
	IoReg_Write32(INV_GAMMA_INV_GAMMA_CTRL_2_reg, inv_gamma_ctrl_2_REG.regValue);
}

void drvif_color_inv_gamma_control_front(unsigned char display)
{
	inv_gamma_inv_gamma_ctrl_1_RBUS inv_gamma_ctrl_1_REG;
	inv_gamma_inv_gamma_ctrl_2_RBUS inv_gamma_ctrl_2_REG;

	inv_gamma_ctrl_1_REG.regValue = IoReg_Read32(INV_GAMMA_INV_GAMMA_CTRL_1_reg);
	inv_gamma_ctrl_2_REG.regValue = IoReg_Read32(INV_GAMMA_INV_GAMMA_CTRL_2_reg);

	if (display == SLR_MAIN_DISPLAY) {
		/*gamma_ctrl_2_REG.gamma_m_tab_sel = 0; */ /* disable main gamma*/
		/* remove "disable gamma" for PIP sub flash when TV scan channel start & end , 20071228 Jerry Wu*/
		/*inv_gamma_ctrl_1_REG.inv_gamma_ax_type_sel = _Gamma_Full;	*/ /*=== marked by Elsie ===*/
		inv_gamma_ctrl_1_REG.res1 = 0; /* reserved*/
		inv_gamma_ctrl_1_REG.inv_gamma_ax_rw_sel = 1; /* writing table*/
		/*gamma_ctrl_2_REG.gamma_m_tab_sel = 0; */ /* don't mark this line, because it cause screen flash problem, Jerry Wu 20101118*/
		inv_gamma_ctrl_2_REG.inv_gamma_m_tab_sel = 0;
	}
	#ifdef CONFIG_DUAL_CHANNEL  /* There are two channels*/
	#ifdef VIP_CONFIG_DUAL_CHANNEL // henry 161214
	else {
		/*gamma_ctrl_2_REG.sub_tab_sel = 0; */ /* disable sub gamma*/
		/* remove "disable gamma" for PIP sub flash when TV scan channel start & end , 20071228 Jerry Wu*/
		/*inv_gamma_ctrl_1_REG.inv_gamma_ax_type_sel = _Gamma_Full;	*/ /*=== marked by Elsie ===*/
		inv_gamma_ctrl_1_REG.res1 = 1; /*  reserved*/
		inv_gamma_ctrl_1_REG.inv_gamma_ax_rw_sel = 1; /* writing table*/
		//inv_gamma_ctrl_2_REG.inv_gamma_s_tab_sel = 0; //jyyang20161215

	}
	#endif
	#endif
	//inv_gamma_ctrl_2_REG.inv_gamma_tab_size_sel = 0;	//20151126 roger, 512 table //jyyang20161215
	IoReg_Write32(INV_GAMMA_INV_GAMMA_CTRL_1_reg, inv_gamma_ctrl_1_REG.regValue);
	IoReg_Write32(INV_GAMMA_INV_GAMMA_CTRL_2_reg, inv_gamma_ctrl_2_REG.regValue);

}

void drvif_color_inv_gamma_control_back(unsigned char display, unsigned char ucWriteEnable)
{
	inv_gamma_inv_gamma_ctrl_1_RBUS inv_gamma_ctrl_1_REG;
	inv_gamma_inv_gamma_ctrl_2_RBUS inv_gamma_ctrl_2_REG;

	inv_gamma_ctrl_1_REG.regValue = IoReg_Read32(INV_GAMMA_INV_GAMMA_CTRL_1_reg);
	inv_gamma_ctrl_2_REG.regValue = IoReg_Read32(INV_GAMMA_INV_GAMMA_CTRL_2_reg);

	if (display == SLR_MAIN_DISPLAY) {

		inv_gamma_ctrl_1_REG.inv_gamma_ax_rw_sel = 0; /* writing table*/
		inv_gamma_ctrl_2_REG.inv_gamma_m_tab_sel = 1; /* use tab-1*/
		#ifdef CONFIG_DUAL_CHANNEL  /* There are two channels*/
		// inv_gamma_ctrl_2_REG.inv_gamma_overlap = 0; /* use main as overlay*/ //jyyang20161215
		#endif
	}
	#ifdef CONFIG_DUAL_CHANNEL  /* There are two channels*/
	#ifdef VIP_CONFIG_DUAL_CHANNEL // henry 161214
	else {
		inv_gamma_ctrl_1_REG.inv_gamma_ax_rw_sel = 0; /* disable writing table*/
		// inv_gamma_ctrl_2_REG.inv_gamma_overlap = 1; /* use sub as overlay*/ //jyyang20161215
		// inv_gamma_ctrl_2_REG.inv_gamma_s_tab_sel = 1; /* sub gamma use tab-1 same to m_tab	rock_rau 2015/09/17 [WOSQRTK-1187]*/ //jyyang20161215
	}
	#endif
	#endif

	IoReg_Write32(INV_GAMMA_INV_GAMMA_CTRL_1_reg, inv_gamma_ctrl_1_REG.regValue);
	if (ucWriteEnable)
		IoReg_Write32(INV_GAMMA_INV_GAMMA_CTRL_2_reg, inv_gamma_ctrl_2_REG.regValue);


}

void drvif_color_inv_gamma_control_back_TV006_demo()
{
	inv_gamma_inv_gamma_ctrl_1_RBUS inv_gamma_ctrl_1_REG;
	inv_gamma_inv_gamma_ctrl_2_RBUS inv_gamma_ctrl_2_REG;

	inv_gamma_ctrl_1_REG.regValue = IoReg_Read32(INV_GAMMA_INV_GAMMA_CTRL_1_reg);
	inv_gamma_ctrl_2_REG.regValue = IoReg_Read32(INV_GAMMA_INV_GAMMA_CTRL_2_reg);

	inv_gamma_ctrl_1_REG.inv_gamma_ax_rw_sel = 0; /* writing table*/
	inv_gamma_ctrl_2_REG.inv_gamma_m_tab_sel = 1; /* use tab-1*/
	//inv_gamma_ctrl_2_REG.inv_gamma_overlap = 1; /* use sub as overlay*/ //jyyang20161215
	//inv_gamma_ctrl_2_REG.inv_gamma_s_tab_sel = 2; /* sub gamma use tab-2*/ //jyyang20161215

	//inv_gamma_ctrl_2_REG.inv_gamma_tab_size_sel = 1;	//switch to 256 table //jyyang20161215

	IoReg_Write32(INV_GAMMA_INV_GAMMA_CTRL_1_reg, inv_gamma_ctrl_1_REG.regValue);
	IoReg_Write32(INV_GAMMA_INV_GAMMA_CTRL_2_reg, inv_gamma_ctrl_2_REG.regValue);


}


void drvif_color_Inv_Gamma_Curve_Write(unsigned int *Gamma_Encode, VIP_GAMMA_CHANNEL_RGB RGB_chanel_idx)
{
	inv_gamma_inv_gamma_ctrl_1_RBUS inv_gamma_ctrl_1_REG;
	inv_gamma_ctrl_1_REG.regValue = IoReg_Read32(INV_GAMMA_INV_GAMMA_CTRL_1_reg);
	inv_gamma_ctrl_1_REG.inv_gamma_ax_ch_sel = RGB_chanel_idx;
	IoReg_Write32(INV_GAMMA_INV_GAMMA_CTRL_1_reg, inv_gamma_ctrl_1_REG.regValue);
	drvif_color_colorwrite_invGamma(Gamma_Encode);
}

void drvif_color_out_gamma_control_front(void)
{
	outputgamma_out_gamma_ctrl_1_RBUS out_gamma_ctrl_1_REG;

	if(Get_DISPLAY_PANEL_TYPE() == P_VBY1_TO_LVDS_2K){
			return;
	}
	out_gamma_ctrl_1_REG.regValue = IoReg_Read32(OUTPUTGAMMA_OUT_GAMMA_CTRL_1_reg);
	out_gamma_ctrl_1_REG.out_gamma_ax_rw_sel = 1; /*enable writing table*/
	IoReg_Write32(OUTPUTGAMMA_OUT_GAMMA_CTRL_1_reg, out_gamma_ctrl_1_REG.regValue);

}

void drvif_color_out_gamma_control_back(void)
{
	outputgamma_out_gamma_ctrl_1_RBUS out_gamma_ctrl_1_REG;

	if(Get_DISPLAY_PANEL_TYPE() == P_VBY1_TO_LVDS_2K){
			return;
	}
	out_gamma_ctrl_1_REG.regValue = IoReg_Read32(OUTPUTGAMMA_OUT_GAMMA_CTRL_1_reg);
	out_gamma_ctrl_1_REG.out_gamma_ax_rw_sel = 0; /* disable writing table*/
	IoReg_Write32(OUTPUTGAMMA_OUT_GAMMA_CTRL_1_reg, out_gamma_ctrl_1_REG.regValue);
}

void drvif_color_out_gamma_control_enable(unsigned char enable)
{
	outputgamma_out_gamma_ctrl_1_RBUS out_gamma_ctrl_1_REG;

	if(Get_DISPLAY_PANEL_TYPE() == P_VBY1_TO_LVDS_2K){
			return;
	}
	out_gamma_ctrl_1_REG.regValue = IoReg_Read32(OUTPUTGAMMA_OUT_GAMMA_CTRL_1_reg);
	out_gamma_ctrl_1_REG.out_gamma_en = enable?1:0;
	IoReg_Write32(OUTPUTGAMMA_OUT_GAMMA_CTRL_1_reg, out_gamma_ctrl_1_REG.regValue);
}

void drvif_color_colorwrite_outGamma(unsigned int *pArray)
{
	unsigned short ii, cnt = 10000;
	outputgamma_out_gamma_port_RBUS out_gamma_port_REG;
	outputgamma_out_gamma_ctrl_1_RBUS out_gamma_ctrl_1_REG;
	unsigned char status = 1;

	if(Get_DISPLAY_PANEL_TYPE() == P_VBY1_TO_LVDS_2K){
			return;
	}
	for (ii = 0; ii < 128; ii++) {
		status = 1;
		cnt = 10000;
		out_gamma_port_REG.regValue = pArray[ii];
		IoReg_Write32(OUTPUTGAMMA_OUT_GAMMA_PORT_reg, out_gamma_port_REG.regValue);

		while ((cnt--) && (status) && ((ii % 16) == 15)) {
			out_gamma_ctrl_1_REG.regValue = IoReg_Read32(OUTPUTGAMMA_OUT_GAMMA_CTRL_1_reg);
			status =  (out_gamma_ctrl_1_REG.out_gamma_fifo_empty == 1) ? 0 : 1;
		}
	}
}

void drvif_color_Out_Gamma_Curve_Write(unsigned int *Gamma_Encode, VIP_GAMMA_CHANNEL_RGB RGB_chanel_idx)
{
	outputgamma_out_gamma_ctrl_1_RBUS out_gamma_ctrl_1_REG;

	if(Get_DISPLAY_PANEL_TYPE() == P_VBY1_TO_LVDS_2K){
			return;
	}
	out_gamma_ctrl_1_REG.regValue = IoReg_Read32(OUTPUTGAMMA_OUT_GAMMA_CTRL_1_reg);
	out_gamma_ctrl_1_REG.out_gamma_ax_ch_sel = RGB_chanel_idx;
	IoReg_Write32(OUTPUTGAMMA_OUT_GAMMA_CTRL_1_reg, out_gamma_ctrl_1_REG.regValue);
	drvif_color_colorwrite_outGamma(Gamma_Encode);
}

void drvif_color_xvYcc_colorspaceyuv2rgbtransfer(unsigned char display, unsigned char xvYcc_en_flag)
{
	yuv2rgb_d_yuv2rgbbyy_control_RBUS d_yuv2rgbbyy_control_REG;

	yuv2rgb_d_yuv2rgb_tab1_data_0_RBUS d_yuv2rgb_tab1_data_0_REG;
	yuv2rgb_d_yuv2rgb_tab1_data_1_RBUS d_yuv2rgb_tab1_data_1_REG;
	yuv2rgb_d_yuv2rgb_tab1_data_2_RBUS d_yuv2rgb_tab1_data_2_REG;
	yuv2rgb_d_yuv2rgb_tab1_data_3_RBUS d_yuv2rgb_tab1_data_3_REG;
	yuv2rgb_d_yuv2rgb_tab1_data_4_RBUS d_yuv2rgb_tab1_data_4_REG;
	yuv2rgb_d_yuv2rgb_tab1_data_5_RBUS d_yuv2rgb_tab1_data_5_REG;
	yuv2rgb_d_yuv2rgb_tab1_data_6_RBUS d_yuv2rgb_tab1_data_6_REG;

	d_yuv2rgbbyy_control_REG.regValue = IoReg_Read32(YUV2RGB_D_YUV2RGBBYY_CONTROL_reg);

	d_yuv2rgb_tab1_data_0_REG.regValue = IoReg_Read32(YUV2RGB_D_YUV2RGB_Tab1_Data_0_reg);
	d_yuv2rgb_tab1_data_1_REG.regValue = IoReg_Read32(YUV2RGB_D_YUV2RGB_Tab1_Data_1_reg);
	d_yuv2rgb_tab1_data_2_REG.regValue = IoReg_Read32(YUV2RGB_D_YUV2RGB_Tab1_Data_2_reg);
	d_yuv2rgb_tab1_data_3_REG.regValue = IoReg_Read32(YUV2RGB_D_YUV2RGB_Tab1_Data_3_reg);
	d_yuv2rgb_tab1_data_4_REG.regValue = IoReg_Read32(YUV2RGB_D_YUV2RGB_Tab1_Data_4_reg);
	d_yuv2rgb_tab1_data_5_REG.regValue = IoReg_Read32(YUV2RGB_D_YUV2RGB_Tab1_Data_5_reg);
	d_yuv2rgb_tab1_data_6_REG.regValue = IoReg_Read32(YUV2RGB_D_YUV2RGB_Tab1_Data_6_reg);

	if (d_yuv2rgbbyy_control_REG.yuv2rgbbymode_main_en == 0) {

		if (xvYcc_en_flag) {
			d_yuv2rgb_tab1_data_0_REG.k11 = (d_yuv2rgb_tab1_data_0_REG.k11 > 0x3ff) ?
											(complement2(complement2(d_yuv2rgb_tab1_data_0_REG.k11)>>1)) :
											((d_yuv2rgb_tab1_data_0_REG.k11)>>1);

			d_yuv2rgb_tab1_data_0_REG.k12 = (d_yuv2rgb_tab1_data_0_REG.k12 > 0x3ff) ?
											(complement2(complement2(d_yuv2rgb_tab1_data_0_REG.k12)>>1)) :
											((d_yuv2rgb_tab1_data_0_REG.k12)>>1);

			d_yuv2rgb_tab1_data_1_REG.k13 = (d_yuv2rgb_tab1_data_1_REG.k13 > 0x3ff) ?
											(complement2(complement2(d_yuv2rgb_tab1_data_1_REG.k13)>>1)) :
											((d_yuv2rgb_tab1_data_1_REG.k13)>>1);

			d_yuv2rgb_tab1_data_2_REG.k22 = (d_yuv2rgb_tab1_data_2_REG.k22 > 0x3ff) ?
											(complement2(complement2(d_yuv2rgb_tab1_data_2_REG.k22)>>1)) :
											((d_yuv2rgb_tab1_data_2_REG.k22)>>1);

			d_yuv2rgb_tab1_data_2_REG.k23 = (d_yuv2rgb_tab1_data_2_REG.k23 > 0x3ff) ?
											(complement2(complement2(d_yuv2rgb_tab1_data_2_REG.k23)>>1)) :
											((d_yuv2rgb_tab1_data_2_REG.k23)>>1);

			d_yuv2rgb_tab1_data_3_REG.k32 = (d_yuv2rgb_tab1_data_3_REG.k32 > 0x3ff) ?
											(complement2(complement2(d_yuv2rgb_tab1_data_3_REG.k32)>>1)) :
											((d_yuv2rgb_tab1_data_3_REG.k32)>>1);

			d_yuv2rgb_tab1_data_3_REG.k33 = (d_yuv2rgb_tab1_data_3_REG.k33 > 0x3ff) ?
											(complement2(complement2(d_yuv2rgb_tab1_data_3_REG.k33)>>1)) :
											((d_yuv2rgb_tab1_data_3_REG.k33)>>1);
		} else {
			d_yuv2rgb_tab1_data_0_REG.k11 = (d_yuv2rgb_tab1_data_0_REG.k11 > 0x3ff) ?
											(complement2(complement2(d_yuv2rgb_tab1_data_0_REG.k11) << 1)) :
											((d_yuv2rgb_tab1_data_0_REG.k11) << 1);

			d_yuv2rgb_tab1_data_0_REG.k12 = (d_yuv2rgb_tab1_data_0_REG.k12 > 0x3ff) ?
											(complement2(complement2(d_yuv2rgb_tab1_data_0_REG.k12) << 1)) :
											((d_yuv2rgb_tab1_data_0_REG.k12) << 1);

			d_yuv2rgb_tab1_data_1_REG.k13 = (d_yuv2rgb_tab1_data_1_REG.k13 > 0x3ff) ?
											(complement2(complement2(d_yuv2rgb_tab1_data_1_REG.k13) << 1)) :
											((d_yuv2rgb_tab1_data_1_REG.k13) << 1);

			d_yuv2rgb_tab1_data_2_REG.k22 = (d_yuv2rgb_tab1_data_2_REG.k22 > 0x3ff) ?
											(complement2(complement2(d_yuv2rgb_tab1_data_2_REG.k22) << 1)) :
											((d_yuv2rgb_tab1_data_2_REG.k22) << 1);

			d_yuv2rgb_tab1_data_2_REG.k23 = (d_yuv2rgb_tab1_data_2_REG.k23 > 0x3ff) ?
											(complement2(complement2(d_yuv2rgb_tab1_data_2_REG.k23) << 1)) :
											((d_yuv2rgb_tab1_data_2_REG.k23) << 1);

			d_yuv2rgb_tab1_data_3_REG.k32 = (d_yuv2rgb_tab1_data_3_REG.k32 > 0x3ff) ?
											(complement2(complement2(d_yuv2rgb_tab1_data_3_REG.k32) << 1)) :
											((d_yuv2rgb_tab1_data_3_REG.k32) << 1);

			d_yuv2rgb_tab1_data_3_REG.k33 = (d_yuv2rgb_tab1_data_3_REG.k33 > 0x3ff) ?
											(complement2(complement2(d_yuv2rgb_tab1_data_3_REG.k33) << 1)) :
											((d_yuv2rgb_tab1_data_3_REG.k33) << 1);
		}

		d_yuv2rgb_tab1_data_4_REG.roffset = d_yuv2rgb_tab1_data_4_REG.roffset + 24576;
		d_yuv2rgb_tab1_data_5_REG.goffset = d_yuv2rgb_tab1_data_4_REG.roffset + 24576;
		d_yuv2rgb_tab1_data_6_REG.boffset = d_yuv2rgb_tab1_data_4_REG.roffset + 24576;

		IoReg_Write32(YUV2RGB_D_YUV2RGB_Tab1_Data_0_reg, d_yuv2rgb_tab1_data_0_REG.regValue);
		IoReg_Write32(YUV2RGB_D_YUV2RGB_Tab1_Data_1_reg, d_yuv2rgb_tab1_data_1_REG.regValue);
		IoReg_Write32(YUV2RGB_D_YUV2RGB_Tab1_Data_2_reg, d_yuv2rgb_tab1_data_2_REG.regValue);
		IoReg_Write32(YUV2RGB_D_YUV2RGB_Tab1_Data_3_reg, d_yuv2rgb_tab1_data_3_REG.regValue);
		IoReg_Write32(YUV2RGB_D_YUV2RGB_Tab1_Data_4_reg, d_yuv2rgb_tab1_data_4_REG.regValue);
		IoReg_Write32(YUV2RGB_D_YUV2RGB_Tab1_Data_5_reg, d_yuv2rgb_tab1_data_5_REG.regValue);
		IoReg_Write32(YUV2RGB_D_YUV2RGB_Tab1_Data_6_reg, d_yuv2rgb_tab1_data_6_REG.regValue);

	} else {
		VIPprintf("Don't suppot for Coef by Y mode!!");

	}




}



#if 0//juwen, 161222, mac5p no colortmp
/*Elsie 20150226 add color temp driver*/
/*============================================================================*/
/**
 * Color_SetRgbColorTemp_contrast
 * Set contrast of RGB path
 * @param < display>	{ specify main/sub to set RgbContrastBrightness }
 * @param < Red> 		{ Red Contrast, Range: 0x00(0)~0x80(1)~0xff(2)}
 * @param < Green> 	{ Green Contrast, Range: 0x00(0)~0x80(1)~0xff(2)}
 * @param < Blue> 	{ Blue Contrast, Range: 0x00(0)~0x80(1)~0xff(2)}
 * @return 			{ void }
*/
void drvif_color_setrgbcolortemp_contrast(unsigned short Red, unsigned short Green, unsigned short Blue)
{
	color_temp_color_temp_contrast_0_RBUS color_temp_contrast_0_reg;
	color_temp_color_temp_contrast_1_RBUS color_temp_contrast_1_reg;

	color_temp_contrast_0_reg.regValue = IoReg_Read32(COLOR_TEMP_Color_Temp_Contrast_0_reg);
	color_temp_contrast_1_reg.regValue = IoReg_Read32(COLOR_TEMP_Color_Temp_Contrast_1_reg);

	color_temp_contrast_0_reg.contrast_r = Red;
	color_temp_contrast_0_reg.contrast_g = Green;
	color_temp_contrast_1_reg.contrast_b = Blue;

	IoReg_Write32(COLOR_TEMP_Color_Temp_Contrast_0_reg, color_temp_contrast_0_reg.regValue);
	IoReg_Write32(COLOR_TEMP_Color_Temp_Contrast_1_reg, color_temp_contrast_1_reg.regValue);

}

/*============================================================================*/
/**
 * Color_SetRgbColorTemp_bright
 * Set brightness of RGB path
 * @param < display>	{ specify main/sub to set RgbContrastBrightness }
 * @param < Red> 		{ Red brightness, Range: 0x000(-512)~0x200(0)~0x3ff(512)}
 * @param < Green> 	{ Green brightness , Range: 0x000(-512)~0x200(0)~0x3ff(512)}
 * @param < Blue> 	{ Blue brightness , Range: 0x000(-512)~0x200(0)~0x3ff(512)}
 * @return 			{ void }
*/

void drvif_color_setrgbcolortemp_bright(unsigned short Red, unsigned short Green, unsigned short Blue)
{
	color_temp_color_temp_brightness_0_RBUS color_temp_brightness_0_reg;
	color_temp_color_temp_brightness_1_RBUS color_temp_brightness_1_reg;

	color_temp_brightness_0_reg.regValue = IoReg_Read32(COLOR_TEMP_Color_Temp_Brightness_0_reg);
	color_temp_brightness_1_reg.regValue = IoReg_Read32(COLOR_TEMP_Color_Temp_Brightness_1_reg);

	color_temp_brightness_0_reg.bright_r = Red;
	color_temp_brightness_0_reg.bright_g = Green;
	color_temp_brightness_1_reg.bright_b = Blue;

	IoReg_Write32(COLOR_TEMP_Color_Temp_Brightness_0_reg, color_temp_brightness_0_reg.regValue);
	IoReg_Write32(COLOR_TEMP_Color_Temp_Brightness_1_reg, color_temp_brightness_1_reg.regValue);

}

void drvif_color_setrgbcolortemp_en(unsigned char enable)
{
	color_temp_color_temp_ctrl_RBUS color_temp_ctrl_reg;
	color_temp_ctrl_reg.regValue = IoReg_Read32(COLOR_TEMP_Color_Temp_CTRL_reg);
	color_temp_ctrl_reg.color_temp_en = enable;
	IoReg_Write32(COLOR_TEMP_Color_Temp_CTRL_reg, color_temp_ctrl_reg.regValue);

}
#endif

void drvif_color_set_new_uvc(DRV_NEW_UVC *ptr)
{
	/*	this IP is located between memory and ICM/DCC*/
	/*	From Magellan2 2015/3/5 chris added*/

	color_uvcoring_uvc_control_RBUS color_uvcoring_uvc_control_reg;
	color_uvcoring_uvc_global_u_RBUS color_uvcoring_uvc_global_u_reg;
	color_uvcoring_uvc_global_v_RBUS color_uvcoring_uvc_global_v_reg;
	color_uvcoring_uvc_skin_u_RBUS color_uvcoring_uvc_skin_u_reg;
	color_uvcoring_uvc_skin_v_RBUS color_uvcoring_uvc_skin_v_reg;

	if (!ptr)
		return;

	color_uvcoring_uvc_control_reg.regValue =  IoReg_Read32(COLOR_UVCORING_UVC_CONTROL_reg);
	color_uvcoring_uvc_global_u_reg.regValue =  IoReg_Read32(COLOR_UVCORING_UVC_GLOBAL_U_reg);
	color_uvcoring_uvc_global_v_reg.regValue =  IoReg_Read32(COLOR_UVCORING_UVC_GLOBAL_V_reg);
	color_uvcoring_uvc_skin_u_reg.regValue =  IoReg_Read32(COLOR_UVCORING_UVC_SKIN_U_reg);
	color_uvcoring_uvc_skin_v_reg.regValue =  IoReg_Read32(COLOR_UVCORING_UVC_SKIN_V_reg);

	/*	DRV_NEW_UVC_Ctrl	*/ /*	10*/
	color_uvcoring_uvc_control_reg.uvc_main_en = ptr->UVC_ctrl.UVC_main_en;
	#ifdef VIP_CONFIG_DUAL_CHANNEL
//	color_uvcoring_uvc_control_reg.uvc_sub_en = ptr->UVC_ctrl.UVC_sub_en;// mac5 dcc remove,no exist
//	color_uvcoring_uvc_control_reg.uvc_overlay_sel = ptr->UVC_ctrl.UVC_overlay_sel;// mac5 dcc remove, no exist
	#endif
	color_uvcoring_uvc_control_reg.uvc_skin_sel = ptr->UVC_ctrl.UVC_skin_sel;
	color_uvcoring_uvc_control_reg.uvc_qdrt1_en = ptr->UVC_ctrl.UVC_qdrt1_en;
	color_uvcoring_uvc_control_reg.uvc_qdrt2_en = ptr->UVC_ctrl.UVC_qdrt2_en;
	color_uvcoring_uvc_control_reg.uvc_qdrt3_en = ptr->UVC_ctrl.UVC_qdrt3_en;
	color_uvcoring_uvc_control_reg.uvc_qdrt4_en = ptr->UVC_ctrl.UVC_qdrt4_en;
	color_uvcoring_uvc_control_reg.uvc_y0 = ptr->UVC_ctrl.UVC_y0;
	color_uvcoring_uvc_control_reg.uvc_yslope = ptr->UVC_ctrl.UVC_y_slope;

	/*	DRV_NEW_UVC_Ctrl - global setting	*/ /*8*/
	color_uvcoring_uvc_global_u_reg.uvc_u_thd1_g = ptr->UVC_set_global.UVC_U_thd1;
	color_uvcoring_uvc_global_u_reg.uvc_u_slope1_g = ptr->UVC_set_global.UVC_U_slope1;
	color_uvcoring_uvc_global_u_reg.uvc_u_thd2_g = ptr->UVC_set_global.UVC_U_thd2;
	color_uvcoring_uvc_global_u_reg.uvc_u_slope2_g = ptr->UVC_set_global.UVC_U_slope2;
	color_uvcoring_uvc_global_v_reg.uvc_v_thd1_g = ptr->UVC_set_global.UVC_V_thd1;
	color_uvcoring_uvc_global_v_reg.uvc_v_slope1_g = ptr->UVC_set_global.UVC_V_slope1;
	color_uvcoring_uvc_global_v_reg.uvc_v_thd2_g = ptr->UVC_set_global.UVC_V_thd2;
	color_uvcoring_uvc_global_v_reg.uvc_v_slope2_g = ptr->UVC_set_global.UVC_V_slope2;

	/*	DRV_NEW_UVC_Ctrl - skin tone setting*/
	color_uvcoring_uvc_skin_u_reg.uvc_u_thd1_sk = ptr->UVC_set_skin.UVC_U_thd1;
	color_uvcoring_uvc_skin_u_reg.uvc_u_slope1_sk = ptr->UVC_set_skin.UVC_U_slope1;
	color_uvcoring_uvc_skin_u_reg.uvc_u_thd2_sk = ptr->UVC_set_skin.UVC_U_thd2;
	color_uvcoring_uvc_skin_u_reg.uvc_u_slope2_sk = ptr->UVC_set_skin.UVC_U_slope2;
	color_uvcoring_uvc_skin_v_reg.uvc_v_thd1_sk = ptr->UVC_set_skin.UVC_V_thd1;
	color_uvcoring_uvc_skin_v_reg.uvc_v_slope1_sk = ptr->UVC_set_skin.UVC_V_slope1;
	color_uvcoring_uvc_skin_v_reg.uvc_v_thd2_sk = ptr->UVC_set_skin.UVC_V_thd2;
	color_uvcoring_uvc_skin_v_reg.uvc_v_slope2_sk = ptr->UVC_set_skin.UVC_V_slope2;

	IoReg_Write32(COLOR_UVCORING_UVC_CONTROL_reg, color_uvcoring_uvc_control_reg.regValue);
	IoReg_Write32(COLOR_UVCORING_UVC_GLOBAL_U_reg, color_uvcoring_uvc_global_u_reg.regValue);
	IoReg_Write32(COLOR_UVCORING_UVC_GLOBAL_V_reg, color_uvcoring_uvc_global_v_reg.regValue);
	IoReg_Write32(COLOR_UVCORING_UVC_SKIN_U_reg, color_uvcoring_uvc_skin_u_reg.regValue);
	IoReg_Write32(COLOR_UVCORING_UVC_SKIN_V_reg, color_uvcoring_uvc_skin_v_reg.regValue);
}

#if 0 // 1d-decontour not implemented in Mac5p, 20161219 jimmy
void drvif_color_set_de_contour(DRV_De_CT_1D *ptr)
{
	/*	this IP is located between YUV2RGB and inverse-gamma*/
	/*	From Magellan2 2015/3/5 Ying-Ru added*/
	de_contour_dct_control_RBUS de_contour_dct_control_reg;
	de_contour_dct_lpf_RBUS de_contour_dct_lpf_reg;
	de_contour_dct_weight_mean_tex_RBUS de_contour_dct_weight_mean_tex_reg;
	de_contour_dct_weight_gap_RBUS de_contour_dct_weight_gap_reg;

	if (!ptr)
		return;

	de_contour_dct_control_reg.regValue =  IoReg_Read32(DE_CONTOUR_DCT_CONTROL_reg);
	de_contour_dct_lpf_reg.regValue =  IoReg_Read32(DE_CONTOUR_DCT_LPF_reg);
	de_contour_dct_weight_mean_tex_reg.regValue =  IoReg_Read32(DE_CONTOUR_DCT_WEIGHT_MEAN_TEX_reg);
	de_contour_dct_weight_gap_reg.regValue =  IoReg_Read32(DE_CONTOUR_DCT_WEIGHT_GAP_reg);

	/*EN or DEBUG Ctrl*/
	de_contour_dct_control_reg.dct_en = ptr->DeContour_ctrl.DeCT_en;
	/*de_contour_dct_control_reg.dct_debug = ptr->DeContour_ctrl.DeCT_DEBUG;*/

	/*LPF tap Set*/
	de_contour_dct_lpf_reg.dct_lp_k0 = ptr->DeContour_tap.K0;
	de_contour_dct_lpf_reg.dct_lp_k1 = ptr->DeContour_tap.K1;
	de_contour_dct_lpf_reg.dct_lp_k2 = ptr->DeContour_tap.K2;
	de_contour_dct_lpf_reg.dct_lp_k3 = ptr->DeContour_tap.K3;
	de_contour_dct_lpf_reg.dct_lp_k4 = ptr->DeContour_tap.K4;
	de_contour_dct_lpf_reg.dct_lp_k5 = ptr->DeContour_tap.K5;
	de_contour_dct_lpf_reg.dct_lp_shift = ptr->DeContour_tap.LP_SHIFT;

	/*De-contour Criteria & Weight*/
	de_contour_dct_weight_mean_tex_reg.dct_smooth_mean_w1 = ptr->DeContour_set.W1;
	de_contour_dct_weight_mean_tex_reg.dct_smooth_tex_w2 = ptr->DeContour_set.W2;
	de_contour_dct_weight_mean_tex_reg.dct_smooth_w1_w2_weight = ptr->DeContour_set.W1W2;
	de_contour_dct_weight_gap_reg.dct_min_gap_w3 = ptr->DeContour_set.MIN_GAP_W3;
	de_contour_dct_weight_gap_reg.dct_gap_w3 = ptr->DeContour_set.GAP_W3;
	de_contour_dct_weight_gap_reg.dct_smooth_gap_weight = ptr->DeContour_set.SMOOTH_GAP_W;
	de_contour_dct_weight_gap_reg.dct_all_channel_blend_weight = ptr->DeContour_set.ALL_CHANNEL_W;

	IoReg_Write32(DE_CONTOUR_DCT_CONTROL_reg, de_contour_dct_control_reg.regValue);
	IoReg_Write32(DE_CONTOUR_DCT_LPF_reg, de_contour_dct_lpf_reg.regValue);
	IoReg_Write32(DE_CONTOUR_DCT_WEIGHT_MEAN_TEX_reg, de_contour_dct_weight_mean_tex_reg.regValue);
	IoReg_Write32(DE_CONTOUR_DCT_WEIGHT_GAP_reg, de_contour_dct_weight_gap_reg.regValue);
}
#endif

void drvif_color_set_Blue_Stretch(DRV_Gamma_BS *ptr)
{
	/*	this IP is located before Gamma mapping*/
	/*	From Magellan2 2015/3/6 Chris added*/

	gamma_gamma_bs_control_RBUS gamma_gamma_bs_control_reg;
	gamma_gamma_bs_y_index_1_RBUS gamma_gamma_bs_y_index_1_reg;
	gamma_gamma_bs_y_index_2_RBUS gamma_gamma_bs_y_index_2_reg;
	gamma_gamma_bs_r_offset_1_RBUS gamma_gamma_bs_r_offset_1_reg;
	gamma_gamma_bs_r_offset_2_RBUS gamma_gamma_bs_r_offset_2_reg;
	gamma_gamma_bs_r_offset_3_RBUS gamma_gamma_bs_r_offset_3_reg;
	gamma_gamma_bs_g_offset_1_RBUS gamma_gamma_bs_g_offset_1_reg;
	gamma_gamma_bs_g_offset_2_RBUS gamma_gamma_bs_g_offset_2_reg;
	gamma_gamma_bs_g_offset_3_RBUS gamma_gamma_bs_g_offset_3_reg;
	gamma_gamma_bs_b_offset_1_RBUS gamma_gamma_bs_b_offset_1_reg;
	gamma_gamma_bs_b_offset_2_RBUS gamma_gamma_bs_b_offset_2_reg;
	gamma_gamma_bs_b_offset_3_RBUS gamma_gamma_bs_b_offset_3_reg;
	gamma_gamma_bs_r_step_1_RBUS gamma_gamma_bs_r_step_1_reg;
	gamma_gamma_bs_r_step_2_RBUS gamma_gamma_bs_r_step_2_reg;
	gamma_gamma_bs_g_step_1_RBUS gamma_gamma_bs_g_step_1_reg;
	gamma_gamma_bs_g_step_2_RBUS gamma_gamma_bs_g_step_2_reg;
	gamma_gamma_bs_b_step_1_RBUS gamma_gamma_bs_b_step_1_reg;
	gamma_gamma_bs_b_step_2_RBUS gamma_gamma_bs_b_step_2_reg;

	if (!ptr)
		return;

	gamma_gamma_bs_control_reg.regValue =  IoReg_Read32(GAMMA_GAMMA_BS_CONTROL_reg);
	gamma_gamma_bs_y_index_1_reg.regValue =  IoReg_Read32(GAMMA_GAMMA_BS_Y_INDEX_1_reg);
	gamma_gamma_bs_y_index_2_reg.regValue =  IoReg_Read32(GAMMA_GAMMA_BS_Y_INDEX_2_reg);
	gamma_gamma_bs_r_offset_1_reg.regValue =  IoReg_Read32(GAMMA_GAMMA_BS_R_OFFSET_1_reg);
	gamma_gamma_bs_r_offset_2_reg.regValue =  IoReg_Read32(GAMMA_GAMMA_BS_R_OFFSET_2_reg);
	gamma_gamma_bs_r_offset_3_reg.regValue =  IoReg_Read32(GAMMA_GAMMA_BS_R_OFFSET_3_reg);
	gamma_gamma_bs_g_offset_1_reg.regValue =  IoReg_Read32(GAMMA_GAMMA_BS_G_OFFSET_1_reg);
	gamma_gamma_bs_g_offset_2_reg.regValue =  IoReg_Read32(GAMMA_GAMMA_BS_G_OFFSET_2_reg);
	gamma_gamma_bs_g_offset_3_reg.regValue =  IoReg_Read32(GAMMA_GAMMA_BS_G_OFFSET_3_reg);
	gamma_gamma_bs_b_offset_1_reg.regValue =  IoReg_Read32(GAMMA_GAMMA_BS_B_OFFSET_1_reg);
	gamma_gamma_bs_b_offset_2_reg.regValue =  IoReg_Read32(GAMMA_GAMMA_BS_B_OFFSET_2_reg);
	gamma_gamma_bs_b_offset_3_reg.regValue =  IoReg_Read32(GAMMA_GAMMA_BS_B_OFFSET_3_reg);
	gamma_gamma_bs_r_step_1_reg.regValue =  IoReg_Read32(GAMMA_GAMMA_BS_R_STEP_1_reg);
	gamma_gamma_bs_r_step_2_reg.regValue =  IoReg_Read32(GAMMA_GAMMA_BS_R_STEP_2_reg);
	gamma_gamma_bs_g_step_1_reg.regValue =  IoReg_Read32(GAMMA_GAMMA_BS_G_STEP_1_reg);
	gamma_gamma_bs_g_step_2_reg.regValue =  IoReg_Read32(GAMMA_GAMMA_BS_G_STEP_2_reg);
	gamma_gamma_bs_b_step_1_reg.regValue =  IoReg_Read32(GAMMA_GAMMA_BS_B_STEP_1_reg);
	gamma_gamma_bs_b_step_2_reg.regValue =  IoReg_Read32(GAMMA_GAMMA_BS_B_STEP_2_reg);

	/*	Ctrl*/
	gamma_gamma_bs_control_reg.gamma_m_bs_en = ptr->GammaBS_ctrl.main_en;
	// gamma_gamma_bs_control_reg.gamma_s_bs_en = ptr->GammaBS_ctrl.sub_en; //jyyang20161215
	gamma_gamma_bs_control_reg.gamma_bs_sat_thd = ptr->GammaBS_ctrl.sat_thd;
	//marked by Elsie START
	//gamma_gamma_bs_control_reg.gamma_bs_gain = ptr->GammaBS_ctrl.gain;
	//marked by Elsie END
	//modified by Elsie START
	gamma_gamma_bs_control_reg.gamma_bs_r_gain = ptr->GammaBS_ctrl.r_gain;//20150709 caroline
	gamma_gamma_bs_control_reg.gamma_bs_g_gain = ptr->GammaBS_ctrl.g_gain;//20150709 caroline
	gamma_gamma_bs_control_reg.gamma_bs_b_gain = ptr->GammaBS_ctrl.b_gain;//20150709 caroline
	//modified by Elsie END

	/*	Y index*/
	gamma_gamma_bs_y_index_1_reg.gamma_bs_y0 = ptr->GammaBS_y.yindx[0];
	gamma_gamma_bs_y_index_1_reg.gamma_bs_y1 = ptr->GammaBS_y.yindx[1];
	gamma_gamma_bs_y_index_1_reg.gamma_bs_y2 = ptr->GammaBS_y.yindx[2];
	gamma_gamma_bs_y_index_1_reg.gamma_bs_y3 = ptr->GammaBS_y.yindx[3];
	gamma_gamma_bs_y_index_2_reg.gamma_bs_y4 = ptr->GammaBS_y.yindx[4];
	gamma_gamma_bs_y_index_2_reg.gamma_bs_y5 = ptr->GammaBS_y.yindx[5];
	gamma_gamma_bs_y_index_2_reg.gamma_bs_y6 = ptr->GammaBS_y.yindx[6];
	gamma_gamma_bs_y_index_2_reg.gamma_bs_y7 = ptr->GammaBS_y.yindx[7];

	/*	Rofst and Rstep*/
	gamma_gamma_bs_r_offset_1_reg.gamma_bs_r_ofst_0 = ptr->GammaBS_R.ofst[0];
	gamma_gamma_bs_r_offset_1_reg.gamma_bs_r_ofst_1 = ptr->GammaBS_R.ofst[1];
	gamma_gamma_bs_r_offset_1_reg.gamma_bs_r_ofst_2 = ptr->GammaBS_R.ofst[2];
	gamma_gamma_bs_r_offset_2_reg.gamma_bs_r_ofst_3 = ptr->GammaBS_R.ofst[3];
	gamma_gamma_bs_r_offset_2_reg.gamma_bs_r_ofst_4 = ptr->GammaBS_R.ofst[4];
	gamma_gamma_bs_r_offset_2_reg.gamma_bs_r_ofst_5 = ptr->GammaBS_R.ofst[5];
	gamma_gamma_bs_r_offset_3_reg.gamma_bs_r_ofst_6 = ptr->GammaBS_R.ofst[6];
	gamma_gamma_bs_r_offset_3_reg.gamma_bs_r_ofst_7 = ptr->GammaBS_R.ofst[7];
	gamma_gamma_bs_r_step_1_reg.gamma_bs_r_step_0 = ptr->GammaBS_R.step[0];
	gamma_gamma_bs_r_step_1_reg.gamma_bs_r_step_1 = ptr->GammaBS_R.step[1];
	gamma_gamma_bs_r_step_1_reg.gamma_bs_r_step_2 = ptr->GammaBS_R.step[2];
	gamma_gamma_bs_r_step_1_reg.gamma_bs_r_step_3 = ptr->GammaBS_R.step[3];
	gamma_gamma_bs_r_step_2_reg.gamma_bs_r_step_4 = ptr->GammaBS_R.step[4];
	gamma_gamma_bs_r_step_2_reg.gamma_bs_r_step_5 = ptr->GammaBS_R.step[5];
	gamma_gamma_bs_r_step_2_reg.gamma_bs_r_step_6 = ptr->GammaBS_R.step[6];
	gamma_gamma_bs_r_step_2_reg.gamma_bs_r_step_7 = ptr->GammaBS_R.step[7];

	/*	Gofst and Gstep*/
	gamma_gamma_bs_g_offset_1_reg.gamma_bs_g_ofst_0 = ptr->GammaBS_G.ofst[0];
	gamma_gamma_bs_g_offset_1_reg.gamma_bs_g_ofst_1 = ptr->GammaBS_G.ofst[1];
	gamma_gamma_bs_g_offset_1_reg.gamma_bs_g_ofst_2 = ptr->GammaBS_G.ofst[2];
	gamma_gamma_bs_g_offset_2_reg.gamma_bs_g_ofst_3 = ptr->GammaBS_G.ofst[3];
	gamma_gamma_bs_g_offset_2_reg.gamma_bs_g_ofst_4 = ptr->GammaBS_G.ofst[4];
	gamma_gamma_bs_g_offset_2_reg.gamma_bs_g_ofst_5 = ptr->GammaBS_G.ofst[5];
	gamma_gamma_bs_g_offset_3_reg.gamma_bs_g_ofst_6 = ptr->GammaBS_G.ofst[6];
	gamma_gamma_bs_g_offset_3_reg.gamma_bs_g_ofst_7 = ptr->GammaBS_G.ofst[7];
	gamma_gamma_bs_g_step_1_reg.gamma_bs_g_step_0 = ptr->GammaBS_G.step[0];
	gamma_gamma_bs_g_step_1_reg.gamma_bs_g_step_1 = ptr->GammaBS_G.step[1];
	gamma_gamma_bs_g_step_1_reg.gamma_bs_g_step_2 = ptr->GammaBS_G.step[2];
	gamma_gamma_bs_g_step_1_reg.gamma_bs_g_step_3 = ptr->GammaBS_G.step[3];
	gamma_gamma_bs_g_step_2_reg.gamma_bs_g_step_4 = ptr->GammaBS_G.step[4];
	gamma_gamma_bs_g_step_2_reg.gamma_bs_g_step_5 = ptr->GammaBS_G.step[5];
	gamma_gamma_bs_g_step_2_reg.gamma_bs_g_step_6 = ptr->GammaBS_G.step[6];
	gamma_gamma_bs_g_step_2_reg.gamma_bs_g_step_7 = ptr->GammaBS_G.step[7];

	/*	Bofst and Bstep*/
	gamma_gamma_bs_b_offset_1_reg.gamma_bs_b_ofst_0 = ptr->GammaBS_B.ofst[0];
	gamma_gamma_bs_b_offset_1_reg.gamma_bs_b_ofst_1 = ptr->GammaBS_B.ofst[1];
	gamma_gamma_bs_b_offset_1_reg.gamma_bs_b_ofst_2 = ptr->GammaBS_B.ofst[2];
	gamma_gamma_bs_b_offset_2_reg.gamma_bs_b_ofst_3 = ptr->GammaBS_B.ofst[3];
	gamma_gamma_bs_b_offset_2_reg.gamma_bs_b_ofst_4 = ptr->GammaBS_B.ofst[4];
	gamma_gamma_bs_b_offset_2_reg.gamma_bs_b_ofst_5 = ptr->GammaBS_B.ofst[5];
	gamma_gamma_bs_b_offset_3_reg.gamma_bs_b_ofst_6 = ptr->GammaBS_B.ofst[6];
	gamma_gamma_bs_b_offset_3_reg.gamma_bs_b_ofst_7 = ptr->GammaBS_B.ofst[7];
	gamma_gamma_bs_b_step_1_reg.gamma_bs_b_step_0 = ptr->GammaBS_B.step[0];
	gamma_gamma_bs_b_step_1_reg.gamma_bs_b_step_1 = ptr->GammaBS_B.step[1];
	gamma_gamma_bs_b_step_1_reg.gamma_bs_b_step_2 = ptr->GammaBS_B.step[2];
	gamma_gamma_bs_b_step_1_reg.gamma_bs_b_step_3 = ptr->GammaBS_B.step[3];
	gamma_gamma_bs_b_step_2_reg.gamma_bs_b_step_4 = ptr->GammaBS_B.step[4];
	gamma_gamma_bs_b_step_2_reg.gamma_bs_b_step_5 = ptr->GammaBS_B.step[5];
	gamma_gamma_bs_b_step_2_reg.gamma_bs_b_step_6 = ptr->GammaBS_B.step[6];
	gamma_gamma_bs_b_step_2_reg.gamma_bs_b_step_7 = ptr->GammaBS_B.step[7];

	/* KTASKWBS-6081, hor line noise, apply bs in porch*/
	if (drvif_scalerdisplay_get_force_bg_status()==0)
		fwif_color_WaitFor_DEN_STOP_UZUDTG();

	IoReg_Write32(GAMMA_GAMMA_BS_CONTROL_reg, gamma_gamma_bs_control_reg.regValue);
	IoReg_Write32(GAMMA_GAMMA_BS_Y_INDEX_1_reg, gamma_gamma_bs_y_index_1_reg.regValue);
	IoReg_Write32(GAMMA_GAMMA_BS_Y_INDEX_2_reg, gamma_gamma_bs_y_index_2_reg.regValue);
	IoReg_Write32(GAMMA_GAMMA_BS_R_OFFSET_1_reg, gamma_gamma_bs_r_offset_1_reg.regValue);
	IoReg_Write32(GAMMA_GAMMA_BS_R_OFFSET_2_reg, gamma_gamma_bs_r_offset_2_reg.regValue);
	IoReg_Write32(GAMMA_GAMMA_BS_R_OFFSET_3_reg, gamma_gamma_bs_r_offset_3_reg.regValue);
	IoReg_Write32(GAMMA_GAMMA_BS_G_OFFSET_1_reg, gamma_gamma_bs_g_offset_1_reg.regValue);
	IoReg_Write32(GAMMA_GAMMA_BS_G_OFFSET_2_reg, gamma_gamma_bs_g_offset_2_reg.regValue);
	IoReg_Write32(GAMMA_GAMMA_BS_G_OFFSET_3_reg, gamma_gamma_bs_g_offset_3_reg.regValue);
	IoReg_Write32(GAMMA_GAMMA_BS_B_OFFSET_1_reg, gamma_gamma_bs_b_offset_1_reg.regValue);
	IoReg_Write32(GAMMA_GAMMA_BS_B_OFFSET_2_reg, gamma_gamma_bs_b_offset_2_reg.regValue);
	IoReg_Write32(GAMMA_GAMMA_BS_B_OFFSET_3_reg, gamma_gamma_bs_b_offset_3_reg.regValue);
	IoReg_Write32(GAMMA_GAMMA_BS_R_STEP_1_reg, gamma_gamma_bs_r_step_1_reg.regValue);
	IoReg_Write32(GAMMA_GAMMA_BS_R_STEP_2_reg, gamma_gamma_bs_r_step_2_reg.regValue);
	IoReg_Write32(GAMMA_GAMMA_BS_G_STEP_1_reg, gamma_gamma_bs_g_step_1_reg.regValue);
	IoReg_Write32(GAMMA_GAMMA_BS_G_STEP_2_reg, gamma_gamma_bs_g_step_2_reg.regValue);
	IoReg_Write32(GAMMA_GAMMA_BS_B_STEP_1_reg, gamma_gamma_bs_b_step_1_reg.regValue);
	IoReg_Write32(GAMMA_GAMMA_BS_B_STEP_2_reg, gamma_gamma_bs_b_step_2_reg.regValue);
}

/*Elsie 20150317*/
void drvif_color_set_Color_Mapping(DRV_Color_Mapping *ptr)
{
#if 0
	_system_setting_info *VIP_system_info_structure_table = (_system_setting_info*)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_system_info_structure);

	if (!ptr)
		return;

	if ((VIP_system_info_structure_table->input_display) == SLR_MAIN_DISPLAY) {
		colormap_d_cmrgb2rgb_control_RBUS cmrgb2rgb_control_reg;
		colormap_d_cmrgb2rgb_tab1_data_in_offset_0_RBUS cmrgb2rgb_tab1_data_in_offset_0_reg;
		colormap_d_cmrgb2rgb_tab1_data_in_offset_1_RBUS cmrgb2rgb_tab1_data_in_offset_1_reg;
		colormap_d_cmrgb2rgb_tab1_data_0_RBUS cmrgb2rgb_tab1_data_0_reg;
		colormap_d_cmrgb2rgb_tab1_data_1_RBUS cmrgb2rgb_tab1_data_1_reg;
		colormap_d_cmrgb2rgb_tab1_data_2_RBUS cmrgb2rgb_tab1_data_2_reg;
		colormap_d_cmrgb2rgb_tab1_data_3_RBUS cmrgb2rgb_tab1_data_3_reg;
		colormap_d_cmrgb2rgb_tab1_data_4_RBUS cmrgb2rgb_tab1_data_4_reg;
		colormap_d_cmrgb2rgb_tab1_out_offset_0_RBUS cmrgb2rgb_tab1_out_offset_0_reg;
		colormap_d_cmrgb2rgb_tab1_out_offset_1_RBUS cmrgb2rgb_tab1_out_offset_1_reg;


		cmrgb2rgb_control_reg.regValue =  IoReg_Read32(COLORMAP_D_CMRGB2RGB_Control_reg);
		cmrgb2rgb_tab1_data_in_offset_0_reg.regValue =  IoReg_Read32(COLORMAP_D_CMRGB2RGB_Tab1_Data_In_Offset_0_reg);
		cmrgb2rgb_tab1_data_in_offset_1_reg.regValue =  IoReg_Read32(COLORMAP_D_CMRGB2RGB_Tab1_Data_In_Offset_1_reg);
		cmrgb2rgb_tab1_data_0_reg.regValue =  IoReg_Read32(COLORMAP_D_CMRGB2RGB_Tab1_Data_0_reg);
		cmrgb2rgb_tab1_data_1_reg.regValue =  IoReg_Read32(COLORMAP_D_CMRGB2RGB_Tab1_Data_1_reg);
		cmrgb2rgb_tab1_data_2_reg.regValue =  IoReg_Read32(COLORMAP_D_CMRGB2RGB_Tab1_Data_2_reg);
		cmrgb2rgb_tab1_data_3_reg.regValue =  IoReg_Read32(COLORMAP_D_CMRGB2RGB_Tab1_Data_3_reg);
		cmrgb2rgb_tab1_data_4_reg.regValue =  IoReg_Read32(COLORMAP_D_CMRGB2RGB_Tab1_Data_4_reg);
		cmrgb2rgb_tab1_out_offset_0_reg.regValue =  IoReg_Read32(COLORMAP_D_CMRGB2RGB_Tab1_Out_offset_0_reg);
		cmrgb2rgb_tab1_out_offset_1_reg.regValue =  IoReg_Read32(COLORMAP_D_CMRGB2RGB_Tab1_Out_offset_1_reg);

		/* ctrl*/
		cmrgb2rgb_control_reg.cmrgb2rgb_main_en = ptr->Color_Mapping_En;
		cmrgb2rgb_control_reg.cmrgb2rgb_main_tab_sel = 0;

		/* input offset*/
		cmrgb2rgb_tab1_data_in_offset_0_reg.x_offset = ptr->CM_InOffset.XOffset;
		cmrgb2rgb_tab1_data_in_offset_0_reg.y_offset = ptr->CM_InOffset.YOffset;
		cmrgb2rgb_tab1_data_in_offset_1_reg.z_offset = ptr->CM_InOffset.ZOffset;

		/* table*/
		cmrgb2rgb_tab1_data_0_reg.k11 = ptr->CM_Data.K11;
		cmrgb2rgb_tab1_data_0_reg.k12 = ptr->CM_Data.K12;
		cmrgb2rgb_tab1_data_1_reg.k13 = ptr->CM_Data.K13;
		cmrgb2rgb_tab1_data_1_reg.k21 = ptr->CM_Data.K21;
		cmrgb2rgb_tab1_data_2_reg.k22 = ptr->CM_Data.K22;
		cmrgb2rgb_tab1_data_2_reg.k23 = ptr->CM_Data.K23;
		cmrgb2rgb_tab1_data_3_reg.k31 = ptr->CM_Data.K31;
		cmrgb2rgb_tab1_data_3_reg.k32 = ptr->CM_Data.K32;
		cmrgb2rgb_tab1_data_4_reg.k33 = ptr->CM_Data.K33;

		/* output offset*/
		cmrgb2rgb_tab1_out_offset_0_reg.roffset = ptr->CM_OutOffset.ROffset;
		cmrgb2rgb_tab1_out_offset_0_reg.goffset = ptr->CM_OutOffset.GOffset;
		cmrgb2rgb_tab1_out_offset_1_reg.boffset = ptr->CM_OutOffset.BOffset;

		IoReg_Write32(COLORMAP_D_CMRGB2RGB_Control_reg, cmrgb2rgb_control_reg.regValue);
		IoReg_Write32(COLORMAP_D_CMRGB2RGB_Tab1_Data_In_Offset_0_reg, cmrgb2rgb_tab1_data_in_offset_0_reg.regValue);
		IoReg_Write32(COLORMAP_D_CMRGB2RGB_Tab1_Data_In_Offset_1_reg, cmrgb2rgb_tab1_data_in_offset_1_reg.regValue);
		IoReg_Write32(COLORMAP_D_CMRGB2RGB_Tab1_Data_0_reg, cmrgb2rgb_tab1_data_0_reg.regValue);
		IoReg_Write32(COLORMAP_D_CMRGB2RGB_Tab1_Data_1_reg, cmrgb2rgb_tab1_data_1_reg.regValue);
		IoReg_Write32(COLORMAP_D_CMRGB2RGB_Tab1_Data_2_reg, cmrgb2rgb_tab1_data_2_reg.regValue);
		IoReg_Write32(COLORMAP_D_CMRGB2RGB_Tab1_Data_3_reg, cmrgb2rgb_tab1_data_3_reg.regValue);
		IoReg_Write32(COLORMAP_D_CMRGB2RGB_Tab1_Data_4_reg, cmrgb2rgb_tab1_data_4_reg.regValue);
		IoReg_Write32(COLORMAP_D_CMRGB2RGB_Tab1_Out_offset_0_reg, cmrgb2rgb_tab1_out_offset_0_reg.regValue);
		IoReg_Write32(COLORMAP_D_CMRGB2RGB_Tab1_Out_offset_1_reg, cmrgb2rgb_tab1_out_offset_1_reg.regValue);
	}
#ifdef VIP_CONFIG_DUAL_CHANNEL
	else {
		colormap_d_cmrgb2rgb_control_RBUS cmrgb2rgb_control_reg;
		colormap_d_cmrgb2rgb_tab2_data_in_offset_0_RBUS cmrgb2rgb_tab2_data_in_offset_0_reg;
		colormap_d_cmrgb2rgb_tab2_data_in_offset_1_RBUS cmrgb2rgb_tab2_data_in_offset_1_reg;
		colormap_d_cmrgb2rgb_tab2_data_0_RBUS cmrgb2rgb_tab2_data_0_reg;
		colormap_d_cmrgb2rgb_tab2_data_1_RBUS cmrgb2rgb_tab2_data_1_reg;
		colormap_d_cmrgb2rgb_tab2_data_2_RBUS cmrgb2rgb_tab2_data_2_reg;
		colormap_d_cmrgb2rgb_tab2_data_3_RBUS cmrgb2rgb_tab2_data_3_reg;
		colormap_d_cmrgb2rgb_tab2_data_4_RBUS cmrgb2rgb_tab2_data_4_reg;
		colormap_d_cmrgb2rgb_tab2_out_offset_0_RBUS cmrgb2rgb_tab2_out_offset_0_reg;
		colormap_d_cmrgb2rgb_tab2_out_offset_1_RBUS cmrgb2rgb_tab2_out_offset_1_reg;


		cmrgb2rgb_control_reg.regValue =  IoReg_Read32(COLORMAP_D_CMRGB2RGB_Control_reg);
		cmrgb2rgb_tab2_data_in_offset_0_reg.regValue =  IoReg_Read32(COLORMAP_D_CMRGB2RGB_Tab2_Data_In_Offset_0_reg);
		cmrgb2rgb_tab2_data_in_offset_1_reg.regValue =  IoReg_Read32(COLORMAP_D_CMRGB2RGB_Tab2_Data_In_Offset_1_reg);
		cmrgb2rgb_tab2_data_0_reg.regValue =  IoReg_Read32(COLORMAP_D_CMRGB2RGB_Tab2_Data_0_reg);
		cmrgb2rgb_tab2_data_1_reg.regValue =  IoReg_Read32(COLORMAP_D_CMRGB2RGB_Tab2_Data_1_reg);
		cmrgb2rgb_tab2_data_2_reg.regValue =  IoReg_Read32(COLORMAP_D_CMRGB2RGB_Tab2_Data_2_reg);
		cmrgb2rgb_tab2_data_3_reg.regValue =  IoReg_Read32(COLORMAP_D_CMRGB2RGB_Tab2_Data_3_reg);
		cmrgb2rgb_tab2_data_4_reg.regValue =  IoReg_Read32(COLORMAP_D_CMRGB2RGB_Tab2_Data_4_reg);
		cmrgb2rgb_tab2_out_offset_0_reg.regValue =  IoReg_Read32(COLORMAP_D_CMRGB2RGB_Tab2_Out_offset_0_reg);
		cmrgb2rgb_tab2_out_offset_1_reg.regValue =  IoReg_Read32(COLORMAP_D_CMRGB2RGB_Tab2_Out_offset_1_reg);

		/* ctrl*/
		cmrgb2rgb_control_reg.cmrgb2rgb_sub_en = ptr->Color_Mapping_En;
		cmrgb2rgb_control_reg.cmrgb2rgb_sub_tab_sel = 1;

		/* input offset*/
		cmrgb2rgb_tab2_data_in_offset_0_reg.x_offset = ptr->CM_InOffset.XOffset;
		cmrgb2rgb_tab2_data_in_offset_0_reg.y_offset = ptr->CM_InOffset.YOffset;
		cmrgb2rgb_tab2_data_in_offset_1_reg.z_offset = ptr->CM_InOffset.ZOffset;

		/* table*/
		cmrgb2rgb_tab2_data_0_reg.k11 = ptr->CM_Data.K11;
		cmrgb2rgb_tab2_data_0_reg.k12 = ptr->CM_Data.K12;
		cmrgb2rgb_tab2_data_1_reg.k13 = ptr->CM_Data.K13;
		cmrgb2rgb_tab2_data_1_reg.k21 = ptr->CM_Data.K21;
		cmrgb2rgb_tab2_data_2_reg.k22 = ptr->CM_Data.K22;
		cmrgb2rgb_tab2_data_2_reg.k23 = ptr->CM_Data.K23;
		cmrgb2rgb_tab2_data_3_reg.k31 = ptr->CM_Data.K31;
		cmrgb2rgb_tab2_data_3_reg.k32 = ptr->CM_Data.K32;
		cmrgb2rgb_tab2_data_4_reg.k33 = ptr->CM_Data.K33;

		/* output offset*/
		cmrgb2rgb_tab2_out_offset_0_reg.roffset = ptr->CM_OutOffset.ROffset;
		cmrgb2rgb_tab2_out_offset_0_reg.goffset = ptr->CM_OutOffset.GOffset;
		cmrgb2rgb_tab2_out_offset_1_reg.boffset = ptr->CM_OutOffset.BOffset;

		IoReg_Write32(COLORMAP_D_CMRGB2RGB_Control_reg, cmrgb2rgb_control_reg.regValue);
		IoReg_Write32(COLORMAP_D_CMRGB2RGB_Tab2_Data_In_Offset_0_reg, cmrgb2rgb_tab2_data_in_offset_0_reg.regValue);
		IoReg_Write32(COLORMAP_D_CMRGB2RGB_Tab2_Data_In_Offset_1_reg, cmrgb2rgb_tab2_data_in_offset_1_reg.regValue);
		IoReg_Write32(COLORMAP_D_CMRGB2RGB_Tab2_Data_0_reg, cmrgb2rgb_tab2_data_0_reg.regValue);
		IoReg_Write32(COLORMAP_D_CMRGB2RGB_Tab2_Data_1_reg, cmrgb2rgb_tab2_data_1_reg.regValue);
		IoReg_Write32(COLORMAP_D_CMRGB2RGB_Tab2_Data_2_reg, cmrgb2rgb_tab2_data_2_reg.regValue);
		IoReg_Write32(COLORMAP_D_CMRGB2RGB_Tab2_Data_3_reg, cmrgb2rgb_tab2_data_3_reg.regValue);
		IoReg_Write32(COLORMAP_D_CMRGB2RGB_Tab2_Data_4_reg, cmrgb2rgb_tab2_data_4_reg.regValue);
		IoReg_Write32(COLORMAP_D_CMRGB2RGB_Tab2_Out_offset_0_reg, cmrgb2rgb_tab2_out_offset_0_reg.regValue);
		IoReg_Write32(COLORMAP_D_CMRGB2RGB_Tab2_Out_offset_1_reg, cmrgb2rgb_tab2_out_offset_1_reg.regValue);
	}
#endif
#endif
}

/*LUT_Ctrl
0: bypass
1: enable for main+sub+overlap
2: enable for main+overlap
*/
void drvif_color_D_3dLUT(unsigned char LUT_Ctrl, unsigned int *pArray)//flora@20150617
{
	unsigned short ii, cnt;
	unsigned char B,G,R;
	unsigned char status;
	unsigned int	baseAddress;
	unsigned char EN_status;

	c3dlut_c3dlut_lut_ctrl0_RBUS c3dlut_lut_ctrl0_REG;
	c3dlut_c3dlut_lut_ctrl_RBUS c3dlut_lut_ctr_REG;

	c3dlut_lut_ctr_REG.regValue = IoReg_Read32(C3DLUT_C3DLUT_LUT_CTRL_reg);
	EN_status = c3dlut_lut_ctr_REG.c3dlut_ctrl;
	c3dlut_lut_ctr_REG.c3dlut_ctrl = 0;
	IoReg_Write32(C3DLUT_C3DLUT_LUT_CTRL_reg, c3dlut_lut_ctr_REG.regValue);	//disable 3D LUT

	if(LUT_Ctrl==0)
		return;
	ii=0;

	for(B=0; B < 9; B++ ) {
		for( G=0; G < 9; G++) {
			c3dlut_lut_ctrl0_REG.regValue = IoReg_Read32(C3DLUT_C3DLUT_LUT_CTRL0_reg);
			c3dlut_lut_ctrl0_REG.lut_rw_sel = 1;//enable firmware to write table
			c3dlut_lut_ctrl0_REG.lut_rw_adr= (B<<4)+G;
			c3dlut_lut_ctrl0_REG.hw_fw_priority_opt = 0;
			IoReg_Write32(C3DLUT_C3DLUT_LUT_CTRL0_reg, c3dlut_lut_ctrl0_REG.regValue);

			baseAddress=C3DLUT_C3DLUT_LUT_WR_DATA_1_reg;
			for( R=0 ; R < 9 ; R++)
			{
				IoReg_Write32(baseAddress, pArray[(2*B)*289*2 + (2*G)*17*2 + (4*R)]);//d0 d1
				//ii++;
				baseAddress+=4;
				IoReg_Write32(baseAddress, pArray[(2*B)*289*2 + (2*G)*17*2 + (4*R) + 1]);//d2
				//ii++;
				baseAddress+=4;
			}

			c3dlut_lut_ctrl0_REG.regValue = IoReg_Read32(C3DLUT_C3DLUT_LUT_CTRL0_reg);
			c3dlut_lut_ctrl0_REG.lut_write_en = 1;//write table
			c3dlut_lut_ctrl0_REG.lut_read_en = 0;
			IoReg_Write32(C3DLUT_C3DLUT_LUT_CTRL0_reg, c3dlut_lut_ctrl0_REG.regValue);

			status = 1;
			cnt = 10000;
			while( (cnt--) && status)//wait for finishing writing
			{
				c3dlut_lut_ctrl0_REG.regValue = IoReg_Read32(C3DLUT_C3DLUT_LUT_CTRL0_reg);
				status = c3dlut_lut_ctrl0_REG.lut_write_en;
			}
		}
	}

	c3dlut_lut_ctrl0_REG.regValue = IoReg_Read32(C3DLUT_C3DLUT_LUT_CTRL0_reg);
	c3dlut_lut_ctrl0_REG.lut_rw_sel = 0;//disable firmware access
	IoReg_Write32(C3DLUT_C3DLUT_LUT_CTRL0_reg, c3dlut_lut_ctrl0_REG.regValue);

	c3dlut_lut_ctr_REG.regValue = IoReg_Read32(C3DLUT_C3DLUT_LUT_CTRL_reg);
	if (LUT_Ctrl <= 2)
		c3dlut_lut_ctr_REG.c3dlut_ctrl = LUT_Ctrl;
	else
		c3dlut_lut_ctr_REG.c3dlut_ctrl = EN_status;
	//fwif_color_WaitFor_DEN_STOP_UZUDTG();
	IoReg_Write32(C3DLUT_C3DLUT_LUT_CTRL_reg, c3dlut_lut_ctr_REG.regValue);

}

void drvif_color_D_3dLUT_Enable(unsigned char LUT_Ctrl)
{
	c3dlut_c3dlut_lut_ctrl_RBUS c3dlut_lut_ctr_REG;
	c3dlut_lut_ctr_REG.regValue = IoReg_Read32(C3DLUT_C3DLUT_LUT_CTRL_reg);
	c3dlut_lut_ctr_REG.c3dlut_ctrl = LUT_Ctrl;
	IoReg_Write32(C3DLUT_C3DLUT_LUT_CTRL_reg, c3dlut_lut_ctr_REG.regValue);	//disable 3D LUT
}

void drvif_color_Read_D_3dLUT(unsigned char *LUT_Ctrl, unsigned int *pArray)
{
	unsigned short ii, cnt;
	unsigned char B,G,R;
	unsigned char status;
	unsigned int baseAddress;
	c3dlut_c3dlut_lut_ctrl0_RBUS c3dlut_lut_ctrl0_REG;
	c3dlut_c3dlut_lut_ctrl_RBUS c3dlut_lut_ctr_REG;

	c3dlut_lut_ctr_REG.regValue = IoReg_Read32(C3DLUT_C3DLUT_LUT_CTRL_reg);
	*LUT_Ctrl = c3dlut_lut_ctr_REG.c3dlut_ctrl;
	c3dlut_lut_ctr_REG.c3dlut_ctrl = 0;
	IoReg_Write32(C3DLUT_C3DLUT_LUT_CTRL_reg, c3dlut_lut_ctr_REG.regValue);	//disable 3D LUT

	ii=0;

	for(B=0; B < 9 ; B++ )
		for( G=0; G < 9  ; G++)
		{
			c3dlut_lut_ctrl0_REG.regValue = IoReg_Read32(C3DLUT_C3DLUT_LUT_CTRL0_reg);
			c3dlut_lut_ctrl0_REG.lut_rw_sel = 2;//enable firmware to write table
			c3dlut_lut_ctrl0_REG.lut_rw_adr = (B<<4) + G;
			c3dlut_lut_ctrl0_REG.hw_fw_priority_opt = 0;
			IoReg_Write32(C3DLUT_C3DLUT_LUT_CTRL0_reg, c3dlut_lut_ctrl0_REG.regValue);

			c3dlut_lut_ctrl0_REG.regValue = IoReg_Read32(C3DLUT_C3DLUT_LUT_CTRL0_reg);
			c3dlut_lut_ctrl0_REG.lut_write_en = 0;//write table
			c3dlut_lut_ctrl0_REG.lut_read_en = 1;
			IoReg_Write32(C3DLUT_C3DLUT_LUT_CTRL0_reg, c3dlut_lut_ctrl0_REG.regValue);

			cnt = 10000;
			status = 1;
			while((cnt--) && status)//wait for finishing writing
			{
				c3dlut_lut_ctrl0_REG.regValue = IoReg_Read32(C3DLUT_C3DLUT_LUT_CTRL0_reg);
				status = c3dlut_lut_ctrl0_REG.lut_read_en;
			}

			baseAddress = C3DLUT_C3DLUT_LUT_RD_DATA_1_reg;
			for( R=0 ; R < 9 ; R++)
			{
				pArray[(2*B)*289*2 + (2*G)*17*2 + (4*R)] = IoReg_Read32(baseAddress);//d0 d1
				//ii++;
				baseAddress+=4;
				pArray[(2*B)*289*2 + (2*G)*17*2 + (4*R) + 1] = IoReg_Read32(baseAddress);//d2
				//ii++;
				baseAddress+=4;
			}
		}

	c3dlut_lut_ctrl0_REG.regValue = IoReg_Read32(C3DLUT_C3DLUT_LUT_CTRL0_reg);
	c3dlut_lut_ctrl0_REG.lut_rw_sel = 0;//disable firmware access
	IoReg_Write32(C3DLUT_C3DLUT_LUT_CTRL0_reg, c3dlut_lut_ctrl0_REG.regValue);

	/* restore */
	c3dlut_lut_ctr_REG.regValue = IoReg_Read32(C3DLUT_C3DLUT_LUT_CTRL_reg);
	c3dlut_lut_ctr_REG.c3dlut_ctrl = *LUT_Ctrl;
	IoReg_Write32(C3DLUT_C3DLUT_LUT_CTRL_reg, c3dlut_lut_ctr_REG.regValue);	//disable 3D LUT
}

void drvif_color_set_Vivid_Color_Enable(unsigned char ucEnable)
{
	color_d_vc_global_ctrl_RBUS			d_vc_global_ctrl_REG;
	d_vc_global_ctrl_REG.regValue = IoReg_Read32(COLOR_D_VC_Global_CTRL_reg);

	d_vc_global_ctrl_REG.m_vc_en = ucEnable;
	d_vc_global_ctrl_REG.write_enable_11 = 1;

	IoReg_Write32(COLOR_D_VC_Global_CTRL_reg, 	d_vc_global_ctrl_REG.regValue);
}

void drvif_color_set_sub_Vivid_Color_Enable(unsigned char ucEnable)
{
#ifdef VIP_CONFIG_DUAL_CHANNEL

	color_d_vc_global_ctrl_RBUS			d_vc_global_ctrl_REG;
	d_vc_global_ctrl_REG.regValue = IoReg_Read32(COLOR_D_VC_Global_CTRL_reg);
	d_vc_global_ctrl_REG.s_vc_en = ucEnable;
	IoReg_Write32(COLOR_D_VC_Global_CTRL_reg, 	d_vc_global_ctrl_REG.regValue);
#endif
}

void drvif_color_disable_VIP()
{

	/*=== i-domain====*/

	/*== main ==*/
	IoReg_ClearBits(0xb8025100,_BIT0);
	IoReg_ClearBits(0xb8023834,_BIT0);
	IoReg_ClearBits(0xb8023600,_BIT4);
	IoReg_ClearBits(0xb8023600,_BIT5);
	IoReg_ClearBits(0xb8023600,_BIT6);
	IoReg_ClearBits(0xb80241a0,_BIT0);
	IoReg_ClearBits(0xb80241a0,_BIT1);
	IoReg_ClearBits(0xb80231d4,_BIT0);
	IoReg_ClearBits(0xb8025004,_BIT2);
	IoReg_ClearBits(0xb8025004,_BIT1);
	IoReg_ClearBits(0xb8023100,_BIT26);
	IoReg_ClearBits(0xb802ad60,_BIT0);

#ifdef VIP_CONFIG_DUAL_CHANNEL
	/*== sub ==*/
	IoReg_ClearBits(0xb8022670,_BIT4);
	IoReg_ClearBits(0xb802310c,_BIT26);
	IoReg_ClearBits(0xb8022670,_BIT5);
	IoReg_ClearBits(0xb8022670,_BIT6);
	IoReg_ClearBits(0xb8022670,_BIT5);
	IoReg_ClearBits(0xb8022670,_BIT6);
#endif

	/*===d-domain==*/
	IoReg_ClearBits(0xb80290c4,_BIT0);
	IoReg_ClearBits(0xb8029038,_BIT16);
	IoReg_ClearBits(0xb802b950,_BIT0);

	IoReg_D_domain_ClearBits(COLOR_D_VC_Global_CTRL_reg,COLOR_D_VC_Global_CTRL_m_dcti_en_mask);
	IoReg_ClearBits(0xb8029040,_BIT4);
	IoReg_D_domain_ClearBits(COLOR_D_VC_Global_CTRL_reg,COLOR_D_VC_Global_CTRL_m_sharp_en_mask);
	IoReg_D_domain_ClearBits(COLOR_D_VC_Global_CTRL_reg,COLOR_D_VC_Global_CTRL_dcc_en_mask);
	IoReg_D_domain_ClearBits(COLOR_D_VC_Global_CTRL_reg,COLOR_D_VC_Global_CTRL_m_icm_en_mask);
	IoReg_ClearBits(0xb802c000,_BIT0);
	IoReg_ClearBits(0xb802c000,_BIT1);
	//IoReg_ClearBits(0xb802c108,_BIT6); /*Main gamma t1*/
	IoReg_ClearBits(0xb802c108,_BIT7);
	IoReg_ClearBits(0xb802c500,_BIT5);
	IoReg_D_domain_ClearBits(COLOR_D_VC_Global_CTRL_reg,COLOR_D_VC_Global_CTRL_m_edgesmooth_en_mask);
	IoReg_ClearBits(0xb802c500,_BIT4);


#ifdef VIP_CONFIG_DUAL_CHANNEL
	/*== sub ==*/
	IoReg_ClearBits(COLOR_D_VC_Global_CTRL_reg,_BIT17);
	IoReg_ClearBits(0xb802c108,_BIT4);
	IoReg_ClearBits(0xb802c108,_BIT5);
	IoReg_ClearBits(COLOR_D_VC_Global_CTRL_reg,_BIT19);
	IoReg_ClearBits(COLOR_D_VC_Global_CTRL_reg,_BIT18);
	IoReg_ClearBits(0xb802c000,_BIT2);
	IoReg_ClearBits(0xb802c000,_BIT3);
#endif



}

void drvif_color_set_color_temp(unsigned char enable, unsigned short Red_Con, unsigned short Green_Con, unsigned short Blue_Con,
	short Red_Bri, short Green_Bri, short Blue_Bri)
 {
return;
#if 0	// mac5 colortmp fix me
	color_temp_color_temp_ctrl_RBUS		color_temp_ctrl_REG;
	color_temp_color_temp_contrast_0_RBUS	color_temp_contrast_0_REG;
	color_temp_color_temp_contrast_1_RBUS	color_temp_contrast_1_REG;
	color_temp_color_temp_brightness_0_RBUS	color_temp_brightness_0_REG;
	color_temp_color_temp_brightness_1_RBUS	color_temp_brightness_1_REG;

	color_temp_ctrl_REG.regValue = IoReg_Read32(COLOR_TEMP_Color_Temp_CTRL_reg);
	color_temp_contrast_0_REG.regValue = IoReg_Read32(COLOR_TEMP_Color_Temp_Contrast_0_reg);
	color_temp_contrast_1_REG.regValue = IoReg_Read32(COLOR_TEMP_Color_Temp_Contrast_1_reg);
	color_temp_brightness_0_REG.regValue = IoReg_Read32(COLOR_TEMP_Color_Temp_Brightness_0_reg);
	color_temp_brightness_1_REG.regValue = IoReg_Read32(COLOR_TEMP_Color_Temp_Brightness_1_reg);

	color_temp_ctrl_REG.color_temp_en = enable;
	color_temp_contrast_0_REG.contrast_r = Red_Con;
	color_temp_contrast_0_REG.contrast_g = Green_Con;
	color_temp_contrast_1_REG.contrast_b = Blue_Con;
	color_temp_brightness_0_REG.bright_r = Red_Bri;
	color_temp_brightness_0_REG.bright_g = Green_Bri;
	color_temp_brightness_1_REG.bright_b = Blue_Bri;

	IoReg_Write32(COLOR_TEMP_Color_Temp_CTRL_reg, color_temp_ctrl_REG.regValue);
	IoReg_Write32(COLOR_TEMP_Color_Temp_Contrast_0_reg, color_temp_contrast_0_REG.regValue);
	IoReg_Write32(COLOR_TEMP_Color_Temp_Contrast_1_reg, color_temp_contrast_1_REG.regValue);
	IoReg_Write32(COLOR_TEMP_Color_Temp_Brightness_0_reg, color_temp_brightness_0_REG.regValue);
	IoReg_Write32(COLOR_TEMP_Color_Temp_Brightness_1_reg, color_temp_brightness_1_REG.regValue);
#endif
}

void drvif_color_inv_gamma_enable(unsigned char display, unsigned char enable, unsigned char useRPC)
{
  	//_system_setting_info *VIP_system_info_structure_table = (_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_system_info_structure);
  	_RPC_system_setting_info *VIP_RPC_system_info_structure_table = NULL;
  	VIP_RPC_system_info_structure_table = (_RPC_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_RPC_system_info_structure);
	if(VIP_RPC_system_info_structure_table == NULL){
			VIPprintf("[%s:%d] Warning here!! RPC_system_info=NULL! \n",__FILE__, __LINE__);
			return;
	}

	if (VIP_RPC_system_info_structure_table->HDR_info.Ctrl_Item[TV006_HDR_DEMO_EN] == 1)
		return;


	if(useRPC && display == SLR_MAIN_DISPLAY) {
		int ret;
		//drvif_color_set_video_fw_irq();

		if (0 != (ret = Scaler_SendRPC(SCALERIOC_GAMMA_ENABLE_PATCH, enable, 1))){
			VIPprintf("ret = %d, SCALERIOC_GAMMA_ENABLE_PATCH fail !!!\n", ret);
		}

	} else {
		inv_gamma_inv_gamma_ctrl_2_RBUS inv_gamma_ctrl_2_REG;

		inv_gamma_ctrl_2_REG.regValue = IoReg_Read32(INV_GAMMA_INV_GAMMA_CTRL_2_reg);

		if (display == SLR_MAIN_DISPLAY) {
			inv_gamma_ctrl_2_REG.inv_gamma_m_tab_sel = enable?1:0; /* use tab-1*/
		}
#ifdef CONFIG_DUAL_CHANNEL  /* There are two channels*/
#ifdef VIP_CONFIG_DUAL_CHANNEL // henry 161214
		else {
			// inv_gamma_ctrl_2_REG.inv_gamma_s_tab_sel = enable?1:0; /* sub gamma use tab-1 same to m_tab	rock_rau 2015/09/17 [WOSQRTK-1187]*/ //jyyang20161215
		}
#endif
#endif
		IoReg_Write32(INV_GAMMA_INV_GAMMA_CTRL_2_reg, inv_gamma_ctrl_2_REG.regValue);
	}
}

void drvif_color_gamma_enable(unsigned char display, unsigned char enable, unsigned char useRPC)
{
	if(useRPC && display == SLR_MAIN_DISPLAY) {
		//int ret;
		//drvif_color_set_video_fw_irq();

		//if (0 != (ret = Scaler_SendRPC(SCALERIOC_GAMMA_ENABLE_PATCH, enable, 1))){
		//	VIPprintf("ret = %d, SCALERIOC_GAMMA_ENABLE_PATCH fail !!!\n", ret);
		//}

	} else {
		gamma_gamma_ctrl_2_RBUS gamma_gamma_ctrl_2_RBUS_reg;

		gamma_gamma_ctrl_2_RBUS_reg.regValue = IoReg_Read32(GAMMA_GAMMA_CTRL_2_reg);

		if (display == SLR_MAIN_DISPLAY) {
			gamma_gamma_ctrl_2_RBUS_reg.gamma_m_tab_sel = enable?1:0; /* use tab-1*/
		}
#ifdef CONFIG_DUAL_CHANNEL  /* There are two channels*/
#ifdef VIP_CONFIG_DUAL_CHANNEL // henry 161214
		else {
			//gamma_gamma_ctrl_2_RBUS_reg.gamma_s_tab_sel = enable?1:0; /* sub gamma use tab-1 same to m_tab	rock_rau 2015/09/17 [WOSQRTK-1187]*/ //jyyang20161215
		}
#endif
#endif
		IoReg_Write32(GAMMA_GAMMA_CTRL_2_reg, gamma_gamma_ctrl_2_RBUS_reg.regValue);
	}
}
#ifdef CONFIG_HW_SUPPORT_MEMC
void drvif_color_set_MEMC_dither()
{
	rtd_outl(MEMC_MUX_MEMC_MUX_DI_CTRL_reg, 0x00000030);
	rtd_outl(MEMC_MUX_MEMC_MUX_DI_SEQUENCE_TABLE_Red_00_07_reg, 0xa3e680ad);
	rtd_outl(MEMC_MUX_MEMC_MUX_DI_SEQUENCE_TABLE_Red_08_15_reg, 0xb92d479e);
	rtd_outl(MEMC_MUX_MEMC_MUX_DI_SEQUENCE_TABLE_Red_16_23_reg, 0x5f1c7412);
	rtd_outl(MEMC_MUX_MEMC_MUX_DI_SEQUENCE_TABLE_Red_24_31_reg, 0x856cb0f3);
	rtd_outl(MEMC_MUX_MEMC_MUX_DI_SEQUENCE_TABLE_Green_00_07_reg, 0x7412b92d);
	rtd_outl(MEMC_MUX_MEMC_MUX_DI_SEQUENCE_TABLE_Green_08_15_reg, 0xb0f35f1c);
	rtd_outl(MEMC_MUX_MEMC_MUX_DI_SEQUENCE_TABLE_Green_16_23_reg, 0x680a856c);
	rtd_outl(MEMC_MUX_MEMC_MUX_DI_SEQUENCE_TABLE_Green_24_31_reg, 0xd479ea3e);
	rtd_outl(MEMC_MUX_MEMC_MUX_DI_SEQUENCE_TABLE_Blue_00_07_reg, 0xf3e680ad);
	rtd_outl(MEMC_MUX_MEMC_MUX_DI_SEQUENCE_TABLE_Blue_08_15_reg, 0xea856cb0);
	rtd_outl(MEMC_MUX_MEMC_MUX_DI_SEQUENCE_TABLE_Blue_16_23_reg, 0x2b92d479);
	rtd_outl(MEMC_MUX_MEMC_MUX_DI_SEQUENCE_TABLE_Blue_24_31_reg, 0x35f1c741);
	rtd_outl(MEMC_MUX_MEMC_MUX_DI_Memc_Mux_Dither_TABLE_Red_00_reg, 0x0000c204);
	rtd_outl(MEMC_MUX_MEMC_MUX_DI_Memc_Mux_Dither_TABLE_Red_01_reg, 0x00286382);
	rtd_outl(MEMC_MUX_MEMC_MUX_DI_Memc_Mux_Dither_TABLE_Red_02_reg, 0x003c31cb);
	rtd_outl(MEMC_MUX_MEMC_MUX_DI_Memc_Mux_Dither_TABLE_Red_03_reg, 0x0014904d);
	rtd_outl(MEMC_MUX_MEMC_MUX_DI_Memc_Mux_Dither_TABLE_Red_04_reg, 0x000cf2c7);
	rtd_outl(MEMC_MUX_MEMC_MUX_DI_Memc_Mux_Dither_TABLE_Red_05_reg, 0x00245341);
	rtd_outl(MEMC_MUX_MEMC_MUX_DI_Memc_Mux_Dither_TABLE_Red_06_reg, 0x00300108);
	rtd_outl(MEMC_MUX_MEMC_MUX_DI_Memc_Mux_Dither_TABLE_Red_07_reg, 0x0018a08e);
	rtd_outl(MEMC_MUX_MEMC_MUX_DI_Memc_Mux_Dither_TABLE_Red_08_reg, 0x0008e286);
	rtd_outl(MEMC_MUX_MEMC_MUX_DI_Memc_Mux_Dither_TABLE_Red_09_reg, 0x002c73c3);
	rtd_outl(MEMC_MUX_MEMC_MUX_DI_Memc_Mux_Dither_TABLE_Red_0A_reg, 0x00341149);
	rtd_outl(MEMC_MUX_MEMC_MUX_DI_Memc_Mux_Dither_TABLE_Red_0B_reg, 0x0010800c);
	rtd_outl(MEMC_MUX_MEMC_MUX_DI_Memc_Mux_Dither_TABLE_Red_0C_reg, 0x0004d245);
	rtd_outl(MEMC_MUX_MEMC_MUX_DI_Memc_Mux_Dither_TABLE_Red_0D_reg, 0x00204300);
	rtd_outl(MEMC_MUX_MEMC_MUX_DI_Memc_Mux_Dither_TABLE_Red_0E_reg, 0x0038218a);
	rtd_outl(MEMC_MUX_MEMC_MUX_DI_Memc_Mux_Dither_TABLE_Red_0F_reg, 0x001cb0cf);
	rtd_outl(MEMC_MUX_MEMC_MUX_DI_Memc_Mux_Dither_TABLE_Green_00_reg, 0x00286382);
	rtd_outl(MEMC_MUX_MEMC_MUX_DI_Memc_Mux_Dither_TABLE_Green_01_reg, 0x003c31cb);
	rtd_outl(MEMC_MUX_MEMC_MUX_DI_Memc_Mux_Dither_TABLE_Green_02_reg, 0x0014904d);
	rtd_outl(MEMC_MUX_MEMC_MUX_DI_Memc_Mux_Dither_TABLE_Green_03_reg, 0x0000c204);
	rtd_outl(MEMC_MUX_MEMC_MUX_DI_Memc_Mux_Dither_TABLE_Green_04_reg, 0x00245341);
	rtd_outl(MEMC_MUX_MEMC_MUX_DI_Memc_Mux_Dither_TABLE_Green_05_reg, 0x00300108);
	rtd_outl(MEMC_MUX_MEMC_MUX_DI_Memc_Mux_Dither_TABLE_Green_06_reg, 0x0018a08e);
	rtd_outl(MEMC_MUX_MEMC_MUX_DI_Memc_Mux_Dither_TABLE_Green_07_reg, 0x000cf2c7);
	rtd_outl(MEMC_MUX_MEMC_MUX_DI_Memc_Mux_Dither_TABLE_Green_08_reg, 0x002c73c3);
	rtd_outl(MEMC_MUX_MEMC_MUX_DI_Memc_Mux_Dither_TABLE_Green_09_reg, 0x00341149);
	rtd_outl(MEMC_MUX_MEMC_MUX_DI_Memc_Mux_Dither_TABLE_Green_0A_reg, 0x0010800c);
	rtd_outl(MEMC_MUX_MEMC_MUX_DI_Memc_Mux_Dither_TABLE_Green_0B_reg, 0x0008e286);
	rtd_outl(MEMC_MUX_MEMC_MUX_DI_Memc_Mux_Dither_TABLE_Green_0C_reg, 0x00204300);
	rtd_outl(MEMC_MUX_MEMC_MUX_DI_Memc_Mux_Dither_TABLE_Green_0D_reg, 0x0038218a);
	rtd_outl(MEMC_MUX_MEMC_MUX_DI_Memc_Mux_Dither_TABLE_Green_0E_reg, 0x001cb0cf);
	rtd_outl(MEMC_MUX_MEMC_MUX_DI_Memc_Mux_Dither_TABLE_Green_0F_reg, 0x0004d245);
	rtd_outl(MEMC_MUX_MEMC_MUX_DI_Memc_Mux_Dither_TABLE_Blue_00_reg, 0x003c31cb);
	rtd_outl(MEMC_MUX_MEMC_MUX_DI_Memc_Mux_Dither_TABLE_Blue_01_reg, 0x0014904d);
	rtd_outl(MEMC_MUX_MEMC_MUX_DI_Memc_Mux_Dither_TABLE_Blue_02_reg, 0x0000c204);
	rtd_outl(MEMC_MUX_MEMC_MUX_DI_Memc_Mux_Dither_TABLE_Blue_03_reg, 0x00286382);
	rtd_outl(MEMC_MUX_MEMC_MUX_DI_Memc_Mux_Dither_TABLE_Blue_04_reg, 0x00300108);
	rtd_outl(MEMC_MUX_MEMC_MUX_DI_Memc_Mux_Dither_TABLE_Blue_05_reg, 0x0018a08e);
	rtd_outl(MEMC_MUX_MEMC_MUX_DI_Memc_Mux_Dither_TABLE_Blue_06_reg, 0x000cf2c7);
	rtd_outl(MEMC_MUX_MEMC_MUX_DI_Memc_Mux_Dither_TABLE_Blue_07_reg, 0x00245341);
	rtd_outl(MEMC_MUX_MEMC_MUX_DI_Memc_Mux_Dither_TABLE_Blue_08_reg, 0x00341149);
	rtd_outl(MEMC_MUX_MEMC_MUX_DI_Memc_Mux_Dither_TABLE_Blue_09_reg, 0x0010800c);
	rtd_outl(MEMC_MUX_MEMC_MUX_DI_Memc_Mux_Dither_TABLE_Blue_0A_reg, 0x0008e286);
	rtd_outl(MEMC_MUX_MEMC_MUX_DI_Memc_Mux_Dither_TABLE_Blue_0B_reg, 0x002c73c3);
	rtd_outl(MEMC_MUX_MEMC_MUX_DI_Memc_Mux_Dither_TABLE_Blue_0C_reg, 0x0038218a);
	rtd_outl(MEMC_MUX_MEMC_MUX_DI_Memc_Mux_Dither_TABLE_Blue_0D_reg, 0x001cb0cf);
	rtd_outl(MEMC_MUX_MEMC_MUX_DI_Memc_Mux_Dither_TABLE_Blue_0E_reg, 0x0004d245);
	rtd_outl(MEMC_MUX_MEMC_MUX_DI_Memc_Mux_Dither_TABLE_Blue_0F_reg, 0x00204300);
	rtd_outl(MEMC_MUX_MEMC_MUX_DI_Temporal_offset_reg, 0xe4e4e4e4);

	#if 0
	rtd_outl(0xb802e940, 0x00000030);
	rtd_outl(0xb802e944, 0xa3e680ad);
	rtd_outl(0xb802e948, 0xb92d479e);
	rtd_outl(0xb802e94c, 0x5f1c7412);
	rtd_outl(0xb802e950, 0x856cb0f3);
	rtd_outl(0xb802e954, 0x7412b92d);
	rtd_outl(0xb802e958, 0xb0f35f1c);
	rtd_outl(0xb802e95c, 0x680a856c);
	rtd_outl(0xb802e960, 0xd479ea3e);
	rtd_outl(0xb802e964, 0xf3e680ad);
	rtd_outl(0xb802e968, 0xea856cb0);
	rtd_outl(0xb802e96c, 0x2b92d479);
	rtd_outl(0xb802e970, 0x35f1c741);
	rtd_outl(0xb802e974, 0x0000c204);
	rtd_outl(0xb802e978, 0x00286382);
	rtd_outl(0xb802e97c, 0x003c31cb);
	rtd_outl(0xb802e980, 0x0014904d);
	rtd_outl(0xb802e984, 0x000cf2c7);
	rtd_outl(0xb802e988, 0x00245341);
	rtd_outl(0xb802e98c, 0x00300108);
	rtd_outl(0xb802e990, 0x0018a08e);
	rtd_outl(0xb802e994, 0x0008e286);
	rtd_outl(0xb802e998, 0x002c73c3);
	rtd_outl(0xb802e99c, 0x00341149);
	rtd_outl(0xb802e9a0, 0x0010800c);
	rtd_outl(0xb802e9a4, 0x0004d245);
	rtd_outl(0xb802e9a8, 0x00204300);
	rtd_outl(0xb802e9ac, 0x0038218a);
	rtd_outl(0xb802e9b0, 0x001cb0cf);
	rtd_outl(0xb802e9b4, 0x00286382);
	rtd_outl(0xb802e9b8, 0x003c31cb);
	rtd_outl(0xb802e9bc, 0x0014904d);
	rtd_outl(0xb802e9c0, 0x0000c204);
	rtd_outl(0xb802e9c4, 0x00245341);
	rtd_outl(0xb802e9c8, 0x00300108);
	rtd_outl(0xb802e9cc, 0x0018a08e);
	rtd_outl(0xb802e9d0, 0x000cf2c7);
	rtd_outl(0xb802e9d4, 0x002c73c3);
	rtd_outl(0xb802e9d8, 0x00341149);
	rtd_outl(0xb802e9dc, 0x0010800c);
	rtd_outl(0xb802e9e0, 0x0008e286);
	rtd_outl(0xb802e9e4, 0x00204300);
	rtd_outl(0xb802e9e8, 0x0038218a);
	rtd_outl(0xb802e9ec, 0x001cb0cf);
	rtd_outl(0xb802e9f0, 0x0004d245);
	rtd_outl(0xb802e9f4, 0x003c31cb);
	rtd_outl(0xb802e9f8, 0x0014904d);
	rtd_outl(0xb802e9fc, 0x0000c204);
	rtd_outl(0xb802ea00, 0x00286382);
	rtd_outl(0xb802ea04, 0x00300108);
	rtd_outl(0xb802ea08, 0x0018a08e);
	rtd_outl(0xb802ea0c, 0x000cf2c7);
	rtd_outl(0xb802ea10, 0x00245341);
	rtd_outl(0xb802ea14, 0x00341149);
	rtd_outl(0xb802ea18, 0x0010800c);
	rtd_outl(0xb802ea1c, 0x0008e286);
	rtd_outl(0xb802ea20, 0x002c73c3);
	rtd_outl(0xb802ea24, 0x0038218a);
	rtd_outl(0xb802ea28, 0x001cb0cf);
	rtd_outl(0xb802ea2c, 0x0004d245);
	rtd_outl(0xb802ea30, 0x00204300);
	rtd_outl(0xb802ea34, 0xe4e4e4e4);
	#endif
}
#endif

void drvif_set_main_dither()
{
	#if 0
    rtd_outl(0xb8022600, 0x00000438);

    rtd_outl(0xb8022604, 0x3705a2e4);
    rtd_outl(0xb8022608, 0xcb6931f6);
    rtd_outl(0xb802260c, 0xe6b0d21f);
    rtd_outl(0xb8022610, 0xc6871b45);
    rtd_outl(0xb8022614, 0x38c6b49e);
    rtd_outl(0xb8022618, 0x1b12dbd4);

    rtd_outl(0xb802261c, 0x30301212);
    rtd_outl(0xb8022620, 0x21210303);
    rtd_outl(0xb8022624, 0x30301212);
    rtd_outl(0xb8022628, 0x21210303);
    rtd_outl(0xb802262c, 0x30301212);
    rtd_outl(0xb8022630, 0x21210303);
    rtd_outl(0xb8022634, 0xe4e4e4e4);

	#endif

	//set table
	IoReg_Write32(MAIN_DITHER_I_Main_DITHER_SEQ_R_00_15_reg, 0x3705a2e4);
	IoReg_Write32(MAIN_DITHER_I_Main_DITHER_SEQ_R_16_31_reg, 0xcb6931f6);
	IoReg_Write32(MAIN_DITHER_I_Main_DITHER_SEQ_G_00_07_reg, 0xe6b0d21f);
	IoReg_Write32(MAIN_DITHER_I_Main_DITHER_SEQ_G_16_31_reg, 0xc6871b45);
	IoReg_Write32(MAIN_DITHER_I_Main_DITHER_SEQ_B_00_15_reg, 0x38c6b49e);
	IoReg_Write32(MAIN_DITHER_I_Main_DITHER_SEQ_B_16_31_reg, 0x1b12dbd4);
	IoReg_Write32(MAIN_DITHER_I_Main_DITHER_TB1_R_00_reg, 0x30301212);
	IoReg_Write32(MAIN_DITHER_I_Main_DITHER_TB1_R_02_reg, 0x21210303);
	IoReg_Write32(MAIN_DITHER_I_Main_DITHER_TB1_G_00_reg, 0x30301212);
	IoReg_Write32(MAIN_DITHER_I_Main_DITHER_TB1_G_02_reg, 0x21210303);
	IoReg_Write32(MAIN_DITHER_I_Main_DITHER_TB1_B_00_reg, 0x30301212);
	IoReg_Write32(MAIN_DITHER_I_Main_DITHER_TB1_B_02_reg, 0x21210303);
	IoReg_Write32(MAIN_DITHER_I_Main_DITHER_Temp_TB1_reg, 0xe4e4e4e4);

	//ch1_temporal_enable
	{
	main_dither_i_main_dither_ctrl1_RBUS main_dither_i_main_dither_ctrl1_RBUS_reg;
	main_dither_i_main_dither_ctrl1_RBUS_reg.regValue = IoReg_Read32(MAIN_DITHER_I_Main_DITHER_CTRL1_reg);
	main_dither_i_main_dither_ctrl1_RBUS_reg.ch1_dithering_table_select = 1;
	main_dither_i_main_dither_ctrl1_RBUS_reg.ch1_temporal_enable = 1;
	IoReg_Write32(MAIN_DITHER_I_Main_DITHER_CTRL1_reg, main_dither_i_main_dither_ctrl1_RBUS_reg.regValue);
	}

}

char drvif_DM2_Wait_DB_Apply(void)
{
	dm_hdr_double_buffer_ctrl_RBUS dm_double_buffer_ctrl_reg;
	UINT32 timeoutcnt = 0x062500;
	char ret = 0;
	// enable DM & Composer clock
	rtd_outl(SYS_REG_SYS_CLKEN1_reg, SYS_REG_SYS_CLKEN1_clken_dolby_dm_mask | SYS_REG_SYS_CLKEN1_clken_dolby_comp_mask | SYS_REG_SYS_CLKEN1_write_data_mask);

	while((DM_HDR_Double_Buffer_CTRL_get_dm_db_apply(IoReg_Read32(DM_HDR_Double_Buffer_CTRL_reg)) == 1) && (timeoutcnt > 10))
		timeoutcnt--;

	if (timeoutcnt <= 10) {
		ret = -1;
		rtd_printk(KERN_EMERG, TAG_NAME, "drvif_DM2_Wait_DB_Apply, wait Fail, time cnt=%d.\n", timeoutcnt);
	}

	return ret;
}

void drvif_DM2_EOTF_Set(unsigned int *EOTF_table32_R, unsigned int *EOTF_table32_G, unsigned int *EOTF_table32_B)
{
	UINT16 i;
	UINT32 timeoutcnt = 0x062500;
	UINT8 timeoutcnt_rw_addr =100;
	dm_hdr_eotf_lut_ctrl0_RBUS DM_HDR_EOTF_LUT_CTRL0_Reg;
	dm_hdr_eotf_lut_ctrl1_RBUS DM_HDR_EOTF_LUT_CTRL1_Reg;
	dm_hdr_eotf_lut_wr_data0_RBUS dm_hdr_eotf_lut_wr_data0_Reg;
	dm_hdr_eotf_lut_wr_data1_RBUS dm_hdr_eotf_lut_wr_data1_Reg;
	dm_hdr_eotf_lut_wr_data2_RBUS dm_hdr_eotf_lut_wr_data2_Reg;
	dm_hdr_eotf_lut_wr_data3_RBUS dm_hdr_eotf_lut_wr_data3_Reg;
	dm_hdr_eotf_lut_wr_data4_RBUS dm_hdr_eotf_lut_wr_data4_Reg;
	dm_hdr_eotf_lut_wr_data5_RBUS dm_hdr_eotf_lut_wr_data5_Reg;

#if 0
	for(i=0;i<timeoutcnt_rw_addr;i++) //switch read/write , address will clean to 0 (some time not work)
	{
		DM_HDR_EOTF_LUT_CTRL0_Reg.regValue = rtd_inl(DM_HDR_EOTF_LUT_CTRL0_reg);
		//write init
		DM_HDR_EOTF_LUT_CTRL0_Reg.regValue = rtd_inl(DM_HDR_EOTF_LUT_CTRL0_reg);
		DM_HDR_EOTF_LUT_CTRL0_Reg.eotf_lut_enable = 1;
		DM_HDR_EOTF_LUT_CTRL0_Reg.eotf_lut_rw_sel = 1;
		rtd_outl(DM_HDR_EOTF_LUT_CTRL0_reg, DM_HDR_EOTF_LUT_CTRL0_Reg.regValue);

		//Read init
		DM_HDR_EOTF_LUT_CTRL0_Reg.regValue = rtd_inl(DM_HDR_EOTF_LUT_CTRL0_reg);
		DM_HDR_EOTF_LUT_CTRL0_Reg.eotf_lut_enable = 1;
		DM_HDR_EOTF_LUT_CTRL0_Reg.eotf_lut_rw_sel = 2;
		rtd_outl(DM_HDR_EOTF_LUT_CTRL0_reg, DM_HDR_EOTF_LUT_CTRL0_Reg.regValue);

		DM_HDR_EOTF_LUT_CTRL1_Reg.regValue = rtd_inl(DM_HDR_EOTF_LUT_CTRL1_reg);

		if(DM_HDR_EOTF_LUT_CTRL1_Reg.eotf_lut_rw_addr!=0)
			rtd_printk(KERN_DEBUG, TAG_NAME, "PQ WARNING, Set HDR EOTF table wrong, rw_address not 0 ,times=%d",i);
		else
			break;

	}// read/write OE/EO table havt to check rw_address is 0
#endif
	/* hw issue, disable dm clk before r/w sel changing*/
	rtd_outl(SYS_REG_SYS_CLKEN1_reg, SYS_REG_SYS_CLKEN1_clken_dolby_dm_mask);
	timeoutcnt = 0x062500;
	/* waiting for clk disable*/
	while ((SYS_REG_SYS_CLKEN1_get_clken_dolby_dm(rtd_inl(SYS_REG_SYS_CLKEN1_reg)) == 1) && (timeoutcnt > 10))
		timeoutcnt --;
	if (timeoutcnt <= 10)
		rtd_printk(KERN_EMERG, TAG_NAME, "drvif_DM2_EOTF_Set, can't disable clk 0\n");

	//write init
	DM_HDR_EOTF_LUT_CTRL0_Reg.regValue = rtd_inl(DM_HDR_EOTF_LUT_CTRL0_reg);
	DM_HDR_EOTF_LUT_CTRL0_Reg.eotf_lut_enable = 1;
	DM_HDR_EOTF_LUT_CTRL0_Reg.eotf_lut_rw_sel = 1;
	rtd_outl(DM_HDR_EOTF_LUT_CTRL0_reg, DM_HDR_EOTF_LUT_CTRL0_Reg.regValue);

	/* enable dm clk*/
	rtd_outl(SYS_REG_SYS_CLKEN1_reg, SYS_REG_SYS_CLKEN1_clken_dolby_dm_mask | SYS_REG_SYS_CLKEN1_write_data_mask);
	timeoutcnt = 0x062500;
	/* waiting for clk disable*/
	while ((SYS_REG_SYS_CLKEN1_get_clken_dolby_dm(rtd_inl(SYS_REG_SYS_CLKEN1_reg)) == 0) && (timeoutcnt > 10)) {
		timeoutcnt --;
	}
	if (timeoutcnt <= 10)
		rtd_printk(KERN_EMERG, TAG_NAME, "drvif_DM2_EOTF_Set, can't en clk 0\n");

	/* hw issue for m5, reset sram manually.*/
	timeoutcnt = 0x062500;
	DM_HDR_EOTF_LUT_CTRL1_Reg.regValue = rtd_inl(DM_HDR_EOTF_LUT_CTRL1_reg);
	while((DM_HDR_EOTF_LUT_CTRL1_Reg.eotf_lut_rw_addr != 0) && (timeoutcnt > 10)) {
		DM_HDR_EOTF_LUT_CTRL1_Reg.eotf_lut_write_en = 1;
		rtd_outl(DM_HDR_EOTF_LUT_CTRL1_reg, DM_HDR_EOTF_LUT_CTRL1_Reg.regValue);
		do {
			timeoutcnt--;
		}while((DM_HDR_EOTF_LUT_CTRL1_get_eotf_lut_write_en(rtd_inl(DM_HDR_EOTF_LUT_CTRL1_reg)) == 1) && (timeoutcnt > 10));
		timeoutcnt--;
		DM_HDR_EOTF_LUT_CTRL1_Reg.regValue = rtd_inl(DM_HDR_EOTF_LUT_CTRL1_reg);

	};

	if (timeoutcnt <= 10) {
		rtd_printk(KERN_EMERG, TAG_NAME, "EOTF sRam Set, timeoutcnt=%d, retrun\n", timeoutcnt);
		return;
	}

	//data check
	for (i = 1; i < EOTF_size; i++)
	{
		if (EOTF_table32_R[i] < EOTF_table32_R[i - 1])
			{rtd_printk(KERN_DEBUG, TAG_NAME, "PQ WARNING, HDR EOTF table wrong, EOTF_table32_R[%d] = %d > EOTF_table32_R[%d] = %d\n", i - 1, EOTF_table32_R[i - 1], i, EOTF_table32_R[i]);}
		if (EOTF_table32_G[i] < EOTF_table32_G[i - 1])
			{rtd_printk(KERN_DEBUG, TAG_NAME, "PQ WARNING, HDR EOTF table wrong, EOTF_table32_G[%d] = %d > EOTF_table32_G[%d] = %d\n", i - 1, EOTF_table32_G[i - 1], i, EOTF_table32_G[i]);}
		if (EOTF_table32_B[i] < EOTF_table32_B[i - 1])
			{rtd_printk(KERN_DEBUG, TAG_NAME, "PQ WARNING, HDR EOTF table wrong, EOTF_table32_B[%d] = %d > EOTF_table32_B[%d] = %d\n", i - 1, EOTF_table32_B[i - 1], i, EOTF_table32_B[i]);}
	}

	timeoutcnt = 0x062500;
	//push data to SRAM
	i = 0;
	while(i < EOTF_size)
	{
		//data
		dm_hdr_eotf_lut_wr_data0_Reg.eotf_wr_lut_data0 = EOTF_table32_R[i];
		dm_hdr_eotf_lut_wr_data2_Reg.eotf_wr_lut_data2 = EOTF_table32_G[i];
		dm_hdr_eotf_lut_wr_data4_Reg.eotf_wr_lut_data4 = EOTF_table32_B[i];

		if (i + 1 < EOTF_size)		//data protect
		{
			dm_hdr_eotf_lut_wr_data1_Reg.eotf_wr_lut_data1 = EOTF_table32_R[i + 1];
			dm_hdr_eotf_lut_wr_data3_Reg.eotf_wr_lut_data3 = EOTF_table32_G[i + 1];
			dm_hdr_eotf_lut_wr_data5_Reg.eotf_wr_lut_data5 = EOTF_table32_B[i + 1];
		}

		rtd_outl(DM_HDR_EOTF_LUT_WR_DATA0_reg, dm_hdr_eotf_lut_wr_data0_Reg.regValue);
		rtd_outl(DM_HDR_EOTF_LUT_WR_DATA1_reg, dm_hdr_eotf_lut_wr_data1_Reg.regValue);
		rtd_outl(DM_HDR_EOTF_LUT_WR_DATA2_reg, dm_hdr_eotf_lut_wr_data2_Reg.regValue);
		rtd_outl(DM_HDR_EOTF_LUT_WR_DATA3_reg, dm_hdr_eotf_lut_wr_data3_Reg.regValue);
		rtd_outl(DM_HDR_EOTF_LUT_WR_DATA4_reg, dm_hdr_eotf_lut_wr_data4_Reg.regValue);
		rtd_outl(DM_HDR_EOTF_LUT_WR_DATA5_reg, dm_hdr_eotf_lut_wr_data5_Reg.regValue);

		//write
		DM_HDR_EOTF_LUT_CTRL1_Reg.regValue = rtd_inl(DM_HDR_EOTF_LUT_CTRL1_reg);
		DM_HDR_EOTF_LUT_CTRL1_Reg.eotf_lut_read_en = 0;
		DM_HDR_EOTF_LUT_CTRL1_Reg.eotf_lut_write_en = 1;
		rtd_outl(DM_HDR_EOTF_LUT_CTRL1_reg, DM_HDR_EOTF_LUT_CTRL1_Reg.regValue);
		do
		{
			timeoutcnt--;
			DM_HDR_EOTF_LUT_CTRL1_Reg.regValue = rtd_inl(DM_HDR_EOTF_LUT_CTRL1_reg);
		}
		while(DM_HDR_EOTF_LUT_CTRL1_Reg.eotf_lut_write_en && timeoutcnt > 10);

		i = i + 2;
	}

	/* hw issue, disable dm clk before r/w sel changing*/
	rtd_outl(SYS_REG_SYS_CLKEN1_reg, SYS_REG_SYS_CLKEN1_clken_dolby_dm_mask);
	timeoutcnt = 0x062500;
	/* waiting for clk disable*/
	while ((SYS_REG_SYS_CLKEN1_get_clken_dolby_dm(rtd_inl(SYS_REG_SYS_CLKEN1_reg)) == 1) && (timeoutcnt > 10))
		timeoutcnt --;
	if (timeoutcnt <= 10)
		rtd_printk(KERN_EMERG, TAG_NAME, "drvif_DM2_EOTF_Set, can't disable clk 1\n");

	//write end
	DM_HDR_EOTF_LUT_CTRL0_Reg.regValue = rtd_inl(DM_HDR_EOTF_LUT_CTRL0_reg);
	DM_HDR_EOTF_LUT_CTRL0_Reg.eotf_lut_enable = 1;
	DM_HDR_EOTF_LUT_CTRL0_Reg.eotf_lut_rw_sel = 0;
	rtd_outl(DM_HDR_EOTF_LUT_CTRL0_reg, DM_HDR_EOTF_LUT_CTRL0_Reg.regValue);

	/* enable dm clk*/
	rtd_outl(SYS_REG_SYS_CLKEN1_reg, SYS_REG_SYS_CLKEN1_clken_dolby_dm_mask | SYS_REG_SYS_CLKEN1_write_data_mask);
	timeoutcnt = 0x062500;
	/* waiting for clk disable*/
	while ((SYS_REG_SYS_CLKEN1_get_clken_dolby_dm(rtd_inl(SYS_REG_SYS_CLKEN1_reg)) == 0) && (timeoutcnt > 10))
		timeoutcnt --;
	if (timeoutcnt <= 10)
		rtd_printk(KERN_EMERG, TAG_NAME, "drvif_DM2_EOTF_Set, can't en clk 1\n");

}

char drvif_DM2_EOTF_Set_By_DMA(unsigned int *EOTF_table32_R, unsigned int *EOTF_table32_G, unsigned int *EOTF_table32_B, unsigned int addr, unsigned int* vir_addr)
{
	dmato3dtable_dmato3dtable_db_ctl_RBUS dmato3dtable_dmato3dtable_db_ctl_reg;
	dmato3dtable_dmato3dtable_table2_format0_RBUS dmato3dtable_dmato3dtable_table2_format0_reg;
	dmato3dtable_dmato3dtable_table2_addr_RBUS dmato3dtable_dmato3dtable_table2_addr_reg;
	dm_dmato3dtable_ctrl_RBUS dm_dmato3dtable_ctrl_reg;
	dmato3dtable_dmato3dtable_table2_status_RBUS dmato3dtable_dmato3dtable_table2_status_reg;

	UINT32 i=0;
	unsigned char *temp;

	if ((EOTF_table32_R == NULL) || (EOTF_table32_G == NULL) || (EOTF_table32_B == NULL) || (addr == 0) || (vir_addr == NULL)) {
		rtd_printk(KERN_EMERG, TAG_NAME, "drvif_DM2_OETF_Set_By_DMA, table NULL, R=%x, G=%x, B=%x, addr = %x, vi_addr = %x\n",
			EOTF_table32_R, EOTF_table32_G, EOTF_table32_B, addr, vir_addr);
		return -1;
	}

	dmato3dtable_dmato3dtable_table2_format0_reg.regValue = IoReg_Read32(DMATO3DTABLE_DMAto3DTable_Table2_Format0_reg);
	dmato3dtable_dmato3dtable_table2_format0_reg.table2_dma_en = 1;
	IoReg_Write32(DMATO3DTABLE_DMAto3DTable_Table2_Format0_reg,dmato3dtable_dmato3dtable_table2_format0_reg.regValue);

	dm_dmato3dtable_ctrl_reg.regValue = IoReg_Read32(DM_DMAto3Dtable_CTRL_reg);
	dm_dmato3dtable_ctrl_reg.eotf_dmato3dtable_en =1;
	IoReg_Write32(DM_DMAto3Dtable_CTRL_reg,dm_dmato3dtable_ctrl_reg.regValue);

	dmato3dtable_dmato3dtable_db_ctl_reg.regValue = IoReg_Read32(DMATO3DTABLE_DMAto3DTable_db_ctl_reg);
	dmato3dtable_dmato3dtable_db_ctl_reg.db_en=1;
	IoReg_Write32(DMATO3DTABLE_DMAto3DTable_db_ctl_reg,dmato3dtable_dmato3dtable_db_ctl_reg.regValue);

	/* phy addr setting*/
	IoReg_Write32(DMATO3DTABLE_DMAto3DTable_Table2_Addr_reg, (addr/*-0x200*/));

	rtd_printk(KERN_INFO, TAG_NAME, "\n vpq eotf : Eotf_phys %x , virtaddr %x \n",addr, vir_addr );

	for(i=0;i<1025;i++)
	{
		temp=(unsigned char *)&EOTF_table32_R[i];
		vir_addr[i*3]=temp[3]+(temp[2]<<8)+(temp[1]<<16)+(temp[0]<<24);
		temp=(unsigned char *)&EOTF_table32_G[i];
		vir_addr[i*3+1]=temp[3]+(temp[2]<<8)+(temp[1]<<16)+(temp[0]<<24);
		temp=(unsigned char *)&EOTF_table32_B[i];
		vir_addr[i*3+2]=temp[3]+(temp[2]<<8)+(temp[1]<<16)+(temp[0]<<24);
	}

	/* this apply flow still need modify fixed me */

	dmato3dtable_dmato3dtable_db_ctl_reg.regValue = IoReg_Read32(DMATO3DTABLE_DMAto3DTable_db_ctl_reg);
	dmato3dtable_dmato3dtable_db_ctl_reg.wtable_apply=1;
	IoReg_Write32(DMATO3DTABLE_DMAto3DTable_db_ctl_reg,dmato3dtable_dmato3dtable_db_ctl_reg.regValue);
	dmato3dtable_dmato3dtable_table2_status_reg.regValue = IoReg_Read32(DMATO3DTABLE_DMAto3DTable_Table2_Status_reg);
	dmato3dtable_dmato3dtable_table2_status_reg.table2_wdone =1;
	IoReg_Write32(DMATO3DTABLE_DMAto3DTable_Table2_Status_reg,dmato3dtable_dmato3dtable_table2_status_reg.regValue);

	dmato3dtable_dmato3dtable_db_ctl_reg.regValue = IoReg_Read32(DMATO3DTABLE_DMAto3DTable_db_ctl_reg);
	dmato3dtable_dmato3dtable_db_ctl_reg.wtable_apply=1;
	IoReg_Write32(DMATO3DTABLE_DMAto3DTable_db_ctl_reg,dmato3dtable_dmato3dtable_db_ctl_reg.regValue);
	return 0;
}

void drvif_DM2_EOTF_Get(unsigned int *EOTF_table32_R, unsigned int *EOTF_table32_G, unsigned int *EOTF_table32_B)
{
	UINT16 i;
	UINT32 timeoutcnt = 0x062500;
	UINT8 timeoutcnt_rw_addr =100;
	dm_hdr_eotf_lut_ctrl0_RBUS DM_HDR_EOTF_LUT_CTRL0_Reg;
	dm_hdr_eotf_lut_ctrl1_RBUS DM_HDR_EOTF_LUT_CTRL1_Reg;
	dm_hdr_eotf_lut_rd_data0_RBUS dm_hdr_eotf_lut_rd_data0_Reg;
	dm_hdr_eotf_lut_rd_data1_RBUS dm_hdr_eotf_lut_rd_data1_Reg;
	dm_hdr_eotf_lut_rd_data2_RBUS dm_hdr_eotf_lut_rd_data2_Reg;
	dm_hdr_eotf_lut_rd_data3_RBUS dm_hdr_eotf_lut_rd_data3_Reg;
	dm_hdr_eotf_lut_rd_data4_RBUS dm_hdr_eotf_lut_rd_data4_Reg;
	dm_hdr_eotf_lut_rd_data5_RBUS dm_hdr_eotf_lut_rd_data5_Reg;
#if 0
	for(i=0;i<timeoutcnt_rw_addr;i++) //switch read/write , address will clean to 0 (some time not work)
	{

		DM_HDR_EOTF_LUT_CTRL0_Reg.regValue = rtd_inl(DM_HDR_EOTF_LUT_CTRL0_reg);
		//read init
		DM_HDR_EOTF_LUT_CTRL0_Reg.regValue = rtd_inl(DM_HDR_EOTF_LUT_CTRL0_reg);
		DM_HDR_EOTF_LUT_CTRL0_Reg.eotf_lut_enable = 1;
		DM_HDR_EOTF_LUT_CTRL0_Reg.eotf_lut_rw_sel = 2;
		rtd_outl(DM_HDR_EOTF_LUT_CTRL0_reg, DM_HDR_EOTF_LUT_CTRL0_Reg.regValue);

		//write init
		DM_HDR_EOTF_LUT_CTRL0_Reg.regValue = rtd_inl(DM_HDR_EOTF_LUT_CTRL0_reg);
		DM_HDR_EOTF_LUT_CTRL0_Reg.eotf_lut_enable = 1;
		DM_HDR_EOTF_LUT_CTRL0_Reg.eotf_lut_rw_sel = 1;
		rtd_outl(DM_HDR_EOTF_LUT_CTRL0_reg, DM_HDR_EOTF_LUT_CTRL0_Reg.regValue);

		DM_HDR_EOTF_LUT_CTRL1_Reg.regValue = rtd_inl(DM_HDR_EOTF_LUT_CTRL1_reg);

		if(DM_HDR_EOTF_LUT_CTRL1_Reg.eotf_lut_rw_addr!=0)
			rtd_printk(KERN_DEBUG, TAG_NAME, "PQ WARNING, Get HDR EOTF table wrong, rw_address not 0 ,times=%d",i);
		else
			break;

	}// read/write OE/EO table havt to check rw_address is 0
#endif
	/* hw issue, disable dm clk before r/w sel changing*/
	rtd_outl(SYS_REG_SYS_CLKEN1_reg, SYS_REG_SYS_CLKEN1_clken_dolby_dm_mask);

	//read init
	DM_HDR_EOTF_LUT_CTRL0_Reg.regValue = rtd_inl(DM_HDR_EOTF_LUT_CTRL0_reg);
	DM_HDR_EOTF_LUT_CTRL0_Reg.eotf_lut_enable = 1;
	DM_HDR_EOTF_LUT_CTRL0_Reg.eotf_lut_rw_sel = 2;
	rtd_outl(DM_HDR_EOTF_LUT_CTRL0_reg, DM_HDR_EOTF_LUT_CTRL0_Reg.regValue);

	/* enable dm clk*/
	rtd_outl(SYS_REG_SYS_CLKEN1_reg, SYS_REG_SYS_CLKEN1_clken_dolby_dm_mask | SYS_REG_SYS_CLKEN1_write_data_mask);

	/* hw issue for m5, reset sram manually.*/
	timeoutcnt = 0x062500;
	DM_HDR_EOTF_LUT_CTRL1_Reg.regValue = rtd_inl(DM_HDR_EOTF_LUT_CTRL1_reg);
	while((DM_HDR_EOTF_LUT_CTRL1_Reg.eotf_lut_rw_addr != 0) && (timeoutcnt > 10)) {
		DM_HDR_EOTF_LUT_CTRL1_Reg.eotf_lut_read_en = 1;
		rtd_outl(DM_HDR_EOTF_LUT_CTRL1_reg, DM_HDR_EOTF_LUT_CTRL1_Reg.regValue);
		do {
			timeoutcnt--;
		}while((DM_HDR_EOTF_LUT_CTRL1_get_eotf_lut_read_en(rtd_inl(DM_HDR_EOTF_LUT_CTRL1_reg)) == 1) && (timeoutcnt > 10));
		timeoutcnt--;
		DM_HDR_EOTF_LUT_CTRL1_Reg.regValue = rtd_inl(DM_HDR_EOTF_LUT_CTRL1_reg);

	};

	if (timeoutcnt <= 0) {
		rtd_printk(KERN_EMERG, TAG_NAME, "EOTF sRam Get, timeoutcnt=%d, return\n", timeoutcnt);
		return;
	}

	//get data to SRAM
	timeoutcnt = 0x062500;
	i = 0;
	while(i < EOTF_size)
	{
		//read
		DM_HDR_EOTF_LUT_CTRL1_Reg.regValue = rtd_inl(DM_HDR_EOTF_LUT_CTRL1_reg);
		DM_HDR_EOTF_LUT_CTRL1_Reg.eotf_lut_write_en = 0;
		DM_HDR_EOTF_LUT_CTRL1_Reg.eotf_lut_read_en = 1;
		rtd_outl(DM_HDR_EOTF_LUT_CTRL1_reg, DM_HDR_EOTF_LUT_CTRL1_Reg.regValue);
		do
		{
			timeoutcnt--;
			DM_HDR_EOTF_LUT_CTRL1_Reg.regValue = rtd_inl(DM_HDR_EOTF_LUT_CTRL1_reg);
		}
		while(DM_HDR_EOTF_LUT_CTRL1_Reg.eotf_lut_read_en && timeoutcnt > 10);

		//data
		dm_hdr_eotf_lut_rd_data0_Reg.regValue = rtd_inl(DM_HDR_EOTF_LUT_RD_DATA0_reg);
		dm_hdr_eotf_lut_rd_data1_Reg.regValue = rtd_inl(DM_HDR_EOTF_LUT_RD_DATA1_reg);
		dm_hdr_eotf_lut_rd_data2_Reg.regValue = rtd_inl(DM_HDR_EOTF_LUT_RD_DATA2_reg);
		dm_hdr_eotf_lut_rd_data3_Reg.regValue = rtd_inl(DM_HDR_EOTF_LUT_RD_DATA3_reg);
		dm_hdr_eotf_lut_rd_data4_Reg.regValue = rtd_inl(DM_HDR_EOTF_LUT_RD_DATA4_reg);
		dm_hdr_eotf_lut_rd_data5_Reg.regValue = rtd_inl(DM_HDR_EOTF_LUT_RD_DATA5_reg);
		EOTF_table32_R[i] = dm_hdr_eotf_lut_rd_data0_Reg.eotf_rd_lut_data0;
		EOTF_table32_G[i] = dm_hdr_eotf_lut_rd_data2_Reg.eotf_rd_lut_data2;
		EOTF_table32_B[i] = dm_hdr_eotf_lut_rd_data4_Reg.eotf_rd_lut_data4;
		if (i + 1 < EOTF_size)		//data protect
		{
			EOTF_table32_R[i + 1] = dm_hdr_eotf_lut_rd_data1_Reg.eotf_rd_lut_data1;
			EOTF_table32_G[i + 1] = dm_hdr_eotf_lut_rd_data3_Reg.eotf_rd_lut_data3;
			EOTF_table32_B[i + 1] = dm_hdr_eotf_lut_rd_data5_Reg.eotf_rd_lut_data5;
		}

		i = i + 2;
	}

	/* hw issue, disable dm clk before r/w sel changing*/
	rtd_outl(SYS_REG_SYS_CLKEN1_reg, SYS_REG_SYS_CLKEN1_clken_dolby_dm_mask);

	//read end
	DM_HDR_EOTF_LUT_CTRL0_Reg.regValue = rtd_inl(DM_HDR_EOTF_LUT_CTRL0_reg);
	DM_HDR_EOTF_LUT_CTRL0_Reg.eotf_lut_enable = 1;
	DM_HDR_EOTF_LUT_CTRL0_Reg.eotf_lut_rw_sel = 0;
	rtd_outl(DM_HDR_EOTF_LUT_CTRL0_reg, DM_HDR_EOTF_LUT_CTRL0_Reg.regValue);

	/* enable dm clk*/
	rtd_outl(SYS_REG_SYS_CLKEN1_reg, SYS_REG_SYS_CLKEN1_clken_dolby_dm_mask | SYS_REG_SYS_CLKEN1_write_data_mask);

	#if 0
	//data check
	for (i = 1; i < EOTF_size; i++)
	{
		if (EOTF_table32_R[i] < EOTF_table32_R[i - 1])
			{rtd_printk(KERN_DEBUG, TAG_NAME, "PQ WARNING, HDR EOTF table wrong, EOTF_table32_R[%d] = %d > EOTF_table32_R[%d] = %d\n", i - 1, EOTF_table32_R[i - 1], i, EOTF_table32_R[i]);}
		if (EOTF_table32_G[i] < EOTF_table32_G[i - 1])
			{rtd_printk(KERN_DEBUG, TAG_NAME, "PQ WARNING, HDR EOTF table wrong, EOTF_table32_G[%d] = %d > EOTF_table32_G[%d] = %d\n", i - 1, EOTF_table32_G[i - 1], i, EOTF_table32_G[i]);}
		if (EOTF_table32_B[i] < EOTF_table32_B[i - 1])
			{rtd_printk(KERN_DEBUG, TAG_NAME, "PQ WARNING, HDR EOTF table wrong, EOTF_table32_B[%d] = %d > EOTF_table32_B[%d] = %d\n", i - 1, EOTF_table32_B[i - 1], i, EOTF_table32_B[i]);}
	}
	#endif
}

void drvif_DM2_EOTF_Enable(unsigned char En, unsigned char sel)
{
	dm_hdr_eotf_lut_ctrl0_RBUS DM_HDR_EOTF_LUT_CTRL0_Reg;
	dm_hdr_path_sel_RBUS dm_hdr_path_sel_reg;
	dm_hdr_double_buffer_ctrl_RBUS dm_double_buffer_ctrl_reg;

	// enable DM & Composer clock
	rtd_outl(SYS_REG_SYS_CLKEN1_reg, SYS_REG_SYS_CLKEN1_clken_dolby_dm_mask | SYS_REG_SYS_CLKEN1_clken_dolby_comp_mask | SYS_REG_SYS_CLKEN1_write_data_mask);


	//read init
	DM_HDR_EOTF_LUT_CTRL0_Reg.regValue = rtd_inl(DM_HDR_EOTF_LUT_CTRL0_reg);
	dm_hdr_path_sel_reg.regValue = rtd_inl(DM_HDR_PATH_SEL_reg);

	DM_HDR_EOTF_LUT_CTRL0_Reg.eotf_lut_enable = En;
	dm_hdr_path_sel_reg.b0103_or_eotf = sel;
	dm_hdr_path_sel_reg.b02b03_no_sram_mode = En;

	rtd_outl(DM_HDR_EOTF_LUT_CTRL0_reg, DM_HDR_EOTF_LUT_CTRL0_Reg.regValue);
	rtd_outl(DM_HDR_PATH_SEL_reg, dm_hdr_path_sel_reg.regValue);


	//apply
	dm_double_buffer_ctrl_reg.regValue = IoReg_Read32(DM_HDR_Double_Buffer_CTRL_reg);
	dm_double_buffer_ctrl_reg.dm_db_read_sel=1;
	dm_double_buffer_ctrl_reg.dm_db_apply = 1;
	IoReg_Write32(DM_HDR_Double_Buffer_CTRL_reg, dm_double_buffer_ctrl_reg.regValue);
}

void drvif_DM2_OETF_Set(unsigned short *OETF_table16_R, unsigned short *OETF_table16_G, unsigned short *OETF_table16_B)
{
	UINT16 i;
	UINT32 timeoutcnt = 0x062500;
	UINT8 timeoutcnt_rw_addr =100;

	dm_hdr_oetf_lut_ctrl0_RBUS DM_HDR_OETF_LUT_CTRL0_Reg;
	dm_hdr_oetf_lut_ctrl1_RBUS DM_HDR_OETF_LUT_CTRL1_Reg;
	dm_hdr_oetf_lut_wr_data0_RBUS dm_hdr_oetf_lut_wr_data0_Reg;
	dm_hdr_oetf_lut_wr_data1_RBUS dm_hdr_oetf_lut_wr_data1_Reg;
	dm_hdr_oetf_lut_wr_data2_RBUS dm_hdr_oetf_lut_wr_data2_Reg;


#if 0
	for(i=0;i<timeoutcnt_rw_addr;i++)//switch read/write , address will clean to 0 (some time not work)
	{
		//write init
		DM_HDR_OETF_LUT_CTRL0_Reg.regValue = rtd_inl(DM_HDR_OETF_LUT_CTRL0_reg);
		DM_HDR_OETF_LUT_CTRL0_Reg.oetf_lut_enable = 1;
		DM_HDR_OETF_LUT_CTRL0_Reg.oetf_lut_rw_sel = 1;
		rtd_outl(DM_HDR_OETF_LUT_CTRL0_reg, DM_HDR_OETF_LUT_CTRL0_Reg.regValue);
		//read init
		DM_HDR_OETF_LUT_CTRL0_Reg.regValue = rtd_inl(DM_HDR_OETF_LUT_CTRL0_reg);
		DM_HDR_OETF_LUT_CTRL0_Reg.oetf_lut_enable = 1;
		DM_HDR_OETF_LUT_CTRL0_Reg.oetf_lut_rw_sel = 2;


		rtd_outl(DM_HDR_OETF_LUT_CTRL0_reg, DM_HDR_OETF_LUT_CTRL0_Reg.regValue);

		DM_HDR_OETF_LUT_CTRL1_Reg.regValue = rtd_inl(DM_HDR_OETF_LUT_CTRL1_reg);
		if(DM_HDR_OETF_LUT_CTRL1_Reg.oetf_lut_rw_addr!=0)
			rtd_printk(KERN_DEBUG, TAG_NAME, "PQ WARNING, Set HDR OETF table wrong, rw_address not 0 ,times=%d",i);
		else
			break;
	} // read/write OE/EO table havt to check rw_address is 0
#endif
	/* hw issue, disable dm clk before r/w sel changing*/
	rtd_outl(SYS_REG_SYS_CLKEN1_reg, SYS_REG_SYS_CLKEN1_clken_dolby_dm_mask);
	timeoutcnt = 0x062500;
	/* waiting for clk disable*/
	while ((SYS_REG_SYS_CLKEN1_get_clken_dolby_dm(rtd_inl(SYS_REG_SYS_CLKEN1_reg)) == 1) && (timeoutcnt > 10))
		timeoutcnt --;
	if (timeoutcnt <= 10)
		rtd_printk(KERN_EMERG, TAG_NAME, "drvif_DM2_OETF_Set, can't disable clk 0\n");

	//write init
	DM_HDR_OETF_LUT_CTRL0_Reg.regValue = rtd_inl(DM_HDR_OETF_LUT_CTRL0_reg);
	DM_HDR_OETF_LUT_CTRL0_Reg.oetf_lut_enable = 1;
	DM_HDR_OETF_LUT_CTRL0_Reg.oetf_lut_rw_sel = 1;
	rtd_outl(DM_HDR_OETF_LUT_CTRL0_reg, DM_HDR_OETF_LUT_CTRL0_Reg.regValue);

	/* enable dm clk*/
	rtd_outl(SYS_REG_SYS_CLKEN1_reg, SYS_REG_SYS_CLKEN1_clken_dolby_dm_mask | SYS_REG_SYS_CLKEN1_write_data_mask);
	timeoutcnt = 0x062500;
	/* waiting for clk disable*/
	while ((SYS_REG_SYS_CLKEN1_get_clken_dolby_dm(rtd_inl(SYS_REG_SYS_CLKEN1_reg)) == 0) && (timeoutcnt > 10))
		timeoutcnt --;
	if (timeoutcnt <= 10)
		rtd_printk(KERN_EMERG, TAG_NAME, "drvif_DM2_OETF_Set, can't en clk 0\n");

	/* hw issue for m5, reset sram manually.*/
	timeoutcnt = 0x062500;
	DM_HDR_OETF_LUT_CTRL1_Reg.regValue = rtd_inl(DM_HDR_OETF_LUT_CTRL1_reg);
	while((DM_HDR_OETF_LUT_CTRL1_Reg.oetf_lut_rw_addr != 0) && (timeoutcnt > 10)) {
		DM_HDR_OETF_LUT_CTRL1_Reg.oetf_lut_write_en = 1;
		rtd_outl(DM_HDR_OETF_LUT_CTRL1_reg, DM_HDR_OETF_LUT_CTRL1_Reg.regValue);
		do {
			timeoutcnt--;
		}while((DM_HDR_OETF_LUT_CTRL1_get_oetf_lut_write_en(rtd_inl(DM_HDR_OETF_LUT_CTRL1_reg)) == 1) && (timeoutcnt > 10));
		timeoutcnt--;
		DM_HDR_OETF_LUT_CTRL1_Reg.regValue = rtd_inl(DM_HDR_OETF_LUT_CTRL1_reg);
	};

	if (timeoutcnt <= 10) {
		rtd_printk(KERN_INFO, TAG_NAME, "OETF sRam Set, timeoutcnt=%d, return \n", timeoutcnt);
		return;
	}

	//data check
	for (i = 1; i < OETF_size; i++)
	{
		if (OETF_table16_R[i] < OETF_table16_R[i - 1])
			{rtd_printk(KERN_DEBUG, TAG_NAME, "PQ WARNING, HDR OETF table wrong, OETF_table16_R[%d] = %d > OETF_table16_R[%d] = %d\n", i - 1, OETF_table16_R[i - 1], i, OETF_table16_R[i]);}
		if (OETF_table16_G[i] < OETF_table16_G[i - 1])
			{rtd_printk(KERN_DEBUG, TAG_NAME, "PQ WARNING, HDR OETF table wrong, OETF_table16_G[%d] = %d > OETF_table16_G[%d] = %d\n", i - 1, OETF_table16_G[i - 1], i, OETF_table16_G[i]);}
		if (OETF_table16_B[i] < OETF_table16_B[i - 1])
			{rtd_printk(KERN_DEBUG, TAG_NAME, "PQ WARNING, HDR OETF table wrong, OETF_table16_B[%d] = %d > OETF_table16_B[%d] = %d\n", i - 1, OETF_table16_B[i - 1], i, OETF_table16_B[i]);}
	}

	timeoutcnt = 0x062500;
	//push data to SRAM
	i = 0;
	while(i < OETF_size)
	{
		//data
		dm_hdr_oetf_lut_wr_data0_Reg.oetf_wr_lut_data0 = OETF_table16_R[i];
		dm_hdr_oetf_lut_wr_data1_Reg.oetf_wr_lut_data2 = OETF_table16_G[i];
		dm_hdr_oetf_lut_wr_data2_Reg.oetf_wr_lut_data4 = OETF_table16_B[i];

		if (i + 1 < OETF_size)
		{
			dm_hdr_oetf_lut_wr_data0_Reg.oetf_wr_lut_data1 = OETF_table16_R[i + 1];
			dm_hdr_oetf_lut_wr_data1_Reg.oetf_wr_lut_data3 = OETF_table16_G[i + 1];
			dm_hdr_oetf_lut_wr_data2_Reg.oetf_wr_lut_data5 = OETF_table16_B[i + 1];
		}

		rtd_outl(DM_HDR_OETF_LUT_WR_DATA0_reg, dm_hdr_oetf_lut_wr_data0_Reg.regValue);
		rtd_outl(DM_HDR_OETF_LUT_WR_DATA1_reg, dm_hdr_oetf_lut_wr_data1_Reg.regValue);
		rtd_outl(DM_HDR_OETF_LUT_WR_DATA2_reg, dm_hdr_oetf_lut_wr_data2_Reg.regValue);

		//write
		DM_HDR_OETF_LUT_CTRL1_Reg.regValue = rtd_inl(DM_HDR_OETF_LUT_CTRL1_reg);
		DM_HDR_OETF_LUT_CTRL1_Reg.oetf_lut_read_en = 0;
		DM_HDR_OETF_LUT_CTRL1_Reg.oetf_lut_write_en = 1;
		rtd_outl(DM_HDR_OETF_LUT_CTRL1_reg, DM_HDR_OETF_LUT_CTRL1_Reg.regValue);
		do
		{
			timeoutcnt--;
			DM_HDR_OETF_LUT_CTRL1_Reg.regValue = rtd_inl(DM_HDR_OETF_LUT_CTRL1_reg);
		}
		while(DM_HDR_OETF_LUT_CTRL1_Reg.oetf_lut_write_en && timeoutcnt > 10);

		i = i + 2;
	}


	/* hw issue, disable dm clk before r/w sel changing*/
	rtd_outl(SYS_REG_SYS_CLKEN1_reg, SYS_REG_SYS_CLKEN1_clken_dolby_dm_mask);
	timeoutcnt = 0x062500;
	/* waiting for clk disable*/
	while ((SYS_REG_SYS_CLKEN1_get_clken_dolby_dm(rtd_inl(SYS_REG_SYS_CLKEN1_reg)) == 1) && (timeoutcnt > 10))
		timeoutcnt --;
	if (timeoutcnt <= 10)
		rtd_printk(KERN_EMERG, TAG_NAME, "drvif_DM2_OETF_Set, can't disable clk 1\n");

	//write end
	DM_HDR_OETF_LUT_CTRL0_Reg.regValue = rtd_inl(DM_HDR_OETF_LUT_CTRL0_reg);
	DM_HDR_OETF_LUT_CTRL0_Reg.oetf_lut_enable = 1;
	DM_HDR_OETF_LUT_CTRL0_Reg.oetf_lut_rw_sel = 0;
	rtd_outl(DM_HDR_OETF_LUT_CTRL0_reg, DM_HDR_OETF_LUT_CTRL0_Reg.regValue);

	/* enable dm clk*/
	rtd_outl(SYS_REG_SYS_CLKEN1_reg, SYS_REG_SYS_CLKEN1_clken_dolby_dm_mask | SYS_REG_SYS_CLKEN1_write_data_mask);
	timeoutcnt = 0x062500;
	/* waiting for clk disable*/
	while ((SYS_REG_SYS_CLKEN1_get_clken_dolby_dm(rtd_inl(SYS_REG_SYS_CLKEN1_reg)) == 0) && (timeoutcnt > 10))
		timeoutcnt --;
	if (timeoutcnt <= 10)
		rtd_printk(KERN_EMERG, TAG_NAME, "drvif_DM2_OETF_Set, can't en clk 1\n");

}

char drvif_DM2_OETF_Set_By_DMA(unsigned short *OETF_table16_R, unsigned short *OETF_table16_G, unsigned short *OETF_table16_B, unsigned int addr, unsigned int* vir_addr)
{
	dmato3dtable_dmato3dtable_db_ctl_RBUS dmato3dtable_dmato3dtable_db_ctl_reg;
	dmato3dtable_dmato3dtable_table3_format0_RBUS dmato3dtable_dmato3dtable_table3_format0_reg;
	dmato3dtable_dmato3dtable_table3_addr_RBUS dmato3dtable_dmato3dtable_table3_addr_reg;
	dm_dmato3dtable_ctrl_RBUS dm_dmato3dtable_ctrl_reg;
	dmato3dtable_dmato3dtable_table3_status_RBUS dmato3dtable_dmato3dtable_table3_status_reg;

	UINT32 i=0;
	unsigned char *temp;
	unsigned short *virAddr_16 = NULL;

	if ((OETF_table16_R == NULL) || (OETF_table16_G == NULL) || (OETF_table16_B == NULL) || (addr == 0) || (vir_addr == NULL)) {
		rtd_printk(KERN_EMERG, TAG_NAME, "drvif_DM2_OETF_Set_By_DMA, table NULL, R=%x, G=%x, B=%x, addr = %x, vi_addr = %x\n",
			OETF_table16_R, OETF_table16_G, OETF_table16_B, addr, vir_addr);
		return -1;
	}

	dmato3dtable_dmato3dtable_table3_format0_reg.regValue = IoReg_Read32(DMATO3DTABLE_DMAto3DTable_Table3_Format0_reg);
	dmato3dtable_dmato3dtable_table3_format0_reg.table3_dma_en = 1;
	IoReg_Write32(DMATO3DTABLE_DMAto3DTable_Table3_Format0_reg,dmato3dtable_dmato3dtable_table3_format0_reg.regValue);

	dm_dmato3dtable_ctrl_reg.regValue = IoReg_Read32(DM_DMAto3Dtable_CTRL_reg);
	dm_dmato3dtable_ctrl_reg.oetf_dmato3dtable_en =1;
	IoReg_Write32(DM_DMAto3Dtable_CTRL_reg,dm_dmato3dtable_ctrl_reg.regValue);


	dmato3dtable_dmato3dtable_db_ctl_reg.regValue = IoReg_Read32(DMATO3DTABLE_DMAto3DTable_db_ctl_reg);
	dmato3dtable_dmato3dtable_db_ctl_reg.db_en=1;
	IoReg_Write32(DMATO3DTABLE_DMAto3DTable_db_ctl_reg,dmato3dtable_dmato3dtable_db_ctl_reg.regValue);

	/* phy addr setting*/
	IoReg_Write32(DMATO3DTABLE_DMAto3DTable_Table3_Addr_reg, (addr/*-0x200*/));


	rtd_printk(KERN_INFO, TAG_NAME, "OETF_phys = %x, OETF_virt = %x\n", addr, vir_addr);

	virAddr_16 = (unsigned short*)vir_addr;

	for(i=0;i<1025;i++)
	{
		temp=(unsigned char *)&OETF_table16_R[i];
		virAddr_16[i*3]=temp[1]+(temp[0]<<8);

		temp=(unsigned char *)&OETF_table16_G[i];
		virAddr_16[i*3+1]=temp[1]+(temp[0]<<8);

		temp=(unsigned char *)&OETF_table16_B[i];
		virAddr_16[i*3+2]=temp[1]+(temp[0]<<8);
	}
	//rtd_printk(KERN_EMERG, TAG_NAME, "\n vpq eotf : Eotf_phys %x , virtaddr %x \n",address,pVirtAddr );

	/* this apply flow still need modify fixed me */

	dmato3dtable_dmato3dtable_db_ctl_reg.regValue = IoReg_Read32(DMATO3DTABLE_DMAto3DTable_db_ctl_reg);
	dmato3dtable_dmato3dtable_db_ctl_reg.wtable_apply=1;
	IoReg_Write32(DMATO3DTABLE_DMAto3DTable_db_ctl_reg,dmato3dtable_dmato3dtable_db_ctl_reg.regValue);


	dmato3dtable_dmato3dtable_table3_status_reg.regValue = IoReg_Read32(DMATO3DTABLE_DMAto3DTable_Table3_Status_reg);
	dmato3dtable_dmato3dtable_table3_status_reg.table3_wdone =1;
	IoReg_Write32(DMATO3DTABLE_DMAto3DTable_Table3_Status_reg,dmato3dtable_dmato3dtable_table3_status_reg.regValue);

	dmato3dtable_dmato3dtable_db_ctl_reg.regValue = IoReg_Read32(DMATO3DTABLE_DMAto3DTable_db_ctl_reg);
	dmato3dtable_dmato3dtable_db_ctl_reg.wtable_apply=1;
	IoReg_Write32(DMATO3DTABLE_DMAto3DTable_db_ctl_reg,dmato3dtable_dmato3dtable_db_ctl_reg.regValue);
	return 0;
}

void drvif_DM2_OETF_Get(unsigned short *OETF_table16_R, unsigned short *OETF_table16_G, unsigned short *OETF_table16_B)
{
	UINT16 i;
	UINT32 timeoutcnt = 0x062500;
	UINT8 timeoutcnt_rw_addr =100;
	dm_hdr_oetf_lut_ctrl0_RBUS DM_HDR_OETF_LUT_CTRL0_Reg;
	dm_hdr_oetf_lut_ctrl1_RBUS DM_HDR_OETF_LUT_CTRL1_Reg;
	dm_hdr_oetf_lut_rd_data0_RBUS dm_hdr_oetf_lut_rd_data0_Reg;
	dm_hdr_oetf_lut_rd_data1_RBUS dm_hdr_oetf_lut_rd_data1_Reg;
	dm_hdr_oetf_lut_rd_data2_RBUS dm_hdr_oetf_lut_rd_data2_Reg;
#if 0
	for(i=0;i<timeoutcnt_rw_addr;i++)//switch read/write , address will clean to 0 (some time not work)
	{
		//Read init
		DM_HDR_OETF_LUT_CTRL0_Reg.regValue = rtd_inl(DM_HDR_OETF_LUT_CTRL0_reg);
		DM_HDR_OETF_LUT_CTRL0_Reg.oetf_lut_enable = 1;
		DM_HDR_OETF_LUT_CTRL0_Reg.oetf_lut_rw_sel = 2;
		rtd_outl(DM_HDR_OETF_LUT_CTRL0_reg, DM_HDR_OETF_LUT_CTRL0_Reg.regValue);
		//write init
		DM_HDR_OETF_LUT_CTRL0_Reg.regValue = rtd_inl(DM_HDR_OETF_LUT_CTRL0_reg);
		DM_HDR_OETF_LUT_CTRL0_Reg.oetf_lut_enable = 1;
		DM_HDR_OETF_LUT_CTRL0_Reg.oetf_lut_rw_sel = 1;
		rtd_outl(DM_HDR_OETF_LUT_CTRL0_reg, DM_HDR_OETF_LUT_CTRL0_Reg.regValue);

		DM_HDR_OETF_LUT_CTRL1_Reg.regValue = rtd_inl(DM_HDR_OETF_LUT_CTRL1_reg);

		if(DM_HDR_OETF_LUT_CTRL1_Reg.oetf_lut_rw_addr!=0)
			rtd_printk(KERN_DEBUG, TAG_NAME, "PQ WARNING, Gt HDR OETF table wrong, rw_address not 0 ,times=%d",i);
		else
			break;

	}// read/write OE/EO table havt to check rw_address is 0
#endif
	/* hw issue, disable dm clk before r/w sel changing*/
	rtd_outl(SYS_REG_SYS_CLKEN1_reg, SYS_REG_SYS_CLKEN1_clken_dolby_dm_mask);

	//read init
	DM_HDR_OETF_LUT_CTRL0_Reg.regValue = rtd_inl(DM_HDR_OETF_LUT_CTRL0_reg);
	DM_HDR_OETF_LUT_CTRL0_Reg.oetf_lut_enable = 1;
	DM_HDR_OETF_LUT_CTRL0_Reg.oetf_lut_rw_sel = 2;
	rtd_outl(DM_HDR_OETF_LUT_CTRL0_reg, DM_HDR_OETF_LUT_CTRL0_Reg.regValue);

	/* enable dm clk*/
	rtd_outl(SYS_REG_SYS_CLKEN1_reg, SYS_REG_SYS_CLKEN1_clken_dolby_dm_mask | SYS_REG_SYS_CLKEN1_write_data_mask);

	/* hw issue for m5, reset sram manually.*/
	timeoutcnt = 0x062500;
	DM_HDR_OETF_LUT_CTRL1_Reg.regValue = rtd_inl(DM_HDR_OETF_LUT_CTRL1_reg);
	while((DM_HDR_OETF_LUT_CTRL1_Reg.oetf_lut_rw_addr != 0) && (timeoutcnt > 10)) {
		DM_HDR_OETF_LUT_CTRL1_Reg.oetf_lut_read_en = 1;
		rtd_outl(DM_HDR_OETF_LUT_CTRL1_reg, DM_HDR_OETF_LUT_CTRL1_Reg.regValue);
		do {
			timeoutcnt--;
		}while((DM_HDR_OETF_LUT_CTRL1_get_oetf_lut_read_en(rtd_inl(DM_HDR_OETF_LUT_CTRL1_reg)) == 1) && (timeoutcnt > 10));
		timeoutcnt--;
		DM_HDR_OETF_LUT_CTRL1_Reg.regValue = rtd_inl(DM_HDR_OETF_LUT_CTRL1_reg);
	};

	if (timeoutcnt <= 0) {
		rtd_printk(KERN_EMERG, TAG_NAME, "OETF sRam Get, timeoutcnt=%d, return\n", timeoutcnt);
		return;
	}

	//get data to SRAM
	timeoutcnt = 0x062500;
	i = 0;
	while(i < OETF_size)
	{
		//read
		DM_HDR_OETF_LUT_CTRL1_Reg.regValue = rtd_inl(DM_HDR_OETF_LUT_CTRL1_reg);
		DM_HDR_OETF_LUT_CTRL1_Reg.oetf_lut_write_en = 0;
		DM_HDR_OETF_LUT_CTRL1_Reg.oetf_lut_read_en = 1;
		rtd_outl(DM_HDR_OETF_LUT_CTRL1_reg, DM_HDR_OETF_LUT_CTRL1_Reg.regValue);
		do
		{
			timeoutcnt--;
			DM_HDR_OETF_LUT_CTRL1_Reg.regValue = rtd_inl(DM_HDR_OETF_LUT_CTRL1_reg);
		}
		while(DM_HDR_OETF_LUT_CTRL1_Reg.oetf_lut_read_en && timeoutcnt > 10);

		//data
		dm_hdr_oetf_lut_rd_data0_Reg.regValue = rtd_inl(DM_HDR_OETF_LUT_RD_DATA0_reg);
		dm_hdr_oetf_lut_rd_data1_Reg.regValue = rtd_inl(DM_HDR_OETF_LUT_RD_DATA1_reg);
		dm_hdr_oetf_lut_rd_data2_Reg.regValue = rtd_inl(DM_HDR_OETF_LUT_RD_DATA2_reg);
		OETF_table16_R[i] = dm_hdr_oetf_lut_rd_data0_Reg.oetf_rd_lut_data0;
		OETF_table16_G[i] = dm_hdr_oetf_lut_rd_data1_Reg.oetf_rd_lut_data2;
		OETF_table16_B[i] = dm_hdr_oetf_lut_rd_data2_Reg.oetf_rd_lut_data4;

		if (i + 1 < OETF_size)	//data protect
		{
			OETF_table16_R[i + 1] = dm_hdr_oetf_lut_rd_data0_Reg.oetf_rd_lut_data1;
			OETF_table16_G[i + 1] = dm_hdr_oetf_lut_rd_data1_Reg.oetf_rd_lut_data3;
			OETF_table16_B[i + 1] = dm_hdr_oetf_lut_rd_data2_Reg.oetf_rd_lut_data5;
		}

		i = i + 2;
	}

	/* hw issue, disable dm clk before r/w sel changing*/
	rtd_outl(SYS_REG_SYS_CLKEN1_reg, SYS_REG_SYS_CLKEN1_clken_dolby_dm_mask);

	//read end
	DM_HDR_OETF_LUT_CTRL0_Reg.regValue = rtd_inl(DM_HDR_OETF_LUT_CTRL0_reg);
	DM_HDR_OETF_LUT_CTRL0_Reg.oetf_lut_enable = 1;
	DM_HDR_OETF_LUT_CTRL0_Reg.oetf_lut_rw_sel = 0;
	rtd_outl(DM_HDR_OETF_LUT_CTRL0_reg, DM_HDR_OETF_LUT_CTRL0_Reg.regValue);

	/* enable dm clk*/
	rtd_outl(SYS_REG_SYS_CLKEN1_reg, SYS_REG_SYS_CLKEN1_clken_dolby_dm_mask | SYS_REG_SYS_CLKEN1_write_data_mask);
#if 0
	//data check
	for (i = 1; i < OETF_size; i++)
	{
		if (OETF_table16_R[i] < OETF_table16_R[i - 1])
			{rtd_printk(KERN_DEBUG, TAG_NAME, "PQ WARNING, HDR OETF table wrong, OETF_table16_R[%d] = %d > OETF_table16_R[%d] = %d\n", i - 1, OETF_table16_R[i - 1], i, OETF_table16_R[i]);}
		if (OETF_table16_G[i] < OETF_table16_G[i - 1])
			{rtd_printk(KERN_DEBUG, TAG_NAME, "PQ WARNING, HDR OETF table wrong, OETF_table16_G[%d] = %d > OETF_table16_G[%d] = %d\n", i - 1, OETF_table16_G[i - 1], i, OETF_table16_G[i]);}
		if (OETF_table16_B[i] < OETF_table16_B[i - 1])
			{rtd_printk(KERN_DEBUG, TAG_NAME, "PQ WARNING, HDR OETF table wrong, OETF_table16_B[%d] = %d > OETF_table16_B[%d] = %d\n", i - 1, OETF_table16_B[i - 1], i, OETF_table16_B[i]);}
	}
#endif
}

void drvif_DM2_OETF_Enable(unsigned char En, unsigned char sel)
{
	dm_hdr_oetf_lut_ctrl0_RBUS DM_HDR_OETF_LUT_CTRL0_Reg;
	dm_hdr_path_sel_RBUS dm_hdr_path_sel_reg;
	dm_hdr_double_buffer_ctrl_RBUS dm_double_buffer_ctrl_reg;

	// enable DM & Composer clock
	rtd_outl(SYS_REG_SYS_CLKEN1_reg, SYS_REG_SYS_CLKEN1_clken_dolby_dm_mask | SYS_REG_SYS_CLKEN1_clken_dolby_comp_mask | SYS_REG_SYS_CLKEN1_write_data_mask);


	//read init
	DM_HDR_OETF_LUT_CTRL0_Reg.regValue = rtd_inl(DM_HDR_OETF_LUT_CTRL0_reg);
	dm_hdr_path_sel_reg.regValue = rtd_inl(DM_HDR_PATH_SEL_reg);

	DM_HDR_OETF_LUT_CTRL0_Reg.oetf_lut_enable = En;
	dm_hdr_path_sel_reg.b0105_or_oetf = sel;
	dm_hdr_path_sel_reg.b02b03_no_sram_mode = En;

	rtd_outl(DM_HDR_OETF_LUT_CTRL0_reg, DM_HDR_OETF_LUT_CTRL0_Reg.regValue);
	rtd_outl(DM_HDR_PATH_SEL_reg, dm_hdr_path_sel_reg.regValue);

	//apply
	dm_double_buffer_ctrl_reg.regValue = IoReg_Read32(DM_HDR_Double_Buffer_CTRL_reg);
	dm_double_buffer_ctrl_reg.dm_db_read_sel=1;
	dm_double_buffer_ctrl_reg.dm_db_apply = 1;
	IoReg_Write32(DM_HDR_Double_Buffer_CTRL_reg, dm_double_buffer_ctrl_reg.regValue);
}

char drvif_DM2_ToneMapping_Set(short *TM_table12_R, short *TM_table12_G, short *TM_table12_B)
{
	UINT16 i;
	UINT32 timeoutcnt1 = 0x062500;
	UINT32 timeoutcnt2 = 0x062500;
	dm_hdr_tone_lut_ctrl0_RBUS dm_hdr_tone_lut_ctrl0_Reg;
	dm_hdr_tone_lut_ctrl1_RBUS dm_hdr_tone_lut_ctrl1_Reg;
	dm_hdr_tone_lut_ctrl2_RBUS dm_hdr_tone_lut_ctrl2_Reg;
	dm_hdr_tone_lut_wr_data0_RBUS dm_hdr_tone_lut_wr_data0_Reg;
	dm_hdr_tone_lut_wr_data1_RBUS dm_hdr_tone_lut_wr_data1_Reg;
	dm_hdr_tone_lut_wr_data2_RBUS dm_hdr_tone_lut_wr_data2_Reg;


	//write init
	dm_hdr_tone_lut_ctrl0_Reg.regValue = rtd_inl(DM_HDR_TONE_LUT_CTRL0_reg);
	dm_hdr_tone_lut_ctrl0_Reg.tone_lut_rw_sel = 1;
	/*dm_hdr_tone_lut_ctrl0_Reg.tone_lut_acc_sel = tbl_sel;*/
	rtd_outl(DM_HDR_TONE_LUT_CTRL0_reg, dm_hdr_tone_lut_ctrl0_Reg.regValue);

	do
	{
		timeoutcnt1--;
		dm_hdr_tone_lut_ctrl2_Reg.regValue = rtd_inl(DM_HDR_TONE_LUT_CTRL2_reg);
	}
	while((dm_hdr_tone_lut_ctrl2_Reg.tone_lut_acc_ready == 0) && timeoutcnt1 > 10);

	if (timeoutcnt1 <= 10)
	{
		rtd_printk(KERN_DEBUG, TAG_NAME, "PQ ERROR, DM_ToneMapping can't write!\n");
		return -1;
	}

	i = 0;
	while(i < ToneMapping_size)
	{
		//data
		dm_hdr_tone_lut_wr_data0_Reg.tone_wr_lut_data0 = TM_table12_R[i];
		dm_hdr_tone_lut_wr_data1_Reg.tone_wr_lut_data2 = TM_table12_G[i];
		dm_hdr_tone_lut_wr_data2_Reg.tone_wr_lut_data4 = TM_table12_B[i];

		if (i + 1 < ToneMapping_size)
		{
			dm_hdr_tone_lut_wr_data0_Reg.tone_wr_lut_data1 = TM_table12_R[i + 1];
			dm_hdr_tone_lut_wr_data1_Reg.tone_wr_lut_data3 = TM_table12_G[i + 1];
			dm_hdr_tone_lut_wr_data2_Reg.tone_wr_lut_data5 = TM_table12_B[i + 1];
		}

		rtd_outl(DM_HDR_TONE_LUT_WR_DATA0_reg, dm_hdr_tone_lut_wr_data0_Reg.regValue);
		rtd_outl(DM_HDR_TONE_LUT_WR_DATA1_reg, dm_hdr_tone_lut_wr_data1_Reg.regValue);
		rtd_outl(DM_HDR_TONE_LUT_WR_DATA2_reg, dm_hdr_tone_lut_wr_data2_Reg.regValue);

		//write
		dm_hdr_tone_lut_ctrl1_Reg.regValue = rtd_inl(DM_HDR_TONE_LUT_CTRL1_reg);
		dm_hdr_tone_lut_ctrl1_Reg.tone_write_en = 1;
		rtd_outl(DM_HDR_TONE_LUT_CTRL1_reg, dm_hdr_tone_lut_ctrl1_Reg.regValue);
		do
		{
			timeoutcnt2--;
			dm_hdr_tone_lut_ctrl1_Reg.regValue = rtd_inl(DM_HDR_TONE_LUT_CTRL1_reg);
		}
		while(dm_hdr_tone_lut_ctrl1_Reg.tone_write_en && timeoutcnt2 > 10);

		i = i + 2;
	}


	//write end
	dm_hdr_tone_lut_ctrl0_Reg.regValue = rtd_inl(DM_HDR_TONE_LUT_CTRL0_reg);
	dm_hdr_tone_lut_ctrl0_Reg.tone_lut_rw_sel = 0;
	/* change table for next writting*/
	dm_hdr_tone_lut_ctrl0_Reg.tone_lut_acc_sel = ~dm_hdr_tone_lut_ctrl0_Reg.tone_lut_acc_sel;
	rtd_outl(DM_HDR_TONE_LUT_CTRL0_reg, dm_hdr_tone_lut_ctrl0_Reg.regValue);

	return 0;
}

char drvif_DM2_ToneMapping_Get(short *TM_table12_R, short *TM_table12_G, short *TM_table12_B)
{
	UINT16 i;
	UINT32 timeoutcnt1 = 0x062500;
	UINT32 timeoutcnt2 = 0x062500;
	dm_hdr_tone_lut_ctrl0_RBUS dm_hdr_tone_lut_ctrl0_Reg;
	dm_hdr_tone_lut_ctrl1_RBUS dm_hdr_tone_lut_ctrl1_Reg;
	dm_hdr_tone_lut_ctrl2_RBUS dm_hdr_tone_lut_ctrl2_Reg;
	dm_hdr_tone_lut_rd_data0_RBUS dm_hdr_tone_lut_rd_data0_Reg;
	dm_hdr_tone_lut_rd_data1_RBUS dm_hdr_tone_lut_rd_data1_Reg;
	dm_hdr_tone_lut_rd_data2_RBUS dm_hdr_tone_lut_rd_data2_Reg;


	//read init
	dm_hdr_tone_lut_ctrl0_Reg.regValue = rtd_inl(DM_HDR_TONE_LUT_CTRL0_reg);
	dm_hdr_tone_lut_ctrl0_Reg.tone_lut_rw_sel = 2;
	/*dm_hdr_tone_lut_ctrl0_Reg.tone_lut_acc_sel = tbl_sel;*/
	rtd_outl(DM_HDR_TONE_LUT_CTRL0_reg, dm_hdr_tone_lut_ctrl0_Reg.regValue);

	do
	{
		timeoutcnt1--;
		dm_hdr_tone_lut_ctrl2_Reg.regValue = rtd_inl(DM_HDR_TONE_LUT_CTRL2_reg);
	}
	while((dm_hdr_tone_lut_ctrl2_Reg.tone_lut_acc_ready == 0) && timeoutcnt1 > 10);

	if (timeoutcnt1 <= 10)
	{
		rtd_printk(KERN_DEBUG, TAG_NAME, "PQ ERROR, DM_ToneMapping can't read!\n");
		return -1;
	}

	i = 0;
	while(i < ToneMapping_size)
	{

		//read
		dm_hdr_tone_lut_ctrl1_Reg.regValue = rtd_inl(DM_HDR_TONE_LUT_CTRL1_reg);
		dm_hdr_tone_lut_ctrl1_Reg.tone_read_en = 1;
		rtd_outl(DM_HDR_TONE_LUT_CTRL1_reg, dm_hdr_tone_lut_ctrl1_Reg.regValue);
		do
		{
			timeoutcnt2--;
			dm_hdr_tone_lut_ctrl1_Reg.regValue = rtd_inl(DM_HDR_TONE_LUT_CTRL1_reg);
		}
		while(dm_hdr_tone_lut_ctrl1_Reg.tone_read_en && timeoutcnt2 > 10);

		//data
		dm_hdr_tone_lut_rd_data0_Reg.regValue = rtd_inl(DM_HDR_TONE_LUT_RD_DATA0_reg);
		dm_hdr_tone_lut_rd_data1_Reg.regValue = rtd_inl(DM_HDR_TONE_LUT_RD_DATA1_reg);
		dm_hdr_tone_lut_rd_data2_Reg.regValue = rtd_inl(DM_HDR_TONE_LUT_RD_DATA2_reg);

		TM_table12_R[i] = dm_hdr_tone_lut_rd_data0_Reg.tone_rd_lut_data0;
		TM_table12_G[i] = dm_hdr_tone_lut_rd_data1_Reg.tone_rd_lut_data2;
		TM_table12_B[i] = dm_hdr_tone_lut_rd_data2_Reg.tone_rd_lut_data4;

		if (i + 1 < ToneMapping_size)	//data protect
		{
			TM_table12_R[i + 1] = dm_hdr_tone_lut_rd_data0_Reg.tone_rd_lut_data1;
			TM_table12_G[i + 1] = dm_hdr_tone_lut_rd_data1_Reg.tone_rd_lut_data3;
			TM_table12_B[i + 1] = dm_hdr_tone_lut_rd_data2_Reg.tone_rd_lut_data5;
		}

		i = i + 2;
	}


	//read end
	dm_hdr_tone_lut_ctrl0_Reg.regValue = rtd_inl(DM_HDR_TONE_LUT_CTRL0_reg);
	dm_hdr_tone_lut_ctrl0_Reg.tone_lut_rw_sel = 0;
	rtd_outl(DM_HDR_TONE_LUT_CTRL0_reg, dm_hdr_tone_lut_ctrl0_Reg.regValue);
	return 0;
}

char drvif_DM2_ToneMapping_Enable(unsigned char En)
{
	dm_hdr_tone_lut_ctrl0_RBUS dm_hdr_tone_lut_ctrl0_Reg;

	//read init
	dm_hdr_tone_lut_ctrl0_Reg.regValue = rtd_inl(DM_HDR_TONE_LUT_CTRL0_reg);
	dm_hdr_tone_lut_ctrl0_Reg.tone_lut_enable = En;
	rtd_outl(DM_HDR_TONE_LUT_CTRL0_reg, dm_hdr_tone_lut_ctrl0_Reg.regValue);

	//apply
	dm_hdr_double_buffer_ctrl_RBUS dm_double_buffer_ctrl_reg;
	dm_double_buffer_ctrl_reg.regValue = IoReg_Read32(DM_HDR_Double_Buffer_CTRL_reg);
	dm_double_buffer_ctrl_reg.dm_db_apply = 1;
	IoReg_Write32(DM_HDR_Double_Buffer_CTRL_reg, dm_double_buffer_ctrl_reg.regValue);
	return 0;
}

void drvif_DM2_GAMMA_Enable(unsigned char En)
{
	dm_dm_submodule_enable_RBUS dm_hdr_submodule_enable_Reg;

	//need protect by semaphore
	dm_hdr_submodule_enable_Reg.regValue = rtd_inl(DM_dm_submodule_enable_reg);
	dm_hdr_submodule_enable_Reg.gamma_enable = En;
	rtd_outl(DM_dm_submodule_enable_reg, dm_hdr_submodule_enable_Reg.regValue);
}


void drvif_DM2_GAMMA_out_shift_Enable(unsigned char En)
{
	dm_hdr_gamma_ctrl0_RBUS dm_hdr_gamma_ctrl0_Reg;

	//need protect by semaphore
	dm_hdr_gamma_ctrl0_Reg.regValue = rtd_inl(DM_HDR_GAMMA_CTRL0_reg);
	dm_hdr_gamma_ctrl0_Reg.gamma_out_shift_en = En;
	rtd_outl(DM_HDR_GAMMA_CTRL0_reg, dm_hdr_gamma_ctrl0_Reg.regValue);
}

void drvif_HDR_BBCGain_Enable(UINT8 BBCGain_En)
{
	//need protect by semaphore
	dm_hdr_path_sel_RBUS dm_hdr_path_sel_Reg;
	dm_hdr_double_buffer_ctrl_RBUS dm_double_buffer_ctrl_reg;

	dm_hdr_path_sel_Reg.regValue = rtd_inl(DM_HDR_PATH_SEL_reg);
	dm_hdr_path_sel_Reg.bbc_hdr_enable = BBCGain_En;
	rtd_outl(DM_HDR_PATH_SEL_reg, dm_hdr_path_sel_Reg.regValue);

	//apply
	dm_double_buffer_ctrl_reg.regValue = IoReg_Read32(DM_HDR_Double_Buffer_CTRL_reg);
	dm_double_buffer_ctrl_reg.dm_db_apply = 1;
	IoReg_Write32(DM_HDR_Double_Buffer_CTRL_reg, dm_double_buffer_ctrl_reg.regValue);
}

void drvif_DM2_HDR_RGB_max_Get(unsigned int *RGB_max)
{
	dm_ycctorgb_max0_RBUS dm_ycctorgb_max0_Reg;
	dm_ycctorgb_max1_RBUS dm_ycctorgb_max1_Reg;
	dm_ycctorgb_max0_Reg.regValue = rtd_inl(DM_YCCtoRGB_MAX0_reg);
	dm_ycctorgb_max1_Reg.regValue = rtd_inl(DM_YCCtoRGB_MAX1_reg);
	RGB_max[0] = dm_ycctorgb_max0_Reg.r_max;
	RGB_max[1] = dm_ycctorgb_max0_Reg.g_max;
	RGB_max[2] = dm_ycctorgb_max1_Reg.b_max;
}

unsigned char drvif_DM2_HDR_histogram_Get(unsigned int *histogram_table24)
{
	dm_dm_submodule_enable_RBUS dm_hdr_submodule_enable_Reg;
	dm_y_histogram_status0_RBUS dm_y_histogram_status0_Reg;
	dm_y_histogram_status1_RBUS dm_y_histogram_status1_Reg;
	dm_y_histogram_status2_RBUS dm_y_histogram_status2_Reg;
	dm_y_histogram_status3_RBUS dm_y_histogram_status3_Reg;
	dm_y_histogram_ctrl_RBUS dm_y_histogram_ctrl_Reg;

	UINT32 timeoutcnt1 = 0x062500;
	UINT32 timeoutcnt2 = 0x062500;
	UINT16 i;

	//need protect by semaphore
	dm_hdr_submodule_enable_Reg.regValue = rtd_inl(DM_dm_submodule_enable_reg);
	dm_hdr_submodule_enable_Reg.hist_enable = 1;
	rtd_outl(DM_dm_submodule_enable_reg, dm_hdr_submodule_enable_Reg.regValue);
	dm_y_histogram_ctrl_Reg.regValue = rtd_inl(DM_Y_histogram_ctrl_reg);
	dm_y_histogram_ctrl_Reg.hist_mode = 1;
	rtd_outl(DM_Y_histogram_ctrl_reg, dm_y_histogram_ctrl_Reg.regValue);

	do
	{
		timeoutcnt1--;
		dm_y_histogram_status0_Reg.regValue = rtd_inl(DM_Y_histogram_status0_reg);
	}
	while((dm_y_histogram_status0_Reg.hist_irq_staus == 0) && timeoutcnt1 > 10);

	if (timeoutcnt1 < 10)
	{
		//need protect by semaphore
		dm_hdr_submodule_enable_Reg.regValue = rtd_inl(DM_dm_submodule_enable_reg);
		dm_hdr_submodule_enable_Reg.hist_enable = 0;
		rtd_outl(DM_dm_submodule_enable_reg, dm_hdr_submodule_enable_Reg.regValue);
		rtd_printk(KERN_DEBUG, TAG_NAME, "PQ ERROR, DM_HDR_histogram can't read!\n");
		return 0;
	}

	for (i = 0; i < HDR_Histogram_size; i = i + 4)
	{

		dm_y_histogram_ctrl_Reg.regValue = rtd_inl(DM_Y_histogram_ctrl_reg);
		dm_y_histogram_ctrl_Reg.hist_rden = 1;
		dm_y_histogram_ctrl_Reg.hist_raddr = (i >> 2);
		rtd_outl(DM_Y_histogram_ctrl_reg, dm_y_histogram_ctrl_Reg.regValue);
		do
		{
			timeoutcnt2--;
			dm_y_histogram_ctrl_Reg.regValue = rtd_inl(DM_Y_histogram_ctrl_reg);
		} while((dm_y_histogram_ctrl_Reg.hist_rden == 1) && timeoutcnt2 > 10);
		if (timeoutcnt2 < 10)
		{
			//need protect by semaphore
			dm_hdr_submodule_enable_Reg.regValue = rtd_inl(DM_dm_submodule_enable_reg);
			dm_hdr_submodule_enable_Reg.hist_enable = 0;
			rtd_outl(DM_dm_submodule_enable_reg, dm_hdr_submodule_enable_Reg.regValue);
			rtd_printk(KERN_DEBUG, TAG_NAME, "PQ ERROR, DM_HDR_histogram read fail!\n");

			return 0;
		}

		dm_y_histogram_status0_Reg.regValue = rtd_inl(DM_Y_histogram_status0_reg);
		dm_y_histogram_status1_Reg.regValue = rtd_inl(DM_Y_histogram_status1_reg);
		dm_y_histogram_status2_Reg.regValue = rtd_inl(DM_Y_histogram_status2_reg);
		dm_y_histogram_status3_Reg.regValue = rtd_inl(DM_Y_histogram_status3_reg);
		histogram_table24[i] = dm_y_histogram_status0_Reg.hist_rdata0;
		histogram_table24[i + 1] = dm_y_histogram_status1_Reg.hist_rdata1;
		histogram_table24[i + 2] = dm_y_histogram_status2_Reg.hist_rdata2;
		histogram_table24[i + 3] = dm_y_histogram_status3_Reg.hist_rdata3;

	}

	//dm_hdr_submodule_enable_Reg.regValue = rtd_inl(DM_dm_submodule_enable_reg);
	//dm_hdr_submodule_enable_Reg.hist_enable = 0;
	//rtd_outl(DM_dm_submodule_enable_reg, dm_hdr_submodule_enable_Reg.regValue);

	#if 0	//debug
	static UINT32 rc = 0;
	rc++;
	if (rc % 91 == 0)
		for (i = 0; i < 128; i++)
			printk("histogram_table24[%d] = %d\n", i, histogram_table24[i]);
	#endif

	return 1;
}

unsigned int drvif_DM_HDR10_I_V_sta_check()
{
	vgip_vgip_chn1_act_vsta_length_RBUS vgip_chn1_act_vsta_length_reg;
	vgip_chn1_act_vsta_length_reg.regValue = IoReg_Read32(VGIP_VGIP_CHN1_ACT_VSTA_Length_reg);
	return vgip_chn1_act_vsta_length_reg.ch1_iv_act_sta;
}

unsigned char drvif_DM_HDR10_porch_check()
{
	UINT32 vgip_lineCnt;
	UINT32 vgipVend;

	vgip_lineCnt = VGIP_VGIP_CHN1_LC_get_ch1_line_cnt(rtd_inl(VGIP_VGIP_CHN1_LC_reg));
	vgipVend = VGIP_VGIP_CHN1_ACT_VSTA_Length_get_ch1_iv_act_sta(rtd_inl(VGIP_VGIP_CHN1_ACT_VSTA_Length_reg))
				+ VGIP_VGIP_CHN1_ACT_VSTA_Length_get_ch1_iv_act_len(rtd_inl(VGIP_VGIP_CHN1_ACT_VSTA_Length_reg));

	if (vgip_lineCnt > (vgipVend + 2))
		return 1;

	return 0;
}

unsigned char drvif_DM_HDR10_enable_Get()
{
	dolby_v_top_top_ctl_RBUS dolby_v_top_top_ctl_Reg;
	UINT8 HDR10_en = 0;

	//check HDR10 enable
	dolby_v_top_top_ctl_Reg.regValue = IoReg_Read32(DOLBY_V_TOP_TOP_CTL_reg);
	if (dolby_v_top_top_ctl_Reg.dolby_mode == 1 || dolby_v_top_top_ctl_Reg.dolby_mode == 3)
		HDR10_en = 1;

	return HDR10_en;
}

void drvif_DM_B05_Set(unsigned short *lutMap)
{
	dm_dm_b05_lut_ctrl0_RBUS dm_b05_lut_ctrl0_reg;
	int lutIdx = 0, lutEntryNum;//,lutIdx_tmp, loopIdx;
	int sram_addr_h,sram_addr_l;
	unsigned short *lut;
	unsigned short *lutS1;
	unsigned short *lutS2;
	unsigned short *lutS3;
	//unsigned short *lutS1End;
	//unsigned short *lutT;
	static int threeDLutUpdatedFlag = 1;

	if(!((get_OTT_HDR_mode() == HDR_MODE_DISABLE) || (get_HDMI_HDR_mode() == HDR_HDR10_HDMI))){
		return ;
	}

	// 3 17x17x17 LUTs
	lutEntryNum = 17 * 17 * 17;
	lutS1 = lut = lutMap;//pDmExec->bwDmLut.lutMap;
	lutS2 = lutS1 + lutEntryNum;
	lutS3 = lutS2 + lutEntryNum;
	lutIdx = 0;

	//for (sram_addr_h = 0; sram_addr_h < 14739; sram_addr_h++) {
	//	rtd_printk(KERN_DEBUG, TAG_NAME, "0x%x,\n", lut[sram_addr_h]);
	//}

	if (threeDLutUpdatedFlag) {

		for (sram_addr_h = 0; sram_addr_h < 17; sram_addr_h++) {
			for (sram_addr_l = 0; sram_addr_l < 17; sram_addr_l++) {

				lutIdx = ((17 * sram_addr_h) + sram_addr_l) * 51;

				//dm_b05_lut_ctrl0_reg.regValue = rtd_inl(DM_DM_B05_LUT_CTRL0_reg);
				//dm_b05_lut_ctrl0_reg.lut_b05_rw_sel = 1;	// write table
				//dm_b05_lut_ctrl0_reg.lut_b05_write_en = 0;
				//dm_b05_lut_ctrl0_reg.lut_b05_read_en = 0;
				//rtd_outl(DM_DM_B05_LUT_CTRL0_reg, dm_b05_lut_ctrl0_reg.regValue);

				// write data
				rtd_outl(DM_DM_B05_LUT_WR_DATA_1_reg, DM_DM_B05_LUT_WR_DATA_1_lut_wr_data_d0_1(lut[lutIdx+0]) |
																DM_DM_B05_LUT_WR_DATA_1_lut_wr_data_d1_1(lut[lutIdx+1]));
				rtd_outl(DM_DM_B05_LUT_WR_DATA_2_reg, DM_DM_B05_LUT_WR_DATA_2_lut_wr_data_d2_1(lut[lutIdx+2]));
				rtd_outl(DM_DM_B05_LUT_WR_DATA_3_reg, DM_DM_B05_LUT_WR_DATA_3_lut_wr_data_d0_2(lut[lutIdx+3]) |
																DM_DM_B05_LUT_WR_DATA_3_lut_wr_data_d1_2(lut[lutIdx+4]));
				rtd_outl(DM_DM_B05_LUT_WR_DATA_4_reg, DM_DM_B05_LUT_WR_DATA_4_lut_wr_data_d2_2(lut[lutIdx+5]));
				rtd_outl(DM_DM_B05_LUT_WR_DATA_5_reg, DM_DM_B05_LUT_WR_DATA_5_lut_wr_data_d0_3(lut[lutIdx+6]) |
																DM_DM_B05_LUT_WR_DATA_5_lut_wr_data_d1_3(lut[lutIdx+7]));
				rtd_outl(DM_DM_B05_LUT_WR_DATA_6_reg, DM_DM_B05_LUT_WR_DATA_6_lut_wr_data_d2_3(lut[lutIdx+8]));
				rtd_outl(DM_DM_B05_LUT_WR_DATA_7_reg, DM_DM_B05_LUT_WR_DATA_7_lut_wr_data_d0_4(lut[lutIdx+9]) |
																DM_DM_B05_LUT_WR_DATA_7_lut_wr_data_d1_4(lut[lutIdx+10]));
				rtd_outl(DM_DM_B05_LUT_WR_DATA_8_reg, DM_DM_B05_LUT_WR_DATA_8_lut_wr_data_d2_4(lut[lutIdx+11]));
				rtd_outl(DM_DM_B05_LUT_WR_DATA_9_reg, DM_DM_B05_LUT_WR_DATA_9_lut_wr_data_d0_5(lut[lutIdx+12]) |
																DM_DM_B05_LUT_WR_DATA_9_lut_wr_data_d1_5(lut[lutIdx+13]));
				rtd_outl(DM_DM_B05_LUT_WR_DATA_10_reg, DM_DM_B05_LUT_WR_DATA_10_lut_wr_data_d2_5(lut[lutIdx+14]));
				rtd_outl(DM_DM_B05_LUT_WR_DATA_11_reg, DM_DM_B05_LUT_WR_DATA_11_lut_wr_data_d0_6(lut[lutIdx+15]) |
																DM_DM_B05_LUT_WR_DATA_11_lut_wr_data_d1_6(lut[lutIdx+16]));
				rtd_outl(DM_DM_B05_LUT_WR_DATA_12_reg, DM_DM_B05_LUT_WR_DATA_12_lut_wr_data_d2_6(lut[lutIdx+17]));
				rtd_outl(DM_DM_B05_LUT_WR_DATA_13_reg, DM_DM_B05_LUT_WR_DATA_13_lut_wr_data_d0_7(lut[lutIdx+18]) |
																DM_DM_B05_LUT_WR_DATA_13_lut_wr_data_d1_7(lut[lutIdx+19]));
				rtd_outl(DM_DM_B05_LUT_WR_DATA_14_reg, DM_DM_B05_LUT_WR_DATA_14_lut_wr_data_d2_7(lut[lutIdx+20]));
				rtd_outl(DM_DM_B05_LUT_WR_DATA_15_reg, DM_DM_B05_LUT_WR_DATA_15_lut_wr_data_d0_8(lut[lutIdx+21]) |
																DM_DM_B05_LUT_WR_DATA_15_lut_wr_data_d1_8(lut[lutIdx+22]));
				rtd_outl(DM_DM_B05_LUT_WR_DATA_16_reg, DM_DM_B05_LUT_WR_DATA_16_lut_wr_data_d2_8(lut[lutIdx+23]));
				rtd_outl(DM_DM_B05_LUT_WR_DATA_17_reg, DM_DM_B05_LUT_WR_DATA_17_lut_wr_data_d0_9(lut[lutIdx+24]) |
																DM_DM_B05_LUT_WR_DATA_17_lut_wr_data_d1_9(lut[lutIdx+25]));
				rtd_outl(DM_DM_B05_LUT_WR_DATA_18_reg, DM_DM_B05_LUT_WR_DATA_18_lut_wr_data_d2_9(lut[lutIdx+26]));
				rtd_outl(DM_DM_B05_LUT_WR_DATA_19_reg, DM_DM_B05_LUT_WR_DATA_19_lut_wr_data_d0_10(lut[lutIdx+27]) |
																DM_DM_B05_LUT_WR_DATA_19_lut_wr_data_d1_10(lut[lutIdx+28]));
				rtd_outl(DM_DM_B05_LUT_WR_DATA_20_reg, DM_DM_B05_LUT_WR_DATA_20_lut_wr_data_d2_10(lut[lutIdx+29]));
				rtd_outl(DM_DM_B05_LUT_WR_DATA_21_reg, DM_DM_B05_LUT_WR_DATA_21_lut_wr_data_d0_11(lut[lutIdx+30]) |
																DM_DM_B05_LUT_WR_DATA_21_lut_wr_data_d1_11(lut[lutIdx+31]));
				rtd_outl(DM_DM_B05_LUT_WR_DATA_22_reg, DM_DM_B05_LUT_WR_DATA_22_lut_wr_data_d2_11(lut[lutIdx+32]));
				rtd_outl(DM_DM_B05_LUT_WR_DATA_23_reg, DM_DM_B05_LUT_WR_DATA_23_lut_wr_data_d0_12(lut[lutIdx+33]) |
																DM_DM_B05_LUT_WR_DATA_23_lut_wr_data_d1_12(lut[lutIdx+34]));
				rtd_outl(DM_DM_B05_LUT_WR_DATA_24_reg, DM_DM_B05_LUT_WR_DATA_24_lut_wr_data_d2_12(lut[lutIdx+35]));
				rtd_outl(DM_DM_B05_LUT_WR_DATA_25_reg, DM_DM_B05_LUT_WR_DATA_25_lut_wr_data_d0_13(lut[lutIdx+36]) |
																DM_DM_B05_LUT_WR_DATA_25_lut_wr_data_d1_13(lut[lutIdx+37]));
				rtd_outl(DM_DM_B05_LUT_WR_DATA_26_reg, DM_DM_B05_LUT_WR_DATA_26_lut_wr_data_d2_13(lut[lutIdx+38]));
				rtd_outl(DM_DM_B05_LUT_WR_DATA_27_reg, DM_DM_B05_LUT_WR_DATA_27_lut_wr_data_d0_14(lut[lutIdx+39]) |
																DM_DM_B05_LUT_WR_DATA_27_lut_wr_data_d1_14(lut[lutIdx+40]));
				rtd_outl(DM_DM_B05_LUT_WR_DATA_28_reg, DM_DM_B05_LUT_WR_DATA_28_lut_wr_data_d2_14(lut[lutIdx+41]));
				rtd_outl(DM_DM_B05_LUT_WR_DATA_29_reg, DM_DM_B05_LUT_WR_DATA_29_lut_wr_data_d0_15(lut[lutIdx+42]) |
																DM_DM_B05_LUT_WR_DATA_29_lut_wr_data_d1_15(lut[lutIdx+43]));
				rtd_outl(DM_DM_B05_LUT_WR_DATA_30_reg, DM_DM_B05_LUT_WR_DATA_30_lut_wr_data_d2_15(lut[lutIdx+44]));
				rtd_outl(DM_DM_B05_LUT_WR_DATA_31_reg, DM_DM_B05_LUT_WR_DATA_31_lut_wr_data_d0_16(lut[lutIdx+45]) |
																DM_DM_B05_LUT_WR_DATA_31_lut_wr_data_d1_16(lut[lutIdx+46]));
				rtd_outl(DM_DM_B05_LUT_WR_DATA_32_reg, DM_DM_B05_LUT_WR_DATA_32_lut_wr_data_d2_16(lut[lutIdx+47]));
				rtd_outl(DM_DM_B05_LUT_WR_DATA_33_reg, DM_DM_B05_LUT_WR_DATA_33_lut_wr_data_d0_17(lut[lutIdx+48]) |
																DM_DM_B05_LUT_WR_DATA_33_lut_wr_data_d1_17(lut[lutIdx+49]));
				rtd_outl(DM_DM_B05_LUT_WR_DATA_34_reg, DM_DM_B05_LUT_WR_DATA_34_lut_wr_data_d2_17(lut[lutIdx+50]));



				// write_en
				dm_b05_lut_ctrl0_reg.regValue = 0;
				dm_b05_lut_ctrl0_reg.lut_b05_rw_adr = ((sram_addr_h<<5) | sram_addr_l);
				dm_b05_lut_ctrl0_reg.lut_b05_write_en = 1;	// write enable
				dm_b05_lut_ctrl0_reg.lut_b05_rw_sel = 1;		// write table
				rtd_outl(DM_DM_B05_LUT_CTRL0_reg, dm_b05_lut_ctrl0_reg.regValue);
				// wait write_en clear
				{
					unsigned char cnt=10;
					while ((DM_DM_B05_LUT_CTRL0_get_lut_b05_write_en(rtd_inl(DM_DM_B05_LUT_CTRL0_reg)) != 0) && (cnt--)) {
						msleep(1);
					}
				}
			}
		}

		dm_b05_lut_ctrl0_reg.regValue = 0;
		rtd_outl(DM_DM_B05_LUT_CTRL0_reg, dm_b05_lut_ctrl0_reg.regValue);

		// read back to check data integrity
		//DM_B05_Check(lutMap);
	}

	threeDLutUpdatedFlag = 0;

}

void drvif_DM_HDR_Wait_VO_porch(void)
{
	unsigned int lineCnt_in;
	unsigned int vo_vstart;
	unsigned int vo_vend;
	unsigned int time_str = rtd_inl(0xb801b6a8);
	unsigned int time_end;

	vodma_vodma_v1sgen_RBUS vodma_v1sgen_RBUS_reg;
	UINT8 line_access_region = 17;	//default case
	vodma_v1sgen_RBUS_reg.regValue = rtd_inl(VODMA_VODMA_V1SGEN_reg);
	if (vodma_v1sgen_RBUS_reg.h_thr >= 3980)	//4k case
	{
		line_access_region = 35;
	}

	do {
		lineCnt_in = rtd_inl(VODMA_VODMA_LINE_ST_reg) & 0xfff;
		vo_vstart = rtd_inl(VODMA_VODMA_V1VGIP_VACT1_reg) & 0xfff;
		vo_vend = (rtd_inl(VODMA_VODMA_V1VGIP_VACT1_reg) >> 16) & 0xfff;
		time_end = rtd_inl(0xb801b6a8);
		if(time_str > time_end){		//overflow
			time_str = time_end;
		}
	}while (((lineCnt_in < (vo_vend + 1)) || (lineCnt_in >(vo_vend + line_access_region))) &&((time_end-time_str)<10000) );
}

char drvif_Wait_VO_start(short delay0, short delay1, unsigned short timeout)
{
	unsigned int lineCnt_in;
	unsigned int vo_vstart;
	unsigned int vo_vend;
	unsigned int time_str = rtd_inl(0xb801b6a8);
	unsigned int time_end;

	vodma_vodma_v1sgen_RBUS vodma_v1sgen_RBUS_reg;
	vodma_v1sgen_RBUS_reg.regValue = rtd_inl(VODMA_VODMA_V1SGEN_reg);

	do {
		lineCnt_in = rtd_inl(VODMA_VODMA_LINE_ST_reg) & 0xfff;
		vo_vstart = rtd_inl(VODMA_VODMA_V1VGIP_VACT1_reg) & 0xfff;
		vo_vend = (rtd_inl(VODMA_VODMA_V1VGIP_VACT1_reg) >> 16) & 0xfff;
		time_end = rtd_inl(0xb801b6a8);
		if(time_str > time_end){		//overflow
			time_str = time_end;
		}
	}while (((lineCnt_in < (vo_vstart + delay0)) || (lineCnt_in > vo_vstart + delay1)) &&((time_end-time_str)<timeout) );

	if ((time_end-time_str) > timeout)
		return -1;
	else
		return 0;

}

char drvif_Wait_VGIP_start(short delay0, short delay1, unsigned short timeout)
{
	int lineCnt_in;
	int vstart;
	int vend;
	unsigned int time_str = rtd_inl(TIMER_SCPU_CLK90K_LO_reg);
	unsigned int time_end;

	vgip_vgip_chn1_lc_RBUS vgip_chn1_lc_reg;
	vgip_vgip_chn1_act_vsta_length_RBUS vgip_chn1_act_vsta_length_reg;	// 221c

	vgip_vgip_chn1_ctrl_RBUS vgip_vgip_chn1_ctrl_Reg;
	vgip_vgip_chn1_ctrl_Reg.regValue = IoReg_Read32(VGIP_VGIP_CHN1_CTRL_reg);

	//VGIP clk disable ==> don't do anything
	if (vgip_vgip_chn1_ctrl_Reg.ch1_in_clk_en == 0)
		return -2;

	//in ForceBG, no need wait porch
	// don't add check condiction in driver, tone mapping is wating for data start
	//if (Check_AP_Set_Enable_ForceBG(SLR_MAIN_DISPLAY))
		//return 1;

	vgip_chn1_act_vsta_length_reg.regValue = IoReg_Read32(VGIP_VGIP_CHN1_ACT_VSTA_Length_reg);
	vstart = vgip_chn1_act_vsta_length_reg.ch1_iv_act_sta;
	/*printk("drvif_Wait_VGIP_start,vstart=%d,d0=%d,d1=%d\n",vstart,delay0,delay1);*/

	do {
			vgip_chn1_act_vsta_length_reg.regValue = IoReg_Read32(VGIP_VGIP_CHN1_ACT_VSTA_Length_reg);
			vgip_chn1_lc_reg.regValue = IoReg_Read32(VGIP_VGIP_CHN1_LC_reg);
			lineCnt_in = vgip_chn1_lc_reg.ch1_line_cnt;
			vstart = vgip_chn1_act_vsta_length_reg.ch1_iv_act_sta;
			time_end = rtd_inl(TIMER_SCPU_CLK90K_LO_reg);
			if(time_str > time_end){		//overflow
				time_str = time_end;
		}
	}while (((lineCnt_in < (vstart + delay0)) || (lineCnt_in > vstart + delay1)) && ((time_end-time_str)<timeout) );
	/*printk("drvif_Wait_VGIP_start,delay0=%d,%d,lineCnt_in=%d\n",delay0,delay1,lineCnt_in);*/
	if ((time_end-time_str) >= timeout)
		return -1;
	else
		return 0;

}

char drvif_Get_VGIP_Active_Info(unsigned short *v_sta, unsigned short *v_len, unsigned short *line_cnt)
{
	vgip_vgip_chn1_lc_RBUS vgip_chn1_lc_reg;
	vgip_vgip_chn1_act_vsta_length_RBUS vgip_chn1_act_vsta_length_reg;	// 221c

	vgip_vgip_chn1_ctrl_RBUS vgip_vgip_chn1_ctrl_Reg;
	vgip_vgip_chn1_ctrl_Reg.regValue = IoReg_Read32(VGIP_VGIP_CHN1_CTRL_reg);

	//VGIP clk disable ==> don't do anything
	if (vgip_vgip_chn1_ctrl_Reg.ch1_in_clk_en == 0)
		return -2;

	if ((v_sta == NULL) || (v_len == NULL) || (line_cnt == NULL)) {
		rtd_printk(KERN_EMERG, TAG_NAME, "drvif_Get_VGIP_Active_Info, NULL\n");
		return -1;
	}

	vgip_chn1_lc_reg.regValue = IoReg_Read32(VGIP_VGIP_CHN1_LC_reg);
	vgip_chn1_act_vsta_length_reg.regValue = IoReg_Read32(VGIP_VGIP_CHN1_ACT_VSTA_Length_reg);
	*v_sta = vgip_chn1_act_vsta_length_reg.ch1_iv_act_sta;
	*v_len = vgip_chn1_act_vsta_length_reg.ch1_iv_act_len;
	*line_cnt = vgip_chn1_lc_reg.ch1_line_cnt;

	return 0;
}

void drvif_Set_DM_HDR_CLK()
{
	rtd_outl(SYS_REG_SYS_CLKEN1_reg, SYS_REG_SYS_CLKEN1_clken_dolby_dm_mask | SYS_REG_SYS_CLKEN1_clken_dolby_comp_mask | SYS_REG_SYS_CLKEN1_write_data_mask);
}

//bitcorrect : k3l = 0, s4ap = 1, k4l = 1, rtice(always) = 0
char drvif_Set_DM_HDR_3dLUT_24x24x24_16(unsigned char enable, unsigned short *pArray)
{
	//write data
	#define BASE_ADDR_0 DM_DM_B05_LUT_WR_DATA_1_reg
	#define BASE_ADDR_17 DM_DM_B05_LUT_WR_DATA_35_reg
	#define BASE_ADDR_17_2 DM_DM_B05_LUT_WR_DATA_39_reg

	dm_dm_submodule_enable_RBUS dm_submodule_enable_REG;
	dm_hdr_double_buffer_ctrl_RBUS dm_double_buffer_ctrl_reg;
	dm_dm_b05_lut_ctrl2_RBUS dm_dm_b05_lut_ctrl2_Reg;
	dm_dm_b05_lut_ctrl1_RBUS dm_dm_b05_lut_ctrl1_Reg;
	dm_threedlut_minmaxc1_RBUS threedlut_minmaxc1_reg;
	dm_threedlut_minmaxc2_RBUS threedlut_minmaxc2_reg;
	dm_threedlut_minmaxc3_RBUS threedlut_minmaxc3_reg;
	dm_threedlut_minmaxinv1_RBUS threedlut_minmaxinv1_reg;
	dm_threedlut_minmaxinv2_RBUS threedlut_minmaxinv2_reg;
	dm_threedlut_minmaxinv3_RBUS threedlut_minmaxinv3_reg;

	UINT32 timeoutcnt = 0x062500;
	UINT8 i = 0, j = 0, k = 0;//, bit_shift = 0;
	UINT32 index = 0;
	UINT32 R_data, G_data, B_data;
	extern unsigned char g_HDR3DLUTForceWrite;

	dm_double_buffer_ctrl_reg.regValue = IoReg_Read32(DM_HDR_Double_Buffer_CTRL_reg);
	dm_double_buffer_ctrl_reg.dm_db_en = 1;
	IoReg_Write32(DM_HDR_Double_Buffer_CTRL_reg, dm_double_buffer_ctrl_reg.regValue);

	//set enable
	dm_submodule_enable_REG.regValue = rtd_inl(DM_dm_submodule_enable_reg);
	if (enable <= 1) {
		dm_submodule_enable_REG.b0501_enable = enable;
	}
	else
		dm_submodule_enable_REG.b0501_enable = 0;
	rtd_outl(DM_dm_submodule_enable_reg, dm_submodule_enable_REG.regValue);

	threedlut_minmaxc1_reg.regValue = IoReg_Read32(DM_ThreeDLUT_MinMaxC1_reg);
	threedlut_minmaxc2_reg.regValue = IoReg_Read32(DM_ThreeDLUT_MinMaxC2_reg);
	threedlut_minmaxc3_reg.regValue = IoReg_Read32(DM_ThreeDLUT_MinMaxC3_reg);
	threedlut_minmaxinv1_reg.regValue = IoReg_Read32(DM_ThreeDLUT_MinMaxInv1_reg);
	threedlut_minmaxinv2_reg.regValue = IoReg_Read32(DM_ThreeDLUT_MinMaxInv2_reg);
	threedlut_minmaxinv3_reg.regValue = IoReg_Read32(DM_ThreeDLUT_MinMaxInv3_reg);
	threedlut_minmaxc1_reg.regValue = 0x7fff0000;//0xffff0000;//MaxC1/MinC1
	threedlut_minmaxc2_reg.regValue = 0x7fff0000;//0xffff0000;//MaxC2/MinC2
	threedlut_minmaxc3_reg.regValue = 0x00000000;//0x00000000;//MinC3
	threedlut_minmaxinv1_reg.regValue = 0x0000b80b;
	threedlut_minmaxinv2_reg.regValue = 0x0000b80b;
	threedlut_minmaxinv3_reg.regValue = 0x0000b80b;
	IoReg_Write32(DM_ThreeDLUT_MinMaxC1_reg, threedlut_minmaxc1_reg.regValue);
	IoReg_Write32(DM_ThreeDLUT_MinMaxC2_reg, threedlut_minmaxc2_reg.regValue);
	IoReg_Write32(DM_ThreeDLUT_MinMaxC3_reg, threedlut_minmaxc3_reg.regValue);
	IoReg_Write32(DM_ThreeDLUT_MinMaxInv1_reg, threedlut_minmaxinv1_reg.regValue);
	IoReg_Write32(DM_ThreeDLUT_MinMaxInv2_reg, threedlut_minmaxinv2_reg.regValue);
	IoReg_Write32(DM_ThreeDLUT_MinMaxInv3_reg, threedlut_minmaxinv3_reg.regValue);

	//set ctrl
	dm_dm_b05_lut_ctrl1_Reg.regValue = rtd_inl(DM_DM_B05_LUT_CTRL1_reg);
	dm_dm_b05_lut_ctrl2_Reg.regValue = rtd_inl(DM_DM_B05_LUT_CTRL2_reg);
	dm_dm_b05_lut_ctrl1_Reg.lut24_b05_rw_sel = 1;
	dm_dm_b05_lut_ctrl1_Reg.lut24_b05_rw_adr = 0;
	dm_dm_b05_lut_ctrl2_Reg.dm_b05_dimension = 1;
	/*dm_dm_b05_lut_ctrl2_Reg.lut24_b05_acc_sel = tbl_sel;*/	/*tbl sel control by fw flow*/
	rtd_outl(DM_DM_B05_LUT_CTRL1_reg, dm_dm_b05_lut_ctrl1_Reg.regValue);
	rtd_outl(DM_DM_B05_LUT_CTRL2_reg, dm_dm_b05_lut_ctrl2_Reg.regValue);

	dm_double_buffer_ctrl_reg.regValue = rtd_inl(DM_HDR_Double_Buffer_CTRL_reg);
	dm_double_buffer_ctrl_reg.dm_db_apply = 1;
	rtd_outl(DM_HDR_Double_Buffer_CTRL_reg, dm_double_buffer_ctrl_reg.regValue);

	/* wait for db apply*/
	timeoutcnt = 0x062500;
	do {
		dm_double_buffer_ctrl_reg.regValue = rtd_inl(DM_HDR_Double_Buffer_CTRL_reg);
		timeoutcnt--;
	} while(dm_double_buffer_ctrl_reg.dm_db_apply == 1 && timeoutcnt > 10);

	if (timeoutcnt <= 10) {
		g_HDR3DLUTForceWrite = 1;
		return -1;
	}

	//disable, return
	if (dm_submodule_enable_REG.b0501_enable == 0) {
		g_HDR3DLUTForceWrite = 1;
		dm_submodule_temp.b0501_enable = 0;
		return 1;
	}

	timeoutcnt = 0x062500;
	for (i = 0; i < 24; i++)
	{
		for(j = 0; j < 24; j++)
		{
			dm_dm_b05_lut_ctrl1_Reg.regValue = rtd_inl(DM_DM_B05_LUT_CTRL1_reg);
			dm_dm_b05_lut_ctrl1_Reg.lut24_b05_rw_adr = (i << 5) + j;
			rtd_outl(DM_DM_B05_LUT_CTRL1_reg, dm_dm_b05_lut_ctrl1_Reg.regValue);

			for(k = 0; k < 17; k++)
			{
				R_data = pArray[index];
				index++;
				G_data = pArray[index];
				index++;
				B_data = pArray[index];
				index++;
				rtd_outl(BASE_ADDR_0 + (k * 2 * 4), (R_data << 16) + G_data);
				rtd_outl(BASE_ADDR_0 + (k * 2 * 4) + 4, B_data);
			}

			R_data = pArray[index];
			index++;
			G_data = pArray[index];
			index++;
			B_data = pArray[index];
			index++;
			rtd_outl(BASE_ADDR_17, (R_data << 16) + G_data);
			rtd_outl(BASE_ADDR_17 + 4, B_data);

			R_data = pArray[index] ;
			index++;
			G_data = pArray[index];
			index++;
			B_data = pArray[index];
			index++;
			rtd_outl(BASE_ADDR_17 + 8, (R_data << 16) + G_data);
			rtd_outl(BASE_ADDR_17 + 12, B_data);

			for(k = 0; k < (24 - 17 - 2); k++)
			{
				R_data = pArray[index];
				index++;
				G_data = pArray[index];
				index++;
				B_data = pArray[index];
				index++;
				rtd_outl(BASE_ADDR_17_2 + (k * 2 * 4), (R_data << 16) + G_data);
				rtd_outl(BASE_ADDR_17_2 + (k * 2 * 4) + 4, B_data);
			}
			dm_dm_b05_lut_ctrl1_Reg.regValue = rtd_inl(DM_DM_B05_LUT_CTRL1_reg);
			dm_dm_b05_lut_ctrl1_Reg.lut24_b05_write_en = 1;
			dm_dm_b05_lut_ctrl1_Reg.lut24_b05_read_en = 0;
			rtd_outl(DM_DM_B05_LUT_CTRL1_reg, dm_dm_b05_lut_ctrl1_Reg.regValue);
			do
			{
				timeoutcnt--;
				dm_dm_b05_lut_ctrl1_Reg.regValue = rtd_inl(DM_DM_B05_LUT_CTRL1_reg);
			} while(dm_dm_b05_lut_ctrl1_Reg.lut24_b05_write_en == 1 && timeoutcnt > 10);
		}
	}
	if (timeoutcnt <= 10)
	{
		rtd_printk(KERN_DEBUG, TAG_NAME, "PQ ERROR, 24x24x24 LUT can't write!\n");
		g_HDR3DLUTForceWrite = 1;
		return -2;
	}

	dm_dm_b05_lut_ctrl1_Reg.regValue = rtd_inl(DM_DM_B05_LUT_CTRL1_reg);
	dm_dm_b05_lut_ctrl1_Reg.lut24_b05_rw_sel = 1;
	rtd_outl(DM_DM_B05_LUT_CTRL1_reg, dm_dm_b05_lut_ctrl1_Reg.regValue);
	dm_dm_b05_lut_ctrl2_Reg.regValue = rtd_inl(DM_DM_B05_LUT_CTRL2_reg);

	dm_double_buffer_ctrl_reg.regValue = rtd_inl(DM_HDR_Double_Buffer_CTRL_reg);
	dm_double_buffer_ctrl_reg.dm_db_apply = 1;
	rtd_outl(DM_HDR_Double_Buffer_CTRL_reg, dm_double_buffer_ctrl_reg.regValue);

	dm_submodule_temp.b0501_enable = 1; /* enable 24x24x24 CSC3 in VSC*/
	g_HDR3DLUTForceWrite = 0;
	return 0;
}

char drvif_Set_DM_HDR_3dLUT_24x24x24_16_By_DMA(unsigned char enable, unsigned short *pArray, unsigned int addr, unsigned int* vir_addr)
{
	dmato3dtable_dmato3dtable_db_ctl_RBUS dmato3dtable_dmato3dtable_db_ctl_reg;
	dmato3dtable_dmato3dtable_table0_format0_RBUS dmato3dtable_dmato3dtable_table0_format0_reg;
	dmato3dtable_dmato3dtable_table0_format1_RBUS dmato3dtable_dmato3dtable_table0_format1_reg;
	dmato3dtable_dmato3dtable_table0_addr_RBUS dmato3dtable_dmato3dtable_table0_addr_reg;
	dmato3dtable_dmato3dtable_table0_burst_RBUS dmato3dtable_dmato3dtable_table0_burst_reg;
	dmato3dtable_dmato3dtable_table0_dma_RBUS dmato3dtable_dmato3dtable_table0_dma_reg;
	dmato3dtable_dmato3dtable_table0_status_RBUS dmato3dtable_dmato3dtable_table0_status_reg;

	dm_dm_submodule_enable_RBUS dm_submodule_enable_REG;
	dm_hdr_double_buffer_ctrl_RBUS dm_double_buffer_ctrl_reg;
	dm_dm_b05_lut_ctrl2_RBUS dm_dm_b05_lut_ctrl2_Reg;
	//dm_dm_b05_lut_ctrl1_RBUS dm_dm_b05_lut_ctrl1_Reg;
	dm_threedlut_minmaxc1_RBUS threedlut_minmaxc1_reg;
	dm_threedlut_minmaxc2_RBUS threedlut_minmaxc2_reg;
	dm_threedlut_minmaxc3_RBUS threedlut_minmaxc3_reg;
	dm_threedlut_minmaxinv1_RBUS threedlut_minmaxinv1_reg;
	dm_threedlut_minmaxinv2_RBUS threedlut_minmaxinv2_reg;
	dm_threedlut_minmaxinv3_RBUS threedlut_minmaxinv3_reg;
	dm_dmato3dtable_ctrl_RBUS dm_dmato3dtable_ctrl_reg;

	unsigned char *vir_addr_8=NULL;
	UINT32 pitch=0,slice=0;
	int lut_idx=0;
	int x,y,z,k;

	dm_double_buffer_ctrl_reg.regValue = IoReg_Read32(DM_HDR_Double_Buffer_CTRL_reg);
	dm_double_buffer_ctrl_reg.dm_db_en = 1;
	IoReg_Write32(DM_HDR_Double_Buffer_CTRL_reg, dm_double_buffer_ctrl_reg.regValue);

	if ((pArray == NULL) || (addr == 0) || (vir_addr == NULL)) {
		rtd_printk(KERN_EMERG, TAG_NAME, "drvif_Set_DM_HDR_3dLUT_24x24x24_16_By_DMA, table NULL, pArray=%x, addr = %x, vi_addr = %x\n",
			pArray, addr, vir_addr);
		return -1;
	}

	if (enable == 0) {
		dm_submodule_enable_REG.regValue = rtd_inl(DM_dm_submodule_enable_reg);
		dm_submodule_enable_REG.b0501_enable = 0;
		rtd_outl(DM_dm_submodule_enable_reg, dm_submodule_enable_REG.regValue);

		dm_double_buffer_ctrl_reg.regValue = rtd_inl(DM_HDR_Double_Buffer_CTRL_reg);
		dm_double_buffer_ctrl_reg.dm_db_apply = 1;
		rtd_outl(DM_HDR_Double_Buffer_CTRL_reg, dm_double_buffer_ctrl_reg.regValue);
		return 1;
	}

	dmato3dtable_dmato3dtable_table0_format0_reg.regValue = IoReg_Read32(DMATO3DTABLE_DMAto3DTable_Table0_Format0_reg);
	dmato3dtable_dmato3dtable_table0_format0_reg.table0_dma_en = 1;
	dmato3dtable_dmato3dtable_table0_format0_reg.table0_num_y = 0x18;
	dmato3dtable_dmato3dtable_table0_format0_reg.table0_num_x= 0x18;
	IoReg_Write32(DMATO3DTABLE_DMAto3DTable_Table0_Format0_reg,dmato3dtable_dmato3dtable_table0_format0_reg.regValue);

	dmato3dtable_dmato3dtable_table0_format1_reg.regValue = IoReg_Read32(DMATO3DTABLE_DMAto3DTable_Table0_Format1_reg);
	dmato3dtable_dmato3dtable_table0_format1_reg.table0_num_z = 0x18;
	IoReg_Write32(DMATO3DTABLE_DMAto3DTable_Table0_Format1_reg,dmato3dtable_dmato3dtable_table0_format1_reg.regValue);

	dmato3dtable_dmato3dtable_table0_burst_reg.regValue = IoReg_Read32(DMATO3DTABLE_DMAto3DTable_Table0_Burst_reg);
	dmato3dtable_dmato3dtable_table0_burst_reg.table0_burst_num = 0xf3;
	IoReg_Write32(DMATO3DTABLE_DMAto3DTable_Table0_Burst_reg,dmato3dtable_dmato3dtable_table0_burst_reg.regValue);

	dmato3dtable_dmato3dtable_table0_dma_reg.regValue = IoReg_Read32(DMATO3DTABLE_DMAto3DTable_Table0_DMA_reg);
	dmato3dtable_dmato3dtable_table0_dma_reg.table0_remain =0;
	IoReg_Write32(DMATO3DTABLE_DMAto3DTable_Table0_DMA_reg,dmato3dtable_dmato3dtable_table0_dma_reg.regValue);

	dm_dmato3dtable_ctrl_reg.regValue = IoReg_Read32(DM_DMAto3Dtable_CTRL_reg);
	dm_dmato3dtable_ctrl_reg.b05_dmato3dtable_en=1;
	IoReg_Write32(DM_DMAto3Dtable_CTRL_reg,dm_dmato3dtable_ctrl_reg.regValue);

	dmato3dtable_dmato3dtable_db_ctl_reg.regValue = IoReg_Read32(DMATO3DTABLE_DMAto3DTable_db_ctl_reg);
	dmato3dtable_dmato3dtable_db_ctl_reg.db_en=1;
	IoReg_Write32(DMATO3DTABLE_DMAto3DTable_db_ctl_reg,dmato3dtable_dmato3dtable_db_ctl_reg.regValue);

	/* DMA addr setting*/
	IoReg_Write32(DMATO3DTABLE_DMAto3DTable_Table0_Addr_reg, (addr/*-0x200*/));

	rtd_printk(KERN_EMERG, TAG_NAME, "\n HDR 3dlut : HDR 3dlut_phys %x , virtaddr %x \n",addr, vir_addr);

	threedlut_minmaxc1_reg.regValue = IoReg_Read32(DM_ThreeDLUT_MinMaxC1_reg);
	threedlut_minmaxc2_reg.regValue = IoReg_Read32(DM_ThreeDLUT_MinMaxC2_reg);
	threedlut_minmaxc3_reg.regValue = IoReg_Read32(DM_ThreeDLUT_MinMaxC3_reg);
	threedlut_minmaxinv1_reg.regValue = IoReg_Read32(DM_ThreeDLUT_MinMaxInv1_reg);
	threedlut_minmaxinv2_reg.regValue = IoReg_Read32(DM_ThreeDLUT_MinMaxInv2_reg);
	threedlut_minmaxinv3_reg.regValue = IoReg_Read32(DM_ThreeDLUT_MinMaxInv3_reg);
	threedlut_minmaxc1_reg.regValue = 0x7fff0000;//0xffff0000;//MaxC1/MinC1
	threedlut_minmaxc2_reg.regValue = 0x7fff0000;//0xffff0000;//MaxC2/MinC2
	threedlut_minmaxc3_reg.regValue = 0x00000000;//0x00000000;//MinC3
	threedlut_minmaxinv1_reg.regValue = 0x0000b80b;
	threedlut_minmaxinv2_reg.regValue = 0x0000b80b;
	threedlut_minmaxinv3_reg.regValue = 0x0000b80b;
	IoReg_Write32(DM_ThreeDLUT_MinMaxC1_reg, threedlut_minmaxc1_reg.regValue);
	IoReg_Write32(DM_ThreeDLUT_MinMaxC2_reg, threedlut_minmaxc2_reg.regValue);
	IoReg_Write32(DM_ThreeDLUT_MinMaxC3_reg, threedlut_minmaxc3_reg.regValue);
	IoReg_Write32(DM_ThreeDLUT_MinMaxInv1_reg, threedlut_minmaxinv1_reg.regValue);
	IoReg_Write32(DM_ThreeDLUT_MinMaxInv2_reg, threedlut_minmaxinv2_reg.regValue);
	IoReg_Write32(DM_ThreeDLUT_MinMaxInv3_reg, threedlut_minmaxinv3_reg.regValue);

	dm_double_buffer_ctrl_reg.regValue = rtd_inl(DM_HDR_Double_Buffer_CTRL_reg);
	dm_double_buffer_ctrl_reg.dm_db_apply = 1;
	rtd_outl(DM_HDR_Double_Buffer_CTRL_reg, dm_double_buffer_ctrl_reg.regValue);

	//set ctrl
	dm_dm_b05_lut_ctrl2_Reg.regValue = rtd_inl(DM_DM_B05_LUT_CTRL2_reg);
	dm_dm_b05_lut_ctrl2_Reg.dm_b05_dimension = 1;
	/*dm_dm_b05_lut_ctrl2_Reg.lut24_b05_acc_sel = tbl_sel;*/	    /*tbl sel control by fw flow*/
	rtd_outl(DM_DM_B05_LUT_CTRL2_reg, dm_dm_b05_lut_ctrl2_Reg.regValue);

	for(k=0;k<24*24*24;k++)
	{
		table[k].y=*(pArray+(k*3));
		table[k].u=*(pArray+(k*3)+1);
		table[k].v=*(pArray+(k*3)+2);

	}
	//for 3d DMA//////////////////////////////////////////////////////////////////////////////////////

	pitch = dimC3;
	slice = dimC2 * dimC3;

	for( z=0;z<(dimC3+1)/2;z++){
	   for( y=0;y<(dimC2+1)/2;y++){
		     for( x=0;x<(dimC1+1)/2;x++){
			      DDR_TABLE[lut_idx++] = table[2*x + 2*y*pitch + 2*z*slice];
			      if(x<(dimC1/2))
					DDR_TABLE[lut_idx++] = table[ (2*x+1) + 2*y*pitch + 2*z*slice];
			      if(y<(dimC2/2))
			      {
					DDR_TABLE[lut_idx++] = table[2*x + (2*y+1)*pitch + 2*z*slice];
					if(x<(dimC1/2))
						  DDR_TABLE[lut_idx++] = table[(2*x+1) + (2*y+1)*pitch + 2*z*slice];
			      }
			      if(z<(dimC3/2))
			      {
					DDR_TABLE[lut_idx++] = table[2*x + 2*y*pitch + (2*z+1)*slice];
					if(x<(dimC1/2))
						  DDR_TABLE[lut_idx++] = table[ (2*x+1) + 2*y*pitch + (2*z+1)*slice];
					if(y<(dimC2/2))
					{
						  DDR_TABLE[lut_idx++] = table[2*x + (2*y+1)*pitch + (2*z+1)*slice];
						  if(x<(dimC1/2))
							   DDR_TABLE[lut_idx++] = (table[(2*x+1) + (2*y+1)*pitch + (2*z+1)*slice]);
					}
				}
			}
		}
	}

	//  fp=fopen("3dLUT_24x24x24_ddr.txt","w");
	//rtd_printk(KERN_EMERG, TAG_NAME, "\n rord  5 3dlut : Eotf__phys %x , virtaddr %x \n",address,pVirtAddr );

	vir_addr_8 = (unsigned char*)vir_addr;

	for(lut_idx=0; lut_idx<(dimC1*dimC2*dimC3);lut_idx+=2)
	{
	 	*vir_addr_8=DDR_TABLE[lut_idx].y>>4;
		vir_addr_8++;
	 	*vir_addr_8=((DDR_TABLE[lut_idx].y&0xf)<<4)+(DDR_TABLE[lut_idx].u>>8);
	 	vir_addr_8++;
	 	*vir_addr_8=DDR_TABLE[lut_idx].u & 0xff;
	 	vir_addr_8++;
		*vir_addr_8=DDR_TABLE[lut_idx].v>>4;
	 	vir_addr_8++;
		*vir_addr_8=((DDR_TABLE[lut_idx].v&0xf)<<4)+(DDR_TABLE[lut_idx+1].y>>8);
	 	vir_addr_8++;
	 	*vir_addr_8=DDR_TABLE[lut_idx+1].y & 0xff;
	 	vir_addr_8++;
		*vir_addr_8=DDR_TABLE[lut_idx+1].u>>4;
	 	vir_addr_8++;
		*vir_addr_8=((DDR_TABLE[lut_idx+1].u&0xf)<<4)+(DDR_TABLE[lut_idx+1].v>>8);
	 	vir_addr_8++;
		*vir_addr_8=DDR_TABLE[lut_idx+1].v & 0xff;
		vir_addr_8++;
	}

	dmato3dtable_dmato3dtable_db_ctl_reg.regValue = IoReg_Read32(DMATO3DTABLE_DMAto3DTable_db_ctl_reg);
	dmato3dtable_dmato3dtable_db_ctl_reg.wtable_apply=1;
	IoReg_Write32(DMATO3DTABLE_DMAto3DTable_db_ctl_reg,dmato3dtable_dmato3dtable_db_ctl_reg.regValue);

	dmato3dtable_dmato3dtable_table0_status_reg.regValue = IoReg_Read32(DMATO3DTABLE_DMAto3DTable_Table0_Status_reg);
	dmato3dtable_dmato3dtable_table0_status_reg.table0_wdone =1;
	IoReg_Write32(DMATO3DTABLE_DMAto3DTable_Table0_Status_reg,dmato3dtable_dmato3dtable_table0_status_reg.regValue);

	dmato3dtable_dmato3dtable_db_ctl_reg.regValue = IoReg_Read32(DMATO3DTABLE_DMAto3DTable_db_ctl_reg);
	dmato3dtable_dmato3dtable_db_ctl_reg.wtable_apply=1;
	IoReg_Write32(DMATO3DTABLE_DMAto3DTable_db_ctl_reg,dmato3dtable_dmato3dtable_db_ctl_reg.regValue);

	dm_submodule_enable_REG.regValue = rtd_inl(DM_dm_submodule_enable_reg);
	dm_submodule_enable_REG.b0501_enable = enable;
	rtd_outl(DM_dm_submodule_enable_reg, dm_submodule_enable_REG.regValue);

	dm_double_buffer_ctrl_reg.regValue = rtd_inl(DM_HDR_Double_Buffer_CTRL_reg);
	dm_double_buffer_ctrl_reg.dm_db_apply = 1;
	rtd_outl(DM_HDR_Double_Buffer_CTRL_reg, dm_double_buffer_ctrl_reg.regValue);

	return 0;
}

char drvif_Get_DM_HDR_3dLUT_24x24x24_16(unsigned short *pArray)
{
	//get data
	#define BASE_ADDR_0 DM_DM_B05_LUT_RD_DATA_1_reg
	#define BASE_ADDR_17 DM_DM_B05_LUT_RD_DATA_35_reg

	dm_dm_b05_lut_ctrl2_RBUS dm_dm_b05_lut_ctrl2_Reg;
	dm_dm_b05_lut_ctrl1_RBUS dm_dm_b05_lut_ctrl1_Reg;
	dm_dm_submodule_enable_RBUS dm_submodule_enable_REG;

	UINT32 timeoutcnt = 0x062500;
	UINT8 i = 0, j = 0, k = 0;
	UINT32 temp;
	UINT32 index = 0;

 	dm_submodule_enable_REG.regValue = rtd_inl(DM_dm_submodule_enable_reg);

	//set ctrl
	dm_dm_b05_lut_ctrl1_Reg.regValue = rtd_inl(DM_DM_B05_LUT_CTRL1_reg);
	dm_dm_b05_lut_ctrl2_Reg.regValue = rtd_inl(DM_DM_B05_LUT_CTRL2_reg);

	if (dm_dm_b05_lut_ctrl2_Reg.dm_b05_dimension != 1 ||   dm_submodule_enable_REG.b0501_enable != 1)
		return 1;

	dm_dm_b05_lut_ctrl1_Reg.lut24_b05_rw_sel = 2;
	dm_dm_b05_lut_ctrl1_Reg.lut24_b05_rw_adr = 0;
	/*dm_dm_b05_lut_ctrl2_Reg.lut24_b05_acc_sel = tbl_sel;*/	/*tbl sel control by fw flow*/
	rtd_outl(DM_DM_B05_LUT_CTRL1_reg, dm_dm_b05_lut_ctrl1_Reg.regValue);
	rtd_outl(DM_DM_B05_LUT_CTRL2_reg, dm_dm_b05_lut_ctrl2_Reg.regValue);

	timeoutcnt = 0x062500;
	for (i = 0; i < 24; i++)
	{
		for(j = 0; j < 24; j++)
		{
			dm_dm_b05_lut_ctrl1_Reg.regValue = rtd_inl(DM_DM_B05_LUT_CTRL1_reg);
			dm_dm_b05_lut_ctrl1_Reg.lut24_b05_rw_adr = (i << 5) + j;
			rtd_outl(DM_DM_B05_LUT_CTRL1_reg, dm_dm_b05_lut_ctrl1_Reg.regValue);


			dm_dm_b05_lut_ctrl1_Reg.regValue = rtd_inl(DM_DM_B05_LUT_CTRL1_reg);
			dm_dm_b05_lut_ctrl1_Reg.lut24_b05_read_en = 1;
			dm_dm_b05_lut_ctrl1_Reg.lut24_b05_write_en = 0;
			rtd_outl(DM_DM_B05_LUT_CTRL1_reg, dm_dm_b05_lut_ctrl1_Reg.regValue);

			do
			{
				timeoutcnt--;
				dm_dm_b05_lut_ctrl1_Reg.regValue = rtd_inl(DM_DM_B05_LUT_CTRL1_reg);
			} while(dm_dm_b05_lut_ctrl1_Reg.lut24_b05_read_en == 1 && timeoutcnt > 10);

			for(k = 0; k < 17; k++)
			{
				temp = rtd_inl(BASE_ADDR_0 + (k * 2 * 4));
				pArray[index] = temp >> 16;
				index++;
				pArray[index] = temp & 0x0000ffff;
				index++;
				temp = rtd_inl(BASE_ADDR_0 + (k * 2 * 4) + 4);
				pArray[index] = temp & 0x0000ffff;
				index++;
			}

			for(k = 0; k < (24 - 17); k++)
			{
				temp = rtd_inl(BASE_ADDR_17 + (k * 2 * 4));
				pArray[index] = temp >> 16;
				index++;
				pArray[index] = temp & 0x0000ffff;
				index++;
				temp = rtd_inl(BASE_ADDR_17 + (k * 2 * 4) + 4);
				pArray[index] = temp & 0x0000ffff;
				index++;
			}

		}
	}

	if (timeoutcnt <= 10)
	{
		rtd_printk(KERN_DEBUG, TAG_NAME, "PQ ERROR, 24x24x24 LUT can't read!\n");
		return -2;
	}

	dm_dm_b05_lut_ctrl1_Reg.regValue = rtd_inl(DM_DM_B05_LUT_CTRL1_reg);
	dm_dm_b05_lut_ctrl1_Reg.lut24_b05_rw_sel = 0;
	rtd_outl(DM_DM_B05_LUT_CTRL1_reg, dm_dm_b05_lut_ctrl1_Reg.regValue);
	return 0;
}


void drvif_DM_HDR_3dLUT_16(unsigned char enable, unsigned short *pArray)/*flora@20150617, modify by juwen*/
{
	unsigned short ii, cnt;
	unsigned char B,G,R;
	unsigned char status;
	unsigned int baseAddress;
	unsigned char EN_status;
	dm_dm_submodule_enable_RBUS dm_submodule_enable_REG;
	dm_dm_b05_lut_ctrl0_RBUS dm_b05_lut_ctrl0_REG;
	dm_hdr_double_buffer_ctrl_RBUS dm_double_buffer_ctrl_reg;
	dm_threedlut_minmaxc1_RBUS threedlut_minmaxc1_reg;
	dm_threedlut_minmaxc2_RBUS threedlut_minmaxc2_reg;
	dm_threedlut_minmaxc3_RBUS threedlut_minmaxc3_reg;
	dm_threedlut_minmaxinv1_RBUS threedlut_minmaxinv1_reg;
	dm_threedlut_minmaxinv2_RBUS threedlut_minmaxinv2_reg;
	dm_threedlut_minmaxinv3_RBUS threedlut_minmaxinv3_reg;

	//_system_setting_info *VIP_system_info_structure_table = (_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_system_info_structure);
	_RPC_system_setting_info *VIP_RPC_system_info_structure_table = NULL;
	VIP_RPC_system_info_structure_table = (_RPC_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_RPC_system_info_structure);

	if(VIP_RPC_system_info_structure_table == NULL){
		VIPprintf("[%s:%d] Warning here!! RPC_system_info=NULL! \n",__FILE__, __LINE__);
		return;
	}

	UINT32 timeoutcnt = 0x032500;
	VIPprintf1("HDR_Setting_Flow_drvif_DM_HDR_3dLUT_16 = %d\n",VIP_RPC_system_info_structure_table->HDR_info.HDR_Setting_Status);

	// enable DM & Composer clock
	rtd_outl(SYS_REG_SYS_CLKEN1_reg, SYS_REG_SYS_CLKEN1_clken_dolby_dm_mask | SYS_REG_SYS_CLKEN1_clken_dolby_comp_mask | SYS_REG_SYS_CLKEN1_write_data_mask);

	VIP_RPC_system_info_structure_table->HDR_info.HDR_Setting_Status = 3;

	dm_double_buffer_ctrl_reg.regValue = IoReg_Read32(DM_HDR_Double_Buffer_CTRL_reg);
	dm_double_buffer_ctrl_reg.dm_db_en = 1;
	IoReg_Write32(DM_HDR_Double_Buffer_CTRL_reg, dm_double_buffer_ctrl_reg.regValue);

	dm_submodule_enable_REG.regValue = IoReg_Read32(DM_dm_submodule_enable_reg);
	EN_status = dm_submodule_enable_REG.b0501_enable;
	dm_submodule_enable_REG.b0501_enable = 0;
	IoReg_Write32(DM_dm_submodule_enable_reg, dm_submodule_enable_REG.regValue);

	threedlut_minmaxc1_reg.regValue = IoReg_Read32(DM_ThreeDLUT_MinMaxC1_reg);
	threedlut_minmaxc2_reg.regValue = IoReg_Read32(DM_ThreeDLUT_MinMaxC2_reg);
	threedlut_minmaxc3_reg.regValue = IoReg_Read32(DM_ThreeDLUT_MinMaxC3_reg);
	threedlut_minmaxinv1_reg.regValue = IoReg_Read32(DM_ThreeDLUT_MinMaxInv1_reg);
	threedlut_minmaxinv2_reg.regValue = IoReg_Read32(DM_ThreeDLUT_MinMaxInv2_reg);
	threedlut_minmaxinv3_reg.regValue = IoReg_Read32(DM_ThreeDLUT_MinMaxInv3_reg);
	threedlut_minmaxc1_reg.regValue = 0x7fff0000;//0xffff0000;//MaxC1/MinC1
	threedlut_minmaxc2_reg.regValue = 0x7fff0000;//0xffff0000;//MaxC2/MinC2
	threedlut_minmaxc3_reg.regValue = 0x00000000;//0x00000000;//MinC3
	threedlut_minmaxinv1_reg.regValue = 0x00008000;/*0x00010000; // for b01_06 Enable*///0x00004000;//iDisxC1Inv
	threedlut_minmaxinv2_reg.regValue = 0x00008000;/*0x00010000; // for b01_06 Enable*///0x00004000;//iDisxC2Inv
	threedlut_minmaxinv3_reg.regValue = 0x00008000;/*0x00010000; // for b01_06 Enable*///0x00004000;//iDisxC3Inv
	IoReg_Write32(DM_ThreeDLUT_MinMaxC1_reg, threedlut_minmaxc1_reg.regValue);
	IoReg_Write32(DM_ThreeDLUT_MinMaxC2_reg, threedlut_minmaxc2_reg.regValue);
	IoReg_Write32(DM_ThreeDLUT_MinMaxC3_reg, threedlut_minmaxc3_reg.regValue);
	IoReg_Write32(DM_ThreeDLUT_MinMaxInv1_reg, threedlut_minmaxinv1_reg.regValue);
	IoReg_Write32(DM_ThreeDLUT_MinMaxInv2_reg, threedlut_minmaxinv2_reg.regValue);
	IoReg_Write32(DM_ThreeDLUT_MinMaxInv3_reg, threedlut_minmaxinv3_reg.regValue);

	dm_double_buffer_ctrl_reg.regValue = rtd_inl(DM_HDR_Double_Buffer_CTRL_reg);
	dm_double_buffer_ctrl_reg.dm_db_apply = 1;
	rtd_outl(DM_HDR_Double_Buffer_CTRL_reg, dm_double_buffer_ctrl_reg.regValue);

	/* wait for db apply*/
	timeoutcnt = 0x062500;
	do {
		dm_double_buffer_ctrl_reg.regValue = IoReg_Read32(DM_HDR_Double_Buffer_CTRL_reg);
		timeoutcnt--;
	} while(dm_double_buffer_ctrl_reg.dm_db_apply == 1 && timeoutcnt > 0);

	/*rtd_printk(KERN_DEBUG, TAG_NAME, "~CSC3~timeoutcnt=%d\n", timeoutcnt);*/


	ii = 0;
	for(B=0; B < 17 ; B++ ) {
		for( G=0; G < 17  ; G++) {

			dm_b05_lut_ctrl0_REG.regValue = IoReg_Read32(DM_DM_B05_LUT_CTRL0_reg);
			dm_b05_lut_ctrl0_REG.lut_b05_rw_sel = 1;/*enable firmware to write table*/
			dm_b05_lut_ctrl0_REG.lut_b05_rw_adr = (B<<5) + G;
			IoReg_Write32(DM_DM_B05_LUT_CTRL0_reg, dm_b05_lut_ctrl0_REG.regValue);
			baseAddress = DM_DM_B05_LUT_WR_DATA_1_reg;

			for (R=0 ;R < 17 ;R++) {
				unsigned int tmpV=(pArray[ii]<<16)+pArray[ii+1]; /* modify by jeffrey, IC register need big endian format */
				IoReg_Write32(baseAddress, tmpV);/*d0 d1*/
				ii+=2;
				baseAddress+=4;

				tmpV=pArray[ii]; /* jeffrey */
				IoReg_Write32(baseAddress, tmpV);/*d2*/
				ii++;
				baseAddress+=4;
			} //R

			dm_b05_lut_ctrl0_REG.regValue = IoReg_Read32(DM_DM_B05_LUT_CTRL0_reg);
			dm_b05_lut_ctrl0_REG.lut_b05_write_en = 1;/*write table*/
			dm_b05_lut_ctrl0_REG.lut_b05_read_en = 0;
			IoReg_Write32(DM_DM_B05_LUT_CTRL0_reg, dm_b05_lut_ctrl0_REG.regValue);

			status = 1;

			cnt = 10000;

			while( (cnt--) && status) { /*wait for finishing writing*/
				dm_b05_lut_ctrl0_REG.regValue = IoReg_Read32(DM_DM_B05_LUT_CTRL0_reg);
				status = dm_b05_lut_ctrl0_REG.lut_b05_write_en;
			} /*while */

			if (status == 1) {
				VIPprintf(" HDR_3dLUT write error, return\n");
				/*VIPprintf(" HDR_3dLUT write error, return\n");*/
				enable = 0;
				//return;

			}/*end if */
		}/* end G */
	}/* end B */

	dm_b05_lut_ctrl0_REG.regValue = IoReg_Read32(DM_DM_B05_LUT_CTRL0_reg);
	dm_b05_lut_ctrl0_REG.lut_b05_rw_sel = 0;/*disable firmware access*/
	IoReg_Write32(DM_DM_B05_LUT_CTRL0_reg, dm_b05_lut_ctrl0_REG.regValue);

	dm_submodule_enable_REG.regValue = IoReg_Read32(DM_dm_submodule_enable_reg);
	if (enable <= 1) {
		dm_submodule_enable_REG.b0501_enable = enable;
	}
	else { /* restore */
		dm_submodule_enable_REG.b0501_enable = EN_status;
	}
	dm_submodule_temp.b0501_enable = dm_submodule_enable_REG.b0501_enable;
	IoReg_Write32(DM_dm_submodule_enable_reg, dm_submodule_enable_REG.regValue);

	dm_double_buffer_ctrl_reg.regValue = rtd_inl(DM_HDR_Double_Buffer_CTRL_reg);
	dm_double_buffer_ctrl_reg.dm_db_apply = 1;
	rtd_outl(DM_HDR_Double_Buffer_CTRL_reg, dm_double_buffer_ctrl_reg.regValue);

	VIP_RPC_system_info_structure_table->HDR_info.HDR_Setting_Status = 0;

}

#ifdef CONFIG_I2RND_B05_ENABLE
void drvif_DM_HDR_3dLUT_16_i2run(unsigned char enable, unsigned short *pArray)/*flora@20150617, modify by juwen*/
{

	rtk_hal_vsc_i2rnd_b05_enable(_ENABLE);
	set_b05_var();

	unsigned short ii, cnt;
	unsigned char B,G,R;
	unsigned char status;
	unsigned int baseAddress;
	unsigned char EN_status;
	dm_dm_submodule_enable_RBUS dm_submodule_enable_REG;
	dm_dm_b05_lut_ctrl0_RBUS dm_b05_lut_ctrl0_REG;
	dm_hdr_double_buffer_ctrl_RBUS dm_double_buffer_ctrl_reg;
	dm_threedlut_minmaxc1_RBUS threedlut_minmaxc1_reg;
	dm_threedlut_minmaxc2_RBUS threedlut_minmaxc2_reg;
	dm_threedlut_minmaxc3_RBUS threedlut_minmaxc3_reg;
	dm_threedlut_minmaxinv1_RBUS threedlut_minmaxinv1_reg;
	dm_threedlut_minmaxinv2_RBUS threedlut_minmaxinv2_reg;
	dm_threedlut_minmaxinv3_RBUS threedlut_minmaxinv3_reg;

	//_system_setting_info *VIP_system_info_structure_table = (_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_system_info_structure);
	_RPC_system_setting_info *VIP_RPC_system_info_structure_table = NULL;
	VIP_RPC_system_info_structure_table = (_RPC_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_RPC_system_info_structure);

	if(VIP_RPC_system_info_structure_table == NULL){
		VIPprintf("[%s:%d] Warning here!! RPC_system_info=NULL! \n",__FILE__, __LINE__);
		return;
	}

	UINT32 timeoutcnt = 0x032500;
	VIPprintf1("HDR_Setting_Flow_drvif_DM_HDR_3dLUT_16 = %d\n",VIP_RPC_system_info_structure_table->HDR_info.HDR_Setting_Status);

	// enable DM & Composer clock
	rtd_outl(SYS_REG_SYS_CLKEN1_reg, SYS_REG_SYS_CLKEN1_clken_dolby_dm_mask | SYS_REG_SYS_CLKEN1_clken_dolby_comp_mask | SYS_REG_SYS_CLKEN1_write_data_mask);


	VIP_RPC_system_info_structure_table->HDR_info.HDR_Setting_Status = 3;

	dm_double_buffer_ctrl_reg.regValue = IoReg_Read32(DM_HDR_Double_Buffer_CTRL_reg);
	dm_double_buffer_ctrl_reg.dm_db_en = 1;
	IoReg_Write32(DM_HDR_Double_Buffer_CTRL_reg, dm_double_buffer_ctrl_reg.regValue);

	dm_submodule_enable_REG.regValue = IoReg_Read32(DM_dm_submodule_enable_reg);
	EN_status = dm_submodule_enable_REG.b0501_enable;

	threedlut_minmaxc1_reg.regValue = IoReg_Read32(DM_ThreeDLUT_MinMaxC1_reg);
	threedlut_minmaxc2_reg.regValue = IoReg_Read32(DM_ThreeDLUT_MinMaxC2_reg);
	threedlut_minmaxc3_reg.regValue = IoReg_Read32(DM_ThreeDLUT_MinMaxC3_reg);
	threedlut_minmaxinv1_reg.regValue = IoReg_Read32(DM_ThreeDLUT_MinMaxInv1_reg);
	threedlut_minmaxinv2_reg.regValue = IoReg_Read32(DM_ThreeDLUT_MinMaxInv2_reg);
	threedlut_minmaxinv3_reg.regValue = IoReg_Read32(DM_ThreeDLUT_MinMaxInv3_reg);
	threedlut_minmaxc1_reg.regValue = 0x7fff0000;//0xffff0000;//MaxC1/MinC1
	threedlut_minmaxc2_reg.regValue = 0x7fff0000;//0xffff0000;//MaxC2/MinC2
	threedlut_minmaxc3_reg.regValue = 0x00000000;//0x00000000;//MinC3
	threedlut_minmaxinv1_reg.regValue = 0x00008000;/*0x00010000; // for b01_06 Enable*///0x00004000;//iDisxC1Inv
	threedlut_minmaxinv2_reg.regValue = 0x00008000;/*0x00010000; // for b01_06 Enable*///0x00004000;//iDisxC2Inv
	threedlut_minmaxinv3_reg.regValue = 0x00008000;/*0x00010000; // for b01_06 Enable*///0x00004000;//iDisxC3Inv
	IoReg_Write32(DM_ThreeDLUT_MinMaxC1_reg, threedlut_minmaxc1_reg.regValue);
	IoReg_Write32(DM_ThreeDLUT_MinMaxC2_reg, threedlut_minmaxc2_reg.regValue);
	IoReg_Write32(DM_ThreeDLUT_MinMaxC3_reg, threedlut_minmaxc3_reg.regValue);
	IoReg_Write32(DM_ThreeDLUT_MinMaxInv1_reg, threedlut_minmaxinv1_reg.regValue);
	IoReg_Write32(DM_ThreeDLUT_MinMaxInv2_reg, threedlut_minmaxinv2_reg.regValue);
	IoReg_Write32(DM_ThreeDLUT_MinMaxInv3_reg, threedlut_minmaxinv3_reg.regValue);

	dm_double_buffer_ctrl_reg.regValue = rtd_inl(DM_HDR_Double_Buffer_CTRL_reg);
	dm_double_buffer_ctrl_reg.dm_db_apply = 1;
	rtd_outl(DM_HDR_Double_Buffer_CTRL_reg, dm_double_buffer_ctrl_reg.regValue);

	/* wait for db apply*/
	timeoutcnt = 0x062500;
	do {
		dm_double_buffer_ctrl_reg.regValue = IoReg_Read32(DM_HDR_Double_Buffer_CTRL_reg);
		timeoutcnt--;
	} while(dm_double_buffer_ctrl_reg.dm_db_apply == 1 && timeoutcnt > 0);

	/*rtd_printk(KERN_DEBUG, TAG_NAME, "~CSC3~timeoutcnt=%d\n", timeoutcnt);*/


	ii = 0;
	for(B=0; B < 17 ; B++ ) {
		for( G=0; G < 17  ; G++) {

			baseAddress = DM_DM_B05_LUT_WR_DATA_1_reg;

			for (R=0 ;R < 17 ;R++) {
				unsigned int tmpV=(pArray[ii]<<16)+pArray[ii+1]; /* modify by jeffrey, IC register need big endian format */
				vo_b05_outl(baseAddress, tmpV);/*d0 d1*/
				ii+=2;
				baseAddress+=4;

				tmpV=pArray[ii]; /* jeffrey */
				vo_b05_outl(baseAddress, tmpV);/*d2*/
				ii++;
				baseAddress+=4;
			} //R

			dm_b05_lut_ctrl0_REG.regValue = 0;
			dm_b05_lut_ctrl0_REG.lut_b05_rw_sel = 1;/*enable firmware to write table*/
			dm_b05_lut_ctrl0_REG.lut_b05_rw_adr = (B<<5) + G;
			dm_b05_lut_ctrl0_REG.lut_b05_write_en = 1;/*write table*/
			vo_b05_outl(DM_DM_B05_LUT_CTRL0_reg, dm_b05_lut_ctrl0_REG.regValue);

		}/* end G */
	}/* end B */

	dm_b05_lut_ctrl0_REG.regValue = IoReg_Read32(DM_DM_B05_LUT_CTRL0_reg);
	dm_b05_lut_ctrl0_REG.lut_b05_rw_sel = 0;/*disable firmware access*/
	vo_b05_outl(DM_DM_B05_LUT_CTRL0_reg, dm_b05_lut_ctrl0_REG.regValue);

	dm_submodule_enable_REG.regValue = IoReg_Read32(DM_dm_submodule_enable_reg);
	if (enable <= 1) {
		dm_submodule_enable_REG.b0501_enable = enable;
	}
	else { /* restore */
		dm_submodule_enable_REG.b0501_enable = EN_status;
	}
	dm_submodule_temp.b0501_enable = dm_submodule_enable_REG.b0501_enable;
	vo_b05_outl(DM_dm_submodule_enable_reg, dm_submodule_enable_REG.regValue);


	dm_double_buffer_ctrl_reg.regValue = rtd_inl(DM_HDR_Double_Buffer_CTRL_reg);
	dm_double_buffer_ctrl_reg.dm_db_apply = 1;
	vo_b05_outl(DM_HDR_Double_Buffer_CTRL_reg, dm_double_buffer_ctrl_reg.regValue);

	VIP_RPC_system_info_structure_table->HDR_info.HDR_Setting_Status = 0;

	rtk_hal_vsc_i2rnd_b05_enable(_DISABLE);

}
#endif

void drvif_DM_HDR_3dLUT(unsigned char enable, unsigned int *pArray)/*flora@20150617, modify by juwen*/
{
	unsigned short ii, cnt;
	unsigned char B,G,R;
	unsigned char status;
	unsigned int baseAddress;
	unsigned char EN_status;
	dm_dm_submodule_enable_RBUS dm_submodule_enable_REG;
	dm_dm_b05_lut_ctrl0_RBUS dm_b05_lut_ctrl0_REG;
	/*c3dlut_c3dlut_lut_ctrl_RBUS c3dlut_lut_ctrl_REG;//juwen, c3dlut_c3dlut_lut_ctrl_RBUS replaced by dm_submodule_enable_REG*/
	dm_threedlut_minmaxc1_RBUS threedlut_minmaxc1_reg;
	dm_threedlut_minmaxc2_RBUS threedlut_minmaxc2_reg;
	dm_threedlut_minmaxc3_RBUS threedlut_minmaxc3_reg;
	dm_threedlut_minmaxinv1_RBUS threedlut_minmaxinv1_reg;
	dm_threedlut_minmaxinv2_RBUS threedlut_minmaxinv2_reg;
	dm_threedlut_minmaxinv3_RBUS threedlut_minmaxinv3_reg;

	if(!((get_OTT_HDR_mode() == HDR_MODE_DISABLE) || (get_HDMI_HDR_mode() == HDR_HDR10_HDMI))){
		return ;
	}
	/*IoReg_ClearBits(C3DLUT_C3DLUT_LUT_CTRL_reg, _BIT0); //3D LUT disable*/
	/*
	c3dlut_lut_ctrl_REG.regValue = IoReg_Read32(C3DLUT_C3DLUT_LUT_CTRL_reg);
	c3dlut_lut_ctrl_REG.C3dLUT_Ctrl=0;
	IoReg_Write32(C3DLUT_C3DLUT_LUT_CTRL_reg, c3dlut_lut_ctrl_REG.regValue);//
	disable 3D LUT
	*/

	/*if(LUT_Ctrl==0)
		// return;*/
	/* do not set enable reg while "enable" = 255, for tool access. */

	dm_hdr_double_buffer_ctrl_RBUS dm_double_buffer_ctrl_reg;

  	//_system_setting_info *VIP_system_info_structure_table = (_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_system_info_structure);
  	_RPC_system_setting_info *VIP_RPC_system_info_structure_table = NULL;
  	VIP_RPC_system_info_structure_table = (_RPC_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_RPC_system_info_structure);

	if(VIP_RPC_system_info_structure_table == NULL){
		VIPprintf("[%s:%d] Warning here!! RPC_system_info=NULL! \n",__FILE__, __LINE__);
		return;
	}

	UINT32 timeoutcnt = 0x062500;
	/*VIPprintf1("HDR_Setting_Flow_drvif_DM_HDR_3dLUT = %d\n",VIP_system_info_structure_table->HDR_info.HDR_Setting_Status);
	do {
		if(VIP_system_info_structure_table->HDR_info.HDR_Setting_Status == 0 &&
			VIP_system_info_structure_table->HDR_info.Ctrl_Item[TV006_HDR_HDR10_set] == 0) {
			VIP_system_info_structure_table->HDR_info.HDR_Setting_Status = 3;
			break;
		}
	} while(timeoutcnt-- != 0);
	VIPprintf1("HDR_Setting_Flow_drvif_DM_HDR_3dLUT, cnt = %d\n",timeoutcnt);*/

	VIP_RPC_system_info_structure_table->HDR_info.HDR_Setting_Status = 3;
	dm_double_buffer_ctrl_reg.regValue = IoReg_Read32(DM_HDR_Double_Buffer_CTRL_reg);
	dm_double_buffer_ctrl_reg.dm_db_en = 1;
	IoReg_Write32(DM_HDR_Double_Buffer_CTRL_reg, dm_double_buffer_ctrl_reg.regValue);

	dm_submodule_enable_REG.regValue = IoReg_Read32(DM_dm_submodule_enable_reg);
	EN_status = dm_submodule_enable_REG.b0501_enable;
	dm_submodule_enable_REG.b0501_enable = 0;
	/*dm_submodule_enable_REG.b01_06_enable = 0;*/
	IoReg_Write32(DM_dm_submodule_enable_reg, dm_submodule_enable_REG.regValue);

	threedlut_minmaxc1_reg.regValue = IoReg_Read32(DM_ThreeDLUT_MinMaxC1_reg);
	threedlut_minmaxc2_reg.regValue = IoReg_Read32(DM_ThreeDLUT_MinMaxC2_reg);
	threedlut_minmaxc3_reg.regValue = IoReg_Read32(DM_ThreeDLUT_MinMaxC3_reg);
	threedlut_minmaxinv1_reg.regValue = IoReg_Read32(DM_ThreeDLUT_MinMaxInv1_reg);
	threedlut_minmaxinv2_reg.regValue = IoReg_Read32(DM_ThreeDLUT_MinMaxInv2_reg);
	threedlut_minmaxinv3_reg.regValue = IoReg_Read32(DM_ThreeDLUT_MinMaxInv3_reg);
	threedlut_minmaxc1_reg.regValue = 0x7fff0000;//0xffff0000;//MaxC1/MinC1
	threedlut_minmaxc2_reg.regValue = 0x7fff0000;//0xffff0000;//MaxC2/MinC2
	threedlut_minmaxc3_reg.regValue = 0x00000000;//0x00000000;//MinC3
	threedlut_minmaxinv1_reg.regValue = 0x00008000;/*0x00010000; // for b01_06 Enable*///0x00004000;//iDisxC1Inv
	threedlut_minmaxinv2_reg.regValue = 0x00008000;/*0x00010000; // for b01_06 Enable*///0x00004000;//iDisxC2Inv
	threedlut_minmaxinv3_reg.regValue = 0x00008000;/*0x00010000; // for b01_06 Enable*///0x00004000;//iDisxC3Inv
	IoReg_Write32(DM_ThreeDLUT_MinMaxC1_reg, threedlut_minmaxc1_reg.regValue);
	IoReg_Write32(DM_ThreeDLUT_MinMaxC2_reg, threedlut_minmaxc2_reg.regValue);
	IoReg_Write32(DM_ThreeDLUT_MinMaxC3_reg, threedlut_minmaxc3_reg.regValue);
	IoReg_Write32(DM_ThreeDLUT_MinMaxInv1_reg, threedlut_minmaxinv1_reg.regValue);
	IoReg_Write32(DM_ThreeDLUT_MinMaxInv2_reg, threedlut_minmaxinv2_reg.regValue);
	IoReg_Write32(DM_ThreeDLUT_MinMaxInv3_reg, threedlut_minmaxinv3_reg.regValue);

	dm_double_buffer_ctrl_reg.regValue = rtd_inl(DM_HDR_Double_Buffer_CTRL_reg);
	dm_double_buffer_ctrl_reg.dm_db_apply = 1;
	rtd_outl(DM_HDR_Double_Buffer_CTRL_reg, dm_double_buffer_ctrl_reg.regValue);

	/* wait for db apply*/
	timeoutcnt = 0x062500;
	do {
		dm_double_buffer_ctrl_reg.regValue = IoReg_Read32(DM_HDR_Double_Buffer_CTRL_reg);
		timeoutcnt--;
	} while(dm_double_buffer_ctrl_reg.dm_db_apply == 1 && timeoutcnt > 0);

	//if(enable == 0) /*ask Flora : LUT_Ctrl=0 <=> dm_submodule_enable_REG.b01_04_enable=0?*/
	//	return;

	ii = 0;

	for(B=0; B < 17 ; B++ ) {
		for( G=0; G < 17  ; G++) {
			dm_b05_lut_ctrl0_REG.regValue = IoReg_Read32(DM_DM_B05_LUT_CTRL0_reg);
			dm_b05_lut_ctrl0_REG.lut_b05_rw_sel = 1;/*enable firmware to write table*/
			dm_b05_lut_ctrl0_REG.lut_b05_rw_adr = (B<<5) + G;
			IoReg_Write32(DM_DM_B05_LUT_CTRL0_reg, dm_b05_lut_ctrl0_REG.regValue);

			baseAddress = DM_DM_B05_LUT_WR_DATA_1_reg;
			for (R=0 ;R < 17 ;R++) {
				IoReg_Write32(baseAddress, pArray[ii]);/*d0 d1*/
				ii++;
				baseAddress+=4;
				IoReg_Write32(baseAddress, pArray[ii]);/*d2*/
				ii++;
				baseAddress+=4;
			}

			dm_b05_lut_ctrl0_REG.regValue = IoReg_Read32(DM_DM_B05_LUT_CTRL0_reg);
			dm_b05_lut_ctrl0_REG.lut_b05_write_en = 1;/*write table*/
			dm_b05_lut_ctrl0_REG.lut_b05_read_en = 0;
			IoReg_Write32(DM_DM_B05_LUT_CTRL0_reg, dm_b05_lut_ctrl0_REG.regValue);

			status = 1;
			cnt = 10000;
			while( (cnt--) && status) { /*wait for finishing writing*/
				dm_b05_lut_ctrl0_REG.regValue = IoReg_Read32(DM_DM_B05_LUT_CTRL0_reg);
				status = dm_b05_lut_ctrl0_REG.lut_b05_write_en;
			}
			if (status == 1) {
				VIPprintf(" HDR_3dLUT write error, return\n");
				/*VIPprintf(" HDR_3dLUT write error, return\n");*/
				return;
			}
		}
	}

	dm_b05_lut_ctrl0_REG.regValue = IoReg_Read32(DM_DM_B05_LUT_CTRL0_reg);
	dm_b05_lut_ctrl0_REG.lut_b05_rw_sel = 0;/*disable firmware access*/
	IoReg_Write32(DM_DM_B05_LUT_CTRL0_reg, dm_b05_lut_ctrl0_REG.regValue);

	/*dm_double_buffer_ctrl_reg.regValue = IoReg_Read32(DM_HDR_Double_Buffer_CTRL_reg);
	dm_double_buffer_ctrl_reg.dm_db_en = 1;
	IoReg_Write32(DM_HDR_Double_Buffer_CTRL_reg, dm_double_buffer_ctrl_reg.regValue);*/

	dm_submodule_enable_REG.regValue = IoReg_Read32(DM_dm_submodule_enable_reg);

	if (enable <= 1)
	{
		dm_submodule_enable_REG.b0501_enable = enable;
		/*dm_submodule_enable_REG.b01_06_enable = enable;*/
	}
	else	/* restore */
	{
		dm_submodule_enable_REG.b0501_enable = EN_status;
		/*(dm_submodule_enable_REG.b01_06_enable = EN_status;*/
	}
	IoReg_Write32(DM_dm_submodule_enable_reg, dm_submodule_enable_REG.regValue);

	dm_double_buffer_ctrl_reg.regValue = rtd_inl(DM_HDR_Double_Buffer_CTRL_reg);
	dm_double_buffer_ctrl_reg.dm_db_apply = 1;
	rtd_outl(DM_HDR_Double_Buffer_CTRL_reg, dm_double_buffer_ctrl_reg.regValue);

	VIP_RPC_system_info_structure_table->HDR_info.HDR_Setting_Status = 0;
	/*VIP_system_info_structure_table->HDR_info.HDR_Setting_Status = 1;*/

	/*//IoReg_SetBits(C3DLUT_C3DLUT_LUT_CTRL_reg, _BIT0);	//enable 3D LUT
	//juwen, 0814,
	//IoReg_Write32(C3DLUT_C3DLUT_LUT_CTRL_reg, LUT_Ctrl);	//enable 3D LUT*/
}

void drvif_Read_DM_HDR_3dLUT(unsigned char *enable, unsigned int *pArray)
{
	unsigned short ii, cnt;
	unsigned char B,G,R;
	unsigned char status;
	unsigned int baseAddress;

	dm_dm_submodule_enable_RBUS dm_submodule_enable_REG;
	dm_dm_b05_lut_ctrl0_RBUS dm_b05_lut_ctrl0_REG;

	dm_hdr_double_buffer_ctrl_RBUS dm_double_buffer_ctrl_reg;

  	//_system_setting_info *VIP_system_info_structure_table = (_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_system_info_structure);
  	_RPC_system_setting_info *VIP_RPC_system_info_structure_table = NULL;
  	VIP_RPC_system_info_structure_table = (_RPC_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_RPC_system_info_structure);

	if(VIP_RPC_system_info_structure_table == NULL){
		VIPprintf("[%s:%d] Warning here!! RPC_system_info=NULL! \n",__FILE__, __LINE__);
		return;
	}

	UINT32 timeoutcnt = 0x032500;
	/*VIPprintf1("HDR_Setting_Flow_drvif_Read_DM_HDR_3dLUT = %d\n",VIP_system_info_structure_table->HDR_info.HDR_Setting_Status);
	do {
		if(VIP_system_info_structure_table->HDR_info.HDR_Setting_Status == 0 &&
			VIP_system_info_structure_table->HDR_info.Ctrl_Item[TV006_HDR_HDR10_set] == 0) {
			VIP_system_info_structure_table->HDR_info.HDR_Setting_Status = 3;
			break;
		}
	} while(timeoutcnt-- != 0);
	VIPprintf1("HDR_Setting_Flow_drvif_Read_DM_HDR_3dLUT, cnt = %d\n",timeoutcnt);*/

	VIP_RPC_system_info_structure_table->HDR_info.HDR_Setting_Status = 3;
	dm_double_buffer_ctrl_reg.regValue = IoReg_Read32(DM_HDR_Double_Buffer_CTRL_reg);
	dm_double_buffer_ctrl_reg.dm_db_en = 1;
	IoReg_Write32(DM_HDR_Double_Buffer_CTRL_reg, dm_double_buffer_ctrl_reg.regValue);

	dm_submodule_enable_REG.regValue = IoReg_Read32(DM_dm_submodule_enable_reg);
	*enable = dm_submodule_enable_REG.b0501_enable;
	dm_submodule_enable_REG.b0501_enable = 0; /* disable while reading*/
	/*dm_submodule_enable_REG.b01_06_enable = 0;*/
	IoReg_Write32(DM_dm_submodule_enable_reg, dm_submodule_enable_REG.regValue);

	dm_double_buffer_ctrl_reg.regValue = rtd_inl(DM_HDR_Double_Buffer_CTRL_reg);
	dm_double_buffer_ctrl_reg.dm_db_apply = 1;
	rtd_outl(DM_HDR_Double_Buffer_CTRL_reg, dm_double_buffer_ctrl_reg.regValue);

	/* wait for db apply*/
	timeoutcnt = 0x062500;
	do {
		dm_double_buffer_ctrl_reg.regValue = IoReg_Read32(DM_HDR_Double_Buffer_CTRL_reg);
		timeoutcnt--;
	} while(dm_double_buffer_ctrl_reg.dm_db_apply == 1 && timeoutcnt > 0);

	ii = 0;

	for(B=0; B < 17 ; B++ ) {
		for( G=0; G < 17  ; G++) {
			dm_b05_lut_ctrl0_REG.regValue = IoReg_Read32(DM_DM_B05_LUT_CTRL0_reg);
			dm_b05_lut_ctrl0_REG.lut_b05_rw_sel = 2;/*enable firmware to read table*/
			dm_b05_lut_ctrl0_REG.lut_b05_rw_adr = (B<<5) + G;
			IoReg_Write32(DM_DM_B05_LUT_CTRL0_reg, dm_b05_lut_ctrl0_REG.regValue);

			dm_b05_lut_ctrl0_REG.regValue = IoReg_Read32(DM_DM_B05_LUT_CTRL0_reg);
			dm_b05_lut_ctrl0_REG.lut_b05_write_en = 0;/*write table*/
			dm_b05_lut_ctrl0_REG.lut_b05_read_en = 1;
			IoReg_Write32(DM_DM_B05_LUT_CTRL0_reg, dm_b05_lut_ctrl0_REG.regValue);

			status = 1;
			cnt = 10000;
			while( (cnt--) && status)/*wait for finishing writing*/
			{
				dm_b05_lut_ctrl0_REG.regValue = IoReg_Read32(DM_DM_B05_LUT_CTRL0_reg);
				status = dm_b05_lut_ctrl0_REG.lut_b05_read_en;
			}

			if (status == 1) {
				VIPprintf(" HDR_3dLUT write error, return\n");
				/*VIPprintf(" HDR_3dLUT read error, return\n");*/
				return;
			}

			baseAddress = DM_DM_B05_LUT_RD_DATA_1_reg;
			for (R=0 ;R < 17 ;R++) {
				pArray[ii] = IoReg_Read32(baseAddress); /*d0, d1*/
				ii++;
				baseAddress+=4;
				pArray[ii] = IoReg_Read32(baseAddress); /*d2*/
				ii++;
				baseAddress+=4;
			}
		}
	}

	dm_b05_lut_ctrl0_REG.regValue = IoReg_Read32(DM_DM_B05_LUT_CTRL0_reg);
	dm_b05_lut_ctrl0_REG.lut_b05_rw_sel = 0;/*disable firmware access*/
	IoReg_Write32(DM_DM_B05_LUT_CTRL0_reg, dm_b05_lut_ctrl0_REG.regValue);

	/*dm_double_buffer_ctrl_reg.regValue = IoReg_Read32(DM_HDR_Double_Buffer_CTRL_reg);
	dm_double_buffer_ctrl_reg.dm_db_en = 1;
	IoReg_Write32(DM_HDR_Double_Buffer_CTRL_reg, dm_double_buffer_ctrl_reg.regValue);*/

	/* restore*/
	dm_submodule_enable_REG.regValue = IoReg_Read32(DM_dm_submodule_enable_reg);
	dm_submodule_enable_REG.b0501_enable = *enable;

	/*dm_submodule_enable_REG.b01_06_enable = *enable;*/
	IoReg_Write32(DM_dm_submodule_enable_reg, dm_submodule_enable_REG.regValue);

	dm_double_buffer_ctrl_reg.regValue = rtd_inl(DM_HDR_Double_Buffer_CTRL_reg);
	dm_double_buffer_ctrl_reg.dm_db_apply = 1;
	rtd_outl(DM_HDR_Double_Buffer_CTRL_reg, dm_double_buffer_ctrl_reg.regValue);

	VIP_RPC_system_info_structure_table->HDR_info.HDR_Setting_Status = 0;
	/*VIP_system_info_structure_table->HDR_info.HDR_Setting_Status = 1;*/


	/*//IoReg_SetBits(C3DLUT_C3DLUT_LUT_CTRL_reg, _BIT0);	//enable 3D LUT
	//juwen, 0814,
	//IoReg_Write32(C3DLUT_C3DLUT_LUT_CTRL_reg, LUT_Ctrl);	//enable 3D LUT*/
}

//B01-02
void drvif_HDR_YUV2RGB(unsigned char enable,unsigned int *pArray)
{
#define hdr_yuv2rgb_shift 9//note by juwen : no use
	unsigned char scale;
	unsigned int coef[12];
	dm_dm_submodule_enable_RBUS dm_submodule_enable_REG;
	dm_ycctorgb_coef0_RBUS ycctorgb_coef0_REG;
	dm_ycctorgb_coef1_RBUS ycctorgb_coef1_REG;
	dm_ycctorgb_coef2_RBUS ycctorgb_coef2_REG;
	dm_ycctorgb_coef3_RBUS ycctorgb_coef3_REG;
	dm_ycctorgb_coef4_RBUS ycctorgb_coef4_REG;
	dm_ycctorgb_coef5_RBUS ycctorgb_coef5_REG;
	dm_ycctorgb_offset0_RBUS ycctorgb_offset0_REG;
	dm_ycctorgb_offset1_RBUS ycctorgb_offset1_REG;
	dm_ycctorgb_offset2_RBUS ycctorgb_offset2_REG;
	dm_ycctorgb_scale_RBUS ycctorgb_scale_REG;

	dm_hdr_double_buffer_ctrl_RBUS dm_double_buffer_ctrl_reg;
	static unsigned int lastCoef9=0xffffffff;

  	//_system_setting_info *VIP_system_info_structure_table = (_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_system_info_structure);
  	_RPC_system_setting_info *VIP_RPC_system_info_structure_table = NULL;
  	VIP_RPC_system_info_structure_table = (_RPC_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_RPC_system_info_structure);

	if(VIP_RPC_system_info_structure_table == NULL){
		VIPprintf("[%s:%d] Warning here!! RPC_system_info=NULL! \n",__FILE__, __LINE__);
		return;
	}

	/*UINT32 timeoutcnt = 0x032500;*/
	VIPprintf1("HDR_Setting_Flow_drvif_HDR_YUV2RGB = %d\n",VIP_RPC_system_info_structure_table->HDR_info.HDR_Setting_Status);

	// enable DM & Composer clock
	rtd_outl(SYS_REG_SYS_CLKEN1_reg, SYS_REG_SYS_CLKEN1_clken_dolby_dm_mask | SYS_REG_SYS_CLKEN1_clken_dolby_comp_mask | SYS_REG_SYS_CLKEN1_write_data_mask);

	/*do {
		if(VIP_system_info_structure_table->HDR_info.HDR_Setting_Status == 0 &&
			VIP_system_info_structure_table->HDR_info.Ctrl_Item[TV006_HDR_HDR10_set] == 0) {
			VIP_system_info_structure_table->HDR_info.HDR_Setting_Status = 2;
			break;
		}
	} while(timeoutcnt-- != 0);
	VIPprintf1("HDR_Setting_Flow_drvif_HDR_YUV2RGB, cnt = %d\n",timeoutcnt);*/

	VIP_RPC_system_info_structure_table->HDR_info.HDR_Setting_Status = 2;
	dm_double_buffer_ctrl_reg.regValue = IoReg_Read32(DM_HDR_Double_Buffer_CTRL_reg);
	dm_double_buffer_ctrl_reg.dm_db_en = 1;
	IoReg_Write32(DM_HDR_Double_Buffer_CTRL_reg, dm_double_buffer_ctrl_reg.regValue);

	//rtd_printk(KERN_DEBUG, TAG_NAME, "%%%%%%%drvif_HDR_YUV2RGB%%%%%%%\n");
			//dm_submodule_enable_REG.regValue = IoReg_Read32(DM_dm_submodule_enable_reg);//read all block en/dis address

	if(enable==0)
	{
		dm_submodule_temp.b01_02_enable=0;
		//IoReg_Write32(DM_dm_submodule_enable_reg, dm_submodule_enable_REG.regValue);//IoReg_Write32(address,value);
		return;
	}

	ycctorgb_scale_REG.regValue=IoReg_Read32(DM_YCCtoRGB_Scale_reg);
	scale=ycctorgb_scale_REG.ycctorgb_scale;

	memcpy(coef, pArray, 12 * sizeof(unsigned int));

	ycctorgb_coef0_REG.regValue = IoReg_Read32(DM_YCCtoRGB_coef0_reg);
	ycctorgb_coef0_REG.m33yuv2rgb00=coef[0];
	ycctorgb_coef0_REG.m33yuv2rgb01=coef[1];
	IoReg_Write32(DM_YCCtoRGB_coef0_reg, ycctorgb_coef0_REG.regValue);

	ycctorgb_coef1_REG.regValue = IoReg_Read32(DM_YCCtoRGB_coef1_reg);
	ycctorgb_coef1_REG.m33yuv2rgb02=coef[2];
	IoReg_Write32(DM_YCCtoRGB_coef1_reg, ycctorgb_coef1_REG.regValue);

	ycctorgb_coef2_REG.regValue = IoReg_Read32(DM_YCCtoRGB_coef2_reg);
	ycctorgb_coef2_REG.m33yuv2rgb10=coef[3];
	ycctorgb_coef2_REG.m33yuv2rgb11=coef[4];
	IoReg_Write32(DM_YCCtoRGB_coef2_reg, ycctorgb_coef2_REG.regValue);

	ycctorgb_coef3_REG.regValue = IoReg_Read32(DM_YCCtoRGB_coef3_reg);
	ycctorgb_coef3_REG.m33yuv2rgb12=coef[5];
	IoReg_Write32(DM_YCCtoRGB_coef3_reg, ycctorgb_coef3_REG.regValue);


	ycctorgb_coef4_REG.regValue = IoReg_Read32(DM_YCCtoRGB_coef4_reg);
	ycctorgb_coef4_REG.m33yuv2rgb20=coef[6];
	ycctorgb_coef4_REG.m33yuv2rgb21=coef[7];
	IoReg_Write32(DM_YCCtoRGB_coef4_reg, ycctorgb_coef4_REG.regValue);

	ycctorgb_coef5_REG.regValue = IoReg_Read32(DM_YCCtoRGB_coef5_reg);
	ycctorgb_coef5_REG.m33yuv2rgb22=coef[8];
	IoReg_Write32(DM_YCCtoRGB_coef5_reg, ycctorgb_coef5_REG.regValue);

	unsigned char bUpdateDmMode = (Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE) != _MODE_STATE_ACTIVE)|| (lastCoef9 != coef[9]);
	if(bUpdateDmMode){
		// check HDR mode data path -- VE compress mode need through DV normal mode

		//offset
		ycctorgb_offset0_REG.regValue = IoReg_Read32(DM_YCCtoRGB_offset0_reg);
		ycctorgb_offset0_REG.v3yuv2rgboffinrgb0=coef[9];	// offset*4 when in composer mode
		IoReg_Write32(DM_YCCtoRGB_offset0_reg, ycctorgb_offset0_REG.regValue);

		ycctorgb_offset1_REG.regValue = IoReg_Read32(DM_YCCtoRGB_offset1_reg);
		ycctorgb_offset1_REG.v3yuv2rgboffinrgb1=coef[10];// offset*4 when in composer mode
		IoReg_Write32(DM_YCCtoRGB_offset1_reg, ycctorgb_offset1_REG.regValue);

		ycctorgb_offset2_REG.regValue = IoReg_Read32(DM_YCCtoRGB_offset2_reg);
		ycctorgb_offset2_REG.v3yuv2rgboffinrgb2=coef[11];// offset*4 when in composer mode
		IoReg_Write32(DM_YCCtoRGB_offset2_reg, ycctorgb_offset2_REG.regValue);

		lastCoef9 = coef[9];
	}


	dm_submodule_temp.b01_02_enable = 1;
	//IoReg_Write32(DM_dm_submodule_enable_reg, dm_submodule_enable_REG.regValue);//IoReg_Write32(address,value);

	/*VIP_system_info_structure_table->HDR_info.HDR_Setting_Status = 1;*/

	dm_double_buffer_ctrl_reg.regValue = rtd_inl(DM_HDR_Double_Buffer_CTRL_reg);
	dm_double_buffer_ctrl_reg.dm_db_apply = 1;
	rtd_outl(DM_HDR_Double_Buffer_CTRL_reg, dm_double_buffer_ctrl_reg.regValue);

	UINT8 i;
	for (i = 0; i < matrix_COEF_Items_Max; i++) {
		VIP_RPC_system_info_structure_table->HDR_info.CSC1_YUV2RGB_Coef[i] = fwif_color_ChangeOneUINT32Endian(coef[i], 0);
	}

	VIP_RPC_system_info_structure_table->HDR_info.HDR_Setting_Status = 0;

}

//B01-04
void drvif_HDR_RGB2OPT(unsigned char enable, unsigned int *pArray)
{
	unsigned char scale;
	unsigned int coef[9];
	UINT32 timeoutcnt = 0x032500;
	//dm_dm_submodule_enable_RBUS dm_submodule_enable_REG;
	dm_rgbtoopt_coef0_RBUS rgbtoopt_coef0_REG;
	dm_rgbtoopt_coef1_RBUS rgbtoopt_coef1_REG;
	dm_rgbtoopt_coef2_RBUS rgbtoopt_coef2_REG;
	dm_rgbtoopt_coef3_RBUS rgbtoopt_coef3_REG;
	dm_rgbtoopt_coef4_RBUS rgbtoopt_coef4_REG;
	dm_rgbtoopt_coef5_RBUS rgbtoopt_coef5_REG;
	dm_rgbtoopt_scale_RBUS rgbtoopt_scale_REG;

	dm_hdr_double_buffer_ctrl_RBUS dm_double_buffer_ctrl_reg;

  	//_system_setting_info *VIP_system_info_structure_table = (_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_system_info_structure);
  	_RPC_system_setting_info *VIP_RPC_system_info_structure_table = NULL;
  	VIP_RPC_system_info_structure_table = (_RPC_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_RPC_system_info_structure);

	if(VIP_RPC_system_info_structure_table == NULL){
		VIPprintf("[%s:%d] Warning here!! RPC_system_info=NULL! \n",__FILE__, __LINE__);
		return;
	}

	if (VIP_RPC_system_info_structure_table->HDR_info.Ctrl_Item[TV006_HDR_En] == 0)
		return;

	timeoutcnt = 0x032500;
	VIPprintf1("HDR_Setting_Flow_drvif_HDR_RGB2OPT = %d\n",VIP_RPC_system_info_structure_table->HDR_info.HDR_Setting_Status);

	// enable DM & Composer clock
	rtd_outl(SYS_REG_SYS_CLKEN1_reg, SYS_REG_SYS_CLKEN1_clken_dolby_dm_mask | SYS_REG_SYS_CLKEN1_clken_dolby_comp_mask | SYS_REG_SYS_CLKEN1_write_data_mask);

	/*do {
		if(VIP_system_info_structure_table->HDR_info.HDR_Setting_Status == 0 &&
			VIP_system_info_structure_table->HDR_info.Ctrl_Item[TV006_HDR_HDR10_set] == 0) {
			VIP_system_info_structure_table->HDR_info.HDR_Setting_Status = 2;
			break;
		}
	} while(timeoutcnt-- != 0);
	VIPprintf1("HDR_Setting_Flow_drvif_HDR_RGB2OPT, cnt = %d\n",timeoutcnt);*/

	VIP_RPC_system_info_structure_table->HDR_info.HDR_Setting_Status = 2;
	dm_double_buffer_ctrl_reg.regValue = IoReg_Read32(DM_HDR_Double_Buffer_CTRL_reg);
	dm_double_buffer_ctrl_reg.dm_db_en = 1;
	IoReg_Write32(DM_HDR_Double_Buffer_CTRL_reg, dm_double_buffer_ctrl_reg.regValue);

	//dm_submodule_enable_REG.regValue = IoReg_Read32(DM_dm_submodule_enable_reg);//read all block en/dis address
	if(enable==0)
	{
		dm_submodule_temp.b01_04_enable=0;
		//IoReg_Write32(DM_dm_submodule_enable_reg, dm_submodule_enable_REG.regValue);//IoReg_Write32(address,value);
		//return;
	}

	rgbtoopt_scale_REG.regValue=IoReg_Read32(DM_RGBtoOPT_Scale_reg);
	scale=rgbtoopt_scale_REG.rgb2optscale;

	memcpy(coef, pArray, 9 * sizeof(unsigned int));

	#if 0
	unsigned char i;
	rtd_printk(KERN_DEBUG, TAG_NAME, "\n\ndrvif_HDR_RGB2OPT:\n");
	for (i = 0; i < 9; i++) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "coef[%d] = 0x%x\n", i, coef[i]);
		rtd_printk(KERN_DEBUG, TAG_NAME, "coef[%d] = 0x%x\n", i, coef[i]);
		rtd_printk(KERN_DEBUG, TAG_NAME, "coef[%d] = 0x%x\n", i, coef[i]);
	}
	#endif

	rgbtoopt_coef0_REG.regValue = IoReg_Read32(DM_RGBtoOPT_coef0_reg);
	rgbtoopt_coef0_REG.m33rgb2opt00=coef[0];
	rgbtoopt_coef0_REG.m33rgb2opt01=coef[1];
	IoReg_Write32(DM_RGBtoOPT_coef0_reg, rgbtoopt_coef0_REG.regValue);

	rgbtoopt_coef1_REG.regValue = IoReg_Read32(DM_RGBtoOPT_coef1_reg);
	rgbtoopt_coef1_REG.m33rgb2opt02=coef[2];
	IoReg_Write32(DM_RGBtoOPT_coef1_reg, rgbtoopt_coef1_REG.regValue);

	rgbtoopt_coef2_REG.regValue = IoReg_Read32(DM_RGBtoOPT_coef2_reg);
	rgbtoopt_coef2_REG.m33rgb2opt10=coef[3];
	rgbtoopt_coef2_REG.m33rgb2opt11=coef[4];
	IoReg_Write32(DM_RGBtoOPT_coef2_reg, rgbtoopt_coef2_REG.regValue);

	rgbtoopt_coef3_REG.regValue = IoReg_Read32(DM_RGBtoOPT_coef3_reg);
	rgbtoopt_coef3_REG.m33rgb2opt12=coef[5];
	IoReg_Write32(DM_RGBtoOPT_coef3_reg, rgbtoopt_coef3_REG.regValue);


	rgbtoopt_coef4_REG.regValue = IoReg_Read32(DM_RGBtoOPT_coef4_reg);
	rgbtoopt_coef4_REG.m33rgb2opt20=coef[6];
	rgbtoopt_coef4_REG.m33rgb2opt21=coef[7];
	IoReg_Write32(DM_RGBtoOPT_coef4_reg, rgbtoopt_coef4_REG.regValue);

	rgbtoopt_coef5_REG.regValue = IoReg_Read32(DM_RGBtoOPT_coef5_reg);
	rgbtoopt_coef5_REG.m33rgb2opt22=coef[8];
	IoReg_Write32(DM_RGBtoOPT_coef5_reg, rgbtoopt_coef5_REG.regValue);

	if(enable==0)
		dm_submodule_temp.b01_04_enable = 0;
	else
		dm_submodule_temp.b01_04_enable = 1;
	//IoReg_Write32(DM_dm_submodule_enable_reg, dm_submodule_enable_REG.regValue);//IoReg_Write32(address,value);

	/*VIP_system_info_structure_table->HDR_info.HDR_Setting_Status = 1;*/

	dm_double_buffer_ctrl_reg.regValue = rtd_inl(DM_HDR_Double_Buffer_CTRL_reg);
	dm_double_buffer_ctrl_reg.dm_db_apply = 1;
	rtd_outl(DM_HDR_Double_Buffer_CTRL_reg, dm_double_buffer_ctrl_reg.regValue);

	VIP_RPC_system_info_structure_table->HDR_info.HDR_Setting_Status = 0;

}

void drvif_HDMI_HDR_I3DDMA_RGB2YUV422(unsigned char enable, unsigned short *pArray, unsigned char enable_444_to_422)
{
#if 1
	h3ddma_rgb2yuv_dither_4xxto4xx_hdmi_rgb2yuv_ctrl_RBUS  ich2_RGB2YUV_CTRL_REG;
	h3ddma_rgb2yuv_dither_4xxto4xx_hdmi_rgb2yuv_tab1_m11_m12_RBUS tab1_M11_M12_REG;
	h3ddma_rgb2yuv_dither_4xxto4xx_hdmi_rgb2yuv_tab1_m13_m21_RBUS tab1_M13_M21_REG;
	h3ddma_rgb2yuv_dither_4xxto4xx_hdmi_rgb2yuv_tab1_m22_m23_RBUS tab1_M22_M23_REG;
	h3ddma_rgb2yuv_dither_4xxto4xx_hdmi_rgb2yuv_tab1_m31_m32_RBUS tab1_M31_M32_REG;
	h3ddma_rgb2yuv_dither_4xxto4xx_hdmi_rgb2yuv_tab1_m33_ygain_RBUS tab1_M33_YGain_REG;
	h3ddma_rgb2yuv_dither_4xxto4xx_hdmi_rgb2yuv_tab1_yo_RBUS tab1_Yo_REG;
	//i3ddma_scaledown_uzd_444to422_ctrl_RBUS i3ddma_scaledown_uzd_444to422_ctrl_Reg;
//	i3ddma_vsd_ctrl0_RBUS i3ddma_vsd_ctrl0_reg;

	ich2_RGB2YUV_CTRL_REG.regValue = IoReg_Read32(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_RGB2YUV_CTRL_reg);

	ich2_RGB2YUV_CTRL_REG.en_rgb2yuv= 0;

	IoReg_Write32(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_RGB2YUV_CTRL_reg, ich2_RGB2YUV_CTRL_REG.regValue);

	/*i3ddma_scaledown_uzd_444to422_ctrl_Reg.regValue = IoReg_Read32(I3DDMA_SCALEDOWN_UZD_444TO422_CTRL_VADDR);
	i3ddma_scaledown_uzd_444to422_ctrl_Reg.cr_dly_cb =*/
	/*i3ddma_vsd_ctrl0_reg.regValue = IoReg_Read32(H3DDMA_HSD_I3DDMA_VSD_Ctrl0_reg);
	if (enable_444_to_422 == 1)
		i3ddma_vsd_ctrl0_reg.sort_fmt = 0;
	else
		i3ddma_vsd_ctrl0_reg.sort_fmt = 1;*/

	if (enable == 0)
		return;

	if (pArray == NULL)
		return;

	tab1_M11_M12_REG.m11 = pArray[_RGB2YUV_m11];
	tab1_M11_M12_REG.m12 = pArray[_RGB2YUV_m12];
	IoReg_Write32(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_RGB2YUV_TAB1_M11_M12_reg, tab1_M11_M12_REG.regValue);

	tab1_M13_M21_REG.m13 = pArray[_RGB2YUV_m13];
	tab1_M13_M21_REG.m21 = pArray[_RGB2YUV_m21];
	IoReg_Write32(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_RGB2YUV_TAB1_M13_M21_reg, tab1_M13_M21_REG.regValue);

	tab1_M22_M23_REG.m22 = pArray[_RGB2YUV_m22];
	tab1_M22_M23_REG.m23 = pArray[_RGB2YUV_m23];
	IoReg_Write32(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_RGB2YUV_TAB1_M22_M23_reg, tab1_M22_M23_REG.regValue);

	tab1_M31_M32_REG.m31 = pArray[_RGB2YUV_m31];
	tab1_M31_M32_REG.m32 = pArray[_RGB2YUV_m32];
	IoReg_Write32(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_RGB2YUV_TAB1_M31_M32_reg, tab1_M31_M32_REG.regValue);

	tab1_M33_YGain_REG.m33 = pArray[_RGB2YUV_m33];
	tab1_M33_YGain_REG.y_gain= pArray[_RGB2YUV_Y_gain];
	IoReg_Write32(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_RGB2YUV_TAB1_M33_YGain_reg, tab1_M33_YGain_REG.regValue);

	tab1_Yo_REG.yo_odd= pArray[_RGB2YUV_Yo_odd];
	tab1_Yo_REG.yo_even = pArray[_RGB2YUV_Yo_even];
	IoReg_Write32(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_RGB2YUV_TAB1_Yo_reg, tab1_Yo_REG.regValue);

	ich2_RGB2YUV_CTRL_REG.sel_rgb= pArray[_RGB2YUV_sel_RGB];
	ich2_RGB2YUV_CTRL_REG.set_r_in_offset= pArray[_RGB2YUV_set_Yin_offset];
	ich2_RGB2YUV_CTRL_REG.set_uv_out_offset= pArray[_RGB2YUV_set_UV_out_offset];
	ich2_RGB2YUV_CTRL_REG.sel_uv_off= pArray[_RGB2YUV_sel_UV_off];
	ich2_RGB2YUV_CTRL_REG.matrix_bypass= pArray[_RGB2YUV_Matrix_bypass];
	ich2_RGB2YUV_CTRL_REG.sel_y_gain= pArray[_RGB2YUV_Enable_Y_gain];

	ich2_RGB2YUV_CTRL_REG.en_rgb2yuv = 1;

	IoReg_Write32(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_RGB2YUV_CTRL_reg, ich2_RGB2YUV_CTRL_REG.regValue);
#endif
#if 0
	rtd_printk(KERN_DEBUG, TAG_NAME, "[RGBHDR10]=%x,%x,%x,%x,%x,%x,%x,%x,%x\n", pArray[_RGB2YUV_m11],pArray[_RGB2YUV_m12],pArray[_RGB2YUV_m13],
	pArray[_RGB2YUV_m21],pArray[_RGB2YUV_m22],pArray[_RGB2YUV_m23],pArray[_RGB2YUV_m31],pArray[_RGB2YUV_m32],pArray[_RGB2YUV_m33]);

	rtd_printk(KERN_DEBUG, TAG_NAME, "[RGBHDR10]=%x,%x,%x,%x,%x,%x,%x,%x,%x\n", pArray[_RGB2YUV_Y_gain],pArray[_RGB2YUV_Yo_odd],pArray[_RGB2YUV_Yo_even],
	pArray[_RGB2YUV_sel_RGB],pArray[_RGB2YUV_set_Yin_offset],pArray[_RGB2YUV_set_UV_out_offset],pArray[_RGB2YUV_sel_UV_off],
	pArray[_RGB2YUV_Matrix_bypass],pArray[_RGB2YUV_Enable_Y_gain]);

	rtd_printk(KERN_DEBUG, TAG_NAME, "[RGBHDR10]=%x,%x,%x,%x,%x,%x,%x\n", IoReg_Read32(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_RGB2YUV_CTRL_reg),
		IoReg_Read32(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_RGB2YUV_TAB1_M11_M12_reg),
		IoReg_Read32(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_RGB2YUV_TAB1_M13_M21_reg),
		IoReg_Read32(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_RGB2YUV_TAB1_M22_M23_reg),
		IoReg_Read32(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_RGB2YUV_TAB1_M31_M32_reg),
		IoReg_Read32(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_RGB2YUV_TAB1_M33_YGain_reg),
		IoReg_Read32(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_RGB2YUV_TAB1_Yo_reg));
#endif
}

void drvif_HDMI_HDR_I3DDMA_RGB2YUV_only_Matrix(unsigned short *pArray)
{
	h3ddma_rgb2yuv_dither_4xxto4xx_hdmi_rgb2yuv_tab1_m11_m12_RBUS tab1_M11_M12_REG;
	h3ddma_rgb2yuv_dither_4xxto4xx_hdmi_rgb2yuv_tab1_m13_m21_RBUS tab1_M13_M21_REG;
	h3ddma_rgb2yuv_dither_4xxto4xx_hdmi_rgb2yuv_tab1_m22_m23_RBUS tab1_M22_M23_REG;
	h3ddma_rgb2yuv_dither_4xxto4xx_hdmi_rgb2yuv_tab1_m31_m32_RBUS tab1_M31_M32_REG;
	h3ddma_rgb2yuv_dither_4xxto4xx_hdmi_rgb2yuv_tab1_m33_ygain_RBUS tab1_M33_YGain_REG;
	h3ddma_rgb2yuv_dither_4xxto4xx_hdmi_rgb2yuv_tab1_yo_RBUS tab1_Yo_REG;

	tab1_M33_YGain_REG.regValue = IoReg_Read32(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_RGB2YUV_TAB1_M33_YGain_reg);

	tab1_M11_M12_REG.m11 = pArray[_RGB2YUV_m11];
	tab1_M11_M12_REG.m12 = pArray[_RGB2YUV_m12];
	IoReg_Write32(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_RGB2YUV_TAB1_M11_M12_reg, tab1_M11_M12_REG.regValue);

	tab1_M13_M21_REG.m13 = pArray[_RGB2YUV_m13];
	tab1_M13_M21_REG.m21 = pArray[_RGB2YUV_m21];
	IoReg_Write32(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_RGB2YUV_TAB1_M13_M21_reg, tab1_M13_M21_REG.regValue);

	tab1_M22_M23_REG.m22 = pArray[_RGB2YUV_m22];
	tab1_M22_M23_REG.m23 = pArray[_RGB2YUV_m23];
	IoReg_Write32(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_RGB2YUV_TAB1_M22_M23_reg, tab1_M22_M23_REG.regValue);

	tab1_M31_M32_REG.m31 = pArray[_RGB2YUV_m31];
	tab1_M31_M32_REG.m32 = pArray[_RGB2YUV_m32];
	IoReg_Write32(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_RGB2YUV_TAB1_M31_M32_reg, tab1_M31_M32_REG.regValue);

	tab1_M33_YGain_REG.m33 = pArray[_RGB2YUV_m33];
	IoReg_Write32(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_RGB2YUV_TAB1_M33_YGain_reg, tab1_M33_YGain_REG.regValue);

	tab1_Yo_REG.yo_even = pArray[_RGB2YUV_Yo_even];
	tab1_Yo_REG.yo_odd= pArray[_RGB2YUV_Yo_odd];
	IoReg_Write32(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_RGB2YUV_TAB1_Yo_reg, tab1_Yo_REG.regValue);
}

unsigned char drvif_HDR_get_VO_Decompress_Status(void)
{
	return (IoReg_Read32(VODMA_DECOMP_CTRL0_reg) & _BIT0);
}

char drvif_M_Plus_Status_Check(void)
{
	/*0xb8028c00[31] = 0*/
	char ret = 0;
	char M_Plus_algo_en = 0;

	M_Plus_algo_en = LG_M_PLUS_M_plus_ctl_get_wpr_on(IoReg_Read32(LG_M_PLUS_M_plus_ctl_reg));

	ret = M_Plus_algo_en;

	return ret;
}

// HDR10 with DV OTT mode path for VE compress mode
void drvif_HDR_Composer_bypass(void)
{
	// Composer byass mode table
	IoReg_Write32(0xb806B000, 0x000EAA00);
	IoReg_Write32(0xb806B004, 0x00222000);
	IoReg_Write32(0xb806B008, 0x03FF0000);
	IoReg_Write32(0xb806B00C, 0x03FF03FF);
	IoReg_Write32(0xb806B010, 0x03FF03FF);
	IoReg_Write32(0xb806B014, 0x03FF03FF);
	IoReg_Write32(0xb806B018, 0x000003FF);
	IoReg_Write32(0xb806B01C, 0x03FF0000);
	IoReg_Write32(0xb806B020, 0x03FF03FF);
	IoReg_Write32(0xb806B024, 0x000003FF);
	IoReg_Write32(0xb806B028, 0x03FF0000);
	IoReg_Write32(0xb806B02C, 0x03FF03FF);
	IoReg_Write32(0xb806B030, 0x000003FF);
	IoReg_Write32(0xb806B034, 0x22222222);
	IoReg_Write32(0xb806B038, 0x00002222);
	IoReg_Write32(0xb806B03C, 0x00002222);
	IoReg_Write32(0xb806B040, 0x00000000);
	IoReg_Write32(0xb806B044, 0x00000000);
	IoReg_Write32(0xb806B048, 0x00000000);
	IoReg_Write32(0xb806B04c, 0x00000000);
	IoReg_Write32(0xb806B050, 0x00000000);
	IoReg_Write32(0xb806B054, 0x00000000);
	IoReg_Write32(0xb806B058, 0x00000000);
	IoReg_Write32(0xb806B05c, 0x00000000);
	IoReg_Write32(0xb806B060, 0x00000000);
	IoReg_Write32(0xb806B064, 0x00000000);
	IoReg_Write32(0xb806B068, 0x00000000);
	IoReg_Write32(0xb806B06c, 0x00000000);
	IoReg_Write32(0xb806B070, 0x00000000);
	IoReg_Write32(0xb806B074, 0x00000000);
	IoReg_Write32(0xb806B078, 0x00000000);
	IoReg_Write32(0xb806B07c, 0x00000000);
	IoReg_Write32(0xb806B080, 0x00000000);
	IoReg_Write32(0xb806B084, 0x00000001);
	IoReg_Write32(0xb806B088, 0x00000000);
	IoReg_Write32(0xb806B0E0, 0x00000000);
	IoReg_Write32(0xb806B0E4, 0x00000001);
	IoReg_Write32(0xb806B0E8, 0x00000000);
	IoReg_Write32(0xb806B110, 0x00000000);
	IoReg_Write32(0xb806B114, 0x00000001);
	IoReg_Write32(0xb806B118, 0x00000000);
	IoReg_Write32(0xb806B2AC, 0x00000002);

	return;
}


//20160520 roger
void drvif_HDMI_Dither_Enable(UINT8 Enable)
{
	UINT8 HDMI_Dither_condition = 0;
	//hdmi_tmds_dpc0_RBUS hdmi_tmds_dpc0_RBUS_reg;
	//hdmi_tmds_dpc0_RBUS_reg.regValue = rtd_inl(HDMI_TMDS_DPC0_reg);

	if ((get_HDMI_HDR_mode() == HDR_HDR10_HDMI) && (drvif_Hdmi_GetColorDepth() == HDMI_COLOR_DEPTH_8B))
		HDMI_Dither_condition = 1;

	//HDMI ditehr, for panasonic 8bit HDR10 signal
	if (Enable && HDMI_Dither_condition)
	{
		//HDMI Dither table
		rtd_outl(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_DITHER_CTRL1_reg, 0x00000030);
		rtd_outl(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_DITHER_SEQ_R_00_15_reg, 0x3705a2e4);
		rtd_outl(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_DITHER_SEQ_R_16_31_reg, 0xcb6931f6);
		rtd_outl(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_DITHER_SEQ_G_00_07_reg, 0xe6b0d21f);
		rtd_outl(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_DITHER_SEQ_G_16_31_reg, 0xc6871b45);
		rtd_outl(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_DITHER_SEQ_B_00_15_reg, 0x38c6b49e);
		rtd_outl(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_DITHER_SEQ_B_16_31_reg, 0x1b12dbd4);
		rtd_outl(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_DITHER_TB1_R_00_reg, 0xe1968f70);
		rtd_outl(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_DITHER_TB1_R_02_reg, 0x4b3c25da);
		rtd_outl(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_DITHER_TB1_G_00_reg, 0xe1968f70);
		rtd_outl(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_DITHER_TB1_G_02_reg, 0x4b3c25da);
		rtd_outl(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_DITHER_TB1_B_00_reg, 0xe1968f70);
		rtd_outl(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_DITHER_TB1_B_02_reg, 0x4b3c25da);
		rtd_outl(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_DITHER_Temp_TB1_reg, 0xe4e4e4e4);
		rtd_outl(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_DITHER_TB2_R_00_reg, 0xe1968f70);
		rtd_outl(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_DITHER_TB2_R_02_reg, 0x4b3c25da);

		#if 0
		rtd_outl(0xb8025a00, 0x00000030);
		rtd_outl(0xb8025a04, 0x3705a2e4);
		rtd_outl(0xb8025a08, 0xcb6931f6);
		rtd_outl(0xb8025a0c, 0xe6b0d21f);
		rtd_outl(0xb8025a10, 0xc6871b45);
		rtd_outl(0xb8025a14, 0x38c6b49e);
		rtd_outl(0xb8025a18, 0x1b12dbd4);
		rtd_outl(0xb8025a1c, 0xe1968f70);
		rtd_outl(0xb8025a20, 0x4b3c25da);
		rtd_outl(0xb8025a24, 0xe1968f70);
		rtd_outl(0xb8025a28, 0x4b3c25da);
		rtd_outl(0xb8025a2c, 0xe1968f70);
		rtd_outl(0xb8025a30, 0x4b3c25da);
		rtd_outl(0xb8025a34, 0xe4e4e4e4);
		rtd_outl(0xb8025a38, 0xe1968f70);
		rtd_outl(0xb8025a3c, 0x4b3c25da);
		#endif

		//HDMI Dither enable
		h3ddma_rgb2yuv_dither_4xxto4xx_hdmi_dither_ctrl1_RBUS hdmi_dither_ctrl1_RBUS_reg;
		hdmi_dither_ctrl1_RBUS_reg.regValue = rtd_inl(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_DITHER_CTRL1_reg);
		hdmi_dither_ctrl1_RBUS_reg.ch2_temporal_enable = 1;
		hdmi_dither_ctrl1_RBUS_reg.ch2_dithering_table_select = 1;
		rtd_outl(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_DITHER_CTRL1_reg, hdmi_dither_ctrl1_RBUS_reg.regValue);

	}
	else
	{
		//HDMI Dither disable
		h3ddma_rgb2yuv_dither_4xxto4xx_hdmi_dither_ctrl1_RBUS hdmi_dither_ctrl1_RBUS_reg;
		hdmi_dither_ctrl1_RBUS_reg.regValue = rtd_inl(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_DITHER_CTRL1_reg);
		hdmi_dither_ctrl1_RBUS_reg.ch2_dithering_table_select = 0;
		rtd_outl(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_DITHER_CTRL1_reg, hdmi_dither_ctrl1_RBUS_reg.regValue);
	}

}

void drvif_reset_EOTF_OETF_table(void)
{
#if 0
	extern UINT32 pre_Eotf_table32[1025];
	extern UINT16 pre_Oetf_table16[1025];
	UINT16 i;
	for (i = 0; i < 1025; i++)
	{
		pre_Eotf_table32[i] = 0;
		pre_Oetf_table16[i] = 0;
	}
#endif
}

unsigned char drvif_color_set_BBC_Enable(unsigned char enable)
{
	dm_hdr_path_sel_RBUS dm_hdr_path_sel_Reg;
	dm_hdr_path_sel_Reg.regValue = rtd_inl(DM_HDR_PATH_SEL_reg);

	if (enable)
	{
		//enable BBC
		dm_hdr_path_sel_Reg.bbc_hdr_enable = 1;
		dm_hdr_path_sel_Reg.b05_position = 1;
		rtd_outl(DM_HDR_PATH_SEL_reg, dm_hdr_path_sel_Reg.regValue);

		//using Global dm_submodule_temp to set DM
		dm_submodule_temp.b01_03_enable = 0;
		dm_submodule_temp.b01_05_enable = 0;
		dm_submodule_temp.b01_04_enable = 0;

		//BBC RGB2Y
		dm_bbc_rgb2y1_RBUS dm_bbc_rgb2y1_Reg;
		dm_bbc_rgb2y2_RBUS dm_bbc_rgb2y2_Reg;
		dm_bbc_rgb2y1_Reg.rgb2y_coef_r = 0x4340;
		dm_bbc_rgb2y1_Reg.rgb2y_coef_g = 0xad90;
		dm_bbc_rgb2y2_Reg.rgb2y_coef_b = 0x0f30;

		rtd_outl(DM_bbc_rgb2y1_reg, dm_bbc_rgb2y1_Reg.regValue);
		rtd_outl(DM_bbc_rgb2y2_reg, dm_bbc_rgb2y2_Reg.regValue);

	}
	else
	{
		//disable BBC
		dm_hdr_path_sel_Reg.bbc_hdr_enable = 0;
		dm_hdr_path_sel_Reg.b05_position = 0;
		rtd_outl(DM_HDR_PATH_SEL_reg, dm_hdr_path_sel_Reg.regValue);
	}

	//apply
	dm_hdr_double_buffer_ctrl_RBUS dm_double_buffer_ctrl_reg;
	dm_double_buffer_ctrl_reg.regValue = IoReg_Read32(DM_HDR_Double_Buffer_CTRL_reg);
	dm_double_buffer_ctrl_reg.dm_db_apply = 1;
	IoReg_Write32(DM_HDR_Double_Buffer_CTRL_reg, dm_double_buffer_ctrl_reg.regValue);
	return TRUE;
}


#if CONFIG_FIRMWARE_IN_KERNEL
unsigned char drvif_color_set_HDR10_Enable(unsigned char* enable)
{
	dolby_v_top_top_ctl_RBUS top_ctl_reg;
	dolby_v_top_top_pic_size_RBUS top_pic_size_reg;
	dolby_v_top_top_pic_total_RBUS top_pic_total_reg;
	dolby_v_top_top_pic_sta_RBUS top_pic_sta_reg;
	dolby_v_top_top_d_buf_RBUS top_d_buf_reg;
	vgip_vgip_chn1_misc_RBUS vgip_chn1_misc_reg;
	dm_input_format_RBUS input_format_reg;
	dm_dm_submodule_enable_RBUS dm_submodule_enable_reg;
	dm_hdr_path_sel_RBUS dm_hdr_path_sel_reg;
	dm_ycctorgb_scale_RBUS ycctorgb_scale_reg;
	dm_signal_range_RBUS signal_range_reg;
	dm_srangeinv_RBUS srangeinv_reg;
	dm_rgbtoopt_scale_RBUS rgbtoopt_scale_reg;
	dm_saturationadj_RBUS dm_saturationadj_reg;
	dm_hdr_double_buffer_ctrl_RBUS dm_double_buffer_ctrl_reg;
	dhdr_v_composer_composer_db_ctrl_RBUS composer_db_ctrl_reg;
	dm_eotf_para1_RBUS eotf_para1_reg;
	dm_rgbtoopt_scale_RBUS dm_rgbtoopt_scale_Reg;
	UINT16 HDR_h, HDR_v;
	UINT32 timeoutcnt = 0x032500;
#if 0	/* determine dolby or HDR10 at "decide_hdr_mode(), seamless will change get_OTT_HDR_mode as HDR_HDR10_VDEC"*/
	if(!((get_OTT_HDR_mode() == HDR_MODE_DISABLE) || (get_HDMI_HDR_mode() == HDR_HDR10_HDMI))){
		rtd_printk(KERN_INFO, TAG_NAME, "drvif_color_set_HDR10_Enable retunr 111\n");
		return 1;
	}
#endif
	// enable DM & Composer clock
	rtd_outl(SYS_REG_SYS_CLKEN1_reg, SYS_REG_SYS_CLKEN1_clken_dolby_dm_mask | SYS_REG_SYS_CLKEN1_clken_dolby_comp_mask | SYS_REG_SYS_CLKEN1_write_data_mask);

	unsigned char bInDolbyMode = DOLBY_V_TOP_TOP_CTL_get_dolby_mode(IoReg_Read32(DOLBY_V_TOP_TOP_CTL_reg));
	extern unsigned char Get_vo_smoothtoggle_timingchange_flag(unsigned char display);
	unsigned char bUpdateDolbyMode = (Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE) != _MODE_STATE_ACTIVE)
		|| (bInDolbyMode == 0)|| (Get_vo_smoothtoggle_timingchange_flag(SLR_MAIN_DISPLAY) == 0);

	if((bUpdateDolbyMode == FALSE) && (enable[HDR_EN]) == 1)
	{
		rtd_printk(KERN_INFO, TAG_NAME, "drvif_color_set_HDR10_Enable retunr 222\n");
		pr_notice("[HDR] Ignore HDR udpate %d/%d\n", Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE) , bInDolbyMode);
		return 1;
	}

	// check HDR mode data path -- VE compress mode need through DV normal mode
	unsigned char bVeCompressMode;
	bVeCompressMode = drvif_HDR_get_VO_Decompress_Status();

	// Composer bypass -- init
	composer_db_ctrl_reg.regValue = rtd_inl(DHDR_V_COMPOSER_Composer_db_ctrl_reg);
	composer_db_ctrl_reg.composer_db_en = 1;
	rtd_outl(DHDR_V_COMPOSER_Composer_db_ctrl_reg, composer_db_ctrl_reg.regValue);

	// Composer bypass
	drvif_HDR_Composer_bypass();

	// in compress mode update video size in VODMA
	top_pic_size_reg.regValue = IoReg_Read32(DOLBY_V_TOP_TOP_PIC_SIZE_reg);
	top_pic_sta_reg.regValue = IoReg_Read32(DOLBY_V_TOP_TOP_PIC_STA_reg);

	//_system_setting_info *VIP_system_info_structure_table = (_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_system_info_structure);
	_RPC_system_setting_info *VIP_RPC_system_info_structure_table = NULL;
	VIP_RPC_system_info_structure_table = (_RPC_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_RPC_system_info_structure);

	if(VIP_RPC_system_info_structure_table == NULL){
		VIPprintf("[%s:%d] Warning here!! RPC_system_info=NULL! \n",__FILE__, __LINE__);
		return;
	}

	top_ctl_reg.regValue = IoReg_Read32(DOLBY_V_TOP_TOP_CTL_reg);
	top_pic_total_reg.regValue = IoReg_Read32(DOLBY_V_TOP_TOP_PIC_TOTAL_reg);
	top_d_buf_reg.regValue = IoReg_Read32(DOLBY_V_TOP_TOP_D_BUF_reg);
	vgip_chn1_misc_reg.regValue = IoReg_Read32(VGIP_VGIP_CHN1_MISC_reg);
	input_format_reg.regValue = IoReg_Read32(DM_Input_Format_reg);
	dm_submodule_enable_reg.regValue = IoReg_Read32(DM_dm_submodule_enable_reg);
	dm_hdr_path_sel_reg.regValue = IoReg_Read32(DM_HDR_PATH_SEL_reg);
	ycctorgb_scale_reg.regValue = IoReg_Read32(DM_YCCtoRGB_Scale_reg);
	signal_range_reg.regValue = IoReg_Read32(DM_Signal_range_reg);
	srangeinv_reg.regValue = IoReg_Read32(DM_sRangeInv_reg);
	rgbtoopt_scale_reg.regValue = IoReg_Read32(DM_RGBtoOPT_Scale_reg);

	dm_double_buffer_ctrl_reg.regValue = IoReg_Read32(DM_HDR_Double_Buffer_CTRL_reg);
	eotf_para1_reg.regValue = IoReg_Read32(DM_EOTF_para1_reg);

	timeoutcnt = 0x032500;
	VIPprintf1("HDR_Setting_Flow_drvif_color_set_HDR10_Enable = %d\n",VIP_RPC_system_info_structure_table->HDR_info.HDR_Setting_Status);

	VIP_RPC_system_info_structure_table->HDR_info.HDR_Setting_Status = 2;

	dm_double_buffer_ctrl_reg.regValue = IoReg_Read32(DM_HDR_Double_Buffer_CTRL_reg);
	dm_double_buffer_ctrl_reg.dm_db_en = 1;
	IoReg_Write32(DM_HDR_Double_Buffer_CTRL_reg, dm_double_buffer_ctrl_reg.regValue);

	top_d_buf_reg.dolby_double_en = 1;
	IoReg_Write32(DOLBY_V_TOP_TOP_D_BUF_reg, top_d_buf_reg.regValue);

	vodma_vodma_v1_dsize_RBUS vodma_v1_dsize_RBUS_reg;
	vodma_v1_dsize_RBUS_reg.regValue = IoReg_Read32(VODMA_VODMA_V1_DSIZE_reg);

	HDR_h = vodma_v1_dsize_RBUS_reg.p_y_len;
	HDR_v = vodma_v1_dsize_RBUS_reg.p_y_nline;



	if (enable[HDR_EN])
	{
		dm_submodule_temp.b01_02_enable = 1;
		dm_submodule_temp.b01_03_enable = 0;	//20160921 roger, K3L have EOTF/OETF table setting by LG, don't enable this, we don't have this function in LG
		dm_submodule_temp.b01_05_enable = 0;	//20160921 roger, K3L have EOTF/OETF table setting by LG, don't enable this, we don't have this function in LG
		dm_submodule_temp.b01_07_enable = 0;
		dm_submodule_temp.b03_enable = 0;
		dm_submodule_temp.b04_enable = 0;
		dm_submodule_temp.b01_06_enable = 0;
		dm_submodule_temp.b01_01_420to422_enable = enable[HDR_420_2_422];
		dm_submodule_temp.b01_01_422to444_enable = enable[HDR_422_2_444];
		dm_submodule_temp.dither_en = enable[HDR_DITHER];

		dm_submodule_temp.b0502_enable = 0;


		dm_saturationadj_reg.regValue = IoReg_Read32(DM_SaturationAdj_reg);
		dm_saturationadj_reg.bypass_unsigned_en = 1;
		IoReg_Write32(DM_SaturationAdj_reg, dm_saturationadj_reg.regValue);

		top_pic_total_reg.dolby_h_total = (IoReg_Read32(VODMA_VODMA_V1SGEN_reg) & 0x00001FFF) + 1;	//0x1131;

		if(bUpdateDolbyMode == TRUE){ // dolby mode change by video fw
			top_ctl_reg.dolby_mode = (bVeCompressMode? 3: 1); // 1: HDMI mode, 3: HDMI with VO decompress mode
			top_ctl_reg.hdmi_in_mux = 1;
			top_ctl_reg.dolby_ratio = 0;
		}

		vgip_chn1_misc_reg.ch1_v1_v3_swap = 0;
		vgip_chn1_misc_reg.ch1_v2_v3_swap = 1;
		vgip_chn1_misc_reg.ch1_v1_v2_swap = 1;

		// dolby mode change by video fw
		if(bUpdateDolbyMode == TRUE){
			input_format_reg.runmode = 1;	//1: HDMI
			// Composer bypass
		}

		input_format_reg.dm_inbits_sel = 2; /*HDR10 is 12bit, 14 is for OTT*/

		/*dm_submodule_enable_reg.format_444to422_dis = 1;*/
		ycctorgb_scale_reg.ycctorgb_scale = 0x0d;
		signal_range_reg.regValue = 0xffff0000;//rangeMax/Min
		srangeinv_reg.regValue = 0x10000;//sRangeInv

		rgbtoopt_scale_reg.rgb2optscale = 0xe;

		eotf_para1_reg.seotf = 1;	/* HDR 10 = 2084*/

		/* set v top size in voDMA*/
		if(bUpdateDolbyMode == TRUE) // dolby mode change by video fw
			IoReg_Write32(DM_Input_Format_reg, input_format_reg.regValue);
		IoReg_Write32(DM_YCCtoRGB_Scale_reg, ycctorgb_scale_reg.regValue);
		IoReg_Write32(DM_Signal_range_reg, signal_range_reg.regValue);
		IoReg_Write32(DM_sRangeInv_reg, srangeinv_reg.regValue);
		IoReg_Write32(DM_RGBtoOPT_Scale_reg, rgbtoopt_scale_reg.regValue);

		if(bUpdateDolbyMode == TRUE)  // dolby mode change by video fw
			IoReg_Write32(DOLBY_V_TOP_TOP_CTL_reg, top_ctl_reg.regValue);
		IoReg_Write32(VGIP_VGIP_CHN1_MISC_reg, vgip_chn1_misc_reg.regValue);
		IoReg_Write32(DM_EOTF_para1_reg, eotf_para1_reg.regValue);

		composer_db_ctrl_reg.composer_db_apply = 1;
		rtd_outl(DHDR_V_COMPOSER_Composer_db_ctrl_reg, composer_db_ctrl_reg.regValue);

		//b05_position
		dm_hdr_path_sel_reg.regValue = rtd_inl(DM_HDR_PATH_SEL_reg);
		dm_hdr_path_sel_reg.b05_position = 1;
		rtd_outl(DM_HDR_PATH_SEL_reg, dm_hdr_path_sel_reg.regValue);

		//b0104_max_val_sel
		dm_rgbtoopt_scale_Reg.regValue = IoReg_Read32(DM_RGBtoOPT_Scale_reg);
		dm_rgbtoopt_scale_Reg.b0104_max_val_sel = 1;
		rtd_outl(DM_RGBtoOPT_Scale_reg, dm_rgbtoopt_scale_Reg.regValue);

		top_d_buf_reg.regValue = rtd_inl(DOLBY_V_TOP_TOP_D_BUF_reg);
		top_d_buf_reg.dolby_double_apply = 1;

		rtd_outl(DOLBY_V_TOP_TOP_D_BUF_reg, top_d_buf_reg.regValue);
		dm_double_buffer_ctrl_reg.regValue = rtd_inl(DM_HDR_Double_Buffer_CTRL_reg);
		dm_double_buffer_ctrl_reg.dm_db_apply = 1;
		rtd_outl(DM_HDR_Double_Buffer_CTRL_reg, dm_double_buffer_ctrl_reg.regValue);


		VIP_RPC_system_info_structure_table->HDR_info.Ctrl_Item[TV006_HDR_En] = 1;
		VIP_RPC_system_info_structure_table->HDR_info.Ctrl_Item[TV006_HDR_HDR10_apply_check] = 0;
		VIP_RPC_system_info_structure_table->HDR_info.Ctrl_Item[TV006_HDR_HDR10_display_check] = 0;

		//20160520 roger, enable HDMI Dither
		//drvif_HDMI_Dither_Enable(1);	//20170104 roger, move to quality_handler to fix KTASKWBS-6351

	}
	else
	{
		main_dither_i_main_dither_ctrl1_RBUS main_dither_i_main_dither_ctrl1_RBUS_reg;
		dm_hdr_double_buffer_ctrl_RBUS dm_double_buffer_ctrl_reg;

		vgip_chn1_misc_reg.ch1_v1_v3_swap = 0;
		vgip_chn1_misc_reg.ch1_v2_v3_swap = 0;
		vgip_chn1_misc_reg.ch1_v1_v2_swap = 0;

		if (get_OTT_HDR_mode()!=HDR_DOLBY_COMPOSER && get_HDMI_HDR_mode()!=HDR_DOLBY_HDMI) {	// don't disable dolby_mode when real DolbyVision enables
			dm_submodule_temp.regValue = 0;
			dm_submodule_temp.b0501_enable = 1;	//20161024 roger, no disable case in HDR10/HLG

			top_ctl_reg.dolby_mode = 0;

			dm_double_buffer_ctrl_reg.dm_db_en = 1;
			IoReg_Write32(DM_HDR_Double_Buffer_CTRL_reg, dm_double_buffer_ctrl_reg.regValue);
			IoReg_Write32(DOLBY_V_TOP_TOP_CTL_reg, top_ctl_reg.regValue);
		}
		IoReg_Write32(VGIP_VGIP_CHN1_MISC_reg, vgip_chn1_misc_reg.regValue);

		VIP_RPC_system_info_structure_table->HDR_info.Ctrl_Item[TV006_HDR_En] = 0;

		//ch1_temporal_enable, set disable
		main_dither_i_main_dither_ctrl1_RBUS_reg.regValue = IoReg_Read32(MAIN_DITHER_I_Main_DITHER_CTRL1_reg);
		main_dither_i_main_dither_ctrl1_RBUS_reg.ch1_dithering_table_select = 0;
		main_dither_i_main_dither_ctrl1_RBUS_reg.ch1_temporal_enable = 0;

		//b05_position
		dm_hdr_path_sel_reg.regValue = rtd_inl(DM_HDR_PATH_SEL_reg);
		dm_hdr_path_sel_reg.b05_position = 0;
		rtd_outl(DM_HDR_PATH_SEL_reg, dm_hdr_path_sel_reg.regValue);
		//apply
		dm_double_buffer_ctrl_reg.regValue = IoReg_Read32(DM_HDR_Double_Buffer_CTRL_reg);
		dm_double_buffer_ctrl_reg.dm_db_apply = 1;
		dm_double_buffer_ctrl_reg.dm_db_read_sel = 1;

		IoReg_Write32(DM_HDR_Double_Buffer_CTRL_reg, dm_double_buffer_ctrl_reg.regValue);

#ifndef CONFIG_HDR_SDR_SEAMLESS
		//reset EOTF/OETF table
		drvif_DM2_EOTF_Enable(1, 0);
		drvif_DM2_OETF_Enable(1, 0);
		drvif_reset_EOTF_OETF_table();
#else
		//reset EOTF/OETF table
		drvif_DM2_EOTF_Enable(1, 0);
		drvif_DM2_OETF_Enable(1, 0);
		drvif_reset_EOTF_OETF_table();


#endif
		//b0104_max_val_sel
		dm_rgbtoopt_scale_Reg.regValue = IoReg_Read32(DM_RGBtoOPT_Scale_reg);
		dm_rgbtoopt_scale_Reg.b0104_max_val_sel = 0;
		rtd_outl(DM_RGBtoOPT_Scale_reg, dm_rgbtoopt_scale_Reg.regValue);

		if (get_OTT_HDR_mode()!=HDR_DOLBY_COMPOSER && get_HDMI_HDR_mode()!=HDR_DOLBY_HDMI) {	// don't disable dolby_mode when real DolbyVision enables
			top_d_buf_reg.regValue = rtd_inl(DOLBY_V_TOP_TOP_D_BUF_reg);
			top_d_buf_reg.dolby_double_apply = 1;
			rtd_outl(DOLBY_V_TOP_TOP_D_BUF_reg, top_d_buf_reg.regValue);
			dm_double_buffer_ctrl_reg.regValue = rtd_inl(DM_HDR_Double_Buffer_CTRL_reg);
			dm_double_buffer_ctrl_reg.dm_db_apply = 1;
			rtd_outl(DM_HDR_Double_Buffer_CTRL_reg, dm_double_buffer_ctrl_reg.regValue);
		}

		//20160520 roger, disable HDMI Dither
		//drvif_HDMI_Dither_Enable(0);	//20170104 roger, move to quality_handler to fix KTASKWBS-6351
	}

	VIP_RPC_system_info_structure_table->HDR_info.HDR_Setting_Status = 0;
	return 1;

}

#else
void drvif_HDR10_init(DRV_HDR10_submodule_CTL *pmoduleArray, DRV_HDR10_top_init_CTL *ptopArray)
{
	#if 0 // No use from mer2,
	dm_dm_submodule_enable_RBUS dm_submodule_enable_reg;
	top_ctl_RBUS top_ctl_reg;
	top_pic_size_RBUS top_pic_size_reg;
	top_pic_total_RBUS top_pic_total_reg;
	top_pic_sta_RBUS top_pic_sta_reg;
	top_d_buf_RBUS top_d_buf_reg;
	vgip_chn1_misc_RBUS vgip_chn1_misc_reg;
	input_format_RBUS input_format_reg;
	format_444to422_RBUS format_444to422_reg;
	ycctorgb_scale_RBUS ycctorgb_scale_reg;
	signal_range_RBUS signal_range_reg;
	srangeinv_RBUS srangeinv_reg;
	rgbtoopt_scale_RBUS rgbtoopt_scale_reg;
	opttoopt_scale_RBUS opttoopt_scale_reg;
	opttoopt_coef0_RBUS opttoopt_coef0_reg;
	opttoopt_coef1_RBUS opttoopt_coef1_reg;
	opttoopt_coef2_RBUS opttoopt_coef2_reg;
	opttoopt_coef3_RBUS opttoopt_coef3_reg;
	opttoopt_coef4_RBUS opttoopt_coef4_reg;
	opttoopt_coef5_RBUS opttoopt_coef5_reg;
	opttoopt_offset_RBUS opttoopt_offset_reg;
	threedlut_minmaxc1_RBUS threedlut_minmaxc1_reg;
	threedlut_minmaxc2_RBUS threedlut_minmaxc2_reg;
	threedlut_minmaxc3_RBUS threedlut_minmaxc3_reg;
	threedlut_minmaxinv1_RBUS threedlut_minmaxinv1_reg;
	threedlut_minmaxinv2_RBUS threedlut_minmaxinv2_reg;
	threedlut_minmaxinv3_RBUS threedlut_minmaxinv3_reg;
	dm_double_buffer_ctrl_RBUS dm_double_buffer_ctrl_reg;
	composer_db_ctrl_RBUS composer_db_ctrl_reg;

	if(!((get_OTT_HDR_mode() == HDR_MODE_DISABLE) || (get_HDMI_HDR_mode() == HDR_HDR10_HDMI))){
		return ;
	}

	unsigned char bInDolbyMode = DOLBY_V_TOP_TOP_CTL_get_dolby_mode(IoReg_Read32(DOLBY_V_TOP_TOP_CTL_reg));

	dm_submodule_enable_reg.regValue = IoReg_Read32(DM_dm_submodule_enable_reg);
	top_ctl_reg.regValue = IoReg_Read32(DOLBY_V_TOP_TOP_CTL_reg);

	// check HDR mode data path -- VE compress mode need through DV normal mode
	top_pic_size_reg.regValue = IoReg_Read32(DOLBY_V_TOP_TOP_PIC_SIZE_reg);
	top_pic_sta_reg.regValue = IoReg_Read32(DOLBY_V_TOP_TOP_PIC_STA_reg);
	top_pic_total_reg.regValue = IoReg_Read32(DOLBY_V_TOP_TOP_PIC_TOTAL_reg);
	top_d_buf_reg.regValue = IoReg_Read32(DOLBY_V_TOP_TOP_D_BUF_reg);
	vgip_chn1_misc_reg.regValue = IoReg_Read32(VGIP_VGIP_CHN1_MISC_reg);
	input_format_reg.regValue = IoReg_Read32(DM_Input_Format_reg);
	format_444to422_reg.regValue = IoReg_Read32(DM_Format_444to422_reg);
	ycctorgb_scale_reg.regValue = IoReg_Read32(DM_YCCtoRGB_Scale_reg);
	signal_range_reg.regValue = IoReg_Read32(DM_Signal_range_reg);
	srangeinv_reg.regValue = IoReg_Read32(DM_sRangeInv_reg);
	rgbtoopt_scale_reg.regValue = IoReg_Read32(DM_RGBtoOPT_Scale_reg);
	opttoopt_scale_reg.regValue = IoReg_Read32(DM_OPTtoOPT_Scale_reg);
	opttoopt_coef0_reg.regValue = IoReg_Read32(DM_OPTtoOPT_coef0_reg);
	opttoopt_coef1_reg.regValue = IoReg_Read32(DM_OPTtoOPT_coef1_reg);
	opttoopt_coef2_reg.regValue = IoReg_Read32(DM_OPTtoOPT_coef2_reg);
	opttoopt_coef3_reg.regValue = IoReg_Read32(DM_OPTtoOPT_coef3_reg);
	opttoopt_coef4_reg.regValue = IoReg_Read32(DM_OPTtoOPT_coef4_reg);
	opttoopt_coef5_reg.regValue = IoReg_Read32(DM_OPTtoOPT_coef5_reg);
	opttoopt_offset_reg.regValue = IoReg_Read32(DM_OPTtoOPT_Offset_reg);
	threedlut_minmaxc1_reg.regValue = IoReg_Read32(DM_ThreeDLUT_MinMaxC1_reg);
	threedlut_minmaxc2_reg.regValue = IoReg_Read32(DM_ThreeDLUT_MinMaxC2_reg);
	threedlut_minmaxc3_reg.regValue = IoReg_Read32(DM_ThreeDLUT_MinMaxC3_reg);
	threedlut_minmaxinv1_reg.regValue = IoReg_Read32(DM_ThreeDLUT_MinMaxInv1_reg);
	threedlut_minmaxinv2_reg.regValue = IoReg_Read32(DM_ThreeDLUT_MinMaxInv2_reg);
	threedlut_minmaxinv3_reg.regValue = IoReg_Read32(DM_ThreeDLUT_MinMaxInv3_reg);
	dm_double_buffer_ctrl_reg.regValue = IoReg_Read32(DM_HDR_Double_Buffer_CTRL_reg);

	top_d_buf_reg.dolby_double_en = 1;
	IoReg_Write32(DOLBY_V_TOP_TOP_D_BUF_reg, top_d_buf_reg.regValue);

	// Composer bypass -- init
	composer_db_ctrl_reg.regValue = rtd_inl(DHDR_V_COMPOSER_Composer_db_ctrl_reg);
	composer_db_ctrl_reg.composer_db_en = 1;
	rtd_outl(DHDR_V_COMPOSER_Composer_db_ctrl_reg, composer_db_ctrl_reg.regValue);

	// Composer bypass
	drvif_HDR_Composer_bypass();

	dm_submodule_enable_reg.regValue = 0x0;

	if ((pmoduleArray->HDR10_EN)==1)
	{

#if 0
		dm_submodule_enable_reg.regValue = 0x0000007e;
		dm_submodule_enable_reg.b01_01_420to422_enable = 0;
		dm_submodule_enable_reg.b01_01_422to444_enable = 1;
		dm_submodule_enable_reg.dither_en = 0;

		top_pic_size_reg.dolby_hsize = 0xf00;
		top_pic_size_reg.dolby_vsize = 0x870;
		top_pic_total_reg.dolby_h_total = 0x1131;
		top_pic_sta_reg.dolby_h_den_sta = 0x008f;
		top_pic_sta_reg.dolby_v_den_sta = 0x0010;
		top_ctl_reg.dolby_mode = 1;
		top_ctl_reg.hdmi_in_mux = 1;
#else

		//submodule init
		dm_submodule_enable_reg.b01_01_420to422_enable = pmoduleArray->HDR10_420_2_422;
		dm_submodule_enable_reg.b01_01_422to444_enable = pmoduleArray->HDR10_422_2_444;
		dm_submodule_enable_reg.b01_02_enable = pmoduleArray->HDR10_YUV2RGB;
		dm_submodule_enable_reg.b01_03_enable = pmoduleArray->HDR10_EOTF;
		dm_submodule_enable_reg.b01_04_enable = pmoduleArray->HDR10_CMT;
		dm_submodule_enable_reg.b01_05_enable = pmoduleArray->HDR10_OETF;
		dm_submodule_enable_reg.b01_06_enable = pmoduleArray->HDR10_RGB2OPT;
		dm_submodule_enable_reg.dither_en = pmoduleArray->HDR10_DITHER;


		//Top CTL
		//top_pic_size_reg.dolby_hsize = ptopArray->dolby_hsize;
		//top_pic_size_reg.dolby_vsize = ptopArray->dolby_vsize;
		//top_pic_sta_reg.dolby_h_den_sta = ptopArray->dolby_h_den_sta;
		//top_pic_sta_reg.dolby_v_den_sta = ptopArray->dolby_v_den_sta;

		top_pic_total_reg.dolby_h_total = ptopArray->dolby_h_total;

		// dolby mode change by video fw
		if(bInDolbyMode == FALSE){
			top_ctl_reg.dolby_mode = ptopArray->dolby_mode;		// 1: HDMI, 2: nprmal but
			top_ctl_reg.hdmi_in_mux = ptopArray->hdmi_in_mux;
			top_ctl_reg.dolby_ratio = 0;
		}
#endif
		// dolby mode change by video fw
		if(bInDolbyMode == FALSE){
			//color format
			input_format_reg.runmode = 1;	// 1: HDMI mode
		 }

		//YUV2RGB
		ycctorgb_scale_reg.ycctorgb_scale = 0x0d;
		signal_range_reg.regValue = 0xffff0000;//rangeMax/Min
		srangeinv_reg.regValue = 0x10000;//sRangeInv

		//CSM
		rgbtoopt_scale_reg.rgb2optscale = 0xe;

		//RGB2OPT(for data range)
		opttoopt_coef0_reg.regValue = 0x00001000;
		opttoopt_coef1_reg.regValue = 0x00000000;
		opttoopt_coef2_reg.regValue = 0x08000000;
		opttoopt_coef3_reg.regValue = 0x00000000;
		opttoopt_coef4_reg.regValue = 0x00000000;
		opttoopt_coef5_reg.regValue = 0x00000800;
		opttoopt_offset_reg.regValue = 0x00000000;
		opttoopt_scale_reg.opt2optscale = 0xC;

		//LUT(for data range )
		threedlut_minmaxc1_reg.regValue = 0x7fff0000;//0xffff0000;//MaxC1/MinC1
		threedlut_minmaxc2_reg.regValue = 0x7fff0000;//0xffff0000;//MaxC2/MinC2
		threedlut_minmaxc3_reg.regValue = 0x00000000;//0x00000000;//MinC3
		threedlut_minmaxinv1_reg.regValue = 0x00010000;//0x00004000;//iDisxC1Inv
		threedlut_minmaxinv2_reg.regValue = 0x00010000;//0x00004000;//iDisxC2Inv
		threedlut_minmaxinv3_reg.regValue = 0x00010000;//0x00004000;//iDisxC3Inv
		format_444to422_reg.format_444to422_dis = 1;

		//data swap
		vgip_chn1_misc_reg.ch1_v1_v3_swap = 0;
		vgip_chn1_misc_reg.ch1_v2_v3_swap = 1;
		vgip_chn1_misc_reg.ch1_v1_v2_swap = 1;

		dm_double_buffer_ctrl_reg.dm_db_en = 0;	//disable double buffer

		//IoReg_Write32(DOLBY_V_TOP_TOP_PIC_SIZE_reg, top_pic_size_reg.regValue);
		//IoReg_Write32(DOLBY_V_TOP_TOP_PIC_STA_reg, top_pic_sta_reg.regValue);

		IoReg_Write32(DOLBY_V_TOP_TOP_PIC_TOTAL_reg, top_pic_total_reg.regValue);
		if(bInDolbyMode == FALSE) // dolby mode change by video fw
			IoReg_Write32(DM_Input_Format_reg, input_format_reg.regValue);
		IoReg_Write32(DM_Format_444to422_reg, format_444to422_reg.regValue);
		IoReg_Write32(DM_YCCtoRGB_Scale_reg, ycctorgb_scale_reg.regValue);
		IoReg_Write32(DM_Signal_range_reg, signal_range_reg.regValue);
		IoReg_Write32(DM_sRangeInv_reg, srangeinv_reg.regValue);
		IoReg_Write32(DM_RGBtoOPT_Scale_reg, rgbtoopt_scale_reg.regValue);
		IoReg_Write32(DM_OPTtoOPT_Scale_reg, opttoopt_scale_reg.regValue);
		IoReg_Write32(DM_OPTtoOPT_coef0_reg, opttoopt_coef0_reg.regValue);
		IoReg_Write32(DM_OPTtoOPT_coef1_reg, opttoopt_coef1_reg.regValue);
		IoReg_Write32(DM_OPTtoOPT_coef2_reg, opttoopt_coef2_reg.regValue);
		IoReg_Write32(DM_OPTtoOPT_coef3_reg, opttoopt_coef3_reg.regValue);
		IoReg_Write32(DM_OPTtoOPT_coef4_reg, opttoopt_coef4_reg.regValue);
		IoReg_Write32(DM_OPTtoOPT_coef5_reg, opttoopt_coef5_reg.regValue);
		IoReg_Write32(DM_OPTtoOPT_Offset_reg, opttoopt_offset_reg.regValue);
		IoReg_Write32(DM_ThreeDLUT_MinMaxC1_reg, threedlut_minmaxc1_reg.regValue);
		IoReg_Write32(DM_ThreeDLUT_MinMaxC2_reg, threedlut_minmaxc2_reg.regValue);
		IoReg_Write32(DM_ThreeDLUT_MinMaxC3_reg, threedlut_minmaxc3_reg.regValue);
		IoReg_Write32(DM_ThreeDLUT_MinMaxInv1_reg, threedlut_minmaxinv1_reg.regValue);
		IoReg_Write32(DM_ThreeDLUT_MinMaxInv2_reg, threedlut_minmaxinv2_reg.regValue);
		IoReg_Write32(DM_ThreeDLUT_MinMaxInv3_reg, threedlut_minmaxinv3_reg.regValue);
		IoReg_Write32(DM_HDR_Double_Buffer_CTRL_reg, dm_double_buffer_ctrl_reg.regValue);
		IoReg_Write32(DM_dm_submodule_enable_reg, dm_submodule_enable_reg.regValue);
		if(bInDolbyMode == FALSE) // dolby mode change by video fw
			IoReg_Write32(DOLBY_V_TOP_TOP_CTL_reg, top_ctl_reg.regValue);
		IoReg_Write32(VGIP_VGIP_CHN1_MISC_reg, vgip_chn1_misc_reg.regValue);

		VIPprintf("vgip_chn1_misc_reg = %x", vgip_chn1_misc_reg.regValue);

		drvif_color_set422to444(0, 0);
	}
	else
	{
		dm_submodule_enable_reg.dither_en = 0;
		top_ctl_reg.dolby_mode = 0;

		vgip_chn1_misc_reg.ch1_v1_v3_swap = 0;
		vgip_chn1_misc_reg.ch1_v2_v3_swap = 0;
		vgip_chn1_misc_reg.ch1_v1_v2_swap = 0;

		dm_double_buffer_ctrl_reg.dm_db_en = 1;
		IoReg_Write32(DM_HDR_Double_Buffer_CTRL_reg, dm_double_buffer_ctrl_reg.regValue);
		IoReg_Write32(DM_dm_submodule_enable_reg, dm_submodule_enable_reg.regValue);
		IoReg_Write32(DOLBY_V_TOP_TOP_CTL_reg, top_ctl_reg.regValue);
		IoReg_Write32(VGIP_VGIP_CHN1_MISC_reg, vgip_chn1_misc_reg.regValue);

	}

	composer_db_ctrl_reg.composer_db_apply = 1;
	rtd_outl(DHDR_V_COMPOSER_Composer_db_ctrl_reg, composer_db_ctrl_reg.regValue);

	top_d_buf_reg.dolby_double_apply = 1;
	IoReg_Write32(DOLBY_V_TOP_TOP_D_BUF_reg, top_d_buf_reg.regValue);

	#endif
}

//B01-03 and B01-05
void drvif_HDR_EOTF_OETF(unsigned char Mode)
{
	dm_dm_submodule_enable_RBUS dm_submodule_enable_reg;
	// eotf_para0_RBUS eotf_para0_reg;  //Mac5p dolby remove
	dm_eotf_para1_RBUS eotf_para1_reg;

	dm_submodule_enable_reg.regValue = IoReg_Read32(DM_dm_submodule_enable_reg);
	//eotf_para0_reg.regValue = IoReg_Read32(DM_EOTF_para0_reg); //Mac5p dolby remove
	eotf_para1_reg.regValue = IoReg_Read32(DM_EOTF_para1_reg);

	if(Mode == ITU_SMPTE2084) {
		//EOTF
		eotf_para1_reg.seotf = 1;
		//OETF
		dm_submodule_enable_reg.b01_05_enable=1;

	} else if ((Mode == ITU_BT1886)) {
		//EOTF
		dm_submodule_enable_reg.b01_03_enable=1;
		eotf_para1_reg.seotf = 0;
		//eotf_para0_reg.signal_eotf_param0=0xffff;//B01-03 gain for gamma //Mac5p dolby remove
		//eotf_para0_reg.signal_eotf_param1=0x0;//B01-03 offset for gamma //Mac5p dolby remove
		//OETF
		dm_submodule_enable_reg.b01_05_enable=1;
	}
	else
	{
		dm_submodule_enable_reg.b01_03_enable=0;
		dm_submodule_enable_reg.b01_05_enable=0;
	}


	IoReg_Write32(DM_dm_submodule_enable_reg, dm_submodule_enable_reg.regValue);
	//IoReg_Write32(DM_EOTF_para0_reg, eotf_para0_reg.regValue); //Mac5p dolby remove
	IoReg_Write32(DM_EOTF_para1_reg, eotf_para1_reg.regValue);

}
#endif

#ifdef CONFIG_HDR_SDR_SEAMLESS
unsigned char drvif_color_set_HDR10_Enable_Seamless(unsigned char* enable)
{
	//dm_submodule_enable_RBUS dm_submodule_enable_reg;
	dolby_v_top_top_ctl_RBUS top_ctl_reg;
	dolby_v_top_top_pic_size_RBUS top_pic_size_reg;
	dolby_v_top_top_pic_total_RBUS top_pic_total_reg;
	dolby_v_top_top_pic_sta_RBUS top_pic_sta_reg;
	dolby_v_top_top_d_buf_RBUS top_d_buf_reg;
	vgip_vgip_chn1_misc_RBUS vgip_chn1_misc_reg;
	dm_input_format_RBUS input_format_reg;
	//dm_eotf_para0_RBUS eotf_para0_reg; //Mac5p dolby remove
	dm_dm_submodule_enable_RBUS dm_submodule_enable_reg;
	dm_ycctorgb_scale_RBUS ycctorgb_scale_reg;
	dm_signal_range_RBUS signal_range_reg;
	dm_srangeinv_RBUS srangeinv_reg;
	dm_rgbtoopt_scale_RBUS rgbtoopt_scale_reg;
	dm_saturationadj_RBUS dm_saturationadj_reg;
	dm_hdr_double_buffer_ctrl_RBUS dm_double_buffer_ctrl_reg;
	dhdr_v_composer_composer_db_ctrl_RBUS composer_db_ctrl_reg;
	dm_eotf_para1_RBUS eotf_para1_reg;
	dm_hdr_path_sel_RBUS dm_hdr_path_sel_reg;
	dm_rgbtoopt_scale_RBUS dm_rgbtoopt_scale_Reg;
	UINT16 HDR_h, HDR_v;
	UINT32 timeoutcnt = 0x032500;
#if 0
	if(!((get_OTT_HDR_mode() == HDR_MODE_DISABLE) || (get_HDMI_HDR_mode() == HDR_HDR10_HDMI))){
		rtd_printk(KERN_INFO, TAG_NAME, "drvif_color_set_HDR10_Enable retunr 111\n");
		return 1;
	}

	// enable DM & Composer clock
	rtd_outl(SYS_REG_SYS_CLKEN1_reg, SYS_REG_SYS_CLKEN1_clken_dolby_dm_mask | SYS_REG_SYS_CLKEN1_clken_dolby_comp_mask | SYS_REG_SYS_CLKEN1_write_data_mask);
#endif
	unsigned char bInDolbyMode = DOLBY_V_TOP_TOP_CTL_get_dolby_mode(IoReg_Read32(DOLBY_V_TOP_TOP_CTL_reg));
	extern unsigned char Get_vo_smoothtoggle_timingchange_flag(unsigned char display);
	unsigned char bUpdateDolbyMode = (Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE) != _MODE_STATE_ACTIVE)
		|| (bInDolbyMode == 0)|| (Get_vo_smoothtoggle_timingchange_flag(SLR_MAIN_DISPLAY) == 0);
#if 0
	if((bUpdateDolbyMode == FALSE) && (enable[HDR_EN]) == 1)
	{
		rtd_printk(KERN_INFO, TAG_NAME, "drvif_color_set_HDR10_Enable retunr 222\n");
		pr_notice("[HDR] Ignore HDR udpate %d/%d\n", Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE) , bInDolbyMode);
		return 1;
	}
#endif
	// check HDR mode data path -- VE compress mode need through DV normal mode
	unsigned char bVeCompressMode;
	bVeCompressMode = drvif_HDR_get_VO_Decompress_Status();

	// Composer bypass -- init
	composer_db_ctrl_reg.regValue = rtd_inl(DHDR_V_COMPOSER_Composer_db_ctrl_reg);
	composer_db_ctrl_reg.composer_db_en = 1;
	rtd_outl(DHDR_V_COMPOSER_Composer_db_ctrl_reg, composer_db_ctrl_reg.regValue);

	// Composer bypass
	drvif_HDR_Composer_bypass();
#if 0
	// in compress mode update video size in VODMA
	top_pic_size_reg.regValue = IoReg_Read32(DOLBY_V_TOP_TOP_PIC_SIZE_reg);
	top_pic_sta_reg.regValue = IoReg_Read32(DOLBY_V_TOP_TOP_PIC_STA_reg);
#endif
	//_system_setting_info *VIP_system_info_structure_table = (_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_system_info_structure);
	_RPC_system_setting_info *VIP_RPC_system_info_structure_table = NULL;
	VIP_RPC_system_info_structure_table = (_RPC_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_RPC_system_info_structure);

	if(VIP_RPC_system_info_structure_table == NULL){
		VIPprintf("[%s:%d] Warning here!! RPC_system_info=NULL! \n",__FILE__, __LINE__);
		return;
	}

	//dm_submodule_enable_reg.regValue = IoReg_Read32(DM_dm_submodule_enable_reg);
	top_ctl_reg.regValue = IoReg_Read32(DOLBY_V_TOP_TOP_CTL_reg);
	top_pic_total_reg.regValue = IoReg_Read32(DOLBY_V_TOP_TOP_PIC_TOTAL_reg);
	top_d_buf_reg.regValue = IoReg_Read32(DOLBY_V_TOP_TOP_D_BUF_reg);
	vgip_chn1_misc_reg.regValue = IoReg_Read32(VGIP_VGIP_CHN1_MISC_reg);
	input_format_reg.regValue = IoReg_Read32(DM_Input_Format_reg);
	//eotf_para0_reg.regValue = IoReg_Read32(DM_EOTF_para0_reg); //Mac5p dolby remove
	dm_submodule_enable_reg.regValue = IoReg_Read32(DM_dm_submodule_enable_reg);
	ycctorgb_scale_reg.regValue = IoReg_Read32(DM_YCCtoRGB_Scale_reg);
	signal_range_reg.regValue = IoReg_Read32(DM_Signal_range_reg);
	srangeinv_reg.regValue = IoReg_Read32(DM_sRangeInv_reg);
	rgbtoopt_scale_reg.regValue = IoReg_Read32(DM_RGBtoOPT_Scale_reg);

	dm_double_buffer_ctrl_reg.regValue = IoReg_Read32(DM_HDR_Double_Buffer_CTRL_reg);
	eotf_para1_reg.regValue = IoReg_Read32(DM_EOTF_para1_reg);
#if 0
	timeoutcnt = 0x032500;
	VIPprintf1("HDR_Setting_Flow_drvif_color_set_HDR10_Enable = %d\n",VIP_system_info_structure_table->HDR_info.HDR_Setting_Status);
#endif
	VIP_RPC_system_info_structure_table->HDR_info.HDR_Setting_Status = 2;

	dm_double_buffer_ctrl_reg.regValue = IoReg_Read32(DM_HDR_Double_Buffer_CTRL_reg);
	dm_double_buffer_ctrl_reg.dm_db_en = 1;
	IoReg_Write32(DM_HDR_Double_Buffer_CTRL_reg, dm_double_buffer_ctrl_reg.regValue);

	top_d_buf_reg.dolby_double_en = 1;
	IoReg_Write32(DOLBY_V_TOP_TOP_D_BUF_reg, top_d_buf_reg.regValue);
#if 0
	vodma_vodma_v1_dsize_RBUS vodma_v1_dsize_RBUS_reg;
	vodma_v1_dsize_RBUS_reg.regValue = IoReg_Read32(VODMA_VODMA_V1_DSIZE_reg);

	HDR_h = vodma_v1_dsize_RBUS_reg.p_y_len;
	HDR_v = vodma_v1_dsize_RBUS_reg.p_y_nline;
#endif


	if (enable[HDR_EN])
	{
		dm_submodule_temp.b01_02_enable = 1;
		dm_submodule_temp.b01_03_enable = 0;	//20160921 roger, K3L have EOTF/OETF table setting by LG, don't enable this, we don't have this function in LG
		dm_submodule_temp.b01_05_enable = 0;	//20160921 roger, K3L have EOTF/OETF table setting by LG, don't enable this, we don't have this function in LG
		dm_submodule_temp.b01_07_enable = 0;
		dm_submodule_temp.b03_enable = 0;
		dm_submodule_temp.b04_enable = 0;
		dm_submodule_temp.b01_06_enable = 0;
		dm_submodule_temp.b01_01_420to422_enable = enable[HDR_420_2_422];
		dm_submodule_temp.b01_01_422to444_enable = enable[HDR_422_2_444];
		dm_submodule_temp.dither_en = enable[HDR_DITHER];

		dm_submodule_temp.format_444to422_dis = 1;


		dm_saturationadj_reg.regValue = IoReg_Read32(DM_SaturationAdj_reg);
		dm_saturationadj_reg.bypass_unsigned_en = 1;
		IoReg_Write32(DM_SaturationAdj_reg, dm_saturationadj_reg.regValue);

		top_pic_total_reg.dolby_h_total = (IoReg_Read32(VODMA_VODMA_V1SGEN_reg) & 0x00001FFF) + 1;	//0x1131;

		if(bUpdateDolbyMode == TRUE){ // dolby mode change by video fw
			top_ctl_reg.dolby_mode = (bVeCompressMode? 3: 1); // 1: HDMI mode, 3: HDMI with VO decompress mode
			top_ctl_reg.hdmi_in_mux = 1;
			top_ctl_reg.dolby_ratio = 0;
		}

		vgip_chn1_misc_reg.ch1_v1_v3_swap = 0;
		vgip_chn1_misc_reg.ch1_v2_v3_swap = 1;
		vgip_chn1_misc_reg.ch1_v1_v2_swap = 1;

		// dolby mode change by video fw
		if(bUpdateDolbyMode == TRUE){
			input_format_reg.runmode = 1;	//1: HDMI
			// Composer bypass
		}

		input_format_reg.dm_inbits_sel = 1; /*HDR10 is 12bit, 14 is for OTT*/

		// eotf_para0_reg.regValue = 0x0000ffff;//B01-03 gain,offset for gamma //Mac5p dolby remove
		/*dm_submodule_enable_reg.format_444to422_dis = 1;*/
		ycctorgb_scale_reg.ycctorgb_scale = 0x0d;
		signal_range_reg.regValue = 0xffff0000;//rangeMax/Min
		srangeinv_reg.regValue = 0x10000;//sRangeInv

		rgbtoopt_scale_reg.rgb2optscale = 0xe;

		eotf_para1_reg.seotf = 1;	/* HDR 10 = 2084*/

		/* set v top size in voDMA*/
		if(bUpdateDolbyMode == TRUE) // dolby mode change by video fw
			IoReg_Write32(DM_Input_Format_reg, input_format_reg.regValue);
		//IoReg_Write32(DM_EOTF_para0_reg, eotf_para0_reg.regValue); //Mac5p dolby remove
		IoReg_Write32(DM_YCCtoRGB_Scale_reg, ycctorgb_scale_reg.regValue);
		IoReg_Write32(DM_Signal_range_reg, signal_range_reg.regValue);
		IoReg_Write32(DM_sRangeInv_reg, srangeinv_reg.regValue);
		IoReg_Write32(DM_RGBtoOPT_Scale_reg, rgbtoopt_scale_reg.regValue);

		if(bUpdateDolbyMode == TRUE)  // dolby mode change by video fw
			IoReg_Write32(DOLBY_V_TOP_TOP_CTL_reg, top_ctl_reg.regValue);
		IoReg_Write32(VGIP_VGIP_CHN1_MISC_reg, vgip_chn1_misc_reg.regValue);
		IoReg_Write32(DM_EOTF_para1_reg, eotf_para1_reg.regValue);

		composer_db_ctrl_reg.composer_db_apply = 1;
		rtd_outl(DHDR_V_COMPOSER_Composer_db_ctrl_reg, composer_db_ctrl_reg.regValue);

		//b05_position
		dm_hdr_path_sel_reg.regValue = rtd_inl(DM_HDR_PATH_SEL_reg);
		dm_hdr_path_sel_reg.b05_position = 1;
		rtd_outl(DM_HDR_PATH_SEL_reg, dm_hdr_path_sel_reg.regValue);

		//b0104_max_val_sel
		dm_rgbtoopt_scale_Reg.regValue = IoReg_Read32(DM_RGBtoOPT_Scale_reg);
		dm_rgbtoopt_scale_Reg.b0104_max_val_sel = 1;
		rtd_outl(DM_RGBtoOPT_Scale_reg, dm_rgbtoopt_scale_Reg.regValue);

		top_d_buf_reg.regValue = rtd_inl(DOLBY_V_TOP_TOP_D_BUF_reg);
		top_d_buf_reg.dolby_double_apply = 1;

		rtd_outl(DOLBY_V_TOP_TOP_D_BUF_reg, top_d_buf_reg.regValue);
		dm_double_buffer_ctrl_reg.regValue = rtd_inl(DM_HDR_Double_Buffer_CTRL_reg);
		dm_double_buffer_ctrl_reg.dm_db_apply = 1;
		rtd_outl(DM_HDR_Double_Buffer_CTRL_reg, dm_double_buffer_ctrl_reg.regValue);


		VIP_RPC_system_info_structure_table->HDR_info.Ctrl_Item[TV006_HDR_En] = 1;
		VIP_RPC_system_info_structure_table->HDR_info.Ctrl_Item[TV006_HDR_HDR10_apply_check] = 0;
		VIP_RPC_system_info_structure_table->HDR_info.Ctrl_Item[TV006_HDR_HDR10_display_check] = 0;

		//20160520 roger, enable HDMI Dither
		//drvif_HDMI_Dither_Enable(1);	//20170104 roger, move to quality_handler to fix KTASKWBS-6351

	}
	else
	{
		main_dither_i_main_dither_ctrl1_RBUS main_dither_i_main_dither_ctrl1_RBUS_reg;
		dm_hdr_double_buffer_ctrl_RBUS dm_double_buffer_ctrl_reg;

		vgip_chn1_misc_reg.ch1_v1_v3_swap = 0;
		vgip_chn1_misc_reg.ch1_v2_v3_swap = 0;
		vgip_chn1_misc_reg.ch1_v1_v2_swap = 0;

		if (get_OTT_HDR_mode()!=HDR_DOLBY_COMPOSER && get_HDMI_HDR_mode()!=HDR_DOLBY_HDMI) {	// don't disable dolby_mode when real DolbyVision enables
			dm_submodule_temp.regValue = 0;
			dm_submodule_temp.b05_enable = 1;	//20161024 roger, no disable case in HDR10/HLG
			top_ctl_reg.dolby_mode = 0;

			dm_double_buffer_ctrl_reg.dm_db_en = 1;
			IoReg_Write32(DM_HDR_Double_Buffer_CTRL_reg, dm_double_buffer_ctrl_reg.regValue);
			IoReg_Write32(DOLBY_V_TOP_TOP_CTL_reg, top_ctl_reg.regValue);
		}
		IoReg_Write32(VGIP_VGIP_CHN1_MISC_reg, vgip_chn1_misc_reg.regValue);

		VIP_RPC_system_info_structure_table->HDR_info.Ctrl_Item[TV006_HDR_En] = 0;

		//ch1_temporal_enable, set disable
		main_dither_i_main_dither_ctrl1_RBUS_reg.regValue = IoReg_Read32(MAIN_DITHER_I_Main_DITHER_CTRL1_reg);
		main_dither_i_main_dither_ctrl1_RBUS_reg.ch1_dithering_table_select = 0;
		main_dither_i_main_dither_ctrl1_RBUS_reg.ch1_temporal_enable = 0;

		//b05_position
		dm_hdr_path_sel_reg.regValue = rtd_inl(DM_HDR_PATH_SEL_reg);
		dm_hdr_path_sel_reg.b05_position = 0;
		rtd_outl(DM_HDR_PATH_SEL_reg, dm_hdr_path_sel_reg.regValue);
		//apply
		dm_double_buffer_ctrl_reg.regValue = IoReg_Read32(DM_HDR_Double_Buffer_CTRL_reg);
		dm_double_buffer_ctrl_reg.dm_db_apply = 1;
		IoReg_Write32(DM_HDR_Double_Buffer_CTRL_reg, dm_double_buffer_ctrl_reg.regValue);

		//reset EOTF/OETF table
		/* do not reset in seanless.*/
		//drvif_DM2_EOTF_Enable(0, 0);
		//drvif_DM2_OETF_Enable(0, 0);
		//drvif_reset_EOTF_OETF_table();

		//b0104_max_val_sel
		dm_rgbtoopt_scale_Reg.regValue = IoReg_Read32(DM_RGBtoOPT_Scale_reg);
		dm_rgbtoopt_scale_Reg.b0104_max_val_sel = 0;
		rtd_outl(DM_RGBtoOPT_Scale_reg, dm_rgbtoopt_scale_Reg.regValue);

		if (get_OTT_HDR_mode()!=HDR_DOLBY_COMPOSER && get_HDMI_HDR_mode()!=HDR_DOLBY_HDMI) {	// don't disable dolby_mode when real DolbyVision enables
			top_d_buf_reg.regValue = rtd_inl(DOLBY_V_TOP_TOP_D_BUF_reg);
			top_d_buf_reg.dolby_double_apply = 1;
			rtd_outl(DOLBY_V_TOP_TOP_D_BUF_reg, top_d_buf_reg.regValue);
			dm_double_buffer_ctrl_reg.regValue = rtd_inl(DM_HDR_Double_Buffer_CTRL_reg);
			dm_double_buffer_ctrl_reg.dm_db_apply = 1;
			rtd_outl(DM_HDR_Double_Buffer_CTRL_reg, dm_double_buffer_ctrl_reg.regValue);
		}

		//20160520 roger, disable HDMI Dither
		//drvif_HDMI_Dither_Enable(0);	//20170104 roger, move to quality_handler to fix KTASKWBS-6351
	}

	VIP_RPC_system_info_structure_table->HDR_info.HDR_Setting_Status = 0;
	return 1;

}
#endif


char drvif_color_set_PQ_ByPass(unsigned char bypass_item)
{
	vgip_data_path_select_RBUS vgip_data_path_select_reg;

	int timeOut = 0x032500;
	unsigned char db_ready, db_en;
	switch(bypass_item) {
		/*===============I Domain===========*/
		case PQ_ByPass_Iedge_Smooth:
			IoReg_ClearBits(IEDGE_SMOOTH_EdgeSmooth_EX_CTRL_reg, IEDGE_SMOOTH_EdgeSmooth_EX_CTRL_edgesmoothex_en_mask);//_BIT0
		break;

		case PQ_ByPass_MPEG_NR:
			IoReg_ClearBits(MPEGNR_ICH1_MPEGNR2_reg, MPEGNR_ICH1_MPEGNR2_cp_mpegenable_x_mask);//_BIT0
			IoReg_SetBits(NR_SNR_DB_CTRL_reg, NR_SNR_DB_CTRL_snr_db_apply_mask); /* SNR DB apply */
		break;

		case PQ_ByPass_HSD_DITHER:
			IoReg_ClearBits(HSD_DITHER_SD_Dither_CTRL1_reg, HSD_DITHER_SD_Dither_CTRL1_ch1_dithering_table_select_mask); //_BIT5 | _BIT6
		break;

		case PQ_ByPass_HSD_DITHER_Temporal:
			IoReg_ClearBits(HSD_DITHER_SD_Dither_CTRL1_reg, HSD_DITHER_SD_Dither_CTRL1_ch1_temporal_enable_mask);//_BIT4
		break;

		case PQ_ByPass_RTNR_Y:
			IoReg_ClearBits(DI_IM_DI_RTNR_CONTROL_reg, DI_IM_DI_RTNR_CONTROL_cp_rtnr_y_enable_mask);//_BIT0
			IoReg_SetBits(DI_db_reg_ctl_reg, DI_db_reg_ctl_db_apply_mask);	/* HW do not clear this bit, alway turn on, setting will be apply while v_sync*/
		break;

		case PQ_ByPass_RTNR_C:
			IoReg_ClearBits(DI_IM_DI_RTNR_CONTROL_reg, DI_IM_DI_RTNR_CONTROL_cp_rtnr_c_enable_mask);//_BIT1
			IoReg_SetBits(DI_db_reg_ctl_reg, DI_db_reg_ctl_db_apply_mask);	/* HW do not clear this bit, alway turn on, setting will be apply while v_sync*/
		break;

		case PQ_ByPass_MCNR:
			IoReg_ClearBits(DI_IM_DI_RTNR_HMCNR_reg, DI_IM_DI_RTNR_HMCNR_cp_temporal_hmcnr_y_en_mask);//_BIT7
		break;

		case PQ_ByPass_I_DCTI:
			IoReg_ClearBits(IDCTI_I_DCTI_CTRL_1_reg, IDCTI_I_DCTI_CTRL_1_dcti_en_mask);//_BIT0
		break;

		case PQ_ByPass_ImpulseNR:
			IoReg_ClearBits(NR_DCH1_CP_Ctrl_reg, NR_DCH1_CP_Ctrl_cp_impulseenable_mask);//_BIT0
			IoReg_SetBits(NR_SNR_DB_CTRL_reg, NR_SNR_DB_CTRL_snr_db_apply_mask); /* DB apply */
		break;

		case PQ_ByPass_SNR_C:
			IoReg_ClearBits(NR_DCH1_CP_Ctrl_reg, NR_DCH1_CP_Ctrl_cp_spatialenablec_mask);//_BIT1
			IoReg_SetBits(NR_SNR_DB_CTRL_reg, NR_SNR_DB_CTRL_snr_db_apply_mask); /* DB apply */
		break;

		case PQ_ByPass_SNR_Y:
			IoReg_ClearBits(NR_DCH1_CP_Ctrl_reg, NR_DCH1_CP_Ctrl_cp_spatialenabley_mask);//_BIT2
			IoReg_SetBits(NR_SNR_DB_CTRL_reg, NR_SNR_DB_CTRL_snr_db_apply_mask); /* DB apply */
		break;

		case PQ_ByPass_MosquiutoNR:
			IoReg_ClearBits(NR_MOSQUITO_CTRL_reg, NR_MOSQUITO_CTRL_mosquito_detect_en_mask);//_BIT0
		break;

		case PQ_ByPass_I_Peaking:
//			IoReg_ClearBits(PEAKING_ICH1_PEAKING_FILTER_reg, PEAKING_ICH1_PEAKING_FILTER_peaking_enable_mask);//_BIT26// mac5 no I_Peaking
		break;

		case PQ_ByPass_MB_Peaking:
			IoReg_ClearBits(COLOR_MB_PEAKING_MB_PEAKING_CTRL_reg, COLOR_MB_PEAKING_MB_PEAKING_CTRL_mb_peaking_en_mask);//_BIT0
		break;

		/*Sub*/
#ifdef VIP_CONFIG_DUAL_CHANNEL // henry 161214
		case PQ_ByPass_HSD_DITHER_Sub:
			IoReg_ClearBits(SUB_DITHER_I_Sub_Dither_CTRL1_reg, SUB_DITHER_I_Sub_Dither_CTRL1_ch2_dithering_table_select_mask);//_BIT5|_BIT6
		break;

		case PQ_ByPass_HSD_DITHER_Temporal_Sub:
			IoReg_ClearBits(SUB_DITHER_I_Sub_Dither_CTRL1_reg, SUB_DITHER_I_Sub_Dither_CTRL1_ch2_temporal_enable_mask);//_BIT4
		break;

		case PQ_ByPass_I_Peaking_Sub:
			IoReg_ClearBits(PEAKING_ICH2_PEAKING_FILTER_reg, PEAKING_ICH2_PEAKING_FILTER_peaking_enable_mask);//_BIT26
		break;
#endif
		/*===============D Domain===========*/
		/*Main*/
		case PQ_ByPass_USM:
			IoReg_ClearBits(SCALEUP_DM_USM_reg, SCALEUP_DM_USM_usm_en_mask);//_BIT0
		break;

		case PQ_ByPass_SU_Peaking:
			IoReg_ClearBits(SCALEUP_DM_UZU_Peaking_Coring_reg, SCALEUP_DM_UZU_Peaking_Coring_pk_en_mask);//_BIT16
		break;

		case PQ_ByPass_SHP_DLTI:
			IoReg_ClearBits(COLOR_SHARP_SHP_DLTI_CTRL_1_reg, COLOR_SHARP_SHP_DLTI_CTRL_1_dlti_en_mask);//_BIT0
		break;

		case PQ_ByPass_DCC:
			IoReg_D_domain_ClearBits(COLOR_D_VC_Global_CTRL_reg, COLOR_D_VC_Global_CTRL_dcc_en_mask);//_BIT0
		break;

		case PQ_ByPass_DCTI:
			IoReg_D_domain_ClearBits(COLOR_D_VC_Global_CTRL_reg, COLOR_D_VC_Global_CTRL_m_dcti_en_mask);//_BIT2
			IoReg_SetBits(COLOR_D_VC_Global_CTRL_DB_reg, COLOR_D_VC_Global_CTRL_DB_db_load_mask);//_BIT0
		break;

		case PQ_ByPass_ICM:
			IoReg_D_domain_ClearBits(COLOR_D_VC_Global_CTRL_reg, COLOR_D_VC_Global_CTRL_m_icm_en_mask);//_BIT3
		break;

		case PQ_ByPass_SHP:
			IoReg_D_domain_ClearBits(COLOR_D_VC_Global_CTRL_reg, COLOR_D_VC_Global_CTRL_m_sharp_en_mask);//_BIT4
		break;

		case PQ_ByPass_Dedge_Smooth:
			IoReg_D_domain_ClearBits(COLOR_D_VC_Global_CTRL_reg, COLOR_D_VC_Global_CTRL_m_edgesmooth_en_mask);//_BIT5
		break;

		case PQ_ByPass_CDS:
			IoReg_ClearBits(COLOR_SHARP_DM_CDS_CM0_U_BOUND_0_reg, COLOR_SHARP_DM_CDS_CM0_U_BOUND_0_cds_enable_mask);//_BIT27
		break;

		case PQ_ByPass_UV_Offset:
			IoReg_ClearBits(YUV2RGB_D_UVOFFSETBYY_CONTROL_reg, YUV2RGB_D_UVOFFSETBYY_CONTROL_uvoffsetbyy_main_en_mask);//_BIT0
		break;

		case PQ_ByPass_V_CTI:
			IoReg_ClearBits(SCALEUP_DM_MEM_CRC_CTRL_reg, SCALEUP_DM_MEM_CRC_CTRL_vcti_en_mask);//_BIT4
		break;

		case PQ_ByPass_sRGB:
			IoReg_ClearBits(SRGB_sRGB_CTRL_reg, SRGB_sRGB_CTRL_srgb_m_tab_sel_mask);//_BIT0|_BIT1
		break;

		case PQ_ByPass_Gamma:
			IoReg_ClearBits(GAMMA_GAMMA_CTRL_2_reg, GAMMA_GAMMA_CTRL_2_gamma_m_tab_sel_mask);//_BIT6|_BIT7
		break;

		case PQ_ByPass_InvGamma:
			IoReg_ClearBits(INV_GAMMA_INV_GAMMA_CTRL_2_reg, INV_GAMMA_INV_GAMMA_CTRL_2_inv_gamma_m_tab_sel_mask);//_BIT6|_BIT7
		break;

		case PQ_ByPass_ColorTemp:
//			IoReg_ClearBits(COLOR_TEMP_Color_Temp_CTRL_reg, COLOR_TEMP_Color_Temp_CTRL_color_temp_en_mask);//_BIT0
		break;

		case PQ_ByPass_DITHER:
			IoReg_ClearBits(DITHER_DITHERING_CTRL_reg, DITHER_DITHERING_CTRL_function_enable_mask);//_BIT5
		break;

		case PQ_ByPass_DITHER_Temporal:
			IoReg_ClearBits(DITHER_DITHERING_CTRL_reg, DITHER_DITHERING_CTRL_temporal_enable_mask);//_BIT4
		break;

		/*Sub*/
#ifdef VIP_CONFIG_DUAL_CHANNEL // henry 161214
		case PQ_ByPass_DCTI_Sub:
			IoReg_ClearBits(COLOR_D_VC_Global_CTRL_reg, COLOR_D_VC_Global_CTRL_s_dcti_en_mask);//_BIT17
		break;

		case PQ_ByPass_ICM_Sub:
			IoReg_ClearBits(COLOR_D_VC_Global_CTRL_reg, COLOR_D_VC_Global_CTRL_s_icm_en_mask);//_BIT18
		break;

		case PQ_ByPass_SHP_Sub:
			IoReg_ClearBits(COLOR_D_VC_Global_CTRL_reg, COLOR_D_VC_Global_CTRL_s_sharp_en_mask);//_BIT19
		break;
#endif
	#if 0 //jyyang20161215
		case PQ_ByPass_sRGB_Sub:
			IoReg_ClearBits(SRGB_sRGB_CTRL_reg, SRGB_sRGB_CTRL_srgb_s_tab_sel_mask);//_BIT2|_BIT3
		break;

		case PQ_ByPass_Gamma_Gamma:
			IoReg_ClearBits(GAMMA_GAMMA_CTRL_2_reg, GAMMA_GAMMA_CTRL_2_gamma_s_tab_sel_mask);//_BIT4|_BIT5
		break;

		case PQ_ByPass_InvGamma_Sub:
			IoReg_ClearBits(INV_GAMMA_INV_GAMMA_CTRL_2_reg, INV_GAMMA_INV_GAMMA_CTRL_2_inv_gamma_s_tab_sel_mask);//_BIT4|_BIT5
		break;
	#endif
		/* new */
		case PQ_ByPass_I_DI_IP_Enable:
			vgip_data_path_select_reg.regValue = IoReg_Read32(VGIP_Data_Path_Select_reg);
			//vgip_data_path_select_reg.uzd1_in_sel = 0;	// can't disable in data fsync mode
			//vgip_data_path_select_reg.xcdi_clk_en = 0;	// can't disable in data fsync mode
			vgip_data_path_select_reg.di_i_clk_en = 0;
			IoReg_Write32(VGIP_Data_Path_Select_reg, vgip_data_path_select_reg.regValue);

			IoReg_SetBits(VGIP_VGIP_CHN1_DOUBLE_BUFFER_CTRL_reg, VGIP_VGIP_CHN1_DOUBLE_BUFFER_CTRL_ch1_db_rdy_mask); /* VGIP DB apply*/

#if 0 // turn off clk
			IoReg_ClearBits(VGIP_Data_Path_Select_reg, VGIP_Data_Path_Select_s1_clk_en_mask);	/* SNR hw issue, turn off cnr clk while h_uzd mux changing*/
			//IoReg_ClearBits(DI_IM_DI_CONTROL_reg, DI_IM_DI_CONTROL_ip_enable_mask);//_BIT28
			di_im_di_control_RBUS di_control_reg;
			di_control_reg.regValue = IoReg_Read32(DI_IM_DI_CONTROL_reg);
			di_control_reg.ip_enable = 0;
			di_control_reg.write_enable_8 = 1;
			IoReg_Write32(DI_IM_DI_CONTROL_reg, di_control_reg.regValue);
			IoReg_ClearBits(VGIP_Data_Path_Select_reg, VGIP_Data_Path_Select_uzd1_in_sel_mask);	/*path need to change while IP disable*/
			IoReg_SetBits(DI_db_reg_ctl_reg, DI_db_reg_ctl_db_apply_mask);	/* HW do not clear this bit, alway turn on, setting will be apply while v_sync*/
			IoReg_SetBits(VGIP_VGIP_CHN1_ACT_HSTA_Width_reg, VGIP_VGIP_CHN1_ACT_HSTA_Width_ch1_db_rdy_mask);	/* path double buffer*/

			db_ready = VGIP_VGIP_CHN1_ACT_HSTA_Width_get_ch1_db_rdy(IoReg_Read32(VGIP_VGIP_CHN1_ACT_HSTA_Width_reg));
			db_en = VGIP_VGIP_CHN1_ACT_HSTA_Width_get_ch1_db_en(IoReg_Read32(VGIP_VGIP_CHN1_ACT_HSTA_Width_reg));
			while((db_ready == 1) && (db_en == 1) && (timeOut > 0)){
				db_ready = VGIP_VGIP_CHN1_ACT_HSTA_Width_get_ch1_db_rdy(IoReg_Read32(VGIP_VGIP_CHN1_ACT_HSTA_Width_reg));
				timeOut--;
			}

			if (timeOut <= 0)
				rtd_printk(KERN_EMERG, TAG_NAME, "PQ bypass, H_UZD db apply timeout!!\n");

			IoReg_SetBits(VGIP_Data_Path_Select_reg, VGIP_Data_Path_Select_s1_clk_en_mask);	/* SNR hw issue, turn off cnr clk while h_uzd mux changing*/
#endif
		break;

		case PQ_ByPass_I_DI:
			IoReg_SetBits(DI_IM_DI_WEAVE_WINDOW_CONTROL_reg, DI_IM_DI_WEAVE_WINDOW_CONTROL_force2d_mask);	/* force 2D*/
			IoReg_SetBits(DI_db_reg_ctl_reg, DI_db_reg_ctl_db_apply_mask);	/* HW do not clear this bit, alway turn on, setting will be apply while v_sync*/
		break;

	}

	return 0;
}
void drvif_color_set_video_fw_irq(void)
{
	ppoverlay_dtg_lc_RBUS dtg_lc_reg;
	ppoverlay_dtg_ie_RBUS	dtg_ie_reg;

	dtg_lc_reg.regValue = IoReg_Read32(PPOVERLAY_DTG_LC_reg);

	dtg_lc_reg.dtg_vlcen=1;
	dtg_lc_reg.dtg_vlc_mode=0;
	dtg_lc_reg.dtg_vlc_src_sel =1;
	IoReg_Write32(PPOVERLAY_DTG_LC_reg, dtg_lc_reg.regValue);

	dtg_ie_reg.regValue = IoReg_Read32(PPOVERLAY_DTG_ie_reg);
	dtg_ie_reg.dtg_vlc_ie=1;
	IoReg_Write32(PPOVERLAY_DTG_ie_reg, dtg_ie_reg.regValue);


}

void WaitDOLBY_DB_Apply_Clean(void)
{
	UINT32 count = 0x032500;
	dolby_v_top_top_d_buf_RBUS top_d_buf_reg;
	do {
		top_d_buf_reg.regValue = rtd_inl(DOLBY_V_TOP_TOP_D_BUF_reg);
	} while(top_d_buf_reg.dolby_double_apply == 1 && count--);
}





void drvif_color_set_Mplus_ModeChange(DRV_Mplus_ModeChange *ptr)
{
	#ifdef MAC5_NO_RGBW
	if(!ptr)
		return;

	lg_m_plus_m_plus_ctl_RBUS lg_m_plus_m_plus_ctl_REG; // 8C00
	lg_m_plus_m_plus_ctl_REG.regValue = IoReg_Read32(LG_M_PLUS_M_plus_ctl_reg);
	lg_m_plus_m_plus_ctl_REG.wpr_on = ptr->wpr_on;
	lg_m_plus_m_plus_ctl_REG.opc_on = ptr->opc_on;
	lg_m_plus_m_plus_ctl_REG.wse_on = ptr->wse_on;
	lg_m_plus_m_plus_ctl_REG.type_sel = ptr->type_sel;
	lg_m_plus_m_plus_ctl_REG.mode_3d = ptr->mode_3d;
	lg_m_plus_m_plus_ctl_REG.test_mode = ptr->test_mode;
	lg_m_plus_m_plus_ctl_REG.mode_sel = ptr->mode_sel;
	IoReg_Write32(LG_M_PLUS_M_plus_ctl_reg, lg_m_plus_m_plus_ctl_REG.regValue);
	return;
	#endif
}


void drvif_color_SetFrameGainLimit(unsigned short nFrameGainLimit)
{
	#ifdef MAC5_NO_RGBW
	lg_m_plus_m_plus_reg4c_RBUS lg_m_plus_m_plus_reg4c_REG;
	lg_m_plus_m_plus_reg4c_REG.regValue = IoReg_Read32(LG_M_PLUS_M_plus_reg4c_reg);
	lg_m_plus_m_plus_reg4c_REG.wpr_reg4e = nFrameGainLimit >> 8;
 	lg_m_plus_m_plus_reg4c_REG.wpr_reg4f = nFrameGainLimit & 0xff;
	IoReg_Write32(LG_M_PLUS_M_plus_reg4c_reg, lg_m_plus_m_plus_reg4c_REG.regValue);
	#endif

}
void drvif_color_GetFrameGainLimit (unsigned short *nFrameGainLimit)
{
	#ifdef MAC5_NO_RGBW
	lg_m_plus_m_plus_reg4c_RBUS lg_m_plus_m_plus_reg4c_REG;
	lg_m_plus_m_plus_reg4c_REG.regValue = IoReg_Read32(LG_M_PLUS_M_plus_reg4c_reg);
	*nFrameGainLimit = lg_m_plus_m_plus_reg4c_REG.regValue & 0x3fff;
	#endif

}
void drvif_color_SetPixelGainLimit(unsigned short nPixelGainLimit)
{
	#ifdef MAC5_NO_RGBW
	lg_m_plus_m_plus_reg64_RBUS lg_m_plus_m_plus_reg64_REG;
	lg_m_plus_m_plus_reg68_RBUS lg_m_plus_m_plus_reg68_REG;

	lg_m_plus_m_plus_reg64_REG.regValue = IoReg_Read32(LG_M_PLUS_M_plus_reg64_reg);
	lg_m_plus_m_plus_reg68_REG.regValue = IoReg_Read32(LG_M_PLUS_M_plus_reg68_reg);

	lg_m_plus_m_plus_reg64_REG.wpr_reg67= nPixelGainLimit >> 8;
	lg_m_plus_m_plus_reg68_REG.wpr_reg68 = nPixelGainLimit & 0xff;
	IoReg_Write32(LG_M_PLUS_M_plus_reg64_reg, lg_m_plus_m_plus_reg64_REG.regValue);
	IoReg_Write32(LG_M_PLUS_M_plus_reg68_reg, lg_m_plus_m_plus_reg68_REG.regValue);
	#endif

}

void drvif_color_GetPixelGainLimit(unsigned short *nPixelGainLimit)
{
	#ifdef MAC5_NO_RGBW
	lg_m_plus_m_plus_reg64_RBUS lg_m_plus_m_plus_reg64_REG;
	lg_m_plus_m_plus_reg68_RBUS lg_m_plus_m_plus_reg68_REG;

	lg_m_plus_m_plus_reg64_REG.regValue = IoReg_Read32(LG_M_PLUS_M_plus_reg64_reg);
	lg_m_plus_m_plus_reg68_REG.regValue = IoReg_Read32(LG_M_PLUS_M_plus_reg68_reg);

	*nPixelGainLimit = (lg_m_plus_m_plus_reg64_REG.wpr_reg67 << 8) + lg_m_plus_m_plus_reg68_REG.wpr_reg68;
	#endif
}





void drvif_color_set_RGBW_Curcuit (VIP_RGBW_MODE mode)
{
#ifdef MAC5_NO_RGBW
	ppoverlay_display_timing_ctrl2_RBUS ppoverlay_display_timing_ctrl2;
	od_dma_oddma_pq_cmp_pair_RBUS od_dma_oddma_pq_cmp_pair;

	ppoverlay_display_timing_ctrl2.regValue = IoReg_Read32(PPOVERLAY_Display_Timing_CTRL2_reg);
	od_dma_oddma_pq_cmp_pair.regValue = IoReg_Read32(OD_DMA_ODDMA_PQ_CMP_PAIR_reg);
	switch(mode) {

		case VIP_RGBW_MODE_DISABLE:
			ppoverlay_display_timing_ctrl2.mplus_rgbw_en = 0; /*Disable*/
			break;
		case VIP_RGBW_MODE_LGDMPLUS:
			od_dma_oddma_pq_cmp_pair.eco_reg_boe_clk_inv = 0; /*Must 0 when not use Himax BOE circuit*/
			ppoverlay_display_timing_ctrl2.mplus_rgbw_en = 1; /*Use LGD M+ Circuit*/
			break;
		case VIP_RGBW_MODE_RTKRGBW:
			od_dma_oddma_pq_cmp_pair.eco_reg_boe_clk_inv = 0; /*Must 0 when not use Himax BOE circuit*/
			ppoverlay_display_timing_ctrl2.mplus_rgbw_en = 2; /*Use RTK RGBW Circuit*/
		case VIP_RGBW_MODE_HIMAXBOE:
			od_dma_oddma_pq_cmp_pair.eco_reg_boe_clk_inv = 1; /*Must 1 when use Himax BOE circuit*/
			ppoverlay_display_timing_ctrl2.mplus_rgbw_en = 4; /*Use Himax BOE Circuit*/
			break;
		default:
			ppoverlay_display_timing_ctrl2.mplus_rgbw_en = 0;
			break;

	}

	IoReg_Write32(OD_DMA_ODDMA_PQ_CMP_PAIR_reg,od_dma_oddma_pq_cmp_pair.regValue);
	IoReg_Write32(PPOVERLAY_Display_Timing_CTRL2_reg,ppoverlay_display_timing_ctrl2.regValue);
#endif
	return;

}



void drvif_color_get_YUV2RGB_nonliner_index(unsigned short *pYidx)
{
	yuv2rgb_d_coefbyy_nonlinear_0_RBUS yuv2rgb_d_coefbyy_nonlinear_0_REG;
	yuv2rgb_d_coefbyy_nonlinear_1_RBUS yuv2rgb_d_coefbyy_nonlinear_1_REG;
	yuv2rgb_d_coefbyy_nonlinear_2_RBUS yuv2rgb_d_coefbyy_nonlinear_2_REG;
	yuv2rgb_d_coefbyy_nonlinear_3_RBUS yuv2rgb_d_coefbyy_nonlinear_3_REG;

	if (pYidx == NULL)
		return;

	yuv2rgb_d_coefbyy_nonlinear_0_REG.regValue = IoReg_Read32(YUV2RGB_D_COEFBYY_NONLINEAR_0_reg);
	yuv2rgb_d_coefbyy_nonlinear_1_REG.regValue = IoReg_Read32(YUV2RGB_D_COEFBYY_NONLINEAR_1_reg);
	yuv2rgb_d_coefbyy_nonlinear_2_REG.regValue = IoReg_Read32(YUV2RGB_D_COEFBYY_NONLINEAR_2_reg);
	yuv2rgb_d_coefbyy_nonlinear_3_REG.regValue = IoReg_Read32(YUV2RGB_D_COEFBYY_NONLINEAR_3_reg);

	pYidx[0] = yuv2rgb_d_coefbyy_nonlinear_0_REG.index_1;
	pYidx[1] = yuv2rgb_d_coefbyy_nonlinear_0_REG.index_2;
	pYidx[2] = yuv2rgb_d_coefbyy_nonlinear_0_REG.index_3;
	pYidx[3] = yuv2rgb_d_coefbyy_nonlinear_0_REG.index_4;

	pYidx[4] = yuv2rgb_d_coefbyy_nonlinear_1_REG.index_5;
	pYidx[5] = yuv2rgb_d_coefbyy_nonlinear_1_REG.index_6;
	pYidx[6] = yuv2rgb_d_coefbyy_nonlinear_1_REG.index_7;
	pYidx[7] = yuv2rgb_d_coefbyy_nonlinear_1_REG.index_8;

	pYidx[8] = yuv2rgb_d_coefbyy_nonlinear_2_REG.index_9;
	pYidx[9] = yuv2rgb_d_coefbyy_nonlinear_2_REG.index_10;
	pYidx[10] = yuv2rgb_d_coefbyy_nonlinear_2_REG.index_11;
	pYidx[11] = yuv2rgb_d_coefbyy_nonlinear_2_REG.index_12;

	pYidx[12] = yuv2rgb_d_coefbyy_nonlinear_3_REG.index_13;
	pYidx[13] = yuv2rgb_d_coefbyy_nonlinear_3_REG.index_14;
	pYidx[14] = yuv2rgb_d_coefbyy_nonlinear_3_REG.index_15;
	pYidx[15] = yuv2rgb_d_coefbyy_nonlinear_3_REG.index_16;
}

void drvif_color_set_outgamma_10bits(void)
{
	rtd_outl(0xb802c804,0x00000160);//--> gamma bypass, write RGB channel
	rtd_outl(0xb802c800,0x00000404);
	rtd_outl(0xb802c800,0x00080404);
	rtd_outl(0xb802c800,0x00100404);
	rtd_outl(0xb802c800,0x00180404);
	rtd_outl(0xb802c800,0x00200404);
	rtd_outl(0xb802c800,0x00280404);
	rtd_outl(0xb802c800,0x00300404);
	rtd_outl(0xb802c800,0x00380404);
	rtd_outl(0xb802c800,0x00400404);
	rtd_outl(0xb802c800,0x00480404);
	rtd_outl(0xb802c800,0x00500404);
	rtd_outl(0xb802c800,0x00580404);
	rtd_outl(0xb802c800,0x00600404);
	rtd_outl(0xb802c800,0x00680404);
	rtd_outl(0xb802c800,0x00700404);
	rtd_outl(0xb802c800,0x00780404);
	rtd_outl(0xb802c800,0x00800404);
	rtd_outl(0xb802c800,0x00880404);
	rtd_outl(0xb802c800,0x00900404);
	rtd_outl(0xb802c800,0x00980404);
	rtd_outl(0xb802c800,0x00a00404);
	rtd_outl(0xb802c800,0x00a80404);
	rtd_outl(0xb802c800,0x00b00404);
	rtd_outl(0xb802c800,0x00b80404);
	rtd_outl(0xb802c800,0x00c00404);
	rtd_outl(0xb802c800,0x00c80404);
	rtd_outl(0xb802c800,0x00d00404);
	rtd_outl(0xb802c800,0x00d80404);
	rtd_outl(0xb802c800,0x00e00404);
	rtd_outl(0xb802c800,0x00e80404);
	rtd_outl(0xb802c800,0x00f00404);
	rtd_outl(0xb802c800,0x00f80404);
	rtd_outl(0xb802c800,0x01000404);
	rtd_outl(0xb802c800,0x01080404);
	rtd_outl(0xb802c800,0x01100404);
	rtd_outl(0xb802c800,0x01180404);
	rtd_outl(0xb802c800,0x01200404);
	rtd_outl(0xb802c800,0x01280404);
	rtd_outl(0xb802c800,0x01300404);
	rtd_outl(0xb802c800,0x01380404);
	rtd_outl(0xb802c800,0x01400404);
	rtd_outl(0xb802c800,0x01480404);
	rtd_outl(0xb802c800,0x01500404);
	rtd_outl(0xb802c800,0x01580404);
	rtd_outl(0xb802c800,0x01600404);
	rtd_outl(0xb802c800,0x01680404);
	rtd_outl(0xb802c800,0x01700404);
	rtd_outl(0xb802c800,0x01780404);
	rtd_outl(0xb802c800,0x01800404);
	rtd_outl(0xb802c800,0x01880404);
	rtd_outl(0xb802c800,0x01900404);
	rtd_outl(0xb802c800,0x01980404);
	rtd_outl(0xb802c800,0x01a00404);
	rtd_outl(0xb802c800,0x01a80404);
	rtd_outl(0xb802c800,0x01b00404);
	rtd_outl(0xb802c800,0x01b80404);
	rtd_outl(0xb802c800,0x01c00404);
	rtd_outl(0xb802c800,0x01c80404);
	rtd_outl(0xb802c800,0x01d00404);
	rtd_outl(0xb802c800,0x01d80404);
	rtd_outl(0xb802c800,0x01e00404);
	rtd_outl(0xb802c800,0x01e80404);
	rtd_outl(0xb802c800,0x01f00404);
	rtd_outl(0xb802c800,0x01f80404);
	rtd_outl(0xb802c800,0x02000404);
	rtd_outl(0xb802c800,0x02080404);
	rtd_outl(0xb802c800,0x02100404);
	rtd_outl(0xb802c800,0x02180404);
	rtd_outl(0xb802c800,0x02200404);
	rtd_outl(0xb802c800,0x02280404);
	rtd_outl(0xb802c800,0x02300404);
	rtd_outl(0xb802c800,0x02380404);
	rtd_outl(0xb802c800,0x02400404);
	rtd_outl(0xb802c800,0x02480404);
	rtd_outl(0xb802c800,0x02500404);
	rtd_outl(0xb802c800,0x02580404);
	rtd_outl(0xb802c800,0x02600404);
	rtd_outl(0xb802c800,0x02680404);
	rtd_outl(0xb802c800,0x02700404);
	rtd_outl(0xb802c800,0x02780404);
	rtd_outl(0xb802c800,0x02800404);
	rtd_outl(0xb802c800,0x02880404);
	rtd_outl(0xb802c800,0x02900404);
	rtd_outl(0xb802c800,0x02980404);
	rtd_outl(0xb802c800,0x02a00404);
	rtd_outl(0xb802c800,0x02a80404);
	rtd_outl(0xb802c800,0x02b00404);
	rtd_outl(0xb802c800,0x02b80404);
	rtd_outl(0xb802c800,0x02c00404);
	rtd_outl(0xb802c800,0x02c80404);
	rtd_outl(0xb802c800,0x02d00404);
	rtd_outl(0xb802c800,0x02d80404);
	rtd_outl(0xb802c800,0x02e00404);
	rtd_outl(0xb802c800,0x02e80404);
	rtd_outl(0xb802c800,0x02f00404);
	rtd_outl(0xb802c800,0x02f80404);
	rtd_outl(0xb802c800,0x03000404);
	rtd_outl(0xb802c800,0x03080404);
	rtd_outl(0xb802c800,0x03100404);
	rtd_outl(0xb802c800,0x03180404);
	rtd_outl(0xb802c800,0x03200404);
	rtd_outl(0xb802c800,0x03280404);
	rtd_outl(0xb802c800,0x03300404);
	rtd_outl(0xb802c800,0x03380404);
	rtd_outl(0xb802c800,0x03400404);
	rtd_outl(0xb802c800,0x03480404);
	rtd_outl(0xb802c800,0x03500404);
	rtd_outl(0xb802c800,0x03580404);
	rtd_outl(0xb802c800,0x03600404);
	rtd_outl(0xb802c800,0x03680404);
	rtd_outl(0xb802c800,0x03700404);
	rtd_outl(0xb802c800,0x03780404);
	rtd_outl(0xb802c800,0x03800404);
	rtd_outl(0xb802c800,0x03880404);
	rtd_outl(0xb802c800,0x03900404);
	rtd_outl(0xb802c800,0x03980404);
	rtd_outl(0xb802c800,0x03a00404);
	rtd_outl(0xb802c800,0x03a80404);
	rtd_outl(0xb802c800,0x03b00404);
	rtd_outl(0xb802c800,0x03b80404);
	rtd_outl(0xb802c800,0x03c00404);
	rtd_outl(0xb802c800,0x03c80404);
	rtd_outl(0xb802c800,0x03d00404);
	rtd_outl(0xb802c800,0x03d80404);
	rtd_outl(0xb802c800,0x03e00404);
	rtd_outl(0xb802c800,0x03e80404);
	rtd_outl(0xb802c800,0x03f00404);
	rtd_outl(0xb802c800,0x03f80404);
	rtd_outl(0xb802c804,0x00000180);//--> W channel, ax table1
	rtd_outl(0xb802c800,0x00000404);
	rtd_outl(0xb802c800,0x00080404);
	rtd_outl(0xb802c800,0x00100404);
	rtd_outl(0xb802c800,0x00180404);
	rtd_outl(0xb802c800,0x00200404);
	rtd_outl(0xb802c800,0x00280404);
	rtd_outl(0xb802c800,0x00300404);
	rtd_outl(0xb802c800,0x00380404);
	rtd_outl(0xb802c800,0x00400404);
	rtd_outl(0xb802c800,0x00480404);
	rtd_outl(0xb802c800,0x00500404);
	rtd_outl(0xb802c800,0x00580404);
	rtd_outl(0xb802c800,0x00600404);
	rtd_outl(0xb802c800,0x00680404);
	rtd_outl(0xb802c800,0x00700404);
	rtd_outl(0xb802c800,0x00780404);
	rtd_outl(0xb802c800,0x00800404);
	rtd_outl(0xb802c800,0x00880404);
	rtd_outl(0xb802c800,0x00900404);
	rtd_outl(0xb802c800,0x00980404);
	rtd_outl(0xb802c800,0x00a00404);
	rtd_outl(0xb802c800,0x00a80404);
	rtd_outl(0xb802c800,0x00b00404);
	rtd_outl(0xb802c800,0x00b80404);
	rtd_outl(0xb802c800,0x00c00404);
	rtd_outl(0xb802c800,0x00c80404);
	rtd_outl(0xb802c800,0x00d00404);
	rtd_outl(0xb802c800,0x00d80404);
	rtd_outl(0xb802c800,0x00e00404);
	rtd_outl(0xb802c800,0x00e80404);
	rtd_outl(0xb802c800,0x00f00404);
	rtd_outl(0xb802c800,0x00f80404);
	rtd_outl(0xb802c800,0x01000404);
	rtd_outl(0xb802c800,0x01080404);
	rtd_outl(0xb802c800,0x01100404);
	rtd_outl(0xb802c800,0x01180404);
	rtd_outl(0xb802c800,0x01200404);
	rtd_outl(0xb802c800,0x01280404);
	rtd_outl(0xb802c800,0x01300404);
	rtd_outl(0xb802c800,0x01380404);
	rtd_outl(0xb802c800,0x01400404);
	rtd_outl(0xb802c800,0x01480404);
	rtd_outl(0xb802c800,0x01500404);
	rtd_outl(0xb802c800,0x01580404);
	rtd_outl(0xb802c800,0x01600404);
	rtd_outl(0xb802c800,0x01680404);
	rtd_outl(0xb802c800,0x01700404);
	rtd_outl(0xb802c800,0x01780404);
	rtd_outl(0xb802c800,0x01800404);
	rtd_outl(0xb802c800,0x01880404);
	rtd_outl(0xb802c800,0x01900404);
	rtd_outl(0xb802c800,0x01980404);
	rtd_outl(0xb802c800,0x01a00404);
	rtd_outl(0xb802c800,0x01a80404);
	rtd_outl(0xb802c800,0x01b00404);
	rtd_outl(0xb802c800,0x01b80404);
	rtd_outl(0xb802c800,0x01c00404);
	rtd_outl(0xb802c800,0x01c80404);
	rtd_outl(0xb802c800,0x01d00404);
	rtd_outl(0xb802c800,0x01d80404);
	rtd_outl(0xb802c800,0x01e00404);
	rtd_outl(0xb802c800,0x01e80404);
	rtd_outl(0xb802c800,0x01f00404);
	rtd_outl(0xb802c800,0x01f80404);
	rtd_outl(0xb802c800,0x02000404);
	rtd_outl(0xb802c800,0x02080404);
	rtd_outl(0xb802c800,0x02100404);
	rtd_outl(0xb802c800,0x02180404);
	rtd_outl(0xb802c800,0x02200404);
	rtd_outl(0xb802c800,0x02280404);
	rtd_outl(0xb802c800,0x02300404);
	rtd_outl(0xb802c800,0x02380404);
	rtd_outl(0xb802c800,0x02400404);
	rtd_outl(0xb802c800,0x02480404);
	rtd_outl(0xb802c800,0x02500404);
	rtd_outl(0xb802c800,0x02580404);
	rtd_outl(0xb802c800,0x02600404);
	rtd_outl(0xb802c800,0x02680404);
	rtd_outl(0xb802c800,0x02700404);
	rtd_outl(0xb802c800,0x02780404);
	rtd_outl(0xb802c800,0x02800404);
	rtd_outl(0xb802c800,0x02880404);
	rtd_outl(0xb802c800,0x02900404);
	rtd_outl(0xb802c800,0x02980404);
	rtd_outl(0xb802c800,0x02a00404);
	rtd_outl(0xb802c800,0x02a80404);
	rtd_outl(0xb802c800,0x02b00404);
	rtd_outl(0xb802c800,0x02b80404);
	rtd_outl(0xb802c800,0x02c00404);
	rtd_outl(0xb802c800,0x02c80404);
	rtd_outl(0xb802c800,0x02d00404);
	rtd_outl(0xb802c800,0x02d80404);
	rtd_outl(0xb802c800,0x02e00404);
	rtd_outl(0xb802c800,0x02e80404);
	rtd_outl(0xb802c800,0x02f00404);
	rtd_outl(0xb802c800,0x02f80404);
	rtd_outl(0xb802c800,0x03000404);
	rtd_outl(0xb802c800,0x03080404);
	rtd_outl(0xb802c800,0x03100404);
	rtd_outl(0xb802c800,0x03180404);
	rtd_outl(0xb802c800,0x03200404);
	rtd_outl(0xb802c800,0x03280404);
	rtd_outl(0xb802c800,0x03300404);
	rtd_outl(0xb802c800,0x03380404);
	rtd_outl(0xb802c800,0x03400404);
	rtd_outl(0xb802c800,0x03480404);
	rtd_outl(0xb802c800,0x03500404);
	rtd_outl(0xb802c800,0x03580404);
	rtd_outl(0xb802c800,0x03600404);
	rtd_outl(0xb802c800,0x03680404);
	rtd_outl(0xb802c800,0x03700404);
	rtd_outl(0xb802c800,0x03780404);
	rtd_outl(0xb802c800,0x03800404);
	rtd_outl(0xb802c800,0x03880404);
	rtd_outl(0xb802c800,0x03900404);
	rtd_outl(0xb802c800,0x03980404);
	rtd_outl(0xb802c800,0x03a00404);
	rtd_outl(0xb802c800,0x03a80404);
	rtd_outl(0xb802c800,0x03b00404);
	rtd_outl(0xb802c800,0x03b80404);
	rtd_outl(0xb802c800,0x03c00404);
	rtd_outl(0xb802c800,0x03c80404);
	rtd_outl(0xb802c800,0x03d00404);
	rtd_outl(0xb802c800,0x03d80404);
	rtd_outl(0xb802c800,0x03e00404);
	rtd_outl(0xb802c800,0x03e80404);
	rtd_outl(0xb802c800,0x03f00404);
	rtd_outl(0xb802c800,0x03f80404);
	rtd_outl(0xb802c804,0x00000081);// disable access, enable gamma
	rtd_maskl(0xb802c814,0xFFFCFFFF,0x00010000);// rgb, loc1
}

static bool intPtnenabled = false;
void drvif_color_set_Partten4AutoGamma(unsigned char  Enable, unsigned short  r_Val,unsigned short  g_Val,unsigned short  b_Val)
{
	unsigned int temp;
	unsigned int yuv2rgbmode;
	static unsigned int table_index[_YUV2RGB_Boffset+1];
	yuv2rgb_d_yuv2rgb_control_RBUS d_yuv2rgb_control_REG;
	yuv2rgb_d_yuv2rgb_control_1_RBUS d_yuv2rgb_control_1_reg;

	yuv2rgb_d_yuv2rgb_tab1_data_0_RBUS d_yuv2rgb_tab1_data_0_REG;
	yuv2rgb_d_yuv2rgb_tab1_data_1_RBUS d_yuv2rgb_tab1_data_1_REG;
	yuv2rgb_d_yuv2rgb_tab1_data_2_RBUS d_yuv2rgb_tab1_data_2_REG;
	yuv2rgb_d_yuv2rgb_tab1_data_3_RBUS d_yuv2rgb_tab1_data_3_REG;
	yuv2rgb_d_yuv2rgb_tab1_data_4_RBUS d_yuv2rgb_tab1_data_4_REG;
	yuv2rgb_d_yuv2rgb_tab1_data_5_RBUS d_yuv2rgb_tab1_data_5_REG;
	yuv2rgb_d_yuv2rgb_tab1_data_6_RBUS d_yuv2rgb_tab1_data_6_REG;
	yuv2rgb_d_yuv2rgbbyy_control_RBUS    d_yuv2rgbbyy_control_REG;

	d_yuv2rgbbyy_control_REG.regValue = IoReg_Read32(YUV2RGB_D_YUV2RGBBYY_CONTROL_reg);

	d_yuv2rgb_tab1_data_0_REG.regValue = IoReg_Read32(YUV2RGB_D_YUV2RGB_Tab1_Data_0_reg);
	d_yuv2rgb_tab1_data_1_REG.regValue = IoReg_Read32(YUV2RGB_D_YUV2RGB_Tab1_Data_1_reg);
	d_yuv2rgb_tab1_data_2_REG.regValue = IoReg_Read32(YUV2RGB_D_YUV2RGB_Tab1_Data_2_reg);
	d_yuv2rgb_tab1_data_3_REG.regValue = IoReg_Read32(YUV2RGB_D_YUV2RGB_Tab1_Data_3_reg);
	d_yuv2rgb_tab1_data_4_REG.regValue = IoReg_Read32(YUV2RGB_D_YUV2RGB_Tab1_Data_4_reg);
	d_yuv2rgb_tab1_data_5_REG.regValue = IoReg_Read32(YUV2RGB_D_YUV2RGB_Tab1_Data_5_reg);
	d_yuv2rgb_tab1_data_6_REG.regValue = IoReg_Read32(YUV2RGB_D_YUV2RGB_Tab1_Data_6_reg);


	d_yuv2rgb_control_REG.regValue = IoReg_Read32(YUV2RGB_D_YUV2RGB_Control_reg);
	d_yuv2rgb_control_1_reg.regValue = IoReg_Read32(YUV2RGB_D_YUV2RGB_Control_1_reg);

	d_yuv2rgb_control_1_reg.yuv2rgb_db_apply = 1;
	//IoReg_Write32(YUV2RGB_D_YUV2RGB_Control_reg, d_yuv2rgb_control_1_reg.regValue);
	IoReg_Write32(YUV2RGB_D_YUV2RGB_Control_1_reg, d_yuv2rgb_control_1_reg.regValue);


	if(Enable)
	{
		//Select table1
		d_yuv2rgb_control_REG.yuv2rgb_main_tab_sel = 0;
		//Select coef mode
		if(intPtnenabled == 0)
		{
			yuv2rgbmode = d_yuv2rgbbyy_control_REG.yuv2rgbbymode_main_en;

			table_index[_YUV2RGB_k11] = d_yuv2rgb_tab1_data_0_REG.k11;
			table_index[_YUV2RGB_k12] = d_yuv2rgb_tab1_data_0_REG.k12;
			table_index[_YUV2RGB_k13] = d_yuv2rgb_tab1_data_1_REG.k13;
			table_index[_YUV2RGB_k22] = d_yuv2rgb_tab1_data_2_REG.k22;
			table_index[_YUV2RGB_k23] = d_yuv2rgb_tab1_data_2_REG.k23 ;
			table_index[_YUV2RGB_k32] = d_yuv2rgb_tab1_data_3_REG.k32;
			table_index[_YUV2RGB_k33] = d_yuv2rgb_tab1_data_3_REG.k33;
			table_index[_YUV2RGB_Roffset] = d_yuv2rgb_tab1_data_4_REG.roffset;
			table_index[_YUV2RGB_Goffset] = d_yuv2rgb_tab1_data_5_REG.goffset;
			table_index[_YUV2RGB_Boffset] = d_yuv2rgb_tab1_data_6_REG.boffset;

		}
		d_yuv2rgbbyy_control_REG.yuv2rgbbymode_main_en = 0;
		//Set yuv2rgb matrix
		d_yuv2rgb_tab1_data_0_REG.regValue = 0;
		d_yuv2rgb_tab1_data_1_REG.regValue = 0;
		d_yuv2rgb_tab1_data_2_REG.regValue = 0;
		d_yuv2rgb_tab1_data_3_REG.regValue = 0;

		//Set RGB offset (14 bits)

		temp = r_Val << 6;
		if (r_Val == 255 )
			temp = 0x3fff;
		d_yuv2rgb_tab1_data_4_REG.regValue = temp;

		temp = g_Val << 6;
		if (g_Val == 255 )
			temp = 0x3fff;
		d_yuv2rgb_tab1_data_5_REG.regValue = temp;

		temp =b_Val << 6;
		if (b_Val == 255 )
			temp = 0x3fff;
		d_yuv2rgb_tab1_data_6_REG.regValue = temp;
		intPtnenabled = 1;
	}
	else
	{
		//table_index = tYUV2RGB_COEF_601_YCbCr_limit2full_range;

		//Select table1
		d_yuv2rgb_control_REG.yuv2rgb_main_tab_sel = 0;
		//Select coef mode
		if(intPtnenabled == 1)
		{
			d_yuv2rgbbyy_control_REG.yuv2rgbbymode_main_en = yuv2rgbmode;
			intPtnenabled = 0;
		}
		//Set yuv2rgb matrix
		d_yuv2rgb_tab1_data_0_REG.k11 = table_index[_YUV2RGB_k11];
		d_yuv2rgb_tab1_data_0_REG.k12 = table_index[_YUV2RGB_k12];
		d_yuv2rgb_tab1_data_1_REG.k13 = table_index[_YUV2RGB_k13];
		d_yuv2rgb_tab1_data_2_REG.k22 = table_index[_YUV2RGB_k22];
		d_yuv2rgb_tab1_data_2_REG.k23 = table_index[_YUV2RGB_k23];
		d_yuv2rgb_tab1_data_3_REG.k32 = table_index[_YUV2RGB_k32];
		d_yuv2rgb_tab1_data_3_REG.k33 = table_index[_YUV2RGB_k33];
		d_yuv2rgb_tab1_data_4_REG.roffset = table_index[_YUV2RGB_Roffset];
		d_yuv2rgb_tab1_data_5_REG.goffset = table_index[_YUV2RGB_Goffset];
		d_yuv2rgb_tab1_data_6_REG.boffset = table_index[_YUV2RGB_Boffset];

	}
	IoReg_Write32(YUV2RGB_D_YUV2RGB_Tab1_Data_0_reg, d_yuv2rgb_tab1_data_0_REG.regValue);
	IoReg_Write32(YUV2RGB_D_YUV2RGB_Tab1_Data_1_reg, d_yuv2rgb_tab1_data_1_REG.regValue);
	IoReg_Write32(YUV2RGB_D_YUV2RGB_Tab1_Data_2_reg, d_yuv2rgb_tab1_data_2_REG.regValue);
	IoReg_Write32(YUV2RGB_D_YUV2RGB_Tab1_Data_3_reg, d_yuv2rgb_tab1_data_3_REG.regValue);
	IoReg_Write32(YUV2RGB_D_YUV2RGB_Tab1_Data_4_reg, d_yuv2rgb_tab1_data_4_REG.regValue);
	IoReg_Write32(YUV2RGB_D_YUV2RGB_Tab1_Data_5_reg, d_yuv2rgb_tab1_data_5_REG.regValue);
	IoReg_Write32(YUV2RGB_D_YUV2RGB_Tab1_Data_6_reg, d_yuv2rgb_tab1_data_6_REG.regValue);
	IoReg_Write32(YUV2RGB_D_YUV2RGB_Control_reg, d_yuv2rgb_control_REG.regValue);
	IoReg_Write32(YUV2RGB_D_YUV2RGBBYY_CONTROL_reg,d_yuv2rgbbyy_control_REG.regValue);
}

void drvif_color_set_Partten4AutoGamma_mute(unsigned char mute_flag, unsigned char display_flag,Drvif_SCALER_DISPLAY_DATA* sdp_info)
{

	//rtd_printk(KERN_EMERG, "\n\n\n\n\n----zjl----[]", "drvif_color_set_Partten4AutoGamma_mute mute_flag =%d display_flag =%d\n\n\n\n\n",mute_flag,display_flag);
    ppoverlay_double_buffer_ctrl_RBUS double_buffer_ctrl_reg;
    ppoverlay_main_display_control_rsv_RBUS main_display_control_rsv_reg;
    unsigned long flags;//for spin_lock_irqsave

    unsigned short VRatioOffset = 0, HRatioOffset = 0;
    unsigned short HStartOffset = 0;
    unsigned short VStartOffset = 0;

	if(display_flag == 1)
	{
		StructSrcRect m_dispwin_set;
		
		m_dispwin_set.srcx = sdp_info->h_sta << 3;//825;
		m_dispwin_set.srcy = sdp_info->h_end << 3;//405;
		m_dispwin_set.src_height = sdp_info->v_sta << 3;//270;
		m_dispwin_set.src_wid = sdp_info->v_end << 3;//270;

		//rtd_printk(KERN_EMERG, "\n\n\n\n\n----zjl----[]", "drvif_color_set_Partten4AutoGamma_mute srcx =%d srcy =%d\n\n\n\n\n",m_dispwin_set.srcx,m_dispwin_set.srcy);
		//rtd_printk(KERN_EMERG, "\n\n\n\n\n----zjl----[]", "drvif_color_set_Partten4AutoGamma_mute src_height =%d src_wid =%d\n\n\n\n\n",m_dispwin_set.src_height,m_dispwin_set.src_wid);

		Scaler_DispWindowSet(m_dispwin_set);
		StructSrcRect m_dispwin = Scaler_DispWindowGet();
			   HRatioOffset =  m_dispwin.srcx;
			   VRatioOffset = m_dispwin.srcy;
			   scalerdisplay_set_main_act_window(
							   (unsigned short)Get_DISP_ACT_STA_HPOS() + HRatioOffset + HStartOffset,
							   (unsigned short)Get_DISP_ACT_STA_HPOS() + Scaler_DispWindowGet().src_wid + HRatioOffset + HStartOffset ,
							   (unsigned short)Get_DISP_ACT_STA_VPOS() + VRatioOffset + VStartOffset,
							   (unsigned short)Get_DISP_ACT_STA_VPOS() + Scaler_DispWindowGet().src_height+ VRatioOffset + VStartOffset );
	}
		
	if(mute_flag == 1)
	{
		down(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
		spin_lock_irqsave(get_DBreg_spinlock(SLR_MAIN_DISPLAY), flags);//lock double buffer spinlock
		double_buffer_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL_reg);
		double_buffer_ctrl_reg.dmainreg_dbuf_en = 0;
		IoReg_Write32(PPOVERLAY_Double_Buffer_CTRL_reg, double_buffer_ctrl_reg.regValue);

		main_display_control_rsv_reg.regValue = IoReg_Read32(PPOVERLAY_Main_Display_Control_RSV_reg);
		main_display_control_rsv_reg.m_force_bg = 0;
		main_display_control_rsv_reg.main_wd_to_background = 0;
		IoReg_Write32(PPOVERLAY_Main_Display_Control_RSV_reg, main_display_control_rsv_reg.regValue);

		double_buffer_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL_reg);
		double_buffer_ctrl_reg.dmainreg_dbuf_en = 1;
		IoReg_Write32(PPOVERLAY_Double_Buffer_CTRL_reg, double_buffer_ctrl_reg.regValue);

		spin_unlock_irqrestore(get_DBreg_spinlock(SLR_MAIN_DISPLAY), flags);//unlock double buffer spinlock
		up(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
	}
	else if(mute_flag == 3)	//still have signal, No mute
	{
		
		down(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
		spin_lock_irqsave(get_DBreg_spinlock(SLR_MAIN_DISPLAY), flags);//lock double buffer spinlock
		double_buffer_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL_reg);
		double_buffer_ctrl_reg.dmainreg_dbuf_en = 0;
		IoReg_Write32(PPOVERLAY_Double_Buffer_CTRL_reg, double_buffer_ctrl_reg.regValue);
		
		main_display_control_rsv_reg.regValue = IoReg_Read32(PPOVERLAY_Main_Display_Control_RSV_reg);
		main_display_control_rsv_reg.m_force_bg = 0;//check it later
		main_display_control_rsv_reg.main_wd_to_background = 1;
		IoReg_Write32(PPOVERLAY_Main_Display_Control_RSV_reg, main_display_control_rsv_reg.regValue);
		
		
		double_buffer_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL_reg);
		double_buffer_ctrl_reg.dmainreg_dbuf_en = 1;
		IoReg_Write32(PPOVERLAY_Double_Buffer_CTRL_reg, double_buffer_ctrl_reg.regValue);
		
		spin_unlock_irqrestore(get_DBreg_spinlock(SLR_MAIN_DISPLAY), flags);//unlock double buffer spinlock
		up(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
	}
	else if(mute_flag == 0){
		
		down(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
		spin_lock_irqsave(get_DBreg_spinlock(SLR_MAIN_DISPLAY), flags);//lock double buffer spinlock
		double_buffer_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL_reg);
		double_buffer_ctrl_reg.dmainreg_dbuf_en = 0;
		IoReg_Write32(PPOVERLAY_Double_Buffer_CTRL_reg, double_buffer_ctrl_reg.regValue);
		
		main_display_control_rsv_reg.regValue = IoReg_Read32(PPOVERLAY_Main_Display_Control_RSV_reg);
		main_display_control_rsv_reg.m_force_bg = 1;//check it later
		main_display_control_rsv_reg.main_wd_to_background = 1;
		IoReg_Write32(PPOVERLAY_Main_Display_Control_RSV_reg, main_display_control_rsv_reg.regValue);	
		
		double_buffer_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL_reg);
		double_buffer_ctrl_reg.dmainreg_dbuf_en = 1;
		IoReg_Write32(PPOVERLAY_Double_Buffer_CTRL_reg, double_buffer_ctrl_reg.regValue);
			
		spin_unlock_irqrestore(get_DBreg_spinlock(SLR_MAIN_DISPLAY), flags);//unlock double buffer spinlock
		up(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/

	}
}

char drvif_color_set_PQ_Module(unsigned char bypass_item,unsigned char bEnable)
{
	switch(bypass_item) {
		/*===============I Domain===========*/
		case PQ_ByPass_Iedge_Smooth:
			if(bEnable){
				IoReg_SetBits(IEDGE_SMOOTH_EdgeSmooth_EX_CTRL_reg, IEDGE_SMOOTH_EdgeSmooth_EX_CTRL_edgesmoothex_en_mask);
			}
			else{
				IoReg_ClearBits(IEDGE_SMOOTH_EdgeSmooth_EX_CTRL_reg, IEDGE_SMOOTH_EdgeSmooth_EX_CTRL_edgesmoothex_en_mask);//_BIT0
			}
		break;

		case PQ_ByPass_MPEG_NR:
			if(bEnable){
				IoReg_SetBits(MPEGNR_ICH1_MPEGNR2_reg, MPEGNR_ICH1_MPEGNR2_cp_mpegenable_x_mask);
			}
			else{
				IoReg_ClearBits(MPEGNR_ICH1_MPEGNR2_reg, MPEGNR_ICH1_MPEGNR2_cp_mpegenable_x_mask);//_BIT0
			}
                        IoReg_SetBits(NR_SNR_DB_CTRL_reg, NR_SNR_DB_CTRL_snr_db_apply_mask); /* SNR DB apply */
		break;

		case PQ_ByPass_HSD_DITHER:
			if(bEnable){
				IoReg_SetBits(HSD_DITHER_SD_Dither_CTRL1_reg, HSD_DITHER_SD_Dither_CTRL1_ch1_dithering_table_select_mask);
			}
			else{
				IoReg_ClearBits(HSD_DITHER_SD_Dither_CTRL1_reg, HSD_DITHER_SD_Dither_CTRL1_ch1_dithering_table_select_mask); //_BIT5 | _BIT6
			}
		break;

		case PQ_ByPass_HSD_DITHER_Temporal:
			if(bEnable){
				IoReg_SetBits(HSD_DITHER_SD_Dither_CTRL1_reg, HSD_DITHER_SD_Dither_CTRL1_ch1_temporal_enable_mask);//_BIT4
			}
			else{
			IoReg_ClearBits(HSD_DITHER_SD_Dither_CTRL1_reg, HSD_DITHER_SD_Dither_CTRL1_ch1_temporal_enable_mask);//_BIT4
			}
		break;

		case PQ_ByPass_RTNR_Y:
			if(bEnable){
				IoReg_SetBits(DI_IM_DI_RTNR_CONTROL_reg, DI_IM_DI_RTNR_CONTROL_cp_rtnr_y_enable_mask);//_BIT0
			}
			else{
				IoReg_ClearBits(DI_IM_DI_RTNR_CONTROL_reg, DI_IM_DI_RTNR_CONTROL_cp_rtnr_y_enable_mask);//_BIT0
			}
                        IoReg_SetBits(DI_db_reg_ctl_reg, DI_db_reg_ctl_db_apply_mask);	/* HW do not clear this bit, alway turn on, setting will be apply while v_sync*/
		break;

		case PQ_ByPass_RTNR_C:
			if(bEnable){
				IoReg_SetBits(DI_IM_DI_RTNR_CONTROL_reg, DI_IM_DI_RTNR_CONTROL_cp_rtnr_c_enable_mask);//_BIT1
			}
			else{
				IoReg_ClearBits(DI_IM_DI_RTNR_CONTROL_reg, DI_IM_DI_RTNR_CONTROL_cp_rtnr_c_enable_mask);//_BIT1
			}
                        IoReg_SetBits(DI_db_reg_ctl_reg, DI_db_reg_ctl_db_apply_mask);	/* HW do not clear this bit, alway turn on, setting will be apply while v_sync*/
		break;
		case PQ_ByPass_MCNR:
			if(bEnable){
				IoReg_SetBits(DI_IM_DI_RTNR_HMCNR_reg, DI_IM_DI_RTNR_HMCNR_cp_temporal_hmcnr_y_en_mask);//_BIT7
			}
			else{
				IoReg_ClearBits(DI_IM_DI_RTNR_HMCNR_reg, DI_IM_DI_RTNR_HMCNR_cp_temporal_hmcnr_y_en_mask);//_BIT7
			}
		break;

		case PQ_ByPass_I_DCTI:
			if(bEnable){
				IoReg_SetBits(IDCTI_I_DCTI_CTRL_1_reg, IDCTI_I_DCTI_CTRL_1_dcti_en_mask);//_BIT0
			}
			else{
				IoReg_ClearBits(IDCTI_I_DCTI_CTRL_1_reg, IDCTI_I_DCTI_CTRL_1_dcti_en_mask);//_BIT0
			}
		break;

		case PQ_ByPass_ImpulseNR:
			if(bEnable){
				IoReg_SetBits(NR_DCH1_CP_Ctrl_reg, NR_DCH1_CP_Ctrl_cp_impulseenable_mask);//_BIT0
			}
			else{
				IoReg_ClearBits(NR_DCH1_CP_Ctrl_reg, NR_DCH1_CP_Ctrl_cp_impulseenable_mask);//_BIT0
			}
                        IoReg_SetBits(NR_SNR_DB_CTRL_reg, NR_SNR_DB_CTRL_snr_db_apply_mask); /* DB apply */
		break;

		case PQ_ByPass_SNR_C:
			if(bEnable){
				IoReg_SetBits(NR_DCH1_CP_Ctrl_reg, NR_DCH1_CP_Ctrl_cp_spatialenablec_mask);//_BIT1
			}
			else{
				IoReg_ClearBits(NR_DCH1_CP_Ctrl_reg, NR_DCH1_CP_Ctrl_cp_spatialenablec_mask);//_BIT1
			}
                        IoReg_SetBits(NR_SNR_DB_CTRL_reg, NR_SNR_DB_CTRL_snr_db_apply_mask); /* DB apply */
		break;

		case PQ_ByPass_SNR_Y:
			if(bEnable){
				IoReg_SetBits(NR_DCH1_CP_Ctrl_reg, NR_DCH1_CP_Ctrl_cp_spatialenabley_mask);//_BIT2
			}
			else{
				IoReg_ClearBits(NR_DCH1_CP_Ctrl_reg, NR_DCH1_CP_Ctrl_cp_spatialenabley_mask);//_BIT2
			}
                        IoReg_SetBits(NR_SNR_DB_CTRL_reg, NR_SNR_DB_CTRL_snr_db_apply_mask); /* DB apply */
		break;

		case PQ_ByPass_MosquiutoNR:
			if(bEnable){
				IoReg_SetBits(NR_MOSQUITO_CTRL_reg, NR_MOSQUITO_CTRL_mosquito_detect_en_mask);//_BIT0
			}
			else{
				IoReg_ClearBits(NR_MOSQUITO_CTRL_reg, NR_MOSQUITO_CTRL_mosquito_detect_en_mask);//_BIT0
			}
		break;

		case PQ_ByPass_I_Peaking:
		break;

		case PQ_ByPass_MB_Peaking:
			if(bEnable){
				IoReg_SetBits(COLOR_MB_PEAKING_MB_PEAKING_CTRL_reg, COLOR_MB_PEAKING_MB_PEAKING_CTRL_mb_peaking_en_mask);//_BIT0
			}
			else{
				IoReg_ClearBits(COLOR_MB_PEAKING_MB_PEAKING_CTRL_reg, COLOR_MB_PEAKING_MB_PEAKING_CTRL_mb_peaking_en_mask);//_BIT0
			}
		break;
#ifdef ANDTV_PQ_COMPILE_FIX
		case PQ_ByPass_Fmd:
            		if(bEnable){
                		IoReg_SetBits(DI_IM_DI_CONTROL_reg, DI_IM_DI_CONTROL_reg_FMD_EN_MASK);//BIT14
            		}
            		else{
                		IoReg_ClearBits(DI_IM_DI_CONTROL_reg, DI_IM_DI_CONTROL_reg_FMD_EN_MASK);//BIT14
            		}
            break;
			case PQ_ByPass_ES:
            		if(bEnable){
                		IoReg_SetBits(DI_IM_DI_NINTRA_CONTROL_reg, DI_IM_DI_NINTRA_CONTROL_nintra_new_mode_en_mask);//_BIT1

            		}
            		else{
                		IoReg_ClearBits(DI_IM_DI_NINTRA_CONTROL_reg, DI_IM_DI_NINTRA_CONTROL_nintra_new_mode_en_mask);//_BIT1
            		}
        	break;
			case PQ_ByPass_CCCL:
            		if(bEnable){
                		IoReg_SetBits(VDPQ_YC_SEP_MODE_CTRL_reg,VDPQ_YC_SEP_MODE_CTRL_Fix2D_mask);//_BIT0
            		}
            		else{
                		IoReg_ClearBits(VDPQ_YC_SEP_MODE_CTRL_reg,VDPQ_YC_SEP_MODE_CTRL_Fix2D_mask );//_BIT0
            		}
        	break;
			case PQ_ByPass_DBC:
            		if(bEnable){
                		IoReg_SetBits(MPEGNR_ICH1_MPEGNR2_V_C_reg ,MPEGNR_ICH1_MPEGNR2_V_C_ENABLE_MASK );//_BIT1
            		}
            		else{
                		IoReg_ClearBits(MPEGNR_ICH1_MPEGNR2_V_C_reg,MPEGNR_ICH1_MPEGNR2_V_C_ENABLE_MASK );//_BIT1
            		}
        	break;
#endif

		/*===============D Domain===========*/
		/*Main*/
		case PQ_ByPass_USM:
			if(bEnable){
				IoReg_SetBits(SCALEUP_DM_USM_reg, SCALEUP_DM_USM_usm_en_mask);//_BIT0
			}
			else{
				IoReg_ClearBits(SCALEUP_DM_USM_reg, SCALEUP_DM_USM_usm_en_mask);//_BIT0
			}
		break;

		case PQ_ByPass_SU_Peaking:
			if(bEnable){
				IoReg_SetBits(SCALEUP_DM_UZU_Peaking_Coring_reg, SCALEUP_DM_UZU_Peaking_Coring_pk_en_mask);//_BIT16
			}
			else{
				IoReg_ClearBits(SCALEUP_DM_UZU_Peaking_Coring_reg, SCALEUP_DM_UZU_Peaking_Coring_pk_en_mask);//_BIT16
			}
		break;

		case PQ_ByPass_SHP_DLTI:
			if(bEnable){
				IoReg_SetBits(COLOR_SHARP_SHP_DLTI_CTRL_1_reg, COLOR_SHARP_SHP_DLTI_CTRL_1_dlti_en_mask);//_BIT0
			}
			else{
				IoReg_ClearBits(COLOR_SHARP_SHP_DLTI_CTRL_1_reg, COLOR_SHARP_SHP_DLTI_CTRL_1_dlti_en_mask);//_BIT0
			}
		break;

		case PQ_ByPass_DCC:
			if(bEnable){
				IoReg_SetBits(COLOR_D_VC_Global_CTRL_reg, COLOR_D_VC_Global_CTRL_dcc_en_mask);//_BIT0
			}
			else{
				IoReg_ClearBits(COLOR_D_VC_Global_CTRL_reg, COLOR_D_VC_Global_CTRL_dcc_en_mask);//_BIT0
			}
		break;

		case PQ_ByPass_DCTI:
			if(bEnable){
				IoReg_SetBits(COLOR_D_VC_Global_CTRL_reg, COLOR_D_VC_Global_CTRL_m_dcti_en_mask);//_BIT2
                IoReg_SetBits(COLOR_D_VC_Global_CTRL_DB_reg, COLOR_D_VC_Global_CTRL_DB_db_load_shift);//_BIT0
			}
			else{
				IoReg_ClearBits(COLOR_D_VC_Global_CTRL_reg, COLOR_D_VC_Global_CTRL_m_dcti_en_mask);//_BIT2
                IoReg_ClearBits(COLOR_D_VC_Global_CTRL_DB_reg, COLOR_D_VC_Global_CTRL_DB_db_load_shift);//_BIT0
			}
		break;

		case PQ_ByPass_ICM:
			if(bEnable){
				IoReg_SetBits(COLOR_D_VC_Global_CTRL_reg, COLOR_D_VC_Global_CTRL_m_icm_en_mask);//_BIT3
			}
			else{
				IoReg_ClearBits(COLOR_D_VC_Global_CTRL_reg, COLOR_D_VC_Global_CTRL_m_icm_en_mask);//_BIT3
			}
		break;

		case PQ_ByPass_SHP:
			if(bEnable){
				IoReg_SetBits(COLOR_D_VC_Global_CTRL_reg, COLOR_D_VC_Global_CTRL_m_sharp_en_mask);//_BIT4
			}
			else{
				IoReg_ClearBits(COLOR_D_VC_Global_CTRL_reg, COLOR_D_VC_Global_CTRL_m_sharp_en_mask);//_BIT4
			}
		break;

		case PQ_ByPass_Dedge_Smooth:
			if(bEnable){
				IoReg_SetBits(COLOR_D_VC_Global_CTRL_reg, COLOR_D_VC_Global_CTRL_m_edgesmooth_en_mask);//_BIT5
			}
			else{
				IoReg_ClearBits(COLOR_D_VC_Global_CTRL_reg, COLOR_D_VC_Global_CTRL_m_edgesmooth_en_mask);//_BIT5
			}
		break;

		case PQ_ByPass_CDS:
			if(bEnable){
				IoReg_SetBits(COLOR_SHARP_DM_CDS_CM0_U_BOUND_0_reg, COLOR_SHARP_DM_CDS_CM0_U_BOUND_0_cds_enable_mask);//_BIT27
			}
			else{
				IoReg_ClearBits(COLOR_SHARP_DM_CDS_CM0_U_BOUND_0_reg, COLOR_SHARP_DM_CDS_CM0_U_BOUND_0_cds_enable_mask);//_BIT27
			}
		break;

		case PQ_ByPass_UV_Offset:
			if(bEnable){
				IoReg_SetBits(YUV2RGB_D_UVOFFSETBYY_CONTROL_reg, YUV2RGB_D_UVOFFSETBYY_CONTROL_uvoffsetbyy_main_en_mask);//_BIT0
			}
			else{
				IoReg_ClearBits(YUV2RGB_D_UVOFFSETBYY_CONTROL_reg, YUV2RGB_D_UVOFFSETBYY_CONTROL_uvoffsetbyy_main_en_mask);//_BIT0
			}
		break;

		case PQ_ByPass_V_CTI:
			if(bEnable){
				IoReg_SetBits(SCALEUP_DM_MEM_CRC_CTRL_reg, SCALEUP_DM_MEM_CRC_CTRL_vcti_en_mask);//_BIT4
			}
			else{
				IoReg_ClearBits(SCALEUP_DM_MEM_CRC_CTRL_reg, SCALEUP_DM_MEM_CRC_CTRL_vcti_en_mask);//_BIT4
			}
		break;

		case PQ_ByPass_sRGB:
			if(bEnable){
				IoReg_SetBits(SRGB_sRGB_CTRL_reg, SRGB_sRGB_CTRL_srgb_m_tab_sel_mask);//_BIT0|_BIT1
			}
			else{
				IoReg_ClearBits(SRGB_sRGB_CTRL_reg, SRGB_sRGB_CTRL_srgb_m_tab_sel_mask);//_BIT0|_BIT1
			}
		break;

		case PQ_ByPass_Gamma:
			if(bEnable){
				IoReg_SetBits(GAMMA_GAMMA_CTRL_2_reg, GAMMA_GAMMA_CTRL_2_gamma_m_tab_sel_mask);//_BIT6|_BIT7
			}
			else{
				IoReg_ClearBits(GAMMA_GAMMA_CTRL_2_reg, GAMMA_GAMMA_CTRL_2_gamma_m_tab_sel_mask);//_BIT6|_BIT7
			}
		break;

		case PQ_ByPass_InvGamma:
			if(bEnable){
				IoReg_SetBits(INV_GAMMA_INV_GAMMA_CTRL_2_reg, INV_GAMMA_INV_GAMMA_CTRL_2_inv_gamma_m_tab_sel_mask);//_BIT6|_BIT7
			}
			else{
				IoReg_ClearBits(INV_GAMMA_INV_GAMMA_CTRL_2_reg, INV_GAMMA_INV_GAMMA_CTRL_2_inv_gamma_m_tab_sel_mask);//_BIT6|_BIT7
			}
		break;


		case PQ_ByPass_DITHER:
			if(bEnable){
				IoReg_SetBits(DITHER_DITHERING_CTRL_reg, DITHER_DITHERING_CTRL_function_enable_mask);//_BIT5
			}
			else{
				IoReg_ClearBits(DITHER_DITHERING_CTRL_reg, DITHER_DITHERING_CTRL_function_enable_mask);//_BIT5
			}
		break;

		case PQ_ByPass_DITHER_Temporal:
			if(bEnable){
				IoReg_SetBits(DITHER_DITHERING_CTRL_reg, DITHER_DITHERING_CTRL_temporal_enable_mask);//_BIT4
			}
			else{
				IoReg_ClearBits(DITHER_DITHERING_CTRL_reg, DITHER_DITHERING_CTRL_temporal_enable_mask);//_BIT4
			}
		break;
#ifdef ANDTV_PQ_COMPILE_FIX
		case PQ_ByPass_COLOR_CORING:
            	if(bEnable){
                		IoReg_SetBits(COLOR_D_VC_Global_CTRL_ICM_UVCoring_reg,COLOR_D_VC_Global_CTRL_ICM_UVCoring_enable_mask );
            		}
            	else{
                		IoReg_ClearBits(COLOR_D_VC_Global_CTRL_ICM_UVCoring_reg,COLOR_D_VC_Global_CTRL_ICM_UVCoring_enable_mask );
            		}
        	break;
#endif

			/* new */
		case PQ_ByPass_I_DI_IP_Enable:
				if(bEnable){
				IoReg_SetBits(DI_IM_DI_CONTROL_reg, DI_IM_DI_CONTROL_ip_enable_mask);//_BIT28
				//IoReg_SetBits(VGIP_Data_Path_Select_reg, VGIP_Data_Path_Select_uzd1_in_sel_mask);	/*path need to change while IP disable*/
				//IoReg_SetBits(DI_db_reg_ctl_reg, DI_db_reg_ctl_db_apply_mask);	/* HW do not clear this bit, alway turn on, setting will be apply while v_sync*/
				//IoReg_SetBits(VGIP_VGIP_CHN1_ACT_HSTA_Width_reg, VGIP_VGIP_CHN1_ACT_HSTA_Width_ch1_db_rdy_mask);
			}
			else{
				IoReg_ClearBits(DI_IM_DI_CONTROL_reg, DI_IM_DI_CONTROL_ip_enable_mask);//_BIT28
				//IoReg_ClearBits(VGIP_Data_Path_Select_reg, VGIP_Data_Path_Select_uzd1_in_sel_mask);	/*path need to change while IP disable*/
				//IoReg_SetBits(DI_db_reg_ctl_reg, DI_db_reg_ctl_db_apply_mask);	/* HW do not clear this bit, alway turn on, setting will be apply while v_sync*/
				//IoReg_SetBits(VGIP_VGIP_CHN1_ACT_HSTA_Width_reg, VGIP_VGIP_CHN1_ACT_HSTA_Width_ch1_db_rdy_mask);
			}
		break;
	}

	return 0;
}

short drvif_DM2_EOTF_OETF_3DLUT_DMA_Err_Check(void)
{
	short ret_val = 0;
	short err_TBL[4] = {0};

	err_TBL[0] = DMATO3DTABLE_DMAto3DTable_Table0_ErrStatus2Irq_get_table0_err_status(IoReg_Read32(DMATO3DTABLE_DMAto3DTable_Table0_ErrStatus2Irq_reg));
	err_TBL[1] = DMATO3DTABLE_DMAto3DTable_Table1_ErrStatus2Irq_get_table1_err_status(IoReg_Read32(DMATO3DTABLE_DMAto3DTable_Table1_ErrStatus2Irq_reg));
	err_TBL[2] = DMATO3DTABLE_DMAto3DTable_Table2_ErrStatus2Irq_get_table2_err_status(IoReg_Read32(DMATO3DTABLE_DMAto3DTable_Table2_ErrStatus2Irq_reg));
	err_TBL[3] = DMATO3DTABLE_DMAto3DTable_Table3_ErrStatus2Irq_get_table3_err_status(IoReg_Read32(DMATO3DTABLE_DMAto3DTable_Table3_ErrStatus2Irq_reg));

	if (err_TBL[0]  != 0)
		ret_val = ret_val | _BIT0;

	if (err_TBL[1]  != 0)
		ret_val = ret_val | _BIT1;

	if (err_TBL[2]  != 0)
		ret_val = ret_val | _BIT2;

	if (err_TBL[3]  != 0)
		ret_val = ret_val | _BIT3;

	return ret_val;
}

void drvif_DM2_EOTF_OETF_3DLUT_DMA_Err_Reset(void)
{
	IoReg_Write32(DMATO3DTABLE_DMAto3DTable_Table0_ErrStatus2Irq_reg, IoReg_Read32(DMATO3DTABLE_DMAto3DTable_Table0_ErrStatus2Irq_reg) | DMATO3DTABLE_DMAto3DTable_Table0_ErrStatus2Irq_table0_err_status_mask);
	IoReg_Write32(DMATO3DTABLE_DMAto3DTable_Table1_ErrStatus2Irq_reg, IoReg_Read32(DMATO3DTABLE_DMAto3DTable_Table1_ErrStatus2Irq_reg) | DMATO3DTABLE_DMAto3DTable_Table1_ErrStatus2Irq_table1_err_status_mask);
	IoReg_Write32(DMATO3DTABLE_DMAto3DTable_Table2_ErrStatus2Irq_reg, IoReg_Read32(DMATO3DTABLE_DMAto3DTable_Table2_ErrStatus2Irq_reg) | DMATO3DTABLE_DMAto3DTable_Table2_ErrStatus2Irq_table2_err_status_mask);
	IoReg_Write32(DMATO3DTABLE_DMAto3DTable_Table3_ErrStatus2Irq_reg, IoReg_Read32(DMATO3DTABLE_DMAto3DTable_Table3_ErrStatus2Irq_reg) | DMATO3DTABLE_DMAto3DTable_Table3_ErrStatus2Irq_table3_err_status_mask);
}


