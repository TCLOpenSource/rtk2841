/* ----------------------------------------------------------------------------
 File Name: DTMBIP_User_Define.h

 Description:

 Version 2.0 : Created   2013.03.05  Sharp Wang	 
				 2.2 : Modified  2013.05.20  Sharp Wang
 ---------------------------------------------------------------------------- */ 
#ifndef __DTMB_DEMOD_REALTEK_H_USER_H__
#define __DTMB_DEMOD_REALTEK_H_USER_H__
//#ifndef __DTMBIP_USER_H__
//#define __DTMBIP_USER_H__

#include <linux/string.h>
#include <linux/kernel.h>
#include <linux/delay.h>
#include <mach/io.h>
#include "dtmb_demod_rtk_type.h"
#include "dtmb_demod_rtk.h"
#include "dtmb_demod_base.h"
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
/**********************************
According different platform, user needs to implement function by self.
**********************************/

/* print function */
/*
#define DTMBTBX_Print(x) //printf x
#define Write_I2C	HD2311_I2C_WRITE
#define Read_I2C	HD2311_I2C_READ
#define Sleep		HD2311_Delay
#define Demod_HW_Reset	HD2311_HwReset
#define SetTuner HD2311_SetTuner
*/
void DTMBIP_MonitorTask(void);
UINT8 DTMBIP_WriteRegister(UINT16 Register,UINT8 Data);
UINT8 DTMBIP_ReadRegister(UINT16 Register,UINT8 *Data);
void DTMBIP_Wait(UINT16 millisecond);
/* HW Reset, It needs to implement by HW designition*/
void DTMBIP_HWReset(void);

/* Set Tuner Frequency */

//UINT8 DTMBIP_TunerInit(void);
BOOL DTMBIP_TunerLock(UINT32 Frequency);


/***********************************
User Function
***********************************/
/*
HD2311 Get Signal Strength/Quality Functions
*/
/* If tuner driver can offer signal strength/quality function, please use them */
UINT8 DTMBIP_GetSignalStrength(UINT8 *SignalStrength);
UINT8 DTMBIP_GetSignalQuality(UINT8 *SignalQuality);

/*
System Initailization,  sometimes, it needs to modify depends on Platforms.
*/
UINT8 DTMBIP_Init(void);

/*
HD2311 Lock Frequency Function
*/
BOOL DTMBIP_DTMBSetFrequency(UINT32 Frequency);

/* Manual Set Dtmb Frequency Function, the input variables are refer to HDICType.h*/
BOOL DTMBIP_DTMBManualSetFrequency(UINT32 Frequency,UINT8 CarrierMode,UINT8 mode,UINT8 rate,UINT8 interleaverLength,UINT8 pnmode,UINT8 PnVariable);

/*
HD2311 function that judges if demod is lock
*/
BOOL DTMBIP_IsDemodLocked(BOOL PrintInfo,UINT8 *presult,UINT8 *locked, UINT8 *Status);
#endif