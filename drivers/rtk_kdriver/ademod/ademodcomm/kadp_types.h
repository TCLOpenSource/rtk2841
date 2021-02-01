/*=============================================================
 * Copyright (c)      Realtek Semiconductor Corporation, 2004 *
 * All rights reserved.                                       *
 *============================================================*/
/*======================= Description ========================*/
/**
  * @file
 * We define the usual types in this file.
 * We define the usual types in this file such as INT8,uin8,etc.
 * Please include this file in all source file. And declare your
 * variables with this re-defined type.
 * @Author Moya Yu
 * @date  2004/4/7
 * @version 1.0
 */

#ifndef __RTD_TYPES_H__
#define __RTD_TYPES_H__
#ifndef _GNU_SOURCE
#define _GNU_SOURCE 1
#endif

#include "kadp_base_types.h"

#ifdef __cplusplus
extern "C" {
#endif


typedef enum _RT_MSG {

	RT_MSG_NULL = 0,

	RT_MSG_CHECK_LOCK = 1000,

	// TP Message
	RT_MSG_TP0_SIGNAL_HALT,
	RT_MSG_TP0_SIGNAL_RESUME,	
#if defined(DTV_WEAK_SIGNAL_DETECT)	//Brian-20130903-Added for Weak signal detect
	RT_MSG_TP0_WEAK_SIGNAL,
	RT_MSG_TP0_WEAK_SIGNAL_RESUME, 
#endif
	// SI messages
	RT_MSG_SI_STREAM_CHANGE_BEGIN = 1200,
	RT_MSG_SI_STREAM_CHANGE_END,
	RT_MSG_SI_CHANNEL_SCAN_DONE,
	RT_MSG_SI_RESET_CHANNEL,
	RT_MSG_SI_RESET_CHANNEL_INFO,
	RT_MSG_SI_GOT_NEW_CHANNEL,
	RT_MSG_SI_GOT_NEW_TIME,
	RT_MSG_SI_GOT_NEW_RATING,
	RT_MSG_SI_GOT_NEW_CUR_PROGRAM,
	RT_MSG_SI_GOT_NEW_PROGRAM,
	RT_MSG_SI_GOT_NEW_DRRT,
	RT_MSG_SI_GOT_NEW_EAM ,
	RT_MSG_SI_GOT_NEW_APP ,//AIT
	RT_MSG_SI_GOT_NEW_NIT,//Network_ID
	RT_MSG_SI_GOT_NEW_CAT,
	RT_MSG_SI_CHECK_NEW_FREQUENCY,	
	RT_MSG_SI_NOTIFY_TS_CHANGE,
	RT_MSG_SI_NOTIFY_CH_CHANGE,
    RT_MSG_SI_GOT_NEW_EVENT_IN_CURRENT_EPG_CH,
    RT_MSG_SI_NOTIFY_RESTART_CUR_CH,//#ifdef ENABLE_NEW_DVB
    RT_MSG_SI_NOTIFY_RESTART_SUB,//#ifdef ENABLE_NEW_DVB
    RT_MSG_SI_PLAY_REPLACEMENT_CH,
    RT_MSG_SI_PLAY_FIRST_CHANNEL_OF_CURRENT_FREQUENCY,
    	RT_MSG_SI_DOWNLOAD_FDT_OK,
	RT_MSG_SI_DOWNLOAD_FDT_TIMEOUT,
#ifdef ENABLE_NIKE_UPGRADE
	RT_MSG_SI_NEED_UPGRADE,
#endif
        RT_MSG_SI_SERVICE_UPDATE,
    RT_MSG_SI_PAT_CURRENT_PROGRAM_CHANGED,
	// Scaler library messages.
    RT_MSG_SLR_TASK_READY = 1300, 	//when scaler task wake up,flow send the msg to ui task
    RT_MSG_SLR_AUTO_ADJUST_BEGIN,	//when scaler task receive flow  auto adjust start msg,flow send the msg to ui task
    RT_MSG_SLR_AUTO_ADJUST_END,		//when scaler task receive flow auto adjust end msg,flow send the msg to ui task
    RT_MSG_SLR_AUTO_ADJUST_OK,   // wdp add
    RT_MSG_SLR_AUTO_ADJUST_FAIL,
    RT_MSG_SLR_MAIN_NO_SIGNAL,
    RT_MSG_SLR_MAIN_NO_CABLE,
    RT_MSG_SLR_MAIN_NO_SUPPORT,
    RT_MSG_SLR_DETECT_OK,
    RT_MSG_SLR_DISPLAY_READY,
    RT_MSG_SLR_AUDIO_ONLY,
#ifdef CONFIG_SOURCE_AUTO_SWITCH
	RT_MSG_SLR_SOURCE_AUTO_SWITCH,
	RT_MSG_SLR_SOURCE_AUTO_SWITCH_AV,
    RT_MSG_SLR_SOURCE_AUTO_SWITCH_YPBPR,
    RT_MSG_SLR_SOURCE_AUTO_SWITCH_HDMI1,
    RT_MSG_SLR_SOURCE_AUTO_SWITCH_HDMI2,
#endif
#if defined(DTV_WEAK_SIGNAL_DETECT)
	//Brian-20130903-Added for Weak signal detect
	RT_MSG_SLR_MAIN_WEAK_SIGNAL,
	RT_MSG_SLR_MAIN_WEAK_SIGNAL_RESUME, 
#endif

#ifdef ENABLE_TVSERVER
	// TvScan Message
	RT_MSG_SLR_SCAN_FREQ_UPDATE,
	RT_MSG_SLR_SCAN_AUTO_COMPLETE,
	RT_MSG_SLR_SCAN_MANUAL_COMPLETE,
	RT_MSG_SLR_SCAN_SEEK_COMPLETE,
#endif	

 //frank@0323 mark ap not process msg    RT_MSG_SLR_SEARCH_MODE,		//Gilbert ==> Mode Searching Message
    RT_MSG_SLR_MAGICPIC_OFF,	// signal is not stable we call ap to close magicpic
    RT_MSG_SLR_FORCE_3D_DISABLE,
    RT_MSG_SLR_DISABLE_OSD,
#ifdef CONFIG_TTX_TOSHIBA_PATCH
	RT_MSG_SLR_TTX_SAVE_LIST,
#endif
	//CC messages
	RT_MSG_CC_GOT_RATING_INFO,
	RT_MSG_CC_GOT_ANALOG_RATING_INFO,
    RT_MSG_CC_GOT_SERVICE_INFO,
    RT_MSG_CC_GOT_PROGRAM_TITLE,
    RT_MSG_CC_GOT_PROGRAM_DESC,
    RT_MSG_CC_GOT_CHANNEL_NAME,
    RT_MSG_CC_DEL_SERVICE_INFO,

	RT_MSG_AUTOCOLOR_SUCCESS, // flow to ap ,then save adc value to eeprom yf 20110720
	RT_MSG_AUTOCOLOR_FAIL,	//  roni 20120315 add,
#if defined(TV032_1)||defined (TV014_1)||(defined TV014_2)//Added by Kangwei 2012-07-18-11:5
	RT_MSG_AWB_MESSAGE_START,
#endif
	RT_MSG_AWB_MESSAGE,
#if defined ENABLE_NEW_DVB_2 || (defined BUILD_TV005_1_ATV) || (defined BUILD_TV005_1_ATSC)	 || defined(BUILD_TV008_2_ATV) || (defined TV003_ATSC) || (defined TV003_ISDB)// alex.lin 20120319 for audio software DD
	RT_MSG_MTS_DETECT,
	RT_MSG_ATV_STATUS_CHANGE_CHANNEL_STDANDARD_CHANGE,
	RT_MSG_ATV_STATUS_DETECTED_STDANDARD_CHANGE,
	RT_MSG_ATV_STATUS_SOUNDMODE_CHANGE,
	RT_MSG_ATV_STATUS_NICAM_WEAK_SIGNAL,
	RT_MSG_ATV_STATUS_NICAM_RECOVERY,
	RT_MSG_CHANNEL_SERVICE_REMOVE,
	#if defined(CONFIG_ENABLE_SPEED_UP_MPX)
	RT_MSG_ATV_STATUS_FIRSTTIME_SOUNDMODE,
	#endif //CONFIG_ENABLE_SPEED_UP_MPX
#endif
	RT_MSG_RATIO_16_9_SETED,
#if (defined BUILD_TV013_1_DTMB) || (defined BUILD_TV013_1_ISDB) || (defined BUILD_TV035_1_DTMB) || (defined BUILD_TV020_1_DTMB) || defined(BUILD_TV010_1_DTMB)
	//RT_MSG_RATIO_16_9_SETED,
	RT_MSG_EG_PIC_REFRESH,  //jacklong2012/08/14
#endif

#if defined(BUILD_TV015_1_ATV)||defined(BUILD_TV020_1_ATV)||defined(BUILD_TV010_1_ISDB)
	#ifdef ENABLE_CHECK_AUDIO_AFTER_SWITCHING_CHANNNEL
	RT_MSG_MTS_DETECT,
	RT_MSG_ATV_STATUS_CHANGE_CHANNEL_STDANDARD_CHANGE,
	RT_MSG_ATV_STATUS_DETECTED_STDANDARD_CHANGE,
	RT_MSG_ATV_STATUS_SOUNDMODE_CHANGE,
	RT_MSG_ATV_STATUS_NICAM_WEAK_SIGNAL,
	RT_MSG_ATV_STATUS_NICAM_RECOVERY,
	#endif
#endif
#if defined(BUILD_TV010_1_ISDB)
	RT_MSG_CHECK_DTV_AUDIO_VEDIO,//toddy_liu add 20121123
#endif
#if defined(CONFIG_ENABLE_YPBPR_AND_AV_USE_SAME_PATH) || defined(CONFIG_ENABLE_YPBPR_AND_AV_USE_SAME_PATH_DETECT_BY_PIN)
	RT_MSG_YPBPR_AV_SAME_PATH_CHANGE_SRC,
#endif //#if defined(CONFIG_ENABLE_YPBPR_AND_AV_USE_SAME_PATH) || defined(CONFIG_ENABLE_YPBPR_AND_AV_USE_SAME_PATH_DETECT_BY_PIN)

	RT_MSG_SELFAWB_START, 
	RT_MSG_SELFAWB_END_SUCCESS, 
	RT_MSG_SELFAWB_END_FAIL, 

    // Eaton+
    RT_MSG_SCART_RATIO_16_9_DETECTED,
    RT_MSG_SCART_RATIO_4_3_DETECTED,

	RT_MSG_DTV_ENCRYPTED,
	RT_MSG_DTV_NO_CI_MODULE,

    RT_MSG_DTV_CI_RESTART_CUR_CH,
#ifdef BUILD_TV013_1_DTMB
	RT_MSG_3D_MODE_READY,
#endif
} RT_MSG;


typedef enum _CI_MSG {
	RT_MSG_CI_DATA_READY = 0,
	RT_MSG_CI_CLOSE_MMI = 1,
	RT_MSG_CI_CARD_INSERTED = 2,
	RT_MSG_CI_CARD_REMOVED = 3,
	RT_MSG_CI_AUTOTEST_MESSAGE_SHOWN = 4
}CI_MSG;

	
//#endif	//__ASSEMBLY__
#ifdef BUILD_DEBUG_CONTROL
//Debug Message Control
typedef struct _DEBUG_SCALER_MESSAGE{
	bool		scalerAdc;
	bool		scalerAPI;
	bool		scalerATV;
	bool		scalerColor;
	bool		scalerClock;
	bool		scalerDisplay;
	bool		scalerDrv;
	bool		scalerFlowMgr;
	bool		scalerIP;
	bool		scalerLib;
	bool		scalerMemory;
	bool		scalerStruct;
	bool		scalerTimer;
	bool		scalerVideo;
	bool		scalerLib_2DCVT3D;
}DEBUG_SCALER_MESSAGE;
typedef struct _RT_DEBUG_MESSAGE{	
	UINT8	AudioEQ;
	UINT8	Audio;
	UINT8	Audio_atv;
	UINT8	Modestate;
	UINT8	ATSC;
	UINT8	PcMgr;
	UINT8	Grpahic;
	UINT8	Channel;
	UINT8	IFD;
	UINT8	TvMgr;
	UINT8	Grp;
	UINT8	Media;
	UINT8	HDMI;
	UINT8	User;		//For UI Log
	UINT8	Enable3D;	//For 3D Log
	UINT8	MEMC;		//For picasso/MEMC API Log
	UINT8	PA136;		//For PA136 Log
	UINT8	MEMC_Update; //For MEMC Update Log
	bool		VBIMSG;			//For TV VBI log
	DEBUG_SCALER_MESSAGE scaler;
} RT_DEBUG_MESSAGE;
extern RT_DEBUG_MESSAGE DebugMsg;
#endif
#ifdef __cplusplus
}
#endif

#endif  //_RTD_TYPES_H
