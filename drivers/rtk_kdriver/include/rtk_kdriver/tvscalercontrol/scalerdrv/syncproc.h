/*=============================================
  * Copyright (c)      Realtek Semiconductor Corporation, 2005
  * All rights reserved.
  * ============================================ */

/*================= File Description ================= */
/**
 * @file
 * The file is a declaration and definition header file
 *
 * @author 	$Author:  $
 * @date 	$Date:  $
 * @version 	$Revision:  $
 * @ingroup
 */

 /**
 * @addtogroup
 * @{
 */

#ifndef _SYNCPROC_H
#define _SYNCPROC_H

//#include <rtd_types.h>
#include <tvscalercontrol/scaler/source.h>


#define SYNC_PROCESSOR1         0
#define SYNC_PROCESSOR2         1

#define VGA_SP_PATH	SYNC_PROCESSOR1
#define YPBPR_SP_PATH	SYNC_PROCESSOR1

#define SOG1                              0
#define SOG2                              1
#define  SOG_SOURCE              SOG1
#define  SOY_SOURCE              SOG2

//SP1_CTRL[2:0], S1_vhs_source_sel
#define SP_VHS_SOURCE_PTG_CS_HS1VS1	0  //ptg_adc_cshs,csvs (PatternGen Composite Signal)
#define SP_VHS_SOURCE_PTG_HS1VS1		1 //ptg_adc_hs,vs (PatternGen Separate  Signal)
#define SP_VHS_SOURCE_PAD_HS1VS1		2 //pad_hs1,pad_vs1
#define SP_VHS_SOURCE_JITTER_PTG		3 //jitter PTG (From APLL Pattern Gen)
#define SP_VHS_SOURCE_SOY_0			4 //SOY0
#define SP_VHS_SOURCE_SOY_1			5 //SOY1
#define SP_VHS_SOURCE_PAD_HS2VS2		6 //pad_hs2,pad_vs2

//Input HS/VS/SOY Source Selection
#define SP_VHS_SOURCE_SOY0	0
#define SP_VHS_SOURCE_SOY1	1

//lewis, because in pacific, VGA/YPbPr can't PIP
#define YPBPR_SOY_PATH_SELECT	SP_VHS_SOURCE_SOY0
#define YPBPR_SOY_DETECT_PATH_SELECT	SP_VHS_SOURCE_SOY1
#define VGA_SOG_PATH_SELECT	SP_VHS_SOURCE_SOY0

#define _IN_HS_SEL_HSRAW	0
#define _IN_HS_SEL_SOY		1	// SOY/SOG

#define ANALOG_MODE_MEASUREMENT      0
#define DIGITAL_MODE_MEASUREMENT     1

#define CLAMP_TRAILING_EDGE	1 //Back Porch
#define CLAMP_LEADING_EDGE	0 //front Porch

#define YPBPR_CLAMP_Y_REF_EDGE	CLAMP_LEADING_EDGE
#define YPBPR_CLAMP_NY_REF_EDGE	CLAMP_LEADING_EDGE
#define VGA_CLAMP_Y_REF_EDGE		CLAMP_LEADING_EDGE
#define VGA_CLAMP_NY_REF_EDGE		CLAMP_LEADING_EDGE
#define SOG_CLAMP_Y_REF_EDGE		CLAMP_LEADING_EDGE
#define SOG_CLAMP_NY_REF_EDGE		CLAMP_LEADING_EDGE

#define CLAMP_CLKSRC_ADC		1
#define CLAMP_CLKSRC_CRYSTAL	0
#define YPBPR_CLAMP_CLKSRC		CLAMP_CLKSRC_ADC
#define VGA_CLAMP_CLKSRC		CLAMP_CLKSRC_CRYSTAL
#define SOG_CLAMP_CLKSRC		CLAMP_CLKSRC_CRYSTAL

#define CLAMP_CNT_UNIT_1CLK	0
#define CLAMP_CNT_UNIT_2CLK	1
#define YPBPR_CLAMP_CNT_UNIT	CLAMP_CNT_UNIT_2CLK
#define VGA_CLAMP_CNT_UNIT	CLAMP_CNT_UNIT_1CLK
#define SOG_CLAMP_CNT_UNIT	CLAMP_CNT_UNIT_1CLK

// [Code Sync][LewisLee][0990326][1]
#if (YPBPR_CLAMP_CNT_UNIT	== CLAMP_CNT_UNIT_2CLK)
#define _YPBPR_CLAMP_2X_CNT_FACTOR	1
#else //#if (YPBPR_CLAMP_CNT_UNIT	== CLAMP_CNT_UNIT_2CLK)
#define _YPBPR_CLAMP_2X_CNT_FACTOR	0
#endif //#if (YPBPR_CLAMP_CNT_UNIT	== CLAMP_CNT_UNIT_2CLK)


//USER:LewisLee DATE:2011/09/23
//need modify it, to prevent Tolerance too large
#if(YPBPR_CLAMP_CLKSRC == CLAMP_CLKSRC_ADC)
#define YPBPR_CLAMP_POSITION_TOLERANCE	(6>>_YPBPR_CLAMP_2X_CNT_FACTOR)
#else //#if(YPBPR_CLAMP_CLKSRC == CLAMP_CLKSRC_ADC)
#define YPBPR_CLAMP_POSITION_TOLERANCE	(2>>_YPBPR_CLAMP_2X_CNT_FACTOR)
#endif //#if(YPBPR_CLAMP_CLKSRC == CLAMP_CLKSRC_ADC)

// [Code Sync][LewisLee][0990326][1][End]

#if (SOG_CLAMP_CNT_UNIT	== CLAMP_CNT_UNIT_2CLK)
#define SOG_CLAMP_POSITION_TOLERANCE	2	//in 2x clock it is 4
#else //#if (SOG_CLAMP_CNT_UNIT	== CLAMP_CNT_UNIT_2CLK)
#define SOG_CLAMP_POSITION_TOLERANCE	5
#endif //#if (SOG_CLAMP_CNT_UNIT	== CLAMP_CNT_UNIT_2CLK)

#define CLAMP_POSITION_CHECK_CNT	10

//0x1802_0014[22:20]	:	RED Channel Clamp Voltage (0V~700mV, Step=100mV)
//0x1802_0014[14:12]	:	GREEN Channel Clamp Voltage (0V~700mV, Step=100mV)
//0x1802_0014[6:4]	:	BLUE Channel Clamp Voltage (0V~700mV, Step=100mV)
//YPbPr
#define YPBPR_R_CLAMP_VOLTAGE		4
#define YPBPR_G_CLAMP_VOLTAGE		4
#define YPBPR_B_CLAMP_VOLTAGE		4

//VGA
#define VGA_R_CLAMP_VOLTAGE		4
#define VGA_G_CLAMP_VOLTAGE		4
#define VGA_B_CLAMP_VOLTAGE		4

//0x1802_001c[23:22], input2/1/0(VIN11P-VIN0P) DC restore resister
#define DC_RESTORE_RESISTER_OPEN	0
#define DC_RESTORE_RESISTER_500K	1
#define DC_RESTORE_RESISTER_1M	2
#define DC_RESTORE_RESISTER_5M	3

//YPbPr
//DC restore power too weak, add DC restore resister, need check root cause
#define DC_RESTORE_RESISTER_YUV	DC_RESTORE_RESISTER_500K//DC_RESTORE_RESISTER_1M

//VGA
#define DC_RESTORE_RESISTER_RGB	DC_RESTORE_RESISTER_500K//DC_RESTORE_RESISTER_1M

// 0x1802_0008[13]
// RGB/YPP Channel Input Range Adjust
// 0: 0.5V-1.0V
// 1: 0.25-1.25V
#define INPUT_RANGE_ADJUST		1

// 0x1802_0008[12]
// RGB/YPP Channel ADC 2nd LPF Gain
// 0: 0.5
// 1:1
#define ADC_2ND_LPF_GAIN			1

//Capture Window Tolerance in Sync Processor 1, 0xb8021010[21:20][15:11]
//Capture Window Tolerance in Sync Processor 2, 0xb802101c[21:20][15:11]
//capture window = กำ((4*x + 3) + LSB) crystal clks for capture window
#define YPBPR_CAP_WIN_RANGE_INIT			4	// 4*4+3 + 1 = 20 crystal clock
#define YPBPR_CAP_WIN_RANGE_LSB_INIT		1

#define YPBPR_CAP_WIN_RANGE_480I			4	// 4*4+3 + 1 = 20 crystal clock
#define YPBPR_CAP_WIN_RANGE_LSB_480I		1

#define YPBPR_CAP_WIN_RANGE_480P			0	// 4*4+3 + 1 = 20 crystal clock
#define YPBPR_CAP_WIN_RANGE_LSB_480P		3

#define YPBPR_CAP_WIN_RANGE_576I			4	// 4*4+3 + 1 = 20 crystal clock
#define YPBPR_CAP_WIN_RANGE_LSB_576I		1

#define YPBPR_CAP_WIN_RANGE_576P			1	// 4*4+3 + 1 = 20 crystal clock
#define YPBPR_CAP_WIN_RANGE_LSB_576P		1

#define YPBPR_CAP_WIN_RANGE_720P			0//5	// 4*5+3 + 1 = 24 crystal clock
#define YPBPR_CAP_WIN_RANGE_LSB_720P		2

#define YPBPR_CAP_WIN_RANGE_1080I		0//5	// 4*5+3 + 1 = 24 crystal clock
#define YPBPR_CAP_WIN_RANGE_LSB_1080I	2

#define YPBPR_CAP_WIN_RANGE_1080P		0//5	// 4*5+3 + 1 = 24 crystal clock
#define YPBPR_CAP_WIN_RANGE_LSB_1080P	2

#define VGA_CAP_WIN_RANGE_SS_INIT		1	// 4*1+3 + 0 = 7 crystal clock
#define VGA_CAP_WIN_RANGE_SS_LSB_INIT	0

#define VGA_CAP_WIN_RANGE_SOG_INIT		1	// 4*1+3 + 0 = 7 crystal clock
#define VGA_CAP_WIN_RANGE_SOG_LSB_INIT	0

#define VGA_CAP_WIN_RANGE_CS_INIT		1	// 4*1+3 + 0 = 7 crystal clock
#define VGA_CAP_WIN_RANGE_CS_LSB_INIT	0


//Stable Period Tolerance in Sync Processor 1, 0xb8021010[10:8]
//Stable Period Tolerance in Sync Processor 2, 0xb802101c[10:8]
#define _PER_RANGE_02_TOLERANCE	0 //กำ2 crystal clks for Stable period
#define _PER_RANGE_04_TOLERANCE	1 //กำ4 crystal clks for Stable period
#define _PER_RANGE_08_TOLERANCE	2 //กำ8 crystal clks for Stable period
#define _PER_RANGE_16_TOLERANCE	3 //กำ16 crystal clks for Stable period
#define _PER_RANGE_32_TOLERANCE	4 //กำ32 crystal clks for Stable period
#define _PER_RANGE_64_TOLERANCE	5 //กำ64 crystal clks for Stable period

#define YPBPR_PER_RANGE_TOLERANCE_INIT	_PER_RANGE_04_TOLERANCE
#define VGA_PER_RANGE_TOLERANCE_INIT		_PER_RANGE_04_TOLERANCE

//Cap window add step as miss lock in Sync Processor 1, 0xb8021010[3]
//Cap window add step as miss lock in Sync Processor 2, 0xb802101c[3]
#define _CAP_WIN_SETP_1_CLK	0	//กำ1 crystal clks
#define _CAP_WIN_SETP_2_CLK	1	//กำ2 crystal clks

#define YPBPR_CAP_WIN_SETP_INIT	_CAP_WIN_SETP_1_CLK
#define VGA_CAP_WIN_SETP_INIT		_CAP_WIN_SETP_2_CLK

//Capture miss limit during Hsync extraction in Sync Processor 1, 0xb8021010[2]
//Capture miss limit during Hsync extraction in Sync Processor 2, 0xb802101c[2]
#define _MISS_LOCK_LIMIT_32	0
#define _MISS_LOCK_LIMIT_16	1

#define YPBPR_MISS_LOCK_LIMIT_INIT		_MISS_LOCK_LIMIT_32
#define VGA_MISS_LOCK_LIMIT_INIT		_MISS_LOCK_LIMIT_32

//Chroma Canceling debounce length selection in Sync Processor 1, 0xb8021028[15:11]
//Chroma Canceling debounce length selection in Sync Processor 2, 0xb802102c[15:11]
#define YPBPR_CHROMA_DEBOUNCE_NUM_INIT		4	// 4 crystal clock
#define YPBPR_CHROMA_DEBOUNCE_NUM_480I		4	// 4 crystal clock
#define YPBPR_CHROMA_DEBOUNCE_NUM_480P		4	// 4 crystal clock
#define YPBPR_CHROMA_DEBOUNCE_NUM_576I		4	// 4 crystal clock
#define YPBPR_CHROMA_DEBOUNCE_NUM_576P		4	// 4 crystal clock
#define YPBPR_CHROMA_DEBOUNCE_NUM_720P		0	// 0 crystal clock
#define YPBPR_CHROMA_DEBOUNCE_NUM_1080I		0	// 0 crystal clock
#define YPBPR_CHROMA_DEBOUNCE_NUM_1080P	0	// 0 crystal clock
#define VGA_CHROMA_DEBOUNCE_NUM_INIT		4	// 4 crystal clock

//VS period measure time out select, 0xb8021100[22]
#define _OFF_MEAS_TO_SEL_38MS		0
#define _OFF_MEAS_TO_SEL_76MS		1

#define _OFF_MEAS_TO_SEL			_OFF_MEAS_TO_SEL_76MS

//VS period measure time out select, ch1:0xb8021200[17]
//VS period measure time out select, ch2:0xb8021214[17]
#define _ON_MEAS_TO_SEL_38MS		0
#define _ON_MEAS_TO_SEL_76MS		1

//Time-Out bit of Input VSYNC Period Measurement (No VSYNC occurred), ch1:0xb802120c[10, 7]
//Time-Out bit of Input VSYNC Period Measurement (No VSYNC occurred), ch2:0xb8021220[10, 7]
#define _ON_VS_PER_TO_LONG	_BIT10	//check 76ms
#define _ON_VS_PER_TO			_BIT7	//check 40ms

#define _ON1_MEAS_TO_SEL				_ON_MEAS_TO_SEL_76MS
#define _ON1_VS_TIMEOUT_CHECK_FLG	_ON_VS_PER_TO_LONG

#define _ON2_MEAS_TO_SEL				_ON_MEAS_TO_SEL_76MS
#define _ON2_VS_TIMEOUT_CHECK_FLG	_ON_VS_PER_TO_LONG

#define _HSYNC_AHS		0
#define _HSYNC_FBHS		1

#define YPBPR_HSYNC_SRC	_HSYNC_FBHS//_HSYNC_AHS
#define VGA_HSYNC_SRC		_HSYNC_AHS//_HSYNC_FBHS //orignal after auto clock it will keep _HSYNC_AHS

//Mask 4 flags (Off_vs_over_range, Off_vs_pol_chg, Off_hs_over_range, off_hs_pol_chg)
//at first 3 frames to avoid flags raise up by mistake.
//0x1802_110c[11]
#define OFF_BLK_2FRAME_EN	_DISABLE

//method 1 => jump phase => 0x18020010[6] : 1
//method 2 => jump phase => 0x18020050[28] : 1
#define ADC_JUMP_PHASE_METHOD2	1

#define ADC_JUMP_PHASE_CHANGE_TYPE1		1
#define ADC_JUMP_PHASE_DETECT_INIT		0
#define ADC_JUMP_PHASE_DETECT_START		1

//0x1802_1004[29:24] : S1_unlock_no_vs_str
//0x1802_1004[23:12] : S1_unlock_no_vs_end
#define YPBPR_JUMP_PHASE_DETECT_VSTART	0x20
#define YPBPR_JUMP_PHASE_DETECT_VEND		0xc8
#define VGA_JUMP_PHASE_DETECT_VSTART		0x20
#define VGA_JUMP_PHASE_DETECT_VEND		0xc8

//0x1802_1000[12]
#define S1_SEPERATE_TESTMODE_DE_VS		0
#define S1_SEPERATE_TESTMODE_VS_RAW		1

//********************** schmitt trigger Setting *************************//
// 0x1802_0044[6] : HSYNC Polarity Select
// 0: Negative HSYNC (high level)
// 1: Positive HSYNC (low level)
// define : 1
#define HSYNC0_POL_NEGATIVE	0
#define HSYNC0_POL_POSITIVE	1
#define HSYNC0_POL				HSYNC0_POL_POSITIVE

// 0x1802_0044[5] : HSYNC Trigger Mode
// 0: old mode
// 1: new mode
// define : 0
#define HSYNC0_MODE_OLD	0
#define HSYNC0_MODE_NEW	1

#define HSYNC0_MODE		HSYNC0_MODE_OLD

// 0x1802_0044[4] : HSYNC Threshold Voltage Fine Tune
// 0 : vtp=vtp		,	vtn=vtn
// 1 : vtp=vtp-0.1	,	vtn=vtn-0.1
// define : 0
#define HSYNC0_VOS_0	0
#define HSYNC0_VOS_1	1
#define HSYNC0_VOS		HSYNC0_VOS_0

// 0x1802_0044[3:2] : HSYNC Positive Threshold Voltage
// Polarity=1(UP)		Polarity=0(DN)
// NEW_MODE
// 00 : vtp=1.4V		, vtp=1.8V
// 01 : vtp=1.6V		, vtp=2.0V
// 10 : vtp=1.8V		, vtp=2.2V*
// 11 : vtp=2.0V		, vtp=2.4V*
// define : 1
#define HSYNC0_VTP_00	0
#define HSYNC0_VTP_01	1
#define HSYNC0_VTP_10	2
#define HSYNC0_VTP_11	3
#define HSYNC0_VTP		HSYNC0_VTP_01

// 0x1802_0044[1:0] : HSYNC Negative Threshold Voltage
// Polarity=1(UP)		Polarity=0(DN)
// NEW_MODE
// 00 : vtn=vtp-1.2V	, vtn=vtp-1.2V
// 01 : vtn=vtp-1.0V	, vtn=vtp-1.0V
// 10 : vtn=vtp-0.8V	, vtn=vtp-0.8V
// 11 : vtn=vtp-0.6V	, vtn=vtp-0.6V
// define : 1
#define HSYNC0_VTN_00	0
#define HSYNC0_VTN_01	1
#define HSYNC0_VTN_10	2
#define HSYNC0_VTN_11	3
#define HSYNC0_VTN		HSYNC0_VTN_01

// OLD_MODE
// [HSYNC0_POL : HSYNC0_MODE]= 2'b00
// Vt+ = 1.5V, Vt- = 1.0V
// [HSYNC0_POL : HSYNC0_MODE]= 2'b10
// HSYNC0_VTN[1:0]	Vt+		Vt-
// 2'b01				2.0V		1.5V
// 2'b11				1.5V		1.0V

//************************** ABL Setting ******************************//
//Width of ABL region in each line
#define _16_PIXEL	0x00
#define _32_PIXEL	0x01
#define _64_PIXEL	0x02
#define _04_PIXEL	0x03

//lines averaged for each ABL adjustment
#define _AVG_08_LINE		0x00
#define _AVG_16_LINE		0x01
#define _AVG_32_LINE		0x02
#define _AVG_64_LINE		0x03

//Lines delayed between each measurement region
#define _DELAY_016_LINE		0x00
#define _DELAY_032_LINE		0x01
#define _DELAY_064_LINE		0x02
#define _DELAY_128_LINE		0x03
#define _DELAY_192_LINE		0x04
#define _DELAY_256_LINE		0x05
#define _DELAY_384_LINE		0x06
#define _DELAY_640_LINE		0x07

#define _ABL_VGA_TARGET_VALUE  ((8 >> 2) - 1) // 4~64 and value should be the times of 4

#define _ABL_YPP_TARGET_VALUE  ((64 >> 2) - 1) // 4~64 and value should be the times of 4

//Start Position of ABL in each line
#define YPBPR_ABL_HD_720P_H_START	0x96
#define YPBPR_ABL_HD_H_START			0x88
#define YPBPR_ABL_SD_60HZ_H_START	0x52
#define YPBPR_ABL_SD_50HZ_H_START	0x56

//Width of ABL region in each line
#define YPBPR_ABL_HD_720P_H_WIDTH	_16_PIXEL
#define YPBPR_ABL_HD_H_WIDTH			_16_PIXEL
#define YPBPR_ABL_SD_60HZ_H_WIDTH	_16_PIXEL
#define YPBPR_ABL_SD_50HZ_H_WIDTH	_16_PIXEL

//lines averaged for each ABL adjustment
#define YPBPR_ABL_HD_720P_LINE_AVG	_AVG_08_LINE
#define YPBPR_ABL_HD_LINE_AVG			_AVG_08_LINE
#define YPBPR_ABL_SD_60HZ_LINE_AVG	_AVG_08_LINE
#define YPBPR_ABL_SD_50HZ_LINE_AVG	_AVG_08_LINE

//Start Vertical Position of ABL in each line

#define YPBPR_ABL_HD_720P_V_START		24
#define YPBPR_ABL_HD_V_START			24
#define YPBPR_ABL_SD_60HZ_V_START		24
#define YPBPR_ABL_SD_50HZ_V_START		24

//Lines delayed between each measurement region
#define YPBPR_ABL_HD_720P_WAIT_LINE	_DELAY_016_LINE
#define YPBPR_ABL_HD_WAIT_LINE		_DELAY_016_LINE
#define YPBPR_ABL_SD_60HZ_WAIT_LINE	_DELAY_016_LINE
#define YPBPR_ABL_SD_50HZ_WAIT_LINE	_DELAY_016_LINE

//End Vertical Position of ABL measurement region
#define YPBPR_ABL_480I_V_END			120
#define YPBPR_ABL_576I_V_END			144
#define YPBPR_ABL_480P_V_END			252
#define YPBPR_ABL_576P_V_END			300
#define YPBPR_ABL_720P_V_END			360
#define YPBPR_ABL_1080I_V_END			264
#define YPBPR_ABL_1080P_V_END			552

//Set ABL Margin, the Large Margin can not be zero!!
#define YPBPR_ABL_EQUAL_MARGIN_INIT	0x01
#define YPBPR_ABL_Y_EQUAL_MARGIN		0x02
#define YPBPR_ABL_Y_LARGE_MARGIN		0x08
#define YPBPR_ABL_UV_EQUAL_MARGIN	0x01//Will modify from Brandon suggestion
#define YPBPR_ABL_UV_LARGE_MARGIN	0x02
#define YPBPR_ABL_LOCK_MARGIN			0x03


#define VGA_SOG_ABL_V_START			0x08
#define VGA_SOG_ABL_V_END				0xe0
#define VGA_SOG_ABL_WAIT_LINE			_DELAY_016_LINE
#define VGA_SOG_ABL_H_WIDTH			_16_PIXEL
#define VGA_SOG_ABL_LINE_AVG			_AVG_08_LINE
#define VGA_SOG_ABL_H_START_OFFSET	10 //Hsync High pulse add 10 pixel

//Set ABL Margin, the Large Margin can not be zero!!
#define VGA_SOG_ABL_EQUAL_MARGIN_INIT	0x01
#define VGA_SOG_ABL_EQUAL_MARGIN		0x04
#define VGA_SOG_ABL_LARGE_MARGIN		0x1F
#define VGA_SOG_ABL_LOCK_MARGIN		0x04

//************************** ABL Setting ******************************//

//spec YPbPr ADC, 0x1802_0040[9]
#define _NORMAL	0
#define _INVERT	1

#define VGA_ADC_CLK_INV	_INVERT
#define YPBPR_ADC_CLK_INV	_INVERT

#define ADC_BW_10M		0
#define ADC_BW_25M		1
#define ADC_BW_37_5M	2
#define ADC_BW_50M		3
#define ADC_BW_75M		4
#define ADC_BW_100M		5
#define ADC_BW_150M		6
#define ADC_BW_200M		7
#define ADC_BW_300M		8
#define ADC_BW_400M		9
#define ADC_BW_X1		10
#define ADC_BW_X2		11
#define ADC_BW_X3		12
#define ADC_BW_X4		13
#define ADC_BW_X5		14
#define ADC_BW_X6		15

#define VGA_SYNC_DETECT_MODE	3

typedef struct {
	unsigned char	src_AdcIndex;		//ADC index
	unsigned char	src_AdcRGBSwap;	//RGB swap
	unsigned char	src_SOYIndex;		//SOY input
} StructSourceSPAdcInfo;

typedef struct {
	unsigned char index;
	unsigned short meas_sta;
	unsigned short updn_sta;
	unsigned short updn_end;
} StructUpDnClamp;

enum _OFFLINE_MS_SRC{
	_OFFLINE_MS_SRC_PATTERN_JPEG = 0,
	_OFFLINE_MS_SRC_ADCHV1,
	_OFFLINE_MS_SRC_RESERVE1,
	_OFFLINE_MS_SRC_RESERVE2,
	_OFFLINE_MS_SRC_RAWHV1,
	_OFFLINE_MS_SRC_DEHV1,	//decomposite
	_OFFLINE_MS_SRC_RAWHV2,
	_OFFLINE_MS_SRC_DEHV2,
	_OFFLINE_MS_SRC_HDMI,
	_OFFLINE_MS_SRC_VDC,
	_OFFLINE_MS_SRC_VIDEO8,
};

//0x1802_1004[6:4] : Hsync Type Detection Auto Run Result
#define NO_SIGNAL									(0)
#define NOT_SUPPORT								(1)
#define YPBPR_SYNC									(2)
#define SERRATION_COMPOSITE_SYNC					(3)
#define XOR_OR_COMPOSITE_WITH_EQUALIZER			(4)
#define XOR_OR_COMPOSITE_WITHOUT_EQUALIZER		(5)
#define SEPARATE_SYNC								(6)
#define HSYNC_ONLY									(7)
#define SYNC_CHANGE								(8)

enum {
	SEPARATE_MODE = 0x00,
	CS_ON_H_MODE ,
	SOG_MODE ,
};

enum SP1_STABLE_CTRL
{
	_STB_CAP_WIN_RANGE_LSB=0,
	_STB_REALTIME_PERIOD,
	_STB_REALTIME_EN,
	_STB_CAP_RANGE,
	_STB_STABLE_PERIOD_TOL,
	_STB_POP_UP_STABLE,
	_STB_CAP_WIN_STEP,
	_STB_MISS_LOCK_LIMIT,
	_STB_STABLE_EN,
};

typedef enum _SYNCPROC_TABLE_TYPE{
	SYNCPROC_TABLE_VGA_MODE,
	SYNCPROC_TABLE_SCREEN_MODE_INFO
} SYNCPROC_TABLE_TYPE;

void SyncProc_InitYPbPr(void);
void SyncProc_ClampSignalOutputEnable(unsigned char sync_indicator, unsigned char enable);
void SyncProc_SOYSourceSelect(unsigned char sync_indicator, unsigned char soy_source_index);
unsigned char SyncProc_TimingModeHandler(int src, StructSourceInput *srcinput_pt);
void ADCSelectInput(int src, ADC_DATA_PATH adc_path, ADC_SOY_PATH soy_path, ADC_PATH_SWAP swap_path);
// CSW+ 0960607 for link in auto.c
void ScalerSetVPosition2(unsigned char display);
void Adjust_ADC_Clock(unsigned char display, unsigned char fast_lock_enable);

void SyncProc_FunctionDisable(int src);
unsigned char SyncProc_SyncHandler(int src);
void SyncProcessFunctionPowerDown(int src);
void SyncProc_hs_sync_source(unsigned char SrcType, unsigned char HsyncSrc);
void SyncProc_SetMinDiff(unsigned char display);
void YPbPr_SyncProc(void);
void VGA_SyncProc(void);

void SyncProc_Updw_Clamp_Ctrl(int src);
void SyncProc_Updw_Ctrl1_R(int src);
void SyncProc_Updw_Ctrl1_G(int src);
void SyncProc_Updw_Ctrl1_B(int src);
void SyncProc_Updw_Error_Stage1(void);
void SyncProc_Updw_Error_Stage2(void);
void SyncProc_Updw_Pvalue_Stage1(void);
void SyncProc_Updw_Pvalue_Stage2(void);
void SyncProc_Updw_Lock_Range(void);
void SyncProc_Updw_Clamp_Enable(bool enable);

void SyncProc_Check_UpDn_Stable(unsigned char display);
void reset_sp_status(void);//reset cap lock statuc
unsigned char check_sp_cap_unlock(void);//if ture: unlock. if false: stable

#endif /* _SYNCPROC_H */

/**
 *
 * @}
 */
