#ifndef __INTRA_H__
#define __INTRA_H__

#ifdef __cplusplus
extern "C" {
#endif

/*============================ Module dependency  ===========================*/
/*#include "rtd_types.h"*/
/*===================================  Types ================================*/

typedef struct {
	unsigned char nintra_new_mode_en;
	unsigned char nintra_src_lpf_clamp_en;
	unsigned char nintra_lp_src_edge_th1;
	unsigned char nintra_lp_src_edge_th2;
	unsigned char nintra_lp_src_edge_slope;
	unsigned char nintra_lp_src_yclamp_th;

} DRV_Intra_Input;

typedef struct {
	unsigned char nintra_ydiff_mode;
	unsigned char nintra_vbound_detect_en;
	unsigned char nintra_search_min_limit_en;
	unsigned char nintra_high_freq_detect_en;
	unsigned char nintra_hdiff_th1;
	unsigned char nintra_hdiff_th2;
	unsigned char nintra_hfq_hdiff_th;
	unsigned char nintra_trans_count_th1;
	unsigned char nintra_trans_count_th2;
	unsigned char nintra_dir_search_region_max;
	unsigned char nintra_sr_minus_value;//di_im_di_nintra_control_RBUS chen 160602
} DRV_Intra_Search_Range;

typedef struct {
	unsigned char nintra_intersection_check_en;
	unsigned char nintra_dynamic_cross_th_en;
	unsigned char nintra_slopediff_th;
	unsigned char nintra_crossdiff_th;
	unsigned char nintra_crossslope_diff_th;
	unsigned char nintra_min_second_dir_check_en;
	unsigned char nintra_min_second_dir_check2_en;
	unsigned char nintra_minsecond_diff_th;
	unsigned char nintra_minsecond_diff_th2;
	unsigned char nintra_minsecond_diff_th3;
	unsigned char nintra_vertical_diff_th;
	unsigned char nintra_lowpass_dir_check_en;
	unsigned char nintra_pre_dir_check_en;
	unsigned char nintra_preline_dir_check1_en;
	unsigned char nintra_preline_dir_check2_en;
	unsigned char nintra_n_check2_control_disable;
	unsigned char nintra_lowpass_dir_count_th;
	unsigned char nintra_check2_y_diff_th;
	unsigned char nintra_vertical_diff_th2;				//di_im_di_nintra_1st_2nd_ydiff_th_2_RBUS
	unsigned char nintra_min_second_diff_th4;			//di_im_di_nintra_1st_2nd_ydiff_th_2_RBUS
} DRV_Intra_direction_refine;

typedef struct {
	unsigned char nintra_dyn_dir_lowpass_en;
	unsigned char nintra_output_lowpass_en;
	unsigned char nintra_ud_boundary_repeat_en;
} DRV_Intra_Out;


typedef struct {
	DRV_Intra_Input								Intra_Input;
	DRV_Intra_Search_Range				Intra_Search_Range;
	DRV_Intra_direction_refine		Intra_direction_refine;
	DRV_Intra_Out									Intra_Out;
} DRV_Intra_Ver2_Table;

/*================================  definitions ===============================*/

/*================================== Variables ==============================*/

/*================================== functions ==============================*/
void drvif_color_intra_init(void);

/*	Erin copy from Pacific 20100223*/
unsigned char drvif_color_intra_all_pacific_new_switch(unsigned char enable);
unsigned char drvif_color_intra_for_ma_mess(unsigned char enable);

/*	Erin add API 100609*/
void drvif_color_Intra_Ver2_table(DRV_Intra_Ver2_Table *ptr);   /*  mag2*/


#ifdef __cplusplus
}
#endif

#endif /* __INTRA_H__*/
