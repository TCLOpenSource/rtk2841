#ifndef __SCALER_STRUCT_H__
#define __SCALER_STRUCT_H__

#ifdef __cplusplus
extern "C" {
#endif


#include <linux/kernel.h>
#include <linux/types.h>
#include <linux/delay.h>


#include <tvscalercontrol/vip/peaking.h>
#include <tvscalercontrol/scalerdrv/scalerdrv.h>
//#include <tvscalercontrol/scaler/vipcommon.h>
//#include <tvscalercontrol/scaler/vipinclude.h>

#include <rtd_types.h>

//#define NEW_ADAPTIVE_STREAM_OVERSCAN //Webos current not ready



/*==================== Definitions ================ */

//#define SCALER_DEBUG

#ifdef SCALER_DEBUG
#define SLR_PRINTF(format, args...) 	printf(format, ##args)
#else
#define SLR_PRINTF(format, args...)
#endif




#define TEST_SKIP_STATE_USE_IPG	 0 // skip scaler's state machine and place internal pattern gen on screen
#define TEST_PATTERN_GEN			0 // use internal pattern gen to setup I/M/D
#define TEST_IMD_BY_YPBPR_SCRIPT	0 // use external YPbPr to setup I/M/D
#define TEST_UZD_BY_IPG			0 // use internal patter gen to varify scaling down
#define TEST_PIP						1// self-test PIP
#define TEST_PIP_BY_IPG				0 // test PIP by internal pattern gen
#define TEST_VO_BY_IPG				0 // test VO by internal pattern gen
#define TEST_SKIP_FOR_DEBUG		0 // skip buggy code
#define TEST_MAIN_IDX				12 // main index for pip auto self-testing
#define TEST_SUB_IDX				5 // sub index for pip auto self-testing 3for ypbpr 5 for hdmi

//unsigned short tAV_PRESET_TABLE[][9]
#define AV_PRESET_TABLE_COL_MAX	9


#define CONFIG_CPU_XTAL_FREQ 27000000
#if 0//?#if defined BUILD_TV057_1_ATV
#define _H_POSITION_MOVE_TOLERANCE      0x3F // +- 63 pixels
#else
//#define _H_POSITION_MOVE_TOLERANCE      0x50 // +- 80 pixels
#define _H_POSITION_MOVE_TOLERANCE      0xa0 // +- 160 pixels
#endif
#define _V_POSITION_MOVE_TOLERANCE      0x32 // 50 lines
#if 0//?#if defined BUILD_TV057_1_ATV
#define _CLOCK_MOVE_TOLERANCE      		0x7F // 127
#else
#define _CLOCK_MOVE_TOLERANCE      		0x32 // 50
#endif

//USER:LewisLee DATE:2015/09/26
//Porch limite is relate by HW
// V front porch need large than 4
// H front porch need large than 2 => 8
#define _VGIP_V_FRONT_PORCH_MIN	0x05
//#define _VGIP_H_FRONT_PORCH_MIN	0x03
#define _VGIP_H_FRONT_PORCH_MIN	0x07

extern unsigned char tripled_info;
#define GET_IS3DFMT()					(tripled_info & (_BIT0 | _BIT1))
#define GET_HDMI_3DTYPE()				((tripled_info& (_BIT2 | _BIT3| _BIT4 | _BIT5)) >> 2)
#define GET_HDMI_3D_USER_DRIVEN()	((tripled_info & _BIT6) >> 6)


#define SET_IS3DFMT(x)					(tripled_info = ((tripled_info & ~(_BIT0 | _BIT1))  | ((unsigned int) x & 0x03) ))
#define SET_HDMI_3DTYPE(x)				(tripled_info = ((tripled_info & ~(_BIT2 | _BIT3 | _BIT4 | _BIT5))  | (((unsigned int) x & 0x0f) << 2)))
#define SET_HDMI_3D_USER_DRIVEN(x)	(tripled_info = ((tripled_info & ~_BIT6)  | (((unsigned short) x & 0x01) << 6)))


extern unsigned char dclk_under_flow_2dcvt3d;
#define SET_PANEL_DCLK_STATUS(x)		(dclk_under_flow_2dcvt3d = x)
#define GET_PANEL_DCLK_STATUS()		(dclk_under_flow_2dcvt3d)

extern unsigned char dclk_divider;
#define SET_PANEL_DCLK_DIV(x)	(dclk_divider = (x))
#define GET_PANEL_DCLK_DIV()	1 //(dclk_divider)


typedef enum _SLR_TVSCAN_MODE{
	SLR_TVSCAN_NONE		=	0x00,		// not TV scan mode
	SLR_TVSCAN_AUTO		=	0x01,		// TV auto scan mode
	SLR_TVSCAN_MANUAL	=	0x02,		// TV manual scan mode
} SLR_TVSCAN_MODE;

typedef enum _SLR_INPUT_INFO{
	SLR_INPUT_H_FREQ	=	0x00,
	SLR_INPUT_V_FREQ,
	SLR_INPUT_H_LEN,		// Input Horizontal Total Length
	SLR_INPUT_V_LEN,		// Input vertical Total Length
	SLR_INPUT_H_COUNT,		// Input Horizontal Count from off-line measure
	SLR_INPUT_V_COUNT,		// Input Horizontal Count from off-line measure
	SLR_INPUT_IPH_ACT_STA,
	SLR_INPUT_IPV_ACT_STA,
	SLR_INPUT_IPH_ACT_WID,
	SLR_INPUT_IPV_ACT_LEN,
	SLR_INPUT_ADC_CLOCK,
	SLR_INPUT_CHANNEL,
	SLR_INPUT_DATA_ARRAY_IDX,
	SLR_INPUT_MODE_CURR,		//unsigned char
	SLR_INPUT_MODE_TABLE_INDEX,
	SLR_INPUT_ASPECT_RATIO,
	SLR_INPUT_AFD,
	SLR_INPUT_MEM_ACT_HSTA,		// M Domain scale
	SLR_INPUT_MEM_ACT_VSTA,		// M Domain scale
	SLR_INPUT_MEM_ACT_LEN,		// M Domain scale
	SLR_INPUT_MEM_ACT_WID,		// M Domain scale
	SLR_INPUT_DISPLAY,
	SLR_INPUT_FAILURECOUNT,
	SLR_INPUT_FAILURECOUNT_NOSUPPORT,
	SLR_INPUT_FRAMESYNC,
	SLR_INPUT_CAP_LEN,		// UZD output & M Domian Input
	SLR_INPUT_CAP_WID,		// UZD output & M Domian Input
	SLR_INPUT_DISP_LEN,			// DISPLAY output
	SLR_INPUT_DISP_WID,			// DISPLAY output
	SLR_INPUT_DISP_LEN_PRE,			// Panel Size
	SLR_INPUT_DISP_WID_PRE,			// Panel Size
	SLR_INPUT_POLARITY,
	SLR_INPUT_IPV_SMARTFIT_START,
	SLR_INPUT_IPH_SMARTFIT_START,
	SLR_INPUT_IPV_ACT_LEN_PRE,
	SLR_INPUT_IPV_ACT_STA_PRE,
	SLR_INPUT_IPH_ACT_WID_PRE,
	SLR_INPUT_IPH_ACT_STA_PRE,
	SLR_INPUT_IHSYNCPULSECOUNT,
	SLR_INPUT_HSYNC,
	SLR_INPUT_VSYNC,
	SLR_INPUT_STATE,
	SLR_INPUT_NSHOWMPTYPE,
	SLR_INPUT_INPUT_SRC,
	SLR_INPUT_OSD_INPUT_SRC,
	SLR_INPUT_IPV_DLY_PRE,
	SLR_INPUT_BGCOLOR_R,
	SLR_INPUT_BGCOLOR_G,
	SLR_INPUT_BGCOLOR_B,
	SLR_INPUT_DISP_STATUS,
	SLR_INPUT_WSS,//for wss aspect ratio
	SLR_INPUT_COLOR_SPACE,
	SLR_INPUT_COLOR_DEPTH,
	SLR_INPUT_COLOR_IMETRY,
	SLR_INPUT_THROUGH_I3DDMA,
	SLR_INPUT_SR_MODE,
	SLR_INPUT_PIXEL_MODE,
	SLR_INPUT_DFRC_ENABLE,
	SLR_INPUT_DI_WID,//add this variable to control DI process width
	SLR_INPUT_DI_LEN,//add this variable to control DI process width		After Mac5P   for DI output
	SLR_INPUT_VO_SOURCE_TYPE,
	SLR_INPUT_FRAC_FS_REMOVE_RATIO,
	SLR_INPUT_FRAC_FS_MULTIPLE_RATIO,
	SLR_INPUT_DTG_MASTER_V_FREQ,
#ifdef CONFIG_SDNR_CROP
	SLR_INPUT_SDNRH_ACT_STA_PRE,
	SLR_INPUT_SDNRV_ACT_STA_PRE,
	SLR_INPUT_SDNRH_ACT_WID_PRE,
	SLR_INPUT_SDNRV_ACT_LEN_PRE,
	SLR_INPUT_SDNRH_ACT_STA,
	SLR_INPUT_SDNRV_ACT_STA,
	SLR_INPUT_SDNRH_ACT_WID,
	SLR_INPUT_SDNRV_ACT_LEN,
#endif
	SLR_INPUT_IVSYNCPULSECOUNT,
	SLR_INPUT_V_SYNC_HIGH_PERIOD,
}SLR_INPUT_INFO;

typedef enum _SLR_SCREEN_INFO{
	SLR_SCREEN_H_POS	=	0x00,
	SLR_SCREEN_V_POS,
	SLR_SCREEN_CLOCK,
	SLR_SCREEN_PHASE,
	SLR_SCREEN_H_SIZE,
	SLR_SCREEN_V_SIZE,
	SLR_SCREEN_DISP_RANGE,
	SLR_SCREEN_OPEN_COUNT,
}SLR_SCREEN_INFO;

typedef enum _SLR_DISP_3D_INFO{
	SLR_DISP_3D_IS3DFMT	=	0x00,
	SLR_DISP_3D_3DTYPE,
	SLR_DISP_3D_ENABLE_DOUBLE_DVS,
	SLR_DISP_3D_3DFLOW,
	SLR_DISP_3D_DISPLAY_SIZE,
	SLR_DISP_3D_MAIN_ADDR,
	SLR_DISP_3D_MAIN_SEC_ADDR,
	SLR_DISP_3D_MAIN_THIRD_ADDR,
	SLR_DISP_3D_SUB_ADDR,
	SLR_DISP_3D_SUB_SEC_ADDR,
	SLR_DISP_3D_SUB_THIRD_ADDR,
	SLR_DISP_3D_LR_SEQUENCE,
	SLR_DISP_3D_IS_2D_CVT_3D,
	SLR_DISP_3D_3DDEPTH,
	SLR_DISP_3D_2DCVT3DDEPTH,
	SLR_DISP_3D_BLKSTEP,
	SLR_DISP_3D_H_RATIO,
	SLR_DISP_3D_V_RATIO,
	SLR_DISP_3D_MEM_WID_PRE,
	SLR_DISP_3D_MEM_LEN_PRE,
}SLR_DISP_3D_INFO;

/**
     3D Mode
     0:2D, 1:3D Auto, 2:3D SideBySide, 3:3D TopAndBottom, 4:3D FramePacking,
     5:2Dcvt3D, 6:3DSBScvt2D, 7:3DTBcvt2D, 8:3DFPcvt2D
**/
typedef enum {
	SLR_3DMODE_2D = 0,
	SLR_3DMODE_3D_AUTO,
	SLR_3DMODE_3D_SBS,
	SLR_3DMODE_3D_TB,
	SLR_3DMODE_3D_FP,
	// --- new 3D format ---
	SLR_3DMODE_3D_LBL,
	SLR_3DMODE_3D_VSTRIP,
	SLR_3DMODE_3D_CKB,
	SLR_3DMODE_3D_REALID,
	SLR_3DMODE_3D_SENSIO,
	SLR_3DMODE_2D_CVT_3D,
	// -------------------
	SLR_3DMODE_3D_AUTO_CVT_2D,
	SLR_3DMODE_3D_SBS_CVT_2D,
	SLR_3DMODE_3D_TB_CVT_2D,
	SLR_3DMODE_3D_FP_CVT_2D,
	// --- new 3D format ---
	SLR_3DMODE_3D_LBL_CVT_2D,
	SLR_3DMODE_3D_VSTRIP_CVT_2D,
	SLR_3DMODE_3D_CKB_CVT_2D,
	SLR_3DMODE_3D_REALID_CVT_2D,
	SLR_3DMODE_3D_SENSIO_CVT_2D,
	// -------------------
	SLR_3DMODE_NUM,
	// disable
	SLR_3DMODE_DISABLE = 0xff,
} SLR_3D_MODE;

typedef enum {
	SLR_3D_FRAME_PACKING = 0,
	SLR_3D_FIELD_ALTERNATIVE = 1,
	SLR_3D_LINE_ALTERNATIVE = 2,
	SLR_3D_SIDE_BY_SIDE_FULL = 3,
	SLR_3D_L_DEPTH = 4,
	SLR_3D_L_DEPTH_GPX = 5,
	SLR_3D_TOP_AND_BOTTOM =6,
	SLR_3D_FRAMESEQUENCE=7,
	SLR_3D_SIDE_BY_SIDE_HALF = 8,
	// --- new 3D format ---
	SLR_3D_VERTICAL_STRIP,
	SLR_3D_CHECKER_BOARD,
	SLR_3D_REALID,
	SLR_3D_SENSIO,
	// -------------------
	SLR_3D_SIDE_BY_SIDE_HALF_CVT_2D,
	SLR_3D_TOP_AND_BOTTOM_CVT_2D,
	SLR_3D_FRAME_PACKING_CVT_2D,
	// --- new 3D format ---
	SLR_3D_LINE_ALTERNATIVE_CVT_2D,
	SLR_3D_VERTICAL_STRIP_CVT_2D,
	SLR_3D_CHECKER_BOARD_CVT_2D,
	SLR_3D_REALID_CVT_2D,
	SLR_3D_SENSIO_CVT_2D,
	// -------------------
	SLR_3D_2D_CVT_3D,
	SLR_3D_2D_ONLY,
	SLR_3D_UNKOWN = 0xFFFFFFFF
} SLR_3D_TYPE;

typedef enum _SLR_MODE_INFO{
	SLR_MODE_MODECURR	=	0x00,
	SLR_MODE_POLARITY,
	SLR_MODE_IHFREQ,
	SLR_MODE_IVFREQ,
	SLR_MODE_IHLEN,
	SLR_MODE_IVLEN,
	SLR_MODE_IHWID,
	SLR_MODE_IVHEIGHT,
	SLR_MODE_IHSTARTPOS,
	SLR_MODE_IVSTARTPOS,
	SLR_MODE_IHCOUNT,
	SLR_MODE_IVCOUNT,
	SLR_MODE_IHSYNCPULSECOUNT,
}SLR_MODE_INFO;

typedef enum _SLR_PIP_INFO{
	SLR_PIP_ENABLE = 0x00,
	SLR_PIP_POSITION,
	SLR_PIP_TYPE,
//	SLR_PIP_SUBRGB_CONTRAST,	// marked by hsliao 20090306
//	SLR_PIP_SUBRGB_BRIGHTNESS,	// marked by hsliao 20090306
	SLR_PIP_BLENDING,
	SLR_PIP_SWAP,
	SLR_PIP_RUN,
}SLR_PIP_INFO;

typedef enum _SLR_PIP_SUB_INFO{
	SLR_PIP_SUB_MPENABLE,
	SLR_PIP_SUB_SUBHVCNT,///! block count in H/V-direction[bit3~2:H, bit1~0:V]
	SLR_PIP_SUB_MPHIIDX,///! MP window index to highlight
	SLR_PIP_SUB_MPENIDX,///! MP window enable status
	SLR_PIP_SUB_MPCNT,///! total MP block count
	SLR_PIP_SUB_MPDISPLINESTEP,	///! line step of display end
	SLR_PIP_SUB_MPDISPBLOCKSTEP///! block step of display end
}SLR_PIP_SUB_INFO;

// Sub type
typedef enum
{
	SUBTYPE_NONE = 0x01,
	SUBTYPE_PIPSMALL = 0x03,     // bit 0 for main don't need to change!!
	SUBTYPE_PIPMEDIUM = 0x05,  // bit 0 for main don't need to change!!
	SUBTYPE_PIPLARGE = 0x07,    // bit 0 for main don't need to change!!
	SUBTYPE_PIPMLSR = 0x08,
	SUBTYPE_PIPMLSR_4x3 = 0x0a,
	SUBTYPE_MP2X2 = 0x0b,  		// bit 0 for main don't need to change!!
	SUBTYPE_MP3X3 = 0x0d,   	// bit 0 for main don't need to change!!
	SUBTYPE_MP4X4 = 0x0e,   	// bit 0 for main don't need to change!!
	SUBTYPE_MP1C12B = 0x10,		//12 sub multi-pictures besieges one main center picture
	SUBTYPE_MP1L7B = 0x14,		//7 multi-pictures besieges one main left-top picture
	SUBTYPE_PIPFULL = 0x16,		//for OSD full screen blending
	SUBTYPE_PIPCUSTOM = 0x19,
	SUBTYPE_ALL = 0x20,
}eSubType;


typedef enum
{
	PIPPOS_TOPLEFT = 0x00,	//[0: top-left corner		]
	PIPPOS_BOTTOMLEFT,		//[1: bottom-left corner	]
	PIPPOS_CENTER,			//[2: center				]
	PIPPOS_TOPRIGHT,		//[3: top-right corner	]
	PIPPOS_BOTTOMRIGHT		//[4: bottom-right corner	]
}ePipPos;

typedef enum
{
	BORDERSTYLE_TOP = 0x00,
	BORDERSTYLE_BOTTOM,
	BORDERSTYLE_LEFT,
	BORDERSTYLE_RIGHT,
	BORDERSTYLE_ALL,
	BORDERSTYLE_NONE
}BorderStyle;


//	unsigned short 	disp_status; 		///! the status of this display
						// bit0: 1 - through IP, 0 - not through IP
						// bit1: 1 - 422 format, 0 - 444 format
						// bit2: 1 - 10 bits, 0 - 8 bits
						// bit3: 1 - 422 formart caputure memory, 0 - 422
						// bit4: NR_MODE
						// bit5: VUZD_MODE
						// bit6: VIDEO_COMP_MODE
						// bit7: 1 - Freeze, 0 - not Freeze
						// bit8: 1 - Interlace in input, 0 - not Interlace in input
						// bit9: 1 - show, 0 - not show
						// bit10: 1 - Enter RTNR, 0 - Not Enter RTNR
						// bit11: 1 - Motion_Adaptive_3A 0-Motion_Adaptive_5A
						// bit14: 1 - Complete modify size, 0 - not complete
						// bit15: 1 - first, 0 - no first
#if 0 //move to scalercommon.h rika 20141024
typedef enum _SLR_DISP_STATUS{
	SLR_DISP_THRIP 			= _BIT0,
	SLR_DISP_422 				= _BIT1,
	SLR_DISP_10BIT			= _BIT2,
	SLR_DISP_422CAP			= _BIT3,
	SLR_DISP_FSYNC		= _BIT4,
	SLR_DISP_VUZD 			= _BIT5,
	SLR_DISP_FSYNC_VUZD		= _BIT4|_BIT5,
	SLR_DISP_COMP				= _BIT6,
	SLR_DISP_FREEZE			= _BIT7,
	SLR_DISP_INTERLACE	= _BIT8,
	SLR_DISP_SHOW				= _BIT9,
	SLR_DISP_RTNR				= _BIT10,
	SLR_DISP_MA3A				= _BIT11,
	SLR_DISP_VFLIP3			= _BIT13,
	SLR_DISP_SIZE				= _BIT14,
	SLR_DISP_FIRST			= _BIT15,
} SLR_DISP_STATUS;
#endif
typedef enum _SLR_DI_STATUS{
	SLR_DI_3A_mode 			= 0,
	SLR_DI_5A_mode 			= 1,
	SLR_DI_progress_mode 	= 2,
} SLR_DI_STATUS;


typedef enum _SLR_SCALE_STATUS{
	SLR_SCALE_V_UP 			= _BIT0,
	SLR_SCALE_V_DOWN		= _BIT1,
	SLR_SCALE_H_UP 			= _BIT2,
	SLR_SCALE_H_DOWN		= _BIT3,
} SLR_SCALE_STATUS;
#define VUZD_BUFFER_FRAMESYNC_MODE			_BIT0
#define VUZD_BUFFER_VUZD_MODE				_BIT1
#define VUZD_BUFFER_BYPASS_MODE				0

typedef enum _SLR_COLOR_INFO{
	SLR_COLOR_BACKLIGHT = 0,
	SLR_COLOR_SHARPNESS ,
	SLR_COLOR_PEAKING ,
	SLR_COLOR_DCTI ,
	SLR_COLOR_DCCLEVEL,
	SLR_COLOR_SCALEPK,
}SLR_COLOR_INFO;

typedef enum {
	// auto
	SLR_RATIO_AUTO = 0,

	// for China
	SLR_RATIO_4_3,
	SLR_RATIO_16_9,
	SLR_RATIO_14_9,
	SLR_RATIO_LETTERBOX,
	SLR_RATIO_PANORAMA,
	SLR_RATIO_FIT,
	SLR_RATIO_POINTTOPOINT,

	// for best buy
	SLR_RATIO_BBY_AUTO,
	SLR_RATIO_BBY_NORMAL,
	SLR_RATIO_BBY_ZOOM,
	SLR_RATIO_BBY_WIDE_1,
	SLR_RATIO_BBY_WIDE_2,
	SLR_RATIO_BBY_CINEMA,
	//for AP set display window
	SLR_RATIO_CUSTOM,
	//modified for display ratio request
	//egger20100909 start
	SLR_ASPECT_RATIO_PERSON,
	SLR_ASPECT_RATIO_CAPTION,
	SLR_ASPECT_RATIO_MOVIE,
	SLR_ASPECT_RATIO_ZOOM,

	//modified for display ratio request
	//egger20100909 end
	//frank@0927 add below display ratio mode for tpv project
	SLR_ASPECT_RATIO_100,
	//frank@1028 add below display ratio mode to keep soure resolution ratio for project
	SLR_ASPECT_RATIO_SOURCE,
	//frank@1229 add below display ratio mode for tpv project
	SLR_RATIO_ZOOM_14_9,
#if 1//#ifdef CONFIG_ENABLE_NATIVE_DISPLAY_RATIO_MODE
	SLR_RATIO_NATIVE,
#endif //#ifdef CONFIG_ENABLE_NATIVE_DISPLAY_RATIO_MODE
	SLR_RATIO_15_9,
	SLR_RATIO_85_48,
	SLR_RATIO_5_4,
	SLR_RATIO_16_10,
	SLR_RATIO_SOURCE_CUSTOM,  //add display ratio mode to keep source resolution ratio and video in display window
	// disable
	SLR_RATIO_DISABLE = 0xff,
} SLR_RATIO_TYPE;

typedef enum
{
	VO_AR_ORIGINAL = 0,			// change back to original size
	VO_AR_16_9_BBY_ZOOM,			// panel 16:9, BBY NORMAL zoom mode
	VO_AR_16_9_BBY_CINEMA,		// panel 16:9, BBY WIDE 2 zoom mode
	VO_AR_16_9_AUTO_AFD,		// afd
	VO_AR_16_9_PERSON,			// panel 16:9, person mode
	VO_AR_16_9_CAPTION,		// panel 16:9, caption mode
	VO_AR_16_9_MOVIE,		// panel 16:9, movie mode
	VO_AR_16_9_ZOOM,		// panel 16:9, zoom mode
	VO_AR_16_9_ZOOM2,		// panel 16:9, zoom2 mode
	VO_AR_16_9_ZOOM3,		// panel 16:9, zoom3 mode
} VO_ASPECT_RATIO;	// aspect ratio which needs VO's help

typedef enum _SLR_IPMARGIN_TYPE{
	SLR_IPMARGIN_H_MAX,
	SLR_IPMARGIN_H_MIN,
	SLR_IPMARGIN_V_MAX,
	SLR_IPMARGIN_V_MIN,
} SLR_IPMARGIN_TYPE;

typedef enum _SLR_SOURCERATIO_TYPE{
	SLR_SOURCERATIO_16X9=0,
	SLR_SOURCERATIO_4X3,
} SLR_SOURCERATIO_TYPE;

typedef enum _SLR_ATV_VIDEO_STD{
	SLR_ATV_VIDEO_AUTO	= 0,
	SLR_ATV_VIDEO_PAL,
	SLR_ATV_VIDEO_NTSC,
	SLR_ATV_VIDEO_NTSC_443,
	SLR_ATV_VIDEO_SECAM,
	SLR_ATV_VIDEO_PAL_DK,
	SLR_ATV_VIDEO_PAL_I,
	SLR_ATV_VIDEO_PAL_BG,
	SLR_ATV_VIDEO_SECAM_DK,
	SLR_ATV_VIDEO_MAX,
}SLR_ATV_VIDEO_STD;

#if 0 // move to scalerCommon.h
/**
 SLR_YCbCrFMT enumerates the YCbCr Chroma Format.
 */
typedef enum {
	SLR_YCBCR_420,			///< YCbCr 4:2:0
	SLR_YCBCR_422,			///< YCbCr 4:2:2
	SLR_YCBCR_444			///< YCbCr 4:4:4
} SLR_YCBCRFMT;

/**
 VODMA_DDOMAIN_CHROMA_FMT enumerates the VO Chroma Format.
 */
typedef enum
{
	FMT_444=0,
	FMT_422,
	FMT_420
} VODMA_DDOMAIN_CHROMA_FMT ;
#endif

typedef enum _SLR_TV_MODE{
//	SLR_TV_MODE_NONE =0,
	SLR_ATV_MODE = 0,
	SLR_DTV_MODE,
	SLR_SCAN_MODE,
}SLR_TV_MODE;

typedef struct _SLR_TV_CHANNEL_INFO{
	SLR_TV_MODE 		mode;
	SLR_ATV_VIDEO_STD 	atvVideoStd;
}SLR_TV_CHANNEL_INFO;

#if 0 // cklai@100427 use enum to define the source object types
// for src_proc[_SRC_OBJ_MAX] =
#define _SRC_OBJ_AV_SV		0
#define _SRC_OBJ_TV			1
#define _SRC_OBJ_HDMI		2
#define _SRC_OBJ_VGA		3
#define _SRC_OBJ_YPBPR 		4
#define _SRC_OBJ_VO			5

#ifdef ENABLE_DISPLAYPORT
#define _SRC_OBJ_DP			6

#ifdef CONFIG_INPUT_SOURCE_IPG
#define _SRC_OBJ_IPG		7
#define _SRC_OBJ_MAX		8
#else
#define _SRC_OBJ_MAX		7
#endif

#else

#ifdef CONFIG_INPUT_SOURCE_IPG
#define _SRC_OBJ_IPG		6
#define _SRC_OBJ_MAX		7
#else
#define _SRC_OBJ_MAX		6
#endif

#endif
#endif // end #if 0 // ckali@...

// for src_proc[_SRC_OBJ_MAX] =
typedef enum _SRC_OBJ_TYPE {
	_SRC_OBJ_AV_SV = 0,
	_SRC_OBJ_TV,
	_SRC_OBJ_HDMI,
	_SRC_OBJ_VGA,
	_SRC_OBJ_YPBPR,
	_SRC_OBJ_VO,
	_SRC_OBJ_OSD,

#ifdef ENABLE_DISPLAYPORT
	_SRC_OBJ_DP,
#endif

#ifdef CONFIG_INPUT_SOURCE_IPG
	_SRC_OBJ_IPG,
#endif

	_SRC_OBJ_MAX,	// don't change this order
}SRC_OBJ_TYPE;

#ifdef CONFIG_SOURCE_AUTO_SWITCH
typedef enum SRC_SWITCH_TYPE {
	_SRC_SWITCH_AV1 = 0,
	_SRC_SWITCH_YPBPR1,
	_SRC_SWITCH_VGA,
	_SRC_SWITCH_HDMI1,
	_SRC_SWITCH_HDMI2,
	_SRC_SWITCH_MAX,	// don't change this order
}SRC_SWITCH_TYPE;
#endif

//need sync with get_HDMI_AFD()
typedef enum _SLR_AFD_RATIO_TYPE{
	SLR_AFD_RATIO_NO_DATA = 0,
	SLR_AFD_RATIO_4_3,
	SLR_AFD_RATIO_16_9,
	SLR_AFD_RATIO_4_3_AFAR_16_9,  //cloud add need See CEA 861 D spec page 67
	SLR_AFD_RATIO_4_3_AFAR_14_9,
	SLR_AFD_RATIO_16_9AFAR_4_3,
	SLR_AFD_RATIO_16_9AFAR_14_9,
	SLR_AFD_RATIO_MAX,
}SLR_AFD_RATIO_TYPE;


/*==================== struct ================ */
// oliver-, move to scalerCommon.h
/*
typedef struct _StructSourceInput{
	ENUM_TVD_INPUT_FORMAT	input_fmt;
	unsigned short			src_type;	// Bit0~Bit7: RTD2622 input from, Bit8~Bit15: VDC input type
	unsigned short			src_index;
//	unsigned char			label[20];
	unsigned char			osdarray_index;
	unsigned char			srcObj_index;
	void*			InitOptions;	// different initial setting according to individual source(just for video decoder)
	unsigned char			srcAutoSwitchAVSV_DB;
} StructSourceInput;
*/


typedef struct _ModeInformationType{
	unsigned char ModeCurr;  				// Input Mode
	unsigned char Polarity;  				// BIT0: H Polarity, Bit1: V Polarity
	unsigned short IHFreq;					// Input Horizontal Frequency
	unsigned short IVFreq;					// Input Vertical Frequency
	unsigned short IHTotal;   				// Input Horizontal Total Length
	unsigned short IVTotal;   				// Input Vertical Total Length
	unsigned short IHWidth;   				// Input Horizontal Width
	unsigned short IVHeight;  				// Input Vertical Height
	unsigned short IHStartPos;				// Input Horizontal Start Position
	unsigned short IVStartPos;				// Input Vertical Start Position
	unsigned short IHCount;   				// Input Horizontal Count Numbers  (measuement unit: Crystal clock)
	unsigned short IVCount;   				// Input Vertical Count Numbers	 (measuement unit: HS)
	unsigned short IHSyncPulseCount;  		// Input Horizontal Sync Pulse Count Numbers
} ModeInformationType;


typedef struct _StructDisplay3DInfo {
	unsigned char bIs3dFmt;			// 0:2D, 1:SG, 2:PR
	unsigned char uc3dType;
	unsigned char bEnableDoubleDVS;
	unsigned char uc3dFlow;
	unsigned int display_size;
	unsigned int main_addr;
	unsigned int main_sec_addr;
	unsigned int main_third_addr;
	unsigned int sub_addr;
	unsigned int sub_sec_addr;
	unsigned int sub_third_addr;
	unsigned char ucLRsequence;
	unsigned char bIs2Dcvt3D;	// 0: disable 1: enable in SG type 2: enable in PR type
	char c3dDepth;
	char c2Dcvt3dDepth;
	unsigned int ui3dBlkStep;
	unsigned int HRatio3d;
	unsigned int VRatio3d;
	unsigned int mem_wid_pre;
	unsigned int mem_len_pre;
} StructDisplay3DInfo;

typedef struct _StructScreenModeInfo{
      unsigned short H_Start_Pos_After_Auto;  //vgip h pos
	  unsigned short V_Start_Pos_After_Auto;
      unsigned char H_Position; //osd h pos
      unsigned char V_Position; // osd v pos
      unsigned char ClockShift_After_auto;//auto clock value 0-255 means adc clock shift. 128: no shift     
      unsigned char Clock;//osd clock value 0-100
      unsigned char Phase;
      unsigned char Open_Count; 		//jerry0108 CSW+ 0961123 Run VGA auto-adjust function at first time display
}StructScreenModeInfo;

#ifdef ENABLE_MHEG5
typedef enum _SLR_IFRAME_MODE{
	SLR_IFRAME_NONE=0,
	SLR_IFRAME_4X3,
	SLR_IFRAME_16X9,
} SLR_IFRAME_MODE;
typedef enum _SLR_MHEG5_SCENE_ASPECT_RATIO{
	SLR_MHEG5_SCENE_ASPECT_NONE=0,
	SLR_MHEG5_SCENE_ASPECT_4X3,
	SLR_MHEG5_SCENE_ASPECT_16X9,
	SLR_MHEG5_SCENE_EXIT,
} SLR_MHEG5_SCENE_ASPECT_RATIO;

typedef enum _SLR_MHEG5_ALIGNMENT{
	SLR_MHEG5_ALIGNMENT_NONE=0,
    SLR_MHEG5_ALIGNMENT_CENTRE_CUT_OUT,
    SLR_MHEG5_ALIGNMENT_LETTERBOX
} SLR_MHEG5_ALIGNMENT;

typedef struct _StructOverscanInfo{
	unsigned short					width;
	unsigned short					height;
	unsigned short					preWidth;
	unsigned short					preHeight;
}StructOverscanInfo;


#endif

typedef enum _RATIO_TYPE_STATE {
	RT_STATE_INIT = 0,
	RT_STATE_CHANGE = 1,
	RT_STATE_UNCHANGED = 2,
}RATIO_TYPE_STATE;

#define GET_H_POSITION() (stScreenModeCurrInfo->H_Position)
#define SET_H_POSITION(x) (stScreenModeCurrInfo->H_Position = x)

#define GET_V_POSITION() (stScreenModeCurrInfo->V_Position)
#define SET_V_POSITION(x) (stScreenModeCurrInfo->V_Position = x)

#define GET_CLOCK() (stScreenModeCurrInfo->Clock)
#define SET_CLOCK(x) (stScreenModeCurrInfo->Clock = x)

#define GET_PHASE() (stScreenModeCurrInfo->Phase)
#define SET_PHASE(x) (stScreenModeCurrInfo->Phase = x)

#define GET_CENTER_CLOCK()  (stScreenModeCurrInfo->Center_Clock)
#define SET_CENTER_CLOCK(x) 	(stScreenModeCurrInfo->Center_Clock = x)

#define GET_H_START_POS_AFTER_AUTO() (stScreenModeCurrInfo->H_Start_Pos_After_Auto)
#define SET_H_START_POS_AFTER_AUTO(x) (stScreenModeCurrInfo->H_Start_Pos_After_Auto = x)

#define GET_V_START_POS_AFTER_AUTO() (stScreenModeCurrInfo->V_Start_Pos_After_Auto)
#define SET_V_START_POS_AFTER_AUTO(x) (stScreenModeCurrInfo->V_Start_Pos_After_Auto = x)

typedef struct _StructPipDataType{
	unsigned char enable:1;
		//bit0		[ 0:disable, 1:enable ]
	unsigned char pipPosition:7;
		//bit 1~3	[ PIP position ]
		//			[ 0 : top-left corner		]
		//			[ 1 : bottom-left corner		]
		//			[ 2 : center				]
		//			[ 3 : top-right corner		]
		//			[ 4 : bottom-right corner	]
		//bit 4~7	[ Reserved ]

	unsigned char type;
		//bit 0~4	[ Sub picture type ]
		//			[ 0x01 : None			]
		//			[ 0x03 : PIP - Small	]
		//			[ 0x05 : PIP - Medium	]
		//			[ 0x07 : PIP - Large	]
		//			[ 0x08 : MLSR			]
		//			[ 0x0a : MLSR4X3		]
		//			[ 0x0b : MP2X2		]
		//			[ 0x0d : MP3X3		]
		//			[ 0x0e : MP4X4		]
		//			[ 0x10 : MP1C12B		] //12 sub multi-pictures besieges one main center picture
		//			[ 0x14 : MP1L7B		] //7 multi-pictures besieges one main left-top picture
		//			[ 0x16 : Full			]
		//			[ 0x18 : All			]
		//Note: Please see SLR_PIP_MODE for more details.
		//bit 5~7	[ Reserved ]

//	unsigned char SubRgbContrast;		// marked by hsliao 20090306
//	unsigned char SubRgbBrightness;	// marked by hsliao 20090306
	unsigned char PipBlending;
	unsigned char PipSwapStatus;
	unsigned char PipRunStatus;
//	unsigned char Reserved[9];
}StructPipDataType;

typedef struct _STRUCTSUBINFO
{
	unsigned char MpEnable;
	unsigned char SubHVCnt;		///! block count in H/V-direction[bit3~2:H, bit1~0:V]
	unsigned short MpHiIdx;		///! MP window index to highlight
	unsigned short MpEnIdx;	///! MP window enable status
	unsigned char MpCnt;		///! total MP block count
	unsigned short MpDispLineStep;	///! line step of display end
	unsigned short MpDispBlockStep;	///! block step of display end
}StructSubInfo;

typedef enum LIVE_ZOOM_TYPE
{
	LIVE_ZOOM_OFF = 0,
	LIVE_ZOOM_MAIN,
	LIVE_ZOOM_SUB,
} LIVE_ZOOM_TYPE_T;

#if 0
typedef enum PIP_TYPE_MAGNIFIER_LIVEZOOM
{
	PIP_LIVEZOOM= 0,
	PIP_MAGNIFIER,
} PIP_TYPE_MAGNIFIER_LIVEZOOM_T;
#endif
#define VD_3D_TABLE_SIZE		30
#define VD_MOTION_STEP		8


/*==================== Functions ================ */
unsigned char Scaler_StructInit(StructSourceInput* sourceInfo, unsigned char maxSource, unsigned char mainInputSource, unsigned char subInputSource);
void Scaler_StructUninit(void);
void Scaler_SET_VSCDispinfo_WithVFEDispinfo(unsigned char display, StructDisplayInfo* VFEDispInfo);
unsigned char vsc_timinginfo_check(void);

unsigned int Scaler_ModeGetModeInfo(SLR_MODE_INFO infoList);
void Scaler_ModeSetModeInfo(SLR_MODE_INFO infoList,unsigned int data);

unsigned int Scaler_ModeGet_Hdmi_ModeInfo(SLR_MODE_INFO infoList);
void Scaler_ModeSet_Hdmi_ModeInfo(SLR_MODE_INFO infoList, unsigned int data);

unsigned char Scaler_TVSetChannelInfo(SLR_TV_CHANNEL_INFO *chInfo);
void Scaler_TVSetExitScan(bool m_exit); //UI direct change ATVAutoScanExitflag
bool Scaler_TVGetExitScan(void);
unsigned char Scaler_TVGetScanMode(void);
SLR_TV_MODE Scaler_TVGetMode(void);
SLR_ATV_VIDEO_STD Scaler_TVGetAtvVideoStd(void);

void Scaler_InputSrcInit(StructSourceInput* ptr);
StructSourceInput* Scaler_Get_InputSrcInit(void);
unsigned short Scaler_InputSrcIndex(unsigned char idx);
void Scaler_AutoAVInputSrcInit(StructSourceInput* ptr);
StructSourceInput* Scaler_InputSrc(unsigned char idx);
StructSourceInput* Scaler_AutoAVInputSrc(unsigned char idx);
unsigned short Scaler_InputSrcGetRawType(unsigned char idx);
unsigned char Scaler_InputSrcGetIdxType(unsigned char idx);
unsigned char Scaler_InputSrcGetIdxFrom(unsigned char idx);
ENUM_TVD_INPUT_FORMAT Scaler_InputSrcGetFormat(SCALER_DISP_CHANNEL channel);
unsigned char Scaler_InputSrcGetType(SCALER_DISP_CHANNEL channel);
unsigned char Scaler_InputSrcGetFrom(SCALER_DISP_CHANNEL channel);
unsigned char Scaler_InputSrcGetMainChType(void);
unsigned char Scaler_InputSrcGetMainChFrom(void);
unsigned char Scaler_InputSrcGetMainChFormat(void);
ENUM_TVD_INPUT_FORMAT Scaler_InputSrcFormat(unsigned char idx); // peggy: add to get input format
ENUM_TVD_INPUT_FORMAT Scaler_InputSrcGetMainFormat(void);

void Scaler_DispSetAutoPosition(bool flag);

bool Scaler_DispGetAutoPosition(void);

unsigned char Scaler_DispInfoSetModeCurr(unsigned int modeCurr);
StructDisplayInfo* Scaler_DispGetInfoPtr(void);
unsigned short Scaler_DispGetInputInfo(SLR_INPUT_INFO infoList);
void Scaler_DispSetInputInfo(SLR_INPUT_INFO infoList,unsigned short value);
void Scaler_DispSetInputInfoByDisp(SCALER_DISP_CHANNEL channel,SLR_INPUT_INFO infoList,unsigned short value);
unsigned short Scaler_DispGetInputInfoByDisp(unsigned char channel,SLR_INPUT_INFO infoList);
unsigned char Scaler_ScreenGetInputInfo(unsigned char source,SLR_SCREEN_INFO infoList);
unsigned short Scaler_DispGetStatus(SCALER_DISP_CHANNEL channel,SLR_DISP_STATUS index);
void Scaler_DispSetStatus(SCALER_DISP_CHANNEL channel,SLR_DISP_STATUS index, unsigned short status);
unsigned short Scaler_DispGetScaleStatus(SCALER_DISP_CHANNEL channel,SLR_SCALE_STATUS index);
void Scaler_DispSetScaleStatus(SCALER_DISP_CHANNEL channel,SLR_SCALE_STATUS index, unsigned char status);
//void Scaler_Disp3dSetInfo(SLR_DISP_3D_INFO infoList, unsigned int value);
void Scaler_Disp3dSetInfo(SCALER_DISP_CHANNEL channel, SLR_DISP_3D_INFO infoList, unsigned int value);
//unsigned int Scaler_Disp3dGetInfo(SLR_DISP_3D_INFO infoList);
unsigned int Scaler_Disp3dGetInfo(SCALER_DISP_CHANNEL channel, SLR_DISP_3D_INFO infoList);

//pip
unsigned char Scaler_PipGetInfo(SLR_PIP_INFO infoList);
void Scaler_PipSetInfo(SLR_PIP_INFO infoList,unsigned char value);
unsigned short Scaler_PipGetSubInfo(SLR_PIP_SUB_INFO infoList);
void Scaler_PipSetSubInfo(SLR_PIP_SUB_INFO infoList,unsigned short value);

//VGA
void Scaler_VGASetClockStatus(SCALER_DISP_CHANNEL channel,unsigned char status);
unsigned char Scaler_VGAGetClockStatus(SCALER_DISP_CHANNEL channel);

//ratio
void Scaler_DispSetRatioMode(SLR_RATIO_TYPE ratio);
#if defined (TV003_ADTV)
bool Scaler_GetIsUserSetRatio(void);
void  Scaler_SetIsUserSetRatio(bool isUser);
#endif
unsigned char Scaler_DispCheckRatio(SLR_RATIO_TYPE ratio);
SLR_RATIO_TYPE Scaler_DispGetRatioMode(void);
SLR_RATIO_TYPE Scaler_DispGetRatioMode2(void);
SLR_RATIO_TYPE Scaler_DispGetPreRatioMode(void); //cloud add@20111223

void Scaler_OSD4k2kSet(unsigned char m_osd4k2k);

void Scaler_AdaptiveStream_NewInputRegionFlagSet(unsigned char display,unsigned char bEnable);
unsigned char Scaler_AdaptiveStream_NewInputRegionFlagGet(unsigned char display);
void Scaler_AdaptiveStream_InputWindowSet(StructSrcRect m_inputwin);
StructSrcRect Scaler_AdaptiveStream_InputWindowGet(void);
void Scaler_DispWindowSet(StructSrcRect m_dispwin);
StructSrcRect Scaler_DispWindowGet(void);
void Scaler_DispWindowSet_source(StructSrcRect m_dispwin);
StructSrcRect Scaler_DispWindowGet_source(void);

//delay
unsigned char Scaler_DispGetIvs2DvsDelay(void);
void Scaler_DispSetIvs2DvsDelay(unsigned char value);


unsigned char Scaler_DispGetVgaIVS2DVSDelay(void);
void Scaler_DispSetVgaIVS2DVSDelay(unsigned char value);


unsigned char Scaler_DispGetIhsDelay(void);
void Scaler_DispSetIhsDelay(unsigned char value);
unsigned char Scaler_DispGetIpMargin(SLR_IPMARGIN_TYPE type);
void Scaler_DispSetIpMargin(SLR_IPMARGIN_TYPE type,unsigned char value);

#ifdef CONFIG_ENABLE_3D_SETTING
unsigned char Scaler_Get3DEnable(void);
unsigned char Scaler_Set3DEnable(unsigned char enable);
#endif

//unsigned char Scaler_GetYcSep(void);
//unsigned char Scaler_SetYcSep(unsigned char yc_sep);

void Scaler_SetHDMIDiditalMeasureIVH(unsigned short value);
unsigned short Scaler_GeHDMIDiditalMeasureIVH(void);

unsigned char Scaler_GetTvBlueScreen(void);
void Scaler_SetTvBlueScreen(unsigned char status);
void Scaler_SetCurrentDispInfo(SCALER_DISP_CHANNEL channel);

void Scaler_SetUserInputSrc(SCALER_DISP_CHANNEL channel,unsigned char index);
unsigned char Scaler_GetUserInputSrc(SCALER_DISP_CHANNEL channel);
unsigned char Scaler_GetSourceListLen(void);
unsigned int Scaler_SendDisplayReadyIrc(VO_VIDEO_PLANE plane);

#if 0//FixedME clamp Mac3

void Scaler_SetChangeChannelMode(unsigned char mode);
unsigned char Scaler_GetChangeChannelMode(void);
#endif

void Scaler_SetATVChangeChannelFlag(unsigned char ucFlag);
unsigned char Scaler_GetATVChangeChannelFlag(void);


void Scaler_SetPreATVCheckFailFlag(unsigned char flag);
unsigned char Scaler_GetPreATVCheckFailFlag(void);
SLR_VOINFO* Scaler_VOInfoPointer(unsigned char port);
void Scaler_SetVOFromJPG(unsigned char plane);//For jpeg flow : im config usage
unsigned char Scaler_VOFrom(unsigned char plane);
unsigned char Scaler_VOFromVDEC(unsigned char plane);
unsigned char Scaler_VOFromJPEG(unsigned char plane);
void Scaler_UpdateVOInfo(unsigned char plane);
void Scaler_ClearVOInfo(unsigned char port);
SLR_VOINFO* Scaler_PreVOInfoPointer(unsigned char plane);
void Scaler_Set_CurVoInfo_plane(VO_VIDEO_PLANE plane);
unsigned char Scaler_Get_CurVoInfo_plane(void);
VO_VIDEO_PLANE Scaler_Get_CurVoInfo_VoVideoPlane(unsigned char display);


#define SET_422_Fr_SD(display)	(Scaler_DispSetStatus(display,SLR_DISP_422CAP,TRUE))
#define CLR_422_Fr_SD(display)	(Scaler_DispSetStatus(display,SLR_DISP_422CAP,FALSE))
#define GET_422_Fr_SD(display)	((Scaler_DispGetStatus(display,SLR_DISP_422CAP))


void Scaler_SetVoVersion(unsigned int version);
unsigned int Scaler_GetVoVersion(void);

// new MV ready version control
//void Scaler_SetMvRdyVersion(unsigned int version);
//unsigned int Scaler_GetMvRdyVersion(void);
void Scaler_SetVoRdyVersion(void);
void Scaler_SetVoRdyVersionManual(unsigned int a_ulVersion);
unsigned int Scaler_GetVoRdyVersion(void);
unsigned char Scaler_GetRoiInfo(SCALER_DISP_CHANNEL channel, int* resolution, int* Width, int* Height, unsigned char* isInterlace, int* freq);
#if defined (TV003_ADTV)
bool Scaler_GetIsHD(void);//peterpan1017,20130228: picture size SD and HD are separate
bool Scaler_GetTimingIsHD(void); //peterpan1017,20130228: Get timing is SD ro HD
#endif
unsigned char Scaler_CheckDviMode(void);
unsigned char Scaler_GetYpbprAutoColorFinish(void);
unsigned char Scaler_SetYpbprAutoColorFinish(void);
unsigned char Scaler_SetYpbprCalibrationFinish(void);
unsigned char Scaler_GetYpbprCalibrationFinish(void);

void Scaler_Set_Vo_Timing_Equal(unsigned char option);
//unsigned char Scaler_GET_Vo_Timing_Equal(void);
//unsigned char Scaler_DO_VO_timing_Equal(VO_VIDEO_PLANE plane);

// new display ready version control
unsigned char Scaler_GetCurPlayVideoIndexValidation(void);
unsigned int Scaler_GetCurPlayVideoIndex(void);
unsigned char Scaler_CheckLatestNewVoInfo(unsigned int ver_vo);
unsigned char Scaler_IsLatestDisplayReady(unsigned int data);

#define GET_UI_SOURCE_FROM_PCB()		(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_DATA_ARRAY_IDX))

// oliver+
unsigned int Scaler_GetRPCSrcInfoSize(void);
unsigned char Scaler_TVSetScanMode(unsigned char a_ucScanMode);

void Scaler_Set3DRatioMode(SLR_RATIO_TYPE ratio3d);

void Scaler_DispSetAutoPosition(bool flag);
bool Scaler_DispGetAutoPosition(void);

#ifdef ENABLE_MHEG5
void Scaler_SetIframeMode(SLR_IFRAME_MODE mode);
SLR_IFRAME_MODE Scaler_GetIframeMode(void);
void Scaler_GetAfdAndRatio(VO_VIDEO_PLANE plane, SLR_AFD_TYPE* afd, SLR_SOURCERATIO_TYPE* ratio);
void Scaler_SetMheg5SceneAspectRatio(SLR_MHEG5_SCENE_ASPECT_RATIO ratio);
SLR_MHEG5_SCENE_ASPECT_RATIO Scaler_GetMheg5SceneAspectRatio(void);

void Scaler_SetMheg5Alignment(SLR_MHEG5_ALIGNMENT alignment);
SLR_MHEG5_ALIGNMENT Scaler_GetMheg5Alignment(void);
void Scaler_SetCurrentOverscanInfo(StructOverscanInfo* info);
void Scaler_GetCurrentOverscanInfo(StructOverscanInfo* info);

#endif

unsigned short Scaler_GetDispStatusFromSource(StructDisplayInfo* p_dispinfo,  SLR_DISP_STATUS index);
void Scaler_SetDispStatusFromSource(StructDisplayInfo* p_dispinfo, SLR_DISP_STATUS index, unsigned short status);

void Set_Live_zoom_mode(LIVE_ZOOM_TYPE_T type);
LIVE_ZOOM_TYPE_T Get_Live_zoom_mode(void);

void Set_LivezoomOffMainForceBG(unsigned char value);
unsigned char Get_LivezoomOffMainForceBG(void);
void Set_LivezoomOrMagnifierPIPON(unsigned char value);
unsigned char Get_LivezoomOrMagnifierPIPON(void);
#if 0

unsigned char Scaler_IsTVBOX(void);
unsigned char Scaler_DispGetCVBSOutputType(void);
unsigned char Scaler_DispGetYPPOutputType(void);
unsigned char Scaler_DispGetHDMIOutputType(void);

SLR_RATIO_TYPE Scaler_GetPreRatio_smoothtoggle(void);
void Scaler_SetPreRatio_smoothtoggle(SLR_RATIO_TYPE ratio);
RATIO_TYPE_STATE Scaler_Getratiostate_smoothtoggle(void);
void Scaler_Setratiostate_smoothtoggle(RATIO_TYPE_STATE state);
#endif

#ifdef __cplusplus
}
#endif

#endif // __SCALER_STRUCT_H__


