#ifndef __SCALER_VFEDEV_H
#define  __SCALER_VFEDEV_H

#define 	BIT0_VFE_AVD	0x00000001

#include "../include/rtk_kdriver/scalercommon/scalerCommon.h"
#ifndef BOOLEAN
#ifndef _EMUL_WIN
typedef	unsigned int			__BOOLEAN;
#define BOOLEAN __BOOLEAN
#else
typedef	unsigned char		__BOOLEAN;
#define BOOLEAN __BOOLEAN
#endif
#endif

#ifndef UINT16
typedef unsigned short UINT16;
#endif
#ifndef UINT8
typedef unsigned char UINT8;
#endif
/**
 * Video Timing Information.
 *
 * @see DDI Implementation Guide
*/

typedef enum
{
	SRC_NOTHING =0,		//Source don't do anything yet
	SRC_INIT_DONE,			//Source after initial
	SRC_OPEN_DONE,		//Source after open
	SRC_CONNECT_DONE,		//Source after connect

	SRC_UNINIT,				//Source uninitial
	SRC_CLOSE, 				// Source close
	SRC_DISCONNECT, 		//Source disconnect
} SOURCE_STATUS;


#ifndef VIDEO_RECT_T /*BLK*/
typedef struct
{
	unsigned short		x;	/**< horizontal Start Position in pixel [0,].*/
	unsigned short		y;	/**< vertical	Start Position in pixel [0,].*/
	unsigned short		w;	/**< horizontal Size(Width)    in pixel [0,].*/
	unsigned short		h;	/**< vertical	Size(Height)   in pixel [0,].*/

} __VIDEO_RECT_T;
#define VIDEO_RECT_T __VIDEO_RECT_T/*BLK*/
#endif /*BLK*/


typedef struct
{
   	int       			 format  ;/**< ... */
	unsigned short       hFreq   ;/**< ... */
	unsigned short       vFreq   ;/**< ... */
	unsigned short       hTotal  ;/**< ... */
	unsigned short       vTotal  ;/**< ... */
	unsigned short       hPorch  ;/**< ... */
	unsigned short       vPorch  ;/**< ... */
	VIDEO_RECT_T 		 active  ;/**< ... */
	unsigned short       scanType;/**< ... */
	unsigned short       phase   ;/**< ... */
}ADC_TIMING_INFO_T;

typedef struct
{
    unsigned short  rGain  ;
    unsigned short  gGain  ;
    unsigned short  bGain  ;
    unsigned short  rOffset;
    unsigned short  gOffset;
    unsigned short  bOffset;

} ADC_CAL_DATA_T;

typedef enum
{
	ADC_ADJ_PC_AUTO = 0,		// PC Auto
	ADC_ADJ_PC_H_POS,			// PC H Position
	ADC_ADJ_PC_V_POS,			// PC V Position
	ADC_ADJ_PC_HV_POS,
	ADC_ADJ_PC_CLOCK,			// PC Clock
	ADC_ADJ_PC_PHASE,			// PC Phase
} ADC_ADJ_PC_MODE_T;

typedef struct
{
	ADC_ADJ_PC_MODE_T mode;
	UINT16 value;
}ADC_ADJ_PC_T;


typedef enum
{
	VFE_AVD_NOTHING_IS_SUPPORTED,
	VFE_AVD_CC_IS_SUPPORTED,
	VFE_AVD_TTX_IS_SUPPORTED,
	VFE_AVD_CC_AND_TTX_ARE_SUPPORTED,
}VFE_AVD_CC_TTX_STATUS_T;

typedef enum
{
	VIDEO_AVDEC_MODE_NTSC		 = 0,
	VIDEO_AVDEC_MODE_PAL			,
	VIDEO_AVDEC_MODE_PAL_NC_358		,
	VIDEO_AVDEC_MODE_PAL_M			,
	VIDEO_AVDEC_MODE_SECAM			,
	VIDEO_AVDEC_MODE_NTSC_443		,
	VIDEO_AVDEC_MODE_PAL_60 		,
	VIDEO_AVDEC_MODE_UNKNOWN_525	,
	VIDEO_AVDEC_MODE_UNKNOWN_625	,
	VIDEO_AVDEC_MODE_UNKNOWN		,
}VFE_AVD_AVDECODER_VIDEO_MODE_T;

typedef enum
{
	 COLOR_SYSTEM_NTSC_M		 = BIT0_VFE_AVD << VIDEO_AVDEC_MODE_NTSC 	,
	 COLOR_SYSTEM_PAL_G 		= BIT0_VFE_AVD << VIDEO_AVDEC_MODE_PAL		,
	 COLOR_SYSTEM_PAL_NC_358	= BIT0_VFE_AVD << VIDEO_AVDEC_MODE_PAL_NC_358	,
	 COLOR_SYSTEM_PAL_M 		= BIT0_VFE_AVD << VIDEO_AVDEC_MODE_PAL_M	,
	 COLOR_SYSTEM_SECAM 		= BIT0_VFE_AVD << VIDEO_AVDEC_MODE_SECAM	,
	 COLOR_SYSTEM_NTSC_443		= BIT0_VFE_AVD << VIDEO_AVDEC_MODE_NTSC_443 ,
	 COLOR_SYSTEM_PAL_60		= BIT0_VFE_AVD << VIDEO_AVDEC_MODE_PAL_60	,
	 COLOR_SYSTEM_PAL_N 										,  /* TBD should be remove */
	 COLOR_SYSTEM_UNKNOWN										,  /* TBD should be remove */

}VFE_AVD_COLOR_SYSTEM_T;

typedef struct
{
	UINT16		w;	/**< horizontal Size(Width)    in pixel [0,].*/
	UINT16		h;	/**< vertical	Size(Height)   in pixel [0,].*/
	UINT16		x;	/**< horizontal Start Position in pixel [0,].*/
	UINT16		y;	/**< vertical	Start Position in pixel [0,].*/
} VFE_AVD_RECT_T;


typedef struct
{
	//SINT32 format;
	int format;
	UINT16 hFreq;	/**< ... */
	UINT16 vFreq;	/**< ... */
	UINT16 hTotal;	/**< ... */
	UINT16 vTotal;	/**< ... */
	UINT16 hPorch;	/**< ... */
	UINT16 vPorch;	/**< ... */
	VFE_AVD_RECT_T	active; /**< ... */
	UINT8 scanType; /**< ... */
	BOOLEAN  vdLock;	/**< for ATV */
	BOOLEAN  HLock;
	BOOLEAN  VLock;
	VFE_AVD_AVDECODER_VIDEO_MODE_T	standard;
} VFE_AVD_TIMING_INFO_T;

typedef struct __DRB_VOINFO{
		VO_VIDEO_PLANE						plane;			///< vo plane
		unsigned int						port;			///< vsc port
		unsigned int						mode;			///< current mode
		unsigned int h_freq;
		unsigned int v_freq;
		unsigned int h_total;
		unsigned int v_total;
		unsigned int h_width;
		unsigned int v_length;
		unsigned int h_start;
		unsigned int v_start;
		unsigned int src_h_wid;
                unsigned int src_v_len;
		unsigned int	progressive;		///< progressive or interlace
		unsigned int	pixelAR_hor;		///< pixel aspect ratio - horizontal
		unsigned int	pixelAR_ver;		///< pixel aspect ratio - vertical
		unsigned int	i_ratio;		///< aspect ratio of input source, 1) 4:3, 0) 16:9 (use panel's definition)
		SLR_AFD_TYPE  afd;
		unsigned int	 voinfo_state;

		// keep "launcher" last for avoid compare in equal timing decesion (Scaler_DO_VO_timing_Equal())
		unsigned int						launcher;		///< 0) VO, 1) scaler request, keep last for avoid compare in equal timing decesion
} DRB_VOINFO;

typedef enum
{
	VFE_AVD_SCART_AR_16_9,		/**< scart aspect ratio [5 ~ 8V] */
	VFE_AVD_SCART_AR_4_3,			/**< scart aspect ratio [9.5 ~ 12V] */
	VFE_AVD_SCART_AR_INVALID
}VFE_AVD_SCART_AR_T;

typedef enum
{
	VIDEO_DDI_FB_STATUS_CVBS,		/**< scart RF status info*/
	VIDEO_DDI_FB_STATUS_RGB,			/**< scart RF status info*/
}VFE_AVD_SCART_FB_STATUS_T;

typedef enum
{
	AVD_INTERNAL_DEMOD,
	AVD_EXTERNAL_DEMOD,
}VFE_AVD_DEMOD_TYPE;

typedef enum
{
	VFE_AVD_PSP_OFF,
	VFE_AVD_PSP_ON_2_LINE_SPLIT_BURST_ON,
	VFE_AVD_PSP_ON_SPLIT_BURST_OFF,
	VFE_AVD_PSP_ON_4LINE_SPLIT_BURST_ON,
} VFE_AVD_PHYSICAL_COPY_PROTECT;


typedef enum
{
	VIDEO_DDI_VBI_PAL_TELETEXT = 0, /**< VBI teletxet */
	VIDEO_DDI_VBI_PAL_WSS,			/**< VBI wss */
	VIDEO_DDI_VBI_PAL_VPS,			/**< VBI vps */
	VIDEO_DDI_VBI_NTSC_CC608,		/**< VBI cc608 */
	VIDEO_DDI_VBI_NTSC_WSS,
	VIDEO_DDI_VBI_ALL,
	VIDEO_DDI_VBI_MAX_SERVICE,		/**< VBI max */
} VFE_AVD_VBI_TYPE_T;

typedef struct
{
	unsigned char vbi_type;
	unsigned char *vbi_status;
	unsigned char *vbi_buffer;
	unsigned int  *vbi_size;
}VBI_STATUS_INFO_T;

typedef struct
{
	VFE_AVD_CC_TTX_STATUS_T vbi_support_type;
	unsigned long cc_phyaddr;
	unsigned long ttx_phyaddr;
	unsigned long vps_phyaddr;
}VBI_INIT_MOUDLE_T;

typedef struct
{
	VFE_AVD_VBI_TYPE_T vbi_type;
	unsigned char enable;
}VBI_REGISTER_CALLBACK_T;

#define VFE_IOC_VO_CMD_IDX_START                130
enum vfe_ioc_vo_cmd_idx_e
{
        VFE_IOC_CMD_VO_GET_TIMINGINFO = VFE_IOC_VO_CMD_IDX_START,
        VFE_IOC_CMD_VO_GET_USBVOINFO,
        VFE_IOC_VO_CMD_IDX_MAX_NUM,
};

typedef struct __VO_VOINFO{
         unsigned int maxcll;
         unsigned int maxfall;

         unsigned int color_transf;
         unsigned int coeffs_overscan;
         unsigned int dispX0;
         unsigned int dispX1;
         unsigned int dispX2;
         unsigned int dispY0;
         unsigned int dispY1;
         unsigned int dispY2;
         unsigned int whitePointX;
         unsigned int whitePointY;
         unsigned int maxL;
         unsigned int minL;
         unsigned int dolbyVision;
} VO_VOINFO;


typedef struct
{
	UINT8 *pData;
	UINT8 len;
}KADP_ADC_PC_EDID_T;

/*-----------------------------------------------------------------------------
	System call
------------------------------------------------------------------------------*/
#define VFE_IOC_MAGIC 'w'

//index range
//ADC: 0 -49
//AVD: 50 - 109
//HDMI 110 - 189
//customer 200-255


// 0~49, ADC releated
#define VFE_IOC_ADC_START_INDEX 0
enum vfe_ioc_adc_idx
{
	VFE_IOC_ADC_IDX_0 = VFE_IOC_ADC_START_INDEX,//0
	VFE_IOC_ADC_IDX_1,//1
	VFE_IOC_ADC_IDX_2,//2
	VFE_IOC_ADC_IDX_3,//3
	VFE_IOC_ADC_IDX_4,//4
	VFE_IOC_ADC_IDX_5,//5
	VFE_IOC_ADC_IDX_6,//6
	VFE_IOC_ADC_IDX_7,//7
	VFE_IOC_ADC_IDX_8,//8
	VFE_IOC_ADC_IDX_9,//9
	VFE_IOC_ADC_IDX_10,//10
	VFE_IOC_ADC_IDX_11,//11
	VFE_IOC_ADC_IDX_12,//12
	VFE_IOC_ADC_IDX_13,//13
	VFE_IOC_ADC_IDX_14,//14
	VFE_IOC_ADC_IDX_15,//15
	VFE_IOC_ADC_IDX_16,//16
	VFE_IOC_ADC_IDX_17,//17
	VFE_IOC_ADC_IDX_18,//18
	VFE_IOC_ADC_IDX_19,//19
	VFE_IOC_ADC_IDX_20,//20
	VFE_IOC_ADC_IDX_21,//21
	VFE_IOC_ADC_IDX_22,//22
	VFE_IOC_ADC_IDX_23,//23
	VFE_IOC_ADC_IDX_24,//24
	VFE_IOC_ADC_IDX_25,//25
	VFE_IOC_ADC_IDX_26,//26
	VFE_IOC_ADC_IDX_27,//27
	VFE_IOC_ADC_IDX_28,//28
	VFE_IOC_ADC_IDX_29,//29
	VFE_IOC_ADC_IDX_30,//30
	VFE_IOC_ADC_IDX_31,//31
	VFE_IOC_ADC_IDX_32,//32
	VFE_IOC_ADC_IDX_33,//33
	VFE_IOC_ADC_IDX_34,//34
	VFE_IOC_ADC_IDX_35,//35
	VFE_IOC_ADC_IDX_36,//36
	VFE_IOC_ADC_IDX_37,//37
	VFE_IOC_ADC_IDX_38,//38
	VFE_IOC_ADC_IDX_39,//39
	VFE_IOC_ADC_IDX_40,//40
	VFE_IOC_ADC_IDX_MAX = 49,
};


// 0~49, ADC releated
#define VFE_IOC_ADC_INIT						_IO(VFE_IOC_MAGIC, VFE_IOC_ADC_IDX_0)
#define VFE_IOC_ADC_UNINIT						_IO(VFE_IOC_MAGIC, VFE_IOC_ADC_IDX_1)
#define VFE_IOC_ADC_OPEN						_IO(VFE_IOC_MAGIC, VFE_IOC_ADC_IDX_2)
#define VFE_IOC_ADC_CLOSE						_IO(VFE_IOC_MAGIC, VFE_IOC_ADC_IDX_3)
#define VFE_IOC_ADC_YPP_CONNECT					_IO(VFE_IOC_MAGIC, VFE_IOC_ADC_IDX_4)
#define VFE_IOC_ADC_VGA_CONNECT					_IO(VFE_IOC_MAGIC, VFE_IOC_ADC_IDX_5)
#define VFE_IOC_ADC_SCARTRGB_CONNECT			_IO(VFE_IOC_MAGIC, VFE_IOC_ADC_IDX_6)
#define VFE_IOC_ADC_YPP_DISCONNECT				_IO(VFE_IOC_MAGIC, VFE_IOC_ADC_IDX_7)
#define VFE_IOC_ADC_VGA_DISCONNECT				_IO(VFE_IOC_MAGIC, VFE_IOC_ADC_IDX_8)
#define VFE_IOC_ADC_SCARTRGB_DISCONNECT			_IO(VFE_IOC_MAGIC, VFE_IOC_ADC_IDX_9)
#define VFE_IOC_ADC_GET_TIMINGINFO				_IO(VFE_IOC_MAGIC, VFE_IOC_ADC_IDX_10) //IOR KADP_ADC_TIMING_INFO_T
#define VFE_IOC_ADC_CALIBRATION_EXTERNAL		_IO(VFE_IOC_MAGIC, VFE_IOC_ADC_IDX_11)
#define VFE_IOC_ADC_CALIBRATION_INTERNAL		_IO(VFE_IOC_MAGIC, VFE_IOC_ADC_IDX_12)
#define VFE_IOC_ADC_CALIBRATION_OTP				_IO(VFE_IOC_MAGIC, VFE_IOC_ADC_IDX_13)
#define VFE_IOC_ADC_GET_ADCVALUE				_IO(VFE_IOC_MAGIC, VFE_IOC_ADC_IDX_14) //IOR KADP_ADC_CAL_DATA_T
#define VFE_IOC_ADC_SET_ADCVALUE				_IO(VFE_IOC_MAGIC, VFE_IOC_ADC_IDX_15) //IOW KADP_ADC_CAL_DATA_T
#define VFE_IOC_ADC_GET_OTPDATA					_IO(VFE_IOC_MAGIC, VFE_IOC_ADC_IDX_16) //IOR KADP_ADC_CAL_DATA_T
#define VFE_IOC_ADC_RESET_CALIBRATION			_IO(VFE_IOC_MAGIC, VFE_IOC_ADC_IDX_17) //IOR KADP_ADC_CAL_DATA_T
#define VFE_IOC_ADC_FAST_MODE					_IO(VFE_IOC_MAGIC, VFE_IOC_ADC_IDX_18)
#define VFE_IOC_ADC_ADJ_PC						_IO(VFE_IOC_MAGIC, VFE_IOC_ADC_IDX_19)
#define VFE_IOC_ADC_ADJ_PC_AUTO					_IO(VFE_IOC_MAGIC, VFE_IOC_ADC_IDX_20)
#define VFE_IOC_ADC_PC_GET_VALUE				_IO(VFE_IOC_MAGIC, VFE_IOC_ADC_IDX_21)	
#define VFE_IOC_ADC_GET_TARTGET_DIFF			_IO(VFE_IOC_MAGIC, VFE_IOC_ADC_IDX_22)
#define VFE_IOC_ADC_GET_TIMINGINFO_EX			_IO(VFE_IOC_MAGIC, VFE_IOC_ADC_IDX_23) //IOR KADP_ADC_TIMING_INFO_EX_T
#define VFE_IOC_ADC_PC_READ_EDID				_IO(VFE_IOC_MAGIC, VFE_IOC_ADC_IDX_24)
#define VFE_IOC_ADC_PC_WRITE_EDID				_IO(VFE_IOC_MAGIC, VFE_IOC_ADC_IDX_25)
#define VFE_IOC_ADC_PC_ENABLE_DDC				_IO(VFE_IOC_MAGIC, VFE_IOC_ADC_IDX_26)

// 50~109, AVD releated
#define VFE_IOC_AVD_START_INDEX (VFE_IOC_ADC_IDX_MAX+1)
enum vfe_ioc_avd_idx
{
	VFE_IOC_AVD_IDX_0 = VFE_IOC_AVD_START_INDEX,//50
	VFE_IOC_AVD_IDX_1,//51
	VFE_IOC_AVD_IDX_2,//52
	VFE_IOC_AVD_IDX_3,//53
	VFE_IOC_AVD_IDX_4,//54
	VFE_IOC_AVD_IDX_5,//55
	VFE_IOC_AVD_IDX_6,//56
	VFE_IOC_AVD_IDX_7,//57
	VFE_IOC_AVD_IDX_8,//58
	VFE_IOC_AVD_IDX_9,//59
	VFE_IOC_AVD_IDX_10,//60
	VFE_IOC_AVD_IDX_11,//61
	VFE_IOC_AVD_IDX_12,//62
	VFE_IOC_AVD_IDX_13,//63
	VFE_IOC_AVD_IDX_14,//64
	VFE_IOC_AVD_IDX_15,//65
	VFE_IOC_AVD_IDX_16,//66
	VFE_IOC_AVD_IDX_17,//67
	VFE_IOC_AVD_IDX_18,//68
	VFE_IOC_AVD_IDX_19,//69
	VFE_IOC_AVD_IDX_20,//70
	VFE_IOC_AVD_IDX_21,//71
	VFE_IOC_AVD_IDX_22,//72
	VFE_IOC_AVD_IDX_23,//73
	VFE_IOC_AVD_IDX_24,//74
	VFE_IOC_AVD_IDX_25,//75
	VFE_IOC_AVD_IDX_26,//76
	VFE_IOC_AVD_IDX_27,//77
	VFE_IOC_AVD_IDX_28,//78
	VFE_IOC_AVD_IDX_29,//79
	VFE_IOC_AVD_IDX_30,//80
	VFE_IOC_AVD_IDX_31,//81
	VFE_IOC_AVD_IDX_32,//82
	VFE_IOC_AVD_IDX_33,//83
	VFE_IOC_AVD_IDX_34,//84
	VFE_IOC_AVD_IDX_35,//85
	VFE_IOC_AVD_IDX_36,//86
	VFE_IOC_AVD_IDX_37,//87
	VFE_IOC_AVD_IDX_38,//88
	VFE_IOC_AVD_IDX_39,//89
	VFE_IOC_AVD_IDX_MAX = 109,
};


#define VFE_IOC_AVD_INIT							_IO(VFE_IOC_MAGIC, VFE_IOC_AVD_IDX_0)//IOW KADP_VFE_AVD_CC_TTX_STATUS_T
#define VFE_IOC_AVD_UNINIT							_IO(VFE_IOC_MAGIC, VFE_IOC_AVD_IDX_1)
#define VFE_IOC_AVD_OPEN							_IO(VFE_IOC_MAGIC, VFE_IOC_AVD_IDX_2)
#define VFE_IOC_AVD_CLOSE							_IO(VFE_IOC_MAGIC, VFE_IOC_AVD_IDX_3)
#define VFE_IOC_AVD_ATV_CONNECT						_IO(VFE_IOC_MAGIC, VFE_IOC_AVD_IDX_4) //IOW int
#define VFE_IOC_AVD_AV_CONNECT						_IO(VFE_IOC_MAGIC, VFE_IOC_AVD_IDX_5) //IOW int
#define VFE_IOC_AVD_SCART_CONNECT					_IO(VFE_IOC_MAGIC, VFE_IOC_AVD_IDX_6) //IOW int
#define VFE_IOC_AVD_ATV_DISCONNECT					_IO(VFE_IOC_MAGIC, VFE_IOC_AVD_IDX_7)
#define VFE_IOC_AVD_AV_DISCONNECT					_IO(VFE_IOC_MAGIC, VFE_IOC_AVD_IDX_8)
#define VFE_IOC_AVD_SCART_DISCONNECT				_IO(VFE_IOC_MAGIC, VFE_IOC_AVD_IDX_9)
#define VFE_IOC_AVD_SET_SYNC_DETECTION_FOR_TUNING 	_IO(VFE_IOC_MAGIC, VFE_IOC_AVD_IDX_10) //IOW unsigned char
#define VFE_IOC_AVD_DOES_SYNC_EXIST					_IO(VFE_IOC_MAGIC, VFE_IOC_AVD_IDX_11)
#define VFE_IOC_AVD_SET_COLOR_SYSTEM				_IO(VFE_IOC_MAGIC, VFE_IOC_AVD_IDX_12) //IOW KADP_VFE_AVD_COLOR_SYSTEM_T
#define VFE_IOC_AVD_GET_COLOR_SYSTEM				_IO(VFE_IOC_MAGIC, VFE_IOC_AVD_IDX_13) //IOR KADP_VFE_AVD_AVDECODER_VIDEO_MODE_T
#define VFE_IOC_AVD_GET_TIMINGINFO					_IO(VFE_IOC_MAGIC, VFE_IOC_AVD_IDX_14) //IOR KADP_VFE_AVD_TIMING_INFO_T
#define VFE_IOC_AVD_GET_SCART_ID					_IO(VFE_IOC_MAGIC, VFE_IOC_AVD_IDX_15) //IOR KADP_VFE_AVD_SCART_AR_T
#define VFE_IOC_AVD_GET_SCART_FAST_BLANKING_STATUS	_IO(VFE_IOC_MAGIC, VFE_IOC_AVD_IDX_16) //IOR KADP_VFE_AVD_SCART_FB_STATUS_T
#define VFE_IOC_AVD_SET_DEMOD_TYPE					_IO(VFE_IOC_MAGIC, VFE_IOC_AVD_IDX_17) //IOW KADP_VFE_AVD_DEMOD_TYPE
#define VFE_IOC_AVD_GET_PHYSICALSIGNAL_COPYPROETCT	_IO(VFE_IOC_MAGIC, VFE_IOC_AVD_IDX_18) //IOR KADP_VFE_AVD_PHYSICAL_COPY_PROTECT
#define VFE_IOC_AVD_INIT_VBI_MODULE					_IO(VFE_IOC_MAGIC, VFE_IOC_AVD_IDX_19) //IOW VBI_INIT_MOUDLE_T
#define VFE_IOC_AVD_ENABLE_VBI						_IO(VFE_IOC_MAGIC, VFE_IOC_AVD_IDX_20) //IOW KADP_VFE_AVD_CC_TTX_STATUS_T
#define VFE_IOC_AVD_DISABLE_VBI						_IO(VFE_IOC_MAGIC, VFE_IOC_AVD_IDX_21) //IOW KADP_VFE_AVD_CC_TTX_STATUS_T
#define VFE_IOC_AVD_GET_480I_WSS_20BITS				_IO(VFE_IOC_MAGIC, VFE_IOC_AVD_IDX_22) //IOR unsigned int
#define VFE_IOC_AVD_GET_576I_WSS_14BITS				_IO(VFE_IOC_MAGIC, VFE_IOC_AVD_IDX_23) //IOR unsigned short
#define VFE_IOC_AVD_VBI_CALLBACK					_IO(VFE_IOC_MAGIC, VFE_IOC_AVD_IDX_24) //IOWR VBI_REGISTER_CALLBACK_T
#define VFE_IOC_AVD_IFD_SET_AUDIO_BP				_IO(VFE_IOC_MAGIC, VFE_IOC_AVD_IDX_25) //IOWR unsigned char
#define VFE_IOC_AVD_DRV_SET_AUDIO_BP				_IO(VFE_IOC_MAGIC, VFE_IOC_AVD_IDX_26) //IOWR unsigned int
#define VFE_IOC_AVD_CHANGE_DEMOD_SYSTEM				_IO(VFE_IOC_MAGIC, VFE_IOC_AVD_IDX_27) //IOW unsigned char
#define VFE_IOC_AVD_Auto_Tune_Mode					_IO(VFE_IOC_MAGIC, VFE_IOC_AVD_IDX_28)//sync from hal //iow unsigned char
#define VFE_IOC_AVD_ATV_SET_CH_CHANGE				_IO(VFE_IOC_MAGIC, VFE_IOC_AVD_IDX_29)//For K4L 
#define VFE_IOC_GET_AV_OFFLINE_SIGTATUS				_IO(VFE_IOC_MAGIC, VFE_IOC_AVD_IDX_30) //IOR unsigned char
#define VFE_IOC_AVD_27M_MODE						_IO(VFE_IOC_MAGIC, VFE_IOC_AVD_IDX_31) //IOW unsigned char
#define VFE_IOC_AVD_GET_TIMINGINFO_EX				_IO(VFE_IOC_MAGIC, VFE_IOC_AVD_IDX_32) //IOR KADP_VFE_AVD_TIMING_INFO_EX_T
#define VFE_IOC_AVD_CHECK_ATV_STABLE				_IO(VFE_IOC_MAGIC, VFE_IOC_AVD_IDX_33) //IOR unsigned char
#define VFE_IOC_AVD_DETECT_TIMING_IN_AUTOSCAN		_IO(VFE_IOC_MAGIC, VFE_IOC_AVD_IDX_33)
#define VFE_IOC_AVD_SOFT_RESET					        _IO(VFE_IOC_MAGIC, VFE_IOC_AVD_IDX_34)

/* hdmi rx ioctrl cmd definitions start */
// 110~189, HDMI releated
#define VFE_IOC_HDMI_CMD_BASE_NUM  (VFE_IOC_AVD_IDX_MAX+1)
enum vfe_ioc_hdmi_cmd_idx_e
{
	VFE_IOC_HDMI_IDX_0 = VFE_IOC_HDMI_CMD_BASE_NUM,//110
	VFE_IOC_HDMI_IDX_1,//111
	VFE_IOC_HDMI_IDX_2,//112
	VFE_IOC_HDMI_IDX_3,//113
	VFE_IOC_HDMI_IDX_4,//114
	VFE_IOC_HDMI_IDX_5,//115
	VFE_IOC_HDMI_IDX_6,//116
	VFE_IOC_HDMI_IDX_7,//117
	VFE_IOC_HDMI_IDX_8,//118
	VFE_IOC_HDMI_IDX_9,//119
	VFE_IOC_HDMI_IDX_10,//120
	VFE_IOC_HDMI_IDX_11,//121
	VFE_IOC_HDMI_IDX_12,//122
	VFE_IOC_HDMI_IDX_13,//123
	VFE_IOC_HDMI_IDX_14,//124
	VFE_IOC_HDMI_IDX_15,//125
	VFE_IOC_HDMI_IDX_16,//126
	VFE_IOC_HDMI_IDX_17,//127
	VFE_IOC_HDMI_IDX_18,//128
	VFE_IOC_HDMI_IDX_19,//129
	VFE_IOC_HDMI_IDX_20,//130
	VFE_IOC_HDMI_IDX_21,//131
	VFE_IOC_HDMI_IDX_22,//132
	VFE_IOC_HDMI_IDX_23,//133
	VFE_IOC_HDMI_IDX_24,//134
	VFE_IOC_HDMI_IDX_25,//135
	VFE_IOC_HDMI_IDX_26,//136
	VFE_IOC_HDMI_IDX_27,//137
	VFE_IOC_HDMI_IDX_28,//138
	VFE_IOC_HDMI_IDX_29,//139
	VFE_IOC_HDMI_IDX_30,//140
	VFE_IOC_HDMI_IDX_31,//141
	VFE_IOC_HDMI_IDX_32,//142
	VFE_IOC_HDMI_IDX_33,//143
	VFE_IOC_HDMI_IDX_34,//144
	VFE_IOC_HDMI_IDX_35,//145
	VFE_IOC_HDMI_IDX_36,//146
	VFE_IOC_HDMI_IDX_37,//147
	VFE_IOC_HDMI_IDX_38,//148
	VFE_IOC_HDMI_IDX_39,//149
	VFE_IOC_HDMI_IDX_40,//150
	VFE_IOC_HDMI_IDX_41,//151
	VFE_IOC_HDMI_IDX_42,//152
	VFE_IOC_HDMI_IDX_43,//153
	VFE_IOC_HDMI_IDX_44,//154
	VFE_IOC_HDMI_IDX_45,//155
	VFE_IOC_HDMI_IDX_46,//156
	VFE_IOC_HDMI_IDX_47,//157
	VFE_IOC_HDMI_IDX_48,//158
	VFE_IOC_HDMI_IDX_49,//159
	VFE_IOC_HDMI_IDX_50,//160
	VFE_IOC_HDMI_IDX_51,//161
	VFE_IOC_HDMI_IDX_52,//162
	VFE_IOC_HDMI_IDX_53,//163
	VFE_IOC_HDMI_IDX_54,//164
	VFE_IOC_HDMI_IDX_55,//165
	VFE_IOC_HDMI_IDX_56,//166
	VFE_IOC_HDMI_IDX_57,//167
	VFE_IOC_HDMI_IDX_58,//168
	VFE_IOC_HDMI_IDX_59,//169
	VFE_IOC_HDMI_IDX_60,//170
	VFE_IOC_HDMI_IDX_61,//171
	VFE_IOC_HDMI_IDX_62,//172
	VFE_IOC_HDMI_IDX_63,//173
	VFE_IOC_HDMI_IDX_64,//174
	VFE_IOC_HDMI_IDX_65,//175
	VFE_IOC_HDMI_IDX_66,//176
	VFE_IOC_HDMI_IDX_67,//177
	VFE_IOC_HDMI_IDX_68,//178
	VFE_IOC_HDMI_IDX_69,//179
	VFE_IOC_HDMI_IDX_70,//180
	VFE_IOC_HDMI_IDX_71,//181
	VFE_IOC_HDMI_IDX_72,//182
	VFE_IOC_HDMI_IDX_73,//183
	VFE_IOC_HDMI_IDX_74,//184
	VFE_IOC_HDMI_IDX_75,//185
	VFE_IOC_HDMI_IDX_76,//186
	VFE_IOC_HDMI_IDX_77,//187
	VFE_IOC_HDMI_IDX_78,//188
	VFE_IOC_HDMI_CMD_IDX_MAXUM=189,
};
#define VFE_IOC_HDMI_CMD_ITEM_NUM                 (VFE_IOC_HDMI_CMD_IDX_MAX_NUM - VFE_IOC_HDMI_CMD_BASE_NUM)

#define VFE_IOC_HDMI_INIT								_IO(VFE_IOC_MAGIC, VFE_IOC_HDMI_IDX_0)
#define VFE_IOC_HDMI_UNINIT								_IO(VFE_IOC_MAGIC, VFE_IOC_HDMI_IDX_1)
#define VFE_IOC_HDMI_OPEN								_IO(VFE_IOC_MAGIC, VFE_IOC_HDMI_IDX_2)
#define VFE_IOC_HDMI_CLOSE								_IO(VFE_IOC_MAGIC, VFE_IOC_HDMI_IDX_3)
#define VFE_IOC_HDMI_CONNECT							_IO(VFE_IOC_MAGIC, VFE_IOC_HDMI_IDX_4) //IOW unsigned char
#define VFE_IOC_HDMI_DISCONNECT							_IO(VFE_IOC_MAGIC, VFE_IOC_HDMI_IDX_5) //IOW unsigned char
#define VFE_IOC_HDMI_GET_PORT_TIMINGINFO				_IO(VFE_IOC_MAGIC, VFE_IOC_HDMI_IDX_6) //_IOWR vfe_hdmi_timing_info_t
#define VFE_IOC_HDMI_GET_PORT_VSIINFO					_IO(VFE_IOC_MAGIC, VFE_IOC_HDMI_IDX_7) //IORW vfe_hdmi_vsi_t
#define VFE_IOC_HDMI_GET_PORT_SPDINFO					_IO(VFE_IOC_MAGIC, VFE_IOC_HDMI_IDX_8) //IORW vfe_hdmi_spd_t
#define VFE_IOC_HDMI_GET_PORT_AVIINFO					_IO(VFE_IOC_MAGIC, VFE_IOC_HDMI_IDX_9) //IORW vfe_hdmi_avi_t
#define VFE_IOC_HDMI_GET_PORT_ALLPACKET                 _IO(VFE_IOC_MAGIC, VFE_IOC_HDMI_IDX_10) //IORW vfe_hdmi_all_packet_t
#define VFE_IOC_HDMI_GET_HDMISW5V						_IO(VFE_IOC_MAGIC, VFE_IOC_HDMI_IDX_11) //IORW vfe_hdmi_sw_5v_t
#define VFE_IOC_HDMI_GET_CONNECTION_STATE				_IO(VFE_IOC_MAGIC, VFE_IOC_HDMI_IDX_12) //IORW vfe_hdmi_connect_state_t
#define VFE_IOC_HDMI_ENABLE_HPD							_IO(VFE_IOC_MAGIC, VFE_IOC_HDMI_IDX_13)
#define VFE_IOC_HDMI_DISABLE_HPD						_IO(VFE_IOC_MAGIC, VFE_IOC_HDMI_IDX_14)
#define VFE_IOC_HDMI_RESTART_HPD						_IO(VFE_IOC_MAGIC, VFE_IOC_HDMI_IDX_15)
#define VFE_IOC_HDMI_DISABLE_INTERNAL_EDID_ACCESS		_IO(VFE_IOC_MAGIC, VFE_IOC_HDMI_IDX_16) //IOW unsigned char
#define VFE_IOC_HDMI_READ_EDID							_IO(VFE_IOC_MAGIC, VFE_IOC_HDMI_IDX_17) //IOWR vfe_hdmi_edid_data_t
#define VFE_IOC_HDMI_WRITE_EDID							_IO(VFE_IOC_MAGIC, VFE_IOC_HDMI_IDX_18) //IOW vfe_hdmi_edid_data_t
#define VFE_IOC_HDMI_WRITE_HDCP							_IO(VFE_IOC_MAGIC, VFE_IOC_HDMI_IDX_19) //IOW vfe_hdmi_hdcp_data_t
#define VFE_IOC_HDMI_READ_HDCP							_IO(VFE_IOC_MAGIC, VFE_IOC_HDMI_IDX_20) //IOWR vfe_hdmi_hdcp_data_t
#define VFE_IOC_HDMI_GET_SOURCE_KSVDATA					_IO(VFE_IOC_MAGIC, VFE_IOC_HDMI_IDX_21) //IOWR vfe_hdmi_ksv_data_t
#define VFE_IOC_HDMI_MHL_ISMODE							_IO(VFE_IOC_MAGIC, VFE_IOC_HDMI_IDX_22) //IOR bool
#define VFE_IOC_HDMI_MHL_SEND_MSCMSG					_IO(VFE_IOC_MAGIC, VFE_IOC_HDMI_IDX_23) //IOW unsigned char
#define VFE_IOC_HDMI_MHL_SEND_WRITEBURST				_IO(VFE_IOC_MAGIC, VFE_IOC_HDMI_IDX_24) //IOW vfe_hdmi_mhl_msc_write_burst_cmd_t
#define VFE_IOC_HDMI_MHL_READ_WRITEBURST				_IO(VFE_IOC_MAGIC, VFE_IOC_HDMI_IDX_25) //IOW vfe_hdmi_mhl_msc_write_burst_cmd_t
#define VFE_IOC_HDMI_GET_MHLMODE						_IO(VFE_IOC_MAGIC, VFE_IOC_HDMI_IDX_26) //IOR vfe_hdmi_mhl_mode_t
#define VFE_IOC_HDMI_GET_CLOCKSTATUS					_IO(VFE_IOC_MAGIC, VFE_IOC_HDMI_IDX_27) //IOR vfe_hdmi_clockstatus_t
#define VFE_IOC_HDMI_MHL_CHECK_RCPMSG					_IO(VFE_IOC_MAGIC, VFE_IOC_HDMI_IDX_28) //IOR bool
#define VFE_IOC_HDMI_MHL_RECEIVE_RCPMSG					_IO(VFE_IOC_MAGIC, VFE_IOC_HDMI_IDX_29) //IOR unsigned char
#define VFE_IOC_HDMI_GET_AUDIO_CODING_TYPE        		_IO(VFE_IOC_MAGIC, VFE_IOC_HDMI_IDX_30) //IOR unsigned char 
#define VFE_IOC_HDMI_SET_HPD_LOW_DELAY                  _IO(VFE_IOC_MAGIC, VFE_IOC_HDMI_IDX_31) //IOw unsigned int
#define VFE_IOC_HDMI_GET_DRM_INFO            			_IO(VFE_IOC_MAGIC, VFE_IOC_HDMI_IDX_32) //IOWR vfe_hdmi_drm_t
#define VFE_IOC_HDMI_SET_ARC_SPDIF_ENABLE				_IO(VFE_IOC_MAGIC, VFE_IOC_HDMI_IDX_33) //IOW unsigned int
#define VFE_IOC_HDMI_GET_AVMUTE             			_IO(VFE_IOC_MAGIC, VFE_IOC_HDMI_IDX_34) //IOWR unsigned char
#define VFE_IOC_HDMI_WRITE_EDID_APPLY					_IO(VFE_IOC_MAGIC, VFE_IOC_HDMI_IDX_35) //IOW vfe_hdmi_edid_data_apply_t
#define VFE_IOC_HDMI_WRITE_HDCP_APPLY					_IO(VFE_IOC_MAGIC, VFE_IOC_HDMI_IDX_36) //IOW vfe_hdmi_hdcp_data_apply_t
#define VFE_IOC_HDMI_GET_RX_PORT_CNT				_IOWR(VFE_IOC_MAGIC, VFE_IOC_HDMI_IDX_37, unsigned char)
#define VFE_IOC_HDMI_GET_HDMI_SUPPORT_VER		_IOWR(VFE_IOC_MAGIC, VFE_IOC_HDMI_IDX_38, vfe_hdmi_support_ver_t)
#define VFE_IOC_HDMI_GET_HDCP_VERSION			_IOWR(VFE_IOC_MAGIC, VFE_IOC_HDMI_IDX_39, vfe_hdmi_hdcp_ver_t)
#define VFE_IOC_HDMI_GET_SRUPPORT_HDCP_VER		_IOWR(VFE_IOC_MAGIC, VFE_IOC_HDMI_IDX_40, vfe_hdcp_table_t)
#define VFE_IOC_HDMI_GET_RECEIVER_ID				_IOWR(VFE_IOC_MAGIC, VFE_IOC_HDMI_IDX_41, unsigned char)
#define VFE_IOC_HDMI_SET_HPD_CONTROL				_IOWR(VFE_IOC_MAGIC, VFE_IOC_HDMI_IDX_42, vfe_hdmi_hpd_t)
#define VFE_IOC_HDMI_GET_LOGICAL_PORT			_IOWR(VFE_IOC_MAGIC, VFE_IOC_HDMI_IDX_43, unsigned char)
#define VFE_IOC_HDMI_GET_ARC_CHANNEL				_IOWR(VFE_IOC_MAGIC, VFE_IOC_HDMI_IDX_44, char)
#define VFE_IOC_HDMI_SET_HPD_STATUS				_IOWR(VFE_IOC_MAGIC, VFE_IOC_HDMI_IDX_45, vfe_hdmi_hpd_t)


///////////////////////////////////////////////////////start///////////////////////////////////////////////////////
//customer range is 200-255
#define VFE_IOC_CUSTOMER_START_INDEX 200
enum vfe_ioc_sustomer_idx
{
	VFE_IOC_CUSTOMER_IDX_0 = VFE_IOC_CUSTOMER_START_INDEX,//200
	VFE_IOC_CUSTOMER_IDX_1,//201
	VFE_IOC_CUSTOMER_IDX_2,//202
	VFE_IOC_CUSTOMER_IDX_3,//203
	VFE_IOC_CUSTOMER_IDX_4,//204
	VFE_IOC_CUSTOMER_IDX_5,//205
	VFE_IOC_CUSTOMER_IDX_6,//206
	VFE_IOC_CUSTOMER_IDX_7,//207
	VFE_IOC_CUSTOMER_IDX_8,//208
	VFE_IOC_CUSTOMER_IDX_9,//209
	VFE_IOC_CUSTOMER_IDX_10,//210
	VFE_IOC_CUSTOMER_IDX_11,//211
	VFE_IOC_CUSTOMER_IDX_12,//212
	VFE_IOC_CUSTOMER_IDX_13,//213
	VFE_IOC_CUSTOMER_IDX_MAX = 255,
};
#define VO_GET_TIMINGINFO						  	_IO(VFE_IOC_MAGIC, VFE_IOC_CUSTOMER_IDX_0) //IOR DRB_VOINFO
#define VFE_IOC_AVD_VBI_TTX_SINGAL			      	_IO(VFE_IOC_MAGIC, VFE_IOC_CUSTOMER_IDX_1) //IOWR unsigned char
// TODO, Merlin3 tv010 sync, need modify index according to merlin3 status
#define VFE_IOC_AVD_Coarse_Lock						_IO(VFE_IOC_MAGIC, VFE_IOC_CUSTOMER_IDX_2) // TO-DO, original is 59

#define VFE_AVD_EXTERN_IOC_GET625MODE				_IO(VFE_IOC_MAGIC, VFE_IOC_CUSTOMER_IDX_3) //IOR unsigned int
#define VFE_AVD_EXTERN_IOC_GET_MACROVISION			_IO(VFE_IOC_MAGIC, VFE_IOC_CUSTOMER_IDX_4) //IOR unsigned int
#define VFE_AVD_EXTERN_IOC_OPEN_AV_OUT_BYPASS		_IO(VFE_IOC_MAGIC, VFE_IOC_CUSTOMER_IDX_5)
#define VFE_AVD_EXTERN_IOC_CLOSE_AV_OUT_BYPASS		_IO(VFE_IOC_MAGIC, VFE_IOC_CUSTOMER_IDX_6)
#define VFE_EXTERN_IOC_GET_OFFLINE_SIGTATUS			_IO(VFE_IOC_MAGIC, VFE_IOC_CUSTOMER_IDX_7) //IOR RTK_MW_SRC_E_BOOL
#define VFE_IOC_SETNSTDVALUE         				_IO(VFE_IOC_MAGIC, VFE_IOC_CUSTOMER_IDX_8) //IOR unsigned int
#define VFE_IOC_AVD_GET_NOISE_STATUS				_IO(VFE_IOC_MAGIC, VFE_IOC_CUSTOMER_IDX_9) //IOR unsigned char
#define VO_GET_USBVOINFO							_IO(VFE_IOC_MAGIC, VFE_IOC_CUSTOMER_IDX_10) //IOR VO_VOINFO
#define VFE_IOC_AVD_SET_AV_OUT						_IO(VFE_IOC_MAGIC, VFE_IOC_CUSTOMER_IDX_11) //IOW  unsigned char
#define VFE_IOC_AVD_DETECT_TIMING_IN_AUTOSCAN		_IO(VFE_IOC_MAGIC, VFE_IOC_CUSTOMER_IDX_12) //IOW unsigned char
#define VO_GET_USBVOINFO_EXTA0                                                  _IO(VFE_IOC_MAGIC, VFE_IOC_CUSTOMER_IDX_13) //IOR VO_VOINFO_EXT_A0

unsigned char get_ADC_Global_Status(void);
unsigned char get_AVD_Global_Status(void);
unsigned char get_ATV_Global_Status(void);
unsigned char get_HDMI_Global_Status(void);
unsigned char get_ADC_Input_Source(void);
unsigned char get_HDMI_Input_Source(void);
unsigned char get_AVD_Input_Source(void);

int VFE_AVD_OPEN(void);
int VFE_AVD_ATV_CONNECT(unsigned short PortNumber);
unsigned short VFE_AVD_ATV_GetCurrentPort(void);

/* Get VDC detect timing flag. */
unsigned char VDC_get_detect_flag(void);

/* hdmi rx ioctrl cmd definitions end */
#endif

