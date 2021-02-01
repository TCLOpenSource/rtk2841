#ifndef __SCALER_COLOR_TV006_H__
#define __SCALER_COLOR_TV006_H__

#ifdef __cplusplus
extern "C" {
#endif
#if CONFIG_FIRMWARE_IN_KERNEL
#include <tvscalercontrol/vip/scalerColor.h>
#else
#include <Platform_Lib/TVScalerControl/vip/scalerColor.h>
#endif

#ifndef SINT8
typedef	signed char				__SINT8;
#define SINT8 __SINT8
#endif

#ifndef SINT16
typedef	signed short			__SINT16;
#define SINT16 __SINT16
#endif

#if CONFIG_FIRMWARE_IN_KERNEL
#else
#ifndef BOOLEAN
typedef	unsigned int			__BOOLEAN;
#define BOOLEAN __BOOLEAN
#endif
#endif

typedef enum {
	RGB2YUV_BLACK_LEVEL_UNDEFINE = 0,
	RGB2YUV_BLACK_LEVEL_LOW,
	RGB2YUV_BLACK_LEVEL_HIGH,
	RGB2YUV_BLACK_LEVEL_AUTO,
} RGB2YUV_BLACK_LEVEL;

typedef enum {
	ACCESS_MODE_READ = 0,
	ACCESS_MODE_GET = ACCESS_MODE_READ,
	ACCESS_MODE_WRITE,
	ACCESS_MODE_SET = ACCESS_MODE_WRITE,
	ACCESS_MODE_MAX,
} ACCESS_MODE;
//------------------------------NR Start -------------------------------------------------

typedef struct{
	BOOLEAN 	Spatial_Enable_Y;
	UINT8		Gain;
	UINT16		Thd_UpBnd;
	UINT8		Thd_LowBnd;
	UINT8		Thd_Step;
	UINT8		RZ_filter_size;
	UINT8		Weight2Y;
	UINT8		Weight3Y;
	UINT8		Weight4Y;
	UINT8		SpatialThlY;
	UINT8		SpatialThl2Y;
	UINT8		SpatialThl4Y;
}CHIP_LPFY_T;

typedef struct{
	BOOLEAN 	Spatial_Enable_C;
	UINT8		LPResultWeightC;
	UINT8		RZ_filter_Size;
	UINT8		Weight2C;
	UINT8		Weight3C;
	UINT8		Weight4C;
	UINT8		SpatialThlC;
	UINT8		SpatialThl2C;
	UINT8		SpatialThl4C;
}CHIP_LPFC_T;


typedef struct{
	UINT16	Curve_step1;
	UINT16	Curve_step2;
	UINT16	Curve_step3;
	UINT16	Curve_step4;
	UINT16	Curve_step5;
	UINT16	Curve_step6;
	UINT16	Curve_step7;
	UINT16	Curve_step8;
}CHIP_NR_CURVEMAPPING_STEP_T;

typedef struct{
	UINT8	Weight1_0;
	UINT8	Weight1_1;
	UINT8	Weight1_2;
	UINT8	Weight1_3;
	UINT8	Weight1_4;
	UINT8	Weight1_5;
	UINT8	Weight1_6;
	UINT8	Weight1_7;
	UINT8	Weight1_8;
	UINT8	Weight2_0;
	UINT8	Weight2_1;
	UINT8	Weight2_2;
	UINT8	Weight2_3;
	UINT8	Weight2_4;
	UINT8	Weight2_5;
	UINT8	Weight2_6;
	UINT8	Weight2_7;
	UINT8	Weight2_8;
}CHIP_NR_CURVEMAPPING_WEIGHT_UI_T;

typedef struct{
	UINT8		Weight1Y;
	UINT8		Weight2Y;
	UINT8		De_ring_Weight;
	UINT8		Ring_Range;
	UINT8		Ring_gain;
}CHIP_BLENDING_T;

typedef struct{
// RTNR Old Mode_General Ctrl
	BOOLEAN	Y_enable;
	UINT8	Mad[15][10];
}CHIP_TNRY_T;

typedef struct{
	BOOLEAN	C_enable;
	UINT8	Mad[7][10];
}CHIP_TNRC_T;



typedef struct{
	BOOLEAN 	Edge_LPF_enable;
	UINT8		Edge_Theshold;
	UINT8		Edge_Theshold_Step;
	BOOLEAN 	Far_Var_farEdge_refine_Enable;
	UINT8		Range;
	UINT8		Far_Var_Gain;
	UINT8		Far_Var_offset;
	UINT8		Hdiff_Frac_Shift;
	UINT8		varDiff_refine_gain;
	UINT8		Vdiff_Frac_Shift;
	BOOLEAN 	Decay_enable;
	UINT8		Hdecay_Start;
	UINT8		Hdecay_Step;
	UINT8		Vdecay_Start;
	UINT8		Vdecay_Step;
	UINT8		MNR_Weight;
	UINT8		Blending_Mode;
}CHIP_MNR_T;

typedef struct{
	BOOLEAN 	MosquitoNR_Enable;
	UINT8		Positive_nLevel_Offset;
	UINT8		Positive_nLevel_Shift;
	UINT8		Negative_nLevel_Offset;
	UINT8		Negative_nLevel_Shift;
	UINT8		Edge_Strength_Gain;
	UINT8		Threshold;
	UINT8		Threshold_Step;
	UINT8		Shift;
}CHIP_MNR_UI_T;


typedef struct{
	UINT8		MpegResultWeight_H;
	UINT8		DC_mode_filter;
	UINT8		Mpg_DC_Gain;
}CHIP_MPEGNR_UI_T;

typedef struct{
	UINT16 NR_LEVEL;
	CHIP_LPFY_T LPF_Y;
	CHIP_LPFC_T LPF_C;
	CHIP_NR_CURVEMAPPING_STEP_T	CurveMappingStep;
	CHIP_NR_CURVEMAPPING_WEIGHT_UI_T CurveMappingWeight;
	CHIP_BLENDING_T BLENDING;
	CHIP_TNRY_T TNR_Y;
	CHIP_TNRC_T TNR_C;
}CHIP_NOISE_REDUCTION_T;

typedef struct{
	CHIP_NOISE_REDUCTION_T NOISE_REDUCTION_T;
}CHIP_NOISE_REDUCTION_TYPE_T;

typedef struct{
	UINT16 MPEG_LEVEL;
	CHIP_MNR_T MNR_T;
	CHIP_MNR_UI_T MNR_UI_T;
	CHIP_MPEGNR_UI_T MPEGNR_UI_T;
}CHIP_MPEG_NOISE_REDUCTION_T;
typedef struct{
	CHIP_MPEG_NOISE_REDUCTION_T MPEG_NOISE_REDUCTION_T;
}CHIP_MPEGNR_TYPE_T;
//------------------------------Nr End----------------------------------------------------
typedef struct {
	BOOLEAN	chroma_gain_en;
	BOOLEAN	chroma_gain_mode;
	BOOLEAN	chroma_gain_lookup_mode;
	UINT8	chroma_gain_base;
	BOOLEAN	chroma_enhance_above_tab_select_main;
	BOOLEAN	chroma_enhance_below_tab_select_main;
	BOOLEAN	saturation_byy_u_tab_select_main;
	BOOLEAN	saturation_byy_v_tab_select_main;

	BOOLEAN	chroma_gain_limit_en;
	UINT8	chroma_gain_limit_seg[8];
	SINT8	chroma_gain_tab0_seg[17];
	SINT8	chroma_gain_tab1_seg[17];
} CHIP_DCC_CHROMA_GAIN_T;

typedef struct {
	UINT16	y0_center;
	UINT16	u0_center;
	UINT16	v0_center;
	UINT8	y0_range;
	UINT8	u0_range;
	UINT8	v0_range;

	UINT16	y1_center;
	UINT16	u1_center;
	UINT16	v1_center;
	UINT8	y1_range;
	UINT8	u1_range;
	UINT8	v1_range;

	UINT16	y2_center;
	UINT16	u2_center;
	UINT16	v2_center;
	UINT8	y2_range;
	UINT8	u2_range;
	UINT8	v2_range;

	UINT16	y3_center;
	UINT16	u3_center;
	UINT16	v3_center;
	UINT8	y3_range;
	UINT8	u3_range;
	UINT8	v3_range;
} CHIP_DCC_SKIN_TONE_RANGE_T;

typedef struct {
	UINT16	D_DCC_SKIN_EN;

	UINT8	Y0_seg[8];
	UINT8	Y1_seg[8];
	UINT8	Y2_seg[8];
	UINT8	Y3_seg[8];
	UINT8	C0_seg[8];
	UINT8	C1_seg[8];
	UINT8	C2_seg[8];
	UINT8	C3_seg[8];
} CHIP_DCC_SKIN_TONE_GAIN_T;


typedef struct {
	CHIP_DCC_SKIN_TONE_RANGE_T	range;
	CHIP_DCC_SKIN_TONE_GAIN_T	value;
} CHIP_DCC_SKINTONE_T;

typedef struct {
	CHIP_DCC_CHROMA_GAIN_T	stChromaGain;
	CHIP_DCC_SKINTONE_T	stSkinTone;
} CHIP_DCC_T;


/* set picture ctrl*/
typedef enum {
	PIC_CTRL_Contrast = 0,
	PIC_CTRL_Brightness,
	PIC_CTRL_Color,
	PIC_CTRL_Tint,
	PIC_CTRL_ITEM_MAX,
} VPQ_PIC_CTRL_ITEM;

typedef struct _VPQ_SetPicCtrl_Mapping_T {
	UINT8 Index_0[PIC_CTRL_ITEM_MAX];
	UINT8 Index_50[PIC_CTRL_ITEM_MAX];
	UINT8 Index_100[PIC_CTRL_ITEM_MAX];

} VPQ_SetPicCtrl_Mapping_T;

typedef struct _VPQ_SetPicCtrl_T {
	UINT8 wId;
	short siVal[PIC_CTRL_ITEM_MAX];
	short Gain_Val[PIC_CTRL_ITEM_MAX];
} VPQ_SetPicCtrl_T;


/* VPQ_SetSaturationLUT */
#define VPQ_SaturationLUT_Seg_Max VIP_YUV2RGB_Y_Seg_Max
#define VPQ_SaturationLUT_Gain_ShiftBit 7

typedef struct {
	unsigned short uSaturationY[VPQ_SaturationLUT_Seg_Max];
	unsigned short uSaturationX[16];
} VPQ_SAT_LUT_T;

/* ---------- 20150602 to follow LG DB---------------*/
/**********************************************************************
	SHP
***********************************************************************/

typedef struct{
	UINT8	edge_mode;
	UINT8	sobel_mode;
	UINT8	edgextrange;
	UINT8	sobel_upbnd;
	UINT8	sobel_stepbit;
	UINT8	zdiff_upbnd;
	UINT8	zdiff_stepbit;
	UINT8	zigsftbit_reg;
	UINT8	texture_enable;
	UINT8	tex_upbnd;
	UINT8	tex_stepbit;
	UINT8	actsftbit_reg;
	UINT8	lpf_mode;
	UINT8	lpf_filter;
}CHIP_SEGMENTATION_T;

typedef struct{
	BOOLEAN	edgeCoringEn;
	BOOLEAN	edgeGainEn;
	UINT8	bigEdgeRatio;
	UINT8	smallEdgeRatio;
	UINT8	deltaEdgeRatio;
	UINT8	smallEdgeUlevel;
	UINT8	deltaEdgeUlevel;
	UINT8	edgeCoringClip;
	UINT8	edgeGainBound;
	UINT8	edgeSerRange;
	UINT8	Edge_delta_ext_R;
}CHIP_EDGE_CORING_MODE_T;

typedef struct{
	UINT8	linearY_Umode;
	UINT8	linearY_Lmode;
	UINT8	linearY_UB;
	UINT8	linearY_LB;
}CHIP_Y_REMAPPING_T;

typedef struct{
	BOOLEAN	edgpk_en;
	UINT8	edge_select_filter;
	UINT8	edge_lpf_shift;
	SINT16	coef_c0_0;
	SINT8	coef_c1_0;
	SINT8	coef_c2_0;
	SINT8	coef_c3_0;
	SINT8	coef_c4_0;
	SINT8	coef_c5_0;
	SINT8	coef_c6_0;
	SINT8	coef_c7_0;
	SINT8	coef_c8_0;
	SINT8	coef_c9_0;
	SINT8	coef_c10_0;
	SINT8	coef_c0_1;
	SINT8	coef_c1_1;
	SINT8	coef_c2_1;
	SINT8	coef_c3_1;
	SINT8	coef_c4_1;
	SINT8	coef_c5_1;
	SINT8	coef_c0_2;
	SINT8	coef_c1_2;
	SINT8	coef_c2_2;
	SINT8	coef_c3_2;
	SINT8	coef_c4_2;
	SINT8	coef_c5_2;
	SINT8	coef_c0_3;
	SINT8	coef_c0_4;
}CHIP_EDGE_HPF_T;

typedef struct{
	UINT16	pos_s1;
	UINT16	pos_s2;
	UINT16	pos_s3;
	UINT16	pos_s4;
	UINT16	pos_s5;
	UINT16	pos_s6;
	UINT16	pos_s7;
	UINT16	pos_s8;
	UINT16	pos_s9;
	UINT16	pos_s10;
	UINT16	pos_s11;
	UINT16	pos_s12;
	UINT16	pos_s13;
	UINT16	pos_s14;
	UINT16	neg_s1;
	UINT16	neg_s2;
	UINT16	neg_s3;
	UINT16	neg_s4;
	UINT16	neg_s5;
	UINT16	neg_s6;
	UINT16	neg_s7;
	UINT16	neg_s8;
	UINT16	neg_s9;
	UINT16	neg_s10;
	UINT16	neg_s11;
	UINT16	neg_s12;
	UINT16	neg_s13;
	UINT16	neg_s14;
}CHIP_EDGE_CURVEMAPPING_STEP_T;

typedef struct{
	UINT8	Gain_Pos;
	UINT8	Gain_Neg;
	UINT8	Gain_Pos2;
	UINT8	Gain_Neg2;
	UINT16	Range_Pos;
	UINT16	Range_Neg;
	UINT8	Coring;
	UINT8	Edge_Shift;
	BOOLEAN	Edge_curve_en;
	UINT16	pos_g0;
	UINT16	pos_g1;
	UINT16	pos_g2;
	UINT16	pos_g3;
	UINT16	pos_g4;
	UINT16	pos_g5;
	UINT16	pos_g6;
	UINT16	pos_g7;
	UINT16	pos_g8;
	UINT16	pos_g9;
	UINT16	pos_g10;
	UINT16	pos_g11;
	UINT16	pos_g12;
	UINT16	pos_g13;
	UINT16	pos_g14;
	UINT16	neg_g0;
	UINT16	neg_g1;
	UINT16	neg_g2;
	UINT16	neg_g3;
	UINT16	neg_g4;
	UINT16	neg_g5;
	UINT16	neg_g6;
	UINT16	neg_g7;
	UINT16	neg_g8;
	UINT16	neg_g9;
	UINT16	neg_g10;
	UINT16	neg_g11;
	UINT16	neg_g12;
	UINT16	neg_g13;
	UINT16	neg_g14;
}CHIP_EDGE_CURVEMAPPING_UI_T;

typedef struct{
	BOOLEAN	texpk_en;
	UINT8	text_select_filter;
	UINT8	tex_lpf_shift;
	SINT16	coef_c0_0;
	SINT8	coef_c1_0;
	SINT8	coef_c2_0;
	SINT8	coef_c3_0;
	SINT8	coef_c4_0;
	SINT8	coef_c5_0;
	SINT8	coef_c6_0;
	SINT8	coef_c7_0;
	SINT8	coef_c8_0;
	SINT8	coef_c9_0;
	SINT8	coef_c10_0;
	SINT8	coef_c0_1;
	SINT8	coef_c1_1;
	SINT8	coef_c2_1;
	SINT8	coef_c3_1;
	SINT8	coef_c4_1;
	SINT8	coef_c5_1;
	SINT8	coef_c0_2;
	SINT8	coef_c1_2;
	SINT8	coef_c2_2;
	SINT8	coef_c3_2;
	SINT8	coef_c4_2;
	SINT8	coef_c5_2;
	SINT8	coef_c0_3;
	SINT8	coef_c0_4;
}CHIP_TEXTURE_HPF_T;

typedef struct{
	UINT16	pos_s1;
	UINT16	pos_s2;
	UINT16	pos_s3;
	UINT16	pos_s4;
	UINT16	pos_s5;
	UINT16	pos_s6;
	UINT16	pos_s7;
	UINT16	pos_s8;
	UINT16	pos_s9;
	UINT16	pos_s10;
	UINT16	pos_s11;
	UINT16	pos_s12;
	UINT16	pos_s13;
	UINT16	pos_s14;
	UINT16	neg_s1;
	UINT16	neg_s2;
	UINT16	neg_s3;
	UINT16	neg_s4;
	UINT16	neg_s5;
	UINT16	neg_s6;
	UINT16	neg_s7;
	UINT16	neg_s8;
	UINT16	neg_s9;
	UINT16	neg_s10;
	UINT16	neg_s11;
	UINT16	neg_s12;
	UINT16	neg_s13;
	UINT16	neg_s14;
}CHIP_TEXTURE_CURVEMAPPING_STEP_T;

typedef struct{
	UINT8	Gain_Pos;
	UINT8	Gain_Neg;
	UINT8	Gain_Pos2;
	UINT8	Gain_Neg2;
	UINT16	Range_Pos;
	UINT16	Range_Neg;
	UINT8	Coring;
	UINT8	Tex_Shift;
	BOOLEAN	enable;
	UINT16	pos_g0;
	UINT16	pos_g1;
	UINT16	pos_g2;
	UINT16	pos_g3;
	UINT16	pos_g4;
	UINT16	pos_g5;
	UINT16	pos_g6;
	UINT16	pos_g7;
	UINT16	pos_g8;
	UINT16	pos_g9;
	UINT16	pos_g10;
	UINT16	pos_g11;
	UINT16	pos_g12;
	UINT16	pos_g13;
	UINT16	pos_g14;
	UINT16	neg_g0;
	UINT16	neg_g1;
	UINT16	neg_g2;
	UINT16	neg_g3;
	UINT16	neg_g4;
	UINT16	neg_g5;
	UINT16	neg_g6;
	UINT16	neg_g7;
	UINT16	neg_g8;
	UINT16	neg_g9;
	UINT16	neg_g10;
	UINT16	neg_g11;
	UINT16	neg_g12;
	UINT16	neg_g13;
	UINT16	neg_g14;
}CHIP_TEXTURE_CURVEMAPPING_UI_T;

typedef struct {
	SINT16	h9_c0;
	SINT8	h9_c1;
	SINT8	h9_c2;
	SINT8	h9_c3;
	SINT8	h9_c4;
	SINT16	h13_c0;
	SINT8	h13_c1;
	SINT8	h13_c2;
	SINT8	h13_c3;
	SINT8	h13_c4;
	SINT8	h13_c5;
	SINT8	h13_c6;
	SINT16	h21_c0;
	SINT8	h21_c1;
	SINT8	h21_c2;
	SINT8	h21_c3;
	SINT8	h21_c4;
	SINT8	h21_c5;
	SINT8	h21_c6;
	SINT8	h21_c7;
	SINT8	h21_c8;
	SINT8	h21_c9;
	SINT8	h21_c10;
	SINT16	v91_c0;
	SINT8	v91_c1;
	SINT8	v91_c2;
	SINT8	v91_c3;
	SINT8	v91_c4;
	SINT16	v92_c0;
	SINT8	v92_c1;
	SINT8	v92_c2;
	SINT8	v92_c3;
	SINT8	v92_c4;
	SINT16	v93_c0;
	SINT8	v93_c1;
	SINT8	v93_c2;
	SINT8	v93_c3;
	SINT8	v93_c4;
} CHIP_COMMON_HPF_T;

typedef struct{
	BOOLEAN	Slope_Gain_Enable;
	UINT8	DIR;
	BOOLEAN	FH;
	UINT8	Gain_boundPos;
	UINT8	Gain_boundNeg;
	UINT8	Gain_extendPos;
	UINT8	Gain_extendNeg;
	BOOLEAN	flat_enable;
	UINT8	flat_offset;
	UINT8	flat_gain;
}CHIP_SLOPE_GAIN_MASK_T;

typedef struct {
	BOOLEAN	vpk_en;
	UINT16	vpk_c0;
	SINT16	vpk_c1;
	SINT8	vpk_c2;
	SINT8	vpk_c3;
	SINT8	vpk_c4;
} CHIP_VERTICAL_HPF_T;

typedef struct {
	UINT16	pos_s1;
	UINT16	pos_s2;
	UINT16	pos_s3;
	UINT16	pos_s4;
	UINT16	pos_s5;
	UINT16	pos_s6;
	UINT16	pos_s7;
	UINT16	pos_s8;
	UINT16	pos_s9;
	UINT16	pos_s10;
	UINT16	pos_s11;
	UINT16	pos_s12;
	UINT16	pos_s13;
	UINT16	pos_s14;
	UINT16	neg_s1;
	UINT16	neg_s2;
	UINT16	neg_s3;
	UINT16	neg_s4;
	UINT16	neg_s5;
	UINT16	neg_s6;
	UINT16	neg_s7;
	UINT16	neg_s8;
	UINT16	neg_s9;
	UINT16	neg_s10;
	UINT16	neg_s11;
	UINT16	neg_s12;
	UINT16	neg_s13;
	UINT16	neg_s14;
} CHIP_VERTICAL_CURVEMAPPING_STEP_T;

typedef struct {
	UINT8	Gain_Pos;
	UINT8	Gain_Neg;
	UINT8	Coring;
	UINT8	Gain_Pos2;
	UINT8	Gain_Neg2;
	UINT8	Range_Pos;
	UINT8	Range_Neg;
	BOOLEAN	 V_Parameters_En;
	UINT8	Edge_Gain_Pos;
	UINT8	Edge_Gain_Neg;
	UINT8	Edge_Coring;
	UINT8	Edge_Gain_Pos2;
	UINT8	Edge_Gain_Neg2;
	UINT16	Edge_Range_Pos;
	UINT16	Edge_Range_Neg;
	BOOLEAN v_tex_en;
	BOOLEAN v_dering_en;
	BOOLEAN	enable;
	UINT16	pos_g0;
	UINT16	pos_g1;
	UINT16	pos_g2;
	UINT16	pos_g3;
	UINT16	pos_g4;
	UINT16	pos_g5;
	UINT16	pos_g6;
	UINT16	pos_g7;
	UINT16	pos_g8;
	UINT16	pos_g9;
	UINT16	pos_g10;
	UINT16	pos_g11;
	UINT16	pos_g12;
	UINT16	pos_g13;
	UINT16	pos_g14;
	UINT16	neg_g0;
	UINT16	neg_g1;
	UINT16	neg_g2;
	UINT16	neg_g3;
	UINT16	neg_g4;
	UINT16	neg_g5;
	UINT16	neg_g6;
	UINT16	neg_g7;
	UINT16	neg_g8;
	UINT16	neg_g9;
	UINT16	neg_g10;
	UINT16	neg_g11;
	UINT16	neg_g12;
	UINT16	neg_g13;
	UINT16	neg_g14;
} CHIP_VERTICAL_CURVEMAPPING_UI_T;

typedef struct{
	BOOLEAN Slope_Gain_V_Enable;
	UINT8	DIR;
	UINT8	Gain_boundPos;
	UINT8	Gain_boundNeg;
	UINT8	Gain_extendPos;
	UINT8	Gain_extendNeg;
	BOOLEAN	flat_v_enable;
	UINT8	flat_offset_v;
	UINT8	flat_gain_v;
}CHIP_VERTICAL_SLOPE_GAIN_MASK_T;

typedef struct {
	BOOLEAN	gain_by_y_en;
	BOOLEAN	gain_by_y_v_en;
	BOOLEAN	gain_by_y_tex_en;
	BOOLEAN	gain_by_y_edg_en;
	BOOLEAN	lpf_weight_en;
	BOOLEAN	lpf_weight_edg_en;
	BOOLEAN	lpf_weight_tex_en;
	BOOLEAN	max_min_gain_en;
	BOOLEAN	max_min_v_en;
	BOOLEAN	max_min_tex_en;
	BOOLEAN	max_min_edg_en;
	BOOLEAN	lv_by_Y_enable;
	BOOLEAN	lv_by_y_edg_enable;
	BOOLEAN	lv_by_y_v_edg_enable;
	BOOLEAN	lv_by_y_tex_enable;
	BOOLEAN	lv_by_y_v_enable;


	UINT8	coef_c0;
	UINT8	coef_c1;
	UINT8	coef_c2;
	UINT8	coef_c3;
	UINT8	coef_c4;
	UINT8	coef_c5;

	UINT16	maxmin_s1;
	UINT16	maxmin_s2;
	UINT16	maxmin_s3;
	UINT16	maxmin_s4;
	UINT16	maxmin_s5;
	UINT16	maxmin_s6;

	UINT16	maxmin_g0;
	UINT16	maxmin_g1;
	UINT16	maxmin_g2;
	UINT16	maxmin_g3;
	UINT16	maxmin_g4;
	UINT16	maxmin_g5;
	UINT16	maxmin_g6;

	UINT16	blending_s1;
	UINT16	blending_s2;
	UINT16	blending_s3;
	UINT16	blending_s4;
	UINT16	blending_s5;
	UINT16	blending_s6;

	UINT16	blending_g0;
	UINT16	blending_g1;
	UINT16	blending_g2;
	UINT16	blending_g3;
	UINT16	blending_g4;
	UINT16	blending_g5;
	UINT16	blending_g6;

	UINT16	y_s1;
	UINT16	y_s2;
	UINT16	y_s3;
	UINT16	y_s4;
	UINT16	y_s5;
	UINT16	y_s6;

	UINT16	y_g0;
	UINT16	y_g1;
	UINT16	y_g2;
	UINT16	y_g3;
	UINT16	y_g4;
	UINT16	y_g5;
	UINT16	y_g6;
} CHIP_MKIII_T;

typedef struct {
	BOOLEAN	i_dcti_enable;
	BOOLEAN	i_dcti_uv_sync_enable;
	BOOLEAN	i_dcti_uv_align_enable;
	UINT8	i_dcti_mode;
	UINT8	i_dcti_gain;
	UINT8	i_dcti_Max_search_range;
	UINT8	i_dcti_Threshold_of_smooth;
	BOOLEAN	d_dcti_enable;
	BOOLEAN	d_dcti_uv_sync_enable;
	BOOLEAN	d_dcti_uv_align_enable;
	UINT8	d_dcti_mode;
	UINT8	d_dcti_gain;
	UINT8	d_dcti_Max_search_range;
	UINT8	d_dcti_Threshold_of_smooth;
	BOOLEAN	vcti_enable;
	UINT8	vcti_type;
	UINT8	vcti_gain;
	UINT8	vcti_type3_thd;
} CHIP_CTI_T;

typedef struct {
	BOOLEAN d_LTI_enable;
	UINT8 d_LTI_can_shift;
	UINT8 d_LTI_maxlen;
	UINT16 d_LTI_pnth;
	BOOLEAN	tn_blend_Enable;
	BOOLEAN	ffd2_Enable;
	UINT8	Data_sel;
	BOOLEAN	tn_blend_mode;
	UINT8	D1_CP_Shift;
	UINT8	DCP_th;
	UINT8	Flat_s_range;
	UINT8	Flat_score_th1;
	UINT16	Ffd1_th;
	UINT8	Ffd1_ratio;
	UINT16	Ffd2_range2R;
	UINT16	Ffd2_range2L;
	UINT8	Ffd2_ratio;
	UINT16	gain_pos;
	UINT16	offset_pos;
	UINT16	gain_neg;
	UINT16	offset_neg;
	UINT8	Tnoff0;
	UINT8	Tnoff1;
	UINT8	Tnoff2;
	UINT8	Tnoff3;
	UINT8	Tnoff4;
	UINT8	Tnoff5;
	UINT8	Tnoff6;
	UINT8	Tnoff7;
	UINT8	Tnoff8;
	UINT8	Tnoff9;
	UINT8	Tnoff10;
	UINT8	Tnoff11;
	UINT8	Tnoff12;
	UINT8	Tnoff13;
	UINT8	Tnoff14;
}CHIP_HLTI_T;

typedef struct{
	BOOLEAN d_LTI_enable;
	UINT8	Can_shift_v;
	UINT8	maxlen_v;
	UINT16	pnth_v;
	UINT16	ffd1_th_v;
	UINT8	ffd1_ratio_v;
	UINT16	gain_pos_v;
	UINT16	offset_pos_v;
	UINT16	gain_neg_v;
	UINT16	offset_neg_v;
	UINT8	Tnoff0_v;
	UINT8	Tnoff1_v;
	UINT8	Tnoff2_v;
	UINT8	Tnoff3_v;
	UINT8	Tnoff4_v;
	UINT8	Tnoff5_v;
	UINT8	Tnoff6_v;
}CHIP_VLTI_T;

typedef struct{
	BOOLEAN ise_en;
	UINT8	ise_step;
	UINT8	ise_scale;
	UINT8	ise_ub;
	UINT8	ise_h_st;
	UINT8	ise_h_end;
	BOOLEAN ise_v_st;
	UINT8	ise_v_end;
}CHIP_ISE_T;

typedef struct{
	BOOLEAN tex_flat_filter_en;
	UINT8	coef_c0_2;
	UINT8	coef_c0_1;
	UINT16	coef_c0_0;
	UINT8	coef_c1_0;
	UINT8	coef_c2_0;
	UINT8	coef_c3_0;
}CHIP_FLAT_FILTER_T;

typedef struct{
	BOOLEAN Maxmin_Limit_En;
	UINT8	Maxmin_Shift;
	UINT8	sr_var_thd;
	BOOLEAN Maxmin_Mode;
	BOOLEAN Maxmin_Range;
	UINT8	Maxmin_Thd;
	BOOLEAN Edge_Range;
	UINT8	Delta_Gain;
	BOOLEAN LPF_Range;
	BOOLEAN lpf_range_en;
	UINT8	lpf_range_thd;
	UINT8	lpf_range_gain;
	UINT8	lpf_range_step;
	UINT8	lpf_gain;
	BOOLEAN lpf_edge_en;
	UINT8	lpf_edge_thd;
	UINT8	lpf_edge_gain;
	UINT8	lpf_edge_step;
	BOOLEAN bif_range_en;
	UINT8	bif_thd0;
	UINT8	bif_thd1;
	UINT8	bif_thd2;
	UINT8	bif_thd3;
	UINT8	bif_thd4;
	UINT8	bif_thd5;
	UINT8	bif_thd6;
	UINT8	bif_thd7;
	UINT8	bif_range_thd0;
	UINT8	bif_range_thd1;
	UINT8	bif_range_gain0;
	UINT8	bif_range_gain1;
	UINT8	bif_range_step0;
	UINT8	bif_range_step1;
	UINT8	bif_gain;
	BOOLEAN bif_edge_en;
	UINT8	bif_edge_thd;
	UINT8	bif_edge_gain;
	UINT8	bif_edge_step;
	BOOLEAN by_gain_en;
	BOOLEAN diffdir_cond_e;
	UINT8	pgain0;
	UINT8	pgain1;
	UINT8	pgain2;
	UINT8	pgain3;
	UINT8	pgain4;
	UINT8	pgain5;
	UINT8	pgain6;
	UINT8	pgain7;
	UINT8	pgain8;
	UINT8	ngain0;
	UINT8	ngain1;
	UINT8	ngain2;
	UINT8	ngain3;
	UINT8	ngain4;
	UINT8	ngain5;
	UINT8	ngain6;
	UINT8	ngain7;
	UINT8	ngain8;
}CHIP_SECOND_SR_T;



typedef struct {
	BOOLEAN mb_peaking_en;
	UINT16 h_c0;
	SINT16 h_c1;
	SINT8 h_c2;
	SINT8 h_c3;
	SINT8 h_c4;
	SINT8 h_c5;
	SINT8 h_c6;
	UINT16 v_c0;
	SINT16 v_c1;
	SINT8 v_c2;
} CHIP_MULTIBAND_PEAKING_HPF_T;

typedef struct {
	BOOLEAN mb_h_en;
	UINT8 H_Gain_Pos;
	UINT8 H_Gain_Neg;
	UINT8 H_Coring;
	UINT8 H_Gain_Pos2;
	UINT8 H_Gain_Neg2;
	UINT16 H_Range_Pos;
	UINT16 H_Range_Neg;
	UINT8 H_Edge_Shift;
	BOOLEAN mb_v_en;
	UINT8 V_Gain_Pos;
	UINT8 V_Gain_Neg;
	UINT8 V_Coring;
	UINT8 V_Gain_Pos2;
	UINT8 V_Gain_Neg2;
	UINT16 V_Range_Pos;
	UINT16 V_Range_Neg;
	UINT8 V_Edge_Shift;
} CHIP_MULTIBAND_PEAKING_UI_T;

typedef struct {
	CHIP_SEGMENTATION_T		stSegmentation;
	CHIP_EDGE_CORING_MODE_T	stEdgeCoringMode;
	CHIP_Y_REMAPPING_T		stYRemapping;
	CHIP_EDGE_HPF_T			stEdgeHPF;
	CHIP_EDGE_CURVEMAPPING_STEP_T	stEdgeCurveMappingStep;
	CHIP_EDGE_CURVEMAPPING_UI_T		stEdgeCurveMappingUI;
	CHIP_TEXTURE_HPF_T				stTextureHPF;
	CHIP_TEXTURE_CURVEMAPPING_STEP_T	stTextureCurveMappingStep;
	CHIP_TEXTURE_CURVEMAPPING_UI_T		stTextureCurveMappingUI;
	CHIP_COMMON_HPF_T	stCommonHPF;
	CHIP_SLOPE_GAIN_MASK_T	stSlopeGainMask;
	CHIP_VERTICAL_HPF_T		stVerticalHPF;
	CHIP_VERTICAL_CURVEMAPPING_STEP_T	stVerticalCurveMappingStep;
	CHIP_VERTICAL_CURVEMAPPING_UI_T		stVerticalCurveMappingUI;
	CHIP_VERTICAL_SLOPE_GAIN_MASK_T	stVerticalSlopeGainMask;
	CHIP_MKIII_T	stMKIII;
	CHIP_CTI_T		stCTI;
	CHIP_HLTI_T	stHLTI;
	CHIP_VLTI_T	stVLTI;
	CHIP_MULTIBAND_PEAKING_HPF_T	stMultibandPeakingHPF;
	CHIP_MULTIBAND_PEAKING_UI_T	stMultibandPeakingUI;
	CHIP_ISE_T	stIse;
	CHIP_FLAT_FILTER_T	stFlatfilter;
	CHIP_SECOND_SR_T	stSecondSr;
} CHIP_SHARPNESS_T;

typedef struct{
	SINT16	ring_h_c0;
	SINT8	ring_h_c1;
	SINT8	ring_h_c2;
	SINT8	ring_h_c3;
	SINT8	ring_h_c4;
	SINT8	ring_h_c5;
	SINT16	ring_v_c0;
	SINT8	ring_v_c1;
	SINT8	ring_v_c2;
	SINT8	ring_v_c3;
	SINT8	ring_v_c4;
	UINT8	edge_filter_sel;
	UINT8	tex_filter_sel;
	UINT8	Ring_Gen_Gain;
	UINT8	Cur_Period;
	UINT16	Cur_Gain;
	UINT16	Cur_Offset;
	UINT8	Ring_Gen_Type;
	UINT8	Filter_Type;
}CHIP_SR_UI_T;

typedef struct {
	BOOLEAN	emf_enable;
	UINT8	emf_range;
	UINT8	emf_shiftbit;
	UINT8	blend_wt;
	UINT8	fix_extend_pos;
	UINT8	fix_extend_neg;
	UINT16	seg0_x;
	UINT16	seg1_x;
	UINT8	gain0;
	UINT8	gain1;
	UINT8	gain2;
	UINT16	Offset0;
} CHIP_EDGE_EMF_UI_T;

typedef struct {
	BOOLEAN	emf_enable;
	UINT8	emf_range;
	UINT8	emf_shiftbit;
	UINT8	blend_wt;
	UINT8	fix_extend_pos;
	UINT8	fix_extend_neg;
	UINT16	seg0_x;
	UINT16	seg1_x;
	UINT8	gain0;
	UINT8	gain1;
	UINT8	gain2;
	UINT16	Offset0;
} CHIP_TEXTURE_EMF_UI_T;

typedef struct {
	BOOLEAN	vemf_en;
	UINT8	vext_reg;
} CHIP_VERTICAL_EMF_UI_T;

typedef struct {
	CHIP_EDGE_EMF_UI_T	stEdgeEMF;
	CHIP_TEXTURE_EMF_UI_T	stTextureEMF;
	CHIP_VERTICAL_EMF_UI_T	stVerticalEMF;
} CHIP_EDGE_ENHANCE_T;

typedef struct {
	CHIP_SHARPNESS_T		stSharpness;
} CHIP_SHARPNESS_UI_T;

typedef struct {
	CHIP_EDGE_ENHANCE_T		stEdgeEnhance;
} CHIP_EDGE_ENHANCE_UI_T;

typedef struct {
	UINT16 SR_LEVEL;
	CHIP_SR_UI_T sr_ui;
} RTK_SR_UI_T;

typedef struct {
	unsigned char Sharpness_OSD_bottom;
	unsigned char Sharpness_OSD_mid;
	unsigned char Sharpness_OSD_top;
	unsigned char Sharpness_ChipValue_bottom;
	unsigned char Sharpness_ChipValue_mid;
	unsigned char Sharpness_ChipValue_top;
} Sharpness_OSD_Remap_Curve;

typedef union
{
    UINT32 Value;
    struct{
        UINT32  tnoff0:4;
        UINT32  tngain0:5;
        UINT32  tnoff1:4;
        UINT32  tngain1:5;
        UINT32  tnoff2:4;
        UINT32  tngain2:5;
        UINT32  res1:5;
    };
}VIP_SHP_LTI_GainOffset;


/*typedef struct{
	CHIP_HLTI_T h_lti;
	CHIP_VLTI_T v_lti;

}CHIP_LTI_T;*/




/*=========ICM start=========*/
#define	CHIP_CM_TBLPOINT	8

typedef enum {
	CHIP_CM_COLOR_REGION_RED,
	CHIP_CM_COLOR_REGION_GRN,
	CHIP_CM_COLOR_REGION_BLU,
	CHIP_CM_COLOR_REGION_CYN,
	CHIP_CM_COLOR_REGION_MGT,
	CHIP_CM_COLOR_REGION_YLW,
	CHIP_CM_COLOR_REGION_SKIN,
	CHIP_CM_COLOR_REGION_RESERVED1,
	CHIP_CM_COLOR_REGION_RESERVED2,
	CHIP_CM_COLOR_REGION_MAX
} CHIP_CM_COLOR_REGION_T;

typedef struct{
	bool		enable;
	CHIP_CM_COLOR_REGION_T	regionNum;
	UINT16		hue_x[CHIP_CM_TBLPOINT];
	UINT16		hue_g[CHIP_CM_TBLPOINT];
	UINT16		sat_x[CHIP_CM_TBLPOINT];
	UINT16		sat_g[CHIP_CM_TBLPOINT];
	UINT16		Int_x[CHIP_CM_TBLPOINT];
	UINT16		Int_g[CHIP_CM_TBLPOINT];
}CHIP_COLOR_REGION_T;

typedef struct{
	CHIP_COLOR_REGION_T		stColorRegion[CHIP_CM_COLOR_REGION_MAX];
	BOOLEAN keepY;
}CHIP_COLOR_REGION_TYPE_T;

typedef struct {
	CHIP_COLOR_REGION_TYPE_T	stColorRegionType;
} CHIP_CM_REGION_T;

typedef struct {
	UINT8	stColorGainHue;
	UINT8	stColorGainSat;
	UINT8	stColorGainInt;
} CHIP_COLOR_LEVEL_GAIN_T;

typedef struct {
	UINT16	masterGain;
	CHIP_COLOR_LEVEL_GAIN_T	stColorGain;
} CHIP_COLOR_GAIN_T;

typedef struct {
	CHIP_COLOR_GAIN_T		stColor[CHIP_CM_COLOR_REGION_MAX];
} CHIP_COLOR_CONTROL_T;

typedef struct {
	CHIP_COLOR_REGION_TYPE_T	stRgn;
	CHIP_COLOR_CONTROL_T		stCtrl;
} CHIP_COLOR_ICM_GAIN_ADJUST_T;

typedef struct {
	UINT16 rgn_idx[62];
	UINT8 rgn_pillar[62];
	UINT16 rgn_gain[62];
	UINT8 pillar_num;
} CM_HUE_SECTION;

typedef struct {
	UINT16 rgn_idx[12];
	UINT8 rgn_pillar[12];
	UINT16 rgn_gain[12];
	UINT8 pillar_num;
} CM_SAT_SECTION;

typedef struct {
	UINT16 rgn_idx[9];
	UINT8 rgn_pillar[9];
	UINT16 rgn_gain[9];
	UINT8 pillar_num;
} CM_ITN_SECTION;

typedef enum {
	COLOR_MODE_NONE = 0,
	COLOR_MODE_ADV,
	COLOR_MODE_EXP
} COLOR_MODE;

typedef struct
{
	SINT8 sCmRegion;// 0~16
	SINT8 sSatGainValue;// -30~30
	SINT8 sHueGainValue;// -30~30
	SINT8 sLuminanceValue;// -30~30
	SINT8 sFreshColorValue;// 0~3:off,low,med,high
} ICM_CM_PARAM_T;

typedef struct
{
	SINT8 sCmPreferred;// 0:skin,1:blus sky,2:grass
	SINT8 sPreferredColorValue;// -5~5
	SINT8 sFreshColorValue;// 0~3:off,low,med,high
} ICM_PC_PARAM_T;

typedef struct {
	unsigned char ctrl[4];
	CHIP_CM_REGION_T cm_rgn;
} CHIP_CM_REGION_EXT_T;

typedef struct {
	unsigned char ctrl[4];
	ICM_PC_PARAM_T ui_param;
	CHIP_COLOR_CONTROL_T cm_ctrl;
} CHIP_COLOR_CONTROL_ADV_EXT_T;

typedef struct {
	unsigned char ctrl[4];
	ICM_CM_PARAM_T ui_param;
	CHIP_COLOR_CONTROL_T cm_ctrl;
} CHIP_COLOR_CONTROL_EXP_EXT_T;

typedef struct {
	unsigned char ctrl[4];
	UINT32 uFcVal;
	CHIP_COLOR_CONTROL_T cm_ctrl;
} CHIP_COLOR_CONTROL_FRESH_T;
/*=========ICM end==========*/

/*=========ICM for RTICE protocol start==========*/
typedef struct {
	UINT16	enable;
	UINT16	regionNum;
	UINT16	hue_x[CHIP_CM_TBLPOINT];
	UINT16	hue_g[CHIP_CM_TBLPOINT];
	UINT16	sat_x[CHIP_CM_TBLPOINT];
	UINT16	sat_g[CHIP_CM_TBLPOINT];
	UINT16	Int_x[CHIP_CM_TBLPOINT];
	UINT16	Int_g[CHIP_CM_TBLPOINT];
} CHIP_COLOR_REGION_RTICE_T;

typedef struct {
	CHIP_COLOR_REGION_RTICE_T	stColorRegion[CHIP_CM_COLOR_REGION_MAX];
} CHIP_COLOR_REGION_TYPE_RTICE_T;

typedef struct {
	UINT16	stColorGainHue;
	UINT16	stColorGainSat;
	UINT16	stColorGainInt;
} CHIP_COLOR_LEVEL_GAIN_RTICE_T;

typedef struct {
	UINT16 				masterGain;
	CHIP_COLOR_LEVEL_GAIN_RTICE_T	stColorGain;
} CHIP_COLOR_GAIN_RTICE_T;

typedef struct {
	CHIP_COLOR_GAIN_RTICE_T		stColor[CHIP_CM_COLOR_REGION_MAX];
} CHIP_COLOR_CONTROL_RTICE_T;

typedef struct {
	CHIP_COLOR_REGION_TYPE_RTICE_T	stRgn;
	CHIP_COLOR_CONTROL_RTICE_T	stCtrl;
} CHIP_COLOR_ICM_GAIN_ADJUST_RTICE_T;
/*=========ICM for RTICE protocol end==========*/

/*=========Gamut start==========*/
typedef enum {
	IDX_3DLUT_BYPASS, //idx 0
	IDX_3DLUT_BT2020_WCG, //idx 1
	IDX_3DLUT_BT2020_OLED, //idx 2
	IDX_3DLUT_BT2020_Sharp, //idx 3
	IDX_3DLUT_BT2020_NCG, //idx 4
	IDX_3DLUT_BT709_WCG_49, //idx 5
	IDX_3DLUT_BT709_WCG_55, //idx 6
	IDX_3DLUT_BT709_WCG_60, //idx 7
	IDX_3DLUT_BT709_WCG_65, //idx 8
	IDX_3DLUT_BT709_Sharp_70, //idx 9
	IDX_3DLUT_BIG_TABLE_MAX, //idx 10
	IDX_3DLUT_EXT_TABLE_START = IDX_3DLUT_BIG_TABLE_MAX, //idx 10
	IDX_3DLUT_55B6 = IDX_3DLUT_EXT_TABLE_START, //idx 10
	IDX_3DLUT_65B6, //idx 11
	IDX_3DLUT_43UH61, //idx 12
	IDX_3DLUT_49UH61, //idx 13
	IDX_3DLUT_55UH61, //idx 14
	IDX_3DLUT_65UH61, //idx 15
	IDX_3DLUT_INX50, //idx 16
	IDX_3DLUT_INX65, //idx 17
	IDX_3DLUT_BOE49, //idx 18
	IDX_3DLUT_BOE55, //idx 19
	IDX_3DLUT_60UH61, //idx 20
	IDX_3DLUT_55UH765, //idx 21
	IDX_3DLUT_60UH765, //idx 22
	IDX_3DLUT_65UH765, //idx 23
	IDX_3DLUT_43_PHT, //idx 24
	IDX_3DLUT_49_PHT, //idx 25
	IDX_3DLUT_MAX,
} GAMUT_3D_LUT_IDX;

#define LUT3D_EXTEND_TBL_Num   (IDX_3DLUT_MAX-IDX_3DLUT_EXT_TABLE_START)

typedef struct {
	unsigned short r_data;
	unsigned short g_data;
	unsigned short b_data;
} GAMUT_3D_LUT_PT_T;

typedef struct {
	unsigned char index;
	GAMUT_3D_LUT_PT_T pt[9][9][9];
} GAMUT_3D_LUT_9x9x9_T;

typedef struct {
	unsigned char index;
	GAMUT_3D_LUT_PT_T pt[4913];
} GAMUT_3D_LUT_17x17x17_T;

typedef struct {
	UINT32 		invgamma_enable;	// inverse gamma & gamma enable,  0: disable, 1: enable
	SINT16		gamutmatrix_00;		// 3x3 matrix
	SINT16		gamutmatrix_01;
	SINT16		gamutmatrix_02;
	SINT16		gamutmatrix_10;
	SINT16		gamutmatrix_11;
	SINT16		gamutmatrix_12;
	SINT16		gamutmatrix_20;
	SINT16		gamutmatrix_21;
	SINT16		gamutmatrix_22;
	BOOLEAN 	b3DLUT_enable;		// 3D LUT,  0: disable, 1: enable
	UINT8		u3DLUT_index;		// 3D LUT table index number
	BOOLEAN 	b3DLUT_internalselect;
} CHIP_COLOR_GAMUT_MAPPING_IO_T;
/*=========Gamut end==========*/

typedef enum {
	STOP_VPQ_IOC_START = 0,
	STOP_VPQ_IOC_SET_FreshContrast = STOP_VPQ_IOC_START,
	STOP_VPQ_IOC_SET_FreshContrastLUT,
	STOP_VPQ_IOC_SET_SAT_LUT,
	STOP_VPQ_LED_LDGetAPL,
	STOP_VPQ_IOC_MAX,
} VPQ_IOCTL_STOP_RUN;

typedef enum {
	VPQ_GAMMA_MODE_INV_OFF_INNER_BYPASS = 0,
	VPQ_GAMMA_MODE_INV_OFF_INNER_ON,
	VPQ_GAMMA_MODE_INV_ON_INNER_BYPASS,
	VPQ_GAMMA_MODE_INV_ON_INNER_ON,
} VPQ_COLOR_GAMMA_MODE;

typedef struct
{
	int wId;
	int uCgVal;
} RTK_COLOR_GAIN_T;

typedef enum
{
	DISP_HIGH_LUM1_MSE_ON = 0,
	DISP_HIGH_LUM2,
	DISP_LOW_POWER1,
	DISP_MLE_MODE_OFF,
	DISP_HIGH_LUM1_MSE_OFF,
	DISP_LOW_POWER2,
	DISP_LOW_POWER2_SC_OFF,
	DISP_MLE_MODE_MAX,
} DISP_MLE_MODE_T;

typedef enum {
 HAL_VPQ_HDR_MODE_SDR,
 HAL_VPQ_HDR_MODE_DOLBY,
 HAL_VPQ_HDR_MODE_HDR10,
 HAL_VPQ_HDR_MODE_HLG,
 HAL_VPQ_HDR_MODE_TECHNICOLOR,
 HAL_VPQ_HDR_MODE_HDREFFECT,
 HAL_VPQ_HDR_MODE_MAX
}HAL_VPQ_HDR_MODE_T;

typedef enum {
 HAL_VPQ_COLORIMETRY_BT601 = 0,
 HAL_VPQ_COLORIMETRY_BT709,
 HAL_VPQ_COLORIMETRY_BT2020,
 HAL_VPQ_COLORIMETRY_MAX
}HAL_VPQ_COLORIMETRY_T;


typedef struct{
	UINT8	M_LC_Comp_En;	//Master enable
	UINT8	LC_Tone_Mapping_En;	//Tone Mapping enable
	UINT8	LC_tmap_slope_unit;	//slope (0, 1)
	UINT8	LC_tmap_blend_factor;	//blend (0~255)
	UINT8	LC_tmap_curve_Grid[8];	// Grid setting
	UINT16	LC_tmap_curve_tone[8];	// Tone setting
	UINT16	LC_ToneMappingSlopePont_Table[256];	// Tone Mapping curve data (8 curves)
} CHIP_LOCAL_CONTRAST_T;

void fwif_color_set_rgb2yuv_black_level_tv006(RGB2YUV_BLACK_LEVEL lv);
RGB2YUV_BLACK_LEVEL fwif_color_get_rgb2yuv_black_level_tv006(void);
unsigned char fwif_color_get_colorspacergb2yuvtransfer_table_tv006(unsigned char channel, unsigned char nSrcType, unsigned char nSD_HD, bool bUse_HDMI_Range_Detect);

void fwif_color_set_ICM_table_driver_init_tv006(void);
void fwif_color_set_ICM_table_driver_init_elem_tv006(COLORELEM_TAB_T *pIcm_tab_elem);
void fwif_color_set_ICM_table_driver_tv006(COLORELEM_TAB_T *pIcm_tab_elem, unsigned char waiting);
unsigned char fwif_color_calc_ICM_gain_table_driver_tv006(CHIP_COLOR_REGION_TYPE_T *crRgn_in, CHIP_COLOR_CONTROL_T *crCtrl_in, COLORELEM_TAB_T *icmTab_in, COLORELEM_TAB_T *icmTab_out);
unsigned char fwif_color_set_YUV2RGB_UV_Offset_tv006(unsigned char display, unsigned char enable, unsigned char mode, DRV_VIP_YUV2RGB_UV_Offset *pUVOffset);

unsigned char fwif_color_get_Decide_YUV2RGB_TBL_Index_tv006(unsigned char src_idx, unsigned char display, unsigned char Input_Data_Mode);
int fwif_color_set_Picture_Control_tv006(unsigned char display, VPQ_SetPicCtrl_T *p_setPicCtrl);
int fwif_color_setCon_Bri_Color_Tint_tv006(unsigned char display, _system_setting_info *system_info_struct);
/*unsigned char fwif_OsdMapToRegValue_tv006(APP_Video_OsdItemType_t bOsdItem, VPQ_SetPicCtrl_T *p_setPicCtrl);*/
void fwif_color_CalContrast_Compensation_tv006(unsigned char display, unsigned char Contrast_Gain, _system_setting_info *system_info_struct);
int fwif_color_CalCon_Bri_Color_Tint_Gain_tv006(unsigned char display, VPQ_SetPicCtrl_T *p_setPicCtrl, _system_setting_info *system_info_struct);
void fwif_color_set_YUV2RGB_tv006(unsigned char src_idx, unsigned char display, unsigned char which_table, unsigned char drvSkip_Flag_coefByY, unsigned char drvSkip_Flag_uvOffset);
char fwif_color_set_DSE_tv006(unsigned char display, VPQ_SAT_LUT_T *satLUT);
int fwif_color_update_YUV2RGB_CSC_tv006(unsigned char display);
#if 0 /* no more use because may confuse when code sync YUV2RGB matrix*/
char fwif_color_set_SaturationLUT_tv006(unsigned char display, VPQ_SAT_LUT_T *satLUT);
char fwif_color_get_SaturationLUT_tv006(unsigned char display, VPQ_SAT_LUT_T *satLUT);
#endif /* no more use because may confuse when code sync YUV2RGB matrix*/
char fwif_color_access_SaturationLUT_tv006(unsigned char display, VPQ_SAT_LUT_T *satLUT, ACCESS_MODE mode);
char fwif_color_access_Total_Sat_Gain_tv006(unsigned char display, VPQ_SAT_LUT_T *satLUT, ACCESS_MODE mode);
char fwif_color_access_Sat_Gain_tv006(unsigned char display, VPQ_SAT_LUT_T *satLUT, ACCESS_MODE mode);
char fwif_color_access_apl_color_gain_tv006(unsigned char display, int* pAplColorGain, ACCESS_MODE mode);

void fwif_color_Set_NR_Table_tv006(CHIP_NOISE_REDUCTION_T *ptr);
CHIP_NOISE_REDUCTION_T *fwif_color_Get_NR_Table_tv006(void);
unsigned char fwif_color_GetDNR_tv006(void);
void fwif_color_SetDNR_tv006(unsigned char level);
void fwif_color_Set_NR_Input_tv006(unsigned char input);
unsigned char fwif_color_get_NR_Input_tv006(void);
void fwif_color_set_PQA_motion_threshold_TV006(void);
void fwif_color_set_LocalContrast_table_TV006(CHIP_LOCAL_CONTRAST_T *param);
void fwif_color_set_LocalContrast_ToneMappingXY_SlopePoint_TV006(CHIP_LOCAL_CONTRAST_T *param);

void fwif_color_Set_MPEGNR_Table_tv006(CHIP_MPEG_NOISE_REDUCTION_T *ptr);
CHIP_MPEG_NOISE_REDUCTION_T *fwif_color_Get_MPEGNR_Table_tv006(void);
unsigned char fwif_color_MPEGDNR_tv006(void);
void fwif_color_Set_MPEGNR_tv006(unsigned char level);
void fwif_color_Set_MNR_Enable_Check_tv006(void);

void fwif_color_set_sharpness_table_TV006(CHIP_SHARPNESS_UI_T *tCHIP_SHARPNESS_UI_T, CHIP_EDGE_ENHANCE_UI_T *tCHIP_EDGE_ENHANCE_UI_T, CHIP_SR_UI_T *ptCHIP_SR_UI_T);
void fwif_color_set_sharpness_table_init_TV006(unsigned char src_idx, unsigned char value);
unsigned char fwif_TwoParts_Linear_Interpolation(Sharpness_OSD_Remap_Curve *ptr, unsigned char value);
void fwif_color_set_SharpnessFilterCoef_for_3D(CHIP_SHARPNESS_UI_T *CHIPShpTable, CHIP_SHARPNESS_UI_T *CHIPShpTable3DCorrection);
unsigned char  fwif_color_set_dcc_Curve_Write_tv006(signed int *sAccLUT);
unsigned char fwif_color_set_dcc_FreshContrast_tv006(CHIP_DCC_T *ptr);
unsigned char  fwif_color_set_bypass_dcc_Curve_Write_tv006(void);
void fwif_color_set_iDcti_dDcti_tv006(unsigned char i_dcti_val, unsigned char d_dcti_val, CHIP_CTI_T *set_cti_db);
void fwif_color_set_Vdcti_tv006(unsigned char v_dcti_val, CHIP_CTI_T *set_cti_db);
void fwif_color_set_dLti_tv006(unsigned char d_lti_val, CHIP_HLTI_T *H_LTI_db, CHIP_VLTI_T *V_LTI_db);

void fwif_color_set_MultiBand_Peaking_tv006(unsigned char multiBand_val, CHIP_MULTIBAND_PEAKING_HPF_T *mb_hpf, CHIP_MULTIBAND_PEAKING_UI_T* mb_UI);

void fwif_color_set_inv_gamma_encode_tv006(void);
void fwif_color_set_cds_table_tv006(unsigned char table_idx);
void fwif_color_set_DCC_Init_tv006(void);
/*unsigned char fwif_color_set_Gamut_3D_Lut_N9_to_N17_tv006(GAMUT_3D_LUT_9x9x9_T *pLut);*/
unsigned char fwif_color_set_Gamut_3D_Lut_buffer_tv006(GAMUT_3D_LUT_17x17x17_T *pLut);
unsigned char fwif_color_set_Gamut_3D_Lut_ext_buffer_tv006(GAMUT_3D_LUT_17x17x17_T *pLut);
void fwif_color_set_color_temp_tv006(unsigned char enable, unsigned short Red_Con, unsigned short Green_Con, unsigned short Blue_Con,
	short Red_Bri, short Green_Bri, short Blue_Bri, unsigned char waitSync);

char fwif_color_set_bt2020_Handler_tv006(unsigned char display, unsigned char Enable_Flag, unsigned char bt2020_Mode);
unsigned char fwif_color_vpq_stop_ioctl(VPQ_IOCTL_STOP_RUN id, ACCESS_MODE mode, unsigned char isStop);

unsigned char fwif_color_get_LD_GetAPL_TV006(UINT16* BLValue);
void fwif_color_SetDataFormatHandler_tv006(void);
#ifdef CONFIG_HDR_SDR_SEAMLESS
void fwif_color_SetDataFormatHandler_tv006_Seamless(unsigned char HDR_Mode);
#endif
void fwif_color_3d_lut_init_tv006(void);
unsigned char fwif_color_3d_lut_access_index(ACCESS_MODE access, unsigned char setIdx);

void fwif_color_set_cinema_mode_en(unsigned char bEn);
unsigned char fwif_color_get_cinema_mode_en(void);
int fwif_color_set_dcc_force_write_flag_RPC(unsigned sendRPC, unsigned int force_write);
void fwif_color_od_table_tv006_convert(unsigned char *pTableIn, unsigned int *pTableOut);
void fwif_color_od_table_tv006_transform(bool transType, unsigned int *pTableIn, unsigned int *pTableOut);
void fwif_color_od_table_17x17_transform(bool transType, unsigned char *pTableIn, unsigned int *pTableOut);
void fwif_color_od_table_restore(void);
void fwif_color_set_out_gamma_encode_tv006(void);
void fwif_color_set_Mplus_ModeChange_TV006(DISP_MLE_MODE_T mode_sel);
void fwif_color_set_DM2_EOTF_TV006(UINT32* EOTF_table32);
void fwif_color_set_DM2_OETF_TV006(UINT16* OETF_table16);
UINT8 fwif_color_get_DM2_HDR_histogram_TV006(UINT32* HDR_info);
UINT8 fwif_color_get_DM_HDR10_enable_TV006(void);
void hdr_resume(void);
void fwif_color_set_HDR_TV006(void);
char fwif_color_set_DM_HDR_3dLUT_24x24x24_16_TV006(void *p);


void fwif_color_set_LD_Backlight_Decision_Replace_TV006(KADP_LED_BACKLIGHT_DECISION *LED_DB_LUT_BACKLIGHT_DECISION, DRV_LD_Backlight_Decision *LD_Backlight_Decision);
void fwif_color_set_LD_Spatial_Filter_Replace_TV006(KADP_LED_SPATIAL_FILTER *LED_DB_LUT_SPATIAL_FILTER, DRV_LD_Spatial_Filter *LD_Spatial_Filter);
void fwif_color_set_LD_Temporal_Filter_Replace_TV006(KADP_LED_TEMPORAL_FILTER *LED_DB_LUT_TEMPORAL_FILTER, DRV_LD_Temporal_Filter *LD_Temporal_Filter);
void fwif_color_set_LD_Spatial_Remap_Replace_TV006(KADP_LED_REMAP_CURVE *LED_DB_LUT_REMAP_CURVE, DRV_LD_Spatial_Remap *LD_Spatial_Remap);
void fwif_color_set_LD_Data_Compensation_NewMode_2DTable_Replace_TV006(KADP_LED_DATA_COMP *LED_DB_LUT_DATA_COMP, DRV_LD_Data_Compensation_NewMode_2DTable *LD_Data_Compensation_NewMode_2DTable);
void fwif_color_set_LDSetDBLUT_TV006(KADP_LED_DB_LUT_T *LED_DB_LUT);
void fwif_color_set_output_gamma_4CHDGA_TV006 (UINT32 *pRedGammaTable, UINT32 * pGreenGammaTable, UINT32 * pBlueGammaTable, UINT32 * pWhiteGammaTable, UINT16 nTableSize);
#if 0	/* juwen, move to "tc_hdr", elieli */
void fwif_color_TC_Enable(UINT8 En);
#endif
void fwif_color_set_SetBOERGBWBypass_TV006(unsigned char BOE_EN);


void fwif_color_SetFrameGainLimit_TV006(unsigned short nFrameGainLimit);
void fwif_color_GetFrameGainLimit_TV006(unsigned short *nFrameGainLimit);
void fwif_color_SetPixelGainLimit_TV006(unsigned short nPixelGainLimit);
void fwif_color_GetPixelGainLimit_TV006(unsigned short *nPixelGainLimit);



#ifdef __cplusplus
}
#endif

#endif /* __SCALER_COLOR_TV006_H__*/


