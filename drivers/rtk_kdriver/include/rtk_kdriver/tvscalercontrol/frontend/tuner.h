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

#ifndef _TUNER_H
#define _TUNER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "auto_conf.h"

//=================================================================
//Driver
//=================================================================
/*=============================================================*/
/**
	This routine will set init.
	@param			
	@return 			
*/
void CTunerInit(unsigned char mode);
/*=============================================================*/
/**
	This routine will set TV to specific frequency.
	@param			freq					frequency
	@return 			Return the status code	_TURE,_FALSE
*/
unsigned char CTunerSetFreq(unsigned int freq);

/*=============================================================*/
/**
	This routine will set TV to specific frequency  in Search mode
	@param			freq					frequency
	@return 			Return the status code	_TURE,_FALSE
*/
unsigned char CTunerSetFreqSearch(unsigned int freq);
/*=============================================================*/
/**
	This routine will get TV to current frequency.
	@param			void
	@return 			Return the freq	frequency
*/
unsigned int CTunerGetFreq(void);
/*=============================================================*/
/**
	This routine will get divider ratio for specific frequency.
	@param			freq					frequency
	@return 			Return the status code	_TURE,_FALSE
*/
unsigned short CTunerGeDiverRatio(unsigned int freq);
/*=============================================================*/
/**
	This routine will check tuner receiving frequency band(VHF Low¡BVHF High¡BUHF).
	@param 			freq	       					tuner receiving frequency(divider)
	@return 			Return tuner receiving frequency band(01¡B02 or 04)
*/
unsigned char CTunerCheckBand(unsigned int freq);

/*=============================================================*/
unsigned int CTunerNToFrequencyNum(unsigned short N);
unsigned int CTunerGetRatioInStepSize(void);
unsigned int CTunerGetPictureInterFreq(void);
unsigned int CTunerGetChanelMaxFreq(void);
unsigned int CTunerGetChanelMinFreq(void);
unsigned int CTunerGetVHF_LowFreq(void);
unsigned int CTunerGetVHF_HighFreq(void);

#ifdef __cplusplus
}
#endif


#endif
/**
 *
 * @}
 */
