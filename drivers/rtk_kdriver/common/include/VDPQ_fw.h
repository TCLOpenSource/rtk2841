// This file is generated using the spec version 1.39, firmware template version 1.39and SRIF Parser                                                                                source code SVN rev:798                    Version flow no.:1.1.55
#ifndef _VDPQ_REG_H_INCLUDED_
#define _VDPQ_REG_H_INCLUDED_

//#define  _VDPQ_USE_STRUCT
#ifdef _VDPQ_USE_STRUCT

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    f_num_chk_3d_sel:2;
    unsigned int    f_hennum_range:6;
}REG18019800;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    f_num_chk_3d_en:1;
    unsigned int    f_num_3d_fail_det:1;
    unsigned int    f_cennum_range:6;
}REG18019804;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    f_num_open3d_cnt:4;
    unsigned int    f_num_close3d_cnt:4;
}REG18019808;

typedef struct
{
    unsigned int    reserved_0:29;
    unsigned int    f_cennum_valid_en:1;
    unsigned int    f_cennum_valid1_en:1;
    unsigned int    f_cennum_valid2_en:1;
}REG1801980C;

typedef struct
{
    unsigned int    reserved_0:12;
    unsigned int    f_cennum_valid1_num:20;
}REG18019810;

typedef struct
{
    unsigned int    reserved_0:12;
    unsigned int    f_cennum_valid2_num:20;
}REG18019814;

typedef struct
{
    unsigned int    reserved_0:30;
    unsigned int    f_hennum_valid_en:1;
    unsigned int    f_hennum_valid1_en:1;
}REG18019818;

typedef struct
{
    unsigned int    reserved_0:12;
    unsigned int    f_hennum_valid1_num:20;
}REG1801981C;

typedef struct
{
    unsigned int    reserved_0:22;
    unsigned int    vactive_st1:10;
}REG18019830;

typedef struct
{
    unsigned int    reserved_0:22;
    unsigned int    vactive_end1:10;
}REG18019834;

typedef struct
{
    unsigned int    reserved_0:22;
    unsigned int    vactive_st2:10;
}REG18019838;

typedef struct
{
    unsigned int    reserved_0:22;
    unsigned int    vactive_end2:10;
}REG1801983C;

typedef struct
{
    unsigned int    reserved_0:26;
    unsigned int    dma_ctrl_ififo_thr:6;
}REG18019840;

typedef struct
{
    unsigned int    reserved_0:26;
    unsigned int    dma_ctrl_ofifo_thr:6;
}REG18019844;

typedef struct
{
    unsigned int    reserved_0:26;
    unsigned int    dma_ctrl_ceiladr:6;
}REG18019848;

typedef struct
{
    unsigned int    dma_3d_on_off:1;
    unsigned int    ntsc443_tune:3;
    unsigned int    reserved_0:2;
    unsigned int    dma_vcnt_diff:10;
    unsigned int    dma_vcnt_sft_chk_en:1;
    unsigned int    reserved_1:2;
    unsigned int    dma_vcnt_sft_thr:5;
    unsigned int    dma_3d_on_vcnt:5;
    unsigned int    dma_ctrl_bstlen:3;
}REG1801984C;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    ofifo_err_flag:1;
    unsigned int    ififo_err_flag_1:1;
    unsigned int    ififo_err_flag_2:1;
    unsigned int    ififo_err_flag_3:1;
    unsigned int    ififo_err_flag_4:1;
    unsigned int    mem_off:1;
    unsigned int    mem_test_mode:1;
    unsigned int    mem_test_mode_ok:1;
}REG18019850;

typedef struct
{
    unsigned int    reserved_0:29;
    unsigned int    dma_field_inv:1;
    unsigned int    dma_adc_in_en:1;
    unsigned int    dma_adc_in_sel:1;
}REG18019854;

typedef struct
{
    unsigned int    reserved_0:21;
    unsigned int    dma_debugif_stline_en:1;
    unsigned int    dma_debugif_stline:10;
}REG18019858;

typedef struct
{
    unsigned int    reserved_0:30;
    unsigned int    vlpf_sram_bypass:1;
    unsigned int    vd_sram_on_off:1;
}REG1801985C;

typedef struct
{
    unsigned int    reserved_0:3;
    unsigned int    frame_addr0:29;
}REG18019870;

typedef struct
{
    unsigned int    reserved_0:3;
    unsigned int    frame_addr1:29;
}REG18019874;

typedef struct
{
    unsigned int    reserved_0:3;
    unsigned int    frame_addr2:29;
}REG18019878;

typedef struct
{
    unsigned int    reserved_0:3;
    unsigned int    frame_addr3:29;
}REG1801987C;

typedef struct
{
    unsigned int    reserved_0:3;
    unsigned int    frame_addr0_end:29;
}REG18019880;

typedef struct
{
    unsigned int    reserved_0:3;
    unsigned int    frame_addr1_end:29;
}REG18019884;

typedef struct
{
    unsigned int    reserved_0:3;
    unsigned int    frame_addr2_end:29;
}REG18019888;

typedef struct
{
    unsigned int    reserved_0:3;
    unsigned int    frame_addr3_end:29;
}REG1801988C;

typedef struct
{
    unsigned int    reserved_0:3;
    unsigned int    dma_debug_adr:29;
}REG18019890;

typedef struct
{
    unsigned int    reserved_0:3;
    unsigned int    dma_debug_vbiend_adr:29;
}REG18019894;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    dma_debug_vd_sel:4;
    unsigned int    dma_mode:1;
    unsigned int    dma_debugmode_sel:2;
    unsigned int    dma_debugmode_en:1;
}REG18019898;

typedef struct
{
    unsigned int    reserved_0:25;
    unsigned int    dma_debug_one_rw_rlt:1;
    unsigned int    dma_debug_rw_en:2;
    unsigned int    reserved_1:4;
}REG1801989C;

typedef struct
{
    unsigned int    calib_delay_hsync_en:1;
    unsigned int    chase_line_pos_en:2;
    unsigned int    calib_delay_frame_sel:1;
    unsigned int    calib_delay_sel:1;
    unsigned int    calib_delay_en:1;
    unsigned int    dma_pix_sht_fix_en:1;
    unsigned int    chase_per_frame_en:1;
    unsigned int    chase_pix_num:4;
    unsigned int    pix_sht_st_th:20;
}REG180198A0;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    fscnum_dif_abs_sel:2;
    unsigned int    pix_sht_limit_en:1;
    unsigned int    pix_sht_limit_th:8;
    unsigned int    pix_sht_end_th:20;
}REG180198A4;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    fscdif_num_abs:6;
    unsigned int    reserved_1:4;
    unsigned int    fscdif_sum_abs:20;
}REG180198A8;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    f1_cennum:16;
}REG180198D0;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    f2_cennum:16;
}REG180198D4;

typedef struct
{
    unsigned int    dummy_1:32;
}REG180198D8;

typedef struct
{
    unsigned int    yc3d_tb_en:1;
    unsigned int    reserved_0:26;
    unsigned int    yc_linebf_sel:1;
    unsigned int    yc_2d_decode_sel:1;
    unsigned int    adaptive_mode:3;
}REG18019900;

typedef struct
{
    unsigned int    reserved_0:20;
    unsigned int    wide_bpf_sel_y:4;
    unsigned int    mid_bpf_sel_y:4;
    unsigned int    narrow_bpf_sel_y:4;
}REG18019904;

typedef struct
{
    unsigned int    reserved_0:20;
    unsigned int    wide_bpf_sel_c:4;
    unsigned int    mid_bpf_sel_c:4;
    unsigned int    narrow_bpf_sel_c:4;
}REG18019908;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    h2v_lk_en:1;
    unsigned int    reserved_1:1;
    unsigned int    v2v_lk_y_en:1;
    unsigned int    v2v_lk_c_en:1;
    unsigned int    h2v_mid_sel_y:1;
    unsigned int    h2v_mid_sel_c:1;
    unsigned int    h2v_near_sel_y:1;
    unsigned int    h2v_near_sel_c:1;
}REG1801990C;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    h2v_vflag_remag_thr:4;
    unsigned int    h2v_vflag_mag_thr:4;
}REG18019910;

typedef struct
{
    unsigned int    reserved_0:25;
    unsigned int    pal_perr:1;
    unsigned int    pal_perr_auto_en:1;
    unsigned int    reserved_1:3;
    unsigned int    palsw_level:2;
}REG18019914;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    noise_ntsc_c:8;
}REG18019918;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    malpha_c_divider2_sel:1;
    unsigned int    malpha_y_divider2_sel:1;
    unsigned int    malpha_y_en:1;
    unsigned int    malpha_y:1;
    unsigned int    malpha_c_en:1;
    unsigned int    malpha_c:1;
    unsigned int    yalpha_en:1;
    unsigned int    yalpha:1;
}REG18019928;

typedef struct
{
    unsigned int    reserved_0:25;
    unsigned int    pal_demod_sel:1;
    unsigned int    reserved_1:2;
    unsigned int    chroma_vlpf_en:1;
    unsigned int    chroma_bw_lo:3;
}REG1801992C;

typedef struct
{
    unsigned int    reserved_0:27;
    unsigned int    debug_mode_2d_en:1;
    unsigned int    debug_mode_2d:4;
}REG18019930;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    bw_gain_sel:2;
    unsigned int    bw_detect_thr:6;
}REG18019934;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    bw_edge_thr:8;
}REG18019938;

typedef struct
{
    unsigned int    reserved_0:23;
    unsigned int    same_phase_diff_1d_gauge_en:1;
    unsigned int    reserved_1:1;
    unsigned int    blend_1d_thr:5;
    unsigned int    bpf_1d_sel_y:2;
}REG1801993C;

typedef struct
{
    unsigned int    reserved_0:25;
    unsigned int    narrow_1d_bpf_sel_c:3;
    unsigned int    reserved_1:1;
    unsigned int    wide_1d_bpf_sel_c:3;
}REG18019940;

typedef struct
{
    unsigned int    force_halpha_en:1;
    unsigned int    reserved_0:3;
    unsigned int    halpha:4;
    unsigned int    reserved_1:3;
    unsigned int    lut_large_th:5;
    unsigned int    lut_fuzzy_th:4;
    unsigned int    reserved_2:1;
    unsigned int    lut_sel_y:3;
    unsigned int    reserved_3:1;
    unsigned int    lut_sel_c:3;
    unsigned int    reserved_4:1;
    unsigned int    h2v_coring_thr:3;
}REG18019944;

typedef struct
{
    unsigned int    reserved_0:25;
    unsigned int    h2v_cvbs_coring_thr:3;
    unsigned int    h2v_bw_color_gain:4;
}REG18019948;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    h2v_y_noise_thr:8;
}REG1801994C;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    h2v_cvbs_noise_thr:8;
}REG18019950;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    h2v_noise_max_hdy:8;
}REG18019954;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    v2v_noise_y_add_dc:8;
}REG18019958;

typedef struct
{
    unsigned int    reserved_0:29;
    unsigned int    h2v_blendratio:3;
}REG1801995C;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    xc_sel_gain:2;
    unsigned int    reserved_1:2;
    unsigned int    y_uniform_thr:4;
}REG18019960;

typedef struct
{
    unsigned int    reserved_0:10;
    unsigned int    cdiff_bpf_mm_small_th:6;
    unsigned int    cdiff_bpf_mm_diff_th:8;
    unsigned int    reserved_1:2;
    unsigned int    cdiff_bpf_hor_range:1;
    unsigned int    cdiff_bpf_ver_range:1;
    unsigned int    reserved_2:2;
    unsigned int    cdiff_bpf_sel_c_en:1;
    unsigned int    cdiff_bpf_sel_y_en:1;
}REG18019964;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    cdiff_bpf_vspd_small_th:6;
    unsigned int    reserved_1:2;
    unsigned int    cdiff_bpf_low_sat_th:6;
    unsigned int    cdiff_bpf_large_offset:4;
    unsigned int    reserved_2:1;
    unsigned int    cdiff_bpf_large_amp_wei:3;
    unsigned int    cdiff_bpf_small_offset:4;
    unsigned int    reserved_3:1;
    unsigned int    cdiff_bpf_small_amp_wei:3;
}REG18019968;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    hvdiff_comp_offset:8;
    unsigned int    hvdiff_comp_multiple:4;
    unsigned int    reserved_1:3;
    unsigned int    diff_tolerance:5;
    unsigned int    reserved_2:3;
    unsigned int    vedge_en:1;
}REG18019970;

typedef struct
{
    unsigned int    reserved_0:15;
    unsigned int    c_follow_y_en:1;
    unsigned int    reserved_1:1;
    unsigned int    hdiff_lowbound:7;
    unsigned int    reserved_2:3;
    unsigned int    vdiff_upbound:5;
}REG18019974;

typedef struct
{
    unsigned int    reserved_0:26;
    unsigned int    diamc_cvbsamp_still_th:6;
}REG1801999C;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    diamc_dc_still_th_offset:6;
    unsigned int    diamc_dc_still_th_weight:4;
    unsigned int    reserved_1:2;
    unsigned int    diamc_y_v_line_id_cnt_th:2;
    unsigned int    reserved_2:1;
    unsigned int    diamc_fid_th_weight:3;
    unsigned int    reserved_3:1;
    unsigned int    diamc_amp_low_bnd:7;
    unsigned int    reserved_4:1;
    unsigned int    diamc_all_line_match_en:1;
    unsigned int    diamc_perfect_fid_en:1;
    unsigned int    diamc_en:1;
}REG180199A0;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    ver_cvbsamp_still_th:6;
    unsigned int    reserved_1:3;
    unsigned int    vmc_cfollowy_en:1;
    unsigned int    reserved_2:1;
    unsigned int    ver_dc_still_th:7;
    unsigned int    reserved_3:2;
    unsigned int    amp_low_bnd:6;
    unsigned int    reserved_4:1;
    unsigned int    slant_det_en:1;
    unsigned int    perfect_fid_en:1;
    unsigned int    vmc_en:1;
}REG180199A4;

typedef struct
{
    unsigned int    reserved_0:17;
    unsigned int    offset_2:3;
    unsigned int    reserved_1:2;
    unsigned int    offset_1:2;
    unsigned int    cnt_th_2:4;
    unsigned int    cnt_th_1:4;
}REG180199A8;

typedef struct
{
    unsigned int    reserved_0:25;
    unsigned int    postp_adapmode:2;
    unsigned int    newadap2d_en:1;
    unsigned int    postp_passnoedg:1;
    unsigned int    yc2d_postp_filter_sel:1;
    unsigned int    postp_adap_en:1;
    unsigned int    yc2d_postp_en:1;
}REG180199D0;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    edgdet_hlo:8;
    unsigned int    edgdet_vlo:8;
}REG180199D4;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    blend_upbnd:8;
}REG180199D8;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    blend_seg3:8;
    unsigned int    blend_seg2:8;
    unsigned int    blend_seg1:8;
}REG180199DC;

typedef struct
{
    unsigned int    cblend_upbnd:8;
    unsigned int    cblend_seg3:8;
    unsigned int    cblend_seg2:8;
    unsigned int    cblend_seg1:8;
}REG180199E0;

typedef struct
{
    unsigned int    dummy_2:32;
}REG18019AFC;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    yc3d_motion_inc_status_15_8:8;
}REG18019B00;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    yc3d_motion_inc_status_7_0:8;
}REG18019B04;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    yc3d_mov_multi_en:1;
    unsigned int    yc3d_multib_det:1;
    unsigned int    yc3d_multi_th1:6;
}REG18019B08;

typedef struct
{
    unsigned int    reserved_0:26;
    unsigned int    yc3d_multi_th2:6;
}REG18019B0C;

typedef struct
{
    unsigned int    reserved_0:26;
    unsigned int    yc3d_multi_th3:6;
}REG18019B10;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    yc3d_trend_mode_sel:1;
    unsigned int    yc3d_trend_adap_en:1;
    unsigned int    yc3d_trend_2d_en:1;
    unsigned int    reserved_1:3;
    unsigned int    yc3d_trend_2d_ratio:2;
}REG18019B14;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    yc3d_trend_a_multiple:4;
    unsigned int    yc3d_trend_b_multiple:4;
}REG18019B18;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    yc3d_trend_c_multiple:4;
    unsigned int    yc3d_trend_d_multiple:4;
}REG18019B1C;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    yc3d_y2d_diff_th:8;
}REG18019B20;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    yc3d_c2d_diff_th:8;
}REG18019B24;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    yc3d_sep_mode1:1;
    unsigned int    yc3d_sep_mode2:1;
    unsigned int    yc_sep_current_sel:1;
    unsigned int    pal_mod_inv:1;
    unsigned int    reserved_1:2;
    unsigned int    yc_sep_mode:2;
}REG18019B28;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    yc3d_debug_en:1;
    unsigned int    reserved_1:3;
    unsigned int    yc3d_debug_mode:4;
}REG18019B2C;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    yc3d_cchroma_bpf_sel:1;
    unsigned int    yc3d_ychroma_bpf_sel:1;
    unsigned int    yc3d_trend_th1:6;
}REG18019B30;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    yc3d_trend_tight_en:1;
    unsigned int    yc3d_trend_th:7;
}REG18019B34;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    yc3d_frame_motion_th:8;
}REG18019B38;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    yc3d_ylo_diff_th1:8;
}REG18019B3C;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    yc3d_ylo_diff_th2:8;
}REG18019B40;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    yc3d_c_bpf_diff_th:8;
}REG18019B44;

typedef struct
{
    unsigned int    reserved_0:27;
    unsigned int    yc3d_trend_like_sum_th1:5;
}REG18019B48;

typedef struct
{
    unsigned int    reserved_0:27;
    unsigned int    yc3d_trend_like_sum_th2:5;
}REG18019B4C;

typedef struct
{
    unsigned int    reserved_0:27;
    unsigned int    yc3d_trend_like_sum_th3:5;
}REG18019B50;

typedef struct
{
    unsigned int    reserved_0:27;
    unsigned int    yc3d_trend_like_sum_th4:5;
}REG18019B54;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    yc3d_magln_det_en:1;
    unsigned int    yc3d_magln_det_status:1;
    unsigned int    yc3d_trend_lpf_sel:2;
    unsigned int    yc3d_trend_tb:2;
    unsigned int    yc3d_trend_cbpf_tb:2;
}REG18019B58;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    yc3d_magln_th1:4;
    unsigned int    yc3d_magln_th2:4;
}REG18019B5C;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    yc3d_magln_sum_th1:4;
    unsigned int    yc3d_magln_sum_th2:4;
}REG18019B60;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    yc3d_chk_prev_frame:2;
    unsigned int    reserved_1:2;
    unsigned int    yc3d_motion_coring:4;
}REG18019B64;

typedef struct
{
    unsigned int    dummy_3:32;
}REG18019B68;

typedef struct
{
    unsigned int    dummy_4:32;
}REG18019B6C;

typedef struct
{
    unsigned int    yc3d_ets_debug_en:1;
    unsigned int    reserved_0:26;
    unsigned int    yc3d_ets_debug_mode:5;
}REG18019C00;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    yc3d_sep_mode_pal:1;
    unsigned int    yc3d_et_3d_dir:2;
    unsigned int    reserved_1:16;
    unsigned int    yc3d_et_wise_ignore_lsb_en:1;
    unsigned int    yc3d_et_wise_amp_en:1;
    unsigned int    yc3d_et_wise_near_only:1;
    unsigned int    yc3d_et_wise_1d_crct_en:1;
    unsigned int    reserved_2:1;
    unsigned int    yc3d_et_wise_en:1;
    unsigned int    yc3d_et_edge_c3d:1;
    unsigned int    yc3d_et_c2d_en:1;
    unsigned int    reserved_3:1;
    unsigned int    yc3d_et_nedgepair_en:1;
    unsigned int    yc3d_et_y_time_cnt_strict_en:1;
    unsigned int    yc3d_et_etstill_en:1;
}REG18019C04;

typedef struct
{
    unsigned int    reserved_0:12;
    unsigned int    yc3d_et_alpha_th5:4;
    unsigned int    yc3d_et_alpha_th4:4;
    unsigned int    yc3d_et_alpha_th3:4;
    unsigned int    yc3d_et_alpha_th2:4;
    unsigned int    yc3d_et_alpha_th1:4;
}REG18019C08;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    yc3d_et_nedge_cnt_th:4;
    unsigned int    yc3d_et_match_cnt_th:4;
}REG18019C0C;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    yc3d_et_sobel_ths:8;
    unsigned int    yc3d_et_sobel_thm:8;
}REG18019C10;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    yc3d_et_c2d_cnt_th:4;
    unsigned int    reserved_1:4;
    unsigned int    yc3d_et_c3d_cnt_th:4;
    unsigned int    yc3d_et_c2d_like_th:8;
    unsigned int    yc3d_et_c3d_diff_th:8;
}REG18019C14;

typedef struct
{
    unsigned int    reserved_0:20;
    unsigned int    yc3d_et_2pair_cnt_th:4;
    unsigned int    yc3d_et_2pair_diff_th:8;
}REG18019C18;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    yc3d_et_wise_amp_th_big:8;
}REG18019C1C;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    yc3d_ets_wise_pse_en:1;
    unsigned int    yc3d_wise_pse_cnt_window_sel:1;
    unsigned int    reserved_1:1;
    unsigned int    yc3d_wise_pse_cnt_th:5;
}REG18019C20;

typedef struct
{
    unsigned int    reserved_0:27;
    unsigned int    yc3d_ets_wise_pse_ths:5;
}REG18019C24;

typedef struct
{
    unsigned int    reserved_0:27;
    unsigned int    yc3d_ets_wise_pse_thd:5;
}REG18019C28;

typedef struct
{
    unsigned int    reserved_0:26;
    unsigned int    yc3d_ets_wise_pse_avg_th1:6;
}REG18019C2C;

typedef struct
{
    unsigned int    reserved_0:26;
    unsigned int    yc3d_ets_wise_pse_avg_th2:6;
}REG18019C30;

typedef struct
{
    unsigned int    reserved_0:9;
    unsigned int    yc3d_ets_wise_pse_com3:7;
    unsigned int    reserved_1:1;
    unsigned int    yc3d_ets_wise_pse_com2:7;
    unsigned int    reserved_2:1;
    unsigned int    yc3d_ets_wise_pse_com1:7;
}REG18019C34;

typedef struct
{
    unsigned int    yc3d_ver_hifreq_sel:1;
    unsigned int    reserved_0:2;
    unsigned int    yc3d_ets_wise_pse_ths_up:9;
    unsigned int    reserved_1:3;
    unsigned int    yc3d_fifd_noise_offset:5;
    unsigned int    reserved_2:12;
}REG18019C68;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    yc3d_ets_far_still_th:6;
    unsigned int    reserved_1:8;
    unsigned int    yc3d_ets_far_still_com_en:1;
    unsigned int    yc3d_ets_cvbs_far_still_com:7;
    unsigned int    reserved_2:3;
    unsigned int    yc3d_ets_np_no_palmode_sel:1;
    unsigned int    yc3d_ets_em_no_palmode:1;
    unsigned int    yc3d_ets_em_pse_en:1;
    unsigned int    yc3d_ets_np_no_palmode:1;
    unsigned int    yc3d_ets_np_pse_en:1;
}REG18019C6C;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    yc3d_et_hifreq_adjust_wise_gain:3;
    unsigned int    reserved_1:1;
    unsigned int    yc3d_et_hifreq_adjust_c2d_gain:3;
    unsigned int    reserved_2:1;
    unsigned int    yc3d_et_hifreq_adjust_c3d_gain:3;
    unsigned int    reserved_3:2;
    unsigned int    yc3d_et_hifreq_adjust_wise_hv:2;
    unsigned int    yc3d_et_hifreq_adjust_c2d_hv:2;
    unsigned int    yc3d_et_hifreq_adjust_c3d_hv:2;
    unsigned int    yc3d_et_hor_hifreq_range:1;
    unsigned int    yc3d_et_ver_hifreq_ext_range:3;
    unsigned int    reserved_4:1;
    unsigned int    yc3d_et_hifreq_adjust_wise:1;
    unsigned int    yc3d_et_hifreq_adjust_c2d:1;
    unsigned int    yc3d_et_hifreq_adjust_c3d:1;
    unsigned int    reserved_5:1;
    unsigned int    yc3d_et_hifreq_disable_wise:1;
    unsigned int    yc3d_et_hifreq_disable_c2d:1;
    unsigned int    yc3d_et_hifreq_disable_c3d:1;
}REG18019CF8;

typedef struct
{
    unsigned int    reserved_0:7;
    unsigned int    yc3d_hor_hifreq_th:9;
    unsigned int    reserved_1:7;
    unsigned int    yc3d_ver_hifreq_th:9;
}REG18019CFC;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    yc3d_grid_hifreq_sum_up_down_th:8;
    unsigned int    reserved_1:2;
    unsigned int    yc3d_grid_hifreq_sad_th:6;
    unsigned int    yc3d_grid_hifreq_th:8;
    unsigned int    reserved_2:3;
    unsigned int    yc3d_grid_hifreq_sel:1;
}REG18019D00;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    yc3d_et_chifreq_ave_min:4;
    unsigned int    yc3d_et_hor_chifreq_th_offset:4;
    unsigned int    yc3d_et_ver_chifreq_th_offset:4;
    unsigned int    reserved_1:2;
    unsigned int    yc3d_et_ver_chifreq_range:1;
    unsigned int    yc3d_et_hor_chifreq_range:1;
    unsigned int    reserved_2:1;
    unsigned int    yc3d_et_ver_chifreq_ext_range:3;
    unsigned int    reserved_3:1;
    unsigned int    yc3d_et_hor_chifreq_ave_div:1;
    unsigned int    yc3d_et_ver_chifreq_ave_div:1;
    unsigned int    yc3d_chifreq_fixth_en:1;
    unsigned int    reserved_4:1;
    unsigned int    yc3d_et_chifreq_disable_wise:1;
    unsigned int    yc3d_et_chifreq_disable_c2d:1;
    unsigned int    yc3d_et_chifreq_disable_c3d:1;
}REG18019D04;

typedef struct
{
    unsigned int    reserved_0:7;
    unsigned int    yc3d_hor_chifreq_th:9;
    unsigned int    reserved_1:7;
    unsigned int    yc3d_ver_chifreq_th:9;
}REG18019D08;

typedef struct
{
    unsigned int    yc3d_nedge_mode_sel:2;
    unsigned int    reserved_0:5;
    unsigned int    yc3d_pair_hor_chifreq_th:9;
    unsigned int    yc3d_pair_chifreq_ave_min:4;
    unsigned int    yc3d_et_pair_chifreq_ext_range:3;
    unsigned int    yc3d_pair_ver_chifreq_th:9;
}REG18019D0C;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    yc3d_fifd_iidd_th_offset:3;
    unsigned int    reserved_1:3;
    unsigned int    yc3d_fifd_corr_cnt_th:5;
    unsigned int    reserved_2:3;
    unsigned int    yc3d_fifd_spa_2d_corr:1;
    unsigned int    reserved_3:1;
    unsigned int    yc3d_fifd_ext_num:3;
    unsigned int    yc3d_fifd_match_cnt_th:4;
    unsigned int    yc3d_fifd_later_style_en:1;
    unsigned int    yc3d_fifd_temp_style_detection_en:1;
    unsigned int    yc3d_fifd_amp_diff_en:1;
    unsigned int    yc3d_fifd_same_style_grid_detection:1;
    unsigned int    yc3d_fifd_grid_content_detection:1;
    unsigned int    yc3d_iidd_en:1;
    unsigned int    yc3d_et_hifreq_disable_fifd:1;
    unsigned int    yc3d_fifd_en:1;
}REG18019D10;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    yc3d_fifd_same_style_grid_th:8;
    unsigned int    reserved_1:7;
    unsigned int    yc3d_fifd_amp_diff_th:9;
}REG18019D14;

typedef struct
{
    unsigned int    yc3d_fifd_amp_diff_th_offset:8;
    unsigned int    yc3d_fifd_large_c_th:8;
    unsigned int    yc3d_fifd_c_diff_th:8;
    unsigned int    reserved_0:1;
    unsigned int    yc3d_fifd_left_right_multiple:3;
    unsigned int    reserved_1:2;
    unsigned int    yc3d_fifd_ver_grid_hifreq_amp_th_en:1;
    unsigned int    yc3d_fifd_ada_amp_th_en:1;
}REG18019D18;

typedef struct
{
    unsigned int    dummy_5:32;
}REG18019D1C;

typedef struct
{
    unsigned int    dummy_6:32;
}REG18019D20;

typedef struct
{
    unsigned int    f4_en:1;
    unsigned int    reserved_0:1;
    unsigned int    f4_global_diff_dbg_sftbit:2;
    unsigned int    f4_dbg_highfreq_diff_th:8;
    unsigned int    f4_dbg_cvbs_amp_th:8;
    unsigned int    reserved_1:3;
    unsigned int    f4_debug_en:1;
    unsigned int    reserved_2:3;
    unsigned int    f4_debug_mode_sel:5;
}REG18019D24;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    cvbs_amp_change_th:7;
    unsigned int    reserved_1:4;
    unsigned int    f4_3d_spatial_cnt_th_5:4;
    unsigned int    f4_3d_spatial_cnt_th_4:4;
    unsigned int    f4_3d_spatial_cnt_th_3:4;
    unsigned int    f4_3d_spatial_cnt_th_2:4;
    unsigned int    f4_3d_spatial_cnt_th_1:4;
}REG18019D28;

typedef struct
{
    unsigned int    reserved_0:9;
    unsigned int    hv_cvbs_diff_large_multiple_th:3;
    unsigned int    reserved_1:1;
    unsigned int    hv_diff_large_multiple_th:3;
    unsigned int    reserved_2:2;
    unsigned int    hv_diff_large_offset_th:6;
    unsigned int    reserved_3:1;
    unsigned int    hv_local_diff_comp_ratio:3;
    unsigned int    hv_diff_tolerance:4;
}REG18019D2C;

typedef struct
{
    unsigned int    reserved_0:19;
    unsigned int    h_diff_normalize_en:1;
    unsigned int    reserved_1:3;
    unsigned int    hv_edge_c_diff_small_th:5;
    unsigned int    reserved_2:3;
    unsigned int    hv_edge_c_diff_small_en:1;
}REG18019D30;

typedef struct
{
    unsigned int    reserved_0:22;
    unsigned int    f4_fill_hole_neightbor_diff_th:6;
    unsigned int    f4_hor_chifreq_range:1;
    unsigned int    f4_ver_chifreq_range:1;
    unsigned int    f4_hor_hifreq_range:1;
    unsigned int    f4_ver_hifreq_usepalmode:1;
}REG18019D34;

typedef struct
{
    unsigned int    reserved_0:20;
    unsigned int    dc_level_change_th_multiple:4;
    unsigned int    reserved_1:2;
    unsigned int    dc_level_change_th_base:6;
}REG18019D38;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    similary_th_base:6;
    unsigned int    reserved_1:3;
    unsigned int    similary_th_multiple:5;
    unsigned int    palerr_accu_tolerance:4;
    unsigned int    reserved_2:2;
    unsigned int    palerr_hifreq_diff_large_th:6;
    unsigned int    reserved_3:3;
    unsigned int    pal_error_detect_en:1;
}REG18019D3C;

typedef struct
{
    unsigned int    reserved_0:3;
    unsigned int    diff_of_spd_small_th_base:5;
    unsigned int    reserved_1:3;
    unsigned int    diff_of_spd_small_th_multiple:5;
    unsigned int    reserved_2:3;
    unsigned int    massive_palmode_error_multiple_th:5;
    unsigned int    reserved_3:1;
    unsigned int    massive_palmode_error_large_th:7;
}REG18019D40;

typedef struct
{
    unsigned int    reserved_0:25;
    unsigned int    large_hor_spd_th:7;
}REG18019D44;

typedef struct
{
    unsigned int    sv_avg_dynamic_en:1;
    unsigned int    reserved_0:6;
    unsigned int    sv_vector_fid_match_cnt_th:5;
    unsigned int    sv_vector_fid_offset:4;
    unsigned int    reserved_1:3;
    unsigned int    sv_vector_large_cnt_th:5;
    unsigned int    reserved_2:3;
    unsigned int    sv_vector_large_th:5;
}REG18019D48;

typedef struct
{
    unsigned int    reserved_0:25;
    unsigned int    sv_self_diff_small_th:7;
}REG18019D4C;

typedef struct
{
    unsigned int    reserved_0:13;
    unsigned int    sghf_inter_diff_th:7;
    unsigned int    sghf_global_diff_small_th:8;
    unsigned int    reserved_1:3;
    unsigned int    sghf_longtime_en:1;
}REG18019D50;

typedef struct
{
    unsigned int    sghf_avg_dynamic_en:1;
    unsigned int    reserved_0:6;
    unsigned int    sghf_vector_fid_match_cnt_th:5;
    unsigned int    sghf_vector_fid_offset:4;
    unsigned int    reserved_1:3;
    unsigned int    sghf_vector_large_cnt_th:5;
    unsigned int    reserved_2:3;
    unsigned int    sghf_vector_large_th:5;
}REG18019D54;

typedef struct
{
    unsigned int    reserved_0:3;
    unsigned int    diff_th_multiple_140:5;
    unsigned int    reserved_1:3;
    unsigned int    diff_th_multiple_160:5;
    unsigned int    reserved_2:3;
    unsigned int    diff_th_multiple_180:5;
    unsigned int    reserved_3:3;
    unsigned int    diff_th_multiple_200:5;
}REG18019D58;

typedef struct
{
    unsigned int    reserved_0:3;
    unsigned int    diff_th_multiple_60:5;
    unsigned int    reserved_1:3;
    unsigned int    diff_th_multiple_80:5;
    unsigned int    reserved_2:3;
    unsigned int    diff_th_multiple_100:5;
    unsigned int    reserved_3:3;
    unsigned int    diff_th_multiple_120:5;
}REG18019D5C;

typedef struct
{
    unsigned int    reserved_0:3;
    unsigned int    diff_th_multiple_0:5;
    unsigned int    reserved_1:3;
    unsigned int    diff_th_multiple_10:5;
    unsigned int    reserved_2:3;
    unsigned int    diff_th_multiple_20:5;
    unsigned int    reserved_3:3;
    unsigned int    diff_th_multiple_40:5;
}REG18019D60;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    diff_th_base_140:6;
    unsigned int    reserved_1:2;
    unsigned int    diff_th_base_160:6;
    unsigned int    reserved_2:2;
    unsigned int    diff_th_base_180:6;
    unsigned int    reserved_3:2;
    unsigned int    diff_th_base_200:6;
}REG18019D64;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    diff_th_base_60:6;
    unsigned int    reserved_1:2;
    unsigned int    diff_th_base_80:6;
    unsigned int    reserved_2:2;
    unsigned int    diff_th_base_100:6;
    unsigned int    reserved_3:2;
    unsigned int    diff_th_base_120:6;
}REG18019D68;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    diff_th_base_0:6;
    unsigned int    reserved_1:2;
    unsigned int    diff_th_base_10:6;
    unsigned int    reserved_2:2;
    unsigned int    diff_th_base_20:6;
    unsigned int    reserved_3:2;
    unsigned int    diff_th_base_40:6;
}REG18019D6C;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    hv_offset:6;
    unsigned int    reserved_1:1;
    unsigned int    still_vector_offset_multiple:3;
    unsigned int    reserved_2:2;
    unsigned int    still_vector_offset_base:6;
    unsigned int    reserved_3:2;
    unsigned int    pal_error_offset:6;
    unsigned int    reserved_4:1;
    unsigned int    hor_c_diff_dpo_hedge_rshift_bit:3;
}REG18019D70;

typedef struct
{
    unsigned int    reserved_0:18;
    unsigned int    still_vector_cvbs_amp_change_offset:6;
    unsigned int    reserved_1:2;
    unsigned int    still_vector_hifreq_diff_th:6;
}REG18019D74;

typedef struct
{
    unsigned int    reserved_0:5;
    unsigned int    later_diff_upper_bound:7;
    unsigned int    reserved_1:1;
    unsigned int    pair_diff_sel_th:7;
    unsigned int    reserved_2:3;
    unsigned int    highfreq_diff_low_border:5;
    unsigned int    flat_offset:4;
}REG18019D78;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    diff_th_upper_bound:7;
    unsigned int    reserved_1:3;
    unsigned int    diff_th_lower_bound:5;
    unsigned int    reserved_2:3;
    unsigned int    diff_th_2d_comp_3d_offset:5;
    unsigned int    reserved_3:2;
    unsigned int    hvdiff_border:6;
}REG18019D7C;

typedef struct
{
    unsigned int    reserved_0:13;
    unsigned int    still_gray_hifreq_th:7;
    unsigned int    reserved_1:2;
    unsigned int    still_gray_hifreq_low_border:6;
    unsigned int    reserved_2:3;
    unsigned int    still_gray_hifreq_enable:1;
}REG18019D80;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    global_diff_tolerance:4;
    unsigned int    reserved_1:3;
    unsigned int    global_diff_offset_dc_fierce_change:5;
    unsigned int    reserved_2:2;
    unsigned int    dc_level_fierce_change_th:6;
    unsigned int    reserved_3:2;
    unsigned int    hdy_small_th:6;
}REG18019D84;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    global_diff_th_hifreq_offset_120:6;
    unsigned int    reserved_1:2;
    unsigned int    global_diff_th_hifreq_offset_140:6;
    unsigned int    reserved_2:2;
    unsigned int    global_diff_th_hifreq_offset_160:6;
    unsigned int    reserved_3:2;
    unsigned int    global_diff_th_hifreq_offset_180:6;
}REG18019D88;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    global_diff_th_hifreq_offset_60:6;
    unsigned int    reserved_1:2;
    unsigned int    global_diff_th_hifreq_offset_70:6;
    unsigned int    reserved_2:2;
    unsigned int    global_diff_th_hifreq_offset_80:6;
    unsigned int    reserved_3:2;
    unsigned int    global_diff_th_hifreq_offset_100:6;
}REG18019D8C;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    global_diff_th_hifreq_offset_20:6;
    unsigned int    reserved_1:2;
    unsigned int    global_diff_th_hifreq_offset_30:6;
    unsigned int    reserved_2:2;
    unsigned int    global_diff_th_hifreq_offset_40:6;
    unsigned int    reserved_3:2;
    unsigned int    global_diff_th_hifreq_offset_50:6;
}REG18019D90;

typedef struct
{
    unsigned int    reserved_0:18;
    unsigned int    global_diff_th_hifreq_offset_0:6;
    unsigned int    reserved_1:2;
    unsigned int    global_diff_th_hifreq_offset_10:6;
}REG18019D94;

typedef struct
{
    unsigned int    reserved_0:15;
    unsigned int    moving_vline_ver_dc_level_fierce_change_th:5;
    unsigned int    reserved_1:3;
    unsigned int    moving_vline_flat_ver_cvbs_th:5;
    unsigned int    reserved_2:1;
    unsigned int    mghf_enable:1;
    unsigned int    moving_vline_en:1;
    unsigned int    dc_level_hor_dc_check_en:1;
}REG18019D98;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    large_hifreq_diff_ratio:3;
    unsigned int    reserved_1:1;
    unsigned int    hor_c_change_ratio:3;
    unsigned int    reserved_2:3;
    unsigned int    hifreq_diff_large_th:5;
    unsigned int    reserved_3:3;
    unsigned int    cvbs_still_th:5;
    unsigned int    reserved_4:3;
    unsigned int    hor_c_change_th:5;
}REG18019D9C;

typedef struct
{
    unsigned int    reserved_0:7;
    unsigned int    gremove_c_small_th:5;
    unsigned int    gremove_bpfedc_small_th:4;
    unsigned int    weight_2d_c:2;
    unsigned int    weight_bld_c:2;
    unsigned int    weight_3d_c:2;
    unsigned int    weight_2d_y:2;
    unsigned int    weight_bld_y:2;
    unsigned int    weight_3d_y:2;
    unsigned int    mghf_narrowbpf_en:1;
    unsigned int    greenish_detected_en:1;
    unsigned int    post2dbpf_c_en:1;
    unsigned int    post2dbpf_y_en:1;
}REG18019DB0;

typedef struct
{
    unsigned int    reserved_0:17;
    unsigned int    hor_cdiff_th_base:7;
    unsigned int    reserved_1:1;
    unsigned int    ver_cdiff_th_base:7;
}REG18019DB4;

typedef struct
{
    unsigned int    reserved_0:5;
    unsigned int    bpfed_c_diff_small_th:7;
    unsigned int    reserved_1:3;
    unsigned int    dual_ch_bpfedc_small_th:5;
    unsigned int    dual_ch_bpfedcdiff_large_ratio:4;
    unsigned int    reserved_2:3;
    unsigned int    dual_ch_bpfedcdiff_large_th:5;
}REG18019DB8;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    bpfed_c_diff_large_hor_offset:7;
    unsigned int    reserved_1:1;
    unsigned int    bpfed_c_diff_large_ver_offset:7;
    unsigned int    reserved_2:1;
    unsigned int    bpfed_c_diff_small_hor_offset:7;
    unsigned int    reserved_3:1;
    unsigned int    bpfed_c_diff_small_ver_offset:7;
}REG18019DBC;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    neighbor_vdiff_small_hor_offset:6;
    unsigned int    reserved_1:2;
    unsigned int    neighbor_hdiff_small_ver_offset:6;
    unsigned int    reserved_2:3;
    unsigned int    vspd_small_th:5;
    unsigned int    reserved_3:3;
    unsigned int    hdy_spd_small_th:5;
}REG18019DC0;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    hvedge_diff_large_ratio:4;
    unsigned int    reserved_1:1;
    unsigned int    vspd_large_th:7;
    unsigned int    reserved_2:1;
    unsigned int    hdy_spd_large_th:7;
    unsigned int    reserved_3:3;
    unsigned int    hdiff_tolerance:5;
}REG18019DC4;

typedef struct
{
    unsigned int    reserved_0:17;
    unsigned int    vedge_hor_offset:7;
    unsigned int    reserved_1:1;
    unsigned int    hedge_ver_offset:7;
}REG18019DC8;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    dia_spd_large_ver_offset:7;
    unsigned int    reserved_1:2;
    unsigned int    dia_spd_large_th_small_hordiff_th:6;
    unsigned int    dia_spd_large_th_small_hordiff_offset:8;
    unsigned int    dia_spd_large_th_base:8;
}REG18019DCC;

typedef struct
{
    unsigned int    reserved_0:15;
    unsigned int    dual_ch_c_small_th:5;
    unsigned int    dual_ch_cdiff_large_ratio:4;
    unsigned int    reserved_1:3;
    unsigned int    dual_ch_cdiff_large_th:5;
}REG18019DD0;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    hdiff_much_larger_ratio:4;
    unsigned int    reserved_1:2;
    unsigned int    hdiff_much_larger_th:6;
    unsigned int    reserved_2:2;
    unsigned int    hdiff_vdiff_diff_larger_th:6;
    unsigned int    reserved_3:1;
    unsigned int    hdiff_large_th:7;
}REG18019DD4;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    ver_color_tran_ver_offset:7;
    unsigned int    reserved_1:1;
    unsigned int    ver_color_tran_ver_cdiff_small_th:7;
    unsigned int    reserved_2:2;
    unsigned int    ver_color_tran_hdiff_large_th:6;
    unsigned int    reserved_3:1;
    unsigned int    hdiff_much_larger_hor_offset:7;
}REG18019DD8;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    colorbar_detect_hor_offset:7;
    unsigned int    reserved_1:1;
    unsigned int    colorbar_detect_ver_offset:7;
    unsigned int    reserved_2:2;
    unsigned int    colorbar_hdiff_large_th:6;
    unsigned int    reserved_3:2;
    unsigned int    colorbar_vdiff_small_th:6;
}REG18019DDC;

typedef struct
{
    unsigned int    ver_avoid_th_c:4;
    unsigned int    ver_avoid_th_y:4;
    unsigned int    reserved_0:1;
    unsigned int    smooth_detect_ver_offset:7;
    unsigned int    reserved_1:2;
    unsigned int    smooth_hdiff_small_th:6;
    unsigned int    reserved_2:2;
    unsigned int    smooth_vdiff_small_th:6;
}REG18019DE0;

typedef struct
{
    unsigned int    vedge_avoid_en:1;
    unsigned int    reserved_0:1;
    unsigned int    vcdiff_large_diff_th:6;
    unsigned int    vcdiff_large_ratio:4;
    unsigned int    v2sides_diff_large_ratio:4;
    unsigned int    reserved_1:1;
    unsigned int    v2sides_diff_large_th:7;
    unsigned int    reserved_2:3;
    unsigned int    v2sides_gray_diff_small_th:5;
}REG18019DE4;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    ignore_th_c:4;
    unsigned int    ignore_th_y:4;
}REG18019DE8;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    ver_cedge_sum_th:7;
    unsigned int    reserved_1:2;
    unsigned int    ver_cedge_single_th:6;
    unsigned int    ver_cedge_en:1;
    unsigned int    reserved_2:1;
    unsigned int    mf_en:1;
    unsigned int    ma0_cnt_th:5;
    unsigned int    point_type_coring_lv:4;
    unsigned int    vline_len_3_sel:1;
    unsigned int    vline_con_en:1;
    unsigned int    cdiff_small_con_en:1;
    unsigned int    ma0_con_en:1;
}REG18019E14;

typedef struct
{
    unsigned int    reserved_0:13;
    unsigned int    cdiff_small_sum_th:7;
    unsigned int    reserved_1:2;
    unsigned int    cdiff_small_single_th:6;
    unsigned int    cdiff_small_len:4;
}REG18019E18;

typedef struct
{
    unsigned int    reserved_0:22;
    unsigned int    postpk_prelpf_mode:1;
    unsigned int    postpk_prelpf_en:1;
    unsigned int    reserved_1:2;
    unsigned int    postpk_alphablend_en:1;
    unsigned int    postpk_dnoise_en:1;
    unsigned int    postpk_adap_mode:2;
    unsigned int    postpk_adappk_en:1;
    unsigned int    postpk_en:1;
}REG18019E1C;

typedef struct
{
    unsigned int    reserved_0:5;
    unsigned int    postpk_c_stepbit:3;
    unsigned int    postpk_c_lwbnd:8;
    unsigned int    reserved_1:5;
    unsigned int    postpk_y_stepbit:3;
    unsigned int    postpk_y_lwbnd:8;
}REG18019E20;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    postpk_lv_upbnd:8;
    unsigned int    reserved_1:5;
    unsigned int    postpk_lv_sft:3;
    unsigned int    postpk_lv_th:8;
}REG18019E24;

typedef struct
{
    unsigned int    reserved_0:3;
    unsigned int    postpk_c0:9;
    unsigned int    reserved_1:3;
    unsigned int    postpk_c1:9;
    unsigned int    postpk_c2:8;
}REG18019E28;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    postpk_gain_pos:8;
    unsigned int    postpk_gain_neg:8;
}REG18019E2C;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    postpk_hv_pos:10;
    unsigned int    postpk_hv_neg:10;
    unsigned int    postpk_lv:8;
}REG18019E30;

typedef struct
{
    unsigned int    dlti_ffd2_ratio:4;
    unsigned int    reserved_0:3;
    unsigned int    dlti_ffd2_en:1;
    unsigned int    dlti_ffd1_ratio:4;
    unsigned int    reserved_1:3;
    unsigned int    dlti_ffd1_th:5;
    unsigned int    reserved_2:1;
    unsigned int    dlti_maxlen:3;
    unsigned int    dlti_pnth:7;
    unsigned int    dlti_en:1;
}REG18019E34;

typedef struct
{
    unsigned int    dlti_d1_cp_shift:4;
    unsigned int    reserved_0:2;
    unsigned int    dlti_dcp_th:6;
    unsigned int    reserved_1:2;
    unsigned int    dlti_tn_blend_mode:1;
    unsigned int    dlti_tn_blend_en:1;
    unsigned int    reserved_2:3;
    unsigned int    dlti_ovc_en:1;
    unsigned int    dlti_can_shift:4;
    unsigned int    dlti_ffd2_range2l:4;
    unsigned int    dlti_ffd2_range2r:4;
}REG18019E38;

typedef struct
{
    unsigned int    dlti_cchange_srcwei_offset_2:4;
    unsigned int    dlti_cchange_srcwei_offset_1:4;
    unsigned int    dlti_uv_diff_th_2:8;
    unsigned int    dlti_uv_diff_th_1:8;
    unsigned int    reserved_0:1;
    unsigned int    dlti_cchange_len:3;
    unsigned int    reserved_1:3;
    unsigned int    dlti_cchange_corr_en:1;
}REG18019E3C;

typedef struct
{
    unsigned int    dlti_tngain7:4;
    unsigned int    dlti_tngain6:4;
    unsigned int    dlti_tngain5:4;
    unsigned int    dlti_tngain4:4;
    unsigned int    dlti_tngain3:4;
    unsigned int    dlti_tngain2:4;
    unsigned int    dlti_tngain1:4;
    unsigned int    dlti_tngain0:4;
}REG18019E40;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    dlti_tngain14:4;
    unsigned int    dlti_tngain13:4;
    unsigned int    dlti_tngain12:4;
    unsigned int    dlti_tngain11:4;
    unsigned int    dlti_tngain10:4;
    unsigned int    dlti_tngain9:4;
    unsigned int    dlti_tngain8:4;
}REG18019E44;

typedef struct
{
    unsigned int    dlti_tnoffset7:4;
    unsigned int    dlti_tnoffset6:4;
    unsigned int    dlti_tnoffset5:4;
    unsigned int    dlti_tnoffset4:4;
    unsigned int    dlti_tnoffset3:4;
    unsigned int    dlti_tnoffset2:4;
    unsigned int    dlti_tnoffset1:4;
    unsigned int    dlti_tnoffset0:4;
}REG18019E48;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    dlti_tnoffset14:4;
    unsigned int    dlti_tnoffset13:4;
    unsigned int    dlti_tnoffset12:4;
    unsigned int    dlti_tnoffset11:4;
    unsigned int    dlti_tnoffset10:4;
    unsigned int    dlti_tnoffset9:4;
    unsigned int    dlti_tnoffset8:4;
}REG18019E4C;

typedef struct
{
    unsigned int    reserved_0:13;
    unsigned int    pd_sel_dlti_cnt_th2:3;
    unsigned int    reserved_1:1;
    unsigned int    pd_sel_dlti_cnt_th1:3;
    unsigned int    pd_sel_dlti_diff_th:8;
    unsigned int    reserved_2:1;
    unsigned int    pd_sel:3;
}REG18019E50;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    pk_alpha_2d_weight:2;
    unsigned int    pk_alpha_bld_weight:2;
    unsigned int    pk_alpha_3d_weight:2;
    unsigned int    reserved_1:2;
    unsigned int    dlti_alpha_2d_weight:2;
    unsigned int    dlti_alpha_bld_weight:2;
    unsigned int    dlti_alpha_3d_weight:2;
    unsigned int    reserved_2:2;
    unsigned int    mf_alpha_2d_weight:2;
    unsigned int    mf_alpha_bld_weight:2;
    unsigned int    mf_alpha_3d_weight:2;
    unsigned int    reserved_3:8;
}REG18019E54;

typedef struct
{
    unsigned int    ntsc443_lpf:1;
    unsigned int    reserved_0:25;
    unsigned int    ntsc443_lpf_ext:2;
    unsigned int    reserved_1:1;
    unsigned int    ntsc443_lpf_th_y:3;
}REG18019E60;

typedef struct
{
    unsigned int    reserved_0:30;
    unsigned int    cp_sweightydebug:2;
}REG18019E64;

typedef struct
{
    unsigned int    reserved_0:5;
    unsigned int    cp_sresultweight:3;
    unsigned int    cp_zoranfiltersizey:2;
    unsigned int    cp_zoranweight2y:2;
    unsigned int    cp_zoranweight3y:2;
    unsigned int    cp_zoranweight4y:2;
    unsigned int    reserved_1:14;
    unsigned int    cp_spatialenablec:1;
    unsigned int    cp_spatialenabley:1;
}REG18019E68;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    cp_spatialthlyx4:8;
    unsigned int    cp_spatialthlyx2:8;
    unsigned int    cp_spatialthly:8;
}REG18019E6C;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    cp_ringweighty:4;
    unsigned int    cp_weight1y:4;
    unsigned int    cp_weight2y:4;
    unsigned int    cp_fixedweight1y:1;
    unsigned int    cp_fixedweight2y:1;
    unsigned int    reserved_1:5;
    unsigned int    cp_ringrange:1;
    unsigned int    cp_ringgain:1;
    unsigned int    reserved_2:7;
}REG18019E70;

typedef struct
{
    unsigned int    dummy_status:32;
}REG18019E74;

typedef struct
{
    unsigned int    cp_sw_edge_thl:16;
    unsigned int    reserved_0:14;
    unsigned int    cp_edge_weight:2;
}REG18019E78;

typedef struct
{
    unsigned int    reserved_0:26;
    unsigned int    xc_blend_en:1;
    unsigned int    de_xc_en:1;
    unsigned int    de_xc_thr:4;
}REG18019F00;

typedef struct
{
    unsigned int    reserved_0:28;
    unsigned int    cnr_lpf_sel:2;
    unsigned int    reserved_1:1;
    unsigned int    cnr_en:1;
}REG18019F04;

typedef struct
{
    unsigned int    reserved_0:26;
    unsigned int    cadap_spatial_lpf_out:1;
    unsigned int    cadap_clpf_en:1;
    unsigned int    cadap_ylpf_en:1;
    unsigned int    cadap_uvsync_en:1;
    unsigned int    cadap_yuvsync_en:1;
    unsigned int    cadap_cti_en:1;
}REG18019F0C;

typedef struct
{
    unsigned int    reserved_0:29;
    unsigned int    cadap_uni_gain_ctrl_en:1;
    unsigned int    cadap_uv_sync_uni_en:1;
    unsigned int    cadap_y_sync_uni_en:1;
}REG18019F10;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    cadap_gain:4;
    unsigned int    cadap_level:4;
}REG18019F14;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    cadap_zc_mag_th_y:4;
    unsigned int    cadap_zc_mag_th_y_c:4;
}REG18019F18;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    cadap_zc_mag_th_c:4;
    unsigned int    cadap_dir_det_gain:4;
}REG18019F1C;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    cadap_ver_uni_th:4;
    unsigned int    cadap_dir_uni_th:4;
}REG18019F20;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    cadap_y_sync_uni_th:4;
    unsigned int    cadap_uv_sync_uni_th:4;
}REG18019F24;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    cadap_lut_level_tha:4;
    unsigned int    cadap_lut_level_thb:4;
}REG18019F28;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    cadap_lut_gain_tha:4;
    unsigned int    cadap_lut_gain_thb:4;
}REG18019F2C;

typedef struct
{
    unsigned int    reserved_0:21;
    unsigned int    dcti_filter_coef_b1:11;
}REG18019F30;

typedef struct
{
    unsigned int    reserved_0:21;
    unsigned int    dcti_filter_coef_b2:11;
}REG18019F34;

typedef struct
{
    unsigned int    reserved_0:21;
    unsigned int    dcti_filter_coef_b3:11;
}REG18019F38;

typedef struct
{
    unsigned int    reserved_0:21;
    unsigned int    dcti_filter_coef_a2:11;
}REG18019F3C;

typedef struct
{
    unsigned int    reserved_0:21;
    unsigned int    dcti_filter_coef_a3:11;
}REG18019F40;

typedef struct
{
    unsigned int    reserved_0:31;
    unsigned int    dcti_filter_en:1;
}REG18019F44;

typedef struct
{
    unsigned int    dummy_7:32;
}REG18019FF8;

typedef struct
{
    unsigned int    dummy_8:32;
}REG18019FFC;
#endif


#define FRAME_BUF_CHK3D_CTRL0                                         0x18019800
#define FRAME_BUF_CHK3D_CTRL0_reg_addr                                "0xb8019800"
#define FRAME_BUF_CHK3D_CTRL0_reg                                     0xb8019800
#define FRAME_BUF_CHK3D_CTRL0_inst_addr                               "0x0200"
#define FRAME_BUF_CHK3D_CTRL0_inst                                    0x0200
#define FRAME_BUF_CHK3D_CTRL0_f_num_chk_3d_sel_shift                  (6)
#define FRAME_BUF_CHK3D_CTRL0_f_hennum_range_shift                    (0)
#define FRAME_BUF_CHK3D_CTRL0_f_num_chk_3d_sel_mask                   (0x000000C0)
#define FRAME_BUF_CHK3D_CTRL0_f_hennum_range_mask                     (0x0000003F)
#define FRAME_BUF_CHK3D_CTRL0_f_num_chk_3d_sel(data)                  (0x000000C0&((data)<<6))
#define FRAME_BUF_CHK3D_CTRL0_f_hennum_range(data)                    (0x0000003F&(data))
#define FRAME_BUF_CHK3D_CTRL0_get_f_num_chk_3d_sel(data)              ((0x000000C0&(data))>>6)
#define FRAME_BUF_CHK3D_CTRL0_get_f_hennum_range(data)                (0x0000003F&(data))


#define FRAME_BUF_CHK3D_CTRL1                                         0x18019804
#define FRAME_BUF_CHK3D_CTRL1_reg_addr                                "0xb8019804"
#define FRAME_BUF_CHK3D_CTRL1_reg                                     0xb8019804
#define FRAME_BUF_CHK3D_CTRL1_inst_addr                               "0x0201"
#define FRAME_BUF_CHK3D_CTRL1_inst                                    0x0201
#define FRAME_BUF_CHK3D_CTRL1_f_num_chk_3d_en_shift                   (7)
#define FRAME_BUF_CHK3D_CTRL1_f_num_3d_fail_det_shift                 (6)
#define FRAME_BUF_CHK3D_CTRL1_f_cennum_range_shift                    (0)
#define FRAME_BUF_CHK3D_CTRL1_f_num_chk_3d_en_mask                    (0x00000080)
#define FRAME_BUF_CHK3D_CTRL1_f_num_3d_fail_det_mask                  (0x00000040)
#define FRAME_BUF_CHK3D_CTRL1_f_cennum_range_mask                     (0x0000003F)
#define FRAME_BUF_CHK3D_CTRL1_f_num_chk_3d_en(data)                   (0x00000080&((data)<<7))
#define FRAME_BUF_CHK3D_CTRL1_f_num_3d_fail_det(data)                 (0x00000040&((data)<<6))
#define FRAME_BUF_CHK3D_CTRL1_f_cennum_range(data)                    (0x0000003F&(data))
#define FRAME_BUF_CHK3D_CTRL1_get_f_num_chk_3d_en(data)               ((0x00000080&(data))>>7)
#define FRAME_BUF_CHK3D_CTRL1_get_f_num_3d_fail_det(data)             ((0x00000040&(data))>>6)
#define FRAME_BUF_CHK3D_CTRL1_get_f_cennum_range(data)                (0x0000003F&(data))


#define FRAME_BUF_CHK3D_CTRL2                                         0x18019808
#define FRAME_BUF_CHK3D_CTRL2_reg_addr                                "0xb8019808"
#define FRAME_BUF_CHK3D_CTRL2_reg                                     0xb8019808
#define FRAME_BUF_CHK3D_CTRL2_inst_addr                               "0x0202"
#define FRAME_BUF_CHK3D_CTRL2_inst                                    0x0202
#define FRAME_BUF_CHK3D_CTRL2_f_num_open3d_cnt_shift                  (4)
#define FRAME_BUF_CHK3D_CTRL2_f_num_close3d_cnt_shift                 (0)
#define FRAME_BUF_CHK3D_CTRL2_f_num_open3d_cnt_mask                   (0x000000F0)
#define FRAME_BUF_CHK3D_CTRL2_f_num_close3d_cnt_mask                  (0x0000000F)
#define FRAME_BUF_CHK3D_CTRL2_f_num_open3d_cnt(data)                  (0x000000F0&((data)<<4))
#define FRAME_BUF_CHK3D_CTRL2_f_num_close3d_cnt(data)                 (0x0000000F&(data))
#define FRAME_BUF_CHK3D_CTRL2_get_f_num_open3d_cnt(data)              ((0x000000F0&(data))>>4)
#define FRAME_BUF_CHK3D_CTRL2_get_f_num_close3d_cnt(data)             (0x0000000F&(data))


#define FRAME_BUF_CHK3D_CEN_CTRL                                      0x1801980c
#define FRAME_BUF_CHK3D_CEN_CTRL_reg_addr                             "0xb801980c"
#define FRAME_BUF_CHK3D_CEN_CTRL_reg                                  0xb801980c
#define FRAME_BUF_CHK3D_CEN_CTRL_inst_addr                            "0x0203"
#define FRAME_BUF_CHK3D_CEN_CTRL_inst                                 0x0203
#define FRAME_BUF_CHK3D_CEN_CTRL_f_cennum_valid_en_shift              (2)
#define FRAME_BUF_CHK3D_CEN_CTRL_f_cennum_valid1_en_shift             (1)
#define FRAME_BUF_CHK3D_CEN_CTRL_f_cennum_valid2_en_shift             (0)
#define FRAME_BUF_CHK3D_CEN_CTRL_f_cennum_valid_en_mask               (0x00000004)
#define FRAME_BUF_CHK3D_CEN_CTRL_f_cennum_valid1_en_mask              (0x00000002)
#define FRAME_BUF_CHK3D_CEN_CTRL_f_cennum_valid2_en_mask              (0x00000001)
#define FRAME_BUF_CHK3D_CEN_CTRL_f_cennum_valid_en(data)              (0x00000004&((data)<<2))
#define FRAME_BUF_CHK3D_CEN_CTRL_f_cennum_valid1_en(data)             (0x00000002&((data)<<1))
#define FRAME_BUF_CHK3D_CEN_CTRL_f_cennum_valid2_en(data)             (0x00000001&(data))
#define FRAME_BUF_CHK3D_CEN_CTRL_get_f_cennum_valid_en(data)          ((0x00000004&(data))>>2)
#define FRAME_BUF_CHK3D_CEN_CTRL_get_f_cennum_valid1_en(data)         ((0x00000002&(data))>>1)
#define FRAME_BUF_CHK3D_CEN_CTRL_get_f_cennum_valid2_en(data)         (0x00000001&(data))


#define FRAME_BUF_CHK3D_CEN_NUM1_BYTE                                 0x18019810
#define FRAME_BUF_CHK3D_CEN_NUM1_BYTE_reg_addr                        "0xb8019810"
#define FRAME_BUF_CHK3D_CEN_NUM1_BYTE_reg                             0xb8019810
#define FRAME_BUF_CHK3D_CEN_NUM1_BYTE_inst_addr                       "0x0204"
#define FRAME_BUF_CHK3D_CEN_NUM1_BYTE_inst                            0x0204
#define FRAME_BUF_CHK3D_CEN_NUM1_BYTE_f_cennum_valid1_num_shift       (0)
#define FRAME_BUF_CHK3D_CEN_NUM1_BYTE_f_cennum_valid1_num_mask        (0x000FFFFF)
#define FRAME_BUF_CHK3D_CEN_NUM1_BYTE_f_cennum_valid1_num(data)       (0x000FFFFF&(data))
#define FRAME_BUF_CHK3D_CEN_NUM1_BYTE_get_f_cennum_valid1_num(data)   (0x000FFFFF&(data))


#define FRAME_BUF_CHK3D_CEN_NUM2_BYTE                                 0x18019814
#define FRAME_BUF_CHK3D_CEN_NUM2_BYTE_reg_addr                        "0xb8019814"
#define FRAME_BUF_CHK3D_CEN_NUM2_BYTE_reg                             0xb8019814
#define FRAME_BUF_CHK3D_CEN_NUM2_BYTE_inst_addr                       "0x0205"
#define FRAME_BUF_CHK3D_CEN_NUM2_BYTE_inst                            0x0205
#define FRAME_BUF_CHK3D_CEN_NUM2_BYTE_f_cennum_valid2_num_shift       (0)
#define FRAME_BUF_CHK3D_CEN_NUM2_BYTE_f_cennum_valid2_num_mask        (0x000FFFFF)
#define FRAME_BUF_CHK3D_CEN_NUM2_BYTE_f_cennum_valid2_num(data)       (0x000FFFFF&(data))
#define FRAME_BUF_CHK3D_CEN_NUM2_BYTE_get_f_cennum_valid2_num(data)   (0x000FFFFF&(data))


#define FRAME_BUF_CHK3D_HEN_NUM1_CTRL                                 0x18019818
#define FRAME_BUF_CHK3D_HEN_NUM1_CTRL_reg_addr                        "0xb8019818"
#define FRAME_BUF_CHK3D_HEN_NUM1_CTRL_reg                             0xb8019818
#define FRAME_BUF_CHK3D_HEN_NUM1_CTRL_inst_addr                       "0x0206"
#define FRAME_BUF_CHK3D_HEN_NUM1_CTRL_inst                            0x0206
#define FRAME_BUF_CHK3D_HEN_NUM1_CTRL_f_hennum_valid_en_shift         (1)
#define FRAME_BUF_CHK3D_HEN_NUM1_CTRL_f_hennum_valid1_en_shift        (0)
#define FRAME_BUF_CHK3D_HEN_NUM1_CTRL_f_hennum_valid_en_mask          (0x00000002)
#define FRAME_BUF_CHK3D_HEN_NUM1_CTRL_f_hennum_valid1_en_mask         (0x00000001)
#define FRAME_BUF_CHK3D_HEN_NUM1_CTRL_f_hennum_valid_en(data)         (0x00000002&((data)<<1))
#define FRAME_BUF_CHK3D_HEN_NUM1_CTRL_f_hennum_valid1_en(data)        (0x00000001&(data))
#define FRAME_BUF_CHK3D_HEN_NUM1_CTRL_get_f_hennum_valid_en(data)     ((0x00000002&(data))>>1)
#define FRAME_BUF_CHK3D_HEN_NUM1_CTRL_get_f_hennum_valid1_en(data)    (0x00000001&(data))


#define FRAME_BUF_CHK3D_HEN_NUM1_BYTE                                 0x1801981c
#define FRAME_BUF_CHK3D_HEN_NUM1_BYTE_reg_addr                        "0xb801981c"
#define FRAME_BUF_CHK3D_HEN_NUM1_BYTE_reg                             0xb801981c
#define FRAME_BUF_CHK3D_HEN_NUM1_BYTE_inst_addr                       "0x0207"
#define FRAME_BUF_CHK3D_HEN_NUM1_BYTE_inst                            0x0207
#define FRAME_BUF_CHK3D_HEN_NUM1_BYTE_f_hennum_valid1_num_shift       (0)
#define FRAME_BUF_CHK3D_HEN_NUM1_BYTE_f_hennum_valid1_num_mask        (0x000FFFFF)
#define FRAME_BUF_CHK3D_HEN_NUM1_BYTE_f_hennum_valid1_num(data)       (0x000FFFFF&(data))
#define FRAME_BUF_CHK3D_HEN_NUM1_BYTE_get_f_hennum_valid1_num(data)   (0x000FFFFF&(data))


#define DMA_VACTIVE_ST1                                               0x18019830
#define DMA_VACTIVE_ST1_reg_addr                                      "0xb8019830"
#define DMA_VACTIVE_ST1_reg                                           0xb8019830
#define DMA_VACTIVE_ST1_inst_addr                                     "0x020C"
#define DMA_VACTIVE_ST1_inst                                          0x020C
#define DMA_VACTIVE_ST1_vactive_st1_shift                             (0)
#define DMA_VACTIVE_ST1_vactive_st1_mask                              (0x000003FF)
#define DMA_VACTIVE_ST1_vactive_st1(data)                             (0x000003FF&(data))
#define DMA_VACTIVE_ST1_get_vactive_st1(data)                         (0x000003FF&(data))


#define DMA_VACTIVE_END1                                              0x18019834
#define DMA_VACTIVE_END1_reg_addr                                     "0xb8019834"
#define DMA_VACTIVE_END1_reg                                          0xb8019834
#define DMA_VACTIVE_END1_inst_addr                                    "0x020D"
#define DMA_VACTIVE_END1_inst                                         0x020D
#define DMA_VACTIVE_END1_vactive_end1_shift                           (0)
#define DMA_VACTIVE_END1_vactive_end1_mask                            (0x000003FF)
#define DMA_VACTIVE_END1_vactive_end1(data)                           (0x000003FF&(data))
#define DMA_VACTIVE_END1_get_vactive_end1(data)                       (0x000003FF&(data))


#define DMA_VACTIVE_ST2                                               0x18019838
#define DMA_VACTIVE_ST2_reg_addr                                      "0xb8019838"
#define DMA_VACTIVE_ST2_reg                                           0xb8019838
#define DMA_VACTIVE_ST2_inst_addr                                     "0x020E"
#define DMA_VACTIVE_ST2_inst                                          0x020E
#define DMA_VACTIVE_ST2_vactive_st2_shift                             (0)
#define DMA_VACTIVE_ST2_vactive_st2_mask                              (0x000003FF)
#define DMA_VACTIVE_ST2_vactive_st2(data)                             (0x000003FF&(data))
#define DMA_VACTIVE_ST2_get_vactive_st2(data)                         (0x000003FF&(data))


#define DMA_VACTIVE_END2                                              0x1801983c
#define DMA_VACTIVE_END2_reg_addr                                     "0xb801983c"
#define DMA_VACTIVE_END2_reg                                          0xb801983c
#define DMA_VACTIVE_END2_inst_addr                                    "0x020F"
#define DMA_VACTIVE_END2_inst                                         0x020F
#define DMA_VACTIVE_END2_vactive_end2_shift                           (0)
#define DMA_VACTIVE_END2_vactive_end2_mask                            (0x000003FF)
#define DMA_VACTIVE_END2_vactive_end2(data)                           (0x000003FF&(data))
#define DMA_VACTIVE_END2_get_vactive_end2(data)                       (0x000003FF&(data))


#define DMA_CTRL1                                                     0x18019840
#define DMA_CTRL1_reg_addr                                            "0xb8019840"
#define DMA_CTRL1_reg                                                 0xb8019840
#define DMA_CTRL1_inst_addr                                           "0x0210"
#define DMA_CTRL1_inst                                                0x0210
#define DMA_CTRL1_dma_ctrl_ififo_thr_shift                            (0)
#define DMA_CTRL1_dma_ctrl_ififo_thr_mask                             (0x0000003F)
#define DMA_CTRL1_dma_ctrl_ififo_thr(data)                            (0x0000003F&(data))
#define DMA_CTRL1_get_dma_ctrl_ififo_thr(data)                        (0x0000003F&(data))


#define DMA_CTRL2                                                     0x18019844
#define DMA_CTRL2_reg_addr                                            "0xb8019844"
#define DMA_CTRL2_reg                                                 0xb8019844
#define DMA_CTRL2_inst_addr                                           "0x0211"
#define DMA_CTRL2_inst                                                0x0211
#define DMA_CTRL2_dma_ctrl_ofifo_thr_shift                            (0)
#define DMA_CTRL2_dma_ctrl_ofifo_thr_mask                             (0x0000003F)
#define DMA_CTRL2_dma_ctrl_ofifo_thr(data)                            (0x0000003F&(data))
#define DMA_CTRL2_get_dma_ctrl_ofifo_thr(data)                        (0x0000003F&(data))


#define DMA_CTRL3                                                     0x18019848
#define DMA_CTRL3_reg_addr                                            "0xb8019848"
#define DMA_CTRL3_reg                                                 0xb8019848
#define DMA_CTRL3_inst_addr                                           "0x0212"
#define DMA_CTRL3_inst                                                0x0212
#define DMA_CTRL3_dma_ctrl_ceiladr_shift                              (0)
#define DMA_CTRL3_dma_ctrl_ceiladr_mask                               (0x0000003F)
#define DMA_CTRL3_dma_ctrl_ceiladr(data)                              (0x0000003F&(data))
#define DMA_CTRL3_get_dma_ctrl_ceiladr(data)                          (0x0000003F&(data))


#define DMA_CTRL4                                                     0x1801984c
#define DMA_CTRL4_reg_addr                                            "0xb801984c"
#define DMA_CTRL4_reg                                                 0xb801984c
#define DMA_CTRL4_inst_addr                                           "0x0213"
#define DMA_CTRL4_inst                                                0x0213
#define DMA_CTRL4_dma_3d_on_off_shift                                 (31)
#define DMA_CTRL4_ntsc443_tune_shift                                  (28)
#define DMA_CTRL4_dma_vcnt_diff_shift                                 (16)
#define DMA_CTRL4_dma_vcnt_sft_chk_en_shift                           (15)
#define DMA_CTRL4_dma_vcnt_sft_thr_shift                              (8)
#define DMA_CTRL4_dma_3d_on_vcnt_shift                                (3)
#define DMA_CTRL4_dma_ctrl_bstlen_shift                               (0)
#define DMA_CTRL4_dma_3d_on_off_mask                                  (0x80000000)
#define DMA_CTRL4_ntsc443_tune_mask                                   (0x70000000)
#define DMA_CTRL4_dma_vcnt_diff_mask                                  (0x03FF0000)
#define DMA_CTRL4_dma_vcnt_sft_chk_en_mask                            (0x00008000)
#define DMA_CTRL4_dma_vcnt_sft_thr_mask                               (0x00001F00)
#define DMA_CTRL4_dma_3d_on_vcnt_mask                                 (0x000000F8)
#define DMA_CTRL4_dma_ctrl_bstlen_mask                                (0x00000007)
#define DMA_CTRL4_dma_3d_on_off(data)                                 (0x80000000&((data)<<31))
#define DMA_CTRL4_ntsc443_tune(data)                                  (0x70000000&((data)<<28))
#define DMA_CTRL4_dma_vcnt_diff(data)                                 (0x03FF0000&((data)<<16))
#define DMA_CTRL4_dma_vcnt_sft_chk_en(data)                           (0x00008000&((data)<<15))
#define DMA_CTRL4_dma_vcnt_sft_thr(data)                              (0x00001F00&((data)<<8))
#define DMA_CTRL4_dma_3d_on_vcnt(data)                                (0x000000F8&((data)<<3))
#define DMA_CTRL4_dma_ctrl_bstlen(data)                               (0x00000007&(data))
#define DMA_CTRL4_get_dma_3d_on_off(data)                             ((0x80000000&(data))>>31)
#define DMA_CTRL4_get_ntsc443_tune(data)                              ((0x70000000&(data))>>28)
#define DMA_CTRL4_get_dma_vcnt_diff(data)                             ((0x03FF0000&(data))>>16)
#define DMA_CTRL4_get_dma_vcnt_sft_chk_en(data)                       ((0x00008000&(data))>>15)
#define DMA_CTRL4_get_dma_vcnt_sft_thr(data)                          ((0x00001F00&(data))>>8)
#define DMA_CTRL4_get_dma_3d_on_vcnt(data)                            ((0x000000F8&(data))>>3)
#define DMA_CTRL4_get_dma_ctrl_bstlen(data)                           (0x00000007&(data))


#define DMA_CTRL5                                                     0x18019850
#define DMA_CTRL5_reg_addr                                            "0xb8019850"
#define DMA_CTRL5_reg                                                 0xb8019850
#define DMA_CTRL5_inst_addr                                           "0x0214"
#define DMA_CTRL5_inst                                                0x0214
#define DMA_CTRL5_ofifo_err_flag_shift                                (7)
#define DMA_CTRL5_ififo_err_flag_1_shift                              (6)
#define DMA_CTRL5_ififo_err_flag_2_shift                              (5)
#define DMA_CTRL5_ififo_err_flag_3_shift                              (4)
#define DMA_CTRL5_ififo_err_flag_4_shift                              (3)
#define DMA_CTRL5_mem_off_shift                                       (2)
#define DMA_CTRL5_mem_test_mode_shift                                 (1)
#define DMA_CTRL5_mem_test_mode_ok_shift                              (0)
#define DMA_CTRL5_ofifo_err_flag_mask                                 (0x00000080)
#define DMA_CTRL5_ififo_err_flag_1_mask                               (0x00000040)
#define DMA_CTRL5_ififo_err_flag_2_mask                               (0x00000020)
#define DMA_CTRL5_ififo_err_flag_3_mask                               (0x00000010)
#define DMA_CTRL5_ififo_err_flag_4_mask                               (0x00000008)
#define DMA_CTRL5_mem_off_mask                                        (0x00000004)
#define DMA_CTRL5_mem_test_mode_mask                                  (0x00000002)
#define DMA_CTRL5_mem_test_mode_ok_mask                               (0x00000001)
#define DMA_CTRL5_ofifo_err_flag(data)                                (0x00000080&((data)<<7))
#define DMA_CTRL5_ififo_err_flag_1(data)                              (0x00000040&((data)<<6))
#define DMA_CTRL5_ififo_err_flag_2(data)                              (0x00000020&((data)<<5))
#define DMA_CTRL5_ififo_err_flag_3(data)                              (0x00000010&((data)<<4))
#define DMA_CTRL5_ififo_err_flag_4(data)                              (0x00000008&((data)<<3))
#define DMA_CTRL5_mem_off(data)                                       (0x00000004&((data)<<2))
#define DMA_CTRL5_mem_test_mode(data)                                 (0x00000002&((data)<<1))
#define DMA_CTRL5_mem_test_mode_ok(data)                              (0x00000001&(data))
#define DMA_CTRL5_get_ofifo_err_flag(data)                            ((0x00000080&(data))>>7)
#define DMA_CTRL5_get_ififo_err_flag_1(data)                          ((0x00000040&(data))>>6)
#define DMA_CTRL5_get_ififo_err_flag_2(data)                          ((0x00000020&(data))>>5)
#define DMA_CTRL5_get_ififo_err_flag_3(data)                          ((0x00000010&(data))>>4)
#define DMA_CTRL5_get_ififo_err_flag_4(data)                          ((0x00000008&(data))>>3)
#define DMA_CTRL5_get_mem_off(data)                                   ((0x00000004&(data))>>2)
#define DMA_CTRL5_get_mem_test_mode(data)                             ((0x00000002&(data))>>1)
#define DMA_CTRL5_get_mem_test_mode_ok(data)                          (0x00000001&(data))


#define DMA_CTRL6                                                     0x18019854
#define DMA_CTRL6_reg_addr                                            "0xb8019854"
#define DMA_CTRL6_reg                                                 0xb8019854
#define DMA_CTRL6_inst_addr                                           "0x0215"
#define DMA_CTRL6_inst                                                0x0215
#define DMA_CTRL6_dma_field_inv_shift                                 (2)
#define DMA_CTRL6_dma_adc_in_en_shift                                 (1)
#define DMA_CTRL6_dma_adc_in_sel_shift                                (0)
#define DMA_CTRL6_dma_field_inv_mask                                  (0x00000004)
#define DMA_CTRL6_dma_adc_in_en_mask                                  (0x00000002)
#define DMA_CTRL6_dma_adc_in_sel_mask                                 (0x00000001)
#define DMA_CTRL6_dma_field_inv(data)                                 (0x00000004&((data)<<2))
#define DMA_CTRL6_dma_adc_in_en(data)                                 (0x00000002&((data)<<1))
#define DMA_CTRL6_dma_adc_in_sel(data)                                (0x00000001&(data))
#define DMA_CTRL6_get_dma_field_inv(data)                             ((0x00000004&(data))>>2)
#define DMA_CTRL6_get_dma_adc_in_en(data)                             ((0x00000002&(data))>>1)
#define DMA_CTRL6_get_dma_adc_in_sel(data)                            (0x00000001&(data))


#define DEBUG_DMA_IF_CTRL                                             0x18019858
#define DEBUG_DMA_IF_CTRL_reg_addr                                    "0xb8019858"
#define DEBUG_DMA_IF_CTRL_reg                                         0xb8019858
#define DEBUG_DMA_IF_CTRL_inst_addr                                   "0x0216"
#define DEBUG_DMA_IF_CTRL_inst                                        0x0216
#define DEBUG_DMA_IF_CTRL_dma_debugif_stline_en_shift                 (10)
#define DEBUG_DMA_IF_CTRL_dma_debugif_stline_shift                    (0)
#define DEBUG_DMA_IF_CTRL_dma_debugif_stline_en_mask                  (0x00000400)
#define DEBUG_DMA_IF_CTRL_dma_debugif_stline_mask                     (0x000003FF)
#define DEBUG_DMA_IF_CTRL_dma_debugif_stline_en(data)                 (0x00000400&((data)<<10))
#define DEBUG_DMA_IF_CTRL_dma_debugif_stline(data)                    (0x000003FF&(data))
#define DEBUG_DMA_IF_CTRL_get_dma_debugif_stline_en(data)             ((0x00000400&(data))>>10)
#define DEBUG_DMA_IF_CTRL_get_dma_debugif_stline(data)                (0x000003FF&(data))


#define VD_SRAM_ON_OFF                                                0x1801985c
#define VD_SRAM_ON_OFF_reg_addr                                       "0xb801985c"
#define VD_SRAM_ON_OFF_reg                                            0xb801985c
#define VD_SRAM_ON_OFF_inst_addr                                      "0x0217"
#define VD_SRAM_ON_OFF_inst                                           0x0217
#define VD_SRAM_ON_OFF_vlpf_sram_bypass_shift                         (1)
#define VD_SRAM_ON_OFF_vd_sram_on_off_shift                           (0)
#define VD_SRAM_ON_OFF_vlpf_sram_bypass_mask                          (0x00000002)
#define VD_SRAM_ON_OFF_vd_sram_on_off_mask                            (0x00000001)
#define VD_SRAM_ON_OFF_vlpf_sram_bypass(data)                         (0x00000002&((data)<<1))
#define VD_SRAM_ON_OFF_vd_sram_on_off(data)                           (0x00000001&(data))
#define VD_SRAM_ON_OFF_get_vlpf_sram_bypass(data)                     ((0x00000002&(data))>>1)
#define VD_SRAM_ON_OFF_get_vd_sram_on_off(data)                       (0x00000001&(data))


#define MEM0_ADDR_INI                                                 0x18019870
#define MEM0_ADDR_INI_reg_addr                                        "0xb8019870"
#define MEM0_ADDR_INI_reg                                             0xb8019870
#define MEM0_ADDR_INI_inst_addr                                       "0x021C"
#define MEM0_ADDR_INI_inst                                            0x021C
#define MEM0_ADDR_INI_frame_addr0_shift                               (0)
#define MEM0_ADDR_INI_frame_addr0_mask                                (0x1FFFFFFF)
#define MEM0_ADDR_INI_frame_addr0(data)                               (0x1FFFFFFF&(data))
#define MEM0_ADDR_INI_get_frame_addr0(data)                           (0x1FFFFFFF&(data))


#define MEM1_ADDR_INI                                                 0x18019874
#define MEM1_ADDR_INI_reg_addr                                        "0xb8019874"
#define MEM1_ADDR_INI_reg                                             0xb8019874
#define MEM1_ADDR_INI_inst_addr                                       "0x021D"
#define MEM1_ADDR_INI_inst                                            0x021D
#define MEM1_ADDR_INI_frame_addr1_shift                               (0)
#define MEM1_ADDR_INI_frame_addr1_mask                                (0x1FFFFFFF)
#define MEM1_ADDR_INI_frame_addr1(data)                               (0x1FFFFFFF&(data))
#define MEM1_ADDR_INI_get_frame_addr1(data)                           (0x1FFFFFFF&(data))


#define MEM2_ADDR_INI                                                 0x18019878
#define MEM2_ADDR_INI_reg_addr                                        "0xb8019878"
#define MEM2_ADDR_INI_reg                                             0xb8019878
#define MEM2_ADDR_INI_inst_addr                                       "0x021E"
#define MEM2_ADDR_INI_inst                                            0x021E
#define MEM2_ADDR_INI_frame_addr2_shift                               (0)
#define MEM2_ADDR_INI_frame_addr2_mask                                (0x1FFFFFFF)
#define MEM2_ADDR_INI_frame_addr2(data)                               (0x1FFFFFFF&(data))
#define MEM2_ADDR_INI_get_frame_addr2(data)                           (0x1FFFFFFF&(data))


#define MEM3_ADDR_INI                                                 0x1801987c
#define MEM3_ADDR_INI_reg_addr                                        "0xb801987c"
#define MEM3_ADDR_INI_reg                                             0xb801987c
#define MEM3_ADDR_INI_inst_addr                                       "0x021F"
#define MEM3_ADDR_INI_inst                                            0x021F
#define MEM3_ADDR_INI_frame_addr3_shift                               (0)
#define MEM3_ADDR_INI_frame_addr3_mask                                (0x1FFFFFFF)
#define MEM3_ADDR_INI_frame_addr3(data)                               (0x1FFFFFFF&(data))
#define MEM3_ADDR_INI_get_frame_addr3(data)                           (0x1FFFFFFF&(data))


#define MEM0_ADDR_END                                                 0x18019880
#define MEM0_ADDR_END_reg_addr                                        "0xb8019880"
#define MEM0_ADDR_END_reg                                             0xb8019880
#define MEM0_ADDR_END_inst_addr                                       "0x0220"
#define MEM0_ADDR_END_inst                                            0x0220
#define MEM0_ADDR_END_frame_addr0_end_shift                           (0)
#define MEM0_ADDR_END_frame_addr0_end_mask                            (0x1FFFFFFF)
#define MEM0_ADDR_END_frame_addr0_end(data)                           (0x1FFFFFFF&(data))
#define MEM0_ADDR_END_get_frame_addr0_end(data)                       (0x1FFFFFFF&(data))


#define MEM1_ADDR_END                                                 0x18019884
#define MEM1_ADDR_END_reg_addr                                        "0xb8019884"
#define MEM1_ADDR_END_reg                                             0xb8019884
#define MEM1_ADDR_END_inst_addr                                       "0x0221"
#define MEM1_ADDR_END_inst                                            0x0221
#define MEM1_ADDR_END_frame_addr1_end_shift                           (0)
#define MEM1_ADDR_END_frame_addr1_end_mask                            (0x1FFFFFFF)
#define MEM1_ADDR_END_frame_addr1_end(data)                           (0x1FFFFFFF&(data))
#define MEM1_ADDR_END_get_frame_addr1_end(data)                       (0x1FFFFFFF&(data))


#define MEM2_ADDR_END                                                 0x18019888
#define MEM2_ADDR_END_reg_addr                                        "0xb8019888"
#define MEM2_ADDR_END_reg                                             0xb8019888
#define MEM2_ADDR_END_inst_addr                                       "0x0222"
#define MEM2_ADDR_END_inst                                            0x0222
#define MEM2_ADDR_END_frame_addr2_end_shift                           (0)
#define MEM2_ADDR_END_frame_addr2_end_mask                            (0x1FFFFFFF)
#define MEM2_ADDR_END_frame_addr2_end(data)                           (0x1FFFFFFF&(data))
#define MEM2_ADDR_END_get_frame_addr2_end(data)                       (0x1FFFFFFF&(data))


#define MEM3_ADDR_END                                                 0x1801988c
#define MEM3_ADDR_END_reg_addr                                        "0xb801988c"
#define MEM3_ADDR_END_reg                                             0xb801988c
#define MEM3_ADDR_END_inst_addr                                       "0x0223"
#define MEM3_ADDR_END_inst                                            0x0223
#define MEM3_ADDR_END_frame_addr3_end_shift                           (0)
#define MEM3_ADDR_END_frame_addr3_end_mask                            (0x1FFFFFFF)
#define MEM3_ADDR_END_frame_addr3_end(data)                           (0x1FFFFFFF&(data))
#define MEM3_ADDR_END_get_frame_addr3_end(data)                       (0x1FFFFFFF&(data))


#define DMA_DEBUG_ADDR                                                0x18019890
#define DMA_DEBUG_ADDR_reg_addr                                       "0xb8019890"
#define DMA_DEBUG_ADDR_reg                                            0xb8019890
#define DMA_DEBUG_ADDR_inst_addr                                      "0x0224"
#define DMA_DEBUG_ADDR_inst                                           0x0224
#define DMA_DEBUG_ADDR_dma_debug_adr_shift                            (0)
#define DMA_DEBUG_ADDR_dma_debug_adr_mask                             (0x1FFFFFFF)
#define DMA_DEBUG_ADDR_dma_debug_adr(data)                            (0x1FFFFFFF&(data))
#define DMA_DEBUG_ADDR_get_dma_debug_adr(data)                        (0x1FFFFFFF&(data))


#define DMA_DEBUG_VBI_END_ADDR                                        0x18019894
#define DMA_DEBUG_VBI_END_ADDR_reg_addr                               "0xb8019894"
#define DMA_DEBUG_VBI_END_ADDR_reg                                    0xb8019894
#define DMA_DEBUG_VBI_END_ADDR_inst_addr                              "0x0225"
#define DMA_DEBUG_VBI_END_ADDR_inst                                   0x0225
#define DMA_DEBUG_VBI_END_ADDR_dma_debug_vbiend_adr_shift             (0)
#define DMA_DEBUG_VBI_END_ADDR_dma_debug_vbiend_adr_mask              (0x1FFFFFFF)
#define DMA_DEBUG_VBI_END_ADDR_dma_debug_vbiend_adr(data)             (0x1FFFFFFF&(data))
#define DMA_DEBUG_VBI_END_ADDR_get_dma_debug_vbiend_adr(data)         (0x1FFFFFFF&(data))


#define VIDEO_DMA_DEBUG_CTRL                                          0x18019898
#define VIDEO_DMA_DEBUG_CTRL_reg_addr                                 "0xb8019898"
#define VIDEO_DMA_DEBUG_CTRL_reg                                      0xb8019898
#define VIDEO_DMA_DEBUG_CTRL_inst_addr                                "0x0226"
#define VIDEO_DMA_DEBUG_CTRL_inst                                     0x0226
#define VIDEO_DMA_DEBUG_CTRL_dma_debug_vd_sel_shift                   (4)
#define VIDEO_DMA_DEBUG_CTRL_dma_mode_shift                           (3)
#define VIDEO_DMA_DEBUG_CTRL_dma_debugmode_sel_shift                  (1)
#define VIDEO_DMA_DEBUG_CTRL_dma_debugmode_en_shift                   (0)
#define VIDEO_DMA_DEBUG_CTRL_dma_debug_vd_sel_mask                    (0x000000F0)
#define VIDEO_DMA_DEBUG_CTRL_dma_mode_mask                            (0x00000008)
#define VIDEO_DMA_DEBUG_CTRL_dma_debugmode_sel_mask                   (0x00000006)
#define VIDEO_DMA_DEBUG_CTRL_dma_debugmode_en_mask                    (0x00000001)
#define VIDEO_DMA_DEBUG_CTRL_dma_debug_vd_sel(data)                   (0x000000F0&((data)<<4))
#define VIDEO_DMA_DEBUG_CTRL_dma_mode(data)                           (0x00000008&((data)<<3))
#define VIDEO_DMA_DEBUG_CTRL_dma_debugmode_sel(data)                  (0x00000006&((data)<<1))
#define VIDEO_DMA_DEBUG_CTRL_dma_debugmode_en(data)                   (0x00000001&(data))
#define VIDEO_DMA_DEBUG_CTRL_get_dma_debug_vd_sel(data)               ((0x000000F0&(data))>>4)
#define VIDEO_DMA_DEBUG_CTRL_get_dma_mode(data)                       ((0x00000008&(data))>>3)
#define VIDEO_DMA_DEBUG_CTRL_get_dma_debugmode_sel(data)              ((0x00000006&(data))>>1)
#define VIDEO_DMA_DEBUG_CTRL_get_dma_debugmode_en(data)               (0x00000001&(data))


#define VBIDMA_TEST_CTRL                                              0x1801989c
#define VBIDMA_TEST_CTRL_reg_addr                                     "0xb801989c"
#define VBIDMA_TEST_CTRL_reg                                          0xb801989c
#define VBIDMA_TEST_CTRL_inst_addr                                    "0x0227"
#define VBIDMA_TEST_CTRL_inst                                         0x0227
#define VBIDMA_TEST_CTRL_dma_debug_one_rw_rlt_shift                   (6)
#define VBIDMA_TEST_CTRL_dma_debug_rw_en_shift                        (4)
#define VBIDMA_TEST_CTRL_dma_debug_one_rw_rlt_mask                    (0x00000040)
#define VBIDMA_TEST_CTRL_dma_debug_rw_en_mask                         (0x00000030)
#define VBIDMA_TEST_CTRL_dma_debug_one_rw_rlt(data)                   (0x00000040&((data)<<6))
#define VBIDMA_TEST_CTRL_dma_debug_rw_en(data)                        (0x00000030&((data)<<4))
#define VBIDMA_TEST_CTRL_get_dma_debug_one_rw_rlt(data)               ((0x00000040&(data))>>6)
#define VBIDMA_TEST_CTRL_get_dma_debug_rw_en(data)                    ((0x00000030&(data))>>4)


#define DMA_CNT_CALIBRATION1                                          0x180198a0
#define DMA_CNT_CALIBRATION1_reg_addr                                 "0xb80198a0"
#define DMA_CNT_CALIBRATION1_reg                                      0xb80198a0
#define DMA_CNT_CALIBRATION1_inst_addr                                "0x0228"
#define DMA_CNT_CALIBRATION1_inst                                     0x0228
#define DMA_CNT_CALIBRATION1_calib_delay_hsync_en_shift               (31)
#define DMA_CNT_CALIBRATION1_chase_line_pos_en_shift                  (29)
#define DMA_CNT_CALIBRATION1_calib_delay_frame_sel_shift              (28)
#define DMA_CNT_CALIBRATION1_calib_delay_sel_shift                    (27)
#define DMA_CNT_CALIBRATION1_calib_delay_en_shift                     (26)
#define DMA_CNT_CALIBRATION1_dma_pix_sht_fix_en_shift                 (25)
#define DMA_CNT_CALIBRATION1_chase_per_frame_en_shift                 (24)
#define DMA_CNT_CALIBRATION1_chase_pix_num_shift                      (20)
#define DMA_CNT_CALIBRATION1_pix_sht_st_th_shift                      (0)
#define DMA_CNT_CALIBRATION1_calib_delay_hsync_en_mask                (0x80000000)
#define DMA_CNT_CALIBRATION1_chase_line_pos_en_mask                   (0x60000000)
#define DMA_CNT_CALIBRATION1_calib_delay_frame_sel_mask               (0x10000000)
#define DMA_CNT_CALIBRATION1_calib_delay_sel_mask                     (0x08000000)
#define DMA_CNT_CALIBRATION1_calib_delay_en_mask                      (0x04000000)
#define DMA_CNT_CALIBRATION1_dma_pix_sht_fix_en_mask                  (0x02000000)
#define DMA_CNT_CALIBRATION1_chase_per_frame_en_mask                  (0x01000000)
#define DMA_CNT_CALIBRATION1_chase_pix_num_mask                       (0x00F00000)
#define DMA_CNT_CALIBRATION1_pix_sht_st_th_mask                       (0x000FFFFF)
#define DMA_CNT_CALIBRATION1_calib_delay_hsync_en(data)               (0x80000000&((data)<<31))
#define DMA_CNT_CALIBRATION1_chase_line_pos_en(data)                  (0x60000000&((data)<<29))
#define DMA_CNT_CALIBRATION1_calib_delay_frame_sel(data)              (0x10000000&((data)<<28))
#define DMA_CNT_CALIBRATION1_calib_delay_sel(data)                    (0x08000000&((data)<<27))
#define DMA_CNT_CALIBRATION1_calib_delay_en(data)                     (0x04000000&((data)<<26))
#define DMA_CNT_CALIBRATION1_dma_pix_sht_fix_en(data)                 (0x02000000&((data)<<25))
#define DMA_CNT_CALIBRATION1_chase_per_frame_en(data)                 (0x01000000&((data)<<24))
#define DMA_CNT_CALIBRATION1_chase_pix_num(data)                      (0x00F00000&((data)<<20))
#define DMA_CNT_CALIBRATION1_pix_sht_st_th(data)                      (0x000FFFFF&(data))
#define DMA_CNT_CALIBRATION1_get_calib_delay_hsync_en(data)           ((0x80000000&(data))>>31)
#define DMA_CNT_CALIBRATION1_get_chase_line_pos_en(data)              ((0x60000000&(data))>>29)
#define DMA_CNT_CALIBRATION1_get_calib_delay_frame_sel(data)          ((0x10000000&(data))>>28)
#define DMA_CNT_CALIBRATION1_get_calib_delay_sel(data)                ((0x08000000&(data))>>27)
#define DMA_CNT_CALIBRATION1_get_calib_delay_en(data)                 ((0x04000000&(data))>>26)
#define DMA_CNT_CALIBRATION1_get_dma_pix_sht_fix_en(data)             ((0x02000000&(data))>>25)
#define DMA_CNT_CALIBRATION1_get_chase_per_frame_en(data)             ((0x01000000&(data))>>24)
#define DMA_CNT_CALIBRATION1_get_chase_pix_num(data)                  ((0x00F00000&(data))>>20)
#define DMA_CNT_CALIBRATION1_get_pix_sht_st_th(data)                  (0x000FFFFF&(data))


#define DMA_CNT_CALIBRATION2                                          0x180198a4
#define DMA_CNT_CALIBRATION2_reg_addr                                 "0xb80198a4"
#define DMA_CNT_CALIBRATION2_reg                                      0xb80198a4
#define DMA_CNT_CALIBRATION2_inst_addr                                "0x0229"
#define DMA_CNT_CALIBRATION2_inst                                     0x0229
#define DMA_CNT_CALIBRATION2_fscnum_dif_abs_sel_shift                 (29)
#define DMA_CNT_CALIBRATION2_pix_sht_limit_en_shift                   (28)
#define DMA_CNT_CALIBRATION2_pix_sht_limit_th_shift                   (20)
#define DMA_CNT_CALIBRATION2_pix_sht_end_th_shift                     (0)
#define DMA_CNT_CALIBRATION2_fscnum_dif_abs_sel_mask                  (0x60000000)
#define DMA_CNT_CALIBRATION2_pix_sht_limit_en_mask                    (0x10000000)
#define DMA_CNT_CALIBRATION2_pix_sht_limit_th_mask                    (0x0FF00000)
#define DMA_CNT_CALIBRATION2_pix_sht_end_th_mask                      (0x000FFFFF)
#define DMA_CNT_CALIBRATION2_fscnum_dif_abs_sel(data)                 (0x60000000&((data)<<29))
#define DMA_CNT_CALIBRATION2_pix_sht_limit_en(data)                   (0x10000000&((data)<<28))
#define DMA_CNT_CALIBRATION2_pix_sht_limit_th(data)                   (0x0FF00000&((data)<<20))
#define DMA_CNT_CALIBRATION2_pix_sht_end_th(data)                     (0x000FFFFF&(data))
#define DMA_CNT_CALIBRATION2_get_fscnum_dif_abs_sel(data)             ((0x60000000&(data))>>29)
#define DMA_CNT_CALIBRATION2_get_pix_sht_limit_en(data)               ((0x10000000&(data))>>28)
#define DMA_CNT_CALIBRATION2_get_pix_sht_limit_th(data)               ((0x0FF00000&(data))>>20)
#define DMA_CNT_CALIBRATION2_get_pix_sht_end_th(data)                 (0x000FFFFF&(data))


#define DMA_CNT_CALIBRATION3                                          0x180198a8
#define DMA_CNT_CALIBRATION3_reg_addr                                 "0xb80198a8"
#define DMA_CNT_CALIBRATION3_reg                                      0xb80198a8
#define DMA_CNT_CALIBRATION3_inst_addr                                "0x022A"
#define DMA_CNT_CALIBRATION3_inst                                     0x022A
#define DMA_CNT_CALIBRATION3_fscdif_num_abs_shift                     (24)
#define DMA_CNT_CALIBRATION3_fscdif_sum_abs_shift                     (0)
#define DMA_CNT_CALIBRATION3_fscdif_num_abs_mask                      (0x3F000000)
#define DMA_CNT_CALIBRATION3_fscdif_sum_abs_mask                      (0x000FFFFF)
#define DMA_CNT_CALIBRATION3_fscdif_num_abs(data)                     (0x3F000000&((data)<<24))
#define DMA_CNT_CALIBRATION3_fscdif_sum_abs(data)                     (0x000FFFFF&(data))
#define DMA_CNT_CALIBRATION3_get_fscdif_num_abs(data)                 ((0x3F000000&(data))>>24)
#define DMA_CNT_CALIBRATION3_get_fscdif_sum_abs(data)                 (0x000FFFFF&(data))


#define FRAME_BUFFER_F1_STATUS                                        0x180198d0
#define FRAME_BUFFER_F1_STATUS_reg_addr                               "0xb80198d0"
#define FRAME_BUFFER_F1_STATUS_reg                                    0xb80198d0
#define FRAME_BUFFER_F1_STATUS_inst_addr                              "0x0234"
#define FRAME_BUFFER_F1_STATUS_inst                                   0x0234
#define FRAME_BUFFER_F1_STATUS_f1_cennum_shift                        (0)
#define FRAME_BUFFER_F1_STATUS_f1_cennum_mask                         (0x0000FFFF)
#define FRAME_BUFFER_F1_STATUS_f1_cennum(data)                        (0x0000FFFF&(data))
#define FRAME_BUFFER_F1_STATUS_get_f1_cennum(data)                    (0x0000FFFF&(data))


#define FRAME_BUFFER_F2_STATUS                                        0x180198d4
#define FRAME_BUFFER_F2_STATUS_reg_addr                               "0xb80198d4"
#define FRAME_BUFFER_F2_STATUS_reg                                    0xb80198d4
#define FRAME_BUFFER_F2_STATUS_inst_addr                              "0x0235"
#define FRAME_BUFFER_F2_STATUS_inst                                   0x0235
#define FRAME_BUFFER_F2_STATUS_f2_cennum_shift                        (0)
#define FRAME_BUFFER_F2_STATUS_f2_cennum_mask                         (0x0000FFFF)
#define FRAME_BUFFER_F2_STATUS_f2_cennum(data)                        (0x0000FFFF&(data))
#define FRAME_BUFFER_F2_STATUS_get_f2_cennum(data)                    (0x0000FFFF&(data))


#define DUMMY_1                                                       0x180198d8
#define DUMMY_1_reg_addr                                              "0xb80198d8"
#define DUMMY_1_reg                                                   0xb80198d8
#define DUMMY_1_inst_addr                                             "0x0236"
#define DUMMY_1_inst                                                  0x0236
#define DUMMY_1_dummy_1_shift                                         (0)
#define DUMMY_1_dummy_1_mask                                          (0xFFFFFFFF)
#define DUMMY_1_dummy_1(data)                                         (0xFFFFFFFF&(data))
#define DUMMY_1_get_dummy_1(data)                                     (0xFFFFFFFF&(data))


#define YC_SEP_CONTROL                                                0x18019900
#define YC_SEP_CONTROL_reg_addr                                       "0xb8019900"
#define YC_SEP_CONTROL_reg                                            0xb8019900
#define YC_SEP_CONTROL_inst_addr                                      "0x0240"
#define YC_SEP_CONTROL_inst                                           0x0240
#define YC_SEP_CONTROL_yc3d_tb_en_shift                               (31)
#define YC_SEP_CONTROL_yc_linebf_sel_shift                            (4)
#define YC_SEP_CONTROL_yc_2d_decode_sel_shift                         (3)
#define YC_SEP_CONTROL_adaptive_mode_shift                            (0)
#define YC_SEP_CONTROL_yc3d_tb_en_mask                                (0x80000000)
#define YC_SEP_CONTROL_yc_linebf_sel_mask                             (0x00000010)
#define YC_SEP_CONTROL_yc_2d_decode_sel_mask                          (0x00000008)
#define YC_SEP_CONTROL_adaptive_mode_mask                             (0x00000007)
#define YC_SEP_CONTROL_yc3d_tb_en(data)                               (0x80000000&((data)<<31))
#define YC_SEP_CONTROL_yc_linebf_sel(data)                            (0x00000010&((data)<<4))
#define YC_SEP_CONTROL_yc_2d_decode_sel(data)                         (0x00000008&((data)<<3))
#define YC_SEP_CONTROL_adaptive_mode(data)                            (0x00000007&(data))
#define YC_SEP_CONTROL_get_yc3d_tb_en(data)                           ((0x80000000&(data))>>31)
#define YC_SEP_CONTROL_get_yc_linebf_sel(data)                        ((0x00000010&(data))>>4)
#define YC_SEP_CONTROL_get_yc_2d_decode_sel(data)                     ((0x00000008&(data))>>3)
#define YC_SEP_CONTROL_get_adaptive_mode(data)                        (0x00000007&(data))


#define BPF_BW_SEL_Y                                                  0x18019904
#define BPF_BW_SEL_Y_reg_addr                                         "0xb8019904"
#define BPF_BW_SEL_Y_reg                                              0xb8019904
#define BPF_BW_SEL_Y_inst_addr                                        "0x0241"
#define BPF_BW_SEL_Y_inst                                             0x0241
#define BPF_BW_SEL_Y_wide_bpf_sel_y_shift                             (8)
#define BPF_BW_SEL_Y_mid_bpf_sel_y_shift                              (4)
#define BPF_BW_SEL_Y_narrow_bpf_sel_y_shift                           (0)
#define BPF_BW_SEL_Y_wide_bpf_sel_y_mask                              (0x00000F00)
#define BPF_BW_SEL_Y_mid_bpf_sel_y_mask                               (0x000000F0)
#define BPF_BW_SEL_Y_narrow_bpf_sel_y_mask                            (0x0000000F)
#define BPF_BW_SEL_Y_wide_bpf_sel_y(data)                             (0x00000F00&((data)<<8))
#define BPF_BW_SEL_Y_mid_bpf_sel_y(data)                              (0x000000F0&((data)<<4))
#define BPF_BW_SEL_Y_narrow_bpf_sel_y(data)                           (0x0000000F&(data))
#define BPF_BW_SEL_Y_get_wide_bpf_sel_y(data)                         ((0x00000F00&(data))>>8)
#define BPF_BW_SEL_Y_get_mid_bpf_sel_y(data)                          ((0x000000F0&(data))>>4)
#define BPF_BW_SEL_Y_get_narrow_bpf_sel_y(data)                       (0x0000000F&(data))


#define BPF_BW_SEL_C                                                  0x18019908
#define BPF_BW_SEL_C_reg_addr                                         "0xb8019908"
#define BPF_BW_SEL_C_reg                                              0xb8019908
#define BPF_BW_SEL_C_inst_addr                                        "0x0242"
#define BPF_BW_SEL_C_inst                                             0x0242
#define BPF_BW_SEL_C_wide_bpf_sel_c_shift                             (8)
#define BPF_BW_SEL_C_mid_bpf_sel_c_shift                              (4)
#define BPF_BW_SEL_C_narrow_bpf_sel_c_shift                           (0)
#define BPF_BW_SEL_C_wide_bpf_sel_c_mask                              (0x00000F00)
#define BPF_BW_SEL_C_mid_bpf_sel_c_mask                               (0x000000F0)
#define BPF_BW_SEL_C_narrow_bpf_sel_c_mask                            (0x0000000F)
#define BPF_BW_SEL_C_wide_bpf_sel_c(data)                             (0x00000F00&((data)<<8))
#define BPF_BW_SEL_C_mid_bpf_sel_c(data)                              (0x000000F0&((data)<<4))
#define BPF_BW_SEL_C_narrow_bpf_sel_c(data)                           (0x0000000F&(data))
#define BPF_BW_SEL_C_get_wide_bpf_sel_c(data)                         ((0x00000F00&(data))>>8)
#define BPF_BW_SEL_C_get_mid_bpf_sel_c(data)                          ((0x000000F0&(data))>>4)
#define BPF_BW_SEL_C_get_narrow_bpf_sel_c(data)                       (0x0000000F&(data))


#define ADAP_BPF_C_TH1                                                0x1801990c
#define ADAP_BPF_C_TH1_reg_addr                                       "0xb801990c"
#define ADAP_BPF_C_TH1_reg                                            0xb801990c
#define ADAP_BPF_C_TH1_inst_addr                                      "0x0243"
#define ADAP_BPF_C_TH1_inst                                           0x0243
#define ADAP_BPF_C_TH1_h2v_lk_en_shift                                (7)
#define ADAP_BPF_C_TH1_v2v_lk_y_en_shift                              (5)
#define ADAP_BPF_C_TH1_v2v_lk_c_en_shift                              (4)
#define ADAP_BPF_C_TH1_h2v_mid_sel_y_shift                            (3)
#define ADAP_BPF_C_TH1_h2v_mid_sel_c_shift                            (2)
#define ADAP_BPF_C_TH1_h2v_near_sel_y_shift                           (1)
#define ADAP_BPF_C_TH1_h2v_near_sel_c_shift                           (0)
#define ADAP_BPF_C_TH1_h2v_lk_en_mask                                 (0x00000080)
#define ADAP_BPF_C_TH1_v2v_lk_y_en_mask                               (0x00000020)
#define ADAP_BPF_C_TH1_v2v_lk_c_en_mask                               (0x00000010)
#define ADAP_BPF_C_TH1_h2v_mid_sel_y_mask                             (0x00000008)
#define ADAP_BPF_C_TH1_h2v_mid_sel_c_mask                             (0x00000004)
#define ADAP_BPF_C_TH1_h2v_near_sel_y_mask                            (0x00000002)
#define ADAP_BPF_C_TH1_h2v_near_sel_c_mask                            (0x00000001)
#define ADAP_BPF_C_TH1_h2v_lk_en(data)                                (0x00000080&((data)<<7))
#define ADAP_BPF_C_TH1_v2v_lk_y_en(data)                              (0x00000020&((data)<<5))
#define ADAP_BPF_C_TH1_v2v_lk_c_en(data)                              (0x00000010&((data)<<4))
#define ADAP_BPF_C_TH1_h2v_mid_sel_y(data)                            (0x00000008&((data)<<3))
#define ADAP_BPF_C_TH1_h2v_mid_sel_c(data)                            (0x00000004&((data)<<2))
#define ADAP_BPF_C_TH1_h2v_near_sel_y(data)                           (0x00000002&((data)<<1))
#define ADAP_BPF_C_TH1_h2v_near_sel_c(data)                           (0x00000001&(data))
#define ADAP_BPF_C_TH1_get_h2v_lk_en(data)                            ((0x00000080&(data))>>7)
#define ADAP_BPF_C_TH1_get_v2v_lk_y_en(data)                          ((0x00000020&(data))>>5)
#define ADAP_BPF_C_TH1_get_v2v_lk_c_en(data)                          ((0x00000010&(data))>>4)
#define ADAP_BPF_C_TH1_get_h2v_mid_sel_y(data)                        ((0x00000008&(data))>>3)
#define ADAP_BPF_C_TH1_get_h2v_mid_sel_c(data)                        ((0x00000004&(data))>>2)
#define ADAP_BPF_C_TH1_get_h2v_near_sel_y(data)                       ((0x00000002&(data))>>1)
#define ADAP_BPF_C_TH1_get_h2v_near_sel_c(data)                       (0x00000001&(data))


#define ADAP_BPF_C_TH2                                                0x18019910
#define ADAP_BPF_C_TH2_reg_addr                                       "0xb8019910"
#define ADAP_BPF_C_TH2_reg                                            0xb8019910
#define ADAP_BPF_C_TH2_inst_addr                                      "0x0244"
#define ADAP_BPF_C_TH2_inst                                           0x0244
#define ADAP_BPF_C_TH2_h2v_vflag_remag_thr_shift                      (4)
#define ADAP_BPF_C_TH2_h2v_vflag_mag_thr_shift                        (0)
#define ADAP_BPF_C_TH2_h2v_vflag_remag_thr_mask                       (0x000000F0)
#define ADAP_BPF_C_TH2_h2v_vflag_mag_thr_mask                         (0x0000000F)
#define ADAP_BPF_C_TH2_h2v_vflag_remag_thr(data)                      (0x000000F0&((data)<<4))
#define ADAP_BPF_C_TH2_h2v_vflag_mag_thr(data)                        (0x0000000F&(data))
#define ADAP_BPF_C_TH2_get_h2v_vflag_remag_thr(data)                  ((0x000000F0&(data))>>4)
#define ADAP_BPF_C_TH2_get_h2v_vflag_mag_thr(data)                    (0x0000000F&(data))


#define COMB_FILTER_CONFIG                                            0x18019914
#define COMB_FILTER_CONFIG_reg_addr                                   "0xb8019914"
#define COMB_FILTER_CONFIG_reg                                        0xb8019914
#define COMB_FILTER_CONFIG_inst_addr                                  "0x0245"
#define COMB_FILTER_CONFIG_inst                                       0x0245
#define COMB_FILTER_CONFIG_pal_perr_shift                             (6)
#define COMB_FILTER_CONFIG_pal_perr_auto_en_shift                     (5)
#define COMB_FILTER_CONFIG_palsw_level_shift                          (0)
#define COMB_FILTER_CONFIG_pal_perr_mask                              (0x00000040)
#define COMB_FILTER_CONFIG_pal_perr_auto_en_mask                      (0x00000020)
#define COMB_FILTER_CONFIG_palsw_level_mask                           (0x00000003)
#define COMB_FILTER_CONFIG_pal_perr(data)                             (0x00000040&((data)<<6))
#define COMB_FILTER_CONFIG_pal_perr_auto_en(data)                     (0x00000020&((data)<<5))
#define COMB_FILTER_CONFIG_palsw_level(data)                          (0x00000003&(data))
#define COMB_FILTER_CONFIG_get_pal_perr(data)                         ((0x00000040&(data))>>6)
#define COMB_FILTER_CONFIG_get_pal_perr_auto_en(data)                 ((0x00000020&(data))>>5)
#define COMB_FILTER_CONFIG_get_palsw_level(data)                      (0x00000003&(data))


#define COMB_FILTER_THRESHOLD1                                        0x18019918
#define COMB_FILTER_THRESHOLD1_reg_addr                               "0xb8019918"
#define COMB_FILTER_THRESHOLD1_reg                                    0xb8019918
#define COMB_FILTER_THRESHOLD1_inst_addr                              "0x0246"
#define COMB_FILTER_THRESHOLD1_inst                                   0x0246
#define COMB_FILTER_THRESHOLD1_noise_ntsc_c_shift                     (0)
#define COMB_FILTER_THRESHOLD1_noise_ntsc_c_mask                      (0x000000FF)
#define COMB_FILTER_THRESHOLD1_noise_ntsc_c(data)                     (0x000000FF&(data))
#define COMB_FILTER_THRESHOLD1_get_noise_ntsc_c(data)                 (0x000000FF&(data))


#define ADAP_BPF_Y_TH3                                                0x18019928
#define ADAP_BPF_Y_TH3_reg_addr                                       "0xb8019928"
#define ADAP_BPF_Y_TH3_reg                                            0xb8019928
#define ADAP_BPF_Y_TH3_inst_addr                                      "0x024A"
#define ADAP_BPF_Y_TH3_inst                                           0x024A
#define ADAP_BPF_Y_TH3_malpha_c_divider2_sel_shift                    (7)
#define ADAP_BPF_Y_TH3_malpha_y_divider2_sel_shift                    (6)
#define ADAP_BPF_Y_TH3_malpha_y_en_shift                              (5)
#define ADAP_BPF_Y_TH3_malpha_y_shift                                 (4)
#define ADAP_BPF_Y_TH3_malpha_c_en_shift                              (3)
#define ADAP_BPF_Y_TH3_malpha_c_shift                                 (2)
#define ADAP_BPF_Y_TH3_yalpha_en_shift                                (1)
#define ADAP_BPF_Y_TH3_yalpha_shift                                   (0)
#define ADAP_BPF_Y_TH3_malpha_c_divider2_sel_mask                     (0x00000080)
#define ADAP_BPF_Y_TH3_malpha_y_divider2_sel_mask                     (0x00000040)
#define ADAP_BPF_Y_TH3_malpha_y_en_mask                               (0x00000020)
#define ADAP_BPF_Y_TH3_malpha_y_mask                                  (0x00000010)
#define ADAP_BPF_Y_TH3_malpha_c_en_mask                               (0x00000008)
#define ADAP_BPF_Y_TH3_malpha_c_mask                                  (0x00000004)
#define ADAP_BPF_Y_TH3_yalpha_en_mask                                 (0x00000002)
#define ADAP_BPF_Y_TH3_yalpha_mask                                    (0x00000001)
#define ADAP_BPF_Y_TH3_malpha_c_divider2_sel(data)                    (0x00000080&((data)<<7))
#define ADAP_BPF_Y_TH3_malpha_y_divider2_sel(data)                    (0x00000040&((data)<<6))
#define ADAP_BPF_Y_TH3_malpha_y_en(data)                              (0x00000020&((data)<<5))
#define ADAP_BPF_Y_TH3_malpha_y(data)                                 (0x00000010&((data)<<4))
#define ADAP_BPF_Y_TH3_malpha_c_en(data)                              (0x00000008&((data)<<3))
#define ADAP_BPF_Y_TH3_malpha_c(data)                                 (0x00000004&((data)<<2))
#define ADAP_BPF_Y_TH3_yalpha_en(data)                                (0x00000002&((data)<<1))
#define ADAP_BPF_Y_TH3_yalpha(data)                                   (0x00000001&(data))
#define ADAP_BPF_Y_TH3_get_malpha_c_divider2_sel(data)                ((0x00000080&(data))>>7)
#define ADAP_BPF_Y_TH3_get_malpha_y_divider2_sel(data)                ((0x00000040&(data))>>6)
#define ADAP_BPF_Y_TH3_get_malpha_y_en(data)                          ((0x00000020&(data))>>5)
#define ADAP_BPF_Y_TH3_get_malpha_y(data)                             ((0x00000010&(data))>>4)
#define ADAP_BPF_Y_TH3_get_malpha_c_en(data)                          ((0x00000008&(data))>>3)
#define ADAP_BPF_Y_TH3_get_malpha_c(data)                             ((0x00000004&(data))>>2)
#define ADAP_BPF_Y_TH3_get_yalpha_en(data)                            ((0x00000002&(data))>>1)
#define ADAP_BPF_Y_TH3_get_yalpha(data)                               (0x00000001&(data))


#define YC_BW_CTRL                                                    0x1801992c
#define YC_BW_CTRL_reg_addr                                           "0xb801992c"
#define YC_BW_CTRL_reg                                                0xb801992c
#define YC_BW_CTRL_inst_addr                                          "0x024B"
#define YC_BW_CTRL_inst                                               0x024B
#define YC_BW_CTRL_pal_demod_sel_shift                                (6)
#define YC_BW_CTRL_chroma_vlpf_en_shift                               (3)
#define YC_BW_CTRL_chroma_bw_lo_shift                                 (0)
#define YC_BW_CTRL_pal_demod_sel_mask                                 (0x00000040)
#define YC_BW_CTRL_chroma_vlpf_en_mask                                (0x00000008)
#define YC_BW_CTRL_chroma_bw_lo_mask                                  (0x00000007)
#define YC_BW_CTRL_pal_demod_sel(data)                                (0x00000040&((data)<<6))
#define YC_BW_CTRL_chroma_vlpf_en(data)                               (0x00000008&((data)<<3))
#define YC_BW_CTRL_chroma_bw_lo(data)                                 (0x00000007&(data))
#define YC_BW_CTRL_get_pal_demod_sel(data)                            ((0x00000040&(data))>>6)
#define YC_BW_CTRL_get_chroma_vlpf_en(data)                           ((0x00000008&(data))>>3)
#define YC_BW_CTRL_get_chroma_bw_lo(data)                             (0x00000007&(data))


#define DEBUG_2D_MODE                                                 0x18019930
#define DEBUG_2D_MODE_reg_addr                                        "0xb8019930"
#define DEBUG_2D_MODE_reg                                             0xb8019930
#define DEBUG_2D_MODE_inst_addr                                       "0x024C"
#define DEBUG_2D_MODE_inst                                            0x024C
#define DEBUG_2D_MODE_debug_mode_2d_en_shift                          (4)
#define DEBUG_2D_MODE_debug_mode_2d_shift                             (0)
#define DEBUG_2D_MODE_debug_mode_2d_en_mask                           (0x00000010)
#define DEBUG_2D_MODE_debug_mode_2d_mask                              (0x0000000F)
#define DEBUG_2D_MODE_debug_mode_2d_en(data)                          (0x00000010&((data)<<4))
#define DEBUG_2D_MODE_debug_mode_2d(data)                             (0x0000000F&(data))
#define DEBUG_2D_MODE_get_debug_mode_2d_en(data)                      ((0x00000010&(data))>>4)
#define DEBUG_2D_MODE_get_debug_mode_2d(data)                         (0x0000000F&(data))


#define BW_DETECTION                                                  0x18019934
#define BW_DETECTION_reg_addr                                         "0xb8019934"
#define BW_DETECTION_reg                                              0xb8019934
#define BW_DETECTION_inst_addr                                        "0x024D"
#define BW_DETECTION_inst                                             0x024D
#define BW_DETECTION_bw_gain_sel_shift                                (6)
#define BW_DETECTION_bw_detect_thr_shift                              (0)
#define BW_DETECTION_bw_gain_sel_mask                                 (0x000000C0)
#define BW_DETECTION_bw_detect_thr_mask                               (0x0000003F)
#define BW_DETECTION_bw_gain_sel(data)                                (0x000000C0&((data)<<6))
#define BW_DETECTION_bw_detect_thr(data)                              (0x0000003F&(data))
#define BW_DETECTION_get_bw_gain_sel(data)                            ((0x000000C0&(data))>>6)
#define BW_DETECTION_get_bw_detect_thr(data)                          (0x0000003F&(data))


#define BW_EDGE_THR                                                   0x18019938
#define BW_EDGE_THR_reg_addr                                          "0xb8019938"
#define BW_EDGE_THR_reg                                               0xb8019938
#define BW_EDGE_THR_inst_addr                                         "0x024E"
#define BW_EDGE_THR_inst                                              0x024E
#define BW_EDGE_THR_bw_edge_thr_shift                                 (0)
#define BW_EDGE_THR_bw_edge_thr_mask                                  (0x000000FF)
#define BW_EDGE_THR_bw_edge_thr(data)                                 (0x000000FF&(data))
#define BW_EDGE_THR_get_bw_edge_thr(data)                             (0x000000FF&(data))


#define BLEND_1D_THR                                                  0x1801993c
#define BLEND_1D_THR_reg_addr                                         "0xb801993c"
#define BLEND_1D_THR_reg                                              0xb801993c
#define BLEND_1D_THR_inst_addr                                        "0x024F"
#define BLEND_1D_THR_inst                                             0x024F
#define BLEND_1D_THR_same_phase_diff_1d_gauge_en_shift                (8)
#define BLEND_1D_THR_blend_1d_thr_shift                               (2)
#define BLEND_1D_THR_bpf_1d_sel_y_shift                               (0)
#define BLEND_1D_THR_same_phase_diff_1d_gauge_en_mask                 (0x00000100)
#define BLEND_1D_THR_blend_1d_thr_mask                                (0x0000007C)
#define BLEND_1D_THR_bpf_1d_sel_y_mask                                (0x00000003)
#define BLEND_1D_THR_same_phase_diff_1d_gauge_en(data)                (0x00000100&((data)<<8))
#define BLEND_1D_THR_blend_1d_thr(data)                               (0x0000007C&((data)<<2))
#define BLEND_1D_THR_bpf_1d_sel_y(data)                               (0x00000003&(data))
#define BLEND_1D_THR_get_same_phase_diff_1d_gauge_en(data)            ((0x00000100&(data))>>8)
#define BLEND_1D_THR_get_blend_1d_thr(data)                           ((0x0000007C&(data))>>2)
#define BLEND_1D_THR_get_bpf_1d_sel_y(data)                           (0x00000003&(data))


#define BLEND_1D_BPF_SEL                                              0x18019940
#define BLEND_1D_BPF_SEL_reg_addr                                     "0xb8019940"
#define BLEND_1D_BPF_SEL_reg                                          0xb8019940
#define BLEND_1D_BPF_SEL_inst_addr                                    "0x0250"
#define BLEND_1D_BPF_SEL_inst                                         0x0250
#define BLEND_1D_BPF_SEL_narrow_1d_bpf_sel_c_shift                    (4)
#define BLEND_1D_BPF_SEL_wide_1d_bpf_sel_c_shift                      (0)
#define BLEND_1D_BPF_SEL_narrow_1d_bpf_sel_c_mask                     (0x00000070)
#define BLEND_1D_BPF_SEL_wide_1d_bpf_sel_c_mask                       (0x00000007)
#define BLEND_1D_BPF_SEL_narrow_1d_bpf_sel_c(data)                    (0x00000070&((data)<<4))
#define BLEND_1D_BPF_SEL_wide_1d_bpf_sel_c(data)                      (0x00000007&(data))
#define BLEND_1D_BPF_SEL_get_narrow_1d_bpf_sel_c(data)                ((0x00000070&(data))>>4)
#define BLEND_1D_BPF_SEL_get_wide_1d_bpf_sel_c(data)                  (0x00000007&(data))


#define ALPHA_2D_MOD_ENABLE                                           0x18019944
#define ALPHA_2D_MOD_ENABLE_reg_addr                                  "0xb8019944"
#define ALPHA_2D_MOD_ENABLE_reg                                       0xb8019944
#define ALPHA_2D_MOD_ENABLE_inst_addr                                 "0x0251"
#define ALPHA_2D_MOD_ENABLE_inst                                      0x0251
#define ALPHA_2D_MOD_ENABLE_force_halpha_en_shift                     (31)
#define ALPHA_2D_MOD_ENABLE_halpha_shift                              (24)
#define ALPHA_2D_MOD_ENABLE_lut_large_th_shift                        (16)
#define ALPHA_2D_MOD_ENABLE_lut_fuzzy_th_shift                        (12)
#define ALPHA_2D_MOD_ENABLE_lut_sel_y_shift                           (8)
#define ALPHA_2D_MOD_ENABLE_lut_sel_c_shift                           (4)
#define ALPHA_2D_MOD_ENABLE_h2v_coring_thr_shift                      (0)
#define ALPHA_2D_MOD_ENABLE_force_halpha_en_mask                      (0x80000000)
#define ALPHA_2D_MOD_ENABLE_halpha_mask                               (0x0F000000)
#define ALPHA_2D_MOD_ENABLE_lut_large_th_mask                         (0x001F0000)
#define ALPHA_2D_MOD_ENABLE_lut_fuzzy_th_mask                         (0x0000F000)
#define ALPHA_2D_MOD_ENABLE_lut_sel_y_mask                            (0x00000700)
#define ALPHA_2D_MOD_ENABLE_lut_sel_c_mask                            (0x00000070)
#define ALPHA_2D_MOD_ENABLE_h2v_coring_thr_mask                       (0x00000007)
#define ALPHA_2D_MOD_ENABLE_force_halpha_en(data)                     (0x80000000&((data)<<31))
#define ALPHA_2D_MOD_ENABLE_halpha(data)                              (0x0F000000&((data)<<24))
#define ALPHA_2D_MOD_ENABLE_lut_large_th(data)                        (0x001F0000&((data)<<16))
#define ALPHA_2D_MOD_ENABLE_lut_fuzzy_th(data)                        (0x0000F000&((data)<<12))
#define ALPHA_2D_MOD_ENABLE_lut_sel_y(data)                           (0x00000700&((data)<<8))
#define ALPHA_2D_MOD_ENABLE_lut_sel_c(data)                           (0x00000070&((data)<<4))
#define ALPHA_2D_MOD_ENABLE_h2v_coring_thr(data)                      (0x00000007&(data))
#define ALPHA_2D_MOD_ENABLE_get_force_halpha_en(data)                 ((0x80000000&(data))>>31)
#define ALPHA_2D_MOD_ENABLE_get_halpha(data)                          ((0x0F000000&(data))>>24)
#define ALPHA_2D_MOD_ENABLE_get_lut_large_th(data)                    ((0x001F0000&(data))>>16)
#define ALPHA_2D_MOD_ENABLE_get_lut_fuzzy_th(data)                    ((0x0000F000&(data))>>12)
#define ALPHA_2D_MOD_ENABLE_get_lut_sel_y(data)                       ((0x00000700&(data))>>8)
#define ALPHA_2D_MOD_ENABLE_get_lut_sel_c(data)                       ((0x00000070&(data))>>4)
#define ALPHA_2D_MOD_ENABLE_get_h2v_coring_thr(data)                  (0x00000007&(data))


#define H2V_CORING_THR                                                0x18019948
#define H2V_CORING_THR_reg_addr                                       "0xb8019948"
#define H2V_CORING_THR_reg                                            0xb8019948
#define H2V_CORING_THR_inst_addr                                      "0x0252"
#define H2V_CORING_THR_inst                                           0x0252
#define H2V_CORING_THR_h2v_cvbs_coring_thr_shift                      (4)
#define H2V_CORING_THR_h2v_bw_color_gain_shift                        (0)
#define H2V_CORING_THR_h2v_cvbs_coring_thr_mask                       (0x00000070)
#define H2V_CORING_THR_h2v_bw_color_gain_mask                         (0x0000000F)
#define H2V_CORING_THR_h2v_cvbs_coring_thr(data)                      (0x00000070&((data)<<4))
#define H2V_CORING_THR_h2v_bw_color_gain(data)                        (0x0000000F&(data))
#define H2V_CORING_THR_get_h2v_cvbs_coring_thr(data)                  ((0x00000070&(data))>>4)
#define H2V_CORING_THR_get_h2v_bw_color_gain(data)                    (0x0000000F&(data))


#define H2V_Y_NOISE_THR                                               0x1801994c
#define H2V_Y_NOISE_THR_reg_addr                                      "0xb801994c"
#define H2V_Y_NOISE_THR_reg                                           0xb801994c
#define H2V_Y_NOISE_THR_inst_addr                                     "0x0253"
#define H2V_Y_NOISE_THR_inst                                          0x0253
#define H2V_Y_NOISE_THR_h2v_y_noise_thr_shift                         (0)
#define H2V_Y_NOISE_THR_h2v_y_noise_thr_mask                          (0x000000FF)
#define H2V_Y_NOISE_THR_h2v_y_noise_thr(data)                         (0x000000FF&(data))
#define H2V_Y_NOISE_THR_get_h2v_y_noise_thr(data)                     (0x000000FF&(data))


#define H2V_CVBS_NOISE_THR                                            0x18019950
#define H2V_CVBS_NOISE_THR_reg_addr                                   "0xb8019950"
#define H2V_CVBS_NOISE_THR_reg                                        0xb8019950
#define H2V_CVBS_NOISE_THR_inst_addr                                  "0x0254"
#define H2V_CVBS_NOISE_THR_inst                                       0x0254
#define H2V_CVBS_NOISE_THR_h2v_cvbs_noise_thr_shift                   (0)
#define H2V_CVBS_NOISE_THR_h2v_cvbs_noise_thr_mask                    (0x000000FF)
#define H2V_CVBS_NOISE_THR_h2v_cvbs_noise_thr(data)                   (0x000000FF&(data))
#define H2V_CVBS_NOISE_THR_get_h2v_cvbs_noise_thr(data)               (0x000000FF&(data))


#define H2V_NOISE_MAX_HDY                                             0x18019954
#define H2V_NOISE_MAX_HDY_reg_addr                                    "0xb8019954"
#define H2V_NOISE_MAX_HDY_reg                                         0xb8019954
#define H2V_NOISE_MAX_HDY_inst_addr                                   "0x0255"
#define H2V_NOISE_MAX_HDY_inst                                        0x0255
#define H2V_NOISE_MAX_HDY_h2v_noise_max_hdy_shift                     (0)
#define H2V_NOISE_MAX_HDY_h2v_noise_max_hdy_mask                      (0x000000FF)
#define H2V_NOISE_MAX_HDY_h2v_noise_max_hdy(data)                     (0x000000FF&(data))
#define H2V_NOISE_MAX_HDY_get_h2v_noise_max_hdy(data)                 (0x000000FF&(data))


#define H2V_NOISE_Y_ADD_DC                                            0x18019958
#define H2V_NOISE_Y_ADD_DC_reg_addr                                   "0xb8019958"
#define H2V_NOISE_Y_ADD_DC_reg                                        0xb8019958
#define H2V_NOISE_Y_ADD_DC_inst_addr                                  "0x0256"
#define H2V_NOISE_Y_ADD_DC_inst                                       0x0256
#define H2V_NOISE_Y_ADD_DC_v2v_noise_y_add_dc_shift                   (0)
#define H2V_NOISE_Y_ADD_DC_v2v_noise_y_add_dc_mask                    (0x000000FF)
#define H2V_NOISE_Y_ADD_DC_v2v_noise_y_add_dc(data)                   (0x000000FF&(data))
#define H2V_NOISE_Y_ADD_DC_get_v2v_noise_y_add_dc(data)               (0x000000FF&(data))


#define H2V_BLEND_RATIO                                               0x1801995c
#define H2V_BLEND_RATIO_reg_addr                                      "0xb801995c"
#define H2V_BLEND_RATIO_reg                                           0xb801995c
#define H2V_BLEND_RATIO_inst_addr                                     "0x0257"
#define H2V_BLEND_RATIO_inst                                          0x0257
#define H2V_BLEND_RATIO_h2v_blendratio_shift                          (0)
#define H2V_BLEND_RATIO_h2v_blendratio_mask                           (0x00000007)
#define H2V_BLEND_RATIO_h2v_blendratio(data)                          (0x00000007&(data))
#define H2V_BLEND_RATIO_get_h2v_blendratio(data)                      (0x00000007&(data))


#define ADAP_BPF_Y_TH2                                                0x18019960
#define ADAP_BPF_Y_TH2_reg_addr                                       "0xb8019960"
#define ADAP_BPF_Y_TH2_reg                                            0xb8019960
#define ADAP_BPF_Y_TH2_inst_addr                                      "0x0258"
#define ADAP_BPF_Y_TH2_inst                                           0x0258
#define ADAP_BPF_Y_TH2_xc_sel_gain_shift                              (6)
#define ADAP_BPF_Y_TH2_y_uniform_thr_shift                            (0)
#define ADAP_BPF_Y_TH2_xc_sel_gain_mask                               (0x000000C0)
#define ADAP_BPF_Y_TH2_y_uniform_thr_mask                             (0x0000000F)
#define ADAP_BPF_Y_TH2_xc_sel_gain(data)                              (0x000000C0&((data)<<6))
#define ADAP_BPF_Y_TH2_y_uniform_thr(data)                            (0x0000000F&(data))
#define ADAP_BPF_Y_TH2_get_xc_sel_gain(data)                          ((0x000000C0&(data))>>6)
#define ADAP_BPF_Y_TH2_get_y_uniform_thr(data)                        (0x0000000F&(data))


#define CDIFF_ADAP_BPF_TH1                                            0x18019964
#define CDIFF_ADAP_BPF_TH1_reg_addr                                   "0xb8019964"
#define CDIFF_ADAP_BPF_TH1_reg                                        0xb8019964
#define CDIFF_ADAP_BPF_TH1_inst_addr                                  "0x0259"
#define CDIFF_ADAP_BPF_TH1_inst                                       0x0259
#define CDIFF_ADAP_BPF_TH1_cdiff_bpf_mm_small_th_shift                (16)
#define CDIFF_ADAP_BPF_TH1_cdiff_bpf_mm_diff_th_shift                 (8)
#define CDIFF_ADAP_BPF_TH1_cdiff_bpf_hor_range_shift                  (5)
#define CDIFF_ADAP_BPF_TH1_cdiff_bpf_ver_range_shift                  (4)
#define CDIFF_ADAP_BPF_TH1_cdiff_bpf_sel_c_en_shift                   (1)
#define CDIFF_ADAP_BPF_TH1_cdiff_bpf_sel_y_en_shift                   (0)
#define CDIFF_ADAP_BPF_TH1_cdiff_bpf_mm_small_th_mask                 (0x003F0000)
#define CDIFF_ADAP_BPF_TH1_cdiff_bpf_mm_diff_th_mask                  (0x0000FF00)
#define CDIFF_ADAP_BPF_TH1_cdiff_bpf_hor_range_mask                   (0x00000020)
#define CDIFF_ADAP_BPF_TH1_cdiff_bpf_ver_range_mask                   (0x00000010)
#define CDIFF_ADAP_BPF_TH1_cdiff_bpf_sel_c_en_mask                    (0x00000002)
#define CDIFF_ADAP_BPF_TH1_cdiff_bpf_sel_y_en_mask                    (0x00000001)
#define CDIFF_ADAP_BPF_TH1_cdiff_bpf_mm_small_th(data)                (0x003F0000&((data)<<16))
#define CDIFF_ADAP_BPF_TH1_cdiff_bpf_mm_diff_th(data)                 (0x0000FF00&((data)<<8))
#define CDIFF_ADAP_BPF_TH1_cdiff_bpf_hor_range(data)                  (0x00000020&((data)<<5))
#define CDIFF_ADAP_BPF_TH1_cdiff_bpf_ver_range(data)                  (0x00000010&((data)<<4))
#define CDIFF_ADAP_BPF_TH1_cdiff_bpf_sel_c_en(data)                   (0x00000002&((data)<<1))
#define CDIFF_ADAP_BPF_TH1_cdiff_bpf_sel_y_en(data)                   (0x00000001&(data))
#define CDIFF_ADAP_BPF_TH1_get_cdiff_bpf_mm_small_th(data)            ((0x003F0000&(data))>>16)
#define CDIFF_ADAP_BPF_TH1_get_cdiff_bpf_mm_diff_th(data)             ((0x0000FF00&(data))>>8)
#define CDIFF_ADAP_BPF_TH1_get_cdiff_bpf_hor_range(data)              ((0x00000020&(data))>>5)
#define CDIFF_ADAP_BPF_TH1_get_cdiff_bpf_ver_range(data)              ((0x00000010&(data))>>4)
#define CDIFF_ADAP_BPF_TH1_get_cdiff_bpf_sel_c_en(data)               ((0x00000002&(data))>>1)
#define CDIFF_ADAP_BPF_TH1_get_cdiff_bpf_sel_y_en(data)               (0x00000001&(data))


#define CDIFF_ADAP_BPF_TH2                                            0x18019968
#define CDIFF_ADAP_BPF_TH2_reg_addr                                   "0xb8019968"
#define CDIFF_ADAP_BPF_TH2_reg                                        0xb8019968
#define CDIFF_ADAP_BPF_TH2_inst_addr                                  "0x025A"
#define CDIFF_ADAP_BPF_TH2_inst                                       0x025A
#define CDIFF_ADAP_BPF_TH2_cdiff_bpf_vspd_small_th_shift              (24)
#define CDIFF_ADAP_BPF_TH2_cdiff_bpf_low_sat_th_shift                 (16)
#define CDIFF_ADAP_BPF_TH2_cdiff_bpf_large_offset_shift               (12)
#define CDIFF_ADAP_BPF_TH2_cdiff_bpf_large_amp_wei_shift              (8)
#define CDIFF_ADAP_BPF_TH2_cdiff_bpf_small_offset_shift               (4)
#define CDIFF_ADAP_BPF_TH2_cdiff_bpf_small_amp_wei_shift              (0)
#define CDIFF_ADAP_BPF_TH2_cdiff_bpf_vspd_small_th_mask               (0x3F000000)
#define CDIFF_ADAP_BPF_TH2_cdiff_bpf_low_sat_th_mask                  (0x003F0000)
#define CDIFF_ADAP_BPF_TH2_cdiff_bpf_large_offset_mask                (0x0000F000)
#define CDIFF_ADAP_BPF_TH2_cdiff_bpf_large_amp_wei_mask               (0x00000700)
#define CDIFF_ADAP_BPF_TH2_cdiff_bpf_small_offset_mask                (0x000000F0)
#define CDIFF_ADAP_BPF_TH2_cdiff_bpf_small_amp_wei_mask               (0x00000007)
#define CDIFF_ADAP_BPF_TH2_cdiff_bpf_vspd_small_th(data)              (0x3F000000&((data)<<24))
#define CDIFF_ADAP_BPF_TH2_cdiff_bpf_low_sat_th(data)                 (0x003F0000&((data)<<16))
#define CDIFF_ADAP_BPF_TH2_cdiff_bpf_large_offset(data)               (0x0000F000&((data)<<12))
#define CDIFF_ADAP_BPF_TH2_cdiff_bpf_large_amp_wei(data)              (0x00000700&((data)<<8))
#define CDIFF_ADAP_BPF_TH2_cdiff_bpf_small_offset(data)               (0x000000F0&((data)<<4))
#define CDIFF_ADAP_BPF_TH2_cdiff_bpf_small_amp_wei(data)              (0x00000007&(data))
#define CDIFF_ADAP_BPF_TH2_get_cdiff_bpf_vspd_small_th(data)          ((0x3F000000&(data))>>24)
#define CDIFF_ADAP_BPF_TH2_get_cdiff_bpf_low_sat_th(data)             ((0x003F0000&(data))>>16)
#define CDIFF_ADAP_BPF_TH2_get_cdiff_bpf_large_offset(data)           ((0x0000F000&(data))>>12)
#define CDIFF_ADAP_BPF_TH2_get_cdiff_bpf_large_amp_wei(data)          ((0x00000700&(data))>>8)
#define CDIFF_ADAP_BPF_TH2_get_cdiff_bpf_small_offset(data)           ((0x000000F0&(data))>>4)
#define CDIFF_ADAP_BPF_TH2_get_cdiff_bpf_small_amp_wei(data)          (0x00000007&(data))


#define BPF_VEDGE_CTRL1                                               0x18019970
#define BPF_VEDGE_CTRL1_reg_addr                                      "0xb8019970"
#define BPF_VEDGE_CTRL1_reg                                           0xb8019970
#define BPF_VEDGE_CTRL1_inst_addr                                     "0x025C"
#define BPF_VEDGE_CTRL1_inst                                          0x025C
#define BPF_VEDGE_CTRL1_hvdiff_comp_offset_shift                      (16)
#define BPF_VEDGE_CTRL1_hvdiff_comp_multiple_shift                    (12)
#define BPF_VEDGE_CTRL1_diff_tolerance_shift                          (4)
#define BPF_VEDGE_CTRL1_vedge_en_shift                                (0)
#define BPF_VEDGE_CTRL1_hvdiff_comp_offset_mask                       (0x00FF0000)
#define BPF_VEDGE_CTRL1_hvdiff_comp_multiple_mask                     (0x0000F000)
#define BPF_VEDGE_CTRL1_diff_tolerance_mask                           (0x000001F0)
#define BPF_VEDGE_CTRL1_vedge_en_mask                                 (0x00000001)
#define BPF_VEDGE_CTRL1_hvdiff_comp_offset(data)                      (0x00FF0000&((data)<<16))
#define BPF_VEDGE_CTRL1_hvdiff_comp_multiple(data)                    (0x0000F000&((data)<<12))
#define BPF_VEDGE_CTRL1_diff_tolerance(data)                          (0x000001F0&((data)<<4))
#define BPF_VEDGE_CTRL1_vedge_en(data)                                (0x00000001&(data))
#define BPF_VEDGE_CTRL1_get_hvdiff_comp_offset(data)                  ((0x00FF0000&(data))>>16)
#define BPF_VEDGE_CTRL1_get_hvdiff_comp_multiple(data)                ((0x0000F000&(data))>>12)
#define BPF_VEDGE_CTRL1_get_diff_tolerance(data)                      ((0x000001F0&(data))>>4)
#define BPF_VEDGE_CTRL1_get_vedge_en(data)                            (0x00000001&(data))


#define BPF_VEDGE_CTRL2                                               0x18019974
#define BPF_VEDGE_CTRL2_reg_addr                                      "0xb8019974"
#define BPF_VEDGE_CTRL2_reg                                           0xb8019974
#define BPF_VEDGE_CTRL2_inst_addr                                     "0x025D"
#define BPF_VEDGE_CTRL2_inst                                          0x025D
#define BPF_VEDGE_CTRL2_c_follow_y_en_shift                           (16)
#define BPF_VEDGE_CTRL2_hdiff_lowbound_shift                          (8)
#define BPF_VEDGE_CTRL2_vdiff_upbound_shift                           (0)
#define BPF_VEDGE_CTRL2_c_follow_y_en_mask                            (0x00010000)
#define BPF_VEDGE_CTRL2_hdiff_lowbound_mask                           (0x00007F00)
#define BPF_VEDGE_CTRL2_vdiff_upbound_mask                            (0x0000001F)
#define BPF_VEDGE_CTRL2_c_follow_y_en(data)                           (0x00010000&((data)<<16))
#define BPF_VEDGE_CTRL2_hdiff_lowbound(data)                          (0x00007F00&((data)<<8))
#define BPF_VEDGE_CTRL2_vdiff_upbound(data)                           (0x0000001F&(data))
#define BPF_VEDGE_CTRL2_get_c_follow_y_en(data)                       ((0x00010000&(data))>>16)
#define BPF_VEDGE_CTRL2_get_hdiff_lowbound(data)                      ((0x00007F00&(data))>>8)
#define BPF_VEDGE_CTRL2_get_vdiff_upbound(data)                       (0x0000001F&(data))


#define DIAMC_CVBS_AMP_TH                                             0x1801999c
#define DIAMC_CVBS_AMP_TH_reg_addr                                    "0xb801999c"
#define DIAMC_CVBS_AMP_TH_reg                                         0xb801999c
#define DIAMC_CVBS_AMP_TH_inst_addr                                   "0x0267"
#define DIAMC_CVBS_AMP_TH_inst                                        0x0267
#define DIAMC_CVBS_AMP_TH_diamc_cvbsamp_still_th_shift                (0)
#define DIAMC_CVBS_AMP_TH_diamc_cvbsamp_still_th_mask                 (0x0000003F)
#define DIAMC_CVBS_AMP_TH_diamc_cvbsamp_still_th(data)                (0x0000003F&(data))
#define DIAMC_CVBS_AMP_TH_get_diamc_cvbsamp_still_th(data)            (0x0000003F&(data))


#define DIAMC_CTRL                                                    0x180199a0
#define DIAMC_CTRL_reg_addr                                           "0xb80199a0"
#define DIAMC_CTRL_reg                                                0xb80199a0
#define DIAMC_CTRL_inst_addr                                          "0x0268"
#define DIAMC_CTRL_inst                                               0x0268
#define DIAMC_CTRL_diamc_dc_still_th_offset_shift                     (24)
#define DIAMC_CTRL_diamc_dc_still_th_weight_shift                     (20)
#define DIAMC_CTRL_diamc_y_v_line_id_cnt_th_shift                     (16)
#define DIAMC_CTRL_diamc_fid_th_weight_shift                          (12)
#define DIAMC_CTRL_diamc_amp_low_bnd_shift                            (4)
#define DIAMC_CTRL_diamc_all_line_match_en_shift                      (2)
#define DIAMC_CTRL_diamc_perfect_fid_en_shift                         (1)
#define DIAMC_CTRL_diamc_en_shift                                     (0)
#define DIAMC_CTRL_diamc_dc_still_th_offset_mask                      (0x3F000000)
#define DIAMC_CTRL_diamc_dc_still_th_weight_mask                      (0x00F00000)
#define DIAMC_CTRL_diamc_y_v_line_id_cnt_th_mask                      (0x00030000)
#define DIAMC_CTRL_diamc_fid_th_weight_mask                           (0x00007000)
#define DIAMC_CTRL_diamc_amp_low_bnd_mask                             (0x000007F0)
#define DIAMC_CTRL_diamc_all_line_match_en_mask                       (0x00000004)
#define DIAMC_CTRL_diamc_perfect_fid_en_mask                          (0x00000002)
#define DIAMC_CTRL_diamc_en_mask                                      (0x00000001)
#define DIAMC_CTRL_diamc_dc_still_th_offset(data)                     (0x3F000000&((data)<<24))
#define DIAMC_CTRL_diamc_dc_still_th_weight(data)                     (0x00F00000&((data)<<20))
#define DIAMC_CTRL_diamc_y_v_line_id_cnt_th(data)                     (0x00030000&((data)<<16))
#define DIAMC_CTRL_diamc_fid_th_weight(data)                          (0x00007000&((data)<<12))
#define DIAMC_CTRL_diamc_amp_low_bnd(data)                            (0x000007F0&((data)<<4))
#define DIAMC_CTRL_diamc_all_line_match_en(data)                      (0x00000004&((data)<<2))
#define DIAMC_CTRL_diamc_perfect_fid_en(data)                         (0x00000002&((data)<<1))
#define DIAMC_CTRL_diamc_en(data)                                     (0x00000001&(data))
#define DIAMC_CTRL_get_diamc_dc_still_th_offset(data)                 ((0x3F000000&(data))>>24)
#define DIAMC_CTRL_get_diamc_dc_still_th_weight(data)                 ((0x00F00000&(data))>>20)
#define DIAMC_CTRL_get_diamc_y_v_line_id_cnt_th(data)                 ((0x00030000&(data))>>16)
#define DIAMC_CTRL_get_diamc_fid_th_weight(data)                      ((0x00007000&(data))>>12)
#define DIAMC_CTRL_get_diamc_amp_low_bnd(data)                        ((0x000007F0&(data))>>4)
#define DIAMC_CTRL_get_diamc_all_line_match_en(data)                  ((0x00000004&(data))>>2)
#define DIAMC_CTRL_get_diamc_perfect_fid_en(data)                     ((0x00000002&(data))>>1)
#define DIAMC_CTRL_get_diamc_en(data)                                 (0x00000001&(data))


#define VMC_CTRL                                                      0x180199a4
#define VMC_CTRL_reg_addr                                             "0xb80199a4"
#define VMC_CTRL_reg                                                  0xb80199a4
#define VMC_CTRL_inst_addr                                            "0x0269"
#define VMC_CTRL_inst                                                 0x0269
#define VMC_CTRL_ver_cvbsamp_still_th_shift                           (24)
#define VMC_CTRL_vmc_cfollowy_en_shift                                (20)
#define VMC_CTRL_ver_dc_still_th_shift                                (12)
#define VMC_CTRL_amp_low_bnd_shift                                    (4)
#define VMC_CTRL_slant_det_en_shift                                   (2)
#define VMC_CTRL_perfect_fid_en_shift                                 (1)
#define VMC_CTRL_vmc_en_shift                                         (0)
#define VMC_CTRL_ver_cvbsamp_still_th_mask                            (0x3F000000)
#define VMC_CTRL_vmc_cfollowy_en_mask                                 (0x00100000)
#define VMC_CTRL_ver_dc_still_th_mask                                 (0x0007F000)
#define VMC_CTRL_amp_low_bnd_mask                                     (0x000003F0)
#define VMC_CTRL_slant_det_en_mask                                    (0x00000004)
#define VMC_CTRL_perfect_fid_en_mask                                  (0x00000002)
#define VMC_CTRL_vmc_en_mask                                          (0x00000001)
#define VMC_CTRL_ver_cvbsamp_still_th(data)                           (0x3F000000&((data)<<24))
#define VMC_CTRL_vmc_cfollowy_en(data)                                (0x00100000&((data)<<20))
#define VMC_CTRL_ver_dc_still_th(data)                                (0x0007F000&((data)<<12))
#define VMC_CTRL_amp_low_bnd(data)                                    (0x000003F0&((data)<<4))
#define VMC_CTRL_slant_det_en(data)                                   (0x00000004&((data)<<2))
#define VMC_CTRL_perfect_fid_en(data)                                 (0x00000002&((data)<<1))
#define VMC_CTRL_vmc_en(data)                                         (0x00000001&(data))
#define VMC_CTRL_get_ver_cvbsamp_still_th(data)                       ((0x3F000000&(data))>>24)
#define VMC_CTRL_get_vmc_cfollowy_en(data)                            ((0x00100000&(data))>>20)
#define VMC_CTRL_get_ver_dc_still_th(data)                            ((0x0007F000&(data))>>12)
#define VMC_CTRL_get_amp_low_bnd(data)                                ((0x000003F0&(data))>>4)
#define VMC_CTRL_get_slant_det_en(data)                               ((0x00000004&(data))>>2)
#define VMC_CTRL_get_perfect_fid_en(data)                             ((0x00000002&(data))>>1)
#define VMC_CTRL_get_vmc_en(data)                                     (0x00000001&(data))


#define VMC_SPATIAL_CORR_CTRL                                         0x180199a8
#define VMC_SPATIAL_CORR_CTRL_reg_addr                                "0xb80199a8"
#define VMC_SPATIAL_CORR_CTRL_reg                                     0xb80199a8
#define VMC_SPATIAL_CORR_CTRL_inst_addr                               "0x026A"
#define VMC_SPATIAL_CORR_CTRL_inst                                    0x026A
#define VMC_SPATIAL_CORR_CTRL_offset_2_shift                          (12)
#define VMC_SPATIAL_CORR_CTRL_offset_1_shift                          (8)
#define VMC_SPATIAL_CORR_CTRL_cnt_th_2_shift                          (4)
#define VMC_SPATIAL_CORR_CTRL_cnt_th_1_shift                          (0)
#define VMC_SPATIAL_CORR_CTRL_offset_2_mask                           (0x00007000)
#define VMC_SPATIAL_CORR_CTRL_offset_1_mask                           (0x00000300)
#define VMC_SPATIAL_CORR_CTRL_cnt_th_2_mask                           (0x000000F0)
#define VMC_SPATIAL_CORR_CTRL_cnt_th_1_mask                           (0x0000000F)
#define VMC_SPATIAL_CORR_CTRL_offset_2(data)                          (0x00007000&((data)<<12))
#define VMC_SPATIAL_CORR_CTRL_offset_1(data)                          (0x00000300&((data)<<8))
#define VMC_SPATIAL_CORR_CTRL_cnt_th_2(data)                          (0x000000F0&((data)<<4))
#define VMC_SPATIAL_CORR_CTRL_cnt_th_1(data)                          (0x0000000F&(data))
#define VMC_SPATIAL_CORR_CTRL_get_offset_2(data)                      ((0x00007000&(data))>>12)
#define VMC_SPATIAL_CORR_CTRL_get_offset_1(data)                      ((0x00000300&(data))>>8)
#define VMC_SPATIAL_CORR_CTRL_get_cnt_th_2(data)                      ((0x000000F0&(data))>>4)
#define VMC_SPATIAL_CORR_CTRL_get_cnt_th_1(data)                      (0x0000000F&(data))


#define YC2D_POSTLP_CTRL                                              0x180199d0
#define YC2D_POSTLP_CTRL_reg_addr                                     "0xb80199d0"
#define YC2D_POSTLP_CTRL_reg                                          0xb80199d0
#define YC2D_POSTLP_CTRL_inst_addr                                    "0x0274"
#define YC2D_POSTLP_CTRL_inst                                         0x0274
#define YC2D_POSTLP_CTRL_postp_adapmode_shift                         (5)
#define YC2D_POSTLP_CTRL_newadap2d_en_shift                           (4)
#define YC2D_POSTLP_CTRL_postp_passnoedg_shift                        (3)
#define YC2D_POSTLP_CTRL_yc2d_postp_filter_sel_shift                  (2)
#define YC2D_POSTLP_CTRL_postp_adap_en_shift                          (1)
#define YC2D_POSTLP_CTRL_yc2d_postp_en_shift                          (0)
#define YC2D_POSTLP_CTRL_postp_adapmode_mask                          (0x00000060)
#define YC2D_POSTLP_CTRL_newadap2d_en_mask                            (0x00000010)
#define YC2D_POSTLP_CTRL_postp_passnoedg_mask                         (0x00000008)
#define YC2D_POSTLP_CTRL_yc2d_postp_filter_sel_mask                   (0x00000004)
#define YC2D_POSTLP_CTRL_postp_adap_en_mask                           (0x00000002)
#define YC2D_POSTLP_CTRL_yc2d_postp_en_mask                           (0x00000001)
#define YC2D_POSTLP_CTRL_postp_adapmode(data)                         (0x00000060&((data)<<5))
#define YC2D_POSTLP_CTRL_newadap2d_en(data)                           (0x00000010&((data)<<4))
#define YC2D_POSTLP_CTRL_postp_passnoedg(data)                        (0x00000008&((data)<<3))
#define YC2D_POSTLP_CTRL_yc2d_postp_filter_sel(data)                  (0x00000004&((data)<<2))
#define YC2D_POSTLP_CTRL_postp_adap_en(data)                          (0x00000002&((data)<<1))
#define YC2D_POSTLP_CTRL_yc2d_postp_en(data)                          (0x00000001&(data))
#define YC2D_POSTLP_CTRL_get_postp_adapmode(data)                     ((0x00000060&(data))>>5)
#define YC2D_POSTLP_CTRL_get_newadap2d_en(data)                       ((0x00000010&(data))>>4)
#define YC2D_POSTLP_CTRL_get_postp_passnoedg(data)                    ((0x00000008&(data))>>3)
#define YC2D_POSTLP_CTRL_get_yc2d_postp_filter_sel(data)              ((0x00000004&(data))>>2)
#define YC2D_POSTLP_CTRL_get_postp_adap_en(data)                      ((0x00000002&(data))>>1)
#define YC2D_POSTLP_CTRL_get_yc2d_postp_en(data)                      (0x00000001&(data))


#define YC_2D_POSTP_TH2                                               0x180199d4
#define YC_2D_POSTP_TH2_reg_addr                                      "0xb80199d4"
#define YC_2D_POSTP_TH2_reg                                           0xb80199d4
#define YC_2D_POSTP_TH2_inst_addr                                     "0x0275"
#define YC_2D_POSTP_TH2_inst                                          0x0275
#define YC_2D_POSTP_TH2_edgdet_hlo_shift                              (8)
#define YC_2D_POSTP_TH2_edgdet_vlo_shift                              (0)
#define YC_2D_POSTP_TH2_edgdet_hlo_mask                               (0x0000FF00)
#define YC_2D_POSTP_TH2_edgdet_vlo_mask                               (0x000000FF)
#define YC_2D_POSTP_TH2_edgdet_hlo(data)                              (0x0000FF00&((data)<<8))
#define YC_2D_POSTP_TH2_edgdet_vlo(data)                              (0x000000FF&(data))
#define YC_2D_POSTP_TH2_get_edgdet_hlo(data)                          ((0x0000FF00&(data))>>8)
#define YC_2D_POSTP_TH2_get_edgdet_vlo(data)                          (0x000000FF&(data))


#define YC_2D_POSTP_TH3                                               0x180199d8
#define YC_2D_POSTP_TH3_reg_addr                                      "0xb80199d8"
#define YC_2D_POSTP_TH3_reg                                           0xb80199d8
#define YC_2D_POSTP_TH3_inst_addr                                     "0x0276"
#define YC_2D_POSTP_TH3_inst                                          0x0276
#define YC_2D_POSTP_TH3_blend_upbnd_shift                             (0)
#define YC_2D_POSTP_TH3_blend_upbnd_mask                              (0x000000FF)
#define YC_2D_POSTP_TH3_blend_upbnd(data)                             (0x000000FF&(data))
#define YC_2D_POSTP_TH3_get_blend_upbnd(data)                         (0x000000FF&(data))


#define YC_2D_POSTP_TH4                                               0x180199dc
#define YC_2D_POSTP_TH4_reg_addr                                      "0xb80199dc"
#define YC_2D_POSTP_TH4_reg                                           0xb80199dc
#define YC_2D_POSTP_TH4_inst_addr                                     "0x0277"
#define YC_2D_POSTP_TH4_inst                                          0x0277
#define YC_2D_POSTP_TH4_blend_seg3_shift                              (16)
#define YC_2D_POSTP_TH4_blend_seg2_shift                              (8)
#define YC_2D_POSTP_TH4_blend_seg1_shift                              (0)
#define YC_2D_POSTP_TH4_blend_seg3_mask                               (0x00FF0000)
#define YC_2D_POSTP_TH4_blend_seg2_mask                               (0x0000FF00)
#define YC_2D_POSTP_TH4_blend_seg1_mask                               (0x000000FF)
#define YC_2D_POSTP_TH4_blend_seg3(data)                              (0x00FF0000&((data)<<16))
#define YC_2D_POSTP_TH4_blend_seg2(data)                              (0x0000FF00&((data)<<8))
#define YC_2D_POSTP_TH4_blend_seg1(data)                              (0x000000FF&(data))
#define YC_2D_POSTP_TH4_get_blend_seg3(data)                          ((0x00FF0000&(data))>>16)
#define YC_2D_POSTP_TH4_get_blend_seg2(data)                          ((0x0000FF00&(data))>>8)
#define YC_2D_POSTP_TH4_get_blend_seg1(data)                          (0x000000FF&(data))


#define YC_2D_POSTP_TH5                                               0x180199e0
#define YC_2D_POSTP_TH5_reg_addr                                      "0xb80199e0"
#define YC_2D_POSTP_TH5_reg                                           0xb80199e0
#define YC_2D_POSTP_TH5_inst_addr                                     "0x0278"
#define YC_2D_POSTP_TH5_inst                                          0x0278
#define YC_2D_POSTP_TH5_cblend_upbnd_shift                            (24)
#define YC_2D_POSTP_TH5_cblend_seg3_shift                             (16)
#define YC_2D_POSTP_TH5_cblend_seg2_shift                             (8)
#define YC_2D_POSTP_TH5_cblend_seg1_shift                             (0)
#define YC_2D_POSTP_TH5_cblend_upbnd_mask                             (0xFF000000)
#define YC_2D_POSTP_TH5_cblend_seg3_mask                              (0x00FF0000)
#define YC_2D_POSTP_TH5_cblend_seg2_mask                              (0x0000FF00)
#define YC_2D_POSTP_TH5_cblend_seg1_mask                              (0x000000FF)
#define YC_2D_POSTP_TH5_cblend_upbnd(data)                            (0xFF000000&((data)<<24))
#define YC_2D_POSTP_TH5_cblend_seg3(data)                             (0x00FF0000&((data)<<16))
#define YC_2D_POSTP_TH5_cblend_seg2(data)                             (0x0000FF00&((data)<<8))
#define YC_2D_POSTP_TH5_cblend_seg1(data)                             (0x000000FF&(data))
#define YC_2D_POSTP_TH5_get_cblend_upbnd(data)                        ((0xFF000000&(data))>>24)
#define YC_2D_POSTP_TH5_get_cblend_seg3(data)                         ((0x00FF0000&(data))>>16)
#define YC_2D_POSTP_TH5_get_cblend_seg2(data)                         ((0x0000FF00&(data))>>8)
#define YC_2D_POSTP_TH5_get_cblend_seg1(data)                         (0x000000FF&(data))


#define DUMMY_2                                                       0x18019afc
#define DUMMY_2_reg_addr                                              "0xb8019afc"
#define DUMMY_2_reg                                                   0xb8019afc
#define DUMMY_2_inst_addr                                             "0x02BF"
#define DUMMY_2_inst                                                  0x02BF
#define DUMMY_2_dummy_2_shift                                         (0)
#define DUMMY_2_dummy_2_mask                                          (0xFFFFFFFF)
#define DUMMY_2_dummy_2(data)                                         (0xFFFFFFFF&(data))
#define DUMMY_2_get_dummy_2(data)                                     (0xFFFFFFFF&(data))


#define YC_3D_MOTION_INC_STATUS2                                      0x18019b00
#define YC_3D_MOTION_INC_STATUS2_reg_addr                             "0xb8019b00"
#define YC_3D_MOTION_INC_STATUS2_reg                                  0xb8019b00
#define YC_3D_MOTION_INC_STATUS2_inst_addr                            "0x02C0"
#define YC_3D_MOTION_INC_STATUS2_inst                                 0x02C0
#define YC_3D_MOTION_INC_STATUS2_yc3d_motion_inc_status_15_8_shift    (0)
#define YC_3D_MOTION_INC_STATUS2_yc3d_motion_inc_status_15_8_mask     (0x000000FF)
#define YC_3D_MOTION_INC_STATUS2_yc3d_motion_inc_status_15_8(data)    (0x000000FF&(data))
#define YC_3D_MOTION_INC_STATUS2_get_yc3d_motion_inc_status_15_8(data)  (0x000000FF&(data))


#define YC_3D_MOTION_INC_STATUS1                                      0x18019b04
#define YC_3D_MOTION_INC_STATUS1_reg_addr                             "0xb8019b04"
#define YC_3D_MOTION_INC_STATUS1_reg                                  0xb8019b04
#define YC_3D_MOTION_INC_STATUS1_inst_addr                            "0x02C1"
#define YC_3D_MOTION_INC_STATUS1_inst                                 0x02C1
#define YC_3D_MOTION_INC_STATUS1_yc3d_motion_inc_status_7_0_shift     (0)
#define YC_3D_MOTION_INC_STATUS1_yc3d_motion_inc_status_7_0_mask      (0x000000FF)
#define YC_3D_MOTION_INC_STATUS1_yc3d_motion_inc_status_7_0(data)     (0x000000FF&(data))
#define YC_3D_MOTION_INC_STATUS1_get_yc3d_motion_inc_status_7_0(data) (0x000000FF&(data))


#define YC_3DSEP_MULTI_CTRL1                                          0x18019b08
#define YC_3DSEP_MULTI_CTRL1_reg_addr                                 "0xb8019b08"
#define YC_3DSEP_MULTI_CTRL1_reg                                      0xb8019b08
#define YC_3DSEP_MULTI_CTRL1_inst_addr                                "0x02C2"
#define YC_3DSEP_MULTI_CTRL1_inst                                     0x02C2
#define YC_3DSEP_MULTI_CTRL1_yc3d_mov_multi_en_shift                  (7)
#define YC_3DSEP_MULTI_CTRL1_yc3d_multib_det_shift                    (6)
#define YC_3DSEP_MULTI_CTRL1_yc3d_multi_th1_shift                     (0)
#define YC_3DSEP_MULTI_CTRL1_yc3d_mov_multi_en_mask                   (0x00000080)
#define YC_3DSEP_MULTI_CTRL1_yc3d_multib_det_mask                     (0x00000040)
#define YC_3DSEP_MULTI_CTRL1_yc3d_multi_th1_mask                      (0x0000003F)
#define YC_3DSEP_MULTI_CTRL1_yc3d_mov_multi_en(data)                  (0x00000080&((data)<<7))
#define YC_3DSEP_MULTI_CTRL1_yc3d_multib_det(data)                    (0x00000040&((data)<<6))
#define YC_3DSEP_MULTI_CTRL1_yc3d_multi_th1(data)                     (0x0000003F&(data))
#define YC_3DSEP_MULTI_CTRL1_get_yc3d_mov_multi_en(data)              ((0x00000080&(data))>>7)
#define YC_3DSEP_MULTI_CTRL1_get_yc3d_multib_det(data)                ((0x00000040&(data))>>6)
#define YC_3DSEP_MULTI_CTRL1_get_yc3d_multi_th1(data)                 (0x0000003F&(data))


#define YC_3DSEP_MULTI_CTRL2                                          0x18019b0c
#define YC_3DSEP_MULTI_CTRL2_reg_addr                                 "0xb8019b0c"
#define YC_3DSEP_MULTI_CTRL2_reg                                      0xb8019b0c
#define YC_3DSEP_MULTI_CTRL2_inst_addr                                "0x02C3"
#define YC_3DSEP_MULTI_CTRL2_inst                                     0x02C3
#define YC_3DSEP_MULTI_CTRL2_yc3d_multi_th2_shift                     (0)
#define YC_3DSEP_MULTI_CTRL2_yc3d_multi_th2_mask                      (0x0000003F)
#define YC_3DSEP_MULTI_CTRL2_yc3d_multi_th2(data)                     (0x0000003F&(data))
#define YC_3DSEP_MULTI_CTRL2_get_yc3d_multi_th2(data)                 (0x0000003F&(data))


#define YC_3DSEP_MULTI_CTRL3                                          0x18019b10
#define YC_3DSEP_MULTI_CTRL3_reg_addr                                 "0xb8019b10"
#define YC_3DSEP_MULTI_CTRL3_reg                                      0xb8019b10
#define YC_3DSEP_MULTI_CTRL3_inst_addr                                "0x02C4"
#define YC_3DSEP_MULTI_CTRL3_inst                                     0x02C4
#define YC_3DSEP_MULTI_CTRL3_yc3d_multi_th3_shift                     (0)
#define YC_3DSEP_MULTI_CTRL3_yc3d_multi_th3_mask                      (0x0000003F)
#define YC_3DSEP_MULTI_CTRL3_yc3d_multi_th3(data)                     (0x0000003F&(data))
#define YC_3DSEP_MULTI_CTRL3_get_yc3d_multi_th3(data)                 (0x0000003F&(data))


#define YC_3DSEP_TREND_MISC_CTRL                                      0x18019b14
#define YC_3DSEP_TREND_MISC_CTRL_reg_addr                             "0xb8019b14"
#define YC_3DSEP_TREND_MISC_CTRL_reg                                  0xb8019b14
#define YC_3DSEP_TREND_MISC_CTRL_inst_addr                            "0x02C5"
#define YC_3DSEP_TREND_MISC_CTRL_inst                                 0x02C5
#define YC_3DSEP_TREND_MISC_CTRL_yc3d_trend_mode_sel_shift            (7)
#define YC_3DSEP_TREND_MISC_CTRL_yc3d_trend_adap_en_shift             (6)
#define YC_3DSEP_TREND_MISC_CTRL_yc3d_trend_2d_en_shift               (5)
#define YC_3DSEP_TREND_MISC_CTRL_yc3d_trend_2d_ratio_shift            (0)
#define YC_3DSEP_TREND_MISC_CTRL_yc3d_trend_mode_sel_mask             (0x00000080)
#define YC_3DSEP_TREND_MISC_CTRL_yc3d_trend_adap_en_mask              (0x00000040)
#define YC_3DSEP_TREND_MISC_CTRL_yc3d_trend_2d_en_mask                (0x00000020)
#define YC_3DSEP_TREND_MISC_CTRL_yc3d_trend_2d_ratio_mask             (0x00000003)
#define YC_3DSEP_TREND_MISC_CTRL_yc3d_trend_mode_sel(data)            (0x00000080&((data)<<7))
#define YC_3DSEP_TREND_MISC_CTRL_yc3d_trend_adap_en(data)             (0x00000040&((data)<<6))
#define YC_3DSEP_TREND_MISC_CTRL_yc3d_trend_2d_en(data)               (0x00000020&((data)<<5))
#define YC_3DSEP_TREND_MISC_CTRL_yc3d_trend_2d_ratio(data)            (0x00000003&(data))
#define YC_3DSEP_TREND_MISC_CTRL_get_yc3d_trend_mode_sel(data)        ((0x00000080&(data))>>7)
#define YC_3DSEP_TREND_MISC_CTRL_get_yc3d_trend_adap_en(data)         ((0x00000040&(data))>>6)
#define YC_3DSEP_TREND_MISC_CTRL_get_yc3d_trend_2d_en(data)           ((0x00000020&(data))>>5)
#define YC_3DSEP_TREND_MISC_CTRL_get_yc3d_trend_2d_ratio(data)        (0x00000003&(data))


#define YC_3DSEP_TREND_MULTI_1                                        0x18019b18
#define YC_3DSEP_TREND_MULTI_1_reg_addr                               "0xb8019b18"
#define YC_3DSEP_TREND_MULTI_1_reg                                    0xb8019b18
#define YC_3DSEP_TREND_MULTI_1_inst_addr                              "0x02C6"
#define YC_3DSEP_TREND_MULTI_1_inst                                   0x02C6
#define YC_3DSEP_TREND_MULTI_1_yc3d_trend_a_multiple_shift            (4)
#define YC_3DSEP_TREND_MULTI_1_yc3d_trend_b_multiple_shift            (0)
#define YC_3DSEP_TREND_MULTI_1_yc3d_trend_a_multiple_mask             (0x000000F0)
#define YC_3DSEP_TREND_MULTI_1_yc3d_trend_b_multiple_mask             (0x0000000F)
#define YC_3DSEP_TREND_MULTI_1_yc3d_trend_a_multiple(data)            (0x000000F0&((data)<<4))
#define YC_3DSEP_TREND_MULTI_1_yc3d_trend_b_multiple(data)            (0x0000000F&(data))
#define YC_3DSEP_TREND_MULTI_1_get_yc3d_trend_a_multiple(data)        ((0x000000F0&(data))>>4)
#define YC_3DSEP_TREND_MULTI_1_get_yc3d_trend_b_multiple(data)        (0x0000000F&(data))


#define YC_3DSEP_TREND_MULTI_2                                        0x18019b1c
#define YC_3DSEP_TREND_MULTI_2_reg_addr                               "0xb8019b1c"
#define YC_3DSEP_TREND_MULTI_2_reg                                    0xb8019b1c
#define YC_3DSEP_TREND_MULTI_2_inst_addr                              "0x02C7"
#define YC_3DSEP_TREND_MULTI_2_inst                                   0x02C7
#define YC_3DSEP_TREND_MULTI_2_yc3d_trend_c_multiple_shift            (4)
#define YC_3DSEP_TREND_MULTI_2_yc3d_trend_d_multiple_shift            (0)
#define YC_3DSEP_TREND_MULTI_2_yc3d_trend_c_multiple_mask             (0x000000F0)
#define YC_3DSEP_TREND_MULTI_2_yc3d_trend_d_multiple_mask             (0x0000000F)
#define YC_3DSEP_TREND_MULTI_2_yc3d_trend_c_multiple(data)            (0x000000F0&((data)<<4))
#define YC_3DSEP_TREND_MULTI_2_yc3d_trend_d_multiple(data)            (0x0000000F&(data))
#define YC_3DSEP_TREND_MULTI_2_get_yc3d_trend_c_multiple(data)        ((0x000000F0&(data))>>4)
#define YC_3DSEP_TREND_MULTI_2_get_yc3d_trend_d_multiple(data)        (0x0000000F&(data))


#define YC_3DSEP_Y2D_DIFF_TH                                          0x18019b20
#define YC_3DSEP_Y2D_DIFF_TH_reg_addr                                 "0xb8019b20"
#define YC_3DSEP_Y2D_DIFF_TH_reg                                      0xb8019b20
#define YC_3DSEP_Y2D_DIFF_TH_inst_addr                                "0x02C8"
#define YC_3DSEP_Y2D_DIFF_TH_inst                                     0x02C8
#define YC_3DSEP_Y2D_DIFF_TH_yc3d_y2d_diff_th_shift                   (0)
#define YC_3DSEP_Y2D_DIFF_TH_yc3d_y2d_diff_th_mask                    (0x000000FF)
#define YC_3DSEP_Y2D_DIFF_TH_yc3d_y2d_diff_th(data)                   (0x000000FF&(data))
#define YC_3DSEP_Y2D_DIFF_TH_get_yc3d_y2d_diff_th(data)               (0x000000FF&(data))


#define YC_3DSEP_C2D_DIFF_TH                                          0x18019b24
#define YC_3DSEP_C2D_DIFF_TH_reg_addr                                 "0xb8019b24"
#define YC_3DSEP_C2D_DIFF_TH_reg                                      0xb8019b24
#define YC_3DSEP_C2D_DIFF_TH_inst_addr                                "0x02C9"
#define YC_3DSEP_C2D_DIFF_TH_inst                                     0x02C9
#define YC_3DSEP_C2D_DIFF_TH_yc3d_c2d_diff_th_shift                   (0)
#define YC_3DSEP_C2D_DIFF_TH_yc3d_c2d_diff_th_mask                    (0x000000FF)
#define YC_3DSEP_C2D_DIFF_TH_yc3d_c2d_diff_th(data)                   (0x000000FF&(data))
#define YC_3DSEP_C2D_DIFF_TH_get_yc3d_c2d_diff_th(data)               (0x000000FF&(data))


#define YC_SEP_MODE_CTRL                                              0x18019b28
#define YC_SEP_MODE_CTRL_reg_addr                                     "0xb8019b28"
#define YC_SEP_MODE_CTRL_reg                                          0xb8019b28
#define YC_SEP_MODE_CTRL_inst_addr                                    "0x02CA"
#define YC_SEP_MODE_CTRL_inst                                         0x02CA
#define YC_SEP_MODE_CTRL_yc3d_sep_mode1_shift                         (7)
#define YC_SEP_MODE_CTRL_yc3d_sep_mode2_shift                         (6)
#define YC_SEP_MODE_CTRL_yc_sep_current_sel_shift                     (5)
#define YC_SEP_MODE_CTRL_pal_mod_inv_shift                            (4)
#define YC_SEP_MODE_CTRL_yc_sep_mode_shift                            (0)
#define YC_SEP_MODE_CTRL_yc3d_sep_mode1_mask                          (0x00000080)
#define YC_SEP_MODE_CTRL_yc3d_sep_mode2_mask                          (0x00000040)
#define YC_SEP_MODE_CTRL_yc_sep_current_sel_mask                      (0x00000020)
#define YC_SEP_MODE_CTRL_pal_mod_inv_mask                             (0x00000010)
#define YC_SEP_MODE_CTRL_yc_sep_mode_mask                             (0x00000003)
#define YC_SEP_MODE_CTRL_yc3d_sep_mode1(data)                         (0x00000080&((data)<<7))
#define YC_SEP_MODE_CTRL_yc3d_sep_mode2(data)                         (0x00000040&((data)<<6))
#define YC_SEP_MODE_CTRL_yc_sep_current_sel(data)                     (0x00000020&((data)<<5))
#define YC_SEP_MODE_CTRL_pal_mod_inv(data)                            (0x00000010&((data)<<4))
#define YC_SEP_MODE_CTRL_yc_sep_mode(data)                            (0x00000003&(data))
#define YC_SEP_MODE_CTRL_get_yc3d_sep_mode1(data)                     ((0x00000080&(data))>>7)
#define YC_SEP_MODE_CTRL_get_yc3d_sep_mode2(data)                     ((0x00000040&(data))>>6)
#define YC_SEP_MODE_CTRL_get_yc_sep_current_sel(data)                 ((0x00000020&(data))>>5)
#define YC_SEP_MODE_CTRL_get_pal_mod_inv(data)                        ((0x00000010&(data))>>4)
#define YC_SEP_MODE_CTRL_get_yc_sep_mode(data)                        (0x00000003&(data))


#define YC_3DSEP_DEBUG_CTRL                                           0x18019b2c
#define YC_3DSEP_DEBUG_CTRL_reg_addr                                  "0xb8019b2c"
#define YC_3DSEP_DEBUG_CTRL_reg                                       0xb8019b2c
#define YC_3DSEP_DEBUG_CTRL_inst_addr                                 "0x02CB"
#define YC_3DSEP_DEBUG_CTRL_inst                                      0x02CB
#define YC_3DSEP_DEBUG_CTRL_yc3d_debug_en_shift                       (7)
#define YC_3DSEP_DEBUG_CTRL_yc3d_debug_mode_shift                     (0)
#define YC_3DSEP_DEBUG_CTRL_yc3d_debug_en_mask                        (0x00000080)
#define YC_3DSEP_DEBUG_CTRL_yc3d_debug_mode_mask                      (0x0000000F)
#define YC_3DSEP_DEBUG_CTRL_yc3d_debug_en(data)                       (0x00000080&((data)<<7))
#define YC_3DSEP_DEBUG_CTRL_yc3d_debug_mode(data)                     (0x0000000F&(data))
#define YC_3DSEP_DEBUG_CTRL_get_yc3d_debug_en(data)                   ((0x00000080&(data))>>7)
#define YC_3DSEP_DEBUG_CTRL_get_yc3d_debug_mode(data)                 (0x0000000F&(data))


#define YC_3DSEP_CHROMA_BPF_SEL                                       0x18019b30
#define YC_3DSEP_CHROMA_BPF_SEL_reg_addr                              "0xb8019b30"
#define YC_3DSEP_CHROMA_BPF_SEL_reg                                   0xb8019b30
#define YC_3DSEP_CHROMA_BPF_SEL_inst_addr                             "0x02CC"
#define YC_3DSEP_CHROMA_BPF_SEL_inst                                  0x02CC
#define YC_3DSEP_CHROMA_BPF_SEL_yc3d_cchroma_bpf_sel_shift            (7)
#define YC_3DSEP_CHROMA_BPF_SEL_yc3d_ychroma_bpf_sel_shift            (6)
#define YC_3DSEP_CHROMA_BPF_SEL_yc3d_trend_th1_shift                  (0)
#define YC_3DSEP_CHROMA_BPF_SEL_yc3d_cchroma_bpf_sel_mask             (0x00000080)
#define YC_3DSEP_CHROMA_BPF_SEL_yc3d_ychroma_bpf_sel_mask             (0x00000040)
#define YC_3DSEP_CHROMA_BPF_SEL_yc3d_trend_th1_mask                   (0x0000003F)
#define YC_3DSEP_CHROMA_BPF_SEL_yc3d_cchroma_bpf_sel(data)            (0x00000080&((data)<<7))
#define YC_3DSEP_CHROMA_BPF_SEL_yc3d_ychroma_bpf_sel(data)            (0x00000040&((data)<<6))
#define YC_3DSEP_CHROMA_BPF_SEL_yc3d_trend_th1(data)                  (0x0000003F&(data))
#define YC_3DSEP_CHROMA_BPF_SEL_get_yc3d_cchroma_bpf_sel(data)        ((0x00000080&(data))>>7)
#define YC_3DSEP_CHROMA_BPF_SEL_get_yc3d_ychroma_bpf_sel(data)        ((0x00000040&(data))>>6)
#define YC_3DSEP_CHROMA_BPF_SEL_get_yc3d_trend_th1(data)              (0x0000003F&(data))


#define YC_3DSEP_TREND_ESTIMATION_CTRL                                0x18019b34
#define YC_3DSEP_TREND_ESTIMATION_CTRL_reg_addr                       "0xb8019b34"
#define YC_3DSEP_TREND_ESTIMATION_CTRL_reg                            0xb8019b34
#define YC_3DSEP_TREND_ESTIMATION_CTRL_inst_addr                      "0x02CD"
#define YC_3DSEP_TREND_ESTIMATION_CTRL_inst                           0x02CD
#define YC_3DSEP_TREND_ESTIMATION_CTRL_yc3d_trend_tight_en_shift      (7)
#define YC_3DSEP_TREND_ESTIMATION_CTRL_yc3d_trend_th_shift            (0)
#define YC_3DSEP_TREND_ESTIMATION_CTRL_yc3d_trend_tight_en_mask       (0x00000080)
#define YC_3DSEP_TREND_ESTIMATION_CTRL_yc3d_trend_th_mask             (0x0000007F)
#define YC_3DSEP_TREND_ESTIMATION_CTRL_yc3d_trend_tight_en(data)      (0x00000080&((data)<<7))
#define YC_3DSEP_TREND_ESTIMATION_CTRL_yc3d_trend_th(data)            (0x0000007F&(data))
#define YC_3DSEP_TREND_ESTIMATION_CTRL_get_yc3d_trend_tight_en(data)  ((0x00000080&(data))>>7)
#define YC_3DSEP_TREND_ESTIMATION_CTRL_get_yc3d_trend_th(data)        (0x0000007F&(data))


#define YC_3DSEP_FRAME_MOTION_THRESHOLD                               0x18019b38
#define YC_3DSEP_FRAME_MOTION_THRESHOLD_reg_addr                      "0xb8019b38"
#define YC_3DSEP_FRAME_MOTION_THRESHOLD_reg                           0xb8019b38
#define YC_3DSEP_FRAME_MOTION_THRESHOLD_inst_addr                     "0x02CE"
#define YC_3DSEP_FRAME_MOTION_THRESHOLD_inst                          0x02CE
#define YC_3DSEP_FRAME_MOTION_THRESHOLD_yc3d_frame_motion_th_shift    (0)
#define YC_3DSEP_FRAME_MOTION_THRESHOLD_yc3d_frame_motion_th_mask     (0x000000FF)
#define YC_3DSEP_FRAME_MOTION_THRESHOLD_yc3d_frame_motion_th(data)    (0x000000FF&(data))
#define YC_3DSEP_FRAME_MOTION_THRESHOLD_get_yc3d_frame_motion_th(data)  (0x000000FF&(data))


#define YC_3DSEP_Y_LOW_DIFF_THRESHOLD1                                0x18019b3c
#define YC_3DSEP_Y_LOW_DIFF_THRESHOLD1_reg_addr                       "0xb8019b3c"
#define YC_3DSEP_Y_LOW_DIFF_THRESHOLD1_reg                            0xb8019b3c
#define YC_3DSEP_Y_LOW_DIFF_THRESHOLD1_inst_addr                      "0x02CF"
#define YC_3DSEP_Y_LOW_DIFF_THRESHOLD1_inst                           0x02CF
#define YC_3DSEP_Y_LOW_DIFF_THRESHOLD1_yc3d_ylo_diff_th1_shift        (0)
#define YC_3DSEP_Y_LOW_DIFF_THRESHOLD1_yc3d_ylo_diff_th1_mask         (0x000000FF)
#define YC_3DSEP_Y_LOW_DIFF_THRESHOLD1_yc3d_ylo_diff_th1(data)        (0x000000FF&(data))
#define YC_3DSEP_Y_LOW_DIFF_THRESHOLD1_get_yc3d_ylo_diff_th1(data)    (0x000000FF&(data))


#define YC_3DSEP_Y_LOW_DIFF_THRESHOLD2                                0x18019b40
#define YC_3DSEP_Y_LOW_DIFF_THRESHOLD2_reg_addr                       "0xb8019b40"
#define YC_3DSEP_Y_LOW_DIFF_THRESHOLD2_reg                            0xb8019b40
#define YC_3DSEP_Y_LOW_DIFF_THRESHOLD2_inst_addr                      "0x02D0"
#define YC_3DSEP_Y_LOW_DIFF_THRESHOLD2_inst                           0x02D0
#define YC_3DSEP_Y_LOW_DIFF_THRESHOLD2_yc3d_ylo_diff_th2_shift        (0)
#define YC_3DSEP_Y_LOW_DIFF_THRESHOLD2_yc3d_ylo_diff_th2_mask         (0x000000FF)
#define YC_3DSEP_Y_LOW_DIFF_THRESHOLD2_yc3d_ylo_diff_th2(data)        (0x000000FF&(data))
#define YC_3DSEP_Y_LOW_DIFF_THRESHOLD2_get_yc3d_ylo_diff_th2(data)    (0x000000FF&(data))


#define YC_3DSEP_C_BPF_DIFF_TH1                                       0x18019b44
#define YC_3DSEP_C_BPF_DIFF_TH1_reg_addr                              "0xb8019b44"
#define YC_3DSEP_C_BPF_DIFF_TH1_reg                                   0xb8019b44
#define YC_3DSEP_C_BPF_DIFF_TH1_inst_addr                             "0x02D1"
#define YC_3DSEP_C_BPF_DIFF_TH1_inst                                  0x02D1
#define YC_3DSEP_C_BPF_DIFF_TH1_yc3d_c_bpf_diff_th_shift              (0)
#define YC_3DSEP_C_BPF_DIFF_TH1_yc3d_c_bpf_diff_th_mask               (0x000000FF)
#define YC_3DSEP_C_BPF_DIFF_TH1_yc3d_c_bpf_diff_th(data)              (0x000000FF&(data))
#define YC_3DSEP_C_BPF_DIFF_TH1_get_yc3d_c_bpf_diff_th(data)          (0x000000FF&(data))


#define YC_3DSEP_TRENDLIKE_TH1                                        0x18019b48
#define YC_3DSEP_TRENDLIKE_TH1_reg_addr                               "0xb8019b48"
#define YC_3DSEP_TRENDLIKE_TH1_reg                                    0xb8019b48
#define YC_3DSEP_TRENDLIKE_TH1_inst_addr                              "0x02D2"
#define YC_3DSEP_TRENDLIKE_TH1_inst                                   0x02D2
#define YC_3DSEP_TRENDLIKE_TH1_yc3d_trend_like_sum_th1_shift          (0)
#define YC_3DSEP_TRENDLIKE_TH1_yc3d_trend_like_sum_th1_mask           (0x0000001F)
#define YC_3DSEP_TRENDLIKE_TH1_yc3d_trend_like_sum_th1(data)          (0x0000001F&(data))
#define YC_3DSEP_TRENDLIKE_TH1_get_yc3d_trend_like_sum_th1(data)      (0x0000001F&(data))


#define YC_3DSEP_TRENDLIKE_TH2                                        0x18019b4c
#define YC_3DSEP_TRENDLIKE_TH2_reg_addr                               "0xb8019b4c"
#define YC_3DSEP_TRENDLIKE_TH2_reg                                    0xb8019b4c
#define YC_3DSEP_TRENDLIKE_TH2_inst_addr                              "0x02D3"
#define YC_3DSEP_TRENDLIKE_TH2_inst                                   0x02D3
#define YC_3DSEP_TRENDLIKE_TH2_yc3d_trend_like_sum_th2_shift          (0)
#define YC_3DSEP_TRENDLIKE_TH2_yc3d_trend_like_sum_th2_mask           (0x0000001F)
#define YC_3DSEP_TRENDLIKE_TH2_yc3d_trend_like_sum_th2(data)          (0x0000001F&(data))
#define YC_3DSEP_TRENDLIKE_TH2_get_yc3d_trend_like_sum_th2(data)      (0x0000001F&(data))


#define YC_3DSEP_TRENDLIKE_TH3                                        0x18019b50
#define YC_3DSEP_TRENDLIKE_TH3_reg_addr                               "0xb8019b50"
#define YC_3DSEP_TRENDLIKE_TH3_reg                                    0xb8019b50
#define YC_3DSEP_TRENDLIKE_TH3_inst_addr                              "0x02D4"
#define YC_3DSEP_TRENDLIKE_TH3_inst                                   0x02D4
#define YC_3DSEP_TRENDLIKE_TH3_yc3d_trend_like_sum_th3_shift          (0)
#define YC_3DSEP_TRENDLIKE_TH3_yc3d_trend_like_sum_th3_mask           (0x0000001F)
#define YC_3DSEP_TRENDLIKE_TH3_yc3d_trend_like_sum_th3(data)          (0x0000001F&(data))
#define YC_3DSEP_TRENDLIKE_TH3_get_yc3d_trend_like_sum_th3(data)      (0x0000001F&(data))


#define YC_3DSEP_TRENDLIKE_TH4                                        0x18019b54
#define YC_3DSEP_TRENDLIKE_TH4_reg_addr                               "0xb8019b54"
#define YC_3DSEP_TRENDLIKE_TH4_reg                                    0xb8019b54
#define YC_3DSEP_TRENDLIKE_TH4_inst_addr                              "0x02D5"
#define YC_3DSEP_TRENDLIKE_TH4_inst                                   0x02D5
#define YC_3DSEP_TRENDLIKE_TH4_yc3d_trend_like_sum_th4_shift          (0)
#define YC_3DSEP_TRENDLIKE_TH4_yc3d_trend_like_sum_th4_mask           (0x0000001F)
#define YC_3DSEP_TRENDLIKE_TH4_yc3d_trend_like_sum_th4(data)          (0x0000001F&(data))
#define YC_3DSEP_TRENDLIKE_TH4_get_yc3d_trend_like_sum_th4(data)      (0x0000001F&(data))


#define YC_3DSEP_MISC_CTRL                                            0x18019b58
#define YC_3DSEP_MISC_CTRL_reg_addr                                   "0xb8019b58"
#define YC_3DSEP_MISC_CTRL_reg                                        0xb8019b58
#define YC_3DSEP_MISC_CTRL_inst_addr                                  "0x02D6"
#define YC_3DSEP_MISC_CTRL_inst                                       0x02D6
#define YC_3DSEP_MISC_CTRL_yc3d_magln_det_en_shift                    (7)
#define YC_3DSEP_MISC_CTRL_yc3d_magln_det_status_shift                (6)
#define YC_3DSEP_MISC_CTRL_yc3d_trend_lpf_sel_shift                   (4)
#define YC_3DSEP_MISC_CTRL_yc3d_trend_tb_shift                        (2)
#define YC_3DSEP_MISC_CTRL_yc3d_trend_cbpf_tb_shift                   (0)
#define YC_3DSEP_MISC_CTRL_yc3d_magln_det_en_mask                     (0x00000080)
#define YC_3DSEP_MISC_CTRL_yc3d_magln_det_status_mask                 (0x00000040)
#define YC_3DSEP_MISC_CTRL_yc3d_trend_lpf_sel_mask                    (0x00000030)
#define YC_3DSEP_MISC_CTRL_yc3d_trend_tb_mask                         (0x0000000C)
#define YC_3DSEP_MISC_CTRL_yc3d_trend_cbpf_tb_mask                    (0x00000003)
#define YC_3DSEP_MISC_CTRL_yc3d_magln_det_en(data)                    (0x00000080&((data)<<7))
#define YC_3DSEP_MISC_CTRL_yc3d_magln_det_status(data)                (0x00000040&((data)<<6))
#define YC_3DSEP_MISC_CTRL_yc3d_trend_lpf_sel(data)                   (0x00000030&((data)<<4))
#define YC_3DSEP_MISC_CTRL_yc3d_trend_tb(data)                        (0x0000000C&((data)<<2))
#define YC_3DSEP_MISC_CTRL_yc3d_trend_cbpf_tb(data)                   (0x00000003&(data))
#define YC_3DSEP_MISC_CTRL_get_yc3d_magln_det_en(data)                ((0x00000080&(data))>>7)
#define YC_3DSEP_MISC_CTRL_get_yc3d_magln_det_status(data)            ((0x00000040&(data))>>6)
#define YC_3DSEP_MISC_CTRL_get_yc3d_trend_lpf_sel(data)               ((0x00000030&(data))>>4)
#define YC_3DSEP_MISC_CTRL_get_yc3d_trend_tb(data)                    ((0x0000000C&(data))>>2)
#define YC_3DSEP_MISC_CTRL_get_yc3d_trend_cbpf_tb(data)               (0x00000003&(data))


#define YC_3DSEP_MAGLN_CTRL1                                          0x18019b5c
#define YC_3DSEP_MAGLN_CTRL1_reg_addr                                 "0xb8019b5c"
#define YC_3DSEP_MAGLN_CTRL1_reg                                      0xb8019b5c
#define YC_3DSEP_MAGLN_CTRL1_inst_addr                                "0x02D7"
#define YC_3DSEP_MAGLN_CTRL1_inst                                     0x02D7
#define YC_3DSEP_MAGLN_CTRL1_yc3d_magln_th1_shift                     (4)
#define YC_3DSEP_MAGLN_CTRL1_yc3d_magln_th2_shift                     (0)
#define YC_3DSEP_MAGLN_CTRL1_yc3d_magln_th1_mask                      (0x000000F0)
#define YC_3DSEP_MAGLN_CTRL1_yc3d_magln_th2_mask                      (0x0000000F)
#define YC_3DSEP_MAGLN_CTRL1_yc3d_magln_th1(data)                     (0x000000F0&((data)<<4))
#define YC_3DSEP_MAGLN_CTRL1_yc3d_magln_th2(data)                     (0x0000000F&(data))
#define YC_3DSEP_MAGLN_CTRL1_get_yc3d_magln_th1(data)                 ((0x000000F0&(data))>>4)
#define YC_3DSEP_MAGLN_CTRL1_get_yc3d_magln_th2(data)                 (0x0000000F&(data))


#define YC_3DSEP_MAGLN_CTRL2                                          0x18019b60
#define YC_3DSEP_MAGLN_CTRL2_reg_addr                                 "0xb8019b60"
#define YC_3DSEP_MAGLN_CTRL2_reg                                      0xb8019b60
#define YC_3DSEP_MAGLN_CTRL2_inst_addr                                "0x02D8"
#define YC_3DSEP_MAGLN_CTRL2_inst                                     0x02D8
#define YC_3DSEP_MAGLN_CTRL2_yc3d_magln_sum_th1_shift                 (4)
#define YC_3DSEP_MAGLN_CTRL2_yc3d_magln_sum_th2_shift                 (0)
#define YC_3DSEP_MAGLN_CTRL2_yc3d_magln_sum_th1_mask                  (0x000000F0)
#define YC_3DSEP_MAGLN_CTRL2_yc3d_magln_sum_th2_mask                  (0x0000000F)
#define YC_3DSEP_MAGLN_CTRL2_yc3d_magln_sum_th1(data)                 (0x000000F0&((data)<<4))
#define YC_3DSEP_MAGLN_CTRL2_yc3d_magln_sum_th2(data)                 (0x0000000F&(data))
#define YC_3DSEP_MAGLN_CTRL2_get_yc3d_magln_sum_th1(data)             ((0x000000F0&(data))>>4)
#define YC_3DSEP_MAGLN_CTRL2_get_yc3d_magln_sum_th2(data)             (0x0000000F&(data))


#define YC_3DSEP_CORING_CTRL                                          0x18019b64
#define YC_3DSEP_CORING_CTRL_reg_addr                                 "0xb8019b64"
#define YC_3DSEP_CORING_CTRL_reg                                      0xb8019b64
#define YC_3DSEP_CORING_CTRL_inst_addr                                "0x02D9"
#define YC_3DSEP_CORING_CTRL_inst                                     0x02D9
#define YC_3DSEP_CORING_CTRL_yc3d_chk_prev_frame_shift                (6)
#define YC_3DSEP_CORING_CTRL_yc3d_motion_coring_shift                 (0)
#define YC_3DSEP_CORING_CTRL_yc3d_chk_prev_frame_mask                 (0x000000C0)
#define YC_3DSEP_CORING_CTRL_yc3d_motion_coring_mask                  (0x0000000F)
#define YC_3DSEP_CORING_CTRL_yc3d_chk_prev_frame(data)                (0x000000C0&((data)<<6))
#define YC_3DSEP_CORING_CTRL_yc3d_motion_coring(data)                 (0x0000000F&(data))
#define YC_3DSEP_CORING_CTRL_get_yc3d_chk_prev_frame(data)            ((0x000000C0&(data))>>6)
#define YC_3DSEP_CORING_CTRL_get_yc3d_motion_coring(data)             (0x0000000F&(data))


#define DUMMY_3                                                       0x18019b68
#define DUMMY_3_reg_addr                                              "0xb8019b68"
#define DUMMY_3_reg                                                   0xb8019b68
#define DUMMY_3_inst_addr                                             "0x02DA"
#define DUMMY_3_inst                                                  0x02DA
#define DUMMY_3_dummy_3_shift                                         (0)
#define DUMMY_3_dummy_3_mask                                          (0xFFFFFFFF)
#define DUMMY_3_dummy_3(data)                                         (0xFFFFFFFF&(data))
#define DUMMY_3_get_dummy_3(data)                                     (0xFFFFFFFF&(data))


#define DUMMY_4                                                       0x18019b6c
#define DUMMY_4_reg_addr                                              "0xb8019b6c"
#define DUMMY_4_reg                                                   0xb8019b6c
#define DUMMY_4_inst_addr                                             "0x02DB"
#define DUMMY_4_inst                                                  0x02DB
#define DUMMY_4_dummy_4_shift                                         (0)
#define DUMMY_4_dummy_4_mask                                          (0xFFFFFFFF)
#define DUMMY_4_dummy_4(data)                                         (0xFFFFFFFF&(data))
#define DUMMY_4_get_dummy_4(data)                                     (0xFFFFFFFF&(data))


#define YC_3D_ETS_DEBUGMODE                                           0x18019c00
#define YC_3D_ETS_DEBUGMODE_reg_addr                                  "0xb8019c00"
#define YC_3D_ETS_DEBUGMODE_reg                                       0xb8019c00
#define YC_3D_ETS_DEBUGMODE_inst_addr                                 "0x0300"
#define YC_3D_ETS_DEBUGMODE_inst                                      0x0300
#define YC_3D_ETS_DEBUGMODE_yc3d_ets_debug_en_shift                   (31)
#define YC_3D_ETS_DEBUGMODE_yc3d_ets_debug_mode_shift                 (0)
#define YC_3D_ETS_DEBUGMODE_yc3d_ets_debug_en_mask                    (0x80000000)
#define YC_3D_ETS_DEBUGMODE_yc3d_ets_debug_mode_mask                  (0x0000001F)
#define YC_3D_ETS_DEBUGMODE_yc3d_ets_debug_en(data)                   (0x80000000&((data)<<31))
#define YC_3D_ETS_DEBUGMODE_yc3d_ets_debug_mode(data)                 (0x0000001F&(data))
#define YC_3D_ETS_DEBUGMODE_get_yc3d_ets_debug_en(data)               ((0x80000000&(data))>>31)
#define YC_3D_ETS_DEBUGMODE_get_yc3d_ets_debug_mode(data)             (0x0000001F&(data))


#define YC_3D_EDGE_TYPE_CTRL                                          0x18019c04
#define YC_3D_EDGE_TYPE_CTRL_reg_addr                                 "0xb8019c04"
#define YC_3D_EDGE_TYPE_CTRL_reg                                      0xb8019c04
#define YC_3D_EDGE_TYPE_CTRL_inst_addr                                "0x0301"
#define YC_3D_EDGE_TYPE_CTRL_inst                                     0x0301
#define YC_3D_EDGE_TYPE_CTRL_yc3d_sep_mode_pal_shift                  (30)
#define YC_3D_EDGE_TYPE_CTRL_yc3d_et_3d_dir_shift                     (28)
#define YC_3D_EDGE_TYPE_CTRL_yc3d_et_wise_ignore_lsb_en_shift         (11)
#define YC_3D_EDGE_TYPE_CTRL_yc3d_et_wise_amp_en_shift                (10)
#define YC_3D_EDGE_TYPE_CTRL_yc3d_et_wise_near_only_shift             (9)
#define YC_3D_EDGE_TYPE_CTRL_yc3d_et_wise_1d_crct_en_shift            (8)
#define YC_3D_EDGE_TYPE_CTRL_yc3d_et_wise_en_shift                    (6)
#define YC_3D_EDGE_TYPE_CTRL_yc3d_et_edge_c3d_shift                   (5)
#define YC_3D_EDGE_TYPE_CTRL_yc3d_et_c2d_en_shift                     (4)
#define YC_3D_EDGE_TYPE_CTRL_yc3d_et_nedgepair_en_shift               (2)
#define YC_3D_EDGE_TYPE_CTRL_yc3d_et_y_time_cnt_strict_en_shift       (1)
#define YC_3D_EDGE_TYPE_CTRL_yc3d_et_etstill_en_shift                 (0)
#define YC_3D_EDGE_TYPE_CTRL_yc3d_sep_mode_pal_mask                   (0x40000000)
#define YC_3D_EDGE_TYPE_CTRL_yc3d_et_3d_dir_mask                      (0x30000000)
#define YC_3D_EDGE_TYPE_CTRL_yc3d_et_wise_ignore_lsb_en_mask          (0x00000800)
#define YC_3D_EDGE_TYPE_CTRL_yc3d_et_wise_amp_en_mask                 (0x00000400)
#define YC_3D_EDGE_TYPE_CTRL_yc3d_et_wise_near_only_mask              (0x00000200)
#define YC_3D_EDGE_TYPE_CTRL_yc3d_et_wise_1d_crct_en_mask             (0x00000100)
#define YC_3D_EDGE_TYPE_CTRL_yc3d_et_wise_en_mask                     (0x00000040)
#define YC_3D_EDGE_TYPE_CTRL_yc3d_et_edge_c3d_mask                    (0x00000020)
#define YC_3D_EDGE_TYPE_CTRL_yc3d_et_c2d_en_mask                      (0x00000010)
#define YC_3D_EDGE_TYPE_CTRL_yc3d_et_nedgepair_en_mask                (0x00000004)
#define YC_3D_EDGE_TYPE_CTRL_yc3d_et_y_time_cnt_strict_en_mask        (0x00000002)
#define YC_3D_EDGE_TYPE_CTRL_yc3d_et_etstill_en_mask                  (0x00000001)
#define YC_3D_EDGE_TYPE_CTRL_yc3d_sep_mode_pal(data)                  (0x40000000&((data)<<30))
#define YC_3D_EDGE_TYPE_CTRL_yc3d_et_3d_dir(data)                     (0x30000000&((data)<<28))
#define YC_3D_EDGE_TYPE_CTRL_yc3d_et_wise_ignore_lsb_en(data)         (0x00000800&((data)<<11))
#define YC_3D_EDGE_TYPE_CTRL_yc3d_et_wise_amp_en(data)                (0x00000400&((data)<<10))
#define YC_3D_EDGE_TYPE_CTRL_yc3d_et_wise_near_only(data)             (0x00000200&((data)<<9))
#define YC_3D_EDGE_TYPE_CTRL_yc3d_et_wise_1d_crct_en(data)            (0x00000100&((data)<<8))
#define YC_3D_EDGE_TYPE_CTRL_yc3d_et_wise_en(data)                    (0x00000040&((data)<<6))
#define YC_3D_EDGE_TYPE_CTRL_yc3d_et_edge_c3d(data)                   (0x00000020&((data)<<5))
#define YC_3D_EDGE_TYPE_CTRL_yc3d_et_c2d_en(data)                     (0x00000010&((data)<<4))
#define YC_3D_EDGE_TYPE_CTRL_yc3d_et_nedgepair_en(data)               (0x00000004&((data)<<2))
#define YC_3D_EDGE_TYPE_CTRL_yc3d_et_y_time_cnt_strict_en(data)       (0x00000002&((data)<<1))
#define YC_3D_EDGE_TYPE_CTRL_yc3d_et_etstill_en(data)                 (0x00000001&(data))
#define YC_3D_EDGE_TYPE_CTRL_get_yc3d_sep_mode_pal(data)              ((0x40000000&(data))>>30)
#define YC_3D_EDGE_TYPE_CTRL_get_yc3d_et_3d_dir(data)                 ((0x30000000&(data))>>28)
#define YC_3D_EDGE_TYPE_CTRL_get_yc3d_et_wise_ignore_lsb_en(data)     ((0x00000800&(data))>>11)
#define YC_3D_EDGE_TYPE_CTRL_get_yc3d_et_wise_amp_en(data)            ((0x00000400&(data))>>10)
#define YC_3D_EDGE_TYPE_CTRL_get_yc3d_et_wise_near_only(data)         ((0x00000200&(data))>>9)
#define YC_3D_EDGE_TYPE_CTRL_get_yc3d_et_wise_1d_crct_en(data)        ((0x00000100&(data))>>8)
#define YC_3D_EDGE_TYPE_CTRL_get_yc3d_et_wise_en(data)                ((0x00000040&(data))>>6)
#define YC_3D_EDGE_TYPE_CTRL_get_yc3d_et_edge_c3d(data)               ((0x00000020&(data))>>5)
#define YC_3D_EDGE_TYPE_CTRL_get_yc3d_et_c2d_en(data)                 ((0x00000010&(data))>>4)
#define YC_3D_EDGE_TYPE_CTRL_get_yc3d_et_nedgepair_en(data)           ((0x00000004&(data))>>2)
#define YC_3D_EDGE_TYPE_CTRL_get_yc3d_et_y_time_cnt_strict_en(data)   ((0x00000002&(data))>>1)
#define YC_3D_EDGE_TYPE_CTRL_get_yc3d_et_etstill_en(data)             (0x00000001&(data))


#define YC_3D_ET_ALPHA_TH                                             0x18019c08
#define YC_3D_ET_ALPHA_TH_reg_addr                                    "0xb8019c08"
#define YC_3D_ET_ALPHA_TH_reg                                         0xb8019c08
#define YC_3D_ET_ALPHA_TH_inst_addr                                   "0x0302"
#define YC_3D_ET_ALPHA_TH_inst                                        0x0302
#define YC_3D_ET_ALPHA_TH_yc3d_et_alpha_th5_shift                     (16)
#define YC_3D_ET_ALPHA_TH_yc3d_et_alpha_th4_shift                     (12)
#define YC_3D_ET_ALPHA_TH_yc3d_et_alpha_th3_shift                     (8)
#define YC_3D_ET_ALPHA_TH_yc3d_et_alpha_th2_shift                     (4)
#define YC_3D_ET_ALPHA_TH_yc3d_et_alpha_th1_shift                     (0)
#define YC_3D_ET_ALPHA_TH_yc3d_et_alpha_th5_mask                      (0x000F0000)
#define YC_3D_ET_ALPHA_TH_yc3d_et_alpha_th4_mask                      (0x0000F000)
#define YC_3D_ET_ALPHA_TH_yc3d_et_alpha_th3_mask                      (0x00000F00)
#define YC_3D_ET_ALPHA_TH_yc3d_et_alpha_th2_mask                      (0x000000F0)
#define YC_3D_ET_ALPHA_TH_yc3d_et_alpha_th1_mask                      (0x0000000F)
#define YC_3D_ET_ALPHA_TH_yc3d_et_alpha_th5(data)                     (0x000F0000&((data)<<16))
#define YC_3D_ET_ALPHA_TH_yc3d_et_alpha_th4(data)                     (0x0000F000&((data)<<12))
#define YC_3D_ET_ALPHA_TH_yc3d_et_alpha_th3(data)                     (0x00000F00&((data)<<8))
#define YC_3D_ET_ALPHA_TH_yc3d_et_alpha_th2(data)                     (0x000000F0&((data)<<4))
#define YC_3D_ET_ALPHA_TH_yc3d_et_alpha_th1(data)                     (0x0000000F&(data))
#define YC_3D_ET_ALPHA_TH_get_yc3d_et_alpha_th5(data)                 ((0x000F0000&(data))>>16)
#define YC_3D_ET_ALPHA_TH_get_yc3d_et_alpha_th4(data)                 ((0x0000F000&(data))>>12)
#define YC_3D_ET_ALPHA_TH_get_yc3d_et_alpha_th3(data)                 ((0x00000F00&(data))>>8)
#define YC_3D_ET_ALPHA_TH_get_yc3d_et_alpha_th2(data)                 ((0x000000F0&(data))>>4)
#define YC_3D_ET_ALPHA_TH_get_yc3d_et_alpha_th1(data)                 (0x0000000F&(data))


#define YC_3D_ET_CNT_TH                                               0x18019c0c
#define YC_3D_ET_CNT_TH_reg_addr                                      "0xb8019c0c"
#define YC_3D_ET_CNT_TH_reg                                           0xb8019c0c
#define YC_3D_ET_CNT_TH_inst_addr                                     "0x0303"
#define YC_3D_ET_CNT_TH_inst                                          0x0303
#define YC_3D_ET_CNT_TH_yc3d_et_nedge_cnt_th_shift                    (4)
#define YC_3D_ET_CNT_TH_yc3d_et_match_cnt_th_shift                    (0)
#define YC_3D_ET_CNT_TH_yc3d_et_nedge_cnt_th_mask                     (0x000000F0)
#define YC_3D_ET_CNT_TH_yc3d_et_match_cnt_th_mask                     (0x0000000F)
#define YC_3D_ET_CNT_TH_yc3d_et_nedge_cnt_th(data)                    (0x000000F0&((data)<<4))
#define YC_3D_ET_CNT_TH_yc3d_et_match_cnt_th(data)                    (0x0000000F&(data))
#define YC_3D_ET_CNT_TH_get_yc3d_et_nedge_cnt_th(data)                ((0x000000F0&(data))>>4)
#define YC_3D_ET_CNT_TH_get_yc3d_et_match_cnt_th(data)                (0x0000000F&(data))


#define YC_3D_ET_SOBEL_TH                                             0x18019c10
#define YC_3D_ET_SOBEL_TH_reg_addr                                    "0xb8019c10"
#define YC_3D_ET_SOBEL_TH_reg                                         0xb8019c10
#define YC_3D_ET_SOBEL_TH_inst_addr                                   "0x0304"
#define YC_3D_ET_SOBEL_TH_inst                                        0x0304
#define YC_3D_ET_SOBEL_TH_yc3d_et_sobel_ths_shift                     (8)
#define YC_3D_ET_SOBEL_TH_yc3d_et_sobel_thm_shift                     (0)
#define YC_3D_ET_SOBEL_TH_yc3d_et_sobel_ths_mask                      (0x0000FF00)
#define YC_3D_ET_SOBEL_TH_yc3d_et_sobel_thm_mask                      (0x000000FF)
#define YC_3D_ET_SOBEL_TH_yc3d_et_sobel_ths(data)                     (0x0000FF00&((data)<<8))
#define YC_3D_ET_SOBEL_TH_yc3d_et_sobel_thm(data)                     (0x000000FF&(data))
#define YC_3D_ET_SOBEL_TH_get_yc3d_et_sobel_ths(data)                 ((0x0000FF00&(data))>>8)
#define YC_3D_ET_SOBEL_TH_get_yc3d_et_sobel_thm(data)                 (0x000000FF&(data))


#define YC_3D_ET_C2D_C3D_TH                                           0x18019c14
#define YC_3D_ET_C2D_C3D_TH_reg_addr                                  "0xb8019c14"
#define YC_3D_ET_C2D_C3D_TH_reg                                       0xb8019c14
#define YC_3D_ET_C2D_C3D_TH_inst_addr                                 "0x0305"
#define YC_3D_ET_C2D_C3D_TH_inst                                      0x0305
#define YC_3D_ET_C2D_C3D_TH_yc3d_et_c2d_cnt_th_shift                  (24)
#define YC_3D_ET_C2D_C3D_TH_yc3d_et_c3d_cnt_th_shift                  (16)
#define YC_3D_ET_C2D_C3D_TH_yc3d_et_c2d_like_th_shift                 (8)
#define YC_3D_ET_C2D_C3D_TH_yc3d_et_c3d_diff_th_shift                 (0)
#define YC_3D_ET_C2D_C3D_TH_yc3d_et_c2d_cnt_th_mask                   (0x0F000000)
#define YC_3D_ET_C2D_C3D_TH_yc3d_et_c3d_cnt_th_mask                   (0x000F0000)
#define YC_3D_ET_C2D_C3D_TH_yc3d_et_c2d_like_th_mask                  (0x0000FF00)
#define YC_3D_ET_C2D_C3D_TH_yc3d_et_c3d_diff_th_mask                  (0x000000FF)
#define YC_3D_ET_C2D_C3D_TH_yc3d_et_c2d_cnt_th(data)                  (0x0F000000&((data)<<24))
#define YC_3D_ET_C2D_C3D_TH_yc3d_et_c3d_cnt_th(data)                  (0x000F0000&((data)<<16))
#define YC_3D_ET_C2D_C3D_TH_yc3d_et_c2d_like_th(data)                 (0x0000FF00&((data)<<8))
#define YC_3D_ET_C2D_C3D_TH_yc3d_et_c3d_diff_th(data)                 (0x000000FF&(data))
#define YC_3D_ET_C2D_C3D_TH_get_yc3d_et_c2d_cnt_th(data)              ((0x0F000000&(data))>>24)
#define YC_3D_ET_C2D_C3D_TH_get_yc3d_et_c3d_cnt_th(data)              ((0x000F0000&(data))>>16)
#define YC_3D_ET_C2D_C3D_TH_get_yc3d_et_c2d_like_th(data)             ((0x0000FF00&(data))>>8)
#define YC_3D_ET_C2D_C3D_TH_get_yc3d_et_c3d_diff_th(data)             (0x000000FF&(data))


#define YC_3D_ET_2PAIR_TH                                             0x18019c18
#define YC_3D_ET_2PAIR_TH_reg_addr                                    "0xb8019c18"
#define YC_3D_ET_2PAIR_TH_reg                                         0xb8019c18
#define YC_3D_ET_2PAIR_TH_inst_addr                                   "0x0306"
#define YC_3D_ET_2PAIR_TH_inst                                        0x0306
#define YC_3D_ET_2PAIR_TH_yc3d_et_2pair_cnt_th_shift                  (8)
#define YC_3D_ET_2PAIR_TH_yc3d_et_2pair_diff_th_shift                 (0)
#define YC_3D_ET_2PAIR_TH_yc3d_et_2pair_cnt_th_mask                   (0x00000F00)
#define YC_3D_ET_2PAIR_TH_yc3d_et_2pair_diff_th_mask                  (0x000000FF)
#define YC_3D_ET_2PAIR_TH_yc3d_et_2pair_cnt_th(data)                  (0x00000F00&((data)<<8))
#define YC_3D_ET_2PAIR_TH_yc3d_et_2pair_diff_th(data)                 (0x000000FF&(data))
#define YC_3D_ET_2PAIR_TH_get_yc3d_et_2pair_cnt_th(data)              ((0x00000F00&(data))>>8)
#define YC_3D_ET_2PAIR_TH_get_yc3d_et_2pair_diff_th(data)             (0x000000FF&(data))


#define YC_3D_ET_WISE_TH                                              0x18019c1c
#define YC_3D_ET_WISE_TH_reg_addr                                     "0xb8019c1c"
#define YC_3D_ET_WISE_TH_reg                                          0xb8019c1c
#define YC_3D_ET_WISE_TH_inst_addr                                    "0x0307"
#define YC_3D_ET_WISE_TH_inst                                         0x0307
#define YC_3D_ET_WISE_TH_yc3d_et_wise_amp_th_big_shift                (0)
#define YC_3D_ET_WISE_TH_yc3d_et_wise_amp_th_big_mask                 (0x000000FF)
#define YC_3D_ET_WISE_TH_yc3d_et_wise_amp_th_big(data)                (0x000000FF&(data))
#define YC_3D_ET_WISE_TH_get_yc3d_et_wise_amp_th_big(data)            (0x000000FF&(data))


#define YC_3D_PSE_CTRL                                                0x18019c20
#define YC_3D_PSE_CTRL_reg_addr                                       "0xb8019c20"
#define YC_3D_PSE_CTRL_reg                                            0xb8019c20
#define YC_3D_PSE_CTRL_inst_addr                                      "0x0308"
#define YC_3D_PSE_CTRL_inst                                           0x0308
#define YC_3D_PSE_CTRL_yc3d_ets_wise_pse_en_shift                     (7)
#define YC_3D_PSE_CTRL_yc3d_wise_pse_cnt_window_sel_shift             (6)
#define YC_3D_PSE_CTRL_yc3d_wise_pse_cnt_th_shift                     (0)
#define YC_3D_PSE_CTRL_yc3d_ets_wise_pse_en_mask                      (0x00000080)
#define YC_3D_PSE_CTRL_yc3d_wise_pse_cnt_window_sel_mask              (0x00000040)
#define YC_3D_PSE_CTRL_yc3d_wise_pse_cnt_th_mask                      (0x0000001F)
#define YC_3D_PSE_CTRL_yc3d_ets_wise_pse_en(data)                     (0x00000080&((data)<<7))
#define YC_3D_PSE_CTRL_yc3d_wise_pse_cnt_window_sel(data)             (0x00000040&((data)<<6))
#define YC_3D_PSE_CTRL_yc3d_wise_pse_cnt_th(data)                     (0x0000001F&(data))
#define YC_3D_PSE_CTRL_get_yc3d_ets_wise_pse_en(data)                 ((0x00000080&(data))>>7)
#define YC_3D_PSE_CTRL_get_yc3d_wise_pse_cnt_window_sel(data)         ((0x00000040&(data))>>6)
#define YC_3D_PSE_CTRL_get_yc3d_wise_pse_cnt_th(data)                 (0x0000001F&(data))


#define YC_3D_PSE_THS                                                 0x18019c24
#define YC_3D_PSE_THS_reg_addr                                        "0xb8019c24"
#define YC_3D_PSE_THS_reg                                             0xb8019c24
#define YC_3D_PSE_THS_inst_addr                                       "0x0309"
#define YC_3D_PSE_THS_inst                                            0x0309
#define YC_3D_PSE_THS_yc3d_ets_wise_pse_ths_shift                     (0)
#define YC_3D_PSE_THS_yc3d_ets_wise_pse_ths_mask                      (0x0000001F)
#define YC_3D_PSE_THS_yc3d_ets_wise_pse_ths(data)                     (0x0000001F&(data))
#define YC_3D_PSE_THS_get_yc3d_ets_wise_pse_ths(data)                 (0x0000001F&(data))


#define YC_3D_PSE_THD                                                 0x18019c28
#define YC_3D_PSE_THD_reg_addr                                        "0xb8019c28"
#define YC_3D_PSE_THD_reg                                             0xb8019c28
#define YC_3D_PSE_THD_inst_addr                                       "0x030A"
#define YC_3D_PSE_THD_inst                                            0x030A
#define YC_3D_PSE_THD_yc3d_ets_wise_pse_thd_shift                     (0)
#define YC_3D_PSE_THD_yc3d_ets_wise_pse_thd_mask                      (0x0000001F)
#define YC_3D_PSE_THD_yc3d_ets_wise_pse_thd(data)                     (0x0000001F&(data))
#define YC_3D_PSE_THD_get_yc3d_ets_wise_pse_thd(data)                 (0x0000001F&(data))


#define YC_3D_PSE_AVG_TH1                                             0x18019c2c
#define YC_3D_PSE_AVG_TH1_reg_addr                                    "0xb8019c2c"
#define YC_3D_PSE_AVG_TH1_reg                                         0xb8019c2c
#define YC_3D_PSE_AVG_TH1_inst_addr                                   "0x030B"
#define YC_3D_PSE_AVG_TH1_inst                                        0x030B
#define YC_3D_PSE_AVG_TH1_yc3d_ets_wise_pse_avg_th1_shift             (0)
#define YC_3D_PSE_AVG_TH1_yc3d_ets_wise_pse_avg_th1_mask              (0x0000003F)
#define YC_3D_PSE_AVG_TH1_yc3d_ets_wise_pse_avg_th1(data)             (0x0000003F&(data))
#define YC_3D_PSE_AVG_TH1_get_yc3d_ets_wise_pse_avg_th1(data)         (0x0000003F&(data))


#define YC_3D_PSE_AVG_TH2                                             0x18019c30
#define YC_3D_PSE_AVG_TH2_reg_addr                                    "0xb8019c30"
#define YC_3D_PSE_AVG_TH2_reg                                         0xb8019c30
#define YC_3D_PSE_AVG_TH2_inst_addr                                   "0x030C"
#define YC_3D_PSE_AVG_TH2_inst                                        0x030C
#define YC_3D_PSE_AVG_TH2_yc3d_ets_wise_pse_avg_th2_shift             (0)
#define YC_3D_PSE_AVG_TH2_yc3d_ets_wise_pse_avg_th2_mask              (0x0000003F)
#define YC_3D_PSE_AVG_TH2_yc3d_ets_wise_pse_avg_th2(data)             (0x0000003F&(data))
#define YC_3D_PSE_AVG_TH2_get_yc3d_ets_wise_pse_avg_th2(data)         (0x0000003F&(data))


#define YC_3D_PSE_COM                                                 0x18019c34
#define YC_3D_PSE_COM_reg_addr                                        "0xb8019c34"
#define YC_3D_PSE_COM_reg                                             0xb8019c34
#define YC_3D_PSE_COM_inst_addr                                       "0x030D"
#define YC_3D_PSE_COM_inst                                            0x030D
#define YC_3D_PSE_COM_yc3d_ets_wise_pse_com3_shift                    (16)
#define YC_3D_PSE_COM_yc3d_ets_wise_pse_com2_shift                    (8)
#define YC_3D_PSE_COM_yc3d_ets_wise_pse_com1_shift                    (0)
#define YC_3D_PSE_COM_yc3d_ets_wise_pse_com3_mask                     (0x007F0000)
#define YC_3D_PSE_COM_yc3d_ets_wise_pse_com2_mask                     (0x00007F00)
#define YC_3D_PSE_COM_yc3d_ets_wise_pse_com1_mask                     (0x0000007F)
#define YC_3D_PSE_COM_yc3d_ets_wise_pse_com3(data)                    (0x007F0000&((data)<<16))
#define YC_3D_PSE_COM_yc3d_ets_wise_pse_com2(data)                    (0x00007F00&((data)<<8))
#define YC_3D_PSE_COM_yc3d_ets_wise_pse_com1(data)                    (0x0000007F&(data))
#define YC_3D_PSE_COM_get_yc3d_ets_wise_pse_com3(data)                ((0x007F0000&(data))>>16)
#define YC_3D_PSE_COM_get_yc3d_ets_wise_pse_com2(data)                ((0x00007F00&(data))>>8)
#define YC_3D_PSE_COM_get_yc3d_ets_wise_pse_com1(data)                (0x0000007F&(data))


#define YC_3D_NO_PALMODE_1                                            0x18019c68
#define YC_3D_NO_PALMODE_1_reg_addr                                   "0xb8019c68"
#define YC_3D_NO_PALMODE_1_reg                                        0xb8019c68
#define YC_3D_NO_PALMODE_1_inst_addr                                  "0x031A"
#define YC_3D_NO_PALMODE_1_inst                                       0x031A
#define YC_3D_NO_PALMODE_1_yc3d_ver_hifreq_sel_shift                  (31)
#define YC_3D_NO_PALMODE_1_yc3d_ets_wise_pse_ths_up_shift             (20)
#define YC_3D_NO_PALMODE_1_yc3d_fifd_noise_offset_shift               (12)
#define YC_3D_NO_PALMODE_1_yc3d_ver_hifreq_sel_mask                   (0x80000000)
#define YC_3D_NO_PALMODE_1_yc3d_ets_wise_pse_ths_up_mask              (0x1FF00000)
#define YC_3D_NO_PALMODE_1_yc3d_fifd_noise_offset_mask                (0x0001F000)
#define YC_3D_NO_PALMODE_1_yc3d_ver_hifreq_sel(data)                  (0x80000000&((data)<<31))
#define YC_3D_NO_PALMODE_1_yc3d_ets_wise_pse_ths_up(data)             (0x1FF00000&((data)<<20))
#define YC_3D_NO_PALMODE_1_yc3d_fifd_noise_offset(data)               (0x0001F000&((data)<<12))
#define YC_3D_NO_PALMODE_1_get_yc3d_ver_hifreq_sel(data)              ((0x80000000&(data))>>31)
#define YC_3D_NO_PALMODE_1_get_yc3d_ets_wise_pse_ths_up(data)         ((0x1FF00000&(data))>>20)
#define YC_3D_NO_PALMODE_1_get_yc3d_fifd_noise_offset(data)           ((0x0001F000&(data))>>12)


#define YC_3D_NO_PALMODE_2                                            0x18019c6c
#define YC_3D_NO_PALMODE_2_reg_addr                                   "0xb8019c6c"
#define YC_3D_NO_PALMODE_2_reg                                        0xb8019c6c
#define YC_3D_NO_PALMODE_2_inst_addr                                  "0x031B"
#define YC_3D_NO_PALMODE_2_inst                                       0x031B
#define YC_3D_NO_PALMODE_2_yc3d_ets_far_still_th_shift                (24)
#define YC_3D_NO_PALMODE_2_yc3d_ets_far_still_com_en_shift            (15)
#define YC_3D_NO_PALMODE_2_yc3d_ets_cvbs_far_still_com_shift          (8)
#define YC_3D_NO_PALMODE_2_yc3d_ets_np_no_palmode_sel_shift           (4)
#define YC_3D_NO_PALMODE_2_yc3d_ets_em_no_palmode_shift               (3)
#define YC_3D_NO_PALMODE_2_yc3d_ets_em_pse_en_shift                   (2)
#define YC_3D_NO_PALMODE_2_yc3d_ets_np_no_palmode_shift               (1)
#define YC_3D_NO_PALMODE_2_yc3d_ets_np_pse_en_shift                   (0)
#define YC_3D_NO_PALMODE_2_yc3d_ets_far_still_th_mask                 (0x3F000000)
#define YC_3D_NO_PALMODE_2_yc3d_ets_far_still_com_en_mask             (0x00008000)
#define YC_3D_NO_PALMODE_2_yc3d_ets_cvbs_far_still_com_mask           (0x00007F00)
#define YC_3D_NO_PALMODE_2_yc3d_ets_np_no_palmode_sel_mask            (0x00000010)
#define YC_3D_NO_PALMODE_2_yc3d_ets_em_no_palmode_mask                (0x00000008)
#define YC_3D_NO_PALMODE_2_yc3d_ets_em_pse_en_mask                    (0x00000004)
#define YC_3D_NO_PALMODE_2_yc3d_ets_np_no_palmode_mask                (0x00000002)
#define YC_3D_NO_PALMODE_2_yc3d_ets_np_pse_en_mask                    (0x00000001)
#define YC_3D_NO_PALMODE_2_yc3d_ets_far_still_th(data)                (0x3F000000&((data)<<24))
#define YC_3D_NO_PALMODE_2_yc3d_ets_far_still_com_en(data)            (0x00008000&((data)<<15))
#define YC_3D_NO_PALMODE_2_yc3d_ets_cvbs_far_still_com(data)          (0x00007F00&((data)<<8))
#define YC_3D_NO_PALMODE_2_yc3d_ets_np_no_palmode_sel(data)           (0x00000010&((data)<<4))
#define YC_3D_NO_PALMODE_2_yc3d_ets_em_no_palmode(data)               (0x00000008&((data)<<3))
#define YC_3D_NO_PALMODE_2_yc3d_ets_em_pse_en(data)                   (0x00000004&((data)<<2))
#define YC_3D_NO_PALMODE_2_yc3d_ets_np_no_palmode(data)               (0x00000002&((data)<<1))
#define YC_3D_NO_PALMODE_2_yc3d_ets_np_pse_en(data)                   (0x00000001&(data))
#define YC_3D_NO_PALMODE_2_get_yc3d_ets_far_still_th(data)            ((0x3F000000&(data))>>24)
#define YC_3D_NO_PALMODE_2_get_yc3d_ets_far_still_com_en(data)        ((0x00008000&(data))>>15)
#define YC_3D_NO_PALMODE_2_get_yc3d_ets_cvbs_far_still_com(data)      ((0x00007F00&(data))>>8)
#define YC_3D_NO_PALMODE_2_get_yc3d_ets_np_no_palmode_sel(data)       ((0x00000010&(data))>>4)
#define YC_3D_NO_PALMODE_2_get_yc3d_ets_em_no_palmode(data)           ((0x00000008&(data))>>3)
#define YC_3D_NO_PALMODE_2_get_yc3d_ets_em_pse_en(data)               ((0x00000004&(data))>>2)
#define YC_3D_NO_PALMODE_2_get_yc3d_ets_np_no_palmode(data)           ((0x00000002&(data))>>1)
#define YC_3D_NO_PALMODE_2_get_yc3d_ets_np_pse_en(data)               (0x00000001&(data))


#define YC_3D_HI_FREQ_CTRL                                            0x18019cf8
#define YC_3D_HI_FREQ_CTRL_reg_addr                                   "0xb8019cf8"
#define YC_3D_HI_FREQ_CTRL_reg                                        0xb8019cf8
#define YC_3D_HI_FREQ_CTRL_inst_addr                                  "0x033E"
#define YC_3D_HI_FREQ_CTRL_inst                                       0x033E
#define YC_3D_HI_FREQ_CTRL_yc3d_et_hifreq_adjust_wise_gain_shift      (28)
#define YC_3D_HI_FREQ_CTRL_yc3d_et_hifreq_adjust_c2d_gain_shift       (24)
#define YC_3D_HI_FREQ_CTRL_yc3d_et_hifreq_adjust_c3d_gain_shift       (20)
#define YC_3D_HI_FREQ_CTRL_yc3d_et_hifreq_adjust_wise_hv_shift        (16)
#define YC_3D_HI_FREQ_CTRL_yc3d_et_hifreq_adjust_c2d_hv_shift         (14)
#define YC_3D_HI_FREQ_CTRL_yc3d_et_hifreq_adjust_c3d_hv_shift         (12)
#define YC_3D_HI_FREQ_CTRL_yc3d_et_hor_hifreq_range_shift             (11)
#define YC_3D_HI_FREQ_CTRL_yc3d_et_ver_hifreq_ext_range_shift         (8)
#define YC_3D_HI_FREQ_CTRL_yc3d_et_hifreq_adjust_wise_shift           (6)
#define YC_3D_HI_FREQ_CTRL_yc3d_et_hifreq_adjust_c2d_shift            (5)
#define YC_3D_HI_FREQ_CTRL_yc3d_et_hifreq_adjust_c3d_shift            (4)
#define YC_3D_HI_FREQ_CTRL_yc3d_et_hifreq_disable_wise_shift          (2)
#define YC_3D_HI_FREQ_CTRL_yc3d_et_hifreq_disable_c2d_shift           (1)
#define YC_3D_HI_FREQ_CTRL_yc3d_et_hifreq_disable_c3d_shift           (0)
#define YC_3D_HI_FREQ_CTRL_yc3d_et_hifreq_adjust_wise_gain_mask       (0x70000000)
#define YC_3D_HI_FREQ_CTRL_yc3d_et_hifreq_adjust_c2d_gain_mask        (0x07000000)
#define YC_3D_HI_FREQ_CTRL_yc3d_et_hifreq_adjust_c3d_gain_mask        (0x00700000)
#define YC_3D_HI_FREQ_CTRL_yc3d_et_hifreq_adjust_wise_hv_mask         (0x00030000)
#define YC_3D_HI_FREQ_CTRL_yc3d_et_hifreq_adjust_c2d_hv_mask          (0x0000C000)
#define YC_3D_HI_FREQ_CTRL_yc3d_et_hifreq_adjust_c3d_hv_mask          (0x00003000)
#define YC_3D_HI_FREQ_CTRL_yc3d_et_hor_hifreq_range_mask              (0x00000800)
#define YC_3D_HI_FREQ_CTRL_yc3d_et_ver_hifreq_ext_range_mask          (0x00000700)
#define YC_3D_HI_FREQ_CTRL_yc3d_et_hifreq_adjust_wise_mask            (0x00000040)
#define YC_3D_HI_FREQ_CTRL_yc3d_et_hifreq_adjust_c2d_mask             (0x00000020)
#define YC_3D_HI_FREQ_CTRL_yc3d_et_hifreq_adjust_c3d_mask             (0x00000010)
#define YC_3D_HI_FREQ_CTRL_yc3d_et_hifreq_disable_wise_mask           (0x00000004)
#define YC_3D_HI_FREQ_CTRL_yc3d_et_hifreq_disable_c2d_mask            (0x00000002)
#define YC_3D_HI_FREQ_CTRL_yc3d_et_hifreq_disable_c3d_mask            (0x00000001)
#define YC_3D_HI_FREQ_CTRL_yc3d_et_hifreq_adjust_wise_gain(data)      (0x70000000&((data)<<28))
#define YC_3D_HI_FREQ_CTRL_yc3d_et_hifreq_adjust_c2d_gain(data)       (0x07000000&((data)<<24))
#define YC_3D_HI_FREQ_CTRL_yc3d_et_hifreq_adjust_c3d_gain(data)       (0x00700000&((data)<<20))
#define YC_3D_HI_FREQ_CTRL_yc3d_et_hifreq_adjust_wise_hv(data)        (0x00030000&((data)<<16))
#define YC_3D_HI_FREQ_CTRL_yc3d_et_hifreq_adjust_c2d_hv(data)         (0x0000C000&((data)<<14))
#define YC_3D_HI_FREQ_CTRL_yc3d_et_hifreq_adjust_c3d_hv(data)         (0x00003000&((data)<<12))
#define YC_3D_HI_FREQ_CTRL_yc3d_et_hor_hifreq_range(data)             (0x00000800&((data)<<11))
#define YC_3D_HI_FREQ_CTRL_yc3d_et_ver_hifreq_ext_range(data)         (0x00000700&((data)<<8))
#define YC_3D_HI_FREQ_CTRL_yc3d_et_hifreq_adjust_wise(data)           (0x00000040&((data)<<6))
#define YC_3D_HI_FREQ_CTRL_yc3d_et_hifreq_adjust_c2d(data)            (0x00000020&((data)<<5))
#define YC_3D_HI_FREQ_CTRL_yc3d_et_hifreq_adjust_c3d(data)            (0x00000010&((data)<<4))
#define YC_3D_HI_FREQ_CTRL_yc3d_et_hifreq_disable_wise(data)          (0x00000004&((data)<<2))
#define YC_3D_HI_FREQ_CTRL_yc3d_et_hifreq_disable_c2d(data)           (0x00000002&((data)<<1))
#define YC_3D_HI_FREQ_CTRL_yc3d_et_hifreq_disable_c3d(data)           (0x00000001&(data))
#define YC_3D_HI_FREQ_CTRL_get_yc3d_et_hifreq_adjust_wise_gain(data)  ((0x70000000&(data))>>28)
#define YC_3D_HI_FREQ_CTRL_get_yc3d_et_hifreq_adjust_c2d_gain(data)   ((0x07000000&(data))>>24)
#define YC_3D_HI_FREQ_CTRL_get_yc3d_et_hifreq_adjust_c3d_gain(data)   ((0x00700000&(data))>>20)
#define YC_3D_HI_FREQ_CTRL_get_yc3d_et_hifreq_adjust_wise_hv(data)    ((0x00030000&(data))>>16)
#define YC_3D_HI_FREQ_CTRL_get_yc3d_et_hifreq_adjust_c2d_hv(data)     ((0x0000C000&(data))>>14)
#define YC_3D_HI_FREQ_CTRL_get_yc3d_et_hifreq_adjust_c3d_hv(data)     ((0x00003000&(data))>>12)
#define YC_3D_HI_FREQ_CTRL_get_yc3d_et_hor_hifreq_range(data)         ((0x00000800&(data))>>11)
#define YC_3D_HI_FREQ_CTRL_get_yc3d_et_ver_hifreq_ext_range(data)     ((0x00000700&(data))>>8)
#define YC_3D_HI_FREQ_CTRL_get_yc3d_et_hifreq_adjust_wise(data)       ((0x00000040&(data))>>6)
#define YC_3D_HI_FREQ_CTRL_get_yc3d_et_hifreq_adjust_c2d(data)        ((0x00000020&(data))>>5)
#define YC_3D_HI_FREQ_CTRL_get_yc3d_et_hifreq_adjust_c3d(data)        ((0x00000010&(data))>>4)
#define YC_3D_HI_FREQ_CTRL_get_yc3d_et_hifreq_disable_wise(data)      ((0x00000004&(data))>>2)
#define YC_3D_HI_FREQ_CTRL_get_yc3d_et_hifreq_disable_c2d(data)       ((0x00000002&(data))>>1)
#define YC_3D_HI_FREQ_CTRL_get_yc3d_et_hifreq_disable_c3d(data)       (0x00000001&(data))


#define YC_3D_HI_FREQ_TH                                              0x18019cfc
#define YC_3D_HI_FREQ_TH_reg_addr                                     "0xb8019cfc"
#define YC_3D_HI_FREQ_TH_reg                                          0xb8019cfc
#define YC_3D_HI_FREQ_TH_inst_addr                                    "0x033F"
#define YC_3D_HI_FREQ_TH_inst                                         0x033F
#define YC_3D_HI_FREQ_TH_yc3d_hor_hifreq_th_shift                     (16)
#define YC_3D_HI_FREQ_TH_yc3d_ver_hifreq_th_shift                     (0)
#define YC_3D_HI_FREQ_TH_yc3d_hor_hifreq_th_mask                      (0x01FF0000)
#define YC_3D_HI_FREQ_TH_yc3d_ver_hifreq_th_mask                      (0x000001FF)
#define YC_3D_HI_FREQ_TH_yc3d_hor_hifreq_th(data)                     (0x01FF0000&((data)<<16))
#define YC_3D_HI_FREQ_TH_yc3d_ver_hifreq_th(data)                     (0x000001FF&(data))
#define YC_3D_HI_FREQ_TH_get_yc3d_hor_hifreq_th(data)                 ((0x01FF0000&(data))>>16)
#define YC_3D_HI_FREQ_TH_get_yc3d_ver_hifreq_th(data)                 (0x000001FF&(data))


#define YC_3D_GRID_HI_FREQ_CTRL                                       0x18019d00
#define YC_3D_GRID_HI_FREQ_CTRL_reg_addr                              "0xb8019d00"
#define YC_3D_GRID_HI_FREQ_CTRL_reg                                   0xb8019d00
#define YC_3D_GRID_HI_FREQ_CTRL_inst_addr                             "0x0340"
#define YC_3D_GRID_HI_FREQ_CTRL_inst                                  0x0340
#define YC_3D_GRID_HI_FREQ_CTRL_yc3d_grid_hifreq_sum_up_down_th_shift (20)
#define YC_3D_GRID_HI_FREQ_CTRL_yc3d_grid_hifreq_sad_th_shift         (12)
#define YC_3D_GRID_HI_FREQ_CTRL_yc3d_grid_hifreq_th_shift             (4)
#define YC_3D_GRID_HI_FREQ_CTRL_yc3d_grid_hifreq_sel_shift            (0)
#define YC_3D_GRID_HI_FREQ_CTRL_yc3d_grid_hifreq_sum_up_down_th_mask  (0x0FF00000)
#define YC_3D_GRID_HI_FREQ_CTRL_yc3d_grid_hifreq_sad_th_mask          (0x0003F000)
#define YC_3D_GRID_HI_FREQ_CTRL_yc3d_grid_hifreq_th_mask              (0x00000FF0)
#define YC_3D_GRID_HI_FREQ_CTRL_yc3d_grid_hifreq_sel_mask             (0x00000001)
#define YC_3D_GRID_HI_FREQ_CTRL_yc3d_grid_hifreq_sum_up_down_th(data) (0x0FF00000&((data)<<20))
#define YC_3D_GRID_HI_FREQ_CTRL_yc3d_grid_hifreq_sad_th(data)         (0x0003F000&((data)<<12))
#define YC_3D_GRID_HI_FREQ_CTRL_yc3d_grid_hifreq_th(data)             (0x00000FF0&((data)<<4))
#define YC_3D_GRID_HI_FREQ_CTRL_yc3d_grid_hifreq_sel(data)            (0x00000001&(data))
#define YC_3D_GRID_HI_FREQ_CTRL_get_yc3d_grid_hifreq_sum_up_down_th(data)  ((0x0FF00000&(data))>>20)
#define YC_3D_GRID_HI_FREQ_CTRL_get_yc3d_grid_hifreq_sad_th(data)     ((0x0003F000&(data))>>12)
#define YC_3D_GRID_HI_FREQ_CTRL_get_yc3d_grid_hifreq_th(data)         ((0x00000FF0&(data))>>4)
#define YC_3D_GRID_HI_FREQ_CTRL_get_yc3d_grid_hifreq_sel(data)        (0x00000001&(data))


#define YC_3D_CHI_FREQ_CTRL                                           0x18019d04
#define YC_3D_CHI_FREQ_CTRL_reg_addr                                  "0xb8019d04"
#define YC_3D_CHI_FREQ_CTRL_reg                                       0xb8019d04
#define YC_3D_CHI_FREQ_CTRL_inst_addr                                 "0x0341"
#define YC_3D_CHI_FREQ_CTRL_inst                                      0x0341
#define YC_3D_CHI_FREQ_CTRL_yc3d_et_chifreq_ave_min_shift             (24)
#define YC_3D_CHI_FREQ_CTRL_yc3d_et_hor_chifreq_th_offset_shift       (20)
#define YC_3D_CHI_FREQ_CTRL_yc3d_et_ver_chifreq_th_offset_shift       (16)
#define YC_3D_CHI_FREQ_CTRL_yc3d_et_ver_chifreq_range_shift           (13)
#define YC_3D_CHI_FREQ_CTRL_yc3d_et_hor_chifreq_range_shift           (12)
#define YC_3D_CHI_FREQ_CTRL_yc3d_et_ver_chifreq_ext_range_shift       (8)
#define YC_3D_CHI_FREQ_CTRL_yc3d_et_hor_chifreq_ave_div_shift         (6)
#define YC_3D_CHI_FREQ_CTRL_yc3d_et_ver_chifreq_ave_div_shift         (5)
#define YC_3D_CHI_FREQ_CTRL_yc3d_chifreq_fixth_en_shift               (4)
#define YC_3D_CHI_FREQ_CTRL_yc3d_et_chifreq_disable_wise_shift        (2)
#define YC_3D_CHI_FREQ_CTRL_yc3d_et_chifreq_disable_c2d_shift         (1)
#define YC_3D_CHI_FREQ_CTRL_yc3d_et_chifreq_disable_c3d_shift         (0)
#define YC_3D_CHI_FREQ_CTRL_yc3d_et_chifreq_ave_min_mask              (0x0F000000)
#define YC_3D_CHI_FREQ_CTRL_yc3d_et_hor_chifreq_th_offset_mask        (0x00F00000)
#define YC_3D_CHI_FREQ_CTRL_yc3d_et_ver_chifreq_th_offset_mask        (0x000F0000)
#define YC_3D_CHI_FREQ_CTRL_yc3d_et_ver_chifreq_range_mask            (0x00002000)
#define YC_3D_CHI_FREQ_CTRL_yc3d_et_hor_chifreq_range_mask            (0x00001000)
#define YC_3D_CHI_FREQ_CTRL_yc3d_et_ver_chifreq_ext_range_mask        (0x00000700)
#define YC_3D_CHI_FREQ_CTRL_yc3d_et_hor_chifreq_ave_div_mask          (0x00000040)
#define YC_3D_CHI_FREQ_CTRL_yc3d_et_ver_chifreq_ave_div_mask          (0x00000020)
#define YC_3D_CHI_FREQ_CTRL_yc3d_chifreq_fixth_en_mask                (0x00000010)
#define YC_3D_CHI_FREQ_CTRL_yc3d_et_chifreq_disable_wise_mask         (0x00000004)
#define YC_3D_CHI_FREQ_CTRL_yc3d_et_chifreq_disable_c2d_mask          (0x00000002)
#define YC_3D_CHI_FREQ_CTRL_yc3d_et_chifreq_disable_c3d_mask          (0x00000001)
#define YC_3D_CHI_FREQ_CTRL_yc3d_et_chifreq_ave_min(data)             (0x0F000000&((data)<<24))
#define YC_3D_CHI_FREQ_CTRL_yc3d_et_hor_chifreq_th_offset(data)       (0x00F00000&((data)<<20))
#define YC_3D_CHI_FREQ_CTRL_yc3d_et_ver_chifreq_th_offset(data)       (0x000F0000&((data)<<16))
#define YC_3D_CHI_FREQ_CTRL_yc3d_et_ver_chifreq_range(data)           (0x00002000&((data)<<13))
#define YC_3D_CHI_FREQ_CTRL_yc3d_et_hor_chifreq_range(data)           (0x00001000&((data)<<12))
#define YC_3D_CHI_FREQ_CTRL_yc3d_et_ver_chifreq_ext_range(data)       (0x00000700&((data)<<8))
#define YC_3D_CHI_FREQ_CTRL_yc3d_et_hor_chifreq_ave_div(data)         (0x00000040&((data)<<6))
#define YC_3D_CHI_FREQ_CTRL_yc3d_et_ver_chifreq_ave_div(data)         (0x00000020&((data)<<5))
#define YC_3D_CHI_FREQ_CTRL_yc3d_chifreq_fixth_en(data)               (0x00000010&((data)<<4))
#define YC_3D_CHI_FREQ_CTRL_yc3d_et_chifreq_disable_wise(data)        (0x00000004&((data)<<2))
#define YC_3D_CHI_FREQ_CTRL_yc3d_et_chifreq_disable_c2d(data)         (0x00000002&((data)<<1))
#define YC_3D_CHI_FREQ_CTRL_yc3d_et_chifreq_disable_c3d(data)         (0x00000001&(data))
#define YC_3D_CHI_FREQ_CTRL_get_yc3d_et_chifreq_ave_min(data)         ((0x0F000000&(data))>>24)
#define YC_3D_CHI_FREQ_CTRL_get_yc3d_et_hor_chifreq_th_offset(data)   ((0x00F00000&(data))>>20)
#define YC_3D_CHI_FREQ_CTRL_get_yc3d_et_ver_chifreq_th_offset(data)   ((0x000F0000&(data))>>16)
#define YC_3D_CHI_FREQ_CTRL_get_yc3d_et_ver_chifreq_range(data)       ((0x00002000&(data))>>13)
#define YC_3D_CHI_FREQ_CTRL_get_yc3d_et_hor_chifreq_range(data)       ((0x00001000&(data))>>12)
#define YC_3D_CHI_FREQ_CTRL_get_yc3d_et_ver_chifreq_ext_range(data)   ((0x00000700&(data))>>8)
#define YC_3D_CHI_FREQ_CTRL_get_yc3d_et_hor_chifreq_ave_div(data)     ((0x00000040&(data))>>6)
#define YC_3D_CHI_FREQ_CTRL_get_yc3d_et_ver_chifreq_ave_div(data)     ((0x00000020&(data))>>5)
#define YC_3D_CHI_FREQ_CTRL_get_yc3d_chifreq_fixth_en(data)           ((0x00000010&(data))>>4)
#define YC_3D_CHI_FREQ_CTRL_get_yc3d_et_chifreq_disable_wise(data)    ((0x00000004&(data))>>2)
#define YC_3D_CHI_FREQ_CTRL_get_yc3d_et_chifreq_disable_c2d(data)     ((0x00000002&(data))>>1)
#define YC_3D_CHI_FREQ_CTRL_get_yc3d_et_chifreq_disable_c3d(data)     (0x00000001&(data))


#define YC_3D_CHI_FREQ_TH                                             0x18019d08
#define YC_3D_CHI_FREQ_TH_reg_addr                                    "0xb8019d08"
#define YC_3D_CHI_FREQ_TH_reg                                         0xb8019d08
#define YC_3D_CHI_FREQ_TH_inst_addr                                   "0x0342"
#define YC_3D_CHI_FREQ_TH_inst                                        0x0342
#define YC_3D_CHI_FREQ_TH_yc3d_hor_chifreq_th_shift                   (16)
#define YC_3D_CHI_FREQ_TH_yc3d_ver_chifreq_th_shift                   (0)
#define YC_3D_CHI_FREQ_TH_yc3d_hor_chifreq_th_mask                    (0x01FF0000)
#define YC_3D_CHI_FREQ_TH_yc3d_ver_chifreq_th_mask                    (0x000001FF)
#define YC_3D_CHI_FREQ_TH_yc3d_hor_chifreq_th(data)                   (0x01FF0000&((data)<<16))
#define YC_3D_CHI_FREQ_TH_yc3d_ver_chifreq_th(data)                   (0x000001FF&(data))
#define YC_3D_CHI_FREQ_TH_get_yc3d_hor_chifreq_th(data)               ((0x01FF0000&(data))>>16)
#define YC_3D_CHI_FREQ_TH_get_yc3d_ver_chifreq_th(data)               (0x000001FF&(data))


#define YC_3D_CHI_FREQ_FOR_NONEDGEPAIR                                0x18019d0c
#define YC_3D_CHI_FREQ_FOR_NONEDGEPAIR_reg_addr                       "0xb8019d0c"
#define YC_3D_CHI_FREQ_FOR_NONEDGEPAIR_reg                            0xb8019d0c
#define YC_3D_CHI_FREQ_FOR_NONEDGEPAIR_inst_addr                      "0x0343"
#define YC_3D_CHI_FREQ_FOR_NONEDGEPAIR_inst                           0x0343
#define YC_3D_CHI_FREQ_FOR_NONEDGEPAIR_yc3d_nedge_mode_sel_shift      (30)
#define YC_3D_CHI_FREQ_FOR_NONEDGEPAIR_yc3d_pair_hor_chifreq_th_shift (16)
#define YC_3D_CHI_FREQ_FOR_NONEDGEPAIR_yc3d_pair_chifreq_ave_min_shift  (12)
#define YC_3D_CHI_FREQ_FOR_NONEDGEPAIR_yc3d_et_pair_chifreq_ext_range_shift  (9)
#define YC_3D_CHI_FREQ_FOR_NONEDGEPAIR_yc3d_pair_ver_chifreq_th_shift (0)
#define YC_3D_CHI_FREQ_FOR_NONEDGEPAIR_yc3d_nedge_mode_sel_mask       (0xC0000000)
#define YC_3D_CHI_FREQ_FOR_NONEDGEPAIR_yc3d_pair_hor_chifreq_th_mask  (0x01FF0000)
#define YC_3D_CHI_FREQ_FOR_NONEDGEPAIR_yc3d_pair_chifreq_ave_min_mask (0x0000F000)
#define YC_3D_CHI_FREQ_FOR_NONEDGEPAIR_yc3d_et_pair_chifreq_ext_range_mask  (0x00000E00)
#define YC_3D_CHI_FREQ_FOR_NONEDGEPAIR_yc3d_pair_ver_chifreq_th_mask  (0x000001FF)
#define YC_3D_CHI_FREQ_FOR_NONEDGEPAIR_yc3d_nedge_mode_sel(data)      (0xC0000000&((data)<<30))
#define YC_3D_CHI_FREQ_FOR_NONEDGEPAIR_yc3d_pair_hor_chifreq_th(data) (0x01FF0000&((data)<<16))
#define YC_3D_CHI_FREQ_FOR_NONEDGEPAIR_yc3d_pair_chifreq_ave_min(data)  (0x0000F000&((data)<<12))
#define YC_3D_CHI_FREQ_FOR_NONEDGEPAIR_yc3d_et_pair_chifreq_ext_range(data)  (0x00000E00&((data)<<9))
#define YC_3D_CHI_FREQ_FOR_NONEDGEPAIR_yc3d_pair_ver_chifreq_th(data) (0x000001FF&(data))
#define YC_3D_CHI_FREQ_FOR_NONEDGEPAIR_get_yc3d_nedge_mode_sel(data)  ((0xC0000000&(data))>>30)
#define YC_3D_CHI_FREQ_FOR_NONEDGEPAIR_get_yc3d_pair_hor_chifreq_th(data)  ((0x01FF0000&(data))>>16)
#define YC_3D_CHI_FREQ_FOR_NONEDGEPAIR_get_yc3d_pair_chifreq_ave_min(data)  ((0x0000F000&(data))>>12)
#define YC_3D_CHI_FREQ_FOR_NONEDGEPAIR_get_yc3d_et_pair_chifreq_ext_range(data)  ((0x00000E00&(data))>>9)
#define YC_3D_CHI_FREQ_FOR_NONEDGEPAIR_get_yc3d_pair_ver_chifreq_th(data)  (0x000001FF&(data))


#define YC_3D_FIFD_CTRL_TH                                            0x18019d10
#define YC_3D_FIFD_CTRL_TH_reg_addr                                   "0xb8019d10"
#define YC_3D_FIFD_CTRL_TH_reg                                        0xb8019d10
#define YC_3D_FIFD_CTRL_TH_inst_addr                                  "0x0344"
#define YC_3D_FIFD_CTRL_TH_inst                                       0x0344
#define YC_3D_FIFD_CTRL_TH_yc3d_fifd_iidd_th_offset_shift             (28)
#define YC_3D_FIFD_CTRL_TH_yc3d_fifd_corr_cnt_th_shift                (20)
#define YC_3D_FIFD_CTRL_TH_yc3d_fifd_spa_2d_corr_shift                (16)
#define YC_3D_FIFD_CTRL_TH_yc3d_fifd_ext_num_shift                    (12)
#define YC_3D_FIFD_CTRL_TH_yc3d_fifd_match_cnt_th_shift               (8)
#define YC_3D_FIFD_CTRL_TH_yc3d_fifd_later_style_en_shift             (7)
#define YC_3D_FIFD_CTRL_TH_yc3d_fifd_temp_style_detection_en_shift    (6)
#define YC_3D_FIFD_CTRL_TH_yc3d_fifd_amp_diff_en_shift                (5)
#define YC_3D_FIFD_CTRL_TH_yc3d_fifd_same_style_grid_detection_shift  (4)
#define YC_3D_FIFD_CTRL_TH_yc3d_fifd_grid_content_detection_shift     (3)
#define YC_3D_FIFD_CTRL_TH_yc3d_iidd_en_shift                         (2)
#define YC_3D_FIFD_CTRL_TH_yc3d_et_hifreq_disable_fifd_shift          (1)
#define YC_3D_FIFD_CTRL_TH_yc3d_fifd_en_shift                         (0)
#define YC_3D_FIFD_CTRL_TH_yc3d_fifd_iidd_th_offset_mask              (0x70000000)
#define YC_3D_FIFD_CTRL_TH_yc3d_fifd_corr_cnt_th_mask                 (0x01F00000)
#define YC_3D_FIFD_CTRL_TH_yc3d_fifd_spa_2d_corr_mask                 (0x00010000)
#define YC_3D_FIFD_CTRL_TH_yc3d_fifd_ext_num_mask                     (0x00007000)
#define YC_3D_FIFD_CTRL_TH_yc3d_fifd_match_cnt_th_mask                (0x00000F00)
#define YC_3D_FIFD_CTRL_TH_yc3d_fifd_later_style_en_mask              (0x00000080)
#define YC_3D_FIFD_CTRL_TH_yc3d_fifd_temp_style_detection_en_mask     (0x00000040)
#define YC_3D_FIFD_CTRL_TH_yc3d_fifd_amp_diff_en_mask                 (0x00000020)
#define YC_3D_FIFD_CTRL_TH_yc3d_fifd_same_style_grid_detection_mask   (0x00000010)
#define YC_3D_FIFD_CTRL_TH_yc3d_fifd_grid_content_detection_mask      (0x00000008)
#define YC_3D_FIFD_CTRL_TH_yc3d_iidd_en_mask                          (0x00000004)
#define YC_3D_FIFD_CTRL_TH_yc3d_et_hifreq_disable_fifd_mask           (0x00000002)
#define YC_3D_FIFD_CTRL_TH_yc3d_fifd_en_mask                          (0x00000001)
#define YC_3D_FIFD_CTRL_TH_yc3d_fifd_iidd_th_offset(data)             (0x70000000&((data)<<28))
#define YC_3D_FIFD_CTRL_TH_yc3d_fifd_corr_cnt_th(data)                (0x01F00000&((data)<<20))
#define YC_3D_FIFD_CTRL_TH_yc3d_fifd_spa_2d_corr(data)                (0x00010000&((data)<<16))
#define YC_3D_FIFD_CTRL_TH_yc3d_fifd_ext_num(data)                    (0x00007000&((data)<<12))
#define YC_3D_FIFD_CTRL_TH_yc3d_fifd_match_cnt_th(data)               (0x00000F00&((data)<<8))
#define YC_3D_FIFD_CTRL_TH_yc3d_fifd_later_style_en(data)             (0x00000080&((data)<<7))
#define YC_3D_FIFD_CTRL_TH_yc3d_fifd_temp_style_detection_en(data)    (0x00000040&((data)<<6))
#define YC_3D_FIFD_CTRL_TH_yc3d_fifd_amp_diff_en(data)                (0x00000020&((data)<<5))
#define YC_3D_FIFD_CTRL_TH_yc3d_fifd_same_style_grid_detection(data)  (0x00000010&((data)<<4))
#define YC_3D_FIFD_CTRL_TH_yc3d_fifd_grid_content_detection(data)     (0x00000008&((data)<<3))
#define YC_3D_FIFD_CTRL_TH_yc3d_iidd_en(data)                         (0x00000004&((data)<<2))
#define YC_3D_FIFD_CTRL_TH_yc3d_et_hifreq_disable_fifd(data)          (0x00000002&((data)<<1))
#define YC_3D_FIFD_CTRL_TH_yc3d_fifd_en(data)                         (0x00000001&(data))
#define YC_3D_FIFD_CTRL_TH_get_yc3d_fifd_iidd_th_offset(data)         ((0x70000000&(data))>>28)
#define YC_3D_FIFD_CTRL_TH_get_yc3d_fifd_corr_cnt_th(data)            ((0x01F00000&(data))>>20)
#define YC_3D_FIFD_CTRL_TH_get_yc3d_fifd_spa_2d_corr(data)            ((0x00010000&(data))>>16)
#define YC_3D_FIFD_CTRL_TH_get_yc3d_fifd_ext_num(data)                ((0x00007000&(data))>>12)
#define YC_3D_FIFD_CTRL_TH_get_yc3d_fifd_match_cnt_th(data)           ((0x00000F00&(data))>>8)
#define YC_3D_FIFD_CTRL_TH_get_yc3d_fifd_later_style_en(data)         ((0x00000080&(data))>>7)
#define YC_3D_FIFD_CTRL_TH_get_yc3d_fifd_temp_style_detection_en(data)  ((0x00000040&(data))>>6)
#define YC_3D_FIFD_CTRL_TH_get_yc3d_fifd_amp_diff_en(data)            ((0x00000020&(data))>>5)
#define YC_3D_FIFD_CTRL_TH_get_yc3d_fifd_same_style_grid_detection(data)  ((0x00000010&(data))>>4)
#define YC_3D_FIFD_CTRL_TH_get_yc3d_fifd_grid_content_detection(data) ((0x00000008&(data))>>3)
#define YC_3D_FIFD_CTRL_TH_get_yc3d_iidd_en(data)                     ((0x00000004&(data))>>2)
#define YC_3D_FIFD_CTRL_TH_get_yc3d_et_hifreq_disable_fifd(data)      ((0x00000002&(data))>>1)
#define YC_3D_FIFD_CTRL_TH_get_yc3d_fifd_en(data)                     (0x00000001&(data))


#define YC_3D_FIFD_AMP_DIFF_SAME_STYLE_GRID_TH                        0x18019d14
#define YC_3D_FIFD_AMP_DIFF_SAME_STYLE_GRID_TH_reg_addr               "0xb8019d14"
#define YC_3D_FIFD_AMP_DIFF_SAME_STYLE_GRID_TH_reg                    0xb8019d14
#define YC_3D_FIFD_AMP_DIFF_SAME_STYLE_GRID_TH_inst_addr              "0x0345"
#define YC_3D_FIFD_AMP_DIFF_SAME_STYLE_GRID_TH_inst                   0x0345
#define YC_3D_FIFD_AMP_DIFF_SAME_STYLE_GRID_TH_yc3d_fifd_same_style_grid_th_shift  (16)
#define YC_3D_FIFD_AMP_DIFF_SAME_STYLE_GRID_TH_yc3d_fifd_amp_diff_th_shift  (0)
#define YC_3D_FIFD_AMP_DIFF_SAME_STYLE_GRID_TH_yc3d_fifd_same_style_grid_th_mask  (0x00FF0000)
#define YC_3D_FIFD_AMP_DIFF_SAME_STYLE_GRID_TH_yc3d_fifd_amp_diff_th_mask  (0x000001FF)
#define YC_3D_FIFD_AMP_DIFF_SAME_STYLE_GRID_TH_yc3d_fifd_same_style_grid_th(data)  (0x00FF0000&((data)<<16))
#define YC_3D_FIFD_AMP_DIFF_SAME_STYLE_GRID_TH_yc3d_fifd_amp_diff_th(data)  (0x000001FF&(data))
#define YC_3D_FIFD_AMP_DIFF_SAME_STYLE_GRID_TH_get_yc3d_fifd_same_style_grid_th(data)  ((0x00FF0000&(data))>>16)
#define YC_3D_FIFD_AMP_DIFF_SAME_STYLE_GRID_TH_get_yc3d_fifd_amp_diff_th(data)  (0x000001FF&(data))


#define YC_3D_FIFD_ADAP_AMP_DIFF_TH_CTRL                              0x18019d18
#define YC_3D_FIFD_ADAP_AMP_DIFF_TH_CTRL_reg_addr                     "0xb8019d18"
#define YC_3D_FIFD_ADAP_AMP_DIFF_TH_CTRL_reg                          0xb8019d18
#define YC_3D_FIFD_ADAP_AMP_DIFF_TH_CTRL_inst_addr                    "0x0346"
#define YC_3D_FIFD_ADAP_AMP_DIFF_TH_CTRL_inst                         0x0346
#define YC_3D_FIFD_ADAP_AMP_DIFF_TH_CTRL_yc3d_fifd_amp_diff_th_offset_shift  (24)
#define YC_3D_FIFD_ADAP_AMP_DIFF_TH_CTRL_yc3d_fifd_large_c_th_shift   (16)
#define YC_3D_FIFD_ADAP_AMP_DIFF_TH_CTRL_yc3d_fifd_c_diff_th_shift    (8)
#define YC_3D_FIFD_ADAP_AMP_DIFF_TH_CTRL_yc3d_fifd_left_right_multiple_shift  (4)
#define YC_3D_FIFD_ADAP_AMP_DIFF_TH_CTRL_yc3d_fifd_ver_grid_hifreq_amp_th_en_shift  (1)
#define YC_3D_FIFD_ADAP_AMP_DIFF_TH_CTRL_yc3d_fifd_ada_amp_th_en_shift  (0)
#define YC_3D_FIFD_ADAP_AMP_DIFF_TH_CTRL_yc3d_fifd_amp_diff_th_offset_mask  (0xFF000000)
#define YC_3D_FIFD_ADAP_AMP_DIFF_TH_CTRL_yc3d_fifd_large_c_th_mask    (0x00FF0000)
#define YC_3D_FIFD_ADAP_AMP_DIFF_TH_CTRL_yc3d_fifd_c_diff_th_mask     (0x0000FF00)
#define YC_3D_FIFD_ADAP_AMP_DIFF_TH_CTRL_yc3d_fifd_left_right_multiple_mask  (0x00000070)
#define YC_3D_FIFD_ADAP_AMP_DIFF_TH_CTRL_yc3d_fifd_ver_grid_hifreq_amp_th_en_mask  (0x00000002)
#define YC_3D_FIFD_ADAP_AMP_DIFF_TH_CTRL_yc3d_fifd_ada_amp_th_en_mask (0x00000001)
#define YC_3D_FIFD_ADAP_AMP_DIFF_TH_CTRL_yc3d_fifd_amp_diff_th_offset(data)  (0xFF000000&((data)<<24))
#define YC_3D_FIFD_ADAP_AMP_DIFF_TH_CTRL_yc3d_fifd_large_c_th(data)   (0x00FF0000&((data)<<16))
#define YC_3D_FIFD_ADAP_AMP_DIFF_TH_CTRL_yc3d_fifd_c_diff_th(data)    (0x0000FF00&((data)<<8))
#define YC_3D_FIFD_ADAP_AMP_DIFF_TH_CTRL_yc3d_fifd_left_right_multiple(data)  (0x00000070&((data)<<4))
#define YC_3D_FIFD_ADAP_AMP_DIFF_TH_CTRL_yc3d_fifd_ver_grid_hifreq_amp_th_en(data)  (0x00000002&((data)<<1))
#define YC_3D_FIFD_ADAP_AMP_DIFF_TH_CTRL_yc3d_fifd_ada_amp_th_en(data)  (0x00000001&(data))
#define YC_3D_FIFD_ADAP_AMP_DIFF_TH_CTRL_get_yc3d_fifd_amp_diff_th_offset(data)  ((0xFF000000&(data))>>24)
#define YC_3D_FIFD_ADAP_AMP_DIFF_TH_CTRL_get_yc3d_fifd_large_c_th(data)  ((0x00FF0000&(data))>>16)
#define YC_3D_FIFD_ADAP_AMP_DIFF_TH_CTRL_get_yc3d_fifd_c_diff_th(data)  ((0x0000FF00&(data))>>8)
#define YC_3D_FIFD_ADAP_AMP_DIFF_TH_CTRL_get_yc3d_fifd_left_right_multiple(data)  ((0x00000070&(data))>>4)
#define YC_3D_FIFD_ADAP_AMP_DIFF_TH_CTRL_get_yc3d_fifd_ver_grid_hifreq_amp_th_en(data)  ((0x00000002&(data))>>1)
#define YC_3D_FIFD_ADAP_AMP_DIFF_TH_CTRL_get_yc3d_fifd_ada_amp_th_en(data)  (0x00000001&(data))


#define DUMMY_5                                                       0x18019d1c
#define DUMMY_5_reg_addr                                              "0xb8019d1c"
#define DUMMY_5_reg                                                   0xb8019d1c
#define DUMMY_5_inst_addr                                             "0x0347"
#define DUMMY_5_inst                                                  0x0347
#define DUMMY_5_dummy_5_shift                                         (0)
#define DUMMY_5_dummy_5_mask                                          (0xFFFFFFFF)
#define DUMMY_5_dummy_5(data)                                         (0xFFFFFFFF&(data))
#define DUMMY_5_get_dummy_5(data)                                     (0xFFFFFFFF&(data))


#define DUMMY_6                                                       0x18019d20
#define DUMMY_6_reg_addr                                              "0xb8019d20"
#define DUMMY_6_reg                                                   0xb8019d20
#define DUMMY_6_inst_addr                                             "0x0348"
#define DUMMY_6_inst                                                  0x0348
#define DUMMY_6_dummy_6_shift                                         (0)
#define DUMMY_6_dummy_6_mask                                          (0xFFFFFFFF)
#define DUMMY_6_dummy_6(data)                                         (0xFFFFFFFF&(data))
#define DUMMY_6_get_dummy_6(data)                                     (0xFFFFFFFF&(data))


#define YC_3D_F4_CTRL                                                 0x18019d24
#define YC_3D_F4_CTRL_reg_addr                                        "0xb8019d24"
#define YC_3D_F4_CTRL_reg                                             0xb8019d24
#define YC_3D_F4_CTRL_inst_addr                                       "0x0349"
#define YC_3D_F4_CTRL_inst                                            0x0349
#define YC_3D_F4_CTRL_f4_en_shift                                     (31)
#define YC_3D_F4_CTRL_f4_global_diff_dbg_sftbit_shift                 (28)
#define YC_3D_F4_CTRL_f4_dbg_highfreq_diff_th_shift                   (20)
#define YC_3D_F4_CTRL_f4_dbg_cvbs_amp_th_shift                        (12)
#define YC_3D_F4_CTRL_f4_debug_en_shift                               (8)
#define YC_3D_F4_CTRL_f4_debug_mode_sel_shift                         (0)
#define YC_3D_F4_CTRL_f4_en_mask                                      (0x80000000)
#define YC_3D_F4_CTRL_f4_global_diff_dbg_sftbit_mask                  (0x30000000)
#define YC_3D_F4_CTRL_f4_dbg_highfreq_diff_th_mask                    (0x0FF00000)
#define YC_3D_F4_CTRL_f4_dbg_cvbs_amp_th_mask                         (0x000FF000)
#define YC_3D_F4_CTRL_f4_debug_en_mask                                (0x00000100)
#define YC_3D_F4_CTRL_f4_debug_mode_sel_mask                          (0x0000001F)
#define YC_3D_F4_CTRL_f4_en(data)                                     (0x80000000&((data)<<31))
#define YC_3D_F4_CTRL_f4_global_diff_dbg_sftbit(data)                 (0x30000000&((data)<<28))
#define YC_3D_F4_CTRL_f4_dbg_highfreq_diff_th(data)                   (0x0FF00000&((data)<<20))
#define YC_3D_F4_CTRL_f4_dbg_cvbs_amp_th(data)                        (0x000FF000&((data)<<12))
#define YC_3D_F4_CTRL_f4_debug_en(data)                               (0x00000100&((data)<<8))
#define YC_3D_F4_CTRL_f4_debug_mode_sel(data)                         (0x0000001F&(data))
#define YC_3D_F4_CTRL_get_f4_en(data)                                 ((0x80000000&(data))>>31)
#define YC_3D_F4_CTRL_get_f4_global_diff_dbg_sftbit(data)             ((0x30000000&(data))>>28)
#define YC_3D_F4_CTRL_get_f4_dbg_highfreq_diff_th(data)               ((0x0FF00000&(data))>>20)
#define YC_3D_F4_CTRL_get_f4_dbg_cvbs_amp_th(data)                    ((0x000FF000&(data))>>12)
#define YC_3D_F4_CTRL_get_f4_debug_en(data)                           ((0x00000100&(data))>>8)
#define YC_3D_F4_CTRL_get_f4_debug_mode_sel(data)                     (0x0000001F&(data))


#define YC_3D_F4_SPA_CNT_CVBS_AMP                                     0x18019d28
#define YC_3D_F4_SPA_CNT_CVBS_AMP_reg_addr                            "0xb8019d28"
#define YC_3D_F4_SPA_CNT_CVBS_AMP_reg                                 0xb8019d28
#define YC_3D_F4_SPA_CNT_CVBS_AMP_inst_addr                           "0x034A"
#define YC_3D_F4_SPA_CNT_CVBS_AMP_inst                                0x034A
#define YC_3D_F4_SPA_CNT_CVBS_AMP_cvbs_amp_change_th_shift            (24)
#define YC_3D_F4_SPA_CNT_CVBS_AMP_f4_3d_spatial_cnt_th_5_shift        (16)
#define YC_3D_F4_SPA_CNT_CVBS_AMP_f4_3d_spatial_cnt_th_4_shift        (12)
#define YC_3D_F4_SPA_CNT_CVBS_AMP_f4_3d_spatial_cnt_th_3_shift        (8)
#define YC_3D_F4_SPA_CNT_CVBS_AMP_f4_3d_spatial_cnt_th_2_shift        (4)
#define YC_3D_F4_SPA_CNT_CVBS_AMP_f4_3d_spatial_cnt_th_1_shift        (0)
#define YC_3D_F4_SPA_CNT_CVBS_AMP_cvbs_amp_change_th_mask             (0x7F000000)
#define YC_3D_F4_SPA_CNT_CVBS_AMP_f4_3d_spatial_cnt_th_5_mask         (0x000F0000)
#define YC_3D_F4_SPA_CNT_CVBS_AMP_f4_3d_spatial_cnt_th_4_mask         (0x0000F000)
#define YC_3D_F4_SPA_CNT_CVBS_AMP_f4_3d_spatial_cnt_th_3_mask         (0x00000F00)
#define YC_3D_F4_SPA_CNT_CVBS_AMP_f4_3d_spatial_cnt_th_2_mask         (0x000000F0)
#define YC_3D_F4_SPA_CNT_CVBS_AMP_f4_3d_spatial_cnt_th_1_mask         (0x0000000F)
#define YC_3D_F4_SPA_CNT_CVBS_AMP_cvbs_amp_change_th(data)            (0x7F000000&((data)<<24))
#define YC_3D_F4_SPA_CNT_CVBS_AMP_f4_3d_spatial_cnt_th_5(data)        (0x000F0000&((data)<<16))
#define YC_3D_F4_SPA_CNT_CVBS_AMP_f4_3d_spatial_cnt_th_4(data)        (0x0000F000&((data)<<12))
#define YC_3D_F4_SPA_CNT_CVBS_AMP_f4_3d_spatial_cnt_th_3(data)        (0x00000F00&((data)<<8))
#define YC_3D_F4_SPA_CNT_CVBS_AMP_f4_3d_spatial_cnt_th_2(data)        (0x000000F0&((data)<<4))
#define YC_3D_F4_SPA_CNT_CVBS_AMP_f4_3d_spatial_cnt_th_1(data)        (0x0000000F&(data))
#define YC_3D_F4_SPA_CNT_CVBS_AMP_get_cvbs_amp_change_th(data)        ((0x7F000000&(data))>>24)
#define YC_3D_F4_SPA_CNT_CVBS_AMP_get_f4_3d_spatial_cnt_th_5(data)    ((0x000F0000&(data))>>16)
#define YC_3D_F4_SPA_CNT_CVBS_AMP_get_f4_3d_spatial_cnt_th_4(data)    ((0x0000F000&(data))>>12)
#define YC_3D_F4_SPA_CNT_CVBS_AMP_get_f4_3d_spatial_cnt_th_3(data)    ((0x00000F00&(data))>>8)
#define YC_3D_F4_SPA_CNT_CVBS_AMP_get_f4_3d_spatial_cnt_th_2(data)    ((0x000000F0&(data))>>4)
#define YC_3D_F4_SPA_CNT_CVBS_AMP_get_f4_3d_spatial_cnt_th_1(data)    (0x0000000F&(data))


#define YC_3D_F4_HV_EDGE_1                                            0x18019d2c
#define YC_3D_F4_HV_EDGE_1_reg_addr                                   "0xb8019d2c"
#define YC_3D_F4_HV_EDGE_1_reg                                        0xb8019d2c
#define YC_3D_F4_HV_EDGE_1_inst_addr                                  "0x034B"
#define YC_3D_F4_HV_EDGE_1_inst                                       0x034B
#define YC_3D_F4_HV_EDGE_1_hv_cvbs_diff_large_multiple_th_shift       (20)
#define YC_3D_F4_HV_EDGE_1_hv_diff_large_multiple_th_shift            (16)
#define YC_3D_F4_HV_EDGE_1_hv_diff_large_offset_th_shift              (8)
#define YC_3D_F4_HV_EDGE_1_hv_local_diff_comp_ratio_shift             (4)
#define YC_3D_F4_HV_EDGE_1_hv_diff_tolerance_shift                    (0)
#define YC_3D_F4_HV_EDGE_1_hv_cvbs_diff_large_multiple_th_mask        (0x00700000)
#define YC_3D_F4_HV_EDGE_1_hv_diff_large_multiple_th_mask             (0x00070000)
#define YC_3D_F4_HV_EDGE_1_hv_diff_large_offset_th_mask               (0x00003F00)
#define YC_3D_F4_HV_EDGE_1_hv_local_diff_comp_ratio_mask              (0x00000070)
#define YC_3D_F4_HV_EDGE_1_hv_diff_tolerance_mask                     (0x0000000F)
#define YC_3D_F4_HV_EDGE_1_hv_cvbs_diff_large_multiple_th(data)       (0x00700000&((data)<<20))
#define YC_3D_F4_HV_EDGE_1_hv_diff_large_multiple_th(data)            (0x00070000&((data)<<16))
#define YC_3D_F4_HV_EDGE_1_hv_diff_large_offset_th(data)              (0x00003F00&((data)<<8))
#define YC_3D_F4_HV_EDGE_1_hv_local_diff_comp_ratio(data)             (0x00000070&((data)<<4))
#define YC_3D_F4_HV_EDGE_1_hv_diff_tolerance(data)                    (0x0000000F&(data))
#define YC_3D_F4_HV_EDGE_1_get_hv_cvbs_diff_large_multiple_th(data)   ((0x00700000&(data))>>20)
#define YC_3D_F4_HV_EDGE_1_get_hv_diff_large_multiple_th(data)        ((0x00070000&(data))>>16)
#define YC_3D_F4_HV_EDGE_1_get_hv_diff_large_offset_th(data)          ((0x00003F00&(data))>>8)
#define YC_3D_F4_HV_EDGE_1_get_hv_local_diff_comp_ratio(data)         ((0x00000070&(data))>>4)
#define YC_3D_F4_HV_EDGE_1_get_hv_diff_tolerance(data)                (0x0000000F&(data))


#define YC_3D_F4_HV_EDGE_2                                            0x18019d30
#define YC_3D_F4_HV_EDGE_2_reg_addr                                   "0xb8019d30"
#define YC_3D_F4_HV_EDGE_2_reg                                        0xb8019d30
#define YC_3D_F4_HV_EDGE_2_inst_addr                                  "0x034C"
#define YC_3D_F4_HV_EDGE_2_inst                                       0x034C
#define YC_3D_F4_HV_EDGE_2_h_diff_normalize_en_shift                  (12)
#define YC_3D_F4_HV_EDGE_2_hv_edge_c_diff_small_th_shift              (4)
#define YC_3D_F4_HV_EDGE_2_hv_edge_c_diff_small_en_shift              (0)
#define YC_3D_F4_HV_EDGE_2_h_diff_normalize_en_mask                   (0x00001000)
#define YC_3D_F4_HV_EDGE_2_hv_edge_c_diff_small_th_mask               (0x000001F0)
#define YC_3D_F4_HV_EDGE_2_hv_edge_c_diff_small_en_mask               (0x00000001)
#define YC_3D_F4_HV_EDGE_2_h_diff_normalize_en(data)                  (0x00001000&((data)<<12))
#define YC_3D_F4_HV_EDGE_2_hv_edge_c_diff_small_th(data)              (0x000001F0&((data)<<4))
#define YC_3D_F4_HV_EDGE_2_hv_edge_c_diff_small_en(data)              (0x00000001&(data))
#define YC_3D_F4_HV_EDGE_2_get_h_diff_normalize_en(data)              ((0x00001000&(data))>>12)
#define YC_3D_F4_HV_EDGE_2_get_hv_edge_c_diff_small_th(data)          ((0x000001F0&(data))>>4)
#define YC_3D_F4_HV_EDGE_2_get_hv_edge_c_diff_small_en(data)          (0x00000001&(data))


#define YC_3D_F4_HIFREQ_DET                                           0x18019d34
#define YC_3D_F4_HIFREQ_DET_reg_addr                                  "0xb8019d34"
#define YC_3D_F4_HIFREQ_DET_reg                                       0xb8019d34
#define YC_3D_F4_HIFREQ_DET_inst_addr                                 "0x034D"
#define YC_3D_F4_HIFREQ_DET_inst                                      0x034D
#define YC_3D_F4_HIFREQ_DET_f4_fill_hole_neightbor_diff_th_shift      (4)
#define YC_3D_F4_HIFREQ_DET_f4_hor_chifreq_range_shift                (3)
#define YC_3D_F4_HIFREQ_DET_f4_ver_chifreq_range_shift                (2)
#define YC_3D_F4_HIFREQ_DET_f4_hor_hifreq_range_shift                 (1)
#define YC_3D_F4_HIFREQ_DET_f4_ver_hifreq_usepalmode_shift            (0)
#define YC_3D_F4_HIFREQ_DET_f4_fill_hole_neightbor_diff_th_mask       (0x000003F0)
#define YC_3D_F4_HIFREQ_DET_f4_hor_chifreq_range_mask                 (0x00000008)
#define YC_3D_F4_HIFREQ_DET_f4_ver_chifreq_range_mask                 (0x00000004)
#define YC_3D_F4_HIFREQ_DET_f4_hor_hifreq_range_mask                  (0x00000002)
#define YC_3D_F4_HIFREQ_DET_f4_ver_hifreq_usepalmode_mask             (0x00000001)
#define YC_3D_F4_HIFREQ_DET_f4_fill_hole_neightbor_diff_th(data)      (0x000003F0&((data)<<4))
#define YC_3D_F4_HIFREQ_DET_f4_hor_chifreq_range(data)                (0x00000008&((data)<<3))
#define YC_3D_F4_HIFREQ_DET_f4_ver_chifreq_range(data)                (0x00000004&((data)<<2))
#define YC_3D_F4_HIFREQ_DET_f4_hor_hifreq_range(data)                 (0x00000002&((data)<<1))
#define YC_3D_F4_HIFREQ_DET_f4_ver_hifreq_usepalmode(data)            (0x00000001&(data))
#define YC_3D_F4_HIFREQ_DET_get_f4_fill_hole_neightbor_diff_th(data)  ((0x000003F0&(data))>>4)
#define YC_3D_F4_HIFREQ_DET_get_f4_hor_chifreq_range(data)            ((0x00000008&(data))>>3)
#define YC_3D_F4_HIFREQ_DET_get_f4_ver_chifreq_range(data)            ((0x00000004&(data))>>2)
#define YC_3D_F4_HIFREQ_DET_get_f4_hor_hifreq_range(data)             ((0x00000002&(data))>>1)
#define YC_3D_F4_HIFREQ_DET_get_f4_ver_hifreq_usepalmode(data)        (0x00000001&(data))


#define YC_3D_F4_DC_COMPARE                                           0x18019d38
#define YC_3D_F4_DC_COMPARE_reg_addr                                  "0xb8019d38"
#define YC_3D_F4_DC_COMPARE_reg                                       0xb8019d38
#define YC_3D_F4_DC_COMPARE_inst_addr                                 "0x034E"
#define YC_3D_F4_DC_COMPARE_inst                                      0x034E
#define YC_3D_F4_DC_COMPARE_dc_level_change_th_multiple_shift         (8)
#define YC_3D_F4_DC_COMPARE_dc_level_change_th_base_shift             (0)
#define YC_3D_F4_DC_COMPARE_dc_level_change_th_multiple_mask          (0x00000F00)
#define YC_3D_F4_DC_COMPARE_dc_level_change_th_base_mask              (0x0000003F)
#define YC_3D_F4_DC_COMPARE_dc_level_change_th_multiple(data)         (0x00000F00&((data)<<8))
#define YC_3D_F4_DC_COMPARE_dc_level_change_th_base(data)             (0x0000003F&(data))
#define YC_3D_F4_DC_COMPARE_get_dc_level_change_th_multiple(data)     ((0x00000F00&(data))>>8)
#define YC_3D_F4_DC_COMPARE_get_dc_level_change_th_base(data)         (0x0000003F&(data))


#define YC_3D_F4_PAL_ERR_COM_1                                        0x18019d3c
#define YC_3D_F4_PAL_ERR_COM_1_reg_addr                               "0xb8019d3c"
#define YC_3D_F4_PAL_ERR_COM_1_reg                                    0xb8019d3c
#define YC_3D_F4_PAL_ERR_COM_1_inst_addr                              "0x034F"
#define YC_3D_F4_PAL_ERR_COM_1_inst                                   0x034F
#define YC_3D_F4_PAL_ERR_COM_1_similary_th_base_shift                 (24)
#define YC_3D_F4_PAL_ERR_COM_1_similary_th_multiple_shift             (16)
#define YC_3D_F4_PAL_ERR_COM_1_palerr_accu_tolerance_shift            (12)
#define YC_3D_F4_PAL_ERR_COM_1_palerr_hifreq_diff_large_th_shift      (4)
#define YC_3D_F4_PAL_ERR_COM_1_pal_error_detect_en_shift              (0)
#define YC_3D_F4_PAL_ERR_COM_1_similary_th_base_mask                  (0x3F000000)
#define YC_3D_F4_PAL_ERR_COM_1_similary_th_multiple_mask              (0x001F0000)
#define YC_3D_F4_PAL_ERR_COM_1_palerr_accu_tolerance_mask             (0x0000F000)
#define YC_3D_F4_PAL_ERR_COM_1_palerr_hifreq_diff_large_th_mask       (0x000003F0)
#define YC_3D_F4_PAL_ERR_COM_1_pal_error_detect_en_mask               (0x00000001)
#define YC_3D_F4_PAL_ERR_COM_1_similary_th_base(data)                 (0x3F000000&((data)<<24))
#define YC_3D_F4_PAL_ERR_COM_1_similary_th_multiple(data)             (0x001F0000&((data)<<16))
#define YC_3D_F4_PAL_ERR_COM_1_palerr_accu_tolerance(data)            (0x0000F000&((data)<<12))
#define YC_3D_F4_PAL_ERR_COM_1_palerr_hifreq_diff_large_th(data)      (0x000003F0&((data)<<4))
#define YC_3D_F4_PAL_ERR_COM_1_pal_error_detect_en(data)              (0x00000001&(data))
#define YC_3D_F4_PAL_ERR_COM_1_get_similary_th_base(data)             ((0x3F000000&(data))>>24)
#define YC_3D_F4_PAL_ERR_COM_1_get_similary_th_multiple(data)         ((0x001F0000&(data))>>16)
#define YC_3D_F4_PAL_ERR_COM_1_get_palerr_accu_tolerance(data)        ((0x0000F000&(data))>>12)
#define YC_3D_F4_PAL_ERR_COM_1_get_palerr_hifreq_diff_large_th(data)  ((0x000003F0&(data))>>4)
#define YC_3D_F4_PAL_ERR_COM_1_get_pal_error_detect_en(data)          (0x00000001&(data))


#define YC_3D_F4_PAL_ERR_COM_2                                        0x18019d40
#define YC_3D_F4_PAL_ERR_COM_2_reg_addr                               "0xb8019d40"
#define YC_3D_F4_PAL_ERR_COM_2_reg                                    0xb8019d40
#define YC_3D_F4_PAL_ERR_COM_2_inst_addr                              "0x0350"
#define YC_3D_F4_PAL_ERR_COM_2_inst                                   0x0350
#define YC_3D_F4_PAL_ERR_COM_2_diff_of_spd_small_th_base_shift        (24)
#define YC_3D_F4_PAL_ERR_COM_2_diff_of_spd_small_th_multiple_shift    (16)
#define YC_3D_F4_PAL_ERR_COM_2_massive_palmode_error_multiple_th_shift  (8)
#define YC_3D_F4_PAL_ERR_COM_2_massive_palmode_error_large_th_shift   (0)
#define YC_3D_F4_PAL_ERR_COM_2_diff_of_spd_small_th_base_mask         (0x1F000000)
#define YC_3D_F4_PAL_ERR_COM_2_diff_of_spd_small_th_multiple_mask     (0x001F0000)
#define YC_3D_F4_PAL_ERR_COM_2_massive_palmode_error_multiple_th_mask (0x00001F00)
#define YC_3D_F4_PAL_ERR_COM_2_massive_palmode_error_large_th_mask    (0x0000007F)
#define YC_3D_F4_PAL_ERR_COM_2_diff_of_spd_small_th_base(data)        (0x1F000000&((data)<<24))
#define YC_3D_F4_PAL_ERR_COM_2_diff_of_spd_small_th_multiple(data)    (0x001F0000&((data)<<16))
#define YC_3D_F4_PAL_ERR_COM_2_massive_palmode_error_multiple_th(data)  (0x00001F00&((data)<<8))
#define YC_3D_F4_PAL_ERR_COM_2_massive_palmode_error_large_th(data)   (0x0000007F&(data))
#define YC_3D_F4_PAL_ERR_COM_2_get_diff_of_spd_small_th_base(data)    ((0x1F000000&(data))>>24)
#define YC_3D_F4_PAL_ERR_COM_2_get_diff_of_spd_small_th_multiple(data)  ((0x001F0000&(data))>>16)
#define YC_3D_F4_PAL_ERR_COM_2_get_massive_palmode_error_multiple_th(data)  ((0x00001F00&(data))>>8)
#define YC_3D_F4_PAL_ERR_COM_2_get_massive_palmode_error_large_th(data)  (0x0000007F&(data))


#define YC_3D_F4_PAL_ERR_COM_3                                        0x18019d44
#define YC_3D_F4_PAL_ERR_COM_3_reg_addr                               "0xb8019d44"
#define YC_3D_F4_PAL_ERR_COM_3_reg                                    0xb8019d44
#define YC_3D_F4_PAL_ERR_COM_3_inst_addr                              "0x0351"
#define YC_3D_F4_PAL_ERR_COM_3_inst                                   0x0351
#define YC_3D_F4_PAL_ERR_COM_3_large_hor_spd_th_shift                 (0)
#define YC_3D_F4_PAL_ERR_COM_3_large_hor_spd_th_mask                  (0x0000007F)
#define YC_3D_F4_PAL_ERR_COM_3_large_hor_spd_th(data)                 (0x0000007F&(data))
#define YC_3D_F4_PAL_ERR_COM_3_get_large_hor_spd_th(data)             (0x0000007F&(data))


#define YC_3D_F4_STILL_VECTOR_1                                       0x18019d48
#define YC_3D_F4_STILL_VECTOR_1_reg_addr                              "0xb8019d48"
#define YC_3D_F4_STILL_VECTOR_1_reg                                   0xb8019d48
#define YC_3D_F4_STILL_VECTOR_1_inst_addr                             "0x0352"
#define YC_3D_F4_STILL_VECTOR_1_inst                                  0x0352
#define YC_3D_F4_STILL_VECTOR_1_sv_avg_dynamic_en_shift               (31)
#define YC_3D_F4_STILL_VECTOR_1_sv_vector_fid_match_cnt_th_shift      (20)
#define YC_3D_F4_STILL_VECTOR_1_sv_vector_fid_offset_shift            (16)
#define YC_3D_F4_STILL_VECTOR_1_sv_vector_large_cnt_th_shift          (8)
#define YC_3D_F4_STILL_VECTOR_1_sv_vector_large_th_shift              (0)
#define YC_3D_F4_STILL_VECTOR_1_sv_avg_dynamic_en_mask                (0x80000000)
#define YC_3D_F4_STILL_VECTOR_1_sv_vector_fid_match_cnt_th_mask       (0x01F00000)
#define YC_3D_F4_STILL_VECTOR_1_sv_vector_fid_offset_mask             (0x000F0000)
#define YC_3D_F4_STILL_VECTOR_1_sv_vector_large_cnt_th_mask           (0x00001F00)
#define YC_3D_F4_STILL_VECTOR_1_sv_vector_large_th_mask               (0x0000001F)
#define YC_3D_F4_STILL_VECTOR_1_sv_avg_dynamic_en(data)               (0x80000000&((data)<<31))
#define YC_3D_F4_STILL_VECTOR_1_sv_vector_fid_match_cnt_th(data)      (0x01F00000&((data)<<20))
#define YC_3D_F4_STILL_VECTOR_1_sv_vector_fid_offset(data)            (0x000F0000&((data)<<16))
#define YC_3D_F4_STILL_VECTOR_1_sv_vector_large_cnt_th(data)          (0x00001F00&((data)<<8))
#define YC_3D_F4_STILL_VECTOR_1_sv_vector_large_th(data)              (0x0000001F&(data))
#define YC_3D_F4_STILL_VECTOR_1_get_sv_avg_dynamic_en(data)           ((0x80000000&(data))>>31)
#define YC_3D_F4_STILL_VECTOR_1_get_sv_vector_fid_match_cnt_th(data)  ((0x01F00000&(data))>>20)
#define YC_3D_F4_STILL_VECTOR_1_get_sv_vector_fid_offset(data)        ((0x000F0000&(data))>>16)
#define YC_3D_F4_STILL_VECTOR_1_get_sv_vector_large_cnt_th(data)      ((0x00001F00&(data))>>8)
#define YC_3D_F4_STILL_VECTOR_1_get_sv_vector_large_th(data)          (0x0000001F&(data))


#define YC_3D_F4_STILL_VECTOR_2                                       0x18019d4c
#define YC_3D_F4_STILL_VECTOR_2_reg_addr                              "0xb8019d4c"
#define YC_3D_F4_STILL_VECTOR_2_reg                                   0xb8019d4c
#define YC_3D_F4_STILL_VECTOR_2_inst_addr                             "0x0353"
#define YC_3D_F4_STILL_VECTOR_2_inst                                  0x0353
#define YC_3D_F4_STILL_VECTOR_2_sv_self_diff_small_th_shift           (0)
#define YC_3D_F4_STILL_VECTOR_2_sv_self_diff_small_th_mask            (0x0000007F)
#define YC_3D_F4_STILL_VECTOR_2_sv_self_diff_small_th(data)           (0x0000007F&(data))
#define YC_3D_F4_STILL_VECTOR_2_get_sv_self_diff_small_th(data)       (0x0000007F&(data))


#define YC_3D_F4_STILL_GRAY_HIFREQ_1                                  0x18019d50
#define YC_3D_F4_STILL_GRAY_HIFREQ_1_reg_addr                         "0xb8019d50"
#define YC_3D_F4_STILL_GRAY_HIFREQ_1_reg                              0xb8019d50
#define YC_3D_F4_STILL_GRAY_HIFREQ_1_inst_addr                        "0x0354"
#define YC_3D_F4_STILL_GRAY_HIFREQ_1_inst                             0x0354
#define YC_3D_F4_STILL_GRAY_HIFREQ_1_sghf_inter_diff_th_shift         (12)
#define YC_3D_F4_STILL_GRAY_HIFREQ_1_sghf_global_diff_small_th_shift  (4)
#define YC_3D_F4_STILL_GRAY_HIFREQ_1_sghf_longtime_en_shift           (0)
#define YC_3D_F4_STILL_GRAY_HIFREQ_1_sghf_inter_diff_th_mask          (0x0007F000)
#define YC_3D_F4_STILL_GRAY_HIFREQ_1_sghf_global_diff_small_th_mask   (0x00000FF0)
#define YC_3D_F4_STILL_GRAY_HIFREQ_1_sghf_longtime_en_mask            (0x00000001)
#define YC_3D_F4_STILL_GRAY_HIFREQ_1_sghf_inter_diff_th(data)         (0x0007F000&((data)<<12))
#define YC_3D_F4_STILL_GRAY_HIFREQ_1_sghf_global_diff_small_th(data)  (0x00000FF0&((data)<<4))
#define YC_3D_F4_STILL_GRAY_HIFREQ_1_sghf_longtime_en(data)           (0x00000001&(data))
#define YC_3D_F4_STILL_GRAY_HIFREQ_1_get_sghf_inter_diff_th(data)     ((0x0007F000&(data))>>12)
#define YC_3D_F4_STILL_GRAY_HIFREQ_1_get_sghf_global_diff_small_th(data)  ((0x00000FF0&(data))>>4)
#define YC_3D_F4_STILL_GRAY_HIFREQ_1_get_sghf_longtime_en(data)       (0x00000001&(data))


#define YC_3D_F4_STILL_GRAY_HIFREQ_2                                  0x18019d54
#define YC_3D_F4_STILL_GRAY_HIFREQ_2_reg_addr                         "0xb8019d54"
#define YC_3D_F4_STILL_GRAY_HIFREQ_2_reg                              0xb8019d54
#define YC_3D_F4_STILL_GRAY_HIFREQ_2_inst_addr                        "0x0355"
#define YC_3D_F4_STILL_GRAY_HIFREQ_2_inst                             0x0355
#define YC_3D_F4_STILL_GRAY_HIFREQ_2_sghf_avg_dynamic_en_shift        (31)
#define YC_3D_F4_STILL_GRAY_HIFREQ_2_sghf_vector_fid_match_cnt_th_shift  (20)
#define YC_3D_F4_STILL_GRAY_HIFREQ_2_sghf_vector_fid_offset_shift     (16)
#define YC_3D_F4_STILL_GRAY_HIFREQ_2_sghf_vector_large_cnt_th_shift   (8)
#define YC_3D_F4_STILL_GRAY_HIFREQ_2_sghf_vector_large_th_shift       (0)
#define YC_3D_F4_STILL_GRAY_HIFREQ_2_sghf_avg_dynamic_en_mask         (0x80000000)
#define YC_3D_F4_STILL_GRAY_HIFREQ_2_sghf_vector_fid_match_cnt_th_mask  (0x01F00000)
#define YC_3D_F4_STILL_GRAY_HIFREQ_2_sghf_vector_fid_offset_mask      (0x000F0000)
#define YC_3D_F4_STILL_GRAY_HIFREQ_2_sghf_vector_large_cnt_th_mask    (0x00001F00)
#define YC_3D_F4_STILL_GRAY_HIFREQ_2_sghf_vector_large_th_mask        (0x0000001F)
#define YC_3D_F4_STILL_GRAY_HIFREQ_2_sghf_avg_dynamic_en(data)        (0x80000000&((data)<<31))
#define YC_3D_F4_STILL_GRAY_HIFREQ_2_sghf_vector_fid_match_cnt_th(data)  (0x01F00000&((data)<<20))
#define YC_3D_F4_STILL_GRAY_HIFREQ_2_sghf_vector_fid_offset(data)     (0x000F0000&((data)<<16))
#define YC_3D_F4_STILL_GRAY_HIFREQ_2_sghf_vector_large_cnt_th(data)   (0x00001F00&((data)<<8))
#define YC_3D_F4_STILL_GRAY_HIFREQ_2_sghf_vector_large_th(data)       (0x0000001F&(data))
#define YC_3D_F4_STILL_GRAY_HIFREQ_2_get_sghf_avg_dynamic_en(data)    ((0x80000000&(data))>>31)
#define YC_3D_F4_STILL_GRAY_HIFREQ_2_get_sghf_vector_fid_match_cnt_th(data)  ((0x01F00000&(data))>>20)
#define YC_3D_F4_STILL_GRAY_HIFREQ_2_get_sghf_vector_fid_offset(data) ((0x000F0000&(data))>>16)
#define YC_3D_F4_STILL_GRAY_HIFREQ_2_get_sghf_vector_large_cnt_th(data)  ((0x00001F00&(data))>>8)
#define YC_3D_F4_STILL_GRAY_HIFREQ_2_get_sghf_vector_large_th(data)   (0x0000001F&(data))


#define YC_3D_F4_PAIR_TH_MULTIPLE_1                                   0x18019d58
#define YC_3D_F4_PAIR_TH_MULTIPLE_1_reg_addr                          "0xb8019d58"
#define YC_3D_F4_PAIR_TH_MULTIPLE_1_reg                               0xb8019d58
#define YC_3D_F4_PAIR_TH_MULTIPLE_1_inst_addr                         "0x0356"
#define YC_3D_F4_PAIR_TH_MULTIPLE_1_inst                              0x0356
#define YC_3D_F4_PAIR_TH_MULTIPLE_1_diff_th_multiple_140_shift        (24)
#define YC_3D_F4_PAIR_TH_MULTIPLE_1_diff_th_multiple_160_shift        (16)
#define YC_3D_F4_PAIR_TH_MULTIPLE_1_diff_th_multiple_180_shift        (8)
#define YC_3D_F4_PAIR_TH_MULTIPLE_1_diff_th_multiple_200_shift        (0)
#define YC_3D_F4_PAIR_TH_MULTIPLE_1_diff_th_multiple_140_mask         (0x1F000000)
#define YC_3D_F4_PAIR_TH_MULTIPLE_1_diff_th_multiple_160_mask         (0x001F0000)
#define YC_3D_F4_PAIR_TH_MULTIPLE_1_diff_th_multiple_180_mask         (0x00001F00)
#define YC_3D_F4_PAIR_TH_MULTIPLE_1_diff_th_multiple_200_mask         (0x0000001F)
#define YC_3D_F4_PAIR_TH_MULTIPLE_1_diff_th_multiple_140(data)        (0x1F000000&((data)<<24))
#define YC_3D_F4_PAIR_TH_MULTIPLE_1_diff_th_multiple_160(data)        (0x001F0000&((data)<<16))
#define YC_3D_F4_PAIR_TH_MULTIPLE_1_diff_th_multiple_180(data)        (0x00001F00&((data)<<8))
#define YC_3D_F4_PAIR_TH_MULTIPLE_1_diff_th_multiple_200(data)        (0x0000001F&(data))
#define YC_3D_F4_PAIR_TH_MULTIPLE_1_get_diff_th_multiple_140(data)    ((0x1F000000&(data))>>24)
#define YC_3D_F4_PAIR_TH_MULTIPLE_1_get_diff_th_multiple_160(data)    ((0x001F0000&(data))>>16)
#define YC_3D_F4_PAIR_TH_MULTIPLE_1_get_diff_th_multiple_180(data)    ((0x00001F00&(data))>>8)
#define YC_3D_F4_PAIR_TH_MULTIPLE_1_get_diff_th_multiple_200(data)    (0x0000001F&(data))


#define YC_3D_F4_PAIR_TH_MULTIPLE_2                                   0x18019d5c
#define YC_3D_F4_PAIR_TH_MULTIPLE_2_reg_addr                          "0xb8019d5c"
#define YC_3D_F4_PAIR_TH_MULTIPLE_2_reg                               0xb8019d5c
#define YC_3D_F4_PAIR_TH_MULTIPLE_2_inst_addr                         "0x0357"
#define YC_3D_F4_PAIR_TH_MULTIPLE_2_inst                              0x0357
#define YC_3D_F4_PAIR_TH_MULTIPLE_2_diff_th_multiple_60_shift         (24)
#define YC_3D_F4_PAIR_TH_MULTIPLE_2_diff_th_multiple_80_shift         (16)
#define YC_3D_F4_PAIR_TH_MULTIPLE_2_diff_th_multiple_100_shift        (8)
#define YC_3D_F4_PAIR_TH_MULTIPLE_2_diff_th_multiple_120_shift        (0)
#define YC_3D_F4_PAIR_TH_MULTIPLE_2_diff_th_multiple_60_mask          (0x1F000000)
#define YC_3D_F4_PAIR_TH_MULTIPLE_2_diff_th_multiple_80_mask          (0x001F0000)
#define YC_3D_F4_PAIR_TH_MULTIPLE_2_diff_th_multiple_100_mask         (0x00001F00)
#define YC_3D_F4_PAIR_TH_MULTIPLE_2_diff_th_multiple_120_mask         (0x0000001F)
#define YC_3D_F4_PAIR_TH_MULTIPLE_2_diff_th_multiple_60(data)         (0x1F000000&((data)<<24))
#define YC_3D_F4_PAIR_TH_MULTIPLE_2_diff_th_multiple_80(data)         (0x001F0000&((data)<<16))
#define YC_3D_F4_PAIR_TH_MULTIPLE_2_diff_th_multiple_100(data)        (0x00001F00&((data)<<8))
#define YC_3D_F4_PAIR_TH_MULTIPLE_2_diff_th_multiple_120(data)        (0x0000001F&(data))
#define YC_3D_F4_PAIR_TH_MULTIPLE_2_get_diff_th_multiple_60(data)     ((0x1F000000&(data))>>24)
#define YC_3D_F4_PAIR_TH_MULTIPLE_2_get_diff_th_multiple_80(data)     ((0x001F0000&(data))>>16)
#define YC_3D_F4_PAIR_TH_MULTIPLE_2_get_diff_th_multiple_100(data)    ((0x00001F00&(data))>>8)
#define YC_3D_F4_PAIR_TH_MULTIPLE_2_get_diff_th_multiple_120(data)    (0x0000001F&(data))


#define YC_3D_F4_PAIR_TH_MULTIPLE_3                                   0x18019d60
#define YC_3D_F4_PAIR_TH_MULTIPLE_3_reg_addr                          "0xb8019d60"
#define YC_3D_F4_PAIR_TH_MULTIPLE_3_reg                               0xb8019d60
#define YC_3D_F4_PAIR_TH_MULTIPLE_3_inst_addr                         "0x0358"
#define YC_3D_F4_PAIR_TH_MULTIPLE_3_inst                              0x0358
#define YC_3D_F4_PAIR_TH_MULTIPLE_3_diff_th_multiple_0_shift          (24)
#define YC_3D_F4_PAIR_TH_MULTIPLE_3_diff_th_multiple_10_shift         (16)
#define YC_3D_F4_PAIR_TH_MULTIPLE_3_diff_th_multiple_20_shift         (8)
#define YC_3D_F4_PAIR_TH_MULTIPLE_3_diff_th_multiple_40_shift         (0)
#define YC_3D_F4_PAIR_TH_MULTIPLE_3_diff_th_multiple_0_mask           (0x1F000000)
#define YC_3D_F4_PAIR_TH_MULTIPLE_3_diff_th_multiple_10_mask          (0x001F0000)
#define YC_3D_F4_PAIR_TH_MULTIPLE_3_diff_th_multiple_20_mask          (0x00001F00)
#define YC_3D_F4_PAIR_TH_MULTIPLE_3_diff_th_multiple_40_mask          (0x0000001F)
#define YC_3D_F4_PAIR_TH_MULTIPLE_3_diff_th_multiple_0(data)          (0x1F000000&((data)<<24))
#define YC_3D_F4_PAIR_TH_MULTIPLE_3_diff_th_multiple_10(data)         (0x001F0000&((data)<<16))
#define YC_3D_F4_PAIR_TH_MULTIPLE_3_diff_th_multiple_20(data)         (0x00001F00&((data)<<8))
#define YC_3D_F4_PAIR_TH_MULTIPLE_3_diff_th_multiple_40(data)         (0x0000001F&(data))
#define YC_3D_F4_PAIR_TH_MULTIPLE_3_get_diff_th_multiple_0(data)      ((0x1F000000&(data))>>24)
#define YC_3D_F4_PAIR_TH_MULTIPLE_3_get_diff_th_multiple_10(data)     ((0x001F0000&(data))>>16)
#define YC_3D_F4_PAIR_TH_MULTIPLE_3_get_diff_th_multiple_20(data)     ((0x00001F00&(data))>>8)
#define YC_3D_F4_PAIR_TH_MULTIPLE_3_get_diff_th_multiple_40(data)     (0x0000001F&(data))


#define YC_3D_F4_PAIR_TH_BASE_1                                       0x18019d64
#define YC_3D_F4_PAIR_TH_BASE_1_reg_addr                              "0xb8019d64"
#define YC_3D_F4_PAIR_TH_BASE_1_reg                                   0xb8019d64
#define YC_3D_F4_PAIR_TH_BASE_1_inst_addr                             "0x0359"
#define YC_3D_F4_PAIR_TH_BASE_1_inst                                  0x0359
#define YC_3D_F4_PAIR_TH_BASE_1_diff_th_base_140_shift                (24)
#define YC_3D_F4_PAIR_TH_BASE_1_diff_th_base_160_shift                (16)
#define YC_3D_F4_PAIR_TH_BASE_1_diff_th_base_180_shift                (8)
#define YC_3D_F4_PAIR_TH_BASE_1_diff_th_base_200_shift                (0)
#define YC_3D_F4_PAIR_TH_BASE_1_diff_th_base_140_mask                 (0x3F000000)
#define YC_3D_F4_PAIR_TH_BASE_1_diff_th_base_160_mask                 (0x003F0000)
#define YC_3D_F4_PAIR_TH_BASE_1_diff_th_base_180_mask                 (0x00003F00)
#define YC_3D_F4_PAIR_TH_BASE_1_diff_th_base_200_mask                 (0x0000003F)
#define YC_3D_F4_PAIR_TH_BASE_1_diff_th_base_140(data)                (0x3F000000&((data)<<24))
#define YC_3D_F4_PAIR_TH_BASE_1_diff_th_base_160(data)                (0x003F0000&((data)<<16))
#define YC_3D_F4_PAIR_TH_BASE_1_diff_th_base_180(data)                (0x00003F00&((data)<<8))
#define YC_3D_F4_PAIR_TH_BASE_1_diff_th_base_200(data)                (0x0000003F&(data))
#define YC_3D_F4_PAIR_TH_BASE_1_get_diff_th_base_140(data)            ((0x3F000000&(data))>>24)
#define YC_3D_F4_PAIR_TH_BASE_1_get_diff_th_base_160(data)            ((0x003F0000&(data))>>16)
#define YC_3D_F4_PAIR_TH_BASE_1_get_diff_th_base_180(data)            ((0x00003F00&(data))>>8)
#define YC_3D_F4_PAIR_TH_BASE_1_get_diff_th_base_200(data)            (0x0000003F&(data))


#define YC_3D_F4_PAIR_TH_BASE_2                                       0x18019d68
#define YC_3D_F4_PAIR_TH_BASE_2_reg_addr                              "0xb8019d68"
#define YC_3D_F4_PAIR_TH_BASE_2_reg                                   0xb8019d68
#define YC_3D_F4_PAIR_TH_BASE_2_inst_addr                             "0x035A"
#define YC_3D_F4_PAIR_TH_BASE_2_inst                                  0x035A
#define YC_3D_F4_PAIR_TH_BASE_2_diff_th_base_60_shift                 (24)
#define YC_3D_F4_PAIR_TH_BASE_2_diff_th_base_80_shift                 (16)
#define YC_3D_F4_PAIR_TH_BASE_2_diff_th_base_100_shift                (8)
#define YC_3D_F4_PAIR_TH_BASE_2_diff_th_base_120_shift                (0)
#define YC_3D_F4_PAIR_TH_BASE_2_diff_th_base_60_mask                  (0x3F000000)
#define YC_3D_F4_PAIR_TH_BASE_2_diff_th_base_80_mask                  (0x003F0000)
#define YC_3D_F4_PAIR_TH_BASE_2_diff_th_base_100_mask                 (0x00003F00)
#define YC_3D_F4_PAIR_TH_BASE_2_diff_th_base_120_mask                 (0x0000003F)
#define YC_3D_F4_PAIR_TH_BASE_2_diff_th_base_60(data)                 (0x3F000000&((data)<<24))
#define YC_3D_F4_PAIR_TH_BASE_2_diff_th_base_80(data)                 (0x003F0000&((data)<<16))
#define YC_3D_F4_PAIR_TH_BASE_2_diff_th_base_100(data)                (0x00003F00&((data)<<8))
#define YC_3D_F4_PAIR_TH_BASE_2_diff_th_base_120(data)                (0x0000003F&(data))
#define YC_3D_F4_PAIR_TH_BASE_2_get_diff_th_base_60(data)             ((0x3F000000&(data))>>24)
#define YC_3D_F4_PAIR_TH_BASE_2_get_diff_th_base_80(data)             ((0x003F0000&(data))>>16)
#define YC_3D_F4_PAIR_TH_BASE_2_get_diff_th_base_100(data)            ((0x00003F00&(data))>>8)
#define YC_3D_F4_PAIR_TH_BASE_2_get_diff_th_base_120(data)            (0x0000003F&(data))


#define YC_3D_F4_PAIR_TH_BASE_3                                       0x18019d6c
#define YC_3D_F4_PAIR_TH_BASE_3_reg_addr                              "0xb8019d6c"
#define YC_3D_F4_PAIR_TH_BASE_3_reg                                   0xb8019d6c
#define YC_3D_F4_PAIR_TH_BASE_3_inst_addr                             "0x035B"
#define YC_3D_F4_PAIR_TH_BASE_3_inst                                  0x035B
#define YC_3D_F4_PAIR_TH_BASE_3_diff_th_base_0_shift                  (24)
#define YC_3D_F4_PAIR_TH_BASE_3_diff_th_base_10_shift                 (16)
#define YC_3D_F4_PAIR_TH_BASE_3_diff_th_base_20_shift                 (8)
#define YC_3D_F4_PAIR_TH_BASE_3_diff_th_base_40_shift                 (0)
#define YC_3D_F4_PAIR_TH_BASE_3_diff_th_base_0_mask                   (0x3F000000)
#define YC_3D_F4_PAIR_TH_BASE_3_diff_th_base_10_mask                  (0x003F0000)
#define YC_3D_F4_PAIR_TH_BASE_3_diff_th_base_20_mask                  (0x00003F00)
#define YC_3D_F4_PAIR_TH_BASE_3_diff_th_base_40_mask                  (0x0000003F)
#define YC_3D_F4_PAIR_TH_BASE_3_diff_th_base_0(data)                  (0x3F000000&((data)<<24))
#define YC_3D_F4_PAIR_TH_BASE_3_diff_th_base_10(data)                 (0x003F0000&((data)<<16))
#define YC_3D_F4_PAIR_TH_BASE_3_diff_th_base_20(data)                 (0x00003F00&((data)<<8))
#define YC_3D_F4_PAIR_TH_BASE_3_diff_th_base_40(data)                 (0x0000003F&(data))
#define YC_3D_F4_PAIR_TH_BASE_3_get_diff_th_base_0(data)              ((0x3F000000&(data))>>24)
#define YC_3D_F4_PAIR_TH_BASE_3_get_diff_th_base_10(data)             ((0x003F0000&(data))>>16)
#define YC_3D_F4_PAIR_TH_BASE_3_get_diff_th_base_20(data)             ((0x00003F00&(data))>>8)
#define YC_3D_F4_PAIR_TH_BASE_3_get_diff_th_base_40(data)             (0x0000003F&(data))


#define YC_3D_F4_PAIR_CTRL_1                                          0x18019d70
#define YC_3D_F4_PAIR_CTRL_1_reg_addr                                 "0xb8019d70"
#define YC_3D_F4_PAIR_CTRL_1_reg                                      0xb8019d70
#define YC_3D_F4_PAIR_CTRL_1_inst_addr                                "0x035C"
#define YC_3D_F4_PAIR_CTRL_1_inst                                     0x035C
#define YC_3D_F4_PAIR_CTRL_1_hv_offset_shift                          (24)
#define YC_3D_F4_PAIR_CTRL_1_still_vector_offset_multiple_shift       (20)
#define YC_3D_F4_PAIR_CTRL_1_still_vector_offset_base_shift           (12)
#define YC_3D_F4_PAIR_CTRL_1_pal_error_offset_shift                   (4)
#define YC_3D_F4_PAIR_CTRL_1_hor_c_diff_dpo_hedge_rshift_bit_shift    (0)
#define YC_3D_F4_PAIR_CTRL_1_hv_offset_mask                           (0x3F000000)
#define YC_3D_F4_PAIR_CTRL_1_still_vector_offset_multiple_mask        (0x00700000)
#define YC_3D_F4_PAIR_CTRL_1_still_vector_offset_base_mask            (0x0003F000)
#define YC_3D_F4_PAIR_CTRL_1_pal_error_offset_mask                    (0x000003F0)
#define YC_3D_F4_PAIR_CTRL_1_hor_c_diff_dpo_hedge_rshift_bit_mask     (0x00000007)
#define YC_3D_F4_PAIR_CTRL_1_hv_offset(data)                          (0x3F000000&((data)<<24))
#define YC_3D_F4_PAIR_CTRL_1_still_vector_offset_multiple(data)       (0x00700000&((data)<<20))
#define YC_3D_F4_PAIR_CTRL_1_still_vector_offset_base(data)           (0x0003F000&((data)<<12))
#define YC_3D_F4_PAIR_CTRL_1_pal_error_offset(data)                   (0x000003F0&((data)<<4))
#define YC_3D_F4_PAIR_CTRL_1_hor_c_diff_dpo_hedge_rshift_bit(data)    (0x00000007&(data))
#define YC_3D_F4_PAIR_CTRL_1_get_hv_offset(data)                      ((0x3F000000&(data))>>24)
#define YC_3D_F4_PAIR_CTRL_1_get_still_vector_offset_multiple(data)   ((0x00700000&(data))>>20)
#define YC_3D_F4_PAIR_CTRL_1_get_still_vector_offset_base(data)       ((0x0003F000&(data))>>12)
#define YC_3D_F4_PAIR_CTRL_1_get_pal_error_offset(data)               ((0x000003F0&(data))>>4)
#define YC_3D_F4_PAIR_CTRL_1_get_hor_c_diff_dpo_hedge_rshift_bit(data)  (0x00000007&(data))


#define YC_3D_F4_PAIR_CTRL_2                                          0x18019d74
#define YC_3D_F4_PAIR_CTRL_2_reg_addr                                 "0xb8019d74"
#define YC_3D_F4_PAIR_CTRL_2_reg                                      0xb8019d74
#define YC_3D_F4_PAIR_CTRL_2_inst_addr                                "0x035D"
#define YC_3D_F4_PAIR_CTRL_2_inst                                     0x035D
#define YC_3D_F4_PAIR_CTRL_2_still_vector_cvbs_amp_change_offset_shift  (8)
#define YC_3D_F4_PAIR_CTRL_2_still_vector_hifreq_diff_th_shift        (0)
#define YC_3D_F4_PAIR_CTRL_2_still_vector_cvbs_amp_change_offset_mask (0x00003F00)
#define YC_3D_F4_PAIR_CTRL_2_still_vector_hifreq_diff_th_mask         (0x0000003F)
#define YC_3D_F4_PAIR_CTRL_2_still_vector_cvbs_amp_change_offset(data)  (0x00003F00&((data)<<8))
#define YC_3D_F4_PAIR_CTRL_2_still_vector_hifreq_diff_th(data)        (0x0000003F&(data))
#define YC_3D_F4_PAIR_CTRL_2_get_still_vector_cvbs_amp_change_offset(data)  ((0x00003F00&(data))>>8)
#define YC_3D_F4_PAIR_CTRL_2_get_still_vector_hifreq_diff_th(data)    (0x0000003F&(data))


#define YC_3D_F4_PAIR_CTRL_3                                          0x18019d78
#define YC_3D_F4_PAIR_CTRL_3_reg_addr                                 "0xb8019d78"
#define YC_3D_F4_PAIR_CTRL_3_reg                                      0xb8019d78
#define YC_3D_F4_PAIR_CTRL_3_inst_addr                                "0x035E"
#define YC_3D_F4_PAIR_CTRL_3_inst                                     0x035E
#define YC_3D_F4_PAIR_CTRL_3_later_diff_upper_bound_shift             (20)
#define YC_3D_F4_PAIR_CTRL_3_pair_diff_sel_th_shift                   (12)
#define YC_3D_F4_PAIR_CTRL_3_highfreq_diff_low_border_shift           (4)
#define YC_3D_F4_PAIR_CTRL_3_flat_offset_shift                        (0)
#define YC_3D_F4_PAIR_CTRL_3_later_diff_upper_bound_mask              (0x07F00000)
#define YC_3D_F4_PAIR_CTRL_3_pair_diff_sel_th_mask                    (0x0007F000)
#define YC_3D_F4_PAIR_CTRL_3_highfreq_diff_low_border_mask            (0x000001F0)
#define YC_3D_F4_PAIR_CTRL_3_flat_offset_mask                         (0x0000000F)
#define YC_3D_F4_PAIR_CTRL_3_later_diff_upper_bound(data)             (0x07F00000&((data)<<20))
#define YC_3D_F4_PAIR_CTRL_3_pair_diff_sel_th(data)                   (0x0007F000&((data)<<12))
#define YC_3D_F4_PAIR_CTRL_3_highfreq_diff_low_border(data)           (0x000001F0&((data)<<4))
#define YC_3D_F4_PAIR_CTRL_3_flat_offset(data)                        (0x0000000F&(data))
#define YC_3D_F4_PAIR_CTRL_3_get_later_diff_upper_bound(data)         ((0x07F00000&(data))>>20)
#define YC_3D_F4_PAIR_CTRL_3_get_pair_diff_sel_th(data)               ((0x0007F000&(data))>>12)
#define YC_3D_F4_PAIR_CTRL_3_get_highfreq_diff_low_border(data)       ((0x000001F0&(data))>>4)
#define YC_3D_F4_PAIR_CTRL_3_get_flat_offset(data)                    (0x0000000F&(data))


#define YC_3D_F4_PAIR_CTRL_4                                          0x18019d7c
#define YC_3D_F4_PAIR_CTRL_4_reg_addr                                 "0xb8019d7c"
#define YC_3D_F4_PAIR_CTRL_4_reg                                      0xb8019d7c
#define YC_3D_F4_PAIR_CTRL_4_inst_addr                                "0x035F"
#define YC_3D_F4_PAIR_CTRL_4_inst                                     0x035F
#define YC_3D_F4_PAIR_CTRL_4_diff_th_upper_bound_shift                (24)
#define YC_3D_F4_PAIR_CTRL_4_diff_th_lower_bound_shift                (16)
#define YC_3D_F4_PAIR_CTRL_4_diff_th_2d_comp_3d_offset_shift          (8)
#define YC_3D_F4_PAIR_CTRL_4_hvdiff_border_shift                      (0)
#define YC_3D_F4_PAIR_CTRL_4_diff_th_upper_bound_mask                 (0x7F000000)
#define YC_3D_F4_PAIR_CTRL_4_diff_th_lower_bound_mask                 (0x001F0000)
#define YC_3D_F4_PAIR_CTRL_4_diff_th_2d_comp_3d_offset_mask           (0x00001F00)
#define YC_3D_F4_PAIR_CTRL_4_hvdiff_border_mask                       (0x0000003F)
#define YC_3D_F4_PAIR_CTRL_4_diff_th_upper_bound(data)                (0x7F000000&((data)<<24))
#define YC_3D_F4_PAIR_CTRL_4_diff_th_lower_bound(data)                (0x001F0000&((data)<<16))
#define YC_3D_F4_PAIR_CTRL_4_diff_th_2d_comp_3d_offset(data)          (0x00001F00&((data)<<8))
#define YC_3D_F4_PAIR_CTRL_4_hvdiff_border(data)                      (0x0000003F&(data))
#define YC_3D_F4_PAIR_CTRL_4_get_diff_th_upper_bound(data)            ((0x7F000000&(data))>>24)
#define YC_3D_F4_PAIR_CTRL_4_get_diff_th_lower_bound(data)            ((0x001F0000&(data))>>16)
#define YC_3D_F4_PAIR_CTRL_4_get_diff_th_2d_comp_3d_offset(data)      ((0x00001F00&(data))>>8)
#define YC_3D_F4_PAIR_CTRL_4_get_hvdiff_border(data)                  (0x0000003F&(data))


#define YC_3D_F4_PAIR_CTRL_5                                          0x18019d80
#define YC_3D_F4_PAIR_CTRL_5_reg_addr                                 "0xb8019d80"
#define YC_3D_F4_PAIR_CTRL_5_reg                                      0xb8019d80
#define YC_3D_F4_PAIR_CTRL_5_inst_addr                                "0x0360"
#define YC_3D_F4_PAIR_CTRL_5_inst                                     0x0360
#define YC_3D_F4_PAIR_CTRL_5_still_gray_hifreq_th_shift               (12)
#define YC_3D_F4_PAIR_CTRL_5_still_gray_hifreq_low_border_shift       (4)
#define YC_3D_F4_PAIR_CTRL_5_still_gray_hifreq_enable_shift           (0)
#define YC_3D_F4_PAIR_CTRL_5_still_gray_hifreq_th_mask                (0x0007F000)
#define YC_3D_F4_PAIR_CTRL_5_still_gray_hifreq_low_border_mask        (0x000003F0)
#define YC_3D_F4_PAIR_CTRL_5_still_gray_hifreq_enable_mask            (0x00000001)
#define YC_3D_F4_PAIR_CTRL_5_still_gray_hifreq_th(data)               (0x0007F000&((data)<<12))
#define YC_3D_F4_PAIR_CTRL_5_still_gray_hifreq_low_border(data)       (0x000003F0&((data)<<4))
#define YC_3D_F4_PAIR_CTRL_5_still_gray_hifreq_enable(data)           (0x00000001&(data))
#define YC_3D_F4_PAIR_CTRL_5_get_still_gray_hifreq_th(data)           ((0x0007F000&(data))>>12)
#define YC_3D_F4_PAIR_CTRL_5_get_still_gray_hifreq_low_border(data)   ((0x000003F0&(data))>>4)
#define YC_3D_F4_PAIR_CTRL_5_get_still_gray_hifreq_enable(data)       (0x00000001&(data))


#define YC_3D_F4_PAIR_CTRL_6                                          0x18019d84
#define YC_3D_F4_PAIR_CTRL_6_reg_addr                                 "0xb8019d84"
#define YC_3D_F4_PAIR_CTRL_6_reg                                      0xb8019d84
#define YC_3D_F4_PAIR_CTRL_6_inst_addr                                "0x0361"
#define YC_3D_F4_PAIR_CTRL_6_inst                                     0x0361
#define YC_3D_F4_PAIR_CTRL_6_global_diff_tolerance_shift              (24)
#define YC_3D_F4_PAIR_CTRL_6_global_diff_offset_dc_fierce_change_shift  (16)
#define YC_3D_F4_PAIR_CTRL_6_dc_level_fierce_change_th_shift          (8)
#define YC_3D_F4_PAIR_CTRL_6_hdy_small_th_shift                       (0)
#define YC_3D_F4_PAIR_CTRL_6_global_diff_tolerance_mask               (0x0F000000)
#define YC_3D_F4_PAIR_CTRL_6_global_diff_offset_dc_fierce_change_mask (0x001F0000)
#define YC_3D_F4_PAIR_CTRL_6_dc_level_fierce_change_th_mask           (0x00003F00)
#define YC_3D_F4_PAIR_CTRL_6_hdy_small_th_mask                        (0x0000003F)
#define YC_3D_F4_PAIR_CTRL_6_global_diff_tolerance(data)              (0x0F000000&((data)<<24))
#define YC_3D_F4_PAIR_CTRL_6_global_diff_offset_dc_fierce_change(data)  (0x001F0000&((data)<<16))
#define YC_3D_F4_PAIR_CTRL_6_dc_level_fierce_change_th(data)          (0x00003F00&((data)<<8))
#define YC_3D_F4_PAIR_CTRL_6_hdy_small_th(data)                       (0x0000003F&(data))
#define YC_3D_F4_PAIR_CTRL_6_get_global_diff_tolerance(data)          ((0x0F000000&(data))>>24)
#define YC_3D_F4_PAIR_CTRL_6_get_global_diff_offset_dc_fierce_change(data)  ((0x001F0000&(data))>>16)
#define YC_3D_F4_PAIR_CTRL_6_get_dc_level_fierce_change_th(data)      ((0x00003F00&(data))>>8)
#define YC_3D_F4_PAIR_CTRL_6_get_hdy_small_th(data)                   (0x0000003F&(data))


#define YC_3D_F4_GLOBAL_DIFF_TH_HIFREQ_OFFSET_1                       0x18019d88
#define YC_3D_F4_GLOBAL_DIFF_TH_HIFREQ_OFFSET_1_reg_addr              "0xb8019d88"
#define YC_3D_F4_GLOBAL_DIFF_TH_HIFREQ_OFFSET_1_reg                   0xb8019d88
#define YC_3D_F4_GLOBAL_DIFF_TH_HIFREQ_OFFSET_1_inst_addr             "0x0362"
#define YC_3D_F4_GLOBAL_DIFF_TH_HIFREQ_OFFSET_1_inst                  0x0362
#define YC_3D_F4_GLOBAL_DIFF_TH_HIFREQ_OFFSET_1_global_diff_th_hifreq_offset_120_shift  (24)
#define YC_3D_F4_GLOBAL_DIFF_TH_HIFREQ_OFFSET_1_global_diff_th_hifreq_offset_140_shift  (16)
#define YC_3D_F4_GLOBAL_DIFF_TH_HIFREQ_OFFSET_1_global_diff_th_hifreq_offset_160_shift  (8)
#define YC_3D_F4_GLOBAL_DIFF_TH_HIFREQ_OFFSET_1_global_diff_th_hifreq_offset_180_shift  (0)
#define YC_3D_F4_GLOBAL_DIFF_TH_HIFREQ_OFFSET_1_global_diff_th_hifreq_offset_120_mask  (0x3F000000)
#define YC_3D_F4_GLOBAL_DIFF_TH_HIFREQ_OFFSET_1_global_diff_th_hifreq_offset_140_mask  (0x003F0000)
#define YC_3D_F4_GLOBAL_DIFF_TH_HIFREQ_OFFSET_1_global_diff_th_hifreq_offset_160_mask  (0x00003F00)
#define YC_3D_F4_GLOBAL_DIFF_TH_HIFREQ_OFFSET_1_global_diff_th_hifreq_offset_180_mask  (0x0000003F)
#define YC_3D_F4_GLOBAL_DIFF_TH_HIFREQ_OFFSET_1_global_diff_th_hifreq_offset_120(data)  (0x3F000000&((data)<<24))
#define YC_3D_F4_GLOBAL_DIFF_TH_HIFREQ_OFFSET_1_global_diff_th_hifreq_offset_140(data)  (0x003F0000&((data)<<16))
#define YC_3D_F4_GLOBAL_DIFF_TH_HIFREQ_OFFSET_1_global_diff_th_hifreq_offset_160(data)  (0x00003F00&((data)<<8))
#define YC_3D_F4_GLOBAL_DIFF_TH_HIFREQ_OFFSET_1_global_diff_th_hifreq_offset_180(data)  (0x0000003F&(data))
#define YC_3D_F4_GLOBAL_DIFF_TH_HIFREQ_OFFSET_1_get_global_diff_th_hifreq_offset_120(data)  ((0x3F000000&(data))>>24)
#define YC_3D_F4_GLOBAL_DIFF_TH_HIFREQ_OFFSET_1_get_global_diff_th_hifreq_offset_140(data)  ((0x003F0000&(data))>>16)
#define YC_3D_F4_GLOBAL_DIFF_TH_HIFREQ_OFFSET_1_get_global_diff_th_hifreq_offset_160(data)  ((0x00003F00&(data))>>8)
#define YC_3D_F4_GLOBAL_DIFF_TH_HIFREQ_OFFSET_1_get_global_diff_th_hifreq_offset_180(data)  (0x0000003F&(data))


#define YC_3D_F4_GLOBAL_DIFF_TH_HIFREQ_OFFSET_2                       0x18019d8c
#define YC_3D_F4_GLOBAL_DIFF_TH_HIFREQ_OFFSET_2_reg_addr              "0xb8019d8c"
#define YC_3D_F4_GLOBAL_DIFF_TH_HIFREQ_OFFSET_2_reg                   0xb8019d8c
#define YC_3D_F4_GLOBAL_DIFF_TH_HIFREQ_OFFSET_2_inst_addr             "0x0363"
#define YC_3D_F4_GLOBAL_DIFF_TH_HIFREQ_OFFSET_2_inst                  0x0363
#define YC_3D_F4_GLOBAL_DIFF_TH_HIFREQ_OFFSET_2_global_diff_th_hifreq_offset_60_shift  (24)
#define YC_3D_F4_GLOBAL_DIFF_TH_HIFREQ_OFFSET_2_global_diff_th_hifreq_offset_70_shift  (16)
#define YC_3D_F4_GLOBAL_DIFF_TH_HIFREQ_OFFSET_2_global_diff_th_hifreq_offset_80_shift  (8)
#define YC_3D_F4_GLOBAL_DIFF_TH_HIFREQ_OFFSET_2_global_diff_th_hifreq_offset_100_shift  (0)
#define YC_3D_F4_GLOBAL_DIFF_TH_HIFREQ_OFFSET_2_global_diff_th_hifreq_offset_60_mask  (0x3F000000)
#define YC_3D_F4_GLOBAL_DIFF_TH_HIFREQ_OFFSET_2_global_diff_th_hifreq_offset_70_mask  (0x003F0000)
#define YC_3D_F4_GLOBAL_DIFF_TH_HIFREQ_OFFSET_2_global_diff_th_hifreq_offset_80_mask  (0x00003F00)
#define YC_3D_F4_GLOBAL_DIFF_TH_HIFREQ_OFFSET_2_global_diff_th_hifreq_offset_100_mask  (0x0000003F)
#define YC_3D_F4_GLOBAL_DIFF_TH_HIFREQ_OFFSET_2_global_diff_th_hifreq_offset_60(data)  (0x3F000000&((data)<<24))
#define YC_3D_F4_GLOBAL_DIFF_TH_HIFREQ_OFFSET_2_global_diff_th_hifreq_offset_70(data)  (0x003F0000&((data)<<16))
#define YC_3D_F4_GLOBAL_DIFF_TH_HIFREQ_OFFSET_2_global_diff_th_hifreq_offset_80(data)  (0x00003F00&((data)<<8))
#define YC_3D_F4_GLOBAL_DIFF_TH_HIFREQ_OFFSET_2_global_diff_th_hifreq_offset_100(data)  (0x0000003F&(data))
#define YC_3D_F4_GLOBAL_DIFF_TH_HIFREQ_OFFSET_2_get_global_diff_th_hifreq_offset_60(data)  ((0x3F000000&(data))>>24)
#define YC_3D_F4_GLOBAL_DIFF_TH_HIFREQ_OFFSET_2_get_global_diff_th_hifreq_offset_70(data)  ((0x003F0000&(data))>>16)
#define YC_3D_F4_GLOBAL_DIFF_TH_HIFREQ_OFFSET_2_get_global_diff_th_hifreq_offset_80(data)  ((0x00003F00&(data))>>8)
#define YC_3D_F4_GLOBAL_DIFF_TH_HIFREQ_OFFSET_2_get_global_diff_th_hifreq_offset_100(data)  (0x0000003F&(data))


#define YC_3D_F4_GLOBAL_DIFF_TH_HIFREQ_OFFSET_3                       0x18019d90
#define YC_3D_F4_GLOBAL_DIFF_TH_HIFREQ_OFFSET_3_reg_addr              "0xb8019d90"
#define YC_3D_F4_GLOBAL_DIFF_TH_HIFREQ_OFFSET_3_reg                   0xb8019d90
#define YC_3D_F4_GLOBAL_DIFF_TH_HIFREQ_OFFSET_3_inst_addr             "0x0364"
#define YC_3D_F4_GLOBAL_DIFF_TH_HIFREQ_OFFSET_3_inst                  0x0364
#define YC_3D_F4_GLOBAL_DIFF_TH_HIFREQ_OFFSET_3_global_diff_th_hifreq_offset_20_shift  (24)
#define YC_3D_F4_GLOBAL_DIFF_TH_HIFREQ_OFFSET_3_global_diff_th_hifreq_offset_30_shift  (16)
#define YC_3D_F4_GLOBAL_DIFF_TH_HIFREQ_OFFSET_3_global_diff_th_hifreq_offset_40_shift  (8)
#define YC_3D_F4_GLOBAL_DIFF_TH_HIFREQ_OFFSET_3_global_diff_th_hifreq_offset_50_shift  (0)
#define YC_3D_F4_GLOBAL_DIFF_TH_HIFREQ_OFFSET_3_global_diff_th_hifreq_offset_20_mask  (0x3F000000)
#define YC_3D_F4_GLOBAL_DIFF_TH_HIFREQ_OFFSET_3_global_diff_th_hifreq_offset_30_mask  (0x003F0000)
#define YC_3D_F4_GLOBAL_DIFF_TH_HIFREQ_OFFSET_3_global_diff_th_hifreq_offset_40_mask  (0x00003F00)
#define YC_3D_F4_GLOBAL_DIFF_TH_HIFREQ_OFFSET_3_global_diff_th_hifreq_offset_50_mask  (0x0000003F)
#define YC_3D_F4_GLOBAL_DIFF_TH_HIFREQ_OFFSET_3_global_diff_th_hifreq_offset_20(data)  (0x3F000000&((data)<<24))
#define YC_3D_F4_GLOBAL_DIFF_TH_HIFREQ_OFFSET_3_global_diff_th_hifreq_offset_30(data)  (0x003F0000&((data)<<16))
#define YC_3D_F4_GLOBAL_DIFF_TH_HIFREQ_OFFSET_3_global_diff_th_hifreq_offset_40(data)  (0x00003F00&((data)<<8))
#define YC_3D_F4_GLOBAL_DIFF_TH_HIFREQ_OFFSET_3_global_diff_th_hifreq_offset_50(data)  (0x0000003F&(data))
#define YC_3D_F4_GLOBAL_DIFF_TH_HIFREQ_OFFSET_3_get_global_diff_th_hifreq_offset_20(data)  ((0x3F000000&(data))>>24)
#define YC_3D_F4_GLOBAL_DIFF_TH_HIFREQ_OFFSET_3_get_global_diff_th_hifreq_offset_30(data)  ((0x003F0000&(data))>>16)
#define YC_3D_F4_GLOBAL_DIFF_TH_HIFREQ_OFFSET_3_get_global_diff_th_hifreq_offset_40(data)  ((0x00003F00&(data))>>8)
#define YC_3D_F4_GLOBAL_DIFF_TH_HIFREQ_OFFSET_3_get_global_diff_th_hifreq_offset_50(data)  (0x0000003F&(data))


#define YC_3D_F4_GLOBAL_DIFF_TH_HIFREQ_OFFSET_4                       0x18019d94
#define YC_3D_F4_GLOBAL_DIFF_TH_HIFREQ_OFFSET_4_reg_addr              "0xb8019d94"
#define YC_3D_F4_GLOBAL_DIFF_TH_HIFREQ_OFFSET_4_reg                   0xb8019d94
#define YC_3D_F4_GLOBAL_DIFF_TH_HIFREQ_OFFSET_4_inst_addr             "0x0365"
#define YC_3D_F4_GLOBAL_DIFF_TH_HIFREQ_OFFSET_4_inst                  0x0365
#define YC_3D_F4_GLOBAL_DIFF_TH_HIFREQ_OFFSET_4_global_diff_th_hifreq_offset_0_shift  (8)
#define YC_3D_F4_GLOBAL_DIFF_TH_HIFREQ_OFFSET_4_global_diff_th_hifreq_offset_10_shift  (0)
#define YC_3D_F4_GLOBAL_DIFF_TH_HIFREQ_OFFSET_4_global_diff_th_hifreq_offset_0_mask  (0x00003F00)
#define YC_3D_F4_GLOBAL_DIFF_TH_HIFREQ_OFFSET_4_global_diff_th_hifreq_offset_10_mask  (0x0000003F)
#define YC_3D_F4_GLOBAL_DIFF_TH_HIFREQ_OFFSET_4_global_diff_th_hifreq_offset_0(data)  (0x00003F00&((data)<<8))
#define YC_3D_F4_GLOBAL_DIFF_TH_HIFREQ_OFFSET_4_global_diff_th_hifreq_offset_10(data)  (0x0000003F&(data))
#define YC_3D_F4_GLOBAL_DIFF_TH_HIFREQ_OFFSET_4_get_global_diff_th_hifreq_offset_0(data)  ((0x00003F00&(data))>>8)
#define YC_3D_F4_GLOBAL_DIFF_TH_HIFREQ_OFFSET_4_get_global_diff_th_hifreq_offset_10(data)  (0x0000003F&(data))


#define YC_3D_F4_MGHF_CTRL_1                                          0x18019d98
#define YC_3D_F4_MGHF_CTRL_1_reg_addr                                 "0xb8019d98"
#define YC_3D_F4_MGHF_CTRL_1_reg                                      0xb8019d98
#define YC_3D_F4_MGHF_CTRL_1_inst_addr                                "0x0366"
#define YC_3D_F4_MGHF_CTRL_1_inst                                     0x0366
#define YC_3D_F4_MGHF_CTRL_1_moving_vline_ver_dc_level_fierce_change_th_shift  (12)
#define YC_3D_F4_MGHF_CTRL_1_moving_vline_flat_ver_cvbs_th_shift      (4)
#define YC_3D_F4_MGHF_CTRL_1_mghf_enable_shift                        (2)
#define YC_3D_F4_MGHF_CTRL_1_moving_vline_en_shift                    (1)
#define YC_3D_F4_MGHF_CTRL_1_dc_level_hor_dc_check_en_shift           (0)
#define YC_3D_F4_MGHF_CTRL_1_moving_vline_ver_dc_level_fierce_change_th_mask  (0x0001F000)
#define YC_3D_F4_MGHF_CTRL_1_moving_vline_flat_ver_cvbs_th_mask       (0x000001F0)
#define YC_3D_F4_MGHF_CTRL_1_mghf_enable_mask                         (0x00000004)
#define YC_3D_F4_MGHF_CTRL_1_moving_vline_en_mask                     (0x00000002)
#define YC_3D_F4_MGHF_CTRL_1_dc_level_hor_dc_check_en_mask            (0x00000001)
#define YC_3D_F4_MGHF_CTRL_1_moving_vline_ver_dc_level_fierce_change_th(data)  (0x0001F000&((data)<<12))
#define YC_3D_F4_MGHF_CTRL_1_moving_vline_flat_ver_cvbs_th(data)      (0x000001F0&((data)<<4))
#define YC_3D_F4_MGHF_CTRL_1_mghf_enable(data)                        (0x00000004&((data)<<2))
#define YC_3D_F4_MGHF_CTRL_1_moving_vline_en(data)                    (0x00000002&((data)<<1))
#define YC_3D_F4_MGHF_CTRL_1_dc_level_hor_dc_check_en(data)           (0x00000001&(data))
#define YC_3D_F4_MGHF_CTRL_1_get_moving_vline_ver_dc_level_fierce_change_th(data)  ((0x0001F000&(data))>>12)
#define YC_3D_F4_MGHF_CTRL_1_get_moving_vline_flat_ver_cvbs_th(data)  ((0x000001F0&(data))>>4)
#define YC_3D_F4_MGHF_CTRL_1_get_mghf_enable(data)                    ((0x00000004&(data))>>2)
#define YC_3D_F4_MGHF_CTRL_1_get_moving_vline_en(data)                ((0x00000002&(data))>>1)
#define YC_3D_F4_MGHF_CTRL_1_get_dc_level_hor_dc_check_en(data)       (0x00000001&(data))


#define YC_3D_F4_MGHF_CTRL_2                                          0x18019d9c
#define YC_3D_F4_MGHF_CTRL_2_reg_addr                                 "0xb8019d9c"
#define YC_3D_F4_MGHF_CTRL_2_reg                                      0xb8019d9c
#define YC_3D_F4_MGHF_CTRL_2_inst_addr                                "0x0367"
#define YC_3D_F4_MGHF_CTRL_2_inst                                     0x0367
#define YC_3D_F4_MGHF_CTRL_2_large_hifreq_diff_ratio_shift            (28)
#define YC_3D_F4_MGHF_CTRL_2_hor_c_change_ratio_shift                 (24)
#define YC_3D_F4_MGHF_CTRL_2_hifreq_diff_large_th_shift               (16)
#define YC_3D_F4_MGHF_CTRL_2_cvbs_still_th_shift                      (8)
#define YC_3D_F4_MGHF_CTRL_2_hor_c_change_th_shift                    (0)
#define YC_3D_F4_MGHF_CTRL_2_large_hifreq_diff_ratio_mask             (0x70000000)
#define YC_3D_F4_MGHF_CTRL_2_hor_c_change_ratio_mask                  (0x07000000)
#define YC_3D_F4_MGHF_CTRL_2_hifreq_diff_large_th_mask                (0x001F0000)
#define YC_3D_F4_MGHF_CTRL_2_cvbs_still_th_mask                       (0x00001F00)
#define YC_3D_F4_MGHF_CTRL_2_hor_c_change_th_mask                     (0x0000001F)
#define YC_3D_F4_MGHF_CTRL_2_large_hifreq_diff_ratio(data)            (0x70000000&((data)<<28))
#define YC_3D_F4_MGHF_CTRL_2_hor_c_change_ratio(data)                 (0x07000000&((data)<<24))
#define YC_3D_F4_MGHF_CTRL_2_hifreq_diff_large_th(data)               (0x001F0000&((data)<<16))
#define YC_3D_F4_MGHF_CTRL_2_cvbs_still_th(data)                      (0x00001F00&((data)<<8))
#define YC_3D_F4_MGHF_CTRL_2_hor_c_change_th(data)                    (0x0000001F&(data))
#define YC_3D_F4_MGHF_CTRL_2_get_large_hifreq_diff_ratio(data)        ((0x70000000&(data))>>28)
#define YC_3D_F4_MGHF_CTRL_2_get_hor_c_change_ratio(data)             ((0x07000000&(data))>>24)
#define YC_3D_F4_MGHF_CTRL_2_get_hifreq_diff_large_th(data)           ((0x001F0000&(data))>>16)
#define YC_3D_F4_MGHF_CTRL_2_get_cvbs_still_th(data)                  ((0x00001F00&(data))>>8)
#define YC_3D_F4_MGHF_CTRL_2_get_hor_c_change_th(data)                (0x0000001F&(data))


#define YC_POST2DBPF_CTRL                                             0x18019db0
#define YC_POST2DBPF_CTRL_reg_addr                                    "0xb8019db0"
#define YC_POST2DBPF_CTRL_reg                                         0xb8019db0
#define YC_POST2DBPF_CTRL_inst_addr                                   "0x036C"
#define YC_POST2DBPF_CTRL_inst                                        0x036C
#define YC_POST2DBPF_CTRL_gremove_c_small_th_shift                    (20)
#define YC_POST2DBPF_CTRL_gremove_bpfedc_small_th_shift               (16)
#define YC_POST2DBPF_CTRL_weight_2d_c_shift                           (14)
#define YC_POST2DBPF_CTRL_weight_bld_c_shift                          (12)
#define YC_POST2DBPF_CTRL_weight_3d_c_shift                           (10)
#define YC_POST2DBPF_CTRL_weight_2d_y_shift                           (8)
#define YC_POST2DBPF_CTRL_weight_bld_y_shift                          (6)
#define YC_POST2DBPF_CTRL_weight_3d_y_shift                           (4)
#define YC_POST2DBPF_CTRL_mghf_narrowbpf_en_shift                     (3)
#define YC_POST2DBPF_CTRL_greenish_detected_en_shift                  (2)
#define YC_POST2DBPF_CTRL_post2dbpf_c_en_shift                        (1)
#define YC_POST2DBPF_CTRL_post2dbpf_y_en_shift                        (0)
#define YC_POST2DBPF_CTRL_gremove_c_small_th_mask                     (0x01F00000)
#define YC_POST2DBPF_CTRL_gremove_bpfedc_small_th_mask                (0x000F0000)
#define YC_POST2DBPF_CTRL_weight_2d_c_mask                            (0x0000C000)
#define YC_POST2DBPF_CTRL_weight_bld_c_mask                           (0x00003000)
#define YC_POST2DBPF_CTRL_weight_3d_c_mask                            (0x00000C00)
#define YC_POST2DBPF_CTRL_weight_2d_y_mask                            (0x00000300)
#define YC_POST2DBPF_CTRL_weight_bld_y_mask                           (0x000000C0)
#define YC_POST2DBPF_CTRL_weight_3d_y_mask                            (0x00000030)
#define YC_POST2DBPF_CTRL_mghf_narrowbpf_en_mask                      (0x00000008)
#define YC_POST2DBPF_CTRL_greenish_detected_en_mask                   (0x00000004)
#define YC_POST2DBPF_CTRL_post2dbpf_c_en_mask                         (0x00000002)
#define YC_POST2DBPF_CTRL_post2dbpf_y_en_mask                         (0x00000001)
#define YC_POST2DBPF_CTRL_gremove_c_small_th(data)                    (0x01F00000&((data)<<20))
#define YC_POST2DBPF_CTRL_gremove_bpfedc_small_th(data)               (0x000F0000&((data)<<16))
#define YC_POST2DBPF_CTRL_weight_2d_c(data)                           (0x0000C000&((data)<<14))
#define YC_POST2DBPF_CTRL_weight_bld_c(data)                          (0x00003000&((data)<<12))
#define YC_POST2DBPF_CTRL_weight_3d_c(data)                           (0x00000C00&((data)<<10))
#define YC_POST2DBPF_CTRL_weight_2d_y(data)                           (0x00000300&((data)<<8))
#define YC_POST2DBPF_CTRL_weight_bld_y(data)                          (0x000000C0&((data)<<6))
#define YC_POST2DBPF_CTRL_weight_3d_y(data)                           (0x00000030&((data)<<4))
#define YC_POST2DBPF_CTRL_mghf_narrowbpf_en(data)                     (0x00000008&((data)<<3))
#define YC_POST2DBPF_CTRL_greenish_detected_en(data)                  (0x00000004&((data)<<2))
#define YC_POST2DBPF_CTRL_post2dbpf_c_en(data)                        (0x00000002&((data)<<1))
#define YC_POST2DBPF_CTRL_post2dbpf_y_en(data)                        (0x00000001&(data))
#define YC_POST2DBPF_CTRL_get_gremove_c_small_th(data)                ((0x01F00000&(data))>>20)
#define YC_POST2DBPF_CTRL_get_gremove_bpfedc_small_th(data)           ((0x000F0000&(data))>>16)
#define YC_POST2DBPF_CTRL_get_weight_2d_c(data)                       ((0x0000C000&(data))>>14)
#define YC_POST2DBPF_CTRL_get_weight_bld_c(data)                      ((0x00003000&(data))>>12)
#define YC_POST2DBPF_CTRL_get_weight_3d_c(data)                       ((0x00000C00&(data))>>10)
#define YC_POST2DBPF_CTRL_get_weight_2d_y(data)                       ((0x00000300&(data))>>8)
#define YC_POST2DBPF_CTRL_get_weight_bld_y(data)                      ((0x000000C0&(data))>>6)
#define YC_POST2DBPF_CTRL_get_weight_3d_y(data)                       ((0x00000030&(data))>>4)
#define YC_POST2DBPF_CTRL_get_mghf_narrowbpf_en(data)                 ((0x00000008&(data))>>3)
#define YC_POST2DBPF_CTRL_get_greenish_detected_en(data)              ((0x00000004&(data))>>2)
#define YC_POST2DBPF_CTRL_get_post2dbpf_c_en(data)                    ((0x00000002&(data))>>1)
#define YC_POST2DBPF_CTRL_get_post2dbpf_y_en(data)                    (0x00000001&(data))


#define YC_POST2DBPF_THBASE                                           0x18019db4
#define YC_POST2DBPF_THBASE_reg_addr                                  "0xb8019db4"
#define YC_POST2DBPF_THBASE_reg                                       0xb8019db4
#define YC_POST2DBPF_THBASE_inst_addr                                 "0x036D"
#define YC_POST2DBPF_THBASE_inst                                      0x036D
#define YC_POST2DBPF_THBASE_hor_cdiff_th_base_shift                   (8)
#define YC_POST2DBPF_THBASE_ver_cdiff_th_base_shift                   (0)
#define YC_POST2DBPF_THBASE_hor_cdiff_th_base_mask                    (0x00007F00)
#define YC_POST2DBPF_THBASE_ver_cdiff_th_base_mask                    (0x0000007F)
#define YC_POST2DBPF_THBASE_hor_cdiff_th_base(data)                   (0x00007F00&((data)<<8))
#define YC_POST2DBPF_THBASE_ver_cdiff_th_base(data)                   (0x0000007F&(data))
#define YC_POST2DBPF_THBASE_get_hor_cdiff_th_base(data)               ((0x00007F00&(data))>>8)
#define YC_POST2DBPF_THBASE_get_ver_cdiff_th_base(data)               (0x0000007F&(data))


#define YC_POST2DBPF_ADAPTH_1                                         0x18019db8
#define YC_POST2DBPF_ADAPTH_1_reg_addr                                "0xb8019db8"
#define YC_POST2DBPF_ADAPTH_1_reg                                     0xb8019db8
#define YC_POST2DBPF_ADAPTH_1_inst_addr                               "0x036E"
#define YC_POST2DBPF_ADAPTH_1_inst                                    0x036E
#define YC_POST2DBPF_ADAPTH_1_bpfed_c_diff_small_th_shift             (20)
#define YC_POST2DBPF_ADAPTH_1_dual_ch_bpfedc_small_th_shift           (12)
#define YC_POST2DBPF_ADAPTH_1_dual_ch_bpfedcdiff_large_ratio_shift    (8)
#define YC_POST2DBPF_ADAPTH_1_dual_ch_bpfedcdiff_large_th_shift       (0)
#define YC_POST2DBPF_ADAPTH_1_bpfed_c_diff_small_th_mask              (0x07F00000)
#define YC_POST2DBPF_ADAPTH_1_dual_ch_bpfedc_small_th_mask            (0x0001F000)
#define YC_POST2DBPF_ADAPTH_1_dual_ch_bpfedcdiff_large_ratio_mask     (0x00000F00)
#define YC_POST2DBPF_ADAPTH_1_dual_ch_bpfedcdiff_large_th_mask        (0x0000001F)
#define YC_POST2DBPF_ADAPTH_1_bpfed_c_diff_small_th(data)             (0x07F00000&((data)<<20))
#define YC_POST2DBPF_ADAPTH_1_dual_ch_bpfedc_small_th(data)           (0x0001F000&((data)<<12))
#define YC_POST2DBPF_ADAPTH_1_dual_ch_bpfedcdiff_large_ratio(data)    (0x00000F00&((data)<<8))
#define YC_POST2DBPF_ADAPTH_1_dual_ch_bpfedcdiff_large_th(data)       (0x0000001F&(data))
#define YC_POST2DBPF_ADAPTH_1_get_bpfed_c_diff_small_th(data)         ((0x07F00000&(data))>>20)
#define YC_POST2DBPF_ADAPTH_1_get_dual_ch_bpfedc_small_th(data)       ((0x0001F000&(data))>>12)
#define YC_POST2DBPF_ADAPTH_1_get_dual_ch_bpfedcdiff_large_ratio(data)  ((0x00000F00&(data))>>8)
#define YC_POST2DBPF_ADAPTH_1_get_dual_ch_bpfedcdiff_large_th(data)   (0x0000001F&(data))


#define YC_POST2DBPF_ADAPTH_2                                         0x18019dbc
#define YC_POST2DBPF_ADAPTH_2_reg_addr                                "0xb8019dbc"
#define YC_POST2DBPF_ADAPTH_2_reg                                     0xb8019dbc
#define YC_POST2DBPF_ADAPTH_2_inst_addr                               "0x036F"
#define YC_POST2DBPF_ADAPTH_2_inst                                    0x036F
#define YC_POST2DBPF_ADAPTH_2_bpfed_c_diff_large_hor_offset_shift     (24)
#define YC_POST2DBPF_ADAPTH_2_bpfed_c_diff_large_ver_offset_shift     (16)
#define YC_POST2DBPF_ADAPTH_2_bpfed_c_diff_small_hor_offset_shift     (8)
#define YC_POST2DBPF_ADAPTH_2_bpfed_c_diff_small_ver_offset_shift     (0)
#define YC_POST2DBPF_ADAPTH_2_bpfed_c_diff_large_hor_offset_mask      (0x7F000000)
#define YC_POST2DBPF_ADAPTH_2_bpfed_c_diff_large_ver_offset_mask      (0x007F0000)
#define YC_POST2DBPF_ADAPTH_2_bpfed_c_diff_small_hor_offset_mask      (0x00007F00)
#define YC_POST2DBPF_ADAPTH_2_bpfed_c_diff_small_ver_offset_mask      (0x0000007F)
#define YC_POST2DBPF_ADAPTH_2_bpfed_c_diff_large_hor_offset(data)     (0x7F000000&((data)<<24))
#define YC_POST2DBPF_ADAPTH_2_bpfed_c_diff_large_ver_offset(data)     (0x007F0000&((data)<<16))
#define YC_POST2DBPF_ADAPTH_2_bpfed_c_diff_small_hor_offset(data)     (0x00007F00&((data)<<8))
#define YC_POST2DBPF_ADAPTH_2_bpfed_c_diff_small_ver_offset(data)     (0x0000007F&(data))
#define YC_POST2DBPF_ADAPTH_2_get_bpfed_c_diff_large_hor_offset(data) ((0x7F000000&(data))>>24)
#define YC_POST2DBPF_ADAPTH_2_get_bpfed_c_diff_large_ver_offset(data) ((0x007F0000&(data))>>16)
#define YC_POST2DBPF_ADAPTH_2_get_bpfed_c_diff_small_hor_offset(data) ((0x00007F00&(data))>>8)
#define YC_POST2DBPF_ADAPTH_2_get_bpfed_c_diff_small_ver_offset(data) (0x0000007F&(data))


#define YC_POST2DBPF_ADAPTH_3                                         0x18019dc0
#define YC_POST2DBPF_ADAPTH_3_reg_addr                                "0xb8019dc0"
#define YC_POST2DBPF_ADAPTH_3_reg                                     0xb8019dc0
#define YC_POST2DBPF_ADAPTH_3_inst_addr                               "0x0370"
#define YC_POST2DBPF_ADAPTH_3_inst                                    0x0370
#define YC_POST2DBPF_ADAPTH_3_neighbor_vdiff_small_hor_offset_shift   (24)
#define YC_POST2DBPF_ADAPTH_3_neighbor_hdiff_small_ver_offset_shift   (16)
#define YC_POST2DBPF_ADAPTH_3_vspd_small_th_shift                     (8)
#define YC_POST2DBPF_ADAPTH_3_hdy_spd_small_th_shift                  (0)
#define YC_POST2DBPF_ADAPTH_3_neighbor_vdiff_small_hor_offset_mask    (0x3F000000)
#define YC_POST2DBPF_ADAPTH_3_neighbor_hdiff_small_ver_offset_mask    (0x003F0000)
#define YC_POST2DBPF_ADAPTH_3_vspd_small_th_mask                      (0x00001F00)
#define YC_POST2DBPF_ADAPTH_3_hdy_spd_small_th_mask                   (0x0000001F)
#define YC_POST2DBPF_ADAPTH_3_neighbor_vdiff_small_hor_offset(data)   (0x3F000000&((data)<<24))
#define YC_POST2DBPF_ADAPTH_3_neighbor_hdiff_small_ver_offset(data)   (0x003F0000&((data)<<16))
#define YC_POST2DBPF_ADAPTH_3_vspd_small_th(data)                     (0x00001F00&((data)<<8))
#define YC_POST2DBPF_ADAPTH_3_hdy_spd_small_th(data)                  (0x0000001F&(data))
#define YC_POST2DBPF_ADAPTH_3_get_neighbor_vdiff_small_hor_offset(data)  ((0x3F000000&(data))>>24)
#define YC_POST2DBPF_ADAPTH_3_get_neighbor_hdiff_small_ver_offset(data)  ((0x003F0000&(data))>>16)
#define YC_POST2DBPF_ADAPTH_3_get_vspd_small_th(data)                 ((0x00001F00&(data))>>8)
#define YC_POST2DBPF_ADAPTH_3_get_hdy_spd_small_th(data)              (0x0000001F&(data))


#define YC_POST2DBPF_ADAPTH_4                                         0x18019dc4
#define YC_POST2DBPF_ADAPTH_4_reg_addr                                "0xb8019dc4"
#define YC_POST2DBPF_ADAPTH_4_reg                                     0xb8019dc4
#define YC_POST2DBPF_ADAPTH_4_inst_addr                               "0x0371"
#define YC_POST2DBPF_ADAPTH_4_inst                                    0x0371
#define YC_POST2DBPF_ADAPTH_4_hvedge_diff_large_ratio_shift           (24)
#define YC_POST2DBPF_ADAPTH_4_vspd_large_th_shift                     (16)
#define YC_POST2DBPF_ADAPTH_4_hdy_spd_large_th_shift                  (8)
#define YC_POST2DBPF_ADAPTH_4_hdiff_tolerance_shift                   (0)
#define YC_POST2DBPF_ADAPTH_4_hvedge_diff_large_ratio_mask            (0x0F000000)
#define YC_POST2DBPF_ADAPTH_4_vspd_large_th_mask                      (0x007F0000)
#define YC_POST2DBPF_ADAPTH_4_hdy_spd_large_th_mask                   (0x00007F00)
#define YC_POST2DBPF_ADAPTH_4_hdiff_tolerance_mask                    (0x0000001F)
#define YC_POST2DBPF_ADAPTH_4_hvedge_diff_large_ratio(data)           (0x0F000000&((data)<<24))
#define YC_POST2DBPF_ADAPTH_4_vspd_large_th(data)                     (0x007F0000&((data)<<16))
#define YC_POST2DBPF_ADAPTH_4_hdy_spd_large_th(data)                  (0x00007F00&((data)<<8))
#define YC_POST2DBPF_ADAPTH_4_hdiff_tolerance(data)                   (0x0000001F&(data))
#define YC_POST2DBPF_ADAPTH_4_get_hvedge_diff_large_ratio(data)       ((0x0F000000&(data))>>24)
#define YC_POST2DBPF_ADAPTH_4_get_vspd_large_th(data)                 ((0x007F0000&(data))>>16)
#define YC_POST2DBPF_ADAPTH_4_get_hdy_spd_large_th(data)              ((0x00007F00&(data))>>8)
#define YC_POST2DBPF_ADAPTH_4_get_hdiff_tolerance(data)               (0x0000001F&(data))


#define YC_POST2DBPF_ADAPTH_5                                         0x18019dc8
#define YC_POST2DBPF_ADAPTH_5_reg_addr                                "0xb8019dc8"
#define YC_POST2DBPF_ADAPTH_5_reg                                     0xb8019dc8
#define YC_POST2DBPF_ADAPTH_5_inst_addr                               "0x0372"
#define YC_POST2DBPF_ADAPTH_5_inst                                    0x0372
#define YC_POST2DBPF_ADAPTH_5_vedge_hor_offset_shift                  (8)
#define YC_POST2DBPF_ADAPTH_5_hedge_ver_offset_shift                  (0)
#define YC_POST2DBPF_ADAPTH_5_vedge_hor_offset_mask                   (0x00007F00)
#define YC_POST2DBPF_ADAPTH_5_hedge_ver_offset_mask                   (0x0000007F)
#define YC_POST2DBPF_ADAPTH_5_vedge_hor_offset(data)                  (0x00007F00&((data)<<8))
#define YC_POST2DBPF_ADAPTH_5_hedge_ver_offset(data)                  (0x0000007F&(data))
#define YC_POST2DBPF_ADAPTH_5_get_vedge_hor_offset(data)              ((0x00007F00&(data))>>8)
#define YC_POST2DBPF_ADAPTH_5_get_hedge_ver_offset(data)              (0x0000007F&(data))


#define YC_POST2DBPF_ADAPTH_6                                         0x18019dcc
#define YC_POST2DBPF_ADAPTH_6_reg_addr                                "0xb8019dcc"
#define YC_POST2DBPF_ADAPTH_6_reg                                     0xb8019dcc
#define YC_POST2DBPF_ADAPTH_6_inst_addr                               "0x0373"
#define YC_POST2DBPF_ADAPTH_6_inst                                    0x0373
#define YC_POST2DBPF_ADAPTH_6_dia_spd_large_ver_offset_shift          (24)
#define YC_POST2DBPF_ADAPTH_6_dia_spd_large_th_small_hordiff_th_shift (16)
#define YC_POST2DBPF_ADAPTH_6_dia_spd_large_th_small_hordiff_offset_shift  (8)
#define YC_POST2DBPF_ADAPTH_6_dia_spd_large_th_base_shift             (0)
#define YC_POST2DBPF_ADAPTH_6_dia_spd_large_ver_offset_mask           (0x7F000000)
#define YC_POST2DBPF_ADAPTH_6_dia_spd_large_th_small_hordiff_th_mask  (0x003F0000)
#define YC_POST2DBPF_ADAPTH_6_dia_spd_large_th_small_hordiff_offset_mask  (0x0000FF00)
#define YC_POST2DBPF_ADAPTH_6_dia_spd_large_th_base_mask              (0x000000FF)
#define YC_POST2DBPF_ADAPTH_6_dia_spd_large_ver_offset(data)          (0x7F000000&((data)<<24))
#define YC_POST2DBPF_ADAPTH_6_dia_spd_large_th_small_hordiff_th(data) (0x003F0000&((data)<<16))
#define YC_POST2DBPF_ADAPTH_6_dia_spd_large_th_small_hordiff_offset(data)  (0x0000FF00&((data)<<8))
#define YC_POST2DBPF_ADAPTH_6_dia_spd_large_th_base(data)             (0x000000FF&(data))
#define YC_POST2DBPF_ADAPTH_6_get_dia_spd_large_ver_offset(data)      ((0x7F000000&(data))>>24)
#define YC_POST2DBPF_ADAPTH_6_get_dia_spd_large_th_small_hordiff_th(data)  ((0x003F0000&(data))>>16)
#define YC_POST2DBPF_ADAPTH_6_get_dia_spd_large_th_small_hordiff_offset(data)  ((0x0000FF00&(data))>>8)
#define YC_POST2DBPF_ADAPTH_6_get_dia_spd_large_th_base(data)         (0x000000FF&(data))


#define YC_POST2DBPF_ADAPTH_7                                         0x18019dd0
#define YC_POST2DBPF_ADAPTH_7_reg_addr                                "0xb8019dd0"
#define YC_POST2DBPF_ADAPTH_7_reg                                     0xb8019dd0
#define YC_POST2DBPF_ADAPTH_7_inst_addr                               "0x0374"
#define YC_POST2DBPF_ADAPTH_7_inst                                    0x0374
#define YC_POST2DBPF_ADAPTH_7_dual_ch_c_small_th_shift                (12)
#define YC_POST2DBPF_ADAPTH_7_dual_ch_cdiff_large_ratio_shift         (8)
#define YC_POST2DBPF_ADAPTH_7_dual_ch_cdiff_large_th_shift            (0)
#define YC_POST2DBPF_ADAPTH_7_dual_ch_c_small_th_mask                 (0x0001F000)
#define YC_POST2DBPF_ADAPTH_7_dual_ch_cdiff_large_ratio_mask          (0x00000F00)
#define YC_POST2DBPF_ADAPTH_7_dual_ch_cdiff_large_th_mask             (0x0000001F)
#define YC_POST2DBPF_ADAPTH_7_dual_ch_c_small_th(data)                (0x0001F000&((data)<<12))
#define YC_POST2DBPF_ADAPTH_7_dual_ch_cdiff_large_ratio(data)         (0x00000F00&((data)<<8))
#define YC_POST2DBPF_ADAPTH_7_dual_ch_cdiff_large_th(data)            (0x0000001F&(data))
#define YC_POST2DBPF_ADAPTH_7_get_dual_ch_c_small_th(data)            ((0x0001F000&(data))>>12)
#define YC_POST2DBPF_ADAPTH_7_get_dual_ch_cdiff_large_ratio(data)     ((0x00000F00&(data))>>8)
#define YC_POST2DBPF_ADAPTH_7_get_dual_ch_cdiff_large_th(data)        (0x0000001F&(data))


#define YC_POST2DBPF_ADAPTH_8                                         0x18019dd4
#define YC_POST2DBPF_ADAPTH_8_reg_addr                                "0xb8019dd4"
#define YC_POST2DBPF_ADAPTH_8_reg                                     0xb8019dd4
#define YC_POST2DBPF_ADAPTH_8_inst_addr                               "0x0375"
#define YC_POST2DBPF_ADAPTH_8_inst                                    0x0375
#define YC_POST2DBPF_ADAPTH_8_hdiff_much_larger_ratio_shift           (24)
#define YC_POST2DBPF_ADAPTH_8_hdiff_much_larger_th_shift              (16)
#define YC_POST2DBPF_ADAPTH_8_hdiff_vdiff_diff_larger_th_shift        (8)
#define YC_POST2DBPF_ADAPTH_8_hdiff_large_th_shift                    (0)
#define YC_POST2DBPF_ADAPTH_8_hdiff_much_larger_ratio_mask            (0x0F000000)
#define YC_POST2DBPF_ADAPTH_8_hdiff_much_larger_th_mask               (0x003F0000)
#define YC_POST2DBPF_ADAPTH_8_hdiff_vdiff_diff_larger_th_mask         (0x00003F00)
#define YC_POST2DBPF_ADAPTH_8_hdiff_large_th_mask                     (0x0000007F)
#define YC_POST2DBPF_ADAPTH_8_hdiff_much_larger_ratio(data)           (0x0F000000&((data)<<24))
#define YC_POST2DBPF_ADAPTH_8_hdiff_much_larger_th(data)              (0x003F0000&((data)<<16))
#define YC_POST2DBPF_ADAPTH_8_hdiff_vdiff_diff_larger_th(data)        (0x00003F00&((data)<<8))
#define YC_POST2DBPF_ADAPTH_8_hdiff_large_th(data)                    (0x0000007F&(data))
#define YC_POST2DBPF_ADAPTH_8_get_hdiff_much_larger_ratio(data)       ((0x0F000000&(data))>>24)
#define YC_POST2DBPF_ADAPTH_8_get_hdiff_much_larger_th(data)          ((0x003F0000&(data))>>16)
#define YC_POST2DBPF_ADAPTH_8_get_hdiff_vdiff_diff_larger_th(data)    ((0x00003F00&(data))>>8)
#define YC_POST2DBPF_ADAPTH_8_get_hdiff_large_th(data)                (0x0000007F&(data))


#define YC_POST2DBPF_ADAPTH_9                                         0x18019dd8
#define YC_POST2DBPF_ADAPTH_9_reg_addr                                "0xb8019dd8"
#define YC_POST2DBPF_ADAPTH_9_reg                                     0xb8019dd8
#define YC_POST2DBPF_ADAPTH_9_inst_addr                               "0x0376"
#define YC_POST2DBPF_ADAPTH_9_inst                                    0x0376
#define YC_POST2DBPF_ADAPTH_9_ver_color_tran_ver_offset_shift         (24)
#define YC_POST2DBPF_ADAPTH_9_ver_color_tran_ver_cdiff_small_th_shift (16)
#define YC_POST2DBPF_ADAPTH_9_ver_color_tran_hdiff_large_th_shift     (8)
#define YC_POST2DBPF_ADAPTH_9_hdiff_much_larger_hor_offset_shift      (0)
#define YC_POST2DBPF_ADAPTH_9_ver_color_tran_ver_offset_mask          (0x7F000000)
#define YC_POST2DBPF_ADAPTH_9_ver_color_tran_ver_cdiff_small_th_mask  (0x007F0000)
#define YC_POST2DBPF_ADAPTH_9_ver_color_tran_hdiff_large_th_mask      (0x00003F00)
#define YC_POST2DBPF_ADAPTH_9_hdiff_much_larger_hor_offset_mask       (0x0000007F)
#define YC_POST2DBPF_ADAPTH_9_ver_color_tran_ver_offset(data)         (0x7F000000&((data)<<24))
#define YC_POST2DBPF_ADAPTH_9_ver_color_tran_ver_cdiff_small_th(data) (0x007F0000&((data)<<16))
#define YC_POST2DBPF_ADAPTH_9_ver_color_tran_hdiff_large_th(data)     (0x00003F00&((data)<<8))
#define YC_POST2DBPF_ADAPTH_9_hdiff_much_larger_hor_offset(data)      (0x0000007F&(data))
#define YC_POST2DBPF_ADAPTH_9_get_ver_color_tran_ver_offset(data)     ((0x7F000000&(data))>>24)
#define YC_POST2DBPF_ADAPTH_9_get_ver_color_tran_ver_cdiff_small_th(data)  ((0x007F0000&(data))>>16)
#define YC_POST2DBPF_ADAPTH_9_get_ver_color_tran_hdiff_large_th(data) ((0x00003F00&(data))>>8)
#define YC_POST2DBPF_ADAPTH_9_get_hdiff_much_larger_hor_offset(data)  (0x0000007F&(data))


#define YC_POST2DBPF_ADAPTH_10                                        0x18019ddc
#define YC_POST2DBPF_ADAPTH_10_reg_addr                               "0xb8019ddc"
#define YC_POST2DBPF_ADAPTH_10_reg                                    0xb8019ddc
#define YC_POST2DBPF_ADAPTH_10_inst_addr                              "0x0377"
#define YC_POST2DBPF_ADAPTH_10_inst                                   0x0377
#define YC_POST2DBPF_ADAPTH_10_colorbar_detect_hor_offset_shift       (24)
#define YC_POST2DBPF_ADAPTH_10_colorbar_detect_ver_offset_shift       (16)
#define YC_POST2DBPF_ADAPTH_10_colorbar_hdiff_large_th_shift          (8)
#define YC_POST2DBPF_ADAPTH_10_colorbar_vdiff_small_th_shift          (0)
#define YC_POST2DBPF_ADAPTH_10_colorbar_detect_hor_offset_mask        (0x7F000000)
#define YC_POST2DBPF_ADAPTH_10_colorbar_detect_ver_offset_mask        (0x007F0000)
#define YC_POST2DBPF_ADAPTH_10_colorbar_hdiff_large_th_mask           (0x00003F00)
#define YC_POST2DBPF_ADAPTH_10_colorbar_vdiff_small_th_mask           (0x0000003F)
#define YC_POST2DBPF_ADAPTH_10_colorbar_detect_hor_offset(data)       (0x7F000000&((data)<<24))
#define YC_POST2DBPF_ADAPTH_10_colorbar_detect_ver_offset(data)       (0x007F0000&((data)<<16))
#define YC_POST2DBPF_ADAPTH_10_colorbar_hdiff_large_th(data)          (0x00003F00&((data)<<8))
#define YC_POST2DBPF_ADAPTH_10_colorbar_vdiff_small_th(data)          (0x0000003F&(data))
#define YC_POST2DBPF_ADAPTH_10_get_colorbar_detect_hor_offset(data)   ((0x7F000000&(data))>>24)
#define YC_POST2DBPF_ADAPTH_10_get_colorbar_detect_ver_offset(data)   ((0x007F0000&(data))>>16)
#define YC_POST2DBPF_ADAPTH_10_get_colorbar_hdiff_large_th(data)      ((0x00003F00&(data))>>8)
#define YC_POST2DBPF_ADAPTH_10_get_colorbar_vdiff_small_th(data)      (0x0000003F&(data))


#define YC_POST2DBPF_ADAPTH_11                                        0x18019de0
#define YC_POST2DBPF_ADAPTH_11_reg_addr                               "0xb8019de0"
#define YC_POST2DBPF_ADAPTH_11_reg                                    0xb8019de0
#define YC_POST2DBPF_ADAPTH_11_inst_addr                              "0x0378"
#define YC_POST2DBPF_ADAPTH_11_inst                                   0x0378
#define YC_POST2DBPF_ADAPTH_11_ver_avoid_th_c_shift                   (28)
#define YC_POST2DBPF_ADAPTH_11_ver_avoid_th_y_shift                   (24)
#define YC_POST2DBPF_ADAPTH_11_smooth_detect_ver_offset_shift         (16)
#define YC_POST2DBPF_ADAPTH_11_smooth_hdiff_small_th_shift            (8)
#define YC_POST2DBPF_ADAPTH_11_smooth_vdiff_small_th_shift            (0)
#define YC_POST2DBPF_ADAPTH_11_ver_avoid_th_c_mask                    (0xF0000000)
#define YC_POST2DBPF_ADAPTH_11_ver_avoid_th_y_mask                    (0x0F000000)
#define YC_POST2DBPF_ADAPTH_11_smooth_detect_ver_offset_mask          (0x007F0000)
#define YC_POST2DBPF_ADAPTH_11_smooth_hdiff_small_th_mask             (0x00003F00)
#define YC_POST2DBPF_ADAPTH_11_smooth_vdiff_small_th_mask             (0x0000003F)
#define YC_POST2DBPF_ADAPTH_11_ver_avoid_th_c(data)                   (0xF0000000&((data)<<28))
#define YC_POST2DBPF_ADAPTH_11_ver_avoid_th_y(data)                   (0x0F000000&((data)<<24))
#define YC_POST2DBPF_ADAPTH_11_smooth_detect_ver_offset(data)         (0x007F0000&((data)<<16))
#define YC_POST2DBPF_ADAPTH_11_smooth_hdiff_small_th(data)            (0x00003F00&((data)<<8))
#define YC_POST2DBPF_ADAPTH_11_smooth_vdiff_small_th(data)            (0x0000003F&(data))
#define YC_POST2DBPF_ADAPTH_11_get_ver_avoid_th_c(data)               ((0xF0000000&(data))>>28)
#define YC_POST2DBPF_ADAPTH_11_get_ver_avoid_th_y(data)               ((0x0F000000&(data))>>24)
#define YC_POST2DBPF_ADAPTH_11_get_smooth_detect_ver_offset(data)     ((0x007F0000&(data))>>16)
#define YC_POST2DBPF_ADAPTH_11_get_smooth_hdiff_small_th(data)        ((0x00003F00&(data))>>8)
#define YC_POST2DBPF_ADAPTH_11_get_smooth_vdiff_small_th(data)        (0x0000003F&(data))


#define YC_POST2DBPF_ADAPTH_12                                        0x18019de4
#define YC_POST2DBPF_ADAPTH_12_reg_addr                               "0xb8019de4"
#define YC_POST2DBPF_ADAPTH_12_reg                                    0xb8019de4
#define YC_POST2DBPF_ADAPTH_12_inst_addr                              "0x0379"
#define YC_POST2DBPF_ADAPTH_12_inst                                   0x0379
#define YC_POST2DBPF_ADAPTH_12_vedge_avoid_en_shift                   (31)
#define YC_POST2DBPF_ADAPTH_12_vcdiff_large_diff_th_shift             (24)
#define YC_POST2DBPF_ADAPTH_12_vcdiff_large_ratio_shift               (20)
#define YC_POST2DBPF_ADAPTH_12_v2sides_diff_large_ratio_shift         (16)
#define YC_POST2DBPF_ADAPTH_12_v2sides_diff_large_th_shift            (8)
#define YC_POST2DBPF_ADAPTH_12_v2sides_gray_diff_small_th_shift       (0)
#define YC_POST2DBPF_ADAPTH_12_vedge_avoid_en_mask                    (0x80000000)
#define YC_POST2DBPF_ADAPTH_12_vcdiff_large_diff_th_mask              (0x3F000000)
#define YC_POST2DBPF_ADAPTH_12_vcdiff_large_ratio_mask                (0x00F00000)
#define YC_POST2DBPF_ADAPTH_12_v2sides_diff_large_ratio_mask          (0x000F0000)
#define YC_POST2DBPF_ADAPTH_12_v2sides_diff_large_th_mask             (0x00007F00)
#define YC_POST2DBPF_ADAPTH_12_v2sides_gray_diff_small_th_mask        (0x0000001F)
#define YC_POST2DBPF_ADAPTH_12_vedge_avoid_en(data)                   (0x80000000&((data)<<31))
#define YC_POST2DBPF_ADAPTH_12_vcdiff_large_diff_th(data)             (0x3F000000&((data)<<24))
#define YC_POST2DBPF_ADAPTH_12_vcdiff_large_ratio(data)               (0x00F00000&((data)<<20))
#define YC_POST2DBPF_ADAPTH_12_v2sides_diff_large_ratio(data)         (0x000F0000&((data)<<16))
#define YC_POST2DBPF_ADAPTH_12_v2sides_diff_large_th(data)            (0x00007F00&((data)<<8))
#define YC_POST2DBPF_ADAPTH_12_v2sides_gray_diff_small_th(data)       (0x0000001F&(data))
#define YC_POST2DBPF_ADAPTH_12_get_vedge_avoid_en(data)               ((0x80000000&(data))>>31)
#define YC_POST2DBPF_ADAPTH_12_get_vcdiff_large_diff_th(data)         ((0x3F000000&(data))>>24)
#define YC_POST2DBPF_ADAPTH_12_get_vcdiff_large_ratio(data)           ((0x00F00000&(data))>>20)
#define YC_POST2DBPF_ADAPTH_12_get_v2sides_diff_large_ratio(data)     ((0x000F0000&(data))>>16)
#define YC_POST2DBPF_ADAPTH_12_get_v2sides_diff_large_th(data)        ((0x00007F00&(data))>>8)
#define YC_POST2DBPF_ADAPTH_12_get_v2sides_gray_diff_small_th(data)   (0x0000001F&(data))


#define YC_POST2DBPF_ADAPTH_13                                        0x18019de8
#define YC_POST2DBPF_ADAPTH_13_reg_addr                               "0xb8019de8"
#define YC_POST2DBPF_ADAPTH_13_reg                                    0xb8019de8
#define YC_POST2DBPF_ADAPTH_13_inst_addr                              "0x037A"
#define YC_POST2DBPF_ADAPTH_13_inst                                   0x037A
#define YC_POST2DBPF_ADAPTH_13_ignore_th_c_shift                      (4)
#define YC_POST2DBPF_ADAPTH_13_ignore_th_y_shift                      (0)
#define YC_POST2DBPF_ADAPTH_13_ignore_th_c_mask                       (0x000000F0)
#define YC_POST2DBPF_ADAPTH_13_ignore_th_y_mask                       (0x0000000F)
#define YC_POST2DBPF_ADAPTH_13_ignore_th_c(data)                      (0x000000F0&((data)<<4))
#define YC_POST2DBPF_ADAPTH_13_ignore_th_y(data)                      (0x0000000F&(data))
#define YC_POST2DBPF_ADAPTH_13_get_ignore_th_c(data)                  ((0x000000F0&(data))>>4)
#define YC_POST2DBPF_ADAPTH_13_get_ignore_th_y(data)                  (0x0000000F&(data))


#define POSTP_MF_COMPENSATION_CTRL1                                   0x18019e14
#define POSTP_MF_COMPENSATION_CTRL1_reg_addr                          "0xb8019e14"
#define POSTP_MF_COMPENSATION_CTRL1_reg                               0xb8019e14
#define POSTP_MF_COMPENSATION_CTRL1_inst_addr                         "0x0385"
#define POSTP_MF_COMPENSATION_CTRL1_inst                              0x0385
#define POSTP_MF_COMPENSATION_CTRL1_ver_cedge_sum_th_shift            (24)
#define POSTP_MF_COMPENSATION_CTRL1_ver_cedge_single_th_shift         (16)
#define POSTP_MF_COMPENSATION_CTRL1_ver_cedge_en_shift                (15)
#define POSTP_MF_COMPENSATION_CTRL1_mf_en_shift                       (13)
#define POSTP_MF_COMPENSATION_CTRL1_ma0_cnt_th_shift                  (8)
#define POSTP_MF_COMPENSATION_CTRL1_point_type_coring_lv_shift        (4)
#define POSTP_MF_COMPENSATION_CTRL1_vline_len_3_sel_shift             (3)
#define POSTP_MF_COMPENSATION_CTRL1_vline_con_en_shift                (2)
#define POSTP_MF_COMPENSATION_CTRL1_cdiff_small_con_en_shift          (1)
#define POSTP_MF_COMPENSATION_CTRL1_ma0_con_en_shift                  (0)
#define POSTP_MF_COMPENSATION_CTRL1_ver_cedge_sum_th_mask             (0x7F000000)
#define POSTP_MF_COMPENSATION_CTRL1_ver_cedge_single_th_mask          (0x003F0000)
#define POSTP_MF_COMPENSATION_CTRL1_ver_cedge_en_mask                 (0x00008000)
#define POSTP_MF_COMPENSATION_CTRL1_mf_en_mask                        (0x00002000)
#define POSTP_MF_COMPENSATION_CTRL1_ma0_cnt_th_mask                   (0x00001F00)
#define POSTP_MF_COMPENSATION_CTRL1_point_type_coring_lv_mask         (0x000000F0)
#define POSTP_MF_COMPENSATION_CTRL1_vline_len_3_sel_mask              (0x00000008)
#define POSTP_MF_COMPENSATION_CTRL1_vline_con_en_mask                 (0x00000004)
#define POSTP_MF_COMPENSATION_CTRL1_cdiff_small_con_en_mask           (0x00000002)
#define POSTP_MF_COMPENSATION_CTRL1_ma0_con_en_mask                   (0x00000001)
#define POSTP_MF_COMPENSATION_CTRL1_ver_cedge_sum_th(data)            (0x7F000000&((data)<<24))
#define POSTP_MF_COMPENSATION_CTRL1_ver_cedge_single_th(data)         (0x003F0000&((data)<<16))
#define POSTP_MF_COMPENSATION_CTRL1_ver_cedge_en(data)                (0x00008000&((data)<<15))
#define POSTP_MF_COMPENSATION_CTRL1_mf_en(data)                       (0x00002000&((data)<<13))
#define POSTP_MF_COMPENSATION_CTRL1_ma0_cnt_th(data)                  (0x00001F00&((data)<<8))
#define POSTP_MF_COMPENSATION_CTRL1_point_type_coring_lv(data)        (0x000000F0&((data)<<4))
#define POSTP_MF_COMPENSATION_CTRL1_vline_len_3_sel(data)             (0x00000008&((data)<<3))
#define POSTP_MF_COMPENSATION_CTRL1_vline_con_en(data)                (0x00000004&((data)<<2))
#define POSTP_MF_COMPENSATION_CTRL1_cdiff_small_con_en(data)          (0x00000002&((data)<<1))
#define POSTP_MF_COMPENSATION_CTRL1_ma0_con_en(data)                  (0x00000001&(data))
#define POSTP_MF_COMPENSATION_CTRL1_get_ver_cedge_sum_th(data)        ((0x7F000000&(data))>>24)
#define POSTP_MF_COMPENSATION_CTRL1_get_ver_cedge_single_th(data)     ((0x003F0000&(data))>>16)
#define POSTP_MF_COMPENSATION_CTRL1_get_ver_cedge_en(data)            ((0x00008000&(data))>>15)
#define POSTP_MF_COMPENSATION_CTRL1_get_mf_en(data)                   ((0x00002000&(data))>>13)
#define POSTP_MF_COMPENSATION_CTRL1_get_ma0_cnt_th(data)              ((0x00001F00&(data))>>8)
#define POSTP_MF_COMPENSATION_CTRL1_get_point_type_coring_lv(data)    ((0x000000F0&(data))>>4)
#define POSTP_MF_COMPENSATION_CTRL1_get_vline_len_3_sel(data)         ((0x00000008&(data))>>3)
#define POSTP_MF_COMPENSATION_CTRL1_get_vline_con_en(data)            ((0x00000004&(data))>>2)
#define POSTP_MF_COMPENSATION_CTRL1_get_cdiff_small_con_en(data)      ((0x00000002&(data))>>1)
#define POSTP_MF_COMPENSATION_CTRL1_get_ma0_con_en(data)              (0x00000001&(data))


#define POSTP_MF_COMPENSATION_CTRL2                                   0x18019e18
#define POSTP_MF_COMPENSATION_CTRL2_reg_addr                          "0xb8019e18"
#define POSTP_MF_COMPENSATION_CTRL2_reg                               0xb8019e18
#define POSTP_MF_COMPENSATION_CTRL2_inst_addr                         "0x0386"
#define POSTP_MF_COMPENSATION_CTRL2_inst                              0x0386
#define POSTP_MF_COMPENSATION_CTRL2_cdiff_small_sum_th_shift          (12)
#define POSTP_MF_COMPENSATION_CTRL2_cdiff_small_single_th_shift       (4)
#define POSTP_MF_COMPENSATION_CTRL2_cdiff_small_len_shift             (0)
#define POSTP_MF_COMPENSATION_CTRL2_cdiff_small_sum_th_mask           (0x0007F000)
#define POSTP_MF_COMPENSATION_CTRL2_cdiff_small_single_th_mask        (0x000003F0)
#define POSTP_MF_COMPENSATION_CTRL2_cdiff_small_len_mask              (0x0000000F)
#define POSTP_MF_COMPENSATION_CTRL2_cdiff_small_sum_th(data)          (0x0007F000&((data)<<12))
#define POSTP_MF_COMPENSATION_CTRL2_cdiff_small_single_th(data)       (0x000003F0&((data)<<4))
#define POSTP_MF_COMPENSATION_CTRL2_cdiff_small_len(data)             (0x0000000F&(data))
#define POSTP_MF_COMPENSATION_CTRL2_get_cdiff_small_sum_th(data)      ((0x0007F000&(data))>>12)
#define POSTP_MF_COMPENSATION_CTRL2_get_cdiff_small_single_th(data)   ((0x000003F0&(data))>>4)
#define POSTP_MF_COMPENSATION_CTRL2_get_cdiff_small_len(data)         (0x0000000F&(data))


#define YC2D_POSTPK2_CTRL1                                            0x18019e1c
#define YC2D_POSTPK2_CTRL1_reg_addr                                   "0xb8019e1c"
#define YC2D_POSTPK2_CTRL1_reg                                        0xb8019e1c
#define YC2D_POSTPK2_CTRL1_inst_addr                                  "0x0387"
#define YC2D_POSTPK2_CTRL1_inst                                       0x0387
#define YC2D_POSTPK2_CTRL1_postpk_prelpf_mode_shift                   (9)
#define YC2D_POSTPK2_CTRL1_postpk_prelpf_en_shift                     (8)
#define YC2D_POSTPK2_CTRL1_postpk_alphablend_en_shift                 (5)
#define YC2D_POSTPK2_CTRL1_postpk_dnoise_en_shift                     (4)
#define YC2D_POSTPK2_CTRL1_postpk_adap_mode_shift                     (2)
#define YC2D_POSTPK2_CTRL1_postpk_adappk_en_shift                     (1)
#define YC2D_POSTPK2_CTRL1_postpk_en_shift                            (0)
#define YC2D_POSTPK2_CTRL1_postpk_prelpf_mode_mask                    (0x00000200)
#define YC2D_POSTPK2_CTRL1_postpk_prelpf_en_mask                      (0x00000100)
#define YC2D_POSTPK2_CTRL1_postpk_alphablend_en_mask                  (0x00000020)
#define YC2D_POSTPK2_CTRL1_postpk_dnoise_en_mask                      (0x00000010)
#define YC2D_POSTPK2_CTRL1_postpk_adap_mode_mask                      (0x0000000C)
#define YC2D_POSTPK2_CTRL1_postpk_adappk_en_mask                      (0x00000002)
#define YC2D_POSTPK2_CTRL1_postpk_en_mask                             (0x00000001)
#define YC2D_POSTPK2_CTRL1_postpk_prelpf_mode(data)                   (0x00000200&((data)<<9))
#define YC2D_POSTPK2_CTRL1_postpk_prelpf_en(data)                     (0x00000100&((data)<<8))
#define YC2D_POSTPK2_CTRL1_postpk_alphablend_en(data)                 (0x00000020&((data)<<5))
#define YC2D_POSTPK2_CTRL1_postpk_dnoise_en(data)                     (0x00000010&((data)<<4))
#define YC2D_POSTPK2_CTRL1_postpk_adap_mode(data)                     (0x0000000C&((data)<<2))
#define YC2D_POSTPK2_CTRL1_postpk_adappk_en(data)                     (0x00000002&((data)<<1))
#define YC2D_POSTPK2_CTRL1_postpk_en(data)                            (0x00000001&(data))
#define YC2D_POSTPK2_CTRL1_get_postpk_prelpf_mode(data)               ((0x00000200&(data))>>9)
#define YC2D_POSTPK2_CTRL1_get_postpk_prelpf_en(data)                 ((0x00000100&(data))>>8)
#define YC2D_POSTPK2_CTRL1_get_postpk_alphablend_en(data)             ((0x00000020&(data))>>5)
#define YC2D_POSTPK2_CTRL1_get_postpk_dnoise_en(data)                 ((0x00000010&(data))>>4)
#define YC2D_POSTPK2_CTRL1_get_postpk_adap_mode(data)                 ((0x0000000C&(data))>>2)
#define YC2D_POSTPK2_CTRL1_get_postpk_adappk_en(data)                 ((0x00000002&(data))>>1)
#define YC2D_POSTPK2_CTRL1_get_postpk_en(data)                        (0x00000001&(data))


#define YC2D_POSTPK2_ADAP1                                            0x18019e20
#define YC2D_POSTPK2_ADAP1_reg_addr                                   "0xb8019e20"
#define YC2D_POSTPK2_ADAP1_reg                                        0xb8019e20
#define YC2D_POSTPK2_ADAP1_inst_addr                                  "0x0388"
#define YC2D_POSTPK2_ADAP1_inst                                       0x0388
#define YC2D_POSTPK2_ADAP1_postpk_c_stepbit_shift                     (24)
#define YC2D_POSTPK2_ADAP1_postpk_c_lwbnd_shift                       (16)
#define YC2D_POSTPK2_ADAP1_postpk_y_stepbit_shift                     (8)
#define YC2D_POSTPK2_ADAP1_postpk_y_lwbnd_shift                       (0)
#define YC2D_POSTPK2_ADAP1_postpk_c_stepbit_mask                      (0x07000000)
#define YC2D_POSTPK2_ADAP1_postpk_c_lwbnd_mask                        (0x00FF0000)
#define YC2D_POSTPK2_ADAP1_postpk_y_stepbit_mask                      (0x00000700)
#define YC2D_POSTPK2_ADAP1_postpk_y_lwbnd_mask                        (0x000000FF)
#define YC2D_POSTPK2_ADAP1_postpk_c_stepbit(data)                     (0x07000000&((data)<<24))
#define YC2D_POSTPK2_ADAP1_postpk_c_lwbnd(data)                       (0x00FF0000&((data)<<16))
#define YC2D_POSTPK2_ADAP1_postpk_y_stepbit(data)                     (0x00000700&((data)<<8))
#define YC2D_POSTPK2_ADAP1_postpk_y_lwbnd(data)                       (0x000000FF&(data))
#define YC2D_POSTPK2_ADAP1_get_postpk_c_stepbit(data)                 ((0x07000000&(data))>>24)
#define YC2D_POSTPK2_ADAP1_get_postpk_c_lwbnd(data)                   ((0x00FF0000&(data))>>16)
#define YC2D_POSTPK2_ADAP1_get_postpk_y_stepbit(data)                 ((0x00000700&(data))>>8)
#define YC2D_POSTPK2_ADAP1_get_postpk_y_lwbnd(data)                   (0x000000FF&(data))


#define YC2D_POSTPK2_DNOISE1                                          0x18019e24
#define YC2D_POSTPK2_DNOISE1_reg_addr                                 "0xb8019e24"
#define YC2D_POSTPK2_DNOISE1_reg                                      0xb8019e24
#define YC2D_POSTPK2_DNOISE1_inst_addr                                "0x0389"
#define YC2D_POSTPK2_DNOISE1_inst                                     0x0389
#define YC2D_POSTPK2_DNOISE1_postpk_lv_upbnd_shift                    (16)
#define YC2D_POSTPK2_DNOISE1_postpk_lv_sft_shift                      (8)
#define YC2D_POSTPK2_DNOISE1_postpk_lv_th_shift                       (0)
#define YC2D_POSTPK2_DNOISE1_postpk_lv_upbnd_mask                     (0x00FF0000)
#define YC2D_POSTPK2_DNOISE1_postpk_lv_sft_mask                       (0x00000700)
#define YC2D_POSTPK2_DNOISE1_postpk_lv_th_mask                        (0x000000FF)
#define YC2D_POSTPK2_DNOISE1_postpk_lv_upbnd(data)                    (0x00FF0000&((data)<<16))
#define YC2D_POSTPK2_DNOISE1_postpk_lv_sft(data)                      (0x00000700&((data)<<8))
#define YC2D_POSTPK2_DNOISE1_postpk_lv_th(data)                       (0x000000FF&(data))
#define YC2D_POSTPK2_DNOISE1_get_postpk_lv_upbnd(data)                ((0x00FF0000&(data))>>16)
#define YC2D_POSTPK2_DNOISE1_get_postpk_lv_sft(data)                  ((0x00000700&(data))>>8)
#define YC2D_POSTPK2_DNOISE1_get_postpk_lv_th(data)                   (0x000000FF&(data))


#define YC2D_POSTPK2_FILTER_0                                         0x18019e28
#define YC2D_POSTPK2_FILTER_0_reg_addr                                "0xb8019e28"
#define YC2D_POSTPK2_FILTER_0_reg                                     0xb8019e28
#define YC2D_POSTPK2_FILTER_0_inst_addr                               "0x038A"
#define YC2D_POSTPK2_FILTER_0_inst                                    0x038A
#define YC2D_POSTPK2_FILTER_0_postpk_c0_shift                         (20)
#define YC2D_POSTPK2_FILTER_0_postpk_c1_shift                         (8)
#define YC2D_POSTPK2_FILTER_0_postpk_c2_shift                         (0)
#define YC2D_POSTPK2_FILTER_0_postpk_c0_mask                          (0x1FF00000)
#define YC2D_POSTPK2_FILTER_0_postpk_c1_mask                          (0x0001FF00)
#define YC2D_POSTPK2_FILTER_0_postpk_c2_mask                          (0x000000FF)
#define YC2D_POSTPK2_FILTER_0_postpk_c0(data)                         (0x1FF00000&((data)<<20))
#define YC2D_POSTPK2_FILTER_0_postpk_c1(data)                         (0x0001FF00&((data)<<8))
#define YC2D_POSTPK2_FILTER_0_postpk_c2(data)                         (0x000000FF&(data))
#define YC2D_POSTPK2_FILTER_0_get_postpk_c0(data)                     ((0x1FF00000&(data))>>20)
#define YC2D_POSTPK2_FILTER_0_get_postpk_c1(data)                     ((0x0001FF00&(data))>>8)
#define YC2D_POSTPK2_FILTER_0_get_postpk_c2(data)                     (0x000000FF&(data))


#define YC2D_POSTPK2_GAIN                                             0x18019e2c
#define YC2D_POSTPK2_GAIN_reg_addr                                    "0xb8019e2c"
#define YC2D_POSTPK2_GAIN_reg                                         0xb8019e2c
#define YC2D_POSTPK2_GAIN_inst_addr                                   "0x038B"
#define YC2D_POSTPK2_GAIN_inst                                        0x038B
#define YC2D_POSTPK2_GAIN_postpk_gain_pos_shift                       (8)
#define YC2D_POSTPK2_GAIN_postpk_gain_neg_shift                       (0)
#define YC2D_POSTPK2_GAIN_postpk_gain_pos_mask                        (0x0000FF00)
#define YC2D_POSTPK2_GAIN_postpk_gain_neg_mask                        (0x000000FF)
#define YC2D_POSTPK2_GAIN_postpk_gain_pos(data)                       (0x0000FF00&((data)<<8))
#define YC2D_POSTPK2_GAIN_postpk_gain_neg(data)                       (0x000000FF&(data))
#define YC2D_POSTPK2_GAIN_get_postpk_gain_pos(data)                   ((0x0000FF00&(data))>>8)
#define YC2D_POSTPK2_GAIN_get_postpk_gain_neg(data)                   (0x000000FF&(data))


#define YC2D_POSTPK2_BOUND                                            0x18019e30
#define YC2D_POSTPK2_BOUND_reg_addr                                   "0xb8019e30"
#define YC2D_POSTPK2_BOUND_reg                                        0xb8019e30
#define YC2D_POSTPK2_BOUND_inst_addr                                  "0x038C"
#define YC2D_POSTPK2_BOUND_inst                                       0x038C
#define YC2D_POSTPK2_BOUND_postpk_hv_pos_shift                        (18)
#define YC2D_POSTPK2_BOUND_postpk_hv_neg_shift                        (8)
#define YC2D_POSTPK2_BOUND_postpk_lv_shift                            (0)
#define YC2D_POSTPK2_BOUND_postpk_hv_pos_mask                         (0x0FFC0000)
#define YC2D_POSTPK2_BOUND_postpk_hv_neg_mask                         (0x0003FF00)
#define YC2D_POSTPK2_BOUND_postpk_lv_mask                             (0x000000FF)
#define YC2D_POSTPK2_BOUND_postpk_hv_pos(data)                        (0x0FFC0000&((data)<<18))
#define YC2D_POSTPK2_BOUND_postpk_hv_neg(data)                        (0x0003FF00&((data)<<8))
#define YC2D_POSTPK2_BOUND_postpk_lv(data)                            (0x000000FF&(data))
#define YC2D_POSTPK2_BOUND_get_postpk_hv_pos(data)                    ((0x0FFC0000&(data))>>18)
#define YC2D_POSTPK2_BOUND_get_postpk_hv_neg(data)                    ((0x0003FF00&(data))>>8)
#define YC2D_POSTPK2_BOUND_get_postpk_lv(data)                        (0x000000FF&(data))


#define POSTP_DLTI_CTRL1                                              0x18019e34
#define POSTP_DLTI_CTRL1_reg_addr                                     "0xb8019e34"
#define POSTP_DLTI_CTRL1_reg                                          0xb8019e34
#define POSTP_DLTI_CTRL1_inst_addr                                    "0x038D"
#define POSTP_DLTI_CTRL1_inst                                         0x038D
#define POSTP_DLTI_CTRL1_dlti_ffd2_ratio_shift                        (28)
#define POSTP_DLTI_CTRL1_dlti_ffd2_en_shift                           (24)
#define POSTP_DLTI_CTRL1_dlti_ffd1_ratio_shift                        (20)
#define POSTP_DLTI_CTRL1_dlti_ffd1_th_shift                           (12)
#define POSTP_DLTI_CTRL1_dlti_maxlen_shift                            (8)
#define POSTP_DLTI_CTRL1_dlti_pnth_shift                              (1)
#define POSTP_DLTI_CTRL1_dlti_en_shift                                (0)
#define POSTP_DLTI_CTRL1_dlti_ffd2_ratio_mask                         (0xF0000000)
#define POSTP_DLTI_CTRL1_dlti_ffd2_en_mask                            (0x01000000)
#define POSTP_DLTI_CTRL1_dlti_ffd1_ratio_mask                         (0x00F00000)
#define POSTP_DLTI_CTRL1_dlti_ffd1_th_mask                            (0x0001F000)
#define POSTP_DLTI_CTRL1_dlti_maxlen_mask                             (0x00000700)
#define POSTP_DLTI_CTRL1_dlti_pnth_mask                               (0x000000FE)
#define POSTP_DLTI_CTRL1_dlti_en_mask                                 (0x00000001)
#define POSTP_DLTI_CTRL1_dlti_ffd2_ratio(data)                        (0xF0000000&((data)<<28))
#define POSTP_DLTI_CTRL1_dlti_ffd2_en(data)                           (0x01000000&((data)<<24))
#define POSTP_DLTI_CTRL1_dlti_ffd1_ratio(data)                        (0x00F00000&((data)<<20))
#define POSTP_DLTI_CTRL1_dlti_ffd1_th(data)                           (0x0001F000&((data)<<12))
#define POSTP_DLTI_CTRL1_dlti_maxlen(data)                            (0x00000700&((data)<<8))
#define POSTP_DLTI_CTRL1_dlti_pnth(data)                              (0x000000FE&((data)<<1))
#define POSTP_DLTI_CTRL1_dlti_en(data)                                (0x00000001&(data))
#define POSTP_DLTI_CTRL1_get_dlti_ffd2_ratio(data)                    ((0xF0000000&(data))>>28)
#define POSTP_DLTI_CTRL1_get_dlti_ffd2_en(data)                       ((0x01000000&(data))>>24)
#define POSTP_DLTI_CTRL1_get_dlti_ffd1_ratio(data)                    ((0x00F00000&(data))>>20)
#define POSTP_DLTI_CTRL1_get_dlti_ffd1_th(data)                       ((0x0001F000&(data))>>12)
#define POSTP_DLTI_CTRL1_get_dlti_maxlen(data)                        ((0x00000700&(data))>>8)
#define POSTP_DLTI_CTRL1_get_dlti_pnth(data)                          ((0x000000FE&(data))>>1)
#define POSTP_DLTI_CTRL1_get_dlti_en(data)                            (0x00000001&(data))


#define POSTP_DLTI_CTRL2                                              0x18019e38
#define POSTP_DLTI_CTRL2_reg_addr                                     "0xb8019e38"
#define POSTP_DLTI_CTRL2_reg                                          0xb8019e38
#define POSTP_DLTI_CTRL2_inst_addr                                    "0x038E"
#define POSTP_DLTI_CTRL2_inst                                         0x038E
#define POSTP_DLTI_CTRL2_dlti_d1_cp_shift_shift                       (28)
#define POSTP_DLTI_CTRL2_dlti_dcp_th_shift                            (20)
#define POSTP_DLTI_CTRL2_dlti_tn_blend_mode_shift                     (17)
#define POSTP_DLTI_CTRL2_dlti_tn_blend_en_shift                       (16)
#define POSTP_DLTI_CTRL2_dlti_ovc_en_shift                            (12)
#define POSTP_DLTI_CTRL2_dlti_can_shift_shift                         (8)
#define POSTP_DLTI_CTRL2_dlti_ffd2_range2l_shift                      (4)
#define POSTP_DLTI_CTRL2_dlti_ffd2_range2r_shift                      (0)
#define POSTP_DLTI_CTRL2_dlti_d1_cp_shift_mask                        (0xF0000000)
#define POSTP_DLTI_CTRL2_dlti_dcp_th_mask                             (0x03F00000)
#define POSTP_DLTI_CTRL2_dlti_tn_blend_mode_mask                      (0x00020000)
#define POSTP_DLTI_CTRL2_dlti_tn_blend_en_mask                        (0x00010000)
#define POSTP_DLTI_CTRL2_dlti_ovc_en_mask                             (0x00001000)
#define POSTP_DLTI_CTRL2_dlti_can_shift_mask                          (0x00000F00)
#define POSTP_DLTI_CTRL2_dlti_ffd2_range2l_mask                       (0x000000F0)
#define POSTP_DLTI_CTRL2_dlti_ffd2_range2r_mask                       (0x0000000F)
#define POSTP_DLTI_CTRL2_dlti_d1_cp_shift(data)                       (0xF0000000&((data)<<28))
#define POSTP_DLTI_CTRL2_dlti_dcp_th(data)                            (0x03F00000&((data)<<20))
#define POSTP_DLTI_CTRL2_dlti_tn_blend_mode(data)                     (0x00020000&((data)<<17))
#define POSTP_DLTI_CTRL2_dlti_tn_blend_en(data)                       (0x00010000&((data)<<16))
#define POSTP_DLTI_CTRL2_dlti_ovc_en(data)                            (0x00001000&((data)<<12))
#define POSTP_DLTI_CTRL2_dlti_can_shift(data)                         (0x00000F00&((data)<<8))
#define POSTP_DLTI_CTRL2_dlti_ffd2_range2l(data)                      (0x000000F0&((data)<<4))
#define POSTP_DLTI_CTRL2_dlti_ffd2_range2r(data)                      (0x0000000F&(data))
#define POSTP_DLTI_CTRL2_get_dlti_d1_cp_shift(data)                   ((0xF0000000&(data))>>28)
#define POSTP_DLTI_CTRL2_get_dlti_dcp_th(data)                        ((0x03F00000&(data))>>20)
#define POSTP_DLTI_CTRL2_get_dlti_tn_blend_mode(data)                 ((0x00020000&(data))>>17)
#define POSTP_DLTI_CTRL2_get_dlti_tn_blend_en(data)                   ((0x00010000&(data))>>16)
#define POSTP_DLTI_CTRL2_get_dlti_ovc_en(data)                        ((0x00001000&(data))>>12)
#define POSTP_DLTI_CTRL2_get_dlti_can_shift(data)                     ((0x00000F00&(data))>>8)
#define POSTP_DLTI_CTRL2_get_dlti_ffd2_range2l(data)                  ((0x000000F0&(data))>>4)
#define POSTP_DLTI_CTRL2_get_dlti_ffd2_range2r(data)                  (0x0000000F&(data))


#define POSTP_DLTI_CTRL3                                              0x18019e3c
#define POSTP_DLTI_CTRL3_reg_addr                                     "0xb8019e3c"
#define POSTP_DLTI_CTRL3_reg                                          0xb8019e3c
#define POSTP_DLTI_CTRL3_inst_addr                                    "0x038F"
#define POSTP_DLTI_CTRL3_inst                                         0x038F
#define POSTP_DLTI_CTRL3_dlti_cchange_srcwei_offset_2_shift           (28)
#define POSTP_DLTI_CTRL3_dlti_cchange_srcwei_offset_1_shift           (24)
#define POSTP_DLTI_CTRL3_dlti_uv_diff_th_2_shift                      (16)
#define POSTP_DLTI_CTRL3_dlti_uv_diff_th_1_shift                      (8)
#define POSTP_DLTI_CTRL3_dlti_cchange_len_shift                       (4)
#define POSTP_DLTI_CTRL3_dlti_cchange_corr_en_shift                   (0)
#define POSTP_DLTI_CTRL3_dlti_cchange_srcwei_offset_2_mask            (0xF0000000)
#define POSTP_DLTI_CTRL3_dlti_cchange_srcwei_offset_1_mask            (0x0F000000)
#define POSTP_DLTI_CTRL3_dlti_uv_diff_th_2_mask                       (0x00FF0000)
#define POSTP_DLTI_CTRL3_dlti_uv_diff_th_1_mask                       (0x0000FF00)
#define POSTP_DLTI_CTRL3_dlti_cchange_len_mask                        (0x00000070)
#define POSTP_DLTI_CTRL3_dlti_cchange_corr_en_mask                    (0x00000001)
#define POSTP_DLTI_CTRL3_dlti_cchange_srcwei_offset_2(data)           (0xF0000000&((data)<<28))
#define POSTP_DLTI_CTRL3_dlti_cchange_srcwei_offset_1(data)           (0x0F000000&((data)<<24))
#define POSTP_DLTI_CTRL3_dlti_uv_diff_th_2(data)                      (0x00FF0000&((data)<<16))
#define POSTP_DLTI_CTRL3_dlti_uv_diff_th_1(data)                      (0x0000FF00&((data)<<8))
#define POSTP_DLTI_CTRL3_dlti_cchange_len(data)                       (0x00000070&((data)<<4))
#define POSTP_DLTI_CTRL3_dlti_cchange_corr_en(data)                   (0x00000001&(data))
#define POSTP_DLTI_CTRL3_get_dlti_cchange_srcwei_offset_2(data)       ((0xF0000000&(data))>>28)
#define POSTP_DLTI_CTRL3_get_dlti_cchange_srcwei_offset_1(data)       ((0x0F000000&(data))>>24)
#define POSTP_DLTI_CTRL3_get_dlti_uv_diff_th_2(data)                  ((0x00FF0000&(data))>>16)
#define POSTP_DLTI_CTRL3_get_dlti_uv_diff_th_1(data)                  ((0x0000FF00&(data))>>8)
#define POSTP_DLTI_CTRL3_get_dlti_cchange_len(data)                   ((0x00000070&(data))>>4)
#define POSTP_DLTI_CTRL3_get_dlti_cchange_corr_en(data)               (0x00000001&(data))


#define POSTP_DLTI_TNGAIN_GAIN_TAB1                                   0x18019e40
#define POSTP_DLTI_TNGAIN_GAIN_TAB1_reg_addr                          "0xb8019e40"
#define POSTP_DLTI_TNGAIN_GAIN_TAB1_reg                               0xb8019e40
#define POSTP_DLTI_TNGAIN_GAIN_TAB1_inst_addr                         "0x0390"
#define POSTP_DLTI_TNGAIN_GAIN_TAB1_inst                              0x0390
#define POSTP_DLTI_TNGAIN_GAIN_TAB1_dlti_tngain7_shift                (28)
#define POSTP_DLTI_TNGAIN_GAIN_TAB1_dlti_tngain6_shift                (24)
#define POSTP_DLTI_TNGAIN_GAIN_TAB1_dlti_tngain5_shift                (20)
#define POSTP_DLTI_TNGAIN_GAIN_TAB1_dlti_tngain4_shift                (16)
#define POSTP_DLTI_TNGAIN_GAIN_TAB1_dlti_tngain3_shift                (12)
#define POSTP_DLTI_TNGAIN_GAIN_TAB1_dlti_tngain2_shift                (8)
#define POSTP_DLTI_TNGAIN_GAIN_TAB1_dlti_tngain1_shift                (4)
#define POSTP_DLTI_TNGAIN_GAIN_TAB1_dlti_tngain0_shift                (0)
#define POSTP_DLTI_TNGAIN_GAIN_TAB1_dlti_tngain7_mask                 (0xF0000000)
#define POSTP_DLTI_TNGAIN_GAIN_TAB1_dlti_tngain6_mask                 (0x0F000000)
#define POSTP_DLTI_TNGAIN_GAIN_TAB1_dlti_tngain5_mask                 (0x00F00000)
#define POSTP_DLTI_TNGAIN_GAIN_TAB1_dlti_tngain4_mask                 (0x000F0000)
#define POSTP_DLTI_TNGAIN_GAIN_TAB1_dlti_tngain3_mask                 (0x0000F000)
#define POSTP_DLTI_TNGAIN_GAIN_TAB1_dlti_tngain2_mask                 (0x00000F00)
#define POSTP_DLTI_TNGAIN_GAIN_TAB1_dlti_tngain1_mask                 (0x000000F0)
#define POSTP_DLTI_TNGAIN_GAIN_TAB1_dlti_tngain0_mask                 (0x0000000F)
#define POSTP_DLTI_TNGAIN_GAIN_TAB1_dlti_tngain7(data)                (0xF0000000&((data)<<28))
#define POSTP_DLTI_TNGAIN_GAIN_TAB1_dlti_tngain6(data)                (0x0F000000&((data)<<24))
#define POSTP_DLTI_TNGAIN_GAIN_TAB1_dlti_tngain5(data)                (0x00F00000&((data)<<20))
#define POSTP_DLTI_TNGAIN_GAIN_TAB1_dlti_tngain4(data)                (0x000F0000&((data)<<16))
#define POSTP_DLTI_TNGAIN_GAIN_TAB1_dlti_tngain3(data)                (0x0000F000&((data)<<12))
#define POSTP_DLTI_TNGAIN_GAIN_TAB1_dlti_tngain2(data)                (0x00000F00&((data)<<8))
#define POSTP_DLTI_TNGAIN_GAIN_TAB1_dlti_tngain1(data)                (0x000000F0&((data)<<4))
#define POSTP_DLTI_TNGAIN_GAIN_TAB1_dlti_tngain0(data)                (0x0000000F&(data))
#define POSTP_DLTI_TNGAIN_GAIN_TAB1_get_dlti_tngain7(data)            ((0xF0000000&(data))>>28)
#define POSTP_DLTI_TNGAIN_GAIN_TAB1_get_dlti_tngain6(data)            ((0x0F000000&(data))>>24)
#define POSTP_DLTI_TNGAIN_GAIN_TAB1_get_dlti_tngain5(data)            ((0x00F00000&(data))>>20)
#define POSTP_DLTI_TNGAIN_GAIN_TAB1_get_dlti_tngain4(data)            ((0x000F0000&(data))>>16)
#define POSTP_DLTI_TNGAIN_GAIN_TAB1_get_dlti_tngain3(data)            ((0x0000F000&(data))>>12)
#define POSTP_DLTI_TNGAIN_GAIN_TAB1_get_dlti_tngain2(data)            ((0x00000F00&(data))>>8)
#define POSTP_DLTI_TNGAIN_GAIN_TAB1_get_dlti_tngain1(data)            ((0x000000F0&(data))>>4)
#define POSTP_DLTI_TNGAIN_GAIN_TAB1_get_dlti_tngain0(data)            (0x0000000F&(data))


#define POSTP_DLTI_TNGAIN_GAIN_TAB2                                   0x18019e44
#define POSTP_DLTI_TNGAIN_GAIN_TAB2_reg_addr                          "0xb8019e44"
#define POSTP_DLTI_TNGAIN_GAIN_TAB2_reg                               0xb8019e44
#define POSTP_DLTI_TNGAIN_GAIN_TAB2_inst_addr                         "0x0391"
#define POSTP_DLTI_TNGAIN_GAIN_TAB2_inst                              0x0391
#define POSTP_DLTI_TNGAIN_GAIN_TAB2_dlti_tngain14_shift               (24)
#define POSTP_DLTI_TNGAIN_GAIN_TAB2_dlti_tngain13_shift               (20)
#define POSTP_DLTI_TNGAIN_GAIN_TAB2_dlti_tngain12_shift               (16)
#define POSTP_DLTI_TNGAIN_GAIN_TAB2_dlti_tngain11_shift               (12)
#define POSTP_DLTI_TNGAIN_GAIN_TAB2_dlti_tngain10_shift               (8)
#define POSTP_DLTI_TNGAIN_GAIN_TAB2_dlti_tngain9_shift                (4)
#define POSTP_DLTI_TNGAIN_GAIN_TAB2_dlti_tngain8_shift                (0)
#define POSTP_DLTI_TNGAIN_GAIN_TAB2_dlti_tngain14_mask                (0x0F000000)
#define POSTP_DLTI_TNGAIN_GAIN_TAB2_dlti_tngain13_mask                (0x00F00000)
#define POSTP_DLTI_TNGAIN_GAIN_TAB2_dlti_tngain12_mask                (0x000F0000)
#define POSTP_DLTI_TNGAIN_GAIN_TAB2_dlti_tngain11_mask                (0x0000F000)
#define POSTP_DLTI_TNGAIN_GAIN_TAB2_dlti_tngain10_mask                (0x00000F00)
#define POSTP_DLTI_TNGAIN_GAIN_TAB2_dlti_tngain9_mask                 (0x000000F0)
#define POSTP_DLTI_TNGAIN_GAIN_TAB2_dlti_tngain8_mask                 (0x0000000F)
#define POSTP_DLTI_TNGAIN_GAIN_TAB2_dlti_tngain14(data)               (0x0F000000&((data)<<24))
#define POSTP_DLTI_TNGAIN_GAIN_TAB2_dlti_tngain13(data)               (0x00F00000&((data)<<20))
#define POSTP_DLTI_TNGAIN_GAIN_TAB2_dlti_tngain12(data)               (0x000F0000&((data)<<16))
#define POSTP_DLTI_TNGAIN_GAIN_TAB2_dlti_tngain11(data)               (0x0000F000&((data)<<12))
#define POSTP_DLTI_TNGAIN_GAIN_TAB2_dlti_tngain10(data)               (0x00000F00&((data)<<8))
#define POSTP_DLTI_TNGAIN_GAIN_TAB2_dlti_tngain9(data)                (0x000000F0&((data)<<4))
#define POSTP_DLTI_TNGAIN_GAIN_TAB2_dlti_tngain8(data)                (0x0000000F&(data))
#define POSTP_DLTI_TNGAIN_GAIN_TAB2_get_dlti_tngain14(data)           ((0x0F000000&(data))>>24)
#define POSTP_DLTI_TNGAIN_GAIN_TAB2_get_dlti_tngain13(data)           ((0x00F00000&(data))>>20)
#define POSTP_DLTI_TNGAIN_GAIN_TAB2_get_dlti_tngain12(data)           ((0x000F0000&(data))>>16)
#define POSTP_DLTI_TNGAIN_GAIN_TAB2_get_dlti_tngain11(data)           ((0x0000F000&(data))>>12)
#define POSTP_DLTI_TNGAIN_GAIN_TAB2_get_dlti_tngain10(data)           ((0x00000F00&(data))>>8)
#define POSTP_DLTI_TNGAIN_GAIN_TAB2_get_dlti_tngain9(data)            ((0x000000F0&(data))>>4)
#define POSTP_DLTI_TNGAIN_GAIN_TAB2_get_dlti_tngain8(data)            (0x0000000F&(data))


#define POSTP_DLTI_TNGAIN_OFFSET_TAB1                                 0x18019e48
#define POSTP_DLTI_TNGAIN_OFFSET_TAB1_reg_addr                        "0xb8019e48"
#define POSTP_DLTI_TNGAIN_OFFSET_TAB1_reg                             0xb8019e48
#define POSTP_DLTI_TNGAIN_OFFSET_TAB1_inst_addr                       "0x0392"
#define POSTP_DLTI_TNGAIN_OFFSET_TAB1_inst                            0x0392
#define POSTP_DLTI_TNGAIN_OFFSET_TAB1_dlti_tnoffset7_shift            (28)
#define POSTP_DLTI_TNGAIN_OFFSET_TAB1_dlti_tnoffset6_shift            (24)
#define POSTP_DLTI_TNGAIN_OFFSET_TAB1_dlti_tnoffset5_shift            (20)
#define POSTP_DLTI_TNGAIN_OFFSET_TAB1_dlti_tnoffset4_shift            (16)
#define POSTP_DLTI_TNGAIN_OFFSET_TAB1_dlti_tnoffset3_shift            (12)
#define POSTP_DLTI_TNGAIN_OFFSET_TAB1_dlti_tnoffset2_shift            (8)
#define POSTP_DLTI_TNGAIN_OFFSET_TAB1_dlti_tnoffset1_shift            (4)
#define POSTP_DLTI_TNGAIN_OFFSET_TAB1_dlti_tnoffset0_shift            (0)
#define POSTP_DLTI_TNGAIN_OFFSET_TAB1_dlti_tnoffset7_mask             (0xF0000000)
#define POSTP_DLTI_TNGAIN_OFFSET_TAB1_dlti_tnoffset6_mask             (0x0F000000)
#define POSTP_DLTI_TNGAIN_OFFSET_TAB1_dlti_tnoffset5_mask             (0x00F00000)
#define POSTP_DLTI_TNGAIN_OFFSET_TAB1_dlti_tnoffset4_mask             (0x000F0000)
#define POSTP_DLTI_TNGAIN_OFFSET_TAB1_dlti_tnoffset3_mask             (0x0000F000)
#define POSTP_DLTI_TNGAIN_OFFSET_TAB1_dlti_tnoffset2_mask             (0x00000F00)
#define POSTP_DLTI_TNGAIN_OFFSET_TAB1_dlti_tnoffset1_mask             (0x000000F0)
#define POSTP_DLTI_TNGAIN_OFFSET_TAB1_dlti_tnoffset0_mask             (0x0000000F)
#define POSTP_DLTI_TNGAIN_OFFSET_TAB1_dlti_tnoffset7(data)            (0xF0000000&((data)<<28))
#define POSTP_DLTI_TNGAIN_OFFSET_TAB1_dlti_tnoffset6(data)            (0x0F000000&((data)<<24))
#define POSTP_DLTI_TNGAIN_OFFSET_TAB1_dlti_tnoffset5(data)            (0x00F00000&((data)<<20))
#define POSTP_DLTI_TNGAIN_OFFSET_TAB1_dlti_tnoffset4(data)            (0x000F0000&((data)<<16))
#define POSTP_DLTI_TNGAIN_OFFSET_TAB1_dlti_tnoffset3(data)            (0x0000F000&((data)<<12))
#define POSTP_DLTI_TNGAIN_OFFSET_TAB1_dlti_tnoffset2(data)            (0x00000F00&((data)<<8))
#define POSTP_DLTI_TNGAIN_OFFSET_TAB1_dlti_tnoffset1(data)            (0x000000F0&((data)<<4))
#define POSTP_DLTI_TNGAIN_OFFSET_TAB1_dlti_tnoffset0(data)            (0x0000000F&(data))
#define POSTP_DLTI_TNGAIN_OFFSET_TAB1_get_dlti_tnoffset7(data)        ((0xF0000000&(data))>>28)
#define POSTP_DLTI_TNGAIN_OFFSET_TAB1_get_dlti_tnoffset6(data)        ((0x0F000000&(data))>>24)
#define POSTP_DLTI_TNGAIN_OFFSET_TAB1_get_dlti_tnoffset5(data)        ((0x00F00000&(data))>>20)
#define POSTP_DLTI_TNGAIN_OFFSET_TAB1_get_dlti_tnoffset4(data)        ((0x000F0000&(data))>>16)
#define POSTP_DLTI_TNGAIN_OFFSET_TAB1_get_dlti_tnoffset3(data)        ((0x0000F000&(data))>>12)
#define POSTP_DLTI_TNGAIN_OFFSET_TAB1_get_dlti_tnoffset2(data)        ((0x00000F00&(data))>>8)
#define POSTP_DLTI_TNGAIN_OFFSET_TAB1_get_dlti_tnoffset1(data)        ((0x000000F0&(data))>>4)
#define POSTP_DLTI_TNGAIN_OFFSET_TAB1_get_dlti_tnoffset0(data)        (0x0000000F&(data))


#define POSTP_DLTI_TNGAIN_OFFSET_TAB2                                 0x18019e4c
#define POSTP_DLTI_TNGAIN_OFFSET_TAB2_reg_addr                        "0xb8019e4c"
#define POSTP_DLTI_TNGAIN_OFFSET_TAB2_reg                             0xb8019e4c
#define POSTP_DLTI_TNGAIN_OFFSET_TAB2_inst_addr                       "0x0393"
#define POSTP_DLTI_TNGAIN_OFFSET_TAB2_inst                            0x0393
#define POSTP_DLTI_TNGAIN_OFFSET_TAB2_dlti_tnoffset14_shift           (24)
#define POSTP_DLTI_TNGAIN_OFFSET_TAB2_dlti_tnoffset13_shift           (20)
#define POSTP_DLTI_TNGAIN_OFFSET_TAB2_dlti_tnoffset12_shift           (16)
#define POSTP_DLTI_TNGAIN_OFFSET_TAB2_dlti_tnoffset11_shift           (12)
#define POSTP_DLTI_TNGAIN_OFFSET_TAB2_dlti_tnoffset10_shift           (8)
#define POSTP_DLTI_TNGAIN_OFFSET_TAB2_dlti_tnoffset9_shift            (4)
#define POSTP_DLTI_TNGAIN_OFFSET_TAB2_dlti_tnoffset8_shift            (0)
#define POSTP_DLTI_TNGAIN_OFFSET_TAB2_dlti_tnoffset14_mask            (0x0F000000)
#define POSTP_DLTI_TNGAIN_OFFSET_TAB2_dlti_tnoffset13_mask            (0x00F00000)
#define POSTP_DLTI_TNGAIN_OFFSET_TAB2_dlti_tnoffset12_mask            (0x000F0000)
#define POSTP_DLTI_TNGAIN_OFFSET_TAB2_dlti_tnoffset11_mask            (0x0000F000)
#define POSTP_DLTI_TNGAIN_OFFSET_TAB2_dlti_tnoffset10_mask            (0x00000F00)
#define POSTP_DLTI_TNGAIN_OFFSET_TAB2_dlti_tnoffset9_mask             (0x000000F0)
#define POSTP_DLTI_TNGAIN_OFFSET_TAB2_dlti_tnoffset8_mask             (0x0000000F)
#define POSTP_DLTI_TNGAIN_OFFSET_TAB2_dlti_tnoffset14(data)           (0x0F000000&((data)<<24))
#define POSTP_DLTI_TNGAIN_OFFSET_TAB2_dlti_tnoffset13(data)           (0x00F00000&((data)<<20))
#define POSTP_DLTI_TNGAIN_OFFSET_TAB2_dlti_tnoffset12(data)           (0x000F0000&((data)<<16))
#define POSTP_DLTI_TNGAIN_OFFSET_TAB2_dlti_tnoffset11(data)           (0x0000F000&((data)<<12))
#define POSTP_DLTI_TNGAIN_OFFSET_TAB2_dlti_tnoffset10(data)           (0x00000F00&((data)<<8))
#define POSTP_DLTI_TNGAIN_OFFSET_TAB2_dlti_tnoffset9(data)            (0x000000F0&((data)<<4))
#define POSTP_DLTI_TNGAIN_OFFSET_TAB2_dlti_tnoffset8(data)            (0x0000000F&(data))
#define POSTP_DLTI_TNGAIN_OFFSET_TAB2_get_dlti_tnoffset14(data)       ((0x0F000000&(data))>>24)
#define POSTP_DLTI_TNGAIN_OFFSET_TAB2_get_dlti_tnoffset13(data)       ((0x00F00000&(data))>>20)
#define POSTP_DLTI_TNGAIN_OFFSET_TAB2_get_dlti_tnoffset12(data)       ((0x000F0000&(data))>>16)
#define POSTP_DLTI_TNGAIN_OFFSET_TAB2_get_dlti_tnoffset11(data)       ((0x0000F000&(data))>>12)
#define POSTP_DLTI_TNGAIN_OFFSET_TAB2_get_dlti_tnoffset10(data)       ((0x00000F00&(data))>>8)
#define POSTP_DLTI_TNGAIN_OFFSET_TAB2_get_dlti_tnoffset9(data)        ((0x000000F0&(data))>>4)
#define POSTP_DLTI_TNGAIN_OFFSET_TAB2_get_dlti_tnoffset8(data)        (0x0000000F&(data))


#define POSTP_DLTI_PK_SELECT                                          0x18019e50
#define POSTP_DLTI_PK_SELECT_reg_addr                                 "0xb8019e50"
#define POSTP_DLTI_PK_SELECT_reg                                      0xb8019e50
#define POSTP_DLTI_PK_SELECT_inst_addr                                "0x0394"
#define POSTP_DLTI_PK_SELECT_inst                                     0x0394
#define POSTP_DLTI_PK_SELECT_pd_sel_dlti_cnt_th2_shift                (16)
#define POSTP_DLTI_PK_SELECT_pd_sel_dlti_cnt_th1_shift                (12)
#define POSTP_DLTI_PK_SELECT_pd_sel_dlti_diff_th_shift                (4)
#define POSTP_DLTI_PK_SELECT_pd_sel_shift                             (0)
#define POSTP_DLTI_PK_SELECT_pd_sel_dlti_cnt_th2_mask                 (0x00070000)
#define POSTP_DLTI_PK_SELECT_pd_sel_dlti_cnt_th1_mask                 (0x00007000)
#define POSTP_DLTI_PK_SELECT_pd_sel_dlti_diff_th_mask                 (0x00000FF0)
#define POSTP_DLTI_PK_SELECT_pd_sel_mask                              (0x00000007)
#define POSTP_DLTI_PK_SELECT_pd_sel_dlti_cnt_th2(data)                (0x00070000&((data)<<16))
#define POSTP_DLTI_PK_SELECT_pd_sel_dlti_cnt_th1(data)                (0x00007000&((data)<<12))
#define POSTP_DLTI_PK_SELECT_pd_sel_dlti_diff_th(data)                (0x00000FF0&((data)<<4))
#define POSTP_DLTI_PK_SELECT_pd_sel(data)                             (0x00000007&(data))
#define POSTP_DLTI_PK_SELECT_get_pd_sel_dlti_cnt_th2(data)            ((0x00070000&(data))>>16)
#define POSTP_DLTI_PK_SELECT_get_pd_sel_dlti_cnt_th1(data)            ((0x00007000&(data))>>12)
#define POSTP_DLTI_PK_SELECT_get_pd_sel_dlti_diff_th(data)            ((0x00000FF0&(data))>>4)
#define POSTP_DLTI_PK_SELECT_get_pd_sel(data)                         (0x00000007&(data))


#define POSTP_3D2DALPHA_BLEND_CTRL                                    0x18019e54
#define POSTP_3D2DALPHA_BLEND_CTRL_reg_addr                           "0xb8019e54"
#define POSTP_3D2DALPHA_BLEND_CTRL_reg                                0xb8019e54
#define POSTP_3D2DALPHA_BLEND_CTRL_inst_addr                          "0x0395"
#define POSTP_3D2DALPHA_BLEND_CTRL_inst                               0x0395
#define POSTP_3D2DALPHA_BLEND_CTRL_pk_alpha_2d_weight_shift           (28)
#define POSTP_3D2DALPHA_BLEND_CTRL_pk_alpha_bld_weight_shift          (26)
#define POSTP_3D2DALPHA_BLEND_CTRL_pk_alpha_3d_weight_shift           (24)
#define POSTP_3D2DALPHA_BLEND_CTRL_dlti_alpha_2d_weight_shift         (20)
#define POSTP_3D2DALPHA_BLEND_CTRL_dlti_alpha_bld_weight_shift        (18)
#define POSTP_3D2DALPHA_BLEND_CTRL_dlti_alpha_3d_weight_shift         (16)
#define POSTP_3D2DALPHA_BLEND_CTRL_mf_alpha_2d_weight_shift           (12)
#define POSTP_3D2DALPHA_BLEND_CTRL_mf_alpha_bld_weight_shift          (10)
#define POSTP_3D2DALPHA_BLEND_CTRL_mf_alpha_3d_weight_shift           (8)
#define POSTP_3D2DALPHA_BLEND_CTRL_pk_alpha_2d_weight_mask            (0x30000000)
#define POSTP_3D2DALPHA_BLEND_CTRL_pk_alpha_bld_weight_mask           (0x0C000000)
#define POSTP_3D2DALPHA_BLEND_CTRL_pk_alpha_3d_weight_mask            (0x03000000)
#define POSTP_3D2DALPHA_BLEND_CTRL_dlti_alpha_2d_weight_mask          (0x00300000)
#define POSTP_3D2DALPHA_BLEND_CTRL_dlti_alpha_bld_weight_mask         (0x000C0000)
#define POSTP_3D2DALPHA_BLEND_CTRL_dlti_alpha_3d_weight_mask          (0x00030000)
#define POSTP_3D2DALPHA_BLEND_CTRL_mf_alpha_2d_weight_mask            (0x00003000)
#define POSTP_3D2DALPHA_BLEND_CTRL_mf_alpha_bld_weight_mask           (0x00000C00)
#define POSTP_3D2DALPHA_BLEND_CTRL_mf_alpha_3d_weight_mask            (0x00000300)
#define POSTP_3D2DALPHA_BLEND_CTRL_pk_alpha_2d_weight(data)           (0x30000000&((data)<<28))
#define POSTP_3D2DALPHA_BLEND_CTRL_pk_alpha_bld_weight(data)          (0x0C000000&((data)<<26))
#define POSTP_3D2DALPHA_BLEND_CTRL_pk_alpha_3d_weight(data)           (0x03000000&((data)<<24))
#define POSTP_3D2DALPHA_BLEND_CTRL_dlti_alpha_2d_weight(data)         (0x00300000&((data)<<20))
#define POSTP_3D2DALPHA_BLEND_CTRL_dlti_alpha_bld_weight(data)        (0x000C0000&((data)<<18))
#define POSTP_3D2DALPHA_BLEND_CTRL_dlti_alpha_3d_weight(data)         (0x00030000&((data)<<16))
#define POSTP_3D2DALPHA_BLEND_CTRL_mf_alpha_2d_weight(data)           (0x00003000&((data)<<12))
#define POSTP_3D2DALPHA_BLEND_CTRL_mf_alpha_bld_weight(data)          (0x00000C00&((data)<<10))
#define POSTP_3D2DALPHA_BLEND_CTRL_mf_alpha_3d_weight(data)           (0x00000300&((data)<<8))
#define POSTP_3D2DALPHA_BLEND_CTRL_get_pk_alpha_2d_weight(data)       ((0x30000000&(data))>>28)
#define POSTP_3D2DALPHA_BLEND_CTRL_get_pk_alpha_bld_weight(data)      ((0x0C000000&(data))>>26)
#define POSTP_3D2DALPHA_BLEND_CTRL_get_pk_alpha_3d_weight(data)       ((0x03000000&(data))>>24)
#define POSTP_3D2DALPHA_BLEND_CTRL_get_dlti_alpha_2d_weight(data)     ((0x00300000&(data))>>20)
#define POSTP_3D2DALPHA_BLEND_CTRL_get_dlti_alpha_bld_weight(data)    ((0x000C0000&(data))>>18)
#define POSTP_3D2DALPHA_BLEND_CTRL_get_dlti_alpha_3d_weight(data)     ((0x00030000&(data))>>16)
#define POSTP_3D2DALPHA_BLEND_CTRL_get_mf_alpha_2d_weight(data)       ((0x00003000&(data))>>12)
#define POSTP_3D2DALPHA_BLEND_CTRL_get_mf_alpha_bld_weight(data)      ((0x00000C00&(data))>>10)
#define POSTP_3D2DALPHA_BLEND_CTRL_get_mf_alpha_3d_weight(data)       ((0x00000300&(data))>>8)


#define POSTP_NTSC443_LPF                                             0x18019e60
#define POSTP_NTSC443_LPF_reg_addr                                    "0xb8019e60"
#define POSTP_NTSC443_LPF_reg                                         0xb8019e60
#define POSTP_NTSC443_LPF_inst_addr                                   "0x0398"
#define POSTP_NTSC443_LPF_inst                                        0x0398
#define POSTP_NTSC443_LPF_ntsc443_lpf_shift                           (31)
#define POSTP_NTSC443_LPF_ntsc443_lpf_ext_shift                       (4)
#define POSTP_NTSC443_LPF_ntsc443_lpf_th_y_shift                      (0)
#define POSTP_NTSC443_LPF_ntsc443_lpf_mask                            (0x80000000)
#define POSTP_NTSC443_LPF_ntsc443_lpf_ext_mask                        (0x00000030)
#define POSTP_NTSC443_LPF_ntsc443_lpf_th_y_mask                       (0x00000007)
#define POSTP_NTSC443_LPF_ntsc443_lpf(data)                           (0x80000000&((data)<<31))
#define POSTP_NTSC443_LPF_ntsc443_lpf_ext(data)                       (0x00000030&((data)<<4))
#define POSTP_NTSC443_LPF_ntsc443_lpf_th_y(data)                      (0x00000007&(data))
#define POSTP_NTSC443_LPF_get_ntsc443_lpf(data)                       ((0x80000000&(data))>>31)
#define POSTP_NTSC443_LPF_get_ntsc443_lpf_ext(data)                   ((0x00000030&(data))>>4)
#define POSTP_NTSC443_LPF_get_ntsc443_lpf_th_y(data)                  (0x00000007&(data))


#define SPNR_DEBUGMODE                                                0x18019e64
#define SPNR_DEBUGMODE_reg_addr                                       "0xb8019e64"
#define SPNR_DEBUGMODE_reg                                            0xb8019e64
#define SPNR_DEBUGMODE_inst_addr                                      "0x0399"
#define SPNR_DEBUGMODE_inst                                           0x0399
#define SPNR_DEBUGMODE_cp_sweightydebug_shift                         (0)
#define SPNR_DEBUGMODE_cp_sweightydebug_mask                          (0x00000003)
#define SPNR_DEBUGMODE_cp_sweightydebug(data)                         (0x00000003&(data))
#define SPNR_DEBUGMODE_get_cp_sweightydebug(data)                     (0x00000003&(data))


#define SPNR_CP_CTRL                                                  0x18019e68
#define SPNR_CP_CTRL_reg_addr                                         "0xb8019e68"
#define SPNR_CP_CTRL_reg                                              0xb8019e68
#define SPNR_CP_CTRL_inst_addr                                        "0x039A"
#define SPNR_CP_CTRL_inst                                             0x039A
#define SPNR_CP_CTRL_cp_sresultweight_shift                           (24)
#define SPNR_CP_CTRL_cp_zoranfiltersizey_shift                        (22)
#define SPNR_CP_CTRL_cp_zoranweight2y_shift                           (20)
#define SPNR_CP_CTRL_cp_zoranweight3y_shift                           (18)
#define SPNR_CP_CTRL_cp_zoranweight4y_shift                           (16)
#define SPNR_CP_CTRL_cp_spatialenablec_shift                          (1)
#define SPNR_CP_CTRL_cp_spatialenabley_shift                          (0)
#define SPNR_CP_CTRL_cp_sresultweight_mask                            (0x07000000)
#define SPNR_CP_CTRL_cp_zoranfiltersizey_mask                         (0x00C00000)
#define SPNR_CP_CTRL_cp_zoranweight2y_mask                            (0x00300000)
#define SPNR_CP_CTRL_cp_zoranweight3y_mask                            (0x000C0000)
#define SPNR_CP_CTRL_cp_zoranweight4y_mask                            (0x00030000)
#define SPNR_CP_CTRL_cp_spatialenablec_mask                           (0x00000002)
#define SPNR_CP_CTRL_cp_spatialenabley_mask                           (0x00000001)
#define SPNR_CP_CTRL_cp_sresultweight(data)                           (0x07000000&((data)<<24))
#define SPNR_CP_CTRL_cp_zoranfiltersizey(data)                        (0x00C00000&((data)<<22))
#define SPNR_CP_CTRL_cp_zoranweight2y(data)                           (0x00300000&((data)<<20))
#define SPNR_CP_CTRL_cp_zoranweight3y(data)                           (0x000C0000&((data)<<18))
#define SPNR_CP_CTRL_cp_zoranweight4y(data)                           (0x00030000&((data)<<16))
#define SPNR_CP_CTRL_cp_spatialenablec(data)                          (0x00000002&((data)<<1))
#define SPNR_CP_CTRL_cp_spatialenabley(data)                          (0x00000001&(data))
#define SPNR_CP_CTRL_get_cp_sresultweight(data)                       ((0x07000000&(data))>>24)
#define SPNR_CP_CTRL_get_cp_zoranfiltersizey(data)                    ((0x00C00000&(data))>>22)
#define SPNR_CP_CTRL_get_cp_zoranweight2y(data)                       ((0x00300000&(data))>>20)
#define SPNR_CP_CTRL_get_cp_zoranweight3y(data)                       ((0x000C0000&(data))>>18)
#define SPNR_CP_CTRL_get_cp_zoranweight4y(data)                       ((0x00030000&(data))>>16)
#define SPNR_CP_CTRL_get_cp_spatialenablec(data)                      ((0x00000002&(data))>>1)
#define SPNR_CP_CTRL_get_cp_spatialenabley(data)                      (0x00000001&(data))


#define SPNR_SPATIAL_TH                                               0x18019e6c
#define SPNR_SPATIAL_TH_reg_addr                                      "0xb8019e6c"
#define SPNR_SPATIAL_TH_reg                                           0xb8019e6c
#define SPNR_SPATIAL_TH_inst_addr                                     "0x039B"
#define SPNR_SPATIAL_TH_inst                                          0x039B
#define SPNR_SPATIAL_TH_cp_spatialthlyx4_shift                        (16)
#define SPNR_SPATIAL_TH_cp_spatialthlyx2_shift                        (8)
#define SPNR_SPATIAL_TH_cp_spatialthly_shift                          (0)
#define SPNR_SPATIAL_TH_cp_spatialthlyx4_mask                         (0x00FF0000)
#define SPNR_SPATIAL_TH_cp_spatialthlyx2_mask                         (0x0000FF00)
#define SPNR_SPATIAL_TH_cp_spatialthly_mask                           (0x000000FF)
#define SPNR_SPATIAL_TH_cp_spatialthlyx4(data)                        (0x00FF0000&((data)<<16))
#define SPNR_SPATIAL_TH_cp_spatialthlyx2(data)                        (0x0000FF00&((data)<<8))
#define SPNR_SPATIAL_TH_cp_spatialthly(data)                          (0x000000FF&(data))
#define SPNR_SPATIAL_TH_get_cp_spatialthlyx4(data)                    ((0x00FF0000&(data))>>16)
#define SPNR_SPATIAL_TH_get_cp_spatialthlyx2(data)                    ((0x0000FF00&(data))>>8)
#define SPNR_SPATIAL_TH_get_cp_spatialthly(data)                      (0x000000FF&(data))


#define SPNR_SPATIAL_WEIGHT                                           0x18019e70
#define SPNR_SPATIAL_WEIGHT_reg_addr                                  "0xb8019e70"
#define SPNR_SPATIAL_WEIGHT_reg                                       0xb8019e70
#define SPNR_SPATIAL_WEIGHT_inst_addr                                 "0x039C"
#define SPNR_SPATIAL_WEIGHT_inst                                      0x039C
#define SPNR_SPATIAL_WEIGHT_cp_ringweighty_shift                      (24)
#define SPNR_SPATIAL_WEIGHT_cp_weight1y_shift                         (20)
#define SPNR_SPATIAL_WEIGHT_cp_weight2y_shift                         (16)
#define SPNR_SPATIAL_WEIGHT_cp_fixedweight1y_shift                    (15)
#define SPNR_SPATIAL_WEIGHT_cp_fixedweight2y_shift                    (14)
#define SPNR_SPATIAL_WEIGHT_cp_ringrange_shift                        (8)
#define SPNR_SPATIAL_WEIGHT_cp_ringgain_shift                         (7)
#define SPNR_SPATIAL_WEIGHT_cp_ringweighty_mask                       (0x0F000000)
#define SPNR_SPATIAL_WEIGHT_cp_weight1y_mask                          (0x00F00000)
#define SPNR_SPATIAL_WEIGHT_cp_weight2y_mask                          (0x000F0000)
#define SPNR_SPATIAL_WEIGHT_cp_fixedweight1y_mask                     (0x00008000)
#define SPNR_SPATIAL_WEIGHT_cp_fixedweight2y_mask                     (0x00004000)
#define SPNR_SPATIAL_WEIGHT_cp_ringrange_mask                         (0x00000100)
#define SPNR_SPATIAL_WEIGHT_cp_ringgain_mask                          (0x00000080)
#define SPNR_SPATIAL_WEIGHT_cp_ringweighty(data)                      (0x0F000000&((data)<<24))
#define SPNR_SPATIAL_WEIGHT_cp_weight1y(data)                         (0x00F00000&((data)<<20))
#define SPNR_SPATIAL_WEIGHT_cp_weight2y(data)                         (0x000F0000&((data)<<16))
#define SPNR_SPATIAL_WEIGHT_cp_fixedweight1y(data)                    (0x00008000&((data)<<15))
#define SPNR_SPATIAL_WEIGHT_cp_fixedweight2y(data)                    (0x00004000&((data)<<14))
#define SPNR_SPATIAL_WEIGHT_cp_ringrange(data)                        (0x00000100&((data)<<8))
#define SPNR_SPATIAL_WEIGHT_cp_ringgain(data)                         (0x00000080&((data)<<7))
#define SPNR_SPATIAL_WEIGHT_get_cp_ringweighty(data)                  ((0x0F000000&(data))>>24)
#define SPNR_SPATIAL_WEIGHT_get_cp_weight1y(data)                     ((0x00F00000&(data))>>20)
#define SPNR_SPATIAL_WEIGHT_get_cp_weight2y(data)                     ((0x000F0000&(data))>>16)
#define SPNR_SPATIAL_WEIGHT_get_cp_fixedweight1y(data)                ((0x00008000&(data))>>15)
#define SPNR_SPATIAL_WEIGHT_get_cp_fixedweight2y(data)                ((0x00004000&(data))>>14)
#define SPNR_SPATIAL_WEIGHT_get_cp_ringrange(data)                    ((0x00000100&(data))>>8)
#define SPNR_SPATIAL_WEIGHT_get_cp_ringgain(data)                     ((0x00000080&(data))>>7)


#define DUMMY_STATUS                                                  0x18019e74
#define DUMMY_STATUS_reg_addr                                         "0xb8019e74"
#define DUMMY_STATUS_reg                                              0xb8019e74
#define DUMMY_STATUS_inst_addr                                        "0x039D"
#define DUMMY_STATUS_inst                                             0x039D
#define DUMMY_STATUS_dummy_status_shift                               (0)
#define DUMMY_STATUS_dummy_status_mask                                (0xFFFFFFFF)
#define DUMMY_STATUS_dummy_status(data)                               (0xFFFFFFFF&(data))
#define DUMMY_STATUS_get_dummy_status(data)                           (0xFFFFFFFF&(data))


#define SPNR_LOCAL_VAR2                                               0x18019e78
#define SPNR_LOCAL_VAR2_reg_addr                                      "0xb8019e78"
#define SPNR_LOCAL_VAR2_reg                                           0xb8019e78
#define SPNR_LOCAL_VAR2_inst_addr                                     "0x039E"
#define SPNR_LOCAL_VAR2_inst                                          0x039E
#define SPNR_LOCAL_VAR2_cp_sw_edge_thl_shift                          (16)
#define SPNR_LOCAL_VAR2_cp_edge_weight_shift                          (0)
#define SPNR_LOCAL_VAR2_cp_sw_edge_thl_mask                           (0xFFFF0000)
#define SPNR_LOCAL_VAR2_cp_edge_weight_mask                           (0x00000003)
#define SPNR_LOCAL_VAR2_cp_sw_edge_thl(data)                          (0xFFFF0000&((data)<<16))
#define SPNR_LOCAL_VAR2_cp_edge_weight(data)                          (0x00000003&(data))
#define SPNR_LOCAL_VAR2_get_cp_sw_edge_thl(data)                      ((0xFFFF0000&(data))>>16)
#define SPNR_LOCAL_VAR2_get_cp_edge_weight(data)                      (0x00000003&(data))


#define DE_XC_CTRL                                                    0x18019f00
#define DE_XC_CTRL_reg_addr                                           "0xb8019f00"
#define DE_XC_CTRL_reg                                                0xb8019f00
#define DE_XC_CTRL_inst_addr                                          "0x03C0"
#define DE_XC_CTRL_inst                                               0x03C0
#define DE_XC_CTRL_xc_blend_en_shift                                  (5)
#define DE_XC_CTRL_de_xc_en_shift                                     (4)
#define DE_XC_CTRL_de_xc_thr_shift                                    (0)
#define DE_XC_CTRL_xc_blend_en_mask                                   (0x00000020)
#define DE_XC_CTRL_de_xc_en_mask                                      (0x00000010)
#define DE_XC_CTRL_de_xc_thr_mask                                     (0x0000000F)
#define DE_XC_CTRL_xc_blend_en(data)                                  (0x00000020&((data)<<5))
#define DE_XC_CTRL_de_xc_en(data)                                     (0x00000010&((data)<<4))
#define DE_XC_CTRL_de_xc_thr(data)                                    (0x0000000F&(data))
#define DE_XC_CTRL_get_xc_blend_en(data)                              ((0x00000020&(data))>>5)
#define DE_XC_CTRL_get_de_xc_en(data)                                 ((0x00000010&(data))>>4)
#define DE_XC_CTRL_get_de_xc_thr(data)                                (0x0000000F&(data))


#define CNR_CTRL                                                      0x18019f04
#define CNR_CTRL_reg_addr                                             "0xb8019f04"
#define CNR_CTRL_reg                                                  0xb8019f04
#define CNR_CTRL_inst_addr                                            "0x03C1"
#define CNR_CTRL_inst                                                 0x03C1
#define CNR_CTRL_cnr_lpf_sel_shift                                    (2)
#define CNR_CTRL_cnr_en_shift                                         (0)
#define CNR_CTRL_cnr_lpf_sel_mask                                     (0x0000000C)
#define CNR_CTRL_cnr_en_mask                                          (0x00000001)
#define CNR_CTRL_cnr_lpf_sel(data)                                    (0x0000000C&((data)<<2))
#define CNR_CTRL_cnr_en(data)                                         (0x00000001&(data))
#define CNR_CTRL_get_cnr_lpf_sel(data)                                ((0x0000000C&(data))>>2)
#define CNR_CTRL_get_cnr_en(data)                                     (0x00000001&(data))


#define CADAP_ENABLE_CTRL                                             0x18019f0c
#define CADAP_ENABLE_CTRL_reg_addr                                    "0xb8019f0c"
#define CADAP_ENABLE_CTRL_reg                                         0xb8019f0c
#define CADAP_ENABLE_CTRL_inst_addr                                   "0x03C3"
#define CADAP_ENABLE_CTRL_inst                                        0x03C3
#define CADAP_ENABLE_CTRL_cadap_spatial_lpf_out_shift                 (5)
#define CADAP_ENABLE_CTRL_cadap_clpf_en_shift                         (4)
#define CADAP_ENABLE_CTRL_cadap_ylpf_en_shift                         (3)
#define CADAP_ENABLE_CTRL_cadap_uvsync_en_shift                       (2)
#define CADAP_ENABLE_CTRL_cadap_yuvsync_en_shift                      (1)
#define CADAP_ENABLE_CTRL_cadap_cti_en_shift                          (0)
#define CADAP_ENABLE_CTRL_cadap_spatial_lpf_out_mask                  (0x00000020)
#define CADAP_ENABLE_CTRL_cadap_clpf_en_mask                          (0x00000010)
#define CADAP_ENABLE_CTRL_cadap_ylpf_en_mask                          (0x00000008)
#define CADAP_ENABLE_CTRL_cadap_uvsync_en_mask                        (0x00000004)
#define CADAP_ENABLE_CTRL_cadap_yuvsync_en_mask                       (0x00000002)
#define CADAP_ENABLE_CTRL_cadap_cti_en_mask                           (0x00000001)
#define CADAP_ENABLE_CTRL_cadap_spatial_lpf_out(data)                 (0x00000020&((data)<<5))
#define CADAP_ENABLE_CTRL_cadap_clpf_en(data)                         (0x00000010&((data)<<4))
#define CADAP_ENABLE_CTRL_cadap_ylpf_en(data)                         (0x00000008&((data)<<3))
#define CADAP_ENABLE_CTRL_cadap_uvsync_en(data)                       (0x00000004&((data)<<2))
#define CADAP_ENABLE_CTRL_cadap_yuvsync_en(data)                      (0x00000002&((data)<<1))
#define CADAP_ENABLE_CTRL_cadap_cti_en(data)                          (0x00000001&(data))
#define CADAP_ENABLE_CTRL_get_cadap_spatial_lpf_out(data)             ((0x00000020&(data))>>5)
#define CADAP_ENABLE_CTRL_get_cadap_clpf_en(data)                     ((0x00000010&(data))>>4)
#define CADAP_ENABLE_CTRL_get_cadap_ylpf_en(data)                     ((0x00000008&(data))>>3)
#define CADAP_ENABLE_CTRL_get_cadap_uvsync_en(data)                   ((0x00000004&(data))>>2)
#define CADAP_ENABLE_CTRL_get_cadap_yuvsync_en(data)                  ((0x00000002&(data))>>1)
#define CADAP_ENABLE_CTRL_get_cadap_cti_en(data)                      (0x00000001&(data))


#define CADAP_ENABLE_CTRL2                                            0x18019f10
#define CADAP_ENABLE_CTRL2_reg_addr                                   "0xb8019f10"
#define CADAP_ENABLE_CTRL2_reg                                        0xb8019f10
#define CADAP_ENABLE_CTRL2_inst_addr                                  "0x03C4"
#define CADAP_ENABLE_CTRL2_inst                                       0x03C4
#define CADAP_ENABLE_CTRL2_cadap_uni_gain_ctrl_en_shift               (2)
#define CADAP_ENABLE_CTRL2_cadap_uv_sync_uni_en_shift                 (1)
#define CADAP_ENABLE_CTRL2_cadap_y_sync_uni_en_shift                  (0)
#define CADAP_ENABLE_CTRL2_cadap_uni_gain_ctrl_en_mask                (0x00000004)
#define CADAP_ENABLE_CTRL2_cadap_uv_sync_uni_en_mask                  (0x00000002)
#define CADAP_ENABLE_CTRL2_cadap_y_sync_uni_en_mask                   (0x00000001)
#define CADAP_ENABLE_CTRL2_cadap_uni_gain_ctrl_en(data)               (0x00000004&((data)<<2))
#define CADAP_ENABLE_CTRL2_cadap_uv_sync_uni_en(data)                 (0x00000002&((data)<<1))
#define CADAP_ENABLE_CTRL2_cadap_y_sync_uni_en(data)                  (0x00000001&(data))
#define CADAP_ENABLE_CTRL2_get_cadap_uni_gain_ctrl_en(data)           ((0x00000004&(data))>>2)
#define CADAP_ENABLE_CTRL2_get_cadap_uv_sync_uni_en(data)             ((0x00000002&(data))>>1)
#define CADAP_ENABLE_CTRL2_get_cadap_y_sync_uni_en(data)              (0x00000001&(data))


#define CADAP_GAIN_CTRL                                               0x18019f14
#define CADAP_GAIN_CTRL_reg_addr                                      "0xb8019f14"
#define CADAP_GAIN_CTRL_reg                                           0xb8019f14
#define CADAP_GAIN_CTRL_inst_addr                                     "0x03C5"
#define CADAP_GAIN_CTRL_inst                                          0x03C5
#define CADAP_GAIN_CTRL_cadap_gain_shift                              (4)
#define CADAP_GAIN_CTRL_cadap_level_shift                             (0)
#define CADAP_GAIN_CTRL_cadap_gain_mask                               (0x000000F0)
#define CADAP_GAIN_CTRL_cadap_level_mask                              (0x0000000F)
#define CADAP_GAIN_CTRL_cadap_gain(data)                              (0x000000F0&((data)<<4))
#define CADAP_GAIN_CTRL_cadap_level(data)                             (0x0000000F&(data))
#define CADAP_GAIN_CTRL_get_cadap_gain(data)                          ((0x000000F0&(data))>>4)
#define CADAP_GAIN_CTRL_get_cadap_level(data)                         (0x0000000F&(data))


#define CADAP_ZC_TH                                                   0x18019f18
#define CADAP_ZC_TH_reg_addr                                          "0xb8019f18"
#define CADAP_ZC_TH_reg                                               0xb8019f18
#define CADAP_ZC_TH_inst_addr                                         "0x03C6"
#define CADAP_ZC_TH_inst                                              0x03C6
#define CADAP_ZC_TH_cadap_zc_mag_th_y_shift                           (4)
#define CADAP_ZC_TH_cadap_zc_mag_th_y_c_shift                         (0)
#define CADAP_ZC_TH_cadap_zc_mag_th_y_mask                            (0x000000F0)
#define CADAP_ZC_TH_cadap_zc_mag_th_y_c_mask                          (0x0000000F)
#define CADAP_ZC_TH_cadap_zc_mag_th_y(data)                           (0x000000F0&((data)<<4))
#define CADAP_ZC_TH_cadap_zc_mag_th_y_c(data)                         (0x0000000F&(data))
#define CADAP_ZC_TH_get_cadap_zc_mag_th_y(data)                       ((0x000000F0&(data))>>4)
#define CADAP_ZC_TH_get_cadap_zc_mag_th_y_c(data)                     (0x0000000F&(data))


#define CADAP_ZC_TH2                                                  0x18019f1c
#define CADAP_ZC_TH2_reg_addr                                         "0xb8019f1c"
#define CADAP_ZC_TH2_reg                                              0xb8019f1c
#define CADAP_ZC_TH2_inst_addr                                        "0x03C7"
#define CADAP_ZC_TH2_inst                                             0x03C7
#define CADAP_ZC_TH2_cadap_zc_mag_th_c_shift                          (4)
#define CADAP_ZC_TH2_cadap_dir_det_gain_shift                         (0)
#define CADAP_ZC_TH2_cadap_zc_mag_th_c_mask                           (0x000000F0)
#define CADAP_ZC_TH2_cadap_dir_det_gain_mask                          (0x0000000F)
#define CADAP_ZC_TH2_cadap_zc_mag_th_c(data)                          (0x000000F0&((data)<<4))
#define CADAP_ZC_TH2_cadap_dir_det_gain(data)                         (0x0000000F&(data))
#define CADAP_ZC_TH2_get_cadap_zc_mag_th_c(data)                      ((0x000000F0&(data))>>4)
#define CADAP_ZC_TH2_get_cadap_dir_det_gain(data)                     (0x0000000F&(data))


#define CADAP_VER_UNIFORMITY_TH                                       0x18019f20
#define CADAP_VER_UNIFORMITY_TH_reg_addr                              "0xb8019f20"
#define CADAP_VER_UNIFORMITY_TH_reg                                   0xb8019f20
#define CADAP_VER_UNIFORMITY_TH_inst_addr                             "0x03C8"
#define CADAP_VER_UNIFORMITY_TH_inst                                  0x03C8
#define CADAP_VER_UNIFORMITY_TH_cadap_ver_uni_th_shift                (4)
#define CADAP_VER_UNIFORMITY_TH_cadap_dir_uni_th_shift                (0)
#define CADAP_VER_UNIFORMITY_TH_cadap_ver_uni_th_mask                 (0x000000F0)
#define CADAP_VER_UNIFORMITY_TH_cadap_dir_uni_th_mask                 (0x0000000F)
#define CADAP_VER_UNIFORMITY_TH_cadap_ver_uni_th(data)                (0x000000F0&((data)<<4))
#define CADAP_VER_UNIFORMITY_TH_cadap_dir_uni_th(data)                (0x0000000F&(data))
#define CADAP_VER_UNIFORMITY_TH_get_cadap_ver_uni_th(data)            ((0x000000F0&(data))>>4)
#define CADAP_VER_UNIFORMITY_TH_get_cadap_dir_uni_th(data)            (0x0000000F&(data))


#define CADAP_SYNC_UNIFORMITY_TH                                      0x18019f24
#define CADAP_SYNC_UNIFORMITY_TH_reg_addr                             "0xb8019f24"
#define CADAP_SYNC_UNIFORMITY_TH_reg                                  0xb8019f24
#define CADAP_SYNC_UNIFORMITY_TH_inst_addr                            "0x03C9"
#define CADAP_SYNC_UNIFORMITY_TH_inst                                 0x03C9
#define CADAP_SYNC_UNIFORMITY_TH_cadap_y_sync_uni_th_shift            (4)
#define CADAP_SYNC_UNIFORMITY_TH_cadap_uv_sync_uni_th_shift           (0)
#define CADAP_SYNC_UNIFORMITY_TH_cadap_y_sync_uni_th_mask             (0x000000F0)
#define CADAP_SYNC_UNIFORMITY_TH_cadap_uv_sync_uni_th_mask            (0x0000000F)
#define CADAP_SYNC_UNIFORMITY_TH_cadap_y_sync_uni_th(data)            (0x000000F0&((data)<<4))
#define CADAP_SYNC_UNIFORMITY_TH_cadap_uv_sync_uni_th(data)           (0x0000000F&(data))
#define CADAP_SYNC_UNIFORMITY_TH_get_cadap_y_sync_uni_th(data)        ((0x000000F0&(data))>>4)
#define CADAP_SYNC_UNIFORMITY_TH_get_cadap_uv_sync_uni_th(data)       (0x0000000F&(data))


#define CADAP_LUT_LEVEL_TH                                            0x18019f28
#define CADAP_LUT_LEVEL_TH_reg_addr                                   "0xb8019f28"
#define CADAP_LUT_LEVEL_TH_reg                                        0xb8019f28
#define CADAP_LUT_LEVEL_TH_inst_addr                                  "0x03CA"
#define CADAP_LUT_LEVEL_TH_inst                                       0x03CA
#define CADAP_LUT_LEVEL_TH_cadap_lut_level_tha_shift                  (4)
#define CADAP_LUT_LEVEL_TH_cadap_lut_level_thb_shift                  (0)
#define CADAP_LUT_LEVEL_TH_cadap_lut_level_tha_mask                   (0x000000F0)
#define CADAP_LUT_LEVEL_TH_cadap_lut_level_thb_mask                   (0x0000000F)
#define CADAP_LUT_LEVEL_TH_cadap_lut_level_tha(data)                  (0x000000F0&((data)<<4))
#define CADAP_LUT_LEVEL_TH_cadap_lut_level_thb(data)                  (0x0000000F&(data))
#define CADAP_LUT_LEVEL_TH_get_cadap_lut_level_tha(data)              ((0x000000F0&(data))>>4)
#define CADAP_LUT_LEVEL_TH_get_cadap_lut_level_thb(data)              (0x0000000F&(data))


#define CADAP_LUT_GAIN_TH                                             0x18019f2c
#define CADAP_LUT_GAIN_TH_reg_addr                                    "0xb8019f2c"
#define CADAP_LUT_GAIN_TH_reg                                         0xb8019f2c
#define CADAP_LUT_GAIN_TH_inst_addr                                   "0x03CB"
#define CADAP_LUT_GAIN_TH_inst                                        0x03CB
#define CADAP_LUT_GAIN_TH_cadap_lut_gain_tha_shift                    (4)
#define CADAP_LUT_GAIN_TH_cadap_lut_gain_thb_shift                    (0)
#define CADAP_LUT_GAIN_TH_cadap_lut_gain_tha_mask                     (0x000000F0)
#define CADAP_LUT_GAIN_TH_cadap_lut_gain_thb_mask                     (0x0000000F)
#define CADAP_LUT_GAIN_TH_cadap_lut_gain_tha(data)                    (0x000000F0&((data)<<4))
#define CADAP_LUT_GAIN_TH_cadap_lut_gain_thb(data)                    (0x0000000F&(data))
#define CADAP_LUT_GAIN_TH_get_cadap_lut_gain_tha(data)                ((0x000000F0&(data))>>4)
#define CADAP_LUT_GAIN_TH_get_cadap_lut_gain_thb(data)                (0x0000000F&(data))


#define DCTI_FILTER_COEF_B1                                           0x18019f30
#define DCTI_FILTER_COEF_B1_reg_addr                                  "0xb8019f30"
#define DCTI_FILTER_COEF_B1_reg                                       0xb8019f30
#define DCTI_FILTER_COEF_B1_inst_addr                                 "0x03CC"
#define DCTI_FILTER_COEF_B1_inst                                      0x03CC
#define DCTI_FILTER_COEF_B1_dcti_filter_coef_b1_shift                 (0)
#define DCTI_FILTER_COEF_B1_dcti_filter_coef_b1_mask                  (0x000007FF)
#define DCTI_FILTER_COEF_B1_dcti_filter_coef_b1(data)                 (0x000007FF&(data))
#define DCTI_FILTER_COEF_B1_get_dcti_filter_coef_b1(data)             (0x000007FF&(data))


#define DCTI_FILTER_COEF_B2                                           0x18019f34
#define DCTI_FILTER_COEF_B2_reg_addr                                  "0xb8019f34"
#define DCTI_FILTER_COEF_B2_reg                                       0xb8019f34
#define DCTI_FILTER_COEF_B2_inst_addr                                 "0x03CD"
#define DCTI_FILTER_COEF_B2_inst                                      0x03CD
#define DCTI_FILTER_COEF_B2_dcti_filter_coef_b2_shift                 (0)
#define DCTI_FILTER_COEF_B2_dcti_filter_coef_b2_mask                  (0x000007FF)
#define DCTI_FILTER_COEF_B2_dcti_filter_coef_b2(data)                 (0x000007FF&(data))
#define DCTI_FILTER_COEF_B2_get_dcti_filter_coef_b2(data)             (0x000007FF&(data))


#define DCTI_FILTER_COEF_B3                                           0x18019f38
#define DCTI_FILTER_COEF_B3_reg_addr                                  "0xb8019f38"
#define DCTI_FILTER_COEF_B3_reg                                       0xb8019f38
#define DCTI_FILTER_COEF_B3_inst_addr                                 "0x03CE"
#define DCTI_FILTER_COEF_B3_inst                                      0x03CE
#define DCTI_FILTER_COEF_B3_dcti_filter_coef_b3_shift                 (0)
#define DCTI_FILTER_COEF_B3_dcti_filter_coef_b3_mask                  (0x000007FF)
#define DCTI_FILTER_COEF_B3_dcti_filter_coef_b3(data)                 (0x000007FF&(data))
#define DCTI_FILTER_COEF_B3_get_dcti_filter_coef_b3(data)             (0x000007FF&(data))


#define DCTI_FILTER_COEF_A2                                           0x18019f3c
#define DCTI_FILTER_COEF_A2_reg_addr                                  "0xb8019f3c"
#define DCTI_FILTER_COEF_A2_reg                                       0xb8019f3c
#define DCTI_FILTER_COEF_A2_inst_addr                                 "0x03CF"
#define DCTI_FILTER_COEF_A2_inst                                      0x03CF
#define DCTI_FILTER_COEF_A2_dcti_filter_coef_a2_shift                 (0)
#define DCTI_FILTER_COEF_A2_dcti_filter_coef_a2_mask                  (0x000007FF)
#define DCTI_FILTER_COEF_A2_dcti_filter_coef_a2(data)                 (0x000007FF&(data))
#define DCTI_FILTER_COEF_A2_get_dcti_filter_coef_a2(data)             (0x000007FF&(data))


#define DCTI_FILTER_COEF_A3                                           0x18019f40
#define DCTI_FILTER_COEF_A3_reg_addr                                  "0xb8019f40"
#define DCTI_FILTER_COEF_A3_reg                                       0xb8019f40
#define DCTI_FILTER_COEF_A3_inst_addr                                 "0x03D0"
#define DCTI_FILTER_COEF_A3_inst                                      0x03D0
#define DCTI_FILTER_COEF_A3_dcti_filter_coef_a3_shift                 (0)
#define DCTI_FILTER_COEF_A3_dcti_filter_coef_a3_mask                  (0x000007FF)
#define DCTI_FILTER_COEF_A3_dcti_filter_coef_a3(data)                 (0x000007FF&(data))
#define DCTI_FILTER_COEF_A3_get_dcti_filter_coef_a3(data)             (0x000007FF&(data))


#define DCTI_FILTER_EN                                                0x18019f44
#define DCTI_FILTER_EN_reg_addr                                       "0xb8019f44"
#define DCTI_FILTER_EN_reg                                            0xb8019f44
#define DCTI_FILTER_EN_inst_addr                                      "0x03D1"
#define DCTI_FILTER_EN_inst                                           0x03D1
#define DCTI_FILTER_EN_dcti_filter_en_shift                           (0)
#define DCTI_FILTER_EN_dcti_filter_en_mask                            (0x00000001)
#define DCTI_FILTER_EN_dcti_filter_en(data)                           (0x00000001&(data))
#define DCTI_FILTER_EN_get_dcti_filter_en(data)                       (0x00000001&(data))


#define DUMMY_7                                                       0x18019ff8
#define DUMMY_7_reg_addr                                              "0xb8019ff8"
#define DUMMY_7_reg                                                   0xb8019ff8
#define DUMMY_7_inst_addr                                             "0x03FE"
#define DUMMY_7_inst                                                  0x03FE
#define DUMMY_7_dummy_7_shift                                         (0)
#define DUMMY_7_dummy_7_mask                                          (0xFFFFFFFF)
#define DUMMY_7_dummy_7(data)                                         (0xFFFFFFFF&(data))
#define DUMMY_7_get_dummy_7(data)                                     (0xFFFFFFFF&(data))


#define DUMMY_8                                                       0x18019ffc
#define DUMMY_8_reg_addr                                              "0xb8019ffc"
#define DUMMY_8_reg                                                   0xb8019ffc
#define DUMMY_8_inst_addr                                             "0x03FF"
#define DUMMY_8_inst                                                  0x03FF
#define DUMMY_8_dummy_8_shift                                         (0)
#define DUMMY_8_dummy_8_mask                                          (0xFFFFFFFF)
#define DUMMY_8_dummy_8(data)                                         (0xFFFFFFFF&(data))
#define DUMMY_8_get_dummy_8(data)                                     (0xFFFFFFFF&(data))
#endif
