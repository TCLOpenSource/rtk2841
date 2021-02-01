/*=============================================
  * Copyright (c)      Realtek Semiconductor Corporation, 2005
  * All rights reserved.
  * ============================================ */

/*================= File Description ================= */
/**
 * @file
 * 	This file is for mode related functions.
 *
 * @author 	$Author: forster $
 * @date 	$Date: 2006-04-19 19:37:42 +0800 (?Ÿæ?ä¸? 19 ?›æ? 2006) $
 * @version 	$Revision: 1536 $
 * @ingroup 	auto
 */

 /**
 * @addtogroup auto
 * @{
 */

 #ifndef _AUTO_H
#define _AUTO_H

/*================ Module dependency  =============== */
//#include <rtd_types.h>
#include <tvscalercontrol/scaler/scalerstruct.h>
#include <tvscalercontrol/scalerdrv/mode.h>
typedef unsigned char UINT8;
typedef unsigned short UINT16;
typedef unsigned int UINT32;

/*==================== Definitions ================= */
//[Code Sync][AlanLi][0980525][1]
//sync auto adjust flow
#define GET_AUTOREADY()		(ucAutoControl & _BIT1)
#define SET_AUTOREADY()  	(ucAutoControl |= _BIT1)
#define CLR_AUTOREADY()  	(ucAutoControl &= ~_BIT1)
#define GET_AUTO_FINISH()		(ucAutoControl & _BIT6)
#define SET_AUTO_FINISH()  	(ucAutoControl |= _BIT6)
#define CLR_AUTO_FINISH()  	(ucAutoControl &= ~_BIT6)
#define GET_AUTO_CONFIG_DOING()		(ucAutoControl & _BIT7)
#define SET_AUTO_CONFIG_DOING()  	(ucAutoControl |= _BIT7)
#define CLR_AUTO_CONFIG_DOING()  	(ucAutoControl &= ~_BIT7)
//[Code Sync][AlanLi][0980525][1][end]

//------ERROR message : SUCCESS(MSB=0)
#define ERROR_SUCCEED   	(0x00)
#define ERROR_SUCCESS_1 	(0x01)
#define ERROR_SUCCESS_2 	(0x02)
#define ERROR_SUCCESS_4 	(0x04)
#define ERROR_SUCCESS_8 	(0x08)
#define ERROR_SUCCESS_16	(0x10)
#define ERROR_SUCCESS_32	(0x20)
#define ERROR_SUCCESS_64	(0x40)
//------ERROR message : ERROR(MSB=1)
#define ERROR_FINISH             (0xf7)
#define ERROR_NOTACTIVE 	(0xf8)
#define ERROR_NOISE_TOO_BIG (0xf9)
#define ERROR_TOO_SMALL 	(0xfa)
#define ERROR_TOO_BIG   	(0xfb)
#define ERROR_INPUT 		(0xfc)
#define ERROR_TIMEOUT   	(0xfd)
#define ERROR_ABORT 		(0xff)

//#if (_AUTO_COLOR)
#define VERTICAL_MARGIN 		(0x30)
#define HORIZONTAL_MARGIN   	(0x30)
#define SELECT_RED  				(0x01)
#define SELECT_GREEN			(0x02)
#define SELECT_BLUE 			(0x04)

#define SELECT_PR                       (0x01)//0          // Ken
#define SELECT_Y                         (0x02)// 1
#define SELECT_PB                       (0x04)// 2

#define SELECT_RGB  		(SELECT_RED | SELECT_GREEN | SELECT_BLUE)
//#endif


#define AUTO_CLOCK_PRECISION		(1)// 2

#define VGA_AWB_CHECK_LEVEL	0x180

#define _AUTO_FAST_FLOW			1

#define AutoColor_Y  1 //GREEN
#define AutoColor_U  0 //BLUE
#define AutoColor_V  2 //RED
#define R_ADC_Dragon 0
#define G_ADC_Dragon 1
#define B_ADC_Dragon 2
#define _Y100UV75		0
#define _Y100UV100		1
#define _Y75UV75		2
//--------------------------------------------------
// Color Source Select for Detection
//--------------------------------------------------
//#define COLORS_BLUE                (0x00)
//#define COLORS_GREEN             (0x01)
//#define COLORS_RED                 (0x02)
#define COLORS_RED                 (0x00)
#define COLORS_BLUE                (0x01)
#define COLORS_GREEN               (0x02)
#define COLORS_ALL                 (0x03)

#define _COLORS_RED  		(0x00)//0x02
#define _COLORS_GREEN		(0x02)//0x01
#define _COLORS_BLUE 		(0x01)//0x00
#define _COLOR_MAX   		(0x20)
#define _COLOR_MIN   		(0x00)
//--------------------------------------------------
// Hardware Auto Phase Step
//--------------------------------------------------
#define HWAUTO_STEP_1              (0x00)
#define HWAUTO_STEP_2              (0x01)
#define HWAUTO_STEP_4              (0x02)
#define HWAUTO_STEP_8              (0x03)
#define HWAUTO_STEP_16             (0x04)

#define HWAUTOSTEPNUM(x)		(x)
#define HWAUTOSTEPSTART(x) 	(x)


typedef struct _AUTO_PARAMETER {
	unsigned char ucFieldControl;
	unsigned short usAutoHStart;
	unsigned short usAutoHEnd;
	unsigned short usAutoVStart;
	unsigned short usAutoVEnd;
	unsigned short ucNMR;
	unsigned short ucNMG;
	unsigned short ucNMB;
	unsigned char ucColor;
	unsigned char ucFieldEnable;
	unsigned char ucVBoundSearch;
}AUTO_PARAMETER, * LP_AUTO_PARAETER;

typedef enum _AUTO_TABLE_TYPE{
	AUTO_TABLE_VGA_MODE,
	AUTO_TABLE_VGA_OFFSET,
	AUTO_TABLE_YPBPR_OFFSET,
	AUTO_TABLE_SCREEN_MODE_INFO
} AUTO_TABLE_TYPE;

typedef enum {
	ADCTYPE_YPBPR = 0,
	ADCTYPE_SCART_RGB,
	ADCTYPE_VGA,
	ADCTYPE_SCART_MAX = ADCTYPE_VGA,
} ADC_TYPE_INDEX;

/*==================== Variables ================= */
#ifdef _AUTO_C
    #define extern
#else
    #define extern   extern
#endif                                  /* def _COLOR_C */

extern unsigned char  ucAutoControl;
extern AUTO_PARAMETER  stAUTO_PARA;
extern unsigned char auto_waitivs(unsigned char display);

#undef extern


/*==================== Functions ================== */
void drvif_auto_setcolorgainoffset(unsigned char colorindex, unsigned short parameter);
void drvif_auto_ResetOffset(unsigned char ucReset);
unsigned char drv_auto_pre_check(unsigned char *select_result);
void drvif_set_gain_from_table(int src);
void drvif_set_offset_from_table(int src);
void drvif_auto_gettargetvalue(unsigned char display, unsigned short* max_value, unsigned short* min_value, unsigned char color);

unsigned char drvif_measure_v_position(unsigned char display, unsigned char NMR_V, unsigned char NMG_V, unsigned char NMB_V, unsigned short *v_start, unsigned short *v_end, unsigned char color);
unsigned char drvif_measure_h_position(unsigned char display, unsigned short NM_H, unsigned short *h_start, unsigned short *h_end, unsigned char color);
unsigned char drvif_ypp_auto_phase_pre_setup(unsigned char display, unsigned char NMR_V, unsigned char NMG_V, unsigned char NMB_V, unsigned char color);

//[Code Sync][AlanLi][0980525][1]
void Reset_YPP_Auto_Phase_SmartFit_Setting(void);
unsigned char drv_auto_get_phase_flag(void);
unsigned char drvif_ypbpr_auto_phasedo_start(unsigned char display);
unsigned char drvif_ypbpr_auto_phasedo_WaitFinish(unsigned char display);

//leochen add for Self-AWB
void drvif_SelfAWB_gettargetvalue(UINT16* target, UINT8 color, UINT8 src);
void drvif_get_default_gainvalue(UINT16* gain_value_r, UINT16* gain_value_g, UINT16* gain_value_b ,UINT8 src);
unsigned char drvif_self_awb_calculate_target_diff(int src , UINT8 ucColor);
void Scaler_PrintADCGainInRegister(void);
void Scaler_PrintADCOffsetInRegister(void);

void auto_AdcGainAdjustReset(void);
void drvif_SelfAWB_GetTargetDiff(UINT16 *a_pusDiff_R, UINT16 *a_pusDiff_G, UINT16 *a_pusDiff_B);
UINT16 drvif_SelfAWB_GetTargetDiff_R(void);
UINT16 drvif_SelfAWB_GetTargetDiff_G(void);
UINT16 drvif_SelfAWB_GetTargetDiff_B(void);
unsigned char get_adc_abl_function(void);
void set_adc_abl_function(unsigned char enable);

unsigned char drvif_self_awb_get_target_diff_proc(int src);
unsigned char drvif_auto_measurecolor(unsigned char display, unsigned char color, unsigned char margin, unsigned short* rev);

unsigned char External_ADC_Calibration_proc(int src);
unsigned char Internal_ADC_Calibration_proc(int src);
void Reset_ADC_Gain_Offset(void);
void OTP_ADC_Calibration_proc(void);
void  drvif_set_smartfit_auto_field_ctrl(unsigned char display);
unsigned int get_sod_software_auto_phase(unsigned short phase);

unsigned char drvif_adc_autobalance_fast(unsigned char display);
unsigned char drvif_adc_autobalance_standard(unsigned char display);
unsigned char drvif_adc_autobalance(unsigned char display);

unsigned char drvif_auto_clockdo(StructScreenModeInfo *p_screenInfo, unsigned char display, unsigned char NM,unsigned char color);
unsigned char drvif_auto_phasedo(StructScreenModeInfo *p_screenInfo, unsigned char display, unsigned char NM,unsigned char color);
unsigned char drvif_auto_positiondo(StructScreenModeInfo *p_screenInfo, unsigned char display, unsigned char NM,unsigned char color);
void drv_auto_clock_fail_handler(StructScreenModeInfo *stScreenModeCurrInfo, unsigned char display, unsigned char Curr_PosH, unsigned char Curr_Clock, unsigned char Curr_Phase);
void drv_auto_phase_fail_handler(StructScreenModeInfo *stScreenModeCurrInfo, unsigned char display,unsigned char Curr_Phase);
void drv_auto_position_fail_handler(StructScreenModeInfo *stScreenModeCurrInfo, unsigned char display, unsigned char Curr_PosH, unsigned char Curr_PosV, unsigned char Curr_Phase, unsigned char Curr_Clock);

void drv_adc_clock_adjust(StructScreenModeInfo *stScreenModeCurrInfo, unsigned char display, unsigned char fast_lock_enable);

#endif
/**
 * @}
 */

