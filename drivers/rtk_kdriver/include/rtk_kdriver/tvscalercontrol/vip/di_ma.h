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

#ifndef _MA_H
#define _MA_H
/*============================ Module dependency  ===========================*/

/*===================================  Types ================================*/

typedef struct {
	unsigned char en;
	unsigned char upperbound_sad;
} DRV_smd_control_t;

typedef struct {
	unsigned char mv_x;
	unsigned char mv_y;
} DRV_smd_gmvcoeff3_t;

typedef struct {
	unsigned short gmv3_th;
	unsigned char apply_result_mode;
	unsigned char firmware_pan;
	unsigned char searchmv_apply;
	unsigned char hardware_pan_en;
	unsigned char vpan_en;
	unsigned char searchmv_apply_sad_th;
	unsigned char firmware_pan_sad_th;
	unsigned char vpan_work_th;
	unsigned char vpan_jump_out;
	unsigned char vpan_upper_bound;
	unsigned char enter_pan_ctr_th;
	unsigned char vpan_gmv1_pixel;
	unsigned char vpan_total_pixel;
	unsigned char addctr_gmv1_pixelth1;
	unsigned char addctr_gmv1_pixelth2;
	unsigned char search_apply_th;
	unsigned char rebuild_pan_ctr;
} DRV_smd_pan_t;

typedef struct {
	unsigned char full_search_mode;
	unsigned char intra_en;
	unsigned char colony_drop_en;
	unsigned char colony_expanse_en;
	unsigned char colony_expanse_type;
	unsigned char result_en;
	unsigned char curr_teeth_offset_c;
	unsigned char curr_teeth_gain_c;
	unsigned char expanse_range;
	unsigned char left_weave_blend;
	unsigned char right_weave_blend;
	unsigned char image_boundary_height;
	unsigned char image_boundary_width;
	unsigned char search_gmv_offset;
	unsigned char search_gmv_gain;
	unsigned char left_us_blend;
	unsigned char right_us_blend;
	unsigned char sm_flag_control;
	unsigned char zm_flag_control;
	unsigned char left_us_range;
	unsigned char left_us_th;
	unsigned char right_us_range;
	unsigned char right_us_th;
} DRV_smd_additionalcoeff_t;

typedef struct {
	unsigned short v4highfreqth1;
	unsigned char v4highfreqth2;
	unsigned char patterngenmode;
	unsigned char v4highfreqeffect;
} DRV_smd_v4highfreq_t;

typedef struct {
	unsigned char en;
	unsigned char pregmv_needstable;
	unsigned char replace_sad;
	unsigned char search_zmv_offset;
	unsigned char fmv2weave_p;
	unsigned char fmv2weave_n;
} DRV_gst_ctrl_t;

typedef struct {
	unsigned short enter_origsad_offset;
	unsigned char enter_origsad_lowth;
	unsigned char outofrange_check;
	unsigned char outofrange_origsad;
	unsigned char outofrange_fracsadlowth;
	unsigned char outofrange_fracsad_offset;
	unsigned char freqnonmatch_check;
	unsigned char freqnonmatch_origsad;
	unsigned char freqnonmatch_fracsad_lowth;
	unsigned char freqnonmatch_fracsad_offset;
} DRV_gst_check_t;

typedef struct {
	unsigned char gmv_sad_th;
	unsigned char gmv_sad_max;
	unsigned char localmv_sad_max;
	unsigned char spatialmv_sad_max;
} DRV_smd_limitsad_t;

typedef struct {
	unsigned char en;
	unsigned char ratio;
} DRV_di_ma_hme_prefer_even_mv;

typedef struct {
	unsigned char en;
	unsigned char Nedge;
	unsigned char RLedge;
} DRV_di_ma_hme_avoid_RL;

typedef struct {
	unsigned char en;
	unsigned char thd0;
	unsigned char thd1;
	unsigned char thd2;
	unsigned char bias1;
	unsigned char bias2;
	unsigned char bias3;
} DRV_di_ma_hme_ref_y;

typedef struct {
	unsigned char chck_1_en;
	unsigned char chck_2_en;
	unsigned char zeroMV_en;
	unsigned char cnt;
	unsigned char maxmin_thd;
} DRV_di_ma_hme_invalid_check;

typedef struct {
	unsigned char min;
	unsigned char x_conti_cnt;
	unsigned char sum_max_ratio;
	unsigned char line_ratio;
	unsigned char max_abs;
} DRV_di_ma_hme_decision;

typedef struct {
	unsigned char hme_refine_en;
	unsigned char refine_c1_en;
	unsigned char c1_2MV_range_th;
	unsigned char c1_2Max_diff_th;
	unsigned char refine_c2_en;
	unsigned char c2_2MV_bin_ratio;
	unsigned char c2_2MV_LineMinIndex_th;
	unsigned char c2_2MV_LineMinIndex_MV_bin_cnt;
	unsigned char refine_c3_en;
	unsigned char c3_MaxInvalidCnt_ratio_th;
	unsigned char c3_SobelDiff_InvalidCnt_th;
	unsigned char refine_t_en;
	unsigned char refine_t_th;
} DRV_di_ma_hme_refine;

typedef struct {
	unsigned char hmc_en;
	unsigned char ma_horicomth;
	unsigned char hmc_even_mv_no_teeth_en;
	unsigned char hmc_odd_mv_no_comp_en;
	unsigned char hmc_window_en;
	unsigned char hmc_follow_MA_en;
	unsigned char hmc_half_mv_blending_en;
	unsigned int hmc_window_top;
	unsigned int hmc_window_bot;
	unsigned int hmc_window_start_line;
} DRV_di_ma_hmc_main_control;

typedef struct {
	unsigned char mv_refine_en;
	unsigned char mv_refine_Y_thd;
	unsigned char mv_refine_subPx_en;
	unsigned char mv_refine_subPx_Y_thd;
	unsigned char mv_refine_curMotion_en;
	unsigned char mv_refine_curMotion_thd;
	unsigned char mv_refine_sobel_en;
	unsigned char mv_refine_sobel_nonEdge_thd;
	unsigned char mv_refine_sobel_diff_thd;
} DRV_di_ma_hmc_mv_refine;

typedef struct {
	unsigned char en;
	unsigned char noise_thd;
	unsigned char hh_h_thd;
	unsigned char hh_v_thd;
	unsigned char zero_hh_1_thd;
	unsigned char zero_1_thd;
	unsigned char zero_2_thd;
	unsigned char same_hh_1_thd;
	unsigned char same_1_thd;
	unsigned char same_2_thd;
} DRV_di_ma_hmc_morphology;

typedef struct {
	unsigned char thd_en;
	unsigned char thd_bias;
	unsigned char clip_en;
	unsigned char clip_min_thd;
	unsigned char clip_max_thd;
} DRV_di_ma_hmc_dynamic_control;

typedef struct {
	unsigned char en;
	unsigned char edge_yuv_diff;
	unsigned char top_bot_y;
	unsigned char top_cur_y;
	unsigned char cur_bot_y;
	unsigned char top_bot_u;
	unsigned char top_cur_u;
	unsigned char cur_bot_u;
	unsigned char top_bot_v;
	unsigned char top_cur_v;
	unsigned char cur_bot_v;
} DRV_di_ma_hmc_vertical_intra;

typedef struct {
	unsigned char pan_en;
	unsigned char sub_px_det_en;
	unsigned char force_comp_en;
	unsigned char pan_odd_mv_en;
	unsigned char pan_mc_vertical_intra_en;
	unsigned char pan_me_hist_sel;
	unsigned char pan_mc_adpative_en;
	unsigned char pan_mc_rls_en;
	unsigned char pan_mc_teeth_check_en;
	unsigned char sobel_diff_thd;
	unsigned char sobel_diff_thd_rls;
	unsigned char teeth_check_thd;
} DRV_di_ma_pan_control;

typedef struct {
	unsigned char Nedge_en;
	unsigned char Hedge_en;
	unsigned char Vedge_en;
	unsigned char Ledge_en;
	unsigned char Redge_en;
} DRV_di_ma_pan_edge_type;

typedef struct {
	int diffMinThd;
	unsigned char restIdx;
	int restIdxThd;
	int diffMaxMin;
	unsigned char panConti_str;
	unsigned char panConti;
	unsigned char panDeb_str;
	unsigned char panDeb;
} DRV_di_ma_pan_detection;

typedef struct {
	DRV_di_ma_hme_prefer_even_mv di_ma_hme_prefer_even_mv;			/* 2*/
	DRV_di_ma_hme_avoid_RL di_ma_hme_avoid_RL;						/* 3*/
	DRV_di_ma_hme_ref_y di_ma_hme_ref_y;							/* 7*/
	DRV_di_ma_hme_invalid_check di_ma_hme_invalid_check;			/* 5*/
	DRV_di_ma_hme_decision di_ma_hme_decision;						/* 5*/
	DRV_di_ma_hme_refine di_ma_hme_refine;							/* 13*/
} DRV_di_ma_hme_table;

typedef struct {
	DRV_di_ma_hmc_main_control di_ma_hmc_main_control;				/* 9*/
	DRV_di_ma_hmc_mv_refine di_ma_hmc_mv_refine;					/* 9*/
	DRV_di_ma_hmc_morphology di_ma_hmc_morphology;					/* 10*/
	DRV_di_ma_hmc_dynamic_control di_ma_hmc_dynamic_control;			/* 5*/
	DRV_di_ma_hmc_vertical_intra di_ma_hmc_vertical_intra;				/* 11*/
	unsigned int DI_HMC_ME_REFINE_CTRL_1;
} DRV_di_ma_hmc_table;

typedef struct {
	DRV_di_ma_pan_control di_ma_pan_control;							/* 12*/
	DRV_di_ma_pan_edge_type di_ma_pan_edge_type;					/* 5*/
	DRV_di_ma_pan_detection di_ma_pan_detection;						/* 4*/
} DRV_di_ma_pan_table;



/* DI MA Control and Parameters (Adjust Part)*/
typedef struct {
	unsigned char ma_controlmode;
	unsigned char ma_stilllogoena;
	unsigned char ma_smoothintra90;
	unsigned char ma_messintra90;
	/*unsigned char ma_onedirectionweaveen;*/
	/*unsigned char ma_preferintra;*/

} DRV_di_ma_control;

typedef struct {
	unsigned char ma_framehtha;
	unsigned char ma_framemtha;
	unsigned char ma_framerlvtha;
	unsigned char ma_framestha;
	unsigned char ma_framehthb;
	unsigned char ma_framemthb;
	unsigned char ma_framerlvthb;
	unsigned char ma_framesthb;
	unsigned char ma_framehthc;
	unsigned char ma_framemthc;
	unsigned char ma_framerlvthc;
	unsigned char ma_framesthc;
} DRV_di_ma_frame_motion_th;

typedef struct {
	unsigned char  ma_fieldteethhtha;
	unsigned char  ma_fieldteethmtha;
	unsigned char  ma_fieldteethrlvtha;
	unsigned char  ma_fieldteethstha;

} DRV_di_ma_field_teeth_th;


typedef struct {
	DRV_di_ma_control di_ma_control;
	DRV_di_ma_frame_motion_th di_ma_frame_motion_th;
	DRV_di_ma_field_teeth_th di_ma_field_teeth_th;
} DRV_di_ma_adjust_table;

/* DI MA Control and Parameters (Init Part)*/
typedef struct {
	unsigned char  ma_stilllogovdth;
	unsigned char  ma_ydiffth;
	unsigned char  ma_fieldteeththb;

} DRV_di_ma_others_th;

typedef struct {
	unsigned char ma_sawtoothhth;
	unsigned char ma_sawtoothmth;
	unsigned char ma_sawtoothrlvth;
	unsigned char ma_sawtoothsth;
} DRV_di_ma_sawtooth_th;

typedef struct {
	unsigned char ma_onedirectionweaveen;
	unsigned char ma_preferintra;
} DRV_di_ma_control_init;


typedef struct {
	DRV_di_ma_control_init di_ma_control_init;
	DRV_di_ma_others_th di_ma_others_th;
	DRV_di_ma_sawtooth_th di_ma_sawtooth_th;
} DRV_di_ma_init_table;





/* chen 0716*/
typedef struct {
	unsigned char smd_water_en;
	unsigned char smd_water_pan_disable;
	unsigned char smd_water_result;
	unsigned char smd_water_gain;
	unsigned char smd_water_offset;
	unsigned char smd_water_modeth;
	unsigned char smd_water_uv_offset;
	unsigned char smd_water_intradiff_th;
	unsigned char smd_water_minteethy;
	unsigned char smd_water_teeth;
	unsigned char smd_elseintra_en;
	unsigned char smd_stillsad_th;
	unsigned char smd_stillsad_max;
	unsigned char smd_water_avgy_offset;
	unsigned char smd_water_avgy_lowbound;
} DRV_Smd_Waterflag;

typedef struct {
	unsigned char smd_searchmvapply_ctr;
	unsigned int smd_firmwarepan_sadmax;
	unsigned char smd_gmvb_sadmin_th;
	unsigned char smd_streammv_gmv_diff;
	unsigned char smd_hardwarepan_firststep;
} DRV_Smd_Pan_modify;

typedef struct {
	unsigned char smd_pg_minsad_th;
	unsigned char smd_pg_messlevel_th;
	unsigned char smd_pg_diffsad_th;
	unsigned char smd_close2gmv_mvselect;
	unsigned char smd_hmin_sad_ctr;
	unsigned char smd_vmin_sad_ctr;
	unsigned char smd_pg_close2gmv;
	unsigned char smd_close2gmv_edgectr;
	unsigned char smd_close2gmv_minctr;
} DRV_Smd_samp_Gmv;

typedef struct {
	unsigned char gst_subpixel_firmwarepan_fmv1;
	unsigned char gst_subpixel_firmwarepan_fmv2;
	unsigned char gst_subpixel_firmwarepan;
	unsigned char gst_blend_weight;
	unsigned char gst_compensate_blending_en;
	unsigned char gst_compensate_fmv8_en;
	unsigned char gst_compensate_fmv7_en;
	unsigned char gst_compensate_fmv6_en;
	unsigned char gst_compensate_fmv5_en;
	unsigned char gst_compensate_fmv4_en;
	unsigned char gst_compensate_fmv3_en;
	unsigned char gst_compensate_fmv2_en;
	unsigned char gst_compensate_fmv1_en;
	unsigned char gst_compensate_fmv0_en;
	unsigned char gst_pg_highpriority;
	unsigned char gst_integerpan_highpriority;
	unsigned char gst_subpixel_rlv2intra_en;
	unsigned char gst_subpixel_hardwarepan_en;
	unsigned char gst_debug_subpixel_pan;
	unsigned char gst_subpixel_compensate_en;
} DRV_Smd_Gst_Compensate;

typedef struct {
	unsigned int gst_subpixel_firmwarepan_sadmax;
	unsigned char gst_subpixel_firmwarepan_sadmin;
	unsigned char gst_subpixel_pan_ratio;
	unsigned char gst_quantizeddiff_gain;
	unsigned char gst_quantizeddiff_offset;
	unsigned char gst_maxfmv_diff_th;
	unsigned char gst_fmvhist_sad_diff;
} DRV_Smd_fmv_pan_coeff;

/* end chen 0716*/


/* ylchen 150617 */
typedef struct {
	unsigned char smd_outofrange_content_new;
	unsigned char smd_acc_smd_en;
	unsigned char smd_spatialfreqnomatch_off;
	unsigned char smd_linecontinous_new_condition;
	unsigned char smd_sawtooth_condition_select;
	unsigned char smd_weave_dynamic;
	unsigned char smd_close2gmv_mvselect;
	unsigned char smd_resurrectsmallwindownum2;
	unsigned char smd_resurrectminsadth2;
	unsigned char smd_reliablerangesadth2;
	unsigned char smd_pg_no_pixel_ctr_en;
	unsigned char smd_gmv_old_method;
	unsigned char smd_search_range_limit_en; //di_di_smd_slow_motion_handle3_RBUS
//	unsigned char smd_sadwindow_select;				//di_di_smd_slow_motion_handle3_RBUS
//	unsigned char smd_hd_zero_mv_sad_select;	//di_di_smd_slow_motion_handle3_RBUS
//	unsigned char smd_field_diff_clamp;				//di_di_smd_slow_motion_handle3_RBUS
//	unsigned char smd_messlevel_vgain;				//di_di_smd_slow_motion_handle3_RBUS
//	unsigned char smd_messlevel_select;				//di_di_smd_slow_motion_handle3_RBUS
} DRV_Smd_MCDI_control;


typedef struct {
	unsigned char gst_min_sad_nolimit_en;
	unsigned char gst_gst_static_disable;
	unsigned char gst_min_sad_compare_diable;
	unsigned char gst_mv_limit;
//	unsigned char smd_fmv_gmv_penalty_en;			//di_di_smd_gmv_penalty_ctrl_RBUS
//	unsigned char smd_notonly_zero_gmv;				//di_di_smd_gmv_penalty_ctrl_RBUS
//	unsigned char smd_messlevel_th;						//di_di_smd_gmv_penalty_ctrl_RBUS
//	unsigned char smd_messlevel_gain_slope;		//di_di_smd_gmv_penalty_ctrl_RBUS
} DRV_Smd_SMD_control;

/*
// chen 160602
typedef struct
{
	unsigned char smd_mv_pixel_acc_max_th;		//di_di_smd_slow_motion_handle1_RBUS
	unsigned char smd_mv_pixel_acc_th;		//di_di_smd_slow_motion_handle1_RBUS
	unsigned char smd_mv_pixel_acc_th2;		//di_di_smd_slow_motion_handle1_RBUS
	unsigned char smd_mv_pixel_acc_th3;	//di_di_smd_slow_motion_handle2_RBUS
	unsigned char smd_mv_pixel_acc_th4;	//di_di_smd_resurrect_ctrl_RBUS

}DRV_Smd_MV_accumulate;



typedef struct
{
	unsigned char smd_gmv_penalty_mess_gain_en;	//di_di_smd_gmv_penalty_ctrl2_RBUS
	unsigned char smd_gmv_only_teeth_mess_gain_en;	//di_di_smd_gmv_penalty_ctrl2_RBUS
	unsigned char smd_gmv_penalty_clamp_en;		//di_di_smd_gmv_penalty_ctrl2_RBUS
	unsigned char smd_close2gmv_fw_en;				//di_di_smd_sampling_gmvc_RBUS
	unsigned char smd_messlevel_field_diff;		//di_di_smd_gmv_penalty_ctrl2_RBUS
	unsigned char smd_gmv_clamp;							//di_di_smd_gmv_penalty_ctrl2_RBUS
	unsigned char smd_fw_gmvx;								//di_di_smd_hardwarepan_modify1_RBUS
	unsigned char smd_fw_gmvy;								//di_di_smd_waterflag_ctr3_RBUS
	unsigned char smd_gmv_candidate_method;		//di_di_smd_gmv_penalty_ctrl_RBUS
	unsigned char smd_mv_value_hist_method;		//di_di_smd_slow_motion_handle3_RBUS
	unsigned char smd_gmv_sad_select;					//di_di_smd_gmv_penalty_ctrl2_RBUS

}DRV_Smd_GMV_Control;



typedef struct
{
	unsigned char smd_mess_conditionoff;		//di_di_smd_slow_motion_handle1_RBUS
	unsigned char smd_messlevel_gain;				//di_di_smd_slow_motion_handle2_RBUS
	unsigned char smd_outrange_field_diff_th;	//di_di_smd_slow_motion_handle3_RBUS
	unsigned char smd_messlevel_gain2;				//di_di_smd_slow_motion_handle2_RBUS
	unsigned char smd_teeth_value_select;   //di_di_smd_slow_motion_handle1_RBUS
	unsigned char smd_outrange_teeth_select;	//di_di_smd_slow_motion_handle1_RBUS


}DRV_Smd_Outofrange_Control;
*/


typedef struct
{
//	unsigned char smd_weave_out_avg_blending_en;		//di_di_smd_slow_motion_handle3_RBUS
//	unsigned char ma_smd_h_compensate_new_en;				//di_di_smd_slow_motion_handle3_RBUS
	unsigned char smd_outdata_limit_en;							//di_di_smd_ma_mc_weight_ctr_RBUS
//	unsigned char smd_smd_ma_only_v_en;							//di_di_smd_diag_edge_protect_ctr_RBUS
//	unsigned char smd_smd_ma_only_center_en;				//di_di_smd_diag_edge_protect_ctr_RBUS
//	unsigned char smd_compensate_teeth_th2;					//di_di_smd_slow_motion_handle3_RBUS
	unsigned char smd_outdata_limit_mvx;						//di_di_smd_ma_mc_weight_ctr_RBUS
	unsigned char	smd_outdata_limit_mvy;						//di_di_smd_ma_mc_weight_ctr_RBUS
//	unsigned char smd_smd_vs_detect_length;					//di_di_smd_diag_edge_protect_ctr_RBUS
//	unsigned char nintra_v_dir_flag_en;							//di_di_smd_diag_edge_protect_ctr_RBUS
//	unsigned char nintra_hv_diff_th;								//di_di_smd_diag_edge_protect_ctr_RBUS
//	unsigned char nintra_h_diff_th;									//di_di_smd_diag_edge_protect_ctr_RBUS


}DRV_Smd_MC_Out_Control;

/*
typedef struct
{
	unsigned char smd_mv_not_gmv_resurrect_en;			//di_di_smd_resurrect_ctrl_RBUS
	unsigned char smd_resurrect_noacc_en;						//di_di_smd_resurrect_ctrl_RBUS
	unsigned char smd_teeth_no_ressurrect_n_en;			//di_di_smd_slow_motion_handle3_RBUS
	unsigned char smd_nongmv0_noacc_en;							//di_di_smd_resurrect_ctrl_RBUS

}DRV_Smd_Resurrect_Condition;
// end chen 160602
*/

typedef struct {
	unsigned char smd_waterflow_protect_en;
	unsigned char smd_currteethgain_wf;
	unsigned char smd_totalteethoffset_wf;
	unsigned char smd_compensate_teeth_th_wf;
	unsigned char smd_min_total_th_wf;
	unsigned char smd_sawtooth_count_th_wf;

} DRV_Smd_Waterflow_teeth_control;


typedef struct {
	unsigned char smd_outofrange_lpf_en;
	unsigned char smd_smd_blend_lpf_en;
	unsigned char smd_smd_blend_clamp_en;
	unsigned char smd_spatial_mv_diff_weight_en;
	unsigned char smd_weight_lpf_select;
	unsigned char smd_odd_mvy_ma_out_select;
	unsigned char smd_spatial_mv_diff_coring;
	unsigned char smd_spatial_mv_diff_gain;
} DRV_Smd_MA_MC_Blending_control;


typedef struct {
	unsigned char smd_mcdi2madi_en;
	unsigned char smd_mcdi2madi_v_pan_new_en;
	unsigned char smd_intra_weight_method;
	unsigned char smd_intra_weight_method_vpan;
	unsigned char smd_diag_count_th;
} DRV_Smd_diag_edge_control;
/* end ylchen 150617 */


typedef struct {
	DRV_smd_control_t smd_control;
	DRV_smd_gmvcoeff3_t smd_gmvcoeff3;
	DRV_smd_pan_t smd_pan;
	DRV_smd_additionalcoeff_t smd_additionalcoeff;
	DRV_smd_v4highfreq_t smd_v4highfreq;
	DRV_gst_ctrl_t gst_ctrl;
	DRV_gst_check_t gst_check;
	DRV_smd_limitsad_t smd_limitsad;
	DRV_Smd_Waterflag Smd_Waterflag;
	DRV_Smd_Pan_modify Smd_Pan_modify;
	DRV_Smd_samp_Gmv Smd_samp_Gmv;
	DRV_Smd_Gst_Compensate Smd_Gst_Compensate;
	DRV_Smd_fmv_pan_coeff Smd_fmv_pan_coeff;

	/* ylchen 150617 */
	DRV_Smd_MCDI_control								Smd_MCDI_control;
	DRV_Smd_SMD_control									Smd_SMD_control;
	DRV_Smd_Waterflow_teeth_control	 		Smd_Waterflow_teeth_control;
	DRV_Smd_MA_MC_Blending_control			Smd_MA_MC_Blending_control;
	DRV_Smd_diag_edge_control						Smd_diag_edge_control;
	/* end ylchen 150617 */
	// chen 160602
//	DRV_Smd_MV_accumulate								Smd_MV_accumulate;
//	DRV_Smd_GMV_Control									Smd_GMV_Control;
//	DRV_Smd_Outofrange_Control					Smd_Outofrange_Control;
	DRV_Smd_MC_Out_Control							Smd_MC_Out_Control;
//	DRV_Smd_Resurrect_Condition					Smd_Resurrect_Condition;

	// end chen 160602

} DRV_di_smd_table_t;

typedef struct {
	unsigned char dynamic_threshold_en;
	unsigned char dynamic_threshold_bias;
	unsigned char dynamic_threshold_clip_en;
	unsigned char dynamic_threshold_min_clip;
	unsigned char dynamic_threshold_max_clip;
	unsigned char mv_refine_en;
	unsigned char even_mv_no_vectorteeth;
	unsigned char odd_mv_no_compesation;
	unsigned char sobel_search_min;
	unsigned char sum_max_ratio;
	unsigned char max_absolute_count;
	unsigned char x_continued_counter;
	unsigned char ma_hmc_lineratio;
} DRV_hmc_table_t;

typedef struct {
	unsigned char mv_refine_mor_en;
	unsigned char mv_refine_mor_noise_th;
	unsigned char mv_refine_mor_same_th1;
	unsigned char mv_refine_mor_zero_th1;
	unsigned char mv_refine_mor_same_th1_hh;
	unsigned char mv_refine_mor_zero_th1_hh;
	unsigned char mv_refine_mor_same_th2;
	unsigned char mv_refine_mor_zero_th2;
	unsigned char mv_refine_mor_hh_h_th;
	unsigned char mv_refine_mor_hh_v_th;

	unsigned char mv_refine_sobel_en;
	unsigned char mv_refine_sobel_diff_th;
	unsigned char mv_refine_sobel_non_edge_th;

	unsigned char mv_refine_cur_motion_en;
	unsigned char mv_refine_cur_motion_th;
	unsigned char follow_ma_result_en;
} DRV_hmc_table2_t;



typedef struct {
	unsigned char chromaerror_en;
	unsigned char chromaerror_all;
	unsigned char chromaerror_th;
	unsigned char chromaerror_framemotionc_th;
	unsigned char di444to422Lowpass;
} DRV_MA_ChromaError;



/*================================== Variables ==============================*/


/*================================ Definitions ==============================*/

#define LEVEL 6

/*================================== Function ===============================*/
/*============================================================================*/
/*
*set Memory for DI Main module
*
*unsigned short	height		image height
*unsigned short  width		image width
*unsigned char 	access  		1:5A		0:3A
*unsigned char 	bit			1:10bits	0:8bits
*/
void DI_SetMemoryMain(unsigned short height, unsigned short width, unsigned char access, unsigned char bit);
/*============================================================================*/
/*
*set Memory for DI Sub module
*
*unsigned short	height		image height
*unsigned short  width		image width
*unsigned char 	bit			1:10bits	0:8bits
*/
void DI_SetMemorySub(unsigned short height, unsigned short width, unsigned char bit);
/*============================================================================*/
/*
*set MA to initial state
*@param <Level> {Level control}
*/
void drvif_color_ma_init(void);
/*============================================================================*/
/*
*set MA threshold for 10 level
*0: intra only 		10:inter only
*@param <Level> {Level control}
*/

void drvif_color_ma_set_DI_MA_Adjust_Table(DRV_di_ma_adjust_table *ptr);
void drvif_color_ma_set_DI_MA_Init_Table(DRV_di_ma_init_table *ptr);




/*======================== End of File =======================================*/
/*
*MA auto threshold
*
*@param <Level> {Level control}
*/
/*void drvif_color_ma_auto_isr(unsigned char channel); */ /* hsliao 20081231, move to linux driver*/


void drvif_color_di_freeze(unsigned char bFreeze);

unsigned char drvif_color_regDCLtable(unsigned short *ptr);
short *drvif_color_getEmfTable(void);
/*unsigned char drvif_color_RegColorTable(StructColorDataType *ptr); */ /* marked by hsliao 20090316*/

void drvif_color_ma_HFD(unsigned char bHFD);
void drvif_color_ma_TeethCheck(unsigned char Level);
unsigned char drvif_color_ma_TeethCheckStatus(void);
void drvif_color_ma_HMCWindow(unsigned char bHMCWindow);
void drvif_color_ma_EdgeType(unsigned char bEdgeType);
void drvif_color_StillLineCntns(unsigned char ch, unsigned char en);
void drvif_color_ma_BTR(unsigned char bBTR);
void drvif_color_ma_BER(unsigned char bBER);   /* 100402*/


void drvif_color_ma_VEdge(unsigned char bEnable);
void drvif_color_ma_FrameSobel_HEdge(unsigned char bEnable);
void drvif_color_ma_420Mode(unsigned char bEnable);

void drvif_color_ma_ChromaError(DRV_MA_ChromaError *ptr);


void drvif_color_ma_auto_init_1(void);
void drvif_color_ma_auto_init_2(void);
void drvif_color_ma_auto_init_3(void);
void drvif_color_ma_auto_init_4(void);

void drvif_color_ma_HMC(DRV_di_ma_hmc_table *ptr);	/* Erin 101021 add for AT engineer mode*/
void drvif_color_ma_HME(DRV_di_ma_hme_table *ptr);
void drvif_color_ma_PAN(DRV_di_ma_pan_table *ptr);
/* Magellan new ip by LearnRPG@20130208*/
void drvif_color_ma_blending_corrector_1(unsigned char bEnable, unsigned char teeth_min, unsigned char teeth_max, unsigned char blendmode);
void drvif_color_ma_blending_corrector_2(unsigned char bEnable, unsigned char mode);
int drvif_color_ma_blending_corrector_2_getData(unsigned char pos_x, unsigned char pos_y);
void drvif_color_ma_Pan_Detection(unsigned char bEnable);

void drvif_color_smd_table(DRV_di_smd_table_t *ptr);

/* Sirius new ip by LearnRPG@20131218*/
void drvif_color_ma_init_g(void);
void drvif_color_ZOOM_MOTION_Seperate(unsigned int x_left_pos, unsigned int x_right_pos, unsigned int y_top_pos, unsigned int y_bot_pos);
void drvif_color_ZOOM_MOTION_En(unsigned char bEnable);
unsigned char drvif_color_ZOOM_MOTION_Status(void);
void drvif_color_ZOOM_MOTION_Level(unsigned char level);
void drvif_color_ZOOM_MOTION_Set_FM_TH(unsigned char Mth[3], unsigned char Hth[3], unsigned char RLVth[3], unsigned char Sth[3]);

void drvif_color_SLOW_MOTION_En(unsigned char bEnable);
unsigned char drvif_color_SLOW_MOTION_Status(void);
void drvif_color_SLOW_MOTION_Level(unsigned char level);
void drvif_color_SLOW_MOTION_Set_FM_TH(unsigned char Mth[3], unsigned char Hth[3], unsigned char RLVth[3], unsigned char Sth[3]);
char drvif_color_Get_MCNR_HV_PAN_MV(unsigned char *MV_X, unsigned char *MV_Y);
void drvif_color_Set_MA_Control_Mode(unsigned char mode);
void drvif_color_Set_DI_DB_APPLY(void);
void drvif_color_Set_smd_reliablerange_sad_th(unsigned char value);

/* Magennal2 new ip by LearnRPG@20150306*/
void drvif_color_VHF(unsigned char bEnable);
void drvif_color_BTR_SaveMode(unsigned char level);
void drvif_color_DI_GameMode(unsigned char bEnable);

void drvif_color_DI_Addr_Boundary_ini(unsigned int DI_addr_sta, unsigned int DI_addr_end, unsigned int DI_MASNR_addr_sta, unsigned int DI_MASNR_addr_end);

/*============================================================================*/


#endif
