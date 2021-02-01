/*=============================================
  * Copyright (c)      Realtek Semiconductor Corporation, 2005
  * All rights reserved.
  * ============================================ */

/*================= File Description ================= */
/**
 * @file
 * 	This file is for mode declarations.
 *
 * @author 	$Author: $
 * @date 	$Date: $
 * @version $Revision:  $
 * @ingroup
 */

/**
 * @addtogroup
 * @{
 */
#ifndef _MODE_H_
#define _MODE_H_

#ifdef __cplusplus
extern "C" {
#endif

//#include <rtd_types.h>
#include <scalercommon/scalerDrvCommon.h>

//--------------------------------------------------
// Definitions of VGA Search Mode Type
//--------------------------------------------------
enum _VGASearchModeType
{
	_PRESET_MODE_TYPE = 0,	//VGA Preset Mode
	_USER_MODE_TYPE,			//VGA User Mode
};

//--------------------------------------------------
// display ratio
//--------------------------------------------------
#define _DISPLAY_RATIO_90          	(90)
#define _DISPLAY_RATIO_92          	(92)
#define _DISPLAY_RATIO_95          	(95)
#define _DISPLAY_RATIO_96          	(96)
#define _DISPLAY_RATIO_97          	(97)
#define _DISPLAY_RATIO_98          	(98)
#define _DISPLAY_RATIO_99          	(99)
#define _DISPLAY_RATIO_100          	(100)

#define _HDMI_VGIP_SMART_FIT	1

//#define _USER_FIFO_MODE_NUM     16 // 48
//#define _MODE_FIRST                 	252
//#define _MODE_EXIST                 	253
//#define _MODE_NOSUPPORT          		254
//#define _MODE_NOSIGNAL              	255


//--------------------------------------------------
// Defination of Mode Polarity
//--------------------------------------------------
#define _SYNC_HN_VN	_BIT0
#define _SYNC_HP_VN	_BIT1
#define _SYNC_HN_VP	_BIT2
#define _SYNC_HP_VP	_BIT3

//--------------------------------------------------
// Tolerance of IHFreq and IVFreq
//--------------------------------------------------
#define _HFREQ_TOLERANCE      10
#define _VFREQ_TOLERANCE      10

//--------------------------------------------------
// Macro of Mode Stable Flag
//--------------------------------------------------

//clear on-line measure flags: clear over range, polarity change status
#ifdef CONFIG_DUAL_CHANNEL  // There are two channels
#define MODE_CLEAR_ONMS_FLAG()	IoReg_SetBits(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) ? ONMS_onms2_status_reg : ONMS_onms1_status_reg,  (_BIT4|_BIT3|_BIT1|_BIT0));
#define MODE_CLEAR_ONMS_FLAG_FOR_2DCVT3D()	/*IoReg_Write32(SYNC_PROCESSOR_SP_MS2STUS_VADDR , 0x3ff);*/
#else
#define MODE_CLEAR_ONMS_FLAG()	IoReg_SetBits(/*Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) ? SYNCPROCESSOR_SP_MS2STUS_VADDR : */ONMS_onms1_status_reg,  (_BIT14|_BIT15|_BIT8|_BIT9));
#define MODE_CLEAR_ONMS_FLAG_FOR_2DCVT3D()	//IoReg_Write32(SYNCPROCESSOR_SP_MS2STUS_VADDR , 0x3ff);
#endif

//extern unsigned short HDMIDiditalMeasureIVH;

//--------------------------------------------------
// MISC config
//--------------------------------------------------
//USER:LewisLee DATE:2016/01/09
//enable more watchdog for HDMI source
//to fix HDMI plug in/out, have sjort time garbage
//Enable Vtotal active measure in DMA VGIP ONMS @Crixus 20161111
#define HDMI_WATCHDOG_NEW_ENABLE	1

//USER:LewisLee DATE:2016/12/02
//enable Hsync measure over range watchdog
//it need more test, disable first
//#define HDMI_HS_MEAS_OVER_RANGE_WD_ENABLE	1

//--------------------------------------------------
// Preset Mode
//--------------------------------------------------
// oliver-, move to scalerDrvCommon.h
/*
enum PresetModeDef
{
	_MODE_640x350_70HZ = 0,		// Mode 00:
	_MODE_640x350_85HZ,			// Mode 01:
	_MODE_640x400_56HZ,			// Mode 02:
	_MODE_640x400_70HZ,			// Mode 03:
	_MODE_640x400_85HZ,			// Mode 04:
	_MODE_720x400_50HZ,			// Mode 05:
	_MODE_720x400_70HZ,			// Mode 06:
	_MODE_720x400_85HZ,			// Mode 07:
	_MODE_720x480_60HZ,			// Mode 08:
	_MODE_640x480_50HZ,			// Mode 09:
	_MODE_640x480_60HZ,			// Mode 10:
	_MODE_640x480_67HZ,			// Mode 11:
	_MODE_640x480_70HZ,			// Mode 12:
	_MODE_640x480_72HZ,			// Mode 13:
	_MODE_640x480_75HZ,			// Mode 14:
	_MODE_640x480_85HZ,			// Mode 15:
	_MODE_800x600_50HZ,			// Mode 16:
	_MODE_800x600_56HZ,			// Mode 17:
	_MODE_800x600_60HZ,			// Mode 18:
	_MODE_800x600_72HZ,			// Mode 19:
	_MODE_800x600_75HZ,			// Mode 20:
	_MODE_800x600_85HZ,			// Mode 21:
	_MODE_832x624_75HZ,			// Mode 22:
	_MODE_1024x768_50HZ,			// Mode 23:
	_MODE_1024x768_60HZ,			// Mode 24:
	_MODE_1024x768_66HZ,			// Mode 25:
	_MODE_1024x768_70HZ,			// Mode 26:
	_MODE_1024x768_75HZ,			// Mode 27:
	_MODE_1024x768_85HZ,			// Mode 28:
	_MODE_1152x864_60HZ,			// Mode 29:
	_MODE_1152x900_66HZ,			// Mode 30:
	_MODE_1280x720_50HZ,			// Mode 31:
	_MODE_1280x720_60HZ,			// Mode 32:
	_MODE_1280x720_60HZ_RB,		// Mode 33:
	_MODE_1280x720_85HZ,			// Mode 34:
	_MODE_1280x768_50HZ,			// Mode 35:
	_MODE_1280x768_60HZ,			// Mode 36:
	_MODE_1280x768_75HZ,			// Mode 37:
	_MODE_1280x768_85HZ,			// Mode 38:
	_MODE_1280x960_50HZ,			// Mode 39:
	_MODE_1280x960_60HZ,			// Mode 40:
	_MODE_1280x960_75HZ,			// Mode 41:
	_MODE_1280x960_85HZ,			// Mode 42:
	_MODE_1280x1024_50HZ,		// Mode 43:
	_MODE_1280x1024_60HZ,		// Mode 44:
	_MODE_1280x1024_60HZ_RB,		// Mode 45:
	_MODE_1280x1024_72HZ,		// Mode 46:
	_MODE_1280x1024_75HZ,		// Mode 47:
	_MODE_1280x1024_85HZ,		// Mode 48:
	_MODE_1360x768_60HZ,			// Mode 49:
	_MODE_1360x768_60HZ_RB,		// Mode 50:
	_MODE_1366x768_60HZ,			// Mode 51:	//VGA1366x768@60
	_MODE_1400x1050_50HZ,		// Mode 52:
	_MODE_1400x1050_60RHZ,		// Mode 53:(Reduced Blanking)
	_MODE_1400x1050_60HZ,		// Mode 54:
	_MODE_1400x1050_75HZ,		// Mode 55:
	_MODE_1440x900_60HZ,			// Mode 56:
	_MODE_1440x900_60RHZ,		// Mode 57:(Reduced Blanking)
	_MODE_1440x900_75HZ,			// Mode 58:
	_MODE_1440x900_85HZ,			// Mode 59:
	_MODE_1600x1200_50HZ,		// Mode 60:
	_MODE_1600x1200_60HZ,		// Mode 61:
	_MODE_1600x1200_65HZ,		// Mode 62:
	_MODE_1600x1200_70HZ,		// Mode 63:
	_MODE_1680x1050_50HZ,		// Mode 64:
	_MODE_1680x1050_60HZ,		// Mode 65:
	_MODE_1680x1050_60RHZ,		// Mode 66:(Reduced Blanking)
	_MODE_1680x1050_75HZ,		// Mode 67:
	_MODE_1680x1050_85HZ,		// Mode 68:
	_MODE_1920x1080_50HZ,		// Mode 69:
	_MODE_1920x1080_60HZ,		// Mode 70:
	_MODE_1920x1080_60HZ_138,	// Mode 71:(Reduced Blanking)
	_MODE_1920x1080_60HZ_148,	// Mode 72:(Reduced Blanking)
	_MODE_1920x1080_75HZ,		// Mode 73:


	_MODE_VGA_480I,				// Mode 74: RGB 480i
	_MODE_VGA_576I,				// Mode 75: RGB 576i
	_MODE_VGA_480P,				// Mode 76: RGB 480p
	_MODE_VGA_576P,				// Mode 77: RGB 576p
	_MODE_VGA_720P50,				// Mode 78: RGB 720px50Hz
	_MODE_VGA_720P60,				// Mode 79: RGB 720px60Hz
	_MODE_VGA_1080I25,			// Mode 80: RGB 1080ix50Hz
	_MODE_VGA_1080I30,			// Mode 81: RGB 1080ix60Hz
	_MODE_VGA_1080P50,   			// Mode 82: VGA 1920x1080ix50HZ (802R) //CSW+ 0971001
	_MODE_VGA_1080P60,	 		// Mode 83: VGA 1920x1080ix60HZ (802R) //CSW+ 0971001
	//[Code Sync][AlanLi][0980527][1]
	//add MAC timing
	_MODE_1024x576_60HZ,			// Mode 84:for MAC
	_MODE_1920x1080_60Hz_173MAC,    // Mode 85:for MAC
	//[Code Sync][AlanLi][0980527][1][end]
	_MODE_PC_TIMING_END = _MODE_1920x1080_60Hz_173MAC,	//75 By Gilbert(2009/6/19) Set the end point of PC Timing

//for YPbPr & Video8
	_MODE_480I,					// Mode 86
	_MODE_576I,					// Mode 87:
	_MODE_480P,					// Mode 88: YPbPr  720x 480px50HZ (802R)
	_MODE_576P,					// Mode 89: YPbPr  720x 576px50HZ (802R)
	_MODE_720P50,					// Mode 90: YPbPr 1280x 720px50HZ
	_MODE_720P60,					// Mode 91: YPbPr 1280x 720px60HZ (802R)
	_MODE_1080I25,					// Mode 92: YPbPr 1920x1080ix50HZ (802R)
	_MODE_1080I30,					// Mode 93: YPbPr 1920x1080ix60HZ (802R)
	_MODE_1080P50,				// Mode 94: YPbPr 1920x1080px50HZ (802R)
	_MODE_1080P60,				// Mode 95:  YPbPr 1920x1080px60HZ (802R)



	// CSW+ 0971225 Add YPbPr timing 1080P/25HZ/24HZ/23.97HZ/29.97HZ/30HZ
	_MODE_1080P23,				// Mode 96: YPbPr 1920x1080px23.976HZ (802R)
	_MODE_1080P24,				// Mode 97: YPbPr 1920x1080px24HZ (802R)
	_MODE_1080P25,				// Mode 98: YPbPr 1920x1080px25HZ (802R)
	_MODE_1080P29,				// Mode 99: YPbPr 1920x1080px29.976HZ (802R)
	_MODE_1080P30,				// Mode 100: YPbPr 1920x1080px30HZ (802R)};
// for HDMI :Justin
	_MODE_1080PM50,				// Mode 101:  HDMI 960x1080px50HZ (802R) //forster modified 050823
	_MODE_1080PM60,				// Mode 102:  HDMI 960x1080px60HZ (802R) //forster modified 050823
	_MODE_1920x1200_60HZ,		// Mode 103
	_MODE_NEW
};
*/

//--------------------------------------------------
// table type for table registration
//--------------------------------------------------
typedef enum _MODE_TABLE_TYPE {
	MODE_TABLE_HDMI,
	MODE_TABLE_PRESET,
	MODE_TABLE_YPBPR,
	//MODE_TABLE_NOTSUPPORT_TIMING,
	//MODE_TABLE_SKIPTIMING,
	MODE_TABLE_VGA,
	MODE_TABLE_SCREEN_MODE_INFO,
}MODE_TABLE_TYPE;


typedef enum _MODE_IDENTIFY_TYPE{
	CUSTOMER_EXTRA_CONDITION = 0x00,
	JUDGE_CONFUSE_MODE,
	HDMI_JUDGE_CONFUSE_MODE,
	HDMI_JUDGE_UNSUPPORT_MODE,
	USER_DEF_CONFUSE_MODE,
	USER_DEF_MODETABLE_SIZE,
	USER_DEF_MODETABLE_ACCEPTIVE,
	USER_DEF_MODETABLE_ACCEPTIVE_SIZE,
	MODE_VGA_USER_FIFO,
} MODE_IDENTIFY_TYPE;

//--------------------------------------------------
// mode table structure
//--------------------------------------------------
typedef struct
{
	unsigned short ModeID;
	unsigned char PolarityFlag;			// Acceptable polarity flags (see _SYNC_HN_VN, _SYNC_HP_VN, _SYNC_HN_VP, _SYNC_HP_VP)
	unsigned short IHWidth;				// Input Horizontal Width
	unsigned short IVHeight;				// Input Vertical Height
	unsigned short IHFreq;				// Input Horizontal Frequency (Unit: 100Hz)
	unsigned short IVFreq;				// Input Vertical Frequency (Unit: 0.1Hz)
	unsigned char IHFreqTolerance;		// Input Horizontal Frequency Tolerance (Unit: 100Hz)
	unsigned char IVFreqTolerance;		// Input Vertical Frequency Tolerance (Unit: 0.1Hz)
	unsigned short IHTotal;				// Input Horizontal Total Length
	unsigned short IVTotal;				// Input Vertical Total Length
	unsigned short IHStartPos;			// Input Horizontal Start Position
	unsigned short IVStartPos;			// Input Vertical Start Position
#ifdef CONFIG_ASPECT_BY_ASPECT_VALUE
	unsigned char AspectRatioValueH;		// Aspect ratio value H
	unsigned char AspectRatioValueV;		// Aspect ratio value V
#endif
} ModeTableType;

#if 0 // marked by hsliao@20100503
typedef struct
{
    unsigned short IHWidth;                   // Input Horizontal Width
    unsigned short IVHeight;                  // Input Vertical Height
    unsigned short IVFreq;           // Input Vertical Frequency(50HZ or 60HZ)
    unsigned char IInterlace;           // Interlace frame or Progress frame
    unsigned char I4_3Rario;           // (4:3) or (16:9) Display Rato
    unsigned short IHTotal;                   // Input Horizontal Total Length
    unsigned short IHStartPos;                // Input Horizontal Start Position
    unsigned short IVStartPos;                // Input Vertical Start Position
} Video16ModeTableType;
#endif

//======= checkType =======//
#define H_HIGH_PULSE_WIDTH 	0x01
#define H_COUNT 				0x02

//======= chargeCondition =======//
#define OVER					0x01
#define UNDER					0x02
#define OVER_AND_EQUAL		0x04
#define UNDER_AND_EQUAL		0x08
#define BY_RANGE				0x10

typedef struct
{
	unsigned char modeIdx;
	unsigned char checkType;
	unsigned short checkValue;
	unsigned char checkValueMax;
	unsigned char chargeCondition;
	unsigned short thresholdValue;
}ModeSkipTimingType;

enum _MODE_RESULT
{
	_MODE_NOSIGNAL	= 0xFF,
	_MODE_NOSUPPORT	= 0xFE,
	_MODE_NOCABLE		= 0xFD,
	_MODE_SUCCESS		= 0xFC,
	_MODE_DETECT		= 0xFB,
	_MDOE_UNDKOWN	= 0xFA,
};

typedef enum _COUNTER_TYPE{
	COUNTER_TYPE_2048		= 0x00,
	COUNTER_TYPE_4096		= 0x01,
	COUNTER_TYPE_8192		= 0x02,
	COUNTER_TYPE_16383	= 0x03,
}COUNTER_TYPE;


/*unsigned char drvif_mode_onlinemeasure(unsigned char mode);*/
 unsigned char drvif_mode_offlinemeasure(unsigned char source, unsigned char mode, StructDisplayInfo* p_dispinfo, ModeInformationType* p_timinginfo);
void drvif_mode_disablechannelproc(unsigned char display);
//DMA oline measure related API
void drvif_mode_enableonlinemeasure(unsigned char channel);
void drvif_mode_disableonlinemeasure(unsigned char channel);
void drvif_mode_onlinemeasure_setting(unsigned char channel, int src, unsigned char wdgenable, unsigned char interruptenable);
unsigned char drvif_mode_check_onlinemeasure_status(unsigned char channel);
#ifdef CONFIG_FORCE_RUN_I3DDMA
unsigned char drvif_mode_check_dma_onlinemeasure_status(void);
void drvif_mode_disable_dma_onlinemeasure(void);
void drvif_mode_enable_dma_onlinemeasure(void);
void drvif_mode_dma_onlinemeasure_setting(unsigned char wdgenable, unsigned char interruptenable);
#endif

/*unsigned char drvif_mode_checkstable(void);*/
unsigned char drvif_mode_checkstableBeforStable(void);
void drvif_mode_disablevgip(unsigned char display);
#if 0
unsigned short drvif_mode_getHDMIDiditalMeasureIVH(void);
#endif //#if 0
void mode_set_dispinfo_from_table(int src, StructDisplayInfo* p_dispinfo, ModeInformationType* p_timinginfo);
unsigned char mode_searchmodetable(int src, StructDisplayInfo* p_dispinfo, ModeInformationType* p_timinginfo);
void drvif_mode_resetmode(unsigned char display);
unsigned char hdmi_mode_identifymode(unsigned char mode_index);
unsigned char adc_mode_identifymode(int src, unsigned char mode_index, ModeInformationType* p_timinginfo);

unsigned int YPbPr_GetMeasureHstartPos(void);
void clear_online_status(unsigned char display);//Clear online status
//void Scaler_InitVGAModeInfo(unsigned char mode);

#ifdef ENABLE_DRIVER_I3DDMA
int Mode_Get_ypbpr_3D_adjustment_hStart(unsigned int mode);
int Mode_Get_ypbpr_3D_adjustment_vStart(unsigned int mode);
#endif
unsigned char drvif_mode_customer_identify_regTable(MODE_IDENTIFY_TYPE index, void *ptr);
void drvif_mode_abl_margin_Setting(void);
 unsigned char drvif_mode_get_mode_ID(unsigned char search_cnt);
void set_hdmi_identify_mode(unsigned char mode);
unsigned char get_hdmi_idntify_mode(void);
unsigned int Hdmi_Search_Mode(unsigned int *mode_id);
unsigned int Hdmi_get_startpos(unsigned int tbl_index, unsigned int *hstart, unsigned int *vstart);
void drvif_aspectratio_disablefrc(unsigned char display);

unsigned int Hdmi_get_startpos(unsigned int tbl_index, unsigned int *hstart, unsigned int *vstart);
void set_ONMS1_V_counter(COUNTER_TYPE type);
void get_ONMS1_V_counter(void);
void set_ONMS1_H_counter(COUNTER_TYPE type);
void get_ONMS1_H_counter(void);

void set_ONMS3_V_counter(COUNTER_TYPE type);
void get_ONMS3_V_counter(void);
void set_ONMS3_H_counter(COUNTER_TYPE type);
void get_ONMS3_H_counter(void);


void vga_clock_online_setting(unsigned char display);//before clock adjust. we only check on3_vs_per_timeout bit13
unsigned char vga_clock_check_onlinemeasure_status(unsigned char display);//Return FALSE: Online measure has error status. for clock chnage using
void vga_clock_clear_online_status(unsigned char display);//this is for clock adjust use. clear h error status 

unsigned char drvif_AV_Detect_OffLine_Signal(unsigned char source);

#ifdef __cplusplus
}
#endif


/*
extern unsigned short tAV_PRESET_TABLE[][5]; //for P¥d

extern ModeTableType tINPUTMODE_HDMI_TABLE[_MAX_HDMI_MODE];
*/
/**
 *
 * @}
 */

#endif /* #define _MODE_H_ */

