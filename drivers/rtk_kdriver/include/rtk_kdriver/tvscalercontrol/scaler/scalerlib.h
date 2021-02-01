#ifndef __SCALER_LIB_H__
#define __SCALER_LIB_H__

#ifdef __cplusplus
extern "C" {
#endif


#include <tvscalercontrol/scalerdrv/scalerdisplay.h>
#if defined BUILD_TV005_2
#include <tvscalercontrol/vip/icm.h>
#endif
#include <tvscalercontrol/vip/scalerColor.h>
#include <tvscalercontrol/scaler/scalercolorlib.h>
//#include <rtd_media_types.h>
// oliver+
//#include "../../../../../../common/IPC/generate/include/system/VideoRPC_Agent_data.h"
//#include <Application/AppClass/setupdef.h>
#include <tvscalercontrol/scaler/vipinclude.h>
#if defined(BUILD_TV030_2)
#include <../../../../project/TvSC_TV030/Custom/executor/dbc_api.h>
#endif

typedef enum {
	YPBPR_AV_INITIAL_STATE = 0x00,
	YPBPR_AV_CHECK_COLOR_BURST_STATE,
	YPBPR_AV_DETECT_FINISH_STATE
} YPBPR_AV_PROC_STATE;

typedef enum {
	YPBPR_AV_IN_NONE_STATE = 0x00,
	YPBPR_AV_IN_AV_STATE,
	YPBPR_AV_IN_YUV_STATE
} YPBPR_AV_DETECT_BY_PIN_PROC_STATE;

/*==================== Definitions ================= */
// enumerate the reasons of forcing to background
typedef enum _SLR_FORCE_BG_REASON {

	SLR_FORCE_BG_SYSTEM = 0,	// background by system flow.
	SLR_FORCE_BG_VCHIP,			// background by V-Chip.
	SLR_FORCE_BG_NO_SIGNAL,		// background used during no signal.
	SLR_FORCE_BG_CHANNEL_TRANS,	// background used furing channel transition.
	SLR_FORCE_BG_AP,			// background by AP.
	SLR_FORCE_BG_SHOW,	// background used bootup logo.
	SLR_FORCE_BG_BOOTUP,	// background used bootup logo.
#if defined(TV032_1)||defined (TV014_1)||(defined TV014_2)	//yq_zhang 2012.06.07
	SLR_FORCE_BG_AGING,
	SLR_FORCE_BG_CHANNEL_HIDE,
#elif defined (BUILD_TV033_1_ISDB)
	SLR_FORCE_BG_AGING,
#elif defined(TV003_ADTV)
        SLR_FORCE_BG_SWITCH_ATV,  // background used during switching source to ATV
        SLR_FORCE_BG_CH_SCAN,
        SLR_FORCE_BG_AUDIO_ONLY,
#endif	//end of TV032_1
	SLR_FORCE_BG_MAX,

} SLR_FORCE_BG_REASON;

typedef enum _SCALER_REG_TABLE_TYPE {

	SCALER_REG_TABLE_VGA_MODEINFO,
	SCALER_REG_TABLE_VGA_GAINOFFSET,
	SCALER_REG_TABLE_YPBPR_GAINOFFSET,
	SCALER_REG_TABLE_SCREENMODEINFO,

	SCALER_REG_TABLE_CDS,  // added this for Color Dependent Sharpness, Jerry Wu 20090420
	SCALER_REG_TABLE_TV_AutoNR_Signal_Status,
	SCALER_REG_TABLE_EGSM_PostSHP_Coef,//20101013 csfanchiang
	SCALER_REG_TABLE_I_EDGE_Smooth_Coef,//20120301 march
	SCALER_REG_TABLE_Auto_Function_Array1,
	SCALER_REG_TABLE_Auto_Function_Array2,
	SCALER_REG_TABLE_HDMI_MODE,
	SCALER_REG_TABLE_VGA_MODE,
	SCALER_REG_TABLE_PRESET_MODE,
	SCALER_REG_TABLE_YPBPR_MODE,
	SCALER_REG_TABLE_AV_PRESET,
	SCALER_REG_TABLE_V8_PRESET,
	SCALER_REG_TABLE_VGA_POSITION,
	SCALER_REG_TABLE_HDMI_CHANNEL0_CONFIG,
	SCALER_REG_TABLE_HDMI_CHANNEL1_CONFIG,
	SCALER_REG_TABLE_HDMI_CHANNEL2_CONFIG,
	SCALER_REG_TABLE_HDMI_HDCP_KEY,
	SCALER_REG_TABLE_Ddomain_SHP,
	SCALER_REG_TABLE_EMF_COEF,
	SCALER_REG_TABLE_TwoD_peaking_AdaptiveCtrl,
	SCALER_REG_TABLE_SHP_COEF,
	SCALER_REG_TABLE_Edge_SHP_COEF,	//CSFC, 20110504
	SCALER_REG_TABLE_Vertical_SHP_COEF,	//CSFC, 20110504
	SCALER_REG_TABLE_INPUT_SHP_COEF,
	SCALER_REG_TABLE_SU_PK_COEFF,
	SCALER_REG_TABLE_SU_PK_COEFF_BY_TIMING,
	SCALER_REG_TABLE_SR_INIT_TABLE,
	//SCALER_REG_TABLE_DCC_LEVEL_TABLE,   //20120827 added by CSFC   remove
	//SCALER_REG_TABLE_RTNR_Y_C_COEFF,    //20100817 added by Leo Chen       remove
	SCALER_REG_TABLE_ODtable_COEFF,//young vippanel
	SCALER_REG_TABLE_DNR_LEVEL_TABLE,   //20100921 added by Leo Chen

	//SCALER_REG_TABLE_dbDCCHisto,
	//SCALER_REG_TABLE_dbDCCCurve,
	SCALER_REG_TABLE_NR_TABLE32,
	SCALER_REG_TABLE_NR_TABLE8,

	SCALER_REG_TABLE_NR_TABLE,
	SCALER_REG_TABLE_PQA_INPUT_TABLE,     //remove
	SCALER_REG_TABLE_PQA_TABLE,           //remove

//#ifdef ENABLE_DCR
	SCALER_REG_TABLE_DCR_TABLE,              //20101111 added by Leo Chen
//#endif
	SCALER_REG_TABLE_MAGIC_PICTURE_INFO,
	SCALER_REG_AV_OFFSET,
	SCALER_REG_SV_OFFSET,
//	SCALER_REG_TABLE_NOTSUPPORTTIMING,
//	SCALER_REG_TABLE_SKIPTIMNG,
	SCALER_REG_FUNC_OVERSCAN,
	SCALER_REG_FUNC_GET_SRC_OVERSCAN,
	SCALER_REG_FUNC_GET_OVERSCAN_RATIO,
	SCALER_REG_TABLE_VGIP_ADJUSTMENT,
	SCALER_REG_FUNC_CUSTOMER_EXTRA_CONDITION,
	SCALER_REG_FUNC_JUDGE_CONFUSE_MODE,
	SCALER_REG_FUNC_HDMI_JUDGE_CONFUSE_MODE,
	SCALER_REG_FUNC_HDMI_JUDGE_UNSOPPORT_MODE,
	SCALER_REG_FUNC_USER_DEF_CONFUSE_MODE,
	SCALER_REG_TABLE_VGA_YPBPR_TABLE_SIZE,
	SCALER_REG_TABLE_VGA_ACCEPTIVE_TABLE,
	SCALER_REG_TABLE_VGA_ACCEPTIVE_TABLE_SIZE,
	SCALER_REG_TABLE_VGA_USER_FIFO_MODE,
	SCALER_REG_VGA_DOS_TIMING,
	SCALER_REG_TABLE_VD_NTSC_3D_TABLE_0,
	SCALER_REG_TABLE_VD_PAL_3D_TABLE_0,
	SCALER_REG_TABLE_UV_Gains_1,
	SCALER_REG_TABLE_UV_Gains_2,
	SCALER_REG_TABLE_AutoView_Max_Min_Table, // Hawaii add for new AutoView 20131001
	//SCALER_REG_TABLE_YUV2RGB_COEF_BY_Y,
	//SCALER_REG_TABLE_YUV2RGB_UV_OFFSET_BY_Y,
	SCALER_REG_FUNC_GET_SRC_3DOVERSCAN,
#ifdef ENABLE_MHEG5
    SCALER_REG_TABLE_MHEG5_ADJUSTMENT,
    SCALER_REG_TABLE_MHEG5_DISPLAY_CHANGE_NOTIFY,
#endif
	//SCALER_REG_TABLE_DCC_skin_tone_TABLE,
	//SCALER_REG_TABLE_SD_H_Table,
	//SCALER_REG_TABLE_SD_V_Table,
	SCALER_REG_TABLE_Ddomain_MBPK,
	SCALER_REG_TABLE_VIP_TABLE,
	SCALER_REG_TABLE_VIP_TABLE_CUSTOM,

	SCALER_SET_DisplayInformation_table,
	SCALER_REG_AP_CHANGE_SOURCE,
#if defined(TV003_ATSC) || defined(TV003_ISDB)
    SCALER_SET_VGA_Fine_Sync,
#endif //#if defined(TV003_ATSC) || defined(TV003_ISDB)
}SCALER_REG_TABLE_TYPE;

typedef enum _SCALER_SIGNAL_STATUS {
	SCALER_SIGNAL_DETECT = 0,
	SCALER_SIGNAL_DISPLAY,
	SCALER_SIGNAL_NOTHING,
} SCALER_SIGNAL_STATUS;

#define SCALERLIB_MADI_OFF				0
#define SCALERLIB_MADI_STANDARD			1
#define SCALERLIB_MADI_AUTO				2
#define SCALERLIB_CROSSCOLOR_OFF		0
#define SCALERLIB_CROSSCOLOR_STANDARD	1
#define SCALERLIB_CROSSCOLOR_AUTO		2

#define SCALERLIB_PatternColor_OFF		0
#define SCALERLIB_PatternColor_RED		1
#define SCALERLIB_PatternColor_GREEN	2
#define SCALERLIB_PatternColor_BLUE		3
#define SCALERLIB_PatternColor_WHITE	4
#define SCALERLIB_PatternColor_BLACK	5
#define SCALERLIB_PatternColor_COLORBAR	6
#define SCALERLIB_PatternColor_GRAYBAR	7
//yanger20130114 modify for factory string command>
#ifdef CONFIG_ENABLE_COMPAL_LA_FACTORY_STRING_COMMAND
#define SCALERLIB_PatternColor_GRAY_25P	8
#define SCALERLIB_PatternColor_GRAY_50P	9
#endif
//yanger20130114 modify for factory string command<

#define SCALERLIB_PatternColor_DCC_ON	254
#define SCALERLIB_PatternColor_DCC_OFF	255
#ifdef ENABLE_FACTORY_FUNCTIONS_TCL //hardy20121212
#define SCALERLIB_PatternColor_YELLOW	8
#define SCALERLIB_PatternColor_GRAY	9
#endif

/*==================== Functions ================== */


//========================================================================
//
//				Source Control & PIP
//
//========================================================================


typedef enum _SLR_PIP_MODE {

	SLR_PIP_NONE	= 0x01,			// none, bit 0 for main don't need to change!!
	SLR_PIP_SMALL	= 0x03,			// small, bit 0 for main don't need to change!!
	SLR_PIP_MEDIUM	= 0x05,			// medium, bit 0 for main don't need to change!!
	SLR_PIP_LARGE	= 0x07,			// large, bit 0 for main don't need to change!!
	SLR_PIP_MLSR	= 0x08,			// side by side, main need to change
	SLR_PIP_MLSR4X3	= 0x0a,			// another side by side, main need to change
	SLR_PIP_MP2X2	= 0x0b,			// 2X2, bit 0 for main don't need to change!!
	SLR_PIP_MP3X3	= 0x0d,			// 3X3, bit 0 for main don't need to change!!
	SLR_PIP_MP4X4	= 0x0e,			// (0x0f ??) 4X4, bit 0 for main don't need to change!!
	SLR_PIP_MP1C12B = 0x10,			// 12 sub multi-pictures besieges one main center picture
	SLR_PIP_MP1L7B	= 0x14,			// 7 multi-pictures besieges one main left-top picture
	SLR_PIP_FULL	= 0x16,			// for OSD full screen blending
	SLR_PIP_CUSTOM = 0x19,			//  custom sub display window, bit 0 for main don't need to change!!
	SLR_PIP_ALL		= 0x20,			// ??

} SLR_PIP_MODE;

typedef enum _SLR_PIP_SUB_POS {

	SLR_PIP_TOP_LEFT = 0,
	SLR_PIP_BOTTOM_LEFT,
	SLR_PIP_CENTER,
	SLR_PIP_TOP_RIGHT,
	SLR_PIP_BOTTOM_RIGHT,

} SLR_PIP_SUB_POS;



typedef struct _ZOOM_INIT_INFO
{
	unsigned char vga_value;
	unsigned char dvi_value;
	unsigned char ypbpr_value;
	unsigned char hdmi_value;
	unsigned char tv_value;
	unsigned char av_value;
	unsigned char sv_value;
}ZOOM_INIT_INFO;

typedef enum _SLR_PICTURE_INFO{
	SLR_PICTURE_I_DLTI = 0x00,
	SLR_PICTURE_I_DCTI,
	SLR_PICTURE_MEMC22,
	SLR_PICTURE_MEMC32,
	SLR_PICTURE_TNR_XC,
	SLR_PICTURE_RTNR_Y,
	SLR_PICTURE_V_DCTI,
	SLR_PICTURE_I_CCORING,
	SLR_PICTURE_D_CCORING,
	SLR_PICTURE_GRIDREMOVE,
	SLR_PICTURE_CONTISTILLLINE,
	SLR_PICTURE_INTRANEWBLEND,
	SLR_PICTURE_INTRANEWLOWANGLE,
	SLR_PICTURE_SUPK_TYPE,
	SLR_PICTURE_RTNR_C,
}SLR_PICTURE_INFO;

typedef enum _SLR_SLR_ACTIVE_BACKLIGHT{
	SLR_BlackAPL_a_HSCA	= 0,
	SLR_BlackAPL_b_HSCB,
	SLR_BlackAPL_c_HSCC,
	SLR_BlackAPL_d_HSCD,
	SLR_BlackAPL_e_HSCE,
	SLR_BlackAPL_f_HSCF,
	SLR_BlackAPL_g_HSCG,
	SLR_BlackAPL_h_HSCH,
	SLR_BlackAPL_BL_Th1_SABH,
	SLR_BlackAPL_BL_Th1_SABL,
	SLR_BlackAPL_BL_Th2_EABH,
	SLR_BlackAPL_BL_Th2_EABL,
	SLR_BlackAPL_BL_Th3_MLBL,
	SLR_BlackAPL_M_ATAB,
	SLR_BlackAPL_KU_USAB,
	SLR_BlackAPL_KD_DSAB,
	SLR_APL_BL_MAX,
	SLR_APL_BL_MIN,
	SLR_ACTIVE_BACKLIGHT_ALL,
}SLR_ACTIVE_BACKLIGHT;


typedef enum _SLR_INPUTWID_CALFUN_TYPE{
	SLR_INPUTWID_CALFUN_M1024S360,
	SLR_INPUTWID_CALFUN_MAX,
} SLR_INPUTWID_CALFUN_TYPE;

typedef enum _SLR_NO_SIGNAL_MUTE_TYPE{
	SLR_NO_SIGNAL_TYPE_NULL,							//default
	SLR_CHANNEL_CHANGE_MUTE_TYPE,					//Channel change
	SLR_TV_TO_EXT_EXT_KEY_MUTE_TYPE,				//TV¡÷EXT (EXT key)
	SLR_EXT_TO_TV_EXT_KEY_MUTE_TYPE,				//EXT¡÷TV (EXT key)
	SLR_EXT_TO_TV_CH_UP_DOWN_KEY_MUTE_TYPE,		//EXT¡÷TV (channel Up/Down)
	SLR_EXT_TO_TV_CH_KEY_MUTE_TYPE,					//EXT¡÷TV (channel direct)
	SLR_EXT_TO_EXT_MUTE_TYPE,						//EXT¡÷EXT
	SLR_MUTE_VOLUME0_MUTE_TYPE,						//Mute: On, Volume=0
	SLR_DC_ON_OFF_MUTE_TYPE,							//Sub Power ON/OFF
	SLR_AC_ON_MUTE_TYPE,								//Main Power (AC) ON
	SLR_AC_OFF_MUTE_TYPE,							//Main Power (AC) OFF
	SLR_AUTO_TUNING_MUTE_TYPE,						//Auto tuning
	SLR_ADVANCED_SOUND_MODE_CHANGE_MUTE_TYPE,	//Advanced Sound mode change
	SLR_MTS_CHANGE_BY_RC_MUTE_TYPE,				//MTS change by remote unit
	SLR_RF_NO_SIGNAL_MUTE_TYPE,						//RF signal cannot be detected
	SLR_NO_SIGNAL_MUTE_TYPE_MAX,
} SLR_NO_SIGNAL_MUTE_TYPE;


typedef struct _SLR_MDOMAIN_DATA {
	unsigned char	avaliable;
	unsigned int 	Mdomain_addr;
	unsigned int 	Mdomain_cache_addr;
	unsigned int 	Mdomain_uncache_addr;
	unsigned short	Mdomain_width;
	unsigned short	Mdomain_height;
	unsigned short	pic_width;
	unsigned short	pic_height;
	unsigned short	original_pic_width;
	unsigned short	original_pic_height;
}SLR_MDOMAIN_DATA;
#if 0
typedef struct _RPC_SHARE_MEM_INFO {
	unsigned int			ulOffset;			//Memory offset
	unsigned int			ulSize;				//Memory size
} RPC_SHARE_MEM_INFO;
#endif
// VGIP2 input source double clock control state
typedef enum _DOUBLE_CLOCK_CTRL_STATE {
	VGIP2_2X_CLK_NON_ACTIVE	= 0,		/* Native input source */
	VGIP2_2X_CLK_VGIP2_INIT	= 1,		/* Start to initial VGIP2 for video capture */
	VGIP2_2X_CLK_VO_INIT		= 2,		/* Switch input source to VO and init VO component */
	VGIP2_2X_CLK_VO_GO		= 3,		/* VO config done and start capture video */
	VGIP2_2X_CLK_DISP_READY	= 4,		/* Scaler complete mode change flow and send display ready to UI thread */
	VGIP2_2X_CLK_PLAYING		= 5,		/* VO detect a new capture buffer */
}DOUBLE_CLOCK_CTRL_STATE;

typedef struct _SRC_INFO{
	unsigned int videoMode;
	unsigned int chroma_422Cap;
	unsigned int width;
	unsigned int height;
	unsigned int frame_rate;
	unsigned int interlacedVideo;
	unsigned int ihCount;
	unsigned int ihCount_offLine;
	unsigned int ivCount;
}SRC_INFO;

typedef enum _SRC_TYPE SRC_TYPE;

typedef struct _VGIP2_CTRL_INFO {
	DOUBLE_CLOCK_CTRL_STATE 	curState;
	SRC_TYPE					srcType;
	unsigned char						srcFrom;
	unsigned char						srcIndex;
	SRC_INFO					srcInfo;
	unsigned char						srcChanged;	// Input source is changed before VGIP2 be released
	unsigned char						srcInHand;	// VGIP2 Input source not be released
}VGIP2_CTRL_INFO;

typedef enum _MAINSUB_SHOWONPR_STATUS{
	MAINSUB_SHOWONPR_NON_ACTIVE = 0,	/*no opration*/
	MAINSUB_SHOWONPR_STORE_MAIN = 1,	/*re init main source for store orignal */
	MAINSUB_SHOWONPR_INIT_SUB = 2,	/*re init main source for store orignal */
	MAINSUB_SHOWONPR_INIT_MAIN = 3,	/*re init sub source*/
	MAINSUB_SHOWONPR_DISPLAY_ON = 4,	/*re init main source*/
}MAINSUB_SHOWONPR_STATUS;

typedef struct _MAINSUB_SHOWONPR_INFO{
	MAINSUB_SHOWONPR_STATUS	curState;
	unsigned int					mainWidth;
	unsigned int					mainLength;
	unsigned int					mainInterlace;
	unsigned int					subWidth;
	unsigned int					subLength;
	unsigned int					subInterlace;
	unsigned int					displayWidth;
	unsigned int					displayLength;
}MAINSUB_SHOWONPR_INFO;

// Check which VO is for the 2D main video
ENUM_TVD_INPUT_FORMAT Scaler_Get_2D_VodmaIndex(void);
VO_VIDEO_PLANE Scaler_Get_2D_VoPlane(void);
VO_VIDEO_PLANE Scaler_Get_3D_VoPlane(void);
// Force enable VO UZU path control (bypass IDMA in VO source)
void Scaler_Set_forceEnable_VO_UZU(unsigned char enable);
unsigned char Scaler_Get_forceEnable_VO_UZU(void);


typedef enum _DISPD_CAP_SRC{
	CAP_SRC_UZU,
	CAP_SRC_SUBTITLE,
	CAP_SRC_OSD,
	CAP_SRC_DITHER,
	SCART_OUT_DTV
}DISPD_CAP_SRC;

typedef enum _DISPD_CAP_MODE{
	CAP_MODE_SEQ,
	CAP_MODE_BLOCK
}DISPD_CAP_MODE;

typedef enum _DISPD_CAP_FMT{
	CAP_420,
	CAP_422
}DISPD_CAP_FMT;

#ifdef ENABLE_PWR_IP_CLOSE_SIRIUS
typedef enum DIGITAL_CLK_TYPE {
	CLOCK_ATV,
	CLOCK_DTV,
	CLOCK_ADC,//YPP/VGA
	CLOCK_CVBS,
	CLOCK_HDMI,
	CLOCK_USB_ANTUTU
}DIGITAL_CLK_TYPE;

void Scaler_close_digitalpart(DIGITAL_CLK_TYPE SrcClkType);

void Scaler_open_digitalpart_allclock(void);

#endif

typedef struct _IDMA_DISPD_CAPTURE_INFO{
	unsigned char enable;
	DISPD_CAP_SRC capSrc;
	DISPD_CAP_MODE capMode;
	DISPD_CAP_FMT capFmt;
	unsigned int capWid;
	unsigned int capLen;
}IDMA_DISPD_CAPTURE_INFO;

//Rotate related info
#if 0//def CONFIG_ENABLE_SE_ROTATE_M_DOMAIN_BLOCK_MODE
typedef enum _MAINSUB_ROTATE_STATUS{
	MAIN_ROTATE_NON_ACTIVE = 0,	/*no opration*/
	MAIN_ROTATE_INIT_UZD = 1,	//UZD : 1920x1080=>1080x1080
	MAIN_ROTATE_INIT_VI = 2,	/*RPC to video fw to initial VI*/
	MAIN_ROTATE_UPDATE_BLOCK_READ = 3,	/*re init main source vodma */
	MAIN_ROTATE_DISPLAY_ON = 4,
}MAINSUB_ROTATE_STATUS;
#endif

void Scaler_SetFacPatternColor(unsigned char val);

// IDMA capture control
void Scaler_Set_DispDCaptureMode(IDMA_DISPD_CAPTURE_INFO capInfo);
unsigned char Scaler_Get_DispDCaptureStatus_enable(void);
void Scaler_Set_DispD2TVECaptureMode(IDMA_DISPD_CAPTURE_INFO capInfo);

unsigned char Scaler_GetIsFirstChangeSrc(void);

/**
 * Scaler_ChangeMainSource
 * change the source of main channel
 *
 * @param { index: depend on each PCB }
 * @param { info: pointer of TV channel info, NULL for non-TV source }
 * @param { ratio_type: aspect ratio type}
 * @return { TRUE/FALSE }
 *
 */
unsigned char Scaler_ChangeMainSource(unsigned char index, SLR_TV_CHANNEL_INFO *info, SLR_RATIO_TYPE ratio_type);
unsigned char Scaler_ChangeMainSourceAudio(unsigned char index, SLR_TV_CHANNEL_INFO *info, SLR_RATIO_TYPE ratio_type);

#if 0
/**
 * Scaler_ChangeChannelMode
 * let scaler task know this status for some change channel effect (like freeze video when change channel from ATV1 to ATV2)
 *
 * @param { mode: TRUE/FALSE }
 *
 */
void Scaler_ChangeChannelMode(unsigned char mode);
#endif

/**
 * Scaler_PipSetMode
 * enable pip/mp mode and set type
 *
 * @param { type:  }
 * @return { TRUE/FALSE }
 *
 */
unsigned char Scaler_PipSetMode(SLR_PIP_MODE mode);

/**
 * Scaler_SubDisplayWindowChange
 * set pip custom mode and set sub dispay window by parameter need not rerun scaler
 *
 * @param { m_setsubdispwin : the StructSrcRect structure can adjust sub channel display window}
 * @return { TRUE/FALSE  }
 *
 */
unsigned char Scaler_SubWindowPositionChange(unsigned short srcx, unsigned short srcy);

/**
 * Scaler_PipSetSubDisplayWindow
 * set pip custom mode and set sub dispay window by parameter
 *
 * @param { m_setsubdispwin : the StructSrcRect structure can adjust sub channel display window}
 * @return { TRUE/FALSE  }
 *
 */
unsigned char Scaler_PipSetSubDisplayWindow(StructSrcRect m_setsubdispwin);

/**
 * Scaler_PipGetMode
 * get current mode of pip/mp
 *
 * @param { void  }
 * @return { mode }
 *
 */
SLR_PIP_MODE Scaler_PipGetMode(void);

/**
 * Scaler_PipSetSubPosition
 * set the position of sub channel
 *
 * @param { pos:  }
 * @return { TRUE/FALSE }
 *
 */
unsigned char Scaler_PipSetSubPosition(SLR_PIP_SUB_POS pos);

/**
 * Scaler_PipGetSubPosition
 * get the position of sub channel
 *
 * @param { void  }
 * @return { SLR_PIP_SUB_POS }
 *
 */
SLR_PIP_SUB_POS Scaler_PipGetSubPosition(void);

/**
 * fwif_pip_setPosition
 * swap the source of main/sub sub channel
 *
 * @param { none  }
 * @return { none}
 *
 */
unsigned char Scaler_PipSwapSource(void);

/**
 * Scaler_PipChangeSubSource
 * change the source of sub channel
 *
 * @param { index: depend on each PCB  }
 * @param { info: pointer of TV channel info }
 * @return { TRUE/FALSE }
 *
 */
unsigned char Scaler_PipChangeSubSource(unsigned char index, SLR_TV_CHANNEL_INFO *info);

/**
 * Scaler_PipSetSubBlending
 * set the blending level of sub channel
 *
 * @param { value:0~128 , 0 mean not transparent }
 * @return { TRUE/FALSE }
 *
 */
unsigned char Scaler_PipSetSubBlending(unsigned char value);

/**
 * Scaler_RegTable
 * reg custom table to libary
 *
 * @param { type }
 * @param { ptr: table address }
 * @return { TRUE/FALSE }
 *
 */
unsigned char Scaler_RegTable(SCALER_REG_TABLE_TYPE type, void *ptr);

/**
 * Scaler_PipInit
 * sync pip parameter with scaler task
 *
 * @param { type:  }
 * @return { TRUE/FALSE }
 *
 */
//unsigned char Scaler_PipInit( SLR_PIP_MODE mode, SLR_PIP_SUB_POS pos, unsigned char blend, unsigned char brightness, unsigned char contrast);
unsigned char Scaler_PipInit(SLR_PIP_MODE mode, SLR_PIP_SUB_POS pos, unsigned char blend);


/**
 * Scaler_PipGetSubBrightness
 * set the brightness level of sub channel
 *
 * @param { }
 * @return { value:0~100  }
 *
 */
//unsigned char Scaler_PipGetSubBrightness(unsigned char dataPathIdx);

/**
 * Scaler_PipSetSubBrightness
 * set the brightness level of sub channel
 *
 * @param { value:0~100}
 * @return { }
 *
 */
//void Scaler_PipSetSubBrightness(unsigned char value);

/**
 * Scaler_PipGetSubContrast
 * set the contrast level of sub channel
 *
 * @param { }
 * @return { TRUE/FALSE }
 *
 */
//unsigned char Scaler_PipGetSubContrast(unsigned char dataPathIdx);

/**
 * Scaler_PipSetSubContrast
 * set the contrast level of sub channel
 *
 * @param { value:0~100  }
 * @return { }
 *
 */
//void Scaler_PipSetSubContrast(unsigned char value);

/**
 * Scaler_ResetSource
 * reset source (external)
 *
 * @param { display: main or sub }
 * @return { void }
 *
 */
void Scaler_ResetSource(SCALER_DISP_CHANNEL display);

//========================================================================
//
//				System
//
//========================================================================
/**
 * Scaler_DeviceInit
 *  	it will open scaler device node for linux driver. need to init device before regist table and Scaler_Init(void).
 *
 */
void Scaler_DeviceInit(void);
void Scaler_DeviceUnInit(void);

/**
 * Scaler_Init
 * scaler init function
 *
 * @param {sourceInfo : source list}
 * @param {maxSource : max number of source list }
 * @param {mainInputSource: index of main source}
 * @param {subInputSource: index of sub source}
 * @return {TRUE/FALSE }
 *
 */
unsigned char Scaler_Init(StructSourceInput* sourceInfo, unsigned char maxSource, unsigned char mainInputSource, unsigned char subInputSource);

#ifdef ENABLE_SUSPEND_DVDPLAYER_TO_RAM

//typedef enum {
//  SCALER_THREAD_TIMER   = 0,
//  SCALER_THREAD_FW_TASK = 1,
//  SCALER_THREAD_NUM     = 2
//} SCALER_THREAD_INDEX_TYPE ;

/**
 * Scaler_DeInit
 * scaler de-init function
 *
 * @param {none}
 * @return {none}
 *
 */
void Scaler_DeInit(void);
void Scaler_Suspend_Fw_Task_To_Disk(void);
void Scaler_Resume_Fw_Task_From_Disk(void);

#endif //#ifdef ENABLE_SUSPEND_DVDPLAYER_TO_RAM

/**
 * Scaler_ActivateTask
 * activate the scaler task.otherwise they will not detect source
 *
 * @param { }
 * @return { }
 *
 */
void Scaler_ActivateTask(void);


void Scaler_ForceUserBg(unsigned int rgb, unsigned char Enable);

/**
 * Scaler_ForceBg
 * Force display to background
 *
 * @param { disp: Main or sub }
 * @param { reason: system flow or V-Chip }
 * @param { enable: force-to-background or not }
 * @return { none }
 *
 */
void Scaler_ForceBg(SCALER_DISP_CHANNEL disp, SLR_FORCE_BG_REASON reason, unsigned char enable);
/**
 * Scaler_ForcePanelBg
 * Force panel interface to background
 *
 * @param { enable: force-to-background or not }
 * @return { none }
 *
 */
bool Scaler_GetBgEnable(SCALER_DISP_CHANNEL disp, SLR_FORCE_BG_REASON reason);
void Scaler_ForcePanelBg(unsigned char enable);
void Scaler_SetForceBgColor(SCALER_DISP_CHANNEL disp, SLR_FORCE_BG_REASON reason, unsigned int rgb);
/**
 * Scaler_ForceDisableBg
 * Force disable background
 *
 * @param { enable: force-disable-background}
 * @return { none }
 *
 */

void Scaler_ForceDisableBg(unsigned char enable);



/**
 * Scaler_GetForceDisableBg
 * Get Force disable background status
 *
 * @param { none}
 * @return { TRUE: force-disable-background}
 *
 */
unsigned char Scaler_GetForceDisableBg(void);

//void Scaler_SetVisible(SCALER_DISP_CHANNEL disp, SLR_FORCE_BG_REASON reason, unsigned char enable);
//void Scaler_EnableNoSignalScreen(SCALER_DISP_CHANNEL disp, unsigned char enable);
//void Scaler_SetNoSignalScreenColor(unsigned char r, unsigned char g, unsigned char b);


/**
 * Scaler_SetRatio
 * change the ratio of display but don't replay scaler flow
 *
 * @param { src_idx:souce index,type: type of display ratio }
 * @return { TRUE/FALSE }
 *
 */
unsigned char Scaler_SetRatio(unsigned char src_idx, SLR_RATIO_TYPE type);

/**
 * Scaler_ChangeCapture
 * change the capture of display
 *
 * @param { void }
 * @return { TRUE/FALSE }
 *
 */

//unsigned char Scaler_ChangeCapture(void);


/**
 * Scaler_ChangeRatio
 * change the ratio of display
 *
 * @param { type: type of display ratio }
 * @return { TRUE/FALSE }
 *
 */
unsigned char Scaler_ChangeRatio(SLR_RATIO_TYPE type);
/**
 * Scaler_ChangeZoom
 * change the zoom of display
 *
 * @param { type: type of display ratio }
 * @return { TRUE/FALSE }
 *
 */

void setVideoScalingMode(int mode);

unsigned char Scaler_ChangeZoom(unsigned char value);

/**
 * Scaler_GetMdomainData
 * Get M domain data structure to process(ex:3D format detect,sent video data to wifi)
 *
 * @param { pMdomain_data: point structure of SLR_MDOMAIN_DATA }
 * @return { none}
 *
 */
void Scaler_GetMdomainData(SLR_MDOMAIN_DATA* pMdomain_data);
/**
 * Scaler_Set_VoPath_ZoomSizeToDefault
 * Set Vo path zoom size to default
 */
void Scaler_Set_VoPath_ZoomSizeToDefault_Flag(UINT8 ucEnable);
void Scaler_Set_VoPath_ZoomSizeToDefault(void);
/**
 * Scaler_OpenVOGating
 * adjust open vo gating according to the ratio of display
 *
 * @param { void}
 * @return { TRUE/FALSE }
 *
 */
unsigned char Scaler_OpenVOGating(void);

#if 1 // temp for unit task flag
unsigned char Scaler_IsUnitTest(void);
void Scaler_SetUnitTestFlag(unsigned char flag);
#endif

//pannel
unsigned char Scaler_SetBackLight(unsigned char value);
unsigned char Scaler_GetBacklight(void);

//void Scaler_SetSleepInterval(unsigned int value);				//unit:msecond,default 100ms

//enable main/sub that enter DI
//void Scaler_SetAutoMA(unsigned char mode);
//unsigned char Scaler_GetAutoMAEnableStatus(void);
#if 0
void Scaler_SetNoSignalFlag(unsigned char enable);
unsigned char Scaler_IsNoSignal(void);
#else
void Scaler_SetSignalStatus(SCALER_SIGNAL_STATUS status);
SCALER_SIGNAL_STATUS Scaler_GetSignalStatus(void);
#endif
void Scaler_SetNoSupportFlag(unsigned char enable);
unsigned char Scaler_IsNoSupport(void);
unsigned char Scaler_IsFreeze(void);
void Scaler_ChannelPlayFreeze(unsigned char mode);
unsigned char Scaler_Get_During_Power_On_EyeGuard_Adjust(SLR_EYE_GUARD_ADJUST_INDEX index);
void Scaler_Set_Brightness_During_Power_On_EyeGuard(SLR_EYE_GUARD_BRIGHTNESS_INDEX index, unsigned short value);
void Scaler_Set_Contrast_During_Power_On_EyeGuard(SLR_EYE_GUARD_CONTRAST_INDEX index, unsigned char value);
void Scaler_PowerOnOff_EyeGuard_Mode(SLR_POWER_ON_OFF_EYE_GUARD_MODE mode, unsigned char ucEnable, unsigned char ucPowerOn);
void Scaler_Set_Keep_In_BootUp_Mode_flag(unsigned char flag);
bool Scaler_Get_Keep_In_BootUp_Mode_flag(void);
void Scaler_DispWindowChange(StructRect m_setdispwin);
void Scaler_SetVideoWindowFirst(StructRect m_setdispwin);


//=======not used========================================================
unsigned char Scaler_GetHue(void);

void Scaler_SetHue(unsigned char value);					//range 0~100

unsigned char Scaler_GetSaturation(void);

void Scaler_SetSaturation(unsigned char value);				//range 0~100

unsigned char Scaler_GetSharpness(void);

void Scaler_SetSharpness(unsigned char value);				//range 0~100


//========================================================================
//
//				Video
//
//========================================================================
//USER: Vincent_Lee  DATE: 2010/10/12  TODO: Add 3 mode(still, optimize, enhance)
unsigned short Scaler_GetMAG_H_Region_Start(void);
unsigned short Scaler_GetMAG_H_Region_End(void);
unsigned short Scaler_GetMAG_H_Region_Width(void);
unsigned short Scaler_GetMAG_V_Region_Start(void);
unsigned short Scaler_GetMAG_V_Region_End(void);
unsigned short Scaler_GetMAG_V_Region_Len(void);

void Scaler_MagicSaturation(unsigned char display, unsigned char MagicMode);		//USER: Vincent_Lee  DATE: 2010/10/12  TODO: Add 3 mode(still, optimize, enhance)
void Scaler_MoveMagicPictureForStill(unsigned int timerId, void* msg);	//USER: Vincent_Lee  DATE: 2010/10/12  TODO: Add 3 mode(still, optimize, enhance)
void Scaler_MoveMagicPictureForDynamic(unsigned int timerId, void* msg);
void Scaler_MoveMagicPicture(unsigned int timerId, void* msg);
unsigned char Scaler_RedoMAG(unsigned int timerId, void* msg);
SLR_MAGIC_TYPE Scaler_GetMagicPicture(void);
//void Scaler_SetMagicPicture(SLR_MAGIC_TYPE type);
unsigned char SignalUnstableDisableMagicPic(void);

//========================================================================
//
//				VGA
//
//========================================================================
unsigned char Scaler_PreGetVPosition(unsigned char value);

unsigned char Scaler_Get_Zoom_In_Out_Enable(void);

unsigned char Scaler_Get_HVSizeAdjustEnable(void);
void Scaler_SetHSizeValue(unsigned char ucValue, unsigned char Apply);
void Scaler_SetVSizeValue(unsigned char ucValue, unsigned char Apply);

#ifdef CONFIG_ENABLE_MODIFY_SIZE_FUNCTION
unsigned char Scaler_Get_CalculateHVSize(unsigned char* H_size, unsigned char* V_size);
#else //#ifdef CONFIG_ENABLE_MODIFY_SIZE_FUNCTION
unsigned char Scaler_Get_SourceByIndex(unsigned char srcIndex);
unsigned char Scaler_Get_HV_Size_MiddleValue(unsigned char srcIndex, int *hsize, int *vsize );
unsigned char Scaler_Get_CalculateHVSize(unsigned char* H_size, unsigned char* V_size);

#endif //#ifdef CONFIG_ENABLE_MODIFY_SIZE_FUNCTION

unsigned char Scaler_Set_HVSize_ToDefault(void);
void VgaAutoInitHVSize(void);
void Scaler_Set_Enter_Zoom_MiddleValue_100_Condition_Flag(unsigned char ucFlag);
unsigned char Scaler_Get_Enter_Zoom_MiddleValue_100_Condition_Flag(void);
unsigned char Scaler_Enter_Zoom_MiddleValue_100_Condition(void);

unsigned char Scaler_GetHSize(void);
unsigned char Scaler_GetVSize(void);
unsigned char Scaler_GetPhase(void);

unsigned char Scaler_GetAclkEnable(void);
void Scaler_SetAclkEnable(unsigned char ucEnable);
unsigned char Scaler_GetClock(void);
void Scaler_SetVGAResetFlag(bool reset_flag);
unsigned char Scaler_GetHDMIDisplayRange(void);
unsigned char Scaler_GetVGACurMode(void);
void Scaler_InitVGAModeInfo(unsigned char mode);

#ifdef CONFIG_MPIXEL_SHIFT
void Scaler_SetVMemPos(int value);
#endif
unsigned char Scaler_GetHPosMoveFactor(void);
void Scaler_SetHPosMoveFactor(unsigned char factor);
unsigned char Scaler_GetVPosMoveFactor(void);
void Scaler_SetVPosMoveFactor(unsigned char factor);
//void Scaler_SetHPosition(unsigned char value);			//range 0~100
//void Scaler_SetVPosition(unsigned char value);			//range 0~100
void Scaler_SetVPosition_Skyworth(unsigned char value);			//range 0~100 //lzq 20130604 skyworth
void Scaler_SetHPositionValue(UINT8 ucValue, UINT8 Apply);
void Scaler_SetVPositionValue(unsigned char ucValue, unsigned char Apply);
void Scaler_Set_Zoom_In_Out_Enable(unsigned char ucEnable);
void Scaler_SetHSize(unsigned char value);				//range 0~10
void Scaler_SetVSize(unsigned char value);				//range 0~10
void Scaler_SetPhase(unsigned char value);				//range 0~63
void Scaler_SetClock(unsigned char value);				//range 0~100

unsigned char GetHSizeApplyValueInverse(unsigned char Hsize);  //jacklong2012/0518
unsigned char GetVSizeApplyValueInverse(unsigned char Vsize);

#if defined(TV013UI_1)||defined(BUILD_TV013_1_ATV)||(defined TV014_1)   //jacklong2012/05/16
#ifdef CONFIG_ENABLE_MODIFY_SIZE_FUNCTION
//USER:LewisLee DATE:2012/10/09
//remove it
#else //#ifdef CONFIG_ENABLE_MODIFY_SIZE_FUNCTION
#endif //#ifdef CONFIG_ENABLE_MODIFY_SIZE_FUNCTION

////===add for haier 20111210 by lichun zhao======//
unsigned char Scaler_Get2DColorManagement(void);
void Scaler_Set2DColorManagement(unsigned char mode);
//jacklong2012/07/05
unsigned char Scaler_Get3DColorManagement(unsigned char input_src_index);
void Scaler_Set3DColorManagement(unsigned char input_src_index ,unsigned char mode);
#ifdef CONFIG_ENABLE_MODIFY_SIZE_FUNCTION
//USER:LewisLee DATE:2012/10/09
//remove it
#else //#ifdef CONFIG_ENABLE_MODIFY_SIZE_FUNCTION
void VgaAutoInitHVSize(void);
void Scaler_UserHVSize_Init(void);
#endif //#ifdef CONFIG_ENABLE_MODIFY_SIZE_FUNCTION
#elif defined(BUILD_TV011_1_ATV)
void VgaAutoInitHVSize(void);
void Scaler_UserHVSize_Init(void);

#endif
void Scaler_SetEnablePositionInitFlag(UINT8 ucEnable);
void Scaler_SetPosition_Initial(void);
void Scaler_SetHDMIDisplayRange(unsigned char value);	//range 0~1
unsigned int Scaler_Get_Hist_Value(unsigned char index); // yf 0908

UINT8 Scaler_Get_SmartFit_Be_Used_At_SameTime_Flag(void);
void Scaler_Set_SmartFit_Be_Used_At_SameTime_Flag(UINT8 ucFlag);

unsigned char  Scaler_Get_VGA_Support_SOG(void);
void  Scaler_Set_VGA_Support_SOG(unsigned char ucEnable);
unsigned char  Scaler_Get_VGA_Support_Composite_Sync(void);
void  Scaler_Set_VGA_Support_Composite_Sync(unsigned char ucEnable);

unsigned char  Scaler_Get_YPbPr_Auto_Soy_Enable(void);
void  Scaler_Set_YPbPr_Auto_Soy_Enable(unsigned char ucEnable);
UINT8  Scaler_Get_VGA_Enable_Asjudt_ClampPulse_In_SS_Type(void);
void  Scaler_Set_VGA_Enable_Asjudt_ClampPulse_In_SS_Type(UINT8 ucEnable);
UINT8  Scaler_Get_VGA_Auto_Adjust_At_First_Detect_Timing(void);
void  Scaler_Set_VGA_Auto_Adjust_At_First_Detect_Timing(UINT8 ucEnable);
UINT8 Scaler_Get_ClampPosition_Check_Cnt_Factor(void);
void Scaler_Set_ClampPosition_Check_Cnt_Factor(UINT8 ucCnt);
UINT8 Scaler_Get_YPbPr_ClampPosition_Check_Cnt(void);
void Scaler_Set_YPbPr_ClampPosition_Check_Cnt(UINT8 ucCnt);
UINT8 Scaler_Get_VGA_ClampPosition_Check_Cnt(void);
void Scaler_Set_VGA_ClampPosition_Check_Cnt(UINT8 ucCnt);

UINT8  Scaler_Get_AutoSOY_Aux_Detect_Enable(void);
void  Scaler_Set_AutoSOY_Aux_Detect_Enable(UINT8 ucEnable);
UINT8  Scaler_Get_AutoSOY_Aux_Compare_Level_Min(void);
void  Scaler_Set_AutoSOY_Aux_Compare_Level_Min(UINT8 ucValue);
UINT8  Scaler_Get_AutoSOY_Aux_Max_Level_Min(void);
void  Scaler_Set_AutoSOY_Aux_Max_Level_Min(UINT8 ucValue);

//========================================================================
//
//				Auto Adjust & Color
//
//========================================================================
/**
 * Scaler_AdcAutoAdjust
 * let scaler to start auto adjust for vga/ypbpr source,when finish it will send a value to UI
 *
 * @param { }
 * @return { }
 *
 */
void Scaler_AdcAutoAdjust(void);
void Scaler_OPC_Hist_Upadte(void); // yf 0908

/**
 * Scaler_AutoColor
 * let scaler to start auto color ,when finish it will send a message to UI
 *
 * @param { }
 * @return { }
 *
 */
void Scaler_AutoColor(void);
#ifdef BUILD_TV005_1_ATV_PATCH_LIB_FROM_MP_BRANCH_SVN_434497_437131
void Scaler_SELFAWB(void);
#endif
void Scaler_SelfAWBGetTargetDiff(void);
int Scaler_GetAutoColor_info(void);
int Scaler_WaitGetAWBTargetDiff(void);

unsigned short Scaler_GetAutoColorRGain(void);
unsigned short Scaler_GetAutoColorGGain(void);
unsigned short Scaler_GetAutoColorBGain(void);
unsigned short Scaler_GetAutoColorROffset(void);
unsigned short Scaler_GetAutoColorGOffset(void);
unsigned short Scaler_GetAutoColorBOffset(void);

void Scaler_SetAutoColorRGain(unsigned short value);		//range 0~1024
void Scaler_SetAutoColorGGain(unsigned short value);		//range 0~1024
void Scaler_SetAutoColorBGain(unsigned short value);		//range 0~1024
void Scaler_SetAutoColorROffset(unsigned short value);	//range 0~1024
void Scaler_SetAutoColorGOffset(unsigned short value);	//range 0~1024
void Scaler_SetAutoColorBOffset(unsigned short value);	//range 0~1024

//NR_log
INT8 COsdCtrlGet_DNR_log(void);
void COsdCtrlSet_DNR_log(UINT16  Message);
INT8 COsdCtrlGet_RTNR_log(void);
void COsdCtrlSet_RTNR_log(UINT16  Message);
INT8 COsdCtrlGet_SNR_log(void);
void COsdCtrlSet_SNR_log(UINT16  Message);
INT8 COsdCtrlGet_INR_log(void);
void COsdCtrlSet_INR_log(UINT16  Message);
INT8 COsdCtrlGet_MPEGNR_log(void);
void COsdCtrlSet_MPEGNR_log(UINT16  Message);
//AUTO_NR_DEBUG
INT8 COsdCtrlGet_DEBUG_AUTO_NR(void);
void COsdCtrlSet_DEBUG_AUTO_NR(UINT16  Message);
INT8 COsdCtrlGet_DEBUG_VD_NOISE(void);
void COsdCtrlSet_DEBUG_VD_NOISE(UINT16  Message);
INT8 COsdCtrlGet_DEBUG_RTNR_MAD(void);
void COsdCtrlSet_DEBUG_RTNR_MAD(UINT16  Message);
INT8 COsdCtrlGet_DEBUG_HISTOGRAM_MEAN(void);
void COsdCtrlSet_DEBUG_HISTOGRAM_MEAN(UINT16  Message);
//PQ Enable_DEBUG
INT8 COsdCtrlGet_DEBUG_DCTI_EN(void);
void COsdCtrlSet_DEBUG_DCTI_EN(UINT16  Message);
INT8 COsdCtrlGet_DEBUG_SHARP_EN(void);
void COsdCtrlSet_DEBUG_SHARP_EN(UINT16  Message);
INT8 COsdCtrlGet_DEBUG_EDGE_SMOOTH_EN(void);
void COsdCtrlSet_DEBUG_EDGE_SMOOTH_EN(UINT16  Message);
INT8 COsdCtrlGet_DEBUG_DCC_EN(void);
void COsdCtrlSet_DEBUG_DCC_EN(UINT16  Message);
INT8 COsdCtrlGet_DEBUG_ICM_EN(void);
void COsdCtrlSet_DEBUG_ICM_EN(UINT16  Message);
INT8 COsdCtrlGet_DEBUG_SRGB_EN(void);
void COsdCtrlSet_DEBUG_SRGB_EN(UINT16  Message);
INT8 COsdCtrlGet_DEBUG_GAMMA_EN(void);
void COsdCtrlSet_DEBUG_GAMMA_EN(UINT16  Message);
INT8 COsdCtrlGet_DEBUG_DITHER_EN(void);
void COsdCtrlSet_DEBUG_DITHER_EN(UINT16  Message);
INT8 COsdCtrlGet_DEBUG_DCR_EN(void);
void COsdCtrlSet_DEBUG_DCR_EN(UINT16  Message);
#if defined(IS_TV05_STYLE_PICTUREMODE)
#if defined (BUILD_TV005_1_ISDB)
INT8 COsdCtrlGet_DEBUG_DCR_OFFSET(void);
void COsdCtrlSet_DEBUG_DCR_OFFSET(UINT16  Message);
#endif
INT8 COsdCtrlGet_DEBUG_MEGA_DCR_EN(void);
void COsdCtrlSet_DEBUG_MEGA_DCR_EN(UINT16  Message);
INT16 COsdCtrlGet_DEBUG_MEGA_DCR_COUNT(void);
void COsdCtrlSet_DEBUG_MEGA_DCR_COUNT(UINT16  Message);
INT8 COsdCtrlGet_DEBUG_MEGA_DCR_WEIGHT(void);
void COsdCtrlSet_DEBUG_MEGA_DCR_WEIGHT(UINT16  Message);
#endif

#if  TEST_SKIP_STATE_USE_IPG || TEST_PATTERN_GEN
void Scaler_InternalPatternGen(void);
#endif

#if TEST_IMD_BY_YPBPR_SCRIPT
void Scaler_ExternalYPbPr480i2DDI(void);
void Scaler_ExternalYPbPr480i3DDI(void);
#endif

#if TEST_UZD_BY_IPG
void Scaler_IPG1080i_FS_SXGA_2DDI(void);
#endif

#if TEST_PIP
unsigned char Scaler_TestPIPEnter(unsigned int timerId, void* msg);
unsigned char Scaler_TestPIPExit(unsigned int timerId, void* msg);

void Scaler_PIPEnter(void);
void Scaler_PIPExit(void);

unsigned char Scaler_TestPIPChangeMode(unsigned int timerId, void* msg);
unsigned char Scaler_TestPIPChangePosition(unsigned int timerId, void* msg);
unsigned char Scaler_TestPIPSwap(unsigned int timerId, void* msg);
unsigned char Scaler_TestPIPQuickSwap(unsigned int timerId, void* msg);
unsigned char Scaler_TestPIPQuickChangeMode(unsigned int timerId, void* msg);
#endif

#if TEST_PIP_BY_IPG
void Scaler_IPG_SUB(void);
#endif

#ifdef ENABLE_VGA_XTAIL_DRIVER_CURRENT_ADJ
void Scaler_VGA_XTAL_ADJ(void);
#endif

void Scaler_Stop(void);
void Scaler_Run(void);
unsigned char Scaler_IsStop(void);

#if 1 //#ifdef CONFIG_NL_VO_INFO // Notify vo_info to scaler via netlink. USER: hsliao DATE: 2010/4/20
void Scaler_VoStop(void);
void Scaler_VoRun(void);
bool Scaler_Get_VideoDisplay(void);
void Scaler_Set_VideoDisplay(bool dispFlag);
#endif

// new MV ready version control
//void Scaler_NotifyMvReady(void);

unsigned int Scaler_VbiTtxGetVirBufAddr(unsigned char bCached);

#ifdef CONFIG_VBI_TTX
void Scaler_VbiTT_DMA_DUMP(void);
#endif

unsigned int Scaler_InitVbiShareMem(void);

#ifdef CONFIG_VBI_CC
#if 1 // USER: hsliao DATE: 2010/05/20, speed up CC/VChip
#if(defined BUILD_TV005_1_ISDB)
void drvif_vbi_cgms_init( void );
UINT32 drvif_get_vbi_cgms_ID_1(void);
#endif
unsigned char Scaler_VbiCcValid_InputSignalSrc(void);
void Scaler_VbiCcInit(void);
void Scaler_VbiCcDeinit(void);
void Scaler_VbiCcPlay(unsigned char from);
unsigned char Scaler_VbiCcIsPlaying(unsigned char from);
void Scaler_VbiCcStop(unsigned char from);
#else
void Scaler_VbiCcPlay_Real(unsigned char from);
unsigned char Scaler_VbiCc_IsPlaying(void);
unsigned char Scaler_VbiCc_IsToPlay(unsigned char from);
unsigned char Scaler_VbiCcPlay(unsigned char from);
void Scaler_VbiCcStop(void);
#endif
void Scaler_VbiCcSetBuf(unsigned int* buf_addr);
unsigned int Scaler_VbiCcGetPhyBufAddr(void);
unsigned int Scaler_VbiCcGetVirBufAddr(unsigned char bCached);

#endif

#ifdef CONFIG_WSS_ENABLE
UINT16 Scaler_VbiGetWss(void);
#endif

#ifdef CONFIG_VBI_TTX
//bool Scaler_VbiTtValid_InputSignalSrc(void);
void Scaler_VbiTtInit(void);
void Scaler_VbiTtDeinit(void);
bool  Scaler_VbiTtSetGetProperty(TTX_VBI_IOCTL_PARAM *param);
bool Scaler_VbiTtGetSignalStatus(void);
int Scaler_VbiTtGetDefaultLanguage(void);
int Scaler_VbiTtGetListMode(void);
UINT16 Scaler_VbiTtGetCurCh(void);
void Scaler_VbiTtSetCurCh(UINT16 cur_ch);
#ifdef CONFIG_TTX_TOSHIBA_PATCH
void Scaler_VbiTtSendMessageToUI(UINT16 message);
#endif
#endif

void Scaler_Set_Mmap_Mode(SCALER_MMAP_MODE mode);
void Scaler_Get_Main_and_Sub_Info(stWINDOW *MainWinInfo, stWINDOW *SubWinInfo);
#if defined ENABLE_NEW_DVB_2_SC || (defined BUILD_TV005_1_ATV) || defined(BUILD_TV005_1_ATSC) || defined(BUILD_TV057_1_ATV)
unsigned char Scaler_GetMpegNR(unsigned char disp);
#elif (defined BUILD_TV010_1_ISDB)//toddy_liu add 20120608
unsigned char Scaler_GetMpegNR(unsigned char disp);
#else
unsigned char Scaler_GetMpegNR(unsigned char disp);
#endif
void Scaler_SetDCL(int value);
unsigned char Scaler_GetDCL(int *value);

#ifdef ENABLE_DCR
void Scaler_DCR(void);
//unsigned char Scaler_SetDcrMode(unsigned char enable);		// move to scalerColorLib_default
#endif
//unsigned char Scaler_SetOSDBacklight2VIP(unsigned char value);		// move to scalerColorLib_default

unsigned char Scaler_GetSpreadSpectrum(unsigned char src_idx);
void Scaler_SetSpreadSpectrum(unsigned char src_idx, unsigned char value);



unsigned char Scaler_GetSenselight(void);
unsigned char Scaler_SetSenselight(unsigned char level);


//20100329 peggy: for getting table from table list by source index
//void* Scaler_GetColorTable(VIP_TABLE_DATA_LIST* pInputArray, int iSrcIdx);
//unsigned char Scaler_RegColorTable(SCALER_REG_TABLE_TYPE type, void *ptr, int iLen);
//unsigned char Scaler_RegPicModeCallback(GET_CURRENT_PICMODE_TABLE_CB func);


unsigned char Scaler_SetVo_Vflip(unsigned char vflip_enable);
void  Scaler_Set_Vflip_Enable(unsigned char ucEnable);

void Set_OPC_DynamicControl(unsigned char Flg);
unsigned char Get_OPC_DynamicControl(void);

void Scaler_SetDisableVIP(unsigned char a_bFlag);
unsigned char Scaler_GetDisableVIP(void);
//unsigned char Scaler_WaitVDCStable(void);




//========================================================================
//
//				Misc.
//
//========================================================================



unsigned int Scaler_OPC_Get_State(void);
UINT32 Scaler_OPC_Get_Adjust_Value(void);
void Scaler_OPC_Set_MenuOnFlag(unsigned char Flg);
unsigned char Scaler_OPC_Get_MenuOnFlag(void);
void Scaler_OPC_Parameter_Initial(unsigned int diff_range_init, unsigned short pattern_ratio_init, unsigned char opc_base_init, unsigned int opc_update_timer_init);
void Scaler_OPC_Set_State(OPC_PROC_STATE curState);
void Scaler_OPC_Set_Enable(unsigned char ucEnable);
UINT32 Scaler_OPC_Get_Enable(void);
UINT32 Scaler_Get_OPC_EVENT(void);

void Scaler_OPC_Set_Adjust_Value(unsigned char opcadjust);
void Scaler_OPC_Function_Enable(unsigned char ucEnable);
//UINT8 Scaler_OPC_9Windows_detector(void);
void Scaler_OPC_Proc_9Windows(void);

#if (((defined(BUILD_TV015_1_ATV))||(defined BUILD_TV020_1_ATV))&&(defined(CONFIG_9WINDOWS_DETECT)))
UINT8 Check_9Windows_for_TPV(void);
#endif

void Scaler_Set_ForceBG_Color_At_Disable_BG_Mode_Enable(UINT8 ucEnable);
UINT8 Scaler_Get_ForceBG_Color_At_Disable_BG_Mode_Enable(void);
void Scaler_Set_ForceBG_Color_At_Disable_BG_Mode(UINT8 ucFlag);
UINT8 Scaler_Get_ForceBG_Color_At_Disable_BG_Mode(void);
void Scaler_Set_ForceBG_Color_At_Disable_BG_Mode_Color(UINT32 Color_R, UINT32 Color_G, UINT32 Color_B);
UINT32 Scaler_Get_ForceBG_Color_At_Disable_BG_Mode_Color(void);
UINT8 Scaler_Check_Enter_ForceBG_Color_At_Disable_BG_Mode(void);


void Scaler_Set_Video_Same_Path_Flag(unsigned char ucTrue);
unsigned char Scaler_Get_Video_Same_Path_Flag(void);
unsigned char Scaler_Get_AV_ColorBurst_Threshold(void);
unsigned char Scaler_Get_AV_DetectCnt_Init(void);
void Scaler_Set_YPbPr_AV_Detect_State(YPBPR_AV_PROC_STATE state);
YPBPR_AV_PROC_STATE Scaler_Get_YPbPr_AV_Detect_State(void);

void Scaler_Set_AV_YUV_Same_Path_Flag(UINT8 ucTrue);
UINT8 Scaler_Get_AV_YUV_Same_Path_Flag(void);
void Scaler_Set_AV_YUV_DetectByPin_State(YPBPR_AV_DETECT_BY_PIN_PROC_STATE state);
YPBPR_AV_DETECT_BY_PIN_PROC_STATE Scaler_Get_AV_YUV_DetectByPin_State(void);
void Scaler_Set_AV_YUV_Same_Path_YUV_PinValue(UINT8 ucValue);
void Scaler_Set_AV_YUV_Same_Path_AV_PinValue(UINT8 ucValue);
void Scaler_Set_AV_YUV_Same_Path_Search_State_Debounce_Threshold(UINT8 ucValue);
void Scaler_Set_AV_YUV_Same_Path_Active_State_Debounce_Threshold(UINT8 ucValue);
UINT8 Scaler_Check_Enter_AV_YUV_Same_Path_CheckState(SCALER_DISP_CHANNEL Display, UINT8 ucSrc);
YPBPR_AV_DETECT_BY_PIN_PROC_STATE Scaler_AV_YUV_DetectByPin_Get_Cur_State(void);
UINT8 Scaler_AV_YUV_DetectByPin_Change_InActive_State(void);

void Scaler_Set_Keep_Frc_Tracking_Framesync(unsigned char mode);
unsigned char Scaler_Get_Keep_Frc_Tracking_Framesync(void);
void Scaler_Set_FramesyncOpenFixLastLine(unsigned char ucEnable);
unsigned char Scaler_Get_FramesyncOpenFixLastLine(void);
void Scaler_Set_FramesyncOpenFixLastLineMethod0(void);
unsigned char Scaler_Get_FramesyncOpenFixLastLineMethod0(void);
void Scaler_Set_FramesyncOpenFixLastLineMethod1(void);
unsigned char Scaler_Get_FramesyncOpenFixLastLineMethod1(void);
unsigned char Scaler_Enter_FramesyncOpenFixLastLine_Condition(void);
unsigned char Scaler_Get_Framesync_FixLastLine_N_Value(void);
void Scalsr_Set_Framesync_FixLastLine_DclkOffset_Step_Method0(unsigned char ucValue);
unsigned char Scalsr_Get_Framesync_FixLastLine_DclkOffset_Step_Method0(void);
unsigned char Scalsr_Get_Framesync_FixLastLine_DclkOffset_Step_Method1(void);
//void Scaler_Set_FRC_Open_Fix_Lastline_2(unsigned char ucEnable);
//unsigned char Scaler_Get_FRC_Open_Fix_Lastline_2(void);
void Scaler_Set_FRC_Open_Fix_Lastline_2_Algo1(void);
unsigned char Scaler_Get_FRC_Open_Fix_Lastline_2_Algo1(void);
void Scaler_Set_FRC_Open_Fix_Lastline_2_Algo2(void);
unsigned char Scaler_Get_FRC_Open_Fix_Lastline_2_Algo2(void);
//unsigned char Scaler_EnterFRC_LastLine_Condition(void);
void Scaler_Set_EnterFRC_LastLine_DVTotoal_Limit_Enable_Flag(UINT8 ucEnable);
UINT8 Scaler_Get_EnterFRC_LastLine_DVTotoal_Limit_Enable_Flag(void);
void Scaler_Set_EnterFRC_LastLine_DVTotoal_Limit_Upper(UINT32 ucValue);
UINT32 Scaler_Get_EnterFRC_LastLine_DVTotoal_Limit_Upper(void);
void Scaler_Set_EnterFRC_LastLine_DVTotoal_Limit_Lower(UINT32 ucValue);
UINT32 Scaler_Get_EnterFRC_LastLine_DVTotoal_Limit_Lower(void);
void Scaler_Set_EnterFRC_LastLine_LastLinePixel_Offset(UINT16 Value);
UINT16 Scaler_Get_EnterFRC_LastLine_LastLinePixel_Offset(void);
void Scaler_Set_VO_Getting_Keep_Frc_Tracking_Framesync_Frc_To_Framesync_Flag(UINT8 ucEnable);
UINT8 Scaler_Get_VO_Getting_Keep_Frc_Tracking_Framesync_Frc_To_Framesync_Flag(void);
UINT8 Scaler_VO_Enable_Getting_Keep_Frc_Tracking_Framesync_Frc_To_Framesync(void);
void Scaler_Set_FS_Mode_Adjust_DVtotal_Flow_Enable(UINT8 ucEnable);
UINT8 Scaler_Get_FS_Mode_Adjust_DVtotal_Flow_Enable(void);
void Scaler_Set_FS_Mode_Adjust_DVTotoal_Limit_Enable_Flag(UINT8 ucEnable);
UINT8 Scaler_Get_FS_Mode_Adjust_DVTotoal_Limit_Enable_Flag(void);
void Scaler_Set_FS_Mode_Adjust_DVTotoal_Limit_Upper(UINT32 ucValue);
UINT32 Scaler_Get_FS_Mode_Adjust_DVTotoal_Limit_Upper(void);
void Scaler_Set_FS_Mode_Adjust_DVTotoal_Limit_Lower(UINT32 ucValue);
UINT32 Scaler_Get_FS_Mode_Adjust_DVTotoal_Limit_Lower(void);
void Scaler_Set_FS_Mode_BeforeDisplay_Adjust_DVTotoal_Flow_Enable(UINT8 ucEnable);
UINT8 Scaler_Get_FS_Mode_BeforeDisplay_Adjust_DVtotal_Flow_Enable(void);
void Scaler_Set_FLL_Mode_Before_Frc_To_Framesync_Flag(UINT8 ucEnable);
UINT8 Scaler_Get_FLL_Mode_Before_Frc_To_Framesync_Flag(void);
void Scaler_Set_Line4x_Mode_At_Framesync_Flag(UINT8 ucEnable);
UINT8 Scaler_Get_Line4x_Mode_At_Framesync_Flag(void);
void Scaler_Set_Line4x_Mode_At_Framesync_Delay_Ms(UINT32 DelayMs);
UINT32 Scaler_Get_Line4x_Mode_At_Framesync_Delay_Ms(void);
void Scaler_Set_DoubleDVS_Line4x_Mode_At_FRC_To_Framesync_Flag(UINT8 ucEnable);
UINT8 Scaler_Get_DoubleDVS_Line4x_Mode_At_FRC_To_Framesync_Flag(void);
void Scaler_Set_DoubleDVS_Line4x_Mode_At_FRC_To_Framesync_Delay_Ms(UINT32 DelayMs);
UINT32 Scaler_Get_DoubleDVS_Line4x_Mode_At_FRC_To_Framesync_Delay_Ms(void);
void Scaler_Set_FS_Mode_VO_Gatting_OpenFixLastLine(UINT8 ucEnable);
UINT8 Scaler_Get_FS_Mode_VO_Gatting_OpenFixLastLine(void);
void Scaler_Set_FS_Mode_VO_Gatting_Adjust_DVTotoal_Limit_Enable_Flag(UINT8 ucEnable);
UINT8 Scaler_Get_FS_Mode_VO_Gatting_Adjust_DVTotoal_Limit_Enable_Flag(void);
void Scaler_Set_FS_Mode_VO_Gatting_Adjust_DVTotoal_Limit_Upper(UINT32 ucValue);
UINT32 Scaler_Get_FS_Mode_VO_Gatting_Adjust_DVTotoal_Limit_Upper(void);
void Scaler_Set_FS_Mode_VO_Gatting_Adjust_DVTotoal_Limit_Lower(UINT32 ucValue);
UINT32 Scaler_Get_FS_Mode_VO_Gatting_Adjust_DVTotoal_Limit_Lower(void);
UINT8 Scaler_Get_FS_Mode_VO_Gatting_FixLastLine_N_Value(void);

void Scaler_Set_FixLastLine_DVTotoal_Limit_ByVfreq_Enable_Flag(UINT8 ucEnable);
UINT8 Scaler_Get_FixLastLine_DVTotoal_Limit_ByVfreq_Enable_Flag(void);
UINT32 Scaler_Get_FixLastLine_DVTotoal_Limit_ByVfreq_Typical(void);
UINT32 Scaler_Get_FixLastLine_DVTotoal_Limit_ByVfreq_Upper(void);
UINT32 Scaler_Get_FixLastLine_DVTotoal_Limit_ByVfreq_Lower(void);
void Scaler_Set_FixLastLine_DVTotal_Limit_60Hz_Typical(UINT32 ucValue);
UINT32 Scaler_Get_FixLastLine_DVTotal_Limit_60Hz_Typical(void);
void Scaler_Set_FixLastLine_DVTotal_Limit_60Hz_Upper(UINT32 ucValue);
UINT32 Scaler_Get_FixLastLine_DVTotal_Limit_60Hz_Upper(void);
void Scaler_Set_FixLastLine_DVTotal_Limit_60Hz_Lower(UINT32 ucValue);
UINT32 Scaler_Get_FixLastLine_DVTotal_Limit_60Hz_Lower(void);
void Scaler_Set_FixLastLine_DVTotal_Limit_50Hz_Typical(UINT32 ucValue);
UINT32 Scaler_Get_FixLastLine_DVTotal_Limit_50Hz_Typical(void);
void Scaler_Set_FixLastLine_DVTotal_Limit_50Hz_Upper(UINT32 ucValue);
UINT32 Scaler_Get_FixLastLine_DVTotal_Limit_50Hz_Upper(void);
void Scaler_Set_FixLastLine_DVTotal_Limit_50Hz_Lower(UINT32 ucValue);
UINT32 Scaler_Get_FixLastLine_DVTotal_Limit_50Hz_Lower(void);
//void Scaler_Set_FreeRun_To_FrameSync_By_HW_Enable(UINT8 ucEnable);
//UINT8 Scaler_Get_FreeRun_To_FrameSync_By_HW_Enable(void);
//void Scaler_Set_FreeRun_To_FrameSync_By_HW_SpeedUp(UINT8 ucEnable);
//UINT8 Scaler_Get_FreeRun_To_FrameSync_By_HW_SpeedUp(void);
//void Scaler_Set_FreeRun_To_FrameSync_By_HW_SpeedUp_TimeOut(UINT32 Value);
//UINT32 Scaler_Get_FreeRun_To_FrameSync_By_HW_SpeedUp_TimeOut(void);
//void Scaler_Set_FreeRun_To_FrameSync_By_HW_SpeedUp_Porch(UINT8 Value);
//UINT8 Scaler_Get_FreeRun_To_FrameSync_By_HW_SpeedUp_Porch(void);
void Scaler_Set_FreeRun_To_FrameSync_By_HW_SpeedUp_DVtotalOffset(UINT8 Value);
UINT8 Scaler_Get_FreeRun_To_FrameSync_By_HW_SpeedUp_DVtotalOffset(void);
void Scaler_Set_FreeRun_To_FrameSync_By_HW_SpeedUp_ByDVtotal(UINT8 ucEnable);
UINT8 Scaler_Get_FreeRun_To_FrameSync_By_HW_SpeedUp_ByDVtotal(void);
void Scaler_Set_FreeRun_To_FrameSync_By_HW_SpeedUp_ByMcode(UINT8 ucEnable);
UINT8 Scaler_Get_FreeRun_To_FrameSync_By_HW_SpeedUp_ByMcode(void);
void Scaler_Set_FreeRun_To_FrameSync_By_HW_SpeedUp_ByPorch(UINT8 ucEnable);
UINT8 Scaler_Get_FreeRun_To_FrameSync_By_HW_SpeedUp_ByPorch(void);
void Scaler_Set_FreeRun_To_FrameSync_By_HW_SpeedUp_ByMcode_HW_CTRL(UINT8 ucEnable);
UINT8 Scaler_Get_FreeRun_To_FrameSync_By_HW_SpeedUp_ByMcode_HW_CTRL(void);
//void Scaler_Set_FreeRun_To_FrameSync_By_HW_LineBufferMode_Enable(UINT8 ucEnable);
//UINT8 Scaler_Get_FreeRun_To_FrameSync_By_HW_LineBufferMode_Enable(void);
//void Scaler_Set_FreeRun_To_FrameSync_By_HW_LineBufferMode_SpeedUp_TimeOut(UINT32 Value);
//UINT32 Scaler_Get_FreeRun_To_FrameSync_By_HW_LineBufferMode_SpeedUp_TimeOut(void);
void Scaler_Set_FreeRun_To_FrameSync_By_HW_FastMode(UINT32 Value);
UINT32 Scaler_Get_FreeRun_To_FrameSync_By_HW_FastMode(void);
void Scaler_Set_FreeRun_To_FrameSync_By_HW_WaitLock_TimeOut(UINT32 Value);
UINT32 Scaler_Get_FreeRun_To_FrameSync_By_HW_WaitLock_TimeOut(void);
void Scaler_Set_FreeRun_To_FrameSync_By_HW_LineBufferMode_WaitLock_TimeOut(UINT32 Value);
UINT32 Scaler_Get_FreeRun_To_FrameSync_By_HW_LineBufferMode_WaitLock_TimeOut(void);
void Scaler_Set_DoubleDVS_FreeRun_To_FrameSync_By_HW_Enable(UINT8 ucEnable);
UINT8 Scaler_Get_DoubleDVS_FreeRun_To_FrameSync_By_HW_Enable(void);
void Scaler_Set_DoubleDVS_FreeRun_To_FrameSync_By_HW_WaitLock_TimeOut(UINT32 Value);
UINT32 Scaler_Get_DoubleDVS_FreeRun_To_FrameSync_By_HW_WaitLock_TimeOut(void);
void Scaler_Set_FreeRun_To_FrameSync_By_HW_Delay(UINT32 delay);
UINT32 Scaler_Get_FreeRun_To_FrameSync_By_HW_Delay(void);
void Scaler_Set_FreeRun_To_FrameSync_By_HW_Exit_At_Fail(UINT32 Enable);
UINT32 Scaler_Get_FreeRun_To_FrameSync_By_HW_Exit_At_Fail(void);

void Scaler_Set_Force_HD_Resolution_Go_Data_FrameSync_Enable(UINT8 ucEnable);
UINT8 Scaler_Get_Force_HD_Resolution_Go_Data_FrameSync_Enable(void);

void Scaler_Set_New_FLL_Alog_With_FixDclk(UINT8 bEnable);
UINT8 Scaler_Get_New_FLL_Alog_With_FixDclk(void);
void Scaler_Set_3D_FramePacking_Mode_Run_Framesync_Enable(UINT8 ucEnable);
UINT8 Scaler_Get_3D_FramePacking_Mode_Run_Framesync_Enable(void);
UINT8 Scaler_3D_FramePacking_Mode_Run_Framesync_Action(UINT8 ucEnter);

UINT32 Scaler_Get_DoubleDVS_NoCalculate_DH_total(UINT8 display);
UINT32 Scaler_Get_DoubleDVS_NoCalculate_DV_total(UINT8 display);
UINT32 Scaler_Get_DoubleDVS_NoCalculate_LastLine_Pixel(UINT8 display);
UINT32 Scaler_Get_DoubleDVS_NoCalculate_N_Value(UINT8 display);

void Scaler_Set_SetFramesync_Later_flag(unsigned char flag);
unsigned char Scaler_Get_SetFramesync_Later(void);
void Scaler_Set_SetDvtotal_Slowly_flag(unsigned char flag);
unsigned char Scaler_Get_SetDvtotal_Slowly_flag(void);
void Scaler_Set_SetDvtotal_Later_flag(unsigned char flag);
unsigned char Scaler_Get_SetDVtotal_Later(void);
void Scaler_Set_SetDPLL_M_Slowly_flag(unsigned char flag);
unsigned char Scaler_Get_SetDPLL_M_Slowly_flag(void);
void Scaler_Set_SetDPLL_M_Later_flag(unsigned char flag);
unsigned char Scaler_Get_SetDPLL_M_Later(void);
void Scaler_Set_Keep_In_FRC_Mode_flag(unsigned char flag);
unsigned char Scaler_Keep_FRC_Mode(void);
UINT8 Scaler_Get_Customer_Force_FRC_Mode(UINT8 InputSrc);
void Scaler_Set_SetDisplayTiming_Later_flag(UINT8 flag);
UINT8 Scaler_Get_SetDisplayTiming_Later(void);

unsigned char Scaler_Get_YPbPr_Phase(unsigned char Mode_Curr);
void Scaler_Set_YPbPr_Phase(unsigned char Mode_Curr, unsigned char ucPhase);
void Scaler_Set_YPbPr_AutoPhase_Flag(unsigned char ucFalg);
UINT8 Scaler_Get_YPbPr_HW_Detect_JumpPhase_Enable(void);
void Scaler_Set_YPbPr_HW_Detect_JumpPhase_Enable(UINT8 ucEnable);
UINT8 Scaler_Get_YPbPr_HW_JumpPhase_Detect_Flag(void);
void Scaler_Set_YPbPr_HW_JumpPhase_Detect_Flag(UINT8 ucFalg);
UINT8 Scaler_Get_YPbPr_HW_JumpPhase_Detect_Counter(void);
void Scaler_Set_YPbPr_HW_JumpPhase_Detect_Counter(UINT8 ucCounter);
UINT8 Scaler_Get_YPbPr_HW_JumpPhase_Detect_Times(void);
void Scaler_Set_YPbPr_HW_JumpPhase_Detect_Times(UINT8 ucTimes);


//unsigned char drvif_color_regDCCSkinToneTable(unsigned int *ptr);   //20100921 added by Leo Chen

unsigned char drvif_color_regDnrLevelTable(unsigned char *ptr);   //20100921 added by Leo Chen
extern unsigned char   *DNR_LEVEL_TABLE;    //20101012 added by Leo Chen

unsigned int drvif_color_regSR_INIT_TABLE(unsigned int *ptr);
extern unsigned int      *SR_INIT_TABLE;

unsigned char drvif_color_DCRTable(UINT8 *ptr);   //20101111 added by Leo Chen

unsigned char drvif_color_regdbDCCHistoTable(unsigned int *ptr);
unsigned char drvif_color_regdbDCCCurveTable(unsigned int *ptr);
#ifdef RTICE2AP_DEBUG_TOOL_ENABLE
unsigned char fwif_color_access_DisplayInfoTable(unsigned int *ptr);
unsigned char fwif_color_access_DisplayInfo(unsigned char display);
#endif


unsigned char Scaler_Get_YPbPr_Position_Adjust_Enable(void);
void Scaler_Set_YPbPr_Position_Adjust_Enable(unsigned char ucEnable);
unsigned char Scaler_Get_YPbPr_H_Position_Adjust_Max(void);
void Scaler_Set_YPbPr_H_Position_Adjust_Max(unsigned char ucMax);
unsigned char Scaler_Get_YPbPr_H_Position_Adjust_Min(void);
void Scaler_Set_YPbPr_H_Position_Adjust_Min(unsigned char ucMin);
unsigned char Scaler_Get_YPbPr_V_Position_Adjust_Max(void);
void Scaler_Set_YPbPr_V_Position_Adjust_Max(unsigned char ucMax);
unsigned char Scaler_Get_YPbPr_V_Position_Adjust_Min(void);
void Scaler_Set_YPbPr_V_Position_Adjust_Min(unsigned char ucMin);
unsigned char Scaler_Get_TV_Position_Adjust_Enable(void);
void Scaler_Set_TV_Position_Adjust_Enable(unsigned char ucEnable);
unsigned char Scaler_Get_TV_H_Position_Adjust_Max(void);
void Scaler_Set_TV_H_Position_Adjust_Max(unsigned char ucMax);
unsigned char Scaler_Get_TV_H_Position_Adjust_Min(void);
void Scaler_Set_TV_H_Position_Adjust_Min(unsigned char ucMin);
unsigned char Scaler_Get_TV_V_Position_Adjust_Max(void);
void Scaler_Set_TV_V_Position_Adjust_Max(unsigned char ucMax);
unsigned char Scaler_Get_TV_V_Position_Adjust_Min(void);
void Scaler_Set_TV_V_Position_Adjust_Min(unsigned char ucMin);
unsigned char Scaler_Get_CVBS_Position_Adjust_Enable(void);
void Scaler_Set_CVBS_Position_Adjust_Enable(unsigned char ucEnable);
unsigned char Scaler_Get_CVBS_H_Position_Adjust_Max(void);
void Scaler_Set_CVBS_H_Position_Adjust_Max(unsigned char ucMax);
unsigned char Scaler_Get_CVBS_H_Position_Adjust_Min(void);
void Scaler_Set_CVBS_H_Position_Adjust_Min(unsigned char ucMin);
unsigned char Scaler_Get_CVBS_V_Position_Adjust_Max(void);
void Scaler_Set_CVBS_V_Position_Adjust_Max(unsigned char ucMax);
unsigned char Scaler_Get_CVBS_V_Position_Adjust_Min(void);
void Scaler_Set_CVBS_V_Position_Adjust_Min(unsigned char ucMin);
unsigned char Scaler_Get_SV_Position_Adjust_Enable(void);
void Scaler_Set_SV_Position_Adjust_Enable(unsigned char ucEnable);
unsigned char Scaler_Get_SV_H_Position_Adjust_Max(void);
void Scaler_Set_SV_H_Position_Adjust_Max(unsigned char ucMax);
unsigned char Scaler_Get_SV_H_Position_Adjust_Min(void);
void Scaler_Set_SV_H_Position_Adjust_Min(unsigned char ucMin);
unsigned char Scaler_Get_SV_V_Position_Adjust_Max(void);
void Scaler_Set_SV_V_Position_Adjust_Max(unsigned char ucMax);
unsigned char Scaler_Get_SV_V_Position_Adjust_Min(void);
void Scaler_Set_SV_V_Position_Adjust_Min(unsigned char ucMin);
unsigned char Scaler_Get_HDMI_Position_Adjust_Enable(void);
void Scaler_Set_HDMI_Position_Adjust_Enable(unsigned char ucEnable);
unsigned char Scaler_Get_HDMI_H_Position_Adjust_Max(void);
void Scaler_Set_HDMI_H_Position_Adjust_Max(unsigned char ucMax);
unsigned char Scaler_Get_HDMI_H_Position_Adjust_Min(void);
void Scaler_Set_HDMI_H_Position_Adjust_Min(unsigned char ucMin);
unsigned char Scaler_Get_HDMI_V_Position_Adjust_Max(void);
void Scaler_Set_HDMI_V_Position_Adjust_Max(unsigned char ucMax);
unsigned char Scaler_Get_HDMI_V_Position_Adjust_Min(void);
void Scaler_Set_HDMI_V_Position_Adjust_Min(unsigned char ucMin);
unsigned char Scaler_Get_Enable_Adjust_Position_Src(void);
unsigned char  Scaler_Get_Adjust_H_Position_Move_Tolerance(void);
unsigned char  Scaler_Get_Adjust_V_Position_Move_Tolerance(void);

unsigned char  Scaler_Get_VGA_Support_SOG(void);
void  Scaler_Set_VGA_Support_SOG(unsigned char ucEnable);
unsigned char  Scaler_Get_VGA_Support_Composite_Sync(void);
void  Scaler_Set_VGA_Support_Composite_Sync(unsigned char ucEnable);

unsigned char  Scaler_Get_YPbPr_Auto_Soy_Enable(void);
void  Scaler_Set_YPbPr_Auto_Soy_Enable(unsigned char ucEnable);

void  Scaler_DDC_CI_Initial(void);
void  Scaler_DDC_CI_ModuleSwap(void);

void  Scaler_DDC_UART_Swap_Enable(unsigned char ucEnable);
void  Scaler_VGA_DDC_UART_Swap_Enable(unsigned char ucEnable);
void  Scaler_HDMI_DDC_UART_Swap_Enable(unsigned char ucEnable);
void  Scaler_DDC_UART_Swap_Function(UART_DDC_SEL ucSel);
void  Scaler_VGA_DDC_UART_Swap_Function(UART_DDC_SEL ucSel);
void  Scaler_HDMI_DDC_UART_Swap_Function(unsigned short src_index, UART_DDC_SEL ucSel);

void Scaler_Set_DisplayRatio_Switch_SpeedUp(unsigned char ucEnable);
unsigned char Scaler_Get_DisplayRatio_Switch_SpeedUp(void);

#if defined(TV003_ADTV)
//===========wallpaper=S=======
void Scaler_Set_IsInPhotoFrame(bool value);
bool Scaler_Get_IsInPhotoFrame(void);
//======
#endif

void Scaler_Set_FRC_Open_Fix_Lastline_2_During_Set_Aspect(unsigned char ucEnable);
unsigned char Scaler_Get_FRC_Open_Fix_Lastline_2_During_Set_Aspect(void);
void Scaler_Set_DisplayRatio_Change_Flag(unsigned char ucTrue);
unsigned char Scaler_Get_DisplayRatio_Change_Flag(void);
void Scaler_Set_DisplayRatio_Run_SearchState_Flag(unsigned char ucFlag);
unsigned char Scaler_Get_DisplayRatio_Run_SearchState_Flag(void);
void Scaler_Set_Vflip_FRC_Style(unsigned char ucStyle);
unsigned char Scaler_Get_Vflip_FRC_Style(void);
unsigned char Scaler_Get_Default_Vflip_FRC_Style(void);

void Scaler_Set_3Buffer_NewRuleFlag(UINT8 ucEnable);
UINT8 Scaler_Get_3Buffer_NewRuleFlag(void);
UINT8 Scaler_Set_Enable_3Buffer_NewRuleCondition(SCALER_DISP_CHANNEL ucDisplay, UINT8 ucSourceType);
UINT8 Scaler_Get_Enable_3Buffer_NewRuleCondition(void);

void Scaler_Set_3D_Mode_3Buffer_SW_Switch_Enable(UINT8 ucEnable);
UINT8 Scaler_Get_3D_Mode_3Buffer_SW_Switch_Enable(void);
UINT8 Scaler_Set_Enable_3D_Mode_3Buffer_SW_Switch_Condition(SCALER_DISP_CHANNEL ucDisplay, UINT8 ucSourceType);
UINT8 Scaler_Get_Enable_3D_Mode_3Buffer_SW_Switch_Condition(void);

void Scaler_Set_Zoom_H_Middle_Value(ZOOM_INIT_INFO *zinit);
void Scaler_Set_Zoom_V_Middle_Value(ZOOM_INIT_INFO *zinit);
void Scaler_Set_Zoom_H_Step_Value(ZOOM_INIT_INFO *zinit);
void Scaler_Set_Zoom_V_Step_Value(ZOOM_INIT_INFO *zinit);
unsigned char Scaler_Get_Vflip_Enable(void);

void Scaler_Set_EdgeSmooth_Enable_Flag(unsigned char ucEnable);
unsigned char Scaler_Get_EdgeSmooth_Enable_Flag(void);

unsigned char xDumpADCRawData(unsigned int timerId, void* msg);
//void xDumpVDRawData(unsigned int Length);
//void xDumpIFDRawData(unsigned int Length);

void Scaler_Set_Watching_EyeGuard_Delay_Mode(UINT8 ucEnable);
UINT8 Scaler_Get_Watching_EyeGuard_Delay_Mode(void);
UINT8 Scaler_Check_Is_ATV_SignalReady(void);
void Scaler_Set2Dcvt3D_Disable(void);
void Scaler_Set2DCvt3D_Strength(unsigned int value);
unsigned int Scaler_Get2DCvt3D_Strength(void);
#ifndef BUILD_TV035_1
void Scaler_Set2DCvt3D_Depth(char value);
char Scaler_Get2DCvt3D_Depth(void);
#endif
void Scaler_Set2Dcvt3D_Shift_direcetion(bool mode);
bool Scaler_Get2Dcvt3D_Shift_direcetion(void);
char Scaler_Get2Dcvt3D_srcType(void);
//unsigned char Scaler_Get2Dcvt3D_Enable(void);
void Scaler_Set3DCvt2D_LR(unsigned char message);
unsigned char Scaler_Get3DCvt2D_LR(void);
void Scaler_Set3DMode_ScalerHasProcessMsgFlag(unsigned char status);
unsigned char Scaler_Get3DMode_ScalerHasProcessMsgFlag(void);
//void Scaler_Set3DMode_Attr(unsigned char message);
void Scaler_Set3DMode_Attr(SCALER_DISP_CHANNEL display, unsigned char message);
#ifdef ENABLE_SPEED_UP_SLR_DISPLAY_ON_FLOW
void Scaler_Sync3DMode_Attr(void);
bool Scaler_Is3DModeChange(void);
#endif

unsigned char Scaler_Config_4k2k_3dUi(unsigned char message);
//unsigned char Scaler_Set3DMode(unsigned char message, bool muteAudio);
unsigned char Scaler_Set3DMode(SCALER_DISP_CHANNEL display, unsigned char message, bool muteAudio);
int Scaler_Set3D_VoAutoDetect_Enable(unsigned char enable);
unsigned char Scaler_Get3D_VoAutoDetectMode(void);
unsigned char Scaler_Set3DMode_with_ChangeRatio(unsigned char message, bool muteAudio, SLR_RATIO_TYPE type);
//unsigned char Scaler_Get3DMode(void);
unsigned char Scaler_Get3DMode(SCALER_DISP_CHANNEL display);
void Scaler_Set3D_Reset3DMode_Flag(unsigned char bEnable);
unsigned char Scaler_Get3D_Reset3DMode_Flag(void);
unsigned char Scaler_Get3DLRSequence(void);
unsigned char Scaler_Set3DLRSwap(unsigned char message);
void Scaler_Set3D_Depth(char value);
char Scaler_Get3D_Depth(void);
void Scaler_Set3D_OSD_enable(bool mode);
bool Scaler_Get3D_OSD_enable(void);
void Scaler_Set3D_OSD_direcetion(bool mode);
bool Scaler_Get3D_OSD_direcetion(void);
void Scaler_Set3D_OSD_Depth(int offset);
int Scaler_Get3D_OSD_Depth(void);
char Scaler_Get3D_IsSupport3D(unsigned char is2Dcvt3D, unsigned char uc3DType);
void Scaler_ForceSupport3D(unsigned char value);
unsigned char Scaler_GetHDMI3D_VOInfo(void);
void Scaler_Set_3D_Change_Flag(UINT8 ucTrue);
UINT8 Scaler_Get_3D_Change_Flag(void);
void Scaler_3D_Mode_Release(SCALER_DISP_CHANNEL Display);

void Scaler_Watching_EyeGuard_Enable(UINT8 ucEnable);

// [3D] MacArthur scaler 3D verify
unsigned char Scaler_Is_Mac3D_Verify_Enabled(void);
#if 0 // forGumpDemo
typedef enum GUMP_DEMO_MODE{
	GUMP_DEMO_MODE_NONE, // unknown
	GUMP_DEMO_MODE_ORIG,
	GUMP_DEMO_MODE_L1R1,
	GUMP_DEMO_MODE_L1R2,
	GUMP_DEMO_MODE_L2R1,
	GUMP_DEMO_MODE_L2R2,
	GUMP_DEMO_MODE_LR_PQ_IMPROVE,
	GUMP_DEMO_MODE_NUM,
}GUMP_DEMO_MODE_T;
void Scaler_Set3D_for_GumpDemo(unsigned char algo);
unsigned char Scaler_Get3D_for_GumpDemo(void);
unsigned char Scaler_Get3D_for_GumpDemo_isScaleDown(void);
unsigned char Scaler_Get3D_for_GumpDemo_isPQImprove(void);
#endif

//void Scaler_ForceUserBg(unsigned int rgb, unsigned char Enable);
/**
 * Scaler_ForceDisableUseMemory
 * Use for Netfix application to reduce memory use
 *
 * @param { none}
 * @return { TRUE: force-disable-Use memory}
 *
 */
void Scaler_ForceDisableUseMemory(unsigned char enable);
unsigned char Scaler_GetForceDisableUseMemory(void);

unsigned int Scaler_InitRPCShareMem(void);
void Scaler_FreeRPCShareMem(void);
long Scaler_SendRPC(unsigned int a_ulCmd, unsigned long a_ulValue, unsigned char a_ucValueOnly);

UINT32 Scaler_GetShareMemVirAddr(unsigned int a_ulCmd);

UINT32 Scaler_ChangeUINT32Endian(UINT32 a_ulLittleIndian);
UINT16 Scaler_ChangeUINT16Endian(UINT16 a_usLittleEndian);
#ifdef	CONFIG_ENABLE_SPEED_UP
void Scaler_DoHDMIInitial(void);
#endif
//[mark by crixus-mac3 linux based]HRESULT * VIDEO_RPC_ToSystem_SendScalerMsg_0_svc(VIDEO_RPC_SCALER_MESSAGE *a_ptScalerMsg, RPC_STRUCT *rpc, HRESULT *result);

void Scaler_Set_TV_FixDclk_Flag(unsigned char ucEnable);
unsigned char Scaler_Get_TV_FixDclk_Flag(void);
void Scaler_Set_First_Set_TV_Dclk_Flag(unsigned char ucFlag);
unsigned char Scaler_Get_First_Set_TV_Dclk_Flag(void);

void Scaler_Set_ATV_VDC_NoiseLevel_Threshold(UINT8 ucLevel);
UINT8 Scaler_Get_ATV_VDC_NoiseLevel_Threshold(void);
void Scaler_Set_ATV_WeakSignal_ChangeToFRC_Flag(UINT8 ucFlag);
UINT8 Scaler_Get_ATV_WeakSignal_ChangeToFRC_Flag(void);

void Scaler_Set_VDC_Vsync_FreeRun_Enable(UINT8 ucFlag);
UINT8 Scaler_Get_VDC_Vsync_FreeRun_Enable(void);

void Scaler_Set_DataFRC_KeepSame_Dclk_Enable(unsigned char ucEnable);
unsigned char Scaler_Get_DataFRC_KeepSame_Dclk_Enable(void);
void Scaler_Set_TV_DataFRC_KeepSame_Dclk_Enable(unsigned char ucEnable);
void Scaler_Set_VO_DataFRC_KeepSame_Dclk_Enable(unsigned char ucEnable);
void Scaler_Set_CVBS_DataFRC_KeepSame_Dclk_Enable(unsigned char ucEnable);
void Scaler_Set_SV_DataFRC_KeepSame_Dclk_Enable(unsigned char ucEnable);
void Scaler_Set_SCART_DataFRC_KeepSame_Dclk_Enable(unsigned char ucEnable);
void Scaler_Set_HDMI_DataFRC_KeepSame_Dclk_Enable(unsigned char ucEnable);
void Scaler_Set_VGA_DataFRC_KeepSame_Dclk_Enable(unsigned char ucEnable);
void Scaler_Set_YPBPR_DataFRC_KeepSame_Dclk_Enable(unsigned char ucEnable);
void Scaler_Set_DISPLAYPORT_DataFRC_KeepSame_Dclk_Enable(unsigned char ucEnable);
unsigned char Scaler_EnterFRC_Keep_Same_Dclk_Condition(unsigned char display);
unsigned int Scaler_Get_EnterFRC_Keep_Same_Dclk_Number(void);
void Scaler_Set_EnterFRC_Keep_Same_Dclk_Number(unsigned int Dclk);

unsigned char Scaler_Get_EnterFRC_LastLine_FixDclk_AdjustDVtotal_Enable_Flag(void);
void Scaler_Set_EnterFRC_LastLine_FixDclk_AdjustDVtotal_Enable_Flag(unsigned char ucEnable);
void Scaler_Set_EnterFRC_LastLine_FixDclk_DVTotoal_Limit_Enable_Flag(unsigned char ucEnable);
unsigned char Scaler_Get_EnterFRC_LastLine_FixDclk_DVTotoal_Limit_Enable_Flag(void);
void Scaler_Set_EnterFRC_LastLine_FixDclk_DVTotoal_Limit_Upper(unsigned int ucValue);
unsigned int Scaler_Get_EnterFRC_LastLine_FixDclk_DVTotoal_Limit_Upper(void);
void Scaler_Set_EnterFRC_LastLine_FixDclk_DVTotoal_Limit_Lower(unsigned int ucValue);
unsigned int Scaler_Get_EnterFRC_LastLine_FixDclk_DVTotoal_Limit_Lower(void);

void Scaler_Set_EnterFRC_FLL_Dynamic_Adjust_DHTotoal_Enable_Flag(UINT8 ucEnable);
UINT8 Scaler_Get_EnterFRC_FLL_Dynamic_Adjust_DHTotoal_Enable_Flag(void);
void Scaler_Set_EnterFRC_FLL_Dynamic_Adjust_DHTotoal_MaxValue(UINT32 MaxValue);
UINT32 Scaler_Get_EnterFRC_FLL_Dynamic_Adjust_DHTotoal_MaxValue(void);
void Scaler_Set_EnterFRC_FLL_Dynamic_Adjust_DHTotoal_MinValue(UINT32 MinValue);
UINT32 Scaler_Get_EnterFRC_FLL_Dynamic_Adjust_DHTotoal_MinValue(void);
void Scaler_Set_EnterFRC_FLL_Dynamic_Adjust_DHTotoal_FrontPorchOffset(UINT32 OffsetValue);
UINT32 Scaler_Get_EnterFRC_FLL_Dynamic_Adjust_DHTotoal_FrontPorchOffset(void);
void Scaler_Set_EnterFRC_FLL_Dynamic_Adjust_DHTotoal_CurrentValue(UINT32 CurValue);
UINT32 Scaler_Get_EnterFRC_FLL_Dynamic_Adjust_DHTotoal_CurrentValue(void);

#ifdef CONFIG_ENABLE_CUSTOMER_SETTING_IN_AP
	//move to AP
#else //#ifdef CONFIG_ENABLE_CUSTOMER_SETTING_IN_AP
void Scaler_EnterFRC_LastLine_FixDclk_DVTotoal_Limit_Enable_ApplyRule(UINT8 ucSourceType, UINT8 ucEnter);
#endif //#ifdef CONFIG_ENABLE_CUSTOMER_SETTING_IN_AP

UINT8 Scaler_Get_EnterFRC_LastLine_DclkOverRange_Compensate_Enable_Flag(void);
void Scaler_Set_EnterFRC_LastLine_DclkOverRange_Compensate_Enable_Flag(UINT8 ucEnable);
UINT8 Scaler_Get_EnterFRC_LastLine_DHtotal_Adjust_Enable_Flag(void);
void Scaler_Set_EnterFRC_LastLine_DHtotal_Adjust_Enable_Flag(UINT8 ucEnable);
UINT32 Scaler_Get_EnterFRC_LastLine_DHtotal_Adjust_Over_OffsetValue(void);
void Scaler_Set_EnterFRC_LastLine_DHtotal_Adjust_Over_OffsetValue(UINT32 Value);
UINT32 Scaler_Get_EnterFRC_LastLine_DHtotal_Adjust_Under_OffsetValue(void);
void Scaler_Set_EnterFRC_LastLine_DHtotal_Adjust_Under_OffsetValue(UINT32 Value);
UINT8 Scaler_Get_EnterFRC_FixDclk_Without_FLL(void);
void Scaler_Set_EnterFRC_FixDclk_Without_FLL(UINT8 Value);

UINT8 Scaler_Get_EnterFramesync_Counter_Threshold_FLL(void);
void Scaler_Set_EnterFramesync_Counter_Threshold_FLL(UINT8 Value);
UINT8 Scaler_Get_EnterFramesync_Counter_Threshold_Without_FLL(void);
void Scaler_Set_EnterFramesync_Counter_Threshold_Without_FLL(UINT8 Value);
UINT8 Scaler_Get_First_EnterFramesync_Counter_Threshold_Without_FLL(void);
void Scaler_Set_First_EnterFramesync_Counter_Threshold_Without_FLL(UINT8 Value);

void Scaler_Set_FrameSync_Dynamic_Adjust_DHTotoal_Enable_Flag(UINT8 ucEnable);
UINT8 Scaler_Get_FrameSync_Dynamic_Adjust_DHTotoal_Enable_Flag(void);
void Scaler_Set_FrameSync_Dynamic_Adjust_FrameBuffer_DHTotoal_MaxValue(UINT32 MaxValue);
UINT32 Scaler_Get_FrameSync_Dynamic_Adjust_FrameBuffer_DHTotoal_MaxValue(void);
void Scaler_Set_FrameSync_Dynamic_Adjust_FrameBuffer_DHTotoal_MinValue(UINT32 MinValue);
UINT32 Scaler_Get_FrameSync_Dynamic_Adjust_FrameBuffer_DHTotoal_MinValue(void);
void Scaler_Set_FrameSync_Dynamic_Adjust_LineBuffer_DHTotoal_MaxValue(UINT32 MaxValue);
UINT32 Scaler_Get_FrameSync_Dynamic_Adjust_LineBuffer_DHTotoal_MaxValue(void);
void Scaler_Set_FrameSync_Dynamic_Adjust_LineBuffer_DHTotoal_MinValue(UINT32 MinValue);
UINT32 Scaler_Get_FrameSync_Dynamic_Adjust_LineBuffer_DHTotoal_MinValue(void);
void Scaler_Set_FrameSync_Dynamic_Adjust_DHTotoal_FrontPorchOffset(UINT32 OffsetValue);
UINT32 Scaler_Get_FrameSync_Dynamic_Adjust_DHTotoal_FrontPorchOffset(void);
void Scaler_Set_FrameSync_Dynamic_Adjust_DHTotoal_CurrentValue(UINT32 CurValue);
UINT32 Scaler_Get_FrameSync_Dynamic_Adjust_DHTotoal_CurrentValue(void);

void Scaler_Set_Dynamic_Adjust_Display_DenVPos_Flag(UINT8 ucEnable);
UINT8 Scaler_Get_Dynamic_Adjust_Display_DenVPos_Flag(void);
void Scaler_Set_Dynamic_Adjust_Display_DenVPos_Start(UINT32 DenVposStart);
UINT32 Scaler_Get_Dynamic_Adjust_Display_DenVPos_Start(void);
void Scaler_Set_Dynamic_Adjust_Display_DenVPos_End(UINT32 DenVposEnd);
UINT32 Scaler_Get_Dynamic_Adjust_Display_DenVPos_End(void);
void Scaler_Set_Dynamic_Adjust_Display_DenVPos_BackPorch_Min(UINT32 BackPorch_Min);
UINT32 Scaler_Get_Dynamic_Adjust_Display_DenVPos_BackPorch_Min(void);
void Scaler_Set_Dynamic_Adjust_Display_DenVPos_FrontPorch_Min(UINT32 FrontPorch_Min);
UINT32 Scaler_Get_Dynamic_Adjust_Display_DenVPos_FrontPorch_Min(void);


UINT8 Scaler_Get_Enable_Adjust_DHtotal(void);
void Scaler_Set_Enable_Adjust_DHtotal(UINT8 ucEnable);
UINT8 Scaler_Get_DHtotal_ChangeFlag(void);
UINT32 Scaler_Get_Dynamic_DHtotal_Value(void);
void Scaler_Set_Dynamic_DHtotal_Value(SCALER_DISP_CHANNEL display);
UINT8 Scaler_Get_Enable_Adjust_DVtotal(void);
void Scaler_Set_Enable_Adjust_DVtotal(UINT8 ucEnable);
UINT8 Scaler_Get_DVtotal_ChangeFlag(void);
UINT32 Scaler_Get_Dynamic_DVtotal_Value(void);
void Scaler_Set_Dynamic_DVtotal_Value(SCALER_DISP_CHANNEL display);
void Scaler_Set_Dynamic_Display_HV_total_Value(SCALER_DISP_CHANNEL display);

UINT8 Scaler_Get3D_IsFramePacking(void);
VO_3D_MODE_TYPE Scaler_Get3D_VoMode3d(void);

void Scaler_Apply_EMI_Setting(void);
void Scaler_Customer_AspectRatio_Rule_Condition(SCALER_DISP_CHANNEL Display, UINT8 src_type, UINT16 timingIndex);
void Scaler_Customer_AspectRatio_Rule_Apply(void);

UINT8 Scaler_Get_HDMI_Video_Mode_Flag(void);
void Scaler_Set_HDMI_Video_Mode_Flag(SCALER_DISP_CHANNEL Display, UINT8 src_type, UINT16 timingIndex);

UINT8 Scaler_Get_AspectRatio_Enter_Native_Mode(void);
SLR_RATIO_TYPE Scaler_Get_Native_AspectRatio_RatioType(void);
void Scaler_Set_Enable_Native_AspectRatio_Apply(UINT8 ucEnable);
void Scaler_Enter_Native_AspectRatio_Condition(UINT8 src_type, UINT16 timingIndex);

SLR_AFD_RATIO_TYPE Scaler_Get_HDMI_AFD_Flag(void);
void Scaler_Set_HDMI_AFD_Flag(SLR_AFD_RATIO_TYPE ucAFD);
UINT8 Scaler_Get_HDMI_AFD_ModeChange_Flag(void);
void Scaler_Set_HDMI_AFD_ModeChange_Flag(UINT8 ucFlag);
SLR_RATIO_TYPE Scaler_Get_HDMI_AFD_4_3_Stretch_On_Ratio(void);
void Scaler_Set_HDMI_AFD_4_3_Stretch_On_Ratio(SLR_RATIO_TYPE ratio);
SLR_RATIO_TYPE Scaler_Get_HDMI_AFD_4_3_Stretch_Off_Ratio(void);
void Scaler_Set_HDMI_AFD_4_3_Stretch_Off_Ratio(SLR_RATIO_TYPE ratio);
SLR_RATIO_TYPE Scaler_Get_HDMI_AFD_16_9_Ratio(void);
void Scaler_Set_HDMI_AFD_16_9_Ratio(SLR_RATIO_TYPE ratio);
UINT8 Scaler_Get_HDMI_UI_Switch_AFD_Mode_Flag(void);
void Scaler_Set_HDMI_UI_Switch_AFD_Mode_Flag(UINT8 ucFlag);
UINT8 Scaler_Get_Enable_Enter_HDMI_AFD_Mode(void);
UINT8 Scaler_Check_Enable_HDMI_AFD_Mode_Apply(UINT8 ucIsPollingState, SLR_AFD_RATIO_TYPE NewRatioType);
void Scaler_Enter_HDMI_AFD_Condition(UINT8 src_type, UINT16 timingIndex);
SLR_RATIO_TYPE Scaler_Get_HDMI_AFD_RecordLastMemoryAspect(void);
void Scaler_Set_HDMI_AFD_RecordLastMemoryAspect(SLR_RATIO_TYPE LastMemoryAspect);
UINT8 Scaler_Get_HDMI_AFD_ForceReturnLastMemoryAspect(void);
void Scaler_Set_HDMI_AFD_ForceReturnLastMemoryAspect(UINT8 ucFlag);

UINT8 Scaler_Get_AspectRatio_Enter_Normal_Mode(void);
SLR_RATIO_TYPE Scaler_Get_Normal_AspectRatio_RatioType(void);
void Scaler_Set_Enable_Normal_AspectRatio_Apply(UINT8 ucEnable);
void Scaler_Enter_Normal_AspectRatio_Condition(UINT8 src_type, UINT16 timingIndex);
void Scaler_Set_HDMI_VideoPC_DisplayRatio(UINT8 src_type, UINT16 timingIndex);

UINT8 Scaler_Get_AspectRatio_Enter_DotByDot_Mode(void);
SLR_RATIO_TYPE Scaler_Get_DotByDot_AspectRatio_RatioType(void);
void Scaler_Set_Enable_DotByDot_AspectRatio_Apply(UINT8 ucEnable);
void Scaler_Enter_DotByDot_AspectRatio_Condition(UINT8 src_type, UINT16 timingIndex);

UINT8 Scaler_Get_AspectRatio_Enable_DotByDot_Exit_Mode(void);
void Scaler_Set_AspectRatio_Enable_DotByDot_Exit_Mode(UINT8 ucEnable);
UINT8 Scaler_Get_Enter_AspectRatio_DotByDot_Exit_Mode(void);
void Scaler_Set_AspectRatio_Exit_DotByDot_DisplayWidth_Min(UINT16 width);
UINT16 Scaler_Get_AspectRatio_Exit_DotByDot_DisplayWidth_Min(void);
void Scaler_Set_AspectRatio_Exit_DotByDot_InputWidth_Max(UINT16 width);
UINT16 Scaler_Get_AspectRatio_Exit_DotByDot_InputWidth_Max(void);
void Scaler_Set_AspectRatio_Exit_DotByDot_InputLength_Max(UINT16 length);
UINT16 Scaler_Get_AspectRatio_Exit_DotByDot_InputLength_Max(void);
void Scaler_Check_DotByDot_AspectRatio_Exit_Condition(UINT8 src_type, UINT16 timingIndex);

void Scaler_YPbPr_Set_onlinemeasure_extra_condition_flag(UINT8 ucEnable);
UINT8 Scaler_YPbPr_Get_onlinemeasure_extra_condition_flag(void);
void Scaler_YPbPr_Set_Enter_onlinemeasure_extra_condition(void);
UINT8 Scaler_YPbPr_Get_Enter_onlinemeasure_extra_condition(void);

void Scaler_Set_VideoNoSignal_Mute_State(SLR_NO_SIGNAL_MUTE_TYPE state);
SLR_NO_SIGNAL_MUTE_TYPE Scaler_Get_VideoNoSignal_Mute_State(void);
//[mark by crixus-mac3 linux based]BOOL Scaler_VideoNoSignal_Mute_Condition_Apply(ENUM_AUDIO_MUTE_ID id, bool bMute);
UINT8 Scaler_VideoNoSignal_Mute_Condition_Check(SLR_NO_SIGNAL_MUTE_TYPE state, UINT8 ucMute);
UINT8 Scaler_VideoNoSignal_Mute(SLR_NO_SIGNAL_MUTE_TYPE state, UINT8 ucMute);

void Scaler_Set_VGA_ADC_NoLock_WD_Flag(UINT8 ucEnable);
void Scaler_Set_YPbPr_ADC_NoLock_WD_Flag(UINT8 ucEnable);
UINT8 Scaler_Get_ADC_NoLock_WD_Enable(SCALER_DISP_CHANNEL display);
void Scaler_Set_VGA_ADC_NoLock_lock_th(UINT8 ucThreshold);
void Scaler_Set_YPbPr_ADC_NoLock_lock_th(UINT8 ucThreshold);
UINT8 Scaler_Get_ADC_NoLock_lock_th(SCALER_DISP_CHANNEL display);

void Scaler_Set_HDMI_EnableMeasure_WD_Flag(UINT8 ucEnable);
UINT8 Scaler_Get_HDMI_EnableMeasure_WD_Flag(void);

void Scaler_Set_Mdomain_Disp_SingleBuffer_Flag(UINT8 ucEnable);
UINT8 Scaler_Get_Mdomain_Disp_SingleBuffer_Flag(void);
UINT8 Scaler_Mdomain_Disp_Disable_DoubleBuffer_Condition(UINT8 ucDisplay);
void Scaler_Set_Mdomain_Disp_SingleBuffer_Disable_FLL_Flag(UINT8 ucEnable);
UINT8 Scaler_Get_Mdomain_Disp_SingleBuffer_Disable_FLL_Flag(void);
UINT8 Scaler_Mdomain_Disp_SingleBuffer_Disable_FLL_Condition(UINT8 ucDisplay);

void Scaler_Set_VO_Gatting_ChangeRatioNumberEnable(UINT8 ucEnable);
UINT8 Scaler_Get_VO_Gatting_ChangeRatioNumberEnable(void);
//void Scaler_Set_VO_Gatting_Width_Threshold(UINT32 width);
//UINT32 Scaler_Get_VO_Gatting_Width_Threshold(void);
void Scaler_Set_VO_Gatting_RatioNum_Threshold(UINT32 threshold);
UINT32 Scaler_Get_VO_Gatting_RatioNum_Threshold(void);
void Scaler_Set_VO_Gatting_RatioNum_ChangeStep(UINT32 ChangeStep);
UINT32 Scaler_Get_VO_Gatting_RatioNum_ChangeStep(void);
UINT8 Scaler_VO_Gatting_ChangeRatioNumberEnable_Condition(void);

void Scaler_PowerOnOff_EyeGuard_Mode_BG_Color(UINT8 ucReset);

void Scaler_Set_HDMI_SourceSwitch_Speed_Up_Enable(UINT8 ucEnable);
UINT8 Scaler_Get_HDMI_SourceSwitch_Speed_Up_Enable(void);
UINT8 Scaler_Enter_HDMI_SourceSwitch_Speed_Up_Condition(UINT8 channel);

void Scaler_Set_VDC_ColorStd_Chech_Debounce_Enable(UINT8 ucEnable);
UINT8 Scaler_Get_VDC_ColorStd_Chech_Debounce_Enable(void);
void Scaler_Set_VDC_ColorStd_Chech_Debounce_Threshold(UINT8 ucThreshold);
UINT8 Scaler_Get_VDC_ColorStd_Chech_Debounce_Threshold(void);

void Scaler_Set_VDC_ColorStd_Manual_Mode_Enable(UINT8 ucEnable);
UINT8 Scaler_Get_VDC_VDC_ColorStd_Manual_Mode_Enable(void);
UINT8 Scaler_VDC_ColorStd_Manual_Mode_Setting(UINT8 ucMode);

void Scaler_Set_LVDS_Converter_To_HDMI_Enable(UINT8 ucEnable);
UINT8 Scaler_Get_LVDS_Converter_To_HDMI_Enable(void);

unsigned char Scaler_Get_2D_3D_DisplayRatio_Change_Flag(void);
void Scaler_Set_2D_3D_DisplayRatio_Change_Flag(unsigned char ucTrue);

void Scaler_SetOSDSrcFinishFlag(unsigned char a_bFlag);
unsigned char Scaler_GetOSDSrcFinishFlag(void);

void Scaler_SetHwVTrackFlag(unsigned char a_ucFlag);
unsigned char Scaler_GetHwVTrackFlag(void);

void Scaler_Disable2DCvt3D(void);

void Scaler_Set3D2DFinishFlag(unsigned char a_ucFlag);
unsigned char Scaler_Get3D2DFinishFlag(void);

void Scaler_SetAutoScanFlag(unsigned char a_ucFlag);
unsigned char Scaler_GetAutoScanFlag(void);
void mScalerSetMAG(void);

void mScalerSetMAG_YUV2RGB_Init(void);
void Scaler_ReleaseMemory(void);
void Scaler_ReallocateMemory(void);
void Scaler_SetAutoScanStart(void);
void Scaler_SetAutoScanStop(void);
#if defined(BUILD_TV005_2)
INT8 Scaler_GetTempTSBGainDiff(unsigned char rgbtype);
void Scaler_SetTempTSBGainDiff(unsigned char rgbtype,INT8 value );
void Scaler_Set3DColorOnOff(bool flag);
void Scaler_SetCinemaMode(unsigned char enable);
#endif
//#if (defined BUILD_TV005_1_ATV) || (defined BUILD_TV005_1_ATSC) || (defined(BUILD_TV057_1_ATV) && defined(IS_TV05_STYLE_PICTUREMODE))

#if  defined(IS_TV05_STYLE_PICTUREMODE)
void Scaler_Set3DColorOnOff(bool flag);
void Scaler_Set3DColorMatrix(BASECOLORADJ *colortable);
INT8 Scaler_GetTempTSBGainDiff(unsigned char rgbtype);
void Scaler_SetTempTSBGainDiff(unsigned char rgbtype,INT8 value );
void Scaler_SetCinemaMode(unsigned char enable);
#endif

#if defined(TV032_1)||defined(BUILD_TV015_1_ATV) || defined(BUILD_TV015_5_ISDB)||defined (TV014_1)||(defined TV014_2)||(defined BUILD_TV020_1_ATV)
void Scaler_OverScan_Reset_Vgip(void);	//yq_zhang 2012.04.25
//yq_zhang add for 1360 x 768 2012.06.05
UINT8 Scaler_Get_panel_is_1366x768(void);
UINT8 Scaler_Get_input_is_1360x768(void);
void Scaler_Set_1360_no_scale_to_1366(UINT8 ucEnable);
UINT8 Scaler_Get_1360_no_scale_to_1366(void);
UINT8 Scaler_do_1360_no_scale_to_1366(void);
#endif

#if  defined(BUILD_TV030_2)
unsigned char Scaler_GetFactoryColorData(FAC_COLOR_INDEX idx, FAC_COLOR_ITEM itm);
void Scaler_SetFactoryColorData(FAC_COLOR_INDEX idx, FAC_COLOR_ITEM itm, unsigned char val);
void Scaler_SetNatureLightContrast(unsigned char contrast);
unsigned char Scaler_GetNatureLightContrast(void);
void Scaler_SetNatureLightBacklight(unsigned char backlight);
unsigned char Scaler_GetNatureLightBacklight(void);
DBC_SOURCE_TYPE_E Scaler_GetNatureLightSourceType(void);
_DBC_SOURCE_STATUS_E Scaler_GetNatureLightSourceStatus(void);
UINT32 Scalers_GetNatureLightAPL(void);
#endif

UINT8 Scaler_get_VIPVersion(void);
void Scaler_set_VIPVersion(UINT8 value);

// move to scalerColorLib_default
#if 0
void Scaler_set_DCR_Enable(UINT8 value);
UINT8 Scaler_get_DCR_Enable(void);
#endif

#ifdef CONFIG_SOURCE_AUTO_SWITCH
unsigned char Scaler_SourceTimer(unsigned int timerId, void* msg);
unsigned char Scaler_SourceAutoSwitch(void);
unsigned char Scaler_SourceDetect(void);
unsigned char Scaler_Get_SourceIndex(void);

extern unsigned char g_bSourceCurrSignalFlag[_SRC_SWITCH_MAX];
extern unsigned char g_bSourcePreSignalFlag[_SRC_SWITCH_MAX];
#endif

void Scaler_GetMainBGColor(int ColorR, int ColorG, int ColorB);
void Scaler_SetMainBGColor(void);
void Scaler_Srcratio_Color(int x,int y,int w,int h,int ColorR,int ColorG,int ColorB);

void Scaler_DispWindowChange(StructRect m_setdispwin);
unsigned char Scaler_PipSetSubDisplayWindow(StructSrcRect m_setsubdispwin);
unsigned char Scaler_GetFacPatternColor(void);
void Scaler_SetFacPatternColor(unsigned char val);

#ifdef CONFIG_ENABLE_VIP_PSEUDO_RPC
/*======vip_PseudoRPC======*/
#define IOCTRL_ERR 1
//#ifndef SUCCESS
//  #define SUCCESS                   0
//#endif

#ifndef FAILED
  #define FAILED                    (-1)
#endif

/*================================== Function ===============================*/

int vip_pseudoScalerDrv_ioctl(unsigned int cmd, unsigned long arg);
long vip_PseudoRPC(unsigned int a_ulCmd, unsigned long a_ulValue, unsigned char a_ucValueOnly);

#endif	//#ifdef CONFIG_ENABLE_VIP_PSEUDO_RPC


void Scaler_Set_ATV_AutoMode_Without_Detect_ColorStd_DuringChnageCH_Enable(UINT8 ucEnable);
UINT8 Scaler_Get_ATV_AutoMode_Without_Detect_ColorStd_DuringChnageCH_Enable(void);
void Scaler_Set_ATV_AutoMode_Without_Detect_ColorStd_DuringChnageCH_NoiseLevel_Threshold(UINT8 ucLevel);
UINT8 Scaler_Get_ATV_AutoMode_Without_Detect_ColorStd_DuringChnageCH_NoiseLevel_Threshold(void);

void Scaler_Set2DCvt3D_View(INT8 value);
INT8 Scaler_Get2DCvt3D_View(void);
#if defined(BUILD_TV035_1)
void GetParam_ColorWheel(unsigned char* PercentR, unsigned char* PercentG, unsigned char* PercentB,unsigned int Pos_x,unsigned int Pos_y);
void Scaler_Set2DCvt3D_Depth(INT8 value);
INT8 Scaler_Get2DCvt3D_Depth(void);
SLR_RATIO_TYPE RatioConvertToSlrRatio(void);
void Scaler_Set_Zoom_by_Original_Ratio(void);

#endif

void Scaler_Rotate_Set(int rotate_mode,int rotate_enable);
unsigned int scaler_MaincvtSub_get_vgip2IhWidth(void);
unsigned int scaler_MaincvtSub_get_vgip2IhCount(void);
unsigned int scaler_MaincvtSub_get_vgip2IvFreq(void);
unsigned int scaler_MaincvtSub_get_vgip2IvHeight(void);
unsigned char scaler_MaincvtSub_get_vgip2SrcFrom(void);
unsigned int scaler_MaincvtSub_get_vgip2SrcInterlaced(void);
unsigned char scaler_MaincvtSub_get_vgip2SrcIndex(void);
DOUBLE_CLOCK_CTRL_STATE scaler_MaincvtSub_get_vgip2CurState(void);
unsigned char scaler_MaincvtSub_check_ignoreThroughDI(void);
unsigned char scaler_MaincvtSub_check_ignoreRTNR(void);
void scaler_MaincvtSub_set_vgip2CurState(DOUBLE_CLOCK_CTRL_STATE curCtrlState);
void scaler_MaincvtSub_set_modeEnableStatus(unsigned char modeEnableFlag);
int scaler_IMdomain_VGIP2_config(StructDisplayInfo* info);
void scaler_MaincvtSub_vo_init(void);
void Set_GOSUBandVODMA(unsigned char value);
unsigned char Get_GOSUBandVODMA(void);
unsigned int get_delayframe_number(void);
unsigned char get_delayframe_fuc(void);
void set_delayframe_buffersize(unsigned int value);
void delay_framebuffer_free(void);
unsigned int delay_framebuffer_alloc(unsigned int buffersize);

unsigned char Scaler_Video_DelayFrame(unsigned int framenum);
void framedelay_videofw_config(void);

void set_mainsubonpr_fuc(unsigned char value);
unsigned char get_mainsubonpr_fuc(void);

unsigned char get_mainsubonpr_SubSourceIDX(void);
unsigned char get_mainsubonpr_MainSourceIDX(void);

void set_MainSubonPR_curState(MAINSUB_SHOWONPR_STATUS value);
MAINSUB_SHOWONPR_STATUS get_MainSubonPR_curState(void);

unsigned int get_MainSubonPR_mainInterlace(void);
unsigned int get_MainSubonPR_mainLength(void);
unsigned int get_MainSubonPR_mainWidth(void);

unsigned int get_MainSubonPR_subWidth(void);
unsigned int get_MainSubonPR_subLength(void);
unsigned int get_MainSubonPR_subInterlace(void);

unsigned int get_MainSubonPR_displayWidth(void);
unsigned int get_MainSubonPR_displayLength(void);

void MainandSub_Save_MainPara_PR(void);
void MainandSub_Save_SubPara_PR(void);
void MainandSub_ShowOn_PRPanel(unsigned char option,unsigned char subindex,unsigned char mainindex);
void set_mainsubonpr_SubSourceIDX(unsigned char value);

void MainSub_On_PRPanel_sub_Change(unsigned char subindex);


void Scaler_FineTuneATVFreq(UINT32 a_ulFreq);
void Scaler_I3DDMA_Buffer_Dump(void);
//void  drvif_I3DDMA_set_capture(SIZE *outsize,unsigned char capformat422);

//Elsie 20131210 sync from Mac2
unsigned int drvif_color_regCoeff_by_y(unsigned int *ptr, bool sendRPC_flag);
unsigned char drvif_color_reg_AutoView_Max_Min_Table(unsigned char *ptr);

UINT8 Scaler_Get_DI_Force_2D_Enable(void);
void Scaler_Set_DI_Force_2D_Enable(UINT8 ucEnable);
UINT8 Scaler_Enter_DI_Force_2D_Condition(UINT8 ucDisplay);



//o----------------------------------------------------------------------------------------------------------------------------------------o
//o----------------------------------------------------------------------------------------------------------------------------------------o
//o----------------------------------------------------------------------------------------------------------------------------------------o
//o----------------------------------------------------------------------------------------------------------------------------------------o
//o----------------------------------------------------------------------------------------------------------------------------------------o



#if defined(BUILD_TV035_1)
void GetParam_ColorWheel(unsigned char* PercentR, unsigned char* PercentG, unsigned char* PercentB,unsigned int Pos_x,unsigned int Pos_y);
void Scaler_Set2DCvt3D_Depth(INT8 value);
INT8 Scaler_Get2DCvt3D_Depth(void);
SLR_RATIO_TYPE RatioConvertToSlrRatio(void);
void Scaler_Set_Zoom_by_Original_Ratio(void);

#endif

#if defined (TV003_ADTV)
void Scaler_Check_SDHD_DisplayRatio_TV003(UINT8 src_type, UINT16 timingIndex);
#endif

//==================================
void Scaler_Set_ATV_WeakSignal_Change_Ch_LongDelay_Enable(UINT8 ucEnable);
UINT8 Scaler_Get_ATV_WeakSignal_Change_Ch_LongDelay_Enable(void);
void Scaler_Set_ATV_GoodSignal_Change_Ch_VDC_NoiseLevel_Threshold(UINT32 NoiseLevel);
UINT32 Scaler_Get_ATV_GoodSignal_Change_Ch_VDC_NoiseLevel_Threshold(void);
void Scaler_Set_ATV_WeakSignal_Change_Ch_VDC_NoiseLevel_Threshold(UINT32 NoiseLevel);
UINT32 Scaler_Get_ATV_WeakSignal_Change_Ch_VDC_NoiseLevel_Threshold(void);
void Scaler_Set_ATV_WeakSignal_Change_Ch_Delay_Ms(UINT32 DelayTime);
UINT32 Scaler_Get_ATV_WeakSignal_Change_Ch_Delay_Ms(void);

void Scaler_Set_DTV_CH_Change_CheckTunerLock_Enable(UINT8 ucEnable);
UINT8 Scaler_Get_DTV_CH_Change_CheckTunerLock_Enable(void);

void Scaler_Set_ATV_VD_Lock_Cnt_Threshold(UINT8 Threshold);
UINT8 Scaler_Get_ATV_VD_Lock_Cnt_Threshold(void);
void Scaler_Set_ATV_VD_Lock_Check_Max(UINT8 value);
UINT8 Scaler_Get_ATV_VD_Lock_Check_Max(void);


void Scaler_Set_ATV_AudioUnMute_Late_DuringCHangeCH_Enable(UINT8 ucEnable);
UINT8 Scaler_Get_ATV_AudioUnMute_Late_DuringCHangeCH_Enable(void);
void Scaler_Set_ATV_AudioUnMute_Late_DuringCHangeCH_Flag(UINT8 ucFlag);
UINT8 Scaler_Get_ATV_AudioUnMute_Late_DuringCHangeCH_Flag(void);
#if defined(IS_MACARTHUR3) && defined(TV032_1)//czl,20131209,sync from 2947
	void Set_AdjustVpos_flag(UINT8 enable);
	UINT8  Get_AdjustVpos_flag_status(void);
#endif
//#if defined (IS_MACARTHUR3)
void vo_se_scaling_ctrl(int enable);
void smooth_toggle_set_vo_timing_change(unsigned char enable);
//#endif
long Scaler_VO_Set_VoForce422_enable(unsigned char bEnable);

void ap_fac_White_window_on( UINT16 value);
void ap_fac_White_window_off( UINT16 value);
UINT8 ap_GetWhiteWindowState(void);

#ifdef CONFIG_ENABLE_SE_ROTATE_M_DOMAIN_BLOCK_MODE
void scaler_Rotate_VI_init_send_rpc(void);
void Set_Rotate_Mode(ROTATE_MODE_LIST value);
ROTATE_MODE_LIST Get_Rotate_Mode(void);
void Set_rotate_function(unsigned char enable);
unsigned char Get_rotate_function(void);
void set_rotate_curState(MAINSUB_ROTATE_STATUS value);
MAINSUB_ROTATE_STATUS get_rotate_curState(void);
void VI_close(void);
void Scaler_HDMI_Rotate(char rotateon, ROTATE_MODE_LIST mode, unsigned char srcIdx);
#endif




#ifdef __cplusplus
}
#endif

#endif // __SCALER_LIB_H__
