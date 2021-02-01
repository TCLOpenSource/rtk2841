/*==========================================================================
  * Copyright (c)      Realtek Semiconductor Corporation, 2006
  * All rights reserved.
  * ========================================================================*/

/*================= File Description =======================================*/
/**
 * @file
 * 	This file is for scaler clock related functions.
 *
 * @author 	$Author$
 * @date		$Date$
 * @version	$Revision$
 * @ingroup	clock
 */

/**
 * @addtogroup clock
 * @{
 */

#ifndef _SCALER_CLOCK_H_
#define _SCALER_CLOCK_H_

/*============================ Module dependency  ===========================*/
//#include <rtd_types.h>

/*===================================  Types ================================*/
/*================================== Variables ==============================*/
/*================================ Definitions ==============================*/
#define _USER_DPLL_NCODE    10//12//16
#define _USER_APLL_NCODE 	3		///! NEVER change this setting !!!
#define _USER_APLL_PE 		100
#define _USER_APLL_n 		8
#define _MCLK_NCODE  		5		///! Do not exceed 20!
#define _DCLK_SPRED_RANGE	0		///! DCLK Spreading range : 0~15

//#define FIB_IC_PATCH 0

#define _PLL_D 0x00
#define _PLL_M 0x01
//new parameter
#define _APLL_N_VALUE_FOR_P_CODE 8
#define _SD_APLL_N_VALUE_FOR_I_CODE 3 //For SD timing 512 = 2^9
#define _HD_APLL_N_VALUE_FOR_I_CODE 3 //For HD timing 512 = 2^9

#define PLLPH0PATH_SHORT_PATH		0
#define PLLPH0PATH_LONG_PATH		1
#ifdef CONFIG_VGA_JUMP_PHASE_SOLVED
#define PLLPH0PATH	PLLPH0PATH_SHORT_PATH
#else //#ifdef CONFIG_VGA_JUMP_PHASE_SOLVED
#define PLLPH0PATH	PLLPH0PATH_SHORT_PATH
#endif //#ifdef CONFIG_VGA_JUMP_PHASE_SOLVED

// 0x1800_0534[17]
// Reserved for DPLL phase swallow circuit
// 0: Path0
// 1: Path1
#define DPLL_PHASE_SWALLOW_CIRCUIT_PATH0	0
#define DPLL_PHASE_SWALLOW_CIRCUIT_PATH1	1

#define DELAY_COMPENSATION_MODE_0	0
#define DELAY_COMPENSATION_MODE_1	1
#define DELAY_COMPENSATION_MODE_2	2
#define DELAY_COMPENSATION_MODE_3	3
#define DELAY_CP_MODE	DELAY_COMPENSATION_MODE_2


//[Code Sync][AlanLi][0980617][1]
extern unsigned char select_adc_vco_div;
//[Code Sync][AlanLi][0980617][1][end]

extern unsigned int panel_type; //for vodma lookup

typedef enum {
	PANEL_NO_DEFINED_1366x768 = 0,
	PANEL_SXGA_1280x1024,
	PANEL_HD1080_1920x1080,
} _PANEL_TYPE;

//Adjust M code state machine
typedef enum {
	DPLL_ADJUST_MCODE_NONE = 0x00,
	DPLL_ADJUST_MCODE_INITIAL,
	DPLL_ADJUST_MCODE_ADJUST,
	DPLL_ADJUST_MCODE_FINISH
} DPLL_ADJUST_MCODE_STATE;

typedef enum {
	DCLK_IN_RANGE = 0,		// In Panel Dclk Range
	DCLK_OVER_RANGE,		// Larger Than Dclk Max
	DCLK_UNDER_RANGE,		// Smaller Than Dclk Min
} DCLK_RANGE_TYPE;

typedef struct _DCLK_PARAM_TABLE{
	unsigned char					M_CODE;
	unsigned char					N_CODE;
	unsigned int					DCLK_OFFSET;
	unsigned char					DCLK_SEL;
}DCLK_PARAM_TABLE;

/*================================== Function ===============================*/
void drvif_clock_set_pll(unsigned int M_Code, unsigned int N_Code, unsigned int div, unsigned int CPC);

/*============================================================================*/
/**
 * Clock_SetMclk
 * Set Memory clock setup
 *
 * @param <void>		{ void }
 * @return 			{ void }
 *
 */
void Clock_SetMclk(unsigned char Mclk);

/*============================================================================*/
/**
 * drvif_clock_set_dclk
 * Set display clock setup
 *
 * @param <void>		{ void }
 * @return 			{ void }
 *
 */
unsigned char drvif_clock_set_dclk(unsigned short niHFreq, unsigned short niVActLen, unsigned int default_freq);
unsigned char drvif_clock_set_dclk2(unsigned short htotal, unsigned short vtotal, unsigned short usFrameRate);
unsigned char drvif_set_dclk_sync_tvbox(unsigned char mode);

unsigned char drvif_clock_set_dtg_uzu_div(void);
unsigned char drvif_clock_set_dtg_memc_div(void);
unsigned char drvif_clock_set_dtg_uzu_divByDisp(unsigned char _channel);
//--------------------------------------------------
// Description  : Adjust Dclk offset
// Input Value  : Dclk offset
// Output Value : None
//--------------------------------------------------
void drvif_clock_offset(unsigned short usDclkOffset);

/*============================================================================*/
/**
 * drvif_clock_set_aclk
 * Set ADC clock setup
 *
 * @param <unsigned short>	{ freq in KHz}
 * @return 			{ void }
 *
 */
unsigned char drvif_clock_set_aclk(StructDisplayInfo * p_dispinfo, int src, unsigned int usClock, unsigned char fast_lock_enable);

void drvif_clk_power_AdcApllEnable(int src);

void drvif_clock_pfd_calibration(void);

void drvif_clock_vodma_dclk(void);

unsigned char drvif_clock_cal_cpc(unsigned int M_Code,unsigned int N_Code); // CPC : charge pump current
//[Code Sync][AlanLi][0980617][1]
void drvif_clock_select_VCO_div(StructDisplayInfo * p_dispinfo);
//[Code Sync][AlanLi][0980617][1][end]

/**
 * This function is used to enable or disable the APLL power
 *
 * @param on_off: [input] you want to turn on or turn off the ADC.
 * @on_off: 0: Normal Run / 1: Power Down
 *
 * @return None
 *
 */
 void drvif_clock_apll_powercontrol(unsigned char on_off);

//DPLL_ADJUST_MCODE_STATE drvif_clock_dpll_M_adjust(void);

DCLK_RANGE_TYPE drvif_get_dclk_margin_check_result(void);

void check_dclk2_is_underflow(void);
void check_dclk_is_underflow(void);
void drvif_3ddma_DVTotal_Set(unsigned char div);
#endif // _SCALER_CLOCK_H_
/*======================== End of File =======================================*/
/**
*
* @}
*/

