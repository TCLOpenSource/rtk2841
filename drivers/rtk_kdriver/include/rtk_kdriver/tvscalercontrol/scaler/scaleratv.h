/*=============================================
  * Copyright (c)      Realtek Semiconductor Corporation, 2006
  * All rights reserved.
  * ============================================ */

/*================= File Description ================= */
/**
 * @file
 * 	This file is for audio middler layer related functions.
 *
 * @author 	$Author: frankcheng $
 * @date 	$Date: 2006-04-19 19:37:42 +0800
 * @version 	$Revision:  $
 * @ingroup 	tv
 */

#ifndef  _CTRL_TV_H
#define _CTRL_TV_H
 /**
 * @addtogroup tv
 * @{
 */

//#ifdef CONFIG_IFD_ENABLE
//#include "frontend/ifd.h"
//#endif

#ifdef __cplusplus
extern "C" {
#endif

//#include <rtd_types.h>

/*================ Module dependency  =============== */

/*==================== Definitions ================= */
typedef enum _AUTOSCANFLOW{
	AUTO_SCAN_ALL = 0,
	AUTO_SCAN_CHINA,
	AUTO_SCAN_EUROPE,
	AUTO_SCAN_USA,
	AUTO_SCAN_First_NTSC_Second_PAL
} AUTOSCANFLOW;


#if 0
typedef enum _REPORT_TV_INFO_STATE{
	TV_INFO_POLLING_DISABLE = 0,
	TV_INFO_POLLING_ENABLE,
	TV_INFO_SWITCH_CHANNEL,
	TV_INFO_SEND_PER_HOUR,
} REPORT_TV_INFO_STATE;

typedef  struct
{
	unsigned int freq;
	unsigned char hour;
	unsigned char minute;
}TV_PROGRAM_INFO;
#endif
//#define _SEND_TV_INFO_THRESHOLD	5 //minute

/*==================== Variables ================= */
//extern unsigned char tv_nosignal2signal ;
//extern unsigned char tvColorIdentifyFlag; // linmc@20100120, prevent fh_adjust in identify_ColorStandard
/*==================== Functions ================== */

/**
	This routine will get the TV funetune freq.
	@param chnfreq	current channel frequency
	@param chnoffset	current channel frequency offset
	@return 			TV funetune freq
*/
//unsigned int fwif_get_tv_freq_finetune_result(unsigned int chnfreq, unsigned char chnoffset);

/**
   fwif_set_child_lock_status
   set whether lock current channel
   include child lock etc
   @param <unsigned char>	{ _ENABLE if current channel need lock,
					   _DISABLE if current channel don't need lock }
   @return <type>		{ void }
*/
//void fwif_set_child_lock_status(unsigned char ucEnable);

/**
   fwif_set_child_lock_control
   include child lock etc
   @param <unsigned char>	{ Main / Sub Display}
   @param <unsigned char>	{ _ENABLE if current channel need lock,
					   _DISABLE if current channel don't need lock }
   @param <unsigned char>	{ _TRUE if Apply background and mute }
   @return <type>		{ void }
*/
//void fwif_set_child_lock_control(unsigned char display, unsigned char ucEnable, unsigned char ucApply);

/**
   fwif_get_child_lock_status
   Check whether lock current channel
   include child lock etc
   @param <type>		{ void }
   @return <unsigned char>	{ return _TRUE if current channel need lock,
					   return _FAIL if current channel don't need lock }
*/
//unsigned char fwif_get_child_lock_status(void);

/**
	This routine will detect TV color standard in auto scan or manu scan
	@param tvAutoScanFreq specific freq to set tuner

	@return 	Return the color standard{ZNTSC, ZPAL_M,...}
*/
unsigned char fwif_tv_autoscanmodedetect( unsigned int tvAutoScanFreq);
/**
	This routine will get the correct freq of autoscan

	@return 	Return the freq that lock video channel
*/
unsigned int fwif_autoscan_getfinalfreq(void);


/**
 * fw_tv_setvideomode
 * This API is used to process TV video mode control
 *
 * @param <mode>	{ ZNTSC,ZNTSC_443, ZPAL_N, ZPAL_M,ZPAL_I, ZSECAM}
 * @param [output] :
 * @return None
 *
 */
void fw_tv_setvideomode(unsigned char mode, unsigned int freq);

/**
 * fw_tv_setvideomode
 * This API is used to process TV video mode control
 *
 * @param <mode>	{ ZNTSC,ZNTSC_443, ZPAL_N, ZPAL_M,ZPAL_I, ZSECAM}
 * @param <frequence>
 * @param <BackupMode>	{ ZNTSC,ZNTSC_443, ZPAL_N, ZPAL_M,ZPAL_I, ZSECAM}
 * @return None
 *
 */
void fw_tv_setVideoAndBackupMode(unsigned char mode, unsigned int freq, unsigned char a_ucBackupMode);

void fw_tv_setVideoAndBackupMode_2nd(UINT8 bChangeColorStd);

//leo 20101027 add for change color system
/**
 * fw_tv_setvideomode_at_changecolorsystem
 * This API is used to process TV video mode control only when change color system
 *
 * @param <mode>	{ ZNTSC,ZNTSC_443, ZPAL_N, ZPAL_M,ZPAL_I, ZSECAM}
 * @param [output] :
 * @return None
 *
 */
void fw_tv_setvideomode_at_changecolorsystem(unsigned char mode);

/**
 * fw_tv_GetAndSetVideoMode
 * Get and Set TV video mode
 *
 * @param None
 * @return None
 *
 */
void fw_tv_GetAndSetVideoMode(void);

/**
 * fw_tv_GetAndSetVideoModeWithoutIFD
 * Get and Set TV video mode without IFD
 *
 * @param None
 * @return None
 *
 */
void fw_tv_GetAndSetVideoModeWithoutIFD(void);

/**
 * fw_tv_getvideomode
 * This API is used to get TV video mode
 *
 * @param <type>	{ void}
 * @return <unsigned char>	{ ZNTSC,ZNTSC_443, ZPAL_N, ZPAL_M,ZPAL_I, ZSECAM}
 *
 */
unsigned char fw_tv_getvideomode(void);

/**
 * fw_tv_getFreq
 * This API is used to get ap set channel tuner freq
 *
 * @param <type>	{ void}
 * @return <unsigned int>	{ the freq of cur channel}
 *
 */
unsigned int fw_tv_getFreq(void);
#if defined(CONFIG_ENABLE_SPEED_UP_CH_SWITCH)	
// oliver+, 2012_06_26
void fw_tv_SetColorChange(UINT8 color_change);
UINT8 fw_tv_getColorChange(void);

// oliver+, 2012_06_26
void fw_tv_SetHVLockFlag(UINT8 a_bLock);
UINT8 fw_tv_getHVLockFlag(void);

void fw_tv_setColorChangeOnly(UINT8 colorChangeOnly);
UINT8 fw_tv_getColorChangeOnly(void);
#endif
#ifdef CONFIG_SET_ATV_CHANNEL_FIRST
void fw_tv_SetChannelSettingFlag(UINT8 channel_set);
UINT8 fw_tv_getChannelSettingFlag(void);
#endif
/**
 Check the TV video mode type in auto color system.
 This function will query the video decoder's mode type register.
 Differ which type it is now.
   @param                               { void }
   @return <ucVdc_TV_Mode> { The result it detected }

 		BIT 0~1
 		 : 1 60 Hz
 		 : 2 50 Hz
 		BIT 4~7
 		 : 00 PAL B,G,H,I
 		 : 10 NTSC M
 		 : 20 SECAM
 		 : 30 NTSC44
 		 : 40 PAL M
 		 : 50 PAL N
 		 : 60 PAL 60
*/
unsigned char fw_tv_getcolorstandard(void);

/**
	This routine will set the specific channel as current channel.
	@param chn			specific channel for switching to

	@return 				Return the status code  _TURE,_FALSE
*/
//unsigned char fwif_tv_setchannel(unsigned char disp, unsigned char chn);

/**
	This routine will set the audio MTS mode.
	@param chn			0:MONO  1:STEREO  2:SAP

	@return
*/
//void fwif_tv_set_audio_mts(unsigned char mode);

//unsigned char fwif_tv_manual_set_tv_std(unsigned char ucMode);
/**
	This routine will enable/disable afc function.
	@param enable			1:Enable  0:DISABLE

	@return
*/
//void fwif_tv_afc_function(unsigned char enable);

//unsigned char fw_tv_getColorStandard_Auto(void);
//unsigned char fw_tv_getColorStandard_Manual(void);
//unsigned char fwif_tv_get_TV_mode(void);
//void fwif_tv_report_tv_program_function(unsigned char disp, REPORT_TV_INFO_STATE state);

unsigned char fwif_tv_ConvertToRegColorStandard(void);


/**
\brief Get play index
\param None
\return None
\bug None
\see None
*/
unsigned int fwif_tv_GetPlayIndex(void);

/**
\brief Set play index
\param None
\return None
\bug None
\see None
*/
unsigned int fwif_tv_SetPlayIndex(void);

/**
\brief Set auto scan flow type (all, china, europe or usa)
\param a_ucFlow[In], flow type
\param a_bManualMode[In], use manual setting or menuconfig setting
\return None
\bug None
\see None
*/
void fwif_tv_autoscan_SetAutoScanFlow(AUTOSCANFLOW a_ucFlow, unsigned char a_bManualMode);


UINT8 fw_av_GetMode(void);

void fw_av_SetMode(UINT8 mode);
void fw_av_SetDefaultMode(UINT8 mode);
void fwif_tv_autoscan_signalboost_enable(bool en);
void fwif_tv_autoscan_signalboostdetect_enable(bool en);
void fwif_tv_autoscan_signalboostdetect_status(bool *en);
void  fwif_tv_signalboostenable(bool en);

bool fw_get9winstate(void) ; //add by skyworth zhaojiayu 2012/10/24
void fw_set9winstate(bool state) ;
void fw_tv_setFreq(UINT32 Freq);

// [2D3D] disable vodma v-sync tracking when input/output v-sync is different
UINT8 fw_av_2Dcvt3D_updateVodmaSyncTrackingMode(UINT8 mode);

void fw_tv_GetAndSetVideoModeWithoutIFD(void);

void SetATVDirectly(UINT8 a_ucVideoMode, UINT8 a_ucAudioMode, UINT32 a_ulFreq, bool a_ucRfInput);
#ifdef IS_MACARTHUR3
void SetATVDirectlyOff(bool bReleaseATV, bool bReleaseVDMemory);
#else
void SetATVDirectlyOff(void);
#endif
void SetATVDirectlyOn(void);
UINT8 fw_IsAtvOut(void);
UINT8 fw_IsSetATVDirectly(void);


void drvif_ifd_preset_audiomode(UINT8 soundSystem);
/**
 * @}
 */
#ifdef __cplusplus
}
#endif




#endif

