#ifndef _RTK_KDV_KEYPAD_H
#define _RTK_KDV_KEYPAD_H

#include <mach/rtk_log.h>
#include <mach/pcbMgr.h>
#include <linux/timer.h>
#include <rtk_gpio.h>

#define DEV_NAME "KEYPAD"

#define MAX_KEYPAD_CNT              8
#define GET_KEY_CODE(x)  ((short int)(((x) >> 48) & 0xFFFF))
#define _ABS(x,y) ((x) >= (y) ? ((x)-(y)) : ((y)-(x)) )
/************************************************************************

************************************************************************/
struct rtk_keypad_data {
    struct input_dev        *input_dev;
    struct device           *dev;
    struct rtk_keypad_host  *kpad_host;
};

typedef enum{
    LSADC_TYPE,
    GPIO_TYPE,
}KEYPAD_TYPE;

typedef enum{
    UNLOCK_MODE,
    LOCK_MODE,
}KEYPAD_MODE;


typedef struct
{
    char pKeyname[PCB_ENUM_NAME_LEN_MAX];
    bool bActive;               // Present active status, if current status same with bActive meaning pressed; if not,meaning released
    bool last_status ;             //To record last status of pin
    bool bEnableRepeatkey ;
    unsigned long long info;    //if setted, use it. if not, parse from PCB_param
    unsigned int       keycode ;    //kernel keycode, It's seem not same with kernal defined at input-event-codes.h
    KEYPAD_TYPE        keypad_type;
    RTK_GPIO_ID        gid;
    int                lsadc_idx;
}KEYPAD_INFO;


struct rtk_keypad_host {
    KEYPAD_INFO         *keyinfo;
    int                 key_cnt;
    KEYPAD_MODE         key_mode;
    struct timer_list   timer;
};


typedef enum {
	/*  Command Type I: User Input */
	CMD_POWER = 1,
	CMD_DISPLAY = 2,
	CMD_SETUP = 3,
	CMD_EJECT = 4,
	CMD_SOURCE = 5,
	CMD_PSCAN = 6,
	CMD_ASPECT_RATIO = 7,
	CMD_GCODE = 8,
	CMD_SCHEDULE = 9,
	CMD_DISC_UTILITY = 10,
	CMD_HDD = 11,
	CMD_DVD = 12,
	CMD_USB = 13,
	CMD_CARD_READER = 14,
	CMD_DVCONTROL = 15,
	CMD_FILE_COPY = 16,
	CMD_MENU = 17,
	CMD_GUIDE = 18,
	CMD_UP = 19,
	CMD_DOWN = 20,
	CMD_LEFT = 21,
	CMD_RIGHT = 22,
	CMD_SELECT = 23, CMD_ENTER = 23, // for backward-compatibility
	CMD_RETURN = 24,
	CMD_DELETE = 25,
	CMD_INSTANT_REPLAY = 26,
	CMD_CMSKIP = 27,
	CMD_ZERO = 28,
	CMD_ONE = 29,
	CMD_TWO = 30,
	CMD_THREE = 31,
	CMD_FOUR = 32,
	CMD_FIVE = 33,
	CMD_SIX = 34,
	CMD_SEVEN = 35,
	CMD_EIGHT = 36,
	CMD_NINE = 37,
	CMD_RECORD_PLAY = 38,	// Record Play == Record Start
	CMD_PLAY = 39,
	CMD_PAUSE = 40,
	CMD_STOP = 41,
	CMD_NEXT = 42,
	CMD_PREV = 43,
	CMD_FFWD = 44,
	CMD_FRWD = 45,
	CMD_SFWD = 46,
	CMD_SRWD = 47,
	CMD_SEARCH = 48,
	CMD_REPEAT = 49,
	CMD_AB_REPEAT = 50,
	CMD_STITLE = 51,
	CMD_AUDIO = 52,
	CMD_ANGLE = 53,
	CMD_ZOOM = 54,
	CMD_VOL_UP = 55,
	CMD_VOL_DOWN = 56,
	CMD_MUTE = 57,
	CMD_ZOOM_IN = 58,
	CMD_ZOOM_OUT = 59,
	CMD_QUALITY = 60,
	CMD_EPG = 61,
	CMD_EDIT = 62,

	// Extra
	CMD_BOOKMARK_SET = 63,
	CMD_BOOKMARK_RESTORE = 64,
	CMD_NEXT_FILE = 65,
	CMD_PREV_FILE = 66,
	CMD_ONETOUCH_COPY = 67,
	CMD_STOP_PLAYBACK = 68,

	// used by script string command
	CMD_STR_CMD = 69,
	CMD_START_BROWSER_DIR_CMD = 70,
	CMD_START_VIDEO_PLAYBACK = 71,
	CMD_START_PHOTO_PLAYBACK = 72,
	CMD_START_AUDIO_PLAYBACK = 73,
	CMD_START_SWF_PLAYBACK = 74,

	// used by ATSC channel number.
	CMD_POINT = 75,
	CMD_TELETEXT = 76,
	CMD_TELETEXT_SUBTITLE = 77,
	CMD_SUBTITLE_RESUME = 78,
	CMD_STILE_TYPE = 79,
	CMD_DISPLAY_VOUT = 80,

	CMD_PAGE_UP = 81,
	CMD_PAGE_DOWN = 82,
	CMD_AUDIO_CHANNEL = 250,
	CMD_EXIT = 251,

	// for adjusting subtitle delay
	CMD_SUBTITLE_DELAY_PLUS = 83,
	CMD_SUBTITLE_DELAY_MINUS = 84,
	CMD_SUBTITLE_CODE_PAGE = 85,

	CMD_WIFI_SCAN_FININSH = 86,//modify by longchao
	CMD_WIFI_PLUGIN = -87,//modify by longchao

	// Following Items are stale and may not use in the future
	CMD_TITLE = 88,
	CMD_TOOLS = 89,

	// for Network
	CMD_NET_GET_COMMAND = 90,
	CMD_MS_AP_COMM = 91,
	CMD_MEDIA_SERVER = 92,
	CMD_MEDIA_CLIENT = 93,
	CMD_NET_DISCONNECTED = -94,
	CMD_NET_CONNECTED = -95,
	CMD_NET_WIFI_UNPLUG = -96,
	CMD_NET_WPS_BTN = 97,

	CMD_FORCE_POWER = 98,
	CMD_SAFE_EJECT = 99,

	// External Force Control Code [via UART]
	CMD_SET_QUALITY 	= 100,
	CMD_SET_LANGUAGE 	= 101,
	CMD_FORCE_BROWSER 	= 102,
	CMD_FORCE_PASSTHROUGH = 103,
	CMD_FORCE_RECORD	= 104,
	CMD_FORCE_TIMESHIFT	= 105,
	CMD_FORCE_PLAY_LAST_TITLE = 106,
	CMD_SET_LIVEPAUSE_DEV = 107,
	CMD_SHOW_REVISION = 108,
	CMD_CONFIG_VIN_MODE = 109,


	//Multi-purpose four color keys
	CMD_OPTION_RED = 120,
	CMD_OPTION_GREEN = 121,
	CMD_OPTION_YELLOW = 122,
	CMD_OPTION_BLUE = 123,
	CMD_OPTION = 124,
	CMD_RELOAD_TVSYSTEM = 125,

	CMD_PICTURE_MODE=127,
#if defined(TV013UI_1) || defined(TV010UI_1)
	CMD_AUTOADJUST_END=128,
	CMD_SOUND_MODE=111,  //modify from 128 by starfu for YK-69HB 2011/06/13
	CMD_DISPLAY_RATIO=112,
	CMD_STOP_MUSIC=113,//modify by shuzhen_cao for stop music when finish playing last music in order play mode
	CMD_SYNC = 114,//for Remotekey
	CMD_SELECTED_SONG = 115,
	CMD_LOAD_MEDIA_FAIL = 116,
	CMD_STOP_PHOTO = 117,
	CMD_3SCREEN_STOP_VIDEO = 118,//add by starfu 2011/07/01 for stop video to can switch SwfPhotoPlaybackAP normally
	CMD_3SCREEN_TEXT_INPUT = 119,//add by starfu 2011/07/29 for 3screen text input from mobile phone to tv
	CMD_CH_UP = -121,
	CMD_CH_DOWN = -120,

	CMD_FAC_ENTER = 302, //tlm 20110630, enter factory menu
	CMD_FAC_SERIAL = 303,
	CMD_FAC_BUS	= 304, // yf 20110708
	CMD_FAC_WARM	= 305,
	CMD_FAC_AV1	=306,
	CMD_FAC_YPBPR1 =307, // tlm 20110721
	CMD_FAC_VGA1    =308,
	CMD_FAC_HDMI1 =309,
	CMD_FAC_HDMI2=310,
	CMD_FAC_HDMI3=311,
	CMD_FAC_ADC=312,
	CMD_FAC_RESET=313,
	CMD_FAC_SOURCE_ADD = 314,
	CMD_FAC_SOURCE_DEC = 315,
	CMD_FAC_EXIT = 316,
	CMD_FAC_RFAGC = 317,
	CMD_FAC_KARAOKE = 318,
	CMD_FAC_UPLAYER = 319,
	CMD_FAC_IPSET = 320,
	CMD_FAC_LIGHT_SENSOR = 321,
	CMD_FAC_WHITE_BALANCE = 322,
	CMD_FAC_SINGLE_LISTEN = 323,
	CMD_FAC_MANUAL_SCAN_UP = 324,
	CMD_FAC_MANUAL_SCAN_DOWN = 325,
	CMD_SHOW_AUTOSCANGUIDE = 326,
	CMD_3SCREEN_CHANGE_SAME_AP = 327,
	CMD_3SCREEN_VIDEO_AUDIO = 328,
	CMD_3SCREEN_PHOTO_VIDEO = 329,
	CMD_3SCREEN_AUDIO_PHOTO = 330,
	CMD_ROTATE_LEFT = 331, //add by sarfu 2011/08/09 for 3screen model
	CMD_ROTATE_RIGHT = 332,//add by sarfu 2011/08/09 for 3screen model
	CMD_SHARE = 333,//add by starfu 2011/08/08 for CloudDesktop.apk
	//       CMD_3D_MODE =334,////jianfei_zhou 0812

	CMD_PHOTO_DECODE_FAIL = 335, //20110817 peggy
	CMD_PHOTO_DECODE_DONE = 336,

	CMD_3SCREEN_BROWSER_AUDIO = 337,
	CMD_3SCREEN_BROWSER_VIDEO = 338,
	CMD_3SCREEN_BROWSER_PHOTO = 339,

	CMD_EXIT_FACTORY_MENU = 340,   //tlm 20110818
	CMD_NEXT_PHOTO=341,
	CMD_PREV_PHOTO=342,
	CMD_REVIEW = 343,   //jacklong 20111102
	CMD_3D_CLOUD=344,
	CMD_APP_SHOP=345,
	CMD_AD_READY =346,
#else
	CMD_AUTOADJUST_END=111,
	CMD_SOUND_MODE=128,
	CMD_DISPLAY_RATIO=129,
#endif

	CMD_INTRO=130,
	CMD_DASH=131,
	CMD_HOME=132,
	CMD_SHORTCUT=134,
	CMD_CHANNEL_INC=135,
	CMD_CHANNEL_DEC=136,
	CMD_VII=137,
	CMD_FREEZE=138,

	//20110523
	CMD_PIP=139,
	CMD_POP=140,
	CMD_MP=141,
	CMD_JUMP=142,
	CMD_FAVCH=143,
	CMD_PROGINFO=144,
	CMD_WIDE=145,
	CMD_CAPTION=146,
	CMD_VIDEO=147,
	CMD_ROI=148,
	CMD_SLEEP=149,
	CMD_3D_MODE =150,
	CMD_VOL_SHOW =151,
	CMD_NOTE_INFO =152,

	CMD_PL_SOURCE = 201,
	CMD_PL_MENU = 202,
	CMD_PL_UP = 203,
	CMD_PL_DOWN = 204,
	CMD_PL_LEFT = 205,
	CMD_PL_RIGHT = 206,
#if	defined(ENABLE_PANEL_LOCK)
	CMD_PANEL_LOCK = -201, //if PANEL_LOCK =On, no send keypad Msg, just show PanelLock Msg
	CMD_PANELLOCK_LOCKSCREEN = 444,
#endif
	//yilu_pan added 20111120
	CMD_VOD_SYSTEM=207,
	CMD_RESERVATION=208,
	CMD_LIVE=209,
	CMD_SOUNDEFFECT_CONTROL=210,
	CMD_FUNCTION=211,
	CMD_SOUNDTRACK=212,
	CMD_RECORDING=213,
	CMD_PRIORITY=214,
	CMD_SCORES_SHOWED=215,
	//CMD_DELETE=219,//yilu_pan 20111120

	//SI	use
	CMD_SI_GOT_NEW_PROGRAM=216,
	CMD_SI_GOT_NEW_CUR_PROGRAM=217,

	//Gilbert 2012/3/1 For customer TV_005_1
	CMD_QUICK=218,
	CMD_LIST=219,
	CMD_TT_INDEX=220,
	CMD_TT_REVEAL=221,
	CMD_TT_HOLD=222,
	CMD_TT_SIZE=223,
	CMD_TT_TXCL=224,
	CMD_HOTEL_MODE=225,
	CMD_SERVICE_MODE=226,
	CMD_HOTEL_CLONE_MODE=227,
	CMD_KEY_SOURCE=228,
	CMD_KEY_UP=229,
	CMD_KEY_DOWN=230,
	/////////////////////////TV_005_1 End

	/* Command Type II: Tokens for Internal Event */
	CMD_TIMER 			= -20,
	CMD_SCHEDULE_UPDATE = -30,	// via Web Interface
#ifdef USE_CAMERA
	CMD_SATA_UPDATED    = -49,  // SATA has been updated
#endif
	CMD_DISC_INSERTED 	= -40,	// Disc Insertion Event
	CMD_STORAGE_UPDATED	= -50,	// Storage has been updated
	CMD_USB_UPDATED_TIMESHIFTABLE 	= -51,	// USB has been updated and timeshiftable.
	CMD_HID_UPDATED  = -52,

	CMD_USBMOUSE_UPDATED = -55,
	CMD_USB_KEYBD 		 = -56,

	CMD_TERMINATE  		= -60,	// terminate file record AP
	CMD_ONPAINT         = -61,   //added by sunling: indicate need to repaint UI.
	// We occupy -62 to -69. reserved.
	CMD_CUSTOM_END      = -62, // @Fixme cmd_custom is internal custom message, user should use CMD_CUSTOM + messageID, from 0 up to 7.
	CMD_CUSTOM          = -69,
	CMD_COMPLETED 		= -70,	// indicating playback completion
#if defined(TV013UI_1) || defined(TV010UI_1)
	CMD_VBUFFER_START		= -71,	// indicating playback vbufferstart
	CMD_VBUFFER_END		= -72,	// indicating playback vbufferend
	CMD_VLOAD_FAILED		= -73,	// indicating playback vfailed
	CMD_VPLAY_START		= -74,	// indicating playback vstart

#endif
	CMD_TIMESHIFT 		= -80,	// for sync timeshift restart
	CMD_REQUEST_PML 	= -90,	// request parental management level (PML)
#if defined(ENABLE_ANDROID)
	// for communication with Android
	CMD_ANDROID_SWITCH	= -91,
	CMD_ANDROID_READY	= -92,
#endif
	CMD_USB_PLUGGED_IN	= -100, // USB Plugged-In Event
	CMD_USB_DVD_EVENT   = -101,  // USB DVD Plug-In or UnPlug
	CMD_FLOW_EVENT 		= -102,

	/* Command Type III: Tokens helping QA/Debugging */
	CMD_TIMELOGGING 	= -103,
	CMD_AUDIO_NEXT      = -104,
	CMD_FLOW_ERR_EVENT  = -105,
	CMD_USER_DEFINE     = -106,

	CMD_DRMRENTAL_EXPIRED	= -107,
	CMD_DRMRENTAL_REQUEST   = -108,

	/* Command Type IV: Null Operation */
	CMD_NOP	= -1,

	// used by HDMI HDCP ON/OFF number.
	CMD_HDCP_ON  = -122,
	CMD_HDCP_OFF = -123,
	// used by HDMI HOT PLUG DETECT.
	CMD_HDMI_HPD = -124,
	CMD_HDMI_READY = -125,
	CMD_HDMI_YST_MODE = -126,
	CMD_DECODE_FINISH = -127,

	//add for gtalk
	CMD_IM_STATUS=-109,
	CMD_IM_FILE_STATUS=-110,
	CMD_IM_MSG_TXT=-111,
	CMD_PLAYATTIME = -112,
	// for skype events
	CMD_SKYPE_EVENT = -113,

	CMD_SCAN_FREQ_UPDATE= -114,
	CMD_SCAN_AUTO_COMPLETE = -115,
	CMD_SCAN_MANUAL_COMPLETE = -116,
	CMD_SCAN_SEEK_COMPLETE = -117,
	CMD_DB_SCAN_START = -118,
	CMD_DB_SCAN_END = -119,
	CMD_SCAN_AUTO_HIT_ONE_COMPLETE = -120,

#ifdef RSSOGLES
	CMD_IMS3D_RELOAD_MODEL = -10,
	CMD_IMS3D_RELOAD_TEXTURE = -11,
	CMD_IMS3D_RELOAD_RSSSCRIPT = -12,
	CMD_IMS3D_RELOAD_ALL = -13,
	CMD_IMS3D_PRINTSCREEN = -18,
#endif

	CMD_DVDMENU = -128,
	CMD_RESET_OSDTIMER = -129,
	CMD_PB_UPDATE_INFO = -130,

#ifdef ENABLE_FACE_DETECTION
	CMD_FACE_DETECT_RESULT = 199,
#endif

#ifdef USE_CAMERA
	CMD_CALL_IN = 200,
#endif

	CMD_AP_SWITCHTO_GAMEAP = 300,
	CMD_SWITCHTO_ROOTAP = 301,
	CMD_SWITCHTO_CATEGORY1 = 302,

#if defined(BUILD_TV015_1_ATV)
	CMD_SOURCE_ATV1 = 303,
	CMD_SOURCE_AV1 = 304,
	CMD_SOURCE_HDMI1 = 305,
	CMD_SOURCE_USB1 = 306,
#endif

	CMD_TV_CHANNEL_AUTO_SCAN_FINISH = 350,
	CMD_SCAN_NO_WIFI = 351,
	CMD_DLNADMR_RESTART = -2,

} USER_CMD;

/************************************************************************
 *  rtk log define
 ************************************************************************/
#define KP_EMERG(fmt, args...)      \
	rtd_printk( KERN_EMERG, DEV_NAME, fmt , ## args)

#define KP_ALERT(fmt, args...)   \
	rtd_printk( KERN_ALERT, DEV_NAME, fmt , ## args)

#define KP_CRIT(fmt, args...)   \
	rtd_printk( KERN_CRIT, DEV_NAME, fmt , ## args)

#define KP_ERR(fmt, args...)   \
	rtd_printk( KERN_ERR, DEV_NAME, fmt , ## args)

#define KP_WARNING(fmt, args...)   \
	rtd_printk( KERN_WARNING, DEV_NAME, fmt , ## args)

#define KP_NOTICE(fmt, args...)   \
	rtd_printk( KERN_NOTICE, DEV_NAME, fmt , ## args)

#define KP_INFO(fmt, args...)   \
	rtd_printk( KERN_INFO, DEV_NAME, fmt , ## args)

#define KP_DEBUG(fmt, args...)   \
	rtd_printk( KERN_DEBUG, DEV_NAME, fmt , ## args)



#endif
