// This file is generated using the spec version 1.39, firmware template version 1.39and SRIF Parser                                                                                source code SVN rev:798                    Version flow no.:1.1.55
#ifndef _AUDIO_REG_H_INCLUDED_
#define _AUDIO_REG_H_INCLUDED_

//#define  _AUDIO_USE_STRUCT
#ifdef _AUDIO_USE_STRUCT

typedef struct
{
    unsigned int    inv_ad_128fs:1;
    unsigned int    reserved_0:1;
    unsigned int    ad_down_sel:2;
    unsigned int    div_pre_512fs_ts:2;
    unsigned int    sel_clk_spdif_out:1;
    unsigned int    sel_clk_i2s_out:1;
    unsigned int    div_dma_r_512fs:2;
    unsigned int    div_tsdma_r_512fs:2;
    unsigned int    reserved_1:20;
}GLOBAL_ctrl_0;

typedef struct
{
    unsigned int    adc_sram_on:1;
    unsigned int    dac_sram_on:1;
    unsigned int    am_sram_on:1;
    unsigned int    a2_eiaj_sram_on:1;
    unsigned int    inv_da_128fs:1;
    unsigned int    inv_da_128fs_ts:1;
    unsigned int    src_da_128fs:1;
    unsigned int    src_da_128fs_ts:1;
    unsigned int    hdv_mode_sel:1;
    unsigned int    sif_adc_clk_sel:2;
    unsigned int    sif_adc_clk_en:1;
    unsigned int    sel_i2s_spdif:1;
    unsigned int    sel_i2s_hdmi:2;
    unsigned int    spdif_nicam:1;
    unsigned int    adc_512fs_sel_ts:2;
    unsigned int    sel_ts_ck_source:2;
    unsigned int    back_end_ts_sample_rate:2;
    unsigned int    da_down_sel_ts:2;
    unsigned int    adc_512fs_sel:2;
    unsigned int    sel_play_ck_source:2;
    unsigned int    back_end_play_sample_rate:2;
    unsigned int    da_down_sel:2;
}GLOBAL_ctrl_1;

typedef struct
{
    unsigned int    contword_inv:1;
    unsigned int    reserved_0:1;
    unsigned int    div_2fs:2;
    unsigned int    reserved_1:1;
    unsigned int    reg_para_e:3;
    unsigned int    reserved_2:2;
    unsigned int    ps_testmode:1;
    unsigned int    ps_contword:5;
    unsigned int    pll_spdif_dtrack_en:1;
    unsigned int    reg_smooth_en:1;
    unsigned int    pll_spdif_auto_mode:1;
    unsigned int    mod_acc_rst:1;
    unsigned int    reg_para_d:4;
    unsigned int    reserved_3:2;
    unsigned int    reg_para_a:6;
}PLLCG_spdif_gain_cr0;

typedef struct
{
    unsigned int    reserved_0:6;
    unsigned int    p_gain_set:10;
    unsigned int    reserved_1:6;
    unsigned int    p_gain_set2:10;
}PLLCG_spdif_gain_cr1;

typedef struct
{
    unsigned int    reserved_0:22;
    unsigned int    i_gain_set:10;
}PLLCG_spdif_gain_cr2;

typedef struct
{
    unsigned int    reserved_0:25;
    unsigned int    reach_time_num:3;
    unsigned int    max_correct_range:4;
}PLLCG_spdif_number;

typedef struct
{
    unsigned int    high_bound1:8;
    unsigned int    low_bound1:8;
    unsigned int    high_bound2:8;
    unsigned int    low_bound2:8;
}PLLCG_spdif_bound;

typedef struct
{
    unsigned int    dummy1800601c_31_16:16;
    unsigned int    reserved_0:13;
    unsigned int    wdog_switch_en:1;
    unsigned int    freq_sel:2;
}GLOBAL_dummy;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    int_fifo0_ts_full_en:1;
    unsigned int    int_fifo0_ts_empty_en:1;
    unsigned int    int_pll64512_wd_en:1;
    unsigned int    int_msd_decision_done_en:1;
    unsigned int    int_msd_fw_scan_done_en:1;
    unsigned int    int_rbus_timeout_en:1;
    unsigned int    int_btsc_mode_chg_en:1;
    unsigned int    int_fifo3_full_en:1;
    unsigned int    int_fifo2_full_en:1;
    unsigned int    int_fifo1_full_en:1;
    unsigned int    int_fifo0_full_en:1;
    unsigned int    int_fifo3_empty_en:1;
    unsigned int    int_fifo2_empty_en:1;
    unsigned int    int_fifo1_empty_en:1;
    unsigned int    int_fifo0_empty_en:1;
    unsigned int    int_nicam_level_status_en:1;
    unsigned int    int_ain_timer_en:1;
    unsigned int    int_aout_timer_en:1;
    unsigned int    int_spi_in_datatype_change_en:1;
    unsigned int    int_spi_in_lock_change_en:1;
    unsigned int    int_nicam_hierr_change_en:1;
    unsigned int    int_i2s_pri_sample_rate_chg_en:1;
    unsigned int    int_i2s_sec_sample_rate_chg_en:1;
    unsigned int    int_spi_sample_rate_chg_en:1;
    unsigned int    int_i2s_pri_word_length_change_en:1;
    unsigned int    int_i2s_sec_word_length_change_en:1;
    unsigned int    int_sif_nopt_en:1;
    unsigned int    int_msd_change_en:1;
    unsigned int    int_msd_timeout_en:1;
    unsigned int    int_mode_det_status_change_en:1;
    unsigned int    int_sif_ovf_en:1;
}INTERRUPT_en;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    int_fifo0_ts_full:1;
    unsigned int    int_fifo0_ts_empty:1;
    unsigned int    int_pll64512_wd:1;
    unsigned int    int_msd_decision_done:1;
    unsigned int    int_msd_fw_scan_done:1;
    unsigned int    int_rbus_timeout:1;
    unsigned int    int_btsc_mode_chg:1;
    unsigned int    int_fifo3_full:1;
    unsigned int    int_fifo2_full:1;
    unsigned int    int_fifo1_full:1;
    unsigned int    int_fifo0_full:1;
    unsigned int    int_fifo3_empty:1;
    unsigned int    int_fifo2_empty:1;
    unsigned int    int_fifo1_empty:1;
    unsigned int    int_fifo0_empty:1;
    unsigned int    int_nicam_level_status:1;
    unsigned int    int_ain_timer:1;
    unsigned int    int_aout_timer:1;
    unsigned int    int_spi_in_datatype_change:1;
    unsigned int    int_spi_in_lock_change:1;
    unsigned int    int_nicam_hierr_change:1;
    unsigned int    int_i2s_pri_sample_rate_chg:1;
    unsigned int    int_i2s_sec_sample_rate_chg:1;
    unsigned int    int_spi_sample_rate_chg:1;
    unsigned int    int_i2s_pri_word_length_change:1;
    unsigned int    int_i2s_sec_word_length_change:1;
    unsigned int    int_sif_nopt:1;
    unsigned int    int_msd_change:1;
    unsigned int    int_msd_timeout:1;
    unsigned int    int_mode_det_status_change:1;
    unsigned int    int_sif_ovf:1;
}INTERRUPT_status;

typedef struct
{
    unsigned int    reserved_0:30;
    unsigned int    ain_timer_en:1;
    unsigned int    aout_timer_en:1;
}AIO_timer_en;

typedef struct
{
    unsigned int    ain_timer:32;
}AIN_counter;

typedef struct
{
    unsigned int    ain_compare:32;
}AIN_compare;

typedef struct
{
    unsigned int    aout_timer:32;
}AOUT_counter;

typedef struct
{
    unsigned int    aout_compare:32;
}AOUT_compare;

typedef struct
{
    unsigned int    source_sel:2;
    unsigned int    left_right:2;
    unsigned int    mode_sel:1;
    unsigned int    debounce_en:1;
    unsigned int    sclk_inv:1;
    unsigned int    dummy18006100_24_16:9;
    unsigned int    reserved_0:4;
    unsigned int    sampling_rate:4;
    unsigned int    reserved_1:1;
    unsigned int    pcm_width:7;
}I2S_in_primary;

typedef struct
{
    unsigned int    source_sel:2;
    unsigned int    left_right:2;
    unsigned int    mode_sel:1;
    unsigned int    debounce_en:1;
    unsigned int    sclk_inv:1;
    unsigned int    reserved_0:13;
    unsigned int    sampling_rate:4;
    unsigned int    reserved_1:1;
    unsigned int    pcm_width:7;
}I2S_in_secondary;

typedef struct
{
    unsigned int    source_sel:2;
    unsigned int    req_after_lock:1;
    unsigned int    debounce_en:1;
    unsigned int    reserved_0:12;
    unsigned int    dummy18006130_15_5:11;
    unsigned int    reserved_1:1;
    unsigned int    sampling_rate:4;
}SPDIF_in;

typedef struct
{
    unsigned int    hw_locked:1;
    unsigned int    invalid_bit:1;
    unsigned int    clock_accuracy:2;
    unsigned int    sampling_freq:4;
    unsigned int    channel_number:4;
    unsigned int    source_number:4;
    unsigned int    category_code:8;
    unsigned int    mode:2;
    unsigned int    pre_emphasis:3;
    unsigned int    copyright:1;
    unsigned int    data_type:1;
    unsigned int    professional:1;
}SPDIF_in_cs;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    output_sel:3;
    unsigned int    reserved_1:2;
    unsigned int    mclk_sel:2;
    unsigned int    reserved_2:5;
    unsigned int    pcm_source_sel:1;
    unsigned int    wclk_inv:1;
    unsigned int    sclk_inv:1;
    unsigned int    dummy18006150_15_0:16;
}I2S_out;

typedef struct
{
    unsigned int    output_sel:2;
    unsigned int    pcm_source_sel:1;
    unsigned int    validity_ctrl:1;
    unsigned int    reserved_0:12;
    unsigned int    dummy18006170_15_0:16;
}SPDIF_out;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    clock_accuracy:2;
    unsigned int    sampling_freq:4;
    unsigned int    channel_number:4;
    unsigned int    source_number:4;
    unsigned int    category_code:8;
    unsigned int    mode:2;
    unsigned int    pre_emphasis:3;
    unsigned int    copyright:1;
    unsigned int    data_type:1;
    unsigned int    professional:1;
}SPDIF_out_cs;

typedef struct
{
    unsigned int    reserved_0:12;
    unsigned int    dummy18006180_19_17:3;
    unsigned int    hw_agc_en:1;
    unsigned int    ob_time:16;
}SIF_agc_eval_cnt;

typedef struct
{
    unsigned int    reserved_0:13;
    unsigned int    non_opt_cnt_th:3;
    unsigned int    non_opt_cnt_under:8;
    unsigned int    non_opt_cnt_ovf:8;
}SIF_agc_optimal;

typedef struct
{
    unsigned int    reserved_0:6;
    unsigned int    ovf_th:10;
    unsigned int    reserved_1:6;
    unsigned int    opt_th:10;
}SIF_agc_threshold;

typedef struct
{
    unsigned int    reserved_0:18;
    unsigned int    ovf:1;
    unsigned int    opt:1;
    unsigned int    reserved_1:2;
    unsigned int    abs_peak:10;
}SIF_agc_status;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    agc2_debounce_cnt:3;
    unsigned int    agc2_stepsize:2;
    unsigned int    agc2_gain_a:2;
    unsigned int    reserved_1:2;
    unsigned int    agc2_gain_b:6;
    unsigned int    agc2_obtime:16;
}SIF_agc2_ctrl;

typedef struct
{
    unsigned int    agc2_en:1;
    unsigned int    reserved_0:1;
    unsigned int    agc2_overflow:1;
    unsigned int    agc2_underflow:1;
    unsigned int    reserved_1:18;
    unsigned int    agc2_sif_mag:10;
}SIF_agc2_status;

typedef struct
{
    unsigned int    reserved_0:27;
    unsigned int    pdetect_enable:1;
    unsigned int    detect_source_sel:4;
}PEAK_contorl;

typedef struct
{
    unsigned int    opt_th_l:16;
    unsigned int    ovf_th_l:16;
}PEAK_contorl_l_0;

typedef struct
{
    unsigned int    dummy180061ac_31_19:13;
    unsigned int    nonopt_cnt_tr_l:3;
    unsigned int    reserved_0:2;
    unsigned int    vpp_eval_cnt_l:14;
}PEAK_control_l_1;

typedef struct
{
    unsigned int    optimize_l_irq_en:1;
    unsigned int    overflow_l_irq_en:1;
    unsigned int    reserved_0:6;
    unsigned int    optimize_l:1;
    unsigned int    overflow_l:1;
    unsigned int    pk_adj_l:6;
    unsigned int    magnitude_l:16;
}PEAK_status_l;

typedef struct
{
    unsigned int    opt_th_r:16;
    unsigned int    ovf_th_r:16;
}PEAK_contorl_r_0;

typedef struct
{
    unsigned int    dummy180061b8_31_19:13;
    unsigned int    nonopt_cnt_tr_r:3;
    unsigned int    reserved_0:2;
    unsigned int    vpp_eval_cnt_r:14;
}PEAK_contorl_r_1;

typedef struct
{
    unsigned int    optimize_r_irq_en:1;
    unsigned int    overflow_r_irq_en:1;
    unsigned int    reserved_0:6;
    unsigned int    optimize_r:1;
    unsigned int    overflow_r:1;
    unsigned int    pk_adj_r:6;
    unsigned int    magnitude_r:16;
}PEAK_status_r;

typedef struct
{
    unsigned int    reserved_0:25;
    unsigned int    post_detect_source_sel:3;
    unsigned int    reserved_1:3;
    unsigned int    post_detect_enable:1;
}POST_peak_contorl;

typedef struct
{
    unsigned int    post_opt_th_l:16;
    unsigned int    post_ovf_th_l:16;
}POST_peak_contorl_l_0;

typedef struct
{
    unsigned int    reserved_0:13;
    unsigned int    post_nonopt_cnt_tr_l:3;
    unsigned int    reserved_1:2;
    unsigned int    post_vpp_eval_cnt_l:14;
}POST_peak_control_l_1;

typedef struct
{
    unsigned int    post_optimize_l_irq_en:1;
    unsigned int    post_overflow_l_irq_en:1;
    unsigned int    reserved_0:6;
    unsigned int    post_optimize_l:1;
    unsigned int    post_overflow_l:1;
    unsigned int    post_pk_adj_l:6;
    unsigned int    post_magnitude_l:16;
}POST_peak_status_l;

typedef struct
{
    unsigned int    post_opt_th_r:16;
    unsigned int    post_ovf_th_r:16;
}POST_peak_contorl_r_0;

typedef struct
{
    unsigned int    reserved_0:13;
    unsigned int    post_nonopt_cnt_tr_r:3;
    unsigned int    reserved_1:2;
    unsigned int    post_vpp_eval_cnt_r:14;
}POST_peak_contorl_r_1;

typedef struct
{
    unsigned int    post_optimize_r_irq_en:1;
    unsigned int    post_overflow_r_irq_en:1;
    unsigned int    reserved_0:6;
    unsigned int    post_optimize_r:1;
    unsigned int    post_overflow_r:1;
    unsigned int    post_pk_adj_r:6;
    unsigned int    post_magnitude_r:16;
}POST_peak_status_r;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    fw_scan_en:1;
    unsigned int    msd_en:1;
    unsigned int    update_en:1;
    unsigned int    carrier_shift_scan_en:1;
    unsigned int    carrier_phase_delta:3;
    unsigned int    reserved_1:1;
    unsigned int    msd_debounce_cnt:3;
    unsigned int    reg_scan_cnt:8;
    unsigned int    reserved_2:1;
    unsigned int    mn_priority:2;
    unsigned int    dkl_priority:1;
    unsigned int    reserved_3:2;
    unsigned int    sound_select:2;
    unsigned int    reserved_4:4;
}MSD_crtl_word;

typedef struct
{
    unsigned int    reserved_0:6;
    unsigned int    deviation_unnormal:2;
    unsigned int    case_subtomain:4;
    unsigned int    reserved_1:1;
    unsigned int    flag_unnormal:1;
    unsigned int    flag_subtomain:1;
    unsigned int    h_dv_th_sel:1;
    unsigned int    reserved_2:3;
    unsigned int    hw_detected_std:5;
    unsigned int    reserved_3:3;
    unsigned int    reg_std:5;
}MSD_result;

typedef struct
{
    unsigned int    reserved_0:3;
    unsigned int    bw_cnt_max:5;
    unsigned int    reserved_1:3;
    unsigned int    bw_cnt_min:5;
    unsigned int    reserved_2:4;
    unsigned int    shift_value:4;
    unsigned int    reserved_3:1;
    unsigned int    main_cari_idx:3;
    unsigned int    deviation:4;
}MSD_status;

typedef struct
{
    unsigned int    main_thresh:16;
    unsigned int    main_thresh_low:16;
}MAIN_tone_threshold;

typedef struct
{
    unsigned int    main_thresh_hd:16;
    unsigned int    main_thresh_hd_low:16;
}MAIN_tone_threshold_hd;

typedef struct
{
    unsigned int    bw_dev_thresh_hd:16;
    unsigned int    bw_dev_thresh:16;
}BW_threshold;

typedef struct
{
    unsigned int    bw_dev_thresh_low:16;
    unsigned int    main_sub_ratio:16;
}MAIN_sub_ratio;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    reg_mag_4_5:16;
}MSD_mag_4_5;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    reg_mag_4_28:16;
}MSD_mag_4_28;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    reg_mag_4_72:16;
}MSD_mag_4_72;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    reg_mag_5_5:16;
}MSD_mag_5_5;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    reg_mag_5_25:16;
}MSD_mag_5_25;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    reg_mag_5_74:16;
}MSD_mag_5_74;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    reg_mag_5_85:16;
}MSD_carrier_5_85;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    reg_mag_5_95:16;
}MSD_carrier_5_95;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    reg_mag_6:16;
}MSD_mag_6;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    reg_mag_6_25:16;
}MSD_mag_6_25;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    reg_mag_6_5:16;
}MSD_carrier_6_5;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    reg_mag_6_552:16;
}MSD_mag_6_552;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    reg_mag_6_74:16;
}MSD_carrier_6_74;

typedef struct
{
    unsigned int    reserved_0:17;
    unsigned int    flag_fw_4:1;
    unsigned int    flag_fw_3:1;
    unsigned int    flag_fw_2:1;
    unsigned int    flag_fw_1:1;
    unsigned int    flag_fw:1;
    unsigned int    flag_4_5:1;
    unsigned int    flag_5_5:1;
    unsigned int    flag_6:1;
    unsigned int    flag_6_5:1;
    unsigned int    flag_4_72:1;
    unsigned int    flag_5_74:1;
    unsigned int    flag_5_85:1;
    unsigned int    flag_6_25:1;
    unsigned int    flag_6_552:1;
    unsigned int    flag_6_74:1;
}MSD_flags;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    fw_phase_delta:14;
    unsigned int    reg_mag_fw:16;
}MSD_programmable_freq;

typedef struct
{
    unsigned int    fw_thresh:16;
    unsigned int    fw_thresh_low:16;
}THRESHOLD_msd_carrier_fw;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    fw_phase_delta_1:14;
    unsigned int    reg_mag_fw_1:16;
}MSD_programmable_freq_1;

typedef struct
{
    unsigned int    fw_thresh_1:16;
    unsigned int    fw_thresh_1_low:16;
}THRESHOLD_msd_carrier_fw_1;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    fw_phase_delta_2:14;
    unsigned int    reg_mag_fw_2:16;
}MSD_programmable_freq_2;

typedef struct
{
    unsigned int    fw_thresh_2:16;
    unsigned int    fw_thresh_2_low:16;
}THRESHOLD_msd_carrier_fw_2;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    fw_phase_delta_3:14;
    unsigned int    reg_mag_fw_3:16;
}MSD_programmable_freq_3;

typedef struct
{
    unsigned int    fw_thresh_3:16;
    unsigned int    fw_thresh_3_low:16;
}THRESHOLD_msd_carrier_fw_3;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    fw_phase_delta_4:14;
    unsigned int    reg_mag_fw_4:16;
}MSD_programmable_freq_4;

typedef struct
{
    unsigned int    fw_thresh_4:16;
    unsigned int    fw_thresh_4_low:16;
}THRESHOLD_msd_carrier_fw_4;

typedef struct
{
    unsigned int    reserved_0:21;
    unsigned int    reg_cari_sft_detect_en:1;
    unsigned int    reg_bw_detect_en:1;
    unsigned int    mono_std_sel:1;
    unsigned int    reserved_1:3;
    unsigned int    second_reg_std:5;
}MSD_second_reg_std;

typedef struct
{
    unsigned int    sec_thresh:16;
    unsigned int    sec_thresh_low:16;
}SECOND_main_tone_threshold;

typedef struct
{
    unsigned int    reserved_0:18;
    unsigned int    dvse_0_msd:1;
    unsigned int    dvs_0_msd:4;
    unsigned int    drf_start_pause_msd:1;
    unsigned int    drf_test_resume_msd:1;
    unsigned int    drf_bist_mode_msd:1;
    unsigned int    drf_bist_done_msd:1;
    unsigned int    drf_bist_fail_msd:1;
    unsigned int    bist_rstn_msd:1;
    unsigned int    bist_mode_msd:1;
    unsigned int    bist_done_msd:1;
    unsigned int    bist_fail_msd:1;
}MSD_bist;

typedef struct
{
    unsigned int    reg_mag_45_fix:16;
    unsigned int    reg_mag_55_fix:16;
}MSD_main_mag_ori1;

typedef struct
{
    unsigned int    reg_mag_60_fix:16;
    unsigned int    reg_mag_65_fix:16;
}MSD_main_mag_ori2;

typedef struct
{
    unsigned int    reserved_0:27;
    unsigned int    msd_gain_en:1;
    unsigned int    msd_gain_result:4;
}MSD_gain_ctrl;

typedef struct
{
    unsigned int    dummy18006294_31_16:16;
    unsigned int    msd_update_count:16;
}MSD_update_count;

typedef struct
{
    unsigned int    md_update_count:16;
    unsigned int    reserved_0:13;
    unsigned int    hw_mode_en:1;
    unsigned int    mode_result:2;
}MODE_detect;

typedef struct
{
    unsigned int    enable:1;
    unsigned int    accu_num:3;
    unsigned int    high_threshold:2;
    unsigned int    low_threshold:2;
    unsigned int    reserved_0:1;
    unsigned int    debounce_cnt:3;
    unsigned int    reserved_1:4;
    unsigned int    max_threshold:16;
}MD_ctrl;

typedef struct
{
    unsigned int    max_other:16;
    unsigned int    dummy18006308_15_8:8;
    unsigned int    gain_result:4;
    unsigned int    reserved_0:2;
    unsigned int    mode_result:2;
}MD_status_1;

typedef struct
{
    unsigned int    max_stereo:16;
    unsigned int    max_dual:16;
}MD_status_2;

typedef struct
{
    unsigned int    rst_n:1;
    unsigned int    enable:1;
    unsigned int    done:1;
    unsigned int    dvse_0_md:1;
    unsigned int    dvs_0_md:4;
    unsigned int    drf_start_pause_md:1;
    unsigned int    drf_test_resume_md:1;
    unsigned int    drf_bist_mode_md:1;
    unsigned int    drf_bist_done_md:1;
    unsigned int    drf_bist_fail_52x16_md:1;
    unsigned int    drf_bist_fail_51x16_md:1;
    unsigned int    reserved_0:16;
    unsigned int    fail_52x16:1;
    unsigned int    fail_51x16:1;
}MBIST_md;

typedef struct
{
    unsigned int    sif_data_source:1;
    unsigned int    reserved_0:30;
    unsigned int    carrier_freq_correct_en:1;
}CARRIER_freq_deviation_ctrl;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    main_phase_delta:14;
    unsigned int    reserved_1:2;
    unsigned int    sub_phase_delta:14;
}CARRIER_phase_delta;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    dummy18006360_7_4:4;
    unsigned int    reserved_1:1;
    unsigned int    am_path_sel:1;
    unsigned int    hw_am_prescale:2;
}AM;

typedef struct
{
    unsigned int    reserved_0:10;
    unsigned int    dvse_0_am:1;
    unsigned int    dvs_0_am:4;
    unsigned int    drf_start_pause_am:1;
    unsigned int    drf_test_resume_am:1;
    unsigned int    drf_bist_mode_am:1;
    unsigned int    drf_bist_done_am:1;
    unsigned int    drf_bist_fail_am:1;
    unsigned int    bist_rstn_am:1;
    unsigned int    bist_mode_am:1;
    unsigned int    bist_done_am:1;
    unsigned int    bist_fail_am:1;
    unsigned int    reserved_1:8;
}BIST_am;

typedef struct
{
    unsigned int    lock_reference:1;
    unsigned int    reserved_0:5;
    unsigned int    pilot_hithresh:10;
    unsigned int    reserved_1:6;
    unsigned int    pilot_lothresh:10;
}BTSC_pilot_thres;

typedef struct
{
    unsigned int    reserved_0:15;
    unsigned int    w1pilotpresent:1;
    unsigned int    w1pilotlocked:1;
    unsigned int    pilot_level_pass:1;
    unsigned int    pilot_hi_pass:1;
    unsigned int    pilot_lo_refuse:1;
    unsigned int    reserved_1:2;
    unsigned int    w10pilotmagnitude:10;
}BTSC_pilot_status;

typedef struct
{
    unsigned int    reserved_0:6;
    unsigned int    sap_hithresh:10;
    unsigned int    reserved_1:6;
    unsigned int    sap_lothresh:10;
}BTSC_sap_thresh;

typedef struct
{
    unsigned int    reserved_0:22;
    unsigned int    w10sapnoise:10;
}BTSC_sap_noise;

typedef struct
{
    unsigned int    reserved_0:6;
    unsigned int    sap_noise_hi_thresh:10;
    unsigned int    reserved_1:6;
    unsigned int    sap_noise_lo_thresh:10;
}BTSC_sap_noise_th;

typedef struct
{
    unsigned int    reserved_0:27;
    unsigned int    sap_debounce_en:1;
    unsigned int    sap_debounce:4;
}BTSC_sap_debounce;

typedef struct
{
    unsigned int    reserved_0:17;
    unsigned int    w1sapqualitygood:1;
    unsigned int    sap_hi_pass:1;
    unsigned int    sap_lo_refuse:1;
    unsigned int    sap_noise_flag:1;
    unsigned int    reserved_1:1;
    unsigned int    w10sapmagnitude:10;
}BTSC_sap_status;

typedef struct
{
    unsigned int    reserved_0:18;
    unsigned int    fm_mag_overflow:1;
    unsigned int    fm_mag_optimize:1;
    unsigned int    reserved_1:2;
    unsigned int    w10fmmagnitude:10;
}BTSC_sif_fm_magnitude;

typedef struct
{
    unsigned int    reserved_0:28;
    unsigned int    testoutputselect:4;
}BTSC_test_mux_sel;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    dummy_6424:16;
}BTSC_dummy;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    btsc_main_phase_delta:12;
    unsigned int    reserved_1:15;
    unsigned int    btsc_carrier_freq_correct_en:1;
}BTSC_carrier_freq_deviation_ctrl;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    unlock_p_gain:4;
    unsigned int    unlock_i_gain:4;
    unsigned int    locked_p_gain:4;
    unsigned int    locked_i_gain:4;
}PHASE_error_pi_gain;

typedef struct
{
    unsigned int    sap_hpf_en:1;
    unsigned int    reserved_0:7;
    unsigned int    phase_err_threshold:24;
}PHASE_err_threshold;

typedef struct
{
    unsigned int    a2_bw_sel:2;
    unsigned int    de_emphasis_time:2;
    unsigned int    iir_lpf_en:1;
    unsigned int    ultra_hdv_mode:1;
    unsigned int    reserved_0:15;
    unsigned int    fm1_deviation_gain:3;
    unsigned int    reserved_1:1;
    unsigned int    fm2_deviation_gain:3;
    unsigned int    reserved_2:3;
    unsigned int    eiaj_sub_deviation:1;
}A2_eiaj_demod;

typedef struct
{
    unsigned int    rst_n:1;
    unsigned int    enable:1;
    unsigned int    done:1;
    unsigned int    dvse_0_a2_eiaj:1;
    unsigned int    dvs_0_a2_eiaj:4;
    unsigned int    drf_start_pause_a2_eiaj:1;
    unsigned int    drf_test_resume_a2_eiaj:1;
    unsigned int    drf_bist_mode_a2_eiaj:1;
    unsigned int    drf_bist_done_a2_eiaj:1;
    unsigned int    drf_fail_24x98_1:1;
    unsigned int    drf_fail_24x98_0:1;
    unsigned int    drf_fail_24x74_0:1;
    unsigned int    drf_fail_24x66_1:1;
    unsigned int    drf_fail_24x66_0:1;
    unsigned int    drf_fail_24x14_1:1;
    unsigned int    drf_fail_24x14_0:1;
    unsigned int    drf_fail_24x13_1:1;
    unsigned int    drf_fail_24x13_0:1;
    unsigned int    reserved_0:2;
    unsigned int    fail_24x98_1:1;
    unsigned int    fail_24x98_0:1;
    unsigned int    fail_24x74_0:1;
    unsigned int    fail_24x66_1:1;
    unsigned int    fail_24x66_0:1;
    unsigned int    fail_24x14_1:1;
    unsigned int    fail_24x14_0:1;
    unsigned int    fail_24x13_1:1;
    unsigned int    fail_24x13_0:1;
}MBIST_a2_eiaj_demod;

typedef struct
{
    unsigned int    magnitude:16;
    unsigned int    dummy18006458_15_0:16;
}A2_eiaj_dc_filter;

typedef struct
{
    unsigned int    psf_sel:1;
    unsigned int    tr_lpf_kp:3;
    unsigned int    reserved_0:1;
    unsigned int    cr_lpf_kp:3;
    unsigned int    reserved_1:2;
    unsigned int    cr_lpf_ki:2;
    unsigned int    tr_timing_step:20;
}NICAM_demod;

typedef struct
{
    unsigned int    enable:1;
    unsigned int    debounce_cnt:3;
    unsigned int    reserved_0:2;
    unsigned int    window_size:10;
    unsigned int    reserved_1:10;
    unsigned int    gain_adjust:6;
}NICAM_dagc_ctrl;

typedef struct
{
    unsigned int    high:16;
    unsigned int    low:16;
}NICAM_dagc_threshold;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    magnitude:16;
}NICAM_dagc_mag;

typedef struct
{
    unsigned int    resampler_ctrl:1;
    unsigned int    data_channel_sel:1;
    unsigned int    pcm_l_out_sel:1;
    unsigned int    pcm_r_out_sel:1;
    unsigned int    cib_1:1;
    unsigned int    cib_0:1;
    unsigned int    cib_mask:1;
    unsigned int    reserved_0:1;
    unsigned int    status_debounce_cnt:4;
    unsigned int    bypass_interpol:1;
    unsigned int    sat_en:1;
    unsigned int    de_em_by_pass:1;
    unsigned int    level_sel:1;
    unsigned int    dummy18006510_15_0:16;
}NICAM_decode_ctrl;

typedef struct
{
    unsigned int    c0:1;
    unsigned int    c1c2c3:3;
    unsigned int    c4:1;
    unsigned int    additional_data:11;
    unsigned int    reserved_0:2;
    unsigned int    bit_cnt_sync:1;
    unsigned int    true_detect:1;
    unsigned int    bit_error_rate:12;
}NICAM_decode_status;

typedef struct
{
    unsigned int    enable:1;
    unsigned int    reserved_0:1;
    unsigned int    c4_hi_ber:2;
    unsigned int    analog_flag:1;
    unsigned int    hi_ber_debounce:3;
    unsigned int    high_threshold:12;
    unsigned int    low_threshold:12;
}NICAM_auto_switch;

typedef struct
{
    unsigned int    enable:1;
    unsigned int    reserved_0:1;
    unsigned int    duration:2;
    unsigned int    reserved_1:28;
}NICAM_demod_auto_recovery;

typedef struct
{
    unsigned int    fifo_ch7_source:2;
    unsigned int    fifo_ch8_source:2;
    unsigned int    fifo_ch5_source:2;
    unsigned int    fifo_ch6_source:2;
    unsigned int    fifo_ch3_source:2;
    unsigned int    fifo_ch4_source:2;
    unsigned int    fifo_ch1_source:2;
    unsigned int    fifo_ch2_source:2;
    unsigned int    reserved_0:13;
    unsigned int    backend_play_en:1;
    unsigned int    downsample_en:1;
    unsigned int    down_rate:1;
}DOWN_sample_control_for_playback;

typedef struct
{
    unsigned int    fifo_ch78_scale:4;
    unsigned int    fifo_ch56_scale:4;
    unsigned int    fifo_ch34_scale:4;
    unsigned int    fifo_ch12_scale:4;
    unsigned int    fifo_ch78_sel:4;
    unsigned int    fifo_ch56_sel:4;
    unsigned int    fifo_ch34_sel:4;
    unsigned int    fifo_ch12_sel:4;
}DOWN_sample_fifo_source_sel;

typedef struct
{
    unsigned int    dummy18006558_31_14:18;
    unsigned int    playback_dvse_0:1;
    unsigned int    playback_dvs_0:4;
    unsigned int    playback_drf_start_pause:1;
    unsigned int    playback_drf_test_resume:1;
    unsigned int    playback_drf_bist_mode:1;
    unsigned int    playback_drf_bist_done:1;
    unsigned int    playback_drf_bist_fail:1;
    unsigned int    playback_bist_rstn:1;
    unsigned int    playback_bist_mode:1;
    unsigned int    playback_bist_done:1;
    unsigned int    playback_bist_fail:1;
}DOWN_sample_mbist_recoding;

typedef struct
{
    unsigned int    dma_wr_src_sel:2;
    unsigned int    dma_output_src_sel:2;
    unsigned int    dma_w_format:1;
    unsigned int    dma_r_format:1;
    unsigned int    reserved_0:4;
    unsigned int    hbr_wr_channel_no:2;
    unsigned int    wr_channel_no:3;
    unsigned int    aidmatype:1;
    unsigned int    rd_channel_no:3;
    unsigned int    aodmatype:1;
    unsigned int    dma_mode:1;
    unsigned int    int_rd_en:1;
    unsigned int    int_wr_en:1;
    unsigned int    dma_int_en:1;
    unsigned int    dma_soft_rd_rst:1;
    unsigned int    dma_soft_wr_rst:1;
    unsigned int    dma_read_enable:1;
    unsigned int    dma_write_enable:1;
    unsigned int    overflow_dma_status:1;
    unsigned int    unflow_dma_status:1;
    unsigned int    wr_intr_dma_status:1;
    unsigned int    rd_intr_dma_status:1;
}ADMA_csr;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    avail_length:15;
    unsigned int    reserved_1:1;
    unsigned int    wr_intr_point:15;
}ADMA_wconf;

typedef struct
{
    unsigned int    wr_start_addr0:26;
    unsigned int    reserved_0:6;
}ADMA_wsadr0;

typedef struct
{
    unsigned int    wr_start_addr1:26;
    unsigned int    reserved_0:6;
}ADMA_wsadr1;

typedef struct
{
    unsigned int    wr_start_addr2:26;
    unsigned int    reserved_0:6;
}ADMA_wsadr2;

typedef struct
{
    unsigned int    wr_start_addr3:26;
    unsigned int    reserved_0:6;
}ADMA_wsadr3;

typedef struct
{
    unsigned int    wr_start_addr4:26;
    unsigned int    reserved_0:6;
}ADMA_wsadr4;

typedef struct
{
    unsigned int    wr_start_addr5:26;
    unsigned int    reserved_0:6;
}ADMA_wsadr5;

typedef struct
{
    unsigned int    wr_start_addr6:26;
    unsigned int    reserved_0:6;
}ADMA_wsadr6;

typedef struct
{
    unsigned int    wr_start_addr7:26;
    unsigned int    reserved_0:6;
}ADMA_wsadr7;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    read_length:15;
    unsigned int    reserved_1:1;
    unsigned int    read_intr_point:15;
}ADMA_rconf;

typedef struct
{
    unsigned int    rd_start_addr0:26;
    unsigned int    reserved_0:6;
}ADMA_rsadr0;

typedef struct
{
    unsigned int    rd_start_addr1:26;
    unsigned int    reserved_0:6;
}ADMA_rsadr1;

typedef struct
{
    unsigned int    rd_start_addr2:26;
    unsigned int    reserved_0:6;
}ADMA_rsadr2;

typedef struct
{
    unsigned int    rd_start_addr3:26;
    unsigned int    reserved_0:6;
}ADMA_rsadr3;

typedef struct
{
    unsigned int    rd_start_addr4:26;
    unsigned int    reserved_0:6;
}ADMA_rsadr4;

typedef struct
{
    unsigned int    rd_start_addr5:26;
    unsigned int    reserved_0:6;
}ADMA_rsadr5;

typedef struct
{
    unsigned int    rd_start_addr6:26;
    unsigned int    reserved_0:6;
}ADMA_rsadr6;

typedef struct
{
    unsigned int    rd_start_addr7:26;
    unsigned int    reserved_0:6;
}ADMA_rsadr7;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    wr_buffer_length:15;
    unsigned int    reserved_1:1;
    unsigned int    rd_buffer_length:15;
}ADMA_chconf;

typedef struct
{
    unsigned int    ts_dma_wr_src_sel:2;
    unsigned int    ts_dma_output_src_sel:2;
    unsigned int    ts_dma_w_format:1;
    unsigned int    ts_dma_r_format:1;
    unsigned int    reserved_0:4;
    unsigned int    ts_hbr_wr_channel_no:2;
    unsigned int    ts_wr_channel_no:3;
    unsigned int    ts_aidmatype:1;
    unsigned int    ts_rd_channel_no:3;
    unsigned int    ts_aodmatype:1;
    unsigned int    ts_dma_mode:1;
    unsigned int    ts_int_rd_en:1;
    unsigned int    ts_int_wr_en:1;
    unsigned int    ts_dma_int_en:1;
    unsigned int    ts_dma_soft_rd_rst:1;
    unsigned int    ts_dma_soft_wr_rst:1;
    unsigned int    ts_dma_read_enable:1;
    unsigned int    ts_dma_write_enable:1;
    unsigned int    ts_overflow_dma_status:1;
    unsigned int    ts_unflow_dma_status:1;
    unsigned int    ts_wr_intr_dma_status:1;
    unsigned int    ts_rd_intr_dma_status:1;
}TSADMA_csr;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    ts_avail_length:15;
    unsigned int    reserved_1:1;
    unsigned int    ts_wr_intr_point:15;
}TS_adma_wconf;

typedef struct
{
    unsigned int    ts_wr_start_addr0:26;
    unsigned int    reserved_0:6;
}TS_adma_wsadr0;

typedef struct
{
    unsigned int    ts_wr_start_addr1:26;
    unsigned int    reserved_0:6;
}TS_adma_wsadr1;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    ts_read_length:15;
    unsigned int    reserved_1:1;
    unsigned int    ts_read_intr_point:15;
}TS_adma_rconf;

typedef struct
{
    unsigned int    ts_rd_start_addr0:26;
    unsigned int    reserved_0:6;
}TS_adma_rsadr0;

typedef struct
{
    unsigned int    ts_rd_start_addr1:26;
    unsigned int    reserved_0:6;
}TS_adma_rsadr1;

typedef struct
{
    unsigned int    ts_rd_start_addr2:26;
    unsigned int    reserved_0:6;
}TS_adma_rsadr2;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    ts_wr_buffer_length:15;
    unsigned int    reserved_1:1;
    unsigned int    ts_rd_buffer_length:15;
}TS_adma_chconf;

typedef struct
{
    unsigned int    reserved_0:18;
    unsigned int    dvse_0_tsdma_bus:1;
    unsigned int    dvs_0_tsdma_bus:4;
    unsigned int    drf_start_pause_tsdma:1;
    unsigned int    drf_test_resume_tsdma:1;
    unsigned int    drf_bist_mode_tsdma:1;
    unsigned int    drf_bist_done_tsdma:1;
    unsigned int    drf_bist_fail_tsdma:1;
    unsigned int    bist_mode_tsdma:1;
    unsigned int    bist_rstn_tsdma:1;
    unsigned int    bist_done_tsdma:1;
    unsigned int    bist_fail_tsdma:1;
}TS_dma_bist_control_indicate;

typedef struct
{
    unsigned int    reserved_0:18;
    unsigned int    dvse_0_aodma_bus:1;
    unsigned int    dvs_0_aodma_bus:4;
    unsigned int    drf_start_pause_audiodma:1;
    unsigned int    drf_test_resume_audiodma:1;
    unsigned int    drf_bist_mode_audiodma:1;
    unsigned int    drf_bist_done_audiodma:1;
    unsigned int    drf_bist_fail_audiodma:1;
    unsigned int    bist_mode_audiodma:1;
    unsigned int    bist_rstn_audiodma:1;
    unsigned int    bist_done_audiodma:1;
    unsigned int    bist_fail_audiodma:1;
}AUDIO_dma_bist_control_indicate;

typedef struct
{
    unsigned int    reserved_0:19;
    unsigned int    test_dma_en:1;
    unsigned int    reserved_1:3;
    unsigned int    test_dma_rw_mode:1;
    unsigned int    test_dma_in_sel:3;
    unsigned int    test_dma_ring:1;
    unsigned int    reserved_2:2;
    unsigned int    test_dma_over_read:1;
    unsigned int    test_dma_over_write:1;
}TEST_dma_control_register;

typedef struct
{
    unsigned int    reserved_0:7;
    unsigned int    test_dma_start_addr:20;
    unsigned int    reserved_1:5;
}TEST_dma_start_address;

typedef struct
{
    unsigned int    reserved_0:7;
    unsigned int    test_dma_stop_addr:20;
    unsigned int    reserved_1:5;
}TEST_dma_stop_address;

typedef struct
{
    unsigned int    dummy18006698_31_1:31;
    unsigned int    dma_sel:1;
}TEST_mode_select;

typedef struct
{
    unsigned int    reserved_0:7;
    unsigned int    test_dma_cur_addr:20;
    unsigned int    reserved_1:5;
}TEST_cur_address;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    basic_premium_sel:1;
    unsigned int    dvol_enable:1;
    unsigned int    loud_enable:1;
    unsigned int    deq_enable:1;
    unsigned int    spatial_ctrlenable:1;
    unsigned int    auto_volenable:1;
    unsigned int    reserved_1:1;
    unsigned int    zcth:5;
    unsigned int    reserved_2:2;
    unsigned int    dvcm:2;
}HW_process_control;

typedef struct
{
    unsigned int    dvol_apply:1;
    unsigned int    zcto:3;
    unsigned int    ramp_step:2;
    unsigned int    delay_ctrl:10;
    unsigned int    mute_apply:1;
    unsigned int    zcto_mute:3;
    unsigned int    ramp_step_mute:2;
    unsigned int    delay_ctrl_mute:10;
}DIGITAL_volume_control_0;

typedef struct
{
    unsigned int    mute_l:1;
    unsigned int    rep_l_status:1;
    unsigned int    reserved_0:1;
    unsigned int    hpf_l_enable:1;
    unsigned int    vol_l_ready:1;
    unsigned int    vol_l_a:5;
    unsigned int    vol_l_b:6;
    unsigned int    mute_r:1;
    unsigned int    rep_r_status:1;
    unsigned int    reserved_1:1;
    unsigned int    hpf_r_enable:1;
    unsigned int    vol_r_ready:1;
    unsigned int    vol_r_a:5;
    unsigned int    vol_r_b:6;
}LR_digital_volume_control;

typedef struct
{
    unsigned int    mute_ls:1;
    unsigned int    rep_ls_status:1;
    unsigned int    reserved_0:1;
    unsigned int    hpf_ls_enable:1;
    unsigned int    vol_ls_ready:1;
    unsigned int    vol_ls_a:5;
    unsigned int    vol_ls_b:6;
    unsigned int    mute_rs:1;
    unsigned int    rep_rs_status:1;
    unsigned int    reserved_1:1;
    unsigned int    hpf_rs_enable:1;
    unsigned int    vol_rs_ready:1;
    unsigned int    vol_rs_a:5;
    unsigned int    vol_rs_b:6;
}LSRS_digital_volume_control;

typedef struct
{
    unsigned int    mute_c:1;
    unsigned int    rep_c_status:1;
    unsigned int    reserved_0:1;
    unsigned int    hpf_c_enable:1;
    unsigned int    vol_c_ready:1;
    unsigned int    vol_c_a:5;
    unsigned int    vol_c_b:6;
    unsigned int    mute_sw:1;
    unsigned int    rep_sw_status:1;
    unsigned int    sw_src_sel:1;
    unsigned int    hpf_sw_enable:1;
    unsigned int    vol_sw_ready:1;
    unsigned int    vol_sw_a:5;
    unsigned int    vol_sw_b:6;
}CSW_digital_volume_control;

typedef struct
{
    unsigned int    reserved_0:30;
    unsigned int    zcto_status:1;
    unsigned int    double_buffer_ack:1;
}DOUBLE_buffer_ack;

typedef struct
{
    unsigned int    dummy18006718_31_0:32;
}DUMMY_6718;

typedef struct
{
    unsigned int    dummy1800671c_31_0:32;
}DUMMY_671c;

typedef struct
{
    unsigned int    freq_beeper:8;
    unsigned int    reserved_0:4;
    unsigned int    beeper_volume:4;
    unsigned int    mute_beeper:1;
    unsigned int    mode_beeper:1;
    unsigned int    reserved_1:6;
    unsigned int    duration_beeper:8;
}PROGRAMMABLE_beeper_control;

typedef struct
{
    unsigned int    reserved_0:17;
    unsigned int    apf_en:1;
    unsigned int    psb_en:1;
    unsigned int    seb_en:1;
    unsigned int    spatial_in_l_sel:1;
    unsigned int    spatial_in_r_sel:1;
    unsigned int    reserved_1:1;
    unsigned int    f_coef:9;
}SPATIAL_effect_control_0;

typedef struct
{
    unsigned int    reserved_0:7;
    unsigned int    depth1:9;
    unsigned int    reserved_1:7;
    unsigned int    depth2:9;
}SPATIAL_effect_control_1;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    avc_noise_gain:2;
    unsigned int    avc_noise_thre:8;
    unsigned int    avc_level_max:8;
    unsigned int    avc_level_min:8;
    unsigned int    avc_down_db:2;
    unsigned int    avc_up_db:2;
}AUTO_volume_control_0;

typedef struct
{
    unsigned int    avc_cnt_thre:8;
    unsigned int    avc_zc_win:12;
    unsigned int    avc_mon_win:12;
}AVC_volume_control_1;

typedef struct
{
    unsigned int    eq_lp_a1:16;
    unsigned int    eq_bp1_a1:16;
}EQ_a1_0;

typedef struct
{
    unsigned int    eq_bp2_a1:16;
    unsigned int    eq_bp3_a1:16;
}EQ_a1_1;

typedef struct
{
    unsigned int    eq_bp4_a1:16;
    unsigned int    eq_bp5_a1:16;
}EQ_a1_2;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    eq_hp_a1:16;
}EQ_a1_3;

typedef struct
{
    unsigned int    eq_bp1_a2:16;
    unsigned int    eq_bp2_a2:16;
}EQ_a2_1;

typedef struct
{
    unsigned int    eq_bp3_a2:16;
    unsigned int    eq_bp4_a2:16;
}EQ_a2_2;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    eq_bp5_a2:16;
}EQ_a2_3;

typedef struct
{
    unsigned int    reserved_0:31;
    unsigned int    eq_hp_slope:1;
}EQ_h0_0;

typedef struct
{
    unsigned int    eq_lp_h0:16;
    unsigned int    eq_bp1_h0:16;
}EQ_h0_1;

typedef struct
{
    unsigned int    eq_bp2_h0:16;
    unsigned int    eq_bp3_h0:16;
}EQ_h0_2;

typedef struct
{
    unsigned int    eq_bp4_h0:16;
    unsigned int    eq_bp5_h0:16;
}EQ_h0_3;

typedef struct
{
    unsigned int    reserved_0:12;
    unsigned int    eq_band4_2_of:1;
    unsigned int    eq_band4_1_of:1;
    unsigned int    eq_band4_2_enable:1;
    unsigned int    eq_band4_1_enable:1;
    unsigned int    reserved_1:1;
    unsigned int    eq_band5_enable:1;
    unsigned int    eq_band4_enable:1;
    unsigned int    eq_band3_enable:1;
    unsigned int    eq_band2_enable:1;
    unsigned int    eq_band1_enable:1;
    unsigned int    eq_lp_enable:1;
    unsigned int    eq_hp_enable:1;
    unsigned int    reserved_2:1;
    unsigned int    eq_band5_of:1;
    unsigned int    eq_band4_of:1;
    unsigned int    eq_band3_of:1;
    unsigned int    eq_band2_of:1;
    unsigned int    eq_band1_of:1;
    unsigned int    eq_lp_of:1;
    unsigned int    eq_hp_of:1;
}EQ_control_status_register;

typedef struct
{
    unsigned int    lr_loud_lp0_a1:16;
    unsigned int    lr_loud_bp1_a1:16;
}LR_loud_a1_0;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    lr_loud_bp2_a1:16;
}LR_loud_a1_1;

typedef struct
{
    unsigned int    lr_loud_bp1_a2:16;
    unsigned int    lr_loud_bp2_a2:16;
}LR_loud_a2;

typedef struct
{
    unsigned int    lr_loud_lp0_h0:16;
    unsigned int    lr_loud_bp1_h0:16;
}LR_loud_h0_0;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    lr_loud_bp2_h0:16;
}LR_loud_h0_1;

typedef struct
{
    unsigned int    lsrs_loud_lp0_a1:16;
    unsigned int    lsrs_loud_bp1_a1:16;
}LSRS_loud_a1_0;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    lsrs_loud_bp2_a1:16;
}LSRS_loud_a1_1;

typedef struct
{
    unsigned int    lsrs_loud_bp1_a2:16;
    unsigned int    lsrs_loud_bp2_a2:16;
}LSRS_loud_a2;

typedef struct
{
    unsigned int    lsrs_loud_lp0_h0:16;
    unsigned int    lsrs_loud_bp1_h0:16;
}LSRS_loud_h0_0;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    lsrs_loud_bp2_h0:16;
}LSRS_loud_h0_1;

typedef struct
{
    unsigned int    csw_loud_lp0_a1:16;
    unsigned int    csw_loud_bp1_a1:16;
}CSW_loud_a1_0;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    csw_loud_bp2_a1:16;
}CSW_loud_a1_1;

typedef struct
{
    unsigned int    csw_loud_bp1_a2:16;
    unsigned int    csw_loud_bp2_a2:16;
}CSW_loud_a2;

typedef struct
{
    unsigned int    csw_loud_lp0_h0:16;
    unsigned int    csw_loud_bp1_h0:16;
}CSW_loud_h0_0;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    csw_loud_bp2_h0:16;
}CSW_loud_h0_1;

typedef struct
{
    unsigned int    reserved_0:23;
    unsigned int    ld_bpf1_en_lr:1;
    unsigned int    ld_lpf_en_lr:1;
    unsigned int    ld_bpf2_en_lr:1;
    unsigned int    ld_bpf1_en_lsrs:1;
    unsigned int    ld_lpf_en_lsrs:1;
    unsigned int    ld_bpf2_en_lsrs:1;
    unsigned int    ld_bpf1_en_csw:1;
    unsigned int    ld_lpf_en_csw:1;
    unsigned int    ld_bpf2_en_csw:1;
}LOUDNESS_control_register;

typedef struct
{
    unsigned int    reserved_0:23;
    unsigned int    ld_lpf_of_lr:1;
    unsigned int    ld_bpf1_of_lr:1;
    unsigned int    ld_bpf2_of_lr:1;
    unsigned int    ld_lpf_of_lsrs:1;
    unsigned int    ld_bpf1_of_lsrs:1;
    unsigned int    ld_bpf2_of_lsrs:1;
    unsigned int    ld_lpf_of_csw:1;
    unsigned int    ld_bpf1_of_csw:1;
    unsigned int    ld_bpf2_of_csw:1;
}LOUDNESS_status_register;

typedef struct
{
    unsigned int    reserved_0:14;
    unsigned int    eq_ovf_en:1;
    unsigned int    loudness_ovf_en:1;
    unsigned int    dvol_int_en:1;
    unsigned int    reserved_1:12;
    unsigned int    dvol_done:1;
    unsigned int    eq_ovf:1;
    unsigned int    loudness_ovf:1;
}SYSTEM_int_en;

typedef struct
{
    unsigned int    reserved_0:18;
    unsigned int    hw_l_inverter_en:1;
    unsigned int    hw_r_inverter_en:1;
    unsigned int    hw_out_limiter_en:1;
    unsigned int    hw_out_limiter:7;
    unsigned int    reserved_1:4;
}HW_backplay_transfer;

typedef struct
{
    unsigned int    dac_pcm:1;
    unsigned int    spdif_pcm:1;
    unsigned int    i2s_pcm:1;
    unsigned int    reserved_0:1;
    unsigned int    i2s_out_3_sel:2;
    unsigned int    i2s_out_2_sel:2;
    unsigned int    i2s_out_1_sel:2;
    unsigned int    i2s_out_0_sel:2;
    unsigned int    spdif_out_sel:2;
    unsigned int    dac_out_sel:2;
    unsigned int    reserved_1:10;
    unsigned int    hw_mixing_sel:2;
    unsigned int    w_ch_12_factor:2;
    unsigned int    w_ch_mix_factor:2;
}HW_out_trans2;

typedef struct
{
    unsigned int    toogle_cnt:8;
    unsigned int    pre_hw_pcm_l:24;
}PRE_hw_pcm_l_control;

typedef struct
{
    unsigned int    pre_hw_pcm_sel:2;
    unsigned int    reserved_0:6;
    unsigned int    pre_hw_pcm_r:24;
}PRE_hw_pcm_r_control;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    post_hw_pcm_l:24;
}POST_hw_pcm_l_control;

typedef struct
{
    unsigned int    post_hw_pcm_sel:2;
    unsigned int    reserved_0:6;
    unsigned int    post_hw_pcm_r:24;
}POST_hw_pcm_r_control;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    avc_lp_out:24;
}AVC_lp_out_control;

typedef struct
{
    unsigned int    eq_bp4_2_a1:16;
    unsigned int    eq_bp4_1_a1:16;
}EQ_a1_4;

typedef struct
{
    unsigned int    eq_bp4_2_a2:16;
    unsigned int    eq_bp4_1_a2:16;
}EQ_a2_4;

typedef struct
{
    unsigned int    eq_bp4_2_h0:16;
    unsigned int    eq_bp4_1_h0:16;
}EQ_h0_4;

typedef struct
{
    unsigned int    lrrr_dvol_apply:1;
    unsigned int    lrrr_zcto:3;
    unsigned int    lrrr_ramp_step:2;
    unsigned int    lrrr_delay_ctrl:10;
    unsigned int    lrrr_mute_apply:1;
    unsigned int    lrrr_zcto_mute:3;
    unsigned int    lrrr_ramp_step_mute:2;
    unsigned int    lrrr_delay_ctrl_mute:10;
}LRRR_digital_volume_control_0;

typedef struct
{
    unsigned int    reserved_0:21;
    unsigned int    lrrr_dvol_enable:1;
    unsigned int    lrrr_zcto_status:1;
    unsigned int    lrrr_zcth:5;
    unsigned int    reserved_1:2;
    unsigned int    lrrr_dvcm:2;
}LRRR_digital_volume_control_1;

typedef struct
{
    unsigned int    mute_lr:1;
    unsigned int    reserved_0:2;
    unsigned int    hpf_lr_enable:1;
    unsigned int    vol_lr_ready:1;
    unsigned int    vol_lr_a:5;
    unsigned int    vol_lr_b:6;
    unsigned int    mute_rr:1;
    unsigned int    reserved_1:2;
    unsigned int    hpf_rr_enable:1;
    unsigned int    vol_rr_ready:1;
    unsigned int    vol_rr_a:5;
    unsigned int    vol_rr_b:6;
}LRRR_digital_volume_control_2;

typedef struct
{
    unsigned int    dummy18006810_31_0:32;
}TS_ds_mbist_recoding;

typedef struct
{
    unsigned int    ts_dac_pcm:1;
    unsigned int    ts_spdif_pcm:1;
    unsigned int    ts_i2s_pcm:1;
    unsigned int    reserved_0:15;
    unsigned int    scart_l_inverter_en:1;
    unsigned int    scart_r_inverter_en:1;
    unsigned int    scart_out_limiter_en:1;
    unsigned int    scart_out_limiter:7;
    unsigned int    reserved_1:3;
    unsigned int    vol_source_sel:1;
}DVOL_control;

typedef struct
{
    unsigned int    reserved_0:12;
    unsigned int    fifo_ch1_source:2;
    unsigned int    fifo_ch2_source:2;
    unsigned int    fifo_ch12_sel:4;
    unsigned int    fifo_ch12_scale:4;
    unsigned int    reserved_1:5;
    unsigned int    backend_play_en:1;
    unsigned int    downsample_en:1;
    unsigned int    down_rate:1;
}DOWN_sample_control_for_ts;

typedef struct
{
    unsigned int    dummy1800681c_31_14:18;
    unsigned int    dvse_0_ts_ds:1;
    unsigned int    dvs_0_ts_ds:4;
    unsigned int    drf_ts_ds_start_pause:1;
    unsigned int    drf_ts_ds_test_resume:1;
    unsigned int    drf_ts_ds_bist_mode:1;
    unsigned int    drf_ts_ds_bist_done:1;
    unsigned int    drf_ts_ds_bist_fail:1;
    unsigned int    ts_ds_bist_rstn:1;
    unsigned int    ts_ds_bist_mode:1;
    unsigned int    ts_ds_bist_done:1;
    unsigned int    ts_ds_bist_fail:1;
}TS_ds_fifo_mbist;

typedef struct
{
    unsigned int    reserved_0:18;
    unsigned int    sif_adc_in_test_en:1;
    unsigned int    sif_adc_in_test_sel:1;
    unsigned int    reserved_1:4;
    unsigned int    debug_mode_sel:8;
}TEST_pattern_gen;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    audio_crc_header:24;
}CRC_header;

typedef struct
{
    unsigned int    reserved_0:12;
    unsigned int    audio_crc_en:1;
    unsigned int    audio_crc_ch_sel:3;
    unsigned int    audio_crc_frame_length:16;
}CRC_contorl;

typedef struct
{
    unsigned int    reserved_0:7;
    unsigned int    audio_crc_done:1;
    unsigned int    audio_crc:24;
}CRC_status;

typedef struct
{
    unsigned int    sine_auto_chk_en:1;
    unsigned int    sine_channel_select:3;
    unsigned int    reserved_0:3;
    unsigned int    auto_chk_result:1;
    unsigned int    half_sine_num:2;
    unsigned int    amplitude_low_threshold:2;
    unsigned int    reserved_1:2;
    unsigned int    zc_sample_cnt_threshold:6;
    unsigned int    zc_sample_cnt_golden:12;
}SINE_auto_chk;

typedef struct
{
    unsigned int    reserved_0:12;
    unsigned int    sine_amplitude:8;
    unsigned int    zc_sample_cnt:12;
}SINE_wave_value;

typedef struct
{
    unsigned int    dummy1800686c_31_0:32;
}PATTERN_gen_dummy;

typedef struct
{
    unsigned int    reserved_0:28;
    unsigned int    dummy18006890_3_1:3;
    unsigned int    to_ack_en:1;
}RBUS_ack_ctrl;

typedef struct
{
    unsigned int    reserved_0:19;
    unsigned int    ack_fail_rw:1;
    unsigned int    ack_fail_addr:12;
}ACK_fail_info;

typedef struct
{
    unsigned int    dac_afifo_enable:1;
    unsigned int    dac2_afifo_enable:1;
    unsigned int    reserved_0:2;
    unsigned int    dac_afifo_full:1;
    unsigned int    dac2_afifo_full:1;
    unsigned int    dac_afifo_empty:1;
    unsigned int    dac2_afifo_empty:1;
    unsigned int    dac_afifo_in_drop_sel:2;
    unsigned int    dac2_afifo_in_drop_sel:2;
    unsigned int    reserved_1:16;
    unsigned int    sel_adda_lp:1;
    unsigned int    sel_adc_2ch_lp_source:1;
    unsigned int    sel_1ch_2ch:1;
    unsigned int    sel_daad_lp:1;
}ADDA_loopback;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    reg_bb_en_io_in:1;
    unsigned int    reg_bb_sw_in:1;
    unsigned int    reserved_1:2;
    unsigned int    reg_bb_ain_df2se:1;
    unsigned int    reg_bb_aio1_io:1;
    unsigned int    reg_bb_aio2_io:1;
    unsigned int    reserved_2:2;
    unsigned int    reg_bb_aio1_mux3:1;
    unsigned int    reg_bb_aio1_mux2:1;
    unsigned int    reg_bb_aio1_mux1:1;
    unsigned int    reserved_3:1;
    unsigned int    reg_bb_aio2_mux3:1;
    unsigned int    reg_bb_aio2_mux2:1;
    unsigned int    reg_bb_aio2_mux1:1;
    unsigned int    reg_bb_aout_copy:2;
    unsigned int    reg_bb_dachp_copy:2;
    unsigned int    reg_bb_aio1_copy:2;
    unsigned int    reg_bb_aio2_copy:2;
}ANALOG_in_out_sel;

typedef struct
{
    unsigned int    reserved_0:14;
    unsigned int    reg_bb_m_adc_l:1;
    unsigned int    reg_bb_m_adc_r:1;
    unsigned int    reserved_1:1;
    unsigned int    reg_bb_m_afe_l:7;
    unsigned int    reserved_2:1;
    unsigned int    reg_bb_m_afe_r:7;
}ANALOG_frontend_mute;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    reg_bb_m_mixer1_l:3;
    unsigned int    reserved_1:1;
    unsigned int    reg_bb_m_mixer1_r:3;
    unsigned int    reserved_2:1;
    unsigned int    reg_bb_m_mixer2_l:3;
    unsigned int    reserved_3:1;
    unsigned int    reg_bb_m_mixer2_r:3;
    unsigned int    reserved_4:1;
}ANALOG_mixer_mute;

typedef struct
{
    unsigned int    reserved_0:11;
    unsigned int    reg_bb_en_amp:1;
    unsigned int    reg_bb_m_aio1_l:1;
    unsigned int    reg_bb_m_aio1_r:1;
    unsigned int    reg_bb_m_aio2_l:1;
    unsigned int    reg_bb_m_aio2_r:1;
    unsigned int    reg_bb_m_aout_l:1;
    unsigned int    reg_bb_m_aout_r:1;
    unsigned int    reg_bb_m_dachp_l:1;
    unsigned int    reg_bb_m_dachp_r:1;
    unsigned int    reg_bb_m_master_l:6;
    unsigned int    reg_bb_m_master_r:6;
}ANALOG_aio_master_hpout_lineout;

typedef struct
{
    unsigned int    smute_left_avol_1_en:1;
    unsigned int    reserved_0:1;
    unsigned int    avol_1_in_left_gain:6;
    unsigned int    smute_right_avol_1_en:1;
    unsigned int    reserved_1:1;
    unsigned int    avol_1_in_right_gain:6;
    unsigned int    soft_volume_ctrl_avol:4;
    unsigned int    reserved_2:12;
}ADC_volume_gain_control;

typedef struct
{
    unsigned int    reserved_0:9;
    unsigned int    reg_bb_dacvref_mode:1;
    unsigned int    reg_bb_pow_afe:1;
    unsigned int    reg_bb_pow_mixer:1;
    unsigned int    reg_bb_pow_master:1;
    unsigned int    reg_bb_pow_adc1:1;
    unsigned int    reg_bb_pow_dac0:1;
    unsigned int    reg_bb_pow_dac1:1;
    unsigned int    reg_bb_pow_mbias:1;
    unsigned int    reg_bb_pow_vref:1;
    unsigned int    reg_bb_pow_dacvref:1;
    unsigned int    reserved_1:1;
    unsigned int    reg_bb_pow_aio1:1;
    unsigned int    reg_bb_pow_aio2:1;
    unsigned int    reg_bb_pow_aout:1;
    unsigned int    reg_bb_pow_dachp:1;
    unsigned int    reserved_2:2;
    unsigned int    reg_bb_pow_ain1:1;
    unsigned int    reg_bb_pow_ain2:1;
    unsigned int    reg_bb_pow_ain3:1;
    unsigned int    reg_bb_pow_ain4:1;
    unsigned int    reg_bb_pow_ain5:1;
    unsigned int    reserved_3:1;
}ANALOG_power;

typedef struct
{
    unsigned int    reserved_0:19;
    unsigned int    reg_adc2x_sifpgapow:1;
    unsigned int    reg_adc2x_sibsifpga:4;
    unsigned int    reserved_1:2;
    unsigned int    afe_pga_vol:6;
}ANALOG_pga;

typedef struct
{
    unsigned int    reserved_0:12;
    unsigned int    reg_bb_adc_ckxen:1;
    unsigned int    reg_bb_adc_set:1;
    unsigned int    reg_bb_vref:2;
    unsigned int    reserved_1:2;
    unsigned int    reg_bb_cio1:14;
}ANALOG_ci01;

typedef struct
{
    unsigned int    reserved_0:18;
    unsigned int    reg_bb_cio2:14;
}ANALOG_ci02;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    reg_bb_cio3:16;
}ANALOG_ci03;

typedef struct
{
    unsigned int    hard_mute_sel:1;
    unsigned int    reserved_0:1;
    unsigned int    time_out_sel:2;
    unsigned int    reserved_1:7;
    unsigned int    reg_bb_pow_zcd:1;
    unsigned int    reg_bb_pow_zcdcomp:8;
    unsigned int    reserved_2:2;
    unsigned int    reg_bb_zcd_curr:2;
    unsigned int    zc_reg_bb_m_aio1_l:1;
    unsigned int    zc_reg_bb_m_aio1_r:1;
    unsigned int    zc_reg_bb_m_aio2_l:1;
    unsigned int    zc_reg_bb_m_aio2_r:1;
    unsigned int    zc_mute_left_lineout:1;
    unsigned int    zc_mute_right_lineout:1;
    unsigned int    zc_mute_left_amp:1;
    unsigned int    zc_mute_right_amp:1;
}ANALOG_hard_mute;

typedef struct
{
    unsigned int    dummy18006930_31_16:16;
    unsigned int    hp_zc_sel:2;
    unsigned int    lineout_zc_sel:2;
    unsigned int    aio1_zc_sel:2;
    unsigned int    aio2_zc_sel:2;
    unsigned int    reserved_0:7;
    unsigned int    dac_water_nomask:1;
}ANALOG_zero_crossing;

typedef struct
{
    unsigned int    reserved_0:28;
    unsigned int    bb_ck_depop_en:1;
    unsigned int    sel_bb_ck_depop:3;
}ANALOG_depop1;

typedef struct
{
    unsigned int    reg_bb_pow_depop:1;
    unsigned int    reg_bb_pow_depop_core:1;
    unsigned int    reg_bb_pow_depop_op:1;
    unsigned int    reserved_0:1;
    unsigned int    reg_bb_cio4:8;
    unsigned int    reserved_1:1;
    unsigned int    reg_bb_depop_cur_sel:3;
    unsigned int    reserved_2:1;
    unsigned int    reg_bb_en_io_out:1;
    unsigned int    reg_bb_depop_cap_sel:2;
    unsigned int    reserved_3:1;
    unsigned int    reg_bb_aout_norm:1;
    unsigned int    reg_bb_aio_norm:1;
    unsigned int    reg_bb_depop_sc_sel:1;
    unsigned int    reg_bb_en_depop_ckgen:1;
    unsigned int    reg_bb_depop_sel:2;
    unsigned int    reg_bb_en_depop_soft_ctrl:1;
    unsigned int    reg_bb_vcm_ready_soft:1;
    unsigned int    reg_bb_hpout_norm:1;
    unsigned int    reserved_4:2;
}ANALOG_depop2;

typedef struct
{
    unsigned int    reg_bb_reserved:32;
}ANALOG_depop_dummy;

typedef struct
{
    unsigned int    dummy_6940:32;
}ANALOG_dummy;

typedef struct
{
    unsigned int    dummy_6944:32;
}ANALOG_dummy2;

typedef struct
{
    unsigned int    bist_mode_adc:1;
    unsigned int    bist_rstn_adc:1;
    unsigned int    bist_done_adc:1;
    unsigned int    bist_fail_adc:1;
    unsigned int    bist_mode_dac1:1;
    unsigned int    bist_rstn_dac1:1;
    unsigned int    bist_done_dac1:1;
    unsigned int    bist_fail_dac1:1;
    unsigned int    bist_mode_dac0:1;
    unsigned int    bist_rstn_dac0:1;
    unsigned int    bist_done_dac0:1;
    unsigned int    bist_fail_dac0:1;
    unsigned int    dvse_0_adda:1;
    unsigned int    dvs_0_adda:4;
    unsigned int    drf_start_pause_adc:1;
    unsigned int    drf_test_resume_adc:1;
    unsigned int    drf_bist_mode_adc:1;
    unsigned int    drf_bist_done_adc:1;
    unsigned int    drf_bist_fail_adc:1;
    unsigned int    drf_start_pause_dac1:1;
    unsigned int    drf_test_resume_dac1:1;
    unsigned int    drf_bist_mode_dac1:1;
    unsigned int    drf_bist_done_dac1:1;
    unsigned int    drf_bist_fail_dac1:1;
    unsigned int    drf_start_pause_dac0:1;
    unsigned int    drf_test_resume_dac0:1;
    unsigned int    drf_bist_mode_dac0:1;
    unsigned int    drf_bist_done_dac0:1;
    unsigned int    drf_bist_fail_dac0:1;
}DRF_bist;
#endif


#define GLOBAL_CTRL_0                                                 0x18006000
#define GLOBAL_CTRL_0_reg_addr                                        "0xb8006000"
#define GLOBAL_CTRL_0_reg                                             0xb8006000
#define GLOBAL_CTRL_0_inst_addr                                       "0x0000"
#define GLOBAL_CTRL_0_inst                                            0x0000
#define GLOBAL_CTRL_0_inv_ad_128fs_shift                              (31)
#define GLOBAL_CTRL_0_ad_down_sel_shift                               (28)
#define GLOBAL_CTRL_0_div_pre_512fs_ts_shift                          (26)
#define GLOBAL_CTRL_0_sel_clk_spdif_out_shift                         (25)
#define GLOBAL_CTRL_0_sel_clk_i2s_out_shift                           (24)
#define GLOBAL_CTRL_0_div_dma_r_512fs_shift                           (22)
#define GLOBAL_CTRL_0_div_tsdma_r_512fs_shift                         (20)
#define GLOBAL_CTRL_0_inv_ad_128fs_mask                               (0x80000000)
#define GLOBAL_CTRL_0_ad_down_sel_mask                                (0x30000000)
#define GLOBAL_CTRL_0_div_pre_512fs_ts_mask                           (0x0C000000)
#define GLOBAL_CTRL_0_sel_clk_spdif_out_mask                          (0x02000000)
#define GLOBAL_CTRL_0_sel_clk_i2s_out_mask                            (0x01000000)
#define GLOBAL_CTRL_0_div_dma_r_512fs_mask                            (0x00C00000)
#define GLOBAL_CTRL_0_div_tsdma_r_512fs_mask                          (0x00300000)
#define GLOBAL_CTRL_0_inv_ad_128fs(data)                              (0x80000000&((data)<<31))
#define GLOBAL_CTRL_0_ad_down_sel(data)                               (0x30000000&((data)<<28))
#define GLOBAL_CTRL_0_div_pre_512fs_ts(data)                          (0x0C000000&((data)<<26))
#define GLOBAL_CTRL_0_sel_clk_spdif_out(data)                         (0x02000000&((data)<<25))
#define GLOBAL_CTRL_0_sel_clk_i2s_out(data)                           (0x01000000&((data)<<24))
#define GLOBAL_CTRL_0_div_dma_r_512fs(data)                           (0x00C00000&((data)<<22))
#define GLOBAL_CTRL_0_div_tsdma_r_512fs(data)                         (0x00300000&((data)<<20))
#define GLOBAL_CTRL_0_get_inv_ad_128fs(data)                          ((0x80000000&(data))>>31)
#define GLOBAL_CTRL_0_get_ad_down_sel(data)                           ((0x30000000&(data))>>28)
#define GLOBAL_CTRL_0_get_div_pre_512fs_ts(data)                      ((0x0C000000&(data))>>26)
#define GLOBAL_CTRL_0_get_sel_clk_spdif_out(data)                     ((0x02000000&(data))>>25)
#define GLOBAL_CTRL_0_get_sel_clk_i2s_out(data)                       ((0x01000000&(data))>>24)
#define GLOBAL_CTRL_0_get_div_dma_r_512fs(data)                       ((0x00C00000&(data))>>22)
#define GLOBAL_CTRL_0_get_div_tsdma_r_512fs(data)                     ((0x00300000&(data))>>20)


#define GLOBAL_CTRL_1                                                 0x18006004
#define GLOBAL_CTRL_1_reg_addr                                        "0xb8006004"
#define GLOBAL_CTRL_1_reg                                             0xb8006004
#define GLOBAL_CTRL_1_inst_addr                                       "0x0001"
#define GLOBAL_CTRL_1_inst                                            0x0001
#define GLOBAL_CTRL_1_adc_sram_on_shift                               (31)
#define GLOBAL_CTRL_1_dac_sram_on_shift                               (30)
#define GLOBAL_CTRL_1_am_sram_on_shift                                (29)
#define GLOBAL_CTRL_1_a2_eiaj_sram_on_shift                           (28)
#define GLOBAL_CTRL_1_inv_da_128fs_shift                              (27)
#define GLOBAL_CTRL_1_inv_da_128fs_ts_shift                           (26)
#define GLOBAL_CTRL_1_src_da_128fs_shift                              (25)
#define GLOBAL_CTRL_1_src_da_128fs_ts_shift                           (24)
#define GLOBAL_CTRL_1_hdv_mode_sel_shift                              (23)
#define GLOBAL_CTRL_1_sif_adc_clk_sel_shift                           (21)
#define GLOBAL_CTRL_1_sif_adc_clk_en_shift                            (20)
#define GLOBAL_CTRL_1_sel_i2s_spdif_shift                             (19)
#define GLOBAL_CTRL_1_sel_i2s_hdmi_shift                              (17)
#define GLOBAL_CTRL_1_spdif_nicam_shift                               (16)
#define GLOBAL_CTRL_1_adc_512fs_sel_ts_shift                          (14)
#define GLOBAL_CTRL_1_sel_ts_ck_source_shift                          (12)
#define GLOBAL_CTRL_1_back_end_ts_sample_rate_shift                   (10)
#define GLOBAL_CTRL_1_da_down_sel_ts_shift                            (8)
#define GLOBAL_CTRL_1_adc_512fs_sel_shift                             (6)
#define GLOBAL_CTRL_1_sel_play_ck_source_shift                        (4)
#define GLOBAL_CTRL_1_back_end_play_sample_rate_shift                 (2)
#define GLOBAL_CTRL_1_da_down_sel_shift                               (0)
#define GLOBAL_CTRL_1_adc_sram_on_mask                                (0x80000000)
#define GLOBAL_CTRL_1_dac_sram_on_mask                                (0x40000000)
#define GLOBAL_CTRL_1_am_sram_on_mask                                 (0x20000000)
#define GLOBAL_CTRL_1_a2_eiaj_sram_on_mask                            (0x10000000)
#define GLOBAL_CTRL_1_inv_da_128fs_mask                               (0x08000000)
#define GLOBAL_CTRL_1_inv_da_128fs_ts_mask                            (0x04000000)
#define GLOBAL_CTRL_1_src_da_128fs_mask                               (0x02000000)
#define GLOBAL_CTRL_1_src_da_128fs_ts_mask                            (0x01000000)
#define GLOBAL_CTRL_1_hdv_mode_sel_mask                               (0x00800000)
#define GLOBAL_CTRL_1_sif_adc_clk_sel_mask                            (0x00600000)
#define GLOBAL_CTRL_1_sif_adc_clk_en_mask                             (0x00100000)
#define GLOBAL_CTRL_1_sel_i2s_spdif_mask                              (0x00080000)
#define GLOBAL_CTRL_1_sel_i2s_hdmi_mask                               (0x00060000)
#define GLOBAL_CTRL_1_spdif_nicam_mask                                (0x00010000)
#define GLOBAL_CTRL_1_adc_512fs_sel_ts_mask                           (0x0000C000)
#define GLOBAL_CTRL_1_sel_ts_ck_source_mask                           (0x00003000)
#define GLOBAL_CTRL_1_back_end_ts_sample_rate_mask                    (0x00000C00)
#define GLOBAL_CTRL_1_da_down_sel_ts_mask                             (0x00000300)
#define GLOBAL_CTRL_1_adc_512fs_sel_mask                              (0x000000C0)
#define GLOBAL_CTRL_1_sel_play_ck_source_mask                         (0x00000030)
#define GLOBAL_CTRL_1_back_end_play_sample_rate_mask                  (0x0000000C)
#define GLOBAL_CTRL_1_da_down_sel_mask                                (0x00000003)
#define GLOBAL_CTRL_1_adc_sram_on(data)                               (0x80000000&((data)<<31))
#define GLOBAL_CTRL_1_dac_sram_on(data)                               (0x40000000&((data)<<30))
#define GLOBAL_CTRL_1_am_sram_on(data)                                (0x20000000&((data)<<29))
#define GLOBAL_CTRL_1_a2_eiaj_sram_on(data)                           (0x10000000&((data)<<28))
#define GLOBAL_CTRL_1_inv_da_128fs(data)                              (0x08000000&((data)<<27))
#define GLOBAL_CTRL_1_inv_da_128fs_ts(data)                           (0x04000000&((data)<<26))
#define GLOBAL_CTRL_1_src_da_128fs(data)                              (0x02000000&((data)<<25))
#define GLOBAL_CTRL_1_src_da_128fs_ts(data)                           (0x01000000&((data)<<24))
#define GLOBAL_CTRL_1_hdv_mode_sel(data)                              (0x00800000&((data)<<23))
#define GLOBAL_CTRL_1_sif_adc_clk_sel(data)                           (0x00600000&((data)<<21))
#define GLOBAL_CTRL_1_sif_adc_clk_en(data)                            (0x00100000&((data)<<20))
#define GLOBAL_CTRL_1_sel_i2s_spdif(data)                             (0x00080000&((data)<<19))
#define GLOBAL_CTRL_1_sel_i2s_hdmi(data)                              (0x00060000&((data)<<17))
#define GLOBAL_CTRL_1_spdif_nicam(data)                               (0x00010000&((data)<<16))
#define GLOBAL_CTRL_1_adc_512fs_sel_ts(data)                          (0x0000C000&((data)<<14))
#define GLOBAL_CTRL_1_sel_ts_ck_source(data)                          (0x00003000&((data)<<12))
#define GLOBAL_CTRL_1_back_end_ts_sample_rate(data)                   (0x00000C00&((data)<<10))
#define GLOBAL_CTRL_1_da_down_sel_ts(data)                            (0x00000300&((data)<<8))
#define GLOBAL_CTRL_1_adc_512fs_sel(data)                             (0x000000C0&((data)<<6))
#define GLOBAL_CTRL_1_sel_play_ck_source(data)                        (0x00000030&((data)<<4))
#define GLOBAL_CTRL_1_back_end_play_sample_rate(data)                 (0x0000000C&((data)<<2))
#define GLOBAL_CTRL_1_da_down_sel(data)                               (0x00000003&(data))
#define GLOBAL_CTRL_1_get_adc_sram_on(data)                           ((0x80000000&(data))>>31)
#define GLOBAL_CTRL_1_get_dac_sram_on(data)                           ((0x40000000&(data))>>30)
#define GLOBAL_CTRL_1_get_am_sram_on(data)                            ((0x20000000&(data))>>29)
#define GLOBAL_CTRL_1_get_a2_eiaj_sram_on(data)                       ((0x10000000&(data))>>28)
#define GLOBAL_CTRL_1_get_inv_da_128fs(data)                          ((0x08000000&(data))>>27)
#define GLOBAL_CTRL_1_get_inv_da_128fs_ts(data)                       ((0x04000000&(data))>>26)
#define GLOBAL_CTRL_1_get_src_da_128fs(data)                          ((0x02000000&(data))>>25)
#define GLOBAL_CTRL_1_get_src_da_128fs_ts(data)                       ((0x01000000&(data))>>24)
#define GLOBAL_CTRL_1_get_hdv_mode_sel(data)                          ((0x00800000&(data))>>23)
#define GLOBAL_CTRL_1_get_sif_adc_clk_sel(data)                       ((0x00600000&(data))>>21)
#define GLOBAL_CTRL_1_get_sif_adc_clk_en(data)                        ((0x00100000&(data))>>20)
#define GLOBAL_CTRL_1_get_sel_i2s_spdif(data)                         ((0x00080000&(data))>>19)
#define GLOBAL_CTRL_1_get_sel_i2s_hdmi(data)                          ((0x00060000&(data))>>17)
#define GLOBAL_CTRL_1_get_spdif_nicam(data)                           ((0x00010000&(data))>>16)
#define GLOBAL_CTRL_1_get_adc_512fs_sel_ts(data)                      ((0x0000C000&(data))>>14)
#define GLOBAL_CTRL_1_get_sel_ts_ck_source(data)                      ((0x00003000&(data))>>12)
#define GLOBAL_CTRL_1_get_back_end_ts_sample_rate(data)               ((0x00000C00&(data))>>10)
#define GLOBAL_CTRL_1_get_da_down_sel_ts(data)                        ((0x00000300&(data))>>8)
#define GLOBAL_CTRL_1_get_adc_512fs_sel(data)                         ((0x000000C0&(data))>>6)
#define GLOBAL_CTRL_1_get_sel_play_ck_source(data)                    ((0x00000030&(data))>>4)
#define GLOBAL_CTRL_1_get_back_end_play_sample_rate(data)             ((0x0000000C&(data))>>2)
#define GLOBAL_CTRL_1_get_da_down_sel(data)                           (0x00000003&(data))


#define PLLCG_SPDIF_GAIN_CR0                                          0x18006008
#define PLLCG_SPDIF_GAIN_CR0_reg_addr                                 "0xb8006008"
#define PLLCG_SPDIF_GAIN_CR0_reg                                      0xb8006008
#define PLLCG_SPDIF_GAIN_CR0_inst_addr                                "0x0002"
#define PLLCG_SPDIF_GAIN_CR0_inst                                     0x0002
#define PLLCG_SPDIF_GAIN_CR0_contword_inv_shift                       (31)
#define PLLCG_SPDIF_GAIN_CR0_div_2fs_shift                            (28)
#define PLLCG_SPDIF_GAIN_CR0_reg_para_e_shift                         (24)
#define PLLCG_SPDIF_GAIN_CR0_ps_testmode_shift                        (21)
#define PLLCG_SPDIF_GAIN_CR0_ps_contword_shift                        (16)
#define PLLCG_SPDIF_GAIN_CR0_pll_spdif_dtrack_en_shift                (15)
#define PLLCG_SPDIF_GAIN_CR0_reg_smooth_en_shift                      (14)
#define PLLCG_SPDIF_GAIN_CR0_pll_spdif_auto_mode_shift                (13)
#define PLLCG_SPDIF_GAIN_CR0_mod_acc_rst_shift                        (12)
#define PLLCG_SPDIF_GAIN_CR0_reg_para_d_shift                         (8)
#define PLLCG_SPDIF_GAIN_CR0_reg_para_a_shift                         (0)
#define PLLCG_SPDIF_GAIN_CR0_contword_inv_mask                        (0x80000000)
#define PLLCG_SPDIF_GAIN_CR0_div_2fs_mask                             (0x30000000)
#define PLLCG_SPDIF_GAIN_CR0_reg_para_e_mask                          (0x07000000)
#define PLLCG_SPDIF_GAIN_CR0_ps_testmode_mask                         (0x00200000)
#define PLLCG_SPDIF_GAIN_CR0_ps_contword_mask                         (0x001F0000)
#define PLLCG_SPDIF_GAIN_CR0_pll_spdif_dtrack_en_mask                 (0x00008000)
#define PLLCG_SPDIF_GAIN_CR0_reg_smooth_en_mask                       (0x00004000)
#define PLLCG_SPDIF_GAIN_CR0_pll_spdif_auto_mode_mask                 (0x00002000)
#define PLLCG_SPDIF_GAIN_CR0_mod_acc_rst_mask                         (0x00001000)
#define PLLCG_SPDIF_GAIN_CR0_reg_para_d_mask                          (0x00000F00)
#define PLLCG_SPDIF_GAIN_CR0_reg_para_a_mask                          (0x0000003F)
#define PLLCG_SPDIF_GAIN_CR0_contword_inv(data)                       (0x80000000&((data)<<31))
#define PLLCG_SPDIF_GAIN_CR0_div_2fs(data)                            (0x30000000&((data)<<28))
#define PLLCG_SPDIF_GAIN_CR0_reg_para_e(data)                         (0x07000000&((data)<<24))
#define PLLCG_SPDIF_GAIN_CR0_ps_testmode(data)                        (0x00200000&((data)<<21))
#define PLLCG_SPDIF_GAIN_CR0_ps_contword(data)                        (0x001F0000&((data)<<16))
#define PLLCG_SPDIF_GAIN_CR0_pll_spdif_dtrack_en(data)                (0x00008000&((data)<<15))
#define PLLCG_SPDIF_GAIN_CR0_reg_smooth_en(data)                      (0x00004000&((data)<<14))
#define PLLCG_SPDIF_GAIN_CR0_pll_spdif_auto_mode(data)                (0x00002000&((data)<<13))
#define PLLCG_SPDIF_GAIN_CR0_mod_acc_rst(data)                        (0x00001000&((data)<<12))
#define PLLCG_SPDIF_GAIN_CR0_reg_para_d(data)                         (0x00000F00&((data)<<8))
#define PLLCG_SPDIF_GAIN_CR0_reg_para_a(data)                         (0x0000003F&(data))
#define PLLCG_SPDIF_GAIN_CR0_get_contword_inv(data)                   ((0x80000000&(data))>>31)
#define PLLCG_SPDIF_GAIN_CR0_get_div_2fs(data)                        ((0x30000000&(data))>>28)
#define PLLCG_SPDIF_GAIN_CR0_get_reg_para_e(data)                     ((0x07000000&(data))>>24)
#define PLLCG_SPDIF_GAIN_CR0_get_ps_testmode(data)                    ((0x00200000&(data))>>21)
#define PLLCG_SPDIF_GAIN_CR0_get_ps_contword(data)                    ((0x001F0000&(data))>>16)
#define PLLCG_SPDIF_GAIN_CR0_get_pll_spdif_dtrack_en(data)            ((0x00008000&(data))>>15)
#define PLLCG_SPDIF_GAIN_CR0_get_reg_smooth_en(data)                  ((0x00004000&(data))>>14)
#define PLLCG_SPDIF_GAIN_CR0_get_pll_spdif_auto_mode(data)            ((0x00002000&(data))>>13)
#define PLLCG_SPDIF_GAIN_CR0_get_mod_acc_rst(data)                    ((0x00001000&(data))>>12)
#define PLLCG_SPDIF_GAIN_CR0_get_reg_para_d(data)                     ((0x00000F00&(data))>>8)
#define PLLCG_SPDIF_GAIN_CR0_get_reg_para_a(data)                     (0x0000003F&(data))


#define PLLCG_SPDIF_GAIN_CR1                                          0x1800600c
#define PLLCG_SPDIF_GAIN_CR1_reg_addr                                 "0xb800600c"
#define PLLCG_SPDIF_GAIN_CR1_reg                                      0xb800600c
#define PLLCG_SPDIF_GAIN_CR1_inst_addr                                "0x0003"
#define PLLCG_SPDIF_GAIN_CR1_inst                                     0x0003
#define PLLCG_SPDIF_GAIN_CR1_p_gain_set_shift                         (16)
#define PLLCG_SPDIF_GAIN_CR1_p_gain_set2_shift                        (0)
#define PLLCG_SPDIF_GAIN_CR1_p_gain_set_mask                          (0x03FF0000)
#define PLLCG_SPDIF_GAIN_CR1_p_gain_set2_mask                         (0x000003FF)
#define PLLCG_SPDIF_GAIN_CR1_p_gain_set(data)                         (0x03FF0000&((data)<<16))
#define PLLCG_SPDIF_GAIN_CR1_p_gain_set2(data)                        (0x000003FF&(data))
#define PLLCG_SPDIF_GAIN_CR1_get_p_gain_set(data)                     ((0x03FF0000&(data))>>16)
#define PLLCG_SPDIF_GAIN_CR1_get_p_gain_set2(data)                    (0x000003FF&(data))


#define PLLCG_SPDIF_GAIN_CR2                                          0x18006010
#define PLLCG_SPDIF_GAIN_CR2_reg_addr                                 "0xb8006010"
#define PLLCG_SPDIF_GAIN_CR2_reg                                      0xb8006010
#define PLLCG_SPDIF_GAIN_CR2_inst_addr                                "0x0004"
#define PLLCG_SPDIF_GAIN_CR2_inst                                     0x0004
#define PLLCG_SPDIF_GAIN_CR2_i_gain_set_shift                         (0)
#define PLLCG_SPDIF_GAIN_CR2_i_gain_set_mask                          (0x000003FF)
#define PLLCG_SPDIF_GAIN_CR2_i_gain_set(data)                         (0x000003FF&(data))
#define PLLCG_SPDIF_GAIN_CR2_get_i_gain_set(data)                     (0x000003FF&(data))


#define PLLCG_SPDIF_NUMBER                                            0x18006014
#define PLLCG_SPDIF_NUMBER_reg_addr                                   "0xb8006014"
#define PLLCG_SPDIF_NUMBER_reg                                        0xb8006014
#define PLLCG_SPDIF_NUMBER_inst_addr                                  "0x0005"
#define PLLCG_SPDIF_NUMBER_inst                                       0x0005
#define PLLCG_SPDIF_NUMBER_reach_time_num_shift                       (4)
#define PLLCG_SPDIF_NUMBER_max_correct_range_shift                    (0)
#define PLLCG_SPDIF_NUMBER_reach_time_num_mask                        (0x00000070)
#define PLLCG_SPDIF_NUMBER_max_correct_range_mask                     (0x0000000F)
#define PLLCG_SPDIF_NUMBER_reach_time_num(data)                       (0x00000070&((data)<<4))
#define PLLCG_SPDIF_NUMBER_max_correct_range(data)                    (0x0000000F&(data))
#define PLLCG_SPDIF_NUMBER_get_reach_time_num(data)                   ((0x00000070&(data))>>4)
#define PLLCG_SPDIF_NUMBER_get_max_correct_range(data)                (0x0000000F&(data))


#define PLLCG_SPDIF_BOUND                                             0x18006018
#define PLLCG_SPDIF_BOUND_reg_addr                                    "0xb8006018"
#define PLLCG_SPDIF_BOUND_reg                                         0xb8006018
#define PLLCG_SPDIF_BOUND_inst_addr                                   "0x0006"
#define PLLCG_SPDIF_BOUND_inst                                        0x0006
#define PLLCG_SPDIF_BOUND_high_bound1_shift                           (24)
#define PLLCG_SPDIF_BOUND_low_bound1_shift                            (16)
#define PLLCG_SPDIF_BOUND_high_bound2_shift                           (8)
#define PLLCG_SPDIF_BOUND_low_bound2_shift                            (0)
#define PLLCG_SPDIF_BOUND_high_bound1_mask                            (0xFF000000)
#define PLLCG_SPDIF_BOUND_low_bound1_mask                             (0x00FF0000)
#define PLLCG_SPDIF_BOUND_high_bound2_mask                            (0x0000FF00)
#define PLLCG_SPDIF_BOUND_low_bound2_mask                             (0x000000FF)
#define PLLCG_SPDIF_BOUND_high_bound1(data)                           (0xFF000000&((data)<<24))
#define PLLCG_SPDIF_BOUND_low_bound1(data)                            (0x00FF0000&((data)<<16))
#define PLLCG_SPDIF_BOUND_high_bound2(data)                           (0x0000FF00&((data)<<8))
#define PLLCG_SPDIF_BOUND_low_bound2(data)                            (0x000000FF&(data))
#define PLLCG_SPDIF_BOUND_get_high_bound1(data)                       ((0xFF000000&(data))>>24)
#define PLLCG_SPDIF_BOUND_get_low_bound1(data)                        ((0x00FF0000&(data))>>16)
#define PLLCG_SPDIF_BOUND_get_high_bound2(data)                       ((0x0000FF00&(data))>>8)
#define PLLCG_SPDIF_BOUND_get_low_bound2(data)                        (0x000000FF&(data))


#define GLOBAL_DUMMY                                                  0x1800601c
#define GLOBAL_DUMMY_reg_addr                                         "0xb800601c"
#define GLOBAL_DUMMY_reg                                              0xb800601c
#define GLOBAL_DUMMY_inst_addr                                        "0x0007"
#define GLOBAL_DUMMY_inst                                             0x0007
#define GLOBAL_DUMMY_dummy1800601c_31_16_shift                        (16)
#define GLOBAL_DUMMY_wdog_switch_en_shift                             (2)
#define GLOBAL_DUMMY_freq_sel_shift                                   (0)
#define GLOBAL_DUMMY_dummy1800601c_31_16_mask                         (0xFFFF0000)
#define GLOBAL_DUMMY_wdog_switch_en_mask                              (0x00000004)
#define GLOBAL_DUMMY_freq_sel_mask                                    (0x00000003)
#define GLOBAL_DUMMY_dummy1800601c_31_16(data)                        (0xFFFF0000&((data)<<16))
#define GLOBAL_DUMMY_wdog_switch_en(data)                             (0x00000004&((data)<<2))
#define GLOBAL_DUMMY_freq_sel(data)                                   (0x00000003&(data))
#define GLOBAL_DUMMY_get_dummy1800601c_31_16(data)                    ((0xFFFF0000&(data))>>16)
#define GLOBAL_DUMMY_get_wdog_switch_en(data)                         ((0x00000004&(data))>>2)
#define GLOBAL_DUMMY_get_freq_sel(data)                               (0x00000003&(data))


#define INTERRUPT_EN                                                  0x18006050
#define INTERRUPT_EN_reg_addr                                         "0xb8006050"
#define INTERRUPT_EN_reg                                              0xb8006050
#define INTERRUPT_EN_inst_addr                                        "0x0014"
#define INTERRUPT_EN_inst                                             0x0014
#define INTERRUPT_EN_int_fifo0_ts_full_en_shift                       (30)
#define INTERRUPT_EN_int_fifo0_ts_empty_en_shift                      (29)
#define INTERRUPT_EN_int_pll64512_wd_en_shift                         (28)
#define INTERRUPT_EN_int_msd_decision_done_en_shift                   (27)
#define INTERRUPT_EN_int_msd_fw_scan_done_en_shift                    (26)
#define INTERRUPT_EN_int_rbus_timeout_en_shift                        (25)
#define INTERRUPT_EN_int_btsc_mode_chg_en_shift                       (24)
#define INTERRUPT_EN_int_fifo3_full_en_shift                          (23)
#define INTERRUPT_EN_int_fifo2_full_en_shift                          (22)
#define INTERRUPT_EN_int_fifo1_full_en_shift                          (21)
#define INTERRUPT_EN_int_fifo0_full_en_shift                          (20)
#define INTERRUPT_EN_int_fifo3_empty_en_shift                         (19)
#define INTERRUPT_EN_int_fifo2_empty_en_shift                         (18)
#define INTERRUPT_EN_int_fifo1_empty_en_shift                         (17)
#define INTERRUPT_EN_int_fifo0_empty_en_shift                         (16)
#define INTERRUPT_EN_int_nicam_level_status_en_shift                  (15)
#define INTERRUPT_EN_int_ain_timer_en_shift                           (14)
#define INTERRUPT_EN_int_aout_timer_en_shift                          (13)
#define INTERRUPT_EN_int_spi_in_datatype_change_en_shift              (12)
#define INTERRUPT_EN_int_spi_in_lock_change_en_shift                  (11)
#define INTERRUPT_EN_int_nicam_hierr_change_en_shift                  (10)
#define INTERRUPT_EN_int_i2s_pri_sample_rate_chg_en_shift             (9)
#define INTERRUPT_EN_int_i2s_sec_sample_rate_chg_en_shift             (8)
#define INTERRUPT_EN_int_spi_sample_rate_chg_en_shift                 (7)
#define INTERRUPT_EN_int_i2s_pri_word_length_change_en_shift          (6)
#define INTERRUPT_EN_int_i2s_sec_word_length_change_en_shift          (5)
#define INTERRUPT_EN_int_sif_nopt_en_shift                            (4)
#define INTERRUPT_EN_int_msd_change_en_shift                          (3)
#define INTERRUPT_EN_int_msd_timeout_en_shift                         (2)
#define INTERRUPT_EN_int_mode_det_status_change_en_shift              (1)
#define INTERRUPT_EN_int_sif_ovf_en_shift                             (0)
#define INTERRUPT_EN_int_fifo0_ts_full_en_mask                        (0x40000000)
#define INTERRUPT_EN_int_fifo0_ts_empty_en_mask                       (0x20000000)
#define INTERRUPT_EN_int_pll64512_wd_en_mask                          (0x10000000)
#define INTERRUPT_EN_int_msd_decision_done_en_mask                    (0x08000000)
#define INTERRUPT_EN_int_msd_fw_scan_done_en_mask                     (0x04000000)
#define INTERRUPT_EN_int_rbus_timeout_en_mask                         (0x02000000)
#define INTERRUPT_EN_int_btsc_mode_chg_en_mask                        (0x01000000)
#define INTERRUPT_EN_int_fifo3_full_en_mask                           (0x00800000)
#define INTERRUPT_EN_int_fifo2_full_en_mask                           (0x00400000)
#define INTERRUPT_EN_int_fifo1_full_en_mask                           (0x00200000)
#define INTERRUPT_EN_int_fifo0_full_en_mask                           (0x00100000)
#define INTERRUPT_EN_int_fifo3_empty_en_mask                          (0x00080000)
#define INTERRUPT_EN_int_fifo2_empty_en_mask                          (0x00040000)
#define INTERRUPT_EN_int_fifo1_empty_en_mask                          (0x00020000)
#define INTERRUPT_EN_int_fifo0_empty_en_mask                          (0x00010000)
#define INTERRUPT_EN_int_nicam_level_status_en_mask                   (0x00008000)
#define INTERRUPT_EN_int_ain_timer_en_mask                            (0x00004000)
#define INTERRUPT_EN_int_aout_timer_en_mask                           (0x00002000)
#define INTERRUPT_EN_int_spi_in_datatype_change_en_mask               (0x00001000)
#define INTERRUPT_EN_int_spi_in_lock_change_en_mask                   (0x00000800)
#define INTERRUPT_EN_int_nicam_hierr_change_en_mask                   (0x00000400)
#define INTERRUPT_EN_int_i2s_pri_sample_rate_chg_en_mask              (0x00000200)
#define INTERRUPT_EN_int_i2s_sec_sample_rate_chg_en_mask              (0x00000100)
#define INTERRUPT_EN_int_spi_sample_rate_chg_en_mask                  (0x00000080)
#define INTERRUPT_EN_int_i2s_pri_word_length_change_en_mask           (0x00000040)
#define INTERRUPT_EN_int_i2s_sec_word_length_change_en_mask           (0x00000020)
#define INTERRUPT_EN_int_sif_nopt_en_mask                             (0x00000010)
#define INTERRUPT_EN_int_msd_change_en_mask                           (0x00000008)
#define INTERRUPT_EN_int_msd_timeout_en_mask                          (0x00000004)
#define INTERRUPT_EN_int_mode_det_status_change_en_mask               (0x00000002)
#define INTERRUPT_EN_int_sif_ovf_en_mask                              (0x00000001)
#define INTERRUPT_EN_int_fifo0_ts_full_en(data)                       (0x40000000&((data)<<30))
#define INTERRUPT_EN_int_fifo0_ts_empty_en(data)                      (0x20000000&((data)<<29))
#define INTERRUPT_EN_int_pll64512_wd_en(data)                         (0x10000000&((data)<<28))
#define INTERRUPT_EN_int_msd_decision_done_en(data)                   (0x08000000&((data)<<27))
#define INTERRUPT_EN_int_msd_fw_scan_done_en(data)                    (0x04000000&((data)<<26))
#define INTERRUPT_EN_int_rbus_timeout_en(data)                        (0x02000000&((data)<<25))
#define INTERRUPT_EN_int_btsc_mode_chg_en(data)                       (0x01000000&((data)<<24))
#define INTERRUPT_EN_int_fifo3_full_en(data)                          (0x00800000&((data)<<23))
#define INTERRUPT_EN_int_fifo2_full_en(data)                          (0x00400000&((data)<<22))
#define INTERRUPT_EN_int_fifo1_full_en(data)                          (0x00200000&((data)<<21))
#define INTERRUPT_EN_int_fifo0_full_en(data)                          (0x00100000&((data)<<20))
#define INTERRUPT_EN_int_fifo3_empty_en(data)                         (0x00080000&((data)<<19))
#define INTERRUPT_EN_int_fifo2_empty_en(data)                         (0x00040000&((data)<<18))
#define INTERRUPT_EN_int_fifo1_empty_en(data)                         (0x00020000&((data)<<17))
#define INTERRUPT_EN_int_fifo0_empty_en(data)                         (0x00010000&((data)<<16))
#define INTERRUPT_EN_int_nicam_level_status_en(data)                  (0x00008000&((data)<<15))
#define INTERRUPT_EN_int_ain_timer_en(data)                           (0x00004000&((data)<<14))
#define INTERRUPT_EN_int_aout_timer_en(data)                          (0x00002000&((data)<<13))
#define INTERRUPT_EN_int_spi_in_datatype_change_en(data)              (0x00001000&((data)<<12))
#define INTERRUPT_EN_int_spi_in_lock_change_en(data)                  (0x00000800&((data)<<11))
#define INTERRUPT_EN_int_nicam_hierr_change_en(data)                  (0x00000400&((data)<<10))
#define INTERRUPT_EN_int_i2s_pri_sample_rate_chg_en(data)             (0x00000200&((data)<<9))
#define INTERRUPT_EN_int_i2s_sec_sample_rate_chg_en(data)             (0x00000100&((data)<<8))
#define INTERRUPT_EN_int_spi_sample_rate_chg_en(data)                 (0x00000080&((data)<<7))
#define INTERRUPT_EN_int_i2s_pri_word_length_change_en(data)          (0x00000040&((data)<<6))
#define INTERRUPT_EN_int_i2s_sec_word_length_change_en(data)          (0x00000020&((data)<<5))
#define INTERRUPT_EN_int_sif_nopt_en(data)                            (0x00000010&((data)<<4))
#define INTERRUPT_EN_int_msd_change_en(data)                          (0x00000008&((data)<<3))
#define INTERRUPT_EN_int_msd_timeout_en(data)                         (0x00000004&((data)<<2))
#define INTERRUPT_EN_int_mode_det_status_change_en(data)              (0x00000002&((data)<<1))
#define INTERRUPT_EN_int_sif_ovf_en(data)                             (0x00000001&(data))
#define INTERRUPT_EN_get_int_fifo0_ts_full_en(data)                   ((0x40000000&(data))>>30)
#define INTERRUPT_EN_get_int_fifo0_ts_empty_en(data)                  ((0x20000000&(data))>>29)
#define INTERRUPT_EN_get_int_pll64512_wd_en(data)                     ((0x10000000&(data))>>28)
#define INTERRUPT_EN_get_int_msd_decision_done_en(data)               ((0x08000000&(data))>>27)
#define INTERRUPT_EN_get_int_msd_fw_scan_done_en(data)                ((0x04000000&(data))>>26)
#define INTERRUPT_EN_get_int_rbus_timeout_en(data)                    ((0x02000000&(data))>>25)
#define INTERRUPT_EN_get_int_btsc_mode_chg_en(data)                   ((0x01000000&(data))>>24)
#define INTERRUPT_EN_get_int_fifo3_full_en(data)                      ((0x00800000&(data))>>23)
#define INTERRUPT_EN_get_int_fifo2_full_en(data)                      ((0x00400000&(data))>>22)
#define INTERRUPT_EN_get_int_fifo1_full_en(data)                      ((0x00200000&(data))>>21)
#define INTERRUPT_EN_get_int_fifo0_full_en(data)                      ((0x00100000&(data))>>20)
#define INTERRUPT_EN_get_int_fifo3_empty_en(data)                     ((0x00080000&(data))>>19)
#define INTERRUPT_EN_get_int_fifo2_empty_en(data)                     ((0x00040000&(data))>>18)
#define INTERRUPT_EN_get_int_fifo1_empty_en(data)                     ((0x00020000&(data))>>17)
#define INTERRUPT_EN_get_int_fifo0_empty_en(data)                     ((0x00010000&(data))>>16)
#define INTERRUPT_EN_get_int_nicam_level_status_en(data)              ((0x00008000&(data))>>15)
#define INTERRUPT_EN_get_int_ain_timer_en(data)                       ((0x00004000&(data))>>14)
#define INTERRUPT_EN_get_int_aout_timer_en(data)                      ((0x00002000&(data))>>13)
#define INTERRUPT_EN_get_int_spi_in_datatype_change_en(data)          ((0x00001000&(data))>>12)
#define INTERRUPT_EN_get_int_spi_in_lock_change_en(data)              ((0x00000800&(data))>>11)
#define INTERRUPT_EN_get_int_nicam_hierr_change_en(data)              ((0x00000400&(data))>>10)
#define INTERRUPT_EN_get_int_i2s_pri_sample_rate_chg_en(data)         ((0x00000200&(data))>>9)
#define INTERRUPT_EN_get_int_i2s_sec_sample_rate_chg_en(data)         ((0x00000100&(data))>>8)
#define INTERRUPT_EN_get_int_spi_sample_rate_chg_en(data)             ((0x00000080&(data))>>7)
#define INTERRUPT_EN_get_int_i2s_pri_word_length_change_en(data)      ((0x00000040&(data))>>6)
#define INTERRUPT_EN_get_int_i2s_sec_word_length_change_en(data)      ((0x00000020&(data))>>5)
#define INTERRUPT_EN_get_int_sif_nopt_en(data)                        ((0x00000010&(data))>>4)
#define INTERRUPT_EN_get_int_msd_change_en(data)                      ((0x00000008&(data))>>3)
#define INTERRUPT_EN_get_int_msd_timeout_en(data)                     ((0x00000004&(data))>>2)
#define INTERRUPT_EN_get_int_mode_det_status_change_en(data)          ((0x00000002&(data))>>1)
#define INTERRUPT_EN_get_int_sif_ovf_en(data)                         (0x00000001&(data))


#define INTERRUPT_STATUS                                              0x18006054
#define INTERRUPT_STATUS_reg_addr                                     "0xb8006054"
#define INTERRUPT_STATUS_reg                                          0xb8006054
#define INTERRUPT_STATUS_inst_addr                                    "0x0015"
#define INTERRUPT_STATUS_inst                                         0x0015
#define INTERRUPT_STATUS_int_fifo0_ts_full_shift                      (30)
#define INTERRUPT_STATUS_int_fifo0_ts_empty_shift                     (29)
#define INTERRUPT_STATUS_int_pll64512_wd_shift                        (28)
#define INTERRUPT_STATUS_int_msd_decision_done_shift                  (27)
#define INTERRUPT_STATUS_int_msd_fw_scan_done_shift                   (26)
#define INTERRUPT_STATUS_int_rbus_timeout_shift                       (25)
#define INTERRUPT_STATUS_int_btsc_mode_chg_shift                      (24)
#define INTERRUPT_STATUS_int_fifo3_full_shift                         (23)
#define INTERRUPT_STATUS_int_fifo2_full_shift                         (22)
#define INTERRUPT_STATUS_int_fifo1_full_shift                         (21)
#define INTERRUPT_STATUS_int_fifo0_full_shift                         (20)
#define INTERRUPT_STATUS_int_fifo3_empty_shift                        (19)
#define INTERRUPT_STATUS_int_fifo2_empty_shift                        (18)
#define INTERRUPT_STATUS_int_fifo1_empty_shift                        (17)
#define INTERRUPT_STATUS_int_fifo0_empty_shift                        (16)
#define INTERRUPT_STATUS_int_nicam_level_status_shift                 (15)
#define INTERRUPT_STATUS_int_ain_timer_shift                          (14)
#define INTERRUPT_STATUS_int_aout_timer_shift                         (13)
#define INTERRUPT_STATUS_int_spi_in_datatype_change_shift             (12)
#define INTERRUPT_STATUS_int_spi_in_lock_change_shift                 (11)
#define INTERRUPT_STATUS_int_nicam_hierr_change_shift                 (10)
#define INTERRUPT_STATUS_int_i2s_pri_sample_rate_chg_shift            (9)
#define INTERRUPT_STATUS_int_i2s_sec_sample_rate_chg_shift            (8)
#define INTERRUPT_STATUS_int_spi_sample_rate_chg_shift                (7)
#define INTERRUPT_STATUS_int_i2s_pri_word_length_change_shift         (6)
#define INTERRUPT_STATUS_int_i2s_sec_word_length_change_shift         (5)
#define INTERRUPT_STATUS_int_sif_nopt_shift                           (4)
#define INTERRUPT_STATUS_int_msd_change_shift                         (3)
#define INTERRUPT_STATUS_int_msd_timeout_shift                        (2)
#define INTERRUPT_STATUS_int_mode_det_status_change_shift             (1)
#define INTERRUPT_STATUS_int_sif_ovf_shift                            (0)
#define INTERRUPT_STATUS_int_fifo0_ts_full_mask                       (0x40000000)
#define INTERRUPT_STATUS_int_fifo0_ts_empty_mask                      (0x20000000)
#define INTERRUPT_STATUS_int_pll64512_wd_mask                         (0x10000000)
#define INTERRUPT_STATUS_int_msd_decision_done_mask                   (0x08000000)
#define INTERRUPT_STATUS_int_msd_fw_scan_done_mask                    (0x04000000)
#define INTERRUPT_STATUS_int_rbus_timeout_mask                        (0x02000000)
#define INTERRUPT_STATUS_int_btsc_mode_chg_mask                       (0x01000000)
#define INTERRUPT_STATUS_int_fifo3_full_mask                          (0x00800000)
#define INTERRUPT_STATUS_int_fifo2_full_mask                          (0x00400000)
#define INTERRUPT_STATUS_int_fifo1_full_mask                          (0x00200000)
#define INTERRUPT_STATUS_int_fifo0_full_mask                          (0x00100000)
#define INTERRUPT_STATUS_int_fifo3_empty_mask                         (0x00080000)
#define INTERRUPT_STATUS_int_fifo2_empty_mask                         (0x00040000)
#define INTERRUPT_STATUS_int_fifo1_empty_mask                         (0x00020000)
#define INTERRUPT_STATUS_int_fifo0_empty_mask                         (0x00010000)
#define INTERRUPT_STATUS_int_nicam_level_status_mask                  (0x00008000)
#define INTERRUPT_STATUS_int_ain_timer_mask                           (0x00004000)
#define INTERRUPT_STATUS_int_aout_timer_mask                          (0x00002000)
#define INTERRUPT_STATUS_int_spi_in_datatype_change_mask              (0x00001000)
#define INTERRUPT_STATUS_int_spi_in_lock_change_mask                  (0x00000800)
#define INTERRUPT_STATUS_int_nicam_hierr_change_mask                  (0x00000400)
#define INTERRUPT_STATUS_int_i2s_pri_sample_rate_chg_mask             (0x00000200)
#define INTERRUPT_STATUS_int_i2s_sec_sample_rate_chg_mask             (0x00000100)
#define INTERRUPT_STATUS_int_spi_sample_rate_chg_mask                 (0x00000080)
#define INTERRUPT_STATUS_int_i2s_pri_word_length_change_mask          (0x00000040)
#define INTERRUPT_STATUS_int_i2s_sec_word_length_change_mask          (0x00000020)
#define INTERRUPT_STATUS_int_sif_nopt_mask                            (0x00000010)
#define INTERRUPT_STATUS_int_msd_change_mask                          (0x00000008)
#define INTERRUPT_STATUS_int_msd_timeout_mask                         (0x00000004)
#define INTERRUPT_STATUS_int_mode_det_status_change_mask              (0x00000002)
#define INTERRUPT_STATUS_int_sif_ovf_mask                             (0x00000001)
#define INTERRUPT_STATUS_int_fifo0_ts_full(data)                      (0x40000000&((data)<<30))
#define INTERRUPT_STATUS_int_fifo0_ts_empty(data)                     (0x20000000&((data)<<29))
#define INTERRUPT_STATUS_int_pll64512_wd(data)                        (0x10000000&((data)<<28))
#define INTERRUPT_STATUS_int_msd_decision_done(data)                  (0x08000000&((data)<<27))
#define INTERRUPT_STATUS_int_msd_fw_scan_done(data)                   (0x04000000&((data)<<26))
#define INTERRUPT_STATUS_int_rbus_timeout(data)                       (0x02000000&((data)<<25))
#define INTERRUPT_STATUS_int_btsc_mode_chg(data)                      (0x01000000&((data)<<24))
#define INTERRUPT_STATUS_int_fifo3_full(data)                         (0x00800000&((data)<<23))
#define INTERRUPT_STATUS_int_fifo2_full(data)                         (0x00400000&((data)<<22))
#define INTERRUPT_STATUS_int_fifo1_full(data)                         (0x00200000&((data)<<21))
#define INTERRUPT_STATUS_int_fifo0_full(data)                         (0x00100000&((data)<<20))
#define INTERRUPT_STATUS_int_fifo3_empty(data)                        (0x00080000&((data)<<19))
#define INTERRUPT_STATUS_int_fifo2_empty(data)                        (0x00040000&((data)<<18))
#define INTERRUPT_STATUS_int_fifo1_empty(data)                        (0x00020000&((data)<<17))
#define INTERRUPT_STATUS_int_fifo0_empty(data)                        (0x00010000&((data)<<16))
#define INTERRUPT_STATUS_int_nicam_level_status(data)                 (0x00008000&((data)<<15))
#define INTERRUPT_STATUS_int_ain_timer(data)                          (0x00004000&((data)<<14))
#define INTERRUPT_STATUS_int_aout_timer(data)                         (0x00002000&((data)<<13))
#define INTERRUPT_STATUS_int_spi_in_datatype_change(data)             (0x00001000&((data)<<12))
#define INTERRUPT_STATUS_int_spi_in_lock_change(data)                 (0x00000800&((data)<<11))
#define INTERRUPT_STATUS_int_nicam_hierr_change(data)                 (0x00000400&((data)<<10))
#define INTERRUPT_STATUS_int_i2s_pri_sample_rate_chg(data)            (0x00000200&((data)<<9))
#define INTERRUPT_STATUS_int_i2s_sec_sample_rate_chg(data)            (0x00000100&((data)<<8))
#define INTERRUPT_STATUS_int_spi_sample_rate_chg(data)                (0x00000080&((data)<<7))
#define INTERRUPT_STATUS_int_i2s_pri_word_length_change(data)         (0x00000040&((data)<<6))
#define INTERRUPT_STATUS_int_i2s_sec_word_length_change(data)         (0x00000020&((data)<<5))
#define INTERRUPT_STATUS_int_sif_nopt(data)                           (0x00000010&((data)<<4))
#define INTERRUPT_STATUS_int_msd_change(data)                         (0x00000008&((data)<<3))
#define INTERRUPT_STATUS_int_msd_timeout(data)                        (0x00000004&((data)<<2))
#define INTERRUPT_STATUS_int_mode_det_status_change(data)             (0x00000002&((data)<<1))
#define INTERRUPT_STATUS_int_sif_ovf(data)                            (0x00000001&(data))
#define INTERRUPT_STATUS_get_int_fifo0_ts_full(data)                  ((0x40000000&(data))>>30)
#define INTERRUPT_STATUS_get_int_fifo0_ts_empty(data)                 ((0x20000000&(data))>>29)
#define INTERRUPT_STATUS_get_int_pll64512_wd(data)                    ((0x10000000&(data))>>28)
#define INTERRUPT_STATUS_get_int_msd_decision_done(data)              ((0x08000000&(data))>>27)
#define INTERRUPT_STATUS_get_int_msd_fw_scan_done(data)               ((0x04000000&(data))>>26)
#define INTERRUPT_STATUS_get_int_rbus_timeout(data)                   ((0x02000000&(data))>>25)
#define INTERRUPT_STATUS_get_int_btsc_mode_chg(data)                  ((0x01000000&(data))>>24)
#define INTERRUPT_STATUS_get_int_fifo3_full(data)                     ((0x00800000&(data))>>23)
#define INTERRUPT_STATUS_get_int_fifo2_full(data)                     ((0x00400000&(data))>>22)
#define INTERRUPT_STATUS_get_int_fifo1_full(data)                     ((0x00200000&(data))>>21)
#define INTERRUPT_STATUS_get_int_fifo0_full(data)                     ((0x00100000&(data))>>20)
#define INTERRUPT_STATUS_get_int_fifo3_empty(data)                    ((0x00080000&(data))>>19)
#define INTERRUPT_STATUS_get_int_fifo2_empty(data)                    ((0x00040000&(data))>>18)
#define INTERRUPT_STATUS_get_int_fifo1_empty(data)                    ((0x00020000&(data))>>17)
#define INTERRUPT_STATUS_get_int_fifo0_empty(data)                    ((0x00010000&(data))>>16)
#define INTERRUPT_STATUS_get_int_nicam_level_status(data)             ((0x00008000&(data))>>15)
#define INTERRUPT_STATUS_get_int_ain_timer(data)                      ((0x00004000&(data))>>14)
#define INTERRUPT_STATUS_get_int_aout_timer(data)                     ((0x00002000&(data))>>13)
#define INTERRUPT_STATUS_get_int_spi_in_datatype_change(data)         ((0x00001000&(data))>>12)
#define INTERRUPT_STATUS_get_int_spi_in_lock_change(data)             ((0x00000800&(data))>>11)
#define INTERRUPT_STATUS_get_int_nicam_hierr_change(data)             ((0x00000400&(data))>>10)
#define INTERRUPT_STATUS_get_int_i2s_pri_sample_rate_chg(data)        ((0x00000200&(data))>>9)
#define INTERRUPT_STATUS_get_int_i2s_sec_sample_rate_chg(data)        ((0x00000100&(data))>>8)
#define INTERRUPT_STATUS_get_int_spi_sample_rate_chg(data)            ((0x00000080&(data))>>7)
#define INTERRUPT_STATUS_get_int_i2s_pri_word_length_change(data)     ((0x00000040&(data))>>6)
#define INTERRUPT_STATUS_get_int_i2s_sec_word_length_change(data)     ((0x00000020&(data))>>5)
#define INTERRUPT_STATUS_get_int_sif_nopt(data)                       ((0x00000010&(data))>>4)
#define INTERRUPT_STATUS_get_int_msd_change(data)                     ((0x00000008&(data))>>3)
#define INTERRUPT_STATUS_get_int_msd_timeout(data)                    ((0x00000004&(data))>>2)
#define INTERRUPT_STATUS_get_int_mode_det_status_change(data)         ((0x00000002&(data))>>1)
#define INTERRUPT_STATUS_get_int_sif_ovf(data)                        (0x00000001&(data))


#define AIO_TIMER_EN                                                  0x18006058
#define AIO_TIMER_EN_reg_addr                                         "0xb8006058"
#define AIO_TIMER_EN_reg                                              0xb8006058
#define AIO_TIMER_EN_inst_addr                                        "0x0016"
#define AIO_TIMER_EN_inst                                             0x0016
#define AIO_TIMER_EN_ain_timer_en_shift                               (1)
#define AIO_TIMER_EN_aout_timer_en_shift                              (0)
#define AIO_TIMER_EN_ain_timer_en_mask                                (0x00000002)
#define AIO_TIMER_EN_aout_timer_en_mask                               (0x00000001)
#define AIO_TIMER_EN_ain_timer_en(data)                               (0x00000002&((data)<<1))
#define AIO_TIMER_EN_aout_timer_en(data)                              (0x00000001&(data))
#define AIO_TIMER_EN_get_ain_timer_en(data)                           ((0x00000002&(data))>>1)
#define AIO_TIMER_EN_get_aout_timer_en(data)                          (0x00000001&(data))


#define AIN_COUNTER                                                   0x1800605c
#define AIN_COUNTER_reg_addr                                          "0xb800605c"
#define AIN_COUNTER_reg                                               0xb800605c
#define AIN_COUNTER_inst_addr                                         "0x0017"
#define AIN_COUNTER_inst                                              0x0017
#define AIN_COUNTER_ain_timer_shift                                   (0)
#define AIN_COUNTER_ain_timer_mask                                    (0xFFFFFFFF)
#define AIN_COUNTER_ain_timer(data)                                   (0xFFFFFFFF&(data))
#define AIN_COUNTER_get_ain_timer(data)                               (0xFFFFFFFF&(data))


#define AIN_COMPARE                                                   0x18006060
#define AIN_COMPARE_reg_addr                                          "0xb8006060"
#define AIN_COMPARE_reg                                               0xb8006060
#define AIN_COMPARE_inst_addr                                         "0x0018"
#define AIN_COMPARE_inst                                              0x0018
#define AIN_COMPARE_ain_compare_shift                                 (0)
#define AIN_COMPARE_ain_compare_mask                                  (0xFFFFFFFF)
#define AIN_COMPARE_ain_compare(data)                                 (0xFFFFFFFF&(data))
#define AIN_COMPARE_get_ain_compare(data)                             (0xFFFFFFFF&(data))


#define AOUT_COUNTER                                                  0x18006064
#define AOUT_COUNTER_reg_addr                                         "0xb8006064"
#define AOUT_COUNTER_reg                                              0xb8006064
#define AOUT_COUNTER_inst_addr                                        "0x0019"
#define AOUT_COUNTER_inst                                             0x0019
#define AOUT_COUNTER_aout_timer_shift                                 (0)
#define AOUT_COUNTER_aout_timer_mask                                  (0xFFFFFFFF)
#define AOUT_COUNTER_aout_timer(data)                                 (0xFFFFFFFF&(data))
#define AOUT_COUNTER_get_aout_timer(data)                             (0xFFFFFFFF&(data))


#define AOUT_COMPARE                                                  0x18006068
#define AOUT_COMPARE_reg_addr                                         "0xb8006068"
#define AOUT_COMPARE_reg                                              0xb8006068
#define AOUT_COMPARE_inst_addr                                        "0x001A"
#define AOUT_COMPARE_inst                                             0x001A
#define AOUT_COMPARE_aout_compare_shift                               (0)
#define AOUT_COMPARE_aout_compare_mask                                (0xFFFFFFFF)
#define AOUT_COMPARE_aout_compare(data)                               (0xFFFFFFFF&(data))
#define AOUT_COMPARE_get_aout_compare(data)                           (0xFFFFFFFF&(data))


#define I2S_IN_PRIMARY                                                0x18006100
#define I2S_IN_PRIMARY_reg_addr                                       "0xb8006100"
#define I2S_IN_PRIMARY_reg                                            0xb8006100
#define I2S_IN_PRIMARY_inst_addr                                      "0x0040"
#define I2S_IN_PRIMARY_inst                                           0x0040
#define I2S_IN_PRIMARY_source_sel_shift                               (30)
#define I2S_IN_PRIMARY_left_right_shift                               (28)
#define I2S_IN_PRIMARY_mode_sel_shift                                 (27)
#define I2S_IN_PRIMARY_debounce_en_shift                              (26)
#define I2S_IN_PRIMARY_sclk_inv_shift                                 (25)
#define I2S_IN_PRIMARY_dummy18006100_24_16_shift                      (16)
#define I2S_IN_PRIMARY_sampling_rate_shift                            (8)
#define I2S_IN_PRIMARY_pcm_width_shift                                (0)
#define I2S_IN_PRIMARY_source_sel_mask                                (0xC0000000)
#define I2S_IN_PRIMARY_left_right_mask                                (0x30000000)
#define I2S_IN_PRIMARY_mode_sel_mask                                  (0x08000000)
#define I2S_IN_PRIMARY_debounce_en_mask                               (0x04000000)
#define I2S_IN_PRIMARY_sclk_inv_mask                                  (0x02000000)
#define I2S_IN_PRIMARY_dummy18006100_24_16_mask                       (0x01FF0000)
#define I2S_IN_PRIMARY_sampling_rate_mask                             (0x00000F00)
#define I2S_IN_PRIMARY_pcm_width_mask                                 (0x0000007F)
#define I2S_IN_PRIMARY_source_sel(data)                               (0xC0000000&((data)<<30))
#define I2S_IN_PRIMARY_left_right(data)                               (0x30000000&((data)<<28))
#define I2S_IN_PRIMARY_mode_sel(data)                                 (0x08000000&((data)<<27))
#define I2S_IN_PRIMARY_debounce_en(data)                              (0x04000000&((data)<<26))
#define I2S_IN_PRIMARY_sclk_inv(data)                                 (0x02000000&((data)<<25))
#define I2S_IN_PRIMARY_dummy18006100_24_16(data)                      (0x01FF0000&((data)<<16))
#define I2S_IN_PRIMARY_sampling_rate(data)                            (0x00000F00&((data)<<8))
#define I2S_IN_PRIMARY_pcm_width(data)                                (0x0000007F&(data))
#define I2S_IN_PRIMARY_get_source_sel(data)                           ((0xC0000000&(data))>>30)
#define I2S_IN_PRIMARY_get_left_right(data)                           ((0x30000000&(data))>>28)
#define I2S_IN_PRIMARY_get_mode_sel(data)                             ((0x08000000&(data))>>27)
#define I2S_IN_PRIMARY_get_debounce_en(data)                          ((0x04000000&(data))>>26)
#define I2S_IN_PRIMARY_get_sclk_inv(data)                             ((0x02000000&(data))>>25)
#define I2S_IN_PRIMARY_get_dummy18006100_24_16(data)                  ((0x01FF0000&(data))>>16)
#define I2S_IN_PRIMARY_get_sampling_rate(data)                        ((0x00000F00&(data))>>8)
#define I2S_IN_PRIMARY_get_pcm_width(data)                            (0x0000007F&(data))


#define I2S_IN_SECONDARY                                              0x18006110
#define I2S_IN_SECONDARY_reg_addr                                     "0xb8006110"
#define I2S_IN_SECONDARY_reg                                          0xb8006110
#define I2S_IN_SECONDARY_inst_addr                                    "0x0044"
#define I2S_IN_SECONDARY_inst                                         0x0044
#define I2S_IN_SECONDARY_source_sel_shift                             (30)
#define I2S_IN_SECONDARY_left_right_shift                             (28)
#define I2S_IN_SECONDARY_mode_sel_shift                               (27)
#define I2S_IN_SECONDARY_debounce_en_shift                            (26)
#define I2S_IN_SECONDARY_sclk_inv_shift                               (25)
#define I2S_IN_SECONDARY_sampling_rate_shift                          (8)
#define I2S_IN_SECONDARY_pcm_width_shift                              (0)
#define I2S_IN_SECONDARY_source_sel_mask                              (0xC0000000)
#define I2S_IN_SECONDARY_left_right_mask                              (0x30000000)
#define I2S_IN_SECONDARY_mode_sel_mask                                (0x08000000)
#define I2S_IN_SECONDARY_debounce_en_mask                             (0x04000000)
#define I2S_IN_SECONDARY_sclk_inv_mask                                (0x02000000)
#define I2S_IN_SECONDARY_sampling_rate_mask                           (0x00000F00)
#define I2S_IN_SECONDARY_pcm_width_mask                               (0x0000007F)
#define I2S_IN_SECONDARY_source_sel(data)                             (0xC0000000&((data)<<30))
#define I2S_IN_SECONDARY_left_right(data)                             (0x30000000&((data)<<28))
#define I2S_IN_SECONDARY_mode_sel(data)                               (0x08000000&((data)<<27))
#define I2S_IN_SECONDARY_debounce_en(data)                            (0x04000000&((data)<<26))
#define I2S_IN_SECONDARY_sclk_inv(data)                               (0x02000000&((data)<<25))
#define I2S_IN_SECONDARY_sampling_rate(data)                          (0x00000F00&((data)<<8))
#define I2S_IN_SECONDARY_pcm_width(data)                              (0x0000007F&(data))
#define I2S_IN_SECONDARY_get_source_sel(data)                         ((0xC0000000&(data))>>30)
#define I2S_IN_SECONDARY_get_left_right(data)                         ((0x30000000&(data))>>28)
#define I2S_IN_SECONDARY_get_mode_sel(data)                           ((0x08000000&(data))>>27)
#define I2S_IN_SECONDARY_get_debounce_en(data)                        ((0x04000000&(data))>>26)
#define I2S_IN_SECONDARY_get_sclk_inv(data)                           ((0x02000000&(data))>>25)
#define I2S_IN_SECONDARY_get_sampling_rate(data)                      ((0x00000F00&(data))>>8)
#define I2S_IN_SECONDARY_get_pcm_width(data)                          (0x0000007F&(data))


#define SPDIF_IN                                                      0x18006130
#define SPDIF_IN_reg_addr                                             "0xb8006130"
#define SPDIF_IN_reg                                                  0xb8006130
#define SPDIF_IN_inst_addr                                            "0x004C"
#define SPDIF_IN_inst                                                 0x004C
#define SPDIF_IN_source_sel_shift                                     (30)
#define SPDIF_IN_req_after_lock_shift                                 (29)
#define SPDIF_IN_debounce_en_shift                                    (28)
#define SPDIF_IN_dummy18006130_15_5_shift                             (5)
#define SPDIF_IN_sampling_rate_shift                                  (0)
#define SPDIF_IN_source_sel_mask                                      (0xC0000000)
#define SPDIF_IN_req_after_lock_mask                                  (0x20000000)
#define SPDIF_IN_debounce_en_mask                                     (0x10000000)
#define SPDIF_IN_dummy18006130_15_5_mask                              (0x0000FFE0)
#define SPDIF_IN_sampling_rate_mask                                   (0x0000000F)
#define SPDIF_IN_source_sel(data)                                     (0xC0000000&((data)<<30))
#define SPDIF_IN_req_after_lock(data)                                 (0x20000000&((data)<<29))
#define SPDIF_IN_debounce_en(data)                                    (0x10000000&((data)<<28))
#define SPDIF_IN_dummy18006130_15_5(data)                             (0x0000FFE0&((data)<<5))
#define SPDIF_IN_sampling_rate(data)                                  (0x0000000F&(data))
#define SPDIF_IN_get_source_sel(data)                                 ((0xC0000000&(data))>>30)
#define SPDIF_IN_get_req_after_lock(data)                             ((0x20000000&(data))>>29)
#define SPDIF_IN_get_debounce_en(data)                                ((0x10000000&(data))>>28)
#define SPDIF_IN_get_dummy18006130_15_5(data)                         ((0x0000FFE0&(data))>>5)
#define SPDIF_IN_get_sampling_rate(data)                              (0x0000000F&(data))


#define SPDIF_IN_CS                                                   0x18006134
#define SPDIF_IN_CS_reg_addr                                          "0xb8006134"
#define SPDIF_IN_CS_reg                                               0xb8006134
#define SPDIF_IN_CS_inst_addr                                         "0x004D"
#define SPDIF_IN_CS_inst                                              0x004D
#define SPDIF_IN_CS_hw_locked_shift                                   (31)
#define SPDIF_IN_CS_invalid_bit_shift                                 (30)
#define SPDIF_IN_CS_clock_accuracy_shift                              (28)
#define SPDIF_IN_CS_sampling_freq_shift                               (24)
#define SPDIF_IN_CS_channel_number_shift                              (20)
#define SPDIF_IN_CS_source_number_shift                               (16)
#define SPDIF_IN_CS_category_code_shift                               (8)
#define SPDIF_IN_CS_mode_shift                                        (6)
#define SPDIF_IN_CS_pre_emphasis_shift                                (3)
#define SPDIF_IN_CS_copyright_shift                                   (2)
#define SPDIF_IN_CS_data_type_shift                                   (1)
#define SPDIF_IN_CS_professional_shift                                (0)
#define SPDIF_IN_CS_hw_locked_mask                                    (0x80000000)
#define SPDIF_IN_CS_invalid_bit_mask                                  (0x40000000)
#define SPDIF_IN_CS_clock_accuracy_mask                               (0x30000000)
#define SPDIF_IN_CS_sampling_freq_mask                                (0x0F000000)
#define SPDIF_IN_CS_channel_number_mask                               (0x00F00000)
#define SPDIF_IN_CS_source_number_mask                                (0x000F0000)
#define SPDIF_IN_CS_category_code_mask                                (0x0000FF00)
#define SPDIF_IN_CS_mode_mask                                         (0x000000C0)
#define SPDIF_IN_CS_pre_emphasis_mask                                 (0x00000038)
#define SPDIF_IN_CS_copyright_mask                                    (0x00000004)
#define SPDIF_IN_CS_data_type_mask                                    (0x00000002)
#define SPDIF_IN_CS_professional_mask                                 (0x00000001)
#define SPDIF_IN_CS_hw_locked(data)                                   (0x80000000&((data)<<31))
#define SPDIF_IN_CS_invalid_bit(data)                                 (0x40000000&((data)<<30))
#define SPDIF_IN_CS_clock_accuracy(data)                              (0x30000000&((data)<<28))
#define SPDIF_IN_CS_sampling_freq(data)                               (0x0F000000&((data)<<24))
#define SPDIF_IN_CS_channel_number(data)                              (0x00F00000&((data)<<20))
#define SPDIF_IN_CS_source_number(data)                               (0x000F0000&((data)<<16))
#define SPDIF_IN_CS_category_code(data)                               (0x0000FF00&((data)<<8))
#define SPDIF_IN_CS_mode(data)                                        (0x000000C0&((data)<<6))
#define SPDIF_IN_CS_pre_emphasis(data)                                (0x00000038&((data)<<3))
#define SPDIF_IN_CS_copyright(data)                                   (0x00000004&((data)<<2))
#define SPDIF_IN_CS_data_type(data)                                   (0x00000002&((data)<<1))
#define SPDIF_IN_CS_professional(data)                                (0x00000001&(data))
#define SPDIF_IN_CS_get_hw_locked(data)                               ((0x80000000&(data))>>31)
#define SPDIF_IN_CS_get_invalid_bit(data)                             ((0x40000000&(data))>>30)
#define SPDIF_IN_CS_get_clock_accuracy(data)                          ((0x30000000&(data))>>28)
#define SPDIF_IN_CS_get_sampling_freq(data)                           ((0x0F000000&(data))>>24)
#define SPDIF_IN_CS_get_channel_number(data)                          ((0x00F00000&(data))>>20)
#define SPDIF_IN_CS_get_source_number(data)                           ((0x000F0000&(data))>>16)
#define SPDIF_IN_CS_get_category_code(data)                           ((0x0000FF00&(data))>>8)
#define SPDIF_IN_CS_get_mode(data)                                    ((0x000000C0&(data))>>6)
#define SPDIF_IN_CS_get_pre_emphasis(data)                            ((0x00000038&(data))>>3)
#define SPDIF_IN_CS_get_copyright(data)                               ((0x00000004&(data))>>2)
#define SPDIF_IN_CS_get_data_type(data)                               ((0x00000002&(data))>>1)
#define SPDIF_IN_CS_get_professional(data)                            (0x00000001&(data))


#define I2S_OUT                                                       0x18006150
#define I2S_OUT_reg_addr                                              "0xb8006150"
#define I2S_OUT_reg                                                   0xb8006150
#define I2S_OUT_inst_addr                                             "0x0054"
#define I2S_OUT_inst                                                  0x0054
#define I2S_OUT_output_sel_shift                                      (28)
#define I2S_OUT_mclk_sel_shift                                        (24)
#define I2S_OUT_pcm_source_sel_shift                                  (18)
#define I2S_OUT_wclk_inv_shift                                        (17)
#define I2S_OUT_sclk_inv_shift                                        (16)
#define I2S_OUT_dummy18006150_15_0_shift                              (0)
#define I2S_OUT_output_sel_mask                                       (0x70000000)
#define I2S_OUT_mclk_sel_mask                                         (0x03000000)
#define I2S_OUT_pcm_source_sel_mask                                   (0x00040000)
#define I2S_OUT_wclk_inv_mask                                         (0x00020000)
#define I2S_OUT_sclk_inv_mask                                         (0x00010000)
#define I2S_OUT_dummy18006150_15_0_mask                               (0x0000FFFF)
#define I2S_OUT_output_sel(data)                                      (0x70000000&((data)<<28))
#define I2S_OUT_mclk_sel(data)                                        (0x03000000&((data)<<24))
#define I2S_OUT_pcm_source_sel(data)                                  (0x00040000&((data)<<18))
#define I2S_OUT_wclk_inv(data)                                        (0x00020000&((data)<<17))
#define I2S_OUT_sclk_inv(data)                                        (0x00010000&((data)<<16))
#define I2S_OUT_dummy18006150_15_0(data)                              (0x0000FFFF&(data))
#define I2S_OUT_get_output_sel(data)                                  ((0x70000000&(data))>>28)
#define I2S_OUT_get_mclk_sel(data)                                    ((0x03000000&(data))>>24)
#define I2S_OUT_get_pcm_source_sel(data)                              ((0x00040000&(data))>>18)
#define I2S_OUT_get_wclk_inv(data)                                    ((0x00020000&(data))>>17)
#define I2S_OUT_get_sclk_inv(data)                                    ((0x00010000&(data))>>16)
#define I2S_OUT_get_dummy18006150_15_0(data)                          (0x0000FFFF&(data))


#define SPDIF_OUT                                                     0x18006170
#define SPDIF_OUT_reg_addr                                            "0xb8006170"
#define SPDIF_OUT_reg                                                 0xb8006170
#define SPDIF_OUT_inst_addr                                           "0x005C"
#define SPDIF_OUT_inst                                                0x005C
#define SPDIF_OUT_output_sel_shift                                    (30)
#define SPDIF_OUT_pcm_source_sel_shift                                (29)
#define SPDIF_OUT_validity_ctrl_shift                                 (28)
#define SPDIF_OUT_dummy18006170_15_0_shift                            (0)
#define SPDIF_OUT_output_sel_mask                                     (0xC0000000)
#define SPDIF_OUT_pcm_source_sel_mask                                 (0x20000000)
#define SPDIF_OUT_validity_ctrl_mask                                  (0x10000000)
#define SPDIF_OUT_dummy18006170_15_0_mask                             (0x0000FFFF)
#define SPDIF_OUT_output_sel(data)                                    (0xC0000000&((data)<<30))
#define SPDIF_OUT_pcm_source_sel(data)                                (0x20000000&((data)<<29))
#define SPDIF_OUT_validity_ctrl(data)                                 (0x10000000&((data)<<28))
#define SPDIF_OUT_dummy18006170_15_0(data)                            (0x0000FFFF&(data))
#define SPDIF_OUT_get_output_sel(data)                                ((0xC0000000&(data))>>30)
#define SPDIF_OUT_get_pcm_source_sel(data)                            ((0x20000000&(data))>>29)
#define SPDIF_OUT_get_validity_ctrl(data)                             ((0x10000000&(data))>>28)
#define SPDIF_OUT_get_dummy18006170_15_0(data)                        (0x0000FFFF&(data))


#define SPDIF_OUT_CS                                                  0x18006174
#define SPDIF_OUT_CS_reg_addr                                         "0xb8006174"
#define SPDIF_OUT_CS_reg                                              0xb8006174
#define SPDIF_OUT_CS_inst_addr                                        "0x005D"
#define SPDIF_OUT_CS_inst                                             0x005D
#define SPDIF_OUT_CS_clock_accuracy_shift                             (28)
#define SPDIF_OUT_CS_sampling_freq_shift                              (24)
#define SPDIF_OUT_CS_channel_number_shift                             (20)
#define SPDIF_OUT_CS_source_number_shift                              (16)
#define SPDIF_OUT_CS_category_code_shift                              (8)
#define SPDIF_OUT_CS_mode_shift                                       (6)
#define SPDIF_OUT_CS_pre_emphasis_shift                               (3)
#define SPDIF_OUT_CS_copyright_shift                                  (2)
#define SPDIF_OUT_CS_data_type_shift                                  (1)
#define SPDIF_OUT_CS_professional_shift                               (0)
#define SPDIF_OUT_CS_clock_accuracy_mask                              (0x30000000)
#define SPDIF_OUT_CS_sampling_freq_mask                               (0x0F000000)
#define SPDIF_OUT_CS_channel_number_mask                              (0x00F00000)
#define SPDIF_OUT_CS_source_number_mask                               (0x000F0000)
#define SPDIF_OUT_CS_category_code_mask                               (0x0000FF00)
#define SPDIF_OUT_CS_mode_mask                                        (0x000000C0)
#define SPDIF_OUT_CS_pre_emphasis_mask                                (0x00000038)
#define SPDIF_OUT_CS_copyright_mask                                   (0x00000004)
#define SPDIF_OUT_CS_data_type_mask                                   (0x00000002)
#define SPDIF_OUT_CS_professional_mask                                (0x00000001)
#define SPDIF_OUT_CS_clock_accuracy(data)                             (0x30000000&((data)<<28))
#define SPDIF_OUT_CS_sampling_freq(data)                              (0x0F000000&((data)<<24))
#define SPDIF_OUT_CS_channel_number(data)                             (0x00F00000&((data)<<20))
#define SPDIF_OUT_CS_source_number(data)                              (0x000F0000&((data)<<16))
#define SPDIF_OUT_CS_category_code(data)                              (0x0000FF00&((data)<<8))
#define SPDIF_OUT_CS_mode(data)                                       (0x000000C0&((data)<<6))
#define SPDIF_OUT_CS_pre_emphasis(data)                               (0x00000038&((data)<<3))
#define SPDIF_OUT_CS_copyright(data)                                  (0x00000004&((data)<<2))
#define SPDIF_OUT_CS_data_type(data)                                  (0x00000002&((data)<<1))
#define SPDIF_OUT_CS_professional(data)                               (0x00000001&(data))
#define SPDIF_OUT_CS_get_clock_accuracy(data)                         ((0x30000000&(data))>>28)
#define SPDIF_OUT_CS_get_sampling_freq(data)                          ((0x0F000000&(data))>>24)
#define SPDIF_OUT_CS_get_channel_number(data)                         ((0x00F00000&(data))>>20)
#define SPDIF_OUT_CS_get_source_number(data)                          ((0x000F0000&(data))>>16)
#define SPDIF_OUT_CS_get_category_code(data)                          ((0x0000FF00&(data))>>8)
#define SPDIF_OUT_CS_get_mode(data)                                   ((0x000000C0&(data))>>6)
#define SPDIF_OUT_CS_get_pre_emphasis(data)                           ((0x00000038&(data))>>3)
#define SPDIF_OUT_CS_get_copyright(data)                              ((0x00000004&(data))>>2)
#define SPDIF_OUT_CS_get_data_type(data)                              ((0x00000002&(data))>>1)
#define SPDIF_OUT_CS_get_professional(data)                           (0x00000001&(data))


#define SIF_AGC_EVAL_CNT                                              0x18006180
#define SIF_AGC_EVAL_CNT_reg_addr                                     "0xb8006180"
#define SIF_AGC_EVAL_CNT_reg                                          0xb8006180
#define SIF_AGC_EVAL_CNT_inst_addr                                    "0x0060"
#define SIF_AGC_EVAL_CNT_inst                                         0x0060
#define SIF_AGC_EVAL_CNT_dummy18006180_19_17_shift                    (17)
#define SIF_AGC_EVAL_CNT_hw_agc_en_shift                              (16)
#define SIF_AGC_EVAL_CNT_ob_time_shift                                (0)
#define SIF_AGC_EVAL_CNT_dummy18006180_19_17_mask                     (0x000E0000)
#define SIF_AGC_EVAL_CNT_hw_agc_en_mask                               (0x00010000)
#define SIF_AGC_EVAL_CNT_ob_time_mask                                 (0x0000FFFF)
#define SIF_AGC_EVAL_CNT_dummy18006180_19_17(data)                    (0x000E0000&((data)<<17))
#define SIF_AGC_EVAL_CNT_hw_agc_en(data)                              (0x00010000&((data)<<16))
#define SIF_AGC_EVAL_CNT_ob_time(data)                                (0x0000FFFF&(data))
#define SIF_AGC_EVAL_CNT_get_dummy18006180_19_17(data)                ((0x000E0000&(data))>>17)
#define SIF_AGC_EVAL_CNT_get_hw_agc_en(data)                          ((0x00010000&(data))>>16)
#define SIF_AGC_EVAL_CNT_get_ob_time(data)                            (0x0000FFFF&(data))


#define SIF_AGC_OPTIMAL                                               0x18006184
#define SIF_AGC_OPTIMAL_reg_addr                                      "0xb8006184"
#define SIF_AGC_OPTIMAL_reg                                           0xb8006184
#define SIF_AGC_OPTIMAL_inst_addr                                     "0x0061"
#define SIF_AGC_OPTIMAL_inst                                          0x0061
#define SIF_AGC_OPTIMAL_non_opt_cnt_th_shift                          (16)
#define SIF_AGC_OPTIMAL_non_opt_cnt_under_shift                       (8)
#define SIF_AGC_OPTIMAL_non_opt_cnt_ovf_shift                         (0)
#define SIF_AGC_OPTIMAL_non_opt_cnt_th_mask                           (0x00070000)
#define SIF_AGC_OPTIMAL_non_opt_cnt_under_mask                        (0x0000FF00)
#define SIF_AGC_OPTIMAL_non_opt_cnt_ovf_mask                          (0x000000FF)
#define SIF_AGC_OPTIMAL_non_opt_cnt_th(data)                          (0x00070000&((data)<<16))
#define SIF_AGC_OPTIMAL_non_opt_cnt_under(data)                       (0x0000FF00&((data)<<8))
#define SIF_AGC_OPTIMAL_non_opt_cnt_ovf(data)                         (0x000000FF&(data))
#define SIF_AGC_OPTIMAL_get_non_opt_cnt_th(data)                      ((0x00070000&(data))>>16)
#define SIF_AGC_OPTIMAL_get_non_opt_cnt_under(data)                   ((0x0000FF00&(data))>>8)
#define SIF_AGC_OPTIMAL_get_non_opt_cnt_ovf(data)                     (0x000000FF&(data))


#define SIF_AGC_THRESHOLD                                             0x18006188
#define SIF_AGC_THRESHOLD_reg_addr                                    "0xb8006188"
#define SIF_AGC_THRESHOLD_reg                                         0xb8006188
#define SIF_AGC_THRESHOLD_inst_addr                                   "0x0062"
#define SIF_AGC_THRESHOLD_inst                                        0x0062
#define SIF_AGC_THRESHOLD_ovf_th_shift                                (16)
#define SIF_AGC_THRESHOLD_opt_th_shift                                (0)
#define SIF_AGC_THRESHOLD_ovf_th_mask                                 (0x03FF0000)
#define SIF_AGC_THRESHOLD_opt_th_mask                                 (0x000003FF)
#define SIF_AGC_THRESHOLD_ovf_th(data)                                (0x03FF0000&((data)<<16))
#define SIF_AGC_THRESHOLD_opt_th(data)                                (0x000003FF&(data))
#define SIF_AGC_THRESHOLD_get_ovf_th(data)                            ((0x03FF0000&(data))>>16)
#define SIF_AGC_THRESHOLD_get_opt_th(data)                            (0x000003FF&(data))


#define SIF_AGC_STATUS                                                0x1800618c
#define SIF_AGC_STATUS_reg_addr                                       "0xb800618c"
#define SIF_AGC_STATUS_reg                                            0xb800618c
#define SIF_AGC_STATUS_inst_addr                                      "0x0063"
#define SIF_AGC_STATUS_inst                                           0x0063
#define SIF_AGC_STATUS_ovf_shift                                      (13)
#define SIF_AGC_STATUS_opt_shift                                      (12)
#define SIF_AGC_STATUS_abs_peak_shift                                 (0)
#define SIF_AGC_STATUS_ovf_mask                                       (0x00002000)
#define SIF_AGC_STATUS_opt_mask                                       (0x00001000)
#define SIF_AGC_STATUS_abs_peak_mask                                  (0x000003FF)
#define SIF_AGC_STATUS_ovf(data)                                      (0x00002000&((data)<<13))
#define SIF_AGC_STATUS_opt(data)                                      (0x00001000&((data)<<12))
#define SIF_AGC_STATUS_abs_peak(data)                                 (0x000003FF&(data))
#define SIF_AGC_STATUS_get_ovf(data)                                  ((0x00002000&(data))>>13)
#define SIF_AGC_STATUS_get_opt(data)                                  ((0x00001000&(data))>>12)
#define SIF_AGC_STATUS_get_abs_peak(data)                             (0x000003FF&(data))


#define SIF_AGC2_CTRL                                                 0x18006190
#define SIF_AGC2_CTRL_reg_addr                                        "0xb8006190"
#define SIF_AGC2_CTRL_reg                                             0xb8006190
#define SIF_AGC2_CTRL_inst_addr                                       "0x0064"
#define SIF_AGC2_CTRL_inst                                            0x0064
#define SIF_AGC2_CTRL_agc2_debounce_cnt_shift                         (28)
#define SIF_AGC2_CTRL_agc2_stepsize_shift                             (26)
#define SIF_AGC2_CTRL_agc2_gain_a_shift                               (24)
#define SIF_AGC2_CTRL_agc2_gain_b_shift                               (16)
#define SIF_AGC2_CTRL_agc2_obtime_shift                               (0)
#define SIF_AGC2_CTRL_agc2_debounce_cnt_mask                          (0x70000000)
#define SIF_AGC2_CTRL_agc2_stepsize_mask                              (0x0C000000)
#define SIF_AGC2_CTRL_agc2_gain_a_mask                                (0x03000000)
#define SIF_AGC2_CTRL_agc2_gain_b_mask                                (0x003F0000)
#define SIF_AGC2_CTRL_agc2_obtime_mask                                (0x0000FFFF)
#define SIF_AGC2_CTRL_agc2_debounce_cnt(data)                         (0x70000000&((data)<<28))
#define SIF_AGC2_CTRL_agc2_stepsize(data)                             (0x0C000000&((data)<<26))
#define SIF_AGC2_CTRL_agc2_gain_a(data)                               (0x03000000&((data)<<24))
#define SIF_AGC2_CTRL_agc2_gain_b(data)                               (0x003F0000&((data)<<16))
#define SIF_AGC2_CTRL_agc2_obtime(data)                               (0x0000FFFF&(data))
#define SIF_AGC2_CTRL_get_agc2_debounce_cnt(data)                     ((0x70000000&(data))>>28)
#define SIF_AGC2_CTRL_get_agc2_stepsize(data)                         ((0x0C000000&(data))>>26)
#define SIF_AGC2_CTRL_get_agc2_gain_a(data)                           ((0x03000000&(data))>>24)
#define SIF_AGC2_CTRL_get_agc2_gain_b(data)                           ((0x003F0000&(data))>>16)
#define SIF_AGC2_CTRL_get_agc2_obtime(data)                           (0x0000FFFF&(data))


#define SIF_AGC2_STATUS                                               0x18006194
#define SIF_AGC2_STATUS_reg_addr                                      "0xb8006194"
#define SIF_AGC2_STATUS_reg                                           0xb8006194
#define SIF_AGC2_STATUS_inst_addr                                     "0x0065"
#define SIF_AGC2_STATUS_inst                                          0x0065
#define SIF_AGC2_STATUS_agc2_en_shift                                 (31)
#define SIF_AGC2_STATUS_agc2_overflow_shift                           (29)
#define SIF_AGC2_STATUS_agc2_underflow_shift                          (28)
#define SIF_AGC2_STATUS_agc2_sif_mag_shift                            (0)
#define SIF_AGC2_STATUS_agc2_en_mask                                  (0x80000000)
#define SIF_AGC2_STATUS_agc2_overflow_mask                            (0x20000000)
#define SIF_AGC2_STATUS_agc2_underflow_mask                           (0x10000000)
#define SIF_AGC2_STATUS_agc2_sif_mag_mask                             (0x000003FF)
#define SIF_AGC2_STATUS_agc2_en(data)                                 (0x80000000&((data)<<31))
#define SIF_AGC2_STATUS_agc2_overflow(data)                           (0x20000000&((data)<<29))
#define SIF_AGC2_STATUS_agc2_underflow(data)                          (0x10000000&((data)<<28))
#define SIF_AGC2_STATUS_agc2_sif_mag(data)                            (0x000003FF&(data))
#define SIF_AGC2_STATUS_get_agc2_en(data)                             ((0x80000000&(data))>>31)
#define SIF_AGC2_STATUS_get_agc2_overflow(data)                       ((0x20000000&(data))>>29)
#define SIF_AGC2_STATUS_get_agc2_underflow(data)                      ((0x10000000&(data))>>28)
#define SIF_AGC2_STATUS_get_agc2_sif_mag(data)                        (0x000003FF&(data))


#define PEAK_CONTORL                                                  0x180061a0
#define PEAK_CONTORL_reg_addr                                         "0xb80061a0"
#define PEAK_CONTORL_reg                                              0xb80061a0
#define PEAK_CONTORL_inst_addr                                        "0x0068"
#define PEAK_CONTORL_inst                                             0x0068
#define PEAK_CONTORL_pdetect_enable_shift                             (4)
#define PEAK_CONTORL_detect_source_sel_shift                          (0)
#define PEAK_CONTORL_pdetect_enable_mask                              (0x00000010)
#define PEAK_CONTORL_detect_source_sel_mask                           (0x0000000F)
#define PEAK_CONTORL_pdetect_enable(data)                             (0x00000010&((data)<<4))
#define PEAK_CONTORL_detect_source_sel(data)                          (0x0000000F&(data))
#define PEAK_CONTORL_get_pdetect_enable(data)                         ((0x00000010&(data))>>4)
#define PEAK_CONTORL_get_detect_source_sel(data)                      (0x0000000F&(data))


#define PEAK_CONTORL_L_0                                              0x180061a8
#define PEAK_CONTORL_L_0_reg_addr                                     "0xb80061a8"
#define PEAK_CONTORL_L_0_reg                                          0xb80061a8
#define PEAK_CONTORL_L_0_inst_addr                                    "0x006A"
#define PEAK_CONTORL_L_0_inst                                         0x006A
#define PEAK_CONTORL_L_0_opt_th_l_shift                               (16)
#define PEAK_CONTORL_L_0_ovf_th_l_shift                               (0)
#define PEAK_CONTORL_L_0_opt_th_l_mask                                (0xFFFF0000)
#define PEAK_CONTORL_L_0_ovf_th_l_mask                                (0x0000FFFF)
#define PEAK_CONTORL_L_0_opt_th_l(data)                               (0xFFFF0000&((data)<<16))
#define PEAK_CONTORL_L_0_ovf_th_l(data)                               (0x0000FFFF&(data))
#define PEAK_CONTORL_L_0_get_opt_th_l(data)                           ((0xFFFF0000&(data))>>16)
#define PEAK_CONTORL_L_0_get_ovf_th_l(data)                           (0x0000FFFF&(data))


#define PEAK_CONTROL_L_1                                              0x180061ac
#define PEAK_CONTROL_L_1_reg_addr                                     "0xb80061ac"
#define PEAK_CONTROL_L_1_reg                                          0xb80061ac
#define PEAK_CONTROL_L_1_inst_addr                                    "0x006B"
#define PEAK_CONTROL_L_1_inst                                         0x006B
#define PEAK_CONTROL_L_1_dummy180061ac_31_19_shift                    (19)
#define PEAK_CONTROL_L_1_nonopt_cnt_tr_l_shift                        (16)
#define PEAK_CONTROL_L_1_vpp_eval_cnt_l_shift                         (0)
#define PEAK_CONTROL_L_1_dummy180061ac_31_19_mask                     (0xFFF80000)
#define PEAK_CONTROL_L_1_nonopt_cnt_tr_l_mask                         (0x00070000)
#define PEAK_CONTROL_L_1_vpp_eval_cnt_l_mask                          (0x00003FFF)
#define PEAK_CONTROL_L_1_dummy180061ac_31_19(data)                    (0xFFF80000&((data)<<19))
#define PEAK_CONTROL_L_1_nonopt_cnt_tr_l(data)                        (0x00070000&((data)<<16))
#define PEAK_CONTROL_L_1_vpp_eval_cnt_l(data)                         (0x00003FFF&(data))
#define PEAK_CONTROL_L_1_get_dummy180061ac_31_19(data)                ((0xFFF80000&(data))>>19)
#define PEAK_CONTROL_L_1_get_nonopt_cnt_tr_l(data)                    ((0x00070000&(data))>>16)
#define PEAK_CONTROL_L_1_get_vpp_eval_cnt_l(data)                     (0x00003FFF&(data))


#define PEAK_STATUS_L                                                 0x180061b0
#define PEAK_STATUS_L_reg_addr                                        "0xb80061b0"
#define PEAK_STATUS_L_reg                                             0xb80061b0
#define PEAK_STATUS_L_inst_addr                                       "0x006C"
#define PEAK_STATUS_L_inst                                            0x006C
#define PEAK_STATUS_L_optimize_l_irq_en_shift                         (31)
#define PEAK_STATUS_L_overflow_l_irq_en_shift                         (30)
#define PEAK_STATUS_L_optimize_l_shift                                (23)
#define PEAK_STATUS_L_overflow_l_shift                                (22)
#define PEAK_STATUS_L_pk_adj_l_shift                                  (16)
#define PEAK_STATUS_L_magnitude_l_shift                               (0)
#define PEAK_STATUS_L_optimize_l_irq_en_mask                          (0x80000000)
#define PEAK_STATUS_L_overflow_l_irq_en_mask                          (0x40000000)
#define PEAK_STATUS_L_optimize_l_mask                                 (0x00800000)
#define PEAK_STATUS_L_overflow_l_mask                                 (0x00400000)
#define PEAK_STATUS_L_pk_adj_l_mask                                   (0x003F0000)
#define PEAK_STATUS_L_magnitude_l_mask                                (0x0000FFFF)
#define PEAK_STATUS_L_optimize_l_irq_en(data)                         (0x80000000&((data)<<31))
#define PEAK_STATUS_L_overflow_l_irq_en(data)                         (0x40000000&((data)<<30))
#define PEAK_STATUS_L_optimize_l(data)                                (0x00800000&((data)<<23))
#define PEAK_STATUS_L_overflow_l(data)                                (0x00400000&((data)<<22))
#define PEAK_STATUS_L_pk_adj_l(data)                                  (0x003F0000&((data)<<16))
#define PEAK_STATUS_L_magnitude_l(data)                               (0x0000FFFF&(data))
#define PEAK_STATUS_L_get_optimize_l_irq_en(data)                     ((0x80000000&(data))>>31)
#define PEAK_STATUS_L_get_overflow_l_irq_en(data)                     ((0x40000000&(data))>>30)
#define PEAK_STATUS_L_get_optimize_l(data)                            ((0x00800000&(data))>>23)
#define PEAK_STATUS_L_get_overflow_l(data)                            ((0x00400000&(data))>>22)
#define PEAK_STATUS_L_get_pk_adj_l(data)                              ((0x003F0000&(data))>>16)
#define PEAK_STATUS_L_get_magnitude_l(data)                           (0x0000FFFF&(data))


#define PEAK_CONTORL_R_0                                              0x180061b4
#define PEAK_CONTORL_R_0_reg_addr                                     "0xb80061b4"
#define PEAK_CONTORL_R_0_reg                                          0xb80061b4
#define PEAK_CONTORL_R_0_inst_addr                                    "0x006D"
#define PEAK_CONTORL_R_0_inst                                         0x006D
#define PEAK_CONTORL_R_0_opt_th_r_shift                               (16)
#define PEAK_CONTORL_R_0_ovf_th_r_shift                               (0)
#define PEAK_CONTORL_R_0_opt_th_r_mask                                (0xFFFF0000)
#define PEAK_CONTORL_R_0_ovf_th_r_mask                                (0x0000FFFF)
#define PEAK_CONTORL_R_0_opt_th_r(data)                               (0xFFFF0000&((data)<<16))
#define PEAK_CONTORL_R_0_ovf_th_r(data)                               (0x0000FFFF&(data))
#define PEAK_CONTORL_R_0_get_opt_th_r(data)                           ((0xFFFF0000&(data))>>16)
#define PEAK_CONTORL_R_0_get_ovf_th_r(data)                           (0x0000FFFF&(data))


#define PEAK_CONTORL_R_1                                              0x180061b8
#define PEAK_CONTORL_R_1_reg_addr                                     "0xb80061b8"
#define PEAK_CONTORL_R_1_reg                                          0xb80061b8
#define PEAK_CONTORL_R_1_inst_addr                                    "0x006E"
#define PEAK_CONTORL_R_1_inst                                         0x006E
#define PEAK_CONTORL_R_1_dummy180061b8_31_19_shift                    (19)
#define PEAK_CONTORL_R_1_nonopt_cnt_tr_r_shift                        (16)
#define PEAK_CONTORL_R_1_vpp_eval_cnt_r_shift                         (0)
#define PEAK_CONTORL_R_1_dummy180061b8_31_19_mask                     (0xFFF80000)
#define PEAK_CONTORL_R_1_nonopt_cnt_tr_r_mask                         (0x00070000)
#define PEAK_CONTORL_R_1_vpp_eval_cnt_r_mask                          (0x00003FFF)
#define PEAK_CONTORL_R_1_dummy180061b8_31_19(data)                    (0xFFF80000&((data)<<19))
#define PEAK_CONTORL_R_1_nonopt_cnt_tr_r(data)                        (0x00070000&((data)<<16))
#define PEAK_CONTORL_R_1_vpp_eval_cnt_r(data)                         (0x00003FFF&(data))
#define PEAK_CONTORL_R_1_get_dummy180061b8_31_19(data)                ((0xFFF80000&(data))>>19)
#define PEAK_CONTORL_R_1_get_nonopt_cnt_tr_r(data)                    ((0x00070000&(data))>>16)
#define PEAK_CONTORL_R_1_get_vpp_eval_cnt_r(data)                     (0x00003FFF&(data))


#define PEAK_STATUS_R                                                 0x180061bc
#define PEAK_STATUS_R_reg_addr                                        "0xb80061bc"
#define PEAK_STATUS_R_reg                                             0xb80061bc
#define PEAK_STATUS_R_inst_addr                                       "0x006F"
#define PEAK_STATUS_R_inst                                            0x006F
#define PEAK_STATUS_R_optimize_r_irq_en_shift                         (31)
#define PEAK_STATUS_R_overflow_r_irq_en_shift                         (30)
#define PEAK_STATUS_R_optimize_r_shift                                (23)
#define PEAK_STATUS_R_overflow_r_shift                                (22)
#define PEAK_STATUS_R_pk_adj_r_shift                                  (16)
#define PEAK_STATUS_R_magnitude_r_shift                               (0)
#define PEAK_STATUS_R_optimize_r_irq_en_mask                          (0x80000000)
#define PEAK_STATUS_R_overflow_r_irq_en_mask                          (0x40000000)
#define PEAK_STATUS_R_optimize_r_mask                                 (0x00800000)
#define PEAK_STATUS_R_overflow_r_mask                                 (0x00400000)
#define PEAK_STATUS_R_pk_adj_r_mask                                   (0x003F0000)
#define PEAK_STATUS_R_magnitude_r_mask                                (0x0000FFFF)
#define PEAK_STATUS_R_optimize_r_irq_en(data)                         (0x80000000&((data)<<31))
#define PEAK_STATUS_R_overflow_r_irq_en(data)                         (0x40000000&((data)<<30))
#define PEAK_STATUS_R_optimize_r(data)                                (0x00800000&((data)<<23))
#define PEAK_STATUS_R_overflow_r(data)                                (0x00400000&((data)<<22))
#define PEAK_STATUS_R_pk_adj_r(data)                                  (0x003F0000&((data)<<16))
#define PEAK_STATUS_R_magnitude_r(data)                               (0x0000FFFF&(data))
#define PEAK_STATUS_R_get_optimize_r_irq_en(data)                     ((0x80000000&(data))>>31)
#define PEAK_STATUS_R_get_overflow_r_irq_en(data)                     ((0x40000000&(data))>>30)
#define PEAK_STATUS_R_get_optimize_r(data)                            ((0x00800000&(data))>>23)
#define PEAK_STATUS_R_get_overflow_r(data)                            ((0x00400000&(data))>>22)
#define PEAK_STATUS_R_get_pk_adj_r(data)                              ((0x003F0000&(data))>>16)
#define PEAK_STATUS_R_get_magnitude_r(data)                           (0x0000FFFF&(data))


#define POST_PEAK_CONTORL                                             0x180061c0
#define POST_PEAK_CONTORL_reg_addr                                    "0xb80061c0"
#define POST_PEAK_CONTORL_reg                                         0xb80061c0
#define POST_PEAK_CONTORL_inst_addr                                   "0x0070"
#define POST_PEAK_CONTORL_inst                                        0x0070
#define POST_PEAK_CONTORL_post_detect_source_sel_shift                (4)
#define POST_PEAK_CONTORL_post_detect_enable_shift                    (0)
#define POST_PEAK_CONTORL_post_detect_source_sel_mask                 (0x00000070)
#define POST_PEAK_CONTORL_post_detect_enable_mask                     (0x00000001)
#define POST_PEAK_CONTORL_post_detect_source_sel(data)                (0x00000070&((data)<<4))
#define POST_PEAK_CONTORL_post_detect_enable(data)                    (0x00000001&(data))
#define POST_PEAK_CONTORL_get_post_detect_source_sel(data)            ((0x00000070&(data))>>4)
#define POST_PEAK_CONTORL_get_post_detect_enable(data)                (0x00000001&(data))


#define POST_PEAK_CONTORL_L_0                                         0x180061c8
#define POST_PEAK_CONTORL_L_0_reg_addr                                "0xb80061c8"
#define POST_PEAK_CONTORL_L_0_reg                                     0xb80061c8
#define POST_PEAK_CONTORL_L_0_inst_addr                               "0x0072"
#define POST_PEAK_CONTORL_L_0_inst                                    0x0072
#define POST_PEAK_CONTORL_L_0_post_opt_th_l_shift                     (16)
#define POST_PEAK_CONTORL_L_0_post_ovf_th_l_shift                     (0)
#define POST_PEAK_CONTORL_L_0_post_opt_th_l_mask                      (0xFFFF0000)
#define POST_PEAK_CONTORL_L_0_post_ovf_th_l_mask                      (0x0000FFFF)
#define POST_PEAK_CONTORL_L_0_post_opt_th_l(data)                     (0xFFFF0000&((data)<<16))
#define POST_PEAK_CONTORL_L_0_post_ovf_th_l(data)                     (0x0000FFFF&(data))
#define POST_PEAK_CONTORL_L_0_get_post_opt_th_l(data)                 ((0xFFFF0000&(data))>>16)
#define POST_PEAK_CONTORL_L_0_get_post_ovf_th_l(data)                 (0x0000FFFF&(data))


#define POST_PEAK_CONTROL_L_1                                         0x180061cc
#define POST_PEAK_CONTROL_L_1_reg_addr                                "0xb80061cc"
#define POST_PEAK_CONTROL_L_1_reg                                     0xb80061cc
#define POST_PEAK_CONTROL_L_1_inst_addr                               "0x0073"
#define POST_PEAK_CONTROL_L_1_inst                                    0x0073
#define POST_PEAK_CONTROL_L_1_post_nonopt_cnt_tr_l_shift              (16)
#define POST_PEAK_CONTROL_L_1_post_vpp_eval_cnt_l_shift               (0)
#define POST_PEAK_CONTROL_L_1_post_nonopt_cnt_tr_l_mask               (0x00070000)
#define POST_PEAK_CONTROL_L_1_post_vpp_eval_cnt_l_mask                (0x00003FFF)
#define POST_PEAK_CONTROL_L_1_post_nonopt_cnt_tr_l(data)              (0x00070000&((data)<<16))
#define POST_PEAK_CONTROL_L_1_post_vpp_eval_cnt_l(data)               (0x00003FFF&(data))
#define POST_PEAK_CONTROL_L_1_get_post_nonopt_cnt_tr_l(data)          ((0x00070000&(data))>>16)
#define POST_PEAK_CONTROL_L_1_get_post_vpp_eval_cnt_l(data)           (0x00003FFF&(data))


#define POST_PEAK_STATUS_L                                            0x180061d0
#define POST_PEAK_STATUS_L_reg_addr                                   "0xb80061d0"
#define POST_PEAK_STATUS_L_reg                                        0xb80061d0
#define POST_PEAK_STATUS_L_inst_addr                                  "0x0074"
#define POST_PEAK_STATUS_L_inst                                       0x0074
#define POST_PEAK_STATUS_L_post_optimize_l_irq_en_shift               (31)
#define POST_PEAK_STATUS_L_post_overflow_l_irq_en_shift               (30)
#define POST_PEAK_STATUS_L_post_optimize_l_shift                      (23)
#define POST_PEAK_STATUS_L_post_overflow_l_shift                      (22)
#define POST_PEAK_STATUS_L_post_pk_adj_l_shift                        (16)
#define POST_PEAK_STATUS_L_post_magnitude_l_shift                     (0)
#define POST_PEAK_STATUS_L_post_optimize_l_irq_en_mask                (0x80000000)
#define POST_PEAK_STATUS_L_post_overflow_l_irq_en_mask                (0x40000000)
#define POST_PEAK_STATUS_L_post_optimize_l_mask                       (0x00800000)
#define POST_PEAK_STATUS_L_post_overflow_l_mask                       (0x00400000)
#define POST_PEAK_STATUS_L_post_pk_adj_l_mask                         (0x003F0000)
#define POST_PEAK_STATUS_L_post_magnitude_l_mask                      (0x0000FFFF)
#define POST_PEAK_STATUS_L_post_optimize_l_irq_en(data)               (0x80000000&((data)<<31))
#define POST_PEAK_STATUS_L_post_overflow_l_irq_en(data)               (0x40000000&((data)<<30))
#define POST_PEAK_STATUS_L_post_optimize_l(data)                      (0x00800000&((data)<<23))
#define POST_PEAK_STATUS_L_post_overflow_l(data)                      (0x00400000&((data)<<22))
#define POST_PEAK_STATUS_L_post_pk_adj_l(data)                        (0x003F0000&((data)<<16))
#define POST_PEAK_STATUS_L_post_magnitude_l(data)                     (0x0000FFFF&(data))
#define POST_PEAK_STATUS_L_get_post_optimize_l_irq_en(data)           ((0x80000000&(data))>>31)
#define POST_PEAK_STATUS_L_get_post_overflow_l_irq_en(data)           ((0x40000000&(data))>>30)
#define POST_PEAK_STATUS_L_get_post_optimize_l(data)                  ((0x00800000&(data))>>23)
#define POST_PEAK_STATUS_L_get_post_overflow_l(data)                  ((0x00400000&(data))>>22)
#define POST_PEAK_STATUS_L_get_post_pk_adj_l(data)                    ((0x003F0000&(data))>>16)
#define POST_PEAK_STATUS_L_get_post_magnitude_l(data)                 (0x0000FFFF&(data))


#define POST_PEAK_CONTORL_R_0                                         0x180061d4
#define POST_PEAK_CONTORL_R_0_reg_addr                                "0xb80061d4"
#define POST_PEAK_CONTORL_R_0_reg                                     0xb80061d4
#define POST_PEAK_CONTORL_R_0_inst_addr                               "0x0075"
#define POST_PEAK_CONTORL_R_0_inst                                    0x0075
#define POST_PEAK_CONTORL_R_0_post_opt_th_r_shift                     (16)
#define POST_PEAK_CONTORL_R_0_post_ovf_th_r_shift                     (0)
#define POST_PEAK_CONTORL_R_0_post_opt_th_r_mask                      (0xFFFF0000)
#define POST_PEAK_CONTORL_R_0_post_ovf_th_r_mask                      (0x0000FFFF)
#define POST_PEAK_CONTORL_R_0_post_opt_th_r(data)                     (0xFFFF0000&((data)<<16))
#define POST_PEAK_CONTORL_R_0_post_ovf_th_r(data)                     (0x0000FFFF&(data))
#define POST_PEAK_CONTORL_R_0_get_post_opt_th_r(data)                 ((0xFFFF0000&(data))>>16)
#define POST_PEAK_CONTORL_R_0_get_post_ovf_th_r(data)                 (0x0000FFFF&(data))


#define POST_PEAK_CONTORL_R_1                                         0x180061d8
#define POST_PEAK_CONTORL_R_1_reg_addr                                "0xb80061d8"
#define POST_PEAK_CONTORL_R_1_reg                                     0xb80061d8
#define POST_PEAK_CONTORL_R_1_inst_addr                               "0x0076"
#define POST_PEAK_CONTORL_R_1_inst                                    0x0076
#define POST_PEAK_CONTORL_R_1_post_nonopt_cnt_tr_r_shift              (16)
#define POST_PEAK_CONTORL_R_1_post_vpp_eval_cnt_r_shift               (0)
#define POST_PEAK_CONTORL_R_1_post_nonopt_cnt_tr_r_mask               (0x00070000)
#define POST_PEAK_CONTORL_R_1_post_vpp_eval_cnt_r_mask                (0x00003FFF)
#define POST_PEAK_CONTORL_R_1_post_nonopt_cnt_tr_r(data)              (0x00070000&((data)<<16))
#define POST_PEAK_CONTORL_R_1_post_vpp_eval_cnt_r(data)               (0x00003FFF&(data))
#define POST_PEAK_CONTORL_R_1_get_post_nonopt_cnt_tr_r(data)          ((0x00070000&(data))>>16)
#define POST_PEAK_CONTORL_R_1_get_post_vpp_eval_cnt_r(data)           (0x00003FFF&(data))


#define POST_PEAK_STATUS_R                                            0x180061dc
#define POST_PEAK_STATUS_R_reg_addr                                   "0xb80061dc"
#define POST_PEAK_STATUS_R_reg                                        0xb80061dc
#define POST_PEAK_STATUS_R_inst_addr                                  "0x0077"
#define POST_PEAK_STATUS_R_inst                                       0x0077
#define POST_PEAK_STATUS_R_post_optimize_r_irq_en_shift               (31)
#define POST_PEAK_STATUS_R_post_overflow_r_irq_en_shift               (30)
#define POST_PEAK_STATUS_R_post_optimize_r_shift                      (23)
#define POST_PEAK_STATUS_R_post_overflow_r_shift                      (22)
#define POST_PEAK_STATUS_R_post_pk_adj_r_shift                        (16)
#define POST_PEAK_STATUS_R_post_magnitude_r_shift                     (0)
#define POST_PEAK_STATUS_R_post_optimize_r_irq_en_mask                (0x80000000)
#define POST_PEAK_STATUS_R_post_overflow_r_irq_en_mask                (0x40000000)
#define POST_PEAK_STATUS_R_post_optimize_r_mask                       (0x00800000)
#define POST_PEAK_STATUS_R_post_overflow_r_mask                       (0x00400000)
#define POST_PEAK_STATUS_R_post_pk_adj_r_mask                         (0x003F0000)
#define POST_PEAK_STATUS_R_post_magnitude_r_mask                      (0x0000FFFF)
#define POST_PEAK_STATUS_R_post_optimize_r_irq_en(data)               (0x80000000&((data)<<31))
#define POST_PEAK_STATUS_R_post_overflow_r_irq_en(data)               (0x40000000&((data)<<30))
#define POST_PEAK_STATUS_R_post_optimize_r(data)                      (0x00800000&((data)<<23))
#define POST_PEAK_STATUS_R_post_overflow_r(data)                      (0x00400000&((data)<<22))
#define POST_PEAK_STATUS_R_post_pk_adj_r(data)                        (0x003F0000&((data)<<16))
#define POST_PEAK_STATUS_R_post_magnitude_r(data)                     (0x0000FFFF&(data))
#define POST_PEAK_STATUS_R_get_post_optimize_r_irq_en(data)           ((0x80000000&(data))>>31)
#define POST_PEAK_STATUS_R_get_post_overflow_r_irq_en(data)           ((0x40000000&(data))>>30)
#define POST_PEAK_STATUS_R_get_post_optimize_r(data)                  ((0x00800000&(data))>>23)
#define POST_PEAK_STATUS_R_get_post_overflow_r(data)                  ((0x00400000&(data))>>22)
#define POST_PEAK_STATUS_R_get_post_pk_adj_r(data)                    ((0x003F0000&(data))>>16)
#define POST_PEAK_STATUS_R_get_post_magnitude_r(data)                 (0x0000FFFF&(data))


#define MSD_CRTL_WORD                                                 0x18006200
#define MSD_CRTL_WORD_reg_addr                                        "0xb8006200"
#define MSD_CRTL_WORD_reg                                             0xb8006200
#define MSD_CRTL_WORD_inst_addr                                       "0x0080"
#define MSD_CRTL_WORD_inst                                            0x0080
#define MSD_CRTL_WORD_fw_scan_en_shift                                (30)
#define MSD_CRTL_WORD_msd_en_shift                                    (29)
#define MSD_CRTL_WORD_update_en_shift                                 (28)
#define MSD_CRTL_WORD_carrier_shift_scan_en_shift                     (27)
#define MSD_CRTL_WORD_carrier_phase_delta_shift                       (24)
#define MSD_CRTL_WORD_msd_debounce_cnt_shift                          (20)
#define MSD_CRTL_WORD_reg_scan_cnt_shift                              (12)
#define MSD_CRTL_WORD_mn_priority_shift                               (9)
#define MSD_CRTL_WORD_dkl_priority_shift                              (8)
#define MSD_CRTL_WORD_sound_select_shift                              (4)
#define MSD_CRTL_WORD_fw_scan_en_mask                                 (0x40000000)
#define MSD_CRTL_WORD_msd_en_mask                                     (0x20000000)
#define MSD_CRTL_WORD_update_en_mask                                  (0x10000000)
#define MSD_CRTL_WORD_carrier_shift_scan_en_mask                      (0x08000000)
#define MSD_CRTL_WORD_carrier_phase_delta_mask                        (0x07000000)
#define MSD_CRTL_WORD_msd_debounce_cnt_mask                           (0x00700000)
#define MSD_CRTL_WORD_reg_scan_cnt_mask                               (0x000FF000)
#define MSD_CRTL_WORD_mn_priority_mask                                (0x00000600)
#define MSD_CRTL_WORD_dkl_priority_mask                               (0x00000100)
#define MSD_CRTL_WORD_sound_select_mask                               (0x00000030)
#define MSD_CRTL_WORD_fw_scan_en(data)                                (0x40000000&((data)<<30))
#define MSD_CRTL_WORD_msd_en(data)                                    (0x20000000&((data)<<29))
#define MSD_CRTL_WORD_update_en(data)                                 (0x10000000&((data)<<28))
#define MSD_CRTL_WORD_carrier_shift_scan_en(data)                     (0x08000000&((data)<<27))
#define MSD_CRTL_WORD_carrier_phase_delta(data)                       (0x07000000&((data)<<24))
#define MSD_CRTL_WORD_msd_debounce_cnt(data)                          (0x00700000&((data)<<20))
#define MSD_CRTL_WORD_reg_scan_cnt(data)                              (0x000FF000&((data)<<12))
#define MSD_CRTL_WORD_mn_priority(data)                               (0x00000600&((data)<<9))
#define MSD_CRTL_WORD_dkl_priority(data)                              (0x00000100&((data)<<8))
#define MSD_CRTL_WORD_sound_select(data)                              (0x00000030&((data)<<4))
#define MSD_CRTL_WORD_get_fw_scan_en(data)                            ((0x40000000&(data))>>30)
#define MSD_CRTL_WORD_get_msd_en(data)                                ((0x20000000&(data))>>29)
#define MSD_CRTL_WORD_get_update_en(data)                             ((0x10000000&(data))>>28)
#define MSD_CRTL_WORD_get_carrier_shift_scan_en(data)                 ((0x08000000&(data))>>27)
#define MSD_CRTL_WORD_get_carrier_phase_delta(data)                   ((0x07000000&(data))>>24)
#define MSD_CRTL_WORD_get_msd_debounce_cnt(data)                      ((0x00700000&(data))>>20)
#define MSD_CRTL_WORD_get_reg_scan_cnt(data)                          ((0x000FF000&(data))>>12)
#define MSD_CRTL_WORD_get_mn_priority(data)                           ((0x00000600&(data))>>9)
#define MSD_CRTL_WORD_get_dkl_priority(data)                          ((0x00000100&(data))>>8)
#define MSD_CRTL_WORD_get_sound_select(data)                          ((0x00000030&(data))>>4)


#define MSD_RESULT                                                    0x18006204
#define MSD_RESULT_reg_addr                                           "0xb8006204"
#define MSD_RESULT_reg                                                0xb8006204
#define MSD_RESULT_inst_addr                                          "0x0081"
#define MSD_RESULT_inst                                               0x0081
#define MSD_RESULT_deviation_unnormal_shift                           (24)
#define MSD_RESULT_case_subtomain_shift                               (20)
#define MSD_RESULT_flag_unnormal_shift                                (18)
#define MSD_RESULT_flag_subtomain_shift                               (17)
#define MSD_RESULT_h_dv_th_sel_shift                                  (16)
#define MSD_RESULT_hw_detected_std_shift                              (8)
#define MSD_RESULT_reg_std_shift                                      (0)
#define MSD_RESULT_deviation_unnormal_mask                            (0x03000000)
#define MSD_RESULT_case_subtomain_mask                                (0x00F00000)
#define MSD_RESULT_flag_unnormal_mask                                 (0x00040000)
#define MSD_RESULT_flag_subtomain_mask                                (0x00020000)
#define MSD_RESULT_h_dv_th_sel_mask                                   (0x00010000)
#define MSD_RESULT_hw_detected_std_mask                               (0x00001F00)
#define MSD_RESULT_reg_std_mask                                       (0x0000001F)
#define MSD_RESULT_deviation_unnormal(data)                           (0x03000000&((data)<<24))
#define MSD_RESULT_case_subtomain(data)                               (0x00F00000&((data)<<20))
#define MSD_RESULT_flag_unnormal(data)                                (0x00040000&((data)<<18))
#define MSD_RESULT_flag_subtomain(data)                               (0x00020000&((data)<<17))
#define MSD_RESULT_h_dv_th_sel(data)                                  (0x00010000&((data)<<16))
#define MSD_RESULT_hw_detected_std(data)                              (0x00001F00&((data)<<8))
#define MSD_RESULT_reg_std(data)                                      (0x0000001F&(data))
#define MSD_RESULT_get_deviation_unnormal(data)                       ((0x03000000&(data))>>24)
#define MSD_RESULT_get_case_subtomain(data)                           ((0x00F00000&(data))>>20)
#define MSD_RESULT_get_flag_unnormal(data)                            ((0x00040000&(data))>>18)
#define MSD_RESULT_get_flag_subtomain(data)                           ((0x00020000&(data))>>17)
#define MSD_RESULT_get_h_dv_th_sel(data)                              ((0x00010000&(data))>>16)
#define MSD_RESULT_get_hw_detected_std(data)                          ((0x00001F00&(data))>>8)
#define MSD_RESULT_get_reg_std(data)                                  (0x0000001F&(data))


#define MSD_STATUS                                                    0x18006208
#define MSD_STATUS_reg_addr                                           "0xb8006208"
#define MSD_STATUS_reg                                                0xb8006208
#define MSD_STATUS_inst_addr                                          "0x0082"
#define MSD_STATUS_inst                                               0x0082
#define MSD_STATUS_bw_cnt_max_shift                                   (24)
#define MSD_STATUS_bw_cnt_min_shift                                   (16)
#define MSD_STATUS_shift_value_shift                                  (8)
#define MSD_STATUS_main_cari_idx_shift                                (4)
#define MSD_STATUS_deviation_shift                                    (0)
#define MSD_STATUS_bw_cnt_max_mask                                    (0x1F000000)
#define MSD_STATUS_bw_cnt_min_mask                                    (0x001F0000)
#define MSD_STATUS_shift_value_mask                                   (0x00000F00)
#define MSD_STATUS_main_cari_idx_mask                                 (0x00000070)
#define MSD_STATUS_deviation_mask                                     (0x0000000F)
#define MSD_STATUS_bw_cnt_max(data)                                   (0x1F000000&((data)<<24))
#define MSD_STATUS_bw_cnt_min(data)                                   (0x001F0000&((data)<<16))
#define MSD_STATUS_shift_value(data)                                  (0x00000F00&((data)<<8))
#define MSD_STATUS_main_cari_idx(data)                                (0x00000070&((data)<<4))
#define MSD_STATUS_deviation(data)                                    (0x0000000F&(data))
#define MSD_STATUS_get_bw_cnt_max(data)                               ((0x1F000000&(data))>>24)
#define MSD_STATUS_get_bw_cnt_min(data)                               ((0x001F0000&(data))>>16)
#define MSD_STATUS_get_shift_value(data)                              ((0x00000F00&(data))>>8)
#define MSD_STATUS_get_main_cari_idx(data)                            ((0x00000070&(data))>>4)
#define MSD_STATUS_get_deviation(data)                                (0x0000000F&(data))


#define MAIN_TONE_THRESHOLD                                           0x1800620c
#define MAIN_TONE_THRESHOLD_reg_addr                                  "0xb800620c"
#define MAIN_TONE_THRESHOLD_reg                                       0xb800620c
#define MAIN_TONE_THRESHOLD_inst_addr                                 "0x0083"
#define MAIN_TONE_THRESHOLD_inst                                      0x0083
#define MAIN_TONE_THRESHOLD_main_thresh_shift                         (16)
#define MAIN_TONE_THRESHOLD_main_thresh_low_shift                     (0)
#define MAIN_TONE_THRESHOLD_main_thresh_mask                          (0xFFFF0000)
#define MAIN_TONE_THRESHOLD_main_thresh_low_mask                      (0x0000FFFF)
#define MAIN_TONE_THRESHOLD_main_thresh(data)                         (0xFFFF0000&((data)<<16))
#define MAIN_TONE_THRESHOLD_main_thresh_low(data)                     (0x0000FFFF&(data))
#define MAIN_TONE_THRESHOLD_get_main_thresh(data)                     ((0xFFFF0000&(data))>>16)
#define MAIN_TONE_THRESHOLD_get_main_thresh_low(data)                 (0x0000FFFF&(data))


#define MAIN_TONE_THRESHOLD_HD                                        0x18006210
#define MAIN_TONE_THRESHOLD_HD_reg_addr                               "0xb8006210"
#define MAIN_TONE_THRESHOLD_HD_reg                                    0xb8006210
#define MAIN_TONE_THRESHOLD_HD_inst_addr                              "0x0084"
#define MAIN_TONE_THRESHOLD_HD_inst                                   0x0084
#define MAIN_TONE_THRESHOLD_HD_main_thresh_hd_shift                   (16)
#define MAIN_TONE_THRESHOLD_HD_main_thresh_hd_low_shift               (0)
#define MAIN_TONE_THRESHOLD_HD_main_thresh_hd_mask                    (0xFFFF0000)
#define MAIN_TONE_THRESHOLD_HD_main_thresh_hd_low_mask                (0x0000FFFF)
#define MAIN_TONE_THRESHOLD_HD_main_thresh_hd(data)                   (0xFFFF0000&((data)<<16))
#define MAIN_TONE_THRESHOLD_HD_main_thresh_hd_low(data)               (0x0000FFFF&(data))
#define MAIN_TONE_THRESHOLD_HD_get_main_thresh_hd(data)               ((0xFFFF0000&(data))>>16)
#define MAIN_TONE_THRESHOLD_HD_get_main_thresh_hd_low(data)           (0x0000FFFF&(data))


#define BW_THRESHOLD                                                  0x18006214
#define BW_THRESHOLD_reg_addr                                         "0xb8006214"
#define BW_THRESHOLD_reg                                              0xb8006214
#define BW_THRESHOLD_inst_addr                                        "0x0085"
#define BW_THRESHOLD_inst                                             0x0085
#define BW_THRESHOLD_bw_dev_thresh_hd_shift                           (16)
#define BW_THRESHOLD_bw_dev_thresh_shift                              (0)
#define BW_THRESHOLD_bw_dev_thresh_hd_mask                            (0xFFFF0000)
#define BW_THRESHOLD_bw_dev_thresh_mask                               (0x0000FFFF)
#define BW_THRESHOLD_bw_dev_thresh_hd(data)                           (0xFFFF0000&((data)<<16))
#define BW_THRESHOLD_bw_dev_thresh(data)                              (0x0000FFFF&(data))
#define BW_THRESHOLD_get_bw_dev_thresh_hd(data)                       ((0xFFFF0000&(data))>>16)
#define BW_THRESHOLD_get_bw_dev_thresh(data)                          (0x0000FFFF&(data))


#define MAIN_SUB_RATIO                                                0x18006218
#define MAIN_SUB_RATIO_reg_addr                                       "0xb8006218"
#define MAIN_SUB_RATIO_reg                                            0xb8006218
#define MAIN_SUB_RATIO_inst_addr                                      "0x0086"
#define MAIN_SUB_RATIO_inst                                           0x0086
#define MAIN_SUB_RATIO_bw_dev_thresh_low_shift                        (16)
#define MAIN_SUB_RATIO_main_sub_ratio_shift                           (0)
#define MAIN_SUB_RATIO_bw_dev_thresh_low_mask                         (0xFFFF0000)
#define MAIN_SUB_RATIO_main_sub_ratio_mask                            (0x0000FFFF)
#define MAIN_SUB_RATIO_bw_dev_thresh_low(data)                        (0xFFFF0000&((data)<<16))
#define MAIN_SUB_RATIO_main_sub_ratio(data)                           (0x0000FFFF&(data))
#define MAIN_SUB_RATIO_get_bw_dev_thresh_low(data)                    ((0xFFFF0000&(data))>>16)
#define MAIN_SUB_RATIO_get_main_sub_ratio(data)                       (0x0000FFFF&(data))


#define MSD_MAG_4_5                                                   0x1800621c
#define MSD_MAG_4_5_reg_addr                                          "0xb800621c"
#define MSD_MAG_4_5_reg                                               0xb800621c
#define MSD_MAG_4_5_inst_addr                                         "0x0087"
#define MSD_MAG_4_5_inst                                              0x0087
#define MSD_MAG_4_5_reg_mag_4_5_shift                                 (0)
#define MSD_MAG_4_5_reg_mag_4_5_mask                                  (0x0000FFFF)
#define MSD_MAG_4_5_reg_mag_4_5(data)                                 (0x0000FFFF&(data))
#define MSD_MAG_4_5_get_reg_mag_4_5(data)                             (0x0000FFFF&(data))


#define MSD_MAG_4_28                                                  0x18006220
#define MSD_MAG_4_28_reg_addr                                         "0xb8006220"
#define MSD_MAG_4_28_reg                                              0xb8006220
#define MSD_MAG_4_28_inst_addr                                        "0x0088"
#define MSD_MAG_4_28_inst                                             0x0088
#define MSD_MAG_4_28_reg_mag_4_28_shift                               (0)
#define MSD_MAG_4_28_reg_mag_4_28_mask                                (0x0000FFFF)
#define MSD_MAG_4_28_reg_mag_4_28(data)                               (0x0000FFFF&(data))
#define MSD_MAG_4_28_get_reg_mag_4_28(data)                           (0x0000FFFF&(data))


#define MSD_MAG_4_72                                                  0x18006224
#define MSD_MAG_4_72_reg_addr                                         "0xb8006224"
#define MSD_MAG_4_72_reg                                              0xb8006224
#define MSD_MAG_4_72_inst_addr                                        "0x0089"
#define MSD_MAG_4_72_inst                                             0x0089
#define MSD_MAG_4_72_reg_mag_4_72_shift                               (0)
#define MSD_MAG_4_72_reg_mag_4_72_mask                                (0x0000FFFF)
#define MSD_MAG_4_72_reg_mag_4_72(data)                               (0x0000FFFF&(data))
#define MSD_MAG_4_72_get_reg_mag_4_72(data)                           (0x0000FFFF&(data))


#define MSD_MAG_5_5                                                   0x18006228
#define MSD_MAG_5_5_reg_addr                                          "0xb8006228"
#define MSD_MAG_5_5_reg                                               0xb8006228
#define MSD_MAG_5_5_inst_addr                                         "0x008A"
#define MSD_MAG_5_5_inst                                              0x008A
#define MSD_MAG_5_5_reg_mag_5_5_shift                                 (0)
#define MSD_MAG_5_5_reg_mag_5_5_mask                                  (0x0000FFFF)
#define MSD_MAG_5_5_reg_mag_5_5(data)                                 (0x0000FFFF&(data))
#define MSD_MAG_5_5_get_reg_mag_5_5(data)                             (0x0000FFFF&(data))


#define MSD_MAG_5_25                                                  0x1800622c
#define MSD_MAG_5_25_reg_addr                                         "0xb800622c"
#define MSD_MAG_5_25_reg                                              0xb800622c
#define MSD_MAG_5_25_inst_addr                                        "0x008B"
#define MSD_MAG_5_25_inst                                             0x008B
#define MSD_MAG_5_25_reg_mag_5_25_shift                               (0)
#define MSD_MAG_5_25_reg_mag_5_25_mask                                (0x0000FFFF)
#define MSD_MAG_5_25_reg_mag_5_25(data)                               (0x0000FFFF&(data))
#define MSD_MAG_5_25_get_reg_mag_5_25(data)                           (0x0000FFFF&(data))


#define MSD_MAG_5_74                                                  0x18006230
#define MSD_MAG_5_74_reg_addr                                         "0xb8006230"
#define MSD_MAG_5_74_reg                                              0xb8006230
#define MSD_MAG_5_74_inst_addr                                        "0x008C"
#define MSD_MAG_5_74_inst                                             0x008C
#define MSD_MAG_5_74_reg_mag_5_74_shift                               (0)
#define MSD_MAG_5_74_reg_mag_5_74_mask                                (0x0000FFFF)
#define MSD_MAG_5_74_reg_mag_5_74(data)                               (0x0000FFFF&(data))
#define MSD_MAG_5_74_get_reg_mag_5_74(data)                           (0x0000FFFF&(data))


#define MSD_CARRIER_5_85                                              0x18006234
#define MSD_CARRIER_5_85_reg_addr                                     "0xb8006234"
#define MSD_CARRIER_5_85_reg                                          0xb8006234
#define MSD_CARRIER_5_85_inst_addr                                    "0x008D"
#define MSD_CARRIER_5_85_inst                                         0x008D
#define MSD_CARRIER_5_85_reg_mag_5_85_shift                           (0)
#define MSD_CARRIER_5_85_reg_mag_5_85_mask                            (0x0000FFFF)
#define MSD_CARRIER_5_85_reg_mag_5_85(data)                           (0x0000FFFF&(data))
#define MSD_CARRIER_5_85_get_reg_mag_5_85(data)                       (0x0000FFFF&(data))


#define MSD_CARRIER_5_95                                              0x18006238
#define MSD_CARRIER_5_95_reg_addr                                     "0xb8006238"
#define MSD_CARRIER_5_95_reg                                          0xb8006238
#define MSD_CARRIER_5_95_inst_addr                                    "0x008E"
#define MSD_CARRIER_5_95_inst                                         0x008E
#define MSD_CARRIER_5_95_reg_mag_5_95_shift                           (0)
#define MSD_CARRIER_5_95_reg_mag_5_95_mask                            (0x0000FFFF)
#define MSD_CARRIER_5_95_reg_mag_5_95(data)                           (0x0000FFFF&(data))
#define MSD_CARRIER_5_95_get_reg_mag_5_95(data)                       (0x0000FFFF&(data))


#define MSD_MAG_6                                                     0x1800623c
#define MSD_MAG_6_reg_addr                                            "0xb800623c"
#define MSD_MAG_6_reg                                                 0xb800623c
#define MSD_MAG_6_inst_addr                                           "0x008F"
#define MSD_MAG_6_inst                                                0x008F
#define MSD_MAG_6_reg_mag_6_shift                                     (0)
#define MSD_MAG_6_reg_mag_6_mask                                      (0x0000FFFF)
#define MSD_MAG_6_reg_mag_6(data)                                     (0x0000FFFF&(data))
#define MSD_MAG_6_get_reg_mag_6(data)                                 (0x0000FFFF&(data))


#define MSD_MAG_6_25                                                  0x18006240
#define MSD_MAG_6_25_reg_addr                                         "0xb8006240"
#define MSD_MAG_6_25_reg                                              0xb8006240
#define MSD_MAG_6_25_inst_addr                                        "0x0090"
#define MSD_MAG_6_25_inst                                             0x0090
#define MSD_MAG_6_25_reg_mag_6_25_shift                               (0)
#define MSD_MAG_6_25_reg_mag_6_25_mask                                (0x0000FFFF)
#define MSD_MAG_6_25_reg_mag_6_25(data)                               (0x0000FFFF&(data))
#define MSD_MAG_6_25_get_reg_mag_6_25(data)                           (0x0000FFFF&(data))


#define MSD_CARRIER_6_5                                               0x18006244
#define MSD_CARRIER_6_5_reg_addr                                      "0xb8006244"
#define MSD_CARRIER_6_5_reg                                           0xb8006244
#define MSD_CARRIER_6_5_inst_addr                                     "0x0091"
#define MSD_CARRIER_6_5_inst                                          0x0091
#define MSD_CARRIER_6_5_reg_mag_6_5_shift                             (0)
#define MSD_CARRIER_6_5_reg_mag_6_5_mask                              (0x0000FFFF)
#define MSD_CARRIER_6_5_reg_mag_6_5(data)                             (0x0000FFFF&(data))
#define MSD_CARRIER_6_5_get_reg_mag_6_5(data)                         (0x0000FFFF&(data))


#define MSD_MAG_6_552                                                 0x18006248
#define MSD_MAG_6_552_reg_addr                                        "0xb8006248"
#define MSD_MAG_6_552_reg                                             0xb8006248
#define MSD_MAG_6_552_inst_addr                                       "0x0092"
#define MSD_MAG_6_552_inst                                            0x0092
#define MSD_MAG_6_552_reg_mag_6_552_shift                             (0)
#define MSD_MAG_6_552_reg_mag_6_552_mask                              (0x0000FFFF)
#define MSD_MAG_6_552_reg_mag_6_552(data)                             (0x0000FFFF&(data))
#define MSD_MAG_6_552_get_reg_mag_6_552(data)                         (0x0000FFFF&(data))


#define MSD_CARRIER_6_74                                              0x1800624c
#define MSD_CARRIER_6_74_reg_addr                                     "0xb800624c"
#define MSD_CARRIER_6_74_reg                                          0xb800624c
#define MSD_CARRIER_6_74_inst_addr                                    "0x0093"
#define MSD_CARRIER_6_74_inst                                         0x0093
#define MSD_CARRIER_6_74_reg_mag_6_74_shift                           (0)
#define MSD_CARRIER_6_74_reg_mag_6_74_mask                            (0x0000FFFF)
#define MSD_CARRIER_6_74_reg_mag_6_74(data)                           (0x0000FFFF&(data))
#define MSD_CARRIER_6_74_get_reg_mag_6_74(data)                       (0x0000FFFF&(data))


#define MSD_FLAGS                                                     0x18006250
#define MSD_FLAGS_reg_addr                                            "0xb8006250"
#define MSD_FLAGS_reg                                                 0xb8006250
#define MSD_FLAGS_inst_addr                                           "0x0094"
#define MSD_FLAGS_inst                                                0x0094
#define MSD_FLAGS_flag_fw_4_shift                                     (14)
#define MSD_FLAGS_flag_fw_3_shift                                     (13)
#define MSD_FLAGS_flag_fw_2_shift                                     (12)
#define MSD_FLAGS_flag_fw_1_shift                                     (11)
#define MSD_FLAGS_flag_fw_shift                                       (10)
#define MSD_FLAGS_flag_4_5_shift                                      (9)
#define MSD_FLAGS_flag_5_5_shift                                      (8)
#define MSD_FLAGS_flag_6_shift                                        (7)
#define MSD_FLAGS_flag_6_5_shift                                      (6)
#define MSD_FLAGS_flag_4_72_shift                                     (5)
#define MSD_FLAGS_flag_5_74_shift                                     (4)
#define MSD_FLAGS_flag_5_85_shift                                     (3)
#define MSD_FLAGS_flag_6_25_shift                                     (2)
#define MSD_FLAGS_flag_6_552_shift                                    (1)
#define MSD_FLAGS_flag_6_74_shift                                     (0)
#define MSD_FLAGS_flag_fw_4_mask                                      (0x00004000)
#define MSD_FLAGS_flag_fw_3_mask                                      (0x00002000)
#define MSD_FLAGS_flag_fw_2_mask                                      (0x00001000)
#define MSD_FLAGS_flag_fw_1_mask                                      (0x00000800)
#define MSD_FLAGS_flag_fw_mask                                        (0x00000400)
#define MSD_FLAGS_flag_4_5_mask                                       (0x00000200)
#define MSD_FLAGS_flag_5_5_mask                                       (0x00000100)
#define MSD_FLAGS_flag_6_mask                                         (0x00000080)
#define MSD_FLAGS_flag_6_5_mask                                       (0x00000040)
#define MSD_FLAGS_flag_4_72_mask                                      (0x00000020)
#define MSD_FLAGS_flag_5_74_mask                                      (0x00000010)
#define MSD_FLAGS_flag_5_85_mask                                      (0x00000008)
#define MSD_FLAGS_flag_6_25_mask                                      (0x00000004)
#define MSD_FLAGS_flag_6_552_mask                                     (0x00000002)
#define MSD_FLAGS_flag_6_74_mask                                      (0x00000001)
#define MSD_FLAGS_flag_fw_4(data)                                     (0x00004000&((data)<<14))
#define MSD_FLAGS_flag_fw_3(data)                                     (0x00002000&((data)<<13))
#define MSD_FLAGS_flag_fw_2(data)                                     (0x00001000&((data)<<12))
#define MSD_FLAGS_flag_fw_1(data)                                     (0x00000800&((data)<<11))
#define MSD_FLAGS_flag_fw(data)                                       (0x00000400&((data)<<10))
#define MSD_FLAGS_flag_4_5(data)                                      (0x00000200&((data)<<9))
#define MSD_FLAGS_flag_5_5(data)                                      (0x00000100&((data)<<8))
#define MSD_FLAGS_flag_6(data)                                        (0x00000080&((data)<<7))
#define MSD_FLAGS_flag_6_5(data)                                      (0x00000040&((data)<<6))
#define MSD_FLAGS_flag_4_72(data)                                     (0x00000020&((data)<<5))
#define MSD_FLAGS_flag_5_74(data)                                     (0x00000010&((data)<<4))
#define MSD_FLAGS_flag_5_85(data)                                     (0x00000008&((data)<<3))
#define MSD_FLAGS_flag_6_25(data)                                     (0x00000004&((data)<<2))
#define MSD_FLAGS_flag_6_552(data)                                    (0x00000002&((data)<<1))
#define MSD_FLAGS_flag_6_74(data)                                     (0x00000001&(data))
#define MSD_FLAGS_get_flag_fw_4(data)                                 ((0x00004000&(data))>>14)
#define MSD_FLAGS_get_flag_fw_3(data)                                 ((0x00002000&(data))>>13)
#define MSD_FLAGS_get_flag_fw_2(data)                                 ((0x00001000&(data))>>12)
#define MSD_FLAGS_get_flag_fw_1(data)                                 ((0x00000800&(data))>>11)
#define MSD_FLAGS_get_flag_fw(data)                                   ((0x00000400&(data))>>10)
#define MSD_FLAGS_get_flag_4_5(data)                                  ((0x00000200&(data))>>9)
#define MSD_FLAGS_get_flag_5_5(data)                                  ((0x00000100&(data))>>8)
#define MSD_FLAGS_get_flag_6(data)                                    ((0x00000080&(data))>>7)
#define MSD_FLAGS_get_flag_6_5(data)                                  ((0x00000040&(data))>>6)
#define MSD_FLAGS_get_flag_4_72(data)                                 ((0x00000020&(data))>>5)
#define MSD_FLAGS_get_flag_5_74(data)                                 ((0x00000010&(data))>>4)
#define MSD_FLAGS_get_flag_5_85(data)                                 ((0x00000008&(data))>>3)
#define MSD_FLAGS_get_flag_6_25(data)                                 ((0x00000004&(data))>>2)
#define MSD_FLAGS_get_flag_6_552(data)                                ((0x00000002&(data))>>1)
#define MSD_FLAGS_get_flag_6_74(data)                                 (0x00000001&(data))


#define MSD_PROGRAMMABLE_FREQ                                         0x18006254
#define MSD_PROGRAMMABLE_FREQ_reg_addr                                "0xb8006254"
#define MSD_PROGRAMMABLE_FREQ_reg                                     0xb8006254
#define MSD_PROGRAMMABLE_FREQ_inst_addr                               "0x0095"
#define MSD_PROGRAMMABLE_FREQ_inst                                    0x0095
#define MSD_PROGRAMMABLE_FREQ_fw_phase_delta_shift                    (16)
#define MSD_PROGRAMMABLE_FREQ_reg_mag_fw_shift                        (0)
#define MSD_PROGRAMMABLE_FREQ_fw_phase_delta_mask                     (0x3FFF0000)
#define MSD_PROGRAMMABLE_FREQ_reg_mag_fw_mask                         (0x0000FFFF)
#define MSD_PROGRAMMABLE_FREQ_fw_phase_delta(data)                    (0x3FFF0000&((data)<<16))
#define MSD_PROGRAMMABLE_FREQ_reg_mag_fw(data)                        (0x0000FFFF&(data))
#define MSD_PROGRAMMABLE_FREQ_get_fw_phase_delta(data)                ((0x3FFF0000&(data))>>16)
#define MSD_PROGRAMMABLE_FREQ_get_reg_mag_fw(data)                    (0x0000FFFF&(data))


#define THRESHOLD_MSD_CARRIER_FW                                      0x18006258
#define THRESHOLD_MSD_CARRIER_FW_reg_addr                             "0xb8006258"
#define THRESHOLD_MSD_CARRIER_FW_reg                                  0xb8006258
#define THRESHOLD_MSD_CARRIER_FW_inst_addr                            "0x0096"
#define THRESHOLD_MSD_CARRIER_FW_inst                                 0x0096
#define THRESHOLD_MSD_CARRIER_FW_fw_thresh_shift                      (16)
#define THRESHOLD_MSD_CARRIER_FW_fw_thresh_low_shift                  (0)
#define THRESHOLD_MSD_CARRIER_FW_fw_thresh_mask                       (0xFFFF0000)
#define THRESHOLD_MSD_CARRIER_FW_fw_thresh_low_mask                   (0x0000FFFF)
#define THRESHOLD_MSD_CARRIER_FW_fw_thresh(data)                      (0xFFFF0000&((data)<<16))
#define THRESHOLD_MSD_CARRIER_FW_fw_thresh_low(data)                  (0x0000FFFF&(data))
#define THRESHOLD_MSD_CARRIER_FW_get_fw_thresh(data)                  ((0xFFFF0000&(data))>>16)
#define THRESHOLD_MSD_CARRIER_FW_get_fw_thresh_low(data)              (0x0000FFFF&(data))


#define MSD_PROGRAMMABLE_FREQ_1                                       0x1800625c
#define MSD_PROGRAMMABLE_FREQ_1_reg_addr                              "0xb800625c"
#define MSD_PROGRAMMABLE_FREQ_1_reg                                   0xb800625c
#define MSD_PROGRAMMABLE_FREQ_1_inst_addr                             "0x0097"
#define MSD_PROGRAMMABLE_FREQ_1_inst                                  0x0097
#define MSD_PROGRAMMABLE_FREQ_1_fw_phase_delta_1_shift                (16)
#define MSD_PROGRAMMABLE_FREQ_1_reg_mag_fw_1_shift                    (0)
#define MSD_PROGRAMMABLE_FREQ_1_fw_phase_delta_1_mask                 (0x3FFF0000)
#define MSD_PROGRAMMABLE_FREQ_1_reg_mag_fw_1_mask                     (0x0000FFFF)
#define MSD_PROGRAMMABLE_FREQ_1_fw_phase_delta_1(data)                (0x3FFF0000&((data)<<16))
#define MSD_PROGRAMMABLE_FREQ_1_reg_mag_fw_1(data)                    (0x0000FFFF&(data))
#define MSD_PROGRAMMABLE_FREQ_1_get_fw_phase_delta_1(data)            ((0x3FFF0000&(data))>>16)
#define MSD_PROGRAMMABLE_FREQ_1_get_reg_mag_fw_1(data)                (0x0000FFFF&(data))


#define THRESHOLD_MSD_CARRIER_FW_1                                    0x18006260
#define THRESHOLD_MSD_CARRIER_FW_1_reg_addr                           "0xb8006260"
#define THRESHOLD_MSD_CARRIER_FW_1_reg                                0xb8006260
#define THRESHOLD_MSD_CARRIER_FW_1_inst_addr                          "0x0098"
#define THRESHOLD_MSD_CARRIER_FW_1_inst                               0x0098
#define THRESHOLD_MSD_CARRIER_FW_1_fw_thresh_1_shift                  (16)
#define THRESHOLD_MSD_CARRIER_FW_1_fw_thresh_1_low_shift              (0)
#define THRESHOLD_MSD_CARRIER_FW_1_fw_thresh_1_mask                   (0xFFFF0000)
#define THRESHOLD_MSD_CARRIER_FW_1_fw_thresh_1_low_mask               (0x0000FFFF)
#define THRESHOLD_MSD_CARRIER_FW_1_fw_thresh_1(data)                  (0xFFFF0000&((data)<<16))
#define THRESHOLD_MSD_CARRIER_FW_1_fw_thresh_1_low(data)              (0x0000FFFF&(data))
#define THRESHOLD_MSD_CARRIER_FW_1_get_fw_thresh_1(data)              ((0xFFFF0000&(data))>>16)
#define THRESHOLD_MSD_CARRIER_FW_1_get_fw_thresh_1_low(data)          (0x0000FFFF&(data))


#define MSD_PROGRAMMABLE_FREQ_2                                       0x18006264
#define MSD_PROGRAMMABLE_FREQ_2_reg_addr                              "0xb8006264"
#define MSD_PROGRAMMABLE_FREQ_2_reg                                   0xb8006264
#define MSD_PROGRAMMABLE_FREQ_2_inst_addr                             "0x0099"
#define MSD_PROGRAMMABLE_FREQ_2_inst                                  0x0099
#define MSD_PROGRAMMABLE_FREQ_2_fw_phase_delta_2_shift                (16)
#define MSD_PROGRAMMABLE_FREQ_2_reg_mag_fw_2_shift                    (0)
#define MSD_PROGRAMMABLE_FREQ_2_fw_phase_delta_2_mask                 (0x3FFF0000)
#define MSD_PROGRAMMABLE_FREQ_2_reg_mag_fw_2_mask                     (0x0000FFFF)
#define MSD_PROGRAMMABLE_FREQ_2_fw_phase_delta_2(data)                (0x3FFF0000&((data)<<16))
#define MSD_PROGRAMMABLE_FREQ_2_reg_mag_fw_2(data)                    (0x0000FFFF&(data))
#define MSD_PROGRAMMABLE_FREQ_2_get_fw_phase_delta_2(data)            ((0x3FFF0000&(data))>>16)
#define MSD_PROGRAMMABLE_FREQ_2_get_reg_mag_fw_2(data)                (0x0000FFFF&(data))


#define THRESHOLD_MSD_CARRIER_FW_2                                    0x18006268
#define THRESHOLD_MSD_CARRIER_FW_2_reg_addr                           "0xb8006268"
#define THRESHOLD_MSD_CARRIER_FW_2_reg                                0xb8006268
#define THRESHOLD_MSD_CARRIER_FW_2_inst_addr                          "0x009A"
#define THRESHOLD_MSD_CARRIER_FW_2_inst                               0x009A
#define THRESHOLD_MSD_CARRIER_FW_2_fw_thresh_2_shift                  (16)
#define THRESHOLD_MSD_CARRIER_FW_2_fw_thresh_2_low_shift              (0)
#define THRESHOLD_MSD_CARRIER_FW_2_fw_thresh_2_mask                   (0xFFFF0000)
#define THRESHOLD_MSD_CARRIER_FW_2_fw_thresh_2_low_mask               (0x0000FFFF)
#define THRESHOLD_MSD_CARRIER_FW_2_fw_thresh_2(data)                  (0xFFFF0000&((data)<<16))
#define THRESHOLD_MSD_CARRIER_FW_2_fw_thresh_2_low(data)              (0x0000FFFF&(data))
#define THRESHOLD_MSD_CARRIER_FW_2_get_fw_thresh_2(data)              ((0xFFFF0000&(data))>>16)
#define THRESHOLD_MSD_CARRIER_FW_2_get_fw_thresh_2_low(data)          (0x0000FFFF&(data))


#define MSD_PROGRAMMABLE_FREQ_3                                       0x1800626c
#define MSD_PROGRAMMABLE_FREQ_3_reg_addr                              "0xb800626c"
#define MSD_PROGRAMMABLE_FREQ_3_reg                                   0xb800626c
#define MSD_PROGRAMMABLE_FREQ_3_inst_addr                             "0x009B"
#define MSD_PROGRAMMABLE_FREQ_3_inst                                  0x009B
#define MSD_PROGRAMMABLE_FREQ_3_fw_phase_delta_3_shift                (16)
#define MSD_PROGRAMMABLE_FREQ_3_reg_mag_fw_3_shift                    (0)
#define MSD_PROGRAMMABLE_FREQ_3_fw_phase_delta_3_mask                 (0x3FFF0000)
#define MSD_PROGRAMMABLE_FREQ_3_reg_mag_fw_3_mask                     (0x0000FFFF)
#define MSD_PROGRAMMABLE_FREQ_3_fw_phase_delta_3(data)                (0x3FFF0000&((data)<<16))
#define MSD_PROGRAMMABLE_FREQ_3_reg_mag_fw_3(data)                    (0x0000FFFF&(data))
#define MSD_PROGRAMMABLE_FREQ_3_get_fw_phase_delta_3(data)            ((0x3FFF0000&(data))>>16)
#define MSD_PROGRAMMABLE_FREQ_3_get_reg_mag_fw_3(data)                (0x0000FFFF&(data))


#define THRESHOLD_MSD_CARRIER_FW_3                                    0x18006270
#define THRESHOLD_MSD_CARRIER_FW_3_reg_addr                           "0xb8006270"
#define THRESHOLD_MSD_CARRIER_FW_3_reg                                0xb8006270
#define THRESHOLD_MSD_CARRIER_FW_3_inst_addr                          "0x009C"
#define THRESHOLD_MSD_CARRIER_FW_3_inst                               0x009C
#define THRESHOLD_MSD_CARRIER_FW_3_fw_thresh_3_shift                  (16)
#define THRESHOLD_MSD_CARRIER_FW_3_fw_thresh_3_low_shift              (0)
#define THRESHOLD_MSD_CARRIER_FW_3_fw_thresh_3_mask                   (0xFFFF0000)
#define THRESHOLD_MSD_CARRIER_FW_3_fw_thresh_3_low_mask               (0x0000FFFF)
#define THRESHOLD_MSD_CARRIER_FW_3_fw_thresh_3(data)                  (0xFFFF0000&((data)<<16))
#define THRESHOLD_MSD_CARRIER_FW_3_fw_thresh_3_low(data)              (0x0000FFFF&(data))
#define THRESHOLD_MSD_CARRIER_FW_3_get_fw_thresh_3(data)              ((0xFFFF0000&(data))>>16)
#define THRESHOLD_MSD_CARRIER_FW_3_get_fw_thresh_3_low(data)          (0x0000FFFF&(data))


#define MSD_PROGRAMMABLE_FREQ_4                                       0x18006274
#define MSD_PROGRAMMABLE_FREQ_4_reg_addr                              "0xb8006274"
#define MSD_PROGRAMMABLE_FREQ_4_reg                                   0xb8006274
#define MSD_PROGRAMMABLE_FREQ_4_inst_addr                             "0x009D"
#define MSD_PROGRAMMABLE_FREQ_4_inst                                  0x009D
#define MSD_PROGRAMMABLE_FREQ_4_fw_phase_delta_4_shift                (16)
#define MSD_PROGRAMMABLE_FREQ_4_reg_mag_fw_4_shift                    (0)
#define MSD_PROGRAMMABLE_FREQ_4_fw_phase_delta_4_mask                 (0x3FFF0000)
#define MSD_PROGRAMMABLE_FREQ_4_reg_mag_fw_4_mask                     (0x0000FFFF)
#define MSD_PROGRAMMABLE_FREQ_4_fw_phase_delta_4(data)                (0x3FFF0000&((data)<<16))
#define MSD_PROGRAMMABLE_FREQ_4_reg_mag_fw_4(data)                    (0x0000FFFF&(data))
#define MSD_PROGRAMMABLE_FREQ_4_get_fw_phase_delta_4(data)            ((0x3FFF0000&(data))>>16)
#define MSD_PROGRAMMABLE_FREQ_4_get_reg_mag_fw_4(data)                (0x0000FFFF&(data))


#define THRESHOLD_MSD_CARRIER_FW_4                                    0x18006278
#define THRESHOLD_MSD_CARRIER_FW_4_reg_addr                           "0xb8006278"
#define THRESHOLD_MSD_CARRIER_FW_4_reg                                0xb8006278
#define THRESHOLD_MSD_CARRIER_FW_4_inst_addr                          "0x009E"
#define THRESHOLD_MSD_CARRIER_FW_4_inst                               0x009E
#define THRESHOLD_MSD_CARRIER_FW_4_fw_thresh_4_shift                  (16)
#define THRESHOLD_MSD_CARRIER_FW_4_fw_thresh_4_low_shift              (0)
#define THRESHOLD_MSD_CARRIER_FW_4_fw_thresh_4_mask                   (0xFFFF0000)
#define THRESHOLD_MSD_CARRIER_FW_4_fw_thresh_4_low_mask               (0x0000FFFF)
#define THRESHOLD_MSD_CARRIER_FW_4_fw_thresh_4(data)                  (0xFFFF0000&((data)<<16))
#define THRESHOLD_MSD_CARRIER_FW_4_fw_thresh_4_low(data)              (0x0000FFFF&(data))
#define THRESHOLD_MSD_CARRIER_FW_4_get_fw_thresh_4(data)              ((0xFFFF0000&(data))>>16)
#define THRESHOLD_MSD_CARRIER_FW_4_get_fw_thresh_4_low(data)          (0x0000FFFF&(data))


#define MSD_SECOND_REG_STD                                            0x1800627c
#define MSD_SECOND_REG_STD_reg_addr                                   "0xb800627c"
#define MSD_SECOND_REG_STD_reg                                        0xb800627c
#define MSD_SECOND_REG_STD_inst_addr                                  "0x009F"
#define MSD_SECOND_REG_STD_inst                                       0x009F
#define MSD_SECOND_REG_STD_reg_cari_sft_detect_en_shift               (10)
#define MSD_SECOND_REG_STD_reg_bw_detect_en_shift                     (9)
#define MSD_SECOND_REG_STD_mono_std_sel_shift                         (8)
#define MSD_SECOND_REG_STD_second_reg_std_shift                       (0)
#define MSD_SECOND_REG_STD_reg_cari_sft_detect_en_mask                (0x00000400)
#define MSD_SECOND_REG_STD_reg_bw_detect_en_mask                      (0x00000200)
#define MSD_SECOND_REG_STD_mono_std_sel_mask                          (0x00000100)
#define MSD_SECOND_REG_STD_second_reg_std_mask                        (0x0000001F)
#define MSD_SECOND_REG_STD_reg_cari_sft_detect_en(data)               (0x00000400&((data)<<10))
#define MSD_SECOND_REG_STD_reg_bw_detect_en(data)                     (0x00000200&((data)<<9))
#define MSD_SECOND_REG_STD_mono_std_sel(data)                         (0x00000100&((data)<<8))
#define MSD_SECOND_REG_STD_second_reg_std(data)                       (0x0000001F&(data))
#define MSD_SECOND_REG_STD_get_reg_cari_sft_detect_en(data)           ((0x00000400&(data))>>10)
#define MSD_SECOND_REG_STD_get_reg_bw_detect_en(data)                 ((0x00000200&(data))>>9)
#define MSD_SECOND_REG_STD_get_mono_std_sel(data)                     ((0x00000100&(data))>>8)
#define MSD_SECOND_REG_STD_get_second_reg_std(data)                   (0x0000001F&(data))


#define SECOND_MAIN_TONE_THRESHOLD                                    0x18006280
#define SECOND_MAIN_TONE_THRESHOLD_reg_addr                           "0xb8006280"
#define SECOND_MAIN_TONE_THRESHOLD_reg                                0xb8006280
#define SECOND_MAIN_TONE_THRESHOLD_inst_addr                          "0x00A0"
#define SECOND_MAIN_TONE_THRESHOLD_inst                               0x00A0
#define SECOND_MAIN_TONE_THRESHOLD_sec_thresh_shift                   (16)
#define SECOND_MAIN_TONE_THRESHOLD_sec_thresh_low_shift               (0)
#define SECOND_MAIN_TONE_THRESHOLD_sec_thresh_mask                    (0xFFFF0000)
#define SECOND_MAIN_TONE_THRESHOLD_sec_thresh_low_mask                (0x0000FFFF)
#define SECOND_MAIN_TONE_THRESHOLD_sec_thresh(data)                   (0xFFFF0000&((data)<<16))
#define SECOND_MAIN_TONE_THRESHOLD_sec_thresh_low(data)               (0x0000FFFF&(data))
#define SECOND_MAIN_TONE_THRESHOLD_get_sec_thresh(data)               ((0xFFFF0000&(data))>>16)
#define SECOND_MAIN_TONE_THRESHOLD_get_sec_thresh_low(data)           (0x0000FFFF&(data))


#define MSD_BIST                                                      0x18006284
#define MSD_BIST_reg_addr                                             "0xb8006284"
#define MSD_BIST_reg                                                  0xb8006284
#define MSD_BIST_inst_addr                                            "0x00A1"
#define MSD_BIST_inst                                                 0x00A1
#define MSD_BIST_dvse_0_msd_shift                                     (13)
#define MSD_BIST_dvs_0_msd_shift                                      (9)
#define MSD_BIST_drf_start_pause_msd_shift                            (8)
#define MSD_BIST_drf_test_resume_msd_shift                            (7)
#define MSD_BIST_drf_bist_mode_msd_shift                              (6)
#define MSD_BIST_drf_bist_done_msd_shift                              (5)
#define MSD_BIST_drf_bist_fail_msd_shift                              (4)
#define MSD_BIST_bist_rstn_msd_shift                                  (3)
#define MSD_BIST_bist_mode_msd_shift                                  (2)
#define MSD_BIST_bist_done_msd_shift                                  (1)
#define MSD_BIST_bist_fail_msd_shift                                  (0)
#define MSD_BIST_dvse_0_msd_mask                                      (0x00002000)
#define MSD_BIST_dvs_0_msd_mask                                       (0x00001E00)
#define MSD_BIST_drf_start_pause_msd_mask                             (0x00000100)
#define MSD_BIST_drf_test_resume_msd_mask                             (0x00000080)
#define MSD_BIST_drf_bist_mode_msd_mask                               (0x00000040)
#define MSD_BIST_drf_bist_done_msd_mask                               (0x00000020)
#define MSD_BIST_drf_bist_fail_msd_mask                               (0x00000010)
#define MSD_BIST_bist_rstn_msd_mask                                   (0x00000008)
#define MSD_BIST_bist_mode_msd_mask                                   (0x00000004)
#define MSD_BIST_bist_done_msd_mask                                   (0x00000002)
#define MSD_BIST_bist_fail_msd_mask                                   (0x00000001)
#define MSD_BIST_dvse_0_msd(data)                                     (0x00002000&((data)<<13))
#define MSD_BIST_dvs_0_msd(data)                                      (0x00001E00&((data)<<9))
#define MSD_BIST_drf_start_pause_msd(data)                            (0x00000100&((data)<<8))
#define MSD_BIST_drf_test_resume_msd(data)                            (0x00000080&((data)<<7))
#define MSD_BIST_drf_bist_mode_msd(data)                              (0x00000040&((data)<<6))
#define MSD_BIST_drf_bist_done_msd(data)                              (0x00000020&((data)<<5))
#define MSD_BIST_drf_bist_fail_msd(data)                              (0x00000010&((data)<<4))
#define MSD_BIST_bist_rstn_msd(data)                                  (0x00000008&((data)<<3))
#define MSD_BIST_bist_mode_msd(data)                                  (0x00000004&((data)<<2))
#define MSD_BIST_bist_done_msd(data)                                  (0x00000002&((data)<<1))
#define MSD_BIST_bist_fail_msd(data)                                  (0x00000001&(data))
#define MSD_BIST_get_dvse_0_msd(data)                                 ((0x00002000&(data))>>13)
#define MSD_BIST_get_dvs_0_msd(data)                                  ((0x00001E00&(data))>>9)
#define MSD_BIST_get_drf_start_pause_msd(data)                        ((0x00000100&(data))>>8)
#define MSD_BIST_get_drf_test_resume_msd(data)                        ((0x00000080&(data))>>7)
#define MSD_BIST_get_drf_bist_mode_msd(data)                          ((0x00000040&(data))>>6)
#define MSD_BIST_get_drf_bist_done_msd(data)                          ((0x00000020&(data))>>5)
#define MSD_BIST_get_drf_bist_fail_msd(data)                          ((0x00000010&(data))>>4)
#define MSD_BIST_get_bist_rstn_msd(data)                              ((0x00000008&(data))>>3)
#define MSD_BIST_get_bist_mode_msd(data)                              ((0x00000004&(data))>>2)
#define MSD_BIST_get_bist_done_msd(data)                              ((0x00000002&(data))>>1)
#define MSD_BIST_get_bist_fail_msd(data)                              (0x00000001&(data))


#define MSD_MAIN_MAG_ORI1                                             0x18006288
#define MSD_MAIN_MAG_ORI1_reg_addr                                    "0xb8006288"
#define MSD_MAIN_MAG_ORI1_reg                                         0xb8006288
#define MSD_MAIN_MAG_ORI1_inst_addr                                   "0x00A2"
#define MSD_MAIN_MAG_ORI1_inst                                        0x00A2
#define MSD_MAIN_MAG_ORI1_reg_mag_45_fix_shift                        (16)
#define MSD_MAIN_MAG_ORI1_reg_mag_55_fix_shift                        (0)
#define MSD_MAIN_MAG_ORI1_reg_mag_45_fix_mask                         (0xFFFF0000)
#define MSD_MAIN_MAG_ORI1_reg_mag_55_fix_mask                         (0x0000FFFF)
#define MSD_MAIN_MAG_ORI1_reg_mag_45_fix(data)                        (0xFFFF0000&((data)<<16))
#define MSD_MAIN_MAG_ORI1_reg_mag_55_fix(data)                        (0x0000FFFF&(data))
#define MSD_MAIN_MAG_ORI1_get_reg_mag_45_fix(data)                    ((0xFFFF0000&(data))>>16)
#define MSD_MAIN_MAG_ORI1_get_reg_mag_55_fix(data)                    (0x0000FFFF&(data))


#define MSD_MAIN_MAG_ORI2                                             0x1800628c
#define MSD_MAIN_MAG_ORI2_reg_addr                                    "0xb800628c"
#define MSD_MAIN_MAG_ORI2_reg                                         0xb800628c
#define MSD_MAIN_MAG_ORI2_inst_addr                                   "0x00A3"
#define MSD_MAIN_MAG_ORI2_inst                                        0x00A3
#define MSD_MAIN_MAG_ORI2_reg_mag_60_fix_shift                        (16)
#define MSD_MAIN_MAG_ORI2_reg_mag_65_fix_shift                        (0)
#define MSD_MAIN_MAG_ORI2_reg_mag_60_fix_mask                         (0xFFFF0000)
#define MSD_MAIN_MAG_ORI2_reg_mag_65_fix_mask                         (0x0000FFFF)
#define MSD_MAIN_MAG_ORI2_reg_mag_60_fix(data)                        (0xFFFF0000&((data)<<16))
#define MSD_MAIN_MAG_ORI2_reg_mag_65_fix(data)                        (0x0000FFFF&(data))
#define MSD_MAIN_MAG_ORI2_get_reg_mag_60_fix(data)                    ((0xFFFF0000&(data))>>16)
#define MSD_MAIN_MAG_ORI2_get_reg_mag_65_fix(data)                    (0x0000FFFF&(data))


#define MSD_GAIN_CTRL                                                 0x18006290
#define MSD_GAIN_CTRL_reg_addr                                        "0xb8006290"
#define MSD_GAIN_CTRL_reg                                             0xb8006290
#define MSD_GAIN_CTRL_inst_addr                                       "0x00A4"
#define MSD_GAIN_CTRL_inst                                            0x00A4
#define MSD_GAIN_CTRL_msd_gain_en_shift                               (4)
#define MSD_GAIN_CTRL_msd_gain_result_shift                           (0)
#define MSD_GAIN_CTRL_msd_gain_en_mask                                (0x00000010)
#define MSD_GAIN_CTRL_msd_gain_result_mask                            (0x0000000F)
#define MSD_GAIN_CTRL_msd_gain_en(data)                               (0x00000010&((data)<<4))
#define MSD_GAIN_CTRL_msd_gain_result(data)                           (0x0000000F&(data))
#define MSD_GAIN_CTRL_get_msd_gain_en(data)                           ((0x00000010&(data))>>4)
#define MSD_GAIN_CTRL_get_msd_gain_result(data)                       (0x0000000F&(data))


#define MSD_UPDATE_COUNT                                              0x18006294
#define MSD_UPDATE_COUNT_reg_addr                                     "0xb8006294"
#define MSD_UPDATE_COUNT_reg                                          0xb8006294
#define MSD_UPDATE_COUNT_inst_addr                                    "0x00A5"
#define MSD_UPDATE_COUNT_inst                                         0x00A5
#define MSD_UPDATE_COUNT_dummy18006294_31_16_shift                    (16)
#define MSD_UPDATE_COUNT_msd_update_count_shift                       (0)
#define MSD_UPDATE_COUNT_dummy18006294_31_16_mask                     (0xFFFF0000)
#define MSD_UPDATE_COUNT_msd_update_count_mask                        (0x0000FFFF)
#define MSD_UPDATE_COUNT_dummy18006294_31_16(data)                    (0xFFFF0000&((data)<<16))
#define MSD_UPDATE_COUNT_msd_update_count(data)                       (0x0000FFFF&(data))
#define MSD_UPDATE_COUNT_get_dummy18006294_31_16(data)                ((0xFFFF0000&(data))>>16)
#define MSD_UPDATE_COUNT_get_msd_update_count(data)                   (0x0000FFFF&(data))


#define MODE_DETECT                                                   0x18006300
#define MODE_DETECT_reg_addr                                          "0xb8006300"
#define MODE_DETECT_reg                                               0xb8006300
#define MODE_DETECT_inst_addr                                         "0x00C0"
#define MODE_DETECT_inst                                              0x00C0
#define MODE_DETECT_md_update_count_shift                             (16)
#define MODE_DETECT_hw_mode_en_shift                                  (2)
#define MODE_DETECT_mode_result_shift                                 (0)
#define MODE_DETECT_md_update_count_mask                              (0xFFFF0000)
#define MODE_DETECT_hw_mode_en_mask                                   (0x00000004)
#define MODE_DETECT_mode_result_mask                                  (0x00000003)
#define MODE_DETECT_md_update_count(data)                             (0xFFFF0000&((data)<<16))
#define MODE_DETECT_hw_mode_en(data)                                  (0x00000004&((data)<<2))
#define MODE_DETECT_mode_result(data)                                 (0x00000003&(data))
#define MODE_DETECT_get_md_update_count(data)                         ((0xFFFF0000&(data))>>16)
#define MODE_DETECT_get_hw_mode_en(data)                              ((0x00000004&(data))>>2)
#define MODE_DETECT_get_mode_result(data)                             (0x00000003&(data))


#define MD_CTRL                                                       0x18006304
#define MD_CTRL_reg_addr                                              "0xb8006304"
#define MD_CTRL_reg                                                   0xb8006304
#define MD_CTRL_inst_addr                                             "0x00C1"
#define MD_CTRL_inst                                                  0x00C1
#define MD_CTRL_enable_shift                                          (31)
#define MD_CTRL_accu_num_shift                                        (28)
#define MD_CTRL_high_threshold_shift                                  (26)
#define MD_CTRL_low_threshold_shift                                   (24)
#define MD_CTRL_debounce_cnt_shift                                    (20)
#define MD_CTRL_max_threshold_shift                                   (0)
#define MD_CTRL_enable_mask                                           (0x80000000)
#define MD_CTRL_accu_num_mask                                         (0x70000000)
#define MD_CTRL_high_threshold_mask                                   (0x0C000000)
#define MD_CTRL_low_threshold_mask                                    (0x03000000)
#define MD_CTRL_debounce_cnt_mask                                     (0x00700000)
#define MD_CTRL_max_threshold_mask                                    (0x0000FFFF)
#define MD_CTRL_enable(data)                                          (0x80000000&((data)<<31))
#define MD_CTRL_accu_num(data)                                        (0x70000000&((data)<<28))
#define MD_CTRL_high_threshold(data)                                  (0x0C000000&((data)<<26))
#define MD_CTRL_low_threshold(data)                                   (0x03000000&((data)<<24))
#define MD_CTRL_debounce_cnt(data)                                    (0x00700000&((data)<<20))
#define MD_CTRL_max_threshold(data)                                   (0x0000FFFF&(data))
#define MD_CTRL_get_enable(data)                                      ((0x80000000&(data))>>31)
#define MD_CTRL_get_accu_num(data)                                    ((0x70000000&(data))>>28)
#define MD_CTRL_get_high_threshold(data)                              ((0x0C000000&(data))>>26)
#define MD_CTRL_get_low_threshold(data)                               ((0x03000000&(data))>>24)
#define MD_CTRL_get_debounce_cnt(data)                                ((0x00700000&(data))>>20)
#define MD_CTRL_get_max_threshold(data)                               (0x0000FFFF&(data))


#define MD_STATUS_1                                                   0x18006308
#define MD_STATUS_1_reg_addr                                          "0xb8006308"
#define MD_STATUS_1_reg                                               0xb8006308
#define MD_STATUS_1_inst_addr                                         "0x00C2"
#define MD_STATUS_1_inst                                              0x00C2
#define MD_STATUS_1_max_other_shift                                   (16)
#define MD_STATUS_1_dummy18006308_15_8_shift                          (8)
#define MD_STATUS_1_gain_result_shift                                 (4)
#define MD_STATUS_1_mode_result_shift                                 (0)
#define MD_STATUS_1_max_other_mask                                    (0xFFFF0000)
#define MD_STATUS_1_dummy18006308_15_8_mask                           (0x0000FF00)
#define MD_STATUS_1_gain_result_mask                                  (0x000000F0)
#define MD_STATUS_1_mode_result_mask                                  (0x00000003)
#define MD_STATUS_1_max_other(data)                                   (0xFFFF0000&((data)<<16))
#define MD_STATUS_1_dummy18006308_15_8(data)                          (0x0000FF00&((data)<<8))
#define MD_STATUS_1_gain_result(data)                                 (0x000000F0&((data)<<4))
#define MD_STATUS_1_mode_result(data)                                 (0x00000003&(data))
#define MD_STATUS_1_get_max_other(data)                               ((0xFFFF0000&(data))>>16)
#define MD_STATUS_1_get_dummy18006308_15_8(data)                      ((0x0000FF00&(data))>>8)
#define MD_STATUS_1_get_gain_result(data)                             ((0x000000F0&(data))>>4)
#define MD_STATUS_1_get_mode_result(data)                             (0x00000003&(data))


#define MD_STATUS_2                                                   0x1800630c
#define MD_STATUS_2_reg_addr                                          "0xb800630c"
#define MD_STATUS_2_reg                                               0xb800630c
#define MD_STATUS_2_inst_addr                                         "0x00C3"
#define MD_STATUS_2_inst                                              0x00C3
#define MD_STATUS_2_max_stereo_shift                                  (16)
#define MD_STATUS_2_max_dual_shift                                    (0)
#define MD_STATUS_2_max_stereo_mask                                   (0xFFFF0000)
#define MD_STATUS_2_max_dual_mask                                     (0x0000FFFF)
#define MD_STATUS_2_max_stereo(data)                                  (0xFFFF0000&((data)<<16))
#define MD_STATUS_2_max_dual(data)                                    (0x0000FFFF&(data))
#define MD_STATUS_2_get_max_stereo(data)                              ((0xFFFF0000&(data))>>16)
#define MD_STATUS_2_get_max_dual(data)                                (0x0000FFFF&(data))


#define MBIST_MD                                                      0x18006310
#define MBIST_MD_reg_addr                                             "0xb8006310"
#define MBIST_MD_reg                                                  0xb8006310
#define MBIST_MD_inst_addr                                            "0x00C4"
#define MBIST_MD_inst                                                 0x00C4
#define MBIST_MD_rst_n_shift                                          (31)
#define MBIST_MD_enable_shift                                         (30)
#define MBIST_MD_done_shift                                           (29)
#define MBIST_MD_dvse_0_md_shift                                      (28)
#define MBIST_MD_dvs_0_md_shift                                       (24)
#define MBIST_MD_drf_start_pause_md_shift                             (23)
#define MBIST_MD_drf_test_resume_md_shift                             (22)
#define MBIST_MD_drf_bist_mode_md_shift                               (21)
#define MBIST_MD_drf_bist_done_md_shift                               (20)
#define MBIST_MD_drf_bist_fail_52x16_md_shift                         (19)
#define MBIST_MD_drf_bist_fail_51x16_md_shift                         (18)
#define MBIST_MD_fail_52x16_shift                                     (1)
#define MBIST_MD_fail_51x16_shift                                     (0)
#define MBIST_MD_rst_n_mask                                           (0x80000000)
#define MBIST_MD_enable_mask                                          (0x40000000)
#define MBIST_MD_done_mask                                            (0x20000000)
#define MBIST_MD_dvse_0_md_mask                                       (0x10000000)
#define MBIST_MD_dvs_0_md_mask                                        (0x0F000000)
#define MBIST_MD_drf_start_pause_md_mask                              (0x00800000)
#define MBIST_MD_drf_test_resume_md_mask                              (0x00400000)
#define MBIST_MD_drf_bist_mode_md_mask                                (0x00200000)
#define MBIST_MD_drf_bist_done_md_mask                                (0x00100000)
#define MBIST_MD_drf_bist_fail_52x16_md_mask                          (0x00080000)
#define MBIST_MD_drf_bist_fail_51x16_md_mask                          (0x00040000)
#define MBIST_MD_fail_52x16_mask                                      (0x00000002)
#define MBIST_MD_fail_51x16_mask                                      (0x00000001)
#define MBIST_MD_rst_n(data)                                          (0x80000000&((data)<<31))
#define MBIST_MD_enable(data)                                         (0x40000000&((data)<<30))
#define MBIST_MD_done(data)                                           (0x20000000&((data)<<29))
#define MBIST_MD_dvse_0_md(data)                                      (0x10000000&((data)<<28))
#define MBIST_MD_dvs_0_md(data)                                       (0x0F000000&((data)<<24))
#define MBIST_MD_drf_start_pause_md(data)                             (0x00800000&((data)<<23))
#define MBIST_MD_drf_test_resume_md(data)                             (0x00400000&((data)<<22))
#define MBIST_MD_drf_bist_mode_md(data)                               (0x00200000&((data)<<21))
#define MBIST_MD_drf_bist_done_md(data)                               (0x00100000&((data)<<20))
#define MBIST_MD_drf_bist_fail_52x16_md(data)                         (0x00080000&((data)<<19))
#define MBIST_MD_drf_bist_fail_51x16_md(data)                         (0x00040000&((data)<<18))
#define MBIST_MD_fail_52x16(data)                                     (0x00000002&((data)<<1))
#define MBIST_MD_fail_51x16(data)                                     (0x00000001&(data))
#define MBIST_MD_get_rst_n(data)                                      ((0x80000000&(data))>>31)
#define MBIST_MD_get_enable(data)                                     ((0x40000000&(data))>>30)
#define MBIST_MD_get_done(data)                                       ((0x20000000&(data))>>29)
#define MBIST_MD_get_dvse_0_md(data)                                  ((0x10000000&(data))>>28)
#define MBIST_MD_get_dvs_0_md(data)                                   ((0x0F000000&(data))>>24)
#define MBIST_MD_get_drf_start_pause_md(data)                         ((0x00800000&(data))>>23)
#define MBIST_MD_get_drf_test_resume_md(data)                         ((0x00400000&(data))>>22)
#define MBIST_MD_get_drf_bist_mode_md(data)                           ((0x00200000&(data))>>21)
#define MBIST_MD_get_drf_bist_done_md(data)                           ((0x00100000&(data))>>20)
#define MBIST_MD_get_drf_bist_fail_52x16_md(data)                     ((0x00080000&(data))>>19)
#define MBIST_MD_get_drf_bist_fail_51x16_md(data)                     ((0x00040000&(data))>>18)
#define MBIST_MD_get_fail_52x16(data)                                 ((0x00000002&(data))>>1)
#define MBIST_MD_get_fail_51x16(data)                                 (0x00000001&(data))


#define CARRIER_FREQ_DEVIATION_CTRL                                   0x18006350
#define CARRIER_FREQ_DEVIATION_CTRL_reg_addr                          "0xb8006350"
#define CARRIER_FREQ_DEVIATION_CTRL_reg                               0xb8006350
#define CARRIER_FREQ_DEVIATION_CTRL_inst_addr                         "0x00D4"
#define CARRIER_FREQ_DEVIATION_CTRL_inst                              0x00D4
#define CARRIER_FREQ_DEVIATION_CTRL_sif_data_source_shift             (31)
#define CARRIER_FREQ_DEVIATION_CTRL_carrier_freq_correct_en_shift     (0)
#define CARRIER_FREQ_DEVIATION_CTRL_sif_data_source_mask              (0x80000000)
#define CARRIER_FREQ_DEVIATION_CTRL_carrier_freq_correct_en_mask      (0x00000001)
#define CARRIER_FREQ_DEVIATION_CTRL_sif_data_source(data)             (0x80000000&((data)<<31))
#define CARRIER_FREQ_DEVIATION_CTRL_carrier_freq_correct_en(data)     (0x00000001&(data))
#define CARRIER_FREQ_DEVIATION_CTRL_get_sif_data_source(data)         ((0x80000000&(data))>>31)
#define CARRIER_FREQ_DEVIATION_CTRL_get_carrier_freq_correct_en(data) (0x00000001&(data))


#define CARRIER_PHASE_DELTA                                           0x18006354
#define CARRIER_PHASE_DELTA_reg_addr                                  "0xb8006354"
#define CARRIER_PHASE_DELTA_reg                                       0xb8006354
#define CARRIER_PHASE_DELTA_inst_addr                                 "0x00D5"
#define CARRIER_PHASE_DELTA_inst                                      0x00D5
#define CARRIER_PHASE_DELTA_main_phase_delta_shift                    (16)
#define CARRIER_PHASE_DELTA_sub_phase_delta_shift                     (0)
#define CARRIER_PHASE_DELTA_main_phase_delta_mask                     (0x3FFF0000)
#define CARRIER_PHASE_DELTA_sub_phase_delta_mask                      (0x00003FFF)
#define CARRIER_PHASE_DELTA_main_phase_delta(data)                    (0x3FFF0000&((data)<<16))
#define CARRIER_PHASE_DELTA_sub_phase_delta(data)                     (0x00003FFF&(data))
#define CARRIER_PHASE_DELTA_get_main_phase_delta(data)                ((0x3FFF0000&(data))>>16)
#define CARRIER_PHASE_DELTA_get_sub_phase_delta(data)                 (0x00003FFF&(data))


#define AM                                                            0x18006360
#define AM_reg_addr                                                   "0xb8006360"
#define AM_reg                                                        0xb8006360
#define AM_inst_addr                                                  "0x00D8"
#define AM_inst                                                       0x00D8
#define AM_dummy18006360_7_4_shift                                    (4)
#define AM_am_path_sel_shift                                          (2)
#define AM_hw_am_prescale_shift                                       (0)
#define AM_dummy18006360_7_4_mask                                     (0x000000F0)
#define AM_am_path_sel_mask                                           (0x00000004)
#define AM_hw_am_prescale_mask                                        (0x00000003)
#define AM_dummy18006360_7_4(data)                                    (0x000000F0&((data)<<4))
#define AM_am_path_sel(data)                                          (0x00000004&((data)<<2))
#define AM_hw_am_prescale(data)                                       (0x00000003&(data))
#define AM_get_dummy18006360_7_4(data)                                ((0x000000F0&(data))>>4)
#define AM_get_am_path_sel(data)                                      ((0x00000004&(data))>>2)
#define AM_get_hw_am_prescale(data)                                   (0x00000003&(data))


#define BIST_AM                                                       0x18006364
#define BIST_AM_reg_addr                                              "0xb8006364"
#define BIST_AM_reg                                                   0xb8006364
#define BIST_AM_inst_addr                                             "0x00D9"
#define BIST_AM_inst                                                  0x00D9
#define BIST_AM_dvse_0_am_shift                                       (21)
#define BIST_AM_dvs_0_am_shift                                        (17)
#define BIST_AM_drf_start_pause_am_shift                              (16)
#define BIST_AM_drf_test_resume_am_shift                              (15)
#define BIST_AM_drf_bist_mode_am_shift                                (14)
#define BIST_AM_drf_bist_done_am_shift                                (13)
#define BIST_AM_drf_bist_fail_am_shift                                (12)
#define BIST_AM_bist_rstn_am_shift                                    (11)
#define BIST_AM_bist_mode_am_shift                                    (10)
#define BIST_AM_bist_done_am_shift                                    (9)
#define BIST_AM_bist_fail_am_shift                                    (8)
#define BIST_AM_dvse_0_am_mask                                        (0x00200000)
#define BIST_AM_dvs_0_am_mask                                         (0x001E0000)
#define BIST_AM_drf_start_pause_am_mask                               (0x00010000)
#define BIST_AM_drf_test_resume_am_mask                               (0x00008000)
#define BIST_AM_drf_bist_mode_am_mask                                 (0x00004000)
#define BIST_AM_drf_bist_done_am_mask                                 (0x00002000)
#define BIST_AM_drf_bist_fail_am_mask                                 (0x00001000)
#define BIST_AM_bist_rstn_am_mask                                     (0x00000800)
#define BIST_AM_bist_mode_am_mask                                     (0x00000400)
#define BIST_AM_bist_done_am_mask                                     (0x00000200)
#define BIST_AM_bist_fail_am_mask                                     (0x00000100)
#define BIST_AM_dvse_0_am(data)                                       (0x00200000&((data)<<21))
#define BIST_AM_dvs_0_am(data)                                        (0x001E0000&((data)<<17))
#define BIST_AM_drf_start_pause_am(data)                              (0x00010000&((data)<<16))
#define BIST_AM_drf_test_resume_am(data)                              (0x00008000&((data)<<15))
#define BIST_AM_drf_bist_mode_am(data)                                (0x00004000&((data)<<14))
#define BIST_AM_drf_bist_done_am(data)                                (0x00002000&((data)<<13))
#define BIST_AM_drf_bist_fail_am(data)                                (0x00001000&((data)<<12))
#define BIST_AM_bist_rstn_am(data)                                    (0x00000800&((data)<<11))
#define BIST_AM_bist_mode_am(data)                                    (0x00000400&((data)<<10))
#define BIST_AM_bist_done_am(data)                                    (0x00000200&((data)<<9))
#define BIST_AM_bist_fail_am(data)                                    (0x00000100&((data)<<8))
#define BIST_AM_get_dvse_0_am(data)                                   ((0x00200000&(data))>>21)
#define BIST_AM_get_dvs_0_am(data)                                    ((0x001E0000&(data))>>17)
#define BIST_AM_get_drf_start_pause_am(data)                          ((0x00010000&(data))>>16)
#define BIST_AM_get_drf_test_resume_am(data)                          ((0x00008000&(data))>>15)
#define BIST_AM_get_drf_bist_mode_am(data)                            ((0x00004000&(data))>>14)
#define BIST_AM_get_drf_bist_done_am(data)                            ((0x00002000&(data))>>13)
#define BIST_AM_get_drf_bist_fail_am(data)                            ((0x00001000&(data))>>12)
#define BIST_AM_get_bist_rstn_am(data)                                ((0x00000800&(data))>>11)
#define BIST_AM_get_bist_mode_am(data)                                ((0x00000400&(data))>>10)
#define BIST_AM_get_bist_done_am(data)                                ((0x00000200&(data))>>9)
#define BIST_AM_get_bist_fail_am(data)                                ((0x00000100&(data))>>8)


#define BTSC_PILOT_THRES                                              0x18006400
#define BTSC_PILOT_THRES_reg_addr                                     "0xb8006400"
#define BTSC_PILOT_THRES_reg                                          0xb8006400
#define BTSC_PILOT_THRES_inst_addr                                    "0x0100"
#define BTSC_PILOT_THRES_inst                                         0x0100
#define BTSC_PILOT_THRES_lock_reference_shift                         (31)
#define BTSC_PILOT_THRES_pilot_hithresh_shift                         (16)
#define BTSC_PILOT_THRES_pilot_lothresh_shift                         (0)
#define BTSC_PILOT_THRES_lock_reference_mask                          (0x80000000)
#define BTSC_PILOT_THRES_pilot_hithresh_mask                          (0x03FF0000)
#define BTSC_PILOT_THRES_pilot_lothresh_mask                          (0x000003FF)
#define BTSC_PILOT_THRES_lock_reference(data)                         (0x80000000&((data)<<31))
#define BTSC_PILOT_THRES_pilot_hithresh(data)                         (0x03FF0000&((data)<<16))
#define BTSC_PILOT_THRES_pilot_lothresh(data)                         (0x000003FF&(data))
#define BTSC_PILOT_THRES_get_lock_reference(data)                     ((0x80000000&(data))>>31)
#define BTSC_PILOT_THRES_get_pilot_hithresh(data)                     ((0x03FF0000&(data))>>16)
#define BTSC_PILOT_THRES_get_pilot_lothresh(data)                     (0x000003FF&(data))


#define BTSC_PILOT_STATUS                                             0x18006404
#define BTSC_PILOT_STATUS_reg_addr                                    "0xb8006404"
#define BTSC_PILOT_STATUS_reg                                         0xb8006404
#define BTSC_PILOT_STATUS_inst_addr                                   "0x0101"
#define BTSC_PILOT_STATUS_inst                                        0x0101
#define BTSC_PILOT_STATUS_w1pilotpresent_shift                        (16)
#define BTSC_PILOT_STATUS_w1pilotlocked_shift                         (15)
#define BTSC_PILOT_STATUS_pilot_level_pass_shift                      (14)
#define BTSC_PILOT_STATUS_pilot_hi_pass_shift                         (13)
#define BTSC_PILOT_STATUS_pilot_lo_refuse_shift                       (12)
#define BTSC_PILOT_STATUS_w10pilotmagnitude_shift                     (0)
#define BTSC_PILOT_STATUS_w1pilotpresent_mask                         (0x00010000)
#define BTSC_PILOT_STATUS_w1pilotlocked_mask                          (0x00008000)
#define BTSC_PILOT_STATUS_pilot_level_pass_mask                       (0x00004000)
#define BTSC_PILOT_STATUS_pilot_hi_pass_mask                          (0x00002000)
#define BTSC_PILOT_STATUS_pilot_lo_refuse_mask                        (0x00001000)
#define BTSC_PILOT_STATUS_w10pilotmagnitude_mask                      (0x000003FF)
#define BTSC_PILOT_STATUS_w1pilotpresent(data)                        (0x00010000&((data)<<16))
#define BTSC_PILOT_STATUS_w1pilotlocked(data)                         (0x00008000&((data)<<15))
#define BTSC_PILOT_STATUS_pilot_level_pass(data)                      (0x00004000&((data)<<14))
#define BTSC_PILOT_STATUS_pilot_hi_pass(data)                         (0x00002000&((data)<<13))
#define BTSC_PILOT_STATUS_pilot_lo_refuse(data)                       (0x00001000&((data)<<12))
#define BTSC_PILOT_STATUS_w10pilotmagnitude(data)                     (0x000003FF&(data))
#define BTSC_PILOT_STATUS_get_w1pilotpresent(data)                    ((0x00010000&(data))>>16)
#define BTSC_PILOT_STATUS_get_w1pilotlocked(data)                     ((0x00008000&(data))>>15)
#define BTSC_PILOT_STATUS_get_pilot_level_pass(data)                  ((0x00004000&(data))>>14)
#define BTSC_PILOT_STATUS_get_pilot_hi_pass(data)                     ((0x00002000&(data))>>13)
#define BTSC_PILOT_STATUS_get_pilot_lo_refuse(data)                   ((0x00001000&(data))>>12)
#define BTSC_PILOT_STATUS_get_w10pilotmagnitude(data)                 (0x000003FF&(data))


#define BTSC_SAP_THRESH                                               0x18006408
#define BTSC_SAP_THRESH_reg_addr                                      "0xb8006408"
#define BTSC_SAP_THRESH_reg                                           0xb8006408
#define BTSC_SAP_THRESH_inst_addr                                     "0x0102"
#define BTSC_SAP_THRESH_inst                                          0x0102
#define BTSC_SAP_THRESH_sap_hithresh_shift                            (16)
#define BTSC_SAP_THRESH_sap_lothresh_shift                            (0)
#define BTSC_SAP_THRESH_sap_hithresh_mask                             (0x03FF0000)
#define BTSC_SAP_THRESH_sap_lothresh_mask                             (0x000003FF)
#define BTSC_SAP_THRESH_sap_hithresh(data)                            (0x03FF0000&((data)<<16))
#define BTSC_SAP_THRESH_sap_lothresh(data)                            (0x000003FF&(data))
#define BTSC_SAP_THRESH_get_sap_hithresh(data)                        ((0x03FF0000&(data))>>16)
#define BTSC_SAP_THRESH_get_sap_lothresh(data)                        (0x000003FF&(data))


#define BTSC_SAP_NOISE                                                0x1800640c
#define BTSC_SAP_NOISE_reg_addr                                       "0xb800640c"
#define BTSC_SAP_NOISE_reg                                            0xb800640c
#define BTSC_SAP_NOISE_inst_addr                                      "0x0103"
#define BTSC_SAP_NOISE_inst                                           0x0103
#define BTSC_SAP_NOISE_w10sapnoise_shift                              (0)
#define BTSC_SAP_NOISE_w10sapnoise_mask                               (0x000003FF)
#define BTSC_SAP_NOISE_w10sapnoise(data)                              (0x000003FF&(data))
#define BTSC_SAP_NOISE_get_w10sapnoise(data)                          (0x000003FF&(data))


#define BTSC_SAP_NOISE_TH                                             0x18006410
#define BTSC_SAP_NOISE_TH_reg_addr                                    "0xb8006410"
#define BTSC_SAP_NOISE_TH_reg                                         0xb8006410
#define BTSC_SAP_NOISE_TH_inst_addr                                   "0x0104"
#define BTSC_SAP_NOISE_TH_inst                                        0x0104
#define BTSC_SAP_NOISE_TH_sap_noise_hi_thresh_shift                   (16)
#define BTSC_SAP_NOISE_TH_sap_noise_lo_thresh_shift                   (0)
#define BTSC_SAP_NOISE_TH_sap_noise_hi_thresh_mask                    (0x03FF0000)
#define BTSC_SAP_NOISE_TH_sap_noise_lo_thresh_mask                    (0x000003FF)
#define BTSC_SAP_NOISE_TH_sap_noise_hi_thresh(data)                   (0x03FF0000&((data)<<16))
#define BTSC_SAP_NOISE_TH_sap_noise_lo_thresh(data)                   (0x000003FF&(data))
#define BTSC_SAP_NOISE_TH_get_sap_noise_hi_thresh(data)               ((0x03FF0000&(data))>>16)
#define BTSC_SAP_NOISE_TH_get_sap_noise_lo_thresh(data)               (0x000003FF&(data))


#define BTSC_SAP_DEBOUNCE                                             0x18006414
#define BTSC_SAP_DEBOUNCE_reg_addr                                    "0xb8006414"
#define BTSC_SAP_DEBOUNCE_reg                                         0xb8006414
#define BTSC_SAP_DEBOUNCE_inst_addr                                   "0x0105"
#define BTSC_SAP_DEBOUNCE_inst                                        0x0105
#define BTSC_SAP_DEBOUNCE_sap_debounce_en_shift                       (4)
#define BTSC_SAP_DEBOUNCE_sap_debounce_shift                          (0)
#define BTSC_SAP_DEBOUNCE_sap_debounce_en_mask                        (0x00000010)
#define BTSC_SAP_DEBOUNCE_sap_debounce_mask                           (0x0000000F)
#define BTSC_SAP_DEBOUNCE_sap_debounce_en(data)                       (0x00000010&((data)<<4))
#define BTSC_SAP_DEBOUNCE_sap_debounce(data)                          (0x0000000F&(data))
#define BTSC_SAP_DEBOUNCE_get_sap_debounce_en(data)                   ((0x00000010&(data))>>4)
#define BTSC_SAP_DEBOUNCE_get_sap_debounce(data)                      (0x0000000F&(data))


#define BTSC_SAP_STATUS                                               0x18006418
#define BTSC_SAP_STATUS_reg_addr                                      "0xb8006418"
#define BTSC_SAP_STATUS_reg                                           0xb8006418
#define BTSC_SAP_STATUS_inst_addr                                     "0x0106"
#define BTSC_SAP_STATUS_inst                                          0x0106
#define BTSC_SAP_STATUS_w1sapqualitygood_shift                        (14)
#define BTSC_SAP_STATUS_sap_hi_pass_shift                             (13)
#define BTSC_SAP_STATUS_sap_lo_refuse_shift                           (12)
#define BTSC_SAP_STATUS_sap_noise_flag_shift                          (11)
#define BTSC_SAP_STATUS_w10sapmagnitude_shift                         (0)
#define BTSC_SAP_STATUS_w1sapqualitygood_mask                         (0x00004000)
#define BTSC_SAP_STATUS_sap_hi_pass_mask                              (0x00002000)
#define BTSC_SAP_STATUS_sap_lo_refuse_mask                            (0x00001000)
#define BTSC_SAP_STATUS_sap_noise_flag_mask                           (0x00000800)
#define BTSC_SAP_STATUS_w10sapmagnitude_mask                          (0x000003FF)
#define BTSC_SAP_STATUS_w1sapqualitygood(data)                        (0x00004000&((data)<<14))
#define BTSC_SAP_STATUS_sap_hi_pass(data)                             (0x00002000&((data)<<13))
#define BTSC_SAP_STATUS_sap_lo_refuse(data)                           (0x00001000&((data)<<12))
#define BTSC_SAP_STATUS_sap_noise_flag(data)                          (0x00000800&((data)<<11))
#define BTSC_SAP_STATUS_w10sapmagnitude(data)                         (0x000003FF&(data))
#define BTSC_SAP_STATUS_get_w1sapqualitygood(data)                    ((0x00004000&(data))>>14)
#define BTSC_SAP_STATUS_get_sap_hi_pass(data)                         ((0x00002000&(data))>>13)
#define BTSC_SAP_STATUS_get_sap_lo_refuse(data)                       ((0x00001000&(data))>>12)
#define BTSC_SAP_STATUS_get_sap_noise_flag(data)                      ((0x00000800&(data))>>11)
#define BTSC_SAP_STATUS_get_w10sapmagnitude(data)                     (0x000003FF&(data))


#define BTSC_SIF_FM_MAGNITUDE                                         0x1800641c
#define BTSC_SIF_FM_MAGNITUDE_reg_addr                                "0xb800641c"
#define BTSC_SIF_FM_MAGNITUDE_reg                                     0xb800641c
#define BTSC_SIF_FM_MAGNITUDE_inst_addr                               "0x0107"
#define BTSC_SIF_FM_MAGNITUDE_inst                                    0x0107
#define BTSC_SIF_FM_MAGNITUDE_fm_mag_overflow_shift                   (13)
#define BTSC_SIF_FM_MAGNITUDE_fm_mag_optimize_shift                   (12)
#define BTSC_SIF_FM_MAGNITUDE_w10fmmagnitude_shift                    (0)
#define BTSC_SIF_FM_MAGNITUDE_fm_mag_overflow_mask                    (0x00002000)
#define BTSC_SIF_FM_MAGNITUDE_fm_mag_optimize_mask                    (0x00001000)
#define BTSC_SIF_FM_MAGNITUDE_w10fmmagnitude_mask                     (0x000003FF)
#define BTSC_SIF_FM_MAGNITUDE_fm_mag_overflow(data)                   (0x00002000&((data)<<13))
#define BTSC_SIF_FM_MAGNITUDE_fm_mag_optimize(data)                   (0x00001000&((data)<<12))
#define BTSC_SIF_FM_MAGNITUDE_w10fmmagnitude(data)                    (0x000003FF&(data))
#define BTSC_SIF_FM_MAGNITUDE_get_fm_mag_overflow(data)               ((0x00002000&(data))>>13)
#define BTSC_SIF_FM_MAGNITUDE_get_fm_mag_optimize(data)               ((0x00001000&(data))>>12)
#define BTSC_SIF_FM_MAGNITUDE_get_w10fmmagnitude(data)                (0x000003FF&(data))


#define BTSC_TEST_MUX_SEL                                             0x18006420
#define BTSC_TEST_MUX_SEL_reg_addr                                    "0xb8006420"
#define BTSC_TEST_MUX_SEL_reg                                         0xb8006420
#define BTSC_TEST_MUX_SEL_inst_addr                                   "0x0108"
#define BTSC_TEST_MUX_SEL_inst                                        0x0108
#define BTSC_TEST_MUX_SEL_testoutputselect_shift                      (0)
#define BTSC_TEST_MUX_SEL_testoutputselect_mask                       (0x0000000F)
#define BTSC_TEST_MUX_SEL_testoutputselect(data)                      (0x0000000F&(data))
#define BTSC_TEST_MUX_SEL_get_testoutputselect(data)                  (0x0000000F&(data))


#define BTSC_DUMMY                                                    0x18006424
#define BTSC_DUMMY_reg_addr                                           "0xb8006424"
#define BTSC_DUMMY_reg                                                0xb8006424
#define BTSC_DUMMY_inst_addr                                          "0x0109"
#define BTSC_DUMMY_inst                                               0x0109
#define BTSC_DUMMY_dummy_6424_shift                                   (0)
#define BTSC_DUMMY_dummy_6424_mask                                    (0x0000FFFF)
#define BTSC_DUMMY_dummy_6424(data)                                   (0x0000FFFF&(data))
#define BTSC_DUMMY_get_dummy_6424(data)                               (0x0000FFFF&(data))


#define BTSC_CARRIER_FREQ_DEVIATION_CTRL                              0x18006428
#define BTSC_CARRIER_FREQ_DEVIATION_CTRL_reg_addr                     "0xb8006428"
#define BTSC_CARRIER_FREQ_DEVIATION_CTRL_reg                          0xb8006428
#define BTSC_CARRIER_FREQ_DEVIATION_CTRL_inst_addr                    "0x010A"
#define BTSC_CARRIER_FREQ_DEVIATION_CTRL_inst                         0x010A
#define BTSC_CARRIER_FREQ_DEVIATION_CTRL_btsc_main_phase_delta_shift  (16)
#define BTSC_CARRIER_FREQ_DEVIATION_CTRL_btsc_carrier_freq_correct_en_shift  (0)
#define BTSC_CARRIER_FREQ_DEVIATION_CTRL_btsc_main_phase_delta_mask   (0x0FFF0000)
#define BTSC_CARRIER_FREQ_DEVIATION_CTRL_btsc_carrier_freq_correct_en_mask  (0x00000001)
#define BTSC_CARRIER_FREQ_DEVIATION_CTRL_btsc_main_phase_delta(data)  (0x0FFF0000&((data)<<16))
#define BTSC_CARRIER_FREQ_DEVIATION_CTRL_btsc_carrier_freq_correct_en(data)  (0x00000001&(data))
#define BTSC_CARRIER_FREQ_DEVIATION_CTRL_get_btsc_main_phase_delta(data)  ((0x0FFF0000&(data))>>16)
#define BTSC_CARRIER_FREQ_DEVIATION_CTRL_get_btsc_carrier_freq_correct_en(data)  (0x00000001&(data))


#define PHASE_ERROR_PI_GAIN                                           0x1800642c
#define PHASE_ERROR_PI_GAIN_reg_addr                                  "0xb800642c"
#define PHASE_ERROR_PI_GAIN_reg                                       0xb800642c
#define PHASE_ERROR_PI_GAIN_inst_addr                                 "0x010B"
#define PHASE_ERROR_PI_GAIN_inst                                      0x010B
#define PHASE_ERROR_PI_GAIN_unlock_p_gain_shift                       (12)
#define PHASE_ERROR_PI_GAIN_unlock_i_gain_shift                       (8)
#define PHASE_ERROR_PI_GAIN_locked_p_gain_shift                       (4)
#define PHASE_ERROR_PI_GAIN_locked_i_gain_shift                       (0)
#define PHASE_ERROR_PI_GAIN_unlock_p_gain_mask                        (0x0000F000)
#define PHASE_ERROR_PI_GAIN_unlock_i_gain_mask                        (0x00000F00)
#define PHASE_ERROR_PI_GAIN_locked_p_gain_mask                        (0x000000F0)
#define PHASE_ERROR_PI_GAIN_locked_i_gain_mask                        (0x0000000F)
#define PHASE_ERROR_PI_GAIN_unlock_p_gain(data)                       (0x0000F000&((data)<<12))
#define PHASE_ERROR_PI_GAIN_unlock_i_gain(data)                       (0x00000F00&((data)<<8))
#define PHASE_ERROR_PI_GAIN_locked_p_gain(data)                       (0x000000F0&((data)<<4))
#define PHASE_ERROR_PI_GAIN_locked_i_gain(data)                       (0x0000000F&(data))
#define PHASE_ERROR_PI_GAIN_get_unlock_p_gain(data)                   ((0x0000F000&(data))>>12)
#define PHASE_ERROR_PI_GAIN_get_unlock_i_gain(data)                   ((0x00000F00&(data))>>8)
#define PHASE_ERROR_PI_GAIN_get_locked_p_gain(data)                   ((0x000000F0&(data))>>4)
#define PHASE_ERROR_PI_GAIN_get_locked_i_gain(data)                   (0x0000000F&(data))


#define PHASE_ERR_THRESHOLD                                           0x18006430
#define PHASE_ERR_THRESHOLD_reg_addr                                  "0xb8006430"
#define PHASE_ERR_THRESHOLD_reg                                       0xb8006430
#define PHASE_ERR_THRESHOLD_inst_addr                                 "0x010C"
#define PHASE_ERR_THRESHOLD_inst                                      0x010C
#define PHASE_ERR_THRESHOLD_sap_hpf_en_shift                          (31)
#define PHASE_ERR_THRESHOLD_phase_err_threshold_shift                 (0)
#define PHASE_ERR_THRESHOLD_sap_hpf_en_mask                           (0x80000000)
#define PHASE_ERR_THRESHOLD_phase_err_threshold_mask                  (0x00FFFFFF)
#define PHASE_ERR_THRESHOLD_sap_hpf_en(data)                          (0x80000000&((data)<<31))
#define PHASE_ERR_THRESHOLD_phase_err_threshold(data)                 (0x00FFFFFF&(data))
#define PHASE_ERR_THRESHOLD_get_sap_hpf_en(data)                      ((0x80000000&(data))>>31)
#define PHASE_ERR_THRESHOLD_get_phase_err_threshold(data)             (0x00FFFFFF&(data))


#define A2_EIAJ_DEMOD                                                 0x18006450
#define A2_EIAJ_DEMOD_reg_addr                                        "0xb8006450"
#define A2_EIAJ_DEMOD_reg                                             0xb8006450
#define A2_EIAJ_DEMOD_inst_addr                                       "0x0114"
#define A2_EIAJ_DEMOD_inst                                            0x0114
#define A2_EIAJ_DEMOD_a2_bw_sel_shift                                 (30)
#define A2_EIAJ_DEMOD_de_emphasis_time_shift                          (28)
#define A2_EIAJ_DEMOD_iir_lpf_en_shift                                (27)
#define A2_EIAJ_DEMOD_ultra_hdv_mode_shift                            (26)
#define A2_EIAJ_DEMOD_fm1_deviation_gain_shift                        (8)
#define A2_EIAJ_DEMOD_fm2_deviation_gain_shift                        (4)
#define A2_EIAJ_DEMOD_eiaj_sub_deviation_shift                        (0)
#define A2_EIAJ_DEMOD_a2_bw_sel_mask                                  (0xC0000000)
#define A2_EIAJ_DEMOD_de_emphasis_time_mask                           (0x30000000)
#define A2_EIAJ_DEMOD_iir_lpf_en_mask                                 (0x08000000)
#define A2_EIAJ_DEMOD_ultra_hdv_mode_mask                             (0x04000000)
#define A2_EIAJ_DEMOD_fm1_deviation_gain_mask                         (0x00000700)
#define A2_EIAJ_DEMOD_fm2_deviation_gain_mask                         (0x00000070)
#define A2_EIAJ_DEMOD_eiaj_sub_deviation_mask                         (0x00000001)
#define A2_EIAJ_DEMOD_a2_bw_sel(data)                                 (0xC0000000&((data)<<30))
#define A2_EIAJ_DEMOD_de_emphasis_time(data)                          (0x30000000&((data)<<28))
#define A2_EIAJ_DEMOD_iir_lpf_en(data)                                (0x08000000&((data)<<27))
#define A2_EIAJ_DEMOD_ultra_hdv_mode(data)                            (0x04000000&((data)<<26))
#define A2_EIAJ_DEMOD_fm1_deviation_gain(data)                        (0x00000700&((data)<<8))
#define A2_EIAJ_DEMOD_fm2_deviation_gain(data)                        (0x00000070&((data)<<4))
#define A2_EIAJ_DEMOD_eiaj_sub_deviation(data)                        (0x00000001&(data))
#define A2_EIAJ_DEMOD_get_a2_bw_sel(data)                             ((0xC0000000&(data))>>30)
#define A2_EIAJ_DEMOD_get_de_emphasis_time(data)                      ((0x30000000&(data))>>28)
#define A2_EIAJ_DEMOD_get_iir_lpf_en(data)                            ((0x08000000&(data))>>27)
#define A2_EIAJ_DEMOD_get_ultra_hdv_mode(data)                        ((0x04000000&(data))>>26)
#define A2_EIAJ_DEMOD_get_fm1_deviation_gain(data)                    ((0x00000700&(data))>>8)
#define A2_EIAJ_DEMOD_get_fm2_deviation_gain(data)                    ((0x00000070&(data))>>4)
#define A2_EIAJ_DEMOD_get_eiaj_sub_deviation(data)                    (0x00000001&(data))


#define MBIST_A2_EIAJ_DEMOD                                           0x18006454
#define MBIST_A2_EIAJ_DEMOD_reg_addr                                  "0xb8006454"
#define MBIST_A2_EIAJ_DEMOD_reg                                       0xb8006454
#define MBIST_A2_EIAJ_DEMOD_inst_addr                                 "0x0115"
#define MBIST_A2_EIAJ_DEMOD_inst                                      0x0115
#define MBIST_A2_EIAJ_DEMOD_rst_n_shift                               (31)
#define MBIST_A2_EIAJ_DEMOD_enable_shift                              (30)
#define MBIST_A2_EIAJ_DEMOD_done_shift                                (29)
#define MBIST_A2_EIAJ_DEMOD_dvse_0_a2_eiaj_shift                      (28)
#define MBIST_A2_EIAJ_DEMOD_dvs_0_a2_eiaj_shift                       (24)
#define MBIST_A2_EIAJ_DEMOD_drf_start_pause_a2_eiaj_shift             (23)
#define MBIST_A2_EIAJ_DEMOD_drf_test_resume_a2_eiaj_shift             (22)
#define MBIST_A2_EIAJ_DEMOD_drf_bist_mode_a2_eiaj_shift               (21)
#define MBIST_A2_EIAJ_DEMOD_drf_bist_done_a2_eiaj_shift               (20)
#define MBIST_A2_EIAJ_DEMOD_drf_fail_24x98_1_shift                    (19)
#define MBIST_A2_EIAJ_DEMOD_drf_fail_24x98_0_shift                    (18)
#define MBIST_A2_EIAJ_DEMOD_drf_fail_24x74_0_shift                    (17)
#define MBIST_A2_EIAJ_DEMOD_drf_fail_24x66_1_shift                    (16)
#define MBIST_A2_EIAJ_DEMOD_drf_fail_24x66_0_shift                    (15)
#define MBIST_A2_EIAJ_DEMOD_drf_fail_24x14_1_shift                    (14)
#define MBIST_A2_EIAJ_DEMOD_drf_fail_24x14_0_shift                    (13)
#define MBIST_A2_EIAJ_DEMOD_drf_fail_24x13_1_shift                    (12)
#define MBIST_A2_EIAJ_DEMOD_drf_fail_24x13_0_shift                    (11)
#define MBIST_A2_EIAJ_DEMOD_fail_24x98_1_shift                        (8)
#define MBIST_A2_EIAJ_DEMOD_fail_24x98_0_shift                        (7)
#define MBIST_A2_EIAJ_DEMOD_fail_24x74_0_shift                        (6)
#define MBIST_A2_EIAJ_DEMOD_fail_24x66_1_shift                        (5)
#define MBIST_A2_EIAJ_DEMOD_fail_24x66_0_shift                        (4)
#define MBIST_A2_EIAJ_DEMOD_fail_24x14_1_shift                        (3)
#define MBIST_A2_EIAJ_DEMOD_fail_24x14_0_shift                        (2)
#define MBIST_A2_EIAJ_DEMOD_fail_24x13_1_shift                        (1)
#define MBIST_A2_EIAJ_DEMOD_fail_24x13_0_shift                        (0)
#define MBIST_A2_EIAJ_DEMOD_rst_n_mask                                (0x80000000)
#define MBIST_A2_EIAJ_DEMOD_enable_mask                               (0x40000000)
#define MBIST_A2_EIAJ_DEMOD_done_mask                                 (0x20000000)
#define MBIST_A2_EIAJ_DEMOD_dvse_0_a2_eiaj_mask                       (0x10000000)
#define MBIST_A2_EIAJ_DEMOD_dvs_0_a2_eiaj_mask                        (0x0F000000)
#define MBIST_A2_EIAJ_DEMOD_drf_start_pause_a2_eiaj_mask              (0x00800000)
#define MBIST_A2_EIAJ_DEMOD_drf_test_resume_a2_eiaj_mask              (0x00400000)
#define MBIST_A2_EIAJ_DEMOD_drf_bist_mode_a2_eiaj_mask                (0x00200000)
#define MBIST_A2_EIAJ_DEMOD_drf_bist_done_a2_eiaj_mask                (0x00100000)
#define MBIST_A2_EIAJ_DEMOD_drf_fail_24x98_1_mask                     (0x00080000)
#define MBIST_A2_EIAJ_DEMOD_drf_fail_24x98_0_mask                     (0x00040000)
#define MBIST_A2_EIAJ_DEMOD_drf_fail_24x74_0_mask                     (0x00020000)
#define MBIST_A2_EIAJ_DEMOD_drf_fail_24x66_1_mask                     (0x00010000)
#define MBIST_A2_EIAJ_DEMOD_drf_fail_24x66_0_mask                     (0x00008000)
#define MBIST_A2_EIAJ_DEMOD_drf_fail_24x14_1_mask                     (0x00004000)
#define MBIST_A2_EIAJ_DEMOD_drf_fail_24x14_0_mask                     (0x00002000)
#define MBIST_A2_EIAJ_DEMOD_drf_fail_24x13_1_mask                     (0x00001000)
#define MBIST_A2_EIAJ_DEMOD_drf_fail_24x13_0_mask                     (0x00000800)
#define MBIST_A2_EIAJ_DEMOD_fail_24x98_1_mask                         (0x00000100)
#define MBIST_A2_EIAJ_DEMOD_fail_24x98_0_mask                         (0x00000080)
#define MBIST_A2_EIAJ_DEMOD_fail_24x74_0_mask                         (0x00000040)
#define MBIST_A2_EIAJ_DEMOD_fail_24x66_1_mask                         (0x00000020)
#define MBIST_A2_EIAJ_DEMOD_fail_24x66_0_mask                         (0x00000010)
#define MBIST_A2_EIAJ_DEMOD_fail_24x14_1_mask                         (0x00000008)
#define MBIST_A2_EIAJ_DEMOD_fail_24x14_0_mask                         (0x00000004)
#define MBIST_A2_EIAJ_DEMOD_fail_24x13_1_mask                         (0x00000002)
#define MBIST_A2_EIAJ_DEMOD_fail_24x13_0_mask                         (0x00000001)
#define MBIST_A2_EIAJ_DEMOD_rst_n(data)                               (0x80000000&((data)<<31))
#define MBIST_A2_EIAJ_DEMOD_enable(data)                              (0x40000000&((data)<<30))
#define MBIST_A2_EIAJ_DEMOD_done(data)                                (0x20000000&((data)<<29))
#define MBIST_A2_EIAJ_DEMOD_dvse_0_a2_eiaj(data)                      (0x10000000&((data)<<28))
#define MBIST_A2_EIAJ_DEMOD_dvs_0_a2_eiaj(data)                       (0x0F000000&((data)<<24))
#define MBIST_A2_EIAJ_DEMOD_drf_start_pause_a2_eiaj(data)             (0x00800000&((data)<<23))
#define MBIST_A2_EIAJ_DEMOD_drf_test_resume_a2_eiaj(data)             (0x00400000&((data)<<22))
#define MBIST_A2_EIAJ_DEMOD_drf_bist_mode_a2_eiaj(data)               (0x00200000&((data)<<21))
#define MBIST_A2_EIAJ_DEMOD_drf_bist_done_a2_eiaj(data)               (0x00100000&((data)<<20))
#define MBIST_A2_EIAJ_DEMOD_drf_fail_24x98_1(data)                    (0x00080000&((data)<<19))
#define MBIST_A2_EIAJ_DEMOD_drf_fail_24x98_0(data)                    (0x00040000&((data)<<18))
#define MBIST_A2_EIAJ_DEMOD_drf_fail_24x74_0(data)                    (0x00020000&((data)<<17))
#define MBIST_A2_EIAJ_DEMOD_drf_fail_24x66_1(data)                    (0x00010000&((data)<<16))
#define MBIST_A2_EIAJ_DEMOD_drf_fail_24x66_0(data)                    (0x00008000&((data)<<15))
#define MBIST_A2_EIAJ_DEMOD_drf_fail_24x14_1(data)                    (0x00004000&((data)<<14))
#define MBIST_A2_EIAJ_DEMOD_drf_fail_24x14_0(data)                    (0x00002000&((data)<<13))
#define MBIST_A2_EIAJ_DEMOD_drf_fail_24x13_1(data)                    (0x00001000&((data)<<12))
#define MBIST_A2_EIAJ_DEMOD_drf_fail_24x13_0(data)                    (0x00000800&((data)<<11))
#define MBIST_A2_EIAJ_DEMOD_fail_24x98_1(data)                        (0x00000100&((data)<<8))
#define MBIST_A2_EIAJ_DEMOD_fail_24x98_0(data)                        (0x00000080&((data)<<7))
#define MBIST_A2_EIAJ_DEMOD_fail_24x74_0(data)                        (0x00000040&((data)<<6))
#define MBIST_A2_EIAJ_DEMOD_fail_24x66_1(data)                        (0x00000020&((data)<<5))
#define MBIST_A2_EIAJ_DEMOD_fail_24x66_0(data)                        (0x00000010&((data)<<4))
#define MBIST_A2_EIAJ_DEMOD_fail_24x14_1(data)                        (0x00000008&((data)<<3))
#define MBIST_A2_EIAJ_DEMOD_fail_24x14_0(data)                        (0x00000004&((data)<<2))
#define MBIST_A2_EIAJ_DEMOD_fail_24x13_1(data)                        (0x00000002&((data)<<1))
#define MBIST_A2_EIAJ_DEMOD_fail_24x13_0(data)                        (0x00000001&(data))
#define MBIST_A2_EIAJ_DEMOD_get_rst_n(data)                           ((0x80000000&(data))>>31)
#define MBIST_A2_EIAJ_DEMOD_get_enable(data)                          ((0x40000000&(data))>>30)
#define MBIST_A2_EIAJ_DEMOD_get_done(data)                            ((0x20000000&(data))>>29)
#define MBIST_A2_EIAJ_DEMOD_get_dvse_0_a2_eiaj(data)                  ((0x10000000&(data))>>28)
#define MBIST_A2_EIAJ_DEMOD_get_dvs_0_a2_eiaj(data)                   ((0x0F000000&(data))>>24)
#define MBIST_A2_EIAJ_DEMOD_get_drf_start_pause_a2_eiaj(data)         ((0x00800000&(data))>>23)
#define MBIST_A2_EIAJ_DEMOD_get_drf_test_resume_a2_eiaj(data)         ((0x00400000&(data))>>22)
#define MBIST_A2_EIAJ_DEMOD_get_drf_bist_mode_a2_eiaj(data)           ((0x00200000&(data))>>21)
#define MBIST_A2_EIAJ_DEMOD_get_drf_bist_done_a2_eiaj(data)           ((0x00100000&(data))>>20)
#define MBIST_A2_EIAJ_DEMOD_get_drf_fail_24x98_1(data)                ((0x00080000&(data))>>19)
#define MBIST_A2_EIAJ_DEMOD_get_drf_fail_24x98_0(data)                ((0x00040000&(data))>>18)
#define MBIST_A2_EIAJ_DEMOD_get_drf_fail_24x74_0(data)                ((0x00020000&(data))>>17)
#define MBIST_A2_EIAJ_DEMOD_get_drf_fail_24x66_1(data)                ((0x00010000&(data))>>16)
#define MBIST_A2_EIAJ_DEMOD_get_drf_fail_24x66_0(data)                ((0x00008000&(data))>>15)
#define MBIST_A2_EIAJ_DEMOD_get_drf_fail_24x14_1(data)                ((0x00004000&(data))>>14)
#define MBIST_A2_EIAJ_DEMOD_get_drf_fail_24x14_0(data)                ((0x00002000&(data))>>13)
#define MBIST_A2_EIAJ_DEMOD_get_drf_fail_24x13_1(data)                ((0x00001000&(data))>>12)
#define MBIST_A2_EIAJ_DEMOD_get_drf_fail_24x13_0(data)                ((0x00000800&(data))>>11)
#define MBIST_A2_EIAJ_DEMOD_get_fail_24x98_1(data)                    ((0x00000100&(data))>>8)
#define MBIST_A2_EIAJ_DEMOD_get_fail_24x98_0(data)                    ((0x00000080&(data))>>7)
#define MBIST_A2_EIAJ_DEMOD_get_fail_24x74_0(data)                    ((0x00000040&(data))>>6)
#define MBIST_A2_EIAJ_DEMOD_get_fail_24x66_1(data)                    ((0x00000020&(data))>>5)
#define MBIST_A2_EIAJ_DEMOD_get_fail_24x66_0(data)                    ((0x00000010&(data))>>4)
#define MBIST_A2_EIAJ_DEMOD_get_fail_24x14_1(data)                    ((0x00000008&(data))>>3)
#define MBIST_A2_EIAJ_DEMOD_get_fail_24x14_0(data)                    ((0x00000004&(data))>>2)
#define MBIST_A2_EIAJ_DEMOD_get_fail_24x13_1(data)                    ((0x00000002&(data))>>1)
#define MBIST_A2_EIAJ_DEMOD_get_fail_24x13_0(data)                    (0x00000001&(data))


#define A2_EIAJ_DC_FILTER                                             0x18006458
#define A2_EIAJ_DC_FILTER_reg_addr                                    "0xb8006458"
#define A2_EIAJ_DC_FILTER_reg                                         0xb8006458
#define A2_EIAJ_DC_FILTER_inst_addr                                   "0x0116"
#define A2_EIAJ_DC_FILTER_inst                                        0x0116
#define A2_EIAJ_DC_FILTER_magnitude_shift                             (16)
#define A2_EIAJ_DC_FILTER_dummy18006458_15_0_shift                    (0)
#define A2_EIAJ_DC_FILTER_magnitude_mask                              (0xFFFF0000)
#define A2_EIAJ_DC_FILTER_dummy18006458_15_0_mask                     (0x0000FFFF)
#define A2_EIAJ_DC_FILTER_magnitude(data)                             (0xFFFF0000&((data)<<16))
#define A2_EIAJ_DC_FILTER_dummy18006458_15_0(data)                    (0x0000FFFF&(data))
#define A2_EIAJ_DC_FILTER_get_magnitude(data)                         ((0xFFFF0000&(data))>>16)
#define A2_EIAJ_DC_FILTER_get_dummy18006458_15_0(data)                (0x0000FFFF&(data))


#define NICAM_DEMOD                                                   0x18006500
#define NICAM_DEMOD_reg_addr                                          "0xb8006500"
#define NICAM_DEMOD_reg                                               0xb8006500
#define NICAM_DEMOD_inst_addr                                         "0x0140"
#define NICAM_DEMOD_inst                                              0x0140
#define NICAM_DEMOD_psf_sel_shift                                     (31)
#define NICAM_DEMOD_tr_lpf_kp_shift                                   (28)
#define NICAM_DEMOD_cr_lpf_kp_shift                                   (24)
#define NICAM_DEMOD_cr_lpf_ki_shift                                   (20)
#define NICAM_DEMOD_tr_timing_step_shift                              (0)
#define NICAM_DEMOD_psf_sel_mask                                      (0x80000000)
#define NICAM_DEMOD_tr_lpf_kp_mask                                    (0x70000000)
#define NICAM_DEMOD_cr_lpf_kp_mask                                    (0x07000000)
#define NICAM_DEMOD_cr_lpf_ki_mask                                    (0x00300000)
#define NICAM_DEMOD_tr_timing_step_mask                               (0x000FFFFF)
#define NICAM_DEMOD_psf_sel(data)                                     (0x80000000&((data)<<31))
#define NICAM_DEMOD_tr_lpf_kp(data)                                   (0x70000000&((data)<<28))
#define NICAM_DEMOD_cr_lpf_kp(data)                                   (0x07000000&((data)<<24))
#define NICAM_DEMOD_cr_lpf_ki(data)                                   (0x00300000&((data)<<20))
#define NICAM_DEMOD_tr_timing_step(data)                              (0x000FFFFF&(data))
#define NICAM_DEMOD_get_psf_sel(data)                                 ((0x80000000&(data))>>31)
#define NICAM_DEMOD_get_tr_lpf_kp(data)                               ((0x70000000&(data))>>28)
#define NICAM_DEMOD_get_cr_lpf_kp(data)                               ((0x07000000&(data))>>24)
#define NICAM_DEMOD_get_cr_lpf_ki(data)                               ((0x00300000&(data))>>20)
#define NICAM_DEMOD_get_tr_timing_step(data)                          (0x000FFFFF&(data))


#define NICAM_DAGC_CTRL                                               0x18006504
#define NICAM_DAGC_CTRL_reg_addr                                      "0xb8006504"
#define NICAM_DAGC_CTRL_reg                                           0xb8006504
#define NICAM_DAGC_CTRL_inst_addr                                     "0x0141"
#define NICAM_DAGC_CTRL_inst                                          0x0141
#define NICAM_DAGC_CTRL_enable_shift                                  (31)
#define NICAM_DAGC_CTRL_debounce_cnt_shift                            (28)
#define NICAM_DAGC_CTRL_window_size_shift                             (16)
#define NICAM_DAGC_CTRL_gain_adjust_shift                             (0)
#define NICAM_DAGC_CTRL_enable_mask                                   (0x80000000)
#define NICAM_DAGC_CTRL_debounce_cnt_mask                             (0x70000000)
#define NICAM_DAGC_CTRL_window_size_mask                              (0x03FF0000)
#define NICAM_DAGC_CTRL_gain_adjust_mask                              (0x0000003F)
#define NICAM_DAGC_CTRL_enable(data)                                  (0x80000000&((data)<<31))
#define NICAM_DAGC_CTRL_debounce_cnt(data)                            (0x70000000&((data)<<28))
#define NICAM_DAGC_CTRL_window_size(data)                             (0x03FF0000&((data)<<16))
#define NICAM_DAGC_CTRL_gain_adjust(data)                             (0x0000003F&(data))
#define NICAM_DAGC_CTRL_get_enable(data)                              ((0x80000000&(data))>>31)
#define NICAM_DAGC_CTRL_get_debounce_cnt(data)                        ((0x70000000&(data))>>28)
#define NICAM_DAGC_CTRL_get_window_size(data)                         ((0x03FF0000&(data))>>16)
#define NICAM_DAGC_CTRL_get_gain_adjust(data)                         (0x0000003F&(data))


#define NICAM_DAGC_THRESHOLD                                          0x18006508
#define NICAM_DAGC_THRESHOLD_reg_addr                                 "0xb8006508"
#define NICAM_DAGC_THRESHOLD_reg                                      0xb8006508
#define NICAM_DAGC_THRESHOLD_inst_addr                                "0x0142"
#define NICAM_DAGC_THRESHOLD_inst                                     0x0142
#define NICAM_DAGC_THRESHOLD_high_shift                               (16)
#define NICAM_DAGC_THRESHOLD_low_shift                                (0)
#define NICAM_DAGC_THRESHOLD_high_mask                                (0xFFFF0000)
#define NICAM_DAGC_THRESHOLD_low_mask                                 (0x0000FFFF)
#define NICAM_DAGC_THRESHOLD_high(data)                               (0xFFFF0000&((data)<<16))
#define NICAM_DAGC_THRESHOLD_low(data)                                (0x0000FFFF&(data))
#define NICAM_DAGC_THRESHOLD_get_high(data)                           ((0xFFFF0000&(data))>>16)
#define NICAM_DAGC_THRESHOLD_get_low(data)                            (0x0000FFFF&(data))


#define NICAM_DAGC_MAG                                                0x1800650c
#define NICAM_DAGC_MAG_reg_addr                                       "0xb800650c"
#define NICAM_DAGC_MAG_reg                                            0xb800650c
#define NICAM_DAGC_MAG_inst_addr                                      "0x0143"
#define NICAM_DAGC_MAG_inst                                           0x0143
#define NICAM_DAGC_MAG_magnitude_shift                                (0)
#define NICAM_DAGC_MAG_magnitude_mask                                 (0x0000FFFF)
#define NICAM_DAGC_MAG_magnitude(data)                                (0x0000FFFF&(data))
#define NICAM_DAGC_MAG_get_magnitude(data)                            (0x0000FFFF&(data))


#define NICAM_DECODE_CTRL                                             0x18006510
#define NICAM_DECODE_CTRL_reg_addr                                    "0xb8006510"
#define NICAM_DECODE_CTRL_reg                                         0xb8006510
#define NICAM_DECODE_CTRL_inst_addr                                   "0x0144"
#define NICAM_DECODE_CTRL_inst                                        0x0144
#define NICAM_DECODE_CTRL_resampler_ctrl_shift                        (31)
#define NICAM_DECODE_CTRL_data_channel_sel_shift                      (30)
#define NICAM_DECODE_CTRL_pcm_l_out_sel_shift                         (29)
#define NICAM_DECODE_CTRL_pcm_r_out_sel_shift                         (28)
#define NICAM_DECODE_CTRL_cib_1_shift                                 (27)
#define NICAM_DECODE_CTRL_cib_0_shift                                 (26)
#define NICAM_DECODE_CTRL_cib_mask_shift                              (25)
#define NICAM_DECODE_CTRL_status_debounce_cnt_shift                   (20)
#define NICAM_DECODE_CTRL_bypass_interpol_shift                       (19)
#define NICAM_DECODE_CTRL_sat_en_shift                                (18)
#define NICAM_DECODE_CTRL_de_em_by_pass_shift                         (17)
#define NICAM_DECODE_CTRL_level_sel_shift                             (16)
#define NICAM_DECODE_CTRL_dummy18006510_15_0_shift                    (0)
#define NICAM_DECODE_CTRL_resampler_ctrl_mask                         (0x80000000)
#define NICAM_DECODE_CTRL_data_channel_sel_mask                       (0x40000000)
#define NICAM_DECODE_CTRL_pcm_l_out_sel_mask                          (0x20000000)
#define NICAM_DECODE_CTRL_pcm_r_out_sel_mask                          (0x10000000)
#define NICAM_DECODE_CTRL_cib_1_mask                                  (0x08000000)
#define NICAM_DECODE_CTRL_cib_0_mask                                  (0x04000000)
#define NICAM_DECODE_CTRL_cib_mask_mask                               (0x02000000)
#define NICAM_DECODE_CTRL_status_debounce_cnt_mask                    (0x00F00000)
#define NICAM_DECODE_CTRL_bypass_interpol_mask                        (0x00080000)
#define NICAM_DECODE_CTRL_sat_en_mask                                 (0x00040000)
#define NICAM_DECODE_CTRL_de_em_by_pass_mask                          (0x00020000)
#define NICAM_DECODE_CTRL_level_sel_mask                              (0x00010000)
#define NICAM_DECODE_CTRL_dummy18006510_15_0_mask                     (0x0000FFFF)
#define NICAM_DECODE_CTRL_resampler_ctrl(data)                        (0x80000000&((data)<<31))
#define NICAM_DECODE_CTRL_data_channel_sel(data)                      (0x40000000&((data)<<30))
#define NICAM_DECODE_CTRL_pcm_l_out_sel(data)                         (0x20000000&((data)<<29))
#define NICAM_DECODE_CTRL_pcm_r_out_sel(data)                         (0x10000000&((data)<<28))
#define NICAM_DECODE_CTRL_cib_1(data)                                 (0x08000000&((data)<<27))
#define NICAM_DECODE_CTRL_cib_0(data)                                 (0x04000000&((data)<<26))
#define NICAM_DECODE_CTRL_cib_mask(data)                              (0x02000000&((data)<<25))
#define NICAM_DECODE_CTRL_status_debounce_cnt(data)                   (0x00F00000&((data)<<20))
#define NICAM_DECODE_CTRL_bypass_interpol(data)                       (0x00080000&((data)<<19))
#define NICAM_DECODE_CTRL_sat_en(data)                                (0x00040000&((data)<<18))
#define NICAM_DECODE_CTRL_de_em_by_pass(data)                         (0x00020000&((data)<<17))
#define NICAM_DECODE_CTRL_level_sel(data)                             (0x00010000&((data)<<16))
#define NICAM_DECODE_CTRL_dummy18006510_15_0(data)                    (0x0000FFFF&(data))
#define NICAM_DECODE_CTRL_get_resampler_ctrl(data)                    ((0x80000000&(data))>>31)
#define NICAM_DECODE_CTRL_get_data_channel_sel(data)                  ((0x40000000&(data))>>30)
#define NICAM_DECODE_CTRL_get_pcm_l_out_sel(data)                     ((0x20000000&(data))>>29)
#define NICAM_DECODE_CTRL_get_pcm_r_out_sel(data)                     ((0x10000000&(data))>>28)
#define NICAM_DECODE_CTRL_get_cib_1(data)                             ((0x08000000&(data))>>27)
#define NICAM_DECODE_CTRL_get_cib_0(data)                             ((0x04000000&(data))>>26)
#define NICAM_DECODE_CTRL_get_cib_mask(data)                          ((0x02000000&(data))>>25)
#define NICAM_DECODE_CTRL_get_status_debounce_cnt(data)               ((0x00F00000&(data))>>20)
#define NICAM_DECODE_CTRL_get_bypass_interpol(data)                   ((0x00080000&(data))>>19)
#define NICAM_DECODE_CTRL_get_sat_en(data)                            ((0x00040000&(data))>>18)
#define NICAM_DECODE_CTRL_get_de_em_by_pass(data)                     ((0x00020000&(data))>>17)
#define NICAM_DECODE_CTRL_get_level_sel(data)                         ((0x00010000&(data))>>16)
#define NICAM_DECODE_CTRL_get_dummy18006510_15_0(data)                (0x0000FFFF&(data))


#define NICAM_DECODE_STATUS                                           0x18006514
#define NICAM_DECODE_STATUS_reg_addr                                  "0xb8006514"
#define NICAM_DECODE_STATUS_reg                                       0xb8006514
#define NICAM_DECODE_STATUS_inst_addr                                 "0x0145"
#define NICAM_DECODE_STATUS_inst                                      0x0145
#define NICAM_DECODE_STATUS_c0_shift                                  (31)
#define NICAM_DECODE_STATUS_c1c2c3_shift                              (28)
#define NICAM_DECODE_STATUS_c4_shift                                  (27)
#define NICAM_DECODE_STATUS_additional_data_shift                     (16)
#define NICAM_DECODE_STATUS_bit_cnt_sync_shift                        (13)
#define NICAM_DECODE_STATUS_true_detect_shift                         (12)
#define NICAM_DECODE_STATUS_bit_error_rate_shift                      (0)
#define NICAM_DECODE_STATUS_c0_mask                                   (0x80000000)
#define NICAM_DECODE_STATUS_c1c2c3_mask                               (0x70000000)
#define NICAM_DECODE_STATUS_c4_mask                                   (0x08000000)
#define NICAM_DECODE_STATUS_additional_data_mask                      (0x07FF0000)
#define NICAM_DECODE_STATUS_bit_cnt_sync_mask                         (0x00002000)
#define NICAM_DECODE_STATUS_true_detect_mask                          (0x00001000)
#define NICAM_DECODE_STATUS_bit_error_rate_mask                       (0x00000FFF)
#define NICAM_DECODE_STATUS_c0(data)                                  (0x80000000&((data)<<31))
#define NICAM_DECODE_STATUS_c1c2c3(data)                              (0x70000000&((data)<<28))
#define NICAM_DECODE_STATUS_c4(data)                                  (0x08000000&((data)<<27))
#define NICAM_DECODE_STATUS_additional_data(data)                     (0x07FF0000&((data)<<16))
#define NICAM_DECODE_STATUS_bit_cnt_sync(data)                        (0x00002000&((data)<<13))
#define NICAM_DECODE_STATUS_true_detect(data)                         (0x00001000&((data)<<12))
#define NICAM_DECODE_STATUS_bit_error_rate(data)                      (0x00000FFF&(data))
#define NICAM_DECODE_STATUS_get_c0(data)                              ((0x80000000&(data))>>31)
#define NICAM_DECODE_STATUS_get_c1c2c3(data)                          ((0x70000000&(data))>>28)
#define NICAM_DECODE_STATUS_get_c4(data)                              ((0x08000000&(data))>>27)
#define NICAM_DECODE_STATUS_get_additional_data(data)                 ((0x07FF0000&(data))>>16)
#define NICAM_DECODE_STATUS_get_bit_cnt_sync(data)                    ((0x00002000&(data))>>13)
#define NICAM_DECODE_STATUS_get_true_detect(data)                     ((0x00001000&(data))>>12)
#define NICAM_DECODE_STATUS_get_bit_error_rate(data)                  (0x00000FFF&(data))


#define NICAM_AUTO_SWITCH                                             0x18006518
#define NICAM_AUTO_SWITCH_reg_addr                                    "0xb8006518"
#define NICAM_AUTO_SWITCH_reg                                         0xb8006518
#define NICAM_AUTO_SWITCH_inst_addr                                   "0x0146"
#define NICAM_AUTO_SWITCH_inst                                        0x0146
#define NICAM_AUTO_SWITCH_enable_shift                                (31)
#define NICAM_AUTO_SWITCH_c4_hi_ber_shift                             (28)
#define NICAM_AUTO_SWITCH_analog_flag_shift                           (27)
#define NICAM_AUTO_SWITCH_hi_ber_debounce_shift                       (24)
#define NICAM_AUTO_SWITCH_high_threshold_shift                        (12)
#define NICAM_AUTO_SWITCH_low_threshold_shift                         (0)
#define NICAM_AUTO_SWITCH_enable_mask                                 (0x80000000)
#define NICAM_AUTO_SWITCH_c4_hi_ber_mask                              (0x30000000)
#define NICAM_AUTO_SWITCH_analog_flag_mask                            (0x08000000)
#define NICAM_AUTO_SWITCH_hi_ber_debounce_mask                        (0x07000000)
#define NICAM_AUTO_SWITCH_high_threshold_mask                         (0x00FFF000)
#define NICAM_AUTO_SWITCH_low_threshold_mask                          (0x00000FFF)
#define NICAM_AUTO_SWITCH_enable(data)                                (0x80000000&((data)<<31))
#define NICAM_AUTO_SWITCH_c4_hi_ber(data)                             (0x30000000&((data)<<28))
#define NICAM_AUTO_SWITCH_analog_flag(data)                           (0x08000000&((data)<<27))
#define NICAM_AUTO_SWITCH_hi_ber_debounce(data)                       (0x07000000&((data)<<24))
#define NICAM_AUTO_SWITCH_high_threshold(data)                        (0x00FFF000&((data)<<12))
#define NICAM_AUTO_SWITCH_low_threshold(data)                         (0x00000FFF&(data))
#define NICAM_AUTO_SWITCH_get_enable(data)                            ((0x80000000&(data))>>31)
#define NICAM_AUTO_SWITCH_get_c4_hi_ber(data)                         ((0x30000000&(data))>>28)
#define NICAM_AUTO_SWITCH_get_analog_flag(data)                       ((0x08000000&(data))>>27)
#define NICAM_AUTO_SWITCH_get_hi_ber_debounce(data)                   ((0x07000000&(data))>>24)
#define NICAM_AUTO_SWITCH_get_high_threshold(data)                    ((0x00FFF000&(data))>>12)
#define NICAM_AUTO_SWITCH_get_low_threshold(data)                     (0x00000FFF&(data))


#define NICAM_DEMOD_AUTO_RECOVERY                                     0x1800651c
#define NICAM_DEMOD_AUTO_RECOVERY_reg_addr                            "0xb800651c"
#define NICAM_DEMOD_AUTO_RECOVERY_reg                                 0xb800651c
#define NICAM_DEMOD_AUTO_RECOVERY_inst_addr                           "0x0147"
#define NICAM_DEMOD_AUTO_RECOVERY_inst                                0x0147
#define NICAM_DEMOD_AUTO_RECOVERY_enable_shift                        (31)
#define NICAM_DEMOD_AUTO_RECOVERY_duration_shift                      (28)
#define NICAM_DEMOD_AUTO_RECOVERY_enable_mask                         (0x80000000)
#define NICAM_DEMOD_AUTO_RECOVERY_duration_mask                       (0x30000000)
#define NICAM_DEMOD_AUTO_RECOVERY_enable(data)                        (0x80000000&((data)<<31))
#define NICAM_DEMOD_AUTO_RECOVERY_duration(data)                      (0x30000000&((data)<<28))
#define NICAM_DEMOD_AUTO_RECOVERY_get_enable(data)                    ((0x80000000&(data))>>31)
#define NICAM_DEMOD_AUTO_RECOVERY_get_duration(data)                  ((0x30000000&(data))>>28)


#define DOWN_SAMPLE_CONTROL_FOR_PLAYBACK                              0x18006550
#define DOWN_SAMPLE_CONTROL_FOR_PLAYBACK_reg_addr                     "0xb8006550"
#define DOWN_SAMPLE_CONTROL_FOR_PLAYBACK_reg                          0xb8006550
#define DOWN_SAMPLE_CONTROL_FOR_PLAYBACK_inst_addr                    "0x0154"
#define DOWN_SAMPLE_CONTROL_FOR_PLAYBACK_inst                         0x0154
#define DOWN_SAMPLE_CONTROL_FOR_PLAYBACK_fifo_ch7_source_shift        (30)
#define DOWN_SAMPLE_CONTROL_FOR_PLAYBACK_fifo_ch8_source_shift        (28)
#define DOWN_SAMPLE_CONTROL_FOR_PLAYBACK_fifo_ch5_source_shift        (26)
#define DOWN_SAMPLE_CONTROL_FOR_PLAYBACK_fifo_ch6_source_shift        (24)
#define DOWN_SAMPLE_CONTROL_FOR_PLAYBACK_fifo_ch3_source_shift        (22)
#define DOWN_SAMPLE_CONTROL_FOR_PLAYBACK_fifo_ch4_source_shift        (20)
#define DOWN_SAMPLE_CONTROL_FOR_PLAYBACK_fifo_ch1_source_shift        (18)
#define DOWN_SAMPLE_CONTROL_FOR_PLAYBACK_fifo_ch2_source_shift        (16)
#define DOWN_SAMPLE_CONTROL_FOR_PLAYBACK_backend_play_en_shift        (2)
#define DOWN_SAMPLE_CONTROL_FOR_PLAYBACK_downsample_en_shift          (1)
#define DOWN_SAMPLE_CONTROL_FOR_PLAYBACK_down_rate_shift              (0)
#define DOWN_SAMPLE_CONTROL_FOR_PLAYBACK_fifo_ch7_source_mask         (0xC0000000)
#define DOWN_SAMPLE_CONTROL_FOR_PLAYBACK_fifo_ch8_source_mask         (0x30000000)
#define DOWN_SAMPLE_CONTROL_FOR_PLAYBACK_fifo_ch5_source_mask         (0x0C000000)
#define DOWN_SAMPLE_CONTROL_FOR_PLAYBACK_fifo_ch6_source_mask         (0x03000000)
#define DOWN_SAMPLE_CONTROL_FOR_PLAYBACK_fifo_ch3_source_mask         (0x00C00000)
#define DOWN_SAMPLE_CONTROL_FOR_PLAYBACK_fifo_ch4_source_mask         (0x00300000)
#define DOWN_SAMPLE_CONTROL_FOR_PLAYBACK_fifo_ch1_source_mask         (0x000C0000)
#define DOWN_SAMPLE_CONTROL_FOR_PLAYBACK_fifo_ch2_source_mask         (0x00030000)
#define DOWN_SAMPLE_CONTROL_FOR_PLAYBACK_backend_play_en_mask         (0x00000004)
#define DOWN_SAMPLE_CONTROL_FOR_PLAYBACK_downsample_en_mask           (0x00000002)
#define DOWN_SAMPLE_CONTROL_FOR_PLAYBACK_down_rate_mask               (0x00000001)
#define DOWN_SAMPLE_CONTROL_FOR_PLAYBACK_fifo_ch7_source(data)        (0xC0000000&((data)<<30))
#define DOWN_SAMPLE_CONTROL_FOR_PLAYBACK_fifo_ch8_source(data)        (0x30000000&((data)<<28))
#define DOWN_SAMPLE_CONTROL_FOR_PLAYBACK_fifo_ch5_source(data)        (0x0C000000&((data)<<26))
#define DOWN_SAMPLE_CONTROL_FOR_PLAYBACK_fifo_ch6_source(data)        (0x03000000&((data)<<24))
#define DOWN_SAMPLE_CONTROL_FOR_PLAYBACK_fifo_ch3_source(data)        (0x00C00000&((data)<<22))
#define DOWN_SAMPLE_CONTROL_FOR_PLAYBACK_fifo_ch4_source(data)        (0x00300000&((data)<<20))
#define DOWN_SAMPLE_CONTROL_FOR_PLAYBACK_fifo_ch1_source(data)        (0x000C0000&((data)<<18))
#define DOWN_SAMPLE_CONTROL_FOR_PLAYBACK_fifo_ch2_source(data)        (0x00030000&((data)<<16))
#define DOWN_SAMPLE_CONTROL_FOR_PLAYBACK_backend_play_en(data)        (0x00000004&((data)<<2))
#define DOWN_SAMPLE_CONTROL_FOR_PLAYBACK_downsample_en(data)          (0x00000002&((data)<<1))
#define DOWN_SAMPLE_CONTROL_FOR_PLAYBACK_down_rate(data)              (0x00000001&(data))
#define DOWN_SAMPLE_CONTROL_FOR_PLAYBACK_get_fifo_ch7_source(data)    ((0xC0000000&(data))>>30)
#define DOWN_SAMPLE_CONTROL_FOR_PLAYBACK_get_fifo_ch8_source(data)    ((0x30000000&(data))>>28)
#define DOWN_SAMPLE_CONTROL_FOR_PLAYBACK_get_fifo_ch5_source(data)    ((0x0C000000&(data))>>26)
#define DOWN_SAMPLE_CONTROL_FOR_PLAYBACK_get_fifo_ch6_source(data)    ((0x03000000&(data))>>24)
#define DOWN_SAMPLE_CONTROL_FOR_PLAYBACK_get_fifo_ch3_source(data)    ((0x00C00000&(data))>>22)
#define DOWN_SAMPLE_CONTROL_FOR_PLAYBACK_get_fifo_ch4_source(data)    ((0x00300000&(data))>>20)
#define DOWN_SAMPLE_CONTROL_FOR_PLAYBACK_get_fifo_ch1_source(data)    ((0x000C0000&(data))>>18)
#define DOWN_SAMPLE_CONTROL_FOR_PLAYBACK_get_fifo_ch2_source(data)    ((0x00030000&(data))>>16)
#define DOWN_SAMPLE_CONTROL_FOR_PLAYBACK_get_backend_play_en(data)    ((0x00000004&(data))>>2)
#define DOWN_SAMPLE_CONTROL_FOR_PLAYBACK_get_downsample_en(data)      ((0x00000002&(data))>>1)
#define DOWN_SAMPLE_CONTROL_FOR_PLAYBACK_get_down_rate(data)          (0x00000001&(data))


#define DOWN_SAMPLE_FIFO_SOURCE_SEL                                   0x18006554
#define DOWN_SAMPLE_FIFO_SOURCE_SEL_reg_addr                          "0xb8006554"
#define DOWN_SAMPLE_FIFO_SOURCE_SEL_reg                               0xb8006554
#define DOWN_SAMPLE_FIFO_SOURCE_SEL_inst_addr                         "0x0155"
#define DOWN_SAMPLE_FIFO_SOURCE_SEL_inst                              0x0155
#define DOWN_SAMPLE_FIFO_SOURCE_SEL_fifo_ch78_scale_shift             (28)
#define DOWN_SAMPLE_FIFO_SOURCE_SEL_fifo_ch56_scale_shift             (24)
#define DOWN_SAMPLE_FIFO_SOURCE_SEL_fifo_ch34_scale_shift             (20)
#define DOWN_SAMPLE_FIFO_SOURCE_SEL_fifo_ch12_scale_shift             (16)
#define DOWN_SAMPLE_FIFO_SOURCE_SEL_fifo_ch78_sel_shift               (12)
#define DOWN_SAMPLE_FIFO_SOURCE_SEL_fifo_ch56_sel_shift               (8)
#define DOWN_SAMPLE_FIFO_SOURCE_SEL_fifo_ch34_sel_shift               (4)
#define DOWN_SAMPLE_FIFO_SOURCE_SEL_fifo_ch12_sel_shift               (0)
#define DOWN_SAMPLE_FIFO_SOURCE_SEL_fifo_ch78_scale_mask              (0xF0000000)
#define DOWN_SAMPLE_FIFO_SOURCE_SEL_fifo_ch56_scale_mask              (0x0F000000)
#define DOWN_SAMPLE_FIFO_SOURCE_SEL_fifo_ch34_scale_mask              (0x00F00000)
#define DOWN_SAMPLE_FIFO_SOURCE_SEL_fifo_ch12_scale_mask              (0x000F0000)
#define DOWN_SAMPLE_FIFO_SOURCE_SEL_fifo_ch78_sel_mask                (0x0000F000)
#define DOWN_SAMPLE_FIFO_SOURCE_SEL_fifo_ch56_sel_mask                (0x00000F00)
#define DOWN_SAMPLE_FIFO_SOURCE_SEL_fifo_ch34_sel_mask                (0x000000F0)
#define DOWN_SAMPLE_FIFO_SOURCE_SEL_fifo_ch12_sel_mask                (0x0000000F)
#define DOWN_SAMPLE_FIFO_SOURCE_SEL_fifo_ch78_scale(data)             (0xF0000000&((data)<<28))
#define DOWN_SAMPLE_FIFO_SOURCE_SEL_fifo_ch56_scale(data)             (0x0F000000&((data)<<24))
#define DOWN_SAMPLE_FIFO_SOURCE_SEL_fifo_ch34_scale(data)             (0x00F00000&((data)<<20))
#define DOWN_SAMPLE_FIFO_SOURCE_SEL_fifo_ch12_scale(data)             (0x000F0000&((data)<<16))
#define DOWN_SAMPLE_FIFO_SOURCE_SEL_fifo_ch78_sel(data)               (0x0000F000&((data)<<12))
#define DOWN_SAMPLE_FIFO_SOURCE_SEL_fifo_ch56_sel(data)               (0x00000F00&((data)<<8))
#define DOWN_SAMPLE_FIFO_SOURCE_SEL_fifo_ch34_sel(data)               (0x000000F0&((data)<<4))
#define DOWN_SAMPLE_FIFO_SOURCE_SEL_fifo_ch12_sel(data)               (0x0000000F&(data))
#define DOWN_SAMPLE_FIFO_SOURCE_SEL_get_fifo_ch78_scale(data)         ((0xF0000000&(data))>>28)
#define DOWN_SAMPLE_FIFO_SOURCE_SEL_get_fifo_ch56_scale(data)         ((0x0F000000&(data))>>24)
#define DOWN_SAMPLE_FIFO_SOURCE_SEL_get_fifo_ch34_scale(data)         ((0x00F00000&(data))>>20)
#define DOWN_SAMPLE_FIFO_SOURCE_SEL_get_fifo_ch12_scale(data)         ((0x000F0000&(data))>>16)
#define DOWN_SAMPLE_FIFO_SOURCE_SEL_get_fifo_ch78_sel(data)           ((0x0000F000&(data))>>12)
#define DOWN_SAMPLE_FIFO_SOURCE_SEL_get_fifo_ch56_sel(data)           ((0x00000F00&(data))>>8)
#define DOWN_SAMPLE_FIFO_SOURCE_SEL_get_fifo_ch34_sel(data)           ((0x000000F0&(data))>>4)
#define DOWN_SAMPLE_FIFO_SOURCE_SEL_get_fifo_ch12_sel(data)           (0x0000000F&(data))


#define DOWN_SAMPLE_MBIST_RECODING                                    0x18006558
#define DOWN_SAMPLE_MBIST_RECODING_reg_addr                           "0xb8006558"
#define DOWN_SAMPLE_MBIST_RECODING_reg                                0xb8006558
#define DOWN_SAMPLE_MBIST_RECODING_inst_addr                          "0x0156"
#define DOWN_SAMPLE_MBIST_RECODING_inst                               0x0156
#define DOWN_SAMPLE_MBIST_RECODING_dummy18006558_31_14_shift          (14)
#define DOWN_SAMPLE_MBIST_RECODING_playback_dvse_0_shift              (13)
#define DOWN_SAMPLE_MBIST_RECODING_playback_dvs_0_shift               (9)
#define DOWN_SAMPLE_MBIST_RECODING_playback_drf_start_pause_shift     (8)
#define DOWN_SAMPLE_MBIST_RECODING_playback_drf_test_resume_shift     (7)
#define DOWN_SAMPLE_MBIST_RECODING_playback_drf_bist_mode_shift       (6)
#define DOWN_SAMPLE_MBIST_RECODING_playback_drf_bist_done_shift       (5)
#define DOWN_SAMPLE_MBIST_RECODING_playback_drf_bist_fail_shift       (4)
#define DOWN_SAMPLE_MBIST_RECODING_playback_bist_rstn_shift           (3)
#define DOWN_SAMPLE_MBIST_RECODING_playback_bist_mode_shift           (2)
#define DOWN_SAMPLE_MBIST_RECODING_playback_bist_done_shift           (1)
#define DOWN_SAMPLE_MBIST_RECODING_playback_bist_fail_shift           (0)
#define DOWN_SAMPLE_MBIST_RECODING_dummy18006558_31_14_mask           (0xFFFFC000)
#define DOWN_SAMPLE_MBIST_RECODING_playback_dvse_0_mask               (0x00002000)
#define DOWN_SAMPLE_MBIST_RECODING_playback_dvs_0_mask                (0x00001E00)
#define DOWN_SAMPLE_MBIST_RECODING_playback_drf_start_pause_mask      (0x00000100)
#define DOWN_SAMPLE_MBIST_RECODING_playback_drf_test_resume_mask      (0x00000080)
#define DOWN_SAMPLE_MBIST_RECODING_playback_drf_bist_mode_mask        (0x00000040)
#define DOWN_SAMPLE_MBIST_RECODING_playback_drf_bist_done_mask        (0x00000020)
#define DOWN_SAMPLE_MBIST_RECODING_playback_drf_bist_fail_mask        (0x00000010)
#define DOWN_SAMPLE_MBIST_RECODING_playback_bist_rstn_mask            (0x00000008)
#define DOWN_SAMPLE_MBIST_RECODING_playback_bist_mode_mask            (0x00000004)
#define DOWN_SAMPLE_MBIST_RECODING_playback_bist_done_mask            (0x00000002)
#define DOWN_SAMPLE_MBIST_RECODING_playback_bist_fail_mask            (0x00000001)
#define DOWN_SAMPLE_MBIST_RECODING_dummy18006558_31_14(data)          (0xFFFFC000&((data)<<14))
#define DOWN_SAMPLE_MBIST_RECODING_playback_dvse_0(data)              (0x00002000&((data)<<13))
#define DOWN_SAMPLE_MBIST_RECODING_playback_dvs_0(data)               (0x00001E00&((data)<<9))
#define DOWN_SAMPLE_MBIST_RECODING_playback_drf_start_pause(data)     (0x00000100&((data)<<8))
#define DOWN_SAMPLE_MBIST_RECODING_playback_drf_test_resume(data)     (0x00000080&((data)<<7))
#define DOWN_SAMPLE_MBIST_RECODING_playback_drf_bist_mode(data)       (0x00000040&((data)<<6))
#define DOWN_SAMPLE_MBIST_RECODING_playback_drf_bist_done(data)       (0x00000020&((data)<<5))
#define DOWN_SAMPLE_MBIST_RECODING_playback_drf_bist_fail(data)       (0x00000010&((data)<<4))
#define DOWN_SAMPLE_MBIST_RECODING_playback_bist_rstn(data)           (0x00000008&((data)<<3))
#define DOWN_SAMPLE_MBIST_RECODING_playback_bist_mode(data)           (0x00000004&((data)<<2))
#define DOWN_SAMPLE_MBIST_RECODING_playback_bist_done(data)           (0x00000002&((data)<<1))
#define DOWN_SAMPLE_MBIST_RECODING_playback_bist_fail(data)           (0x00000001&(data))
#define DOWN_SAMPLE_MBIST_RECODING_get_dummy18006558_31_14(data)      ((0xFFFFC000&(data))>>14)
#define DOWN_SAMPLE_MBIST_RECODING_get_playback_dvse_0(data)          ((0x00002000&(data))>>13)
#define DOWN_SAMPLE_MBIST_RECODING_get_playback_dvs_0(data)           ((0x00001E00&(data))>>9)
#define DOWN_SAMPLE_MBIST_RECODING_get_playback_drf_start_pause(data) ((0x00000100&(data))>>8)
#define DOWN_SAMPLE_MBIST_RECODING_get_playback_drf_test_resume(data) ((0x00000080&(data))>>7)
#define DOWN_SAMPLE_MBIST_RECODING_get_playback_drf_bist_mode(data)   ((0x00000040&(data))>>6)
#define DOWN_SAMPLE_MBIST_RECODING_get_playback_drf_bist_done(data)   ((0x00000020&(data))>>5)
#define DOWN_SAMPLE_MBIST_RECODING_get_playback_drf_bist_fail(data)   ((0x00000010&(data))>>4)
#define DOWN_SAMPLE_MBIST_RECODING_get_playback_bist_rstn(data)       ((0x00000008&(data))>>3)
#define DOWN_SAMPLE_MBIST_RECODING_get_playback_bist_mode(data)       ((0x00000004&(data))>>2)
#define DOWN_SAMPLE_MBIST_RECODING_get_playback_bist_done(data)       ((0x00000002&(data))>>1)
#define DOWN_SAMPLE_MBIST_RECODING_get_playback_bist_fail(data)       (0x00000001&(data))


#define ADMA_CSR                                                      0x18006600
#define ADMA_CSR_reg_addr                                             "0xb8006600"
#define ADMA_CSR_reg                                                  0xb8006600
#define ADMA_CSR_inst_addr                                            "0x0180"
#define ADMA_CSR_inst                                                 0x0180
#define ADMA_CSR_dma_wr_src_sel_shift                                 (30)
#define ADMA_CSR_dma_output_src_sel_shift                             (28)
#define ADMA_CSR_dma_w_format_shift                                   (27)
#define ADMA_CSR_dma_r_format_shift                                   (26)
#define ADMA_CSR_hbr_wr_channel_no_shift                              (20)
#define ADMA_CSR_wr_channel_no_shift                                  (17)
#define ADMA_CSR_aidmatype_shift                                      (16)
#define ADMA_CSR_rd_channel_no_shift                                  (13)
#define ADMA_CSR_aodmatype_shift                                      (12)
#define ADMA_CSR_dma_mode_shift                                       (11)
#define ADMA_CSR_int_rd_en_shift                                      (10)
#define ADMA_CSR_int_wr_en_shift                                      (9)
#define ADMA_CSR_dma_int_en_shift                                     (8)
#define ADMA_CSR_dma_soft_rd_rst_shift                                (7)
#define ADMA_CSR_dma_soft_wr_rst_shift                                (6)
#define ADMA_CSR_dma_read_enable_shift                                (5)
#define ADMA_CSR_dma_write_enable_shift                               (4)
#define ADMA_CSR_overflow_dma_status_shift                            (3)
#define ADMA_CSR_unflow_dma_status_shift                              (2)
#define ADMA_CSR_wr_intr_dma_status_shift                             (1)
#define ADMA_CSR_rd_intr_dma_status_shift                             (0)
#define ADMA_CSR_dma_wr_src_sel_mask                                  (0xC0000000)
#define ADMA_CSR_dma_output_src_sel_mask                              (0x30000000)
#define ADMA_CSR_dma_w_format_mask                                    (0x08000000)
#define ADMA_CSR_dma_r_format_mask                                    (0x04000000)
#define ADMA_CSR_hbr_wr_channel_no_mask                               (0x00300000)
#define ADMA_CSR_wr_channel_no_mask                                   (0x000E0000)
#define ADMA_CSR_aidmatype_mask                                       (0x00010000)
#define ADMA_CSR_rd_channel_no_mask                                   (0x0000E000)
#define ADMA_CSR_aodmatype_mask                                       (0x00001000)
#define ADMA_CSR_dma_mode_mask                                        (0x00000800)
#define ADMA_CSR_int_rd_en_mask                                       (0x00000400)
#define ADMA_CSR_int_wr_en_mask                                       (0x00000200)
#define ADMA_CSR_dma_int_en_mask                                      (0x00000100)
#define ADMA_CSR_dma_soft_rd_rst_mask                                 (0x00000080)
#define ADMA_CSR_dma_soft_wr_rst_mask                                 (0x00000040)
#define ADMA_CSR_dma_read_enable_mask                                 (0x00000020)
#define ADMA_CSR_dma_write_enable_mask                                (0x00000010)
#define ADMA_CSR_overflow_dma_status_mask                             (0x00000008)
#define ADMA_CSR_unflow_dma_status_mask                               (0x00000004)
#define ADMA_CSR_wr_intr_dma_status_mask                              (0x00000002)
#define ADMA_CSR_rd_intr_dma_status_mask                              (0x00000001)
#define ADMA_CSR_dma_wr_src_sel(data)                                 (0xC0000000&((data)<<30))
#define ADMA_CSR_dma_output_src_sel(data)                             (0x30000000&((data)<<28))
#define ADMA_CSR_dma_w_format(data)                                   (0x08000000&((data)<<27))
#define ADMA_CSR_dma_r_format(data)                                   (0x04000000&((data)<<26))
#define ADMA_CSR_hbr_wr_channel_no(data)                              (0x00300000&((data)<<20))
#define ADMA_CSR_wr_channel_no(data)                                  (0x000E0000&((data)<<17))
#define ADMA_CSR_aidmatype(data)                                      (0x00010000&((data)<<16))
#define ADMA_CSR_rd_channel_no(data)                                  (0x0000E000&((data)<<13))
#define ADMA_CSR_aodmatype(data)                                      (0x00001000&((data)<<12))
#define ADMA_CSR_dma_mode(data)                                       (0x00000800&((data)<<11))
#define ADMA_CSR_int_rd_en(data)                                      (0x00000400&((data)<<10))
#define ADMA_CSR_int_wr_en(data)                                      (0x00000200&((data)<<9))
#define ADMA_CSR_dma_int_en(data)                                     (0x00000100&((data)<<8))
#define ADMA_CSR_dma_soft_rd_rst(data)                                (0x00000080&((data)<<7))
#define ADMA_CSR_dma_soft_wr_rst(data)                                (0x00000040&((data)<<6))
#define ADMA_CSR_dma_read_enable(data)                                (0x00000020&((data)<<5))
#define ADMA_CSR_dma_write_enable(data)                               (0x00000010&((data)<<4))
#define ADMA_CSR_overflow_dma_status(data)                            (0x00000008&((data)<<3))
#define ADMA_CSR_unflow_dma_status(data)                              (0x00000004&((data)<<2))
#define ADMA_CSR_wr_intr_dma_status(data)                             (0x00000002&((data)<<1))
#define ADMA_CSR_rd_intr_dma_status(data)                             (0x00000001&(data))
#define ADMA_CSR_get_dma_wr_src_sel(data)                             ((0xC0000000&(data))>>30)
#define ADMA_CSR_get_dma_output_src_sel(data)                         ((0x30000000&(data))>>28)
#define ADMA_CSR_get_dma_w_format(data)                               ((0x08000000&(data))>>27)
#define ADMA_CSR_get_dma_r_format(data)                               ((0x04000000&(data))>>26)
#define ADMA_CSR_get_hbr_wr_channel_no(data)                          ((0x00300000&(data))>>20)
#define ADMA_CSR_get_wr_channel_no(data)                              ((0x000E0000&(data))>>17)
#define ADMA_CSR_get_aidmatype(data)                                  ((0x00010000&(data))>>16)
#define ADMA_CSR_get_rd_channel_no(data)                              ((0x0000E000&(data))>>13)
#define ADMA_CSR_get_aodmatype(data)                                  ((0x00001000&(data))>>12)
#define ADMA_CSR_get_dma_mode(data)                                   ((0x00000800&(data))>>11)
#define ADMA_CSR_get_int_rd_en(data)                                  ((0x00000400&(data))>>10)
#define ADMA_CSR_get_int_wr_en(data)                                  ((0x00000200&(data))>>9)
#define ADMA_CSR_get_dma_int_en(data)                                 ((0x00000100&(data))>>8)
#define ADMA_CSR_get_dma_soft_rd_rst(data)                            ((0x00000080&(data))>>7)
#define ADMA_CSR_get_dma_soft_wr_rst(data)                            ((0x00000040&(data))>>6)
#define ADMA_CSR_get_dma_read_enable(data)                            ((0x00000020&(data))>>5)
#define ADMA_CSR_get_dma_write_enable(data)                           ((0x00000010&(data))>>4)
#define ADMA_CSR_get_overflow_dma_status(data)                        ((0x00000008&(data))>>3)
#define ADMA_CSR_get_unflow_dma_status(data)                          ((0x00000004&(data))>>2)
#define ADMA_CSR_get_wr_intr_dma_status(data)                         ((0x00000002&(data))>>1)
#define ADMA_CSR_get_rd_intr_dma_status(data)                         (0x00000001&(data))


#define ADMA_WCONF                                                    0x18006604
#define ADMA_WCONF_reg_addr                                           "0xb8006604"
#define ADMA_WCONF_reg                                                0xb8006604
#define ADMA_WCONF_inst_addr                                          "0x0181"
#define ADMA_WCONF_inst                                               0x0181
#define ADMA_WCONF_avail_length_shift                                 (16)
#define ADMA_WCONF_wr_intr_point_shift                                (0)
#define ADMA_WCONF_avail_length_mask                                  (0x7FFF0000)
#define ADMA_WCONF_wr_intr_point_mask                                 (0x00007FFF)
#define ADMA_WCONF_avail_length(data)                                 (0x7FFF0000&((data)<<16))
#define ADMA_WCONF_wr_intr_point(data)                                (0x00007FFF&(data))
#define ADMA_WCONF_get_avail_length(data)                             ((0x7FFF0000&(data))>>16)
#define ADMA_WCONF_get_wr_intr_point(data)                            (0x00007FFF&(data))


#define ADMA_WSADR0                                                   0x18006608
#define ADMA_WSADR0_reg_addr                                          "0xb8006608"
#define ADMA_WSADR0_reg                                               0xb8006608
#define ADMA_WSADR0_inst_addr                                         "0x0182"
#define ADMA_WSADR0_inst                                              0x0182
#define ADMA_WSADR0_wr_start_addr0_shift                              (6)
#define ADMA_WSADR0_wr_start_addr0_mask                               (0xFFFFFFC0)
#define ADMA_WSADR0_wr_start_addr0(data)                              (0xFFFFFFC0&((data)<<6))
#define ADMA_WSADR0_get_wr_start_addr0(data)                          ((0xFFFFFFC0&(data))>>6)


#define ADMA_WSADR1                                                   0x1800660c
#define ADMA_WSADR1_reg_addr                                          "0xb800660c"
#define ADMA_WSADR1_reg                                               0xb800660c
#define ADMA_WSADR1_inst_addr                                         "0x0183"
#define ADMA_WSADR1_inst                                              0x0183
#define ADMA_WSADR1_wr_start_addr1_shift                              (6)
#define ADMA_WSADR1_wr_start_addr1_mask                               (0xFFFFFFC0)
#define ADMA_WSADR1_wr_start_addr1(data)                              (0xFFFFFFC0&((data)<<6))
#define ADMA_WSADR1_get_wr_start_addr1(data)                          ((0xFFFFFFC0&(data))>>6)


#define ADMA_WSADR2                                                   0x18006610
#define ADMA_WSADR2_reg_addr                                          "0xb8006610"
#define ADMA_WSADR2_reg                                               0xb8006610
#define ADMA_WSADR2_inst_addr                                         "0x0184"
#define ADMA_WSADR2_inst                                              0x0184
#define ADMA_WSADR2_wr_start_addr2_shift                              (6)
#define ADMA_WSADR2_wr_start_addr2_mask                               (0xFFFFFFC0)
#define ADMA_WSADR2_wr_start_addr2(data)                              (0xFFFFFFC0&((data)<<6))
#define ADMA_WSADR2_get_wr_start_addr2(data)                          ((0xFFFFFFC0&(data))>>6)


#define ADMA_WSADR3                                                   0x18006614
#define ADMA_WSADR3_reg_addr                                          "0xb8006614"
#define ADMA_WSADR3_reg                                               0xb8006614
#define ADMA_WSADR3_inst_addr                                         "0x0185"
#define ADMA_WSADR3_inst                                              0x0185
#define ADMA_WSADR3_wr_start_addr3_shift                              (6)
#define ADMA_WSADR3_wr_start_addr3_mask                               (0xFFFFFFC0)
#define ADMA_WSADR3_wr_start_addr3(data)                              (0xFFFFFFC0&((data)<<6))
#define ADMA_WSADR3_get_wr_start_addr3(data)                          ((0xFFFFFFC0&(data))>>6)


#define ADMA_WSADR4                                                   0x18006618
#define ADMA_WSADR4_reg_addr                                          "0xb8006618"
#define ADMA_WSADR4_reg                                               0xb8006618
#define ADMA_WSADR4_inst_addr                                         "0x0186"
#define ADMA_WSADR4_inst                                              0x0186
#define ADMA_WSADR4_wr_start_addr4_shift                              (6)
#define ADMA_WSADR4_wr_start_addr4_mask                               (0xFFFFFFC0)
#define ADMA_WSADR4_wr_start_addr4(data)                              (0xFFFFFFC0&((data)<<6))
#define ADMA_WSADR4_get_wr_start_addr4(data)                          ((0xFFFFFFC0&(data))>>6)


#define ADMA_WSADR5                                                   0x1800661c
#define ADMA_WSADR5_reg_addr                                          "0xb800661c"
#define ADMA_WSADR5_reg                                               0xb800661c
#define ADMA_WSADR5_inst_addr                                         "0x0187"
#define ADMA_WSADR5_inst                                              0x0187
#define ADMA_WSADR5_wr_start_addr5_shift                              (6)
#define ADMA_WSADR5_wr_start_addr5_mask                               (0xFFFFFFC0)
#define ADMA_WSADR5_wr_start_addr5(data)                              (0xFFFFFFC0&((data)<<6))
#define ADMA_WSADR5_get_wr_start_addr5(data)                          ((0xFFFFFFC0&(data))>>6)


#define ADMA_WSADR6                                                   0x18006620
#define ADMA_WSADR6_reg_addr                                          "0xb8006620"
#define ADMA_WSADR6_reg                                               0xb8006620
#define ADMA_WSADR6_inst_addr                                         "0x0188"
#define ADMA_WSADR6_inst                                              0x0188
#define ADMA_WSADR6_wr_start_addr6_shift                              (6)
#define ADMA_WSADR6_wr_start_addr6_mask                               (0xFFFFFFC0)
#define ADMA_WSADR6_wr_start_addr6(data)                              (0xFFFFFFC0&((data)<<6))
#define ADMA_WSADR6_get_wr_start_addr6(data)                          ((0xFFFFFFC0&(data))>>6)


#define ADMA_WSADR7                                                   0x18006624
#define ADMA_WSADR7_reg_addr                                          "0xb8006624"
#define ADMA_WSADR7_reg                                               0xb8006624
#define ADMA_WSADR7_inst_addr                                         "0x0189"
#define ADMA_WSADR7_inst                                              0x0189
#define ADMA_WSADR7_wr_start_addr7_shift                              (6)
#define ADMA_WSADR7_wr_start_addr7_mask                               (0xFFFFFFC0)
#define ADMA_WSADR7_wr_start_addr7(data)                              (0xFFFFFFC0&((data)<<6))
#define ADMA_WSADR7_get_wr_start_addr7(data)                          ((0xFFFFFFC0&(data))>>6)


#define ADMA_RCONF                                                    0x18006628
#define ADMA_RCONF_reg_addr                                           "0xb8006628"
#define ADMA_RCONF_reg                                                0xb8006628
#define ADMA_RCONF_inst_addr                                          "0x018A"
#define ADMA_RCONF_inst                                               0x018A
#define ADMA_RCONF_read_length_shift                                  (16)
#define ADMA_RCONF_read_intr_point_shift                              (0)
#define ADMA_RCONF_read_length_mask                                   (0x7FFF0000)
#define ADMA_RCONF_read_intr_point_mask                               (0x00007FFF)
#define ADMA_RCONF_read_length(data)                                  (0x7FFF0000&((data)<<16))
#define ADMA_RCONF_read_intr_point(data)                              (0x00007FFF&(data))
#define ADMA_RCONF_get_read_length(data)                              ((0x7FFF0000&(data))>>16)
#define ADMA_RCONF_get_read_intr_point(data)                          (0x00007FFF&(data))


#define ADMA_RSADR0                                                   0x1800662c
#define ADMA_RSADR0_reg_addr                                          "0xb800662c"
#define ADMA_RSADR0_reg                                               0xb800662c
#define ADMA_RSADR0_inst_addr                                         "0x018B"
#define ADMA_RSADR0_inst                                              0x018B
#define ADMA_RSADR0_rd_start_addr0_shift                              (6)
#define ADMA_RSADR0_rd_start_addr0_mask                               (0xFFFFFFC0)
#define ADMA_RSADR0_rd_start_addr0(data)                              (0xFFFFFFC0&((data)<<6))
#define ADMA_RSADR0_get_rd_start_addr0(data)                          ((0xFFFFFFC0&(data))>>6)


#define ADMA_RSADR1                                                   0x18006630
#define ADMA_RSADR1_reg_addr                                          "0xb8006630"
#define ADMA_RSADR1_reg                                               0xb8006630
#define ADMA_RSADR1_inst_addr                                         "0x018C"
#define ADMA_RSADR1_inst                                              0x018C
#define ADMA_RSADR1_rd_start_addr1_shift                              (6)
#define ADMA_RSADR1_rd_start_addr1_mask                               (0xFFFFFFC0)
#define ADMA_RSADR1_rd_start_addr1(data)                              (0xFFFFFFC0&((data)<<6))
#define ADMA_RSADR1_get_rd_start_addr1(data)                          ((0xFFFFFFC0&(data))>>6)


#define ADMA_RSADR2                                                   0x18006634
#define ADMA_RSADR2_reg_addr                                          "0xb8006634"
#define ADMA_RSADR2_reg                                               0xb8006634
#define ADMA_RSADR2_inst_addr                                         "0x018D"
#define ADMA_RSADR2_inst                                              0x018D
#define ADMA_RSADR2_rd_start_addr2_shift                              (6)
#define ADMA_RSADR2_rd_start_addr2_mask                               (0xFFFFFFC0)
#define ADMA_RSADR2_rd_start_addr2(data)                              (0xFFFFFFC0&((data)<<6))
#define ADMA_RSADR2_get_rd_start_addr2(data)                          ((0xFFFFFFC0&(data))>>6)


#define ADMA_RSADR3                                                   0x18006638
#define ADMA_RSADR3_reg_addr                                          "0xb8006638"
#define ADMA_RSADR3_reg                                               0xb8006638
#define ADMA_RSADR3_inst_addr                                         "0x018E"
#define ADMA_RSADR3_inst                                              0x018E
#define ADMA_RSADR3_rd_start_addr3_shift                              (6)
#define ADMA_RSADR3_rd_start_addr3_mask                               (0xFFFFFFC0)
#define ADMA_RSADR3_rd_start_addr3(data)                              (0xFFFFFFC0&((data)<<6))
#define ADMA_RSADR3_get_rd_start_addr3(data)                          ((0xFFFFFFC0&(data))>>6)


#define ADMA_RSADR4                                                   0x1800663c
#define ADMA_RSADR4_reg_addr                                          "0xb800663c"
#define ADMA_RSADR4_reg                                               0xb800663c
#define ADMA_RSADR4_inst_addr                                         "0x018F"
#define ADMA_RSADR4_inst                                              0x018F
#define ADMA_RSADR4_rd_start_addr4_shift                              (6)
#define ADMA_RSADR4_rd_start_addr4_mask                               (0xFFFFFFC0)
#define ADMA_RSADR4_rd_start_addr4(data)                              (0xFFFFFFC0&((data)<<6))
#define ADMA_RSADR4_get_rd_start_addr4(data)                          ((0xFFFFFFC0&(data))>>6)


#define ADMA_RSADR5                                                   0x18006640
#define ADMA_RSADR5_reg_addr                                          "0xb8006640"
#define ADMA_RSADR5_reg                                               0xb8006640
#define ADMA_RSADR5_inst_addr                                         "0x0190"
#define ADMA_RSADR5_inst                                              0x0190
#define ADMA_RSADR5_rd_start_addr5_shift                              (6)
#define ADMA_RSADR5_rd_start_addr5_mask                               (0xFFFFFFC0)
#define ADMA_RSADR5_rd_start_addr5(data)                              (0xFFFFFFC0&((data)<<6))
#define ADMA_RSADR5_get_rd_start_addr5(data)                          ((0xFFFFFFC0&(data))>>6)


#define ADMA_RSADR6                                                   0x18006644
#define ADMA_RSADR6_reg_addr                                          "0xb8006644"
#define ADMA_RSADR6_reg                                               0xb8006644
#define ADMA_RSADR6_inst_addr                                         "0x0191"
#define ADMA_RSADR6_inst                                              0x0191
#define ADMA_RSADR6_rd_start_addr6_shift                              (6)
#define ADMA_RSADR6_rd_start_addr6_mask                               (0xFFFFFFC0)
#define ADMA_RSADR6_rd_start_addr6(data)                              (0xFFFFFFC0&((data)<<6))
#define ADMA_RSADR6_get_rd_start_addr6(data)                          ((0xFFFFFFC0&(data))>>6)


#define ADMA_RSADR7                                                   0x18006648
#define ADMA_RSADR7_reg_addr                                          "0xb8006648"
#define ADMA_RSADR7_reg                                               0xb8006648
#define ADMA_RSADR7_inst_addr                                         "0x0192"
#define ADMA_RSADR7_inst                                              0x0192
#define ADMA_RSADR7_rd_start_addr7_shift                              (6)
#define ADMA_RSADR7_rd_start_addr7_mask                               (0xFFFFFFC0)
#define ADMA_RSADR7_rd_start_addr7(data)                              (0xFFFFFFC0&((data)<<6))
#define ADMA_RSADR7_get_rd_start_addr7(data)                          ((0xFFFFFFC0&(data))>>6)


#define ADMA_CHCONF                                                   0x1800664c
#define ADMA_CHCONF_reg_addr                                          "0xb800664c"
#define ADMA_CHCONF_reg                                               0xb800664c
#define ADMA_CHCONF_inst_addr                                         "0x0193"
#define ADMA_CHCONF_inst                                              0x0193
#define ADMA_CHCONF_wr_buffer_length_shift                            (16)
#define ADMA_CHCONF_rd_buffer_length_shift                            (0)
#define ADMA_CHCONF_wr_buffer_length_mask                             (0x7FFF0000)
#define ADMA_CHCONF_rd_buffer_length_mask                             (0x00007FFF)
#define ADMA_CHCONF_wr_buffer_length(data)                            (0x7FFF0000&((data)<<16))
#define ADMA_CHCONF_rd_buffer_length(data)                            (0x00007FFF&(data))
#define ADMA_CHCONF_get_wr_buffer_length(data)                        ((0x7FFF0000&(data))>>16)
#define ADMA_CHCONF_get_rd_buffer_length(data)                        (0x00007FFF&(data))


#define TSADMA_CSR                                                    0x18006650
#define TSADMA_CSR_reg_addr                                           "0xb8006650"
#define TSADMA_CSR_reg                                                0xb8006650
#define TSADMA_CSR_inst_addr                                          "0x0194"
#define TSADMA_CSR_inst                                               0x0194
#define TSADMA_CSR_ts_dma_wr_src_sel_shift                            (30)
#define TSADMA_CSR_ts_dma_output_src_sel_shift                        (28)
#define TSADMA_CSR_ts_dma_w_format_shift                              (27)
#define TSADMA_CSR_ts_dma_r_format_shift                              (26)
#define TSADMA_CSR_ts_hbr_wr_channel_no_shift                         (20)
#define TSADMA_CSR_ts_wr_channel_no_shift                             (17)
#define TSADMA_CSR_ts_aidmatype_shift                                 (16)
#define TSADMA_CSR_ts_rd_channel_no_shift                             (13)
#define TSADMA_CSR_ts_aodmatype_shift                                 (12)
#define TSADMA_CSR_ts_dma_mode_shift                                  (11)
#define TSADMA_CSR_ts_int_rd_en_shift                                 (10)
#define TSADMA_CSR_ts_int_wr_en_shift                                 (9)
#define TSADMA_CSR_ts_dma_int_en_shift                                (8)
#define TSADMA_CSR_ts_dma_soft_rd_rst_shift                           (7)
#define TSADMA_CSR_ts_dma_soft_wr_rst_shift                           (6)
#define TSADMA_CSR_ts_dma_read_enable_shift                           (5)
#define TSADMA_CSR_ts_dma_write_enable_shift                          (4)
#define TSADMA_CSR_ts_overflow_dma_status_shift                       (3)
#define TSADMA_CSR_ts_unflow_dma_status_shift                         (2)
#define TSADMA_CSR_ts_wr_intr_dma_status_shift                        (1)
#define TSADMA_CSR_ts_rd_intr_dma_status_shift                        (0)
#define TSADMA_CSR_ts_dma_wr_src_sel_mask                             (0xC0000000)
#define TSADMA_CSR_ts_dma_output_src_sel_mask                         (0x30000000)
#define TSADMA_CSR_ts_dma_w_format_mask                               (0x08000000)
#define TSADMA_CSR_ts_dma_r_format_mask                               (0x04000000)
#define TSADMA_CSR_ts_hbr_wr_channel_no_mask                          (0x00300000)
#define TSADMA_CSR_ts_wr_channel_no_mask                              (0x000E0000)
#define TSADMA_CSR_ts_aidmatype_mask                                  (0x00010000)
#define TSADMA_CSR_ts_rd_channel_no_mask                              (0x0000E000)
#define TSADMA_CSR_ts_aodmatype_mask                                  (0x00001000)
#define TSADMA_CSR_ts_dma_mode_mask                                   (0x00000800)
#define TSADMA_CSR_ts_int_rd_en_mask                                  (0x00000400)
#define TSADMA_CSR_ts_int_wr_en_mask                                  (0x00000200)
#define TSADMA_CSR_ts_dma_int_en_mask                                 (0x00000100)
#define TSADMA_CSR_ts_dma_soft_rd_rst_mask                            (0x00000080)
#define TSADMA_CSR_ts_dma_soft_wr_rst_mask                            (0x00000040)
#define TSADMA_CSR_ts_dma_read_enable_mask                            (0x00000020)
#define TSADMA_CSR_ts_dma_write_enable_mask                           (0x00000010)
#define TSADMA_CSR_ts_overflow_dma_status_mask                        (0x00000008)
#define TSADMA_CSR_ts_unflow_dma_status_mask                          (0x00000004)
#define TSADMA_CSR_ts_wr_intr_dma_status_mask                         (0x00000002)
#define TSADMA_CSR_ts_rd_intr_dma_status_mask                         (0x00000001)
#define TSADMA_CSR_ts_dma_wr_src_sel(data)                            (0xC0000000&((data)<<30))
#define TSADMA_CSR_ts_dma_output_src_sel(data)                        (0x30000000&((data)<<28))
#define TSADMA_CSR_ts_dma_w_format(data)                              (0x08000000&((data)<<27))
#define TSADMA_CSR_ts_dma_r_format(data)                              (0x04000000&((data)<<26))
#define TSADMA_CSR_ts_hbr_wr_channel_no(data)                         (0x00300000&((data)<<20))
#define TSADMA_CSR_ts_wr_channel_no(data)                             (0x000E0000&((data)<<17))
#define TSADMA_CSR_ts_aidmatype(data)                                 (0x00010000&((data)<<16))
#define TSADMA_CSR_ts_rd_channel_no(data)                             (0x0000E000&((data)<<13))
#define TSADMA_CSR_ts_aodmatype(data)                                 (0x00001000&((data)<<12))
#define TSADMA_CSR_ts_dma_mode(data)                                  (0x00000800&((data)<<11))
#define TSADMA_CSR_ts_int_rd_en(data)                                 (0x00000400&((data)<<10))
#define TSADMA_CSR_ts_int_wr_en(data)                                 (0x00000200&((data)<<9))
#define TSADMA_CSR_ts_dma_int_en(data)                                (0x00000100&((data)<<8))
#define TSADMA_CSR_ts_dma_soft_rd_rst(data)                           (0x00000080&((data)<<7))
#define TSADMA_CSR_ts_dma_soft_wr_rst(data)                           (0x00000040&((data)<<6))
#define TSADMA_CSR_ts_dma_read_enable(data)                           (0x00000020&((data)<<5))
#define TSADMA_CSR_ts_dma_write_enable(data)                          (0x00000010&((data)<<4))
#define TSADMA_CSR_ts_overflow_dma_status(data)                       (0x00000008&((data)<<3))
#define TSADMA_CSR_ts_unflow_dma_status(data)                         (0x00000004&((data)<<2))
#define TSADMA_CSR_ts_wr_intr_dma_status(data)                        (0x00000002&((data)<<1))
#define TSADMA_CSR_ts_rd_intr_dma_status(data)                        (0x00000001&(data))
#define TSADMA_CSR_get_ts_dma_wr_src_sel(data)                        ((0xC0000000&(data))>>30)
#define TSADMA_CSR_get_ts_dma_output_src_sel(data)                    ((0x30000000&(data))>>28)
#define TSADMA_CSR_get_ts_dma_w_format(data)                          ((0x08000000&(data))>>27)
#define TSADMA_CSR_get_ts_dma_r_format(data)                          ((0x04000000&(data))>>26)
#define TSADMA_CSR_get_ts_hbr_wr_channel_no(data)                     ((0x00300000&(data))>>20)
#define TSADMA_CSR_get_ts_wr_channel_no(data)                         ((0x000E0000&(data))>>17)
#define TSADMA_CSR_get_ts_aidmatype(data)                             ((0x00010000&(data))>>16)
#define TSADMA_CSR_get_ts_rd_channel_no(data)                         ((0x0000E000&(data))>>13)
#define TSADMA_CSR_get_ts_aodmatype(data)                             ((0x00001000&(data))>>12)
#define TSADMA_CSR_get_ts_dma_mode(data)                              ((0x00000800&(data))>>11)
#define TSADMA_CSR_get_ts_int_rd_en(data)                             ((0x00000400&(data))>>10)
#define TSADMA_CSR_get_ts_int_wr_en(data)                             ((0x00000200&(data))>>9)
#define TSADMA_CSR_get_ts_dma_int_en(data)                            ((0x00000100&(data))>>8)
#define TSADMA_CSR_get_ts_dma_soft_rd_rst(data)                       ((0x00000080&(data))>>7)
#define TSADMA_CSR_get_ts_dma_soft_wr_rst(data)                       ((0x00000040&(data))>>6)
#define TSADMA_CSR_get_ts_dma_read_enable(data)                       ((0x00000020&(data))>>5)
#define TSADMA_CSR_get_ts_dma_write_enable(data)                      ((0x00000010&(data))>>4)
#define TSADMA_CSR_get_ts_overflow_dma_status(data)                   ((0x00000008&(data))>>3)
#define TSADMA_CSR_get_ts_unflow_dma_status(data)                     ((0x00000004&(data))>>2)
#define TSADMA_CSR_get_ts_wr_intr_dma_status(data)                    ((0x00000002&(data))>>1)
#define TSADMA_CSR_get_ts_rd_intr_dma_status(data)                    (0x00000001&(data))


#define TS_ADMA_WCONF                                                 0x18006654
#define TS_ADMA_WCONF_reg_addr                                        "0xb8006654"
#define TS_ADMA_WCONF_reg                                             0xb8006654
#define TS_ADMA_WCONF_inst_addr                                       "0x0195"
#define TS_ADMA_WCONF_inst                                            0x0195
#define TS_ADMA_WCONF_ts_avail_length_shift                           (16)
#define TS_ADMA_WCONF_ts_wr_intr_point_shift                          (0)
#define TS_ADMA_WCONF_ts_avail_length_mask                            (0x7FFF0000)
#define TS_ADMA_WCONF_ts_wr_intr_point_mask                           (0x00007FFF)
#define TS_ADMA_WCONF_ts_avail_length(data)                           (0x7FFF0000&((data)<<16))
#define TS_ADMA_WCONF_ts_wr_intr_point(data)                          (0x00007FFF&(data))
#define TS_ADMA_WCONF_get_ts_avail_length(data)                       ((0x7FFF0000&(data))>>16)
#define TS_ADMA_WCONF_get_ts_wr_intr_point(data)                      (0x00007FFF&(data))


#define TS_ADMA_WSADR0                                                0x18006658
#define TS_ADMA_WSADR0_reg_addr                                       "0xb8006658"
#define TS_ADMA_WSADR0_reg                                            0xb8006658
#define TS_ADMA_WSADR0_inst_addr                                      "0x0196"
#define TS_ADMA_WSADR0_inst                                           0x0196
#define TS_ADMA_WSADR0_ts_wr_start_addr0_shift                        (6)
#define TS_ADMA_WSADR0_ts_wr_start_addr0_mask                         (0xFFFFFFC0)
#define TS_ADMA_WSADR0_ts_wr_start_addr0(data)                        (0xFFFFFFC0&((data)<<6))
#define TS_ADMA_WSADR0_get_ts_wr_start_addr0(data)                    ((0xFFFFFFC0&(data))>>6)


#define TS_ADMA_WSADR1                                                0x1800665c
#define TS_ADMA_WSADR1_reg_addr                                       "0xb800665c"
#define TS_ADMA_WSADR1_reg                                            0xb800665c
#define TS_ADMA_WSADR1_inst_addr                                      "0x0197"
#define TS_ADMA_WSADR1_inst                                           0x0197
#define TS_ADMA_WSADR1_ts_wr_start_addr1_shift                        (6)
#define TS_ADMA_WSADR1_ts_wr_start_addr1_mask                         (0xFFFFFFC0)
#define TS_ADMA_WSADR1_ts_wr_start_addr1(data)                        (0xFFFFFFC0&((data)<<6))
#define TS_ADMA_WSADR1_get_ts_wr_start_addr1(data)                    ((0xFFFFFFC0&(data))>>6)


#define TS_ADMA_RCONF                                                 0x18006660
#define TS_ADMA_RCONF_reg_addr                                        "0xb8006660"
#define TS_ADMA_RCONF_reg                                             0xb8006660
#define TS_ADMA_RCONF_inst_addr                                       "0x0198"
#define TS_ADMA_RCONF_inst                                            0x0198
#define TS_ADMA_RCONF_ts_read_length_shift                            (16)
#define TS_ADMA_RCONF_ts_read_intr_point_shift                        (0)
#define TS_ADMA_RCONF_ts_read_length_mask                             (0x7FFF0000)
#define TS_ADMA_RCONF_ts_read_intr_point_mask                         (0x00007FFF)
#define TS_ADMA_RCONF_ts_read_length(data)                            (0x7FFF0000&((data)<<16))
#define TS_ADMA_RCONF_ts_read_intr_point(data)                        (0x00007FFF&(data))
#define TS_ADMA_RCONF_get_ts_read_length(data)                        ((0x7FFF0000&(data))>>16)
#define TS_ADMA_RCONF_get_ts_read_intr_point(data)                    (0x00007FFF&(data))


#define TS_ADMA_RSADR0                                                0x18006664
#define TS_ADMA_RSADR0_reg_addr                                       "0xb8006664"
#define TS_ADMA_RSADR0_reg                                            0xb8006664
#define TS_ADMA_RSADR0_inst_addr                                      "0x0199"
#define TS_ADMA_RSADR0_inst                                           0x0199
#define TS_ADMA_RSADR0_ts_rd_start_addr0_shift                        (6)
#define TS_ADMA_RSADR0_ts_rd_start_addr0_mask                         (0xFFFFFFC0)
#define TS_ADMA_RSADR0_ts_rd_start_addr0(data)                        (0xFFFFFFC0&((data)<<6))
#define TS_ADMA_RSADR0_get_ts_rd_start_addr0(data)                    ((0xFFFFFFC0&(data))>>6)


#define TS_ADMA_RSADR1                                                0x18006668
#define TS_ADMA_RSADR1_reg_addr                                       "0xb8006668"
#define TS_ADMA_RSADR1_reg                                            0xb8006668
#define TS_ADMA_RSADR1_inst_addr                                      "0x019A"
#define TS_ADMA_RSADR1_inst                                           0x019A
#define TS_ADMA_RSADR1_ts_rd_start_addr1_shift                        (6)
#define TS_ADMA_RSADR1_ts_rd_start_addr1_mask                         (0xFFFFFFC0)
#define TS_ADMA_RSADR1_ts_rd_start_addr1(data)                        (0xFFFFFFC0&((data)<<6))
#define TS_ADMA_RSADR1_get_ts_rd_start_addr1(data)                    ((0xFFFFFFC0&(data))>>6)


#define TS_ADMA_RSADR2                                                0x1800666c
#define TS_ADMA_RSADR2_reg_addr                                       "0xb800666c"
#define TS_ADMA_RSADR2_reg                                            0xb800666c
#define TS_ADMA_RSADR2_inst_addr                                      "0x019B"
#define TS_ADMA_RSADR2_inst                                           0x019B
#define TS_ADMA_RSADR2_ts_rd_start_addr2_shift                        (6)
#define TS_ADMA_RSADR2_ts_rd_start_addr2_mask                         (0xFFFFFFC0)
#define TS_ADMA_RSADR2_ts_rd_start_addr2(data)                        (0xFFFFFFC0&((data)<<6))
#define TS_ADMA_RSADR2_get_ts_rd_start_addr2(data)                    ((0xFFFFFFC0&(data))>>6)


#define TS_ADMA_CHCONF                                                0x18006670
#define TS_ADMA_CHCONF_reg_addr                                       "0xb8006670"
#define TS_ADMA_CHCONF_reg                                            0xb8006670
#define TS_ADMA_CHCONF_inst_addr                                      "0x019C"
#define TS_ADMA_CHCONF_inst                                           0x019C
#define TS_ADMA_CHCONF_ts_wr_buffer_length_shift                      (16)
#define TS_ADMA_CHCONF_ts_rd_buffer_length_shift                      (0)
#define TS_ADMA_CHCONF_ts_wr_buffer_length_mask                       (0x7FFF0000)
#define TS_ADMA_CHCONF_ts_rd_buffer_length_mask                       (0x00007FFF)
#define TS_ADMA_CHCONF_ts_wr_buffer_length(data)                      (0x7FFF0000&((data)<<16))
#define TS_ADMA_CHCONF_ts_rd_buffer_length(data)                      (0x00007FFF&(data))
#define TS_ADMA_CHCONF_get_ts_wr_buffer_length(data)                  ((0x7FFF0000&(data))>>16)
#define TS_ADMA_CHCONF_get_ts_rd_buffer_length(data)                  (0x00007FFF&(data))


#define TS_DMA_BIST_CONTROL_INDICATE                                  0x18006674
#define TS_DMA_BIST_CONTROL_INDICATE_reg_addr                         "0xb8006674"
#define TS_DMA_BIST_CONTROL_INDICATE_reg                              0xb8006674
#define TS_DMA_BIST_CONTROL_INDICATE_inst_addr                        "0x019D"
#define TS_DMA_BIST_CONTROL_INDICATE_inst                             0x019D
#define TS_DMA_BIST_CONTROL_INDICATE_dvse_0_tsdma_bus_shift           (13)
#define TS_DMA_BIST_CONTROL_INDICATE_dvs_0_tsdma_bus_shift            (9)
#define TS_DMA_BIST_CONTROL_INDICATE_drf_start_pause_tsdma_shift      (8)
#define TS_DMA_BIST_CONTROL_INDICATE_drf_test_resume_tsdma_shift      (7)
#define TS_DMA_BIST_CONTROL_INDICATE_drf_bist_mode_tsdma_shift        (6)
#define TS_DMA_BIST_CONTROL_INDICATE_drf_bist_done_tsdma_shift        (5)
#define TS_DMA_BIST_CONTROL_INDICATE_drf_bist_fail_tsdma_shift        (4)
#define TS_DMA_BIST_CONTROL_INDICATE_bist_mode_tsdma_shift            (3)
#define TS_DMA_BIST_CONTROL_INDICATE_bist_rstn_tsdma_shift            (2)
#define TS_DMA_BIST_CONTROL_INDICATE_bist_done_tsdma_shift            (1)
#define TS_DMA_BIST_CONTROL_INDICATE_bist_fail_tsdma_shift            (0)
#define TS_DMA_BIST_CONTROL_INDICATE_dvse_0_tsdma_bus_mask            (0x00002000)
#define TS_DMA_BIST_CONTROL_INDICATE_dvs_0_tsdma_bus_mask             (0x00001E00)
#define TS_DMA_BIST_CONTROL_INDICATE_drf_start_pause_tsdma_mask       (0x00000100)
#define TS_DMA_BIST_CONTROL_INDICATE_drf_test_resume_tsdma_mask       (0x00000080)
#define TS_DMA_BIST_CONTROL_INDICATE_drf_bist_mode_tsdma_mask         (0x00000040)
#define TS_DMA_BIST_CONTROL_INDICATE_drf_bist_done_tsdma_mask         (0x00000020)
#define TS_DMA_BIST_CONTROL_INDICATE_drf_bist_fail_tsdma_mask         (0x00000010)
#define TS_DMA_BIST_CONTROL_INDICATE_bist_mode_tsdma_mask             (0x00000008)
#define TS_DMA_BIST_CONTROL_INDICATE_bist_rstn_tsdma_mask             (0x00000004)
#define TS_DMA_BIST_CONTROL_INDICATE_bist_done_tsdma_mask             (0x00000002)
#define TS_DMA_BIST_CONTROL_INDICATE_bist_fail_tsdma_mask             (0x00000001)
#define TS_DMA_BIST_CONTROL_INDICATE_dvse_0_tsdma_bus(data)           (0x00002000&((data)<<13))
#define TS_DMA_BIST_CONTROL_INDICATE_dvs_0_tsdma_bus(data)            (0x00001E00&((data)<<9))
#define TS_DMA_BIST_CONTROL_INDICATE_drf_start_pause_tsdma(data)      (0x00000100&((data)<<8))
#define TS_DMA_BIST_CONTROL_INDICATE_drf_test_resume_tsdma(data)      (0x00000080&((data)<<7))
#define TS_DMA_BIST_CONTROL_INDICATE_drf_bist_mode_tsdma(data)        (0x00000040&((data)<<6))
#define TS_DMA_BIST_CONTROL_INDICATE_drf_bist_done_tsdma(data)        (0x00000020&((data)<<5))
#define TS_DMA_BIST_CONTROL_INDICATE_drf_bist_fail_tsdma(data)        (0x00000010&((data)<<4))
#define TS_DMA_BIST_CONTROL_INDICATE_bist_mode_tsdma(data)            (0x00000008&((data)<<3))
#define TS_DMA_BIST_CONTROL_INDICATE_bist_rstn_tsdma(data)            (0x00000004&((data)<<2))
#define TS_DMA_BIST_CONTROL_INDICATE_bist_done_tsdma(data)            (0x00000002&((data)<<1))
#define TS_DMA_BIST_CONTROL_INDICATE_bist_fail_tsdma(data)            (0x00000001&(data))
#define TS_DMA_BIST_CONTROL_INDICATE_get_dvse_0_tsdma_bus(data)       ((0x00002000&(data))>>13)
#define TS_DMA_BIST_CONTROL_INDICATE_get_dvs_0_tsdma_bus(data)        ((0x00001E00&(data))>>9)
#define TS_DMA_BIST_CONTROL_INDICATE_get_drf_start_pause_tsdma(data)  ((0x00000100&(data))>>8)
#define TS_DMA_BIST_CONTROL_INDICATE_get_drf_test_resume_tsdma(data)  ((0x00000080&(data))>>7)
#define TS_DMA_BIST_CONTROL_INDICATE_get_drf_bist_mode_tsdma(data)    ((0x00000040&(data))>>6)
#define TS_DMA_BIST_CONTROL_INDICATE_get_drf_bist_done_tsdma(data)    ((0x00000020&(data))>>5)
#define TS_DMA_BIST_CONTROL_INDICATE_get_drf_bist_fail_tsdma(data)    ((0x00000010&(data))>>4)
#define TS_DMA_BIST_CONTROL_INDICATE_get_bist_mode_tsdma(data)        ((0x00000008&(data))>>3)
#define TS_DMA_BIST_CONTROL_INDICATE_get_bist_rstn_tsdma(data)        ((0x00000004&(data))>>2)
#define TS_DMA_BIST_CONTROL_INDICATE_get_bist_done_tsdma(data)        ((0x00000002&(data))>>1)
#define TS_DMA_BIST_CONTROL_INDICATE_get_bist_fail_tsdma(data)        (0x00000001&(data))


#define AUDIO_DMA_BIST_CONTROL_INDICATE                               0x18006688
#define AUDIO_DMA_BIST_CONTROL_INDICATE_reg_addr                      "0xb8006688"
#define AUDIO_DMA_BIST_CONTROL_INDICATE_reg                           0xb8006688
#define AUDIO_DMA_BIST_CONTROL_INDICATE_inst_addr                     "0x01A2"
#define AUDIO_DMA_BIST_CONTROL_INDICATE_inst                          0x01A2
#define AUDIO_DMA_BIST_CONTROL_INDICATE_dvse_0_aodma_bus_shift        (13)
#define AUDIO_DMA_BIST_CONTROL_INDICATE_dvs_0_aodma_bus_shift         (9)
#define AUDIO_DMA_BIST_CONTROL_INDICATE_drf_start_pause_audiodma_shift  (8)
#define AUDIO_DMA_BIST_CONTROL_INDICATE_drf_test_resume_audiodma_shift  (7)
#define AUDIO_DMA_BIST_CONTROL_INDICATE_drf_bist_mode_audiodma_shift  (6)
#define AUDIO_DMA_BIST_CONTROL_INDICATE_drf_bist_done_audiodma_shift  (5)
#define AUDIO_DMA_BIST_CONTROL_INDICATE_drf_bist_fail_audiodma_shift  (4)
#define AUDIO_DMA_BIST_CONTROL_INDICATE_bist_mode_audiodma_shift      (3)
#define AUDIO_DMA_BIST_CONTROL_INDICATE_bist_rstn_audiodma_shift      (2)
#define AUDIO_DMA_BIST_CONTROL_INDICATE_bist_done_audiodma_shift      (1)
#define AUDIO_DMA_BIST_CONTROL_INDICATE_bist_fail_audiodma_shift      (0)
#define AUDIO_DMA_BIST_CONTROL_INDICATE_dvse_0_aodma_bus_mask         (0x00002000)
#define AUDIO_DMA_BIST_CONTROL_INDICATE_dvs_0_aodma_bus_mask          (0x00001E00)
#define AUDIO_DMA_BIST_CONTROL_INDICATE_drf_start_pause_audiodma_mask (0x00000100)
#define AUDIO_DMA_BIST_CONTROL_INDICATE_drf_test_resume_audiodma_mask (0x00000080)
#define AUDIO_DMA_BIST_CONTROL_INDICATE_drf_bist_mode_audiodma_mask   (0x00000040)
#define AUDIO_DMA_BIST_CONTROL_INDICATE_drf_bist_done_audiodma_mask   (0x00000020)
#define AUDIO_DMA_BIST_CONTROL_INDICATE_drf_bist_fail_audiodma_mask   (0x00000010)
#define AUDIO_DMA_BIST_CONTROL_INDICATE_bist_mode_audiodma_mask       (0x00000008)
#define AUDIO_DMA_BIST_CONTROL_INDICATE_bist_rstn_audiodma_mask       (0x00000004)
#define AUDIO_DMA_BIST_CONTROL_INDICATE_bist_done_audiodma_mask       (0x00000002)
#define AUDIO_DMA_BIST_CONTROL_INDICATE_bist_fail_audiodma_mask       (0x00000001)
#define AUDIO_DMA_BIST_CONTROL_INDICATE_dvse_0_aodma_bus(data)        (0x00002000&((data)<<13))
#define AUDIO_DMA_BIST_CONTROL_INDICATE_dvs_0_aodma_bus(data)         (0x00001E00&((data)<<9))
#define AUDIO_DMA_BIST_CONTROL_INDICATE_drf_start_pause_audiodma(data)  (0x00000100&((data)<<8))
#define AUDIO_DMA_BIST_CONTROL_INDICATE_drf_test_resume_audiodma(data)  (0x00000080&((data)<<7))
#define AUDIO_DMA_BIST_CONTROL_INDICATE_drf_bist_mode_audiodma(data)  (0x00000040&((data)<<6))
#define AUDIO_DMA_BIST_CONTROL_INDICATE_drf_bist_done_audiodma(data)  (0x00000020&((data)<<5))
#define AUDIO_DMA_BIST_CONTROL_INDICATE_drf_bist_fail_audiodma(data)  (0x00000010&((data)<<4))
#define AUDIO_DMA_BIST_CONTROL_INDICATE_bist_mode_audiodma(data)      (0x00000008&((data)<<3))
#define AUDIO_DMA_BIST_CONTROL_INDICATE_bist_rstn_audiodma(data)      (0x00000004&((data)<<2))
#define AUDIO_DMA_BIST_CONTROL_INDICATE_bist_done_audiodma(data)      (0x00000002&((data)<<1))
#define AUDIO_DMA_BIST_CONTROL_INDICATE_bist_fail_audiodma(data)      (0x00000001&(data))
#define AUDIO_DMA_BIST_CONTROL_INDICATE_get_dvse_0_aodma_bus(data)    ((0x00002000&(data))>>13)
#define AUDIO_DMA_BIST_CONTROL_INDICATE_get_dvs_0_aodma_bus(data)     ((0x00001E00&(data))>>9)
#define AUDIO_DMA_BIST_CONTROL_INDICATE_get_drf_start_pause_audiodma(data)  ((0x00000100&(data))>>8)
#define AUDIO_DMA_BIST_CONTROL_INDICATE_get_drf_test_resume_audiodma(data)  ((0x00000080&(data))>>7)
#define AUDIO_DMA_BIST_CONTROL_INDICATE_get_drf_bist_mode_audiodma(data)  ((0x00000040&(data))>>6)
#define AUDIO_DMA_BIST_CONTROL_INDICATE_get_drf_bist_done_audiodma(data)  ((0x00000020&(data))>>5)
#define AUDIO_DMA_BIST_CONTROL_INDICATE_get_drf_bist_fail_audiodma(data)  ((0x00000010&(data))>>4)
#define AUDIO_DMA_BIST_CONTROL_INDICATE_get_bist_mode_audiodma(data)  ((0x00000008&(data))>>3)
#define AUDIO_DMA_BIST_CONTROL_INDICATE_get_bist_rstn_audiodma(data)  ((0x00000004&(data))>>2)
#define AUDIO_DMA_BIST_CONTROL_INDICATE_get_bist_done_audiodma(data)  ((0x00000002&(data))>>1)
#define AUDIO_DMA_BIST_CONTROL_INDICATE_get_bist_fail_audiodma(data)  (0x00000001&(data))


#define TEST_DMA_CONTROL_REGISTER                                     0x1800668c
#define TEST_DMA_CONTROL_REGISTER_reg_addr                            "0xb800668c"
#define TEST_DMA_CONTROL_REGISTER_reg                                 0xb800668c
#define TEST_DMA_CONTROL_REGISTER_inst_addr                           "0x01A3"
#define TEST_DMA_CONTROL_REGISTER_inst                                0x01A3
#define TEST_DMA_CONTROL_REGISTER_test_dma_en_shift                   (12)
#define TEST_DMA_CONTROL_REGISTER_test_dma_rw_mode_shift              (8)
#define TEST_DMA_CONTROL_REGISTER_test_dma_in_sel_shift               (5)
#define TEST_DMA_CONTROL_REGISTER_test_dma_ring_shift                 (4)
#define TEST_DMA_CONTROL_REGISTER_test_dma_over_read_shift            (1)
#define TEST_DMA_CONTROL_REGISTER_test_dma_over_write_shift           (0)
#define TEST_DMA_CONTROL_REGISTER_test_dma_en_mask                    (0x00001000)
#define TEST_DMA_CONTROL_REGISTER_test_dma_rw_mode_mask               (0x00000100)
#define TEST_DMA_CONTROL_REGISTER_test_dma_in_sel_mask                (0x000000E0)
#define TEST_DMA_CONTROL_REGISTER_test_dma_ring_mask                  (0x00000010)
#define TEST_DMA_CONTROL_REGISTER_test_dma_over_read_mask             (0x00000002)
#define TEST_DMA_CONTROL_REGISTER_test_dma_over_write_mask            (0x00000001)
#define TEST_DMA_CONTROL_REGISTER_test_dma_en(data)                   (0x00001000&((data)<<12))
#define TEST_DMA_CONTROL_REGISTER_test_dma_rw_mode(data)              (0x00000100&((data)<<8))
#define TEST_DMA_CONTROL_REGISTER_test_dma_in_sel(data)               (0x000000E0&((data)<<5))
#define TEST_DMA_CONTROL_REGISTER_test_dma_ring(data)                 (0x00000010&((data)<<4))
#define TEST_DMA_CONTROL_REGISTER_test_dma_over_read(data)            (0x00000002&((data)<<1))
#define TEST_DMA_CONTROL_REGISTER_test_dma_over_write(data)           (0x00000001&(data))
#define TEST_DMA_CONTROL_REGISTER_get_test_dma_en(data)               ((0x00001000&(data))>>12)
#define TEST_DMA_CONTROL_REGISTER_get_test_dma_rw_mode(data)          ((0x00000100&(data))>>8)
#define TEST_DMA_CONTROL_REGISTER_get_test_dma_in_sel(data)           ((0x000000E0&(data))>>5)
#define TEST_DMA_CONTROL_REGISTER_get_test_dma_ring(data)             ((0x00000010&(data))>>4)
#define TEST_DMA_CONTROL_REGISTER_get_test_dma_over_read(data)        ((0x00000002&(data))>>1)
#define TEST_DMA_CONTROL_REGISTER_get_test_dma_over_write(data)       (0x00000001&(data))


#define TEST_DMA_START_ADDRESS                                        0x18006690
#define TEST_DMA_START_ADDRESS_reg_addr                               "0xb8006690"
#define TEST_DMA_START_ADDRESS_reg                                    0xb8006690
#define TEST_DMA_START_ADDRESS_inst_addr                              "0x01A4"
#define TEST_DMA_START_ADDRESS_inst                                   0x01A4
#define TEST_DMA_START_ADDRESS_test_dma_start_addr_shift              (5)
#define TEST_DMA_START_ADDRESS_test_dma_start_addr_mask               (0x01FFFFE0)
#define TEST_DMA_START_ADDRESS_test_dma_start_addr(data)              (0x01FFFFE0&((data)<<5))
#define TEST_DMA_START_ADDRESS_get_test_dma_start_addr(data)          ((0x01FFFFE0&(data))>>5)


#define TEST_DMA_STOP_ADDRESS                                         0x18006694
#define TEST_DMA_STOP_ADDRESS_reg_addr                                "0xb8006694"
#define TEST_DMA_STOP_ADDRESS_reg                                     0xb8006694
#define TEST_DMA_STOP_ADDRESS_inst_addr                               "0x01A5"
#define TEST_DMA_STOP_ADDRESS_inst                                    0x01A5
#define TEST_DMA_STOP_ADDRESS_test_dma_stop_addr_shift                (5)
#define TEST_DMA_STOP_ADDRESS_test_dma_stop_addr_mask                 (0x01FFFFE0)
#define TEST_DMA_STOP_ADDRESS_test_dma_stop_addr(data)                (0x01FFFFE0&((data)<<5))
#define TEST_DMA_STOP_ADDRESS_get_test_dma_stop_addr(data)            ((0x01FFFFE0&(data))>>5)


#define TEST_MODE_SELECT                                              0x18006698
#define TEST_MODE_SELECT_reg_addr                                     "0xb8006698"
#define TEST_MODE_SELECT_reg                                          0xb8006698
#define TEST_MODE_SELECT_inst_addr                                    "0x01A6"
#define TEST_MODE_SELECT_inst                                         0x01A6
#define TEST_MODE_SELECT_dummy18006698_31_1_shift                     (1)
#define TEST_MODE_SELECT_dma_sel_shift                                (0)
#define TEST_MODE_SELECT_dummy18006698_31_1_mask                      (0xFFFFFFFE)
#define TEST_MODE_SELECT_dma_sel_mask                                 (0x00000001)
#define TEST_MODE_SELECT_dummy18006698_31_1(data)                     (0xFFFFFFFE&((data)<<1))
#define TEST_MODE_SELECT_dma_sel(data)                                (0x00000001&(data))
#define TEST_MODE_SELECT_get_dummy18006698_31_1(data)                 ((0xFFFFFFFE&(data))>>1)
#define TEST_MODE_SELECT_get_dma_sel(data)                            (0x00000001&(data))


#define TEST_CUR_ADDRESS                                              0x1800669c
#define TEST_CUR_ADDRESS_reg_addr                                     "0xb800669c"
#define TEST_CUR_ADDRESS_reg                                          0xb800669c
#define TEST_CUR_ADDRESS_inst_addr                                    "0x01A7"
#define TEST_CUR_ADDRESS_inst                                         0x01A7
#define TEST_CUR_ADDRESS_test_dma_cur_addr_shift                      (5)
#define TEST_CUR_ADDRESS_test_dma_cur_addr_mask                       (0x01FFFFE0)
#define TEST_CUR_ADDRESS_test_dma_cur_addr(data)                      (0x01FFFFE0&((data)<<5))
#define TEST_CUR_ADDRESS_get_test_dma_cur_addr(data)                  ((0x01FFFFE0&(data))>>5)


#define HW_PROCESS_CONTROL                                            0x18006700
#define HW_PROCESS_CONTROL_reg_addr                                   "0xb8006700"
#define HW_PROCESS_CONTROL_reg                                        0xb8006700
#define HW_PROCESS_CONTROL_inst_addr                                  "0x01C0"
#define HW_PROCESS_CONTROL_inst                                       0x01C0
#define HW_PROCESS_CONTROL_basic_premium_sel_shift                    (15)
#define HW_PROCESS_CONTROL_dvol_enable_shift                          (14)
#define HW_PROCESS_CONTROL_loud_enable_shift                          (13)
#define HW_PROCESS_CONTROL_deq_enable_shift                           (12)
#define HW_PROCESS_CONTROL_spatial_ctrlenable_shift                   (11)
#define HW_PROCESS_CONTROL_auto_volenable_shift                       (10)
#define HW_PROCESS_CONTROL_zcth_shift                                 (4)
#define HW_PROCESS_CONTROL_dvcm_shift                                 (0)
#define HW_PROCESS_CONTROL_basic_premium_sel_mask                     (0x00008000)
#define HW_PROCESS_CONTROL_dvol_enable_mask                           (0x00004000)
#define HW_PROCESS_CONTROL_loud_enable_mask                           (0x00002000)
#define HW_PROCESS_CONTROL_deq_enable_mask                            (0x00001000)
#define HW_PROCESS_CONTROL_spatial_ctrlenable_mask                    (0x00000800)
#define HW_PROCESS_CONTROL_auto_volenable_mask                        (0x00000400)
#define HW_PROCESS_CONTROL_zcth_mask                                  (0x000001F0)
#define HW_PROCESS_CONTROL_dvcm_mask                                  (0x00000003)
#define HW_PROCESS_CONTROL_basic_premium_sel(data)                    (0x00008000&((data)<<15))
#define HW_PROCESS_CONTROL_dvol_enable(data)                          (0x00004000&((data)<<14))
#define HW_PROCESS_CONTROL_loud_enable(data)                          (0x00002000&((data)<<13))
#define HW_PROCESS_CONTROL_deq_enable(data)                           (0x00001000&((data)<<12))
#define HW_PROCESS_CONTROL_spatial_ctrlenable(data)                   (0x00000800&((data)<<11))
#define HW_PROCESS_CONTROL_auto_volenable(data)                       (0x00000400&((data)<<10))
#define HW_PROCESS_CONTROL_zcth(data)                                 (0x000001F0&((data)<<4))
#define HW_PROCESS_CONTROL_dvcm(data)                                 (0x00000003&(data))
#define HW_PROCESS_CONTROL_get_basic_premium_sel(data)                ((0x00008000&(data))>>15)
#define HW_PROCESS_CONTROL_get_dvol_enable(data)                      ((0x00004000&(data))>>14)
#define HW_PROCESS_CONTROL_get_loud_enable(data)                      ((0x00002000&(data))>>13)
#define HW_PROCESS_CONTROL_get_deq_enable(data)                       ((0x00001000&(data))>>12)
#define HW_PROCESS_CONTROL_get_spatial_ctrlenable(data)               ((0x00000800&(data))>>11)
#define HW_PROCESS_CONTROL_get_auto_volenable(data)                   ((0x00000400&(data))>>10)
#define HW_PROCESS_CONTROL_get_zcth(data)                             ((0x000001F0&(data))>>4)
#define HW_PROCESS_CONTROL_get_dvcm(data)                             (0x00000003&(data))


#define DIGITAL_VOLUME_CONTROL_0                                      0x18006704
#define DIGITAL_VOLUME_CONTROL_0_reg_addr                             "0xb8006704"
#define DIGITAL_VOLUME_CONTROL_0_reg                                  0xb8006704
#define DIGITAL_VOLUME_CONTROL_0_inst_addr                            "0x01C1"
#define DIGITAL_VOLUME_CONTROL_0_inst                                 0x01C1
#define DIGITAL_VOLUME_CONTROL_0_dvol_apply_shift                     (31)
#define DIGITAL_VOLUME_CONTROL_0_zcto_shift                           (28)
#define DIGITAL_VOLUME_CONTROL_0_ramp_step_shift                      (26)
#define DIGITAL_VOLUME_CONTROL_0_delay_ctrl_shift                     (16)
#define DIGITAL_VOLUME_CONTROL_0_mute_apply_shift                     (15)
#define DIGITAL_VOLUME_CONTROL_0_zcto_mute_shift                      (12)
#define DIGITAL_VOLUME_CONTROL_0_ramp_step_mute_shift                 (10)
#define DIGITAL_VOLUME_CONTROL_0_delay_ctrl_mute_shift                (0)
#define DIGITAL_VOLUME_CONTROL_0_dvol_apply_mask                      (0x80000000)
#define DIGITAL_VOLUME_CONTROL_0_zcto_mask                            (0x70000000)
#define DIGITAL_VOLUME_CONTROL_0_ramp_step_mask                       (0x0C000000)
#define DIGITAL_VOLUME_CONTROL_0_delay_ctrl_mask                      (0x03FF0000)
#define DIGITAL_VOLUME_CONTROL_0_mute_apply_mask                      (0x00008000)
#define DIGITAL_VOLUME_CONTROL_0_zcto_mute_mask                       (0x00007000)
#define DIGITAL_VOLUME_CONTROL_0_ramp_step_mute_mask                  (0x00000C00)
#define DIGITAL_VOLUME_CONTROL_0_delay_ctrl_mute_mask                 (0x000003FF)
#define DIGITAL_VOLUME_CONTROL_0_dvol_apply(data)                     (0x80000000&((data)<<31))
#define DIGITAL_VOLUME_CONTROL_0_zcto(data)                           (0x70000000&((data)<<28))
#define DIGITAL_VOLUME_CONTROL_0_ramp_step(data)                      (0x0C000000&((data)<<26))
#define DIGITAL_VOLUME_CONTROL_0_delay_ctrl(data)                     (0x03FF0000&((data)<<16))
#define DIGITAL_VOLUME_CONTROL_0_mute_apply(data)                     (0x00008000&((data)<<15))
#define DIGITAL_VOLUME_CONTROL_0_zcto_mute(data)                      (0x00007000&((data)<<12))
#define DIGITAL_VOLUME_CONTROL_0_ramp_step_mute(data)                 (0x00000C00&((data)<<10))
#define DIGITAL_VOLUME_CONTROL_0_delay_ctrl_mute(data)                (0x000003FF&(data))
#define DIGITAL_VOLUME_CONTROL_0_get_dvol_apply(data)                 ((0x80000000&(data))>>31)
#define DIGITAL_VOLUME_CONTROL_0_get_zcto(data)                       ((0x70000000&(data))>>28)
#define DIGITAL_VOLUME_CONTROL_0_get_ramp_step(data)                  ((0x0C000000&(data))>>26)
#define DIGITAL_VOLUME_CONTROL_0_get_delay_ctrl(data)                 ((0x03FF0000&(data))>>16)
#define DIGITAL_VOLUME_CONTROL_0_get_mute_apply(data)                 ((0x00008000&(data))>>15)
#define DIGITAL_VOLUME_CONTROL_0_get_zcto_mute(data)                  ((0x00007000&(data))>>12)
#define DIGITAL_VOLUME_CONTROL_0_get_ramp_step_mute(data)             ((0x00000C00&(data))>>10)
#define DIGITAL_VOLUME_CONTROL_0_get_delay_ctrl_mute(data)            (0x000003FF&(data))


#define LR_DIGITAL_VOLUME_CONTROL                                     0x18006708
#define LR_DIGITAL_VOLUME_CONTROL_reg_addr                            "0xb8006708"
#define LR_DIGITAL_VOLUME_CONTROL_reg                                 0xb8006708
#define LR_DIGITAL_VOLUME_CONTROL_inst_addr                           "0x01C2"
#define LR_DIGITAL_VOLUME_CONTROL_inst                                0x01C2
#define LR_DIGITAL_VOLUME_CONTROL_mute_l_shift                        (31)
#define LR_DIGITAL_VOLUME_CONTROL_rep_l_status_shift                  (30)
#define LR_DIGITAL_VOLUME_CONTROL_hpf_l_enable_shift                  (28)
#define LR_DIGITAL_VOLUME_CONTROL_vol_l_ready_shift                   (27)
#define LR_DIGITAL_VOLUME_CONTROL_vol_l_a_shift                       (22)
#define LR_DIGITAL_VOLUME_CONTROL_vol_l_b_shift                       (16)
#define LR_DIGITAL_VOLUME_CONTROL_mute_r_shift                        (15)
#define LR_DIGITAL_VOLUME_CONTROL_rep_r_status_shift                  (14)
#define LR_DIGITAL_VOLUME_CONTROL_hpf_r_enable_shift                  (12)
#define LR_DIGITAL_VOLUME_CONTROL_vol_r_ready_shift                   (11)
#define LR_DIGITAL_VOLUME_CONTROL_vol_r_a_shift                       (6)
#define LR_DIGITAL_VOLUME_CONTROL_vol_r_b_shift                       (0)
#define LR_DIGITAL_VOLUME_CONTROL_mute_l_mask                         (0x80000000)
#define LR_DIGITAL_VOLUME_CONTROL_rep_l_status_mask                   (0x40000000)
#define LR_DIGITAL_VOLUME_CONTROL_hpf_l_enable_mask                   (0x10000000)
#define LR_DIGITAL_VOLUME_CONTROL_vol_l_ready_mask                    (0x08000000)
#define LR_DIGITAL_VOLUME_CONTROL_vol_l_a_mask                        (0x07C00000)
#define LR_DIGITAL_VOLUME_CONTROL_vol_l_b_mask                        (0x003F0000)
#define LR_DIGITAL_VOLUME_CONTROL_mute_r_mask                         (0x00008000)
#define LR_DIGITAL_VOLUME_CONTROL_rep_r_status_mask                   (0x00004000)
#define LR_DIGITAL_VOLUME_CONTROL_hpf_r_enable_mask                   (0x00001000)
#define LR_DIGITAL_VOLUME_CONTROL_vol_r_ready_mask                    (0x00000800)
#define LR_DIGITAL_VOLUME_CONTROL_vol_r_a_mask                        (0x000007C0)
#define LR_DIGITAL_VOLUME_CONTROL_vol_r_b_mask                        (0x0000003F)
#define LR_DIGITAL_VOLUME_CONTROL_mute_l(data)                        (0x80000000&((data)<<31))
#define LR_DIGITAL_VOLUME_CONTROL_rep_l_status(data)                  (0x40000000&((data)<<30))
#define LR_DIGITAL_VOLUME_CONTROL_hpf_l_enable(data)                  (0x10000000&((data)<<28))
#define LR_DIGITAL_VOLUME_CONTROL_vol_l_ready(data)                   (0x08000000&((data)<<27))
#define LR_DIGITAL_VOLUME_CONTROL_vol_l_a(data)                       (0x07C00000&((data)<<22))
#define LR_DIGITAL_VOLUME_CONTROL_vol_l_b(data)                       (0x003F0000&((data)<<16))
#define LR_DIGITAL_VOLUME_CONTROL_mute_r(data)                        (0x00008000&((data)<<15))
#define LR_DIGITAL_VOLUME_CONTROL_rep_r_status(data)                  (0x00004000&((data)<<14))
#define LR_DIGITAL_VOLUME_CONTROL_hpf_r_enable(data)                  (0x00001000&((data)<<12))
#define LR_DIGITAL_VOLUME_CONTROL_vol_r_ready(data)                   (0x00000800&((data)<<11))
#define LR_DIGITAL_VOLUME_CONTROL_vol_r_a(data)                       (0x000007C0&((data)<<6))
#define LR_DIGITAL_VOLUME_CONTROL_vol_r_b(data)                       (0x0000003F&(data))
#define LR_DIGITAL_VOLUME_CONTROL_get_mute_l(data)                    ((0x80000000&(data))>>31)
#define LR_DIGITAL_VOLUME_CONTROL_get_rep_l_status(data)              ((0x40000000&(data))>>30)
#define LR_DIGITAL_VOLUME_CONTROL_get_hpf_l_enable(data)              ((0x10000000&(data))>>28)
#define LR_DIGITAL_VOLUME_CONTROL_get_vol_l_ready(data)               ((0x08000000&(data))>>27)
#define LR_DIGITAL_VOLUME_CONTROL_get_vol_l_a(data)                   ((0x07C00000&(data))>>22)
#define LR_DIGITAL_VOLUME_CONTROL_get_vol_l_b(data)                   ((0x003F0000&(data))>>16)
#define LR_DIGITAL_VOLUME_CONTROL_get_mute_r(data)                    ((0x00008000&(data))>>15)
#define LR_DIGITAL_VOLUME_CONTROL_get_rep_r_status(data)              ((0x00004000&(data))>>14)
#define LR_DIGITAL_VOLUME_CONTROL_get_hpf_r_enable(data)              ((0x00001000&(data))>>12)
#define LR_DIGITAL_VOLUME_CONTROL_get_vol_r_ready(data)               ((0x00000800&(data))>>11)
#define LR_DIGITAL_VOLUME_CONTROL_get_vol_r_a(data)                   ((0x000007C0&(data))>>6)
#define LR_DIGITAL_VOLUME_CONTROL_get_vol_r_b(data)                   (0x0000003F&(data))


#define LSRS_DIGITAL_VOLUME_CONTROL                                   0x1800670c
#define LSRS_DIGITAL_VOLUME_CONTROL_reg_addr                          "0xb800670c"
#define LSRS_DIGITAL_VOLUME_CONTROL_reg                               0xb800670c
#define LSRS_DIGITAL_VOLUME_CONTROL_inst_addr                         "0x01C3"
#define LSRS_DIGITAL_VOLUME_CONTROL_inst                              0x01C3
#define LSRS_DIGITAL_VOLUME_CONTROL_mute_ls_shift                     (31)
#define LSRS_DIGITAL_VOLUME_CONTROL_rep_ls_status_shift               (30)
#define LSRS_DIGITAL_VOLUME_CONTROL_hpf_ls_enable_shift               (28)
#define LSRS_DIGITAL_VOLUME_CONTROL_vol_ls_ready_shift                (27)
#define LSRS_DIGITAL_VOLUME_CONTROL_vol_ls_a_shift                    (22)
#define LSRS_DIGITAL_VOLUME_CONTROL_vol_ls_b_shift                    (16)
#define LSRS_DIGITAL_VOLUME_CONTROL_mute_rs_shift                     (15)
#define LSRS_DIGITAL_VOLUME_CONTROL_rep_rs_status_shift               (14)
#define LSRS_DIGITAL_VOLUME_CONTROL_hpf_rs_enable_shift               (12)
#define LSRS_DIGITAL_VOLUME_CONTROL_vol_rs_ready_shift                (11)
#define LSRS_DIGITAL_VOLUME_CONTROL_vol_rs_a_shift                    (6)
#define LSRS_DIGITAL_VOLUME_CONTROL_vol_rs_b_shift                    (0)
#define LSRS_DIGITAL_VOLUME_CONTROL_mute_ls_mask                      (0x80000000)
#define LSRS_DIGITAL_VOLUME_CONTROL_rep_ls_status_mask                (0x40000000)
#define LSRS_DIGITAL_VOLUME_CONTROL_hpf_ls_enable_mask                (0x10000000)
#define LSRS_DIGITAL_VOLUME_CONTROL_vol_ls_ready_mask                 (0x08000000)
#define LSRS_DIGITAL_VOLUME_CONTROL_vol_ls_a_mask                     (0x07C00000)
#define LSRS_DIGITAL_VOLUME_CONTROL_vol_ls_b_mask                     (0x003F0000)
#define LSRS_DIGITAL_VOLUME_CONTROL_mute_rs_mask                      (0x00008000)
#define LSRS_DIGITAL_VOLUME_CONTROL_rep_rs_status_mask                (0x00004000)
#define LSRS_DIGITAL_VOLUME_CONTROL_hpf_rs_enable_mask                (0x00001000)
#define LSRS_DIGITAL_VOLUME_CONTROL_vol_rs_ready_mask                 (0x00000800)
#define LSRS_DIGITAL_VOLUME_CONTROL_vol_rs_a_mask                     (0x000007C0)
#define LSRS_DIGITAL_VOLUME_CONTROL_vol_rs_b_mask                     (0x0000003F)
#define LSRS_DIGITAL_VOLUME_CONTROL_mute_ls(data)                     (0x80000000&((data)<<31))
#define LSRS_DIGITAL_VOLUME_CONTROL_rep_ls_status(data)               (0x40000000&((data)<<30))
#define LSRS_DIGITAL_VOLUME_CONTROL_hpf_ls_enable(data)               (0x10000000&((data)<<28))
#define LSRS_DIGITAL_VOLUME_CONTROL_vol_ls_ready(data)                (0x08000000&((data)<<27))
#define LSRS_DIGITAL_VOLUME_CONTROL_vol_ls_a(data)                    (0x07C00000&((data)<<22))
#define LSRS_DIGITAL_VOLUME_CONTROL_vol_ls_b(data)                    (0x003F0000&((data)<<16))
#define LSRS_DIGITAL_VOLUME_CONTROL_mute_rs(data)                     (0x00008000&((data)<<15))
#define LSRS_DIGITAL_VOLUME_CONTROL_rep_rs_status(data)               (0x00004000&((data)<<14))
#define LSRS_DIGITAL_VOLUME_CONTROL_hpf_rs_enable(data)               (0x00001000&((data)<<12))
#define LSRS_DIGITAL_VOLUME_CONTROL_vol_rs_ready(data)                (0x00000800&((data)<<11))
#define LSRS_DIGITAL_VOLUME_CONTROL_vol_rs_a(data)                    (0x000007C0&((data)<<6))
#define LSRS_DIGITAL_VOLUME_CONTROL_vol_rs_b(data)                    (0x0000003F&(data))
#define LSRS_DIGITAL_VOLUME_CONTROL_get_mute_ls(data)                 ((0x80000000&(data))>>31)
#define LSRS_DIGITAL_VOLUME_CONTROL_get_rep_ls_status(data)           ((0x40000000&(data))>>30)
#define LSRS_DIGITAL_VOLUME_CONTROL_get_hpf_ls_enable(data)           ((0x10000000&(data))>>28)
#define LSRS_DIGITAL_VOLUME_CONTROL_get_vol_ls_ready(data)            ((0x08000000&(data))>>27)
#define LSRS_DIGITAL_VOLUME_CONTROL_get_vol_ls_a(data)                ((0x07C00000&(data))>>22)
#define LSRS_DIGITAL_VOLUME_CONTROL_get_vol_ls_b(data)                ((0x003F0000&(data))>>16)
#define LSRS_DIGITAL_VOLUME_CONTROL_get_mute_rs(data)                 ((0x00008000&(data))>>15)
#define LSRS_DIGITAL_VOLUME_CONTROL_get_rep_rs_status(data)           ((0x00004000&(data))>>14)
#define LSRS_DIGITAL_VOLUME_CONTROL_get_hpf_rs_enable(data)           ((0x00001000&(data))>>12)
#define LSRS_DIGITAL_VOLUME_CONTROL_get_vol_rs_ready(data)            ((0x00000800&(data))>>11)
#define LSRS_DIGITAL_VOLUME_CONTROL_get_vol_rs_a(data)                ((0x000007C0&(data))>>6)
#define LSRS_DIGITAL_VOLUME_CONTROL_get_vol_rs_b(data)                (0x0000003F&(data))


#define CSW_DIGITAL_VOLUME_CONTROL                                    0x18006710
#define CSW_DIGITAL_VOLUME_CONTROL_reg_addr                           "0xb8006710"
#define CSW_DIGITAL_VOLUME_CONTROL_reg                                0xb8006710
#define CSW_DIGITAL_VOLUME_CONTROL_inst_addr                          "0x01C4"
#define CSW_DIGITAL_VOLUME_CONTROL_inst                               0x01C4
#define CSW_DIGITAL_VOLUME_CONTROL_mute_c_shift                       (31)
#define CSW_DIGITAL_VOLUME_CONTROL_rep_c_status_shift                 (30)
#define CSW_DIGITAL_VOLUME_CONTROL_hpf_c_enable_shift                 (28)
#define CSW_DIGITAL_VOLUME_CONTROL_vol_c_ready_shift                  (27)
#define CSW_DIGITAL_VOLUME_CONTROL_vol_c_a_shift                      (22)
#define CSW_DIGITAL_VOLUME_CONTROL_vol_c_b_shift                      (16)
#define CSW_DIGITAL_VOLUME_CONTROL_mute_sw_shift                      (15)
#define CSW_DIGITAL_VOLUME_CONTROL_rep_sw_status_shift                (14)
#define CSW_DIGITAL_VOLUME_CONTROL_sw_src_sel_shift                   (13)
#define CSW_DIGITAL_VOLUME_CONTROL_hpf_sw_enable_shift                (12)
#define CSW_DIGITAL_VOLUME_CONTROL_vol_sw_ready_shift                 (11)
#define CSW_DIGITAL_VOLUME_CONTROL_vol_sw_a_shift                     (6)
#define CSW_DIGITAL_VOLUME_CONTROL_vol_sw_b_shift                     (0)
#define CSW_DIGITAL_VOLUME_CONTROL_mute_c_mask                        (0x80000000)
#define CSW_DIGITAL_VOLUME_CONTROL_rep_c_status_mask                  (0x40000000)
#define CSW_DIGITAL_VOLUME_CONTROL_hpf_c_enable_mask                  (0x10000000)
#define CSW_DIGITAL_VOLUME_CONTROL_vol_c_ready_mask                   (0x08000000)
#define CSW_DIGITAL_VOLUME_CONTROL_vol_c_a_mask                       (0x07C00000)
#define CSW_DIGITAL_VOLUME_CONTROL_vol_c_b_mask                       (0x003F0000)
#define CSW_DIGITAL_VOLUME_CONTROL_mute_sw_mask                       (0x00008000)
#define CSW_DIGITAL_VOLUME_CONTROL_rep_sw_status_mask                 (0x00004000)
#define CSW_DIGITAL_VOLUME_CONTROL_sw_src_sel_mask                    (0x00002000)
#define CSW_DIGITAL_VOLUME_CONTROL_hpf_sw_enable_mask                 (0x00001000)
#define CSW_DIGITAL_VOLUME_CONTROL_vol_sw_ready_mask                  (0x00000800)
#define CSW_DIGITAL_VOLUME_CONTROL_vol_sw_a_mask                      (0x000007C0)
#define CSW_DIGITAL_VOLUME_CONTROL_vol_sw_b_mask                      (0x0000003F)
#define CSW_DIGITAL_VOLUME_CONTROL_mute_c(data)                       (0x80000000&((data)<<31))
#define CSW_DIGITAL_VOLUME_CONTROL_rep_c_status(data)                 (0x40000000&((data)<<30))
#define CSW_DIGITAL_VOLUME_CONTROL_hpf_c_enable(data)                 (0x10000000&((data)<<28))
#define CSW_DIGITAL_VOLUME_CONTROL_vol_c_ready(data)                  (0x08000000&((data)<<27))
#define CSW_DIGITAL_VOLUME_CONTROL_vol_c_a(data)                      (0x07C00000&((data)<<22))
#define CSW_DIGITAL_VOLUME_CONTROL_vol_c_b(data)                      (0x003F0000&((data)<<16))
#define CSW_DIGITAL_VOLUME_CONTROL_mute_sw(data)                      (0x00008000&((data)<<15))
#define CSW_DIGITAL_VOLUME_CONTROL_rep_sw_status(data)                (0x00004000&((data)<<14))
#define CSW_DIGITAL_VOLUME_CONTROL_sw_src_sel(data)                   (0x00002000&((data)<<13))
#define CSW_DIGITAL_VOLUME_CONTROL_hpf_sw_enable(data)                (0x00001000&((data)<<12))
#define CSW_DIGITAL_VOLUME_CONTROL_vol_sw_ready(data)                 (0x00000800&((data)<<11))
#define CSW_DIGITAL_VOLUME_CONTROL_vol_sw_a(data)                     (0x000007C0&((data)<<6))
#define CSW_DIGITAL_VOLUME_CONTROL_vol_sw_b(data)                     (0x0000003F&(data))
#define CSW_DIGITAL_VOLUME_CONTROL_get_mute_c(data)                   ((0x80000000&(data))>>31)
#define CSW_DIGITAL_VOLUME_CONTROL_get_rep_c_status(data)             ((0x40000000&(data))>>30)
#define CSW_DIGITAL_VOLUME_CONTROL_get_hpf_c_enable(data)             ((0x10000000&(data))>>28)
#define CSW_DIGITAL_VOLUME_CONTROL_get_vol_c_ready(data)              ((0x08000000&(data))>>27)
#define CSW_DIGITAL_VOLUME_CONTROL_get_vol_c_a(data)                  ((0x07C00000&(data))>>22)
#define CSW_DIGITAL_VOLUME_CONTROL_get_vol_c_b(data)                  ((0x003F0000&(data))>>16)
#define CSW_DIGITAL_VOLUME_CONTROL_get_mute_sw(data)                  ((0x00008000&(data))>>15)
#define CSW_DIGITAL_VOLUME_CONTROL_get_rep_sw_status(data)            ((0x00004000&(data))>>14)
#define CSW_DIGITAL_VOLUME_CONTROL_get_sw_src_sel(data)               ((0x00002000&(data))>>13)
#define CSW_DIGITAL_VOLUME_CONTROL_get_hpf_sw_enable(data)            ((0x00001000&(data))>>12)
#define CSW_DIGITAL_VOLUME_CONTROL_get_vol_sw_ready(data)             ((0x00000800&(data))>>11)
#define CSW_DIGITAL_VOLUME_CONTROL_get_vol_sw_a(data)                 ((0x000007C0&(data))>>6)
#define CSW_DIGITAL_VOLUME_CONTROL_get_vol_sw_b(data)                 (0x0000003F&(data))


#define DOUBLE_BUFFER_ACK                                             0x18006714
#define DOUBLE_BUFFER_ACK_reg_addr                                    "0xb8006714"
#define DOUBLE_BUFFER_ACK_reg                                         0xb8006714
#define DOUBLE_BUFFER_ACK_inst_addr                                   "0x01C5"
#define DOUBLE_BUFFER_ACK_inst                                        0x01C5
#define DOUBLE_BUFFER_ACK_zcto_status_shift                           (1)
#define DOUBLE_BUFFER_ACK_double_buffer_ack_shift                     (0)
#define DOUBLE_BUFFER_ACK_zcto_status_mask                            (0x00000002)
#define DOUBLE_BUFFER_ACK_double_buffer_ack_mask                      (0x00000001)
#define DOUBLE_BUFFER_ACK_zcto_status(data)                           (0x00000002&((data)<<1))
#define DOUBLE_BUFFER_ACK_double_buffer_ack(data)                     (0x00000001&(data))
#define DOUBLE_BUFFER_ACK_get_zcto_status(data)                       ((0x00000002&(data))>>1)
#define DOUBLE_BUFFER_ACK_get_double_buffer_ack(data)                 (0x00000001&(data))


#define DUMMY_6718                                                    0x18006718
#define DUMMY_6718_reg_addr                                           "0xb8006718"
#define DUMMY_6718_reg                                                0xb8006718
#define DUMMY_6718_inst_addr                                          "0x01C6"
#define DUMMY_6718_inst                                               0x01C6
#define DUMMY_6718_dummy18006718_31_0_shift                           (0)
#define DUMMY_6718_dummy18006718_31_0_mask                            (0xFFFFFFFF)
#define DUMMY_6718_dummy18006718_31_0(data)                           (0xFFFFFFFF&(data))
#define DUMMY_6718_get_dummy18006718_31_0(data)                       (0xFFFFFFFF&(data))


#define DUMMY_671C                                                    0x1800671c
#define DUMMY_671C_reg_addr                                           "0xb800671c"
#define DUMMY_671C_reg                                                0xb800671c
#define DUMMY_671C_inst_addr                                          "0x01C7"
#define DUMMY_671C_inst                                               0x01C7
#define DUMMY_671C_dummy1800671c_31_0_shift                           (0)
#define DUMMY_671C_dummy1800671c_31_0_mask                            (0xFFFFFFFF)
#define DUMMY_671C_dummy1800671c_31_0(data)                           (0xFFFFFFFF&(data))
#define DUMMY_671C_get_dummy1800671c_31_0(data)                       (0xFFFFFFFF&(data))


#define PROGRAMMABLE_BEEPER_CONTROL                                   0x1800672c
#define PROGRAMMABLE_BEEPER_CONTROL_reg_addr                          "0xb800672c"
#define PROGRAMMABLE_BEEPER_CONTROL_reg                               0xb800672c
#define PROGRAMMABLE_BEEPER_CONTROL_inst_addr                         "0x01CB"
#define PROGRAMMABLE_BEEPER_CONTROL_inst                              0x01CB
#define PROGRAMMABLE_BEEPER_CONTROL_freq_beeper_shift                 (24)
#define PROGRAMMABLE_BEEPER_CONTROL_beeper_volume_shift               (16)
#define PROGRAMMABLE_BEEPER_CONTROL_mute_beeper_shift                 (15)
#define PROGRAMMABLE_BEEPER_CONTROL_mode_beeper_shift                 (14)
#define PROGRAMMABLE_BEEPER_CONTROL_duration_beeper_shift             (0)
#define PROGRAMMABLE_BEEPER_CONTROL_freq_beeper_mask                  (0xFF000000)
#define PROGRAMMABLE_BEEPER_CONTROL_beeper_volume_mask                (0x000F0000)
#define PROGRAMMABLE_BEEPER_CONTROL_mute_beeper_mask                  (0x00008000)
#define PROGRAMMABLE_BEEPER_CONTROL_mode_beeper_mask                  (0x00004000)
#define PROGRAMMABLE_BEEPER_CONTROL_duration_beeper_mask              (0x000000FF)
#define PROGRAMMABLE_BEEPER_CONTROL_freq_beeper(data)                 (0xFF000000&((data)<<24))
#define PROGRAMMABLE_BEEPER_CONTROL_beeper_volume(data)               (0x000F0000&((data)<<16))
#define PROGRAMMABLE_BEEPER_CONTROL_mute_beeper(data)                 (0x00008000&((data)<<15))
#define PROGRAMMABLE_BEEPER_CONTROL_mode_beeper(data)                 (0x00004000&((data)<<14))
#define PROGRAMMABLE_BEEPER_CONTROL_duration_beeper(data)             (0x000000FF&(data))
#define PROGRAMMABLE_BEEPER_CONTROL_get_freq_beeper(data)             ((0xFF000000&(data))>>24)
#define PROGRAMMABLE_BEEPER_CONTROL_get_beeper_volume(data)           ((0x000F0000&(data))>>16)
#define PROGRAMMABLE_BEEPER_CONTROL_get_mute_beeper(data)             ((0x00008000&(data))>>15)
#define PROGRAMMABLE_BEEPER_CONTROL_get_mode_beeper(data)             ((0x00004000&(data))>>14)
#define PROGRAMMABLE_BEEPER_CONTROL_get_duration_beeper(data)         (0x000000FF&(data))


#define SPATIAL_EFFECT_CONTROL_0                                      0x18006730
#define SPATIAL_EFFECT_CONTROL_0_reg_addr                             "0xb8006730"
#define SPATIAL_EFFECT_CONTROL_0_reg                                  0xb8006730
#define SPATIAL_EFFECT_CONTROL_0_inst_addr                            "0x01CC"
#define SPATIAL_EFFECT_CONTROL_0_inst                                 0x01CC
#define SPATIAL_EFFECT_CONTROL_0_apf_en_shift                         (14)
#define SPATIAL_EFFECT_CONTROL_0_psb_en_shift                         (13)
#define SPATIAL_EFFECT_CONTROL_0_seb_en_shift                         (12)
#define SPATIAL_EFFECT_CONTROL_0_spatial_in_l_sel_shift               (11)
#define SPATIAL_EFFECT_CONTROL_0_spatial_in_r_sel_shift               (10)
#define SPATIAL_EFFECT_CONTROL_0_f_coef_shift                         (0)
#define SPATIAL_EFFECT_CONTROL_0_apf_en_mask                          (0x00004000)
#define SPATIAL_EFFECT_CONTROL_0_psb_en_mask                          (0x00002000)
#define SPATIAL_EFFECT_CONTROL_0_seb_en_mask                          (0x00001000)
#define SPATIAL_EFFECT_CONTROL_0_spatial_in_l_sel_mask                (0x00000800)
#define SPATIAL_EFFECT_CONTROL_0_spatial_in_r_sel_mask                (0x00000400)
#define SPATIAL_EFFECT_CONTROL_0_f_coef_mask                          (0x000001FF)
#define SPATIAL_EFFECT_CONTROL_0_apf_en(data)                         (0x00004000&((data)<<14))
#define SPATIAL_EFFECT_CONTROL_0_psb_en(data)                         (0x00002000&((data)<<13))
#define SPATIAL_EFFECT_CONTROL_0_seb_en(data)                         (0x00001000&((data)<<12))
#define SPATIAL_EFFECT_CONTROL_0_spatial_in_l_sel(data)               (0x00000800&((data)<<11))
#define SPATIAL_EFFECT_CONTROL_0_spatial_in_r_sel(data)               (0x00000400&((data)<<10))
#define SPATIAL_EFFECT_CONTROL_0_f_coef(data)                         (0x000001FF&(data))
#define SPATIAL_EFFECT_CONTROL_0_get_apf_en(data)                     ((0x00004000&(data))>>14)
#define SPATIAL_EFFECT_CONTROL_0_get_psb_en(data)                     ((0x00002000&(data))>>13)
#define SPATIAL_EFFECT_CONTROL_0_get_seb_en(data)                     ((0x00001000&(data))>>12)
#define SPATIAL_EFFECT_CONTROL_0_get_spatial_in_l_sel(data)           ((0x00000800&(data))>>11)
#define SPATIAL_EFFECT_CONTROL_0_get_spatial_in_r_sel(data)           ((0x00000400&(data))>>10)
#define SPATIAL_EFFECT_CONTROL_0_get_f_coef(data)                     (0x000001FF&(data))


#define SPATIAL_EFFECT_CONTROL_1                                      0x18006734
#define SPATIAL_EFFECT_CONTROL_1_reg_addr                             "0xb8006734"
#define SPATIAL_EFFECT_CONTROL_1_reg                                  0xb8006734
#define SPATIAL_EFFECT_CONTROL_1_inst_addr                            "0x01CD"
#define SPATIAL_EFFECT_CONTROL_1_inst                                 0x01CD
#define SPATIAL_EFFECT_CONTROL_1_depth1_shift                         (16)
#define SPATIAL_EFFECT_CONTROL_1_depth2_shift                         (0)
#define SPATIAL_EFFECT_CONTROL_1_depth1_mask                          (0x01FF0000)
#define SPATIAL_EFFECT_CONTROL_1_depth2_mask                          (0x000001FF)
#define SPATIAL_EFFECT_CONTROL_1_depth1(data)                         (0x01FF0000&((data)<<16))
#define SPATIAL_EFFECT_CONTROL_1_depth2(data)                         (0x000001FF&(data))
#define SPATIAL_EFFECT_CONTROL_1_get_depth1(data)                     ((0x01FF0000&(data))>>16)
#define SPATIAL_EFFECT_CONTROL_1_get_depth2(data)                     (0x000001FF&(data))


#define AUTO_VOLUME_CONTROL_0                                         0x18006738
#define AUTO_VOLUME_CONTROL_0_reg_addr                                "0xb8006738"
#define AUTO_VOLUME_CONTROL_0_reg                                     0xb8006738
#define AUTO_VOLUME_CONTROL_0_inst_addr                               "0x01CE"
#define AUTO_VOLUME_CONTROL_0_inst                                    0x01CE
#define AUTO_VOLUME_CONTROL_0_avc_noise_gain_shift                    (28)
#define AUTO_VOLUME_CONTROL_0_avc_noise_thre_shift                    (20)
#define AUTO_VOLUME_CONTROL_0_avc_level_max_shift                     (12)
#define AUTO_VOLUME_CONTROL_0_avc_level_min_shift                     (4)
#define AUTO_VOLUME_CONTROL_0_avc_down_db_shift                       (2)
#define AUTO_VOLUME_CONTROL_0_avc_up_db_shift                         (0)
#define AUTO_VOLUME_CONTROL_0_avc_noise_gain_mask                     (0x30000000)
#define AUTO_VOLUME_CONTROL_0_avc_noise_thre_mask                     (0x0FF00000)
#define AUTO_VOLUME_CONTROL_0_avc_level_max_mask                      (0x000FF000)
#define AUTO_VOLUME_CONTROL_0_avc_level_min_mask                      (0x00000FF0)
#define AUTO_VOLUME_CONTROL_0_avc_down_db_mask                        (0x0000000C)
#define AUTO_VOLUME_CONTROL_0_avc_up_db_mask                          (0x00000003)
#define AUTO_VOLUME_CONTROL_0_avc_noise_gain(data)                    (0x30000000&((data)<<28))
#define AUTO_VOLUME_CONTROL_0_avc_noise_thre(data)                    (0x0FF00000&((data)<<20))
#define AUTO_VOLUME_CONTROL_0_avc_level_max(data)                     (0x000FF000&((data)<<12))
#define AUTO_VOLUME_CONTROL_0_avc_level_min(data)                     (0x00000FF0&((data)<<4))
#define AUTO_VOLUME_CONTROL_0_avc_down_db(data)                       (0x0000000C&((data)<<2))
#define AUTO_VOLUME_CONTROL_0_avc_up_db(data)                         (0x00000003&(data))
#define AUTO_VOLUME_CONTROL_0_get_avc_noise_gain(data)                ((0x30000000&(data))>>28)
#define AUTO_VOLUME_CONTROL_0_get_avc_noise_thre(data)                ((0x0FF00000&(data))>>20)
#define AUTO_VOLUME_CONTROL_0_get_avc_level_max(data)                 ((0x000FF000&(data))>>12)
#define AUTO_VOLUME_CONTROL_0_get_avc_level_min(data)                 ((0x00000FF0&(data))>>4)
#define AUTO_VOLUME_CONTROL_0_get_avc_down_db(data)                   ((0x0000000C&(data))>>2)
#define AUTO_VOLUME_CONTROL_0_get_avc_up_db(data)                     (0x00000003&(data))


#define AVC_VOLUME_CONTROL_1                                          0x1800673c
#define AVC_VOLUME_CONTROL_1_reg_addr                                 "0xb800673c"
#define AVC_VOLUME_CONTROL_1_reg                                      0xb800673c
#define AVC_VOLUME_CONTROL_1_inst_addr                                "0x01CF"
#define AVC_VOLUME_CONTROL_1_inst                                     0x01CF
#define AVC_VOLUME_CONTROL_1_avc_cnt_thre_shift                       (24)
#define AVC_VOLUME_CONTROL_1_avc_zc_win_shift                         (12)
#define AVC_VOLUME_CONTROL_1_avc_mon_win_shift                        (0)
#define AVC_VOLUME_CONTROL_1_avc_cnt_thre_mask                        (0xFF000000)
#define AVC_VOLUME_CONTROL_1_avc_zc_win_mask                          (0x00FFF000)
#define AVC_VOLUME_CONTROL_1_avc_mon_win_mask                         (0x00000FFF)
#define AVC_VOLUME_CONTROL_1_avc_cnt_thre(data)                       (0xFF000000&((data)<<24))
#define AVC_VOLUME_CONTROL_1_avc_zc_win(data)                         (0x00FFF000&((data)<<12))
#define AVC_VOLUME_CONTROL_1_avc_mon_win(data)                        (0x00000FFF&(data))
#define AVC_VOLUME_CONTROL_1_get_avc_cnt_thre(data)                   ((0xFF000000&(data))>>24)
#define AVC_VOLUME_CONTROL_1_get_avc_zc_win(data)                     ((0x00FFF000&(data))>>12)
#define AVC_VOLUME_CONTROL_1_get_avc_mon_win(data)                    (0x00000FFF&(data))


#define EQ_A1_0                                                       0x18006740
#define EQ_A1_0_reg_addr                                              "0xb8006740"
#define EQ_A1_0_reg                                                   0xb8006740
#define EQ_A1_0_inst_addr                                             "0x01D0"
#define EQ_A1_0_inst                                                  0x01D0
#define EQ_A1_0_eq_lp_a1_shift                                        (16)
#define EQ_A1_0_eq_bp1_a1_shift                                       (0)
#define EQ_A1_0_eq_lp_a1_mask                                         (0xFFFF0000)
#define EQ_A1_0_eq_bp1_a1_mask                                        (0x0000FFFF)
#define EQ_A1_0_eq_lp_a1(data)                                        (0xFFFF0000&((data)<<16))
#define EQ_A1_0_eq_bp1_a1(data)                                       (0x0000FFFF&(data))
#define EQ_A1_0_get_eq_lp_a1(data)                                    ((0xFFFF0000&(data))>>16)
#define EQ_A1_0_get_eq_bp1_a1(data)                                   (0x0000FFFF&(data))


#define EQ_A1_1                                                       0x18006744
#define EQ_A1_1_reg_addr                                              "0xb8006744"
#define EQ_A1_1_reg                                                   0xb8006744
#define EQ_A1_1_inst_addr                                             "0x01D1"
#define EQ_A1_1_inst                                                  0x01D1
#define EQ_A1_1_eq_bp2_a1_shift                                       (16)
#define EQ_A1_1_eq_bp3_a1_shift                                       (0)
#define EQ_A1_1_eq_bp2_a1_mask                                        (0xFFFF0000)
#define EQ_A1_1_eq_bp3_a1_mask                                        (0x0000FFFF)
#define EQ_A1_1_eq_bp2_a1(data)                                       (0xFFFF0000&((data)<<16))
#define EQ_A1_1_eq_bp3_a1(data)                                       (0x0000FFFF&(data))
#define EQ_A1_1_get_eq_bp2_a1(data)                                   ((0xFFFF0000&(data))>>16)
#define EQ_A1_1_get_eq_bp3_a1(data)                                   (0x0000FFFF&(data))


#define EQ_A1_2                                                       0x18006748
#define EQ_A1_2_reg_addr                                              "0xb8006748"
#define EQ_A1_2_reg                                                   0xb8006748
#define EQ_A1_2_inst_addr                                             "0x01D2"
#define EQ_A1_2_inst                                                  0x01D2
#define EQ_A1_2_eq_bp4_a1_shift                                       (16)
#define EQ_A1_2_eq_bp5_a1_shift                                       (0)
#define EQ_A1_2_eq_bp4_a1_mask                                        (0xFFFF0000)
#define EQ_A1_2_eq_bp5_a1_mask                                        (0x0000FFFF)
#define EQ_A1_2_eq_bp4_a1(data)                                       (0xFFFF0000&((data)<<16))
#define EQ_A1_2_eq_bp5_a1(data)                                       (0x0000FFFF&(data))
#define EQ_A1_2_get_eq_bp4_a1(data)                                   ((0xFFFF0000&(data))>>16)
#define EQ_A1_2_get_eq_bp5_a1(data)                                   (0x0000FFFF&(data))


#define EQ_A1_3                                                       0x1800674c
#define EQ_A1_3_reg_addr                                              "0xb800674c"
#define EQ_A1_3_reg                                                   0xb800674c
#define EQ_A1_3_inst_addr                                             "0x01D3"
#define EQ_A1_3_inst                                                  0x01D3
#define EQ_A1_3_eq_hp_a1_shift                                        (0)
#define EQ_A1_3_eq_hp_a1_mask                                         (0x0000FFFF)
#define EQ_A1_3_eq_hp_a1(data)                                        (0x0000FFFF&(data))
#define EQ_A1_3_get_eq_hp_a1(data)                                    (0x0000FFFF&(data))


#define EQ_A2_1                                                       0x18006750
#define EQ_A2_1_reg_addr                                              "0xb8006750"
#define EQ_A2_1_reg                                                   0xb8006750
#define EQ_A2_1_inst_addr                                             "0x01D4"
#define EQ_A2_1_inst                                                  0x01D4
#define EQ_A2_1_eq_bp1_a2_shift                                       (16)
#define EQ_A2_1_eq_bp2_a2_shift                                       (0)
#define EQ_A2_1_eq_bp1_a2_mask                                        (0xFFFF0000)
#define EQ_A2_1_eq_bp2_a2_mask                                        (0x0000FFFF)
#define EQ_A2_1_eq_bp1_a2(data)                                       (0xFFFF0000&((data)<<16))
#define EQ_A2_1_eq_bp2_a2(data)                                       (0x0000FFFF&(data))
#define EQ_A2_1_get_eq_bp1_a2(data)                                   ((0xFFFF0000&(data))>>16)
#define EQ_A2_1_get_eq_bp2_a2(data)                                   (0x0000FFFF&(data))


#define EQ_A2_2                                                       0x18006754
#define EQ_A2_2_reg_addr                                              "0xb8006754"
#define EQ_A2_2_reg                                                   0xb8006754
#define EQ_A2_2_inst_addr                                             "0x01D5"
#define EQ_A2_2_inst                                                  0x01D5
#define EQ_A2_2_eq_bp3_a2_shift                                       (16)
#define EQ_A2_2_eq_bp4_a2_shift                                       (0)
#define EQ_A2_2_eq_bp3_a2_mask                                        (0xFFFF0000)
#define EQ_A2_2_eq_bp4_a2_mask                                        (0x0000FFFF)
#define EQ_A2_2_eq_bp3_a2(data)                                       (0xFFFF0000&((data)<<16))
#define EQ_A2_2_eq_bp4_a2(data)                                       (0x0000FFFF&(data))
#define EQ_A2_2_get_eq_bp3_a2(data)                                   ((0xFFFF0000&(data))>>16)
#define EQ_A2_2_get_eq_bp4_a2(data)                                   (0x0000FFFF&(data))


#define EQ_A2_3                                                       0x18006758
#define EQ_A2_3_reg_addr                                              "0xb8006758"
#define EQ_A2_3_reg                                                   0xb8006758
#define EQ_A2_3_inst_addr                                             "0x01D6"
#define EQ_A2_3_inst                                                  0x01D6
#define EQ_A2_3_eq_bp5_a2_shift                                       (0)
#define EQ_A2_3_eq_bp5_a2_mask                                        (0x0000FFFF)
#define EQ_A2_3_eq_bp5_a2(data)                                       (0x0000FFFF&(data))
#define EQ_A2_3_get_eq_bp5_a2(data)                                   (0x0000FFFF&(data))


#define EQ_H0_0                                                       0x1800675c
#define EQ_H0_0_reg_addr                                              "0xb800675c"
#define EQ_H0_0_reg                                                   0xb800675c
#define EQ_H0_0_inst_addr                                             "0x01D7"
#define EQ_H0_0_inst                                                  0x01D7
#define EQ_H0_0_eq_hp_slope_shift                                     (0)
#define EQ_H0_0_eq_hp_slope_mask                                      (0x00000001)
#define EQ_H0_0_eq_hp_slope(data)                                     (0x00000001&(data))
#define EQ_H0_0_get_eq_hp_slope(data)                                 (0x00000001&(data))


#define EQ_H0_1                                                       0x18006760
#define EQ_H0_1_reg_addr                                              "0xb8006760"
#define EQ_H0_1_reg                                                   0xb8006760
#define EQ_H0_1_inst_addr                                             "0x01D8"
#define EQ_H0_1_inst                                                  0x01D8
#define EQ_H0_1_eq_lp_h0_shift                                        (16)
#define EQ_H0_1_eq_bp1_h0_shift                                       (0)
#define EQ_H0_1_eq_lp_h0_mask                                         (0xFFFF0000)
#define EQ_H0_1_eq_bp1_h0_mask                                        (0x0000FFFF)
#define EQ_H0_1_eq_lp_h0(data)                                        (0xFFFF0000&((data)<<16))
#define EQ_H0_1_eq_bp1_h0(data)                                       (0x0000FFFF&(data))
#define EQ_H0_1_get_eq_lp_h0(data)                                    ((0xFFFF0000&(data))>>16)
#define EQ_H0_1_get_eq_bp1_h0(data)                                   (0x0000FFFF&(data))


#define EQ_H0_2                                                       0x18006764
#define EQ_H0_2_reg_addr                                              "0xb8006764"
#define EQ_H0_2_reg                                                   0xb8006764
#define EQ_H0_2_inst_addr                                             "0x01D9"
#define EQ_H0_2_inst                                                  0x01D9
#define EQ_H0_2_eq_bp2_h0_shift                                       (16)
#define EQ_H0_2_eq_bp3_h0_shift                                       (0)
#define EQ_H0_2_eq_bp2_h0_mask                                        (0xFFFF0000)
#define EQ_H0_2_eq_bp3_h0_mask                                        (0x0000FFFF)
#define EQ_H0_2_eq_bp2_h0(data)                                       (0xFFFF0000&((data)<<16))
#define EQ_H0_2_eq_bp3_h0(data)                                       (0x0000FFFF&(data))
#define EQ_H0_2_get_eq_bp2_h0(data)                                   ((0xFFFF0000&(data))>>16)
#define EQ_H0_2_get_eq_bp3_h0(data)                                   (0x0000FFFF&(data))


#define EQ_H0_3                                                       0x18006768
#define EQ_H0_3_reg_addr                                              "0xb8006768"
#define EQ_H0_3_reg                                                   0xb8006768
#define EQ_H0_3_inst_addr                                             "0x01DA"
#define EQ_H0_3_inst                                                  0x01DA
#define EQ_H0_3_eq_bp4_h0_shift                                       (16)
#define EQ_H0_3_eq_bp5_h0_shift                                       (0)
#define EQ_H0_3_eq_bp4_h0_mask                                        (0xFFFF0000)
#define EQ_H0_3_eq_bp5_h0_mask                                        (0x0000FFFF)
#define EQ_H0_3_eq_bp4_h0(data)                                       (0xFFFF0000&((data)<<16))
#define EQ_H0_3_eq_bp5_h0(data)                                       (0x0000FFFF&(data))
#define EQ_H0_3_get_eq_bp4_h0(data)                                   ((0xFFFF0000&(data))>>16)
#define EQ_H0_3_get_eq_bp5_h0(data)                                   (0x0000FFFF&(data))


#define EQ_CONTROL_STATUS_REGISTER                                    0x1800676c
#define EQ_CONTROL_STATUS_REGISTER_reg_addr                           "0xb800676c"
#define EQ_CONTROL_STATUS_REGISTER_reg                                0xb800676c
#define EQ_CONTROL_STATUS_REGISTER_inst_addr                          "0x01DB"
#define EQ_CONTROL_STATUS_REGISTER_inst                               0x01DB
#define EQ_CONTROL_STATUS_REGISTER_eq_band4_2_of_shift                (19)
#define EQ_CONTROL_STATUS_REGISTER_eq_band4_1_of_shift                (18)
#define EQ_CONTROL_STATUS_REGISTER_eq_band4_2_enable_shift            (17)
#define EQ_CONTROL_STATUS_REGISTER_eq_band4_1_enable_shift            (16)
#define EQ_CONTROL_STATUS_REGISTER_eq_band5_enable_shift              (14)
#define EQ_CONTROL_STATUS_REGISTER_eq_band4_enable_shift              (13)
#define EQ_CONTROL_STATUS_REGISTER_eq_band3_enable_shift              (12)
#define EQ_CONTROL_STATUS_REGISTER_eq_band2_enable_shift              (11)
#define EQ_CONTROL_STATUS_REGISTER_eq_band1_enable_shift              (10)
#define EQ_CONTROL_STATUS_REGISTER_eq_lp_enable_shift                 (9)
#define EQ_CONTROL_STATUS_REGISTER_eq_hp_enable_shift                 (8)
#define EQ_CONTROL_STATUS_REGISTER_eq_band5_of_shift                  (6)
#define EQ_CONTROL_STATUS_REGISTER_eq_band4_of_shift                  (5)
#define EQ_CONTROL_STATUS_REGISTER_eq_band3_of_shift                  (4)
#define EQ_CONTROL_STATUS_REGISTER_eq_band2_of_shift                  (3)
#define EQ_CONTROL_STATUS_REGISTER_eq_band1_of_shift                  (2)
#define EQ_CONTROL_STATUS_REGISTER_eq_lp_of_shift                     (1)
#define EQ_CONTROL_STATUS_REGISTER_eq_hp_of_shift                     (0)
#define EQ_CONTROL_STATUS_REGISTER_eq_band4_2_of_mask                 (0x00080000)
#define EQ_CONTROL_STATUS_REGISTER_eq_band4_1_of_mask                 (0x00040000)
#define EQ_CONTROL_STATUS_REGISTER_eq_band4_2_enable_mask             (0x00020000)
#define EQ_CONTROL_STATUS_REGISTER_eq_band4_1_enable_mask             (0x00010000)
#define EQ_CONTROL_STATUS_REGISTER_eq_band5_enable_mask               (0x00004000)
#define EQ_CONTROL_STATUS_REGISTER_eq_band4_enable_mask               (0x00002000)
#define EQ_CONTROL_STATUS_REGISTER_eq_band3_enable_mask               (0x00001000)
#define EQ_CONTROL_STATUS_REGISTER_eq_band2_enable_mask               (0x00000800)
#define EQ_CONTROL_STATUS_REGISTER_eq_band1_enable_mask               (0x00000400)
#define EQ_CONTROL_STATUS_REGISTER_eq_lp_enable_mask                  (0x00000200)
#define EQ_CONTROL_STATUS_REGISTER_eq_hp_enable_mask                  (0x00000100)
#define EQ_CONTROL_STATUS_REGISTER_eq_band5_of_mask                   (0x00000040)
#define EQ_CONTROL_STATUS_REGISTER_eq_band4_of_mask                   (0x00000020)
#define EQ_CONTROL_STATUS_REGISTER_eq_band3_of_mask                   (0x00000010)
#define EQ_CONTROL_STATUS_REGISTER_eq_band2_of_mask                   (0x00000008)
#define EQ_CONTROL_STATUS_REGISTER_eq_band1_of_mask                   (0x00000004)
#define EQ_CONTROL_STATUS_REGISTER_eq_lp_of_mask                      (0x00000002)
#define EQ_CONTROL_STATUS_REGISTER_eq_hp_of_mask                      (0x00000001)
#define EQ_CONTROL_STATUS_REGISTER_eq_band4_2_of(data)                (0x00080000&((data)<<19))
#define EQ_CONTROL_STATUS_REGISTER_eq_band4_1_of(data)                (0x00040000&((data)<<18))
#define EQ_CONTROL_STATUS_REGISTER_eq_band4_2_enable(data)            (0x00020000&((data)<<17))
#define EQ_CONTROL_STATUS_REGISTER_eq_band4_1_enable(data)            (0x00010000&((data)<<16))
#define EQ_CONTROL_STATUS_REGISTER_eq_band5_enable(data)              (0x00004000&((data)<<14))
#define EQ_CONTROL_STATUS_REGISTER_eq_band4_enable(data)              (0x00002000&((data)<<13))
#define EQ_CONTROL_STATUS_REGISTER_eq_band3_enable(data)              (0x00001000&((data)<<12))
#define EQ_CONTROL_STATUS_REGISTER_eq_band2_enable(data)              (0x00000800&((data)<<11))
#define EQ_CONTROL_STATUS_REGISTER_eq_band1_enable(data)              (0x00000400&((data)<<10))
#define EQ_CONTROL_STATUS_REGISTER_eq_lp_enable(data)                 (0x00000200&((data)<<9))
#define EQ_CONTROL_STATUS_REGISTER_eq_hp_enable(data)                 (0x00000100&((data)<<8))
#define EQ_CONTROL_STATUS_REGISTER_eq_band5_of(data)                  (0x00000040&((data)<<6))
#define EQ_CONTROL_STATUS_REGISTER_eq_band4_of(data)                  (0x00000020&((data)<<5))
#define EQ_CONTROL_STATUS_REGISTER_eq_band3_of(data)                  (0x00000010&((data)<<4))
#define EQ_CONTROL_STATUS_REGISTER_eq_band2_of(data)                  (0x00000008&((data)<<3))
#define EQ_CONTROL_STATUS_REGISTER_eq_band1_of(data)                  (0x00000004&((data)<<2))
#define EQ_CONTROL_STATUS_REGISTER_eq_lp_of(data)                     (0x00000002&((data)<<1))
#define EQ_CONTROL_STATUS_REGISTER_eq_hp_of(data)                     (0x00000001&(data))
#define EQ_CONTROL_STATUS_REGISTER_get_eq_band4_2_of(data)            ((0x00080000&(data))>>19)
#define EQ_CONTROL_STATUS_REGISTER_get_eq_band4_1_of(data)            ((0x00040000&(data))>>18)
#define EQ_CONTROL_STATUS_REGISTER_get_eq_band4_2_enable(data)        ((0x00020000&(data))>>17)
#define EQ_CONTROL_STATUS_REGISTER_get_eq_band4_1_enable(data)        ((0x00010000&(data))>>16)
#define EQ_CONTROL_STATUS_REGISTER_get_eq_band5_enable(data)          ((0x00004000&(data))>>14)
#define EQ_CONTROL_STATUS_REGISTER_get_eq_band4_enable(data)          ((0x00002000&(data))>>13)
#define EQ_CONTROL_STATUS_REGISTER_get_eq_band3_enable(data)          ((0x00001000&(data))>>12)
#define EQ_CONTROL_STATUS_REGISTER_get_eq_band2_enable(data)          ((0x00000800&(data))>>11)
#define EQ_CONTROL_STATUS_REGISTER_get_eq_band1_enable(data)          ((0x00000400&(data))>>10)
#define EQ_CONTROL_STATUS_REGISTER_get_eq_lp_enable(data)             ((0x00000200&(data))>>9)
#define EQ_CONTROL_STATUS_REGISTER_get_eq_hp_enable(data)             ((0x00000100&(data))>>8)
#define EQ_CONTROL_STATUS_REGISTER_get_eq_band5_of(data)              ((0x00000040&(data))>>6)
#define EQ_CONTROL_STATUS_REGISTER_get_eq_band4_of(data)              ((0x00000020&(data))>>5)
#define EQ_CONTROL_STATUS_REGISTER_get_eq_band3_of(data)              ((0x00000010&(data))>>4)
#define EQ_CONTROL_STATUS_REGISTER_get_eq_band2_of(data)              ((0x00000008&(data))>>3)
#define EQ_CONTROL_STATUS_REGISTER_get_eq_band1_of(data)              ((0x00000004&(data))>>2)
#define EQ_CONTROL_STATUS_REGISTER_get_eq_lp_of(data)                 ((0x00000002&(data))>>1)
#define EQ_CONTROL_STATUS_REGISTER_get_eq_hp_of(data)                 (0x00000001&(data))


#define LR_LOUD_A1_0                                                  0x18006770
#define LR_LOUD_A1_0_reg_addr                                         "0xb8006770"
#define LR_LOUD_A1_0_reg                                              0xb8006770
#define LR_LOUD_A1_0_inst_addr                                        "0x01DC"
#define LR_LOUD_A1_0_inst                                             0x01DC
#define LR_LOUD_A1_0_lr_loud_lp0_a1_shift                             (16)
#define LR_LOUD_A1_0_lr_loud_bp1_a1_shift                             (0)
#define LR_LOUD_A1_0_lr_loud_lp0_a1_mask                              (0xFFFF0000)
#define LR_LOUD_A1_0_lr_loud_bp1_a1_mask                              (0x0000FFFF)
#define LR_LOUD_A1_0_lr_loud_lp0_a1(data)                             (0xFFFF0000&((data)<<16))
#define LR_LOUD_A1_0_lr_loud_bp1_a1(data)                             (0x0000FFFF&(data))
#define LR_LOUD_A1_0_get_lr_loud_lp0_a1(data)                         ((0xFFFF0000&(data))>>16)
#define LR_LOUD_A1_0_get_lr_loud_bp1_a1(data)                         (0x0000FFFF&(data))


#define LR_LOUD_A1_1                                                  0x18006774
#define LR_LOUD_A1_1_reg_addr                                         "0xb8006774"
#define LR_LOUD_A1_1_reg                                              0xb8006774
#define LR_LOUD_A1_1_inst_addr                                        "0x01DD"
#define LR_LOUD_A1_1_inst                                             0x01DD
#define LR_LOUD_A1_1_lr_loud_bp2_a1_shift                             (0)
#define LR_LOUD_A1_1_lr_loud_bp2_a1_mask                              (0x0000FFFF)
#define LR_LOUD_A1_1_lr_loud_bp2_a1(data)                             (0x0000FFFF&(data))
#define LR_LOUD_A1_1_get_lr_loud_bp2_a1(data)                         (0x0000FFFF&(data))


#define LR_LOUD_A2                                                    0x18006778
#define LR_LOUD_A2_reg_addr                                           "0xb8006778"
#define LR_LOUD_A2_reg                                                0xb8006778
#define LR_LOUD_A2_inst_addr                                          "0x01DE"
#define LR_LOUD_A2_inst                                               0x01DE
#define LR_LOUD_A2_lr_loud_bp1_a2_shift                               (16)
#define LR_LOUD_A2_lr_loud_bp2_a2_shift                               (0)
#define LR_LOUD_A2_lr_loud_bp1_a2_mask                                (0xFFFF0000)
#define LR_LOUD_A2_lr_loud_bp2_a2_mask                                (0x0000FFFF)
#define LR_LOUD_A2_lr_loud_bp1_a2(data)                               (0xFFFF0000&((data)<<16))
#define LR_LOUD_A2_lr_loud_bp2_a2(data)                               (0x0000FFFF&(data))
#define LR_LOUD_A2_get_lr_loud_bp1_a2(data)                           ((0xFFFF0000&(data))>>16)
#define LR_LOUD_A2_get_lr_loud_bp2_a2(data)                           (0x0000FFFF&(data))


#define LR_LOUD_H0_0                                                  0x1800677c
#define LR_LOUD_H0_0_reg_addr                                         "0xb800677c"
#define LR_LOUD_H0_0_reg                                              0xb800677c
#define LR_LOUD_H0_0_inst_addr                                        "0x01DF"
#define LR_LOUD_H0_0_inst                                             0x01DF
#define LR_LOUD_H0_0_lr_loud_lp0_h0_shift                             (16)
#define LR_LOUD_H0_0_lr_loud_bp1_h0_shift                             (0)
#define LR_LOUD_H0_0_lr_loud_lp0_h0_mask                              (0xFFFF0000)
#define LR_LOUD_H0_0_lr_loud_bp1_h0_mask                              (0x0000FFFF)
#define LR_LOUD_H0_0_lr_loud_lp0_h0(data)                             (0xFFFF0000&((data)<<16))
#define LR_LOUD_H0_0_lr_loud_bp1_h0(data)                             (0x0000FFFF&(data))
#define LR_LOUD_H0_0_get_lr_loud_lp0_h0(data)                         ((0xFFFF0000&(data))>>16)
#define LR_LOUD_H0_0_get_lr_loud_bp1_h0(data)                         (0x0000FFFF&(data))


#define LR_LOUD_H0_1                                                  0x18006780
#define LR_LOUD_H0_1_reg_addr                                         "0xb8006780"
#define LR_LOUD_H0_1_reg                                              0xb8006780
#define LR_LOUD_H0_1_inst_addr                                        "0x01E0"
#define LR_LOUD_H0_1_inst                                             0x01E0
#define LR_LOUD_H0_1_lr_loud_bp2_h0_shift                             (0)
#define LR_LOUD_H0_1_lr_loud_bp2_h0_mask                              (0x0000FFFF)
#define LR_LOUD_H0_1_lr_loud_bp2_h0(data)                             (0x0000FFFF&(data))
#define LR_LOUD_H0_1_get_lr_loud_bp2_h0(data)                         (0x0000FFFF&(data))


#define LSRS_LOUD_A1_0                                                0x18006784
#define LSRS_LOUD_A1_0_reg_addr                                       "0xb8006784"
#define LSRS_LOUD_A1_0_reg                                            0xb8006784
#define LSRS_LOUD_A1_0_inst_addr                                      "0x01E1"
#define LSRS_LOUD_A1_0_inst                                           0x01E1
#define LSRS_LOUD_A1_0_lsrs_loud_lp0_a1_shift                         (16)
#define LSRS_LOUD_A1_0_lsrs_loud_bp1_a1_shift                         (0)
#define LSRS_LOUD_A1_0_lsrs_loud_lp0_a1_mask                          (0xFFFF0000)
#define LSRS_LOUD_A1_0_lsrs_loud_bp1_a1_mask                          (0x0000FFFF)
#define LSRS_LOUD_A1_0_lsrs_loud_lp0_a1(data)                         (0xFFFF0000&((data)<<16))
#define LSRS_LOUD_A1_0_lsrs_loud_bp1_a1(data)                         (0x0000FFFF&(data))
#define LSRS_LOUD_A1_0_get_lsrs_loud_lp0_a1(data)                     ((0xFFFF0000&(data))>>16)
#define LSRS_LOUD_A1_0_get_lsrs_loud_bp1_a1(data)                     (0x0000FFFF&(data))


#define LSRS_LOUD_A1_1                                                0x18006788
#define LSRS_LOUD_A1_1_reg_addr                                       "0xb8006788"
#define LSRS_LOUD_A1_1_reg                                            0xb8006788
#define LSRS_LOUD_A1_1_inst_addr                                      "0x01E2"
#define LSRS_LOUD_A1_1_inst                                           0x01E2
#define LSRS_LOUD_A1_1_lsrs_loud_bp2_a1_shift                         (0)
#define LSRS_LOUD_A1_1_lsrs_loud_bp2_a1_mask                          (0x0000FFFF)
#define LSRS_LOUD_A1_1_lsrs_loud_bp2_a1(data)                         (0x0000FFFF&(data))
#define LSRS_LOUD_A1_1_get_lsrs_loud_bp2_a1(data)                     (0x0000FFFF&(data))


#define LSRS_LOUD_A2                                                  0x1800678c
#define LSRS_LOUD_A2_reg_addr                                         "0xb800678c"
#define LSRS_LOUD_A2_reg                                              0xb800678c
#define LSRS_LOUD_A2_inst_addr                                        "0x01E3"
#define LSRS_LOUD_A2_inst                                             0x01E3
#define LSRS_LOUD_A2_lsrs_loud_bp1_a2_shift                           (16)
#define LSRS_LOUD_A2_lsrs_loud_bp2_a2_shift                           (0)
#define LSRS_LOUD_A2_lsrs_loud_bp1_a2_mask                            (0xFFFF0000)
#define LSRS_LOUD_A2_lsrs_loud_bp2_a2_mask                            (0x0000FFFF)
#define LSRS_LOUD_A2_lsrs_loud_bp1_a2(data)                           (0xFFFF0000&((data)<<16))
#define LSRS_LOUD_A2_lsrs_loud_bp2_a2(data)                           (0x0000FFFF&(data))
#define LSRS_LOUD_A2_get_lsrs_loud_bp1_a2(data)                       ((0xFFFF0000&(data))>>16)
#define LSRS_LOUD_A2_get_lsrs_loud_bp2_a2(data)                       (0x0000FFFF&(data))


#define LSRS_LOUD_H0_0                                                0x18006790
#define LSRS_LOUD_H0_0_reg_addr                                       "0xb8006790"
#define LSRS_LOUD_H0_0_reg                                            0xb8006790
#define LSRS_LOUD_H0_0_inst_addr                                      "0x01E4"
#define LSRS_LOUD_H0_0_inst                                           0x01E4
#define LSRS_LOUD_H0_0_lsrs_loud_lp0_h0_shift                         (16)
#define LSRS_LOUD_H0_0_lsrs_loud_bp1_h0_shift                         (0)
#define LSRS_LOUD_H0_0_lsrs_loud_lp0_h0_mask                          (0xFFFF0000)
#define LSRS_LOUD_H0_0_lsrs_loud_bp1_h0_mask                          (0x0000FFFF)
#define LSRS_LOUD_H0_0_lsrs_loud_lp0_h0(data)                         (0xFFFF0000&((data)<<16))
#define LSRS_LOUD_H0_0_lsrs_loud_bp1_h0(data)                         (0x0000FFFF&(data))
#define LSRS_LOUD_H0_0_get_lsrs_loud_lp0_h0(data)                     ((0xFFFF0000&(data))>>16)
#define LSRS_LOUD_H0_0_get_lsrs_loud_bp1_h0(data)                     (0x0000FFFF&(data))


#define LSRS_LOUD_H0_1                                                0x18006794
#define LSRS_LOUD_H0_1_reg_addr                                       "0xb8006794"
#define LSRS_LOUD_H0_1_reg                                            0xb8006794
#define LSRS_LOUD_H0_1_inst_addr                                      "0x01E5"
#define LSRS_LOUD_H0_1_inst                                           0x01E5
#define LSRS_LOUD_H0_1_lsrs_loud_bp2_h0_shift                         (0)
#define LSRS_LOUD_H0_1_lsrs_loud_bp2_h0_mask                          (0x0000FFFF)
#define LSRS_LOUD_H0_1_lsrs_loud_bp2_h0(data)                         (0x0000FFFF&(data))
#define LSRS_LOUD_H0_1_get_lsrs_loud_bp2_h0(data)                     (0x0000FFFF&(data))


#define CSW_LOUD_A1_0                                                 0x18006798
#define CSW_LOUD_A1_0_reg_addr                                        "0xb8006798"
#define CSW_LOUD_A1_0_reg                                             0xb8006798
#define CSW_LOUD_A1_0_inst_addr                                       "0x01E6"
#define CSW_LOUD_A1_0_inst                                            0x01E6
#define CSW_LOUD_A1_0_csw_loud_lp0_a1_shift                           (16)
#define CSW_LOUD_A1_0_csw_loud_bp1_a1_shift                           (0)
#define CSW_LOUD_A1_0_csw_loud_lp0_a1_mask                            (0xFFFF0000)
#define CSW_LOUD_A1_0_csw_loud_bp1_a1_mask                            (0x0000FFFF)
#define CSW_LOUD_A1_0_csw_loud_lp0_a1(data)                           (0xFFFF0000&((data)<<16))
#define CSW_LOUD_A1_0_csw_loud_bp1_a1(data)                           (0x0000FFFF&(data))
#define CSW_LOUD_A1_0_get_csw_loud_lp0_a1(data)                       ((0xFFFF0000&(data))>>16)
#define CSW_LOUD_A1_0_get_csw_loud_bp1_a1(data)                       (0x0000FFFF&(data))


#define CSW_LOUD_A1_1                                                 0x1800679c
#define CSW_LOUD_A1_1_reg_addr                                        "0xb800679c"
#define CSW_LOUD_A1_1_reg                                             0xb800679c
#define CSW_LOUD_A1_1_inst_addr                                       "0x01E7"
#define CSW_LOUD_A1_1_inst                                            0x01E7
#define CSW_LOUD_A1_1_csw_loud_bp2_a1_shift                           (0)
#define CSW_LOUD_A1_1_csw_loud_bp2_a1_mask                            (0x0000FFFF)
#define CSW_LOUD_A1_1_csw_loud_bp2_a1(data)                           (0x0000FFFF&(data))
#define CSW_LOUD_A1_1_get_csw_loud_bp2_a1(data)                       (0x0000FFFF&(data))


#define CSW_LOUD_A2                                                   0x180067a0
#define CSW_LOUD_A2_reg_addr                                          "0xb80067a0"
#define CSW_LOUD_A2_reg                                               0xb80067a0
#define CSW_LOUD_A2_inst_addr                                         "0x01E8"
#define CSW_LOUD_A2_inst                                              0x01E8
#define CSW_LOUD_A2_csw_loud_bp1_a2_shift                             (16)
#define CSW_LOUD_A2_csw_loud_bp2_a2_shift                             (0)
#define CSW_LOUD_A2_csw_loud_bp1_a2_mask                              (0xFFFF0000)
#define CSW_LOUD_A2_csw_loud_bp2_a2_mask                              (0x0000FFFF)
#define CSW_LOUD_A2_csw_loud_bp1_a2(data)                             (0xFFFF0000&((data)<<16))
#define CSW_LOUD_A2_csw_loud_bp2_a2(data)                             (0x0000FFFF&(data))
#define CSW_LOUD_A2_get_csw_loud_bp1_a2(data)                         ((0xFFFF0000&(data))>>16)
#define CSW_LOUD_A2_get_csw_loud_bp2_a2(data)                         (0x0000FFFF&(data))


#define CSW_LOUD_H0_0                                                 0x180067a4
#define CSW_LOUD_H0_0_reg_addr                                        "0xb80067a4"
#define CSW_LOUD_H0_0_reg                                             0xb80067a4
#define CSW_LOUD_H0_0_inst_addr                                       "0x01E9"
#define CSW_LOUD_H0_0_inst                                            0x01E9
#define CSW_LOUD_H0_0_csw_loud_lp0_h0_shift                           (16)
#define CSW_LOUD_H0_0_csw_loud_bp1_h0_shift                           (0)
#define CSW_LOUD_H0_0_csw_loud_lp0_h0_mask                            (0xFFFF0000)
#define CSW_LOUD_H0_0_csw_loud_bp1_h0_mask                            (0x0000FFFF)
#define CSW_LOUD_H0_0_csw_loud_lp0_h0(data)                           (0xFFFF0000&((data)<<16))
#define CSW_LOUD_H0_0_csw_loud_bp1_h0(data)                           (0x0000FFFF&(data))
#define CSW_LOUD_H0_0_get_csw_loud_lp0_h0(data)                       ((0xFFFF0000&(data))>>16)
#define CSW_LOUD_H0_0_get_csw_loud_bp1_h0(data)                       (0x0000FFFF&(data))


#define CSW_LOUD_H0_1                                                 0x180067a8
#define CSW_LOUD_H0_1_reg_addr                                        "0xb80067a8"
#define CSW_LOUD_H0_1_reg                                             0xb80067a8
#define CSW_LOUD_H0_1_inst_addr                                       "0x01EA"
#define CSW_LOUD_H0_1_inst                                            0x01EA
#define CSW_LOUD_H0_1_csw_loud_bp2_h0_shift                           (0)
#define CSW_LOUD_H0_1_csw_loud_bp2_h0_mask                            (0x0000FFFF)
#define CSW_LOUD_H0_1_csw_loud_bp2_h0(data)                           (0x0000FFFF&(data))
#define CSW_LOUD_H0_1_get_csw_loud_bp2_h0(data)                       (0x0000FFFF&(data))


#define LOUDNESS_CONTROL_REGISTER                                     0x180067ac
#define LOUDNESS_CONTROL_REGISTER_reg_addr                            "0xb80067ac"
#define LOUDNESS_CONTROL_REGISTER_reg                                 0xb80067ac
#define LOUDNESS_CONTROL_REGISTER_inst_addr                           "0x01EB"
#define LOUDNESS_CONTROL_REGISTER_inst                                0x01EB
#define LOUDNESS_CONTROL_REGISTER_ld_bpf1_en_lr_shift                 (8)
#define LOUDNESS_CONTROL_REGISTER_ld_lpf_en_lr_shift                  (7)
#define LOUDNESS_CONTROL_REGISTER_ld_bpf2_en_lr_shift                 (6)
#define LOUDNESS_CONTROL_REGISTER_ld_bpf1_en_lsrs_shift               (5)
#define LOUDNESS_CONTROL_REGISTER_ld_lpf_en_lsrs_shift                (4)
#define LOUDNESS_CONTROL_REGISTER_ld_bpf2_en_lsrs_shift               (3)
#define LOUDNESS_CONTROL_REGISTER_ld_bpf1_en_csw_shift                (2)
#define LOUDNESS_CONTROL_REGISTER_ld_lpf_en_csw_shift                 (1)
#define LOUDNESS_CONTROL_REGISTER_ld_bpf2_en_csw_shift                (0)
#define LOUDNESS_CONTROL_REGISTER_ld_bpf1_en_lr_mask                  (0x00000100)
#define LOUDNESS_CONTROL_REGISTER_ld_lpf_en_lr_mask                   (0x00000080)
#define LOUDNESS_CONTROL_REGISTER_ld_bpf2_en_lr_mask                  (0x00000040)
#define LOUDNESS_CONTROL_REGISTER_ld_bpf1_en_lsrs_mask                (0x00000020)
#define LOUDNESS_CONTROL_REGISTER_ld_lpf_en_lsrs_mask                 (0x00000010)
#define LOUDNESS_CONTROL_REGISTER_ld_bpf2_en_lsrs_mask                (0x00000008)
#define LOUDNESS_CONTROL_REGISTER_ld_bpf1_en_csw_mask                 (0x00000004)
#define LOUDNESS_CONTROL_REGISTER_ld_lpf_en_csw_mask                  (0x00000002)
#define LOUDNESS_CONTROL_REGISTER_ld_bpf2_en_csw_mask                 (0x00000001)
#define LOUDNESS_CONTROL_REGISTER_ld_bpf1_en_lr(data)                 (0x00000100&((data)<<8))
#define LOUDNESS_CONTROL_REGISTER_ld_lpf_en_lr(data)                  (0x00000080&((data)<<7))
#define LOUDNESS_CONTROL_REGISTER_ld_bpf2_en_lr(data)                 (0x00000040&((data)<<6))
#define LOUDNESS_CONTROL_REGISTER_ld_bpf1_en_lsrs(data)               (0x00000020&((data)<<5))
#define LOUDNESS_CONTROL_REGISTER_ld_lpf_en_lsrs(data)                (0x00000010&((data)<<4))
#define LOUDNESS_CONTROL_REGISTER_ld_bpf2_en_lsrs(data)               (0x00000008&((data)<<3))
#define LOUDNESS_CONTROL_REGISTER_ld_bpf1_en_csw(data)                (0x00000004&((data)<<2))
#define LOUDNESS_CONTROL_REGISTER_ld_lpf_en_csw(data)                 (0x00000002&((data)<<1))
#define LOUDNESS_CONTROL_REGISTER_ld_bpf2_en_csw(data)                (0x00000001&(data))
#define LOUDNESS_CONTROL_REGISTER_get_ld_bpf1_en_lr(data)             ((0x00000100&(data))>>8)
#define LOUDNESS_CONTROL_REGISTER_get_ld_lpf_en_lr(data)              ((0x00000080&(data))>>7)
#define LOUDNESS_CONTROL_REGISTER_get_ld_bpf2_en_lr(data)             ((0x00000040&(data))>>6)
#define LOUDNESS_CONTROL_REGISTER_get_ld_bpf1_en_lsrs(data)           ((0x00000020&(data))>>5)
#define LOUDNESS_CONTROL_REGISTER_get_ld_lpf_en_lsrs(data)            ((0x00000010&(data))>>4)
#define LOUDNESS_CONTROL_REGISTER_get_ld_bpf2_en_lsrs(data)           ((0x00000008&(data))>>3)
#define LOUDNESS_CONTROL_REGISTER_get_ld_bpf1_en_csw(data)            ((0x00000004&(data))>>2)
#define LOUDNESS_CONTROL_REGISTER_get_ld_lpf_en_csw(data)             ((0x00000002&(data))>>1)
#define LOUDNESS_CONTROL_REGISTER_get_ld_bpf2_en_csw(data)            (0x00000001&(data))


#define LOUDNESS_STATUS_REGISTER                                      0x180067b0
#define LOUDNESS_STATUS_REGISTER_reg_addr                             "0xb80067b0"
#define LOUDNESS_STATUS_REGISTER_reg                                  0xb80067b0
#define LOUDNESS_STATUS_REGISTER_inst_addr                            "0x01EC"
#define LOUDNESS_STATUS_REGISTER_inst                                 0x01EC
#define LOUDNESS_STATUS_REGISTER_ld_lpf_of_lr_shift                   (8)
#define LOUDNESS_STATUS_REGISTER_ld_bpf1_of_lr_shift                  (7)
#define LOUDNESS_STATUS_REGISTER_ld_bpf2_of_lr_shift                  (6)
#define LOUDNESS_STATUS_REGISTER_ld_lpf_of_lsrs_shift                 (5)
#define LOUDNESS_STATUS_REGISTER_ld_bpf1_of_lsrs_shift                (4)
#define LOUDNESS_STATUS_REGISTER_ld_bpf2_of_lsrs_shift                (3)
#define LOUDNESS_STATUS_REGISTER_ld_lpf_of_csw_shift                  (2)
#define LOUDNESS_STATUS_REGISTER_ld_bpf1_of_csw_shift                 (1)
#define LOUDNESS_STATUS_REGISTER_ld_bpf2_of_csw_shift                 (0)
#define LOUDNESS_STATUS_REGISTER_ld_lpf_of_lr_mask                    (0x00000100)
#define LOUDNESS_STATUS_REGISTER_ld_bpf1_of_lr_mask                   (0x00000080)
#define LOUDNESS_STATUS_REGISTER_ld_bpf2_of_lr_mask                   (0x00000040)
#define LOUDNESS_STATUS_REGISTER_ld_lpf_of_lsrs_mask                  (0x00000020)
#define LOUDNESS_STATUS_REGISTER_ld_bpf1_of_lsrs_mask                 (0x00000010)
#define LOUDNESS_STATUS_REGISTER_ld_bpf2_of_lsrs_mask                 (0x00000008)
#define LOUDNESS_STATUS_REGISTER_ld_lpf_of_csw_mask                   (0x00000004)
#define LOUDNESS_STATUS_REGISTER_ld_bpf1_of_csw_mask                  (0x00000002)
#define LOUDNESS_STATUS_REGISTER_ld_bpf2_of_csw_mask                  (0x00000001)
#define LOUDNESS_STATUS_REGISTER_ld_lpf_of_lr(data)                   (0x00000100&((data)<<8))
#define LOUDNESS_STATUS_REGISTER_ld_bpf1_of_lr(data)                  (0x00000080&((data)<<7))
#define LOUDNESS_STATUS_REGISTER_ld_bpf2_of_lr(data)                  (0x00000040&((data)<<6))
#define LOUDNESS_STATUS_REGISTER_ld_lpf_of_lsrs(data)                 (0x00000020&((data)<<5))
#define LOUDNESS_STATUS_REGISTER_ld_bpf1_of_lsrs(data)                (0x00000010&((data)<<4))
#define LOUDNESS_STATUS_REGISTER_ld_bpf2_of_lsrs(data)                (0x00000008&((data)<<3))
#define LOUDNESS_STATUS_REGISTER_ld_lpf_of_csw(data)                  (0x00000004&((data)<<2))
#define LOUDNESS_STATUS_REGISTER_ld_bpf1_of_csw(data)                 (0x00000002&((data)<<1))
#define LOUDNESS_STATUS_REGISTER_ld_bpf2_of_csw(data)                 (0x00000001&(data))
#define LOUDNESS_STATUS_REGISTER_get_ld_lpf_of_lr(data)               ((0x00000100&(data))>>8)
#define LOUDNESS_STATUS_REGISTER_get_ld_bpf1_of_lr(data)              ((0x00000080&(data))>>7)
#define LOUDNESS_STATUS_REGISTER_get_ld_bpf2_of_lr(data)              ((0x00000040&(data))>>6)
#define LOUDNESS_STATUS_REGISTER_get_ld_lpf_of_lsrs(data)             ((0x00000020&(data))>>5)
#define LOUDNESS_STATUS_REGISTER_get_ld_bpf1_of_lsrs(data)            ((0x00000010&(data))>>4)
#define LOUDNESS_STATUS_REGISTER_get_ld_bpf2_of_lsrs(data)            ((0x00000008&(data))>>3)
#define LOUDNESS_STATUS_REGISTER_get_ld_lpf_of_csw(data)              ((0x00000004&(data))>>2)
#define LOUDNESS_STATUS_REGISTER_get_ld_bpf1_of_csw(data)             ((0x00000002&(data))>>1)
#define LOUDNESS_STATUS_REGISTER_get_ld_bpf2_of_csw(data)             (0x00000001&(data))


#define SYSTEM_INT_EN                                                 0x180067b4
#define SYSTEM_INT_EN_reg_addr                                        "0xb80067b4"
#define SYSTEM_INT_EN_reg                                             0xb80067b4
#define SYSTEM_INT_EN_inst_addr                                       "0x01ED"
#define SYSTEM_INT_EN_inst                                            0x01ED
#define SYSTEM_INT_EN_eq_ovf_en_shift                                 (17)
#define SYSTEM_INT_EN_loudness_ovf_en_shift                           (16)
#define SYSTEM_INT_EN_dvol_int_en_shift                               (15)
#define SYSTEM_INT_EN_dvol_done_shift                                 (2)
#define SYSTEM_INT_EN_eq_ovf_shift                                    (1)
#define SYSTEM_INT_EN_loudness_ovf_shift                              (0)
#define SYSTEM_INT_EN_eq_ovf_en_mask                                  (0x00020000)
#define SYSTEM_INT_EN_loudness_ovf_en_mask                            (0x00010000)
#define SYSTEM_INT_EN_dvol_int_en_mask                                (0x00008000)
#define SYSTEM_INT_EN_dvol_done_mask                                  (0x00000004)
#define SYSTEM_INT_EN_eq_ovf_mask                                     (0x00000002)
#define SYSTEM_INT_EN_loudness_ovf_mask                               (0x00000001)
#define SYSTEM_INT_EN_eq_ovf_en(data)                                 (0x00020000&((data)<<17))
#define SYSTEM_INT_EN_loudness_ovf_en(data)                           (0x00010000&((data)<<16))
#define SYSTEM_INT_EN_dvol_int_en(data)                               (0x00008000&((data)<<15))
#define SYSTEM_INT_EN_dvol_done(data)                                 (0x00000004&((data)<<2))
#define SYSTEM_INT_EN_eq_ovf(data)                                    (0x00000002&((data)<<1))
#define SYSTEM_INT_EN_loudness_ovf(data)                              (0x00000001&(data))
#define SYSTEM_INT_EN_get_eq_ovf_en(data)                             ((0x00020000&(data))>>17)
#define SYSTEM_INT_EN_get_loudness_ovf_en(data)                       ((0x00010000&(data))>>16)
#define SYSTEM_INT_EN_get_dvol_int_en(data)                           ((0x00008000&(data))>>15)
#define SYSTEM_INT_EN_get_dvol_done(data)                             ((0x00000004&(data))>>2)
#define SYSTEM_INT_EN_get_eq_ovf(data)                                ((0x00000002&(data))>>1)
#define SYSTEM_INT_EN_get_loudness_ovf(data)                          (0x00000001&(data))


#define HW_BACKPLAY_TRANSFER                                          0x180067b8
#define HW_BACKPLAY_TRANSFER_reg_addr                                 "0xb80067b8"
#define HW_BACKPLAY_TRANSFER_reg                                      0xb80067b8
#define HW_BACKPLAY_TRANSFER_inst_addr                                "0x01EE"
#define HW_BACKPLAY_TRANSFER_inst                                     0x01EE
#define HW_BACKPLAY_TRANSFER_hw_l_inverter_en_shift                   (13)
#define HW_BACKPLAY_TRANSFER_hw_r_inverter_en_shift                   (12)
#define HW_BACKPLAY_TRANSFER_hw_out_limiter_en_shift                  (11)
#define HW_BACKPLAY_TRANSFER_hw_out_limiter_shift                     (4)
#define HW_BACKPLAY_TRANSFER_hw_l_inverter_en_mask                    (0x00002000)
#define HW_BACKPLAY_TRANSFER_hw_r_inverter_en_mask                    (0x00001000)
#define HW_BACKPLAY_TRANSFER_hw_out_limiter_en_mask                   (0x00000800)
#define HW_BACKPLAY_TRANSFER_hw_out_limiter_mask                      (0x000007F0)
#define HW_BACKPLAY_TRANSFER_hw_l_inverter_en(data)                   (0x00002000&((data)<<13))
#define HW_BACKPLAY_TRANSFER_hw_r_inverter_en(data)                   (0x00001000&((data)<<12))
#define HW_BACKPLAY_TRANSFER_hw_out_limiter_en(data)                  (0x00000800&((data)<<11))
#define HW_BACKPLAY_TRANSFER_hw_out_limiter(data)                     (0x000007F0&((data)<<4))
#define HW_BACKPLAY_TRANSFER_get_hw_l_inverter_en(data)               ((0x00002000&(data))>>13)
#define HW_BACKPLAY_TRANSFER_get_hw_r_inverter_en(data)               ((0x00001000&(data))>>12)
#define HW_BACKPLAY_TRANSFER_get_hw_out_limiter_en(data)              ((0x00000800&(data))>>11)
#define HW_BACKPLAY_TRANSFER_get_hw_out_limiter(data)                 ((0x000007F0&(data))>>4)


#define HW_OUT_TRANS2                                                 0x180067bc
#define HW_OUT_TRANS2_reg_addr                                        "0xb80067bc"
#define HW_OUT_TRANS2_reg                                             0xb80067bc
#define HW_OUT_TRANS2_inst_addr                                       "0x01EF"
#define HW_OUT_TRANS2_inst                                            0x01EF
#define HW_OUT_TRANS2_dac_pcm_shift                                   (31)
#define HW_OUT_TRANS2_spdif_pcm_shift                                 (30)
#define HW_OUT_TRANS2_i2s_pcm_shift                                   (29)
#define HW_OUT_TRANS2_i2s_out_3_sel_shift                             (26)
#define HW_OUT_TRANS2_i2s_out_2_sel_shift                             (24)
#define HW_OUT_TRANS2_i2s_out_1_sel_shift                             (22)
#define HW_OUT_TRANS2_i2s_out_0_sel_shift                             (20)
#define HW_OUT_TRANS2_spdif_out_sel_shift                             (18)
#define HW_OUT_TRANS2_dac_out_sel_shift                               (16)
#define HW_OUT_TRANS2_hw_mixing_sel_shift                             (4)
#define HW_OUT_TRANS2_w_ch_12_factor_shift                            (2)
#define HW_OUT_TRANS2_w_ch_mix_factor_shift                           (0)
#define HW_OUT_TRANS2_dac_pcm_mask                                    (0x80000000)
#define HW_OUT_TRANS2_spdif_pcm_mask                                  (0x40000000)
#define HW_OUT_TRANS2_i2s_pcm_mask                                    (0x20000000)
#define HW_OUT_TRANS2_i2s_out_3_sel_mask                              (0x0C000000)
#define HW_OUT_TRANS2_i2s_out_2_sel_mask                              (0x03000000)
#define HW_OUT_TRANS2_i2s_out_1_sel_mask                              (0x00C00000)
#define HW_OUT_TRANS2_i2s_out_0_sel_mask                              (0x00300000)
#define HW_OUT_TRANS2_spdif_out_sel_mask                              (0x000C0000)
#define HW_OUT_TRANS2_dac_out_sel_mask                                (0x00030000)
#define HW_OUT_TRANS2_hw_mixing_sel_mask                              (0x00000030)
#define HW_OUT_TRANS2_w_ch_12_factor_mask                             (0x0000000C)
#define HW_OUT_TRANS2_w_ch_mix_factor_mask                            (0x00000003)
#define HW_OUT_TRANS2_dac_pcm(data)                                   (0x80000000&((data)<<31))
#define HW_OUT_TRANS2_spdif_pcm(data)                                 (0x40000000&((data)<<30))
#define HW_OUT_TRANS2_i2s_pcm(data)                                   (0x20000000&((data)<<29))
#define HW_OUT_TRANS2_i2s_out_3_sel(data)                             (0x0C000000&((data)<<26))
#define HW_OUT_TRANS2_i2s_out_2_sel(data)                             (0x03000000&((data)<<24))
#define HW_OUT_TRANS2_i2s_out_1_sel(data)                             (0x00C00000&((data)<<22))
#define HW_OUT_TRANS2_i2s_out_0_sel(data)                             (0x00300000&((data)<<20))
#define HW_OUT_TRANS2_spdif_out_sel(data)                             (0x000C0000&((data)<<18))
#define HW_OUT_TRANS2_dac_out_sel(data)                               (0x00030000&((data)<<16))
#define HW_OUT_TRANS2_hw_mixing_sel(data)                             (0x00000030&((data)<<4))
#define HW_OUT_TRANS2_w_ch_12_factor(data)                            (0x0000000C&((data)<<2))
#define HW_OUT_TRANS2_w_ch_mix_factor(data)                           (0x00000003&(data))
#define HW_OUT_TRANS2_get_dac_pcm(data)                               ((0x80000000&(data))>>31)
#define HW_OUT_TRANS2_get_spdif_pcm(data)                             ((0x40000000&(data))>>30)
#define HW_OUT_TRANS2_get_i2s_pcm(data)                               ((0x20000000&(data))>>29)
#define HW_OUT_TRANS2_get_i2s_out_3_sel(data)                         ((0x0C000000&(data))>>26)
#define HW_OUT_TRANS2_get_i2s_out_2_sel(data)                         ((0x03000000&(data))>>24)
#define HW_OUT_TRANS2_get_i2s_out_1_sel(data)                         ((0x00C00000&(data))>>22)
#define HW_OUT_TRANS2_get_i2s_out_0_sel(data)                         ((0x00300000&(data))>>20)
#define HW_OUT_TRANS2_get_spdif_out_sel(data)                         ((0x000C0000&(data))>>18)
#define HW_OUT_TRANS2_get_dac_out_sel(data)                           ((0x00030000&(data))>>16)
#define HW_OUT_TRANS2_get_hw_mixing_sel(data)                         ((0x00000030&(data))>>4)
#define HW_OUT_TRANS2_get_w_ch_12_factor(data)                        ((0x0000000C&(data))>>2)
#define HW_OUT_TRANS2_get_w_ch_mix_factor(data)                       (0x00000003&(data))


#define PRE_HW_PCM_L_CONTROL                                          0x180067c0
#define PRE_HW_PCM_L_CONTROL_reg_addr                                 "0xb80067c0"
#define PRE_HW_PCM_L_CONTROL_reg                                      0xb80067c0
#define PRE_HW_PCM_L_CONTROL_inst_addr                                "0x01F0"
#define PRE_HW_PCM_L_CONTROL_inst                                     0x01F0
#define PRE_HW_PCM_L_CONTROL_toogle_cnt_shift                         (24)
#define PRE_HW_PCM_L_CONTROL_pre_hw_pcm_l_shift                       (0)
#define PRE_HW_PCM_L_CONTROL_toogle_cnt_mask                          (0xFF000000)
#define PRE_HW_PCM_L_CONTROL_pre_hw_pcm_l_mask                        (0x00FFFFFF)
#define PRE_HW_PCM_L_CONTROL_toogle_cnt(data)                         (0xFF000000&((data)<<24))
#define PRE_HW_PCM_L_CONTROL_pre_hw_pcm_l(data)                       (0x00FFFFFF&(data))
#define PRE_HW_PCM_L_CONTROL_get_toogle_cnt(data)                     ((0xFF000000&(data))>>24)
#define PRE_HW_PCM_L_CONTROL_get_pre_hw_pcm_l(data)                   (0x00FFFFFF&(data))


#define PRE_HW_PCM_R_CONTROL                                          0x180067c4
#define PRE_HW_PCM_R_CONTROL_reg_addr                                 "0xb80067c4"
#define PRE_HW_PCM_R_CONTROL_reg                                      0xb80067c4
#define PRE_HW_PCM_R_CONTROL_inst_addr                                "0x01F1"
#define PRE_HW_PCM_R_CONTROL_inst                                     0x01F1
#define PRE_HW_PCM_R_CONTROL_pre_hw_pcm_sel_shift                     (30)
#define PRE_HW_PCM_R_CONTROL_pre_hw_pcm_r_shift                       (0)
#define PRE_HW_PCM_R_CONTROL_pre_hw_pcm_sel_mask                      (0xC0000000)
#define PRE_HW_PCM_R_CONTROL_pre_hw_pcm_r_mask                        (0x00FFFFFF)
#define PRE_HW_PCM_R_CONTROL_pre_hw_pcm_sel(data)                     (0xC0000000&((data)<<30))
#define PRE_HW_PCM_R_CONTROL_pre_hw_pcm_r(data)                       (0x00FFFFFF&(data))
#define PRE_HW_PCM_R_CONTROL_get_pre_hw_pcm_sel(data)                 ((0xC0000000&(data))>>30)
#define PRE_HW_PCM_R_CONTROL_get_pre_hw_pcm_r(data)                   (0x00FFFFFF&(data))


#define POST_HW_PCM_L_CONTROL                                         0x180067c8
#define POST_HW_PCM_L_CONTROL_reg_addr                                "0xb80067c8"
#define POST_HW_PCM_L_CONTROL_reg                                     0xb80067c8
#define POST_HW_PCM_L_CONTROL_inst_addr                               "0x01F2"
#define POST_HW_PCM_L_CONTROL_inst                                    0x01F2
#define POST_HW_PCM_L_CONTROL_post_hw_pcm_l_shift                     (0)
#define POST_HW_PCM_L_CONTROL_post_hw_pcm_l_mask                      (0x00FFFFFF)
#define POST_HW_PCM_L_CONTROL_post_hw_pcm_l(data)                     (0x00FFFFFF&(data))
#define POST_HW_PCM_L_CONTROL_get_post_hw_pcm_l(data)                 (0x00FFFFFF&(data))


#define POST_HW_PCM_R_CONTROL                                         0x180067cc
#define POST_HW_PCM_R_CONTROL_reg_addr                                "0xb80067cc"
#define POST_HW_PCM_R_CONTROL_reg                                     0xb80067cc
#define POST_HW_PCM_R_CONTROL_inst_addr                               "0x01F3"
#define POST_HW_PCM_R_CONTROL_inst                                    0x01F3
#define POST_HW_PCM_R_CONTROL_post_hw_pcm_sel_shift                   (30)
#define POST_HW_PCM_R_CONTROL_post_hw_pcm_r_shift                     (0)
#define POST_HW_PCM_R_CONTROL_post_hw_pcm_sel_mask                    (0xC0000000)
#define POST_HW_PCM_R_CONTROL_post_hw_pcm_r_mask                      (0x00FFFFFF)
#define POST_HW_PCM_R_CONTROL_post_hw_pcm_sel(data)                   (0xC0000000&((data)<<30))
#define POST_HW_PCM_R_CONTROL_post_hw_pcm_r(data)                     (0x00FFFFFF&(data))
#define POST_HW_PCM_R_CONTROL_get_post_hw_pcm_sel(data)               ((0xC0000000&(data))>>30)
#define POST_HW_PCM_R_CONTROL_get_post_hw_pcm_r(data)                 (0x00FFFFFF&(data))


#define AVC_LP_OUT_CONTROL                                            0x180067d0
#define AVC_LP_OUT_CONTROL_reg_addr                                   "0xb80067d0"
#define AVC_LP_OUT_CONTROL_reg                                        0xb80067d0
#define AVC_LP_OUT_CONTROL_inst_addr                                  "0x01F4"
#define AVC_LP_OUT_CONTROL_inst                                       0x01F4
#define AVC_LP_OUT_CONTROL_avc_lp_out_shift                           (0)
#define AVC_LP_OUT_CONTROL_avc_lp_out_mask                            (0x00FFFFFF)
#define AVC_LP_OUT_CONTROL_avc_lp_out(data)                           (0x00FFFFFF&(data))
#define AVC_LP_OUT_CONTROL_get_avc_lp_out(data)                       (0x00FFFFFF&(data))


#define EQ_A1_4                                                       0x180067d4
#define EQ_A1_4_reg_addr                                              "0xb80067d4"
#define EQ_A1_4_reg                                                   0xb80067d4
#define EQ_A1_4_inst_addr                                             "0x01F5"
#define EQ_A1_4_inst                                                  0x01F5
#define EQ_A1_4_eq_bp4_2_a1_shift                                     (16)
#define EQ_A1_4_eq_bp4_1_a1_shift                                     (0)
#define EQ_A1_4_eq_bp4_2_a1_mask                                      (0xFFFF0000)
#define EQ_A1_4_eq_bp4_1_a1_mask                                      (0x0000FFFF)
#define EQ_A1_4_eq_bp4_2_a1(data)                                     (0xFFFF0000&((data)<<16))
#define EQ_A1_4_eq_bp4_1_a1(data)                                     (0x0000FFFF&(data))
#define EQ_A1_4_get_eq_bp4_2_a1(data)                                 ((0xFFFF0000&(data))>>16)
#define EQ_A1_4_get_eq_bp4_1_a1(data)                                 (0x0000FFFF&(data))


#define EQ_A2_4                                                       0x180067d8
#define EQ_A2_4_reg_addr                                              "0xb80067d8"
#define EQ_A2_4_reg                                                   0xb80067d8
#define EQ_A2_4_inst_addr                                             "0x01F6"
#define EQ_A2_4_inst                                                  0x01F6
#define EQ_A2_4_eq_bp4_2_a2_shift                                     (16)
#define EQ_A2_4_eq_bp4_1_a2_shift                                     (0)
#define EQ_A2_4_eq_bp4_2_a2_mask                                      (0xFFFF0000)
#define EQ_A2_4_eq_bp4_1_a2_mask                                      (0x0000FFFF)
#define EQ_A2_4_eq_bp4_2_a2(data)                                     (0xFFFF0000&((data)<<16))
#define EQ_A2_4_eq_bp4_1_a2(data)                                     (0x0000FFFF&(data))
#define EQ_A2_4_get_eq_bp4_2_a2(data)                                 ((0xFFFF0000&(data))>>16)
#define EQ_A2_4_get_eq_bp4_1_a2(data)                                 (0x0000FFFF&(data))


#define EQ_H0_4                                                       0x180067dc
#define EQ_H0_4_reg_addr                                              "0xb80067dc"
#define EQ_H0_4_reg                                                   0xb80067dc
#define EQ_H0_4_inst_addr                                             "0x01F7"
#define EQ_H0_4_inst                                                  0x01F7
#define EQ_H0_4_eq_bp4_2_h0_shift                                     (16)
#define EQ_H0_4_eq_bp4_1_h0_shift                                     (0)
#define EQ_H0_4_eq_bp4_2_h0_mask                                      (0xFFFF0000)
#define EQ_H0_4_eq_bp4_1_h0_mask                                      (0x0000FFFF)
#define EQ_H0_4_eq_bp4_2_h0(data)                                     (0xFFFF0000&((data)<<16))
#define EQ_H0_4_eq_bp4_1_h0(data)                                     (0x0000FFFF&(data))
#define EQ_H0_4_get_eq_bp4_2_h0(data)                                 ((0xFFFF0000&(data))>>16)
#define EQ_H0_4_get_eq_bp4_1_h0(data)                                 (0x0000FFFF&(data))


#define LRRR_DIGITAL_VOLUME_CONTROL_0                                 0x18006800
#define LRRR_DIGITAL_VOLUME_CONTROL_0_reg_addr                        "0xb8006800"
#define LRRR_DIGITAL_VOLUME_CONTROL_0_reg                             0xb8006800
#define LRRR_DIGITAL_VOLUME_CONTROL_0_inst_addr                       "0x0200"
#define LRRR_DIGITAL_VOLUME_CONTROL_0_inst                            0x0200
#define LRRR_DIGITAL_VOLUME_CONTROL_0_lrrr_dvol_apply_shift           (31)
#define LRRR_DIGITAL_VOLUME_CONTROL_0_lrrr_zcto_shift                 (28)
#define LRRR_DIGITAL_VOLUME_CONTROL_0_lrrr_ramp_step_shift            (26)
#define LRRR_DIGITAL_VOLUME_CONTROL_0_lrrr_delay_ctrl_shift           (16)
#define LRRR_DIGITAL_VOLUME_CONTROL_0_lrrr_mute_apply_shift           (15)
#define LRRR_DIGITAL_VOLUME_CONTROL_0_lrrr_zcto_mute_shift            (12)
#define LRRR_DIGITAL_VOLUME_CONTROL_0_lrrr_ramp_step_mute_shift       (10)
#define LRRR_DIGITAL_VOLUME_CONTROL_0_lrrr_delay_ctrl_mute_shift      (0)
#define LRRR_DIGITAL_VOLUME_CONTROL_0_lrrr_dvol_apply_mask            (0x80000000)
#define LRRR_DIGITAL_VOLUME_CONTROL_0_lrrr_zcto_mask                  (0x70000000)
#define LRRR_DIGITAL_VOLUME_CONTROL_0_lrrr_ramp_step_mask             (0x0C000000)
#define LRRR_DIGITAL_VOLUME_CONTROL_0_lrrr_delay_ctrl_mask            (0x03FF0000)
#define LRRR_DIGITAL_VOLUME_CONTROL_0_lrrr_mute_apply_mask            (0x00008000)
#define LRRR_DIGITAL_VOLUME_CONTROL_0_lrrr_zcto_mute_mask             (0x00007000)
#define LRRR_DIGITAL_VOLUME_CONTROL_0_lrrr_ramp_step_mute_mask        (0x00000C00)
#define LRRR_DIGITAL_VOLUME_CONTROL_0_lrrr_delay_ctrl_mute_mask       (0x000003FF)
#define LRRR_DIGITAL_VOLUME_CONTROL_0_lrrr_dvol_apply(data)           (0x80000000&((data)<<31))
#define LRRR_DIGITAL_VOLUME_CONTROL_0_lrrr_zcto(data)                 (0x70000000&((data)<<28))
#define LRRR_DIGITAL_VOLUME_CONTROL_0_lrrr_ramp_step(data)            (0x0C000000&((data)<<26))
#define LRRR_DIGITAL_VOLUME_CONTROL_0_lrrr_delay_ctrl(data)           (0x03FF0000&((data)<<16))
#define LRRR_DIGITAL_VOLUME_CONTROL_0_lrrr_mute_apply(data)           (0x00008000&((data)<<15))
#define LRRR_DIGITAL_VOLUME_CONTROL_0_lrrr_zcto_mute(data)            (0x00007000&((data)<<12))
#define LRRR_DIGITAL_VOLUME_CONTROL_0_lrrr_ramp_step_mute(data)       (0x00000C00&((data)<<10))
#define LRRR_DIGITAL_VOLUME_CONTROL_0_lrrr_delay_ctrl_mute(data)      (0x000003FF&(data))
#define LRRR_DIGITAL_VOLUME_CONTROL_0_get_lrrr_dvol_apply(data)       ((0x80000000&(data))>>31)
#define LRRR_DIGITAL_VOLUME_CONTROL_0_get_lrrr_zcto(data)             ((0x70000000&(data))>>28)
#define LRRR_DIGITAL_VOLUME_CONTROL_0_get_lrrr_ramp_step(data)        ((0x0C000000&(data))>>26)
#define LRRR_DIGITAL_VOLUME_CONTROL_0_get_lrrr_delay_ctrl(data)       ((0x03FF0000&(data))>>16)
#define LRRR_DIGITAL_VOLUME_CONTROL_0_get_lrrr_mute_apply(data)       ((0x00008000&(data))>>15)
#define LRRR_DIGITAL_VOLUME_CONTROL_0_get_lrrr_zcto_mute(data)        ((0x00007000&(data))>>12)
#define LRRR_DIGITAL_VOLUME_CONTROL_0_get_lrrr_ramp_step_mute(data)   ((0x00000C00&(data))>>10)
#define LRRR_DIGITAL_VOLUME_CONTROL_0_get_lrrr_delay_ctrl_mute(data)  (0x000003FF&(data))


#define LRRR_DIGITAL_VOLUME_CONTROL_1                                 0x18006804
#define LRRR_DIGITAL_VOLUME_CONTROL_1_reg_addr                        "0xb8006804"
#define LRRR_DIGITAL_VOLUME_CONTROL_1_reg                             0xb8006804
#define LRRR_DIGITAL_VOLUME_CONTROL_1_inst_addr                       "0x0201"
#define LRRR_DIGITAL_VOLUME_CONTROL_1_inst                            0x0201
#define LRRR_DIGITAL_VOLUME_CONTROL_1_lrrr_dvol_enable_shift          (10)
#define LRRR_DIGITAL_VOLUME_CONTROL_1_lrrr_zcto_status_shift          (9)
#define LRRR_DIGITAL_VOLUME_CONTROL_1_lrrr_zcth_shift                 (4)
#define LRRR_DIGITAL_VOLUME_CONTROL_1_lrrr_dvcm_shift                 (0)
#define LRRR_DIGITAL_VOLUME_CONTROL_1_lrrr_dvol_enable_mask           (0x00000400)
#define LRRR_DIGITAL_VOLUME_CONTROL_1_lrrr_zcto_status_mask           (0x00000200)
#define LRRR_DIGITAL_VOLUME_CONTROL_1_lrrr_zcth_mask                  (0x000001F0)
#define LRRR_DIGITAL_VOLUME_CONTROL_1_lrrr_dvcm_mask                  (0x00000003)
#define LRRR_DIGITAL_VOLUME_CONTROL_1_lrrr_dvol_enable(data)          (0x00000400&((data)<<10))
#define LRRR_DIGITAL_VOLUME_CONTROL_1_lrrr_zcto_status(data)          (0x00000200&((data)<<9))
#define LRRR_DIGITAL_VOLUME_CONTROL_1_lrrr_zcth(data)                 (0x000001F0&((data)<<4))
#define LRRR_DIGITAL_VOLUME_CONTROL_1_lrrr_dvcm(data)                 (0x00000003&(data))
#define LRRR_DIGITAL_VOLUME_CONTROL_1_get_lrrr_dvol_enable(data)      ((0x00000400&(data))>>10)
#define LRRR_DIGITAL_VOLUME_CONTROL_1_get_lrrr_zcto_status(data)      ((0x00000200&(data))>>9)
#define LRRR_DIGITAL_VOLUME_CONTROL_1_get_lrrr_zcth(data)             ((0x000001F0&(data))>>4)
#define LRRR_DIGITAL_VOLUME_CONTROL_1_get_lrrr_dvcm(data)             (0x00000003&(data))


#define LRRR_DIGITAL_VOLUME_CONTROL_2                                 0x18006808
#define LRRR_DIGITAL_VOLUME_CONTROL_2_reg_addr                        "0xb8006808"
#define LRRR_DIGITAL_VOLUME_CONTROL_2_reg                             0xb8006808
#define LRRR_DIGITAL_VOLUME_CONTROL_2_inst_addr                       "0x0202"
#define LRRR_DIGITAL_VOLUME_CONTROL_2_inst                            0x0202
#define LRRR_DIGITAL_VOLUME_CONTROL_2_mute_lr_shift                   (31)
#define LRRR_DIGITAL_VOLUME_CONTROL_2_hpf_lr_enable_shift             (28)
#define LRRR_DIGITAL_VOLUME_CONTROL_2_vol_lr_ready_shift              (27)
#define LRRR_DIGITAL_VOLUME_CONTROL_2_vol_lr_a_shift                  (22)
#define LRRR_DIGITAL_VOLUME_CONTROL_2_vol_lr_b_shift                  (16)
#define LRRR_DIGITAL_VOLUME_CONTROL_2_mute_rr_shift                   (15)
#define LRRR_DIGITAL_VOLUME_CONTROL_2_hpf_rr_enable_shift             (12)
#define LRRR_DIGITAL_VOLUME_CONTROL_2_vol_rr_ready_shift              (11)
#define LRRR_DIGITAL_VOLUME_CONTROL_2_vol_rr_a_shift                  (6)
#define LRRR_DIGITAL_VOLUME_CONTROL_2_vol_rr_b_shift                  (0)
#define LRRR_DIGITAL_VOLUME_CONTROL_2_mute_lr_mask                    (0x80000000)
#define LRRR_DIGITAL_VOLUME_CONTROL_2_hpf_lr_enable_mask              (0x10000000)
#define LRRR_DIGITAL_VOLUME_CONTROL_2_vol_lr_ready_mask               (0x08000000)
#define LRRR_DIGITAL_VOLUME_CONTROL_2_vol_lr_a_mask                   (0x07C00000)
#define LRRR_DIGITAL_VOLUME_CONTROL_2_vol_lr_b_mask                   (0x003F0000)
#define LRRR_DIGITAL_VOLUME_CONTROL_2_mute_rr_mask                    (0x00008000)
#define LRRR_DIGITAL_VOLUME_CONTROL_2_hpf_rr_enable_mask              (0x00001000)
#define LRRR_DIGITAL_VOLUME_CONTROL_2_vol_rr_ready_mask               (0x00000800)
#define LRRR_DIGITAL_VOLUME_CONTROL_2_vol_rr_a_mask                   (0x000007C0)
#define LRRR_DIGITAL_VOLUME_CONTROL_2_vol_rr_b_mask                   (0x0000003F)
#define LRRR_DIGITAL_VOLUME_CONTROL_2_mute_lr(data)                   (0x80000000&((data)<<31))
#define LRRR_DIGITAL_VOLUME_CONTROL_2_hpf_lr_enable(data)             (0x10000000&((data)<<28))
#define LRRR_DIGITAL_VOLUME_CONTROL_2_vol_lr_ready(data)              (0x08000000&((data)<<27))
#define LRRR_DIGITAL_VOLUME_CONTROL_2_vol_lr_a(data)                  (0x07C00000&((data)<<22))
#define LRRR_DIGITAL_VOLUME_CONTROL_2_vol_lr_b(data)                  (0x003F0000&((data)<<16))
#define LRRR_DIGITAL_VOLUME_CONTROL_2_mute_rr(data)                   (0x00008000&((data)<<15))
#define LRRR_DIGITAL_VOLUME_CONTROL_2_hpf_rr_enable(data)             (0x00001000&((data)<<12))
#define LRRR_DIGITAL_VOLUME_CONTROL_2_vol_rr_ready(data)              (0x00000800&((data)<<11))
#define LRRR_DIGITAL_VOLUME_CONTROL_2_vol_rr_a(data)                  (0x000007C0&((data)<<6))
#define LRRR_DIGITAL_VOLUME_CONTROL_2_vol_rr_b(data)                  (0x0000003F&(data))
#define LRRR_DIGITAL_VOLUME_CONTROL_2_get_mute_lr(data)               ((0x80000000&(data))>>31)
#define LRRR_DIGITAL_VOLUME_CONTROL_2_get_hpf_lr_enable(data)         ((0x10000000&(data))>>28)
#define LRRR_DIGITAL_VOLUME_CONTROL_2_get_vol_lr_ready(data)          ((0x08000000&(data))>>27)
#define LRRR_DIGITAL_VOLUME_CONTROL_2_get_vol_lr_a(data)              ((0x07C00000&(data))>>22)
#define LRRR_DIGITAL_VOLUME_CONTROL_2_get_vol_lr_b(data)              ((0x003F0000&(data))>>16)
#define LRRR_DIGITAL_VOLUME_CONTROL_2_get_mute_rr(data)               ((0x00008000&(data))>>15)
#define LRRR_DIGITAL_VOLUME_CONTROL_2_get_hpf_rr_enable(data)         ((0x00001000&(data))>>12)
#define LRRR_DIGITAL_VOLUME_CONTROL_2_get_vol_rr_ready(data)          ((0x00000800&(data))>>11)
#define LRRR_DIGITAL_VOLUME_CONTROL_2_get_vol_rr_a(data)              ((0x000007C0&(data))>>6)
#define LRRR_DIGITAL_VOLUME_CONTROL_2_get_vol_rr_b(data)              (0x0000003F&(data))


#define TS_DS_MBIST_RECODING                                          0x18006810
#define TS_DS_MBIST_RECODING_reg_addr                                 "0xb8006810"
#define TS_DS_MBIST_RECODING_reg                                      0xb8006810
#define TS_DS_MBIST_RECODING_inst_addr                                "0x0204"
#define TS_DS_MBIST_RECODING_inst                                     0x0204
#define TS_DS_MBIST_RECODING_dummy18006810_31_0_shift                 (0)
#define TS_DS_MBIST_RECODING_dummy18006810_31_0_mask                  (0xFFFFFFFF)
#define TS_DS_MBIST_RECODING_dummy18006810_31_0(data)                 (0xFFFFFFFF&(data))
#define TS_DS_MBIST_RECODING_get_dummy18006810_31_0(data)             (0xFFFFFFFF&(data))


#define DVOL_CONTROL                                                  0x18006814
#define DVOL_CONTROL_reg_addr                                         "0xb8006814"
#define DVOL_CONTROL_reg                                              0xb8006814
#define DVOL_CONTROL_inst_addr                                        "0x0205"
#define DVOL_CONTROL_inst                                             0x0205
#define DVOL_CONTROL_ts_dac_pcm_shift                                 (31)
#define DVOL_CONTROL_ts_spdif_pcm_shift                               (30)
#define DVOL_CONTROL_ts_i2s_pcm_shift                                 (29)
#define DVOL_CONTROL_scart_l_inverter_en_shift                        (13)
#define DVOL_CONTROL_scart_r_inverter_en_shift                        (12)
#define DVOL_CONTROL_scart_out_limiter_en_shift                       (11)
#define DVOL_CONTROL_scart_out_limiter_shift                          (4)
#define DVOL_CONTROL_vol_source_sel_shift                             (0)
#define DVOL_CONTROL_ts_dac_pcm_mask                                  (0x80000000)
#define DVOL_CONTROL_ts_spdif_pcm_mask                                (0x40000000)
#define DVOL_CONTROL_ts_i2s_pcm_mask                                  (0x20000000)
#define DVOL_CONTROL_scart_l_inverter_en_mask                         (0x00002000)
#define DVOL_CONTROL_scart_r_inverter_en_mask                         (0x00001000)
#define DVOL_CONTROL_scart_out_limiter_en_mask                        (0x00000800)
#define DVOL_CONTROL_scart_out_limiter_mask                           (0x000007F0)
#define DVOL_CONTROL_vol_source_sel_mask                              (0x00000001)
#define DVOL_CONTROL_ts_dac_pcm(data)                                 (0x80000000&((data)<<31))
#define DVOL_CONTROL_ts_spdif_pcm(data)                               (0x40000000&((data)<<30))
#define DVOL_CONTROL_ts_i2s_pcm(data)                                 (0x20000000&((data)<<29))
#define DVOL_CONTROL_scart_l_inverter_en(data)                        (0x00002000&((data)<<13))
#define DVOL_CONTROL_scart_r_inverter_en(data)                        (0x00001000&((data)<<12))
#define DVOL_CONTROL_scart_out_limiter_en(data)                       (0x00000800&((data)<<11))
#define DVOL_CONTROL_scart_out_limiter(data)                          (0x000007F0&((data)<<4))
#define DVOL_CONTROL_vol_source_sel(data)                             (0x00000001&(data))
#define DVOL_CONTROL_get_ts_dac_pcm(data)                             ((0x80000000&(data))>>31)
#define DVOL_CONTROL_get_ts_spdif_pcm(data)                           ((0x40000000&(data))>>30)
#define DVOL_CONTROL_get_ts_i2s_pcm(data)                             ((0x20000000&(data))>>29)
#define DVOL_CONTROL_get_scart_l_inverter_en(data)                    ((0x00002000&(data))>>13)
#define DVOL_CONTROL_get_scart_r_inverter_en(data)                    ((0x00001000&(data))>>12)
#define DVOL_CONTROL_get_scart_out_limiter_en(data)                   ((0x00000800&(data))>>11)
#define DVOL_CONTROL_get_scart_out_limiter(data)                      ((0x000007F0&(data))>>4)
#define DVOL_CONTROL_get_vol_source_sel(data)                         (0x00000001&(data))


#define DOWN_SAMPLE_CONTROL_FOR_TS                                    0x18006818
#define DOWN_SAMPLE_CONTROL_FOR_TS_reg_addr                           "0xb8006818"
#define DOWN_SAMPLE_CONTROL_FOR_TS_reg                                0xb8006818
#define DOWN_SAMPLE_CONTROL_FOR_TS_inst_addr                          "0x0206"
#define DOWN_SAMPLE_CONTROL_FOR_TS_inst                               0x0206
#define DOWN_SAMPLE_CONTROL_FOR_TS_fifo_ch1_source_shift              (18)
#define DOWN_SAMPLE_CONTROL_FOR_TS_fifo_ch2_source_shift              (16)
#define DOWN_SAMPLE_CONTROL_FOR_TS_fifo_ch12_sel_shift                (12)
#define DOWN_SAMPLE_CONTROL_FOR_TS_fifo_ch12_scale_shift              (8)
#define DOWN_SAMPLE_CONTROL_FOR_TS_backend_play_en_shift              (2)
#define DOWN_SAMPLE_CONTROL_FOR_TS_downsample_en_shift                (1)
#define DOWN_SAMPLE_CONTROL_FOR_TS_down_rate_shift                    (0)
#define DOWN_SAMPLE_CONTROL_FOR_TS_fifo_ch1_source_mask               (0x000C0000)
#define DOWN_SAMPLE_CONTROL_FOR_TS_fifo_ch2_source_mask               (0x00030000)
#define DOWN_SAMPLE_CONTROL_FOR_TS_fifo_ch12_sel_mask                 (0x0000F000)
#define DOWN_SAMPLE_CONTROL_FOR_TS_fifo_ch12_scale_mask               (0x00000F00)
#define DOWN_SAMPLE_CONTROL_FOR_TS_backend_play_en_mask               (0x00000004)
#define DOWN_SAMPLE_CONTROL_FOR_TS_downsample_en_mask                 (0x00000002)
#define DOWN_SAMPLE_CONTROL_FOR_TS_down_rate_mask                     (0x00000001)
#define DOWN_SAMPLE_CONTROL_FOR_TS_fifo_ch1_source(data)              (0x000C0000&((data)<<18))
#define DOWN_SAMPLE_CONTROL_FOR_TS_fifo_ch2_source(data)              (0x00030000&((data)<<16))
#define DOWN_SAMPLE_CONTROL_FOR_TS_fifo_ch12_sel(data)                (0x0000F000&((data)<<12))
#define DOWN_SAMPLE_CONTROL_FOR_TS_fifo_ch12_scale(data)              (0x00000F00&((data)<<8))
#define DOWN_SAMPLE_CONTROL_FOR_TS_backend_play_en(data)              (0x00000004&((data)<<2))
#define DOWN_SAMPLE_CONTROL_FOR_TS_downsample_en(data)                (0x00000002&((data)<<1))
#define DOWN_SAMPLE_CONTROL_FOR_TS_down_rate(data)                    (0x00000001&(data))
#define DOWN_SAMPLE_CONTROL_FOR_TS_get_fifo_ch1_source(data)          ((0x000C0000&(data))>>18)
#define DOWN_SAMPLE_CONTROL_FOR_TS_get_fifo_ch2_source(data)          ((0x00030000&(data))>>16)
#define DOWN_SAMPLE_CONTROL_FOR_TS_get_fifo_ch12_sel(data)            ((0x0000F000&(data))>>12)
#define DOWN_SAMPLE_CONTROL_FOR_TS_get_fifo_ch12_scale(data)          ((0x00000F00&(data))>>8)
#define DOWN_SAMPLE_CONTROL_FOR_TS_get_backend_play_en(data)          ((0x00000004&(data))>>2)
#define DOWN_SAMPLE_CONTROL_FOR_TS_get_downsample_en(data)            ((0x00000002&(data))>>1)
#define DOWN_SAMPLE_CONTROL_FOR_TS_get_down_rate(data)                (0x00000001&(data))


#define TS_DS_FIFO_MBIST                                              0x1800681c
#define TS_DS_FIFO_MBIST_reg_addr                                     "0xb800681c"
#define TS_DS_FIFO_MBIST_reg                                          0xb800681c
#define TS_DS_FIFO_MBIST_inst_addr                                    "0x0207"
#define TS_DS_FIFO_MBIST_inst                                         0x0207
#define TS_DS_FIFO_MBIST_dummy1800681c_31_14_shift                    (14)
#define TS_DS_FIFO_MBIST_dvse_0_ts_ds_shift                           (13)
#define TS_DS_FIFO_MBIST_dvs_0_ts_ds_shift                            (9)
#define TS_DS_FIFO_MBIST_drf_ts_ds_start_pause_shift                  (8)
#define TS_DS_FIFO_MBIST_drf_ts_ds_test_resume_shift                  (7)
#define TS_DS_FIFO_MBIST_drf_ts_ds_bist_mode_shift                    (6)
#define TS_DS_FIFO_MBIST_drf_ts_ds_bist_done_shift                    (5)
#define TS_DS_FIFO_MBIST_drf_ts_ds_bist_fail_shift                    (4)
#define TS_DS_FIFO_MBIST_ts_ds_bist_rstn_shift                        (3)
#define TS_DS_FIFO_MBIST_ts_ds_bist_mode_shift                        (2)
#define TS_DS_FIFO_MBIST_ts_ds_bist_done_shift                        (1)
#define TS_DS_FIFO_MBIST_ts_ds_bist_fail_shift                        (0)
#define TS_DS_FIFO_MBIST_dummy1800681c_31_14_mask                     (0xFFFFC000)
#define TS_DS_FIFO_MBIST_dvse_0_ts_ds_mask                            (0x00002000)
#define TS_DS_FIFO_MBIST_dvs_0_ts_ds_mask                             (0x00001E00)
#define TS_DS_FIFO_MBIST_drf_ts_ds_start_pause_mask                   (0x00000100)
#define TS_DS_FIFO_MBIST_drf_ts_ds_test_resume_mask                   (0x00000080)
#define TS_DS_FIFO_MBIST_drf_ts_ds_bist_mode_mask                     (0x00000040)
#define TS_DS_FIFO_MBIST_drf_ts_ds_bist_done_mask                     (0x00000020)
#define TS_DS_FIFO_MBIST_drf_ts_ds_bist_fail_mask                     (0x00000010)
#define TS_DS_FIFO_MBIST_ts_ds_bist_rstn_mask                         (0x00000008)
#define TS_DS_FIFO_MBIST_ts_ds_bist_mode_mask                         (0x00000004)
#define TS_DS_FIFO_MBIST_ts_ds_bist_done_mask                         (0x00000002)
#define TS_DS_FIFO_MBIST_ts_ds_bist_fail_mask                         (0x00000001)
#define TS_DS_FIFO_MBIST_dummy1800681c_31_14(data)                    (0xFFFFC000&((data)<<14))
#define TS_DS_FIFO_MBIST_dvse_0_ts_ds(data)                           (0x00002000&((data)<<13))
#define TS_DS_FIFO_MBIST_dvs_0_ts_ds(data)                            (0x00001E00&((data)<<9))
#define TS_DS_FIFO_MBIST_drf_ts_ds_start_pause(data)                  (0x00000100&((data)<<8))
#define TS_DS_FIFO_MBIST_drf_ts_ds_test_resume(data)                  (0x00000080&((data)<<7))
#define TS_DS_FIFO_MBIST_drf_ts_ds_bist_mode(data)                    (0x00000040&((data)<<6))
#define TS_DS_FIFO_MBIST_drf_ts_ds_bist_done(data)                    (0x00000020&((data)<<5))
#define TS_DS_FIFO_MBIST_drf_ts_ds_bist_fail(data)                    (0x00000010&((data)<<4))
#define TS_DS_FIFO_MBIST_ts_ds_bist_rstn(data)                        (0x00000008&((data)<<3))
#define TS_DS_FIFO_MBIST_ts_ds_bist_mode(data)                        (0x00000004&((data)<<2))
#define TS_DS_FIFO_MBIST_ts_ds_bist_done(data)                        (0x00000002&((data)<<1))
#define TS_DS_FIFO_MBIST_ts_ds_bist_fail(data)                        (0x00000001&(data))
#define TS_DS_FIFO_MBIST_get_dummy1800681c_31_14(data)                ((0xFFFFC000&(data))>>14)
#define TS_DS_FIFO_MBIST_get_dvse_0_ts_ds(data)                       ((0x00002000&(data))>>13)
#define TS_DS_FIFO_MBIST_get_dvs_0_ts_ds(data)                        ((0x00001E00&(data))>>9)
#define TS_DS_FIFO_MBIST_get_drf_ts_ds_start_pause(data)              ((0x00000100&(data))>>8)
#define TS_DS_FIFO_MBIST_get_drf_ts_ds_test_resume(data)              ((0x00000080&(data))>>7)
#define TS_DS_FIFO_MBIST_get_drf_ts_ds_bist_mode(data)                ((0x00000040&(data))>>6)
#define TS_DS_FIFO_MBIST_get_drf_ts_ds_bist_done(data)                ((0x00000020&(data))>>5)
#define TS_DS_FIFO_MBIST_get_drf_ts_ds_bist_fail(data)                ((0x00000010&(data))>>4)
#define TS_DS_FIFO_MBIST_get_ts_ds_bist_rstn(data)                    ((0x00000008&(data))>>3)
#define TS_DS_FIFO_MBIST_get_ts_ds_bist_mode(data)                    ((0x00000004&(data))>>2)
#define TS_DS_FIFO_MBIST_get_ts_ds_bist_done(data)                    ((0x00000002&(data))>>1)
#define TS_DS_FIFO_MBIST_get_ts_ds_bist_fail(data)                    (0x00000001&(data))


#define TEST_PATTERN_GEN                                              0x18006850
#define TEST_PATTERN_GEN_reg_addr                                     "0xb8006850"
#define TEST_PATTERN_GEN_reg                                          0xb8006850
#define TEST_PATTERN_GEN_inst_addr                                    "0x0214"
#define TEST_PATTERN_GEN_inst                                         0x0214
#define TEST_PATTERN_GEN_sif_adc_in_test_en_shift                     (13)
#define TEST_PATTERN_GEN_sif_adc_in_test_sel_shift                    (12)
#define TEST_PATTERN_GEN_debug_mode_sel_shift                         (0)
#define TEST_PATTERN_GEN_sif_adc_in_test_en_mask                      (0x00002000)
#define TEST_PATTERN_GEN_sif_adc_in_test_sel_mask                     (0x00001000)
#define TEST_PATTERN_GEN_debug_mode_sel_mask                          (0x000000FF)
#define TEST_PATTERN_GEN_sif_adc_in_test_en(data)                     (0x00002000&((data)<<13))
#define TEST_PATTERN_GEN_sif_adc_in_test_sel(data)                    (0x00001000&((data)<<12))
#define TEST_PATTERN_GEN_debug_mode_sel(data)                         (0x000000FF&(data))
#define TEST_PATTERN_GEN_get_sif_adc_in_test_en(data)                 ((0x00002000&(data))>>13)
#define TEST_PATTERN_GEN_get_sif_adc_in_test_sel(data)                ((0x00001000&(data))>>12)
#define TEST_PATTERN_GEN_get_debug_mode_sel(data)                     (0x000000FF&(data))


#define CRC_HEADER                                                    0x18006854
#define CRC_HEADER_reg_addr                                           "0xb8006854"
#define CRC_HEADER_reg                                                0xb8006854
#define CRC_HEADER_inst_addr                                          "0x0215"
#define CRC_HEADER_inst                                               0x0215
#define CRC_HEADER_audio_crc_header_shift                             (0)
#define CRC_HEADER_audio_crc_header_mask                              (0x00FFFFFF)
#define CRC_HEADER_audio_crc_header(data)                             (0x00FFFFFF&(data))
#define CRC_HEADER_get_audio_crc_header(data)                         (0x00FFFFFF&(data))


#define CRC_CONTORL                                                   0x18006858
#define CRC_CONTORL_reg_addr                                          "0xb8006858"
#define CRC_CONTORL_reg                                               0xb8006858
#define CRC_CONTORL_inst_addr                                         "0x0216"
#define CRC_CONTORL_inst                                              0x0216
#define CRC_CONTORL_audio_crc_en_shift                                (19)
#define CRC_CONTORL_audio_crc_ch_sel_shift                            (16)
#define CRC_CONTORL_audio_crc_frame_length_shift                      (0)
#define CRC_CONTORL_audio_crc_en_mask                                 (0x00080000)
#define CRC_CONTORL_audio_crc_ch_sel_mask                             (0x00070000)
#define CRC_CONTORL_audio_crc_frame_length_mask                       (0x0000FFFF)
#define CRC_CONTORL_audio_crc_en(data)                                (0x00080000&((data)<<19))
#define CRC_CONTORL_audio_crc_ch_sel(data)                            (0x00070000&((data)<<16))
#define CRC_CONTORL_audio_crc_frame_length(data)                      (0x0000FFFF&(data))
#define CRC_CONTORL_get_audio_crc_en(data)                            ((0x00080000&(data))>>19)
#define CRC_CONTORL_get_audio_crc_ch_sel(data)                        ((0x00070000&(data))>>16)
#define CRC_CONTORL_get_audio_crc_frame_length(data)                  (0x0000FFFF&(data))


#define CRC_STATUS                                                    0x1800685c
#define CRC_STATUS_reg_addr                                           "0xb800685c"
#define CRC_STATUS_reg                                                0xb800685c
#define CRC_STATUS_inst_addr                                          "0x0217"
#define CRC_STATUS_inst                                               0x0217
#define CRC_STATUS_audio_crc_done_shift                               (24)
#define CRC_STATUS_audio_crc_shift                                    (0)
#define CRC_STATUS_audio_crc_done_mask                                (0x01000000)
#define CRC_STATUS_audio_crc_mask                                     (0x00FFFFFF)
#define CRC_STATUS_audio_crc_done(data)                               (0x01000000&((data)<<24))
#define CRC_STATUS_audio_crc(data)                                    (0x00FFFFFF&(data))
#define CRC_STATUS_get_audio_crc_done(data)                           ((0x01000000&(data))>>24)
#define CRC_STATUS_get_audio_crc(data)                                (0x00FFFFFF&(data))


#define SINE_AUTO_CHK                                                 0x18006864
#define SINE_AUTO_CHK_reg_addr                                        "0xb8006864"
#define SINE_AUTO_CHK_reg                                             0xb8006864
#define SINE_AUTO_CHK_inst_addr                                       "0x0219"
#define SINE_AUTO_CHK_inst                                            0x0219
#define SINE_AUTO_CHK_sine_auto_chk_en_shift                          (31)
#define SINE_AUTO_CHK_sine_channel_select_shift                       (28)
#define SINE_AUTO_CHK_auto_chk_result_shift                           (24)
#define SINE_AUTO_CHK_half_sine_num_shift                             (22)
#define SINE_AUTO_CHK_amplitude_low_threshold_shift                   (20)
#define SINE_AUTO_CHK_zc_sample_cnt_threshold_shift                   (12)
#define SINE_AUTO_CHK_zc_sample_cnt_golden_shift                      (0)
#define SINE_AUTO_CHK_sine_auto_chk_en_mask                           (0x80000000)
#define SINE_AUTO_CHK_sine_channel_select_mask                        (0x70000000)
#define SINE_AUTO_CHK_auto_chk_result_mask                            (0x01000000)
#define SINE_AUTO_CHK_half_sine_num_mask                              (0x00C00000)
#define SINE_AUTO_CHK_amplitude_low_threshold_mask                    (0x00300000)
#define SINE_AUTO_CHK_zc_sample_cnt_threshold_mask                    (0x0003F000)
#define SINE_AUTO_CHK_zc_sample_cnt_golden_mask                       (0x00000FFF)
#define SINE_AUTO_CHK_sine_auto_chk_en(data)                          (0x80000000&((data)<<31))
#define SINE_AUTO_CHK_sine_channel_select(data)                       (0x70000000&((data)<<28))
#define SINE_AUTO_CHK_auto_chk_result(data)                           (0x01000000&((data)<<24))
#define SINE_AUTO_CHK_half_sine_num(data)                             (0x00C00000&((data)<<22))
#define SINE_AUTO_CHK_amplitude_low_threshold(data)                   (0x00300000&((data)<<20))
#define SINE_AUTO_CHK_zc_sample_cnt_threshold(data)                   (0x0003F000&((data)<<12))
#define SINE_AUTO_CHK_zc_sample_cnt_golden(data)                      (0x00000FFF&(data))
#define SINE_AUTO_CHK_get_sine_auto_chk_en(data)                      ((0x80000000&(data))>>31)
#define SINE_AUTO_CHK_get_sine_channel_select(data)                   ((0x70000000&(data))>>28)
#define SINE_AUTO_CHK_get_auto_chk_result(data)                       ((0x01000000&(data))>>24)
#define SINE_AUTO_CHK_get_half_sine_num(data)                         ((0x00C00000&(data))>>22)
#define SINE_AUTO_CHK_get_amplitude_low_threshold(data)               ((0x00300000&(data))>>20)
#define SINE_AUTO_CHK_get_zc_sample_cnt_threshold(data)               ((0x0003F000&(data))>>12)
#define SINE_AUTO_CHK_get_zc_sample_cnt_golden(data)                  (0x00000FFF&(data))


#define SINE_WAVE_VALUE                                               0x18006868
#define SINE_WAVE_VALUE_reg_addr                                      "0xb8006868"
#define SINE_WAVE_VALUE_reg                                           0xb8006868
#define SINE_WAVE_VALUE_inst_addr                                     "0x021A"
#define SINE_WAVE_VALUE_inst                                          0x021A
#define SINE_WAVE_VALUE_sine_amplitude_shift                          (12)
#define SINE_WAVE_VALUE_zc_sample_cnt_shift                           (0)
#define SINE_WAVE_VALUE_sine_amplitude_mask                           (0x000FF000)
#define SINE_WAVE_VALUE_zc_sample_cnt_mask                            (0x00000FFF)
#define SINE_WAVE_VALUE_sine_amplitude(data)                          (0x000FF000&((data)<<12))
#define SINE_WAVE_VALUE_zc_sample_cnt(data)                           (0x00000FFF&(data))
#define SINE_WAVE_VALUE_get_sine_amplitude(data)                      ((0x000FF000&(data))>>12)
#define SINE_WAVE_VALUE_get_zc_sample_cnt(data)                       (0x00000FFF&(data))


#define PATTERN_GEN_DUMMY                                             0x1800686c
#define PATTERN_GEN_DUMMY_reg_addr                                    "0xb800686c"
#define PATTERN_GEN_DUMMY_reg                                         0xb800686c
#define PATTERN_GEN_DUMMY_inst_addr                                   "0x021B"
#define PATTERN_GEN_DUMMY_inst                                        0x021B
#define PATTERN_GEN_DUMMY_dummy1800686c_31_0_shift                    (0)
#define PATTERN_GEN_DUMMY_dummy1800686c_31_0_mask                     (0xFFFFFFFF)
#define PATTERN_GEN_DUMMY_dummy1800686c_31_0(data)                    (0xFFFFFFFF&(data))
#define PATTERN_GEN_DUMMY_get_dummy1800686c_31_0(data)                (0xFFFFFFFF&(data))


#define RBUS_ACK_CTRL                                                 0x18006890
#define RBUS_ACK_CTRL_reg_addr                                        "0xb8006890"
#define RBUS_ACK_CTRL_reg                                             0xb8006890
#define RBUS_ACK_CTRL_inst_addr                                       "0x0224"
#define RBUS_ACK_CTRL_inst                                            0x0224
#define RBUS_ACK_CTRL_dummy18006890_3_1_shift                         (1)
#define RBUS_ACK_CTRL_to_ack_en_shift                                 (0)
#define RBUS_ACK_CTRL_dummy18006890_3_1_mask                          (0x0000000E)
#define RBUS_ACK_CTRL_to_ack_en_mask                                  (0x00000001)
#define RBUS_ACK_CTRL_dummy18006890_3_1(data)                         (0x0000000E&((data)<<1))
#define RBUS_ACK_CTRL_to_ack_en(data)                                 (0x00000001&(data))
#define RBUS_ACK_CTRL_get_dummy18006890_3_1(data)                     ((0x0000000E&(data))>>1)
#define RBUS_ACK_CTRL_get_to_ack_en(data)                             (0x00000001&(data))


#define ACK_FAIL_INFO                                                 0x18006894
#define ACK_FAIL_INFO_reg_addr                                        "0xb8006894"
#define ACK_FAIL_INFO_reg                                             0xb8006894
#define ACK_FAIL_INFO_inst_addr                                       "0x0225"
#define ACK_FAIL_INFO_inst                                            0x0225
#define ACK_FAIL_INFO_ack_fail_rw_shift                               (12)
#define ACK_FAIL_INFO_ack_fail_addr_shift                             (0)
#define ACK_FAIL_INFO_ack_fail_rw_mask                                (0x00001000)
#define ACK_FAIL_INFO_ack_fail_addr_mask                              (0x00000FFF)
#define ACK_FAIL_INFO_ack_fail_rw(data)                               (0x00001000&((data)<<12))
#define ACK_FAIL_INFO_ack_fail_addr(data)                             (0x00000FFF&(data))
#define ACK_FAIL_INFO_get_ack_fail_rw(data)                           ((0x00001000&(data))>>12)
#define ACK_FAIL_INFO_get_ack_fail_addr(data)                         (0x00000FFF&(data))


#define ADDA_LOOPBACK                                                 0x18006900
#define ADDA_LOOPBACK_reg_addr                                        "0xb8006900"
#define ADDA_LOOPBACK_reg                                             0xb8006900
#define ADDA_LOOPBACK_inst_addr                                       "0x0240"
#define ADDA_LOOPBACK_inst                                            0x0240
#define ADDA_LOOPBACK_dac_afifo_enable_shift                          (31)
#define ADDA_LOOPBACK_dac2_afifo_enable_shift                         (30)
#define ADDA_LOOPBACK_dac_afifo_full_shift                            (27)
#define ADDA_LOOPBACK_dac2_afifo_full_shift                           (26)
#define ADDA_LOOPBACK_dac_afifo_empty_shift                           (25)
#define ADDA_LOOPBACK_dac2_afifo_empty_shift                          (24)
#define ADDA_LOOPBACK_dac_afifo_in_drop_sel_shift                     (22)
#define ADDA_LOOPBACK_dac2_afifo_in_drop_sel_shift                    (20)
#define ADDA_LOOPBACK_sel_adda_lp_shift                               (3)
#define ADDA_LOOPBACK_sel_adc_2ch_lp_source_shift                     (2)
#define ADDA_LOOPBACK_sel_1ch_2ch_shift                               (1)
#define ADDA_LOOPBACK_sel_daad_lp_shift                               (0)
#define ADDA_LOOPBACK_dac_afifo_enable_mask                           (0x80000000)
#define ADDA_LOOPBACK_dac2_afifo_enable_mask                          (0x40000000)
#define ADDA_LOOPBACK_dac_afifo_full_mask                             (0x08000000)
#define ADDA_LOOPBACK_dac2_afifo_full_mask                            (0x04000000)
#define ADDA_LOOPBACK_dac_afifo_empty_mask                            (0x02000000)
#define ADDA_LOOPBACK_dac2_afifo_empty_mask                           (0x01000000)
#define ADDA_LOOPBACK_dac_afifo_in_drop_sel_mask                      (0x00C00000)
#define ADDA_LOOPBACK_dac2_afifo_in_drop_sel_mask                     (0x00300000)
#define ADDA_LOOPBACK_sel_adda_lp_mask                                (0x00000008)
#define ADDA_LOOPBACK_sel_adc_2ch_lp_source_mask                      (0x00000004)
#define ADDA_LOOPBACK_sel_1ch_2ch_mask                                (0x00000002)
#define ADDA_LOOPBACK_sel_daad_lp_mask                                (0x00000001)
#define ADDA_LOOPBACK_dac_afifo_enable(data)                          (0x80000000&((data)<<31))
#define ADDA_LOOPBACK_dac2_afifo_enable(data)                         (0x40000000&((data)<<30))
#define ADDA_LOOPBACK_dac_afifo_full(data)                            (0x08000000&((data)<<27))
#define ADDA_LOOPBACK_dac2_afifo_full(data)                           (0x04000000&((data)<<26))
#define ADDA_LOOPBACK_dac_afifo_empty(data)                           (0x02000000&((data)<<25))
#define ADDA_LOOPBACK_dac2_afifo_empty(data)                          (0x01000000&((data)<<24))
#define ADDA_LOOPBACK_dac_afifo_in_drop_sel(data)                     (0x00C00000&((data)<<22))
#define ADDA_LOOPBACK_dac2_afifo_in_drop_sel(data)                    (0x00300000&((data)<<20))
#define ADDA_LOOPBACK_sel_adda_lp(data)                               (0x00000008&((data)<<3))
#define ADDA_LOOPBACK_sel_adc_2ch_lp_source(data)                     (0x00000004&((data)<<2))
#define ADDA_LOOPBACK_sel_1ch_2ch(data)                               (0x00000002&((data)<<1))
#define ADDA_LOOPBACK_sel_daad_lp(data)                               (0x00000001&(data))
#define ADDA_LOOPBACK_get_dac_afifo_enable(data)                      ((0x80000000&(data))>>31)
#define ADDA_LOOPBACK_get_dac2_afifo_enable(data)                     ((0x40000000&(data))>>30)
#define ADDA_LOOPBACK_get_dac_afifo_full(data)                        ((0x08000000&(data))>>27)
#define ADDA_LOOPBACK_get_dac2_afifo_full(data)                       ((0x04000000&(data))>>26)
#define ADDA_LOOPBACK_get_dac_afifo_empty(data)                       ((0x02000000&(data))>>25)
#define ADDA_LOOPBACK_get_dac2_afifo_empty(data)                      ((0x01000000&(data))>>24)
#define ADDA_LOOPBACK_get_dac_afifo_in_drop_sel(data)                 ((0x00C00000&(data))>>22)
#define ADDA_LOOPBACK_get_dac2_afifo_in_drop_sel(data)                ((0x00300000&(data))>>20)
#define ADDA_LOOPBACK_get_sel_adda_lp(data)                           ((0x00000008&(data))>>3)
#define ADDA_LOOPBACK_get_sel_adc_2ch_lp_source(data)                 ((0x00000004&(data))>>2)
#define ADDA_LOOPBACK_get_sel_1ch_2ch(data)                           ((0x00000002&(data))>>1)
#define ADDA_LOOPBACK_get_sel_daad_lp(data)                           (0x00000001&(data))


#define ANALOG_IN_OUT_SEL                                             0x18006904
#define ANALOG_IN_OUT_SEL_reg_addr                                    "0xb8006904"
#define ANALOG_IN_OUT_SEL_reg                                         0xb8006904
#define ANALOG_IN_OUT_SEL_inst_addr                                   "0x0241"
#define ANALOG_IN_OUT_SEL_inst                                        0x0241
#define ANALOG_IN_OUT_SEL_reg_bb_en_io_in_shift                       (23)
#define ANALOG_IN_OUT_SEL_reg_bb_sw_in_shift                          (22)
#define ANALOG_IN_OUT_SEL_reg_bb_ain_df2se_shift                      (19)
#define ANALOG_IN_OUT_SEL_reg_bb_aio1_io_shift                        (18)
#define ANALOG_IN_OUT_SEL_reg_bb_aio2_io_shift                        (17)
#define ANALOG_IN_OUT_SEL_reg_bb_aio1_mux3_shift                      (14)
#define ANALOG_IN_OUT_SEL_reg_bb_aio1_mux2_shift                      (13)
#define ANALOG_IN_OUT_SEL_reg_bb_aio1_mux1_shift                      (12)
#define ANALOG_IN_OUT_SEL_reg_bb_aio2_mux3_shift                      (10)
#define ANALOG_IN_OUT_SEL_reg_bb_aio2_mux2_shift                      (9)
#define ANALOG_IN_OUT_SEL_reg_bb_aio2_mux1_shift                      (8)
#define ANALOG_IN_OUT_SEL_reg_bb_aout_copy_shift                      (6)
#define ANALOG_IN_OUT_SEL_reg_bb_dachp_copy_shift                     (4)
#define ANALOG_IN_OUT_SEL_reg_bb_aio1_copy_shift                      (2)
#define ANALOG_IN_OUT_SEL_reg_bb_aio2_copy_shift                      (0)
#define ANALOG_IN_OUT_SEL_reg_bb_en_io_in_mask                        (0x00800000)
#define ANALOG_IN_OUT_SEL_reg_bb_sw_in_mask                           (0x00400000)
#define ANALOG_IN_OUT_SEL_reg_bb_ain_df2se_mask                       (0x00080000)
#define ANALOG_IN_OUT_SEL_reg_bb_aio1_io_mask                         (0x00040000)
#define ANALOG_IN_OUT_SEL_reg_bb_aio2_io_mask                         (0x00020000)
#define ANALOG_IN_OUT_SEL_reg_bb_aio1_mux3_mask                       (0x00004000)
#define ANALOG_IN_OUT_SEL_reg_bb_aio1_mux2_mask                       (0x00002000)
#define ANALOG_IN_OUT_SEL_reg_bb_aio1_mux1_mask                       (0x00001000)
#define ANALOG_IN_OUT_SEL_reg_bb_aio2_mux3_mask                       (0x00000400)
#define ANALOG_IN_OUT_SEL_reg_bb_aio2_mux2_mask                       (0x00000200)
#define ANALOG_IN_OUT_SEL_reg_bb_aio2_mux1_mask                       (0x00000100)
#define ANALOG_IN_OUT_SEL_reg_bb_aout_copy_mask                       (0x000000C0)
#define ANALOG_IN_OUT_SEL_reg_bb_dachp_copy_mask                      (0x00000030)
#define ANALOG_IN_OUT_SEL_reg_bb_aio1_copy_mask                       (0x0000000C)
#define ANALOG_IN_OUT_SEL_reg_bb_aio2_copy_mask                       (0x00000003)
#define ANALOG_IN_OUT_SEL_reg_bb_en_io_in(data)                       (0x00800000&((data)<<23))
#define ANALOG_IN_OUT_SEL_reg_bb_sw_in(data)                          (0x00400000&((data)<<22))
#define ANALOG_IN_OUT_SEL_reg_bb_ain_df2se(data)                      (0x00080000&((data)<<19))
#define ANALOG_IN_OUT_SEL_reg_bb_aio1_io(data)                        (0x00040000&((data)<<18))
#define ANALOG_IN_OUT_SEL_reg_bb_aio2_io(data)                        (0x00020000&((data)<<17))
#define ANALOG_IN_OUT_SEL_reg_bb_aio1_mux3(data)                      (0x00004000&((data)<<14))
#define ANALOG_IN_OUT_SEL_reg_bb_aio1_mux2(data)                      (0x00002000&((data)<<13))
#define ANALOG_IN_OUT_SEL_reg_bb_aio1_mux1(data)                      (0x00001000&((data)<<12))
#define ANALOG_IN_OUT_SEL_reg_bb_aio2_mux3(data)                      (0x00000400&((data)<<10))
#define ANALOG_IN_OUT_SEL_reg_bb_aio2_mux2(data)                      (0x00000200&((data)<<9))
#define ANALOG_IN_OUT_SEL_reg_bb_aio2_mux1(data)                      (0x00000100&((data)<<8))
#define ANALOG_IN_OUT_SEL_reg_bb_aout_copy(data)                      (0x000000C0&((data)<<6))
#define ANALOG_IN_OUT_SEL_reg_bb_dachp_copy(data)                     (0x00000030&((data)<<4))
#define ANALOG_IN_OUT_SEL_reg_bb_aio1_copy(data)                      (0x0000000C&((data)<<2))
#define ANALOG_IN_OUT_SEL_reg_bb_aio2_copy(data)                      (0x00000003&(data))
#define ANALOG_IN_OUT_SEL_get_reg_bb_en_io_in(data)                   ((0x00800000&(data))>>23)
#define ANALOG_IN_OUT_SEL_get_reg_bb_sw_in(data)                      ((0x00400000&(data))>>22)
#define ANALOG_IN_OUT_SEL_get_reg_bb_ain_df2se(data)                  ((0x00080000&(data))>>19)
#define ANALOG_IN_OUT_SEL_get_reg_bb_aio1_io(data)                    ((0x00040000&(data))>>18)
#define ANALOG_IN_OUT_SEL_get_reg_bb_aio2_io(data)                    ((0x00020000&(data))>>17)
#define ANALOG_IN_OUT_SEL_get_reg_bb_aio1_mux3(data)                  ((0x00004000&(data))>>14)
#define ANALOG_IN_OUT_SEL_get_reg_bb_aio1_mux2(data)                  ((0x00002000&(data))>>13)
#define ANALOG_IN_OUT_SEL_get_reg_bb_aio1_mux1(data)                  ((0x00001000&(data))>>12)
#define ANALOG_IN_OUT_SEL_get_reg_bb_aio2_mux3(data)                  ((0x00000400&(data))>>10)
#define ANALOG_IN_OUT_SEL_get_reg_bb_aio2_mux2(data)                  ((0x00000200&(data))>>9)
#define ANALOG_IN_OUT_SEL_get_reg_bb_aio2_mux1(data)                  ((0x00000100&(data))>>8)
#define ANALOG_IN_OUT_SEL_get_reg_bb_aout_copy(data)                  ((0x000000C0&(data))>>6)
#define ANALOG_IN_OUT_SEL_get_reg_bb_dachp_copy(data)                 ((0x00000030&(data))>>4)
#define ANALOG_IN_OUT_SEL_get_reg_bb_aio1_copy(data)                  ((0x0000000C&(data))>>2)
#define ANALOG_IN_OUT_SEL_get_reg_bb_aio2_copy(data)                  (0x00000003&(data))


#define ANALOG_FRONTEND_MUTE                                          0x18006908
#define ANALOG_FRONTEND_MUTE_reg_addr                                 "0xb8006908"
#define ANALOG_FRONTEND_MUTE_reg                                      0xb8006908
#define ANALOG_FRONTEND_MUTE_inst_addr                                "0x0242"
#define ANALOG_FRONTEND_MUTE_inst                                     0x0242
#define ANALOG_FRONTEND_MUTE_reg_bb_m_adc_l_shift                     (17)
#define ANALOG_FRONTEND_MUTE_reg_bb_m_adc_r_shift                     (16)
#define ANALOG_FRONTEND_MUTE_reg_bb_m_afe_l_shift                     (8)
#define ANALOG_FRONTEND_MUTE_reg_bb_m_afe_r_shift                     (0)
#define ANALOG_FRONTEND_MUTE_reg_bb_m_adc_l_mask                      (0x00020000)
#define ANALOG_FRONTEND_MUTE_reg_bb_m_adc_r_mask                      (0x00010000)
#define ANALOG_FRONTEND_MUTE_reg_bb_m_afe_l_mask                      (0x00007F00)
#define ANALOG_FRONTEND_MUTE_reg_bb_m_afe_r_mask                      (0x0000007F)
#define ANALOG_FRONTEND_MUTE_reg_bb_m_adc_l(data)                     (0x00020000&((data)<<17))
#define ANALOG_FRONTEND_MUTE_reg_bb_m_adc_r(data)                     (0x00010000&((data)<<16))
#define ANALOG_FRONTEND_MUTE_reg_bb_m_afe_l(data)                     (0x00007F00&((data)<<8))
#define ANALOG_FRONTEND_MUTE_reg_bb_m_afe_r(data)                     (0x0000007F&(data))
#define ANALOG_FRONTEND_MUTE_get_reg_bb_m_adc_l(data)                 ((0x00020000&(data))>>17)
#define ANALOG_FRONTEND_MUTE_get_reg_bb_m_adc_r(data)                 ((0x00010000&(data))>>16)
#define ANALOG_FRONTEND_MUTE_get_reg_bb_m_afe_l(data)                 ((0x00007F00&(data))>>8)
#define ANALOG_FRONTEND_MUTE_get_reg_bb_m_afe_r(data)                 (0x0000007F&(data))


#define ANALOG_MIXER_MUTE                                             0x1800690c
#define ANALOG_MIXER_MUTE_reg_addr                                    "0xb800690c"
#define ANALOG_MIXER_MUTE_reg                                         0xb800690c
#define ANALOG_MIXER_MUTE_inst_addr                                   "0x0243"
#define ANALOG_MIXER_MUTE_inst                                        0x0243
#define ANALOG_MIXER_MUTE_reg_bb_m_mixer1_l_shift                     (13)
#define ANALOG_MIXER_MUTE_reg_bb_m_mixer1_r_shift                     (9)
#define ANALOG_MIXER_MUTE_reg_bb_m_mixer2_l_shift                     (5)
#define ANALOG_MIXER_MUTE_reg_bb_m_mixer2_r_shift                     (1)
#define ANALOG_MIXER_MUTE_reg_bb_m_mixer1_l_mask                      (0x0000E000)
#define ANALOG_MIXER_MUTE_reg_bb_m_mixer1_r_mask                      (0x00000E00)
#define ANALOG_MIXER_MUTE_reg_bb_m_mixer2_l_mask                      (0x000000E0)
#define ANALOG_MIXER_MUTE_reg_bb_m_mixer2_r_mask                      (0x0000000E)
#define ANALOG_MIXER_MUTE_reg_bb_m_mixer1_l(data)                     (0x0000E000&((data)<<13))
#define ANALOG_MIXER_MUTE_reg_bb_m_mixer1_r(data)                     (0x00000E00&((data)<<9))
#define ANALOG_MIXER_MUTE_reg_bb_m_mixer2_l(data)                     (0x000000E0&((data)<<5))
#define ANALOG_MIXER_MUTE_reg_bb_m_mixer2_r(data)                     (0x0000000E&((data)<<1))
#define ANALOG_MIXER_MUTE_get_reg_bb_m_mixer1_l(data)                 ((0x0000E000&(data))>>13)
#define ANALOG_MIXER_MUTE_get_reg_bb_m_mixer1_r(data)                 ((0x00000E00&(data))>>9)
#define ANALOG_MIXER_MUTE_get_reg_bb_m_mixer2_l(data)                 ((0x000000E0&(data))>>5)
#define ANALOG_MIXER_MUTE_get_reg_bb_m_mixer2_r(data)                 ((0x0000000E&(data))>>1)


#define ANALOG_AIO_MASTER_HPOUT_LINEOUT                               0x18006910
#define ANALOG_AIO_MASTER_HPOUT_LINEOUT_reg_addr                      "0xb8006910"
#define ANALOG_AIO_MASTER_HPOUT_LINEOUT_reg                           0xb8006910
#define ANALOG_AIO_MASTER_HPOUT_LINEOUT_inst_addr                     "0x0244"
#define ANALOG_AIO_MASTER_HPOUT_LINEOUT_inst                          0x0244
#define ANALOG_AIO_MASTER_HPOUT_LINEOUT_reg_bb_en_amp_shift           (20)
#define ANALOG_AIO_MASTER_HPOUT_LINEOUT_reg_bb_m_aio1_l_shift         (19)
#define ANALOG_AIO_MASTER_HPOUT_LINEOUT_reg_bb_m_aio1_r_shift         (18)
#define ANALOG_AIO_MASTER_HPOUT_LINEOUT_reg_bb_m_aio2_l_shift         (17)
#define ANALOG_AIO_MASTER_HPOUT_LINEOUT_reg_bb_m_aio2_r_shift         (16)
#define ANALOG_AIO_MASTER_HPOUT_LINEOUT_reg_bb_m_aout_l_shift         (15)
#define ANALOG_AIO_MASTER_HPOUT_LINEOUT_reg_bb_m_aout_r_shift         (14)
#define ANALOG_AIO_MASTER_HPOUT_LINEOUT_reg_bb_m_dachp_l_shift        (13)
#define ANALOG_AIO_MASTER_HPOUT_LINEOUT_reg_bb_m_dachp_r_shift        (12)
#define ANALOG_AIO_MASTER_HPOUT_LINEOUT_reg_bb_m_master_l_shift       (6)
#define ANALOG_AIO_MASTER_HPOUT_LINEOUT_reg_bb_m_master_r_shift       (0)
#define ANALOG_AIO_MASTER_HPOUT_LINEOUT_reg_bb_en_amp_mask            (0x00100000)
#define ANALOG_AIO_MASTER_HPOUT_LINEOUT_reg_bb_m_aio1_l_mask          (0x00080000)
#define ANALOG_AIO_MASTER_HPOUT_LINEOUT_reg_bb_m_aio1_r_mask          (0x00040000)
#define ANALOG_AIO_MASTER_HPOUT_LINEOUT_reg_bb_m_aio2_l_mask          (0x00020000)
#define ANALOG_AIO_MASTER_HPOUT_LINEOUT_reg_bb_m_aio2_r_mask          (0x00010000)
#define ANALOG_AIO_MASTER_HPOUT_LINEOUT_reg_bb_m_aout_l_mask          (0x00008000)
#define ANALOG_AIO_MASTER_HPOUT_LINEOUT_reg_bb_m_aout_r_mask          (0x00004000)
#define ANALOG_AIO_MASTER_HPOUT_LINEOUT_reg_bb_m_dachp_l_mask         (0x00002000)
#define ANALOG_AIO_MASTER_HPOUT_LINEOUT_reg_bb_m_dachp_r_mask         (0x00001000)
#define ANALOG_AIO_MASTER_HPOUT_LINEOUT_reg_bb_m_master_l_mask        (0x00000FC0)
#define ANALOG_AIO_MASTER_HPOUT_LINEOUT_reg_bb_m_master_r_mask        (0x0000003F)
#define ANALOG_AIO_MASTER_HPOUT_LINEOUT_reg_bb_en_amp(data)           (0x00100000&((data)<<20))
#define ANALOG_AIO_MASTER_HPOUT_LINEOUT_reg_bb_m_aio1_l(data)         (0x00080000&((data)<<19))
#define ANALOG_AIO_MASTER_HPOUT_LINEOUT_reg_bb_m_aio1_r(data)         (0x00040000&((data)<<18))
#define ANALOG_AIO_MASTER_HPOUT_LINEOUT_reg_bb_m_aio2_l(data)         (0x00020000&((data)<<17))
#define ANALOG_AIO_MASTER_HPOUT_LINEOUT_reg_bb_m_aio2_r(data)         (0x00010000&((data)<<16))
#define ANALOG_AIO_MASTER_HPOUT_LINEOUT_reg_bb_m_aout_l(data)         (0x00008000&((data)<<15))
#define ANALOG_AIO_MASTER_HPOUT_LINEOUT_reg_bb_m_aout_r(data)         (0x00004000&((data)<<14))
#define ANALOG_AIO_MASTER_HPOUT_LINEOUT_reg_bb_m_dachp_l(data)        (0x00002000&((data)<<13))
#define ANALOG_AIO_MASTER_HPOUT_LINEOUT_reg_bb_m_dachp_r(data)        (0x00001000&((data)<<12))
#define ANALOG_AIO_MASTER_HPOUT_LINEOUT_reg_bb_m_master_l(data)       (0x00000FC0&((data)<<6))
#define ANALOG_AIO_MASTER_HPOUT_LINEOUT_reg_bb_m_master_r(data)       (0x0000003F&(data))
#define ANALOG_AIO_MASTER_HPOUT_LINEOUT_get_reg_bb_en_amp(data)       ((0x00100000&(data))>>20)
#define ANALOG_AIO_MASTER_HPOUT_LINEOUT_get_reg_bb_m_aio1_l(data)     ((0x00080000&(data))>>19)
#define ANALOG_AIO_MASTER_HPOUT_LINEOUT_get_reg_bb_m_aio1_r(data)     ((0x00040000&(data))>>18)
#define ANALOG_AIO_MASTER_HPOUT_LINEOUT_get_reg_bb_m_aio2_l(data)     ((0x00020000&(data))>>17)
#define ANALOG_AIO_MASTER_HPOUT_LINEOUT_get_reg_bb_m_aio2_r(data)     ((0x00010000&(data))>>16)
#define ANALOG_AIO_MASTER_HPOUT_LINEOUT_get_reg_bb_m_aout_l(data)     ((0x00008000&(data))>>15)
#define ANALOG_AIO_MASTER_HPOUT_LINEOUT_get_reg_bb_m_aout_r(data)     ((0x00004000&(data))>>14)
#define ANALOG_AIO_MASTER_HPOUT_LINEOUT_get_reg_bb_m_dachp_l(data)    ((0x00002000&(data))>>13)
#define ANALOG_AIO_MASTER_HPOUT_LINEOUT_get_reg_bb_m_dachp_r(data)    ((0x00001000&(data))>>12)
#define ANALOG_AIO_MASTER_HPOUT_LINEOUT_get_reg_bb_m_master_l(data)   ((0x00000FC0&(data))>>6)
#define ANALOG_AIO_MASTER_HPOUT_LINEOUT_get_reg_bb_m_master_r(data)   (0x0000003F&(data))


#define ADC_VOLUME_GAIN_CONTROL                                       0x18006914
#define ADC_VOLUME_GAIN_CONTROL_reg_addr                              "0xb8006914"
#define ADC_VOLUME_GAIN_CONTROL_reg                                   0xb8006914
#define ADC_VOLUME_GAIN_CONTROL_inst_addr                             "0x0245"
#define ADC_VOLUME_GAIN_CONTROL_inst                                  0x0245
#define ADC_VOLUME_GAIN_CONTROL_smute_left_avol_1_en_shift            (31)
#define ADC_VOLUME_GAIN_CONTROL_avol_1_in_left_gain_shift             (24)
#define ADC_VOLUME_GAIN_CONTROL_smute_right_avol_1_en_shift           (23)
#define ADC_VOLUME_GAIN_CONTROL_avol_1_in_right_gain_shift            (16)
#define ADC_VOLUME_GAIN_CONTROL_soft_volume_ctrl_avol_shift           (12)
#define ADC_VOLUME_GAIN_CONTROL_smute_left_avol_1_en_mask             (0x80000000)
#define ADC_VOLUME_GAIN_CONTROL_avol_1_in_left_gain_mask              (0x3F000000)
#define ADC_VOLUME_GAIN_CONTROL_smute_right_avol_1_en_mask            (0x00800000)
#define ADC_VOLUME_GAIN_CONTROL_avol_1_in_right_gain_mask             (0x003F0000)
#define ADC_VOLUME_GAIN_CONTROL_soft_volume_ctrl_avol_mask            (0x0000F000)
#define ADC_VOLUME_GAIN_CONTROL_smute_left_avol_1_en(data)            (0x80000000&((data)<<31))
#define ADC_VOLUME_GAIN_CONTROL_avol_1_in_left_gain(data)             (0x3F000000&((data)<<24))
#define ADC_VOLUME_GAIN_CONTROL_smute_right_avol_1_en(data)           (0x00800000&((data)<<23))
#define ADC_VOLUME_GAIN_CONTROL_avol_1_in_right_gain(data)            (0x003F0000&((data)<<16))
#define ADC_VOLUME_GAIN_CONTROL_soft_volume_ctrl_avol(data)           (0x0000F000&((data)<<12))
#define ADC_VOLUME_GAIN_CONTROL_get_smute_left_avol_1_en(data)        ((0x80000000&(data))>>31)
#define ADC_VOLUME_GAIN_CONTROL_get_avol_1_in_left_gain(data)         ((0x3F000000&(data))>>24)
#define ADC_VOLUME_GAIN_CONTROL_get_smute_right_avol_1_en(data)       ((0x00800000&(data))>>23)
#define ADC_VOLUME_GAIN_CONTROL_get_avol_1_in_right_gain(data)        ((0x003F0000&(data))>>16)
#define ADC_VOLUME_GAIN_CONTROL_get_soft_volume_ctrl_avol(data)       ((0x0000F000&(data))>>12)


#define ANALOG_POWER                                                  0x18006918
#define ANALOG_POWER_reg_addr                                         "0xb8006918"
#define ANALOG_POWER_reg                                              0xb8006918
#define ANALOG_POWER_inst_addr                                        "0x0246"
#define ANALOG_POWER_inst                                             0x0246
#define ANALOG_POWER_reg_bb_dacvref_mode_shift                        (22)
#define ANALOG_POWER_reg_bb_pow_afe_shift                             (21)
#define ANALOG_POWER_reg_bb_pow_mixer_shift                           (20)
#define ANALOG_POWER_reg_bb_pow_master_shift                          (19)
#define ANALOG_POWER_reg_bb_pow_adc1_shift                            (18)
#define ANALOG_POWER_reg_bb_pow_dac0_shift                            (17)
#define ANALOG_POWER_reg_bb_pow_dac1_shift                            (16)
#define ANALOG_POWER_reg_bb_pow_mbias_shift                           (15)
#define ANALOG_POWER_reg_bb_pow_vref_shift                            (14)
#define ANALOG_POWER_reg_bb_pow_dacvref_shift                         (13)
#define ANALOG_POWER_reg_bb_pow_aio1_shift                            (11)
#define ANALOG_POWER_reg_bb_pow_aio2_shift                            (10)
#define ANALOG_POWER_reg_bb_pow_aout_shift                            (9)
#define ANALOG_POWER_reg_bb_pow_dachp_shift                           (8)
#define ANALOG_POWER_reg_bb_pow_ain1_shift                            (5)
#define ANALOG_POWER_reg_bb_pow_ain2_shift                            (4)
#define ANALOG_POWER_reg_bb_pow_ain3_shift                            (3)
#define ANALOG_POWER_reg_bb_pow_ain4_shift                            (2)
#define ANALOG_POWER_reg_bb_pow_ain5_shift                            (1)
#define ANALOG_POWER_reg_bb_dacvref_mode_mask                         (0x00400000)
#define ANALOG_POWER_reg_bb_pow_afe_mask                              (0x00200000)
#define ANALOG_POWER_reg_bb_pow_mixer_mask                            (0x00100000)
#define ANALOG_POWER_reg_bb_pow_master_mask                           (0x00080000)
#define ANALOG_POWER_reg_bb_pow_adc1_mask                             (0x00040000)
#define ANALOG_POWER_reg_bb_pow_dac0_mask                             (0x00020000)
#define ANALOG_POWER_reg_bb_pow_dac1_mask                             (0x00010000)
#define ANALOG_POWER_reg_bb_pow_mbias_mask                            (0x00008000)
#define ANALOG_POWER_reg_bb_pow_vref_mask                             (0x00004000)
#define ANALOG_POWER_reg_bb_pow_dacvref_mask                          (0x00002000)
#define ANALOG_POWER_reg_bb_pow_aio1_mask                             (0x00000800)
#define ANALOG_POWER_reg_bb_pow_aio2_mask                             (0x00000400)
#define ANALOG_POWER_reg_bb_pow_aout_mask                             (0x00000200)
#define ANALOG_POWER_reg_bb_pow_dachp_mask                            (0x00000100)
#define ANALOG_POWER_reg_bb_pow_ain1_mask                             (0x00000020)
#define ANALOG_POWER_reg_bb_pow_ain2_mask                             (0x00000010)
#define ANALOG_POWER_reg_bb_pow_ain3_mask                             (0x00000008)
#define ANALOG_POWER_reg_bb_pow_ain4_mask                             (0x00000004)
#define ANALOG_POWER_reg_bb_pow_ain5_mask                             (0x00000002)
#define ANALOG_POWER_reg_bb_dacvref_mode(data)                        (0x00400000&((data)<<22))
#define ANALOG_POWER_reg_bb_pow_afe(data)                             (0x00200000&((data)<<21))
#define ANALOG_POWER_reg_bb_pow_mixer(data)                           (0x00100000&((data)<<20))
#define ANALOG_POWER_reg_bb_pow_master(data)                          (0x00080000&((data)<<19))
#define ANALOG_POWER_reg_bb_pow_adc1(data)                            (0x00040000&((data)<<18))
#define ANALOG_POWER_reg_bb_pow_dac0(data)                            (0x00020000&((data)<<17))
#define ANALOG_POWER_reg_bb_pow_dac1(data)                            (0x00010000&((data)<<16))
#define ANALOG_POWER_reg_bb_pow_mbias(data)                           (0x00008000&((data)<<15))
#define ANALOG_POWER_reg_bb_pow_vref(data)                            (0x00004000&((data)<<14))
#define ANALOG_POWER_reg_bb_pow_dacvref(data)                         (0x00002000&((data)<<13))
#define ANALOG_POWER_reg_bb_pow_aio1(data)                            (0x00000800&((data)<<11))
#define ANALOG_POWER_reg_bb_pow_aio2(data)                            (0x00000400&((data)<<10))
#define ANALOG_POWER_reg_bb_pow_aout(data)                            (0x00000200&((data)<<9))
#define ANALOG_POWER_reg_bb_pow_dachp(data)                           (0x00000100&((data)<<8))
#define ANALOG_POWER_reg_bb_pow_ain1(data)                            (0x00000020&((data)<<5))
#define ANALOG_POWER_reg_bb_pow_ain2(data)                            (0x00000010&((data)<<4))
#define ANALOG_POWER_reg_bb_pow_ain3(data)                            (0x00000008&((data)<<3))
#define ANALOG_POWER_reg_bb_pow_ain4(data)                            (0x00000004&((data)<<2))
#define ANALOG_POWER_reg_bb_pow_ain5(data)                            (0x00000002&((data)<<1))
#define ANALOG_POWER_get_reg_bb_dacvref_mode(data)                    ((0x00400000&(data))>>22)
#define ANALOG_POWER_get_reg_bb_pow_afe(data)                         ((0x00200000&(data))>>21)
#define ANALOG_POWER_get_reg_bb_pow_mixer(data)                       ((0x00100000&(data))>>20)
#define ANALOG_POWER_get_reg_bb_pow_master(data)                      ((0x00080000&(data))>>19)
#define ANALOG_POWER_get_reg_bb_pow_adc1(data)                        ((0x00040000&(data))>>18)
#define ANALOG_POWER_get_reg_bb_pow_dac0(data)                        ((0x00020000&(data))>>17)
#define ANALOG_POWER_get_reg_bb_pow_dac1(data)                        ((0x00010000&(data))>>16)
#define ANALOG_POWER_get_reg_bb_pow_mbias(data)                       ((0x00008000&(data))>>15)
#define ANALOG_POWER_get_reg_bb_pow_vref(data)                        ((0x00004000&(data))>>14)
#define ANALOG_POWER_get_reg_bb_pow_dacvref(data)                     ((0x00002000&(data))>>13)
#define ANALOG_POWER_get_reg_bb_pow_aio1(data)                        ((0x00000800&(data))>>11)
#define ANALOG_POWER_get_reg_bb_pow_aio2(data)                        ((0x00000400&(data))>>10)
#define ANALOG_POWER_get_reg_bb_pow_aout(data)                        ((0x00000200&(data))>>9)
#define ANALOG_POWER_get_reg_bb_pow_dachp(data)                       ((0x00000100&(data))>>8)
#define ANALOG_POWER_get_reg_bb_pow_ain1(data)                        ((0x00000020&(data))>>5)
#define ANALOG_POWER_get_reg_bb_pow_ain2(data)                        ((0x00000010&(data))>>4)
#define ANALOG_POWER_get_reg_bb_pow_ain3(data)                        ((0x00000008&(data))>>3)
#define ANALOG_POWER_get_reg_bb_pow_ain4(data)                        ((0x00000004&(data))>>2)
#define ANALOG_POWER_get_reg_bb_pow_ain5(data)                        ((0x00000002&(data))>>1)


#define ANALOG_PGA                                                    0x1800691c
#define ANALOG_PGA_reg_addr                                           "0xb800691c"
#define ANALOG_PGA_reg                                                0xb800691c
#define ANALOG_PGA_inst_addr                                          "0x0247"
#define ANALOG_PGA_inst                                               0x0247
#define ANALOG_PGA_reg_adc2x_sifpgapow_shift                          (12)
#define ANALOG_PGA_reg_adc2x_sibsifpga_shift                          (8)
#define ANALOG_PGA_afe_pga_vol_shift                                  (0)
#define ANALOG_PGA_reg_adc2x_sifpgapow_mask                           (0x00001000)
#define ANALOG_PGA_reg_adc2x_sibsifpga_mask                           (0x00000F00)
#define ANALOG_PGA_afe_pga_vol_mask                                   (0x0000003F)
#define ANALOG_PGA_reg_adc2x_sifpgapow(data)                          (0x00001000&((data)<<12))
#define ANALOG_PGA_reg_adc2x_sibsifpga(data)                          (0x00000F00&((data)<<8))
#define ANALOG_PGA_afe_pga_vol(data)                                  (0x0000003F&(data))
#define ANALOG_PGA_get_reg_adc2x_sifpgapow(data)                      ((0x00001000&(data))>>12)
#define ANALOG_PGA_get_reg_adc2x_sibsifpga(data)                      ((0x00000F00&(data))>>8)
#define ANALOG_PGA_get_afe_pga_vol(data)                              (0x0000003F&(data))


#define ANALOG_CI01                                                   0x18006920
#define ANALOG_CI01_reg_addr                                          "0xb8006920"
#define ANALOG_CI01_reg                                               0xb8006920
#define ANALOG_CI01_inst_addr                                         "0x0248"
#define ANALOG_CI01_inst                                              0x0248
#define ANALOG_CI01_reg_bb_adc_ckxen_shift                            (19)
#define ANALOG_CI01_reg_bb_adc_set_shift                              (18)
#define ANALOG_CI01_reg_bb_vref_shift                                 (16)
#define ANALOG_CI01_reg_bb_cio1_shift                                 (0)
#define ANALOG_CI01_reg_bb_adc_ckxen_mask                             (0x00080000)
#define ANALOG_CI01_reg_bb_adc_set_mask                               (0x00040000)
#define ANALOG_CI01_reg_bb_vref_mask                                  (0x00030000)
#define ANALOG_CI01_reg_bb_cio1_mask                                  (0x00003FFF)
#define ANALOG_CI01_reg_bb_adc_ckxen(data)                            (0x00080000&((data)<<19))
#define ANALOG_CI01_reg_bb_adc_set(data)                              (0x00040000&((data)<<18))
#define ANALOG_CI01_reg_bb_vref(data)                                 (0x00030000&((data)<<16))
#define ANALOG_CI01_reg_bb_cio1(data)                                 (0x00003FFF&(data))
#define ANALOG_CI01_get_reg_bb_adc_ckxen(data)                        ((0x00080000&(data))>>19)
#define ANALOG_CI01_get_reg_bb_adc_set(data)                          ((0x00040000&(data))>>18)
#define ANALOG_CI01_get_reg_bb_vref(data)                             ((0x00030000&(data))>>16)
#define ANALOG_CI01_get_reg_bb_cio1(data)                             (0x00003FFF&(data))


#define ANALOG_CI02                                                   0x18006924
#define ANALOG_CI02_reg_addr                                          "0xb8006924"
#define ANALOG_CI02_reg                                               0xb8006924
#define ANALOG_CI02_inst_addr                                         "0x0249"
#define ANALOG_CI02_inst                                              0x0249
#define ANALOG_CI02_reg_bb_cio2_shift                                 (0)
#define ANALOG_CI02_reg_bb_cio2_mask                                  (0x00003FFF)
#define ANALOG_CI02_reg_bb_cio2(data)                                 (0x00003FFF&(data))
#define ANALOG_CI02_get_reg_bb_cio2(data)                             (0x00003FFF&(data))


#define ANALOG_CI03                                                   0x18006928
#define ANALOG_CI03_reg_addr                                          "0xb8006928"
#define ANALOG_CI03_reg                                               0xb8006928
#define ANALOG_CI03_inst_addr                                         "0x024A"
#define ANALOG_CI03_inst                                              0x024A
#define ANALOG_CI03_reg_bb_cio3_shift                                 (0)
#define ANALOG_CI03_reg_bb_cio3_mask                                  (0x0000FFFF)
#define ANALOG_CI03_reg_bb_cio3(data)                                 (0x0000FFFF&(data))
#define ANALOG_CI03_get_reg_bb_cio3(data)                             (0x0000FFFF&(data))


#define ANALOG_HARD_MUTE                                              0x1800692c
#define ANALOG_HARD_MUTE_reg_addr                                     "0xb800692c"
#define ANALOG_HARD_MUTE_reg                                          0xb800692c
#define ANALOG_HARD_MUTE_inst_addr                                    "0x024B"
#define ANALOG_HARD_MUTE_inst                                         0x024B
#define ANALOG_HARD_MUTE_hard_mute_sel_shift                          (31)
#define ANALOG_HARD_MUTE_time_out_sel_shift                           (28)
#define ANALOG_HARD_MUTE_reg_bb_pow_zcd_shift                         (20)
#define ANALOG_HARD_MUTE_reg_bb_pow_zcdcomp_shift                     (12)
#define ANALOG_HARD_MUTE_reg_bb_zcd_curr_shift                        (8)
#define ANALOG_HARD_MUTE_zc_reg_bb_m_aio1_l_shift                     (7)
#define ANALOG_HARD_MUTE_zc_reg_bb_m_aio1_r_shift                     (6)
#define ANALOG_HARD_MUTE_zc_reg_bb_m_aio2_l_shift                     (5)
#define ANALOG_HARD_MUTE_zc_reg_bb_m_aio2_r_shift                     (4)
#define ANALOG_HARD_MUTE_zc_mute_left_lineout_shift                   (3)
#define ANALOG_HARD_MUTE_zc_mute_right_lineout_shift                  (2)
#define ANALOG_HARD_MUTE_zc_mute_left_amp_shift                       (1)
#define ANALOG_HARD_MUTE_zc_mute_right_amp_shift                      (0)
#define ANALOG_HARD_MUTE_hard_mute_sel_mask                           (0x80000000)
#define ANALOG_HARD_MUTE_time_out_sel_mask                            (0x30000000)
#define ANALOG_HARD_MUTE_reg_bb_pow_zcd_mask                          (0x00100000)
#define ANALOG_HARD_MUTE_reg_bb_pow_zcdcomp_mask                      (0x000FF000)
#define ANALOG_HARD_MUTE_reg_bb_zcd_curr_mask                         (0x00000300)
#define ANALOG_HARD_MUTE_zc_reg_bb_m_aio1_l_mask                      (0x00000080)
#define ANALOG_HARD_MUTE_zc_reg_bb_m_aio1_r_mask                      (0x00000040)
#define ANALOG_HARD_MUTE_zc_reg_bb_m_aio2_l_mask                      (0x00000020)
#define ANALOG_HARD_MUTE_zc_reg_bb_m_aio2_r_mask                      (0x00000010)
#define ANALOG_HARD_MUTE_zc_mute_left_lineout_mask                    (0x00000008)
#define ANALOG_HARD_MUTE_zc_mute_right_lineout_mask                   (0x00000004)
#define ANALOG_HARD_MUTE_zc_mute_left_amp_mask                        (0x00000002)
#define ANALOG_HARD_MUTE_zc_mute_right_amp_mask                       (0x00000001)
#define ANALOG_HARD_MUTE_hard_mute_sel(data)                          (0x80000000&((data)<<31))
#define ANALOG_HARD_MUTE_time_out_sel(data)                           (0x30000000&((data)<<28))
#define ANALOG_HARD_MUTE_reg_bb_pow_zcd(data)                         (0x00100000&((data)<<20))
#define ANALOG_HARD_MUTE_reg_bb_pow_zcdcomp(data)                     (0x000FF000&((data)<<12))
#define ANALOG_HARD_MUTE_reg_bb_zcd_curr(data)                        (0x00000300&((data)<<8))
#define ANALOG_HARD_MUTE_zc_reg_bb_m_aio1_l(data)                     (0x00000080&((data)<<7))
#define ANALOG_HARD_MUTE_zc_reg_bb_m_aio1_r(data)                     (0x00000040&((data)<<6))
#define ANALOG_HARD_MUTE_zc_reg_bb_m_aio2_l(data)                     (0x00000020&((data)<<5))
#define ANALOG_HARD_MUTE_zc_reg_bb_m_aio2_r(data)                     (0x00000010&((data)<<4))
#define ANALOG_HARD_MUTE_zc_mute_left_lineout(data)                   (0x00000008&((data)<<3))
#define ANALOG_HARD_MUTE_zc_mute_right_lineout(data)                  (0x00000004&((data)<<2))
#define ANALOG_HARD_MUTE_zc_mute_left_amp(data)                       (0x00000002&((data)<<1))
#define ANALOG_HARD_MUTE_zc_mute_right_amp(data)                      (0x00000001&(data))
#define ANALOG_HARD_MUTE_get_hard_mute_sel(data)                      ((0x80000000&(data))>>31)
#define ANALOG_HARD_MUTE_get_time_out_sel(data)                       ((0x30000000&(data))>>28)
#define ANALOG_HARD_MUTE_get_reg_bb_pow_zcd(data)                     ((0x00100000&(data))>>20)
#define ANALOG_HARD_MUTE_get_reg_bb_pow_zcdcomp(data)                 ((0x000FF000&(data))>>12)
#define ANALOG_HARD_MUTE_get_reg_bb_zcd_curr(data)                    ((0x00000300&(data))>>8)
#define ANALOG_HARD_MUTE_get_zc_reg_bb_m_aio1_l(data)                 ((0x00000080&(data))>>7)
#define ANALOG_HARD_MUTE_get_zc_reg_bb_m_aio1_r(data)                 ((0x00000040&(data))>>6)
#define ANALOG_HARD_MUTE_get_zc_reg_bb_m_aio2_l(data)                 ((0x00000020&(data))>>5)
#define ANALOG_HARD_MUTE_get_zc_reg_bb_m_aio2_r(data)                 ((0x00000010&(data))>>4)
#define ANALOG_HARD_MUTE_get_zc_mute_left_lineout(data)               ((0x00000008&(data))>>3)
#define ANALOG_HARD_MUTE_get_zc_mute_right_lineout(data)              ((0x00000004&(data))>>2)
#define ANALOG_HARD_MUTE_get_zc_mute_left_amp(data)                   ((0x00000002&(data))>>1)
#define ANALOG_HARD_MUTE_get_zc_mute_right_amp(data)                  (0x00000001&(data))


#define ANALOG_ZERO_CROSSING                                          0x18006930
#define ANALOG_ZERO_CROSSING_reg_addr                                 "0xb8006930"
#define ANALOG_ZERO_CROSSING_reg                                      0xb8006930
#define ANALOG_ZERO_CROSSING_inst_addr                                "0x024C"
#define ANALOG_ZERO_CROSSING_inst                                     0x024C
#define ANALOG_ZERO_CROSSING_dummy18006930_31_16_shift                (16)
#define ANALOG_ZERO_CROSSING_hp_zc_sel_shift                          (14)
#define ANALOG_ZERO_CROSSING_lineout_zc_sel_shift                     (12)
#define ANALOG_ZERO_CROSSING_aio1_zc_sel_shift                        (10)
#define ANALOG_ZERO_CROSSING_aio2_zc_sel_shift                        (8)
#define ANALOG_ZERO_CROSSING_dac_water_nomask_shift                   (0)
#define ANALOG_ZERO_CROSSING_dummy18006930_31_16_mask                 (0xFFFF0000)
#define ANALOG_ZERO_CROSSING_hp_zc_sel_mask                           (0x0000C000)
#define ANALOG_ZERO_CROSSING_lineout_zc_sel_mask                      (0x00003000)
#define ANALOG_ZERO_CROSSING_aio1_zc_sel_mask                         (0x00000C00)
#define ANALOG_ZERO_CROSSING_aio2_zc_sel_mask                         (0x00000300)
#define ANALOG_ZERO_CROSSING_dac_water_nomask_mask                    (0x00000001)
#define ANALOG_ZERO_CROSSING_dummy18006930_31_16(data)                (0xFFFF0000&((data)<<16))
#define ANALOG_ZERO_CROSSING_hp_zc_sel(data)                          (0x0000C000&((data)<<14))
#define ANALOG_ZERO_CROSSING_lineout_zc_sel(data)                     (0x00003000&((data)<<12))
#define ANALOG_ZERO_CROSSING_aio1_zc_sel(data)                        (0x00000C00&((data)<<10))
#define ANALOG_ZERO_CROSSING_aio2_zc_sel(data)                        (0x00000300&((data)<<8))
#define ANALOG_ZERO_CROSSING_dac_water_nomask(data)                   (0x00000001&(data))
#define ANALOG_ZERO_CROSSING_get_dummy18006930_31_16(data)            ((0xFFFF0000&(data))>>16)
#define ANALOG_ZERO_CROSSING_get_hp_zc_sel(data)                      ((0x0000C000&(data))>>14)
#define ANALOG_ZERO_CROSSING_get_lineout_zc_sel(data)                 ((0x00003000&(data))>>12)
#define ANALOG_ZERO_CROSSING_get_aio1_zc_sel(data)                    ((0x00000C00&(data))>>10)
#define ANALOG_ZERO_CROSSING_get_aio2_zc_sel(data)                    ((0x00000300&(data))>>8)
#define ANALOG_ZERO_CROSSING_get_dac_water_nomask(data)               (0x00000001&(data))


#define ANALOG_DEPOP1                                                 0x18006934
#define ANALOG_DEPOP1_reg_addr                                        "0xb8006934"
#define ANALOG_DEPOP1_reg                                             0xb8006934
#define ANALOG_DEPOP1_inst_addr                                       "0x024D"
#define ANALOG_DEPOP1_inst                                            0x024D
#define ANALOG_DEPOP1_bb_ck_depop_en_shift                            (3)
#define ANALOG_DEPOP1_sel_bb_ck_depop_shift                           (0)
#define ANALOG_DEPOP1_bb_ck_depop_en_mask                             (0x00000008)
#define ANALOG_DEPOP1_sel_bb_ck_depop_mask                            (0x00000007)
#define ANALOG_DEPOP1_bb_ck_depop_en(data)                            (0x00000008&((data)<<3))
#define ANALOG_DEPOP1_sel_bb_ck_depop(data)                           (0x00000007&(data))
#define ANALOG_DEPOP1_get_bb_ck_depop_en(data)                        ((0x00000008&(data))>>3)
#define ANALOG_DEPOP1_get_sel_bb_ck_depop(data)                       (0x00000007&(data))


#define ANALOG_DEPOP2                                                 0x18006938
#define ANALOG_DEPOP2_reg_addr                                        "0xb8006938"
#define ANALOG_DEPOP2_reg                                             0xb8006938
#define ANALOG_DEPOP2_inst_addr                                       "0x024E"
#define ANALOG_DEPOP2_inst                                            0x024E
#define ANALOG_DEPOP2_reg_bb_pow_depop_shift                          (31)
#define ANALOG_DEPOP2_reg_bb_pow_depop_core_shift                     (30)
#define ANALOG_DEPOP2_reg_bb_pow_depop_op_shift                       (29)
#define ANALOG_DEPOP2_reg_bb_cio4_shift                               (20)
#define ANALOG_DEPOP2_reg_bb_depop_cur_sel_shift                      (16)
#define ANALOG_DEPOP2_reg_bb_en_io_out_shift                          (14)
#define ANALOG_DEPOP2_reg_bb_depop_cap_sel_shift                      (12)
#define ANALOG_DEPOP2_reg_bb_aout_norm_shift                          (10)
#define ANALOG_DEPOP2_reg_bb_aio_norm_shift                           (9)
#define ANALOG_DEPOP2_reg_bb_depop_sc_sel_shift                       (8)
#define ANALOG_DEPOP2_reg_bb_en_depop_ckgen_shift                     (7)
#define ANALOG_DEPOP2_reg_bb_depop_sel_shift                          (5)
#define ANALOG_DEPOP2_reg_bb_en_depop_soft_ctrl_shift                 (4)
#define ANALOG_DEPOP2_reg_bb_vcm_ready_soft_shift                     (3)
#define ANALOG_DEPOP2_reg_bb_hpout_norm_shift                         (2)
#define ANALOG_DEPOP2_reg_bb_pow_depop_mask                           (0x80000000)
#define ANALOG_DEPOP2_reg_bb_pow_depop_core_mask                      (0x40000000)
#define ANALOG_DEPOP2_reg_bb_pow_depop_op_mask                        (0x20000000)
#define ANALOG_DEPOP2_reg_bb_cio4_mask                                (0x0FF00000)
#define ANALOG_DEPOP2_reg_bb_depop_cur_sel_mask                       (0x00070000)
#define ANALOG_DEPOP2_reg_bb_en_io_out_mask                           (0x00004000)
#define ANALOG_DEPOP2_reg_bb_depop_cap_sel_mask                       (0x00003000)
#define ANALOG_DEPOP2_reg_bb_aout_norm_mask                           (0x00000400)
#define ANALOG_DEPOP2_reg_bb_aio_norm_mask                            (0x00000200)
#define ANALOG_DEPOP2_reg_bb_depop_sc_sel_mask                        (0x00000100)
#define ANALOG_DEPOP2_reg_bb_en_depop_ckgen_mask                      (0x00000080)
#define ANALOG_DEPOP2_reg_bb_depop_sel_mask                           (0x00000060)
#define ANALOG_DEPOP2_reg_bb_en_depop_soft_ctrl_mask                  (0x00000010)
#define ANALOG_DEPOP2_reg_bb_vcm_ready_soft_mask                      (0x00000008)
#define ANALOG_DEPOP2_reg_bb_hpout_norm_mask                          (0x00000004)
#define ANALOG_DEPOP2_reg_bb_pow_depop(data)                          (0x80000000&((data)<<31))
#define ANALOG_DEPOP2_reg_bb_pow_depop_core(data)                     (0x40000000&((data)<<30))
#define ANALOG_DEPOP2_reg_bb_pow_depop_op(data)                       (0x20000000&((data)<<29))
#define ANALOG_DEPOP2_reg_bb_cio4(data)                               (0x0FF00000&((data)<<20))
#define ANALOG_DEPOP2_reg_bb_depop_cur_sel(data)                      (0x00070000&((data)<<16))
#define ANALOG_DEPOP2_reg_bb_en_io_out(data)                          (0x00004000&((data)<<14))
#define ANALOG_DEPOP2_reg_bb_depop_cap_sel(data)                      (0x00003000&((data)<<12))
#define ANALOG_DEPOP2_reg_bb_aout_norm(data)                          (0x00000400&((data)<<10))
#define ANALOG_DEPOP2_reg_bb_aio_norm(data)                           (0x00000200&((data)<<9))
#define ANALOG_DEPOP2_reg_bb_depop_sc_sel(data)                       (0x00000100&((data)<<8))
#define ANALOG_DEPOP2_reg_bb_en_depop_ckgen(data)                     (0x00000080&((data)<<7))
#define ANALOG_DEPOP2_reg_bb_depop_sel(data)                          (0x00000060&((data)<<5))
#define ANALOG_DEPOP2_reg_bb_en_depop_soft_ctrl(data)                 (0x00000010&((data)<<4))
#define ANALOG_DEPOP2_reg_bb_vcm_ready_soft(data)                     (0x00000008&((data)<<3))
#define ANALOG_DEPOP2_reg_bb_hpout_norm(data)                         (0x00000004&((data)<<2))
#define ANALOG_DEPOP2_get_reg_bb_pow_depop(data)                      ((0x80000000&(data))>>31)
#define ANALOG_DEPOP2_get_reg_bb_pow_depop_core(data)                 ((0x40000000&(data))>>30)
#define ANALOG_DEPOP2_get_reg_bb_pow_depop_op(data)                   ((0x20000000&(data))>>29)
#define ANALOG_DEPOP2_get_reg_bb_cio4(data)                           ((0x0FF00000&(data))>>20)
#define ANALOG_DEPOP2_get_reg_bb_depop_cur_sel(data)                  ((0x00070000&(data))>>16)
#define ANALOG_DEPOP2_get_reg_bb_en_io_out(data)                      ((0x00004000&(data))>>14)
#define ANALOG_DEPOP2_get_reg_bb_depop_cap_sel(data)                  ((0x00003000&(data))>>12)
#define ANALOG_DEPOP2_get_reg_bb_aout_norm(data)                      ((0x00000400&(data))>>10)
#define ANALOG_DEPOP2_get_reg_bb_aio_norm(data)                       ((0x00000200&(data))>>9)
#define ANALOG_DEPOP2_get_reg_bb_depop_sc_sel(data)                   ((0x00000100&(data))>>8)
#define ANALOG_DEPOP2_get_reg_bb_en_depop_ckgen(data)                 ((0x00000080&(data))>>7)
#define ANALOG_DEPOP2_get_reg_bb_depop_sel(data)                      ((0x00000060&(data))>>5)
#define ANALOG_DEPOP2_get_reg_bb_en_depop_soft_ctrl(data)             ((0x00000010&(data))>>4)
#define ANALOG_DEPOP2_get_reg_bb_vcm_ready_soft(data)                 ((0x00000008&(data))>>3)
#define ANALOG_DEPOP2_get_reg_bb_hpout_norm(data)                     ((0x00000004&(data))>>2)


#define ANALOG_DEPOP_DUMMY                                            0x1800693c
#define ANALOG_DEPOP_DUMMY_reg_addr                                   "0xb800693c"
#define ANALOG_DEPOP_DUMMY_reg                                        0xb800693c
#define ANALOG_DEPOP_DUMMY_inst_addr                                  "0x024F"
#define ANALOG_DEPOP_DUMMY_inst                                       0x024F
#define ANALOG_DEPOP_DUMMY_reg_bb_reserved_shift                      (0)
#define ANALOG_DEPOP_DUMMY_reg_bb_reserved_mask                       (0xFFFFFFFF)
#define ANALOG_DEPOP_DUMMY_reg_bb_reserved(data)                      (0xFFFFFFFF&(data))
#define ANALOG_DEPOP_DUMMY_get_reg_bb_reserved(data)                  (0xFFFFFFFF&(data))


#define ANALOG_DUMMY                                                  0x18006940
#define ANALOG_DUMMY_reg_addr                                         "0xb8006940"
#define ANALOG_DUMMY_reg                                              0xb8006940
#define ANALOG_DUMMY_inst_addr                                        "0x0250"
#define ANALOG_DUMMY_inst                                             0x0250
#define ANALOG_DUMMY_dummy_6940_shift                                 (0)
#define ANALOG_DUMMY_dummy_6940_mask                                  (0xFFFFFFFF)
#define ANALOG_DUMMY_dummy_6940(data)                                 (0xFFFFFFFF&(data))
#define ANALOG_DUMMY_get_dummy_6940(data)                             (0xFFFFFFFF&(data))


#define ANALOG_DUMMY2                                                 0x18006944
#define ANALOG_DUMMY2_reg_addr                                        "0xb8006944"
#define ANALOG_DUMMY2_reg                                             0xb8006944
#define ANALOG_DUMMY2_inst_addr                                       "0x0251"
#define ANALOG_DUMMY2_inst                                            0x0251
#define ANALOG_DUMMY2_dummy_6944_shift                                (0)
#define ANALOG_DUMMY2_dummy_6944_mask                                 (0xFFFFFFFF)
#define ANALOG_DUMMY2_dummy_6944(data)                                (0xFFFFFFFF&(data))
#define ANALOG_DUMMY2_get_dummy_6944(data)                            (0xFFFFFFFF&(data))


#define DRF_BIST                                                      0x18006948
#define DRF_BIST_reg_addr                                             "0xb8006948"
#define DRF_BIST_reg                                                  0xb8006948
#define DRF_BIST_inst_addr                                            "0x0252"
#define DRF_BIST_inst                                                 0x0252
#define DRF_BIST_bist_mode_adc_shift                                  (31)
#define DRF_BIST_bist_rstn_adc_shift                                  (30)
#define DRF_BIST_bist_done_adc_shift                                  (29)
#define DRF_BIST_bist_fail_adc_shift                                  (28)
#define DRF_BIST_bist_mode_dac1_shift                                 (27)
#define DRF_BIST_bist_rstn_dac1_shift                                 (26)
#define DRF_BIST_bist_done_dac1_shift                                 (25)
#define DRF_BIST_bist_fail_dac1_shift                                 (24)
#define DRF_BIST_bist_mode_dac0_shift                                 (23)
#define DRF_BIST_bist_rstn_dac0_shift                                 (22)
#define DRF_BIST_bist_done_dac0_shift                                 (21)
#define DRF_BIST_bist_fail_dac0_shift                                 (20)
#define DRF_BIST_dvse_0_adda_shift                                    (19)
#define DRF_BIST_dvs_0_adda_shift                                     (15)
#define DRF_BIST_drf_start_pause_adc_shift                            (14)
#define DRF_BIST_drf_test_resume_adc_shift                            (13)
#define DRF_BIST_drf_bist_mode_adc_shift                              (12)
#define DRF_BIST_drf_bist_done_adc_shift                              (11)
#define DRF_BIST_drf_bist_fail_adc_shift                              (10)
#define DRF_BIST_drf_start_pause_dac1_shift                           (9)
#define DRF_BIST_drf_test_resume_dac1_shift                           (8)
#define DRF_BIST_drf_bist_mode_dac1_shift                             (7)
#define DRF_BIST_drf_bist_done_dac1_shift                             (6)
#define DRF_BIST_drf_bist_fail_dac1_shift                             (5)
#define DRF_BIST_drf_start_pause_dac0_shift                           (4)
#define DRF_BIST_drf_test_resume_dac0_shift                           (3)
#define DRF_BIST_drf_bist_mode_dac0_shift                             (2)
#define DRF_BIST_drf_bist_done_dac0_shift                             (1)
#define DRF_BIST_drf_bist_fail_dac0_shift                             (0)
#define DRF_BIST_bist_mode_adc_mask                                   (0x80000000)
#define DRF_BIST_bist_rstn_adc_mask                                   (0x40000000)
#define DRF_BIST_bist_done_adc_mask                                   (0x20000000)
#define DRF_BIST_bist_fail_adc_mask                                   (0x10000000)
#define DRF_BIST_bist_mode_dac1_mask                                  (0x08000000)
#define DRF_BIST_bist_rstn_dac1_mask                                  (0x04000000)
#define DRF_BIST_bist_done_dac1_mask                                  (0x02000000)
#define DRF_BIST_bist_fail_dac1_mask                                  (0x01000000)
#define DRF_BIST_bist_mode_dac0_mask                                  (0x00800000)
#define DRF_BIST_bist_rstn_dac0_mask                                  (0x00400000)
#define DRF_BIST_bist_done_dac0_mask                                  (0x00200000)
#define DRF_BIST_bist_fail_dac0_mask                                  (0x00100000)
#define DRF_BIST_dvse_0_adda_mask                                     (0x00080000)
#define DRF_BIST_dvs_0_adda_mask                                      (0x00078000)
#define DRF_BIST_drf_start_pause_adc_mask                             (0x00004000)
#define DRF_BIST_drf_test_resume_adc_mask                             (0x00002000)
#define DRF_BIST_drf_bist_mode_adc_mask                               (0x00001000)
#define DRF_BIST_drf_bist_done_adc_mask                               (0x00000800)
#define DRF_BIST_drf_bist_fail_adc_mask                               (0x00000400)
#define DRF_BIST_drf_start_pause_dac1_mask                            (0x00000200)
#define DRF_BIST_drf_test_resume_dac1_mask                            (0x00000100)
#define DRF_BIST_drf_bist_mode_dac1_mask                              (0x00000080)
#define DRF_BIST_drf_bist_done_dac1_mask                              (0x00000040)
#define DRF_BIST_drf_bist_fail_dac1_mask                              (0x00000020)
#define DRF_BIST_drf_start_pause_dac0_mask                            (0x00000010)
#define DRF_BIST_drf_test_resume_dac0_mask                            (0x00000008)
#define DRF_BIST_drf_bist_mode_dac0_mask                              (0x00000004)
#define DRF_BIST_drf_bist_done_dac0_mask                              (0x00000002)
#define DRF_BIST_drf_bist_fail_dac0_mask                              (0x00000001)
#define DRF_BIST_bist_mode_adc(data)                                  (0x80000000&((data)<<31))
#define DRF_BIST_bist_rstn_adc(data)                                  (0x40000000&((data)<<30))
#define DRF_BIST_bist_done_adc(data)                                  (0x20000000&((data)<<29))
#define DRF_BIST_bist_fail_adc(data)                                  (0x10000000&((data)<<28))
#define DRF_BIST_bist_mode_dac1(data)                                 (0x08000000&((data)<<27))
#define DRF_BIST_bist_rstn_dac1(data)                                 (0x04000000&((data)<<26))
#define DRF_BIST_bist_done_dac1(data)                                 (0x02000000&((data)<<25))
#define DRF_BIST_bist_fail_dac1(data)                                 (0x01000000&((data)<<24))
#define DRF_BIST_bist_mode_dac0(data)                                 (0x00800000&((data)<<23))
#define DRF_BIST_bist_rstn_dac0(data)                                 (0x00400000&((data)<<22))
#define DRF_BIST_bist_done_dac0(data)                                 (0x00200000&((data)<<21))
#define DRF_BIST_bist_fail_dac0(data)                                 (0x00100000&((data)<<20))
#define DRF_BIST_dvse_0_adda(data)                                    (0x00080000&((data)<<19))
#define DRF_BIST_dvs_0_adda(data)                                     (0x00078000&((data)<<15))
#define DRF_BIST_drf_start_pause_adc(data)                            (0x00004000&((data)<<14))
#define DRF_BIST_drf_test_resume_adc(data)                            (0x00002000&((data)<<13))
#define DRF_BIST_drf_bist_mode_adc(data)                              (0x00001000&((data)<<12))
#define DRF_BIST_drf_bist_done_adc(data)                              (0x00000800&((data)<<11))
#define DRF_BIST_drf_bist_fail_adc(data)                              (0x00000400&((data)<<10))
#define DRF_BIST_drf_start_pause_dac1(data)                           (0x00000200&((data)<<9))
#define DRF_BIST_drf_test_resume_dac1(data)                           (0x00000100&((data)<<8))
#define DRF_BIST_drf_bist_mode_dac1(data)                             (0x00000080&((data)<<7))
#define DRF_BIST_drf_bist_done_dac1(data)                             (0x00000040&((data)<<6))
#define DRF_BIST_drf_bist_fail_dac1(data)                             (0x00000020&((data)<<5))
#define DRF_BIST_drf_start_pause_dac0(data)                           (0x00000010&((data)<<4))
#define DRF_BIST_drf_test_resume_dac0(data)                           (0x00000008&((data)<<3))
#define DRF_BIST_drf_bist_mode_dac0(data)                             (0x00000004&((data)<<2))
#define DRF_BIST_drf_bist_done_dac0(data)                             (0x00000002&((data)<<1))
#define DRF_BIST_drf_bist_fail_dac0(data)                             (0x00000001&(data))
#define DRF_BIST_get_bist_mode_adc(data)                              ((0x80000000&(data))>>31)
#define DRF_BIST_get_bist_rstn_adc(data)                              ((0x40000000&(data))>>30)
#define DRF_BIST_get_bist_done_adc(data)                              ((0x20000000&(data))>>29)
#define DRF_BIST_get_bist_fail_adc(data)                              ((0x10000000&(data))>>28)
#define DRF_BIST_get_bist_mode_dac1(data)                             ((0x08000000&(data))>>27)
#define DRF_BIST_get_bist_rstn_dac1(data)                             ((0x04000000&(data))>>26)
#define DRF_BIST_get_bist_done_dac1(data)                             ((0x02000000&(data))>>25)
#define DRF_BIST_get_bist_fail_dac1(data)                             ((0x01000000&(data))>>24)
#define DRF_BIST_get_bist_mode_dac0(data)                             ((0x00800000&(data))>>23)
#define DRF_BIST_get_bist_rstn_dac0(data)                             ((0x00400000&(data))>>22)
#define DRF_BIST_get_bist_done_dac0(data)                             ((0x00200000&(data))>>21)
#define DRF_BIST_get_bist_fail_dac0(data)                             ((0x00100000&(data))>>20)
#define DRF_BIST_get_dvse_0_adda(data)                                ((0x00080000&(data))>>19)
#define DRF_BIST_get_dvs_0_adda(data)                                 ((0x00078000&(data))>>15)
#define DRF_BIST_get_drf_start_pause_adc(data)                        ((0x00004000&(data))>>14)
#define DRF_BIST_get_drf_test_resume_adc(data)                        ((0x00002000&(data))>>13)
#define DRF_BIST_get_drf_bist_mode_adc(data)                          ((0x00001000&(data))>>12)
#define DRF_BIST_get_drf_bist_done_adc(data)                          ((0x00000800&(data))>>11)
#define DRF_BIST_get_drf_bist_fail_adc(data)                          ((0x00000400&(data))>>10)
#define DRF_BIST_get_drf_start_pause_dac1(data)                       ((0x00000200&(data))>>9)
#define DRF_BIST_get_drf_test_resume_dac1(data)                       ((0x00000100&(data))>>8)
#define DRF_BIST_get_drf_bist_mode_dac1(data)                         ((0x00000080&(data))>>7)
#define DRF_BIST_get_drf_bist_done_dac1(data)                         ((0x00000040&(data))>>6)
#define DRF_BIST_get_drf_bist_fail_dac1(data)                         ((0x00000020&(data))>>5)
#define DRF_BIST_get_drf_start_pause_dac0(data)                       ((0x00000010&(data))>>4)
#define DRF_BIST_get_drf_test_resume_dac0(data)                       ((0x00000008&(data))>>3)
#define DRF_BIST_get_drf_bist_mode_dac0(data)                         ((0x00000004&(data))>>2)
#define DRF_BIST_get_drf_bist_done_dac0(data)                         ((0x00000002&(data))>>1)
#define DRF_BIST_get_drf_bist_fail_dac0(data)                         (0x00000001&(data))
#endif
