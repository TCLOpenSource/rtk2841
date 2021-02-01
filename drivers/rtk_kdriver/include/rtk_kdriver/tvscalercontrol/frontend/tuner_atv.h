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

#ifndef _TUNER_ATV_H
#define _TUNER_ATV_H

#ifdef __cplusplus
extern "C" {
#endif

//#include <rtd_types.h>
#ifndef UINT8
typedef  unsigned char UINT8;
#endif
#ifndef UINT16
typedef  unsigned short UINT16;
#endif
#ifndef UINT32
typedef  unsigned int UINT32;
#endif
//#ifndef bool
//typedef int bool;
//#endif

#define Set_ActiveTunerID(x)					(gTunerActiveID=x)
#define Get_ActiveTunerID()					(gTunerActiveID)



#define _TUNER_NUM	1

//Please update to tuner_name_table@ifd_factorymode.cpp
typedef enum _TUNER_ID {
	TUNER_NULL = 0,
	TUNER_NXP_TDA18273,
	TUNER_NXP_TDA18274,
	TUNER_NXP_TDA18275,
	TUNER_NXP_TDA18275A,
	TUNER_RAFAEL_R620D,
	TUNER_RAFAEL_R830,
       TUNER_RAFAEL_R828,
       TUNER_RAFAEL_R840,
	TUNER_FRESCO_FM2150,
	TUNER_SILICONLABS_SI2151,
	TUNER_SILICONLABS_SI2157,
	TUNER_SILICONLABS_SI2158,
	TUNER_MAXLINEAR_MXL601,
	TUNER_MAXLINEAR_MXL661,
	TUNER_FITICOMM_FC0014,
	TUNER_SONY_SUTRE221ZN,
	TUNER_SONY_SUTRE231,
	TUNER_SONY_SUTRC234,
	TUNER_SONY_SUTRA231TN,
	TUNER_SONY_SUTRE232TN,
	TUNER_TV_FRONTEND_CTRL,
}TUNER_ID;

//=================================================================
//structure of TV tuner
//=================================================================

//struct _StructTunerObject;
//typedef struct _StructTunerObject StructTunerObject;

//struct _StructTunerObject {
//	UINT8 	addr;
//	UINT8 	if_addr;
//	void 	(*Init)(void);
//	UINT8	(*IsLocked)(UINT8 *afc);
//	UINT8 	(*SetFreq)(UINT32 freq);
//	INT32 	(*GetAFCOffset)(UINT8 afc);
//};
//extern StructTunerObject ObjTuner[];

//=================================================================
//Driver
//=================================================================
/*=============================================================*/
/**
	This routine will set init.
	@param			
	@return 			
*/
//void CTunerGlobalVarInit(void);
/*=============================================================*/
/**
	This routine will set TV to specific frequency.
	@param			freq					frequency
	@return 			Return the status code	_TURE,_FALSE
*/
//UINT8 CTunerSetFreq(UINT32 freq);

/*=============================================================*/
/**
	This routine will set TV to specific frequency  in Search mode
	@param			freq					frequency
	@return 			Return the status code	_TURE,_FALSE
*/
//UINT8 CTunerSetFreqSearch(UINT32 freq);
/*=============================================================*/
/**
	This routine will get TV to current frequency.
	@param			void
	@return 			Return the freq	frequency
*/
//UINT32 CTunerGetFreq(void);
/*=============================================================*/
/**
	This routine will get divider ratio for specific frequency.
	@param			freq					frequency
	@return 			Return the status code	_TURE,_FALSE
*/
//UINT16 CTunerGeDiverRatio(UINT32 freq);
/*=============================================================*/
/**
	This routine will check tuner receiving frequency band(VHF Low¡BVHF High¡BUHF).
	@param 			freq	       					tuner receiving frequency(divider)
	@return 			Return tuner receiving frequency band(01¡B02 or 04)
*/
//UINT8 CTunerCheckBand(UINT32 freq);

/*=============================================================*/
//UINT32 CTunerNToFrequencyNum(UINT16 N);
//UINT32 CTunerGetRatioInStepSize(void);
//UINT32 CTunerGetPictureInterFreq(void);
//UINT32 CTunerGetChanelMaxFreq(void);
//UINT32 CTunerGetChanelMinFreq(void);
//UINT32 CTunerGetVHF_LowFreq(void);
//UINT32 CTunerGetVHF_HighFreq(void);

#ifdef __cplusplus
}
#endif


#endif
/**
 *
 * @}
 */
