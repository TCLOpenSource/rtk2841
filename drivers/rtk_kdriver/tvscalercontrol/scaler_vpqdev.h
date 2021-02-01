#ifndef __SCALER_VPQDEV_H
#define  __SCALER_VPQDEV_H


/**
 * Video Picture Quality Information.
 *
 * @see DDI Implementation Guide
*/
#include <scalercommon/vipCommon.h>
#include <scalercommon/scalerDrvCommon.h>

#include <tvscalercontrol/vip/film.h>
#include <tvscalercontrol/vip/peaking.h>
#include <tvscalercontrol/vip/nr.h>
#include <tvscalercontrol/vip/icm.h>
#include <tvscalercontrol/vip/scalerColor_tv006.h>

#ifndef VIDEO_WID_T
	typedef enum{
		VIDEO_WID_MIN	= 0,				/**< WID min */
		VIDEO_WID_0 	= VIDEO_WID_MIN,	/**< WID main window */
		VIDEO_WID_1,						/**< WID sub window */
		VIDEO_WID_MAX	= VIDEO_WID_1,		/**< WID max */
		VIDEO_WID_MAXN, 					/**< WID max number */
	} __VIDEO_WID_T;
#define VIDEO_WID_T __VIDEO_WID_T
#endif

#ifndef SINT32
typedef signed int                __SINT32;
#define SINT32 __SINT32
#endif

typedef enum{
	UI_LEVEL_OFF = 0,
	UI_LEVEL_LOW,
	UI_LEVEL_MIDDLE,
	UI_LEVEL_HIGH,
	UI_LEVEL_AUTO,
	UI_LEVEL_SELECT_MAX,
} UI_LEVEL_SELECT;

typedef struct{
	UINT16 Red_Gain;
	UINT16 Green_Gain;
	UINT16 Blue_Gain;
	UINT16 Red_Offset;
	UINT16 Green_Offset;
	UINT16 Blue_Offset;
} COLORTEMP_ELEM_T;

typedef struct{
	UINT16 Gamme_Red[1024];
	UINT16 Gamme_Green[1024];
	UINT16 Gamme_Blue[1024];
} GAMMA_RGB_T;

typedef enum{
	PQ_DEV_NOTHING = 0,
	PQ_DEV_INIT_DONE,
	PQ_DEV_OPEN_DONE,
	PQ_DEV_UNINIT,
	PQ_DEV_CLOSE,
} PQ_DEV_STATUS;

typedef struct{
	UINT8 wId;
	UINT16 uDcVal;
	UINT32 pstData;
} FreshContrast_T;

typedef struct{
	signed int FreshContrastLUT[DCC_Curve_Node_MAX];
} FreshContrastLUT_T;

typedef struct{
	UINT32 bin[32];
} FreshContrastBin_T;

typedef struct{
	UINT32 chrm_bin[32];
} chrm_bin_T;

typedef struct{
	UINT32 hue_bin[24];
} hue_bin_T;

typedef struct{
	UINT8 wId;
	signed int uCgVal;
} ColorGain_T;


/* clear white gain control*/
typedef struct _HAL_VPQ_CLEAR_WHITE{
	VIDEO_WID_T wId;
	unsigned char enable;
	unsigned char mode;
	unsigned char Uoffset[VIP_YUV2RGB_Y_Seg_Max];
	unsigned char Voffset[VIP_YUV2RGB_Y_Seg_Max];
	unsigned char Ustep[VIP_YUV2RGB_Y_Seg_Max];
	unsigned char Vstep[VIP_YUV2RGB_Y_Seg_Max];
	unsigned char UV_index[VIP_YUV2RGB_Y_Seg_Max-1];
} HAL_VPQ_CLEAR_WHITE;

typedef struct _RTK_BLUE_STRETCH_T {
	unsigned char ctrl[4];
	DRV_Gamma_BS gamma_bs;
} RTK_BLUE_STRETCH_T;

/* set black level*/
typedef enum{
	SET_BLACK_LEVEL_ITEM_Level = 0,
	SET_BLACK_LEVEL_ITEM_Input_Info,
	SET_BLACK_LEVEL_ITEM_HDR_CSC1,
	SET_BLACK_LEVEL_ITEM_MAX,
} HAL_VPQ_SET_BLACK_LEVEL_ITEM;

typedef struct _HAL_VPQ_SET_BLACK_LEVEL{
	VIDEO_WID_T wId;
	UINT8 uBlVal[SET_BLACK_LEVEL_ITEM_MAX];
} HAL_VPQ_SET_BLACK_LEVEL;


typedef struct {
	unsigned int Gamut33Matrix[9];
} HDR_SetGamut33Matrix_T;

typedef struct {
	UINT16 hdr_3dlut[HDR_24x24x24_size*3];
} HDR_Set3DLUT_16_T;

typedef struct {
    UINT32 version;//Version = 0 wild card(default data
    UINT32 length;//pData Length
    UINT8  wId;//0 : main
    UINT32* pData;
} HAL_VPQ_DATA_T;

typedef struct{
	UINT8 extType; // index for type (eg. 0: POD, 1:PCID, 2:reserved)
	UINT8 *pExtData; // LUT table data
	UINT32 extLength;  // LUT data size // variable size
}HAL_VPQ_OD_Extention_T;

/**
*	3d mode type enum
*/
typedef enum{
	HAL_VPQ_3D_MODE_OFF = 0,		/*< 3d off, 3d to 2d*/
	HAL_VPQ_3D_MODE_3D_TB,			/*< 3d top and botom*/
	HAL_VPQ_3D_MODE_3D_SS,			/*< 3d side by side*/
	HAL_VPQ_3D_MODE_3D_CB,			/*< 3d checker board*/
	HAL_VPQ_3D_MODE_3D_FS,			/*< 3d frame seq*/
	HAL_VPQ_3D_MODE_3D_CI,			/*< 3d column interleave*/
	HAL_VPQ_3D_MODE_3D_LIH,			/*< 3d line interleave half*/
	HAL_VPQ_3D_MODE_3D_FP,			/*< 3d frame packing*/
	HAL_VPQ_3D_MODE_3D_FA,			/*< 3d field alternative*/
	HAL_VPQ_3D_MODE_3D_LA,			/*< 3d line alternative*/
	HAL_VPQ_3D_MODE_3D_SSF,			/*< 3d side by side full*/
	HAL_VPQ_3D_MODE_3D_DS,			/*< 3d dual stream*/
	HAL_VPQ_3D_MODE_2DTO3D,			/*< 2d to 3d*/
	HAL_VPQ_3D_MODE_MAX				/*< max num*/
}
HAL_VPQ_3D_MODE_T;

typedef enum{
	HAL_VPQ_INPUT_ATV = 0,			/*< analog rf*/
	HAL_VPQ_INPUT_AV,				/*< cvbs,svideo*/
	HAL_VPQ_INPUT_SCARTRGB,			/*< scart-rgb*/
	HAL_VPQ_INPUT_COMP,				/*< component*/
	HAL_VPQ_INPUT_RGB_PC,			/*< rgb-pc*/
	HAL_VPQ_INPUT_HDMI_TV,			/*< hdmi non-pc(hdmi-av,dvi-dtv,mcam)*/
	HAL_VPQ_INPUT_HDMI_PC,			/*< hdmi pc(dvi-pc)*/
	HAL_VPQ_INPUT_DTV,				/*< digital rf*/
	HAL_VPQ_INPUT_PICWIZ,			/*< dtv pic wiz*/
	HAL_VPQ_INPUT_PICTEST,			/*< dtv pic test*/
	HAL_VPQ_INPUT_MEDIA_MOVIE,		/*< divx, cp-divx*/
	HAL_VPQ_INPUT_MEDIA_PHOTO,		/*< photo, cp-photo*/
	HAL_VPQ_INPUT_CAMERA,			/*< vcs*/
	HAL_VPQ_INPUT_PVR_DTV,			/*< pvr dtv*/
	HAL_VPQ_INPUT_PVR_ATV,			/*< pvr atv*/
	HAL_VPQ_INPUT_PVR_AV,			/*< pvr av,scart-rgb*/
	HAL_VPQ_INPUT_MAX				/*< max num*/
}
HAL_VPQ_INPUT_T;

/**
*	HDR CSC1 enum
*/
typedef enum
{
	HAL_VPQ_HDR_OFF = 0,			///  the special control here, it is HDR ALL OFF
	HAL_VPQ_HDR_CSC1_BT709,
	HAL_VPQ_HDR_BT2020,

	HAL_VPQ_HDR_CSC1_MAX				///< max num
}
HAL_VPQ_HDR_CSC1_T;

typedef struct{
	short m[3][3];
} PANEL_MATRIX_T;

typedef struct{
	unsigned char uColorGamut;
	unsigned char uIsSD;
	unsigned char uIsPAL;
	CHIP_COLOR_GAMUT_MAPPING_IO_T gamutMapping;
} COLOR_GAMUT_T;

#define VPQ_IOC_MAGIC 'p'

enum vpq_ioc_pq_cmd{
	VPQ_IOC_PQ_CMD_INIT = 0,
	VPQ_IOC_PQ_CMD_UNINIT = 1,/* 1*/
	VPQ_IOC_PQ_CMD_OPEN = 2,/* 2*/
	VPQ_IOC_PQ_CMD_CLOSE = 3,/* 3*/
	VPQ_IOC_PQ_CMD_SET_COLOR_TEMP = 4,
	VPQ_IOC_PQ_CMD_SET_COLOR_FILTER = 5,
	VPQ_IOC_PQ_CMD_GET_MOTION_LEVEL = 6,
	VPQ_IOC_PQ_CMD_GET_NOISE_LEVEL = 7,
	VPQ_IOC_PQ_CMD_SET_GAMMA_LUT = 8,
	VPQ_IOC_PQ_CMD_SET_SPLIT_DEMO = 9,
	VPQ_IOC_PQ_CMD_SET_IRE_INNER_PATTERN = 10,
	VPQ_IOC_PQ_CMD_SET_FILM_MODE = 11,
	VPQ_IOC_PQ_CMD_SET_FILM_TABLE = 12,
	VPQ_IOC_PQ_CMD_SET_SHARPNESS_LEVEL = 13,
	VPQ_IOC_PQ_CMD_SET_SHARPNESS_TABLE = 14,
	VPQ_IOC_PQ_CMD_NR_PQA_TABLE = 15,
	VPQ_IOC_PQ_CMD_NR_PQA_INPUT_TABLE = 16,
	VPQ_IOC_PQ_CMD_NR_LEVEL = 17,
	VPQ_IOC_PQ_CMD_MPEGNR_LEVEL = 18,
	VPQ_IOC_PQ_CMD_GET_HistoData_Countbins = 19,
	VPQ_IOC_PQ_CMD_GET_HistoData_APL = 20,
	VPQ_IOC_PQ_CMD_GET_HistoData_Min = 21,
	VPQ_IOC_PQ_CMD_GET_HistoData_Max = 22,
	VPQ_IOC_PQ_CMD_GET_HistoData_PeakLow = 23,
	VPQ_IOC_PQ_CMD_GET_HistoData_PeakHigh = 24,
	VPQ_IOC_PQ_CMD_SET_FreshContrast = 25,
	VPQ_IOC_PQ_CMD_SET_FreshContrastLUT = 26,
	VPQ_IOC_PQ_CMD_GET_FreshContrastBypassLUT = 27,
	VPQ_IOC_PQ_CMD_SET_ColorGain = 28,
	VPQ_IOC_PQ_CMD_SET_CLEAR_WHITE_GAIN = 29,
	VPQ_IOC_PQ_CMD_SET_INIT_COLOR_ADV = 30,
	VPQ_IOC_PQ_CMD_SET_INIT_COLOR_EXP = 31,
	VPQ_IOC_PQ_CMD_SET_FRESH_COLOR = 32,
	VPQ_IOC_PQ_CMD_SET_PREFERRED_COLOR = 33,
	VPQ_IOC_PQ_CMD_SET_COLOR_MANAGEMENT = 34,
	VPQ_IOC_PQ_CMD_SET_3D_COLOR_CORRECTION = 35,
	VPQ_IOC_PQ_CMD_SET_Pic_Ctrl = 36,
	VPQ_IOC_PQ_CMD_SET_Black_Level = 37,
	VPQ_IOC_PQ_CMD_GET_HistoData_chrm_bin = 38,
	VPQ_IOC_PQ_CMD_GET_HistoData_hue_bin = 39,
	VPQ_IOC_PQ_CMD_GET_HistoData_skin_count = 40,
	VPQ_IOC_PQ_CMD_GET_HistoData_sat_status = 41,
	VPQ_IOC_PQ_CMD_GET_HistoData_diff_sum = 42,
	VPQ_IOC_PQ_CMD_GET_HistoData_texture = 43,
	VPQ_IOC_PQ_CMD_GET_HistoData_motion = 44,
	VPQ_IOC_PQ_CMD_SET_COLOR_GAMUT = 45,
	VPQ_IOC_PQ_CMD_SET_SAT_LUT = 46,
	VPQ_IOC_PQ_CMD_SET_FILM_FPS = 47,
	VPQ_IOC_PQ_CMD_SET_DITHER_BIT = 48,
	VPQ_IOC_PQ_CMD_GET_Input_V_Freq = 49,
	VPQ_IOC_PQ_CMD_SET_VPQ_Shp_Val = 50,
	VPQ_IOC_PQ_CMD_SET_EDGE_ENHANCE = 51,
	VPQ_IOC_PQ_CMD_SET_PROJECT_ID = 52,
	VPQ_IOC_PQ_CMD_SET_ICM_ELEM = 53,
	VPQ_IOC_PQ_CMD_SET_SR_TABLE = 54,
	VPQ_IOC_PQ_CMD_SET_GAMUT_3D_LUT_N9_BUFFER = 55,
	VPQ_IOC_PQ_CMD_SET_GAMUT_3D_LUT_N17_BUFFER = 56,
	VPQ_IOC_PQ_CMD_SET_GAMUT_3D_LUT_INDEX = 57,
	VPQ_IOC_PQ_CMD_SET_HDR_GAMUTMATRIX = 58,
	VPQ_IOC_PQ_CMD_SET_HDR_3DLUT = 59,
	VPQ_IOC_PQ_CMD_SET_LOWDEALY_MODE = 60,
	VPQ_IOC_PQ_CMD_SET_HDR_3DLUT_16 = 61,
	VPQ_IOC_PQ_CMD_HDR_DEMO_Mode_ON = 62,
	VPQ_IOC_PQ_CMD_HDR_DEMO_Mode_OFF = 63,
	VPQ_IOC_PQ_CMD_NR_INPUT = 64,
	VPQ_IOC_PQ_CMD_SET_HDR_3DLUT_24x24x24_16_1 = 65,
	VPQ_IOC_PQ_CMD_SET_HDR_3DLUT_24x24x24_16_2 = 66,
	VPQ_IOC_PQ_CMD_SET_HDR_Eotf = 67,
	VPQ_IOC_PQ_CMD_SET_HDR_Oetf = 68,
	VPQ_IOC_PQ_CMD_GET_HDR_PicInfo = 69,
	VPQ_IOC_PQ_CMD_SET_HDR_InvGamma = 70,
	VPQ_IOC_PQ_CMD_SET_BLUE_STRETCH = 71,
	VPQ_IOC_PQ_CMD_SET_PQModeInfo = 72,
	VPQ_IOC_PQ_CMD_SET_LOCALCONTRAST_PARAM = 73,
	VPQ_IOC_PQ_CMD_SET_OdExtentions = 74,
	VPQ_IOC_PQ_CMD_SET_Od = 75,
};


#define VPQ_IOC_INIT						_IO(VPQ_IOC_MAGIC, VPQ_IOC_PQ_CMD_INIT)
#define VPQ_IOC_UNINIT						_IO(VPQ_IOC_MAGIC, VPQ_IOC_PQ_CMD_UNINIT)
#define VPQ_IOC_OPEN						_IO(VPQ_IOC_MAGIC, VPQ_IOC_PQ_CMD_OPEN)
#define VPQ_IOC_CLOSE						_IO(VPQ_IOC_MAGIC, VPQ_IOC_PQ_CMD_CLOSE)
#define VPQ_IOC_SET_COLOR_TEMP				_IOW(VPQ_IOC_MAGIC, VPQ_IOC_PQ_CMD_SET_COLOR_TEMP, COLORTEMP_ELEM_T)
#define VPQ_IOC_SET_COLOR_FILTER			_IOW(VPQ_IOC_MAGIC, VPQ_IOC_PQ_CMD_SET_COLOR_FILTER, unsigned int)
#define VPQ_IOC_GET_MOTION_LEVEL			_IOR(VPQ_IOC_MAGIC, VPQ_IOC_PQ_CMD_GET_MOTION_LEVEL, unsigned int)
#define VPQ_IOC_GET_NOISE_LEVEL				_IOR(VPQ_IOC_MAGIC, VPQ_IOC_PQ_CMD_GET_NOISE_LEVEL, unsigned int)
#define VPQ_IOC_SET_GAMMA_LUT				_IOW(VPQ_IOC_MAGIC, VPQ_IOC_PQ_CMD_SET_GAMMA_LUT, GAMMA_RGB_T)
#define VPQ_IOC_SET_SPLIT_DEMO				_IOW(VPQ_IOC_MAGIC, VPQ_IOC_PQ_CMD_SET_SPLIT_DEMO, unsigned int)
#define VPQ_IOC_SET_IRE_INNER_PATTERN		_IOW(VPQ_IOC_MAGIC, VPQ_IOC_PQ_CMD_SET_IRE_INNER_PATTERN, unsigned int)
#define VPQ_IOC_SET_FILM_MODE				_IOW(VPQ_IOC_MAGIC, VPQ_IOC_PQ_CMD_SET_FILM_MODE, DRV_film_mode)
#define VPQ_IOC_SET_FILM_TABLE				_IOW(VPQ_IOC_MAGIC, VPQ_IOC_PQ_CMD_SET_FILM_TABLE, DRV_film_table_t)
#define VPQ_IOC_SET_SHARPNESS_LEVEL			_IOW(VPQ_IOC_MAGIC, VPQ_IOC_PQ_CMD_SET_SHARPNESS_LEVEL, DRV_Sharpness_Level)
#define VPQ_IOC_SET_SHARPNESS_TABLE			_IOW(VPQ_IOC_MAGIC, VPQ_IOC_PQ_CMD_SET_SHARPNESS_TABLE, CHIP_SHARPNESS_UI_T)
#define VPQ_IOC_SET_VPQ_Shp_Val		_IOW(VPQ_IOC_MAGIC, VPQ_IOC_PQ_CMD_SET_VPQ_Shp_Val, unsigned short)
#define VPQ_IOC_SET_EDGE_ENHANCE		_IOR(VPQ_IOC_MAGIC, VPQ_IOC_PQ_CMD_SET_EDGE_ENHANCE, CHIP_EDGE_ENHANCE_UI_T)
#define VPQ_IOC_SET_NR_PQA_TABLE			_IOW(VPQ_IOC_MAGIC, VPQ_IOC_PQ_CMD_NR_PQA_TABLE, unsigned char)
#define VPQ_IOC_SET_NR_PQA_INPUT_TABLE		_IOW(VPQ_IOC_MAGIC, VPQ_IOC_PQ_CMD_NR_PQA_INPUT_TABLE, unsigned char)
#define VPQ_IOC_SET_NR_LEVEL 				_IOW(VPQ_IOC_MAGIC, VPQ_IOC_PQ_CMD_NR_LEVEL, CHIP_NOISE_REDUCTION_T)
#define VPQ_IOC_SET_MPEGNR_LEVEL 			_IOW(VPQ_IOC_MAGIC, VPQ_IOC_PQ_CMD_MPEGNR_LEVEL, CHIP_MPEG_NOISE_REDUCTION_T)
#define VPQ_IOC_GET_HistoData_Countbins		_IOR(VPQ_IOC_MAGIC, VPQ_IOC_PQ_CMD_GET_HistoData_Countbins, FreshContrastBin_T)
#define VPQ_IOC_GET_HistoData_chrm_bin		_IOR(VPQ_IOC_MAGIC, VPQ_IOC_PQ_CMD_GET_HistoData_chrm_bin, chrm_bin_T)
#define VPQ_IOC_GET_HistoData_hue_bin		_IOR(VPQ_IOC_MAGIC, VPQ_IOC_PQ_CMD_GET_HistoData_hue_bin, hue_bin_T)
#define VPQ_IOC_GET_HistoData_APL			_IOR(VPQ_IOC_MAGIC, VPQ_IOC_PQ_CMD_GET_HistoData_APL, unsigned int)
#define VPQ_IOC_GET_HistoData_Min			_IOR(VPQ_IOC_MAGIC, VPQ_IOC_PQ_CMD_GET_HistoData_Min, signed int)
#define VPQ_IOC_GET_HistoData_Max			_IOR(VPQ_IOC_MAGIC, VPQ_IOC_PQ_CMD_GET_HistoData_Max, signed int)
#define VPQ_IOC_GET_HistoData_PeakLow		_IOR(VPQ_IOC_MAGIC, VPQ_IOC_PQ_CMD_GET_HistoData_PeakLow, signed int)
#define VPQ_IOC_GET_HistoData_PeakHigh		_IOR(VPQ_IOC_MAGIC, VPQ_IOC_PQ_CMD_GET_HistoData_PeakHigh, signed int)
#define VPQ_IOC_GET_HistoData_skin_count	_IOR(VPQ_IOC_MAGIC, VPQ_IOC_PQ_CMD_GET_HistoData_skin_count, unsigned int)
#define VPQ_IOC_GET_HistoData_sat_status	_IOR(VPQ_IOC_MAGIC, VPQ_IOC_PQ_CMD_GET_HistoData_sat_status, unsigned int)
#define VPQ_IOC_GET_HistoData_diff_sum		_IOR(VPQ_IOC_MAGIC, VPQ_IOC_PQ_CMD_GET_HistoData_diff_sum, unsigned int)
#define VPQ_IOC_GET_HistoData_motion		_IOR(VPQ_IOC_MAGIC, VPQ_IOC_PQ_CMD_GET_HistoData_motion, unsigned int)
#define VPQ_IOC_GET_HistoData_texture 		_IOR(VPQ_IOC_MAGIC, VPQ_IOC_PQ_CMD_GET_HistoData_texture, unsigned int)
#define VPQ_IOC_SET_FreshContrast			_IOW(VPQ_IOC_MAGIC, VPQ_IOC_PQ_CMD_SET_FreshContrast, CHIP_DCC_T)
#define VPQ_IOC_SET_FreshContrastLUT		_IOW(VPQ_IOC_MAGIC, VPQ_IOC_PQ_CMD_SET_FreshContrastLUT, FreshContrastLUT_T)
#define VPQ_IOC_GET_FreshContrastBypassLUT	_IOR(VPQ_IOC_MAGIC, VPQ_IOC_PQ_CMD_GET_FreshContrastBypassLUT, FreshContrastLUT_T)
#define VPQ_IOC_SET_ColorGain				_IOW(VPQ_IOC_MAGIC, VPQ_IOC_PQ_CMD_SET_ColorGain, RTK_COLOR_GAIN_T)
#define VPQ_IOC_SET_CLEAR_WHITE_GAIN 		_IOW(VPQ_IOC_MAGIC, VPQ_IOC_PQ_CMD_SET_CLEAR_WHITE_GAIN, HAL_VPQ_CLEAR_WHITE)
#define VPQ_IOC_SET_INIT_COLOR_ADV			_IOW(VPQ_IOC_MAGIC, VPQ_IOC_PQ_CMD_SET_INIT_COLOR_ADV, unsigned int)
#define VPQ_IOC_SET_INIT_COLOR_EXP			_IOW(VPQ_IOC_MAGIC, VPQ_IOC_PQ_CMD_SET_INIT_COLOR_EXP, unsigned int)
#define VPQ_IOC_SET_FRESH_COLOR			_IOWR(VPQ_IOC_MAGIC, VPQ_IOC_PQ_CMD_SET_FRESH_COLOR, unsigned int)
#define VPQ_IOC_SET_PREFERRED_COLOR			_IOWR(VPQ_IOC_MAGIC, VPQ_IOC_PQ_CMD_SET_PREFERRED_COLOR, unsigned int)
#define VPQ_IOC_SET_COLOR_MANAGEMENT		_IOWR(VPQ_IOC_MAGIC, VPQ_IOC_PQ_CMD_SET_COLOR_MANAGEMENT, unsigned int)
#define VPQ_IOC_SET_3D_COLOR_CORRECTION		_IOW(VPQ_IOC_MAGIC, VPQ_IOC_PQ_CMD_SET_3D_COLOR_CORRECTION, unsigned int)
#define VPQ_IOC_SET_PIC_CTRL 				_IOW(VPQ_IOC_MAGIC, VPQ_IOC_PQ_CMD_SET_Pic_Ctrl, VPQ_SetPicCtrl_T)
#define VPQ_IOC_SET_BLACK_LEVEL 			_IOW(VPQ_IOC_MAGIC, VPQ_IOC_PQ_CMD_SET_Black_Level, HAL_VPQ_SET_BLACK_LEVEL)
#define VPQ_IOC_SET_COLOR_GAMUT				_IOW(VPQ_IOC_MAGIC, VPQ_IOC_PQ_CMD_SET_COLOR_GAMUT, COLOR_GAMUT_T)
#define VPQ_IOC_SET_SAT_LUT					_IOW(VPQ_IOC_MAGIC, VPQ_IOC_PQ_CMD_SET_SAT_LUT, VPQ_SAT_LUT_T)
#define VPQ_IOC_SET_FILM_FPS				_IOW(VPQ_IOC_MAGIC, VPQ_IOC_PQ_CMD_SET_FILM_FPS, unsigned int)
#define VPQ_IOC_SET_DITHER_BIT				_IOW(VPQ_IOC_MAGIC, VPQ_IOC_PQ_CMD_SET_DITHER_BIT, unsigned int)
#define VPQ_IOC_GET_Input_V_Freq			_IOR(VPQ_IOC_MAGIC, VPQ_IOC_PQ_CMD_GET_Input_V_Freq, unsigned int)
#define VPQ_IOC_SET_PROJECT_ID				_IOW(VPQ_IOC_MAGIC, VPQ_IOC_PQ_CMD_SET_PROJECT_ID, unsigned int)
#define VPQ_IOC_SET_ICM_ELEM				_IOW(VPQ_IOC_MAGIC, VPQ_IOC_PQ_CMD_SET_ICM_ELEM, unsigned int)
#define VPQ_IOC_SET_SR_TABLE				_IOW(VPQ_IOC_MAGIC, VPQ_IOC_PQ_CMD_SET_SR_TABLE, RTK_SR_UI_T)
#define VPQ_IOC_SET_GAMUT_3D_LUT_N9_BUFFER		_IOW(VPQ_IOC_MAGIC, VPQ_IOC_PQ_CMD_SET_GAMUT_3D_LUT_N9_BUFFER, unsigned int)
#define VPQ_IOC_SET_GAMUT_3D_LUT_N17_BUFFER		_IOW(VPQ_IOC_MAGIC, VPQ_IOC_PQ_CMD_SET_GAMUT_3D_LUT_N17_BUFFER, unsigned int)
#define VPQ_IOC_SET_GAMUT_3D_LUT_INDEX			_IOW(VPQ_IOC_MAGIC, VPQ_IOC_PQ_CMD_SET_GAMUT_3D_LUT_INDEX, unsigned int)
#define VPQ_IOC_SET_HDR_GAMUTMATRIX		_IOW(VPQ_IOC_MAGIC, VPQ_IOC_PQ_CMD_SET_HDR_GAMUTMATRIX, HDR_SetGamut33Matrix_T)
#define VPQ_IOC_SET_HDR_3DLUT		_IOW(VPQ_IOC_MAGIC, VPQ_IOC_PQ_CMD_SET_HDR_3DLUT, int)
#define VPQ_IOC_SET_LOWDELAY_MODE		_IOW(VPQ_IOC_MAGIC, VPQ_IOC_PQ_CMD_SET_LOWDEALY_MODE,unsigned int)
#define VPQ_IOC_SET_HDR_3DLUT_16	_IOW(VPQ_IOC_MAGIC, VPQ_IOC_PQ_CMD_SET_HDR_3DLUT_16, int)
#define VPQ_IOC_HDR_DEMO_Mode_ON	_IOW(VPQ_IOC_MAGIC, VPQ_IOC_PQ_CMD_HDR_DEMO_Mode_ON, int)
#define VPQ_IOC_HDR_DEMO_Mode_OFF	_IOW(VPQ_IOC_MAGIC, VPQ_IOC_PQ_CMD_HDR_DEMO_Mode_OFF, int)
#define VPQ_IOC_SET_NR_INPUT 		_IOW(VPQ_IOC_MAGIC, VPQ_IOC_PQ_CMD_NR_INPUT, unsigned char)
#define VPQ_IOC_SET_HDR_3DLUT_24x24x24_16_1	_IOW(VPQ_IOC_MAGIC, VPQ_IOC_PQ_CMD_SET_HDR_3DLUT_24x24x24_16_1, int)
#define VPQ_IOC_SET_HDR_3DLUT_24x24x24_16_2	_IOW(VPQ_IOC_MAGIC, VPQ_IOC_PQ_CMD_SET_HDR_3DLUT_24x24x24_16_2, int)
#define VPQ_IOC_SET_HDR_Eotf	_IOW(VPQ_IOC_MAGIC, VPQ_IOC_PQ_CMD_SET_HDR_Eotf, int)
#define VPQ_IOC_SET_HDR_Oetf	_IOW(VPQ_IOC_MAGIC, VPQ_IOC_PQ_CMD_SET_HDR_Oetf, int)
#define VPQ_IOC_GET_HDR_PicInfo	_IOR(VPQ_IOC_MAGIC, VPQ_IOC_PQ_CMD_GET_HDR_PicInfo, int)
#define VPQ_IOC_SET_HDR_InvGamma	_IOW(VPQ_IOC_MAGIC, VPQ_IOC_PQ_CMD_SET_HDR_InvGamma, unsigned char)
#define VPQ_IOC_SET_BLUE_STRETCH 			_IOW(VPQ_IOC_MAGIC, VPQ_IOC_PQ_CMD_SET_BLUE_STRETCH, unsigned int)
#define VPQ_IOC_SET_PQModeInfo	_IOW(VPQ_IOC_MAGIC, VPQ_IOC_PQ_CMD_SET_PQModeInfo, int)
#define VPQ_IOC_SET_LOCALCONTRAST_PARAM	_IOW(VPQ_IOC_MAGIC, VPQ_IOC_PQ_CMD_SET_LOCALCONTRAST_PARAM, CHIP_LOCAL_CONTRAST_T)
#define VPQ_IOC_SET_OdExtentions  _IOW(VPQ_IOC_MAGIC, VPQ_IOC_PQ_CMD_SET_OdExtentions, _HAL_VPQ_DATA_T)
#define VPQ_IOC_SET_Od _IOW(VPQ_IOC_MAGIC, VPQ_IOC_PQ_CMD_SET_Od, HAL_VPQ_DATA_T)


typedef struct {
    /*Clk*/
	UINT32 CRT_PLL_SSC0_S_R;
    	UINT32 CRT_PLL_SSC3_S_R;
	UINT32 CRT_PLL_SSC4_S_R;
	UINT32 CRT_SYS_DCLKSS_S_R;
	UINT32 CRT_SYS_PLL_DISP1_S_R;
	UINT32 CRT_SYS_PLL_DISP2_S_R;
	UINT32 CRT_SYS_PLL_DISP3_S_R;
	UINT32 CRT_SYS_DISPCLKSEL_S_R;
} VPQ_SUSPEND_RESUME_T;

typedef struct {
	UINT32 OD_DMA_ODDMA_CMP_RESOLUTION_S_R;
	UINT32 OD_DMA_ODDMA_COMP_SETTING_S_R;
	UINT32 OD_DMA_ODDMA_DECMP_RESOLUTION_S_R;
	UINT32 OD_DMA_ODDMA_DECOMP_SETTING_S_R;
	UINT32 OD_DMA_DECOMP_COMPENSATION_S_R;
	UINT32 OD_DMA_OD_DMA_CTRL4_S_R;
	UINT32 OD_DMA_ODDMA_LR_SEPARATE_CTRL1_S_R;
	UINT32 OD_DMA_ODDMA_LR_SEPARATE_CTRL2_S_R;
	UINT32 OD_DMA_ODDMA_DISPLAY11_NUMWTL_S_R;
	UINT32 OD_DMA_ODDMA_DISPLAY11_RDNUMLENREM_S_R;
	UINT32 OD_DMA_ODDMA_DISP11_LINESTEP_S_R;
	UINT32 OD_DMA_ODDMA_DISPLAY11_LINENUM_S_R;
	UINT32 OD_DMA_ODDMA_CAP_L1_START_S_R;
	UINT32 OD_DMA_ODDMA_CAP_L2_START_S_R;
	UINT32 OD_DMA_ODDMA_DISP11_START_ADDR_L1_S_R;
	UINT32 OD_DMA_ODDMA_DISP11_START_ADDR_L2_S_R;
	UINT32 OD_DMA_ODDMA_CAP_CTL2_S_R;
	UINT32 OD_DMA_ODDMA_CAP_CTL0_S_R;
	UINT32 OD_DMA_ODDMA_CAP_CTL1_S_R;
	UINT32 OD_DMA_ODDMA_FRC_CTRL_S_R;
	UINT32 OD_DMA_ODDMA_DISPLAY_CTRL_S_R;
	UINT32 OD_DMA_ODDMA_COMP_DECOMP_CLK_GATED_S_R;
	UINT32 OD_DMA_ODDMA_COMPRESS_IRQ_EN_S_R;
	UINT32 OD_DMA_ODDMA_DECOMP_IRQ_EN_S_R;
	UINT32 OD_DMA_ODDMA_INTERRUPT_ENABLE_S_R;
	UINT32 OD_DMA_ODDMA_CRC_CTRL_S_R;
	unsigned char od_enable;
} OD_SUSPEND_RESUME_T;

typedef struct {
    UINT32 version;//Version = 0 wild card(default data
    UINT32 length;//pData Length
    UINT8  wId;//0 : main
    UINT8* pData;
} _HAL_VPQ_DATA_T;

void vpq_do_suspend(void);
void vpq_do_resume(void);
void vpq_do_resume_instanboot(void);
unsigned char vpq_get_handler_bypass(void);
#endif
