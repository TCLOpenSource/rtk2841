// This file is generated using the spec version 1.39, firmware template version 1.39and SRIF Parser                                                                                source code SVN rev:798                    Version flow no.:1.1.55
#ifndef _VDTOP_REG_H_INCLUDED_
#define _VDTOP_REG_H_INCLUDED_

//#define  _VDTOP_USE_STRUCT
#ifdef _VDTOP_USE_STRUCT

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    hv_delay:1;
    unsigned int    hpixel:2;
    unsigned int    vline_625:1;
    unsigned int    colour_mode:3;
    unsigned int    reserved_1:1;
}REG18019000;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    cv_inv:1;
    unsigned int    cv_src:1;
    unsigned int    yc_src:1;
    unsigned int    reserved_1:4;
    unsigned int    ped:1;
}REG18019004;

typedef struct
{
    unsigned int    reserved_0:22;
    unsigned int    chromalock_acc:1;
    unsigned int    h_fine_lock:1;
    unsigned int    mv_colourstripes:3;
    unsigned int    mv_vbi_detected:1;
    unsigned int    chomalock:1;
    unsigned int    vlock:1;
    unsigned int    hlock:1;
    unsigned int    no_signal:1;
}REG18019008;

typedef struct
{
    unsigned int    reserved_0:23;
    unsigned int    v_detect_flag:1;
    unsigned int    detect358_flag:1;
    unsigned int    vlock_new:1;
    unsigned int    noisy_vbi:1;
    unsigned int    detect443_flag:1;
    unsigned int    burst_detect:1;
    unsigned int    palor_flag:1;
    unsigned int    palm_flag:1;
    unsigned int    proscan_detected:1;
}REG1801900C;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    vcr_rew:1;
    unsigned int    vcr_ff:1;
    unsigned int    vcr_trick:1;
    unsigned int    vcr:1;
    unsigned int    noisy:1;
    unsigned int    lines_625_detected:1;
    unsigned int    secam_detected:1;
    unsigned int    pal_detected:1;
}REG18019010;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    hdto_inc_status:30;
}REG18019014;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    cdto_inc_status:30;
}REG18019018;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    burst_magnitude:8;
}REG1801901C;

typedef struct
{
    unsigned int    reserved_0:20;
    unsigned int    agc_dgain:12;
}REG18019020;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    status_cmag:8;
}REG18019024;

typedef struct
{
    unsigned int    reserved_0:18;
    unsigned int    status_cgain:14;
}REG18019028;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    status_cordiq_freq:8;
}REG1801902C;

typedef struct
{
    unsigned int    reserved_0:22;
    unsigned int    v_1st_line:10;
}REG18019030;

typedef struct
{
    unsigned int    reserved_0:22;
    unsigned int    v_2nd_line:10;
}REG18019034;

typedef struct
{
    unsigned int    reserved_0:19;
    unsigned int    porch_h:13;
}REG18019038;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    status_noise:8;
}REG1801903C;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    noise_thresh:8;
}REG18019040;

typedef struct
{
    unsigned int    hdto_fixed:1;
    unsigned int    reserved_0:1;
    unsigned int    hdto_inc:30;
}REG18019050;

typedef struct
{
    unsigned int    cdto_fixed:1;
    unsigned int    reserved_0:1;
    unsigned int    cdto_inc:30;
}REG18019054;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    chip_ver:16;
}REG18019058;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    contrast:8;
}REG18019060;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    brightness:8;
}REG18019064;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    saturation:8;
}REG18019068;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    hue:8;
}REG1801906C;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    blue_screen_y:8;
}REG18019070;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    blue_screen_cb:8;
}REG18019074;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    blue_screen_cr:8;
}REG18019078;

typedef struct
{
    unsigned int    reserved_0:20;
    unsigned int    motion_delay:4;
    unsigned int    snow_freerun_en:1;
    unsigned int    cbcr_swap:1;
    unsigned int    blue_mode:2;
    unsigned int    yc_delay:4;
}REG1801907C;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    avout_hsync_start:10;
    unsigned int    reserved_1:2;
    unsigned int    avout_hsync_end:10;
    unsigned int    reserved_2:3;
    unsigned int    fe_bypass_sel:1;
    unsigned int    sw_tu_cvbs:1;
    unsigned int    reserved_3:1;
    unsigned int    clamp_if_up_en:1;
    unsigned int    clamp_if_dn_en:1;
}REG18019080;

typedef struct
{
    unsigned int    reserved_0:5;
    unsigned int    output_fifo_full:1;
    unsigned int    output_fifo_empty:1;
    unsigned int    output_delay_0_180_sw:1;
    unsigned int    avout_test_in:12;
    unsigned int    reserved_1:3;
    unsigned int    avout_mixer_sel:4;
    unsigned int    reserved_2:3;
    unsigned int    avout_fifo_status_full:1;
    unsigned int    avout_fifo_status_empty:1;
}REG18019084;

typedef struct
{
    unsigned int    peak_deb_en:1;
    unsigned int    reserved_0:1;
    unsigned int    peak_diff_sel:2;
    unsigned int    reserved_1:2;
    unsigned int    peak_data_sel:1;
    unsigned int    peak_deb_limit:9;
    unsigned int    peak_deb_thl:8;
    unsigned int    hagc_err_coring_en:1;
    unsigned int    agc_peak_nominal:7;
}REG18019090;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    ycsep_data_decrease_en:1;
    unsigned int    ycsep_data_decrease_ratio:3;
    unsigned int    agc_peak_nominal_ycsep:12;
    unsigned int    reserved_1:1;
    unsigned int    agc_gate_kill_mode_sel:2;
    unsigned int    agc_gate_kill_w_hlock:1;
    unsigned int    agc_gate_vsync_coarse:1;
    unsigned int    agc_gate_vsync_stip:1;
    unsigned int    agc_gate_kill_mode:2;
    unsigned int    agc_peak_en:1;
    unsigned int    agc_peak_cntl:3;
}REG18019094;

typedef struct
{
    unsigned int    peak_gain:12;
    unsigned int    diff_level:12;
    unsigned int    unlock_peakrst_en:1;
    unsigned int    hagc_err_coring_th:5;
    unsigned int    agc_peak_loop_gain:2;
}REG18019098;

typedef struct
{
    unsigned int    reserved_0:3;
    unsigned int    fix_dgain:1;
    unsigned int    reserved_1:6;
    unsigned int    dgain_state:2;
    unsigned int    under_gain:12;
    unsigned int    hagc_field_mode:1;
    unsigned int    mv_hagc_mode:1;
    unsigned int    dc_clamp_mode:2;
    unsigned int    reserved_2:1;
    unsigned int    bgate_raw_sel:1;
    unsigned int    cagc_en:1;
    unsigned int    hagc_en:1;
}REG1801909C;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    hagc:8;
}REG180190A0;

typedef struct
{
    unsigned int    reserved_0:21;
    unsigned int    agc_gate_start:11;
}REG180190A4;

typedef struct
{
    unsigned int    reserved_0:25;
    unsigned int    agc_gate_width:7;
}REG180190A8;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    agc_bp_delay:8;
}REG180190AC;

typedef struct
{
    unsigned int    reserved_0:26;
    unsigned int    clampagc_under_th2:6;
}REG180190B0;

typedef struct
{
    unsigned int    reserved_0:19;
    unsigned int    data_path_dgain_div2_en:1;
    unsigned int    reserved_1:1;
    unsigned int    agc_under_loop_gain:3;
    unsigned int    under_flag:1;
    unsigned int    reserved_2:3;
    unsigned int    clampagc_under_th1:4;
}REG180190B4;

typedef struct
{
    unsigned int    under_deb_en:1;
    unsigned int    under_gate_en:1;
    unsigned int    under_diff_sel:2;
    unsigned int    reserved_0:3;
    unsigned int    under_deb_limit:9;
    unsigned int    under_deb_thl:8;
    unsigned int    clampagc_under_cntl:6;
    unsigned int    clampagc_under_en:1;
    unsigned int    blank_vid_offset:1;
}REG180190B8;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    under_gate_end:10;
    unsigned int    reserved_1:2;
    unsigned int    under_gate_st:10;
    unsigned int    reserved_2:1;
    unsigned int    vsync_agc_min:7;
}REG180190BC;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    vsync_clamp_mode:2;
    unsigned int    vsync_agc_max:6;
}REG180190C0;

typedef struct
{
    unsigned int    reserved_0:13;
    unsigned int    auto_dc_restore_sel:3;
    unsigned int    reserved_1:1;
    unsigned int    auto_dc_restore_en2:1;
    unsigned int    auto_dc_restore_en1:1;
    unsigned int    auto_dc_restore_en0:1;
    unsigned int    auto_dc_restore_disable_ad4_updn:1;
    unsigned int    auto_dc_restore_disable_ad3_updn:1;
    unsigned int    auto_dc_restore_disable_ad2_updn:1;
    unsigned int    auto_dc_restore_disable_ad1_updn:1;
    unsigned int    cpump_adjust_delay:6;
    unsigned int    cpump_adjust_polarity:1;
    unsigned int    cpump_delay_en:1;
}REG180190C4;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    cpump_adjust:8;
}REG180190C8;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    cpump_delay:8;
}REG180190CC;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    adc_updn_swap:1;
    unsigned int    adc_input_swap:1;
    unsigned int    adc_cbcr_pump_swap:1;
    unsigned int    agc_gate_thresh:5;
}REG180190D0;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    measure_dc_128_64_sel:1;
    unsigned int    dgain_ignore_fine_lock:1;
    unsigned int    measure_dc_rough:1;
    unsigned int    new_clamp_rc_rate_en:1;
    unsigned int    clampagc_rc_rate_3_0:4;
}REG180190D4;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    measure_dc_rough_dn:8;
}REG180190D8;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    measure_dc_rough_up:8;
}REG180190DC;

typedef struct
{
    unsigned int    reserved_0:20;
    unsigned int    measure_dc_th_dn:12;
}REG180190E0;

typedef struct
{
    unsigned int    reserved_0:20;
    unsigned int    measure_dc_th_up:12;
}REG180190E4;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    vsag_rc_input:1;
    unsigned int    reserved_1:1;
    unsigned int    vsag_agc_peak_cntl:6;
}REG180190E8;

typedef struct
{
    unsigned int    reserved_0:19;
    unsigned int    peak_vsag:13;
}REG180190EC;

typedef struct
{
    unsigned int    reserved_0:25;
    unsigned int    new_total_under_en:1;
    unsigned int    new_under_gain_en:1;
    unsigned int    new_under_th2_en:1;
    unsigned int    reserved_1:1;
    unsigned int    lose_sgate_flag:1;
    unsigned int    lose_bgate_flag:1;
    unsigned int    field_kill_rst:1;
}REG180190F0;

typedef struct
{
    unsigned int    reserved_0:22;
    unsigned int    field_kill_num:10;
}REG180190F4;

typedef struct
{
    unsigned int    reserved_0:21;
    unsigned int    kill_gate_up:11;
}REG180190F8;

typedef struct
{
    unsigned int    reserved_0:21;
    unsigned int    kill_gate_dn:11;
}REG180190FC;

typedef struct
{
    unsigned int    reserved_0:26;
    unsigned int    syncmidpt_add_level_h:2;
    unsigned int    reserved_1:2;
    unsigned int    sync_midpt_lowest_en:1;
    unsigned int    reserved_2:1;
}REG18019100;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    syncmidpt_fix_add_value_h:8;
}REG18019104;

typedef struct
{
    unsigned int    reserved_0:22;
    unsigned int    lpfsync_plus_w_hlock:2;
    unsigned int    lpfsync_plus_rm:1;
    unsigned int    reserved_1:1;
    unsigned int    lpfsync_plus_diff:6;
}REG18019108;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    spike_min_thresh:8;
}REG1801910C;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    spike_max_thresh:8;
}REG18019110;

typedef struct
{
    unsigned int    reserved_0:21;
    unsigned int    spike_detected:1;
    unsigned int    spike_detected_up:10;
}REG18019114;

typedef struct
{
    unsigned int    reserved_0:22;
    unsigned int    spike_detected_dn:10;
}REG18019118;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    lpfsync_plus_dc:8;
}REG1801911C;

typedef struct
{
    unsigned int    reserved_0:22;
    unsigned int    hdetect_error_avg_interval:2;
    unsigned int    reserved_1:1;
    unsigned int    hdetect_error_avg_length:3;
    unsigned int    reserved_2:3;
    unsigned int    hdetect_error_avg_sel:1;
}REG18019128;

typedef struct
{
    unsigned int    hdetect_error_var:16;
    unsigned int    hdetect_error_mean:16;
}REG1801912C;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    locked_count_noisy_max:4;
    unsigned int    locked_count_clean_max:4;
}REG18019130;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    hlock_vsync_mode:2;
    unsigned int    hstate_fixed:1;
    unsigned int    disable_hfine:1;
    unsigned int    hstate_unlocked:1;
    unsigned int    hstate_max:3;
}REG18019134;

typedef struct
{
    unsigned int    reserved_0:6;
    unsigned int    fine_phase_error_thl_9_0:10;
    unsigned int    cpll_hpll_use_front_vactive:1;
    unsigned int    hstate_hlock_sel:1;
    unsigned int    hstate_ignore_err:1;
    unsigned int    auto_fine_phase_sel:1;
    unsigned int    fine_hstate_to_5:1;
    unsigned int    auto_fine_phase_sel_en:1;
    unsigned int    hpll_fine_lock_data_sel:1;
    unsigned int    coarse_phase_rising_en:1;
    unsigned int    fine_src_sel:1;
    unsigned int    coarse_src_sel:1;
    unsigned int    fine_gate_sel:1;
    unsigned int    gate_end_thresh:5;
}REG18019138;

typedef struct
{
    unsigned int    reserved_0:25;
    unsigned int    coarse_sync_start:7;
}REG1801913C;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    coarse_sync_end:8;
}REG18019140;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    agc_trailing_sel:1;
    unsigned int    coarse_backporch_start:7;
}REG18019144;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    coarse_backporch_end:8;
}REG18019148;

typedef struct
{
    unsigned int    reserved_0:26;
    unsigned int    lpfsync_force_blank_en:1;
    unsigned int    nosignal_hlock_check_en:1;
    unsigned int    agc_clamping_trailing_sel:1;
    unsigned int    killgate_sel:1;
    unsigned int    coarse_phase_sel:1;
    unsigned int    fine_phase_sel:1;
}REG1801914C;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    lsync_tip_start:8;
}REG18019150;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    lsync_tip_end:8;
}REG18019154;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    lporch_start:8;
}REG18019158;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    lporch_end:8;
}REG1801915C;

typedef struct
{
    unsigned int    reserved_0:30;
    unsigned int    hpll_integral_rst:1;
    unsigned int    hpll_integral_ext:1;
}REG18019160;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    impulsive_noise_disable_pll_en:1;
    unsigned int    cstate_impn_max:3;
    unsigned int    reserved_1:1;
    unsigned int    hstate_impn_max:3;
    unsigned int    reserved_2:1;
    unsigned int    hstate_vcr_max:3;
    unsigned int    hstate_loopfilter_sw:1;
    unsigned int    hstate_status:3;
}REG18019164;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    hdetect_loopfilter_dctrl1:4;
    unsigned int    hdetect_loopfilter_dctrl2:4;
}REG18019168;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    hsync_start:8;
}REG1801916C;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    hsync_width:8;
}REG18019170;

typedef struct
{
    unsigned int    reserved_0:29;
    unsigned int    hresampler_app_alpha_sel:1;
    unsigned int    hresampler_app_sel:1;
    unsigned int    hresampler_2up:1;
}REG18019174;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    hpll_manu_mode_en:1;
    unsigned int    reserved_1:1;
    unsigned int    hpll_kp_coef_0:6;
}REG18019178;

typedef struct
{
    unsigned int    reserved_0:26;
    unsigned int    hpll_kp_coef_1:6;
}REG1801917C;

typedef struct
{
    unsigned int    reserved_0:26;
    unsigned int    hpll_kp_coef_2:6;
}REG18019180;

typedef struct
{
    unsigned int    reserved_0:26;
    unsigned int    hpll_kp_coef_3:6;
}REG18019184;

typedef struct
{
    unsigned int    reserved_0:26;
    unsigned int    hpll_kp_coef_4:6;
}REG18019188;

typedef struct
{
    unsigned int    reserved_0:26;
    unsigned int    hpll_kp_coef_5:6;
}REG1801918C;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    hpll_ki_coef_0:8;
}REG18019190;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    hpll_ki_coef_1:8;
}REG18019194;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    hpll_ki_coef_2:8;
}REG18019198;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    hpll_ki_coef_3:8;
}REG1801919C;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    hpll_ki_coef_4:8;
}REG180191A0;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    hpll_ki_coef_5:8;
}REG180191A4;

typedef struct
{
    unsigned int    reserved_0:22;
    unsigned int    second_pll_level_sel:2;
    unsigned int    reserved_1:2;
    unsigned int    second_pll_gain_sel:2;
    unsigned int    second_pll_clampgate_sel:1;
    unsigned int    second_pll_phase_sel:1;
    unsigned int    second_pll_w_hlock:1;
    unsigned int    second_pll_en:1;
}REG180191A8;

typedef struct
{
    unsigned int    second_pll_sync_level:8;
    unsigned int    second_pll_dc_add:12;
    unsigned int    second_pll_dc_rm:12;
}REG180191AC;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    second_comp_blevel:12;
    unsigned int    second_comp_slevel:12;
}REG180191B0;

typedef struct
{
    unsigned int    reserved_0:12;
    unsigned int    second_trailing:8;
    unsigned int    second_dgain:12;
}REG180191B4;

typedef struct
{
    unsigned int    second_backporch_start:8;
    unsigned int    second_backporch_end:8;
    unsigned int    second_hsync_tip_start:8;
    unsigned int    second_hsync_tip_end:8;
}REG180191B8;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    headswitch_debounce_en:1;
    unsigned int    second_pll_kill_en:1;
    unsigned int    under_detected_flag:1;
    unsigned int    under_count_reset:1;
    unsigned int    reserved_1:2;
    unsigned int    under_line_err_thl:10;
    unsigned int    reserved_2:2;
    unsigned int    under_min_err_thl:10;
}REG180191BC;

typedef struct
{
    unsigned int    reserved_0:22;
    unsigned int    under_field_err_thl:10;
}REG180191C0;

typedef struct
{
    unsigned int    reserved_0:10;
    unsigned int    under_debounce_thl:10;
    unsigned int    reserved_1:2;
    unsigned int    under_debounce_max:10;
}REG180191C4;

typedef struct
{
    unsigned int    coch_detected_by_check_dc:1;
    unsigned int    reserved_0:7;
    unsigned int    coch_avg_line1_diff_thre_up:12;
    unsigned int    coch_avg_line1_diff_thre_lo:12;
}REG180191C8;

typedef struct
{
    unsigned int    coch_detect_lpf_reset:1;
    unsigned int    reserved_0:9;
    unsigned int    coch_detect_counter_up_thre:10;
    unsigned int    reserved_1:2;
    unsigned int    coch_detect_counter_lo_thre:10;
}REG180191CC;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    hsync_rising:8;
}REG180191D0;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    hsync_phase_offset:8;
}REG180191D4;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    hsync_gate_start:8;
}REG180191D8;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    hsync_gate_end:8;
}REG180191DC;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    hsync_tip_start:8;
}REG180191E0;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    hsync_tip_end:8;
}REG180191E4;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    hsync_rising_start:8;
}REG180191E8;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    hsync_rising_end:8;
}REG180191EC;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    backporch_start:8;
}REG180191F0;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    backporch_end:8;
}REG180191F4;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    hblank_start:8;
}REG180191F8;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    hblank_end:8;
}REG180191FC;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    burst_gate_start:8;
}REG18019200;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    burst_gate_end:8;
}REG18019204;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    hactive_start:8;
}REG18019208;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    hactive_width:8;
}REG1801920C;

typedef struct
{
    unsigned int    hdetect_hstate_phase_max_en:1;
    unsigned int    reserved_0:2;
    unsigned int    hdetect_hstate_3_phase_max:13;
    unsigned int    reserved_1:3;
    unsigned int    hdetect_hstate_4_phase_max:13;
}REG18019210;

typedef struct
{
    unsigned int    reserved_0:3;
    unsigned int    hdetect_hstate_5_phase_max:13;
    unsigned int    hdetect_err04_th:8;
    unsigned int    hdetect_err00_th:8;
}REG18019214;

typedef struct
{
    unsigned int    reserved_0:23;
    unsigned int    cpll_use_fine_or_final_hlock:1;
    unsigned int    new_c_state_i:1;
    unsigned int    new_cstate:1;
    unsigned int    cstate_cntl:2;
    unsigned int    reserved_1:1;
    unsigned int    cstate_status:3;
}REG18019218;

typedef struct
{
    unsigned int    reserved_0:13;
    unsigned int    s_b_level_fir_en:1;
    unsigned int    level_fir_num_32_64_blevel:1;
    unsigned int    level_fir_num_32_64_slevel:1;
    unsigned int    coef_syncmidpt_fir_in:8;
    unsigned int    reserved_1:5;
    unsigned int    new_hpll_lpf_sel:1;
    unsigned int    gate_iir_h_sel:1;
    unsigned int    gate_iir_v_sel:1;
}REG1801921C;

typedef struct
{
    unsigned int    reserved_0:20;
    unsigned int    headswitch_err_sel:2;
    unsigned int    hsync_refind_mask_err:1;
    unsigned int    hsync_refind:1;
    unsigned int    gate_iir_coef1:8;
}REG18019220;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    hdetect_err07_th:8;
    unsigned int    gate_iir_coef2:8;
}REG18019224;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    hstate_err_thl:14;
    unsigned int    reserved_1:6;
    unsigned int    hstate_err_counter:2;
    unsigned int    vphase_status:8;
}REG18019228;

typedef struct
{
    unsigned int    hdetect_err05_th:8;
    unsigned int    hdetect_err10_th:8;
    unsigned int    hdetect_err01_th:8;
    unsigned int    vphasediff_status:8;
}REG1801922C;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    noise_vbi_thresh:8;
}REG18019230;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    coch_detected_status:1;
    unsigned int    reserved_1:1;
    unsigned int    coch_detected_frame:6;
}REG18019234;

typedef struct
{
    unsigned int    reserved_0:28;
    unsigned int    coch_bp_diff_th:4;
}REG18019238;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    coch_line_count_th:8;
}REG1801923C;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    mv_window2_value:8;
}REG18019240;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    ad_burst_gate_start:8;
}REG18019244;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    ad_burst_gate_end:8;
}REG18019248;

typedef struct
{
    unsigned int    reserved_0:29;
    unsigned int    cstripe_detect_control:3;
}REG1801924C;

typedef struct
{
    unsigned int    h_err_constraint_en:1;
    unsigned int    reserved_0:1;
    unsigned int    h_err_constraint_high_th:14;
    unsigned int    reserved_1:2;
    unsigned int    h_err_constraint_low_th:14;
}REG18019250;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    h_err_constraint_hstate:3;
    unsigned int    h_err_constraint_val:13;
}REG18019254;

typedef struct
{
    unsigned int    hdetect_restore_hdto_en:1;
    unsigned int    hdetect_set_new_hdto_n:3;
    unsigned int    hdetect_restore_hdto_status:1;
    unsigned int    hdetect_force_hdto_en:1;
    unsigned int    hdetect_set_hdto_start:10;
    unsigned int    reserved_0:3;
    unsigned int    hdetect_restore_vcr_enable:1;
    unsigned int    reserved_1:2;
    unsigned int    hdetect_save_stable_hdto_start:10;
}REG18019258;

typedef struct
{
    unsigned int    reserved_0:18;
    unsigned int    hdetect_set_hdto_phase_err_th:14;
}REG1801925C;

typedef struct
{
    unsigned int    wrong_if_pc_detect_th:8;
    unsigned int    sync_level_manu:8;
    unsigned int    reserved_0:7;
    unsigned int    sync_level_manu_en:1;
    unsigned int    reserved_1:7;
    unsigned int    wrong_if_pc_detect:1;
}REG18019260;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    cpll_phase_thr_up:14;
    unsigned int    reserved_1:2;
    unsigned int    cpll_phase_thr_dn:14;
}REG18019264;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    cpll_ampl_thr:7;
    unsigned int    reserved_1:2;
    unsigned int    cerror_continune_same_sign_thr:6;
    unsigned int    reserved_2:13;
    unsigned int    cpll_ampl_neg_flag:1;
    unsigned int    cpll_phase_small_flag:1;
    unsigned int    cpll_stable_flag:1;
}REG18019268;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    ampl_out_line_iir:14;
    unsigned int    reserved_1:2;
    unsigned int    phase_out_line_iir:14;
}REG1801926C;

typedef struct
{
    unsigned int    herror_pos_neg_value_diff_thr:16;
    unsigned int    reserved_0:2;
    unsigned int    herror_continune_same_sign_thr:6;
    unsigned int    herror_neg_pos_num_total_thr:4;
    unsigned int    herror_neg_pos_value_total_thr:4;
}REG18019270;

typedef struct
{
    unsigned int    herror_neg_value:16;
    unsigned int    herror_pos_value:16;
}REG18019274;

typedef struct
{
    unsigned int    reserved_0:3;
    unsigned int    herror_neg_pos_err_th:13;
    unsigned int    reserved_1:1;
    unsigned int    herror_neg_pos_num_win_thr:7;
    unsigned int    reserved_2:5;
    unsigned int    herror_pos_neg_num_even:1;
    unsigned int    herror_pos_neg_value_even:1;
    unsigned int    herror_stable_state_hold_en:1;
}REG18019278;

typedef struct
{
    unsigned int    reserved_0:7;
    unsigned int    statistic_h_phase_diff_sec1_end:9;
    unsigned int    reserved_1:7;
    unsigned int    statistic_h_phase_diff_sec1_start:9;
}REG1801927C;

typedef struct
{
    unsigned int    reserved_0:7;
    unsigned int    statistic_h_phase_diff_sec2_end:9;
    unsigned int    reserved_1:7;
    unsigned int    statistic_h_phase_diff_sec2_start:9;
}REG18019280;

typedef struct
{
    unsigned int    reserved_0:3;
    unsigned int    statistic_h_phase_diff_hitso_level2:13;
    unsigned int    reserved_1:3;
    unsigned int    statistic_h_phase_diff_hitso_level1:13;
}REG18019284;

typedef struct
{
    unsigned int    reserved_0:3;
    unsigned int    statistic_h_phase_diff_hitso_level4:13;
    unsigned int    reserved_1:3;
    unsigned int    statistic_h_phase_diff_hitso_level3:13;
}REG18019288;

typedef struct
{
    unsigned int    reserved_0:19;
    unsigned int    statistic_h_phase_diff_hitso_level5:13;
}REG1801928C;

typedef struct
{
    unsigned int    statistic_h_phase_diff_sec1_histo_ready:1;
    unsigned int    reserved_0:1;
    unsigned int    statistic_h_phase_diff_sec1_histo_2:10;
    unsigned int    statistic_h_phase_diff_sec1_histo_1:10;
    unsigned int    statistic_h_phase_diff_sec1_histo_0:10;
}REG18019290;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    statistic_h_phase_diff_sec1_histo_5:10;
    unsigned int    statistic_h_phase_diff_sec1_histo_4:10;
    unsigned int    statistic_h_phase_diff_sec1_histo_3:10;
}REG18019294;

typedef struct
{
    unsigned int    statistic_h_phase_diff_sec2_histo_ready:1;
    unsigned int    reserved_0:1;
    unsigned int    statistic_h_phase_diff_sec2_histo_2:10;
    unsigned int    statistic_h_phase_diff_sec2_histo_1:10;
    unsigned int    statistic_h_phase_diff_sec2_histo_0:10;
}REG18019298;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    statistic_h_phase_diff_sec2_histo_5:10;
    unsigned int    statistic_h_phase_diff_sec2_histo_4:10;
    unsigned int    statistic_h_phase_diff_sec2_histo_3:10;
}REG1801929C;

typedef struct
{
    unsigned int    iir_up_speed_on:1;
    unsigned int    data_level_diff_iir_en:1;
    unsigned int    statistic_data_level_diff_th:14;
    unsigned int    reserved_0:10;
    unsigned int    statistic_data_level_line_num:6;
}REG180192A0;

typedef struct
{
    unsigned int    statistic_data_level_ready:1;
    unsigned int    reserved_0:7;
    unsigned int    statistic_data_level_sec1_min:12;
    unsigned int    statistic_data_level_sec1_max:12;
}REG180192A4;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    statistic_data_level_sec2_min:12;
    unsigned int    statistic_data_level_sec2_max:12;
}REG180192A8;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    statistic_data_level_sec3_min:12;
    unsigned int    statistic_data_level_sec3_max:12;
}REG180192AC;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    statistic_data_level_sec4_min:12;
    unsigned int    statistic_data_level_sec4_max:12;
}REG180192B0;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    statistic_data_level_sec5_min:12;
    unsigned int    statistic_data_level_sec5_max:12;
}REG180192B4;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    statistic_data_level_sec6_min:12;
    unsigned int    statistic_data_level_sec6_max:12;
}REG180192B8;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    statistic_data_level_sec7_min:12;
    unsigned int    statistic_data_level_sec7_max:12;
}REG180192BC;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    statistic_data_level_sec8_min:12;
    unsigned int    statistic_data_level_sec8_max:12;
}REG180192C0;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    vsync_cntl:2;
    unsigned int    vsync_threshold:6;
}REG18019300;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    field_polarity:1;
    unsigned int    flip_field:1;
    unsigned int    veven_delayed:1;
    unsigned int    vodd_delayed:1;
    unsigned int    field_detect_mode:2;
    unsigned int    vloop_tc3:2;
}REG18019304;

typedef struct
{
    unsigned int    reserved_0:25;
    unsigned int    vloop_tc2:7;
}REG18019308;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    vloop_tc1:8;
}REG1801930C;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    serration_threshold:8;
}REG18019310;

typedef struct
{
    unsigned int    reserved_0:14;
    unsigned int    vsync_delay_sel:1;
    unsigned int    vsync_delay_en:1;
    unsigned int    vsync_delay_1d:4;
    unsigned int    vsync_delay_2d:4;
    unsigned int    reserved_1:5;
    unsigned int    no_signal_dec:3;
}REG18019314;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    vactive_start:8;
}REG18019318;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    vactive_height:8;
}REG1801931C;

typedef struct
{
    unsigned int    reserved_0:25;
    unsigned int    vsync_h_min:7;
}REG18019320;

typedef struct
{
    unsigned int    reserved_0:25;
    unsigned int    vsync_h_max:7;
}REG18019324;

typedef struct
{
    unsigned int    reserved_0:25;
    unsigned int    vsync_vbi_min:7;
}REG18019328;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    vlock_wide_range:1;
    unsigned int    vsync_vbi_max:7;
}REG1801932C;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    syncmidpt_dc_rough:1;
    unsigned int    midpt_625_dc_th_en:1;
    unsigned int    midpt_rough_vdetect_en:1;
    unsigned int    vsync_625_midpt_en:1;
    unsigned int    reserved_1:2;
    unsigned int    syncmidpt_add_level:2;
}REG18019330;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    syncmidpt_fix_add_value:8;
}REG18019334;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    midpt_625_dc_th:8;
}REG18019338;

typedef struct
{
    unsigned int    reserved_0:20;
    unsigned int    sync_dc_offset_th:12;
}REG1801933C;

typedef struct
{
    unsigned int    reserved_0:20;
    unsigned int    sync_midpt_625:12;
}REG18019340;

typedef struct
{
    unsigned int    reserved_0:20;
    unsigned int    sync_midpt_h:12;
}REG18019344;

typedef struct
{
    unsigned int    reserved_0:20;
    unsigned int    sync_midpt_v:12;
}REG18019348;

typedef struct
{
    unsigned int    reserved_0:14;
    unsigned int    raw_vdetect_max_sel:2;
    unsigned int    reserved_1:3;
    unsigned int    no_signal_hpll_out:1;
    unsigned int    reserved_2:1;
    unsigned int    no_signal_to_0_sel:1;
    unsigned int    hpll_no_signal_sel:1;
    unsigned int    vlock_sel:1;
    unsigned int    vdetect_pattern_sel:2;
    unsigned int    reserved_3:2;
    unsigned int    adc_lpf_sel:3;
    unsigned int    new_vdetect_line_length_en:1;
}REG1801934C;

typedef struct
{
    unsigned int    reserved_0:6;
    unsigned int    adc_lpf_coef1:10;
    unsigned int    reserved_1:6;
    unsigned int    adc_lpf_coef2:10;
}REG18019350;

typedef struct
{
    unsigned int    reserved_0:6;
    unsigned int    adc_lpf_coef3:10;
    unsigned int    reserved_1:6;
    unsigned int    adc_lpf_coef4:10;
}REG18019354;

typedef struct
{
    unsigned int    reserved_0:6;
    unsigned int    adc_lpf_coef5:10;
    unsigned int    reserved_1:6;
    unsigned int    adc_lpf_coef6:10;
}REG18019358;

typedef struct
{
    unsigned int    reserved_0:6;
    unsigned int    adc_lpf_coef7:10;
    unsigned int    reserved_1:6;
    unsigned int    adc_lpf_coef8:10;
}REG1801935C;

typedef struct
{
    unsigned int    reserved_0:6;
    unsigned int    adc_lpf_coef9:10;
    unsigned int    reserved_1:6;
    unsigned int    adc_lpf_coefa:10;
}REG18019360;

typedef struct
{
    unsigned int    reserved_0:6;
    unsigned int    adc_lpf_coefb:10;
    unsigned int    reserved_1:6;
    unsigned int    adc_lpf_coefc:10;
}REG18019364;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    new_vdetect_line_length:8;
}REG18019368;

typedef struct
{
    unsigned int    reserved_0:28;
    unsigned int    new_vdetect_force_en:1;
    unsigned int    no_vsync_flag_en:1;
    unsigned int    new_vdetect_window_en:1;
    unsigned int    new_vdetect_window_manu_en:1;
}REG1801936C;

typedef struct
{
    unsigned int    reserved_0:20;
    unsigned int    new_vdetect_window:12;
}REG18019370;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    new_vdetect_max_limit_value:12;
    unsigned int    reserved_1:2;
    unsigned int    new_vdetect_max_limit_en:1;
    unsigned int    new_vdetect_coch_en:1;
    unsigned int    new_vdetect_en:1;
    unsigned int    gate_sel:1;
    unsigned int    vloss_detect_en:1;
    unsigned int    new_vdetect_vcount_window_en:1;
    unsigned int    new_vsync_offset_manul_mode_en:1;
    unsigned int    new_vsync_offset_manul:3;
}REG18019374;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    old_hdetect_lpf_en:1;
    unsigned int    new_vdetect_feature_th_manul_en:1;
    unsigned int    no_vsync_flag:1;
    unsigned int    new_vloss_flag:1;
    unsigned int    force_new_vdetect_fine_window:1;
    unsigned int    vsync_fine_window_state1_en:1;
    unsigned int    reserved_1:2;
}REG18019378;

typedef struct
{
    unsigned int    reserved_0:22;
    unsigned int    new_vdetect_loop_core_th:10;
}REG1801937C;

typedef struct
{
    unsigned int    reserved_0:20;
    unsigned int    new_vdetect_diff_offset:12;
}REG18019380;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    vsync_fine_start1:10;
    unsigned int    reserved_1:2;
    unsigned int    new_vdetect_loss_max:6;
    unsigned int    reserved_2:2;
    unsigned int    vsync_fine_start:10;
}REG18019384;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    vsync_fine_end1:10;
    unsigned int    reserved_1:2;
    unsigned int    new_vdetect_loss_up:6;
    unsigned int    reserved_2:2;
    unsigned int    vsync_fine_end:10;
}REG18019388;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    no_vsync_th_hi:4;
    unsigned int    no_vsync_th_lo:4;
}REG1801938C;

typedef struct
{
    unsigned int    reserved_0:14;
    unsigned int    new_vdetect_loss_dn:6;
    unsigned int    reserved_1:2;
    unsigned int    new_vdetect_fine_vphase_th:10;
}REG18019390;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    new_vdetect_feature_th1:8;
}REG18019394;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    new_vdetect_feature_th2:8;
}REG18019398;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    new_vdetect_feature_th3:8;
}REG1801939C;

typedef struct
{
    unsigned int    new_vdetect_feature_th7:8;
    unsigned int    new_vdetect_feature_th6:8;
    unsigned int    new_vdetect_feature_th5:8;
    unsigned int    new_vdetect_feature_th4:8;
}REG180193A0;

typedef struct
{
    unsigned int    reserved_0:3;
    unsigned int    vstate0_direct_vsync:1;
    unsigned int    vstate0_counter_num:8;
    unsigned int    reserved_1:3;
    unsigned int    vsync_stable_en:1;
    unsigned int    vstate_reset:2;
    unsigned int    vsync_refind_con_sel:2;
    unsigned int    reserved_2:3;
    unsigned int    vsync_refind:1;
    unsigned int    reserved_3:4;
    unsigned int    vstate_2to3_er:4;
}REG180193B0;

typedef struct
{
    unsigned int    vstate_2to3_th:8;
    unsigned int    vstate_new2to3_en:1;
    unsigned int    hsync_refind_min:7;
    unsigned int    reserved_0:1;
    unsigned int    hsync_refind_max:7;
    unsigned int    vstate_1to2_er:4;
    unsigned int    vstate_back1_er:4;
}REG180193B4;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    hsync_reset_for_vsync:10;
    unsigned int    reserved_1:2;
    unsigned int    hsync_reset_for_data:10;
    unsigned int    vstate_counter_num:8;
}REG180193B8;

typedef struct
{
    unsigned int    vphase_error_window:8;
    unsigned int    reserved_0:3;
    unsigned int    vstate3_err_adjust_en:1;
    unsigned int    vstate3_err_adjust_th:4;
    unsigned int    reserved_1:3;
    unsigned int    vsync_vertical_sum_num:5;
    unsigned int    reserved_2:2;
    unsigned int    vstate_status:2;
    unsigned int    vstate_sw_en:1;
    unsigned int    vstate_sw:2;
    unsigned int    vcr_back_en:1;
}REG180193BC;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    vloop0_tc1:8;
}REG180193C0;

typedef struct
{
    unsigned int    reserved_0:25;
    unsigned int    vloop0_tc2:7;
}REG180193C4;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    vloop2_tc1:8;
}REG180193C8;

typedef struct
{
    unsigned int    reserved_0:25;
    unsigned int    vloop2_tc2:7;
}REG180193CC;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    vloop3_tc1:8;
}REG180193D0;

typedef struct
{
    unsigned int    reserved_0:25;
    unsigned int    vloop3_tc2:7;
}REG180193D4;

typedef struct
{
    unsigned int    reserved_0:26;
    unsigned int    vloop0_tc3:2;
    unsigned int    vloop2_tc3:2;
    unsigned int    vloop3_tc3:2;
}REG180193D8;

typedef struct
{
    unsigned int    reserved_0:25;
    unsigned int    flag_chrmaunlock_kill:1;
    unsigned int    flag_user_kill:1;
    unsigned int    flag_cgain_too_big_kill:1;
    unsigned int    new_vdetect_lock_en:1;
    unsigned int    vlock_count:3;
}REG180193DC;

typedef struct
{
    unsigned int    vsync_detect_rst:1;
    unsigned int    reserved_0:2;
    unsigned int    vsync_detect_crlock_en:1;
    unsigned int    reserved_1:2;
    unsigned int    vsync_detect_count_thl:6;
    unsigned int    reserved_2:1;
    unsigned int    vsync_detect_core_thl:11;
    unsigned int    vlock_window:8;
}REG180193E0;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    vlock_phase_plus:8;
}REG180193E4;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    vline_adj_cnt_a:8;
}REG180193E8;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    vline_adj_cnt_b:8;
}REG180193EC;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    table_hactive_width:8;
}REG180193F0;

typedef struct
{
    unsigned int    reserved_0:12;
    unsigned int    vlines_the_same_cnt_thr:4;
    unsigned int    reserved_1:1;
    unsigned int    vsync_freerun_when_unstable_en:1;
    unsigned int    vlines_the_same_flag:1;
    unsigned int    vlines_diff_flag:1;
    unsigned int    reserved_2:2;
    unsigned int    vlines_freerun:10;
}REG180193F4;

typedef struct
{
    unsigned int    reserved_0:3;
    unsigned int    fix_cgain:1;
    unsigned int    reserved_1:16;
    unsigned int    cagc_pll_input_sel:2;
    unsigned int    cagc_data_input_sel:2;
    unsigned int    cagc:8;
}REG18019400;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    user_ckill_mode:2;
    unsigned int    vbi_ckill:1;
    unsigned int    hlock_ckill:1;
    unsigned int    chroma_kill:4;
}REG18019404;

typedef struct
{
    unsigned int    reserved_0:17;
    unsigned int    lose_acc_chromalock_level:3;
    unsigned int    reserved_1:1;
    unsigned int    chromalock_input_acc_en:1;
    unsigned int    chromalock_input_acc_num:2;
    unsigned int    lose_chromalock_count:4;
    unsigned int    lose_chromalock_level:3;
    unsigned int    lose_chromalock_ckill:1;
}REG18019408;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    cnew_gate_en:1;
    unsigned int    reserved_1:3;
    unsigned int    flag358_cresample_lpf_sel:2;
    unsigned int    cagc_igain:2;
}REG1801940C;

typedef struct
{
    unsigned int    reserved_0:7;
    unsigned int    cresample_signed_en:1;
    unsigned int    reserved_1:3;
    unsigned int    cloop_freq_offset_limit_en:1;
    unsigned int    cloop_freq_offset_limit:12;
    unsigned int    secam_cresample_lpf_sel:2;
    unsigned int    cresample_lpf_sel:2;
    unsigned int    cstate:3;
    unsigned int    fixed_cstate:1;
}REG18019410;

typedef struct
{
    unsigned int    reserved_0:25;
    unsigned int    chroma_burst5or10:1;
    unsigned int    fixed_burstgate:1;
    unsigned int    cautopos:5;
}REG18019414;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    chromalock_cstate_en:1;
    unsigned int    chromalock_cstate:3;
    unsigned int    reserved_1:3;
    unsigned int    ckill_lb_sel:1;
}REG18019418;

typedef struct
{
    unsigned int    ckill_level_user_offset_en:1;
    unsigned int    reserved_0:1;
    unsigned int    ckill_level_user_offset:14;
    unsigned int    ckill_level_user_mode_en:1;
    unsigned int    reserved_1:1;
    unsigned int    ckill_level_user_mode_value:14;
}REG1801941C;

typedef struct
{
    unsigned int    reserved_0:7;
    unsigned int    badedit_noisy_off_en:1;
    unsigned int    badedit_in_noise_thr:8;
    unsigned int    badedit_out_noise_thr:8;
    unsigned int    fast_lock_en:1;
    unsigned int    phase_fast_lock_en:1;
    unsigned int    badedit_phase_lock_en:1;
    unsigned int    badedit_pulse_detect:1;
    unsigned int    bad_phase_detect:1;
    unsigned int    badedit_line_num:3;
}REG18019420;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    badedit_th:8;
}REG18019424;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    badphase_th:8;
}REG18019428;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    cstate_line_num:8;
}REG1801942C;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    cpeak_noisy_act_en_pll:1;
    unsigned int    cpeak_noisy_act_en:1;
    unsigned int    cpeak_noise_thr2:8;
    unsigned int    cpeak_noise_thr1:8;
    unsigned int    reserved_1:3;
    unsigned int    chroma_peak_en_pll:1;
    unsigned int    new_cgain_level_en:1;
    unsigned int    chroma_peak_en:1;
    unsigned int    chroma_agc_peak_cnt:6;
}REG18019430;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    chroma_agc_peak_nominal:8;
}REG18019434;

typedef struct
{
    unsigned int    reserved_0:14;
    unsigned int    close_ckill_loopfilter:1;
    unsigned int    cagc_upper_xroot2_en:1;
    unsigned int    reserved_1:2;
    unsigned int    cagc_upper:14;
}REG18019438;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    cagc_peak_err_adj_en:1;
    unsigned int    cagc_burst_err_adj_en:1;
    unsigned int    cagc_peak_err_diff_sel:6;
}REG1801943C;

typedef struct
{
    unsigned int    reserved_0:26;
    unsigned int    cagc_burst_err_diff_sel:6;
}REG18019440;

typedef struct
{
    unsigned int    reserved_0:26;
    unsigned int    cagc_peak_luma_ratio:6;
}REG18019444;

typedef struct
{
    unsigned int    reserved_0:25;
    unsigned int    cb_delay:3;
    unsigned int    reserved_1:1;
    unsigned int    cr_delay:3;
}REG18019448;

typedef struct
{
    unsigned int    reserved_0:30;
    unsigned int    flag_burst_x4:1;
    unsigned int    burst_cgain_x4_en:1;
}REG1801944C;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    burst_cgain_mag_th:8;
}REG18019450;

typedef struct
{
    unsigned int    flag358_iir_en:1;
    unsigned int    flag358_iir_cunlock_en:1;
    unsigned int    flag358_cdto_inc:30;
}REG18019454;

typedef struct
{
    unsigned int    burst_location_fix_en:1;
    unsigned int    burst_location_sel_clock:1;
    unsigned int    burst_location_selreg_en:1;
    unsigned int    normal_burst_locationreg_en:1;
    unsigned int    burst_location_sel_modify_sel:3;
    unsigned int    burst_location_sel_modify_en:1;
    unsigned int    burst_location_center_modify_sel:3;
    unsigned int    burst_location_center_modify_en:1;
    unsigned int    reserved_0:1;
    unsigned int    burst_location_fix:11;
    unsigned int    reserved_1:2;
    unsigned int    burst_location_sel:2;
    unsigned int    burst_location_lpf_reset:1;
    unsigned int    burst_location_rst_en:1;
    unsigned int    auto_burst_location_en:1;
    unsigned int    new_coef_sel:1;
}REG18019458;

typedef struct
{
    unsigned int    reserved_0:5;
    unsigned int    burst_location_result:11;
    unsigned int    reserved_1:5;
    unsigned int    normal_burst_location:11;
}REG1801945C;

typedef struct
{
    unsigned int    wide_burst_location_modify_sel:3;
    unsigned int    wide_burst_location_modify_en:1;
    unsigned int    reserved_0:1;
    unsigned int    wide_burst_location_end:11;
    unsigned int    reserved_1:2;
    unsigned int    wide_burst_location_endreg_en:1;
    unsigned int    wide_burst_location_startreg_en:1;
    unsigned int    reserved_2:1;
    unsigned int    wide_burst_location_start:11;
}REG18019460;

typedef struct
{
    unsigned int    reserved_0:18;
    unsigned int    burst_location_sel_status:2;
    unsigned int    reserved_1:1;
    unsigned int    normal_burst_location_status:11;
}REG18019464;

typedef struct
{
    unsigned int    reserved_0:5;
    unsigned int    wide_burst_location_end_status:11;
    unsigned int    reserved_1:5;
    unsigned int    wide_burst_location_start_status:11;
}REG18019468;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    flag625_vsync_l_sel:1;
    unsigned int    flag625_vsync_l_th:1;
    unsigned int    palm_atone_counter:6;
}REG18019490;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    palm_atone_threshold:8;
}REG18019494;

typedef struct
{
    unsigned int    reserved_0:20;
    unsigned int    colour_mode_dark_check:1;
    unsigned int    colour_mode_dark_set:3;
    unsigned int    auto_mode_en:1;
    unsigned int    auto_625only_en:1;
    unsigned int    auto_burst_switch_625only:1;
    unsigned int    reserved_1:1;
    unsigned int    state_machine_reset:1;
    unsigned int    manual_mode_select:3;
}REG180194A0;

typedef struct
{
    unsigned int    reserved_0:25;
    unsigned int    set_mode_status:3;
    unsigned int    reserved_1:1;
    unsigned int    decision_mode_status:3;
}REG180194A4;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    disable_mode_en:1;
    unsigned int    disable_mode:1;
    unsigned int    statistic_number:6;
}REG180194A8;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    prefer_ntsc50_paln:1;
    unsigned int    prefer_ntsc443_pal60:1;
    unsigned int    prefer_secam_pali:1;
    unsigned int    prefer_ntsc_palm:1;
    unsigned int    prefer_ntsc50_paln_en:1;
    unsigned int    prefer_ntsc443_pal60_en:1;
    unsigned int    prefer_secam_pali_en:1;
    unsigned int    prefer_ntsc_palm_en:1;
}REG180194AC;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    fix_625flag_en:1;
    unsigned int    fix_443flag_en:1;
    unsigned int    fix_palorflag_en:1;
    unsigned int    fix_secamflag_en:1;
    unsigned int    fix_625_h:1;
    unsigned int    fix_443_h:1;
    unsigned int    fix_palor_h:1;
    unsigned int    fix_secam_h:1;
}REG180194B0;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    hactivestartreg_en:1;
    unsigned int    hpixelreg_en:1;
    unsigned int    colourmodereg_en:1;
    unsigned int    hagcreg_en:1;
    unsigned int    vline625reg_en:1;
    unsigned int    cdtomem_reg_en:1;
    unsigned int    vsyncreg_en:1;
    unsigned int    ped_reg_en:1;
}REG180194B4;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    switch_palo_palm_method:2;
    unsigned int    auto_secam_pali_method:2;
    unsigned int    secam_flag_freq_disable:1;
    unsigned int    statistic_multiplier:3;
}REG180194B8;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    new_cr1delay_en:1;
    unsigned int    new_cb1delay_en:1;
    unsigned int    new_y1delay_en:1;
    unsigned int    reserved_1:1;
    unsigned int    cr1delayreg_en:1;
    unsigned int    cb1delayreg_en:1;
    unsigned int    y1delayreg_en:1;
    unsigned int    reserved_2:2;
    unsigned int    cr1delay:6;
    unsigned int    reserved_3:2;
    unsigned int    cb1delay:6;
    unsigned int    reserved_4:2;
    unsigned int    y1delay:6;
}REG180194C0;

typedef struct
{
    unsigned int    auto_pos_modify_en:1;
    unsigned int    auto_pos_mode_sel:3;
    unsigned int    auto_ycdelay_modify_en:1;
    unsigned int    auto_ycdelay_mode_sel:3;
    unsigned int    reserved_0:1;
    unsigned int    ckill_cr1delayreg_en:1;
    unsigned int    ckill_cb1delayreg_en:1;
    unsigned int    ckill_y1delayreg_en:1;
    unsigned int    ckill_cr1delay:6;
    unsigned int    ckill_cb1delay:6;
    unsigned int    reserved_1:2;
    unsigned int    ckill_y1delay:6;
}REG180194C4;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    fix_358flag_en:1;
    unsigned int    fix_358_h:1;
    unsigned int    auto_443_358_method_625:2;
    unsigned int    auto_443_358_method_525:2;
    unsigned int    auto_sel_no_burst_625:2;
}REG180194C8;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    no_burst_mag_th:8;
}REG180194CC;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    no_burst_mag_filter_th:8;
}REG180194D0;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    burst_mag_trig_offset:4;
    unsigned int    no_burst_flag:1;
    unsigned int    paln_flag_new:1;
    unsigned int    burst_win_error:1;
    unsigned int    no_burst_443_en:1;
}REG180194D4;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    flag358_secam_phase_diff_hcount_en:1;
    unsigned int    flag358_phase_diff_hcount:7;
}REG180194D8;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    flag358_secam_phase_diff_dr:8;
}REG180194DC;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    flag358_secam_phase_diff_db:8;
}REG180194E0;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    burst_mag_th_358:8;
}REG180194E4;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    table_cagc_en:1;
    unsigned int    table_vline_625:1;
    unsigned int    table_hpixel:2;
    unsigned int    table_ped:1;
    unsigned int    table_colour_mode:3;
}REG180194F0;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    table_hagc:8;
}REG180194F4;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    table_hactive_start:8;
}REG180194F8;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    table_vactive_start:8;
}REG180194FC;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    table_vactive_height:8;
}REG18019500;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    table_cdto:30;
}REG18019504;

typedef struct
{
    unsigned int    vline_625_vloop_clr_en:1;
    unsigned int    vline_625_src_sel:1;
    unsigned int    new_625flag_window:10;
    unsigned int    reserved_0:2;
    unsigned int    new_625flag_div_thr:10;
    unsigned int    flag_625_counter:8;
}REG18019508;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    flag_443_counter:8;
}REG1801950C;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    secam_flag_counter:8;
}REG18019510;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    palm_flag_counter:8;
}REG18019514;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    burst_valid_counter:8;
}REG18019518;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    midpoint_adjustment:8;
}REG1801951C;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    freq_flag_threshold_tune:8;
}REG18019520;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    frequency_valid_upper_limit:8;
}REG18019524;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    condition_enable:1;
    unsigned int    frequency_valid_inner_limit:7;
}REG18019528;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    frequency_valid_lower_limit:8;
}REG1801952C;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    secam_flag_frequency_upper_limit:8;
}REG18019530;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    secam_flag_frequency_lower_limit:8;
}REG18019534;

typedef struct
{
    unsigned int    reserved_0:3;
    unsigned int    palm_flag_limit_en:1;
    unsigned int    pal_sw_acc_input_polar:1;
    unsigned int    pal_sw_input_sel:1;
    unsigned int    palm_sw_acc_input_polar:1;
    unsigned int    palm_sw_input_sel:1;
    unsigned int    reserved_1:3;
    unsigned int    pal_flag_threshold:13;
    unsigned int    palm_flag_phase_adjust:8;
}REG18019538;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    burst_mag_trigger:4;
    unsigned int    burst_mag_threshold:4;
}REG1801953C;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    vsync_select:1;
    unsigned int    secam_frequency_valid_enable:1;
    unsigned int    auto_noburst_palflag_off:1;
    unsigned int    burst_noise_weighting_auto:1;
    unsigned int    burst_noise_weighting:4;
}REG18019540;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    agc_gate_kill_sync_white_en:1;
    unsigned int    new_358_flag_cordic:1;
    unsigned int    new_358_flag_cos_sin:1;
    unsigned int    reserved_1:5;
}REG18019550;

typedef struct
{
    unsigned int    reserved_0:21;
    unsigned int    new_dto_358_cnt_up:11;
}REG18019554;

typedef struct
{
    unsigned int    reserved_0:21;
    unsigned int    new_dto_358_cnt_dn:11;
}REG18019558;

typedef struct
{
    unsigned int    reserved_0:22;
    unsigned int    sep_count_th:10;
}REG1801955C;

typedef struct
{
    unsigned int    reserved_0:21;
    unsigned int    sep_burst_start:11;
}REG18019560;

typedef struct
{
    unsigned int    reserved_0:21;
    unsigned int    sep_burst_end:11;
}REG18019564;

typedef struct
{
    unsigned int    reserved_0:22;
    unsigned int    sep_core_burst_rst:1;
    unsigned int    sep_core_burst_rst_en:1;
    unsigned int    sep_443_core_burst:8;
}REG18019568;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    sep_358_core_burst:8;
}REG1801956C;

typedef struct
{
    unsigned int    reserved_0:22;
    unsigned int    sep_pal_secam_core_burst_rst:1;
    unsigned int    sep_pal_secam_core_burst_rst_en:1;
    unsigned int    sep_pal_secam_core_burst:8;
}REG18019570;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    sep_443_thl:8;
    unsigned int    sep_358_thl:8;
}REG18019574;

typedef struct
{
    unsigned int    reserved_0:7;
    unsigned int    sep_secam_f_sel:1;
    unsigned int    sep_secam_thl:8;
    unsigned int    sep_secam_thl_ratio:8;
    unsigned int    reserved_1:5;
    unsigned int    power_secam_flag:1;
    unsigned int    power_443_flag:1;
    unsigned int    power_358_flag:1;
}REG18019578;

typedef struct
{
    unsigned int    reserved_0:25;
    unsigned int    pk_foraudio:1;
    unsigned int    mode_secam2_sel:2;
    unsigned int    reserved_1:2;
    unsigned int    mode_443358pk_sel:2;
}REG1801957C;

typedef struct
{
    unsigned int    dark_badedit_noisy_off_en:1;
    unsigned int    dark_badedit_phase_lock_en:1;
    unsigned int    dark_fast_lock_en:1;
    unsigned int    dark_phase_fast_lock_en:1;
    unsigned int    dark_fixed_cstate:1;
    unsigned int    dark_cstate:3;
    unsigned int    dark_chromalock_cstate_en:1;
    unsigned int    dark_chromalock_cstate:3;
    unsigned int    reserved_0:3;
    unsigned int    dark_cresample_signed_en:1;
    unsigned int    dark_cagc:8;
    unsigned int    dark_cagc_pll_input_sel:2;
    unsigned int    dark_cagc_en:1;
    unsigned int    dark_fix_cgain:1;
    unsigned int    dark_cpll_cdto_change_en:1;
    unsigned int    dark_cpll_cdto_change_mode:3;
}REG18019580;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    dark_cpll_cdto_change_value:30;
}REG18019584;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    dark_palm_flag_counter:8;
    unsigned int    dark_palm_flag_phase_adjust:8;
    unsigned int    reserved_1:1;
    unsigned int    dark_palsw_level:2;
    unsigned int    dark_palm_flag_limit_en:1;
    unsigned int    dark_pal_sw_acc_input_polar:1;
    unsigned int    dark_pal_sw_input_sel:1;
    unsigned int    dark_palm_sw_acc_input_polar:1;
    unsigned int    dark_palm_sw_input_sel:1;
}REG18019588;

typedef struct
{
    unsigned int    reserved_0:3;
    unsigned int    dark_pal_flag_threshold:13;
    unsigned int    reserved_1:1;
    unsigned int    dark_chromalock_input_acc_en:1;
    unsigned int    dark_chromalock_input_acc_num:2;
    unsigned int    reserved_2:1;
    unsigned int    dark_lose_acc_chromalock_level:3;
    unsigned int    dark_lose_chromalock_count:4;
    unsigned int    reserved_3:1;
    unsigned int    dark_lose_chromalock_level:3;
}REG1801958C;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    dark_cpll_decide_mode_error:2;
    unsigned int    reserved_1:1;
    unsigned int    dark_cpll_decide_mode:3;
    unsigned int    dark_cpll_vsync_num:8;
    unsigned int    dark_cpll_chromalock_sel:1;
    unsigned int    dark_cpll_mode_en_pali:1;
    unsigned int    dark_cpll_mode_en_pal60:1;
    unsigned int    dark_cpll_mode_en_ntsc443:1;
    unsigned int    dark_cpll_mode_en_paln:1;
    unsigned int    dark_cpll_mode_en_ntsc50:1;
    unsigned int    dark_cpll_mode_en_palm:1;
    unsigned int    dark_cpll_mode_en_ntsc:1;
    unsigned int    dark_cpll_fix_mode_en:1;
    unsigned int    dark_cpll_user_mode:3;
    unsigned int    dark_cpll_mode:2;
    unsigned int    dark_cpll_auto_run:1;
    unsigned int    dark_cpll_start:1;
}REG18019590;

typedef struct
{
    unsigned int    chromalock_acc_dark:1;
    unsigned int    chromalock_dark:1;
    unsigned int    pal_flag_dark:1;
    unsigned int    palm_flag_dark:1;
    unsigned int    reserved_0:3;
    unsigned int    dark_cpll_loop_done:1;
    unsigned int    reserved_1:1;
    unsigned int    dark_cpll_pali_palm_flag:1;
    unsigned int    dark_cpll_pal60_palm_flag:1;
    unsigned int    dark_cpll_ntsc443_palm_flag:1;
    unsigned int    dark_cpll_paln_palm_flag:1;
    unsigned int    dark_cpll_ntsc50_palm_flag:1;
    unsigned int    dark_cpll_palm_palm_flag:1;
    unsigned int    dark_cpll_ntsc_palm_flag:1;
    unsigned int    reserved_2:1;
    unsigned int    dark_cpll_pali_pal_flag:1;
    unsigned int    dark_cpll_pal60_pal_flag:1;
    unsigned int    dark_cpll_ntsc443_pal_flag:1;
    unsigned int    dark_cpll_paln_pal_flag:1;
    unsigned int    dark_cpll_ntsc50_pal_flag:1;
    unsigned int    dark_cpll_palm_pal_flag:1;
    unsigned int    dark_cpll_ntsc_pal_flag:1;
    unsigned int    reserved_3:1;
    unsigned int    dark_cpll_pali_lock:1;
    unsigned int    dark_cpll_pal60_lock:1;
    unsigned int    dark_cpll_ntsc443_lock:1;
    unsigned int    dark_cpll_paln_lock:1;
    unsigned int    dark_cpll_ntsc50_lock:1;
    unsigned int    dark_cpll_palm_lock:1;
    unsigned int    dark_cpll_ntsc_lock:1;
}REG18019594;

typedef struct
{
    unsigned int    reserved_0:23;
    unsigned int    vd_irq_en:1;
    unsigned int    vcr_irq_en:1;
    unsigned int    nosig_irq_en:1;
    unsigned int    mode_irq_en:1;
    unsigned int    proscan_irq_en:1;
    unsigned int    noisy_irq_en:1;
    unsigned int    chromalock_irq_en:1;
    unsigned int    vlock_irq_en:1;
    unsigned int    hlock_irq_en:1;
}REG180195A0;

typedef struct
{
    unsigned int    reserved_0:26;
    unsigned int    vd_scene_change_irq_en:1;
    unsigned int    ddr_addr_irq_en:1;
    unsigned int    noisy_vbi_irq_en:1;
    unsigned int    coch_irq_en:1;
    unsigned int    mv_irq_en:1;
    unsigned int    field_irq_en:1;
}REG180195A4;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    ad1_over_irq_en:1;
    unsigned int    ad1_under_irq_en:1;
    unsigned int    ad2_over_irq_en:1;
    unsigned int    ad2_under_irq_en:1;
    unsigned int    ad3_over_irq_en:1;
    unsigned int    ad3_under_irq_en:1;
    unsigned int    ad4_over_irq_en:1;
    unsigned int    ad4_under_irq_en:1;
}REG180195A8;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    vcr_irq:1;
    unsigned int    nosig_irq:1;
    unsigned int    mode_irq:1;
    unsigned int    proscan_irq:1;
    unsigned int    noisy_irq:1;
    unsigned int    chromalock_irq:1;
    unsigned int    vlock_irq:1;
    unsigned int    hlock_irq:1;
}REG180195AC;

typedef struct
{
    unsigned int    reserved_0:26;
    unsigned int    vd_scene_change_irq:1;
    unsigned int    ddr_addr_irq:1;
    unsigned int    noisy_vbi_irq:1;
    unsigned int    coch_irq:1;
    unsigned int    mv_irq:1;
    unsigned int    field_irq:1;
}REG180195B0;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    ad1_overflow_irq:1;
    unsigned int    ad1_underflow_irq:1;
    unsigned int    ad2_overflow_irq:1;
    unsigned int    ad2_underflow_irq:1;
    unsigned int    ad3_overflow_irq:1;
    unsigned int    ad3_underflow_irq:1;
    unsigned int    ad4_overflow_irq:1;
    unsigned int    ad4_underflow_irq:1;
}REG180195B4;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    adc_over_threh:4;
    unsigned int    adc_under_threh:4;
}REG180195B8;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    ld_pause_detect:1;
    unsigned int    ldp_det_en:1;
    unsigned int    ldp_switch_en:1;
    unsigned int    ldpaus_th:5;
}REG180195E0;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    coch_en:1;
    unsigned int    disp_freerun_sel:1;
    unsigned int    vd_out_dvalid_sel_d1:1;
    unsigned int    vcr_disable:1;
    unsigned int    freerun_sel:1;
    unsigned int    lock_h_on_no_signal:1;
    unsigned int    disable_blue_screen_when_vcr:1;
    unsigned int    detect_vcr_when_h_unlock:1;
}REG180195E4;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    cenable_line_count:8;
}REG180195E8;

typedef struct
{
    unsigned int    reserved_0:26;
    unsigned int    auto_3dchange_vcr:1;
    unsigned int    auto_3dchange_noisy:1;
    unsigned int    field_toggle_en:1;
    unsigned int    cbcr_ini_mux:1;
    unsigned int    reserved_1:2;
}REG180195EC;

typedef struct
{
    unsigned int    reserved_0:18;
    unsigned int    cdet_phase_err_status:14;
}REG180195F0;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    sw_comp:2;
    unsigned int    sw_pr_r:2;
    unsigned int    sw_pb_b:2;
    unsigned int    sw_g:2;
}REG18019608;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    clamp_ad1:2;
    unsigned int    clamp_ad2:2;
    unsigned int    clamp_ad3:2;
    unsigned int    clamp_ad4:2;
}REG1801960C;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    clamp_a_up_en:1;
    unsigned int    clamp_a_dn_en:1;
    unsigned int    clamp_b_up_en:1;
    unsigned int    clamp_b_dn_en:1;
    unsigned int    clamp_c_up_en:1;
    unsigned int    clamp_c_dn_en:1;
    unsigned int    clamp_d_up_en:1;
    unsigned int    clamp_d_dn_en:1;
}REG18019610;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    aa3_en:1;
    unsigned int    fb_th:3;
    unsigned int    fb_delay:4;
}REG18019618;

typedef struct
{
    unsigned int    reserved_0:21;
    unsigned int    fb2rgb_dly:3;
    unsigned int    reserved_1:2;
    unsigned int    rgb2cvbs_dly:6;
}REG1801961C;

typedef struct
{
    unsigned int    reserved_0:23;
    unsigned int    outfifo_444_sel:1;
    unsigned int    scart_en:1;
    unsigned int    yout_limit:1;
    unsigned int    fb_inv:1;
    unsigned int    cout_limit:1;
    unsigned int    out444_sel:1;
    unsigned int    aa422_en:1;
    unsigned int    fb_sw:1;
    unsigned int    fb_en:1;
}REG18019620;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    fb_thmax:4;
    unsigned int    fb_thmin:4;
}REG18019624;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    contrast2:8;
}REG18019628;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    brightness2:8;
}REG1801962C;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    cr_saturation:8;
}REG18019630;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    cb_saturation:8;
}REG18019634;

typedef struct
{
    unsigned int    reserved_0:26;
    unsigned int    peak_range2:2;
    unsigned int    peak_gain2:3;
    unsigned int    peak_en2:1;
}REG18019638;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    fbgain_en:1;
    unsigned int    fbgain:7;
}REG1801963C;

typedef struct
{
    unsigned int    reserved_0:26;
    unsigned int    scart_vbi_rgb_sel:2;
    unsigned int    reserved_1:1;
    unsigned int    fb_status:3;
}REG18019640;

typedef struct
{
    unsigned int    reserved_0:20;
    unsigned int    yorr_in_offset_status:12;
}REG18019650;

typedef struct
{
    unsigned int    reserved_0:20;
    unsigned int    uorg_in_offset_status:12;
}REG18019654;

typedef struct
{
    unsigned int    reserved_0:20;
    unsigned int    vorb_in_offset_status:12;
}REG18019658;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    rgb_output_en:1;
    unsigned int    reserved_1:7;
}REG1801965C;

typedef struct
{
    unsigned int    reserved_0:22;
    unsigned int    gain_r:10;
}REG18019660;

typedef struct
{
    unsigned int    reserved_0:22;
    unsigned int    gain_g:10;
}REG18019664;

typedef struct
{
    unsigned int    reserved_0:22;
    unsigned int    gain_b:10;
}REG18019668;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    offset_r:8;
}REG1801966C;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    offset_g:8;
}REG18019670;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    offset_b:8;
}REG18019674;

typedef struct
{
    unsigned int    reserved_0:20;
    unsigned int    r_prblevel:12;
}REG18019680;

typedef struct
{
    unsigned int    reserved_0:20;
    unsigned int    g_blevel:12;
}REG18019684;

typedef struct
{
    unsigned int    reserved_0:20;
    unsigned int    b_pbblevel:12;
}REG18019688;

typedef struct
{
    unsigned int    reserved_0:20;
    unsigned int    comp_blevel:12;
}REG1801968C;

typedef struct
{
    unsigned int    reserved_0:20;
    unsigned int    comp_slevel:12;
}REG18019690;

typedef struct
{
    unsigned int    reserved_0:20;
    unsigned int    vbi_blevel:12;
}REG18019694;

typedef struct
{
    unsigned int    reserved_0:18;
    unsigned int    hphase_err_status:14;
}REG18019698;

typedef struct
{
    unsigned int    reserved_0:20;
    unsigned int    avout_fifo_sel:1;
    unsigned int    avout_fifo_rd_ptr:11;
}REG1801969C;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    blank_level_comp_manu_add:12;
    unsigned int    reserved_1:4;
    unsigned int    blank_level_comp_manu:12;
}REG180196A0;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    blank_level_c_manu:12;
    unsigned int    reserved_1:4;
    unsigned int    blank_level_r_manu:12;
}REG180196A4;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    blank_level_g_manu:12;
    unsigned int    reserved_1:4;
    unsigned int    blank_level_b_manu:12;
}REG180196A8;

typedef struct
{
    unsigned int    fpga_test1:31;
    unsigned int    factory_flag:1;
}REG180196B0;

typedef struct
{
    unsigned int    fpga_test2:32;
}REG180196B4;

typedef struct
{
    unsigned int    fpga_test3:32;
}REG180196B8;

typedef struct
{
    unsigned int    fpga_test4:32;
}REG180196BC;

typedef struct
{
    unsigned int    fpga_test5:32;
}REG180196C0;

typedef struct
{
    unsigned int    fpga_test6:32;
}REG180196C4;

typedef struct
{
    unsigned int    fpga_test7:32;
}REG180196C8;

typedef struct
{
    unsigned int    fpga_test8:32;
}REG180196CC;

typedef struct
{
    unsigned int    reserved_0:15;
    unsigned int    secam_y_fir_en:1;
    unsigned int    reserved_1:1;
    unsigned int    secam_y_hpf_sel:3;
    unsigned int    reserved_2:1;
    unsigned int    secam_y_lpf_sel:3;
    unsigned int    drdb_freq_const:1;
    unsigned int    drdb_vlpf_en:1;
    unsigned int    reserved_3:1;
    unsigned int    secam_flag_sel:1;
    unsigned int    reserved_4:2;
    unsigned int    secam_notch_filter:2;
}REG18019700;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    dr_offset:8;
}REG18019704;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    db_offset:8;
}REG18019708;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    secam_phase_diff_hcount_en:1;
    unsigned int    secam_phase_diff_hcount:7;
}REG1801970C;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    secam_phase_diff_dr:8;
}REG18019710;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    secam_phase_diff_db:8;
}REG18019714;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    secam_gain_drdb_en:1;
    unsigned int    secam_gain_drdb:7;
}REG18019718;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    secam_gain_y_en:1;
    unsigned int    secam_gain_y:7;
}REG1801971C;

typedef struct
{
    unsigned int    reserved_0:27;
    unsigned int    secam_gain_delay:5;
}REG18019720;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    secam_gain_debug_en:1;
    unsigned int    secam_gain_debug:7;
}REG18019724;

typedef struct
{
    unsigned int    reserved_0:28;
    unsigned int    yadap_hpf_sel:2;
    unsigned int    yadap_peak_mode:2;
}REG18019728;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    yadap_peak_gain:4;
    unsigned int    yadap_peak_th:4;
}REG1801972C;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    yadap_peak_gain_2d:4;
    unsigned int    yadap_uniform_gain:4;
}REG18019730;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    new_secam_phase_diff_hcount_en:1;
    unsigned int    new_secam_phase_diff_hcount:7;
}REG18019734;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    new_secam_phase_diff_dr:8;
}REG18019738;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    new_secam_phase_diff_db:8;
}REG1801973C;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    new_secam_cdto_inc:30;
}REG18019740;

typedef struct
{
    unsigned int    secam_gp_en:1;
    unsigned int    reserved_0:9;
    unsigned int    secam_gp_step:10;
    unsigned int    reserved_1:2;
    unsigned int    secam_gp_thl:10;
}REG18019744;

typedef struct
{
    unsigned int    vdec_ps_disp_27_en:1;
    unsigned int    hresampler_combi_delay:3;
    unsigned int    reserved_0:1;
    unsigned int    vd_output_135_sel:1;
    unsigned int    vd_output_27_repeat_sel:1;
    unsigned int    vd_output_27_repeat_en:1;
    unsigned int    reserved_1:16;
    unsigned int    v8format_sel:1;
    unsigned int    reserved_2:4;
    unsigned int    ps_updn_swap:1;
    unsigned int    reserved_3:1;
    unsigned int    fifo_initialization:1;
}REG18019758;

typedef struct
{
    unsigned int    reserved_0:7;
    unsigned int    ps_540_coe_en:1;
    unsigned int    reserved_1:3;
    unsigned int    ps_540_select_tap:5;
    unsigned int    reserved_2:1;
    unsigned int    ps_540_coe_modify:7;
    unsigned int    reserved_3:6;
    unsigned int    fifo_full_status:1;
    unsigned int    fifo_empty_status:1;
}REG1801975C;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    pll_i_gain:8;
}REG18019760;

typedef struct
{
    unsigned int    reserved_0:13;
    unsigned int    fifo_wo_ps:1;
    unsigned int    fifo_depth_wo_ps:6;
    unsigned int    reserved_1:2;
    unsigned int    swallow_freq_sel:2;
    unsigned int    swallow_on_vsync:1;
    unsigned int    ndivload_en:1;
    unsigned int    ps_up_en:1;
    unsigned int    ps_dn_en:1;
    unsigned int    pll_div:4;
}REG18019764;

typedef struct
{
    unsigned int    reserved_0:25;
    unsigned int    fifo_depth_min_clr:1;
    unsigned int    fifo_depth_min_status:6;
}REG18019768;

typedef struct
{
    unsigned int    reserved_0:25;
    unsigned int    fifo_depth_max_clr:1;
    unsigned int    fifo_depth_max_status:6;
}REG1801976C;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    ps_up_i:1;
    unsigned int    ps_dn_i:1;
    unsigned int    reserved_1:4;
    unsigned int    ps_divload:1;
    unsigned int    ps_pselload:1;
}REG18019770;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    pll_debug_en:1;
    unsigned int    ps_psel:3;
    unsigned int    ps_ndiv:4;
}REG18019774;

typedef struct
{
    unsigned int    reserved_0:11;
    unsigned int    ps_fix_en:1;
    unsigned int    ps_fix_value:8;
    unsigned int    ps_new_kikp:1;
    unsigned int    ps_new_kp:3;
    unsigned int    reserved_1:2;
    unsigned int    cnt_en:1;
    unsigned int    period_sel:2;
    unsigned int    lpf_en:1;
    unsigned int    k_sel:2;
}REG18019778;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    fifo_wo_ps_clk_jump:1;
    unsigned int    fifo_wo_ps_err_act:1;
    unsigned int    fifo_wo_ps_adapt:1;
    unsigned int    fifo_wo_ps_hlen_min:12;
    unsigned int    reserved_1:2;
    unsigned int    fifo_depth_wo_ps_min:6;
    unsigned int    reserved_2:2;
    unsigned int    fifo_depth_wo_ps_max:6;
}REG1801977C;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    fifo_wo_ps_ps_up_i1:1;
    unsigned int    fifo_wo_ps_ps_dn_i1:1;
    unsigned int    fifo_wo_ps_ps_pselload1:1;
    unsigned int    fifo_wo_ps_ps_divload1:1;
    unsigned int    fifo_wo_ps_ps_psel1:3;
    unsigned int    fifo_wo_ps_ps_ndiv1:5;
    unsigned int    fifo_wo_ps_ps_up_i0:1;
    unsigned int    fifo_wo_ps_ps_dn_i0:1;
    unsigned int    fifo_wo_ps_ps_pselload0:1;
    unsigned int    fifo_wo_ps_ps_divload0:1;
    unsigned int    fifo_wo_ps_ps_psel0:3;
    unsigned int    fifo_wo_ps_ps_ndiv0:5;
}REG18019780;

typedef struct
{
    unsigned int    reserved_0:19;
    unsigned int    fifo_clk_state:1;
    unsigned int    fifo_out_line_len:12;
}REG18019784;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    debug_test_enable:1;
    unsigned int    debug_test:7;
}REG18019788;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    muxanalogb:4;
    unsigned int    muxanaloga:4;
}REG1801978C;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    clk_dac_polarity:1;
    unsigned int    clk_sct_polarity:1;
    unsigned int    reserved_1:1;
    unsigned int    debug_test_dac_en:1;
    unsigned int    muxdigital:4;
}REG18019790;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    patgen_vline_vactive_end:10;
    unsigned int    reserved_1:2;
    unsigned int    patgen_vline:10;
    unsigned int    patgen_vline_en:1;
    unsigned int    fifo_out_pattern_gen_en:1;
    unsigned int    pattern_gen_scart_en:1;
    unsigned int    crc_chk_sel:1;
    unsigned int    reserved_2:1;
    unsigned int    pattern_gen_input_mode_sel:1;
    unsigned int    pattern_gen_cvbs_mode:1;
    unsigned int    pattern_generator_enable:1;
}REG18019794;

typedef struct
{
    unsigned int    crc_result:32;
}REG18019798;

typedef struct
{
    unsigned int    reserved_0:23;
    unsigned int    clk_vdadc_polarity:1;
    unsigned int    clk_polarity:1;
    unsigned int    patgen_sync_gain:3;
    unsigned int    reserved_1:1;
    unsigned int    patgen_burst_gain:3;
}REG1801979C;

typedef struct
{
    unsigned int    reserved_0:27;
    unsigned int    bist_mode_out:1;
    unsigned int    bist_mode_fifo:1;
    unsigned int    bist_mode_dma:1;
    unsigned int    bist_mode_27_2:1;
    unsigned int    bist_mode_27_1:1;
}REG180197A0;

typedef struct
{
    unsigned int    reserved_0:27;
    unsigned int    bist_done_out:1;
    unsigned int    bist_done_fifo:1;
    unsigned int    bist_done_dma:1;
    unsigned int    bist_done_27_2:1;
    unsigned int    bist_done_27_1:1;
}REG180197A4;

typedef struct
{
    unsigned int    reserved_0:27;
    unsigned int    bist_fail_out:1;
    unsigned int    bist_fail_fifo:1;
    unsigned int    bist_fail_dma:1;
    unsigned int    bist_fail_27_2:1;
    unsigned int    bist_fail_27_1:1;
}REG180197A8;

typedef struct
{
    unsigned int    reserved_0:27;
    unsigned int    bist_drf_mode_out:1;
    unsigned int    bist_drf_mode_fifo:1;
    unsigned int    bist_drf_mode_dma:1;
    unsigned int    bist_drf_mode_27_2:1;
    unsigned int    bist_drf_mode_27_1:1;
}REG180197AC;

typedef struct
{
    unsigned int    reserved_0:27;
    unsigned int    bist_drf_resume_out:1;
    unsigned int    bist_drf_resume_fifo:1;
    unsigned int    bist_drf_resume_dma:1;
    unsigned int    bist_drf_resume_27_2:1;
    unsigned int    bist_drf_resume_27_1:1;
}REG180197B0;

typedef struct
{
    unsigned int    reserved_0:27;
    unsigned int    bist_drf_done_out:1;
    unsigned int    bist_drf_done_fifo:1;
    unsigned int    bist_drf_done_dma:1;
    unsigned int    bist_drf_done_27_2:1;
    unsigned int    bist_drf_done_27_1:1;
}REG180197B4;

typedef struct
{
    unsigned int    reserved_0:27;
    unsigned int    bist_drf_pause_out:1;
    unsigned int    bist_drf_pause_fifo:1;
    unsigned int    bist_drf_pause_dma:1;
    unsigned int    bist_drf_pause_27_2:1;
    unsigned int    bist_drf_pause_27_1:1;
}REG180197B8;

typedef struct
{
    unsigned int    reserved_0:27;
    unsigned int    bist_drf_fail_out:1;
    unsigned int    bist_drf_fail_fifo:1;
    unsigned int    bist_drf_fail_dma:1;
    unsigned int    bist_drf_fail_27_2:1;
    unsigned int    bist_drf_fail_27_1:1;
}REG180197BC;

typedef struct
{
    unsigned int    reserved_0:28;
    unsigned int    bist_mem_fail_27_1_3_0:4;
}REG180197C0;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    bist_mem_fail_27_2_7_0:8;
}REG180197C4;

typedef struct
{
    unsigned int    reserved_0:27;
    unsigned int    bist_mem_fail_dma_4_0:5;
}REG180197C8;

typedef struct
{
    unsigned int    reserved_0:30;
    unsigned int    bist_mem_fail_fifo_1_0:2;
}REG180197CC;

typedef struct
{
    unsigned int    reserved_0:28;
    unsigned int    bist_mem_fail_out_3_0:4;
}REG180197D0;

typedef struct
{
    unsigned int    reserved_0:28;
    unsigned int    bist_drf_mem_fail_27_1_3_0:4;
}REG180197D4;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    bist_drf_mem_fail_27_2_7_0:8;
}REG180197D8;

typedef struct
{
    unsigned int    reserved_0:27;
    unsigned int    bist_drf_mem_fail_dma_4_0:5;
}REG180197DC;

typedef struct
{
    unsigned int    reserved_0:30;
    unsigned int    bist_drf_mem_fail_fifo_1_0:2;
}REG180197E0;

typedef struct
{
    unsigned int    reserved_0:28;
    unsigned int    bist_drf_mem_fail_out_3_0:4;
}REG180197E4;

typedef struct
{
    unsigned int    reserved_0:9;
    unsigned int    mbist_dvs_out:4;
    unsigned int    mbist_dvse_out:1;
    unsigned int    mbist_dvs_fifo:3;
    unsigned int    mbist_dvse_fifo:1;
    unsigned int    mbist_dvs_dma:3;
    unsigned int    mbist_dvse_dma:1;
    unsigned int    mbist_dvs_27_2:4;
    unsigned int    mbist_dvse_27_2:1;
    unsigned int    mbist_dvs_27_1:4;
    unsigned int    mbist_dvse_27_1:1;
}REG180197E8;

typedef struct
{
    unsigned int    reserved_0:29;
    unsigned int    adc_updn_debug_en:1;
    unsigned int    adc_updn_debug_up:1;
    unsigned int    adc_updn_debug_dn:1;
}REG180197FC;
#endif


#define VIDEO_CONTROL0                                                0x18019000
#define VIDEO_CONTROL0_reg_addr                                       "0xb8019000"
#define VIDEO_CONTROL0_reg                                            0xb8019000
#define VIDEO_CONTROL0_inst_addr                                      "0x0000"
#define VIDEO_CONTROL0_inst                                           0x0000
#define VIDEO_CONTROL0_hv_delay_shift                                 (7)
#define VIDEO_CONTROL0_hpixel_shift                                   (5)
#define VIDEO_CONTROL0_vline_625_shift                                (4)
#define VIDEO_CONTROL0_colour_mode_shift                              (1)
#define VIDEO_CONTROL0_hv_delay_mask                                  (0x00000080)
#define VIDEO_CONTROL0_hpixel_mask                                    (0x00000060)
#define VIDEO_CONTROL0_vline_625_mask                                 (0x00000010)
#define VIDEO_CONTROL0_colour_mode_mask                               (0x0000000E)
#define VIDEO_CONTROL0_hv_delay(data)                                 (0x00000080&((data)<<7))
#define VIDEO_CONTROL0_hpixel(data)                                   (0x00000060&((data)<<5))
#define VIDEO_CONTROL0_vline_625(data)                                (0x00000010&((data)<<4))
#define VIDEO_CONTROL0_colour_mode(data)                              (0x0000000E&((data)<<1))
#define VIDEO_CONTROL0_get_hv_delay(data)                             ((0x00000080&(data))>>7)
#define VIDEO_CONTROL0_get_hpixel(data)                               ((0x00000060&(data))>>5)
#define VIDEO_CONTROL0_get_vline_625(data)                            ((0x00000010&(data))>>4)
#define VIDEO_CONTROL0_get_colour_mode(data)                          ((0x0000000E&(data))>>1)


#define VIDEO_CONTROL1                                                0x18019004
#define VIDEO_CONTROL1_reg_addr                                       "0xb8019004"
#define VIDEO_CONTROL1_reg                                            0xb8019004
#define VIDEO_CONTROL1_inst_addr                                      "0x0001"
#define VIDEO_CONTROL1_inst                                           0x0001
#define VIDEO_CONTROL1_cv_inv_shift                                   (7)
#define VIDEO_CONTROL1_cv_src_shift                                   (6)
#define VIDEO_CONTROL1_yc_src_shift                                   (5)
#define VIDEO_CONTROL1_ped_shift                                      (0)
#define VIDEO_CONTROL1_cv_inv_mask                                    (0x00000080)
#define VIDEO_CONTROL1_cv_src_mask                                    (0x00000040)
#define VIDEO_CONTROL1_yc_src_mask                                    (0x00000020)
#define VIDEO_CONTROL1_ped_mask                                       (0x00000001)
#define VIDEO_CONTROL1_cv_inv(data)                                   (0x00000080&((data)<<7))
#define VIDEO_CONTROL1_cv_src(data)                                   (0x00000040&((data)<<6))
#define VIDEO_CONTROL1_yc_src(data)                                   (0x00000020&((data)<<5))
#define VIDEO_CONTROL1_ped(data)                                      (0x00000001&(data))
#define VIDEO_CONTROL1_get_cv_inv(data)                               ((0x00000080&(data))>>7)
#define VIDEO_CONTROL1_get_cv_src(data)                               ((0x00000040&(data))>>6)
#define VIDEO_CONTROL1_get_yc_src(data)                               ((0x00000020&(data))>>5)
#define VIDEO_CONTROL1_get_ped(data)                                  (0x00000001&(data))


#define VIDEO_STATUS_REG1                                             0x18019008
#define VIDEO_STATUS_REG1_reg_addr                                    "0xb8019008"
#define VIDEO_STATUS_REG1_reg                                         0xb8019008
#define VIDEO_STATUS_REG1_inst_addr                                   "0x0002"
#define VIDEO_STATUS_REG1_inst                                        0x0002
#define VIDEO_STATUS_REG1_chromalock_acc_shift                        (9)
#define VIDEO_STATUS_REG1_h_fine_lock_shift                           (8)
#define VIDEO_STATUS_REG1_mv_colourstripes_shift                      (5)
#define VIDEO_STATUS_REG1_mv_vbi_detected_shift                       (4)
#define VIDEO_STATUS_REG1_chomalock_shift                             (3)
#define VIDEO_STATUS_REG1_vlock_shift                                 (2)
#define VIDEO_STATUS_REG1_hlock_shift                                 (1)
#define VIDEO_STATUS_REG1_no_signal_shift                             (0)
#define VIDEO_STATUS_REG1_chromalock_acc_mask                         (0x00000200)
#define VIDEO_STATUS_REG1_h_fine_lock_mask                            (0x00000100)
#define VIDEO_STATUS_REG1_mv_colourstripes_mask                       (0x000000E0)
#define VIDEO_STATUS_REG1_mv_vbi_detected_mask                        (0x00000010)
#define VIDEO_STATUS_REG1_chomalock_mask                              (0x00000008)
#define VIDEO_STATUS_REG1_vlock_mask                                  (0x00000004)
#define VIDEO_STATUS_REG1_hlock_mask                                  (0x00000002)
#define VIDEO_STATUS_REG1_no_signal_mask                              (0x00000001)
#define VIDEO_STATUS_REG1_chromalock_acc(data)                        (0x00000200&((data)<<9))
#define VIDEO_STATUS_REG1_h_fine_lock(data)                           (0x00000100&((data)<<8))
#define VIDEO_STATUS_REG1_mv_colourstripes(data)                      (0x000000E0&((data)<<5))
#define VIDEO_STATUS_REG1_mv_vbi_detected(data)                       (0x00000010&((data)<<4))
#define VIDEO_STATUS_REG1_chomalock(data)                             (0x00000008&((data)<<3))
#define VIDEO_STATUS_REG1_vlock(data)                                 (0x00000004&((data)<<2))
#define VIDEO_STATUS_REG1_hlock(data)                                 (0x00000002&((data)<<1))
#define VIDEO_STATUS_REG1_no_signal(data)                             (0x00000001&(data))
#define VIDEO_STATUS_REG1_get_chromalock_acc(data)                    ((0x00000200&(data))>>9)
#define VIDEO_STATUS_REG1_get_h_fine_lock(data)                       ((0x00000100&(data))>>8)
#define VIDEO_STATUS_REG1_get_mv_colourstripes(data)                  ((0x000000E0&(data))>>5)
#define VIDEO_STATUS_REG1_get_mv_vbi_detected(data)                   ((0x00000010&(data))>>4)
#define VIDEO_STATUS_REG1_get_chomalock(data)                         ((0x00000008&(data))>>3)
#define VIDEO_STATUS_REG1_get_vlock(data)                             ((0x00000004&(data))>>2)
#define VIDEO_STATUS_REG1_get_hlock(data)                             ((0x00000002&(data))>>1)
#define VIDEO_STATUS_REG1_get_no_signal(data)                         (0x00000001&(data))


#define VIDEO_STATUS_REG2                                             0x1801900c
#define VIDEO_STATUS_REG2_reg_addr                                    "0xb801900c"
#define VIDEO_STATUS_REG2_reg                                         0xb801900c
#define VIDEO_STATUS_REG2_inst_addr                                   "0x0003"
#define VIDEO_STATUS_REG2_inst                                        0x0003
#define VIDEO_STATUS_REG2_v_detect_flag_shift                         (8)
#define VIDEO_STATUS_REG2_detect358_flag_shift                        (7)
#define VIDEO_STATUS_REG2_vlock_new_shift                             (6)
#define VIDEO_STATUS_REG2_noisy_vbi_shift                             (5)
#define VIDEO_STATUS_REG2_detect443_flag_shift                        (4)
#define VIDEO_STATUS_REG2_burst_detect_shift                          (3)
#define VIDEO_STATUS_REG2_palor_flag_shift                            (2)
#define VIDEO_STATUS_REG2_palm_flag_shift                             (1)
#define VIDEO_STATUS_REG2_proscan_detected_shift                      (0)
#define VIDEO_STATUS_REG2_v_detect_flag_mask                          (0x00000100)
#define VIDEO_STATUS_REG2_detect358_flag_mask                         (0x00000080)
#define VIDEO_STATUS_REG2_vlock_new_mask                              (0x00000040)
#define VIDEO_STATUS_REG2_noisy_vbi_mask                              (0x00000020)
#define VIDEO_STATUS_REG2_detect443_flag_mask                         (0x00000010)
#define VIDEO_STATUS_REG2_burst_detect_mask                           (0x00000008)
#define VIDEO_STATUS_REG2_palor_flag_mask                             (0x00000004)
#define VIDEO_STATUS_REG2_palm_flag_mask                              (0x00000002)
#define VIDEO_STATUS_REG2_proscan_detected_mask                       (0x00000001)
#define VIDEO_STATUS_REG2_v_detect_flag(data)                         (0x00000100&((data)<<8))
#define VIDEO_STATUS_REG2_detect358_flag(data)                        (0x00000080&((data)<<7))
#define VIDEO_STATUS_REG2_vlock_new(data)                             (0x00000040&((data)<<6))
#define VIDEO_STATUS_REG2_noisy_vbi(data)                             (0x00000020&((data)<<5))
#define VIDEO_STATUS_REG2_detect443_flag(data)                        (0x00000010&((data)<<4))
#define VIDEO_STATUS_REG2_burst_detect(data)                          (0x00000008&((data)<<3))
#define VIDEO_STATUS_REG2_palor_flag(data)                            (0x00000004&((data)<<2))
#define VIDEO_STATUS_REG2_palm_flag(data)                             (0x00000002&((data)<<1))
#define VIDEO_STATUS_REG2_proscan_detected(data)                      (0x00000001&(data))
#define VIDEO_STATUS_REG2_get_v_detect_flag(data)                     ((0x00000100&(data))>>8)
#define VIDEO_STATUS_REG2_get_detect358_flag(data)                    ((0x00000080&(data))>>7)
#define VIDEO_STATUS_REG2_get_vlock_new(data)                         ((0x00000040&(data))>>6)
#define VIDEO_STATUS_REG2_get_noisy_vbi(data)                         ((0x00000020&(data))>>5)
#define VIDEO_STATUS_REG2_get_detect443_flag(data)                    ((0x00000010&(data))>>4)
#define VIDEO_STATUS_REG2_get_burst_detect(data)                      ((0x00000008&(data))>>3)
#define VIDEO_STATUS_REG2_get_palor_flag(data)                        ((0x00000004&(data))>>2)
#define VIDEO_STATUS_REG2_get_palm_flag(data)                         ((0x00000002&(data))>>1)
#define VIDEO_STATUS_REG2_get_proscan_detected(data)                  (0x00000001&(data))


#define VIDEO_STATUS_REG3                                             0x18019010
#define VIDEO_STATUS_REG3_reg_addr                                    "0xb8019010"
#define VIDEO_STATUS_REG3_reg                                         0xb8019010
#define VIDEO_STATUS_REG3_inst_addr                                   "0x0004"
#define VIDEO_STATUS_REG3_inst                                        0x0004
#define VIDEO_STATUS_REG3_vcr_rew_shift                               (7)
#define VIDEO_STATUS_REG3_vcr_ff_shift                                (6)
#define VIDEO_STATUS_REG3_vcr_trick_shift                             (5)
#define VIDEO_STATUS_REG3_vcr_shift                                   (4)
#define VIDEO_STATUS_REG3_noisy_shift                                 (3)
#define VIDEO_STATUS_REG3_lines_625_detected_shift                    (2)
#define VIDEO_STATUS_REG3_secam_detected_shift                        (1)
#define VIDEO_STATUS_REG3_pal_detected_shift                          (0)
#define VIDEO_STATUS_REG3_vcr_rew_mask                                (0x00000080)
#define VIDEO_STATUS_REG3_vcr_ff_mask                                 (0x00000040)
#define VIDEO_STATUS_REG3_vcr_trick_mask                              (0x00000020)
#define VIDEO_STATUS_REG3_vcr_mask                                    (0x00000010)
#define VIDEO_STATUS_REG3_noisy_mask                                  (0x00000008)
#define VIDEO_STATUS_REG3_lines_625_detected_mask                     (0x00000004)
#define VIDEO_STATUS_REG3_secam_detected_mask                         (0x00000002)
#define VIDEO_STATUS_REG3_pal_detected_mask                           (0x00000001)
#define VIDEO_STATUS_REG3_vcr_rew(data)                               (0x00000080&((data)<<7))
#define VIDEO_STATUS_REG3_vcr_ff(data)                                (0x00000040&((data)<<6))
#define VIDEO_STATUS_REG3_vcr_trick(data)                             (0x00000020&((data)<<5))
#define VIDEO_STATUS_REG3_vcr(data)                                   (0x00000010&((data)<<4))
#define VIDEO_STATUS_REG3_noisy(data)                                 (0x00000008&((data)<<3))
#define VIDEO_STATUS_REG3_lines_625_detected(data)                    (0x00000004&((data)<<2))
#define VIDEO_STATUS_REG3_secam_detected(data)                        (0x00000002&((data)<<1))
#define VIDEO_STATUS_REG3_pal_detected(data)                          (0x00000001&(data))
#define VIDEO_STATUS_REG3_get_vcr_rew(data)                           ((0x00000080&(data))>>7)
#define VIDEO_STATUS_REG3_get_vcr_ff(data)                            ((0x00000040&(data))>>6)
#define VIDEO_STATUS_REG3_get_vcr_trick(data)                         ((0x00000020&(data))>>5)
#define VIDEO_STATUS_REG3_get_vcr(data)                               ((0x00000010&(data))>>4)
#define VIDEO_STATUS_REG3_get_noisy(data)                             ((0x00000008&(data))>>3)
#define VIDEO_STATUS_REG3_get_lines_625_detected(data)                ((0x00000004&(data))>>2)
#define VIDEO_STATUS_REG3_get_secam_detected(data)                    ((0x00000002&(data))>>1)
#define VIDEO_STATUS_REG3_get_pal_detected(data)                      (0x00000001&(data))


#define HDTO_INC_STATUS                                               0x18019014
#define HDTO_INC_STATUS_reg_addr                                      "0xb8019014"
#define HDTO_INC_STATUS_reg                                           0xb8019014
#define HDTO_INC_STATUS_inst_addr                                     "0x0005"
#define HDTO_INC_STATUS_inst                                          0x0005
#define HDTO_INC_STATUS_hdto_inc_status_shift                         (0)
#define HDTO_INC_STATUS_hdto_inc_status_mask                          (0x3FFFFFFF)
#define HDTO_INC_STATUS_hdto_inc_status(data)                         (0x3FFFFFFF&(data))
#define HDTO_INC_STATUS_get_hdto_inc_status(data)                     (0x3FFFFFFF&(data))


#define CDTO_INC_STATUS                                               0x18019018
#define CDTO_INC_STATUS_reg_addr                                      "0xb8019018"
#define CDTO_INC_STATUS_reg                                           0xb8019018
#define CDTO_INC_STATUS_inst_addr                                     "0x0006"
#define CDTO_INC_STATUS_inst                                          0x0006
#define CDTO_INC_STATUS_cdto_inc_status_shift                         (0)
#define CDTO_INC_STATUS_cdto_inc_status_mask                          (0x3FFFFFFF)
#define CDTO_INC_STATUS_cdto_inc_status(data)                         (0x3FFFFFFF&(data))
#define CDTO_INC_STATUS_get_cdto_inc_status(data)                     (0x3FFFFFFF&(data))


#define AVG_BURST_MAG_STATUS                                          0x1801901c
#define AVG_BURST_MAG_STATUS_reg_addr                                 "0xb801901c"
#define AVG_BURST_MAG_STATUS_reg                                      0xb801901c
#define AVG_BURST_MAG_STATUS_inst_addr                                "0x0007"
#define AVG_BURST_MAG_STATUS_inst                                     0x0007
#define AVG_BURST_MAG_STATUS_burst_magnitude_shift                    (0)
#define AVG_BURST_MAG_STATUS_burst_magnitude_mask                     (0x000000FF)
#define AVG_BURST_MAG_STATUS_burst_magnitude(data)                    (0x000000FF&(data))
#define AVG_BURST_MAG_STATUS_get_burst_magnitude(data)                (0x000000FF&(data))


#define AGC_DGAIN_STATUS                                              0x18019020
#define AGC_DGAIN_STATUS_reg_addr                                     "0xb8019020"
#define AGC_DGAIN_STATUS_reg                                          0xb8019020
#define AGC_DGAIN_STATUS_inst_addr                                    "0x0008"
#define AGC_DGAIN_STATUS_inst                                         0x0008
#define AGC_DGAIN_STATUS_agc_dgain_shift                              (0)
#define AGC_DGAIN_STATUS_agc_dgain_mask                               (0x00000FFF)
#define AGC_DGAIN_STATUS_agc_dgain(data)                              (0x00000FFF&(data))
#define AGC_DGAIN_STATUS_get_agc_dgain(data)                          (0x00000FFF&(data))


#define CMAG_STATUS                                                   0x18019024
#define CMAG_STATUS_reg_addr                                          "0xb8019024"
#define CMAG_STATUS_reg                                               0xb8019024
#define CMAG_STATUS_inst_addr                                         "0x0009"
#define CMAG_STATUS_inst                                              0x0009
#define CMAG_STATUS_status_cmag_shift                                 (0)
#define CMAG_STATUS_status_cmag_mask                                  (0x000000FF)
#define CMAG_STATUS_status_cmag(data)                                 (0x000000FF&(data))
#define CMAG_STATUS_get_status_cmag(data)                             (0x000000FF&(data))


#define CGAIN_STATUS                                                  0x18019028
#define CGAIN_STATUS_reg_addr                                         "0xb8019028"
#define CGAIN_STATUS_reg                                              0xb8019028
#define CGAIN_STATUS_inst_addr                                        "0x000A"
#define CGAIN_STATUS_inst                                             0x000A
#define CGAIN_STATUS_status_cgain_shift                               (0)
#define CGAIN_STATUS_status_cgain_mask                                (0x00003FFF)
#define CGAIN_STATUS_status_cgain(data)                               (0x00003FFF&(data))
#define CGAIN_STATUS_get_status_cgain(data)                           (0x00003FFF&(data))


#define CORDIC_FREQ_STATUS                                            0x1801902c
#define CORDIC_FREQ_STATUS_reg_addr                                   "0xb801902c"
#define CORDIC_FREQ_STATUS_reg                                        0xb801902c
#define CORDIC_FREQ_STATUS_inst_addr                                  "0x000B"
#define CORDIC_FREQ_STATUS_inst                                       0x000B
#define CORDIC_FREQ_STATUS_status_cordiq_freq_shift                   (0)
#define CORDIC_FREQ_STATUS_status_cordiq_freq_mask                    (0x000000FF)
#define CORDIC_FREQ_STATUS_status_cordiq_freq(data)                   (0x000000FF&(data))
#define CORDIC_FREQ_STATUS_get_status_cordiq_freq(data)               (0x000000FF&(data))


#define MEASURE_FIRST_V                                               0x18019030
#define MEASURE_FIRST_V_reg_addr                                      "0xb8019030"
#define MEASURE_FIRST_V_reg                                           0xb8019030
#define MEASURE_FIRST_V_inst_addr                                     "0x000C"
#define MEASURE_FIRST_V_inst                                          0x000C
#define MEASURE_FIRST_V_v_1st_line_shift                              (0)
#define MEASURE_FIRST_V_v_1st_line_mask                               (0x000003FF)
#define MEASURE_FIRST_V_v_1st_line(data)                              (0x000003FF&(data))
#define MEASURE_FIRST_V_get_v_1st_line(data)                          (0x000003FF&(data))


#define MEASURE_SECOND_V                                              0x18019034
#define MEASURE_SECOND_V_reg_addr                                     "0xb8019034"
#define MEASURE_SECOND_V_reg                                          0xb8019034
#define MEASURE_SECOND_V_inst_addr                                    "0x000D"
#define MEASURE_SECOND_V_inst                                         0x000D
#define MEASURE_SECOND_V_v_2nd_line_shift                             (0)
#define MEASURE_SECOND_V_v_2nd_line_mask                              (0x000003FF)
#define MEASURE_SECOND_V_v_2nd_line(data)                             (0x000003FF&(data))
#define MEASURE_SECOND_V_get_v_2nd_line(data)                         (0x000003FF&(data))


#define PORCH_HEIGHT_M                                                0x18019038
#define PORCH_HEIGHT_M_reg_addr                                       "0xb8019038"
#define PORCH_HEIGHT_M_reg                                            0xb8019038
#define PORCH_HEIGHT_M_inst_addr                                      "0x000E"
#define PORCH_HEIGHT_M_inst                                           0x000E
#define PORCH_HEIGHT_M_porch_h_shift                                  (0)
#define PORCH_HEIGHT_M_porch_h_mask                                   (0x00001FFF)
#define PORCH_HEIGHT_M_porch_h(data)                                  (0x00001FFF&(data))
#define PORCH_HEIGHT_M_get_porch_h(data)                              (0x00001FFF&(data))


#define NOISE_STATUS                                                  0x1801903c
#define NOISE_STATUS_reg_addr                                         "0xb801903c"
#define NOISE_STATUS_reg                                              0xb801903c
#define NOISE_STATUS_inst_addr                                        "0x000F"
#define NOISE_STATUS_inst                                             0x000F
#define NOISE_STATUS_status_noise_shift                               (0)
#define NOISE_STATUS_status_noise_mask                                (0x000000FF)
#define NOISE_STATUS_status_noise(data)                               (0x000000FF&(data))
#define NOISE_STATUS_get_status_noise(data)                           (0x000000FF&(data))


#define NOISE_THRESHOLD                                               0x18019040
#define NOISE_THRESHOLD_reg_addr                                      "0xb8019040"
#define NOISE_THRESHOLD_reg                                           0xb8019040
#define NOISE_THRESHOLD_inst_addr                                     "0x0010"
#define NOISE_THRESHOLD_inst                                          0x0010
#define NOISE_THRESHOLD_noise_thresh_shift                            (0)
#define NOISE_THRESHOLD_noise_thresh_mask                             (0x000000FF)
#define NOISE_THRESHOLD_noise_thresh(data)                            (0x000000FF&(data))
#define NOISE_THRESHOLD_get_noise_thresh(data)                        (0x000000FF&(data))


#define HSYNC_DTO_INC                                                 0x18019050
#define HSYNC_DTO_INC_reg_addr                                        "0xb8019050"
#define HSYNC_DTO_INC_reg                                             0xb8019050
#define HSYNC_DTO_INC_inst_addr                                       "0x0014"
#define HSYNC_DTO_INC_inst                                            0x0014
#define HSYNC_DTO_INC_hdto_fixed_shift                                (31)
#define HSYNC_DTO_INC_hdto_inc_shift                                  (0)
#define HSYNC_DTO_INC_hdto_fixed_mask                                 (0x80000000)
#define HSYNC_DTO_INC_hdto_inc_mask                                   (0x3FFFFFFF)
#define HSYNC_DTO_INC_hdto_fixed(data)                                (0x80000000&((data)<<31))
#define HSYNC_DTO_INC_hdto_inc(data)                                  (0x3FFFFFFF&(data))
#define HSYNC_DTO_INC_get_hdto_fixed(data)                            ((0x80000000&(data))>>31)
#define HSYNC_DTO_INC_get_hdto_inc(data)                              (0x3FFFFFFF&(data))


#define CHROMA_DTO_INC                                                0x18019054
#define CHROMA_DTO_INC_reg_addr                                       "0xb8019054"
#define CHROMA_DTO_INC_reg                                            0xb8019054
#define CHROMA_DTO_INC_inst_addr                                      "0x0015"
#define CHROMA_DTO_INC_inst                                           0x0015
#define CHROMA_DTO_INC_cdto_fixed_shift                               (31)
#define CHROMA_DTO_INC_cdto_inc_shift                                 (0)
#define CHROMA_DTO_INC_cdto_fixed_mask                                (0x80000000)
#define CHROMA_DTO_INC_cdto_inc_mask                                  (0x3FFFFFFF)
#define CHROMA_DTO_INC_cdto_fixed(data)                               (0x80000000&((data)<<31))
#define CHROMA_DTO_INC_cdto_inc(data)                                 (0x3FFFFFFF&(data))
#define CHROMA_DTO_INC_get_cdto_fixed(data)                           ((0x80000000&(data))>>31)
#define CHROMA_DTO_INC_get_cdto_inc(data)                             (0x3FFFFFFF&(data))


#define CHIP_VER                                                      0x18019058
#define CHIP_VER_reg_addr                                             "0xb8019058"
#define CHIP_VER_reg                                                  0xb8019058
#define CHIP_VER_inst_addr                                            "0x0016"
#define CHIP_VER_inst                                                 0x0016
#define CHIP_VER_chip_ver_shift                                       (0)
#define CHIP_VER_chip_ver_mask                                        (0x0000FFFF)
#define CHIP_VER_chip_ver(data)                                       (0x0000FFFF&(data))
#define CHIP_VER_get_chip_ver(data)                                   (0x0000FFFF&(data))


#define LUMA_CONTRAST_ADJ                                             0x18019060
#define LUMA_CONTRAST_ADJ_reg_addr                                    "0xb8019060"
#define LUMA_CONTRAST_ADJ_reg                                         0xb8019060
#define LUMA_CONTRAST_ADJ_inst_addr                                   "0x0018"
#define LUMA_CONTRAST_ADJ_inst                                        0x0018
#define LUMA_CONTRAST_ADJ_contrast_shift                              (0)
#define LUMA_CONTRAST_ADJ_contrast_mask                               (0x000000FF)
#define LUMA_CONTRAST_ADJ_contrast(data)                              (0x000000FF&(data))
#define LUMA_CONTRAST_ADJ_get_contrast(data)                          (0x000000FF&(data))


#define LUMA_BRIGHTNESS_ADJ                                           0x18019064
#define LUMA_BRIGHTNESS_ADJ_reg_addr                                  "0xb8019064"
#define LUMA_BRIGHTNESS_ADJ_reg                                       0xb8019064
#define LUMA_BRIGHTNESS_ADJ_inst_addr                                 "0x0019"
#define LUMA_BRIGHTNESS_ADJ_inst                                      0x0019
#define LUMA_BRIGHTNESS_ADJ_brightness_shift                          (0)
#define LUMA_BRIGHTNESS_ADJ_brightness_mask                           (0x000000FF)
#define LUMA_BRIGHTNESS_ADJ_brightness(data)                          (0x000000FF&(data))
#define LUMA_BRIGHTNESS_ADJ_get_brightness(data)                      (0x000000FF&(data))


#define CHROMA_SATURATION_ADJ                                         0x18019068
#define CHROMA_SATURATION_ADJ_reg_addr                                "0xb8019068"
#define CHROMA_SATURATION_ADJ_reg                                     0xb8019068
#define CHROMA_SATURATION_ADJ_inst_addr                               "0x001A"
#define CHROMA_SATURATION_ADJ_inst                                    0x001A
#define CHROMA_SATURATION_ADJ_saturation_shift                        (0)
#define CHROMA_SATURATION_ADJ_saturation_mask                         (0x000000FF)
#define CHROMA_SATURATION_ADJ_saturation(data)                        (0x000000FF&(data))
#define CHROMA_SATURATION_ADJ_get_saturation(data)                    (0x000000FF&(data))


#define CHROMA_HUE_PHASE_ADJ                                          0x1801906c
#define CHROMA_HUE_PHASE_ADJ_reg_addr                                 "0xb801906c"
#define CHROMA_HUE_PHASE_ADJ_reg                                      0xb801906c
#define CHROMA_HUE_PHASE_ADJ_inst_addr                                "0x001B"
#define CHROMA_HUE_PHASE_ADJ_inst                                     0x001B
#define CHROMA_HUE_PHASE_ADJ_hue_shift                                (0)
#define CHROMA_HUE_PHASE_ADJ_hue_mask                                 (0x000000FF)
#define CHROMA_HUE_PHASE_ADJ_hue(data)                                (0x000000FF&(data))
#define CHROMA_HUE_PHASE_ADJ_get_hue(data)                            (0x000000FF&(data))


#define BLUE_SCREEN_Y                                                 0x18019070
#define BLUE_SCREEN_Y_reg_addr                                        "0xb8019070"
#define BLUE_SCREEN_Y_reg                                             0xb8019070
#define BLUE_SCREEN_Y_inst_addr                                       "0x001C"
#define BLUE_SCREEN_Y_inst                                            0x001C
#define BLUE_SCREEN_Y_blue_screen_y_shift                             (0)
#define BLUE_SCREEN_Y_blue_screen_y_mask                              (0x000000FF)
#define BLUE_SCREEN_Y_blue_screen_y(data)                             (0x000000FF&(data))
#define BLUE_SCREEN_Y_get_blue_screen_y(data)                         (0x000000FF&(data))


#define BLUE_SCREEN_CB                                                0x18019074
#define BLUE_SCREEN_CB_reg_addr                                       "0xb8019074"
#define BLUE_SCREEN_CB_reg                                            0xb8019074
#define BLUE_SCREEN_CB_inst_addr                                      "0x001D"
#define BLUE_SCREEN_CB_inst                                           0x001D
#define BLUE_SCREEN_CB_blue_screen_cb_shift                           (0)
#define BLUE_SCREEN_CB_blue_screen_cb_mask                            (0x000000FF)
#define BLUE_SCREEN_CB_blue_screen_cb(data)                           (0x000000FF&(data))
#define BLUE_SCREEN_CB_get_blue_screen_cb(data)                       (0x000000FF&(data))


#define BLUE_SCREEN_CR                                                0x18019078
#define BLUE_SCREEN_CR_reg_addr                                       "0xb8019078"
#define BLUE_SCREEN_CR_reg                                            0xb8019078
#define BLUE_SCREEN_CR_inst_addr                                      "0x001E"
#define BLUE_SCREEN_CR_inst                                           0x001E
#define BLUE_SCREEN_CR_blue_screen_cr_shift                           (0)
#define BLUE_SCREEN_CR_blue_screen_cr_mask                            (0x000000FF)
#define BLUE_SCREEN_CR_blue_screen_cr(data)                           (0x000000FF&(data))
#define BLUE_SCREEN_CR_get_blue_screen_cr(data)                       (0x000000FF&(data))


#define OUTPUT_CONTROL                                                0x1801907c
#define OUTPUT_CONTROL_reg_addr                                       "0xb801907c"
#define OUTPUT_CONTROL_reg                                            0xb801907c
#define OUTPUT_CONTROL_inst_addr                                      "0x001F"
#define OUTPUT_CONTROL_inst                                           0x001F
#define OUTPUT_CONTROL_motion_delay_shift                             (8)
#define OUTPUT_CONTROL_snow_freerun_en_shift                          (7)
#define OUTPUT_CONTROL_cbcr_swap_shift                                (6)
#define OUTPUT_CONTROL_blue_mode_shift                                (4)
#define OUTPUT_CONTROL_yc_delay_shift                                 (0)
#define OUTPUT_CONTROL_motion_delay_mask                              (0x00000F00)
#define OUTPUT_CONTROL_snow_freerun_en_mask                           (0x00000080)
#define OUTPUT_CONTROL_cbcr_swap_mask                                 (0x00000040)
#define OUTPUT_CONTROL_blue_mode_mask                                 (0x00000030)
#define OUTPUT_CONTROL_yc_delay_mask                                  (0x0000000F)
#define OUTPUT_CONTROL_motion_delay(data)                             (0x00000F00&((data)<<8))
#define OUTPUT_CONTROL_snow_freerun_en(data)                          (0x00000080&((data)<<7))
#define OUTPUT_CONTROL_cbcr_swap(data)                                (0x00000040&((data)<<6))
#define OUTPUT_CONTROL_blue_mode(data)                                (0x00000030&((data)<<4))
#define OUTPUT_CONTROL_yc_delay(data)                                 (0x0000000F&(data))
#define OUTPUT_CONTROL_get_motion_delay(data)                         ((0x00000F00&(data))>>8)
#define OUTPUT_CONTROL_get_snow_freerun_en(data)                      ((0x00000080&(data))>>7)
#define OUTPUT_CONTROL_get_cbcr_swap(data)                            ((0x00000040&(data))>>6)
#define OUTPUT_CONTROL_get_blue_mode(data)                            ((0x00000030&(data))>>4)
#define OUTPUT_CONTROL_get_yc_delay(data)                             (0x0000000F&(data))


#define INOUT_CTRL                                                    0x18019080
#define INOUT_CTRL_reg_addr                                           "0xb8019080"
#define INOUT_CTRL_reg                                                0xb8019080
#define INOUT_CTRL_inst_addr                                          "0x0020"
#define INOUT_CTRL_inst                                               0x0020
#define INOUT_CTRL_avout_hsync_start_shift                            (20)
#define INOUT_CTRL_avout_hsync_end_shift                              (8)
#define INOUT_CTRL_fe_bypass_sel_shift                                (4)
#define INOUT_CTRL_sw_tu_cvbs_shift                                   (3)
#define INOUT_CTRL_clamp_if_up_en_shift                               (1)
#define INOUT_CTRL_clamp_if_dn_en_shift                               (0)
#define INOUT_CTRL_avout_hsync_start_mask                             (0x3FF00000)
#define INOUT_CTRL_avout_hsync_end_mask                               (0x0003FF00)
#define INOUT_CTRL_fe_bypass_sel_mask                                 (0x00000010)
#define INOUT_CTRL_sw_tu_cvbs_mask                                    (0x00000008)
#define INOUT_CTRL_clamp_if_up_en_mask                                (0x00000002)
#define INOUT_CTRL_clamp_if_dn_en_mask                                (0x00000001)
#define INOUT_CTRL_avout_hsync_start(data)                            (0x3FF00000&((data)<<20))
#define INOUT_CTRL_avout_hsync_end(data)                              (0x0003FF00&((data)<<8))
#define INOUT_CTRL_fe_bypass_sel(data)                                (0x00000010&((data)<<4))
#define INOUT_CTRL_sw_tu_cvbs(data)                                   (0x00000008&((data)<<3))
#define INOUT_CTRL_clamp_if_up_en(data)                               (0x00000002&((data)<<1))
#define INOUT_CTRL_clamp_if_dn_en(data)                               (0x00000001&(data))
#define INOUT_CTRL_get_avout_hsync_start(data)                        ((0x3FF00000&(data))>>20)
#define INOUT_CTRL_get_avout_hsync_end(data)                          ((0x0003FF00&(data))>>8)
#define INOUT_CTRL_get_fe_bypass_sel(data)                            ((0x00000010&(data))>>4)
#define INOUT_CTRL_get_sw_tu_cvbs(data)                               ((0x00000008&(data))>>3)
#define INOUT_CTRL_get_clamp_if_up_en(data)                           ((0x00000002&(data))>>1)
#define INOUT_CTRL_get_clamp_if_dn_en(data)                           (0x00000001&(data))


#define AVOUT_FIFO_STATUS                                             0x18019084
#define AVOUT_FIFO_STATUS_reg_addr                                    "0xb8019084"
#define AVOUT_FIFO_STATUS_reg                                         0xb8019084
#define AVOUT_FIFO_STATUS_inst_addr                                   "0x0021"
#define AVOUT_FIFO_STATUS_inst                                        0x0021
#define AVOUT_FIFO_STATUS_output_fifo_full_shift                      (26)
#define AVOUT_FIFO_STATUS_output_fifo_empty_shift                     (25)
#define AVOUT_FIFO_STATUS_output_delay_0_180_sw_shift                 (24)
#define AVOUT_FIFO_STATUS_avout_test_in_shift                         (12)
#define AVOUT_FIFO_STATUS_avout_mixer_sel_shift                       (5)
#define AVOUT_FIFO_STATUS_avout_fifo_status_full_shift                (1)
#define AVOUT_FIFO_STATUS_avout_fifo_status_empty_shift               (0)
#define AVOUT_FIFO_STATUS_output_fifo_full_mask                       (0x04000000)
#define AVOUT_FIFO_STATUS_output_fifo_empty_mask                      (0x02000000)
#define AVOUT_FIFO_STATUS_output_delay_0_180_sw_mask                  (0x01000000)
#define AVOUT_FIFO_STATUS_avout_test_in_mask                          (0x00FFF000)
#define AVOUT_FIFO_STATUS_avout_mixer_sel_mask                        (0x000001E0)
#define AVOUT_FIFO_STATUS_avout_fifo_status_full_mask                 (0x00000002)
#define AVOUT_FIFO_STATUS_avout_fifo_status_empty_mask                (0x00000001)
#define AVOUT_FIFO_STATUS_output_fifo_full(data)                      (0x04000000&((data)<<26))
#define AVOUT_FIFO_STATUS_output_fifo_empty(data)                     (0x02000000&((data)<<25))
#define AVOUT_FIFO_STATUS_output_delay_0_180_sw(data)                 (0x01000000&((data)<<24))
#define AVOUT_FIFO_STATUS_avout_test_in(data)                         (0x00FFF000&((data)<<12))
#define AVOUT_FIFO_STATUS_avout_mixer_sel(data)                       (0x000001E0&((data)<<5))
#define AVOUT_FIFO_STATUS_avout_fifo_status_full(data)                (0x00000002&((data)<<1))
#define AVOUT_FIFO_STATUS_avout_fifo_status_empty(data)               (0x00000001&(data))
#define AVOUT_FIFO_STATUS_get_output_fifo_full(data)                  ((0x04000000&(data))>>26)
#define AVOUT_FIFO_STATUS_get_output_fifo_empty(data)                 ((0x02000000&(data))>>25)
#define AVOUT_FIFO_STATUS_get_output_delay_0_180_sw(data)             ((0x01000000&(data))>>24)
#define AVOUT_FIFO_STATUS_get_avout_test_in(data)                     ((0x00FFF000&(data))>>12)
#define AVOUT_FIFO_STATUS_get_avout_mixer_sel(data)                   ((0x000001E0&(data))>>5)
#define AVOUT_FIFO_STATUS_get_avout_fifo_status_full(data)            ((0x00000002&(data))>>1)
#define AVOUT_FIFO_STATUS_get_avout_fifo_status_empty(data)           (0x00000001&(data))


#define AGC_PEAK_NOMINAL                                              0x18019090
#define AGC_PEAK_NOMINAL_reg_addr                                     "0xb8019090"
#define AGC_PEAK_NOMINAL_reg                                          0xb8019090
#define AGC_PEAK_NOMINAL_inst_addr                                    "0x0024"
#define AGC_PEAK_NOMINAL_inst                                         0x0024
#define AGC_PEAK_NOMINAL_peak_deb_en_shift                            (31)
#define AGC_PEAK_NOMINAL_peak_diff_sel_shift                          (28)
#define AGC_PEAK_NOMINAL_peak_data_sel_shift                          (25)
#define AGC_PEAK_NOMINAL_peak_deb_limit_shift                         (16)
#define AGC_PEAK_NOMINAL_peak_deb_thl_shift                           (8)
#define AGC_PEAK_NOMINAL_hagc_err_coring_en_shift                     (7)
#define AGC_PEAK_NOMINAL_agc_peak_nominal_shift                       (0)
#define AGC_PEAK_NOMINAL_peak_deb_en_mask                             (0x80000000)
#define AGC_PEAK_NOMINAL_peak_diff_sel_mask                           (0x30000000)
#define AGC_PEAK_NOMINAL_peak_data_sel_mask                           (0x02000000)
#define AGC_PEAK_NOMINAL_peak_deb_limit_mask                          (0x01FF0000)
#define AGC_PEAK_NOMINAL_peak_deb_thl_mask                            (0x0000FF00)
#define AGC_PEAK_NOMINAL_hagc_err_coring_en_mask                      (0x00000080)
#define AGC_PEAK_NOMINAL_agc_peak_nominal_mask                        (0x0000007F)
#define AGC_PEAK_NOMINAL_peak_deb_en(data)                            (0x80000000&((data)<<31))
#define AGC_PEAK_NOMINAL_peak_diff_sel(data)                          (0x30000000&((data)<<28))
#define AGC_PEAK_NOMINAL_peak_data_sel(data)                          (0x02000000&((data)<<25))
#define AGC_PEAK_NOMINAL_peak_deb_limit(data)                         (0x01FF0000&((data)<<16))
#define AGC_PEAK_NOMINAL_peak_deb_thl(data)                           (0x0000FF00&((data)<<8))
#define AGC_PEAK_NOMINAL_hagc_err_coring_en(data)                     (0x00000080&((data)<<7))
#define AGC_PEAK_NOMINAL_agc_peak_nominal(data)                       (0x0000007F&(data))
#define AGC_PEAK_NOMINAL_get_peak_deb_en(data)                        ((0x80000000&(data))>>31)
#define AGC_PEAK_NOMINAL_get_peak_diff_sel(data)                      ((0x30000000&(data))>>28)
#define AGC_PEAK_NOMINAL_get_peak_data_sel(data)                      ((0x02000000&(data))>>25)
#define AGC_PEAK_NOMINAL_get_peak_deb_limit(data)                     ((0x01FF0000&(data))>>16)
#define AGC_PEAK_NOMINAL_get_peak_deb_thl(data)                       ((0x0000FF00&(data))>>8)
#define AGC_PEAK_NOMINAL_get_hagc_err_coring_en(data)                 ((0x00000080&(data))>>7)
#define AGC_PEAK_NOMINAL_get_agc_peak_nominal(data)                   (0x0000007F&(data))


#define AGC_PEAK_AND_GATE_CTRL                                        0x18019094
#define AGC_PEAK_AND_GATE_CTRL_reg_addr                               "0xb8019094"
#define AGC_PEAK_AND_GATE_CTRL_reg                                    0xb8019094
#define AGC_PEAK_AND_GATE_CTRL_inst_addr                              "0x0025"
#define AGC_PEAK_AND_GATE_CTRL_inst                                   0x0025
#define AGC_PEAK_AND_GATE_CTRL_ycsep_data_decrease_en_shift           (27)
#define AGC_PEAK_AND_GATE_CTRL_ycsep_data_decrease_ratio_shift        (24)
#define AGC_PEAK_AND_GATE_CTRL_agc_peak_nominal_ycsep_shift           (12)
#define AGC_PEAK_AND_GATE_CTRL_agc_gate_kill_mode_sel_shift           (9)
#define AGC_PEAK_AND_GATE_CTRL_agc_gate_kill_w_hlock_shift            (8)
#define AGC_PEAK_AND_GATE_CTRL_agc_gate_vsync_coarse_shift            (7)
#define AGC_PEAK_AND_GATE_CTRL_agc_gate_vsync_stip_shift              (6)
#define AGC_PEAK_AND_GATE_CTRL_agc_gate_kill_mode_shift               (4)
#define AGC_PEAK_AND_GATE_CTRL_agc_peak_en_shift                      (3)
#define AGC_PEAK_AND_GATE_CTRL_agc_peak_cntl_shift                    (0)
#define AGC_PEAK_AND_GATE_CTRL_ycsep_data_decrease_en_mask            (0x08000000)
#define AGC_PEAK_AND_GATE_CTRL_ycsep_data_decrease_ratio_mask         (0x07000000)
#define AGC_PEAK_AND_GATE_CTRL_agc_peak_nominal_ycsep_mask            (0x00FFF000)
#define AGC_PEAK_AND_GATE_CTRL_agc_gate_kill_mode_sel_mask            (0x00000600)
#define AGC_PEAK_AND_GATE_CTRL_agc_gate_kill_w_hlock_mask             (0x00000100)
#define AGC_PEAK_AND_GATE_CTRL_agc_gate_vsync_coarse_mask             (0x00000080)
#define AGC_PEAK_AND_GATE_CTRL_agc_gate_vsync_stip_mask               (0x00000040)
#define AGC_PEAK_AND_GATE_CTRL_agc_gate_kill_mode_mask                (0x00000030)
#define AGC_PEAK_AND_GATE_CTRL_agc_peak_en_mask                       (0x00000008)
#define AGC_PEAK_AND_GATE_CTRL_agc_peak_cntl_mask                     (0x00000007)
#define AGC_PEAK_AND_GATE_CTRL_ycsep_data_decrease_en(data)           (0x08000000&((data)<<27))
#define AGC_PEAK_AND_GATE_CTRL_ycsep_data_decrease_ratio(data)        (0x07000000&((data)<<24))
#define AGC_PEAK_AND_GATE_CTRL_agc_peak_nominal_ycsep(data)           (0x00FFF000&((data)<<12))
#define AGC_PEAK_AND_GATE_CTRL_agc_gate_kill_mode_sel(data)           (0x00000600&((data)<<9))
#define AGC_PEAK_AND_GATE_CTRL_agc_gate_kill_w_hlock(data)            (0x00000100&((data)<<8))
#define AGC_PEAK_AND_GATE_CTRL_agc_gate_vsync_coarse(data)            (0x00000080&((data)<<7))
#define AGC_PEAK_AND_GATE_CTRL_agc_gate_vsync_stip(data)              (0x00000040&((data)<<6))
#define AGC_PEAK_AND_GATE_CTRL_agc_gate_kill_mode(data)               (0x00000030&((data)<<4))
#define AGC_PEAK_AND_GATE_CTRL_agc_peak_en(data)                      (0x00000008&((data)<<3))
#define AGC_PEAK_AND_GATE_CTRL_agc_peak_cntl(data)                    (0x00000007&(data))
#define AGC_PEAK_AND_GATE_CTRL_get_ycsep_data_decrease_en(data)       ((0x08000000&(data))>>27)
#define AGC_PEAK_AND_GATE_CTRL_get_ycsep_data_decrease_ratio(data)    ((0x07000000&(data))>>24)
#define AGC_PEAK_AND_GATE_CTRL_get_agc_peak_nominal_ycsep(data)       ((0x00FFF000&(data))>>12)
#define AGC_PEAK_AND_GATE_CTRL_get_agc_gate_kill_mode_sel(data)       ((0x00000600&(data))>>9)
#define AGC_PEAK_AND_GATE_CTRL_get_agc_gate_kill_w_hlock(data)        ((0x00000100&(data))>>8)
#define AGC_PEAK_AND_GATE_CTRL_get_agc_gate_vsync_coarse(data)        ((0x00000080&(data))>>7)
#define AGC_PEAK_AND_GATE_CTRL_get_agc_gate_vsync_stip(data)          ((0x00000040&(data))>>6)
#define AGC_PEAK_AND_GATE_CTRL_get_agc_gate_kill_mode(data)           ((0x00000030&(data))>>4)
#define AGC_PEAK_AND_GATE_CTRL_get_agc_peak_en(data)                  ((0x00000008&(data))>>3)
#define AGC_PEAK_AND_GATE_CTRL_get_agc_peak_cntl(data)                (0x00000007&(data))


#define AGC_PEAK_CTRL                                                 0x18019098
#define AGC_PEAK_CTRL_reg_addr                                        "0xb8019098"
#define AGC_PEAK_CTRL_reg                                             0xb8019098
#define AGC_PEAK_CTRL_inst_addr                                       "0x0026"
#define AGC_PEAK_CTRL_inst                                            0x0026
#define AGC_PEAK_CTRL_peak_gain_shift                                 (20)
#define AGC_PEAK_CTRL_diff_level_shift                                (8)
#define AGC_PEAK_CTRL_unlock_peakrst_en_shift                         (7)
#define AGC_PEAK_CTRL_hagc_err_coring_th_shift                        (2)
#define AGC_PEAK_CTRL_agc_peak_loop_gain_shift                        (0)
#define AGC_PEAK_CTRL_peak_gain_mask                                  (0xFFF00000)
#define AGC_PEAK_CTRL_diff_level_mask                                 (0x000FFF00)
#define AGC_PEAK_CTRL_unlock_peakrst_en_mask                          (0x00000080)
#define AGC_PEAK_CTRL_hagc_err_coring_th_mask                         (0x0000007C)
#define AGC_PEAK_CTRL_agc_peak_loop_gain_mask                         (0x00000003)
#define AGC_PEAK_CTRL_peak_gain(data)                                 (0xFFF00000&((data)<<20))
#define AGC_PEAK_CTRL_diff_level(data)                                (0x000FFF00&((data)<<8))
#define AGC_PEAK_CTRL_unlock_peakrst_en(data)                         (0x00000080&((data)<<7))
#define AGC_PEAK_CTRL_hagc_err_coring_th(data)                        (0x0000007C&((data)<<2))
#define AGC_PEAK_CTRL_agc_peak_loop_gain(data)                        (0x00000003&(data))
#define AGC_PEAK_CTRL_get_peak_gain(data)                             ((0xFFF00000&(data))>>20)
#define AGC_PEAK_CTRL_get_diff_level(data)                            ((0x000FFF00&(data))>>8)
#define AGC_PEAK_CTRL_get_unlock_peakrst_en(data)                     ((0x00000080&(data))>>7)
#define AGC_PEAK_CTRL_get_hagc_err_coring_th(data)                    ((0x0000007C&(data))>>2)
#define AGC_PEAK_CTRL_get_agc_peak_loop_gain(data)                    (0x00000003&(data))


#define VIDEO_CONTROL2                                                0x1801909c
#define VIDEO_CONTROL2_reg_addr                                       "0xb801909c"
#define VIDEO_CONTROL2_reg                                            0xb801909c
#define VIDEO_CONTROL2_inst_addr                                      "0x0027"
#define VIDEO_CONTROL2_inst                                           0x0027
#define VIDEO_CONTROL2_fix_dgain_shift                                (28)
#define VIDEO_CONTROL2_dgain_state_shift                              (20)
#define VIDEO_CONTROL2_under_gain_shift                               (8)
#define VIDEO_CONTROL2_hagc_field_mode_shift                          (7)
#define VIDEO_CONTROL2_mv_hagc_mode_shift                             (6)
#define VIDEO_CONTROL2_dc_clamp_mode_shift                            (4)
#define VIDEO_CONTROL2_bgate_raw_sel_shift                            (2)
#define VIDEO_CONTROL2_cagc_en_shift                                  (1)
#define VIDEO_CONTROL2_hagc_en_shift                                  (0)
#define VIDEO_CONTROL2_fix_dgain_mask                                 (0x10000000)
#define VIDEO_CONTROL2_dgain_state_mask                               (0x00300000)
#define VIDEO_CONTROL2_under_gain_mask                                (0x000FFF00)
#define VIDEO_CONTROL2_hagc_field_mode_mask                           (0x00000080)
#define VIDEO_CONTROL2_mv_hagc_mode_mask                              (0x00000040)
#define VIDEO_CONTROL2_dc_clamp_mode_mask                             (0x00000030)
#define VIDEO_CONTROL2_bgate_raw_sel_mask                             (0x00000004)
#define VIDEO_CONTROL2_cagc_en_mask                                   (0x00000002)
#define VIDEO_CONTROL2_hagc_en_mask                                   (0x00000001)
#define VIDEO_CONTROL2_fix_dgain(data)                                (0x10000000&((data)<<28))
#define VIDEO_CONTROL2_dgain_state(data)                              (0x00300000&((data)<<20))
#define VIDEO_CONTROL2_under_gain(data)                               (0x000FFF00&((data)<<8))
#define VIDEO_CONTROL2_hagc_field_mode(data)                          (0x00000080&((data)<<7))
#define VIDEO_CONTROL2_mv_hagc_mode(data)                             (0x00000040&((data)<<6))
#define VIDEO_CONTROL2_dc_clamp_mode(data)                            (0x00000030&((data)<<4))
#define VIDEO_CONTROL2_bgate_raw_sel(data)                            (0x00000004&((data)<<2))
#define VIDEO_CONTROL2_cagc_en(data)                                  (0x00000002&((data)<<1))
#define VIDEO_CONTROL2_hagc_en(data)                                  (0x00000001&(data))
#define VIDEO_CONTROL2_get_fix_dgain(data)                            ((0x10000000&(data))>>28)
#define VIDEO_CONTROL2_get_dgain_state(data)                          ((0x00300000&(data))>>20)
#define VIDEO_CONTROL2_get_under_gain(data)                           ((0x000FFF00&(data))>>8)
#define VIDEO_CONTROL2_get_hagc_field_mode(data)                      ((0x00000080&(data))>>7)
#define VIDEO_CONTROL2_get_mv_hagc_mode(data)                         ((0x00000040&(data))>>6)
#define VIDEO_CONTROL2_get_dc_clamp_mode(data)                        ((0x00000030&(data))>>4)
#define VIDEO_CONTROL2_get_bgate_raw_sel(data)                        ((0x00000004&(data))>>2)
#define VIDEO_CONTROL2_get_cagc_en(data)                              ((0x00000002&(data))>>1)
#define VIDEO_CONTROL2_get_hagc_en(data)                              (0x00000001&(data))


#define LUMA_AGC_VALUE                                                0x180190a0
#define LUMA_AGC_VALUE_reg_addr                                       "0xb80190a0"
#define LUMA_AGC_VALUE_reg                                            0xb80190a0
#define LUMA_AGC_VALUE_inst_addr                                      "0x0028"
#define LUMA_AGC_VALUE_inst                                           0x0028
#define LUMA_AGC_VALUE_hagc_shift                                     (0)
#define LUMA_AGC_VALUE_hagc_mask                                      (0x000000FF)
#define LUMA_AGC_VALUE_hagc(data)                                     (0x000000FF&(data))
#define LUMA_AGC_VALUE_get_hagc(data)                                 (0x000000FF&(data))


#define AGC_GATE_START                                                0x180190a4
#define AGC_GATE_START_reg_addr                                       "0xb80190a4"
#define AGC_GATE_START_reg                                            0xb80190a4
#define AGC_GATE_START_inst_addr                                      "0x0029"
#define AGC_GATE_START_inst                                           0x0029
#define AGC_GATE_START_agc_gate_start_shift                           (0)
#define AGC_GATE_START_agc_gate_start_mask                            (0x000007FF)
#define AGC_GATE_START_agc_gate_start(data)                           (0x000007FF&(data))
#define AGC_GATE_START_get_agc_gate_start(data)                       (0x000007FF&(data))


#define AGC_GATE_WIDTH                                                0x180190a8
#define AGC_GATE_WIDTH_reg_addr                                       "0xb80190a8"
#define AGC_GATE_WIDTH_reg                                            0xb80190a8
#define AGC_GATE_WIDTH_inst_addr                                      "0x002A"
#define AGC_GATE_WIDTH_inst                                           0x002A
#define AGC_GATE_WIDTH_agc_gate_width_shift                           (0)
#define AGC_GATE_WIDTH_agc_gate_width_mask                            (0x0000007F)
#define AGC_GATE_WIDTH_agc_gate_width(data)                           (0x0000007F&(data))
#define AGC_GATE_WIDTH_get_agc_gate_width(data)                       (0x0000007F&(data))


#define AGC_BP_DELAY                                                  0x180190ac
#define AGC_BP_DELAY_reg_addr                                         "0xb80190ac"
#define AGC_BP_DELAY_reg                                              0xb80190ac
#define AGC_BP_DELAY_inst_addr                                        "0x002B"
#define AGC_BP_DELAY_inst                                             0x002B
#define AGC_BP_DELAY_agc_bp_delay_shift                               (0)
#define AGC_BP_DELAY_agc_bp_delay_mask                                (0x000000FF)
#define AGC_BP_DELAY_agc_bp_delay(data)                               (0x000000FF&(data))
#define AGC_BP_DELAY_get_agc_bp_delay(data)                           (0x000000FF&(data))


#define CLAMPAGC_COMPLUMA_NEW_THRESHOLD2                              0x180190b0
#define CLAMPAGC_COMPLUMA_NEW_THRESHOLD2_reg_addr                     "0xb80190b0"
#define CLAMPAGC_COMPLUMA_NEW_THRESHOLD2_reg                          0xb80190b0
#define CLAMPAGC_COMPLUMA_NEW_THRESHOLD2_inst_addr                    "0x002C"
#define CLAMPAGC_COMPLUMA_NEW_THRESHOLD2_inst                         0x002C
#define CLAMPAGC_COMPLUMA_NEW_THRESHOLD2_clampagc_under_th2_shift     (0)
#define CLAMPAGC_COMPLUMA_NEW_THRESHOLD2_clampagc_under_th2_mask      (0x0000003F)
#define CLAMPAGC_COMPLUMA_NEW_THRESHOLD2_clampagc_under_th2(data)     (0x0000003F&(data))
#define CLAMPAGC_COMPLUMA_NEW_THRESHOLD2_get_clampagc_under_th2(data) (0x0000003F&(data))


#define CLAMPAGC_COMPLUMA_NEW_THRESHOLD1                              0x180190b4
#define CLAMPAGC_COMPLUMA_NEW_THRESHOLD1_reg_addr                     "0xb80190b4"
#define CLAMPAGC_COMPLUMA_NEW_THRESHOLD1_reg                          0xb80190b4
#define CLAMPAGC_COMPLUMA_NEW_THRESHOLD1_inst_addr                    "0x002D"
#define CLAMPAGC_COMPLUMA_NEW_THRESHOLD1_inst                         0x002D
#define CLAMPAGC_COMPLUMA_NEW_THRESHOLD1_data_path_dgain_div2_en_shift  (12)
#define CLAMPAGC_COMPLUMA_NEW_THRESHOLD1_agc_under_loop_gain_shift    (8)
#define CLAMPAGC_COMPLUMA_NEW_THRESHOLD1_under_flag_shift             (7)
#define CLAMPAGC_COMPLUMA_NEW_THRESHOLD1_clampagc_under_th1_shift     (0)
#define CLAMPAGC_COMPLUMA_NEW_THRESHOLD1_data_path_dgain_div2_en_mask (0x00001000)
#define CLAMPAGC_COMPLUMA_NEW_THRESHOLD1_agc_under_loop_gain_mask     (0x00000700)
#define CLAMPAGC_COMPLUMA_NEW_THRESHOLD1_under_flag_mask              (0x00000080)
#define CLAMPAGC_COMPLUMA_NEW_THRESHOLD1_clampagc_under_th1_mask      (0x0000000F)
#define CLAMPAGC_COMPLUMA_NEW_THRESHOLD1_data_path_dgain_div2_en(data)  (0x00001000&((data)<<12))
#define CLAMPAGC_COMPLUMA_NEW_THRESHOLD1_agc_under_loop_gain(data)    (0x00000700&((data)<<8))
#define CLAMPAGC_COMPLUMA_NEW_THRESHOLD1_under_flag(data)             (0x00000080&((data)<<7))
#define CLAMPAGC_COMPLUMA_NEW_THRESHOLD1_clampagc_under_th1(data)     (0x0000000F&(data))
#define CLAMPAGC_COMPLUMA_NEW_THRESHOLD1_get_data_path_dgain_div2_en(data)  ((0x00001000&(data))>>12)
#define CLAMPAGC_COMPLUMA_NEW_THRESHOLD1_get_agc_under_loop_gain(data)  ((0x00000700&(data))>>8)
#define CLAMPAGC_COMPLUMA_NEW_THRESHOLD1_get_under_flag(data)         ((0x00000080&(data))>>7)
#define CLAMPAGC_COMPLUMA_NEW_THRESHOLD1_get_clampagc_under_th1(data) (0x0000000F&(data))


#define CLAMPAGC_COMPLUMA_NEW_CONTROL                                 0x180190b8
#define CLAMPAGC_COMPLUMA_NEW_CONTROL_reg_addr                        "0xb80190b8"
#define CLAMPAGC_COMPLUMA_NEW_CONTROL_reg                             0xb80190b8
#define CLAMPAGC_COMPLUMA_NEW_CONTROL_inst_addr                       "0x002E"
#define CLAMPAGC_COMPLUMA_NEW_CONTROL_inst                            0x002E
#define CLAMPAGC_COMPLUMA_NEW_CONTROL_under_deb_en_shift              (31)
#define CLAMPAGC_COMPLUMA_NEW_CONTROL_under_gate_en_shift             (30)
#define CLAMPAGC_COMPLUMA_NEW_CONTROL_under_diff_sel_shift            (28)
#define CLAMPAGC_COMPLUMA_NEW_CONTROL_under_deb_limit_shift           (16)
#define CLAMPAGC_COMPLUMA_NEW_CONTROL_under_deb_thl_shift             (8)
#define CLAMPAGC_COMPLUMA_NEW_CONTROL_clampagc_under_cntl_shift       (2)
#define CLAMPAGC_COMPLUMA_NEW_CONTROL_clampagc_under_en_shift         (1)
#define CLAMPAGC_COMPLUMA_NEW_CONTROL_blank_vid_offset_shift          (0)
#define CLAMPAGC_COMPLUMA_NEW_CONTROL_under_deb_en_mask               (0x80000000)
#define CLAMPAGC_COMPLUMA_NEW_CONTROL_under_gate_en_mask              (0x40000000)
#define CLAMPAGC_COMPLUMA_NEW_CONTROL_under_diff_sel_mask             (0x30000000)
#define CLAMPAGC_COMPLUMA_NEW_CONTROL_under_deb_limit_mask            (0x01FF0000)
#define CLAMPAGC_COMPLUMA_NEW_CONTROL_under_deb_thl_mask              (0x0000FF00)
#define CLAMPAGC_COMPLUMA_NEW_CONTROL_clampagc_under_cntl_mask        (0x000000FC)
#define CLAMPAGC_COMPLUMA_NEW_CONTROL_clampagc_under_en_mask          (0x00000002)
#define CLAMPAGC_COMPLUMA_NEW_CONTROL_blank_vid_offset_mask           (0x00000001)
#define CLAMPAGC_COMPLUMA_NEW_CONTROL_under_deb_en(data)              (0x80000000&((data)<<31))
#define CLAMPAGC_COMPLUMA_NEW_CONTROL_under_gate_en(data)             (0x40000000&((data)<<30))
#define CLAMPAGC_COMPLUMA_NEW_CONTROL_under_diff_sel(data)            (0x30000000&((data)<<28))
#define CLAMPAGC_COMPLUMA_NEW_CONTROL_under_deb_limit(data)           (0x01FF0000&((data)<<16))
#define CLAMPAGC_COMPLUMA_NEW_CONTROL_under_deb_thl(data)             (0x0000FF00&((data)<<8))
#define CLAMPAGC_COMPLUMA_NEW_CONTROL_clampagc_under_cntl(data)       (0x000000FC&((data)<<2))
#define CLAMPAGC_COMPLUMA_NEW_CONTROL_clampagc_under_en(data)         (0x00000002&((data)<<1))
#define CLAMPAGC_COMPLUMA_NEW_CONTROL_blank_vid_offset(data)          (0x00000001&(data))
#define CLAMPAGC_COMPLUMA_NEW_CONTROL_get_under_deb_en(data)          ((0x80000000&(data))>>31)
#define CLAMPAGC_COMPLUMA_NEW_CONTROL_get_under_gate_en(data)         ((0x40000000&(data))>>30)
#define CLAMPAGC_COMPLUMA_NEW_CONTROL_get_under_diff_sel(data)        ((0x30000000&(data))>>28)
#define CLAMPAGC_COMPLUMA_NEW_CONTROL_get_under_deb_limit(data)       ((0x01FF0000&(data))>>16)
#define CLAMPAGC_COMPLUMA_NEW_CONTROL_get_under_deb_thl(data)         ((0x0000FF00&(data))>>8)
#define CLAMPAGC_COMPLUMA_NEW_CONTROL_get_clampagc_under_cntl(data)   ((0x000000FC&(data))>>2)
#define CLAMPAGC_COMPLUMA_NEW_CONTROL_get_clampagc_under_en(data)     ((0x00000002&(data))>>1)
#define CLAMPAGC_COMPLUMA_NEW_CONTROL_get_blank_vid_offset(data)      (0x00000001&(data))


#define VSYNC_AGC_MIN                                                 0x180190bc
#define VSYNC_AGC_MIN_reg_addr                                        "0xb80190bc"
#define VSYNC_AGC_MIN_reg                                             0xb80190bc
#define VSYNC_AGC_MIN_inst_addr                                       "0x002F"
#define VSYNC_AGC_MIN_inst                                            0x002F
#define VSYNC_AGC_MIN_under_gate_end_shift                            (20)
#define VSYNC_AGC_MIN_under_gate_st_shift                             (8)
#define VSYNC_AGC_MIN_vsync_agc_min_shift                             (0)
#define VSYNC_AGC_MIN_under_gate_end_mask                             (0x3FF00000)
#define VSYNC_AGC_MIN_under_gate_st_mask                              (0x0003FF00)
#define VSYNC_AGC_MIN_vsync_agc_min_mask                              (0x0000007F)
#define VSYNC_AGC_MIN_under_gate_end(data)                            (0x3FF00000&((data)<<20))
#define VSYNC_AGC_MIN_under_gate_st(data)                             (0x0003FF00&((data)<<8))
#define VSYNC_AGC_MIN_vsync_agc_min(data)                             (0x0000007F&(data))
#define VSYNC_AGC_MIN_get_under_gate_end(data)                        ((0x3FF00000&(data))>>20)
#define VSYNC_AGC_MIN_get_under_gate_st(data)                         ((0x0003FF00&(data))>>8)
#define VSYNC_AGC_MIN_get_vsync_agc_min(data)                         (0x0000007F&(data))


#define VSYNC_AGC_LOCKOUT_END                                         0x180190c0
#define VSYNC_AGC_LOCKOUT_END_reg_addr                                "0xb80190c0"
#define VSYNC_AGC_LOCKOUT_END_reg                                     0xb80190c0
#define VSYNC_AGC_LOCKOUT_END_inst_addr                               "0x0030"
#define VSYNC_AGC_LOCKOUT_END_inst                                    0x0030
#define VSYNC_AGC_LOCKOUT_END_vsync_clamp_mode_shift                  (6)
#define VSYNC_AGC_LOCKOUT_END_vsync_agc_max_shift                     (0)
#define VSYNC_AGC_LOCKOUT_END_vsync_clamp_mode_mask                   (0x000000C0)
#define VSYNC_AGC_LOCKOUT_END_vsync_agc_max_mask                      (0x0000003F)
#define VSYNC_AGC_LOCKOUT_END_vsync_clamp_mode(data)                  (0x000000C0&((data)<<6))
#define VSYNC_AGC_LOCKOUT_END_vsync_agc_max(data)                     (0x0000003F&(data))
#define VSYNC_AGC_LOCKOUT_END_get_vsync_clamp_mode(data)              ((0x000000C0&(data))>>6)
#define VSYNC_AGC_LOCKOUT_END_get_vsync_agc_max(data)                 (0x0000003F&(data))


#define CHARGE_PUMP_DELAY_CONTROL                                     0x180190c4
#define CHARGE_PUMP_DELAY_CONTROL_reg_addr                            "0xb80190c4"
#define CHARGE_PUMP_DELAY_CONTROL_reg                                 0xb80190c4
#define CHARGE_PUMP_DELAY_CONTROL_inst_addr                           "0x0031"
#define CHARGE_PUMP_DELAY_CONTROL_inst                                0x0031
#define CHARGE_PUMP_DELAY_CONTROL_auto_dc_restore_sel_shift           (16)
#define CHARGE_PUMP_DELAY_CONTROL_auto_dc_restore_en2_shift           (14)
#define CHARGE_PUMP_DELAY_CONTROL_auto_dc_restore_en1_shift           (13)
#define CHARGE_PUMP_DELAY_CONTROL_auto_dc_restore_en0_shift           (12)
#define CHARGE_PUMP_DELAY_CONTROL_auto_dc_restore_disable_ad4_updn_shift  (11)
#define CHARGE_PUMP_DELAY_CONTROL_auto_dc_restore_disable_ad3_updn_shift  (10)
#define CHARGE_PUMP_DELAY_CONTROL_auto_dc_restore_disable_ad2_updn_shift  (9)
#define CHARGE_PUMP_DELAY_CONTROL_auto_dc_restore_disable_ad1_updn_shift  (8)
#define CHARGE_PUMP_DELAY_CONTROL_cpump_adjust_delay_shift            (2)
#define CHARGE_PUMP_DELAY_CONTROL_cpump_adjust_polarity_shift         (1)
#define CHARGE_PUMP_DELAY_CONTROL_cpump_delay_en_shift                (0)
#define CHARGE_PUMP_DELAY_CONTROL_auto_dc_restore_sel_mask            (0x00070000)
#define CHARGE_PUMP_DELAY_CONTROL_auto_dc_restore_en2_mask            (0x00004000)
#define CHARGE_PUMP_DELAY_CONTROL_auto_dc_restore_en1_mask            (0x00002000)
#define CHARGE_PUMP_DELAY_CONTROL_auto_dc_restore_en0_mask            (0x00001000)
#define CHARGE_PUMP_DELAY_CONTROL_auto_dc_restore_disable_ad4_updn_mask  (0x00000800)
#define CHARGE_PUMP_DELAY_CONTROL_auto_dc_restore_disable_ad3_updn_mask  (0x00000400)
#define CHARGE_PUMP_DELAY_CONTROL_auto_dc_restore_disable_ad2_updn_mask  (0x00000200)
#define CHARGE_PUMP_DELAY_CONTROL_auto_dc_restore_disable_ad1_updn_mask  (0x00000100)
#define CHARGE_PUMP_DELAY_CONTROL_cpump_adjust_delay_mask             (0x000000FC)
#define CHARGE_PUMP_DELAY_CONTROL_cpump_adjust_polarity_mask          (0x00000002)
#define CHARGE_PUMP_DELAY_CONTROL_cpump_delay_en_mask                 (0x00000001)
#define CHARGE_PUMP_DELAY_CONTROL_auto_dc_restore_sel(data)           (0x00070000&((data)<<16))
#define CHARGE_PUMP_DELAY_CONTROL_auto_dc_restore_en2(data)           (0x00004000&((data)<<14))
#define CHARGE_PUMP_DELAY_CONTROL_auto_dc_restore_en1(data)           (0x00002000&((data)<<13))
#define CHARGE_PUMP_DELAY_CONTROL_auto_dc_restore_en0(data)           (0x00001000&((data)<<12))
#define CHARGE_PUMP_DELAY_CONTROL_auto_dc_restore_disable_ad4_updn(data)  (0x00000800&((data)<<11))
#define CHARGE_PUMP_DELAY_CONTROL_auto_dc_restore_disable_ad3_updn(data)  (0x00000400&((data)<<10))
#define CHARGE_PUMP_DELAY_CONTROL_auto_dc_restore_disable_ad2_updn(data)  (0x00000200&((data)<<9))
#define CHARGE_PUMP_DELAY_CONTROL_auto_dc_restore_disable_ad1_updn(data)  (0x00000100&((data)<<8))
#define CHARGE_PUMP_DELAY_CONTROL_cpump_adjust_delay(data)            (0x000000FC&((data)<<2))
#define CHARGE_PUMP_DELAY_CONTROL_cpump_adjust_polarity(data)         (0x00000002&((data)<<1))
#define CHARGE_PUMP_DELAY_CONTROL_cpump_delay_en(data)                (0x00000001&(data))
#define CHARGE_PUMP_DELAY_CONTROL_get_auto_dc_restore_sel(data)       ((0x00070000&(data))>>16)
#define CHARGE_PUMP_DELAY_CONTROL_get_auto_dc_restore_en2(data)       ((0x00004000&(data))>>14)
#define CHARGE_PUMP_DELAY_CONTROL_get_auto_dc_restore_en1(data)       ((0x00002000&(data))>>13)
#define CHARGE_PUMP_DELAY_CONTROL_get_auto_dc_restore_en0(data)       ((0x00001000&(data))>>12)
#define CHARGE_PUMP_DELAY_CONTROL_get_auto_dc_restore_disable_ad4_updn(data)  ((0x00000800&(data))>>11)
#define CHARGE_PUMP_DELAY_CONTROL_get_auto_dc_restore_disable_ad3_updn(data)  ((0x00000400&(data))>>10)
#define CHARGE_PUMP_DELAY_CONTROL_get_auto_dc_restore_disable_ad2_updn(data)  ((0x00000200&(data))>>9)
#define CHARGE_PUMP_DELAY_CONTROL_get_auto_dc_restore_disable_ad1_updn(data)  ((0x00000100&(data))>>8)
#define CHARGE_PUMP_DELAY_CONTROL_get_cpump_adjust_delay(data)        ((0x000000FC&(data))>>2)
#define CHARGE_PUMP_DELAY_CONTROL_get_cpump_adjust_polarity(data)     ((0x00000002&(data))>>1)
#define CHARGE_PUMP_DELAY_CONTROL_get_cpump_delay_en(data)            (0x00000001&(data))


#define CHARGE_PUMP_ADJUSTMENT                                        0x180190c8
#define CHARGE_PUMP_ADJUSTMENT_reg_addr                               "0xb80190c8"
#define CHARGE_PUMP_ADJUSTMENT_reg                                    0xb80190c8
#define CHARGE_PUMP_ADJUSTMENT_inst_addr                              "0x0032"
#define CHARGE_PUMP_ADJUSTMENT_inst                                   0x0032
#define CHARGE_PUMP_ADJUSTMENT_cpump_adjust_shift                     (0)
#define CHARGE_PUMP_ADJUSTMENT_cpump_adjust_mask                      (0x000000FF)
#define CHARGE_PUMP_ADJUSTMENT_cpump_adjust(data)                     (0x000000FF&(data))
#define CHARGE_PUMP_ADJUSTMENT_get_cpump_adjust(data)                 (0x000000FF&(data))


#define CHARGE_PUMP_DELAY                                             0x180190cc
#define CHARGE_PUMP_DELAY_reg_addr                                    "0xb80190cc"
#define CHARGE_PUMP_DELAY_reg                                         0xb80190cc
#define CHARGE_PUMP_DELAY_inst_addr                                   "0x0033"
#define CHARGE_PUMP_DELAY_inst                                        0x0033
#define CHARGE_PUMP_DELAY_cpump_delay_shift                           (0)
#define CHARGE_PUMP_DELAY_cpump_delay_mask                            (0x000000FF)
#define CHARGE_PUMP_DELAY_cpump_delay(data)                           (0x000000FF&(data))
#define CHARGE_PUMP_DELAY_get_cpump_delay(data)                       (0x000000FF&(data))


#define AGC_GATE_TH_SWAP                                              0x180190d0
#define AGC_GATE_TH_SWAP_reg_addr                                     "0xb80190d0"
#define AGC_GATE_TH_SWAP_reg                                          0xb80190d0
#define AGC_GATE_TH_SWAP_inst_addr                                    "0x0034"
#define AGC_GATE_TH_SWAP_inst                                         0x0034
#define AGC_GATE_TH_SWAP_adc_updn_swap_shift                          (7)
#define AGC_GATE_TH_SWAP_adc_input_swap_shift                         (6)
#define AGC_GATE_TH_SWAP_adc_cbcr_pump_swap_shift                     (5)
#define AGC_GATE_TH_SWAP_agc_gate_thresh_shift                        (0)
#define AGC_GATE_TH_SWAP_adc_updn_swap_mask                           (0x00000080)
#define AGC_GATE_TH_SWAP_adc_input_swap_mask                          (0x00000040)
#define AGC_GATE_TH_SWAP_adc_cbcr_pump_swap_mask                      (0x00000020)
#define AGC_GATE_TH_SWAP_agc_gate_thresh_mask                         (0x0000001F)
#define AGC_GATE_TH_SWAP_adc_updn_swap(data)                          (0x00000080&((data)<<7))
#define AGC_GATE_TH_SWAP_adc_input_swap(data)                         (0x00000040&((data)<<6))
#define AGC_GATE_TH_SWAP_adc_cbcr_pump_swap(data)                     (0x00000020&((data)<<5))
#define AGC_GATE_TH_SWAP_agc_gate_thresh(data)                        (0x0000001F&(data))
#define AGC_GATE_TH_SWAP_get_adc_updn_swap(data)                      ((0x00000080&(data))>>7)
#define AGC_GATE_TH_SWAP_get_adc_input_swap(data)                     ((0x00000040&(data))>>6)
#define AGC_GATE_TH_SWAP_get_adc_cbcr_pump_swap(data)                 ((0x00000020&(data))>>5)
#define AGC_GATE_TH_SWAP_get_agc_gate_thresh(data)                    (0x0000001F&(data))


#define NEW_CLAMPAGC_CTRL                                             0x180190d4
#define NEW_CLAMPAGC_CTRL_reg_addr                                    "0xb80190d4"
#define NEW_CLAMPAGC_CTRL_reg                                         0xb80190d4
#define NEW_CLAMPAGC_CTRL_inst_addr                                   "0x0035"
#define NEW_CLAMPAGC_CTRL_inst                                        0x0035
#define NEW_CLAMPAGC_CTRL_measure_dc_128_64_sel_shift                 (7)
#define NEW_CLAMPAGC_CTRL_dgain_ignore_fine_lock_shift                (6)
#define NEW_CLAMPAGC_CTRL_measure_dc_rough_shift                      (5)
#define NEW_CLAMPAGC_CTRL_new_clamp_rc_rate_en_shift                  (4)
#define NEW_CLAMPAGC_CTRL_clampagc_rc_rate_3_0_shift                  (0)
#define NEW_CLAMPAGC_CTRL_measure_dc_128_64_sel_mask                  (0x00000080)
#define NEW_CLAMPAGC_CTRL_dgain_ignore_fine_lock_mask                 (0x00000040)
#define NEW_CLAMPAGC_CTRL_measure_dc_rough_mask                       (0x00000020)
#define NEW_CLAMPAGC_CTRL_new_clamp_rc_rate_en_mask                   (0x00000010)
#define NEW_CLAMPAGC_CTRL_clampagc_rc_rate_3_0_mask                   (0x0000000F)
#define NEW_CLAMPAGC_CTRL_measure_dc_128_64_sel(data)                 (0x00000080&((data)<<7))
#define NEW_CLAMPAGC_CTRL_dgain_ignore_fine_lock(data)                (0x00000040&((data)<<6))
#define NEW_CLAMPAGC_CTRL_measure_dc_rough(data)                      (0x00000020&((data)<<5))
#define NEW_CLAMPAGC_CTRL_new_clamp_rc_rate_en(data)                  (0x00000010&((data)<<4))
#define NEW_CLAMPAGC_CTRL_clampagc_rc_rate_3_0(data)                  (0x0000000F&(data))
#define NEW_CLAMPAGC_CTRL_get_measure_dc_128_64_sel(data)             ((0x00000080&(data))>>7)
#define NEW_CLAMPAGC_CTRL_get_dgain_ignore_fine_lock(data)            ((0x00000040&(data))>>6)
#define NEW_CLAMPAGC_CTRL_get_measure_dc_rough(data)                  ((0x00000020&(data))>>5)
#define NEW_CLAMPAGC_CTRL_get_new_clamp_rc_rate_en(data)              ((0x00000010&(data))>>4)
#define NEW_CLAMPAGC_CTRL_get_clampagc_rc_rate_3_0(data)              (0x0000000F&(data))


#define MEASURE_DC_ROUGH_DN                                           0x180190d8
#define MEASURE_DC_ROUGH_DN_reg_addr                                  "0xb80190d8"
#define MEASURE_DC_ROUGH_DN_reg                                       0xb80190d8
#define MEASURE_DC_ROUGH_DN_inst_addr                                 "0x0036"
#define MEASURE_DC_ROUGH_DN_inst                                      0x0036
#define MEASURE_DC_ROUGH_DN_measure_dc_rough_dn_shift                 (0)
#define MEASURE_DC_ROUGH_DN_measure_dc_rough_dn_mask                  (0x000000FF)
#define MEASURE_DC_ROUGH_DN_measure_dc_rough_dn(data)                 (0x000000FF&(data))
#define MEASURE_DC_ROUGH_DN_get_measure_dc_rough_dn(data)             (0x000000FF&(data))


#define MEASURE_DC_ROUGH_UP                                           0x180190dc
#define MEASURE_DC_ROUGH_UP_reg_addr                                  "0xb80190dc"
#define MEASURE_DC_ROUGH_UP_reg                                       0xb80190dc
#define MEASURE_DC_ROUGH_UP_inst_addr                                 "0x0037"
#define MEASURE_DC_ROUGH_UP_inst                                      0x0037
#define MEASURE_DC_ROUGH_UP_measure_dc_rough_up_shift                 (0)
#define MEASURE_DC_ROUGH_UP_measure_dc_rough_up_mask                  (0x000000FF)
#define MEASURE_DC_ROUGH_UP_measure_dc_rough_up(data)                 (0x000000FF&(data))
#define MEASURE_DC_ROUGH_UP_get_measure_dc_rough_up(data)             (0x000000FF&(data))


#define MEASURE_DC_TH_DN                                              0x180190e0
#define MEASURE_DC_TH_DN_reg_addr                                     "0xb80190e0"
#define MEASURE_DC_TH_DN_reg                                          0xb80190e0
#define MEASURE_DC_TH_DN_inst_addr                                    "0x0038"
#define MEASURE_DC_TH_DN_inst                                         0x0038
#define MEASURE_DC_TH_DN_measure_dc_th_dn_shift                       (0)
#define MEASURE_DC_TH_DN_measure_dc_th_dn_mask                        (0x00000FFF)
#define MEASURE_DC_TH_DN_measure_dc_th_dn(data)                       (0x00000FFF&(data))
#define MEASURE_DC_TH_DN_get_measure_dc_th_dn(data)                   (0x00000FFF&(data))


#define MEASURE_DC_TH_UP                                              0x180190e4
#define MEASURE_DC_TH_UP_reg_addr                                     "0xb80190e4"
#define MEASURE_DC_TH_UP_reg                                          0xb80190e4
#define MEASURE_DC_TH_UP_inst_addr                                    "0x0039"
#define MEASURE_DC_TH_UP_inst                                         0x0039
#define MEASURE_DC_TH_UP_measure_dc_th_up_shift                       (0)
#define MEASURE_DC_TH_UP_measure_dc_th_up_mask                        (0x00000FFF)
#define MEASURE_DC_TH_UP_measure_dc_th_up(data)                       (0x00000FFF&(data))
#define MEASURE_DC_TH_UP_get_measure_dc_th_up(data)                   (0x00000FFF&(data))


#define VSAG_CNTL_1                                                   0x180190e8
#define VSAG_CNTL_1_reg_addr                                          "0xb80190e8"
#define VSAG_CNTL_1_reg                                               0xb80190e8
#define VSAG_CNTL_1_inst_addr                                         "0x003A"
#define VSAG_CNTL_1_inst                                              0x003A
#define VSAG_CNTL_1_vsag_rc_input_shift                               (7)
#define VSAG_CNTL_1_vsag_agc_peak_cntl_shift                          (0)
#define VSAG_CNTL_1_vsag_rc_input_mask                                (0x00000080)
#define VSAG_CNTL_1_vsag_agc_peak_cntl_mask                           (0x0000003F)
#define VSAG_CNTL_1_vsag_rc_input(data)                               (0x00000080&((data)<<7))
#define VSAG_CNTL_1_vsag_agc_peak_cntl(data)                          (0x0000003F&(data))
#define VSAG_CNTL_1_get_vsag_rc_input(data)                           ((0x00000080&(data))>>7)
#define VSAG_CNTL_1_get_vsag_agc_peak_cntl(data)                      (0x0000003F&(data))


#define PEAK_VSAG                                                     0x180190ec
#define PEAK_VSAG_reg_addr                                            "0xb80190ec"
#define PEAK_VSAG_reg                                                 0xb80190ec
#define PEAK_VSAG_inst_addr                                           "0x003B"
#define PEAK_VSAG_inst                                                0x003B
#define PEAK_VSAG_peak_vsag_shift                                     (0)
#define PEAK_VSAG_peak_vsag_mask                                      (0x00001FFF)
#define PEAK_VSAG_peak_vsag(data)                                     (0x00001FFF&(data))
#define PEAK_VSAG_get_peak_vsag(data)                                 (0x00001FFF&(data))


#define KILL_FIELD                                                    0x180190f0
#define KILL_FIELD_reg_addr                                           "0xb80190f0"
#define KILL_FIELD_reg                                                0xb80190f0
#define KILL_FIELD_inst_addr                                          "0x003C"
#define KILL_FIELD_inst                                               0x003C
#define KILL_FIELD_new_total_under_en_shift                           (6)
#define KILL_FIELD_new_under_gain_en_shift                            (5)
#define KILL_FIELD_new_under_th2_en_shift                             (4)
#define KILL_FIELD_lose_sgate_flag_shift                              (2)
#define KILL_FIELD_lose_bgate_flag_shift                              (1)
#define KILL_FIELD_field_kill_rst_shift                               (0)
#define KILL_FIELD_new_total_under_en_mask                            (0x00000040)
#define KILL_FIELD_new_under_gain_en_mask                             (0x00000020)
#define KILL_FIELD_new_under_th2_en_mask                              (0x00000010)
#define KILL_FIELD_lose_sgate_flag_mask                               (0x00000004)
#define KILL_FIELD_lose_bgate_flag_mask                               (0x00000002)
#define KILL_FIELD_field_kill_rst_mask                                (0x00000001)
#define KILL_FIELD_new_total_under_en(data)                           (0x00000040&((data)<<6))
#define KILL_FIELD_new_under_gain_en(data)                            (0x00000020&((data)<<5))
#define KILL_FIELD_new_under_th2_en(data)                             (0x00000010&((data)<<4))
#define KILL_FIELD_lose_sgate_flag(data)                              (0x00000004&((data)<<2))
#define KILL_FIELD_lose_bgate_flag(data)                              (0x00000002&((data)<<1))
#define KILL_FIELD_field_kill_rst(data)                               (0x00000001&(data))
#define KILL_FIELD_get_new_total_under_en(data)                       ((0x00000040&(data))>>6)
#define KILL_FIELD_get_new_under_gain_en(data)                        ((0x00000020&(data))>>5)
#define KILL_FIELD_get_new_under_th2_en(data)                         ((0x00000010&(data))>>4)
#define KILL_FIELD_get_lose_sgate_flag(data)                          ((0x00000004&(data))>>2)
#define KILL_FIELD_get_lose_bgate_flag(data)                          ((0x00000002&(data))>>1)
#define KILL_FIELD_get_field_kill_rst(data)                           (0x00000001&(data))


#define FIELD_KILL_MUN                                                0x180190f4
#define FIELD_KILL_MUN_reg_addr                                       "0xb80190f4"
#define FIELD_KILL_MUN_reg                                            0xb80190f4
#define FIELD_KILL_MUN_inst_addr                                      "0x003D"
#define FIELD_KILL_MUN_inst                                           0x003D
#define FIELD_KILL_MUN_field_kill_num_shift                           (0)
#define FIELD_KILL_MUN_field_kill_num_mask                            (0x000003FF)
#define FIELD_KILL_MUN_field_kill_num(data)                           (0x000003FF&(data))
#define FIELD_KILL_MUN_get_field_kill_num(data)                       (0x000003FF&(data))


#define KILL_GATE_UP                                                  0x180190f8
#define KILL_GATE_UP_reg_addr                                         "0xb80190f8"
#define KILL_GATE_UP_reg                                              0xb80190f8
#define KILL_GATE_UP_inst_addr                                        "0x003E"
#define KILL_GATE_UP_inst                                             0x003E
#define KILL_GATE_UP_kill_gate_up_shift                               (0)
#define KILL_GATE_UP_kill_gate_up_mask                                (0x000007FF)
#define KILL_GATE_UP_kill_gate_up(data)                               (0x000007FF&(data))
#define KILL_GATE_UP_get_kill_gate_up(data)                           (0x000007FF&(data))


#define KILL_GATE_DN                                                  0x180190fc
#define KILL_GATE_DN_reg_addr                                         "0xb80190fc"
#define KILL_GATE_DN_reg                                              0xb80190fc
#define KILL_GATE_DN_inst_addr                                        "0x003F"
#define KILL_GATE_DN_inst                                             0x003F
#define KILL_GATE_DN_kill_gate_dn_shift                               (0)
#define KILL_GATE_DN_kill_gate_dn_mask                                (0x000007FF)
#define KILL_GATE_DN_kill_gate_dn(data)                               (0x000007FF&(data))
#define KILL_GATE_DN_get_kill_gate_dn(data)                           (0x000007FF&(data))


#define SYNCMIDPT                                                     0x18019100
#define SYNCMIDPT_reg_addr                                            "0xb8019100"
#define SYNCMIDPT_reg                                                 0xb8019100
#define SYNCMIDPT_inst_addr                                           "0x0040"
#define SYNCMIDPT_inst                                                0x0040
#define SYNCMIDPT_syncmidpt_add_level_h_shift                         (4)
#define SYNCMIDPT_sync_midpt_lowest_en_shift                          (1)
#define SYNCMIDPT_syncmidpt_add_level_h_mask                          (0x00000030)
#define SYNCMIDPT_sync_midpt_lowest_en_mask                           (0x00000002)
#define SYNCMIDPT_syncmidpt_add_level_h(data)                         (0x00000030&((data)<<4))
#define SYNCMIDPT_sync_midpt_lowest_en(data)                          (0x00000002&((data)<<1))
#define SYNCMIDPT_get_syncmidpt_add_level_h(data)                     ((0x00000030&(data))>>4)
#define SYNCMIDPT_get_sync_midpt_lowest_en(data)                      ((0x00000002&(data))>>1)


#define SYNCMIDPT_FIX_ADD_VALUE                                       0x18019104
#define SYNCMIDPT_FIX_ADD_VALUE_reg_addr                              "0xb8019104"
#define SYNCMIDPT_FIX_ADD_VALUE_reg                                   0xb8019104
#define SYNCMIDPT_FIX_ADD_VALUE_inst_addr                             "0x0041"
#define SYNCMIDPT_FIX_ADD_VALUE_inst                                  0x0041
#define SYNCMIDPT_FIX_ADD_VALUE_syncmidpt_fix_add_value_h_shift       (0)
#define SYNCMIDPT_FIX_ADD_VALUE_syncmidpt_fix_add_value_h_mask        (0x000000FF)
#define SYNCMIDPT_FIX_ADD_VALUE_syncmidpt_fix_add_value_h(data)       (0x000000FF&(data))
#define SYNCMIDPT_FIX_ADD_VALUE_get_syncmidpt_fix_add_value_h(data)   (0x000000FF&(data))


#define LPFSYNC                                                       0x18019108
#define LPFSYNC_reg_addr                                              "0xb8019108"
#define LPFSYNC_reg                                                   0xb8019108
#define LPFSYNC_inst_addr                                             "0x0042"
#define LPFSYNC_inst                                                  0x0042
#define LPFSYNC_lpfsync_plus_w_hlock_shift                            (8)
#define LPFSYNC_lpfsync_plus_rm_shift                                 (7)
#define LPFSYNC_lpfsync_plus_diff_shift                               (0)
#define LPFSYNC_lpfsync_plus_w_hlock_mask                             (0x00000300)
#define LPFSYNC_lpfsync_plus_rm_mask                                  (0x00000080)
#define LPFSYNC_lpfsync_plus_diff_mask                                (0x0000003F)
#define LPFSYNC_lpfsync_plus_w_hlock(data)                            (0x00000300&((data)<<8))
#define LPFSYNC_lpfsync_plus_rm(data)                                 (0x00000080&((data)<<7))
#define LPFSYNC_lpfsync_plus_diff(data)                               (0x0000003F&(data))
#define LPFSYNC_get_lpfsync_plus_w_hlock(data)                        ((0x00000300&(data))>>8)
#define LPFSYNC_get_lpfsync_plus_rm(data)                             ((0x00000080&(data))>>7)
#define LPFSYNC_get_lpfsync_plus_diff(data)                           (0x0000003F&(data))


#define SPIKE_MIN                                                     0x1801910c
#define SPIKE_MIN_reg_addr                                            "0xb801910c"
#define SPIKE_MIN_reg                                                 0xb801910c
#define SPIKE_MIN_inst_addr                                           "0x0043"
#define SPIKE_MIN_inst                                                0x0043
#define SPIKE_MIN_spike_min_thresh_shift                              (0)
#define SPIKE_MIN_spike_min_thresh_mask                               (0x000000FF)
#define SPIKE_MIN_spike_min_thresh(data)                              (0x000000FF&(data))
#define SPIKE_MIN_get_spike_min_thresh(data)                          (0x000000FF&(data))


#define SPIKE_MAX                                                     0x18019110
#define SPIKE_MAX_reg_addr                                            "0xb8019110"
#define SPIKE_MAX_reg                                                 0xb8019110
#define SPIKE_MAX_inst_addr                                           "0x0044"
#define SPIKE_MAX_inst                                                0x0044
#define SPIKE_MAX_spike_max_thresh_shift                              (0)
#define SPIKE_MAX_spike_max_thresh_mask                               (0x000000FF)
#define SPIKE_MAX_spike_max_thresh(data)                              (0x000000FF&(data))
#define SPIKE_MAX_get_spike_max_thresh(data)                          (0x000000FF&(data))


#define SPIKE_DETECTED_UP                                             0x18019114
#define SPIKE_DETECTED_UP_reg_addr                                    "0xb8019114"
#define SPIKE_DETECTED_UP_reg                                         0xb8019114
#define SPIKE_DETECTED_UP_inst_addr                                   "0x0045"
#define SPIKE_DETECTED_UP_inst                                        0x0045
#define SPIKE_DETECTED_UP_spike_detected_shift                        (10)
#define SPIKE_DETECTED_UP_spike_detected_up_shift                     (0)
#define SPIKE_DETECTED_UP_spike_detected_mask                         (0x00000400)
#define SPIKE_DETECTED_UP_spike_detected_up_mask                      (0x000003FF)
#define SPIKE_DETECTED_UP_spike_detected(data)                        (0x00000400&((data)<<10))
#define SPIKE_DETECTED_UP_spike_detected_up(data)                     (0x000003FF&(data))
#define SPIKE_DETECTED_UP_get_spike_detected(data)                    ((0x00000400&(data))>>10)
#define SPIKE_DETECTED_UP_get_spike_detected_up(data)                 (0x000003FF&(data))


#define SPIKE_DETECTED_DN                                             0x18019118
#define SPIKE_DETECTED_DN_reg_addr                                    "0xb8019118"
#define SPIKE_DETECTED_DN_reg                                         0xb8019118
#define SPIKE_DETECTED_DN_inst_addr                                   "0x0046"
#define SPIKE_DETECTED_DN_inst                                        0x0046
#define SPIKE_DETECTED_DN_spike_detected_dn_shift                     (0)
#define SPIKE_DETECTED_DN_spike_detected_dn_mask                      (0x000003FF)
#define SPIKE_DETECTED_DN_spike_detected_dn(data)                     (0x000003FF&(data))
#define SPIKE_DETECTED_DN_get_spike_detected_dn(data)                 (0x000003FF&(data))


#define LPFSYNC_PLUS_DC                                               0x1801911c
#define LPFSYNC_PLUS_DC_reg_addr                                      "0xb801911c"
#define LPFSYNC_PLUS_DC_reg                                           0xb801911c
#define LPFSYNC_PLUS_DC_inst_addr                                     "0x0047"
#define LPFSYNC_PLUS_DC_inst                                          0x0047
#define LPFSYNC_PLUS_DC_lpfsync_plus_dc_shift                         (0)
#define LPFSYNC_PLUS_DC_lpfsync_plus_dc_mask                          (0x000000FF)
#define LPFSYNC_PLUS_DC_lpfsync_plus_dc(data)                         (0x000000FF&(data))
#define LPFSYNC_PLUS_DC_get_lpfsync_plus_dc(data)                     (0x000000FF&(data))


#define HDETECT_ERR_VAR_CTRL                                          0x18019128
#define HDETECT_ERR_VAR_CTRL_reg_addr                                 "0xb8019128"
#define HDETECT_ERR_VAR_CTRL_reg                                      0xb8019128
#define HDETECT_ERR_VAR_CTRL_inst_addr                                "0x004A"
#define HDETECT_ERR_VAR_CTRL_inst                                     0x004A
#define HDETECT_ERR_VAR_CTRL_hdetect_error_avg_interval_shift         (8)
#define HDETECT_ERR_VAR_CTRL_hdetect_error_avg_length_shift           (4)
#define HDETECT_ERR_VAR_CTRL_hdetect_error_avg_sel_shift              (0)
#define HDETECT_ERR_VAR_CTRL_hdetect_error_avg_interval_mask          (0x00000300)
#define HDETECT_ERR_VAR_CTRL_hdetect_error_avg_length_mask            (0x00000070)
#define HDETECT_ERR_VAR_CTRL_hdetect_error_avg_sel_mask               (0x00000001)
#define HDETECT_ERR_VAR_CTRL_hdetect_error_avg_interval(data)         (0x00000300&((data)<<8))
#define HDETECT_ERR_VAR_CTRL_hdetect_error_avg_length(data)           (0x00000070&((data)<<4))
#define HDETECT_ERR_VAR_CTRL_hdetect_error_avg_sel(data)              (0x00000001&(data))
#define HDETECT_ERR_VAR_CTRL_get_hdetect_error_avg_interval(data)     ((0x00000300&(data))>>8)
#define HDETECT_ERR_VAR_CTRL_get_hdetect_error_avg_length(data)       ((0x00000070&(data))>>4)
#define HDETECT_ERR_VAR_CTRL_get_hdetect_error_avg_sel(data)          (0x00000001&(data))


#define HDETECT_ERR_VAR_STATUS                                        0x1801912c
#define HDETECT_ERR_VAR_STATUS_reg_addr                               "0xb801912c"
#define HDETECT_ERR_VAR_STATUS_reg                                    0xb801912c
#define HDETECT_ERR_VAR_STATUS_inst_addr                              "0x004B"
#define HDETECT_ERR_VAR_STATUS_inst                                   0x004B
#define HDETECT_ERR_VAR_STATUS_hdetect_error_var_shift                (16)
#define HDETECT_ERR_VAR_STATUS_hdetect_error_mean_shift               (0)
#define HDETECT_ERR_VAR_STATUS_hdetect_error_var_mask                 (0xFFFF0000)
#define HDETECT_ERR_VAR_STATUS_hdetect_error_mean_mask                (0x0000FFFF)
#define HDETECT_ERR_VAR_STATUS_hdetect_error_var(data)                (0xFFFF0000&((data)<<16))
#define HDETECT_ERR_VAR_STATUS_hdetect_error_mean(data)               (0x0000FFFF&(data))
#define HDETECT_ERR_VAR_STATUS_get_hdetect_error_var(data)            ((0xFFFF0000&(data))>>16)
#define HDETECT_ERR_VAR_STATUS_get_hdetect_error_mean(data)           (0x0000FFFF&(data))


#define LOCK_COUNT                                                    0x18019130
#define LOCK_COUNT_reg_addr                                           "0xb8019130"
#define LOCK_COUNT_reg                                                0xb8019130
#define LOCK_COUNT_inst_addr                                          "0x004C"
#define LOCK_COUNT_inst                                               0x004C
#define LOCK_COUNT_locked_count_noisy_max_shift                       (4)
#define LOCK_COUNT_locked_count_clean_max_shift                       (0)
#define LOCK_COUNT_locked_count_noisy_max_mask                        (0x000000F0)
#define LOCK_COUNT_locked_count_clean_max_mask                        (0x0000000F)
#define LOCK_COUNT_locked_count_noisy_max(data)                       (0x000000F0&((data)<<4))
#define LOCK_COUNT_locked_count_clean_max(data)                       (0x0000000F&(data))
#define LOCK_COUNT_get_locked_count_noisy_max(data)                   ((0x000000F0&(data))>>4)
#define LOCK_COUNT_get_locked_count_clean_max(data)                   (0x0000000F&(data))


#define H_LOOP_MAXSTATE                                               0x18019134
#define H_LOOP_MAXSTATE_reg_addr                                      "0xb8019134"
#define H_LOOP_MAXSTATE_reg                                           0xb8019134
#define H_LOOP_MAXSTATE_inst_addr                                     "0x004D"
#define H_LOOP_MAXSTATE_inst                                          0x004D
#define H_LOOP_MAXSTATE_hlock_vsync_mode_shift                        (6)
#define H_LOOP_MAXSTATE_hstate_fixed_shift                            (5)
#define H_LOOP_MAXSTATE_disable_hfine_shift                           (4)
#define H_LOOP_MAXSTATE_hstate_unlocked_shift                         (3)
#define H_LOOP_MAXSTATE_hstate_max_shift                              (0)
#define H_LOOP_MAXSTATE_hlock_vsync_mode_mask                         (0x000000C0)
#define H_LOOP_MAXSTATE_hstate_fixed_mask                             (0x00000020)
#define H_LOOP_MAXSTATE_disable_hfine_mask                            (0x00000010)
#define H_LOOP_MAXSTATE_hstate_unlocked_mask                          (0x00000008)
#define H_LOOP_MAXSTATE_hstate_max_mask                               (0x00000007)
#define H_LOOP_MAXSTATE_hlock_vsync_mode(data)                        (0x000000C0&((data)<<6))
#define H_LOOP_MAXSTATE_hstate_fixed(data)                            (0x00000020&((data)<<5))
#define H_LOOP_MAXSTATE_disable_hfine(data)                           (0x00000010&((data)<<4))
#define H_LOOP_MAXSTATE_hstate_unlocked(data)                         (0x00000008&((data)<<3))
#define H_LOOP_MAXSTATE_hstate_max(data)                              (0x00000007&(data))
#define H_LOOP_MAXSTATE_get_hlock_vsync_mode(data)                    ((0x000000C0&(data))>>6)
#define H_LOOP_MAXSTATE_get_hstate_fixed(data)                        ((0x00000020&(data))>>5)
#define H_LOOP_MAXSTATE_get_disable_hfine(data)                       ((0x00000010&(data))>>4)
#define H_LOOP_MAXSTATE_get_hstate_unlocked(data)                     ((0x00000008&(data))>>3)
#define H_LOOP_MAXSTATE_get_hstate_max(data)                          (0x00000007&(data))


#define CLAMPAGC_CTRL0                                                0x18019138
#define CLAMPAGC_CTRL0_reg_addr                                       "0xb8019138"
#define CLAMPAGC_CTRL0_reg                                            0xb8019138
#define CLAMPAGC_CTRL0_inst_addr                                      "0x004E"
#define CLAMPAGC_CTRL0_inst                                           0x004E
#define CLAMPAGC_CTRL0_fine_phase_error_thl_9_0_shift                 (16)
#define CLAMPAGC_CTRL0_cpll_hpll_use_front_vactive_shift              (15)
#define CLAMPAGC_CTRL0_hstate_hlock_sel_shift                         (14)
#define CLAMPAGC_CTRL0_hstate_ignore_err_shift                        (13)
#define CLAMPAGC_CTRL0_auto_fine_phase_sel_shift                      (12)
#define CLAMPAGC_CTRL0_fine_hstate_to_5_shift                         (11)
#define CLAMPAGC_CTRL0_auto_fine_phase_sel_en_shift                   (10)
#define CLAMPAGC_CTRL0_hpll_fine_lock_data_sel_shift                  (9)
#define CLAMPAGC_CTRL0_coarse_phase_rising_en_shift                   (8)
#define CLAMPAGC_CTRL0_fine_src_sel_shift                             (7)
#define CLAMPAGC_CTRL0_coarse_src_sel_shift                           (6)
#define CLAMPAGC_CTRL0_fine_gate_sel_shift                            (5)
#define CLAMPAGC_CTRL0_gate_end_thresh_shift                          (0)
#define CLAMPAGC_CTRL0_fine_phase_error_thl_9_0_mask                  (0x03FF0000)
#define CLAMPAGC_CTRL0_cpll_hpll_use_front_vactive_mask               (0x00008000)
#define CLAMPAGC_CTRL0_hstate_hlock_sel_mask                          (0x00004000)
#define CLAMPAGC_CTRL0_hstate_ignore_err_mask                         (0x00002000)
#define CLAMPAGC_CTRL0_auto_fine_phase_sel_mask                       (0x00001000)
#define CLAMPAGC_CTRL0_fine_hstate_to_5_mask                          (0x00000800)
#define CLAMPAGC_CTRL0_auto_fine_phase_sel_en_mask                    (0x00000400)
#define CLAMPAGC_CTRL0_hpll_fine_lock_data_sel_mask                   (0x00000200)
#define CLAMPAGC_CTRL0_coarse_phase_rising_en_mask                    (0x00000100)
#define CLAMPAGC_CTRL0_fine_src_sel_mask                              (0x00000080)
#define CLAMPAGC_CTRL0_coarse_src_sel_mask                            (0x00000040)
#define CLAMPAGC_CTRL0_fine_gate_sel_mask                             (0x00000020)
#define CLAMPAGC_CTRL0_gate_end_thresh_mask                           (0x0000001F)
#define CLAMPAGC_CTRL0_fine_phase_error_thl_9_0(data)                 (0x03FF0000&((data)<<16))
#define CLAMPAGC_CTRL0_cpll_hpll_use_front_vactive(data)              (0x00008000&((data)<<15))
#define CLAMPAGC_CTRL0_hstate_hlock_sel(data)                         (0x00004000&((data)<<14))
#define CLAMPAGC_CTRL0_hstate_ignore_err(data)                        (0x00002000&((data)<<13))
#define CLAMPAGC_CTRL0_auto_fine_phase_sel(data)                      (0x00001000&((data)<<12))
#define CLAMPAGC_CTRL0_fine_hstate_to_5(data)                         (0x00000800&((data)<<11))
#define CLAMPAGC_CTRL0_auto_fine_phase_sel_en(data)                   (0x00000400&((data)<<10))
#define CLAMPAGC_CTRL0_hpll_fine_lock_data_sel(data)                  (0x00000200&((data)<<9))
#define CLAMPAGC_CTRL0_coarse_phase_rising_en(data)                   (0x00000100&((data)<<8))
#define CLAMPAGC_CTRL0_fine_src_sel(data)                             (0x00000080&((data)<<7))
#define CLAMPAGC_CTRL0_coarse_src_sel(data)                           (0x00000040&((data)<<6))
#define CLAMPAGC_CTRL0_fine_gate_sel(data)                            (0x00000020&((data)<<5))
#define CLAMPAGC_CTRL0_gate_end_thresh(data)                          (0x0000001F&(data))
#define CLAMPAGC_CTRL0_get_fine_phase_error_thl_9_0(data)             ((0x03FF0000&(data))>>16)
#define CLAMPAGC_CTRL0_get_cpll_hpll_use_front_vactive(data)          ((0x00008000&(data))>>15)
#define CLAMPAGC_CTRL0_get_hstate_hlock_sel(data)                     ((0x00004000&(data))>>14)
#define CLAMPAGC_CTRL0_get_hstate_ignore_err(data)                    ((0x00002000&(data))>>13)
#define CLAMPAGC_CTRL0_get_auto_fine_phase_sel(data)                  ((0x00001000&(data))>>12)
#define CLAMPAGC_CTRL0_get_fine_hstate_to_5(data)                     ((0x00000800&(data))>>11)
#define CLAMPAGC_CTRL0_get_auto_fine_phase_sel_en(data)               ((0x00000400&(data))>>10)
#define CLAMPAGC_CTRL0_get_hpll_fine_lock_data_sel(data)              ((0x00000200&(data))>>9)
#define CLAMPAGC_CTRL0_get_coarse_phase_rising_en(data)               ((0x00000100&(data))>>8)
#define CLAMPAGC_CTRL0_get_fine_src_sel(data)                         ((0x00000080&(data))>>7)
#define CLAMPAGC_CTRL0_get_coarse_src_sel(data)                       ((0x00000040&(data))>>6)
#define CLAMPAGC_CTRL0_get_fine_gate_sel(data)                        ((0x00000020&(data))>>5)
#define CLAMPAGC_CTRL0_get_gate_end_thresh(data)                      (0x0000001F&(data))


#define CLAMPAGC_NEW_SYNC_START                                       0x1801913c
#define CLAMPAGC_NEW_SYNC_START_reg_addr                              "0xb801913c"
#define CLAMPAGC_NEW_SYNC_START_reg                                   0xb801913c
#define CLAMPAGC_NEW_SYNC_START_inst_addr                             "0x004F"
#define CLAMPAGC_NEW_SYNC_START_inst                                  0x004F
#define CLAMPAGC_NEW_SYNC_START_coarse_sync_start_shift               (0)
#define CLAMPAGC_NEW_SYNC_START_coarse_sync_start_mask                (0x0000007F)
#define CLAMPAGC_NEW_SYNC_START_coarse_sync_start(data)               (0x0000007F&(data))
#define CLAMPAGC_NEW_SYNC_START_get_coarse_sync_start(data)           (0x0000007F&(data))


#define CLAMPAGC_NEW_SYNC_END                                         0x18019140
#define CLAMPAGC_NEW_SYNC_END_reg_addr                                "0xb8019140"
#define CLAMPAGC_NEW_SYNC_END_reg                                     0xb8019140
#define CLAMPAGC_NEW_SYNC_END_inst_addr                               "0x0050"
#define CLAMPAGC_NEW_SYNC_END_inst                                    0x0050
#define CLAMPAGC_NEW_SYNC_END_coarse_sync_end_shift                   (0)
#define CLAMPAGC_NEW_SYNC_END_coarse_sync_end_mask                    (0x000000FF)
#define CLAMPAGC_NEW_SYNC_END_coarse_sync_end(data)                   (0x000000FF&(data))
#define CLAMPAGC_NEW_SYNC_END_get_coarse_sync_end(data)               (0x000000FF&(data))


#define CLAMPAGC_NEW_BACKPORCH_START                                  0x18019144
#define CLAMPAGC_NEW_BACKPORCH_START_reg_addr                         "0xb8019144"
#define CLAMPAGC_NEW_BACKPORCH_START_reg                              0xb8019144
#define CLAMPAGC_NEW_BACKPORCH_START_inst_addr                        "0x0051"
#define CLAMPAGC_NEW_BACKPORCH_START_inst                             0x0051
#define CLAMPAGC_NEW_BACKPORCH_START_agc_trailing_sel_shift           (7)
#define CLAMPAGC_NEW_BACKPORCH_START_coarse_backporch_start_shift     (0)
#define CLAMPAGC_NEW_BACKPORCH_START_agc_trailing_sel_mask            (0x00000080)
#define CLAMPAGC_NEW_BACKPORCH_START_coarse_backporch_start_mask      (0x0000007F)
#define CLAMPAGC_NEW_BACKPORCH_START_agc_trailing_sel(data)           (0x00000080&((data)<<7))
#define CLAMPAGC_NEW_BACKPORCH_START_coarse_backporch_start(data)     (0x0000007F&(data))
#define CLAMPAGC_NEW_BACKPORCH_START_get_agc_trailing_sel(data)       ((0x00000080&(data))>>7)
#define CLAMPAGC_NEW_BACKPORCH_START_get_coarse_backporch_start(data) (0x0000007F&(data))


#define CLAMPAGC_NEW_BACKPORCH_END                                    0x18019148
#define CLAMPAGC_NEW_BACKPORCH_END_reg_addr                           "0xb8019148"
#define CLAMPAGC_NEW_BACKPORCH_END_reg                                0xb8019148
#define CLAMPAGC_NEW_BACKPORCH_END_inst_addr                          "0x0052"
#define CLAMPAGC_NEW_BACKPORCH_END_inst                               0x0052
#define CLAMPAGC_NEW_BACKPORCH_END_coarse_backporch_end_shift         (0)
#define CLAMPAGC_NEW_BACKPORCH_END_coarse_backporch_end_mask          (0x000000FF)
#define CLAMPAGC_NEW_BACKPORCH_END_coarse_backporch_end(data)         (0x000000FF&(data))
#define CLAMPAGC_NEW_BACKPORCH_END_get_coarse_backporch_end(data)     (0x000000FF&(data))


#define HDETECT_PHASE_SEL                                             0x1801914c
#define HDETECT_PHASE_SEL_reg_addr                                    "0xb801914c"
#define HDETECT_PHASE_SEL_reg                                         0xb801914c
#define HDETECT_PHASE_SEL_inst_addr                                   "0x0053"
#define HDETECT_PHASE_SEL_inst                                        0x0053
#define HDETECT_PHASE_SEL_lpfsync_force_blank_en_shift                (5)
#define HDETECT_PHASE_SEL_nosignal_hlock_check_en_shift               (4)
#define HDETECT_PHASE_SEL_agc_clamping_trailing_sel_shift             (3)
#define HDETECT_PHASE_SEL_killgate_sel_shift                          (2)
#define HDETECT_PHASE_SEL_coarse_phase_sel_shift                      (1)
#define HDETECT_PHASE_SEL_fine_phase_sel_shift                        (0)
#define HDETECT_PHASE_SEL_lpfsync_force_blank_en_mask                 (0x00000020)
#define HDETECT_PHASE_SEL_nosignal_hlock_check_en_mask                (0x00000010)
#define HDETECT_PHASE_SEL_agc_clamping_trailing_sel_mask              (0x00000008)
#define HDETECT_PHASE_SEL_killgate_sel_mask                           (0x00000004)
#define HDETECT_PHASE_SEL_coarse_phase_sel_mask                       (0x00000002)
#define HDETECT_PHASE_SEL_fine_phase_sel_mask                         (0x00000001)
#define HDETECT_PHASE_SEL_lpfsync_force_blank_en(data)                (0x00000020&((data)<<5))
#define HDETECT_PHASE_SEL_nosignal_hlock_check_en(data)               (0x00000010&((data)<<4))
#define HDETECT_PHASE_SEL_agc_clamping_trailing_sel(data)             (0x00000008&((data)<<3))
#define HDETECT_PHASE_SEL_killgate_sel(data)                          (0x00000004&((data)<<2))
#define HDETECT_PHASE_SEL_coarse_phase_sel(data)                      (0x00000002&((data)<<1))
#define HDETECT_PHASE_SEL_fine_phase_sel(data)                        (0x00000001&(data))
#define HDETECT_PHASE_SEL_get_lpfsync_force_blank_en(data)            ((0x00000020&(data))>>5)
#define HDETECT_PHASE_SEL_get_nosignal_hlock_check_en(data)           ((0x00000010&(data))>>4)
#define HDETECT_PHASE_SEL_get_agc_clamping_trailing_sel(data)         ((0x00000008&(data))>>3)
#define HDETECT_PHASE_SEL_get_killgate_sel(data)                      ((0x00000004&(data))>>2)
#define HDETECT_PHASE_SEL_get_coarse_phase_sel(data)                  ((0x00000002&(data))>>1)
#define HDETECT_PHASE_SEL_get_fine_phase_sel(data)                    (0x00000001&(data))


#define HDETECT_COUNTER_TIP_START                                     0x18019150
#define HDETECT_COUNTER_TIP_START_reg_addr                            "0xb8019150"
#define HDETECT_COUNTER_TIP_START_reg                                 0xb8019150
#define HDETECT_COUNTER_TIP_START_inst_addr                           "0x0054"
#define HDETECT_COUNTER_TIP_START_inst                                0x0054
#define HDETECT_COUNTER_TIP_START_lsync_tip_start_shift               (0)
#define HDETECT_COUNTER_TIP_START_lsync_tip_start_mask                (0x000000FF)
#define HDETECT_COUNTER_TIP_START_lsync_tip_start(data)               (0x000000FF&(data))
#define HDETECT_COUNTER_TIP_START_get_lsync_tip_start(data)           (0x000000FF&(data))


#define HDETECT_COUNTER_TIP_END                                       0x18019154
#define HDETECT_COUNTER_TIP_END_reg_addr                              "0xb8019154"
#define HDETECT_COUNTER_TIP_END_reg                                   0xb8019154
#define HDETECT_COUNTER_TIP_END_inst_addr                             "0x0055"
#define HDETECT_COUNTER_TIP_END_inst                                  0x0055
#define HDETECT_COUNTER_TIP_END_lsync_tip_end_shift                   (0)
#define HDETECT_COUNTER_TIP_END_lsync_tip_end_mask                    (0x000000FF)
#define HDETECT_COUNTER_TIP_END_lsync_tip_end(data)                   (0x000000FF&(data))
#define HDETECT_COUNTER_TIP_END_get_lsync_tip_end(data)               (0x000000FF&(data))


#define HDETECT_COUNTER_BACKPORCH_START                               0x18019158
#define HDETECT_COUNTER_BACKPORCH_START_reg_addr                      "0xb8019158"
#define HDETECT_COUNTER_BACKPORCH_START_reg                           0xb8019158
#define HDETECT_COUNTER_BACKPORCH_START_inst_addr                     "0x0056"
#define HDETECT_COUNTER_BACKPORCH_START_inst                          0x0056
#define HDETECT_COUNTER_BACKPORCH_START_lporch_start_shift            (0)
#define HDETECT_COUNTER_BACKPORCH_START_lporch_start_mask             (0x000000FF)
#define HDETECT_COUNTER_BACKPORCH_START_lporch_start(data)            (0x000000FF&(data))
#define HDETECT_COUNTER_BACKPORCH_START_get_lporch_start(data)        (0x000000FF&(data))


#define HDETECT_COUNTER_BACKPORCH_END                                 0x1801915c
#define HDETECT_COUNTER_BACKPORCH_END_reg_addr                        "0xb801915c"
#define HDETECT_COUNTER_BACKPORCH_END_reg                             0xb801915c
#define HDETECT_COUNTER_BACKPORCH_END_inst_addr                       "0x0057"
#define HDETECT_COUNTER_BACKPORCH_END_inst                            0x0057
#define HDETECT_COUNTER_BACKPORCH_END_lporch_end_shift                (0)
#define HDETECT_COUNTER_BACKPORCH_END_lporch_end_mask                 (0x000000FF)
#define HDETECT_COUNTER_BACKPORCH_END_lporch_end(data)                (0x000000FF&(data))
#define HDETECT_COUNTER_BACKPORCH_END_get_lporch_end(data)            (0x000000FF&(data))


#define HPLL_INTEGRAL_CTRL                                            0x18019160
#define HPLL_INTEGRAL_CTRL_reg_addr                                   "0xb8019160"
#define HPLL_INTEGRAL_CTRL_reg                                        0xb8019160
#define HPLL_INTEGRAL_CTRL_inst_addr                                  "0x0058"
#define HPLL_INTEGRAL_CTRL_inst                                       0x0058
#define HPLL_INTEGRAL_CTRL_hpll_integral_rst_shift                    (1)
#define HPLL_INTEGRAL_CTRL_hpll_integral_ext_shift                    (0)
#define HPLL_INTEGRAL_CTRL_hpll_integral_rst_mask                     (0x00000002)
#define HPLL_INTEGRAL_CTRL_hpll_integral_ext_mask                     (0x00000001)
#define HPLL_INTEGRAL_CTRL_hpll_integral_rst(data)                    (0x00000002&((data)<<1))
#define HPLL_INTEGRAL_CTRL_hpll_integral_ext(data)                    (0x00000001&(data))
#define HPLL_INTEGRAL_CTRL_get_hpll_integral_rst(data)                ((0x00000002&(data))>>1)
#define HPLL_INTEGRAL_CTRL_get_hpll_integral_ext(data)                (0x00000001&(data))


#define HDETECT_LOOPFILTER_SW                                         0x18019164
#define HDETECT_LOOPFILTER_SW_reg_addr                                "0xb8019164"
#define HDETECT_LOOPFILTER_SW_reg                                     0xb8019164
#define HDETECT_LOOPFILTER_SW_inst_addr                               "0x0059"
#define HDETECT_LOOPFILTER_SW_inst                                    0x0059
#define HDETECT_LOOPFILTER_SW_impulsive_noise_disable_pll_en_shift    (15)
#define HDETECT_LOOPFILTER_SW_cstate_impn_max_shift                   (12)
#define HDETECT_LOOPFILTER_SW_hstate_impn_max_shift                   (8)
#define HDETECT_LOOPFILTER_SW_hstate_vcr_max_shift                    (4)
#define HDETECT_LOOPFILTER_SW_hstate_loopfilter_sw_shift              (3)
#define HDETECT_LOOPFILTER_SW_hstate_status_shift                     (0)
#define HDETECT_LOOPFILTER_SW_impulsive_noise_disable_pll_en_mask     (0x00008000)
#define HDETECT_LOOPFILTER_SW_cstate_impn_max_mask                    (0x00007000)
#define HDETECT_LOOPFILTER_SW_hstate_impn_max_mask                    (0x00000700)
#define HDETECT_LOOPFILTER_SW_hstate_vcr_max_mask                     (0x00000070)
#define HDETECT_LOOPFILTER_SW_hstate_loopfilter_sw_mask               (0x00000008)
#define HDETECT_LOOPFILTER_SW_hstate_status_mask                      (0x00000007)
#define HDETECT_LOOPFILTER_SW_impulsive_noise_disable_pll_en(data)    (0x00008000&((data)<<15))
#define HDETECT_LOOPFILTER_SW_cstate_impn_max(data)                   (0x00007000&((data)<<12))
#define HDETECT_LOOPFILTER_SW_hstate_impn_max(data)                   (0x00000700&((data)<<8))
#define HDETECT_LOOPFILTER_SW_hstate_vcr_max(data)                    (0x00000070&((data)<<4))
#define HDETECT_LOOPFILTER_SW_hstate_loopfilter_sw(data)              (0x00000008&((data)<<3))
#define HDETECT_LOOPFILTER_SW_hstate_status(data)                     (0x00000007&(data))
#define HDETECT_LOOPFILTER_SW_get_impulsive_noise_disable_pll_en(data)  ((0x00008000&(data))>>15)
#define HDETECT_LOOPFILTER_SW_get_cstate_impn_max(data)               ((0x00007000&(data))>>12)
#define HDETECT_LOOPFILTER_SW_get_hstate_impn_max(data)               ((0x00000700&(data))>>8)
#define HDETECT_LOOPFILTER_SW_get_hstate_vcr_max(data)                ((0x00000070&(data))>>4)
#define HDETECT_LOOPFILTER_SW_get_hstate_loopfilter_sw(data)          ((0x00000008&(data))>>3)
#define HDETECT_LOOPFILTER_SW_get_hstate_status(data)                 (0x00000007&(data))


#define HDETECT_LOOPFILTER_DCTRL                                      0x18019168
#define HDETECT_LOOPFILTER_DCTRL_reg_addr                             "0xb8019168"
#define HDETECT_LOOPFILTER_DCTRL_reg                                  0xb8019168
#define HDETECT_LOOPFILTER_DCTRL_inst_addr                            "0x005A"
#define HDETECT_LOOPFILTER_DCTRL_inst                                 0x005A
#define HDETECT_LOOPFILTER_DCTRL_hdetect_loopfilter_dctrl1_shift      (4)
#define HDETECT_LOOPFILTER_DCTRL_hdetect_loopfilter_dctrl2_shift      (0)
#define HDETECT_LOOPFILTER_DCTRL_hdetect_loopfilter_dctrl1_mask       (0x000000F0)
#define HDETECT_LOOPFILTER_DCTRL_hdetect_loopfilter_dctrl2_mask       (0x0000000F)
#define HDETECT_LOOPFILTER_DCTRL_hdetect_loopfilter_dctrl1(data)      (0x000000F0&((data)<<4))
#define HDETECT_LOOPFILTER_DCTRL_hdetect_loopfilter_dctrl2(data)      (0x0000000F&(data))
#define HDETECT_LOOPFILTER_DCTRL_get_hdetect_loopfilter_dctrl1(data)  ((0x000000F0&(data))>>4)
#define HDETECT_LOOPFILTER_DCTRL_get_hdetect_loopfilter_dctrl2(data)  (0x0000000F&(data))


#define HSYNC_PULSE_START                                             0x1801916c
#define HSYNC_PULSE_START_reg_addr                                    "0xb801916c"
#define HSYNC_PULSE_START_reg                                         0xb801916c
#define HSYNC_PULSE_START_inst_addr                                   "0x005B"
#define HSYNC_PULSE_START_inst                                        0x005B
#define HSYNC_PULSE_START_hsync_start_shift                           (0)
#define HSYNC_PULSE_START_hsync_start_mask                            (0x000000FF)
#define HSYNC_PULSE_START_hsync_start(data)                           (0x000000FF&(data))
#define HSYNC_PULSE_START_get_hsync_start(data)                       (0x000000FF&(data))


#define HSYNC_PULSE_WIDTH                                             0x18019170
#define HSYNC_PULSE_WIDTH_reg_addr                                    "0xb8019170"
#define HSYNC_PULSE_WIDTH_reg                                         0xb8019170
#define HSYNC_PULSE_WIDTH_inst_addr                                   "0x005C"
#define HSYNC_PULSE_WIDTH_inst                                        0x005C
#define HSYNC_PULSE_WIDTH_hsync_width_shift                           (0)
#define HSYNC_PULSE_WIDTH_hsync_width_mask                            (0x000000FF)
#define HSYNC_PULSE_WIDTH_hsync_width(data)                           (0x000000FF&(data))
#define HSYNC_PULSE_WIDTH_get_hsync_width(data)                       (0x000000FF&(data))


#define CHROMA_HRESAMPLER_CONTROL                                     0x18019174
#define CHROMA_HRESAMPLER_CONTROL_reg_addr                            "0xb8019174"
#define CHROMA_HRESAMPLER_CONTROL_reg                                 0xb8019174
#define CHROMA_HRESAMPLER_CONTROL_inst_addr                           "0x005D"
#define CHROMA_HRESAMPLER_CONTROL_inst                                0x005D
#define CHROMA_HRESAMPLER_CONTROL_hresampler_app_alpha_sel_shift      (2)
#define CHROMA_HRESAMPLER_CONTROL_hresampler_app_sel_shift            (1)
#define CHROMA_HRESAMPLER_CONTROL_hresampler_2up_shift                (0)
#define CHROMA_HRESAMPLER_CONTROL_hresampler_app_alpha_sel_mask       (0x00000004)
#define CHROMA_HRESAMPLER_CONTROL_hresampler_app_sel_mask             (0x00000002)
#define CHROMA_HRESAMPLER_CONTROL_hresampler_2up_mask                 (0x00000001)
#define CHROMA_HRESAMPLER_CONTROL_hresampler_app_alpha_sel(data)      (0x00000004&((data)<<2))
#define CHROMA_HRESAMPLER_CONTROL_hresampler_app_sel(data)            (0x00000002&((data)<<1))
#define CHROMA_HRESAMPLER_CONTROL_hresampler_2up(data)                (0x00000001&(data))
#define CHROMA_HRESAMPLER_CONTROL_get_hresampler_app_alpha_sel(data)  ((0x00000004&(data))>>2)
#define CHROMA_HRESAMPLER_CONTROL_get_hresampler_app_sel(data)        ((0x00000002&(data))>>1)
#define CHROMA_HRESAMPLER_CONTROL_get_hresampler_2up(data)            (0x00000001&(data))


#define HPLL_KP_0                                                     0x18019178
#define HPLL_KP_0_reg_addr                                            "0xb8019178"
#define HPLL_KP_0_reg                                                 0xb8019178
#define HPLL_KP_0_inst_addr                                           "0x005E"
#define HPLL_KP_0_inst                                                0x005E
#define HPLL_KP_0_hpll_manu_mode_en_shift                             (7)
#define HPLL_KP_0_hpll_kp_coef_0_shift                                (0)
#define HPLL_KP_0_hpll_manu_mode_en_mask                              (0x00000080)
#define HPLL_KP_0_hpll_kp_coef_0_mask                                 (0x0000003F)
#define HPLL_KP_0_hpll_manu_mode_en(data)                             (0x00000080&((data)<<7))
#define HPLL_KP_0_hpll_kp_coef_0(data)                                (0x0000003F&(data))
#define HPLL_KP_0_get_hpll_manu_mode_en(data)                         ((0x00000080&(data))>>7)
#define HPLL_KP_0_get_hpll_kp_coef_0(data)                            (0x0000003F&(data))


#define HPLL_KP_1                                                     0x1801917c
#define HPLL_KP_1_reg_addr                                            "0xb801917c"
#define HPLL_KP_1_reg                                                 0xb801917c
#define HPLL_KP_1_inst_addr                                           "0x005F"
#define HPLL_KP_1_inst                                                0x005F
#define HPLL_KP_1_hpll_kp_coef_1_shift                                (0)
#define HPLL_KP_1_hpll_kp_coef_1_mask                                 (0x0000003F)
#define HPLL_KP_1_hpll_kp_coef_1(data)                                (0x0000003F&(data))
#define HPLL_KP_1_get_hpll_kp_coef_1(data)                            (0x0000003F&(data))


#define HPLL_KP_2                                                     0x18019180
#define HPLL_KP_2_reg_addr                                            "0xb8019180"
#define HPLL_KP_2_reg                                                 0xb8019180
#define HPLL_KP_2_inst_addr                                           "0x0060"
#define HPLL_KP_2_inst                                                0x0060
#define HPLL_KP_2_hpll_kp_coef_2_shift                                (0)
#define HPLL_KP_2_hpll_kp_coef_2_mask                                 (0x0000003F)
#define HPLL_KP_2_hpll_kp_coef_2(data)                                (0x0000003F&(data))
#define HPLL_KP_2_get_hpll_kp_coef_2(data)                            (0x0000003F&(data))


#define HPLL_KP_3                                                     0x18019184
#define HPLL_KP_3_reg_addr                                            "0xb8019184"
#define HPLL_KP_3_reg                                                 0xb8019184
#define HPLL_KP_3_inst_addr                                           "0x0061"
#define HPLL_KP_3_inst                                                0x0061
#define HPLL_KP_3_hpll_kp_coef_3_shift                                (0)
#define HPLL_KP_3_hpll_kp_coef_3_mask                                 (0x0000003F)
#define HPLL_KP_3_hpll_kp_coef_3(data)                                (0x0000003F&(data))
#define HPLL_KP_3_get_hpll_kp_coef_3(data)                            (0x0000003F&(data))


#define HPLL_KP_4                                                     0x18019188
#define HPLL_KP_4_reg_addr                                            "0xb8019188"
#define HPLL_KP_4_reg                                                 0xb8019188
#define HPLL_KP_4_inst_addr                                           "0x0062"
#define HPLL_KP_4_inst                                                0x0062
#define HPLL_KP_4_hpll_kp_coef_4_shift                                (0)
#define HPLL_KP_4_hpll_kp_coef_4_mask                                 (0x0000003F)
#define HPLL_KP_4_hpll_kp_coef_4(data)                                (0x0000003F&(data))
#define HPLL_KP_4_get_hpll_kp_coef_4(data)                            (0x0000003F&(data))


#define HPLL_KP_5                                                     0x1801918c
#define HPLL_KP_5_reg_addr                                            "0xb801918c"
#define HPLL_KP_5_reg                                                 0xb801918c
#define HPLL_KP_5_inst_addr                                           "0x0063"
#define HPLL_KP_5_inst                                                0x0063
#define HPLL_KP_5_hpll_kp_coef_5_shift                                (0)
#define HPLL_KP_5_hpll_kp_coef_5_mask                                 (0x0000003F)
#define HPLL_KP_5_hpll_kp_coef_5(data)                                (0x0000003F&(data))
#define HPLL_KP_5_get_hpll_kp_coef_5(data)                            (0x0000003F&(data))


#define HPLL_KI_0                                                     0x18019190
#define HPLL_KI_0_reg_addr                                            "0xb8019190"
#define HPLL_KI_0_reg                                                 0xb8019190
#define HPLL_KI_0_inst_addr                                           "0x0064"
#define HPLL_KI_0_inst                                                0x0064
#define HPLL_KI_0_hpll_ki_coef_0_shift                                (0)
#define HPLL_KI_0_hpll_ki_coef_0_mask                                 (0x000000FF)
#define HPLL_KI_0_hpll_ki_coef_0(data)                                (0x000000FF&(data))
#define HPLL_KI_0_get_hpll_ki_coef_0(data)                            (0x000000FF&(data))


#define HPLL_KI_1                                                     0x18019194
#define HPLL_KI_1_reg_addr                                            "0xb8019194"
#define HPLL_KI_1_reg                                                 0xb8019194
#define HPLL_KI_1_inst_addr                                           "0x0065"
#define HPLL_KI_1_inst                                                0x0065
#define HPLL_KI_1_hpll_ki_coef_1_shift                                (0)
#define HPLL_KI_1_hpll_ki_coef_1_mask                                 (0x000000FF)
#define HPLL_KI_1_hpll_ki_coef_1(data)                                (0x000000FF&(data))
#define HPLL_KI_1_get_hpll_ki_coef_1(data)                            (0x000000FF&(data))


#define HPLL_KI_2                                                     0x18019198
#define HPLL_KI_2_reg_addr                                            "0xb8019198"
#define HPLL_KI_2_reg                                                 0xb8019198
#define HPLL_KI_2_inst_addr                                           "0x0066"
#define HPLL_KI_2_inst                                                0x0066
#define HPLL_KI_2_hpll_ki_coef_2_shift                                (0)
#define HPLL_KI_2_hpll_ki_coef_2_mask                                 (0x000000FF)
#define HPLL_KI_2_hpll_ki_coef_2(data)                                (0x000000FF&(data))
#define HPLL_KI_2_get_hpll_ki_coef_2(data)                            (0x000000FF&(data))


#define HPLL_KI_3                                                     0x1801919c
#define HPLL_KI_3_reg_addr                                            "0xb801919c"
#define HPLL_KI_3_reg                                                 0xb801919c
#define HPLL_KI_3_inst_addr                                           "0x0067"
#define HPLL_KI_3_inst                                                0x0067
#define HPLL_KI_3_hpll_ki_coef_3_shift                                (0)
#define HPLL_KI_3_hpll_ki_coef_3_mask                                 (0x000000FF)
#define HPLL_KI_3_hpll_ki_coef_3(data)                                (0x000000FF&(data))
#define HPLL_KI_3_get_hpll_ki_coef_3(data)                            (0x000000FF&(data))


#define HPLL_KI_4                                                     0x180191a0
#define HPLL_KI_4_reg_addr                                            "0xb80191a0"
#define HPLL_KI_4_reg                                                 0xb80191a0
#define HPLL_KI_4_inst_addr                                           "0x0068"
#define HPLL_KI_4_inst                                                0x0068
#define HPLL_KI_4_hpll_ki_coef_4_shift                                (0)
#define HPLL_KI_4_hpll_ki_coef_4_mask                                 (0x000000FF)
#define HPLL_KI_4_hpll_ki_coef_4(data)                                (0x000000FF&(data))
#define HPLL_KI_4_get_hpll_ki_coef_4(data)                            (0x000000FF&(data))


#define HPLL_KI_5                                                     0x180191a4
#define HPLL_KI_5_reg_addr                                            "0xb80191a4"
#define HPLL_KI_5_reg                                                 0xb80191a4
#define HPLL_KI_5_inst_addr                                           "0x0069"
#define HPLL_KI_5_inst                                                0x0069
#define HPLL_KI_5_hpll_ki_coef_5_shift                                (0)
#define HPLL_KI_5_hpll_ki_coef_5_mask                                 (0x000000FF)
#define HPLL_KI_5_hpll_ki_coef_5(data)                                (0x000000FF&(data))
#define HPLL_KI_5_get_hpll_ki_coef_5(data)                            (0x000000FF&(data))


#define SECOND_PLL_GAIN                                               0x180191a8
#define SECOND_PLL_GAIN_reg_addr                                      "0xb80191a8"
#define SECOND_PLL_GAIN_reg                                           0xb80191a8
#define SECOND_PLL_GAIN_inst_addr                                     "0x006A"
#define SECOND_PLL_GAIN_inst                                          0x006A
#define SECOND_PLL_GAIN_second_pll_level_sel_shift                    (8)
#define SECOND_PLL_GAIN_second_pll_gain_sel_shift                     (4)
#define SECOND_PLL_GAIN_second_pll_clampgate_sel_shift                (3)
#define SECOND_PLL_GAIN_second_pll_phase_sel_shift                    (2)
#define SECOND_PLL_GAIN_second_pll_w_hlock_shift                      (1)
#define SECOND_PLL_GAIN_second_pll_en_shift                           (0)
#define SECOND_PLL_GAIN_second_pll_level_sel_mask                     (0x00000300)
#define SECOND_PLL_GAIN_second_pll_gain_sel_mask                      (0x00000030)
#define SECOND_PLL_GAIN_second_pll_clampgate_sel_mask                 (0x00000008)
#define SECOND_PLL_GAIN_second_pll_phase_sel_mask                     (0x00000004)
#define SECOND_PLL_GAIN_second_pll_w_hlock_mask                       (0x00000002)
#define SECOND_PLL_GAIN_second_pll_en_mask                            (0x00000001)
#define SECOND_PLL_GAIN_second_pll_level_sel(data)                    (0x00000300&((data)<<8))
#define SECOND_PLL_GAIN_second_pll_gain_sel(data)                     (0x00000030&((data)<<4))
#define SECOND_PLL_GAIN_second_pll_clampgate_sel(data)                (0x00000008&((data)<<3))
#define SECOND_PLL_GAIN_second_pll_phase_sel(data)                    (0x00000004&((data)<<2))
#define SECOND_PLL_GAIN_second_pll_w_hlock(data)                      (0x00000002&((data)<<1))
#define SECOND_PLL_GAIN_second_pll_en(data)                           (0x00000001&(data))
#define SECOND_PLL_GAIN_get_second_pll_level_sel(data)                ((0x00000300&(data))>>8)
#define SECOND_PLL_GAIN_get_second_pll_gain_sel(data)                 ((0x00000030&(data))>>4)
#define SECOND_PLL_GAIN_get_second_pll_clampgate_sel(data)            ((0x00000008&(data))>>3)
#define SECOND_PLL_GAIN_get_second_pll_phase_sel(data)                ((0x00000004&(data))>>2)
#define SECOND_PLL_GAIN_get_second_pll_w_hlock(data)                  ((0x00000002&(data))>>1)
#define SECOND_PLL_GAIN_get_second_pll_en(data)                       (0x00000001&(data))


#define SECOND_PLL_GAIN1                                              0x180191ac
#define SECOND_PLL_GAIN1_reg_addr                                     "0xb80191ac"
#define SECOND_PLL_GAIN1_reg                                          0xb80191ac
#define SECOND_PLL_GAIN1_inst_addr                                    "0x006B"
#define SECOND_PLL_GAIN1_inst                                         0x006B
#define SECOND_PLL_GAIN1_second_pll_sync_level_shift                  (24)
#define SECOND_PLL_GAIN1_second_pll_dc_add_shift                      (12)
#define SECOND_PLL_GAIN1_second_pll_dc_rm_shift                       (0)
#define SECOND_PLL_GAIN1_second_pll_sync_level_mask                   (0xFF000000)
#define SECOND_PLL_GAIN1_second_pll_dc_add_mask                       (0x00FFF000)
#define SECOND_PLL_GAIN1_second_pll_dc_rm_mask                        (0x00000FFF)
#define SECOND_PLL_GAIN1_second_pll_sync_level(data)                  (0xFF000000&((data)<<24))
#define SECOND_PLL_GAIN1_second_pll_dc_add(data)                      (0x00FFF000&((data)<<12))
#define SECOND_PLL_GAIN1_second_pll_dc_rm(data)                       (0x00000FFF&(data))
#define SECOND_PLL_GAIN1_get_second_pll_sync_level(data)              ((0xFF000000&(data))>>24)
#define SECOND_PLL_GAIN1_get_second_pll_dc_add(data)                  ((0x00FFF000&(data))>>12)
#define SECOND_PLL_GAIN1_get_second_pll_dc_rm(data)                   (0x00000FFF&(data))


#define SECOND_PLL_GAIN2                                              0x180191b0
#define SECOND_PLL_GAIN2_reg_addr                                     "0xb80191b0"
#define SECOND_PLL_GAIN2_reg                                          0xb80191b0
#define SECOND_PLL_GAIN2_inst_addr                                    "0x006C"
#define SECOND_PLL_GAIN2_inst                                         0x006C
#define SECOND_PLL_GAIN2_second_comp_blevel_shift                     (12)
#define SECOND_PLL_GAIN2_second_comp_slevel_shift                     (0)
#define SECOND_PLL_GAIN2_second_comp_blevel_mask                      (0x00FFF000)
#define SECOND_PLL_GAIN2_second_comp_slevel_mask                      (0x00000FFF)
#define SECOND_PLL_GAIN2_second_comp_blevel(data)                     (0x00FFF000&((data)<<12))
#define SECOND_PLL_GAIN2_second_comp_slevel(data)                     (0x00000FFF&(data))
#define SECOND_PLL_GAIN2_get_second_comp_blevel(data)                 ((0x00FFF000&(data))>>12)
#define SECOND_PLL_GAIN2_get_second_comp_slevel(data)                 (0x00000FFF&(data))


#define SECOND_PLL_GAIN3                                              0x180191b4
#define SECOND_PLL_GAIN3_reg_addr                                     "0xb80191b4"
#define SECOND_PLL_GAIN3_reg                                          0xb80191b4
#define SECOND_PLL_GAIN3_inst_addr                                    "0x006D"
#define SECOND_PLL_GAIN3_inst                                         0x006D
#define SECOND_PLL_GAIN3_second_trailing_shift                        (12)
#define SECOND_PLL_GAIN3_second_dgain_shift                           (0)
#define SECOND_PLL_GAIN3_second_trailing_mask                         (0x000FF000)
#define SECOND_PLL_GAIN3_second_dgain_mask                            (0x00000FFF)
#define SECOND_PLL_GAIN3_second_trailing(data)                        (0x000FF000&((data)<<12))
#define SECOND_PLL_GAIN3_second_dgain(data)                           (0x00000FFF&(data))
#define SECOND_PLL_GAIN3_get_second_trailing(data)                    ((0x000FF000&(data))>>12)
#define SECOND_PLL_GAIN3_get_second_dgain(data)                       (0x00000FFF&(data))


#define SECOND_PLL_GAIN4                                              0x180191b8
#define SECOND_PLL_GAIN4_reg_addr                                     "0xb80191b8"
#define SECOND_PLL_GAIN4_reg                                          0xb80191b8
#define SECOND_PLL_GAIN4_inst_addr                                    "0x006E"
#define SECOND_PLL_GAIN4_inst                                         0x006E
#define SECOND_PLL_GAIN4_second_backporch_start_shift                 (24)
#define SECOND_PLL_GAIN4_second_backporch_end_shift                   (16)
#define SECOND_PLL_GAIN4_second_hsync_tip_start_shift                 (8)
#define SECOND_PLL_GAIN4_second_hsync_tip_end_shift                   (0)
#define SECOND_PLL_GAIN4_second_backporch_start_mask                  (0xFF000000)
#define SECOND_PLL_GAIN4_second_backporch_end_mask                    (0x00FF0000)
#define SECOND_PLL_GAIN4_second_hsync_tip_start_mask                  (0x0000FF00)
#define SECOND_PLL_GAIN4_second_hsync_tip_end_mask                    (0x000000FF)
#define SECOND_PLL_GAIN4_second_backporch_start(data)                 (0xFF000000&((data)<<24))
#define SECOND_PLL_GAIN4_second_backporch_end(data)                   (0x00FF0000&((data)<<16))
#define SECOND_PLL_GAIN4_second_hsync_tip_start(data)                 (0x0000FF00&((data)<<8))
#define SECOND_PLL_GAIN4_second_hsync_tip_end(data)                   (0x000000FF&(data))
#define SECOND_PLL_GAIN4_get_second_backporch_start(data)             ((0xFF000000&(data))>>24)
#define SECOND_PLL_GAIN4_get_second_backporch_end(data)               ((0x00FF0000&(data))>>16)
#define SECOND_PLL_GAIN4_get_second_hsync_tip_start(data)             ((0x0000FF00&(data))>>8)
#define SECOND_PLL_GAIN4_get_second_hsync_tip_end(data)               (0x000000FF&(data))


#define UNDER_NEW_TH1                                                 0x180191bc
#define UNDER_NEW_TH1_reg_addr                                        "0xb80191bc"
#define UNDER_NEW_TH1_reg                                             0xb80191bc
#define UNDER_NEW_TH1_inst_addr                                       "0x006F"
#define UNDER_NEW_TH1_inst                                            0x006F
#define UNDER_NEW_TH1_headswitch_debounce_en_shift                    (27)
#define UNDER_NEW_TH1_second_pll_kill_en_shift                        (26)
#define UNDER_NEW_TH1_under_detected_flag_shift                       (25)
#define UNDER_NEW_TH1_under_count_reset_shift                         (24)
#define UNDER_NEW_TH1_under_line_err_thl_shift                        (12)
#define UNDER_NEW_TH1_under_min_err_thl_shift                         (0)
#define UNDER_NEW_TH1_headswitch_debounce_en_mask                     (0x08000000)
#define UNDER_NEW_TH1_second_pll_kill_en_mask                         (0x04000000)
#define UNDER_NEW_TH1_under_detected_flag_mask                        (0x02000000)
#define UNDER_NEW_TH1_under_count_reset_mask                          (0x01000000)
#define UNDER_NEW_TH1_under_line_err_thl_mask                         (0x003FF000)
#define UNDER_NEW_TH1_under_min_err_thl_mask                          (0x000003FF)
#define UNDER_NEW_TH1_headswitch_debounce_en(data)                    (0x08000000&((data)<<27))
#define UNDER_NEW_TH1_second_pll_kill_en(data)                        (0x04000000&((data)<<26))
#define UNDER_NEW_TH1_under_detected_flag(data)                       (0x02000000&((data)<<25))
#define UNDER_NEW_TH1_under_count_reset(data)                         (0x01000000&((data)<<24))
#define UNDER_NEW_TH1_under_line_err_thl(data)                        (0x003FF000&((data)<<12))
#define UNDER_NEW_TH1_under_min_err_thl(data)                         (0x000003FF&(data))
#define UNDER_NEW_TH1_get_headswitch_debounce_en(data)                ((0x08000000&(data))>>27)
#define UNDER_NEW_TH1_get_second_pll_kill_en(data)                    ((0x04000000&(data))>>26)
#define UNDER_NEW_TH1_get_under_detected_flag(data)                   ((0x02000000&(data))>>25)
#define UNDER_NEW_TH1_get_under_count_reset(data)                     ((0x01000000&(data))>>24)
#define UNDER_NEW_TH1_get_under_line_err_thl(data)                    ((0x003FF000&(data))>>12)
#define UNDER_NEW_TH1_get_under_min_err_thl(data)                     (0x000003FF&(data))


#define UNDER_NEW_TH2                                                 0x180191c0
#define UNDER_NEW_TH2_reg_addr                                        "0xb80191c0"
#define UNDER_NEW_TH2_reg                                             0xb80191c0
#define UNDER_NEW_TH2_inst_addr                                       "0x0070"
#define UNDER_NEW_TH2_inst                                            0x0070
#define UNDER_NEW_TH2_under_field_err_thl_shift                       (0)
#define UNDER_NEW_TH2_under_field_err_thl_mask                        (0x000003FF)
#define UNDER_NEW_TH2_under_field_err_thl(data)                       (0x000003FF&(data))
#define UNDER_NEW_TH2_get_under_field_err_thl(data)                   (0x000003FF&(data))


#define UNDER_NEW_TH3                                                 0x180191c4
#define UNDER_NEW_TH3_reg_addr                                        "0xb80191c4"
#define UNDER_NEW_TH3_reg                                             0xb80191c4
#define UNDER_NEW_TH3_inst_addr                                       "0x0071"
#define UNDER_NEW_TH3_inst                                            0x0071
#define UNDER_NEW_TH3_under_debounce_thl_shift                        (12)
#define UNDER_NEW_TH3_under_debounce_max_shift                        (0)
#define UNDER_NEW_TH3_under_debounce_thl_mask                         (0x003FF000)
#define UNDER_NEW_TH3_under_debounce_max_mask                         (0x000003FF)
#define UNDER_NEW_TH3_under_debounce_thl(data)                        (0x003FF000&((data)<<12))
#define UNDER_NEW_TH3_under_debounce_max(data)                        (0x000003FF&(data))
#define UNDER_NEW_TH3_get_under_debounce_thl(data)                    ((0x003FF000&(data))>>12)
#define UNDER_NEW_TH3_get_under_debounce_max(data)                    (0x000003FF&(data))


#define DC_COCH_SEPERATE_1                                            0x180191c8
#define DC_COCH_SEPERATE_1_reg_addr                                   "0xb80191c8"
#define DC_COCH_SEPERATE_1_reg                                        0xb80191c8
#define DC_COCH_SEPERATE_1_inst_addr                                  "0x0072"
#define DC_COCH_SEPERATE_1_inst                                       0x0072
#define DC_COCH_SEPERATE_1_coch_detected_by_check_dc_shift            (31)
#define DC_COCH_SEPERATE_1_coch_avg_line1_diff_thre_up_shift          (12)
#define DC_COCH_SEPERATE_1_coch_avg_line1_diff_thre_lo_shift          (0)
#define DC_COCH_SEPERATE_1_coch_detected_by_check_dc_mask             (0x80000000)
#define DC_COCH_SEPERATE_1_coch_avg_line1_diff_thre_up_mask           (0x00FFF000)
#define DC_COCH_SEPERATE_1_coch_avg_line1_diff_thre_lo_mask           (0x00000FFF)
#define DC_COCH_SEPERATE_1_coch_detected_by_check_dc(data)            (0x80000000&((data)<<31))
#define DC_COCH_SEPERATE_1_coch_avg_line1_diff_thre_up(data)          (0x00FFF000&((data)<<12))
#define DC_COCH_SEPERATE_1_coch_avg_line1_diff_thre_lo(data)          (0x00000FFF&(data))
#define DC_COCH_SEPERATE_1_get_coch_detected_by_check_dc(data)        ((0x80000000&(data))>>31)
#define DC_COCH_SEPERATE_1_get_coch_avg_line1_diff_thre_up(data)      ((0x00FFF000&(data))>>12)
#define DC_COCH_SEPERATE_1_get_coch_avg_line1_diff_thre_lo(data)      (0x00000FFF&(data))


#define DC_COCH_SEPERATE_2                                            0x180191cc
#define DC_COCH_SEPERATE_2_reg_addr                                   "0xb80191cc"
#define DC_COCH_SEPERATE_2_reg                                        0xb80191cc
#define DC_COCH_SEPERATE_2_inst_addr                                  "0x0073"
#define DC_COCH_SEPERATE_2_inst                                       0x0073
#define DC_COCH_SEPERATE_2_coch_detect_lpf_reset_shift                (31)
#define DC_COCH_SEPERATE_2_coch_detect_counter_up_thre_shift          (12)
#define DC_COCH_SEPERATE_2_coch_detect_counter_lo_thre_shift          (0)
#define DC_COCH_SEPERATE_2_coch_detect_lpf_reset_mask                 (0x80000000)
#define DC_COCH_SEPERATE_2_coch_detect_counter_up_thre_mask           (0x003FF000)
#define DC_COCH_SEPERATE_2_coch_detect_counter_lo_thre_mask           (0x000003FF)
#define DC_COCH_SEPERATE_2_coch_detect_lpf_reset(data)                (0x80000000&((data)<<31))
#define DC_COCH_SEPERATE_2_coch_detect_counter_up_thre(data)          (0x003FF000&((data)<<12))
#define DC_COCH_SEPERATE_2_coch_detect_counter_lo_thre(data)          (0x000003FF&(data))
#define DC_COCH_SEPERATE_2_get_coch_detect_lpf_reset(data)            ((0x80000000&(data))>>31)
#define DC_COCH_SEPERATE_2_get_coch_detect_counter_up_thre(data)      ((0x003FF000&(data))>>12)
#define DC_COCH_SEPERATE_2_get_coch_detect_counter_lo_thre(data)      (0x000003FF&(data))


#define HSYNC_RISING                                                  0x180191d0
#define HSYNC_RISING_reg_addr                                         "0xb80191d0"
#define HSYNC_RISING_reg                                              0xb80191d0
#define HSYNC_RISING_inst_addr                                        "0x0074"
#define HSYNC_RISING_inst                                             0x0074
#define HSYNC_RISING_hsync_rising_shift                               (0)
#define HSYNC_RISING_hsync_rising_mask                                (0x000000FF)
#define HSYNC_RISING_hsync_rising(data)                               (0x000000FF&(data))
#define HSYNC_RISING_get_hsync_rising(data)                           (0x000000FF&(data))


#define HSYNC_PHASE_OFFSET                                            0x180191d4
#define HSYNC_PHASE_OFFSET_reg_addr                                   "0xb80191d4"
#define HSYNC_PHASE_OFFSET_reg                                        0xb80191d4
#define HSYNC_PHASE_OFFSET_inst_addr                                  "0x0075"
#define HSYNC_PHASE_OFFSET_inst                                       0x0075
#define HSYNC_PHASE_OFFSET_hsync_phase_offset_shift                   (0)
#define HSYNC_PHASE_OFFSET_hsync_phase_offset_mask                    (0x000000FF)
#define HSYNC_PHASE_OFFSET_hsync_phase_offset(data)                   (0x000000FF&(data))
#define HSYNC_PHASE_OFFSET_get_hsync_phase_offset(data)               (0x000000FF&(data))


#define HSYNC_GATE_START                                              0x180191d8
#define HSYNC_GATE_START_reg_addr                                     "0xb80191d8"
#define HSYNC_GATE_START_reg                                          0xb80191d8
#define HSYNC_GATE_START_inst_addr                                    "0x0076"
#define HSYNC_GATE_START_inst                                         0x0076
#define HSYNC_GATE_START_hsync_gate_start_shift                       (0)
#define HSYNC_GATE_START_hsync_gate_start_mask                        (0x000000FF)
#define HSYNC_GATE_START_hsync_gate_start(data)                       (0x000000FF&(data))
#define HSYNC_GATE_START_get_hsync_gate_start(data)                   (0x000000FF&(data))


#define HSYNC_GATE_END                                                0x180191dc
#define HSYNC_GATE_END_reg_addr                                       "0xb80191dc"
#define HSYNC_GATE_END_reg                                            0xb80191dc
#define HSYNC_GATE_END_inst_addr                                      "0x0077"
#define HSYNC_GATE_END_inst                                           0x0077
#define HSYNC_GATE_END_hsync_gate_end_shift                           (0)
#define HSYNC_GATE_END_hsync_gate_end_mask                            (0x000000FF)
#define HSYNC_GATE_END_hsync_gate_end(data)                           (0x000000FF&(data))
#define HSYNC_GATE_END_get_hsync_gate_end(data)                       (0x000000FF&(data))


#define HSYNC_TIP_START                                               0x180191e0
#define HSYNC_TIP_START_reg_addr                                      "0xb80191e0"
#define HSYNC_TIP_START_reg                                           0xb80191e0
#define HSYNC_TIP_START_inst_addr                                     "0x0078"
#define HSYNC_TIP_START_inst                                          0x0078
#define HSYNC_TIP_START_hsync_tip_start_shift                         (0)
#define HSYNC_TIP_START_hsync_tip_start_mask                          (0x000000FF)
#define HSYNC_TIP_START_hsync_tip_start(data)                         (0x000000FF&(data))
#define HSYNC_TIP_START_get_hsync_tip_start(data)                     (0x000000FF&(data))


#define HSYNC_TIP_END                                                 0x180191e4
#define HSYNC_TIP_END_reg_addr                                        "0xb80191e4"
#define HSYNC_TIP_END_reg                                             0xb80191e4
#define HSYNC_TIP_END_inst_addr                                       "0x0079"
#define HSYNC_TIP_END_inst                                            0x0079
#define HSYNC_TIP_END_hsync_tip_end_shift                             (0)
#define HSYNC_TIP_END_hsync_tip_end_mask                              (0x000000FF)
#define HSYNC_TIP_END_hsync_tip_end(data)                             (0x000000FF&(data))
#define HSYNC_TIP_END_get_hsync_tip_end(data)                         (0x000000FF&(data))


#define HSYNC_RISING_START                                            0x180191e8
#define HSYNC_RISING_START_reg_addr                                   "0xb80191e8"
#define HSYNC_RISING_START_reg                                        0xb80191e8
#define HSYNC_RISING_START_inst_addr                                  "0x007A"
#define HSYNC_RISING_START_inst                                       0x007A
#define HSYNC_RISING_START_hsync_rising_start_shift                   (0)
#define HSYNC_RISING_START_hsync_rising_start_mask                    (0x000000FF)
#define HSYNC_RISING_START_hsync_rising_start(data)                   (0x000000FF&(data))
#define HSYNC_RISING_START_get_hsync_rising_start(data)               (0x000000FF&(data))


#define HSYNC_RISING_END                                              0x180191ec
#define HSYNC_RISING_END_reg_addr                                     "0xb80191ec"
#define HSYNC_RISING_END_reg                                          0xb80191ec
#define HSYNC_RISING_END_inst_addr                                    "0x007B"
#define HSYNC_RISING_END_inst                                         0x007B
#define HSYNC_RISING_END_hsync_rising_end_shift                       (0)
#define HSYNC_RISING_END_hsync_rising_end_mask                        (0x000000FF)
#define HSYNC_RISING_END_hsync_rising_end(data)                       (0x000000FF&(data))
#define HSYNC_RISING_END_get_hsync_rising_end(data)                   (0x000000FF&(data))


#define BACKPROCH_START                                               0x180191f0
#define BACKPROCH_START_reg_addr                                      "0xb80191f0"
#define BACKPROCH_START_reg                                           0xb80191f0
#define BACKPROCH_START_inst_addr                                     "0x007C"
#define BACKPROCH_START_inst                                          0x007C
#define BACKPROCH_START_backporch_start_shift                         (0)
#define BACKPROCH_START_backporch_start_mask                          (0x000000FF)
#define BACKPROCH_START_backporch_start(data)                         (0x000000FF&(data))
#define BACKPROCH_START_get_backporch_start(data)                     (0x000000FF&(data))


#define BACKPORCH_END                                                 0x180191f4
#define BACKPORCH_END_reg_addr                                        "0xb80191f4"
#define BACKPORCH_END_reg                                             0xb80191f4
#define BACKPORCH_END_inst_addr                                       "0x007D"
#define BACKPORCH_END_inst                                            0x007D
#define BACKPORCH_END_backporch_end_shift                             (0)
#define BACKPORCH_END_backporch_end_mask                              (0x000000FF)
#define BACKPORCH_END_backporch_end(data)                             (0x000000FF&(data))
#define BACKPORCH_END_get_backporch_end(data)                         (0x000000FF&(data))


#define HBLANK_START                                                  0x180191f8
#define HBLANK_START_reg_addr                                         "0xb80191f8"
#define HBLANK_START_reg                                              0xb80191f8
#define HBLANK_START_inst_addr                                        "0x007E"
#define HBLANK_START_inst                                             0x007E
#define HBLANK_START_hblank_start_shift                               (0)
#define HBLANK_START_hblank_start_mask                                (0x000000FF)
#define HBLANK_START_hblank_start(data)                               (0x000000FF&(data))
#define HBLANK_START_get_hblank_start(data)                           (0x000000FF&(data))


#define HBLANK_END                                                    0x180191fc
#define HBLANK_END_reg_addr                                           "0xb80191fc"
#define HBLANK_END_reg                                                0xb80191fc
#define HBLANK_END_inst_addr                                          "0x007F"
#define HBLANK_END_inst                                               0x007F
#define HBLANK_END_hblank_end_shift                                   (0)
#define HBLANK_END_hblank_end_mask                                    (0x000000FF)
#define HBLANK_END_hblank_end(data)                                   (0x000000FF&(data))
#define HBLANK_END_get_hblank_end(data)                               (0x000000FF&(data))


#define BURST_GATE_START                                              0x18019200
#define BURST_GATE_START_reg_addr                                     "0xb8019200"
#define BURST_GATE_START_reg                                          0xb8019200
#define BURST_GATE_START_inst_addr                                    "0x0080"
#define BURST_GATE_START_inst                                         0x0080
#define BURST_GATE_START_burst_gate_start_shift                       (0)
#define BURST_GATE_START_burst_gate_start_mask                        (0x000000FF)
#define BURST_GATE_START_burst_gate_start(data)                       (0x000000FF&(data))
#define BURST_GATE_START_get_burst_gate_start(data)                   (0x000000FF&(data))


#define BURST_GATE_END                                                0x18019204
#define BURST_GATE_END_reg_addr                                       "0xb8019204"
#define BURST_GATE_END_reg                                            0xb8019204
#define BURST_GATE_END_inst_addr                                      "0x0081"
#define BURST_GATE_END_inst                                           0x0081
#define BURST_GATE_END_burst_gate_end_shift                           (0)
#define BURST_GATE_END_burst_gate_end_mask                            (0x000000FF)
#define BURST_GATE_END_burst_gate_end(data)                           (0x000000FF&(data))
#define BURST_GATE_END_get_burst_gate_end(data)                       (0x000000FF&(data))


#define HACTIVE_START                                                 0x18019208
#define HACTIVE_START_reg_addr                                        "0xb8019208"
#define HACTIVE_START_reg                                             0xb8019208
#define HACTIVE_START_inst_addr                                       "0x0082"
#define HACTIVE_START_inst                                            0x0082
#define HACTIVE_START_hactive_start_shift                             (0)
#define HACTIVE_START_hactive_start_mask                              (0x000000FF)
#define HACTIVE_START_hactive_start(data)                             (0x000000FF&(data))
#define HACTIVE_START_get_hactive_start(data)                         (0x000000FF&(data))


#define HACTIVE_WIDTH                                                 0x1801920c
#define HACTIVE_WIDTH_reg_addr                                        "0xb801920c"
#define HACTIVE_WIDTH_reg                                             0xb801920c
#define HACTIVE_WIDTH_inst_addr                                       "0x0083"
#define HACTIVE_WIDTH_inst                                            0x0083
#define HACTIVE_WIDTH_hactive_width_shift                             (0)
#define HACTIVE_WIDTH_hactive_width_mask                              (0x000000FF)
#define HACTIVE_WIDTH_hactive_width(data)                             (0x000000FF&(data))
#define HACTIVE_WIDTH_get_hactive_width(data)                         (0x000000FF&(data))


#define HDETECT_ERR_TH1                                               0x18019210
#define HDETECT_ERR_TH1_reg_addr                                      "0xb8019210"
#define HDETECT_ERR_TH1_reg                                           0xb8019210
#define HDETECT_ERR_TH1_inst_addr                                     "0x0084"
#define HDETECT_ERR_TH1_inst                                          0x0084
#define HDETECT_ERR_TH1_hdetect_hstate_phase_max_en_shift             (31)
#define HDETECT_ERR_TH1_hdetect_hstate_3_phase_max_shift              (16)
#define HDETECT_ERR_TH1_hdetect_hstate_4_phase_max_shift              (0)
#define HDETECT_ERR_TH1_hdetect_hstate_phase_max_en_mask              (0x80000000)
#define HDETECT_ERR_TH1_hdetect_hstate_3_phase_max_mask               (0x1FFF0000)
#define HDETECT_ERR_TH1_hdetect_hstate_4_phase_max_mask               (0x00001FFF)
#define HDETECT_ERR_TH1_hdetect_hstate_phase_max_en(data)             (0x80000000&((data)<<31))
#define HDETECT_ERR_TH1_hdetect_hstate_3_phase_max(data)              (0x1FFF0000&((data)<<16))
#define HDETECT_ERR_TH1_hdetect_hstate_4_phase_max(data)              (0x00001FFF&(data))
#define HDETECT_ERR_TH1_get_hdetect_hstate_phase_max_en(data)         ((0x80000000&(data))>>31)
#define HDETECT_ERR_TH1_get_hdetect_hstate_3_phase_max(data)          ((0x1FFF0000&(data))>>16)
#define HDETECT_ERR_TH1_get_hdetect_hstate_4_phase_max(data)          (0x00001FFF&(data))


#define HDETECT_ERR_TH2                                               0x18019214
#define HDETECT_ERR_TH2_reg_addr                                      "0xb8019214"
#define HDETECT_ERR_TH2_reg                                           0xb8019214
#define HDETECT_ERR_TH2_inst_addr                                     "0x0085"
#define HDETECT_ERR_TH2_inst                                          0x0085
#define HDETECT_ERR_TH2_hdetect_hstate_5_phase_max_shift              (16)
#define HDETECT_ERR_TH2_hdetect_err04_th_shift                        (8)
#define HDETECT_ERR_TH2_hdetect_err00_th_shift                        (0)
#define HDETECT_ERR_TH2_hdetect_hstate_5_phase_max_mask               (0x1FFF0000)
#define HDETECT_ERR_TH2_hdetect_err04_th_mask                         (0x0000FF00)
#define HDETECT_ERR_TH2_hdetect_err00_th_mask                         (0x000000FF)
#define HDETECT_ERR_TH2_hdetect_hstate_5_phase_max(data)              (0x1FFF0000&((data)<<16))
#define HDETECT_ERR_TH2_hdetect_err04_th(data)                        (0x0000FF00&((data)<<8))
#define HDETECT_ERR_TH2_hdetect_err00_th(data)                        (0x000000FF&(data))
#define HDETECT_ERR_TH2_get_hdetect_hstate_5_phase_max(data)          ((0x1FFF0000&(data))>>16)
#define HDETECT_ERR_TH2_get_hdetect_err04_th(data)                    ((0x0000FF00&(data))>>8)
#define HDETECT_ERR_TH2_get_hdetect_err00_th(data)                    (0x000000FF&(data))


#define CSTATE_STATUS                                                 0x18019218
#define CSTATE_STATUS_reg_addr                                        "0xb8019218"
#define CSTATE_STATUS_reg                                             0xb8019218
#define CSTATE_STATUS_inst_addr                                       "0x0086"
#define CSTATE_STATUS_inst                                            0x0086
#define CSTATE_STATUS_cpll_use_fine_or_final_hlock_shift              (8)
#define CSTATE_STATUS_new_c_state_i_shift                             (7)
#define CSTATE_STATUS_new_cstate_shift                                (6)
#define CSTATE_STATUS_cstate_cntl_shift                               (4)
#define CSTATE_STATUS_cstate_status_shift                             (0)
#define CSTATE_STATUS_cpll_use_fine_or_final_hlock_mask               (0x00000100)
#define CSTATE_STATUS_new_c_state_i_mask                              (0x00000080)
#define CSTATE_STATUS_new_cstate_mask                                 (0x00000040)
#define CSTATE_STATUS_cstate_cntl_mask                                (0x00000030)
#define CSTATE_STATUS_cstate_status_mask                              (0x00000007)
#define CSTATE_STATUS_cpll_use_fine_or_final_hlock(data)              (0x00000100&((data)<<8))
#define CSTATE_STATUS_new_c_state_i(data)                             (0x00000080&((data)<<7))
#define CSTATE_STATUS_new_cstate(data)                                (0x00000040&((data)<<6))
#define CSTATE_STATUS_cstate_cntl(data)                               (0x00000030&((data)<<4))
#define CSTATE_STATUS_cstate_status(data)                             (0x00000007&(data))
#define CSTATE_STATUS_get_cpll_use_fine_or_final_hlock(data)          ((0x00000100&(data))>>8)
#define CSTATE_STATUS_get_new_c_state_i(data)                         ((0x00000080&(data))>>7)
#define CSTATE_STATUS_get_new_cstate(data)                            ((0x00000040&(data))>>6)
#define CSTATE_STATUS_get_cstate_cntl(data)                           ((0x00000030&(data))>>4)
#define CSTATE_STATUS_get_cstate_status(data)                         (0x00000007&(data))


#define HDETECT_GATE_CTRL                                             0x1801921c
#define HDETECT_GATE_CTRL_reg_addr                                    "0xb801921c"
#define HDETECT_GATE_CTRL_reg                                         0xb801921c
#define HDETECT_GATE_CTRL_inst_addr                                   "0x0087"
#define HDETECT_GATE_CTRL_inst                                        0x0087
#define HDETECT_GATE_CTRL_s_b_level_fir_en_shift                      (18)
#define HDETECT_GATE_CTRL_level_fir_num_32_64_blevel_shift            (17)
#define HDETECT_GATE_CTRL_level_fir_num_32_64_slevel_shift            (16)
#define HDETECT_GATE_CTRL_coef_syncmidpt_fir_in_shift                 (8)
#define HDETECT_GATE_CTRL_new_hpll_lpf_sel_shift                      (2)
#define HDETECT_GATE_CTRL_gate_iir_h_sel_shift                        (1)
#define HDETECT_GATE_CTRL_gate_iir_v_sel_shift                        (0)
#define HDETECT_GATE_CTRL_s_b_level_fir_en_mask                       (0x00040000)
#define HDETECT_GATE_CTRL_level_fir_num_32_64_blevel_mask             (0x00020000)
#define HDETECT_GATE_CTRL_level_fir_num_32_64_slevel_mask             (0x00010000)
#define HDETECT_GATE_CTRL_coef_syncmidpt_fir_in_mask                  (0x0000FF00)
#define HDETECT_GATE_CTRL_new_hpll_lpf_sel_mask                       (0x00000004)
#define HDETECT_GATE_CTRL_gate_iir_h_sel_mask                         (0x00000002)
#define HDETECT_GATE_CTRL_gate_iir_v_sel_mask                         (0x00000001)
#define HDETECT_GATE_CTRL_s_b_level_fir_en(data)                      (0x00040000&((data)<<18))
#define HDETECT_GATE_CTRL_level_fir_num_32_64_blevel(data)            (0x00020000&((data)<<17))
#define HDETECT_GATE_CTRL_level_fir_num_32_64_slevel(data)            (0x00010000&((data)<<16))
#define HDETECT_GATE_CTRL_coef_syncmidpt_fir_in(data)                 (0x0000FF00&((data)<<8))
#define HDETECT_GATE_CTRL_new_hpll_lpf_sel(data)                      (0x00000004&((data)<<2))
#define HDETECT_GATE_CTRL_gate_iir_h_sel(data)                        (0x00000002&((data)<<1))
#define HDETECT_GATE_CTRL_gate_iir_v_sel(data)                        (0x00000001&(data))
#define HDETECT_GATE_CTRL_get_s_b_level_fir_en(data)                  ((0x00040000&(data))>>18)
#define HDETECT_GATE_CTRL_get_level_fir_num_32_64_blevel(data)        ((0x00020000&(data))>>17)
#define HDETECT_GATE_CTRL_get_level_fir_num_32_64_slevel(data)        ((0x00010000&(data))>>16)
#define HDETECT_GATE_CTRL_get_coef_syncmidpt_fir_in(data)             ((0x0000FF00&(data))>>8)
#define HDETECT_GATE_CTRL_get_new_hpll_lpf_sel(data)                  ((0x00000004&(data))>>2)
#define HDETECT_GATE_CTRL_get_gate_iir_h_sel(data)                    ((0x00000002&(data))>>1)
#define HDETECT_GATE_CTRL_get_gate_iir_v_sel(data)                    (0x00000001&(data))


#define HDETECT_GATE_COEF1                                            0x18019220
#define HDETECT_GATE_COEF1_reg_addr                                   "0xb8019220"
#define HDETECT_GATE_COEF1_reg                                        0xb8019220
#define HDETECT_GATE_COEF1_inst_addr                                  "0x0088"
#define HDETECT_GATE_COEF1_inst                                       0x0088
#define HDETECT_GATE_COEF1_headswitch_err_sel_shift                   (10)
#define HDETECT_GATE_COEF1_hsync_refind_mask_err_shift                (9)
#define HDETECT_GATE_COEF1_hsync_refind_shift                         (8)
#define HDETECT_GATE_COEF1_gate_iir_coef1_shift                       (0)
#define HDETECT_GATE_COEF1_headswitch_err_sel_mask                    (0x00000C00)
#define HDETECT_GATE_COEF1_hsync_refind_mask_err_mask                 (0x00000200)
#define HDETECT_GATE_COEF1_hsync_refind_mask                          (0x00000100)
#define HDETECT_GATE_COEF1_gate_iir_coef1_mask                        (0x000000FF)
#define HDETECT_GATE_COEF1_headswitch_err_sel(data)                   (0x00000C00&((data)<<10))
#define HDETECT_GATE_COEF1_hsync_refind_mask_err(data)                (0x00000200&((data)<<9))
#define HDETECT_GATE_COEF1_hsync_refind(data)                         (0x00000100&((data)<<8))
#define HDETECT_GATE_COEF1_gate_iir_coef1(data)                       (0x000000FF&(data))
#define HDETECT_GATE_COEF1_get_headswitch_err_sel(data)               ((0x00000C00&(data))>>10)
#define HDETECT_GATE_COEF1_get_hsync_refind_mask_err(data)            ((0x00000200&(data))>>9)
#define HDETECT_GATE_COEF1_get_hsync_refind(data)                     ((0x00000100&(data))>>8)
#define HDETECT_GATE_COEF1_get_gate_iir_coef1(data)                   (0x000000FF&(data))


#define HDETECT_GATE_COEF2                                            0x18019224
#define HDETECT_GATE_COEF2_reg_addr                                   "0xb8019224"
#define HDETECT_GATE_COEF2_reg                                        0xb8019224
#define HDETECT_GATE_COEF2_inst_addr                                  "0x0089"
#define HDETECT_GATE_COEF2_inst                                       0x0089
#define HDETECT_GATE_COEF2_hdetect_err07_th_shift                     (8)
#define HDETECT_GATE_COEF2_gate_iir_coef2_shift                       (0)
#define HDETECT_GATE_COEF2_hdetect_err07_th_mask                      (0x0000FF00)
#define HDETECT_GATE_COEF2_gate_iir_coef2_mask                        (0x000000FF)
#define HDETECT_GATE_COEF2_hdetect_err07_th(data)                     (0x0000FF00&((data)<<8))
#define HDETECT_GATE_COEF2_gate_iir_coef2(data)                       (0x000000FF&(data))
#define HDETECT_GATE_COEF2_get_hdetect_err07_th(data)                 ((0x0000FF00&(data))>>8)
#define HDETECT_GATE_COEF2_get_gate_iir_coef2(data)                   (0x000000FF&(data))


#define HDETECT_VPHASE_STATUS                                         0x18019228
#define HDETECT_VPHASE_STATUS_reg_addr                                "0xb8019228"
#define HDETECT_VPHASE_STATUS_reg                                     0xb8019228
#define HDETECT_VPHASE_STATUS_inst_addr                               "0x008A"
#define HDETECT_VPHASE_STATUS_inst                                    0x008A
#define HDETECT_VPHASE_STATUS_hstate_err_thl_shift                    (16)
#define HDETECT_VPHASE_STATUS_hstate_err_counter_shift                (8)
#define HDETECT_VPHASE_STATUS_vphase_status_shift                     (0)
#define HDETECT_VPHASE_STATUS_hstate_err_thl_mask                     (0x3FFF0000)
#define HDETECT_VPHASE_STATUS_hstate_err_counter_mask                 (0x00000300)
#define HDETECT_VPHASE_STATUS_vphase_status_mask                      (0x000000FF)
#define HDETECT_VPHASE_STATUS_hstate_err_thl(data)                    (0x3FFF0000&((data)<<16))
#define HDETECT_VPHASE_STATUS_hstate_err_counter(data)                (0x00000300&((data)<<8))
#define HDETECT_VPHASE_STATUS_vphase_status(data)                     (0x000000FF&(data))
#define HDETECT_VPHASE_STATUS_get_hstate_err_thl(data)                ((0x3FFF0000&(data))>>16)
#define HDETECT_VPHASE_STATUS_get_hstate_err_counter(data)            ((0x00000300&(data))>>8)
#define HDETECT_VPHASE_STATUS_get_vphase_status(data)                 (0x000000FF&(data))


#define HDETECT_VPHASEDIFF_STATUS                                     0x1801922c
#define HDETECT_VPHASEDIFF_STATUS_reg_addr                            "0xb801922c"
#define HDETECT_VPHASEDIFF_STATUS_reg                                 0xb801922c
#define HDETECT_VPHASEDIFF_STATUS_inst_addr                           "0x008B"
#define HDETECT_VPHASEDIFF_STATUS_inst                                0x008B
#define HDETECT_VPHASEDIFF_STATUS_hdetect_err05_th_shift              (24)
#define HDETECT_VPHASEDIFF_STATUS_hdetect_err10_th_shift              (16)
#define HDETECT_VPHASEDIFF_STATUS_hdetect_err01_th_shift              (8)
#define HDETECT_VPHASEDIFF_STATUS_vphasediff_status_shift             (0)
#define HDETECT_VPHASEDIFF_STATUS_hdetect_err05_th_mask               (0xFF000000)
#define HDETECT_VPHASEDIFF_STATUS_hdetect_err10_th_mask               (0x00FF0000)
#define HDETECT_VPHASEDIFF_STATUS_hdetect_err01_th_mask               (0x0000FF00)
#define HDETECT_VPHASEDIFF_STATUS_vphasediff_status_mask              (0x000000FF)
#define HDETECT_VPHASEDIFF_STATUS_hdetect_err05_th(data)              (0xFF000000&((data)<<24))
#define HDETECT_VPHASEDIFF_STATUS_hdetect_err10_th(data)              (0x00FF0000&((data)<<16))
#define HDETECT_VPHASEDIFF_STATUS_hdetect_err01_th(data)              (0x0000FF00&((data)<<8))
#define HDETECT_VPHASEDIFF_STATUS_vphasediff_status(data)             (0x000000FF&(data))
#define HDETECT_VPHASEDIFF_STATUS_get_hdetect_err05_th(data)          ((0xFF000000&(data))>>24)
#define HDETECT_VPHASEDIFF_STATUS_get_hdetect_err10_th(data)          ((0x00FF0000&(data))>>16)
#define HDETECT_VPHASEDIFF_STATUS_get_hdetect_err01_th(data)          ((0x0000FF00&(data))>>8)
#define HDETECT_VPHASEDIFF_STATUS_get_vphasediff_status(data)         (0x000000FF&(data))


#define NOISE_VBI_THRESHOLD                                           0x18019230
#define NOISE_VBI_THRESHOLD_reg_addr                                  "0xb8019230"
#define NOISE_VBI_THRESHOLD_reg                                       0xb8019230
#define NOISE_VBI_THRESHOLD_inst_addr                                 "0x008C"
#define NOISE_VBI_THRESHOLD_inst                                      0x008C
#define NOISE_VBI_THRESHOLD_noise_vbi_thresh_shift                    (0)
#define NOISE_VBI_THRESHOLD_noise_vbi_thresh_mask                     (0x000000FF)
#define NOISE_VBI_THRESHOLD_noise_vbi_thresh(data)                    (0x000000FF&(data))
#define NOISE_VBI_THRESHOLD_get_noise_vbi_thresh(data)                (0x000000FF&(data))


#define VBI_CO_CH_CTRL0                                               0x18019234
#define VBI_CO_CH_CTRL0_reg_addr                                      "0xb8019234"
#define VBI_CO_CH_CTRL0_reg                                           0xb8019234
#define VBI_CO_CH_CTRL0_inst_addr                                     "0x008D"
#define VBI_CO_CH_CTRL0_inst                                          0x008D
#define VBI_CO_CH_CTRL0_coch_detected_status_shift                    (7)
#define VBI_CO_CH_CTRL0_coch_detected_frame_shift                     (0)
#define VBI_CO_CH_CTRL0_coch_detected_status_mask                     (0x00000080)
#define VBI_CO_CH_CTRL0_coch_detected_frame_mask                      (0x0000003F)
#define VBI_CO_CH_CTRL0_coch_detected_status(data)                    (0x00000080&((data)<<7))
#define VBI_CO_CH_CTRL0_coch_detected_frame(data)                     (0x0000003F&(data))
#define VBI_CO_CH_CTRL0_get_coch_detected_status(data)                ((0x00000080&(data))>>7)
#define VBI_CO_CH_CTRL0_get_coch_detected_frame(data)                 (0x0000003F&(data))


#define VBI_CO_CH_CTRL1                                               0x18019238
#define VBI_CO_CH_CTRL1_reg_addr                                      "0xb8019238"
#define VBI_CO_CH_CTRL1_reg                                           0xb8019238
#define VBI_CO_CH_CTRL1_inst_addr                                     "0x008E"
#define VBI_CO_CH_CTRL1_inst                                          0x008E
#define VBI_CO_CH_CTRL1_coch_bp_diff_th_shift                         (0)
#define VBI_CO_CH_CTRL1_coch_bp_diff_th_mask                          (0x0000000F)
#define VBI_CO_CH_CTRL1_coch_bp_diff_th(data)                         (0x0000000F&(data))
#define VBI_CO_CH_CTRL1_get_coch_bp_diff_th(data)                     (0x0000000F&(data))


#define VBI_CO_CH_CTRL2                                               0x1801923c
#define VBI_CO_CH_CTRL2_reg_addr                                      "0xb801923c"
#define VBI_CO_CH_CTRL2_reg                                           0xb801923c
#define VBI_CO_CH_CTRL2_inst_addr                                     "0x008F"
#define VBI_CO_CH_CTRL2_inst                                          0x008F
#define VBI_CO_CH_CTRL2_coch_line_count_th_shift                      (0)
#define VBI_CO_CH_CTRL2_coch_line_count_th_mask                       (0x000000FF)
#define VBI_CO_CH_CTRL2_coch_line_count_th(data)                      (0x000000FF&(data))
#define VBI_CO_CH_CTRL2_get_coch_line_count_th(data)                  (0x000000FF&(data))


#define MV_DETECT_WINDOW                                              0x18019240
#define MV_DETECT_WINDOW_reg_addr                                     "0xb8019240"
#define MV_DETECT_WINDOW_reg                                          0xb8019240
#define MV_DETECT_WINDOW_inst_addr                                    "0x0090"
#define MV_DETECT_WINDOW_inst                                         0x0090
#define MV_DETECT_WINDOW_mv_window2_value_shift                       (0)
#define MV_DETECT_WINDOW_mv_window2_value_mask                        (0x000000FF)
#define MV_DETECT_WINDOW_mv_window2_value(data)                       (0x000000FF&(data))
#define MV_DETECT_WINDOW_get_mv_window2_value(data)                   (0x000000FF&(data))


#define MV_BURSTGATE_START                                            0x18019244
#define MV_BURSTGATE_START_reg_addr                                   "0xb8019244"
#define MV_BURSTGATE_START_reg                                        0xb8019244
#define MV_BURSTGATE_START_inst_addr                                  "0x0091"
#define MV_BURSTGATE_START_inst                                       0x0091
#define MV_BURSTGATE_START_ad_burst_gate_start_shift                  (0)
#define MV_BURSTGATE_START_ad_burst_gate_start_mask                   (0x000000FF)
#define MV_BURSTGATE_START_ad_burst_gate_start(data)                  (0x000000FF&(data))
#define MV_BURSTGATE_START_get_ad_burst_gate_start(data)              (0x000000FF&(data))


#define MV_BURSTGATE_END                                              0x18019248
#define MV_BURSTGATE_END_reg_addr                                     "0xb8019248"
#define MV_BURSTGATE_END_reg                                          0xb8019248
#define MV_BURSTGATE_END_inst_addr                                    "0x0092"
#define MV_BURSTGATE_END_inst                                         0x0092
#define MV_BURSTGATE_END_ad_burst_gate_end_shift                      (0)
#define MV_BURSTGATE_END_ad_burst_gate_end_mask                       (0x000000FF)
#define MV_BURSTGATE_END_ad_burst_gate_end(data)                      (0x000000FF&(data))
#define MV_BURSTGATE_END_get_ad_burst_gate_end(data)                  (0x000000FF&(data))


#define COLORSTRIPE_CONTROL                                           0x1801924c
#define COLORSTRIPE_CONTROL_reg_addr                                  "0xb801924c"
#define COLORSTRIPE_CONTROL_reg                                       0xb801924c
#define COLORSTRIPE_CONTROL_inst_addr                                 "0x0093"
#define COLORSTRIPE_CONTROL_inst                                      0x0093
#define COLORSTRIPE_CONTROL_cstripe_detect_control_shift              (0)
#define COLORSTRIPE_CONTROL_cstripe_detect_control_mask               (0x00000007)
#define COLORSTRIPE_CONTROL_cstripe_detect_control(data)              (0x00000007&(data))
#define COLORSTRIPE_CONTROL_get_cstripe_detect_control(data)          (0x00000007&(data))


#define H_ERR_CONSTRAINT_1                                            0x18019250
#define H_ERR_CONSTRAINT_1_reg_addr                                   "0xb8019250"
#define H_ERR_CONSTRAINT_1_reg                                        0xb8019250
#define H_ERR_CONSTRAINT_1_inst_addr                                  "0x0094"
#define H_ERR_CONSTRAINT_1_inst                                       0x0094
#define H_ERR_CONSTRAINT_1_h_err_constraint_en_shift                  (31)
#define H_ERR_CONSTRAINT_1_h_err_constraint_high_th_shift             (16)
#define H_ERR_CONSTRAINT_1_h_err_constraint_low_th_shift              (0)
#define H_ERR_CONSTRAINT_1_h_err_constraint_en_mask                   (0x80000000)
#define H_ERR_CONSTRAINT_1_h_err_constraint_high_th_mask              (0x3FFF0000)
#define H_ERR_CONSTRAINT_1_h_err_constraint_low_th_mask               (0x00003FFF)
#define H_ERR_CONSTRAINT_1_h_err_constraint_en(data)                  (0x80000000&((data)<<31))
#define H_ERR_CONSTRAINT_1_h_err_constraint_high_th(data)             (0x3FFF0000&((data)<<16))
#define H_ERR_CONSTRAINT_1_h_err_constraint_low_th(data)              (0x00003FFF&(data))
#define H_ERR_CONSTRAINT_1_get_h_err_constraint_en(data)              ((0x80000000&(data))>>31)
#define H_ERR_CONSTRAINT_1_get_h_err_constraint_high_th(data)         ((0x3FFF0000&(data))>>16)
#define H_ERR_CONSTRAINT_1_get_h_err_constraint_low_th(data)          (0x00003FFF&(data))


#define H_ERR_CONSTRAINT_2                                            0x18019254
#define H_ERR_CONSTRAINT_2_reg_addr                                   "0xb8019254"
#define H_ERR_CONSTRAINT_2_reg                                        0xb8019254
#define H_ERR_CONSTRAINT_2_inst_addr                                  "0x0095"
#define H_ERR_CONSTRAINT_2_inst                                       0x0095
#define H_ERR_CONSTRAINT_2_h_err_constraint_hstate_shift              (13)
#define H_ERR_CONSTRAINT_2_h_err_constraint_val_shift                 (0)
#define H_ERR_CONSTRAINT_2_h_err_constraint_hstate_mask               (0x0000E000)
#define H_ERR_CONSTRAINT_2_h_err_constraint_val_mask                  (0x00001FFF)
#define H_ERR_CONSTRAINT_2_h_err_constraint_hstate(data)              (0x0000E000&((data)<<13))
#define H_ERR_CONSTRAINT_2_h_err_constraint_val(data)                 (0x00001FFF&(data))
#define H_ERR_CONSTRAINT_2_get_h_err_constraint_hstate(data)          ((0x0000E000&(data))>>13)
#define H_ERR_CONSTRAINT_2_get_h_err_constraint_val(data)             (0x00001FFF&(data))


#define H_RESTORE_HDTO_1                                              0x18019258
#define H_RESTORE_HDTO_1_reg_addr                                     "0xb8019258"
#define H_RESTORE_HDTO_1_reg                                          0xb8019258
#define H_RESTORE_HDTO_1_inst_addr                                    "0x0096"
#define H_RESTORE_HDTO_1_inst                                         0x0096
#define H_RESTORE_HDTO_1_hdetect_restore_hdto_en_shift                (31)
#define H_RESTORE_HDTO_1_hdetect_set_new_hdto_n_shift                 (28)
#define H_RESTORE_HDTO_1_hdetect_restore_hdto_status_shift            (27)
#define H_RESTORE_HDTO_1_hdetect_force_hdto_en_shift                  (26)
#define H_RESTORE_HDTO_1_hdetect_set_hdto_start_shift                 (16)
#define H_RESTORE_HDTO_1_hdetect_restore_vcr_enable_shift             (12)
#define H_RESTORE_HDTO_1_hdetect_save_stable_hdto_start_shift         (0)
#define H_RESTORE_HDTO_1_hdetect_restore_hdto_en_mask                 (0x80000000)
#define H_RESTORE_HDTO_1_hdetect_set_new_hdto_n_mask                  (0x70000000)
#define H_RESTORE_HDTO_1_hdetect_restore_hdto_status_mask             (0x08000000)
#define H_RESTORE_HDTO_1_hdetect_force_hdto_en_mask                   (0x04000000)
#define H_RESTORE_HDTO_1_hdetect_set_hdto_start_mask                  (0x03FF0000)
#define H_RESTORE_HDTO_1_hdetect_restore_vcr_enable_mask              (0x00001000)
#define H_RESTORE_HDTO_1_hdetect_save_stable_hdto_start_mask          (0x000003FF)
#define H_RESTORE_HDTO_1_hdetect_restore_hdto_en(data)                (0x80000000&((data)<<31))
#define H_RESTORE_HDTO_1_hdetect_set_new_hdto_n(data)                 (0x70000000&((data)<<28))
#define H_RESTORE_HDTO_1_hdetect_restore_hdto_status(data)            (0x08000000&((data)<<27))
#define H_RESTORE_HDTO_1_hdetect_force_hdto_en(data)                  (0x04000000&((data)<<26))
#define H_RESTORE_HDTO_1_hdetect_set_hdto_start(data)                 (0x03FF0000&((data)<<16))
#define H_RESTORE_HDTO_1_hdetect_restore_vcr_enable(data)             (0x00001000&((data)<<12))
#define H_RESTORE_HDTO_1_hdetect_save_stable_hdto_start(data)         (0x000003FF&(data))
#define H_RESTORE_HDTO_1_get_hdetect_restore_hdto_en(data)            ((0x80000000&(data))>>31)
#define H_RESTORE_HDTO_1_get_hdetect_set_new_hdto_n(data)             ((0x70000000&(data))>>28)
#define H_RESTORE_HDTO_1_get_hdetect_restore_hdto_status(data)        ((0x08000000&(data))>>27)
#define H_RESTORE_HDTO_1_get_hdetect_force_hdto_en(data)              ((0x04000000&(data))>>26)
#define H_RESTORE_HDTO_1_get_hdetect_set_hdto_start(data)             ((0x03FF0000&(data))>>16)
#define H_RESTORE_HDTO_1_get_hdetect_restore_vcr_enable(data)         ((0x00001000&(data))>>12)
#define H_RESTORE_HDTO_1_get_hdetect_save_stable_hdto_start(data)     (0x000003FF&(data))


#define H_RESTORE_HDTO_2                                              0x1801925c
#define H_RESTORE_HDTO_2_reg_addr                                     "0xb801925c"
#define H_RESTORE_HDTO_2_reg                                          0xb801925c
#define H_RESTORE_HDTO_2_inst_addr                                    "0x0097"
#define H_RESTORE_HDTO_2_inst                                         0x0097
#define H_RESTORE_HDTO_2_hdetect_set_hdto_phase_err_th_shift          (0)
#define H_RESTORE_HDTO_2_hdetect_set_hdto_phase_err_th_mask           (0x00003FFF)
#define H_RESTORE_HDTO_2_hdetect_set_hdto_phase_err_th(data)          (0x00003FFF&(data))
#define H_RESTORE_HDTO_2_get_hdetect_set_hdto_phase_err_th(data)      (0x00003FFF&(data))


#define IF_WRONG_PC                                                   0x18019260
#define IF_WRONG_PC_reg_addr                                          "0xb8019260"
#define IF_WRONG_PC_reg                                               0xb8019260
#define IF_WRONG_PC_inst_addr                                         "0x0098"
#define IF_WRONG_PC_inst                                              0x0098
#define IF_WRONG_PC_wrong_if_pc_detect_th_shift                       (24)
#define IF_WRONG_PC_sync_level_manu_shift                             (16)
#define IF_WRONG_PC_sync_level_manu_en_shift                          (8)
#define IF_WRONG_PC_wrong_if_pc_detect_shift                          (0)
#define IF_WRONG_PC_wrong_if_pc_detect_th_mask                        (0xFF000000)
#define IF_WRONG_PC_sync_level_manu_mask                              (0x00FF0000)
#define IF_WRONG_PC_sync_level_manu_en_mask                           (0x00000100)
#define IF_WRONG_PC_wrong_if_pc_detect_mask                           (0x00000001)
#define IF_WRONG_PC_wrong_if_pc_detect_th(data)                       (0xFF000000&((data)<<24))
#define IF_WRONG_PC_sync_level_manu(data)                             (0x00FF0000&((data)<<16))
#define IF_WRONG_PC_sync_level_manu_en(data)                          (0x00000100&((data)<<8))
#define IF_WRONG_PC_wrong_if_pc_detect(data)                          (0x00000001&(data))
#define IF_WRONG_PC_get_wrong_if_pc_detect_th(data)                   ((0xFF000000&(data))>>24)
#define IF_WRONG_PC_get_sync_level_manu(data)                         ((0x00FF0000&(data))>>16)
#define IF_WRONG_PC_get_sync_level_manu_en(data)                      ((0x00000100&(data))>>8)
#define IF_WRONG_PC_get_wrong_if_pc_detect(data)                      (0x00000001&(data))


#define CPLL_STABILITY_OBSERVE_1                                      0x18019264
#define CPLL_STABILITY_OBSERVE_1_reg_addr                             "0xb8019264"
#define CPLL_STABILITY_OBSERVE_1_reg                                  0xb8019264
#define CPLL_STABILITY_OBSERVE_1_inst_addr                            "0x0099"
#define CPLL_STABILITY_OBSERVE_1_inst                                 0x0099
#define CPLL_STABILITY_OBSERVE_1_cpll_phase_thr_up_shift              (16)
#define CPLL_STABILITY_OBSERVE_1_cpll_phase_thr_dn_shift              (0)
#define CPLL_STABILITY_OBSERVE_1_cpll_phase_thr_up_mask               (0x3FFF0000)
#define CPLL_STABILITY_OBSERVE_1_cpll_phase_thr_dn_mask               (0x00003FFF)
#define CPLL_STABILITY_OBSERVE_1_cpll_phase_thr_up(data)              (0x3FFF0000&((data)<<16))
#define CPLL_STABILITY_OBSERVE_1_cpll_phase_thr_dn(data)              (0x00003FFF&(data))
#define CPLL_STABILITY_OBSERVE_1_get_cpll_phase_thr_up(data)          ((0x3FFF0000&(data))>>16)
#define CPLL_STABILITY_OBSERVE_1_get_cpll_phase_thr_dn(data)          (0x00003FFF&(data))


#define CPLL_STABILITY_OBSERVE_2                                      0x18019268
#define CPLL_STABILITY_OBSERVE_2_reg_addr                             "0xb8019268"
#define CPLL_STABILITY_OBSERVE_2_reg                                  0xb8019268
#define CPLL_STABILITY_OBSERVE_2_inst_addr                            "0x009A"
#define CPLL_STABILITY_OBSERVE_2_inst                                 0x009A
#define CPLL_STABILITY_OBSERVE_2_cpll_ampl_thr_shift                  (24)
#define CPLL_STABILITY_OBSERVE_2_cerror_continune_same_sign_thr_shift (16)
#define CPLL_STABILITY_OBSERVE_2_cpll_ampl_neg_flag_shift             (2)
#define CPLL_STABILITY_OBSERVE_2_cpll_phase_small_flag_shift          (1)
#define CPLL_STABILITY_OBSERVE_2_cpll_stable_flag_shift               (0)
#define CPLL_STABILITY_OBSERVE_2_cpll_ampl_thr_mask                   (0x7F000000)
#define CPLL_STABILITY_OBSERVE_2_cerror_continune_same_sign_thr_mask  (0x003F0000)
#define CPLL_STABILITY_OBSERVE_2_cpll_ampl_neg_flag_mask              (0x00000004)
#define CPLL_STABILITY_OBSERVE_2_cpll_phase_small_flag_mask           (0x00000002)
#define CPLL_STABILITY_OBSERVE_2_cpll_stable_flag_mask                (0x00000001)
#define CPLL_STABILITY_OBSERVE_2_cpll_ampl_thr(data)                  (0x7F000000&((data)<<24))
#define CPLL_STABILITY_OBSERVE_2_cerror_continune_same_sign_thr(data) (0x003F0000&((data)<<16))
#define CPLL_STABILITY_OBSERVE_2_cpll_ampl_neg_flag(data)             (0x00000004&((data)<<2))
#define CPLL_STABILITY_OBSERVE_2_cpll_phase_small_flag(data)          (0x00000002&((data)<<1))
#define CPLL_STABILITY_OBSERVE_2_cpll_stable_flag(data)               (0x00000001&(data))
#define CPLL_STABILITY_OBSERVE_2_get_cpll_ampl_thr(data)              ((0x7F000000&(data))>>24)
#define CPLL_STABILITY_OBSERVE_2_get_cerror_continune_same_sign_thr(data)  ((0x003F0000&(data))>>16)
#define CPLL_STABILITY_OBSERVE_2_get_cpll_ampl_neg_flag(data)         ((0x00000004&(data))>>2)
#define CPLL_STABILITY_OBSERVE_2_get_cpll_phase_small_flag(data)      ((0x00000002&(data))>>1)
#define CPLL_STABILITY_OBSERVE_2_get_cpll_stable_flag(data)           (0x00000001&(data))


#define CPLL_STABILITY_OBSERVE_3                                      0x1801926c
#define CPLL_STABILITY_OBSERVE_3_reg_addr                             "0xb801926c"
#define CPLL_STABILITY_OBSERVE_3_reg                                  0xb801926c
#define CPLL_STABILITY_OBSERVE_3_inst_addr                            "0x009B"
#define CPLL_STABILITY_OBSERVE_3_inst                                 0x009B
#define CPLL_STABILITY_OBSERVE_3_ampl_out_line_iir_shift              (16)
#define CPLL_STABILITY_OBSERVE_3_phase_out_line_iir_shift             (0)
#define CPLL_STABILITY_OBSERVE_3_ampl_out_line_iir_mask               (0x3FFF0000)
#define CPLL_STABILITY_OBSERVE_3_phase_out_line_iir_mask              (0x00003FFF)
#define CPLL_STABILITY_OBSERVE_3_ampl_out_line_iir(data)              (0x3FFF0000&((data)<<16))
#define CPLL_STABILITY_OBSERVE_3_phase_out_line_iir(data)             (0x00003FFF&(data))
#define CPLL_STABILITY_OBSERVE_3_get_ampl_out_line_iir(data)          ((0x3FFF0000&(data))>>16)
#define CPLL_STABILITY_OBSERVE_3_get_phase_out_line_iir(data)         (0x00003FFF&(data))


#define HPLL_STABILITY_OBSERVE_1                                      0x18019270
#define HPLL_STABILITY_OBSERVE_1_reg_addr                             "0xb8019270"
#define HPLL_STABILITY_OBSERVE_1_reg                                  0xb8019270
#define HPLL_STABILITY_OBSERVE_1_inst_addr                            "0x009C"
#define HPLL_STABILITY_OBSERVE_1_inst                                 0x009C
#define HPLL_STABILITY_OBSERVE_1_herror_pos_neg_value_diff_thr_shift  (16)
#define HPLL_STABILITY_OBSERVE_1_herror_continune_same_sign_thr_shift (8)
#define HPLL_STABILITY_OBSERVE_1_herror_neg_pos_num_total_thr_shift   (4)
#define HPLL_STABILITY_OBSERVE_1_herror_neg_pos_value_total_thr_shift (0)
#define HPLL_STABILITY_OBSERVE_1_herror_pos_neg_value_diff_thr_mask   (0xFFFF0000)
#define HPLL_STABILITY_OBSERVE_1_herror_continune_same_sign_thr_mask  (0x00003F00)
#define HPLL_STABILITY_OBSERVE_1_herror_neg_pos_num_total_thr_mask    (0x000000F0)
#define HPLL_STABILITY_OBSERVE_1_herror_neg_pos_value_total_thr_mask  (0x0000000F)
#define HPLL_STABILITY_OBSERVE_1_herror_pos_neg_value_diff_thr(data)  (0xFFFF0000&((data)<<16))
#define HPLL_STABILITY_OBSERVE_1_herror_continune_same_sign_thr(data) (0x00003F00&((data)<<8))
#define HPLL_STABILITY_OBSERVE_1_herror_neg_pos_num_total_thr(data)   (0x000000F0&((data)<<4))
#define HPLL_STABILITY_OBSERVE_1_herror_neg_pos_value_total_thr(data) (0x0000000F&(data))
#define HPLL_STABILITY_OBSERVE_1_get_herror_pos_neg_value_diff_thr(data)  ((0xFFFF0000&(data))>>16)
#define HPLL_STABILITY_OBSERVE_1_get_herror_continune_same_sign_thr(data)  ((0x00003F00&(data))>>8)
#define HPLL_STABILITY_OBSERVE_1_get_herror_neg_pos_num_total_thr(data)  ((0x000000F0&(data))>>4)
#define HPLL_STABILITY_OBSERVE_1_get_herror_neg_pos_value_total_thr(data)  (0x0000000F&(data))


#define HPLL_STABILITY_OBSERVE_2                                      0x18019274
#define HPLL_STABILITY_OBSERVE_2_reg_addr                             "0xb8019274"
#define HPLL_STABILITY_OBSERVE_2_reg                                  0xb8019274
#define HPLL_STABILITY_OBSERVE_2_inst_addr                            "0x009D"
#define HPLL_STABILITY_OBSERVE_2_inst                                 0x009D
#define HPLL_STABILITY_OBSERVE_2_herror_neg_value_shift               (16)
#define HPLL_STABILITY_OBSERVE_2_herror_pos_value_shift               (0)
#define HPLL_STABILITY_OBSERVE_2_herror_neg_value_mask                (0xFFFF0000)
#define HPLL_STABILITY_OBSERVE_2_herror_pos_value_mask                (0x0000FFFF)
#define HPLL_STABILITY_OBSERVE_2_herror_neg_value(data)               (0xFFFF0000&((data)<<16))
#define HPLL_STABILITY_OBSERVE_2_herror_pos_value(data)               (0x0000FFFF&(data))
#define HPLL_STABILITY_OBSERVE_2_get_herror_neg_value(data)           ((0xFFFF0000&(data))>>16)
#define HPLL_STABILITY_OBSERVE_2_get_herror_pos_value(data)           (0x0000FFFF&(data))


#define HPLL_STABILITY_OBSERVE_3                                      0x18019278
#define HPLL_STABILITY_OBSERVE_3_reg_addr                             "0xb8019278"
#define HPLL_STABILITY_OBSERVE_3_reg                                  0xb8019278
#define HPLL_STABILITY_OBSERVE_3_inst_addr                            "0x009E"
#define HPLL_STABILITY_OBSERVE_3_inst                                 0x009E
#define HPLL_STABILITY_OBSERVE_3_herror_neg_pos_err_th_shift          (16)
#define HPLL_STABILITY_OBSERVE_3_herror_neg_pos_num_win_thr_shift     (8)
#define HPLL_STABILITY_OBSERVE_3_herror_pos_neg_num_even_shift        (2)
#define HPLL_STABILITY_OBSERVE_3_herror_pos_neg_value_even_shift      (1)
#define HPLL_STABILITY_OBSERVE_3_herror_stable_state_hold_en_shift    (0)
#define HPLL_STABILITY_OBSERVE_3_herror_neg_pos_err_th_mask           (0x1FFF0000)
#define HPLL_STABILITY_OBSERVE_3_herror_neg_pos_num_win_thr_mask      (0x00007F00)
#define HPLL_STABILITY_OBSERVE_3_herror_pos_neg_num_even_mask         (0x00000004)
#define HPLL_STABILITY_OBSERVE_3_herror_pos_neg_value_even_mask       (0x00000002)
#define HPLL_STABILITY_OBSERVE_3_herror_stable_state_hold_en_mask     (0x00000001)
#define HPLL_STABILITY_OBSERVE_3_herror_neg_pos_err_th(data)          (0x1FFF0000&((data)<<16))
#define HPLL_STABILITY_OBSERVE_3_herror_neg_pos_num_win_thr(data)     (0x00007F00&((data)<<8))
#define HPLL_STABILITY_OBSERVE_3_herror_pos_neg_num_even(data)        (0x00000004&((data)<<2))
#define HPLL_STABILITY_OBSERVE_3_herror_pos_neg_value_even(data)      (0x00000002&((data)<<1))
#define HPLL_STABILITY_OBSERVE_3_herror_stable_state_hold_en(data)    (0x00000001&(data))
#define HPLL_STABILITY_OBSERVE_3_get_herror_neg_pos_err_th(data)      ((0x1FFF0000&(data))>>16)
#define HPLL_STABILITY_OBSERVE_3_get_herror_neg_pos_num_win_thr(data) ((0x00007F00&(data))>>8)
#define HPLL_STABILITY_OBSERVE_3_get_herror_pos_neg_num_even(data)    ((0x00000004&(data))>>2)
#define HPLL_STABILITY_OBSERVE_3_get_herror_pos_neg_value_even(data)  ((0x00000002&(data))>>1)
#define HPLL_STABILITY_OBSERVE_3_get_herror_stable_state_hold_en(data)  (0x00000001&(data))


#define H_PHASE_DIFF_STATISTICS_SET_1                                 0x1801927c
#define H_PHASE_DIFF_STATISTICS_SET_1_reg_addr                        "0xb801927c"
#define H_PHASE_DIFF_STATISTICS_SET_1_reg                             0xb801927c
#define H_PHASE_DIFF_STATISTICS_SET_1_inst_addr                       "0x009F"
#define H_PHASE_DIFF_STATISTICS_SET_1_inst                            0x009F
#define H_PHASE_DIFF_STATISTICS_SET_1_statistic_h_phase_diff_sec1_end_shift  (16)
#define H_PHASE_DIFF_STATISTICS_SET_1_statistic_h_phase_diff_sec1_start_shift  (0)
#define H_PHASE_DIFF_STATISTICS_SET_1_statistic_h_phase_diff_sec1_end_mask  (0x01FF0000)
#define H_PHASE_DIFF_STATISTICS_SET_1_statistic_h_phase_diff_sec1_start_mask  (0x000001FF)
#define H_PHASE_DIFF_STATISTICS_SET_1_statistic_h_phase_diff_sec1_end(data)  (0x01FF0000&((data)<<16))
#define H_PHASE_DIFF_STATISTICS_SET_1_statistic_h_phase_diff_sec1_start(data)  (0x000001FF&(data))
#define H_PHASE_DIFF_STATISTICS_SET_1_get_statistic_h_phase_diff_sec1_end(data)  ((0x01FF0000&(data))>>16)
#define H_PHASE_DIFF_STATISTICS_SET_1_get_statistic_h_phase_diff_sec1_start(data)  (0x000001FF&(data))


#define H_PHASE_DIFF_STATISTICS_SET_2                                 0x18019280
#define H_PHASE_DIFF_STATISTICS_SET_2_reg_addr                        "0xb8019280"
#define H_PHASE_DIFF_STATISTICS_SET_2_reg                             0xb8019280
#define H_PHASE_DIFF_STATISTICS_SET_2_inst_addr                       "0x00A0"
#define H_PHASE_DIFF_STATISTICS_SET_2_inst                            0x00A0
#define H_PHASE_DIFF_STATISTICS_SET_2_statistic_h_phase_diff_sec2_end_shift  (16)
#define H_PHASE_DIFF_STATISTICS_SET_2_statistic_h_phase_diff_sec2_start_shift  (0)
#define H_PHASE_DIFF_STATISTICS_SET_2_statistic_h_phase_diff_sec2_end_mask  (0x01FF0000)
#define H_PHASE_DIFF_STATISTICS_SET_2_statistic_h_phase_diff_sec2_start_mask  (0x000001FF)
#define H_PHASE_DIFF_STATISTICS_SET_2_statistic_h_phase_diff_sec2_end(data)  (0x01FF0000&((data)<<16))
#define H_PHASE_DIFF_STATISTICS_SET_2_statistic_h_phase_diff_sec2_start(data)  (0x000001FF&(data))
#define H_PHASE_DIFF_STATISTICS_SET_2_get_statistic_h_phase_diff_sec2_end(data)  ((0x01FF0000&(data))>>16)
#define H_PHASE_DIFF_STATISTICS_SET_2_get_statistic_h_phase_diff_sec2_start(data)  (0x000001FF&(data))


#define H_PHASE_DIFF_STATISTICS_SET_3                                 0x18019284
#define H_PHASE_DIFF_STATISTICS_SET_3_reg_addr                        "0xb8019284"
#define H_PHASE_DIFF_STATISTICS_SET_3_reg                             0xb8019284
#define H_PHASE_DIFF_STATISTICS_SET_3_inst_addr                       "0x00A1"
#define H_PHASE_DIFF_STATISTICS_SET_3_inst                            0x00A1
#define H_PHASE_DIFF_STATISTICS_SET_3_statistic_h_phase_diff_hitso_level2_shift  (16)
#define H_PHASE_DIFF_STATISTICS_SET_3_statistic_h_phase_diff_hitso_level1_shift  (0)
#define H_PHASE_DIFF_STATISTICS_SET_3_statistic_h_phase_diff_hitso_level2_mask  (0x1FFF0000)
#define H_PHASE_DIFF_STATISTICS_SET_3_statistic_h_phase_diff_hitso_level1_mask  (0x00001FFF)
#define H_PHASE_DIFF_STATISTICS_SET_3_statistic_h_phase_diff_hitso_level2(data)  (0x1FFF0000&((data)<<16))
#define H_PHASE_DIFF_STATISTICS_SET_3_statistic_h_phase_diff_hitso_level1(data)  (0x00001FFF&(data))
#define H_PHASE_DIFF_STATISTICS_SET_3_get_statistic_h_phase_diff_hitso_level2(data)  ((0x1FFF0000&(data))>>16)
#define H_PHASE_DIFF_STATISTICS_SET_3_get_statistic_h_phase_diff_hitso_level1(data)  (0x00001FFF&(data))


#define H_PHASE_DIFF_STATISTICS_SET_4                                 0x18019288
#define H_PHASE_DIFF_STATISTICS_SET_4_reg_addr                        "0xb8019288"
#define H_PHASE_DIFF_STATISTICS_SET_4_reg                             0xb8019288
#define H_PHASE_DIFF_STATISTICS_SET_4_inst_addr                       "0x00A2"
#define H_PHASE_DIFF_STATISTICS_SET_4_inst                            0x00A2
#define H_PHASE_DIFF_STATISTICS_SET_4_statistic_h_phase_diff_hitso_level4_shift  (16)
#define H_PHASE_DIFF_STATISTICS_SET_4_statistic_h_phase_diff_hitso_level3_shift  (0)
#define H_PHASE_DIFF_STATISTICS_SET_4_statistic_h_phase_diff_hitso_level4_mask  (0x1FFF0000)
#define H_PHASE_DIFF_STATISTICS_SET_4_statistic_h_phase_diff_hitso_level3_mask  (0x00001FFF)
#define H_PHASE_DIFF_STATISTICS_SET_4_statistic_h_phase_diff_hitso_level4(data)  (0x1FFF0000&((data)<<16))
#define H_PHASE_DIFF_STATISTICS_SET_4_statistic_h_phase_diff_hitso_level3(data)  (0x00001FFF&(data))
#define H_PHASE_DIFF_STATISTICS_SET_4_get_statistic_h_phase_diff_hitso_level4(data)  ((0x1FFF0000&(data))>>16)
#define H_PHASE_DIFF_STATISTICS_SET_4_get_statistic_h_phase_diff_hitso_level3(data)  (0x00001FFF&(data))


#define H_PHASE_DIFF_STATISTICS_SET_5                                 0x1801928c
#define H_PHASE_DIFF_STATISTICS_SET_5_reg_addr                        "0xb801928c"
#define H_PHASE_DIFF_STATISTICS_SET_5_reg                             0xb801928c
#define H_PHASE_DIFF_STATISTICS_SET_5_inst_addr                       "0x00A3"
#define H_PHASE_DIFF_STATISTICS_SET_5_inst                            0x00A3
#define H_PHASE_DIFF_STATISTICS_SET_5_statistic_h_phase_diff_hitso_level5_shift  (0)
#define H_PHASE_DIFF_STATISTICS_SET_5_statistic_h_phase_diff_hitso_level5_mask  (0x00001FFF)
#define H_PHASE_DIFF_STATISTICS_SET_5_statistic_h_phase_diff_hitso_level5(data)  (0x00001FFF&(data))
#define H_PHASE_DIFF_STATISTICS_SET_5_get_statistic_h_phase_diff_hitso_level5(data)  (0x00001FFF&(data))


#define H_PHASE_DIFF_SEC1_HISTOGRAM_1                                 0x18019290
#define H_PHASE_DIFF_SEC1_HISTOGRAM_1_reg_addr                        "0xb8019290"
#define H_PHASE_DIFF_SEC1_HISTOGRAM_1_reg                             0xb8019290
#define H_PHASE_DIFF_SEC1_HISTOGRAM_1_inst_addr                       "0x00A4"
#define H_PHASE_DIFF_SEC1_HISTOGRAM_1_inst                            0x00A4
#define H_PHASE_DIFF_SEC1_HISTOGRAM_1_statistic_h_phase_diff_sec1_histo_ready_shift  (31)
#define H_PHASE_DIFF_SEC1_HISTOGRAM_1_statistic_h_phase_diff_sec1_histo_2_shift  (20)
#define H_PHASE_DIFF_SEC1_HISTOGRAM_1_statistic_h_phase_diff_sec1_histo_1_shift  (10)
#define H_PHASE_DIFF_SEC1_HISTOGRAM_1_statistic_h_phase_diff_sec1_histo_0_shift  (0)
#define H_PHASE_DIFF_SEC1_HISTOGRAM_1_statistic_h_phase_diff_sec1_histo_ready_mask  (0x80000000)
#define H_PHASE_DIFF_SEC1_HISTOGRAM_1_statistic_h_phase_diff_sec1_histo_2_mask  (0x3FF00000)
#define H_PHASE_DIFF_SEC1_HISTOGRAM_1_statistic_h_phase_diff_sec1_histo_1_mask  (0x000FFC00)
#define H_PHASE_DIFF_SEC1_HISTOGRAM_1_statistic_h_phase_diff_sec1_histo_0_mask  (0x000003FF)
#define H_PHASE_DIFF_SEC1_HISTOGRAM_1_statistic_h_phase_diff_sec1_histo_ready(data)  (0x80000000&((data)<<31))
#define H_PHASE_DIFF_SEC1_HISTOGRAM_1_statistic_h_phase_diff_sec1_histo_2(data)  (0x3FF00000&((data)<<20))
#define H_PHASE_DIFF_SEC1_HISTOGRAM_1_statistic_h_phase_diff_sec1_histo_1(data)  (0x000FFC00&((data)<<10))
#define H_PHASE_DIFF_SEC1_HISTOGRAM_1_statistic_h_phase_diff_sec1_histo_0(data)  (0x000003FF&(data))
#define H_PHASE_DIFF_SEC1_HISTOGRAM_1_get_statistic_h_phase_diff_sec1_histo_ready(data)  ((0x80000000&(data))>>31)
#define H_PHASE_DIFF_SEC1_HISTOGRAM_1_get_statistic_h_phase_diff_sec1_histo_2(data)  ((0x3FF00000&(data))>>20)
#define H_PHASE_DIFF_SEC1_HISTOGRAM_1_get_statistic_h_phase_diff_sec1_histo_1(data)  ((0x000FFC00&(data))>>10)
#define H_PHASE_DIFF_SEC1_HISTOGRAM_1_get_statistic_h_phase_diff_sec1_histo_0(data)  (0x000003FF&(data))


#define H_PHASE_DIFF_SEC1_HISTOGRAM_2                                 0x18019294
#define H_PHASE_DIFF_SEC1_HISTOGRAM_2_reg_addr                        "0xb8019294"
#define H_PHASE_DIFF_SEC1_HISTOGRAM_2_reg                             0xb8019294
#define H_PHASE_DIFF_SEC1_HISTOGRAM_2_inst_addr                       "0x00A5"
#define H_PHASE_DIFF_SEC1_HISTOGRAM_2_inst                            0x00A5
#define H_PHASE_DIFF_SEC1_HISTOGRAM_2_statistic_h_phase_diff_sec1_histo_5_shift  (20)
#define H_PHASE_DIFF_SEC1_HISTOGRAM_2_statistic_h_phase_diff_sec1_histo_4_shift  (10)
#define H_PHASE_DIFF_SEC1_HISTOGRAM_2_statistic_h_phase_diff_sec1_histo_3_shift  (0)
#define H_PHASE_DIFF_SEC1_HISTOGRAM_2_statistic_h_phase_diff_sec1_histo_5_mask  (0x3FF00000)
#define H_PHASE_DIFF_SEC1_HISTOGRAM_2_statistic_h_phase_diff_sec1_histo_4_mask  (0x000FFC00)
#define H_PHASE_DIFF_SEC1_HISTOGRAM_2_statistic_h_phase_diff_sec1_histo_3_mask  (0x000003FF)
#define H_PHASE_DIFF_SEC1_HISTOGRAM_2_statistic_h_phase_diff_sec1_histo_5(data)  (0x3FF00000&((data)<<20))
#define H_PHASE_DIFF_SEC1_HISTOGRAM_2_statistic_h_phase_diff_sec1_histo_4(data)  (0x000FFC00&((data)<<10))
#define H_PHASE_DIFF_SEC1_HISTOGRAM_2_statistic_h_phase_diff_sec1_histo_3(data)  (0x000003FF&(data))
#define H_PHASE_DIFF_SEC1_HISTOGRAM_2_get_statistic_h_phase_diff_sec1_histo_5(data)  ((0x3FF00000&(data))>>20)
#define H_PHASE_DIFF_SEC1_HISTOGRAM_2_get_statistic_h_phase_diff_sec1_histo_4(data)  ((0x000FFC00&(data))>>10)
#define H_PHASE_DIFF_SEC1_HISTOGRAM_2_get_statistic_h_phase_diff_sec1_histo_3(data)  (0x000003FF&(data))


#define H_PHASE_DIFF_SEC2_HISTOGRAM_1                                 0x18019298
#define H_PHASE_DIFF_SEC2_HISTOGRAM_1_reg_addr                        "0xb8019298"
#define H_PHASE_DIFF_SEC2_HISTOGRAM_1_reg                             0xb8019298
#define H_PHASE_DIFF_SEC2_HISTOGRAM_1_inst_addr                       "0x00A6"
#define H_PHASE_DIFF_SEC2_HISTOGRAM_1_inst                            0x00A6
#define H_PHASE_DIFF_SEC2_HISTOGRAM_1_statistic_h_phase_diff_sec2_histo_ready_shift  (31)
#define H_PHASE_DIFF_SEC2_HISTOGRAM_1_statistic_h_phase_diff_sec2_histo_2_shift  (20)
#define H_PHASE_DIFF_SEC2_HISTOGRAM_1_statistic_h_phase_diff_sec2_histo_1_shift  (10)
#define H_PHASE_DIFF_SEC2_HISTOGRAM_1_statistic_h_phase_diff_sec2_histo_0_shift  (0)
#define H_PHASE_DIFF_SEC2_HISTOGRAM_1_statistic_h_phase_diff_sec2_histo_ready_mask  (0x80000000)
#define H_PHASE_DIFF_SEC2_HISTOGRAM_1_statistic_h_phase_diff_sec2_histo_2_mask  (0x3FF00000)
#define H_PHASE_DIFF_SEC2_HISTOGRAM_1_statistic_h_phase_diff_sec2_histo_1_mask  (0x000FFC00)
#define H_PHASE_DIFF_SEC2_HISTOGRAM_1_statistic_h_phase_diff_sec2_histo_0_mask  (0x000003FF)
#define H_PHASE_DIFF_SEC2_HISTOGRAM_1_statistic_h_phase_diff_sec2_histo_ready(data)  (0x80000000&((data)<<31))
#define H_PHASE_DIFF_SEC2_HISTOGRAM_1_statistic_h_phase_diff_sec2_histo_2(data)  (0x3FF00000&((data)<<20))
#define H_PHASE_DIFF_SEC2_HISTOGRAM_1_statistic_h_phase_diff_sec2_histo_1(data)  (0x000FFC00&((data)<<10))
#define H_PHASE_DIFF_SEC2_HISTOGRAM_1_statistic_h_phase_diff_sec2_histo_0(data)  (0x000003FF&(data))
#define H_PHASE_DIFF_SEC2_HISTOGRAM_1_get_statistic_h_phase_diff_sec2_histo_ready(data)  ((0x80000000&(data))>>31)
#define H_PHASE_DIFF_SEC2_HISTOGRAM_1_get_statistic_h_phase_diff_sec2_histo_2(data)  ((0x3FF00000&(data))>>20)
#define H_PHASE_DIFF_SEC2_HISTOGRAM_1_get_statistic_h_phase_diff_sec2_histo_1(data)  ((0x000FFC00&(data))>>10)
#define H_PHASE_DIFF_SEC2_HISTOGRAM_1_get_statistic_h_phase_diff_sec2_histo_0(data)  (0x000003FF&(data))


#define H_PHASE_DIFF_SEC2_HISTOGRAM_2                                 0x1801929c
#define H_PHASE_DIFF_SEC2_HISTOGRAM_2_reg_addr                        "0xb801929c"
#define H_PHASE_DIFF_SEC2_HISTOGRAM_2_reg                             0xb801929c
#define H_PHASE_DIFF_SEC2_HISTOGRAM_2_inst_addr                       "0x00A7"
#define H_PHASE_DIFF_SEC2_HISTOGRAM_2_inst                            0x00A7
#define H_PHASE_DIFF_SEC2_HISTOGRAM_2_statistic_h_phase_diff_sec2_histo_5_shift  (20)
#define H_PHASE_DIFF_SEC2_HISTOGRAM_2_statistic_h_phase_diff_sec2_histo_4_shift  (10)
#define H_PHASE_DIFF_SEC2_HISTOGRAM_2_statistic_h_phase_diff_sec2_histo_3_shift  (0)
#define H_PHASE_DIFF_SEC2_HISTOGRAM_2_statistic_h_phase_diff_sec2_histo_5_mask  (0x3FF00000)
#define H_PHASE_DIFF_SEC2_HISTOGRAM_2_statistic_h_phase_diff_sec2_histo_4_mask  (0x000FFC00)
#define H_PHASE_DIFF_SEC2_HISTOGRAM_2_statistic_h_phase_diff_sec2_histo_3_mask  (0x000003FF)
#define H_PHASE_DIFF_SEC2_HISTOGRAM_2_statistic_h_phase_diff_sec2_histo_5(data)  (0x3FF00000&((data)<<20))
#define H_PHASE_DIFF_SEC2_HISTOGRAM_2_statistic_h_phase_diff_sec2_histo_4(data)  (0x000FFC00&((data)<<10))
#define H_PHASE_DIFF_SEC2_HISTOGRAM_2_statistic_h_phase_diff_sec2_histo_3(data)  (0x000003FF&(data))
#define H_PHASE_DIFF_SEC2_HISTOGRAM_2_get_statistic_h_phase_diff_sec2_histo_5(data)  ((0x3FF00000&(data))>>20)
#define H_PHASE_DIFF_SEC2_HISTOGRAM_2_get_statistic_h_phase_diff_sec2_histo_4(data)  ((0x000FFC00&(data))>>10)
#define H_PHASE_DIFF_SEC2_HISTOGRAM_2_get_statistic_h_phase_diff_sec2_histo_3(data)  (0x000003FF&(data))


#define DATA_LEVEL_STATISTICS_SET_1                                   0x180192a0
#define DATA_LEVEL_STATISTICS_SET_1_reg_addr                          "0xb80192a0"
#define DATA_LEVEL_STATISTICS_SET_1_reg                               0xb80192a0
#define DATA_LEVEL_STATISTICS_SET_1_inst_addr                         "0x00A8"
#define DATA_LEVEL_STATISTICS_SET_1_inst                              0x00A8
#define DATA_LEVEL_STATISTICS_SET_1_iir_up_speed_on_shift             (31)
#define DATA_LEVEL_STATISTICS_SET_1_data_level_diff_iir_en_shift      (30)
#define DATA_LEVEL_STATISTICS_SET_1_statistic_data_level_diff_th_shift  (16)
#define DATA_LEVEL_STATISTICS_SET_1_statistic_data_level_line_num_shift  (0)
#define DATA_LEVEL_STATISTICS_SET_1_iir_up_speed_on_mask              (0x80000000)
#define DATA_LEVEL_STATISTICS_SET_1_data_level_diff_iir_en_mask       (0x40000000)
#define DATA_LEVEL_STATISTICS_SET_1_statistic_data_level_diff_th_mask (0x3FFF0000)
#define DATA_LEVEL_STATISTICS_SET_1_statistic_data_level_line_num_mask  (0x0000003F)
#define DATA_LEVEL_STATISTICS_SET_1_iir_up_speed_on(data)             (0x80000000&((data)<<31))
#define DATA_LEVEL_STATISTICS_SET_1_data_level_diff_iir_en(data)      (0x40000000&((data)<<30))
#define DATA_LEVEL_STATISTICS_SET_1_statistic_data_level_diff_th(data)  (0x3FFF0000&((data)<<16))
#define DATA_LEVEL_STATISTICS_SET_1_statistic_data_level_line_num(data)  (0x0000003F&(data))
#define DATA_LEVEL_STATISTICS_SET_1_get_iir_up_speed_on(data)         ((0x80000000&(data))>>31)
#define DATA_LEVEL_STATISTICS_SET_1_get_data_level_diff_iir_en(data)  ((0x40000000&(data))>>30)
#define DATA_LEVEL_STATISTICS_SET_1_get_statistic_data_level_diff_th(data)  ((0x3FFF0000&(data))>>16)
#define DATA_LEVEL_STATISTICS_SET_1_get_statistic_data_level_line_num(data)  (0x0000003F&(data))


#define DATA_LEVEL_STATISTICS_SEC1                                    0x180192a4
#define DATA_LEVEL_STATISTICS_SEC1_reg_addr                           "0xb80192a4"
#define DATA_LEVEL_STATISTICS_SEC1_reg                                0xb80192a4
#define DATA_LEVEL_STATISTICS_SEC1_inst_addr                          "0x00A9"
#define DATA_LEVEL_STATISTICS_SEC1_inst                               0x00A9
#define DATA_LEVEL_STATISTICS_SEC1_statistic_data_level_ready_shift   (31)
#define DATA_LEVEL_STATISTICS_SEC1_statistic_data_level_sec1_min_shift  (12)
#define DATA_LEVEL_STATISTICS_SEC1_statistic_data_level_sec1_max_shift  (0)
#define DATA_LEVEL_STATISTICS_SEC1_statistic_data_level_ready_mask    (0x80000000)
#define DATA_LEVEL_STATISTICS_SEC1_statistic_data_level_sec1_min_mask (0x00FFF000)
#define DATA_LEVEL_STATISTICS_SEC1_statistic_data_level_sec1_max_mask (0x00000FFF)
#define DATA_LEVEL_STATISTICS_SEC1_statistic_data_level_ready(data)   (0x80000000&((data)<<31))
#define DATA_LEVEL_STATISTICS_SEC1_statistic_data_level_sec1_min(data)  (0x00FFF000&((data)<<12))
#define DATA_LEVEL_STATISTICS_SEC1_statistic_data_level_sec1_max(data)  (0x00000FFF&(data))
#define DATA_LEVEL_STATISTICS_SEC1_get_statistic_data_level_ready(data)  ((0x80000000&(data))>>31)
#define DATA_LEVEL_STATISTICS_SEC1_get_statistic_data_level_sec1_min(data)  ((0x00FFF000&(data))>>12)
#define DATA_LEVEL_STATISTICS_SEC1_get_statistic_data_level_sec1_max(data)  (0x00000FFF&(data))


#define DATA_LEVEL_STATISTICS_SEC2                                    0x180192a8
#define DATA_LEVEL_STATISTICS_SEC2_reg_addr                           "0xb80192a8"
#define DATA_LEVEL_STATISTICS_SEC2_reg                                0xb80192a8
#define DATA_LEVEL_STATISTICS_SEC2_inst_addr                          "0x00AA"
#define DATA_LEVEL_STATISTICS_SEC2_inst                               0x00AA
#define DATA_LEVEL_STATISTICS_SEC2_statistic_data_level_sec2_min_shift  (12)
#define DATA_LEVEL_STATISTICS_SEC2_statistic_data_level_sec2_max_shift  (0)
#define DATA_LEVEL_STATISTICS_SEC2_statistic_data_level_sec2_min_mask (0x00FFF000)
#define DATA_LEVEL_STATISTICS_SEC2_statistic_data_level_sec2_max_mask (0x00000FFF)
#define DATA_LEVEL_STATISTICS_SEC2_statistic_data_level_sec2_min(data)  (0x00FFF000&((data)<<12))
#define DATA_LEVEL_STATISTICS_SEC2_statistic_data_level_sec2_max(data)  (0x00000FFF&(data))
#define DATA_LEVEL_STATISTICS_SEC2_get_statistic_data_level_sec2_min(data)  ((0x00FFF000&(data))>>12)
#define DATA_LEVEL_STATISTICS_SEC2_get_statistic_data_level_sec2_max(data)  (0x00000FFF&(data))


#define DATA_LEVEL_STATISTICS_SEC3                                    0x180192ac
#define DATA_LEVEL_STATISTICS_SEC3_reg_addr                           "0xb80192ac"
#define DATA_LEVEL_STATISTICS_SEC3_reg                                0xb80192ac
#define DATA_LEVEL_STATISTICS_SEC3_inst_addr                          "0x00AB"
#define DATA_LEVEL_STATISTICS_SEC3_inst                               0x00AB
#define DATA_LEVEL_STATISTICS_SEC3_statistic_data_level_sec3_min_shift  (12)
#define DATA_LEVEL_STATISTICS_SEC3_statistic_data_level_sec3_max_shift  (0)
#define DATA_LEVEL_STATISTICS_SEC3_statistic_data_level_sec3_min_mask (0x00FFF000)
#define DATA_LEVEL_STATISTICS_SEC3_statistic_data_level_sec3_max_mask (0x00000FFF)
#define DATA_LEVEL_STATISTICS_SEC3_statistic_data_level_sec3_min(data)  (0x00FFF000&((data)<<12))
#define DATA_LEVEL_STATISTICS_SEC3_statistic_data_level_sec3_max(data)  (0x00000FFF&(data))
#define DATA_LEVEL_STATISTICS_SEC3_get_statistic_data_level_sec3_min(data)  ((0x00FFF000&(data))>>12)
#define DATA_LEVEL_STATISTICS_SEC3_get_statistic_data_level_sec3_max(data)  (0x00000FFF&(data))


#define DATA_LEVEL_STATISTICS_SEC4                                    0x180192b0
#define DATA_LEVEL_STATISTICS_SEC4_reg_addr                           "0xb80192b0"
#define DATA_LEVEL_STATISTICS_SEC4_reg                                0xb80192b0
#define DATA_LEVEL_STATISTICS_SEC4_inst_addr                          "0x00AC"
#define DATA_LEVEL_STATISTICS_SEC4_inst                               0x00AC
#define DATA_LEVEL_STATISTICS_SEC4_statistic_data_level_sec4_min_shift  (12)
#define DATA_LEVEL_STATISTICS_SEC4_statistic_data_level_sec4_max_shift  (0)
#define DATA_LEVEL_STATISTICS_SEC4_statistic_data_level_sec4_min_mask (0x00FFF000)
#define DATA_LEVEL_STATISTICS_SEC4_statistic_data_level_sec4_max_mask (0x00000FFF)
#define DATA_LEVEL_STATISTICS_SEC4_statistic_data_level_sec4_min(data)  (0x00FFF000&((data)<<12))
#define DATA_LEVEL_STATISTICS_SEC4_statistic_data_level_sec4_max(data)  (0x00000FFF&(data))
#define DATA_LEVEL_STATISTICS_SEC4_get_statistic_data_level_sec4_min(data)  ((0x00FFF000&(data))>>12)
#define DATA_LEVEL_STATISTICS_SEC4_get_statistic_data_level_sec4_max(data)  (0x00000FFF&(data))


#define DATA_LEVEL_STATISTICS_SEC5                                    0x180192b4
#define DATA_LEVEL_STATISTICS_SEC5_reg_addr                           "0xb80192b4"
#define DATA_LEVEL_STATISTICS_SEC5_reg                                0xb80192b4
#define DATA_LEVEL_STATISTICS_SEC5_inst_addr                          "0x00AD"
#define DATA_LEVEL_STATISTICS_SEC5_inst                               0x00AD
#define DATA_LEVEL_STATISTICS_SEC5_statistic_data_level_sec5_min_shift  (12)
#define DATA_LEVEL_STATISTICS_SEC5_statistic_data_level_sec5_max_shift  (0)
#define DATA_LEVEL_STATISTICS_SEC5_statistic_data_level_sec5_min_mask (0x00FFF000)
#define DATA_LEVEL_STATISTICS_SEC5_statistic_data_level_sec5_max_mask (0x00000FFF)
#define DATA_LEVEL_STATISTICS_SEC5_statistic_data_level_sec5_min(data)  (0x00FFF000&((data)<<12))
#define DATA_LEVEL_STATISTICS_SEC5_statistic_data_level_sec5_max(data)  (0x00000FFF&(data))
#define DATA_LEVEL_STATISTICS_SEC5_get_statistic_data_level_sec5_min(data)  ((0x00FFF000&(data))>>12)
#define DATA_LEVEL_STATISTICS_SEC5_get_statistic_data_level_sec5_max(data)  (0x00000FFF&(data))


#define DATA_LEVEL_STATISTICS_SEC6                                    0x180192b8
#define DATA_LEVEL_STATISTICS_SEC6_reg_addr                           "0xb80192b8"
#define DATA_LEVEL_STATISTICS_SEC6_reg                                0xb80192b8
#define DATA_LEVEL_STATISTICS_SEC6_inst_addr                          "0x00AE"
#define DATA_LEVEL_STATISTICS_SEC6_inst                               0x00AE
#define DATA_LEVEL_STATISTICS_SEC6_statistic_data_level_sec6_min_shift  (12)
#define DATA_LEVEL_STATISTICS_SEC6_statistic_data_level_sec6_max_shift  (0)
#define DATA_LEVEL_STATISTICS_SEC6_statistic_data_level_sec6_min_mask (0x00FFF000)
#define DATA_LEVEL_STATISTICS_SEC6_statistic_data_level_sec6_max_mask (0x00000FFF)
#define DATA_LEVEL_STATISTICS_SEC6_statistic_data_level_sec6_min(data)  (0x00FFF000&((data)<<12))
#define DATA_LEVEL_STATISTICS_SEC6_statistic_data_level_sec6_max(data)  (0x00000FFF&(data))
#define DATA_LEVEL_STATISTICS_SEC6_get_statistic_data_level_sec6_min(data)  ((0x00FFF000&(data))>>12)
#define DATA_LEVEL_STATISTICS_SEC6_get_statistic_data_level_sec6_max(data)  (0x00000FFF&(data))


#define DATA_LEVEL_STATISTICS_SEC7                                    0x180192bc
#define DATA_LEVEL_STATISTICS_SEC7_reg_addr                           "0xb80192bc"
#define DATA_LEVEL_STATISTICS_SEC7_reg                                0xb80192bc
#define DATA_LEVEL_STATISTICS_SEC7_inst_addr                          "0x00AF"
#define DATA_LEVEL_STATISTICS_SEC7_inst                               0x00AF
#define DATA_LEVEL_STATISTICS_SEC7_statistic_data_level_sec7_min_shift  (12)
#define DATA_LEVEL_STATISTICS_SEC7_statistic_data_level_sec7_max_shift  (0)
#define DATA_LEVEL_STATISTICS_SEC7_statistic_data_level_sec7_min_mask (0x00FFF000)
#define DATA_LEVEL_STATISTICS_SEC7_statistic_data_level_sec7_max_mask (0x00000FFF)
#define DATA_LEVEL_STATISTICS_SEC7_statistic_data_level_sec7_min(data)  (0x00FFF000&((data)<<12))
#define DATA_LEVEL_STATISTICS_SEC7_statistic_data_level_sec7_max(data)  (0x00000FFF&(data))
#define DATA_LEVEL_STATISTICS_SEC7_get_statistic_data_level_sec7_min(data)  ((0x00FFF000&(data))>>12)
#define DATA_LEVEL_STATISTICS_SEC7_get_statistic_data_level_sec7_max(data)  (0x00000FFF&(data))


#define DATA_LEVEL_STATISTICS_SEC8                                    0x180192c0
#define DATA_LEVEL_STATISTICS_SEC8_reg_addr                           "0xb80192c0"
#define DATA_LEVEL_STATISTICS_SEC8_reg                                0xb80192c0
#define DATA_LEVEL_STATISTICS_SEC8_inst_addr                          "0x00B0"
#define DATA_LEVEL_STATISTICS_SEC8_inst                               0x00B0
#define DATA_LEVEL_STATISTICS_SEC8_statistic_data_level_sec8_min_shift  (12)
#define DATA_LEVEL_STATISTICS_SEC8_statistic_data_level_sec8_max_shift  (0)
#define DATA_LEVEL_STATISTICS_SEC8_statistic_data_level_sec8_min_mask (0x00FFF000)
#define DATA_LEVEL_STATISTICS_SEC8_statistic_data_level_sec8_max_mask (0x00000FFF)
#define DATA_LEVEL_STATISTICS_SEC8_statistic_data_level_sec8_min(data)  (0x00FFF000&((data)<<12))
#define DATA_LEVEL_STATISTICS_SEC8_statistic_data_level_sec8_max(data)  (0x00000FFF&(data))
#define DATA_LEVEL_STATISTICS_SEC8_get_statistic_data_level_sec8_min(data)  ((0x00FFF000&(data))>>12)
#define DATA_LEVEL_STATISTICS_SEC8_get_statistic_data_level_sec8_max(data)  (0x00000FFF&(data))


#define VSYNC_CNTL                                                    0x18019300
#define VSYNC_CNTL_reg_addr                                           "0xb8019300"
#define VSYNC_CNTL_reg                                                0xb8019300
#define VSYNC_CNTL_inst_addr                                          "0x00C0"
#define VSYNC_CNTL_inst                                               0x00C0
#define VSYNC_CNTL_vsync_cntl_shift                                   (6)
#define VSYNC_CNTL_vsync_threshold_shift                              (0)
#define VSYNC_CNTL_vsync_cntl_mask                                    (0x000000C0)
#define VSYNC_CNTL_vsync_threshold_mask                               (0x0000003F)
#define VSYNC_CNTL_vsync_cntl(data)                                   (0x000000C0&((data)<<6))
#define VSYNC_CNTL_vsync_threshold(data)                              (0x0000003F&(data))
#define VSYNC_CNTL_get_vsync_cntl(data)                               ((0x000000C0&(data))>>6)
#define VSYNC_CNTL_get_vsync_threshold(data)                          (0x0000003F&(data))


#define VSYNC_TIME_CONST                                              0x18019304
#define VSYNC_TIME_CONST_reg_addr                                     "0xb8019304"
#define VSYNC_TIME_CONST_reg                                          0xb8019304
#define VSYNC_TIME_CONST_inst_addr                                    "0x00C1"
#define VSYNC_TIME_CONST_inst                                         0x00C1
#define VSYNC_TIME_CONST_field_polarity_shift                         (7)
#define VSYNC_TIME_CONST_flip_field_shift                             (6)
#define VSYNC_TIME_CONST_veven_delayed_shift                          (5)
#define VSYNC_TIME_CONST_vodd_delayed_shift                           (4)
#define VSYNC_TIME_CONST_field_detect_mode_shift                      (2)
#define VSYNC_TIME_CONST_vloop_tc3_shift                              (0)
#define VSYNC_TIME_CONST_field_polarity_mask                          (0x00000080)
#define VSYNC_TIME_CONST_flip_field_mask                              (0x00000040)
#define VSYNC_TIME_CONST_veven_delayed_mask                           (0x00000020)
#define VSYNC_TIME_CONST_vodd_delayed_mask                            (0x00000010)
#define VSYNC_TIME_CONST_field_detect_mode_mask                       (0x0000000C)
#define VSYNC_TIME_CONST_vloop_tc3_mask                               (0x00000003)
#define VSYNC_TIME_CONST_field_polarity(data)                         (0x00000080&((data)<<7))
#define VSYNC_TIME_CONST_flip_field(data)                             (0x00000040&((data)<<6))
#define VSYNC_TIME_CONST_veven_delayed(data)                          (0x00000020&((data)<<5))
#define VSYNC_TIME_CONST_vodd_delayed(data)                           (0x00000010&((data)<<4))
#define VSYNC_TIME_CONST_field_detect_mode(data)                      (0x0000000C&((data)<<2))
#define VSYNC_TIME_CONST_vloop_tc3(data)                              (0x00000003&(data))
#define VSYNC_TIME_CONST_get_field_polarity(data)                     ((0x00000080&(data))>>7)
#define VSYNC_TIME_CONST_get_flip_field(data)                         ((0x00000040&(data))>>6)
#define VSYNC_TIME_CONST_get_veven_delayed(data)                      ((0x00000020&(data))>>5)
#define VSYNC_TIME_CONST_get_vodd_delayed(data)                       ((0x00000010&(data))>>4)
#define VSYNC_TIME_CONST_get_field_detect_mode(data)                  ((0x0000000C&(data))>>2)
#define VSYNC_TIME_CONST_get_vloop_tc3(data)                          (0x00000003&(data))


#define VSYNC_TIME_CONST2                                             0x18019308
#define VSYNC_TIME_CONST2_reg_addr                                    "0xb8019308"
#define VSYNC_TIME_CONST2_reg                                         0xb8019308
#define VSYNC_TIME_CONST2_inst_addr                                   "0x00C2"
#define VSYNC_TIME_CONST2_inst                                        0x00C2
#define VSYNC_TIME_CONST2_vloop_tc2_shift                             (0)
#define VSYNC_TIME_CONST2_vloop_tc2_mask                              (0x0000007F)
#define VSYNC_TIME_CONST2_vloop_tc2(data)                             (0x0000007F&(data))
#define VSYNC_TIME_CONST2_get_vloop_tc2(data)                         (0x0000007F&(data))


#define VSYNC_TIME_CONST1                                             0x1801930c
#define VSYNC_TIME_CONST1_reg_addr                                    "0xb801930c"
#define VSYNC_TIME_CONST1_reg                                         0xb801930c
#define VSYNC_TIME_CONST1_inst_addr                                   "0x00C3"
#define VSYNC_TIME_CONST1_inst                                        0x00C3
#define VSYNC_TIME_CONST1_vloop_tc1_shift                             (0)
#define VSYNC_TIME_CONST1_vloop_tc1_mask                              (0x000000FF)
#define VSYNC_TIME_CONST1_vloop_tc1(data)                             (0x000000FF&(data))
#define VSYNC_TIME_CONST1_get_vloop_tc1(data)                         (0x000000FF&(data))


#define SERRATION_TH                                                  0x18019310
#define SERRATION_TH_reg_addr                                         "0xb8019310"
#define SERRATION_TH_reg                                              0xb8019310
#define SERRATION_TH_inst_addr                                        "0x00C4"
#define SERRATION_TH_inst                                             0x00C4
#define SERRATION_TH_serration_threshold_shift                        (0)
#define SERRATION_TH_serration_threshold_mask                         (0x000000FF)
#define SERRATION_TH_serration_threshold(data)                        (0x000000FF&(data))
#define SERRATION_TH_get_serration_threshold(data)                    (0x000000FF&(data))


#define NO_SIGNAL_DEC                                                 0x18019314
#define NO_SIGNAL_DEC_reg_addr                                        "0xb8019314"
#define NO_SIGNAL_DEC_reg                                             0xb8019314
#define NO_SIGNAL_DEC_inst_addr                                       "0x00C5"
#define NO_SIGNAL_DEC_inst                                            0x00C5
#define NO_SIGNAL_DEC_vsync_delay_sel_shift                           (17)
#define NO_SIGNAL_DEC_vsync_delay_en_shift                            (16)
#define NO_SIGNAL_DEC_vsync_delay_1d_shift                            (12)
#define NO_SIGNAL_DEC_vsync_delay_2d_shift                            (8)
#define NO_SIGNAL_DEC_no_signal_dec_shift                             (0)
#define NO_SIGNAL_DEC_vsync_delay_sel_mask                            (0x00020000)
#define NO_SIGNAL_DEC_vsync_delay_en_mask                             (0x00010000)
#define NO_SIGNAL_DEC_vsync_delay_1d_mask                             (0x0000F000)
#define NO_SIGNAL_DEC_vsync_delay_2d_mask                             (0x00000F00)
#define NO_SIGNAL_DEC_no_signal_dec_mask                              (0x00000007)
#define NO_SIGNAL_DEC_vsync_delay_sel(data)                           (0x00020000&((data)<<17))
#define NO_SIGNAL_DEC_vsync_delay_en(data)                            (0x00010000&((data)<<16))
#define NO_SIGNAL_DEC_vsync_delay_1d(data)                            (0x0000F000&((data)<<12))
#define NO_SIGNAL_DEC_vsync_delay_2d(data)                            (0x00000F00&((data)<<8))
#define NO_SIGNAL_DEC_no_signal_dec(data)                             (0x00000007&(data))
#define NO_SIGNAL_DEC_get_vsync_delay_sel(data)                       ((0x00020000&(data))>>17)
#define NO_SIGNAL_DEC_get_vsync_delay_en(data)                        ((0x00010000&(data))>>16)
#define NO_SIGNAL_DEC_get_vsync_delay_1d(data)                        ((0x0000F000&(data))>>12)
#define NO_SIGNAL_DEC_get_vsync_delay_2d(data)                        ((0x00000F00&(data))>>8)
#define NO_SIGNAL_DEC_get_no_signal_dec(data)                         (0x00000007&(data))


#define VACTIVE_START                                                 0x18019318
#define VACTIVE_START_reg_addr                                        "0xb8019318"
#define VACTIVE_START_reg                                             0xb8019318
#define VACTIVE_START_inst_addr                                       "0x00C6"
#define VACTIVE_START_inst                                            0x00C6
#define VACTIVE_START_vactive_start_shift                             (0)
#define VACTIVE_START_vactive_start_mask                              (0x000000FF)
#define VACTIVE_START_vactive_start(data)                             (0x000000FF&(data))
#define VACTIVE_START_get_vactive_start(data)                         (0x000000FF&(data))


#define VACTIVE_HEIGHT                                                0x1801931c
#define VACTIVE_HEIGHT_reg_addr                                       "0xb801931c"
#define VACTIVE_HEIGHT_reg                                            0xb801931c
#define VACTIVE_HEIGHT_inst_addr                                      "0x00C7"
#define VACTIVE_HEIGHT_inst                                           0x00C7
#define VACTIVE_HEIGHT_vactive_height_shift                           (0)
#define VACTIVE_HEIGHT_vactive_height_mask                            (0x000000FF)
#define VACTIVE_HEIGHT_vactive_height(data)                           (0x000000FF&(data))
#define VACTIVE_HEIGHT_get_vactive_height(data)                       (0x000000FF&(data))


#define VSYNC_H_MIN                                                   0x18019320
#define VSYNC_H_MIN_reg_addr                                          "0xb8019320"
#define VSYNC_H_MIN_reg                                               0xb8019320
#define VSYNC_H_MIN_inst_addr                                         "0x00C8"
#define VSYNC_H_MIN_inst                                              0x00C8
#define VSYNC_H_MIN_vsync_h_min_shift                                 (0)
#define VSYNC_H_MIN_vsync_h_min_mask                                  (0x0000007F)
#define VSYNC_H_MIN_vsync_h_min(data)                                 (0x0000007F&(data))
#define VSYNC_H_MIN_get_vsync_h_min(data)                             (0x0000007F&(data))


#define VSYNC_H_MAX                                                   0x18019324
#define VSYNC_H_MAX_reg_addr                                          "0xb8019324"
#define VSYNC_H_MAX_reg                                               0xb8019324
#define VSYNC_H_MAX_inst_addr                                         "0x00C9"
#define VSYNC_H_MAX_inst                                              0x00C9
#define VSYNC_H_MAX_vsync_h_max_shift                                 (0)
#define VSYNC_H_MAX_vsync_h_max_mask                                  (0x0000007F)
#define VSYNC_H_MAX_vsync_h_max(data)                                 (0x0000007F&(data))
#define VSYNC_H_MAX_get_vsync_h_max(data)                             (0x0000007F&(data))


#define VSYNC_VBI_MIN                                                 0x18019328
#define VSYNC_VBI_MIN_reg_addr                                        "0xb8019328"
#define VSYNC_VBI_MIN_reg                                             0xb8019328
#define VSYNC_VBI_MIN_inst_addr                                       "0x00CA"
#define VSYNC_VBI_MIN_inst                                            0x00CA
#define VSYNC_VBI_MIN_vsync_vbi_min_shift                             (0)
#define VSYNC_VBI_MIN_vsync_vbi_min_mask                              (0x0000007F)
#define VSYNC_VBI_MIN_vsync_vbi_min(data)                             (0x0000007F&(data))
#define VSYNC_VBI_MIN_get_vsync_vbi_min(data)                         (0x0000007F&(data))


#define VSYNC_VBI_LOCKOUT_END                                         0x1801932c
#define VSYNC_VBI_LOCKOUT_END_reg_addr                                "0xb801932c"
#define VSYNC_VBI_LOCKOUT_END_reg                                     0xb801932c
#define VSYNC_VBI_LOCKOUT_END_inst_addr                               "0x00CB"
#define VSYNC_VBI_LOCKOUT_END_inst                                    0x00CB
#define VSYNC_VBI_LOCKOUT_END_vlock_wide_range_shift                  (7)
#define VSYNC_VBI_LOCKOUT_END_vsync_vbi_max_shift                     (0)
#define VSYNC_VBI_LOCKOUT_END_vlock_wide_range_mask                   (0x00000080)
#define VSYNC_VBI_LOCKOUT_END_vsync_vbi_max_mask                      (0x0000007F)
#define VSYNC_VBI_LOCKOUT_END_vlock_wide_range(data)                  (0x00000080&((data)<<7))
#define VSYNC_VBI_LOCKOUT_END_vsync_vbi_max(data)                     (0x0000007F&(data))
#define VSYNC_VBI_LOCKOUT_END_get_vlock_wide_range(data)              ((0x00000080&(data))>>7)
#define VSYNC_VBI_LOCKOUT_END_get_vsync_vbi_max(data)                 (0x0000007F&(data))


#define MIDPT_CTRL                                                    0x18019330
#define MIDPT_CTRL_reg_addr                                           "0xb8019330"
#define MIDPT_CTRL_reg                                                0xb8019330
#define MIDPT_CTRL_inst_addr                                          "0x00CC"
#define MIDPT_CTRL_inst                                               0x00CC
#define MIDPT_CTRL_syncmidpt_dc_rough_shift                           (7)
#define MIDPT_CTRL_midpt_625_dc_th_en_shift                           (6)
#define MIDPT_CTRL_midpt_rough_vdetect_en_shift                       (5)
#define MIDPT_CTRL_vsync_625_midpt_en_shift                           (4)
#define MIDPT_CTRL_syncmidpt_add_level_shift                          (0)
#define MIDPT_CTRL_syncmidpt_dc_rough_mask                            (0x00000080)
#define MIDPT_CTRL_midpt_625_dc_th_en_mask                            (0x00000040)
#define MIDPT_CTRL_midpt_rough_vdetect_en_mask                        (0x00000020)
#define MIDPT_CTRL_vsync_625_midpt_en_mask                            (0x00000010)
#define MIDPT_CTRL_syncmidpt_add_level_mask                           (0x00000003)
#define MIDPT_CTRL_syncmidpt_dc_rough(data)                           (0x00000080&((data)<<7))
#define MIDPT_CTRL_midpt_625_dc_th_en(data)                           (0x00000040&((data)<<6))
#define MIDPT_CTRL_midpt_rough_vdetect_en(data)                       (0x00000020&((data)<<5))
#define MIDPT_CTRL_vsync_625_midpt_en(data)                           (0x00000010&((data)<<4))
#define MIDPT_CTRL_syncmidpt_add_level(data)                          (0x00000003&(data))
#define MIDPT_CTRL_get_syncmidpt_dc_rough(data)                       ((0x00000080&(data))>>7)
#define MIDPT_CTRL_get_midpt_625_dc_th_en(data)                       ((0x00000040&(data))>>6)
#define MIDPT_CTRL_get_midpt_rough_vdetect_en(data)                   ((0x00000020&(data))>>5)
#define MIDPT_CTRL_get_vsync_625_midpt_en(data)                       ((0x00000010&(data))>>4)
#define MIDPT_CTRL_get_syncmidpt_add_level(data)                      (0x00000003&(data))


#define MIDPT_FIX_ADD_VALUE                                           0x18019334
#define MIDPT_FIX_ADD_VALUE_reg_addr                                  "0xb8019334"
#define MIDPT_FIX_ADD_VALUE_reg                                       0xb8019334
#define MIDPT_FIX_ADD_VALUE_inst_addr                                 "0x00CD"
#define MIDPT_FIX_ADD_VALUE_inst                                      0x00CD
#define MIDPT_FIX_ADD_VALUE_syncmidpt_fix_add_value_shift             (0)
#define MIDPT_FIX_ADD_VALUE_syncmidpt_fix_add_value_mask              (0x000000FF)
#define MIDPT_FIX_ADD_VALUE_syncmidpt_fix_add_value(data)             (0x000000FF&(data))
#define MIDPT_FIX_ADD_VALUE_get_syncmidpt_fix_add_value(data)         (0x000000FF&(data))


#define MIDPT_625_DC_TH                                               0x18019338
#define MIDPT_625_DC_TH_reg_addr                                      "0xb8019338"
#define MIDPT_625_DC_TH_reg                                           0xb8019338
#define MIDPT_625_DC_TH_inst_addr                                     "0x00CE"
#define MIDPT_625_DC_TH_inst                                          0x00CE
#define MIDPT_625_DC_TH_midpt_625_dc_th_shift                         (0)
#define MIDPT_625_DC_TH_midpt_625_dc_th_mask                          (0x000000FF)
#define MIDPT_625_DC_TH_midpt_625_dc_th(data)                         (0x000000FF&(data))
#define MIDPT_625_DC_TH_get_midpt_625_dc_th(data)                     (0x000000FF&(data))


#define SYNC_DC_OFFSET_TH1                                            0x1801933c
#define SYNC_DC_OFFSET_TH1_reg_addr                                   "0xb801933c"
#define SYNC_DC_OFFSET_TH1_reg                                        0xb801933c
#define SYNC_DC_OFFSET_TH1_inst_addr                                  "0x00CF"
#define SYNC_DC_OFFSET_TH1_inst                                       0x00CF
#define SYNC_DC_OFFSET_TH1_sync_dc_offset_th_shift                    (0)
#define SYNC_DC_OFFSET_TH1_sync_dc_offset_th_mask                     (0x00000FFF)
#define SYNC_DC_OFFSET_TH1_sync_dc_offset_th(data)                    (0x00000FFF&(data))
#define SYNC_DC_OFFSET_TH1_get_sync_dc_offset_th(data)                (0x00000FFF&(data))


#define SYNC_DC_OFFSET_TH                                             0x18019340
#define SYNC_DC_OFFSET_TH_reg_addr                                    "0xb8019340"
#define SYNC_DC_OFFSET_TH_reg                                         0xb8019340
#define SYNC_DC_OFFSET_TH_inst_addr                                   "0x00D0"
#define SYNC_DC_OFFSET_TH_inst                                        0x00D0
#define SYNC_DC_OFFSET_TH_sync_midpt_625_shift                        (0)
#define SYNC_DC_OFFSET_TH_sync_midpt_625_mask                         (0x00000FFF)
#define SYNC_DC_OFFSET_TH_sync_midpt_625(data)                        (0x00000FFF&(data))
#define SYNC_DC_OFFSET_TH_get_sync_midpt_625(data)                    (0x00000FFF&(data))


#define SYNC_MIDPT_H                                                  0x18019344
#define SYNC_MIDPT_H_reg_addr                                         "0xb8019344"
#define SYNC_MIDPT_H_reg                                              0xb8019344
#define SYNC_MIDPT_H_inst_addr                                        "0x00D1"
#define SYNC_MIDPT_H_inst                                             0x00D1
#define SYNC_MIDPT_H_sync_midpt_h_shift                               (0)
#define SYNC_MIDPT_H_sync_midpt_h_mask                                (0x00000FFF)
#define SYNC_MIDPT_H_sync_midpt_h(data)                               (0x00000FFF&(data))
#define SYNC_MIDPT_H_get_sync_midpt_h(data)                           (0x00000FFF&(data))


#define SYNC_MIDPT_V                                                  0x18019348
#define SYNC_MIDPT_V_reg_addr                                         "0xb8019348"
#define SYNC_MIDPT_V_reg                                              0xb8019348
#define SYNC_MIDPT_V_inst_addr                                        "0x00D2"
#define SYNC_MIDPT_V_inst                                             0x00D2
#define SYNC_MIDPT_V_sync_midpt_v_shift                               (0)
#define SYNC_MIDPT_V_sync_midpt_v_mask                                (0x00000FFF)
#define SYNC_MIDPT_V_sync_midpt_v(data)                               (0x00000FFF&(data))
#define SYNC_MIDPT_V_get_sync_midpt_v(data)                           (0x00000FFF&(data))


#define SYNC_MIDPT_V2                                                 0x1801934c
#define SYNC_MIDPT_V2_reg_addr                                        "0xb801934c"
#define SYNC_MIDPT_V2_reg                                             0xb801934c
#define SYNC_MIDPT_V2_inst_addr                                       "0x00D3"
#define SYNC_MIDPT_V2_inst                                            0x00D3
#define SYNC_MIDPT_V2_raw_vdetect_max_sel_shift                       (16)
#define SYNC_MIDPT_V2_no_signal_hpll_out_shift                        (12)
#define SYNC_MIDPT_V2_no_signal_to_0_sel_shift                        (10)
#define SYNC_MIDPT_V2_hpll_no_signal_sel_shift                        (9)
#define SYNC_MIDPT_V2_vlock_sel_shift                                 (8)
#define SYNC_MIDPT_V2_vdetect_pattern_sel_shift                       (6)
#define SYNC_MIDPT_V2_adc_lpf_sel_shift                               (1)
#define SYNC_MIDPT_V2_new_vdetect_line_length_en_shift                (0)
#define SYNC_MIDPT_V2_raw_vdetect_max_sel_mask                        (0x00030000)
#define SYNC_MIDPT_V2_no_signal_hpll_out_mask                         (0x00001000)
#define SYNC_MIDPT_V2_no_signal_to_0_sel_mask                         (0x00000400)
#define SYNC_MIDPT_V2_hpll_no_signal_sel_mask                         (0x00000200)
#define SYNC_MIDPT_V2_vlock_sel_mask                                  (0x00000100)
#define SYNC_MIDPT_V2_vdetect_pattern_sel_mask                        (0x000000C0)
#define SYNC_MIDPT_V2_adc_lpf_sel_mask                                (0x0000000E)
#define SYNC_MIDPT_V2_new_vdetect_line_length_en_mask                 (0x00000001)
#define SYNC_MIDPT_V2_raw_vdetect_max_sel(data)                       (0x00030000&((data)<<16))
#define SYNC_MIDPT_V2_no_signal_hpll_out(data)                        (0x00001000&((data)<<12))
#define SYNC_MIDPT_V2_no_signal_to_0_sel(data)                        (0x00000400&((data)<<10))
#define SYNC_MIDPT_V2_hpll_no_signal_sel(data)                        (0x00000200&((data)<<9))
#define SYNC_MIDPT_V2_vlock_sel(data)                                 (0x00000100&((data)<<8))
#define SYNC_MIDPT_V2_vdetect_pattern_sel(data)                       (0x000000C0&((data)<<6))
#define SYNC_MIDPT_V2_adc_lpf_sel(data)                               (0x0000000E&((data)<<1))
#define SYNC_MIDPT_V2_new_vdetect_line_length_en(data)                (0x00000001&(data))
#define SYNC_MIDPT_V2_get_raw_vdetect_max_sel(data)                   ((0x00030000&(data))>>16)
#define SYNC_MIDPT_V2_get_no_signal_hpll_out(data)                    ((0x00001000&(data))>>12)
#define SYNC_MIDPT_V2_get_no_signal_to_0_sel(data)                    ((0x00000400&(data))>>10)
#define SYNC_MIDPT_V2_get_hpll_no_signal_sel(data)                    ((0x00000200&(data))>>9)
#define SYNC_MIDPT_V2_get_vlock_sel(data)                             ((0x00000100&(data))>>8)
#define SYNC_MIDPT_V2_get_vdetect_pattern_sel(data)                   ((0x000000C0&(data))>>6)
#define SYNC_MIDPT_V2_get_adc_lpf_sel(data)                           ((0x0000000E&(data))>>1)
#define SYNC_MIDPT_V2_get_new_vdetect_line_length_en(data)            (0x00000001&(data))


#define ADC_27_LPF_COEF_1                                             0x18019350
#define ADC_27_LPF_COEF_1_reg_addr                                    "0xb8019350"
#define ADC_27_LPF_COEF_1_reg                                         0xb8019350
#define ADC_27_LPF_COEF_1_inst_addr                                   "0x00D4"
#define ADC_27_LPF_COEF_1_inst                                        0x00D4
#define ADC_27_LPF_COEF_1_adc_lpf_coef1_shift                         (16)
#define ADC_27_LPF_COEF_1_adc_lpf_coef2_shift                         (0)
#define ADC_27_LPF_COEF_1_adc_lpf_coef1_mask                          (0x03FF0000)
#define ADC_27_LPF_COEF_1_adc_lpf_coef2_mask                          (0x000003FF)
#define ADC_27_LPF_COEF_1_adc_lpf_coef1(data)                         (0x03FF0000&((data)<<16))
#define ADC_27_LPF_COEF_1_adc_lpf_coef2(data)                         (0x000003FF&(data))
#define ADC_27_LPF_COEF_1_get_adc_lpf_coef1(data)                     ((0x03FF0000&(data))>>16)
#define ADC_27_LPF_COEF_1_get_adc_lpf_coef2(data)                     (0x000003FF&(data))


#define ADC_27_LPF_COEF_2                                             0x18019354
#define ADC_27_LPF_COEF_2_reg_addr                                    "0xb8019354"
#define ADC_27_LPF_COEF_2_reg                                         0xb8019354
#define ADC_27_LPF_COEF_2_inst_addr                                   "0x00D5"
#define ADC_27_LPF_COEF_2_inst                                        0x00D5
#define ADC_27_LPF_COEF_2_adc_lpf_coef3_shift                         (16)
#define ADC_27_LPF_COEF_2_adc_lpf_coef4_shift                         (0)
#define ADC_27_LPF_COEF_2_adc_lpf_coef3_mask                          (0x03FF0000)
#define ADC_27_LPF_COEF_2_adc_lpf_coef4_mask                          (0x000003FF)
#define ADC_27_LPF_COEF_2_adc_lpf_coef3(data)                         (0x03FF0000&((data)<<16))
#define ADC_27_LPF_COEF_2_adc_lpf_coef4(data)                         (0x000003FF&(data))
#define ADC_27_LPF_COEF_2_get_adc_lpf_coef3(data)                     ((0x03FF0000&(data))>>16)
#define ADC_27_LPF_COEF_2_get_adc_lpf_coef4(data)                     (0x000003FF&(data))


#define ADC_27_LPF_COEF_3                                             0x18019358
#define ADC_27_LPF_COEF_3_reg_addr                                    "0xb8019358"
#define ADC_27_LPF_COEF_3_reg                                         0xb8019358
#define ADC_27_LPF_COEF_3_inst_addr                                   "0x00D6"
#define ADC_27_LPF_COEF_3_inst                                        0x00D6
#define ADC_27_LPF_COEF_3_adc_lpf_coef5_shift                         (16)
#define ADC_27_LPF_COEF_3_adc_lpf_coef6_shift                         (0)
#define ADC_27_LPF_COEF_3_adc_lpf_coef5_mask                          (0x03FF0000)
#define ADC_27_LPF_COEF_3_adc_lpf_coef6_mask                          (0x000003FF)
#define ADC_27_LPF_COEF_3_adc_lpf_coef5(data)                         (0x03FF0000&((data)<<16))
#define ADC_27_LPF_COEF_3_adc_lpf_coef6(data)                         (0x000003FF&(data))
#define ADC_27_LPF_COEF_3_get_adc_lpf_coef5(data)                     ((0x03FF0000&(data))>>16)
#define ADC_27_LPF_COEF_3_get_adc_lpf_coef6(data)                     (0x000003FF&(data))


#define ADC_27_LPF_COEF_4                                             0x1801935c
#define ADC_27_LPF_COEF_4_reg_addr                                    "0xb801935c"
#define ADC_27_LPF_COEF_4_reg                                         0xb801935c
#define ADC_27_LPF_COEF_4_inst_addr                                   "0x00D7"
#define ADC_27_LPF_COEF_4_inst                                        0x00D7
#define ADC_27_LPF_COEF_4_adc_lpf_coef7_shift                         (16)
#define ADC_27_LPF_COEF_4_adc_lpf_coef8_shift                         (0)
#define ADC_27_LPF_COEF_4_adc_lpf_coef7_mask                          (0x03FF0000)
#define ADC_27_LPF_COEF_4_adc_lpf_coef8_mask                          (0x000003FF)
#define ADC_27_LPF_COEF_4_adc_lpf_coef7(data)                         (0x03FF0000&((data)<<16))
#define ADC_27_LPF_COEF_4_adc_lpf_coef8(data)                         (0x000003FF&(data))
#define ADC_27_LPF_COEF_4_get_adc_lpf_coef7(data)                     ((0x03FF0000&(data))>>16)
#define ADC_27_LPF_COEF_4_get_adc_lpf_coef8(data)                     (0x000003FF&(data))


#define ADC_27_LPF_COEF_5                                             0x18019360
#define ADC_27_LPF_COEF_5_reg_addr                                    "0xb8019360"
#define ADC_27_LPF_COEF_5_reg                                         0xb8019360
#define ADC_27_LPF_COEF_5_inst_addr                                   "0x00D8"
#define ADC_27_LPF_COEF_5_inst                                        0x00D8
#define ADC_27_LPF_COEF_5_adc_lpf_coef9_shift                         (16)
#define ADC_27_LPF_COEF_5_adc_lpf_coefa_shift                         (0)
#define ADC_27_LPF_COEF_5_adc_lpf_coef9_mask                          (0x03FF0000)
#define ADC_27_LPF_COEF_5_adc_lpf_coefa_mask                          (0x000003FF)
#define ADC_27_LPF_COEF_5_adc_lpf_coef9(data)                         (0x03FF0000&((data)<<16))
#define ADC_27_LPF_COEF_5_adc_lpf_coefa(data)                         (0x000003FF&(data))
#define ADC_27_LPF_COEF_5_get_adc_lpf_coef9(data)                     ((0x03FF0000&(data))>>16)
#define ADC_27_LPF_COEF_5_get_adc_lpf_coefa(data)                     (0x000003FF&(data))


#define ADC_27_LPF_COEF_6                                             0x18019364
#define ADC_27_LPF_COEF_6_reg_addr                                    "0xb8019364"
#define ADC_27_LPF_COEF_6_reg                                         0xb8019364
#define ADC_27_LPF_COEF_6_inst_addr                                   "0x00D9"
#define ADC_27_LPF_COEF_6_inst                                        0x00D9
#define ADC_27_LPF_COEF_6_adc_lpf_coefb_shift                         (16)
#define ADC_27_LPF_COEF_6_adc_lpf_coefc_shift                         (0)
#define ADC_27_LPF_COEF_6_adc_lpf_coefb_mask                          (0x03FF0000)
#define ADC_27_LPF_COEF_6_adc_lpf_coefc_mask                          (0x000003FF)
#define ADC_27_LPF_COEF_6_adc_lpf_coefb(data)                         (0x03FF0000&((data)<<16))
#define ADC_27_LPF_COEF_6_adc_lpf_coefc(data)                         (0x000003FF&(data))
#define ADC_27_LPF_COEF_6_get_adc_lpf_coefb(data)                     ((0x03FF0000&(data))>>16)
#define ADC_27_LPF_COEF_6_get_adc_lpf_coefc(data)                     (0x000003FF&(data))


#define VDETECT_LINE_LENGHT                                           0x18019368
#define VDETECT_LINE_LENGHT_reg_addr                                  "0xb8019368"
#define VDETECT_LINE_LENGHT_reg                                       0xb8019368
#define VDETECT_LINE_LENGHT_inst_addr                                 "0x00DA"
#define VDETECT_LINE_LENGHT_inst                                      0x00DA
#define VDETECT_LINE_LENGHT_new_vdetect_line_length_shift             (0)
#define VDETECT_LINE_LENGHT_new_vdetect_line_length_mask              (0x000000FF)
#define VDETECT_LINE_LENGHT_new_vdetect_line_length(data)             (0x000000FF&(data))
#define VDETECT_LINE_LENGHT_get_new_vdetect_line_length(data)         (0x000000FF&(data))


#define VDETECT_WINDOW_CTRL                                           0x1801936c
#define VDETECT_WINDOW_CTRL_reg_addr                                  "0xb801936c"
#define VDETECT_WINDOW_CTRL_reg                                       0xb801936c
#define VDETECT_WINDOW_CTRL_inst_addr                                 "0x00DB"
#define VDETECT_WINDOW_CTRL_inst                                      0x00DB
#define VDETECT_WINDOW_CTRL_new_vdetect_force_en_shift                (3)
#define VDETECT_WINDOW_CTRL_no_vsync_flag_en_shift                    (2)
#define VDETECT_WINDOW_CTRL_new_vdetect_window_en_shift               (1)
#define VDETECT_WINDOW_CTRL_new_vdetect_window_manu_en_shift          (0)
#define VDETECT_WINDOW_CTRL_new_vdetect_force_en_mask                 (0x00000008)
#define VDETECT_WINDOW_CTRL_no_vsync_flag_en_mask                     (0x00000004)
#define VDETECT_WINDOW_CTRL_new_vdetect_window_en_mask                (0x00000002)
#define VDETECT_WINDOW_CTRL_new_vdetect_window_manu_en_mask           (0x00000001)
#define VDETECT_WINDOW_CTRL_new_vdetect_force_en(data)                (0x00000008&((data)<<3))
#define VDETECT_WINDOW_CTRL_no_vsync_flag_en(data)                    (0x00000004&((data)<<2))
#define VDETECT_WINDOW_CTRL_new_vdetect_window_en(data)               (0x00000002&((data)<<1))
#define VDETECT_WINDOW_CTRL_new_vdetect_window_manu_en(data)          (0x00000001&(data))
#define VDETECT_WINDOW_CTRL_get_new_vdetect_force_en(data)            ((0x00000008&(data))>>3)
#define VDETECT_WINDOW_CTRL_get_no_vsync_flag_en(data)                ((0x00000004&(data))>>2)
#define VDETECT_WINDOW_CTRL_get_new_vdetect_window_en(data)           ((0x00000002&(data))>>1)
#define VDETECT_WINDOW_CTRL_get_new_vdetect_window_manu_en(data)      (0x00000001&(data))


#define VDETECT_WINDOW_TH                                             0x18019370
#define VDETECT_WINDOW_TH_reg_addr                                    "0xb8019370"
#define VDETECT_WINDOW_TH_reg                                         0xb8019370
#define VDETECT_WINDOW_TH_inst_addr                                   "0x00DC"
#define VDETECT_WINDOW_TH_inst                                        0x00DC
#define VDETECT_WINDOW_TH_new_vdetect_window_shift                    (0)
#define VDETECT_WINDOW_TH_new_vdetect_window_mask                     (0x00000FFF)
#define VDETECT_WINDOW_TH_new_vdetect_window(data)                    (0x00000FFF&(data))
#define VDETECT_WINDOW_TH_get_new_vdetect_window(data)                (0x00000FFF&(data))


#define NEW_VDETECT_CTRL                                              0x18019374
#define NEW_VDETECT_CTRL_reg_addr                                     "0xb8019374"
#define NEW_VDETECT_CTRL_reg                                          0xb8019374
#define NEW_VDETECT_CTRL_inst_addr                                    "0x00DD"
#define NEW_VDETECT_CTRL_inst                                         0x00DD
#define NEW_VDETECT_CTRL_new_vdetect_max_limit_value_shift            (12)
#define NEW_VDETECT_CTRL_new_vdetect_max_limit_en_shift               (9)
#define NEW_VDETECT_CTRL_new_vdetect_coch_en_shift                    (8)
#define NEW_VDETECT_CTRL_new_vdetect_en_shift                         (7)
#define NEW_VDETECT_CTRL_gate_sel_shift                               (6)
#define NEW_VDETECT_CTRL_vloss_detect_en_shift                        (5)
#define NEW_VDETECT_CTRL_new_vdetect_vcount_window_en_shift           (4)
#define NEW_VDETECT_CTRL_new_vsync_offset_manul_mode_en_shift         (3)
#define NEW_VDETECT_CTRL_new_vsync_offset_manul_shift                 (0)
#define NEW_VDETECT_CTRL_new_vdetect_max_limit_value_mask             (0x00FFF000)
#define NEW_VDETECT_CTRL_new_vdetect_max_limit_en_mask                (0x00000200)
#define NEW_VDETECT_CTRL_new_vdetect_coch_en_mask                     (0x00000100)
#define NEW_VDETECT_CTRL_new_vdetect_en_mask                          (0x00000080)
#define NEW_VDETECT_CTRL_gate_sel_mask                                (0x00000040)
#define NEW_VDETECT_CTRL_vloss_detect_en_mask                         (0x00000020)
#define NEW_VDETECT_CTRL_new_vdetect_vcount_window_en_mask            (0x00000010)
#define NEW_VDETECT_CTRL_new_vsync_offset_manul_mode_en_mask          (0x00000008)
#define NEW_VDETECT_CTRL_new_vsync_offset_manul_mask                  (0x00000007)
#define NEW_VDETECT_CTRL_new_vdetect_max_limit_value(data)            (0x00FFF000&((data)<<12))
#define NEW_VDETECT_CTRL_new_vdetect_max_limit_en(data)               (0x00000200&((data)<<9))
#define NEW_VDETECT_CTRL_new_vdetect_coch_en(data)                    (0x00000100&((data)<<8))
#define NEW_VDETECT_CTRL_new_vdetect_en(data)                         (0x00000080&((data)<<7))
#define NEW_VDETECT_CTRL_gate_sel(data)                               (0x00000040&((data)<<6))
#define NEW_VDETECT_CTRL_vloss_detect_en(data)                        (0x00000020&((data)<<5))
#define NEW_VDETECT_CTRL_new_vdetect_vcount_window_en(data)           (0x00000010&((data)<<4))
#define NEW_VDETECT_CTRL_new_vsync_offset_manul_mode_en(data)         (0x00000008&((data)<<3))
#define NEW_VDETECT_CTRL_new_vsync_offset_manul(data)                 (0x00000007&(data))
#define NEW_VDETECT_CTRL_get_new_vdetect_max_limit_value(data)        ((0x00FFF000&(data))>>12)
#define NEW_VDETECT_CTRL_get_new_vdetect_max_limit_en(data)           ((0x00000200&(data))>>9)
#define NEW_VDETECT_CTRL_get_new_vdetect_coch_en(data)                ((0x00000100&(data))>>8)
#define NEW_VDETECT_CTRL_get_new_vdetect_en(data)                     ((0x00000080&(data))>>7)
#define NEW_VDETECT_CTRL_get_gate_sel(data)                           ((0x00000040&(data))>>6)
#define NEW_VDETECT_CTRL_get_vloss_detect_en(data)                    ((0x00000020&(data))>>5)
#define NEW_VDETECT_CTRL_get_new_vdetect_vcount_window_en(data)       ((0x00000010&(data))>>4)
#define NEW_VDETECT_CTRL_get_new_vsync_offset_manul_mode_en(data)     ((0x00000008&(data))>>3)
#define NEW_VDETECT_CTRL_get_new_vsync_offset_manul(data)             (0x00000007&(data))


#define NEW_VDETECT_LOOP_TH2                                          0x18019378
#define NEW_VDETECT_LOOP_TH2_reg_addr                                 "0xb8019378"
#define NEW_VDETECT_LOOP_TH2_reg                                      0xb8019378
#define NEW_VDETECT_LOOP_TH2_inst_addr                                "0x00DE"
#define NEW_VDETECT_LOOP_TH2_inst                                     0x00DE
#define NEW_VDETECT_LOOP_TH2_old_hdetect_lpf_en_shift                 (7)
#define NEW_VDETECT_LOOP_TH2_new_vdetect_feature_th_manul_en_shift    (6)
#define NEW_VDETECT_LOOP_TH2_no_vsync_flag_shift                      (5)
#define NEW_VDETECT_LOOP_TH2_new_vloss_flag_shift                     (4)
#define NEW_VDETECT_LOOP_TH2_force_new_vdetect_fine_window_shift      (3)
#define NEW_VDETECT_LOOP_TH2_vsync_fine_window_state1_en_shift        (2)
#define NEW_VDETECT_LOOP_TH2_old_hdetect_lpf_en_mask                  (0x00000080)
#define NEW_VDETECT_LOOP_TH2_new_vdetect_feature_th_manul_en_mask     (0x00000040)
#define NEW_VDETECT_LOOP_TH2_no_vsync_flag_mask                       (0x00000020)
#define NEW_VDETECT_LOOP_TH2_new_vloss_flag_mask                      (0x00000010)
#define NEW_VDETECT_LOOP_TH2_force_new_vdetect_fine_window_mask       (0x00000008)
#define NEW_VDETECT_LOOP_TH2_vsync_fine_window_state1_en_mask         (0x00000004)
#define NEW_VDETECT_LOOP_TH2_old_hdetect_lpf_en(data)                 (0x00000080&((data)<<7))
#define NEW_VDETECT_LOOP_TH2_new_vdetect_feature_th_manul_en(data)    (0x00000040&((data)<<6))
#define NEW_VDETECT_LOOP_TH2_no_vsync_flag(data)                      (0x00000020&((data)<<5))
#define NEW_VDETECT_LOOP_TH2_new_vloss_flag(data)                     (0x00000010&((data)<<4))
#define NEW_VDETECT_LOOP_TH2_force_new_vdetect_fine_window(data)      (0x00000008&((data)<<3))
#define NEW_VDETECT_LOOP_TH2_vsync_fine_window_state1_en(data)        (0x00000004&((data)<<2))
#define NEW_VDETECT_LOOP_TH2_get_old_hdetect_lpf_en(data)             ((0x00000080&(data))>>7)
#define NEW_VDETECT_LOOP_TH2_get_new_vdetect_feature_th_manul_en(data)  ((0x00000040&(data))>>6)
#define NEW_VDETECT_LOOP_TH2_get_no_vsync_flag(data)                  ((0x00000020&(data))>>5)
#define NEW_VDETECT_LOOP_TH2_get_new_vloss_flag(data)                 ((0x00000010&(data))>>4)
#define NEW_VDETECT_LOOP_TH2_get_force_new_vdetect_fine_window(data)  ((0x00000008&(data))>>3)
#define NEW_VDETECT_LOOP_TH2_get_vsync_fine_window_state1_en(data)    ((0x00000004&(data))>>2)


#define NEW_VDETECT_LOOP_TH1                                          0x1801937c
#define NEW_VDETECT_LOOP_TH1_reg_addr                                 "0xb801937c"
#define NEW_VDETECT_LOOP_TH1_reg                                      0xb801937c
#define NEW_VDETECT_LOOP_TH1_inst_addr                                "0x00DF"
#define NEW_VDETECT_LOOP_TH1_inst                                     0x00DF
#define NEW_VDETECT_LOOP_TH1_new_vdetect_loop_core_th_shift           (0)
#define NEW_VDETECT_LOOP_TH1_new_vdetect_loop_core_th_mask            (0x000003FF)
#define NEW_VDETECT_LOOP_TH1_new_vdetect_loop_core_th(data)           (0x000003FF&(data))
#define NEW_VDETECT_LOOP_TH1_get_new_vdetect_loop_core_th(data)       (0x000003FF&(data))


#define NEW_VDETECT_DIFF_OFFSET                                       0x18019380
#define NEW_VDETECT_DIFF_OFFSET_reg_addr                              "0xb8019380"
#define NEW_VDETECT_DIFF_OFFSET_reg                                   0xb8019380
#define NEW_VDETECT_DIFF_OFFSET_inst_addr                             "0x00E0"
#define NEW_VDETECT_DIFF_OFFSET_inst                                  0x00E0
#define NEW_VDETECT_DIFF_OFFSET_new_vdetect_diff_offset_shift         (0)
#define NEW_VDETECT_DIFF_OFFSET_new_vdetect_diff_offset_mask          (0x00000FFF)
#define NEW_VDETECT_DIFF_OFFSET_new_vdetect_diff_offset(data)         (0x00000FFF&(data))
#define NEW_VDETECT_DIFF_OFFSET_get_new_vdetect_diff_offset(data)     (0x00000FFF&(data))


#define VSYNC_FINE_START                                              0x18019384
#define VSYNC_FINE_START_reg_addr                                     "0xb8019384"
#define VSYNC_FINE_START_reg                                          0xb8019384
#define VSYNC_FINE_START_inst_addr                                    "0x00E1"
#define VSYNC_FINE_START_inst                                         0x00E1
#define VSYNC_FINE_START_vsync_fine_start1_shift                      (20)
#define VSYNC_FINE_START_new_vdetect_loss_max_shift                   (12)
#define VSYNC_FINE_START_vsync_fine_start_shift                       (0)
#define VSYNC_FINE_START_vsync_fine_start1_mask                       (0x3FF00000)
#define VSYNC_FINE_START_new_vdetect_loss_max_mask                    (0x0003F000)
#define VSYNC_FINE_START_vsync_fine_start_mask                        (0x000003FF)
#define VSYNC_FINE_START_vsync_fine_start1(data)                      (0x3FF00000&((data)<<20))
#define VSYNC_FINE_START_new_vdetect_loss_max(data)                   (0x0003F000&((data)<<12))
#define VSYNC_FINE_START_vsync_fine_start(data)                       (0x000003FF&(data))
#define VSYNC_FINE_START_get_vsync_fine_start1(data)                  ((0x3FF00000&(data))>>20)
#define VSYNC_FINE_START_get_new_vdetect_loss_max(data)               ((0x0003F000&(data))>>12)
#define VSYNC_FINE_START_get_vsync_fine_start(data)                   (0x000003FF&(data))


#define VSYNC_FINE_END                                                0x18019388
#define VSYNC_FINE_END_reg_addr                                       "0xb8019388"
#define VSYNC_FINE_END_reg                                            0xb8019388
#define VSYNC_FINE_END_inst_addr                                      "0x00E2"
#define VSYNC_FINE_END_inst                                           0x00E2
#define VSYNC_FINE_END_vsync_fine_end1_shift                          (20)
#define VSYNC_FINE_END_new_vdetect_loss_up_shift                      (12)
#define VSYNC_FINE_END_vsync_fine_end_shift                           (0)
#define VSYNC_FINE_END_vsync_fine_end1_mask                           (0x3FF00000)
#define VSYNC_FINE_END_new_vdetect_loss_up_mask                       (0x0003F000)
#define VSYNC_FINE_END_vsync_fine_end_mask                            (0x000003FF)
#define VSYNC_FINE_END_vsync_fine_end1(data)                          (0x3FF00000&((data)<<20))
#define VSYNC_FINE_END_new_vdetect_loss_up(data)                      (0x0003F000&((data)<<12))
#define VSYNC_FINE_END_vsync_fine_end(data)                           (0x000003FF&(data))
#define VSYNC_FINE_END_get_vsync_fine_end1(data)                      ((0x3FF00000&(data))>>20)
#define VSYNC_FINE_END_get_new_vdetect_loss_up(data)                  ((0x0003F000&(data))>>12)
#define VSYNC_FINE_END_get_vsync_fine_end(data)                       (0x000003FF&(data))


#define NO_VSYNC_TH                                                   0x1801938c
#define NO_VSYNC_TH_reg_addr                                          "0xb801938c"
#define NO_VSYNC_TH_reg                                               0xb801938c
#define NO_VSYNC_TH_inst_addr                                         "0x00E3"
#define NO_VSYNC_TH_inst                                              0x00E3
#define NO_VSYNC_TH_no_vsync_th_hi_shift                              (4)
#define NO_VSYNC_TH_no_vsync_th_lo_shift                              (0)
#define NO_VSYNC_TH_no_vsync_th_hi_mask                               (0x000000F0)
#define NO_VSYNC_TH_no_vsync_th_lo_mask                               (0x0000000F)
#define NO_VSYNC_TH_no_vsync_th_hi(data)                              (0x000000F0&((data)<<4))
#define NO_VSYNC_TH_no_vsync_th_lo(data)                              (0x0000000F&(data))
#define NO_VSYNC_TH_get_no_vsync_th_hi(data)                          ((0x000000F0&(data))>>4)
#define NO_VSYNC_TH_get_no_vsync_th_lo(data)                          (0x0000000F&(data))


#define NEW_VDETECT_VPHASE_TH                                         0x18019390
#define NEW_VDETECT_VPHASE_TH_reg_addr                                "0xb8019390"
#define NEW_VDETECT_VPHASE_TH_reg                                     0xb8019390
#define NEW_VDETECT_VPHASE_TH_inst_addr                               "0x00E4"
#define NEW_VDETECT_VPHASE_TH_inst                                    0x00E4
#define NEW_VDETECT_VPHASE_TH_new_vdetect_loss_dn_shift               (12)
#define NEW_VDETECT_VPHASE_TH_new_vdetect_fine_vphase_th_shift        (0)
#define NEW_VDETECT_VPHASE_TH_new_vdetect_loss_dn_mask                (0x0003F000)
#define NEW_VDETECT_VPHASE_TH_new_vdetect_fine_vphase_th_mask         (0x000003FF)
#define NEW_VDETECT_VPHASE_TH_new_vdetect_loss_dn(data)               (0x0003F000&((data)<<12))
#define NEW_VDETECT_VPHASE_TH_new_vdetect_fine_vphase_th(data)        (0x000003FF&(data))
#define NEW_VDETECT_VPHASE_TH_get_new_vdetect_loss_dn(data)           ((0x0003F000&(data))>>12)
#define NEW_VDETECT_VPHASE_TH_get_new_vdetect_fine_vphase_th(data)    (0x000003FF&(data))


#define NEW_VDETECT_TH1                                               0x18019394
#define NEW_VDETECT_TH1_reg_addr                                      "0xb8019394"
#define NEW_VDETECT_TH1_reg                                           0xb8019394
#define NEW_VDETECT_TH1_inst_addr                                     "0x00E5"
#define NEW_VDETECT_TH1_inst                                          0x00E5
#define NEW_VDETECT_TH1_new_vdetect_feature_th1_shift                 (0)
#define NEW_VDETECT_TH1_new_vdetect_feature_th1_mask                  (0x000000FF)
#define NEW_VDETECT_TH1_new_vdetect_feature_th1(data)                 (0x000000FF&(data))
#define NEW_VDETECT_TH1_get_new_vdetect_feature_th1(data)             (0x000000FF&(data))


#define NEW_VDETECT_TH2                                               0x18019398
#define NEW_VDETECT_TH2_reg_addr                                      "0xb8019398"
#define NEW_VDETECT_TH2_reg                                           0xb8019398
#define NEW_VDETECT_TH2_inst_addr                                     "0x00E6"
#define NEW_VDETECT_TH2_inst                                          0x00E6
#define NEW_VDETECT_TH2_new_vdetect_feature_th2_shift                 (0)
#define NEW_VDETECT_TH2_new_vdetect_feature_th2_mask                  (0x000000FF)
#define NEW_VDETECT_TH2_new_vdetect_feature_th2(data)                 (0x000000FF&(data))
#define NEW_VDETECT_TH2_get_new_vdetect_feature_th2(data)             (0x000000FF&(data))


#define NEW_VDETECT_TH3                                               0x1801939c
#define NEW_VDETECT_TH3_reg_addr                                      "0xb801939c"
#define NEW_VDETECT_TH3_reg                                           0xb801939c
#define NEW_VDETECT_TH3_inst_addr                                     "0x00E7"
#define NEW_VDETECT_TH3_inst                                          0x00E7
#define NEW_VDETECT_TH3_new_vdetect_feature_th3_shift                 (0)
#define NEW_VDETECT_TH3_new_vdetect_feature_th3_mask                  (0x000000FF)
#define NEW_VDETECT_TH3_new_vdetect_feature_th3(data)                 (0x000000FF&(data))
#define NEW_VDETECT_TH3_get_new_vdetect_feature_th3(data)             (0x000000FF&(data))


#define NEW_VDETECT_TH4                                               0x180193a0
#define NEW_VDETECT_TH4_reg_addr                                      "0xb80193a0"
#define NEW_VDETECT_TH4_reg                                           0xb80193a0
#define NEW_VDETECT_TH4_inst_addr                                     "0x00E8"
#define NEW_VDETECT_TH4_inst                                          0x00E8
#define NEW_VDETECT_TH4_new_vdetect_feature_th7_shift                 (24)
#define NEW_VDETECT_TH4_new_vdetect_feature_th6_shift                 (16)
#define NEW_VDETECT_TH4_new_vdetect_feature_th5_shift                 (8)
#define NEW_VDETECT_TH4_new_vdetect_feature_th4_shift                 (0)
#define NEW_VDETECT_TH4_new_vdetect_feature_th7_mask                  (0xFF000000)
#define NEW_VDETECT_TH4_new_vdetect_feature_th6_mask                  (0x00FF0000)
#define NEW_VDETECT_TH4_new_vdetect_feature_th5_mask                  (0x0000FF00)
#define NEW_VDETECT_TH4_new_vdetect_feature_th4_mask                  (0x000000FF)
#define NEW_VDETECT_TH4_new_vdetect_feature_th7(data)                 (0xFF000000&((data)<<24))
#define NEW_VDETECT_TH4_new_vdetect_feature_th6(data)                 (0x00FF0000&((data)<<16))
#define NEW_VDETECT_TH4_new_vdetect_feature_th5(data)                 (0x0000FF00&((data)<<8))
#define NEW_VDETECT_TH4_new_vdetect_feature_th4(data)                 (0x000000FF&(data))
#define NEW_VDETECT_TH4_get_new_vdetect_feature_th7(data)             ((0xFF000000&(data))>>24)
#define NEW_VDETECT_TH4_get_new_vdetect_feature_th6(data)             ((0x00FF0000&(data))>>16)
#define NEW_VDETECT_TH4_get_new_vdetect_feature_th5(data)             ((0x0000FF00&(data))>>8)
#define NEW_VDETECT_TH4_get_new_vdetect_feature_th4(data)             (0x000000FF&(data))


#define VSTATE_CTRL0                                                  0x180193b0
#define VSTATE_CTRL0_reg_addr                                         "0xb80193b0"
#define VSTATE_CTRL0_reg                                              0xb80193b0
#define VSTATE_CTRL0_inst_addr                                        "0x00EC"
#define VSTATE_CTRL0_inst                                             0x00EC
#define VSTATE_CTRL0_vstate0_direct_vsync_shift                       (28)
#define VSTATE_CTRL0_vstate0_counter_num_shift                        (20)
#define VSTATE_CTRL0_vsync_stable_en_shift                            (16)
#define VSTATE_CTRL0_vstate_reset_shift                               (14)
#define VSTATE_CTRL0_vsync_refind_con_sel_shift                       (12)
#define VSTATE_CTRL0_vsync_refind_shift                               (8)
#define VSTATE_CTRL0_vstate_2to3_er_shift                             (0)
#define VSTATE_CTRL0_vstate0_direct_vsync_mask                        (0x10000000)
#define VSTATE_CTRL0_vstate0_counter_num_mask                         (0x0FF00000)
#define VSTATE_CTRL0_vsync_stable_en_mask                             (0x00010000)
#define VSTATE_CTRL0_vstate_reset_mask                                (0x0000C000)
#define VSTATE_CTRL0_vsync_refind_con_sel_mask                        (0x00003000)
#define VSTATE_CTRL0_vsync_refind_mask                                (0x00000100)
#define VSTATE_CTRL0_vstate_2to3_er_mask                              (0x0000000F)
#define VSTATE_CTRL0_vstate0_direct_vsync(data)                       (0x10000000&((data)<<28))
#define VSTATE_CTRL0_vstate0_counter_num(data)                        (0x0FF00000&((data)<<20))
#define VSTATE_CTRL0_vsync_stable_en(data)                            (0x00010000&((data)<<16))
#define VSTATE_CTRL0_vstate_reset(data)                               (0x0000C000&((data)<<14))
#define VSTATE_CTRL0_vsync_refind_con_sel(data)                       (0x00003000&((data)<<12))
#define VSTATE_CTRL0_vsync_refind(data)                               (0x00000100&((data)<<8))
#define VSTATE_CTRL0_vstate_2to3_er(data)                             (0x0000000F&(data))
#define VSTATE_CTRL0_get_vstate0_direct_vsync(data)                   ((0x10000000&(data))>>28)
#define VSTATE_CTRL0_get_vstate0_counter_num(data)                    ((0x0FF00000&(data))>>20)
#define VSTATE_CTRL0_get_vsync_stable_en(data)                        ((0x00010000&(data))>>16)
#define VSTATE_CTRL0_get_vstate_reset(data)                           ((0x0000C000&(data))>>14)
#define VSTATE_CTRL0_get_vsync_refind_con_sel(data)                   ((0x00003000&(data))>>12)
#define VSTATE_CTRL0_get_vsync_refind(data)                           ((0x00000100&(data))>>8)
#define VSTATE_CTRL0_get_vstate_2to3_er(data)                         (0x0000000F&(data))


#define VSTATE_CTRL1                                                  0x180193b4
#define VSTATE_CTRL1_reg_addr                                         "0xb80193b4"
#define VSTATE_CTRL1_reg                                              0xb80193b4
#define VSTATE_CTRL1_inst_addr                                        "0x00ED"
#define VSTATE_CTRL1_inst                                             0x00ED
#define VSTATE_CTRL1_vstate_2to3_th_shift                             (24)
#define VSTATE_CTRL1_vstate_new2to3_en_shift                          (23)
#define VSTATE_CTRL1_hsync_refind_min_shift                           (16)
#define VSTATE_CTRL1_hsync_refind_max_shift                           (8)
#define VSTATE_CTRL1_vstate_1to2_er_shift                             (4)
#define VSTATE_CTRL1_vstate_back1_er_shift                            (0)
#define VSTATE_CTRL1_vstate_2to3_th_mask                              (0xFF000000)
#define VSTATE_CTRL1_vstate_new2to3_en_mask                           (0x00800000)
#define VSTATE_CTRL1_hsync_refind_min_mask                            (0x007F0000)
#define VSTATE_CTRL1_hsync_refind_max_mask                            (0x00007F00)
#define VSTATE_CTRL1_vstate_1to2_er_mask                              (0x000000F0)
#define VSTATE_CTRL1_vstate_back1_er_mask                             (0x0000000F)
#define VSTATE_CTRL1_vstate_2to3_th(data)                             (0xFF000000&((data)<<24))
#define VSTATE_CTRL1_vstate_new2to3_en(data)                          (0x00800000&((data)<<23))
#define VSTATE_CTRL1_hsync_refind_min(data)                           (0x007F0000&((data)<<16))
#define VSTATE_CTRL1_hsync_refind_max(data)                           (0x00007F00&((data)<<8))
#define VSTATE_CTRL1_vstate_1to2_er(data)                             (0x000000F0&((data)<<4))
#define VSTATE_CTRL1_vstate_back1_er(data)                            (0x0000000F&(data))
#define VSTATE_CTRL1_get_vstate_2to3_th(data)                         ((0xFF000000&(data))>>24)
#define VSTATE_CTRL1_get_vstate_new2to3_en(data)                      ((0x00800000&(data))>>23)
#define VSTATE_CTRL1_get_hsync_refind_min(data)                       ((0x007F0000&(data))>>16)
#define VSTATE_CTRL1_get_hsync_refind_max(data)                       ((0x00007F00&(data))>>8)
#define VSTATE_CTRL1_get_vstate_1to2_er(data)                         ((0x000000F0&(data))>>4)
#define VSTATE_CTRL1_get_vstate_back1_er(data)                        (0x0000000F&(data))


#define VSTATE_CTRL2                                                  0x180193b8
#define VSTATE_CTRL2_reg_addr                                         "0xb80193b8"
#define VSTATE_CTRL2_reg                                              0xb80193b8
#define VSTATE_CTRL2_inst_addr                                        "0x00EE"
#define VSTATE_CTRL2_inst                                             0x00EE
#define VSTATE_CTRL2_hsync_reset_for_vsync_shift                      (20)
#define VSTATE_CTRL2_hsync_reset_for_data_shift                       (8)
#define VSTATE_CTRL2_vstate_counter_num_shift                         (0)
#define VSTATE_CTRL2_hsync_reset_for_vsync_mask                       (0x3FF00000)
#define VSTATE_CTRL2_hsync_reset_for_data_mask                        (0x0003FF00)
#define VSTATE_CTRL2_vstate_counter_num_mask                          (0x000000FF)
#define VSTATE_CTRL2_hsync_reset_for_vsync(data)                      (0x3FF00000&((data)<<20))
#define VSTATE_CTRL2_hsync_reset_for_data(data)                       (0x0003FF00&((data)<<8))
#define VSTATE_CTRL2_vstate_counter_num(data)                         (0x000000FF&(data))
#define VSTATE_CTRL2_get_hsync_reset_for_vsync(data)                  ((0x3FF00000&(data))>>20)
#define VSTATE_CTRL2_get_hsync_reset_for_data(data)                   ((0x0003FF00&(data))>>8)
#define VSTATE_CTRL2_get_vstate_counter_num(data)                     (0x000000FF&(data))


#define VSTATE_CTRL3                                                  0x180193bc
#define VSTATE_CTRL3_reg_addr                                         "0xb80193bc"
#define VSTATE_CTRL3_reg                                              0xb80193bc
#define VSTATE_CTRL3_inst_addr                                        "0x00EF"
#define VSTATE_CTRL3_inst                                             0x00EF
#define VSTATE_CTRL3_vphase_error_window_shift                        (24)
#define VSTATE_CTRL3_vstate3_err_adjust_en_shift                      (20)
#define VSTATE_CTRL3_vstate3_err_adjust_th_shift                      (16)
#define VSTATE_CTRL3_vsync_vertical_sum_num_shift                     (8)
#define VSTATE_CTRL3_vstate_status_shift                              (4)
#define VSTATE_CTRL3_vstate_sw_en_shift                               (3)
#define VSTATE_CTRL3_vstate_sw_shift                                  (1)
#define VSTATE_CTRL3_vcr_back_en_shift                                (0)
#define VSTATE_CTRL3_vphase_error_window_mask                         (0xFF000000)
#define VSTATE_CTRL3_vstate3_err_adjust_en_mask                       (0x00100000)
#define VSTATE_CTRL3_vstate3_err_adjust_th_mask                       (0x000F0000)
#define VSTATE_CTRL3_vsync_vertical_sum_num_mask                      (0x00001F00)
#define VSTATE_CTRL3_vstate_status_mask                               (0x00000030)
#define VSTATE_CTRL3_vstate_sw_en_mask                                (0x00000008)
#define VSTATE_CTRL3_vstate_sw_mask                                   (0x00000006)
#define VSTATE_CTRL3_vcr_back_en_mask                                 (0x00000001)
#define VSTATE_CTRL3_vphase_error_window(data)                        (0xFF000000&((data)<<24))
#define VSTATE_CTRL3_vstate3_err_adjust_en(data)                      (0x00100000&((data)<<20))
#define VSTATE_CTRL3_vstate3_err_adjust_th(data)                      (0x000F0000&((data)<<16))
#define VSTATE_CTRL3_vsync_vertical_sum_num(data)                     (0x00001F00&((data)<<8))
#define VSTATE_CTRL3_vstate_status(data)                              (0x00000030&((data)<<4))
#define VSTATE_CTRL3_vstate_sw_en(data)                               (0x00000008&((data)<<3))
#define VSTATE_CTRL3_vstate_sw(data)                                  (0x00000006&((data)<<1))
#define VSTATE_CTRL3_vcr_back_en(data)                                (0x00000001&(data))
#define VSTATE_CTRL3_get_vphase_error_window(data)                    ((0xFF000000&(data))>>24)
#define VSTATE_CTRL3_get_vstate3_err_adjust_en(data)                  ((0x00100000&(data))>>20)
#define VSTATE_CTRL3_get_vstate3_err_adjust_th(data)                  ((0x000F0000&(data))>>16)
#define VSTATE_CTRL3_get_vsync_vertical_sum_num(data)                 ((0x00001F00&(data))>>8)
#define VSTATE_CTRL3_get_vstate_status(data)                          ((0x00000030&(data))>>4)
#define VSTATE_CTRL3_get_vstate_sw_en(data)                           ((0x00000008&(data))>>3)
#define VSTATE_CTRL3_get_vstate_sw(data)                              ((0x00000006&(data))>>1)
#define VSTATE_CTRL3_get_vcr_back_en(data)                            (0x00000001&(data))


#define VLOOP0_TC1                                                    0x180193c0
#define VLOOP0_TC1_reg_addr                                           "0xb80193c0"
#define VLOOP0_TC1_reg                                                0xb80193c0
#define VLOOP0_TC1_inst_addr                                          "0x00F0"
#define VLOOP0_TC1_inst                                               0x00F0
#define VLOOP0_TC1_vloop0_tc1_shift                                   (0)
#define VLOOP0_TC1_vloop0_tc1_mask                                    (0x000000FF)
#define VLOOP0_TC1_vloop0_tc1(data)                                   (0x000000FF&(data))
#define VLOOP0_TC1_get_vloop0_tc1(data)                               (0x000000FF&(data))


#define VLOOP0_TC2                                                    0x180193c4
#define VLOOP0_TC2_reg_addr                                           "0xb80193c4"
#define VLOOP0_TC2_reg                                                0xb80193c4
#define VLOOP0_TC2_inst_addr                                          "0x00F1"
#define VLOOP0_TC2_inst                                               0x00F1
#define VLOOP0_TC2_vloop0_tc2_shift                                   (0)
#define VLOOP0_TC2_vloop0_tc2_mask                                    (0x0000007F)
#define VLOOP0_TC2_vloop0_tc2(data)                                   (0x0000007F&(data))
#define VLOOP0_TC2_get_vloop0_tc2(data)                               (0x0000007F&(data))


#define VLOOP2_TC1                                                    0x180193c8
#define VLOOP2_TC1_reg_addr                                           "0xb80193c8"
#define VLOOP2_TC1_reg                                                0xb80193c8
#define VLOOP2_TC1_inst_addr                                          "0x00F2"
#define VLOOP2_TC1_inst                                               0x00F2
#define VLOOP2_TC1_vloop2_tc1_shift                                   (0)
#define VLOOP2_TC1_vloop2_tc1_mask                                    (0x000000FF)
#define VLOOP2_TC1_vloop2_tc1(data)                                   (0x000000FF&(data))
#define VLOOP2_TC1_get_vloop2_tc1(data)                               (0x000000FF&(data))


#define VLOOP2_TC2                                                    0x180193cc
#define VLOOP2_TC2_reg_addr                                           "0xb80193cc"
#define VLOOP2_TC2_reg                                                0xb80193cc
#define VLOOP2_TC2_inst_addr                                          "0x00F3"
#define VLOOP2_TC2_inst                                               0x00F3
#define VLOOP2_TC2_vloop2_tc2_shift                                   (0)
#define VLOOP2_TC2_vloop2_tc2_mask                                    (0x0000007F)
#define VLOOP2_TC2_vloop2_tc2(data)                                   (0x0000007F&(data))
#define VLOOP2_TC2_get_vloop2_tc2(data)                               (0x0000007F&(data))


#define VLOOP3_TC1                                                    0x180193d0
#define VLOOP3_TC1_reg_addr                                           "0xb80193d0"
#define VLOOP3_TC1_reg                                                0xb80193d0
#define VLOOP3_TC1_inst_addr                                          "0x00F4"
#define VLOOP3_TC1_inst                                               0x00F4
#define VLOOP3_TC1_vloop3_tc1_shift                                   (0)
#define VLOOP3_TC1_vloop3_tc1_mask                                    (0x000000FF)
#define VLOOP3_TC1_vloop3_tc1(data)                                   (0x000000FF&(data))
#define VLOOP3_TC1_get_vloop3_tc1(data)                               (0x000000FF&(data))


#define VLOOP3_TC2                                                    0x180193d4
#define VLOOP3_TC2_reg_addr                                           "0xb80193d4"
#define VLOOP3_TC2_reg                                                0xb80193d4
#define VLOOP3_TC2_inst_addr                                          "0x00F5"
#define VLOOP3_TC2_inst                                               0x00F5
#define VLOOP3_TC2_vloop3_tc2_shift                                   (0)
#define VLOOP3_TC2_vloop3_tc2_mask                                    (0x0000007F)
#define VLOOP3_TC2_vloop3_tc2(data)                                   (0x0000007F&(data))
#define VLOOP3_TC2_get_vloop3_tc2(data)                               (0x0000007F&(data))


#define VLOOP_TC3                                                     0x180193d8
#define VLOOP_TC3_reg_addr                                            "0xb80193d8"
#define VLOOP_TC3_reg                                                 0xb80193d8
#define VLOOP_TC3_inst_addr                                           "0x00F6"
#define VLOOP_TC3_inst                                                0x00F6
#define VLOOP_TC3_vloop0_tc3_shift                                    (4)
#define VLOOP_TC3_vloop2_tc3_shift                                    (2)
#define VLOOP_TC3_vloop3_tc3_shift                                    (0)
#define VLOOP_TC3_vloop0_tc3_mask                                     (0x00000030)
#define VLOOP_TC3_vloop2_tc3_mask                                     (0x0000000C)
#define VLOOP_TC3_vloop3_tc3_mask                                     (0x00000003)
#define VLOOP_TC3_vloop0_tc3(data)                                    (0x00000030&((data)<<4))
#define VLOOP_TC3_vloop2_tc3(data)                                    (0x0000000C&((data)<<2))
#define VLOOP_TC3_vloop3_tc3(data)                                    (0x00000003&(data))
#define VLOOP_TC3_get_vloop0_tc3(data)                                ((0x00000030&(data))>>4)
#define VLOOP_TC3_get_vloop2_tc3(data)                                ((0x0000000C&(data))>>2)
#define VLOOP_TC3_get_vloop3_tc3(data)                                (0x00000003&(data))


#define VLOCK_COUNT                                                   0x180193dc
#define VLOCK_COUNT_reg_addr                                          "0xb80193dc"
#define VLOCK_COUNT_reg                                               0xb80193dc
#define VLOCK_COUNT_inst_addr                                         "0x00F7"
#define VLOCK_COUNT_inst                                              0x00F7
#define VLOCK_COUNT_flag_chrmaunlock_kill_shift                       (6)
#define VLOCK_COUNT_flag_user_kill_shift                              (5)
#define VLOCK_COUNT_flag_cgain_too_big_kill_shift                     (4)
#define VLOCK_COUNT_new_vdetect_lock_en_shift                         (3)
#define VLOCK_COUNT_vlock_count_shift                                 (0)
#define VLOCK_COUNT_flag_chrmaunlock_kill_mask                        (0x00000040)
#define VLOCK_COUNT_flag_user_kill_mask                               (0x00000020)
#define VLOCK_COUNT_flag_cgain_too_big_kill_mask                      (0x00000010)
#define VLOCK_COUNT_new_vdetect_lock_en_mask                          (0x00000008)
#define VLOCK_COUNT_vlock_count_mask                                  (0x00000007)
#define VLOCK_COUNT_flag_chrmaunlock_kill(data)                       (0x00000040&((data)<<6))
#define VLOCK_COUNT_flag_user_kill(data)                              (0x00000020&((data)<<5))
#define VLOCK_COUNT_flag_cgain_too_big_kill(data)                     (0x00000010&((data)<<4))
#define VLOCK_COUNT_new_vdetect_lock_en(data)                         (0x00000008&((data)<<3))
#define VLOCK_COUNT_vlock_count(data)                                 (0x00000007&(data))
#define VLOCK_COUNT_get_flag_chrmaunlock_kill(data)                   ((0x00000040&(data))>>6)
#define VLOCK_COUNT_get_flag_user_kill(data)                          ((0x00000020&(data))>>5)
#define VLOCK_COUNT_get_flag_cgain_too_big_kill(data)                 ((0x00000010&(data))>>4)
#define VLOCK_COUNT_get_new_vdetect_lock_en(data)                     ((0x00000008&(data))>>3)
#define VLOCK_COUNT_get_vlock_count(data)                             (0x00000007&(data))


#define VLOCK_WINDOW                                                  0x180193e0
#define VLOCK_WINDOW_reg_addr                                         "0xb80193e0"
#define VLOCK_WINDOW_reg                                              0xb80193e0
#define VLOCK_WINDOW_inst_addr                                        "0x00F8"
#define VLOCK_WINDOW_inst                                             0x00F8
#define VLOCK_WINDOW_vsync_detect_rst_shift                           (31)
#define VLOCK_WINDOW_vsync_detect_crlock_en_shift                     (28)
#define VLOCK_WINDOW_vsync_detect_count_thl_shift                     (20)
#define VLOCK_WINDOW_vsync_detect_core_thl_shift                      (8)
#define VLOCK_WINDOW_vlock_window_shift                               (0)
#define VLOCK_WINDOW_vsync_detect_rst_mask                            (0x80000000)
#define VLOCK_WINDOW_vsync_detect_crlock_en_mask                      (0x10000000)
#define VLOCK_WINDOW_vsync_detect_count_thl_mask                      (0x03F00000)
#define VLOCK_WINDOW_vsync_detect_core_thl_mask                       (0x0007FF00)
#define VLOCK_WINDOW_vlock_window_mask                                (0x000000FF)
#define VLOCK_WINDOW_vsync_detect_rst(data)                           (0x80000000&((data)<<31))
#define VLOCK_WINDOW_vsync_detect_crlock_en(data)                     (0x10000000&((data)<<28))
#define VLOCK_WINDOW_vsync_detect_count_thl(data)                     (0x03F00000&((data)<<20))
#define VLOCK_WINDOW_vsync_detect_core_thl(data)                      (0x0007FF00&((data)<<8))
#define VLOCK_WINDOW_vlock_window(data)                               (0x000000FF&(data))
#define VLOCK_WINDOW_get_vsync_detect_rst(data)                       ((0x80000000&(data))>>31)
#define VLOCK_WINDOW_get_vsync_detect_crlock_en(data)                 ((0x10000000&(data))>>28)
#define VLOCK_WINDOW_get_vsync_detect_count_thl(data)                 ((0x03F00000&(data))>>20)
#define VLOCK_WINDOW_get_vsync_detect_core_thl(data)                  ((0x0007FF00&(data))>>8)
#define VLOCK_WINDOW_get_vlock_window(data)                           (0x000000FF&(data))


#define VLOCK_PHASE_PLUS                                              0x180193e4
#define VLOCK_PHASE_PLUS_reg_addr                                     "0xb80193e4"
#define VLOCK_PHASE_PLUS_reg                                          0xb80193e4
#define VLOCK_PHASE_PLUS_inst_addr                                    "0x00F9"
#define VLOCK_PHASE_PLUS_inst                                         0x00F9
#define VLOCK_PHASE_PLUS_vlock_phase_plus_shift                       (0)
#define VLOCK_PHASE_PLUS_vlock_phase_plus_mask                        (0x000000FF)
#define VLOCK_PHASE_PLUS_vlock_phase_plus(data)                       (0x000000FF&(data))
#define VLOCK_PHASE_PLUS_get_vlock_phase_plus(data)                   (0x000000FF&(data))


#define VLINE_ADJ_CNT_A                                               0x180193e8
#define VLINE_ADJ_CNT_A_reg_addr                                      "0xb80193e8"
#define VLINE_ADJ_CNT_A_reg                                           0xb80193e8
#define VLINE_ADJ_CNT_A_inst_addr                                     "0x00FA"
#define VLINE_ADJ_CNT_A_inst                                          0x00FA
#define VLINE_ADJ_CNT_A_vline_adj_cnt_a_shift                         (0)
#define VLINE_ADJ_CNT_A_vline_adj_cnt_a_mask                          (0x000000FF)
#define VLINE_ADJ_CNT_A_vline_adj_cnt_a(data)                         (0x000000FF&(data))
#define VLINE_ADJ_CNT_A_get_vline_adj_cnt_a(data)                     (0x000000FF&(data))


#define VLINE_ADJ_CNT_B                                               0x180193ec
#define VLINE_ADJ_CNT_B_reg_addr                                      "0xb80193ec"
#define VLINE_ADJ_CNT_B_reg                                           0xb80193ec
#define VLINE_ADJ_CNT_B_inst_addr                                     "0x00FB"
#define VLINE_ADJ_CNT_B_inst                                          0x00FB
#define VLINE_ADJ_CNT_B_vline_adj_cnt_b_shift                         (0)
#define VLINE_ADJ_CNT_B_vline_adj_cnt_b_mask                          (0x000000FF)
#define VLINE_ADJ_CNT_B_vline_adj_cnt_b(data)                         (0x000000FF&(data))
#define VLINE_ADJ_CNT_B_get_vline_adj_cnt_b(data)                     (0x000000FF&(data))


#define TABLE_HACTIVE_WIDTH                                           0x180193f0
#define TABLE_HACTIVE_WIDTH_reg_addr                                  "0xb80193f0"
#define TABLE_HACTIVE_WIDTH_reg                                       0xb80193f0
#define TABLE_HACTIVE_WIDTH_inst_addr                                 "0x00FC"
#define TABLE_HACTIVE_WIDTH_inst                                      0x00FC
#define TABLE_HACTIVE_WIDTH_table_hactive_width_shift                 (0)
#define TABLE_HACTIVE_WIDTH_table_hactive_width_mask                  (0x000000FF)
#define TABLE_HACTIVE_WIDTH_table_hactive_width(data)                 (0x000000FF&(data))
#define TABLE_HACTIVE_WIDTH_get_table_hactive_width(data)             (0x000000FF&(data))


#define VSYNC_PLL_FREERUN_MUX                                         0x180193f4
#define VSYNC_PLL_FREERUN_MUX_reg_addr                                "0xb80193f4"
#define VSYNC_PLL_FREERUN_MUX_reg                                     0xb80193f4
#define VSYNC_PLL_FREERUN_MUX_inst_addr                               "0x00FD"
#define VSYNC_PLL_FREERUN_MUX_inst                                    0x00FD
#define VSYNC_PLL_FREERUN_MUX_vlines_the_same_cnt_thr_shift           (16)
#define VSYNC_PLL_FREERUN_MUX_vsync_freerun_when_unstable_en_shift    (14)
#define VSYNC_PLL_FREERUN_MUX_vlines_the_same_flag_shift              (13)
#define VSYNC_PLL_FREERUN_MUX_vlines_diff_flag_shift                  (12)
#define VSYNC_PLL_FREERUN_MUX_vlines_freerun_shift                    (0)
#define VSYNC_PLL_FREERUN_MUX_vlines_the_same_cnt_thr_mask            (0x000F0000)
#define VSYNC_PLL_FREERUN_MUX_vsync_freerun_when_unstable_en_mask     (0x00004000)
#define VSYNC_PLL_FREERUN_MUX_vlines_the_same_flag_mask               (0x00002000)
#define VSYNC_PLL_FREERUN_MUX_vlines_diff_flag_mask                   (0x00001000)
#define VSYNC_PLL_FREERUN_MUX_vlines_freerun_mask                     (0x000003FF)
#define VSYNC_PLL_FREERUN_MUX_vlines_the_same_cnt_thr(data)           (0x000F0000&((data)<<16))
#define VSYNC_PLL_FREERUN_MUX_vsync_freerun_when_unstable_en(data)    (0x00004000&((data)<<14))
#define VSYNC_PLL_FREERUN_MUX_vlines_the_same_flag(data)              (0x00002000&((data)<<13))
#define VSYNC_PLL_FREERUN_MUX_vlines_diff_flag(data)                  (0x00001000&((data)<<12))
#define VSYNC_PLL_FREERUN_MUX_vlines_freerun(data)                    (0x000003FF&(data))
#define VSYNC_PLL_FREERUN_MUX_get_vlines_the_same_cnt_thr(data)       ((0x000F0000&(data))>>16)
#define VSYNC_PLL_FREERUN_MUX_get_vsync_freerun_when_unstable_en(data)  ((0x00004000&(data))>>14)
#define VSYNC_PLL_FREERUN_MUX_get_vlines_the_same_flag(data)          ((0x00002000&(data))>>13)
#define VSYNC_PLL_FREERUN_MUX_get_vlines_diff_flag(data)              ((0x00001000&(data))>>12)
#define VSYNC_PLL_FREERUN_MUX_get_vlines_freerun(data)                (0x000003FF&(data))


#define CHROMA_AGC                                                    0x18019400
#define CHROMA_AGC_reg_addr                                           "0xb8019400"
#define CHROMA_AGC_reg                                                0xb8019400
#define CHROMA_AGC_inst_addr                                          "0x0100"
#define CHROMA_AGC_inst                                               0x0100
#define CHROMA_AGC_fix_cgain_shift                                    (28)
#define CHROMA_AGC_cagc_pll_input_sel_shift                           (10)
#define CHROMA_AGC_cagc_data_input_sel_shift                          (8)
#define CHROMA_AGC_cagc_shift                                         (0)
#define CHROMA_AGC_fix_cgain_mask                                     (0x10000000)
#define CHROMA_AGC_cagc_pll_input_sel_mask                            (0x00000C00)
#define CHROMA_AGC_cagc_data_input_sel_mask                           (0x00000300)
#define CHROMA_AGC_cagc_mask                                          (0x000000FF)
#define CHROMA_AGC_fix_cgain(data)                                    (0x10000000&((data)<<28))
#define CHROMA_AGC_cagc_pll_input_sel(data)                           (0x00000C00&((data)<<10))
#define CHROMA_AGC_cagc_data_input_sel(data)                          (0x00000300&((data)<<8))
#define CHROMA_AGC_cagc(data)                                         (0x000000FF&(data))
#define CHROMA_AGC_get_fix_cgain(data)                                ((0x10000000&(data))>>28)
#define CHROMA_AGC_get_cagc_pll_input_sel(data)                       ((0x00000C00&(data))>>10)
#define CHROMA_AGC_get_cagc_data_input_sel(data)                      ((0x00000300&(data))>>8)
#define CHROMA_AGC_get_cagc(data)                                     (0x000000FF&(data))


#define CHROMA_KILL                                                   0x18019404
#define CHROMA_KILL_reg_addr                                          "0xb8019404"
#define CHROMA_KILL_reg                                               0xb8019404
#define CHROMA_KILL_inst_addr                                         "0x0101"
#define CHROMA_KILL_inst                                              0x0101
#define CHROMA_KILL_user_ckill_mode_shift                             (6)
#define CHROMA_KILL_vbi_ckill_shift                                   (5)
#define CHROMA_KILL_hlock_ckill_shift                                 (4)
#define CHROMA_KILL_chroma_kill_shift                                 (0)
#define CHROMA_KILL_user_ckill_mode_mask                              (0x000000C0)
#define CHROMA_KILL_vbi_ckill_mask                                    (0x00000020)
#define CHROMA_KILL_hlock_ckill_mask                                  (0x00000010)
#define CHROMA_KILL_chroma_kill_mask                                  (0x0000000F)
#define CHROMA_KILL_user_ckill_mode(data)                             (0x000000C0&((data)<<6))
#define CHROMA_KILL_vbi_ckill(data)                                   (0x00000020&((data)<<5))
#define CHROMA_KILL_hlock_ckill(data)                                 (0x00000010&((data)<<4))
#define CHROMA_KILL_chroma_kill(data)                                 (0x0000000F&(data))
#define CHROMA_KILL_get_user_ckill_mode(data)                         ((0x000000C0&(data))>>6)
#define CHROMA_KILL_get_vbi_ckill(data)                               ((0x00000020&(data))>>5)
#define CHROMA_KILL_get_hlock_ckill(data)                             ((0x00000010&(data))>>4)
#define CHROMA_KILL_get_chroma_kill(data)                             (0x0000000F&(data))


#define CHROMA_LOCK_CONFIG                                            0x18019408
#define CHROMA_LOCK_CONFIG_reg_addr                                   "0xb8019408"
#define CHROMA_LOCK_CONFIG_reg                                        0xb8019408
#define CHROMA_LOCK_CONFIG_inst_addr                                  "0x0102"
#define CHROMA_LOCK_CONFIG_inst                                       0x0102
#define CHROMA_LOCK_CONFIG_lose_acc_chromalock_level_shift            (12)
#define CHROMA_LOCK_CONFIG_chromalock_input_acc_en_shift              (10)
#define CHROMA_LOCK_CONFIG_chromalock_input_acc_num_shift             (8)
#define CHROMA_LOCK_CONFIG_lose_chromalock_count_shift                (4)
#define CHROMA_LOCK_CONFIG_lose_chromalock_level_shift                (1)
#define CHROMA_LOCK_CONFIG_lose_chromalock_ckill_shift                (0)
#define CHROMA_LOCK_CONFIG_lose_acc_chromalock_level_mask             (0x00007000)
#define CHROMA_LOCK_CONFIG_chromalock_input_acc_en_mask               (0x00000400)
#define CHROMA_LOCK_CONFIG_chromalock_input_acc_num_mask              (0x00000300)
#define CHROMA_LOCK_CONFIG_lose_chromalock_count_mask                 (0x000000F0)
#define CHROMA_LOCK_CONFIG_lose_chromalock_level_mask                 (0x0000000E)
#define CHROMA_LOCK_CONFIG_lose_chromalock_ckill_mask                 (0x00000001)
#define CHROMA_LOCK_CONFIG_lose_acc_chromalock_level(data)            (0x00007000&((data)<<12))
#define CHROMA_LOCK_CONFIG_chromalock_input_acc_en(data)              (0x00000400&((data)<<10))
#define CHROMA_LOCK_CONFIG_chromalock_input_acc_num(data)             (0x00000300&((data)<<8))
#define CHROMA_LOCK_CONFIG_lose_chromalock_count(data)                (0x000000F0&((data)<<4))
#define CHROMA_LOCK_CONFIG_lose_chromalock_level(data)                (0x0000000E&((data)<<1))
#define CHROMA_LOCK_CONFIG_lose_chromalock_ckill(data)                (0x00000001&(data))
#define CHROMA_LOCK_CONFIG_get_lose_acc_chromalock_level(data)        ((0x00007000&(data))>>12)
#define CHROMA_LOCK_CONFIG_get_chromalock_input_acc_en(data)          ((0x00000400&(data))>>10)
#define CHROMA_LOCK_CONFIG_get_chromalock_input_acc_num(data)         ((0x00000300&(data))>>8)
#define CHROMA_LOCK_CONFIG_get_lose_chromalock_count(data)            ((0x000000F0&(data))>>4)
#define CHROMA_LOCK_CONFIG_get_lose_chromalock_level(data)            ((0x0000000E&(data))>>1)
#define CHROMA_LOCK_CONFIG_get_lose_chromalock_ckill(data)            (0x00000001&(data))


#define CHROMA_LOOPFILTER_GAIN                                        0x1801940c
#define CHROMA_LOOPFILTER_GAIN_reg_addr                               "0xb801940c"
#define CHROMA_LOOPFILTER_GAIN_reg                                    0xb801940c
#define CHROMA_LOOPFILTER_GAIN_inst_addr                              "0x0103"
#define CHROMA_LOOPFILTER_GAIN_inst                                   0x0103
#define CHROMA_LOOPFILTER_GAIN_cnew_gate_en_shift                     (7)
#define CHROMA_LOOPFILTER_GAIN_flag358_cresample_lpf_sel_shift        (2)
#define CHROMA_LOOPFILTER_GAIN_cagc_igain_shift                       (0)
#define CHROMA_LOOPFILTER_GAIN_cnew_gate_en_mask                      (0x00000080)
#define CHROMA_LOOPFILTER_GAIN_flag358_cresample_lpf_sel_mask         (0x0000000C)
#define CHROMA_LOOPFILTER_GAIN_cagc_igain_mask                        (0x00000003)
#define CHROMA_LOOPFILTER_GAIN_cnew_gate_en(data)                     (0x00000080&((data)<<7))
#define CHROMA_LOOPFILTER_GAIN_flag358_cresample_lpf_sel(data)        (0x0000000C&((data)<<2))
#define CHROMA_LOOPFILTER_GAIN_cagc_igain(data)                       (0x00000003&(data))
#define CHROMA_LOOPFILTER_GAIN_get_cnew_gate_en(data)                 ((0x00000080&(data))>>7)
#define CHROMA_LOOPFILTER_GAIN_get_flag358_cresample_lpf_sel(data)    ((0x0000000C&(data))>>2)
#define CHROMA_LOOPFILTER_GAIN_get_cagc_igain(data)                   (0x00000003&(data))


#define CHROMA_LOOPFILTER_STATE                                       0x18019410
#define CHROMA_LOOPFILTER_STATE_reg_addr                              "0xb8019410"
#define CHROMA_LOOPFILTER_STATE_reg                                   0xb8019410
#define CHROMA_LOOPFILTER_STATE_inst_addr                             "0x0104"
#define CHROMA_LOOPFILTER_STATE_inst                                  0x0104
#define CHROMA_LOOPFILTER_STATE_cresample_signed_en_shift             (24)
#define CHROMA_LOOPFILTER_STATE_cloop_freq_offset_limit_en_shift      (20)
#define CHROMA_LOOPFILTER_STATE_cloop_freq_offset_limit_shift         (8)
#define CHROMA_LOOPFILTER_STATE_secam_cresample_lpf_sel_shift         (6)
#define CHROMA_LOOPFILTER_STATE_cresample_lpf_sel_shift               (4)
#define CHROMA_LOOPFILTER_STATE_cstate_shift                          (1)
#define CHROMA_LOOPFILTER_STATE_fixed_cstate_shift                    (0)
#define CHROMA_LOOPFILTER_STATE_cresample_signed_en_mask              (0x01000000)
#define CHROMA_LOOPFILTER_STATE_cloop_freq_offset_limit_en_mask       (0x00100000)
#define CHROMA_LOOPFILTER_STATE_cloop_freq_offset_limit_mask          (0x000FFF00)
#define CHROMA_LOOPFILTER_STATE_secam_cresample_lpf_sel_mask          (0x000000C0)
#define CHROMA_LOOPFILTER_STATE_cresample_lpf_sel_mask                (0x00000030)
#define CHROMA_LOOPFILTER_STATE_cstate_mask                           (0x0000000E)
#define CHROMA_LOOPFILTER_STATE_fixed_cstate_mask                     (0x00000001)
#define CHROMA_LOOPFILTER_STATE_cresample_signed_en(data)             (0x01000000&((data)<<24))
#define CHROMA_LOOPFILTER_STATE_cloop_freq_offset_limit_en(data)      (0x00100000&((data)<<20))
#define CHROMA_LOOPFILTER_STATE_cloop_freq_offset_limit(data)         (0x000FFF00&((data)<<8))
#define CHROMA_LOOPFILTER_STATE_secam_cresample_lpf_sel(data)         (0x000000C0&((data)<<6))
#define CHROMA_LOOPFILTER_STATE_cresample_lpf_sel(data)               (0x00000030&((data)<<4))
#define CHROMA_LOOPFILTER_STATE_cstate(data)                          (0x0000000E&((data)<<1))
#define CHROMA_LOOPFILTER_STATE_fixed_cstate(data)                    (0x00000001&(data))
#define CHROMA_LOOPFILTER_STATE_get_cresample_signed_en(data)         ((0x01000000&(data))>>24)
#define CHROMA_LOOPFILTER_STATE_get_cloop_freq_offset_limit_en(data)  ((0x00100000&(data))>>20)
#define CHROMA_LOOPFILTER_STATE_get_cloop_freq_offset_limit(data)     ((0x000FFF00&(data))>>8)
#define CHROMA_LOOPFILTER_STATE_get_secam_cresample_lpf_sel(data)     ((0x000000C0&(data))>>6)
#define CHROMA_LOOPFILTER_STATE_get_cresample_lpf_sel(data)           ((0x00000030&(data))>>4)
#define CHROMA_LOOPFILTER_STATE_get_cstate(data)                      ((0x0000000E&(data))>>1)
#define CHROMA_LOOPFILTER_STATE_get_fixed_cstate(data)                (0x00000001&(data))


#define CHROMA_AUTOPOS                                                0x18019414
#define CHROMA_AUTOPOS_reg_addr                                       "0xb8019414"
#define CHROMA_AUTOPOS_reg                                            0xb8019414
#define CHROMA_AUTOPOS_inst_addr                                      "0x0105"
#define CHROMA_AUTOPOS_inst                                           0x0105
#define CHROMA_AUTOPOS_chroma_burst5or10_shift                        (6)
#define CHROMA_AUTOPOS_fixed_burstgate_shift                          (5)
#define CHROMA_AUTOPOS_cautopos_shift                                 (0)
#define CHROMA_AUTOPOS_chroma_burst5or10_mask                         (0x00000040)
#define CHROMA_AUTOPOS_fixed_burstgate_mask                           (0x00000020)
#define CHROMA_AUTOPOS_cautopos_mask                                  (0x0000001F)
#define CHROMA_AUTOPOS_chroma_burst5or10(data)                        (0x00000040&((data)<<6))
#define CHROMA_AUTOPOS_fixed_burstgate(data)                          (0x00000020&((data)<<5))
#define CHROMA_AUTOPOS_cautopos(data)                                 (0x0000001F&(data))
#define CHROMA_AUTOPOS_get_chroma_burst5or10(data)                    ((0x00000040&(data))>>6)
#define CHROMA_AUTOPOS_get_fixed_burstgate(data)                      ((0x00000020&(data))>>5)
#define CHROMA_AUTOPOS_get_cautopos(data)                             (0x0000001F&(data))


#define CKILL_LB_SEL                                                  0x18019418
#define CKILL_LB_SEL_reg_addr                                         "0xb8019418"
#define CKILL_LB_SEL_reg                                              0xb8019418
#define CKILL_LB_SEL_inst_addr                                        "0x0106"
#define CKILL_LB_SEL_inst                                             0x0106
#define CKILL_LB_SEL_chromalock_cstate_en_shift                       (7)
#define CKILL_LB_SEL_chromalock_cstate_shift                          (4)
#define CKILL_LB_SEL_ckill_lb_sel_shift                               (0)
#define CKILL_LB_SEL_chromalock_cstate_en_mask                        (0x00000080)
#define CKILL_LB_SEL_chromalock_cstate_mask                           (0x00000070)
#define CKILL_LB_SEL_ckill_lb_sel_mask                                (0x00000001)
#define CKILL_LB_SEL_chromalock_cstate_en(data)                       (0x00000080&((data)<<7))
#define CKILL_LB_SEL_chromalock_cstate(data)                          (0x00000070&((data)<<4))
#define CKILL_LB_SEL_ckill_lb_sel(data)                               (0x00000001&(data))
#define CKILL_LB_SEL_get_chromalock_cstate_en(data)                   ((0x00000080&(data))>>7)
#define CKILL_LB_SEL_get_chromalock_cstate(data)                      ((0x00000070&(data))>>4)
#define CKILL_LB_SEL_get_ckill_lb_sel(data)                           (0x00000001&(data))


#define CKILL_GAIN_KILL_THL                                           0x1801941c
#define CKILL_GAIN_KILL_THL_reg_addr                                  "0xb801941c"
#define CKILL_GAIN_KILL_THL_reg                                       0xb801941c
#define CKILL_GAIN_KILL_THL_inst_addr                                 "0x0107"
#define CKILL_GAIN_KILL_THL_inst                                      0x0107
#define CKILL_GAIN_KILL_THL_ckill_level_user_offset_en_shift          (31)
#define CKILL_GAIN_KILL_THL_ckill_level_user_offset_shift             (16)
#define CKILL_GAIN_KILL_THL_ckill_level_user_mode_en_shift            (15)
#define CKILL_GAIN_KILL_THL_ckill_level_user_mode_value_shift         (0)
#define CKILL_GAIN_KILL_THL_ckill_level_user_offset_en_mask           (0x80000000)
#define CKILL_GAIN_KILL_THL_ckill_level_user_offset_mask              (0x3FFF0000)
#define CKILL_GAIN_KILL_THL_ckill_level_user_mode_en_mask             (0x00008000)
#define CKILL_GAIN_KILL_THL_ckill_level_user_mode_value_mask          (0x00003FFF)
#define CKILL_GAIN_KILL_THL_ckill_level_user_offset_en(data)          (0x80000000&((data)<<31))
#define CKILL_GAIN_KILL_THL_ckill_level_user_offset(data)             (0x3FFF0000&((data)<<16))
#define CKILL_GAIN_KILL_THL_ckill_level_user_mode_en(data)            (0x00008000&((data)<<15))
#define CKILL_GAIN_KILL_THL_ckill_level_user_mode_value(data)         (0x00003FFF&(data))
#define CKILL_GAIN_KILL_THL_get_ckill_level_user_offset_en(data)      ((0x80000000&(data))>>31)
#define CKILL_GAIN_KILL_THL_get_ckill_level_user_offset(data)         ((0x3FFF0000&(data))>>16)
#define CKILL_GAIN_KILL_THL_get_ckill_level_user_mode_en(data)        ((0x00008000&(data))>>15)
#define CKILL_GAIN_KILL_THL_get_ckill_level_user_mode_value(data)     (0x00003FFF&(data))


#define CSTATE_CTRL                                                   0x18019420
#define CSTATE_CTRL_reg_addr                                          "0xb8019420"
#define CSTATE_CTRL_reg                                               0xb8019420
#define CSTATE_CTRL_inst_addr                                         "0x0108"
#define CSTATE_CTRL_inst                                              0x0108
#define CSTATE_CTRL_badedit_noisy_off_en_shift                        (24)
#define CSTATE_CTRL_badedit_in_noise_thr_shift                        (16)
#define CSTATE_CTRL_badedit_out_noise_thr_shift                       (8)
#define CSTATE_CTRL_fast_lock_en_shift                                (7)
#define CSTATE_CTRL_phase_fast_lock_en_shift                          (6)
#define CSTATE_CTRL_badedit_phase_lock_en_shift                       (5)
#define CSTATE_CTRL_badedit_pulse_detect_shift                        (4)
#define CSTATE_CTRL_bad_phase_detect_shift                            (3)
#define CSTATE_CTRL_badedit_line_num_shift                            (0)
#define CSTATE_CTRL_badedit_noisy_off_en_mask                         (0x01000000)
#define CSTATE_CTRL_badedit_in_noise_thr_mask                         (0x00FF0000)
#define CSTATE_CTRL_badedit_out_noise_thr_mask                        (0x0000FF00)
#define CSTATE_CTRL_fast_lock_en_mask                                 (0x00000080)
#define CSTATE_CTRL_phase_fast_lock_en_mask                           (0x00000040)
#define CSTATE_CTRL_badedit_phase_lock_en_mask                        (0x00000020)
#define CSTATE_CTRL_badedit_pulse_detect_mask                         (0x00000010)
#define CSTATE_CTRL_bad_phase_detect_mask                             (0x00000008)
#define CSTATE_CTRL_badedit_line_num_mask                             (0x00000007)
#define CSTATE_CTRL_badedit_noisy_off_en(data)                        (0x01000000&((data)<<24))
#define CSTATE_CTRL_badedit_in_noise_thr(data)                        (0x00FF0000&((data)<<16))
#define CSTATE_CTRL_badedit_out_noise_thr(data)                       (0x0000FF00&((data)<<8))
#define CSTATE_CTRL_fast_lock_en(data)                                (0x00000080&((data)<<7))
#define CSTATE_CTRL_phase_fast_lock_en(data)                          (0x00000040&((data)<<6))
#define CSTATE_CTRL_badedit_phase_lock_en(data)                       (0x00000020&((data)<<5))
#define CSTATE_CTRL_badedit_pulse_detect(data)                        (0x00000010&((data)<<4))
#define CSTATE_CTRL_bad_phase_detect(data)                            (0x00000008&((data)<<3))
#define CSTATE_CTRL_badedit_line_num(data)                            (0x00000007&(data))
#define CSTATE_CTRL_get_badedit_noisy_off_en(data)                    ((0x01000000&(data))>>24)
#define CSTATE_CTRL_get_badedit_in_noise_thr(data)                    ((0x00FF0000&(data))>>16)
#define CSTATE_CTRL_get_badedit_out_noise_thr(data)                   ((0x0000FF00&(data))>>8)
#define CSTATE_CTRL_get_fast_lock_en(data)                            ((0x00000080&(data))>>7)
#define CSTATE_CTRL_get_phase_fast_lock_en(data)                      ((0x00000040&(data))>>6)
#define CSTATE_CTRL_get_badedit_phase_lock_en(data)                   ((0x00000020&(data))>>5)
#define CSTATE_CTRL_get_badedit_pulse_detect(data)                    ((0x00000010&(data))>>4)
#define CSTATE_CTRL_get_bad_phase_detect(data)                        ((0x00000008&(data))>>3)
#define CSTATE_CTRL_get_badedit_line_num(data)                        (0x00000007&(data))


#define BADEDIT_TH                                                    0x18019424
#define BADEDIT_TH_reg_addr                                           "0xb8019424"
#define BADEDIT_TH_reg                                                0xb8019424
#define BADEDIT_TH_inst_addr                                          "0x0109"
#define BADEDIT_TH_inst                                               0x0109
#define BADEDIT_TH_badedit_th_shift                                   (0)
#define BADEDIT_TH_badedit_th_mask                                    (0x000000FF)
#define BADEDIT_TH_badedit_th(data)                                   (0x000000FF&(data))
#define BADEDIT_TH_get_badedit_th(data)                               (0x000000FF&(data))


#define BADPHASE_TH                                                   0x18019428
#define BADPHASE_TH_reg_addr                                          "0xb8019428"
#define BADPHASE_TH_reg                                               0xb8019428
#define BADPHASE_TH_inst_addr                                         "0x010A"
#define BADPHASE_TH_inst                                              0x010A
#define BADPHASE_TH_badphase_th_shift                                 (0)
#define BADPHASE_TH_badphase_th_mask                                  (0x000000FF)
#define BADPHASE_TH_badphase_th(data)                                 (0x000000FF&(data))
#define BADPHASE_TH_get_badphase_th(data)                             (0x000000FF&(data))


#define CSTATE_LINE_NUM                                               0x1801942c
#define CSTATE_LINE_NUM_reg_addr                                      "0xb801942c"
#define CSTATE_LINE_NUM_reg                                           0xb801942c
#define CSTATE_LINE_NUM_inst_addr                                     "0x010B"
#define CSTATE_LINE_NUM_inst                                          0x010B
#define CSTATE_LINE_NUM_cstate_line_num_shift                         (0)
#define CSTATE_LINE_NUM_cstate_line_num_mask                          (0x000000FF)
#define CSTATE_LINE_NUM_cstate_line_num(data)                         (0x000000FF&(data))
#define CSTATE_LINE_NUM_get_cstate_line_num(data)                     (0x000000FF&(data))


#define CHROMA_AGC_PEAK_CTRL                                          0x18019430
#define CHROMA_AGC_PEAK_CTRL_reg_addr                                 "0xb8019430"
#define CHROMA_AGC_PEAK_CTRL_reg                                      0xb8019430
#define CHROMA_AGC_PEAK_CTRL_inst_addr                                "0x010C"
#define CHROMA_AGC_PEAK_CTRL_inst                                     0x010C
#define CHROMA_AGC_PEAK_CTRL_cpeak_noisy_act_en_pll_shift             (29)
#define CHROMA_AGC_PEAK_CTRL_cpeak_noisy_act_en_shift                 (28)
#define CHROMA_AGC_PEAK_CTRL_cpeak_noise_thr2_shift                   (20)
#define CHROMA_AGC_PEAK_CTRL_cpeak_noise_thr1_shift                   (12)
#define CHROMA_AGC_PEAK_CTRL_chroma_peak_en_pll_shift                 (8)
#define CHROMA_AGC_PEAK_CTRL_new_cgain_level_en_shift                 (7)
#define CHROMA_AGC_PEAK_CTRL_chroma_peak_en_shift                     (6)
#define CHROMA_AGC_PEAK_CTRL_chroma_agc_peak_cnt_shift                (0)
#define CHROMA_AGC_PEAK_CTRL_cpeak_noisy_act_en_pll_mask              (0x20000000)
#define CHROMA_AGC_PEAK_CTRL_cpeak_noisy_act_en_mask                  (0x10000000)
#define CHROMA_AGC_PEAK_CTRL_cpeak_noise_thr2_mask                    (0x0FF00000)
#define CHROMA_AGC_PEAK_CTRL_cpeak_noise_thr1_mask                    (0x000FF000)
#define CHROMA_AGC_PEAK_CTRL_chroma_peak_en_pll_mask                  (0x00000100)
#define CHROMA_AGC_PEAK_CTRL_new_cgain_level_en_mask                  (0x00000080)
#define CHROMA_AGC_PEAK_CTRL_chroma_peak_en_mask                      (0x00000040)
#define CHROMA_AGC_PEAK_CTRL_chroma_agc_peak_cnt_mask                 (0x0000003F)
#define CHROMA_AGC_PEAK_CTRL_cpeak_noisy_act_en_pll(data)             (0x20000000&((data)<<29))
#define CHROMA_AGC_PEAK_CTRL_cpeak_noisy_act_en(data)                 (0x10000000&((data)<<28))
#define CHROMA_AGC_PEAK_CTRL_cpeak_noise_thr2(data)                   (0x0FF00000&((data)<<20))
#define CHROMA_AGC_PEAK_CTRL_cpeak_noise_thr1(data)                   (0x000FF000&((data)<<12))
#define CHROMA_AGC_PEAK_CTRL_chroma_peak_en_pll(data)                 (0x00000100&((data)<<8))
#define CHROMA_AGC_PEAK_CTRL_new_cgain_level_en(data)                 (0x00000080&((data)<<7))
#define CHROMA_AGC_PEAK_CTRL_chroma_peak_en(data)                     (0x00000040&((data)<<6))
#define CHROMA_AGC_PEAK_CTRL_chroma_agc_peak_cnt(data)                (0x0000003F&(data))
#define CHROMA_AGC_PEAK_CTRL_get_cpeak_noisy_act_en_pll(data)         ((0x20000000&(data))>>29)
#define CHROMA_AGC_PEAK_CTRL_get_cpeak_noisy_act_en(data)             ((0x10000000&(data))>>28)
#define CHROMA_AGC_PEAK_CTRL_get_cpeak_noise_thr2(data)               ((0x0FF00000&(data))>>20)
#define CHROMA_AGC_PEAK_CTRL_get_cpeak_noise_thr1(data)               ((0x000FF000&(data))>>12)
#define CHROMA_AGC_PEAK_CTRL_get_chroma_peak_en_pll(data)             ((0x00000100&(data))>>8)
#define CHROMA_AGC_PEAK_CTRL_get_new_cgain_level_en(data)             ((0x00000080&(data))>>7)
#define CHROMA_AGC_PEAK_CTRL_get_chroma_peak_en(data)                 ((0x00000040&(data))>>6)
#define CHROMA_AGC_PEAK_CTRL_get_chroma_agc_peak_cnt(data)            (0x0000003F&(data))


#define CHROMA_AGC_PEAK_NOMINAL                                       0x18019434
#define CHROMA_AGC_PEAK_NOMINAL_reg_addr                              "0xb8019434"
#define CHROMA_AGC_PEAK_NOMINAL_reg                                   0xb8019434
#define CHROMA_AGC_PEAK_NOMINAL_inst_addr                             "0x010D"
#define CHROMA_AGC_PEAK_NOMINAL_inst                                  0x010D
#define CHROMA_AGC_PEAK_NOMINAL_chroma_agc_peak_nominal_shift         (0)
#define CHROMA_AGC_PEAK_NOMINAL_chroma_agc_peak_nominal_mask          (0x000000FF)
#define CHROMA_AGC_PEAK_NOMINAL_chroma_agc_peak_nominal(data)         (0x000000FF&(data))
#define CHROMA_AGC_PEAK_NOMINAL_get_chroma_agc_peak_nominal(data)     (0x000000FF&(data))


#define CLOSE_CKILL_LOOPFILTER                                        0x18019438
#define CLOSE_CKILL_LOOPFILTER_reg_addr                               "0xb8019438"
#define CLOSE_CKILL_LOOPFILTER_reg                                    0xb8019438
#define CLOSE_CKILL_LOOPFILTER_inst_addr                              "0x010E"
#define CLOSE_CKILL_LOOPFILTER_inst                                   0x010E
#define CLOSE_CKILL_LOOPFILTER_close_ckill_loopfilter_shift           (17)
#define CLOSE_CKILL_LOOPFILTER_cagc_upper_xroot2_en_shift             (16)
#define CLOSE_CKILL_LOOPFILTER_cagc_upper_shift                       (0)
#define CLOSE_CKILL_LOOPFILTER_close_ckill_loopfilter_mask            (0x00020000)
#define CLOSE_CKILL_LOOPFILTER_cagc_upper_xroot2_en_mask              (0x00010000)
#define CLOSE_CKILL_LOOPFILTER_cagc_upper_mask                        (0x00003FFF)
#define CLOSE_CKILL_LOOPFILTER_close_ckill_loopfilter(data)           (0x00020000&((data)<<17))
#define CLOSE_CKILL_LOOPFILTER_cagc_upper_xroot2_en(data)             (0x00010000&((data)<<16))
#define CLOSE_CKILL_LOOPFILTER_cagc_upper(data)                       (0x00003FFF&(data))
#define CLOSE_CKILL_LOOPFILTER_get_close_ckill_loopfilter(data)       ((0x00020000&(data))>>17)
#define CLOSE_CKILL_LOOPFILTER_get_cagc_upper_xroot2_en(data)         ((0x00010000&(data))>>16)
#define CLOSE_CKILL_LOOPFILTER_get_cagc_upper(data)                   (0x00003FFF&(data))


#define CAGC_PEAK_CTRL1                                               0x1801943c
#define CAGC_PEAK_CTRL1_reg_addr                                      "0xb801943c"
#define CAGC_PEAK_CTRL1_reg                                           0xb801943c
#define CAGC_PEAK_CTRL1_inst_addr                                     "0x010F"
#define CAGC_PEAK_CTRL1_inst                                          0x010F
#define CAGC_PEAK_CTRL1_cagc_peak_err_adj_en_shift                    (7)
#define CAGC_PEAK_CTRL1_cagc_burst_err_adj_en_shift                   (6)
#define CAGC_PEAK_CTRL1_cagc_peak_err_diff_sel_shift                  (0)
#define CAGC_PEAK_CTRL1_cagc_peak_err_adj_en_mask                     (0x00000080)
#define CAGC_PEAK_CTRL1_cagc_burst_err_adj_en_mask                    (0x00000040)
#define CAGC_PEAK_CTRL1_cagc_peak_err_diff_sel_mask                   (0x0000003F)
#define CAGC_PEAK_CTRL1_cagc_peak_err_adj_en(data)                    (0x00000080&((data)<<7))
#define CAGC_PEAK_CTRL1_cagc_burst_err_adj_en(data)                   (0x00000040&((data)<<6))
#define CAGC_PEAK_CTRL1_cagc_peak_err_diff_sel(data)                  (0x0000003F&(data))
#define CAGC_PEAK_CTRL1_get_cagc_peak_err_adj_en(data)                ((0x00000080&(data))>>7)
#define CAGC_PEAK_CTRL1_get_cagc_burst_err_adj_en(data)               ((0x00000040&(data))>>6)
#define CAGC_PEAK_CTRL1_get_cagc_peak_err_diff_sel(data)              (0x0000003F&(data))


#define CAGC_PEAK_CTRL2                                               0x18019440
#define CAGC_PEAK_CTRL2_reg_addr                                      "0xb8019440"
#define CAGC_PEAK_CTRL2_reg                                           0xb8019440
#define CAGC_PEAK_CTRL2_inst_addr                                     "0x0110"
#define CAGC_PEAK_CTRL2_inst                                          0x0110
#define CAGC_PEAK_CTRL2_cagc_burst_err_diff_sel_shift                 (0)
#define CAGC_PEAK_CTRL2_cagc_burst_err_diff_sel_mask                  (0x0000003F)
#define CAGC_PEAK_CTRL2_cagc_burst_err_diff_sel(data)                 (0x0000003F&(data))
#define CAGC_PEAK_CTRL2_get_cagc_burst_err_diff_sel(data)             (0x0000003F&(data))


#define CAGC_PEAK_CTRL3                                               0x18019444
#define CAGC_PEAK_CTRL3_reg_addr                                      "0xb8019444"
#define CAGC_PEAK_CTRL3_reg                                           0xb8019444
#define CAGC_PEAK_CTRL3_inst_addr                                     "0x0111"
#define CAGC_PEAK_CTRL3_inst                                          0x0111
#define CAGC_PEAK_CTRL3_cagc_peak_luma_ratio_shift                    (0)
#define CAGC_PEAK_CTRL3_cagc_peak_luma_ratio_mask                     (0x0000003F)
#define CAGC_PEAK_CTRL3_cagc_peak_luma_ratio(data)                    (0x0000003F&(data))
#define CAGC_PEAK_CTRL3_get_cagc_peak_luma_ratio(data)                (0x0000003F&(data))


#define CHROMA_DELAY_CTRL                                             0x18019448
#define CHROMA_DELAY_CTRL_reg_addr                                    "0xb8019448"
#define CHROMA_DELAY_CTRL_reg                                         0xb8019448
#define CHROMA_DELAY_CTRL_inst_addr                                   "0x0112"
#define CHROMA_DELAY_CTRL_inst                                        0x0112
#define CHROMA_DELAY_CTRL_cb_delay_shift                              (4)
#define CHROMA_DELAY_CTRL_cr_delay_shift                              (0)
#define CHROMA_DELAY_CTRL_cb_delay_mask                               (0x00000070)
#define CHROMA_DELAY_CTRL_cr_delay_mask                               (0x00000007)
#define CHROMA_DELAY_CTRL_cb_delay(data)                              (0x00000070&((data)<<4))
#define CHROMA_DELAY_CTRL_cr_delay(data)                              (0x00000007&(data))
#define CHROMA_DELAY_CTRL_get_cb_delay(data)                          ((0x00000070&(data))>>4)
#define CHROMA_DELAY_CTRL_get_cr_delay(data)                          (0x00000007&(data))


#define BURST_CGAIN_CTRL                                              0x1801944c
#define BURST_CGAIN_CTRL_reg_addr                                     "0xb801944c"
#define BURST_CGAIN_CTRL_reg                                          0xb801944c
#define BURST_CGAIN_CTRL_inst_addr                                    "0x0113"
#define BURST_CGAIN_CTRL_inst                                         0x0113
#define BURST_CGAIN_CTRL_flag_burst_x4_shift                          (1)
#define BURST_CGAIN_CTRL_burst_cgain_x4_en_shift                      (0)
#define BURST_CGAIN_CTRL_flag_burst_x4_mask                           (0x00000002)
#define BURST_CGAIN_CTRL_burst_cgain_x4_en_mask                       (0x00000001)
#define BURST_CGAIN_CTRL_flag_burst_x4(data)                          (0x00000002&((data)<<1))
#define BURST_CGAIN_CTRL_burst_cgain_x4_en(data)                      (0x00000001&(data))
#define BURST_CGAIN_CTRL_get_flag_burst_x4(data)                      ((0x00000002&(data))>>1)
#define BURST_CGAIN_CTRL_get_burst_cgain_x4_en(data)                  (0x00000001&(data))


#define BURST_CGAIN_MAG_TH                                            0x18019450
#define BURST_CGAIN_MAG_TH_reg_addr                                   "0xb8019450"
#define BURST_CGAIN_MAG_TH_reg                                        0xb8019450
#define BURST_CGAIN_MAG_TH_inst_addr                                  "0x0114"
#define BURST_CGAIN_MAG_TH_inst                                       0x0114
#define BURST_CGAIN_MAG_TH_burst_cgain_mag_th_shift                   (0)
#define BURST_CGAIN_MAG_TH_burst_cgain_mag_th_mask                    (0x000000FF)
#define BURST_CGAIN_MAG_TH_burst_cgain_mag_th(data)                   (0x000000FF&(data))
#define BURST_CGAIN_MAG_TH_get_burst_cgain_mag_th(data)               (0x000000FF&(data))


#define FLAG358_CDTO_INC4                                             0x18019454
#define FLAG358_CDTO_INC4_reg_addr                                    "0xb8019454"
#define FLAG358_CDTO_INC4_reg                                         0xb8019454
#define FLAG358_CDTO_INC4_inst_addr                                   "0x0115"
#define FLAG358_CDTO_INC4_inst                                        0x0115
#define FLAG358_CDTO_INC4_flag358_iir_en_shift                        (31)
#define FLAG358_CDTO_INC4_flag358_iir_cunlock_en_shift                (30)
#define FLAG358_CDTO_INC4_flag358_cdto_inc_shift                      (0)
#define FLAG358_CDTO_INC4_flag358_iir_en_mask                         (0x80000000)
#define FLAG358_CDTO_INC4_flag358_iir_cunlock_en_mask                 (0x40000000)
#define FLAG358_CDTO_INC4_flag358_cdto_inc_mask                       (0x3FFFFFFF)
#define FLAG358_CDTO_INC4_flag358_iir_en(data)                        (0x80000000&((data)<<31))
#define FLAG358_CDTO_INC4_flag358_iir_cunlock_en(data)                (0x40000000&((data)<<30))
#define FLAG358_CDTO_INC4_flag358_cdto_inc(data)                      (0x3FFFFFFF&(data))
#define FLAG358_CDTO_INC4_get_flag358_iir_en(data)                    ((0x80000000&(data))>>31)
#define FLAG358_CDTO_INC4_get_flag358_iir_cunlock_en(data)            ((0x40000000&(data))>>30)
#define FLAG358_CDTO_INC4_get_flag358_cdto_inc(data)                  (0x3FFFFFFF&(data))


#define SEPARATE_443_358_NEW_FUNCTION_1                               0x18019458
#define SEPARATE_443_358_NEW_FUNCTION_1_reg_addr                      "0xb8019458"
#define SEPARATE_443_358_NEW_FUNCTION_1_reg                           0xb8019458
#define SEPARATE_443_358_NEW_FUNCTION_1_inst_addr                     "0x0116"
#define SEPARATE_443_358_NEW_FUNCTION_1_inst                          0x0116
#define SEPARATE_443_358_NEW_FUNCTION_1_burst_location_fix_en_shift   (31)
#define SEPARATE_443_358_NEW_FUNCTION_1_burst_location_sel_clock_shift  (30)
#define SEPARATE_443_358_NEW_FUNCTION_1_burst_location_selreg_en_shift  (29)
#define SEPARATE_443_358_NEW_FUNCTION_1_normal_burst_locationreg_en_shift  (28)
#define SEPARATE_443_358_NEW_FUNCTION_1_burst_location_sel_modify_sel_shift  (25)
#define SEPARATE_443_358_NEW_FUNCTION_1_burst_location_sel_modify_en_shift  (24)
#define SEPARATE_443_358_NEW_FUNCTION_1_burst_location_center_modify_sel_shift  (21)
#define SEPARATE_443_358_NEW_FUNCTION_1_burst_location_center_modify_en_shift  (20)
#define SEPARATE_443_358_NEW_FUNCTION_1_burst_location_fix_shift      (8)
#define SEPARATE_443_358_NEW_FUNCTION_1_burst_location_sel_shift      (4)
#define SEPARATE_443_358_NEW_FUNCTION_1_burst_location_lpf_reset_shift  (3)
#define SEPARATE_443_358_NEW_FUNCTION_1_burst_location_rst_en_shift   (2)
#define SEPARATE_443_358_NEW_FUNCTION_1_auto_burst_location_en_shift  (1)
#define SEPARATE_443_358_NEW_FUNCTION_1_new_coef_sel_shift            (0)
#define SEPARATE_443_358_NEW_FUNCTION_1_burst_location_fix_en_mask    (0x80000000)
#define SEPARATE_443_358_NEW_FUNCTION_1_burst_location_sel_clock_mask (0x40000000)
#define SEPARATE_443_358_NEW_FUNCTION_1_burst_location_selreg_en_mask (0x20000000)
#define SEPARATE_443_358_NEW_FUNCTION_1_normal_burst_locationreg_en_mask  (0x10000000)
#define SEPARATE_443_358_NEW_FUNCTION_1_burst_location_sel_modify_sel_mask  (0x0E000000)
#define SEPARATE_443_358_NEW_FUNCTION_1_burst_location_sel_modify_en_mask  (0x01000000)
#define SEPARATE_443_358_NEW_FUNCTION_1_burst_location_center_modify_sel_mask  (0x00E00000)
#define SEPARATE_443_358_NEW_FUNCTION_1_burst_location_center_modify_en_mask  (0x00100000)
#define SEPARATE_443_358_NEW_FUNCTION_1_burst_location_fix_mask       (0x0007FF00)
#define SEPARATE_443_358_NEW_FUNCTION_1_burst_location_sel_mask       (0x00000030)
#define SEPARATE_443_358_NEW_FUNCTION_1_burst_location_lpf_reset_mask (0x00000008)
#define SEPARATE_443_358_NEW_FUNCTION_1_burst_location_rst_en_mask    (0x00000004)
#define SEPARATE_443_358_NEW_FUNCTION_1_auto_burst_location_en_mask   (0x00000002)
#define SEPARATE_443_358_NEW_FUNCTION_1_new_coef_sel_mask             (0x00000001)
#define SEPARATE_443_358_NEW_FUNCTION_1_burst_location_fix_en(data)   (0x80000000&((data)<<31))
#define SEPARATE_443_358_NEW_FUNCTION_1_burst_location_sel_clock(data)  (0x40000000&((data)<<30))
#define SEPARATE_443_358_NEW_FUNCTION_1_burst_location_selreg_en(data)  (0x20000000&((data)<<29))
#define SEPARATE_443_358_NEW_FUNCTION_1_normal_burst_locationreg_en(data)  (0x10000000&((data)<<28))
#define SEPARATE_443_358_NEW_FUNCTION_1_burst_location_sel_modify_sel(data)  (0x0E000000&((data)<<25))
#define SEPARATE_443_358_NEW_FUNCTION_1_burst_location_sel_modify_en(data)  (0x01000000&((data)<<24))
#define SEPARATE_443_358_NEW_FUNCTION_1_burst_location_center_modify_sel(data)  (0x00E00000&((data)<<21))
#define SEPARATE_443_358_NEW_FUNCTION_1_burst_location_center_modify_en(data)  (0x00100000&((data)<<20))
#define SEPARATE_443_358_NEW_FUNCTION_1_burst_location_fix(data)      (0x0007FF00&((data)<<8))
#define SEPARATE_443_358_NEW_FUNCTION_1_burst_location_sel(data)      (0x00000030&((data)<<4))
#define SEPARATE_443_358_NEW_FUNCTION_1_burst_location_lpf_reset(data)  (0x00000008&((data)<<3))
#define SEPARATE_443_358_NEW_FUNCTION_1_burst_location_rst_en(data)   (0x00000004&((data)<<2))
#define SEPARATE_443_358_NEW_FUNCTION_1_auto_burst_location_en(data)  (0x00000002&((data)<<1))
#define SEPARATE_443_358_NEW_FUNCTION_1_new_coef_sel(data)            (0x00000001&(data))
#define SEPARATE_443_358_NEW_FUNCTION_1_get_burst_location_fix_en(data)  ((0x80000000&(data))>>31)
#define SEPARATE_443_358_NEW_FUNCTION_1_get_burst_location_sel_clock(data)  ((0x40000000&(data))>>30)
#define SEPARATE_443_358_NEW_FUNCTION_1_get_burst_location_selreg_en(data)  ((0x20000000&(data))>>29)
#define SEPARATE_443_358_NEW_FUNCTION_1_get_normal_burst_locationreg_en(data)  ((0x10000000&(data))>>28)
#define SEPARATE_443_358_NEW_FUNCTION_1_get_burst_location_sel_modify_sel(data)  ((0x0E000000&(data))>>25)
#define SEPARATE_443_358_NEW_FUNCTION_1_get_burst_location_sel_modify_en(data)  ((0x01000000&(data))>>24)
#define SEPARATE_443_358_NEW_FUNCTION_1_get_burst_location_center_modify_sel(data)  ((0x00E00000&(data))>>21)
#define SEPARATE_443_358_NEW_FUNCTION_1_get_burst_location_center_modify_en(data)  ((0x00100000&(data))>>20)
#define SEPARATE_443_358_NEW_FUNCTION_1_get_burst_location_fix(data)  ((0x0007FF00&(data))>>8)
#define SEPARATE_443_358_NEW_FUNCTION_1_get_burst_location_sel(data)  ((0x00000030&(data))>>4)
#define SEPARATE_443_358_NEW_FUNCTION_1_get_burst_location_lpf_reset(data)  ((0x00000008&(data))>>3)
#define SEPARATE_443_358_NEW_FUNCTION_1_get_burst_location_rst_en(data)  ((0x00000004&(data))>>2)
#define SEPARATE_443_358_NEW_FUNCTION_1_get_auto_burst_location_en(data)  ((0x00000002&(data))>>1)
#define SEPARATE_443_358_NEW_FUNCTION_1_get_new_coef_sel(data)        (0x00000001&(data))


#define SEPARATE_443_358_NEW_FUNCTION_2                               0x1801945c
#define SEPARATE_443_358_NEW_FUNCTION_2_reg_addr                      "0xb801945c"
#define SEPARATE_443_358_NEW_FUNCTION_2_reg                           0xb801945c
#define SEPARATE_443_358_NEW_FUNCTION_2_inst_addr                     "0x0117"
#define SEPARATE_443_358_NEW_FUNCTION_2_inst                          0x0117
#define SEPARATE_443_358_NEW_FUNCTION_2_burst_location_result_shift   (16)
#define SEPARATE_443_358_NEW_FUNCTION_2_normal_burst_location_shift   (0)
#define SEPARATE_443_358_NEW_FUNCTION_2_burst_location_result_mask    (0x07FF0000)
#define SEPARATE_443_358_NEW_FUNCTION_2_normal_burst_location_mask    (0x000007FF)
#define SEPARATE_443_358_NEW_FUNCTION_2_burst_location_result(data)   (0x07FF0000&((data)<<16))
#define SEPARATE_443_358_NEW_FUNCTION_2_normal_burst_location(data)   (0x000007FF&(data))
#define SEPARATE_443_358_NEW_FUNCTION_2_get_burst_location_result(data)  ((0x07FF0000&(data))>>16)
#define SEPARATE_443_358_NEW_FUNCTION_2_get_normal_burst_location(data)  (0x000007FF&(data))


#define SEPARATE_443_358_NEW_FUNCTION_3                               0x18019460
#define SEPARATE_443_358_NEW_FUNCTION_3_reg_addr                      "0xb8019460"
#define SEPARATE_443_358_NEW_FUNCTION_3_reg                           0xb8019460
#define SEPARATE_443_358_NEW_FUNCTION_3_inst_addr                     "0x0118"
#define SEPARATE_443_358_NEW_FUNCTION_3_inst                          0x0118
#define SEPARATE_443_358_NEW_FUNCTION_3_wide_burst_location_modify_sel_shift  (29)
#define SEPARATE_443_358_NEW_FUNCTION_3_wide_burst_location_modify_en_shift  (28)
#define SEPARATE_443_358_NEW_FUNCTION_3_wide_burst_location_end_shift (16)
#define SEPARATE_443_358_NEW_FUNCTION_3_wide_burst_location_endreg_en_shift  (13)
#define SEPARATE_443_358_NEW_FUNCTION_3_wide_burst_location_startreg_en_shift  (12)
#define SEPARATE_443_358_NEW_FUNCTION_3_wide_burst_location_start_shift  (0)
#define SEPARATE_443_358_NEW_FUNCTION_3_wide_burst_location_modify_sel_mask  (0xE0000000)
#define SEPARATE_443_358_NEW_FUNCTION_3_wide_burst_location_modify_en_mask  (0x10000000)
#define SEPARATE_443_358_NEW_FUNCTION_3_wide_burst_location_end_mask  (0x07FF0000)
#define SEPARATE_443_358_NEW_FUNCTION_3_wide_burst_location_endreg_en_mask  (0x00002000)
#define SEPARATE_443_358_NEW_FUNCTION_3_wide_burst_location_startreg_en_mask  (0x00001000)
#define SEPARATE_443_358_NEW_FUNCTION_3_wide_burst_location_start_mask  (0x000007FF)
#define SEPARATE_443_358_NEW_FUNCTION_3_wide_burst_location_modify_sel(data)  (0xE0000000&((data)<<29))
#define SEPARATE_443_358_NEW_FUNCTION_3_wide_burst_location_modify_en(data)  (0x10000000&((data)<<28))
#define SEPARATE_443_358_NEW_FUNCTION_3_wide_burst_location_end(data) (0x07FF0000&((data)<<16))
#define SEPARATE_443_358_NEW_FUNCTION_3_wide_burst_location_endreg_en(data)  (0x00002000&((data)<<13))
#define SEPARATE_443_358_NEW_FUNCTION_3_wide_burst_location_startreg_en(data)  (0x00001000&((data)<<12))
#define SEPARATE_443_358_NEW_FUNCTION_3_wide_burst_location_start(data)  (0x000007FF&(data))
#define SEPARATE_443_358_NEW_FUNCTION_3_get_wide_burst_location_modify_sel(data)  ((0xE0000000&(data))>>29)
#define SEPARATE_443_358_NEW_FUNCTION_3_get_wide_burst_location_modify_en(data)  ((0x10000000&(data))>>28)
#define SEPARATE_443_358_NEW_FUNCTION_3_get_wide_burst_location_end(data)  ((0x07FF0000&(data))>>16)
#define SEPARATE_443_358_NEW_FUNCTION_3_get_wide_burst_location_endreg_en(data)  ((0x00002000&(data))>>13)
#define SEPARATE_443_358_NEW_FUNCTION_3_get_wide_burst_location_startreg_en(data)  ((0x00001000&(data))>>12)
#define SEPARATE_443_358_NEW_FUNCTION_3_get_wide_burst_location_start(data)  (0x000007FF&(data))


#define BURST_LOCATION_STATUS_1                                       0x18019464
#define BURST_LOCATION_STATUS_1_reg_addr                              "0xb8019464"
#define BURST_LOCATION_STATUS_1_reg                                   0xb8019464
#define BURST_LOCATION_STATUS_1_inst_addr                             "0x0119"
#define BURST_LOCATION_STATUS_1_inst                                  0x0119
#define BURST_LOCATION_STATUS_1_burst_location_sel_status_shift       (12)
#define BURST_LOCATION_STATUS_1_normal_burst_location_status_shift    (0)
#define BURST_LOCATION_STATUS_1_burst_location_sel_status_mask        (0x00003000)
#define BURST_LOCATION_STATUS_1_normal_burst_location_status_mask     (0x000007FF)
#define BURST_LOCATION_STATUS_1_burst_location_sel_status(data)       (0x00003000&((data)<<12))
#define BURST_LOCATION_STATUS_1_normal_burst_location_status(data)    (0x000007FF&(data))
#define BURST_LOCATION_STATUS_1_get_burst_location_sel_status(data)   ((0x00003000&(data))>>12)
#define BURST_LOCATION_STATUS_1_get_normal_burst_location_status(data)  (0x000007FF&(data))


#define BURST_LOCATION_STATUS_2                                       0x18019468
#define BURST_LOCATION_STATUS_2_reg_addr                              "0xb8019468"
#define BURST_LOCATION_STATUS_2_reg                                   0xb8019468
#define BURST_LOCATION_STATUS_2_inst_addr                             "0x011A"
#define BURST_LOCATION_STATUS_2_inst                                  0x011A
#define BURST_LOCATION_STATUS_2_wide_burst_location_end_status_shift  (16)
#define BURST_LOCATION_STATUS_2_wide_burst_location_start_status_shift  (0)
#define BURST_LOCATION_STATUS_2_wide_burst_location_end_status_mask   (0x07FF0000)
#define BURST_LOCATION_STATUS_2_wide_burst_location_start_status_mask (0x000007FF)
#define BURST_LOCATION_STATUS_2_wide_burst_location_end_status(data)  (0x07FF0000&((data)<<16))
#define BURST_LOCATION_STATUS_2_wide_burst_location_start_status(data)  (0x000007FF&(data))
#define BURST_LOCATION_STATUS_2_get_wide_burst_location_end_status(data)  ((0x07FF0000&(data))>>16)
#define BURST_LOCATION_STATUS_2_get_wide_burst_location_start_status(data)  (0x000007FF&(data))


#define PALM_FLAG_COMPENSATION1                                       0x18019490
#define PALM_FLAG_COMPENSATION1_reg_addr                              "0xb8019490"
#define PALM_FLAG_COMPENSATION1_reg                                   0xb8019490
#define PALM_FLAG_COMPENSATION1_inst_addr                             "0x0124"
#define PALM_FLAG_COMPENSATION1_inst                                  0x0124
#define PALM_FLAG_COMPENSATION1_flag625_vsync_l_sel_shift             (7)
#define PALM_FLAG_COMPENSATION1_flag625_vsync_l_th_shift              (6)
#define PALM_FLAG_COMPENSATION1_palm_atone_counter_shift              (0)
#define PALM_FLAG_COMPENSATION1_flag625_vsync_l_sel_mask              (0x00000080)
#define PALM_FLAG_COMPENSATION1_flag625_vsync_l_th_mask               (0x00000040)
#define PALM_FLAG_COMPENSATION1_palm_atone_counter_mask               (0x0000003F)
#define PALM_FLAG_COMPENSATION1_flag625_vsync_l_sel(data)             (0x00000080&((data)<<7))
#define PALM_FLAG_COMPENSATION1_flag625_vsync_l_th(data)              (0x00000040&((data)<<6))
#define PALM_FLAG_COMPENSATION1_palm_atone_counter(data)              (0x0000003F&(data))
#define PALM_FLAG_COMPENSATION1_get_flag625_vsync_l_sel(data)         ((0x00000080&(data))>>7)
#define PALM_FLAG_COMPENSATION1_get_flag625_vsync_l_th(data)          ((0x00000040&(data))>>6)
#define PALM_FLAG_COMPENSATION1_get_palm_atone_counter(data)          (0x0000003F&(data))


#define PALM_FLAG_COMPENSATION2                                       0x18019494
#define PALM_FLAG_COMPENSATION2_reg_addr                              "0xb8019494"
#define PALM_FLAG_COMPENSATION2_reg                                   0xb8019494
#define PALM_FLAG_COMPENSATION2_inst_addr                             "0x0125"
#define PALM_FLAG_COMPENSATION2_inst                                  0x0125
#define PALM_FLAG_COMPENSATION2_palm_atone_threshold_shift            (0)
#define PALM_FLAG_COMPENSATION2_palm_atone_threshold_mask             (0x000000FF)
#define PALM_FLAG_COMPENSATION2_palm_atone_threshold(data)            (0x000000FF&(data))
#define PALM_FLAG_COMPENSATION2_get_palm_atone_threshold(data)        (0x000000FF&(data))


#define MANUAL_MODE                                                   0x180194a0
#define MANUAL_MODE_reg_addr                                          "0xb80194a0"
#define MANUAL_MODE_reg                                               0xb80194a0
#define MANUAL_MODE_inst_addr                                         "0x0128"
#define MANUAL_MODE_inst                                              0x0128
#define MANUAL_MODE_colour_mode_dark_check_shift                      (11)
#define MANUAL_MODE_colour_mode_dark_set_shift                        (8)
#define MANUAL_MODE_auto_mode_en_shift                                (7)
#define MANUAL_MODE_auto_625only_en_shift                             (6)
#define MANUAL_MODE_auto_burst_switch_625only_shift                   (5)
#define MANUAL_MODE_state_machine_reset_shift                         (3)
#define MANUAL_MODE_manual_mode_select_shift                          (0)
#define MANUAL_MODE_colour_mode_dark_check_mask                       (0x00000800)
#define MANUAL_MODE_colour_mode_dark_set_mask                         (0x00000700)
#define MANUAL_MODE_auto_mode_en_mask                                 (0x00000080)
#define MANUAL_MODE_auto_625only_en_mask                              (0x00000040)
#define MANUAL_MODE_auto_burst_switch_625only_mask                    (0x00000020)
#define MANUAL_MODE_state_machine_reset_mask                          (0x00000008)
#define MANUAL_MODE_manual_mode_select_mask                           (0x00000007)
#define MANUAL_MODE_colour_mode_dark_check(data)                      (0x00000800&((data)<<11))
#define MANUAL_MODE_colour_mode_dark_set(data)                        (0x00000700&((data)<<8))
#define MANUAL_MODE_auto_mode_en(data)                                (0x00000080&((data)<<7))
#define MANUAL_MODE_auto_625only_en(data)                             (0x00000040&((data)<<6))
#define MANUAL_MODE_auto_burst_switch_625only(data)                   (0x00000020&((data)<<5))
#define MANUAL_MODE_state_machine_reset(data)                         (0x00000008&((data)<<3))
#define MANUAL_MODE_manual_mode_select(data)                          (0x00000007&(data))
#define MANUAL_MODE_get_colour_mode_dark_check(data)                  ((0x00000800&(data))>>11)
#define MANUAL_MODE_get_colour_mode_dark_set(data)                    ((0x00000700&(data))>>8)
#define MANUAL_MODE_get_auto_mode_en(data)                            ((0x00000080&(data))>>7)
#define MANUAL_MODE_get_auto_625only_en(data)                         ((0x00000040&(data))>>6)
#define MANUAL_MODE_get_auto_burst_switch_625only(data)               ((0x00000020&(data))>>5)
#define MANUAL_MODE_get_state_machine_reset(data)                     ((0x00000008&(data))>>3)
#define MANUAL_MODE_get_manual_mode_select(data)                      (0x00000007&(data))


#define MODE_DETECTION_STATUS                                         0x180194a4
#define MODE_DETECTION_STATUS_reg_addr                                "0xb80194a4"
#define MODE_DETECTION_STATUS_reg                                     0xb80194a4
#define MODE_DETECTION_STATUS_inst_addr                               "0x0129"
#define MODE_DETECTION_STATUS_inst                                    0x0129
#define MODE_DETECTION_STATUS_set_mode_status_shift                   (4)
#define MODE_DETECTION_STATUS_decision_mode_status_shift              (0)
#define MODE_DETECTION_STATUS_set_mode_status_mask                    (0x00000070)
#define MODE_DETECTION_STATUS_decision_mode_status_mask               (0x00000007)
#define MODE_DETECTION_STATUS_set_mode_status(data)                   (0x00000070&((data)<<4))
#define MODE_DETECTION_STATUS_decision_mode_status(data)              (0x00000007&(data))
#define MODE_DETECTION_STATUS_get_set_mode_status(data)               ((0x00000070&(data))>>4)
#define MODE_DETECTION_STATUS_get_decision_mode_status(data)          (0x00000007&(data))


#define STATISTIC_AND_DISABLE_MODE                                    0x180194a8
#define STATISTIC_AND_DISABLE_MODE_reg_addr                           "0xb80194a8"
#define STATISTIC_AND_DISABLE_MODE_reg                                0xb80194a8
#define STATISTIC_AND_DISABLE_MODE_inst_addr                          "0x012A"
#define STATISTIC_AND_DISABLE_MODE_inst                               0x012A
#define STATISTIC_AND_DISABLE_MODE_disable_mode_en_shift              (7)
#define STATISTIC_AND_DISABLE_MODE_disable_mode_shift                 (6)
#define STATISTIC_AND_DISABLE_MODE_statistic_number_shift             (0)
#define STATISTIC_AND_DISABLE_MODE_disable_mode_en_mask               (0x00000080)
#define STATISTIC_AND_DISABLE_MODE_disable_mode_mask                  (0x00000040)
#define STATISTIC_AND_DISABLE_MODE_statistic_number_mask              (0x0000003F)
#define STATISTIC_AND_DISABLE_MODE_disable_mode_en(data)              (0x00000080&((data)<<7))
#define STATISTIC_AND_DISABLE_MODE_disable_mode(data)                 (0x00000040&((data)<<6))
#define STATISTIC_AND_DISABLE_MODE_statistic_number(data)             (0x0000003F&(data))
#define STATISTIC_AND_DISABLE_MODE_get_disable_mode_en(data)          ((0x00000080&(data))>>7)
#define STATISTIC_AND_DISABLE_MODE_get_disable_mode(data)             ((0x00000040&(data))>>6)
#define STATISTIC_AND_DISABLE_MODE_get_statistic_number(data)         (0x0000003F&(data))


#define PREFER_MODE                                                   0x180194ac
#define PREFER_MODE_reg_addr                                          "0xb80194ac"
#define PREFER_MODE_reg                                               0xb80194ac
#define PREFER_MODE_inst_addr                                         "0x012B"
#define PREFER_MODE_inst                                              0x012B
#define PREFER_MODE_prefer_ntsc50_paln_shift                          (7)
#define PREFER_MODE_prefer_ntsc443_pal60_shift                        (6)
#define PREFER_MODE_prefer_secam_pali_shift                           (5)
#define PREFER_MODE_prefer_ntsc_palm_shift                            (4)
#define PREFER_MODE_prefer_ntsc50_paln_en_shift                       (3)
#define PREFER_MODE_prefer_ntsc443_pal60_en_shift                     (2)
#define PREFER_MODE_prefer_secam_pali_en_shift                        (1)
#define PREFER_MODE_prefer_ntsc_palm_en_shift                         (0)
#define PREFER_MODE_prefer_ntsc50_paln_mask                           (0x00000080)
#define PREFER_MODE_prefer_ntsc443_pal60_mask                         (0x00000040)
#define PREFER_MODE_prefer_secam_pali_mask                            (0x00000020)
#define PREFER_MODE_prefer_ntsc_palm_mask                             (0x00000010)
#define PREFER_MODE_prefer_ntsc50_paln_en_mask                        (0x00000008)
#define PREFER_MODE_prefer_ntsc443_pal60_en_mask                      (0x00000004)
#define PREFER_MODE_prefer_secam_pali_en_mask                         (0x00000002)
#define PREFER_MODE_prefer_ntsc_palm_en_mask                          (0x00000001)
#define PREFER_MODE_prefer_ntsc50_paln(data)                          (0x00000080&((data)<<7))
#define PREFER_MODE_prefer_ntsc443_pal60(data)                        (0x00000040&((data)<<6))
#define PREFER_MODE_prefer_secam_pali(data)                           (0x00000020&((data)<<5))
#define PREFER_MODE_prefer_ntsc_palm(data)                            (0x00000010&((data)<<4))
#define PREFER_MODE_prefer_ntsc50_paln_en(data)                       (0x00000008&((data)<<3))
#define PREFER_MODE_prefer_ntsc443_pal60_en(data)                     (0x00000004&((data)<<2))
#define PREFER_MODE_prefer_secam_pali_en(data)                        (0x00000002&((data)<<1))
#define PREFER_MODE_prefer_ntsc_palm_en(data)                         (0x00000001&(data))
#define PREFER_MODE_get_prefer_ntsc50_paln(data)                      ((0x00000080&(data))>>7)
#define PREFER_MODE_get_prefer_ntsc443_pal60(data)                    ((0x00000040&(data))>>6)
#define PREFER_MODE_get_prefer_secam_pali(data)                       ((0x00000020&(data))>>5)
#define PREFER_MODE_get_prefer_ntsc_palm(data)                        ((0x00000010&(data))>>4)
#define PREFER_MODE_get_prefer_ntsc50_paln_en(data)                   ((0x00000008&(data))>>3)
#define PREFER_MODE_get_prefer_ntsc443_pal60_en(data)                 ((0x00000004&(data))>>2)
#define PREFER_MODE_get_prefer_secam_pali_en(data)                    ((0x00000002&(data))>>1)
#define PREFER_MODE_get_prefer_ntsc_palm_en(data)                     (0x00000001&(data))


#define STATE_MACHINE_FIX_MODE                                        0x180194b0
#define STATE_MACHINE_FIX_MODE_reg_addr                               "0xb80194b0"
#define STATE_MACHINE_FIX_MODE_reg                                    0xb80194b0
#define STATE_MACHINE_FIX_MODE_inst_addr                              "0x012C"
#define STATE_MACHINE_FIX_MODE_inst                                   0x012C
#define STATE_MACHINE_FIX_MODE_fix_625flag_en_shift                   (7)
#define STATE_MACHINE_FIX_MODE_fix_443flag_en_shift                   (6)
#define STATE_MACHINE_FIX_MODE_fix_palorflag_en_shift                 (5)
#define STATE_MACHINE_FIX_MODE_fix_secamflag_en_shift                 (4)
#define STATE_MACHINE_FIX_MODE_fix_625_h_shift                        (3)
#define STATE_MACHINE_FIX_MODE_fix_443_h_shift                        (2)
#define STATE_MACHINE_FIX_MODE_fix_palor_h_shift                      (1)
#define STATE_MACHINE_FIX_MODE_fix_secam_h_shift                      (0)
#define STATE_MACHINE_FIX_MODE_fix_625flag_en_mask                    (0x00000080)
#define STATE_MACHINE_FIX_MODE_fix_443flag_en_mask                    (0x00000040)
#define STATE_MACHINE_FIX_MODE_fix_palorflag_en_mask                  (0x00000020)
#define STATE_MACHINE_FIX_MODE_fix_secamflag_en_mask                  (0x00000010)
#define STATE_MACHINE_FIX_MODE_fix_625_h_mask                         (0x00000008)
#define STATE_MACHINE_FIX_MODE_fix_443_h_mask                         (0x00000004)
#define STATE_MACHINE_FIX_MODE_fix_palor_h_mask                       (0x00000002)
#define STATE_MACHINE_FIX_MODE_fix_secam_h_mask                       (0x00000001)
#define STATE_MACHINE_FIX_MODE_fix_625flag_en(data)                   (0x00000080&((data)<<7))
#define STATE_MACHINE_FIX_MODE_fix_443flag_en(data)                   (0x00000040&((data)<<6))
#define STATE_MACHINE_FIX_MODE_fix_palorflag_en(data)                 (0x00000020&((data)<<5))
#define STATE_MACHINE_FIX_MODE_fix_secamflag_en(data)                 (0x00000010&((data)<<4))
#define STATE_MACHINE_FIX_MODE_fix_625_h(data)                        (0x00000008&((data)<<3))
#define STATE_MACHINE_FIX_MODE_fix_443_h(data)                        (0x00000004&((data)<<2))
#define STATE_MACHINE_FIX_MODE_fix_palor_h(data)                      (0x00000002&((data)<<1))
#define STATE_MACHINE_FIX_MODE_fix_secam_h(data)                      (0x00000001&(data))
#define STATE_MACHINE_FIX_MODE_get_fix_625flag_en(data)               ((0x00000080&(data))>>7)
#define STATE_MACHINE_FIX_MODE_get_fix_443flag_en(data)               ((0x00000040&(data))>>6)
#define STATE_MACHINE_FIX_MODE_get_fix_palorflag_en(data)             ((0x00000020&(data))>>5)
#define STATE_MACHINE_FIX_MODE_get_fix_secamflag_en(data)             ((0x00000010&(data))>>4)
#define STATE_MACHINE_FIX_MODE_get_fix_625_h(data)                    ((0x00000008&(data))>>3)
#define STATE_MACHINE_FIX_MODE_get_fix_443_h(data)                    ((0x00000004&(data))>>2)
#define STATE_MACHINE_FIX_MODE_get_fix_palor_h(data)                  ((0x00000002&(data))>>1)
#define STATE_MACHINE_FIX_MODE_get_fix_secam_h(data)                  (0x00000001&(data))


#define VD_BASIC_REGISTER_ENABLE                                      0x180194b4
#define VD_BASIC_REGISTER_ENABLE_reg_addr                             "0xb80194b4"
#define VD_BASIC_REGISTER_ENABLE_reg                                  0xb80194b4
#define VD_BASIC_REGISTER_ENABLE_inst_addr                            "0x012D"
#define VD_BASIC_REGISTER_ENABLE_inst                                 0x012D
#define VD_BASIC_REGISTER_ENABLE_hactivestartreg_en_shift             (7)
#define VD_BASIC_REGISTER_ENABLE_hpixelreg_en_shift                   (6)
#define VD_BASIC_REGISTER_ENABLE_colourmodereg_en_shift               (5)
#define VD_BASIC_REGISTER_ENABLE_hagcreg_en_shift                     (4)
#define VD_BASIC_REGISTER_ENABLE_vline625reg_en_shift                 (3)
#define VD_BASIC_REGISTER_ENABLE_cdtomem_reg_en_shift                 (2)
#define VD_BASIC_REGISTER_ENABLE_vsyncreg_en_shift                    (1)
#define VD_BASIC_REGISTER_ENABLE_ped_reg_en_shift                     (0)
#define VD_BASIC_REGISTER_ENABLE_hactivestartreg_en_mask              (0x00000080)
#define VD_BASIC_REGISTER_ENABLE_hpixelreg_en_mask                    (0x00000040)
#define VD_BASIC_REGISTER_ENABLE_colourmodereg_en_mask                (0x00000020)
#define VD_BASIC_REGISTER_ENABLE_hagcreg_en_mask                      (0x00000010)
#define VD_BASIC_REGISTER_ENABLE_vline625reg_en_mask                  (0x00000008)
#define VD_BASIC_REGISTER_ENABLE_cdtomem_reg_en_mask                  (0x00000004)
#define VD_BASIC_REGISTER_ENABLE_vsyncreg_en_mask                     (0x00000002)
#define VD_BASIC_REGISTER_ENABLE_ped_reg_en_mask                      (0x00000001)
#define VD_BASIC_REGISTER_ENABLE_hactivestartreg_en(data)             (0x00000080&((data)<<7))
#define VD_BASIC_REGISTER_ENABLE_hpixelreg_en(data)                   (0x00000040&((data)<<6))
#define VD_BASIC_REGISTER_ENABLE_colourmodereg_en(data)               (0x00000020&((data)<<5))
#define VD_BASIC_REGISTER_ENABLE_hagcreg_en(data)                     (0x00000010&((data)<<4))
#define VD_BASIC_REGISTER_ENABLE_vline625reg_en(data)                 (0x00000008&((data)<<3))
#define VD_BASIC_REGISTER_ENABLE_cdtomem_reg_en(data)                 (0x00000004&((data)<<2))
#define VD_BASIC_REGISTER_ENABLE_vsyncreg_en(data)                    (0x00000002&((data)<<1))
#define VD_BASIC_REGISTER_ENABLE_ped_reg_en(data)                     (0x00000001&(data))
#define VD_BASIC_REGISTER_ENABLE_get_hactivestartreg_en(data)         ((0x00000080&(data))>>7)
#define VD_BASIC_REGISTER_ENABLE_get_hpixelreg_en(data)               ((0x00000040&(data))>>6)
#define VD_BASIC_REGISTER_ENABLE_get_colourmodereg_en(data)           ((0x00000020&(data))>>5)
#define VD_BASIC_REGISTER_ENABLE_get_hagcreg_en(data)                 ((0x00000010&(data))>>4)
#define VD_BASIC_REGISTER_ENABLE_get_vline625reg_en(data)             ((0x00000008&(data))>>3)
#define VD_BASIC_REGISTER_ENABLE_get_cdtomem_reg_en(data)             ((0x00000004&(data))>>2)
#define VD_BASIC_REGISTER_ENABLE_get_vsyncreg_en(data)                ((0x00000002&(data))>>1)
#define VD_BASIC_REGISTER_ENABLE_get_ped_reg_en(data)                 (0x00000001&(data))


#define AUTO_MODE_S_M_STATISTIC                                       0x180194b8
#define AUTO_MODE_S_M_STATISTIC_reg_addr                              "0xb80194b8"
#define AUTO_MODE_S_M_STATISTIC_reg                                   0xb80194b8
#define AUTO_MODE_S_M_STATISTIC_inst_addr                             "0x012E"
#define AUTO_MODE_S_M_STATISTIC_inst                                  0x012E
#define AUTO_MODE_S_M_STATISTIC_switch_palo_palm_method_shift         (6)
#define AUTO_MODE_S_M_STATISTIC_auto_secam_pali_method_shift          (4)
#define AUTO_MODE_S_M_STATISTIC_secam_flag_freq_disable_shift         (3)
#define AUTO_MODE_S_M_STATISTIC_statistic_multiplier_shift            (0)
#define AUTO_MODE_S_M_STATISTIC_switch_palo_palm_method_mask          (0x000000C0)
#define AUTO_MODE_S_M_STATISTIC_auto_secam_pali_method_mask           (0x00000030)
#define AUTO_MODE_S_M_STATISTIC_secam_flag_freq_disable_mask          (0x00000008)
#define AUTO_MODE_S_M_STATISTIC_statistic_multiplier_mask             (0x00000007)
#define AUTO_MODE_S_M_STATISTIC_switch_palo_palm_method(data)         (0x000000C0&((data)<<6))
#define AUTO_MODE_S_M_STATISTIC_auto_secam_pali_method(data)          (0x00000030&((data)<<4))
#define AUTO_MODE_S_M_STATISTIC_secam_flag_freq_disable(data)         (0x00000008&((data)<<3))
#define AUTO_MODE_S_M_STATISTIC_statistic_multiplier(data)            (0x00000007&(data))
#define AUTO_MODE_S_M_STATISTIC_get_switch_palo_palm_method(data)     ((0x000000C0&(data))>>6)
#define AUTO_MODE_S_M_STATISTIC_get_auto_secam_pali_method(data)      ((0x00000030&(data))>>4)
#define AUTO_MODE_S_M_STATISTIC_get_secam_flag_freq_disable(data)     ((0x00000008&(data))>>3)
#define AUTO_MODE_S_M_STATISTIC_get_statistic_multiplier(data)        (0x00000007&(data))


#define AUTO_POS_CTRL                                                 0x180194c0
#define AUTO_POS_CTRL_reg_addr                                        "0xb80194c0"
#define AUTO_POS_CTRL_reg                                             0xb80194c0
#define AUTO_POS_CTRL_inst_addr                                       "0x0130"
#define AUTO_POS_CTRL_inst                                            0x0130
#define AUTO_POS_CTRL_new_cr1delay_en_shift                           (30)
#define AUTO_POS_CTRL_new_cb1delay_en_shift                           (29)
#define AUTO_POS_CTRL_new_y1delay_en_shift                            (28)
#define AUTO_POS_CTRL_cr1delayreg_en_shift                            (26)
#define AUTO_POS_CTRL_cb1delayreg_en_shift                            (25)
#define AUTO_POS_CTRL_y1delayreg_en_shift                             (24)
#define AUTO_POS_CTRL_cr1delay_shift                                  (16)
#define AUTO_POS_CTRL_cb1delay_shift                                  (8)
#define AUTO_POS_CTRL_y1delay_shift                                   (0)
#define AUTO_POS_CTRL_new_cr1delay_en_mask                            (0x40000000)
#define AUTO_POS_CTRL_new_cb1delay_en_mask                            (0x20000000)
#define AUTO_POS_CTRL_new_y1delay_en_mask                             (0x10000000)
#define AUTO_POS_CTRL_cr1delayreg_en_mask                             (0x04000000)
#define AUTO_POS_CTRL_cb1delayreg_en_mask                             (0x02000000)
#define AUTO_POS_CTRL_y1delayreg_en_mask                              (0x01000000)
#define AUTO_POS_CTRL_cr1delay_mask                                   (0x003F0000)
#define AUTO_POS_CTRL_cb1delay_mask                                   (0x00003F00)
#define AUTO_POS_CTRL_y1delay_mask                                    (0x0000003F)
#define AUTO_POS_CTRL_new_cr1delay_en(data)                           (0x40000000&((data)<<30))
#define AUTO_POS_CTRL_new_cb1delay_en(data)                           (0x20000000&((data)<<29))
#define AUTO_POS_CTRL_new_y1delay_en(data)                            (0x10000000&((data)<<28))
#define AUTO_POS_CTRL_cr1delayreg_en(data)                            (0x04000000&((data)<<26))
#define AUTO_POS_CTRL_cb1delayreg_en(data)                            (0x02000000&((data)<<25))
#define AUTO_POS_CTRL_y1delayreg_en(data)                             (0x01000000&((data)<<24))
#define AUTO_POS_CTRL_cr1delay(data)                                  (0x003F0000&((data)<<16))
#define AUTO_POS_CTRL_cb1delay(data)                                  (0x00003F00&((data)<<8))
#define AUTO_POS_CTRL_y1delay(data)                                   (0x0000003F&(data))
#define AUTO_POS_CTRL_get_new_cr1delay_en(data)                       ((0x40000000&(data))>>30)
#define AUTO_POS_CTRL_get_new_cb1delay_en(data)                       ((0x20000000&(data))>>29)
#define AUTO_POS_CTRL_get_new_y1delay_en(data)                        ((0x10000000&(data))>>28)
#define AUTO_POS_CTRL_get_cr1delayreg_en(data)                        ((0x04000000&(data))>>26)
#define AUTO_POS_CTRL_get_cb1delayreg_en(data)                        ((0x02000000&(data))>>25)
#define AUTO_POS_CTRL_get_y1delayreg_en(data)                         ((0x01000000&(data))>>24)
#define AUTO_POS_CTRL_get_cr1delay(data)                              ((0x003F0000&(data))>>16)
#define AUTO_POS_CTRL_get_cb1delay(data)                              ((0x00003F00&(data))>>8)
#define AUTO_POS_CTRL_get_y1delay(data)                               (0x0000003F&(data))


#define AUTO_POS_CTRL_2                                               0x180194c4
#define AUTO_POS_CTRL_2_reg_addr                                      "0xb80194c4"
#define AUTO_POS_CTRL_2_reg                                           0xb80194c4
#define AUTO_POS_CTRL_2_inst_addr                                     "0x0131"
#define AUTO_POS_CTRL_2_inst                                          0x0131
#define AUTO_POS_CTRL_2_auto_pos_modify_en_shift                      (31)
#define AUTO_POS_CTRL_2_auto_pos_mode_sel_shift                       (28)
#define AUTO_POS_CTRL_2_auto_ycdelay_modify_en_shift                  (27)
#define AUTO_POS_CTRL_2_auto_ycdelay_mode_sel_shift                   (24)
#define AUTO_POS_CTRL_2_ckill_cr1delayreg_en_shift                    (22)
#define AUTO_POS_CTRL_2_ckill_cb1delayreg_en_shift                    (21)
#define AUTO_POS_CTRL_2_ckill_y1delayreg_en_shift                     (20)
#define AUTO_POS_CTRL_2_ckill_cr1delay_shift                          (14)
#define AUTO_POS_CTRL_2_ckill_cb1delay_shift                          (8)
#define AUTO_POS_CTRL_2_ckill_y1delay_shift                           (0)
#define AUTO_POS_CTRL_2_auto_pos_modify_en_mask                       (0x80000000)
#define AUTO_POS_CTRL_2_auto_pos_mode_sel_mask                        (0x70000000)
#define AUTO_POS_CTRL_2_auto_ycdelay_modify_en_mask                   (0x08000000)
#define AUTO_POS_CTRL_2_auto_ycdelay_mode_sel_mask                    (0x07000000)
#define AUTO_POS_CTRL_2_ckill_cr1delayreg_en_mask                     (0x00400000)
#define AUTO_POS_CTRL_2_ckill_cb1delayreg_en_mask                     (0x00200000)
#define AUTO_POS_CTRL_2_ckill_y1delayreg_en_mask                      (0x00100000)
#define AUTO_POS_CTRL_2_ckill_cr1delay_mask                           (0x000FC000)
#define AUTO_POS_CTRL_2_ckill_cb1delay_mask                           (0x00003F00)
#define AUTO_POS_CTRL_2_ckill_y1delay_mask                            (0x0000003F)
#define AUTO_POS_CTRL_2_auto_pos_modify_en(data)                      (0x80000000&((data)<<31))
#define AUTO_POS_CTRL_2_auto_pos_mode_sel(data)                       (0x70000000&((data)<<28))
#define AUTO_POS_CTRL_2_auto_ycdelay_modify_en(data)                  (0x08000000&((data)<<27))
#define AUTO_POS_CTRL_2_auto_ycdelay_mode_sel(data)                   (0x07000000&((data)<<24))
#define AUTO_POS_CTRL_2_ckill_cr1delayreg_en(data)                    (0x00400000&((data)<<22))
#define AUTO_POS_CTRL_2_ckill_cb1delayreg_en(data)                    (0x00200000&((data)<<21))
#define AUTO_POS_CTRL_2_ckill_y1delayreg_en(data)                     (0x00100000&((data)<<20))
#define AUTO_POS_CTRL_2_ckill_cr1delay(data)                          (0x000FC000&((data)<<14))
#define AUTO_POS_CTRL_2_ckill_cb1delay(data)                          (0x00003F00&((data)<<8))
#define AUTO_POS_CTRL_2_ckill_y1delay(data)                           (0x0000003F&(data))
#define AUTO_POS_CTRL_2_get_auto_pos_modify_en(data)                  ((0x80000000&(data))>>31)
#define AUTO_POS_CTRL_2_get_auto_pos_mode_sel(data)                   ((0x70000000&(data))>>28)
#define AUTO_POS_CTRL_2_get_auto_ycdelay_modify_en(data)              ((0x08000000&(data))>>27)
#define AUTO_POS_CTRL_2_get_auto_ycdelay_mode_sel(data)               ((0x07000000&(data))>>24)
#define AUTO_POS_CTRL_2_get_ckill_cr1delayreg_en(data)                ((0x00400000&(data))>>22)
#define AUTO_POS_CTRL_2_get_ckill_cb1delayreg_en(data)                ((0x00200000&(data))>>21)
#define AUTO_POS_CTRL_2_get_ckill_y1delayreg_en(data)                 ((0x00100000&(data))>>20)
#define AUTO_POS_CTRL_2_get_ckill_cr1delay(data)                      ((0x000FC000&(data))>>14)
#define AUTO_POS_CTRL_2_get_ckill_cb1delay(data)                      ((0x00003F00&(data))>>8)
#define AUTO_POS_CTRL_2_get_ckill_y1delay(data)                       (0x0000003F&(data))


#define FLAG358_CTRL                                                  0x180194c8
#define FLAG358_CTRL_reg_addr                                         "0xb80194c8"
#define FLAG358_CTRL_reg                                              0xb80194c8
#define FLAG358_CTRL_inst_addr                                        "0x0132"
#define FLAG358_CTRL_inst                                             0x0132
#define FLAG358_CTRL_fix_358flag_en_shift                             (7)
#define FLAG358_CTRL_fix_358_h_shift                                  (6)
#define FLAG358_CTRL_auto_443_358_method_625_shift                    (4)
#define FLAG358_CTRL_auto_443_358_method_525_shift                    (2)
#define FLAG358_CTRL_auto_sel_no_burst_625_shift                      (0)
#define FLAG358_CTRL_fix_358flag_en_mask                              (0x00000080)
#define FLAG358_CTRL_fix_358_h_mask                                   (0x00000040)
#define FLAG358_CTRL_auto_443_358_method_625_mask                     (0x00000030)
#define FLAG358_CTRL_auto_443_358_method_525_mask                     (0x0000000C)
#define FLAG358_CTRL_auto_sel_no_burst_625_mask                       (0x00000003)
#define FLAG358_CTRL_fix_358flag_en(data)                             (0x00000080&((data)<<7))
#define FLAG358_CTRL_fix_358_h(data)                                  (0x00000040&((data)<<6))
#define FLAG358_CTRL_auto_443_358_method_625(data)                    (0x00000030&((data)<<4))
#define FLAG358_CTRL_auto_443_358_method_525(data)                    (0x0000000C&((data)<<2))
#define FLAG358_CTRL_auto_sel_no_burst_625(data)                      (0x00000003&(data))
#define FLAG358_CTRL_get_fix_358flag_en(data)                         ((0x00000080&(data))>>7)
#define FLAG358_CTRL_get_fix_358_h(data)                              ((0x00000040&(data))>>6)
#define FLAG358_CTRL_get_auto_443_358_method_625(data)                ((0x00000030&(data))>>4)
#define FLAG358_CTRL_get_auto_443_358_method_525(data)                ((0x0000000C&(data))>>2)
#define FLAG358_CTRL_get_auto_sel_no_burst_625(data)                  (0x00000003&(data))


#define NO_BURST_MAG_TH                                               0x180194cc
#define NO_BURST_MAG_TH_reg_addr                                      "0xb80194cc"
#define NO_BURST_MAG_TH_reg                                           0xb80194cc
#define NO_BURST_MAG_TH_inst_addr                                     "0x0133"
#define NO_BURST_MAG_TH_inst                                          0x0133
#define NO_BURST_MAG_TH_no_burst_mag_th_shift                         (0)
#define NO_BURST_MAG_TH_no_burst_mag_th_mask                          (0x000000FF)
#define NO_BURST_MAG_TH_no_burst_mag_th(data)                         (0x000000FF&(data))
#define NO_BURST_MAG_TH_get_no_burst_mag_th(data)                     (0x000000FF&(data))


#define NO_BURST_MAG_FILTER_TH                                        0x180194d0
#define NO_BURST_MAG_FILTER_TH_reg_addr                               "0xb80194d0"
#define NO_BURST_MAG_FILTER_TH_reg                                    0xb80194d0
#define NO_BURST_MAG_FILTER_TH_inst_addr                              "0x0134"
#define NO_BURST_MAG_FILTER_TH_inst                                   0x0134
#define NO_BURST_MAG_FILTER_TH_no_burst_mag_filter_th_shift           (0)
#define NO_BURST_MAG_FILTER_TH_no_burst_mag_filter_th_mask            (0x000000FF)
#define NO_BURST_MAG_FILTER_TH_no_burst_mag_filter_th(data)           (0x000000FF&(data))
#define NO_BURST_MAG_FILTER_TH_get_no_burst_mag_filter_th(data)       (0x000000FF&(data))


#define NO_BURST_443_CTRL                                             0x180194d4
#define NO_BURST_443_CTRL_reg_addr                                    "0xb80194d4"
#define NO_BURST_443_CTRL_reg                                         0xb80194d4
#define NO_BURST_443_CTRL_inst_addr                                   "0x0135"
#define NO_BURST_443_CTRL_inst                                        0x0135
#define NO_BURST_443_CTRL_burst_mag_trig_offset_shift                 (4)
#define NO_BURST_443_CTRL_no_burst_flag_shift                         (3)
#define NO_BURST_443_CTRL_paln_flag_new_shift                         (2)
#define NO_BURST_443_CTRL_burst_win_error_shift                       (1)
#define NO_BURST_443_CTRL_no_burst_443_en_shift                       (0)
#define NO_BURST_443_CTRL_burst_mag_trig_offset_mask                  (0x000000F0)
#define NO_BURST_443_CTRL_no_burst_flag_mask                          (0x00000008)
#define NO_BURST_443_CTRL_paln_flag_new_mask                          (0x00000004)
#define NO_BURST_443_CTRL_burst_win_error_mask                        (0x00000002)
#define NO_BURST_443_CTRL_no_burst_443_en_mask                        (0x00000001)
#define NO_BURST_443_CTRL_burst_mag_trig_offset(data)                 (0x000000F0&((data)<<4))
#define NO_BURST_443_CTRL_no_burst_flag(data)                         (0x00000008&((data)<<3))
#define NO_BURST_443_CTRL_paln_flag_new(data)                         (0x00000004&((data)<<2))
#define NO_BURST_443_CTRL_burst_win_error(data)                       (0x00000002&((data)<<1))
#define NO_BURST_443_CTRL_no_burst_443_en(data)                       (0x00000001&(data))
#define NO_BURST_443_CTRL_get_burst_mag_trig_offset(data)             ((0x000000F0&(data))>>4)
#define NO_BURST_443_CTRL_get_no_burst_flag(data)                     ((0x00000008&(data))>>3)
#define NO_BURST_443_CTRL_get_paln_flag_new(data)                     ((0x00000004&(data))>>2)
#define NO_BURST_443_CTRL_get_burst_win_error(data)                   ((0x00000002&(data))>>1)
#define NO_BURST_443_CTRL_get_no_burst_443_en(data)                   (0x00000001&(data))


#define FLAG358_SECAM_HCOUNT_RESET_CTRL                               0x180194d8
#define FLAG358_SECAM_HCOUNT_RESET_CTRL_reg_addr                      "0xb80194d8"
#define FLAG358_SECAM_HCOUNT_RESET_CTRL_reg                           0xb80194d8
#define FLAG358_SECAM_HCOUNT_RESET_CTRL_inst_addr                     "0x0136"
#define FLAG358_SECAM_HCOUNT_RESET_CTRL_inst                          0x0136
#define FLAG358_SECAM_HCOUNT_RESET_CTRL_flag358_secam_phase_diff_hcount_en_shift  (7)
#define FLAG358_SECAM_HCOUNT_RESET_CTRL_flag358_phase_diff_hcount_shift  (0)
#define FLAG358_SECAM_HCOUNT_RESET_CTRL_flag358_secam_phase_diff_hcount_en_mask  (0x00000080)
#define FLAG358_SECAM_HCOUNT_RESET_CTRL_flag358_phase_diff_hcount_mask  (0x0000007F)
#define FLAG358_SECAM_HCOUNT_RESET_CTRL_flag358_secam_phase_diff_hcount_en(data)  (0x00000080&((data)<<7))
#define FLAG358_SECAM_HCOUNT_RESET_CTRL_flag358_phase_diff_hcount(data)  (0x0000007F&(data))
#define FLAG358_SECAM_HCOUNT_RESET_CTRL_get_flag358_secam_phase_diff_hcount_en(data)  ((0x00000080&(data))>>7)
#define FLAG358_SECAM_HCOUNT_RESET_CTRL_get_flag358_phase_diff_hcount(data)  (0x0000007F&(data))


#define FLAG358_SECAM_PHASE_DIFF_DR                                   0x180194dc
#define FLAG358_SECAM_PHASE_DIFF_DR_reg_addr                          "0xb80194dc"
#define FLAG358_SECAM_PHASE_DIFF_DR_reg                               0xb80194dc
#define FLAG358_SECAM_PHASE_DIFF_DR_inst_addr                         "0x0137"
#define FLAG358_SECAM_PHASE_DIFF_DR_inst                              0x0137
#define FLAG358_SECAM_PHASE_DIFF_DR_flag358_secam_phase_diff_dr_shift (0)
#define FLAG358_SECAM_PHASE_DIFF_DR_flag358_secam_phase_diff_dr_mask  (0x000000FF)
#define FLAG358_SECAM_PHASE_DIFF_DR_flag358_secam_phase_diff_dr(data) (0x000000FF&(data))
#define FLAG358_SECAM_PHASE_DIFF_DR_get_flag358_secam_phase_diff_dr(data)  (0x000000FF&(data))


#define FLAG358_SECAM_PHASE_DIFF_DB                                   0x180194e0
#define FLAG358_SECAM_PHASE_DIFF_DB_reg_addr                          "0xb80194e0"
#define FLAG358_SECAM_PHASE_DIFF_DB_reg                               0xb80194e0
#define FLAG358_SECAM_PHASE_DIFF_DB_inst_addr                         "0x0138"
#define FLAG358_SECAM_PHASE_DIFF_DB_inst                              0x0138
#define FLAG358_SECAM_PHASE_DIFF_DB_flag358_secam_phase_diff_db_shift (0)
#define FLAG358_SECAM_PHASE_DIFF_DB_flag358_secam_phase_diff_db_mask  (0x000000FF)
#define FLAG358_SECAM_PHASE_DIFF_DB_flag358_secam_phase_diff_db(data) (0x000000FF&(data))
#define FLAG358_SECAM_PHASE_DIFF_DB_get_flag358_secam_phase_diff_db(data)  (0x000000FF&(data))


#define BURST_MAG_TH_358                                              0x180194e4
#define BURST_MAG_TH_358_reg_addr                                     "0xb80194e4"
#define BURST_MAG_TH_358_reg                                          0xb80194e4
#define BURST_MAG_TH_358_inst_addr                                    "0x0139"
#define BURST_MAG_TH_358_inst                                         0x0139
#define BURST_MAG_TH_358_burst_mag_th_358_shift                       (0)
#define BURST_MAG_TH_358_burst_mag_th_358_mask                        (0x000000FF)
#define BURST_MAG_TH_358_burst_mag_th_358(data)                       (0x000000FF&(data))
#define BURST_MAG_TH_358_get_burst_mag_th_358(data)                   (0x000000FF&(data))


#define AUTO_MODE_TABLE1                                              0x180194f0
#define AUTO_MODE_TABLE1_reg_addr                                     "0xb80194f0"
#define AUTO_MODE_TABLE1_reg                                          0xb80194f0
#define AUTO_MODE_TABLE1_inst_addr                                    "0x013C"
#define AUTO_MODE_TABLE1_inst                                         0x013C
#define AUTO_MODE_TABLE1_table_cagc_en_shift                          (7)
#define AUTO_MODE_TABLE1_table_vline_625_shift                        (6)
#define AUTO_MODE_TABLE1_table_hpixel_shift                           (4)
#define AUTO_MODE_TABLE1_table_ped_shift                              (3)
#define AUTO_MODE_TABLE1_table_colour_mode_shift                      (0)
#define AUTO_MODE_TABLE1_table_cagc_en_mask                           (0x00000080)
#define AUTO_MODE_TABLE1_table_vline_625_mask                         (0x00000040)
#define AUTO_MODE_TABLE1_table_hpixel_mask                            (0x00000030)
#define AUTO_MODE_TABLE1_table_ped_mask                               (0x00000008)
#define AUTO_MODE_TABLE1_table_colour_mode_mask                       (0x00000007)
#define AUTO_MODE_TABLE1_table_cagc_en(data)                          (0x00000080&((data)<<7))
#define AUTO_MODE_TABLE1_table_vline_625(data)                        (0x00000040&((data)<<6))
#define AUTO_MODE_TABLE1_table_hpixel(data)                           (0x00000030&((data)<<4))
#define AUTO_MODE_TABLE1_table_ped(data)                              (0x00000008&((data)<<3))
#define AUTO_MODE_TABLE1_table_colour_mode(data)                      (0x00000007&(data))
#define AUTO_MODE_TABLE1_get_table_cagc_en(data)                      ((0x00000080&(data))>>7)
#define AUTO_MODE_TABLE1_get_table_vline_625(data)                    ((0x00000040&(data))>>6)
#define AUTO_MODE_TABLE1_get_table_hpixel(data)                       ((0x00000030&(data))>>4)
#define AUTO_MODE_TABLE1_get_table_ped(data)                          ((0x00000008&(data))>>3)
#define AUTO_MODE_TABLE1_get_table_colour_mode(data)                  (0x00000007&(data))


#define AUTO_MODE_TABLE2                                              0x180194f4
#define AUTO_MODE_TABLE2_reg_addr                                     "0xb80194f4"
#define AUTO_MODE_TABLE2_reg                                          0xb80194f4
#define AUTO_MODE_TABLE2_inst_addr                                    "0x013D"
#define AUTO_MODE_TABLE2_inst                                         0x013D
#define AUTO_MODE_TABLE2_table_hagc_shift                             (0)
#define AUTO_MODE_TABLE2_table_hagc_mask                              (0x000000FF)
#define AUTO_MODE_TABLE2_table_hagc(data)                             (0x000000FF&(data))
#define AUTO_MODE_TABLE2_get_table_hagc(data)                         (0x000000FF&(data))


#define AUTO_MODE_TABLE3                                              0x180194f8
#define AUTO_MODE_TABLE3_reg_addr                                     "0xb80194f8"
#define AUTO_MODE_TABLE3_reg                                          0xb80194f8
#define AUTO_MODE_TABLE3_inst_addr                                    "0x013E"
#define AUTO_MODE_TABLE3_inst                                         0x013E
#define AUTO_MODE_TABLE3_table_hactive_start_shift                    (0)
#define AUTO_MODE_TABLE3_table_hactive_start_mask                     (0x000000FF)
#define AUTO_MODE_TABLE3_table_hactive_start(data)                    (0x000000FF&(data))
#define AUTO_MODE_TABLE3_get_table_hactive_start(data)                (0x000000FF&(data))


#define AUTO_MODE_TABLE4                                              0x180194fc
#define AUTO_MODE_TABLE4_reg_addr                                     "0xb80194fc"
#define AUTO_MODE_TABLE4_reg                                          0xb80194fc
#define AUTO_MODE_TABLE4_inst_addr                                    "0x013F"
#define AUTO_MODE_TABLE4_inst                                         0x013F
#define AUTO_MODE_TABLE4_table_vactive_start_shift                    (0)
#define AUTO_MODE_TABLE4_table_vactive_start_mask                     (0x000000FF)
#define AUTO_MODE_TABLE4_table_vactive_start(data)                    (0x000000FF&(data))
#define AUTO_MODE_TABLE4_get_table_vactive_start(data)                (0x000000FF&(data))


#define AUTO_MODE_TABLE5                                              0x18019500
#define AUTO_MODE_TABLE5_reg_addr                                     "0xb8019500"
#define AUTO_MODE_TABLE5_reg                                          0xb8019500
#define AUTO_MODE_TABLE5_inst_addr                                    "0x0140"
#define AUTO_MODE_TABLE5_inst                                         0x0140
#define AUTO_MODE_TABLE5_table_vactive_height_shift                   (0)
#define AUTO_MODE_TABLE5_table_vactive_height_mask                    (0x000000FF)
#define AUTO_MODE_TABLE5_table_vactive_height(data)                   (0x000000FF&(data))
#define AUTO_MODE_TABLE5_get_table_vactive_height(data)               (0x000000FF&(data))


#define AUTO_MODE_TABLE6                                              0x18019504
#define AUTO_MODE_TABLE6_reg_addr                                     "0xb8019504"
#define AUTO_MODE_TABLE6_reg                                          0xb8019504
#define AUTO_MODE_TABLE6_inst_addr                                    "0x0141"
#define AUTO_MODE_TABLE6_inst                                         0x0141
#define AUTO_MODE_TABLE6_table_cdto_shift                             (0)
#define AUTO_MODE_TABLE6_table_cdto_mask                              (0x3FFFFFFF)
#define AUTO_MODE_TABLE6_table_cdto(data)                             (0x3FFFFFFF&(data))
#define AUTO_MODE_TABLE6_get_table_cdto(data)                         (0x3FFFFFFF&(data))


#define FLAG_625_COUNTER                                              0x18019508
#define FLAG_625_COUNTER_reg_addr                                     "0xb8019508"
#define FLAG_625_COUNTER_reg                                          0xb8019508
#define FLAG_625_COUNTER_inst_addr                                    "0x0142"
#define FLAG_625_COUNTER_inst                                         0x0142
#define FLAG_625_COUNTER_vline_625_vloop_clr_en_shift                 (31)
#define FLAG_625_COUNTER_vline_625_src_sel_shift                      (30)
#define FLAG_625_COUNTER_new_625flag_window_shift                     (20)
#define FLAG_625_COUNTER_new_625flag_div_thr_shift                    (8)
#define FLAG_625_COUNTER_flag_625_counter_shift                       (0)
#define FLAG_625_COUNTER_vline_625_vloop_clr_en_mask                  (0x80000000)
#define FLAG_625_COUNTER_vline_625_src_sel_mask                       (0x40000000)
#define FLAG_625_COUNTER_new_625flag_window_mask                      (0x3FF00000)
#define FLAG_625_COUNTER_new_625flag_div_thr_mask                     (0x0003FF00)
#define FLAG_625_COUNTER_flag_625_counter_mask                        (0x000000FF)
#define FLAG_625_COUNTER_vline_625_vloop_clr_en(data)                 (0x80000000&((data)<<31))
#define FLAG_625_COUNTER_vline_625_src_sel(data)                      (0x40000000&((data)<<30))
#define FLAG_625_COUNTER_new_625flag_window(data)                     (0x3FF00000&((data)<<20))
#define FLAG_625_COUNTER_new_625flag_div_thr(data)                    (0x0003FF00&((data)<<8))
#define FLAG_625_COUNTER_flag_625_counter(data)                       (0x000000FF&(data))
#define FLAG_625_COUNTER_get_vline_625_vloop_clr_en(data)             ((0x80000000&(data))>>31)
#define FLAG_625_COUNTER_get_vline_625_src_sel(data)                  ((0x40000000&(data))>>30)
#define FLAG_625_COUNTER_get_new_625flag_window(data)                 ((0x3FF00000&(data))>>20)
#define FLAG_625_COUNTER_get_new_625flag_div_thr(data)                ((0x0003FF00&(data))>>8)
#define FLAG_625_COUNTER_get_flag_625_counter(data)                   (0x000000FF&(data))


#define FLAG_443_COUNTER                                              0x1801950c
#define FLAG_443_COUNTER_reg_addr                                     "0xb801950c"
#define FLAG_443_COUNTER_reg                                          0xb801950c
#define FLAG_443_COUNTER_inst_addr                                    "0x0143"
#define FLAG_443_COUNTER_inst                                         0x0143
#define FLAG_443_COUNTER_flag_443_counter_shift                       (0)
#define FLAG_443_COUNTER_flag_443_counter_mask                        (0x000000FF)
#define FLAG_443_COUNTER_flag_443_counter(data)                       (0x000000FF&(data))
#define FLAG_443_COUNTER_get_flag_443_counter(data)                   (0x000000FF&(data))


#define SECAM_FLAG_COUNTER                                            0x18019510
#define SECAM_FLAG_COUNTER_reg_addr                                   "0xb8019510"
#define SECAM_FLAG_COUNTER_reg                                        0xb8019510
#define SECAM_FLAG_COUNTER_inst_addr                                  "0x0144"
#define SECAM_FLAG_COUNTER_inst                                       0x0144
#define SECAM_FLAG_COUNTER_secam_flag_counter_shift                   (0)
#define SECAM_FLAG_COUNTER_secam_flag_counter_mask                    (0x000000FF)
#define SECAM_FLAG_COUNTER_secam_flag_counter(data)                   (0x000000FF&(data))
#define SECAM_FLAG_COUNTER_get_secam_flag_counter(data)               (0x000000FF&(data))


#define PALM_FLAG_COUNTER                                             0x18019514
#define PALM_FLAG_COUNTER_reg_addr                                    "0xb8019514"
#define PALM_FLAG_COUNTER_reg                                         0xb8019514
#define PALM_FLAG_COUNTER_inst_addr                                   "0x0145"
#define PALM_FLAG_COUNTER_inst                                        0x0145
#define PALM_FLAG_COUNTER_palm_flag_counter_shift                     (0)
#define PALM_FLAG_COUNTER_palm_flag_counter_mask                      (0x000000FF)
#define PALM_FLAG_COUNTER_palm_flag_counter(data)                     (0x000000FF&(data))
#define PALM_FLAG_COUNTER_get_palm_flag_counter(data)                 (0x000000FF&(data))


#define BURST_VALID_COUNTER                                           0x18019518
#define BURST_VALID_COUNTER_reg_addr                                  "0xb8019518"
#define BURST_VALID_COUNTER_reg                                       0xb8019518
#define BURST_VALID_COUNTER_inst_addr                                 "0x0146"
#define BURST_VALID_COUNTER_inst                                      0x0146
#define BURST_VALID_COUNTER_burst_valid_counter_shift                 (0)
#define BURST_VALID_COUNTER_burst_valid_counter_mask                  (0x000000FF)
#define BURST_VALID_COUNTER_burst_valid_counter(data)                 (0x000000FF&(data))
#define BURST_VALID_COUNTER_get_burst_valid_counter(data)             (0x000000FF&(data))


#define MIDPOINT_ADJ                                                  0x1801951c
#define MIDPOINT_ADJ_reg_addr                                         "0xb801951c"
#define MIDPOINT_ADJ_reg                                              0xb801951c
#define MIDPOINT_ADJ_inst_addr                                        "0x0147"
#define MIDPOINT_ADJ_inst                                             0x0147
#define MIDPOINT_ADJ_midpoint_adjustment_shift                        (0)
#define MIDPOINT_ADJ_midpoint_adjustment_mask                         (0x000000FF)
#define MIDPOINT_ADJ_midpoint_adjustment(data)                        (0x000000FF&(data))
#define MIDPOINT_ADJ_get_midpoint_adjustment(data)                    (0x000000FF&(data))


#define FREQ_FLAG_THRESHOLD                                           0x18019520
#define FREQ_FLAG_THRESHOLD_reg_addr                                  "0xb8019520"
#define FREQ_FLAG_THRESHOLD_reg                                       0xb8019520
#define FREQ_FLAG_THRESHOLD_inst_addr                                 "0x0148"
#define FREQ_FLAG_THRESHOLD_inst                                      0x0148
#define FREQ_FLAG_THRESHOLD_freq_flag_threshold_tune_shift            (0)
#define FREQ_FLAG_THRESHOLD_freq_flag_threshold_tune_mask             (0x000000FF)
#define FREQ_FLAG_THRESHOLD_freq_flag_threshold_tune(data)            (0x000000FF&(data))
#define FREQ_FLAG_THRESHOLD_get_freq_flag_threshold_tune(data)        (0x000000FF&(data))


#define FREQ_VALID_MAX                                                0x18019524
#define FREQ_VALID_MAX_reg_addr                                       "0xb8019524"
#define FREQ_VALID_MAX_reg                                            0xb8019524
#define FREQ_VALID_MAX_inst_addr                                      "0x0149"
#define FREQ_VALID_MAX_inst                                           0x0149
#define FREQ_VALID_MAX_frequency_valid_upper_limit_shift              (0)
#define FREQ_VALID_MAX_frequency_valid_upper_limit_mask               (0x000000FF)
#define FREQ_VALID_MAX_frequency_valid_upper_limit(data)              (0x000000FF&(data))
#define FREQ_VALID_MAX_get_frequency_valid_upper_limit(data)          (0x000000FF&(data))


#define FREQ_VALID_INNER                                              0x18019528
#define FREQ_VALID_INNER_reg_addr                                     "0xb8019528"
#define FREQ_VALID_INNER_reg                                          0xb8019528
#define FREQ_VALID_INNER_inst_addr                                    "0x014A"
#define FREQ_VALID_INNER_inst                                         0x014A
#define FREQ_VALID_INNER_condition_enable_shift                       (7)
#define FREQ_VALID_INNER_frequency_valid_inner_limit_shift            (0)
#define FREQ_VALID_INNER_condition_enable_mask                        (0x00000080)
#define FREQ_VALID_INNER_frequency_valid_inner_limit_mask             (0x0000007F)
#define FREQ_VALID_INNER_condition_enable(data)                       (0x00000080&((data)<<7))
#define FREQ_VALID_INNER_frequency_valid_inner_limit(data)            (0x0000007F&(data))
#define FREQ_VALID_INNER_get_condition_enable(data)                   ((0x00000080&(data))>>7)
#define FREQ_VALID_INNER_get_frequency_valid_inner_limit(data)        (0x0000007F&(data))


#define FREQ_VALID_MIN                                                0x1801952c
#define FREQ_VALID_MIN_reg_addr                                       "0xb801952c"
#define FREQ_VALID_MIN_reg                                            0xb801952c
#define FREQ_VALID_MIN_inst_addr                                      "0x014B"
#define FREQ_VALID_MIN_inst                                           0x014B
#define FREQ_VALID_MIN_frequency_valid_lower_limit_shift              (0)
#define FREQ_VALID_MIN_frequency_valid_lower_limit_mask               (0x000000FF)
#define FREQ_VALID_MIN_frequency_valid_lower_limit(data)              (0x000000FF&(data))
#define FREQ_VALID_MIN_get_frequency_valid_lower_limit(data)          (0x000000FF&(data))


#define SECAM_FLAG_COUNTER_MAX                                        0x18019530
#define SECAM_FLAG_COUNTER_MAX_reg_addr                               "0xb8019530"
#define SECAM_FLAG_COUNTER_MAX_reg                                    0xb8019530
#define SECAM_FLAG_COUNTER_MAX_inst_addr                              "0x014C"
#define SECAM_FLAG_COUNTER_MAX_inst                                   0x014C
#define SECAM_FLAG_COUNTER_MAX_secam_flag_frequency_upper_limit_shift (0)
#define SECAM_FLAG_COUNTER_MAX_secam_flag_frequency_upper_limit_mask  (0x000000FF)
#define SECAM_FLAG_COUNTER_MAX_secam_flag_frequency_upper_limit(data) (0x000000FF&(data))
#define SECAM_FLAG_COUNTER_MAX_get_secam_flag_frequency_upper_limit(data)  (0x000000FF&(data))


#define SECAM_FLAG_COUNTER_MIN                                        0x18019534
#define SECAM_FLAG_COUNTER_MIN_reg_addr                               "0xb8019534"
#define SECAM_FLAG_COUNTER_MIN_reg                                    0xb8019534
#define SECAM_FLAG_COUNTER_MIN_inst_addr                              "0x014D"
#define SECAM_FLAG_COUNTER_MIN_inst                                   0x014D
#define SECAM_FLAG_COUNTER_MIN_secam_flag_frequency_lower_limit_shift (0)
#define SECAM_FLAG_COUNTER_MIN_secam_flag_frequency_lower_limit_mask  (0x000000FF)
#define SECAM_FLAG_COUNTER_MIN_secam_flag_frequency_lower_limit(data) (0x000000FF&(data))
#define SECAM_FLAG_COUNTER_MIN_get_secam_flag_frequency_lower_limit(data)  (0x000000FF&(data))


#define PALM_FLAG_PHASE_ADJ                                           0x18019538
#define PALM_FLAG_PHASE_ADJ_reg_addr                                  "0xb8019538"
#define PALM_FLAG_PHASE_ADJ_reg                                       0xb8019538
#define PALM_FLAG_PHASE_ADJ_inst_addr                                 "0x014E"
#define PALM_FLAG_PHASE_ADJ_inst                                      0x014E
#define PALM_FLAG_PHASE_ADJ_palm_flag_limit_en_shift                  (28)
#define PALM_FLAG_PHASE_ADJ_pal_sw_acc_input_polar_shift              (27)
#define PALM_FLAG_PHASE_ADJ_pal_sw_input_sel_shift                    (26)
#define PALM_FLAG_PHASE_ADJ_palm_sw_acc_input_polar_shift             (25)
#define PALM_FLAG_PHASE_ADJ_palm_sw_input_sel_shift                   (24)
#define PALM_FLAG_PHASE_ADJ_pal_flag_threshold_shift                  (8)
#define PALM_FLAG_PHASE_ADJ_palm_flag_phase_adjust_shift              (0)
#define PALM_FLAG_PHASE_ADJ_palm_flag_limit_en_mask                   (0x10000000)
#define PALM_FLAG_PHASE_ADJ_pal_sw_acc_input_polar_mask               (0x08000000)
#define PALM_FLAG_PHASE_ADJ_pal_sw_input_sel_mask                     (0x04000000)
#define PALM_FLAG_PHASE_ADJ_palm_sw_acc_input_polar_mask              (0x02000000)
#define PALM_FLAG_PHASE_ADJ_palm_sw_input_sel_mask                    (0x01000000)
#define PALM_FLAG_PHASE_ADJ_pal_flag_threshold_mask                   (0x001FFF00)
#define PALM_FLAG_PHASE_ADJ_palm_flag_phase_adjust_mask               (0x000000FF)
#define PALM_FLAG_PHASE_ADJ_palm_flag_limit_en(data)                  (0x10000000&((data)<<28))
#define PALM_FLAG_PHASE_ADJ_pal_sw_acc_input_polar(data)              (0x08000000&((data)<<27))
#define PALM_FLAG_PHASE_ADJ_pal_sw_input_sel(data)                    (0x04000000&((data)<<26))
#define PALM_FLAG_PHASE_ADJ_palm_sw_acc_input_polar(data)             (0x02000000&((data)<<25))
#define PALM_FLAG_PHASE_ADJ_palm_sw_input_sel(data)                   (0x01000000&((data)<<24))
#define PALM_FLAG_PHASE_ADJ_pal_flag_threshold(data)                  (0x001FFF00&((data)<<8))
#define PALM_FLAG_PHASE_ADJ_palm_flag_phase_adjust(data)              (0x000000FF&(data))
#define PALM_FLAG_PHASE_ADJ_get_palm_flag_limit_en(data)              ((0x10000000&(data))>>28)
#define PALM_FLAG_PHASE_ADJ_get_pal_sw_acc_input_polar(data)          ((0x08000000&(data))>>27)
#define PALM_FLAG_PHASE_ADJ_get_pal_sw_input_sel(data)                ((0x04000000&(data))>>26)
#define PALM_FLAG_PHASE_ADJ_get_palm_sw_acc_input_polar(data)         ((0x02000000&(data))>>25)
#define PALM_FLAG_PHASE_ADJ_get_palm_sw_input_sel(data)               ((0x01000000&(data))>>24)
#define PALM_FLAG_PHASE_ADJ_get_pal_flag_threshold(data)              ((0x001FFF00&(data))>>8)
#define PALM_FLAG_PHASE_ADJ_get_palm_flag_phase_adjust(data)          (0x000000FF&(data))


#define BURST_LOWER_LIMIT                                             0x1801953c
#define BURST_LOWER_LIMIT_reg_addr                                    "0xb801953c"
#define BURST_LOWER_LIMIT_reg                                         0xb801953c
#define BURST_LOWER_LIMIT_inst_addr                                   "0x014F"
#define BURST_LOWER_LIMIT_inst                                        0x014F
#define BURST_LOWER_LIMIT_burst_mag_trigger_shift                     (4)
#define BURST_LOWER_LIMIT_burst_mag_threshold_shift                   (0)
#define BURST_LOWER_LIMIT_burst_mag_trigger_mask                      (0x000000F0)
#define BURST_LOWER_LIMIT_burst_mag_threshold_mask                    (0x0000000F)
#define BURST_LOWER_LIMIT_burst_mag_trigger(data)                     (0x000000F0&((data)<<4))
#define BURST_LOWER_LIMIT_burst_mag_threshold(data)                   (0x0000000F&(data))
#define BURST_LOWER_LIMIT_get_burst_mag_trigger(data)                 ((0x000000F0&(data))>>4)
#define BURST_LOWER_LIMIT_get_burst_mag_threshold(data)               (0x0000000F&(data))


#define BURST_MAG_CHOICE                                              0x18019540
#define BURST_MAG_CHOICE_reg_addr                                     "0xb8019540"
#define BURST_MAG_CHOICE_reg                                          0xb8019540
#define BURST_MAG_CHOICE_inst_addr                                    "0x0150"
#define BURST_MAG_CHOICE_inst                                         0x0150
#define BURST_MAG_CHOICE_vsync_select_shift                           (7)
#define BURST_MAG_CHOICE_secam_frequency_valid_enable_shift           (6)
#define BURST_MAG_CHOICE_auto_noburst_palflag_off_shift               (5)
#define BURST_MAG_CHOICE_burst_noise_weighting_auto_shift             (4)
#define BURST_MAG_CHOICE_burst_noise_weighting_shift                  (0)
#define BURST_MAG_CHOICE_vsync_select_mask                            (0x00000080)
#define BURST_MAG_CHOICE_secam_frequency_valid_enable_mask            (0x00000040)
#define BURST_MAG_CHOICE_auto_noburst_palflag_off_mask                (0x00000020)
#define BURST_MAG_CHOICE_burst_noise_weighting_auto_mask              (0x00000010)
#define BURST_MAG_CHOICE_burst_noise_weighting_mask                   (0x0000000F)
#define BURST_MAG_CHOICE_vsync_select(data)                           (0x00000080&((data)<<7))
#define BURST_MAG_CHOICE_secam_frequency_valid_enable(data)           (0x00000040&((data)<<6))
#define BURST_MAG_CHOICE_auto_noburst_palflag_off(data)               (0x00000020&((data)<<5))
#define BURST_MAG_CHOICE_burst_noise_weighting_auto(data)             (0x00000010&((data)<<4))
#define BURST_MAG_CHOICE_burst_noise_weighting(data)                  (0x0000000F&(data))
#define BURST_MAG_CHOICE_get_vsync_select(data)                       ((0x00000080&(data))>>7)
#define BURST_MAG_CHOICE_get_secam_frequency_valid_enable(data)       ((0x00000040&(data))>>6)
#define BURST_MAG_CHOICE_get_auto_noburst_palflag_off(data)           ((0x00000020&(data))>>5)
#define BURST_MAG_CHOICE_get_burst_noise_weighting_auto(data)         ((0x00000010&(data))>>4)
#define BURST_MAG_CHOICE_get_burst_noise_weighting(data)              (0x0000000F&(data))


#define NEW_358_CTRL                                                  0x18019550
#define NEW_358_CTRL_reg_addr                                         "0xb8019550"
#define NEW_358_CTRL_reg                                              0xb8019550
#define NEW_358_CTRL_inst_addr                                        "0x0154"
#define NEW_358_CTRL_inst                                             0x0154
#define NEW_358_CTRL_agc_gate_kill_sync_white_en_shift                (7)
#define NEW_358_CTRL_new_358_flag_cordic_shift                        (6)
#define NEW_358_CTRL_new_358_flag_cos_sin_shift                       (5)
#define NEW_358_CTRL_agc_gate_kill_sync_white_en_mask                 (0x00000080)
#define NEW_358_CTRL_new_358_flag_cordic_mask                         (0x00000040)
#define NEW_358_CTRL_new_358_flag_cos_sin_mask                        (0x00000020)
#define NEW_358_CTRL_agc_gate_kill_sync_white_en(data)                (0x00000080&((data)<<7))
#define NEW_358_CTRL_new_358_flag_cordic(data)                        (0x00000040&((data)<<6))
#define NEW_358_CTRL_new_358_flag_cos_sin(data)                       (0x00000020&((data)<<5))
#define NEW_358_CTRL_get_agc_gate_kill_sync_white_en(data)            ((0x00000080&(data))>>7)
#define NEW_358_CTRL_get_new_358_flag_cordic(data)                    ((0x00000040&(data))>>6)
#define NEW_358_CTRL_get_new_358_flag_cos_sin(data)                   ((0x00000020&(data))>>5)


#define NEW_358_CNT_UP                                                0x18019554
#define NEW_358_CNT_UP_reg_addr                                       "0xb8019554"
#define NEW_358_CNT_UP_reg                                            0xb8019554
#define NEW_358_CNT_UP_inst_addr                                      "0x0155"
#define NEW_358_CNT_UP_inst                                           0x0155
#define NEW_358_CNT_UP_new_dto_358_cnt_up_shift                       (0)
#define NEW_358_CNT_UP_new_dto_358_cnt_up_mask                        (0x000007FF)
#define NEW_358_CNT_UP_new_dto_358_cnt_up(data)                       (0x000007FF&(data))
#define NEW_358_CNT_UP_get_new_dto_358_cnt_up(data)                   (0x000007FF&(data))


#define NEW_358_CNT_DN                                                0x18019558
#define NEW_358_CNT_DN_reg_addr                                       "0xb8019558"
#define NEW_358_CNT_DN_reg                                            0xb8019558
#define NEW_358_CNT_DN_inst_addr                                      "0x0156"
#define NEW_358_CNT_DN_inst                                           0x0156
#define NEW_358_CNT_DN_new_dto_358_cnt_dn_shift                       (0)
#define NEW_358_CNT_DN_new_dto_358_cnt_dn_mask                        (0x000007FF)
#define NEW_358_CNT_DN_new_dto_358_cnt_dn(data)                       (0x000007FF&(data))
#define NEW_358_CNT_DN_get_new_dto_358_cnt_dn(data)                   (0x000007FF&(data))


#define SEP_COUNT_TH                                                  0x1801955c
#define SEP_COUNT_TH_reg_addr                                         "0xb801955c"
#define SEP_COUNT_TH_reg                                              0xb801955c
#define SEP_COUNT_TH_inst_addr                                        "0x0157"
#define SEP_COUNT_TH_inst                                             0x0157
#define SEP_COUNT_TH_sep_count_th_shift                               (0)
#define SEP_COUNT_TH_sep_count_th_mask                                (0x000003FF)
#define SEP_COUNT_TH_sep_count_th(data)                               (0x000003FF&(data))
#define SEP_COUNT_TH_get_sep_count_th(data)                           (0x000003FF&(data))


#define SEP_BURST_START0                                              0x18019560
#define SEP_BURST_START0_reg_addr                                     "0xb8019560"
#define SEP_BURST_START0_reg                                          0xb8019560
#define SEP_BURST_START0_inst_addr                                    "0x0158"
#define SEP_BURST_START0_inst                                         0x0158
#define SEP_BURST_START0_sep_burst_start_shift                        (0)
#define SEP_BURST_START0_sep_burst_start_mask                         (0x000007FF)
#define SEP_BURST_START0_sep_burst_start(data)                        (0x000007FF&(data))
#define SEP_BURST_START0_get_sep_burst_start(data)                    (0x000007FF&(data))


#define SEP_BURST_END0                                                0x18019564
#define SEP_BURST_END0_reg_addr                                       "0xb8019564"
#define SEP_BURST_END0_reg                                            0xb8019564
#define SEP_BURST_END0_inst_addr                                      "0x0159"
#define SEP_BURST_END0_inst                                           0x0159
#define SEP_BURST_END0_sep_burst_end_shift                            (0)
#define SEP_BURST_END0_sep_burst_end_mask                             (0x000007FF)
#define SEP_BURST_END0_sep_burst_end(data)                            (0x000007FF&(data))
#define SEP_BURST_END0_get_sep_burst_end(data)                        (0x000007FF&(data))


#define SEP_BURST_RO_1                                                0x18019568
#define SEP_BURST_RO_1_reg_addr                                       "0xb8019568"
#define SEP_BURST_RO_1_reg                                            0xb8019568
#define SEP_BURST_RO_1_inst_addr                                      "0x015A"
#define SEP_BURST_RO_1_inst                                           0x015A
#define SEP_BURST_RO_1_sep_core_burst_rst_shift                       (9)
#define SEP_BURST_RO_1_sep_core_burst_rst_en_shift                    (8)
#define SEP_BURST_RO_1_sep_443_core_burst_shift                       (0)
#define SEP_BURST_RO_1_sep_core_burst_rst_mask                        (0x00000200)
#define SEP_BURST_RO_1_sep_core_burst_rst_en_mask                     (0x00000100)
#define SEP_BURST_RO_1_sep_443_core_burst_mask                        (0x000000FF)
#define SEP_BURST_RO_1_sep_core_burst_rst(data)                       (0x00000200&((data)<<9))
#define SEP_BURST_RO_1_sep_core_burst_rst_en(data)                    (0x00000100&((data)<<8))
#define SEP_BURST_RO_1_sep_443_core_burst(data)                       (0x000000FF&(data))
#define SEP_BURST_RO_1_get_sep_core_burst_rst(data)                   ((0x00000200&(data))>>9)
#define SEP_BURST_RO_1_get_sep_core_burst_rst_en(data)                ((0x00000100&(data))>>8)
#define SEP_BURST_RO_1_get_sep_443_core_burst(data)                   (0x000000FF&(data))


#define SEP_BURST_RO_2                                                0x1801956c
#define SEP_BURST_RO_2_reg_addr                                       "0xb801956c"
#define SEP_BURST_RO_2_reg                                            0xb801956c
#define SEP_BURST_RO_2_inst_addr                                      "0x015B"
#define SEP_BURST_RO_2_inst                                           0x015B
#define SEP_BURST_RO_2_sep_358_core_burst_shift                       (0)
#define SEP_BURST_RO_2_sep_358_core_burst_mask                        (0x000000FF)
#define SEP_BURST_RO_2_sep_358_core_burst(data)                       (0x000000FF&(data))
#define SEP_BURST_RO_2_get_sep_358_core_burst(data)                   (0x000000FF&(data))


#define SEP_BURST_RO3                                                 0x18019570
#define SEP_BURST_RO3_reg_addr                                        "0xb8019570"
#define SEP_BURST_RO3_reg                                             0xb8019570
#define SEP_BURST_RO3_inst_addr                                       "0x015C"
#define SEP_BURST_RO3_inst                                            0x015C
#define SEP_BURST_RO3_sep_pal_secam_core_burst_rst_shift              (9)
#define SEP_BURST_RO3_sep_pal_secam_core_burst_rst_en_shift           (8)
#define SEP_BURST_RO3_sep_pal_secam_core_burst_shift                  (0)
#define SEP_BURST_RO3_sep_pal_secam_core_burst_rst_mask               (0x00000200)
#define SEP_BURST_RO3_sep_pal_secam_core_burst_rst_en_mask            (0x00000100)
#define SEP_BURST_RO3_sep_pal_secam_core_burst_mask                   (0x000000FF)
#define SEP_BURST_RO3_sep_pal_secam_core_burst_rst(data)              (0x00000200&((data)<<9))
#define SEP_BURST_RO3_sep_pal_secam_core_burst_rst_en(data)           (0x00000100&((data)<<8))
#define SEP_BURST_RO3_sep_pal_secam_core_burst(data)                  (0x000000FF&(data))
#define SEP_BURST_RO3_get_sep_pal_secam_core_burst_rst(data)          ((0x00000200&(data))>>9)
#define SEP_BURST_RO3_get_sep_pal_secam_core_burst_rst_en(data)       ((0x00000100&(data))>>8)
#define SEP_BURST_RO3_get_sep_pal_secam_core_burst(data)              (0x000000FF&(data))


#define SEP_BURST_TH1                                                 0x18019574
#define SEP_BURST_TH1_reg_addr                                        "0xb8019574"
#define SEP_BURST_TH1_reg                                             0xb8019574
#define SEP_BURST_TH1_inst_addr                                       "0x015D"
#define SEP_BURST_TH1_inst                                            0x015D
#define SEP_BURST_TH1_sep_443_thl_shift                               (8)
#define SEP_BURST_TH1_sep_358_thl_shift                               (0)
#define SEP_BURST_TH1_sep_443_thl_mask                                (0x0000FF00)
#define SEP_BURST_TH1_sep_358_thl_mask                                (0x000000FF)
#define SEP_BURST_TH1_sep_443_thl(data)                               (0x0000FF00&((data)<<8))
#define SEP_BURST_TH1_sep_358_thl(data)                               (0x000000FF&(data))
#define SEP_BURST_TH1_get_sep_443_thl(data)                           ((0x0000FF00&(data))>>8)
#define SEP_BURST_TH1_get_sep_358_thl(data)                           (0x000000FF&(data))


#define SEP_BURST_FLAG1                                               0x18019578
#define SEP_BURST_FLAG1_reg_addr                                      "0xb8019578"
#define SEP_BURST_FLAG1_reg                                           0xb8019578
#define SEP_BURST_FLAG1_inst_addr                                     "0x015E"
#define SEP_BURST_FLAG1_inst                                          0x015E
#define SEP_BURST_FLAG1_sep_secam_f_sel_shift                         (24)
#define SEP_BURST_FLAG1_sep_secam_thl_shift                           (16)
#define SEP_BURST_FLAG1_sep_secam_thl_ratio_shift                     (8)
#define SEP_BURST_FLAG1_power_secam_flag_shift                        (2)
#define SEP_BURST_FLAG1_power_443_flag_shift                          (1)
#define SEP_BURST_FLAG1_power_358_flag_shift                          (0)
#define SEP_BURST_FLAG1_sep_secam_f_sel_mask                          (0x01000000)
#define SEP_BURST_FLAG1_sep_secam_thl_mask                            (0x00FF0000)
#define SEP_BURST_FLAG1_sep_secam_thl_ratio_mask                      (0x0000FF00)
#define SEP_BURST_FLAG1_power_secam_flag_mask                         (0x00000004)
#define SEP_BURST_FLAG1_power_443_flag_mask                           (0x00000002)
#define SEP_BURST_FLAG1_power_358_flag_mask                           (0x00000001)
#define SEP_BURST_FLAG1_sep_secam_f_sel(data)                         (0x01000000&((data)<<24))
#define SEP_BURST_FLAG1_sep_secam_thl(data)                           (0x00FF0000&((data)<<16))
#define SEP_BURST_FLAG1_sep_secam_thl_ratio(data)                     (0x0000FF00&((data)<<8))
#define SEP_BURST_FLAG1_power_secam_flag(data)                        (0x00000004&((data)<<2))
#define SEP_BURST_FLAG1_power_443_flag(data)                          (0x00000002&((data)<<1))
#define SEP_BURST_FLAG1_power_358_flag(data)                          (0x00000001&(data))
#define SEP_BURST_FLAG1_get_sep_secam_f_sel(data)                     ((0x01000000&(data))>>24)
#define SEP_BURST_FLAG1_get_sep_secam_thl(data)                       ((0x00FF0000&(data))>>16)
#define SEP_BURST_FLAG1_get_sep_secam_thl_ratio(data)                 ((0x0000FF00&(data))>>8)
#define SEP_BURST_FLAG1_get_power_secam_flag(data)                    ((0x00000004&(data))>>2)
#define SEP_BURST_FLAG1_get_power_443_flag(data)                      ((0x00000002&(data))>>1)
#define SEP_BURST_FLAG1_get_power_358_flag(data)                      (0x00000001&(data))


#define AUTOMODE_443358PK_CTRL                                        0x1801957c
#define AUTOMODE_443358PK_CTRL_reg_addr                               "0xb801957c"
#define AUTOMODE_443358PK_CTRL_reg                                    0xb801957c
#define AUTOMODE_443358PK_CTRL_inst_addr                              "0x015F"
#define AUTOMODE_443358PK_CTRL_inst                                   0x015F
#define AUTOMODE_443358PK_CTRL_pk_foraudio_shift                      (6)
#define AUTOMODE_443358PK_CTRL_mode_secam2_sel_shift                  (4)
#define AUTOMODE_443358PK_CTRL_mode_443358pk_sel_shift                (0)
#define AUTOMODE_443358PK_CTRL_pk_foraudio_mask                       (0x00000040)
#define AUTOMODE_443358PK_CTRL_mode_secam2_sel_mask                   (0x00000030)
#define AUTOMODE_443358PK_CTRL_mode_443358pk_sel_mask                 (0x00000003)
#define AUTOMODE_443358PK_CTRL_pk_foraudio(data)                      (0x00000040&((data)<<6))
#define AUTOMODE_443358PK_CTRL_mode_secam2_sel(data)                  (0x00000030&((data)<<4))
#define AUTOMODE_443358PK_CTRL_mode_443358pk_sel(data)                (0x00000003&(data))
#define AUTOMODE_443358PK_CTRL_get_pk_foraudio(data)                  ((0x00000040&(data))>>6)
#define AUTOMODE_443358PK_CTRL_get_mode_secam2_sel(data)              ((0x00000030&(data))>>4)
#define AUTOMODE_443358PK_CTRL_get_mode_443358pk_sel(data)            (0x00000003&(data))


#define DARK_CPLL_CDETECT_1                                           0x18019580
#define DARK_CPLL_CDETECT_1_reg_addr                                  "0xb8019580"
#define DARK_CPLL_CDETECT_1_reg                                       0xb8019580
#define DARK_CPLL_CDETECT_1_inst_addr                                 "0x0160"
#define DARK_CPLL_CDETECT_1_inst                                      0x0160
#define DARK_CPLL_CDETECT_1_dark_badedit_noisy_off_en_shift           (31)
#define DARK_CPLL_CDETECT_1_dark_badedit_phase_lock_en_shift          (30)
#define DARK_CPLL_CDETECT_1_dark_fast_lock_en_shift                   (29)
#define DARK_CPLL_CDETECT_1_dark_phase_fast_lock_en_shift             (28)
#define DARK_CPLL_CDETECT_1_dark_fixed_cstate_shift                   (27)
#define DARK_CPLL_CDETECT_1_dark_cstate_shift                         (24)
#define DARK_CPLL_CDETECT_1_dark_chromalock_cstate_en_shift           (23)
#define DARK_CPLL_CDETECT_1_dark_chromalock_cstate_shift              (20)
#define DARK_CPLL_CDETECT_1_dark_cresample_signed_en_shift            (16)
#define DARK_CPLL_CDETECT_1_dark_cagc_shift                           (8)
#define DARK_CPLL_CDETECT_1_dark_cagc_pll_input_sel_shift             (6)
#define DARK_CPLL_CDETECT_1_dark_cagc_en_shift                        (5)
#define DARK_CPLL_CDETECT_1_dark_fix_cgain_shift                      (4)
#define DARK_CPLL_CDETECT_1_dark_cpll_cdto_change_en_shift            (3)
#define DARK_CPLL_CDETECT_1_dark_cpll_cdto_change_mode_shift          (0)
#define DARK_CPLL_CDETECT_1_dark_badedit_noisy_off_en_mask            (0x80000000)
#define DARK_CPLL_CDETECT_1_dark_badedit_phase_lock_en_mask           (0x40000000)
#define DARK_CPLL_CDETECT_1_dark_fast_lock_en_mask                    (0x20000000)
#define DARK_CPLL_CDETECT_1_dark_phase_fast_lock_en_mask              (0x10000000)
#define DARK_CPLL_CDETECT_1_dark_fixed_cstate_mask                    (0x08000000)
#define DARK_CPLL_CDETECT_1_dark_cstate_mask                          (0x07000000)
#define DARK_CPLL_CDETECT_1_dark_chromalock_cstate_en_mask            (0x00800000)
#define DARK_CPLL_CDETECT_1_dark_chromalock_cstate_mask               (0x00700000)
#define DARK_CPLL_CDETECT_1_dark_cresample_signed_en_mask             (0x00010000)
#define DARK_CPLL_CDETECT_1_dark_cagc_mask                            (0x0000FF00)
#define DARK_CPLL_CDETECT_1_dark_cagc_pll_input_sel_mask              (0x000000C0)
#define DARK_CPLL_CDETECT_1_dark_cagc_en_mask                         (0x00000020)
#define DARK_CPLL_CDETECT_1_dark_fix_cgain_mask                       (0x00000010)
#define DARK_CPLL_CDETECT_1_dark_cpll_cdto_change_en_mask             (0x00000008)
#define DARK_CPLL_CDETECT_1_dark_cpll_cdto_change_mode_mask           (0x00000007)
#define DARK_CPLL_CDETECT_1_dark_badedit_noisy_off_en(data)           (0x80000000&((data)<<31))
#define DARK_CPLL_CDETECT_1_dark_badedit_phase_lock_en(data)          (0x40000000&((data)<<30))
#define DARK_CPLL_CDETECT_1_dark_fast_lock_en(data)                   (0x20000000&((data)<<29))
#define DARK_CPLL_CDETECT_1_dark_phase_fast_lock_en(data)             (0x10000000&((data)<<28))
#define DARK_CPLL_CDETECT_1_dark_fixed_cstate(data)                   (0x08000000&((data)<<27))
#define DARK_CPLL_CDETECT_1_dark_cstate(data)                         (0x07000000&((data)<<24))
#define DARK_CPLL_CDETECT_1_dark_chromalock_cstate_en(data)           (0x00800000&((data)<<23))
#define DARK_CPLL_CDETECT_1_dark_chromalock_cstate(data)              (0x00700000&((data)<<20))
#define DARK_CPLL_CDETECT_1_dark_cresample_signed_en(data)            (0x00010000&((data)<<16))
#define DARK_CPLL_CDETECT_1_dark_cagc(data)                           (0x0000FF00&((data)<<8))
#define DARK_CPLL_CDETECT_1_dark_cagc_pll_input_sel(data)             (0x000000C0&((data)<<6))
#define DARK_CPLL_CDETECT_1_dark_cagc_en(data)                        (0x00000020&((data)<<5))
#define DARK_CPLL_CDETECT_1_dark_fix_cgain(data)                      (0x00000010&((data)<<4))
#define DARK_CPLL_CDETECT_1_dark_cpll_cdto_change_en(data)            (0x00000008&((data)<<3))
#define DARK_CPLL_CDETECT_1_dark_cpll_cdto_change_mode(data)          (0x00000007&(data))
#define DARK_CPLL_CDETECT_1_get_dark_badedit_noisy_off_en(data)       ((0x80000000&(data))>>31)
#define DARK_CPLL_CDETECT_1_get_dark_badedit_phase_lock_en(data)      ((0x40000000&(data))>>30)
#define DARK_CPLL_CDETECT_1_get_dark_fast_lock_en(data)               ((0x20000000&(data))>>29)
#define DARK_CPLL_CDETECT_1_get_dark_phase_fast_lock_en(data)         ((0x10000000&(data))>>28)
#define DARK_CPLL_CDETECT_1_get_dark_fixed_cstate(data)               ((0x08000000&(data))>>27)
#define DARK_CPLL_CDETECT_1_get_dark_cstate(data)                     ((0x07000000&(data))>>24)
#define DARK_CPLL_CDETECT_1_get_dark_chromalock_cstate_en(data)       ((0x00800000&(data))>>23)
#define DARK_CPLL_CDETECT_1_get_dark_chromalock_cstate(data)          ((0x00700000&(data))>>20)
#define DARK_CPLL_CDETECT_1_get_dark_cresample_signed_en(data)        ((0x00010000&(data))>>16)
#define DARK_CPLL_CDETECT_1_get_dark_cagc(data)                       ((0x0000FF00&(data))>>8)
#define DARK_CPLL_CDETECT_1_get_dark_cagc_pll_input_sel(data)         ((0x000000C0&(data))>>6)
#define DARK_CPLL_CDETECT_1_get_dark_cagc_en(data)                    ((0x00000020&(data))>>5)
#define DARK_CPLL_CDETECT_1_get_dark_fix_cgain(data)                  ((0x00000010&(data))>>4)
#define DARK_CPLL_CDETECT_1_get_dark_cpll_cdto_change_en(data)        ((0x00000008&(data))>>3)
#define DARK_CPLL_CDETECT_1_get_dark_cpll_cdto_change_mode(data)      (0x00000007&(data))


#define DARK_CPLL_CDETECT_2                                           0x18019584
#define DARK_CPLL_CDETECT_2_reg_addr                                  "0xb8019584"
#define DARK_CPLL_CDETECT_2_reg                                       0xb8019584
#define DARK_CPLL_CDETECT_2_inst_addr                                 "0x0161"
#define DARK_CPLL_CDETECT_2_inst                                      0x0161
#define DARK_CPLL_CDETECT_2_dark_cpll_cdto_change_value_shift         (0)
#define DARK_CPLL_CDETECT_2_dark_cpll_cdto_change_value_mask          (0x3FFFFFFF)
#define DARK_CPLL_CDETECT_2_dark_cpll_cdto_change_value(data)         (0x3FFFFFFF&(data))
#define DARK_CPLL_CDETECT_2_get_dark_cpll_cdto_change_value(data)     (0x3FFFFFFF&(data))


#define DARK_CPLL_PAL                                                 0x18019588
#define DARK_CPLL_PAL_reg_addr                                        "0xb8019588"
#define DARK_CPLL_PAL_reg                                             0xb8019588
#define DARK_CPLL_PAL_inst_addr                                       "0x0162"
#define DARK_CPLL_PAL_inst                                            0x0162
#define DARK_CPLL_PAL_dark_palm_flag_counter_shift                    (16)
#define DARK_CPLL_PAL_dark_palm_flag_phase_adjust_shift               (8)
#define DARK_CPLL_PAL_dark_palsw_level_shift                          (5)
#define DARK_CPLL_PAL_dark_palm_flag_limit_en_shift                   (4)
#define DARK_CPLL_PAL_dark_pal_sw_acc_input_polar_shift               (3)
#define DARK_CPLL_PAL_dark_pal_sw_input_sel_shift                     (2)
#define DARK_CPLL_PAL_dark_palm_sw_acc_input_polar_shift              (1)
#define DARK_CPLL_PAL_dark_palm_sw_input_sel_shift                    (0)
#define DARK_CPLL_PAL_dark_palm_flag_counter_mask                     (0x00FF0000)
#define DARK_CPLL_PAL_dark_palm_flag_phase_adjust_mask                (0x0000FF00)
#define DARK_CPLL_PAL_dark_palsw_level_mask                           (0x00000060)
#define DARK_CPLL_PAL_dark_palm_flag_limit_en_mask                    (0x00000010)
#define DARK_CPLL_PAL_dark_pal_sw_acc_input_polar_mask                (0x00000008)
#define DARK_CPLL_PAL_dark_pal_sw_input_sel_mask                      (0x00000004)
#define DARK_CPLL_PAL_dark_palm_sw_acc_input_polar_mask               (0x00000002)
#define DARK_CPLL_PAL_dark_palm_sw_input_sel_mask                     (0x00000001)
#define DARK_CPLL_PAL_dark_palm_flag_counter(data)                    (0x00FF0000&((data)<<16))
#define DARK_CPLL_PAL_dark_palm_flag_phase_adjust(data)               (0x0000FF00&((data)<<8))
#define DARK_CPLL_PAL_dark_palsw_level(data)                          (0x00000060&((data)<<5))
#define DARK_CPLL_PAL_dark_palm_flag_limit_en(data)                   (0x00000010&((data)<<4))
#define DARK_CPLL_PAL_dark_pal_sw_acc_input_polar(data)               (0x00000008&((data)<<3))
#define DARK_CPLL_PAL_dark_pal_sw_input_sel(data)                     (0x00000004&((data)<<2))
#define DARK_CPLL_PAL_dark_palm_sw_acc_input_polar(data)              (0x00000002&((data)<<1))
#define DARK_CPLL_PAL_dark_palm_sw_input_sel(data)                    (0x00000001&(data))
#define DARK_CPLL_PAL_get_dark_palm_flag_counter(data)                ((0x00FF0000&(data))>>16)
#define DARK_CPLL_PAL_get_dark_palm_flag_phase_adjust(data)           ((0x0000FF00&(data))>>8)
#define DARK_CPLL_PAL_get_dark_palsw_level(data)                      ((0x00000060&(data))>>5)
#define DARK_CPLL_PAL_get_dark_palm_flag_limit_en(data)               ((0x00000010&(data))>>4)
#define DARK_CPLL_PAL_get_dark_pal_sw_acc_input_polar(data)           ((0x00000008&(data))>>3)
#define DARK_CPLL_PAL_get_dark_pal_sw_input_sel(data)                 ((0x00000004&(data))>>2)
#define DARK_CPLL_PAL_get_dark_palm_sw_acc_input_polar(data)          ((0x00000002&(data))>>1)
#define DARK_CPLL_PAL_get_dark_palm_sw_input_sel(data)                (0x00000001&(data))


#define DARK_CPLL_CHROMALOCK                                          0x1801958c
#define DARK_CPLL_CHROMALOCK_reg_addr                                 "0xb801958c"
#define DARK_CPLL_CHROMALOCK_reg                                      0xb801958c
#define DARK_CPLL_CHROMALOCK_inst_addr                                "0x0163"
#define DARK_CPLL_CHROMALOCK_inst                                     0x0163
#define DARK_CPLL_CHROMALOCK_dark_pal_flag_threshold_shift            (16)
#define DARK_CPLL_CHROMALOCK_dark_chromalock_input_acc_en_shift       (14)
#define DARK_CPLL_CHROMALOCK_dark_chromalock_input_acc_num_shift      (12)
#define DARK_CPLL_CHROMALOCK_dark_lose_acc_chromalock_level_shift     (8)
#define DARK_CPLL_CHROMALOCK_dark_lose_chromalock_count_shift         (4)
#define DARK_CPLL_CHROMALOCK_dark_lose_chromalock_level_shift         (0)
#define DARK_CPLL_CHROMALOCK_dark_pal_flag_threshold_mask             (0x1FFF0000)
#define DARK_CPLL_CHROMALOCK_dark_chromalock_input_acc_en_mask        (0x00004000)
#define DARK_CPLL_CHROMALOCK_dark_chromalock_input_acc_num_mask       (0x00003000)
#define DARK_CPLL_CHROMALOCK_dark_lose_acc_chromalock_level_mask      (0x00000700)
#define DARK_CPLL_CHROMALOCK_dark_lose_chromalock_count_mask          (0x000000F0)
#define DARK_CPLL_CHROMALOCK_dark_lose_chromalock_level_mask          (0x00000007)
#define DARK_CPLL_CHROMALOCK_dark_pal_flag_threshold(data)            (0x1FFF0000&((data)<<16))
#define DARK_CPLL_CHROMALOCK_dark_chromalock_input_acc_en(data)       (0x00004000&((data)<<14))
#define DARK_CPLL_CHROMALOCK_dark_chromalock_input_acc_num(data)      (0x00003000&((data)<<12))
#define DARK_CPLL_CHROMALOCK_dark_lose_acc_chromalock_level(data)     (0x00000700&((data)<<8))
#define DARK_CPLL_CHROMALOCK_dark_lose_chromalock_count(data)         (0x000000F0&((data)<<4))
#define DARK_CPLL_CHROMALOCK_dark_lose_chromalock_level(data)         (0x00000007&(data))
#define DARK_CPLL_CHROMALOCK_get_dark_pal_flag_threshold(data)        ((0x1FFF0000&(data))>>16)
#define DARK_CPLL_CHROMALOCK_get_dark_chromalock_input_acc_en(data)   ((0x00004000&(data))>>14)
#define DARK_CPLL_CHROMALOCK_get_dark_chromalock_input_acc_num(data)  ((0x00003000&(data))>>12)
#define DARK_CPLL_CHROMALOCK_get_dark_lose_acc_chromalock_level(data) ((0x00000700&(data))>>8)
#define DARK_CPLL_CHROMALOCK_get_dark_lose_chromalock_count(data)     ((0x000000F0&(data))>>4)
#define DARK_CPLL_CHROMALOCK_get_dark_lose_chromalock_level(data)     (0x00000007&(data))


#define DARK_CPLL_CONTROLL                                            0x18019590
#define DARK_CPLL_CONTROLL_reg_addr                                   "0xb8019590"
#define DARK_CPLL_CONTROLL_reg                                        0xb8019590
#define DARK_CPLL_CONTROLL_inst_addr                                  "0x0164"
#define DARK_CPLL_CONTROLL_inst                                       0x0164
#define DARK_CPLL_CONTROLL_dark_cpll_decide_mode_error_shift          (28)
#define DARK_CPLL_CONTROLL_dark_cpll_decide_mode_shift                (24)
#define DARK_CPLL_CONTROLL_dark_cpll_vsync_num_shift                  (16)
#define DARK_CPLL_CONTROLL_dark_cpll_chromalock_sel_shift             (15)
#define DARK_CPLL_CONTROLL_dark_cpll_mode_en_pali_shift               (14)
#define DARK_CPLL_CONTROLL_dark_cpll_mode_en_pal60_shift              (13)
#define DARK_CPLL_CONTROLL_dark_cpll_mode_en_ntsc443_shift            (12)
#define DARK_CPLL_CONTROLL_dark_cpll_mode_en_paln_shift               (11)
#define DARK_CPLL_CONTROLL_dark_cpll_mode_en_ntsc50_shift             (10)
#define DARK_CPLL_CONTROLL_dark_cpll_mode_en_palm_shift               (9)
#define DARK_CPLL_CONTROLL_dark_cpll_mode_en_ntsc_shift               (8)
#define DARK_CPLL_CONTROLL_dark_cpll_fix_mode_en_shift                (7)
#define DARK_CPLL_CONTROLL_dark_cpll_user_mode_shift                  (4)
#define DARK_CPLL_CONTROLL_dark_cpll_mode_shift                       (2)
#define DARK_CPLL_CONTROLL_dark_cpll_auto_run_shift                   (1)
#define DARK_CPLL_CONTROLL_dark_cpll_start_shift                      (0)
#define DARK_CPLL_CONTROLL_dark_cpll_decide_mode_error_mask           (0x30000000)
#define DARK_CPLL_CONTROLL_dark_cpll_decide_mode_mask                 (0x07000000)
#define DARK_CPLL_CONTROLL_dark_cpll_vsync_num_mask                   (0x00FF0000)
#define DARK_CPLL_CONTROLL_dark_cpll_chromalock_sel_mask              (0x00008000)
#define DARK_CPLL_CONTROLL_dark_cpll_mode_en_pali_mask                (0x00004000)
#define DARK_CPLL_CONTROLL_dark_cpll_mode_en_pal60_mask               (0x00002000)
#define DARK_CPLL_CONTROLL_dark_cpll_mode_en_ntsc443_mask             (0x00001000)
#define DARK_CPLL_CONTROLL_dark_cpll_mode_en_paln_mask                (0x00000800)
#define DARK_CPLL_CONTROLL_dark_cpll_mode_en_ntsc50_mask              (0x00000400)
#define DARK_CPLL_CONTROLL_dark_cpll_mode_en_palm_mask                (0x00000200)
#define DARK_CPLL_CONTROLL_dark_cpll_mode_en_ntsc_mask                (0x00000100)
#define DARK_CPLL_CONTROLL_dark_cpll_fix_mode_en_mask                 (0x00000080)
#define DARK_CPLL_CONTROLL_dark_cpll_user_mode_mask                   (0x00000070)
#define DARK_CPLL_CONTROLL_dark_cpll_mode_mask                        (0x0000000C)
#define DARK_CPLL_CONTROLL_dark_cpll_auto_run_mask                    (0x00000002)
#define DARK_CPLL_CONTROLL_dark_cpll_start_mask                       (0x00000001)
#define DARK_CPLL_CONTROLL_dark_cpll_decide_mode_error(data)          (0x30000000&((data)<<28))
#define DARK_CPLL_CONTROLL_dark_cpll_decide_mode(data)                (0x07000000&((data)<<24))
#define DARK_CPLL_CONTROLL_dark_cpll_vsync_num(data)                  (0x00FF0000&((data)<<16))
#define DARK_CPLL_CONTROLL_dark_cpll_chromalock_sel(data)             (0x00008000&((data)<<15))
#define DARK_CPLL_CONTROLL_dark_cpll_mode_en_pali(data)               (0x00004000&((data)<<14))
#define DARK_CPLL_CONTROLL_dark_cpll_mode_en_pal60(data)              (0x00002000&((data)<<13))
#define DARK_CPLL_CONTROLL_dark_cpll_mode_en_ntsc443(data)            (0x00001000&((data)<<12))
#define DARK_CPLL_CONTROLL_dark_cpll_mode_en_paln(data)               (0x00000800&((data)<<11))
#define DARK_CPLL_CONTROLL_dark_cpll_mode_en_ntsc50(data)             (0x00000400&((data)<<10))
#define DARK_CPLL_CONTROLL_dark_cpll_mode_en_palm(data)               (0x00000200&((data)<<9))
#define DARK_CPLL_CONTROLL_dark_cpll_mode_en_ntsc(data)               (0x00000100&((data)<<8))
#define DARK_CPLL_CONTROLL_dark_cpll_fix_mode_en(data)                (0x00000080&((data)<<7))
#define DARK_CPLL_CONTROLL_dark_cpll_user_mode(data)                  (0x00000070&((data)<<4))
#define DARK_CPLL_CONTROLL_dark_cpll_mode(data)                       (0x0000000C&((data)<<2))
#define DARK_CPLL_CONTROLL_dark_cpll_auto_run(data)                   (0x00000002&((data)<<1))
#define DARK_CPLL_CONTROLL_dark_cpll_start(data)                      (0x00000001&(data))
#define DARK_CPLL_CONTROLL_get_dark_cpll_decide_mode_error(data)      ((0x30000000&(data))>>28)
#define DARK_CPLL_CONTROLL_get_dark_cpll_decide_mode(data)            ((0x07000000&(data))>>24)
#define DARK_CPLL_CONTROLL_get_dark_cpll_vsync_num(data)              ((0x00FF0000&(data))>>16)
#define DARK_CPLL_CONTROLL_get_dark_cpll_chromalock_sel(data)         ((0x00008000&(data))>>15)
#define DARK_CPLL_CONTROLL_get_dark_cpll_mode_en_pali(data)           ((0x00004000&(data))>>14)
#define DARK_CPLL_CONTROLL_get_dark_cpll_mode_en_pal60(data)          ((0x00002000&(data))>>13)
#define DARK_CPLL_CONTROLL_get_dark_cpll_mode_en_ntsc443(data)        ((0x00001000&(data))>>12)
#define DARK_CPLL_CONTROLL_get_dark_cpll_mode_en_paln(data)           ((0x00000800&(data))>>11)
#define DARK_CPLL_CONTROLL_get_dark_cpll_mode_en_ntsc50(data)         ((0x00000400&(data))>>10)
#define DARK_CPLL_CONTROLL_get_dark_cpll_mode_en_palm(data)           ((0x00000200&(data))>>9)
#define DARK_CPLL_CONTROLL_get_dark_cpll_mode_en_ntsc(data)           ((0x00000100&(data))>>8)
#define DARK_CPLL_CONTROLL_get_dark_cpll_fix_mode_en(data)            ((0x00000080&(data))>>7)
#define DARK_CPLL_CONTROLL_get_dark_cpll_user_mode(data)              ((0x00000070&(data))>>4)
#define DARK_CPLL_CONTROLL_get_dark_cpll_mode(data)                   ((0x0000000C&(data))>>2)
#define DARK_CPLL_CONTROLL_get_dark_cpll_auto_run(data)               ((0x00000002&(data))>>1)
#define DARK_CPLL_CONTROLL_get_dark_cpll_start(data)                  (0x00000001&(data))


#define DARK_CPLL_RESULT                                              0x18019594
#define DARK_CPLL_RESULT_reg_addr                                     "0xb8019594"
#define DARK_CPLL_RESULT_reg                                          0xb8019594
#define DARK_CPLL_RESULT_inst_addr                                    "0x0165"
#define DARK_CPLL_RESULT_inst                                         0x0165
#define DARK_CPLL_RESULT_chromalock_acc_dark_shift                    (31)
#define DARK_CPLL_RESULT_chromalock_dark_shift                        (30)
#define DARK_CPLL_RESULT_pal_flag_dark_shift                          (29)
#define DARK_CPLL_RESULT_palm_flag_dark_shift                         (28)
#define DARK_CPLL_RESULT_dark_cpll_loop_done_shift                    (24)
#define DARK_CPLL_RESULT_dark_cpll_pali_palm_flag_shift               (22)
#define DARK_CPLL_RESULT_dark_cpll_pal60_palm_flag_shift              (21)
#define DARK_CPLL_RESULT_dark_cpll_ntsc443_palm_flag_shift            (20)
#define DARK_CPLL_RESULT_dark_cpll_paln_palm_flag_shift               (19)
#define DARK_CPLL_RESULT_dark_cpll_ntsc50_palm_flag_shift             (18)
#define DARK_CPLL_RESULT_dark_cpll_palm_palm_flag_shift               (17)
#define DARK_CPLL_RESULT_dark_cpll_ntsc_palm_flag_shift               (16)
#define DARK_CPLL_RESULT_dark_cpll_pali_pal_flag_shift                (14)
#define DARK_CPLL_RESULT_dark_cpll_pal60_pal_flag_shift               (13)
#define DARK_CPLL_RESULT_dark_cpll_ntsc443_pal_flag_shift             (12)
#define DARK_CPLL_RESULT_dark_cpll_paln_pal_flag_shift                (11)
#define DARK_CPLL_RESULT_dark_cpll_ntsc50_pal_flag_shift              (10)
#define DARK_CPLL_RESULT_dark_cpll_palm_pal_flag_shift                (9)
#define DARK_CPLL_RESULT_dark_cpll_ntsc_pal_flag_shift                (8)
#define DARK_CPLL_RESULT_dark_cpll_pali_lock_shift                    (6)
#define DARK_CPLL_RESULT_dark_cpll_pal60_lock_shift                   (5)
#define DARK_CPLL_RESULT_dark_cpll_ntsc443_lock_shift                 (4)
#define DARK_CPLL_RESULT_dark_cpll_paln_lock_shift                    (3)
#define DARK_CPLL_RESULT_dark_cpll_ntsc50_lock_shift                  (2)
#define DARK_CPLL_RESULT_dark_cpll_palm_lock_shift                    (1)
#define DARK_CPLL_RESULT_dark_cpll_ntsc_lock_shift                    (0)
#define DARK_CPLL_RESULT_chromalock_acc_dark_mask                     (0x80000000)
#define DARK_CPLL_RESULT_chromalock_dark_mask                         (0x40000000)
#define DARK_CPLL_RESULT_pal_flag_dark_mask                           (0x20000000)
#define DARK_CPLL_RESULT_palm_flag_dark_mask                          (0x10000000)
#define DARK_CPLL_RESULT_dark_cpll_loop_done_mask                     (0x01000000)
#define DARK_CPLL_RESULT_dark_cpll_pali_palm_flag_mask                (0x00400000)
#define DARK_CPLL_RESULT_dark_cpll_pal60_palm_flag_mask               (0x00200000)
#define DARK_CPLL_RESULT_dark_cpll_ntsc443_palm_flag_mask             (0x00100000)
#define DARK_CPLL_RESULT_dark_cpll_paln_palm_flag_mask                (0x00080000)
#define DARK_CPLL_RESULT_dark_cpll_ntsc50_palm_flag_mask              (0x00040000)
#define DARK_CPLL_RESULT_dark_cpll_palm_palm_flag_mask                (0x00020000)
#define DARK_CPLL_RESULT_dark_cpll_ntsc_palm_flag_mask                (0x00010000)
#define DARK_CPLL_RESULT_dark_cpll_pali_pal_flag_mask                 (0x00004000)
#define DARK_CPLL_RESULT_dark_cpll_pal60_pal_flag_mask                (0x00002000)
#define DARK_CPLL_RESULT_dark_cpll_ntsc443_pal_flag_mask              (0x00001000)
#define DARK_CPLL_RESULT_dark_cpll_paln_pal_flag_mask                 (0x00000800)
#define DARK_CPLL_RESULT_dark_cpll_ntsc50_pal_flag_mask               (0x00000400)
#define DARK_CPLL_RESULT_dark_cpll_palm_pal_flag_mask                 (0x00000200)
#define DARK_CPLL_RESULT_dark_cpll_ntsc_pal_flag_mask                 (0x00000100)
#define DARK_CPLL_RESULT_dark_cpll_pali_lock_mask                     (0x00000040)
#define DARK_CPLL_RESULT_dark_cpll_pal60_lock_mask                    (0x00000020)
#define DARK_CPLL_RESULT_dark_cpll_ntsc443_lock_mask                  (0x00000010)
#define DARK_CPLL_RESULT_dark_cpll_paln_lock_mask                     (0x00000008)
#define DARK_CPLL_RESULT_dark_cpll_ntsc50_lock_mask                   (0x00000004)
#define DARK_CPLL_RESULT_dark_cpll_palm_lock_mask                     (0x00000002)
#define DARK_CPLL_RESULT_dark_cpll_ntsc_lock_mask                     (0x00000001)
#define DARK_CPLL_RESULT_chromalock_acc_dark(data)                    (0x80000000&((data)<<31))
#define DARK_CPLL_RESULT_chromalock_dark(data)                        (0x40000000&((data)<<30))
#define DARK_CPLL_RESULT_pal_flag_dark(data)                          (0x20000000&((data)<<29))
#define DARK_CPLL_RESULT_palm_flag_dark(data)                         (0x10000000&((data)<<28))
#define DARK_CPLL_RESULT_dark_cpll_loop_done(data)                    (0x01000000&((data)<<24))
#define DARK_CPLL_RESULT_dark_cpll_pali_palm_flag(data)               (0x00400000&((data)<<22))
#define DARK_CPLL_RESULT_dark_cpll_pal60_palm_flag(data)              (0x00200000&((data)<<21))
#define DARK_CPLL_RESULT_dark_cpll_ntsc443_palm_flag(data)            (0x00100000&((data)<<20))
#define DARK_CPLL_RESULT_dark_cpll_paln_palm_flag(data)               (0x00080000&((data)<<19))
#define DARK_CPLL_RESULT_dark_cpll_ntsc50_palm_flag(data)             (0x00040000&((data)<<18))
#define DARK_CPLL_RESULT_dark_cpll_palm_palm_flag(data)               (0x00020000&((data)<<17))
#define DARK_CPLL_RESULT_dark_cpll_ntsc_palm_flag(data)               (0x00010000&((data)<<16))
#define DARK_CPLL_RESULT_dark_cpll_pali_pal_flag(data)                (0x00004000&((data)<<14))
#define DARK_CPLL_RESULT_dark_cpll_pal60_pal_flag(data)               (0x00002000&((data)<<13))
#define DARK_CPLL_RESULT_dark_cpll_ntsc443_pal_flag(data)             (0x00001000&((data)<<12))
#define DARK_CPLL_RESULT_dark_cpll_paln_pal_flag(data)                (0x00000800&((data)<<11))
#define DARK_CPLL_RESULT_dark_cpll_ntsc50_pal_flag(data)              (0x00000400&((data)<<10))
#define DARK_CPLL_RESULT_dark_cpll_palm_pal_flag(data)                (0x00000200&((data)<<9))
#define DARK_CPLL_RESULT_dark_cpll_ntsc_pal_flag(data)                (0x00000100&((data)<<8))
#define DARK_CPLL_RESULT_dark_cpll_pali_lock(data)                    (0x00000040&((data)<<6))
#define DARK_CPLL_RESULT_dark_cpll_pal60_lock(data)                   (0x00000020&((data)<<5))
#define DARK_CPLL_RESULT_dark_cpll_ntsc443_lock(data)                 (0x00000010&((data)<<4))
#define DARK_CPLL_RESULT_dark_cpll_paln_lock(data)                    (0x00000008&((data)<<3))
#define DARK_CPLL_RESULT_dark_cpll_ntsc50_lock(data)                  (0x00000004&((data)<<2))
#define DARK_CPLL_RESULT_dark_cpll_palm_lock(data)                    (0x00000002&((data)<<1))
#define DARK_CPLL_RESULT_dark_cpll_ntsc_lock(data)                    (0x00000001&(data))
#define DARK_CPLL_RESULT_get_chromalock_acc_dark(data)                ((0x80000000&(data))>>31)
#define DARK_CPLL_RESULT_get_chromalock_dark(data)                    ((0x40000000&(data))>>30)
#define DARK_CPLL_RESULT_get_pal_flag_dark(data)                      ((0x20000000&(data))>>29)
#define DARK_CPLL_RESULT_get_palm_flag_dark(data)                     ((0x10000000&(data))>>28)
#define DARK_CPLL_RESULT_get_dark_cpll_loop_done(data)                ((0x01000000&(data))>>24)
#define DARK_CPLL_RESULT_get_dark_cpll_pali_palm_flag(data)           ((0x00400000&(data))>>22)
#define DARK_CPLL_RESULT_get_dark_cpll_pal60_palm_flag(data)          ((0x00200000&(data))>>21)
#define DARK_CPLL_RESULT_get_dark_cpll_ntsc443_palm_flag(data)        ((0x00100000&(data))>>20)
#define DARK_CPLL_RESULT_get_dark_cpll_paln_palm_flag(data)           ((0x00080000&(data))>>19)
#define DARK_CPLL_RESULT_get_dark_cpll_ntsc50_palm_flag(data)         ((0x00040000&(data))>>18)
#define DARK_CPLL_RESULT_get_dark_cpll_palm_palm_flag(data)           ((0x00020000&(data))>>17)
#define DARK_CPLL_RESULT_get_dark_cpll_ntsc_palm_flag(data)           ((0x00010000&(data))>>16)
#define DARK_CPLL_RESULT_get_dark_cpll_pali_pal_flag(data)            ((0x00004000&(data))>>14)
#define DARK_CPLL_RESULT_get_dark_cpll_pal60_pal_flag(data)           ((0x00002000&(data))>>13)
#define DARK_CPLL_RESULT_get_dark_cpll_ntsc443_pal_flag(data)         ((0x00001000&(data))>>12)
#define DARK_CPLL_RESULT_get_dark_cpll_paln_pal_flag(data)            ((0x00000800&(data))>>11)
#define DARK_CPLL_RESULT_get_dark_cpll_ntsc50_pal_flag(data)          ((0x00000400&(data))>>10)
#define DARK_CPLL_RESULT_get_dark_cpll_palm_pal_flag(data)            ((0x00000200&(data))>>9)
#define DARK_CPLL_RESULT_get_dark_cpll_ntsc_pal_flag(data)            ((0x00000100&(data))>>8)
#define DARK_CPLL_RESULT_get_dark_cpll_pali_lock(data)                ((0x00000040&(data))>>6)
#define DARK_CPLL_RESULT_get_dark_cpll_pal60_lock(data)               ((0x00000020&(data))>>5)
#define DARK_CPLL_RESULT_get_dark_cpll_ntsc443_lock(data)             ((0x00000010&(data))>>4)
#define DARK_CPLL_RESULT_get_dark_cpll_paln_lock(data)                ((0x00000008&(data))>>3)
#define DARK_CPLL_RESULT_get_dark_cpll_ntsc50_lock(data)              ((0x00000004&(data))>>2)
#define DARK_CPLL_RESULT_get_dark_cpll_palm_lock(data)                ((0x00000002&(data))>>1)
#define DARK_CPLL_RESULT_get_dark_cpll_ntsc_lock(data)                (0x00000001&(data))


#define IRQ_MASK1                                                     0x180195a0
#define IRQ_MASK1_reg_addr                                            "0xb80195a0"
#define IRQ_MASK1_reg                                                 0xb80195a0
#define IRQ_MASK1_inst_addr                                           "0x0168"
#define IRQ_MASK1_inst                                                0x0168
#define IRQ_MASK1_vd_irq_en_shift                                     (8)
#define IRQ_MASK1_vcr_irq_en_shift                                    (7)
#define IRQ_MASK1_nosig_irq_en_shift                                  (6)
#define IRQ_MASK1_mode_irq_en_shift                                   (5)
#define IRQ_MASK1_proscan_irq_en_shift                                (4)
#define IRQ_MASK1_noisy_irq_en_shift                                  (3)
#define IRQ_MASK1_chromalock_irq_en_shift                             (2)
#define IRQ_MASK1_vlock_irq_en_shift                                  (1)
#define IRQ_MASK1_hlock_irq_en_shift                                  (0)
#define IRQ_MASK1_vd_irq_en_mask                                      (0x00000100)
#define IRQ_MASK1_vcr_irq_en_mask                                     (0x00000080)
#define IRQ_MASK1_nosig_irq_en_mask                                   (0x00000040)
#define IRQ_MASK1_mode_irq_en_mask                                    (0x00000020)
#define IRQ_MASK1_proscan_irq_en_mask                                 (0x00000010)
#define IRQ_MASK1_noisy_irq_en_mask                                   (0x00000008)
#define IRQ_MASK1_chromalock_irq_en_mask                              (0x00000004)
#define IRQ_MASK1_vlock_irq_en_mask                                   (0x00000002)
#define IRQ_MASK1_hlock_irq_en_mask                                   (0x00000001)
#define IRQ_MASK1_vd_irq_en(data)                                     (0x00000100&((data)<<8))
#define IRQ_MASK1_vcr_irq_en(data)                                    (0x00000080&((data)<<7))
#define IRQ_MASK1_nosig_irq_en(data)                                  (0x00000040&((data)<<6))
#define IRQ_MASK1_mode_irq_en(data)                                   (0x00000020&((data)<<5))
#define IRQ_MASK1_proscan_irq_en(data)                                (0x00000010&((data)<<4))
#define IRQ_MASK1_noisy_irq_en(data)                                  (0x00000008&((data)<<3))
#define IRQ_MASK1_chromalock_irq_en(data)                             (0x00000004&((data)<<2))
#define IRQ_MASK1_vlock_irq_en(data)                                  (0x00000002&((data)<<1))
#define IRQ_MASK1_hlock_irq_en(data)                                  (0x00000001&(data))
#define IRQ_MASK1_get_vd_irq_en(data)                                 ((0x00000100&(data))>>8)
#define IRQ_MASK1_get_vcr_irq_en(data)                                ((0x00000080&(data))>>7)
#define IRQ_MASK1_get_nosig_irq_en(data)                              ((0x00000040&(data))>>6)
#define IRQ_MASK1_get_mode_irq_en(data)                               ((0x00000020&(data))>>5)
#define IRQ_MASK1_get_proscan_irq_en(data)                            ((0x00000010&(data))>>4)
#define IRQ_MASK1_get_noisy_irq_en(data)                              ((0x00000008&(data))>>3)
#define IRQ_MASK1_get_chromalock_irq_en(data)                         ((0x00000004&(data))>>2)
#define IRQ_MASK1_get_vlock_irq_en(data)                              ((0x00000002&(data))>>1)
#define IRQ_MASK1_get_hlock_irq_en(data)                              (0x00000001&(data))


#define IRQ_MASK2                                                     0x180195a4
#define IRQ_MASK2_reg_addr                                            "0xb80195a4"
#define IRQ_MASK2_reg                                                 0xb80195a4
#define IRQ_MASK2_inst_addr                                           "0x0169"
#define IRQ_MASK2_inst                                                0x0169
#define IRQ_MASK2_vd_scene_change_irq_en_shift                        (5)
#define IRQ_MASK2_ddr_addr_irq_en_shift                               (4)
#define IRQ_MASK2_noisy_vbi_irq_en_shift                              (3)
#define IRQ_MASK2_coch_irq_en_shift                                   (2)
#define IRQ_MASK2_mv_irq_en_shift                                     (1)
#define IRQ_MASK2_field_irq_en_shift                                  (0)
#define IRQ_MASK2_vd_scene_change_irq_en_mask                         (0x00000020)
#define IRQ_MASK2_ddr_addr_irq_en_mask                                (0x00000010)
#define IRQ_MASK2_noisy_vbi_irq_en_mask                               (0x00000008)
#define IRQ_MASK2_coch_irq_en_mask                                    (0x00000004)
#define IRQ_MASK2_mv_irq_en_mask                                      (0x00000002)
#define IRQ_MASK2_field_irq_en_mask                                   (0x00000001)
#define IRQ_MASK2_vd_scene_change_irq_en(data)                        (0x00000020&((data)<<5))
#define IRQ_MASK2_ddr_addr_irq_en(data)                               (0x00000010&((data)<<4))
#define IRQ_MASK2_noisy_vbi_irq_en(data)                              (0x00000008&((data)<<3))
#define IRQ_MASK2_coch_irq_en(data)                                   (0x00000004&((data)<<2))
#define IRQ_MASK2_mv_irq_en(data)                                     (0x00000002&((data)<<1))
#define IRQ_MASK2_field_irq_en(data)                                  (0x00000001&(data))
#define IRQ_MASK2_get_vd_scene_change_irq_en(data)                    ((0x00000020&(data))>>5)
#define IRQ_MASK2_get_ddr_addr_irq_en(data)                           ((0x00000010&(data))>>4)
#define IRQ_MASK2_get_noisy_vbi_irq_en(data)                          ((0x00000008&(data))>>3)
#define IRQ_MASK2_get_coch_irq_en(data)                               ((0x00000004&(data))>>2)
#define IRQ_MASK2_get_mv_irq_en(data)                                 ((0x00000002&(data))>>1)
#define IRQ_MASK2_get_field_irq_en(data)                              (0x00000001&(data))


#define IRQ_MASK3                                                     0x180195a8
#define IRQ_MASK3_reg_addr                                            "0xb80195a8"
#define IRQ_MASK3_reg                                                 0xb80195a8
#define IRQ_MASK3_inst_addr                                           "0x016A"
#define IRQ_MASK3_inst                                                0x016A
#define IRQ_MASK3_ad1_over_irq_en_shift                               (7)
#define IRQ_MASK3_ad1_under_irq_en_shift                              (6)
#define IRQ_MASK3_ad2_over_irq_en_shift                               (5)
#define IRQ_MASK3_ad2_under_irq_en_shift                              (4)
#define IRQ_MASK3_ad3_over_irq_en_shift                               (3)
#define IRQ_MASK3_ad3_under_irq_en_shift                              (2)
#define IRQ_MASK3_ad4_over_irq_en_shift                               (1)
#define IRQ_MASK3_ad4_under_irq_en_shift                              (0)
#define IRQ_MASK3_ad1_over_irq_en_mask                                (0x00000080)
#define IRQ_MASK3_ad1_under_irq_en_mask                               (0x00000040)
#define IRQ_MASK3_ad2_over_irq_en_mask                                (0x00000020)
#define IRQ_MASK3_ad2_under_irq_en_mask                               (0x00000010)
#define IRQ_MASK3_ad3_over_irq_en_mask                                (0x00000008)
#define IRQ_MASK3_ad3_under_irq_en_mask                               (0x00000004)
#define IRQ_MASK3_ad4_over_irq_en_mask                                (0x00000002)
#define IRQ_MASK3_ad4_under_irq_en_mask                               (0x00000001)
#define IRQ_MASK3_ad1_over_irq_en(data)                               (0x00000080&((data)<<7))
#define IRQ_MASK3_ad1_under_irq_en(data)                              (0x00000040&((data)<<6))
#define IRQ_MASK3_ad2_over_irq_en(data)                               (0x00000020&((data)<<5))
#define IRQ_MASK3_ad2_under_irq_en(data)                              (0x00000010&((data)<<4))
#define IRQ_MASK3_ad3_over_irq_en(data)                               (0x00000008&((data)<<3))
#define IRQ_MASK3_ad3_under_irq_en(data)                              (0x00000004&((data)<<2))
#define IRQ_MASK3_ad4_over_irq_en(data)                               (0x00000002&((data)<<1))
#define IRQ_MASK3_ad4_under_irq_en(data)                              (0x00000001&(data))
#define IRQ_MASK3_get_ad1_over_irq_en(data)                           ((0x00000080&(data))>>7)
#define IRQ_MASK3_get_ad1_under_irq_en(data)                          ((0x00000040&(data))>>6)
#define IRQ_MASK3_get_ad2_over_irq_en(data)                           ((0x00000020&(data))>>5)
#define IRQ_MASK3_get_ad2_under_irq_en(data)                          ((0x00000010&(data))>>4)
#define IRQ_MASK3_get_ad3_over_irq_en(data)                           ((0x00000008&(data))>>3)
#define IRQ_MASK3_get_ad3_under_irq_en(data)                          ((0x00000004&(data))>>2)
#define IRQ_MASK3_get_ad4_over_irq_en(data)                           ((0x00000002&(data))>>1)
#define IRQ_MASK3_get_ad4_under_irq_en(data)                          (0x00000001&(data))


#define IRQ_STATUS1                                                   0x180195ac
#define IRQ_STATUS1_reg_addr                                          "0xb80195ac"
#define IRQ_STATUS1_reg                                               0xb80195ac
#define IRQ_STATUS1_inst_addr                                         "0x016B"
#define IRQ_STATUS1_inst                                              0x016B
#define IRQ_STATUS1_vcr_irq_shift                                     (7)
#define IRQ_STATUS1_nosig_irq_shift                                   (6)
#define IRQ_STATUS1_mode_irq_shift                                    (5)
#define IRQ_STATUS1_proscan_irq_shift                                 (4)
#define IRQ_STATUS1_noisy_irq_shift                                   (3)
#define IRQ_STATUS1_chromalock_irq_shift                              (2)
#define IRQ_STATUS1_vlock_irq_shift                                   (1)
#define IRQ_STATUS1_hlock_irq_shift                                   (0)
#define IRQ_STATUS1_vcr_irq_mask                                      (0x00000080)
#define IRQ_STATUS1_nosig_irq_mask                                    (0x00000040)
#define IRQ_STATUS1_mode_irq_mask                                     (0x00000020)
#define IRQ_STATUS1_proscan_irq_mask                                  (0x00000010)
#define IRQ_STATUS1_noisy_irq_mask                                    (0x00000008)
#define IRQ_STATUS1_chromalock_irq_mask                               (0x00000004)
#define IRQ_STATUS1_vlock_irq_mask                                    (0x00000002)
#define IRQ_STATUS1_hlock_irq_mask                                    (0x00000001)
#define IRQ_STATUS1_vcr_irq(data)                                     (0x00000080&((data)<<7))
#define IRQ_STATUS1_nosig_irq(data)                                   (0x00000040&((data)<<6))
#define IRQ_STATUS1_mode_irq(data)                                    (0x00000020&((data)<<5))
#define IRQ_STATUS1_proscan_irq(data)                                 (0x00000010&((data)<<4))
#define IRQ_STATUS1_noisy_irq(data)                                   (0x00000008&((data)<<3))
#define IRQ_STATUS1_chromalock_irq(data)                              (0x00000004&((data)<<2))
#define IRQ_STATUS1_vlock_irq(data)                                   (0x00000002&((data)<<1))
#define IRQ_STATUS1_hlock_irq(data)                                   (0x00000001&(data))
#define IRQ_STATUS1_get_vcr_irq(data)                                 ((0x00000080&(data))>>7)
#define IRQ_STATUS1_get_nosig_irq(data)                               ((0x00000040&(data))>>6)
#define IRQ_STATUS1_get_mode_irq(data)                                ((0x00000020&(data))>>5)
#define IRQ_STATUS1_get_proscan_irq(data)                             ((0x00000010&(data))>>4)
#define IRQ_STATUS1_get_noisy_irq(data)                               ((0x00000008&(data))>>3)
#define IRQ_STATUS1_get_chromalock_irq(data)                          ((0x00000004&(data))>>2)
#define IRQ_STATUS1_get_vlock_irq(data)                               ((0x00000002&(data))>>1)
#define IRQ_STATUS1_get_hlock_irq(data)                               (0x00000001&(data))


#define IRQ_STATUS2                                                   0x180195b0
#define IRQ_STATUS2_reg_addr                                          "0xb80195b0"
#define IRQ_STATUS2_reg                                               0xb80195b0
#define IRQ_STATUS2_inst_addr                                         "0x016C"
#define IRQ_STATUS2_inst                                              0x016C
#define IRQ_STATUS2_vd_scene_change_irq_shift                         (5)
#define IRQ_STATUS2_ddr_addr_irq_shift                                (4)
#define IRQ_STATUS2_noisy_vbi_irq_shift                               (3)
#define IRQ_STATUS2_coch_irq_shift                                    (2)
#define IRQ_STATUS2_mv_irq_shift                                      (1)
#define IRQ_STATUS2_field_irq_shift                                   (0)
#define IRQ_STATUS2_vd_scene_change_irq_mask                          (0x00000020)
#define IRQ_STATUS2_ddr_addr_irq_mask                                 (0x00000010)
#define IRQ_STATUS2_noisy_vbi_irq_mask                                (0x00000008)
#define IRQ_STATUS2_coch_irq_mask                                     (0x00000004)
#define IRQ_STATUS2_mv_irq_mask                                       (0x00000002)
#define IRQ_STATUS2_field_irq_mask                                    (0x00000001)
#define IRQ_STATUS2_vd_scene_change_irq(data)                         (0x00000020&((data)<<5))
#define IRQ_STATUS2_ddr_addr_irq(data)                                (0x00000010&((data)<<4))
#define IRQ_STATUS2_noisy_vbi_irq(data)                               (0x00000008&((data)<<3))
#define IRQ_STATUS2_coch_irq(data)                                    (0x00000004&((data)<<2))
#define IRQ_STATUS2_mv_irq(data)                                      (0x00000002&((data)<<1))
#define IRQ_STATUS2_field_irq(data)                                   (0x00000001&(data))
#define IRQ_STATUS2_get_vd_scene_change_irq(data)                     ((0x00000020&(data))>>5)
#define IRQ_STATUS2_get_ddr_addr_irq(data)                            ((0x00000010&(data))>>4)
#define IRQ_STATUS2_get_noisy_vbi_irq(data)                           ((0x00000008&(data))>>3)
#define IRQ_STATUS2_get_coch_irq(data)                                ((0x00000004&(data))>>2)
#define IRQ_STATUS2_get_mv_irq(data)                                  ((0x00000002&(data))>>1)
#define IRQ_STATUS2_get_field_irq(data)                               (0x00000001&(data))


#define IRQ_STATUS3                                                   0x180195b4
#define IRQ_STATUS3_reg_addr                                          "0xb80195b4"
#define IRQ_STATUS3_reg                                               0xb80195b4
#define IRQ_STATUS3_inst_addr                                         "0x016D"
#define IRQ_STATUS3_inst                                              0x016D
#define IRQ_STATUS3_ad1_overflow_irq_shift                            (7)
#define IRQ_STATUS3_ad1_underflow_irq_shift                           (6)
#define IRQ_STATUS3_ad2_overflow_irq_shift                            (5)
#define IRQ_STATUS3_ad2_underflow_irq_shift                           (4)
#define IRQ_STATUS3_ad3_overflow_irq_shift                            (3)
#define IRQ_STATUS3_ad3_underflow_irq_shift                           (2)
#define IRQ_STATUS3_ad4_overflow_irq_shift                            (1)
#define IRQ_STATUS3_ad4_underflow_irq_shift                           (0)
#define IRQ_STATUS3_ad1_overflow_irq_mask                             (0x00000080)
#define IRQ_STATUS3_ad1_underflow_irq_mask                            (0x00000040)
#define IRQ_STATUS3_ad2_overflow_irq_mask                             (0x00000020)
#define IRQ_STATUS3_ad2_underflow_irq_mask                            (0x00000010)
#define IRQ_STATUS3_ad3_overflow_irq_mask                             (0x00000008)
#define IRQ_STATUS3_ad3_underflow_irq_mask                            (0x00000004)
#define IRQ_STATUS3_ad4_overflow_irq_mask                             (0x00000002)
#define IRQ_STATUS3_ad4_underflow_irq_mask                            (0x00000001)
#define IRQ_STATUS3_ad1_overflow_irq(data)                            (0x00000080&((data)<<7))
#define IRQ_STATUS3_ad1_underflow_irq(data)                           (0x00000040&((data)<<6))
#define IRQ_STATUS3_ad2_overflow_irq(data)                            (0x00000020&((data)<<5))
#define IRQ_STATUS3_ad2_underflow_irq(data)                           (0x00000010&((data)<<4))
#define IRQ_STATUS3_ad3_overflow_irq(data)                            (0x00000008&((data)<<3))
#define IRQ_STATUS3_ad3_underflow_irq(data)                           (0x00000004&((data)<<2))
#define IRQ_STATUS3_ad4_overflow_irq(data)                            (0x00000002&((data)<<1))
#define IRQ_STATUS3_ad4_underflow_irq(data)                           (0x00000001&(data))
#define IRQ_STATUS3_get_ad1_overflow_irq(data)                        ((0x00000080&(data))>>7)
#define IRQ_STATUS3_get_ad1_underflow_irq(data)                       ((0x00000040&(data))>>6)
#define IRQ_STATUS3_get_ad2_overflow_irq(data)                        ((0x00000020&(data))>>5)
#define IRQ_STATUS3_get_ad2_underflow_irq(data)                       ((0x00000010&(data))>>4)
#define IRQ_STATUS3_get_ad3_overflow_irq(data)                        ((0x00000008&(data))>>3)
#define IRQ_STATUS3_get_ad3_underflow_irq(data)                       ((0x00000004&(data))>>2)
#define IRQ_STATUS3_get_ad4_overflow_irq(data)                        ((0x00000002&(data))>>1)
#define IRQ_STATUS3_get_ad4_underflow_irq(data)                       (0x00000001&(data))


#define ADC_LIMIT_THRESHOLD                                           0x180195b8
#define ADC_LIMIT_THRESHOLD_reg_addr                                  "0xb80195b8"
#define ADC_LIMIT_THRESHOLD_reg                                       0xb80195b8
#define ADC_LIMIT_THRESHOLD_inst_addr                                 "0x016E"
#define ADC_LIMIT_THRESHOLD_inst                                      0x016E
#define ADC_LIMIT_THRESHOLD_adc_over_threh_shift                      (4)
#define ADC_LIMIT_THRESHOLD_adc_under_threh_shift                     (0)
#define ADC_LIMIT_THRESHOLD_adc_over_threh_mask                       (0x000000F0)
#define ADC_LIMIT_THRESHOLD_adc_under_threh_mask                      (0x0000000F)
#define ADC_LIMIT_THRESHOLD_adc_over_threh(data)                      (0x000000F0&((data)<<4))
#define ADC_LIMIT_THRESHOLD_adc_under_threh(data)                     (0x0000000F&(data))
#define ADC_LIMIT_THRESHOLD_get_adc_over_threh(data)                  ((0x000000F0&(data))>>4)
#define ADC_LIMIT_THRESHOLD_get_adc_under_threh(data)                 (0x0000000F&(data))


#define LDPAUSE_CTRL                                                  0x180195e0
#define LDPAUSE_CTRL_reg_addr                                         "0xb80195e0"
#define LDPAUSE_CTRL_reg                                              0xb80195e0
#define LDPAUSE_CTRL_inst_addr                                        "0x0178"
#define LDPAUSE_CTRL_inst                                             0x0178
#define LDPAUSE_CTRL_ld_pause_detect_shift                            (7)
#define LDPAUSE_CTRL_ldp_det_en_shift                                 (6)
#define LDPAUSE_CTRL_ldp_switch_en_shift                              (5)
#define LDPAUSE_CTRL_ldpaus_th_shift                                  (0)
#define LDPAUSE_CTRL_ld_pause_detect_mask                             (0x00000080)
#define LDPAUSE_CTRL_ldp_det_en_mask                                  (0x00000040)
#define LDPAUSE_CTRL_ldp_switch_en_mask                               (0x00000020)
#define LDPAUSE_CTRL_ldpaus_th_mask                                   (0x0000001F)
#define LDPAUSE_CTRL_ld_pause_detect(data)                            (0x00000080&((data)<<7))
#define LDPAUSE_CTRL_ldp_det_en(data)                                 (0x00000040&((data)<<6))
#define LDPAUSE_CTRL_ldp_switch_en(data)                              (0x00000020&((data)<<5))
#define LDPAUSE_CTRL_ldpaus_th(data)                                  (0x0000001F&(data))
#define LDPAUSE_CTRL_get_ld_pause_detect(data)                        ((0x00000080&(data))>>7)
#define LDPAUSE_CTRL_get_ldp_det_en(data)                             ((0x00000040&(data))>>6)
#define LDPAUSE_CTRL_get_ldp_switch_en(data)                          ((0x00000020&(data))>>5)
#define LDPAUSE_CTRL_get_ldpaus_th(data)                              (0x0000001F&(data))


#define VCR_OPTION                                                    0x180195e4
#define VCR_OPTION_reg_addr                                           "0xb80195e4"
#define VCR_OPTION_reg                                                0xb80195e4
#define VCR_OPTION_inst_addr                                          "0x0179"
#define VCR_OPTION_inst                                               0x0179
#define VCR_OPTION_coch_en_shift                                      (7)
#define VCR_OPTION_disp_freerun_sel_shift                             (6)
#define VCR_OPTION_vd_out_dvalid_sel_d1_shift                         (5)
#define VCR_OPTION_vcr_disable_shift                                  (4)
#define VCR_OPTION_freerun_sel_shift                                  (3)
#define VCR_OPTION_lock_h_on_no_signal_shift                          (2)
#define VCR_OPTION_disable_blue_screen_when_vcr_shift                 (1)
#define VCR_OPTION_detect_vcr_when_h_unlock_shift                     (0)
#define VCR_OPTION_coch_en_mask                                       (0x00000080)
#define VCR_OPTION_disp_freerun_sel_mask                              (0x00000040)
#define VCR_OPTION_vd_out_dvalid_sel_d1_mask                          (0x00000020)
#define VCR_OPTION_vcr_disable_mask                                   (0x00000010)
#define VCR_OPTION_freerun_sel_mask                                   (0x00000008)
#define VCR_OPTION_lock_h_on_no_signal_mask                           (0x00000004)
#define VCR_OPTION_disable_blue_screen_when_vcr_mask                  (0x00000002)
#define VCR_OPTION_detect_vcr_when_h_unlock_mask                      (0x00000001)
#define VCR_OPTION_coch_en(data)                                      (0x00000080&((data)<<7))
#define VCR_OPTION_disp_freerun_sel(data)                             (0x00000040&((data)<<6))
#define VCR_OPTION_vd_out_dvalid_sel_d1(data)                         (0x00000020&((data)<<5))
#define VCR_OPTION_vcr_disable(data)                                  (0x00000010&((data)<<4))
#define VCR_OPTION_freerun_sel(data)                                  (0x00000008&((data)<<3))
#define VCR_OPTION_lock_h_on_no_signal(data)                          (0x00000004&((data)<<2))
#define VCR_OPTION_disable_blue_screen_when_vcr(data)                 (0x00000002&((data)<<1))
#define VCR_OPTION_detect_vcr_when_h_unlock(data)                     (0x00000001&(data))
#define VCR_OPTION_get_coch_en(data)                                  ((0x00000080&(data))>>7)
#define VCR_OPTION_get_disp_freerun_sel(data)                         ((0x00000040&(data))>>6)
#define VCR_OPTION_get_vd_out_dvalid_sel_d1(data)                     ((0x00000020&(data))>>5)
#define VCR_OPTION_get_vcr_disable(data)                              ((0x00000010&(data))>>4)
#define VCR_OPTION_get_freerun_sel(data)                              ((0x00000008&(data))>>3)
#define VCR_OPTION_get_lock_h_on_no_signal(data)                      ((0x00000004&(data))>>2)
#define VCR_OPTION_get_disable_blue_screen_when_vcr(data)             ((0x00000002&(data))>>1)
#define VCR_OPTION_get_detect_vcr_when_h_unlock(data)                 (0x00000001&(data))


#define CENABLE_LINE_COUNT                                            0x180195e8
#define CENABLE_LINE_COUNT_reg_addr                                   "0xb80195e8"
#define CENABLE_LINE_COUNT_reg                                        0xb80195e8
#define CENABLE_LINE_COUNT_inst_addr                                  "0x017A"
#define CENABLE_LINE_COUNT_inst                                       0x017A
#define CENABLE_LINE_COUNT_cenable_line_count_shift                   (0)
#define CENABLE_LINE_COUNT_cenable_line_count_mask                    (0x000000FF)
#define CENABLE_LINE_COUNT_cenable_line_count(data)                   (0x000000FF&(data))
#define CENABLE_LINE_COUNT_get_cenable_line_count(data)               (0x000000FF&(data))


#define SIGNAL_STM_CONTROL                                            0x180195ec
#define SIGNAL_STM_CONTROL_reg_addr                                   "0xb80195ec"
#define SIGNAL_STM_CONTROL_reg                                        0xb80195ec
#define SIGNAL_STM_CONTROL_inst_addr                                  "0x017B"
#define SIGNAL_STM_CONTROL_inst                                       0x017B
#define SIGNAL_STM_CONTROL_auto_3dchange_vcr_shift                    (5)
#define SIGNAL_STM_CONTROL_auto_3dchange_noisy_shift                  (4)
#define SIGNAL_STM_CONTROL_field_toggle_en_shift                      (3)
#define SIGNAL_STM_CONTROL_cbcr_ini_mux_shift                         (2)
#define SIGNAL_STM_CONTROL_auto_3dchange_vcr_mask                     (0x00000020)
#define SIGNAL_STM_CONTROL_auto_3dchange_noisy_mask                   (0x00000010)
#define SIGNAL_STM_CONTROL_field_toggle_en_mask                       (0x00000008)
#define SIGNAL_STM_CONTROL_cbcr_ini_mux_mask                          (0x00000004)
#define SIGNAL_STM_CONTROL_auto_3dchange_vcr(data)                    (0x00000020&((data)<<5))
#define SIGNAL_STM_CONTROL_auto_3dchange_noisy(data)                  (0x00000010&((data)<<4))
#define SIGNAL_STM_CONTROL_field_toggle_en(data)                      (0x00000008&((data)<<3))
#define SIGNAL_STM_CONTROL_cbcr_ini_mux(data)                         (0x00000004&((data)<<2))
#define SIGNAL_STM_CONTROL_get_auto_3dchange_vcr(data)                ((0x00000020&(data))>>5)
#define SIGNAL_STM_CONTROL_get_auto_3dchange_noisy(data)              ((0x00000010&(data))>>4)
#define SIGNAL_STM_CONTROL_get_field_toggle_en(data)                  ((0x00000008&(data))>>3)
#define SIGNAL_STM_CONTROL_get_cbcr_ini_mux(data)                     ((0x00000004&(data))>>2)


#define CDETECT_PHASE_ERR_STATUS                                      0x180195f0
#define CDETECT_PHASE_ERR_STATUS_reg_addr                             "0xb80195f0"
#define CDETECT_PHASE_ERR_STATUS_reg                                  0xb80195f0
#define CDETECT_PHASE_ERR_STATUS_inst_addr                            "0x017C"
#define CDETECT_PHASE_ERR_STATUS_inst                                 0x017C
#define CDETECT_PHASE_ERR_STATUS_cdet_phase_err_status_shift          (0)
#define CDETECT_PHASE_ERR_STATUS_cdet_phase_err_status_mask           (0x00003FFF)
#define CDETECT_PHASE_ERR_STATUS_cdet_phase_err_status(data)          (0x00003FFF&(data))
#define CDETECT_PHASE_ERR_STATUS_get_cdet_phase_err_status(data)      (0x00003FFF&(data))


#define AD_SW_CTRL0                                                   0x18019608
#define AD_SW_CTRL0_reg_addr                                          "0xb8019608"
#define AD_SW_CTRL0_reg                                               0xb8019608
#define AD_SW_CTRL0_inst_addr                                         "0x0182"
#define AD_SW_CTRL0_inst                                              0x0182
#define AD_SW_CTRL0_sw_comp_shift                                     (6)
#define AD_SW_CTRL0_sw_pr_r_shift                                     (4)
#define AD_SW_CTRL0_sw_pb_b_shift                                     (2)
#define AD_SW_CTRL0_sw_g_shift                                        (0)
#define AD_SW_CTRL0_sw_comp_mask                                      (0x000000C0)
#define AD_SW_CTRL0_sw_pr_r_mask                                      (0x00000030)
#define AD_SW_CTRL0_sw_pb_b_mask                                      (0x0000000C)
#define AD_SW_CTRL0_sw_g_mask                                         (0x00000003)
#define AD_SW_CTRL0_sw_comp(data)                                     (0x000000C0&((data)<<6))
#define AD_SW_CTRL0_sw_pr_r(data)                                     (0x00000030&((data)<<4))
#define AD_SW_CTRL0_sw_pb_b(data)                                     (0x0000000C&((data)<<2))
#define AD_SW_CTRL0_sw_g(data)                                        (0x00000003&(data))
#define AD_SW_CTRL0_get_sw_comp(data)                                 ((0x000000C0&(data))>>6)
#define AD_SW_CTRL0_get_sw_pr_r(data)                                 ((0x00000030&(data))>>4)
#define AD_SW_CTRL0_get_sw_pb_b(data)                                 ((0x0000000C&(data))>>2)
#define AD_SW_CTRL0_get_sw_g(data)                                    (0x00000003&(data))


#define CLAMP_UPDN_EN                                                 0x1801960c
#define CLAMP_UPDN_EN_reg_addr                                        "0xb801960c"
#define CLAMP_UPDN_EN_reg                                             0xb801960c
#define CLAMP_UPDN_EN_inst_addr                                       "0x0183"
#define CLAMP_UPDN_EN_inst                                            0x0183
#define CLAMP_UPDN_EN_clamp_ad1_shift                                 (6)
#define CLAMP_UPDN_EN_clamp_ad2_shift                                 (4)
#define CLAMP_UPDN_EN_clamp_ad3_shift                                 (2)
#define CLAMP_UPDN_EN_clamp_ad4_shift                                 (0)
#define CLAMP_UPDN_EN_clamp_ad1_mask                                  (0x000000C0)
#define CLAMP_UPDN_EN_clamp_ad2_mask                                  (0x00000030)
#define CLAMP_UPDN_EN_clamp_ad3_mask                                  (0x0000000C)
#define CLAMP_UPDN_EN_clamp_ad4_mask                                  (0x00000003)
#define CLAMP_UPDN_EN_clamp_ad1(data)                                 (0x000000C0&((data)<<6))
#define CLAMP_UPDN_EN_clamp_ad2(data)                                 (0x00000030&((data)<<4))
#define CLAMP_UPDN_EN_clamp_ad3(data)                                 (0x0000000C&((data)<<2))
#define CLAMP_UPDN_EN_clamp_ad4(data)                                 (0x00000003&(data))
#define CLAMP_UPDN_EN_get_clamp_ad1(data)                             ((0x000000C0&(data))>>6)
#define CLAMP_UPDN_EN_get_clamp_ad2(data)                             ((0x00000030&(data))>>4)
#define CLAMP_UPDN_EN_get_clamp_ad3(data)                             ((0x0000000C&(data))>>2)
#define CLAMP_UPDN_EN_get_clamp_ad4(data)                             (0x00000003&(data))


#define CLAMP_RGB_UPDN_EN                                             0x18019610
#define CLAMP_RGB_UPDN_EN_reg_addr                                    "0xb8019610"
#define CLAMP_RGB_UPDN_EN_reg                                         0xb8019610
#define CLAMP_RGB_UPDN_EN_inst_addr                                   "0x0184"
#define CLAMP_RGB_UPDN_EN_inst                                        0x0184
#define CLAMP_RGB_UPDN_EN_clamp_a_up_en_shift                         (7)
#define CLAMP_RGB_UPDN_EN_clamp_a_dn_en_shift                         (6)
#define CLAMP_RGB_UPDN_EN_clamp_b_up_en_shift                         (5)
#define CLAMP_RGB_UPDN_EN_clamp_b_dn_en_shift                         (4)
#define CLAMP_RGB_UPDN_EN_clamp_c_up_en_shift                         (3)
#define CLAMP_RGB_UPDN_EN_clamp_c_dn_en_shift                         (2)
#define CLAMP_RGB_UPDN_EN_clamp_d_up_en_shift                         (1)
#define CLAMP_RGB_UPDN_EN_clamp_d_dn_en_shift                         (0)
#define CLAMP_RGB_UPDN_EN_clamp_a_up_en_mask                          (0x00000080)
#define CLAMP_RGB_UPDN_EN_clamp_a_dn_en_mask                          (0x00000040)
#define CLAMP_RGB_UPDN_EN_clamp_b_up_en_mask                          (0x00000020)
#define CLAMP_RGB_UPDN_EN_clamp_b_dn_en_mask                          (0x00000010)
#define CLAMP_RGB_UPDN_EN_clamp_c_up_en_mask                          (0x00000008)
#define CLAMP_RGB_UPDN_EN_clamp_c_dn_en_mask                          (0x00000004)
#define CLAMP_RGB_UPDN_EN_clamp_d_up_en_mask                          (0x00000002)
#define CLAMP_RGB_UPDN_EN_clamp_d_dn_en_mask                          (0x00000001)
#define CLAMP_RGB_UPDN_EN_clamp_a_up_en(data)                         (0x00000080&((data)<<7))
#define CLAMP_RGB_UPDN_EN_clamp_a_dn_en(data)                         (0x00000040&((data)<<6))
#define CLAMP_RGB_UPDN_EN_clamp_b_up_en(data)                         (0x00000020&((data)<<5))
#define CLAMP_RGB_UPDN_EN_clamp_b_dn_en(data)                         (0x00000010&((data)<<4))
#define CLAMP_RGB_UPDN_EN_clamp_c_up_en(data)                         (0x00000008&((data)<<3))
#define CLAMP_RGB_UPDN_EN_clamp_c_dn_en(data)                         (0x00000004&((data)<<2))
#define CLAMP_RGB_UPDN_EN_clamp_d_up_en(data)                         (0x00000002&((data)<<1))
#define CLAMP_RGB_UPDN_EN_clamp_d_dn_en(data)                         (0x00000001&(data))
#define CLAMP_RGB_UPDN_EN_get_clamp_a_up_en(data)                     ((0x00000080&(data))>>7)
#define CLAMP_RGB_UPDN_EN_get_clamp_a_dn_en(data)                     ((0x00000040&(data))>>6)
#define CLAMP_RGB_UPDN_EN_get_clamp_b_up_en(data)                     ((0x00000020&(data))>>5)
#define CLAMP_RGB_UPDN_EN_get_clamp_b_dn_en(data)                     ((0x00000010&(data))>>4)
#define CLAMP_RGB_UPDN_EN_get_clamp_c_up_en(data)                     ((0x00000008&(data))>>3)
#define CLAMP_RGB_UPDN_EN_get_clamp_c_dn_en(data)                     ((0x00000004&(data))>>2)
#define CLAMP_RGB_UPDN_EN_get_clamp_d_up_en(data)                     ((0x00000002&(data))>>1)
#define CLAMP_RGB_UPDN_EN_get_clamp_d_dn_en(data)                     (0x00000001&(data))


#define FSW_CTRL0                                                     0x18019618
#define FSW_CTRL0_reg_addr                                            "0xb8019618"
#define FSW_CTRL0_reg                                                 0xb8019618
#define FSW_CTRL0_inst_addr                                           "0x0186"
#define FSW_CTRL0_inst                                                0x0186
#define FSW_CTRL0_aa3_en_shift                                        (7)
#define FSW_CTRL0_fb_th_shift                                         (4)
#define FSW_CTRL0_fb_delay_shift                                      (0)
#define FSW_CTRL0_aa3_en_mask                                         (0x00000080)
#define FSW_CTRL0_fb_th_mask                                          (0x00000070)
#define FSW_CTRL0_fb_delay_mask                                       (0x0000000F)
#define FSW_CTRL0_aa3_en(data)                                        (0x00000080&((data)<<7))
#define FSW_CTRL0_fb_th(data)                                         (0x00000070&((data)<<4))
#define FSW_CTRL0_fb_delay(data)                                      (0x0000000F&(data))
#define FSW_CTRL0_get_aa3_en(data)                                    ((0x00000080&(data))>>7)
#define FSW_CTRL0_get_fb_th(data)                                     ((0x00000070&(data))>>4)
#define FSW_CTRL0_get_fb_delay(data)                                  (0x0000000F&(data))


#define FSW_CTRL1                                                     0x1801961c
#define FSW_CTRL1_reg_addr                                            "0xb801961c"
#define FSW_CTRL1_reg                                                 0xb801961c
#define FSW_CTRL1_inst_addr                                           "0x0187"
#define FSW_CTRL1_inst                                                0x0187
#define FSW_CTRL1_fb2rgb_dly_shift                                    (8)
#define FSW_CTRL1_rgb2cvbs_dly_shift                                  (0)
#define FSW_CTRL1_fb2rgb_dly_mask                                     (0x00000700)
#define FSW_CTRL1_rgb2cvbs_dly_mask                                   (0x0000003F)
#define FSW_CTRL1_fb2rgb_dly(data)                                    (0x00000700&((data)<<8))
#define FSW_CTRL1_rgb2cvbs_dly(data)                                  (0x0000003F&(data))
#define FSW_CTRL1_get_fb2rgb_dly(data)                                ((0x00000700&(data))>>8)
#define FSW_CTRL1_get_rgb2cvbs_dly(data)                              (0x0000003F&(data))


#define FSW_CTRL2                                                     0x18019620
#define FSW_CTRL2_reg_addr                                            "0xb8019620"
#define FSW_CTRL2_reg                                                 0xb8019620
#define FSW_CTRL2_inst_addr                                           "0x0188"
#define FSW_CTRL2_inst                                                0x0188
#define FSW_CTRL2_outfifo_444_sel_shift                               (8)
#define FSW_CTRL2_scart_en_shift                                      (7)
#define FSW_CTRL2_yout_limit_shift                                    (6)
#define FSW_CTRL2_fb_inv_shift                                        (5)
#define FSW_CTRL2_cout_limit_shift                                    (4)
#define FSW_CTRL2_out444_sel_shift                                    (3)
#define FSW_CTRL2_aa422_en_shift                                      (2)
#define FSW_CTRL2_fb_sw_shift                                         (1)
#define FSW_CTRL2_fb_en_shift                                         (0)
#define FSW_CTRL2_outfifo_444_sel_mask                                (0x00000100)
#define FSW_CTRL2_scart_en_mask                                       (0x00000080)
#define FSW_CTRL2_yout_limit_mask                                     (0x00000040)
#define FSW_CTRL2_fb_inv_mask                                         (0x00000020)
#define FSW_CTRL2_cout_limit_mask                                     (0x00000010)
#define FSW_CTRL2_out444_sel_mask                                     (0x00000008)
#define FSW_CTRL2_aa422_en_mask                                       (0x00000004)
#define FSW_CTRL2_fb_sw_mask                                          (0x00000002)
#define FSW_CTRL2_fb_en_mask                                          (0x00000001)
#define FSW_CTRL2_outfifo_444_sel(data)                               (0x00000100&((data)<<8))
#define FSW_CTRL2_scart_en(data)                                      (0x00000080&((data)<<7))
#define FSW_CTRL2_yout_limit(data)                                    (0x00000040&((data)<<6))
#define FSW_CTRL2_fb_inv(data)                                        (0x00000020&((data)<<5))
#define FSW_CTRL2_cout_limit(data)                                    (0x00000010&((data)<<4))
#define FSW_CTRL2_out444_sel(data)                                    (0x00000008&((data)<<3))
#define FSW_CTRL2_aa422_en(data)                                      (0x00000004&((data)<<2))
#define FSW_CTRL2_fb_sw(data)                                         (0x00000002&((data)<<1))
#define FSW_CTRL2_fb_en(data)                                         (0x00000001&(data))
#define FSW_CTRL2_get_outfifo_444_sel(data)                           ((0x00000100&(data))>>8)
#define FSW_CTRL2_get_scart_en(data)                                  ((0x00000080&(data))>>7)
#define FSW_CTRL2_get_yout_limit(data)                                ((0x00000040&(data))>>6)
#define FSW_CTRL2_get_fb_inv(data)                                    ((0x00000020&(data))>>5)
#define FSW_CTRL2_get_cout_limit(data)                                ((0x00000010&(data))>>4)
#define FSW_CTRL2_get_out444_sel(data)                                ((0x00000008&(data))>>3)
#define FSW_CTRL2_get_aa422_en(data)                                  ((0x00000004&(data))>>2)
#define FSW_CTRL2_get_fb_sw(data)                                     ((0x00000002&(data))>>1)
#define FSW_CTRL2_get_fb_en(data)                                     (0x00000001&(data))


#define FSW_CTRL3                                                     0x18019624
#define FSW_CTRL3_reg_addr                                            "0xb8019624"
#define FSW_CTRL3_reg                                                 0xb8019624
#define FSW_CTRL3_inst_addr                                           "0x0189"
#define FSW_CTRL3_inst                                                0x0189
#define FSW_CTRL3_fb_thmax_shift                                      (4)
#define FSW_CTRL3_fb_thmin_shift                                      (0)
#define FSW_CTRL3_fb_thmax_mask                                       (0x000000F0)
#define FSW_CTRL3_fb_thmin_mask                                       (0x0000000F)
#define FSW_CTRL3_fb_thmax(data)                                      (0x000000F0&((data)<<4))
#define FSW_CTRL3_fb_thmin(data)                                      (0x0000000F&(data))
#define FSW_CTRL3_get_fb_thmax(data)                                  ((0x000000F0&(data))>>4)
#define FSW_CTRL3_get_fb_thmin(data)                                  (0x0000000F&(data))


#define LUMA_CONTRAST2_ADJ                                            0x18019628
#define LUMA_CONTRAST2_ADJ_reg_addr                                   "0xb8019628"
#define LUMA_CONTRAST2_ADJ_reg                                        0xb8019628
#define LUMA_CONTRAST2_ADJ_inst_addr                                  "0x018A"
#define LUMA_CONTRAST2_ADJ_inst                                       0x018A
#define LUMA_CONTRAST2_ADJ_contrast2_shift                            (0)
#define LUMA_CONTRAST2_ADJ_contrast2_mask                             (0x000000FF)
#define LUMA_CONTRAST2_ADJ_contrast2(data)                            (0x000000FF&(data))
#define LUMA_CONTRAST2_ADJ_get_contrast2(data)                        (0x000000FF&(data))


#define LUMA_BRIGHTNESS2_ADJ                                          0x1801962c
#define LUMA_BRIGHTNESS2_ADJ_reg_addr                                 "0xb801962c"
#define LUMA_BRIGHTNESS2_ADJ_reg                                      0xb801962c
#define LUMA_BRIGHTNESS2_ADJ_inst_addr                                "0x018B"
#define LUMA_BRIGHTNESS2_ADJ_inst                                     0x018B
#define LUMA_BRIGHTNESS2_ADJ_brightness2_shift                        (0)
#define LUMA_BRIGHTNESS2_ADJ_brightness2_mask                         (0x000000FF)
#define LUMA_BRIGHTNESS2_ADJ_brightness2(data)                        (0x000000FF&(data))
#define LUMA_BRIGHTNESS2_ADJ_get_brightness2(data)                    (0x000000FF&(data))


#define CHROMA_SATURATION2_ADJ                                        0x18019630
#define CHROMA_SATURATION2_ADJ_reg_addr                               "0xb8019630"
#define CHROMA_SATURATION2_ADJ_reg                                    0xb8019630
#define CHROMA_SATURATION2_ADJ_inst_addr                              "0x018C"
#define CHROMA_SATURATION2_ADJ_inst                                   0x018C
#define CHROMA_SATURATION2_ADJ_cr_saturation_shift                    (0)
#define CHROMA_SATURATION2_ADJ_cr_saturation_mask                     (0x000000FF)
#define CHROMA_SATURATION2_ADJ_cr_saturation(data)                    (0x000000FF&(data))
#define CHROMA_SATURATION2_ADJ_get_cr_saturation(data)                (0x000000FF&(data))


#define CB_SAT_ADJ                                                    0x18019634
#define CB_SAT_ADJ_reg_addr                                           "0xb8019634"
#define CB_SAT_ADJ_reg                                                0xb8019634
#define CB_SAT_ADJ_inst_addr                                          "0x018D"
#define CB_SAT_ADJ_inst                                               0x018D
#define CB_SAT_ADJ_cb_saturation_shift                                (0)
#define CB_SAT_ADJ_cb_saturation_mask                                 (0x000000FF)
#define CB_SAT_ADJ_cb_saturation(data)                                (0x000000FF&(data))
#define CB_SAT_ADJ_get_cb_saturation(data)                            (0x000000FF&(data))


#define LUMA_PEAKING2                                                 0x18019638
#define LUMA_PEAKING2_reg_addr                                        "0xb8019638"
#define LUMA_PEAKING2_reg                                             0xb8019638
#define LUMA_PEAKING2_inst_addr                                       "0x018E"
#define LUMA_PEAKING2_inst                                            0x018E
#define LUMA_PEAKING2_peak_range2_shift                               (4)
#define LUMA_PEAKING2_peak_gain2_shift                                (1)
#define LUMA_PEAKING2_peak_en2_shift                                  (0)
#define LUMA_PEAKING2_peak_range2_mask                                (0x00000030)
#define LUMA_PEAKING2_peak_gain2_mask                                 (0x0000000E)
#define LUMA_PEAKING2_peak_en2_mask                                   (0x00000001)
#define LUMA_PEAKING2_peak_range2(data)                               (0x00000030&((data)<<4))
#define LUMA_PEAKING2_peak_gain2(data)                                (0x0000000E&((data)<<1))
#define LUMA_PEAKING2_peak_en2(data)                                  (0x00000001&(data))
#define LUMA_PEAKING2_get_peak_range2(data)                           ((0x00000030&(data))>>4)
#define LUMA_PEAKING2_get_peak_gain2(data)                            ((0x0000000E&(data))>>1)
#define LUMA_PEAKING2_get_peak_en2(data)                              (0x00000001&(data))


#define FSW_GAIN_CTRL                                                 0x1801963c
#define FSW_GAIN_CTRL_reg_addr                                        "0xb801963c"
#define FSW_GAIN_CTRL_reg                                             0xb801963c
#define FSW_GAIN_CTRL_inst_addr                                       "0x018F"
#define FSW_GAIN_CTRL_inst                                            0x018F
#define FSW_GAIN_CTRL_fbgain_en_shift                                 (7)
#define FSW_GAIN_CTRL_fbgain_shift                                    (0)
#define FSW_GAIN_CTRL_fbgain_en_mask                                  (0x00000080)
#define FSW_GAIN_CTRL_fbgain_mask                                     (0x0000007F)
#define FSW_GAIN_CTRL_fbgain_en(data)                                 (0x00000080&((data)<<7))
#define FSW_GAIN_CTRL_fbgain(data)                                    (0x0000007F&(data))
#define FSW_GAIN_CTRL_get_fbgain_en(data)                             ((0x00000080&(data))>>7)
#define FSW_GAIN_CTRL_get_fbgain(data)                                (0x0000007F&(data))


#define FSW_INPUT_STATUS                                              0x18019640
#define FSW_INPUT_STATUS_reg_addr                                     "0xb8019640"
#define FSW_INPUT_STATUS_reg                                          0xb8019640
#define FSW_INPUT_STATUS_inst_addr                                    "0x0190"
#define FSW_INPUT_STATUS_inst                                         0x0190
#define FSW_INPUT_STATUS_scart_vbi_rgb_sel_shift                      (4)
#define FSW_INPUT_STATUS_fb_status_shift                              (0)
#define FSW_INPUT_STATUS_scart_vbi_rgb_sel_mask                       (0x00000030)
#define FSW_INPUT_STATUS_fb_status_mask                               (0x00000007)
#define FSW_INPUT_STATUS_scart_vbi_rgb_sel(data)                      (0x00000030&((data)<<4))
#define FSW_INPUT_STATUS_fb_status(data)                              (0x00000007&(data))
#define FSW_INPUT_STATUS_get_scart_vbi_rgb_sel(data)                  ((0x00000030&(data))>>4)
#define FSW_INPUT_STATUS_get_fb_status(data)                          (0x00000007&(data))


#define ADCR_CALI_STATUS                                              0x18019650
#define ADCR_CALI_STATUS_reg_addr                                     "0xb8019650"
#define ADCR_CALI_STATUS_reg                                          0xb8019650
#define ADCR_CALI_STATUS_inst_addr                                    "0x0194"
#define ADCR_CALI_STATUS_inst                                         0x0194
#define ADCR_CALI_STATUS_yorr_in_offset_status_shift                  (0)
#define ADCR_CALI_STATUS_yorr_in_offset_status_mask                   (0x00000FFF)
#define ADCR_CALI_STATUS_yorr_in_offset_status(data)                  (0x00000FFF&(data))
#define ADCR_CALI_STATUS_get_yorr_in_offset_status(data)              (0x00000FFF&(data))


#define ADCG_CALI_STATUS                                              0x18019654
#define ADCG_CALI_STATUS_reg_addr                                     "0xb8019654"
#define ADCG_CALI_STATUS_reg                                          0xb8019654
#define ADCG_CALI_STATUS_inst_addr                                    "0x0195"
#define ADCG_CALI_STATUS_inst                                         0x0195
#define ADCG_CALI_STATUS_uorg_in_offset_status_shift                  (0)
#define ADCG_CALI_STATUS_uorg_in_offset_status_mask                   (0x00000FFF)
#define ADCG_CALI_STATUS_uorg_in_offset_status(data)                  (0x00000FFF&(data))
#define ADCG_CALI_STATUS_get_uorg_in_offset_status(data)              (0x00000FFF&(data))


#define ADCB_CALI_STATUS                                              0x18019658
#define ADCB_CALI_STATUS_reg_addr                                     "0xb8019658"
#define ADCB_CALI_STATUS_reg                                          0xb8019658
#define ADCB_CALI_STATUS_inst_addr                                    "0x0196"
#define ADCB_CALI_STATUS_inst                                         0x0196
#define ADCB_CALI_STATUS_vorb_in_offset_status_shift                  (0)
#define ADCB_CALI_STATUS_vorb_in_offset_status_mask                   (0x00000FFF)
#define ADCB_CALI_STATUS_vorb_in_offset_status(data)                  (0x00000FFF&(data))
#define ADCB_CALI_STATUS_get_vorb_in_offset_status(data)              (0x00000FFF&(data))


#define ADC_GAIN_R1                                                   0x1801965c
#define ADC_GAIN_R1_reg_addr                                          "0xb801965c"
#define ADC_GAIN_R1_reg                                               0xb801965c
#define ADC_GAIN_R1_inst_addr                                         "0x0197"
#define ADC_GAIN_R1_inst                                              0x0197
#define ADC_GAIN_R1_rgb_output_en_shift                               (7)
#define ADC_GAIN_R1_rgb_output_en_mask                                (0x00000080)
#define ADC_GAIN_R1_rgb_output_en(data)                               (0x00000080&((data)<<7))
#define ADC_GAIN_R1_get_rgb_output_en(data)                           ((0x00000080&(data))>>7)


#define ADC_GAIN_R                                                    0x18019660
#define ADC_GAIN_R_reg_addr                                           "0xb8019660"
#define ADC_GAIN_R_reg                                                0xb8019660
#define ADC_GAIN_R_inst_addr                                          "0x0198"
#define ADC_GAIN_R_inst                                               0x0198
#define ADC_GAIN_R_gain_r_shift                                       (0)
#define ADC_GAIN_R_gain_r_mask                                        (0x000003FF)
#define ADC_GAIN_R_gain_r(data)                                       (0x000003FF&(data))
#define ADC_GAIN_R_get_gain_r(data)                                   (0x000003FF&(data))


#define ADC_GAIN_G                                                    0x18019664
#define ADC_GAIN_G_reg_addr                                           "0xb8019664"
#define ADC_GAIN_G_reg                                                0xb8019664
#define ADC_GAIN_G_inst_addr                                          "0x0199"
#define ADC_GAIN_G_inst                                               0x0199
#define ADC_GAIN_G_gain_g_shift                                       (0)
#define ADC_GAIN_G_gain_g_mask                                        (0x000003FF)
#define ADC_GAIN_G_gain_g(data)                                       (0x000003FF&(data))
#define ADC_GAIN_G_get_gain_g(data)                                   (0x000003FF&(data))


#define ADC_GAIN_B                                                    0x18019668
#define ADC_GAIN_B_reg_addr                                           "0xb8019668"
#define ADC_GAIN_B_reg                                                0xb8019668
#define ADC_GAIN_B_inst_addr                                          "0x019A"
#define ADC_GAIN_B_inst                                               0x019A
#define ADC_GAIN_B_gain_b_shift                                       (0)
#define ADC_GAIN_B_gain_b_mask                                        (0x000003FF)
#define ADC_GAIN_B_gain_b(data)                                       (0x000003FF&(data))
#define ADC_GAIN_B_get_gain_b(data)                                   (0x000003FF&(data))


#define ADC_OFFSET_R                                                  0x1801966c
#define ADC_OFFSET_R_reg_addr                                         "0xb801966c"
#define ADC_OFFSET_R_reg                                              0xb801966c
#define ADC_OFFSET_R_inst_addr                                        "0x019B"
#define ADC_OFFSET_R_inst                                             0x019B
#define ADC_OFFSET_R_offset_r_shift                                   (0)
#define ADC_OFFSET_R_offset_r_mask                                    (0x000000FF)
#define ADC_OFFSET_R_offset_r(data)                                   (0x000000FF&(data))
#define ADC_OFFSET_R_get_offset_r(data)                               (0x000000FF&(data))


#define ADC_OFFSET_G                                                  0x18019670
#define ADC_OFFSET_G_reg_addr                                         "0xb8019670"
#define ADC_OFFSET_G_reg                                              0xb8019670
#define ADC_OFFSET_G_inst_addr                                        "0x019C"
#define ADC_OFFSET_G_inst                                             0x019C
#define ADC_OFFSET_G_offset_g_shift                                   (0)
#define ADC_OFFSET_G_offset_g_mask                                    (0x000000FF)
#define ADC_OFFSET_G_offset_g(data)                                   (0x000000FF&(data))
#define ADC_OFFSET_G_get_offset_g(data)                               (0x000000FF&(data))


#define ADC_OFFSET_B                                                  0x18019674
#define ADC_OFFSET_B_reg_addr                                         "0xb8019674"
#define ADC_OFFSET_B_reg                                              0xb8019674
#define ADC_OFFSET_B_inst_addr                                        "0x019D"
#define ADC_OFFSET_B_inst                                             0x019D
#define ADC_OFFSET_B_offset_b_shift                                   (0)
#define ADC_OFFSET_B_offset_b_mask                                    (0x000000FF)
#define ADC_OFFSET_B_offset_b(data)                                   (0x000000FF&(data))
#define ADC_OFFSET_B_get_offset_b(data)                               (0x000000FF&(data))


#define CLAMP_TEST_REG0                                               0x18019680
#define CLAMP_TEST_REG0_reg_addr                                      "0xb8019680"
#define CLAMP_TEST_REG0_reg                                           0xb8019680
#define CLAMP_TEST_REG0_inst_addr                                     "0x01A0"
#define CLAMP_TEST_REG0_inst                                          0x01A0
#define CLAMP_TEST_REG0_r_prblevel_shift                              (0)
#define CLAMP_TEST_REG0_r_prblevel_mask                               (0x00000FFF)
#define CLAMP_TEST_REG0_r_prblevel(data)                              (0x00000FFF&(data))
#define CLAMP_TEST_REG0_get_r_prblevel(data)                          (0x00000FFF&(data))


#define CLAMP_TEST_REG2                                               0x18019684
#define CLAMP_TEST_REG2_reg_addr                                      "0xb8019684"
#define CLAMP_TEST_REG2_reg                                           0xb8019684
#define CLAMP_TEST_REG2_inst_addr                                     "0x01A1"
#define CLAMP_TEST_REG2_inst                                          0x01A1
#define CLAMP_TEST_REG2_g_blevel_shift                                (0)
#define CLAMP_TEST_REG2_g_blevel_mask                                 (0x00000FFF)
#define CLAMP_TEST_REG2_g_blevel(data)                                (0x00000FFF&(data))
#define CLAMP_TEST_REG2_get_g_blevel(data)                            (0x00000FFF&(data))


#define CLAMP_TEST_REG4                                               0x18019688
#define CLAMP_TEST_REG4_reg_addr                                      "0xb8019688"
#define CLAMP_TEST_REG4_reg                                           0xb8019688
#define CLAMP_TEST_REG4_inst_addr                                     "0x01A2"
#define CLAMP_TEST_REG4_inst                                          0x01A2
#define CLAMP_TEST_REG4_b_pbblevel_shift                              (0)
#define CLAMP_TEST_REG4_b_pbblevel_mask                               (0x00000FFF)
#define CLAMP_TEST_REG4_b_pbblevel(data)                              (0x00000FFF&(data))
#define CLAMP_TEST_REG4_get_b_pbblevel(data)                          (0x00000FFF&(data))


#define CLAMP_TEST_REG6                                               0x1801968c
#define CLAMP_TEST_REG6_reg_addr                                      "0xb801968c"
#define CLAMP_TEST_REG6_reg                                           0xb801968c
#define CLAMP_TEST_REG6_inst_addr                                     "0x01A3"
#define CLAMP_TEST_REG6_inst                                          0x01A3
#define CLAMP_TEST_REG6_comp_blevel_shift                             (0)
#define CLAMP_TEST_REG6_comp_blevel_mask                              (0x00000FFF)
#define CLAMP_TEST_REG6_comp_blevel(data)                             (0x00000FFF&(data))
#define CLAMP_TEST_REG6_get_comp_blevel(data)                         (0x00000FFF&(data))


#define CLAMP_TEST_REG8                                               0x18019690
#define CLAMP_TEST_REG8_reg_addr                                      "0xb8019690"
#define CLAMP_TEST_REG8_reg                                           0xb8019690
#define CLAMP_TEST_REG8_inst_addr                                     "0x01A4"
#define CLAMP_TEST_REG8_inst                                          0x01A4
#define CLAMP_TEST_REG8_comp_slevel_shift                             (0)
#define CLAMP_TEST_REG8_comp_slevel_mask                              (0x00000FFF)
#define CLAMP_TEST_REG8_comp_slevel(data)                             (0x00000FFF&(data))
#define CLAMP_TEST_REG8_get_comp_slevel(data)                         (0x00000FFF&(data))


#define CLAMP_TEST_REG11                                              0x18019694
#define CLAMP_TEST_REG11_reg_addr                                     "0xb8019694"
#define CLAMP_TEST_REG11_reg                                          0xb8019694
#define CLAMP_TEST_REG11_inst_addr                                    "0x01A5"
#define CLAMP_TEST_REG11_inst                                         0x01A5
#define CLAMP_TEST_REG11_vbi_blevel_shift                             (0)
#define CLAMP_TEST_REG11_vbi_blevel_mask                              (0x00000FFF)
#define CLAMP_TEST_REG11_vbi_blevel(data)                             (0x00000FFF&(data))
#define CLAMP_TEST_REG11_get_vbi_blevel(data)                         (0x00000FFF&(data))


#define HDETECT_PHASE_ERR_STATUS2                                     0x18019698
#define HDETECT_PHASE_ERR_STATUS2_reg_addr                            "0xb8019698"
#define HDETECT_PHASE_ERR_STATUS2_reg                                 0xb8019698
#define HDETECT_PHASE_ERR_STATUS2_inst_addr                           "0x01A6"
#define HDETECT_PHASE_ERR_STATUS2_inst                                0x01A6
#define HDETECT_PHASE_ERR_STATUS2_hphase_err_status_shift             (0)
#define HDETECT_PHASE_ERR_STATUS2_hphase_err_status_mask              (0x00003FFF)
#define HDETECT_PHASE_ERR_STATUS2_hphase_err_status(data)             (0x00003FFF&(data))
#define HDETECT_PHASE_ERR_STATUS2_get_hphase_err_status(data)         (0x00003FFF&(data))


#define AVOUT_FIFO_RD_PTR                                             0x1801969c
#define AVOUT_FIFO_RD_PTR_reg_addr                                    "0xb801969c"
#define AVOUT_FIFO_RD_PTR_reg                                         0xb801969c
#define AVOUT_FIFO_RD_PTR_inst_addr                                   "0x01A7"
#define AVOUT_FIFO_RD_PTR_inst                                        0x01A7
#define AVOUT_FIFO_RD_PTR_avout_fifo_sel_shift                        (11)
#define AVOUT_FIFO_RD_PTR_avout_fifo_rd_ptr_shift                     (0)
#define AVOUT_FIFO_RD_PTR_avout_fifo_sel_mask                         (0x00000800)
#define AVOUT_FIFO_RD_PTR_avout_fifo_rd_ptr_mask                      (0x000007FF)
#define AVOUT_FIFO_RD_PTR_avout_fifo_sel(data)                        (0x00000800&((data)<<11))
#define AVOUT_FIFO_RD_PTR_avout_fifo_rd_ptr(data)                     (0x000007FF&(data))
#define AVOUT_FIFO_RD_PTR_get_avout_fifo_sel(data)                    ((0x00000800&(data))>>11)
#define AVOUT_FIFO_RD_PTR_get_avout_fifo_rd_ptr(data)                 (0x000007FF&(data))


#define BLANK_LEVEL_MANU_COMP_VALUE                                   0x180196a0
#define BLANK_LEVEL_MANU_COMP_VALUE_reg_addr                          "0xb80196a0"
#define BLANK_LEVEL_MANU_COMP_VALUE_reg                               0xb80196a0
#define BLANK_LEVEL_MANU_COMP_VALUE_inst_addr                         "0x01A8"
#define BLANK_LEVEL_MANU_COMP_VALUE_inst                              0x01A8
#define BLANK_LEVEL_MANU_COMP_VALUE_blank_level_comp_manu_add_shift   (16)
#define BLANK_LEVEL_MANU_COMP_VALUE_blank_level_comp_manu_shift       (0)
#define BLANK_LEVEL_MANU_COMP_VALUE_blank_level_comp_manu_add_mask    (0x0FFF0000)
#define BLANK_LEVEL_MANU_COMP_VALUE_blank_level_comp_manu_mask        (0x00000FFF)
#define BLANK_LEVEL_MANU_COMP_VALUE_blank_level_comp_manu_add(data)   (0x0FFF0000&((data)<<16))
#define BLANK_LEVEL_MANU_COMP_VALUE_blank_level_comp_manu(data)       (0x00000FFF&(data))
#define BLANK_LEVEL_MANU_COMP_VALUE_get_blank_level_comp_manu_add(data)  ((0x0FFF0000&(data))>>16)
#define BLANK_LEVEL_MANU_COMP_VALUE_get_blank_level_comp_manu(data)   (0x00000FFF&(data))


#define BLANK_LEVEL_MANU_C_R_VALUE                                    0x180196a4
#define BLANK_LEVEL_MANU_C_R_VALUE_reg_addr                           "0xb80196a4"
#define BLANK_LEVEL_MANU_C_R_VALUE_reg                                0xb80196a4
#define BLANK_LEVEL_MANU_C_R_VALUE_inst_addr                          "0x01A9"
#define BLANK_LEVEL_MANU_C_R_VALUE_inst                               0x01A9
#define BLANK_LEVEL_MANU_C_R_VALUE_blank_level_c_manu_shift           (16)
#define BLANK_LEVEL_MANU_C_R_VALUE_blank_level_r_manu_shift           (0)
#define BLANK_LEVEL_MANU_C_R_VALUE_blank_level_c_manu_mask            (0x0FFF0000)
#define BLANK_LEVEL_MANU_C_R_VALUE_blank_level_r_manu_mask            (0x00000FFF)
#define BLANK_LEVEL_MANU_C_R_VALUE_blank_level_c_manu(data)           (0x0FFF0000&((data)<<16))
#define BLANK_LEVEL_MANU_C_R_VALUE_blank_level_r_manu(data)           (0x00000FFF&(data))
#define BLANK_LEVEL_MANU_C_R_VALUE_get_blank_level_c_manu(data)       ((0x0FFF0000&(data))>>16)
#define BLANK_LEVEL_MANU_C_R_VALUE_get_blank_level_r_manu(data)       (0x00000FFF&(data))


#define BLANK_LEVEL_MANU_G_B_VALUE                                    0x180196a8
#define BLANK_LEVEL_MANU_G_B_VALUE_reg_addr                           "0xb80196a8"
#define BLANK_LEVEL_MANU_G_B_VALUE_reg                                0xb80196a8
#define BLANK_LEVEL_MANU_G_B_VALUE_inst_addr                          "0x01AA"
#define BLANK_LEVEL_MANU_G_B_VALUE_inst                               0x01AA
#define BLANK_LEVEL_MANU_G_B_VALUE_blank_level_g_manu_shift           (16)
#define BLANK_LEVEL_MANU_G_B_VALUE_blank_level_b_manu_shift           (0)
#define BLANK_LEVEL_MANU_G_B_VALUE_blank_level_g_manu_mask            (0x0FFF0000)
#define BLANK_LEVEL_MANU_G_B_VALUE_blank_level_b_manu_mask            (0x00000FFF)
#define BLANK_LEVEL_MANU_G_B_VALUE_blank_level_g_manu(data)           (0x0FFF0000&((data)<<16))
#define BLANK_LEVEL_MANU_G_B_VALUE_blank_level_b_manu(data)           (0x00000FFF&(data))
#define BLANK_LEVEL_MANU_G_B_VALUE_get_blank_level_g_manu(data)       ((0x0FFF0000&(data))>>16)
#define BLANK_LEVEL_MANU_G_B_VALUE_get_blank_level_b_manu(data)       (0x00000FFF&(data))


#define FPGA_TEST_REG1                                                0x180196b0
#define FPGA_TEST_REG1_reg_addr                                       "0xb80196b0"
#define FPGA_TEST_REG1_reg                                            0xb80196b0
#define FPGA_TEST_REG1_inst_addr                                      "0x01AC"
#define FPGA_TEST_REG1_inst                                           0x01AC
#define FPGA_TEST_REG1_fpga_test1_shift                               (1)
#define FPGA_TEST_REG1_factory_flag_shift                             (0)
#define FPGA_TEST_REG1_fpga_test1_mask                                (0xFFFFFFFE)
#define FPGA_TEST_REG1_factory_flag_mask                              (0x00000001)
#define FPGA_TEST_REG1_fpga_test1(data)                               (0xFFFFFFFE&((data)<<1))
#define FPGA_TEST_REG1_factory_flag(data)                             (0x00000001&(data))
#define FPGA_TEST_REG1_get_fpga_test1(data)                           ((0xFFFFFFFE&(data))>>1)
#define FPGA_TEST_REG1_get_factory_flag(data)                         (0x00000001&(data))


#define FPGA_TEST_REG2                                                0x180196b4
#define FPGA_TEST_REG2_reg_addr                                       "0xb80196b4"
#define FPGA_TEST_REG2_reg                                            0xb80196b4
#define FPGA_TEST_REG2_inst_addr                                      "0x01AD"
#define FPGA_TEST_REG2_inst                                           0x01AD
#define FPGA_TEST_REG2_fpga_test2_shift                               (0)
#define FPGA_TEST_REG2_fpga_test2_mask                                (0xFFFFFFFF)
#define FPGA_TEST_REG2_fpga_test2(data)                               (0xFFFFFFFF&(data))
#define FPGA_TEST_REG2_get_fpga_test2(data)                           (0xFFFFFFFF&(data))


#define FPGA_TEST_REG3                                                0x180196b8
#define FPGA_TEST_REG3_reg_addr                                       "0xb80196b8"
#define FPGA_TEST_REG3_reg                                            0xb80196b8
#define FPGA_TEST_REG3_inst_addr                                      "0x01AE"
#define FPGA_TEST_REG3_inst                                           0x01AE
#define FPGA_TEST_REG3_fpga_test3_shift                               (0)
#define FPGA_TEST_REG3_fpga_test3_mask                                (0xFFFFFFFF)
#define FPGA_TEST_REG3_fpga_test3(data)                               (0xFFFFFFFF&(data))
#define FPGA_TEST_REG3_get_fpga_test3(data)                           (0xFFFFFFFF&(data))


#define FPGA_TEST_REG4                                                0x180196bc
#define FPGA_TEST_REG4_reg_addr                                       "0xb80196bc"
#define FPGA_TEST_REG4_reg                                            0xb80196bc
#define FPGA_TEST_REG4_inst_addr                                      "0x01AF"
#define FPGA_TEST_REG4_inst                                           0x01AF
#define FPGA_TEST_REG4_fpga_test4_shift                               (0)
#define FPGA_TEST_REG4_fpga_test4_mask                                (0xFFFFFFFF)
#define FPGA_TEST_REG4_fpga_test4(data)                               (0xFFFFFFFF&(data))
#define FPGA_TEST_REG4_get_fpga_test4(data)                           (0xFFFFFFFF&(data))


#define FPGA_TEST_REG5                                                0x180196c0
#define FPGA_TEST_REG5_reg_addr                                       "0xb80196c0"
#define FPGA_TEST_REG5_reg                                            0xb80196c0
#define FPGA_TEST_REG5_inst_addr                                      "0x01B0"
#define FPGA_TEST_REG5_inst                                           0x01B0
#define FPGA_TEST_REG5_fpga_test5_shift                               (0)
#define FPGA_TEST_REG5_fpga_test5_mask                                (0xFFFFFFFF)
#define FPGA_TEST_REG5_fpga_test5(data)                               (0xFFFFFFFF&(data))
#define FPGA_TEST_REG5_get_fpga_test5(data)                           (0xFFFFFFFF&(data))


#define FPGA_TEST_REG6                                                0x180196c4
#define FPGA_TEST_REG6_reg_addr                                       "0xb80196c4"
#define FPGA_TEST_REG6_reg                                            0xb80196c4
#define FPGA_TEST_REG6_inst_addr                                      "0x01B1"
#define FPGA_TEST_REG6_inst                                           0x01B1
#define FPGA_TEST_REG6_fpga_test6_shift                               (0)
#define FPGA_TEST_REG6_fpga_test6_mask                                (0xFFFFFFFF)
#define FPGA_TEST_REG6_fpga_test6(data)                               (0xFFFFFFFF&(data))
#define FPGA_TEST_REG6_get_fpga_test6(data)                           (0xFFFFFFFF&(data))


#define FPGA_TEST_REG7                                                0x180196c8
#define FPGA_TEST_REG7_reg_addr                                       "0xb80196c8"
#define FPGA_TEST_REG7_reg                                            0xb80196c8
#define FPGA_TEST_REG7_inst_addr                                      "0x01B2"
#define FPGA_TEST_REG7_inst                                           0x01B2
#define FPGA_TEST_REG7_fpga_test7_shift                               (0)
#define FPGA_TEST_REG7_fpga_test7_mask                                (0xFFFFFFFF)
#define FPGA_TEST_REG7_fpga_test7(data)                               (0xFFFFFFFF&(data))
#define FPGA_TEST_REG7_get_fpga_test7(data)                           (0xFFFFFFFF&(data))


#define FPGA_TEST_REG8                                                0x180196cc
#define FPGA_TEST_REG8_reg_addr                                       "0xb80196cc"
#define FPGA_TEST_REG8_reg                                            0xb80196cc
#define FPGA_TEST_REG8_inst_addr                                      "0x01B3"
#define FPGA_TEST_REG8_inst                                           0x01B3
#define FPGA_TEST_REG8_fpga_test8_shift                               (0)
#define FPGA_TEST_REG8_fpga_test8_mask                                (0xFFFFFFFF)
#define FPGA_TEST_REG8_fpga_test8(data)                               (0xFFFFFFFF&(data))
#define FPGA_TEST_REG8_get_fpga_test8(data)                           (0xFFFFFFFF&(data))


#define SECAM_CTRL                                                    0x18019700
#define SECAM_CTRL_reg_addr                                           "0xb8019700"
#define SECAM_CTRL_reg                                                0xb8019700
#define SECAM_CTRL_inst_addr                                          "0x01C0"
#define SECAM_CTRL_inst                                               0x01C0
#define SECAM_CTRL_secam_y_fir_en_shift                               (16)
#define SECAM_CTRL_secam_y_hpf_sel_shift                              (12)
#define SECAM_CTRL_secam_y_lpf_sel_shift                              (8)
#define SECAM_CTRL_drdb_freq_const_shift                              (7)
#define SECAM_CTRL_drdb_vlpf_en_shift                                 (6)
#define SECAM_CTRL_secam_flag_sel_shift                               (4)
#define SECAM_CTRL_secam_notch_filter_shift                           (0)
#define SECAM_CTRL_secam_y_fir_en_mask                                (0x00010000)
#define SECAM_CTRL_secam_y_hpf_sel_mask                               (0x00007000)
#define SECAM_CTRL_secam_y_lpf_sel_mask                               (0x00000700)
#define SECAM_CTRL_drdb_freq_const_mask                               (0x00000080)
#define SECAM_CTRL_drdb_vlpf_en_mask                                  (0x00000040)
#define SECAM_CTRL_secam_flag_sel_mask                                (0x00000010)
#define SECAM_CTRL_secam_notch_filter_mask                            (0x00000003)
#define SECAM_CTRL_secam_y_fir_en(data)                               (0x00010000&((data)<<16))
#define SECAM_CTRL_secam_y_hpf_sel(data)                              (0x00007000&((data)<<12))
#define SECAM_CTRL_secam_y_lpf_sel(data)                              (0x00000700&((data)<<8))
#define SECAM_CTRL_drdb_freq_const(data)                              (0x00000080&((data)<<7))
#define SECAM_CTRL_drdb_vlpf_en(data)                                 (0x00000040&((data)<<6))
#define SECAM_CTRL_secam_flag_sel(data)                               (0x00000010&((data)<<4))
#define SECAM_CTRL_secam_notch_filter(data)                           (0x00000003&(data))
#define SECAM_CTRL_get_secam_y_fir_en(data)                           ((0x00010000&(data))>>16)
#define SECAM_CTRL_get_secam_y_hpf_sel(data)                          ((0x00007000&(data))>>12)
#define SECAM_CTRL_get_secam_y_lpf_sel(data)                          ((0x00000700&(data))>>8)
#define SECAM_CTRL_get_drdb_freq_const(data)                          ((0x00000080&(data))>>7)
#define SECAM_CTRL_get_drdb_vlpf_en(data)                             ((0x00000040&(data))>>6)
#define SECAM_CTRL_get_secam_flag_sel(data)                           ((0x00000010&(data))>>4)
#define SECAM_CTRL_get_secam_notch_filter(data)                       (0x00000003&(data))


#define SECAM_DRFREQ_OFFSET                                           0x18019704
#define SECAM_DRFREQ_OFFSET_reg_addr                                  "0xb8019704"
#define SECAM_DRFREQ_OFFSET_reg                                       0xb8019704
#define SECAM_DRFREQ_OFFSET_inst_addr                                 "0x01C1"
#define SECAM_DRFREQ_OFFSET_inst                                      0x01C1
#define SECAM_DRFREQ_OFFSET_dr_offset_shift                           (0)
#define SECAM_DRFREQ_OFFSET_dr_offset_mask                            (0x000000FF)
#define SECAM_DRFREQ_OFFSET_dr_offset(data)                           (0x000000FF&(data))
#define SECAM_DRFREQ_OFFSET_get_dr_offset(data)                       (0x000000FF&(data))


#define SECAM_DBFREQ_OFFSET                                           0x18019708
#define SECAM_DBFREQ_OFFSET_reg_addr                                  "0xb8019708"
#define SECAM_DBFREQ_OFFSET_reg                                       0xb8019708
#define SECAM_DBFREQ_OFFSET_inst_addr                                 "0x01C2"
#define SECAM_DBFREQ_OFFSET_inst                                      0x01C2
#define SECAM_DBFREQ_OFFSET_db_offset_shift                           (0)
#define SECAM_DBFREQ_OFFSET_db_offset_mask                            (0x000000FF)
#define SECAM_DBFREQ_OFFSET_db_offset(data)                           (0x000000FF&(data))
#define SECAM_DBFREQ_OFFSET_get_db_offset(data)                       (0x000000FF&(data))


#define SECAM_HCOUNT_RESET_CTRL                                       0x1801970c
#define SECAM_HCOUNT_RESET_CTRL_reg_addr                              "0xb801970c"
#define SECAM_HCOUNT_RESET_CTRL_reg                                   0xb801970c
#define SECAM_HCOUNT_RESET_CTRL_inst_addr                             "0x01C3"
#define SECAM_HCOUNT_RESET_CTRL_inst                                  0x01C3
#define SECAM_HCOUNT_RESET_CTRL_secam_phase_diff_hcount_en_shift      (7)
#define SECAM_HCOUNT_RESET_CTRL_secam_phase_diff_hcount_shift         (0)
#define SECAM_HCOUNT_RESET_CTRL_secam_phase_diff_hcount_en_mask       (0x00000080)
#define SECAM_HCOUNT_RESET_CTRL_secam_phase_diff_hcount_mask          (0x0000007F)
#define SECAM_HCOUNT_RESET_CTRL_secam_phase_diff_hcount_en(data)      (0x00000080&((data)<<7))
#define SECAM_HCOUNT_RESET_CTRL_secam_phase_diff_hcount(data)         (0x0000007F&(data))
#define SECAM_HCOUNT_RESET_CTRL_get_secam_phase_diff_hcount_en(data)  ((0x00000080&(data))>>7)
#define SECAM_HCOUNT_RESET_CTRL_get_secam_phase_diff_hcount(data)     (0x0000007F&(data))


#define PHASE_DIFF_DR_RST                                             0x18019710
#define PHASE_DIFF_DR_RST_reg_addr                                    "0xb8019710"
#define PHASE_DIFF_DR_RST_reg                                         0xb8019710
#define PHASE_DIFF_DR_RST_inst_addr                                   "0x01C4"
#define PHASE_DIFF_DR_RST_inst                                        0x01C4
#define PHASE_DIFF_DR_RST_secam_phase_diff_dr_shift                   (0)
#define PHASE_DIFF_DR_RST_secam_phase_diff_dr_mask                    (0x000000FF)
#define PHASE_DIFF_DR_RST_secam_phase_diff_dr(data)                   (0x000000FF&(data))
#define PHASE_DIFF_DR_RST_get_secam_phase_diff_dr(data)               (0x000000FF&(data))


#define PHASE_DIFF_DB_RST                                             0x18019714
#define PHASE_DIFF_DB_RST_reg_addr                                    "0xb8019714"
#define PHASE_DIFF_DB_RST_reg                                         0xb8019714
#define PHASE_DIFF_DB_RST_inst_addr                                   "0x01C5"
#define PHASE_DIFF_DB_RST_inst                                        0x01C5
#define PHASE_DIFF_DB_RST_secam_phase_diff_db_shift                   (0)
#define PHASE_DIFF_DB_RST_secam_phase_diff_db_mask                    (0x000000FF)
#define PHASE_DIFF_DB_RST_secam_phase_diff_db(data)                   (0x000000FF&(data))
#define PHASE_DIFF_DB_RST_get_secam_phase_diff_db(data)               (0x000000FF&(data))


#define DRDB_GAIN_TABLE_CTRL                                          0x18019718
#define DRDB_GAIN_TABLE_CTRL_reg_addr                                 "0xb8019718"
#define DRDB_GAIN_TABLE_CTRL_reg                                      0xb8019718
#define DRDB_GAIN_TABLE_CTRL_inst_addr                                "0x01C6"
#define DRDB_GAIN_TABLE_CTRL_inst                                     0x01C6
#define DRDB_GAIN_TABLE_CTRL_secam_gain_drdb_en_shift                 (7)
#define DRDB_GAIN_TABLE_CTRL_secam_gain_drdb_shift                    (0)
#define DRDB_GAIN_TABLE_CTRL_secam_gain_drdb_en_mask                  (0x00000080)
#define DRDB_GAIN_TABLE_CTRL_secam_gain_drdb_mask                     (0x0000007F)
#define DRDB_GAIN_TABLE_CTRL_secam_gain_drdb_en(data)                 (0x00000080&((data)<<7))
#define DRDB_GAIN_TABLE_CTRL_secam_gain_drdb(data)                    (0x0000007F&(data))
#define DRDB_GAIN_TABLE_CTRL_get_secam_gain_drdb_en(data)             ((0x00000080&(data))>>7)
#define DRDB_GAIN_TABLE_CTRL_get_secam_gain_drdb(data)                (0x0000007F&(data))


#define Y_GAIN_TABLE_CTRL                                             0x1801971c
#define Y_GAIN_TABLE_CTRL_reg_addr                                    "0xb801971c"
#define Y_GAIN_TABLE_CTRL_reg                                         0xb801971c
#define Y_GAIN_TABLE_CTRL_inst_addr                                   "0x01C7"
#define Y_GAIN_TABLE_CTRL_inst                                        0x01C7
#define Y_GAIN_TABLE_CTRL_secam_gain_y_en_shift                       (7)
#define Y_GAIN_TABLE_CTRL_secam_gain_y_shift                          (0)
#define Y_GAIN_TABLE_CTRL_secam_gain_y_en_mask                        (0x00000080)
#define Y_GAIN_TABLE_CTRL_secam_gain_y_mask                           (0x0000007F)
#define Y_GAIN_TABLE_CTRL_secam_gain_y_en(data)                       (0x00000080&((data)<<7))
#define Y_GAIN_TABLE_CTRL_secam_gain_y(data)                          (0x0000007F&(data))
#define Y_GAIN_TABLE_CTRL_get_secam_gain_y_en(data)                   ((0x00000080&(data))>>7)
#define Y_GAIN_TABLE_CTRL_get_secam_gain_y(data)                      (0x0000007F&(data))


#define SECAM_GAIN_DLY                                                0x18019720
#define SECAM_GAIN_DLY_reg_addr                                       "0xb8019720"
#define SECAM_GAIN_DLY_reg                                            0xb8019720
#define SECAM_GAIN_DLY_inst_addr                                      "0x01C8"
#define SECAM_GAIN_DLY_inst                                           0x01C8
#define SECAM_GAIN_DLY_secam_gain_delay_shift                         (0)
#define SECAM_GAIN_DLY_secam_gain_delay_mask                          (0x0000001F)
#define SECAM_GAIN_DLY_secam_gain_delay(data)                         (0x0000001F&(data))
#define SECAM_GAIN_DLY_get_secam_gain_delay(data)                     (0x0000001F&(data))


#define SECAM_GAIN_TABLE_DEBUG                                        0x18019724
#define SECAM_GAIN_TABLE_DEBUG_reg_addr                               "0xb8019724"
#define SECAM_GAIN_TABLE_DEBUG_reg                                    0xb8019724
#define SECAM_GAIN_TABLE_DEBUG_inst_addr                              "0x01C9"
#define SECAM_GAIN_TABLE_DEBUG_inst                                   0x01C9
#define SECAM_GAIN_TABLE_DEBUG_secam_gain_debug_en_shift              (7)
#define SECAM_GAIN_TABLE_DEBUG_secam_gain_debug_shift                 (0)
#define SECAM_GAIN_TABLE_DEBUG_secam_gain_debug_en_mask               (0x00000080)
#define SECAM_GAIN_TABLE_DEBUG_secam_gain_debug_mask                  (0x0000007F)
#define SECAM_GAIN_TABLE_DEBUG_secam_gain_debug_en(data)              (0x00000080&((data)<<7))
#define SECAM_GAIN_TABLE_DEBUG_secam_gain_debug(data)                 (0x0000007F&(data))
#define SECAM_GAIN_TABLE_DEBUG_get_secam_gain_debug_en(data)          ((0x00000080&(data))>>7)
#define SECAM_GAIN_TABLE_DEBUG_get_secam_gain_debug(data)             (0x0000007F&(data))


#define SECAM_YADAP_MODE                                              0x18019728
#define SECAM_YADAP_MODE_reg_addr                                     "0xb8019728"
#define SECAM_YADAP_MODE_reg                                          0xb8019728
#define SECAM_YADAP_MODE_inst_addr                                    "0x01CA"
#define SECAM_YADAP_MODE_inst                                         0x01CA
#define SECAM_YADAP_MODE_yadap_hpf_sel_shift                          (2)
#define SECAM_YADAP_MODE_yadap_peak_mode_shift                        (0)
#define SECAM_YADAP_MODE_yadap_hpf_sel_mask                           (0x0000000C)
#define SECAM_YADAP_MODE_yadap_peak_mode_mask                         (0x00000003)
#define SECAM_YADAP_MODE_yadap_hpf_sel(data)                          (0x0000000C&((data)<<2))
#define SECAM_YADAP_MODE_yadap_peak_mode(data)                        (0x00000003&(data))
#define SECAM_YADAP_MODE_get_yadap_hpf_sel(data)                      ((0x0000000C&(data))>>2)
#define SECAM_YADAP_MODE_get_yadap_peak_mode(data)                    (0x00000003&(data))


#define SECAM_YADAP_CTRL1                                             0x1801972c
#define SECAM_YADAP_CTRL1_reg_addr                                    "0xb801972c"
#define SECAM_YADAP_CTRL1_reg                                         0xb801972c
#define SECAM_YADAP_CTRL1_inst_addr                                   "0x01CB"
#define SECAM_YADAP_CTRL1_inst                                        0x01CB
#define SECAM_YADAP_CTRL1_yadap_peak_gain_shift                       (4)
#define SECAM_YADAP_CTRL1_yadap_peak_th_shift                         (0)
#define SECAM_YADAP_CTRL1_yadap_peak_gain_mask                        (0x000000F0)
#define SECAM_YADAP_CTRL1_yadap_peak_th_mask                          (0x0000000F)
#define SECAM_YADAP_CTRL1_yadap_peak_gain(data)                       (0x000000F0&((data)<<4))
#define SECAM_YADAP_CTRL1_yadap_peak_th(data)                         (0x0000000F&(data))
#define SECAM_YADAP_CTRL1_get_yadap_peak_gain(data)                   ((0x000000F0&(data))>>4)
#define SECAM_YADAP_CTRL1_get_yadap_peak_th(data)                     (0x0000000F&(data))


#define SECAM_YADAP_CTRL2                                             0x18019730
#define SECAM_YADAP_CTRL2_reg_addr                                    "0xb8019730"
#define SECAM_YADAP_CTRL2_reg                                         0xb8019730
#define SECAM_YADAP_CTRL2_inst_addr                                   "0x01CC"
#define SECAM_YADAP_CTRL2_inst                                        0x01CC
#define SECAM_YADAP_CTRL2_yadap_peak_gain_2d_shift                    (4)
#define SECAM_YADAP_CTRL2_yadap_uniform_gain_shift                    (0)
#define SECAM_YADAP_CTRL2_yadap_peak_gain_2d_mask                     (0x000000F0)
#define SECAM_YADAP_CTRL2_yadap_uniform_gain_mask                     (0x0000000F)
#define SECAM_YADAP_CTRL2_yadap_peak_gain_2d(data)                    (0x000000F0&((data)<<4))
#define SECAM_YADAP_CTRL2_yadap_uniform_gain(data)                    (0x0000000F&(data))
#define SECAM_YADAP_CTRL2_get_yadap_peak_gain_2d(data)                ((0x000000F0&(data))>>4)
#define SECAM_YADAP_CTRL2_get_yadap_uniform_gain(data)                (0x0000000F&(data))


#define NEW_SECAM_HCOUNT_RESET_CTRL                                   0x18019734
#define NEW_SECAM_HCOUNT_RESET_CTRL_reg_addr                          "0xb8019734"
#define NEW_SECAM_HCOUNT_RESET_CTRL_reg                               0xb8019734
#define NEW_SECAM_HCOUNT_RESET_CTRL_inst_addr                         "0x01CD"
#define NEW_SECAM_HCOUNT_RESET_CTRL_inst                              0x01CD
#define NEW_SECAM_HCOUNT_RESET_CTRL_new_secam_phase_diff_hcount_en_shift  (7)
#define NEW_SECAM_HCOUNT_RESET_CTRL_new_secam_phase_diff_hcount_shift (0)
#define NEW_SECAM_HCOUNT_RESET_CTRL_new_secam_phase_diff_hcount_en_mask  (0x00000080)
#define NEW_SECAM_HCOUNT_RESET_CTRL_new_secam_phase_diff_hcount_mask  (0x0000007F)
#define NEW_SECAM_HCOUNT_RESET_CTRL_new_secam_phase_diff_hcount_en(data)  (0x00000080&((data)<<7))
#define NEW_SECAM_HCOUNT_RESET_CTRL_new_secam_phase_diff_hcount(data) (0x0000007F&(data))
#define NEW_SECAM_HCOUNT_RESET_CTRL_get_new_secam_phase_diff_hcount_en(data)  ((0x00000080&(data))>>7)
#define NEW_SECAM_HCOUNT_RESET_CTRL_get_new_secam_phase_diff_hcount(data)  (0x0000007F&(data))


#define NEW_SECAM_PHASE_DIFF_DR                                       0x18019738
#define NEW_SECAM_PHASE_DIFF_DR_reg_addr                              "0xb8019738"
#define NEW_SECAM_PHASE_DIFF_DR_reg                                   0xb8019738
#define NEW_SECAM_PHASE_DIFF_DR_inst_addr                             "0x01CE"
#define NEW_SECAM_PHASE_DIFF_DR_inst                                  0x01CE
#define NEW_SECAM_PHASE_DIFF_DR_new_secam_phase_diff_dr_shift         (0)
#define NEW_SECAM_PHASE_DIFF_DR_new_secam_phase_diff_dr_mask          (0x000000FF)
#define NEW_SECAM_PHASE_DIFF_DR_new_secam_phase_diff_dr(data)         (0x000000FF&(data))
#define NEW_SECAM_PHASE_DIFF_DR_get_new_secam_phase_diff_dr(data)     (0x000000FF&(data))


#define NEW_SECAM_PHASE_DIFF_DB                                       0x1801973c
#define NEW_SECAM_PHASE_DIFF_DB_reg_addr                              "0xb801973c"
#define NEW_SECAM_PHASE_DIFF_DB_reg                                   0xb801973c
#define NEW_SECAM_PHASE_DIFF_DB_inst_addr                             "0x01CF"
#define NEW_SECAM_PHASE_DIFF_DB_inst                                  0x01CF
#define NEW_SECAM_PHASE_DIFF_DB_new_secam_phase_diff_db_shift         (0)
#define NEW_SECAM_PHASE_DIFF_DB_new_secam_phase_diff_db_mask          (0x000000FF)
#define NEW_SECAM_PHASE_DIFF_DB_new_secam_phase_diff_db(data)         (0x000000FF&(data))
#define NEW_SECAM_PHASE_DIFF_DB_get_new_secam_phase_diff_db(data)     (0x000000FF&(data))


#define NEW_SECAM_CDTO_INC                                            0x18019740
#define NEW_SECAM_CDTO_INC_reg_addr                                   "0xb8019740"
#define NEW_SECAM_CDTO_INC_reg                                        0xb8019740
#define NEW_SECAM_CDTO_INC_inst_addr                                  "0x01D0"
#define NEW_SECAM_CDTO_INC_inst                                       0x01D0
#define NEW_SECAM_CDTO_INC_new_secam_cdto_inc_shift                   (0)
#define NEW_SECAM_CDTO_INC_new_secam_cdto_inc_mask                    (0x3FFFFFFF)
#define NEW_SECAM_CDTO_INC_new_secam_cdto_inc(data)                   (0x3FFFFFFF&(data))
#define NEW_SECAM_CDTO_INC_get_new_secam_cdto_inc(data)               (0x3FFFFFFF&(data))


#define SECAM_GP_RM                                                   0x18019744
#define SECAM_GP_RM_reg_addr                                          "0xb8019744"
#define SECAM_GP_RM_reg                                               0xb8019744
#define SECAM_GP_RM_inst_addr                                         "0x01D1"
#define SECAM_GP_RM_inst                                              0x01D1
#define SECAM_GP_RM_secam_gp_en_shift                                 (31)
#define SECAM_GP_RM_secam_gp_step_shift                               (12)
#define SECAM_GP_RM_secam_gp_thl_shift                                (0)
#define SECAM_GP_RM_secam_gp_en_mask                                  (0x80000000)
#define SECAM_GP_RM_secam_gp_step_mask                                (0x003FF000)
#define SECAM_GP_RM_secam_gp_thl_mask                                 (0x000003FF)
#define SECAM_GP_RM_secam_gp_en(data)                                 (0x80000000&((data)<<31))
#define SECAM_GP_RM_secam_gp_step(data)                               (0x003FF000&((data)<<12))
#define SECAM_GP_RM_secam_gp_thl(data)                                (0x000003FF&(data))
#define SECAM_GP_RM_get_secam_gp_en(data)                             ((0x80000000&(data))>>31)
#define SECAM_GP_RM_get_secam_gp_step(data)                           ((0x003FF000&(data))>>12)
#define SECAM_GP_RM_get_secam_gp_thl(data)                            (0x000003FF&(data))


#define FIFO_CTRL                                                     0x18019758
#define FIFO_CTRL_reg_addr                                            "0xb8019758"
#define FIFO_CTRL_reg                                                 0xb8019758
#define FIFO_CTRL_inst_addr                                           "0x01D6"
#define FIFO_CTRL_inst                                                0x01D6
#define FIFO_CTRL_vdec_ps_disp_27_en_shift                            (31)
#define FIFO_CTRL_hresampler_combi_delay_shift                        (28)
#define FIFO_CTRL_vd_output_135_sel_shift                             (26)
#define FIFO_CTRL_vd_output_27_repeat_sel_shift                       (25)
#define FIFO_CTRL_vd_output_27_repeat_en_shift                        (24)
#define FIFO_CTRL_v8format_sel_shift                                  (7)
#define FIFO_CTRL_ps_updn_swap_shift                                  (2)
#define FIFO_CTRL_fifo_initialization_shift                           (0)
#define FIFO_CTRL_vdec_ps_disp_27_en_mask                             (0x80000000)
#define FIFO_CTRL_hresampler_combi_delay_mask                         (0x70000000)
#define FIFO_CTRL_vd_output_135_sel_mask                              (0x04000000)
#define FIFO_CTRL_vd_output_27_repeat_sel_mask                        (0x02000000)
#define FIFO_CTRL_vd_output_27_repeat_en_mask                         (0x01000000)
#define FIFO_CTRL_v8format_sel_mask                                   (0x00000080)
#define FIFO_CTRL_ps_updn_swap_mask                                   (0x00000004)
#define FIFO_CTRL_fifo_initialization_mask                            (0x00000001)
#define FIFO_CTRL_vdec_ps_disp_27_en(data)                            (0x80000000&((data)<<31))
#define FIFO_CTRL_hresampler_combi_delay(data)                        (0x70000000&((data)<<28))
#define FIFO_CTRL_vd_output_135_sel(data)                             (0x04000000&((data)<<26))
#define FIFO_CTRL_vd_output_27_repeat_sel(data)                       (0x02000000&((data)<<25))
#define FIFO_CTRL_vd_output_27_repeat_en(data)                        (0x01000000&((data)<<24))
#define FIFO_CTRL_v8format_sel(data)                                  (0x00000080&((data)<<7))
#define FIFO_CTRL_ps_updn_swap(data)                                  (0x00000004&((data)<<2))
#define FIFO_CTRL_fifo_initialization(data)                           (0x00000001&(data))
#define FIFO_CTRL_get_vdec_ps_disp_27_en(data)                        ((0x80000000&(data))>>31)
#define FIFO_CTRL_get_hresampler_combi_delay(data)                    ((0x70000000&(data))>>28)
#define FIFO_CTRL_get_vd_output_135_sel(data)                         ((0x04000000&(data))>>26)
#define FIFO_CTRL_get_vd_output_27_repeat_sel(data)                   ((0x02000000&(data))>>25)
#define FIFO_CTRL_get_vd_output_27_repeat_en(data)                    ((0x01000000&(data))>>24)
#define FIFO_CTRL_get_v8format_sel(data)                              ((0x00000080&(data))>>7)
#define FIFO_CTRL_get_ps_updn_swap(data)                              ((0x00000004&(data))>>2)
#define FIFO_CTRL_get_fifo_initialization(data)                       (0x00000001&(data))


#define FIFO_STATUS                                                   0x1801975c
#define FIFO_STATUS_reg_addr                                          "0xb801975c"
#define FIFO_STATUS_reg                                               0xb801975c
#define FIFO_STATUS_inst_addr                                         "0x01D7"
#define FIFO_STATUS_inst                                              0x01D7
#define FIFO_STATUS_ps_540_coe_en_shift                               (24)
#define FIFO_STATUS_ps_540_select_tap_shift                           (16)
#define FIFO_STATUS_ps_540_coe_modify_shift                           (8)
#define FIFO_STATUS_fifo_full_status_shift                            (1)
#define FIFO_STATUS_fifo_empty_status_shift                           (0)
#define FIFO_STATUS_ps_540_coe_en_mask                                (0x01000000)
#define FIFO_STATUS_ps_540_select_tap_mask                            (0x001F0000)
#define FIFO_STATUS_ps_540_coe_modify_mask                            (0x00007F00)
#define FIFO_STATUS_fifo_full_status_mask                             (0x00000002)
#define FIFO_STATUS_fifo_empty_status_mask                            (0x00000001)
#define FIFO_STATUS_ps_540_coe_en(data)                               (0x01000000&((data)<<24))
#define FIFO_STATUS_ps_540_select_tap(data)                           (0x001F0000&((data)<<16))
#define FIFO_STATUS_ps_540_coe_modify(data)                           (0x00007F00&((data)<<8))
#define FIFO_STATUS_fifo_full_status(data)                            (0x00000002&((data)<<1))
#define FIFO_STATUS_fifo_empty_status(data)                           (0x00000001&(data))
#define FIFO_STATUS_get_ps_540_coe_en(data)                           ((0x01000000&(data))>>24)
#define FIFO_STATUS_get_ps_540_select_tap(data)                       ((0x001F0000&(data))>>16)
#define FIFO_STATUS_get_ps_540_coe_modify(data)                       ((0x00007F00&(data))>>8)
#define FIFO_STATUS_get_fifo_full_status(data)                        ((0x00000002&(data))>>1)
#define FIFO_STATUS_get_fifo_empty_status(data)                       (0x00000001&(data))


#define I_GAIN_CONTROL                                                0x18019760
#define I_GAIN_CONTROL_reg_addr                                       "0xb8019760"
#define I_GAIN_CONTROL_reg                                            0xb8019760
#define I_GAIN_CONTROL_inst_addr                                      "0x01D8"
#define I_GAIN_CONTROL_inst                                           0x01D8
#define I_GAIN_CONTROL_pll_i_gain_shift                               (0)
#define I_GAIN_CONTROL_pll_i_gain_mask                                (0x000000FF)
#define I_GAIN_CONTROL_pll_i_gain(data)                               (0x000000FF&(data))
#define I_GAIN_CONTROL_get_pll_i_gain(data)                           (0x000000FF&(data))


#define MISC_CONTROL                                                  0x18019764
#define MISC_CONTROL_reg_addr                                         "0xb8019764"
#define MISC_CONTROL_reg                                              0xb8019764
#define MISC_CONTROL_inst_addr                                        "0x01D9"
#define MISC_CONTROL_inst                                             0x01D9
#define MISC_CONTROL_fifo_wo_ps_shift                                 (18)
#define MISC_CONTROL_fifo_depth_wo_ps_shift                           (12)
#define MISC_CONTROL_swallow_freq_sel_shift                           (8)
#define MISC_CONTROL_swallow_on_vsync_shift                           (7)
#define MISC_CONTROL_ndivload_en_shift                                (6)
#define MISC_CONTROL_ps_up_en_shift                                   (5)
#define MISC_CONTROL_ps_dn_en_shift                                   (4)
#define MISC_CONTROL_pll_div_shift                                    (0)
#define MISC_CONTROL_fifo_wo_ps_mask                                  (0x00040000)
#define MISC_CONTROL_fifo_depth_wo_ps_mask                            (0x0003F000)
#define MISC_CONTROL_swallow_freq_sel_mask                            (0x00000300)
#define MISC_CONTROL_swallow_on_vsync_mask                            (0x00000080)
#define MISC_CONTROL_ndivload_en_mask                                 (0x00000040)
#define MISC_CONTROL_ps_up_en_mask                                    (0x00000020)
#define MISC_CONTROL_ps_dn_en_mask                                    (0x00000010)
#define MISC_CONTROL_pll_div_mask                                     (0x0000000F)
#define MISC_CONTROL_fifo_wo_ps(data)                                 (0x00040000&((data)<<18))
#define MISC_CONTROL_fifo_depth_wo_ps(data)                           (0x0003F000&((data)<<12))
#define MISC_CONTROL_swallow_freq_sel(data)                           (0x00000300&((data)<<8))
#define MISC_CONTROL_swallow_on_vsync(data)                           (0x00000080&((data)<<7))
#define MISC_CONTROL_ndivload_en(data)                                (0x00000040&((data)<<6))
#define MISC_CONTROL_ps_up_en(data)                                   (0x00000020&((data)<<5))
#define MISC_CONTROL_ps_dn_en(data)                                   (0x00000010&((data)<<4))
#define MISC_CONTROL_pll_div(data)                                    (0x0000000F&(data))
#define MISC_CONTROL_get_fifo_wo_ps(data)                             ((0x00040000&(data))>>18)
#define MISC_CONTROL_get_fifo_depth_wo_ps(data)                       ((0x0003F000&(data))>>12)
#define MISC_CONTROL_get_swallow_freq_sel(data)                       ((0x00000300&(data))>>8)
#define MISC_CONTROL_get_swallow_on_vsync(data)                       ((0x00000080&(data))>>7)
#define MISC_CONTROL_get_ndivload_en(data)                            ((0x00000040&(data))>>6)
#define MISC_CONTROL_get_ps_up_en(data)                               ((0x00000020&(data))>>5)
#define MISC_CONTROL_get_ps_dn_en(data)                               ((0x00000010&(data))>>4)
#define MISC_CONTROL_get_pll_div(data)                                (0x0000000F&(data))


#define FIFO_DEPTH_MIN_STATUS                                         0x18019768
#define FIFO_DEPTH_MIN_STATUS_reg_addr                                "0xb8019768"
#define FIFO_DEPTH_MIN_STATUS_reg                                     0xb8019768
#define FIFO_DEPTH_MIN_STATUS_inst_addr                               "0x01DA"
#define FIFO_DEPTH_MIN_STATUS_inst                                    0x01DA
#define FIFO_DEPTH_MIN_STATUS_fifo_depth_min_clr_shift                (6)
#define FIFO_DEPTH_MIN_STATUS_fifo_depth_min_status_shift             (0)
#define FIFO_DEPTH_MIN_STATUS_fifo_depth_min_clr_mask                 (0x00000040)
#define FIFO_DEPTH_MIN_STATUS_fifo_depth_min_status_mask              (0x0000003F)
#define FIFO_DEPTH_MIN_STATUS_fifo_depth_min_clr(data)                (0x00000040&((data)<<6))
#define FIFO_DEPTH_MIN_STATUS_fifo_depth_min_status(data)             (0x0000003F&(data))
#define FIFO_DEPTH_MIN_STATUS_get_fifo_depth_min_clr(data)            ((0x00000040&(data))>>6)
#define FIFO_DEPTH_MIN_STATUS_get_fifo_depth_min_status(data)         (0x0000003F&(data))


#define FIFO_DEPTH_MAX_STATUS                                         0x1801976c
#define FIFO_DEPTH_MAX_STATUS_reg_addr                                "0xb801976c"
#define FIFO_DEPTH_MAX_STATUS_reg                                     0xb801976c
#define FIFO_DEPTH_MAX_STATUS_inst_addr                               "0x01DB"
#define FIFO_DEPTH_MAX_STATUS_inst                                    0x01DB
#define FIFO_DEPTH_MAX_STATUS_fifo_depth_max_clr_shift                (6)
#define FIFO_DEPTH_MAX_STATUS_fifo_depth_max_status_shift             (0)
#define FIFO_DEPTH_MAX_STATUS_fifo_depth_max_clr_mask                 (0x00000040)
#define FIFO_DEPTH_MAX_STATUS_fifo_depth_max_status_mask              (0x0000003F)
#define FIFO_DEPTH_MAX_STATUS_fifo_depth_max_clr(data)                (0x00000040&((data)<<6))
#define FIFO_DEPTH_MAX_STATUS_fifo_depth_max_status(data)             (0x0000003F&(data))
#define FIFO_DEPTH_MAX_STATUS_get_fifo_depth_max_clr(data)            ((0x00000040&(data))>>6)
#define FIFO_DEPTH_MAX_STATUS_get_fifo_depth_max_status(data)         (0x0000003F&(data))


#define PLL_DEBUG_CTRL1                                               0x18019770
#define PLL_DEBUG_CTRL1_reg_addr                                      "0xb8019770"
#define PLL_DEBUG_CTRL1_reg                                           0xb8019770
#define PLL_DEBUG_CTRL1_inst_addr                                     "0x01DC"
#define PLL_DEBUG_CTRL1_inst                                          0x01DC
#define PLL_DEBUG_CTRL1_ps_up_i_shift                                 (7)
#define PLL_DEBUG_CTRL1_ps_dn_i_shift                                 (6)
#define PLL_DEBUG_CTRL1_ps_divload_shift                              (1)
#define PLL_DEBUG_CTRL1_ps_pselload_shift                             (0)
#define PLL_DEBUG_CTRL1_ps_up_i_mask                                  (0x00000080)
#define PLL_DEBUG_CTRL1_ps_dn_i_mask                                  (0x00000040)
#define PLL_DEBUG_CTRL1_ps_divload_mask                               (0x00000002)
#define PLL_DEBUG_CTRL1_ps_pselload_mask                              (0x00000001)
#define PLL_DEBUG_CTRL1_ps_up_i(data)                                 (0x00000080&((data)<<7))
#define PLL_DEBUG_CTRL1_ps_dn_i(data)                                 (0x00000040&((data)<<6))
#define PLL_DEBUG_CTRL1_ps_divload(data)                              (0x00000002&((data)<<1))
#define PLL_DEBUG_CTRL1_ps_pselload(data)                             (0x00000001&(data))
#define PLL_DEBUG_CTRL1_get_ps_up_i(data)                             ((0x00000080&(data))>>7)
#define PLL_DEBUG_CTRL1_get_ps_dn_i(data)                             ((0x00000040&(data))>>6)
#define PLL_DEBUG_CTRL1_get_ps_divload(data)                          ((0x00000002&(data))>>1)
#define PLL_DEBUG_CTRL1_get_ps_pselload(data)                         (0x00000001&(data))


#define PLL_DEBUG_CTRL2                                               0x18019774
#define PLL_DEBUG_CTRL2_reg_addr                                      "0xb8019774"
#define PLL_DEBUG_CTRL2_reg                                           0xb8019774
#define PLL_DEBUG_CTRL2_inst_addr                                     "0x01DD"
#define PLL_DEBUG_CTRL2_inst                                          0x01DD
#define PLL_DEBUG_CTRL2_pll_debug_en_shift                            (7)
#define PLL_DEBUG_CTRL2_ps_psel_shift                                 (4)
#define PLL_DEBUG_CTRL2_ps_ndiv_shift                                 (0)
#define PLL_DEBUG_CTRL2_pll_debug_en_mask                             (0x00000080)
#define PLL_DEBUG_CTRL2_ps_psel_mask                                  (0x00000070)
#define PLL_DEBUG_CTRL2_ps_ndiv_mask                                  (0x0000000F)
#define PLL_DEBUG_CTRL2_pll_debug_en(data)                            (0x00000080&((data)<<7))
#define PLL_DEBUG_CTRL2_ps_psel(data)                                 (0x00000070&((data)<<4))
#define PLL_DEBUG_CTRL2_ps_ndiv(data)                                 (0x0000000F&(data))
#define PLL_DEBUG_CTRL2_get_pll_debug_en(data)                        ((0x00000080&(data))>>7)
#define PLL_DEBUG_CTRL2_get_ps_psel(data)                             ((0x00000070&(data))>>4)
#define PLL_DEBUG_CTRL2_get_ps_ndiv(data)                             (0x0000000F&(data))


#define DISP_FSYNC_CONTROL                                            0x18019778
#define DISP_FSYNC_CONTROL_reg_addr                                   "0xb8019778"
#define DISP_FSYNC_CONTROL_reg                                        0xb8019778
#define DISP_FSYNC_CONTROL_inst_addr                                  "0x01DE"
#define DISP_FSYNC_CONTROL_inst                                       0x01DE
#define DISP_FSYNC_CONTROL_ps_fix_en_shift                            (20)
#define DISP_FSYNC_CONTROL_ps_fix_value_shift                         (12)
#define DISP_FSYNC_CONTROL_ps_new_kikp_shift                          (11)
#define DISP_FSYNC_CONTROL_ps_new_kp_shift                            (8)
#define DISP_FSYNC_CONTROL_cnt_en_shift                               (5)
#define DISP_FSYNC_CONTROL_period_sel_shift                           (3)
#define DISP_FSYNC_CONTROL_lpf_en_shift                               (2)
#define DISP_FSYNC_CONTROL_k_sel_shift                                (0)
#define DISP_FSYNC_CONTROL_ps_fix_en_mask                             (0x00100000)
#define DISP_FSYNC_CONTROL_ps_fix_value_mask                          (0x000FF000)
#define DISP_FSYNC_CONTROL_ps_new_kikp_mask                           (0x00000800)
#define DISP_FSYNC_CONTROL_ps_new_kp_mask                             (0x00000700)
#define DISP_FSYNC_CONTROL_cnt_en_mask                                (0x00000020)
#define DISP_FSYNC_CONTROL_period_sel_mask                            (0x00000018)
#define DISP_FSYNC_CONTROL_lpf_en_mask                                (0x00000004)
#define DISP_FSYNC_CONTROL_k_sel_mask                                 (0x00000003)
#define DISP_FSYNC_CONTROL_ps_fix_en(data)                            (0x00100000&((data)<<20))
#define DISP_FSYNC_CONTROL_ps_fix_value(data)                         (0x000FF000&((data)<<12))
#define DISP_FSYNC_CONTROL_ps_new_kikp(data)                          (0x00000800&((data)<<11))
#define DISP_FSYNC_CONTROL_ps_new_kp(data)                            (0x00000700&((data)<<8))
#define DISP_FSYNC_CONTROL_cnt_en(data)                               (0x00000020&((data)<<5))
#define DISP_FSYNC_CONTROL_period_sel(data)                           (0x00000018&((data)<<3))
#define DISP_FSYNC_CONTROL_lpf_en(data)                               (0x00000004&((data)<<2))
#define DISP_FSYNC_CONTROL_k_sel(data)                                (0x00000003&(data))
#define DISP_FSYNC_CONTROL_get_ps_fix_en(data)                        ((0x00100000&(data))>>20)
#define DISP_FSYNC_CONTROL_get_ps_fix_value(data)                     ((0x000FF000&(data))>>12)
#define DISP_FSYNC_CONTROL_get_ps_new_kikp(data)                      ((0x00000800&(data))>>11)
#define DISP_FSYNC_CONTROL_get_ps_new_kp(data)                        ((0x00000700&(data))>>8)
#define DISP_FSYNC_CONTROL_get_cnt_en(data)                           ((0x00000020&(data))>>5)
#define DISP_FSYNC_CONTROL_get_period_sel(data)                       ((0x00000018&(data))>>3)
#define DISP_FSYNC_CONTROL_get_lpf_en(data)                           ((0x00000004&(data))>>2)
#define DISP_FSYNC_CONTROL_get_k_sel(data)                            (0x00000003&(data))


#define FIFO_WO_PS_FUNC                                               0x1801977c
#define FIFO_WO_PS_FUNC_reg_addr                                      "0xb801977c"
#define FIFO_WO_PS_FUNC_reg                                           0xb801977c
#define FIFO_WO_PS_FUNC_inst_addr                                     "0x01DF"
#define FIFO_WO_PS_FUNC_inst                                          0x01DF
#define FIFO_WO_PS_FUNC_fifo_wo_ps_clk_jump_shift                     (30)
#define FIFO_WO_PS_FUNC_fifo_wo_ps_err_act_shift                      (29)
#define FIFO_WO_PS_FUNC_fifo_wo_ps_adapt_shift                        (28)
#define FIFO_WO_PS_FUNC_fifo_wo_ps_hlen_min_shift                     (16)
#define FIFO_WO_PS_FUNC_fifo_depth_wo_ps_min_shift                    (8)
#define FIFO_WO_PS_FUNC_fifo_depth_wo_ps_max_shift                    (0)
#define FIFO_WO_PS_FUNC_fifo_wo_ps_clk_jump_mask                      (0x40000000)
#define FIFO_WO_PS_FUNC_fifo_wo_ps_err_act_mask                       (0x20000000)
#define FIFO_WO_PS_FUNC_fifo_wo_ps_adapt_mask                         (0x10000000)
#define FIFO_WO_PS_FUNC_fifo_wo_ps_hlen_min_mask                      (0x0FFF0000)
#define FIFO_WO_PS_FUNC_fifo_depth_wo_ps_min_mask                     (0x00003F00)
#define FIFO_WO_PS_FUNC_fifo_depth_wo_ps_max_mask                     (0x0000003F)
#define FIFO_WO_PS_FUNC_fifo_wo_ps_clk_jump(data)                     (0x40000000&((data)<<30))
#define FIFO_WO_PS_FUNC_fifo_wo_ps_err_act(data)                      (0x20000000&((data)<<29))
#define FIFO_WO_PS_FUNC_fifo_wo_ps_adapt(data)                        (0x10000000&((data)<<28))
#define FIFO_WO_PS_FUNC_fifo_wo_ps_hlen_min(data)                     (0x0FFF0000&((data)<<16))
#define FIFO_WO_PS_FUNC_fifo_depth_wo_ps_min(data)                    (0x00003F00&((data)<<8))
#define FIFO_WO_PS_FUNC_fifo_depth_wo_ps_max(data)                    (0x0000003F&(data))
#define FIFO_WO_PS_FUNC_get_fifo_wo_ps_clk_jump(data)                 ((0x40000000&(data))>>30)
#define FIFO_WO_PS_FUNC_get_fifo_wo_ps_err_act(data)                  ((0x20000000&(data))>>29)
#define FIFO_WO_PS_FUNC_get_fifo_wo_ps_adapt(data)                    ((0x10000000&(data))>>28)
#define FIFO_WO_PS_FUNC_get_fifo_wo_ps_hlen_min(data)                 ((0x0FFF0000&(data))>>16)
#define FIFO_WO_PS_FUNC_get_fifo_depth_wo_ps_min(data)                ((0x00003F00&(data))>>8)
#define FIFO_WO_PS_FUNC_get_fifo_depth_wo_ps_max(data)                (0x0000003F&(data))


#define FIFO_WO_PS_CLK_STATE_PARAMETER                                0x18019780
#define FIFO_WO_PS_CLK_STATE_PARAMETER_reg_addr                       "0xb8019780"
#define FIFO_WO_PS_CLK_STATE_PARAMETER_reg                            0xb8019780
#define FIFO_WO_PS_CLK_STATE_PARAMETER_inst_addr                      "0x01E0"
#define FIFO_WO_PS_CLK_STATE_PARAMETER_inst                           0x01E0
#define FIFO_WO_PS_CLK_STATE_PARAMETER_fifo_wo_ps_ps_up_i1_shift      (23)
#define FIFO_WO_PS_CLK_STATE_PARAMETER_fifo_wo_ps_ps_dn_i1_shift      (22)
#define FIFO_WO_PS_CLK_STATE_PARAMETER_fifo_wo_ps_ps_pselload1_shift  (21)
#define FIFO_WO_PS_CLK_STATE_PARAMETER_fifo_wo_ps_ps_divload1_shift   (20)
#define FIFO_WO_PS_CLK_STATE_PARAMETER_fifo_wo_ps_ps_psel1_shift      (17)
#define FIFO_WO_PS_CLK_STATE_PARAMETER_fifo_wo_ps_ps_ndiv1_shift      (12)
#define FIFO_WO_PS_CLK_STATE_PARAMETER_fifo_wo_ps_ps_up_i0_shift      (11)
#define FIFO_WO_PS_CLK_STATE_PARAMETER_fifo_wo_ps_ps_dn_i0_shift      (10)
#define FIFO_WO_PS_CLK_STATE_PARAMETER_fifo_wo_ps_ps_pselload0_shift  (9)
#define FIFO_WO_PS_CLK_STATE_PARAMETER_fifo_wo_ps_ps_divload0_shift   (8)
#define FIFO_WO_PS_CLK_STATE_PARAMETER_fifo_wo_ps_ps_psel0_shift      (5)
#define FIFO_WO_PS_CLK_STATE_PARAMETER_fifo_wo_ps_ps_ndiv0_shift      (0)
#define FIFO_WO_PS_CLK_STATE_PARAMETER_fifo_wo_ps_ps_up_i1_mask       (0x00800000)
#define FIFO_WO_PS_CLK_STATE_PARAMETER_fifo_wo_ps_ps_dn_i1_mask       (0x00400000)
#define FIFO_WO_PS_CLK_STATE_PARAMETER_fifo_wo_ps_ps_pselload1_mask   (0x00200000)
#define FIFO_WO_PS_CLK_STATE_PARAMETER_fifo_wo_ps_ps_divload1_mask    (0x00100000)
#define FIFO_WO_PS_CLK_STATE_PARAMETER_fifo_wo_ps_ps_psel1_mask       (0x000E0000)
#define FIFO_WO_PS_CLK_STATE_PARAMETER_fifo_wo_ps_ps_ndiv1_mask       (0x0001F000)
#define FIFO_WO_PS_CLK_STATE_PARAMETER_fifo_wo_ps_ps_up_i0_mask       (0x00000800)
#define FIFO_WO_PS_CLK_STATE_PARAMETER_fifo_wo_ps_ps_dn_i0_mask       (0x00000400)
#define FIFO_WO_PS_CLK_STATE_PARAMETER_fifo_wo_ps_ps_pselload0_mask   (0x00000200)
#define FIFO_WO_PS_CLK_STATE_PARAMETER_fifo_wo_ps_ps_divload0_mask    (0x00000100)
#define FIFO_WO_PS_CLK_STATE_PARAMETER_fifo_wo_ps_ps_psel0_mask       (0x000000E0)
#define FIFO_WO_PS_CLK_STATE_PARAMETER_fifo_wo_ps_ps_ndiv0_mask       (0x0000001F)
#define FIFO_WO_PS_CLK_STATE_PARAMETER_fifo_wo_ps_ps_up_i1(data)      (0x00800000&((data)<<23))
#define FIFO_WO_PS_CLK_STATE_PARAMETER_fifo_wo_ps_ps_dn_i1(data)      (0x00400000&((data)<<22))
#define FIFO_WO_PS_CLK_STATE_PARAMETER_fifo_wo_ps_ps_pselload1(data)  (0x00200000&((data)<<21))
#define FIFO_WO_PS_CLK_STATE_PARAMETER_fifo_wo_ps_ps_divload1(data)   (0x00100000&((data)<<20))
#define FIFO_WO_PS_CLK_STATE_PARAMETER_fifo_wo_ps_ps_psel1(data)      (0x000E0000&((data)<<17))
#define FIFO_WO_PS_CLK_STATE_PARAMETER_fifo_wo_ps_ps_ndiv1(data)      (0x0001F000&((data)<<12))
#define FIFO_WO_PS_CLK_STATE_PARAMETER_fifo_wo_ps_ps_up_i0(data)      (0x00000800&((data)<<11))
#define FIFO_WO_PS_CLK_STATE_PARAMETER_fifo_wo_ps_ps_dn_i0(data)      (0x00000400&((data)<<10))
#define FIFO_WO_PS_CLK_STATE_PARAMETER_fifo_wo_ps_ps_pselload0(data)  (0x00000200&((data)<<9))
#define FIFO_WO_PS_CLK_STATE_PARAMETER_fifo_wo_ps_ps_divload0(data)   (0x00000100&((data)<<8))
#define FIFO_WO_PS_CLK_STATE_PARAMETER_fifo_wo_ps_ps_psel0(data)      (0x000000E0&((data)<<5))
#define FIFO_WO_PS_CLK_STATE_PARAMETER_fifo_wo_ps_ps_ndiv0(data)      (0x0000001F&(data))
#define FIFO_WO_PS_CLK_STATE_PARAMETER_get_fifo_wo_ps_ps_up_i1(data)  ((0x00800000&(data))>>23)
#define FIFO_WO_PS_CLK_STATE_PARAMETER_get_fifo_wo_ps_ps_dn_i1(data)  ((0x00400000&(data))>>22)
#define FIFO_WO_PS_CLK_STATE_PARAMETER_get_fifo_wo_ps_ps_pselload1(data)  ((0x00200000&(data))>>21)
#define FIFO_WO_PS_CLK_STATE_PARAMETER_get_fifo_wo_ps_ps_divload1(data)  ((0x00100000&(data))>>20)
#define FIFO_WO_PS_CLK_STATE_PARAMETER_get_fifo_wo_ps_ps_psel1(data)  ((0x000E0000&(data))>>17)
#define FIFO_WO_PS_CLK_STATE_PARAMETER_get_fifo_wo_ps_ps_ndiv1(data)  ((0x0001F000&(data))>>12)
#define FIFO_WO_PS_CLK_STATE_PARAMETER_get_fifo_wo_ps_ps_up_i0(data)  ((0x00000800&(data))>>11)
#define FIFO_WO_PS_CLK_STATE_PARAMETER_get_fifo_wo_ps_ps_dn_i0(data)  ((0x00000400&(data))>>10)
#define FIFO_WO_PS_CLK_STATE_PARAMETER_get_fifo_wo_ps_ps_pselload0(data)  ((0x00000200&(data))>>9)
#define FIFO_WO_PS_CLK_STATE_PARAMETER_get_fifo_wo_ps_ps_divload0(data)  ((0x00000100&(data))>>8)
#define FIFO_WO_PS_CLK_STATE_PARAMETER_get_fifo_wo_ps_ps_psel0(data)  ((0x000000E0&(data))>>5)
#define FIFO_WO_PS_CLK_STATE_PARAMETER_get_fifo_wo_ps_ps_ndiv0(data)  (0x0000001F&(data))


#define FIFO_STATUS_NO_PLL                                            0x18019784
#define FIFO_STATUS_NO_PLL_reg_addr                                   "0xb8019784"
#define FIFO_STATUS_NO_PLL_reg                                        0xb8019784
#define FIFO_STATUS_NO_PLL_inst_addr                                  "0x01E1"
#define FIFO_STATUS_NO_PLL_inst                                       0x01E1
#define FIFO_STATUS_NO_PLL_fifo_clk_state_shift                       (12)
#define FIFO_STATUS_NO_PLL_fifo_out_line_len_shift                    (0)
#define FIFO_STATUS_NO_PLL_fifo_clk_state_mask                        (0x00001000)
#define FIFO_STATUS_NO_PLL_fifo_out_line_len_mask                     (0x00000FFF)
#define FIFO_STATUS_NO_PLL_fifo_clk_state(data)                       (0x00001000&((data)<<12))
#define FIFO_STATUS_NO_PLL_fifo_out_line_len(data)                    (0x00000FFF&(data))
#define FIFO_STATUS_NO_PLL_get_fifo_clk_state(data)                   ((0x00001000&(data))>>12)
#define FIFO_STATUS_NO_PLL_get_fifo_out_line_len(data)                (0x00000FFF&(data))


#define DEBUG_MUX                                                     0x18019788
#define DEBUG_MUX_reg_addr                                            "0xb8019788"
#define DEBUG_MUX_reg                                                 0xb8019788
#define DEBUG_MUX_inst_addr                                           "0x01E2"
#define DEBUG_MUX_inst                                                0x01E2
#define DEBUG_MUX_debug_test_enable_shift                             (7)
#define DEBUG_MUX_debug_test_shift                                    (0)
#define DEBUG_MUX_debug_test_enable_mask                              (0x00000080)
#define DEBUG_MUX_debug_test_mask                                     (0x0000007F)
#define DEBUG_MUX_debug_test_enable(data)                             (0x00000080&((data)<<7))
#define DEBUG_MUX_debug_test(data)                                    (0x0000007F&(data))
#define DEBUG_MUX_get_debug_test_enable(data)                         ((0x00000080&(data))>>7)
#define DEBUG_MUX_get_debug_test(data)                                (0x0000007F&(data))


#define VIDEO_DEBUG_ANALOG                                            0x1801978c
#define VIDEO_DEBUG_ANALOG_reg_addr                                   "0xb801978c"
#define VIDEO_DEBUG_ANALOG_reg                                        0xb801978c
#define VIDEO_DEBUG_ANALOG_inst_addr                                  "0x01E3"
#define VIDEO_DEBUG_ANALOG_inst                                       0x01E3
#define VIDEO_DEBUG_ANALOG_muxanalogb_shift                           (4)
#define VIDEO_DEBUG_ANALOG_muxanaloga_shift                           (0)
#define VIDEO_DEBUG_ANALOG_muxanalogb_mask                            (0x000000F0)
#define VIDEO_DEBUG_ANALOG_muxanaloga_mask                            (0x0000000F)
#define VIDEO_DEBUG_ANALOG_muxanalogb(data)                           (0x000000F0&((data)<<4))
#define VIDEO_DEBUG_ANALOG_muxanaloga(data)                           (0x0000000F&(data))
#define VIDEO_DEBUG_ANALOG_get_muxanalogb(data)                       ((0x000000F0&(data))>>4)
#define VIDEO_DEBUG_ANALOG_get_muxanaloga(data)                       (0x0000000F&(data))


#define VIDEO_DEBUG_DIGITAL                                           0x18019790
#define VIDEO_DEBUG_DIGITAL_reg_addr                                  "0xb8019790"
#define VIDEO_DEBUG_DIGITAL_reg                                       0xb8019790
#define VIDEO_DEBUG_DIGITAL_inst_addr                                 "0x01E4"
#define VIDEO_DEBUG_DIGITAL_inst                                      0x01E4
#define VIDEO_DEBUG_DIGITAL_clk_dac_polarity_shift                    (7)
#define VIDEO_DEBUG_DIGITAL_clk_sct_polarity_shift                    (6)
#define VIDEO_DEBUG_DIGITAL_debug_test_dac_en_shift                   (4)
#define VIDEO_DEBUG_DIGITAL_muxdigital_shift                          (0)
#define VIDEO_DEBUG_DIGITAL_clk_dac_polarity_mask                     (0x00000080)
#define VIDEO_DEBUG_DIGITAL_clk_sct_polarity_mask                     (0x00000040)
#define VIDEO_DEBUG_DIGITAL_debug_test_dac_en_mask                    (0x00000010)
#define VIDEO_DEBUG_DIGITAL_muxdigital_mask                           (0x0000000F)
#define VIDEO_DEBUG_DIGITAL_clk_dac_polarity(data)                    (0x00000080&((data)<<7))
#define VIDEO_DEBUG_DIGITAL_clk_sct_polarity(data)                    (0x00000040&((data)<<6))
#define VIDEO_DEBUG_DIGITAL_debug_test_dac_en(data)                   (0x00000010&((data)<<4))
#define VIDEO_DEBUG_DIGITAL_muxdigital(data)                          (0x0000000F&(data))
#define VIDEO_DEBUG_DIGITAL_get_clk_dac_polarity(data)                ((0x00000080&(data))>>7)
#define VIDEO_DEBUG_DIGITAL_get_clk_sct_polarity(data)                ((0x00000040&(data))>>6)
#define VIDEO_DEBUG_DIGITAL_get_debug_test_dac_en(data)               ((0x00000010&(data))>>4)
#define VIDEO_DEBUG_DIGITAL_get_muxdigital(data)                      (0x0000000F&(data))


#define PATTERN_CONTROL                                               0x18019794
#define PATTERN_CONTROL_reg_addr                                      "0xb8019794"
#define PATTERN_CONTROL_reg                                           0xb8019794
#define PATTERN_CONTROL_inst_addr                                     "0x01E5"
#define PATTERN_CONTROL_inst                                          0x01E5
#define PATTERN_CONTROL_patgen_vline_vactive_end_shift                (20)
#define PATTERN_CONTROL_patgen_vline_shift                            (8)
#define PATTERN_CONTROL_patgen_vline_en_shift                         (7)
#define PATTERN_CONTROL_fifo_out_pattern_gen_en_shift                 (6)
#define PATTERN_CONTROL_pattern_gen_scart_en_shift                    (5)
#define PATTERN_CONTROL_crc_chk_sel_shift                             (4)
#define PATTERN_CONTROL_pattern_gen_input_mode_sel_shift              (2)
#define PATTERN_CONTROL_pattern_gen_cvbs_mode_shift                   (1)
#define PATTERN_CONTROL_pattern_generator_enable_shift                (0)
#define PATTERN_CONTROL_patgen_vline_vactive_end_mask                 (0x3FF00000)
#define PATTERN_CONTROL_patgen_vline_mask                             (0x0003FF00)
#define PATTERN_CONTROL_patgen_vline_en_mask                          (0x00000080)
#define PATTERN_CONTROL_fifo_out_pattern_gen_en_mask                  (0x00000040)
#define PATTERN_CONTROL_pattern_gen_scart_en_mask                     (0x00000020)
#define PATTERN_CONTROL_crc_chk_sel_mask                              (0x00000010)
#define PATTERN_CONTROL_pattern_gen_input_mode_sel_mask               (0x00000004)
#define PATTERN_CONTROL_pattern_gen_cvbs_mode_mask                    (0x00000002)
#define PATTERN_CONTROL_pattern_generator_enable_mask                 (0x00000001)
#define PATTERN_CONTROL_patgen_vline_vactive_end(data)                (0x3FF00000&((data)<<20))
#define PATTERN_CONTROL_patgen_vline(data)                            (0x0003FF00&((data)<<8))
#define PATTERN_CONTROL_patgen_vline_en(data)                         (0x00000080&((data)<<7))
#define PATTERN_CONTROL_fifo_out_pattern_gen_en(data)                 (0x00000040&((data)<<6))
#define PATTERN_CONTROL_pattern_gen_scart_en(data)                    (0x00000020&((data)<<5))
#define PATTERN_CONTROL_crc_chk_sel(data)                             (0x00000010&((data)<<4))
#define PATTERN_CONTROL_pattern_gen_input_mode_sel(data)              (0x00000004&((data)<<2))
#define PATTERN_CONTROL_pattern_gen_cvbs_mode(data)                   (0x00000002&((data)<<1))
#define PATTERN_CONTROL_pattern_generator_enable(data)                (0x00000001&(data))
#define PATTERN_CONTROL_get_patgen_vline_vactive_end(data)            ((0x3FF00000&(data))>>20)
#define PATTERN_CONTROL_get_patgen_vline(data)                        ((0x0003FF00&(data))>>8)
#define PATTERN_CONTROL_get_patgen_vline_en(data)                     ((0x00000080&(data))>>7)
#define PATTERN_CONTROL_get_fifo_out_pattern_gen_en(data)             ((0x00000040&(data))>>6)
#define PATTERN_CONTROL_get_pattern_gen_scart_en(data)                ((0x00000020&(data))>>5)
#define PATTERN_CONTROL_get_crc_chk_sel(data)                         ((0x00000010&(data))>>4)
#define PATTERN_CONTROL_get_pattern_gen_input_mode_sel(data)          ((0x00000004&(data))>>2)
#define PATTERN_CONTROL_get_pattern_gen_cvbs_mode(data)               ((0x00000002&(data))>>1)
#define PATTERN_CONTROL_get_pattern_generator_enable(data)            (0x00000001&(data))


#define CRC_RESULT3                                                   0x18019798
#define CRC_RESULT3_reg_addr                                          "0xb8019798"
#define CRC_RESULT3_reg                                               0xb8019798
#define CRC_RESULT3_inst_addr                                         "0x01E6"
#define CRC_RESULT3_inst                                              0x01E6
#define CRC_RESULT3_crc_result_shift                                  (0)
#define CRC_RESULT3_crc_result_mask                                   (0xFFFFFFFF)
#define CRC_RESULT3_crc_result(data)                                  (0xFFFFFFFF&(data))
#define CRC_RESULT3_get_crc_result(data)                              (0xFFFFFFFF&(data))


#define PATGEN_CTRL                                                   0x1801979c
#define PATGEN_CTRL_reg_addr                                          "0xb801979c"
#define PATGEN_CTRL_reg                                               0xb801979c
#define PATGEN_CTRL_inst_addr                                         "0x01E7"
#define PATGEN_CTRL_inst                                              0x01E7
#define PATGEN_CTRL_clk_vdadc_polarity_shift                          (8)
#define PATGEN_CTRL_clk_polarity_shift                                (7)
#define PATGEN_CTRL_patgen_sync_gain_shift                            (4)
#define PATGEN_CTRL_patgen_burst_gain_shift                           (0)
#define PATGEN_CTRL_clk_vdadc_polarity_mask                           (0x00000100)
#define PATGEN_CTRL_clk_polarity_mask                                 (0x00000080)
#define PATGEN_CTRL_patgen_sync_gain_mask                             (0x00000070)
#define PATGEN_CTRL_patgen_burst_gain_mask                            (0x00000007)
#define PATGEN_CTRL_clk_vdadc_polarity(data)                          (0x00000100&((data)<<8))
#define PATGEN_CTRL_clk_polarity(data)                                (0x00000080&((data)<<7))
#define PATGEN_CTRL_patgen_sync_gain(data)                            (0x00000070&((data)<<4))
#define PATGEN_CTRL_patgen_burst_gain(data)                           (0x00000007&(data))
#define PATGEN_CTRL_get_clk_vdadc_polarity(data)                      ((0x00000100&(data))>>8)
#define PATGEN_CTRL_get_clk_polarity(data)                            ((0x00000080&(data))>>7)
#define PATGEN_CTRL_get_patgen_sync_gain(data)                        ((0x00000070&(data))>>4)
#define PATGEN_CTRL_get_patgen_burst_gain(data)                       (0x00000007&(data))


#define BIST_MODE                                                     0x180197a0
#define BIST_MODE_reg_addr                                            "0xb80197a0"
#define BIST_MODE_reg                                                 0xb80197a0
#define BIST_MODE_inst_addr                                           "0x01E8"
#define BIST_MODE_inst                                                0x01E8
#define BIST_MODE_bist_mode_out_shift                                 (4)
#define BIST_MODE_bist_mode_fifo_shift                                (3)
#define BIST_MODE_bist_mode_dma_shift                                 (2)
#define BIST_MODE_bist_mode_27_2_shift                                (1)
#define BIST_MODE_bist_mode_27_1_shift                                (0)
#define BIST_MODE_bist_mode_out_mask                                  (0x00000010)
#define BIST_MODE_bist_mode_fifo_mask                                 (0x00000008)
#define BIST_MODE_bist_mode_dma_mask                                  (0x00000004)
#define BIST_MODE_bist_mode_27_2_mask                                 (0x00000002)
#define BIST_MODE_bist_mode_27_1_mask                                 (0x00000001)
#define BIST_MODE_bist_mode_out(data)                                 (0x00000010&((data)<<4))
#define BIST_MODE_bist_mode_fifo(data)                                (0x00000008&((data)<<3))
#define BIST_MODE_bist_mode_dma(data)                                 (0x00000004&((data)<<2))
#define BIST_MODE_bist_mode_27_2(data)                                (0x00000002&((data)<<1))
#define BIST_MODE_bist_mode_27_1(data)                                (0x00000001&(data))
#define BIST_MODE_get_bist_mode_out(data)                             ((0x00000010&(data))>>4)
#define BIST_MODE_get_bist_mode_fifo(data)                            ((0x00000008&(data))>>3)
#define BIST_MODE_get_bist_mode_dma(data)                             ((0x00000004&(data))>>2)
#define BIST_MODE_get_bist_mode_27_2(data)                            ((0x00000002&(data))>>1)
#define BIST_MODE_get_bist_mode_27_1(data)                            (0x00000001&(data))


#define BIST_DONE                                                     0x180197a4
#define BIST_DONE_reg_addr                                            "0xb80197a4"
#define BIST_DONE_reg                                                 0xb80197a4
#define BIST_DONE_inst_addr                                           "0x01E9"
#define BIST_DONE_inst                                                0x01E9
#define BIST_DONE_bist_done_out_shift                                 (4)
#define BIST_DONE_bist_done_fifo_shift                                (3)
#define BIST_DONE_bist_done_dma_shift                                 (2)
#define BIST_DONE_bist_done_27_2_shift                                (1)
#define BIST_DONE_bist_done_27_1_shift                                (0)
#define BIST_DONE_bist_done_out_mask                                  (0x00000010)
#define BIST_DONE_bist_done_fifo_mask                                 (0x00000008)
#define BIST_DONE_bist_done_dma_mask                                  (0x00000004)
#define BIST_DONE_bist_done_27_2_mask                                 (0x00000002)
#define BIST_DONE_bist_done_27_1_mask                                 (0x00000001)
#define BIST_DONE_bist_done_out(data)                                 (0x00000010&((data)<<4))
#define BIST_DONE_bist_done_fifo(data)                                (0x00000008&((data)<<3))
#define BIST_DONE_bist_done_dma(data)                                 (0x00000004&((data)<<2))
#define BIST_DONE_bist_done_27_2(data)                                (0x00000002&((data)<<1))
#define BIST_DONE_bist_done_27_1(data)                                (0x00000001&(data))
#define BIST_DONE_get_bist_done_out(data)                             ((0x00000010&(data))>>4)
#define BIST_DONE_get_bist_done_fifo(data)                            ((0x00000008&(data))>>3)
#define BIST_DONE_get_bist_done_dma(data)                             ((0x00000004&(data))>>2)
#define BIST_DONE_get_bist_done_27_2(data)                            ((0x00000002&(data))>>1)
#define BIST_DONE_get_bist_done_27_1(data)                            (0x00000001&(data))


#define BIST_FAIL                                                     0x180197a8
#define BIST_FAIL_reg_addr                                            "0xb80197a8"
#define BIST_FAIL_reg                                                 0xb80197a8
#define BIST_FAIL_inst_addr                                           "0x01EA"
#define BIST_FAIL_inst                                                0x01EA
#define BIST_FAIL_bist_fail_out_shift                                 (4)
#define BIST_FAIL_bist_fail_fifo_shift                                (3)
#define BIST_FAIL_bist_fail_dma_shift                                 (2)
#define BIST_FAIL_bist_fail_27_2_shift                                (1)
#define BIST_FAIL_bist_fail_27_1_shift                                (0)
#define BIST_FAIL_bist_fail_out_mask                                  (0x00000010)
#define BIST_FAIL_bist_fail_fifo_mask                                 (0x00000008)
#define BIST_FAIL_bist_fail_dma_mask                                  (0x00000004)
#define BIST_FAIL_bist_fail_27_2_mask                                 (0x00000002)
#define BIST_FAIL_bist_fail_27_1_mask                                 (0x00000001)
#define BIST_FAIL_bist_fail_out(data)                                 (0x00000010&((data)<<4))
#define BIST_FAIL_bist_fail_fifo(data)                                (0x00000008&((data)<<3))
#define BIST_FAIL_bist_fail_dma(data)                                 (0x00000004&((data)<<2))
#define BIST_FAIL_bist_fail_27_2(data)                                (0x00000002&((data)<<1))
#define BIST_FAIL_bist_fail_27_1(data)                                (0x00000001&(data))
#define BIST_FAIL_get_bist_fail_out(data)                             ((0x00000010&(data))>>4)
#define BIST_FAIL_get_bist_fail_fifo(data)                            ((0x00000008&(data))>>3)
#define BIST_FAIL_get_bist_fail_dma(data)                             ((0x00000004&(data))>>2)
#define BIST_FAIL_get_bist_fail_27_2(data)                            ((0x00000002&(data))>>1)
#define BIST_FAIL_get_bist_fail_27_1(data)                            (0x00000001&(data))


#define BIST_DRF_MODE                                                 0x180197ac
#define BIST_DRF_MODE_reg_addr                                        "0xb80197ac"
#define BIST_DRF_MODE_reg                                             0xb80197ac
#define BIST_DRF_MODE_inst_addr                                       "0x01EB"
#define BIST_DRF_MODE_inst                                            0x01EB
#define BIST_DRF_MODE_bist_drf_mode_out_shift                         (4)
#define BIST_DRF_MODE_bist_drf_mode_fifo_shift                        (3)
#define BIST_DRF_MODE_bist_drf_mode_dma_shift                         (2)
#define BIST_DRF_MODE_bist_drf_mode_27_2_shift                        (1)
#define BIST_DRF_MODE_bist_drf_mode_27_1_shift                        (0)
#define BIST_DRF_MODE_bist_drf_mode_out_mask                          (0x00000010)
#define BIST_DRF_MODE_bist_drf_mode_fifo_mask                         (0x00000008)
#define BIST_DRF_MODE_bist_drf_mode_dma_mask                          (0x00000004)
#define BIST_DRF_MODE_bist_drf_mode_27_2_mask                         (0x00000002)
#define BIST_DRF_MODE_bist_drf_mode_27_1_mask                         (0x00000001)
#define BIST_DRF_MODE_bist_drf_mode_out(data)                         (0x00000010&((data)<<4))
#define BIST_DRF_MODE_bist_drf_mode_fifo(data)                        (0x00000008&((data)<<3))
#define BIST_DRF_MODE_bist_drf_mode_dma(data)                         (0x00000004&((data)<<2))
#define BIST_DRF_MODE_bist_drf_mode_27_2(data)                        (0x00000002&((data)<<1))
#define BIST_DRF_MODE_bist_drf_mode_27_1(data)                        (0x00000001&(data))
#define BIST_DRF_MODE_get_bist_drf_mode_out(data)                     ((0x00000010&(data))>>4)
#define BIST_DRF_MODE_get_bist_drf_mode_fifo(data)                    ((0x00000008&(data))>>3)
#define BIST_DRF_MODE_get_bist_drf_mode_dma(data)                     ((0x00000004&(data))>>2)
#define BIST_DRF_MODE_get_bist_drf_mode_27_2(data)                    ((0x00000002&(data))>>1)
#define BIST_DRF_MODE_get_bist_drf_mode_27_1(data)                    (0x00000001&(data))


#define BIST_DRF_RESUME                                               0x180197b0
#define BIST_DRF_RESUME_reg_addr                                      "0xb80197b0"
#define BIST_DRF_RESUME_reg                                           0xb80197b0
#define BIST_DRF_RESUME_inst_addr                                     "0x01EC"
#define BIST_DRF_RESUME_inst                                          0x01EC
#define BIST_DRF_RESUME_bist_drf_resume_out_shift                     (4)
#define BIST_DRF_RESUME_bist_drf_resume_fifo_shift                    (3)
#define BIST_DRF_RESUME_bist_drf_resume_dma_shift                     (2)
#define BIST_DRF_RESUME_bist_drf_resume_27_2_shift                    (1)
#define BIST_DRF_RESUME_bist_drf_resume_27_1_shift                    (0)
#define BIST_DRF_RESUME_bist_drf_resume_out_mask                      (0x00000010)
#define BIST_DRF_RESUME_bist_drf_resume_fifo_mask                     (0x00000008)
#define BIST_DRF_RESUME_bist_drf_resume_dma_mask                      (0x00000004)
#define BIST_DRF_RESUME_bist_drf_resume_27_2_mask                     (0x00000002)
#define BIST_DRF_RESUME_bist_drf_resume_27_1_mask                     (0x00000001)
#define BIST_DRF_RESUME_bist_drf_resume_out(data)                     (0x00000010&((data)<<4))
#define BIST_DRF_RESUME_bist_drf_resume_fifo(data)                    (0x00000008&((data)<<3))
#define BIST_DRF_RESUME_bist_drf_resume_dma(data)                     (0x00000004&((data)<<2))
#define BIST_DRF_RESUME_bist_drf_resume_27_2(data)                    (0x00000002&((data)<<1))
#define BIST_DRF_RESUME_bist_drf_resume_27_1(data)                    (0x00000001&(data))
#define BIST_DRF_RESUME_get_bist_drf_resume_out(data)                 ((0x00000010&(data))>>4)
#define BIST_DRF_RESUME_get_bist_drf_resume_fifo(data)                ((0x00000008&(data))>>3)
#define BIST_DRF_RESUME_get_bist_drf_resume_dma(data)                 ((0x00000004&(data))>>2)
#define BIST_DRF_RESUME_get_bist_drf_resume_27_2(data)                ((0x00000002&(data))>>1)
#define BIST_DRF_RESUME_get_bist_drf_resume_27_1(data)                (0x00000001&(data))


#define BIST_DRF_DONE                                                 0x180197b4
#define BIST_DRF_DONE_reg_addr                                        "0xb80197b4"
#define BIST_DRF_DONE_reg                                             0xb80197b4
#define BIST_DRF_DONE_inst_addr                                       "0x01ED"
#define BIST_DRF_DONE_inst                                            0x01ED
#define BIST_DRF_DONE_bist_drf_done_out_shift                         (4)
#define BIST_DRF_DONE_bist_drf_done_fifo_shift                        (3)
#define BIST_DRF_DONE_bist_drf_done_dma_shift                         (2)
#define BIST_DRF_DONE_bist_drf_done_27_2_shift                        (1)
#define BIST_DRF_DONE_bist_drf_done_27_1_shift                        (0)
#define BIST_DRF_DONE_bist_drf_done_out_mask                          (0x00000010)
#define BIST_DRF_DONE_bist_drf_done_fifo_mask                         (0x00000008)
#define BIST_DRF_DONE_bist_drf_done_dma_mask                          (0x00000004)
#define BIST_DRF_DONE_bist_drf_done_27_2_mask                         (0x00000002)
#define BIST_DRF_DONE_bist_drf_done_27_1_mask                         (0x00000001)
#define BIST_DRF_DONE_bist_drf_done_out(data)                         (0x00000010&((data)<<4))
#define BIST_DRF_DONE_bist_drf_done_fifo(data)                        (0x00000008&((data)<<3))
#define BIST_DRF_DONE_bist_drf_done_dma(data)                         (0x00000004&((data)<<2))
#define BIST_DRF_DONE_bist_drf_done_27_2(data)                        (0x00000002&((data)<<1))
#define BIST_DRF_DONE_bist_drf_done_27_1(data)                        (0x00000001&(data))
#define BIST_DRF_DONE_get_bist_drf_done_out(data)                     ((0x00000010&(data))>>4)
#define BIST_DRF_DONE_get_bist_drf_done_fifo(data)                    ((0x00000008&(data))>>3)
#define BIST_DRF_DONE_get_bist_drf_done_dma(data)                     ((0x00000004&(data))>>2)
#define BIST_DRF_DONE_get_bist_drf_done_27_2(data)                    ((0x00000002&(data))>>1)
#define BIST_DRF_DONE_get_bist_drf_done_27_1(data)                    (0x00000001&(data))


#define BIST_DRF_PAUSE                                                0x180197b8
#define BIST_DRF_PAUSE_reg_addr                                       "0xb80197b8"
#define BIST_DRF_PAUSE_reg                                            0xb80197b8
#define BIST_DRF_PAUSE_inst_addr                                      "0x01EE"
#define BIST_DRF_PAUSE_inst                                           0x01EE
#define BIST_DRF_PAUSE_bist_drf_pause_out_shift                       (4)
#define BIST_DRF_PAUSE_bist_drf_pause_fifo_shift                      (3)
#define BIST_DRF_PAUSE_bist_drf_pause_dma_shift                       (2)
#define BIST_DRF_PAUSE_bist_drf_pause_27_2_shift                      (1)
#define BIST_DRF_PAUSE_bist_drf_pause_27_1_shift                      (0)
#define BIST_DRF_PAUSE_bist_drf_pause_out_mask                        (0x00000010)
#define BIST_DRF_PAUSE_bist_drf_pause_fifo_mask                       (0x00000008)
#define BIST_DRF_PAUSE_bist_drf_pause_dma_mask                        (0x00000004)
#define BIST_DRF_PAUSE_bist_drf_pause_27_2_mask                       (0x00000002)
#define BIST_DRF_PAUSE_bist_drf_pause_27_1_mask                       (0x00000001)
#define BIST_DRF_PAUSE_bist_drf_pause_out(data)                       (0x00000010&((data)<<4))
#define BIST_DRF_PAUSE_bist_drf_pause_fifo(data)                      (0x00000008&((data)<<3))
#define BIST_DRF_PAUSE_bist_drf_pause_dma(data)                       (0x00000004&((data)<<2))
#define BIST_DRF_PAUSE_bist_drf_pause_27_2(data)                      (0x00000002&((data)<<1))
#define BIST_DRF_PAUSE_bist_drf_pause_27_1(data)                      (0x00000001&(data))
#define BIST_DRF_PAUSE_get_bist_drf_pause_out(data)                   ((0x00000010&(data))>>4)
#define BIST_DRF_PAUSE_get_bist_drf_pause_fifo(data)                  ((0x00000008&(data))>>3)
#define BIST_DRF_PAUSE_get_bist_drf_pause_dma(data)                   ((0x00000004&(data))>>2)
#define BIST_DRF_PAUSE_get_bist_drf_pause_27_2(data)                  ((0x00000002&(data))>>1)
#define BIST_DRF_PAUSE_get_bist_drf_pause_27_1(data)                  (0x00000001&(data))


#define BIST_DRF_FAIL                                                 0x180197bc
#define BIST_DRF_FAIL_reg_addr                                        "0xb80197bc"
#define BIST_DRF_FAIL_reg                                             0xb80197bc
#define BIST_DRF_FAIL_inst_addr                                       "0x01EF"
#define BIST_DRF_FAIL_inst                                            0x01EF
#define BIST_DRF_FAIL_bist_drf_fail_out_shift                         (4)
#define BIST_DRF_FAIL_bist_drf_fail_fifo_shift                        (3)
#define BIST_DRF_FAIL_bist_drf_fail_dma_shift                         (2)
#define BIST_DRF_FAIL_bist_drf_fail_27_2_shift                        (1)
#define BIST_DRF_FAIL_bist_drf_fail_27_1_shift                        (0)
#define BIST_DRF_FAIL_bist_drf_fail_out_mask                          (0x00000010)
#define BIST_DRF_FAIL_bist_drf_fail_fifo_mask                         (0x00000008)
#define BIST_DRF_FAIL_bist_drf_fail_dma_mask                          (0x00000004)
#define BIST_DRF_FAIL_bist_drf_fail_27_2_mask                         (0x00000002)
#define BIST_DRF_FAIL_bist_drf_fail_27_1_mask                         (0x00000001)
#define BIST_DRF_FAIL_bist_drf_fail_out(data)                         (0x00000010&((data)<<4))
#define BIST_DRF_FAIL_bist_drf_fail_fifo(data)                        (0x00000008&((data)<<3))
#define BIST_DRF_FAIL_bist_drf_fail_dma(data)                         (0x00000004&((data)<<2))
#define BIST_DRF_FAIL_bist_drf_fail_27_2(data)                        (0x00000002&((data)<<1))
#define BIST_DRF_FAIL_bist_drf_fail_27_1(data)                        (0x00000001&(data))
#define BIST_DRF_FAIL_get_bist_drf_fail_out(data)                     ((0x00000010&(data))>>4)
#define BIST_DRF_FAIL_get_bist_drf_fail_fifo(data)                    ((0x00000008&(data))>>3)
#define BIST_DRF_FAIL_get_bist_drf_fail_dma(data)                     ((0x00000004&(data))>>2)
#define BIST_DRF_FAIL_get_bist_drf_fail_27_2(data)                    ((0x00000002&(data))>>1)
#define BIST_DRF_FAIL_get_bist_drf_fail_27_1(data)                    (0x00000001&(data))


#define BIST_FAIL_27_1                                                0x180197c0
#define BIST_FAIL_27_1_reg_addr                                       "0xb80197c0"
#define BIST_FAIL_27_1_reg                                            0xb80197c0
#define BIST_FAIL_27_1_inst_addr                                      "0x01F0"
#define BIST_FAIL_27_1_inst                                           0x01F0
#define BIST_FAIL_27_1_bist_mem_fail_27_1_3_0_shift                   (0)
#define BIST_FAIL_27_1_bist_mem_fail_27_1_3_0_mask                    (0x0000000F)
#define BIST_FAIL_27_1_bist_mem_fail_27_1_3_0(data)                   (0x0000000F&(data))
#define BIST_FAIL_27_1_get_bist_mem_fail_27_1_3_0(data)               (0x0000000F&(data))


#define BIST_FAIL_27_2                                                0x180197c4
#define BIST_FAIL_27_2_reg_addr                                       "0xb80197c4"
#define BIST_FAIL_27_2_reg                                            0xb80197c4
#define BIST_FAIL_27_2_inst_addr                                      "0x01F1"
#define BIST_FAIL_27_2_inst                                           0x01F1
#define BIST_FAIL_27_2_bist_mem_fail_27_2_7_0_shift                   (0)
#define BIST_FAIL_27_2_bist_mem_fail_27_2_7_0_mask                    (0x000000FF)
#define BIST_FAIL_27_2_bist_mem_fail_27_2_7_0(data)                   (0x000000FF&(data))
#define BIST_FAIL_27_2_get_bist_mem_fail_27_2_7_0(data)               (0x000000FF&(data))


#define BIST_FAIL_DMA                                                 0x180197c8
#define BIST_FAIL_DMA_reg_addr                                        "0xb80197c8"
#define BIST_FAIL_DMA_reg                                             0xb80197c8
#define BIST_FAIL_DMA_inst_addr                                       "0x01F2"
#define BIST_FAIL_DMA_inst                                            0x01F2
#define BIST_FAIL_DMA_bist_mem_fail_dma_4_0_shift                     (0)
#define BIST_FAIL_DMA_bist_mem_fail_dma_4_0_mask                      (0x0000001F)
#define BIST_FAIL_DMA_bist_mem_fail_dma_4_0(data)                     (0x0000001F&(data))
#define BIST_FAIL_DMA_get_bist_mem_fail_dma_4_0(data)                 (0x0000001F&(data))


#define BIST_FAIL_FIFO                                                0x180197cc
#define BIST_FAIL_FIFO_reg_addr                                       "0xb80197cc"
#define BIST_FAIL_FIFO_reg                                            0xb80197cc
#define BIST_FAIL_FIFO_inst_addr                                      "0x01F3"
#define BIST_FAIL_FIFO_inst                                           0x01F3
#define BIST_FAIL_FIFO_bist_mem_fail_fifo_1_0_shift                   (0)
#define BIST_FAIL_FIFO_bist_mem_fail_fifo_1_0_mask                    (0x00000003)
#define BIST_FAIL_FIFO_bist_mem_fail_fifo_1_0(data)                   (0x00000003&(data))
#define BIST_FAIL_FIFO_get_bist_mem_fail_fifo_1_0(data)               (0x00000003&(data))


#define BIST_FAIL_OUT                                                 0x180197d0
#define BIST_FAIL_OUT_reg_addr                                        "0xb80197d0"
#define BIST_FAIL_OUT_reg                                             0xb80197d0
#define BIST_FAIL_OUT_inst_addr                                       "0x01F4"
#define BIST_FAIL_OUT_inst                                            0x01F4
#define BIST_FAIL_OUT_bist_mem_fail_out_3_0_shift                     (0)
#define BIST_FAIL_OUT_bist_mem_fail_out_3_0_mask                      (0x0000000F)
#define BIST_FAIL_OUT_bist_mem_fail_out_3_0(data)                     (0x0000000F&(data))
#define BIST_FAIL_OUT_get_bist_mem_fail_out_3_0(data)                 (0x0000000F&(data))


#define BIST_DRF_FAIL_27_1                                            0x180197d4
#define BIST_DRF_FAIL_27_1_reg_addr                                   "0xb80197d4"
#define BIST_DRF_FAIL_27_1_reg                                        0xb80197d4
#define BIST_DRF_FAIL_27_1_inst_addr                                  "0x01F5"
#define BIST_DRF_FAIL_27_1_inst                                       0x01F5
#define BIST_DRF_FAIL_27_1_bist_drf_mem_fail_27_1_3_0_shift           (0)
#define BIST_DRF_FAIL_27_1_bist_drf_mem_fail_27_1_3_0_mask            (0x0000000F)
#define BIST_DRF_FAIL_27_1_bist_drf_mem_fail_27_1_3_0(data)           (0x0000000F&(data))
#define BIST_DRF_FAIL_27_1_get_bist_drf_mem_fail_27_1_3_0(data)       (0x0000000F&(data))


#define BIST_DRF_FAIL_27_2                                            0x180197d8
#define BIST_DRF_FAIL_27_2_reg_addr                                   "0xb80197d8"
#define BIST_DRF_FAIL_27_2_reg                                        0xb80197d8
#define BIST_DRF_FAIL_27_2_inst_addr                                  "0x01F6"
#define BIST_DRF_FAIL_27_2_inst                                       0x01F6
#define BIST_DRF_FAIL_27_2_bist_drf_mem_fail_27_2_7_0_shift           (0)
#define BIST_DRF_FAIL_27_2_bist_drf_mem_fail_27_2_7_0_mask            (0x000000FF)
#define BIST_DRF_FAIL_27_2_bist_drf_mem_fail_27_2_7_0(data)           (0x000000FF&(data))
#define BIST_DRF_FAIL_27_2_get_bist_drf_mem_fail_27_2_7_0(data)       (0x000000FF&(data))


#define BIST_DRF_FAIL_DMA                                             0x180197dc
#define BIST_DRF_FAIL_DMA_reg_addr                                    "0xb80197dc"
#define BIST_DRF_FAIL_DMA_reg                                         0xb80197dc
#define BIST_DRF_FAIL_DMA_inst_addr                                   "0x01F7"
#define BIST_DRF_FAIL_DMA_inst                                        0x01F7
#define BIST_DRF_FAIL_DMA_bist_drf_mem_fail_dma_4_0_shift             (0)
#define BIST_DRF_FAIL_DMA_bist_drf_mem_fail_dma_4_0_mask              (0x0000001F)
#define BIST_DRF_FAIL_DMA_bist_drf_mem_fail_dma_4_0(data)             (0x0000001F&(data))
#define BIST_DRF_FAIL_DMA_get_bist_drf_mem_fail_dma_4_0(data)         (0x0000001F&(data))


#define BIST_DRF_FAIL_FIFO                                            0x180197e0
#define BIST_DRF_FAIL_FIFO_reg_addr                                   "0xb80197e0"
#define BIST_DRF_FAIL_FIFO_reg                                        0xb80197e0
#define BIST_DRF_FAIL_FIFO_inst_addr                                  "0x01F8"
#define BIST_DRF_FAIL_FIFO_inst                                       0x01F8
#define BIST_DRF_FAIL_FIFO_bist_drf_mem_fail_fifo_1_0_shift           (0)
#define BIST_DRF_FAIL_FIFO_bist_drf_mem_fail_fifo_1_0_mask            (0x00000003)
#define BIST_DRF_FAIL_FIFO_bist_drf_mem_fail_fifo_1_0(data)           (0x00000003&(data))
#define BIST_DRF_FAIL_FIFO_get_bist_drf_mem_fail_fifo_1_0(data)       (0x00000003&(data))


#define BIST_DRF_FAIL_OUT                                             0x180197e4
#define BIST_DRF_FAIL_OUT_reg_addr                                    "0xb80197e4"
#define BIST_DRF_FAIL_OUT_reg                                         0xb80197e4
#define BIST_DRF_FAIL_OUT_inst_addr                                   "0x01F9"
#define BIST_DRF_FAIL_OUT_inst                                        0x01F9
#define BIST_DRF_FAIL_OUT_bist_drf_mem_fail_out_3_0_shift             (0)
#define BIST_DRF_FAIL_OUT_bist_drf_mem_fail_out_3_0_mask              (0x0000000F)
#define BIST_DRF_FAIL_OUT_bist_drf_mem_fail_out_3_0(data)             (0x0000000F&(data))
#define BIST_DRF_FAIL_OUT_get_bist_drf_mem_fail_out_3_0(data)         (0x0000000F&(data))


#define BIST_DVSE_DVS                                                 0x180197e8
#define BIST_DVSE_DVS_reg_addr                                        "0xb80197e8"
#define BIST_DVSE_DVS_reg                                             0xb80197e8
#define BIST_DVSE_DVS_inst_addr                                       "0x01FA"
#define BIST_DVSE_DVS_inst                                            0x01FA
#define BIST_DVSE_DVS_mbist_dvs_out_shift                             (19)
#define BIST_DVSE_DVS_mbist_dvse_out_shift                            (18)
#define BIST_DVSE_DVS_mbist_dvs_fifo_shift                            (15)
#define BIST_DVSE_DVS_mbist_dvse_fifo_shift                           (14)
#define BIST_DVSE_DVS_mbist_dvs_dma_shift                             (11)
#define BIST_DVSE_DVS_mbist_dvse_dma_shift                            (10)
#define BIST_DVSE_DVS_mbist_dvs_27_2_shift                            (6)
#define BIST_DVSE_DVS_mbist_dvse_27_2_shift                           (5)
#define BIST_DVSE_DVS_mbist_dvs_27_1_shift                            (1)
#define BIST_DVSE_DVS_mbist_dvse_27_1_shift                           (0)
#define BIST_DVSE_DVS_mbist_dvs_out_mask                              (0x00780000)
#define BIST_DVSE_DVS_mbist_dvse_out_mask                             (0x00040000)
#define BIST_DVSE_DVS_mbist_dvs_fifo_mask                             (0x00038000)
#define BIST_DVSE_DVS_mbist_dvse_fifo_mask                            (0x00004000)
#define BIST_DVSE_DVS_mbist_dvs_dma_mask                              (0x00003800)
#define BIST_DVSE_DVS_mbist_dvse_dma_mask                             (0x00000400)
#define BIST_DVSE_DVS_mbist_dvs_27_2_mask                             (0x000003C0)
#define BIST_DVSE_DVS_mbist_dvse_27_2_mask                            (0x00000020)
#define BIST_DVSE_DVS_mbist_dvs_27_1_mask                             (0x0000001E)
#define BIST_DVSE_DVS_mbist_dvse_27_1_mask                            (0x00000001)
#define BIST_DVSE_DVS_mbist_dvs_out(data)                             (0x00780000&((data)<<19))
#define BIST_DVSE_DVS_mbist_dvse_out(data)                            (0x00040000&((data)<<18))
#define BIST_DVSE_DVS_mbist_dvs_fifo(data)                            (0x00038000&((data)<<15))
#define BIST_DVSE_DVS_mbist_dvse_fifo(data)                           (0x00004000&((data)<<14))
#define BIST_DVSE_DVS_mbist_dvs_dma(data)                             (0x00003800&((data)<<11))
#define BIST_DVSE_DVS_mbist_dvse_dma(data)                            (0x00000400&((data)<<10))
#define BIST_DVSE_DVS_mbist_dvs_27_2(data)                            (0x000003C0&((data)<<6))
#define BIST_DVSE_DVS_mbist_dvse_27_2(data)                           (0x00000020&((data)<<5))
#define BIST_DVSE_DVS_mbist_dvs_27_1(data)                            (0x0000001E&((data)<<1))
#define BIST_DVSE_DVS_mbist_dvse_27_1(data)                           (0x00000001&(data))
#define BIST_DVSE_DVS_get_mbist_dvs_out(data)                         ((0x00780000&(data))>>19)
#define BIST_DVSE_DVS_get_mbist_dvse_out(data)                        ((0x00040000&(data))>>18)
#define BIST_DVSE_DVS_get_mbist_dvs_fifo(data)                        ((0x00038000&(data))>>15)
#define BIST_DVSE_DVS_get_mbist_dvse_fifo(data)                       ((0x00004000&(data))>>14)
#define BIST_DVSE_DVS_get_mbist_dvs_dma(data)                         ((0x00003800&(data))>>11)
#define BIST_DVSE_DVS_get_mbist_dvse_dma(data)                        ((0x00000400&(data))>>10)
#define BIST_DVSE_DVS_get_mbist_dvs_27_2(data)                        ((0x000003C0&(data))>>6)
#define BIST_DVSE_DVS_get_mbist_dvse_27_2(data)                       ((0x00000020&(data))>>5)
#define BIST_DVSE_DVS_get_mbist_dvs_27_1(data)                        ((0x0000001E&(data))>>1)
#define BIST_DVSE_DVS_get_mbist_dvse_27_1(data)                       (0x00000001&(data))


#define ADC_UPDN_CTRL                                                 0x180197fc
#define ADC_UPDN_CTRL_reg_addr                                        "0xb80197fc"
#define ADC_UPDN_CTRL_reg                                             0xb80197fc
#define ADC_UPDN_CTRL_inst_addr                                       "0x01FF"
#define ADC_UPDN_CTRL_inst                                            0x01FF
#define ADC_UPDN_CTRL_adc_updn_debug_en_shift                         (2)
#define ADC_UPDN_CTRL_adc_updn_debug_up_shift                         (1)
#define ADC_UPDN_CTRL_adc_updn_debug_dn_shift                         (0)
#define ADC_UPDN_CTRL_adc_updn_debug_en_mask                          (0x00000004)
#define ADC_UPDN_CTRL_adc_updn_debug_up_mask                          (0x00000002)
#define ADC_UPDN_CTRL_adc_updn_debug_dn_mask                          (0x00000001)
#define ADC_UPDN_CTRL_adc_updn_debug_en(data)                         (0x00000004&((data)<<2))
#define ADC_UPDN_CTRL_adc_updn_debug_up(data)                         (0x00000002&((data)<<1))
#define ADC_UPDN_CTRL_adc_updn_debug_dn(data)                         (0x00000001&(data))
#define ADC_UPDN_CTRL_get_adc_updn_debug_en(data)                     ((0x00000004&(data))>>2)
#define ADC_UPDN_CTRL_get_adc_updn_debug_up(data)                     ((0x00000002&(data))>>1)
#define ADC_UPDN_CTRL_get_adc_updn_debug_dn(data)                     (0x00000001&(data))
#endif
