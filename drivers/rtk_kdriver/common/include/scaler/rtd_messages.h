#ifndef _COMMON_RTD_MESSAGES_H__
#define _COMMON_RTD_MESSAGES_H__

//#include <rtd_types.h>


//*************************************************************
// DEFINE
//*************************************************************
// message should start after 300 because state chart has its own message starting from 0.
#define RC_MSG_BEGIN                    300
#define RC_MSG_END						999

#define DTV_MODULE_MSG_BEGIN			1000

#define AP_MSG_BEGIN      	            2000

#define LIB_MSG_BEGIN                   3000

#define KERNEL_MSG_BEGIN                4000
#define ROS_MSG_BEGIN					4001
#define TP_MSG_BEGIN					4100
#define ATV_MSG_BEGIN					4200
#define IO_MSG_BEGIN					4300
#define PLAYBACK_MSG_BEGIN				4400


//#define IDTV_MSG_BEGIN					4700

//#define TEST_MSG_BEGIN                  5000


//*************************************************************
// ENUM
//*************************************************************
enum LIB_MSG_TYPE {
	MSG_LIB_NULL = LIB_MSG_BEGIN,

	// Timer Message.
	MSG_LIB_TIMER,
	MSG_LIB_TIMER_AB_REPEAT,

	// SI messages.
	MSG_LIB_SI_NULL,
	MSG_LIB_SI_STREAM_CHANGE_BEGIN,
	MSG_LIB_SI_STREAM_CHANGE_END,
	MSG_LIB_SI_CHANNEL_SCAN_DONE,
	MSG_LIB_SI_RESET_CHANNEL,
	MSG_LIB_SI_GOT_NEW_CHANNEL,
	MSG_LIB_SI_GOT_NEW_TIME,
	MSG_LIB_SI_GOT_NEW_RATING,		//
	MSG_LIB_SI_GOT_NEW_CUR_PROGRAM,	// EIT0
	MSG_LIB_SI_GOT_NEW_PROGRAM,		// EIT
	MSG_LIB_SI_GOT_NEW_DRRT,
	MSG_LIB_SI_GOT_NEW_EAM,
//	MSG_LIB_SI_NEW_PMT,
	MSB_LIB_SI_NEW_NIT,
	MSB_LIB_SI_NEW_SDT,
	MSG_LIB_SI_MAX,

	MSG_LIB_MF_NULL,
	MSG_LIB_MF_NO_SIGNAL,
	MSG_LIB_MF_AUDIO_CHANNEL,
	MSG_LIB_MF_MAX,

	// Data Provider Scan Finish
	MSG_LIB_DP_SCAN_FINISH,
	// Playback Mgr Messages.
	MSG_LIB_PB_NULL,
	MSG_LIB_PB_UPDATE_STATUS_STOP,
	MSG_LIB_PB_UPDATE_PROGRESS,
	MSG_LIB_PB_UPDATE_MSG3,
	MSG_LIB_PB_HIDE_MSG1,
	MSG_LIB_PB_HIDE_MSG2,
	MSG_LIB_PB_HIDE_MSG3,
	MSG_LIB_PB_AV_COMPLETE,			//rmp playback message

	MSG_LIB_PB_AV_PLAY_ERROR,
	MSG_LIB_PB_AV_LOAD_ERROR,
	MSG_LIB_PB_AV_PUREAUDIO,
	MSG_LIB_PB_AV_REWIND2FORWARD,
	MSG_LIB_PB_PHOTO_COMPLETE,
	MSG_LIB_PB_PHOTO_USER_BREAK,
	MSG_LIB_PB_PHOTO_UNSUPPORT,
	MSG_LIB_PB_PHOTO_DECODE_ERROR,
	MSG_LIB_PB_PHOTO_REAL_DECODE,
	MSG_LIB_PB_PHOTO_HUGE_DECODE,
	MSG_LIB_PB_VOL_CLOSE,
	MSG_LIB_PB_START_ZOOMPHOTO,//forever101111
	MSG_LIB_PB_MAX,

//CC Message
	MSG_LIB_CC_NULL,
	MSG_LIB_CC_GOT_RATING_INFO,
	MSG_LIB_CC_GOT_ANALOG_RATING_INFO,
    MSG_LIB_CC_GOT_SERVICE_INFO,
    MSG_LIB_CC_GOT_PROGRAM_TITLE,
    MSG_LIB_CC_GOT_PROGRAM_DESC,
    MSG_LIB_CC_GOT_CHANNEL_NAME,
    MSG_LIB_CC_DEL_SERVICE_INFO,
	MSG_LIB_CC_MAX,

	//pcMgr Message: block status is changed
	MSG_LIB_CHECK_PARENTAL_LOCK,
	MSG_LIB_CHECK_CHANNEL_LOCK,
	MSG_LIB_CHECK_SOURCE_LOCK,

	//scaler Messgage:
	MSG_LIB_SLR_NULL,
	MSG_LIB_SLR_TASK_READY,
	MSG_LIB_SLR_TASK_ACTIVATE_ACK,
	MSG_LIB_SLR_AUTOADJUST_START,
	MSG_LIB_SLR_AUTOADJUST_END,
	MSG_LIB_SLR_MAIN_NO_SIGNAL,
	MSG_LIB_SLR_MAIN_NO_CABLE,
	MSG_LIB_SLR_MAIN_NO_SUPPORT,
	MSG_LIB_SLR_MAIN_SIGNAL_DETECT_OK,
	MSG_LIB_SLR_SUB_SIGNAL_DETECT_OK,
	MSG_LIB_SLR_MAIN_DISPLAY_READY,
	MSG_LIB_SLR_SUB_DISPLAY_READY,
	MSG_LIB_SLR_MAIN_DISPLAY_NOSIGNAL,  //TLM
	MSG_LIB_SLR_MAIN_NEED_COLOR_CONFIG,
	MSG_LIB_SLR_SUB_NEED_COLOR_CONFIG,
	MSG_LIB_SLR_AUTOCOLOR_FINISH,
	MSG_LIB_SLR_AUTOCOLOR_SUCCESS,  //<Stanley K90804> For auto color result
	MSG_LIB_SLR_AUTOCOLOR_FAIL,//<Stanley K90804> For auto color result
	MSG_LIB_SLR_MAIN_SEARCH_MODE, //Gilbert ==> For Search Mode
	MSG_LIB_SLR_MAGICPIC_OFF,

	// HDMI Message
	MSG_LIB_HDMI_AUDIO_CHANGE,
	MSG_LIB_PARSE_COMMAND_MODE,

	//YWE Message
	MSG_LIB_YWE_LOADING,
	MSG_LIB_YWE_INSTALLING,
	MSG_LIB_YWE_SHUTDOWN,
	MSG_LIB_YWE_OOBE_WIDGET,
	MSG_LIB_YWE_POST_WIDGET,
	MSG_LIB_YWE_GFXSHUTDOW_COMPLETE,
	MSG_LIB_YWE_PLAYBACK_PLAY,

	//Multak Kalaok Message
	MSG_LIB_MULTAK_PLAYING_MUS,//M_STATUS_PLAYING_MUS
	MSG_LIB_MULTAK_STOP_MUS,//M_STATUS_STOP_MUS
	MSG_LIB_MULTAK_FINISH_MUS,//M_STATUS_FINISH_MUS
	MSG_LIB_MULTAK_FINISH_LRC,//M_STATUS_FINISH_LRC
	MSG_LIB_MULTAK_RECORD_ERROR,//M_STATUS_RECORD_ERROR
	MSG_LIB_MULTAK_FINISH_MP3,//M_STATUS_FINISH_MP3
	MSG_LIB_MULTAK_FINISH_MOVIE,//M_STATUS_FINISH_MOVIE
	MSG_LIB_MULTAK_FINISH_SPEECH,//M_STATUS_FINISH_SPEECH
	MSG_LIB_MULTAK_START_BUFFERING,//M_STATUS_START_BUFFERING
	MSG_LIB_MULTAK_STOP_BUFFERING,//M_STATUS_STOP_BUFFERING
	MSG_LIB_MULTAK_BUFFERING_FAILED_USE_LOCAL,//M_STATUS_BUFFERING_FAILED_USE_LOCAL
	MSG_LIB_MULTAK_SPEECH_DATA_UPDATE,//M_STATUS_SPEECH_DATA_UPDATE
	MSG_LIB_MULTAK_SPEECH_DATA_UPDATE_FINISH,//M_STATUS_SPEECH_DATA_UPDATE_FINISH
	MSG_LIB_MULTAK_MUS_LOAD_FAILED,//M_STATUS_MUS_LOAD_FAILED
	MSG_LIB_MULTAK_MUS_PLAY_FAILED,//M_STATUS_MUS_PLAY_FAILED
	MSG_LIB_MULTAK_SCORE_END,		//M_STATUS_SCORE_END

	//BesTV Message
	MSG_LIB_BESTV_BUFFERING,

	//subtitle Message
	MSG_LIB_SUBTITLE,

	//Teletext Message
	MSG_LIB_TELETEXT_UPDATE_FRAME,
	MSG_LIB_TELETEXT_NEXT_SUBPAGE,
	MSG_LIB_TELETEXT_ENABLE_FATCH_IN_BG,
	MSG_LIB_TELETEXT_STOP,
	MSG_LIB_TELETEXT_EXIT,

	// CA Message description please see dtv/include/system/chi/chihandler.h
	MSG_LIB_CA_OPEN_HTML,
	MSG_LIB_CA_OPEN_MSGBOX,
 	MSG_LIB_CA_CLOSE_DIALOG,
 	MSG_LIB_CA_UPGRADE,
 	MSG_LIB_CA_TUNE,
	MSG_LIB_CA_FIRMWARE_UPDATE_FINISH,

	//CI Message
	MSG_LIB_CI_AOT_CLOSE_MMI,
	MSG_LIB_CI_AOT_DISPLAY_CONTROL_MMI_HIGH_LEVE_MODE,
 	MSG_LIB_CI_AOT_LIST_MENU_LAST,

 	MSG_LIB_CI_AOT_ENQ,
 	MSG_LIB_CI_AOT_APPLICATION_INFO,
	MSG_LIB_CI_AOT_CA_SYSTEM_ID,

	MSG_DRV_CI_SLOT0_INSERT,
	MSG_DRV_CI_SLOT1_INSERT,
	MSG_DRV_CI_SLOT0_REMOVE,
	MSG_DRV_CI_SLOT1_REMOVE,
	MSG_DRV_CI_INVALID_PCCARD_INSERTED,
	MSG_DRV_CI_UNABLE_TO_INITIALISE_CAM,
	MSG_DRV_CI_UNABLE_TO_RESET_CAM_IF,
	MSG_DRV_CI_PCCARD_NOT_RESPOND,
	MSG_DRV_CI_CAM_NOT_RESPOND,
	MSG_DRV_CI_CAM_LINK_INIT_FAIL,
	MSG_DRV_CI_UNABLE_TO_ALLOCATE_CAM_RX_BUFFER,
	MSG_DRV_CI_CAM_DETECTED_AND_INIT_SUCCESS,
	MSG_DRV_CI_CAM_VALIDATED_SUCCESS,


	//yiping_xu add for fastDowning
	MSG_FAST_DOWNLOADING_CREATE_NEW_TASK_OK,
	MSG_FAST_DOWNLOADING_CREATE_NEW_TASK_FAIL,
	MSG_FAST_DOWNLOADING_OK,
	MSG_FAST_DOWNLOADING_FAIL,
	MSG_FAST_DOWNLOADING_PAUSE_OK,
	MSG_FAST_DOWNLOADING_PAUSE_FAIL,

#ifdef CONFIG_ENABLE_YPBPR_AND_AV_USE_SAME_PATH
	MSG_LIB_YPBPR_AV_SAME_PATH_CHANGE_SRC,
#endif //#ifdef CONFIG_ENABLE_YPBPR_AND_AV_USE_SAME_PATH
#ifdef ENABLE_LIB_PPPOE
	MSG_LIB_NET_PPPOE_LINK_UP,
	MSG_LIB_NET_PPPOE_LINK_DOWN,
#endif

	MSG_LIB_PB_AV_PLAY_NEXTSONG,

	MSG_LIB_OPC_VALUE_DISPLAY,

	//oliver+
	// IO, write data to usb device
	MSG_LIB_IO_WRITE_TO_USB,
	// For rain
	MSG_LIB_IO_WRITE_TO_USB2,

};

enum SYSTEM_MSG_TYPE {
	MSG_SYS_NULL = KERNEL_MSG_BEGIN,

    // ROS messages.
    MSG_SYS_ROS_NULL = ROS_MSG_BEGIN,
	MSG_SYS_MV_READY,
	MSG_SYS_SV_READY,
	MSG_SYS_MV_DISP_FMT_CHANGE,
	MSG_SYS_SV_DISP_FMT_CHANGE,
	MSG_SYS_MV_SET_COMPRESS_READY,
	MSG_SYS_SV_SET_COMPRESS_READY,
	MSG_SYS_ROS_HANG,
	MSG_SYS_MA_READY,
	MSG_SYS_SA_READY,
	MSG_SYS_SUB_PTS_TIMEUP,
	MSG_SYS_SUB_PTS_Q_OVERFLOW,
	MSG_SYS_SUB_PTS_Q_RESET,
	MSG_SYS_MV_NOT_SUPPORT_FMT,
	MSG_SYS_SV_NOT_SUPPORT_FMT,

	// TP messages.
	MSG_SYS_TP_NULL = TP_MSG_BEGIN,
	MSG_SYS_TP0_SIGNAL_HALT,
	MSG_SYS_TP0_SIGNAL_RESUME,
	MSG_SYS_TP1_SIGNAL_HALT,
	MSG_SYS_TP1_SIGNAL_RESUME,
	MSG_SYS_TP0_FIFO_FULL,
	MSG_SYS_TP1_FIFO_FULL,
	MSG_SYS_TP_RESET,
	MSG_SYS_TP_BAD_SIGNAL,

	MSG_SYS_DTV_AUDIO_SIGNAL_RESUME,

	// 2620 ATV messages
	MSG_SYS_ATV_NULL = ATV_MSG_BEGIN,
	MSG_SYS_ATV_CH_INFO_READY,
	MSG_SYS_MV_VDC_DECTECT,
	MSG_SYS_SV_VDC_DECTECT,
	MSG_SYS_VBI_VCHIP_MAIN_READY,
	MSG_SYS_VBI_VCHIP_SUB_READY,
	MSG_SYS_SHOW_NO_SIGNAL,
	MSG_SYS_HDMI_DECTECT,
	MSG_SYS_ADC_DECTECT,
	MSG_SYS_NO_SIGNAL,
	MSG_IFD_RF_MAX,
/*
	// 2547D ATV messages
	MSG_SYS_EPG,
	MSG_SYS_ATVSCANSTART,
	MSG_SYS_ATVSCANDONE,
*/
	// I/O messages
	MSG_SYS_IO_NULL = IO_MSG_BEGIN,
	MSG_SYS_HDCP_AUTHENTICATION,


	//file playback message
	MSG_SYS_PB_VIDEO_EOS = PLAYBACK_MSG_BEGIN,
	MSG_SYS_PB_AUDIO_EOS,
	MSG_SYS_PB_VIDEO_FATAL_ERR,
	MSG_SYS_PB_AUDIO_FATAL_ERR,
	MSG_SYS_PB_AUDIO_DECODE_FAIL,

/*
	// IDTV messages
	MSG_SYS_IDTV_NULL = IDTV_MSG_BEGIN,
	MSG_SYS_IDTV_SET_SPECIFIED_CH,
	MSG_SYS_IDTV_SET_EXISTING_CH,
	MSG_SYS_IDTV_START_AUTOSCAN,
	MSG_SYS_IDTV_CANCEL_AUTOSCAN,
	MSG_SYS_IDTV_SET_NEXT_CH,
	MSG_SYS_IDTV_SET_PREV_CH,
	MSG_SYS_IDTV_OPEN_EPG,
	MSG_SYS_IDTV_CLOSE_EPG,
*/
	// Headphone
	MSG_SYS_HP_PLUGIN,
	MSG_SYS_HP_UNPLUG,

	// USB messages
	MSG_SYS_USB_PLUGIN,
	MSG_SYS_USB_UNPLUG,

	// USB netlink message
	MSG_SYS_USB_NL_PLUGIN,
	MSG_SYS_USB_NL_UNPLUG,
	MSG_SYS_USB_NL_UNPLUG_BEGIN,//4408
	MSG_SYS_USB_NL_UNPLUG_END,

	// ETH messages
	MSG_SYS_ETH_LINK,
	MSG_SYS_ETH_DOWN,
	MSG_SYS_WLAN_LINK,
	MSG_SYS_WLAN_DOWN,
	MSG_SYS_WLAN_DISCONNECT,

	//frontend test messages
	MSG_FETEST_ATSC,
	MSG_FETEST_QAM64,
	MSG_FETEST_QAM256,
	MSG_FETEST_SETQAM,
	MSG_FETEST_QUIT,

	//scaler messages
	MSG_SYS_SLR_VO_READY,
	MSG_SYS_SLR_DIVX_ZOOM_PROC,
	MSG_SYS_SLR_NOSIGNAL_MUTE,
	MSG_SYS_SLR_WSS_CHANGE,
/*
	MSG_ATV_MANUALSCAN_BEGIN,
	MSG_ATV_MANUALSCAN_END,
	MSG_DTV_MANUALSCAN_BEGIN,
	MSG_DTV_MANUALSCAN_END,
*/
	//media browser
	MSG_MEDIABROWSER_PHOTOTHUMB,
	MSG_MEDIABROWSER_MUSICTHUMB,
	MSG_MEDIABROWSER_MOVIETHUMB,
	MSG_MEDIABROWSER_TEXTTHUMB,
	MSG_MEDIABROWSER_READER_COMPLETE,
	MSG_MEDIABROWSER_READER_CANCEL,
	MSG_MEDIABROWSER_USB_NOT_EXIST,

	//trans QHsm
	MSG_MAINMENU_STATUS,

	MSG_SYS_PB_AUDIO_FORMAT_CHANGE,

};

#define	MSG_DATA_TP_RESUME_VIDEO  1	//ROS is decoding.
#define	MSG_DATA_TP_RESUME_AUDIO  2 //ROS is decoding.

#endif

