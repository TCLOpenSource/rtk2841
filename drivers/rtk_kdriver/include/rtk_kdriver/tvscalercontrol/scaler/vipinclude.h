#ifndef __VIP_INCLUDE_H__
#define __VIP_INCLUDE_H__


#ifdef __cplusplus
extern "C" {
#endif

/*#include <base_types.h>*/
/*#include "setupdef_picmode.h"*/
#include <scalercommon/vipCommon.h>	/* in common*/
/*#include <tvscalercontrol/vip/peaking.h> */ /*mark by ren 140527, no more used and it will cause vipRelease compiler error*/


#include <rbus/di_reg.h>
#include <rbus/nr_reg.h>
#include <rbus/vdpq_reg.h>
#include <rbus/color_sharp_reg.h>
#include <scalercommon/vipCommon.h>

#include <rbus/color_edge_smooth_reg.h> // 20151008, willy, need to control DI vertical LPF in PQA
#include <rbus/iedge_smooth_reg.h>
/*#include <tvscalercontrol/scaler/setupdef_picmode.h>*/
#define _empty 0
/*-----------------------------------------------------------------------------*/
/* from scalerStruct.h*/
/*-----------------------------------------------------------------------------*/
/*#pragma pack(push)*/  /* push current alignment to stack */
#pragma pack(4)     /* set alignment to 4 byte boundary */

extern unsigned char ucIsPrintVIP;
/*#define VIPprintf(fmt, args...)	printk(KERN_DEBUG fmt, ##args)*/

#define OSD_FOUR_LEVEL_MAPPING_ENABLE
#define SR_MAX_YPBPR_GAINOFFSET_MODE	15

typedef struct _ADCGainOffset {
    unsigned short Gain_R;	/*In fact, 11bits */
    unsigned short Gain_G;	/*In fact, 11bits */
    unsigned short Gain_B;	/*In fact, 11bits */
    unsigned short Offset_R;	/*In fact, 11bits */
    unsigned short Offset_G;	/*In fact, 11bits */
    unsigned short Offset_B;	/*In fact, 11bits */
} ADCGainOffset;



typedef struct {
    unsigned char ModeNum;                   /* Mode Number*/
    unsigned short IHFreq;                    /* Input Horizontal Frequency*/
    unsigned short IVFreq;                    /* Input Vertical Frequency*/
} StructModeUserFIFODataType;

typedef struct _StructColorDataType {
	unsigned char MBPeaking;
	unsigned char Intensity;
	unsigned char Gamma;
	unsigned char DLti;
	unsigned char DCti;
	unsigned char Film;		/* BIT 0~3: 22 mode, BIT4~7: 32 mode*/
	unsigned char NRSpatialY;	/* Erin modify for Atlantic 100406*/
	unsigned char NRSpatialC;	/* Erin modify for Atlantic 100406*/
	unsigned char iESM;		/*Lydia modify for Macarthur 1010210*/
	unsigned char Vertical_NR;
	unsigned char iESM_en;
	unsigned char iESM_extension;
	unsigned char iESM_t2df;
	unsigned char iESM_crct;
	unsigned char iESM_chaos;
	unsigned char iESM_edge;
	unsigned char NRTemporal;
	unsigned char ChromaErrReduction;
	unsigned char NoiseEstimation;
	unsigned char MotionAdaptive;
	unsigned char CrossColor;
	unsigned char Intra;
	unsigned char ScaleUpH;
	unsigned char ScaleUpV;
	unsigned char ScaleUpH_8tap;		/*20140327 roger*/
	unsigned char ScaleUpV_6tap;		/*20140327 roger*/
	unsigned char ScaleUpDir;
	unsigned char ScaleUpDir_weighting;
	unsigned char ScalePK;
	unsigned char DccLevel;
	unsigned char LowAngle;
	unsigned char DNR;	/*yyfor compile 10.25*/
	unsigned char SceneMode; /*jacklong 03/31 add*/
	unsigned char I_DLTi;
	unsigned char I_DCTi;
	unsigned char I_NEWDCTi;
	unsigned char memc22;
	unsigned char memc32;
	unsigned char tnr_xc_ctrl;
	/*unsigned char rtnr;	*/ /*no use now, but remove it hard, so we keep	*/ /*Elsie 20140107: now we can remove it*/
	unsigned char V_DCTi;
	/*unsigned char I_Ccoring;*/ /*no use now, maybe remove it*/
	/*unsigned char D_Ccoring;*/ /*no use now, maybe remove it*/
	/*unsigned char YUV2RGB_COEF_BY_Y_Table_Select;*/
	/*unsigned char YUV2RGB_UV_OFFSET_BY_Y_Table_Select;*/
	unsigned char YUV2RGB_Table_Select;
	unsigned char YUV2RGB_double_coef_EN;
	unsigned char gridRemove;
	unsigned char ContiStillLine;
	unsigned char IntraNewBlend;
	unsigned char IntraNewLowangle;
	unsigned char SUPK_type;
	unsigned char rtnr_y;
	unsigned char rtnr_c;
	unsigned char Spread_Spectrum;
	unsigned char Sindex;
	unsigned char Shigh;
	unsigned char Slow;
	unsigned char Gammadebug;  /*add by Diane*/
	unsigned char Gainred; /*add by Diane*/
	unsigned char Gaingreen; /*add by Diane*/
	unsigned char Gainblue; /*add by Diane*/
	unsigned char Centerred; /*add by Diane*/
	unsigned char Centergreen; /*add by Diane*/
	unsigned char Centerblue; /*add by Diane*/
	unsigned char TwoD_peaking_AdaptiveCtrl;

	/* sync to pacific */ /* hsinyi21 20100324*/
	unsigned char DCL_B;
	unsigned char DCL_W;
	unsigned char Shp_Vgain;
	unsigned char Egsm_postshp_level;
	unsigned char Egsm_Postshp_table;
	unsigned char Dering;
	unsigned char MA_BTR;
	unsigned char MA_BER;
	unsigned char IntraAllPacificNew;
	unsigned char H8_Scaling;
	unsigned char Shp_Table;
	unsigned char emf_mk2;
	unsigned char tnrxc_mk2;
	unsigned char SKIPIR_ring;
	unsigned char SKIPIR_islet;
	unsigned char SKIPIR_dnoise;
	unsigned char SKIPIR_dnoise_table;
	unsigned char VIP_debug_mode;
	unsigned char ICM_Table;
	unsigned char ICM_7Axis_Table;
	unsigned char ICM_7Axis_adjust_value[Axis_Max];
	unsigned char CDS_Table;/*planck 20101103.*/
	unsigned char UnsharpMask;/*planck 20101104*/
	unsigned char MPEGNR_H;/*csfanchiang 20101127*/
	unsigned char MPEGNR_V;/*csfanchiang 20101127*/
	unsigned char PQA_Table;
	unsigned char PQA_I_Table;
	unsigned char Shp_2Dpk_Seg;
	unsigned char Shp_2Dpk_Tex_Detect;
	unsigned char DCC_Slow;
	unsigned char DCC_Shigh;
	unsigned char DCC_Sindex;
	unsigned char HMCNR_range;
	unsigned char HMCNR_blending;
	unsigned char DLTI_fd1_ratio;
	unsigned char DCC_extend_style;
	unsigned char DCC_W_expand;/*DCC_W_extend;*/
	unsigned char DCC_B_expand;/*DCC_B_extend;*/
	unsigned char DCC_W_index;
	unsigned char DCC_B_index;
	unsigned char DCC_style;
	unsigned char DCC_Blending_DelayTime;
	unsigned char DCC_Blending_Step;
	unsigned char DCC_hist_adjust_table;
	unsigned char SR_edge_gain;
	unsigned char SR_texture_gain;
	unsigned char DCC_table_select;
	unsigned char DCC_Color_Independent_table_select;
	unsigned char DCC_chroma_compensation_table_select;
	unsigned char Adaptive_Gamma;
	unsigned char ScaleDownHTable;
	unsigned char ScaleDownVTable;
	unsigned char DCC_Histogram_gain[DCC_Histogram_gain_bin_max];
	unsigned char DCC_Histogram_offset[DCC_Histogram_offset_bin_max];
	unsigned char DCC_Histogram_limit[DCC_Histogram_limit_bin_max];
	unsigned char Custom_Style;
	unsigned char DCC_adaptive_Level_Table;
	unsigned char DCC_database_Table;
	unsigned char DCC_UserCurve_Table;
	unsigned char DCC_Picture_Mode_Weight;
	unsigned char DCC_Boundary_Check_Table;
	unsigned char DCC_Level_and_Blend_Coef_Table;

	unsigned short UV_Delay_Enable;
	unsigned short UV_Delay;
	unsigned char  VD_ConBriHueSat_Table;

	/*for T2 2644i, elieli20131001*/
	unsigned char WB_Pattern_R;
	unsigned char WB_Pattern_G;
	unsigned char WB_Pattern_B;
	unsigned short Gamma_Pattern_R;
	unsigned short Gamma_Pattern_G;
	unsigned short Gamma_Pattern_B;
	unsigned short PQ_byPass_En;

	unsigned short RTNR_NM;
	unsigned char MA_Chroma_Error;
	unsigned char MADI_HMC;
	unsigned char MADI_HME;
	unsigned char MADI_PAN;

	unsigned char LocalDimmingEnable;
	unsigned char LocalDimmingTable;
	unsigned char DISMDTable;

	unsigned char color_new_uvc;
	unsigned char blue_stretch;

	unsigned char color_de_countour;	/*Elsie 20150310*/
	unsigned char LocalContrastEnable;
	unsigned char LocalContrastTable;
	unsigned char LocalContrastDemoMode;
	unsigned char V_DCTi_Lpf;
	unsigned char d3dLUT;
	unsigned char I_De_XC;
	unsigned char Output_InvOutput_GAMMA;
	unsigned char ScaleUpH_C;
	unsigned char ScaleUpV_C;
	unsigned char ScaleUP_TwoStep;
	unsigned char OSD_Sharpness;
} StructColorDataType;

typedef struct {

	unsigned char Gainred; /*add by Diane*/
	unsigned char Gaingreen; /*add by Diane*/
	unsigned char Gainblue; /*add by Diane*/
	unsigned char Centerred; /*add by Diane*/
	unsigned char Centergreen; /*add by Diane*/
	unsigned char Centerblue; /*add by Diane*/

} StructGammaFactoryDataType;

#ifdef OSD_FOUR_LEVEL_MAPPING_ENABLE
typedef struct {

	unsigned char Brightness_0;
	unsigned char Brightness_25;
	unsigned char Brightness_50;
	unsigned char Brightness_75;
	unsigned char Brightness_100;
	unsigned char Contrast_0;
	unsigned char Contrast_25;
	unsigned char Contrast_50;
	unsigned char Contrast_75;
	unsigned char Contrast_100;
	unsigned char Saturation_0;
	unsigned char Saturation_25;
	unsigned char Saturation_50;
	unsigned char Saturation_75;
	unsigned char Saturation_100;
	unsigned char Hue_0;
	unsigned char Hue_25;
	unsigned char Hue_50;
	unsigned char Hue_75;
	unsigned char Hue_100;
	unsigned char Sharpness_0;
	unsigned char Sharpness_25;
	unsigned char Sharpness_50;
	unsigned char Sharpness_75;
	unsigned char Sharpness_100;
	unsigned char Backlight_0;
	unsigned char Backlight_25;
	unsigned char Backlight_50;
	unsigned char Backlight_75;
	unsigned char Backlight_100;

} StructColorDataFacModeType;

typedef enum _FAC_COLOR_INDEX {
    FAC_BRIGHTNESS,
    FAC_CONTRAST,
    FAC_SATURATION,
    FAC_HUE,
    FAC_SHARPNESS,
    FAC_BACKLIGHT,
    FAC_CURVE_MAX = FAC_BACKLIGHT,
} FAC_COLOR_INDEX;

typedef enum _FAC_COLOR_ITEM {
    FAC_ITEM_0,
    FAC_ITEM_25,
    FAC_ITEM_50,
    FAC_ITEM_75,
    FAC_ITEM_100,
} FAC_COLOR_ITEM;

#else

typedef struct{

	unsigned char Brightness_0;
	unsigned char Brightness_50;
	unsigned char Brightness_100;
	unsigned char Contrast_0;
	unsigned char Contrast_50;
	unsigned char Contrast_100;
	unsigned char Saturation_0;
	unsigned char Saturation_50;
	unsigned char Saturation_100;
	unsigned char Hue_0;
	unsigned char Hue_50;
	unsigned char Hue_100;
	unsigned char Sharpness_0;
	unsigned char Sharpness_50;
	unsigned char Sharpness_100;
	unsigned char Backlight_0;
	unsigned char Backlight_50;
	unsigned char Backlight_100;

} StructColorDataFacModeType;

#endif

#if 0
typedef struct {

	unsigned char SU_H;
	unsigned char SU_V;
	unsigned char S_PK;
	unsigned char SUPK_MASK;
	unsigned char Unsharp_Mask;
	unsigned char SHP1D2D_EGSM;
	unsigned char EGSM_Postshp_Table; /*6:SKIPIR_dnoise_LVth_max*/
	unsigned char iEGSM_table; /*7: SKIPIR_dnoise_LVth_min*/
	unsigned char TwoStep_SU_Table; /*8: SKIPIR_dnoise_gainth_min*/
	unsigned char SR_edge_gain; /*9: SKIPIR_dnoise_gainth_min*/
	unsigned char SR_tex_gain;
	unsigned char SD_H_table;
	unsigned char SD_V_table;
	unsigned char SD_444To422;
	unsigned char ColorSpace_control;
	unsigned char Reserved_15;
	unsigned char Reserved_16;
	unsigned char Reserved_17;
	unsigned char Reserved_18;
	unsigned char Reserved_19;
	unsigned char Reserved_20;

} VIP_QUALITY_Extend2_Coef;

typedef struct {

	unsigned char DNR_Table;		/*Lydia modify for Macarthur 1010210*/
	unsigned char VerticalNR;
	unsigned char Dering;
	unsigned char newRTNR_style;
	unsigned char newRTNR_mixWeight;
	unsigned char RTNR_CORRECTION_BIT;
	unsigned char DI_SMD_enable;
	unsigned char Reserved_07;
	unsigned char Reserved_08;
	unsigned char Reserved_09;
	unsigned char Reserved_10;
	unsigned char Reserved_11;
	unsigned char Reserved_12;
	unsigned char Reserved_13;
	unsigned char Reserved_14;
	unsigned char Reserved_15;
	unsigned char Reserved_16;
	unsigned char Reserved_17;
	unsigned char Reserved_18;
	unsigned char Reserved_19;
	unsigned char Reserved_20;

} VIP_QUALITY_Extend3_Coef;

typedef struct {

	unsigned char Reserved_00;
	unsigned char Reserved_01;
	unsigned char Reserved_02;
	unsigned char Reserved_03;
	unsigned char Reserved_04;
	unsigned char Reserved_05;
	unsigned char Reserved_06;
	unsigned char Reserved_07;
	unsigned char Reserved_08;
	unsigned char Reserved_09;
	unsigned char Reserved_10;
	unsigned char Reserved_11;
	unsigned char Reserved_12;
	unsigned char Reserved_13;
	unsigned char Reserved_14;
	unsigned char Reserved_15;
	unsigned char Reserved_16;
	unsigned char Reserved_17;
	unsigned char Reserved_18;
	unsigned char Reserved_19;
	unsigned char Reserved_20;

} VIP_QUALITY_Extend4_Coef;

/*young 3Dtable*/
typedef struct {

	unsigned char S_Gamma_Index;
	unsigned char S_Gamma_High;
	unsigned char S_Gamma_Low;
	unsigned char S_PK;
	unsigned char SUPK_MASK;
	unsigned char UNSHARP_MASK;
	unsigned char Sharpness_table;
	unsigned char DCC;
	unsigned char DCL_W;
	unsigned char DCL_B;
	unsigned char NRSPAT;
	unsigned char rtnr_y	;
	unsigned char rtnr_c	;
	unsigned char ICM	;
	unsigned char iESM;
	unsigned char Reserved_15;
	unsigned char Reserved_16;
	unsigned char Reserved_17;
	unsigned char Reserved_18;
	unsigned char Reserved_19;
	unsigned char Reserved_20;


} VIP_QUALITY_3Dmode_Coef;
#endif 

typedef enum _DCR_MODE{
    DCR_MASTER,
    DCR_SLAVE,
    DCR_MODE_MAX,
} DCR_MODE;

typedef enum _VIP_Access_Memory_DisplayInfo_Coef{
	inputsrc = 0,
	HDMI_Data_Range = 1,
	Frame_rate_input = 2,
	Frame_rate_output = 3,
	DisplayInfo_Coef_MAX,
} VIP_Access_Memory_DisplayInfo_Coef;

/*-----------------------------------------------------------------------------*/
/* from scalerLib.h*/
/*-----------------------------------------------------------------------------*/
/*#if defined(BUILD_TV005_1_ATV) || defined(BUILD_TV005_1_ATSC) || defined(BUILD_TV057_1_ATV)*/


/*#if  defined(BUILD_TV005_1_ATV) || defined(BUILD_TV005_1_ATSC) || defined(BUILD_TV057_1_ATV)*/
#if defined(PQ_005_STYLE) || defined(BUILD_TV005_2)

typedef struct {
	char	gainDiff_R;
	char	gainDiff_G;
	char	gainDiff_B;
} GainDiff;

typedef struct {
	GainDiff		warm;
	GainDiff		normal;
	GainDiff		cool;
} ColorTemp_Gain_Diff;
#endif

#if  defined(IS_TV05_STYLE_PICTUREMODE)
typedef struct _SLR_PICTURE_MODE_DATA {
	VIP_TABLE_COLORSTD_ENUM mode;	/*20120409 roger*/

	unsigned char Brightness;
	unsigned char Contrast;
	unsigned char Saturation;
	unsigned char Hue;
	unsigned char Sharpness;
	unsigned char DNR;
	unsigned char DccMode;
	unsigned char ColorTemp;
	unsigned char DCRMode; /*sync from AT*/
	unsigned char BackLight;
	unsigned char MEMC;
	unsigned char MPEG;
	unsigned char xvYcc_Mode;

	unsigned char Modification:4;   /*cloud: 1: user mode*/
	unsigned char Cinema:4;   /*cloud:*/
	ColorTemp_Gain_Diff	RGB_Diff;
#if (defined (PQ_005_STYLE))/*yuan::20130624*/
		unsigned char Auto_NR;	/*yuan20130314::add for Auto_NR by picture mode*/
#endif


} SLR_PICTURE_MODE_DATA;

#elif defined(IS_TV003_STYLE_PICTUREMODE)   /*TV003_ADTV*/
#define SLR_COLORTEMP_MAX_NUM_X    (13)
#define SLR_COLORTEMP_MAX_NUM_Y    (7)
#define SLR_COLORTEMP_MID_NUM_X	   (6)
#define SLR_COLORTEMP_MID_NUM_Y    (3)
#if defined(PQ_03_3_ColorTemp)
typedef enum _SLR_COLOR_TEMP_MODE {
	SLR_COLOR_TEMP_LOW = 0,
	SLR_COLOR_TEMP_MIDDLE,
	SLR_COLOR_TEMP_HIGH,
	SLR_COLOR_TEMP_MAX,
} SLR_COLOR_TEMP_MODE;
#endif
typedef struct {
	unsigned char X_index;
	unsigned char Y_index;
#if defined(PQ_03_3_ColorTemp)
	SLR_COLOR_TEMP_MODE eColorTempMode;
	char	R_Lo[SLR_COLOR_TEMP_MAX];
	char	G_Lo[SLR_COLOR_TEMP_MAX];
	char	B_Lo[SLR_COLOR_TEMP_MAX];
	char	R_Hi[SLR_COLOR_TEMP_MAX];
	char	G_Hi[SLR_COLOR_TEMP_MAX];
	char	B_Hi[SLR_COLOR_TEMP_MAX];
#endif

} ColorTemp_Index;

typedef enum _VIP_TABLE_AREA_ENUM {
	VIP_AREA_asia = 0,
	VIP_AREA_phil,
	VIP_AREA_iran,
	VIP_AREA_MAX_NUM,
} VIP_TABLE_AREA_ENUM;

typedef struct _SLR_PICTURE_MODE_DATA {
	PICTURE_MODE  mode;
	unsigned char Brightness;
	unsigned char Contrast;
	unsigned char Saturation;
	unsigned char Hue;
	unsigned char Sharpness;
	unsigned char DNR;
	unsigned char DccMode;
	unsigned char DCRMode;
	unsigned char BackLight;
	unsigned char MEMC;
	unsigned char MPEG;
	unsigned char xvYcc_Mode;
	ColorTemp_Index ColorTempIndex;
	unsigned char FilmMode;
	unsigned char MonochromeMode;
	char ICM_CMS[6][3];
} SLR_PICTURE_MODE_DATA;


#else

typedef enum _PICTURE_MODE {

	PICTURE_MODE_USER = 0,
	PICTURE_MODE_VIVID,
	PICTURE_MODE_STD,
	PICTURE_MODE_GENTLE,
	PICTURE_MODE_MOVIE,
	PICTURE_MODE_SPORT,
	PICTURE_MODE_GAME,
	PICTURE_MODE_AUTO_VIEW,
	PICTURE_MODE_DYNAMIC,
	PICTURE_MODE_STANDARD,
	PICTURE_MODE_MILD,
	PICTURE_MODE_ECO,
	PICTURE_MODE_PC,
	PICTURE_MODE_CRICKET,/*yuan::20130624*/
	PICTURE_MODE_MAX,

} PICTURE_MODE;

typedef struct _SLR_PICTURE_MODE_DATA {

	PICTURE_MODE  mode;		/* peggy: add picture for identifying*/

	unsigned char Brightness;
	unsigned char Contrast;
	unsigned char Saturation;
	unsigned char Hue;
	unsigned char Sharpness;
	unsigned char DNR;
	unsigned char DccMode;
	unsigned char ColorTemp;
	unsigned char DCRMode; /*sync from AT*/
	unsigned char BackLight;
#if defined(TV014_1)
	unsigned char FilmMode;
	unsigned char ColorEnhancement;
#elif defined(BUILD_TV057_1_ATV)
	unsigned char channelColourSet;
	unsigned char MPEG;
#else
	unsigned char MEMC;
	unsigned char MPEG;
#endif
	unsigned char xvYcc_Mode;

#if  defined(BUILD_TV005_2)
	unsigned char Modification:4;   /*cloud: 1: user mode*/
	unsigned char Cinema:4;   /*cloud:*/
	ColorTemp_Gain_Diff	RGB_Diff;
	unsigned char unsharp_mask;
#else
	#if  (defined BUILD_TV010_1_ISDB)/*toddy_liu add 20120608*/
		unsigned char Modification:4;   /*cloud: 1: user mode*/
	#endif
		unsigned char Reversed1;
		unsigned char Reversed2;
		unsigned char Reversed3;
		unsigned char Reversed4;
#endif

	unsigned char Black_Level;
	unsigned char Reality_Creation;
	unsigned char Resolution;
	unsigned char Black_Corrector;
	unsigned char Black_Adjust;
	unsigned char LED_Motion_Mode;

} SLR_PICTURE_MODE_DATA;
#endif

#ifdef BUILD_TV010_1_ISDB_COLOR_TEMP
typedef struct _SLR_COLORTEMP_DATA {
	INT16	R_val;/*gain*/
	INT16	G_val;/*gain*/
	INT16	B_val;/*gain*/
	unsigned short	R_offset_val;
	unsigned short	G_offset_val;
	unsigned short	B_offset_val;
	unsigned char   gamma_curve_index;
} SLR_COLORTEMP_DATA;

#else

#if  defined(TV020_STYLE_PQ) || defined(BUILD_TV030_2)
typedef struct _SLR_COLORTEMP_DATA {
	short R_val;/*gain*/
	short G_val;/*gain*/
	short B_val;/*gain*/
	short R_offset_val;
	short G_offset_val;
	short B_offset_val;
	char  gamma_curve_index;
} SLR_COLORTEMP_DATA;

#else

typedef struct _SLR_COLORTEMP_DATA {
	unsigned short	R_val;/*gain*/
	unsigned short	G_val;/*gain*/
	unsigned short	B_val;/*gain*/
	unsigned short	R_offset_val;
	unsigned short	G_offset_val;
	unsigned short	B_offset_val;
	unsigned char   gamma_curve_index;
} SLR_COLORTEMP_DATA;

#endif
#endif
#pragma pack()   /* restore original alignment from stack */


#if  defined(IS_TV05_STYLE_PICTUREMODE)
typedef enum _SLR_COLORTEMP_LEVEL {
	SLR_COLORTEMP_WARM = 0,
	SLR_COLORTEMP_NORMAL,
	SLR_COLORTEMP_COOL,
	SLR_COLORTEMP_MAX_NUM,
} SLR_COLORTEMP_LEVEL;
#else
typedef enum _SLR_COLORTEMP_LEVEL {
	SLR_COLORTEMP_USER = 0,
	SLR_COLORTEMP_NORMAL,	/*std*/
	SLR_COLORTEMP_WARMER,	/*6500K*/
	SLR_COLORTEMP_WARM,		/*7300K*/
	SLR_COLORTEMP_COOL,		/*8200K*/
	SLR_COLORTEMP_COOLER,	/*9300K*/
	SLR_COLORTEMP_MAX_NUM,
} SLR_COLORTEMP_LEVEL;
#endif

typedef enum _GAMMA_LEVEL {
	GAMMA_CURVE_0 = 0,
	GAMMA_CURVE_1,
	GAMMA_CURVE_2,
	GAMMA_CURVE_3,
	GAMMA_CURVE_4,
	GAMMA_CURVE_5,
	GAMMA_CURVE_6,
	GAMMA_CURVE_7,
	GAMMA_CURVE_8,
	GAMMA_CURVE_9,
	GAMMA_CURVE_identity,
	GAMMA_CURVE_RELATE_TO_GAMMA_MODE,
	GAMMA_CURVE_MAX_NUM,
} GAMMA_LEVEL;


typedef enum _SLR_DCC_MODE{
	SLR_DCC_OFF	= 0,
	SLR_DCC_LOW,
	SLR_DCC_MID,
	SLR_DCC_HIGH,
	SLR_DCC_Default,
	SLR_DCC_MODE_MAX,
} SLR_DCC_MODE;


typedef enum _SLR_DNR_MODE{
	SLR_DNR_OFF	= 0,
	SLR_DNR_LOW,
	SLR_DNR_MEDIEN,
	SLR_DNR_HIGH,
} SLR_DNR_MODE;

typedef enum _SLR_xvYcc_MODE{
	SLR_xvYcc_OFF	= 0,
	SLR_xvYcc_ON,
	SLR_xvYcc_Auto,
	SLR_xvYcc_Err,
}SLR_xvYcc_MODE;

/*-----------------------------------------------------------------------------*/
/* from scalerColor.h*/
/*-----------------------------------------------------------------------------*/


typedef enum _COLOR_TABLE_TYPE {

	COLOR_TABLE_DATA,
	COLOR_TABLE_FACMODE,
	COLOR_TABLE_VIP_COEF,
	COLOR_TABLE_VIP_EXTEND_COEF,
	COLOR_TABLE_VIP_EXTEND2_COEF,
	COLOR_TABLE_COLORTEMP_SET,

} COLOR_TABLE_TYPE;

/* 20100330 peggy: add vip table sourec, according to definition in source.h but add default source*/
typedef enum _VIP_TABLE_SRC_ENUM {

	VIP_SRC_DEFAULT 	= 0,
	VIP_SRC_ATV,
	VIP_SRC_VO,
	VIP_SRC_AV,
	VIP_SRC_SV,
	VIP_SRC_COMPONENT,
	VIP_SRC_SCART,
	VIP_SRC_SCART_RGB,
	VIP_SRC_HDMI,
	VIP_SRC_HDMI1,
	VIP_SRC_HDMI2,
	VIP_SRC_HDMI3,
	VIP_SRC_DVI,
	VIP_SRC_VGA,
	VIP_SRC_YPBPR,
	VIP_SRC_PVR,
	VIP_SRC_VIDEO8,
	VIP_SRC_USB,
	VIP_SRC_WIFI,
	VIP_SRC_DISPLAYPORT,
	VIP_SRC_VO_USB,
	VIP_SRC_VO_JPEG, /* added this for JPEG 20120629 Jerry Wu*/
	VIP_SRC_3D,		/*--- Add 3D Source for TCL  lhh_20130521*/
} VIP_TABLE_SRC_ENUM;


/* oliver-, move to scalerCommon.h*/
#define RTNR_Y_C_MAX 11 /*20100817 added by Leo Chen*/




#pragma pack(4)     /* set alignment to 4 byte boundary */

typedef struct _VIP_TABLE_DATA_STRUCT {
	VIP_TABLE_SRC_ENUM		source;
	VIP_TABLE_TIMIMG_ENUM	timing;
	VIP_TABLE_COLORSTD_ENUM	color;
	void *tableData;
} VIP_TABLE_DATA_STRUCT;

typedef struct _VIP_TABLE_DATA_STRUCT_EX {
	VIP_TABLE_SRC_ENUM		source;
	VIP_TABLE_TIMIMG_ENUM	timing;
	VIP_TABLE_COLORSTD_ENUM	color;
	void *tableData;
	unsigned int			tableDataLen;
} VIP_TABLE_DATA_STRUCT_EX;

#pragma pack()   /* restore original alignment from stack */

typedef struct{
	unsigned char VIP_USER_QUALITY_Coef[VIP_QUALITY_SOURCE_NUM][VIP_QUALITY_FUNCTION_TOTAL_CHECK];
	unsigned char VIP_VIVID_QUALITY_Coef[VIP_QUALITY_SOURCE_NUM][VIP_QUALITY_FUNCTION_TOTAL_CHECK];
	unsigned char VIP_STANDARD_QUALITY_Coef[VIP_QUALITY_SOURCE_NUM][VIP_QUALITY_FUNCTION_TOTAL_CHECK];
	unsigned char VIP_GENTLE_QUALITY_Coef[VIP_QUALITY_SOURCE_NUM][VIP_QUALITY_FUNCTION_TOTAL_CHECK];
} SLR_PICTURE_MODE_VIP_TABLE;

#ifdef __cplusplus
}
#endif


#endif
