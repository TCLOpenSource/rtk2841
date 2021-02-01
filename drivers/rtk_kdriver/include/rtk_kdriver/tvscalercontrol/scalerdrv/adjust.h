/*==========================================================================
  * Copyright (c)      Realtek Semiconductor Corporation, 2006
  * All rights reserved.
  * ========================================================================*/

/*================= File Description =======================================*/
/**
 * @file
 * 	This file is for timer related functions.
 *
 * @author 	$Author$
 * @date		$Date$
 * @version	$Revision$
 * @ingroup	timer
 */

/**
 * @addtogroup timer
 * @{
 */

#ifndef _ADJUST_H_
#define _ADJUST_H_

#ifdef __cplusplus
extern "C" {
#endif

//#include <rtd_types.h>

//--------------------------------------------------
// Definitions of Display Delay
//--------------------------------------------------
//Modify by frank for CB/cr #define _CAPTURE_HDELAY                 	3
#define _CAPTURE_HDELAY                 	3 // 2
#define _PROGRAM_HDELAY                 	0 // 10   CSW* modify 0961004 to adjust IHS delay in window H position
#define _PROGRAM_VDELAY                 	15// VIP needs v start >=15, for newMCNR ATV pre-load fail issue change to 10
//#define _PROGRAM_VDELAY                 	5// 2 it must larger than 4 or de-interlace will result in problem *: forster modified 071029
//extern unsigned char _PROGRAM_VDELAY;		//CSW+ 20090707	for xoceco K8258 timing448
#define _MEASURE_HDEALY                 	7
#define _HSTARTBIAS					200
#ifdef CONFIG_FRC_OPEN_FIX_LAST_LINE
#define GET_SCALER_FRC_OPEN_FIX_LASTLINE()	1
#else
#define GET_SCALER_FRC_OPEN_FIX_LASTLINE()	0
#endif

#define _FRC_MODE_IVS2DVS_LINE_1				3
#define _FRC_MODE_IVS2DVS_LINE_2				3
#define _FRC_MODE_IVS2DVS_PIXEL_1				0
#define _FRC_MODE_IVS2DVS_PIXEL_2				0

void drv_adjust_syncprocessormeasurestart(void);
//void Adjust_DclkOffset(unsigned short usDclkOffset);
void drv_adjust_spreadspectrumrange(unsigned char ucSpreadRange);

//forster modified 071002
//void  drv_adjust_measureivs2dvsdelay(void);
unsigned char drv_adjust_measureivs2dvsdelay(void);
unsigned int  Measure_GattingDvst(unsigned char display);

void drv_adjust_spreadspectrumrange(unsigned char ucSpreadRange);
unsigned char drv_read_spreadspectrumrange(void);
void drvif_clear_ivs2dvsdelay(void);
void drvif_set_frc_ivs2dvsdelay_line(unsigned short iv2dv_line1, unsigned short iv2dv_line2, unsigned char ucDelayField);
void drvif_set_frc_ivs2dvsdelay_pixel(unsigned short iv2dv_pixel1, unsigned short iv2dv_pixel2, unsigned char ucDelayField);
void drvif_adjust_spreadspectrumrange_FMDIV(unsigned char ucValue);
unsigned char drvif_read_spreadspectrumrange_FMDIV(void);

#ifdef __cplusplus
}
#endif

#endif // _ADJUST_H_

/**
 * @}
 */

