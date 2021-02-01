/* 20140523 Local Contrast header file*/
#ifndef  __LOCALCONTRAST_H__
#define  __LOCALCONTRAST_H__

#ifdef __cplusplus
extern "C" {
#endif
/* some include about scaler*/
#if CONFIG_FIRMWARE_IN_KERNEL
#include <scalercommon/vipCommon.h>
#include <scalercommon/vipRPCCommon.h>
#else
#include <scaler/vipCommon.h>
#endif
/*
#define LC_BL_Profile_Table_NUM 6
#define LC_BL_Profile_Table_ROW 4
#define LC_BL_Profile_Table_COLUMN 20
#define LC_Table_NUM 10
//juwen, add LC : tone mapping curve
#define LC_Curve_ToneM_PointSlope 256
#define LC_Table_ToneM_NUM 10
*/
/*
typedef struct {
	unsigned char lc_local_sharp_en;
	unsigned char lc_tone_mapping_en;
	unsigned char lc_db_en;
	unsigned char lc_db_apply;
	unsigned char lc_db_read_level;
	unsigned char lc_3d_mode;
	//unsigned char lc_blk_hnum;//juwen, 1028, set blk num/size and factor
	//unsigned char lc_blk_vnum;//juwen, 1028, set blk num/size and factor
	unsigned char lc_subblk_mode;
	unsigned char lc_gcon_mode;
	unsigned char lc_hist_mode;
	unsigned char lc_tenable;
	unsigned char lc_valid;
	//unsigned short lc_blk_hsize;//juwen, 1028, set blk num/size and factor
	//unsigned short lc_blk_vsize;//juwen, 1028, set blk num/size and factor

} DRV_LC_Global_Ctrl;


typedef struct {
	unsigned char lc_maxgain;
	unsigned char lc_avegain;
	unsigned char lc_histshiftbit;
	unsigned char lc_hist0gain;
	unsigned char lc_hist1gain;
	unsigned char lc_hist2gain;
	unsigned char lc_hist3gain;
	unsigned char lc_hist4gain;
	unsigned char lc_hist5gain;
	unsigned char lc_hist6gain;
	unsigned char lc_hist7gain;

} DRV_LC_Backlight_Decision;



typedef struct {
	unsigned char lc_spatialcoef0;
	unsigned char lc_spatialcoef1;
	unsigned char lc_spatialcoef2;
	unsigned char lc_spatialcoef3;
	unsigned char lc_spatialcoef4;
	unsigned char lc_spatialcoef5;
	unsigned char lc_spatialcoef6;
	unsigned char lc_spatialcoef7;
	unsigned char lc_spatialcoef8;
	unsigned char lc_spatialcoef9;
	unsigned char lc_spatialcoef10;
	unsigned char lc_spatialremapen;

} DRV_LC_Spatial_Filter;


typedef struct {

	unsigned char lc_tmp_pos0thd;
	unsigned char lc_tmp_pos1thd;
	unsigned char lc_tmp_posmingain;
	unsigned char lc_tmp_posmaxgain;
	unsigned char lc_tmp_neg0thd;
	unsigned char lc_tmp_neg1thd;
	unsigned char lc_tmp_negmingain;
	unsigned char lc_tmp_negmaxgain;
	unsigned char lc_tmp_maxdiff;
	unsigned char lc_tmp_scenechangegain1;

} DRV_LC_Temporal_Filter;


typedef struct {
	unsigned char lc_tab_hsize;
	//unsigned int lc_hfactor;//juwen, 1028, set blk num/size and factor
	unsigned char lc_hinitphase3_right;
	unsigned char lc_hboundary;
	unsigned char lc_hinitphase1;
	unsigned char lc_hinitphase2;
	unsigned char lc_hinitphase3_left;
	unsigned char lc_tab_vsize;
	//unsigned int lc_vfactor;//juwen, 1028, set blk num/size and factor
	unsigned char lc_vinitphase3_right;
	unsigned char lc_vboundary;
	unsigned char lc_vinitphase1;
	unsigned char lc_vinitphase2;
	unsigned char lc_vinitphase3_left;
	unsigned char lc_blight_update_en;
	unsigned char lc_blight_sw_mode;
	unsigned char lc_table_sw_mode;

} DRV_LC_Backlight_Profile_Interpolation;

typedef struct {
	unsigned char lc_demo_en;
	unsigned char lc_demo_mode;
	unsigned short lc_demo_top;
	unsigned short lc_demo_bottom;
	unsigned short lc_demo_left;
	unsigned short lc_demo_right;
} DRV_LC_Demo_Window;

typedef struct {
	unsigned short lc_tmap_g0_th1;
	unsigned short lc_tmap_g0_th2;
	unsigned short lc_tmap_g0_th3;
	unsigned short lc_tmap_g0_th4;
	unsigned short lc_tmap_g0_th5;
	unsigned short lc_tmap_g0_th6;
	unsigned short lc_tmap_g0_th7;
	unsigned short lc_tmap_g0_th8;
	unsigned short lc_tmap_g0_th9;
	unsigned short lc_tmap_g0_th10;
	unsigned short lc_tmap_g0_th11;
	unsigned short lc_tmap_g0_th12;
	unsigned short lc_tmap_g0_th13;
	unsigned short lc_tmap_g0_th14;
	unsigned short lc_tmap_g0_th15;
	unsigned short lc_tmap_g0_th16;
	unsigned short lc_tmap_g0_th17;
	unsigned short lc_tmap_g0_th18;
	unsigned short lc_tmap_g0_th19;
	unsigned short lc_tmap_g0_th20;
	unsigned short lc_tmap_g0_th21;
	unsigned short lc_tmap_g0_th22;
	unsigned short lc_tmap_g0_th23;
	unsigned short lc_tmap_g0_th24;
	unsigned short lc_tmap_g0_th25;
	unsigned short lc_tmap_g0_th26;
	unsigned short lc_tmap_g0_th27;
	unsigned short lc_tmap_g0_th28;
	unsigned short lc_tmap_g0_th29;
	unsigned short lc_tmap_g0_th30;
	unsigned short lc_tmap_g0_th31;
} DRV_LC_ToneMapping_Grid0;

typedef struct {
	unsigned short lc_tmap_g2_th1;
	unsigned short lc_tmap_g2_th2;
	unsigned short lc_tmap_g2_th3;
	unsigned short lc_tmap_g2_th4;
	unsigned short lc_tmap_g2_th5;
	unsigned short lc_tmap_g2_th6;
	unsigned short lc_tmap_g2_th7;
	unsigned short lc_tmap_g2_th8;
	unsigned short lc_tmap_g2_th9;
	unsigned short lc_tmap_g2_th10;
	unsigned short lc_tmap_g2_th11;
	unsigned short lc_tmap_g2_th12;
	unsigned short lc_tmap_g2_th13;
	unsigned short lc_tmap_g2_th14;
	unsigned short lc_tmap_g2_th15;
	unsigned short lc_tmap_g2_th16;
	unsigned short lc_tmap_g2_th17;
	unsigned short lc_tmap_g2_th18;
	unsigned short lc_tmap_g2_th19;
	unsigned short lc_tmap_g2_th20;
	unsigned short lc_tmap_g2_th21;
	unsigned short lc_tmap_g2_th22;
	unsigned short lc_tmap_g2_th23;
	unsigned short lc_tmap_g2_th24;
	unsigned short lc_tmap_g2_th25;
	unsigned short lc_tmap_g2_th26;
	unsigned short lc_tmap_g2_th27;
	unsigned short lc_tmap_g2_th28;
	unsigned short lc_tmap_g2_th29;
	unsigned short lc_tmap_g2_th30;
	unsigned short lc_tmap_g2_th31;

} DRV_LC_ToneMapping_Grid2;

typedef struct {
	unsigned char lc_tmap_curve0_grid;
	unsigned short lc_tmap_curve0_tone;
	unsigned char lc_tmap_curve1_grid;
	unsigned short lc_tmap_curve1_tone;
	unsigned char lc_tmap_curve2_grid;
	unsigned short lc_tmap_curve2_tone;
	unsigned char lc_tmap_curve3_grid;
	unsigned short lc_tmap_curve3_tone;
	unsigned char lc_tmap_curve4_grid;
	unsigned short lc_tmap_curve4_tone;
	unsigned char lc_tmap_curve5_grid;
	unsigned short lc_tmap_curve5_tone;
	unsigned char lc_tmap_curve6_grid;
	unsigned short lc_tmap_curve6_tone;
	unsigned char lc_tmap_curve7_grid;
	unsigned short lc_tmap_curve7_tone;

} DRV_LC_ToneMapping_CurveSelect;


typedef struct {
	unsigned char lc_tmap_slope_unit;
	unsigned char lc_tmap_blend_factor;
} DRV_LC_ToneMapping_Blend;

typedef struct {
	unsigned char lc_gain_by_yin_0;
	unsigned char lc_gain_by_yin_1;
	unsigned char lc_gain_by_yin_2;
	unsigned char lc_gain_by_yin_3;
	unsigned char lc_gain_by_yin_4;
	unsigned char lc_gain_by_yin_5;
	unsigned char lc_gain_by_yin_6;
	unsigned char lc_gain_by_yin_7;
	unsigned char lc_gain_by_yin_8;
	unsigned char lc_gain_by_yin_9;
	unsigned char lc_gain_by_yin_10;
	unsigned char lc_gain_by_yin_11;
	unsigned char lc_gain_by_yin_12;
	unsigned char lc_gain_by_yin_13;
	unsigned char lc_gain_by_yin_14;
	unsigned char lc_gain_by_yin_15;
	unsigned char lc_gain_by_yin_16;
	unsigned char lc_gain_by_yin_17;
	unsigned char lc_gain_by_yin_18;
	unsigned char lc_gain_by_yin_19;
	unsigned char lc_gain_by_yin_20;
	unsigned char lc_gain_by_yin_21;
	unsigned char lc_gain_by_yin_22;
	unsigned char lc_gain_by_yin_23;
	unsigned char lc_gain_by_yin_24;
	unsigned char lc_gain_by_yin_25;
	unsigned char lc_gain_by_yin_26;
	unsigned char lc_gain_by_yin_27;
	unsigned char lc_gain_by_yin_28;
	unsigned char lc_gain_by_yin_29;
	unsigned char lc_gain_by_yin_30;
	unsigned char lc_gain_by_yin_31;
	unsigned char lc_gain_by_yin_32;
	unsigned char lc_gain_by_yin_divisor;
} DRV_LC_Shpnr_Gain1st;

typedef struct {
	unsigned char lc_gain_by_ydiff_0;
	unsigned char lc_gain_by_ydiff_1;
	unsigned char lc_gain_by_ydiff_2;
	unsigned char lc_gain_by_ydiff_3;
	unsigned char lc_gain_by_ydiff_4;
	unsigned char lc_gain_by_ydiff_5;
	unsigned char lc_gain_by_ydiff_6;
	unsigned char lc_gain_by_ydiff_7;
	unsigned char lc_gain_by_ydiff_8;
	unsigned char lc_gain_by_ydiff_9;
	unsigned char lc_gain_by_ydiff_10;
	unsigned char lc_gain_by_ydiff_11;
	unsigned char lc_gain_by_ydiff_12;
	unsigned char lc_gain_by_ydiff_13;
	unsigned char lc_gain_by_ydiff_14;
	unsigned char lc_gain_by_ydiff_15;
	unsigned char lc_gain_by_ydiff_16;
	unsigned char lc_gain_by_ydiff_17;
	unsigned char lc_gain_by_ydiff_18;
	unsigned char lc_gain_by_ydiff_19;
	unsigned char lc_gain_by_ydiff_20;
	unsigned char lc_gain_by_ydiff_21;
	unsigned char lc_gain_by_ydiff_22;
	unsigned char lc_gain_by_ydiff_23;
	unsigned char lc_gain_by_ydiff_24;
	unsigned char lc_gain_by_ydiff_25;
	unsigned char lc_gain_by_ydiff_26;
	unsigned char lc_gain_by_ydiff_27;
	unsigned char lc_gain_by_ydiff_28;
	unsigned char lc_gain_by_ydiff_29;
	unsigned char lc_gain_by_ydiff_30;
	unsigned char lc_gain_by_ydiff_31;
	unsigned char lc_gain_by_ydiff_32;
	unsigned char lc_gain_by_ydiff_divisor;
} DRV_LC_Shpnr_Gain2nd;

typedef struct {
	unsigned char lc_ydiff_measure_en;
	unsigned short lc_ydiff_abs_th;

} DRV_LC_Diff_Ctrl0;

typedef struct {
	DRV_LC_Global_Ctrl LC_Global_Ctrl;
	DRV_LC_Backlight_Decision LC_Backlight_Decision;
	DRV_LC_Spatial_Filter LC_Spatial_Filter;
	DRV_LC_Temporal_Filter LC_Temporal_Filter;
	DRV_LC_Backlight_Profile_Interpolation LC_Backlight_Profile_Interpolation;
	DRV_LC_Demo_Window LC_Demo_Window;
	DRV_LC_ToneMapping_Grid0 LC_ToneMapping_Grid0;
	DRV_LC_ToneMapping_Grid2 LC_ToneMapping_Grid2;
	DRV_LC_ToneMapping_CurveSelect LC_ToneMapping_CurveSelect;
	DRV_LC_ToneMapping_Blend LC_ToneMapping_Blend;
	DRV_LC_Shpnr_Gain1st LC_Shpnr_Gain1st;
	DRV_LC_Shpnr_Gain2nd LC_Shpnr_Gain2nd;
	DRV_LC_Diff_Ctrl0 LC_Diff_Ctrl0;

} DRV_Local_Contrast_Table;

//juwen, 1028, set blk num/size and factor
typedef struct {
        unsigned char nBlk_Hnum;
        unsigned char nBlk_Vnum;
        unsigned short  nBlk_Hsize;
        unsigned short  nBlk_Vsize;
	  unsigned int lc_hfactor;
	  unsigned int lc_vfactor;
} LC_Region_Num_Size;

*/

void drvif_color_set_LC_Enable(unsigned char enable);
void drvif_color_set_LC_Global_Ctrl(DRV_LC_Global_Ctrl *ptr);
void drvif_color_set_LC_Backlight_Decision(DRV_LC_Backlight_Decision *ptr);
void drvif_color_set_LC_Spatial_Filter(DRV_LC_Spatial_Filter *ptr);
void drvif_color_set_LC_Temporal_Filter(DRV_LC_Temporal_Filter *ptr);
void drvif_color_set_LC_Backlight_Profile_Interpolation(DRV_LC_Backlight_Profile_Interpolation *ptr);
//void drvif_color_set_LC_BL_Profile_Interpolation_Table(unsigned int *ptr);
void drvif_color_set_LC_BL_Profile_Interpolation_Table(unsigned int *ptr,unsigned char mode,unsigned char tab_size);

void drvif_color_set_LC_Demo_Window(DRV_LC_Demo_Window *ptr);
void drvif_color_set_LC_Backlight_Profile_Interpolation_Table(int ptr[6][4][20]);

void drvif_color_set_LC_ToneMapping_Grid0(DRV_LC_ToneMapping_Grid0 *ptr);
void drvif_color_set_LC_ToneMapping_Grid2(DRV_LC_ToneMapping_Grid2 *ptr);

void drvif_color_set_LC_ToneMapping_CurveSelect(DRV_LC_ToneMapping_CurveSelect *ptr);
void drvif_color_set_LC_ToneMapping_Blend(DRV_LC_ToneMapping_Blend *ptr);


void drvif_color_set_LC_Shpnr_Gain1st(DRV_LC_Shpnr_Gain1st *ptr);
void drvif_color_set_LC_Shpnr_Gain2nd(DRV_LC_Shpnr_Gain2nd *ptr);
void drvif_color_set_LC_Diff_Ctrl0(DRV_LC_Diff_Ctrl0 *ptr);
//juwen, add LC : tone mapping curve
void drvif_color_set_LC_ToneMappingSlopePoint(unsigned int *ptr);
void drvif_color_get_LC_ToneMappingSlopePoint(unsigned int *ptr_out);
void drvif_color_set_LC_DebugMode(unsigned char DebugMode);

char drvif_color_get_LC_Enable(void);
char drvif_color_get_LC_DebugMode(void);
void drvif_color_set_HV_Num_Fac_Size(VIP_DRV_Local_Contrast_Region_Num_Size *LC_Region_Num_Size);

unsigned char drvif_color_get_LC_blk_hnum(void);
unsigned char drvif_color_get_LC_blk_vnum(void);
void drvif_color_get_LC_APL(unsigned int *ptr_out);
void drvif_color_get_LC_Histogram(unsigned int *plc_out);
void drvif_color_get_LC_Blight_dat(unsigned int *ptr_out);

#ifdef __cplusplus
}
#endif

#endif // __LOCALCONTRAST_H__


