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

/*============================ Module dependency  ===========================*/
#if CONFIG_FIRMWARE_IN_KERNEL
//#include <mach/io.h>
//#include <rbus/scaler/rbusPpOverlayReg.h>
#include <rbus/ppoverlay_reg.h>

#include <tvscalercontrol/io/ioregdrv.h>

#include <tvscalercontrol/scaler/scalerstruct.h>
#include <tvscalercontrol/scalerdrv/mode.h>
#include <tvscalercontrol/scaler/source.h>
#include <tvscalercontrol/scalerdrv/scalerdrv.h>
#include <tvscalercontrol/scalerdrv/scalermemory.h>
#include <tvscalercontrol/vip/vip_reg_def.h>

#include <tvscalercontrol/vip/di_ma.h>
#include <tvscalercontrol/vip/ultrazoom.h>
#include <tvscalercontrol/panel/panelapi.h>

/* oliver+*/
#include <scalercommon/scalerDrvCommon.h>
#include <tvscalercontrol/scaler/scalercolorlib.h>
#include <mach/rtk_log.h>
#define TAG_NAME "VPQ"

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

#include <unistd.h>			// 'close()'
#include <fcntl.h>			// 'open()'
#include <stdio.h>
//#include <sys/ioctl.h>
#include <string.h>

//#include "rtd_regs.h"
#include <Platform_Lib/TVScalerControl/io/ioRegDrv.h>
//#include <Application/AppClass/TvControl/Utils/RtSystem.h>
#include <Platform_Lib/TVScalerControl/scaler/scalerStruct.h>
#include <Platform_Lib/TVScalerControl/scalerDrv/mode.h>
#include <Platform_Lib/TVScalerControl/scaler/source.h>
#include <Platform_Lib/TVScalerControl/scalerDrv/scalerDrv.h>
#include <Platform_Lib/TVScalerControl/scalerDrv/scalerMemory.h>
#include <Platform_Lib/TVScalerControl/vip/VIP_reg_def.h>
#include <Platform_Lib/TVScalerControl/vip/color.h>
#include <Platform_Lib/TVScalerControl/vip/dcc.h>
#include <Platform_Lib/TVScalerControl/vip/di_ma.h>
#include <Platform_Lib/TVScalerControl/vip/ypbpr_auto.h>
#include <Platform_Lib/TVScalerControl/vip/peaking.h>
#include <Platform_Lib/TVScalerControl/vip/ultrazoom.h>
#include <Platform_Lib/panel/panelAPI.h>
//#include "rtd_struct.h" // nick187
#include <rbusVgipReg.h>
//#include <rbusPpOverlayReg.h>
#include <ppoverlay_reg.h>


// oliver+
#include <scaler/scalerDrvCommon.h>
#include <Platform_Lib/TVScalerControl/scaler/scalerLib.h>
#include <Platform_Lib/TVScalerControl/scaler/scalerColorLib.h>

#if 1//defined(PQ_DUMPDIDATA)
#include <Platform_Lib/MoveDataEngine/md_api.h>//yuan::add for Dump Di
#include <OSAL/PLI.h>//yuan::add for Dump Di
#include <Platform_Lib/TVScalerControl/scalerDrv/scalerMemory.h>
#endif

//#include "osdcore.h"
#endif

#if CONFIG_FIRMWARE_IN_KERNEL
#define VIPprintf(fmt, args...)	rtd_printk(KERN_DEBUG, TAG_NAME, fmt, ##args)//printk(KERN_DEBUG fmt, ##args)
#else
#define VIPprintf(fmt, args...)	printf(fmt, ##args)
#define msleep(x)							((void)0)
#endif

/*================================ Definitions ==============================*/


/*===================================  Types ================================*/

/*================================== Variables ==============================*/

/*forster modified 061219*/
/*
unsigned char tMA_Init_Main[28] = {0x4, 0x0, 0xff, 0x2,

					0x18, 0x0, 0x64, 0x22, 0x45, 0x2, 0xf, 0xf, 0x2, 0xa, 0xa, 0x14, 0x14, 0xc, 0x6,
					0xa, 0x14, 0x18, 0x10, 0x14, 0x32, 0x14, 0x96, 0x0f, 0};
unsigned char tMA_Init_Sub[28] = {0x4, 0x0, 0xff, 0xa,
					0x17, 0x0, 0x64, 0x22, 0x45, 0x2, 0xf, 0xf, 0x2, 0xa, 0xa, 0x14, 0x14, 0xc, 0x6,
					0xa, 0x14, 0x18, 0x10, 0x14, 0x32, 0x14, 0x96, 0};


unsigned char tMA_Init_Main[29] = {0x4, 0x0, 0xff, 0x2,
					0x18 <<24 |0x0<<16, 0x64, 0x22,
					0x45, 0x2, 0xf, 0xf, 0x2, 0xa, 0xa, 0x14, 0x14, 0xc, 0x6,
					0xa, 0x14, 0x18, 0x10, 0x14, 0x32, 0x14, 0x96, 0x0f, 0};
unsigned char tMA_Init_Sub[28] = {0x4, 0x0, 0xff, 0xa,
					0x17, 0x0, 0x64, 0x22, 0x45, 0x2, 0xf, 0xf, 0x2, 0xa, 0xa, 0x14, 0x14, 0xc, 0x6,
					0xa, 0x14, 0x18, 0x10, 0x14, 0x32, 0x14, 0x96, 0};
*/



#if defined(CONFIG_CUSTOMER_REALTEK)
static unsigned int DarkSum1;
static unsigned int BritSum1;
static unsigned int TotalSum1;
#endif

static unsigned char bTemporalEnable;
static unsigned char bRTNRYEn;
static unsigned char bRTNRCEn;
static unsigned char bRTNRXCEn;
static unsigned char bPseudoMEMCEn;




/* Sirius new ip by LearnRPG@20131218*/

UINT8 ZOOM_MOTION_LEVEL[] = {0, 0, 0, 0, 0, 0}; /* how many mode or timeing for level*/
			/* M       H          RLV      S */
UINT8 ZOOM_MOTION_TH[LEVEL][4][3] = {
	{{2, 4, 6}, {2, 4, 6}, {2, 4, 6}, {2, 4, 6} },
	{{3, 5, 6}, {3, 4, 6}, {2, 4, 6}, {2, 5, 6} },
	{{4, 6, 6}, {4, 4, 6}, {2, 4, 6}, {2, 6, 6} },
	{{5, 7, 6}, {5, 4, 6}, {2, 4, 6}, {2, 7, 6} },
	{{6, 8, 6}, {6, 4, 6}, {2, 4, 6}, {2, 8, 6} },
	{{7, 9, 6}, {7, 4, 6}, {2, 4, 6}, {2, 9, 6} }
	};

UINT8 SLOW_MOTION_LEVEL[] = {0, 0, 0, 0, 0, 0}; /* how many mode or timeing for level*/
			/* M       H          RLV      S */
UINT8 SLOW_MOTION_TH[LEVEL][4][3] = {
	{{2, 4, 6}, {2, 4, 6}, {2, 4, 6}, {2, 4, 6} },
	{{3, 5, 6}, {3, 4, 6}, {2, 4, 6}, {2, 5, 6} },
	{{4, 6, 6}, {4, 4, 6}, {2, 4, 6}, {2, 6, 6} },
	{{5, 7, 6}, {5, 4, 6}, {2, 4, 6}, {2, 7, 6} },
	{{6, 8, 6}, {6, 4, 6}, {2, 4, 6}, {2, 8, 6} },
	{{7, 9, 6}, {7, 4, 6}, {2, 4, 6}, {2, 9, 6} }
	};

/*0: adaptive th en
   1: adaptive th bias
   2: adaptive th clip en
   3: adaptive th min clip
   4: adaptive th max clip
   5: mv reifne en
   6: even mv no vectorteeth
   7: odd mv no compesation
   8: hme sobel search min
   9: hme sum max ratio
   A: hme max absolute count
   B: hme x continued counter
   C: hme line ratio
*/
UINT8 HMC_TABLE[LEVEL][13] =	{{1, 16, 1, 1, 16, 1, 1, 1, 4, 2, 0, 0, 2},
				{1, 16, 1, 1, 16, 1, 1, 1, 4, 2, 0, 0, 4},
				{1, 16, 1, 1, 16, 1, 1, 1, 4, 2, 0, 0, 6},
				{1, 16, 1, 1, 16, 1, 1, 1, 4, 2, 0, 0, 8},
				{1, 16, 1, 1, 16, 1, 1, 1, 4, 2, 0, 0, 10},
				{1, 16, 1, 1, 16, 1, 1, 1, 4, 2, 0, 0, 12} };


/*static StructColorDataType *stColorData = NULL; */ /* marked by hsliao 20090316*/

#if 0
void MA_AutoThreshold(unsigned char NoiseLevelSpatial)
{

	unsigned int	TotalFrameMotionSum = 0;
	unsigned int 	LargeFrameMotionSum = 0;
	unsigned int 	LargeFrameMotionPixel = 0;
	unsigned int 	SmallFrameMotionPixel = 0;
	unsigned int 	MessHoriPixel = 0;
	unsigned int 	StatusFrameDiffSum_C = 0;
	unsigned int 	StatusFrameDiffSum = 0;
	unsigned char 	Mode = 0;
	unsigned char 	array[256] = {0};

	NoiseLevelSpatial = 0;
	Rspi_WriteByte(_P2_94_, 0x00);
	Rspi_Read(_P2_99_, 12, 1, array);

	TotalFrameMotionSum = (array[0]<<16)+(array[1]<<8)+array[2];
	LargeFrameMotionSum = (array[3]<<16)+(array[4]<<8)+array[5];
	LargeFrameMotionPixel = (array[6]<<16)+(array[7]<<8)+array[8];
	MessHoriPixel = (array[9]<<16)+(array[10]<<8)+array[11];
	SmallFrameMotionPixel = TotalFrameMotionSum-LargeFrameMotionSum;

	RTD_Log(LOGGER_INFO, "TotalFrameMotionSum = %d\n", TotalFrameMotionSum);
	RTD_Log(LOGGER_INFO, "LargeFrameMotionSum = %d\n", LargeFrameMotionSum);
	RTD_Log(LOGGER_INFO, "LargeFrameMotionPixel = %d\n", LargeFrameMotionPixel);
	RTD_Log(LOGGER_INFO, "SmallFrameMotionPixel = %d\n", SmallFrameMotionPixel);
	RTD_Log(LOGGER_INFO, "MessHoriPixel = %d\n", MessHoriPixel);

	Rspi_WriteByte(_P2_91_, 0x24);
	Rspi_Read(_P2_99_, 27, 1, array);

	StatusFrameDiffSum_C = (array[0]<<16)+(array[1]<<8)+array[2];
	StatusFrameDiffSum = (array[24]<<16)+(array[25]<<8)+array[26];
	RTD_Log(LOGGER_INFO, "StatusFrameDiffSum_C = %d\n", StatusFrameDiffSum_C);
	RTD_Log(LOGGER_INFO, "StatusFrameDiffSum = %d\n", StatusFrameDiffSum);

	if ((LargeFrameMotionPixel+SmallFrameMotionPixel) > 130000 &&
		(LargeFrameMotionPixel*4 < SmallFrameMotionPixel*3) &&
		SmallFrameMotionPixel > 80000 && NoiseLevelSpatial > 5) {
		Mode = 5;
	} else if (LargeFrameMotionPixel < SmallFrameMotionPixel &&
		SmallFrameMotionPixel > 20000 && StatusFrameDiffSum_C < 5120) {
		if (SmallFrameMotionPixel < 35000)
			Mode = 1;
		else if (SmallFrameMotionPixel < 75000)
			Mode = 2;
		else if (SmallFrameMotionPixel < 110000)
			Mode = 3;
		else
			Mode = 4;
	}

	if ((Mode == 4 && StatusFrameDiffSum_C < 5120) ||
		LargeFrameMotionSum*3 < TotalFrameMotionSum && Mode < 5) {
		Rspi_WriteByte(_P2_64_, 0x88);/*smooth a, RLV a*/
		Rspi_WriteByte(_P2_65_, 0xa8);/*hori a, mess a*/
		Rspi_WriteByte(_P2_66_, 0xf);/*teeth a RLV*/
		Rspi_WriteByte(_P2_69_, 0xf);/*teeth a Smooth*/
		Rspi_WriteByte(_P2_6A_, 0xff);/*Sawtooth a Smooth*/
		Rspi_WriteByte(_P2_6B_, 0xff);/*Sawtooth a RLV*/
	} else if (Mode == 4)
		Mode = 3;

	if (Mode == 1) {
		Rspi_WriteByte(_P2_64_, 0x23);/*smooth a, RLV a*/
		Rspi_WriteByte(_P2_65_, 0x56);/*hori a, mess a*/
	} else if (Mode == 2) {
		Rspi_WriteByte(_P2_64_, 0x33);/*smooth a, RLV a*/
		Rspi_WriteByte(_P2_65_, 0x68);/*hori a, mess a*/
	} else if (Mode == 3) {
		Rspi_WriteByte(_P2_64_, 0x34);/*smooth a, RLV a*/
		Rspi_WriteByte(_P2_65_, 0x78);/*hori a, mess a*/
	}

	if (MessHoriPixel > 50000 && StatusFrameDiffSum_C < 5120 &&
		LargeFrameMotionPixel < SmallFrameMotionPixel) {
		Rspi_WriteByte(_P2_68_, 0xf);/*teeth mess a*/
		Rspi_WriteByte(_P2_67_, 0x14);/*teeth Horizontal a*/

		if (NoiseLevelSpatial > 5)
			Rspi_WriteByte(_P2_69_, 0x14);/*teeth a Smooth*/

		Rspi_WriteByte(_P2_66_, 0x14);/*teeth a RLV*/
		Rspi_WriteByte(_P2_6C_, 0xff);/*Sawtooth Horizontal*/

		if (MessHoriPixel > 90000 && NoiseLevelSpatial > 5) {
			Rspi_WriteByte(_P2_6A_, 0xff);/*Sawtooth a Smooth*/
			Rspi_WriteByte(_P2_6B_, 0xff);/*Sawtooth a RLV*/
			Rspi_WriteByte(_P2_6D_, 0xff);/*Sawtooth a Mess*/
		} else if (MessHoriPixel > 60000 && NoiseLevelSpatial > 5)
			Rspi_WriteByte(_P2_6D_, 0xff);/*Sawtooth a Mess*/

	}
	if (Mode == 5) {
		Rspi_WriteByte(_P2_64_, 0xff);/*smooth a, RLV a*/
		Rspi_WriteByte(_P2_65_, 0xff);/*hori a, mess a*/

		Rspi_WriteByte(_P2_68_, 0x14);/*teeth mess a*/
		Rspi_WriteByte(_P2_67_, 0x14);/*teeth Horizontal a*/
		Rspi_WriteByte(_P2_66_, 0x14);/*teeth a RLV*/
		Rspi_WriteByte(_P2_69_, 0x14);/*teeth a Smooth*/

		Rspi_WriteByte(_P2_6A_, 0xff);/*Sawtooth a Smooth*/
		Rspi_WriteByte(_P2_6B_, 0xff);/*Sawtooth a RLV*/
		Rspi_WriteByte(_P2_6C_, 0xff);/*Sawtooth Horizontal*/
		Rspi_WriteByte(_P2_6D_, 0xff);/*Sawtooth a Mess*/
	}

}
#endif

#if 0

/*
	access	5A => 1
		3A => 0
	bit     10 bit => 1
		8  bit => 0
*/

void DI_SetMemoryMain(unsigned short height, unsigned short width, unsigned char access, unsigned char bit)
{
	unsigned int	value, tmp;
	unsigned char	bitNum;

	/*Main*/
	value = Rspi_ReadByte(_D1_CH_DATA_FORMAT);
	Rspi_WriteByte(_D1_CH_DATA_FORMAT, value&0xfb);

	RTD_Log(LOGGER_INFO, "\n Deinterlace height = %x", height);
	RTD_Log(LOGGER_INFO, "\n Deinterlace width = %x", width);


	if (access) { /* 3 */ /* 5A */
		if (bit) { /* 10 bits */
			value = Rspi_ReadByte(_D1_CH_DATA_FORMAT);
			Rspi_WriteByte(_D1_CH_DATA_FORMAT, value|0x2);/*main 10 bits*/
			bitNum = 20;
		} else { /* 8 bits */
			value = Rspi_ReadByte(_D1_CH_DATA_FORMAT);
			Rspi_WriteByte(_D1_CH_DATA_FORMAT, value&0xfd);/*main 8 bits*/
			bitNum = 16;
		}
		/*Number, Remain*/
		value = (height*width*bitNum)>>13; /*(64*128)*/
		tmp = ((height*width*bitNum)-(value<<13))>>6;/*64*/
		if (tmp == 0) { /* remain can't be zero */
			value -= 1;
			tmp = 0x80;
		}
		RTD_Log(LOGGER_INFO, "\nDi Memory value = %x", value);

		Rspi_WriteByte(_P3_36_DDR_VFIFORDWRNUM_MSB, value>>8);
		Rspi_WriteByte(_P3_37_DDR_VFIFORDWRNUM_LSB, value&0xff);
		/*value = ((height*width*bitNum)-(value<<13))>>6;*/ /*64*/
		/*Rspi_WriteByte(_P3_38_DDR_VFIFORDWR_REMAINDER, value);*/
		Rspi_WriteByte(_P3_38_DDR_VFIFORDWR_REMAINDER, tmp);

		value = (height*width*bitNum)>>5;/*(32)*/
		tmp = value;
		Rspi_WriteByte(_P3_30_DDR_VFIFO_SELECT, 0x1);
		Rspi_WriteByte(_P3_31_DDR_VMEM_VADDRMSB, value>>16);
		Rspi_WriteByte(_P3_32_DDR_VMEM_VADDRMID, (value>>8)&0xff);
		Rspi_WriteByte(_P3_33_DDR_VMEM_VADDRLSB, value&0xff);

		value = value+tmp;
		Rspi_WriteByte(_P3_30_DDR_VFIFO_SELECT, 0x2);
		Rspi_WriteByte(_P3_31_DDR_VMEM_VADDRMSB, value>>16);
		Rspi_WriteByte(_P3_32_DDR_VMEM_VADDRMID, (value>>8)&0xff);
		Rspi_WriteByte(_P3_33_DDR_VMEM_VADDRLSB, value&0xff);

		value = value+tmp;
		Rspi_WriteByte(_P3_30_DDR_VFIFO_SELECT, 0x3);
		Rspi_WriteByte(_P3_31_DDR_VMEM_VADDRMSB, value>>16);
		Rspi_WriteByte(_P3_32_DDR_VMEM_VADDRMID, (value>>8)&0xff);
		Rspi_WriteByte(_P3_33_DDR_VMEM_VADDRLSB, value&0xff);
	/*	Rspi_ClearBits(_P2_12_, _BIT2);*/
	} else { /* 3 */ /* 3A */
		if (bit) { /* 10 bits */
			value = Rspi_ReadByte(_D1_CH_DATA_FORMAT);
			Rspi_WriteByte(_D1_CH_DATA_FORMAT, value|0x2);/*main 10 bits*/
			bitNum = 24;
		} else { /* 8 bits */
			value = Rspi_ReadByte(_D1_CH_DATA_FORMAT);
			Rspi_WriteByte(_D1_CH_DATA_FORMAT, value&0xfd);/*main 8 bits*/
			bitNum = 20;
		}
		/*Number, Remain*/
		value = (height*width*bitNum)>>13; /*(64*128)*/
		tmp = ((height*width*bitNum)-(value<<13))>>6;/*64*/
		if (tmp == 0) {
		      value -= 1;
		      tmp = 0x80;
		}
		Rspi_WriteByte(_P3_36_DDR_VFIFORDWRNUM_MSB, value>>8);
		Rspi_WriteByte(_P3_37_DDR_VFIFORDWRNUM_LSB, value&0xff);
		/*value = ((height*width*bitNum)-(value<<13))>>6;*/ /*64*/
		/*Rspi_WriteByte(_P3_38_DDR_VFIFORDWR_REMAINDER, value);*/
		Rspi_WriteByte(_P3_38_DDR_VFIFORDWR_REMAINDER, tmp);

		value = (height*width*bitNum)>>5;/*(32)*/
		Rspi_WriteByte(_P3_30_DDR_VFIFO_SELECT, 0x1);
		Rspi_WriteByte(_P3_31_DDR_VMEM_VADDRMSB, value>>16);
		Rspi_WriteByte(_P3_32_DDR_VMEM_VADDRMID, (value>>8)&0xff);
		Rspi_WriteByte(_P3_33_DDR_VMEM_VADDRLSB, value&0xff);
	/*	Rspi_SetBits(_P2_12_, _BIT2);*/
	}
}

void DI_SetMemorySub(unsigned short height, unsigned short width, unsigned char bit)
{
	unsigned int	value;
	unsigned int	StartAddr = 0;
	unsigned char	bitNum;

	if (bit) { /* 10 bits */
		value = Rspi_ReadByte(_D1_CH_DATA_FORMAT);
		Rspi_WriteByte(_D1_CH_DATA_FORMAT, value|0x1);/*main 10 bits*/
		bitNum = 24;
	} else { /* 8 bits */
		value = Rspi_ReadByte(_D1_CH_DATA_FORMAT);
		Rspi_WriteByte(_D1_CH_DATA_FORMAT, value&0xfe);/*main 8 bits*/
		bitNum = 20;
	}
	/*Sub*/
	value = Rspi_ReadByte(_D1_CH_DATA_FORMAT);
	Rspi_WriteByte(_D1_CH_DATA_FORMAT, value|0x4);
	/*Number, Remain*/
	value = (height*width*bitNum)>>13; /*(64*128)*/
	Rspi_WriteByte(_P3_36_DDR_VFIFORDWRNUM_MSB, value>>8);
	Rspi_WriteByte(_P3_37_DDR_VFIFORDWRNUM_LSB, value&0xff);
	value = ((height*width*bitNum)-(value<<13))>>6;/*64*/
	Rspi_WriteByte(_P3_38_DDR_VFIFORDWR_REMAINDER, value);

	Rspi_WriteByte(_P3_30_DDR_VFIFO_SELECT, 0x4);
	Rspi_WriteByte(_P3_31_DDR_VMEM_VADDRMSB, StartAddr>>16);
	Rspi_WriteByte(_P3_32_DDR_VMEM_VADDRMID, (StartAddr>>8)&0xff);
	Rspi_WriteByte(_P3_33_DDR_VMEM_VADDRLSB, StartAddr&0xff);

	value = (height*width*bitNum)>>5;/*(32)*/
	value = value+StartAddr;
	Rspi_WriteByte(_P3_30_DDR_VFIFO_SELECT, 0x5);
	Rspi_WriteByte(_P3_31_DDR_VMEM_VADDRMSB, value>>16);
	Rspi_WriteByte(_P3_32_DDR_VMEM_VADDRMID, (value>>8)&0xff);
	Rspi_WriteByte(_P3_33_DDR_VMEM_VADDRLSB, value&0xff);
}
#endif
/*		reg1806100c_Reg.hsize = info->CapWid;*/ /* Width;*/
/*		reg1806100c_Reg.vsize = info->IPV_ACT_LEN; */ /* Height;*/
/*		info->ucMode_Curr == _MODE_576I*/


/*#define IoReg_Read32(regtype, offset)		(*(volatile regtype *)(offset))*/



void drvif_color_StillLineCntns(unsigned char ch, unsigned char level)
{
	if (ch != SLR_MAIN_DISPLAY) /*sub:empty function*/
		return;
	else {
		di_im_di_intra_sobel_motion_th_RBUS Intra_SobelDetector_MotionThl_reg;
		Intra_SobelDetector_MotionThl_reg.regValue = IoReg_Read32(DI_IM_DI_INTRA_SOBEL_MOTION_TH_reg);

		if (level != 0) {
			/*level limit*/
			level = (level >= 5) ? 5 : level;

			/*setting*/
			Intra_SobelDetector_MotionThl_reg.stilllinecntns_apply_hmc_window = 1;
			Intra_SobelDetector_MotionThl_reg.stilllinecntns_window_mode = 1; /*0:one line mode , 1:two line mode*/
			Intra_SobelDetector_MotionThl_reg.stilllinecntns_window = 2 + level;

			/*threshold*/
			Intra_SobelDetector_MotionThl_reg.stilllinecntns_cond_th = 3;/*time domain cnt th*/
			Intra_SobelDetector_MotionThl_reg.stilllinecntns_window_th = 1;/*large value decrease the effect*/

			/*enable*/
			Intra_SobelDetector_MotionThl_reg.stillline_cntns_en = 1;
		} else
			Intra_SobelDetector_MotionThl_reg.stillline_cntns_en = 0;

		IoReg_Write32(DI_IM_DI_INTRA_SOBEL_MOTION_TH_reg, Intra_SobelDetector_MotionThl_reg.regValue);
	}


}



void drvif_color_ma_init() /* when turning on auto MA (OSD)*/
{
	/*Deinterlace only Main*/
	/* Thur modified 20090114
	DI_Control_Register_RBUS reg18061000_Reg;
	Frame_Motion_Detector_Threshold_A_RBUS reg18061080_Reg;
	Frame_Motion_Detector_Threshold_B_RBUS reg18061084_Reg;
	Frame_Motion_Detector_Threshold_C_RBUS reg18061088_Reg;
	Field_Teeth_Detector_Threshold_A_RBUS reg1806108c_Reg;
	Field_Teeth_Detector_Threshold_B_and_Anti_CC_and_Still_Logo_RBUS reg18061090_Reg;
	Sawtooth__Threshold_RBUS reg18061094_Reg;
	Compensation_Threshold_A_RBUS reg18061098_Reg;
	Compensation_Threshold_B_RBUS reg1806109c_Reg;
	*/
	histogram_ich1_hist_in_cselect_RBUS		ich1_hist_in_cselect_reg;

	Scaler_SetMADI_INIT();


	/* LearnRPG new algo on LV*/
	drvif_color_ma_HFD(1);
	drvif_color_ma_TeethCheck(0);

	ich1_hist_in_cselect_reg.regValue = IoReg_Read32(HISTOGRAM_ICH1_Hist_IN_CSELECT_reg);
	ich1_hist_in_cselect_reg.ch1_his_updatelockmode_en = 0;/*disable for histogram lock, 20130314, CSFC*/
	IoReg_Write32(HISTOGRAM_ICH1_Hist_IN_CSELECT_reg, ich1_hist_in_cselect_reg.regValue);

	VIPprintf("Diane--drvif_color_ma_init\n");

	drvif_color_ma_BTR(1);

	#if defined(PQ_TV005_Style) /* TSB style : do not use pan detection*/
	drvif_color_ma_Pan_Detection(0);
	#else
	drvif_color_ma_Pan_Detection(1);
	#endif
	drvif_color_ma_Pan_Detection(1);

	Scaler_SetMADI_HME(6);
	Scaler_SetMADI_HMC(6);

	Scaler_SetMA_Chroma_Error(1);

	drvif_color_ZOOM_MOTION_En(0);
	drvif_color_ZOOM_MOTION_Level(1);
	/*vif_color_ZOOM_MOTION_En(1);*/
	drvif_color_SLOW_MOTION_Level(2);
	/*vif_color_SLOW_MOTION_En(1);*/
}


/* Erin add for AT 100409*/
void drvif_color_ma_auto_init_1()/* when turning off AutoMA1_Enable (OSD)*/
{

}

void drvif_color_ma_auto_init_2()/* when turning off AutoMA2_Enable (OSD)*/
{

}

void drvif_color_ma_auto_init_3()/* when turning off AutoMA3_Enable (OSD)*/
{

}

void drvif_color_ma_auto_init_4()/* when turning off AutoMA4_Enable (OSD)*/
{

}

/* End Erin add for AT 100409*/


/**
 * Set auto MA threshold ??
 *
 * @param	Level: degree of auto MA level
 * @return	void
 */

void drvif_color_ma_set_DI_MA_Adjust_Table(DRV_di_ma_adjust_table *ptr)
{
	di_im_di_control_RBUS di_control_reg;
	di_im_di_ma_frame_motion_th_a_RBUS motion_detect_th_a_reg;
	di_im_di_ma_frame_motion_th_b_RBUS motion_detect_th_b_reg;
	di_im_di_ma_frame_motion_th_c_RBUS motion_detect_th_c_reg;
	di_im_di_ma_field_teeth_th_a_RBUS teeth_detect_th_a_reg;

	/* Read from register*/
	di_control_reg.regValue = IoReg_Read32(DI_IM_DI_CONTROL_reg);
	motion_detect_th_a_reg.regValue = IoReg_Read32(DI_IM_DI_MA_FRAME_MOTION_TH_A_reg);
	motion_detect_th_b_reg.regValue = IoReg_Read32(DI_IM_DI_MA_FRAME_MOTION_TH_B_reg);
	motion_detect_th_c_reg.regValue = IoReg_Read32(DI_IM_DI_MA_FRAME_MOTION_TH_C_reg);
	teeth_detect_th_a_reg.regValue = IoReg_Read32(DI_IM_DI_MA_FIELD_TEETH_TH_A_reg);

	/* Set DI MA Control Parameters*/
	di_control_reg.ma_controlmode = ptr->di_ma_control.ma_controlmode; // write_enable 0 [2]
	di_control_reg.ma_stilllogoena = ptr->di_ma_control.ma_stilllogoena; // write_enable 2[8]
	di_control_reg.ma_messintra90 = ptr->di_ma_control.ma_messintra90; // write_enable 3[6]
	di_control_reg.ma_smoothintra90 = ptr->di_ma_control.ma_smoothintra90;

	/* henry @ mac5 161219 DI write enable bit */
	//di_control_reg.regValue = di_control_reg.regValue | DI_IM_DI_CONTROL_write_enable_0_mask | DI_IM_DI_CONTROL_write_enable_2_mask | DI_IM_DI_CONTROL_write_enable_3_mask;
	di_control_reg.write_enable_0 = 1;
	di_control_reg.write_enable_2 = 1;
	di_control_reg.write_enable_3 = 1;

	/* Set Frame Motion*/
	motion_detect_th_a_reg.ma_framehtha = ptr->di_ma_frame_motion_th.ma_framehtha;
	motion_detect_th_a_reg.ma_framemtha = ptr->di_ma_frame_motion_th.ma_framemtha;
	motion_detect_th_a_reg.ma_framerlvtha = ptr->di_ma_frame_motion_th.ma_framerlvtha;
	motion_detect_th_a_reg.ma_framestha = ptr->di_ma_frame_motion_th.ma_framestha;

	motion_detect_th_b_reg.ma_framehthb = ptr->di_ma_frame_motion_th.ma_framehthb;
	motion_detect_th_b_reg.ma_framemthb = ptr->di_ma_frame_motion_th.ma_framemthb;
	motion_detect_th_b_reg.ma_framerlvthb = ptr->di_ma_frame_motion_th.ma_framerlvthb;
	motion_detect_th_b_reg.ma_framesthb = ptr->di_ma_frame_motion_th.ma_framesthb;

	motion_detect_th_c_reg.ma_framehthc = ptr->di_ma_frame_motion_th.ma_framehthc;
	motion_detect_th_c_reg.ma_framemthc = ptr->di_ma_frame_motion_th.ma_framemthc;
	motion_detect_th_c_reg.ma_framerlvthc = ptr->di_ma_frame_motion_th.ma_framerlvthc;
	motion_detect_th_c_reg.ma_framesthc = ptr->di_ma_frame_motion_th.ma_framesthc;

	/* Set Field teeth TH*/
	teeth_detect_th_a_reg.ma_fieldteethhtha = ptr->di_ma_field_teeth_th.ma_fieldteethhtha;
	teeth_detect_th_a_reg.ma_fieldteethmtha = ptr->di_ma_field_teeth_th.ma_fieldteethmtha;
	teeth_detect_th_a_reg.ma_fieldteethrlvtha = ptr->di_ma_field_teeth_th.ma_fieldteethrlvtha;
	teeth_detect_th_a_reg.ma_fieldteethstha = ptr->di_ma_field_teeth_th.ma_fieldteethstha;


	/* Write to register*/
	IoReg_Write32(DI_IM_DI_CONTROL_reg, di_control_reg.regValue);
	IoReg_Write32(DI_IM_DI_MA_FRAME_MOTION_TH_A_reg, motion_detect_th_a_reg.regValue);
	IoReg_Write32(DI_IM_DI_MA_FRAME_MOTION_TH_B_reg, motion_detect_th_b_reg.regValue);
	IoReg_Write32(DI_IM_DI_MA_FRAME_MOTION_TH_C_reg, motion_detect_th_c_reg.regValue);
	IoReg_Write32(DI_IM_DI_MA_FIELD_TEETH_TH_A_reg, teeth_detect_th_a_reg.regValue);

}

void drvif_color_ma_set_DI_MA_Init_Table(DRV_di_ma_init_table *ptr)
{

	di_im_di_ma_others_th_RBUS teeth_detect_th_b_reg;
	di_im_di_ma_sawtooth_th_RBUS sawtooth_th_reg;
	di_im_di_control_RBUS di_control_reg;

	/* Read from register*/
	teeth_detect_th_b_reg.regValue = IoReg_Read32(DI_IM_DI_MA_OTHERS_TH_reg);
	sawtooth_th_reg.regValue = IoReg_Read32(DI_IM_DI_MA_SAWTOOTH_TH_reg);
	di_control_reg.regValue = IoReg_Read32(DI_IM_DI_CONTROL_reg);

	/* Set Parameters*/
	di_control_reg.ma_onedirectionweaveen = ptr->di_ma_control_init.ma_onedirectionweaveen;
	di_control_reg.ma_preferintra = ptr->di_ma_control_init.ma_preferintra;

	teeth_detect_th_b_reg.ma_fieldteeththb = ptr->di_ma_others_th.ma_fieldteeththb;
	teeth_detect_th_b_reg.ma_stilllogovdth = ptr->di_ma_others_th.ma_stilllogovdth;
	teeth_detect_th_b_reg.ma_ydiffth = ptr->di_ma_others_th.ma_ydiffth;

	sawtooth_th_reg.ma_sawtoothhth = ptr->di_ma_sawtooth_th.ma_sawtoothhth;
	sawtooth_th_reg.ma_sawtoothmth = ptr->di_ma_sawtooth_th.ma_sawtoothmth;
	sawtooth_th_reg.ma_sawtoothrlvth = ptr->di_ma_sawtooth_th.ma_sawtoothrlvth;
	sawtooth_th_reg.ma_sawtoothsth = ptr->di_ma_sawtooth_th.ma_sawtoothsth;

	/* Write to register*/
	IoReg_Write32(DI_IM_DI_MA_OTHERS_TH_reg, teeth_detect_th_b_reg.regValue);
	IoReg_Write32(DI_IM_DI_MA_SAWTOOTH_TH_reg, sawtooth_th_reg.regValue);
	IoReg_Write32(DI_IM_DI_CONTROL_reg, di_control_reg.regValue);

}



extern unsigned char Scaler_I2rnd_get_enable(void);
void drvif_color_di_freeze(unsigned char bFreeze)
{
	/*printf("\033[1;41m drvif_color_di_freeze: bFreeze =%d \033[m\n", bFreeze);*/
	di_im_di_tnr_xc_control_RBUS TNR_XC_reg;
	di_im_di_blend_and_weighting_method_RBUS Blend_value_and_weighting_method_reg;
	di_im_di_rtnr_control_RBUS RecursiveTemporalNRCtrl_reg;

	di_im_di_control_RBUS di_control_reg;
	di_im_di_weave_window_control_RBUS di_weave_window_control_reg;
	di_db_reg_ctl_RBUS  db_reg_ctl_reg;

	static unsigned char mFreeze = FALSE;
	unsigned char timeout=0;

	if (mFreeze == bFreeze)
		return;
	else
		mFreeze = bFreeze;

	db_reg_ctl_reg.regValue =rtd_inl(DI_db_reg_ctl_reg);
#ifdef CONFIG_I2RND_ENABLE
	//Eric@0508 I2rnd do not set DI Double buffer
	if(!Scaler_I2rnd_get_enable()){
		db_reg_ctl_reg.db_en=1;
	}
	else{
		db_reg_ctl_reg.db_en=0;
	}
#else
	db_reg_ctl_reg.db_en=1;
#endif
	rtd_outl(DI_db_reg_ctl_reg,db_reg_ctl_reg.regValue);

	TNR_XC_reg.regValue = IoReg_Read32(DI_IM_DI_TNR_XC_CONTROL_reg);/*tnr-xc*/
	Blend_value_and_weighting_method_reg.regValue = IoReg_Read32(DI_IM_DI_BLEND_AND_WEIGHTING_METHOD_reg);/*pseudo memc*/
	RecursiveTemporalNRCtrl_reg.regValue = IoReg_Read32(DI_IM_DI_RTNR_CONTROL_reg);/*rtnr*/

	di_control_reg.regValue = IoReg_Read32(DI_IM_DI_CONTROL_reg);
	di_weave_window_control_reg.regValue = IoReg_Read32(DI_IM_DI_WEAVE_WINDOW_CONTROL_reg);

	/*USER:LewisLee DATE:2013/07/30*/
	/*fix DI 2D mode, freeze fail*/
	if (_ENABLE == Scaler_Get_DI_Force_2D_Enable()) {
		if (_TRUE == bFreeze) {
			if (_TRUE == di_weave_window_control_reg.force2d) {
				di_weave_window_control_reg.force2d = _FALSE;
				IoReg_Write32(DI_IM_DI_WEAVE_WINDOW_CONTROL_reg, di_weave_window_control_reg.regValue);
				/*WaitFor_IVS1();*/
				WaitFor_IVS1();	/* Rt_Sleep(20);*/

				di_weave_window_control_reg.regValue = IoReg_Read32(DI_IM_DI_WEAVE_WINDOW_CONTROL_reg);
			}
		} else { /* if (_FALSE == bFreeze) */
			if (_ENABLE == Scaler_Enter_DI_Force_2D_Condition((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY)))
				di_weave_window_control_reg.force2d = _TRUE;
		}
	}

	if (bFreeze) {
		bTemporalEnable = di_control_reg.cp_temporalenable;

		bRTNRXCEn = TNR_XC_reg.cp_temporal_xc_en;
		bPseudoMEMCEn = Blend_value_and_weighting_method_reg.pseudo_memc_en;
		bRTNRYEn = RecursiveTemporalNRCtrl_reg.cp_rtnr_y_enable;
		bRTNRCEn = RecursiveTemporalNRCtrl_reg.cp_rtnr_c_enable;

		TNR_XC_reg.cp_temporal_xc_en = 0;
		Blend_value_and_weighting_method_reg.pseudo_memc_en = 0;
		RecursiveTemporalNRCtrl_reg.cp_rtnr_y_enable = 0;
		RecursiveTemporalNRCtrl_reg.cp_rtnr_c_enable = 0;
		/*VIPprintf("\n yuan,b_cp_temporal_xc_en=%d\n",TNR_XC_reg.cp_temporal_xc_en);*/

		di_control_reg.film_enable = di_control_reg.film_enable&0x0F; /* disable film before di freeze*/
		di_control_reg.cp_temporalenable = 0;
		di_weave_window_control_reg.freeze = 1;

		/*WaitFor_IEN_START1();*/
		/*IoReg_BusyCheckRegInverseBit(VGIP_VGIP_CHN1_STATUS_reg, _BIT7, 0x1FFFF);*/

	} else {
		di_control_reg.film_enable = di_control_reg.film_enable|0x10;
		di_control_reg.cp_temporalenable = bTemporalEnable;

		TNR_XC_reg.cp_temporal_xc_en = bRTNRXCEn;

		/*VIPprintf("\n yuan,c_cp_temporal_xc_en=%d\n",TNR_XC_reg.cp_temporal_xc_en);*/
		Blend_value_and_weighting_method_reg.pseudo_memc_en = bPseudoMEMCEn;
		RecursiveTemporalNRCtrl_reg.cp_rtnr_y_enable = bRTNRYEn;
		RecursiveTemporalNRCtrl_reg.cp_rtnr_c_enable = bRTNRCEn;

		di_weave_window_control_reg.freeze = 0;
	}

	//20150805 roger, temporalenable must follow cp_temporal_xc_en
	di_control_reg.cp_temporalenable = TNR_XC_reg.cp_temporal_xc_en;
	/* henry @ mac5 161219 DI write enable bit */
	//di_control_reg.regValue = di_control_reg.regValue | DI_IM_DI_CONTROL_write_enable_6_mask | DI_IM_DI_CONTROL_write_enable_5_mask; // cp_temp: write_enable[18] // film: write_enable[16]
	di_control_reg.write_enable_5 = 1;
	di_control_reg.write_enable_6 = 1;



	/*VIPprintf("\n yuan,a_cp_temporal_xc_en=%d\n",TNR_XC_reg.cp_temporal_xc_en);*/
	/* henry @ mac5 161219 DI write enable bit */
	IoReg_Write32(DI_IM_DI_CONTROL_reg, di_control_reg.regValue);
	IoReg_Write32(DI_IM_DI_WEAVE_WINDOW_CONTROL_reg, di_weave_window_control_reg.regValue);
	IoReg_Write32(DI_IM_DI_TNR_XC_CONTROL_reg, TNR_XC_reg.regValue);/*tnr-xc*/
	IoReg_Write32(DI_IM_DI_BLEND_AND_WEIGHTING_METHOD_reg, Blend_value_and_weighting_method_reg.regValue);/*pseudo memc*/
	IoReg_Write32(DI_IM_DI_RTNR_CONTROL_reg, RecursiveTemporalNRCtrl_reg.regValue);/*rtnr*/


	db_reg_ctl_reg.regValue =rtd_inl(DI_db_reg_ctl_reg);
	db_reg_ctl_reg.db_apply = 1;
	IoReg_Write32(DI_db_reg_ctl_reg, db_reg_ctl_reg.regValue);

	db_reg_ctl_reg.regValue = IoReg_Read32(DI_db_reg_ctl_reg);
	while(db_reg_ctl_reg.db_apply) {
		timeout++;
		msleep(10);
		db_reg_ctl_reg.regValue = IoReg_Read32(DI_db_reg_ctl_reg);
		if(timeout >= 5)
		break;
	}

	db_reg_ctl_reg.regValue = IoReg_Read32(DI_db_reg_ctl_reg);
	db_reg_ctl_reg.db_en=0;
	rtd_outl(DI_db_reg_ctl_reg,db_reg_ctl_reg.regValue);
}





void drvif_color_ma_HFD(unsigned char bHFD)
{


	di_im_di_control_RBUS di_control_reg;
	di_im_di_hfd_control_RBUS HFD_Control_Reg;
	di_control_reg.regValue = IoReg_Read32(DI_IM_DI_CONTROL_reg);
	HFD_Control_Reg.regValue = IoReg_Read32(DI_IM_DI_HFD_CONTROL_reg);
	if (bHFD) {
		bTemporalEnable = di_control_reg.cp_temporalenable;
		di_control_reg.cp_temporalenable = 0; // write_enable[18]
		HFD_Control_Reg.hfd_highfrequencydetectoren = 1;
	} else {
		di_control_reg.cp_temporalenable = bTemporalEnable; // write_enable[18]
		HFD_Control_Reg.hfd_highfrequencydetectoren = 0;
	}

	/* henry @ mac5 161219 DI write enable bit */
	//di_control_reg.regValue = di_control_reg.regValue | DI_IM_DI_CONTROL_write_enable_6_mask;
	di_control_reg.write_enable_6 = 1;

	IoReg_Write32(DI_IM_DI_CONTROL_reg, di_control_reg.regValue);
	IoReg_Write32(DI_IM_DI_HFD_CONTROL_reg, HFD_Control_Reg.regValue);
}

void drvif_color_ma_TeethCheck(unsigned char Level)
{
#if 0/*frank@01072013 return for complier OK*/
	di_im_di_hfd_ma_error_recovery_RBUS MA_Error_Recovery_Reg;
	MA_Error_Recovery_Reg.regValue = IoReg_Read32(DI_IM_DI_HFD_MA_ERROR_RECOVERY_reg);


	MA_Error_Recovery_Reg.ma_teeth_cont_check_en = Level;


	IoReg_Write32(DI_IM_DI_HFD_MA_ERROR_RECOVERY_reg, MA_Error_Recovery_Reg.regValue);
#else
	return;
#endif

}

/* must check teethcheck status then change FIFO size*/
/* if enable each pixel bits number add 2*/
unsigned char drvif_color_ma_TeethCheckStatus()
{
#if 0
	di_im_di_hfd_ma_error_recovery_RBUS MA_Error_Recovery_Reg;
	MA_Error_Recovery_Reg.regValue = IoReg_Read32(DI_IM_DI_HFD_MA_ERROR_RECOVERY_reg);

	if (MA_Error_Recovery_Reg.ma_teeth_cont_check_en > 0)
		return TRUE;
	else
		return FALSE;
#else
	return TRUE;
#endif
}

void drvif_color_ma_HMCWindow(unsigned char bHMCWindow)
{
#if 0/*frank@01072013 return for complier OK*/
	di_im_di_hfd_ma_error_recovery_RBUS MA_Error_Recovery_Reg;
	MA_Error_Recovery_Reg.regValue = IoReg_Read32(DI_IM_DI_HFD_MA_ERROR_RECOVERY_reg);


	if (bHMCWindow) {
		MA_Error_Recovery_Reg.ma_teeth_cont_check_en = 1;
	} else {
		MA_Error_Recovery_Reg.ma_teeth_cont_check_en = 0;
	}

	IoReg_Write32(DI_IM_DI_HFD_MA_ERROR_RECOVERY_reg, MA_Error_Recovery_Reg.regValue);
#else
	return;
#endif
}



void drvif_color_ma_EdgeType(unsigned char bEdgeType)
{
	di_im_di_tnr_xc_control_RBUS TNR_XC_Reg;
	TNR_XC_Reg.regValue = IoReg_Read32(DI_IM_DI_TNR_XC_CONTROL_reg);

	if (bEdgeType) {
		TNR_XC_Reg.set_sobeledgetypeen = 1;
	} else {
		TNR_XC_Reg.set_sobeledgetypeen = 0;
	}
	IoReg_Write32(DI_IM_DI_TNR_XC_CONTROL_reg, TNR_XC_Reg.regValue); /* 41e8 , bit31*/


}

void drvif_color_ma_BTRBER_init(void)
{
}

void drvif_color_ma_BTR(unsigned char bBTR)
{
	di_im_di_btr_control_RBUS BTR_Control_Reg;
	di_im_di_ber_temporal_control_RBUS BER_Temporal_Control_Reg;
	SCALER_DISP_CHANNEL display = (SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY);

	BTR_Control_Reg.regValue = IoReg_Read32(DI_IM_DI_BTR_CONTROL_reg);
	BER_Temporal_Control_Reg.regValue = IoReg_Read32(DI_IM_DI_BER_TEMPORAL_CONTROL_reg);

	/* only 5A & interlace mode enable 20bit function*/
/*frank@1016 sync with DI setting	if  ((bBTR && (info->CapWid < 960))  && GET_INTERLACE_IN_INPUT_MODE(info->display))  	{*/
	if  ((bBTR && (Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_IPH_ACT_WID) < 960)) && Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_DISP_STATUS)) {

		BTR_Control_Reg.btr_blendtemporalrecoveryen = 1;
		BTR_Control_Reg.btr_sola_method0_blendtype = 1;
		BTR_Control_Reg.btr_solutiontype = 0;
		BER_Temporal_Control_Reg.ber_blendtemporalrevoeryen = 1;

	} else {
		/*egger20110803 Enable Blend_Temporal_Recovery_Control in HD Timing*/
		BTR_Control_Reg.btr_blendtemporalrecoveryen = 1;
		BTR_Control_Reg.btr_sola_method0_blendtype = 1;
		BTR_Control_Reg.btr_solutiontype = 1;
		BER_Temporal_Control_Reg.ber_blendtemporalrevoeryen = 0;
	}

	/* DI bit number control -- saving bandwidth*/
	if (drv_memory_get_ip_Btr_mode() == _DISABLE) {
		VIPprintf("[DI] BTR DISABLE\n");
		BTR_Control_Reg.btr_blendtemporalrecoveryen = 0;
	}

	IoReg_Write32(DI_IM_DI_BTR_CONTROL_reg, BTR_Control_Reg.regValue);
	IoReg_Write32(DI_IM_DI_BER_TEMPORAL_CONTROL_reg, BER_Temporal_Control_Reg.regValue);

}

/* Erin 100402*/
void drvif_color_ma_BER(unsigned char bBER)
{
	di_im_di_ber_spatial_control_RBUS BER_Spatial_Control_Reg;

	BER_Spatial_Control_Reg.regValue = IoReg_Read32(DI_IM_DI_BER_SPATIAL_CONTROL_reg);

	if (bBER) {
		BER_Spatial_Control_Reg.ber_blendspatialrecoveryen = 1;
	} else {
		BER_Spatial_Control_Reg.ber_blendspatialrecoveryen = 0;
	}

	IoReg_Write32(DI_IM_DI_BER_SPATIAL_CONTROL_reg, BER_Spatial_Control_Reg.regValue);
}


void drvif_color_ma_VEdge(unsigned char bEnable)
{
	di_im_di_classify2_thclassify_threshold_RBUS Classify2_th_Classify_Threshold_Reg;

	Classify2_th_Classify_Threshold_Reg.regValue = IoReg_Read32(DI_IM_DI_CLASSIFY2_THClassify_Threshold_reg);

	if (bEnable) {
		Classify2_th_Classify_Threshold_Reg.ma_vedge_nolp_en = 2;
	} else {
		Classify2_th_Classify_Threshold_Reg.ma_vedge_nolp_en = 0;
	}

	IoReg_Write32(DI_IM_DI_CLASSIFY2_THClassify_Threshold_reg, Classify2_th_Classify_Threshold_Reg.regValue);
}

void drvif_color_ma_FrameSobel_HEdge(unsigned char bEnable)
{
#if 0/*frank@01072013 return for complier OK*/
	im_di_framesobel_ctrl_RBUS FrameSobel_Ctrl_Reg;

	FrameSobel_Ctrl_Reg.regValue = IoReg_Read32(DI_IM_DI_FRAMESOBEL_CTRL_VADDR);

	if (bEnable) {
		FrameSobel_Ctrl_Reg.framesobel_en = 1;
	} else {
		FrameSobel_Ctrl_Reg.framesobel_en = 0;
	}

	IoReg_Write32(DI_IM_DI_FRAMESOBEL_CTRL_VADDR, FrameSobel_Ctrl_Reg.regValue);
#else
	return;
#endif
}

void drvif_color_ma_420Mode(unsigned char bEnable)
{
}

void drvif_color_ma_ChromaError(DRV_MA_ChromaError *ptr)
{
	di_im_di_framesobel_statistic_ctrl_RBUS FrameSobel_statistic_ctrl;
	di_im_di_framesobel_statistic_RBUS FrameSobel_statistic_Reg;
	di_im_di_control_RBUS di_im_di_control_RBUS_reg;

	FrameSobel_statistic_ctrl.regValue = IoReg_Read32(DI_IM_DI_FRAMESOBEL_STATISTIC_CTRL_reg);
	FrameSobel_statistic_Reg.regValue = IoReg_Read32(DI_IM_DI_FRAMESOBEL_STATISTIC_reg);
	di_im_di_control_RBUS_reg.regValue = IoReg_Read32(DI_IM_DI_CONTROL_reg);

	FrameSobel_statistic_ctrl.chromaerror_framemotionc_th = ptr->chromaerror_framemotionc_th;
	FrameSobel_statistic_Reg.chromaerror_all = ptr->chromaerror_all;
	FrameSobel_statistic_Reg.chromaerror_en = ptr->chromaerror_en;
	FrameSobel_statistic_Reg.chromaerror_th = ptr->chromaerror_th;
	di_im_di_control_RBUS_reg.di444to422lowpass = ptr->di444to422Lowpass;
	di_im_di_control_RBUS_reg.write_enable_7 = 1;

	IoReg_Write32(DI_IM_DI_FRAMESOBEL_STATISTIC_CTRL_reg, FrameSobel_statistic_ctrl.regValue);
	IoReg_Write32(DI_IM_DI_FRAMESOBEL_STATISTIC_reg, FrameSobel_statistic_Reg.regValue);
	IoReg_Write32(DI_IM_DI_CONTROL_reg, di_im_di_control_RBUS_reg.regValue);
}

/*
Level 0 : disable
Level 1: enable 0, low hmc
Level 6: enable 5, high hmc
*/
void drvif_color_ma_HMC(DRV_di_ma_hmc_table *ptr)
{
	/* di_ma_hmc_main_control part*/
	di_im_di_control_RBUS di_ctrl_reg;
	di_im_di_hfd_ma_error_recovery_RBUS di_hmc_window_ctrl_reg;
	di_im_di_hmc_adjustable_RBUS di_hmc_adjustable_reg;
	di_im_di_hmc_adjustable2_RBUS di_hmc_adjustable2_reg;
	di_im_di_hmc_pan_control_RBUS di_hmc_pan_control_reg;
	di_im_di_hmc_3a_RBUS di_hmc_3a_reg;
	di_im_di_ma_others_th_RBUS teeth_detect_th_b_reg;

	/* di_ma_hmc_mv_refine*/
	di_im_di_hmc_pan_control_par_2_RBUS di_hmc_pan_control_par_2_reg;
	di_im_di_hmc_adjustable4_RBUS di_hmc_adjustable4_reg;

	/* di_ma_hmc_morphology*/
	di_im_di_hmc_adjustable3_RBUS di_hmc_adjustable3_reg;

	/* di_ma_hmc_dynamic_control*/
	di_im_di_framesobel_statistic_RBUS di_framesobel_statistic_reg;
	/*di_im_di_hmc_adjustable_RBUS di_hmc_adjustable_reg;*/

	/* di_ma_hmc_vertical_intra*/
	di_im_di_hmc_pan_vertical_intra_1_RBUS di_hmc_pan_vertical_intra_1_reg;
	di_im_di_hmc_pan_vertical_intra_2_RBUS di_hmc_pan_vertical_intra_2_reg;
	di_im_di_hmc_pan_vertical_intra_3_RBUS di_hmc_pan_vertical_intra_3_reg;

	di_im_di_hmc_me_refine_ctrl_1_RBUS di_hmc_me_refine_ctrl1_reg;
	di_im_di_hmc_me_refine_ctrl_2_RBUS di_hmc_me_refine_ctrl2_reg;

	if (!ptr)
		return;

	di_ctrl_reg.regValue = IoReg_Read32(DI_IM_DI_CONTROL_reg);
	teeth_detect_th_b_reg.regValue = IoReg_Read32(DI_IM_DI_MA_OTHERS_TH_reg);
	di_hmc_window_ctrl_reg.regValue = IoReg_Read32(DI_IM_DI_HFD_MA_ERROR_RECOVERY_reg);
	di_hmc_adjustable_reg.regValue = IoReg_Read32(DI_IM_DI_HMC_ADJUSTABLE_reg);
	di_hmc_adjustable2_reg.regValue = IoReg_Read32(DI_IM_DI_HMC_ADJUSTABLE2_reg);
	di_hmc_pan_control_reg.regValue = IoReg_Read32(DI_IM_DI_HMC_PAN_CONTROL_reg);
	di_hmc_3a_reg.regValue = IoReg_Read32(DI_IM_DI_HMC_3A_reg);
	di_hmc_pan_control_par_2_reg.regValue = IoReg_Read32(DI_IM_DI_HMC_PAN_CONTROL_PAR_2_reg);
	di_hmc_adjustable4_reg.regValue = IoReg_Read32(DI_IM_DI_HMC_ADJUSTABLE4_reg);
	di_hmc_adjustable3_reg.regValue = IoReg_Read32(DI_IM_DI_HMC_ADJUSTABLE3_reg);
	di_framesobel_statistic_reg.regValue = IoReg_Read32(DI_IM_DI_FRAMESOBEL_STATISTIC_reg);
	di_hmc_adjustable_reg.regValue = IoReg_Read32(DI_IM_DI_HMC_ADJUSTABLE_reg);
	di_hmc_pan_vertical_intra_1_reg.regValue = IoReg_Read32(DI_IM_DI_HMC_PAN_VERTICAL_INTRA_1_reg);
	di_hmc_pan_vertical_intra_2_reg.regValue = IoReg_Read32(DI_IM_DI_HMC_PAN_VERTICAL_INTRA_2_reg);
	di_hmc_pan_vertical_intra_3_reg.regValue = IoReg_Read32(DI_IM_DI_HMC_PAN_VERTICAL_INTRA_3_reg);

	di_hmc_me_refine_ctrl1_reg.regValue = IoReg_Read32(DI_IM_DI_HMC_ME_REFINE_CTRL_1_reg);
	di_hmc_me_refine_ctrl2_reg.regValue = IoReg_Read32(DI_IM_DI_HMC_ME_REFINE_CTRL_2_reg);


	di_hmc_me_refine_ctrl1_reg.regValue = ptr->DI_HMC_ME_REFINE_CTRL_1;
	di_hmc_me_refine_ctrl2_reg.hmc_fw_ctrl_bypass = 0; //init value by hmc_en rord.tsao 2016/11/22
	IoReg_Write32(DI_IM_DI_HMC_ME_REFINE_CTRL_1_reg,di_hmc_me_refine_ctrl1_reg.regValue);
	IoReg_Write32(DI_IM_DI_HMC_ME_REFINE_CTRL_2_reg,di_hmc_me_refine_ctrl2_reg.regValue);

	/* di_ma_hmc_main_control part*/
	di_ctrl_reg.ma_horicomen = ptr->di_ma_hmc_main_control.hmc_en; // write_enable[10]
	di_hmc_window_ctrl_reg.hmc_window_en = ptr->di_ma_hmc_main_control.hmc_window_en;
	di_hmc_window_ctrl_reg.hmc_window_top = ptr->di_ma_hmc_main_control.hmc_window_top;
	di_hmc_window_ctrl_reg.hmc_window_bot = ptr->di_ma_hmc_main_control.hmc_window_bot;
	di_hmc_adjustable_reg.hmc_even_mv_no_vectorteeth = ptr->di_ma_hmc_main_control.hmc_even_mv_no_teeth_en;
	di_hmc_adjustable_reg.hmc_odd_mv_no_compesation = ptr->di_ma_hmc_main_control.hmc_odd_mv_no_comp_en;
	di_hmc_adjustable2_reg.hmc_follow_ma_result_en = ptr->di_ma_hmc_main_control.hmc_follow_MA_en;
	di_hmc_adjustable3_reg.hmc_fail_follow_ma_result_en = 1;
	di_hmc_pan_control_reg.hmc_half_mv_blending_en = ptr->di_ma_hmc_main_control.hmc_half_mv_blending_en;
	di_hmc_3a_reg.hmc_startline = ptr->di_ma_hmc_main_control.hmc_window_start_line;
	teeth_detect_th_b_reg.ma_horicomth = ptr->di_ma_hmc_main_control.ma_horicomth;

	/* henry @ mac5 161219 DI write enable bit */
	//di_ctrl_reg.regValue = di_ctrl_reg.regValue | DI_IM_DI_CONTROL_write_enable_4_mask;
	di_ctrl_reg.write_enable_4 = 1;
	/* di_ma_hmc_mv_refine*/
	di_hmc_adjustable_reg.hmc_mv_refine_en = ptr->di_ma_hmc_mv_refine.mv_refine_en;
	di_hmc_adjustable_reg.hmc_mv_refine_y_th = ptr->di_ma_hmc_mv_refine.mv_refine_Y_thd;
	di_hmc_pan_control_reg.hmc_mv_refine_sub_px_mv_en = ptr->di_ma_hmc_mv_refine.mv_refine_subPx_en;
	di_hmc_pan_control_par_2_reg.hmc_sub_pixel_diff_thd = ptr->di_ma_hmc_mv_refine.mv_refine_subPx_Y_thd;
	di_hmc_adjustable2_reg.hmc_mv_refine_cur_motion_en = ptr->di_ma_hmc_mv_refine.mv_refine_curMotion_en;
	di_hmc_adjustable2_reg.hmc_mv_refine_cur_motion_th = ptr->di_ma_hmc_mv_refine.mv_refine_curMotion_thd;
	di_hmc_adjustable4_reg.hmc_mv_refine_sobel_en = ptr->di_ma_hmc_mv_refine.mv_refine_sobel_en;
	di_hmc_adjustable4_reg.hmc_mv_refine_sobel_diff_th = ptr->di_ma_hmc_mv_refine.mv_refine_sobel_diff_thd;
	di_hmc_adjustable4_reg.hmc_mv_refine_sobel_non_edge_th = ptr->di_ma_hmc_mv_refine.mv_refine_sobel_nonEdge_thd;

	/* di_ma_hmc_morphology*/
	di_hmc_adjustable_reg.hmc_mv_refine_mor_en = ptr->di_ma_hmc_morphology.en;
	di_hmc_adjustable2_reg.hmc_mv_refine_mor_noise_th = ptr->di_ma_hmc_morphology.noise_thd;
	di_hmc_adjustable2_reg.hmc_mv_refine_mor_same_th1_hh = ptr->di_ma_hmc_morphology.same_hh_1_thd;
	di_hmc_adjustable2_reg.hmc_mv_refine_mor_zero_th1_hh = ptr->di_ma_hmc_morphology.zero_hh_1_thd;
	di_hmc_adjustable3_reg.hmc_mv_refine_mor_same_th1 = ptr->di_ma_hmc_morphology.same_1_thd;
	di_hmc_adjustable3_reg.hmc_mv_refine_mor_same_th2 = ptr->di_ma_hmc_morphology.same_2_thd;
	di_hmc_adjustable3_reg.hmc_mv_refine_mor_zero_th1 = ptr->di_ma_hmc_morphology.zero_1_thd;
	di_hmc_adjustable3_reg.hmc_mv_refine_mor_zero_th2 = ptr->di_ma_hmc_morphology.zero_2_thd;
	di_hmc_adjustable4_reg.hmc_mv_refine_mor_hh_h_th = ptr->di_ma_hmc_morphology.hh_h_thd;
	di_hmc_adjustable4_reg.hmc_mv_refine_mor_hh_v_th = ptr->di_ma_hmc_morphology.hh_v_thd;

	/* di_ma_hmc_dynamic_control*/
	di_framesobel_statistic_reg.hmc_dynamic_threshold_en = ptr->di_ma_hmc_dynamic_control.thd_en;
	di_framesobel_statistic_reg.hmc_dynamic_threshold_bias = ptr->di_ma_hmc_dynamic_control.thd_bias;
	di_hmc_adjustable_reg.mc_dynamic_threshold_clip_en = ptr->di_ma_hmc_dynamic_control.clip_en;
	di_hmc_adjustable_reg.hmc_dynamic_threshold_min_clip = ptr->di_ma_hmc_dynamic_control.clip_min_thd;
	di_framesobel_statistic_reg.hmc_dynamic_threshold_max_clip = ptr->di_ma_hmc_dynamic_control.clip_max_thd;

	/* di_ma_hmc_vertical_intra*/
	di_hmc_pan_control_reg.hmc_vertical_intra_en = ptr->di_ma_hmc_vertical_intra.en;
	di_hmc_pan_vertical_intra_1_reg.hmc_vertical_intra_edge_yuv_diff = ptr->di_ma_hmc_vertical_intra.edge_yuv_diff;
	di_hmc_pan_vertical_intra_1_reg.hmc_vertical_intra_top_bot_diff_y = ptr->di_ma_hmc_vertical_intra.top_bot_y;
	di_hmc_pan_vertical_intra_1_reg.hmc_vertical_intra_top_bot_diff_u = ptr->di_ma_hmc_vertical_intra.top_bot_u;
	di_hmc_pan_vertical_intra_1_reg.hmc_vertical_intra_top_bot_diff_v = ptr->di_ma_hmc_vertical_intra.top_bot_v;
	di_hmc_pan_vertical_intra_2_reg.hmc_vertical_intra_top_cur_diff_y = ptr->di_ma_hmc_vertical_intra.top_cur_y;
	di_hmc_pan_vertical_intra_2_reg.hmc_vertical_intra_top_cur_diff_u = ptr->di_ma_hmc_vertical_intra.top_cur_u;
	di_hmc_pan_vertical_intra_2_reg.hmc_vertical_intra_top_cur_diff_v = ptr->di_ma_hmc_vertical_intra.top_cur_v;
	di_hmc_pan_vertical_intra_3_reg.hmc_vertical_intra_cur_bot_diff_y = ptr->di_ma_hmc_vertical_intra.cur_bot_y;
	di_hmc_pan_vertical_intra_3_reg.hmc_vertical_intra_cur_bot_diff_u = ptr->di_ma_hmc_vertical_intra.cur_bot_u;
	di_hmc_pan_vertical_intra_3_reg.hmc_vertical_intra_cur_bot_diff_v = ptr->di_ma_hmc_vertical_intra.cur_bot_v;

	IoReg_Write32(DI_IM_DI_CONTROL_reg, di_ctrl_reg.regValue);
	IoReg_Write32(DI_IM_DI_MA_OTHERS_TH_reg, teeth_detect_th_b_reg.regValue);
	IoReg_Write32(DI_IM_DI_HFD_MA_ERROR_RECOVERY_reg, di_hmc_window_ctrl_reg.regValue);
	IoReg_Write32(DI_IM_DI_HMC_ADJUSTABLE_reg, di_hmc_adjustable_reg.regValue);
	IoReg_Write32(DI_IM_DI_HMC_ADJUSTABLE2_reg, di_hmc_adjustable2_reg.regValue);
	IoReg_Write32(DI_IM_DI_HMC_PAN_CONTROL_reg, di_hmc_pan_control_reg.regValue);
	IoReg_Write32(DI_IM_DI_HMC_3A_reg, di_hmc_3a_reg.regValue);
	IoReg_Write32(DI_IM_DI_HMC_PAN_CONTROL_PAR_2_reg, di_hmc_pan_control_par_2_reg.regValue);
	IoReg_Write32(DI_IM_DI_HMC_ADJUSTABLE4_reg, di_hmc_adjustable4_reg.regValue);
	IoReg_Write32(DI_IM_DI_HMC_ADJUSTABLE3_reg, di_hmc_adjustable3_reg.regValue);
	IoReg_Write32(DI_IM_DI_FRAMESOBEL_STATISTIC_reg, di_framesobel_statistic_reg.regValue);
	IoReg_Write32(DI_IM_DI_HMC_ADJUSTABLE_reg, di_hmc_adjustable_reg.regValue);
	IoReg_Write32(DI_IM_DI_HMC_PAN_VERTICAL_INTRA_1_reg, di_hmc_pan_vertical_intra_1_reg.regValue);
	IoReg_Write32(DI_IM_DI_HMC_PAN_VERTICAL_INTRA_2_reg, di_hmc_pan_vertical_intra_2_reg.regValue);
	IoReg_Write32(DI_IM_DI_HMC_PAN_VERTICAL_INTRA_3_reg, di_hmc_pan_vertical_intra_3_reg.regValue);
}

void drvif_color_ma_HME(DRV_di_ma_hme_table *ptr)
{
	di_im_di_hmc_pan_control_RBUS di_hmc_pan_control_reg;
	di_im_di_hmc_pan_add_bias_RBUS di_hmc_pan_add_bias_reg;
	di_im_di_hmc_pan_control_par_1_RBUS di_hmc_pan_control_par_1_reg;
	di_im_di_hmc_pan_control_par_2_RBUS di_hmc_pan_control_par_2_reg;
	di_im_di_hmc_adjustable2_RBUS di_hmc_adjustable2_reg;
	di_im_di_hmc_adjustable_RBUS di_hmc_adjustable_reg;
	di_im_di_hmc_statistic1_RBUS di_hmc_statistic1_reg;

	if (!ptr)
		return;

	di_hmc_pan_control_reg.regValue = IoReg_Read32(DI_IM_DI_HMC_PAN_CONTROL_reg);
	di_hmc_pan_add_bias_reg.regValue = IoReg_Read32(DI_IM_DI_HMC_PAN_ADD_BIAS_reg);
	di_hmc_pan_control_par_1_reg.regValue = IoReg_Read32(DI_IM_DI_HMC_PAN_CONTROL_PAR_1_reg);
	di_hmc_pan_control_par_2_reg.regValue = IoReg_Read32(DI_IM_DI_HMC_PAN_CONTROL_PAR_2_reg);
	di_hmc_adjustable2_reg.regValue = IoReg_Read32(DI_IM_DI_HMC_ADJUSTABLE2_reg);
	di_hmc_adjustable_reg.regValue = IoReg_Read32(DI_IM_DI_HMC_ADJUSTABLE_reg);
	di_hmc_statistic1_reg.regValue = IoReg_Read32(DI_IM_DI_HMC_STATISTIC1_reg);

	/*		di_ma_hme_prefer_even_mv di_ma_hme_prefer_even_mv;			*/ /* 2*/
	di_hmc_pan_control_reg.hme_prefer_even_mv_en = 0;
	di_hmc_pan_control_par_2_reg.hme_prefer_even_mv_ratio = ptr->di_ma_hme_prefer_even_mv.ratio;

	/*		di_ma_hme_avoid_RL di_ma_hme_avoid_RL;						*/ /* 3*/
	di_hmc_pan_control_reg.hme_avoid_rltype_vertical_pan_en = ptr->di_ma_hme_avoid_RL.en;
	di_hmc_pan_control_par_2_reg.hme_avoid_rltype_vertical_pan_nedge_thd = ptr->di_ma_hme_avoid_RL.Nedge;
	di_hmc_pan_control_par_2_reg.hme_avoid_rltype_vertical_pan_rledge_thd = ptr->di_ma_hme_avoid_RL.RLedge;

	/*		di_ma_hme_ref_y di_ma_hme_ref_y;							*/ /* 7*/
	di_hmc_pan_control_reg.pan_me_sobel_diff_ref_y_add_bias_en = ptr->di_ma_hme_ref_y.en;
	di_hmc_pan_add_bias_reg.pan_me_sobel_diff_ref_y_add_bias_1 = ptr->di_ma_hme_ref_y.bias1;
	di_hmc_pan_add_bias_reg.pan_me_sobel_diff_ref_y_add_bias_2 = ptr->di_ma_hme_ref_y.bias2;
	di_hmc_pan_add_bias_reg.pan_me_sobel_diff_ref_y_add_bias_3 = ptr->di_ma_hme_ref_y.bias3;
	di_hmc_pan_add_bias_reg.pan_me_sobel_diff_ref_y_add_bias_th0 = ptr->di_ma_hme_ref_y.thd0;
	di_hmc_pan_add_bias_reg.pan_me_sobel_diff_ref_y_add_bias_th1 = ptr->di_ma_hme_ref_y.thd1;
	di_hmc_pan_add_bias_reg.pan_me_sobel_diff_ref_y_add_bias_th2 = ptr->di_ma_hme_ref_y.thd2;

	/*		di_ma_hme_invalid_check di_ma_hme_invalid_check;				*/ /* 5*/
	di_hmc_pan_control_reg.hme_check_zero_mv_en = ptr->di_ma_hme_invalid_check.zeroMV_en;
	di_hmc_pan_control_reg.pan_me_invalid_check_en = ptr->di_ma_hme_invalid_check.chck_1_en;
	di_hmc_pan_control_reg.hme_consider_mv_invalid_en = ptr->di_ma_hme_invalid_check.chck_2_en;
	di_hmc_pan_control_par_1_reg.pan_me_invalid_check_cnt_thd = ptr->di_ma_hme_invalid_check.cnt;
	di_hmc_pan_control_par_1_reg.pan_me_invalid_check_maxmin_diff_thd = ptr->di_ma_hme_invalid_check.maxmin_thd;

	/*		di_ma_hme_decision di_ma_hme_decision;						*/ /* 5*/
	di_hmc_adjustable_reg.hme_sobel_search_min = ptr->di_ma_hme_decision.min;
	di_hmc_adjustable2_reg.hme_x_continued_counter = ptr->di_ma_hme_decision.x_conti_cnt;
	di_hmc_adjustable_reg.hme_max_absolute_count = ptr->di_ma_hme_decision.max_abs;
	di_hmc_statistic1_reg.ma_hmc_lineratio = ptr->di_ma_hme_decision.line_ratio;
	di_hmc_pan_control_par_1_reg.hme_sum_max_ratio = ptr->di_ma_hme_decision.sum_max_ratio;

	IoReg_Write32(DI_IM_DI_HMC_PAN_CONTROL_reg, di_hmc_pan_control_reg.regValue);
	IoReg_Write32(DI_IM_DI_HMC_PAN_ADD_BIAS_reg, di_hmc_pan_add_bias_reg.regValue);
	IoReg_Write32(DI_IM_DI_HMC_PAN_CONTROL_PAR_1_reg, di_hmc_pan_control_par_1_reg.regValue);
	IoReg_Write32(DI_IM_DI_HMC_PAN_CONTROL_PAR_2_reg, di_hmc_pan_control_par_2_reg.regValue);
	IoReg_Write32(DI_IM_DI_HMC_ADJUSTABLE2_reg, di_hmc_adjustable2_reg.regValue);
	IoReg_Write32(DI_IM_DI_HMC_ADJUSTABLE_reg, di_hmc_adjustable_reg.regValue);
	IoReg_Write32(DI_IM_DI_HMC_STATISTIC1_reg, di_hmc_statistic1_reg.regValue);
}

void drvif_color_ma_PAN(DRV_di_ma_pan_table *ptr)
{
	di_im_di_pan_detection_control_1_RBUS di_pan_detection_control_1_RBUS ;
	di_im_di_pan_detection_control_2_RBUS di_pan_detection_control_2_RBUS ;
	di_im_di_hmc_pan_control_RBUS di_hmc_pan_control_reg;
	di_im_di_hmc_pan_control_par_1_RBUS di_hmc_pan_control_par_1_reg;
	di_im_di_hmc_pan_dummy_1_RBUS di_im_di_hmc_pan_dummy_1_reg;
	di_im_di_hmc_pan_dummy_2_RBUS di_im_di_hmc_pan_dummy_2_reg;
	di_im_di_hmc_pan_dummy_3_RBUS di_im_di_hmc_pan_dummy_3_reg;

	if (!ptr)
		return;

	di_pan_detection_control_1_RBUS.regValue = IoReg_Read32(DI_IM_DI_PAN_DETECTION_CONTROL_1_reg);
	di_pan_detection_control_2_RBUS.regValue = IoReg_Read32(DI_IM_DI_PAN_DETECTION_CONTROL_2_reg);
	di_hmc_pan_control_reg.regValue = IoReg_Read32(DI_IM_DI_HMC_PAN_CONTROL_reg);
	di_hmc_pan_control_par_1_reg.regValue = IoReg_Read32(DI_IM_DI_HMC_PAN_CONTROL_PAR_1_reg);
	di_im_di_hmc_pan_dummy_1_reg.regValue = IoReg_Read32(DI_IM_DI_HMC_PAN_DUMMY_1_reg);
	di_im_di_hmc_pan_dummy_2_reg.regValue = IoReg_Read32(DI_IM_DI_HMC_PAN_DUMMY_2_reg);
	di_im_di_hmc_pan_dummy_3_reg.regValue = IoReg_Read32(DI_IM_DI_HMC_PAN_DUMMY_3_reg);

	/*		DRV_di_ma_pan_control di_ma_pan_control;						*/ /* 12*/
	di_pan_detection_control_1_RBUS.pan_en = ptr->di_ma_pan_control.pan_en;
	di_pan_detection_control_1_RBUS.pan_mc_odd_mv_pass_en = ptr->di_ma_pan_control.pan_odd_mv_en;
	di_pan_detection_control_1_RBUS.pan_mc_sobel_diff_min_th = ptr->di_ma_pan_control.sobel_diff_thd;
	di_pan_detection_control_2_RBUS.pan_mc_teeth_check_en = ptr->di_ma_pan_control.pan_mc_teeth_check_en;
	di_pan_detection_control_2_RBUS.pan_mc_teeth_check_th = ptr->di_ma_pan_control.teeth_check_thd;
	di_hmc_pan_control_reg.pan_me_sub_pixel_mv_det_en = ptr->di_ma_pan_control.sub_px_det_en;
	di_hmc_pan_control_reg.pan_mc_force_compensation_en = ptr->di_ma_pan_control.force_comp_en;
	di_hmc_pan_control_reg.pan_mc_compensation_vertical_intra_en = ptr->di_ma_pan_control.pan_mc_vertical_intra_en;
	di_hmc_pan_control_reg.pan_me_select_mv_hist = ptr->di_ma_pan_control.pan_me_hist_sel;
	di_hmc_pan_control_reg.pan_mc_adaptive_compensation_en = ptr->di_ma_pan_control.pan_mc_adpative_en;
	di_hmc_pan_control_reg.pan_mc_rls_en = ptr->di_ma_pan_control.pan_mc_rls_en;
	di_hmc_pan_control_par_1_reg.pan_mc_rls_sobel_diff_min_th = ptr->di_ma_pan_control.sobel_diff_thd_rls;

	/*		DRV_di_ma_pan_edge_type di_ma_pan_edge_type;					*/ /* 5*/
	di_pan_detection_control_2_RBUS.pan_mc_edge_n = ptr->di_ma_pan_edge_type.Nedge_en;
	di_pan_detection_control_2_RBUS.pan_mc_edge_h = ptr->di_ma_pan_edge_type.Hedge_en;
	di_pan_detection_control_2_RBUS.pan_mc_edge_v = ptr->di_ma_pan_edge_type.Vedge_en;
	di_pan_detection_control_2_RBUS.pan_mc_edge_l = ptr->di_ma_pan_edge_type.Ledge_en;
	di_pan_detection_control_2_RBUS.pan_mc_edge_r = ptr->di_ma_pan_edge_type.Redge_en;

	/*		DRV_di_ma_pan_detection di_ma_pan_detection;					*/ /*	8*/
	di_im_di_hmc_pan_dummy_1_reg.diffMinThd = ptr->di_ma_pan_detection.diffMinThd;
	di_im_di_hmc_pan_dummy_1_reg.restIdx = ptr->di_ma_pan_detection.restIdx;
	di_im_di_hmc_pan_dummy_1_reg.restIdxThd = ptr->di_ma_pan_detection.restIdxThd;
	di_im_di_hmc_pan_dummy_2_reg.diffMaxMin = ptr->di_ma_pan_detection.diffMaxMin;
	di_im_di_hmc_pan_dummy_2_reg.panConti_str = ptr->di_ma_pan_detection.panConti_str;
	di_im_di_hmc_pan_dummy_2_reg.panConti = ptr->di_ma_pan_detection.panConti;
	di_im_di_hmc_pan_dummy_3_reg.panDeb_str = ptr->di_ma_pan_detection.panDeb_str;
	di_im_di_hmc_pan_dummy_3_reg.panDeb = ptr->di_ma_pan_detection.panDeb;

	IoReg_Write32(DI_IM_DI_PAN_DETECTION_CONTROL_1_reg, di_pan_detection_control_1_RBUS.regValue);
	IoReg_Write32(DI_IM_DI_PAN_DETECTION_CONTROL_2_reg, di_pan_detection_control_2_RBUS.regValue);
	IoReg_Write32(DI_IM_DI_HMC_PAN_CONTROL_reg, di_hmc_pan_control_reg.regValue);
	IoReg_Write32(DI_IM_DI_HMC_PAN_CONTROL_PAR_1_reg, di_hmc_pan_control_par_1_reg.regValue);
	IoReg_Write32(DI_IM_DI_HMC_PAN_DUMMY_1_reg, di_im_di_hmc_pan_dummy_1_reg.regValue);
	IoReg_Write32(DI_IM_DI_HMC_PAN_DUMMY_2_reg, di_im_di_hmc_pan_dummy_2_reg.regValue);
	IoReg_Write32(DI_IM_DI_HMC_PAN_DUMMY_3_reg, di_im_di_hmc_pan_dummy_3_reg.regValue);
}

void drvif_color_ma_blending_corrector_1(unsigned char bEnable, unsigned char teeth_min, unsigned char teeth_max, unsigned char blendmode)
{
	di_im_di_blending_corrector_1_RBUS di_blending_corrector_1_reg;

	di_blending_corrector_1_reg.regValue = IoReg_Read32(DI_IM_DI_BLENDING_CORRECTOR_1_reg);

	if (bEnable)
		di_blending_corrector_1_reg.bc_type1_en = 1;
	else
		di_blending_corrector_1_reg.bc_type1_en = 0;

	if (teeth_min <= 15)
		di_blending_corrector_1_reg.bc_type1_mid_teeth_min = teeth_min;

	if (teeth_max <= 255)
		di_blending_corrector_1_reg.bc_type1_mid_teeth_max = teeth_max;

	if (blendmode <= 3)
		di_blending_corrector_1_reg.bc_type1_blendmode = blendmode;

	IoReg_Write32(DI_IM_DI_BLENDING_CORRECTOR_1_reg, di_blending_corrector_1_reg.regValue);
}

void drvif_color_ma_blending_corrector_2(unsigned char bEnable, unsigned char mode)
{
	di_im_di_blending_corrector_1_RBUS di_blending_corrector_1_reg;
	di_im_di_blending_corrector_2_RBUS di_blending_corrector_2_reg;

	di_blending_corrector_1_reg.regValue = IoReg_Read32(DI_IM_DI_BLENDING_CORRECTOR_1_reg);
	di_blending_corrector_2_reg.regValue = IoReg_Read32(DI_IM_DI_BLENDING_CORRECTOR_2_reg);

	switch (mode) {
	case 0: /* SD*/
		di_blending_corrector_2_reg.bc_type2_block_width = 48;
		di_blending_corrector_2_reg.bc_type2_block_height = 32;
		break;
	case 1:
		di_blending_corrector_2_reg.bc_type2_block_width = 128;
		di_blending_corrector_2_reg.bc_type2_block_height = 60;
		break;
	}

	IoReg_Write32(DI_IM_DI_BLENDING_CORRECTOR_2_reg, di_blending_corrector_2_reg.regValue);

	if (bEnable)
		di_blending_corrector_1_reg.bc_type2_en = 1;
	else
		di_blending_corrector_1_reg.bc_type2_en = 0;

	IoReg_Write32(DI_IM_DI_BLENDING_CORRECTOR_1_reg, di_blending_corrector_1_reg.regValue);
}

int drvif_color_ma_blending_corrector_2_getData(unsigned char pos_x, unsigned char pos_y)
{
	di_im_di_blending_corrector_1_RBUS di_blending_corrector_1_reg;
	di_im_di_blending_corrector_2_RBUS di_blending_corrector_2_reg;

	if (pos_x > 14)
		pos_x = 14;
	if (pos_y > 17)
		pos_y = 17;

	di_blending_corrector_1_reg.regValue = IoReg_Read32(DI_IM_DI_BLENDING_CORRECTOR_1_reg);
	di_blending_corrector_1_reg.bc_type2_block_access_x = pos_x;
	di_blending_corrector_1_reg.bc_type2_block_access_y = pos_y;
	IoReg_Write32(DI_IM_DI_BLENDING_CORRECTOR_1_reg, di_blending_corrector_1_reg.regValue);

	di_blending_corrector_2_reg.regValue = IoReg_Read32(DI_IM_DI_BLENDING_CORRECTOR_2_reg);

	return di_blending_corrector_2_reg.bc_type2_block_access_data;

}

void drvif_color_ma_Pan_Detection(unsigned char bEnable)
{
	unsigned char source;
	di_im_di_pan_detection_control_1_RBUS di_pan_detection_control_1_reg;
	di_im_di_pan_detection_control_2_RBUS di_pan_detection_control_2_reg;
	di_im_di_pan_detection_control_3_RBUS di_pan_detection_control_3_reg;
	di_im_di_framesobel_statistic_RBUS di_framesobel_statistic_Reg;
	di_im_di_pan_detection_statistic_8_RBUS im_di_pan_detection_statistic_8_reg;

	di_pan_detection_control_1_reg.regValue = IoReg_Read32(DI_IM_DI_PAN_DETECTION_CONTROL_1_reg);
	di_pan_detection_control_2_reg.regValue = IoReg_Read32(DI_IM_DI_PAN_DETECTION_CONTROL_2_reg);
	di_pan_detection_control_3_reg.regValue = IoReg_Read32(DI_IM_DI_PAN_DETECTION_CONTROL_3_reg);
	di_framesobel_statistic_Reg.regValue = IoReg_Read32(DI_IM_DI_FRAMESOBEL_STATISTIC_reg);
	im_di_pan_detection_statistic_8_reg.regValue = IoReg_Read32(DI_IM_DI_PAN_DETECTION_STATISTIC_8_reg);

#if 0
	if (bEnable) {
		di_pan_detection_control_1_reg.pan_en = 1;
		di_pan_detection_control_2_reg.pan_mc_edge_v = 1;
		di_pan_detection_control_3_reg.pan_me_border_top_width = 2;
		di_pan_detection_control_3_reg.pan_me_border_bot_width = 2;
		di_pan_detection_control_3_reg.pan_me_border_left_width = 2;
		di_pan_detection_control_3_reg.pan_me_border_right_width = 2;
	} else
		di_pan_detection_control_1_reg.pan_en = 0;
#else

	source = fwif_vip_source_check(3, 0);
	if (bEnable) {
		di_pan_detection_control_1_reg.pan_en = 1;
		di_pan_detection_control_2_reg.pan_mc_edge_v = 1;
		im_di_pan_detection_statistic_8_reg.pan_me_border_top_width = 2;
		di_pan_detection_control_3_reg.pan_me_border_bot_width = 2;
		di_pan_detection_control_3_reg.pan_me_border_left_width = 2;
		di_pan_detection_control_3_reg.pan_me_border_right_width = 2;
		di_framesobel_statistic_Reg.hmc_vector_follow_pan_en = 1;

		/*sync aug demo platform, elieli 20131205*/
		/*di_pan_detection_control_2_reg.regValue = 0x800057c4;*/

		IoReg_ClearBits(DI_IM_DI_DUMMY_4_reg, _BIT4);
		if (source == VIP_QUALITY_CVBS_NTSC) {
			di_pan_detection_control_1_reg.pan_mc_odd_mv_pass_en = 0;
			/*di_pan_detection_control_1_reg.pan_me_condition_3_en = 1;*/
			/*di_pan_detection_control_1_reg.pan_me_condition_1_ratio = 11;*/
			/*di_pan_detection_control_1_reg.pan_me_condition_2_ratio = 13;*/
			di_pan_detection_control_3_reg.pan_me_border_left_width = 7;
			di_pan_detection_control_3_reg.pan_me_border_right_width = 7;
			IoReg_SetBits(DI_IM_DI_DUMMY_4_reg, _BIT4); /* eco item, always use pan vector*/
		} else if (source == VIP_QUALITY_CVBS_PAL) {
			di_pan_detection_control_1_reg.pan_mc_odd_mv_pass_en = 0;	/* 0;	*/ /* sync from aug demo platform, elieli 20131205*/
			/*di_pan_detection_control_1_reg.pan_me_condition_3_en = 1;*/
			/*di_pan_detection_control_1_reg.pan_me_condition_1_ratio = 12; */ /*8;    */ /* 12; 	*/ /* sync from aug demo platform, elieli 20131205*/
			/*di_pan_detection_control_1_reg.pan_me_condition_2_ratio = 13; */ /*16;   */ /* 13;	*/ /* sync from aug demo platform, elieli 20131205*/
			di_pan_detection_control_3_reg.pan_me_border_left_width = 11;
			di_pan_detection_control_3_reg.pan_me_border_right_width = 11;
			/*sync aug demo platform, elieli 20131205*/
			/*di_pan_detection_control_1_reg.regValue = 0x006b3fb9;*/
			IoReg_SetBits(DI_IM_DI_DUMMY_4_reg, _BIT4); /* eco item, always use pan vector*/
		}
#if 0
		else if (source == VIP_QUALITY_HDMI_1080I) {
			di_pan_detection_control_1_reg.pan_mc_odd_mv_pass_en = 1; 	  /* 0;	*/ /* sync from aug demo platform, elieli 20131205*/
			di_pan_detection_control_1_reg.pan_me_condition_3_en = 0;
			di_pan_detection_control_1_reg.pan_me_condition_1_ratio = 8;    /* 12; 	*/ /* sync from aug demo platform, elieli 20131205*/
			di_pan_detection_control_1_reg.pan_me_condition_2_ratio = 15;   /* 13;	*/ /* sync from aug demo platform, elieli 20131205*/
			im_di_pan_detection_statistic_8_reg.pan_mc_mv_continue_th = 15;
			di_pan_detection_control_1_reg.pan_en = 0;	/* turn off pan detection @ 1080i, elieli*/
			/*sync aug demo platform, elieli 20131205*/
			/*di_pan_detection_control_1_reg.regValue = 0x006b3fb9;*/
		}
#endif
		else {
			di_pan_detection_control_1_reg.pan_mc_odd_mv_pass_en = 1;
			/*di_pan_detection_control_1_reg.pan_me_condition_3_en = 0;*/
			/*di_pan_detection_control_1_reg.pan_me_condition_1_ratio = 8;*/
			/*di_pan_detection_control_1_reg.pan_me_condition_2_ratio = 14;*/
			IoReg_ClearBits(DI_IM_DI_DUMMY_4_reg, _BIT4);
		}
	} else {
		di_pan_detection_control_1_reg.pan_en = 0;
		di_framesobel_statistic_Reg.hmc_vector_follow_pan_en = 0;
	}


#endif

	IoReg_Write32(DI_IM_DI_PAN_DETECTION_CONTROL_1_reg, di_pan_detection_control_1_reg.regValue);
	IoReg_Write32(DI_IM_DI_PAN_DETECTION_CONTROL_2_reg, di_pan_detection_control_2_reg.regValue);
	IoReg_Write32(DI_IM_DI_PAN_DETECTION_CONTROL_3_reg, di_pan_detection_control_3_reg.regValue);
	IoReg_Write32(DI_IM_DI_FRAMESOBEL_STATISTIC_reg,  di_framesobel_statistic_Reg.regValue);
	IoReg_Write32(DI_IM_DI_PAN_DETECTION_STATISTIC_8_reg,  im_di_pan_detection_statistic_8_reg.regValue);

}

void drvif_color_ma_boundary_inter_mode(unsigned char bEnable)
{
	di_im_di_weave_window_control_RBUS im_di_weave_window_control_reg;

	im_di_weave_window_control_reg.regValue = IoReg_Read32(DI_IM_DI_WEAVE_WINDOW_CONTROL_reg);

	if (bEnable)
		im_di_weave_window_control_reg.boundary_inter_mode = 1;
	else
		im_di_weave_window_control_reg.boundary_inter_mode = 0;

	IoReg_Write32(DI_IM_DI_WEAVE_WINDOW_CONTROL_reg, im_di_weave_window_control_reg.regValue);
}

void drvif_color_ma_hmc_dynamic_threshold(unsigned char bEnable)
{
	di_im_di_framesobel_statistic_RBUS im_di_framesobel_statistic_reg;
	di_im_di_hmc_adjustable_RBUS im_di_hmc_adjustable_reg;

	im_di_framesobel_statistic_reg.regValue = IoReg_Read32(DI_IM_DI_FRAMESOBEL_STATISTIC_reg);
	im_di_hmc_adjustable_reg.regValue = IoReg_Read32(DI_IM_DI_HMC_ADJUSTABLE_reg);

	if (bEnable == 0) {
		im_di_framesobel_statistic_reg.hmc_dynamic_threshold_en = 0;
	} else {
		im_di_framesobel_statistic_reg.hmc_dynamic_threshold_en = 1;
		im_di_hmc_adjustable_reg.hmc_dynamic_threshold_min_clip = 0;
		im_di_framesobel_statistic_reg.hmc_dynamic_threshold_max_clip = 16;
		im_di_framesobel_statistic_reg.hmc_dynamic_threshold_bias = 16;
	}

	IoReg_Write32(DI_IM_DI_FRAMESOBEL_STATISTIC_reg, im_di_framesobel_statistic_reg.regValue);
	IoReg_Write32(DI_IM_DI_HMC_ADJUSTABLE_reg, im_di_hmc_adjustable_reg.regValue);
}

void drvif_color_ma_444_and_422_mode(unsigned char modeType, unsigned char boundaryType)
{
	di_im_di_dma_RBUS im_di_dma_reg;

	im_di_dma_reg.regValue = IoReg_Read32(DI_IM_DI_DMA_reg);

	if (modeType > 2)
		modeType = 0;

	if (boundaryType > 1)
		boundaryType = 0;

	/* modeType definition*/
	/*
	modeType                  0                                     1                               2
	444to422        drop no_crcb_delay            drop crcb_delay            interpolation
	422to444    interpolation no_crcb_delay   interpolation crcb_delay    duplication
	*/
	if (modeType == 0) { /*orginal default mode*/
		im_di_dma_reg.dma_444to422_drop = 1;
		im_di_dma_reg.dma_444to422_cr_dly_cb = 0;

		im_di_dma_reg.dma_422to444_duplicate = 0;
		im_di_dma_reg.dma_422to444_cr_dly_cb = 0;

		if (boundaryType == 0) /* orginal default mode */
			im_di_dma_reg.dma_422to444_boundary_duplicate = 0;
		else
			im_di_dma_reg.dma_422to444_boundary_duplicate = 1;
	} else if (modeType == 1) {
		im_di_dma_reg.dma_444to422_drop = 1;
		im_di_dma_reg.dma_444to422_cr_dly_cb = 1;

		im_di_dma_reg.dma_422to444_duplicate = 0;
		im_di_dma_reg.dma_422to444_cr_dly_cb = 1;

	} else if (modeType == 2) {
		im_di_dma_reg.dma_444to422_drop = 0;

		im_di_dma_reg.dma_422to444_duplicate = 1;
	}

	IoReg_Write32(DI_IM_DI_DMA_reg, im_di_dma_reg.regValue);
}

void drvif_color_ma_444to422lowpass_duplicate(unsigned char bEnable)
{
	di_im_di_dma_RBUS im_di_dma_reg;

	im_di_dma_reg.regValue = IoReg_Read32(DI_IM_DI_DMA_reg);

	if (bEnable == 0) /* orginal default mode */
		im_di_dma_reg.dma_444to422_lowpass_boundary_duplicate = 0;
	else
		im_di_dma_reg.dma_444to422_lowpass_boundary_duplicate = 1;

	IoReg_Write32(DI_IM_DI_DMA_reg, im_di_dma_reg.regValue);
}

void drvif_color_ma_HD_follow_pan(unsigned char bEnable)
{
	di_im_di_framesobel_statistic_RBUS im_di_framesobel_statistic_reg;

	im_di_framesobel_statistic_reg.regValue = IoReg_Read32(DI_IM_DI_FRAMESOBEL_STATISTIC_reg);

	if (bEnable == 0)
		im_di_framesobel_statistic_reg.hmc_vector_follow_pan_en = 0;
	else
		im_di_framesobel_statistic_reg.hmc_vector_follow_pan_en = 1;

	IoReg_Write32(DI_IM_DI_FRAMESOBEL_STATISTIC_reg, im_di_framesobel_statistic_reg.regValue);
}

void drvif_color_smd_table(DRV_di_smd_table_t *ptr)
{
	di_di_smd_control_candidatelist_RBUS init_smd_control_candidatelist_reg;
	di_di_smd_gmvcoeff3_RBUS init_di_smd_gmvcoeff3_reg;
	di_di_smd_pan1_RBUS init_di_smd_pan1_reg;
	di_di_smd_pan2_RBUS init_di_smd_pan2_reg;
	di_di_smd_pan3_RBUS init_di_smd_pan3_reg;
	di_di_smd_additionalcoeff1_RBUS init_di_smd_additionalcoeff1_reg;
	di_di_smd_additionalcoeff2_RBUS init_di_smd_additionalcoeff2_reg;
	di_di_smd_additionalcoeff3_RBUS init_di_smd_additionalcoeff3_reg;
	di_di_smd_v4highfreq_RBUS init_di_smd_v4highfreq_reg;
	di_di_gst_ctrl_RBUS init_di_gst_ctrl_reg;
	di_di_gst_enter_origsadcheck_RBUS init_di_gst_enter_origsadcheck_reg;
	di_di_gst_outofrangecheck_RBUS init_di_gst_outofrangecheck_reg;
	di_di_gst_freqnonmatchcheck_RBUS init_di_gst_freqnonmatchcheck_reg;
	di_di_smd_candidatelimitsad_RBUS init_di_smd_candidatelimitsad_reg;
	/* set waterflag para.*/
	di_di_smd_waterflag_ctr1_RBUS di_di_smd_waterflag_ctr1;
	di_di_smd_waterflag_ctr2_RBUS di_di_smd_waterflag_ctr2;
	di_di_smd_waterflag_ctr3_RBUS di_di_smd_waterflag_ctr3;
	/* set FMV pan para.*/
	di_di_smd_hardwarepan_modify1_RBUS di_di_smd_hardwarepan_modify1;
	di_di_smd_sampling_gmvc_RBUS di_di_smd_sampling_gmvc;
	di_di_smd_sampling_gmvb_RBUS di_di_smd_sampling_gmvb;
	di_di_gst_compensate_RBUS di_di_gst_compensate;
	di_di_gst_fmv_pan_coeff1_RBUS di_di_gst_fmv_pan_coeff1;
	di_di_gst_fmv_pan_coeff2_RBUS di_di_gst_fmv_pan_coeff2;

	/* ylchen 150617*/
	di_di_smd_waterflow_teeth_ctr_RBUS					di_di_smd_waterflow_teeth_ctr;
	di_di_smd_ma_mc_weight_ctr_RBUS							di_di_smd_ma_mc_weight_ctr;
	di_di_smd_diag_edge_protect_ctr_RBUS				di_di_smd_diag_edge_protect_ctr;
	di_di_smd_slow_motion_handle1_RBUS					di_di_smd_slow_motion_handle1;
	di_di_smd_slow_motion_handle2_RBUS					di_di_smd_slow_motion_handle2;
	/* end tlchen 150617*/

	// chen 160602
//	di_di_smd_slow_motion_handle3_RBUS					di_di_smd_slow_motion_handle3;
//	di_di_smd_gmv_penalty_ctrl_RBUS							di_di_smd_gmv_penalty_ctrl;
//	di_di_smd_resurrect_ctrl_RBUS								di_di_smd_resurrect_ctrl;
//	di_di_smd_gmv_penalty_ctrl2_RBUS						di_di_smd_gmv_penalty_ctrl2;

	// end chen 160602


	if (!ptr)
		return;

	init_smd_control_candidatelist_reg.regValue = IoReg_Read32(DI_DI_SMD_Control_CandidateList_reg);
	init_di_smd_gmvcoeff3_reg.regValue = IoReg_Read32(DI_DI_SMD_GMVCoeff3_reg);
	init_di_smd_pan1_reg.regValue = IoReg_Read32(DI_DI_SMD_Pan1_reg);
	init_di_smd_pan2_reg.regValue = IoReg_Read32(DI_DI_SMD_Pan2_reg);
	init_di_smd_pan3_reg.regValue = IoReg_Read32(DI_DI_SMD_Pan3_reg);
	init_di_smd_additionalcoeff1_reg.regValue = IoReg_Read32(DI_DI_SMD_AdditionalCoeff1_reg);
	init_di_smd_additionalcoeff2_reg.regValue = IoReg_Read32(DI_DI_SMD_AdditionalCoeff2_reg);
	init_di_smd_additionalcoeff3_reg.regValue = IoReg_Read32(DI_DI_SMD_AdditionalCoeff3_reg);
	init_di_smd_v4highfreq_reg.regValue = IoReg_Read32(DI_DI_SMD_V4HighFreq_reg);
	init_di_gst_ctrl_reg.regValue = IoReg_Read32(DI_DI_GST_Ctrl_reg);
	init_di_gst_enter_origsadcheck_reg.regValue = IoReg_Read32(DI_DI_GST_Enter_origSADCheck_reg);
	init_di_gst_freqnonmatchcheck_reg.regValue = IoReg_Read32(DI_DI_GST_FreqNonMatchCheck_reg);
	init_di_gst_outofrangecheck_reg.regValue = IoReg_Read32(DI_DI_GST_OutOfRangeCheck_reg);
	init_di_smd_candidatelimitsad_reg.regValue = IoReg_Read32(DI_DI_SMD_CandidateLimitSAD_reg);
	di_di_smd_waterflag_ctr1.regValue = IoReg_Read32(DI_DI_SMD_WaterFlag_Ctr1_reg);
	di_di_smd_waterflag_ctr2.regValue = IoReg_Read32(DI_DI_SMD_WaterFlag_Ctr2_reg);
	di_di_smd_waterflag_ctr3.regValue = IoReg_Read32(DI_DI_SMD_WaterFlag_Ctr3_reg);
	di_di_smd_hardwarepan_modify1.regValue = IoReg_Read32(DI_DI_SMD_HardwarePan_Modify1_reg);
	di_di_smd_sampling_gmvc.regValue = IoReg_Read32(DI_DI_SMD_Sampling_GMVc_reg);
	di_di_smd_sampling_gmvb.regValue = IoReg_Read32(DI_DI_SMD_Sampling_GMVb_reg);
	di_di_gst_compensate.regValue = IoReg_Read32(DI_DI_GST_Compensate_reg);
	di_di_gst_fmv_pan_coeff1.regValue = IoReg_Read32(DI_DI_GST_FMV_Pan_Coeff1_reg);
	di_di_gst_fmv_pan_coeff2.regValue = IoReg_Read32(DI_DI_GST_FMV_Pan_Coeff2_reg);


	/* ylchen 150617*/
	di_di_smd_waterflow_teeth_ctr.regValue			= IoReg_Read32(DI_DI_SMD_WaterFlow_Teeth_Ctr_reg);
	di_di_smd_ma_mc_weight_ctr.regValue					= IoReg_Read32(DI_DI_SMD_MA_MC_Weight_Ctr_reg);
	di_di_smd_diag_edge_protect_ctr.regValue		= IoReg_Read32(DI_DI_SMD_Diag_Edge_Protect_Ctr_reg);
	di_di_smd_slow_motion_handle1.regValue			= IoReg_Read32(DI_DI_SMD_Slow_Motion_handle1_reg);
	di_di_smd_slow_motion_handle2.regValue			= IoReg_Read32(DI_DI_SMD_Slow_Motion_handle2_reg);
	/* end ylchen 150617*/

	// chen 160602
//	di_di_smd_slow_motion_handle3.regValue			= IoReg_Read32(DI_DI_SMD_Slow_Motion_handle3_reg);
//	di_di_smd_gmv_penalty_ctrl.regValue			= IoReg_Read32(DI_DI_SMD_GMV_Penalty_Ctrl_reg);
//	di_di_smd_resurrect_ctrl.regValue						= IoReg_Read32(DI_DI_SMD_Resurrect_Ctrl_reg);
//	di_di_smd_gmv_penalty_ctrl2.regValue			= IoReg_Read32(DI_DI_SMD_GMV_Penalty_Ctrl2_reg);
	di_di_smd_hardwarepan_modify1.regValue			= IoReg_Read32(DI_DI_SMD_HardwarePan_Modify1_reg);
	di_di_smd_waterflag_ctr3.regValue			= IoReg_Read32(DI_DI_SMD_WaterFlag_Ctr3_reg);
//	di_di_smd_gmv_penalty_ctrl.regValue			= IoReg_Read32(DI_DI_SMD_GMV_Penalty_Ctrl_reg);
	// end chen 160602


	init_smd_control_candidatelist_reg.smd_en = ptr->smd_control.en;
	init_smd_control_candidatelist_reg.smd_upperbound_sad_forjudgemv = ptr->smd_control.upperbound_sad;

	init_di_smd_gmvcoeff3_reg.smd_firmwaremv_x = ptr->smd_gmvcoeff3.mv_x;
	init_di_smd_gmvcoeff3_reg.smd_firmwaremv_y = ptr->smd_gmvcoeff3.mv_y;

	init_di_smd_pan1_reg.smd_apply_result_mode = ptr->smd_pan.apply_result_mode;
	init_di_smd_pan1_reg.smd_firmware_pan = ptr->smd_pan.firmware_pan;
	init_di_smd_pan1_reg.smd_searchmv_apply = ptr->smd_pan.searchmv_apply;
	init_di_smd_pan1_reg.smd_hardware_pan_en = ptr->smd_pan.hardware_pan_en;
	init_di_smd_pan1_reg.smd_vpan_en = ptr->smd_pan.vpan_en;
	init_di_smd_pan1_reg.smd_searchmv_apply_sad_th = ptr->smd_pan.searchmv_apply_sad_th;
	init_di_smd_pan1_reg.smd_firmware_pan_sad_th = ptr->smd_pan.firmware_pan_sad_th;
	init_di_smd_pan1_reg.smd_vpan_work_th = ptr->smd_pan.vpan_work_th;
	init_di_smd_pan1_reg.smd_vpan_jump_out = ptr->smd_pan.vpan_jump_out;
	init_di_smd_pan1_reg.smd_vpan_upper_bound = ptr->smd_pan.vpan_upper_bound;
	init_di_smd_pan2_reg.smd_enter_pan_ctr_th = ptr->smd_pan.enter_pan_ctr_th;
	init_di_smd_pan2_reg.smd_vpan_gmv1_pixel = ptr->smd_pan.vpan_gmv1_pixel;
	init_di_smd_pan2_reg.smd_vpan_total_pixel = ptr->smd_pan.vpan_total_pixel;
	init_di_smd_pan2_reg.smd_gmv3_th = ptr->smd_pan.gmv3_th;
	init_di_smd_pan3_reg.smd_addctr_gmv1_pixelth1 = ptr->smd_pan.addctr_gmv1_pixelth1;
	init_di_smd_pan3_reg.smd_addctr_gmv1_pixelth2 = ptr->smd_pan.addctr_gmv1_pixelth2;
	init_di_smd_pan3_reg.smd_search_apply_th = ptr->smd_pan.search_apply_th;
	init_di_smd_pan3_reg.smd_rebuild_pan_ctr = ptr->smd_pan.rebuild_pan_ctr;

	init_di_smd_additionalcoeff1_reg.smd_full_search_mode = ptr->smd_additionalcoeff.full_search_mode;
	init_di_smd_additionalcoeff1_reg.smd_intra_en = ptr->smd_additionalcoeff.intra_en;
	init_di_smd_additionalcoeff1_reg.smd_colony_drop_en = ptr->smd_additionalcoeff.colony_drop_en;
	init_di_smd_additionalcoeff1_reg.smd_colony_expanse_en = ptr->smd_additionalcoeff.colony_expanse_en;
	init_di_smd_additionalcoeff1_reg.smd_colony_expanse_type = ptr->smd_additionalcoeff.colony_expanse_type;
	init_di_smd_additionalcoeff1_reg.smd_result_en = ptr->smd_additionalcoeff.result_en;
	init_di_smd_additionalcoeff1_reg.smd_curr_teeth_offset_c = ptr->smd_additionalcoeff.curr_teeth_offset_c;
	init_di_smd_additionalcoeff1_reg.smd_curr_teeth_gain_c = ptr->smd_additionalcoeff.curr_teeth_gain_c;
	init_di_smd_additionalcoeff1_reg.smd_expanse_range = ptr->smd_additionalcoeff.expanse_range;
	init_di_smd_additionalcoeff1_reg.smd_left_weave_blend = ptr->smd_additionalcoeff.left_weave_blend;
	init_di_smd_additionalcoeff1_reg.smd_right_weave_blend = ptr->smd_additionalcoeff.right_weave_blend;
	init_di_smd_additionalcoeff2_reg.smd_image_boundary_height = ptr->smd_additionalcoeff.image_boundary_height;
	init_di_smd_additionalcoeff2_reg.smd_image_boundary_width = ptr->smd_additionalcoeff.image_boundary_width;
	init_di_smd_additionalcoeff2_reg.smd_search_gmv_offset = ptr->smd_additionalcoeff.search_gmv_offset;
	init_di_smd_additionalcoeff2_reg.smd_search_gmv_gain = ptr->smd_additionalcoeff.search_gmv_gain;
	init_di_smd_additionalcoeff2_reg.smd_left_us_blend = ptr->smd_additionalcoeff.left_us_blend;
	init_di_smd_additionalcoeff2_reg.smd_right_us_blend = ptr->smd_additionalcoeff.right_us_blend;
	init_di_smd_additionalcoeff3_reg.smd_sm_flag_control = ptr->smd_additionalcoeff.sm_flag_control;
	init_di_smd_additionalcoeff3_reg.smd_zm_flag_control = ptr->smd_additionalcoeff.zm_flag_control;
	init_di_smd_additionalcoeff3_reg.smd_left_us_range = ptr->smd_additionalcoeff.left_us_range;
	init_di_smd_additionalcoeff3_reg.smd_left_us_th = ptr->smd_additionalcoeff.left_us_th;
	init_di_smd_additionalcoeff3_reg.smd_right_us_range = ptr->smd_additionalcoeff.right_us_range;
	init_di_smd_additionalcoeff3_reg.smd_right_us_th = ptr->smd_additionalcoeff.right_us_th;

	init_di_smd_v4highfreq_reg.smd_patterngenmode = ptr->smd_v4highfreq.patterngenmode;
	init_di_smd_v4highfreq_reg.smd_v4highfreqeffect = ptr->smd_v4highfreq.v4highfreqeffect;
	init_di_smd_v4highfreq_reg.smd_v4highfreqth2 = ptr->smd_v4highfreq.v4highfreqth2;
	init_di_smd_v4highfreq_reg.smd_v4highfreqth1 = ptr->smd_v4highfreq.v4highfreqth1;

	init_di_gst_ctrl_reg.gst_en = ptr->gst_ctrl.en;
	init_di_gst_ctrl_reg.gst_pregmv_needstable = ptr->gst_ctrl.pregmv_needstable;
	init_di_gst_ctrl_reg.gst_replace_sad = ptr->gst_ctrl.replace_sad;
	init_di_gst_ctrl_reg.gst_search_zmv_offset = ptr->gst_ctrl.search_zmv_offset;
	init_di_gst_ctrl_reg.gst_fmv2weave_p = ptr->gst_ctrl.fmv2weave_p;
	init_di_gst_ctrl_reg.gst_fmv2weave_n = ptr->gst_ctrl.fmv2weave_n;

	init_di_gst_enter_origsadcheck_reg.gst_enter_origsad_lowth = ptr->gst_check.enter_origsad_lowth;
	init_di_gst_enter_origsadcheck_reg.gst_enter_origsad_offset = ptr->gst_check.enter_origsad_offset;
	init_di_gst_outofrangecheck_reg.gst_outofrange_check = ptr->gst_check.outofrange_check;
	init_di_gst_outofrangecheck_reg.gst_outofrange_origsad = ptr->gst_check.outofrange_origsad;
	init_di_gst_outofrangecheck_reg.gst_outofrange_fracsadlowth = ptr->gst_check.outofrange_fracsadlowth;
	init_di_gst_outofrangecheck_reg.gst_outofrange_fracsad_offset = ptr->gst_check.outofrange_fracsad_offset;
	init_di_gst_freqnonmatchcheck_reg.gst_freqnonmatch_check = ptr->gst_check.freqnonmatch_check;
	init_di_gst_freqnonmatchcheck_reg.gst_freqnonmatch_origsad = ptr->gst_check.freqnonmatch_origsad;
	init_di_gst_freqnonmatchcheck_reg.gst_freqnonmatch_fracsad_lowth = ptr->gst_check.freqnonmatch_fracsad_lowth;
	init_di_gst_freqnonmatchcheck_reg.gst_freqnonmatch_fracsad_offset = ptr->gst_check.freqnonmatch_fracsad_offset;

	init_di_smd_candidatelimitsad_reg.smd_gmv_sad_th = ptr->smd_limitsad.gmv_sad_th;
	init_di_smd_candidatelimitsad_reg.smd_gmv_sad_max = ptr->smd_limitsad.gmv_sad_max;
	init_di_smd_candidatelimitsad_reg.smd_localmv_sad_max = ptr->smd_limitsad.localmv_sad_max;
	init_di_smd_candidatelimitsad_reg.smd_spatialmv_sad_max = ptr->smd_limitsad.spatialmv_sad_max;

	di_di_smd_waterflag_ctr1.smd_water_en = ptr->Smd_Waterflag.smd_water_en;
	di_di_smd_waterflag_ctr1.smd_water_pan_disable = ptr->Smd_Waterflag.smd_water_pan_disable;
	di_di_smd_waterflag_ctr1.smd_water_result = ptr->Smd_Waterflag.smd_water_result;
	di_di_smd_waterflag_ctr1.smd_water_gain = ptr->Smd_Waterflag.smd_water_gain;
	di_di_smd_waterflag_ctr1.smd_water_offset = ptr->Smd_Waterflag.smd_water_offset;
	di_di_smd_waterflag_ctr1.smd_water_modeth = ptr->Smd_Waterflag.smd_water_modeth;

	di_di_smd_waterflag_ctr2.smd_water_uv_offset = ptr->Smd_Waterflag.smd_water_uv_offset;
	di_di_smd_waterflag_ctr2.smd_water_intradiff_th = ptr->Smd_Waterflag.smd_water_intradiff_th;
	di_di_smd_waterflag_ctr2.smd_water_minteethy = ptr->Smd_Waterflag.smd_water_minteethy;
	di_di_smd_waterflag_ctr2.smd_water_teeth = ptr->Smd_Waterflag.smd_water_teeth;

	di_di_smd_waterflag_ctr3.smd_elseintra_en = ptr->Smd_Waterflag.smd_elseintra_en;
	di_di_smd_waterflag_ctr3.smd_stillsad_th = ptr->Smd_Waterflag.smd_stillsad_th;
	di_di_smd_waterflag_ctr3.smd_stillsad_max = ptr->Smd_Waterflag.smd_stillsad_max;
	di_di_smd_waterflag_ctr3.smd_water_avgy_offset = ptr->Smd_Waterflag.smd_water_avgy_offset;
	di_di_smd_waterflag_ctr3.smd_water_avgy_lowbound = ptr->Smd_Waterflag.smd_water_avgy_lowbound;

	di_di_smd_hardwarepan_modify1.smd_searchmvapply_ctr = ptr->Smd_Pan_modify.smd_searchmvapply_ctr;
	di_di_smd_hardwarepan_modify1.smd_firmwarepan_sadmax = ptr->Smd_Pan_modify.smd_firmwarepan_sadmax;
	di_di_smd_hardwarepan_modify1.smd_gmvb_sadmin_th = ptr->Smd_Pan_modify.smd_gmvb_sadmin_th;
	di_di_smd_hardwarepan_modify1.smd_streammv_gmv_diff = ptr->Smd_Pan_modify.smd_streammv_gmv_diff;
	di_di_smd_hardwarepan_modify1.smd_hardwarepan_firststep = ptr->Smd_Pan_modify.smd_hardwarepan_firststep;


	di_di_smd_sampling_gmvc.smd_pg_minsad_th = ptr->Smd_samp_Gmv.smd_pg_minsad_th;
	di_di_smd_sampling_gmvc.smd_pg_messlevel_th = ptr->Smd_samp_Gmv.smd_pg_messlevel_th;
	di_di_smd_sampling_gmvc.smd_pg_diffsad_th = ptr->Smd_samp_Gmv.smd_pg_diffsad_th;
	di_di_smd_sampling_gmvc.smd_close2gmv_mvselect = ptr->Smd_samp_Gmv.smd_close2gmv_mvselect;
	di_di_smd_sampling_gmvb.smd_hmin_sad_ctr = ptr->Smd_samp_Gmv.smd_hmin_sad_ctr;
	di_di_smd_sampling_gmvb.smd_vmin_sad_ctr = ptr->Smd_samp_Gmv.smd_vmin_sad_ctr;
	di_di_smd_sampling_gmvb.smd_pg_close2gmv = ptr->Smd_samp_Gmv.smd_pg_close2gmv;
	di_di_smd_sampling_gmvb.smd_close2gmv_edgectr = ptr->Smd_samp_Gmv.smd_close2gmv_edgectr;
	di_di_smd_sampling_gmvb.smd_close2gmv_minctr = ptr->Smd_samp_Gmv.smd_close2gmv_minctr;

	di_di_gst_compensate.gst_subpixel_firmwarepan_fmv1 = ptr->Smd_Gst_Compensate.gst_subpixel_firmwarepan_fmv1;
	di_di_gst_compensate.gst_subpixel_firmwarepan_fmv2 = ptr->Smd_Gst_Compensate.gst_subpixel_firmwarepan_fmv2;
	di_di_gst_compensate.gst_subpixel_firmwarepan = ptr->Smd_Gst_Compensate.gst_subpixel_firmwarepan;
	di_di_gst_compensate.gst_blend_weight = ptr->Smd_Gst_Compensate.gst_blend_weight;
	di_di_gst_compensate.gst_compensate_blending_en = ptr->Smd_Gst_Compensate.gst_compensate_blending_en;
	di_di_gst_compensate.gst_compensate_fmv8_en = ptr->Smd_Gst_Compensate.gst_compensate_fmv8_en;
	di_di_gst_compensate.gst_compensate_fmv7_en = ptr->Smd_Gst_Compensate.gst_compensate_fmv7_en;
	di_di_gst_compensate.gst_compensate_fmv6_en = ptr->Smd_Gst_Compensate.gst_compensate_fmv6_en;
	di_di_gst_compensate.gst_compensate_fmv5_en = ptr->Smd_Gst_Compensate.gst_compensate_fmv5_en;
	di_di_gst_compensate.gst_compensate_fmv4_en = ptr->Smd_Gst_Compensate.gst_compensate_fmv4_en;
	di_di_gst_compensate.gst_compensate_fmv3_en = ptr->Smd_Gst_Compensate.gst_compensate_fmv3_en;
	di_di_gst_compensate.gst_compensate_fmv2_en = ptr->Smd_Gst_Compensate.gst_compensate_fmv2_en;
	di_di_gst_compensate.gst_compensate_fmv1_en = ptr->Smd_Gst_Compensate.gst_compensate_fmv1_en;
	di_di_gst_compensate.gst_compensate_fmv0_en = ptr->Smd_Gst_Compensate.gst_compensate_fmv0_en;
	di_di_gst_compensate.gst_pg_highpriority = ptr->Smd_Gst_Compensate.gst_pg_highpriority;
	di_di_gst_compensate.gst_integerpan_highpriority = ptr->Smd_Gst_Compensate.gst_integerpan_highpriority;
	di_di_gst_compensate.gst_subpixel_rlv2intra_en = ptr->Smd_Gst_Compensate.gst_subpixel_rlv2intra_en;
	di_di_gst_compensate.gst_subpixel_hardwarepan_en = ptr->Smd_Gst_Compensate.gst_subpixel_hardwarepan_en;
	di_di_gst_compensate.gst_debug_subpixel_pan = ptr->Smd_Gst_Compensate.gst_debug_subpixel_pan;
	di_di_gst_compensate.gst_subpixel_compensate_en = ptr->Smd_Gst_Compensate.gst_subpixel_compensate_en;

	di_di_gst_fmv_pan_coeff1.gst_subpixel_firmwarepan_sadmax = ptr->Smd_fmv_pan_coeff.gst_subpixel_firmwarepan_sadmax;
	di_di_gst_fmv_pan_coeff1.gst_subpixel_firmwarepan_sadmin  = ptr->Smd_fmv_pan_coeff.gst_subpixel_firmwarepan_sadmin;
	di_di_gst_fmv_pan_coeff1.gst_subpixel_pan_ratio = ptr->Smd_fmv_pan_coeff.gst_subpixel_pan_ratio;
	di_di_gst_fmv_pan_coeff2.gst_quantizeddiff_gain = ptr->Smd_fmv_pan_coeff.gst_quantizeddiff_gain;
	di_di_gst_fmv_pan_coeff2.gst_quantizeddiff_offset = ptr->Smd_fmv_pan_coeff.gst_quantizeddiff_offset;
	di_di_gst_fmv_pan_coeff2.gst_maxfmv_diff_th = ptr->Smd_fmv_pan_coeff.gst_maxfmv_diff_th;
	di_di_gst_fmv_pan_coeff2.gst_fmvhist_sad_diff  = ptr->Smd_fmv_pan_coeff.gst_fmvhist_sad_diff;


	/* ylchen 150617 */
	di_di_smd_slow_motion_handle1.smd_outofrange_content_new		=ptr->Smd_MCDI_control.smd_outofrange_content_new;
	di_di_smd_slow_motion_handle1.smd_acc_smd_en								=ptr->Smd_MCDI_control.smd_acc_smd_en;
	di_di_smd_slow_motion_handle1.smd_spatialfreqnomatch_off		=ptr->Smd_MCDI_control.smd_spatialfreqnomatch_off;
	di_di_smd_slow_motion_handle1.smd_linecontinous_new_condition=ptr->Smd_MCDI_control.smd_linecontinous_new_condition;
	di_di_smd_slow_motion_handle1.smd_sawtooth_condition_select	=ptr->Smd_MCDI_control.smd_sawtooth_condition_select;
	di_di_smd_slow_motion_handle1.smd_weave_dynamic							=ptr->Smd_MCDI_control.smd_weave_dynamic;
	di_di_smd_sampling_gmvc.smd_close2gmv_mvselect							=ptr->Smd_MCDI_control.smd_close2gmv_mvselect;
	di_di_smd_slow_motion_handle1.smd_resurrectsmallwindownum2	=ptr->Smd_MCDI_control.smd_resurrectsmallwindownum2;
	di_di_smd_slow_motion_handle2.smd_resurrectminsadth2				=ptr->Smd_MCDI_control.smd_resurrectminsadth2;
	di_di_smd_slow_motion_handle2.smd_reliablerangesadth2				=ptr->Smd_MCDI_control.smd_reliablerangesadth2;
	init_di_smd_pan1_reg.smd_pg_no_pixel_ctr_en												=ptr->Smd_MCDI_control.smd_pg_no_pixel_ctr_en;
	init_di_smd_gmvcoeff3_reg.smd_gmv_old_method											=ptr->Smd_MCDI_control.smd_gmv_old_method;


	di_di_smd_slow_motion_handle1.gst_min_sad_nolimit_en				=ptr->Smd_SMD_control.gst_min_sad_nolimit_en;
	di_di_smd_slow_motion_handle1.gst_gst_static_disable				=ptr->Smd_SMD_control.gst_gst_static_disable;
	di_di_smd_slow_motion_handle1.gst_min_sad_compare_diable		=ptr->Smd_SMD_control.gst_min_sad_compare_diable;
	di_di_smd_slow_motion_handle2.gst_mv_limit									=ptr->Smd_SMD_control.gst_mv_limit;

	di_di_smd_waterflow_teeth_ctr.smd_waterflow_protect_en			=ptr->Smd_Waterflow_teeth_control.smd_waterflow_protect_en;
	di_di_smd_waterflow_teeth_ctr.smd_currteethgain_wf					=ptr->Smd_Waterflow_teeth_control.smd_currteethgain_wf;
	di_di_smd_waterflow_teeth_ctr.smd_totalteethoffset_wf				=ptr->Smd_Waterflow_teeth_control.smd_totalteethoffset_wf;
	di_di_smd_waterflow_teeth_ctr.smd_compensate_teeth_th_wf		=ptr->Smd_Waterflow_teeth_control.smd_compensate_teeth_th_wf;
	di_di_smd_waterflow_teeth_ctr.smd_min_total_th_wf						=ptr->Smd_Waterflow_teeth_control.smd_min_total_th_wf;
	di_di_smd_waterflow_teeth_ctr.smd_sawtooth_count_th_wf			=ptr->Smd_Waterflow_teeth_control.smd_sawtooth_count_th_wf;

	di_di_smd_ma_mc_weight_ctr.smd_outofrange_lpf_en						=ptr->Smd_MA_MC_Blending_control.smd_outofrange_lpf_en;
	di_di_smd_ma_mc_weight_ctr.smd_smd_blend_lpf_en							=ptr->Smd_MA_MC_Blending_control.smd_smd_blend_lpf_en;
	di_di_smd_ma_mc_weight_ctr.smd_smd_blend_clamp_en						=ptr->Smd_MA_MC_Blending_control.smd_smd_blend_clamp_en;
	di_di_smd_ma_mc_weight_ctr.smd_spatial_mv_diff_weight_en		=ptr->Smd_MA_MC_Blending_control.smd_spatial_mv_diff_weight_en;
	di_di_smd_slow_motion_handle1.smd_weight_lpf_select					=ptr->Smd_MA_MC_Blending_control.smd_weight_lpf_select;
	di_di_smd_ma_mc_weight_ctr.smd_odd_mvy_ma_out_select				=ptr->Smd_MA_MC_Blending_control.smd_odd_mvy_ma_out_select;
	di_di_smd_ma_mc_weight_ctr.smd_spatial_mv_diff_coring				=ptr->Smd_MA_MC_Blending_control.smd_spatial_mv_diff_coring;
	di_di_smd_ma_mc_weight_ctr.smd_spatial_mv_diff_gain					=ptr->Smd_MA_MC_Blending_control.smd_spatial_mv_diff_gain;

	di_di_smd_diag_edge_protect_ctr.smd_mcdi2madi_en						=ptr->Smd_diag_edge_control.smd_mcdi2madi_en;
	di_di_smd_diag_edge_protect_ctr.smd_mcdi2madi_v_pan_new_en	=ptr->Smd_diag_edge_control.smd_mcdi2madi_v_pan_new_en;
	di_di_smd_diag_edge_protect_ctr.smd_intra_weight_method			=ptr->Smd_diag_edge_control.smd_intra_weight_method;
	di_di_smd_diag_edge_protect_ctr.smd_intra_weight_method_vpan=ptr->Smd_diag_edge_control.smd_intra_weight_method_vpan;
	di_di_smd_diag_edge_protect_ctr.smd_diag_count_th						=ptr->Smd_diag_edge_control.smd_diag_count_th;
	/* end ylchen 150617 */

	// chen 160602
		di_di_smd_ma_mc_weight_ctr.smd_search_range_limit_en 		=ptr->Smd_MCDI_control.smd_search_range_limit_en;
//		di_di_smd_slow_motion_handle3.smd_sadwindow_select					=ptr->Smd_MCDI_control.smd_sadwindow_select;
//		di_di_smd_slow_motion_handle3.smd_hd_zero_mv_sad_select 		=ptr->Smd_MCDI_control.smd_hd_zero_mv_sad_select;
//		di_di_smd_slow_motion_handle3.smd_field_diff_clamp					=ptr->Smd_MCDI_control.smd_field_diff_clamp;
//		di_di_smd_slow_motion_handle3.smd_messlevel_vgain						=ptr->Smd_MCDI_control.smd_messlevel_vgain;
//		di_di_smd_slow_motion_handle3.smd_messlevel_select					=ptr->Smd_MCDI_control.smd_messlevel_select;
		// end chen 160602


			// chen 160602
//			di_di_smd_gmv_penalty_ctrl.smd_fmv_gmv_penalty_en						=ptr->Smd_SMD_control.smd_fmv_gmv_penalty_en;
//			di_di_smd_gmv_penalty_ctrl.smd_notonly_zero_gmv 						=ptr->Smd_SMD_control.smd_notonly_zero_gmv;
//			di_di_smd_gmv_penalty_ctrl.smd_messlevel_th 								=ptr->Smd_SMD_control.smd_messlevel_th;
//			di_di_smd_gmv_penalty_ctrl.smd_messlevel_gain_slope 				=ptr->Smd_SMD_control.smd_messlevel_gain_slope;
		// end chen 160602

		// chen 160602
//			di_di_smd_slow_motion_handle1.smd_mv_pixel_acc_max_th				=ptr->Smd_MV_accumulate.smd_mv_pixel_acc_max_th;
//			di_di_smd_slow_motion_handle1.smd_mv_pixel_acc_th						=ptr->Smd_MV_accumulate.smd_mv_pixel_acc_th;
//			di_di_smd_slow_motion_handle1.smd_mv_pixel_acc_th2					=ptr->Smd_MV_accumulate.smd_mv_pixel_acc_th2;
//			di_di_smd_slow_motion_handle2.smd_mv_pixel_acc_th3					=ptr->Smd_MV_accumulate.smd_mv_pixel_acc_th3;
//			di_di_smd_resurrect_ctrl.smd_mv_pixel_acc_th4								=ptr->Smd_MV_accumulate.smd_mv_pixel_acc_th4;


//			di_di_smd_gmv_penalty_ctrl2.smd_gmv_penalty_mess_gain_en		=ptr->Smd_GMV_Control.smd_gmv_penalty_mess_gain_en;
//			di_di_smd_gmv_penalty_ctrl2.smd_gmv_only_teeth_mess_gain_en =ptr->Smd_GMV_Control.smd_gmv_only_teeth_mess_gain_en;
//			di_di_smd_gmv_penalty_ctrl2.smd_gmv_penalty_clamp_en				=ptr->Smd_GMV_Control.smd_gmv_penalty_clamp_en;
//			di_di_smd_sampling_gmvc.smd_close2gmv_fw_en 								=ptr->Smd_GMV_Control.smd_close2gmv_fw_en;
//			di_di_smd_gmv_penalty_ctrl2.smd_messlevel_field_diff				=ptr->Smd_GMV_Control.smd_messlevel_field_diff;
//			di_di_smd_gmv_penalty_ctrl2.smd_gmv_clamp										=ptr->Smd_GMV_Control.smd_gmv_clamp;
//			di_di_smd_hardwarepan_modify1.smd_fw_gmvx										=ptr->Smd_GMV_Control.smd_fw_gmvx;
//			di_di_smd_waterflag_ctr3.smd_fw_gmvy												=ptr->Smd_GMV_Control.smd_fw_gmvy;
//			di_di_smd_gmv_penalty_ctrl.smd_gmv_candidate_method 				=ptr->Smd_GMV_Control.smd_gmv_candidate_method;
//			di_di_smd_slow_motion_handle3.smd_mv_value_hist_method			=ptr->Smd_GMV_Control.smd_mv_value_hist_method;
//			di_di_smd_gmv_penalty_ctrl2.smd_gmv_sad_select							=ptr->Smd_GMV_Control.smd_gmv_sad_select;


//			di_di_smd_slow_motion_handle2.smd_messlevel_gain						=ptr->Smd_Outofrange_Control.smd_messlevel_gain;
//			di_di_smd_slow_motion_handle1.smd_teeth_value_select				=ptr->Smd_Outofrange_Control.smd_teeth_value_select;
//			di_di_smd_slow_motion_handle1.smd_mess_conditionoff 				=ptr->Smd_Outofrange_Control.smd_mess_conditionoff;
//			di_di_smd_slow_motion_handle1.smd_outrange_teeth_select 		=ptr->Smd_Outofrange_Control.smd_outrange_teeth_select;
//			di_di_smd_slow_motion_handle3.smd_outrange_field_diff_th		=ptr->Smd_Outofrange_Control.smd_outrange_field_diff_th;
//			di_di_smd_slow_motion_handle2.smd_messlevel_gain2						=ptr->Smd_Outofrange_Control.smd_messlevel_gain2;

//			di_di_smd_slow_motion_handle3.smd_weave_out_avg_blending_en =ptr->Smd_MC_Out_Control.smd_weave_out_avg_blending_en;
//			di_di_smd_slow_motion_handle3.ma_smd_h_compensate_new_en		=ptr->Smd_MC_Out_Control.ma_smd_h_compensate_new_en;
			di_di_smd_ma_mc_weight_ctr.smd_outdata_limit_en 						=ptr->Smd_MC_Out_Control.smd_outdata_limit_en;
//			di_di_smd_diag_edge_protect_ctr.smd_smd_ma_only_v_en				=ptr->Smd_MC_Out_Control.smd_smd_ma_only_v_en;
//			di_di_smd_diag_edge_protect_ctr.smd_smd_ma_only_center_en		=ptr->Smd_MC_Out_Control.smd_smd_ma_only_center_en;
//			di_di_smd_slow_motion_handle3.smd_compensate_teeth_th2			=ptr->Smd_MC_Out_Control.smd_compensate_teeth_th2;
			di_di_smd_ma_mc_weight_ctr.smd_outdata_limit_mvx						=ptr->Smd_MC_Out_Control.smd_outdata_limit_mvx;
			di_di_smd_ma_mc_weight_ctr.smd_outdata_limit_mvy						=ptr->Smd_MC_Out_Control.smd_outdata_limit_mvy;
//			di_di_smd_diag_edge_protect_ctr.smd_smd_vs_detect_length		=ptr->Smd_MC_Out_Control.smd_smd_vs_detect_length;
//			di_di_smd_diag_edge_protect_ctr.nintra_hv_diff_th						=ptr->Smd_MC_Out_Control.nintra_hv_diff_th;
//			di_di_smd_diag_edge_protect_ctr.nintra_h_diff_th						=ptr->Smd_MC_Out_Control.nintra_h_diff_th;
//			di_di_smd_diag_edge_protect_ctr.nintra_v_dir_flag_en				=ptr->Smd_MC_Out_Control.nintra_v_dir_flag_en;


//			di_di_smd_resurrect_ctrl.smd_mv_not_gmv_resurrect_en				=ptr->Smd_Resurrect_Condition.smd_mv_not_gmv_resurrect_en;
//			di_di_smd_resurrect_ctrl.smd_resurrect_noacc_en 						=ptr->Smd_Resurrect_Condition.smd_resurrect_noacc_en;
//			di_di_smd_slow_motion_handle3.smd_teeth_no_ressurrect_n_en	=ptr->Smd_Resurrect_Condition.smd_teeth_no_ressurrect_n_en;
//			di_di_smd_resurrect_ctrl.smd_nongmv0_noacc_en								=ptr->Smd_Resurrect_Condition.smd_nongmv0_noacc_en;

		// end chen 160602



	IoReg_Write32(DI_DI_SMD_Control_CandidateList_reg, init_smd_control_candidatelist_reg.regValue);
	IoReg_Write32(DI_DI_SMD_GMVCoeff3_reg, init_di_smd_gmvcoeff3_reg.regValue);
	IoReg_Write32(DI_DI_SMD_Pan1_reg, init_di_smd_pan1_reg.regValue);
	IoReg_Write32(DI_DI_SMD_Pan2_reg, init_di_smd_pan2_reg.regValue);
	IoReg_Write32(DI_DI_SMD_Pan3_reg, init_di_smd_pan3_reg.regValue);
	IoReg_Write32(DI_DI_SMD_AdditionalCoeff1_reg, init_di_smd_additionalcoeff1_reg.regValue);
	IoReg_Write32(DI_DI_SMD_AdditionalCoeff2_reg, init_di_smd_additionalcoeff2_reg.regValue);
	IoReg_Write32(DI_DI_SMD_AdditionalCoeff3_reg, init_di_smd_additionalcoeff3_reg.regValue);
	IoReg_Write32(DI_DI_SMD_V4HighFreq_reg, init_di_smd_v4highfreq_reg.regValue);
	IoReg_Write32(DI_DI_GST_Ctrl_reg, init_di_gst_ctrl_reg.regValue);
	IoReg_Write32(DI_DI_GST_Enter_origSADCheck_reg, init_di_gst_enter_origsadcheck_reg.regValue);
	IoReg_Write32(DI_DI_GST_OutOfRangeCheck_reg, init_di_gst_outofrangecheck_reg.regValue);
	IoReg_Write32(DI_DI_GST_FreqNonMatchCheck_reg, init_di_gst_freqnonmatchcheck_reg.regValue);
	IoReg_Write32(DI_DI_SMD_CandidateLimitSAD_reg, init_di_smd_candidatelimitsad_reg.regValue);

	IoReg_Write32(DI_DI_SMD_WaterFlag_Ctr1_reg, di_di_smd_waterflag_ctr1.regValue);
	IoReg_Write32(DI_DI_SMD_WaterFlag_Ctr2_reg, di_di_smd_waterflag_ctr2.regValue);
	IoReg_Write32(DI_DI_SMD_WaterFlag_Ctr3_reg, di_di_smd_waterflag_ctr3.regValue);

	IoReg_Write32(DI_DI_SMD_HardwarePan_Modify1_reg, di_di_smd_hardwarepan_modify1.regValue);
	IoReg_Write32(DI_DI_SMD_Sampling_GMVc_reg, di_di_smd_sampling_gmvc.regValue);
	IoReg_Write32(DI_DI_SMD_Sampling_GMVb_reg, di_di_smd_sampling_gmvb.regValue);
	IoReg_Write32(DI_DI_GST_Compensate_reg, di_di_gst_compensate.regValue);
	IoReg_Write32(DI_DI_GST_FMV_Pan_Coeff1_reg, di_di_gst_fmv_pan_coeff1.regValue);
	IoReg_Write32(DI_DI_GST_FMV_Pan_Coeff2_reg, di_di_gst_fmv_pan_coeff2.regValue);

	/* ylchen 150617 */
	IoReg_Write32(DI_DI_SMD_WaterFlow_Teeth_Ctr_reg, 					di_di_smd_waterflow_teeth_ctr.regValue);
	IoReg_Write32(DI_DI_SMD_MA_MC_Weight_Ctr_reg, 						di_di_smd_ma_mc_weight_ctr.regValue);
	IoReg_Write32(DI_DI_SMD_Diag_Edge_Protect_Ctr_reg, 				di_di_smd_diag_edge_protect_ctr.regValue);
	IoReg_Write32(DI_DI_SMD_Slow_Motion_handle1_reg, 					di_di_smd_slow_motion_handle1.regValue);
	IoReg_Write32(DI_DI_SMD_Slow_Motion_handle2_reg, 					di_di_smd_slow_motion_handle2.regValue);
	/* end ylchen 150617 */

	// chen 160602
//	IoReg_Write32(DI_DI_SMD_Slow_Motion_handle3_reg, 					di_di_smd_slow_motion_handle3.regValue);
//	IoReg_Write32(DI_DI_SMD_GMV_Penalty_Ctrl_reg, 						di_di_smd_gmv_penalty_ctrl.regValue);
//	IoReg_Write32(DI_DI_SMD_Resurrect_Ctrl_reg, 							di_di_smd_resurrect_ctrl.regValue);
//	IoReg_Write32(DI_DI_SMD_GMV_Penalty_Ctrl2_reg, 						di_di_smd_gmv_penalty_ctrl2.regValue);
	IoReg_Write32(DI_DI_SMD_HardwarePan_Modify1_reg, 					di_di_smd_hardwarepan_modify1.regValue);
	IoReg_Write32(DI_DI_SMD_WaterFlag_Ctr3_reg, 							di_di_smd_waterflag_ctr3.regValue);
//	IoReg_Write32(DI_DI_SMD_GMV_Penalty_Ctrl_reg, 						di_di_smd_gmv_penalty_ctrl.regValue);
	// end chen 160602

}

void drvif_color_ZOOM_MOTION_Seperate(UINT32 x_left_pos, UINT32 x_right_pos, UINT32 y_top_pos, UINT32 y_bot_pos)
{
	UINT32 tmp;
	di_im_di_zoommotion_det_02_RBUS zoommotion_det_02_reg;
	di_im_di_zoommotion_det_03_RBUS zoommotion_det_03_reg;

	zoommotion_det_02_reg.regValue = IoReg_Read32(DI_IM_DI_ZoomMotion_Det_02_reg);
	zoommotion_det_03_reg.regValue = IoReg_Read32(DI_IM_DI_ZoomMotion_Det_03_reg);

	if (x_left_pos > 1920)
		x_left_pos = 1920;
	if (x_right_pos > 1920)
		x_right_pos = 1920;
	if (y_top_pos > 1080)
		y_top_pos = 1080;
	if (y_bot_pos > 1080)
		y_top_pos = 1080;

	if (x_left_pos > x_right_pos) {
		tmp = x_left_pos;
		x_left_pos = x_right_pos;
		x_right_pos = tmp;
	}

	if (y_top_pos > y_bot_pos) {
		tmp = y_top_pos;
		y_top_pos = y_bot_pos;
		y_bot_pos = tmp;
	}

	zoommotion_det_02_reg.smd_zoommotion_x_1 = x_left_pos;
	zoommotion_det_02_reg.smd_zoommotion_x_2 = x_right_pos;
	zoommotion_det_03_reg.smd_zoommotion_y_1 = y_top_pos;
	zoommotion_det_03_reg.smd_zoommotion_y_2 = y_bot_pos;

	IoReg_Write32(DI_IM_DI_ZoomMotion_Det_02_reg, zoommotion_det_02_reg.regValue);
	IoReg_Write32(DI_IM_DI_ZoomMotion_Det_03_reg, zoommotion_det_03_reg.regValue);
}

void drvif_color_ZOOM_MOTION_En(unsigned char bEnable)
{
	di_im_di_zoommotion_detector_RBUS zoommotion_detector_reg;
	unsigned char source;
	source = fwif_vip_source_check(3, 0);

	zoommotion_detector_reg.regValue = IoReg_Read32(DI_IM_DI_ZoomMotion_Detector_reg);

	zoommotion_detector_reg.smd_zoommotion_block_1_en = 1;
	zoommotion_detector_reg.smd_zoommotion_block_3_en = 1;
	zoommotion_detector_reg.smd_zoommotion_block_7_en = 1;
	zoommotion_detector_reg.smd_zoommotion_block_9_en = 1;
	zoommotion_detector_reg.smd_zoommotion_type_sel = 0;
	zoommotion_detector_reg.smd_zoommotion_continue_th = 2;

	if (bEnable) {
		zoommotion_detector_reg.smd_zoommotion_en = 1;
	} else {
		zoommotion_detector_reg.smd_zoommotion_en = 0;
	}

	IoReg_Write32(DI_IM_DI_ZoomMotion_Detector_reg, zoommotion_detector_reg.regValue);

	if (source == VIP_QUALITY_CVBS_NTSC || source == VIP_QUALITY_YPbPr_480I || source == VIP_QUALITY_HDMI_480I) {
		drvif_color_ZOOM_MOTION_Seperate(200, 520, 130, 350);
	} else if (source == VIP_QUALITY_CVBS_PAL || source == VIP_QUALITY_YPbPr_576I || source == VIP_QUALITY_HDMI_576I) {
		drvif_color_ZOOM_MOTION_Seperate(200, 520, 130, 440);
	} else {
		drvif_color_ZOOM_MOTION_Seperate(600, 1320, 360, 720);
	}
}

unsigned char drvif_color_ZOOM_MOTION_Status()
{
	di_im_di_zoommotion_detector_RBUS zoommotion_detector_reg;
	zoommotion_detector_reg.regValue = IoReg_Read32(DI_IM_DI_ZoomMotion_Detector_reg);

	/*
	0: no zoom motion
	1: zoom out
	2: zoom in
	*/
	return zoommotion_detector_reg.smd_zoommotion_flag;
}

void drvif_color_ZOOM_MOTION_Level(unsigned char level)
{
	drvif_color_ZOOM_MOTION_Set_FM_TH(ZOOM_MOTION_TH[level][0], ZOOM_MOTION_TH[level][1], ZOOM_MOTION_TH[level][2], ZOOM_MOTION_TH[level][3]);
}

void drvif_color_ZOOM_MOTION_Set_FM_TH(UINT8 Mth[3], UINT8 Hth[3], UINT8 RLVth[3], UINT8 Sth[3])
{
	di_im_di_zoommotion_det_fm_th_a_RBUS zoommotion_det_fm_th_a_reg;
	di_im_di_zoommotion_det_fm_th_b_RBUS zoommotion_det_fm_th_b_reg;
	di_im_di_zoommotion_det_fm_th_c_RBUS zoommotion_det_fm_th_c_reg;

	zoommotion_det_fm_th_a_reg.regValue = IoReg_Read32(DI_IM_DI_ZoomMotion_Det_FM_TH_A_reg);
	zoommotion_det_fm_th_b_reg.regValue = IoReg_Read32(DI_IM_DI_ZoomMotion_Det_FM_TH_B_reg);
	zoommotion_det_fm_th_c_reg.regValue = IoReg_Read32(DI_IM_DI_ZoomMotion_Det_FM_TH_C_reg);

	zoommotion_det_fm_th_a_reg.smd_zoommotion_ma_framemtha = Mth[0];
	zoommotion_det_fm_th_b_reg.smd_zoommotion_ma_framemthb = Mth[1];
	zoommotion_det_fm_th_c_reg.smd_zoommotion_ma_framemthc = Mth[2];

	zoommotion_det_fm_th_a_reg.smd_zoommotion_ma_framehtha = Hth[0];
	zoommotion_det_fm_th_b_reg.smd_zoommotion_ma_framehthb = Hth[1];
	zoommotion_det_fm_th_c_reg.smd_zoommotion_ma_framehthc = Hth[2];

	zoommotion_det_fm_th_a_reg.smd_zoommotion_ma_framerlvtha = RLVth[0];
	zoommotion_det_fm_th_b_reg.smd_zoommotion_ma_framerlvthb = RLVth[1];
	zoommotion_det_fm_th_c_reg.smd_zoommotion_ma_framerlvthc = RLVth[2];

	zoommotion_det_fm_th_a_reg.smd_zoommotion_ma_framestha = Sth[0];
	zoommotion_det_fm_th_b_reg.smd_zoommotion_ma_framesthb = Sth[1];
	zoommotion_det_fm_th_c_reg.smd_zoommotion_ma_framesthc = Sth[2];

	IoReg_Write32(DI_IM_DI_ZoomMotion_Det_FM_TH_A_reg, zoommotion_det_fm_th_a_reg.regValue);
	IoReg_Write32(DI_IM_DI_ZoomMotion_Det_FM_TH_B_reg, zoommotion_det_fm_th_b_reg.regValue);
	IoReg_Write32(DI_IM_DI_ZoomMotion_Det_FM_TH_C_reg, zoommotion_det_fm_th_c_reg.regValue);

}

void drvif_color_SLOW_MOTION_En(unsigned char bEnable)
{
	di_im_di_slowmotion_detector_1_RBUS slowmotion_detector_reg;

	slowmotion_detector_reg.regValue = IoReg_Read32(DI_IM_DI_SlowMotion_Detector_1_reg);

	if (bEnable) {
		slowmotion_detector_reg.smd_slowmotion_en = 1;
	} else {
		slowmotion_detector_reg.smd_slowmotion_en = 0;
	}

	IoReg_Write32(DI_IM_DI_SlowMotion_Detector_1_reg, slowmotion_detector_reg.regValue);

}

unsigned char drvif_color_SLOW_MOTION_Status()
{
	di_im_di_slowmotion_detector_1_RBUS slowmotion_detector_reg;

	slowmotion_detector_reg.regValue = IoReg_Read32(DI_IM_DI_SlowMotion_Detector_1_reg);

	return slowmotion_detector_reg.smd_slowmotion_flag;
}

void drvif_color_SLOW_MOTION_Level(unsigned char level)
{
	drvif_color_SLOW_MOTION_Set_FM_TH(SLOW_MOTION_TH[level][0], SLOW_MOTION_TH[level][1], SLOW_MOTION_TH[level][2], SLOW_MOTION_TH[level][3]);
}

void drvif_color_SLOW_MOTION_Set_FM_TH(UINT8 Mth[3], UINT8 Hth[3], UINT8 RLVth[3], UINT8 Sth[3])
{
	di_im_di_slowmotion_det_fm_th_a_RBUS slowmotion_det_fm_th_a_reg;
	di_im_di_slowmotion_det_fm_th_b_RBUS slowmotion_det_fm_th_b_reg;
	di_im_di_slowmotion_det_fm_th_c_RBUS slowmotion_det_fm_th_c_reg;

	slowmotion_det_fm_th_a_reg.regValue = IoReg_Read32(DI_IM_DI_SlowMotion_Det_FM_TH_A_reg);
	slowmotion_det_fm_th_b_reg.regValue = IoReg_Read32(DI_IM_DI_SlowMotion_Det_FM_TH_B_reg);
	slowmotion_det_fm_th_c_reg.regValue = IoReg_Read32(DI_IM_DI_SlowMotion_Det_FM_TH_C_reg);

	slowmotion_det_fm_th_a_reg.smd_slowmotion_ma_framemtha = Mth[0];
	slowmotion_det_fm_th_b_reg.smd_slowmotion_ma_framemthb = Mth[1];
	slowmotion_det_fm_th_c_reg.smd_slowmotion_ma_framemthc = Mth[2];

	slowmotion_det_fm_th_a_reg.smd_slowmotion_ma_framehtha = Hth[0];
	slowmotion_det_fm_th_b_reg.smd_slowmotion_ma_framehthb = Hth[1];
	slowmotion_det_fm_th_c_reg.smd_slowmotion_ma_framehthc = Hth[2];

	slowmotion_det_fm_th_a_reg.smd_slowmotion_ma_framerlvtha = RLVth[0];
	slowmotion_det_fm_th_b_reg.smd_slowmotion_ma_framerlvthb = RLVth[1];
	slowmotion_det_fm_th_c_reg.smd_slowmotion_ma_framerlvthc = RLVth[2];

	slowmotion_det_fm_th_a_reg.smd_slowmotion_ma_framestha = Sth[0];
	slowmotion_det_fm_th_b_reg.smd_slowmotion_ma_framesthb = Sth[1];
	slowmotion_det_fm_th_c_reg.smd_slowmotion_ma_framesthc = Sth[2];

	IoReg_Write32(DI_IM_DI_SlowMotion_Det_FM_TH_A_reg, slowmotion_det_fm_th_a_reg.regValue);
	IoReg_Write32(DI_IM_DI_SlowMotion_Det_FM_TH_B_reg, slowmotion_det_fm_th_b_reg.regValue);
	IoReg_Write32(DI_IM_DI_SlowMotion_Det_FM_TH_C_reg, slowmotion_det_fm_th_c_reg.regValue);

}

char drvif_color_Get_MCNR_HV_PAN_MV(unsigned char *MV_h, unsigned char *MV_v)
{
	di_im_new_mcnr_pan_condition_RBUS di_im_new_mcnr_pan_condition;
	di_im_new_mcnr_control4_RBUS di_im_new_mcnr_control4;

	di_im_new_mcnr_pan_condition.regValue = IoReg_Read32(DI_IM_NEW_MCNR_PAN_CONDITION_reg);
	di_im_new_mcnr_control4.regValue = IoReg_Read32(DI_IM_NEW_MCNR_CONTROL4_reg);

	if ((MV_h == NULL) || (MV_v == NULL)) {
		rtd_printk(KERN_EMERG, TAG_NAME, "drvif_color_Get_MCNR_HV_PAN_MV NULL point!!\n");
		return -1;
	}

	*MV_h = di_im_new_mcnr_pan_condition.h_pan_mv_value;
	*MV_v = di_im_new_mcnr_control4.n_mcnr_v_pan_mv;

	return 0;
}

void drvif_color_Set_MA_Control_Mode(unsigned char mode)
{
	di_im_di_control_RBUS di_control_reg;
	di_control_reg.regValue = IoReg_Read32(DI_IM_DI_CONTROL_reg);
	di_control_reg.ma_controlmode = mode;
	di_control_reg.write_enable_0 = 1;
	IoReg_Write32(DI_IM_DI_CONTROL_reg, di_control_reg.regValue);
}

void drvif_color_Set_DI_DB_APPLY(void)
{
	IoReg_SetBits(DI_db_reg_ctl_reg, DI_db_reg_ctl_db_apply_mask);
}

void drvif_color_Set_smd_reliablerange_sad_th(unsigned char value)
{
	di_di_smd_choosecandidate_RBUS 	smd_choosecandidate_reg;
	smd_choosecandidate_reg.regValue = IoReg_Read32(DI_DI_SMD_ChooseCandidate_reg);
	smd_choosecandidate_reg.smd_reliablerange_sad_th = value;
	IoReg_Write32(DI_DI_SMD_ChooseCandidate_reg, smd_choosecandidate_reg.regValue);
}

void drvif_color_DI_Addr_Boundary_ini(unsigned int DI_addr_sta, unsigned int DI_addr_end, unsigned int DI_MASNR_addr_sta, unsigned int DI_MASNR_addr_end)
{
	IoReg_Write32(DI_DI1_WRRD_BoundaryAddr1_reg, DI_addr_sta);
	IoReg_Write32(DI_DI1_WRRD_BoundaryAddr2_reg, DI_addr_end);
	//IoReg_Write32(DI_MVF_WR_BoundaryAddr1_reg, DI_MASNR_addr_sta);	/* no this IP*/
	//IoReg_Write32(DI_MVF_WR_BoundaryAddr2_reg, DI_MASNR_addr_end);

	IoReg_SetBits(DI_db_reg_ctl_reg, DI_db_reg_ctl_db_apply_mask);
}

