// This file is generated using the spec version 1.39, firmware template version 1.39and SRIF Parser                                                                                source code SVN rev:793                    Version flow no.:1.1.44
#ifndef _DI_REG_H_INCLUDED_
#define _DI_REG_H_INCLUDED_

//#define  _DI_USE_STRUCT
#ifdef _DI_USE_STRUCT

typedef struct
{
    unsigned int    film_sawtooth_choose:2;
    unsigned int    film22_filter_andor:1;
    unsigned int    ip_enable:1;
    unsigned int    di444to422lowpass:1;
    unsigned int    cp_tresultweight:3;
    unsigned int    cp_temporalenable:1;
    unsigned int    intra_lowangleenable:1;
    unsigned int    intra_stage1enable:1;
    unsigned int    intra_stage2enable:1;
    unsigned int    intra_mfilterenable:1;
    unsigned int    intra_interpolationrange:4;
    unsigned int    film_enable:5;
    unsigned int    ma_vertexten:1;
    unsigned int    ma_horicomen:1;
    unsigned int    ma_stilllogoena:1;
    unsigned int    ma_smoothintra90:1;
    unsigned int    ma_messintra90:1;
    unsigned int    ma_3aenable:1;
    unsigned int    ma_controlmode:2;
    unsigned int    ma_onedirectionweaveen:1;
    unsigned int    ma_preferintra:1;
}IM_di_control;

typedef struct
{
    unsigned int    fun_y_en:1;
    unsigned int    y10bitsin:1;
    unsigned int    c10bitsin:1;
    unsigned int    reserved_0:11;
    unsigned int    cr_fh_switch:1;
    unsigned int    cr_autoimg_enable:1;
    unsigned int    reserved_1:15;
    unsigned int    cp_bist_clkmux_en:1;
}REG18024004;

typedef struct
{
    unsigned int    field_confuse:1;
    unsigned int    di_3d_l_flag:1;
    unsigned int    reserved_0:24;
    unsigned int    film_debugmode:1;
    unsigned int    ma_debugmode:3;
    unsigned int    ma_modeselect:1;
    unsigned int    cp_tnrdebugmode:1;
}IM_di_debug_mode;

typedef struct
{
    unsigned int    singlefieldintra:1;
    unsigned int    hsize:11;
    unsigned int    vsize:10;
    unsigned int    hblksize:10;
}IM_di_active_window_control;

typedef struct
{
    unsigned int    fixedwindowmode:2;
    unsigned int    reserved_0:8;
    unsigned int    hblksize_msb:1;
    unsigned int    freeze:1;
    unsigned int    force2d:1;
    unsigned int    readstart:11;
    unsigned int    delpixelen:1;
    unsigned int    dellineen:1;
    unsigned int    fixedwindow5:1;
    unsigned int    fixedwindow4:1;
    unsigned int    fixedwindow3:1;
    unsigned int    fixedwindow2:1;
    unsigned int    fixedwindow1:1;
    unsigned int    fixedwindow0:1;
}IM_di_weave_window_control;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    ystart_11_0:12;
    unsigned int    reserved_1:4;
    unsigned int    xstart_11_0:12;
}IM_di_weave_window_0_start;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    yend_11_0:12;
    unsigned int    reserved_1:4;
    unsigned int    xend_11_0:12;
}IM_di_weave_window_0_end;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    ystart_23_12:12;
    unsigned int    reserved_1:4;
    unsigned int    xstart_23_12:12;
}IM_di_weave_window_1_start;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    yend_23_12:12;
    unsigned int    reserved_1:4;
    unsigned int    xend_23_12:12;
}IM_di_weave_window_1_end;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    ystart_35_24:12;
    unsigned int    reserved_1:4;
    unsigned int    xstart_35_24:12;
}IM_di_weave_window_2_start;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    yend_35_24:12;
    unsigned int    reserved_1:4;
    unsigned int    xend_35_24:12;
}IM_di_weave_window_2_end;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    ystart_47_36:12;
    unsigned int    reserved_1:4;
    unsigned int    xstart_47_36:12;
}IM_di_weave_window_3_start;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    yend_47_36:12;
    unsigned int    reserved_1:4;
    unsigned int    xend_47_36:12;
}IM_di_weave_window_3_end;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    ystart_59_48:12;
    unsigned int    reserved_1:4;
    unsigned int    xstart_59_48:12;
}IM_di_weave_window_4_start;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    yend_59_48:12;
    unsigned int    reserved_1:4;
    unsigned int    xend_59_48:12;
}IM_di_weave_window_4_end;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    ystart_71_60:12;
    unsigned int    reserved_1:4;
    unsigned int    xstart_71_60:12;
}IM_di_weave_window_5_start;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    yend_71_60:12;
    unsigned int    reserved_1:4;
    unsigned int    xend_71_60:12;
}IM_di_weave_window_5_end;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    pseudo_memc_film22_sequence:2;
    unsigned int    pseudo_memc_film22_weight0:2;
    unsigned int    pseudo_memc_film22_weight1:2;
    unsigned int    reserved_1:3;
    unsigned int    ma_class_h_th1_cmp:5;
    unsigned int    reserved_2:3;
    unsigned int    ma_class_h_th1:5;
    unsigned int    reserved_3:3;
    unsigned int    ma_class_h_th2:5;
}IM_di_classify_th;

typedef struct
{
    unsigned int    pseudo_memc_en:1;
    unsigned int    dummy18024048_30:1;
    unsigned int    pseudo_memc_film32_sequence:4;
    unsigned int    pseudo_memc_film32_weight0:2;
    unsigned int    pseudo_memc_film32_weight1:2;
    unsigned int    pseudo_memc_film32_weight2:2;
    unsigned int    pseudo_memc_film32_weight3:2;
    unsigned int    ma_blend_fmcomb3:2;
    unsigned int    ma_blend_fmcomb2:2;
    unsigned int    ma_blend_fmcomb1_hor:2;
    unsigned int    ma_blend_fmcomb1:2;
    unsigned int    ma_blend_fmcomb0:2;
    unsigned int    reserved_0:1;
    unsigned int    ma_blend10_weight:3;
    unsigned int    reserved_1:1;
    unsigned int    ma_blend01_weight:3;
}IM_di_blend_and_weighting_method;

typedef struct
{
    unsigned int    dummy1802404c_31:1;
    unsigned int    ma_sobelthm:10;
    unsigned int    ma_sobelths:10;
    unsigned int    force_2d_timing_en:1;
    unsigned int    force_2d_timing_mode:1;
    unsigned int    field_diff1:1;
    unsigned int    vodma_film_en:1;
    unsigned int    field_diff1_sel:1;
    unsigned int    dummy1802404c_5_3:3;
    unsigned int    force_di_nxt:1;
    unsigned int    force_dma_intra:1;
    unsigned int    force_dma_2d:1;
}IM_di_mpeg_sequence_app;

typedef struct
{
    unsigned int    ma_vedge_nolp_en:3;
    unsigned int    ma_class_s_th2:5;
    unsigned int    reserved_0:3;
    unsigned int    ma_class_rlv_th1_cmp:5;
    unsigned int    reserved_1:3;
    unsigned int    ma_class_rlv_th1:5;
    unsigned int    reserved_2:3;
    unsigned int    ma_class_rlv_th2:5;
}IM_di_classify2_th;

typedef struct
{
    unsigned int    ma_new_class_en:1;
    unsigned int    reserved_0:25;
    unsigned int    ma_vedge_add_rlv:2;
    unsigned int    reserved_1:1;
    unsigned int    ma_vedge_nonlpfm_en:1;
    unsigned int    ma_vedge_force90_en:1;
    unsigned int    ma_vedge_force_intra_en:1;
}IM_di_new_class;

typedef struct
{
    unsigned int    dma_420_en:2;
    unsigned int    rdma_random_en:1;
    unsigned int    reserved_0:7;
    unsigned int    linesize_even:10;
    unsigned int    reserved_1:2;
    unsigned int    linesize_odd:10;
}IM_di_dma;

typedef struct
{
    unsigned int    cr_var4thl:8;
    unsigned int    cr_var3thl:8;
    unsigned int    cr_var2thl:8;
    unsigned int    cr_var1thl:8;
}IM_di_xc_auto_balance_th;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    cr_transitionthl:8;
    unsigned int    cr_meanthl:8;
}IM_di_xc_auto_balance_th2;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    cr_thl_mainbalance:8;
    unsigned int    cr_thl_subbalance:16;
}IM_di_xc_auto_balance_th3;

typedef struct
{
    unsigned int    reserved_0:3;
    unsigned int    stilllinecntns_window_mode:1;
    unsigned int    stilllinecntns_cond_th:2;
    unsigned int    stilllinecntns_window_th:5;
    unsigned int    stilllinecntns_window:3;
    unsigned int    stilllinecntns_apply_hmc_window:1;
    unsigned int    stillline_cntns_en:1;
    unsigned int    intra_motionthly:8;
    unsigned int    intra_motionthlc:8;
}IM_di_intra_sobel_motion_th;

typedef struct
{
    unsigned int    intra_con1peakthly:8;
    unsigned int    intra_con1peakthlc:8;
    unsigned int    intra_con2interpolationthly:8;
    unsigned int    intra_con3peakthly:8;
}IM_di_intra_line_cont_th;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    intra_mfilter_angle_range:2;
    unsigned int    intra_mfilter_angle_enable:1;
    unsigned int    intra_ma_mess_enable:1;
    unsigned int    intra_con2interpolationthly_mess:8;
    unsigned int    intra_mfilterthl:8;
    unsigned int    intra_areaedgepixeldiffthly:8;
}IM_di_intra_th;

typedef struct
{
    unsigned int    ma_framehtha:8;
    unsigned int    ma_framemtha:8;
    unsigned int    ma_framestha:8;
    unsigned int    ma_framerlvtha:8;
}IM_di_ma_frame_motion_th_a;

typedef struct
{
    unsigned int    ma_framemthb:8;
    unsigned int    ma_framehthb:8;
    unsigned int    ma_framerlvthb:8;
    unsigned int    ma_framesthb:8;
}IM_di_ma_frame_motion_th_b;

typedef struct
{
    unsigned int    ma_framemthc:8;
    unsigned int    ma_framehthc:8;
    unsigned int    ma_framerlvthc:8;
    unsigned int    ma_framesthc:8;
}IM_di_ma_frame_motion_th_c;

typedef struct
{
    unsigned int    ma_fieldteethstha:8;
    unsigned int    ma_fieldteethmtha:8;
    unsigned int    ma_fieldteethhtha:8;
    unsigned int    ma_fieldteethrlvtha:8;
}IM_di_ma_field_teeth_th_a;

typedef struct
{
    unsigned int    ma_horicomth:8;
    unsigned int    ma_stilllogovdth:8;
    unsigned int    ma_ydiffth:8;
    unsigned int    ma_fieldteeththb:8;
}IM_di_ma_others_th;

typedef struct
{
    unsigned int    ma_sawtoothmth:8;
    unsigned int    ma_sawtoothhth:8;
    unsigned int    ma_sawtoothrlvth:8;
    unsigned int    ma_sawtoothsth:8;
}IM_di_ma_sawtooth_th;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    ma_vertrange:10;
    unsigned int    ma_vertleftstart:10;
    unsigned int    ma_vertrightstart:10;
}IM_di_ma_vertext_th_a;

typedef struct
{
    unsigned int    ma_vertth1:8;
    unsigned int    ma_vertth2:8;
    unsigned int    ma_vertth3:8;
    unsigned int    ma_vertth4:8;
}IM_di_ma_vertext_th_b;

typedef struct
{
    unsigned int    film_leavequick_en:1;
    unsigned int    film_verscrollingtext_en:1;
    unsigned int    film_thumbnail_en:1;
    unsigned int    film_pair1_en:1;
    unsigned int    film_pair2_en:1;
    unsigned int    film_pair_en_auto:1;
    unsigned int    film_violate_strict_en:1;
    unsigned int    reserved_0:1;
    unsigned int    film22_sawtooththl:8;
    unsigned int    film_sawtooththl:8;
    unsigned int    film_frmotionthl:8;
}IM_di_film_sawtooth_filmframe_th;

typedef struct
{
    unsigned int    film_fieldmotionsumthl:8;
    unsigned int    film22_fistaticsthl:8;
    unsigned int    film_frstaticsthl:8;
    unsigned int    film_fistaticsthl:8;
}IM_di_film_static_sum_th;

typedef struct
{
    unsigned int    film_pairratio_all1:4;
    unsigned int    film_pairratio_all2:4;
    unsigned int    film_fiminsthl:8;
    unsigned int    film_fimaxsthl:16;
}IM_di_film_field_judge_th;

typedef struct
{
    unsigned int    film_subfieldmotionsumthl:8;
    unsigned int    film22_subfistaticsthl:8;
    unsigned int    film_subfrstaticsthl:8;
    unsigned int    film_subfistaticsthl:8;
}IM_di_film_static_sum_sub_th;

typedef struct
{
    unsigned int    film_pairratio_sub1:4;
    unsigned int    film_pairratio_sub2:4;
    unsigned int    film_subfiminsthl:8;
    unsigned int    film_subfimaxsthl:16;
}IM_di_film_field_judge_sub_th;

typedef struct
{
    unsigned int    film22_debounce_fieldnum:4;
    unsigned int    film32_debounce_fieldnum:4;
    unsigned int    dummy180240b4_23_16:8;
    unsigned int    film22_subfieldmotionsumthl:8;
    unsigned int    film22_fieldmotionsumthl:8;
}IM_di_film_motion_sum_th;

typedef struct
{
    unsigned int    reserved_0:32;
}RESERVED_0;

typedef struct
{
    unsigned int    reserved_0:32;
}RESERVED_1;

typedef struct
{
    unsigned int    film_hifreq_thl:16;
    unsigned int    film_hifreq_cnt_thl:4;
    unsigned int    film_3d_mode:2;
    unsigned int    reserved_0:1;
    unsigned int    film_motionstatus_choose:1;
    unsigned int    film_hbcounter:8;
}IM_di_si_film_hb_cout;

typedef struct
{
    unsigned int    dummy180240c4_31_9:23;
    unsigned int    film_hifreq_flag:1;
    unsigned int    film_detected:1;
    unsigned int    film_subdetected:1;
    unsigned int    film_confuse:1;
    unsigned int    film_sequence:5;
}IM_di_si_film_final_result;

typedef struct
{
    unsigned int    film_framestatic:8;
    unsigned int    film_framepair:16;
    unsigned int    film_prefistatic1:8;
}IM_di_si_film_pattern_a;

typedef struct
{
    unsigned int    film_nxtfistatic1:8;
    unsigned int    film_prefistatic2:8;
    unsigned int    film_nxtfistatic2:8;
    unsigned int    film_nxtfimotion:8;
}IM_di_si_film_pattern_b;

typedef struct
{
    unsigned int    film_detected321:8;
    unsigned int    film_match321:8;
    unsigned int    film_violate321:8;
    unsigned int    film_sequence321_39_32:8;
}IM_di_si_film_32_result_1_a;

typedef struct
{
    unsigned int    film_sequence321_31_0:32;
}IM_di_si_film_32_result_1_b;

typedef struct
{
    unsigned int    film_detected322:8;
    unsigned int    film_match322:8;
    unsigned int    film_violate322:8;
    unsigned int    film_sequence322_39_32:8;
}IM_di_si_film_32_result_2_a;

typedef struct
{
    unsigned int    film_sequence322_31_0:32;
}IM_di_si_film_32_result_2_b;

typedef struct
{
    unsigned int    film_detected22:8;
    unsigned int    film_match22:8;
    unsigned int    film_violate22:8;
    unsigned int    film_sequence22_39_32:8;
}IM_di_si_film_22_result_a;

typedef struct
{
    unsigned int    film_sequence22_31_0:32;
}IM_di_si_film_22_result_b;

typedef struct
{
    unsigned int    reserved_0:12;
    unsigned int    film_motionstatus_719_700:20;
}IM_di_si_film_motion_next;

typedef struct
{
    unsigned int    reserved_0:12;
    unsigned int    film_motionstatus_699_680:20;
}IM_di_si_film_motion_next_h_t;

typedef struct
{
    unsigned int    reserved_0:12;
    unsigned int    film_motionstatus_679_660:20;
}IM_di_si_film_motion_next_h_m;

typedef struct
{
    unsigned int    reserved_0:12;
    unsigned int    film_motionstatus_659_640:20;
}IM_di_si_film_motion_next_h_b;

typedef struct
{
    unsigned int    reserved_0:12;
    unsigned int    film_motionstatus_639_620:20;
}IM_di_si_film_motion_next_v_l;

typedef struct
{
    unsigned int    reserved_0:12;
    unsigned int    film_motionstatus_619_600:20;
}IM_di_si_film_motion_next_v_m;

typedef struct
{
    unsigned int    reserved_0:12;
    unsigned int    film_motionstatus_599_580:20;
}IM_di_si_film_motion_next_v_r;

typedef struct
{
    unsigned int    reserved_0:12;
    unsigned int    film_motionstatus_579_560:20;
}IM_di_si_film_motion_next_c;

typedef struct
{
    unsigned int    reserved_0:12;
    unsigned int    film_motionstatus_559_540:20;
}IM_di_si_film_motion_pre;

typedef struct
{
    unsigned int    reserved_0:12;
    unsigned int    film_motionstatus_539_520:20;
}IM_di_si_film_motion_pre_h_t;

typedef struct
{
    unsigned int    reserved_0:12;
    unsigned int    film_motionstatus_519_500:20;
}IM_di_si_film_motion_pre_h_m;

typedef struct
{
    unsigned int    reserved_0:12;
    unsigned int    film_motionstatus_499_480:20;
}IM_di_si_film_motion_pre_h_b;

typedef struct
{
    unsigned int    reserved_0:12;
    unsigned int    film_motionstatus_479_460:20;
}IM_di_si_film_motion_pre_v_l;

typedef struct
{
    unsigned int    reserved_0:12;
    unsigned int    film_motionstatus_459_440:20;
}IM_di_si_film_motion_pre_v_m;

typedef struct
{
    unsigned int    reserved_0:12;
    unsigned int    film_motionstatus_439_420:20;
}IM_di_si_film_motion_pre_v_r;

typedef struct
{
    unsigned int    reserved_0:12;
    unsigned int    film_motionstatus_419_400:20;
}IM_di_si_film_motion_pre_c;

typedef struct
{
    unsigned int    reserved_0:12;
    unsigned int    film_motionstatus_399_380:20;
}IM_di_si_film_motion;

typedef struct
{
    unsigned int    reserved_0:12;
    unsigned int    film_motionstatus_379_360:20;
}IM_di_si_film_motion_h_t;

typedef struct
{
    unsigned int    reserved_0:12;
    unsigned int    film_motionstatus_359_340:20;
}IM_di_si_film_motion_h_m;

typedef struct
{
    unsigned int    reserved_0:12;
    unsigned int    film_motionstatus_339_320:20;
}IM_di_si_film_motion_h_b;

typedef struct
{
    unsigned int    reserved_0:12;
    unsigned int    film_motionstatus_319_300:20;
}IM_di_si_film_motion_v_l;

typedef struct
{
    unsigned int    reserved_0:12;
    unsigned int    film_motionstatus_299_280:20;
}IM_di_si_film_motion_v_m;

typedef struct
{
    unsigned int    reserved_0:12;
    unsigned int    film_motionstatus_279_260:20;
}IM_di_si_film_motion_v_r;

typedef struct
{
    unsigned int    reserved_0:12;
    unsigned int    film_motionstatus_259_240:20;
}IM_di_si_film_motion_c;

typedef struct
{
    unsigned int    reserved_0:12;
    unsigned int    film_motionstatus_239_220:20;
}IM_di_si_film_motion_h_11;

typedef struct
{
    unsigned int    reserved_0:12;
    unsigned int    film_motionstatus_219_200:20;
}IM_di_si_film_motion_h_10;

typedef struct
{
    unsigned int    reserved_0:12;
    unsigned int    film_motionstatus_199_180:20;
}IM_di_si_film_motion_h_09;

typedef struct
{
    unsigned int    reserved_0:12;
    unsigned int    film_motionstatus_179_160:20;
}IM_di_si_film_motion_h_08;

typedef struct
{
    unsigned int    reserved_0:12;
    unsigned int    film_motionstatus_159_140:20;
}IM_di_si_film_motion_h_07;

typedef struct
{
    unsigned int    reserved_0:12;
    unsigned int    film_motionstatus_139_120:20;
}IM_di_si_film_motion_h_06;

typedef struct
{
    unsigned int    reserved_0:12;
    unsigned int    film_motionstatus_119_100:20;
}IM_di_si_film_motion_h_05;

typedef struct
{
    unsigned int    reserved_0:12;
    unsigned int    film_motionstatus_99_80:20;
}IM_di_si_film_motion_h_04;

typedef struct
{
    unsigned int    reserved_0:12;
    unsigned int    film_motionstatus_79_60:20;
}IM_di_si_film_motion_h_03;

typedef struct
{
    unsigned int    reserved_0:12;
    unsigned int    film_motionstatus_59_40:20;
}IM_di_si_film_motion_h_02;

typedef struct
{
    unsigned int    reserved_0:12;
    unsigned int    film_motionstatus_39_20:20;
}IM_di_si_film_motion_h_01;

typedef struct
{
    unsigned int    reserved_0:12;
    unsigned int    film_motionstatus_19_0:20;
}IM_di_si_film_motion_h_00;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    total_frame_motion_sum:24;
}IM_di_si_ma_total_fm_sum;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    large_frame_motion_pixel:24;
}IM_di_si_ma_large_fm_pixel;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    large_frame_motion_sum:24;
}IM_di_si_ma_large_fm_sum;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    mess_horizontal_pixel:24;
}IM_di_si_ma_mess_h_pixel;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    cr_subbal_status:3;
    unsigned int    cr_enable_mainbalance:1;
    unsigned int    cr_mean3_status:8;
    unsigned int    cr_mean2_status:8;
    unsigned int    cr_mean1_status:8;
}IM_di_si_image_balance;

typedef struct
{
    unsigned int    reserved_0:14;
    unsigned int    di_crc_ctrl_conti:1;
    unsigned int    di_crc_ctrl_start:1;
    unsigned int    cr_amount_subbalance:16;
}IM_di_si_sub_in_auto_balance;

typedef struct
{
    unsigned int    di_crc_result:32;
}IM_di_crc_result;

typedef struct
{
    unsigned int    newintrainterpolate_vertical_thd:10;
    unsigned int    newintrainterpolate_sumdiff_thd:10;
    unsigned int    newintrainterpolate_pixdiff_thd:8;
    unsigned int    newintrainterpolate_enable:1;
    unsigned int    reserved_0:1;
    unsigned int    cp_partialstill:1;
    unsigned int    cp_partialstillnew:1;
}IM_di_si_still_info_for_ne;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    film22_nxtfistatic1:8;
    unsigned int    film22_nxtfimotion:8;
}IM_di_si_film22_detector_pattern;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    cp_temporalthly:8;
    unsigned int    cp_temporalthlc:8;
}IM_di_tnr_th;

typedef struct
{
    unsigned int    cp_rtnr_interlace_force2d_en:1;
    unsigned int    cp_rtnr_rgb444_enable:1;
    unsigned int    reserved_0:4;
    unsigned int    cp_rtnr_rounding_correction2_errorthd_c:6;
    unsigned int    reserved_1:2;
    unsigned int    cp_rtnr_rounding_correction2_errorthd_y:6;
    unsigned int    reserved_2:1;
    unsigned int    cp_rtnr_rounding_correction2_mode:2;
    unsigned int    cp_rtnr_rounding_correction2_en:1;
    unsigned int    cp_rtnr_updatelockflg:1;
    unsigned int    cp_rtnr_updatelocken:1;
    unsigned int    cp_rtnr_mad_window:2;
    unsigned int    cp_rtnr_rounding_correction:1;
    unsigned int    cp_rtnr_progressive:1;
    unsigned int    cp_rtnr_c_enable:1;
    unsigned int    cp_rtnr_y_enable:1;
}IM_di_rtnr_control;

typedef struct
{
    unsigned int    dummy180241a4_31_0:32;
}IM_di_dummy_0;

typedef struct
{
    unsigned int    dummy180241a8_31_0:32;
}IM_di_dummy_1;

typedef struct
{
    unsigned int    dummy180241ac_31_0:32;
}IM_di_dummy_2;

typedef struct
{
    unsigned int    reserved_0:5;
    unsigned int    cp_temporal_mad_y_th1:11;
    unsigned int    reserved_1:5;
    unsigned int    cp_temporal_mad_y_th2:11;
}IM_di_rtnr_mad_y_th;

typedef struct
{
    unsigned int    reserved_0:5;
    unsigned int    cp_temporal_mad_c_th1:11;
    unsigned int    reserved_1:5;
    unsigned int    cp_temporal_mad_c_th2:11;
}IM_di_rtnr_mad_c_th;

typedef struct
{
    unsigned int    reserved_0:11;
    unsigned int    cp_temporal_mad_countery:21;
}IM_di_rtnr_mad_y_counter;

typedef struct
{
    unsigned int    reserved_0:11;
    unsigned int    cp_temporal_mad_counteru:21;
}IM_di_rtnr_mad_u_counter;

typedef struct
{
    unsigned int    reserved_0:11;
    unsigned int    cp_temporal_mad_counterv:21;
}IM_di_rtnr_mad_v_counter;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    dummy180241c4_15_13:3;
    unsigned int    cp_temporal_num_match_l:4;
    unsigned int    cp_temporal_l_qlfy_th:4;
    unsigned int    cp_temporal_c_k_decision:3;
    unsigned int    cp_temporal_edge_crct_en:1;
    unsigned int    reserved_1:1;
}IM_di_rtnr_ediff_control;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    cp_temporal_sad_offset_y:8;
    unsigned int    cp_temporal_sad_offset_u:8;
    unsigned int    cp_temporal_sad_offset_v:8;
}IM_di_rtnr_sad_offset;

typedef struct
{
    unsigned int    cp_temporal_e_th1_y:8;
    unsigned int    cp_temporal_e_th2_y:8;
    unsigned int    cp_temporal_e_th1_c:8;
    unsigned int    cp_temporal_e_th2_c:8;
}IM_di_rtnr_ediff_th;

typedef struct
{
    unsigned int    dummy180241d0_31_22:10;
    unsigned int    cp_temporal_sbl_thm_y:10;
    unsigned int    dummy180241d0_11_10:2;
    unsigned int    cp_temporal_sbl_ths_y:10;
}IM_di_rtnr_ediff_sobel_th;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    cp_temporal_nl_up_bnd_y:8;
    unsigned int    cp_temporal_nl_low_bnd_y:8;
}IM_di_rtnr_level_bound;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    cp_temporal_same_et_cnt_y:24;
}IM_di_rtnr_et_count_y;

typedef struct
{
    unsigned int    cp_temporal_same_et_sad_sum_y:32;
}IM_di_rtnr_et_sum_y;

typedef struct
{
    unsigned int    cp_temporal_same_et_sad_sum_u:32;
}IM_di_rtnr_et_sum_u;

typedef struct
{
    unsigned int    cp_temporal_same_et_sad_sum_v:32;
}IM_di_rtnr_et_sum_v;

typedef struct
{
    unsigned int    set_sobeledgetypeen:1;
    unsigned int    set_stillmotion_tha:4;
    unsigned int    set_stillmotion_thb:4;
    unsigned int    set_stillmotion_thc:4;
    unsigned int    set_classifysmooth:3;
    unsigned int    set_frame_offset_verystill:4;
    unsigned int    set_frame_offset_still:3;
    unsigned int    set_frame_offset_motion:3;
    unsigned int    set_frame_offset_verymotion:4;
    unsigned int    cp_temporal_xc_switch:1;
    unsigned int    cp_temporal_xc_en:1;
}IM_di_tnr_xc_control;

typedef struct
{
    unsigned int    set_sobeledgetype_sel:2;
    unsigned int    reserved_0:5;
    unsigned int    hfd_highfrequencydetectoren:1;
    unsigned int    hfd_highlowhighdiff_thl:8;
    unsigned int    reserved_1:4;
    unsigned int    hfd_highlowhighdiff_count_thl:4;
    unsigned int    reserved_2:3;
    unsigned int    hfd_manyteethareastilllogoen:1;
    unsigned int    hfd_3x3blockteethcount_thl:4;
}IM_di_hfd_control;

typedef struct
{
    unsigned int    hfd_checklinemotioncounten:1;
    unsigned int    hfd_framekcombineoflinemotion:2;
    unsigned int    reserved_0:2;
    unsigned int    hfd_linemotioncount_thl2:11;
    unsigned int    reserved_1:5;
    unsigned int    hfd_linemotioncount_thl:11;
}IM_di_hfd_line_motion_count;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    hfd_statistic:24;
}IM_di_hfd_statistic;

typedef struct
{
    unsigned int    reserved_0:3;
    unsigned int    hmc_window_en:1;
    unsigned int    hmc_window_top:10;
    unsigned int    hmc_window_bot:10;
    unsigned int    ma_teeth_cont_check_dma_en:1;
    unsigned int    ma_teeth_cont_filter_en:1;
    unsigned int    ma_teeth_cont_check_en:2;
    unsigned int    ma_teeth_cont_check_th:2;
    unsigned int    stilllogolrcorrectionen:1;
    unsigned int    stilllogoweavelineen:1;
}IM_di_hfd_ma_error_recovery;

typedef struct
{
    unsigned int    newintralowangle_continuous_pt:7;
    unsigned int    newintralowangle_precur_diff_thd:10;
    unsigned int    newintralowangle_vercur_diff_thd:10;
    unsigned int    newintralowangle_left_dir:2;
    unsigned int    newintralowangle_right_dir:2;
    unsigned int    newintralowangle_enable:1;
}IM_di_new_intra_low_angle;

typedef struct
{
    unsigned int    intranewgracorr_transpt_thd:8;
    unsigned int    intranewgracorr_gradmatchmin_thd:8;
    unsigned int    intranewgracorr_gradmatchdiff_thd:8;
    unsigned int    intranewgracorr_mintransrange:4;
    unsigned int    intranewgracorr_minmatchdifftransrange:4;
}IM_di_intra_new_gradient_correct;

typedef struct
{
    unsigned int    intranewgracorr_enable:1;
    unsigned int    intranewgracorr_doublecheck_enable:1;
    unsigned int    intra_lowangle_lpf_enable:1;
    unsigned int    intra_averagefilter_enable:1;
    unsigned int    intra_range_correct_interpolation_enable:1;
    unsigned int    reserved_0:7;
    unsigned int    intranewgracorr_transptcenter_thd:8;
    unsigned int    intra_areacorner_intrarange_correct_enable:1;
    unsigned int    reserved_1:1;
    unsigned int    intra_lowangle_lpf_diffthd:10;
}IM_di_intra_post_process;

typedef struct
{
    unsigned int    reserved_0:5;
    unsigned int    btr_hmc_blendchoose:1;
    unsigned int    btr_blendtemporaldebugmode:2;
    unsigned int    reserved_1:1;
    unsigned int    btr_solb_cur1_count:3;
    unsigned int    reserved_2:1;
    unsigned int    btr_solb_cur0_count:3;
    unsigned int    reserved_3:1;
    unsigned int    btr_solb_temporallength:3;
    unsigned int    reserved_4:2;
    unsigned int    btr_blendtemporalrecovery_dma_en:1;
    unsigned int    btr_sola_method0_blendtype:1;
    unsigned int    btr_sola_method0_successtime:3;
    unsigned int    btr_sola_method:1;
    unsigned int    btr_sola_temporallength:2;
    unsigned int    btr_solutiontype:1;
    unsigned int    btr_blendtemporalrecoveryen:1;
}IM_di_btr_control;

typedef struct
{
    unsigned int    btr_sola_method0_cur1_pre4_max:2;
    unsigned int    btr_sola_method0_cur1_pre4_min:2;
    unsigned int    btr_sola_method0_cur1_pre3_max:2;
    unsigned int    btr_sola_method0_cur1_pre3_min:2;
    unsigned int    btr_sola_method0_cur1_pre2_max:2;
    unsigned int    btr_sola_method0_cur1_pre2_min:2;
    unsigned int    btr_sola_method0_cur1_pre1_max:2;
    unsigned int    btr_sola_method0_cur1_pre1_min:2;
    unsigned int    btr_sola_method0_cur0_pre4_max:2;
    unsigned int    btr_sola_method0_cur0_pre4_min:2;
    unsigned int    btr_sola_method0_cur0_pre3_max:2;
    unsigned int    btr_sola_method0_cur0_pre3_min:2;
    unsigned int    btr_sola_method0_cur0_pre2_max:2;
    unsigned int    btr_sola_method0_cur0_pre2_min:2;
    unsigned int    btr_sola_method0_cur0_pre1_max:2;
    unsigned int    btr_sola_method0_cur0_pre1_min:2;
}IM_di_btr_sola_method0_min_max;

typedef struct
{
    unsigned int    intra_areacorner_intrarange_correct_peak_thd:8;
    unsigned int    btr_longweavesum:24;
}IM_di_btr_longweave_statistic;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    ber_lowpasssum:24;
}IM_di_ber_lowpass_statistic;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    ber_closeclevel_max:8;
    unsigned int    reserved_1:4;
    unsigned int    ber_closeclevel_min:8;
    unsigned int    ber_blendspatial_lpf_blendingtype:1;
    unsigned int    ber_blendspatial_lpf_stilllogo:1;
    unsigned int    ber_blendspatialclassify:1;
    unsigned int    ber_blendspatialrecoveryen:1;
}IM_di_ber_spatial_control;

typedef struct
{
    unsigned int    reserved_0:6;
    unsigned int    ber_diffylevel_max:10;
    unsigned int    reserved_1:6;
    unsigned int    ber_diffylevel_min:10;
}IM_di_ber_spatial_diffy;

typedef struct
{
    unsigned int    ber_totalcontinuesum:24;
    unsigned int    ber_spatialcontinuelength:4;
    unsigned int    ber_blendtemporaltype:1;
    unsigned int    ber_blendtemporalblock:2;
    unsigned int    ber_blendtemporalrevoeryen:1;
}IM_di_ber_temporal_control;

typedef struct
{
    unsigned int    intra_lpattern_flat_rldiff_th:8;
    unsigned int    intra_lpattern_flat_cendiff_th:8;
    unsigned int    intra_lpattern_flat_wholediff_th:8;
    unsigned int    intra_lpattern_rough_diff_th:8;
}IM_di_intra_l_cross_pat_det_th1;

typedef struct
{
    unsigned int    intra_lpattern_rough_flat_diff_th:8;
    unsigned int    intra_lpattern_vdiff_th:8;
    unsigned int    intra_lpattern_vdev_lowbound_th:8;
    unsigned int    intra_lpattern_vdev_highbound_th:8;
}IM_di_intra_l_cross_pat_det_th2;

typedef struct
{
    unsigned int    intra_lpattern_cen_pixdiff_th:8;
    unsigned int    reserved_0:19;
    unsigned int    intra_lpattern_dir_pk_enable:1;
    unsigned int    intra_lpattern_rough_ratio:3;
    unsigned int    intra_lpattern_enable:1;
}IM_di_intra_l_cross_pat_det_ctl;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    cp_noiseesthorend:12;
    unsigned int    reserved_1:4;
    unsigned int    cp_noiseesthorstart:12;
}NOISEEST_hor_range;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    cp_noiseestverend:12;
    unsigned int    reserved_1:4;
    unsigned int    cp_noiseestverstart:12;
}NOISEEST_ver_range;

typedef struct
{
    unsigned int    reserved_0:32;
}IM_di_dummy_3;

typedef struct
{
    unsigned int    dummy1802423c_31_0:32;
}IM_di_dummy_4;

typedef struct
{
    unsigned int    cp_histthl1:8;
    unsigned int    cp_histthl2:8;
    unsigned int    reserved_0:2;
    unsigned int    subsamplingmode:2;
    unsigned int    reserved_1:1;
    unsigned int    cp_histhoroffset:3;
    unsigned int    reserved_2:1;
    unsigned int    cp_histveroffset:3;
    unsigned int    reserved_3:3;
    unsigned int    cp_histveren:1;
}MPEG_hist_blking;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    cp_cntver1:12;
    unsigned int    reserved_1:4;
    unsigned int    cp_cntver0:12;
}CNTVER0;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    cp_cntver3:12;
    unsigned int    reserved_1:4;
    unsigned int    cp_cntver2:12;
}CNTVER2;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    cp_cntver5:12;
    unsigned int    reserved_1:4;
    unsigned int    cp_cntver4:12;
}CNTVER4;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    cp_cntver7:12;
    unsigned int    reserved_1:4;
    unsigned int    cp_cntver6:12;
}CNTVER6;

typedef struct
{
    unsigned int    cp_mpglowerbound:8;
    unsigned int    cp_mpgupperbound:8;
    unsigned int    reserved_0:3;
    unsigned int    cp_mpglpmode:1;
    unsigned int    reserved_1:1;
    unsigned int    cp_mpgidx_y:3;
    unsigned int    reserved_2:1;
    unsigned int    cp_mpegresultweight_y:3;
    unsigned int    cp_mpgidxmode_y:2;
    unsigned int    cp_mpegenable_y_c:1;
    unsigned int    cp_mpegenable_y_y:1;
}MPEGNR1;

typedef struct
{
    unsigned int    reserved_0:12;
    unsigned int    pib_film_all:1;
    unsigned int    pib_film_h_t:1;
    unsigned int    pib_film_h_m:1;
    unsigned int    pib_film_h_b:1;
    unsigned int    pib_film_v_l:1;
    unsigned int    pib_film_v_m:1;
    unsigned int    pib_film_v_r:1;
    unsigned int    pib_film_c:1;
    unsigned int    pib_film_h_11:1;
    unsigned int    pib_film_h_10:1;
    unsigned int    pib_film_h_09:1;
    unsigned int    pib_film_h_08:1;
    unsigned int    pib_film_h_07:1;
    unsigned int    pib_film_h_06:1;
    unsigned int    pib_film_h_05:1;
    unsigned int    pib_film_h_04:1;
    unsigned int    pib_film_h_03:1;
    unsigned int    pib_film_h_02:1;
    unsigned int    pib_film_h_01:1;
    unsigned int    pib_film_h_00:1;
}IM_di_pib_control;

typedef struct
{
    unsigned int    pib_film_all_th:16;
    unsigned int    pib_film_cen_all:16;
}IM_di_pib_all_cen_th;

typedef struct
{
    unsigned int    pib_film_h_th:16;
    unsigned int    pib_film_v_th:16;
}IM_di_pib_h_v_th;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    pib_film_h00_h11_th:16;
}IM_di_pib_h00_h11_th;

typedef struct
{
    unsigned int    reserved_0:3;
    unsigned int    prgfilm_32_detect_num:5;
    unsigned int    reserved_1:3;
    unsigned int    prgfilm_22_detect_num:5;
    unsigned int    reserved_2:2;
    unsigned int    prgfilm_motion_th:8;
    unsigned int    prgfilm_debug:1;
    unsigned int    prgfilm_motion_cnt_avg_auto:1;
    unsigned int    prgfilm_32_auto:1;
    unsigned int    prgfilm_22_auto:1;
    unsigned int    prgfilm_32_en:1;
    unsigned int    prgfilm_22_en:1;
}DI_p_film_ctrl0;

typedef struct
{
    unsigned int    reserved_0:3;
    unsigned int    prgfilm_fw_32_detected:1;
    unsigned int    prgfilm_fw_22_detected:1;
    unsigned int    prgfilm_fw_film_idx:5;
    unsigned int    prgfilm_fw_motion_cnt_avg:22;
}DI_p_film_ctrl1;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    prgfilm_32_detected:1;
    unsigned int    prgfilm_22_detected:1;
    unsigned int    reserved_1:1;
    unsigned int    prgfilm_film_idx:5;
    unsigned int    prgfilm_motion_cnt:22;
}DI_p_film_read;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    hmc_lstatistic:10;
    unsigned int    hmc_rstatistic:10;
    unsigned int    hmc_startline:10;
}IM_di_hmc_3a;

typedef struct
{
    unsigned int    reserved_0:25;
    unsigned int    hmc_mvth2:3;
    unsigned int    reserved_1:1;
    unsigned int    hmc_mvth1:3;
}IM_di_hmc_statistic_th;

typedef struct
{
    unsigned int    hmc_lb_pixelsum:16;
    unsigned int    hmc_rb_pixelsum:16;
}IM_di_hmc_statistic1;

typedef struct
{
    unsigned int    hmc_lm_pixelsum:16;
    unsigned int    hmc_rm_pixelsum:16;
}IM_di_hmc_statistic2;

typedef struct
{
    unsigned int    hmc_ls_pixelsum:16;
    unsigned int    hmc_rs_pixelsum:16;
}IM_di_hmc_statistic3;

typedef struct
{
    unsigned int    framesobel_en:1;
    unsigned int    framesobel_hedge_count:7;
    unsigned int    reserved_0:5;
    unsigned int    framesobel_hedge_length:3;
    unsigned int    framesobel_gradi_h_th:8;
    unsigned int    framesobel_gradi_v_th:8;
}IM_di_framesobel_ctrl;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    framesobel_hedge_count_sta:7;
    unsigned int    chromaerror_framemotionc_th:8;
    unsigned int    framesobel_gradi_h_th_sta:8;
    unsigned int    framesobel_gradi_v_th_sta:8;
}IM_di_framesobel_statistic_ctrl;

typedef struct
{
    unsigned int    chromaerror_en:1;
    unsigned int    chromaerror_all:1;
    unsigned int    reserved_0:1;
    unsigned int    chromaerror_th:5;
    unsigned int    framesobel_hedge_statistic:24;
}IM_di_framesobel_statistic;

typedef struct
{
    unsigned int    tnrxc_mkii_thc2:8;
    unsigned int    tnrxc_mkii_thc1:8;
    unsigned int    tnrxc_mkii_thy:8;
    unsigned int    dummy180242a0_7_2:6;
    unsigned int    tnrxc_dbguvmode:1;
    unsigned int    tnrxc_mkii_en:1;
}TNRXC_mkii_ctrl;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    cp_temporal_y_kout_dark_2:3;
    unsigned int    reserved_1:1;
    unsigned int    cp_temporal_y_kin_dark_2:3;
    unsigned int    cp_temporal_y_dark_th:8;
    unsigned int    reserved_2:5;
    unsigned int    cp_temporal_y_kout_dark:3;
    unsigned int    reserved_3:1;
    unsigned int    cp_temporal_y_kin_dark:3;
    unsigned int    reserved_4:3;
    unsigned int    cp_temporal_y_dark_k_en:1;
}IM_di_rtnr_k_dark;

typedef struct
{
    unsigned int    dummy180242a8_31_29:3;
    unsigned int    rtnr_refined_c_en:1;
    unsigned int    rtnr_th_localedgediff:12;
    unsigned int    rtnr_stilledge_debug:1;
    unsigned int    rtnr_stilledge_bonusbias:3;
    unsigned int    rtnr_localedge_debug:1;
    unsigned int    rtnr_act_bias:3;
    unsigned int    dummy180242a8_7:1;
    unsigned int    rtnr_crct_bias:3;
    unsigned int    rtnr_crct_debug:1;
    unsigned int    rtnr_stilledge_en:1;
    unsigned int    rtnr_localedge_en:1;
    unsigned int    rtnr_new_formula_en:1;
}IM_di_rtnr_refined_ctrl;

typedef struct
{
    unsigned int    dummy180242ac_31_17:15;
    unsigned int    rtnr_stilledge_th_edgdiff:9;
    unsigned int    rtnr_stilledge_th_edg:8;
}IM_di_rtnr_refined_ctrl2;

typedef struct
{
    unsigned int    cp_temporalthly3:8;
    unsigned int    cp_temporalthly2:8;
    unsigned int    cp_temporalthly1:8;
    unsigned int    cp_temporalthly0:8;
}IM_di_rtnr_y_th0_th3;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    cp_temporalthly6:8;
    unsigned int    cp_temporalthly5:8;
    unsigned int    cp_temporalthly4:8;
}IM_di_rtnr_y_th4_th6;

typedef struct
{
    unsigned int    cp_temporalthlc3:8;
    unsigned int    cp_temporalthlc2:8;
    unsigned int    cp_temporalthlc1:8;
    unsigned int    cp_temporalthlc0:8;
}IM_di_rtnr_c_th0_th3;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    cp_temporalthlc6:8;
    unsigned int    cp_temporalthlc5:8;
    unsigned int    cp_temporalthlc4:8;
}IM_di_rtnr_c_th4_th6;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    cp_temporal_y_k7:3;
    unsigned int    reserved_1:1;
    unsigned int    cp_temporal_y_k6:3;
    unsigned int    reserved_2:1;
    unsigned int    cp_temporal_y_k5:3;
    unsigned int    reserved_3:1;
    unsigned int    cp_temporal_y_k4:3;
    unsigned int    reserved_4:1;
    unsigned int    cp_temporal_y_k3:3;
    unsigned int    reserved_5:1;
    unsigned int    cp_temporal_y_k2:3;
    unsigned int    reserved_6:1;
    unsigned int    cp_temporal_y_k1:3;
    unsigned int    reserved_7:1;
    unsigned int    cp_temporal_y_k0:3;
}IM_di_rtnr_y_k;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    cp_temporal_c_k7:3;
    unsigned int    reserved_1:1;
    unsigned int    cp_temporal_c_k6:3;
    unsigned int    reserved_2:1;
    unsigned int    cp_temporal_c_k5:3;
    unsigned int    reserved_3:1;
    unsigned int    cp_temporal_c_k4:3;
    unsigned int    reserved_4:1;
    unsigned int    cp_temporal_c_k3:3;
    unsigned int    reserved_5:1;
    unsigned int    cp_temporal_c_k2:3;
    unsigned int    reserved_6:1;
    unsigned int    cp_temporal_c_k1:3;
    unsigned int    reserved_7:1;
    unsigned int    cp_temporal_c_k0:3;
}IM_di_rtnr_c_k;

typedef struct
{
    unsigned int    reserved_0:23;
    unsigned int    cp_temporal_y_k_decision:1;
    unsigned int    reserved_1:1;
    unsigned int    cp_temporal_ediff_en6:1;
    unsigned int    cp_temporal_ediff_en5:1;
    unsigned int    cp_temporal_ediff_en4:1;
    unsigned int    cp_temporal_ediff_en3:1;
    unsigned int    cp_temporal_ediff_en2:1;
    unsigned int    cp_temporal_ediff_en1:1;
    unsigned int    cp_temporal_ediff_en0:1;
}IM_di_rtnr_ediff_enable;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    rtnr_debugmode:4;
    unsigned int    reserved_1:1;
    unsigned int    rtnr_moredetail_cotinue_en:1;
    unsigned int    rtnr_k_temporal_compare_snr:1;
    unsigned int    rtnr_k_temporal_compare_en:1;
    unsigned int    rtnr_statistic_motion_sad_th:8;
    unsigned int    rtnr_sad_mix_cal_weight:4;
    unsigned int    reserved_2:1;
    unsigned int    rtnr_sad_method:2;
    unsigned int    rtnr_new_method_en:1;
}IM_di_rtnr_new_control;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    rtnr_sobel_method:2;
    unsigned int    rtnr_sbl_thm_y:10;
    unsigned int    reserved_1:2;
    unsigned int    rtnr_sbl_ths_y:10;
}IM_di_rtnr_new_sobel_th;

typedef struct
{
    unsigned int    rtnr_calculate_motion_sad_edge_th4:8;
    unsigned int    rtnr_calculate_motion_sad_edge_th3:8;
    unsigned int    rtnr_calculate_motion_sad_edge_th2:8;
    unsigned int    rtnr_calculate_motion_sad_edge_th1:8;
}IM_di_rtnr_new_sad_edge_th_1;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    rtnr_calculate_motion_sad_edge_th7:8;
    unsigned int    rtnr_calculate_motion_sad_edge_th6:8;
    unsigned int    rtnr_calculate_motion_sad_edge_th5:8;
}IM_di_rtnr_new_sad_edge_th_2;

typedef struct
{
    unsigned int    rtnr_calculate_motion_sad_nonedge_th4:8;
    unsigned int    rtnr_calculate_motion_sad_nonedge_th3:8;
    unsigned int    rtnr_calculate_motion_sad_nonedge_th2:8;
    unsigned int    rtnr_calculate_motion_sad_nonedge_th1:8;
}IM_di_rtnr_new_sad_nonedge_th_1;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    rtnr_calculate_motion_sad_nonedge_th7:8;
    unsigned int    rtnr_calculate_motion_sad_nonedge_th6:8;
    unsigned int    rtnr_calculate_motion_sad_nonedge_th5:8;
}IM_di_rtnr_new_sad_nonedge_th_2;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    rtnr_statistic_motion_count_th7:4;
    unsigned int    rtnr_statistic_motion_count_th6:4;
    unsigned int    rtnr_statistic_motion_count_th5:4;
    unsigned int    rtnr_statistic_motion_count_th4:4;
    unsigned int    rtnr_statistic_motion_count_th3:4;
    unsigned int    rtnr_statistic_motion_count_th2:4;
    unsigned int    rtnr_statistic_motion_count_th1:4;
}IM_di_rtnr_new_sad_count_th;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    rtnr_edgetypediff_count_th4:6;
    unsigned int    reserved_1:2;
    unsigned int    rtnr_edgetypediff_count_th3:6;
    unsigned int    reserved_2:2;
    unsigned int    rtnr_edgetypediff_count_th2:6;
    unsigned int    reserved_3:2;
    unsigned int    rtnr_edgetypediff_count_th1:6;
}IM_di_rtnr_new_edgetypediff_th_1;

typedef struct
{
    unsigned int    reserved_0:10;
    unsigned int    rtnr_edgetypediff_count_th7:6;
    unsigned int    reserved_1:2;
    unsigned int    rtnr_edgetypediff_count_th6:6;
    unsigned int    reserved_2:2;
    unsigned int    rtnr_edgetypediff_count_th5:6;
}IM_di_rtnr_new_edgetypediff_th_2;

typedef struct
{
    unsigned int    reserved_0:11;
    unsigned int    rtnr_snr_mask:1;
    unsigned int    rtnr_snr_result_offset:3;
    unsigned int    rtnr_snr_result_offset_invert_en:1;
    unsigned int    rtnr_snr_result_motion_weight:4;
    unsigned int    rtnr_snr_result_edgestatus_weight:4;
    unsigned int    reserved_1:2;
    unsigned int    rtnr_snr_result_motion_invert_en:1;
    unsigned int    rtnr_snr_result_edgestatus_invert_en:1;
    unsigned int    rtnr_snr_sobel_3_en:1;
    unsigned int    rtnr_snr_sobel_2_en:1;
    unsigned int    rtnr_snr_sobel_1_en:1;
    unsigned int    rtnr_snr_en:1;
}IM_di_rtnr_new_snr_control;

typedef struct
{
    unsigned int    rtnr_snr_edgestatus_th4:8;
    unsigned int    rtnr_snr_edgestatus_th3:8;
    unsigned int    rtnr_snr_edgestatus_th2:8;
    unsigned int    rtnr_snr_edgestatus_th1:8;
}IM_di_rtnr_new_snr_th_1;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    rtnr_snr_edgestatus_th7:8;
    unsigned int    rtnr_snr_edgestatus_th6:8;
    unsigned int    rtnr_snr_edgestatus_th5:8;
}IM_di_rtnr_new_snr_th2;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    rtnr_k_07:3;
    unsigned int    reserved_1:1;
    unsigned int    rtnr_k_06:3;
    unsigned int    reserved_2:1;
    unsigned int    rtnr_k_05:3;
    unsigned int    reserved_3:1;
    unsigned int    rtnr_k_04:3;
    unsigned int    reserved_4:1;
    unsigned int    rtnr_k_03:3;
    unsigned int    reserved_5:1;
    unsigned int    rtnr_k_02:3;
    unsigned int    reserved_6:1;
    unsigned int    rtnr_k_01:3;
    unsigned int    reserved_7:1;
    unsigned int    rtnr_k_00:3;
}IM_di_rtnr_new_k_00;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    rtnr_k_17:3;
    unsigned int    reserved_1:1;
    unsigned int    rtnr_k_16:3;
    unsigned int    reserved_2:1;
    unsigned int    rtnr_k_15:3;
    unsigned int    reserved_3:1;
    unsigned int    rtnr_k_14:3;
    unsigned int    reserved_4:1;
    unsigned int    rtnr_k_13:3;
    unsigned int    reserved_5:1;
    unsigned int    rtnr_k_12:3;
    unsigned int    reserved_6:1;
    unsigned int    rtnr_k_11:3;
    unsigned int    reserved_7:1;
    unsigned int    rtnr_k_10:3;
}IM_di_rtnr_new_k_10;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    rtnr_k_27:3;
    unsigned int    reserved_1:1;
    unsigned int    rtnr_k_26:3;
    unsigned int    reserved_2:1;
    unsigned int    rtnr_k_25:3;
    unsigned int    reserved_3:1;
    unsigned int    rtnr_k_24:3;
    unsigned int    reserved_4:1;
    unsigned int    rtnr_k_23:3;
    unsigned int    reserved_5:1;
    unsigned int    rtnr_k_22:3;
    unsigned int    reserved_6:1;
    unsigned int    rtnr_k_21:3;
    unsigned int    reserved_7:1;
    unsigned int    rtnr_k_20:3;
}IM_di_rtnr_new_k_20;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    rtnr_k_37:3;
    unsigned int    reserved_1:1;
    unsigned int    rtnr_k_36:3;
    unsigned int    reserved_2:1;
    unsigned int    rtnr_k_35:3;
    unsigned int    reserved_3:1;
    unsigned int    rtnr_k_34:3;
    unsigned int    reserved_4:1;
    unsigned int    rtnr_k_33:3;
    unsigned int    reserved_5:1;
    unsigned int    rtnr_k_32:3;
    unsigned int    reserved_6:1;
    unsigned int    rtnr_k_31:3;
    unsigned int    reserved_7:1;
    unsigned int    rtnr_k_30:3;
}IM_di_rtnr_new_k_30;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    rtnr_k_47:3;
    unsigned int    reserved_1:1;
    unsigned int    rtnr_k_46:3;
    unsigned int    reserved_2:1;
    unsigned int    rtnr_k_45:3;
    unsigned int    reserved_3:1;
    unsigned int    rtnr_k_44:3;
    unsigned int    reserved_4:1;
    unsigned int    rtnr_k_43:3;
    unsigned int    reserved_5:1;
    unsigned int    rtnr_k_42:3;
    unsigned int    reserved_6:1;
    unsigned int    rtnr_k_41:3;
    unsigned int    reserved_7:1;
    unsigned int    rtnr_k_40:3;
}IM_di_rtnr_new_k_40;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    rtnr_k_57:3;
    unsigned int    reserved_1:1;
    unsigned int    rtnr_k_56:3;
    unsigned int    reserved_2:1;
    unsigned int    rtnr_k_55:3;
    unsigned int    reserved_3:1;
    unsigned int    rtnr_k_54:3;
    unsigned int    reserved_4:1;
    unsigned int    rtnr_k_53:3;
    unsigned int    reserved_5:1;
    unsigned int    rtnr_k_52:3;
    unsigned int    reserved_6:1;
    unsigned int    rtnr_k_51:3;
    unsigned int    reserved_7:1;
    unsigned int    rtnr_k_50:3;
}IM_di_rtnr_new_k_50;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    rtnr_k_67:3;
    unsigned int    reserved_1:1;
    unsigned int    rtnr_k_66:3;
    unsigned int    reserved_2:1;
    unsigned int    rtnr_k_65:3;
    unsigned int    reserved_3:1;
    unsigned int    rtnr_k_64:3;
    unsigned int    reserved_4:1;
    unsigned int    rtnr_k_63:3;
    unsigned int    reserved_5:1;
    unsigned int    rtnr_k_62:3;
    unsigned int    reserved_6:1;
    unsigned int    rtnr_k_61:3;
    unsigned int    reserved_7:1;
    unsigned int    rtnr_k_60:3;
}IM_di_rtnr_new_k_60;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    rtnr_k_77:3;
    unsigned int    reserved_1:1;
    unsigned int    rtnr_k_76:3;
    unsigned int    reserved_2:1;
    unsigned int    rtnr_k_75:3;
    unsigned int    reserved_3:1;
    unsigned int    rtnr_k_74:3;
    unsigned int    reserved_4:1;
    unsigned int    rtnr_k_73:3;
    unsigned int    reserved_5:1;
    unsigned int    rtnr_k_72:3;
    unsigned int    reserved_6:1;
    unsigned int    rtnr_k_71:3;
    unsigned int    reserved_7:1;
    unsigned int    rtnr_k_70:3;
}IM_di_rtnr_new_k_70;

typedef struct
{
    unsigned int    reg_vc_nr_mask1_yref:6;
    unsigned int    reserved_0:2;
    unsigned int    reg_vc_nr_mask1_uref:6;
    unsigned int    reserved_1:2;
    unsigned int    reg_vc_nr_mask1_vref:6;
    unsigned int    reserved_2:4;
    unsigned int    rtnr_mask1_ygain:2;
    unsigned int    rtnr_mask1_ugain:2;
    unsigned int    rtnr_mask1_vgain:2;
}IM_di_rtnr_new_mask1_ctrl1;

typedef struct
{
    unsigned int    reserved_0:13;
    unsigned int    rtnr_mask1_maplimit:3;
    unsigned int    rtnr_mask1_mapthre:4;
    unsigned int    reserved_1:1;
    unsigned int    rtnr_mask1_mapstep:3;
    unsigned int    reserved_2:3;
    unsigned int    rtnr_mask1_dir:1;
    unsigned int    reserved_3:3;
    unsigned int    rtnr_mask1_en:1;
}IM_di_rtnr_new_mask1_ctrl2;

typedef struct
{
    unsigned int    reg_vc_nr_mask2_yref:6;
    unsigned int    reserved_0:2;
    unsigned int    reg_vc_nr_mask2_uref:6;
    unsigned int    reserved_1:2;
    unsigned int    reg_vc_nr_mask2_vref:6;
    unsigned int    reserved_2:4;
    unsigned int    rtnr_mask2_ygain:2;
    unsigned int    rtnr_mask2_ugain:2;
    unsigned int    rtnr_mask2_vgain:2;
}IM_di_rtnr_new_mask2_ctrl1;

typedef struct
{
    unsigned int    reserved_0:13;
    unsigned int    rtnr_mask2_maplimit:3;
    unsigned int    rtnr_mask2_mapthre:4;
    unsigned int    reserved_1:1;
    unsigned int    rtnr_mask2_mapstep:3;
    unsigned int    reserved_2:3;
    unsigned int    rtnr_mask2_dir:1;
    unsigned int    reserved_3:3;
    unsigned int    rtnr_mask2_en:1;
}IM_di_rtnr_new_mask2_ctrl2;

typedef struct
{
    unsigned int    bist_rst:1;
    unsigned int    bist_en:1;
    unsigned int    reserved_0:1;
    unsigned int    bist_done:5;
    unsigned int    bist_fail:24;
}IM_di_si_bist_bisr_info;

typedef struct
{
    unsigned int    reserved_0:3;
    unsigned int    drf_bist_done:5;
    unsigned int    drf_bist_fail:24;
}IM_di_si_bist_drf_info_1;

typedef struct
{
    unsigned int    reserved_0:27;
    unsigned int    drf_start_pause:5;
}IM_di_si_bist_drf_info_2;

typedef struct
{
    unsigned int    reserved_0:17;
    unsigned int    drf_test_resume_di:1;
    unsigned int    drf_bist_en_di:1;
    unsigned int    dvse_di:1;
    unsigned int    dvs_di:4;
    unsigned int    reserved_1:1;
    unsigned int    drf_test_resume_linebuffer:1;
    unsigned int    drf_bist_en_linebuffer:1;
    unsigned int    dvse_linebuffer:1;
    unsigned int    dvs_linebuffer:4;
}IM_di_si_bist_drf_ctrl;

typedef struct
{
    unsigned int    reserved_0:5;
    unsigned int    bisr_so_1:7;
    unsigned int    reserved_1:5;
    unsigned int    bisr_so_0:7;
    unsigned int    bisr_hold_remap:1;
    unsigned int    bisr_cmp_rst:1;
    unsigned int    bisr_run_rst:1;
    unsigned int    bisr_run:1;
    unsigned int    reserved_2:3;
    unsigned int    bisr_repaired:1;
}IM_di_si_bisr_control;

typedef struct
{
    unsigned int    reserved_0:13;
    unsigned int    drf_bisr_mode_2to1:1;
    unsigned int    drf_bisr_rst_2to1:1;
    unsigned int    drf_bisr_resume_2to1:1;
    unsigned int    reserved_1:3;
    unsigned int    dvse_1_2to1:1;
    unsigned int    dvs_1_2to1:4;
    unsigned int    reserved_2:3;
    unsigned int    dvse_0_2to1:1;
    unsigned int    dvs_0_2to1:4;
}IM_di_si_bisr_drf_ctrl;
#endif


#define IM_DI_CONTROL                                                 0x18024000
#define IM_DI_CONTROL_reg_addr                                        "0xb8024000"
#define IM_DI_CONTROL_reg                                             0xb8024000
#define IM_DI_CONTROL_inst_addr                                       "0x0000"
#define IM_DI_CONTROL_inst                                            0x0000
#define IM_DI_CONTROL_film_sawtooth_choose_shift                      (30)
#define IM_DI_CONTROL_film22_filter_andor_shift                       (29)
#define IM_DI_CONTROL_ip_enable_shift                                 (28)
#define IM_DI_CONTROL_di444to422lowpass_shift                         (27)
#define IM_DI_CONTROL_cp_tresultweight_shift                          (24)
#define IM_DI_CONTROL_cp_temporalenable_shift                         (23)
#define IM_DI_CONTROL_intra_lowangleenable_shift                      (22)
#define IM_DI_CONTROL_intra_stage1enable_shift                        (21)
#define IM_DI_CONTROL_intra_stage2enable_shift                        (20)
#define IM_DI_CONTROL_intra_mfilterenable_shift                       (19)
#define IM_DI_CONTROL_intra_interpolationrange_shift                  (15)
#define IM_DI_CONTROL_film_enable_shift                               (10)
#define IM_DI_CONTROL_ma_vertexten_shift                              (9)
#define IM_DI_CONTROL_ma_horicomen_shift                              (8)
#define IM_DI_CONTROL_ma_stilllogoena_shift                           (7)
#define IM_DI_CONTROL_ma_smoothintra90_shift                          (6)
#define IM_DI_CONTROL_ma_messintra90_shift                            (5)
#define IM_DI_CONTROL_ma_3aenable_shift                               (4)
#define IM_DI_CONTROL_ma_controlmode_shift                            (2)
#define IM_DI_CONTROL_ma_onedirectionweaveen_shift                    (1)
#define IM_DI_CONTROL_ma_preferintra_shift                            (0)
#define IM_DI_CONTROL_film_sawtooth_choose_mask                       (0xC0000000)
#define IM_DI_CONTROL_film22_filter_andor_mask                        (0x20000000)
#define IM_DI_CONTROL_ip_enable_mask                                  (0x10000000)
#define IM_DI_CONTROL_di444to422lowpass_mask                          (0x08000000)
#define IM_DI_CONTROL_cp_tresultweight_mask                           (0x07000000)
#define IM_DI_CONTROL_cp_temporalenable_mask                          (0x00800000)
#define IM_DI_CONTROL_intra_lowangleenable_mask                       (0x00400000)
#define IM_DI_CONTROL_intra_stage1enable_mask                         (0x00200000)
#define IM_DI_CONTROL_intra_stage2enable_mask                         (0x00100000)
#define IM_DI_CONTROL_intra_mfilterenable_mask                        (0x00080000)
#define IM_DI_CONTROL_intra_interpolationrange_mask                   (0x00078000)
#define IM_DI_CONTROL_film_enable_mask                                (0x00007C00)
#define IM_DI_CONTROL_ma_vertexten_mask                               (0x00000200)
#define IM_DI_CONTROL_ma_horicomen_mask                               (0x00000100)
#define IM_DI_CONTROL_ma_stilllogoena_mask                            (0x00000080)
#define IM_DI_CONTROL_ma_smoothintra90_mask                           (0x00000040)
#define IM_DI_CONTROL_ma_messintra90_mask                             (0x00000020)
#define IM_DI_CONTROL_ma_3aenable_mask                                (0x00000010)
#define IM_DI_CONTROL_ma_controlmode_mask                             (0x0000000C)
#define IM_DI_CONTROL_ma_onedirectionweaveen_mask                     (0x00000002)
#define IM_DI_CONTROL_ma_preferintra_mask                             (0x00000001)
#define IM_DI_CONTROL_film_sawtooth_choose(data)                      (0xC0000000&((data)<<30))
#define IM_DI_CONTROL_film22_filter_andor(data)                       (0x20000000&((data)<<29))
#define IM_DI_CONTROL_ip_enable(data)                                 (0x10000000&((data)<<28))
#define IM_DI_CONTROL_di444to422lowpass(data)                         (0x08000000&((data)<<27))
#define IM_DI_CONTROL_cp_tresultweight(data)                          (0x07000000&((data)<<24))
#define IM_DI_CONTROL_cp_temporalenable(data)                         (0x00800000&((data)<<23))
#define IM_DI_CONTROL_intra_lowangleenable(data)                      (0x00400000&((data)<<22))
#define IM_DI_CONTROL_intra_stage1enable(data)                        (0x00200000&((data)<<21))
#define IM_DI_CONTROL_intra_stage2enable(data)                        (0x00100000&((data)<<20))
#define IM_DI_CONTROL_intra_mfilterenable(data)                       (0x00080000&((data)<<19))
#define IM_DI_CONTROL_intra_interpolationrange(data)                  (0x00078000&((data)<<15))
#define IM_DI_CONTROL_film_enable(data)                               (0x00007C00&((data)<<10))
#define IM_DI_CONTROL_ma_vertexten(data)                              (0x00000200&((data)<<9))
#define IM_DI_CONTROL_ma_horicomen(data)                              (0x00000100&((data)<<8))
#define IM_DI_CONTROL_ma_stilllogoena(data)                           (0x00000080&((data)<<7))
#define IM_DI_CONTROL_ma_smoothintra90(data)                          (0x00000040&((data)<<6))
#define IM_DI_CONTROL_ma_messintra90(data)                            (0x00000020&((data)<<5))
#define IM_DI_CONTROL_ma_3aenable(data)                               (0x00000010&((data)<<4))
#define IM_DI_CONTROL_ma_controlmode(data)                            (0x0000000C&((data)<<2))
#define IM_DI_CONTROL_ma_onedirectionweaveen(data)                    (0x00000002&((data)<<1))
#define IM_DI_CONTROL_ma_preferintra(data)                            (0x00000001&(data))
#define IM_DI_CONTROL_get_film_sawtooth_choose(data)                  ((0xC0000000&(data))>>30)
#define IM_DI_CONTROL_get_film22_filter_andor(data)                   ((0x20000000&(data))>>29)
#define IM_DI_CONTROL_get_ip_enable(data)                             ((0x10000000&(data))>>28)
#define IM_DI_CONTROL_get_di444to422lowpass(data)                     ((0x08000000&(data))>>27)
#define IM_DI_CONTROL_get_cp_tresultweight(data)                      ((0x07000000&(data))>>24)
#define IM_DI_CONTROL_get_cp_temporalenable(data)                     ((0x00800000&(data))>>23)
#define IM_DI_CONTROL_get_intra_lowangleenable(data)                  ((0x00400000&(data))>>22)
#define IM_DI_CONTROL_get_intra_stage1enable(data)                    ((0x00200000&(data))>>21)
#define IM_DI_CONTROL_get_intra_stage2enable(data)                    ((0x00100000&(data))>>20)
#define IM_DI_CONTROL_get_intra_mfilterenable(data)                   ((0x00080000&(data))>>19)
#define IM_DI_CONTROL_get_intra_interpolationrange(data)              ((0x00078000&(data))>>15)
#define IM_DI_CONTROL_get_film_enable(data)                           ((0x00007C00&(data))>>10)
#define IM_DI_CONTROL_get_ma_vertexten(data)                          ((0x00000200&(data))>>9)
#define IM_DI_CONTROL_get_ma_horicomen(data)                          ((0x00000100&(data))>>8)
#define IM_DI_CONTROL_get_ma_stilllogoena(data)                       ((0x00000080&(data))>>7)
#define IM_DI_CONTROL_get_ma_smoothintra90(data)                      ((0x00000040&(data))>>6)
#define IM_DI_CONTROL_get_ma_messintra90(data)                        ((0x00000020&(data))>>5)
#define IM_DI_CONTROL_get_ma_3aenable(data)                           ((0x00000010&(data))>>4)
#define IM_DI_CONTROL_get_ma_controlmode(data)                        ((0x0000000C&(data))>>2)
#define IM_DI_CONTROL_get_ma_onedirectionweaveen(data)                ((0x00000002&(data))>>1)
#define IM_DI_CONTROL_get_ma_preferintra(data)                        (0x00000001&(data))


#define COLORRECOVERYOPTION                                           0x18024004
#define COLORRECOVERYOPTION_reg_addr                                  "0xb8024004"
#define COLORRECOVERYOPTION_reg                                       0xb8024004
#define COLORRECOVERYOPTION_inst_addr                                 "0x0001"
#define COLORRECOVERYOPTION_inst                                      0x0001
#define COLORRECOVERYOPTION_fun_y_en_shift                            (31)
#define COLORRECOVERYOPTION_y10bitsin_shift                           (30)
#define COLORRECOVERYOPTION_c10bitsin_shift                           (29)
#define COLORRECOVERYOPTION_cr_fh_switch_shift                        (17)
#define COLORRECOVERYOPTION_cr_autoimg_enable_shift                   (16)
#define COLORRECOVERYOPTION_cp_bist_clkmux_en_shift                   (0)
#define COLORRECOVERYOPTION_fun_y_en_mask                             (0x80000000)
#define COLORRECOVERYOPTION_y10bitsin_mask                            (0x40000000)
#define COLORRECOVERYOPTION_c10bitsin_mask                            (0x20000000)
#define COLORRECOVERYOPTION_cr_fh_switch_mask                         (0x00020000)
#define COLORRECOVERYOPTION_cr_autoimg_enable_mask                    (0x00010000)
#define COLORRECOVERYOPTION_cp_bist_clkmux_en_mask                    (0x00000001)
#define COLORRECOVERYOPTION_fun_y_en(data)                            (0x80000000&((data)<<31))
#define COLORRECOVERYOPTION_y10bitsin(data)                           (0x40000000&((data)<<30))
#define COLORRECOVERYOPTION_c10bitsin(data)                           (0x20000000&((data)<<29))
#define COLORRECOVERYOPTION_cr_fh_switch(data)                        (0x00020000&((data)<<17))
#define COLORRECOVERYOPTION_cr_autoimg_enable(data)                   (0x00010000&((data)<<16))
#define COLORRECOVERYOPTION_cp_bist_clkmux_en(data)                   (0x00000001&(data))
#define COLORRECOVERYOPTION_get_fun_y_en(data)                        ((0x80000000&(data))>>31)
#define COLORRECOVERYOPTION_get_y10bitsin(data)                       ((0x40000000&(data))>>30)
#define COLORRECOVERYOPTION_get_c10bitsin(data)                       ((0x20000000&(data))>>29)
#define COLORRECOVERYOPTION_get_cr_fh_switch(data)                    ((0x00020000&(data))>>17)
#define COLORRECOVERYOPTION_get_cr_autoimg_enable(data)               ((0x00010000&(data))>>16)
#define COLORRECOVERYOPTION_get_cp_bist_clkmux_en(data)               (0x00000001&(data))


#define IM_DI_DEBUG_MODE                                              0x18024008
#define IM_DI_DEBUG_MODE_reg_addr                                     "0xb8024008"
#define IM_DI_DEBUG_MODE_reg                                          0xb8024008
#define IM_DI_DEBUG_MODE_inst_addr                                    "0x0002"
#define IM_DI_DEBUG_MODE_inst                                         0x0002
#define IM_DI_DEBUG_MODE_field_confuse_shift                          (31)
#define IM_DI_DEBUG_MODE_di_3d_l_flag_shift                           (30)
#define IM_DI_DEBUG_MODE_film_debugmode_shift                         (5)
#define IM_DI_DEBUG_MODE_ma_debugmode_shift                           (2)
#define IM_DI_DEBUG_MODE_ma_modeselect_shift                          (1)
#define IM_DI_DEBUG_MODE_cp_tnrdebugmode_shift                        (0)
#define IM_DI_DEBUG_MODE_field_confuse_mask                           (0x80000000)
#define IM_DI_DEBUG_MODE_di_3d_l_flag_mask                            (0x40000000)
#define IM_DI_DEBUG_MODE_film_debugmode_mask                          (0x00000020)
#define IM_DI_DEBUG_MODE_ma_debugmode_mask                            (0x0000001C)
#define IM_DI_DEBUG_MODE_ma_modeselect_mask                           (0x00000002)
#define IM_DI_DEBUG_MODE_cp_tnrdebugmode_mask                         (0x00000001)
#define IM_DI_DEBUG_MODE_field_confuse(data)                          (0x80000000&((data)<<31))
#define IM_DI_DEBUG_MODE_di_3d_l_flag(data)                           (0x40000000&((data)<<30))
#define IM_DI_DEBUG_MODE_film_debugmode(data)                         (0x00000020&((data)<<5))
#define IM_DI_DEBUG_MODE_ma_debugmode(data)                           (0x0000001C&((data)<<2))
#define IM_DI_DEBUG_MODE_ma_modeselect(data)                          (0x00000002&((data)<<1))
#define IM_DI_DEBUG_MODE_cp_tnrdebugmode(data)                        (0x00000001&(data))
#define IM_DI_DEBUG_MODE_get_field_confuse(data)                      ((0x80000000&(data))>>31)
#define IM_DI_DEBUG_MODE_get_di_3d_l_flag(data)                       ((0x40000000&(data))>>30)
#define IM_DI_DEBUG_MODE_get_film_debugmode(data)                     ((0x00000020&(data))>>5)
#define IM_DI_DEBUG_MODE_get_ma_debugmode(data)                       ((0x0000001C&(data))>>2)
#define IM_DI_DEBUG_MODE_get_ma_modeselect(data)                      ((0x00000002&(data))>>1)
#define IM_DI_DEBUG_MODE_get_cp_tnrdebugmode(data)                    (0x00000001&(data))


#define IM_DI_ACTIVE_WINDOW_CONTROL                                   0x1802400c
#define IM_DI_ACTIVE_WINDOW_CONTROL_reg_addr                          "0xb802400c"
#define IM_DI_ACTIVE_WINDOW_CONTROL_reg                               0xb802400c
#define IM_DI_ACTIVE_WINDOW_CONTROL_inst_addr                         "0x0003"
#define IM_DI_ACTIVE_WINDOW_CONTROL_inst                              0x0003
#define IM_DI_ACTIVE_WINDOW_CONTROL_singlefieldintra_shift            (31)
#define IM_DI_ACTIVE_WINDOW_CONTROL_hsize_shift                       (20)
#define IM_DI_ACTIVE_WINDOW_CONTROL_vsize_shift                       (10)
#define IM_DI_ACTIVE_WINDOW_CONTROL_hblksize_shift                    (0)
#define IM_DI_ACTIVE_WINDOW_CONTROL_singlefieldintra_mask             (0x80000000)
#define IM_DI_ACTIVE_WINDOW_CONTROL_hsize_mask                        (0x7FF00000)
#define IM_DI_ACTIVE_WINDOW_CONTROL_vsize_mask                        (0x000FFC00)
#define IM_DI_ACTIVE_WINDOW_CONTROL_hblksize_mask                     (0x000003FF)
#define IM_DI_ACTIVE_WINDOW_CONTROL_singlefieldintra(data)            (0x80000000&((data)<<31))
#define IM_DI_ACTIVE_WINDOW_CONTROL_hsize(data)                       (0x7FF00000&((data)<<20))
#define IM_DI_ACTIVE_WINDOW_CONTROL_vsize(data)                       (0x000FFC00&((data)<<10))
#define IM_DI_ACTIVE_WINDOW_CONTROL_hblksize(data)                    (0x000003FF&(data))
#define IM_DI_ACTIVE_WINDOW_CONTROL_get_singlefieldintra(data)        ((0x80000000&(data))>>31)
#define IM_DI_ACTIVE_WINDOW_CONTROL_get_hsize(data)                   ((0x7FF00000&(data))>>20)
#define IM_DI_ACTIVE_WINDOW_CONTROL_get_vsize(data)                   ((0x000FFC00&(data))>>10)
#define IM_DI_ACTIVE_WINDOW_CONTROL_get_hblksize(data)                (0x000003FF&(data))


#define IM_DI_WEAVE_WINDOW_CONTROL                                    0x18024010
#define IM_DI_WEAVE_WINDOW_CONTROL_reg_addr                           "0xb8024010"
#define IM_DI_WEAVE_WINDOW_CONTROL_reg                                0xb8024010
#define IM_DI_WEAVE_WINDOW_CONTROL_inst_addr                          "0x0004"
#define IM_DI_WEAVE_WINDOW_CONTROL_inst                               0x0004
#define IM_DI_WEAVE_WINDOW_CONTROL_fixedwindowmode_shift              (30)
#define IM_DI_WEAVE_WINDOW_CONTROL_hblksize_msb_shift                 (21)
#define IM_DI_WEAVE_WINDOW_CONTROL_freeze_shift                       (20)
#define IM_DI_WEAVE_WINDOW_CONTROL_force2d_shift                      (19)
#define IM_DI_WEAVE_WINDOW_CONTROL_readstart_shift                    (8)
#define IM_DI_WEAVE_WINDOW_CONTROL_delpixelen_shift                   (7)
#define IM_DI_WEAVE_WINDOW_CONTROL_dellineen_shift                    (6)
#define IM_DI_WEAVE_WINDOW_CONTROL_fixedwindow5_shift                 (5)
#define IM_DI_WEAVE_WINDOW_CONTROL_fixedwindow4_shift                 (4)
#define IM_DI_WEAVE_WINDOW_CONTROL_fixedwindow3_shift                 (3)
#define IM_DI_WEAVE_WINDOW_CONTROL_fixedwindow2_shift                 (2)
#define IM_DI_WEAVE_WINDOW_CONTROL_fixedwindow1_shift                 (1)
#define IM_DI_WEAVE_WINDOW_CONTROL_fixedwindow0_shift                 (0)
#define IM_DI_WEAVE_WINDOW_CONTROL_fixedwindowmode_mask               (0xC0000000)
#define IM_DI_WEAVE_WINDOW_CONTROL_hblksize_msb_mask                  (0x00200000)
#define IM_DI_WEAVE_WINDOW_CONTROL_freeze_mask                        (0x00100000)
#define IM_DI_WEAVE_WINDOW_CONTROL_force2d_mask                       (0x00080000)
#define IM_DI_WEAVE_WINDOW_CONTROL_readstart_mask                     (0x0007FF00)
#define IM_DI_WEAVE_WINDOW_CONTROL_delpixelen_mask                    (0x00000080)
#define IM_DI_WEAVE_WINDOW_CONTROL_dellineen_mask                     (0x00000040)
#define IM_DI_WEAVE_WINDOW_CONTROL_fixedwindow5_mask                  (0x00000020)
#define IM_DI_WEAVE_WINDOW_CONTROL_fixedwindow4_mask                  (0x00000010)
#define IM_DI_WEAVE_WINDOW_CONTROL_fixedwindow3_mask                  (0x00000008)
#define IM_DI_WEAVE_WINDOW_CONTROL_fixedwindow2_mask                  (0x00000004)
#define IM_DI_WEAVE_WINDOW_CONTROL_fixedwindow1_mask                  (0x00000002)
#define IM_DI_WEAVE_WINDOW_CONTROL_fixedwindow0_mask                  (0x00000001)
#define IM_DI_WEAVE_WINDOW_CONTROL_fixedwindowmode(data)              (0xC0000000&((data)<<30))
#define IM_DI_WEAVE_WINDOW_CONTROL_hblksize_msb(data)                 (0x00200000&((data)<<21))
#define IM_DI_WEAVE_WINDOW_CONTROL_freeze(data)                       (0x00100000&((data)<<20))
#define IM_DI_WEAVE_WINDOW_CONTROL_force2d(data)                      (0x00080000&((data)<<19))
#define IM_DI_WEAVE_WINDOW_CONTROL_readstart(data)                    (0x0007FF00&((data)<<8))
#define IM_DI_WEAVE_WINDOW_CONTROL_delpixelen(data)                   (0x00000080&((data)<<7))
#define IM_DI_WEAVE_WINDOW_CONTROL_dellineen(data)                    (0x00000040&((data)<<6))
#define IM_DI_WEAVE_WINDOW_CONTROL_fixedwindow5(data)                 (0x00000020&((data)<<5))
#define IM_DI_WEAVE_WINDOW_CONTROL_fixedwindow4(data)                 (0x00000010&((data)<<4))
#define IM_DI_WEAVE_WINDOW_CONTROL_fixedwindow3(data)                 (0x00000008&((data)<<3))
#define IM_DI_WEAVE_WINDOW_CONTROL_fixedwindow2(data)                 (0x00000004&((data)<<2))
#define IM_DI_WEAVE_WINDOW_CONTROL_fixedwindow1(data)                 (0x00000002&((data)<<1))
#define IM_DI_WEAVE_WINDOW_CONTROL_fixedwindow0(data)                 (0x00000001&(data))
#define IM_DI_WEAVE_WINDOW_CONTROL_get_fixedwindowmode(data)          ((0xC0000000&(data))>>30)
#define IM_DI_WEAVE_WINDOW_CONTROL_get_hblksize_msb(data)             ((0x00200000&(data))>>21)
#define IM_DI_WEAVE_WINDOW_CONTROL_get_freeze(data)                   ((0x00100000&(data))>>20)
#define IM_DI_WEAVE_WINDOW_CONTROL_get_force2d(data)                  ((0x00080000&(data))>>19)
#define IM_DI_WEAVE_WINDOW_CONTROL_get_readstart(data)                ((0x0007FF00&(data))>>8)
#define IM_DI_WEAVE_WINDOW_CONTROL_get_delpixelen(data)               ((0x00000080&(data))>>7)
#define IM_DI_WEAVE_WINDOW_CONTROL_get_dellineen(data)                ((0x00000040&(data))>>6)
#define IM_DI_WEAVE_WINDOW_CONTROL_get_fixedwindow5(data)             ((0x00000020&(data))>>5)
#define IM_DI_WEAVE_WINDOW_CONTROL_get_fixedwindow4(data)             ((0x00000010&(data))>>4)
#define IM_DI_WEAVE_WINDOW_CONTROL_get_fixedwindow3(data)             ((0x00000008&(data))>>3)
#define IM_DI_WEAVE_WINDOW_CONTROL_get_fixedwindow2(data)             ((0x00000004&(data))>>2)
#define IM_DI_WEAVE_WINDOW_CONTROL_get_fixedwindow1(data)             ((0x00000002&(data))>>1)
#define IM_DI_WEAVE_WINDOW_CONTROL_get_fixedwindow0(data)             (0x00000001&(data))


#define IM_DI_WEAVE_WINDOW_0_START                                    0x18024014
#define IM_DI_WEAVE_WINDOW_0_START_reg_addr                           "0xb8024014"
#define IM_DI_WEAVE_WINDOW_0_START_reg                                0xb8024014
#define IM_DI_WEAVE_WINDOW_0_START_inst_addr                          "0x0005"
#define IM_DI_WEAVE_WINDOW_0_START_inst                               0x0005
#define IM_DI_WEAVE_WINDOW_0_START_ystart_11_0_shift                  (16)
#define IM_DI_WEAVE_WINDOW_0_START_xstart_11_0_shift                  (0)
#define IM_DI_WEAVE_WINDOW_0_START_ystart_11_0_mask                   (0x0FFF0000)
#define IM_DI_WEAVE_WINDOW_0_START_xstart_11_0_mask                   (0x00000FFF)
#define IM_DI_WEAVE_WINDOW_0_START_ystart_11_0(data)                  (0x0FFF0000&((data)<<16))
#define IM_DI_WEAVE_WINDOW_0_START_xstart_11_0(data)                  (0x00000FFF&(data))
#define IM_DI_WEAVE_WINDOW_0_START_get_ystart_11_0(data)              ((0x0FFF0000&(data))>>16)
#define IM_DI_WEAVE_WINDOW_0_START_get_xstart_11_0(data)              (0x00000FFF&(data))


#define IM_DI_WEAVE_WINDOW_0_END                                      0x18024018
#define IM_DI_WEAVE_WINDOW_0_END_reg_addr                             "0xb8024018"
#define IM_DI_WEAVE_WINDOW_0_END_reg                                  0xb8024018
#define IM_DI_WEAVE_WINDOW_0_END_inst_addr                            "0x0006"
#define IM_DI_WEAVE_WINDOW_0_END_inst                                 0x0006
#define IM_DI_WEAVE_WINDOW_0_END_yend_11_0_shift                      (16)
#define IM_DI_WEAVE_WINDOW_0_END_xend_11_0_shift                      (0)
#define IM_DI_WEAVE_WINDOW_0_END_yend_11_0_mask                       (0x0FFF0000)
#define IM_DI_WEAVE_WINDOW_0_END_xend_11_0_mask                       (0x00000FFF)
#define IM_DI_WEAVE_WINDOW_0_END_yend_11_0(data)                      (0x0FFF0000&((data)<<16))
#define IM_DI_WEAVE_WINDOW_0_END_xend_11_0(data)                      (0x00000FFF&(data))
#define IM_DI_WEAVE_WINDOW_0_END_get_yend_11_0(data)                  ((0x0FFF0000&(data))>>16)
#define IM_DI_WEAVE_WINDOW_0_END_get_xend_11_0(data)                  (0x00000FFF&(data))


#define IM_DI_WEAVE_WINDOW_1_START                                    0x1802401c
#define IM_DI_WEAVE_WINDOW_1_START_reg_addr                           "0xb802401c"
#define IM_DI_WEAVE_WINDOW_1_START_reg                                0xb802401c
#define IM_DI_WEAVE_WINDOW_1_START_inst_addr                          "0x0007"
#define IM_DI_WEAVE_WINDOW_1_START_inst                               0x0007
#define IM_DI_WEAVE_WINDOW_1_START_ystart_23_12_shift                 (16)
#define IM_DI_WEAVE_WINDOW_1_START_xstart_23_12_shift                 (0)
#define IM_DI_WEAVE_WINDOW_1_START_ystart_23_12_mask                  (0x0FFF0000)
#define IM_DI_WEAVE_WINDOW_1_START_xstart_23_12_mask                  (0x00000FFF)
#define IM_DI_WEAVE_WINDOW_1_START_ystart_23_12(data)                 (0x0FFF0000&((data)<<16))
#define IM_DI_WEAVE_WINDOW_1_START_xstart_23_12(data)                 (0x00000FFF&(data))
#define IM_DI_WEAVE_WINDOW_1_START_get_ystart_23_12(data)             ((0x0FFF0000&(data))>>16)
#define IM_DI_WEAVE_WINDOW_1_START_get_xstart_23_12(data)             (0x00000FFF&(data))


#define IM_DI_WEAVE_WINDOW_1_END                                      0x18024020
#define IM_DI_WEAVE_WINDOW_1_END_reg_addr                             "0xb8024020"
#define IM_DI_WEAVE_WINDOW_1_END_reg                                  0xb8024020
#define IM_DI_WEAVE_WINDOW_1_END_inst_addr                            "0x0008"
#define IM_DI_WEAVE_WINDOW_1_END_inst                                 0x0008
#define IM_DI_WEAVE_WINDOW_1_END_yend_23_12_shift                     (16)
#define IM_DI_WEAVE_WINDOW_1_END_xend_23_12_shift                     (0)
#define IM_DI_WEAVE_WINDOW_1_END_yend_23_12_mask                      (0x0FFF0000)
#define IM_DI_WEAVE_WINDOW_1_END_xend_23_12_mask                      (0x00000FFF)
#define IM_DI_WEAVE_WINDOW_1_END_yend_23_12(data)                     (0x0FFF0000&((data)<<16))
#define IM_DI_WEAVE_WINDOW_1_END_xend_23_12(data)                     (0x00000FFF&(data))
#define IM_DI_WEAVE_WINDOW_1_END_get_yend_23_12(data)                 ((0x0FFF0000&(data))>>16)
#define IM_DI_WEAVE_WINDOW_1_END_get_xend_23_12(data)                 (0x00000FFF&(data))


#define IM_DI_WEAVE_WINDOW_2_START                                    0x18024024
#define IM_DI_WEAVE_WINDOW_2_START_reg_addr                           "0xb8024024"
#define IM_DI_WEAVE_WINDOW_2_START_reg                                0xb8024024
#define IM_DI_WEAVE_WINDOW_2_START_inst_addr                          "0x0009"
#define IM_DI_WEAVE_WINDOW_2_START_inst                               0x0009
#define IM_DI_WEAVE_WINDOW_2_START_ystart_35_24_shift                 (16)
#define IM_DI_WEAVE_WINDOW_2_START_xstart_35_24_shift                 (0)
#define IM_DI_WEAVE_WINDOW_2_START_ystart_35_24_mask                  (0x0FFF0000)
#define IM_DI_WEAVE_WINDOW_2_START_xstart_35_24_mask                  (0x00000FFF)
#define IM_DI_WEAVE_WINDOW_2_START_ystart_35_24(data)                 (0x0FFF0000&((data)<<16))
#define IM_DI_WEAVE_WINDOW_2_START_xstart_35_24(data)                 (0x00000FFF&(data))
#define IM_DI_WEAVE_WINDOW_2_START_get_ystart_35_24(data)             ((0x0FFF0000&(data))>>16)
#define IM_DI_WEAVE_WINDOW_2_START_get_xstart_35_24(data)             (0x00000FFF&(data))


#define IM_DI_WEAVE_WINDOW_2_END                                      0x18024028
#define IM_DI_WEAVE_WINDOW_2_END_reg_addr                             "0xb8024028"
#define IM_DI_WEAVE_WINDOW_2_END_reg                                  0xb8024028
#define IM_DI_WEAVE_WINDOW_2_END_inst_addr                            "0x000A"
#define IM_DI_WEAVE_WINDOW_2_END_inst                                 0x000A
#define IM_DI_WEAVE_WINDOW_2_END_yend_35_24_shift                     (16)
#define IM_DI_WEAVE_WINDOW_2_END_xend_35_24_shift                     (0)
#define IM_DI_WEAVE_WINDOW_2_END_yend_35_24_mask                      (0x0FFF0000)
#define IM_DI_WEAVE_WINDOW_2_END_xend_35_24_mask                      (0x00000FFF)
#define IM_DI_WEAVE_WINDOW_2_END_yend_35_24(data)                     (0x0FFF0000&((data)<<16))
#define IM_DI_WEAVE_WINDOW_2_END_xend_35_24(data)                     (0x00000FFF&(data))
#define IM_DI_WEAVE_WINDOW_2_END_get_yend_35_24(data)                 ((0x0FFF0000&(data))>>16)
#define IM_DI_WEAVE_WINDOW_2_END_get_xend_35_24(data)                 (0x00000FFF&(data))


#define IM_DI_WEAVE_WINDOW_3_START                                    0x1802402c
#define IM_DI_WEAVE_WINDOW_3_START_reg_addr                           "0xb802402c"
#define IM_DI_WEAVE_WINDOW_3_START_reg                                0xb802402c
#define IM_DI_WEAVE_WINDOW_3_START_inst_addr                          "0x000B"
#define IM_DI_WEAVE_WINDOW_3_START_inst                               0x000B
#define IM_DI_WEAVE_WINDOW_3_START_ystart_47_36_shift                 (16)
#define IM_DI_WEAVE_WINDOW_3_START_xstart_47_36_shift                 (0)
#define IM_DI_WEAVE_WINDOW_3_START_ystart_47_36_mask                  (0x0FFF0000)
#define IM_DI_WEAVE_WINDOW_3_START_xstart_47_36_mask                  (0x00000FFF)
#define IM_DI_WEAVE_WINDOW_3_START_ystart_47_36(data)                 (0x0FFF0000&((data)<<16))
#define IM_DI_WEAVE_WINDOW_3_START_xstart_47_36(data)                 (0x00000FFF&(data))
#define IM_DI_WEAVE_WINDOW_3_START_get_ystart_47_36(data)             ((0x0FFF0000&(data))>>16)
#define IM_DI_WEAVE_WINDOW_3_START_get_xstart_47_36(data)             (0x00000FFF&(data))


#define IM_DI_WEAVE_WINDOW_3_END                                      0x18024030
#define IM_DI_WEAVE_WINDOW_3_END_reg_addr                             "0xb8024030"
#define IM_DI_WEAVE_WINDOW_3_END_reg                                  0xb8024030
#define IM_DI_WEAVE_WINDOW_3_END_inst_addr                            "0x000C"
#define IM_DI_WEAVE_WINDOW_3_END_inst                                 0x000C
#define IM_DI_WEAVE_WINDOW_3_END_yend_47_36_shift                     (16)
#define IM_DI_WEAVE_WINDOW_3_END_xend_47_36_shift                     (0)
#define IM_DI_WEAVE_WINDOW_3_END_yend_47_36_mask                      (0x0FFF0000)
#define IM_DI_WEAVE_WINDOW_3_END_xend_47_36_mask                      (0x00000FFF)
#define IM_DI_WEAVE_WINDOW_3_END_yend_47_36(data)                     (0x0FFF0000&((data)<<16))
#define IM_DI_WEAVE_WINDOW_3_END_xend_47_36(data)                     (0x00000FFF&(data))
#define IM_DI_WEAVE_WINDOW_3_END_get_yend_47_36(data)                 ((0x0FFF0000&(data))>>16)
#define IM_DI_WEAVE_WINDOW_3_END_get_xend_47_36(data)                 (0x00000FFF&(data))


#define IM_DI_WEAVE_WINDOW_4_START                                    0x18024034
#define IM_DI_WEAVE_WINDOW_4_START_reg_addr                           "0xb8024034"
#define IM_DI_WEAVE_WINDOW_4_START_reg                                0xb8024034
#define IM_DI_WEAVE_WINDOW_4_START_inst_addr                          "0x000D"
#define IM_DI_WEAVE_WINDOW_4_START_inst                               0x000D
#define IM_DI_WEAVE_WINDOW_4_START_ystart_59_48_shift                 (16)
#define IM_DI_WEAVE_WINDOW_4_START_xstart_59_48_shift                 (0)
#define IM_DI_WEAVE_WINDOW_4_START_ystart_59_48_mask                  (0x0FFF0000)
#define IM_DI_WEAVE_WINDOW_4_START_xstart_59_48_mask                  (0x00000FFF)
#define IM_DI_WEAVE_WINDOW_4_START_ystart_59_48(data)                 (0x0FFF0000&((data)<<16))
#define IM_DI_WEAVE_WINDOW_4_START_xstart_59_48(data)                 (0x00000FFF&(data))
#define IM_DI_WEAVE_WINDOW_4_START_get_ystart_59_48(data)             ((0x0FFF0000&(data))>>16)
#define IM_DI_WEAVE_WINDOW_4_START_get_xstart_59_48(data)             (0x00000FFF&(data))


#define IM_DI_WEAVE_WINDOW_4_END                                      0x18024038
#define IM_DI_WEAVE_WINDOW_4_END_reg_addr                             "0xb8024038"
#define IM_DI_WEAVE_WINDOW_4_END_reg                                  0xb8024038
#define IM_DI_WEAVE_WINDOW_4_END_inst_addr                            "0x000E"
#define IM_DI_WEAVE_WINDOW_4_END_inst                                 0x000E
#define IM_DI_WEAVE_WINDOW_4_END_yend_59_48_shift                     (16)
#define IM_DI_WEAVE_WINDOW_4_END_xend_59_48_shift                     (0)
#define IM_DI_WEAVE_WINDOW_4_END_yend_59_48_mask                      (0x0FFF0000)
#define IM_DI_WEAVE_WINDOW_4_END_xend_59_48_mask                      (0x00000FFF)
#define IM_DI_WEAVE_WINDOW_4_END_yend_59_48(data)                     (0x0FFF0000&((data)<<16))
#define IM_DI_WEAVE_WINDOW_4_END_xend_59_48(data)                     (0x00000FFF&(data))
#define IM_DI_WEAVE_WINDOW_4_END_get_yend_59_48(data)                 ((0x0FFF0000&(data))>>16)
#define IM_DI_WEAVE_WINDOW_4_END_get_xend_59_48(data)                 (0x00000FFF&(data))


#define IM_DI_WEAVE_WINDOW_5_START                                    0x1802403c
#define IM_DI_WEAVE_WINDOW_5_START_reg_addr                           "0xb802403c"
#define IM_DI_WEAVE_WINDOW_5_START_reg                                0xb802403c
#define IM_DI_WEAVE_WINDOW_5_START_inst_addr                          "0x000F"
#define IM_DI_WEAVE_WINDOW_5_START_inst                               0x000F
#define IM_DI_WEAVE_WINDOW_5_START_ystart_71_60_shift                 (16)
#define IM_DI_WEAVE_WINDOW_5_START_xstart_71_60_shift                 (0)
#define IM_DI_WEAVE_WINDOW_5_START_ystart_71_60_mask                  (0x0FFF0000)
#define IM_DI_WEAVE_WINDOW_5_START_xstart_71_60_mask                  (0x00000FFF)
#define IM_DI_WEAVE_WINDOW_5_START_ystart_71_60(data)                 (0x0FFF0000&((data)<<16))
#define IM_DI_WEAVE_WINDOW_5_START_xstart_71_60(data)                 (0x00000FFF&(data))
#define IM_DI_WEAVE_WINDOW_5_START_get_ystart_71_60(data)             ((0x0FFF0000&(data))>>16)
#define IM_DI_WEAVE_WINDOW_5_START_get_xstart_71_60(data)             (0x00000FFF&(data))


#define IM_DI_WEAVE_WINDOW_5_END                                      0x18024040
#define IM_DI_WEAVE_WINDOW_5_END_reg_addr                             "0xb8024040"
#define IM_DI_WEAVE_WINDOW_5_END_reg                                  0xb8024040
#define IM_DI_WEAVE_WINDOW_5_END_inst_addr                            "0x0010"
#define IM_DI_WEAVE_WINDOW_5_END_inst                                 0x0010
#define IM_DI_WEAVE_WINDOW_5_END_yend_71_60_shift                     (16)
#define IM_DI_WEAVE_WINDOW_5_END_xend_71_60_shift                     (0)
#define IM_DI_WEAVE_WINDOW_5_END_yend_71_60_mask                      (0x0FFF0000)
#define IM_DI_WEAVE_WINDOW_5_END_xend_71_60_mask                      (0x00000FFF)
#define IM_DI_WEAVE_WINDOW_5_END_yend_71_60(data)                     (0x0FFF0000&((data)<<16))
#define IM_DI_WEAVE_WINDOW_5_END_xend_71_60(data)                     (0x00000FFF&(data))
#define IM_DI_WEAVE_WINDOW_5_END_get_yend_71_60(data)                 ((0x0FFF0000&(data))>>16)
#define IM_DI_WEAVE_WINDOW_5_END_get_xend_71_60(data)                 (0x00000FFF&(data))


#define IM_DI_CLASSIFY_TH                                             0x18024044
#define IM_DI_CLASSIFY_TH_reg_addr                                    "0xb8024044"
#define IM_DI_CLASSIFY_TH_reg                                         0xb8024044
#define IM_DI_CLASSIFY_TH_inst_addr                                   "0x0011"
#define IM_DI_CLASSIFY_TH_inst                                        0x0011
#define IM_DI_CLASSIFY_TH_pseudo_memc_film22_sequence_shift           (28)
#define IM_DI_CLASSIFY_TH_pseudo_memc_film22_weight0_shift            (26)
#define IM_DI_CLASSIFY_TH_pseudo_memc_film22_weight1_shift            (24)
#define IM_DI_CLASSIFY_TH_ma_class_h_th1_cmp_shift                    (16)
#define IM_DI_CLASSIFY_TH_ma_class_h_th1_shift                        (8)
#define IM_DI_CLASSIFY_TH_ma_class_h_th2_shift                        (0)
#define IM_DI_CLASSIFY_TH_pseudo_memc_film22_sequence_mask            (0x30000000)
#define IM_DI_CLASSIFY_TH_pseudo_memc_film22_weight0_mask             (0x0C000000)
#define IM_DI_CLASSIFY_TH_pseudo_memc_film22_weight1_mask             (0x03000000)
#define IM_DI_CLASSIFY_TH_ma_class_h_th1_cmp_mask                     (0x001F0000)
#define IM_DI_CLASSIFY_TH_ma_class_h_th1_mask                         (0x00001F00)
#define IM_DI_CLASSIFY_TH_ma_class_h_th2_mask                         (0x0000001F)
#define IM_DI_CLASSIFY_TH_pseudo_memc_film22_sequence(data)           (0x30000000&((data)<<28))
#define IM_DI_CLASSIFY_TH_pseudo_memc_film22_weight0(data)            (0x0C000000&((data)<<26))
#define IM_DI_CLASSIFY_TH_pseudo_memc_film22_weight1(data)            (0x03000000&((data)<<24))
#define IM_DI_CLASSIFY_TH_ma_class_h_th1_cmp(data)                    (0x001F0000&((data)<<16))
#define IM_DI_CLASSIFY_TH_ma_class_h_th1(data)                        (0x00001F00&((data)<<8))
#define IM_DI_CLASSIFY_TH_ma_class_h_th2(data)                        (0x0000001F&(data))
#define IM_DI_CLASSIFY_TH_get_pseudo_memc_film22_sequence(data)       ((0x30000000&(data))>>28)
#define IM_DI_CLASSIFY_TH_get_pseudo_memc_film22_weight0(data)        ((0x0C000000&(data))>>26)
#define IM_DI_CLASSIFY_TH_get_pseudo_memc_film22_weight1(data)        ((0x03000000&(data))>>24)
#define IM_DI_CLASSIFY_TH_get_ma_class_h_th1_cmp(data)                ((0x001F0000&(data))>>16)
#define IM_DI_CLASSIFY_TH_get_ma_class_h_th1(data)                    ((0x00001F00&(data))>>8)
#define IM_DI_CLASSIFY_TH_get_ma_class_h_th2(data)                    (0x0000001F&(data))


#define IM_DI_BLEND_AND_WEIGHTING_METHOD                              0x18024048
#define IM_DI_BLEND_AND_WEIGHTING_METHOD_reg_addr                     "0xb8024048"
#define IM_DI_BLEND_AND_WEIGHTING_METHOD_reg                          0xb8024048
#define IM_DI_BLEND_AND_WEIGHTING_METHOD_inst_addr                    "0x0012"
#define IM_DI_BLEND_AND_WEIGHTING_METHOD_inst                         0x0012
#define IM_DI_BLEND_AND_WEIGHTING_METHOD_pseudo_memc_en_shift         (31)
#define IM_DI_BLEND_AND_WEIGHTING_METHOD_dummy18024048_30_shift       (30)
#define IM_DI_BLEND_AND_WEIGHTING_METHOD_pseudo_memc_film32_sequence_shift  (26)
#define IM_DI_BLEND_AND_WEIGHTING_METHOD_pseudo_memc_film32_weight0_shift  (24)
#define IM_DI_BLEND_AND_WEIGHTING_METHOD_pseudo_memc_film32_weight1_shift  (22)
#define IM_DI_BLEND_AND_WEIGHTING_METHOD_pseudo_memc_film32_weight2_shift  (20)
#define IM_DI_BLEND_AND_WEIGHTING_METHOD_pseudo_memc_film32_weight3_shift  (18)
#define IM_DI_BLEND_AND_WEIGHTING_METHOD_ma_blend_fmcomb3_shift       (16)
#define IM_DI_BLEND_AND_WEIGHTING_METHOD_ma_blend_fmcomb2_shift       (14)
#define IM_DI_BLEND_AND_WEIGHTING_METHOD_ma_blend_fmcomb1_hor_shift   (12)
#define IM_DI_BLEND_AND_WEIGHTING_METHOD_ma_blend_fmcomb1_shift       (10)
#define IM_DI_BLEND_AND_WEIGHTING_METHOD_ma_blend_fmcomb0_shift       (8)
#define IM_DI_BLEND_AND_WEIGHTING_METHOD_ma_blend10_weight_shift      (4)
#define IM_DI_BLEND_AND_WEIGHTING_METHOD_ma_blend01_weight_shift      (0)
#define IM_DI_BLEND_AND_WEIGHTING_METHOD_pseudo_memc_en_mask          (0x80000000)
#define IM_DI_BLEND_AND_WEIGHTING_METHOD_dummy18024048_30_mask        (0x40000000)
#define IM_DI_BLEND_AND_WEIGHTING_METHOD_pseudo_memc_film32_sequence_mask  (0x3C000000)
#define IM_DI_BLEND_AND_WEIGHTING_METHOD_pseudo_memc_film32_weight0_mask  (0x03000000)
#define IM_DI_BLEND_AND_WEIGHTING_METHOD_pseudo_memc_film32_weight1_mask  (0x00C00000)
#define IM_DI_BLEND_AND_WEIGHTING_METHOD_pseudo_memc_film32_weight2_mask  (0x00300000)
#define IM_DI_BLEND_AND_WEIGHTING_METHOD_pseudo_memc_film32_weight3_mask  (0x000C0000)
#define IM_DI_BLEND_AND_WEIGHTING_METHOD_ma_blend_fmcomb3_mask        (0x00030000)
#define IM_DI_BLEND_AND_WEIGHTING_METHOD_ma_blend_fmcomb2_mask        (0x0000C000)
#define IM_DI_BLEND_AND_WEIGHTING_METHOD_ma_blend_fmcomb1_hor_mask    (0x00003000)
#define IM_DI_BLEND_AND_WEIGHTING_METHOD_ma_blend_fmcomb1_mask        (0x00000C00)
#define IM_DI_BLEND_AND_WEIGHTING_METHOD_ma_blend_fmcomb0_mask        (0x00000300)
#define IM_DI_BLEND_AND_WEIGHTING_METHOD_ma_blend10_weight_mask       (0x00000070)
#define IM_DI_BLEND_AND_WEIGHTING_METHOD_ma_blend01_weight_mask       (0x00000007)
#define IM_DI_BLEND_AND_WEIGHTING_METHOD_pseudo_memc_en(data)         (0x80000000&((data)<<31))
#define IM_DI_BLEND_AND_WEIGHTING_METHOD_dummy18024048_30(data)       (0x40000000&((data)<<30))
#define IM_DI_BLEND_AND_WEIGHTING_METHOD_pseudo_memc_film32_sequence(data)  (0x3C000000&((data)<<26))
#define IM_DI_BLEND_AND_WEIGHTING_METHOD_pseudo_memc_film32_weight0(data)  (0x03000000&((data)<<24))
#define IM_DI_BLEND_AND_WEIGHTING_METHOD_pseudo_memc_film32_weight1(data)  (0x00C00000&((data)<<22))
#define IM_DI_BLEND_AND_WEIGHTING_METHOD_pseudo_memc_film32_weight2(data)  (0x00300000&((data)<<20))
#define IM_DI_BLEND_AND_WEIGHTING_METHOD_pseudo_memc_film32_weight3(data)  (0x000C0000&((data)<<18))
#define IM_DI_BLEND_AND_WEIGHTING_METHOD_ma_blend_fmcomb3(data)       (0x00030000&((data)<<16))
#define IM_DI_BLEND_AND_WEIGHTING_METHOD_ma_blend_fmcomb2(data)       (0x0000C000&((data)<<14))
#define IM_DI_BLEND_AND_WEIGHTING_METHOD_ma_blend_fmcomb1_hor(data)   (0x00003000&((data)<<12))
#define IM_DI_BLEND_AND_WEIGHTING_METHOD_ma_blend_fmcomb1(data)       (0x00000C00&((data)<<10))
#define IM_DI_BLEND_AND_WEIGHTING_METHOD_ma_blend_fmcomb0(data)       (0x00000300&((data)<<8))
#define IM_DI_BLEND_AND_WEIGHTING_METHOD_ma_blend10_weight(data)      (0x00000070&((data)<<4))
#define IM_DI_BLEND_AND_WEIGHTING_METHOD_ma_blend01_weight(data)      (0x00000007&(data))
#define IM_DI_BLEND_AND_WEIGHTING_METHOD_get_pseudo_memc_en(data)     ((0x80000000&(data))>>31)
#define IM_DI_BLEND_AND_WEIGHTING_METHOD_get_dummy18024048_30(data)   ((0x40000000&(data))>>30)
#define IM_DI_BLEND_AND_WEIGHTING_METHOD_get_pseudo_memc_film32_sequence(data)  ((0x3C000000&(data))>>26)
#define IM_DI_BLEND_AND_WEIGHTING_METHOD_get_pseudo_memc_film32_weight0(data)  ((0x03000000&(data))>>24)
#define IM_DI_BLEND_AND_WEIGHTING_METHOD_get_pseudo_memc_film32_weight1(data)  ((0x00C00000&(data))>>22)
#define IM_DI_BLEND_AND_WEIGHTING_METHOD_get_pseudo_memc_film32_weight2(data)  ((0x00300000&(data))>>20)
#define IM_DI_BLEND_AND_WEIGHTING_METHOD_get_pseudo_memc_film32_weight3(data)  ((0x000C0000&(data))>>18)
#define IM_DI_BLEND_AND_WEIGHTING_METHOD_get_ma_blend_fmcomb3(data)   ((0x00030000&(data))>>16)
#define IM_DI_BLEND_AND_WEIGHTING_METHOD_get_ma_blend_fmcomb2(data)   ((0x0000C000&(data))>>14)
#define IM_DI_BLEND_AND_WEIGHTING_METHOD_get_ma_blend_fmcomb1_hor(data)  ((0x00003000&(data))>>12)
#define IM_DI_BLEND_AND_WEIGHTING_METHOD_get_ma_blend_fmcomb1(data)   ((0x00000C00&(data))>>10)
#define IM_DI_BLEND_AND_WEIGHTING_METHOD_get_ma_blend_fmcomb0(data)   ((0x00000300&(data))>>8)
#define IM_DI_BLEND_AND_WEIGHTING_METHOD_get_ma_blend10_weight(data)  ((0x00000070&(data))>>4)
#define IM_DI_BLEND_AND_WEIGHTING_METHOD_get_ma_blend01_weight(data)  (0x00000007&(data))


#define IM_DI_MPEG_SEQUENCE_APP                                       0x1802404c
#define IM_DI_MPEG_SEQUENCE_APP_reg_addr                              "0xb802404c"
#define IM_DI_MPEG_SEQUENCE_APP_reg                                   0xb802404c
#define IM_DI_MPEG_SEQUENCE_APP_inst_addr                             "0x0013"
#define IM_DI_MPEG_SEQUENCE_APP_inst                                  0x0013
#define IM_DI_MPEG_SEQUENCE_APP_dummy1802404c_31_shift                (31)
#define IM_DI_MPEG_SEQUENCE_APP_ma_sobelthm_shift                     (21)
#define IM_DI_MPEG_SEQUENCE_APP_ma_sobelths_shift                     (11)
#define IM_DI_MPEG_SEQUENCE_APP_force_2d_timing_en_shift              (10)
#define IM_DI_MPEG_SEQUENCE_APP_force_2d_timing_mode_shift            (9)
#define IM_DI_MPEG_SEQUENCE_APP_field_diff1_shift                     (8)
#define IM_DI_MPEG_SEQUENCE_APP_vodma_film_en_shift                   (7)
#define IM_DI_MPEG_SEQUENCE_APP_field_diff1_sel_shift                 (6)
#define IM_DI_MPEG_SEQUENCE_APP_dummy1802404c_5_3_shift               (3)
#define IM_DI_MPEG_SEQUENCE_APP_force_di_nxt_shift                    (2)
#define IM_DI_MPEG_SEQUENCE_APP_force_dma_intra_shift                 (1)
#define IM_DI_MPEG_SEQUENCE_APP_force_dma_2d_shift                    (0)
#define IM_DI_MPEG_SEQUENCE_APP_dummy1802404c_31_mask                 (0x80000000)
#define IM_DI_MPEG_SEQUENCE_APP_ma_sobelthm_mask                      (0x7FE00000)
#define IM_DI_MPEG_SEQUENCE_APP_ma_sobelths_mask                      (0x001FF800)
#define IM_DI_MPEG_SEQUENCE_APP_force_2d_timing_en_mask               (0x00000400)
#define IM_DI_MPEG_SEQUENCE_APP_force_2d_timing_mode_mask             (0x00000200)
#define IM_DI_MPEG_SEQUENCE_APP_field_diff1_mask                      (0x00000100)
#define IM_DI_MPEG_SEQUENCE_APP_vodma_film_en_mask                    (0x00000080)
#define IM_DI_MPEG_SEQUENCE_APP_field_diff1_sel_mask                  (0x00000040)
#define IM_DI_MPEG_SEQUENCE_APP_dummy1802404c_5_3_mask                (0x00000038)
#define IM_DI_MPEG_SEQUENCE_APP_force_di_nxt_mask                     (0x00000004)
#define IM_DI_MPEG_SEQUENCE_APP_force_dma_intra_mask                  (0x00000002)
#define IM_DI_MPEG_SEQUENCE_APP_force_dma_2d_mask                     (0x00000001)
#define IM_DI_MPEG_SEQUENCE_APP_dummy1802404c_31(data)                (0x80000000&((data)<<31))
#define IM_DI_MPEG_SEQUENCE_APP_ma_sobelthm(data)                     (0x7FE00000&((data)<<21))
#define IM_DI_MPEG_SEQUENCE_APP_ma_sobelths(data)                     (0x001FF800&((data)<<11))
#define IM_DI_MPEG_SEQUENCE_APP_force_2d_timing_en(data)              (0x00000400&((data)<<10))
#define IM_DI_MPEG_SEQUENCE_APP_force_2d_timing_mode(data)            (0x00000200&((data)<<9))
#define IM_DI_MPEG_SEQUENCE_APP_field_diff1(data)                     (0x00000100&((data)<<8))
#define IM_DI_MPEG_SEQUENCE_APP_vodma_film_en(data)                   (0x00000080&((data)<<7))
#define IM_DI_MPEG_SEQUENCE_APP_field_diff1_sel(data)                 (0x00000040&((data)<<6))
#define IM_DI_MPEG_SEQUENCE_APP_dummy1802404c_5_3(data)               (0x00000038&((data)<<3))
#define IM_DI_MPEG_SEQUENCE_APP_force_di_nxt(data)                    (0x00000004&((data)<<2))
#define IM_DI_MPEG_SEQUENCE_APP_force_dma_intra(data)                 (0x00000002&((data)<<1))
#define IM_DI_MPEG_SEQUENCE_APP_force_dma_2d(data)                    (0x00000001&(data))
#define IM_DI_MPEG_SEQUENCE_APP_get_dummy1802404c_31(data)            ((0x80000000&(data))>>31)
#define IM_DI_MPEG_SEQUENCE_APP_get_ma_sobelthm(data)                 ((0x7FE00000&(data))>>21)
#define IM_DI_MPEG_SEQUENCE_APP_get_ma_sobelths(data)                 ((0x001FF800&(data))>>11)
#define IM_DI_MPEG_SEQUENCE_APP_get_force_2d_timing_en(data)          ((0x00000400&(data))>>10)
#define IM_DI_MPEG_SEQUENCE_APP_get_force_2d_timing_mode(data)        ((0x00000200&(data))>>9)
#define IM_DI_MPEG_SEQUENCE_APP_get_field_diff1(data)                 ((0x00000100&(data))>>8)
#define IM_DI_MPEG_SEQUENCE_APP_get_vodma_film_en(data)               ((0x00000080&(data))>>7)
#define IM_DI_MPEG_SEQUENCE_APP_get_field_diff1_sel(data)             ((0x00000040&(data))>>6)
#define IM_DI_MPEG_SEQUENCE_APP_get_dummy1802404c_5_3(data)           ((0x00000038&(data))>>3)
#define IM_DI_MPEG_SEQUENCE_APP_get_force_di_nxt(data)                ((0x00000004&(data))>>2)
#define IM_DI_MPEG_SEQUENCE_APP_get_force_dma_intra(data)             ((0x00000002&(data))>>1)
#define IM_DI_MPEG_SEQUENCE_APP_get_force_dma_2d(data)                (0x00000001&(data))


#define IM_DI_CLASSIFY2_TH                                            0x18024050
#define IM_DI_CLASSIFY2_TH_reg_addr                                   "0xb8024050"
#define IM_DI_CLASSIFY2_TH_reg                                        0xb8024050
#define IM_DI_CLASSIFY2_TH_inst_addr                                  "0x0014"
#define IM_DI_CLASSIFY2_TH_inst                                       0x0014
#define IM_DI_CLASSIFY2_TH_ma_vedge_nolp_en_shift                     (29)
#define IM_DI_CLASSIFY2_TH_ma_class_s_th2_shift                       (24)
#define IM_DI_CLASSIFY2_TH_ma_class_rlv_th1_cmp_shift                 (16)
#define IM_DI_CLASSIFY2_TH_ma_class_rlv_th1_shift                     (8)
#define IM_DI_CLASSIFY2_TH_ma_class_rlv_th2_shift                     (0)
#define IM_DI_CLASSIFY2_TH_ma_vedge_nolp_en_mask                      (0xE0000000)
#define IM_DI_CLASSIFY2_TH_ma_class_s_th2_mask                        (0x1F000000)
#define IM_DI_CLASSIFY2_TH_ma_class_rlv_th1_cmp_mask                  (0x001F0000)
#define IM_DI_CLASSIFY2_TH_ma_class_rlv_th1_mask                      (0x00001F00)
#define IM_DI_CLASSIFY2_TH_ma_class_rlv_th2_mask                      (0x0000001F)
#define IM_DI_CLASSIFY2_TH_ma_vedge_nolp_en(data)                     (0xE0000000&((data)<<29))
#define IM_DI_CLASSIFY2_TH_ma_class_s_th2(data)                       (0x1F000000&((data)<<24))
#define IM_DI_CLASSIFY2_TH_ma_class_rlv_th1_cmp(data)                 (0x001F0000&((data)<<16))
#define IM_DI_CLASSIFY2_TH_ma_class_rlv_th1(data)                     (0x00001F00&((data)<<8))
#define IM_DI_CLASSIFY2_TH_ma_class_rlv_th2(data)                     (0x0000001F&(data))
#define IM_DI_CLASSIFY2_TH_get_ma_vedge_nolp_en(data)                 ((0xE0000000&(data))>>29)
#define IM_DI_CLASSIFY2_TH_get_ma_class_s_th2(data)                   ((0x1F000000&(data))>>24)
#define IM_DI_CLASSIFY2_TH_get_ma_class_rlv_th1_cmp(data)             ((0x001F0000&(data))>>16)
#define IM_DI_CLASSIFY2_TH_get_ma_class_rlv_th1(data)                 ((0x00001F00&(data))>>8)
#define IM_DI_CLASSIFY2_TH_get_ma_class_rlv_th2(data)                 (0x0000001F&(data))


#define IM_DI_NEW_CLASS                                               0x18024054
#define IM_DI_NEW_CLASS_reg_addr                                      "0xb8024054"
#define IM_DI_NEW_CLASS_reg                                           0xb8024054
#define IM_DI_NEW_CLASS_inst_addr                                     "0x0015"
#define IM_DI_NEW_CLASS_inst                                          0x0015
#define IM_DI_NEW_CLASS_ma_new_class_en_shift                         (31)
#define IM_DI_NEW_CLASS_ma_vedge_add_rlv_shift                        (4)
#define IM_DI_NEW_CLASS_ma_vedge_nonlpfm_en_shift                     (2)
#define IM_DI_NEW_CLASS_ma_vedge_force90_en_shift                     (1)
#define IM_DI_NEW_CLASS_ma_vedge_force_intra_en_shift                 (0)
#define IM_DI_NEW_CLASS_ma_new_class_en_mask                          (0x80000000)
#define IM_DI_NEW_CLASS_ma_vedge_add_rlv_mask                         (0x00000030)
#define IM_DI_NEW_CLASS_ma_vedge_nonlpfm_en_mask                      (0x00000004)
#define IM_DI_NEW_CLASS_ma_vedge_force90_en_mask                      (0x00000002)
#define IM_DI_NEW_CLASS_ma_vedge_force_intra_en_mask                  (0x00000001)
#define IM_DI_NEW_CLASS_ma_new_class_en(data)                         (0x80000000&((data)<<31))
#define IM_DI_NEW_CLASS_ma_vedge_add_rlv(data)                        (0x00000030&((data)<<4))
#define IM_DI_NEW_CLASS_ma_vedge_nonlpfm_en(data)                     (0x00000004&((data)<<2))
#define IM_DI_NEW_CLASS_ma_vedge_force90_en(data)                     (0x00000002&((data)<<1))
#define IM_DI_NEW_CLASS_ma_vedge_force_intra_en(data)                 (0x00000001&(data))
#define IM_DI_NEW_CLASS_get_ma_new_class_en(data)                     ((0x80000000&(data))>>31)
#define IM_DI_NEW_CLASS_get_ma_vedge_add_rlv(data)                    ((0x00000030&(data))>>4)
#define IM_DI_NEW_CLASS_get_ma_vedge_nonlpfm_en(data)                 ((0x00000004&(data))>>2)
#define IM_DI_NEW_CLASS_get_ma_vedge_force90_en(data)                 ((0x00000002&(data))>>1)
#define IM_DI_NEW_CLASS_get_ma_vedge_force_intra_en(data)             (0x00000001&(data))


#define IM_DI_DMA                                                     0x18024058
#define IM_DI_DMA_reg_addr                                            "0xb8024058"
#define IM_DI_DMA_reg                                                 0xb8024058
#define IM_DI_DMA_inst_addr                                           "0x0016"
#define IM_DI_DMA_inst                                                0x0016
#define IM_DI_DMA_dma_420_en_shift                                    (30)
#define IM_DI_DMA_rdma_random_en_shift                                (29)
#define IM_DI_DMA_linesize_even_shift                                 (12)
#define IM_DI_DMA_linesize_odd_shift                                  (0)
#define IM_DI_DMA_dma_420_en_mask                                     (0xC0000000)
#define IM_DI_DMA_rdma_random_en_mask                                 (0x20000000)
#define IM_DI_DMA_linesize_even_mask                                  (0x003FF000)
#define IM_DI_DMA_linesize_odd_mask                                   (0x000003FF)
#define IM_DI_DMA_dma_420_en(data)                                    (0xC0000000&((data)<<30))
#define IM_DI_DMA_rdma_random_en(data)                                (0x20000000&((data)<<29))
#define IM_DI_DMA_linesize_even(data)                                 (0x003FF000&((data)<<12))
#define IM_DI_DMA_linesize_odd(data)                                  (0x000003FF&(data))
#define IM_DI_DMA_get_dma_420_en(data)                                ((0xC0000000&(data))>>30)
#define IM_DI_DMA_get_rdma_random_en(data)                            ((0x20000000&(data))>>29)
#define IM_DI_DMA_get_linesize_even(data)                             ((0x003FF000&(data))>>12)
#define IM_DI_DMA_get_linesize_odd(data)                              (0x000003FF&(data))


#define IM_DI_XC_AUTO_BALANCE_TH                                      0x18024068
#define IM_DI_XC_AUTO_BALANCE_TH_reg_addr                             "0xb8024068"
#define IM_DI_XC_AUTO_BALANCE_TH_reg                                  0xb8024068
#define IM_DI_XC_AUTO_BALANCE_TH_inst_addr                            "0x001A"
#define IM_DI_XC_AUTO_BALANCE_TH_inst                                 0x001A
#define IM_DI_XC_AUTO_BALANCE_TH_cr_var4thl_shift                     (24)
#define IM_DI_XC_AUTO_BALANCE_TH_cr_var3thl_shift                     (16)
#define IM_DI_XC_AUTO_BALANCE_TH_cr_var2thl_shift                     (8)
#define IM_DI_XC_AUTO_BALANCE_TH_cr_var1thl_shift                     (0)
#define IM_DI_XC_AUTO_BALANCE_TH_cr_var4thl_mask                      (0xFF000000)
#define IM_DI_XC_AUTO_BALANCE_TH_cr_var3thl_mask                      (0x00FF0000)
#define IM_DI_XC_AUTO_BALANCE_TH_cr_var2thl_mask                      (0x0000FF00)
#define IM_DI_XC_AUTO_BALANCE_TH_cr_var1thl_mask                      (0x000000FF)
#define IM_DI_XC_AUTO_BALANCE_TH_cr_var4thl(data)                     (0xFF000000&((data)<<24))
#define IM_DI_XC_AUTO_BALANCE_TH_cr_var3thl(data)                     (0x00FF0000&((data)<<16))
#define IM_DI_XC_AUTO_BALANCE_TH_cr_var2thl(data)                     (0x0000FF00&((data)<<8))
#define IM_DI_XC_AUTO_BALANCE_TH_cr_var1thl(data)                     (0x000000FF&(data))
#define IM_DI_XC_AUTO_BALANCE_TH_get_cr_var4thl(data)                 ((0xFF000000&(data))>>24)
#define IM_DI_XC_AUTO_BALANCE_TH_get_cr_var3thl(data)                 ((0x00FF0000&(data))>>16)
#define IM_DI_XC_AUTO_BALANCE_TH_get_cr_var2thl(data)                 ((0x0000FF00&(data))>>8)
#define IM_DI_XC_AUTO_BALANCE_TH_get_cr_var1thl(data)                 (0x000000FF&(data))


#define IM_DI_XC_AUTO_BALANCE_TH2                                     0x1802406c
#define IM_DI_XC_AUTO_BALANCE_TH2_reg_addr                            "0xb802406c"
#define IM_DI_XC_AUTO_BALANCE_TH2_reg                                 0xb802406c
#define IM_DI_XC_AUTO_BALANCE_TH2_inst_addr                           "0x001B"
#define IM_DI_XC_AUTO_BALANCE_TH2_inst                                0x001B
#define IM_DI_XC_AUTO_BALANCE_TH2_cr_transitionthl_shift              (8)
#define IM_DI_XC_AUTO_BALANCE_TH2_cr_meanthl_shift                    (0)
#define IM_DI_XC_AUTO_BALANCE_TH2_cr_transitionthl_mask               (0x0000FF00)
#define IM_DI_XC_AUTO_BALANCE_TH2_cr_meanthl_mask                     (0x000000FF)
#define IM_DI_XC_AUTO_BALANCE_TH2_cr_transitionthl(data)              (0x0000FF00&((data)<<8))
#define IM_DI_XC_AUTO_BALANCE_TH2_cr_meanthl(data)                    (0x000000FF&(data))
#define IM_DI_XC_AUTO_BALANCE_TH2_get_cr_transitionthl(data)          ((0x0000FF00&(data))>>8)
#define IM_DI_XC_AUTO_BALANCE_TH2_get_cr_meanthl(data)                (0x000000FF&(data))


#define IM_DI_XC_AUTO_BALANCE_TH3                                     0x18024070
#define IM_DI_XC_AUTO_BALANCE_TH3_reg_addr                            "0xb8024070"
#define IM_DI_XC_AUTO_BALANCE_TH3_reg                                 0xb8024070
#define IM_DI_XC_AUTO_BALANCE_TH3_inst_addr                           "0x001C"
#define IM_DI_XC_AUTO_BALANCE_TH3_inst                                0x001C
#define IM_DI_XC_AUTO_BALANCE_TH3_cr_thl_mainbalance_shift            (16)
#define IM_DI_XC_AUTO_BALANCE_TH3_cr_thl_subbalance_shift             (0)
#define IM_DI_XC_AUTO_BALANCE_TH3_cr_thl_mainbalance_mask             (0x00FF0000)
#define IM_DI_XC_AUTO_BALANCE_TH3_cr_thl_subbalance_mask              (0x0000FFFF)
#define IM_DI_XC_AUTO_BALANCE_TH3_cr_thl_mainbalance(data)            (0x00FF0000&((data)<<16))
#define IM_DI_XC_AUTO_BALANCE_TH3_cr_thl_subbalance(data)             (0x0000FFFF&(data))
#define IM_DI_XC_AUTO_BALANCE_TH3_get_cr_thl_mainbalance(data)        ((0x00FF0000&(data))>>16)
#define IM_DI_XC_AUTO_BALANCE_TH3_get_cr_thl_subbalance(data)         (0x0000FFFF&(data))


#define IM_DI_INTRA_SOBEL_MOTION_TH                                   0x18024074
#define IM_DI_INTRA_SOBEL_MOTION_TH_reg_addr                          "0xb8024074"
#define IM_DI_INTRA_SOBEL_MOTION_TH_reg                               0xb8024074
#define IM_DI_INTRA_SOBEL_MOTION_TH_inst_addr                         "0x001D"
#define IM_DI_INTRA_SOBEL_MOTION_TH_inst                              0x001D
#define IM_DI_INTRA_SOBEL_MOTION_TH_stilllinecntns_window_mode_shift  (28)
#define IM_DI_INTRA_SOBEL_MOTION_TH_stilllinecntns_cond_th_shift      (26)
#define IM_DI_INTRA_SOBEL_MOTION_TH_stilllinecntns_window_th_shift    (21)
#define IM_DI_INTRA_SOBEL_MOTION_TH_stilllinecntns_window_shift       (18)
#define IM_DI_INTRA_SOBEL_MOTION_TH_stilllinecntns_apply_hmc_window_shift  (17)
#define IM_DI_INTRA_SOBEL_MOTION_TH_stillline_cntns_en_shift          (16)
#define IM_DI_INTRA_SOBEL_MOTION_TH_intra_motionthly_shift            (8)
#define IM_DI_INTRA_SOBEL_MOTION_TH_intra_motionthlc_shift            (0)
#define IM_DI_INTRA_SOBEL_MOTION_TH_stilllinecntns_window_mode_mask   (0x10000000)
#define IM_DI_INTRA_SOBEL_MOTION_TH_stilllinecntns_cond_th_mask       (0x0C000000)
#define IM_DI_INTRA_SOBEL_MOTION_TH_stilllinecntns_window_th_mask     (0x03E00000)
#define IM_DI_INTRA_SOBEL_MOTION_TH_stilllinecntns_window_mask        (0x001C0000)
#define IM_DI_INTRA_SOBEL_MOTION_TH_stilllinecntns_apply_hmc_window_mask  (0x00020000)
#define IM_DI_INTRA_SOBEL_MOTION_TH_stillline_cntns_en_mask           (0x00010000)
#define IM_DI_INTRA_SOBEL_MOTION_TH_intra_motionthly_mask             (0x0000FF00)
#define IM_DI_INTRA_SOBEL_MOTION_TH_intra_motionthlc_mask             (0x000000FF)
#define IM_DI_INTRA_SOBEL_MOTION_TH_stilllinecntns_window_mode(data)  (0x10000000&((data)<<28))
#define IM_DI_INTRA_SOBEL_MOTION_TH_stilllinecntns_cond_th(data)      (0x0C000000&((data)<<26))
#define IM_DI_INTRA_SOBEL_MOTION_TH_stilllinecntns_window_th(data)    (0x03E00000&((data)<<21))
#define IM_DI_INTRA_SOBEL_MOTION_TH_stilllinecntns_window(data)       (0x001C0000&((data)<<18))
#define IM_DI_INTRA_SOBEL_MOTION_TH_stilllinecntns_apply_hmc_window(data)  (0x00020000&((data)<<17))
#define IM_DI_INTRA_SOBEL_MOTION_TH_stillline_cntns_en(data)          (0x00010000&((data)<<16))
#define IM_DI_INTRA_SOBEL_MOTION_TH_intra_motionthly(data)            (0x0000FF00&((data)<<8))
#define IM_DI_INTRA_SOBEL_MOTION_TH_intra_motionthlc(data)            (0x000000FF&(data))
#define IM_DI_INTRA_SOBEL_MOTION_TH_get_stilllinecntns_window_mode(data)  ((0x10000000&(data))>>28)
#define IM_DI_INTRA_SOBEL_MOTION_TH_get_stilllinecntns_cond_th(data)  ((0x0C000000&(data))>>26)
#define IM_DI_INTRA_SOBEL_MOTION_TH_get_stilllinecntns_window_th(data)  ((0x03E00000&(data))>>21)
#define IM_DI_INTRA_SOBEL_MOTION_TH_get_stilllinecntns_window(data)   ((0x001C0000&(data))>>18)
#define IM_DI_INTRA_SOBEL_MOTION_TH_get_stilllinecntns_apply_hmc_window(data)  ((0x00020000&(data))>>17)
#define IM_DI_INTRA_SOBEL_MOTION_TH_get_stillline_cntns_en(data)      ((0x00010000&(data))>>16)
#define IM_DI_INTRA_SOBEL_MOTION_TH_get_intra_motionthly(data)        ((0x0000FF00&(data))>>8)
#define IM_DI_INTRA_SOBEL_MOTION_TH_get_intra_motionthlc(data)        (0x000000FF&(data))


#define IM_DI_INTRA_LINE_CONT_TH                                      0x18024078
#define IM_DI_INTRA_LINE_CONT_TH_reg_addr                             "0xb8024078"
#define IM_DI_INTRA_LINE_CONT_TH_reg                                  0xb8024078
#define IM_DI_INTRA_LINE_CONT_TH_inst_addr                            "0x001E"
#define IM_DI_INTRA_LINE_CONT_TH_inst                                 0x001E
#define IM_DI_INTRA_LINE_CONT_TH_intra_con1peakthly_shift             (24)
#define IM_DI_INTRA_LINE_CONT_TH_intra_con1peakthlc_shift             (16)
#define IM_DI_INTRA_LINE_CONT_TH_intra_con2interpolationthly_shift    (8)
#define IM_DI_INTRA_LINE_CONT_TH_intra_con3peakthly_shift             (0)
#define IM_DI_INTRA_LINE_CONT_TH_intra_con1peakthly_mask              (0xFF000000)
#define IM_DI_INTRA_LINE_CONT_TH_intra_con1peakthlc_mask              (0x00FF0000)
#define IM_DI_INTRA_LINE_CONT_TH_intra_con2interpolationthly_mask     (0x0000FF00)
#define IM_DI_INTRA_LINE_CONT_TH_intra_con3peakthly_mask              (0x000000FF)
#define IM_DI_INTRA_LINE_CONT_TH_intra_con1peakthly(data)             (0xFF000000&((data)<<24))
#define IM_DI_INTRA_LINE_CONT_TH_intra_con1peakthlc(data)             (0x00FF0000&((data)<<16))
#define IM_DI_INTRA_LINE_CONT_TH_intra_con2interpolationthly(data)    (0x0000FF00&((data)<<8))
#define IM_DI_INTRA_LINE_CONT_TH_intra_con3peakthly(data)             (0x000000FF&(data))
#define IM_DI_INTRA_LINE_CONT_TH_get_intra_con1peakthly(data)         ((0xFF000000&(data))>>24)
#define IM_DI_INTRA_LINE_CONT_TH_get_intra_con1peakthlc(data)         ((0x00FF0000&(data))>>16)
#define IM_DI_INTRA_LINE_CONT_TH_get_intra_con2interpolationthly(data)  ((0x0000FF00&(data))>>8)
#define IM_DI_INTRA_LINE_CONT_TH_get_intra_con3peakthly(data)         (0x000000FF&(data))


#define IM_DI_INTRA_TH                                                0x1802407c
#define IM_DI_INTRA_TH_reg_addr                                       "0xb802407c"
#define IM_DI_INTRA_TH_reg                                            0xb802407c
#define IM_DI_INTRA_TH_inst_addr                                      "0x001F"
#define IM_DI_INTRA_TH_inst                                           0x001F
#define IM_DI_INTRA_TH_intra_mfilter_angle_range_shift                (26)
#define IM_DI_INTRA_TH_intra_mfilter_angle_enable_shift               (25)
#define IM_DI_INTRA_TH_intra_ma_mess_enable_shift                     (24)
#define IM_DI_INTRA_TH_intra_con2interpolationthly_mess_shift         (16)
#define IM_DI_INTRA_TH_intra_mfilterthl_shift                         (8)
#define IM_DI_INTRA_TH_intra_areaedgepixeldiffthly_shift              (0)
#define IM_DI_INTRA_TH_intra_mfilter_angle_range_mask                 (0x0C000000)
#define IM_DI_INTRA_TH_intra_mfilter_angle_enable_mask                (0x02000000)
#define IM_DI_INTRA_TH_intra_ma_mess_enable_mask                      (0x01000000)
#define IM_DI_INTRA_TH_intra_con2interpolationthly_mess_mask          (0x00FF0000)
#define IM_DI_INTRA_TH_intra_mfilterthl_mask                          (0x0000FF00)
#define IM_DI_INTRA_TH_intra_areaedgepixeldiffthly_mask               (0x000000FF)
#define IM_DI_INTRA_TH_intra_mfilter_angle_range(data)                (0x0C000000&((data)<<26))
#define IM_DI_INTRA_TH_intra_mfilter_angle_enable(data)               (0x02000000&((data)<<25))
#define IM_DI_INTRA_TH_intra_ma_mess_enable(data)                     (0x01000000&((data)<<24))
#define IM_DI_INTRA_TH_intra_con2interpolationthly_mess(data)         (0x00FF0000&((data)<<16))
#define IM_DI_INTRA_TH_intra_mfilterthl(data)                         (0x0000FF00&((data)<<8))
#define IM_DI_INTRA_TH_intra_areaedgepixeldiffthly(data)              (0x000000FF&(data))
#define IM_DI_INTRA_TH_get_intra_mfilter_angle_range(data)            ((0x0C000000&(data))>>26)
#define IM_DI_INTRA_TH_get_intra_mfilter_angle_enable(data)           ((0x02000000&(data))>>25)
#define IM_DI_INTRA_TH_get_intra_ma_mess_enable(data)                 ((0x01000000&(data))>>24)
#define IM_DI_INTRA_TH_get_intra_con2interpolationthly_mess(data)     ((0x00FF0000&(data))>>16)
#define IM_DI_INTRA_TH_get_intra_mfilterthl(data)                     ((0x0000FF00&(data))>>8)
#define IM_DI_INTRA_TH_get_intra_areaedgepixeldiffthly(data)          (0x000000FF&(data))


#define IM_DI_MA_FRAME_MOTION_TH_A                                    0x18024080
#define IM_DI_MA_FRAME_MOTION_TH_A_reg_addr                           "0xb8024080"
#define IM_DI_MA_FRAME_MOTION_TH_A_reg                                0xb8024080
#define IM_DI_MA_FRAME_MOTION_TH_A_inst_addr                          "0x0020"
#define IM_DI_MA_FRAME_MOTION_TH_A_inst                               0x0020
#define IM_DI_MA_FRAME_MOTION_TH_A_ma_framehtha_shift                 (24)
#define IM_DI_MA_FRAME_MOTION_TH_A_ma_framemtha_shift                 (16)
#define IM_DI_MA_FRAME_MOTION_TH_A_ma_framestha_shift                 (8)
#define IM_DI_MA_FRAME_MOTION_TH_A_ma_framerlvtha_shift               (0)
#define IM_DI_MA_FRAME_MOTION_TH_A_ma_framehtha_mask                  (0xFF000000)
#define IM_DI_MA_FRAME_MOTION_TH_A_ma_framemtha_mask                  (0x00FF0000)
#define IM_DI_MA_FRAME_MOTION_TH_A_ma_framestha_mask                  (0x0000FF00)
#define IM_DI_MA_FRAME_MOTION_TH_A_ma_framerlvtha_mask                (0x000000FF)
#define IM_DI_MA_FRAME_MOTION_TH_A_ma_framehtha(data)                 (0xFF000000&((data)<<24))
#define IM_DI_MA_FRAME_MOTION_TH_A_ma_framemtha(data)                 (0x00FF0000&((data)<<16))
#define IM_DI_MA_FRAME_MOTION_TH_A_ma_framestha(data)                 (0x0000FF00&((data)<<8))
#define IM_DI_MA_FRAME_MOTION_TH_A_ma_framerlvtha(data)               (0x000000FF&(data))
#define IM_DI_MA_FRAME_MOTION_TH_A_get_ma_framehtha(data)             ((0xFF000000&(data))>>24)
#define IM_DI_MA_FRAME_MOTION_TH_A_get_ma_framemtha(data)             ((0x00FF0000&(data))>>16)
#define IM_DI_MA_FRAME_MOTION_TH_A_get_ma_framestha(data)             ((0x0000FF00&(data))>>8)
#define IM_DI_MA_FRAME_MOTION_TH_A_get_ma_framerlvtha(data)           (0x000000FF&(data))


#define IM_DI_MA_FRAME_MOTION_TH_B                                    0x18024084
#define IM_DI_MA_FRAME_MOTION_TH_B_reg_addr                           "0xb8024084"
#define IM_DI_MA_FRAME_MOTION_TH_B_reg                                0xb8024084
#define IM_DI_MA_FRAME_MOTION_TH_B_inst_addr                          "0x0021"
#define IM_DI_MA_FRAME_MOTION_TH_B_inst                               0x0021
#define IM_DI_MA_FRAME_MOTION_TH_B_ma_framemthb_shift                 (24)
#define IM_DI_MA_FRAME_MOTION_TH_B_ma_framehthb_shift                 (16)
#define IM_DI_MA_FRAME_MOTION_TH_B_ma_framerlvthb_shift               (8)
#define IM_DI_MA_FRAME_MOTION_TH_B_ma_framesthb_shift                 (0)
#define IM_DI_MA_FRAME_MOTION_TH_B_ma_framemthb_mask                  (0xFF000000)
#define IM_DI_MA_FRAME_MOTION_TH_B_ma_framehthb_mask                  (0x00FF0000)
#define IM_DI_MA_FRAME_MOTION_TH_B_ma_framerlvthb_mask                (0x0000FF00)
#define IM_DI_MA_FRAME_MOTION_TH_B_ma_framesthb_mask                  (0x000000FF)
#define IM_DI_MA_FRAME_MOTION_TH_B_ma_framemthb(data)                 (0xFF000000&((data)<<24))
#define IM_DI_MA_FRAME_MOTION_TH_B_ma_framehthb(data)                 (0x00FF0000&((data)<<16))
#define IM_DI_MA_FRAME_MOTION_TH_B_ma_framerlvthb(data)               (0x0000FF00&((data)<<8))
#define IM_DI_MA_FRAME_MOTION_TH_B_ma_framesthb(data)                 (0x000000FF&(data))
#define IM_DI_MA_FRAME_MOTION_TH_B_get_ma_framemthb(data)             ((0xFF000000&(data))>>24)
#define IM_DI_MA_FRAME_MOTION_TH_B_get_ma_framehthb(data)             ((0x00FF0000&(data))>>16)
#define IM_DI_MA_FRAME_MOTION_TH_B_get_ma_framerlvthb(data)           ((0x0000FF00&(data))>>8)
#define IM_DI_MA_FRAME_MOTION_TH_B_get_ma_framesthb(data)             (0x000000FF&(data))


#define IM_DI_MA_FRAME_MOTION_TH_C                                    0x18024088
#define IM_DI_MA_FRAME_MOTION_TH_C_reg_addr                           "0xb8024088"
#define IM_DI_MA_FRAME_MOTION_TH_C_reg                                0xb8024088
#define IM_DI_MA_FRAME_MOTION_TH_C_inst_addr                          "0x0022"
#define IM_DI_MA_FRAME_MOTION_TH_C_inst                               0x0022
#define IM_DI_MA_FRAME_MOTION_TH_C_ma_framemthc_shift                 (24)
#define IM_DI_MA_FRAME_MOTION_TH_C_ma_framehthc_shift                 (16)
#define IM_DI_MA_FRAME_MOTION_TH_C_ma_framerlvthc_shift               (8)
#define IM_DI_MA_FRAME_MOTION_TH_C_ma_framesthc_shift                 (0)
#define IM_DI_MA_FRAME_MOTION_TH_C_ma_framemthc_mask                  (0xFF000000)
#define IM_DI_MA_FRAME_MOTION_TH_C_ma_framehthc_mask                  (0x00FF0000)
#define IM_DI_MA_FRAME_MOTION_TH_C_ma_framerlvthc_mask                (0x0000FF00)
#define IM_DI_MA_FRAME_MOTION_TH_C_ma_framesthc_mask                  (0x000000FF)
#define IM_DI_MA_FRAME_MOTION_TH_C_ma_framemthc(data)                 (0xFF000000&((data)<<24))
#define IM_DI_MA_FRAME_MOTION_TH_C_ma_framehthc(data)                 (0x00FF0000&((data)<<16))
#define IM_DI_MA_FRAME_MOTION_TH_C_ma_framerlvthc(data)               (0x0000FF00&((data)<<8))
#define IM_DI_MA_FRAME_MOTION_TH_C_ma_framesthc(data)                 (0x000000FF&(data))
#define IM_DI_MA_FRAME_MOTION_TH_C_get_ma_framemthc(data)             ((0xFF000000&(data))>>24)
#define IM_DI_MA_FRAME_MOTION_TH_C_get_ma_framehthc(data)             ((0x00FF0000&(data))>>16)
#define IM_DI_MA_FRAME_MOTION_TH_C_get_ma_framerlvthc(data)           ((0x0000FF00&(data))>>8)
#define IM_DI_MA_FRAME_MOTION_TH_C_get_ma_framesthc(data)             (0x000000FF&(data))


#define IM_DI_MA_FIELD_TEETH_TH_A                                     0x1802408c
#define IM_DI_MA_FIELD_TEETH_TH_A_reg_addr                            "0xb802408c"
#define IM_DI_MA_FIELD_TEETH_TH_A_reg                                 0xb802408c
#define IM_DI_MA_FIELD_TEETH_TH_A_inst_addr                           "0x0023"
#define IM_DI_MA_FIELD_TEETH_TH_A_inst                                0x0023
#define IM_DI_MA_FIELD_TEETH_TH_A_ma_fieldteethstha_shift             (24)
#define IM_DI_MA_FIELD_TEETH_TH_A_ma_fieldteethmtha_shift             (16)
#define IM_DI_MA_FIELD_TEETH_TH_A_ma_fieldteethhtha_shift             (8)
#define IM_DI_MA_FIELD_TEETH_TH_A_ma_fieldteethrlvtha_shift           (0)
#define IM_DI_MA_FIELD_TEETH_TH_A_ma_fieldteethstha_mask              (0xFF000000)
#define IM_DI_MA_FIELD_TEETH_TH_A_ma_fieldteethmtha_mask              (0x00FF0000)
#define IM_DI_MA_FIELD_TEETH_TH_A_ma_fieldteethhtha_mask              (0x0000FF00)
#define IM_DI_MA_FIELD_TEETH_TH_A_ma_fieldteethrlvtha_mask            (0x000000FF)
#define IM_DI_MA_FIELD_TEETH_TH_A_ma_fieldteethstha(data)             (0xFF000000&((data)<<24))
#define IM_DI_MA_FIELD_TEETH_TH_A_ma_fieldteethmtha(data)             (0x00FF0000&((data)<<16))
#define IM_DI_MA_FIELD_TEETH_TH_A_ma_fieldteethhtha(data)             (0x0000FF00&((data)<<8))
#define IM_DI_MA_FIELD_TEETH_TH_A_ma_fieldteethrlvtha(data)           (0x000000FF&(data))
#define IM_DI_MA_FIELD_TEETH_TH_A_get_ma_fieldteethstha(data)         ((0xFF000000&(data))>>24)
#define IM_DI_MA_FIELD_TEETH_TH_A_get_ma_fieldteethmtha(data)         ((0x00FF0000&(data))>>16)
#define IM_DI_MA_FIELD_TEETH_TH_A_get_ma_fieldteethhtha(data)         ((0x0000FF00&(data))>>8)
#define IM_DI_MA_FIELD_TEETH_TH_A_get_ma_fieldteethrlvtha(data)       (0x000000FF&(data))


#define IM_DI_MA_OTHERS_TH                                            0x18024090
#define IM_DI_MA_OTHERS_TH_reg_addr                                   "0xb8024090"
#define IM_DI_MA_OTHERS_TH_reg                                        0xb8024090
#define IM_DI_MA_OTHERS_TH_inst_addr                                  "0x0024"
#define IM_DI_MA_OTHERS_TH_inst                                       0x0024
#define IM_DI_MA_OTHERS_TH_ma_horicomth_shift                         (24)
#define IM_DI_MA_OTHERS_TH_ma_stilllogovdth_shift                     (16)
#define IM_DI_MA_OTHERS_TH_ma_ydiffth_shift                           (8)
#define IM_DI_MA_OTHERS_TH_ma_fieldteeththb_shift                     (0)
#define IM_DI_MA_OTHERS_TH_ma_horicomth_mask                          (0xFF000000)
#define IM_DI_MA_OTHERS_TH_ma_stilllogovdth_mask                      (0x00FF0000)
#define IM_DI_MA_OTHERS_TH_ma_ydiffth_mask                            (0x0000FF00)
#define IM_DI_MA_OTHERS_TH_ma_fieldteeththb_mask                      (0x000000FF)
#define IM_DI_MA_OTHERS_TH_ma_horicomth(data)                         (0xFF000000&((data)<<24))
#define IM_DI_MA_OTHERS_TH_ma_stilllogovdth(data)                     (0x00FF0000&((data)<<16))
#define IM_DI_MA_OTHERS_TH_ma_ydiffth(data)                           (0x0000FF00&((data)<<8))
#define IM_DI_MA_OTHERS_TH_ma_fieldteeththb(data)                     (0x000000FF&(data))
#define IM_DI_MA_OTHERS_TH_get_ma_horicomth(data)                     ((0xFF000000&(data))>>24)
#define IM_DI_MA_OTHERS_TH_get_ma_stilllogovdth(data)                 ((0x00FF0000&(data))>>16)
#define IM_DI_MA_OTHERS_TH_get_ma_ydiffth(data)                       ((0x0000FF00&(data))>>8)
#define IM_DI_MA_OTHERS_TH_get_ma_fieldteeththb(data)                 (0x000000FF&(data))


#define IM_DI_MA_SAWTOOTH_TH                                          0x18024094
#define IM_DI_MA_SAWTOOTH_TH_reg_addr                                 "0xb8024094"
#define IM_DI_MA_SAWTOOTH_TH_reg                                      0xb8024094
#define IM_DI_MA_SAWTOOTH_TH_inst_addr                                "0x0025"
#define IM_DI_MA_SAWTOOTH_TH_inst                                     0x0025
#define IM_DI_MA_SAWTOOTH_TH_ma_sawtoothmth_shift                     (24)
#define IM_DI_MA_SAWTOOTH_TH_ma_sawtoothhth_shift                     (16)
#define IM_DI_MA_SAWTOOTH_TH_ma_sawtoothrlvth_shift                   (8)
#define IM_DI_MA_SAWTOOTH_TH_ma_sawtoothsth_shift                     (0)
#define IM_DI_MA_SAWTOOTH_TH_ma_sawtoothmth_mask                      (0xFF000000)
#define IM_DI_MA_SAWTOOTH_TH_ma_sawtoothhth_mask                      (0x00FF0000)
#define IM_DI_MA_SAWTOOTH_TH_ma_sawtoothrlvth_mask                    (0x0000FF00)
#define IM_DI_MA_SAWTOOTH_TH_ma_sawtoothsth_mask                      (0x000000FF)
#define IM_DI_MA_SAWTOOTH_TH_ma_sawtoothmth(data)                     (0xFF000000&((data)<<24))
#define IM_DI_MA_SAWTOOTH_TH_ma_sawtoothhth(data)                     (0x00FF0000&((data)<<16))
#define IM_DI_MA_SAWTOOTH_TH_ma_sawtoothrlvth(data)                   (0x0000FF00&((data)<<8))
#define IM_DI_MA_SAWTOOTH_TH_ma_sawtoothsth(data)                     (0x000000FF&(data))
#define IM_DI_MA_SAWTOOTH_TH_get_ma_sawtoothmth(data)                 ((0xFF000000&(data))>>24)
#define IM_DI_MA_SAWTOOTH_TH_get_ma_sawtoothhth(data)                 ((0x00FF0000&(data))>>16)
#define IM_DI_MA_SAWTOOTH_TH_get_ma_sawtoothrlvth(data)               ((0x0000FF00&(data))>>8)
#define IM_DI_MA_SAWTOOTH_TH_get_ma_sawtoothsth(data)                 (0x000000FF&(data))


#define IM_DI_MA_VERTEXT_TH_A                                         0x18024098
#define IM_DI_MA_VERTEXT_TH_A_reg_addr                                "0xb8024098"
#define IM_DI_MA_VERTEXT_TH_A_reg                                     0xb8024098
#define IM_DI_MA_VERTEXT_TH_A_inst_addr                               "0x0026"
#define IM_DI_MA_VERTEXT_TH_A_inst                                    0x0026
#define IM_DI_MA_VERTEXT_TH_A_ma_vertrange_shift                      (20)
#define IM_DI_MA_VERTEXT_TH_A_ma_vertleftstart_shift                  (10)
#define IM_DI_MA_VERTEXT_TH_A_ma_vertrightstart_shift                 (0)
#define IM_DI_MA_VERTEXT_TH_A_ma_vertrange_mask                       (0x3FF00000)
#define IM_DI_MA_VERTEXT_TH_A_ma_vertleftstart_mask                   (0x000FFC00)
#define IM_DI_MA_VERTEXT_TH_A_ma_vertrightstart_mask                  (0x000003FF)
#define IM_DI_MA_VERTEXT_TH_A_ma_vertrange(data)                      (0x3FF00000&((data)<<20))
#define IM_DI_MA_VERTEXT_TH_A_ma_vertleftstart(data)                  (0x000FFC00&((data)<<10))
#define IM_DI_MA_VERTEXT_TH_A_ma_vertrightstart(data)                 (0x000003FF&(data))
#define IM_DI_MA_VERTEXT_TH_A_get_ma_vertrange(data)                  ((0x3FF00000&(data))>>20)
#define IM_DI_MA_VERTEXT_TH_A_get_ma_vertleftstart(data)              ((0x000FFC00&(data))>>10)
#define IM_DI_MA_VERTEXT_TH_A_get_ma_vertrightstart(data)             (0x000003FF&(data))


#define IM_DI_MA_VERTEXT_TH_B                                         0x1802409c
#define IM_DI_MA_VERTEXT_TH_B_reg_addr                                "0xb802409c"
#define IM_DI_MA_VERTEXT_TH_B_reg                                     0xb802409c
#define IM_DI_MA_VERTEXT_TH_B_inst_addr                               "0x0027"
#define IM_DI_MA_VERTEXT_TH_B_inst                                    0x0027
#define IM_DI_MA_VERTEXT_TH_B_ma_vertth1_shift                        (24)
#define IM_DI_MA_VERTEXT_TH_B_ma_vertth2_shift                        (16)
#define IM_DI_MA_VERTEXT_TH_B_ma_vertth3_shift                        (8)
#define IM_DI_MA_VERTEXT_TH_B_ma_vertth4_shift                        (0)
#define IM_DI_MA_VERTEXT_TH_B_ma_vertth1_mask                         (0xFF000000)
#define IM_DI_MA_VERTEXT_TH_B_ma_vertth2_mask                         (0x00FF0000)
#define IM_DI_MA_VERTEXT_TH_B_ma_vertth3_mask                         (0x0000FF00)
#define IM_DI_MA_VERTEXT_TH_B_ma_vertth4_mask                         (0x000000FF)
#define IM_DI_MA_VERTEXT_TH_B_ma_vertth1(data)                        (0xFF000000&((data)<<24))
#define IM_DI_MA_VERTEXT_TH_B_ma_vertth2(data)                        (0x00FF0000&((data)<<16))
#define IM_DI_MA_VERTEXT_TH_B_ma_vertth3(data)                        (0x0000FF00&((data)<<8))
#define IM_DI_MA_VERTEXT_TH_B_ma_vertth4(data)                        (0x000000FF&(data))
#define IM_DI_MA_VERTEXT_TH_B_get_ma_vertth1(data)                    ((0xFF000000&(data))>>24)
#define IM_DI_MA_VERTEXT_TH_B_get_ma_vertth2(data)                    ((0x00FF0000&(data))>>16)
#define IM_DI_MA_VERTEXT_TH_B_get_ma_vertth3(data)                    ((0x0000FF00&(data))>>8)
#define IM_DI_MA_VERTEXT_TH_B_get_ma_vertth4(data)                    (0x000000FF&(data))


#define IM_DI_FILM_SAWTOOTH_FILMFRAME_TH                              0x180240a0
#define IM_DI_FILM_SAWTOOTH_FILMFRAME_TH_reg_addr                     "0xb80240a0"
#define IM_DI_FILM_SAWTOOTH_FILMFRAME_TH_reg                          0xb80240a0
#define IM_DI_FILM_SAWTOOTH_FILMFRAME_TH_inst_addr                    "0x0028"
#define IM_DI_FILM_SAWTOOTH_FILMFRAME_TH_inst                         0x0028
#define IM_DI_FILM_SAWTOOTH_FILMFRAME_TH_film_leavequick_en_shift     (31)
#define IM_DI_FILM_SAWTOOTH_FILMFRAME_TH_film_verscrollingtext_en_shift  (30)
#define IM_DI_FILM_SAWTOOTH_FILMFRAME_TH_film_thumbnail_en_shift      (29)
#define IM_DI_FILM_SAWTOOTH_FILMFRAME_TH_film_pair1_en_shift          (28)
#define IM_DI_FILM_SAWTOOTH_FILMFRAME_TH_film_pair2_en_shift          (27)
#define IM_DI_FILM_SAWTOOTH_FILMFRAME_TH_film_pair_en_auto_shift      (26)
#define IM_DI_FILM_SAWTOOTH_FILMFRAME_TH_film_violate_strict_en_shift (25)
#define IM_DI_FILM_SAWTOOTH_FILMFRAME_TH_film22_sawtooththl_shift     (16)
#define IM_DI_FILM_SAWTOOTH_FILMFRAME_TH_film_sawtooththl_shift       (8)
#define IM_DI_FILM_SAWTOOTH_FILMFRAME_TH_film_frmotionthl_shift       (0)
#define IM_DI_FILM_SAWTOOTH_FILMFRAME_TH_film_leavequick_en_mask      (0x80000000)
#define IM_DI_FILM_SAWTOOTH_FILMFRAME_TH_film_verscrollingtext_en_mask  (0x40000000)
#define IM_DI_FILM_SAWTOOTH_FILMFRAME_TH_film_thumbnail_en_mask       (0x20000000)
#define IM_DI_FILM_SAWTOOTH_FILMFRAME_TH_film_pair1_en_mask           (0x10000000)
#define IM_DI_FILM_SAWTOOTH_FILMFRAME_TH_film_pair2_en_mask           (0x08000000)
#define IM_DI_FILM_SAWTOOTH_FILMFRAME_TH_film_pair_en_auto_mask       (0x04000000)
#define IM_DI_FILM_SAWTOOTH_FILMFRAME_TH_film_violate_strict_en_mask  (0x02000000)
#define IM_DI_FILM_SAWTOOTH_FILMFRAME_TH_film22_sawtooththl_mask      (0x00FF0000)
#define IM_DI_FILM_SAWTOOTH_FILMFRAME_TH_film_sawtooththl_mask        (0x0000FF00)
#define IM_DI_FILM_SAWTOOTH_FILMFRAME_TH_film_frmotionthl_mask        (0x000000FF)
#define IM_DI_FILM_SAWTOOTH_FILMFRAME_TH_film_leavequick_en(data)     (0x80000000&((data)<<31))
#define IM_DI_FILM_SAWTOOTH_FILMFRAME_TH_film_verscrollingtext_en(data)  (0x40000000&((data)<<30))
#define IM_DI_FILM_SAWTOOTH_FILMFRAME_TH_film_thumbnail_en(data)      (0x20000000&((data)<<29))
#define IM_DI_FILM_SAWTOOTH_FILMFRAME_TH_film_pair1_en(data)          (0x10000000&((data)<<28))
#define IM_DI_FILM_SAWTOOTH_FILMFRAME_TH_film_pair2_en(data)          (0x08000000&((data)<<27))
#define IM_DI_FILM_SAWTOOTH_FILMFRAME_TH_film_pair_en_auto(data)      (0x04000000&((data)<<26))
#define IM_DI_FILM_SAWTOOTH_FILMFRAME_TH_film_violate_strict_en(data) (0x02000000&((data)<<25))
#define IM_DI_FILM_SAWTOOTH_FILMFRAME_TH_film22_sawtooththl(data)     (0x00FF0000&((data)<<16))
#define IM_DI_FILM_SAWTOOTH_FILMFRAME_TH_film_sawtooththl(data)       (0x0000FF00&((data)<<8))
#define IM_DI_FILM_SAWTOOTH_FILMFRAME_TH_film_frmotionthl(data)       (0x000000FF&(data))
#define IM_DI_FILM_SAWTOOTH_FILMFRAME_TH_get_film_leavequick_en(data) ((0x80000000&(data))>>31)
#define IM_DI_FILM_SAWTOOTH_FILMFRAME_TH_get_film_verscrollingtext_en(data)  ((0x40000000&(data))>>30)
#define IM_DI_FILM_SAWTOOTH_FILMFRAME_TH_get_film_thumbnail_en(data)  ((0x20000000&(data))>>29)
#define IM_DI_FILM_SAWTOOTH_FILMFRAME_TH_get_film_pair1_en(data)      ((0x10000000&(data))>>28)
#define IM_DI_FILM_SAWTOOTH_FILMFRAME_TH_get_film_pair2_en(data)      ((0x08000000&(data))>>27)
#define IM_DI_FILM_SAWTOOTH_FILMFRAME_TH_get_film_pair_en_auto(data)  ((0x04000000&(data))>>26)
#define IM_DI_FILM_SAWTOOTH_FILMFRAME_TH_get_film_violate_strict_en(data)  ((0x02000000&(data))>>25)
#define IM_DI_FILM_SAWTOOTH_FILMFRAME_TH_get_film22_sawtooththl(data) ((0x00FF0000&(data))>>16)
#define IM_DI_FILM_SAWTOOTH_FILMFRAME_TH_get_film_sawtooththl(data)   ((0x0000FF00&(data))>>8)
#define IM_DI_FILM_SAWTOOTH_FILMFRAME_TH_get_film_frmotionthl(data)   (0x000000FF&(data))


#define IM_DI_FILM_STATIC_SUM_TH                                      0x180240a4
#define IM_DI_FILM_STATIC_SUM_TH_reg_addr                             "0xb80240a4"
#define IM_DI_FILM_STATIC_SUM_TH_reg                                  0xb80240a4
#define IM_DI_FILM_STATIC_SUM_TH_inst_addr                            "0x0029"
#define IM_DI_FILM_STATIC_SUM_TH_inst                                 0x0029
#define IM_DI_FILM_STATIC_SUM_TH_film_fieldmotionsumthl_shift         (24)
#define IM_DI_FILM_STATIC_SUM_TH_film22_fistaticsthl_shift            (16)
#define IM_DI_FILM_STATIC_SUM_TH_film_frstaticsthl_shift              (8)
#define IM_DI_FILM_STATIC_SUM_TH_film_fistaticsthl_shift              (0)
#define IM_DI_FILM_STATIC_SUM_TH_film_fieldmotionsumthl_mask          (0xFF000000)
#define IM_DI_FILM_STATIC_SUM_TH_film22_fistaticsthl_mask             (0x00FF0000)
#define IM_DI_FILM_STATIC_SUM_TH_film_frstaticsthl_mask               (0x0000FF00)
#define IM_DI_FILM_STATIC_SUM_TH_film_fistaticsthl_mask               (0x000000FF)
#define IM_DI_FILM_STATIC_SUM_TH_film_fieldmotionsumthl(data)         (0xFF000000&((data)<<24))
#define IM_DI_FILM_STATIC_SUM_TH_film22_fistaticsthl(data)            (0x00FF0000&((data)<<16))
#define IM_DI_FILM_STATIC_SUM_TH_film_frstaticsthl(data)              (0x0000FF00&((data)<<8))
#define IM_DI_FILM_STATIC_SUM_TH_film_fistaticsthl(data)              (0x000000FF&(data))
#define IM_DI_FILM_STATIC_SUM_TH_get_film_fieldmotionsumthl(data)     ((0xFF000000&(data))>>24)
#define IM_DI_FILM_STATIC_SUM_TH_get_film22_fistaticsthl(data)        ((0x00FF0000&(data))>>16)
#define IM_DI_FILM_STATIC_SUM_TH_get_film_frstaticsthl(data)          ((0x0000FF00&(data))>>8)
#define IM_DI_FILM_STATIC_SUM_TH_get_film_fistaticsthl(data)          (0x000000FF&(data))


#define IM_DI_FILM_FIELD_JUDGE_TH                                     0x180240a8
#define IM_DI_FILM_FIELD_JUDGE_TH_reg_addr                            "0xb80240a8"
#define IM_DI_FILM_FIELD_JUDGE_TH_reg                                 0xb80240a8
#define IM_DI_FILM_FIELD_JUDGE_TH_inst_addr                           "0x002A"
#define IM_DI_FILM_FIELD_JUDGE_TH_inst                                0x002A
#define IM_DI_FILM_FIELD_JUDGE_TH_film_pairratio_all1_shift           (28)
#define IM_DI_FILM_FIELD_JUDGE_TH_film_pairratio_all2_shift           (24)
#define IM_DI_FILM_FIELD_JUDGE_TH_film_fiminsthl_shift                (16)
#define IM_DI_FILM_FIELD_JUDGE_TH_film_fimaxsthl_shift                (0)
#define IM_DI_FILM_FIELD_JUDGE_TH_film_pairratio_all1_mask            (0xF0000000)
#define IM_DI_FILM_FIELD_JUDGE_TH_film_pairratio_all2_mask            (0x0F000000)
#define IM_DI_FILM_FIELD_JUDGE_TH_film_fiminsthl_mask                 (0x00FF0000)
#define IM_DI_FILM_FIELD_JUDGE_TH_film_fimaxsthl_mask                 (0x0000FFFF)
#define IM_DI_FILM_FIELD_JUDGE_TH_film_pairratio_all1(data)           (0xF0000000&((data)<<28))
#define IM_DI_FILM_FIELD_JUDGE_TH_film_pairratio_all2(data)           (0x0F000000&((data)<<24))
#define IM_DI_FILM_FIELD_JUDGE_TH_film_fiminsthl(data)                (0x00FF0000&((data)<<16))
#define IM_DI_FILM_FIELD_JUDGE_TH_film_fimaxsthl(data)                (0x0000FFFF&(data))
#define IM_DI_FILM_FIELD_JUDGE_TH_get_film_pairratio_all1(data)       ((0xF0000000&(data))>>28)
#define IM_DI_FILM_FIELD_JUDGE_TH_get_film_pairratio_all2(data)       ((0x0F000000&(data))>>24)
#define IM_DI_FILM_FIELD_JUDGE_TH_get_film_fiminsthl(data)            ((0x00FF0000&(data))>>16)
#define IM_DI_FILM_FIELD_JUDGE_TH_get_film_fimaxsthl(data)            (0x0000FFFF&(data))


#define IM_DI_FILM_STATIC_SUM_SUB_TH                                  0x180240ac
#define IM_DI_FILM_STATIC_SUM_SUB_TH_reg_addr                         "0xb80240ac"
#define IM_DI_FILM_STATIC_SUM_SUB_TH_reg                              0xb80240ac
#define IM_DI_FILM_STATIC_SUM_SUB_TH_inst_addr                        "0x002B"
#define IM_DI_FILM_STATIC_SUM_SUB_TH_inst                             0x002B
#define IM_DI_FILM_STATIC_SUM_SUB_TH_film_subfieldmotionsumthl_shift  (24)
#define IM_DI_FILM_STATIC_SUM_SUB_TH_film22_subfistaticsthl_shift     (16)
#define IM_DI_FILM_STATIC_SUM_SUB_TH_film_subfrstaticsthl_shift       (8)
#define IM_DI_FILM_STATIC_SUM_SUB_TH_film_subfistaticsthl_shift       (0)
#define IM_DI_FILM_STATIC_SUM_SUB_TH_film_subfieldmotionsumthl_mask   (0xFF000000)
#define IM_DI_FILM_STATIC_SUM_SUB_TH_film22_subfistaticsthl_mask      (0x00FF0000)
#define IM_DI_FILM_STATIC_SUM_SUB_TH_film_subfrstaticsthl_mask        (0x0000FF00)
#define IM_DI_FILM_STATIC_SUM_SUB_TH_film_subfistaticsthl_mask        (0x000000FF)
#define IM_DI_FILM_STATIC_SUM_SUB_TH_film_subfieldmotionsumthl(data)  (0xFF000000&((data)<<24))
#define IM_DI_FILM_STATIC_SUM_SUB_TH_film22_subfistaticsthl(data)     (0x00FF0000&((data)<<16))
#define IM_DI_FILM_STATIC_SUM_SUB_TH_film_subfrstaticsthl(data)       (0x0000FF00&((data)<<8))
#define IM_DI_FILM_STATIC_SUM_SUB_TH_film_subfistaticsthl(data)       (0x000000FF&(data))
#define IM_DI_FILM_STATIC_SUM_SUB_TH_get_film_subfieldmotionsumthl(data)  ((0xFF000000&(data))>>24)
#define IM_DI_FILM_STATIC_SUM_SUB_TH_get_film22_subfistaticsthl(data) ((0x00FF0000&(data))>>16)
#define IM_DI_FILM_STATIC_SUM_SUB_TH_get_film_subfrstaticsthl(data)   ((0x0000FF00&(data))>>8)
#define IM_DI_FILM_STATIC_SUM_SUB_TH_get_film_subfistaticsthl(data)   (0x000000FF&(data))


#define IM_DI_FILM_FIELD_JUDGE_SUB_TH                                 0x180240b0
#define IM_DI_FILM_FIELD_JUDGE_SUB_TH_reg_addr                        "0xb80240b0"
#define IM_DI_FILM_FIELD_JUDGE_SUB_TH_reg                             0xb80240b0
#define IM_DI_FILM_FIELD_JUDGE_SUB_TH_inst_addr                       "0x002C"
#define IM_DI_FILM_FIELD_JUDGE_SUB_TH_inst                            0x002C
#define IM_DI_FILM_FIELD_JUDGE_SUB_TH_film_pairratio_sub1_shift       (28)
#define IM_DI_FILM_FIELD_JUDGE_SUB_TH_film_pairratio_sub2_shift       (24)
#define IM_DI_FILM_FIELD_JUDGE_SUB_TH_film_subfiminsthl_shift         (16)
#define IM_DI_FILM_FIELD_JUDGE_SUB_TH_film_subfimaxsthl_shift         (0)
#define IM_DI_FILM_FIELD_JUDGE_SUB_TH_film_pairratio_sub1_mask        (0xF0000000)
#define IM_DI_FILM_FIELD_JUDGE_SUB_TH_film_pairratio_sub2_mask        (0x0F000000)
#define IM_DI_FILM_FIELD_JUDGE_SUB_TH_film_subfiminsthl_mask          (0x00FF0000)
#define IM_DI_FILM_FIELD_JUDGE_SUB_TH_film_subfimaxsthl_mask          (0x0000FFFF)
#define IM_DI_FILM_FIELD_JUDGE_SUB_TH_film_pairratio_sub1(data)       (0xF0000000&((data)<<28))
#define IM_DI_FILM_FIELD_JUDGE_SUB_TH_film_pairratio_sub2(data)       (0x0F000000&((data)<<24))
#define IM_DI_FILM_FIELD_JUDGE_SUB_TH_film_subfiminsthl(data)         (0x00FF0000&((data)<<16))
#define IM_DI_FILM_FIELD_JUDGE_SUB_TH_film_subfimaxsthl(data)         (0x0000FFFF&(data))
#define IM_DI_FILM_FIELD_JUDGE_SUB_TH_get_film_pairratio_sub1(data)   ((0xF0000000&(data))>>28)
#define IM_DI_FILM_FIELD_JUDGE_SUB_TH_get_film_pairratio_sub2(data)   ((0x0F000000&(data))>>24)
#define IM_DI_FILM_FIELD_JUDGE_SUB_TH_get_film_subfiminsthl(data)     ((0x00FF0000&(data))>>16)
#define IM_DI_FILM_FIELD_JUDGE_SUB_TH_get_film_subfimaxsthl(data)     (0x0000FFFF&(data))


#define IM_DI_FILM_MOTION_SUM_TH                                      0x180240b4
#define IM_DI_FILM_MOTION_SUM_TH_reg_addr                             "0xb80240b4"
#define IM_DI_FILM_MOTION_SUM_TH_reg                                  0xb80240b4
#define IM_DI_FILM_MOTION_SUM_TH_inst_addr                            "0x002D"
#define IM_DI_FILM_MOTION_SUM_TH_inst                                 0x002D
#define IM_DI_FILM_MOTION_SUM_TH_film22_debounce_fieldnum_shift       (28)
#define IM_DI_FILM_MOTION_SUM_TH_film32_debounce_fieldnum_shift       (24)
#define IM_DI_FILM_MOTION_SUM_TH_dummy180240b4_23_16_shift            (16)
#define IM_DI_FILM_MOTION_SUM_TH_film22_subfieldmotionsumthl_shift    (8)
#define IM_DI_FILM_MOTION_SUM_TH_film22_fieldmotionsumthl_shift       (0)
#define IM_DI_FILM_MOTION_SUM_TH_film22_debounce_fieldnum_mask        (0xF0000000)
#define IM_DI_FILM_MOTION_SUM_TH_film32_debounce_fieldnum_mask        (0x0F000000)
#define IM_DI_FILM_MOTION_SUM_TH_dummy180240b4_23_16_mask             (0x00FF0000)
#define IM_DI_FILM_MOTION_SUM_TH_film22_subfieldmotionsumthl_mask     (0x0000FF00)
#define IM_DI_FILM_MOTION_SUM_TH_film22_fieldmotionsumthl_mask        (0x000000FF)
#define IM_DI_FILM_MOTION_SUM_TH_film22_debounce_fieldnum(data)       (0xF0000000&((data)<<28))
#define IM_DI_FILM_MOTION_SUM_TH_film32_debounce_fieldnum(data)       (0x0F000000&((data)<<24))
#define IM_DI_FILM_MOTION_SUM_TH_dummy180240b4_23_16(data)            (0x00FF0000&((data)<<16))
#define IM_DI_FILM_MOTION_SUM_TH_film22_subfieldmotionsumthl(data)    (0x0000FF00&((data)<<8))
#define IM_DI_FILM_MOTION_SUM_TH_film22_fieldmotionsumthl(data)       (0x000000FF&(data))
#define IM_DI_FILM_MOTION_SUM_TH_get_film22_debounce_fieldnum(data)   ((0xF0000000&(data))>>28)
#define IM_DI_FILM_MOTION_SUM_TH_get_film32_debounce_fieldnum(data)   ((0x0F000000&(data))>>24)
#define IM_DI_FILM_MOTION_SUM_TH_get_dummy180240b4_23_16(data)        ((0x00FF0000&(data))>>16)
#define IM_DI_FILM_MOTION_SUM_TH_get_film22_subfieldmotionsumthl(data)  ((0x0000FF00&(data))>>8)
#define IM_DI_FILM_MOTION_SUM_TH_get_film22_fieldmotionsumthl(data)   (0x000000FF&(data))


#define RESERVED_0                                                    0x180240b8
#define RESERVED_0_reg_addr                                           "0xb80240b8"
#define RESERVED_0_reg                                                0xb80240b8
#define RESERVED_0_inst_addr                                          "0x002E"
#define RESERVED_0_inst                                               0x002E


#define RESERVED_1                                                    0x180240bc
#define RESERVED_1_reg_addr                                           "0xb80240bc"
#define RESERVED_1_reg                                                0xb80240bc
#define RESERVED_1_inst_addr                                          "0x002F"
#define RESERVED_1_inst                                               0x002F


#define IM_DI_SI_FILM_HB_COUT                                         0x180240c0
#define IM_DI_SI_FILM_HB_COUT_reg_addr                                "0xb80240c0"
#define IM_DI_SI_FILM_HB_COUT_reg                                     0xb80240c0
#define IM_DI_SI_FILM_HB_COUT_inst_addr                               "0x0030"
#define IM_DI_SI_FILM_HB_COUT_inst                                    0x0030
#define IM_DI_SI_FILM_HB_COUT_film_hifreq_thl_shift                   (16)
#define IM_DI_SI_FILM_HB_COUT_film_hifreq_cnt_thl_shift               (12)
#define IM_DI_SI_FILM_HB_COUT_film_3d_mode_shift                      (10)
#define IM_DI_SI_FILM_HB_COUT_film_motionstatus_choose_shift          (8)
#define IM_DI_SI_FILM_HB_COUT_film_hbcounter_shift                    (0)
#define IM_DI_SI_FILM_HB_COUT_film_hifreq_thl_mask                    (0xFFFF0000)
#define IM_DI_SI_FILM_HB_COUT_film_hifreq_cnt_thl_mask                (0x0000F000)
#define IM_DI_SI_FILM_HB_COUT_film_3d_mode_mask                       (0x00000C00)
#define IM_DI_SI_FILM_HB_COUT_film_motionstatus_choose_mask           (0x00000100)
#define IM_DI_SI_FILM_HB_COUT_film_hbcounter_mask                     (0x000000FF)
#define IM_DI_SI_FILM_HB_COUT_film_hifreq_thl(data)                   (0xFFFF0000&((data)<<16))
#define IM_DI_SI_FILM_HB_COUT_film_hifreq_cnt_thl(data)               (0x0000F000&((data)<<12))
#define IM_DI_SI_FILM_HB_COUT_film_3d_mode(data)                      (0x00000C00&((data)<<10))
#define IM_DI_SI_FILM_HB_COUT_film_motionstatus_choose(data)          (0x00000100&((data)<<8))
#define IM_DI_SI_FILM_HB_COUT_film_hbcounter(data)                    (0x000000FF&(data))
#define IM_DI_SI_FILM_HB_COUT_get_film_hifreq_thl(data)               ((0xFFFF0000&(data))>>16)
#define IM_DI_SI_FILM_HB_COUT_get_film_hifreq_cnt_thl(data)           ((0x0000F000&(data))>>12)
#define IM_DI_SI_FILM_HB_COUT_get_film_3d_mode(data)                  ((0x00000C00&(data))>>10)
#define IM_DI_SI_FILM_HB_COUT_get_film_motionstatus_choose(data)      ((0x00000100&(data))>>8)
#define IM_DI_SI_FILM_HB_COUT_get_film_hbcounter(data)                (0x000000FF&(data))


#define IM_DI_SI_FILM_FINAL_RESULT                                    0x180240c4
#define IM_DI_SI_FILM_FINAL_RESULT_reg_addr                           "0xb80240c4"
#define IM_DI_SI_FILM_FINAL_RESULT_reg                                0xb80240c4
#define IM_DI_SI_FILM_FINAL_RESULT_inst_addr                          "0x0031"
#define IM_DI_SI_FILM_FINAL_RESULT_inst                               0x0031
#define IM_DI_SI_FILM_FINAL_RESULT_dummy180240c4_31_9_shift           (9)
#define IM_DI_SI_FILM_FINAL_RESULT_film_hifreq_flag_shift             (8)
#define IM_DI_SI_FILM_FINAL_RESULT_film_detected_shift                (7)
#define IM_DI_SI_FILM_FINAL_RESULT_film_subdetected_shift             (6)
#define IM_DI_SI_FILM_FINAL_RESULT_film_confuse_shift                 (5)
#define IM_DI_SI_FILM_FINAL_RESULT_film_sequence_shift                (0)
#define IM_DI_SI_FILM_FINAL_RESULT_dummy180240c4_31_9_mask            (0xFFFFFE00)
#define IM_DI_SI_FILM_FINAL_RESULT_film_hifreq_flag_mask              (0x00000100)
#define IM_DI_SI_FILM_FINAL_RESULT_film_detected_mask                 (0x00000080)
#define IM_DI_SI_FILM_FINAL_RESULT_film_subdetected_mask              (0x00000040)
#define IM_DI_SI_FILM_FINAL_RESULT_film_confuse_mask                  (0x00000020)
#define IM_DI_SI_FILM_FINAL_RESULT_film_sequence_mask                 (0x0000001F)
#define IM_DI_SI_FILM_FINAL_RESULT_dummy180240c4_31_9(data)           (0xFFFFFE00&((data)<<9))
#define IM_DI_SI_FILM_FINAL_RESULT_film_hifreq_flag(data)             (0x00000100&((data)<<8))
#define IM_DI_SI_FILM_FINAL_RESULT_film_detected(data)                (0x00000080&((data)<<7))
#define IM_DI_SI_FILM_FINAL_RESULT_film_subdetected(data)             (0x00000040&((data)<<6))
#define IM_DI_SI_FILM_FINAL_RESULT_film_confuse(data)                 (0x00000020&((data)<<5))
#define IM_DI_SI_FILM_FINAL_RESULT_film_sequence(data)                (0x0000001F&(data))
#define IM_DI_SI_FILM_FINAL_RESULT_get_dummy180240c4_31_9(data)       ((0xFFFFFE00&(data))>>9)
#define IM_DI_SI_FILM_FINAL_RESULT_get_film_hifreq_flag(data)         ((0x00000100&(data))>>8)
#define IM_DI_SI_FILM_FINAL_RESULT_get_film_detected(data)            ((0x00000080&(data))>>7)
#define IM_DI_SI_FILM_FINAL_RESULT_get_film_subdetected(data)         ((0x00000040&(data))>>6)
#define IM_DI_SI_FILM_FINAL_RESULT_get_film_confuse(data)             ((0x00000020&(data))>>5)
#define IM_DI_SI_FILM_FINAL_RESULT_get_film_sequence(data)            (0x0000001F&(data))


#define IM_DI_SI_FILM_PATTERN_A                                       0x180240c8
#define IM_DI_SI_FILM_PATTERN_A_reg_addr                              "0xb80240c8"
#define IM_DI_SI_FILM_PATTERN_A_reg                                   0xb80240c8
#define IM_DI_SI_FILM_PATTERN_A_inst_addr                             "0x0032"
#define IM_DI_SI_FILM_PATTERN_A_inst                                  0x0032
#define IM_DI_SI_FILM_PATTERN_A_film_framestatic_shift                (24)
#define IM_DI_SI_FILM_PATTERN_A_film_framepair_shift                  (8)
#define IM_DI_SI_FILM_PATTERN_A_film_prefistatic1_shift               (0)
#define IM_DI_SI_FILM_PATTERN_A_film_framestatic_mask                 (0xFF000000)
#define IM_DI_SI_FILM_PATTERN_A_film_framepair_mask                   (0x00FFFF00)
#define IM_DI_SI_FILM_PATTERN_A_film_prefistatic1_mask                (0x000000FF)
#define IM_DI_SI_FILM_PATTERN_A_film_framestatic(data)                (0xFF000000&((data)<<24))
#define IM_DI_SI_FILM_PATTERN_A_film_framepair(data)                  (0x00FFFF00&((data)<<8))
#define IM_DI_SI_FILM_PATTERN_A_film_prefistatic1(data)               (0x000000FF&(data))
#define IM_DI_SI_FILM_PATTERN_A_get_film_framestatic(data)            ((0xFF000000&(data))>>24)
#define IM_DI_SI_FILM_PATTERN_A_get_film_framepair(data)              ((0x00FFFF00&(data))>>8)
#define IM_DI_SI_FILM_PATTERN_A_get_film_prefistatic1(data)           (0x000000FF&(data))


#define IM_DI_SI_FILM_PATTERN_B                                       0x180240cc
#define IM_DI_SI_FILM_PATTERN_B_reg_addr                              "0xb80240cc"
#define IM_DI_SI_FILM_PATTERN_B_reg                                   0xb80240cc
#define IM_DI_SI_FILM_PATTERN_B_inst_addr                             "0x0033"
#define IM_DI_SI_FILM_PATTERN_B_inst                                  0x0033
#define IM_DI_SI_FILM_PATTERN_B_film_nxtfistatic1_shift               (24)
#define IM_DI_SI_FILM_PATTERN_B_film_prefistatic2_shift               (16)
#define IM_DI_SI_FILM_PATTERN_B_film_nxtfistatic2_shift               (8)
#define IM_DI_SI_FILM_PATTERN_B_film_nxtfimotion_shift                (0)
#define IM_DI_SI_FILM_PATTERN_B_film_nxtfistatic1_mask                (0xFF000000)
#define IM_DI_SI_FILM_PATTERN_B_film_prefistatic2_mask                (0x00FF0000)
#define IM_DI_SI_FILM_PATTERN_B_film_nxtfistatic2_mask                (0x0000FF00)
#define IM_DI_SI_FILM_PATTERN_B_film_nxtfimotion_mask                 (0x000000FF)
#define IM_DI_SI_FILM_PATTERN_B_film_nxtfistatic1(data)               (0xFF000000&((data)<<24))
#define IM_DI_SI_FILM_PATTERN_B_film_prefistatic2(data)               (0x00FF0000&((data)<<16))
#define IM_DI_SI_FILM_PATTERN_B_film_nxtfistatic2(data)               (0x0000FF00&((data)<<8))
#define IM_DI_SI_FILM_PATTERN_B_film_nxtfimotion(data)                (0x000000FF&(data))
#define IM_DI_SI_FILM_PATTERN_B_get_film_nxtfistatic1(data)           ((0xFF000000&(data))>>24)
#define IM_DI_SI_FILM_PATTERN_B_get_film_prefistatic2(data)           ((0x00FF0000&(data))>>16)
#define IM_DI_SI_FILM_PATTERN_B_get_film_nxtfistatic2(data)           ((0x0000FF00&(data))>>8)
#define IM_DI_SI_FILM_PATTERN_B_get_film_nxtfimotion(data)            (0x000000FF&(data))


#define IM_DI_SI_FILM_32_RESULT_1_A                                   0x180240d0
#define IM_DI_SI_FILM_32_RESULT_1_A_reg_addr                          "0xb80240d0"
#define IM_DI_SI_FILM_32_RESULT_1_A_reg                               0xb80240d0
#define IM_DI_SI_FILM_32_RESULT_1_A_inst_addr                         "0x0034"
#define IM_DI_SI_FILM_32_RESULT_1_A_inst                              0x0034
#define IM_DI_SI_FILM_32_RESULT_1_A_film_detected321_shift            (24)
#define IM_DI_SI_FILM_32_RESULT_1_A_film_match321_shift               (16)
#define IM_DI_SI_FILM_32_RESULT_1_A_film_violate321_shift             (8)
#define IM_DI_SI_FILM_32_RESULT_1_A_film_sequence321_39_32_shift      (0)
#define IM_DI_SI_FILM_32_RESULT_1_A_film_detected321_mask             (0xFF000000)
#define IM_DI_SI_FILM_32_RESULT_1_A_film_match321_mask                (0x00FF0000)
#define IM_DI_SI_FILM_32_RESULT_1_A_film_violate321_mask              (0x0000FF00)
#define IM_DI_SI_FILM_32_RESULT_1_A_film_sequence321_39_32_mask       (0x000000FF)
#define IM_DI_SI_FILM_32_RESULT_1_A_film_detected321(data)            (0xFF000000&((data)<<24))
#define IM_DI_SI_FILM_32_RESULT_1_A_film_match321(data)               (0x00FF0000&((data)<<16))
#define IM_DI_SI_FILM_32_RESULT_1_A_film_violate321(data)             (0x0000FF00&((data)<<8))
#define IM_DI_SI_FILM_32_RESULT_1_A_film_sequence321_39_32(data)      (0x000000FF&(data))
#define IM_DI_SI_FILM_32_RESULT_1_A_get_film_detected321(data)        ((0xFF000000&(data))>>24)
#define IM_DI_SI_FILM_32_RESULT_1_A_get_film_match321(data)           ((0x00FF0000&(data))>>16)
#define IM_DI_SI_FILM_32_RESULT_1_A_get_film_violate321(data)         ((0x0000FF00&(data))>>8)
#define IM_DI_SI_FILM_32_RESULT_1_A_get_film_sequence321_39_32(data)  (0x000000FF&(data))


#define IM_DI_SI_FILM_32_RESULT_1_B                                   0x180240d4
#define IM_DI_SI_FILM_32_RESULT_1_B_reg_addr                          "0xb80240d4"
#define IM_DI_SI_FILM_32_RESULT_1_B_reg                               0xb80240d4
#define IM_DI_SI_FILM_32_RESULT_1_B_inst_addr                         "0x0035"
#define IM_DI_SI_FILM_32_RESULT_1_B_inst                              0x0035
#define IM_DI_SI_FILM_32_RESULT_1_B_film_sequence321_31_0_shift       (0)
#define IM_DI_SI_FILM_32_RESULT_1_B_film_sequence321_31_0_mask        (0xFFFFFFFF)
#define IM_DI_SI_FILM_32_RESULT_1_B_film_sequence321_31_0(data)       (0xFFFFFFFF&(data))
#define IM_DI_SI_FILM_32_RESULT_1_B_get_film_sequence321_31_0(data)   (0xFFFFFFFF&(data))


#define IM_DI_SI_FILM_32_RESULT_2_A                                   0x180240d8
#define IM_DI_SI_FILM_32_RESULT_2_A_reg_addr                          "0xb80240d8"
#define IM_DI_SI_FILM_32_RESULT_2_A_reg                               0xb80240d8
#define IM_DI_SI_FILM_32_RESULT_2_A_inst_addr                         "0x0036"
#define IM_DI_SI_FILM_32_RESULT_2_A_inst                              0x0036
#define IM_DI_SI_FILM_32_RESULT_2_A_film_detected322_shift            (24)
#define IM_DI_SI_FILM_32_RESULT_2_A_film_match322_shift               (16)
#define IM_DI_SI_FILM_32_RESULT_2_A_film_violate322_shift             (8)
#define IM_DI_SI_FILM_32_RESULT_2_A_film_sequence322_39_32_shift      (0)
#define IM_DI_SI_FILM_32_RESULT_2_A_film_detected322_mask             (0xFF000000)
#define IM_DI_SI_FILM_32_RESULT_2_A_film_match322_mask                (0x00FF0000)
#define IM_DI_SI_FILM_32_RESULT_2_A_film_violate322_mask              (0x0000FF00)
#define IM_DI_SI_FILM_32_RESULT_2_A_film_sequence322_39_32_mask       (0x000000FF)
#define IM_DI_SI_FILM_32_RESULT_2_A_film_detected322(data)            (0xFF000000&((data)<<24))
#define IM_DI_SI_FILM_32_RESULT_2_A_film_match322(data)               (0x00FF0000&((data)<<16))
#define IM_DI_SI_FILM_32_RESULT_2_A_film_violate322(data)             (0x0000FF00&((data)<<8))
#define IM_DI_SI_FILM_32_RESULT_2_A_film_sequence322_39_32(data)      (0x000000FF&(data))
#define IM_DI_SI_FILM_32_RESULT_2_A_get_film_detected322(data)        ((0xFF000000&(data))>>24)
#define IM_DI_SI_FILM_32_RESULT_2_A_get_film_match322(data)           ((0x00FF0000&(data))>>16)
#define IM_DI_SI_FILM_32_RESULT_2_A_get_film_violate322(data)         ((0x0000FF00&(data))>>8)
#define IM_DI_SI_FILM_32_RESULT_2_A_get_film_sequence322_39_32(data)  (0x000000FF&(data))


#define IM_DI_SI_FILM_32_RESULT_2_B                                   0x180240dc
#define IM_DI_SI_FILM_32_RESULT_2_B_reg_addr                          "0xb80240dc"
#define IM_DI_SI_FILM_32_RESULT_2_B_reg                               0xb80240dc
#define IM_DI_SI_FILM_32_RESULT_2_B_inst_addr                         "0x0037"
#define IM_DI_SI_FILM_32_RESULT_2_B_inst                              0x0037
#define IM_DI_SI_FILM_32_RESULT_2_B_film_sequence322_31_0_shift       (0)
#define IM_DI_SI_FILM_32_RESULT_2_B_film_sequence322_31_0_mask        (0xFFFFFFFF)
#define IM_DI_SI_FILM_32_RESULT_2_B_film_sequence322_31_0(data)       (0xFFFFFFFF&(data))
#define IM_DI_SI_FILM_32_RESULT_2_B_get_film_sequence322_31_0(data)   (0xFFFFFFFF&(data))


#define IM_DI_SI_FILM_22_RESULT_A                                     0x180240e0
#define IM_DI_SI_FILM_22_RESULT_A_reg_addr                            "0xb80240e0"
#define IM_DI_SI_FILM_22_RESULT_A_reg                                 0xb80240e0
#define IM_DI_SI_FILM_22_RESULT_A_inst_addr                           "0x0038"
#define IM_DI_SI_FILM_22_RESULT_A_inst                                0x0038
#define IM_DI_SI_FILM_22_RESULT_A_film_detected22_shift               (24)
#define IM_DI_SI_FILM_22_RESULT_A_film_match22_shift                  (16)
#define IM_DI_SI_FILM_22_RESULT_A_film_violate22_shift                (8)
#define IM_DI_SI_FILM_22_RESULT_A_film_sequence22_39_32_shift         (0)
#define IM_DI_SI_FILM_22_RESULT_A_film_detected22_mask                (0xFF000000)
#define IM_DI_SI_FILM_22_RESULT_A_film_match22_mask                   (0x00FF0000)
#define IM_DI_SI_FILM_22_RESULT_A_film_violate22_mask                 (0x0000FF00)
#define IM_DI_SI_FILM_22_RESULT_A_film_sequence22_39_32_mask          (0x000000FF)
#define IM_DI_SI_FILM_22_RESULT_A_film_detected22(data)               (0xFF000000&((data)<<24))
#define IM_DI_SI_FILM_22_RESULT_A_film_match22(data)                  (0x00FF0000&((data)<<16))
#define IM_DI_SI_FILM_22_RESULT_A_film_violate22(data)                (0x0000FF00&((data)<<8))
#define IM_DI_SI_FILM_22_RESULT_A_film_sequence22_39_32(data)         (0x000000FF&(data))
#define IM_DI_SI_FILM_22_RESULT_A_get_film_detected22(data)           ((0xFF000000&(data))>>24)
#define IM_DI_SI_FILM_22_RESULT_A_get_film_match22(data)              ((0x00FF0000&(data))>>16)
#define IM_DI_SI_FILM_22_RESULT_A_get_film_violate22(data)            ((0x0000FF00&(data))>>8)
#define IM_DI_SI_FILM_22_RESULT_A_get_film_sequence22_39_32(data)     (0x000000FF&(data))


#define IM_DI_SI_FILM_22_RESULT_B                                     0x180240e4
#define IM_DI_SI_FILM_22_RESULT_B_reg_addr                            "0xb80240e4"
#define IM_DI_SI_FILM_22_RESULT_B_reg                                 0xb80240e4
#define IM_DI_SI_FILM_22_RESULT_B_inst_addr                           "0x0039"
#define IM_DI_SI_FILM_22_RESULT_B_inst                                0x0039
#define IM_DI_SI_FILM_22_RESULT_B_film_sequence22_31_0_shift          (0)
#define IM_DI_SI_FILM_22_RESULT_B_film_sequence22_31_0_mask           (0xFFFFFFFF)
#define IM_DI_SI_FILM_22_RESULT_B_film_sequence22_31_0(data)          (0xFFFFFFFF&(data))
#define IM_DI_SI_FILM_22_RESULT_B_get_film_sequence22_31_0(data)      (0xFFFFFFFF&(data))


#define IM_DI_SI_FILM_MOTION_NEXT                                     0x180240e8
#define IM_DI_SI_FILM_MOTION_NEXT_reg_addr                            "0xb80240e8"
#define IM_DI_SI_FILM_MOTION_NEXT_reg                                 0xb80240e8
#define IM_DI_SI_FILM_MOTION_NEXT_inst_addr                           "0x003A"
#define IM_DI_SI_FILM_MOTION_NEXT_inst                                0x003A
#define IM_DI_SI_FILM_MOTION_NEXT_film_motionstatus_719_700_shift     (0)
#define IM_DI_SI_FILM_MOTION_NEXT_film_motionstatus_719_700_mask      (0x000FFFFF)
#define IM_DI_SI_FILM_MOTION_NEXT_film_motionstatus_719_700(data)     (0x000FFFFF&(data))
#define IM_DI_SI_FILM_MOTION_NEXT_get_film_motionstatus_719_700(data) (0x000FFFFF&(data))


#define IM_DI_SI_FILM_MOTION_NEXT_H_T                                 0x180240ec
#define IM_DI_SI_FILM_MOTION_NEXT_H_T_reg_addr                        "0xb80240ec"
#define IM_DI_SI_FILM_MOTION_NEXT_H_T_reg                             0xb80240ec
#define IM_DI_SI_FILM_MOTION_NEXT_H_T_inst_addr                       "0x003B"
#define IM_DI_SI_FILM_MOTION_NEXT_H_T_inst                            0x003B
#define IM_DI_SI_FILM_MOTION_NEXT_H_T_film_motionstatus_699_680_shift (0)
#define IM_DI_SI_FILM_MOTION_NEXT_H_T_film_motionstatus_699_680_mask  (0x000FFFFF)
#define IM_DI_SI_FILM_MOTION_NEXT_H_T_film_motionstatus_699_680(data) (0x000FFFFF&(data))
#define IM_DI_SI_FILM_MOTION_NEXT_H_T_get_film_motionstatus_699_680(data)  (0x000FFFFF&(data))


#define IM_DI_SI_FILM_MOTION_NEXT_H_M                                 0x180240f0
#define IM_DI_SI_FILM_MOTION_NEXT_H_M_reg_addr                        "0xb80240f0"
#define IM_DI_SI_FILM_MOTION_NEXT_H_M_reg                             0xb80240f0
#define IM_DI_SI_FILM_MOTION_NEXT_H_M_inst_addr                       "0x003C"
#define IM_DI_SI_FILM_MOTION_NEXT_H_M_inst                            0x003C
#define IM_DI_SI_FILM_MOTION_NEXT_H_M_film_motionstatus_679_660_shift (0)
#define IM_DI_SI_FILM_MOTION_NEXT_H_M_film_motionstatus_679_660_mask  (0x000FFFFF)
#define IM_DI_SI_FILM_MOTION_NEXT_H_M_film_motionstatus_679_660(data) (0x000FFFFF&(data))
#define IM_DI_SI_FILM_MOTION_NEXT_H_M_get_film_motionstatus_679_660(data)  (0x000FFFFF&(data))


#define IM_DI_SI_FILM_MOTION_NEXT_H_B                                 0x180240f4
#define IM_DI_SI_FILM_MOTION_NEXT_H_B_reg_addr                        "0xb80240f4"
#define IM_DI_SI_FILM_MOTION_NEXT_H_B_reg                             0xb80240f4
#define IM_DI_SI_FILM_MOTION_NEXT_H_B_inst_addr                       "0x003D"
#define IM_DI_SI_FILM_MOTION_NEXT_H_B_inst                            0x003D
#define IM_DI_SI_FILM_MOTION_NEXT_H_B_film_motionstatus_659_640_shift (0)
#define IM_DI_SI_FILM_MOTION_NEXT_H_B_film_motionstatus_659_640_mask  (0x000FFFFF)
#define IM_DI_SI_FILM_MOTION_NEXT_H_B_film_motionstatus_659_640(data) (0x000FFFFF&(data))
#define IM_DI_SI_FILM_MOTION_NEXT_H_B_get_film_motionstatus_659_640(data)  (0x000FFFFF&(data))


#define IM_DI_SI_FILM_MOTION_NEXT_V_L                                 0x180240f8
#define IM_DI_SI_FILM_MOTION_NEXT_V_L_reg_addr                        "0xb80240f8"
#define IM_DI_SI_FILM_MOTION_NEXT_V_L_reg                             0xb80240f8
#define IM_DI_SI_FILM_MOTION_NEXT_V_L_inst_addr                       "0x003E"
#define IM_DI_SI_FILM_MOTION_NEXT_V_L_inst                            0x003E
#define IM_DI_SI_FILM_MOTION_NEXT_V_L_film_motionstatus_639_620_shift (0)
#define IM_DI_SI_FILM_MOTION_NEXT_V_L_film_motionstatus_639_620_mask  (0x000FFFFF)
#define IM_DI_SI_FILM_MOTION_NEXT_V_L_film_motionstatus_639_620(data) (0x000FFFFF&(data))
#define IM_DI_SI_FILM_MOTION_NEXT_V_L_get_film_motionstatus_639_620(data)  (0x000FFFFF&(data))


#define IM_DI_SI_FILM_MOTION_NEXT_V_M                                 0x180240fc
#define IM_DI_SI_FILM_MOTION_NEXT_V_M_reg_addr                        "0xb80240fc"
#define IM_DI_SI_FILM_MOTION_NEXT_V_M_reg                             0xb80240fc
#define IM_DI_SI_FILM_MOTION_NEXT_V_M_inst_addr                       "0x003F"
#define IM_DI_SI_FILM_MOTION_NEXT_V_M_inst                            0x003F
#define IM_DI_SI_FILM_MOTION_NEXT_V_M_film_motionstatus_619_600_shift (0)
#define IM_DI_SI_FILM_MOTION_NEXT_V_M_film_motionstatus_619_600_mask  (0x000FFFFF)
#define IM_DI_SI_FILM_MOTION_NEXT_V_M_film_motionstatus_619_600(data) (0x000FFFFF&(data))
#define IM_DI_SI_FILM_MOTION_NEXT_V_M_get_film_motionstatus_619_600(data)  (0x000FFFFF&(data))


#define IM_DI_SI_FILM_MOTION_NEXT_V_R                                 0x18024100
#define IM_DI_SI_FILM_MOTION_NEXT_V_R_reg_addr                        "0xb8024100"
#define IM_DI_SI_FILM_MOTION_NEXT_V_R_reg                             0xb8024100
#define IM_DI_SI_FILM_MOTION_NEXT_V_R_inst_addr                       "0x0040"
#define IM_DI_SI_FILM_MOTION_NEXT_V_R_inst                            0x0040
#define IM_DI_SI_FILM_MOTION_NEXT_V_R_film_motionstatus_599_580_shift (0)
#define IM_DI_SI_FILM_MOTION_NEXT_V_R_film_motionstatus_599_580_mask  (0x000FFFFF)
#define IM_DI_SI_FILM_MOTION_NEXT_V_R_film_motionstatus_599_580(data) (0x000FFFFF&(data))
#define IM_DI_SI_FILM_MOTION_NEXT_V_R_get_film_motionstatus_599_580(data)  (0x000FFFFF&(data))


#define IM_DI_SI_FILM_MOTION_NEXT_C                                   0x18024104
#define IM_DI_SI_FILM_MOTION_NEXT_C_reg_addr                          "0xb8024104"
#define IM_DI_SI_FILM_MOTION_NEXT_C_reg                               0xb8024104
#define IM_DI_SI_FILM_MOTION_NEXT_C_inst_addr                         "0x0041"
#define IM_DI_SI_FILM_MOTION_NEXT_C_inst                              0x0041
#define IM_DI_SI_FILM_MOTION_NEXT_C_film_motionstatus_579_560_shift   (0)
#define IM_DI_SI_FILM_MOTION_NEXT_C_film_motionstatus_579_560_mask    (0x000FFFFF)
#define IM_DI_SI_FILM_MOTION_NEXT_C_film_motionstatus_579_560(data)   (0x000FFFFF&(data))
#define IM_DI_SI_FILM_MOTION_NEXT_C_get_film_motionstatus_579_560(data)  (0x000FFFFF&(data))


#define IM_DI_SI_FILM_MOTION_PRE                                      0x18024108
#define IM_DI_SI_FILM_MOTION_PRE_reg_addr                             "0xb8024108"
#define IM_DI_SI_FILM_MOTION_PRE_reg                                  0xb8024108
#define IM_DI_SI_FILM_MOTION_PRE_inst_addr                            "0x0042"
#define IM_DI_SI_FILM_MOTION_PRE_inst                                 0x0042
#define IM_DI_SI_FILM_MOTION_PRE_film_motionstatus_559_540_shift      (0)
#define IM_DI_SI_FILM_MOTION_PRE_film_motionstatus_559_540_mask       (0x000FFFFF)
#define IM_DI_SI_FILM_MOTION_PRE_film_motionstatus_559_540(data)      (0x000FFFFF&(data))
#define IM_DI_SI_FILM_MOTION_PRE_get_film_motionstatus_559_540(data)  (0x000FFFFF&(data))


#define IM_DI_SI_FILM_MOTION_PRE_H_T                                  0x1802410c
#define IM_DI_SI_FILM_MOTION_PRE_H_T_reg_addr                         "0xb802410c"
#define IM_DI_SI_FILM_MOTION_PRE_H_T_reg                              0xb802410c
#define IM_DI_SI_FILM_MOTION_PRE_H_T_inst_addr                        "0x0043"
#define IM_DI_SI_FILM_MOTION_PRE_H_T_inst                             0x0043
#define IM_DI_SI_FILM_MOTION_PRE_H_T_film_motionstatus_539_520_shift  (0)
#define IM_DI_SI_FILM_MOTION_PRE_H_T_film_motionstatus_539_520_mask   (0x000FFFFF)
#define IM_DI_SI_FILM_MOTION_PRE_H_T_film_motionstatus_539_520(data)  (0x000FFFFF&(data))
#define IM_DI_SI_FILM_MOTION_PRE_H_T_get_film_motionstatus_539_520(data)  (0x000FFFFF&(data))


#define IM_DI_SI_FILM_MOTION_PRE_H_M                                  0x18024110
#define IM_DI_SI_FILM_MOTION_PRE_H_M_reg_addr                         "0xb8024110"
#define IM_DI_SI_FILM_MOTION_PRE_H_M_reg                              0xb8024110
#define IM_DI_SI_FILM_MOTION_PRE_H_M_inst_addr                        "0x0044"
#define IM_DI_SI_FILM_MOTION_PRE_H_M_inst                             0x0044
#define IM_DI_SI_FILM_MOTION_PRE_H_M_film_motionstatus_519_500_shift  (0)
#define IM_DI_SI_FILM_MOTION_PRE_H_M_film_motionstatus_519_500_mask   (0x000FFFFF)
#define IM_DI_SI_FILM_MOTION_PRE_H_M_film_motionstatus_519_500(data)  (0x000FFFFF&(data))
#define IM_DI_SI_FILM_MOTION_PRE_H_M_get_film_motionstatus_519_500(data)  (0x000FFFFF&(data))


#define IM_DI_SI_FILM_MOTION_PRE_H_B                                  0x18024114
#define IM_DI_SI_FILM_MOTION_PRE_H_B_reg_addr                         "0xb8024114"
#define IM_DI_SI_FILM_MOTION_PRE_H_B_reg                              0xb8024114
#define IM_DI_SI_FILM_MOTION_PRE_H_B_inst_addr                        "0x0045"
#define IM_DI_SI_FILM_MOTION_PRE_H_B_inst                             0x0045
#define IM_DI_SI_FILM_MOTION_PRE_H_B_film_motionstatus_499_480_shift  (0)
#define IM_DI_SI_FILM_MOTION_PRE_H_B_film_motionstatus_499_480_mask   (0x000FFFFF)
#define IM_DI_SI_FILM_MOTION_PRE_H_B_film_motionstatus_499_480(data)  (0x000FFFFF&(data))
#define IM_DI_SI_FILM_MOTION_PRE_H_B_get_film_motionstatus_499_480(data)  (0x000FFFFF&(data))


#define IM_DI_SI_FILM_MOTION_PRE_V_L                                  0x18024118
#define IM_DI_SI_FILM_MOTION_PRE_V_L_reg_addr                         "0xb8024118"
#define IM_DI_SI_FILM_MOTION_PRE_V_L_reg                              0xb8024118
#define IM_DI_SI_FILM_MOTION_PRE_V_L_inst_addr                        "0x0046"
#define IM_DI_SI_FILM_MOTION_PRE_V_L_inst                             0x0046
#define IM_DI_SI_FILM_MOTION_PRE_V_L_film_motionstatus_479_460_shift  (0)
#define IM_DI_SI_FILM_MOTION_PRE_V_L_film_motionstatus_479_460_mask   (0x000FFFFF)
#define IM_DI_SI_FILM_MOTION_PRE_V_L_film_motionstatus_479_460(data)  (0x000FFFFF&(data))
#define IM_DI_SI_FILM_MOTION_PRE_V_L_get_film_motionstatus_479_460(data)  (0x000FFFFF&(data))


#define IM_DI_SI_FILM_MOTION_PRE_V_M                                  0x1802411c
#define IM_DI_SI_FILM_MOTION_PRE_V_M_reg_addr                         "0xb802411c"
#define IM_DI_SI_FILM_MOTION_PRE_V_M_reg                              0xb802411c
#define IM_DI_SI_FILM_MOTION_PRE_V_M_inst_addr                        "0x0047"
#define IM_DI_SI_FILM_MOTION_PRE_V_M_inst                             0x0047
#define IM_DI_SI_FILM_MOTION_PRE_V_M_film_motionstatus_459_440_shift  (0)
#define IM_DI_SI_FILM_MOTION_PRE_V_M_film_motionstatus_459_440_mask   (0x000FFFFF)
#define IM_DI_SI_FILM_MOTION_PRE_V_M_film_motionstatus_459_440(data)  (0x000FFFFF&(data))
#define IM_DI_SI_FILM_MOTION_PRE_V_M_get_film_motionstatus_459_440(data)  (0x000FFFFF&(data))


#define IM_DI_SI_FILM_MOTION_PRE_V_R                                  0x18024120
#define IM_DI_SI_FILM_MOTION_PRE_V_R_reg_addr                         "0xb8024120"
#define IM_DI_SI_FILM_MOTION_PRE_V_R_reg                              0xb8024120
#define IM_DI_SI_FILM_MOTION_PRE_V_R_inst_addr                        "0x0048"
#define IM_DI_SI_FILM_MOTION_PRE_V_R_inst                             0x0048
#define IM_DI_SI_FILM_MOTION_PRE_V_R_film_motionstatus_439_420_shift  (0)
#define IM_DI_SI_FILM_MOTION_PRE_V_R_film_motionstatus_439_420_mask   (0x000FFFFF)
#define IM_DI_SI_FILM_MOTION_PRE_V_R_film_motionstatus_439_420(data)  (0x000FFFFF&(data))
#define IM_DI_SI_FILM_MOTION_PRE_V_R_get_film_motionstatus_439_420(data)  (0x000FFFFF&(data))


#define IM_DI_SI_FILM_MOTION_PRE_C                                    0x18024124
#define IM_DI_SI_FILM_MOTION_PRE_C_reg_addr                           "0xb8024124"
#define IM_DI_SI_FILM_MOTION_PRE_C_reg                                0xb8024124
#define IM_DI_SI_FILM_MOTION_PRE_C_inst_addr                          "0x0049"
#define IM_DI_SI_FILM_MOTION_PRE_C_inst                               0x0049
#define IM_DI_SI_FILM_MOTION_PRE_C_film_motionstatus_419_400_shift    (0)
#define IM_DI_SI_FILM_MOTION_PRE_C_film_motionstatus_419_400_mask     (0x000FFFFF)
#define IM_DI_SI_FILM_MOTION_PRE_C_film_motionstatus_419_400(data)    (0x000FFFFF&(data))
#define IM_DI_SI_FILM_MOTION_PRE_C_get_film_motionstatus_419_400(data)  (0x000FFFFF&(data))


#define IM_DI_SI_FILM_MOTION                                          0x18024128
#define IM_DI_SI_FILM_MOTION_reg_addr                                 "0xb8024128"
#define IM_DI_SI_FILM_MOTION_reg                                      0xb8024128
#define IM_DI_SI_FILM_MOTION_inst_addr                                "0x004A"
#define IM_DI_SI_FILM_MOTION_inst                                     0x004A
#define IM_DI_SI_FILM_MOTION_film_motionstatus_399_380_shift          (0)
#define IM_DI_SI_FILM_MOTION_film_motionstatus_399_380_mask           (0x000FFFFF)
#define IM_DI_SI_FILM_MOTION_film_motionstatus_399_380(data)          (0x000FFFFF&(data))
#define IM_DI_SI_FILM_MOTION_get_film_motionstatus_399_380(data)      (0x000FFFFF&(data))


#define IM_DI_SI_FILM_MOTION_H_T                                      0x1802412c
#define IM_DI_SI_FILM_MOTION_H_T_reg_addr                             "0xb802412c"
#define IM_DI_SI_FILM_MOTION_H_T_reg                                  0xb802412c
#define IM_DI_SI_FILM_MOTION_H_T_inst_addr                            "0x004B"
#define IM_DI_SI_FILM_MOTION_H_T_inst                                 0x004B
#define IM_DI_SI_FILM_MOTION_H_T_film_motionstatus_379_360_shift      (0)
#define IM_DI_SI_FILM_MOTION_H_T_film_motionstatus_379_360_mask       (0x000FFFFF)
#define IM_DI_SI_FILM_MOTION_H_T_film_motionstatus_379_360(data)      (0x000FFFFF&(data))
#define IM_DI_SI_FILM_MOTION_H_T_get_film_motionstatus_379_360(data)  (0x000FFFFF&(data))


#define IM_DI_SI_FILM_MOTION_H_M                                      0x18024130
#define IM_DI_SI_FILM_MOTION_H_M_reg_addr                             "0xb8024130"
#define IM_DI_SI_FILM_MOTION_H_M_reg                                  0xb8024130
#define IM_DI_SI_FILM_MOTION_H_M_inst_addr                            "0x004C"
#define IM_DI_SI_FILM_MOTION_H_M_inst                                 0x004C
#define IM_DI_SI_FILM_MOTION_H_M_film_motionstatus_359_340_shift      (0)
#define IM_DI_SI_FILM_MOTION_H_M_film_motionstatus_359_340_mask       (0x000FFFFF)
#define IM_DI_SI_FILM_MOTION_H_M_film_motionstatus_359_340(data)      (0x000FFFFF&(data))
#define IM_DI_SI_FILM_MOTION_H_M_get_film_motionstatus_359_340(data)  (0x000FFFFF&(data))


#define IM_DI_SI_FILM_MOTION_H_B                                      0x18024134
#define IM_DI_SI_FILM_MOTION_H_B_reg_addr                             "0xb8024134"
#define IM_DI_SI_FILM_MOTION_H_B_reg                                  0xb8024134
#define IM_DI_SI_FILM_MOTION_H_B_inst_addr                            "0x004D"
#define IM_DI_SI_FILM_MOTION_H_B_inst                                 0x004D
#define IM_DI_SI_FILM_MOTION_H_B_film_motionstatus_339_320_shift      (0)
#define IM_DI_SI_FILM_MOTION_H_B_film_motionstatus_339_320_mask       (0x000FFFFF)
#define IM_DI_SI_FILM_MOTION_H_B_film_motionstatus_339_320(data)      (0x000FFFFF&(data))
#define IM_DI_SI_FILM_MOTION_H_B_get_film_motionstatus_339_320(data)  (0x000FFFFF&(data))


#define IM_DI_SI_FILM_MOTION_V_L                                      0x18024138
#define IM_DI_SI_FILM_MOTION_V_L_reg_addr                             "0xb8024138"
#define IM_DI_SI_FILM_MOTION_V_L_reg                                  0xb8024138
#define IM_DI_SI_FILM_MOTION_V_L_inst_addr                            "0x004E"
#define IM_DI_SI_FILM_MOTION_V_L_inst                                 0x004E
#define IM_DI_SI_FILM_MOTION_V_L_film_motionstatus_319_300_shift      (0)
#define IM_DI_SI_FILM_MOTION_V_L_film_motionstatus_319_300_mask       (0x000FFFFF)
#define IM_DI_SI_FILM_MOTION_V_L_film_motionstatus_319_300(data)      (0x000FFFFF&(data))
#define IM_DI_SI_FILM_MOTION_V_L_get_film_motionstatus_319_300(data)  (0x000FFFFF&(data))


#define IM_DI_SI_FILM_MOTION_V_M                                      0x1802413c
#define IM_DI_SI_FILM_MOTION_V_M_reg_addr                             "0xb802413c"
#define IM_DI_SI_FILM_MOTION_V_M_reg                                  0xb802413c
#define IM_DI_SI_FILM_MOTION_V_M_inst_addr                            "0x004F"
#define IM_DI_SI_FILM_MOTION_V_M_inst                                 0x004F
#define IM_DI_SI_FILM_MOTION_V_M_film_motionstatus_299_280_shift      (0)
#define IM_DI_SI_FILM_MOTION_V_M_film_motionstatus_299_280_mask       (0x000FFFFF)
#define IM_DI_SI_FILM_MOTION_V_M_film_motionstatus_299_280(data)      (0x000FFFFF&(data))
#define IM_DI_SI_FILM_MOTION_V_M_get_film_motionstatus_299_280(data)  (0x000FFFFF&(data))


#define IM_DI_SI_FILM_MOTION_V_R                                      0x18024140
#define IM_DI_SI_FILM_MOTION_V_R_reg_addr                             "0xb8024140"
#define IM_DI_SI_FILM_MOTION_V_R_reg                                  0xb8024140
#define IM_DI_SI_FILM_MOTION_V_R_inst_addr                            "0x0050"
#define IM_DI_SI_FILM_MOTION_V_R_inst                                 0x0050
#define IM_DI_SI_FILM_MOTION_V_R_film_motionstatus_279_260_shift      (0)
#define IM_DI_SI_FILM_MOTION_V_R_film_motionstatus_279_260_mask       (0x000FFFFF)
#define IM_DI_SI_FILM_MOTION_V_R_film_motionstatus_279_260(data)      (0x000FFFFF&(data))
#define IM_DI_SI_FILM_MOTION_V_R_get_film_motionstatus_279_260(data)  (0x000FFFFF&(data))


#define IM_DI_SI_FILM_MOTION_C                                        0x18024144
#define IM_DI_SI_FILM_MOTION_C_reg_addr                               "0xb8024144"
#define IM_DI_SI_FILM_MOTION_C_reg                                    0xb8024144
#define IM_DI_SI_FILM_MOTION_C_inst_addr                              "0x0051"
#define IM_DI_SI_FILM_MOTION_C_inst                                   0x0051
#define IM_DI_SI_FILM_MOTION_C_film_motionstatus_259_240_shift        (0)
#define IM_DI_SI_FILM_MOTION_C_film_motionstatus_259_240_mask         (0x000FFFFF)
#define IM_DI_SI_FILM_MOTION_C_film_motionstatus_259_240(data)        (0x000FFFFF&(data))
#define IM_DI_SI_FILM_MOTION_C_get_film_motionstatus_259_240(data)    (0x000FFFFF&(data))


#define IM_DI_SI_FILM_MOTION_H_11                                     0x18024148
#define IM_DI_SI_FILM_MOTION_H_11_reg_addr                            "0xb8024148"
#define IM_DI_SI_FILM_MOTION_H_11_reg                                 0xb8024148
#define IM_DI_SI_FILM_MOTION_H_11_inst_addr                           "0x0052"
#define IM_DI_SI_FILM_MOTION_H_11_inst                                0x0052
#define IM_DI_SI_FILM_MOTION_H_11_film_motionstatus_239_220_shift     (0)
#define IM_DI_SI_FILM_MOTION_H_11_film_motionstatus_239_220_mask      (0x000FFFFF)
#define IM_DI_SI_FILM_MOTION_H_11_film_motionstatus_239_220(data)     (0x000FFFFF&(data))
#define IM_DI_SI_FILM_MOTION_H_11_get_film_motionstatus_239_220(data) (0x000FFFFF&(data))


#define IM_DI_SI_FILM_MOTION_H_10                                     0x1802414c
#define IM_DI_SI_FILM_MOTION_H_10_reg_addr                            "0xb802414c"
#define IM_DI_SI_FILM_MOTION_H_10_reg                                 0xb802414c
#define IM_DI_SI_FILM_MOTION_H_10_inst_addr                           "0x0053"
#define IM_DI_SI_FILM_MOTION_H_10_inst                                0x0053
#define IM_DI_SI_FILM_MOTION_H_10_film_motionstatus_219_200_shift     (0)
#define IM_DI_SI_FILM_MOTION_H_10_film_motionstatus_219_200_mask      (0x000FFFFF)
#define IM_DI_SI_FILM_MOTION_H_10_film_motionstatus_219_200(data)     (0x000FFFFF&(data))
#define IM_DI_SI_FILM_MOTION_H_10_get_film_motionstatus_219_200(data) (0x000FFFFF&(data))


#define IM_DI_SI_FILM_MOTION_H_09                                     0x18024150
#define IM_DI_SI_FILM_MOTION_H_09_reg_addr                            "0xb8024150"
#define IM_DI_SI_FILM_MOTION_H_09_reg                                 0xb8024150
#define IM_DI_SI_FILM_MOTION_H_09_inst_addr                           "0x0054"
#define IM_DI_SI_FILM_MOTION_H_09_inst                                0x0054
#define IM_DI_SI_FILM_MOTION_H_09_film_motionstatus_199_180_shift     (0)
#define IM_DI_SI_FILM_MOTION_H_09_film_motionstatus_199_180_mask      (0x000FFFFF)
#define IM_DI_SI_FILM_MOTION_H_09_film_motionstatus_199_180(data)     (0x000FFFFF&(data))
#define IM_DI_SI_FILM_MOTION_H_09_get_film_motionstatus_199_180(data) (0x000FFFFF&(data))


#define IM_DI_SI_FILM_MOTION_H_08                                     0x18024154
#define IM_DI_SI_FILM_MOTION_H_08_reg_addr                            "0xb8024154"
#define IM_DI_SI_FILM_MOTION_H_08_reg                                 0xb8024154
#define IM_DI_SI_FILM_MOTION_H_08_inst_addr                           "0x0055"
#define IM_DI_SI_FILM_MOTION_H_08_inst                                0x0055
#define IM_DI_SI_FILM_MOTION_H_08_film_motionstatus_179_160_shift     (0)
#define IM_DI_SI_FILM_MOTION_H_08_film_motionstatus_179_160_mask      (0x000FFFFF)
#define IM_DI_SI_FILM_MOTION_H_08_film_motionstatus_179_160(data)     (0x000FFFFF&(data))
#define IM_DI_SI_FILM_MOTION_H_08_get_film_motionstatus_179_160(data) (0x000FFFFF&(data))


#define IM_DI_SI_FILM_MOTION_H_07                                     0x18024158
#define IM_DI_SI_FILM_MOTION_H_07_reg_addr                            "0xb8024158"
#define IM_DI_SI_FILM_MOTION_H_07_reg                                 0xb8024158
#define IM_DI_SI_FILM_MOTION_H_07_inst_addr                           "0x0056"
#define IM_DI_SI_FILM_MOTION_H_07_inst                                0x0056
#define IM_DI_SI_FILM_MOTION_H_07_film_motionstatus_159_140_shift     (0)
#define IM_DI_SI_FILM_MOTION_H_07_film_motionstatus_159_140_mask      (0x000FFFFF)
#define IM_DI_SI_FILM_MOTION_H_07_film_motionstatus_159_140(data)     (0x000FFFFF&(data))
#define IM_DI_SI_FILM_MOTION_H_07_get_film_motionstatus_159_140(data) (0x000FFFFF&(data))


#define IM_DI_SI_FILM_MOTION_H_06                                     0x1802415c
#define IM_DI_SI_FILM_MOTION_H_06_reg_addr                            "0xb802415c"
#define IM_DI_SI_FILM_MOTION_H_06_reg                                 0xb802415c
#define IM_DI_SI_FILM_MOTION_H_06_inst_addr                           "0x0057"
#define IM_DI_SI_FILM_MOTION_H_06_inst                                0x0057
#define IM_DI_SI_FILM_MOTION_H_06_film_motionstatus_139_120_shift     (0)
#define IM_DI_SI_FILM_MOTION_H_06_film_motionstatus_139_120_mask      (0x000FFFFF)
#define IM_DI_SI_FILM_MOTION_H_06_film_motionstatus_139_120(data)     (0x000FFFFF&(data))
#define IM_DI_SI_FILM_MOTION_H_06_get_film_motionstatus_139_120(data) (0x000FFFFF&(data))


#define IM_DI_SI_FILM_MOTION_H_05                                     0x18024160
#define IM_DI_SI_FILM_MOTION_H_05_reg_addr                            "0xb8024160"
#define IM_DI_SI_FILM_MOTION_H_05_reg                                 0xb8024160
#define IM_DI_SI_FILM_MOTION_H_05_inst_addr                           "0x0058"
#define IM_DI_SI_FILM_MOTION_H_05_inst                                0x0058
#define IM_DI_SI_FILM_MOTION_H_05_film_motionstatus_119_100_shift     (0)
#define IM_DI_SI_FILM_MOTION_H_05_film_motionstatus_119_100_mask      (0x000FFFFF)
#define IM_DI_SI_FILM_MOTION_H_05_film_motionstatus_119_100(data)     (0x000FFFFF&(data))
#define IM_DI_SI_FILM_MOTION_H_05_get_film_motionstatus_119_100(data) (0x000FFFFF&(data))


#define IM_DI_SI_FILM_MOTION_H_04                                     0x18024164
#define IM_DI_SI_FILM_MOTION_H_04_reg_addr                            "0xb8024164"
#define IM_DI_SI_FILM_MOTION_H_04_reg                                 0xb8024164
#define IM_DI_SI_FILM_MOTION_H_04_inst_addr                           "0x0059"
#define IM_DI_SI_FILM_MOTION_H_04_inst                                0x0059
#define IM_DI_SI_FILM_MOTION_H_04_film_motionstatus_99_80_shift       (0)
#define IM_DI_SI_FILM_MOTION_H_04_film_motionstatus_99_80_mask        (0x000FFFFF)
#define IM_DI_SI_FILM_MOTION_H_04_film_motionstatus_99_80(data)       (0x000FFFFF&(data))
#define IM_DI_SI_FILM_MOTION_H_04_get_film_motionstatus_99_80(data)   (0x000FFFFF&(data))


#define IM_DI_SI_FILM_MOTION_H_03                                     0x18024168
#define IM_DI_SI_FILM_MOTION_H_03_reg_addr                            "0xb8024168"
#define IM_DI_SI_FILM_MOTION_H_03_reg                                 0xb8024168
#define IM_DI_SI_FILM_MOTION_H_03_inst_addr                           "0x005A"
#define IM_DI_SI_FILM_MOTION_H_03_inst                                0x005A
#define IM_DI_SI_FILM_MOTION_H_03_film_motionstatus_79_60_shift       (0)
#define IM_DI_SI_FILM_MOTION_H_03_film_motionstatus_79_60_mask        (0x000FFFFF)
#define IM_DI_SI_FILM_MOTION_H_03_film_motionstatus_79_60(data)       (0x000FFFFF&(data))
#define IM_DI_SI_FILM_MOTION_H_03_get_film_motionstatus_79_60(data)   (0x000FFFFF&(data))


#define IM_DI_SI_FILM_MOTION_H_02                                     0x1802416c
#define IM_DI_SI_FILM_MOTION_H_02_reg_addr                            "0xb802416c"
#define IM_DI_SI_FILM_MOTION_H_02_reg                                 0xb802416c
#define IM_DI_SI_FILM_MOTION_H_02_inst_addr                           "0x005B"
#define IM_DI_SI_FILM_MOTION_H_02_inst                                0x005B
#define IM_DI_SI_FILM_MOTION_H_02_film_motionstatus_59_40_shift       (0)
#define IM_DI_SI_FILM_MOTION_H_02_film_motionstatus_59_40_mask        (0x000FFFFF)
#define IM_DI_SI_FILM_MOTION_H_02_film_motionstatus_59_40(data)       (0x000FFFFF&(data))
#define IM_DI_SI_FILM_MOTION_H_02_get_film_motionstatus_59_40(data)   (0x000FFFFF&(data))


#define IM_DI_SI_FILM_MOTION_H_01                                     0x18024170
#define IM_DI_SI_FILM_MOTION_H_01_reg_addr                            "0xb8024170"
#define IM_DI_SI_FILM_MOTION_H_01_reg                                 0xb8024170
#define IM_DI_SI_FILM_MOTION_H_01_inst_addr                           "0x005C"
#define IM_DI_SI_FILM_MOTION_H_01_inst                                0x005C
#define IM_DI_SI_FILM_MOTION_H_01_film_motionstatus_39_20_shift       (0)
#define IM_DI_SI_FILM_MOTION_H_01_film_motionstatus_39_20_mask        (0x000FFFFF)
#define IM_DI_SI_FILM_MOTION_H_01_film_motionstatus_39_20(data)       (0x000FFFFF&(data))
#define IM_DI_SI_FILM_MOTION_H_01_get_film_motionstatus_39_20(data)   (0x000FFFFF&(data))


#define IM_DI_SI_FILM_MOTION_H_00                                     0x18024174
#define IM_DI_SI_FILM_MOTION_H_00_reg_addr                            "0xb8024174"
#define IM_DI_SI_FILM_MOTION_H_00_reg                                 0xb8024174
#define IM_DI_SI_FILM_MOTION_H_00_inst_addr                           "0x005D"
#define IM_DI_SI_FILM_MOTION_H_00_inst                                0x005D
#define IM_DI_SI_FILM_MOTION_H_00_film_motionstatus_19_0_shift        (0)
#define IM_DI_SI_FILM_MOTION_H_00_film_motionstatus_19_0_mask         (0x000FFFFF)
#define IM_DI_SI_FILM_MOTION_H_00_film_motionstatus_19_0(data)        (0x000FFFFF&(data))
#define IM_DI_SI_FILM_MOTION_H_00_get_film_motionstatus_19_0(data)    (0x000FFFFF&(data))


#define IM_DI_SI_MA_TOTAL_FM_SUM                                      0x18024178
#define IM_DI_SI_MA_TOTAL_FM_SUM_reg_addr                             "0xb8024178"
#define IM_DI_SI_MA_TOTAL_FM_SUM_reg                                  0xb8024178
#define IM_DI_SI_MA_TOTAL_FM_SUM_inst_addr                            "0x005E"
#define IM_DI_SI_MA_TOTAL_FM_SUM_inst                                 0x005E
#define IM_DI_SI_MA_TOTAL_FM_SUM_total_frame_motion_sum_shift         (0)
#define IM_DI_SI_MA_TOTAL_FM_SUM_total_frame_motion_sum_mask          (0x00FFFFFF)
#define IM_DI_SI_MA_TOTAL_FM_SUM_total_frame_motion_sum(data)         (0x00FFFFFF&(data))
#define IM_DI_SI_MA_TOTAL_FM_SUM_get_total_frame_motion_sum(data)     (0x00FFFFFF&(data))


#define IM_DI_SI_MA_LARGE_FM_PIXEL                                    0x1802417c
#define IM_DI_SI_MA_LARGE_FM_PIXEL_reg_addr                           "0xb802417c"
#define IM_DI_SI_MA_LARGE_FM_PIXEL_reg                                0xb802417c
#define IM_DI_SI_MA_LARGE_FM_PIXEL_inst_addr                          "0x005F"
#define IM_DI_SI_MA_LARGE_FM_PIXEL_inst                               0x005F
#define IM_DI_SI_MA_LARGE_FM_PIXEL_large_frame_motion_pixel_shift     (0)
#define IM_DI_SI_MA_LARGE_FM_PIXEL_large_frame_motion_pixel_mask      (0x00FFFFFF)
#define IM_DI_SI_MA_LARGE_FM_PIXEL_large_frame_motion_pixel(data)     (0x00FFFFFF&(data))
#define IM_DI_SI_MA_LARGE_FM_PIXEL_get_large_frame_motion_pixel(data) (0x00FFFFFF&(data))


#define IM_DI_SI_MA_LARGE_FM_SUM                                      0x18024180
#define IM_DI_SI_MA_LARGE_FM_SUM_reg_addr                             "0xb8024180"
#define IM_DI_SI_MA_LARGE_FM_SUM_reg                                  0xb8024180
#define IM_DI_SI_MA_LARGE_FM_SUM_inst_addr                            "0x0060"
#define IM_DI_SI_MA_LARGE_FM_SUM_inst                                 0x0060
#define IM_DI_SI_MA_LARGE_FM_SUM_large_frame_motion_sum_shift         (0)
#define IM_DI_SI_MA_LARGE_FM_SUM_large_frame_motion_sum_mask          (0x00FFFFFF)
#define IM_DI_SI_MA_LARGE_FM_SUM_large_frame_motion_sum(data)         (0x00FFFFFF&(data))
#define IM_DI_SI_MA_LARGE_FM_SUM_get_large_frame_motion_sum(data)     (0x00FFFFFF&(data))


#define IM_DI_SI_MA_MESS_H_PIXEL                                      0x18024184
#define IM_DI_SI_MA_MESS_H_PIXEL_reg_addr                             "0xb8024184"
#define IM_DI_SI_MA_MESS_H_PIXEL_reg                                  0xb8024184
#define IM_DI_SI_MA_MESS_H_PIXEL_inst_addr                            "0x0061"
#define IM_DI_SI_MA_MESS_H_PIXEL_inst                                 0x0061
#define IM_DI_SI_MA_MESS_H_PIXEL_mess_horizontal_pixel_shift          (0)
#define IM_DI_SI_MA_MESS_H_PIXEL_mess_horizontal_pixel_mask           (0x00FFFFFF)
#define IM_DI_SI_MA_MESS_H_PIXEL_mess_horizontal_pixel(data)          (0x00FFFFFF&(data))
#define IM_DI_SI_MA_MESS_H_PIXEL_get_mess_horizontal_pixel(data)      (0x00FFFFFF&(data))


#define IM_DI_SI_IMAGE_BALANCE                                        0x18024188
#define IM_DI_SI_IMAGE_BALANCE_reg_addr                               "0xb8024188"
#define IM_DI_SI_IMAGE_BALANCE_reg                                    0xb8024188
#define IM_DI_SI_IMAGE_BALANCE_inst_addr                              "0x0062"
#define IM_DI_SI_IMAGE_BALANCE_inst                                   0x0062
#define IM_DI_SI_IMAGE_BALANCE_cr_subbal_status_shift                 (25)
#define IM_DI_SI_IMAGE_BALANCE_cr_enable_mainbalance_shift            (24)
#define IM_DI_SI_IMAGE_BALANCE_cr_mean3_status_shift                  (16)
#define IM_DI_SI_IMAGE_BALANCE_cr_mean2_status_shift                  (8)
#define IM_DI_SI_IMAGE_BALANCE_cr_mean1_status_shift                  (0)
#define IM_DI_SI_IMAGE_BALANCE_cr_subbal_status_mask                  (0x0E000000)
#define IM_DI_SI_IMAGE_BALANCE_cr_enable_mainbalance_mask             (0x01000000)
#define IM_DI_SI_IMAGE_BALANCE_cr_mean3_status_mask                   (0x00FF0000)
#define IM_DI_SI_IMAGE_BALANCE_cr_mean2_status_mask                   (0x0000FF00)
#define IM_DI_SI_IMAGE_BALANCE_cr_mean1_status_mask                   (0x000000FF)
#define IM_DI_SI_IMAGE_BALANCE_cr_subbal_status(data)                 (0x0E000000&((data)<<25))
#define IM_DI_SI_IMAGE_BALANCE_cr_enable_mainbalance(data)            (0x01000000&((data)<<24))
#define IM_DI_SI_IMAGE_BALANCE_cr_mean3_status(data)                  (0x00FF0000&((data)<<16))
#define IM_DI_SI_IMAGE_BALANCE_cr_mean2_status(data)                  (0x0000FF00&((data)<<8))
#define IM_DI_SI_IMAGE_BALANCE_cr_mean1_status(data)                  (0x000000FF&(data))
#define IM_DI_SI_IMAGE_BALANCE_get_cr_subbal_status(data)             ((0x0E000000&(data))>>25)
#define IM_DI_SI_IMAGE_BALANCE_get_cr_enable_mainbalance(data)        ((0x01000000&(data))>>24)
#define IM_DI_SI_IMAGE_BALANCE_get_cr_mean3_status(data)              ((0x00FF0000&(data))>>16)
#define IM_DI_SI_IMAGE_BALANCE_get_cr_mean2_status(data)              ((0x0000FF00&(data))>>8)
#define IM_DI_SI_IMAGE_BALANCE_get_cr_mean1_status(data)              (0x000000FF&(data))


#define IM_DI_SI_SUB_IN_AUTO_BALANCE                                  0x1802418c
#define IM_DI_SI_SUB_IN_AUTO_BALANCE_reg_addr                         "0xb802418c"
#define IM_DI_SI_SUB_IN_AUTO_BALANCE_reg                              0xb802418c
#define IM_DI_SI_SUB_IN_AUTO_BALANCE_inst_addr                        "0x0063"
#define IM_DI_SI_SUB_IN_AUTO_BALANCE_inst                             0x0063
#define IM_DI_SI_SUB_IN_AUTO_BALANCE_di_crc_ctrl_conti_shift          (17)
#define IM_DI_SI_SUB_IN_AUTO_BALANCE_di_crc_ctrl_start_shift          (16)
#define IM_DI_SI_SUB_IN_AUTO_BALANCE_cr_amount_subbalance_shift       (0)
#define IM_DI_SI_SUB_IN_AUTO_BALANCE_di_crc_ctrl_conti_mask           (0x00020000)
#define IM_DI_SI_SUB_IN_AUTO_BALANCE_di_crc_ctrl_start_mask           (0x00010000)
#define IM_DI_SI_SUB_IN_AUTO_BALANCE_cr_amount_subbalance_mask        (0x0000FFFF)
#define IM_DI_SI_SUB_IN_AUTO_BALANCE_di_crc_ctrl_conti(data)          (0x00020000&((data)<<17))
#define IM_DI_SI_SUB_IN_AUTO_BALANCE_di_crc_ctrl_start(data)          (0x00010000&((data)<<16))
#define IM_DI_SI_SUB_IN_AUTO_BALANCE_cr_amount_subbalance(data)       (0x0000FFFF&(data))
#define IM_DI_SI_SUB_IN_AUTO_BALANCE_get_di_crc_ctrl_conti(data)      ((0x00020000&(data))>>17)
#define IM_DI_SI_SUB_IN_AUTO_BALANCE_get_di_crc_ctrl_start(data)      ((0x00010000&(data))>>16)
#define IM_DI_SI_SUB_IN_AUTO_BALANCE_get_cr_amount_subbalance(data)   (0x0000FFFF&(data))


#define IM_DI_CRC_RESULT                                              0x18024190
#define IM_DI_CRC_RESULT_reg_addr                                     "0xb8024190"
#define IM_DI_CRC_RESULT_reg                                          0xb8024190
#define IM_DI_CRC_RESULT_inst_addr                                    "0x0064"
#define IM_DI_CRC_RESULT_inst                                         0x0064
#define IM_DI_CRC_RESULT_di_crc_result_shift                          (0)
#define IM_DI_CRC_RESULT_di_crc_result_mask                           (0xFFFFFFFF)
#define IM_DI_CRC_RESULT_di_crc_result(data)                          (0xFFFFFFFF&(data))
#define IM_DI_CRC_RESULT_get_di_crc_result(data)                      (0xFFFFFFFF&(data))


#define IM_DI_SI_STILL_INFO_FOR_NE                                    0x18024194
#define IM_DI_SI_STILL_INFO_FOR_NE_reg_addr                           "0xb8024194"
#define IM_DI_SI_STILL_INFO_FOR_NE_reg                                0xb8024194
#define IM_DI_SI_STILL_INFO_FOR_NE_inst_addr                          "0x0065"
#define IM_DI_SI_STILL_INFO_FOR_NE_inst                               0x0065
#define IM_DI_SI_STILL_INFO_FOR_NE_newintrainterpolate_vertical_thd_shift  (22)
#define IM_DI_SI_STILL_INFO_FOR_NE_newintrainterpolate_sumdiff_thd_shift  (12)
#define IM_DI_SI_STILL_INFO_FOR_NE_newintrainterpolate_pixdiff_thd_shift  (4)
#define IM_DI_SI_STILL_INFO_FOR_NE_newintrainterpolate_enable_shift   (3)
#define IM_DI_SI_STILL_INFO_FOR_NE_cp_partialstill_shift              (1)
#define IM_DI_SI_STILL_INFO_FOR_NE_cp_partialstillnew_shift           (0)
#define IM_DI_SI_STILL_INFO_FOR_NE_newintrainterpolate_vertical_thd_mask  (0xFFC00000)
#define IM_DI_SI_STILL_INFO_FOR_NE_newintrainterpolate_sumdiff_thd_mask  (0x003FF000)
#define IM_DI_SI_STILL_INFO_FOR_NE_newintrainterpolate_pixdiff_thd_mask  (0x00000FF0)
#define IM_DI_SI_STILL_INFO_FOR_NE_newintrainterpolate_enable_mask    (0x00000008)
#define IM_DI_SI_STILL_INFO_FOR_NE_cp_partialstill_mask               (0x00000002)
#define IM_DI_SI_STILL_INFO_FOR_NE_cp_partialstillnew_mask            (0x00000001)
#define IM_DI_SI_STILL_INFO_FOR_NE_newintrainterpolate_vertical_thd(data)  (0xFFC00000&((data)<<22))
#define IM_DI_SI_STILL_INFO_FOR_NE_newintrainterpolate_sumdiff_thd(data)  (0x003FF000&((data)<<12))
#define IM_DI_SI_STILL_INFO_FOR_NE_newintrainterpolate_pixdiff_thd(data)  (0x00000FF0&((data)<<4))
#define IM_DI_SI_STILL_INFO_FOR_NE_newintrainterpolate_enable(data)   (0x00000008&((data)<<3))
#define IM_DI_SI_STILL_INFO_FOR_NE_cp_partialstill(data)              (0x00000002&((data)<<1))
#define IM_DI_SI_STILL_INFO_FOR_NE_cp_partialstillnew(data)           (0x00000001&(data))
#define IM_DI_SI_STILL_INFO_FOR_NE_get_newintrainterpolate_vertical_thd(data)  ((0xFFC00000&(data))>>22)
#define IM_DI_SI_STILL_INFO_FOR_NE_get_newintrainterpolate_sumdiff_thd(data)  ((0x003FF000&(data))>>12)
#define IM_DI_SI_STILL_INFO_FOR_NE_get_newintrainterpolate_pixdiff_thd(data)  ((0x00000FF0&(data))>>4)
#define IM_DI_SI_STILL_INFO_FOR_NE_get_newintrainterpolate_enable(data)  ((0x00000008&(data))>>3)
#define IM_DI_SI_STILL_INFO_FOR_NE_get_cp_partialstill(data)          ((0x00000002&(data))>>1)
#define IM_DI_SI_STILL_INFO_FOR_NE_get_cp_partialstillnew(data)       (0x00000001&(data))


#define IM_DI_SI_FILM22_DETECTOR_PATTERN                              0x18024198
#define IM_DI_SI_FILM22_DETECTOR_PATTERN_reg_addr                     "0xb8024198"
#define IM_DI_SI_FILM22_DETECTOR_PATTERN_reg                          0xb8024198
#define IM_DI_SI_FILM22_DETECTOR_PATTERN_inst_addr                    "0x0066"
#define IM_DI_SI_FILM22_DETECTOR_PATTERN_inst                         0x0066
#define IM_DI_SI_FILM22_DETECTOR_PATTERN_film22_nxtfistatic1_shift    (8)
#define IM_DI_SI_FILM22_DETECTOR_PATTERN_film22_nxtfimotion_shift     (0)
#define IM_DI_SI_FILM22_DETECTOR_PATTERN_film22_nxtfistatic1_mask     (0x0000FF00)
#define IM_DI_SI_FILM22_DETECTOR_PATTERN_film22_nxtfimotion_mask      (0x000000FF)
#define IM_DI_SI_FILM22_DETECTOR_PATTERN_film22_nxtfistatic1(data)    (0x0000FF00&((data)<<8))
#define IM_DI_SI_FILM22_DETECTOR_PATTERN_film22_nxtfimotion(data)     (0x000000FF&(data))
#define IM_DI_SI_FILM22_DETECTOR_PATTERN_get_film22_nxtfistatic1(data)  ((0x0000FF00&(data))>>8)
#define IM_DI_SI_FILM22_DETECTOR_PATTERN_get_film22_nxtfimotion(data) (0x000000FF&(data))


#define IM_DI_TNR_TH                                                  0x1802419c
#define IM_DI_TNR_TH_reg_addr                                         "0xb802419c"
#define IM_DI_TNR_TH_reg                                              0xb802419c
#define IM_DI_TNR_TH_inst_addr                                        "0x0067"
#define IM_DI_TNR_TH_inst                                             0x0067
#define IM_DI_TNR_TH_cp_temporalthly_shift                            (8)
#define IM_DI_TNR_TH_cp_temporalthlc_shift                            (0)
#define IM_DI_TNR_TH_cp_temporalthly_mask                             (0x0000FF00)
#define IM_DI_TNR_TH_cp_temporalthlc_mask                             (0x000000FF)
#define IM_DI_TNR_TH_cp_temporalthly(data)                            (0x0000FF00&((data)<<8))
#define IM_DI_TNR_TH_cp_temporalthlc(data)                            (0x000000FF&(data))
#define IM_DI_TNR_TH_get_cp_temporalthly(data)                        ((0x0000FF00&(data))>>8)
#define IM_DI_TNR_TH_get_cp_temporalthlc(data)                        (0x000000FF&(data))


#define IM_DI_RTNR_CONTROL                                            0x180241a0
#define IM_DI_RTNR_CONTROL_reg_addr                                   "0xb80241a0"
#define IM_DI_RTNR_CONTROL_reg                                        0xb80241a0
#define IM_DI_RTNR_CONTROL_inst_addr                                  "0x0068"
#define IM_DI_RTNR_CONTROL_inst                                       0x0068
#define IM_DI_RTNR_CONTROL_cp_rtnr_interlace_force2d_en_shift         (31)
#define IM_DI_RTNR_CONTROL_cp_rtnr_rgb444_enable_shift                (30)
#define IM_DI_RTNR_CONTROL_cp_rtnr_rounding_correction2_errorthd_c_shift  (20)
#define IM_DI_RTNR_CONTROL_cp_rtnr_rounding_correction2_errorthd_y_shift  (12)
#define IM_DI_RTNR_CONTROL_cp_rtnr_rounding_correction2_mode_shift    (9)
#define IM_DI_RTNR_CONTROL_cp_rtnr_rounding_correction2_en_shift      (8)
#define IM_DI_RTNR_CONTROL_cp_rtnr_updatelockflg_shift                (7)
#define IM_DI_RTNR_CONTROL_cp_rtnr_updatelocken_shift                 (6)
#define IM_DI_RTNR_CONTROL_cp_rtnr_mad_window_shift                   (4)
#define IM_DI_RTNR_CONTROL_cp_rtnr_rounding_correction_shift          (3)
#define IM_DI_RTNR_CONTROL_cp_rtnr_progressive_shift                  (2)
#define IM_DI_RTNR_CONTROL_cp_rtnr_c_enable_shift                     (1)
#define IM_DI_RTNR_CONTROL_cp_rtnr_y_enable_shift                     (0)
#define IM_DI_RTNR_CONTROL_cp_rtnr_interlace_force2d_en_mask          (0x80000000)
#define IM_DI_RTNR_CONTROL_cp_rtnr_rgb444_enable_mask                 (0x40000000)
#define IM_DI_RTNR_CONTROL_cp_rtnr_rounding_correction2_errorthd_c_mask  (0x03F00000)
#define IM_DI_RTNR_CONTROL_cp_rtnr_rounding_correction2_errorthd_y_mask  (0x0003F000)
#define IM_DI_RTNR_CONTROL_cp_rtnr_rounding_correction2_mode_mask     (0x00000600)
#define IM_DI_RTNR_CONTROL_cp_rtnr_rounding_correction2_en_mask       (0x00000100)
#define IM_DI_RTNR_CONTROL_cp_rtnr_updatelockflg_mask                 (0x00000080)
#define IM_DI_RTNR_CONTROL_cp_rtnr_updatelocken_mask                  (0x00000040)
#define IM_DI_RTNR_CONTROL_cp_rtnr_mad_window_mask                    (0x00000030)
#define IM_DI_RTNR_CONTROL_cp_rtnr_rounding_correction_mask           (0x00000008)
#define IM_DI_RTNR_CONTROL_cp_rtnr_progressive_mask                   (0x00000004)
#define IM_DI_RTNR_CONTROL_cp_rtnr_c_enable_mask                      (0x00000002)
#define IM_DI_RTNR_CONTROL_cp_rtnr_y_enable_mask                      (0x00000001)
#define IM_DI_RTNR_CONTROL_cp_rtnr_interlace_force2d_en(data)         (0x80000000&((data)<<31))
#define IM_DI_RTNR_CONTROL_cp_rtnr_rgb444_enable(data)                (0x40000000&((data)<<30))
#define IM_DI_RTNR_CONTROL_cp_rtnr_rounding_correction2_errorthd_c(data)  (0x03F00000&((data)<<20))
#define IM_DI_RTNR_CONTROL_cp_rtnr_rounding_correction2_errorthd_y(data)  (0x0003F000&((data)<<12))
#define IM_DI_RTNR_CONTROL_cp_rtnr_rounding_correction2_mode(data)    (0x00000600&((data)<<9))
#define IM_DI_RTNR_CONTROL_cp_rtnr_rounding_correction2_en(data)      (0x00000100&((data)<<8))
#define IM_DI_RTNR_CONTROL_cp_rtnr_updatelockflg(data)                (0x00000080&((data)<<7))
#define IM_DI_RTNR_CONTROL_cp_rtnr_updatelocken(data)                 (0x00000040&((data)<<6))
#define IM_DI_RTNR_CONTROL_cp_rtnr_mad_window(data)                   (0x00000030&((data)<<4))
#define IM_DI_RTNR_CONTROL_cp_rtnr_rounding_correction(data)          (0x00000008&((data)<<3))
#define IM_DI_RTNR_CONTROL_cp_rtnr_progressive(data)                  (0x00000004&((data)<<2))
#define IM_DI_RTNR_CONTROL_cp_rtnr_c_enable(data)                     (0x00000002&((data)<<1))
#define IM_DI_RTNR_CONTROL_cp_rtnr_y_enable(data)                     (0x00000001&(data))
#define IM_DI_RTNR_CONTROL_get_cp_rtnr_interlace_force2d_en(data)     ((0x80000000&(data))>>31)
#define IM_DI_RTNR_CONTROL_get_cp_rtnr_rgb444_enable(data)            ((0x40000000&(data))>>30)
#define IM_DI_RTNR_CONTROL_get_cp_rtnr_rounding_correction2_errorthd_c(data)  ((0x03F00000&(data))>>20)
#define IM_DI_RTNR_CONTROL_get_cp_rtnr_rounding_correction2_errorthd_y(data)  ((0x0003F000&(data))>>12)
#define IM_DI_RTNR_CONTROL_get_cp_rtnr_rounding_correction2_mode(data)  ((0x00000600&(data))>>9)
#define IM_DI_RTNR_CONTROL_get_cp_rtnr_rounding_correction2_en(data)  ((0x00000100&(data))>>8)
#define IM_DI_RTNR_CONTROL_get_cp_rtnr_updatelockflg(data)            ((0x00000080&(data))>>7)
#define IM_DI_RTNR_CONTROL_get_cp_rtnr_updatelocken(data)             ((0x00000040&(data))>>6)
#define IM_DI_RTNR_CONTROL_get_cp_rtnr_mad_window(data)               ((0x00000030&(data))>>4)
#define IM_DI_RTNR_CONTROL_get_cp_rtnr_rounding_correction(data)      ((0x00000008&(data))>>3)
#define IM_DI_RTNR_CONTROL_get_cp_rtnr_progressive(data)              ((0x00000004&(data))>>2)
#define IM_DI_RTNR_CONTROL_get_cp_rtnr_c_enable(data)                 ((0x00000002&(data))>>1)
#define IM_DI_RTNR_CONTROL_get_cp_rtnr_y_enable(data)                 (0x00000001&(data))


#define IM_DI_DUMMY_0                                                 0x180241a4
#define IM_DI_DUMMY_0_reg_addr                                        "0xb80241a4"
#define IM_DI_DUMMY_0_reg                                             0xb80241a4
#define IM_DI_DUMMY_0_inst_addr                                       "0x0069"
#define IM_DI_DUMMY_0_inst                                            0x0069
#define IM_DI_DUMMY_0_dummy180241a4_31_0_shift                        (0)
#define IM_DI_DUMMY_0_dummy180241a4_31_0_mask                         (0xFFFFFFFF)
#define IM_DI_DUMMY_0_dummy180241a4_31_0(data)                        (0xFFFFFFFF&(data))
#define IM_DI_DUMMY_0_get_dummy180241a4_31_0(data)                    (0xFFFFFFFF&(data))


#define IM_DI_DUMMY_1                                                 0x180241a8
#define IM_DI_DUMMY_1_reg_addr                                        "0xb80241a8"
#define IM_DI_DUMMY_1_reg                                             0xb80241a8
#define IM_DI_DUMMY_1_inst_addr                                       "0x006A"
#define IM_DI_DUMMY_1_inst                                            0x006A
#define IM_DI_DUMMY_1_dummy180241a8_31_0_shift                        (0)
#define IM_DI_DUMMY_1_dummy180241a8_31_0_mask                         (0xFFFFFFFF)
#define IM_DI_DUMMY_1_dummy180241a8_31_0(data)                        (0xFFFFFFFF&(data))
#define IM_DI_DUMMY_1_get_dummy180241a8_31_0(data)                    (0xFFFFFFFF&(data))


#define IM_DI_DUMMY_2                                                 0x180241ac
#define IM_DI_DUMMY_2_reg_addr                                        "0xb80241ac"
#define IM_DI_DUMMY_2_reg                                             0xb80241ac
#define IM_DI_DUMMY_2_inst_addr                                       "0x006B"
#define IM_DI_DUMMY_2_inst                                            0x006B
#define IM_DI_DUMMY_2_dummy180241ac_31_0_shift                        (0)
#define IM_DI_DUMMY_2_dummy180241ac_31_0_mask                         (0xFFFFFFFF)
#define IM_DI_DUMMY_2_dummy180241ac_31_0(data)                        (0xFFFFFFFF&(data))
#define IM_DI_DUMMY_2_get_dummy180241ac_31_0(data)                    (0xFFFFFFFF&(data))


#define IM_DI_RTNR_MAD_Y_TH                                           0x180241b0
#define IM_DI_RTNR_MAD_Y_TH_reg_addr                                  "0xb80241b0"
#define IM_DI_RTNR_MAD_Y_TH_reg                                       0xb80241b0
#define IM_DI_RTNR_MAD_Y_TH_inst_addr                                 "0x006C"
#define IM_DI_RTNR_MAD_Y_TH_inst                                      0x006C
#define IM_DI_RTNR_MAD_Y_TH_cp_temporal_mad_y_th1_shift               (16)
#define IM_DI_RTNR_MAD_Y_TH_cp_temporal_mad_y_th2_shift               (0)
#define IM_DI_RTNR_MAD_Y_TH_cp_temporal_mad_y_th1_mask                (0x07FF0000)
#define IM_DI_RTNR_MAD_Y_TH_cp_temporal_mad_y_th2_mask                (0x000007FF)
#define IM_DI_RTNR_MAD_Y_TH_cp_temporal_mad_y_th1(data)               (0x07FF0000&((data)<<16))
#define IM_DI_RTNR_MAD_Y_TH_cp_temporal_mad_y_th2(data)               (0x000007FF&(data))
#define IM_DI_RTNR_MAD_Y_TH_get_cp_temporal_mad_y_th1(data)           ((0x07FF0000&(data))>>16)
#define IM_DI_RTNR_MAD_Y_TH_get_cp_temporal_mad_y_th2(data)           (0x000007FF&(data))


#define IM_DI_RTNR_MAD_C_TH                                           0x180241b4
#define IM_DI_RTNR_MAD_C_TH_reg_addr                                  "0xb80241b4"
#define IM_DI_RTNR_MAD_C_TH_reg                                       0xb80241b4
#define IM_DI_RTNR_MAD_C_TH_inst_addr                                 "0x006D"
#define IM_DI_RTNR_MAD_C_TH_inst                                      0x006D
#define IM_DI_RTNR_MAD_C_TH_cp_temporal_mad_c_th1_shift               (16)
#define IM_DI_RTNR_MAD_C_TH_cp_temporal_mad_c_th2_shift               (0)
#define IM_DI_RTNR_MAD_C_TH_cp_temporal_mad_c_th1_mask                (0x07FF0000)
#define IM_DI_RTNR_MAD_C_TH_cp_temporal_mad_c_th2_mask                (0x000007FF)
#define IM_DI_RTNR_MAD_C_TH_cp_temporal_mad_c_th1(data)               (0x07FF0000&((data)<<16))
#define IM_DI_RTNR_MAD_C_TH_cp_temporal_mad_c_th2(data)               (0x000007FF&(data))
#define IM_DI_RTNR_MAD_C_TH_get_cp_temporal_mad_c_th1(data)           ((0x07FF0000&(data))>>16)
#define IM_DI_RTNR_MAD_C_TH_get_cp_temporal_mad_c_th2(data)           (0x000007FF&(data))


#define IM_DI_RTNR_MAD_Y_COUNTER                                      0x180241b8
#define IM_DI_RTNR_MAD_Y_COUNTER_reg_addr                             "0xb80241b8"
#define IM_DI_RTNR_MAD_Y_COUNTER_reg                                  0xb80241b8
#define IM_DI_RTNR_MAD_Y_COUNTER_inst_addr                            "0x006E"
#define IM_DI_RTNR_MAD_Y_COUNTER_inst                                 0x006E
#define IM_DI_RTNR_MAD_Y_COUNTER_cp_temporal_mad_countery_shift       (0)
#define IM_DI_RTNR_MAD_Y_COUNTER_cp_temporal_mad_countery_mask        (0x001FFFFF)
#define IM_DI_RTNR_MAD_Y_COUNTER_cp_temporal_mad_countery(data)       (0x001FFFFF&(data))
#define IM_DI_RTNR_MAD_Y_COUNTER_get_cp_temporal_mad_countery(data)   (0x001FFFFF&(data))


#define IM_DI_RTNR_MAD_U_COUNTER                                      0x180241bc
#define IM_DI_RTNR_MAD_U_COUNTER_reg_addr                             "0xb80241bc"
#define IM_DI_RTNR_MAD_U_COUNTER_reg                                  0xb80241bc
#define IM_DI_RTNR_MAD_U_COUNTER_inst_addr                            "0x006F"
#define IM_DI_RTNR_MAD_U_COUNTER_inst                                 0x006F
#define IM_DI_RTNR_MAD_U_COUNTER_cp_temporal_mad_counteru_shift       (0)
#define IM_DI_RTNR_MAD_U_COUNTER_cp_temporal_mad_counteru_mask        (0x001FFFFF)
#define IM_DI_RTNR_MAD_U_COUNTER_cp_temporal_mad_counteru(data)       (0x001FFFFF&(data))
#define IM_DI_RTNR_MAD_U_COUNTER_get_cp_temporal_mad_counteru(data)   (0x001FFFFF&(data))


#define IM_DI_RTNR_MAD_V_COUNTER                                      0x180241c0
#define IM_DI_RTNR_MAD_V_COUNTER_reg_addr                             "0xb80241c0"
#define IM_DI_RTNR_MAD_V_COUNTER_reg                                  0xb80241c0
#define IM_DI_RTNR_MAD_V_COUNTER_inst_addr                            "0x0070"
#define IM_DI_RTNR_MAD_V_COUNTER_inst                                 0x0070
#define IM_DI_RTNR_MAD_V_COUNTER_cp_temporal_mad_counterv_shift       (0)
#define IM_DI_RTNR_MAD_V_COUNTER_cp_temporal_mad_counterv_mask        (0x001FFFFF)
#define IM_DI_RTNR_MAD_V_COUNTER_cp_temporal_mad_counterv(data)       (0x001FFFFF&(data))
#define IM_DI_RTNR_MAD_V_COUNTER_get_cp_temporal_mad_counterv(data)   (0x001FFFFF&(data))


#define IM_DI_RTNR_EDIFF_CONTROL                                      0x180241c4
#define IM_DI_RTNR_EDIFF_CONTROL_reg_addr                             "0xb80241c4"
#define IM_DI_RTNR_EDIFF_CONTROL_reg                                  0xb80241c4
#define IM_DI_RTNR_EDIFF_CONTROL_inst_addr                            "0x0071"
#define IM_DI_RTNR_EDIFF_CONTROL_inst                                 0x0071
#define IM_DI_RTNR_EDIFF_CONTROL_dummy180241c4_15_13_shift            (13)
#define IM_DI_RTNR_EDIFF_CONTROL_cp_temporal_num_match_l_shift        (9)
#define IM_DI_RTNR_EDIFF_CONTROL_cp_temporal_l_qlfy_th_shift          (5)
#define IM_DI_RTNR_EDIFF_CONTROL_cp_temporal_c_k_decision_shift       (2)
#define IM_DI_RTNR_EDIFF_CONTROL_cp_temporal_edge_crct_en_shift       (1)
#define IM_DI_RTNR_EDIFF_CONTROL_dummy180241c4_15_13_mask             (0x0000E000)
#define IM_DI_RTNR_EDIFF_CONTROL_cp_temporal_num_match_l_mask         (0x00001E00)
#define IM_DI_RTNR_EDIFF_CONTROL_cp_temporal_l_qlfy_th_mask           (0x000001E0)
#define IM_DI_RTNR_EDIFF_CONTROL_cp_temporal_c_k_decision_mask        (0x0000001C)
#define IM_DI_RTNR_EDIFF_CONTROL_cp_temporal_edge_crct_en_mask        (0x00000002)
#define IM_DI_RTNR_EDIFF_CONTROL_dummy180241c4_15_13(data)            (0x0000E000&((data)<<13))
#define IM_DI_RTNR_EDIFF_CONTROL_cp_temporal_num_match_l(data)        (0x00001E00&((data)<<9))
#define IM_DI_RTNR_EDIFF_CONTROL_cp_temporal_l_qlfy_th(data)          (0x000001E0&((data)<<5))
#define IM_DI_RTNR_EDIFF_CONTROL_cp_temporal_c_k_decision(data)       (0x0000001C&((data)<<2))
#define IM_DI_RTNR_EDIFF_CONTROL_cp_temporal_edge_crct_en(data)       (0x00000002&((data)<<1))
#define IM_DI_RTNR_EDIFF_CONTROL_get_dummy180241c4_15_13(data)        ((0x0000E000&(data))>>13)
#define IM_DI_RTNR_EDIFF_CONTROL_get_cp_temporal_num_match_l(data)    ((0x00001E00&(data))>>9)
#define IM_DI_RTNR_EDIFF_CONTROL_get_cp_temporal_l_qlfy_th(data)      ((0x000001E0&(data))>>5)
#define IM_DI_RTNR_EDIFF_CONTROL_get_cp_temporal_c_k_decision(data)   ((0x0000001C&(data))>>2)
#define IM_DI_RTNR_EDIFF_CONTROL_get_cp_temporal_edge_crct_en(data)   ((0x00000002&(data))>>1)


#define IM_DI_RTNR_SAD_OFFSET                                         0x180241c8
#define IM_DI_RTNR_SAD_OFFSET_reg_addr                                "0xb80241c8"
#define IM_DI_RTNR_SAD_OFFSET_reg                                     0xb80241c8
#define IM_DI_RTNR_SAD_OFFSET_inst_addr                               "0x0072"
#define IM_DI_RTNR_SAD_OFFSET_inst                                    0x0072
#define IM_DI_RTNR_SAD_OFFSET_cp_temporal_sad_offset_y_shift          (16)
#define IM_DI_RTNR_SAD_OFFSET_cp_temporal_sad_offset_u_shift          (8)
#define IM_DI_RTNR_SAD_OFFSET_cp_temporal_sad_offset_v_shift          (0)
#define IM_DI_RTNR_SAD_OFFSET_cp_temporal_sad_offset_y_mask           (0x00FF0000)
#define IM_DI_RTNR_SAD_OFFSET_cp_temporal_sad_offset_u_mask           (0x0000FF00)
#define IM_DI_RTNR_SAD_OFFSET_cp_temporal_sad_offset_v_mask           (0x000000FF)
#define IM_DI_RTNR_SAD_OFFSET_cp_temporal_sad_offset_y(data)          (0x00FF0000&((data)<<16))
#define IM_DI_RTNR_SAD_OFFSET_cp_temporal_sad_offset_u(data)          (0x0000FF00&((data)<<8))
#define IM_DI_RTNR_SAD_OFFSET_cp_temporal_sad_offset_v(data)          (0x000000FF&(data))
#define IM_DI_RTNR_SAD_OFFSET_get_cp_temporal_sad_offset_y(data)      ((0x00FF0000&(data))>>16)
#define IM_DI_RTNR_SAD_OFFSET_get_cp_temporal_sad_offset_u(data)      ((0x0000FF00&(data))>>8)
#define IM_DI_RTNR_SAD_OFFSET_get_cp_temporal_sad_offset_v(data)      (0x000000FF&(data))


#define IM_DI_RTNR_EDIFF_TH                                           0x180241cc
#define IM_DI_RTNR_EDIFF_TH_reg_addr                                  "0xb80241cc"
#define IM_DI_RTNR_EDIFF_TH_reg                                       0xb80241cc
#define IM_DI_RTNR_EDIFF_TH_inst_addr                                 "0x0073"
#define IM_DI_RTNR_EDIFF_TH_inst                                      0x0073
#define IM_DI_RTNR_EDIFF_TH_cp_temporal_e_th1_y_shift                 (24)
#define IM_DI_RTNR_EDIFF_TH_cp_temporal_e_th2_y_shift                 (16)
#define IM_DI_RTNR_EDIFF_TH_cp_temporal_e_th1_c_shift                 (8)
#define IM_DI_RTNR_EDIFF_TH_cp_temporal_e_th2_c_shift                 (0)
#define IM_DI_RTNR_EDIFF_TH_cp_temporal_e_th1_y_mask                  (0xFF000000)
#define IM_DI_RTNR_EDIFF_TH_cp_temporal_e_th2_y_mask                  (0x00FF0000)
#define IM_DI_RTNR_EDIFF_TH_cp_temporal_e_th1_c_mask                  (0x0000FF00)
#define IM_DI_RTNR_EDIFF_TH_cp_temporal_e_th2_c_mask                  (0x000000FF)
#define IM_DI_RTNR_EDIFF_TH_cp_temporal_e_th1_y(data)                 (0xFF000000&((data)<<24))
#define IM_DI_RTNR_EDIFF_TH_cp_temporal_e_th2_y(data)                 (0x00FF0000&((data)<<16))
#define IM_DI_RTNR_EDIFF_TH_cp_temporal_e_th1_c(data)                 (0x0000FF00&((data)<<8))
#define IM_DI_RTNR_EDIFF_TH_cp_temporal_e_th2_c(data)                 (0x000000FF&(data))
#define IM_DI_RTNR_EDIFF_TH_get_cp_temporal_e_th1_y(data)             ((0xFF000000&(data))>>24)
#define IM_DI_RTNR_EDIFF_TH_get_cp_temporal_e_th2_y(data)             ((0x00FF0000&(data))>>16)
#define IM_DI_RTNR_EDIFF_TH_get_cp_temporal_e_th1_c(data)             ((0x0000FF00&(data))>>8)
#define IM_DI_RTNR_EDIFF_TH_get_cp_temporal_e_th2_c(data)             (0x000000FF&(data))


#define IM_DI_RTNR_EDIFF_SOBEL_TH                                     0x180241d0
#define IM_DI_RTNR_EDIFF_SOBEL_TH_reg_addr                            "0xb80241d0"
#define IM_DI_RTNR_EDIFF_SOBEL_TH_reg                                 0xb80241d0
#define IM_DI_RTNR_EDIFF_SOBEL_TH_inst_addr                           "0x0074"
#define IM_DI_RTNR_EDIFF_SOBEL_TH_inst                                0x0074
#define IM_DI_RTNR_EDIFF_SOBEL_TH_dummy180241d0_31_22_shift           (22)
#define IM_DI_RTNR_EDIFF_SOBEL_TH_cp_temporal_sbl_thm_y_shift         (12)
#define IM_DI_RTNR_EDIFF_SOBEL_TH_dummy180241d0_11_10_shift           (10)
#define IM_DI_RTNR_EDIFF_SOBEL_TH_cp_temporal_sbl_ths_y_shift         (0)
#define IM_DI_RTNR_EDIFF_SOBEL_TH_dummy180241d0_31_22_mask            (0xFFC00000)
#define IM_DI_RTNR_EDIFF_SOBEL_TH_cp_temporal_sbl_thm_y_mask          (0x003FF000)
#define IM_DI_RTNR_EDIFF_SOBEL_TH_dummy180241d0_11_10_mask            (0x00000C00)
#define IM_DI_RTNR_EDIFF_SOBEL_TH_cp_temporal_sbl_ths_y_mask          (0x000003FF)
#define IM_DI_RTNR_EDIFF_SOBEL_TH_dummy180241d0_31_22(data)           (0xFFC00000&((data)<<22))
#define IM_DI_RTNR_EDIFF_SOBEL_TH_cp_temporal_sbl_thm_y(data)         (0x003FF000&((data)<<12))
#define IM_DI_RTNR_EDIFF_SOBEL_TH_dummy180241d0_11_10(data)           (0x00000C00&((data)<<10))
#define IM_DI_RTNR_EDIFF_SOBEL_TH_cp_temporal_sbl_ths_y(data)         (0x000003FF&(data))
#define IM_DI_RTNR_EDIFF_SOBEL_TH_get_dummy180241d0_31_22(data)       ((0xFFC00000&(data))>>22)
#define IM_DI_RTNR_EDIFF_SOBEL_TH_get_cp_temporal_sbl_thm_y(data)     ((0x003FF000&(data))>>12)
#define IM_DI_RTNR_EDIFF_SOBEL_TH_get_dummy180241d0_11_10(data)       ((0x00000C00&(data))>>10)
#define IM_DI_RTNR_EDIFF_SOBEL_TH_get_cp_temporal_sbl_ths_y(data)     (0x000003FF&(data))


#define IM_DI_RTNR_LEVEL_BOUND                                        0x180241d4
#define IM_DI_RTNR_LEVEL_BOUND_reg_addr                               "0xb80241d4"
#define IM_DI_RTNR_LEVEL_BOUND_reg                                    0xb80241d4
#define IM_DI_RTNR_LEVEL_BOUND_inst_addr                              "0x0075"
#define IM_DI_RTNR_LEVEL_BOUND_inst                                   0x0075
#define IM_DI_RTNR_LEVEL_BOUND_cp_temporal_nl_up_bnd_y_shift          (8)
#define IM_DI_RTNR_LEVEL_BOUND_cp_temporal_nl_low_bnd_y_shift         (0)
#define IM_DI_RTNR_LEVEL_BOUND_cp_temporal_nl_up_bnd_y_mask           (0x0000FF00)
#define IM_DI_RTNR_LEVEL_BOUND_cp_temporal_nl_low_bnd_y_mask          (0x000000FF)
#define IM_DI_RTNR_LEVEL_BOUND_cp_temporal_nl_up_bnd_y(data)          (0x0000FF00&((data)<<8))
#define IM_DI_RTNR_LEVEL_BOUND_cp_temporal_nl_low_bnd_y(data)         (0x000000FF&(data))
#define IM_DI_RTNR_LEVEL_BOUND_get_cp_temporal_nl_up_bnd_y(data)      ((0x0000FF00&(data))>>8)
#define IM_DI_RTNR_LEVEL_BOUND_get_cp_temporal_nl_low_bnd_y(data)     (0x000000FF&(data))


#define IM_DI_RTNR_ET_COUNT_Y                                         0x180241d8
#define IM_DI_RTNR_ET_COUNT_Y_reg_addr                                "0xb80241d8"
#define IM_DI_RTNR_ET_COUNT_Y_reg                                     0xb80241d8
#define IM_DI_RTNR_ET_COUNT_Y_inst_addr                               "0x0076"
#define IM_DI_RTNR_ET_COUNT_Y_inst                                    0x0076
#define IM_DI_RTNR_ET_COUNT_Y_cp_temporal_same_et_cnt_y_shift         (0)
#define IM_DI_RTNR_ET_COUNT_Y_cp_temporal_same_et_cnt_y_mask          (0x00FFFFFF)
#define IM_DI_RTNR_ET_COUNT_Y_cp_temporal_same_et_cnt_y(data)         (0x00FFFFFF&(data))
#define IM_DI_RTNR_ET_COUNT_Y_get_cp_temporal_same_et_cnt_y(data)     (0x00FFFFFF&(data))


#define IM_DI_RTNR_ET_SUM_Y                                           0x180241dc
#define IM_DI_RTNR_ET_SUM_Y_reg_addr                                  "0xb80241dc"
#define IM_DI_RTNR_ET_SUM_Y_reg                                       0xb80241dc
#define IM_DI_RTNR_ET_SUM_Y_inst_addr                                 "0x0077"
#define IM_DI_RTNR_ET_SUM_Y_inst                                      0x0077
#define IM_DI_RTNR_ET_SUM_Y_cp_temporal_same_et_sad_sum_y_shift       (0)
#define IM_DI_RTNR_ET_SUM_Y_cp_temporal_same_et_sad_sum_y_mask        (0xFFFFFFFF)
#define IM_DI_RTNR_ET_SUM_Y_cp_temporal_same_et_sad_sum_y(data)       (0xFFFFFFFF&(data))
#define IM_DI_RTNR_ET_SUM_Y_get_cp_temporal_same_et_sad_sum_y(data)   (0xFFFFFFFF&(data))


#define IM_DI_RTNR_ET_SUM_U                                           0x180241e0
#define IM_DI_RTNR_ET_SUM_U_reg_addr                                  "0xb80241e0"
#define IM_DI_RTNR_ET_SUM_U_reg                                       0xb80241e0
#define IM_DI_RTNR_ET_SUM_U_inst_addr                                 "0x0078"
#define IM_DI_RTNR_ET_SUM_U_inst                                      0x0078
#define IM_DI_RTNR_ET_SUM_U_cp_temporal_same_et_sad_sum_u_shift       (0)
#define IM_DI_RTNR_ET_SUM_U_cp_temporal_same_et_sad_sum_u_mask        (0xFFFFFFFF)
#define IM_DI_RTNR_ET_SUM_U_cp_temporal_same_et_sad_sum_u(data)       (0xFFFFFFFF&(data))
#define IM_DI_RTNR_ET_SUM_U_get_cp_temporal_same_et_sad_sum_u(data)   (0xFFFFFFFF&(data))


#define IM_DI_RTNR_ET_SUM_V                                           0x180241e4
#define IM_DI_RTNR_ET_SUM_V_reg_addr                                  "0xb80241e4"
#define IM_DI_RTNR_ET_SUM_V_reg                                       0xb80241e4
#define IM_DI_RTNR_ET_SUM_V_inst_addr                                 "0x0079"
#define IM_DI_RTNR_ET_SUM_V_inst                                      0x0079
#define IM_DI_RTNR_ET_SUM_V_cp_temporal_same_et_sad_sum_v_shift       (0)
#define IM_DI_RTNR_ET_SUM_V_cp_temporal_same_et_sad_sum_v_mask        (0xFFFFFFFF)
#define IM_DI_RTNR_ET_SUM_V_cp_temporal_same_et_sad_sum_v(data)       (0xFFFFFFFF&(data))
#define IM_DI_RTNR_ET_SUM_V_get_cp_temporal_same_et_sad_sum_v(data)   (0xFFFFFFFF&(data))


#define IM_DI_TNR_XC_CONTROL                                          0x180241e8
#define IM_DI_TNR_XC_CONTROL_reg_addr                                 "0xb80241e8"
#define IM_DI_TNR_XC_CONTROL_reg                                      0xb80241e8
#define IM_DI_TNR_XC_CONTROL_inst_addr                                "0x007A"
#define IM_DI_TNR_XC_CONTROL_inst                                     0x007A
#define IM_DI_TNR_XC_CONTROL_set_sobeledgetypeen_shift                (31)
#define IM_DI_TNR_XC_CONTROL_set_stillmotion_tha_shift                (27)
#define IM_DI_TNR_XC_CONTROL_set_stillmotion_thb_shift                (23)
#define IM_DI_TNR_XC_CONTROL_set_stillmotion_thc_shift                (19)
#define IM_DI_TNR_XC_CONTROL_set_classifysmooth_shift                 (16)
#define IM_DI_TNR_XC_CONTROL_set_frame_offset_verystill_shift         (12)
#define IM_DI_TNR_XC_CONTROL_set_frame_offset_still_shift             (9)
#define IM_DI_TNR_XC_CONTROL_set_frame_offset_motion_shift            (6)
#define IM_DI_TNR_XC_CONTROL_set_frame_offset_verymotion_shift        (2)
#define IM_DI_TNR_XC_CONTROL_cp_temporal_xc_switch_shift              (1)
#define IM_DI_TNR_XC_CONTROL_cp_temporal_xc_en_shift                  (0)
#define IM_DI_TNR_XC_CONTROL_set_sobeledgetypeen_mask                 (0x80000000)
#define IM_DI_TNR_XC_CONTROL_set_stillmotion_tha_mask                 (0x78000000)
#define IM_DI_TNR_XC_CONTROL_set_stillmotion_thb_mask                 (0x07800000)
#define IM_DI_TNR_XC_CONTROL_set_stillmotion_thc_mask                 (0x00780000)
#define IM_DI_TNR_XC_CONTROL_set_classifysmooth_mask                  (0x00070000)
#define IM_DI_TNR_XC_CONTROL_set_frame_offset_verystill_mask          (0x0000F000)
#define IM_DI_TNR_XC_CONTROL_set_frame_offset_still_mask              (0x00000E00)
#define IM_DI_TNR_XC_CONTROL_set_frame_offset_motion_mask             (0x000001C0)
#define IM_DI_TNR_XC_CONTROL_set_frame_offset_verymotion_mask         (0x0000003C)
#define IM_DI_TNR_XC_CONTROL_cp_temporal_xc_switch_mask               (0x00000002)
#define IM_DI_TNR_XC_CONTROL_cp_temporal_xc_en_mask                   (0x00000001)
#define IM_DI_TNR_XC_CONTROL_set_sobeledgetypeen(data)                (0x80000000&((data)<<31))
#define IM_DI_TNR_XC_CONTROL_set_stillmotion_tha(data)                (0x78000000&((data)<<27))
#define IM_DI_TNR_XC_CONTROL_set_stillmotion_thb(data)                (0x07800000&((data)<<23))
#define IM_DI_TNR_XC_CONTROL_set_stillmotion_thc(data)                (0x00780000&((data)<<19))
#define IM_DI_TNR_XC_CONTROL_set_classifysmooth(data)                 (0x00070000&((data)<<16))
#define IM_DI_TNR_XC_CONTROL_set_frame_offset_verystill(data)         (0x0000F000&((data)<<12))
#define IM_DI_TNR_XC_CONTROL_set_frame_offset_still(data)             (0x00000E00&((data)<<9))
#define IM_DI_TNR_XC_CONTROL_set_frame_offset_motion(data)            (0x000001C0&((data)<<6))
#define IM_DI_TNR_XC_CONTROL_set_frame_offset_verymotion(data)        (0x0000003C&((data)<<2))
#define IM_DI_TNR_XC_CONTROL_cp_temporal_xc_switch(data)              (0x00000002&((data)<<1))
#define IM_DI_TNR_XC_CONTROL_cp_temporal_xc_en(data)                  (0x00000001&(data))
#define IM_DI_TNR_XC_CONTROL_get_set_sobeledgetypeen(data)            ((0x80000000&(data))>>31)
#define IM_DI_TNR_XC_CONTROL_get_set_stillmotion_tha(data)            ((0x78000000&(data))>>27)
#define IM_DI_TNR_XC_CONTROL_get_set_stillmotion_thb(data)            ((0x07800000&(data))>>23)
#define IM_DI_TNR_XC_CONTROL_get_set_stillmotion_thc(data)            ((0x00780000&(data))>>19)
#define IM_DI_TNR_XC_CONTROL_get_set_classifysmooth(data)             ((0x00070000&(data))>>16)
#define IM_DI_TNR_XC_CONTROL_get_set_frame_offset_verystill(data)     ((0x0000F000&(data))>>12)
#define IM_DI_TNR_XC_CONTROL_get_set_frame_offset_still(data)         ((0x00000E00&(data))>>9)
#define IM_DI_TNR_XC_CONTROL_get_set_frame_offset_motion(data)        ((0x000001C0&(data))>>6)
#define IM_DI_TNR_XC_CONTROL_get_set_frame_offset_verymotion(data)    ((0x0000003C&(data))>>2)
#define IM_DI_TNR_XC_CONTROL_get_cp_temporal_xc_switch(data)          ((0x00000002&(data))>>1)
#define IM_DI_TNR_XC_CONTROL_get_cp_temporal_xc_en(data)              (0x00000001&(data))


#define IM_DI_HFD_CONTROL                                             0x180241ec
#define IM_DI_HFD_CONTROL_reg_addr                                    "0xb80241ec"
#define IM_DI_HFD_CONTROL_reg                                         0xb80241ec
#define IM_DI_HFD_CONTROL_inst_addr                                   "0x007B"
#define IM_DI_HFD_CONTROL_inst                                        0x007B
#define IM_DI_HFD_CONTROL_set_sobeledgetype_sel_shift                 (30)
#define IM_DI_HFD_CONTROL_hfd_highfrequencydetectoren_shift           (24)
#define IM_DI_HFD_CONTROL_hfd_highlowhighdiff_thl_shift               (16)
#define IM_DI_HFD_CONTROL_hfd_highlowhighdiff_count_thl_shift         (8)
#define IM_DI_HFD_CONTROL_hfd_manyteethareastilllogoen_shift          (4)
#define IM_DI_HFD_CONTROL_hfd_3x3blockteethcount_thl_shift            (0)
#define IM_DI_HFD_CONTROL_set_sobeledgetype_sel_mask                  (0xC0000000)
#define IM_DI_HFD_CONTROL_hfd_highfrequencydetectoren_mask            (0x01000000)
#define IM_DI_HFD_CONTROL_hfd_highlowhighdiff_thl_mask                (0x00FF0000)
#define IM_DI_HFD_CONTROL_hfd_highlowhighdiff_count_thl_mask          (0x00000F00)
#define IM_DI_HFD_CONTROL_hfd_manyteethareastilllogoen_mask           (0x00000010)
#define IM_DI_HFD_CONTROL_hfd_3x3blockteethcount_thl_mask             (0x0000000F)
#define IM_DI_HFD_CONTROL_set_sobeledgetype_sel(data)                 (0xC0000000&((data)<<30))
#define IM_DI_HFD_CONTROL_hfd_highfrequencydetectoren(data)           (0x01000000&((data)<<24))
#define IM_DI_HFD_CONTROL_hfd_highlowhighdiff_thl(data)               (0x00FF0000&((data)<<16))
#define IM_DI_HFD_CONTROL_hfd_highlowhighdiff_count_thl(data)         (0x00000F00&((data)<<8))
#define IM_DI_HFD_CONTROL_hfd_manyteethareastilllogoen(data)          (0x00000010&((data)<<4))
#define IM_DI_HFD_CONTROL_hfd_3x3blockteethcount_thl(data)            (0x0000000F&(data))
#define IM_DI_HFD_CONTROL_get_set_sobeledgetype_sel(data)             ((0xC0000000&(data))>>30)
#define IM_DI_HFD_CONTROL_get_hfd_highfrequencydetectoren(data)       ((0x01000000&(data))>>24)
#define IM_DI_HFD_CONTROL_get_hfd_highlowhighdiff_thl(data)           ((0x00FF0000&(data))>>16)
#define IM_DI_HFD_CONTROL_get_hfd_highlowhighdiff_count_thl(data)     ((0x00000F00&(data))>>8)
#define IM_DI_HFD_CONTROL_get_hfd_manyteethareastilllogoen(data)      ((0x00000010&(data))>>4)
#define IM_DI_HFD_CONTROL_get_hfd_3x3blockteethcount_thl(data)        (0x0000000F&(data))


#define IM_DI_HFD_LINE_MOTION_COUNT                                   0x180241f0
#define IM_DI_HFD_LINE_MOTION_COUNT_reg_addr                          "0xb80241f0"
#define IM_DI_HFD_LINE_MOTION_COUNT_reg                               0xb80241f0
#define IM_DI_HFD_LINE_MOTION_COUNT_inst_addr                         "0x007C"
#define IM_DI_HFD_LINE_MOTION_COUNT_inst                              0x007C
#define IM_DI_HFD_LINE_MOTION_COUNT_hfd_checklinemotioncounten_shift  (31)
#define IM_DI_HFD_LINE_MOTION_COUNT_hfd_framekcombineoflinemotion_shift  (29)
#define IM_DI_HFD_LINE_MOTION_COUNT_hfd_linemotioncount_thl2_shift    (16)
#define IM_DI_HFD_LINE_MOTION_COUNT_hfd_linemotioncount_thl_shift     (0)
#define IM_DI_HFD_LINE_MOTION_COUNT_hfd_checklinemotioncounten_mask   (0x80000000)
#define IM_DI_HFD_LINE_MOTION_COUNT_hfd_framekcombineoflinemotion_mask  (0x60000000)
#define IM_DI_HFD_LINE_MOTION_COUNT_hfd_linemotioncount_thl2_mask     (0x07FF0000)
#define IM_DI_HFD_LINE_MOTION_COUNT_hfd_linemotioncount_thl_mask      (0x000007FF)
#define IM_DI_HFD_LINE_MOTION_COUNT_hfd_checklinemotioncounten(data)  (0x80000000&((data)<<31))
#define IM_DI_HFD_LINE_MOTION_COUNT_hfd_framekcombineoflinemotion(data)  (0x60000000&((data)<<29))
#define IM_DI_HFD_LINE_MOTION_COUNT_hfd_linemotioncount_thl2(data)    (0x07FF0000&((data)<<16))
#define IM_DI_HFD_LINE_MOTION_COUNT_hfd_linemotioncount_thl(data)     (0x000007FF&(data))
#define IM_DI_HFD_LINE_MOTION_COUNT_get_hfd_checklinemotioncounten(data)  ((0x80000000&(data))>>31)
#define IM_DI_HFD_LINE_MOTION_COUNT_get_hfd_framekcombineoflinemotion(data)  ((0x60000000&(data))>>29)
#define IM_DI_HFD_LINE_MOTION_COUNT_get_hfd_linemotioncount_thl2(data)  ((0x07FF0000&(data))>>16)
#define IM_DI_HFD_LINE_MOTION_COUNT_get_hfd_linemotioncount_thl(data) (0x000007FF&(data))


#define IM_DI_HFD_STATISTIC                                           0x180241f4
#define IM_DI_HFD_STATISTIC_reg_addr                                  "0xb80241f4"
#define IM_DI_HFD_STATISTIC_reg                                       0xb80241f4
#define IM_DI_HFD_STATISTIC_inst_addr                                 "0x007D"
#define IM_DI_HFD_STATISTIC_inst                                      0x007D
#define IM_DI_HFD_STATISTIC_hfd_statistic_shift                       (0)
#define IM_DI_HFD_STATISTIC_hfd_statistic_mask                        (0x00FFFFFF)
#define IM_DI_HFD_STATISTIC_hfd_statistic(data)                       (0x00FFFFFF&(data))
#define IM_DI_HFD_STATISTIC_get_hfd_statistic(data)                   (0x00FFFFFF&(data))


#define IM_DI_HFD_MA_ERROR_RECOVERY                                   0x180241f8
#define IM_DI_HFD_MA_ERROR_RECOVERY_reg_addr                          "0xb80241f8"
#define IM_DI_HFD_MA_ERROR_RECOVERY_reg                               0xb80241f8
#define IM_DI_HFD_MA_ERROR_RECOVERY_inst_addr                         "0x007E"
#define IM_DI_HFD_MA_ERROR_RECOVERY_inst                              0x007E
#define IM_DI_HFD_MA_ERROR_RECOVERY_hmc_window_en_shift               (28)
#define IM_DI_HFD_MA_ERROR_RECOVERY_hmc_window_top_shift              (18)
#define IM_DI_HFD_MA_ERROR_RECOVERY_hmc_window_bot_shift              (8)
#define IM_DI_HFD_MA_ERROR_RECOVERY_ma_teeth_cont_check_dma_en_shift  (7)
#define IM_DI_HFD_MA_ERROR_RECOVERY_ma_teeth_cont_filter_en_shift     (6)
#define IM_DI_HFD_MA_ERROR_RECOVERY_ma_teeth_cont_check_en_shift      (4)
#define IM_DI_HFD_MA_ERROR_RECOVERY_ma_teeth_cont_check_th_shift      (2)
#define IM_DI_HFD_MA_ERROR_RECOVERY_stilllogolrcorrectionen_shift     (1)
#define IM_DI_HFD_MA_ERROR_RECOVERY_stilllogoweavelineen_shift        (0)
#define IM_DI_HFD_MA_ERROR_RECOVERY_hmc_window_en_mask                (0x10000000)
#define IM_DI_HFD_MA_ERROR_RECOVERY_hmc_window_top_mask               (0x0FFC0000)
#define IM_DI_HFD_MA_ERROR_RECOVERY_hmc_window_bot_mask               (0x0003FF00)
#define IM_DI_HFD_MA_ERROR_RECOVERY_ma_teeth_cont_check_dma_en_mask   (0x00000080)
#define IM_DI_HFD_MA_ERROR_RECOVERY_ma_teeth_cont_filter_en_mask      (0x00000040)
#define IM_DI_HFD_MA_ERROR_RECOVERY_ma_teeth_cont_check_en_mask       (0x00000030)
#define IM_DI_HFD_MA_ERROR_RECOVERY_ma_teeth_cont_check_th_mask       (0x0000000C)
#define IM_DI_HFD_MA_ERROR_RECOVERY_stilllogolrcorrectionen_mask      (0x00000002)
#define IM_DI_HFD_MA_ERROR_RECOVERY_stilllogoweavelineen_mask         (0x00000001)
#define IM_DI_HFD_MA_ERROR_RECOVERY_hmc_window_en(data)               (0x10000000&((data)<<28))
#define IM_DI_HFD_MA_ERROR_RECOVERY_hmc_window_top(data)              (0x0FFC0000&((data)<<18))
#define IM_DI_HFD_MA_ERROR_RECOVERY_hmc_window_bot(data)              (0x0003FF00&((data)<<8))
#define IM_DI_HFD_MA_ERROR_RECOVERY_ma_teeth_cont_check_dma_en(data)  (0x00000080&((data)<<7))
#define IM_DI_HFD_MA_ERROR_RECOVERY_ma_teeth_cont_filter_en(data)     (0x00000040&((data)<<6))
#define IM_DI_HFD_MA_ERROR_RECOVERY_ma_teeth_cont_check_en(data)      (0x00000030&((data)<<4))
#define IM_DI_HFD_MA_ERROR_RECOVERY_ma_teeth_cont_check_th(data)      (0x0000000C&((data)<<2))
#define IM_DI_HFD_MA_ERROR_RECOVERY_stilllogolrcorrectionen(data)     (0x00000002&((data)<<1))
#define IM_DI_HFD_MA_ERROR_RECOVERY_stilllogoweavelineen(data)        (0x00000001&(data))
#define IM_DI_HFD_MA_ERROR_RECOVERY_get_hmc_window_en(data)           ((0x10000000&(data))>>28)
#define IM_DI_HFD_MA_ERROR_RECOVERY_get_hmc_window_top(data)          ((0x0FFC0000&(data))>>18)
#define IM_DI_HFD_MA_ERROR_RECOVERY_get_hmc_window_bot(data)          ((0x0003FF00&(data))>>8)
#define IM_DI_HFD_MA_ERROR_RECOVERY_get_ma_teeth_cont_check_dma_en(data)  ((0x00000080&(data))>>7)
#define IM_DI_HFD_MA_ERROR_RECOVERY_get_ma_teeth_cont_filter_en(data) ((0x00000040&(data))>>6)
#define IM_DI_HFD_MA_ERROR_RECOVERY_get_ma_teeth_cont_check_en(data)  ((0x00000030&(data))>>4)
#define IM_DI_HFD_MA_ERROR_RECOVERY_get_ma_teeth_cont_check_th(data)  ((0x0000000C&(data))>>2)
#define IM_DI_HFD_MA_ERROR_RECOVERY_get_stilllogolrcorrectionen(data) ((0x00000002&(data))>>1)
#define IM_DI_HFD_MA_ERROR_RECOVERY_get_stilllogoweavelineen(data)    (0x00000001&(data))


#define IM_DI_NEW_INTRA_LOW_ANGLE                                     0x180241fc
#define IM_DI_NEW_INTRA_LOW_ANGLE_reg_addr                            "0xb80241fc"
#define IM_DI_NEW_INTRA_LOW_ANGLE_reg                                 0xb80241fc
#define IM_DI_NEW_INTRA_LOW_ANGLE_inst_addr                           "0x007F"
#define IM_DI_NEW_INTRA_LOW_ANGLE_inst                                0x007F
#define IM_DI_NEW_INTRA_LOW_ANGLE_newintralowangle_continuous_pt_shift  (25)
#define IM_DI_NEW_INTRA_LOW_ANGLE_newintralowangle_precur_diff_thd_shift  (15)
#define IM_DI_NEW_INTRA_LOW_ANGLE_newintralowangle_vercur_diff_thd_shift  (5)
#define IM_DI_NEW_INTRA_LOW_ANGLE_newintralowangle_left_dir_shift     (3)
#define IM_DI_NEW_INTRA_LOW_ANGLE_newintralowangle_right_dir_shift    (1)
#define IM_DI_NEW_INTRA_LOW_ANGLE_newintralowangle_enable_shift       (0)
#define IM_DI_NEW_INTRA_LOW_ANGLE_newintralowangle_continuous_pt_mask (0xFE000000)
#define IM_DI_NEW_INTRA_LOW_ANGLE_newintralowangle_precur_diff_thd_mask  (0x01FF8000)
#define IM_DI_NEW_INTRA_LOW_ANGLE_newintralowangle_vercur_diff_thd_mask  (0x00007FE0)
#define IM_DI_NEW_INTRA_LOW_ANGLE_newintralowangle_left_dir_mask      (0x00000018)
#define IM_DI_NEW_INTRA_LOW_ANGLE_newintralowangle_right_dir_mask     (0x00000006)
#define IM_DI_NEW_INTRA_LOW_ANGLE_newintralowangle_enable_mask        (0x00000001)
#define IM_DI_NEW_INTRA_LOW_ANGLE_newintralowangle_continuous_pt(data)  (0xFE000000&((data)<<25))
#define IM_DI_NEW_INTRA_LOW_ANGLE_newintralowangle_precur_diff_thd(data)  (0x01FF8000&((data)<<15))
#define IM_DI_NEW_INTRA_LOW_ANGLE_newintralowangle_vercur_diff_thd(data)  (0x00007FE0&((data)<<5))
#define IM_DI_NEW_INTRA_LOW_ANGLE_newintralowangle_left_dir(data)     (0x00000018&((data)<<3))
#define IM_DI_NEW_INTRA_LOW_ANGLE_newintralowangle_right_dir(data)    (0x00000006&((data)<<1))
#define IM_DI_NEW_INTRA_LOW_ANGLE_newintralowangle_enable(data)       (0x00000001&(data))
#define IM_DI_NEW_INTRA_LOW_ANGLE_get_newintralowangle_continuous_pt(data)  ((0xFE000000&(data))>>25)
#define IM_DI_NEW_INTRA_LOW_ANGLE_get_newintralowangle_precur_diff_thd(data)  ((0x01FF8000&(data))>>15)
#define IM_DI_NEW_INTRA_LOW_ANGLE_get_newintralowangle_vercur_diff_thd(data)  ((0x00007FE0&(data))>>5)
#define IM_DI_NEW_INTRA_LOW_ANGLE_get_newintralowangle_left_dir(data) ((0x00000018&(data))>>3)
#define IM_DI_NEW_INTRA_LOW_ANGLE_get_newintralowangle_right_dir(data)  ((0x00000006&(data))>>1)
#define IM_DI_NEW_INTRA_LOW_ANGLE_get_newintralowangle_enable(data)   (0x00000001&(data))


#define IM_DI_INTRA_NEW_GRADIENT_CORRECT                              0x18024200
#define IM_DI_INTRA_NEW_GRADIENT_CORRECT_reg_addr                     "0xb8024200"
#define IM_DI_INTRA_NEW_GRADIENT_CORRECT_reg                          0xb8024200
#define IM_DI_INTRA_NEW_GRADIENT_CORRECT_inst_addr                    "0x0080"
#define IM_DI_INTRA_NEW_GRADIENT_CORRECT_inst                         0x0080
#define IM_DI_INTRA_NEW_GRADIENT_CORRECT_intranewgracorr_transpt_thd_shift  (24)
#define IM_DI_INTRA_NEW_GRADIENT_CORRECT_intranewgracorr_gradmatchmin_thd_shift  (16)
#define IM_DI_INTRA_NEW_GRADIENT_CORRECT_intranewgracorr_gradmatchdiff_thd_shift  (8)
#define IM_DI_INTRA_NEW_GRADIENT_CORRECT_intranewgracorr_mintransrange_shift  (4)
#define IM_DI_INTRA_NEW_GRADIENT_CORRECT_intranewgracorr_minmatchdifftransrange_shift  (0)
#define IM_DI_INTRA_NEW_GRADIENT_CORRECT_intranewgracorr_transpt_thd_mask  (0xFF000000)
#define IM_DI_INTRA_NEW_GRADIENT_CORRECT_intranewgracorr_gradmatchmin_thd_mask  (0x00FF0000)
#define IM_DI_INTRA_NEW_GRADIENT_CORRECT_intranewgracorr_gradmatchdiff_thd_mask  (0x0000FF00)
#define IM_DI_INTRA_NEW_GRADIENT_CORRECT_intranewgracorr_mintransrange_mask  (0x000000F0)
#define IM_DI_INTRA_NEW_GRADIENT_CORRECT_intranewgracorr_minmatchdifftransrange_mask  (0x0000000F)
#define IM_DI_INTRA_NEW_GRADIENT_CORRECT_intranewgracorr_transpt_thd(data)  (0xFF000000&((data)<<24))
#define IM_DI_INTRA_NEW_GRADIENT_CORRECT_intranewgracorr_gradmatchmin_thd(data)  (0x00FF0000&((data)<<16))
#define IM_DI_INTRA_NEW_GRADIENT_CORRECT_intranewgracorr_gradmatchdiff_thd(data)  (0x0000FF00&((data)<<8))
#define IM_DI_INTRA_NEW_GRADIENT_CORRECT_intranewgracorr_mintransrange(data)  (0x000000F0&((data)<<4))
#define IM_DI_INTRA_NEW_GRADIENT_CORRECT_intranewgracorr_minmatchdifftransrange(data)  (0x0000000F&(data))
#define IM_DI_INTRA_NEW_GRADIENT_CORRECT_get_intranewgracorr_transpt_thd(data)  ((0xFF000000&(data))>>24)
#define IM_DI_INTRA_NEW_GRADIENT_CORRECT_get_intranewgracorr_gradmatchmin_thd(data)  ((0x00FF0000&(data))>>16)
#define IM_DI_INTRA_NEW_GRADIENT_CORRECT_get_intranewgracorr_gradmatchdiff_thd(data)  ((0x0000FF00&(data))>>8)
#define IM_DI_INTRA_NEW_GRADIENT_CORRECT_get_intranewgracorr_mintransrange(data)  ((0x000000F0&(data))>>4)
#define IM_DI_INTRA_NEW_GRADIENT_CORRECT_get_intranewgracorr_minmatchdifftransrange(data)  (0x0000000F&(data))


#define IM_DI_INTRA_POST_PROCESS                                      0x18024204
#define IM_DI_INTRA_POST_PROCESS_reg_addr                             "0xb8024204"
#define IM_DI_INTRA_POST_PROCESS_reg                                  0xb8024204
#define IM_DI_INTRA_POST_PROCESS_inst_addr                            "0x0081"
#define IM_DI_INTRA_POST_PROCESS_inst                                 0x0081
#define IM_DI_INTRA_POST_PROCESS_intranewgracorr_enable_shift         (31)
#define IM_DI_INTRA_POST_PROCESS_intranewgracorr_doublecheck_enable_shift  (30)
#define IM_DI_INTRA_POST_PROCESS_intra_lowangle_lpf_enable_shift      (29)
#define IM_DI_INTRA_POST_PROCESS_intra_averagefilter_enable_shift     (28)
#define IM_DI_INTRA_POST_PROCESS_intra_range_correct_interpolation_enable_shift  (27)
#define IM_DI_INTRA_POST_PROCESS_intranewgracorr_transptcenter_thd_shift  (12)
#define IM_DI_INTRA_POST_PROCESS_intra_areacorner_intrarange_correct_enable_shift  (11)
#define IM_DI_INTRA_POST_PROCESS_intra_lowangle_lpf_diffthd_shift     (0)
#define IM_DI_INTRA_POST_PROCESS_intranewgracorr_enable_mask          (0x80000000)
#define IM_DI_INTRA_POST_PROCESS_intranewgracorr_doublecheck_enable_mask  (0x40000000)
#define IM_DI_INTRA_POST_PROCESS_intra_lowangle_lpf_enable_mask       (0x20000000)
#define IM_DI_INTRA_POST_PROCESS_intra_averagefilter_enable_mask      (0x10000000)
#define IM_DI_INTRA_POST_PROCESS_intra_range_correct_interpolation_enable_mask  (0x08000000)
#define IM_DI_INTRA_POST_PROCESS_intranewgracorr_transptcenter_thd_mask  (0x000FF000)
#define IM_DI_INTRA_POST_PROCESS_intra_areacorner_intrarange_correct_enable_mask  (0x00000800)
#define IM_DI_INTRA_POST_PROCESS_intra_lowangle_lpf_diffthd_mask      (0x000003FF)
#define IM_DI_INTRA_POST_PROCESS_intranewgracorr_enable(data)         (0x80000000&((data)<<31))
#define IM_DI_INTRA_POST_PROCESS_intranewgracorr_doublecheck_enable(data)  (0x40000000&((data)<<30))
#define IM_DI_INTRA_POST_PROCESS_intra_lowangle_lpf_enable(data)      (0x20000000&((data)<<29))
#define IM_DI_INTRA_POST_PROCESS_intra_averagefilter_enable(data)     (0x10000000&((data)<<28))
#define IM_DI_INTRA_POST_PROCESS_intra_range_correct_interpolation_enable(data)  (0x08000000&((data)<<27))
#define IM_DI_INTRA_POST_PROCESS_intranewgracorr_transptcenter_thd(data)  (0x000FF000&((data)<<12))
#define IM_DI_INTRA_POST_PROCESS_intra_areacorner_intrarange_correct_enable(data)  (0x00000800&((data)<<11))
#define IM_DI_INTRA_POST_PROCESS_intra_lowangle_lpf_diffthd(data)     (0x000003FF&(data))
#define IM_DI_INTRA_POST_PROCESS_get_intranewgracorr_enable(data)     ((0x80000000&(data))>>31)
#define IM_DI_INTRA_POST_PROCESS_get_intranewgracorr_doublecheck_enable(data)  ((0x40000000&(data))>>30)
#define IM_DI_INTRA_POST_PROCESS_get_intra_lowangle_lpf_enable(data)  ((0x20000000&(data))>>29)
#define IM_DI_INTRA_POST_PROCESS_get_intra_averagefilter_enable(data) ((0x10000000&(data))>>28)
#define IM_DI_INTRA_POST_PROCESS_get_intra_range_correct_interpolation_enable(data)  ((0x08000000&(data))>>27)
#define IM_DI_INTRA_POST_PROCESS_get_intranewgracorr_transptcenter_thd(data)  ((0x000FF000&(data))>>12)
#define IM_DI_INTRA_POST_PROCESS_get_intra_areacorner_intrarange_correct_enable(data)  ((0x00000800&(data))>>11)
#define IM_DI_INTRA_POST_PROCESS_get_intra_lowangle_lpf_diffthd(data) (0x000003FF&(data))


#define IM_DI_BTR_CONTROL                                             0x18024208
#define IM_DI_BTR_CONTROL_reg_addr                                    "0xb8024208"
#define IM_DI_BTR_CONTROL_reg                                         0xb8024208
#define IM_DI_BTR_CONTROL_inst_addr                                   "0x0082"
#define IM_DI_BTR_CONTROL_inst                                        0x0082
#define IM_DI_BTR_CONTROL_btr_hmc_blendchoose_shift                   (26)
#define IM_DI_BTR_CONTROL_btr_blendtemporaldebugmode_shift            (24)
#define IM_DI_BTR_CONTROL_btr_solb_cur1_count_shift                   (20)
#define IM_DI_BTR_CONTROL_btr_solb_cur0_count_shift                   (16)
#define IM_DI_BTR_CONTROL_btr_solb_temporallength_shift               (12)
#define IM_DI_BTR_CONTROL_btr_blendtemporalrecovery_dma_en_shift      (9)
#define IM_DI_BTR_CONTROL_btr_sola_method0_blendtype_shift            (8)
#define IM_DI_BTR_CONTROL_btr_sola_method0_successtime_shift          (5)
#define IM_DI_BTR_CONTROL_btr_sola_method_shift                       (4)
#define IM_DI_BTR_CONTROL_btr_sola_temporallength_shift               (2)
#define IM_DI_BTR_CONTROL_btr_solutiontype_shift                      (1)
#define IM_DI_BTR_CONTROL_btr_blendtemporalrecoveryen_shift           (0)
#define IM_DI_BTR_CONTROL_btr_hmc_blendchoose_mask                    (0x04000000)
#define IM_DI_BTR_CONTROL_btr_blendtemporaldebugmode_mask             (0x03000000)
#define IM_DI_BTR_CONTROL_btr_solb_cur1_count_mask                    (0x00700000)
#define IM_DI_BTR_CONTROL_btr_solb_cur0_count_mask                    (0x00070000)
#define IM_DI_BTR_CONTROL_btr_solb_temporallength_mask                (0x00007000)
#define IM_DI_BTR_CONTROL_btr_blendtemporalrecovery_dma_en_mask       (0x00000200)
#define IM_DI_BTR_CONTROL_btr_sola_method0_blendtype_mask             (0x00000100)
#define IM_DI_BTR_CONTROL_btr_sola_method0_successtime_mask           (0x000000E0)
#define IM_DI_BTR_CONTROL_btr_sola_method_mask                        (0x00000010)
#define IM_DI_BTR_CONTROL_btr_sola_temporallength_mask                (0x0000000C)
#define IM_DI_BTR_CONTROL_btr_solutiontype_mask                       (0x00000002)
#define IM_DI_BTR_CONTROL_btr_blendtemporalrecoveryen_mask            (0x00000001)
#define IM_DI_BTR_CONTROL_btr_hmc_blendchoose(data)                   (0x04000000&((data)<<26))
#define IM_DI_BTR_CONTROL_btr_blendtemporaldebugmode(data)            (0x03000000&((data)<<24))
#define IM_DI_BTR_CONTROL_btr_solb_cur1_count(data)                   (0x00700000&((data)<<20))
#define IM_DI_BTR_CONTROL_btr_solb_cur0_count(data)                   (0x00070000&((data)<<16))
#define IM_DI_BTR_CONTROL_btr_solb_temporallength(data)               (0x00007000&((data)<<12))
#define IM_DI_BTR_CONTROL_btr_blendtemporalrecovery_dma_en(data)      (0x00000200&((data)<<9))
#define IM_DI_BTR_CONTROL_btr_sola_method0_blendtype(data)            (0x00000100&((data)<<8))
#define IM_DI_BTR_CONTROL_btr_sola_method0_successtime(data)          (0x000000E0&((data)<<5))
#define IM_DI_BTR_CONTROL_btr_sola_method(data)                       (0x00000010&((data)<<4))
#define IM_DI_BTR_CONTROL_btr_sola_temporallength(data)               (0x0000000C&((data)<<2))
#define IM_DI_BTR_CONTROL_btr_solutiontype(data)                      (0x00000002&((data)<<1))
#define IM_DI_BTR_CONTROL_btr_blendtemporalrecoveryen(data)           (0x00000001&(data))
#define IM_DI_BTR_CONTROL_get_btr_hmc_blendchoose(data)               ((0x04000000&(data))>>26)
#define IM_DI_BTR_CONTROL_get_btr_blendtemporaldebugmode(data)        ((0x03000000&(data))>>24)
#define IM_DI_BTR_CONTROL_get_btr_solb_cur1_count(data)               ((0x00700000&(data))>>20)
#define IM_DI_BTR_CONTROL_get_btr_solb_cur0_count(data)               ((0x00070000&(data))>>16)
#define IM_DI_BTR_CONTROL_get_btr_solb_temporallength(data)           ((0x00007000&(data))>>12)
#define IM_DI_BTR_CONTROL_get_btr_blendtemporalrecovery_dma_en(data)  ((0x00000200&(data))>>9)
#define IM_DI_BTR_CONTROL_get_btr_sola_method0_blendtype(data)        ((0x00000100&(data))>>8)
#define IM_DI_BTR_CONTROL_get_btr_sola_method0_successtime(data)      ((0x000000E0&(data))>>5)
#define IM_DI_BTR_CONTROL_get_btr_sola_method(data)                   ((0x00000010&(data))>>4)
#define IM_DI_BTR_CONTROL_get_btr_sola_temporallength(data)           ((0x0000000C&(data))>>2)
#define IM_DI_BTR_CONTROL_get_btr_solutiontype(data)                  ((0x00000002&(data))>>1)
#define IM_DI_BTR_CONTROL_get_btr_blendtemporalrecoveryen(data)       (0x00000001&(data))


#define IM_DI_BTR_SOLA_METHOD0_MIN_MAX                                0x1802420c
#define IM_DI_BTR_SOLA_METHOD0_MIN_MAX_reg_addr                       "0xb802420c"
#define IM_DI_BTR_SOLA_METHOD0_MIN_MAX_reg                            0xb802420c
#define IM_DI_BTR_SOLA_METHOD0_MIN_MAX_inst_addr                      "0x0083"
#define IM_DI_BTR_SOLA_METHOD0_MIN_MAX_inst                           0x0083
#define IM_DI_BTR_SOLA_METHOD0_MIN_MAX_btr_sola_method0_cur1_pre4_max_shift  (30)
#define IM_DI_BTR_SOLA_METHOD0_MIN_MAX_btr_sola_method0_cur1_pre4_min_shift  (28)
#define IM_DI_BTR_SOLA_METHOD0_MIN_MAX_btr_sola_method0_cur1_pre3_max_shift  (26)
#define IM_DI_BTR_SOLA_METHOD0_MIN_MAX_btr_sola_method0_cur1_pre3_min_shift  (24)
#define IM_DI_BTR_SOLA_METHOD0_MIN_MAX_btr_sola_method0_cur1_pre2_max_shift  (22)
#define IM_DI_BTR_SOLA_METHOD0_MIN_MAX_btr_sola_method0_cur1_pre2_min_shift  (20)
#define IM_DI_BTR_SOLA_METHOD0_MIN_MAX_btr_sola_method0_cur1_pre1_max_shift  (18)
#define IM_DI_BTR_SOLA_METHOD0_MIN_MAX_btr_sola_method0_cur1_pre1_min_shift  (16)
#define IM_DI_BTR_SOLA_METHOD0_MIN_MAX_btr_sola_method0_cur0_pre4_max_shift  (14)
#define IM_DI_BTR_SOLA_METHOD0_MIN_MAX_btr_sola_method0_cur0_pre4_min_shift  (12)
#define IM_DI_BTR_SOLA_METHOD0_MIN_MAX_btr_sola_method0_cur0_pre3_max_shift  (10)
#define IM_DI_BTR_SOLA_METHOD0_MIN_MAX_btr_sola_method0_cur0_pre3_min_shift  (8)
#define IM_DI_BTR_SOLA_METHOD0_MIN_MAX_btr_sola_method0_cur0_pre2_max_shift  (6)
#define IM_DI_BTR_SOLA_METHOD0_MIN_MAX_btr_sola_method0_cur0_pre2_min_shift  (4)
#define IM_DI_BTR_SOLA_METHOD0_MIN_MAX_btr_sola_method0_cur0_pre1_max_shift  (2)
#define IM_DI_BTR_SOLA_METHOD0_MIN_MAX_btr_sola_method0_cur0_pre1_min_shift  (0)
#define IM_DI_BTR_SOLA_METHOD0_MIN_MAX_btr_sola_method0_cur1_pre4_max_mask  (0xC0000000)
#define IM_DI_BTR_SOLA_METHOD0_MIN_MAX_btr_sola_method0_cur1_pre4_min_mask  (0x30000000)
#define IM_DI_BTR_SOLA_METHOD0_MIN_MAX_btr_sola_method0_cur1_pre3_max_mask  (0x0C000000)
#define IM_DI_BTR_SOLA_METHOD0_MIN_MAX_btr_sola_method0_cur1_pre3_min_mask  (0x03000000)
#define IM_DI_BTR_SOLA_METHOD0_MIN_MAX_btr_sola_method0_cur1_pre2_max_mask  (0x00C00000)
#define IM_DI_BTR_SOLA_METHOD0_MIN_MAX_btr_sola_method0_cur1_pre2_min_mask  (0x00300000)
#define IM_DI_BTR_SOLA_METHOD0_MIN_MAX_btr_sola_method0_cur1_pre1_max_mask  (0x000C0000)
#define IM_DI_BTR_SOLA_METHOD0_MIN_MAX_btr_sola_method0_cur1_pre1_min_mask  (0x00030000)
#define IM_DI_BTR_SOLA_METHOD0_MIN_MAX_btr_sola_method0_cur0_pre4_max_mask  (0x0000C000)
#define IM_DI_BTR_SOLA_METHOD0_MIN_MAX_btr_sola_method0_cur0_pre4_min_mask  (0x00003000)
#define IM_DI_BTR_SOLA_METHOD0_MIN_MAX_btr_sola_method0_cur0_pre3_max_mask  (0x00000C00)
#define IM_DI_BTR_SOLA_METHOD0_MIN_MAX_btr_sola_method0_cur0_pre3_min_mask  (0x00000300)
#define IM_DI_BTR_SOLA_METHOD0_MIN_MAX_btr_sola_method0_cur0_pre2_max_mask  (0x000000C0)
#define IM_DI_BTR_SOLA_METHOD0_MIN_MAX_btr_sola_method0_cur0_pre2_min_mask  (0x00000030)
#define IM_DI_BTR_SOLA_METHOD0_MIN_MAX_btr_sola_method0_cur0_pre1_max_mask  (0x0000000C)
#define IM_DI_BTR_SOLA_METHOD0_MIN_MAX_btr_sola_method0_cur0_pre1_min_mask  (0x00000003)
#define IM_DI_BTR_SOLA_METHOD0_MIN_MAX_btr_sola_method0_cur1_pre4_max(data)  (0xC0000000&((data)<<30))
#define IM_DI_BTR_SOLA_METHOD0_MIN_MAX_btr_sola_method0_cur1_pre4_min(data)  (0x30000000&((data)<<28))
#define IM_DI_BTR_SOLA_METHOD0_MIN_MAX_btr_sola_method0_cur1_pre3_max(data)  (0x0C000000&((data)<<26))
#define IM_DI_BTR_SOLA_METHOD0_MIN_MAX_btr_sola_method0_cur1_pre3_min(data)  (0x03000000&((data)<<24))
#define IM_DI_BTR_SOLA_METHOD0_MIN_MAX_btr_sola_method0_cur1_pre2_max(data)  (0x00C00000&((data)<<22))
#define IM_DI_BTR_SOLA_METHOD0_MIN_MAX_btr_sola_method0_cur1_pre2_min(data)  (0x00300000&((data)<<20))
#define IM_DI_BTR_SOLA_METHOD0_MIN_MAX_btr_sola_method0_cur1_pre1_max(data)  (0x000C0000&((data)<<18))
#define IM_DI_BTR_SOLA_METHOD0_MIN_MAX_btr_sola_method0_cur1_pre1_min(data)  (0x00030000&((data)<<16))
#define IM_DI_BTR_SOLA_METHOD0_MIN_MAX_btr_sola_method0_cur0_pre4_max(data)  (0x0000C000&((data)<<14))
#define IM_DI_BTR_SOLA_METHOD0_MIN_MAX_btr_sola_method0_cur0_pre4_min(data)  (0x00003000&((data)<<12))
#define IM_DI_BTR_SOLA_METHOD0_MIN_MAX_btr_sola_method0_cur0_pre3_max(data)  (0x00000C00&((data)<<10))
#define IM_DI_BTR_SOLA_METHOD0_MIN_MAX_btr_sola_method0_cur0_pre3_min(data)  (0x00000300&((data)<<8))
#define IM_DI_BTR_SOLA_METHOD0_MIN_MAX_btr_sola_method0_cur0_pre2_max(data)  (0x000000C0&((data)<<6))
#define IM_DI_BTR_SOLA_METHOD0_MIN_MAX_btr_sola_method0_cur0_pre2_min(data)  (0x00000030&((data)<<4))
#define IM_DI_BTR_SOLA_METHOD0_MIN_MAX_btr_sola_method0_cur0_pre1_max(data)  (0x0000000C&((data)<<2))
#define IM_DI_BTR_SOLA_METHOD0_MIN_MAX_btr_sola_method0_cur0_pre1_min(data)  (0x00000003&(data))
#define IM_DI_BTR_SOLA_METHOD0_MIN_MAX_get_btr_sola_method0_cur1_pre4_max(data)  ((0xC0000000&(data))>>30)
#define IM_DI_BTR_SOLA_METHOD0_MIN_MAX_get_btr_sola_method0_cur1_pre4_min(data)  ((0x30000000&(data))>>28)
#define IM_DI_BTR_SOLA_METHOD0_MIN_MAX_get_btr_sola_method0_cur1_pre3_max(data)  ((0x0C000000&(data))>>26)
#define IM_DI_BTR_SOLA_METHOD0_MIN_MAX_get_btr_sola_method0_cur1_pre3_min(data)  ((0x03000000&(data))>>24)
#define IM_DI_BTR_SOLA_METHOD0_MIN_MAX_get_btr_sola_method0_cur1_pre2_max(data)  ((0x00C00000&(data))>>22)
#define IM_DI_BTR_SOLA_METHOD0_MIN_MAX_get_btr_sola_method0_cur1_pre2_min(data)  ((0x00300000&(data))>>20)
#define IM_DI_BTR_SOLA_METHOD0_MIN_MAX_get_btr_sola_method0_cur1_pre1_max(data)  ((0x000C0000&(data))>>18)
#define IM_DI_BTR_SOLA_METHOD0_MIN_MAX_get_btr_sola_method0_cur1_pre1_min(data)  ((0x00030000&(data))>>16)
#define IM_DI_BTR_SOLA_METHOD0_MIN_MAX_get_btr_sola_method0_cur0_pre4_max(data)  ((0x0000C000&(data))>>14)
#define IM_DI_BTR_SOLA_METHOD0_MIN_MAX_get_btr_sola_method0_cur0_pre4_min(data)  ((0x00003000&(data))>>12)
#define IM_DI_BTR_SOLA_METHOD0_MIN_MAX_get_btr_sola_method0_cur0_pre3_max(data)  ((0x00000C00&(data))>>10)
#define IM_DI_BTR_SOLA_METHOD0_MIN_MAX_get_btr_sola_method0_cur0_pre3_min(data)  ((0x00000300&(data))>>8)
#define IM_DI_BTR_SOLA_METHOD0_MIN_MAX_get_btr_sola_method0_cur0_pre2_max(data)  ((0x000000C0&(data))>>6)
#define IM_DI_BTR_SOLA_METHOD0_MIN_MAX_get_btr_sola_method0_cur0_pre2_min(data)  ((0x00000030&(data))>>4)
#define IM_DI_BTR_SOLA_METHOD0_MIN_MAX_get_btr_sola_method0_cur0_pre1_max(data)  ((0x0000000C&(data))>>2)
#define IM_DI_BTR_SOLA_METHOD0_MIN_MAX_get_btr_sola_method0_cur0_pre1_min(data)  (0x00000003&(data))


#define IM_DI_BTR_LONGWEAVE_STATISTIC                                 0x18024210
#define IM_DI_BTR_LONGWEAVE_STATISTIC_reg_addr                        "0xb8024210"
#define IM_DI_BTR_LONGWEAVE_STATISTIC_reg                             0xb8024210
#define IM_DI_BTR_LONGWEAVE_STATISTIC_inst_addr                       "0x0084"
#define IM_DI_BTR_LONGWEAVE_STATISTIC_inst                            0x0084
#define IM_DI_BTR_LONGWEAVE_STATISTIC_intra_areacorner_intrarange_correct_peak_thd_shift  (24)
#define IM_DI_BTR_LONGWEAVE_STATISTIC_btr_longweavesum_shift          (0)
#define IM_DI_BTR_LONGWEAVE_STATISTIC_intra_areacorner_intrarange_correct_peak_thd_mask  (0xFF000000)
#define IM_DI_BTR_LONGWEAVE_STATISTIC_btr_longweavesum_mask           (0x00FFFFFF)
#define IM_DI_BTR_LONGWEAVE_STATISTIC_intra_areacorner_intrarange_correct_peak_thd(data)  (0xFF000000&((data)<<24))
#define IM_DI_BTR_LONGWEAVE_STATISTIC_btr_longweavesum(data)          (0x00FFFFFF&(data))
#define IM_DI_BTR_LONGWEAVE_STATISTIC_get_intra_areacorner_intrarange_correct_peak_thd(data)  ((0xFF000000&(data))>>24)
#define IM_DI_BTR_LONGWEAVE_STATISTIC_get_btr_longweavesum(data)      (0x00FFFFFF&(data))


#define IM_DI_BER_LOWPASS_STATISTIC                                   0x18024214
#define IM_DI_BER_LOWPASS_STATISTIC_reg_addr                          "0xb8024214"
#define IM_DI_BER_LOWPASS_STATISTIC_reg                               0xb8024214
#define IM_DI_BER_LOWPASS_STATISTIC_inst_addr                         "0x0085"
#define IM_DI_BER_LOWPASS_STATISTIC_inst                              0x0085
#define IM_DI_BER_LOWPASS_STATISTIC_ber_lowpasssum_shift              (0)
#define IM_DI_BER_LOWPASS_STATISTIC_ber_lowpasssum_mask               (0x00FFFFFF)
#define IM_DI_BER_LOWPASS_STATISTIC_ber_lowpasssum(data)              (0x00FFFFFF&(data))
#define IM_DI_BER_LOWPASS_STATISTIC_get_ber_lowpasssum(data)          (0x00FFFFFF&(data))


#define IM_DI_BER_SPATIAL_CONTROL                                     0x18024218
#define IM_DI_BER_SPATIAL_CONTROL_reg_addr                            "0xb8024218"
#define IM_DI_BER_SPATIAL_CONTROL_reg                                 0xb8024218
#define IM_DI_BER_SPATIAL_CONTROL_inst_addr                           "0x0086"
#define IM_DI_BER_SPATIAL_CONTROL_inst                                0x0086
#define IM_DI_BER_SPATIAL_CONTROL_ber_closeclevel_max_shift           (16)
#define IM_DI_BER_SPATIAL_CONTROL_ber_closeclevel_min_shift           (4)
#define IM_DI_BER_SPATIAL_CONTROL_ber_blendspatial_lpf_blendingtype_shift  (3)
#define IM_DI_BER_SPATIAL_CONTROL_ber_blendspatial_lpf_stilllogo_shift  (2)
#define IM_DI_BER_SPATIAL_CONTROL_ber_blendspatialclassify_shift      (1)
#define IM_DI_BER_SPATIAL_CONTROL_ber_blendspatialrecoveryen_shift    (0)
#define IM_DI_BER_SPATIAL_CONTROL_ber_closeclevel_max_mask            (0x00FF0000)
#define IM_DI_BER_SPATIAL_CONTROL_ber_closeclevel_min_mask            (0x00000FF0)
#define IM_DI_BER_SPATIAL_CONTROL_ber_blendspatial_lpf_blendingtype_mask  (0x00000008)
#define IM_DI_BER_SPATIAL_CONTROL_ber_blendspatial_lpf_stilllogo_mask (0x00000004)
#define IM_DI_BER_SPATIAL_CONTROL_ber_blendspatialclassify_mask       (0x00000002)
#define IM_DI_BER_SPATIAL_CONTROL_ber_blendspatialrecoveryen_mask     (0x00000001)
#define IM_DI_BER_SPATIAL_CONTROL_ber_closeclevel_max(data)           (0x00FF0000&((data)<<16))
#define IM_DI_BER_SPATIAL_CONTROL_ber_closeclevel_min(data)           (0x00000FF0&((data)<<4))
#define IM_DI_BER_SPATIAL_CONTROL_ber_blendspatial_lpf_blendingtype(data)  (0x00000008&((data)<<3))
#define IM_DI_BER_SPATIAL_CONTROL_ber_blendspatial_lpf_stilllogo(data)  (0x00000004&((data)<<2))
#define IM_DI_BER_SPATIAL_CONTROL_ber_blendspatialclassify(data)      (0x00000002&((data)<<1))
#define IM_DI_BER_SPATIAL_CONTROL_ber_blendspatialrecoveryen(data)    (0x00000001&(data))
#define IM_DI_BER_SPATIAL_CONTROL_get_ber_closeclevel_max(data)       ((0x00FF0000&(data))>>16)
#define IM_DI_BER_SPATIAL_CONTROL_get_ber_closeclevel_min(data)       ((0x00000FF0&(data))>>4)
#define IM_DI_BER_SPATIAL_CONTROL_get_ber_blendspatial_lpf_blendingtype(data)  ((0x00000008&(data))>>3)
#define IM_DI_BER_SPATIAL_CONTROL_get_ber_blendspatial_lpf_stilllogo(data)  ((0x00000004&(data))>>2)
#define IM_DI_BER_SPATIAL_CONTROL_get_ber_blendspatialclassify(data)  ((0x00000002&(data))>>1)
#define IM_DI_BER_SPATIAL_CONTROL_get_ber_blendspatialrecoveryen(data)  (0x00000001&(data))


#define IM_DI_BER_SPATIAL_DIFFY                                       0x1802421c
#define IM_DI_BER_SPATIAL_DIFFY_reg_addr                              "0xb802421c"
#define IM_DI_BER_SPATIAL_DIFFY_reg                                   0xb802421c
#define IM_DI_BER_SPATIAL_DIFFY_inst_addr                             "0x0087"
#define IM_DI_BER_SPATIAL_DIFFY_inst                                  0x0087
#define IM_DI_BER_SPATIAL_DIFFY_ber_diffylevel_max_shift              (16)
#define IM_DI_BER_SPATIAL_DIFFY_ber_diffylevel_min_shift              (0)
#define IM_DI_BER_SPATIAL_DIFFY_ber_diffylevel_max_mask               (0x03FF0000)
#define IM_DI_BER_SPATIAL_DIFFY_ber_diffylevel_min_mask               (0x000003FF)
#define IM_DI_BER_SPATIAL_DIFFY_ber_diffylevel_max(data)              (0x03FF0000&((data)<<16))
#define IM_DI_BER_SPATIAL_DIFFY_ber_diffylevel_min(data)              (0x000003FF&(data))
#define IM_DI_BER_SPATIAL_DIFFY_get_ber_diffylevel_max(data)          ((0x03FF0000&(data))>>16)
#define IM_DI_BER_SPATIAL_DIFFY_get_ber_diffylevel_min(data)          (0x000003FF&(data))


#define IM_DI_BER_TEMPORAL_CONTROL                                    0x18024220
#define IM_DI_BER_TEMPORAL_CONTROL_reg_addr                           "0xb8024220"
#define IM_DI_BER_TEMPORAL_CONTROL_reg                                0xb8024220
#define IM_DI_BER_TEMPORAL_CONTROL_inst_addr                          "0x0088"
#define IM_DI_BER_TEMPORAL_CONTROL_inst                               0x0088
#define IM_DI_BER_TEMPORAL_CONTROL_ber_totalcontinuesum_shift         (8)
#define IM_DI_BER_TEMPORAL_CONTROL_ber_spatialcontinuelength_shift    (4)
#define IM_DI_BER_TEMPORAL_CONTROL_ber_blendtemporaltype_shift        (3)
#define IM_DI_BER_TEMPORAL_CONTROL_ber_blendtemporalblock_shift       (1)
#define IM_DI_BER_TEMPORAL_CONTROL_ber_blendtemporalrevoeryen_shift   (0)
#define IM_DI_BER_TEMPORAL_CONTROL_ber_totalcontinuesum_mask          (0xFFFFFF00)
#define IM_DI_BER_TEMPORAL_CONTROL_ber_spatialcontinuelength_mask     (0x000000F0)
#define IM_DI_BER_TEMPORAL_CONTROL_ber_blendtemporaltype_mask         (0x00000008)
#define IM_DI_BER_TEMPORAL_CONTROL_ber_blendtemporalblock_mask        (0x00000006)
#define IM_DI_BER_TEMPORAL_CONTROL_ber_blendtemporalrevoeryen_mask    (0x00000001)
#define IM_DI_BER_TEMPORAL_CONTROL_ber_totalcontinuesum(data)         (0xFFFFFF00&((data)<<8))
#define IM_DI_BER_TEMPORAL_CONTROL_ber_spatialcontinuelength(data)    (0x000000F0&((data)<<4))
#define IM_DI_BER_TEMPORAL_CONTROL_ber_blendtemporaltype(data)        (0x00000008&((data)<<3))
#define IM_DI_BER_TEMPORAL_CONTROL_ber_blendtemporalblock(data)       (0x00000006&((data)<<1))
#define IM_DI_BER_TEMPORAL_CONTROL_ber_blendtemporalrevoeryen(data)   (0x00000001&(data))
#define IM_DI_BER_TEMPORAL_CONTROL_get_ber_totalcontinuesum(data)     ((0xFFFFFF00&(data))>>8)
#define IM_DI_BER_TEMPORAL_CONTROL_get_ber_spatialcontinuelength(data)  ((0x000000F0&(data))>>4)
#define IM_DI_BER_TEMPORAL_CONTROL_get_ber_blendtemporaltype(data)    ((0x00000008&(data))>>3)
#define IM_DI_BER_TEMPORAL_CONTROL_get_ber_blendtemporalblock(data)   ((0x00000006&(data))>>1)
#define IM_DI_BER_TEMPORAL_CONTROL_get_ber_blendtemporalrevoeryen(data)  (0x00000001&(data))


#define IM_DI_INTRA_L_CROSS_PAT_DET_TH1                               0x18024224
#define IM_DI_INTRA_L_CROSS_PAT_DET_TH1_reg_addr                      "0xb8024224"
#define IM_DI_INTRA_L_CROSS_PAT_DET_TH1_reg                           0xb8024224
#define IM_DI_INTRA_L_CROSS_PAT_DET_TH1_inst_addr                     "0x0089"
#define IM_DI_INTRA_L_CROSS_PAT_DET_TH1_inst                          0x0089
#define IM_DI_INTRA_L_CROSS_PAT_DET_TH1_intra_lpattern_flat_rldiff_th_shift  (24)
#define IM_DI_INTRA_L_CROSS_PAT_DET_TH1_intra_lpattern_flat_cendiff_th_shift  (16)
#define IM_DI_INTRA_L_CROSS_PAT_DET_TH1_intra_lpattern_flat_wholediff_th_shift  (8)
#define IM_DI_INTRA_L_CROSS_PAT_DET_TH1_intra_lpattern_rough_diff_th_shift  (0)
#define IM_DI_INTRA_L_CROSS_PAT_DET_TH1_intra_lpattern_flat_rldiff_th_mask  (0xFF000000)
#define IM_DI_INTRA_L_CROSS_PAT_DET_TH1_intra_lpattern_flat_cendiff_th_mask  (0x00FF0000)
#define IM_DI_INTRA_L_CROSS_PAT_DET_TH1_intra_lpattern_flat_wholediff_th_mask  (0x0000FF00)
#define IM_DI_INTRA_L_CROSS_PAT_DET_TH1_intra_lpattern_rough_diff_th_mask  (0x000000FF)
#define IM_DI_INTRA_L_CROSS_PAT_DET_TH1_intra_lpattern_flat_rldiff_th(data)  (0xFF000000&((data)<<24))
#define IM_DI_INTRA_L_CROSS_PAT_DET_TH1_intra_lpattern_flat_cendiff_th(data)  (0x00FF0000&((data)<<16))
#define IM_DI_INTRA_L_CROSS_PAT_DET_TH1_intra_lpattern_flat_wholediff_th(data)  (0x0000FF00&((data)<<8))
#define IM_DI_INTRA_L_CROSS_PAT_DET_TH1_intra_lpattern_rough_diff_th(data)  (0x000000FF&(data))
#define IM_DI_INTRA_L_CROSS_PAT_DET_TH1_get_intra_lpattern_flat_rldiff_th(data)  ((0xFF000000&(data))>>24)
#define IM_DI_INTRA_L_CROSS_PAT_DET_TH1_get_intra_lpattern_flat_cendiff_th(data)  ((0x00FF0000&(data))>>16)
#define IM_DI_INTRA_L_CROSS_PAT_DET_TH1_get_intra_lpattern_flat_wholediff_th(data)  ((0x0000FF00&(data))>>8)
#define IM_DI_INTRA_L_CROSS_PAT_DET_TH1_get_intra_lpattern_rough_diff_th(data)  (0x000000FF&(data))


#define IM_DI_INTRA_L_CROSS_PAT_DET_TH2                               0x18024228
#define IM_DI_INTRA_L_CROSS_PAT_DET_TH2_reg_addr                      "0xb8024228"
#define IM_DI_INTRA_L_CROSS_PAT_DET_TH2_reg                           0xb8024228
#define IM_DI_INTRA_L_CROSS_PAT_DET_TH2_inst_addr                     "0x008A"
#define IM_DI_INTRA_L_CROSS_PAT_DET_TH2_inst                          0x008A
#define IM_DI_INTRA_L_CROSS_PAT_DET_TH2_intra_lpattern_rough_flat_diff_th_shift  (24)
#define IM_DI_INTRA_L_CROSS_PAT_DET_TH2_intra_lpattern_vdiff_th_shift (16)
#define IM_DI_INTRA_L_CROSS_PAT_DET_TH2_intra_lpattern_vdev_lowbound_th_shift  (8)
#define IM_DI_INTRA_L_CROSS_PAT_DET_TH2_intra_lpattern_vdev_highbound_th_shift  (0)
#define IM_DI_INTRA_L_CROSS_PAT_DET_TH2_intra_lpattern_rough_flat_diff_th_mask  (0xFF000000)
#define IM_DI_INTRA_L_CROSS_PAT_DET_TH2_intra_lpattern_vdiff_th_mask  (0x00FF0000)
#define IM_DI_INTRA_L_CROSS_PAT_DET_TH2_intra_lpattern_vdev_lowbound_th_mask  (0x0000FF00)
#define IM_DI_INTRA_L_CROSS_PAT_DET_TH2_intra_lpattern_vdev_highbound_th_mask  (0x000000FF)
#define IM_DI_INTRA_L_CROSS_PAT_DET_TH2_intra_lpattern_rough_flat_diff_th(data)  (0xFF000000&((data)<<24))
#define IM_DI_INTRA_L_CROSS_PAT_DET_TH2_intra_lpattern_vdiff_th(data) (0x00FF0000&((data)<<16))
#define IM_DI_INTRA_L_CROSS_PAT_DET_TH2_intra_lpattern_vdev_lowbound_th(data)  (0x0000FF00&((data)<<8))
#define IM_DI_INTRA_L_CROSS_PAT_DET_TH2_intra_lpattern_vdev_highbound_th(data)  (0x000000FF&(data))
#define IM_DI_INTRA_L_CROSS_PAT_DET_TH2_get_intra_lpattern_rough_flat_diff_th(data)  ((0xFF000000&(data))>>24)
#define IM_DI_INTRA_L_CROSS_PAT_DET_TH2_get_intra_lpattern_vdiff_th(data)  ((0x00FF0000&(data))>>16)
#define IM_DI_INTRA_L_CROSS_PAT_DET_TH2_get_intra_lpattern_vdev_lowbound_th(data)  ((0x0000FF00&(data))>>8)
#define IM_DI_INTRA_L_CROSS_PAT_DET_TH2_get_intra_lpattern_vdev_highbound_th(data)  (0x000000FF&(data))


#define IM_DI_INTRA_L_CROSS_PAT_DET_CTL                               0x1802422c
#define IM_DI_INTRA_L_CROSS_PAT_DET_CTL_reg_addr                      "0xb802422c"
#define IM_DI_INTRA_L_CROSS_PAT_DET_CTL_reg                           0xb802422c
#define IM_DI_INTRA_L_CROSS_PAT_DET_CTL_inst_addr                     "0x008B"
#define IM_DI_INTRA_L_CROSS_PAT_DET_CTL_inst                          0x008B
#define IM_DI_INTRA_L_CROSS_PAT_DET_CTL_intra_lpattern_cen_pixdiff_th_shift  (24)
#define IM_DI_INTRA_L_CROSS_PAT_DET_CTL_intra_lpattern_dir_pk_enable_shift  (4)
#define IM_DI_INTRA_L_CROSS_PAT_DET_CTL_intra_lpattern_rough_ratio_shift  (1)
#define IM_DI_INTRA_L_CROSS_PAT_DET_CTL_intra_lpattern_enable_shift   (0)
#define IM_DI_INTRA_L_CROSS_PAT_DET_CTL_intra_lpattern_cen_pixdiff_th_mask  (0xFF000000)
#define IM_DI_INTRA_L_CROSS_PAT_DET_CTL_intra_lpattern_dir_pk_enable_mask  (0x00000010)
#define IM_DI_INTRA_L_CROSS_PAT_DET_CTL_intra_lpattern_rough_ratio_mask  (0x0000000E)
#define IM_DI_INTRA_L_CROSS_PAT_DET_CTL_intra_lpattern_enable_mask    (0x00000001)
#define IM_DI_INTRA_L_CROSS_PAT_DET_CTL_intra_lpattern_cen_pixdiff_th(data)  (0xFF000000&((data)<<24))
#define IM_DI_INTRA_L_CROSS_PAT_DET_CTL_intra_lpattern_dir_pk_enable(data)  (0x00000010&((data)<<4))
#define IM_DI_INTRA_L_CROSS_PAT_DET_CTL_intra_lpattern_rough_ratio(data)  (0x0000000E&((data)<<1))
#define IM_DI_INTRA_L_CROSS_PAT_DET_CTL_intra_lpattern_enable(data)   (0x00000001&(data))
#define IM_DI_INTRA_L_CROSS_PAT_DET_CTL_get_intra_lpattern_cen_pixdiff_th(data)  ((0xFF000000&(data))>>24)
#define IM_DI_INTRA_L_CROSS_PAT_DET_CTL_get_intra_lpattern_dir_pk_enable(data)  ((0x00000010&(data))>>4)
#define IM_DI_INTRA_L_CROSS_PAT_DET_CTL_get_intra_lpattern_rough_ratio(data)  ((0x0000000E&(data))>>1)
#define IM_DI_INTRA_L_CROSS_PAT_DET_CTL_get_intra_lpattern_enable(data)  (0x00000001&(data))


#define NOISEEST_HOR_RANGE                                            0x18024230
#define NOISEEST_HOR_RANGE_reg_addr                                   "0xb8024230"
#define NOISEEST_HOR_RANGE_reg                                        0xb8024230
#define NOISEEST_HOR_RANGE_inst_addr                                  "0x008C"
#define NOISEEST_HOR_RANGE_inst                                       0x008C
#define NOISEEST_HOR_RANGE_cp_noiseesthorend_shift                    (16)
#define NOISEEST_HOR_RANGE_cp_noiseesthorstart_shift                  (0)
#define NOISEEST_HOR_RANGE_cp_noiseesthorend_mask                     (0x0FFF0000)
#define NOISEEST_HOR_RANGE_cp_noiseesthorstart_mask                   (0x00000FFF)
#define NOISEEST_HOR_RANGE_cp_noiseesthorend(data)                    (0x0FFF0000&((data)<<16))
#define NOISEEST_HOR_RANGE_cp_noiseesthorstart(data)                  (0x00000FFF&(data))
#define NOISEEST_HOR_RANGE_get_cp_noiseesthorend(data)                ((0x0FFF0000&(data))>>16)
#define NOISEEST_HOR_RANGE_get_cp_noiseesthorstart(data)              (0x00000FFF&(data))


#define NOISEEST_VER_RANGE                                            0x18024234
#define NOISEEST_VER_RANGE_reg_addr                                   "0xb8024234"
#define NOISEEST_VER_RANGE_reg                                        0xb8024234
#define NOISEEST_VER_RANGE_inst_addr                                  "0x008D"
#define NOISEEST_VER_RANGE_inst                                       0x008D
#define NOISEEST_VER_RANGE_cp_noiseestverend_shift                    (16)
#define NOISEEST_VER_RANGE_cp_noiseestverstart_shift                  (0)
#define NOISEEST_VER_RANGE_cp_noiseestverend_mask                     (0x0FFF0000)
#define NOISEEST_VER_RANGE_cp_noiseestverstart_mask                   (0x00000FFF)
#define NOISEEST_VER_RANGE_cp_noiseestverend(data)                    (0x0FFF0000&((data)<<16))
#define NOISEEST_VER_RANGE_cp_noiseestverstart(data)                  (0x00000FFF&(data))
#define NOISEEST_VER_RANGE_get_cp_noiseestverend(data)                ((0x0FFF0000&(data))>>16)
#define NOISEEST_VER_RANGE_get_cp_noiseestverstart(data)              (0x00000FFF&(data))


#define IM_DI_DUMMY_3                                                 0x18024238
#define IM_DI_DUMMY_3_reg_addr                                        "0xb8024238"
#define IM_DI_DUMMY_3_reg                                             0xb8024238
#define IM_DI_DUMMY_3_inst_addr                                       "0x008E"
#define IM_DI_DUMMY_3_inst                                            0x008E


#define IM_DI_DUMMY_4                                                 0x1802423c
#define IM_DI_DUMMY_4_reg_addr                                        "0xb802423c"
#define IM_DI_DUMMY_4_reg                                             0xb802423c
#define IM_DI_DUMMY_4_inst_addr                                       "0x008F"
#define IM_DI_DUMMY_4_inst                                            0x008F
#define IM_DI_DUMMY_4_dummy1802423c_31_0_shift                        (0)
#define IM_DI_DUMMY_4_dummy1802423c_31_0_mask                         (0xFFFFFFFF)
#define IM_DI_DUMMY_4_dummy1802423c_31_0(data)                        (0xFFFFFFFF&(data))
#define IM_DI_DUMMY_4_get_dummy1802423c_31_0(data)                    (0xFFFFFFFF&(data))


#define MPEG_HIST_BLKING                                              0x18024240
#define MPEG_HIST_BLKING_reg_addr                                     "0xb8024240"
#define MPEG_HIST_BLKING_reg                                          0xb8024240
#define MPEG_HIST_BLKING_inst_addr                                    "0x0090"
#define MPEG_HIST_BLKING_inst                                         0x0090
#define MPEG_HIST_BLKING_cp_histthl1_shift                            (24)
#define MPEG_HIST_BLKING_cp_histthl2_shift                            (16)
#define MPEG_HIST_BLKING_subsamplingmode_shift                        (12)
#define MPEG_HIST_BLKING_cp_histhoroffset_shift                       (8)
#define MPEG_HIST_BLKING_cp_histveroffset_shift                       (4)
#define MPEG_HIST_BLKING_cp_histveren_shift                           (0)
#define MPEG_HIST_BLKING_cp_histthl1_mask                             (0xFF000000)
#define MPEG_HIST_BLKING_cp_histthl2_mask                             (0x00FF0000)
#define MPEG_HIST_BLKING_subsamplingmode_mask                         (0x00003000)
#define MPEG_HIST_BLKING_cp_histhoroffset_mask                        (0x00000700)
#define MPEG_HIST_BLKING_cp_histveroffset_mask                        (0x00000070)
#define MPEG_HIST_BLKING_cp_histveren_mask                            (0x00000001)
#define MPEG_HIST_BLKING_cp_histthl1(data)                            (0xFF000000&((data)<<24))
#define MPEG_HIST_BLKING_cp_histthl2(data)                            (0x00FF0000&((data)<<16))
#define MPEG_HIST_BLKING_subsamplingmode(data)                        (0x00003000&((data)<<12))
#define MPEG_HIST_BLKING_cp_histhoroffset(data)                       (0x00000700&((data)<<8))
#define MPEG_HIST_BLKING_cp_histveroffset(data)                       (0x00000070&((data)<<4))
#define MPEG_HIST_BLKING_cp_histveren(data)                           (0x00000001&(data))
#define MPEG_HIST_BLKING_get_cp_histthl1(data)                        ((0xFF000000&(data))>>24)
#define MPEG_HIST_BLKING_get_cp_histthl2(data)                        ((0x00FF0000&(data))>>16)
#define MPEG_HIST_BLKING_get_subsamplingmode(data)                    ((0x00003000&(data))>>12)
#define MPEG_HIST_BLKING_get_cp_histhoroffset(data)                   ((0x00000700&(data))>>8)
#define MPEG_HIST_BLKING_get_cp_histveroffset(data)                   ((0x00000070&(data))>>4)
#define MPEG_HIST_BLKING_get_cp_histveren(data)                       (0x00000001&(data))


#define CNTVER0                                                       0x18024244
#define CNTVER0_reg_addr                                              "0xb8024244"
#define CNTVER0_reg                                                   0xb8024244
#define CNTVER0_inst_addr                                             "0x0091"
#define CNTVER0_inst                                                  0x0091
#define CNTVER0_cp_cntver1_shift                                      (16)
#define CNTVER0_cp_cntver0_shift                                      (0)
#define CNTVER0_cp_cntver1_mask                                       (0x0FFF0000)
#define CNTVER0_cp_cntver0_mask                                       (0x00000FFF)
#define CNTVER0_cp_cntver1(data)                                      (0x0FFF0000&((data)<<16))
#define CNTVER0_cp_cntver0(data)                                      (0x00000FFF&(data))
#define CNTVER0_get_cp_cntver1(data)                                  ((0x0FFF0000&(data))>>16)
#define CNTVER0_get_cp_cntver0(data)                                  (0x00000FFF&(data))


#define CNTVER2                                                       0x18024248
#define CNTVER2_reg_addr                                              "0xb8024248"
#define CNTVER2_reg                                                   0xb8024248
#define CNTVER2_inst_addr                                             "0x0092"
#define CNTVER2_inst                                                  0x0092
#define CNTVER2_cp_cntver3_shift                                      (16)
#define CNTVER2_cp_cntver2_shift                                      (0)
#define CNTVER2_cp_cntver3_mask                                       (0x0FFF0000)
#define CNTVER2_cp_cntver2_mask                                       (0x00000FFF)
#define CNTVER2_cp_cntver3(data)                                      (0x0FFF0000&((data)<<16))
#define CNTVER2_cp_cntver2(data)                                      (0x00000FFF&(data))
#define CNTVER2_get_cp_cntver3(data)                                  ((0x0FFF0000&(data))>>16)
#define CNTVER2_get_cp_cntver2(data)                                  (0x00000FFF&(data))


#define CNTVER4                                                       0x1802424c
#define CNTVER4_reg_addr                                              "0xb802424c"
#define CNTVER4_reg                                                   0xb802424c
#define CNTVER4_inst_addr                                             "0x0093"
#define CNTVER4_inst                                                  0x0093
#define CNTVER4_cp_cntver5_shift                                      (16)
#define CNTVER4_cp_cntver4_shift                                      (0)
#define CNTVER4_cp_cntver5_mask                                       (0x0FFF0000)
#define CNTVER4_cp_cntver4_mask                                       (0x00000FFF)
#define CNTVER4_cp_cntver5(data)                                      (0x0FFF0000&((data)<<16))
#define CNTVER4_cp_cntver4(data)                                      (0x00000FFF&(data))
#define CNTVER4_get_cp_cntver5(data)                                  ((0x0FFF0000&(data))>>16)
#define CNTVER4_get_cp_cntver4(data)                                  (0x00000FFF&(data))


#define CNTVER6                                                       0x18024250
#define CNTVER6_reg_addr                                              "0xb8024250"
#define CNTVER6_reg                                                   0xb8024250
#define CNTVER6_inst_addr                                             "0x0094"
#define CNTVER6_inst                                                  0x0094
#define CNTVER6_cp_cntver7_shift                                      (16)
#define CNTVER6_cp_cntver6_shift                                      (0)
#define CNTVER6_cp_cntver7_mask                                       (0x0FFF0000)
#define CNTVER6_cp_cntver6_mask                                       (0x00000FFF)
#define CNTVER6_cp_cntver7(data)                                      (0x0FFF0000&((data)<<16))
#define CNTVER6_cp_cntver6(data)                                      (0x00000FFF&(data))
#define CNTVER6_get_cp_cntver7(data)                                  ((0x0FFF0000&(data))>>16)
#define CNTVER6_get_cp_cntver6(data)                                  (0x00000FFF&(data))


#define MPEGNR1                                                       0x18024254
#define MPEGNR1_reg_addr                                              "0xb8024254"
#define MPEGNR1_reg                                                   0xb8024254
#define MPEGNR1_inst_addr                                             "0x0095"
#define MPEGNR1_inst                                                  0x0095
#define MPEGNR1_cp_mpglowerbound_shift                                (24)
#define MPEGNR1_cp_mpgupperbound_shift                                (16)
#define MPEGNR1_cp_mpglpmode_shift                                    (12)
#define MPEGNR1_cp_mpgidx_y_shift                                     (8)
#define MPEGNR1_cp_mpegresultweight_y_shift                           (4)
#define MPEGNR1_cp_mpgidxmode_y_shift                                 (2)
#define MPEGNR1_cp_mpegenable_y_c_shift                               (1)
#define MPEGNR1_cp_mpegenable_y_y_shift                               (0)
#define MPEGNR1_cp_mpglowerbound_mask                                 (0xFF000000)
#define MPEGNR1_cp_mpgupperbound_mask                                 (0x00FF0000)
#define MPEGNR1_cp_mpglpmode_mask                                     (0x00001000)
#define MPEGNR1_cp_mpgidx_y_mask                                      (0x00000700)
#define MPEGNR1_cp_mpegresultweight_y_mask                            (0x00000070)
#define MPEGNR1_cp_mpgidxmode_y_mask                                  (0x0000000C)
#define MPEGNR1_cp_mpegenable_y_c_mask                                (0x00000002)
#define MPEGNR1_cp_mpegenable_y_y_mask                                (0x00000001)
#define MPEGNR1_cp_mpglowerbound(data)                                (0xFF000000&((data)<<24))
#define MPEGNR1_cp_mpgupperbound(data)                                (0x00FF0000&((data)<<16))
#define MPEGNR1_cp_mpglpmode(data)                                    (0x00001000&((data)<<12))
#define MPEGNR1_cp_mpgidx_y(data)                                     (0x00000700&((data)<<8))
#define MPEGNR1_cp_mpegresultweight_y(data)                           (0x00000070&((data)<<4))
#define MPEGNR1_cp_mpgidxmode_y(data)                                 (0x0000000C&((data)<<2))
#define MPEGNR1_cp_mpegenable_y_c(data)                               (0x00000002&((data)<<1))
#define MPEGNR1_cp_mpegenable_y_y(data)                               (0x00000001&(data))
#define MPEGNR1_get_cp_mpglowerbound(data)                            ((0xFF000000&(data))>>24)
#define MPEGNR1_get_cp_mpgupperbound(data)                            ((0x00FF0000&(data))>>16)
#define MPEGNR1_get_cp_mpglpmode(data)                                ((0x00001000&(data))>>12)
#define MPEGNR1_get_cp_mpgidx_y(data)                                 ((0x00000700&(data))>>8)
#define MPEGNR1_get_cp_mpegresultweight_y(data)                       ((0x00000070&(data))>>4)
#define MPEGNR1_get_cp_mpgidxmode_y(data)                             ((0x0000000C&(data))>>2)
#define MPEGNR1_get_cp_mpegenable_y_c(data)                           ((0x00000002&(data))>>1)
#define MPEGNR1_get_cp_mpegenable_y_y(data)                           (0x00000001&(data))


#define IM_DI_PIB_CONTROL                                             0x18024260
#define IM_DI_PIB_CONTROL_reg_addr                                    "0xb8024260"
#define IM_DI_PIB_CONTROL_reg                                         0xb8024260
#define IM_DI_PIB_CONTROL_inst_addr                                   "0x0098"
#define IM_DI_PIB_CONTROL_inst                                        0x0098
#define IM_DI_PIB_CONTROL_pib_film_all_shift                          (19)
#define IM_DI_PIB_CONTROL_pib_film_h_t_shift                          (18)
#define IM_DI_PIB_CONTROL_pib_film_h_m_shift                          (17)
#define IM_DI_PIB_CONTROL_pib_film_h_b_shift                          (16)
#define IM_DI_PIB_CONTROL_pib_film_v_l_shift                          (15)
#define IM_DI_PIB_CONTROL_pib_film_v_m_shift                          (14)
#define IM_DI_PIB_CONTROL_pib_film_v_r_shift                          (13)
#define IM_DI_PIB_CONTROL_pib_film_c_shift                            (12)
#define IM_DI_PIB_CONTROL_pib_film_h_11_shift                         (11)
#define IM_DI_PIB_CONTROL_pib_film_h_10_shift                         (10)
#define IM_DI_PIB_CONTROL_pib_film_h_09_shift                         (9)
#define IM_DI_PIB_CONTROL_pib_film_h_08_shift                         (8)
#define IM_DI_PIB_CONTROL_pib_film_h_07_shift                         (7)
#define IM_DI_PIB_CONTROL_pib_film_h_06_shift                         (6)
#define IM_DI_PIB_CONTROL_pib_film_h_05_shift                         (5)
#define IM_DI_PIB_CONTROL_pib_film_h_04_shift                         (4)
#define IM_DI_PIB_CONTROL_pib_film_h_03_shift                         (3)
#define IM_DI_PIB_CONTROL_pib_film_h_02_shift                         (2)
#define IM_DI_PIB_CONTROL_pib_film_h_01_shift                         (1)
#define IM_DI_PIB_CONTROL_pib_film_h_00_shift                         (0)
#define IM_DI_PIB_CONTROL_pib_film_all_mask                           (0x00080000)
#define IM_DI_PIB_CONTROL_pib_film_h_t_mask                           (0x00040000)
#define IM_DI_PIB_CONTROL_pib_film_h_m_mask                           (0x00020000)
#define IM_DI_PIB_CONTROL_pib_film_h_b_mask                           (0x00010000)
#define IM_DI_PIB_CONTROL_pib_film_v_l_mask                           (0x00008000)
#define IM_DI_PIB_CONTROL_pib_film_v_m_mask                           (0x00004000)
#define IM_DI_PIB_CONTROL_pib_film_v_r_mask                           (0x00002000)
#define IM_DI_PIB_CONTROL_pib_film_c_mask                             (0x00001000)
#define IM_DI_PIB_CONTROL_pib_film_h_11_mask                          (0x00000800)
#define IM_DI_PIB_CONTROL_pib_film_h_10_mask                          (0x00000400)
#define IM_DI_PIB_CONTROL_pib_film_h_09_mask                          (0x00000200)
#define IM_DI_PIB_CONTROL_pib_film_h_08_mask                          (0x00000100)
#define IM_DI_PIB_CONTROL_pib_film_h_07_mask                          (0x00000080)
#define IM_DI_PIB_CONTROL_pib_film_h_06_mask                          (0x00000040)
#define IM_DI_PIB_CONTROL_pib_film_h_05_mask                          (0x00000020)
#define IM_DI_PIB_CONTROL_pib_film_h_04_mask                          (0x00000010)
#define IM_DI_PIB_CONTROL_pib_film_h_03_mask                          (0x00000008)
#define IM_DI_PIB_CONTROL_pib_film_h_02_mask                          (0x00000004)
#define IM_DI_PIB_CONTROL_pib_film_h_01_mask                          (0x00000002)
#define IM_DI_PIB_CONTROL_pib_film_h_00_mask                          (0x00000001)
#define IM_DI_PIB_CONTROL_pib_film_all(data)                          (0x00080000&((data)<<19))
#define IM_DI_PIB_CONTROL_pib_film_h_t(data)                          (0x00040000&((data)<<18))
#define IM_DI_PIB_CONTROL_pib_film_h_m(data)                          (0x00020000&((data)<<17))
#define IM_DI_PIB_CONTROL_pib_film_h_b(data)                          (0x00010000&((data)<<16))
#define IM_DI_PIB_CONTROL_pib_film_v_l(data)                          (0x00008000&((data)<<15))
#define IM_DI_PIB_CONTROL_pib_film_v_m(data)                          (0x00004000&((data)<<14))
#define IM_DI_PIB_CONTROL_pib_film_v_r(data)                          (0x00002000&((data)<<13))
#define IM_DI_PIB_CONTROL_pib_film_c(data)                            (0x00001000&((data)<<12))
#define IM_DI_PIB_CONTROL_pib_film_h_11(data)                         (0x00000800&((data)<<11))
#define IM_DI_PIB_CONTROL_pib_film_h_10(data)                         (0x00000400&((data)<<10))
#define IM_DI_PIB_CONTROL_pib_film_h_09(data)                         (0x00000200&((data)<<9))
#define IM_DI_PIB_CONTROL_pib_film_h_08(data)                         (0x00000100&((data)<<8))
#define IM_DI_PIB_CONTROL_pib_film_h_07(data)                         (0x00000080&((data)<<7))
#define IM_DI_PIB_CONTROL_pib_film_h_06(data)                         (0x00000040&((data)<<6))
#define IM_DI_PIB_CONTROL_pib_film_h_05(data)                         (0x00000020&((data)<<5))
#define IM_DI_PIB_CONTROL_pib_film_h_04(data)                         (0x00000010&((data)<<4))
#define IM_DI_PIB_CONTROL_pib_film_h_03(data)                         (0x00000008&((data)<<3))
#define IM_DI_PIB_CONTROL_pib_film_h_02(data)                         (0x00000004&((data)<<2))
#define IM_DI_PIB_CONTROL_pib_film_h_01(data)                         (0x00000002&((data)<<1))
#define IM_DI_PIB_CONTROL_pib_film_h_00(data)                         (0x00000001&(data))
#define IM_DI_PIB_CONTROL_get_pib_film_all(data)                      ((0x00080000&(data))>>19)
#define IM_DI_PIB_CONTROL_get_pib_film_h_t(data)                      ((0x00040000&(data))>>18)
#define IM_DI_PIB_CONTROL_get_pib_film_h_m(data)                      ((0x00020000&(data))>>17)
#define IM_DI_PIB_CONTROL_get_pib_film_h_b(data)                      ((0x00010000&(data))>>16)
#define IM_DI_PIB_CONTROL_get_pib_film_v_l(data)                      ((0x00008000&(data))>>15)
#define IM_DI_PIB_CONTROL_get_pib_film_v_m(data)                      ((0x00004000&(data))>>14)
#define IM_DI_PIB_CONTROL_get_pib_film_v_r(data)                      ((0x00002000&(data))>>13)
#define IM_DI_PIB_CONTROL_get_pib_film_c(data)                        ((0x00001000&(data))>>12)
#define IM_DI_PIB_CONTROL_get_pib_film_h_11(data)                     ((0x00000800&(data))>>11)
#define IM_DI_PIB_CONTROL_get_pib_film_h_10(data)                     ((0x00000400&(data))>>10)
#define IM_DI_PIB_CONTROL_get_pib_film_h_09(data)                     ((0x00000200&(data))>>9)
#define IM_DI_PIB_CONTROL_get_pib_film_h_08(data)                     ((0x00000100&(data))>>8)
#define IM_DI_PIB_CONTROL_get_pib_film_h_07(data)                     ((0x00000080&(data))>>7)
#define IM_DI_PIB_CONTROL_get_pib_film_h_06(data)                     ((0x00000040&(data))>>6)
#define IM_DI_PIB_CONTROL_get_pib_film_h_05(data)                     ((0x00000020&(data))>>5)
#define IM_DI_PIB_CONTROL_get_pib_film_h_04(data)                     ((0x00000010&(data))>>4)
#define IM_DI_PIB_CONTROL_get_pib_film_h_03(data)                     ((0x00000008&(data))>>3)
#define IM_DI_PIB_CONTROL_get_pib_film_h_02(data)                     ((0x00000004&(data))>>2)
#define IM_DI_PIB_CONTROL_get_pib_film_h_01(data)                     ((0x00000002&(data))>>1)
#define IM_DI_PIB_CONTROL_get_pib_film_h_00(data)                     (0x00000001&(data))


#define IM_DI_PIB_ALL_CEN_TH                                          0x18024264
#define IM_DI_PIB_ALL_CEN_TH_reg_addr                                 "0xb8024264"
#define IM_DI_PIB_ALL_CEN_TH_reg                                      0xb8024264
#define IM_DI_PIB_ALL_CEN_TH_inst_addr                                "0x0099"
#define IM_DI_PIB_ALL_CEN_TH_inst                                     0x0099
#define IM_DI_PIB_ALL_CEN_TH_pib_film_all_th_shift                    (16)
#define IM_DI_PIB_ALL_CEN_TH_pib_film_cen_all_shift                   (0)
#define IM_DI_PIB_ALL_CEN_TH_pib_film_all_th_mask                     (0xFFFF0000)
#define IM_DI_PIB_ALL_CEN_TH_pib_film_cen_all_mask                    (0x0000FFFF)
#define IM_DI_PIB_ALL_CEN_TH_pib_film_all_th(data)                    (0xFFFF0000&((data)<<16))
#define IM_DI_PIB_ALL_CEN_TH_pib_film_cen_all(data)                   (0x0000FFFF&(data))
#define IM_DI_PIB_ALL_CEN_TH_get_pib_film_all_th(data)                ((0xFFFF0000&(data))>>16)
#define IM_DI_PIB_ALL_CEN_TH_get_pib_film_cen_all(data)               (0x0000FFFF&(data))


#define IM_DI_PIB_H_V_TH                                              0x18024268
#define IM_DI_PIB_H_V_TH_reg_addr                                     "0xb8024268"
#define IM_DI_PIB_H_V_TH_reg                                          0xb8024268
#define IM_DI_PIB_H_V_TH_inst_addr                                    "0x009A"
#define IM_DI_PIB_H_V_TH_inst                                         0x009A
#define IM_DI_PIB_H_V_TH_pib_film_h_th_shift                          (16)
#define IM_DI_PIB_H_V_TH_pib_film_v_th_shift                          (0)
#define IM_DI_PIB_H_V_TH_pib_film_h_th_mask                           (0xFFFF0000)
#define IM_DI_PIB_H_V_TH_pib_film_v_th_mask                           (0x0000FFFF)
#define IM_DI_PIB_H_V_TH_pib_film_h_th(data)                          (0xFFFF0000&((data)<<16))
#define IM_DI_PIB_H_V_TH_pib_film_v_th(data)                          (0x0000FFFF&(data))
#define IM_DI_PIB_H_V_TH_get_pib_film_h_th(data)                      ((0xFFFF0000&(data))>>16)
#define IM_DI_PIB_H_V_TH_get_pib_film_v_th(data)                      (0x0000FFFF&(data))


#define IM_DI_PIB_H00_H11_TH                                          0x1802426c
#define IM_DI_PIB_H00_H11_TH_reg_addr                                 "0xb802426c"
#define IM_DI_PIB_H00_H11_TH_reg                                      0xb802426c
#define IM_DI_PIB_H00_H11_TH_inst_addr                                "0x009B"
#define IM_DI_PIB_H00_H11_TH_inst                                     0x009B
#define IM_DI_PIB_H00_H11_TH_pib_film_h00_h11_th_shift                (0)
#define IM_DI_PIB_H00_H11_TH_pib_film_h00_h11_th_mask                 (0x0000FFFF)
#define IM_DI_PIB_H00_H11_TH_pib_film_h00_h11_th(data)                (0x0000FFFF&(data))
#define IM_DI_PIB_H00_H11_TH_get_pib_film_h00_h11_th(data)            (0x0000FFFF&(data))


#define DI_P_FILM_CTRL0                                               0x18024270
#define DI_P_FILM_CTRL0_reg_addr                                      "0xb8024270"
#define DI_P_FILM_CTRL0_reg                                           0xb8024270
#define DI_P_FILM_CTRL0_inst_addr                                     "0x009C"
#define DI_P_FILM_CTRL0_inst                                          0x009C
#define DI_P_FILM_CTRL0_prgfilm_32_detect_num_shift                   (24)
#define DI_P_FILM_CTRL0_prgfilm_22_detect_num_shift                   (16)
#define DI_P_FILM_CTRL0_prgfilm_motion_th_shift                       (6)
#define DI_P_FILM_CTRL0_prgfilm_debug_shift                           (5)
#define DI_P_FILM_CTRL0_prgfilm_motion_cnt_avg_auto_shift             (4)
#define DI_P_FILM_CTRL0_prgfilm_32_auto_shift                         (3)
#define DI_P_FILM_CTRL0_prgfilm_22_auto_shift                         (2)
#define DI_P_FILM_CTRL0_prgfilm_32_en_shift                           (1)
#define DI_P_FILM_CTRL0_prgfilm_22_en_shift                           (0)
#define DI_P_FILM_CTRL0_prgfilm_32_detect_num_mask                    (0x1F000000)
#define DI_P_FILM_CTRL0_prgfilm_22_detect_num_mask                    (0x001F0000)
#define DI_P_FILM_CTRL0_prgfilm_motion_th_mask                        (0x00003FC0)
#define DI_P_FILM_CTRL0_prgfilm_debug_mask                            (0x00000020)
#define DI_P_FILM_CTRL0_prgfilm_motion_cnt_avg_auto_mask              (0x00000010)
#define DI_P_FILM_CTRL0_prgfilm_32_auto_mask                          (0x00000008)
#define DI_P_FILM_CTRL0_prgfilm_22_auto_mask                          (0x00000004)
#define DI_P_FILM_CTRL0_prgfilm_32_en_mask                            (0x00000002)
#define DI_P_FILM_CTRL0_prgfilm_22_en_mask                            (0x00000001)
#define DI_P_FILM_CTRL0_prgfilm_32_detect_num(data)                   (0x1F000000&((data)<<24))
#define DI_P_FILM_CTRL0_prgfilm_22_detect_num(data)                   (0x001F0000&((data)<<16))
#define DI_P_FILM_CTRL0_prgfilm_motion_th(data)                       (0x00003FC0&((data)<<6))
#define DI_P_FILM_CTRL0_prgfilm_debug(data)                           (0x00000020&((data)<<5))
#define DI_P_FILM_CTRL0_prgfilm_motion_cnt_avg_auto(data)             (0x00000010&((data)<<4))
#define DI_P_FILM_CTRL0_prgfilm_32_auto(data)                         (0x00000008&((data)<<3))
#define DI_P_FILM_CTRL0_prgfilm_22_auto(data)                         (0x00000004&((data)<<2))
#define DI_P_FILM_CTRL0_prgfilm_32_en(data)                           (0x00000002&((data)<<1))
#define DI_P_FILM_CTRL0_prgfilm_22_en(data)                           (0x00000001&(data))
#define DI_P_FILM_CTRL0_get_prgfilm_32_detect_num(data)               ((0x1F000000&(data))>>24)
#define DI_P_FILM_CTRL0_get_prgfilm_22_detect_num(data)               ((0x001F0000&(data))>>16)
#define DI_P_FILM_CTRL0_get_prgfilm_motion_th(data)                   ((0x00003FC0&(data))>>6)
#define DI_P_FILM_CTRL0_get_prgfilm_debug(data)                       ((0x00000020&(data))>>5)
#define DI_P_FILM_CTRL0_get_prgfilm_motion_cnt_avg_auto(data)         ((0x00000010&(data))>>4)
#define DI_P_FILM_CTRL0_get_prgfilm_32_auto(data)                     ((0x00000008&(data))>>3)
#define DI_P_FILM_CTRL0_get_prgfilm_22_auto(data)                     ((0x00000004&(data))>>2)
#define DI_P_FILM_CTRL0_get_prgfilm_32_en(data)                       ((0x00000002&(data))>>1)
#define DI_P_FILM_CTRL0_get_prgfilm_22_en(data)                       (0x00000001&(data))


#define DI_P_FILM_CTRL1                                               0x18024274
#define DI_P_FILM_CTRL1_reg_addr                                      "0xb8024274"
#define DI_P_FILM_CTRL1_reg                                           0xb8024274
#define DI_P_FILM_CTRL1_inst_addr                                     "0x009D"
#define DI_P_FILM_CTRL1_inst                                          0x009D
#define DI_P_FILM_CTRL1_prgfilm_fw_32_detected_shift                  (28)
#define DI_P_FILM_CTRL1_prgfilm_fw_22_detected_shift                  (27)
#define DI_P_FILM_CTRL1_prgfilm_fw_film_idx_shift                     (22)
#define DI_P_FILM_CTRL1_prgfilm_fw_motion_cnt_avg_shift               (0)
#define DI_P_FILM_CTRL1_prgfilm_fw_32_detected_mask                   (0x10000000)
#define DI_P_FILM_CTRL1_prgfilm_fw_22_detected_mask                   (0x08000000)
#define DI_P_FILM_CTRL1_prgfilm_fw_film_idx_mask                      (0x07C00000)
#define DI_P_FILM_CTRL1_prgfilm_fw_motion_cnt_avg_mask                (0x003FFFFF)
#define DI_P_FILM_CTRL1_prgfilm_fw_32_detected(data)                  (0x10000000&((data)<<28))
#define DI_P_FILM_CTRL1_prgfilm_fw_22_detected(data)                  (0x08000000&((data)<<27))
#define DI_P_FILM_CTRL1_prgfilm_fw_film_idx(data)                     (0x07C00000&((data)<<22))
#define DI_P_FILM_CTRL1_prgfilm_fw_motion_cnt_avg(data)               (0x003FFFFF&(data))
#define DI_P_FILM_CTRL1_get_prgfilm_fw_32_detected(data)              ((0x10000000&(data))>>28)
#define DI_P_FILM_CTRL1_get_prgfilm_fw_22_detected(data)              ((0x08000000&(data))>>27)
#define DI_P_FILM_CTRL1_get_prgfilm_fw_film_idx(data)                 ((0x07C00000&(data))>>22)
#define DI_P_FILM_CTRL1_get_prgfilm_fw_motion_cnt_avg(data)           (0x003FFFFF&(data))


#define DI_P_FILM_READ                                                0x18024278
#define DI_P_FILM_READ_reg_addr                                       "0xb8024278"
#define DI_P_FILM_READ_reg                                            0xb8024278
#define DI_P_FILM_READ_inst_addr                                      "0x009E"
#define DI_P_FILM_READ_inst                                           0x009E
#define DI_P_FILM_READ_prgfilm_32_detected_shift                      (29)
#define DI_P_FILM_READ_prgfilm_22_detected_shift                      (28)
#define DI_P_FILM_READ_prgfilm_film_idx_shift                         (22)
#define DI_P_FILM_READ_prgfilm_motion_cnt_shift                       (0)
#define DI_P_FILM_READ_prgfilm_32_detected_mask                       (0x20000000)
#define DI_P_FILM_READ_prgfilm_22_detected_mask                       (0x10000000)
#define DI_P_FILM_READ_prgfilm_film_idx_mask                          (0x07C00000)
#define DI_P_FILM_READ_prgfilm_motion_cnt_mask                        (0x003FFFFF)
#define DI_P_FILM_READ_prgfilm_32_detected(data)                      (0x20000000&((data)<<29))
#define DI_P_FILM_READ_prgfilm_22_detected(data)                      (0x10000000&((data)<<28))
#define DI_P_FILM_READ_prgfilm_film_idx(data)                         (0x07C00000&((data)<<22))
#define DI_P_FILM_READ_prgfilm_motion_cnt(data)                       (0x003FFFFF&(data))
#define DI_P_FILM_READ_get_prgfilm_32_detected(data)                  ((0x20000000&(data))>>29)
#define DI_P_FILM_READ_get_prgfilm_22_detected(data)                  ((0x10000000&(data))>>28)
#define DI_P_FILM_READ_get_prgfilm_film_idx(data)                     ((0x07C00000&(data))>>22)
#define DI_P_FILM_READ_get_prgfilm_motion_cnt(data)                   (0x003FFFFF&(data))


#define IM_DI_HMC_3A                                                  0x18024280
#define IM_DI_HMC_3A_reg_addr                                         "0xb8024280"
#define IM_DI_HMC_3A_reg                                              0xb8024280
#define IM_DI_HMC_3A_inst_addr                                        "0x00A0"
#define IM_DI_HMC_3A_inst                                             0x00A0
#define IM_DI_HMC_3A_hmc_lstatistic_shift                             (20)
#define IM_DI_HMC_3A_hmc_rstatistic_shift                             (10)
#define IM_DI_HMC_3A_hmc_startline_shift                              (0)
#define IM_DI_HMC_3A_hmc_lstatistic_mask                              (0x3FF00000)
#define IM_DI_HMC_3A_hmc_rstatistic_mask                              (0x000FFC00)
#define IM_DI_HMC_3A_hmc_startline_mask                               (0x000003FF)
#define IM_DI_HMC_3A_hmc_lstatistic(data)                             (0x3FF00000&((data)<<20))
#define IM_DI_HMC_3A_hmc_rstatistic(data)                             (0x000FFC00&((data)<<10))
#define IM_DI_HMC_3A_hmc_startline(data)                              (0x000003FF&(data))
#define IM_DI_HMC_3A_get_hmc_lstatistic(data)                         ((0x3FF00000&(data))>>20)
#define IM_DI_HMC_3A_get_hmc_rstatistic(data)                         ((0x000FFC00&(data))>>10)
#define IM_DI_HMC_3A_get_hmc_startline(data)                          (0x000003FF&(data))


#define IM_DI_HMC_STATISTIC_TH                                        0x18024284
#define IM_DI_HMC_STATISTIC_TH_reg_addr                               "0xb8024284"
#define IM_DI_HMC_STATISTIC_TH_reg                                    0xb8024284
#define IM_DI_HMC_STATISTIC_TH_inst_addr                              "0x00A1"
#define IM_DI_HMC_STATISTIC_TH_inst                                   0x00A1
#define IM_DI_HMC_STATISTIC_TH_hmc_mvth2_shift                        (4)
#define IM_DI_HMC_STATISTIC_TH_hmc_mvth1_shift                        (0)
#define IM_DI_HMC_STATISTIC_TH_hmc_mvth2_mask                         (0x00000070)
#define IM_DI_HMC_STATISTIC_TH_hmc_mvth1_mask                         (0x00000007)
#define IM_DI_HMC_STATISTIC_TH_hmc_mvth2(data)                        (0x00000070&((data)<<4))
#define IM_DI_HMC_STATISTIC_TH_hmc_mvth1(data)                        (0x00000007&(data))
#define IM_DI_HMC_STATISTIC_TH_get_hmc_mvth2(data)                    ((0x00000070&(data))>>4)
#define IM_DI_HMC_STATISTIC_TH_get_hmc_mvth1(data)                    (0x00000007&(data))


#define IM_DI_HMC_STATISTIC1                                          0x18024288
#define IM_DI_HMC_STATISTIC1_reg_addr                                 "0xb8024288"
#define IM_DI_HMC_STATISTIC1_reg                                      0xb8024288
#define IM_DI_HMC_STATISTIC1_inst_addr                                "0x00A2"
#define IM_DI_HMC_STATISTIC1_inst                                     0x00A2
#define IM_DI_HMC_STATISTIC1_hmc_lb_pixelsum_shift                    (16)
#define IM_DI_HMC_STATISTIC1_hmc_rb_pixelsum_shift                    (0)
#define IM_DI_HMC_STATISTIC1_hmc_lb_pixelsum_mask                     (0xFFFF0000)
#define IM_DI_HMC_STATISTIC1_hmc_rb_pixelsum_mask                     (0x0000FFFF)
#define IM_DI_HMC_STATISTIC1_hmc_lb_pixelsum(data)                    (0xFFFF0000&((data)<<16))
#define IM_DI_HMC_STATISTIC1_hmc_rb_pixelsum(data)                    (0x0000FFFF&(data))
#define IM_DI_HMC_STATISTIC1_get_hmc_lb_pixelsum(data)                ((0xFFFF0000&(data))>>16)
#define IM_DI_HMC_STATISTIC1_get_hmc_rb_pixelsum(data)                (0x0000FFFF&(data))


#define IM_DI_HMC_STATISTIC2                                          0x1802428c
#define IM_DI_HMC_STATISTIC2_reg_addr                                 "0xb802428c"
#define IM_DI_HMC_STATISTIC2_reg                                      0xb802428c
#define IM_DI_HMC_STATISTIC2_inst_addr                                "0x00A3"
#define IM_DI_HMC_STATISTIC2_inst                                     0x00A3
#define IM_DI_HMC_STATISTIC2_hmc_lm_pixelsum_shift                    (16)
#define IM_DI_HMC_STATISTIC2_hmc_rm_pixelsum_shift                    (0)
#define IM_DI_HMC_STATISTIC2_hmc_lm_pixelsum_mask                     (0xFFFF0000)
#define IM_DI_HMC_STATISTIC2_hmc_rm_pixelsum_mask                     (0x0000FFFF)
#define IM_DI_HMC_STATISTIC2_hmc_lm_pixelsum(data)                    (0xFFFF0000&((data)<<16))
#define IM_DI_HMC_STATISTIC2_hmc_rm_pixelsum(data)                    (0x0000FFFF&(data))
#define IM_DI_HMC_STATISTIC2_get_hmc_lm_pixelsum(data)                ((0xFFFF0000&(data))>>16)
#define IM_DI_HMC_STATISTIC2_get_hmc_rm_pixelsum(data)                (0x0000FFFF&(data))


#define IM_DI_HMC_STATISTIC3                                          0x18024290
#define IM_DI_HMC_STATISTIC3_reg_addr                                 "0xb8024290"
#define IM_DI_HMC_STATISTIC3_reg                                      0xb8024290
#define IM_DI_HMC_STATISTIC3_inst_addr                                "0x00A4"
#define IM_DI_HMC_STATISTIC3_inst                                     0x00A4
#define IM_DI_HMC_STATISTIC3_hmc_ls_pixelsum_shift                    (16)
#define IM_DI_HMC_STATISTIC3_hmc_rs_pixelsum_shift                    (0)
#define IM_DI_HMC_STATISTIC3_hmc_ls_pixelsum_mask                     (0xFFFF0000)
#define IM_DI_HMC_STATISTIC3_hmc_rs_pixelsum_mask                     (0x0000FFFF)
#define IM_DI_HMC_STATISTIC3_hmc_ls_pixelsum(data)                    (0xFFFF0000&((data)<<16))
#define IM_DI_HMC_STATISTIC3_hmc_rs_pixelsum(data)                    (0x0000FFFF&(data))
#define IM_DI_HMC_STATISTIC3_get_hmc_ls_pixelsum(data)                ((0xFFFF0000&(data))>>16)
#define IM_DI_HMC_STATISTIC3_get_hmc_rs_pixelsum(data)                (0x0000FFFF&(data))


#define IM_DI_FRAMESOBEL_CTRL                                         0x18024294
#define IM_DI_FRAMESOBEL_CTRL_reg_addr                                "0xb8024294"
#define IM_DI_FRAMESOBEL_CTRL_reg                                     0xb8024294
#define IM_DI_FRAMESOBEL_CTRL_inst_addr                               "0x00A5"
#define IM_DI_FRAMESOBEL_CTRL_inst                                    0x00A5
#define IM_DI_FRAMESOBEL_CTRL_framesobel_en_shift                     (31)
#define IM_DI_FRAMESOBEL_CTRL_framesobel_hedge_count_shift            (24)
#define IM_DI_FRAMESOBEL_CTRL_framesobel_hedge_length_shift           (16)
#define IM_DI_FRAMESOBEL_CTRL_framesobel_gradi_h_th_shift             (8)
#define IM_DI_FRAMESOBEL_CTRL_framesobel_gradi_v_th_shift             (0)
#define IM_DI_FRAMESOBEL_CTRL_framesobel_en_mask                      (0x80000000)
#define IM_DI_FRAMESOBEL_CTRL_framesobel_hedge_count_mask             (0x7F000000)
#define IM_DI_FRAMESOBEL_CTRL_framesobel_hedge_length_mask            (0x00070000)
#define IM_DI_FRAMESOBEL_CTRL_framesobel_gradi_h_th_mask              (0x0000FF00)
#define IM_DI_FRAMESOBEL_CTRL_framesobel_gradi_v_th_mask              (0x000000FF)
#define IM_DI_FRAMESOBEL_CTRL_framesobel_en(data)                     (0x80000000&((data)<<31))
#define IM_DI_FRAMESOBEL_CTRL_framesobel_hedge_count(data)            (0x7F000000&((data)<<24))
#define IM_DI_FRAMESOBEL_CTRL_framesobel_hedge_length(data)           (0x00070000&((data)<<16))
#define IM_DI_FRAMESOBEL_CTRL_framesobel_gradi_h_th(data)             (0x0000FF00&((data)<<8))
#define IM_DI_FRAMESOBEL_CTRL_framesobel_gradi_v_th(data)             (0x000000FF&(data))
#define IM_DI_FRAMESOBEL_CTRL_get_framesobel_en(data)                 ((0x80000000&(data))>>31)
#define IM_DI_FRAMESOBEL_CTRL_get_framesobel_hedge_count(data)        ((0x7F000000&(data))>>24)
#define IM_DI_FRAMESOBEL_CTRL_get_framesobel_hedge_length(data)       ((0x00070000&(data))>>16)
#define IM_DI_FRAMESOBEL_CTRL_get_framesobel_gradi_h_th(data)         ((0x0000FF00&(data))>>8)
#define IM_DI_FRAMESOBEL_CTRL_get_framesobel_gradi_v_th(data)         (0x000000FF&(data))


#define IM_DI_FRAMESOBEL_STATISTIC_CTRL                               0x18024298
#define IM_DI_FRAMESOBEL_STATISTIC_CTRL_reg_addr                      "0xb8024298"
#define IM_DI_FRAMESOBEL_STATISTIC_CTRL_reg                           0xb8024298
#define IM_DI_FRAMESOBEL_STATISTIC_CTRL_inst_addr                     "0x00A6"
#define IM_DI_FRAMESOBEL_STATISTIC_CTRL_inst                          0x00A6
#define IM_DI_FRAMESOBEL_STATISTIC_CTRL_framesobel_hedge_count_sta_shift  (24)
#define IM_DI_FRAMESOBEL_STATISTIC_CTRL_chromaerror_framemotionc_th_shift  (16)
#define IM_DI_FRAMESOBEL_STATISTIC_CTRL_framesobel_gradi_h_th_sta_shift  (8)
#define IM_DI_FRAMESOBEL_STATISTIC_CTRL_framesobel_gradi_v_th_sta_shift  (0)
#define IM_DI_FRAMESOBEL_STATISTIC_CTRL_framesobel_hedge_count_sta_mask  (0x7F000000)
#define IM_DI_FRAMESOBEL_STATISTIC_CTRL_chromaerror_framemotionc_th_mask  (0x00FF0000)
#define IM_DI_FRAMESOBEL_STATISTIC_CTRL_framesobel_gradi_h_th_sta_mask  (0x0000FF00)
#define IM_DI_FRAMESOBEL_STATISTIC_CTRL_framesobel_gradi_v_th_sta_mask  (0x000000FF)
#define IM_DI_FRAMESOBEL_STATISTIC_CTRL_framesobel_hedge_count_sta(data)  (0x7F000000&((data)<<24))
#define IM_DI_FRAMESOBEL_STATISTIC_CTRL_chromaerror_framemotionc_th(data)  (0x00FF0000&((data)<<16))
#define IM_DI_FRAMESOBEL_STATISTIC_CTRL_framesobel_gradi_h_th_sta(data)  (0x0000FF00&((data)<<8))
#define IM_DI_FRAMESOBEL_STATISTIC_CTRL_framesobel_gradi_v_th_sta(data)  (0x000000FF&(data))
#define IM_DI_FRAMESOBEL_STATISTIC_CTRL_get_framesobel_hedge_count_sta(data)  ((0x7F000000&(data))>>24)
#define IM_DI_FRAMESOBEL_STATISTIC_CTRL_get_chromaerror_framemotionc_th(data)  ((0x00FF0000&(data))>>16)
#define IM_DI_FRAMESOBEL_STATISTIC_CTRL_get_framesobel_gradi_h_th_sta(data)  ((0x0000FF00&(data))>>8)
#define IM_DI_FRAMESOBEL_STATISTIC_CTRL_get_framesobel_gradi_v_th_sta(data)  (0x000000FF&(data))


#define IM_DI_FRAMESOBEL_STATISTIC                                    0x1802429c
#define IM_DI_FRAMESOBEL_STATISTIC_reg_addr                           "0xb802429c"
#define IM_DI_FRAMESOBEL_STATISTIC_reg                                0xb802429c
#define IM_DI_FRAMESOBEL_STATISTIC_inst_addr                          "0x00A7"
#define IM_DI_FRAMESOBEL_STATISTIC_inst                               0x00A7
#define IM_DI_FRAMESOBEL_STATISTIC_chromaerror_en_shift               (31)
#define IM_DI_FRAMESOBEL_STATISTIC_chromaerror_all_shift              (30)
#define IM_DI_FRAMESOBEL_STATISTIC_chromaerror_th_shift               (24)
#define IM_DI_FRAMESOBEL_STATISTIC_framesobel_hedge_statistic_shift   (0)
#define IM_DI_FRAMESOBEL_STATISTIC_chromaerror_en_mask                (0x80000000)
#define IM_DI_FRAMESOBEL_STATISTIC_chromaerror_all_mask               (0x40000000)
#define IM_DI_FRAMESOBEL_STATISTIC_chromaerror_th_mask                (0x1F000000)
#define IM_DI_FRAMESOBEL_STATISTIC_framesobel_hedge_statistic_mask    (0x00FFFFFF)
#define IM_DI_FRAMESOBEL_STATISTIC_chromaerror_en(data)               (0x80000000&((data)<<31))
#define IM_DI_FRAMESOBEL_STATISTIC_chromaerror_all(data)              (0x40000000&((data)<<30))
#define IM_DI_FRAMESOBEL_STATISTIC_chromaerror_th(data)               (0x1F000000&((data)<<24))
#define IM_DI_FRAMESOBEL_STATISTIC_framesobel_hedge_statistic(data)   (0x00FFFFFF&(data))
#define IM_DI_FRAMESOBEL_STATISTIC_get_chromaerror_en(data)           ((0x80000000&(data))>>31)
#define IM_DI_FRAMESOBEL_STATISTIC_get_chromaerror_all(data)          ((0x40000000&(data))>>30)
#define IM_DI_FRAMESOBEL_STATISTIC_get_chromaerror_th(data)           ((0x1F000000&(data))>>24)
#define IM_DI_FRAMESOBEL_STATISTIC_get_framesobel_hedge_statistic(data)  (0x00FFFFFF&(data))


#define TNRXC_MKII_CTRL                                               0x180242a0
#define TNRXC_MKII_CTRL_reg_addr                                      "0xb80242a0"
#define TNRXC_MKII_CTRL_reg                                           0xb80242a0
#define TNRXC_MKII_CTRL_inst_addr                                     "0x00A8"
#define TNRXC_MKII_CTRL_inst                                          0x00A8
#define TNRXC_MKII_CTRL_tnrxc_mkii_thc2_shift                         (24)
#define TNRXC_MKII_CTRL_tnrxc_mkii_thc1_shift                         (16)
#define TNRXC_MKII_CTRL_tnrxc_mkii_thy_shift                          (8)
#define TNRXC_MKII_CTRL_dummy180242a0_7_2_shift                       (2)
#define TNRXC_MKII_CTRL_tnrxc_dbguvmode_shift                         (1)
#define TNRXC_MKII_CTRL_tnrxc_mkii_en_shift                           (0)
#define TNRXC_MKII_CTRL_tnrxc_mkii_thc2_mask                          (0xFF000000)
#define TNRXC_MKII_CTRL_tnrxc_mkii_thc1_mask                          (0x00FF0000)
#define TNRXC_MKII_CTRL_tnrxc_mkii_thy_mask                           (0x0000FF00)
#define TNRXC_MKII_CTRL_dummy180242a0_7_2_mask                        (0x000000FC)
#define TNRXC_MKII_CTRL_tnrxc_dbguvmode_mask                          (0x00000002)
#define TNRXC_MKII_CTRL_tnrxc_mkii_en_mask                            (0x00000001)
#define TNRXC_MKII_CTRL_tnrxc_mkii_thc2(data)                         (0xFF000000&((data)<<24))
#define TNRXC_MKII_CTRL_tnrxc_mkii_thc1(data)                         (0x00FF0000&((data)<<16))
#define TNRXC_MKII_CTRL_tnrxc_mkii_thy(data)                          (0x0000FF00&((data)<<8))
#define TNRXC_MKII_CTRL_dummy180242a0_7_2(data)                       (0x000000FC&((data)<<2))
#define TNRXC_MKII_CTRL_tnrxc_dbguvmode(data)                         (0x00000002&((data)<<1))
#define TNRXC_MKII_CTRL_tnrxc_mkii_en(data)                           (0x00000001&(data))
#define TNRXC_MKII_CTRL_get_tnrxc_mkii_thc2(data)                     ((0xFF000000&(data))>>24)
#define TNRXC_MKII_CTRL_get_tnrxc_mkii_thc1(data)                     ((0x00FF0000&(data))>>16)
#define TNRXC_MKII_CTRL_get_tnrxc_mkii_thy(data)                      ((0x0000FF00&(data))>>8)
#define TNRXC_MKII_CTRL_get_dummy180242a0_7_2(data)                   ((0x000000FC&(data))>>2)
#define TNRXC_MKII_CTRL_get_tnrxc_dbguvmode(data)                     ((0x00000002&(data))>>1)
#define TNRXC_MKII_CTRL_get_tnrxc_mkii_en(data)                       (0x00000001&(data))


#define IM_DI_RTNR_K_DARK                                             0x180242a4
#define IM_DI_RTNR_K_DARK_reg_addr                                    "0xb80242a4"
#define IM_DI_RTNR_K_DARK_reg                                         0xb80242a4
#define IM_DI_RTNR_K_DARK_inst_addr                                   "0x00A9"
#define IM_DI_RTNR_K_DARK_inst                                        0x00A9
#define IM_DI_RTNR_K_DARK_cp_temporal_y_kout_dark_2_shift             (28)
#define IM_DI_RTNR_K_DARK_cp_temporal_y_kin_dark_2_shift              (24)
#define IM_DI_RTNR_K_DARK_cp_temporal_y_dark_th_shift                 (16)
#define IM_DI_RTNR_K_DARK_cp_temporal_y_kout_dark_shift               (8)
#define IM_DI_RTNR_K_DARK_cp_temporal_y_kin_dark_shift                (4)
#define IM_DI_RTNR_K_DARK_cp_temporal_y_dark_k_en_shift               (0)
#define IM_DI_RTNR_K_DARK_cp_temporal_y_kout_dark_2_mask              (0x70000000)
#define IM_DI_RTNR_K_DARK_cp_temporal_y_kin_dark_2_mask               (0x07000000)
#define IM_DI_RTNR_K_DARK_cp_temporal_y_dark_th_mask                  (0x00FF0000)
#define IM_DI_RTNR_K_DARK_cp_temporal_y_kout_dark_mask                (0x00000700)
#define IM_DI_RTNR_K_DARK_cp_temporal_y_kin_dark_mask                 (0x00000070)
#define IM_DI_RTNR_K_DARK_cp_temporal_y_dark_k_en_mask                (0x00000001)
#define IM_DI_RTNR_K_DARK_cp_temporal_y_kout_dark_2(data)             (0x70000000&((data)<<28))
#define IM_DI_RTNR_K_DARK_cp_temporal_y_kin_dark_2(data)              (0x07000000&((data)<<24))
#define IM_DI_RTNR_K_DARK_cp_temporal_y_dark_th(data)                 (0x00FF0000&((data)<<16))
#define IM_DI_RTNR_K_DARK_cp_temporal_y_kout_dark(data)               (0x00000700&((data)<<8))
#define IM_DI_RTNR_K_DARK_cp_temporal_y_kin_dark(data)                (0x00000070&((data)<<4))
#define IM_DI_RTNR_K_DARK_cp_temporal_y_dark_k_en(data)               (0x00000001&(data))
#define IM_DI_RTNR_K_DARK_get_cp_temporal_y_kout_dark_2(data)         ((0x70000000&(data))>>28)
#define IM_DI_RTNR_K_DARK_get_cp_temporal_y_kin_dark_2(data)          ((0x07000000&(data))>>24)
#define IM_DI_RTNR_K_DARK_get_cp_temporal_y_dark_th(data)             ((0x00FF0000&(data))>>16)
#define IM_DI_RTNR_K_DARK_get_cp_temporal_y_kout_dark(data)           ((0x00000700&(data))>>8)
#define IM_DI_RTNR_K_DARK_get_cp_temporal_y_kin_dark(data)            ((0x00000070&(data))>>4)
#define IM_DI_RTNR_K_DARK_get_cp_temporal_y_dark_k_en(data)           (0x00000001&(data))


#define IM_DI_RTNR_REFINED_CTRL                                       0x180242a8
#define IM_DI_RTNR_REFINED_CTRL_reg_addr                              "0xb80242a8"
#define IM_DI_RTNR_REFINED_CTRL_reg                                   0xb80242a8
#define IM_DI_RTNR_REFINED_CTRL_inst_addr                             "0x00AA"
#define IM_DI_RTNR_REFINED_CTRL_inst                                  0x00AA
#define IM_DI_RTNR_REFINED_CTRL_dummy180242a8_31_29_shift             (29)
#define IM_DI_RTNR_REFINED_CTRL_rtnr_refined_c_en_shift               (28)
#define IM_DI_RTNR_REFINED_CTRL_rtnr_th_localedgediff_shift           (16)
#define IM_DI_RTNR_REFINED_CTRL_rtnr_stilledge_debug_shift            (15)
#define IM_DI_RTNR_REFINED_CTRL_rtnr_stilledge_bonusbias_shift        (12)
#define IM_DI_RTNR_REFINED_CTRL_rtnr_localedge_debug_shift            (11)
#define IM_DI_RTNR_REFINED_CTRL_rtnr_act_bias_shift                   (8)
#define IM_DI_RTNR_REFINED_CTRL_dummy180242a8_7_shift                 (7)
#define IM_DI_RTNR_REFINED_CTRL_rtnr_crct_bias_shift                  (4)
#define IM_DI_RTNR_REFINED_CTRL_rtnr_crct_debug_shift                 (3)
#define IM_DI_RTNR_REFINED_CTRL_rtnr_stilledge_en_shift               (2)
#define IM_DI_RTNR_REFINED_CTRL_rtnr_localedge_en_shift               (1)
#define IM_DI_RTNR_REFINED_CTRL_rtnr_new_formula_en_shift             (0)
#define IM_DI_RTNR_REFINED_CTRL_dummy180242a8_31_29_mask              (0xE0000000)
#define IM_DI_RTNR_REFINED_CTRL_rtnr_refined_c_en_mask                (0x10000000)
#define IM_DI_RTNR_REFINED_CTRL_rtnr_th_localedgediff_mask            (0x0FFF0000)
#define IM_DI_RTNR_REFINED_CTRL_rtnr_stilledge_debug_mask             (0x00008000)
#define IM_DI_RTNR_REFINED_CTRL_rtnr_stilledge_bonusbias_mask         (0x00007000)
#define IM_DI_RTNR_REFINED_CTRL_rtnr_localedge_debug_mask             (0x00000800)
#define IM_DI_RTNR_REFINED_CTRL_rtnr_act_bias_mask                    (0x00000700)
#define IM_DI_RTNR_REFINED_CTRL_dummy180242a8_7_mask                  (0x00000080)
#define IM_DI_RTNR_REFINED_CTRL_rtnr_crct_bias_mask                   (0x00000070)
#define IM_DI_RTNR_REFINED_CTRL_rtnr_crct_debug_mask                  (0x00000008)
#define IM_DI_RTNR_REFINED_CTRL_rtnr_stilledge_en_mask                (0x00000004)
#define IM_DI_RTNR_REFINED_CTRL_rtnr_localedge_en_mask                (0x00000002)
#define IM_DI_RTNR_REFINED_CTRL_rtnr_new_formula_en_mask              (0x00000001)
#define IM_DI_RTNR_REFINED_CTRL_dummy180242a8_31_29(data)             (0xE0000000&((data)<<29))
#define IM_DI_RTNR_REFINED_CTRL_rtnr_refined_c_en(data)               (0x10000000&((data)<<28))
#define IM_DI_RTNR_REFINED_CTRL_rtnr_th_localedgediff(data)           (0x0FFF0000&((data)<<16))
#define IM_DI_RTNR_REFINED_CTRL_rtnr_stilledge_debug(data)            (0x00008000&((data)<<15))
#define IM_DI_RTNR_REFINED_CTRL_rtnr_stilledge_bonusbias(data)        (0x00007000&((data)<<12))
#define IM_DI_RTNR_REFINED_CTRL_rtnr_localedge_debug(data)            (0x00000800&((data)<<11))
#define IM_DI_RTNR_REFINED_CTRL_rtnr_act_bias(data)                   (0x00000700&((data)<<8))
#define IM_DI_RTNR_REFINED_CTRL_dummy180242a8_7(data)                 (0x00000080&((data)<<7))
#define IM_DI_RTNR_REFINED_CTRL_rtnr_crct_bias(data)                  (0x00000070&((data)<<4))
#define IM_DI_RTNR_REFINED_CTRL_rtnr_crct_debug(data)                 (0x00000008&((data)<<3))
#define IM_DI_RTNR_REFINED_CTRL_rtnr_stilledge_en(data)               (0x00000004&((data)<<2))
#define IM_DI_RTNR_REFINED_CTRL_rtnr_localedge_en(data)               (0x00000002&((data)<<1))
#define IM_DI_RTNR_REFINED_CTRL_rtnr_new_formula_en(data)             (0x00000001&(data))
#define IM_DI_RTNR_REFINED_CTRL_get_dummy180242a8_31_29(data)         ((0xE0000000&(data))>>29)
#define IM_DI_RTNR_REFINED_CTRL_get_rtnr_refined_c_en(data)           ((0x10000000&(data))>>28)
#define IM_DI_RTNR_REFINED_CTRL_get_rtnr_th_localedgediff(data)       ((0x0FFF0000&(data))>>16)
#define IM_DI_RTNR_REFINED_CTRL_get_rtnr_stilledge_debug(data)        ((0x00008000&(data))>>15)
#define IM_DI_RTNR_REFINED_CTRL_get_rtnr_stilledge_bonusbias(data)    ((0x00007000&(data))>>12)
#define IM_DI_RTNR_REFINED_CTRL_get_rtnr_localedge_debug(data)        ((0x00000800&(data))>>11)
#define IM_DI_RTNR_REFINED_CTRL_get_rtnr_act_bias(data)               ((0x00000700&(data))>>8)
#define IM_DI_RTNR_REFINED_CTRL_get_dummy180242a8_7(data)             ((0x00000080&(data))>>7)
#define IM_DI_RTNR_REFINED_CTRL_get_rtnr_crct_bias(data)              ((0x00000070&(data))>>4)
#define IM_DI_RTNR_REFINED_CTRL_get_rtnr_crct_debug(data)             ((0x00000008&(data))>>3)
#define IM_DI_RTNR_REFINED_CTRL_get_rtnr_stilledge_en(data)           ((0x00000004&(data))>>2)
#define IM_DI_RTNR_REFINED_CTRL_get_rtnr_localedge_en(data)           ((0x00000002&(data))>>1)
#define IM_DI_RTNR_REFINED_CTRL_get_rtnr_new_formula_en(data)         (0x00000001&(data))


#define IM_DI_RTNR_REFINED_CTRL2                                      0x180242ac
#define IM_DI_RTNR_REFINED_CTRL2_reg_addr                             "0xb80242ac"
#define IM_DI_RTNR_REFINED_CTRL2_reg                                  0xb80242ac
#define IM_DI_RTNR_REFINED_CTRL2_inst_addr                            "0x00AB"
#define IM_DI_RTNR_REFINED_CTRL2_inst                                 0x00AB
#define IM_DI_RTNR_REFINED_CTRL2_dummy180242ac_31_17_shift            (17)
#define IM_DI_RTNR_REFINED_CTRL2_rtnr_stilledge_th_edgdiff_shift      (8)
#define IM_DI_RTNR_REFINED_CTRL2_rtnr_stilledge_th_edg_shift          (0)
#define IM_DI_RTNR_REFINED_CTRL2_dummy180242ac_31_17_mask             (0xFFFE0000)
#define IM_DI_RTNR_REFINED_CTRL2_rtnr_stilledge_th_edgdiff_mask       (0x0001FF00)
#define IM_DI_RTNR_REFINED_CTRL2_rtnr_stilledge_th_edg_mask           (0x000000FF)
#define IM_DI_RTNR_REFINED_CTRL2_dummy180242ac_31_17(data)            (0xFFFE0000&((data)<<17))
#define IM_DI_RTNR_REFINED_CTRL2_rtnr_stilledge_th_edgdiff(data)      (0x0001FF00&((data)<<8))
#define IM_DI_RTNR_REFINED_CTRL2_rtnr_stilledge_th_edg(data)          (0x000000FF&(data))
#define IM_DI_RTNR_REFINED_CTRL2_get_dummy180242ac_31_17(data)        ((0xFFFE0000&(data))>>17)
#define IM_DI_RTNR_REFINED_CTRL2_get_rtnr_stilledge_th_edgdiff(data)  ((0x0001FF00&(data))>>8)
#define IM_DI_RTNR_REFINED_CTRL2_get_rtnr_stilledge_th_edg(data)      (0x000000FF&(data))


#define IM_DI_RTNR_Y_TH0_TH3                                          0x180242b0
#define IM_DI_RTNR_Y_TH0_TH3_reg_addr                                 "0xb80242b0"
#define IM_DI_RTNR_Y_TH0_TH3_reg                                      0xb80242b0
#define IM_DI_RTNR_Y_TH0_TH3_inst_addr                                "0x00AC"
#define IM_DI_RTNR_Y_TH0_TH3_inst                                     0x00AC
#define IM_DI_RTNR_Y_TH0_TH3_cp_temporalthly3_shift                   (24)
#define IM_DI_RTNR_Y_TH0_TH3_cp_temporalthly2_shift                   (16)
#define IM_DI_RTNR_Y_TH0_TH3_cp_temporalthly1_shift                   (8)
#define IM_DI_RTNR_Y_TH0_TH3_cp_temporalthly0_shift                   (0)
#define IM_DI_RTNR_Y_TH0_TH3_cp_temporalthly3_mask                    (0xFF000000)
#define IM_DI_RTNR_Y_TH0_TH3_cp_temporalthly2_mask                    (0x00FF0000)
#define IM_DI_RTNR_Y_TH0_TH3_cp_temporalthly1_mask                    (0x0000FF00)
#define IM_DI_RTNR_Y_TH0_TH3_cp_temporalthly0_mask                    (0x000000FF)
#define IM_DI_RTNR_Y_TH0_TH3_cp_temporalthly3(data)                   (0xFF000000&((data)<<24))
#define IM_DI_RTNR_Y_TH0_TH3_cp_temporalthly2(data)                   (0x00FF0000&((data)<<16))
#define IM_DI_RTNR_Y_TH0_TH3_cp_temporalthly1(data)                   (0x0000FF00&((data)<<8))
#define IM_DI_RTNR_Y_TH0_TH3_cp_temporalthly0(data)                   (0x000000FF&(data))
#define IM_DI_RTNR_Y_TH0_TH3_get_cp_temporalthly3(data)               ((0xFF000000&(data))>>24)
#define IM_DI_RTNR_Y_TH0_TH3_get_cp_temporalthly2(data)               ((0x00FF0000&(data))>>16)
#define IM_DI_RTNR_Y_TH0_TH3_get_cp_temporalthly1(data)               ((0x0000FF00&(data))>>8)
#define IM_DI_RTNR_Y_TH0_TH3_get_cp_temporalthly0(data)               (0x000000FF&(data))


#define IM_DI_RTNR_Y_TH4_TH6                                          0x180242b4
#define IM_DI_RTNR_Y_TH4_TH6_reg_addr                                 "0xb80242b4"
#define IM_DI_RTNR_Y_TH4_TH6_reg                                      0xb80242b4
#define IM_DI_RTNR_Y_TH4_TH6_inst_addr                                "0x00AD"
#define IM_DI_RTNR_Y_TH4_TH6_inst                                     0x00AD
#define IM_DI_RTNR_Y_TH4_TH6_cp_temporalthly6_shift                   (16)
#define IM_DI_RTNR_Y_TH4_TH6_cp_temporalthly5_shift                   (8)
#define IM_DI_RTNR_Y_TH4_TH6_cp_temporalthly4_shift                   (0)
#define IM_DI_RTNR_Y_TH4_TH6_cp_temporalthly6_mask                    (0x00FF0000)
#define IM_DI_RTNR_Y_TH4_TH6_cp_temporalthly5_mask                    (0x0000FF00)
#define IM_DI_RTNR_Y_TH4_TH6_cp_temporalthly4_mask                    (0x000000FF)
#define IM_DI_RTNR_Y_TH4_TH6_cp_temporalthly6(data)                   (0x00FF0000&((data)<<16))
#define IM_DI_RTNR_Y_TH4_TH6_cp_temporalthly5(data)                   (0x0000FF00&((data)<<8))
#define IM_DI_RTNR_Y_TH4_TH6_cp_temporalthly4(data)                   (0x000000FF&(data))
#define IM_DI_RTNR_Y_TH4_TH6_get_cp_temporalthly6(data)               ((0x00FF0000&(data))>>16)
#define IM_DI_RTNR_Y_TH4_TH6_get_cp_temporalthly5(data)               ((0x0000FF00&(data))>>8)
#define IM_DI_RTNR_Y_TH4_TH6_get_cp_temporalthly4(data)               (0x000000FF&(data))


#define IM_DI_RTNR_C_TH0_TH3                                          0x180242b8
#define IM_DI_RTNR_C_TH0_TH3_reg_addr                                 "0xb80242b8"
#define IM_DI_RTNR_C_TH0_TH3_reg                                      0xb80242b8
#define IM_DI_RTNR_C_TH0_TH3_inst_addr                                "0x00AE"
#define IM_DI_RTNR_C_TH0_TH3_inst                                     0x00AE
#define IM_DI_RTNR_C_TH0_TH3_cp_temporalthlc3_shift                   (24)
#define IM_DI_RTNR_C_TH0_TH3_cp_temporalthlc2_shift                   (16)
#define IM_DI_RTNR_C_TH0_TH3_cp_temporalthlc1_shift                   (8)
#define IM_DI_RTNR_C_TH0_TH3_cp_temporalthlc0_shift                   (0)
#define IM_DI_RTNR_C_TH0_TH3_cp_temporalthlc3_mask                    (0xFF000000)
#define IM_DI_RTNR_C_TH0_TH3_cp_temporalthlc2_mask                    (0x00FF0000)
#define IM_DI_RTNR_C_TH0_TH3_cp_temporalthlc1_mask                    (0x0000FF00)
#define IM_DI_RTNR_C_TH0_TH3_cp_temporalthlc0_mask                    (0x000000FF)
#define IM_DI_RTNR_C_TH0_TH3_cp_temporalthlc3(data)                   (0xFF000000&((data)<<24))
#define IM_DI_RTNR_C_TH0_TH3_cp_temporalthlc2(data)                   (0x00FF0000&((data)<<16))
#define IM_DI_RTNR_C_TH0_TH3_cp_temporalthlc1(data)                   (0x0000FF00&((data)<<8))
#define IM_DI_RTNR_C_TH0_TH3_cp_temporalthlc0(data)                   (0x000000FF&(data))
#define IM_DI_RTNR_C_TH0_TH3_get_cp_temporalthlc3(data)               ((0xFF000000&(data))>>24)
#define IM_DI_RTNR_C_TH0_TH3_get_cp_temporalthlc2(data)               ((0x00FF0000&(data))>>16)
#define IM_DI_RTNR_C_TH0_TH3_get_cp_temporalthlc1(data)               ((0x0000FF00&(data))>>8)
#define IM_DI_RTNR_C_TH0_TH3_get_cp_temporalthlc0(data)               (0x000000FF&(data))


#define IM_DI_RTNR_C_TH4_TH6                                          0x180242bc
#define IM_DI_RTNR_C_TH4_TH6_reg_addr                                 "0xb80242bc"
#define IM_DI_RTNR_C_TH4_TH6_reg                                      0xb80242bc
#define IM_DI_RTNR_C_TH4_TH6_inst_addr                                "0x00AF"
#define IM_DI_RTNR_C_TH4_TH6_inst                                     0x00AF
#define IM_DI_RTNR_C_TH4_TH6_cp_temporalthlc6_shift                   (16)
#define IM_DI_RTNR_C_TH4_TH6_cp_temporalthlc5_shift                   (8)
#define IM_DI_RTNR_C_TH4_TH6_cp_temporalthlc4_shift                   (0)
#define IM_DI_RTNR_C_TH4_TH6_cp_temporalthlc6_mask                    (0x00FF0000)
#define IM_DI_RTNR_C_TH4_TH6_cp_temporalthlc5_mask                    (0x0000FF00)
#define IM_DI_RTNR_C_TH4_TH6_cp_temporalthlc4_mask                    (0x000000FF)
#define IM_DI_RTNR_C_TH4_TH6_cp_temporalthlc6(data)                   (0x00FF0000&((data)<<16))
#define IM_DI_RTNR_C_TH4_TH6_cp_temporalthlc5(data)                   (0x0000FF00&((data)<<8))
#define IM_DI_RTNR_C_TH4_TH6_cp_temporalthlc4(data)                   (0x000000FF&(data))
#define IM_DI_RTNR_C_TH4_TH6_get_cp_temporalthlc6(data)               ((0x00FF0000&(data))>>16)
#define IM_DI_RTNR_C_TH4_TH6_get_cp_temporalthlc5(data)               ((0x0000FF00&(data))>>8)
#define IM_DI_RTNR_C_TH4_TH6_get_cp_temporalthlc4(data)               (0x000000FF&(data))


#define IM_DI_RTNR_Y_K                                                0x180242c0
#define IM_DI_RTNR_Y_K_reg_addr                                       "0xb80242c0"
#define IM_DI_RTNR_Y_K_reg                                            0xb80242c0
#define IM_DI_RTNR_Y_K_inst_addr                                      "0x00B0"
#define IM_DI_RTNR_Y_K_inst                                           0x00B0
#define IM_DI_RTNR_Y_K_cp_temporal_y_k7_shift                         (28)
#define IM_DI_RTNR_Y_K_cp_temporal_y_k6_shift                         (24)
#define IM_DI_RTNR_Y_K_cp_temporal_y_k5_shift                         (20)
#define IM_DI_RTNR_Y_K_cp_temporal_y_k4_shift                         (16)
#define IM_DI_RTNR_Y_K_cp_temporal_y_k3_shift                         (12)
#define IM_DI_RTNR_Y_K_cp_temporal_y_k2_shift                         (8)
#define IM_DI_RTNR_Y_K_cp_temporal_y_k1_shift                         (4)
#define IM_DI_RTNR_Y_K_cp_temporal_y_k0_shift                         (0)
#define IM_DI_RTNR_Y_K_cp_temporal_y_k7_mask                          (0x70000000)
#define IM_DI_RTNR_Y_K_cp_temporal_y_k6_mask                          (0x07000000)
#define IM_DI_RTNR_Y_K_cp_temporal_y_k5_mask                          (0x00700000)
#define IM_DI_RTNR_Y_K_cp_temporal_y_k4_mask                          (0x00070000)
#define IM_DI_RTNR_Y_K_cp_temporal_y_k3_mask                          (0x00007000)
#define IM_DI_RTNR_Y_K_cp_temporal_y_k2_mask                          (0x00000700)
#define IM_DI_RTNR_Y_K_cp_temporal_y_k1_mask                          (0x00000070)
#define IM_DI_RTNR_Y_K_cp_temporal_y_k0_mask                          (0x00000007)
#define IM_DI_RTNR_Y_K_cp_temporal_y_k7(data)                         (0x70000000&((data)<<28))
#define IM_DI_RTNR_Y_K_cp_temporal_y_k6(data)                         (0x07000000&((data)<<24))
#define IM_DI_RTNR_Y_K_cp_temporal_y_k5(data)                         (0x00700000&((data)<<20))
#define IM_DI_RTNR_Y_K_cp_temporal_y_k4(data)                         (0x00070000&((data)<<16))
#define IM_DI_RTNR_Y_K_cp_temporal_y_k3(data)                         (0x00007000&((data)<<12))
#define IM_DI_RTNR_Y_K_cp_temporal_y_k2(data)                         (0x00000700&((data)<<8))
#define IM_DI_RTNR_Y_K_cp_temporal_y_k1(data)                         (0x00000070&((data)<<4))
#define IM_DI_RTNR_Y_K_cp_temporal_y_k0(data)                         (0x00000007&(data))
#define IM_DI_RTNR_Y_K_get_cp_temporal_y_k7(data)                     ((0x70000000&(data))>>28)
#define IM_DI_RTNR_Y_K_get_cp_temporal_y_k6(data)                     ((0x07000000&(data))>>24)
#define IM_DI_RTNR_Y_K_get_cp_temporal_y_k5(data)                     ((0x00700000&(data))>>20)
#define IM_DI_RTNR_Y_K_get_cp_temporal_y_k4(data)                     ((0x00070000&(data))>>16)
#define IM_DI_RTNR_Y_K_get_cp_temporal_y_k3(data)                     ((0x00007000&(data))>>12)
#define IM_DI_RTNR_Y_K_get_cp_temporal_y_k2(data)                     ((0x00000700&(data))>>8)
#define IM_DI_RTNR_Y_K_get_cp_temporal_y_k1(data)                     ((0x00000070&(data))>>4)
#define IM_DI_RTNR_Y_K_get_cp_temporal_y_k0(data)                     (0x00000007&(data))


#define IM_DI_RTNR_C_K                                                0x180242c4
#define IM_DI_RTNR_C_K_reg_addr                                       "0xb80242c4"
#define IM_DI_RTNR_C_K_reg                                            0xb80242c4
#define IM_DI_RTNR_C_K_inst_addr                                      "0x00B1"
#define IM_DI_RTNR_C_K_inst                                           0x00B1
#define IM_DI_RTNR_C_K_cp_temporal_c_k7_shift                         (28)
#define IM_DI_RTNR_C_K_cp_temporal_c_k6_shift                         (24)
#define IM_DI_RTNR_C_K_cp_temporal_c_k5_shift                         (20)
#define IM_DI_RTNR_C_K_cp_temporal_c_k4_shift                         (16)
#define IM_DI_RTNR_C_K_cp_temporal_c_k3_shift                         (12)
#define IM_DI_RTNR_C_K_cp_temporal_c_k2_shift                         (8)
#define IM_DI_RTNR_C_K_cp_temporal_c_k1_shift                         (4)
#define IM_DI_RTNR_C_K_cp_temporal_c_k0_shift                         (0)
#define IM_DI_RTNR_C_K_cp_temporal_c_k7_mask                          (0x70000000)
#define IM_DI_RTNR_C_K_cp_temporal_c_k6_mask                          (0x07000000)
#define IM_DI_RTNR_C_K_cp_temporal_c_k5_mask                          (0x00700000)
#define IM_DI_RTNR_C_K_cp_temporal_c_k4_mask                          (0x00070000)
#define IM_DI_RTNR_C_K_cp_temporal_c_k3_mask                          (0x00007000)
#define IM_DI_RTNR_C_K_cp_temporal_c_k2_mask                          (0x00000700)
#define IM_DI_RTNR_C_K_cp_temporal_c_k1_mask                          (0x00000070)
#define IM_DI_RTNR_C_K_cp_temporal_c_k0_mask                          (0x00000007)
#define IM_DI_RTNR_C_K_cp_temporal_c_k7(data)                         (0x70000000&((data)<<28))
#define IM_DI_RTNR_C_K_cp_temporal_c_k6(data)                         (0x07000000&((data)<<24))
#define IM_DI_RTNR_C_K_cp_temporal_c_k5(data)                         (0x00700000&((data)<<20))
#define IM_DI_RTNR_C_K_cp_temporal_c_k4(data)                         (0x00070000&((data)<<16))
#define IM_DI_RTNR_C_K_cp_temporal_c_k3(data)                         (0x00007000&((data)<<12))
#define IM_DI_RTNR_C_K_cp_temporal_c_k2(data)                         (0x00000700&((data)<<8))
#define IM_DI_RTNR_C_K_cp_temporal_c_k1(data)                         (0x00000070&((data)<<4))
#define IM_DI_RTNR_C_K_cp_temporal_c_k0(data)                         (0x00000007&(data))
#define IM_DI_RTNR_C_K_get_cp_temporal_c_k7(data)                     ((0x70000000&(data))>>28)
#define IM_DI_RTNR_C_K_get_cp_temporal_c_k6(data)                     ((0x07000000&(data))>>24)
#define IM_DI_RTNR_C_K_get_cp_temporal_c_k5(data)                     ((0x00700000&(data))>>20)
#define IM_DI_RTNR_C_K_get_cp_temporal_c_k4(data)                     ((0x00070000&(data))>>16)
#define IM_DI_RTNR_C_K_get_cp_temporal_c_k3(data)                     ((0x00007000&(data))>>12)
#define IM_DI_RTNR_C_K_get_cp_temporal_c_k2(data)                     ((0x00000700&(data))>>8)
#define IM_DI_RTNR_C_K_get_cp_temporal_c_k1(data)                     ((0x00000070&(data))>>4)
#define IM_DI_RTNR_C_K_get_cp_temporal_c_k0(data)                     (0x00000007&(data))


#define IM_DI_RTNR_EDIFF_ENABLE                                       0x180242c8
#define IM_DI_RTNR_EDIFF_ENABLE_reg_addr                              "0xb80242c8"
#define IM_DI_RTNR_EDIFF_ENABLE_reg                                   0xb80242c8
#define IM_DI_RTNR_EDIFF_ENABLE_inst_addr                             "0x00B2"
#define IM_DI_RTNR_EDIFF_ENABLE_inst                                  0x00B2
#define IM_DI_RTNR_EDIFF_ENABLE_cp_temporal_y_k_decision_shift        (8)
#define IM_DI_RTNR_EDIFF_ENABLE_cp_temporal_ediff_en6_shift           (6)
#define IM_DI_RTNR_EDIFF_ENABLE_cp_temporal_ediff_en5_shift           (5)
#define IM_DI_RTNR_EDIFF_ENABLE_cp_temporal_ediff_en4_shift           (4)
#define IM_DI_RTNR_EDIFF_ENABLE_cp_temporal_ediff_en3_shift           (3)
#define IM_DI_RTNR_EDIFF_ENABLE_cp_temporal_ediff_en2_shift           (2)
#define IM_DI_RTNR_EDIFF_ENABLE_cp_temporal_ediff_en1_shift           (1)
#define IM_DI_RTNR_EDIFF_ENABLE_cp_temporal_ediff_en0_shift           (0)
#define IM_DI_RTNR_EDIFF_ENABLE_cp_temporal_y_k_decision_mask         (0x00000100)
#define IM_DI_RTNR_EDIFF_ENABLE_cp_temporal_ediff_en6_mask            (0x00000040)
#define IM_DI_RTNR_EDIFF_ENABLE_cp_temporal_ediff_en5_mask            (0x00000020)
#define IM_DI_RTNR_EDIFF_ENABLE_cp_temporal_ediff_en4_mask            (0x00000010)
#define IM_DI_RTNR_EDIFF_ENABLE_cp_temporal_ediff_en3_mask            (0x00000008)
#define IM_DI_RTNR_EDIFF_ENABLE_cp_temporal_ediff_en2_mask            (0x00000004)
#define IM_DI_RTNR_EDIFF_ENABLE_cp_temporal_ediff_en1_mask            (0x00000002)
#define IM_DI_RTNR_EDIFF_ENABLE_cp_temporal_ediff_en0_mask            (0x00000001)
#define IM_DI_RTNR_EDIFF_ENABLE_cp_temporal_y_k_decision(data)        (0x00000100&((data)<<8))
#define IM_DI_RTNR_EDIFF_ENABLE_cp_temporal_ediff_en6(data)           (0x00000040&((data)<<6))
#define IM_DI_RTNR_EDIFF_ENABLE_cp_temporal_ediff_en5(data)           (0x00000020&((data)<<5))
#define IM_DI_RTNR_EDIFF_ENABLE_cp_temporal_ediff_en4(data)           (0x00000010&((data)<<4))
#define IM_DI_RTNR_EDIFF_ENABLE_cp_temporal_ediff_en3(data)           (0x00000008&((data)<<3))
#define IM_DI_RTNR_EDIFF_ENABLE_cp_temporal_ediff_en2(data)           (0x00000004&((data)<<2))
#define IM_DI_RTNR_EDIFF_ENABLE_cp_temporal_ediff_en1(data)           (0x00000002&((data)<<1))
#define IM_DI_RTNR_EDIFF_ENABLE_cp_temporal_ediff_en0(data)           (0x00000001&(data))
#define IM_DI_RTNR_EDIFF_ENABLE_get_cp_temporal_y_k_decision(data)    ((0x00000100&(data))>>8)
#define IM_DI_RTNR_EDIFF_ENABLE_get_cp_temporal_ediff_en6(data)       ((0x00000040&(data))>>6)
#define IM_DI_RTNR_EDIFF_ENABLE_get_cp_temporal_ediff_en5(data)       ((0x00000020&(data))>>5)
#define IM_DI_RTNR_EDIFF_ENABLE_get_cp_temporal_ediff_en4(data)       ((0x00000010&(data))>>4)
#define IM_DI_RTNR_EDIFF_ENABLE_get_cp_temporal_ediff_en3(data)       ((0x00000008&(data))>>3)
#define IM_DI_RTNR_EDIFF_ENABLE_get_cp_temporal_ediff_en2(data)       ((0x00000004&(data))>>2)
#define IM_DI_RTNR_EDIFF_ENABLE_get_cp_temporal_ediff_en1(data)       ((0x00000002&(data))>>1)
#define IM_DI_RTNR_EDIFF_ENABLE_get_cp_temporal_ediff_en0(data)       (0x00000001&(data))


#define IM_DI_RTNR_NEW_CONTROL                                        0x180242d0
#define IM_DI_RTNR_NEW_CONTROL_reg_addr                               "0xb80242d0"
#define IM_DI_RTNR_NEW_CONTROL_reg                                    0xb80242d0
#define IM_DI_RTNR_NEW_CONTROL_inst_addr                              "0x00B4"
#define IM_DI_RTNR_NEW_CONTROL_inst                                   0x00B4
#define IM_DI_RTNR_NEW_CONTROL_rtnr_debugmode_shift                   (20)
#define IM_DI_RTNR_NEW_CONTROL_rtnr_moredetail_cotinue_en_shift       (18)
#define IM_DI_RTNR_NEW_CONTROL_rtnr_k_temporal_compare_snr_shift      (17)
#define IM_DI_RTNR_NEW_CONTROL_rtnr_k_temporal_compare_en_shift       (16)
#define IM_DI_RTNR_NEW_CONTROL_rtnr_statistic_motion_sad_th_shift     (8)
#define IM_DI_RTNR_NEW_CONTROL_rtnr_sad_mix_cal_weight_shift          (4)
#define IM_DI_RTNR_NEW_CONTROL_rtnr_sad_method_shift                  (1)
#define IM_DI_RTNR_NEW_CONTROL_rtnr_new_method_en_shift               (0)
#define IM_DI_RTNR_NEW_CONTROL_rtnr_debugmode_mask                    (0x00F00000)
#define IM_DI_RTNR_NEW_CONTROL_rtnr_moredetail_cotinue_en_mask        (0x00040000)
#define IM_DI_RTNR_NEW_CONTROL_rtnr_k_temporal_compare_snr_mask       (0x00020000)
#define IM_DI_RTNR_NEW_CONTROL_rtnr_k_temporal_compare_en_mask        (0x00010000)
#define IM_DI_RTNR_NEW_CONTROL_rtnr_statistic_motion_sad_th_mask      (0x0000FF00)
#define IM_DI_RTNR_NEW_CONTROL_rtnr_sad_mix_cal_weight_mask           (0x000000F0)
#define IM_DI_RTNR_NEW_CONTROL_rtnr_sad_method_mask                   (0x00000006)
#define IM_DI_RTNR_NEW_CONTROL_rtnr_new_method_en_mask                (0x00000001)
#define IM_DI_RTNR_NEW_CONTROL_rtnr_debugmode(data)                   (0x00F00000&((data)<<20))
#define IM_DI_RTNR_NEW_CONTROL_rtnr_moredetail_cotinue_en(data)       (0x00040000&((data)<<18))
#define IM_DI_RTNR_NEW_CONTROL_rtnr_k_temporal_compare_snr(data)      (0x00020000&((data)<<17))
#define IM_DI_RTNR_NEW_CONTROL_rtnr_k_temporal_compare_en(data)       (0x00010000&((data)<<16))
#define IM_DI_RTNR_NEW_CONTROL_rtnr_statistic_motion_sad_th(data)     (0x0000FF00&((data)<<8))
#define IM_DI_RTNR_NEW_CONTROL_rtnr_sad_mix_cal_weight(data)          (0x000000F0&((data)<<4))
#define IM_DI_RTNR_NEW_CONTROL_rtnr_sad_method(data)                  (0x00000006&((data)<<1))
#define IM_DI_RTNR_NEW_CONTROL_rtnr_new_method_en(data)               (0x00000001&(data))
#define IM_DI_RTNR_NEW_CONTROL_get_rtnr_debugmode(data)               ((0x00F00000&(data))>>20)
#define IM_DI_RTNR_NEW_CONTROL_get_rtnr_moredetail_cotinue_en(data)   ((0x00040000&(data))>>18)
#define IM_DI_RTNR_NEW_CONTROL_get_rtnr_k_temporal_compare_snr(data)  ((0x00020000&(data))>>17)
#define IM_DI_RTNR_NEW_CONTROL_get_rtnr_k_temporal_compare_en(data)   ((0x00010000&(data))>>16)
#define IM_DI_RTNR_NEW_CONTROL_get_rtnr_statistic_motion_sad_th(data) ((0x0000FF00&(data))>>8)
#define IM_DI_RTNR_NEW_CONTROL_get_rtnr_sad_mix_cal_weight(data)      ((0x000000F0&(data))>>4)
#define IM_DI_RTNR_NEW_CONTROL_get_rtnr_sad_method(data)              ((0x00000006&(data))>>1)
#define IM_DI_RTNR_NEW_CONTROL_get_rtnr_new_method_en(data)           (0x00000001&(data))


#define IM_DI_RTNR_NEW_SOBEL_TH                                       0x180242d4
#define IM_DI_RTNR_NEW_SOBEL_TH_reg_addr                              "0xb80242d4"
#define IM_DI_RTNR_NEW_SOBEL_TH_reg                                   0xb80242d4
#define IM_DI_RTNR_NEW_SOBEL_TH_inst_addr                             "0x00B5"
#define IM_DI_RTNR_NEW_SOBEL_TH_inst                                  0x00B5
#define IM_DI_RTNR_NEW_SOBEL_TH_rtnr_sobel_method_shift               (22)
#define IM_DI_RTNR_NEW_SOBEL_TH_rtnr_sbl_thm_y_shift                  (12)
#define IM_DI_RTNR_NEW_SOBEL_TH_rtnr_sbl_ths_y_shift                  (0)
#define IM_DI_RTNR_NEW_SOBEL_TH_rtnr_sobel_method_mask                (0x00C00000)
#define IM_DI_RTNR_NEW_SOBEL_TH_rtnr_sbl_thm_y_mask                   (0x003FF000)
#define IM_DI_RTNR_NEW_SOBEL_TH_rtnr_sbl_ths_y_mask                   (0x000003FF)
#define IM_DI_RTNR_NEW_SOBEL_TH_rtnr_sobel_method(data)               (0x00C00000&((data)<<22))
#define IM_DI_RTNR_NEW_SOBEL_TH_rtnr_sbl_thm_y(data)                  (0x003FF000&((data)<<12))
#define IM_DI_RTNR_NEW_SOBEL_TH_rtnr_sbl_ths_y(data)                  (0x000003FF&(data))
#define IM_DI_RTNR_NEW_SOBEL_TH_get_rtnr_sobel_method(data)           ((0x00C00000&(data))>>22)
#define IM_DI_RTNR_NEW_SOBEL_TH_get_rtnr_sbl_thm_y(data)              ((0x003FF000&(data))>>12)
#define IM_DI_RTNR_NEW_SOBEL_TH_get_rtnr_sbl_ths_y(data)              (0x000003FF&(data))


#define IM_DI_RTNR_NEW_SAD_EDGE_TH_1                                  0x180242d8
#define IM_DI_RTNR_NEW_SAD_EDGE_TH_1_reg_addr                         "0xb80242d8"
#define IM_DI_RTNR_NEW_SAD_EDGE_TH_1_reg                              0xb80242d8
#define IM_DI_RTNR_NEW_SAD_EDGE_TH_1_inst_addr                        "0x00B6"
#define IM_DI_RTNR_NEW_SAD_EDGE_TH_1_inst                             0x00B6
#define IM_DI_RTNR_NEW_SAD_EDGE_TH_1_rtnr_calculate_motion_sad_edge_th4_shift  (24)
#define IM_DI_RTNR_NEW_SAD_EDGE_TH_1_rtnr_calculate_motion_sad_edge_th3_shift  (16)
#define IM_DI_RTNR_NEW_SAD_EDGE_TH_1_rtnr_calculate_motion_sad_edge_th2_shift  (8)
#define IM_DI_RTNR_NEW_SAD_EDGE_TH_1_rtnr_calculate_motion_sad_edge_th1_shift  (0)
#define IM_DI_RTNR_NEW_SAD_EDGE_TH_1_rtnr_calculate_motion_sad_edge_th4_mask  (0xFF000000)
#define IM_DI_RTNR_NEW_SAD_EDGE_TH_1_rtnr_calculate_motion_sad_edge_th3_mask  (0x00FF0000)
#define IM_DI_RTNR_NEW_SAD_EDGE_TH_1_rtnr_calculate_motion_sad_edge_th2_mask  (0x0000FF00)
#define IM_DI_RTNR_NEW_SAD_EDGE_TH_1_rtnr_calculate_motion_sad_edge_th1_mask  (0x000000FF)
#define IM_DI_RTNR_NEW_SAD_EDGE_TH_1_rtnr_calculate_motion_sad_edge_th4(data)  (0xFF000000&((data)<<24))
#define IM_DI_RTNR_NEW_SAD_EDGE_TH_1_rtnr_calculate_motion_sad_edge_th3(data)  (0x00FF0000&((data)<<16))
#define IM_DI_RTNR_NEW_SAD_EDGE_TH_1_rtnr_calculate_motion_sad_edge_th2(data)  (0x0000FF00&((data)<<8))
#define IM_DI_RTNR_NEW_SAD_EDGE_TH_1_rtnr_calculate_motion_sad_edge_th1(data)  (0x000000FF&(data))
#define IM_DI_RTNR_NEW_SAD_EDGE_TH_1_get_rtnr_calculate_motion_sad_edge_th4(data)  ((0xFF000000&(data))>>24)
#define IM_DI_RTNR_NEW_SAD_EDGE_TH_1_get_rtnr_calculate_motion_sad_edge_th3(data)  ((0x00FF0000&(data))>>16)
#define IM_DI_RTNR_NEW_SAD_EDGE_TH_1_get_rtnr_calculate_motion_sad_edge_th2(data)  ((0x0000FF00&(data))>>8)
#define IM_DI_RTNR_NEW_SAD_EDGE_TH_1_get_rtnr_calculate_motion_sad_edge_th1(data)  (0x000000FF&(data))


#define IM_DI_RTNR_NEW_SAD_EDGE_TH_2                                  0x180242dc
#define IM_DI_RTNR_NEW_SAD_EDGE_TH_2_reg_addr                         "0xb80242dc"
#define IM_DI_RTNR_NEW_SAD_EDGE_TH_2_reg                              0xb80242dc
#define IM_DI_RTNR_NEW_SAD_EDGE_TH_2_inst_addr                        "0x00B7"
#define IM_DI_RTNR_NEW_SAD_EDGE_TH_2_inst                             0x00B7
#define IM_DI_RTNR_NEW_SAD_EDGE_TH_2_rtnr_calculate_motion_sad_edge_th7_shift  (16)
#define IM_DI_RTNR_NEW_SAD_EDGE_TH_2_rtnr_calculate_motion_sad_edge_th6_shift  (8)
#define IM_DI_RTNR_NEW_SAD_EDGE_TH_2_rtnr_calculate_motion_sad_edge_th5_shift  (0)
#define IM_DI_RTNR_NEW_SAD_EDGE_TH_2_rtnr_calculate_motion_sad_edge_th7_mask  (0x00FF0000)
#define IM_DI_RTNR_NEW_SAD_EDGE_TH_2_rtnr_calculate_motion_sad_edge_th6_mask  (0x0000FF00)
#define IM_DI_RTNR_NEW_SAD_EDGE_TH_2_rtnr_calculate_motion_sad_edge_th5_mask  (0x000000FF)
#define IM_DI_RTNR_NEW_SAD_EDGE_TH_2_rtnr_calculate_motion_sad_edge_th7(data)  (0x00FF0000&((data)<<16))
#define IM_DI_RTNR_NEW_SAD_EDGE_TH_2_rtnr_calculate_motion_sad_edge_th6(data)  (0x0000FF00&((data)<<8))
#define IM_DI_RTNR_NEW_SAD_EDGE_TH_2_rtnr_calculate_motion_sad_edge_th5(data)  (0x000000FF&(data))
#define IM_DI_RTNR_NEW_SAD_EDGE_TH_2_get_rtnr_calculate_motion_sad_edge_th7(data)  ((0x00FF0000&(data))>>16)
#define IM_DI_RTNR_NEW_SAD_EDGE_TH_2_get_rtnr_calculate_motion_sad_edge_th6(data)  ((0x0000FF00&(data))>>8)
#define IM_DI_RTNR_NEW_SAD_EDGE_TH_2_get_rtnr_calculate_motion_sad_edge_th5(data)  (0x000000FF&(data))


#define IM_DI_RTNR_NEW_SAD_NONEDGE_TH_1                               0x180242e0
#define IM_DI_RTNR_NEW_SAD_NONEDGE_TH_1_reg_addr                      "0xb80242e0"
#define IM_DI_RTNR_NEW_SAD_NONEDGE_TH_1_reg                           0xb80242e0
#define IM_DI_RTNR_NEW_SAD_NONEDGE_TH_1_inst_addr                     "0x00B8"
#define IM_DI_RTNR_NEW_SAD_NONEDGE_TH_1_inst                          0x00B8
#define IM_DI_RTNR_NEW_SAD_NONEDGE_TH_1_rtnr_calculate_motion_sad_nonedge_th4_shift  (24)
#define IM_DI_RTNR_NEW_SAD_NONEDGE_TH_1_rtnr_calculate_motion_sad_nonedge_th3_shift  (16)
#define IM_DI_RTNR_NEW_SAD_NONEDGE_TH_1_rtnr_calculate_motion_sad_nonedge_th2_shift  (8)
#define IM_DI_RTNR_NEW_SAD_NONEDGE_TH_1_rtnr_calculate_motion_sad_nonedge_th1_shift  (0)
#define IM_DI_RTNR_NEW_SAD_NONEDGE_TH_1_rtnr_calculate_motion_sad_nonedge_th4_mask  (0xFF000000)
#define IM_DI_RTNR_NEW_SAD_NONEDGE_TH_1_rtnr_calculate_motion_sad_nonedge_th3_mask  (0x00FF0000)
#define IM_DI_RTNR_NEW_SAD_NONEDGE_TH_1_rtnr_calculate_motion_sad_nonedge_th2_mask  (0x0000FF00)
#define IM_DI_RTNR_NEW_SAD_NONEDGE_TH_1_rtnr_calculate_motion_sad_nonedge_th1_mask  (0x000000FF)
#define IM_DI_RTNR_NEW_SAD_NONEDGE_TH_1_rtnr_calculate_motion_sad_nonedge_th4(data)  (0xFF000000&((data)<<24))
#define IM_DI_RTNR_NEW_SAD_NONEDGE_TH_1_rtnr_calculate_motion_sad_nonedge_th3(data)  (0x00FF0000&((data)<<16))
#define IM_DI_RTNR_NEW_SAD_NONEDGE_TH_1_rtnr_calculate_motion_sad_nonedge_th2(data)  (0x0000FF00&((data)<<8))
#define IM_DI_RTNR_NEW_SAD_NONEDGE_TH_1_rtnr_calculate_motion_sad_nonedge_th1(data)  (0x000000FF&(data))
#define IM_DI_RTNR_NEW_SAD_NONEDGE_TH_1_get_rtnr_calculate_motion_sad_nonedge_th4(data)  ((0xFF000000&(data))>>24)
#define IM_DI_RTNR_NEW_SAD_NONEDGE_TH_1_get_rtnr_calculate_motion_sad_nonedge_th3(data)  ((0x00FF0000&(data))>>16)
#define IM_DI_RTNR_NEW_SAD_NONEDGE_TH_1_get_rtnr_calculate_motion_sad_nonedge_th2(data)  ((0x0000FF00&(data))>>8)
#define IM_DI_RTNR_NEW_SAD_NONEDGE_TH_1_get_rtnr_calculate_motion_sad_nonedge_th1(data)  (0x000000FF&(data))


#define IM_DI_RTNR_NEW_SAD_NONEDGE_TH_2                               0x180242e4
#define IM_DI_RTNR_NEW_SAD_NONEDGE_TH_2_reg_addr                      "0xb80242e4"
#define IM_DI_RTNR_NEW_SAD_NONEDGE_TH_2_reg                           0xb80242e4
#define IM_DI_RTNR_NEW_SAD_NONEDGE_TH_2_inst_addr                     "0x00B9"
#define IM_DI_RTNR_NEW_SAD_NONEDGE_TH_2_inst                          0x00B9
#define IM_DI_RTNR_NEW_SAD_NONEDGE_TH_2_rtnr_calculate_motion_sad_nonedge_th7_shift  (16)
#define IM_DI_RTNR_NEW_SAD_NONEDGE_TH_2_rtnr_calculate_motion_sad_nonedge_th6_shift  (8)
#define IM_DI_RTNR_NEW_SAD_NONEDGE_TH_2_rtnr_calculate_motion_sad_nonedge_th5_shift  (0)
#define IM_DI_RTNR_NEW_SAD_NONEDGE_TH_2_rtnr_calculate_motion_sad_nonedge_th7_mask  (0x00FF0000)
#define IM_DI_RTNR_NEW_SAD_NONEDGE_TH_2_rtnr_calculate_motion_sad_nonedge_th6_mask  (0x0000FF00)
#define IM_DI_RTNR_NEW_SAD_NONEDGE_TH_2_rtnr_calculate_motion_sad_nonedge_th5_mask  (0x000000FF)
#define IM_DI_RTNR_NEW_SAD_NONEDGE_TH_2_rtnr_calculate_motion_sad_nonedge_th7(data)  (0x00FF0000&((data)<<16))
#define IM_DI_RTNR_NEW_SAD_NONEDGE_TH_2_rtnr_calculate_motion_sad_nonedge_th6(data)  (0x0000FF00&((data)<<8))
#define IM_DI_RTNR_NEW_SAD_NONEDGE_TH_2_rtnr_calculate_motion_sad_nonedge_th5(data)  (0x000000FF&(data))
#define IM_DI_RTNR_NEW_SAD_NONEDGE_TH_2_get_rtnr_calculate_motion_sad_nonedge_th7(data)  ((0x00FF0000&(data))>>16)
#define IM_DI_RTNR_NEW_SAD_NONEDGE_TH_2_get_rtnr_calculate_motion_sad_nonedge_th6(data)  ((0x0000FF00&(data))>>8)
#define IM_DI_RTNR_NEW_SAD_NONEDGE_TH_2_get_rtnr_calculate_motion_sad_nonedge_th5(data)  (0x000000FF&(data))


#define IM_DI_RTNR_NEW_SAD_COUNT_TH                                   0x180242e8
#define IM_DI_RTNR_NEW_SAD_COUNT_TH_reg_addr                          "0xb80242e8"
#define IM_DI_RTNR_NEW_SAD_COUNT_TH_reg                               0xb80242e8
#define IM_DI_RTNR_NEW_SAD_COUNT_TH_inst_addr                         "0x00BA"
#define IM_DI_RTNR_NEW_SAD_COUNT_TH_inst                              0x00BA
#define IM_DI_RTNR_NEW_SAD_COUNT_TH_rtnr_statistic_motion_count_th7_shift  (24)
#define IM_DI_RTNR_NEW_SAD_COUNT_TH_rtnr_statistic_motion_count_th6_shift  (20)
#define IM_DI_RTNR_NEW_SAD_COUNT_TH_rtnr_statistic_motion_count_th5_shift  (16)
#define IM_DI_RTNR_NEW_SAD_COUNT_TH_rtnr_statistic_motion_count_th4_shift  (12)
#define IM_DI_RTNR_NEW_SAD_COUNT_TH_rtnr_statistic_motion_count_th3_shift  (8)
#define IM_DI_RTNR_NEW_SAD_COUNT_TH_rtnr_statistic_motion_count_th2_shift  (4)
#define IM_DI_RTNR_NEW_SAD_COUNT_TH_rtnr_statistic_motion_count_th1_shift  (0)
#define IM_DI_RTNR_NEW_SAD_COUNT_TH_rtnr_statistic_motion_count_th7_mask  (0x0F000000)
#define IM_DI_RTNR_NEW_SAD_COUNT_TH_rtnr_statistic_motion_count_th6_mask  (0x00F00000)
#define IM_DI_RTNR_NEW_SAD_COUNT_TH_rtnr_statistic_motion_count_th5_mask  (0x000F0000)
#define IM_DI_RTNR_NEW_SAD_COUNT_TH_rtnr_statistic_motion_count_th4_mask  (0x0000F000)
#define IM_DI_RTNR_NEW_SAD_COUNT_TH_rtnr_statistic_motion_count_th3_mask  (0x00000F00)
#define IM_DI_RTNR_NEW_SAD_COUNT_TH_rtnr_statistic_motion_count_th2_mask  (0x000000F0)
#define IM_DI_RTNR_NEW_SAD_COUNT_TH_rtnr_statistic_motion_count_th1_mask  (0x0000000F)
#define IM_DI_RTNR_NEW_SAD_COUNT_TH_rtnr_statistic_motion_count_th7(data)  (0x0F000000&((data)<<24))
#define IM_DI_RTNR_NEW_SAD_COUNT_TH_rtnr_statistic_motion_count_th6(data)  (0x00F00000&((data)<<20))
#define IM_DI_RTNR_NEW_SAD_COUNT_TH_rtnr_statistic_motion_count_th5(data)  (0x000F0000&((data)<<16))
#define IM_DI_RTNR_NEW_SAD_COUNT_TH_rtnr_statistic_motion_count_th4(data)  (0x0000F000&((data)<<12))
#define IM_DI_RTNR_NEW_SAD_COUNT_TH_rtnr_statistic_motion_count_th3(data)  (0x00000F00&((data)<<8))
#define IM_DI_RTNR_NEW_SAD_COUNT_TH_rtnr_statistic_motion_count_th2(data)  (0x000000F0&((data)<<4))
#define IM_DI_RTNR_NEW_SAD_COUNT_TH_rtnr_statistic_motion_count_th1(data)  (0x0000000F&(data))
#define IM_DI_RTNR_NEW_SAD_COUNT_TH_get_rtnr_statistic_motion_count_th7(data)  ((0x0F000000&(data))>>24)
#define IM_DI_RTNR_NEW_SAD_COUNT_TH_get_rtnr_statistic_motion_count_th6(data)  ((0x00F00000&(data))>>20)
#define IM_DI_RTNR_NEW_SAD_COUNT_TH_get_rtnr_statistic_motion_count_th5(data)  ((0x000F0000&(data))>>16)
#define IM_DI_RTNR_NEW_SAD_COUNT_TH_get_rtnr_statistic_motion_count_th4(data)  ((0x0000F000&(data))>>12)
#define IM_DI_RTNR_NEW_SAD_COUNT_TH_get_rtnr_statistic_motion_count_th3(data)  ((0x00000F00&(data))>>8)
#define IM_DI_RTNR_NEW_SAD_COUNT_TH_get_rtnr_statistic_motion_count_th2(data)  ((0x000000F0&(data))>>4)
#define IM_DI_RTNR_NEW_SAD_COUNT_TH_get_rtnr_statistic_motion_count_th1(data)  (0x0000000F&(data))


#define IM_DI_RTNR_NEW_EDGETYPEDIFF_TH_1                              0x180242ec
#define IM_DI_RTNR_NEW_EDGETYPEDIFF_TH_1_reg_addr                     "0xb80242ec"
#define IM_DI_RTNR_NEW_EDGETYPEDIFF_TH_1_reg                          0xb80242ec
#define IM_DI_RTNR_NEW_EDGETYPEDIFF_TH_1_inst_addr                    "0x00BB"
#define IM_DI_RTNR_NEW_EDGETYPEDIFF_TH_1_inst                         0x00BB
#define IM_DI_RTNR_NEW_EDGETYPEDIFF_TH_1_rtnr_edgetypediff_count_th4_shift  (24)
#define IM_DI_RTNR_NEW_EDGETYPEDIFF_TH_1_rtnr_edgetypediff_count_th3_shift  (16)
#define IM_DI_RTNR_NEW_EDGETYPEDIFF_TH_1_rtnr_edgetypediff_count_th2_shift  (8)
#define IM_DI_RTNR_NEW_EDGETYPEDIFF_TH_1_rtnr_edgetypediff_count_th1_shift  (0)
#define IM_DI_RTNR_NEW_EDGETYPEDIFF_TH_1_rtnr_edgetypediff_count_th4_mask  (0x3F000000)
#define IM_DI_RTNR_NEW_EDGETYPEDIFF_TH_1_rtnr_edgetypediff_count_th3_mask  (0x003F0000)
#define IM_DI_RTNR_NEW_EDGETYPEDIFF_TH_1_rtnr_edgetypediff_count_th2_mask  (0x00003F00)
#define IM_DI_RTNR_NEW_EDGETYPEDIFF_TH_1_rtnr_edgetypediff_count_th1_mask  (0x0000003F)
#define IM_DI_RTNR_NEW_EDGETYPEDIFF_TH_1_rtnr_edgetypediff_count_th4(data)  (0x3F000000&((data)<<24))
#define IM_DI_RTNR_NEW_EDGETYPEDIFF_TH_1_rtnr_edgetypediff_count_th3(data)  (0x003F0000&((data)<<16))
#define IM_DI_RTNR_NEW_EDGETYPEDIFF_TH_1_rtnr_edgetypediff_count_th2(data)  (0x00003F00&((data)<<8))
#define IM_DI_RTNR_NEW_EDGETYPEDIFF_TH_1_rtnr_edgetypediff_count_th1(data)  (0x0000003F&(data))
#define IM_DI_RTNR_NEW_EDGETYPEDIFF_TH_1_get_rtnr_edgetypediff_count_th4(data)  ((0x3F000000&(data))>>24)
#define IM_DI_RTNR_NEW_EDGETYPEDIFF_TH_1_get_rtnr_edgetypediff_count_th3(data)  ((0x003F0000&(data))>>16)
#define IM_DI_RTNR_NEW_EDGETYPEDIFF_TH_1_get_rtnr_edgetypediff_count_th2(data)  ((0x00003F00&(data))>>8)
#define IM_DI_RTNR_NEW_EDGETYPEDIFF_TH_1_get_rtnr_edgetypediff_count_th1(data)  (0x0000003F&(data))


#define IM_DI_RTNR_NEW_EDGETYPEDIFF_TH_2                              0x180242f0
#define IM_DI_RTNR_NEW_EDGETYPEDIFF_TH_2_reg_addr                     "0xb80242f0"
#define IM_DI_RTNR_NEW_EDGETYPEDIFF_TH_2_reg                          0xb80242f0
#define IM_DI_RTNR_NEW_EDGETYPEDIFF_TH_2_inst_addr                    "0x00BC"
#define IM_DI_RTNR_NEW_EDGETYPEDIFF_TH_2_inst                         0x00BC
#define IM_DI_RTNR_NEW_EDGETYPEDIFF_TH_2_rtnr_edgetypediff_count_th7_shift  (16)
#define IM_DI_RTNR_NEW_EDGETYPEDIFF_TH_2_rtnr_edgetypediff_count_th6_shift  (8)
#define IM_DI_RTNR_NEW_EDGETYPEDIFF_TH_2_rtnr_edgetypediff_count_th5_shift  (0)
#define IM_DI_RTNR_NEW_EDGETYPEDIFF_TH_2_rtnr_edgetypediff_count_th7_mask  (0x003F0000)
#define IM_DI_RTNR_NEW_EDGETYPEDIFF_TH_2_rtnr_edgetypediff_count_th6_mask  (0x00003F00)
#define IM_DI_RTNR_NEW_EDGETYPEDIFF_TH_2_rtnr_edgetypediff_count_th5_mask  (0x0000003F)
#define IM_DI_RTNR_NEW_EDGETYPEDIFF_TH_2_rtnr_edgetypediff_count_th7(data)  (0x003F0000&((data)<<16))
#define IM_DI_RTNR_NEW_EDGETYPEDIFF_TH_2_rtnr_edgetypediff_count_th6(data)  (0x00003F00&((data)<<8))
#define IM_DI_RTNR_NEW_EDGETYPEDIFF_TH_2_rtnr_edgetypediff_count_th5(data)  (0x0000003F&(data))
#define IM_DI_RTNR_NEW_EDGETYPEDIFF_TH_2_get_rtnr_edgetypediff_count_th7(data)  ((0x003F0000&(data))>>16)
#define IM_DI_RTNR_NEW_EDGETYPEDIFF_TH_2_get_rtnr_edgetypediff_count_th6(data)  ((0x00003F00&(data))>>8)
#define IM_DI_RTNR_NEW_EDGETYPEDIFF_TH_2_get_rtnr_edgetypediff_count_th5(data)  (0x0000003F&(data))


#define IM_DI_RTNR_NEW_SNR_CONTROL                                    0x180242f4
#define IM_DI_RTNR_NEW_SNR_CONTROL_reg_addr                           "0xb80242f4"
#define IM_DI_RTNR_NEW_SNR_CONTROL_reg                                0xb80242f4
#define IM_DI_RTNR_NEW_SNR_CONTROL_inst_addr                          "0x00BD"
#define IM_DI_RTNR_NEW_SNR_CONTROL_inst                               0x00BD
#define IM_DI_RTNR_NEW_SNR_CONTROL_rtnr_snr_mask_shift                (20)
#define IM_DI_RTNR_NEW_SNR_CONTROL_rtnr_snr_result_offset_shift       (17)
#define IM_DI_RTNR_NEW_SNR_CONTROL_rtnr_snr_result_offset_invert_en_shift  (16)
#define IM_DI_RTNR_NEW_SNR_CONTROL_rtnr_snr_result_motion_weight_shift  (12)
#define IM_DI_RTNR_NEW_SNR_CONTROL_rtnr_snr_result_edgestatus_weight_shift  (8)
#define IM_DI_RTNR_NEW_SNR_CONTROL_rtnr_snr_result_motion_invert_en_shift  (5)
#define IM_DI_RTNR_NEW_SNR_CONTROL_rtnr_snr_result_edgestatus_invert_en_shift  (4)
#define IM_DI_RTNR_NEW_SNR_CONTROL_rtnr_snr_sobel_3_en_shift          (3)
#define IM_DI_RTNR_NEW_SNR_CONTROL_rtnr_snr_sobel_2_en_shift          (2)
#define IM_DI_RTNR_NEW_SNR_CONTROL_rtnr_snr_sobel_1_en_shift          (1)
#define IM_DI_RTNR_NEW_SNR_CONTROL_rtnr_snr_en_shift                  (0)
#define IM_DI_RTNR_NEW_SNR_CONTROL_rtnr_snr_mask_mask                 (0x00100000)
#define IM_DI_RTNR_NEW_SNR_CONTROL_rtnr_snr_result_offset_mask        (0x000E0000)
#define IM_DI_RTNR_NEW_SNR_CONTROL_rtnr_snr_result_offset_invert_en_mask  (0x00010000)
#define IM_DI_RTNR_NEW_SNR_CONTROL_rtnr_snr_result_motion_weight_mask (0x0000F000)
#define IM_DI_RTNR_NEW_SNR_CONTROL_rtnr_snr_result_edgestatus_weight_mask  (0x00000F00)
#define IM_DI_RTNR_NEW_SNR_CONTROL_rtnr_snr_result_motion_invert_en_mask  (0x00000020)
#define IM_DI_RTNR_NEW_SNR_CONTROL_rtnr_snr_result_edgestatus_invert_en_mask  (0x00000010)
#define IM_DI_RTNR_NEW_SNR_CONTROL_rtnr_snr_sobel_3_en_mask           (0x00000008)
#define IM_DI_RTNR_NEW_SNR_CONTROL_rtnr_snr_sobel_2_en_mask           (0x00000004)
#define IM_DI_RTNR_NEW_SNR_CONTROL_rtnr_snr_sobel_1_en_mask           (0x00000002)
#define IM_DI_RTNR_NEW_SNR_CONTROL_rtnr_snr_en_mask                   (0x00000001)
#define IM_DI_RTNR_NEW_SNR_CONTROL_rtnr_snr_mask(data)                (0x00100000&((data)<<20))
#define IM_DI_RTNR_NEW_SNR_CONTROL_rtnr_snr_result_offset(data)       (0x000E0000&((data)<<17))
#define IM_DI_RTNR_NEW_SNR_CONTROL_rtnr_snr_result_offset_invert_en(data)  (0x00010000&((data)<<16))
#define IM_DI_RTNR_NEW_SNR_CONTROL_rtnr_snr_result_motion_weight(data)  (0x0000F000&((data)<<12))
#define IM_DI_RTNR_NEW_SNR_CONTROL_rtnr_snr_result_edgestatus_weight(data)  (0x00000F00&((data)<<8))
#define IM_DI_RTNR_NEW_SNR_CONTROL_rtnr_snr_result_motion_invert_en(data)  (0x00000020&((data)<<5))
#define IM_DI_RTNR_NEW_SNR_CONTROL_rtnr_snr_result_edgestatus_invert_en(data)  (0x00000010&((data)<<4))
#define IM_DI_RTNR_NEW_SNR_CONTROL_rtnr_snr_sobel_3_en(data)          (0x00000008&((data)<<3))
#define IM_DI_RTNR_NEW_SNR_CONTROL_rtnr_snr_sobel_2_en(data)          (0x00000004&((data)<<2))
#define IM_DI_RTNR_NEW_SNR_CONTROL_rtnr_snr_sobel_1_en(data)          (0x00000002&((data)<<1))
#define IM_DI_RTNR_NEW_SNR_CONTROL_rtnr_snr_en(data)                  (0x00000001&(data))
#define IM_DI_RTNR_NEW_SNR_CONTROL_get_rtnr_snr_mask(data)            ((0x00100000&(data))>>20)
#define IM_DI_RTNR_NEW_SNR_CONTROL_get_rtnr_snr_result_offset(data)   ((0x000E0000&(data))>>17)
#define IM_DI_RTNR_NEW_SNR_CONTROL_get_rtnr_snr_result_offset_invert_en(data)  ((0x00010000&(data))>>16)
#define IM_DI_RTNR_NEW_SNR_CONTROL_get_rtnr_snr_result_motion_weight(data)  ((0x0000F000&(data))>>12)
#define IM_DI_RTNR_NEW_SNR_CONTROL_get_rtnr_snr_result_edgestatus_weight(data)  ((0x00000F00&(data))>>8)
#define IM_DI_RTNR_NEW_SNR_CONTROL_get_rtnr_snr_result_motion_invert_en(data)  ((0x00000020&(data))>>5)
#define IM_DI_RTNR_NEW_SNR_CONTROL_get_rtnr_snr_result_edgestatus_invert_en(data)  ((0x00000010&(data))>>4)
#define IM_DI_RTNR_NEW_SNR_CONTROL_get_rtnr_snr_sobel_3_en(data)      ((0x00000008&(data))>>3)
#define IM_DI_RTNR_NEW_SNR_CONTROL_get_rtnr_snr_sobel_2_en(data)      ((0x00000004&(data))>>2)
#define IM_DI_RTNR_NEW_SNR_CONTROL_get_rtnr_snr_sobel_1_en(data)      ((0x00000002&(data))>>1)
#define IM_DI_RTNR_NEW_SNR_CONTROL_get_rtnr_snr_en(data)              (0x00000001&(data))


#define IM_DI_RTNR_NEW_SNR_TH_1                                       0x180242f8
#define IM_DI_RTNR_NEW_SNR_TH_1_reg_addr                              "0xb80242f8"
#define IM_DI_RTNR_NEW_SNR_TH_1_reg                                   0xb80242f8
#define IM_DI_RTNR_NEW_SNR_TH_1_inst_addr                             "0x00BE"
#define IM_DI_RTNR_NEW_SNR_TH_1_inst                                  0x00BE
#define IM_DI_RTNR_NEW_SNR_TH_1_rtnr_snr_edgestatus_th4_shift         (24)
#define IM_DI_RTNR_NEW_SNR_TH_1_rtnr_snr_edgestatus_th3_shift         (16)
#define IM_DI_RTNR_NEW_SNR_TH_1_rtnr_snr_edgestatus_th2_shift         (8)
#define IM_DI_RTNR_NEW_SNR_TH_1_rtnr_snr_edgestatus_th1_shift         (0)
#define IM_DI_RTNR_NEW_SNR_TH_1_rtnr_snr_edgestatus_th4_mask          (0xFF000000)
#define IM_DI_RTNR_NEW_SNR_TH_1_rtnr_snr_edgestatus_th3_mask          (0x00FF0000)
#define IM_DI_RTNR_NEW_SNR_TH_1_rtnr_snr_edgestatus_th2_mask          (0x0000FF00)
#define IM_DI_RTNR_NEW_SNR_TH_1_rtnr_snr_edgestatus_th1_mask          (0x000000FF)
#define IM_DI_RTNR_NEW_SNR_TH_1_rtnr_snr_edgestatus_th4(data)         (0xFF000000&((data)<<24))
#define IM_DI_RTNR_NEW_SNR_TH_1_rtnr_snr_edgestatus_th3(data)         (0x00FF0000&((data)<<16))
#define IM_DI_RTNR_NEW_SNR_TH_1_rtnr_snr_edgestatus_th2(data)         (0x0000FF00&((data)<<8))
#define IM_DI_RTNR_NEW_SNR_TH_1_rtnr_snr_edgestatus_th1(data)         (0x000000FF&(data))
#define IM_DI_RTNR_NEW_SNR_TH_1_get_rtnr_snr_edgestatus_th4(data)     ((0xFF000000&(data))>>24)
#define IM_DI_RTNR_NEW_SNR_TH_1_get_rtnr_snr_edgestatus_th3(data)     ((0x00FF0000&(data))>>16)
#define IM_DI_RTNR_NEW_SNR_TH_1_get_rtnr_snr_edgestatus_th2(data)     ((0x0000FF00&(data))>>8)
#define IM_DI_RTNR_NEW_SNR_TH_1_get_rtnr_snr_edgestatus_th1(data)     (0x000000FF&(data))


#define IM_DI_RTNR_NEW_SNR_TH2                                        0x180242fc
#define IM_DI_RTNR_NEW_SNR_TH2_reg_addr                               "0xb80242fc"
#define IM_DI_RTNR_NEW_SNR_TH2_reg                                    0xb80242fc
#define IM_DI_RTNR_NEW_SNR_TH2_inst_addr                              "0x00BF"
#define IM_DI_RTNR_NEW_SNR_TH2_inst                                   0x00BF
#define IM_DI_RTNR_NEW_SNR_TH2_rtnr_snr_edgestatus_th7_shift          (16)
#define IM_DI_RTNR_NEW_SNR_TH2_rtnr_snr_edgestatus_th6_shift          (8)
#define IM_DI_RTNR_NEW_SNR_TH2_rtnr_snr_edgestatus_th5_shift          (0)
#define IM_DI_RTNR_NEW_SNR_TH2_rtnr_snr_edgestatus_th7_mask           (0x00FF0000)
#define IM_DI_RTNR_NEW_SNR_TH2_rtnr_snr_edgestatus_th6_mask           (0x0000FF00)
#define IM_DI_RTNR_NEW_SNR_TH2_rtnr_snr_edgestatus_th5_mask           (0x000000FF)
#define IM_DI_RTNR_NEW_SNR_TH2_rtnr_snr_edgestatus_th7(data)          (0x00FF0000&((data)<<16))
#define IM_DI_RTNR_NEW_SNR_TH2_rtnr_snr_edgestatus_th6(data)          (0x0000FF00&((data)<<8))
#define IM_DI_RTNR_NEW_SNR_TH2_rtnr_snr_edgestatus_th5(data)          (0x000000FF&(data))
#define IM_DI_RTNR_NEW_SNR_TH2_get_rtnr_snr_edgestatus_th7(data)      ((0x00FF0000&(data))>>16)
#define IM_DI_RTNR_NEW_SNR_TH2_get_rtnr_snr_edgestatus_th6(data)      ((0x0000FF00&(data))>>8)
#define IM_DI_RTNR_NEW_SNR_TH2_get_rtnr_snr_edgestatus_th5(data)      (0x000000FF&(data))


#define IM_DI_RTNR_NEW_K_00                                           0x18024300
#define IM_DI_RTNR_NEW_K_00_reg_addr                                  "0xb8024300"
#define IM_DI_RTNR_NEW_K_00_reg                                       0xb8024300
#define IM_DI_RTNR_NEW_K_00_inst_addr                                 "0x00C0"
#define IM_DI_RTNR_NEW_K_00_inst                                      0x00C0
#define IM_DI_RTNR_NEW_K_00_rtnr_k_07_shift                           (28)
#define IM_DI_RTNR_NEW_K_00_rtnr_k_06_shift                           (24)
#define IM_DI_RTNR_NEW_K_00_rtnr_k_05_shift                           (20)
#define IM_DI_RTNR_NEW_K_00_rtnr_k_04_shift                           (16)
#define IM_DI_RTNR_NEW_K_00_rtnr_k_03_shift                           (12)
#define IM_DI_RTNR_NEW_K_00_rtnr_k_02_shift                           (8)
#define IM_DI_RTNR_NEW_K_00_rtnr_k_01_shift                           (4)
#define IM_DI_RTNR_NEW_K_00_rtnr_k_00_shift                           (0)
#define IM_DI_RTNR_NEW_K_00_rtnr_k_07_mask                            (0x70000000)
#define IM_DI_RTNR_NEW_K_00_rtnr_k_06_mask                            (0x07000000)
#define IM_DI_RTNR_NEW_K_00_rtnr_k_05_mask                            (0x00700000)
#define IM_DI_RTNR_NEW_K_00_rtnr_k_04_mask                            (0x00070000)
#define IM_DI_RTNR_NEW_K_00_rtnr_k_03_mask                            (0x00007000)
#define IM_DI_RTNR_NEW_K_00_rtnr_k_02_mask                            (0x00000700)
#define IM_DI_RTNR_NEW_K_00_rtnr_k_01_mask                            (0x00000070)
#define IM_DI_RTNR_NEW_K_00_rtnr_k_00_mask                            (0x00000007)
#define IM_DI_RTNR_NEW_K_00_rtnr_k_07(data)                           (0x70000000&((data)<<28))
#define IM_DI_RTNR_NEW_K_00_rtnr_k_06(data)                           (0x07000000&((data)<<24))
#define IM_DI_RTNR_NEW_K_00_rtnr_k_05(data)                           (0x00700000&((data)<<20))
#define IM_DI_RTNR_NEW_K_00_rtnr_k_04(data)                           (0x00070000&((data)<<16))
#define IM_DI_RTNR_NEW_K_00_rtnr_k_03(data)                           (0x00007000&((data)<<12))
#define IM_DI_RTNR_NEW_K_00_rtnr_k_02(data)                           (0x00000700&((data)<<8))
#define IM_DI_RTNR_NEW_K_00_rtnr_k_01(data)                           (0x00000070&((data)<<4))
#define IM_DI_RTNR_NEW_K_00_rtnr_k_00(data)                           (0x00000007&(data))
#define IM_DI_RTNR_NEW_K_00_get_rtnr_k_07(data)                       ((0x70000000&(data))>>28)
#define IM_DI_RTNR_NEW_K_00_get_rtnr_k_06(data)                       ((0x07000000&(data))>>24)
#define IM_DI_RTNR_NEW_K_00_get_rtnr_k_05(data)                       ((0x00700000&(data))>>20)
#define IM_DI_RTNR_NEW_K_00_get_rtnr_k_04(data)                       ((0x00070000&(data))>>16)
#define IM_DI_RTNR_NEW_K_00_get_rtnr_k_03(data)                       ((0x00007000&(data))>>12)
#define IM_DI_RTNR_NEW_K_00_get_rtnr_k_02(data)                       ((0x00000700&(data))>>8)
#define IM_DI_RTNR_NEW_K_00_get_rtnr_k_01(data)                       ((0x00000070&(data))>>4)
#define IM_DI_RTNR_NEW_K_00_get_rtnr_k_00(data)                       (0x00000007&(data))


#define IM_DI_RTNR_NEW_K_10                                           0x18024304
#define IM_DI_RTNR_NEW_K_10_reg_addr                                  "0xb8024304"
#define IM_DI_RTNR_NEW_K_10_reg                                       0xb8024304
#define IM_DI_RTNR_NEW_K_10_inst_addr                                 "0x00C1"
#define IM_DI_RTNR_NEW_K_10_inst                                      0x00C1
#define IM_DI_RTNR_NEW_K_10_rtnr_k_17_shift                           (28)
#define IM_DI_RTNR_NEW_K_10_rtnr_k_16_shift                           (24)
#define IM_DI_RTNR_NEW_K_10_rtnr_k_15_shift                           (20)
#define IM_DI_RTNR_NEW_K_10_rtnr_k_14_shift                           (16)
#define IM_DI_RTNR_NEW_K_10_rtnr_k_13_shift                           (12)
#define IM_DI_RTNR_NEW_K_10_rtnr_k_12_shift                           (8)
#define IM_DI_RTNR_NEW_K_10_rtnr_k_11_shift                           (4)
#define IM_DI_RTNR_NEW_K_10_rtnr_k_10_shift                           (0)
#define IM_DI_RTNR_NEW_K_10_rtnr_k_17_mask                            (0x70000000)
#define IM_DI_RTNR_NEW_K_10_rtnr_k_16_mask                            (0x07000000)
#define IM_DI_RTNR_NEW_K_10_rtnr_k_15_mask                            (0x00700000)
#define IM_DI_RTNR_NEW_K_10_rtnr_k_14_mask                            (0x00070000)
#define IM_DI_RTNR_NEW_K_10_rtnr_k_13_mask                            (0x00007000)
#define IM_DI_RTNR_NEW_K_10_rtnr_k_12_mask                            (0x00000700)
#define IM_DI_RTNR_NEW_K_10_rtnr_k_11_mask                            (0x00000070)
#define IM_DI_RTNR_NEW_K_10_rtnr_k_10_mask                            (0x00000007)
#define IM_DI_RTNR_NEW_K_10_rtnr_k_17(data)                           (0x70000000&((data)<<28))
#define IM_DI_RTNR_NEW_K_10_rtnr_k_16(data)                           (0x07000000&((data)<<24))
#define IM_DI_RTNR_NEW_K_10_rtnr_k_15(data)                           (0x00700000&((data)<<20))
#define IM_DI_RTNR_NEW_K_10_rtnr_k_14(data)                           (0x00070000&((data)<<16))
#define IM_DI_RTNR_NEW_K_10_rtnr_k_13(data)                           (0x00007000&((data)<<12))
#define IM_DI_RTNR_NEW_K_10_rtnr_k_12(data)                           (0x00000700&((data)<<8))
#define IM_DI_RTNR_NEW_K_10_rtnr_k_11(data)                           (0x00000070&((data)<<4))
#define IM_DI_RTNR_NEW_K_10_rtnr_k_10(data)                           (0x00000007&(data))
#define IM_DI_RTNR_NEW_K_10_get_rtnr_k_17(data)                       ((0x70000000&(data))>>28)
#define IM_DI_RTNR_NEW_K_10_get_rtnr_k_16(data)                       ((0x07000000&(data))>>24)
#define IM_DI_RTNR_NEW_K_10_get_rtnr_k_15(data)                       ((0x00700000&(data))>>20)
#define IM_DI_RTNR_NEW_K_10_get_rtnr_k_14(data)                       ((0x00070000&(data))>>16)
#define IM_DI_RTNR_NEW_K_10_get_rtnr_k_13(data)                       ((0x00007000&(data))>>12)
#define IM_DI_RTNR_NEW_K_10_get_rtnr_k_12(data)                       ((0x00000700&(data))>>8)
#define IM_DI_RTNR_NEW_K_10_get_rtnr_k_11(data)                       ((0x00000070&(data))>>4)
#define IM_DI_RTNR_NEW_K_10_get_rtnr_k_10(data)                       (0x00000007&(data))


#define IM_DI_RTNR_NEW_K_20                                           0x18024308
#define IM_DI_RTNR_NEW_K_20_reg_addr                                  "0xb8024308"
#define IM_DI_RTNR_NEW_K_20_reg                                       0xb8024308
#define IM_DI_RTNR_NEW_K_20_inst_addr                                 "0x00C2"
#define IM_DI_RTNR_NEW_K_20_inst                                      0x00C2
#define IM_DI_RTNR_NEW_K_20_rtnr_k_27_shift                           (28)
#define IM_DI_RTNR_NEW_K_20_rtnr_k_26_shift                           (24)
#define IM_DI_RTNR_NEW_K_20_rtnr_k_25_shift                           (20)
#define IM_DI_RTNR_NEW_K_20_rtnr_k_24_shift                           (16)
#define IM_DI_RTNR_NEW_K_20_rtnr_k_23_shift                           (12)
#define IM_DI_RTNR_NEW_K_20_rtnr_k_22_shift                           (8)
#define IM_DI_RTNR_NEW_K_20_rtnr_k_21_shift                           (4)
#define IM_DI_RTNR_NEW_K_20_rtnr_k_20_shift                           (0)
#define IM_DI_RTNR_NEW_K_20_rtnr_k_27_mask                            (0x70000000)
#define IM_DI_RTNR_NEW_K_20_rtnr_k_26_mask                            (0x07000000)
#define IM_DI_RTNR_NEW_K_20_rtnr_k_25_mask                            (0x00700000)
#define IM_DI_RTNR_NEW_K_20_rtnr_k_24_mask                            (0x00070000)
#define IM_DI_RTNR_NEW_K_20_rtnr_k_23_mask                            (0x00007000)
#define IM_DI_RTNR_NEW_K_20_rtnr_k_22_mask                            (0x00000700)
#define IM_DI_RTNR_NEW_K_20_rtnr_k_21_mask                            (0x00000070)
#define IM_DI_RTNR_NEW_K_20_rtnr_k_20_mask                            (0x00000007)
#define IM_DI_RTNR_NEW_K_20_rtnr_k_27(data)                           (0x70000000&((data)<<28))
#define IM_DI_RTNR_NEW_K_20_rtnr_k_26(data)                           (0x07000000&((data)<<24))
#define IM_DI_RTNR_NEW_K_20_rtnr_k_25(data)                           (0x00700000&((data)<<20))
#define IM_DI_RTNR_NEW_K_20_rtnr_k_24(data)                           (0x00070000&((data)<<16))
#define IM_DI_RTNR_NEW_K_20_rtnr_k_23(data)                           (0x00007000&((data)<<12))
#define IM_DI_RTNR_NEW_K_20_rtnr_k_22(data)                           (0x00000700&((data)<<8))
#define IM_DI_RTNR_NEW_K_20_rtnr_k_21(data)                           (0x00000070&((data)<<4))
#define IM_DI_RTNR_NEW_K_20_rtnr_k_20(data)                           (0x00000007&(data))
#define IM_DI_RTNR_NEW_K_20_get_rtnr_k_27(data)                       ((0x70000000&(data))>>28)
#define IM_DI_RTNR_NEW_K_20_get_rtnr_k_26(data)                       ((0x07000000&(data))>>24)
#define IM_DI_RTNR_NEW_K_20_get_rtnr_k_25(data)                       ((0x00700000&(data))>>20)
#define IM_DI_RTNR_NEW_K_20_get_rtnr_k_24(data)                       ((0x00070000&(data))>>16)
#define IM_DI_RTNR_NEW_K_20_get_rtnr_k_23(data)                       ((0x00007000&(data))>>12)
#define IM_DI_RTNR_NEW_K_20_get_rtnr_k_22(data)                       ((0x00000700&(data))>>8)
#define IM_DI_RTNR_NEW_K_20_get_rtnr_k_21(data)                       ((0x00000070&(data))>>4)
#define IM_DI_RTNR_NEW_K_20_get_rtnr_k_20(data)                       (0x00000007&(data))


#define IM_DI_RTNR_NEW_K_30                                           0x1802430c
#define IM_DI_RTNR_NEW_K_30_reg_addr                                  "0xb802430c"
#define IM_DI_RTNR_NEW_K_30_reg                                       0xb802430c
#define IM_DI_RTNR_NEW_K_30_inst_addr                                 "0x00C3"
#define IM_DI_RTNR_NEW_K_30_inst                                      0x00C3
#define IM_DI_RTNR_NEW_K_30_rtnr_k_37_shift                           (28)
#define IM_DI_RTNR_NEW_K_30_rtnr_k_36_shift                           (24)
#define IM_DI_RTNR_NEW_K_30_rtnr_k_35_shift                           (20)
#define IM_DI_RTNR_NEW_K_30_rtnr_k_34_shift                           (16)
#define IM_DI_RTNR_NEW_K_30_rtnr_k_33_shift                           (12)
#define IM_DI_RTNR_NEW_K_30_rtnr_k_32_shift                           (8)
#define IM_DI_RTNR_NEW_K_30_rtnr_k_31_shift                           (4)
#define IM_DI_RTNR_NEW_K_30_rtnr_k_30_shift                           (0)
#define IM_DI_RTNR_NEW_K_30_rtnr_k_37_mask                            (0x70000000)
#define IM_DI_RTNR_NEW_K_30_rtnr_k_36_mask                            (0x07000000)
#define IM_DI_RTNR_NEW_K_30_rtnr_k_35_mask                            (0x00700000)
#define IM_DI_RTNR_NEW_K_30_rtnr_k_34_mask                            (0x00070000)
#define IM_DI_RTNR_NEW_K_30_rtnr_k_33_mask                            (0x00007000)
#define IM_DI_RTNR_NEW_K_30_rtnr_k_32_mask                            (0x00000700)
#define IM_DI_RTNR_NEW_K_30_rtnr_k_31_mask                            (0x00000070)
#define IM_DI_RTNR_NEW_K_30_rtnr_k_30_mask                            (0x00000007)
#define IM_DI_RTNR_NEW_K_30_rtnr_k_37(data)                           (0x70000000&((data)<<28))
#define IM_DI_RTNR_NEW_K_30_rtnr_k_36(data)                           (0x07000000&((data)<<24))
#define IM_DI_RTNR_NEW_K_30_rtnr_k_35(data)                           (0x00700000&((data)<<20))
#define IM_DI_RTNR_NEW_K_30_rtnr_k_34(data)                           (0x00070000&((data)<<16))
#define IM_DI_RTNR_NEW_K_30_rtnr_k_33(data)                           (0x00007000&((data)<<12))
#define IM_DI_RTNR_NEW_K_30_rtnr_k_32(data)                           (0x00000700&((data)<<8))
#define IM_DI_RTNR_NEW_K_30_rtnr_k_31(data)                           (0x00000070&((data)<<4))
#define IM_DI_RTNR_NEW_K_30_rtnr_k_30(data)                           (0x00000007&(data))
#define IM_DI_RTNR_NEW_K_30_get_rtnr_k_37(data)                       ((0x70000000&(data))>>28)
#define IM_DI_RTNR_NEW_K_30_get_rtnr_k_36(data)                       ((0x07000000&(data))>>24)
#define IM_DI_RTNR_NEW_K_30_get_rtnr_k_35(data)                       ((0x00700000&(data))>>20)
#define IM_DI_RTNR_NEW_K_30_get_rtnr_k_34(data)                       ((0x00070000&(data))>>16)
#define IM_DI_RTNR_NEW_K_30_get_rtnr_k_33(data)                       ((0x00007000&(data))>>12)
#define IM_DI_RTNR_NEW_K_30_get_rtnr_k_32(data)                       ((0x00000700&(data))>>8)
#define IM_DI_RTNR_NEW_K_30_get_rtnr_k_31(data)                       ((0x00000070&(data))>>4)
#define IM_DI_RTNR_NEW_K_30_get_rtnr_k_30(data)                       (0x00000007&(data))


#define IM_DI_RTNR_NEW_K_40                                           0x18024310
#define IM_DI_RTNR_NEW_K_40_reg_addr                                  "0xb8024310"
#define IM_DI_RTNR_NEW_K_40_reg                                       0xb8024310
#define IM_DI_RTNR_NEW_K_40_inst_addr                                 "0x00C4"
#define IM_DI_RTNR_NEW_K_40_inst                                      0x00C4
#define IM_DI_RTNR_NEW_K_40_rtnr_k_47_shift                           (28)
#define IM_DI_RTNR_NEW_K_40_rtnr_k_46_shift                           (24)
#define IM_DI_RTNR_NEW_K_40_rtnr_k_45_shift                           (20)
#define IM_DI_RTNR_NEW_K_40_rtnr_k_44_shift                           (16)
#define IM_DI_RTNR_NEW_K_40_rtnr_k_43_shift                           (12)
#define IM_DI_RTNR_NEW_K_40_rtnr_k_42_shift                           (8)
#define IM_DI_RTNR_NEW_K_40_rtnr_k_41_shift                           (4)
#define IM_DI_RTNR_NEW_K_40_rtnr_k_40_shift                           (0)
#define IM_DI_RTNR_NEW_K_40_rtnr_k_47_mask                            (0x70000000)
#define IM_DI_RTNR_NEW_K_40_rtnr_k_46_mask                            (0x07000000)
#define IM_DI_RTNR_NEW_K_40_rtnr_k_45_mask                            (0x00700000)
#define IM_DI_RTNR_NEW_K_40_rtnr_k_44_mask                            (0x00070000)
#define IM_DI_RTNR_NEW_K_40_rtnr_k_43_mask                            (0x00007000)
#define IM_DI_RTNR_NEW_K_40_rtnr_k_42_mask                            (0x00000700)
#define IM_DI_RTNR_NEW_K_40_rtnr_k_41_mask                            (0x00000070)
#define IM_DI_RTNR_NEW_K_40_rtnr_k_40_mask                            (0x00000007)
#define IM_DI_RTNR_NEW_K_40_rtnr_k_47(data)                           (0x70000000&((data)<<28))
#define IM_DI_RTNR_NEW_K_40_rtnr_k_46(data)                           (0x07000000&((data)<<24))
#define IM_DI_RTNR_NEW_K_40_rtnr_k_45(data)                           (0x00700000&((data)<<20))
#define IM_DI_RTNR_NEW_K_40_rtnr_k_44(data)                           (0x00070000&((data)<<16))
#define IM_DI_RTNR_NEW_K_40_rtnr_k_43(data)                           (0x00007000&((data)<<12))
#define IM_DI_RTNR_NEW_K_40_rtnr_k_42(data)                           (0x00000700&((data)<<8))
#define IM_DI_RTNR_NEW_K_40_rtnr_k_41(data)                           (0x00000070&((data)<<4))
#define IM_DI_RTNR_NEW_K_40_rtnr_k_40(data)                           (0x00000007&(data))
#define IM_DI_RTNR_NEW_K_40_get_rtnr_k_47(data)                       ((0x70000000&(data))>>28)
#define IM_DI_RTNR_NEW_K_40_get_rtnr_k_46(data)                       ((0x07000000&(data))>>24)
#define IM_DI_RTNR_NEW_K_40_get_rtnr_k_45(data)                       ((0x00700000&(data))>>20)
#define IM_DI_RTNR_NEW_K_40_get_rtnr_k_44(data)                       ((0x00070000&(data))>>16)
#define IM_DI_RTNR_NEW_K_40_get_rtnr_k_43(data)                       ((0x00007000&(data))>>12)
#define IM_DI_RTNR_NEW_K_40_get_rtnr_k_42(data)                       ((0x00000700&(data))>>8)
#define IM_DI_RTNR_NEW_K_40_get_rtnr_k_41(data)                       ((0x00000070&(data))>>4)
#define IM_DI_RTNR_NEW_K_40_get_rtnr_k_40(data)                       (0x00000007&(data))


#define IM_DI_RTNR_NEW_K_50                                           0x18024314
#define IM_DI_RTNR_NEW_K_50_reg_addr                                  "0xb8024314"
#define IM_DI_RTNR_NEW_K_50_reg                                       0xb8024314
#define IM_DI_RTNR_NEW_K_50_inst_addr                                 "0x00C5"
#define IM_DI_RTNR_NEW_K_50_inst                                      0x00C5
#define IM_DI_RTNR_NEW_K_50_rtnr_k_57_shift                           (28)
#define IM_DI_RTNR_NEW_K_50_rtnr_k_56_shift                           (24)
#define IM_DI_RTNR_NEW_K_50_rtnr_k_55_shift                           (20)
#define IM_DI_RTNR_NEW_K_50_rtnr_k_54_shift                           (16)
#define IM_DI_RTNR_NEW_K_50_rtnr_k_53_shift                           (12)
#define IM_DI_RTNR_NEW_K_50_rtnr_k_52_shift                           (8)
#define IM_DI_RTNR_NEW_K_50_rtnr_k_51_shift                           (4)
#define IM_DI_RTNR_NEW_K_50_rtnr_k_50_shift                           (0)
#define IM_DI_RTNR_NEW_K_50_rtnr_k_57_mask                            (0x70000000)
#define IM_DI_RTNR_NEW_K_50_rtnr_k_56_mask                            (0x07000000)
#define IM_DI_RTNR_NEW_K_50_rtnr_k_55_mask                            (0x00700000)
#define IM_DI_RTNR_NEW_K_50_rtnr_k_54_mask                            (0x00070000)
#define IM_DI_RTNR_NEW_K_50_rtnr_k_53_mask                            (0x00007000)
#define IM_DI_RTNR_NEW_K_50_rtnr_k_52_mask                            (0x00000700)
#define IM_DI_RTNR_NEW_K_50_rtnr_k_51_mask                            (0x00000070)
#define IM_DI_RTNR_NEW_K_50_rtnr_k_50_mask                            (0x00000007)
#define IM_DI_RTNR_NEW_K_50_rtnr_k_57(data)                           (0x70000000&((data)<<28))
#define IM_DI_RTNR_NEW_K_50_rtnr_k_56(data)                           (0x07000000&((data)<<24))
#define IM_DI_RTNR_NEW_K_50_rtnr_k_55(data)                           (0x00700000&((data)<<20))
#define IM_DI_RTNR_NEW_K_50_rtnr_k_54(data)                           (0x00070000&((data)<<16))
#define IM_DI_RTNR_NEW_K_50_rtnr_k_53(data)                           (0x00007000&((data)<<12))
#define IM_DI_RTNR_NEW_K_50_rtnr_k_52(data)                           (0x00000700&((data)<<8))
#define IM_DI_RTNR_NEW_K_50_rtnr_k_51(data)                           (0x00000070&((data)<<4))
#define IM_DI_RTNR_NEW_K_50_rtnr_k_50(data)                           (0x00000007&(data))
#define IM_DI_RTNR_NEW_K_50_get_rtnr_k_57(data)                       ((0x70000000&(data))>>28)
#define IM_DI_RTNR_NEW_K_50_get_rtnr_k_56(data)                       ((0x07000000&(data))>>24)
#define IM_DI_RTNR_NEW_K_50_get_rtnr_k_55(data)                       ((0x00700000&(data))>>20)
#define IM_DI_RTNR_NEW_K_50_get_rtnr_k_54(data)                       ((0x00070000&(data))>>16)
#define IM_DI_RTNR_NEW_K_50_get_rtnr_k_53(data)                       ((0x00007000&(data))>>12)
#define IM_DI_RTNR_NEW_K_50_get_rtnr_k_52(data)                       ((0x00000700&(data))>>8)
#define IM_DI_RTNR_NEW_K_50_get_rtnr_k_51(data)                       ((0x00000070&(data))>>4)
#define IM_DI_RTNR_NEW_K_50_get_rtnr_k_50(data)                       (0x00000007&(data))


#define IM_DI_RTNR_NEW_K_60                                           0x18024318
#define IM_DI_RTNR_NEW_K_60_reg_addr                                  "0xb8024318"
#define IM_DI_RTNR_NEW_K_60_reg                                       0xb8024318
#define IM_DI_RTNR_NEW_K_60_inst_addr                                 "0x00C6"
#define IM_DI_RTNR_NEW_K_60_inst                                      0x00C6
#define IM_DI_RTNR_NEW_K_60_rtnr_k_67_shift                           (28)
#define IM_DI_RTNR_NEW_K_60_rtnr_k_66_shift                           (24)
#define IM_DI_RTNR_NEW_K_60_rtnr_k_65_shift                           (20)
#define IM_DI_RTNR_NEW_K_60_rtnr_k_64_shift                           (16)
#define IM_DI_RTNR_NEW_K_60_rtnr_k_63_shift                           (12)
#define IM_DI_RTNR_NEW_K_60_rtnr_k_62_shift                           (8)
#define IM_DI_RTNR_NEW_K_60_rtnr_k_61_shift                           (4)
#define IM_DI_RTNR_NEW_K_60_rtnr_k_60_shift                           (0)
#define IM_DI_RTNR_NEW_K_60_rtnr_k_67_mask                            (0x70000000)
#define IM_DI_RTNR_NEW_K_60_rtnr_k_66_mask                            (0x07000000)
#define IM_DI_RTNR_NEW_K_60_rtnr_k_65_mask                            (0x00700000)
#define IM_DI_RTNR_NEW_K_60_rtnr_k_64_mask                            (0x00070000)
#define IM_DI_RTNR_NEW_K_60_rtnr_k_63_mask                            (0x00007000)
#define IM_DI_RTNR_NEW_K_60_rtnr_k_62_mask                            (0x00000700)
#define IM_DI_RTNR_NEW_K_60_rtnr_k_61_mask                            (0x00000070)
#define IM_DI_RTNR_NEW_K_60_rtnr_k_60_mask                            (0x00000007)
#define IM_DI_RTNR_NEW_K_60_rtnr_k_67(data)                           (0x70000000&((data)<<28))
#define IM_DI_RTNR_NEW_K_60_rtnr_k_66(data)                           (0x07000000&((data)<<24))
#define IM_DI_RTNR_NEW_K_60_rtnr_k_65(data)                           (0x00700000&((data)<<20))
#define IM_DI_RTNR_NEW_K_60_rtnr_k_64(data)                           (0x00070000&((data)<<16))
#define IM_DI_RTNR_NEW_K_60_rtnr_k_63(data)                           (0x00007000&((data)<<12))
#define IM_DI_RTNR_NEW_K_60_rtnr_k_62(data)                           (0x00000700&((data)<<8))
#define IM_DI_RTNR_NEW_K_60_rtnr_k_61(data)                           (0x00000070&((data)<<4))
#define IM_DI_RTNR_NEW_K_60_rtnr_k_60(data)                           (0x00000007&(data))
#define IM_DI_RTNR_NEW_K_60_get_rtnr_k_67(data)                       ((0x70000000&(data))>>28)
#define IM_DI_RTNR_NEW_K_60_get_rtnr_k_66(data)                       ((0x07000000&(data))>>24)
#define IM_DI_RTNR_NEW_K_60_get_rtnr_k_65(data)                       ((0x00700000&(data))>>20)
#define IM_DI_RTNR_NEW_K_60_get_rtnr_k_64(data)                       ((0x00070000&(data))>>16)
#define IM_DI_RTNR_NEW_K_60_get_rtnr_k_63(data)                       ((0x00007000&(data))>>12)
#define IM_DI_RTNR_NEW_K_60_get_rtnr_k_62(data)                       ((0x00000700&(data))>>8)
#define IM_DI_RTNR_NEW_K_60_get_rtnr_k_61(data)                       ((0x00000070&(data))>>4)
#define IM_DI_RTNR_NEW_K_60_get_rtnr_k_60(data)                       (0x00000007&(data))


#define IM_DI_RTNR_NEW_K_70                                           0x1802431c
#define IM_DI_RTNR_NEW_K_70_reg_addr                                  "0xb802431c"
#define IM_DI_RTNR_NEW_K_70_reg                                       0xb802431c
#define IM_DI_RTNR_NEW_K_70_inst_addr                                 "0x00C7"
#define IM_DI_RTNR_NEW_K_70_inst                                      0x00C7
#define IM_DI_RTNR_NEW_K_70_rtnr_k_77_shift                           (28)
#define IM_DI_RTNR_NEW_K_70_rtnr_k_76_shift                           (24)
#define IM_DI_RTNR_NEW_K_70_rtnr_k_75_shift                           (20)
#define IM_DI_RTNR_NEW_K_70_rtnr_k_74_shift                           (16)
#define IM_DI_RTNR_NEW_K_70_rtnr_k_73_shift                           (12)
#define IM_DI_RTNR_NEW_K_70_rtnr_k_72_shift                           (8)
#define IM_DI_RTNR_NEW_K_70_rtnr_k_71_shift                           (4)
#define IM_DI_RTNR_NEW_K_70_rtnr_k_70_shift                           (0)
#define IM_DI_RTNR_NEW_K_70_rtnr_k_77_mask                            (0x70000000)
#define IM_DI_RTNR_NEW_K_70_rtnr_k_76_mask                            (0x07000000)
#define IM_DI_RTNR_NEW_K_70_rtnr_k_75_mask                            (0x00700000)
#define IM_DI_RTNR_NEW_K_70_rtnr_k_74_mask                            (0x00070000)
#define IM_DI_RTNR_NEW_K_70_rtnr_k_73_mask                            (0x00007000)
#define IM_DI_RTNR_NEW_K_70_rtnr_k_72_mask                            (0x00000700)
#define IM_DI_RTNR_NEW_K_70_rtnr_k_71_mask                            (0x00000070)
#define IM_DI_RTNR_NEW_K_70_rtnr_k_70_mask                            (0x00000007)
#define IM_DI_RTNR_NEW_K_70_rtnr_k_77(data)                           (0x70000000&((data)<<28))
#define IM_DI_RTNR_NEW_K_70_rtnr_k_76(data)                           (0x07000000&((data)<<24))
#define IM_DI_RTNR_NEW_K_70_rtnr_k_75(data)                           (0x00700000&((data)<<20))
#define IM_DI_RTNR_NEW_K_70_rtnr_k_74(data)                           (0x00070000&((data)<<16))
#define IM_DI_RTNR_NEW_K_70_rtnr_k_73(data)                           (0x00007000&((data)<<12))
#define IM_DI_RTNR_NEW_K_70_rtnr_k_72(data)                           (0x00000700&((data)<<8))
#define IM_DI_RTNR_NEW_K_70_rtnr_k_71(data)                           (0x00000070&((data)<<4))
#define IM_DI_RTNR_NEW_K_70_rtnr_k_70(data)                           (0x00000007&(data))
#define IM_DI_RTNR_NEW_K_70_get_rtnr_k_77(data)                       ((0x70000000&(data))>>28)
#define IM_DI_RTNR_NEW_K_70_get_rtnr_k_76(data)                       ((0x07000000&(data))>>24)
#define IM_DI_RTNR_NEW_K_70_get_rtnr_k_75(data)                       ((0x00700000&(data))>>20)
#define IM_DI_RTNR_NEW_K_70_get_rtnr_k_74(data)                       ((0x00070000&(data))>>16)
#define IM_DI_RTNR_NEW_K_70_get_rtnr_k_73(data)                       ((0x00007000&(data))>>12)
#define IM_DI_RTNR_NEW_K_70_get_rtnr_k_72(data)                       ((0x00000700&(data))>>8)
#define IM_DI_RTNR_NEW_K_70_get_rtnr_k_71(data)                       ((0x00000070&(data))>>4)
#define IM_DI_RTNR_NEW_K_70_get_rtnr_k_70(data)                       (0x00000007&(data))


#define IM_DI_RTNR_NEW_MASK1_CTRL1                                    0x18024320
#define IM_DI_RTNR_NEW_MASK1_CTRL1_reg_addr                           "0xb8024320"
#define IM_DI_RTNR_NEW_MASK1_CTRL1_reg                                0xb8024320
#define IM_DI_RTNR_NEW_MASK1_CTRL1_inst_addr                          "0x00C8"
#define IM_DI_RTNR_NEW_MASK1_CTRL1_inst                               0x00C8
#define IM_DI_RTNR_NEW_MASK1_CTRL1_reg_vc_nr_mask1_yref_shift         (26)
#define IM_DI_RTNR_NEW_MASK1_CTRL1_reg_vc_nr_mask1_uref_shift         (18)
#define IM_DI_RTNR_NEW_MASK1_CTRL1_reg_vc_nr_mask1_vref_shift         (10)
#define IM_DI_RTNR_NEW_MASK1_CTRL1_rtnr_mask1_ygain_shift             (4)
#define IM_DI_RTNR_NEW_MASK1_CTRL1_rtnr_mask1_ugain_shift             (2)
#define IM_DI_RTNR_NEW_MASK1_CTRL1_rtnr_mask1_vgain_shift             (0)
#define IM_DI_RTNR_NEW_MASK1_CTRL1_reg_vc_nr_mask1_yref_mask          (0xFC000000)
#define IM_DI_RTNR_NEW_MASK1_CTRL1_reg_vc_nr_mask1_uref_mask          (0x00FC0000)
#define IM_DI_RTNR_NEW_MASK1_CTRL1_reg_vc_nr_mask1_vref_mask          (0x0000FC00)
#define IM_DI_RTNR_NEW_MASK1_CTRL1_rtnr_mask1_ygain_mask              (0x00000030)
#define IM_DI_RTNR_NEW_MASK1_CTRL1_rtnr_mask1_ugain_mask              (0x0000000C)
#define IM_DI_RTNR_NEW_MASK1_CTRL1_rtnr_mask1_vgain_mask              (0x00000003)
#define IM_DI_RTNR_NEW_MASK1_CTRL1_reg_vc_nr_mask1_yref(data)         (0xFC000000&((data)<<26))
#define IM_DI_RTNR_NEW_MASK1_CTRL1_reg_vc_nr_mask1_uref(data)         (0x00FC0000&((data)<<18))
#define IM_DI_RTNR_NEW_MASK1_CTRL1_reg_vc_nr_mask1_vref(data)         (0x0000FC00&((data)<<10))
#define IM_DI_RTNR_NEW_MASK1_CTRL1_rtnr_mask1_ygain(data)             (0x00000030&((data)<<4))
#define IM_DI_RTNR_NEW_MASK1_CTRL1_rtnr_mask1_ugain(data)             (0x0000000C&((data)<<2))
#define IM_DI_RTNR_NEW_MASK1_CTRL1_rtnr_mask1_vgain(data)             (0x00000003&(data))
#define IM_DI_RTNR_NEW_MASK1_CTRL1_get_reg_vc_nr_mask1_yref(data)     ((0xFC000000&(data))>>26)
#define IM_DI_RTNR_NEW_MASK1_CTRL1_get_reg_vc_nr_mask1_uref(data)     ((0x00FC0000&(data))>>18)
#define IM_DI_RTNR_NEW_MASK1_CTRL1_get_reg_vc_nr_mask1_vref(data)     ((0x0000FC00&(data))>>10)
#define IM_DI_RTNR_NEW_MASK1_CTRL1_get_rtnr_mask1_ygain(data)         ((0x00000030&(data))>>4)
#define IM_DI_RTNR_NEW_MASK1_CTRL1_get_rtnr_mask1_ugain(data)         ((0x0000000C&(data))>>2)
#define IM_DI_RTNR_NEW_MASK1_CTRL1_get_rtnr_mask1_vgain(data)         (0x00000003&(data))


#define IM_DI_RTNR_NEW_MASK1_CTRL2                                    0x18024324
#define IM_DI_RTNR_NEW_MASK1_CTRL2_reg_addr                           "0xb8024324"
#define IM_DI_RTNR_NEW_MASK1_CTRL2_reg                                0xb8024324
#define IM_DI_RTNR_NEW_MASK1_CTRL2_inst_addr                          "0x00C9"
#define IM_DI_RTNR_NEW_MASK1_CTRL2_inst                               0x00C9
#define IM_DI_RTNR_NEW_MASK1_CTRL2_rtnr_mask1_maplimit_shift          (16)
#define IM_DI_RTNR_NEW_MASK1_CTRL2_rtnr_mask1_mapthre_shift           (12)
#define IM_DI_RTNR_NEW_MASK1_CTRL2_rtnr_mask1_mapstep_shift           (8)
#define IM_DI_RTNR_NEW_MASK1_CTRL2_rtnr_mask1_dir_shift               (4)
#define IM_DI_RTNR_NEW_MASK1_CTRL2_rtnr_mask1_en_shift                (0)
#define IM_DI_RTNR_NEW_MASK1_CTRL2_rtnr_mask1_maplimit_mask           (0x00070000)
#define IM_DI_RTNR_NEW_MASK1_CTRL2_rtnr_mask1_mapthre_mask            (0x0000F000)
#define IM_DI_RTNR_NEW_MASK1_CTRL2_rtnr_mask1_mapstep_mask            (0x00000700)
#define IM_DI_RTNR_NEW_MASK1_CTRL2_rtnr_mask1_dir_mask                (0x00000010)
#define IM_DI_RTNR_NEW_MASK1_CTRL2_rtnr_mask1_en_mask                 (0x00000001)
#define IM_DI_RTNR_NEW_MASK1_CTRL2_rtnr_mask1_maplimit(data)          (0x00070000&((data)<<16))
#define IM_DI_RTNR_NEW_MASK1_CTRL2_rtnr_mask1_mapthre(data)           (0x0000F000&((data)<<12))
#define IM_DI_RTNR_NEW_MASK1_CTRL2_rtnr_mask1_mapstep(data)           (0x00000700&((data)<<8))
#define IM_DI_RTNR_NEW_MASK1_CTRL2_rtnr_mask1_dir(data)               (0x00000010&((data)<<4))
#define IM_DI_RTNR_NEW_MASK1_CTRL2_rtnr_mask1_en(data)                (0x00000001&(data))
#define IM_DI_RTNR_NEW_MASK1_CTRL2_get_rtnr_mask1_maplimit(data)      ((0x00070000&(data))>>16)
#define IM_DI_RTNR_NEW_MASK1_CTRL2_get_rtnr_mask1_mapthre(data)       ((0x0000F000&(data))>>12)
#define IM_DI_RTNR_NEW_MASK1_CTRL2_get_rtnr_mask1_mapstep(data)       ((0x00000700&(data))>>8)
#define IM_DI_RTNR_NEW_MASK1_CTRL2_get_rtnr_mask1_dir(data)           ((0x00000010&(data))>>4)
#define IM_DI_RTNR_NEW_MASK1_CTRL2_get_rtnr_mask1_en(data)            (0x00000001&(data))


#define IM_DI_RTNR_NEW_MASK2_CTRL1                                    0x18024328
#define IM_DI_RTNR_NEW_MASK2_CTRL1_reg_addr                           "0xb8024328"
#define IM_DI_RTNR_NEW_MASK2_CTRL1_reg                                0xb8024328
#define IM_DI_RTNR_NEW_MASK2_CTRL1_inst_addr                          "0x00CA"
#define IM_DI_RTNR_NEW_MASK2_CTRL1_inst                               0x00CA
#define IM_DI_RTNR_NEW_MASK2_CTRL1_reg_vc_nr_mask2_yref_shift         (26)
#define IM_DI_RTNR_NEW_MASK2_CTRL1_reg_vc_nr_mask2_uref_shift         (18)
#define IM_DI_RTNR_NEW_MASK2_CTRL1_reg_vc_nr_mask2_vref_shift         (10)
#define IM_DI_RTNR_NEW_MASK2_CTRL1_rtnr_mask2_ygain_shift             (4)
#define IM_DI_RTNR_NEW_MASK2_CTRL1_rtnr_mask2_ugain_shift             (2)
#define IM_DI_RTNR_NEW_MASK2_CTRL1_rtnr_mask2_vgain_shift             (0)
#define IM_DI_RTNR_NEW_MASK2_CTRL1_reg_vc_nr_mask2_yref_mask          (0xFC000000)
#define IM_DI_RTNR_NEW_MASK2_CTRL1_reg_vc_nr_mask2_uref_mask          (0x00FC0000)
#define IM_DI_RTNR_NEW_MASK2_CTRL1_reg_vc_nr_mask2_vref_mask          (0x0000FC00)
#define IM_DI_RTNR_NEW_MASK2_CTRL1_rtnr_mask2_ygain_mask              (0x00000030)
#define IM_DI_RTNR_NEW_MASK2_CTRL1_rtnr_mask2_ugain_mask              (0x0000000C)
#define IM_DI_RTNR_NEW_MASK2_CTRL1_rtnr_mask2_vgain_mask              (0x00000003)
#define IM_DI_RTNR_NEW_MASK2_CTRL1_reg_vc_nr_mask2_yref(data)         (0xFC000000&((data)<<26))
#define IM_DI_RTNR_NEW_MASK2_CTRL1_reg_vc_nr_mask2_uref(data)         (0x00FC0000&((data)<<18))
#define IM_DI_RTNR_NEW_MASK2_CTRL1_reg_vc_nr_mask2_vref(data)         (0x0000FC00&((data)<<10))
#define IM_DI_RTNR_NEW_MASK2_CTRL1_rtnr_mask2_ygain(data)             (0x00000030&((data)<<4))
#define IM_DI_RTNR_NEW_MASK2_CTRL1_rtnr_mask2_ugain(data)             (0x0000000C&((data)<<2))
#define IM_DI_RTNR_NEW_MASK2_CTRL1_rtnr_mask2_vgain(data)             (0x00000003&(data))
#define IM_DI_RTNR_NEW_MASK2_CTRL1_get_reg_vc_nr_mask2_yref(data)     ((0xFC000000&(data))>>26)
#define IM_DI_RTNR_NEW_MASK2_CTRL1_get_reg_vc_nr_mask2_uref(data)     ((0x00FC0000&(data))>>18)
#define IM_DI_RTNR_NEW_MASK2_CTRL1_get_reg_vc_nr_mask2_vref(data)     ((0x0000FC00&(data))>>10)
#define IM_DI_RTNR_NEW_MASK2_CTRL1_get_rtnr_mask2_ygain(data)         ((0x00000030&(data))>>4)
#define IM_DI_RTNR_NEW_MASK2_CTRL1_get_rtnr_mask2_ugain(data)         ((0x0000000C&(data))>>2)
#define IM_DI_RTNR_NEW_MASK2_CTRL1_get_rtnr_mask2_vgain(data)         (0x00000003&(data))


#define IM_DI_RTNR_NEW_MASK2_CTRL2                                    0x1802432c
#define IM_DI_RTNR_NEW_MASK2_CTRL2_reg_addr                           "0xb802432c"
#define IM_DI_RTNR_NEW_MASK2_CTRL2_reg                                0xb802432c
#define IM_DI_RTNR_NEW_MASK2_CTRL2_inst_addr                          "0x00CB"
#define IM_DI_RTNR_NEW_MASK2_CTRL2_inst                               0x00CB
#define IM_DI_RTNR_NEW_MASK2_CTRL2_rtnr_mask2_maplimit_shift          (16)
#define IM_DI_RTNR_NEW_MASK2_CTRL2_rtnr_mask2_mapthre_shift           (12)
#define IM_DI_RTNR_NEW_MASK2_CTRL2_rtnr_mask2_mapstep_shift           (8)
#define IM_DI_RTNR_NEW_MASK2_CTRL2_rtnr_mask2_dir_shift               (4)
#define IM_DI_RTNR_NEW_MASK2_CTRL2_rtnr_mask2_en_shift                (0)
#define IM_DI_RTNR_NEW_MASK2_CTRL2_rtnr_mask2_maplimit_mask           (0x00070000)
#define IM_DI_RTNR_NEW_MASK2_CTRL2_rtnr_mask2_mapthre_mask            (0x0000F000)
#define IM_DI_RTNR_NEW_MASK2_CTRL2_rtnr_mask2_mapstep_mask            (0x00000700)
#define IM_DI_RTNR_NEW_MASK2_CTRL2_rtnr_mask2_dir_mask                (0x00000010)
#define IM_DI_RTNR_NEW_MASK2_CTRL2_rtnr_mask2_en_mask                 (0x00000001)
#define IM_DI_RTNR_NEW_MASK2_CTRL2_rtnr_mask2_maplimit(data)          (0x00070000&((data)<<16))
#define IM_DI_RTNR_NEW_MASK2_CTRL2_rtnr_mask2_mapthre(data)           (0x0000F000&((data)<<12))
#define IM_DI_RTNR_NEW_MASK2_CTRL2_rtnr_mask2_mapstep(data)           (0x00000700&((data)<<8))
#define IM_DI_RTNR_NEW_MASK2_CTRL2_rtnr_mask2_dir(data)               (0x00000010&((data)<<4))
#define IM_DI_RTNR_NEW_MASK2_CTRL2_rtnr_mask2_en(data)                (0x00000001&(data))
#define IM_DI_RTNR_NEW_MASK2_CTRL2_get_rtnr_mask2_maplimit(data)      ((0x00070000&(data))>>16)
#define IM_DI_RTNR_NEW_MASK2_CTRL2_get_rtnr_mask2_mapthre(data)       ((0x0000F000&(data))>>12)
#define IM_DI_RTNR_NEW_MASK2_CTRL2_get_rtnr_mask2_mapstep(data)       ((0x00000700&(data))>>8)
#define IM_DI_RTNR_NEW_MASK2_CTRL2_get_rtnr_mask2_dir(data)           ((0x00000010&(data))>>4)
#define IM_DI_RTNR_NEW_MASK2_CTRL2_get_rtnr_mask2_en(data)            (0x00000001&(data))


#define IM_DI_SI_BIST_BISR_INFO                                       0x18024330
#define IM_DI_SI_BIST_BISR_INFO_reg_addr                              "0xb8024330"
#define IM_DI_SI_BIST_BISR_INFO_reg                                   0xb8024330
#define IM_DI_SI_BIST_BISR_INFO_inst_addr                             "0x00CC"
#define IM_DI_SI_BIST_BISR_INFO_inst                                  0x00CC
#define IM_DI_SI_BIST_BISR_INFO_bist_rst_shift                        (31)
#define IM_DI_SI_BIST_BISR_INFO_bist_en_shift                         (30)
#define IM_DI_SI_BIST_BISR_INFO_bist_done_shift                       (24)
#define IM_DI_SI_BIST_BISR_INFO_bist_fail_shift                       (0)
#define IM_DI_SI_BIST_BISR_INFO_bist_rst_mask                         (0x80000000)
#define IM_DI_SI_BIST_BISR_INFO_bist_en_mask                          (0x40000000)
#define IM_DI_SI_BIST_BISR_INFO_bist_done_mask                        (0x1F000000)
#define IM_DI_SI_BIST_BISR_INFO_bist_fail_mask                        (0x00FFFFFF)
#define IM_DI_SI_BIST_BISR_INFO_bist_rst(data)                        (0x80000000&((data)<<31))
#define IM_DI_SI_BIST_BISR_INFO_bist_en(data)                         (0x40000000&((data)<<30))
#define IM_DI_SI_BIST_BISR_INFO_bist_done(data)                       (0x1F000000&((data)<<24))
#define IM_DI_SI_BIST_BISR_INFO_bist_fail(data)                       (0x00FFFFFF&(data))
#define IM_DI_SI_BIST_BISR_INFO_get_bist_rst(data)                    ((0x80000000&(data))>>31)
#define IM_DI_SI_BIST_BISR_INFO_get_bist_en(data)                     ((0x40000000&(data))>>30)
#define IM_DI_SI_BIST_BISR_INFO_get_bist_done(data)                   ((0x1F000000&(data))>>24)
#define IM_DI_SI_BIST_BISR_INFO_get_bist_fail(data)                   (0x00FFFFFF&(data))


#define IM_DI_SI_BIST_DRF_INFO_1                                      0x18024334
#define IM_DI_SI_BIST_DRF_INFO_1_reg_addr                             "0xb8024334"
#define IM_DI_SI_BIST_DRF_INFO_1_reg                                  0xb8024334
#define IM_DI_SI_BIST_DRF_INFO_1_inst_addr                            "0x00CD"
#define IM_DI_SI_BIST_DRF_INFO_1_inst                                 0x00CD
#define IM_DI_SI_BIST_DRF_INFO_1_drf_bist_done_shift                  (24)
#define IM_DI_SI_BIST_DRF_INFO_1_drf_bist_fail_shift                  (0)
#define IM_DI_SI_BIST_DRF_INFO_1_drf_bist_done_mask                   (0x1F000000)
#define IM_DI_SI_BIST_DRF_INFO_1_drf_bist_fail_mask                   (0x00FFFFFF)
#define IM_DI_SI_BIST_DRF_INFO_1_drf_bist_done(data)                  (0x1F000000&((data)<<24))
#define IM_DI_SI_BIST_DRF_INFO_1_drf_bist_fail(data)                  (0x00FFFFFF&(data))
#define IM_DI_SI_BIST_DRF_INFO_1_get_drf_bist_done(data)              ((0x1F000000&(data))>>24)
#define IM_DI_SI_BIST_DRF_INFO_1_get_drf_bist_fail(data)              (0x00FFFFFF&(data))


#define IM_DI_SI_BIST_DRF_INFO_2                                      0x18024338
#define IM_DI_SI_BIST_DRF_INFO_2_reg_addr                             "0xb8024338"
#define IM_DI_SI_BIST_DRF_INFO_2_reg                                  0xb8024338
#define IM_DI_SI_BIST_DRF_INFO_2_inst_addr                            "0x00CE"
#define IM_DI_SI_BIST_DRF_INFO_2_inst                                 0x00CE
#define IM_DI_SI_BIST_DRF_INFO_2_drf_start_pause_shift                (0)
#define IM_DI_SI_BIST_DRF_INFO_2_drf_start_pause_mask                 (0x0000001F)
#define IM_DI_SI_BIST_DRF_INFO_2_drf_start_pause(data)                (0x0000001F&(data))
#define IM_DI_SI_BIST_DRF_INFO_2_get_drf_start_pause(data)            (0x0000001F&(data))


#define IM_DI_SI_BIST_DRF_CTRL                                        0x1802433c
#define IM_DI_SI_BIST_DRF_CTRL_reg_addr                               "0xb802433c"
#define IM_DI_SI_BIST_DRF_CTRL_reg                                    0xb802433c
#define IM_DI_SI_BIST_DRF_CTRL_inst_addr                              "0x00CF"
#define IM_DI_SI_BIST_DRF_CTRL_inst                                   0x00CF
#define IM_DI_SI_BIST_DRF_CTRL_drf_test_resume_di_shift               (14)
#define IM_DI_SI_BIST_DRF_CTRL_drf_bist_en_di_shift                   (13)
#define IM_DI_SI_BIST_DRF_CTRL_dvse_di_shift                          (12)
#define IM_DI_SI_BIST_DRF_CTRL_dvs_di_shift                           (8)
#define IM_DI_SI_BIST_DRF_CTRL_drf_test_resume_linebuffer_shift       (6)
#define IM_DI_SI_BIST_DRF_CTRL_drf_bist_en_linebuffer_shift           (5)
#define IM_DI_SI_BIST_DRF_CTRL_dvse_linebuffer_shift                  (4)
#define IM_DI_SI_BIST_DRF_CTRL_dvs_linebuffer_shift                   (0)
#define IM_DI_SI_BIST_DRF_CTRL_drf_test_resume_di_mask                (0x00004000)
#define IM_DI_SI_BIST_DRF_CTRL_drf_bist_en_di_mask                    (0x00002000)
#define IM_DI_SI_BIST_DRF_CTRL_dvse_di_mask                           (0x00001000)
#define IM_DI_SI_BIST_DRF_CTRL_dvs_di_mask                            (0x00000F00)
#define IM_DI_SI_BIST_DRF_CTRL_drf_test_resume_linebuffer_mask        (0x00000040)
#define IM_DI_SI_BIST_DRF_CTRL_drf_bist_en_linebuffer_mask            (0x00000020)
#define IM_DI_SI_BIST_DRF_CTRL_dvse_linebuffer_mask                   (0x00000010)
#define IM_DI_SI_BIST_DRF_CTRL_dvs_linebuffer_mask                    (0x0000000F)
#define IM_DI_SI_BIST_DRF_CTRL_drf_test_resume_di(data)               (0x00004000&((data)<<14))
#define IM_DI_SI_BIST_DRF_CTRL_drf_bist_en_di(data)                   (0x00002000&((data)<<13))
#define IM_DI_SI_BIST_DRF_CTRL_dvse_di(data)                          (0x00001000&((data)<<12))
#define IM_DI_SI_BIST_DRF_CTRL_dvs_di(data)                           (0x00000F00&((data)<<8))
#define IM_DI_SI_BIST_DRF_CTRL_drf_test_resume_linebuffer(data)       (0x00000040&((data)<<6))
#define IM_DI_SI_BIST_DRF_CTRL_drf_bist_en_linebuffer(data)           (0x00000020&((data)<<5))
#define IM_DI_SI_BIST_DRF_CTRL_dvse_linebuffer(data)                  (0x00000010&((data)<<4))
#define IM_DI_SI_BIST_DRF_CTRL_dvs_linebuffer(data)                   (0x0000000F&(data))
#define IM_DI_SI_BIST_DRF_CTRL_get_drf_test_resume_di(data)           ((0x00004000&(data))>>14)
#define IM_DI_SI_BIST_DRF_CTRL_get_drf_bist_en_di(data)               ((0x00002000&(data))>>13)
#define IM_DI_SI_BIST_DRF_CTRL_get_dvse_di(data)                      ((0x00001000&(data))>>12)
#define IM_DI_SI_BIST_DRF_CTRL_get_dvs_di(data)                       ((0x00000F00&(data))>>8)
#define IM_DI_SI_BIST_DRF_CTRL_get_drf_test_resume_linebuffer(data)   ((0x00000040&(data))>>6)
#define IM_DI_SI_BIST_DRF_CTRL_get_drf_bist_en_linebuffer(data)       ((0x00000020&(data))>>5)
#define IM_DI_SI_BIST_DRF_CTRL_get_dvse_linebuffer(data)              ((0x00000010&(data))>>4)
#define IM_DI_SI_BIST_DRF_CTRL_get_dvs_linebuffer(data)               (0x0000000F&(data))


#define IM_DI_SI_BISR_CONTROL                                         0x18024340
#define IM_DI_SI_BISR_CONTROL_reg_addr                                "0xb8024340"
#define IM_DI_SI_BISR_CONTROL_reg                                     0xb8024340
#define IM_DI_SI_BISR_CONTROL_inst_addr                               "0x00D0"
#define IM_DI_SI_BISR_CONTROL_inst                                    0x00D0
#define IM_DI_SI_BISR_CONTROL_bisr_so_1_shift                         (20)
#define IM_DI_SI_BISR_CONTROL_bisr_so_0_shift                         (8)
#define IM_DI_SI_BISR_CONTROL_bisr_hold_remap_shift                   (7)
#define IM_DI_SI_BISR_CONTROL_bisr_cmp_rst_shift                      (6)
#define IM_DI_SI_BISR_CONTROL_bisr_run_rst_shift                      (5)
#define IM_DI_SI_BISR_CONTROL_bisr_run_shift                          (4)
#define IM_DI_SI_BISR_CONTROL_bisr_repaired_shift                     (0)
#define IM_DI_SI_BISR_CONTROL_bisr_so_1_mask                          (0x07F00000)
#define IM_DI_SI_BISR_CONTROL_bisr_so_0_mask                          (0x00007F00)
#define IM_DI_SI_BISR_CONTROL_bisr_hold_remap_mask                    (0x00000080)
#define IM_DI_SI_BISR_CONTROL_bisr_cmp_rst_mask                       (0x00000040)
#define IM_DI_SI_BISR_CONTROL_bisr_run_rst_mask                       (0x00000020)
#define IM_DI_SI_BISR_CONTROL_bisr_run_mask                           (0x00000010)
#define IM_DI_SI_BISR_CONTROL_bisr_repaired_mask                      (0x00000001)
#define IM_DI_SI_BISR_CONTROL_bisr_so_1(data)                         (0x07F00000&((data)<<20))
#define IM_DI_SI_BISR_CONTROL_bisr_so_0(data)                         (0x00007F00&((data)<<8))
#define IM_DI_SI_BISR_CONTROL_bisr_hold_remap(data)                   (0x00000080&((data)<<7))
#define IM_DI_SI_BISR_CONTROL_bisr_cmp_rst(data)                      (0x00000040&((data)<<6))
#define IM_DI_SI_BISR_CONTROL_bisr_run_rst(data)                      (0x00000020&((data)<<5))
#define IM_DI_SI_BISR_CONTROL_bisr_run(data)                          (0x00000010&((data)<<4))
#define IM_DI_SI_BISR_CONTROL_bisr_repaired(data)                     (0x00000001&(data))
#define IM_DI_SI_BISR_CONTROL_get_bisr_so_1(data)                     ((0x07F00000&(data))>>20)
#define IM_DI_SI_BISR_CONTROL_get_bisr_so_0(data)                     ((0x00007F00&(data))>>8)
#define IM_DI_SI_BISR_CONTROL_get_bisr_hold_remap(data)               ((0x00000080&(data))>>7)
#define IM_DI_SI_BISR_CONTROL_get_bisr_cmp_rst(data)                  ((0x00000040&(data))>>6)
#define IM_DI_SI_BISR_CONTROL_get_bisr_run_rst(data)                  ((0x00000020&(data))>>5)
#define IM_DI_SI_BISR_CONTROL_get_bisr_run(data)                      ((0x00000010&(data))>>4)
#define IM_DI_SI_BISR_CONTROL_get_bisr_repaired(data)                 (0x00000001&(data))


#define IM_DI_SI_BISR_DRF_CTRL                                        0x18024344
#define IM_DI_SI_BISR_DRF_CTRL_reg_addr                               "0xb8024344"
#define IM_DI_SI_BISR_DRF_CTRL_reg                                    0xb8024344
#define IM_DI_SI_BISR_DRF_CTRL_inst_addr                              "0x00D1"
#define IM_DI_SI_BISR_DRF_CTRL_inst                                   0x00D1
#define IM_DI_SI_BISR_DRF_CTRL_drf_bisr_mode_2to1_shift               (18)
#define IM_DI_SI_BISR_DRF_CTRL_drf_bisr_rst_2to1_shift                (17)
#define IM_DI_SI_BISR_DRF_CTRL_drf_bisr_resume_2to1_shift             (16)
#define IM_DI_SI_BISR_DRF_CTRL_dvse_1_2to1_shift                      (12)
#define IM_DI_SI_BISR_DRF_CTRL_dvs_1_2to1_shift                       (8)
#define IM_DI_SI_BISR_DRF_CTRL_dvse_0_2to1_shift                      (4)
#define IM_DI_SI_BISR_DRF_CTRL_dvs_0_2to1_shift                       (0)
#define IM_DI_SI_BISR_DRF_CTRL_drf_bisr_mode_2to1_mask                (0x00040000)
#define IM_DI_SI_BISR_DRF_CTRL_drf_bisr_rst_2to1_mask                 (0x00020000)
#define IM_DI_SI_BISR_DRF_CTRL_drf_bisr_resume_2to1_mask              (0x00010000)
#define IM_DI_SI_BISR_DRF_CTRL_dvse_1_2to1_mask                       (0x00001000)
#define IM_DI_SI_BISR_DRF_CTRL_dvs_1_2to1_mask                        (0x00000F00)
#define IM_DI_SI_BISR_DRF_CTRL_dvse_0_2to1_mask                       (0x00000010)
#define IM_DI_SI_BISR_DRF_CTRL_dvs_0_2to1_mask                        (0x0000000F)
#define IM_DI_SI_BISR_DRF_CTRL_drf_bisr_mode_2to1(data)               (0x00040000&((data)<<18))
#define IM_DI_SI_BISR_DRF_CTRL_drf_bisr_rst_2to1(data)                (0x00020000&((data)<<17))
#define IM_DI_SI_BISR_DRF_CTRL_drf_bisr_resume_2to1(data)             (0x00010000&((data)<<16))
#define IM_DI_SI_BISR_DRF_CTRL_dvse_1_2to1(data)                      (0x00001000&((data)<<12))
#define IM_DI_SI_BISR_DRF_CTRL_dvs_1_2to1(data)                       (0x00000F00&((data)<<8))
#define IM_DI_SI_BISR_DRF_CTRL_dvse_0_2to1(data)                      (0x00000010&((data)<<4))
#define IM_DI_SI_BISR_DRF_CTRL_dvs_0_2to1(data)                       (0x0000000F&(data))
#define IM_DI_SI_BISR_DRF_CTRL_get_drf_bisr_mode_2to1(data)           ((0x00040000&(data))>>18)
#define IM_DI_SI_BISR_DRF_CTRL_get_drf_bisr_rst_2to1(data)            ((0x00020000&(data))>>17)
#define IM_DI_SI_BISR_DRF_CTRL_get_drf_bisr_resume_2to1(data)         ((0x00010000&(data))>>16)
#define IM_DI_SI_BISR_DRF_CTRL_get_dvse_1_2to1(data)                  ((0x00001000&(data))>>12)
#define IM_DI_SI_BISR_DRF_CTRL_get_dvs_1_2to1(data)                   ((0x00000F00&(data))>>8)
#define IM_DI_SI_BISR_DRF_CTRL_get_dvse_0_2to1(data)                  ((0x00000010&(data))>>4)
#define IM_DI_SI_BISR_DRF_CTRL_get_dvs_0_2to1(data)                   (0x0000000F&(data))
#endif

