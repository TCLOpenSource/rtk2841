/*==========================================================================
  * Copyright (c)      Realtek Semiconductor Corporation, 2006
  * All rights reserved.
  * ========================================================================*/

/*================= File Description =======================================*/
/**
 * @file
 * 	This file is for color related functions.
 *
 * @author 	$Author$
 * @date 	$Date$
 * @version $Revision$
 */

/**
 * @addtogroup color
 * @{
 */

#ifndef _VIP_COLOR_H
#define _VIP_COLOR_H

/*================================ Definitions ==============================*/

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Header include
 ******************************************************************************/
#if CONFIG_FIRMWARE_IN_KERNEL
#include <scalercommon/vipCommon.h>
#include <scalercommon/scalerCommon.h>
#else
#include <rtd_types.h>
#include <scaler/vipCommon.h>
#include <scaler/scalerCommon.h>
#endif
/*******************************************************************************
 * Marco
 ******************************************************************************/


/*******************************************************************************
 * Variable
 ******************************************************************************/


/*******************************************************************************
* Constant
******************************************************************************/

#define _RGB2YUV_m11					0x00
#define _RGB2YUV_m12					0x01
#define _RGB2YUV_m13					0x02
#define _RGB2YUV_m21					0x03
#define _RGB2YUV_m22					0x04
#define _RGB2YUV_m23					0x05
#define _RGB2YUV_m31					0x06
#define _RGB2YUV_m32					0x07
#define _RGB2YUV_m33					0x08
#define _RGB2YUV_Yo_even				0x09
#define _RGB2YUV_Yo_odd					0x0a
#define _RGB2YUV_Y_gain					0x0b
#define _RGB2YUV_sel_RGB				0x0c
#define _RGB2YUV_set_Yin_offset			0x0d
#define _RGB2YUV_set_UV_out_offset		0x0e
#define _RGB2YUV_sel_UV_off				0x0f
#define _RGB2YUV_Matrix_bypass			0x10
#define _RGB2YUV_Enable_Y_gain			0x11


#define _YUV2RGB_k11					0x00
#define _YUV2RGB_k12					0x01
#define _YUV2RGB_k13					0x02
#define _YUV2RGB_k22					0x03
#define _YUV2RGB_k23		 			0x04
#define _YUV2RGB_k32					0x05
#define _YUV2RGB_k33					0x06
#define _YUV2RGB_Roffset	 			0x07
#define _YUV2RGB_Goffset				0x08
#define _YUV2RGB_Boffset				0x09
#define _YUV2RGB_Y_Clamp				0x0a
#define _YUV2RGB_UV_Clamp				0x0b


#define _Gamma_Full						0x01
#define _Gamma_Compact					0x00

#define _ICM_ALL_DATA_HUE 				0
#define _ICM_ALL_DATA_SAT 				2
#define _ICM_ALL_DATA_ITN 				4
#define _ICM_ALL_DATA_SOFTCLAMP_CTRL 	6
#define _ICM_ALL_DATA_SOFTCLAMP_SLOPE 	7
#define _SOFTCLAMP_SAT_SLOP_EN			2
#define _SOFTCLAMP_ITN_SLOP_EN			1

#define _SRGB_TABLE_BYPASS				0
#define _SRGB_TABLE_COEFF1				1
#define _SRGB_TABLE_COEFF2				2
#define _SRGB_TABLE_RESERVED			3

#define _SRGB_MAIN_TABLE_SEL			_SRGB_TABLE_COEFF1
#define _SRGB_SUB_TABLE_SEL				_SRGB_TABLE_COEFF1

/*hsinyi 20090617*/
/* Definitions of Digital Filter===============*/
#define _DISABLE_PORT                   0
#define _PHASE_ACCESS_PORT              1
#define _NEG_SMEAR_ACCESS_PORT     		2
#define _POS_SMEAR_ACCESS_PORT			3
#define _NEG_RING_ACCESS_PORT        	4
#define _POS_RING_ACCESS_PORT			5
#define _MISMATCH_ACCESS_PORT			6
#define _YPBPR_ACCESS_PORT              7
#define _NOISE_REDUCTION_PORT        	8

#define _YPBPR_DISABLE                  0
#define _YPBPR_ENABLE                   7

#define _PHASE_THD_0                    0
#define _PHASE_THD_1                    1
#define _PHASE_THD_2                    2
#define _PHASE_THD_3                    3
#define _PHASE_THD_4                    4
#define _PHASE_THD_5                    5
#define _PHASE_THD_6                    6
#define _PHASE_THD_7                    7

#define _SMEAR_RING_THD_0               0
#define _SMEAR_RING_THD_1               1
#define _SMEAR_RING_THD_2               2
#define _SMEAR_RING_THD_3               3
#define _SMEAR_RING_THD_4               4
#define _SMEAR_RING_THD_5               5
#define _SMEAR_RING_THD_6               6
#define _SMEAR_RING_THD_7               7

#define _MISMATCH_THD_0                 0
#define _MISMATCH_THD_1                 1

#define _NOISE_REDUCTION_THD_0          0
#define _NOISE_REDUCTION_THD_1          1
#define _NOISE_REDUCTION_THD_2          2
#define _NOISE_REDUCTION_THD_3          3
#define _NOISE_REDUCTION_THD_4          4
#define _NOISE_REDUCTION_THD_5          5
#define _NOISE_REDUCTION_THD_6          6
#define _NOISE_REDUCTION_THD_7          7

#define _DIV_VALUE_0                    0
#define _DIV_VALUE_1                    1
#define _DIV_VALUE_2                    2
#define _DIV_VALUE_3                    3

#define VIP_DITHERLUT_ROW_MAX			3
#define VIP_DITHERLUT_COL_MAX			16
#define VIP_DITHERLUT_DEP_MAX			4

#define VIP_HDMI_DITHERLUT_COL_MAX		4
#define VIP_HDMI_DITHERLUT_DEP_MAX		4

#define _YUV2RGB_UVOFFSET_BY_Y_UOFFSET	0x00
#define _YUV2RGB_UVOFFSET_BY_Y_VOFFSET	0x01
#define _YUV2RGB_UVOFFSET_BY_Y_USTEP	0x02
#define _YUV2RGB_UVOFFSET_BY_Y_VSTEP	0x03

#define _YUV2RGB_COEF_BY_Y_M0			0x00
#define _YUV2RGB_COEF_BY_Y_M1			0x01
#define _YUV2RGB_COEF_BY_Y_M2			0x02
#define _YUV2RGB_COEF_BY_Y_M3			0x03
#define _YUV2RGB_COEF_BY_Y_M4			0x04
#define _YUV2RGB_COEF_BY_Y_M5			0x05
#define _YUV2RGB_COEF_BY_Y_M6			0x06
#define _YUV2RGB_COEF_BY_Y_M7			0x07
#define _YUV2RGB_COEF_BY_Y_M8			0x08
#define _YUV2RGB_COEF_BY_Y_M9			0x09
#define _YUV2RGB_COEF_BY_Y_M10			0x0a
#define _YUV2RGB_COEF_BY_Y_M11			0x0b
#define _YUV2RGB_COEF_BY_Y_M12			0x0c
#define _YUV2RGB_COEF_BY_Y_M13			0x0d
#define _YUV2RGB_COEF_BY_Y_M14			0x0e
#define _YUV2RGB_COEF_BY_Y_M15			0x0f
#define _YUV2RGB_COEF_BY_Y_M16			0x10

#define _YUV2RGB_COEF_BY_Y_k11			0x00
#define _YUV2RGB_COEF_BY_Y_k12			0x01
#define _YUV2RGB_COEF_BY_Y_k13			0x02
#define _YUV2RGB_COEF_BY_Y_k22			0x03
#define _YUV2RGB_COEF_BY_Y_k23			0x04
#define _YUV2RGB_COEF_BY_Y_k32			0x05
#define _YUV2RGB_COEF_BY_Y_k33			0x06

#define VIP_DYNAMIC_DITHERING_TABLE_MAX	2

#define Bin_Num_sRGB 					128	/* Mac2=32, Sirius=128 (jyyang_2013/12/28)*/

#define IRE_PATTERN_USE_3D_PTG	1


typedef enum _VIP_HDR_DM_CSC1_YUV2RGB_TABLE {
	HDR_DM_CSC1_YUV2RGB_BT709_Limted_235_240_to_255 = 0,
	HDR_DM_CSC1_YUV2RGB_BT709_255_to_255,
	HDR_DM_CSC1_YUV2RGB_BT2020_Limted_235_to_255,
	HDR_DM_CSC1_YUV2RGB_BT2020_255_to_255,
	HDR_DM_CSC1_YUV2RGB_ByPass_255_to_255,
	HDR_DM_CSC1_YUV2RGB_ByPass_Limted_235_to_255,

	VIP_HDR_DM_CSC1_YUV2RGB_TABLE_Max,

} VIP_HDR_DM_CSC1_YUV2RGB_TABLE;

#define HDR_TABLE_NUM 5
/*#define HDR_RGB2YUV_TABLE_NUM 5*/
typedef enum {
	HDR_RGB2OPT_709_TO_2020 = 0,
	HDR_RGB2OPT_2020_TO_709,
	HDR_RGB2OPT_DCI_TO_709,
	HDR_RGB2OPT_DCI_TO_2020,
	HDR_RGB2OPT_2020_TO_DCI,
	HDR_RGB2OPT_RGB_TO_Y,
	HDR_RGB2OPT_TABLE_NUM
};

/* DM2 */
#define EOTF_size 1025
#define OETF_size 1025
#define ToneMapping_size 129
#define HDR_Histogram_size 128
#define HDR_24x24x24_size (24*24*24)

typedef struct _VIP_HDR10_OETF_ByLuminace_TBL {
	unsigned short panel_Luminace;

	unsigned short  OETF_100N[OETF_size];
	unsigned short  OETF_150N[OETF_size];
	unsigned short  OETF_200N[OETF_size];
	unsigned short  OETF_250B[OETF_size];
	unsigned short  OETF_300B[OETF_size];
	unsigned short  OETF_350B[OETF_size];
	unsigned short  OETF_400B[OETF_size];
	unsigned short  OETF_400N6[OETF_size];
	unsigned short  OETF_500N6[OETF_size];
	unsigned short  OETF_600N6[OETF_size];
	unsigned short  OETF_660N6[OETF_size];
	unsigned short  OETF_700N6[OETF_size];
	unsigned short  OETF_800N6[OETF_size];
	unsigned short  OETF_1000N6[OETF_size];
	unsigned short  OETF_1000Over[OETF_size];

} VIP_HDR10_OETF_ByLuminace_TBL;

/*******************************************************************************
 * Structure
 ******************************************************************************/
typedef struct {
	unsigned char Data_sel;
	unsigned char maxlen;
	unsigned char psmth;
	unsigned char lpmode;
	unsigned char EngDiv;
	unsigned char offDiv;
	unsigned char uvGain;
	unsigned char Dcti_mode;
	unsigned char cur_sel;
	unsigned char Dcti_en;
} DRV_VipSHDIDcti_t;

typedef struct {
	unsigned char u_delay;
	unsigned char v_delay;

} DRV_VipUV_Delay;


typedef struct {
	unsigned char yc_delay;
	unsigned char cb_delay;
	unsigned char cr_delay;
	unsigned char new_crldelay_en;
	unsigned char new_cbldelay_en;
	unsigned char new_yldelay_en;
	unsigned char crldelay_en;
	unsigned char cbldelay_en;
	unsigned char yldelay_en;
	unsigned char crl_delay;
	unsigned char cbl_delay;
	unsigned char yl_delay;

} DRV_VipUV_Delay_TOP;

typedef struct {
	DRV_VipUV_Delay_TOP VipUV_Delay_TOP;
} DRV_VipUV_Delay_TOP_Table;


typedef struct {
	unsigned int BSum;
	unsigned int GSum;
	unsigned int RSum;
	unsigned char BMax;
	unsigned char BMin;
	unsigned char GMax;
	unsigned char GMin;
	unsigned char RMax;
	unsigned char RMin;
} RGB_pixel_info;

typedef struct  {
	unsigned char HDR10_EN;
	unsigned char HDR10_420_2_422;
	unsigned char HDR10_422_2_444;
	unsigned char HDR10_YUV2RGB;
	unsigned char HDR10_EOTF;
	unsigned char HDR10_CMT;
	unsigned char HDR10_OETF;
	unsigned char HDR10_RGB2OPT;
	unsigned char HDR10_DITHER;
} DRV_HDR10_submodule_CTL;

typedef struct  {
	unsigned int dolby_mode;
	unsigned int hdmi_in_mux;
	unsigned int dolby_hsize;
	unsigned int dolby_vsize;
	unsigned int dolby_h_total;
	unsigned int dolby_h_den_sta;
	unsigned int dolby_v_den_sta;
} DRV_HDR10_top_init_CTL;

typedef struct  {

	unsigned char wpr_on;
	unsigned char opc_on;
	unsigned char wse_on;
	unsigned char type_sel;
	unsigned char mode_3d;
	unsigned char test_mode;
	unsigned char mode_sel;


} DRV_Mplus_ModeChange;

typedef struct  {

	unsigned short h_sta;
	unsigned short h_end;
	unsigned short v_sta;
	unsigned short v_end;

}Drvif_SCALER_DISPLAY_DATA;

typedef enum _VIP_RGBW_MODE {
	VIP_RGBW_MODE_DISABLE = 0,
	VIP_RGBW_MODE_LGDMPLUS,
	VIP_RGBW_MODE_RTKRGBW,
	VIP_RGBW_MODE_HIMAXBOE,
	VIP_RGBW_MODE_MAX,
} VIP_RGBW_MODE;

typedef struct _yuvdata
{
	unsigned short y;
	unsigned short u;
	unsigned short v;
} yuvdata;


typedef enum _VIP_8VERTEX_RGB {
	VIP_8VERTEX_R = 0,
	VIP_8VERTEX_G,
	VIP_8VERTEX_B,
	
	VIP_8VERTEX_RGB_MAX
} VIP_8VERTEX_RGB;

typedef enum _VIP_8VERTEX {
	VIP_8VERTEX_WHITE = 0,
	VIP_8VERTEX_BLACK,
	VIP_8VERTEX_RED,
	VIP_8VERTEX_GREEN,
	VIP_8VERTEX_BLUE,
	VIP_8VERTEX_YELLOW,
	VIP_8VERTEX_CYAN,
	VIP_8VERTEX_MAGENTA,

	VIP_8VERTEX_MAX
} VIP_8VERTEX;


/*******************************************************************************
* enumeration
******************************************************************************/

typedef enum _VIP_GAMMA_TYPE {
	VIP_GAMMA_MODE1_R = 0,
	VIP_GAMMA_MODE1_G,
	VIP_GAMMA_MODE1_B,
	VIP_GAMMA_MODE2_R,
	VIP_GAMMA_MODE2_G,
	VIP_GAMMA_MODE2_B,
	VIP_GAMMA_MODE3_R,
	VIP_GAMMA_MODE3_G,
	VIP_GAMMA_MODE3_B,
	VIP_GAMMA_MODE4_R,
	VIP_GAMMA_MODE4_G,
	VIP_GAMMA_MODE4_B,
	VIP_GAMMA_MODE5_R,
	VIP_GAMMA_MODE5_G,
	VIP_GAMMA_MODE5_B,
	VIP_GAMMA_MODE6_R,
	VIP_GAMMA_MODE6_G,
	VIP_GAMMA_MODE6_B,
	VIP_GAMMA_MODE7_R,
	VIP_GAMMA_MODE7_G,
	VIP_GAMMA_MODE7_B,
	VIP_GAMMA_MODE8_R,
	VIP_GAMMA_MODE8_G,
	VIP_GAMMA_MODE8_B,
	VIP_GAMMA_MODE9_R,
	VIP_GAMMA_MODE9_G,
	VIP_GAMMA_MODE9_B,
	VIP_GAMMA_MODE10_R,
	VIP_GAMMA_MODE10_G,
	VIP_GAMMA_MODE10_B,
	VIP_GAMMA_MODE11_R,
	VIP_GAMMA_MODE11_G,
	VIP_GAMMA_MODE11_B,
	VIP_GAMMA_MODE12_R,
	VIP_GAMMA_MODE12_G,
	VIP_GAMMA_MODE12_B,

} VIP_GAMMA_TYPE;

typedef enum _VIP_PANEL_BIT {
	VIP_PANEL_BIT6 = 0,
	VIP_PANEL_BIT8,
	VIP_PANEL_BIT10,
	VIP_PANEL_BIT_OTHERS,
} VIP_PANEL_BIT;

typedef enum _VIP_UV_DELAY_ENABLE {
	VIP_UV_DELAY_OFF = 0,
	VIP_UV_DELAY_ON,
} VIP_UV_DELAY_ENABLE;

typedef enum _VIP_GAMMA_CHANNEL_RGB {
	GAMMA_CHANNEL_R = 0,
	GAMMA_CHANNEL_G,
	GAMMA_CHANNEL_B,
	VIP_GAMMA_CHANNEL_RGB_MAX,
	GAMMA_CHANNEL_W,
} VIP_GAMMA_CHANNEL_RGB;

typedef enum _VIP_RGB2YUV_OUT_DATA_Ctrl {
	RGB2YUV_OUT_DATA_Old_Mode = 0,
	RGB2YUV_OUT_DATA_16_235,
	RGB2YUV_OUT_DATA_0_255,
	RGB2YUV_OUT_DATA_newTable_newPath_Mode,
	RGB2YUV_OUT_DATA_0_255_HDR10_Mode,

	RGB2YUV_OUT_DATA__Max,
} VIP_RGB2YUV_OUT_DATA_Ctrl;

typedef enum _VIP_RGB2YUV_COEF_MATRIX_MODE {
	RGB2YUV_COEF_BYPASS_NORMAL_GAIN = 0,
	RGB2YUV_COEF_BYPASS_0_255_TO_16_235,
	RGB2YUV_COEF_RGB_0_255_TO_YCC601_16_235,
	RGB2YUV_COEF_RGB_16_235_TO_YCC601_16_235,
	RGB2YUV_COEF_RGB_0_255_TO_YCC709_16_235,
	RGB2YUV_COEF_RGB_16_235_TO_YCC709_16_235,
	RGB2YUV_COEF_RGB_0_255_TO_YCC709_0_255,
	RGB2YUV_COEF_TV006_YPP_LOW,
	RGB2YUV_COEF_RGB_0_255_TO_YCC2020_16_235,
	RGB2YUV_COEF_RGB_0_255_TO_YCC2020_0_255,

	RGB2YUV_COEF_YCC601_0_255_TO_YCC709_0_255,

	RGB2YUV_COEF_YCC2020_16_235_TO_YCC709_16_235,
	RGB2YUV_COEF_YCC2020_0_255_TO_YCC709_16_235,

	RGB2YUV_COEF_MATRIX_MODE_Max,

} VIP_RGB2YUV_COEF_MATRIX_MODE;

typedef enum _VIP_RGB2YUV_COEF_MATRIX_ITEMS {
	RGB2YUV_COEF_M11 = 0,
	RGB2YUV_COEF_M12,
	RGB2YUV_COEF_M13,
	RGB2YUV_COEF_M21,
	RGB2YUV_COEF_M22,
	RGB2YUV_COEF_M23,
	RGB2YUV_COEF_M31,
	RGB2YUV_COEF_M32,
	RGB2YUV_COEF_M33,
	RGB2YUV_COEF_Yo_Even,
	RGB2YUV_COEF_Yo_Odd,
	RGB2YUV_COEF_Yo_Gain,
	RGB2YUV_COEF_Sel_RGB,
	RGB2YUV_COEF_Sel_Yin_Offset,
	RGB2YUV_COEF_Sel_UV_Out_Offset,
	RGB2YUV_COEF_Sel_UV_Off,
	RGB2YUV_COEF_Matrix_Bypass,
	RGB2YUV_COEF_Enable_Y_Gain,

	RGB2YUV_COEF_MATRIX_ITEMS_Max,

} VIP_RGB2YUV_COEF_MATRIX_ITEMS;

typedef enum _COLOR_FUN_BYPASS {
	BYPASS_VIVID_COLOR = 0,
	BYPASS_RGB_CON,
	BYPASS_RGB_BRI,
	BYPASS_GAMMA,
	BYPASS_D_DITHER,
	BYPASS_SRGB,
	BYPASS_RGB2YUV_MATRIX,
	BYPASS_YUV2RGB_MATRIX,
} COLOR_FUN_BYPASS;

typedef enum _BYPASS_FLAG {
	IP_BYPASS = 0,
	IP_NO_BYPASS
} BYPASS_FLAG;

#if CONFIG_FIRMWARE_IN_KERNEL
typedef enum _HDR_table_item {
	HDR_EN = 0,
	HDR_420_2_422,
	HDR_422_2_444,
	HDR_DITHER,

	HDR_ITEM_MAX,
} HDR_table_item;
#else
typedef enum _HDR_table_item {
	HDR_YUV2RGB_t_sel,
	HDR_RGB2OPT_t_sel,
	HDR_LUT_t_sel,

	HDR_ITEM_MAX,
} HDR_table_item;
#endif

/*******************************************************************************
 * Structure
 ******************************************************************************/
typedef struct {
	unsigned char gamma_adapt_en;
	unsigned short sat_thl;
	unsigned short sat_thl_mul;
} DRV_Adaptive_Gamma_Ctrl;

typedef struct {
	COLOR_FUN_BYPASS idIP;
	unsigned char bypass_switch;
} Color_Fun_Bypass;
#if 0
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

	VIP_PQ_ByPass_ITEMS_Max,

} VIP_PQ_ByPass_ITEMS;

typedef struct _VIP_PQ_ByPass_Struct{
	unsigned char VIP_PQ_ByPass_TBL[VIP_PQ_ByPass_ITEMS_Max];

} VIP_PQ_ByPass_Struct;
#endif
#define Bin_Num_Output_InvOutput_Gamma 256
#define Output_InvOutput_Gamma_TBL_MAX 5

typedef struct _VIP_Output_InvOutput_Gamma_CTRL_ITEM{
	unsigned char output_Gamma_En;
	unsigned char output_Location;
	unsigned char InvOutput_Gamma_En;

} VIP_Output_InvOutput_Gamma_CTRL_ITEM;

typedef struct _VIP_Output_Gamma_TBL{
	unsigned int TBL_R[Bin_Num_Output_InvOutput_Gamma/2];
	unsigned int TBL_G[Bin_Num_Output_InvOutput_Gamma/2];
	unsigned int TBL_B[Bin_Num_Output_InvOutput_Gamma/2];
	unsigned int TBL_W[Bin_Num_Output_InvOutput_Gamma/2];

} VIP_Output_Gamma_TBL;

typedef struct _VIP_InvOutput_Gamma_TBL{
	unsigned int TBL_R[Bin_Num_Output_InvOutput_Gamma/2];
	unsigned int TBL_G[Bin_Num_Output_InvOutput_Gamma/2];
	unsigned int TBL_B[Bin_Num_Output_InvOutput_Gamma/2];

} VIP_InvOutput_Gamma_TBL;

typedef struct _VIP_Output_InvOutput_Gamma{
	VIP_Output_InvOutput_Gamma_CTRL_ITEM Output_InvOutput_Gamma_CTRL_ITEM;
	VIP_Output_Gamma_TBL Output_Gamma_TBL;
	VIP_InvOutput_Gamma_TBL InvOutput_Gamma_TBL;

} VIP_Output_InvOutput_Gamma;

/*******************************************************************************
 * Program
 ******************************************************************************/
void drvif_color_set_BOE_RGBW(unsigned short *ptr_tab, int w_rate);

void drvif_color_set_Panel_Bit(VIP_PANEL_BIT bit);

void drvif_color_digital_filtering_init(SCALER_DISP_CHANNEL display);
void drvif_color_setSD_dithering(unsigned char enable);

void drvif_color_setydlti(unsigned char display, unsigned char Level);
void drvif_color_setgamma(unsigned char display, unsigned char Mode, VIP_Gamma *ptr);
void drvif_color_setycontrastbrightness_new(unsigned char display, unsigned char Contrast, unsigned char Brightness, unsigned char csp_control);
/* driver for YUV2RGB, sub channel is same as main now. fix this driver for sub channel if necessary.*/
void drvif_color_setYUV2RGB_CSMatrix(DRV_VIP_YUV2RGB_CSMatrix *ptr, VIP_CSMatrix_WriteType WriteMode, VIP_YUV2RGB_Y_SEG idx, unsigned char display, VIP_Table_Select tbl);

void drvif_color_setdithering(void);
void drvif_color_set_main_dither(unsigned char enable);
/*void drvif_color_handler(void);	*/ /* move to scalerColor*/
/*void drvif_color_setdataformathandler(void);	*/ /* move to scalerLib*/

void drvif_color_setrgbcontrast(unsigned char display, unsigned short Red, unsigned short Green, unsigned short Blue, unsigned char  BlendRatio, unsigned char Overlay);
void drvif_color_setrgbbrightness(unsigned char display, unsigned short Red, unsigned short Green, unsigned short Blue);
void drvif_color_gamma_control_front(unsigned char display);
void drvif_color_gamma_control_back(unsigned char display, unsigned char ucWriteEnable);

void drvif_color_colorwrite_output_gamma(unsigned int *pArray, VIP_GAMMA_CHANNEL_RGB RGB_chanel_idx);
void drvif_color_colorwrite_inv_output_gamma(unsigned int *pArray, VIP_GAMMA_CHANNEL_RGB RGB_chanel_idx);
void drvif_color_colorwrite_inv_output_gamma_Enable(unsigned char Enable);

void drvif_color_set_output_gamma_format(unsigned char Enable, unsigned char fmt, unsigned char loc, unsigned char ch_order);
#ifdef MAC5_NO_RGBW
unsigned char drvif_color_Get_RGBW_Mode(void);
#endif
void drvif_color_set_outgamma_10bits(void);

void drvif_color_sub_huesat(unsigned char display, short Hue, short Sat);
void drvif_color_set422to444(unsigned char channel, unsigned char bEnable);
void drvif_color_sethighlightwindowstep(unsigned short hstep, unsigned short wstep, unsigned short vstep, unsigned short lstep);
void drvif_color_set_sethighlightwindowmin(unsigned short minwidth, unsigned short minlen);
void drvif_color_sethighlightwindowborder(unsigned char Border, unsigned char BorderType);
unsigned char drvif_color_gethighlightwindow_enable(void);
void drvif_color_sethighlightwindow(unsigned char Ena_bit, unsigned short HSTA, unsigned short VSTA, unsigned short HEND, unsigned short VEND, unsigned short Border);

void drvif_color_colorspacergb2yuvtransfer(unsigned char channel, unsigned short *table_index);

void drvif_color_setpiprgbcontrastbrightness(unsigned char BlendRatio);
void drvif_color_setuv_sat(unsigned char display, unsigned char Sat);
void drvif_sRGB_SetGrid(unsigned char display, signed int *sRGB_grid);
void scalerVIP_sRGB_Write_FullfSize_rgbChange(int color_change);
void scalerVIP_sRGB_Write_HalfSize_rgbChange(int table_sel, int color_change);

void scalerVIP_sRGB_Read_FullSize(void);

void drvif_color_chroma_coring(unsigned char display, unsigned char domain, unsigned char Level);
void drvif_color_profile_init(unsigned char display);


void wait_for_sRGB_fifo_empty(void);

void drvif_color_UV_Delay_Enable(VIP_UV_DELAY_ENABLE on_off);
void drvif_color_Set_UV_Delay(DRV_VipUV_Delay *ptr);
void drvif_color_Set_UV_Delay_TOP(DRV_VipUV_Delay_TOP_Table *ptr);

void drvif_color_Get_UV_Delay(DRV_VipUV_Delay *ptr);


void drvif_color_Gamma_Curve_Write(unsigned int *Gamma_Encode, VIP_GAMMA_CHANNEL_RGB RGB_chanel_idx);
unsigned char drvif_color_Gamma_Read_Write_Check(void);

void drvif_color_dnewdcti_table(DRV_VipNewDDcti_Table *ptr);
void drvif_color_inewdcti_table(DRV_VipNewIDcti_Table *ptr);

/* 2013.07.07 Diane add for Gamma Log*/
void drvif_Gamma_Encode_Log_Setting(unsigned char value);
void drvif_Gamma_Decode_Log_Setting(unsigned char value);
void drvif_Gamma_Calculated_Log_Setting(unsigned char value);
void drvif_Gamma_Final_Table_Log_Setting(unsigned char value);
void drvif_Output_Gamma_Encode_Log_Setting(unsigned char value);
void drvif_Output_Gamma_Decode_Log_Setting(unsigned char value);
void drvif_Output_Gamma_Calculated_Log_Setting(unsigned char value);
void drvif_Output_Gamma_Final_Table_Log_Setting(unsigned char value);

unsigned char drvif_Gamma_Encode_Log_Getting(void);
unsigned char drvif_Gamma_Decode_Log_Getting(void);
unsigned char drvif_Gamma_Calculated_Log_Getting(void);
unsigned char drvif_Gamma_Final_Table_Log_Getting(void);
unsigned char drvif_Output_Gamma_Encode_Log_Getting(void);
unsigned char drvif_Output_Gamma_Decode_Log_Getting(void);
unsigned char drvif_Output_Gamma_Calculated_Log_Getting(void);
unsigned char drvif_Output_Gamma_Final_Table_Log_Getting(void);

unsigned char drvif_color_Get_Color_UV_Delay(void);
unsigned char drvif_color_Get_Color_UV_Delay_Enable(void);
/*unsigned char drvif_color_regDitherLUT(unsigned char *table);*/
/*void drvif_color_digital_filtering_init(void);*/

void drvif_color_Setditherbit(VIP_PANEL_BIT default_vip_panel_bit);
void drvif_color_dither_mode(unsigned char mode);

/*for xvYvv*/
void drvif_color_inv_gamma_control_front(unsigned char display);
void drvif_color_inv_gamma_control_back(unsigned char display, unsigned char ucWriteEnable);
void drvif_color_Inv_Gamma_Curve_Write(unsigned int *Gamma_Encode, VIP_GAMMA_CHANNEL_RGB RGB_chanel_idx);
void drvif_color_sRGB_ByPass(void);
void drvif_color_xvYcc_colorspaceyuv2rgbtransfer(unsigned char display, unsigned char xvYcc_en_flag);

void fwif_color_set_TSB_rgbbrightness(unsigned char display, unsigned short Red, unsigned short Green, unsigned short Blue);

void drvif_color_set_Adaptive_Gamma(DRV_Adaptive_Gamma_Ctrl *ptr);

/*using drvif_color_setYUV2RGB_CSMatrix instead, elieli*/
#if 0
void drvif_color_colorspaceyuv2rgbtransfer_coef_by_y(unsigned char display, unsigned char which_table, unsigned int tYUV2RGB_COEF_BY_Y_table[][YUV2RGB_COEF_BY_Y_Seg_Num]);
void drvif_color_colorspaceyuv2rgbtransfer_uv_offset_by_y(unsigned char display, unsigned char which_table, unsigned int tYUV2RGB_UV_OFFSET_BY_Y_table[][YUV2RGB_UV_OFFSET_BY_Y_Seg_Num]);
void drvif_color_colorspaceyuv2rgbtransfer(unsigned char display, unsigned short *table_index);

void drvif_color_reg_YUV2RGB_COEF_BY_Y_Table(unsigned int *table);
void drvif_color_reg_YUV2RGB_UV_OFFSET_BY_Y_Table(unsigned int *table);
#endif
#if 0 //jyyang20161215 // Dstat is remoived since mac5
int drvif_color_get_rgb_pixel_info(RGB_pixel_info *data);
#endif
void drvif_color_bypass(Color_Fun_Bypass *ptr, unsigned char ipNum);
void drvif_color_set_WB_pattern_setup(void);
void drvif_color_set_WB_pattern_off(unsigned char bForceBG, unsigned char b422Format);
void drvif_color_set_WB_pattern_RGB(unsigned char R, unsigned char G, unsigned char B);
unsigned char drvif_color_get_WB_pattern_on(void);


#if 0//juwen, 161222, mac5p no colortmp
void drvif_color_setrgbcolortemp_contrast(unsigned short Red, unsigned short Green, unsigned short Blue);
void drvif_color_setrgbcolortemp_bright(unsigned short Red, unsigned short Green, unsigned short Blue);
void drvif_color_setrgbcolortemp_en(unsigned char enable);
#endif

void drvif_color_set_new_uvc(DRV_NEW_UVC *ptr);
void drvif_color_set_de_contour(DRV_De_CT_1D *ptr);
void drvif_color_set_Blue_Stretch(DRV_Gamma_BS *ptr);

void drvif_color_set_Color_Mapping(DRV_Color_Mapping *ptr);
void drvif_color_inv_gamma_init(void);

void drvif_color_D_3dLUT(unsigned char LUT_Ctrl, unsigned int *pArray);//flora@20150617
void drvif_color_Read_D_3dLUT(unsigned char *LUT_Ctrl, unsigned int *pArray);

void drvif_color_set_Vivid_Color_Enable(unsigned char ucEnable);
void drvif_color_set_sub_Vivid_Color_Enable(unsigned char ucEnable);

void drvif_color_disable_VIP(void);

void drvif_color_set_color_temp(unsigned char enable, unsigned short Red_Con, unsigned short Green_Con, unsigned short Blue_Con,
	short Red_Bri, short Green_Bri, short Blue_Bri);
void drvif_color_inv_gamma_enable(unsigned char display, unsigned char enable, unsigned char useRPC);
void drvif_color_gamma_enable(unsigned char display, unsigned char enable, unsigned char useRPC);
void drvif_DM_B05_Set(unsigned short *lutMap);
void drvif_DM_HDR_3dLUT(unsigned char enable, unsigned int *pArray);/*flora@20150617, modify by juwen*/
#ifdef CONFIG_I2RND_B05_ENABLE
void drvif_DM_HDR_3dLUT_16_i2run(unsigned char enable, unsigned short *pArray);
#endif
void drvif_DM_HDR_3dLUT_16(unsigned char enable, unsigned short *pArray);/*flora@20150617, modify by juwen*/

char drvif_Wait_VO_start(short delay0, short delay1, unsigned short timeout);
char drvif_Wait_VGIP_start(short delay0, short delay1, unsigned short timeout);
char drvif_Get_VGIP_Active_Info(unsigned short *v_sta, unsigned short *v_len, unsigned short *line_cnt);

void drvif_Read_DM_HDR_3dLUT(unsigned char *enable, unsigned int *pArray);
void drvif_HDR_YUV2RGB(unsigned char enable, unsigned int *pArray);
void drvif_HDR_RGB2OPT(unsigned char enable, unsigned int *pArray);
void drvif_HDMI_HDR_I3DDMA_RGB2YUV422(unsigned char enable, unsigned short *pArray, unsigned char enable_444_to_422);
void drvif_HDMI_HDR_I3DDMA_RGB2YUV_only_Matrix(unsigned short *pArray);
char drvif_Set_DM_HDR_3dLUT_24x24x24_16(unsigned char enable, unsigned short *pArray);
char drvif_Set_DM_HDR_3dLUT_24x24x24_16_By_DMA(unsigned char enable, unsigned short *pArray, unsigned int addr, unsigned int* vir_addr);
char drvif_Get_DM_HDR_3dLUT_24x24x24_16(unsigned short *pArray);
void drvif_Set_DM_HDR_CLK(void);

void drvif_color_disable_VIP(void);

unsigned char drvif_color_set_BBC_Enable(unsigned char enable);

#if CONFIG_FIRMWARE_IN_KERNEL
unsigned char drvif_color_set_HDR10_Enable(unsigned char* enable);
#else
void drvif_HDR10_init(DRV_HDR10_submodule_CTL *pmoduleArray, DRV_HDR10_top_init_CTL *ptopArray);
#endif
#ifdef CONFIG_HDR_SDR_SEAMLESS
unsigned char drvif_color_set_HDR10_Enable_Seamless(unsigned char* enable);
#endif
void drvif_HDR_EOTF_OETF(unsigned char Mode);

unsigned char drvif_HDR_get_VO_Decompress_Status(void);

char drvif_M_Plus_Status_Check(void);

char drvif_color_set_PQ_ByPass(unsigned char bypass_item);
void drvif_color_set_video_fw_irq(void);

void drvif_set_main_dither(void);
#ifdef CONFIG_HW_SUPPORT_MEMC
void drvif_color_set_MEMC_dither(void);
#endif


void WaitDOLBY_DB_Apply_Clean(void);

void drvif_color_D_3dLUT_Enable(unsigned char LUT_Ctrl);
void drvif_color_get_rgb2yuvtransfer(unsigned char channel, unsigned short *table_index);

void drvif_color_out_gamma_control_front(void);
void drvif_color_out_gamma_control_back(void);
void drvif_color_out_gamma_control_enable(unsigned char enable);
void drvif_color_colorwrite_outGamma(unsigned int *pArray);
void drvif_color_Out_Gamma_Curve_Write(unsigned int *Gamma_Encode, VIP_GAMMA_CHANNEL_RGB RGB_chanel_idx);

char drvif_DM2_Wait_DB_Apply(void);
void drvif_DM2_EOTF_Set(unsigned int *EOTF_table32_R, unsigned int *EOTF_table32_G, unsigned int *EOTF_table32_B);
char drvif_DM2_EOTF_Set_By_DMA(unsigned int *EOTF_table32_R, unsigned int *EOTF_table32_G, unsigned int *EOTF_table32_B, unsigned int addr, unsigned int* vir_addr);
void drvif_DM2_EOTF_Get(unsigned int *EOTF_table32_R, unsigned int *EOTF_table32_G, unsigned int *EOTF_table32_B);
void drvif_DM2_EOTF_Enable(unsigned char En, unsigned char sel);
void drvif_DM2_OETF_Set(unsigned short *OETF_table16_R, unsigned short *OETF_table16_G, unsigned short *OETF_table16_B);
char drvif_DM2_OETF_Set_By_DMA(unsigned short *OETF_table16_R, unsigned short *OETF_table16_G, unsigned short *OETF_table16_B, unsigned int addr, unsigned int* vir_addr);
void drvif_DM2_OETF_Get(unsigned short *OETF_table16_R, unsigned short *OETF_table16_G, unsigned short *OETF_table16_B);
void drvif_DM2_OETF_Enable(unsigned char En, unsigned char sel);
char drvif_DM2_ToneMapping_Set(short *TM_table12_R, short *TM_table12_G, short *TM_table12_B);
char drvif_DM2_ToneMapping_Get(short *TM_table12_R, short *TM_table12_G, short *TM_table12_B);
char drvif_DM2_ToneMapping_Enable(unsigned char En);
void drvif_DM2_GAMMA_Enable(unsigned char En);
void drvif_DM2_GAMMA_out_shift_Enable(unsigned char En);
unsigned char drvif_DM2_HDR_histogram_Get(unsigned int *histogram_table24);
void drvif_DM2_HDR_RGB_max_Get(unsigned int *RGB_max);
void drvif_color_set_Mplus_ModeChange(DRV_Mplus_ModeChange *ptr);
void drvif_color_SetFrameGainLimit(unsigned short nFrameGainLimit);
void drvif_color_GetFrameGainLimit (unsigned short *nFrameGainLimit);
void drvif_color_SetPixelGainLimit(unsigned short nPixelGainLimit);
void drvif_color_GetPixelGainLimit(unsigned short *nPixelGainLimit);

char drvif_color_Access_Reg(unsigned int addr, unsigned char bit_mask, unsigned char isSet_flag, unsigned int *reg_value);

void drvif_color_set_RGBW_Curcuit(VIP_RGBW_MODE mode);
unsigned char drvif_DM_HDR10_enable_Get(void);
unsigned char drvif_DM_HDR10_porch_check(void);
unsigned int drvif_DM_HDR10_I_V_sta_check(void);
void drvif_color_get_YUV2RGB_nonliner_index(unsigned short *pYidx);
void drvif_HDMI_Dither_Enable(unsigned char Enable);
void drvif_color_set_outgamma_10bits(void);
void drvif_color_set_Partten4AutoGamma(unsigned char  Enable, unsigned short  r_Val,unsigned short  g_Val,unsigned short  b_Val);
void drvif_color_set_Partten4AutoGamma_mute(unsigned char mute_flag, unsigned char display_flag,Drvif_SCALER_DISPLAY_DATA* sdp_info);
char drvif_color_set_PQ_Module(unsigned char bypass_item,unsigned char bEnable);
short drvif_DM2_EOTF_OETF_3DLUT_DMA_Err_Check(void);
void drvif_DM2_EOTF_OETF_3DLUT_DMA_Err_Reset(void);



#ifdef __cplusplus
}
#endif


#endif
/* 100312 Erin*/


