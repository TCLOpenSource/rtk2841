/***************************************************************************
	scalerRPCCommon.h  -  description
	-------------------
    begin                :  July 18 2017
    copyright           : (C) 2017 by csFanChiang
    email                : csFanChiang@realtek.com
 ***************************************************************************/

#ifndef _RPCCOMMON_VIP_H__
#define _RPCCOMMON_VIP_H__

#include <scalercommon/vipCommon.h>

/*===================================*/
/*======== PQ by Pass for Power Saving =========*/
/*===================================*/
#define VIP_PQ_ByPass_TBL_Max 10
typedef enum _VIP_PQ_ByPass_ITEMS {
	/*===============I Domain===========*/
	/*Main*/
	PQ_ByPass_Iedge_Smooth = 0,		/*0*/
	PQ_ByPass_MPEG_NR,
	PQ_ByPass_HSD_DITHER,
	PQ_ByPass_HSD_DITHER_Temporal,
	PQ_ByPass_RTNR_Y,
	PQ_ByPass_RTNR_C,				/*5*/
	PQ_ByPass_MCNR,
	PQ_ByPass_I_DCTI,
	PQ_ByPass_ImpulseNR,
	PQ_ByPass_SNR_C,
	PQ_ByPass_SNR_Y,				/*10*/
	PQ_ByPass_MosquiutoNR,
	PQ_ByPass_I_Peaking,
	PQ_ByPass_MB_Peaking,

	/*Sub*/
	PQ_ByPass_HSD_DITHER_Sub,
	PQ_ByPass_HSD_DITHER_Temporal_Sub,		/*15*/
	PQ_ByPass_I_Peaking_Sub,

	/*===============D Domain===========*/
	/*Main*/
	PQ_ByPass_USM,
	PQ_ByPass_SU_Peaking,
	PQ_ByPass_SHP_DLTI,
	PQ_ByPass_DCC,			/*20*/
	PQ_ByPass_DCTI,
	PQ_ByPass_ICM,
	PQ_ByPass_SHP,
	PQ_ByPass_Dedge_Smooth,
	PQ_ByPass_CDS,			/*25*/
	PQ_ByPass_UV_Offset,
	PQ_ByPass_V_CTI,
	PQ_ByPass_sRGB,
	PQ_ByPass_Gamma,
	PQ_ByPass_InvGamma,	/*30*/
	PQ_ByPass_ColorTemp,
	PQ_ByPass_DITHER,
	PQ_ByPass_DITHER_Temporal,

	/*Sub*/
	PQ_ByPass_DCTI_Sub,
	PQ_ByPass_ICM_Sub,		/*35*/
	PQ_ByPass_SHP_Sub,
	PQ_ByPass_sRGB_Sub,
	PQ_ByPass_Gamma_Gamma,
	PQ_ByPass_InvGamma_Sub,

	/* new */
	PQ_ByPass_I_DI_IP_Enable,	/*40*/
	PQ_ByPass_I_DI,	/* force 2D*/

	VIP_PQ_ByPass_ITEMS_Max,

} VIP_PQ_ByPass_ITEMS;

typedef struct _VIP_PQ_ByPass_Struct{
	unsigned char VIP_PQ_ByPass_TBL[VIP_PQ_ByPass_ITEMS_Max];
} VIP_PQ_ByPass_Struct;

typedef struct _VIP_PQ_ByPass_Ctrl{
	unsigned char table_idx;
	VIP_PQ_ByPass_Struct PQ_ByPass_Struct[VIP_PQ_ByPass_TBL_Max];
} VIP_PQ_ByPass_Ctrl;
/*===================================*/
/*======== PQ by Pass for Power Saving =========*/
/*===================================*/

typedef struct {
	int Apply_Curve[DCC_Curve_Node_MAX];
} RPC_Adapt_DCC_Info_Item;

typedef struct {
	unsigned char hist_init_flag;
	unsigned char TimingChange_flag_for_RTNR;
	unsigned char MPEG_BLK_init;
	unsigned char m_film;
	unsigned char g_fw_film_en;
	unsigned char m_film_clear;
	unsigned char smooth_toggle_update_flag;
} _VIP_NetFlix_smooth_Toggle_info;


typedef struct {
	unsigned int Netflix_CapWid;
	unsigned int Netflix_CapLen;
	unsigned int Netflix_Enable;
	_VIP_NetFlix_smooth_Toggle_info	NetFlix_smooth_Toggle_info;
} VIP_NetFlix_info;

typedef struct {
	unsigned char VCPU_DTV_SD_p2i;
	int decode_bit_rate;
	int inputplugin_bit_rate;
	int YouTube_TargetWid;
	int YouTube_TargetLen;
	int YouTube_BitRate;
}VIP_VCPU_setting_info;

typedef struct {
	unsigned char is_me_dead;
	int vo_channel_speed;
	unsigned char m_VOSeek;
	unsigned char m_MiraCast;
	unsigned char bZoomAction;
	unsigned char bShiftAction;
	unsigned char DC_offon_flg;
}VIP_MEMC_VCPU_setting_info;


/************************************************************/
/*********** RPC_SmartPIC_Clue START ****  SmartPIC_Clue START *****/
/************************************************************/
typedef struct _RPC_CLUES {
	RPC_Adapt_DCC_Info_Item RPC_Adapt_DCC_Info;
	VIP_NetFlix_info S_NetFlix_info;
	VIP_VCPU_setting_info VCPU_setting_info;
	VIP_MEMC_VCPU_setting_info MEMC_VCPU_setting_info;

	unsigned int SceneChange;
	unsigned int D_SceneChange;
	unsigned char prePowerSaveStatus;
} _RPC_clues;
/************************************************************/
/*********** RPC_SmartPIC_Clue END *******  SmartPIC_Clue END ******/
/************************************************************/


typedef struct {
	unsigned char DCC_Curve_apply_flag;
	unsigned char VGIP_ISR_IN_VCPU_flag;
	unsigned char AutoMA_Running_flag;
	unsigned char HDMI_color_space;
} DRV_RPC_SCPU_ISR_INFO_TO_VCPU;

typedef struct {
	unsigned char memc_cadence;
	unsigned char memc_avdelay;
} DRV_RPC_MEMC_ISR_INFO_TO_VCPU;

typedef struct _DRV_ScalingDown_COEF_TAB {
	signed short FIR_Coef_Table[SDFIR64_MAXNUM][SD_FIR_Coef_MAXNUM];

} DRV_ScalingDown_COEF_TAB;


typedef struct _VIP_ScalingDown_Setting_INFO {
	DRV_ScalingDown_COEF_TAB ScalingDown_COEF_TAB;
	unsigned char SD_H_Coeff_Sel[VIP_ScalingDown_FIR_Level_Max];
	unsigned char SD_V_Coeff_Sel[VIP_ScalingDown_FIR_Level_Max];
	unsigned char SDFH444To422Sel;
	unsigned char SDFHSel;
	unsigned char SDFVSel;
	unsigned char IsHScalerDown;
	unsigned char IsVScalerDown;
	unsigned char IsH444To422;

	unsigned char isCutHor4Line;
	unsigned char isCutVer2Line;

} VIP_ScalingDown_Setting_INFO;

/*===================================*/
/*======== I de_XC  ====================*/
/*===================================*/
#define I_De_XC_TBL_Max 10

typedef struct _VIP_I_De_XC_TBL {
	unsigned char dexc_en;
	unsigned char Dexc_spatial_correction_en;
	unsigned char dexc_y_error_th1;
	unsigned char dexc_y_error_th2;
	unsigned char dexc_y_amp_th;
	unsigned char dexc_c_error_th1;
	unsigned char dexc_c_error_th2;
	unsigned char dexc_c_amp_th;
	unsigned char dexc_step_lv1;
	unsigned char dexc_step_lv2;
	unsigned char dexc_step_still;
	unsigned char dexc_step_notxc;
	unsigned char dexc_hold_th;
	unsigned char dexc_blending_table_0;
	unsigned char dexc_blending_table_1;
	unsigned char dexc_blending_table_2;
	unsigned char dexc_blending_table_3;
	unsigned char dexc_blending_table_4;
	unsigned char dexc_blending_table_5;
	unsigned char dexc_blending_table_6;
	unsigned char dexc_blending_table_7;

} VIP_I_De_XC_TBL;

typedef struct _VIP_I_De_XC_CTRL {
	unsigned char table_select;
	VIP_I_De_XC_TBL De_XC_TBL[I_De_XC_TBL_Max];

} VIP_I_De_XC_CTRL;
/*===================================*/
/*======== I de_XC   ====================*/
/*===================================*/

typedef struct _VIP_ScalingUp_Ctrl{
	unsigned char Two_Step_Mode;
	unsigned char UZU_Vertical_Mode;
	unsigned char UZU_Dir_Phase_En;

} VIP_ScalingUp_Ctrl;

/************************************************************************************************************/
/********************* HDR START ************ HDR START ***** HDR START *************************************/
/************************************************************************************************************/
typedef enum _VIP_HDR_DM_MATRIX_ITEMS {
	matrix_COEF_m11 = 0,
	matrix_COEF_m12,
	matrix_COEF_m13,
	matrix_COEF_m21,
	matrix_COEF_m22,
	matrix_COEF_m23,
	matrix_COEF_m31,
	matrix_COEF_m32,
	matrix_COEF_m33,
	matrix3x3_COEF__Items_Max,
	matrix_COEF_R_Offset = matrix3x3_COEF__Items_Max,
	matrix_COEF_G_Offset,
	matrix_COEF_B_Offset,

	matrix_COEF_Items_Max,

} VIP_HDR_DM_MATRIX_ITEMS;

typedef enum _VIP_HDR_DM_EOTF_OETF_ITEMS {
	oetf_eotf_reverse_0 = 0,
	oetf_eotf_reverse_1,
	oetf_eotf_reverse_2,
	oetf_eotf_reverse_3,
	oetf_eotf_reverse_4,
	oetf_eotf_reverse_5,
	oetf_eotf_reverse_6,
	oetf_eotf_reverse_7,
	oetf_eotf_reverse_8,
	oetf_eotf_reverse_9,
	oetf_eotf_Items_Max,

} VIP_HDR_DM_EOTF_OETF_ITEMS;

typedef enum _VIP_HDR_DM_CTRL_ITEMS {
	TV006_HDR_En,
	TV006_HDR_DEMO_EN,
	TV006_HDR_HDR10_set,
	TV006_HDR_HDR10_display_check,
	TV006_HDR_HDR10_apply_check,
	TV006_HDR_HDR10_enable_Coef,
	CTRL_reverse_6,
	CTRL_reverse_7,
	CTRL_reverse_8,
	CTRL_reverse_9,
	CTRL_reverse_10,
	CTRL_reverse_11,
	CTRL_reverse_12,
	CTRL_reverse_13,
	CTRL_reverse_14,

	CTRL_Items_Max,

} VIP_HDR_DM_CTRL_ITEMS;

typedef struct _VIP_HDR_PQModeInfo {
	unsigned int version;//Version = 0 wild card(default data
	unsigned int length;//pData Length
	unsigned char  wId;//0 : main
	unsigned int* pData;

} VIP_HDR_PQModeInfo;	/* same as HAL_VPQ_DATA_T*/

typedef struct _TC_HDR_metadata_variables {
	int tmInputSignalBlackLevelOffset;
	int tmInputSignalWhiteLevelOffset;
	int shadowGain;
	int highlightGain;
	int midToneWidthAdjFactor;
	int tmOutputFineTuningNumVal;
	int tmOutputFineTuningX[10];
	int tmOutputFineTuningY[10];
	int saturationGainNumVal;
	int saturationGainX[6];
	int saturationGainY[6];
} TC_HDR_metadata_variables;

typedef struct _TC_HDR_metadata_tables {
	int luminanceMappingNumVal;
	int luminanceMappingX[33];
	int luminanceMappingY[33];
	int colourCorrectionNumVal;
	int colourCorrectionX[33];
	int colourCorrectionY[33];
	int chromaToLumaInjectionMuA;
	int chromaToLumaInjectionMuB;
} TC_HDR_metadata_tables;

typedef struct _TC_HDR_metadata {
	int specVersion;
	int payloadMode;
	int hdrPicColourSpace;
	int hdrMasterDisplayColourSpace;
	int hdrMasterDisplayMaxLuminance;
	int hdrMasterDisplayMinLuminance;
	int sdrPicColourSpace;
	int sdrMasterDisplayColourSpace;
	TC_HDR_metadata_variables variables;
	TC_HDR_metadata_tables tables;
} TC_HDR_metadata;

typedef struct _VIP_HDR_INFO {
	unsigned char HDR_Setting_Status;
	unsigned char Ctrl_Item[CTRL_Items_Max];
	unsigned int CSC1_YUV2RGB_Coef[matrix_COEF_Items_Max];
	unsigned int Matrix_3x3[matrix_COEF_Items_Max];
	unsigned int EOTF_OETF[oetf_eotf_Items_Max];
	VIP_HDR_PQModeInfo HDR_PQModeInfo;
	TC_HDR_metadata tc_hdr_metadata;
} VIP_HDR_INFO;

/************************************************************************************************************/
/************************ HDR End ******* HDR End ***** HDR End ***********************************************/
/************************************************************************************************************/

/*===================================*/
/*============= De-XC ===================*/
/*===================================*/

typedef enum _VIP_I_De_XC_MEM_BORROW_MODE{
	De_XC_MEM_UNKNOW = 0,
	De_XC_MEM_From_VBM_Directly,
	De_XC_MEM_From_I3D_DMA,	/* memory will release by itself in i3ddma*/
	I_De_XC_MEM_BORROW_MODE_Max,

} VIP_I_De_XC_MEM_BORROW_MODE;

typedef struct _VIP_I_De_XC_MEM {
	unsigned long phyaddr;
	/*unsigned int size;*/
	unsigned int getsize;
	unsigned char Borrow_Mode;
	unsigned char DMA_Status[5];
} VIP_I_De_XC_MEM;

/*===================================*/
/*============= De-XC ===================*/
/*===================================*/

typedef enum _VIP_PQ_SOURCE_TYPE_From_AP_Item {
	PQ_SRC_From_AP_UNKNOW = 0,
	PQ_SRC_From_AP_AVD,
	PQ_SRC_From_AP_ADC,
	PQ_SRC_From_AP_HDMI,
	PQ_SRC_From_AP_JPEG,
	PQ_SRC_From_AP_DTV,
	PQ_SRC_From_AP_USB,
	PQ_SRC_From_AP_OTT,

	PQ_SRC_From_AP_ITEM_MAX,
} VIP_PQ_SOURCE_TYPE_From_AP_Item;

/*============= LC ===================*/
/*===================================*/
typedef struct _VIP_DRV_Local_Contrast_Region_Num_Size {
        unsigned char nBlk_Hnum;
        unsigned char nBlk_Vnum;
        unsigned short  nBlk_Hsize;
        unsigned short  nBlk_Vsize;
	  unsigned int lc_hfactor;
	  unsigned int lc_vfactor;
} VIP_DRV_Local_Contrast_Region_Num_Size;

typedef struct _VIP_Local_Contrast_Ctrl{
	unsigned char LC_Table_Idx;
	unsigned char BL_Profile_Interpolation_lc_tab_hsize;
	unsigned char BL_Profile_Interpolation_lc_tab_vsize;
        unsigned char nBlk_Hnum;
        unsigned char nBlk_Vnum;

} VIP_Local_Contrast_Ctrl;
/*===================================*/
/*============= LC ===================*/
/*===================================*/

/************************************************************/
/***** _RPC_system_setting_info START ** system_setting_info START ******/
/************************************************************/
typedef struct {
	DRV_RPC_SCPU_ISR_INFO_TO_VCPU SCPU_ISRIINFO_TO_VCPU;
	DRV_RPC_MEMC_ISR_INFO_TO_VCPU MEMC_ISRIINFO_TO_VCPU;
	VIP_PQ_ByPass_Ctrl PQ_ByPass_Ctrl;
	VIP_ScalingDown_Setting_INFO ScalingDown_Setting_INFO;
	VIP_I_De_XC_CTRL I_De_XC_CTRL;
	VIP_I_De_XC_MEM DE_XCXL_Memory_CTRL[2];
	VIP_ScalingUp_Ctrl ScalingUp_Ctrl;
	VIP_HDR_INFO	HDR_info;
	VIP_Local_Contrast_Ctrl Local_Contrast_Ctrl;
	unsigned char Project_ID;
	unsigned char PQ_demo_flag;
	unsigned char DCC_hist_shift_bit;
	unsigned char VIP_source;
	unsigned char PQ_source_type_from_AP;
} _RPC_system_setting_info;
/************************************************************/
/****** _RPC_system_setting_info END ****  system_setting_info END *******/
/************************************************************/


/************************************************************/
/*****RPC_SLR_VIP_TABLE  START ** system_setting_info START ******/
/************************************************************/

typedef struct {
	unsigned char chromaerror_en;
	unsigned char chromaerror_all;
	unsigned char chromaerror_th;
	unsigned char chromaerror_framemotionc_th;
	unsigned char di444to422Lowpass;
} RPC_VIP_MA_ChromaError;

typedef struct {
	unsigned char VIP_QUALITY_Coef[VIP_QUALITY_SOURCE_NUM][VIP_QUALITY_Coef_MAX];
	RPC_VIP_MA_ChromaError MA_Chroma_Error_Table[t_MA_Chroma_Error_MAX];

} RPC_SLR_VIP_TABLE;


/************************************************************/
/***** RPC_SLR_VIP_TABLE START ** system_setting_info START ******/
/************************************************************/


#endif


