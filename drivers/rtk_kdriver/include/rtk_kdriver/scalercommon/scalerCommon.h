/***************************************************************************
                          scalerCommon.h  -  description
                             -------------------
    begin                : Wed Mar 11 2009
    copyright           : (C) 2008 by hsliao
    email                : hsliao@realtek.com
 ***************************************************************************/

#ifndef _COMMON_SCALERCOMMON_H__
#define _COMMON_SCALERCOMMON_H__

//#include <VideoRPC_System.h>
//#include <rtd_types.h>

//------------------------------------------
// Definitions of Bits
//------------------------------------------

#ifdef _BIT0
#undef _BIT0
#endif
#ifdef _BIT1
#undef _BIT1
#endif
#ifdef _BIT2
#undef _BIT2
#endif
#ifdef _BIT3
#undef _BIT3
#endif
#ifdef _BIT4
#undef _BIT4
#endif
#ifdef _BIT5
#undef _BIT5
#endif
#ifdef _BIT6
#undef _BIT6
#endif
#ifdef _BIT7
#undef _BIT7
#endif
#ifdef _BIT8
#undef _BIT8
#endif
#ifdef _BIT9
#undef _BIT9
#endif
#ifdef _BIT10
#undef _BIT10
#endif
#ifdef _BIT11
#undef _BIT11
#endif
#ifdef _BIT12
#undef _BIT12
#endif
#ifdef _BIT13
#undef _BIT13
#endif
#ifdef _BIT14
#undef _BIT14
#endif
#ifdef _BIT15
#undef _BIT15
#endif
#ifdef _BIT16
#undef _BIT16
#endif
#ifdef _BIT17
#undef _BIT17
#endif
#ifdef _BIT18
#undef _BIT18
#endif
#ifdef _BIT19
#undef _BIT19
#endif
#ifdef _BIT20
#undef _BIT20
#endif
#ifdef _BIT21
#undef _BIT21
#endif
#ifdef _BIT22
#undef _BIT22
#endif
#ifdef _BIT23
#undef _BIT23
#endif
#ifdef _BIT24
#undef _BIT24
#endif
#ifdef _BIT25
#undef _BIT25
#endif
#ifdef _BIT26
#undef _BIT26
#endif
#ifdef _BIT27
#undef _BIT27
#endif
#ifdef _BIT28
#undef _BIT28
#endif
#ifdef _BIT29
#undef _BIT29
#endif
#ifdef _BIT30
#undef _BIT30
#endif
#ifdef _BIT31
#undef _BIT31
#endif

#define _ZERO                       0x00
#define _BIT0                       0x01
#define _BIT1                       0x02
#define _BIT2                       0x04
#define _BIT3                       0x08
#define _BIT4                       0x10
#define _BIT5                       0x20
#define _BIT6                       0x40
#define _BIT7                       0x80
#define _BIT8                       0x0100
#define _BIT9                       0x0200
#define _BIT10                      0x0400
#define _BIT11                      0x0800
#define _BIT12                      0x1000
#define _BIT13                      0x2000
#define _BIT14                      0x4000
#define _BIT15                      0x8000
#define _BIT16                      0x10000
#define _BIT17                      0x20000
#define _BIT18                      0x40000
#define _BIT19                      0x80000
#define _BIT20                      0x100000
#define _BIT21                      0x200000
#define _BIT22                      0x400000
#define _BIT23                      0x800000
#define _BIT24                      0x1000000
#define _BIT25                      0x2000000
#define _BIT26                      0x4000000
#define _BIT27                      0x8000000
#define _BIT28                      0x10000000
#define _BIT29                      0x20000000
#define _BIT30                      0x40000000
#define _BIT31                      0x80000000


#ifndef TRUE
#define TRUE 1
#endif

#ifndef _TRUE
#define _TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef _FALSE
#define _FALSE 0
#endif

//#define bool unsigned char
/*
#ifndef SUCCESS
  #define SUCCESS                   0
#endif

#ifndef FAILED
  #define FAILED                    (-1)
#endif
*/
#define ON				1
#define OFF				0
#define _ENABLE			1
#define _DISABLE			0
//#define ENABLE			1
//#define DISABLE			0
#define SLR_SUCCESS		1
#define SLR_FAIL			0

// For scalerVIP.c
#define DCR_MAX               5
#define DCR_NODE_NUM    5

#define ADAPTIVE_STREAM_INIT 0xFF
//------------------------------------------
// Definitions of Table Flag for Scaler Access.
//------------------------------------------
#define _TBL_ADDR_NO_INC 	(_BIT7)
#define _TBL_ZERO 			(_BIT6)
#define _TBL_END			(_ZERO)

#define HIGH_BYTE(x)	((x & 0xFF00)>>8)
#define LOW_BYTE(x)		(x & 0x00FF)

#ifndef SHL
	#define SHL(x,y)				((x) << (y))
#endif

#ifndef SHR
#define SHR(x,y)				((x) >> (y))
#endif

#ifndef AND
#define AND(n1,n2)  			((n1) & (n2))
#endif

#ifndef SCALER_OR
#define SCALER_OR(n1,n2)   			((n1) | (n2))
#endif


#ifndef ABS
#define ABS(x,y)				((x > y) ? (x-y) : (y-x))
#endif


#ifndef MAX
    #define MAX(a,b)                (((a) > (b)) ? (a) : (b))
#endif

#ifndef MIN
    #define MIN(a,b)                (((a) < (b)) ? (a) : (b))
#endif


//fndef __ROS__ // ros vo driver still use old interface for compiling
#define NEW_VOINFO_INTERFACE 1
//ndif

#ifndef CONFIG_DUAL_CHANNEL
#define MAX_DISP_CHANNEL_NUM 1
#else
#define MAX_DISP_CHANNEL_NUM 2
#endif

// [2D3D] 2D3D conversion control define
#define SCALER_2D_3D_LINE_REPEAT_CTRL_BIT_START	1
#define SCALER_2D_3D_LINE_REPEAT_CTRL_MASK		(1 << SCALER_2D_3D_LINE_REPEAT_CTRL_BIT_START)

#define SCALER_2D_3D_ZOOM_MODE_CTRL_BIT_START	2
#define SCALER_2D_3D_ZOOM_MODE_CTRL_MASK		(1 << SCALER_2D_3D_ZOOM_MODE_CTRL_BIT_START)

#define FRAME_LEN_IN_PR	540
#define V_FREQ_MAX					600	// [2D3D] Do vertical frequency FRC when VFreq > 60Hz
#define V_FREQ_MAX_MARGIN			5	// [2D3D] +0.5 Hz for margin case

#define HOR_WIDTH_OVER_3DDI_BANDWIDTH	1280

// [2D3D] vertical length adjustment control
#define MAX_PANEL_HEIGHT			1080
#define V_POSITION_MODIFY_LEN_MIN	288
#define V_ACT_LEN_ADJ_THRESHOLD	10	// change v.act sta/len when panel/picture length diff > 10
#define V_ACT_STA_ADJ_THRESHOLD	10	// change v.act sta/len when reserved v.front porch > 10
#define V_ACT_STA_ADJ_LINE		3	// postpone the vertical active start for removing the un-wanted vertical line

typedef enum _VDC_YCSEPARATE_MODE {
	VDC_YCSEPARATE_DEFAULT = 0,
	VDC_YCSEPARATE_1D,
	VDC_YCSEPARATE_2D,
	VDC_YCSEPARATE_3D,
	VDC_YCSEPARATE_3DFix,
} VDC_YCSEPARATE_MODE;

typedef enum _UART_DDC_SEL
{
	PIN_AS_UART = 0,
	PIN_AS_DDC
}UART_DDC_SEL;

typedef enum
{
	_OPC_Daylight = 0,
	_OPC_Normal,
	_OPC_Night,
	_OPC_User,
	_OPC_Dynamic,
	_OPC_State_Max,
}OPC_PROC_STATE;

typedef enum _SCALERVIP_MPEGNR {
	SCALERVIP_MPEGNR_OFF = 0,
	SCALERVIP_MPEGNR_LOW,
	SCALERVIP_MPEGNR_MIDDLE,
	SCALERVIP_MPEGNR_HIGH,
	SCALERVIP_MPEGNR_AUTO,
} SCALERVIP_MPEGNR;


typedef enum _SCALER_MMAP_MODE{
	SCALER_MMAP_MODE_DEFAULT = 0,
	SCALER_MMAP_MODE_TTX = 1,
	SCALER_MMAP_MODE_CC = 2,
	SCALER_MMAP_MODE_SUBTITLE = 3,
	SCALER_MMAP_MODE_DMA_DUMP_TTX = 4,
}SCALER_MMAP_MODE;

typedef enum _SLR_POWER_ON_OFF_EYE_GUARD_MODE{
	SLR_POWER_ON_OFF_EG_STANDARD_MODE,
	SLR_POWER_ON_OFF_EG_EYE_GUARD_MODE,
	SLR_POWER_ON_OFF_EG_CURTAIN_MODE,
	SLR_POWER_ON_OFF_EG_MODE_MAX,
} SLR_POWER_ON_OFF_EYE_GUARD_MODE;

typedef enum _SLR_EYE_GUARD_ADJUST_INDEX{
	SLR_EYE_GUARD_BRIGHTNESS,
	SLR_EYE_GUARD_CONTRAST,
	SLR_EYE_GUARD_ADJUST_MAX,
} SLR_EYE_GUARD_ADJUST_INDEX;

typedef enum _SLR_EYE_GUARD_CONTRAST_INDEX{
	SLR_EYE_GUARD_CINTRAST_R,
	SLR_EYE_GUARD_CINTRAST_G,
	SLR_EYE_GUARD_CINTRAST_B,
	SLR_EYE_GUARD_CINTRAST_MAX,
} SLR_EYE_GUARD_CONTRAST_INDEX;

typedef enum _SLR_EYE_GUARD_BRIGHTNESS_INDEX{
	SLR_EYE_GUARD_BRIGHTNESS_R,
	SLR_EYE_GUARD_BRIGHTNESS_G,
	SLR_EYE_GUARD_BRIGHTNESS_B,
	SLR_EYE_GUARD_BRIGHTNESS_MAX,
} SLR_EYE_GUARD_BRIGHTNESS_INDEX;

typedef enum _SCALER_DISP_CHANNEL{
	SLR_MAIN_DISPLAY = 0,
	SLR_SUB_DISPLAY
}SCALER_DISP_CHANNEL;

typedef enum _SCALER_DISP_NUM{
	_CHANNEL1 = 0,
	_CHANNEL2
}SCALER_CHANNEL_NUM;

/**
 * SLR_YCbCrFMT enumerates the YCbCr Chroma Format.
 */
typedef enum {
	SLR_YCBCR_420,			///< YCbCr 4:2:0
	SLR_YCBCR_422,			///< YCbCr 4:2:2
	SLR_YCBCR_444			///< YCbCr 4:4:4
} SLR_YCBCRFMT;

/**
 * VODMA_DDOMAIN_CHROMA_FMT enumerates the VO Chroma Format.
 */
typedef enum
{
	FMT_444 = 0,
	FMT_422,
	FMT_420
} VODMA_DDOMAIN_CHROMA_FMT;


/**
 * SENSIO_INPUT_MUX enumerates the Sensio Input Mux.
 */
typedef enum
{
	INPUT_VO = 0,
	INPUT_HDMI,
} SENSIO_INPUT_MUX;



/**
 * SLR_AFD_TYPE enumerates afd type.	refer to ATSC A53 TableA12
 */
typedef enum {
	SLR_AFD_RESERVE1= 0,
	SLR_AFD_RESERVE2,
	SLR_AFD_BOX_16X9,
	SLR_AFD_BOX_14X9,
	SLR_AFD_BOX_G16X9,
	SLR_AFD_RESERVE3,
	SLR_AFD_RESERVE4,
	SLR_AFD_RESERVE5,
	SLR_AFD_SAME_AS_FRAME,	//same as code frame
	SLR_AFD_4X3,
	SLR_AFD_16X9,
	SLR_AFD_14X9,
	SLR_AFD_RESERVE6,
	SLR_AFD_4X3_SP,			//4:3(with shoot&protect 14:9 center)
	SLR_AFD_16X9_SP,		//16:9(with shoot&protect 14:9 center)
	SLR_AFD_16X9_SP_4X3,	//16:9(with shoot&protect 4:3 center)
} SLR_AFD_TYPE;

/**
 * SLR_WSS_TYPE enumerates wss type.
 */
typedef enum {
	SLR_WSS_RESERVE1= 0,
	SLR_WSS_BOX_14X9,      //box 14:9 centre
	SLR_WSS_BOX_14X9_TOP,  //box 14:9 top
	SLR_WSS_RESERVE2,
	SLR_WSS_BOX_16X9_TOP,  //box 16:9 top
	SLR_WSS_RESERVE3,
	SLR_WSS_RESERVE4,
	SLR_WSS_16X9,    //7//full format 16:9 (anamorphic)
	SLR_WSS_4X3,	  //8 full format 4:3
	SLR_WSS_RESERVE5,
	SLR_WSS_RESERVE6,
	SLR_WSS_BOX_16X9,//11 box 16:9 centre
	SLR_WSS_RESERVE7,
	SLR_WSS_BOX_G16X9,	//box > 16:9 centre
	SLR_WSS_14X9_SP,	//14:9(with shoot&protect 14:9 center)
	SLR_WSS_RESERVE8,
} SLR_WSS_TYPE;

enum VO_VIDEO_PLANE {
	VO_VIDEO_PLANE_V1 = 0,
	VO_VIDEO_PLANE_V2 = 1,
	VO_VIDEO_PLANE_V3 = 2,
	VO_VIDEO_PLANE_SUB1 = 3,
	VO_VIDEO_PLANE_NONE = 255,
};
typedef enum VO_VIDEO_PLANE VO_VIDEO_PLANE;

enum VO_3D_MODE_TYPE {
	VO_2D_MODE = 0,
	VO_3D_SIDE_BY_SIDE_HALF = 0 + 1,
	VO_3D_TOP_AND_BOTTOM = 0 + 2,
	VO_3D_FRAME_PACKING = 0 + 3,
	VO_3D_LINE_BY_LINE = 0 + 4,
	VO_3D_VERTICAL_STRIPE = 0 + 5,
	VO_3D_CHECKER_BOARD = 0 + 6,
	VO_3D_REALID = 0 + 7,
	VO_3D_SENSIO = 0 + 8,
	VO_3D_AUTO = 0 + 9,
	VO_3D_MVC_SBS = 0 + 10,
};
typedef enum VO_3D_MODE_TYPE VO_3D_MODE_TYPE;

enum VO_FORCE2D_MODE {
	VO_FORCE2D_DISABLE = 0,
	VO_FORCE2D_LEFT = 0 + 1,
	VO_FORCE2D_RIGHT = 0 + 2,
};
typedef enum VO_FORCE2D_MODE VO_FORCE2D_MODE;


/* types for image orientations */
typedef enum _DIRECT_VO_FRAME_ORIENTATION
{
  DIRECT_VO_FRAME_ORIENTATION_ROTATE_0 = 0x00,
  DIRECT_VO_FRAME_ORIENTATION_ROTATE_90 = 0x01,
  DIRECT_VO_FRAME_ORIENTATION_ROTATE_180 = 0x02,
  DIRECT_VO_FRAME_ORIENTATION_ROTATE_270 = 0x03,
  DIRECT_VO_FRAME_ORIENTATION_FLIP_ROTATE_0 = 0x04,
  DIRECT_VO_FRAME_ORIENTATION_FLIP_ROTATE_90 = 0x05,
  DIRECT_VO_FRAME_ORIENTATION_FLIP_ROTATE_180 = 0x06,
  DIRECT_VO_FRAME_ORIENTATION_FLIP_ROTATE_270 = 0x07,
  DIRECT_VO_FRAME_ORIENTATION_DEFAULT = 0x08,
} DIRECT_VO_FRAME_ORIENTATION;


/**
 * VO Info for scaler
 */
typedef struct _SLR_VOINFO {
	VO_VIDEO_PLANE						plane;			///< vo plane
	unsigned int						port;			///< vsc port
	unsigned int						mode;			///< current mode
	unsigned int						h_start;		///< horizontal start
	unsigned int						v_start;		///< veritical start
	unsigned int						h_width;		///< horizontal size
	unsigned int						v_length;		///< vertical size
	unsigned int						h_total;		///< total horizontal size
	unsigned int						v_total;		///< total horizontal size
	VODMA_DDOMAIN_CHROMA_FMT				chroma_fmt;		///< chroma format
	unsigned int						progressive;		///< progressive or interlace
	unsigned int						h_freq;			///< horizontal frequency
	unsigned int						v_freq;			///< vertical frequency
	unsigned int						pixel_clk;		///< pixel clock
	unsigned int						source;			///< 0) DTV, 1) JPEG, 2)GAME, 3) DirectVO
	unsigned int						isJPEG;			///< 0) VIDEO, 1) JPEG // add for vip temporally, should use ""source" if scaler jpeg flow is fixed
	VO_3D_MODE_TYPE						mode_3d ;		///< 0) 2D, 1) Side-by-side, 2)top and bot, 3) frame packing
	VO_FORCE2D_MODE						force2d ;		///< 0) disable, 1) force left, 2) force right
	unsigned int 						se_pre_width; 		//FixedME clamp for AP side
	unsigned int 						se_pre_height;
	unsigned int						set_se_blank;
	unsigned int 						src_h_wid;      	///< added for tcl api to keep original src_size
	unsigned int 						src_v_len;	   	///< added for tcl api to keep original src_size without crop
	unsigned int						video_full_range_flag;
	unsigned int						xvYCC;          	///< xvYCC color space
	unsigned int						MaxCLL;
	unsigned int						MaxFALL;
	unsigned int						security;		///< information for security
	unsigned int						vdec_source;
	unsigned int						colorspace;
	unsigned int						lowdelay;		///<vo lowdelay mode
	unsigned int						isVP9;			//for VP9 source, mdomain go 8bit,and vo don't overscan for fs
    	DIRECT_VO_FRAME_ORIENTATION         screenRotation; // types for image orientations
	unsigned int color_transf;
	unsigned int coeffs_overscan;
	unsigned int dispXY0;
	unsigned int dispXY1;
	unsigned int dispXY2;
	unsigned int whitePointXY;
	unsigned int maxL;
	unsigned int minL;

	/*
	HDR item need to keep latest item for seamless case @Crixus 20170215
	*/
	unsigned int						transfer_characteristics;	///< information for xvYCC/HDR content
	unsigned int						matrix_coefficiets;	///< information for HDR content
	unsigned int						colour_primaries;	///< information for HDR content
	unsigned int						DolbyVision;

	// keep "launcher" last for avoid compare in equal timing decesion (Scaler_DO_VO_timing_Equal())
	unsigned int						i_ratio;		///< aspect ratio of input source, 1) 4:3, 0) 16:9 (use panel's definition)
	SLR_AFD_TYPE						afd;			///< active format description
	unsigned int						pixelAR_hor;		///< pixel aspect ratio - horizontal
	unsigned int						pixelAR_ver;		///< pixel aspect ratio - vertical
	unsigned int						launcher;		///< 0) VO, 1) scaler request, keep last for avoid compare in equal timing decesion
} SLR_VOINFO;
typedef enum
{
	SOURCE_VIDEO = 0,
	SOURCE_JPEG,
	SOURCE_GAME,
	SOURCE_DIRECTVO,
	SOURCE_ENCODER,
} VO_SOURCE_TYPE_INFO;

// oliver-


/**
 * 3D Detect Info for scaler
 */
typedef struct _SLR_3DDETECTINFO {
	VO_3D_MODE_TYPE						mode_3d ;		///< 0) 2D, 1) Side-by-side, 2)top and bot, 3) frame packing
	unsigned int						depth;			///< depth
} SLR_3DDETECTINFO;


typedef enum
{
	VODMA_DEFAULT_MODE = 0,
	VODMA_858x525_720x480_60I,
	VODMA_858x525_720x480_60P,
	VODMA_864x625_720x576_50I,
	VODMA_864x625_720x576_50P,
	VODMA_1980x750_1280x720_50P,
	VODMA_1650x750_1280x720_60P,
	VODMA_2640x1125_1920x1080_50I,
	VODMA_2200x1125_1920x1080_60I,
	VODMA_2640x1125_1920x1080_50P,
	VODMA_2200x1125_1920x1080_60P,
	VODMA_4120x2192_3840x2160_30I,
	VODMA_4120x2192_3840x2160_30P,
	VODMA_MODE_NUM
} VODMA_MODE ;


typedef enum
{
	SCALER_VO_AR_ORIGINAL = 0,			// change back to original size
	SCALER_VO_AR_16_9_1080I_BBY_ZOOM,	// panel16:9, 1080I, BBY NORMAL zoom mode
	SCALER_VO_AR_16_9_1080I_BBY_CINEMA,// panel 16:9, 1080I, BBY WIDE 2 zoom mode
	SCALER_VO_AR_16_9_AUTO_AFD,		// panel 16:9, follow AFD under auto mode
	SCALER_VO_AR_16_9_PERSON,	// panel 16:9, person mode
	SCALER_VO_AR_16_9_CAPTION,// panel 16:9, caption mode
	SCALER_VO_AR_16_9_MOVIE,		// panel 16:9, movie mode
	SCALER_VO_AR_16_9_ZOOM, 	// panel 16:9, zoom mode
	SCALER_VO_AR_16_9_ZOOM2,		// panel 16:9, zoom2 mode
	SCALER_VO_AR_16_9_ZOOM3,		// panel 16:9, zoom3 mode,
	SCALER_VO_AR_16_9_CUSTOMER, 	// panel 16:9, customer mode
	SCALER_VO_AR_16_9_CUSTOMER2,   //panel 16:9 , cutomer mode for tcl api rika 20140919
} SCALER_VO_ASPECT_RATIO;		// aspect ratio which needs VO's help


typedef struct _SLR_VO_Shift_Window {
	 int						shift_h;			///< current mode
	 int						shift_w;		///< horizontal start
	 int						shift_v;		///< veritical start
	 int						shift_l;		///< horizontal size
} SLR_VO_Shift_Window;


//#else

/**
 * SLR_ASPECTRATIO enumerates the aspect ratio.
 */
typedef enum {
	/// Reserved
	SLR_RATIO_RESERVED,
	/// Square pixel
	SLR_RATIO_1x1,
	/// 4x3 Narrow Screen
	SLR_RATIO_4x3,
	/// 16x9 Wide Screen
	SLR_RATIO_16x9,
	/// 2.21x1
	SLR_RATIO_221x1,
	/// PAL
	SLR_RATIO_PAL,
	/// NULL, Unknown
	SLR_RATIO_NULL
} SLR_ASPECTRATIO;

/**
 * SLR_FRAMERATE enumerates the frame rate.
 */
typedef enum {
	SLR_FR_FORBIDDEN,		///< forbidden
	SLR_FR_24_1P001,		///< 24/1.001
	SLR_FR_24,				///< 24
	SLR_FR_25,				///< 25
	SLR_FR_30_1P001,		///< 30/1.001
	SLR_FR_30,				///< 30
	SLR_FR_50,				///< 50
	SLR_FR_60_1P001,		///< 60/1.001
	SLR_FR_60,				///< 60
	SLR_FR_NULL			///< NULL, Unknown
} SLR_FRAMERATE;

/**
 * MVD Info for scaler
 */
typedef struct _SLR_MVDINFO {
	unsigned int			mode_curr;			///< current mode
	unsigned int			horizontal_start;		///< horizontal start
	unsigned int			vertical_start;		///< veritical start
	unsigned int			horizontal_size;		///< horizontal size
	unsigned int			vertical_size;			///< vertical size
	unsigned int			horizontal_size_ori;	///< original horz size
	unsigned int			vertical_size_ori;		///< original vert size
	unsigned int			horizontal_total;		///< total horz size
	SLR_ASPECTRATIO	ar;					///< Aspect Ratio
	SLR_FRAMERATE	fr;					///< Frame Rate
	SLR_YCBCRFMT	yFmt;				///< Chroma Format
	int			progressive;			///< progressive or interlace

/*
	unsigned char			mode_curr;			///< current mode
	unsigned short			horizontal_start;		///< horizontal start
	unsigned short			vertical_start;		///< veritical start
	unsigned short			horizontal_size;		///< horizontal size
	unsigned short			vertical_size;			///< vertical size
	unsigned short			horizontal_size_ori;	///< original horz size
	unsigned short			vertical_size_ori;		///< original vert size
	unsigned short			horizontal_total;		///< total horz size
	SLR_ASPECTRATIO	ar;					///< Aspect Ratio
	SLR_FRAMERATE	fr;					///< Frame Rate
	SLR_YCBCRFMT	yFmt;				///< Chroma Format
	int			progressive;			///< progressive or interlace
*/
} SLR_MVDINFO;

// oliver-
//#endif // NEW_VOINFO_INTERFACE

// From scalerMemory.h
typedef struct _SCALERDRV_ALLOCBUFFER_INFO {
	unsigned int normal_mem_addr;
	unsigned int normal_mem_size;
	unsigned int optimize_mem_addr;
	unsigned int optimize_mem_size;
}SCALERDRV_ALLOCBUFFER_INFO;

// From scalerMemory.h
typedef struct _SCALERDRV_DOUBLEBUF_INFO {
	unsigned int MEMIDX_MAIN_ADDR;
	unsigned int MEMIDX_MAIN_SEC_ADDR;
}SCALERDRV_DOUBLEBUF_INFO;


// From scalerMemory.h
typedef struct _KB_Param
{
	unsigned int x;  //h start
	unsigned int y;  //v start
	unsigned int w;  //width
	unsigned int l;   //len
	unsigned int xphase;
	unsigned int yphase;
	unsigned int wphase;
	unsigned int lphase;
	int x_phase_step; //h step
	int y_phase_step; //v step
	int w_phase_step;  //width step
	int l_phase_step;   //len step
	unsigned int dstx;
	unsigned int dsty;
	unsigned int min_w;
	unsigned int min_l;
	unsigned int max_w;
	unsigned int max_l;
} KB_Param;


// From scalerVBI.h
typedef struct _TTX_VBI_IOCTL_PARAM
{
	unsigned int mode;
	unsigned int data;
}TTX_VBI_IOCTL_PARAM;

// From scalerVBI.h
typedef enum
{
    VBI_MODE_NONE = 0,
    VBI_MODE_CC,
    VBI_MODE_TELETEXT
}VBI_MODE_LIST;

// From scalerVBI.h
typedef struct _VBI_IOCTL_PARAM
{
	VBI_MODE_LIST mode;
	unsigned int cmd;
}VBI_IOCTL_PARAM;

typedef enum
{
    ROTATE_MODE_0 = 0,
    ROTATE_MODE_90,
    ROTATE_MODE_180,
    ROTATE_MODE_270
}ROTATE_MODE_LIST;

typedef struct ROTATE_IOCTL_PARAM
{
	ROTATE_MODE_LIST mode;
	unsigned int cmd;
}ROTATE_IOCTL_PARAM;

typedef struct FRAME_DELAY_IOCTL_PARAM
{
	unsigned int framenumber;
	unsigned int buffersize;
	unsigned int bufferstartaddr;
}FRAME_DELAY_IOCTL_PARAM;

typedef struct FILM_MODE_IOCTL_PARAM
{
	unsigned int fmenable;
	unsigned int buffer4addr;
}FILM_MODE_IOCTL_PARAM;

enum VO_CHROMA_FMT {
	VO_CHROMA_YUV420 = 0,
	VO_CHROMA_YUV422 = 0 + 1,
	VO_CHROMA_YUV444 = 0 + 2,
	VO_CHROMA_ARGB8888 = 0 + 3,
	VO_CHROMA_RGB888 = 0 + 4,
	VO_CHROMA_RGB565 = 0 + 5,
	VO_CHROMA_YUV411 = 0 + 6,
};
typedef enum VO_CHROMA_FMT VO_CHROMA_FMT;


typedef struct HDMI_ROTATE_IOCTL_CONFIG {
	unsigned int width;
	unsigned int height;
	unsigned int framerate;
	unsigned int progressive;
	unsigned int data_bit_width;
	enum VO_CHROMA_FMT chroma_fmt;
	ROTATE_MODE_LIST rotatemode;
}HDMI_ROTATE_IOCTL_CONFIG;

typedef struct SCALER_DISPLAY_WINDOW
{
	unsigned int vo_scaling_enable;
	unsigned int vo_scaling_alloc_mem_enable;
	 //unsigned int	outputx;
	 //unsigned int	outputy;
	unsigned int	outputWidth ;
	unsigned int  outputHeight ;
	unsigned int 	tve_linestep;
	unsigned int tve_vflip_en;
	unsigned int vo_clock_modify;
	unsigned int scart_isr_enable;
} SCALER_DISPLAY_WINDOW ;

typedef enum _VO_DROP_LINE_MODE{
	MODE_2DCVT3D	= (1 << 0),
	MODE_3D_MVC	= (1 << 1),
	MODE_4K2K_VID	= (1 << 2)
}VO_DROP_LINE_MODE;


typedef enum _DISP_MODE{
	_DISP_2D=0,
	_DISP_3D=1,
	_DISP_MODE_NUM=2,
}DISP_MODE;

typedef struct _VO_RATIO_SMOOTH_TOGGLE_INFO {
	unsigned int type;
	unsigned int vo_aspect_ratio_enable;
	unsigned int srcx;     		//x
	unsigned int srcy;     		//y
	unsigned int src_wid;    	//width
	unsigned int src_height;	//height
	unsigned int display;
	unsigned int vo_plane;
} VO_RATIO_SMOOTH_TOGGLE_INFO;

typedef struct _VO_Scaler_State {
	unsigned int type;
	unsigned int state;
	//add overscan size
	unsigned int overscan_x;
	unsigned int overscan_y;
	unsigned int overscan_wid;
	unsigned int overscan_height;

	unsigned int disp_x;     		//x
	unsigned int disp_y;     		//y
	unsigned int disp_wid;    	//width
	unsigned int disp_height;	//height

	unsigned int vo_3d_mode;
	unsigned int display;

	unsigned int NewAdaptiveInputFlag;
} VO_Scaler_State;

typedef struct _VGIP_Overscan_INFO {
	int hratio;
	int vratio;
	int h_start;
	int h_width;
	int v_start;
	int v_length;
	int display;
} VGIP_Overscan_INFO;

typedef struct _Panel_Parameter_INFO {
	unsigned int disp_h_total;
	unsigned int disp_v_total;
	unsigned int disp_clock_max;
	unsigned int disp_clock_min;
	unsigned int disp_clock_typical;
	unsigned int disp_ratio_4x3;
	unsigned int disp_den_start_vpos;
	unsigned int disp_act_start_vpos;
	unsigned int disp_act_end_vpos;
	unsigned int disp_act_start_hpos;
	unsigned int disp_act_end_hpos;
	unsigned int panel_custom_index;
	unsigned int panel_type;
	unsigned int DISPLAY_PORT;
	unsigned int DISPLAY_REFRESH_RATE;
	unsigned int panel_support_3d_display;
	unsigned int panel_3d_line_alternative_support;
	unsigned int panel_3d_PR_outout_LR_swap;
	unsigned int panel_3d_SG_output_120HZ;
	unsigned int panel_3d_SG_24HZ_output_FHD;
	unsigned int panel_3d_PR_to_SG_output_FRC;
	unsigned int lvds_converter_to_HDMI;
	unsigned int panel_vflip;
} Panel_Parameter_INFO;

typedef struct _SCALER_MEMORY_INFO {
	unsigned int DI_addr;
	unsigned int DI_size;
	unsigned int M_main_sec_addr;
	unsigned int M_main_first_addr;
	unsigned int M_main_third_addr;
	//unsigned int M_main_size;
	//sub addr
      unsigned int M_sub_sec_addr;
      unsigned int M_sub_first_addr;
      unsigned int M_sub_third_addr;
} SCALER_MEMORY_INFO;

typedef struct _SMOOTH_TOGGLE_UPDATE_PLANE_INFO{
	unsigned int update_flag;
	unsigned int curr_plane;
}SMOOTH_TOGGLE_UPDATE_PLANE_INFO;

// From scalerInfo.h
typedef struct _SCALER_3D_DISP_INFO {
	unsigned int bIs3dFmt;			// 0:2D, 1:SG, 2:PR, 3:3Dcvt2D
	unsigned int uc3dType;
	unsigned int bEnableDoubleDVS;
	unsigned int uc3dFlow; // will be replaced by uc3dMcapFlow
	unsigned int uc3dMcapFlow; // data frame sync(0), FRC(1)
	unsigned int uc3dMdispFlow;
	unsigned int capWid;
	unsigned int capLen;
	unsigned int bInterlaced;
	unsigned int display_size;
	unsigned int main_addr;
	unsigned int main_sec_addr;
	unsigned int main_third_addr;
	unsigned int sub_addr;
	unsigned int sub_sec_addr;
	unsigned int sub_third_addr;
	unsigned int ucLRsequence;
	unsigned int bIs2Dcvt3D;	// 0: disable(or D-domain 2Dcvt3D mode) 1: enable in SG type 2: enable in PR type
	unsigned int bIs2Dcvt3D_user;	// [2D3D] 2Dcvt3D user mode status
	unsigned int bIs2Dcvt3D_ddMode;	// [2D3D] do 2Dcvt3D in D-Domain (for 1080i bandwidth issue)
	signed int c3dDepth;
	signed int c2Dcvt3dDepth;
	unsigned int ui3dBlkStep;
	unsigned int vgip2_src;	// for 2D cvt 3D mode only
	unsigned int mainSub_freeRun;	// [2D3D] main/sub timing(v-sync) free run
	unsigned int vgip2_vfreq;	// [2D3D] main/sub timing(v-sync) free run
	unsigned int bIsVflip;
	unsigned int ui3dDropLineMode;	// 3D mode which need do vertical decimation
	unsigned int bIsFp1080i;
	unsigned int bIsHdmi4k2k;
} SCALER_3D_DISP_INFO;

typedef struct _SCLAER_ZOOM_INFO{
	//added by rika 20140628
		unsigned int vo_aspect_ratio_enable;

	    int zoom_crop_adj_hpos;     		//x
		int zoom_crop_adj_vpos;     		//y
		int zoom_crop_adj_hsize;    	//width
		int zoom_crop_adj_vsize;	//height

		unsigned int zoom_disp_hpos;	//disp x
		unsigned int zoom_disp_vpos;	//disp y
		unsigned int zoom_disp_hsize;	//width
		unsigned int zoom_disp_vsize;	//height


		//below are added for data fs vo rika 20140912
		unsigned int customerX;
		unsigned int customerY;
		unsigned int customerW;
		unsigned int customerH;


		unsigned int videoPlane;
		unsigned int ScalerARMode;
		unsigned int zoom_fs;//imdSmoothInfo[Smooth_Toggle_dislay].IMD_SMOOTH_FRAMESYNC
		unsigned int source_type;   //0) DTV, 1) JPEG, 2)GAME, 3) DirectVO
		unsigned int curr_smooth_toggle_enable; // 0:go scaler flow;1 go smooth toggle
		unsigned int zoom_func;     // 0:ZOOM_CROP,1:ZOOM_DISP
		unsigned int channel;
		unsigned int overscan_flag;
		unsigned int check_only_xy_shift_change;
		unsigned int drop_v_position;
		unsigned int drop_v_len;
		unsigned int bNewAdaptiveInputFlag;
		//unsigned int disp_h_total;
		//unsigned int disp_v_total;
		//unsigned int disp_clock_max;
		//unsigned int disp_clock_min;
		//unsigned int disp_clock_typical;
		//unsigned int disp_ratio_4x3;
		//unsigned int disp_den_start_vpos;
		//unsigned int disp_act_start_vpos;
		//unsigned int disp_act_end_vpos;
		//unsigned int disp_act_start_hpos;
		//unsigned int disp_act_end_hpos;

}SCALER_ZOOM_INFO;

typedef struct _SCALER_ROTATE_INFO{
	unsigned int width;
	unsigned int height;
	unsigned int rotatemode;
	unsigned int disconnecten;
}SCALER_ROTATE_INFO;

/**
 * package of disp3d_info and src_info in share memory space
 */
typedef struct _SCALER_DISP3DINFO_PKG {
	SCALER_3D_DISP_INFO	disp3d_info;
} SCALER_DISP3DINFO_PKG;

// From modeState.h
enum _MODE_STATE
{
	_MODE_STATE_NONE = 0,						// none state
	_MODE_STATE_SEARCH,						// detect mode
	_MODE_STATE_ACTIVE,						// ative mode to show
	_MODE_STATE_FREEZE,						// freeze
	_MODE_STATE_TV_SCAN,						// tv scan channel
	_MODE_STATE_SHOWSNOW,					// Show snow in TV
};

typedef enum _Histogram_Table_Factor{
	Histogram_Factor_Gain = 0,
	Histogram_Factor_Offset,
	Histogram_Factor_Limit,
	Histogram_Factor_Max,
}Histogram_Table_Factor;


// From scalerColor.h
#define RTNR_Y_C_MAX 11 //20100817 added by Leo Chen

enum ENUM_TVD_INPUT_FORMAT {
	TVD_INFMT_CVBS0_TUNER = 0,
	TVD_INFMT_CVBS1 = 1,
	TVD_INFMT_CVBS2 = 2,
	TVD_INFMT_SVIDEO0 = 3,
	TVD_INFMT_SVIDEO1 = 4,
	TVD_INFMT_YPbPr0 = 5,
	TVD_INFMT_YPbPr1 = 6,
	TVD_INFMT_SCART = 7,
	TVD_INFMT_YPbPrM = 8,
	TVD_INFMT_SCART_CVBS = 9,
	TVD_INFMT_SCART_RGB = 10,
	TVD_INFMT_YPbPr2 = 11,
	TVD_INFMT_YPbPr3 = 12,
	TVD_INFMT_HDMI0 = 13,
	TVD_INFMT_HDMI1 = 14,
	TVD_INFMT_HDMI2 = 15,
	TVD_INFMT_HDMI3 = 16,
	TVD_INFMT_VGA0 = 17,
	TVD_INFMT_VGA1 = 18,
	TVD_INFMT_VODMA0 = 19,
	TVD_INFMT_VODMA1 = 20,
	TVD_INFMT_OSD0 = 21,
};
typedef enum ENUM_TVD_INPUT_FORMAT ENUM_TVD_INPUT_FORMAT;


// From scalerStruct.h
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

// From scalerStruct.h
typedef struct _StructDisplayInfo{
	unsigned char 	channel;
	unsigned char 	input_src; 	///!  input source of this display
	unsigned char	osd_input_src;	// for seperating driver & ui input source
	unsigned char	nShowMpType;
	unsigned short 	state; 		///! the state of this display (Search, Active ...)
	unsigned short 	disp_status; 		///! the status of this display
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
	unsigned char 	data_array_index;
	unsigned char 	display;
	unsigned char	IsBlock;//for vchip
	unsigned char IPV_DLY_PRE;
	unsigned short INPUT_ADC_CLOCK;
	unsigned short IPH_SMARTFIT_START;//for keep smart fit ms Hstart
	unsigned short IPV_SMARTFIT_START;//for keep smart fit ms Vstart

	unsigned short IPH_ACT_STA_PRE;     //x
	unsigned short IPV_ACT_STA_PRE;     //y
	unsigned short IPH_ACT_WID_PRE;    //
	unsigned short IPV_ACT_LEN_PRE;

	unsigned short IPH_ACT_STA;     //x
	unsigned short IPV_ACT_STA;     //y
	unsigned short IPH_ACT_WID;    //
	unsigned short IPV_ACT_LEN;
	unsigned char ScaleOption;		///! scaling-related parameters
						// bit0: 1 - vertical up, 0 - not vertical up
						// bit1: 1 - vertical down, 0 - not vertical down
						// bit2: 1 - horizontal up, 0 - not horizontal up
						// bit3: 1 - horizontal down, 0 - not horizontal down
	unsigned short Hsync;
	unsigned short Vsync;
	unsigned short CapWid;			///! capture window width
	unsigned short CapLen;			///! capture window length
	unsigned short MEM_ACT_HSTA;	// the active start x-pixle of FIFO output in M-domain
	unsigned short MEM_ACT_VSTA;	// the active start y-pixle of FIFO output in M-domain
	unsigned short MEM_ACT_WID;    // the active width of FIFO output in M-domain
	unsigned short MEM_ACT_LEN;	// the active length of FIFO output in M-domain
	unsigned short DispWid;			///! display widnow width
	unsigned short DispLen;			///! display window length
	unsigned short DispWid_PRE;			///! display widnow width
	unsigned short DispLen_PRE;			///! display window length
	unsigned char ucMode_Curr;			///! current input mode id (480i 576i ...1080i 1080p...etc.)
	unsigned char ucMode_Table_Index;   ///! current index of the mode table
	unsigned char IAspectRatio;			///! aspect ratio of input source, 1: 4:3, 0: 16:9 (use panel's definition)
	unsigned char ModeSearchCount;
	unsigned char FailureCount;		// Recoder failure count
	unsigned char FailureCountNoSupport;		// Recoder NoSupport failure count
	unsigned char FrameSyncFlag;	//_TRUE: Frame Sync Mode, _FALSE: FRC Mode
	StructSourceInput	*SrcInfo;
	SLR_AFD_TYPE afd;
	SLR_WSS_TYPE wss;

	unsigned char Polarity;  				// BIT0: H Polarity, Bit1: V Polarity
	unsigned short IHFreq;					// Input Horizontal Frequency
	unsigned short IVFreq;					// Input Vertical Frequency
	unsigned short IHTotal;   				// Input Horizontal Total Length
	unsigned short IVTotal;   				// Input Vertical Total Length
	unsigned short IHCount_PRE;   			// Input Horizontal Count from off-line measure
	unsigned short IVCount_PRE;   			// Input Vertical Count from off-line measure
	unsigned short IHSyncPulseCount;  		// Input Horizontal Sync Pulse Count Numbers
	unsigned char  bg_color_r;		// for background color r
	unsigned char  bg_color_g;		// for background color g
	unsigned char  bg_color_b;		// for background color b
	unsigned char  vga_clock_setting;

	unsigned char  color_space;
	unsigned char  color_depth;
	unsigned char  color_imetry;
	unsigned char  through_i3ddma;
	unsigned char  SR_MODE;
	unsigned char  PIXEL_MODE;
	unsigned char  DFRC_ENABLE;
	unsigned short DiWid;			/// di window width
	unsigned short DiLen;			/// di window length
	unsigned char vo_type;			//info from VO_SOURCE_TYPE_INFO
	unsigned char frac_fs_remove_ratio;			//fractional framesync remove ratio
	unsigned char frac_fs_multiple_ratio;		//fractional framesync multiple ratio
	unsigned short dtg_m_v_freq;		//the v_freq of dtg_m
#if 1	//CONFIG_SDNR_CROP
	unsigned short	SDNRH_ACT_STA_PRE;
	unsigned short	SDNRV_ACT_STA_PRE;
	unsigned short	SDNRH_ACT_WID_PRE;
	unsigned short	SDNRV_ACT_LEN_PRE;
	unsigned short	SDNRH_ACT_STA;
	unsigned short	SDNRV_ACT_STA;
	unsigned short	SDNRH_ACT_WID;
	unsigned short	SDNRV_ACT_LEN;
#endif
	unsigned short IVSyncPulseCount;  		// Input Vertical Sync Pulse Count Numbers
	unsigned short IVPolarityIndicator;
}StructDisplayInfo;


typedef struct {	//initialization in scalerstruct.c
	//vsc path
	unsigned char VSC_Device_Init_Done;
	unsigned short main_inputregion_x_pre;
	unsigned short main_inputregion_w_pre;
	unsigned short main_inputregion_x_ori_pre;
	unsigned short main_inputregion_w_ori_pre;
	unsigned char main_check_pre_flag;
	unsigned char OuputDisplayMode;
	unsigned char OutputVencMode;
	unsigned char OutputMemoryMode;
	unsigned char OutputAveMode;
	unsigned char RGB444Mode;
	unsigned char RGB444Mode_change;
	unsigned char DI_low_delay_flag;
	unsigned int main_opensourceID;
	unsigned char main_VO_smoothtoggle_need_presetting;
	unsigned char VscMuteStatus;
	unsigned char Main_AutoRunScaler;
	char Main_Run_Scaler_flag;
	char Main_Output_Set_flag;
	char Main_force_frc_flag;
	char Main_force_frc_fs_flag;
	char Main_Scaler_Stop_flag;
	char Main_Output_Set_flag_Special_Case;
	char Main_Request_ForceBG_ctrl;
	char Main_Reset_Mode_flag;
	unsigned char Main_during_scalerflow_flag;
	unsigned char main_winfreeze;
	unsigned char mainVscFreezeFlag;
	unsigned char subVscFreezeFlag;
	char memc_realcinema_run_flag;
	unsigned char separator_vsc;

	//smooth toggle
	unsigned char check_only_xy_shift_same_region;
	char Main_smooth_toggle_set_flag;
	char Main_SetOutput_request_muteoff_smooth_toggle_set_flag;
	unsigned char JPEG_Scaler_SM;
	unsigned char adaptive_stream;
	unsigned char adaptive_stream_pre;
	unsigned char separator_smoothtoggle;
	//adc
	unsigned char separator_adc;
	//avd
	unsigned char g_ucCheckAVDandWebOSInfoCount;
	unsigned char g_ucVSCCheckATVChanelChange;;
	unsigned char g_ucVSCATVChanelChangeStart;;
	unsigned char g_ucVSCATVSetWinBlankCount;;
	unsigned char g_ucVDCDetectStage;;
	char Main_ATV_Go_Smooth_Toggle_flag;
	char Main_ATV_PassThrought_output_flag;
	unsigned short Main_ATV_InputRegion_x_pre;
	unsigned short Main_ATV_InputRegion_y_pre;
	unsigned short Main_ATV_InputRegion_w_pre;
	unsigned short Main_ATV_InputRegion_h_pre;
	unsigned short Main_ATV_OutputRegion_x_pre;
	unsigned short Main_ATV_OutputRegion_y_pre;
	unsigned short Main_ATV_OutputRegion_w_pre;
	unsigned short Main_ATV_OutputRegion_h_pre;
	char run_iv2dv_slow_tuning_flag;
	unsigned char separator_avd;
	//hdmi
	unsigned char line_cnt_no_run_hdmi_check;
	unsigned char separator_hdmi;

	//HDR
	unsigned char hdmi_dolby_vision_flag;
	unsigned char separator_hdr;

	//Sub path
#ifdef CONFIG_DUAL_CHANNEL
	unsigned int sub_opensourceID;
	unsigned char LivezoomvoinfocheckFlag;/*flag means:main run scaler checkde vo info or not*/
	unsigned char LivezoomMainRerunFlag;/*flag means:main run scaler once for open livezoom and magnifier*/
	unsigned char LivezoomSubRerunFlag;
	unsigned char LivezoomMainRerunEndneedOpenforcebgFlag;/*flag means:main run scaler over when open livezoom and magnifier,need todo open main forcebg*/
	unsigned char LivezoomSubRerunEndneedOpenforcebgFlag;/*flag means:sub run scaler over when open livezoom and magnifier,need todo open sub forcebg*/
	unsigned char magnifier_mainscaler_run_livezoom;/*flag means:main run scaler once for open livezoom and magnifier,no need setting vgip and di*/
	unsigned char DataFramesynclivezoom;/*flag means:store now main run data frame sync or not*/
	unsigned char LivezoomOffKeepMainForceBG;/*flag means:let main re run scaler with forcebg when livezoom and magnifier off*/
	unsigned char multiview_sub_interlace_flag;
	unsigned char Sub_OuputDisplayMode;
	unsigned char Sub_OutputVencMode;
	unsigned char Sub_OutputMemoryMode;
	unsigned char Sub_OutputAveMode;
	char Sub_Run_Scaler_flag;
	char Sub_Output_Set_flag;
	char Sub_Scaler_Stop_flag;
	unsigned char Sub_AutoRunScaler;
	char Sub_ATV_Go_Smooth_Toggle_flag;
	char Sub_Request_ForceBG_ctrl;
	char Sub_Reset_Mode_flag;


	unsigned short Sub_ATV_InputRegion_x_pre;
	unsigned short Sub_ATV_InputRegion_y_pre;
	unsigned short Sub_ATV_InputRegion_w_pre;
	unsigned short Sub_ATV_InputRegion_h_pre;
	unsigned short Sub_ATV_OutputRegion_x_pre;
	unsigned short Sub_ATV_OutputRegion_y_pre;
	unsigned short Sub_ATV_OutputRegion_w_pre;
	unsigned short Sub_ATV_OutputRegion_h_pre;
	unsigned int  sub_zoom_disp_hpos;
	unsigned int  sub_zoom_disp_vpos;
	unsigned int  sub_zoom_disp_hsize;
	unsigned int  sub_zoom_disp_vsize;
	unsigned char sub_wind0000;
	unsigned char separator_sub;
#endif
	//vpq
	unsigned char vpq_ld_first_boot;
	unsigned char separator_vpq;
	//game mode
	unsigned char game_mode_dynamic_flag;
	unsigned char smoothtoggle_start_flag;
	unsigned char rotate_muteoff_request_flag;
	unsigned char rotate_run_scaler_flag;
	unsigned char Main_run_smooth_toggle_from_mute_off;//when mute off and Main_SetOutput_request_muteoff_smooth_toggle_set_flag. means trigger smooth toggle from mute off
	unsigned char dvo_dual_decoder_flag;
	unsigned char dvo_dual_decoder_run;
}__attribute__ ((section ("RTD_DEBUG_STRUCT"))) DEBUG_SCALER_VSC_STRUCT;

// From source.h
enum _SRC_FROM_TYPE {
	_SRC_FROM_ADC = 0x01,
	_SRC_FROM_VDC,
	_SRC_FROM_TMDS,
	_SRC_FROM_VIDEO8,
	_SRC_FROM_VIDMA,
	_SRC_FROM_VO,
	_SRC_FROM_OSD,

#ifdef CONFIG_INPUT_SOURCE_IPG
	_SRC_FROM_IPG,
#endif
};

enum _VO_SRC_FROM{
	VO_FROM_DTV=0x0,
	VO_FROM_JPEG,
	VO_FROM_GAME,
	VO_FROM_MAX,
};


// From source.h
enum _SRC_TYPE {
	_SRC_TV = 0x01,
	_SRC_VO,
	_SRC_CVBS,
	_SRC_SV,
	_SRC_COMPONENT,
	_SRC_SCART,
	_SRC_SCART_RGB,
	_SRC_HDMI,
	_SRC_DVI,
	_SRC_VGA,
	_SRC_YPBPR,
	_SRC_PVR,
	_SRC_VIDEO8,
	_SRC_USB,
	_SRC_WIFI,
	_SRC_DISPLAYPORT,
	_SRC_OSD,

#ifdef CONFIG_INPUT_SOURCE_IPG
	_SRC_IPG,
#endif

	_SRC_MAX,	// don't change this order
};


typedef enum _SLR_DISP_STATUS{
	//moved from scalerstruct.h rika 20141024
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

typedef struct _SCALER_DISP_INFO {
	unsigned int 	input_src; 		///!  input source of this display
	unsigned int	state; 			///! the state of this display (Search, Active ...)
	unsigned int	disp_status;		///! the status of this display
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
	unsigned int	display;			// main (channel 1) or sub (channel 2)
	unsigned int	MEM_ACT_WID;	// the active width of FIFO output in M-domain
	unsigned int	MEM_ACT_LEN;	// the active length of FIFO output in M-domain
	unsigned int	MEM_ACT_HSTA;
	unsigned int    MEM_ACT_VSTA;
	unsigned int	ucMode_Curr;	// 480i, 480p, 576i, 576p, ...etc.
	unsigned int	DispWid;			// display window width
	unsigned int	DispLen;			// display window length
	unsigned int	IVFreq;
	unsigned int	CapWid;
	unsigned int	CapLen;
	unsigned int	IphActWid_Pre;
	unsigned int	IpvActLen_Pre;
	unsigned int	IpvActSTA_H;
	unsigned int	IpvActSTA_V;
	unsigned int	IphActWid_H;
	unsigned int	IpvActLen_V;
	unsigned int	Iph_STA_Pre;//Record h start from main/sub vgip source
	unsigned int	Ipv_STA_Pre;//Record v start from main/sub vgip source
	unsigned int	ui_select_src;//record ui input src. type from enum _SRC_TYPE
	unsigned int	src_h_total;
	unsigned int	src_v_total;
	unsigned int	scaler_source_type;

} SCALER_DISP_INFO;

typedef struct _SCALER_DISPINFO_PKG {
	SCALER_DISP_INFO	disp_info[MAX_DISP_CHANNEL_NUM];
} SCALER_DISPINFO_PKG;

typedef struct _SMOOTH_TOGGLE_DATA_MODE {
	unsigned int display;
	unsigned int data_mode;
} SMOOTH_TOGGLE_DATA_MODE;

typedef struct _VIDEO_RPC_DOLBY_VISION_FRAME_INFO{
    /* Frame info */
    unsigned int isHdmi;			// 0: HDMI mode, 1: Normal mode
    unsigned int picWidth;			// picture width
    unsigned int picLen;				// picture height
    unsigned int picRatioMode;		// 0: 1/4 mode, 1: 1:1 mode

    /* capture buffer */
    unsigned int md_status;			// md_parse error status, 0: OK, B[0]: CRC error, B[1]: size error
    unsigned int md_pts;			// update buffer index time
    unsigned int md_pktSize;		// metadata body size
    unsigned int md_bufPhyAddr;	// metatdata buffer address

    /* HW setting data structure */
    unsigned int parser_status;		// metadata parse result [TBD]
    unsigned int parser_pts;			// metadata parse finish time [TDB]
    unsigned int parser_dm_setting;	// data structure of DM HW setting [TBD]
    unsigned int parser_composer_setting; // data structure of Composer HW setting [TBD]
}VIDEO_RPC_DOLBY_VISION_FRAME_INFO;



/** The shared memory definition */
typedef struct _VIDEO_RPC_DOBLBY_VISION_SHM {
    unsigned int picQWr;
    unsigned int picQRd;
    VIDEO_RPC_DOLBY_VISION_FRAME_INFO frameInfo[16];
}VIDEO_RPC_DOBLBY_VISION_SHM;

typedef struct _VIDEO_RPC_VO_OVERSCAN_INFO {
    unsigned int plane;
    unsigned int vo_source;
    unsigned int vo_overscan_enable;
    unsigned int input_x;
    unsigned int input_y;
    unsigned int input_w;
    unsigned int input_h;
}VIDEO_RPC_VO_OVERSCAN_INFO;

typedef struct _SMOOTH_TOGGLE_UPDATE_INFO {
	unsigned int IMD_SMOOTH_H_ACT_WID_PRE;	 //voinfo size
	unsigned int IMD_SMOOTH_V_ACT_LEN_PRE; 	//voinfo size
	unsigned int IMD_SMOOTH_H_ACT_STA_PRE;		//voinfo size
	unsigned int IMD_SMOOTH_V_ACT_STA_PRE;		//voinfo size
	unsigned int IMD_SMOOTH_H_ACT_WID;   //webos inputregion size
	unsigned int IMD_SMOOTH_H_ACT_STA;	 //webos inputregion size
	unsigned int IMD_SMOOTH_V_ACT_LEN;	 //webos inputregion size
	unsigned int IMD_SMOOTH_V_ACT_STA;	 //webos inputregion size
	unsigned int IMD_SMOOTH_CapWid;			///! capture window width
	unsigned int IMD_SMOOTH_CapLen;			///! capture window length
	unsigned int IMD_SMOOTH_DI_WID;		//di input wid
	unsigned int IMD_SMOOTH_DI_LEN;		//di input LEN
	unsigned int IMD_SMOOTH_MEM_ACT_HSTA;	// the active start x-pixle of FIFO output in M-domain
	unsigned int IMD_SMOOTH_MEM_ACT_VSTA;	// the active start y-pixle of FIFO output in M-domain
	unsigned int IMD_SMOOTH_MEM_ACT_WID;    // the active width of FIFO output in M-domain
	unsigned int IMD_SMOOTH_MEM_ACT_LEN;	// the active length of FIFO output in M-domain
	unsigned int IMD_SMOOTH_DispWid;			// display window width
	unsigned int IMD_SMOOTH_DispLen;			// display window length
	unsigned int IMD_SMOOTH_H_TOTAL;	//input total(voinfo)
	unsigned int IMD_SMOOTH_V_TOTAL;	//input total(voinfo)
	unsigned int IMD_SMOOTH_SDNR_H_ACT_WID;  //SDNR outputsize -> UZD input
	unsigned int IMD_SMOOTH_SDNR_V_ACT_LEN; //SDNR outputsize -> UZD input
	unsigned int IMD_SMOOTH_SDNR_H_ACT_STA; //sdnr output start
	unsigned int IMD_SMOOTH_SDNR_V_ACT_STA;//sdnr output start
	unsigned int IMD_SMOOTH_FRAMESYNC;
	unsigned int IMD_SMOOTH_H_SCALE_DOWN;
	unsigned int IMD_SMOOTH_V_SCALE_DOWN;
	unsigned int IMD_SMOOTH_H_SCALE_UP;
	unsigned int IMD_SMOOTH_V_SCALE_UP;
	unsigned int IMD_SMOOTH_DISP_RTNR;
	unsigned int IMD_SMOOTH_V_UZD_BUFFER_MODE;
	unsigned int IMD_SMOOTH_DISP_422;
	unsigned int IMD_SMOOTH_DISP_422CAP;
	unsigned int IMD_SMOOTH_DI_CUT_4_LINES;
	unsigned int IMD_SMOOTH_DISP_THRIP;
	unsigned int IMD_SMOOTH_MODE_CURR;
	unsigned int IMD_SMOOTH_DISP_10BIT;
	unsigned int IMD_SMOOTH_DISP_INTERLACE;
	unsigned int IMD_SMOOTH_V_FREQ;
	unsigned int IMD_SMOOTH_H_FREQ;
	unsigned int IMD_SMOOTH_VFLIP;
	unsigned int IMD_SMOOTH_INPUT_AFD;
	unsigned int IMD_SMOOTH_DISP_MA3A;
	unsigned int IMD_SMOOTH_DISP_VFLIP3;
	unsigned int IMD_SMOOTH_SOURCE_TYPE;
	unsigned int IMD_SMOOTH_INPUT_THROUGH_I3DDMA;
	unsigned int IMD_SMOOTH_DI_RTNR_FORCE_2D;
	unsigned int IMD_SMOOTH_DI_SWITH;//timing from di/rtnr to non-di/rtnr or non-di/rtnr to di/rtnr would set 1
} SMOOTH_TOGGLE_UPDATE_INFO;

typedef struct SMOOTH_TOGGLE_UPDATE_FW_INFO{
	unsigned int update_flag;
	unsigned int smoooth_toggle_enable;
	unsigned int vodma_plane;
	unsigned int done_flag;
	SMOOTH_TOGGLE_UPDATE_INFO smooth_toggle_info;
}SMOOTH_TOGGLE_UPDATE_FW_INFO;

typedef struct _SMOOTH_TOGGLE_UPDATE_FWINFO_PKG{
	SMOOTH_TOGGLE_UPDATE_FW_INFO sm_info[MAX_DISP_CHANNEL_NUM];
}SMOOTH_TOGGLE_UPDATE_FWINFO_PKG;

// From scalerVBI.h
typedef enum
{
    // === scalerVIP.c ===
       HIST_CNT_MEM_IDX,
      // SMARTPIC_CLUS_IDX,
       RPC_SMARTPIC_CLUS_IDX,
       HIST_CNT_SUB_MEM_IDX,
       EMF_COEF_MEM_IDX,
	DCR_TABLE_MEM_IDX,

    // === scalerMemory.c ===
	MEM_TAG_MEM_IDX,

    // === scalerVO.c ===
	VO_INFO_MEM_IDX,
	MVD_INFO_MEM_IDX,

	INFO_3DDETECT_MEM_IDX,

    // === scalerIRQ.c ===
	JPEG_CTRL_MEM_IDX,
	KB_INFO_MEM_IDX,

	// HDR Dolby Vision
	 HDR_DV_HDMI_INFO_MEM_IDX,
	 HDR_DV_OTT_INFO_MEM_IDX,
	VO_SMOOTH_TOGGLE_IDX,
	VO_SMOOTH_TOGGLE_SHAREMEM_SYNC_IDX,//This is for smooth toggle share memory sync flag
	VO_SMOOTH_TOGGLE_SHIFTXY_SHAREMEM_SYNC_IDX,
	VO_RUN_SCALER_IDX,
	DM_CONNECT_FLAG_IDX,
	I3DDMA_CHANGE_SHAREMEM_SYNC_IDX,
	VBI_SHAREMEM_DATA_IDX,
	//Dump register
	SCALERIOC_DUMP_REGISTER_COUNTER_IDX,
	//SCALERIOC_DUMP_REGISTER_INFO_IDX,
	 RPC_SHARE_MEM_INDEX_MAX,


}SCALER_RPC_SHARE_MEM_INDEX;



// From source.h
#define GET_SOURCE_TYPE(src_type)			(((src_type>>8) & 0xff))

#define RPC_SEND_VALUE_ONLY 1

unsigned int Scaler_VGIPInit(void);
unsigned int Scaler_VGIPISR(unsigned int vector, unsigned int data);
//unsigned int Scaler_VGIPDSR();
void Scaler_VGIPDSR(unsigned int vector, unsigned int count, unsigned int data);

// From scalerVBI.h
#define MVD_SUBTITLE_BUF_SIZE 		(10*1024)  ///< Buffer size

typedef struct _MVD_SUBTITLE_BUF {
	unsigned int	tpMod;							///< 0=first TP, 1=second TP (initial: 0xFF)
	unsigned int	aspectRatio;					///< 0=16:9, 1=4:
	unsigned int	wPtr;							///< write_pointer
	unsigned int	rPtr;							///< read_pointer
	unsigned int	overflowFlag;					///< overflow_flag
	unsigned int	sData;							///< array to store subtitle data.
	unsigned int	res;                            ///< reserved_bits
	unsigned int	applied;						///< new settings have been latched
} MVD_SUBTITLE_BUF;

#define VBI_TTX_RING_BUF            1

#define VBI_TTX_DMA_WIDTH			(64) // 64 bytes
#define VBI_TTX_DMA_LENGTH			(21) // 21 lines, 6~26
#define VBI_TTX_DMA_LENGTH_ALIGN	(24) // 24 lines, because we need 256 alignment (24*64=6*4*64=6*256)
#define VBI_TTX_BUF_LENGTH			(VBI_TTX_DMA_LENGTH*10) // 10 * 21 lines

#define PPR_PTNGEN_PKT_LEN_BYTES	(47)	// Pattern Generator data length in bytes (including preamble bytes), please sync with ppr.h

typedef enum
{
    VBI_GET_SIGNAL,
    VBI_READ_ERROR_STATUS,
    VBI_RESET_ERROR_STATUS,
    VBI_SET_HIGH_LEVEL,
    VBI_SET_TT_HIGH_LEVEL,
    VBI_GET_TT_HIGH_LEVEL,
    VBI_GET_TT_HIGH_LEVEL_IIR,
    VBI_SET_WSS_HIGH_LEVEL,
    VBI_SET_CLAMP_DGAIN,
    VBI_FIX_SLICER_LEVEL,
    VBI_SET_SLICER_LEVEL_MODE,
    VBI_GET_SLICER_LEVEL_MODE,
    VBI_SET_VPS_TRIAL_START,
    VBI_TTX_DUMP_2_USB_START,
    VBI_TTX_DUMP_2_USB_STOP,
    VBI_TTX_DUMP_2_USB_GETSIZE,
} TTX_VBI_CMDLIST;

#define TTX_SLICER_PACKET_SIZE  (42)   //42bytes for a packet
#define PPR_FIELD_BUFF_PKT_NUM  (210)

#define VBI_VPS_BUF_LENGTH   (600)
#define VBI_VPS_FRAME_BYTES    (13)

#define VBI_CC_BUF_LENGTH   (1024)
#define VBI_CC_FRAME_BYTES    (3)

typedef enum
{
	CGMS_CVBS_NTSC=0,
	CGMS_YPBPR_480i,
	CGMS_YPBPR_480p,
	CGMS_YPBPR_720p,
	CGMS_YPBPR_1080i,
}CGMS_SOURCE;

typedef struct _VBI_CGMS_PARAM
{
	CGMS_SOURCE source;
	unsigned int enable;
}VBI_CGMS_PARAM;

typedef enum VSC_INPUT_TYPE
{
	VSC_INPUTSRC_AVD = 0,
	VSC_INPUTSRC_ADC,
	VSC_INPUTSRC_HDMI,
	VSC_INPUTSRC_VDEC,
	VSC_INPUTSRC_JPEG,
	VSC_INPUTSRC_MAX = VSC_INPUTSRC_JPEG,
	VSC_INPUTSRC_MAXN,
} VSC_INPUT_TYPE_T;

//Evance@20160721 add for Magnifier rect
typedef enum VSC_SUB_SHAPE
{
	VSC_MGF_TYPE_CIRCLE = 0,
	VSC_MGF_TYPE_RECTANGLE,
	VSC_MGF_TYPE_MAX = VSC_MGF_TYPE_RECTANGLE,
	VSC_MGF_TYPE_MAXN,
} VSC_SUB_SHAPE_T;




/*
- PIP: Live zoom, magnifire
- PBP: Multiview
- default mode is pip
*/
typedef enum VSC_SUB_MODE
{
	VSC_SUB_MODE_PIP,
	VSC_SUB_MODE_PBP,
	VSC_SUB_MODE_MAX = VSC_SUB_MODE_PBP,
	VSC_SUB_MODE_MAXN
} VSC_SUB_MODE_T;

unsigned char Get_DisplayMode_Port(unsigned char display);
VSC_INPUT_TYPE_T Get_DisplayMode_Src(unsigned char display);
VSC_SUB_MODE_T get_sub_mode(void);//Get current sub mode
VSC_SUB_SHAPE_T get_shape_mode(void);//Get current sub mode

#endif

