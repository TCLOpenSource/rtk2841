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
 * @version $Revision$
 */

/**
 * @addtogroup color
 * @{
 */

#ifndef _YPBPR_AUTO_H
#define _YPBPR_AUTO_H

/*#include "rtd_types.h"*/
/*============================ Module dependency  ===========================*/


/*===================================  Types ================================*/

/*================================== Variables ==============================*/

#define _MAX_PRESET_YPBPR 15


typedef struct _ADCGainOffset { /*Fix error by Will*/
	unsigned short Gain_R;	/*In fact, 11bits */
	unsigned short Gain_G;	/*In fact, 11bits */
	unsigned short Gain_B;	/*In fact, 11bits */
	unsigned short Offset_R;	/*In fact, 11bits */
	unsigned short Offset_G;	/*In fact, 11bits */
	unsigned short Offset_B;	/*In fact, 11bits */
} ADCGainOffset;



/*================================ Definitions ==============================*/

typedef struct {
	unsigned char   Y_RGB_idx;/*R = 0,G = 1,B = 2*/
	unsigned char   U_RGB_idx;/*R = 0,G = 1,B = 2*/
	unsigned char   V_RGB_idx;/*R = 0,G = 1,B = 2*/
} YUV_RGB_ADC;

typedef struct {
	unsigned short   h_start;
	unsigned short   h_end;
	unsigned short   v_start;
	unsigned short   v_end;
} TVColorBar;

typedef enum _AUTO_COLOR_TABLE_TYPE {
	AUTO_COLOR_TABLE_YPBPR_OFFSET,
} AUTO_COLOR_TABLE_TYPE;


/*================================== Function ===============================*/

/**
 *
 *
 *
 * @param <???> {comment}
 * @param <???> {comment}
 */
  #endif	/*#ifndef _YPBPR_AUTO_H*/

