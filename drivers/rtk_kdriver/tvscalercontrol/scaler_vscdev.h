#ifndef __VSC_H
#define  __VSC_H

/*-----------------------------------------------------------------------------
	Macro Definitions
------------------------------------------------------------------------------*/
#if !defined(BIT0) && !defined(BIT1)
#define		BIT0		0x00000001
#define		BIT1		0x00000002
#define		BIT2		0x00000004
#define		BIT3		0x00000008
#define		BIT4		0x00000010
#define		BIT5		0x00000020
#define		BIT6		0x00000040
#define		BIT7		0x00000080
#define		BIT8		0x00000100
#endif

#define AVD_DI_5A_WIDTH 960
#define AVD_27M_VGIP_WIDTH 1440
#define AVD_NORMAL_WIDTH 720


#define FRC_MUTE_MASK (BIT7)
#define VIDEO_DDI_RECT_T VIDEO_RECT_T

//Frame delay boundary
#define MODE_480I_FRAME_DELAY_LOWER_BOUNDARY 	0
#define MODE_480I_FRAME_DELAY_UPPER_BOUNDARY 	65
#define MODE_576I_FRAME_DELAY_LOWER_BOUNDARY 	0
#define MODE_576I_FRAME_DELAY_UPPER_BOUNDARY 	64
#define MODE_480P_FRAME_DELAY_LOWER_BOUNDARY 	0
#define MODE_480P_FRAME_DELAY_UPPER_BOUNDARY 	78
#define MODE_576P_FRAME_DELAY_LOWER_BOUNDARY 	0
#define MODE_576P_FRAME_DELAY_UPPER_BOUNDARY 	46
#define MODE_720P50_FRAME_DELAY_LOWER_BOUNDARY 	0
#define MODE_720P50_FRAME_DELAY_UPPER_BOUNDARY 	98
#define MODE_720P60_FRAME_DELAY_LOWER_BOUNDARY 	0
#define MODE_720P60_FRAME_DELAY_UPPER_BOUNDARY 	30
#define MODE_1080P24_FRAME_DELAY_LOWER_BOUNDARY 0
#define MODE_1080P24_FRAME_DELAY_UPPER_BOUNDARY 30
#define MODE_1080P30_FRAME_DELAY_LOWER_BOUNDARY 540
#define MODE_1080P30_FRAME_DELAY_UPPER_BOUNDARY 600
#define MODE_1080P30_FRAME_DELAY_LOWER_BOUNDARY_60HZ_PANEL 270
#define MODE_1080P30_FRAME_DELAY_UPPER_BOUNDARY_60HZ_PANEL 300
#define MODE_1080P50_FRAME_DELAY_LOWER_BOUNDARY 0
#define MODE_1080P50_FRAME_DELAY_UPPER_BOUNDARY 30
#define MODE_1080P60_FRAME_DELAY_LOWER_BOUNDARY 0
#define MODE_1080P60_FRAME_DELAY_UPPER_BOUNDARY 30
#define MODE_1080I50_FRAME_DELAY_LOWER_BOUNDARY 0
#define MODE_1080I50_FRAME_DELAY_UPPER_BOUNDARY 30
#define MODE_1080I60_FRAME_DELAY_LOWER_BOUNDARY 0
#define MODE_1080I60_FRAME_DELAY_UPPER_BOUNDARY 30
#define MODE_4K2K24_FRAME_DELAY_LOWER_BOUNDARY 	1620
#define MODE_4K2K24_FRAME_DELAY_UPPER_BOUNDARY 	2160
#define MODE_4K2K30_FRAME_DELAY_LOWER_BOUNDARY 	1620
#define MODE_4K2K30_FRAME_DELAY_UPPER_BOUNDARY 	2160
#define MODE_4K2K50_FRAME_DELAY_LOWER_BOUNDARY 	1080
#define MODE_4K2K50_FRAME_DELAY_UPPER_BOUNDARY 	1142
#define MODE_4K2K60_FRAME_DELAY_LOWER_BOUNDARY 	1080
#define MODE_4K2K60_FRAME_DELAY_UPPER_BOUNDARY 	1142



#if (CONFIG_ARCH_RTK284X)
#define	REDUCE_DI_WIDTH_LIMIT_THRESHOLD		1920
#else
#define	REDUCE_DI_WIDTH_LIMIT_THRESHOLD		4096
#endif


/**
 * Video Window Rect.
 *
 * @see DDI Implementation Guide
*/
#ifndef VIDEO_WID_T
		typedef enum
		{
			VIDEO_WID_MIN	= 0,				/**< WID min */
			VIDEO_WID_0 	= VIDEO_WID_MIN,	/**< WID main window */
			VIDEO_WID_1,						/**< WID sub window */
			VIDEO_WID_2,
			VIDEO_WID_3,
			VIDEO_WID_MAX	= VIDEO_WID_3,		/**< WID max */
			VIDEO_WID_MAXN, 					/**< WID max number */
		} __VIDEO_WID_T;
#define VIDEO_WID_T __VIDEO_WID_T
#endif
	/**
	 * Video Window Rect.
	 *
	 * @see DDI Implementation Guide
	*/
#ifndef VIDEO_RECT_T
	typedef struct
	{
		unsigned short		x;	/**< horizontal Start Position in pixel [0,].*/
		unsigned short		y;	/**< vertical	Start Position in pixel [0,].*/
		unsigned short		w;	/**< horizontal Size(Width)    in pixel [0,].*/
		unsigned short		h;	/**< vertical	Size(Height)   in pixel [0,].*/
	} __VIDEO_RECT_T;
#define VIDEO_RECT_T __VIDEO_RECT_T
#endif

//Evance
typedef struct VSC_SUB_SHAPE_INFO{
	VSC_SUB_SHAPE_T shapeinfo;
	VIDEO_RECT_T rect;

}VSC_SUB_SHAPE_INFO_T;



typedef struct VSC_INPUT_SRC_INFO
{
	VSC_INPUT_TYPE_T type;
	unsigned char attr;
	unsigned char resourceIndex;
} VSC_INPUT_SRC_INFO_T;

/**
 * Scaler Output Mode.
 *
 * @see HAL Implementation Guide
*/
typedef enum VSC_OUTPUT_MODE
{
	VSC_OUTPUT_DISPLAY_MODE = 0,
	VSC_OUTPUT_VENC_MODE,
	VSC_OUTPUT_MEMORY_MODE,
	VSC_OUTPUT_AVE_MODE,
	VSC_OUTPUT_MAX = VSC_OUTPUT_AVE_MODE,
	VSC_OUTPUT_MAXN,
} VSC_OUTPUT_MODE_T;
/**
 * Color of Video Window.
 *
 * @see DDI Implementation Guide
*/
typedef enum
{
	VIDEO_DDI_WIN_COLOR_BLACK,		/**< window color black */
	VIDEO_DDI_WIN_COLOR_BLUE,		/**< window color blue */
	VIDEO_DDI_WIN_COLOR_GRAY,		/**< window color gray */
	VIDEO_DDI_WIN_COLOR_RGB_API		/**< window color form RGB API VBE_IOC_SET_FORCEBG_COLOR*/
} VIDEO_DDI_WIN_COLOR_T;

/**
 * Multi Window Mode.
 *
*/
typedef enum
{
	VIDEO_MULTI_WIN_MODE_MIN = 0,
	VIDEO_MULTI_WIN_MODE_OFF = VIDEO_MULTI_WIN_MODE_MIN,
	VIDEO_MULTI_WIN_MODE_PIP,
	VIDEO_MULTI_WIN_MODE_TRANSCODING,
	VIDEO_MULTI_WIN_MODE_2ND_TV,
	VIDEO_MULTI_WIN_MODE_CAPTURE,
	VIDEO_MULTI_WIN_MODE_MAXN,
} VIDEO_MULTI_WIN_MODE_T;

/**
 * Video Input source Information.
 *
 */
typedef struct VIDEO_SRC_INFO
{
	unsigned int	Type:8;		/**< ... */
	unsigned int	Index:8;	/**< ... */
	unsigned int	Attr:8;		/**< ... */
	unsigned int	Resv:8;		/**< ... */
} VIDEO_SRC_INFO_T;

/**
 * Video Pixel format
 *
 */
typedef enum
{
	VIDEO_DDI_PIXEL_FORMAT_RGB10,
	VIDEO_DDI_PIXEL_FORMAT_RGB8,
	VIDEO_DDI_PIXEL_FORMAT_YCBCR444_10,
	VIDEO_DDI_PIXEL_FORMAT_YCBCR444_8,
	VIDEO_DDI_PIXEL_FORMAT_YCBCR422_10,
	VIDEO_DDI_PIXEL_FORMAT_YCBCR422_8,
	VIDEO_DDI_PIXEL_FORMAT_YCBCR420_10,
	VIDEO_DDI_PIXEL_FORMAT_YCBCR420_8,
	VIDEO_DDI_PIXEL_FORMAT_ARGB8,
	VIDEO_DDI_PIXEL_FORMAT_ARGB10,
   	VIDEO_DDI_PIXEL_FORMAT_YCSEPARATED,
}VIDEO_DDI_PIXEL_FORMAT_T;

/**
 * Video Capture Info
 *
 */
	typedef struct
	{
		unsigned short width;
		unsigned short height;
		VIDEO_DDI_PIXEL_FORMAT_T pixelFormat;
		const unsigned char* pData;
		const unsigned char* pCbCr;
		unsigned short* pScanTypeCapImg; // 0:I, 1:P
	}VIDEO_DDI_CAPTURE_INFO_T;


/**
 * 3D Video Full Timing Information.
 *
 * @see DDI Implementation Guide
*/
/*  have to refer timing info, doesn't refer 3D tag or header info */
typedef enum
{
	/*     아래 enum value는 관리 안함.  */
	VIDEO_DDI_3D_FORMAT_2D,					/**< for No 3D (OFF)..... INPUT_TYPE_2DTO3D */

	/*      From UI, 3D ON이면서 아래 Format이 넘어오면 일반 3D ON이 됨.    */
	//interim format - half
	VIDEO_DDI_3D_FORMAT_TOP_BOTTOM,			/**< for T/B, S/S, Checker, Frame Seq...INPUT_TYPE_TOPNBOTTOM*/
	VIDEO_DDI_3D_FORMAT_SIDEBYSIDE_HALF,	/**< for T/B, S/S, Checker, Frame Seq...INPUT_TYPE_SIDEBYSIDE*/
	VIDEO_DDI_3D_FORMAT_CHECKER_BOARD,		/**< for T/B, S/S, Checker, Frame Seq...INPUT_TYPE_CHECKERBOARD*/
	VIDEO_DDI_3D_FORMAT_FRAME_SEQ,			/**< for T/B, S/S, Checker, Frame Seq...INPUT_TYPE_FRAMESEQ*/
	VIDEO_DDI_3D_FORMAT_COLUMN_INTERLEAVE,	/**< for H.264*/
	VIDEO_DDI_3D_FORMAT_LINE_INTERLEAVE_HALF,	/**< for H.264*/

	//Full format
	VIDEO_DDI_3D_FORMAT_FRAME_PACKING,			/**< Full format*/
	VIDEO_DDI_3D_FORMAT_FIELD_ALTERNATIVE,		/**< Full format*/
	VIDEO_DDI_3D_FORMAT_LINE_ALTERNATIVE,		/**< Full format (row interleave)*/
	VIDEO_DDI_3D_FORMAT_SIDEBYSIDE_FULL,		/**< Full format*/
	VIDEO_DDI_3D_FORMAT_DUALSTREAM,		/**< Full format*/
	/*    From UI, 3D ON이면서 아래 Format이 넘어오면 2D to 3D 가 됨    */
	VIDEO_DDI_3D_FORMAT_2DTO3D,					/**< for2D TO  3D..... INPUT_TYPE_2DTO3D */
	VIDEO_DDI_3D_FORMAT_MAX,
}VIDEO_DDI_3D_FORMAT_TYPE_T;

/**
 * 3D Video Full Timing Information.
 *
 * @see DDI Implementation Guide
*/
/*  have to refer timing info, doesn't refer 3D tag or header info */
typedef enum
{
	/*     아래 enum value는 관리 안함.  */
//	VIDEO_DDI_3D_PATTERN_2D			        = BIT0 << VIDEO_DDI_3D_FORMAT_2D                ,

	/*      From UI, 3D ON이면서 아래 Format이 넘어오면 일반 3D ON이 됨.    */
	//interim format - half
	VIDEO_DDI_3D_PATTERN_TOP_BOTTOM         = BIT0 << VIDEO_DDI_3D_FORMAT_TOP_BOTTOM        ,
	VIDEO_DDI_3D_PATTERN_SIDEBYSIDE_HALF    = BIT0 << VIDEO_DDI_3D_FORMAT_SIDEBYSIDE_HALF   ,
	VIDEO_DDI_3D_PATTERN_CHECKER_BOARD      = BIT0 << VIDEO_DDI_3D_FORMAT_CHECKER_BOARD     ,
	VIDEO_DDI_3D_PATTERN_FRAME_SEQ          = BIT0 << VIDEO_DDI_3D_FORMAT_FRAME_SEQ         ,
	VIDEO_DDI_3D_PATTERN_COLUMN_INTERLEAVE  = BIT0 << VIDEO_DDI_3D_FORMAT_COLUMN_INTERLEAVE ,
	VIDEO_DDI_3D_PATTERN_LINE_INTERLEAVE_HALF	= BIT0 << VIDEO_DDI_3D_FORMAT_LINE_INTERLEAVE_HALF ,

	//Full format
	VIDEO_DDI_3D_PATTERN_FRAME_PACKING       = BIT0 << VIDEO_DDI_3D_FORMAT_FRAME_PACKING     ,
	VIDEO_DDI_3D_PATTERN_FIELD_ALTERNATIVE   = BIT0 << VIDEO_DDI_3D_FORMAT_FIELD_ALTERNATIVE ,
	VIDEO_DDI_3D_PATTERN_LINE_ALTERNATIVE    = BIT0 << VIDEO_DDI_3D_FORMAT_LINE_ALTERNATIVE  ,
	VIDEO_DDI_3D_PATTERN_SIDEBYSIDE_FULL     = BIT0 << VIDEO_DDI_3D_FORMAT_SIDEBYSIDE_FULL   ,
	VIDEO_DDI_3D_PATTERN_DUALSTREAM          = BIT0 << VIDEO_DDI_3D_FORMAT_DUALSTREAM        ,

}VIDEO_DDI_3D_PATTERN_TYPE_T;

/**
 * 3D L/R selection
 * .
*/
typedef enum
{
	VIDEO_DDI_3D_LR,	//Driver와 일치.
	VIDEO_DDI_3D_RL,
}VIDEO_DDI_3D_LR_TYPE_T;

/**
 * 3D Dual Mode Information.
 *
 * @see DDI Implementation Guide
*/
typedef enum
{
	VIDEO_DDI_DUAL_2D,			/**< for No Dual (OFF) */
	VIDEO_DDI_DUAL_TOP_BOTTOM,	/**< for T/B Dual Mode */
	VIDEO_DDI_DUAL_SIDEBYSIDE,	/**< for S/S Dual Mode */
}VIDEO_DDI_DUAL_TYPE_T;

/**
 * Video Timing Information.
 *
 * @see DDI Implementation Guide
*/
typedef struct
{
   	int format;	/**< update by LG */
	unsigned short hFreq;	/**< ... */
	unsigned short vFreq;	/**< ... */
	unsigned short hTotal;	/**< ... */
	unsigned short vTotal;	/**< ... */
	unsigned short hPorch;	/**< ... */
	unsigned short vPorch;	/**< ... */
	VIDEO_RECT_T	active;	/**< ... */
	unsigned short scanType;	/**< ... */
	unsigned short phase;	    /**< ... */  // need to check UINT16
	unsigned char  mode;	    /**< update by LG */
//	VFE_AVD_AVDECODER_VIDEO_MODE_T  standard;	/**< for color standard*/ // 2012.10.31 yongsu.yoo change this for Late-return of analog color system
	unsigned char  vdLock;	/**< for ATV */
	/* 3D restructuring by seongcheoll.kim 2011.07.01 */
	VIDEO_DDI_3D_FORMAT_TYPE_T full_3d_timing;
	VIDEO_DDI_3D_LR_TYPE_T	video_LR_order;
} VIDEO_TIMING_INFO_T;

#if 1
/**
 * pixel grab color.
 *
 * @see DDI Implementation Guide
*/
typedef struct
{
	unsigned char pixelGrabCb;	/**< Cb */
	unsigned char pixelGrabY;	/**< Y */
	unsigned char pixelGrabCr;	/**< CR */
}VIDEO_DDI_PIXEL_GRAB_COLOR_T;

/**
 * pixel grab region.
 *
 * @see DDI Implementation Guide
*/
typedef struct
{
	VIDEO_WID_T wID;	/**< select main or sub window */
	unsigned int pixelGrabX;	/**< x position */
	unsigned int pixelGrabY;	/**< y position */
	unsigned int pixelGrabW;	/**< capture width */
	unsigned int pixelGrabH;	/**< capture h */

	unsigned int realPixelGrabW;	/**< real W in memory */
	unsigned int realPixelGrabH;	/**< real H in memory */
	unsigned char colorSpace;	/**< 0: YUV 1:RGB */
}VIDEO_DDI_PIXEL_GRAB_REGION_T;

/**
 * standard pixel color.
 *
 * @see DDI Implementation Guide
*/
typedef struct
{
	unsigned short pixelStandardCb;	/**< standard pixel color Cb */
	unsigned short pixelStandardY;	/**< standard pixel color Y */
	unsigned short pixelStandardCr;	/**< standard pixel color Cr */
}VIDEO_DDI_PIXEL_STANDARD_COLOR_T;

/**
 * color standard.
 *
 * @see DDI Implementation Guide
*/
typedef enum
{
	VIDEO_DDI_COLOR_STANDARD_YUV = 0,
	VIDEO_DDI_COLOR_STANDARD_RGB,
} VIDEO_DDI_COLOR_STANDARD_T;

/**
 * color standard.
 *
 * @see DDI Implementation Guide
*/
typedef enum
{
	VIDEO_DDI_PIXEL_8BIT = 0,
	VIDEO_DDI_PIXEL_10BIT,
} VIDEO_DDI_PIXEL_COLOR_FORMAT_T;

/**
 * capture location
 *
 * @see DDI Implementation Guide
*/
typedef enum
{
	VIDEO_DDI_SCALER_OUTPUT = 0,
	VIDEO_DDI_DISPLAY_OUTPUT,
}VIDEO_DDI_CAPTURE_PLACE_T;
#endif

/**
 * Video output format type for UD display
 */
typedef struct {
	bool isUD;
	unsigned short fr_rate;						///< display frame rate
	unsigned short h_total;						///< pixels per line
	unsigned short v_total;						///< lines per frame
}VIDEO_DDI_DIS_FMT_T;

/**
 * Video UD format
 * 2011.11.08 by daegun.park
 */
typedef enum
{
	UD_MODE_FHD,
	UD_MODE_UD,
	UD_MODE_UD_HALF,
}VIDEO_UD_MODE_T;


/**
 * Video Component Index
 *
 */
typedef enum {
	COMP_INDEX_1 = 0,
	COMP_INDEX_2,
	COMP_INDEX_3,	// 20091111 drmyung : add
	NUM_COMP_INPUTS
} VIDEO_COMP_INDEX_T;

/**
 * Video Input signal source definition.
 *
 */
typedef enum VIDEO_SRC_TYPE
{
	VIDEO_SRC_TV	= 0,	/**< TV Input */
	VIDEO_SRC_SCART,		/**< Scart Input */
	VIDEO_SRC_AV,			/**< AV Input */
	VIDEO_SRC_AUTOAV,		/**< Auto AV(SCART) Input */
	VIDEO_SRC_COMP,			/**< Component(YPbPr) Input */
	VIDEO_SRC_RGB,			/**< RGB Input */
	VIDEO_SRC_HDMI,			/**< HDMI Input */
#ifdef INCLUDE_DVR_READY
	VIDEO_SRC_PLAYHDD,		/**< PVR : Recorded Playback mode */
#endif
	VIDEO_SRC_USB,			/**< ... */
	VIDEO_SRC_BT,			/**< ... */
	VIDEO_SRC_MEDIASHARE,	/**< ... */
	VIDEO_SRC_PICWIZARD,	/**< ... */
	VIDEO_SRC_SUPPORT,		/**< ... */
	VIDEO_SRC_BB,			/**< ... */
	VIDEO_SRC_FLASH,		/**< ... */
	VIDEO_SRC_VCS,			/**< ... */
	VIDEO_SRC_INVALID,		/**< Invalid Source Input */
	VIDEO_SRC_MAX = VIDEO_SRC_INVALID,	/**< MAX Input Number */
} VIDEO_SRC_TYPE_T;

/**
 * TV Src Attribute definition.
 *
 */
typedef enum VIDEO_TV_SRC_ATTR
{
	VIDEO_TV_ATTR_ANALOG = 0,	/**< ... */
	VIDEO_TV_ATTR_DIGITAL		/**< ... */

} VIDEO_TV_SRC_ATTR_T;

/**
 * EMF attribute definitions.
 *
 */
typedef enum VIDEO_EMF_SRC_ATTR
{
	VIDEO_EMF_ATTR_PHOTO_MUSIC		= 0,	/**< ... */
	VIDEO_EMF_ATTR_MOVIE,					/**< ... */
	VIDEO_EMF_ATTR_VCS, 	/**< ... */

} VIDEO_EMF_SRC_ATTR_T;

#ifndef TRIDTV_SC_OUTPUT_TYPE_T
typedef enum
{
	SC_OUT_SINGLE_2D  = 0 ,///< single nomal
	SC_OUT_SINGLE_TB      ,///< top and bottom
	SC_OUT_SINGLE_SS      ,///< side by side
	SC_OUT_SINGLE_FS      ,///< Frame Sequential(Interleaving)

	SC_OUT_DUAL_FHD       ,///< dual screen
	SC_OUT_DUAL_TB        ,///< dual top and bottom for H13 internal type
	SC_OUT_DUAL_SS        ,///< dual side by side for H13 internal type
	SC_OUT_SINGLE_T       ,//<H13 DRIVE 요청 SINGLE TOP ONLY>
	SC_OUT_SINGLE_LA     ,
	SC_OUT_MAX            ,//MAX
}__TRIDTV_SC_OUTPUT_TYPE_T;
#define TRIDTV_SC_OUTPUT_TYPE_T __TRIDTV_SC_OUTPUT_TYPE_T
#endif

#ifndef TRIDTV_INPUT_TYPE_T
typedef enum
{
	/*	Drive에서 아래 value 사용 안함.	*/
	INPUT_TYPE_3DOFF = 0,			//VIDEO_3D_FORMAT_2D,

	//interim format - half
	INPUT_TYPE_TOPNBOTTOM,		//VIDEO_3D_FORMAT_TOP_BOTTOM,
	INPUT_TYPE_SIDEBYSIDE,		//VIDEO_3D_FORMAT_SIDEBYSIDE_HALF,
	INPUT_TYPE_CHECKERBOARD,	//VIDEO_3D_FORMAT_CHECKER_BOARD,
	INPUT_TYPE_FRAMESEQ,		//VIDEO_3D_FORMAT_FRAME_SEQ
	INPUT_TYPE_COLUMN_INTERLEAVE,	/**< for H.264*/
	INPUT_TYPE_LINE_INTERLEAVE_HALF,	/**< for H.264*/

	//Full format
	INPUT_TYPE_FRAMEPAC,			//VIDEO_3D_FORMAT_FRAME_PACKING
	INPUT_TYPE_FIELD_ALTERNATIVE,	//VIDEO_3D_FORMAT_FIELD_ALTERNATIVE
	INPUT_TYPE_LINE_ALTERNATIVE,	//VIDEO_3D_FORMAT_LINE_ALTERNATIVE
	INPUT_TYPE_SIDEBYSIDE_FULL,		//VIDEO_3D_FORMAT_SIDEBYSIDE_FULL,
	INPUT_TYPE_DUALSTREAM, 	/**< Full format*/

	/*	Drive에서 아래 value 사용 안함. */
	INPUT_TYPE_2DTO3D,			//VIDEO_3D_FORMAT_2DTO3D,

	INPUT_TYPE_MAX,
}__TRIDTV_INPUT_TYPE_T;
#define TRIDTV_INPUT_TYPE_T __TRIDTV_INPUT_TYPE_T
#endif
/**
 * Define 3D Input LR Type.
 */
#ifndef  TRIDTV_INPUT_LR_SEQ_T
typedef enum
{
	INPUT_LR_SEQ = 0,
	INPUT_RL_SEQ,
	INPUT_LR_MAX,
} __TRIDTV_INPUT_LR_SEQ_T;
#define TRIDTV_INPUT_LR_SEQ_T __TRIDTV_INPUT_LR_SEQ_T
#endif

#ifndef TRIDTV_3DMODE_FLAG_T
typedef enum
{
	TRIDTV_3DMODE_OFF= 0,
	TRIDTV_3DMODE_ON 	,
	TRIDTV_3DMODE_2DTO3D,
	TRIDTV_3DMODE_3DTO2D,
	TRIDTV_3DMODE_MAX,
} __TRIDTV_3DMODE_FLAG_T;
#define TRIDTV_3DMODE_FLAG_T __TRIDTV_3DMODE_FLAG_T
#endif

#ifndef TRIDTV_SCALER_CTRL_T
typedef struct {

	TRIDTV_3DMODE_FLAG_T     mode;		///< select formatter operation mode. it controls 3D mode ON/OFF.
	TRIDTV_INPUT_TYPE_T		 in_fmt;	///< input image format(top/bottom, sidebyside, checkboard, frame, field seq, dual 2d)
	TRIDTV_SC_OUTPUT_TYPE_T  out_fmt;	///< output image format(top/bottom, sidebyside, checkboard, frame, field seq)
	TRIDTV_INPUT_LR_SEQ_T    lr;		///< output left/right first order
}__TRIDTV_SCALER_CTRL_T;
#define TRIDTV_SCALER_CTRL_T __TRIDTV_SCALER_CTRL_T
#endif

typedef enum {
	VIDEO_SEAMLESS_OFF,
	VIDEO_SEAMLESS_AUTO,      ///< Neflix
	VIDEO_SEAMLESS_EXTERNAL,  ///< BBC
	VIDEO_SEAMLESS_INTERNAL,  ///< Amazon
	VIDEO_SEAMLESS_MAX
} VIDEO_SEAMLESS_MODE_T;

typedef enum VO_VSC_SRC_TYPE {
	VO_VSC_SRC_VDEC = 0,
	VO_VSC_SRC_JPEG,
	VO_VSC_SRC_HDMI,
	VO_VSC_SRC_AVD,
	VO_VSC_SRC_ADC,
} VO_VSC_SRC_TYPE_T;

typedef enum _DI_RTNR_Mode_By_AP{
	DI_RTNR_OFF = 0,
	DI_RTNR_422 = 1,
	DI_RTNR_420 = 2,
	DI_RTNR_400 = 3,

} DI_RTNR_Mode_By_AP;

/*-----------------------------------------------------------------------------
	Definition of struct for IO ctrl cmd(all parameters include in the same struct)
------------------------------------------------------------------------------*/
/*
VSC_IOC_CONNECT
VSC_IOC_DISCONNECT
*/
typedef struct
{
	VIDEO_WID_T connectwid;
	VSC_INPUT_SRC_INFO_T vsc_input;
	VSC_OUTPUT_MODE_T outputmode;
}VSC_CONNECT_PARA_T;

/*
VSC_IOC_SET_WINBLANK
*/
typedef struct
{
	VIDEO_WID_T winblankwid;
	bool winblankbonoff;
	VIDEO_DDI_WIN_COLOR_T winblankcolor;
}VSC_WINBLANK_PARA_T;

/*
VSC_IOC_GET_INPUTREGION

VSC_IOC_GET_OUTPUTREGION
VSC_IOC_SET_OUTPUTREGION
*/
typedef struct
{
	VIDEO_WID_T setframewid;
	VIDEO_DDI_RECT_T * pinregion;
}VSC_GET_FRAME_REGION_T;

/*
VSC_IOC_SET_INPUTREGION
VSC_IOC_SET_OUTPUTREGION
*/
typedef struct
{
	VIDEO_WID_T setframewid;
	VIDEO_DDI_RECT_T inregion;
}VSC_SET_FRAME_REGION_T;

/*
VSC_IOC_SET_WINFREEZE
VSC_IOC_FREEZE_VIDEOFRAMEBUFFER
*/
typedef struct
{
	VIDEO_WID_T freezewid;
	bool freezeonoff;
}VSC_FREEZE_ACTION_T;

/*
VSC_IOC_READ_VIDEOFRAMEBUFFER
*/
typedef struct
{
	VIDEO_WID_T bufferwid;//in
	VIDEO_DDI_RECT_T * pinregion;//in
	VIDEO_DDI_PIXEL_STANDARD_COLOR_T * pRead;
	VIDEO_DDI_COLOR_STANDARD_T * pcolor_standard;
	VIDEO_DDI_PIXEL_COLOR_FORMAT_T * ppixelcolorformat;
}VSC_READ_BUFFER_ACTION_T;

/*
VSC_IOC_WRITE_VIDEOFRAMEBUFFER
*/
typedef struct
{
	VIDEO_WID_T bufferwid;//in
	VIDEO_DDI_RECT_T * pinregion;//in
	VIDEO_DDI_PIXEL_STANDARD_COLOR_T * pWrite;//in
}VSC_WRITE_BUFFER_ACTION_T;

/*
VSC_IOC_CAPTURE_VIDEOFRAME
*/
typedef struct
{
	VIDEO_DDI_CAPTURE_PLACE_T place;
	VIDEO_DDI_CAPTURE_INFO_T * pcaptureinfo;
}VSC_CAPTURE_FRAME_ACTION_T;

/*
VSC_IOC_GET_3DAUTODETECTMODE
*/
typedef struct
{
	VIDEO_WID_T wid;//in
	VIDEO_DDI_3D_FORMAT_TYPE_T * pvideo3dtype;
}VSC_3DAUTODET_ACTION_T;

/*
VSC_IOC_SET_3DPATTERNMODE

*/
typedef struct
{
	VIDEO_WID_T wid;//in
	VIDEO_DDI_3D_PATTERN_TYPE_T video3dtype;
}VSC_3DPATTERNMODE_ACTION_T;

/*
VSC_IOC_SET_VENCMODE
*/
typedef struct
{
	unsigned short framerate;
	unsigned short scantype;
}VSC_SET_VENCMODE_ACTION_T;

/*
VSC_IOC_GET_V2GFRAMEBUFFER
*/
typedef struct
{
	VIDEO_WID_T wid;//in
	VIDEO_DDI_CAPTURE_INFO_T* pCaptureInfo;
}VSC_GET_V2GFRAMEBUFFER_T;

/*
VSC_IOC_GET_VIDEODELAYEDTIME
*/
typedef struct
{
	VIDEO_WID_T wid;//in
	unsigned short * pDelayedTime;
}VSC_GET_VIDEODELAYEDTIME_T;

typedef struct SCALER_INPUT_INFO{
	unsigned int inputWid;
	unsigned int inputLen;
	unsigned int capWid;
	unsigned int capLen;
	unsigned int inputFramerate;
	unsigned int interlace;
}SCALER_INPUT_INFO;

typedef struct VSC_GET_INPUT_INFO{
	VIDEO_WID_T wid;//in
	SCALER_INPUT_INFO *inputInfo;
}VSC_GET_INPUT_INFO;

/*
VSC_IOC_SET_TILEMAXROWVAL
*/
typedef struct
{
	unsigned char uMaxRow;
	unsigned char  uMaxCol;
}VSC_SET_TILEMAXROWVAL_T;

/*
VSC_IOC_GET_VIDEODELAYEDTIME
*/
typedef struct
{
	VIDEO_WID_T wid;//in
	unsigned char* bMVOPEnable;
}VSC_GET_GETMVOPSTATUS_T;

typedef struct
{
	unsigned int display_wid;
	unsigned int  display_len;
}VSC_PANEL_SIZE_T;

typedef struct VSC_SET_ZORDER_T{
	unsigned char uZorder; // 0: bottom, 1: bottom+1,..
	unsigned char uAlpha; // 0 ~ 255
}VSC_SET_ZORDER_T;

typedef struct
{
	VIDEO_WID_T magnifierWid;
	VIDEO_RECT_T magnifierinregion;
	VIDEO_RECT_T magnifieroutregion;
	unsigned short W;
	unsigned short H;
}VSC_MAGNIGIER_PARA_T;

typedef enum
{
	VSC_VIDEO_COLOR_OFF,
	VSC_VIDEO_COLOR_WHITE,
}VSC_VIDEO_COLOR_TYPE_T;

typedef struct
{
	short port;
	unsigned short width;
	unsigned short height;
}VSC_ADAPTIVE_STREAM_INFO_FROM_APP;

typedef struct
{
	short display;
	unsigned short width;
	unsigned short height;
	unsigned short update_flag;
}SCALER_ADAPTIVE_STREAM_INFO;//This data is for scaler flow

typedef struct
{
	short port;
	unsigned char *update_flag;
}VSC_NOTICE_GST_VO_UPDATE_INFO;//This is for adaptive stream sync vo ready

typedef struct
{
	short port;
	unsigned char enable;
}VSC_APP_CONTROL_FORCEBG_TYPE;

typedef enum {
	VSC_HDR_HDR10,
	VSC_HDR_DOLBY,
	VSC_HDR_VP9,
	VSC_HDR_HLG,
	VSC_HDR_MAX = VSC_HDR_HLG,
	VSC_HDR_MAXN,
} VSC_HDR_TYPE_T;

typedef enum VSC_I2RND_STAGE_TYPE
{
	I2RND_STAGE_DISABLE = 0,
	I2RND_STAGE_DETECT_SOURCE,
	I2RND_STAGE_SUB_VO_RPC,
	I2RND_STAGE_TRIGGER_RUN_MAIN,
	I2RND_STAGE_MAIN_GET_RPC,
	I2RND_STAGE_MAIN_I2RND_DONE,
	I2RND_STAGE_MAXN,
} VSC_I2RND_STAGE_TYPE_T;


typedef enum VSC_I2RND_ATV_RERUN_MAIN_STAGE_TYPE
{
	I2RND_ATV_STAGE_DISABLE = 0,
	I2RND_ATV_STAGE_TRIGGER_RUN_MAIN,
	I2RND_ATV_STAGE_I3DDMA_RPC,
	I2RND_ATV_STAGE_RERUN_MAIN_DONE,
	I2RND_ATV_STAGE_MAXN,
} VSC_I2RND_ATV_RERUN_MAIN_STAGE_TYPE_T;

typedef enum VSC_SUB_PURPOSE
{
   VSC_SUB_PURPOSE_NONE =0,      // in case PBP enter/exit or PIP(live zoom or magnifier) exit.
   VSC_SUB_PURPOSE_LIVE_ZOOM, // in case live zoom enter
   VSC_SUB_PURPOSE_MAGNIFIER, // in case magnifier enter
   VSC_SUB_PURPOSE_MAX = VSC_SUB_PURPOSE_MAGNIFIER,
   VSC_SUB_PURPOSE_MAXN
} VSC_SUB_PURPOSE_T;

typedef struct
{
	unsigned char window;
	unsigned char buffer;
} VSC_SET_DELAY_BUFFER_TYPE;


typedef struct VSC_ACTIVE_VIDEO_WINDOW {
	VIDEO_RECT_T original;
	VIDEO_RECT_T active;
} VSC_ACTIVE_VIDEO_WINDOW_T;

typedef struct
{
	VIDEO_WID_T connectwid;
	VSC_ACTIVE_VIDEO_WINDOW_T window;
	unsigned char ready_flag;
} VSC_GET_BLACDETECTION_INFO_T;

typedef struct VSC_UZD_CRC{
	VIDEO_WID_T wid;
	unsigned int CRC_Value;
}VSC_UZD_CRC;

typedef enum {
     VSC_ROTATE_0,
     VSC_ROTATE_90,
     VSC_ROTATE_180,
     VSC_ROTATE_270
} VSC_ROTATE_T;

#define VSC_MAJOR 0   /* dynamic major by default */
#define VSC_NR_DEVS 1    /* se0 through se3 */


#define VSC_DEVICE_NUM							1
#define VSC_DEVICE_NAME							"vscdev"

#define VSC_IOC_MAGIC							'q'
#define VSC_IOC_INITIALIZE							_IO(VSC_IOC_MAGIC, 1)
#define VSC_IOC_UNINITIALIZE						_IO(VSC_IOC_MAGIC, 2)
#define VSC_IOC_OPEN							_IOW(VSC_IOC_MAGIC, 3, VIDEO_WID_T)
#define VSC_IOC_CLOSE							_IOW(VSC_IOC_MAGIC, 4, VIDEO_WID_T)
#define VSC_IOC_CONNECT							_IOW(VSC_IOC_MAGIC, 5, VSC_CONNECT_PARA_T)
#define VSC_IOC_DISCONNECT						_IOW(VSC_IOC_MAGIC, 6, VSC_CONNECT_PARA_T)
#define VSC_IOC_SET_WINBLANK						_IOW(VSC_IOC_MAGIC, 7, VSC_WINBLANK_PARA_T)
#define VSC_IOC_GET_INPUTREGION						_IOR(VSC_IOC_MAGIC, 8, VSC_GET_FRAME_REGION_T)
#define VSC_IOC_SET_INPUTREGION						_IOW(VSC_IOC_MAGIC, 9, VSC_SET_FRAME_REGION_T)
#define VSC_IOC_GET_OUTPUTREGION					_IOR(VSC_IOC_MAGIC, 10, VSC_GET_FRAME_REGION_T)
#define VSC_IOC_SET_OUTPUTREGION						_IOW(VSC_IOC_MAGIC, 11, VSC_SET_FRAME_REGION_T)
#define VSC_IOC_SET_VENCMODE						_IOW(VSC_IOC_MAGIC, 12,VSC_SET_VENCMODE_ACTION_T)
#define VSC_IOC_SET_WINFREEZE						_IOW(VSC_IOC_MAGIC, 13, VSC_FREEZE_ACTION_T)
#define VSC_IOC_CAPTURE_VIDEOFRAME					_IOW(VSC_IOC_MAGIC, 14, VSC_CAPTURE_FRAME_ACTION_T)
#define VSC_IOC_FREEZE_VIDEOFRAMEBUFFER					_IOW(VSC_IOC_MAGIC, 15, VSC_FREEZE_ACTION_T)
#define VSC_IOC_READ_VIDEOFRAMEBUFFER					_IOW(VSC_IOC_MAGIC, 16, VSC_READ_BUFFER_ACTION_T)
#define VSC_IOC_WRITE_VIDEOFRAMEBUFFER					_IOW(VSC_IOC_MAGIC, 17, VSC_WRITE_BUFFER_ACTION_T)
#define VSC_IOC_SET_RGB444MODE						_IOW(VSC_IOC_MAGIC, 18, bool)
#define VSC_IOC_SET_3DFORSCALER						_IOW(VSC_IOC_MAGIC, 19, unsigned int)
#define VSC_IOC_GET_3DAUTODETECTMODE					_IOR(VSC_IOC_MAGIC, 20, VSC_3DAUTODET_ACTION_T)
#define VSC_IOC_SET_3DPATTERNMODE					_IOW(VSC_IOC_MAGIC, 21,VSC_3DPATTERNMODE_ACTION_T)
#define VSC_IOC_OPENV2G							_IOW(VSC_IOC_MAGIC, 22, VIDEO_WID_T)
#define VSC_IOC_CLOSEV2G							_IOW(VSC_IOC_MAGIC, 23, VIDEO_WID_T)
#define VSC_IOC_GET_V2GFRAMEBUFFER					_IOR(VSC_IOC_MAGIC, 24, VSC_GET_V2GFRAMEBUFFER_T)
#define VSC_IOC_SET_UDINPUT						_IOW(VSC_IOC_MAGIC,25, VIDEO_UD_MODE_T)
#define VSC_IOC_SET_UDOUTPUT						_IOW(VSC_IOC_MAGIC,26, VIDEO_DDI_DIS_FMT_T)
#define VSC_IOC_GET_VIDEODELAYEDTIME					_IOR(VSC_IOC_MAGIC, 27, VSC_GET_VIDEODELAYEDTIME_T)
#define VSC_IOC_SET_TITLEMODE						_IOW(VSC_IOC_MAGIC,28, bool)
#define VSC_IOC_SET_TILEMAXROWVAL					_IOW(VSC_IOC_MAGIC,29, VSC_SET_TILEMAXROWVAL_T)
#define VSC_IOC_SET_TILEID							_IOW(VSC_IOC_MAGIC,30, unsigned char)
#define VSC_IOC_SET_ADAPTIVESTREAM					_IOW(VSC_IOC_MAGIC,31, bool)

#define VSC_IOC_SET_SOCOUTPUTFMT					_IOW(VSC_IOC_MAGIC,32, unsigned short)
#define VSC_IOC_SET_FRCTYPE						_IOW(VSC_IOC_MAGIC,33, unsigned short)
#define VSC_IOC_GET_FRCTYPE						_IOW(VSC_IOC_MAGIC,34, unsigned short)
#define VSC_IOC_GET_GETMVOPSTATUS					_IOW(VSC_IOC_MAGIC,35, unsigned short)

#define VSC_IOC_SET_VENCI3DDMA						_IOW(VSC_IOC_MAGIC,36, IDMA_DISPD_CAPTURE_INFO)
#define VSC_IOC_STOPVO							_IO(VSC_IOC_MAGIC,37)
#define VSC_IOC_GETINPUTINFO				      		_IOW(VSC_IOC_MAGIC,38, VSC_GET_INPUT_INFO)
#define VSC_IOC_SHOWOSDSAMPLE						_IOW(VSC_IOC_MAGIC,39, unsigned char)
#define VSC_IOC_GETPANELSIZE				_IOW(VSC_IOC_MAGIC,40, VSC_PANEL_SIZE_T)
#define VSC_IOC_SET_DOLBYVISION_IDMA_ENABLE		_IOW(VSC_IOC_MAGIC,41, unsigned char)
#define VSC_IOC_SETZORDER						_IOW(VSC_IOC_MAGIC, 42, VSC_SET_ZORDER_T)
#define VSC_IOC_MAKECOLOREDVIDEO				_IOW(VSC_IOC_MAGIC, 43, VSC_VIDEO_COLOR_TYPE_T)

#define VSC_IOC_DM_OPEN						_IOW(VSC_IOC_MAGIC,44, unsigned char)
#define VSC_IOC_DM_CLOSE						_IOW(VSC_IOC_MAGIC,45, unsigned char)
#define VSC_IOC_DM_CONNECT						_IOW(VSC_IOC_MAGIC,46, unsigned char)
#define VSC_IOC_DM_DISCONNECT						_IOW(VSC_IOC_MAGIC,47, unsigned char)
#define VSC_IOC_ISDOLBYHDR							_IOW(VSC_IOC_MAGIC,48, unsigned int)
#define VSC_IOC_UPDATE_ADAPTIVE_STREAMING_INFO	_IOW(VSC_IOC_MAGIC,49, VSC_ADAPTIVE_STREAM_INFO_FROM_APP)
#define VSC_IOC_NOTICE_GST_VO_UPDATE	_IOW(VSC_IOC_MAGIC,50, VSC_NOTICE_GST_VO_UPDATE_INFO)

#define VSC_IOC_APP_CONTRO_FORCEBG   _IOR(VSC_IOC_MAGIC, 51, VSC_APP_CONTROL_FORCEBG_TYPE)

#define VSC_IOC_HDR_OPEN							_IOW(VSC_IOC_MAGIC,52, unsigned char)
#define VSC_IOC_HDR_CLOSE						_IOW(VSC_IOC_MAGIC,53, unsigned char)
#define VSC_IOC_HDR_CONNECT						_IOW(VSC_IOC_MAGIC,54, unsigned char)
#define VSC_IOC_HDR_DISCONNECT					_IOW(VSC_IOC_MAGIC,55, unsigned char)

#define VSC_IOC_GET_ADAPTIVE_INPUTREGION					_IOR(VSC_IOC_MAGIC, 56, VSC_GET_FRAME_REGION_T)
#define VSC_IOC_SET_ADAPTIVE_INPUTREGION						_IOW(VSC_IOC_MAGIC,57, VSC_SET_FRAME_REGION_T)

#define VSC_IOC_SET_SubWinShape					_IO(VSC_IOC_MAGIC, 58)
#define VSC_IOC_SET_SetSubWinMode						_IO(VSC_IOC_MAGIC,59)
#define VSC_IOC_SET_SetSubWinPurpose					_IO(VSC_IOC_MAGIC, 60)
#define VSC_IOC_SET_SetDelayBuffer 					_IO(VSC_IOC_MAGIC, 61)

#define VSC_IOC_GET_BLACDETECTION_INFO_T   _IOR(VSC_IOC_MAGIC, 62, VSC_GET_BLACDETECTION_INFO_T)
#define VSC_IOC_SET_BLACDETECTION_EN		_IOW(VSC_IOC_MAGIC, 63, unsigned char)
#define VSC_IOC_RotateVideo					_IOW(VSC_IOC_MAGIC, 64, unsigned char)
#define VSC_IOC_SET_SetSubWinModeEx		_IO(VSC_IOC_MAGIC, 65)
#define VSC_IOC_SetVideoPattern				_IO(VSC_IOC_MAGIC, 66)
#define VSC_IOC_GetLimitedWindow				_IO(VSC_IOC_MAGIC, 67)
#define VSC_IOC_SET_INPUTREGION_EX				_IO(VSC_IOC_MAGIC, 68)
#define VSC_IOC_SET_ADAPTIVESTREAMEX	_IOW(VSC_IOC_MAGIC,69, VSC_ADAPTIVESTREAM_PARA_T)
#define VSC_IOC_WAIT_MUTEOFF_QUEUE                  _IO(VSC_IOC_MAGIC, 70)
#define VSC_IOC_VDO_CONNECT						_IOW(VSC_IOC_MAGIC, 71, VSC_CONNECT_PARA_T)
#define VSC_IOC_VDO_DISCONNECT						_IOW(VSC_IOC_MAGIC, 72, VSC_CONNECT_PARA_T)
#define VSC_IOC_SetVideoLatencyPattern				_IO(VSC_IOC_MAGIC, 73)
#define VSC_IOC_Set_VD_PTG					_IOW(VSC_IOC_MAGIC, 74,unsigned char)
#define VSC_IOC_GET_UZD_CRC					_IOR(VSC_IOC_MAGIC, 75,VSC_UZD_CRC)
#define VSC_IOC_Mdom_switch_mem_block					_IOW(VSC_IOC_MAGIC,76, unsigned char)
#define VSC_IOC_Mdom_Get_map_addr					_IOW(VSC_IOC_MAGIC,77, unsigned char)
#define VSC_IOC_Mdom_Get_phy_addr					_IOW(VSC_IOC_MAGIC,78, unsigned char)

#define VSC_IOC_SET_UZD_PATH					_IOR(VSC_IOC_MAGIC, 79,unsigned char)

#define VSC_IOC_SET_DRIVER_PATTERN					_IOR(VSC_IOC_MAGIC, 80,unsigned char)
#define VSC_IOC_SET_DRIVER_TABLE				_IOR(VSC_IOC_MAGIC, 81,unsigned char)

#define VSC_IOC_SET_TestPatternColor                           _IOW(VSC_IOC_MAGIC, 82,unsigned char)
#define VSC_IOC_SET_TestPatternRGBColor                                _IOW(VSC_IOC_MAGIC, 83,unsigned char)
#define VSC_IOC_SET_TestPatternIRE                             _IOW(VSC_IOC_MAGIC, 84,unsigned char)
#define VSC_IOC_SET_WINBLANK_SYNC_MEMC						_IO(VSC_IOC_MAGIC, 85)
#define VSC_IOC_SET_DUALDECODER                                        _IOW(VSC_IOC_MAGIC,86, unsigned char)
#define VSC_IOC_MAXNR							87


typedef enum{//for mute off callback use
	WIN_MAIN_ONLY = 0x1,//only call main callback
	WIN_SUB_ONLY = 0x2,//only call sub callback
	WIN_MAIN_SUB_BOTH = WIN_MAIN_ONLY | WIN_SUB_ONLY,//call both main and sub callback
} WIN_CALLBACK_INFO;


VSC_INPUT_TYPE_T Get_DisplayMode_Src(unsigned char display);

unsigned char vo_overscan_disable(VSC_INPUT_TYPE_T srctype);
unsigned char vo_overscan_adjust(VSC_INPUT_TYPE_T srctype);
void magnifier_message_push(VSC_MAGNIGIER_PARA_T message);
unsigned char get_ForceSmoothtoggleGo(void);
unsigned char vsc_get_adaptivestream_flag(void);
unsigned char Get_AVD_display(unsigned char display);
bool rtk_hal_vsc_GetRGB444Mode(void);
void Scaler_start_orbit_algo(unsigned char b_enable);
void Scaler_reset_orbit(void);
void fw_set_vsc_GameMode(unsigned char b_vscGameMode_OnOff);
unsigned char fw_get_vsc_GameMode(void);

#ifdef SMOOTH_TOGGLE_DATAFRCFS_TEST
unsigned char vsc_decide_timingframesync(unsigned char display);
#endif
unsigned char Get_AVD_display(unsigned char display);
unsigned char Get_Factory_SelfDiagnosis_Mode(void);
unsigned char Scaler_data_frc_fs_change_adjust_after_scaler(unsigned char display,unsigned short disp_height);
void Scaler_data_frc_fs_change_adjust_outputregion(unsigned char display,unsigned short disp_height);
void Scaler_Dolby_HDR_reset(void);
unsigned char uc4_get_main_dispwin_value(unsigned short *x, unsigned short *y, unsigned short *w, unsigned short *h);//WOSQRTK-7731
void scaler_dolby_enable_idmacap2_metadata(unsigned char enable);
void scaler_i2rnd_run_main(void);
unsigned char rtk_hal_vsc_i2rnd_enable(unsigned char enable);
unsigned short Scaler_CalAVD27MWidth(SCALER_DISP_CHANNEL display,unsigned short a_usInput);
unsigned char rtk_hal_vsc_i2rnd_b05_enable(unsigned char enable);
VSC_SUB_PURPOSE_T Get_Magnifier_LiveZoom_Mode(void);
unsigned char get_LiveZoomPcmodeDiableRTNR(void);
void set_LiveZoomPcmodeDiableRTNR(unsigned char value);
void reset_rotate_mode(void);
void scaler_save_main_info(void);
void scaler_update_struct_info(unsigned char display);
unsigned char Scaler_get_data_framesync(unsigned char display);
unsigned char get_scaler_stop_flag(unsigned char display);
unsigned char rtk_hal_vsc_Getdualdecoder(void);
unsigned char check_atv_stable_for_bg(unsigned char display);
void  rtk_hal_vsc_Setdualdecoder_run(unsigned char flag);
unsigned char rtk_hal_vsc_Getdualdecoder_run(void);
#endif

