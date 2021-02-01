// This file is generated using the spec version 1.39, firmware template version 1.39and SRIF Parser                                                                                source code SVN rev:802                    Version flow no.:1.1.69
#ifndef _DISP2TVE_REG_H_INCLUDED_
#define _DISP2TVE_REG_H_INCLUDED_

#ifndef __ASSEMBLY__
#define  _DISP2TVE_USE_STRUCT
#endif

#ifdef _DISP2TVE_USE_STRUCT

typedef struct
{
    unsigned int    global_en:1;
    unsigned int    hdmitx_en:1;
    unsigned int    tve_p_en:1;
    unsigned int    tve_i_en:1;
    unsigned int    muxin_tvei:2;
    unsigned int    muxin_vodisp_buf:1;
    unsigned int    clkmux_vodisp_buf:1;
    unsigned int    muxin_hdmitx:2;
    unsigned int    muxin_tvep:2;
    unsigned int    vbimixer_p_en:1;
    unsigned int    vbimixer_i_en:1;
    unsigned int    dispd_cut_mode:1;
    unsigned int    vodma3_cut_mode:1;
    unsigned int    full_gate_dispd_sel:2;
    unsigned int    full_gate_vodma3_sel:2;
    unsigned int    real_dum0:12;
}DISP2TVE_global;

typedef struct
{
    unsigned int    en_reint_hd:1;
    unsigned int    field_drop_reint_hd:1;
    unsigned int    en_reint_sd:1;
    unsigned int    field_drop_reint_sd:1;
    unsigned int    en_vodisp_buf:1;
    unsigned int    field_drop_vodisp_buf:1;
    unsigned int    reserved_0:26;
}DISP2TVE_reint;

typedef struct
{
    unsigned int    reserved_0:20;
    unsigned int    repeat_lsb:1;
    unsigned int    sel_2x_gain:1;
    unsigned int    sel_y_gain:1;
    unsigned int    matrix_bypass:1;
    unsigned int    sel_uv_off:1;
    unsigned int    set_uv_out_offset:1;
    unsigned int    set_r_in_offset:1;
    unsigned int    sel_rgb:1;
    unsigned int    sel_sign:1;
    unsigned int    reserved_1:1;
    unsigned int    en_rgb2yuv:2;
}DISP2TVE_cc_h_0;

typedef struct
{
    unsigned int    m13:11;
    unsigned int    m12:10;
    unsigned int    m11:11;
}DISP2TVE_cc_h_1;

typedef struct
{
    unsigned int    reserved_0:3;
    unsigned int    m23:9;
    unsigned int    m22:10;
    unsigned int    m21:10;
}DISP2TVE_cc_h_2;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    m33:10;
    unsigned int    m32:11;
    unsigned int    m31:10;
}DISP2TVE_cc_h_3;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    y_gain:9;
    unsigned int    yo_odd:11;
    unsigned int    yo_even:11;
}DISP2TVE_cc_h_4;

typedef struct
{
    unsigned int    reserved_0:21;
    unsigned int    sel_2x_gain:1;
    unsigned int    sel_y_gain:1;
    unsigned int    matrix_bypass:1;
    unsigned int    sel_uv_off:1;
    unsigned int    set_uv_out_offset:1;
    unsigned int    set_r_in_offset:1;
    unsigned int    sel_rgb:1;
    unsigned int    sel_sign:1;
    unsigned int    reserved_1:1;
    unsigned int    en_rgb2yuv:2;
}DISP2TVE_cc_p_0;

typedef struct
{
    unsigned int    m13:11;
    unsigned int    m12:10;
    unsigned int    m11:11;
}DISP2TVE_cc_p_1;

typedef struct
{
    unsigned int    reserved_0:3;
    unsigned int    m23:9;
    unsigned int    m22:10;
    unsigned int    m21:10;
}DISP2TVE_cc_p_2;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    m33:10;
    unsigned int    m32:11;
    unsigned int    m31:10;
}DISP2TVE_cc_p_3;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    y_gain:9;
    unsigned int    yo_odd:11;
    unsigned int    yo_even:11;
}DISP2TVE_cc_p_4;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    en_rbswap:2;
    unsigned int    en_444to422_drop:1;
    unsigned int    en_121_lpf:1;
    unsigned int    reserved_1:1;
    unsigned int    sel_2x_gain:1;
    unsigned int    sel_y_gain:1;
    unsigned int    matrix_bypass:1;
    unsigned int    sel_uv_off:1;
    unsigned int    set_uv_out_offset:1;
    unsigned int    set_r_in_offset:1;
    unsigned int    sel_rgb:1;
    unsigned int    sel_sign:1;
    unsigned int    reserved_2:1;
    unsigned int    en_rgb2yuv:2;
}DISP2TVE_cc_i_0;

typedef struct
{
    unsigned int    m13:11;
    unsigned int    m12:10;
    unsigned int    m11:11;
}DISP2TVE_cc_i_1;

typedef struct
{
    unsigned int    reserved_0:3;
    unsigned int    m23:9;
    unsigned int    m22:10;
    unsigned int    m21:10;
}DISP2TVE_cc_i_2;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    m33:10;
    unsigned int    m32:11;
    unsigned int    m31:10;
}DISP2TVE_cc_i_3;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    y_gain:9;
    unsigned int    yo_odd:11;
    unsigned int    yo_even:11;
}DISP2TVE_cc_i_4;

typedef struct
{
    unsigned int    dummy18026060_31_28:4;
    unsigned int    dd_y_size:12;
    unsigned int    dummy18026060_15_12:4;
    unsigned int    dd_x_size:12;
}DISP2TVE_dd_size;

typedef struct
{
    unsigned int    dummy18026064_31_28:4;
    unsigned int    act_y_start:12;
    unsigned int    dummy18026064_15_12:4;
    unsigned int    act_x_start:12;
}DISP2TVE_dd_vo_init0;

typedef struct
{
    unsigned int    dummy18026068_31_28:4;
    unsigned int    act_y_end:12;
    unsigned int    dummy18026068_15_12:4;
    unsigned int    act_x_end:12;
}DISP2TVE_dd_vo_init1;

typedef struct
{
    unsigned int    dummy1802606c_31_24:8;
    unsigned int    dd_bkg_r:8;
    unsigned int    dd_bkg_g:8;
    unsigned int    dd_bkg_b:8;
}DISP2TVE_dd_bkg;

typedef struct
{
    unsigned int    dummy18026080_31_28:4;
    unsigned int    reint_hd_wptr:12;
    unsigned int    dummy18026080_15_12:4;
    unsigned int    reint_hd_rptr:12;
}STATUS_fifo_reint_hd;

typedef struct
{
    unsigned int    dummy18026084_31_28:4;
    unsigned int    reint_sd_wptr:12;
    unsigned int    dummy18026084_15_12:4;
    unsigned int    reint_sd_rptr:12;
}STATUS_fifo_reint_sd;

typedef struct
{
    unsigned int    dummy18026088_31_28:4;
    unsigned int    vodisp_buf_wptr:12;
    unsigned int    dummy18026088_15_12:4;
    unsigned int    vodisp_buf_rptr:12;
}STATUS_fifo_vodisp_buf;

typedef struct
{
    unsigned int    dummy1802608c_31_24:8;
    unsigned int    full_gated_dispd:1;
    unsigned int    full_gated_vodma3:1;
    unsigned int    reint_hd_fifo_full:1;
    unsigned int    reint_sd_fifo_full:1;
    unsigned int    vodisp_buf_fifo_full:1;
    unsigned int    h_unfl:1;
    unsigned int    p_unfl:1;
    unsigned int    i_unfl:1;
    unsigned int    status_en:8;
    unsigned int    irq_en:8;
}STATUS_fifo_comm;

typedef struct
{
    unsigned int    reserved_0:13;
    unsigned int    vodisp_buf_db_en:1;
    unsigned int    vodisp_buf_db_read_sel:1;
    unsigned int    vodisp_buf_db_apply:1;
    unsigned int    reserved_1:1;
    unsigned int    reint_sd_db_en:1;
    unsigned int    reint_sd_db_read_sel:1;
    unsigned int    reint_sd_db_apply:1;
    unsigned int    reserved_2:1;
    unsigned int    reint_hd_db_en:1;
    unsigned int    reint_hd_db_read_sel:1;
    unsigned int    reint_hd_db_apply:1;
    unsigned int    reserved_3:1;
    unsigned int    tve_p_vbi_db_en:1;
    unsigned int    tve_p_vbi_db_read_sel:1;
    unsigned int    tve_p_vbi_db_apply:1;
    unsigned int    reserved_4:1;
    unsigned int    tve_i_vbi_db_en:1;
    unsigned int    tve_i_vbi_db_read_sel:1;
    unsigned int    tve_i_vbi_db_apply:1;
}DISP2TVE_db_ctrl;

typedef struct
{
    unsigned int    dummy18026094_31_16:16;
    unsigned int    real_dum3:16;
}STATUS_timing_reint_sd;

typedef struct
{
    unsigned int    dummy18026098_31_16:16;
    unsigned int    real_dum4:16;
}STATUS_timing_vodisp_buf;

typedef struct
{
    unsigned int    reserved_0:14;
    unsigned int    ls:1;
    unsigned int    rm:4;
    unsigned int    rme:1;
    unsigned int    reserved_1:3;
    unsigned int    drf_bist_fail:1;
    unsigned int    drf_bist_done:1;
    unsigned int    drf_pause:1;
    unsigned int    drf_resume:1;
    unsigned int    drf_bist_mode:1;
    unsigned int    reserved_2:1;
    unsigned int    bist_fail:1;
    unsigned int    bist_done:1;
    unsigned int    bist_mode:1;
}REINT_hd_bist;

typedef struct
{
    unsigned int    reserved_0:14;
    unsigned int    ls:1;
    unsigned int    rm:4;
    unsigned int    rme:1;
    unsigned int    reserved_1:3;
    unsigned int    drf_bist_fail:1;
    unsigned int    drf_bist_done:1;
    unsigned int    drf_pause:1;
    unsigned int    drf_resume:1;
    unsigned int    drf_bist_mode:1;
    unsigned int    reserved_2:1;
    unsigned int    bist_fail:1;
    unsigned int    bist_done:1;
    unsigned int    bist_mode:1;
}REINT_sd_bist;

typedef struct
{
    unsigned int    reserved_0:14;
    unsigned int    ls:1;
    unsigned int    rm:4;
    unsigned int    rme:1;
    unsigned int    reserved_1:3;
    unsigned int    drf_bist_fail:1;
    unsigned int    drf_bist_done:1;
    unsigned int    drf_pause:1;
    unsigned int    drf_resume:1;
    unsigned int    drf_bist_mode:1;
    unsigned int    reserved_2:1;
    unsigned int    bist_fail:1;
    unsigned int    bist_done:1;
    unsigned int    bist_mode:1;
}VO_buf_bist;

typedef struct
{
    unsigned int    dummy180260c0_31_24:8;
    unsigned int    dummy180260c0_23_14:10;
    unsigned int    real_dum:8;
    unsigned int    ramp_tvep_mode:1;
    unsigned int    ramp_tvep_en:1;
    unsigned int    ramp_tvep_step:2;
    unsigned int    ramp_tvep_pol:1;
    unsigned int    ramp_test_go:1;
}TVE_mp_ptg;

typedef struct
{
    unsigned int    dummy180260c4_31_15:17;
    unsigned int    sram_data_length:11;
    unsigned int    sram_acc_mode:2;
    unsigned int    sram_pat_go:1;
    unsigned int    sram_test_en:1;
}MP_sram_set;

typedef struct
{
    unsigned int    reserved_0:22;
    unsigned int    sram_acc_addr:10;
}MP_sram_addr;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    sram_acc_lsb:24;
}MP_sram_lsb;

typedef struct
{
    unsigned int    reserved_0:22;
    unsigned int    tve_i_crc_start:1;
    unsigned int    tve_i_crc_conti:1;
    unsigned int    tve_p_crc_start:1;
    unsigned int    tve_p_crc_conti:1;
    unsigned int    tve_h_crc_start:1;
    unsigned int    tve_h_crc_conti:1;
    unsigned int    vodma3_crc_start:1;
    unsigned int    vodma3_crc_conti:1;
    unsigned int    dispd_crc_start:1;
    unsigned int    dispd_crc_conti:1;
}DISP2TVE_crc_ctrl;

typedef struct
{
    unsigned int    dispd_crc_result:32;
}DISPD_crc_result;

typedef struct
{
    unsigned int    vodma3_crc_result:32;
}VODMA3_crc_result;

typedef struct
{
    unsigned int    tve_h_crc_result:32;
}TVE_h_crc_result;

typedef struct
{
    unsigned int    tve_p_crc_result:32;
}TVE_p_crc_result;

typedef struct
{
    unsigned int    tve_i_crc_result:32;
}TVE_i_crc_result;

typedef struct
{
    unsigned int    reserved_0:14;
    unsigned int    tve_p_vbi_len:18;
}TVE_p_vbi;

typedef struct
{
    unsigned int    reserved_0:14;
    unsigned int    tve_i_vbi_len:18;
}TVE_i_vbi;

typedef struct
{
    unsigned int    reserved_0:31;
    unsigned int    mb_peaking_en:1;
}D2T_mb_peaking_ctrl;

typedef struct
{
    unsigned int    sh_b0:2;
    unsigned int    sh_b1:2;
    unsigned int    reserved_0:3;
    unsigned int    c0:9;
    unsigned int    reserved_1:7;
    unsigned int    c1:9;
}D2T_mb_peaking_filter_0;

typedef struct
{
    unsigned int    c2:8;
    unsigned int    reserved_0:1;
    unsigned int    c3:7;
    unsigned int    reserved_1:1;
    unsigned int    c4:7;
    unsigned int    reserved_2:2;
    unsigned int    c5:6;
}D2T_mb_peaking_filter_1;

typedef struct
{
    unsigned int    reserved_0:26;
    unsigned int    c6:6;
}D2T_mb_peaking_filter_2;

typedef struct
{
    unsigned int    lv:8;
    unsigned int    gain_blr:8;
    unsigned int    gain_pos:8;
    unsigned int    gain_neg:8;
}D2T_mb_peaking_gain;

typedef struct
{
    unsigned int    reserved_0:6;
    unsigned int    hv_pos:10;
    unsigned int    reserved_1:6;
    unsigned int    hv_neg:10;
}D2T_mb_peaking_bound;

typedef struct
{
    unsigned int    reserved_0:29;
    unsigned int    mb_db_en:1;
    unsigned int    mb_db_read_sel:1;
    unsigned int    mb_db_apply:1;
}D2T_mb_double_buffer_ctrl;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    dummy1802610c_7_0:8;
}D2T_mb_dummy;
#endif


#define DISP2TVE_GLOBAL                                               0x18026000
#define DISP2TVE_GLOBAL_reg_addr                                      "0xb8026000"
#define DISP2TVE_GLOBAL_reg                                           0xb8026000
#define DISP2TVE_GLOBAL_inst_addr                                     "0x0000"
#define DISP2TVE_GLOBAL_inst                                          0x0000
#define set_DISP2TVE_GLOBAL_reg(data)                                 (*((volatile unsigned int*)DISP2TVE_GLOBAL_reg)=data)
#define get_DISP2TVE_GLOBAL_reg                                       (*((volatile unsigned int*)DISP2TVE_GLOBAL_reg))
#define DISP2TVE_GLOBAL_global_en_shift                               (31)
#define DISP2TVE_GLOBAL_hdmitx_en_shift                               (30)
#define DISP2TVE_GLOBAL_tve_p_en_shift                                (29)
#define DISP2TVE_GLOBAL_tve_i_en_shift                                (28)
#define DISP2TVE_GLOBAL_muxin_tvei_shift                              (26)
#define DISP2TVE_GLOBAL_muxin_vodisp_buf_shift                        (25)
#define DISP2TVE_GLOBAL_clkmux_vodisp_buf_shift                       (24)
#define DISP2TVE_GLOBAL_muxin_hdmitx_shift                            (22)
#define DISP2TVE_GLOBAL_muxin_tvep_shift                              (20)
#define DISP2TVE_GLOBAL_vbimixer_p_en_shift                           (19)
#define DISP2TVE_GLOBAL_vbimixer_i_en_shift                           (18)
#define DISP2TVE_GLOBAL_dispd_cut_mode_shift                          (17)
#define DISP2TVE_GLOBAL_vodma3_cut_mode_shift                         (16)
#define DISP2TVE_GLOBAL_full_gate_dispd_sel_shift                     (14)
#define DISP2TVE_GLOBAL_full_gate_vodma3_sel_shift                    (12)
#define DISP2TVE_GLOBAL_real_dum0_shift                               (0)
#define DISP2TVE_GLOBAL_global_en_mask                                (0x80000000)
#define DISP2TVE_GLOBAL_hdmitx_en_mask                                (0x40000000)
#define DISP2TVE_GLOBAL_tve_p_en_mask                                 (0x20000000)
#define DISP2TVE_GLOBAL_tve_i_en_mask                                 (0x10000000)
#define DISP2TVE_GLOBAL_muxin_tvei_mask                               (0x0C000000)
#define DISP2TVE_GLOBAL_muxin_vodisp_buf_mask                         (0x02000000)
#define DISP2TVE_GLOBAL_clkmux_vodisp_buf_mask                        (0x01000000)
#define DISP2TVE_GLOBAL_muxin_hdmitx_mask                             (0x00C00000)
#define DISP2TVE_GLOBAL_muxin_tvep_mask                               (0x00300000)
#define DISP2TVE_GLOBAL_vbimixer_p_en_mask                            (0x00080000)
#define DISP2TVE_GLOBAL_vbimixer_i_en_mask                            (0x00040000)
#define DISP2TVE_GLOBAL_dispd_cut_mode_mask                           (0x00020000)
#define DISP2TVE_GLOBAL_vodma3_cut_mode_mask                          (0x00010000)
#define DISP2TVE_GLOBAL_full_gate_dispd_sel_mask                      (0x0000C000)
#define DISP2TVE_GLOBAL_full_gate_vodma3_sel_mask                     (0x00003000)
#define DISP2TVE_GLOBAL_real_dum0_mask                                (0x00000FFF)
#define DISP2TVE_GLOBAL_global_en(data)                               (0x80000000&((data)<<31))
#define DISP2TVE_GLOBAL_hdmitx_en(data)                               (0x40000000&((data)<<30))
#define DISP2TVE_GLOBAL_tve_p_en(data)                                (0x20000000&((data)<<29))
#define DISP2TVE_GLOBAL_tve_i_en(data)                                (0x10000000&((data)<<28))
#define DISP2TVE_GLOBAL_muxin_tvei(data)                              (0x0C000000&((data)<<26))
#define DISP2TVE_GLOBAL_muxin_vodisp_buf(data)                        (0x02000000&((data)<<25))
#define DISP2TVE_GLOBAL_clkmux_vodisp_buf(data)                       (0x01000000&((data)<<24))
#define DISP2TVE_GLOBAL_muxin_hdmitx(data)                            (0x00C00000&((data)<<22))
#define DISP2TVE_GLOBAL_muxin_tvep(data)                              (0x00300000&((data)<<20))
#define DISP2TVE_GLOBAL_vbimixer_p_en(data)                           (0x00080000&((data)<<19))
#define DISP2TVE_GLOBAL_vbimixer_i_en(data)                           (0x00040000&((data)<<18))
#define DISP2TVE_GLOBAL_dispd_cut_mode(data)                          (0x00020000&((data)<<17))
#define DISP2TVE_GLOBAL_vodma3_cut_mode(data)                         (0x00010000&((data)<<16))
#define DISP2TVE_GLOBAL_full_gate_dispd_sel(data)                     (0x0000C000&((data)<<14))
#define DISP2TVE_GLOBAL_full_gate_vodma3_sel(data)                    (0x00003000&((data)<<12))
#define DISP2TVE_GLOBAL_real_dum0(data)                               (0x00000FFF&(data))
#define DISP2TVE_GLOBAL_get_global_en(data)                           ((0x80000000&(data))>>31)
#define DISP2TVE_GLOBAL_get_hdmitx_en(data)                           ((0x40000000&(data))>>30)
#define DISP2TVE_GLOBAL_get_tve_p_en(data)                            ((0x20000000&(data))>>29)
#define DISP2TVE_GLOBAL_get_tve_i_en(data)                            ((0x10000000&(data))>>28)
#define DISP2TVE_GLOBAL_get_muxin_tvei(data)                          ((0x0C000000&(data))>>26)
#define DISP2TVE_GLOBAL_get_muxin_vodisp_buf(data)                    ((0x02000000&(data))>>25)
#define DISP2TVE_GLOBAL_get_clkmux_vodisp_buf(data)                   ((0x01000000&(data))>>24)
#define DISP2TVE_GLOBAL_get_muxin_hdmitx(data)                        ((0x00C00000&(data))>>22)
#define DISP2TVE_GLOBAL_get_muxin_tvep(data)                          ((0x00300000&(data))>>20)
#define DISP2TVE_GLOBAL_get_vbimixer_p_en(data)                       ((0x00080000&(data))>>19)
#define DISP2TVE_GLOBAL_get_vbimixer_i_en(data)                       ((0x00040000&(data))>>18)
#define DISP2TVE_GLOBAL_get_dispd_cut_mode(data)                      ((0x00020000&(data))>>17)
#define DISP2TVE_GLOBAL_get_vodma3_cut_mode(data)                     ((0x00010000&(data))>>16)
#define DISP2TVE_GLOBAL_get_full_gate_dispd_sel(data)                 ((0x0000C000&(data))>>14)
#define DISP2TVE_GLOBAL_get_full_gate_vodma3_sel(data)                ((0x00003000&(data))>>12)
#define DISP2TVE_GLOBAL_get_real_dum0(data)                           (0x00000FFF&(data))


#define DISP2TVE_REINT                                                0x18026004
#define DISP2TVE_REINT_reg_addr                                       "0xb8026004"
#define DISP2TVE_REINT_reg                                            0xb8026004
#define DISP2TVE_REINT_inst_addr                                      "0x0001"
#define DISP2TVE_REINT_inst                                           0x0001
#define set_DISP2TVE_REINT_reg(data)                                  (*((volatile unsigned int*)DISP2TVE_REINT_reg)=data)
#define get_DISP2TVE_REINT_reg                                        (*((volatile unsigned int*)DISP2TVE_REINT_reg))
#define DISP2TVE_REINT_en_reint_hd_shift                              (31)
#define DISP2TVE_REINT_field_drop_reint_hd_shift                      (30)
#define DISP2TVE_REINT_en_reint_sd_shift                              (29)
#define DISP2TVE_REINT_field_drop_reint_sd_shift                      (28)
#define DISP2TVE_REINT_en_vodisp_buf_shift                            (27)
#define DISP2TVE_REINT_field_drop_vodisp_buf_shift                    (26)
#define DISP2TVE_REINT_en_reint_hd_mask                               (0x80000000)
#define DISP2TVE_REINT_field_drop_reint_hd_mask                       (0x40000000)
#define DISP2TVE_REINT_en_reint_sd_mask                               (0x20000000)
#define DISP2TVE_REINT_field_drop_reint_sd_mask                       (0x10000000)
#define DISP2TVE_REINT_en_vodisp_buf_mask                             (0x08000000)
#define DISP2TVE_REINT_field_drop_vodisp_buf_mask                     (0x04000000)
#define DISP2TVE_REINT_en_reint_hd(data)                              (0x80000000&((data)<<31))
#define DISP2TVE_REINT_field_drop_reint_hd(data)                      (0x40000000&((data)<<30))
#define DISP2TVE_REINT_en_reint_sd(data)                              (0x20000000&((data)<<29))
#define DISP2TVE_REINT_field_drop_reint_sd(data)                      (0x10000000&((data)<<28))
#define DISP2TVE_REINT_en_vodisp_buf(data)                            (0x08000000&((data)<<27))
#define DISP2TVE_REINT_field_drop_vodisp_buf(data)                    (0x04000000&((data)<<26))
#define DISP2TVE_REINT_get_en_reint_hd(data)                          ((0x80000000&(data))>>31)
#define DISP2TVE_REINT_get_field_drop_reint_hd(data)                  ((0x40000000&(data))>>30)
#define DISP2TVE_REINT_get_en_reint_sd(data)                          ((0x20000000&(data))>>29)
#define DISP2TVE_REINT_get_field_drop_reint_sd(data)                  ((0x10000000&(data))>>28)
#define DISP2TVE_REINT_get_en_vodisp_buf(data)                        ((0x08000000&(data))>>27)
#define DISP2TVE_REINT_get_field_drop_vodisp_buf(data)                ((0x04000000&(data))>>26)


#define DISP2TVE_CC_H_0                                               0x18026010
#define DISP2TVE_CC_H_0_reg_addr                                      "0xb8026010"
#define DISP2TVE_CC_H_0_reg                                           0xb8026010
#define DISP2TVE_CC_H_0_inst_addr                                     "0x0004"
#define DISP2TVE_CC_H_0_inst                                          0x0004
#define set_DISP2TVE_CC_H_0_reg(data)                                 (*((volatile unsigned int*)DISP2TVE_CC_H_0_reg)=data)
#define get_DISP2TVE_CC_H_0_reg                                       (*((volatile unsigned int*)DISP2TVE_CC_H_0_reg))
#define DISP2TVE_CC_H_0_repeat_lsb_shift                              (11)
#define DISP2TVE_CC_H_0_sel_2x_gain_shift                             (10)
#define DISP2TVE_CC_H_0_sel_y_gain_shift                              (9)
#define DISP2TVE_CC_H_0_matrix_bypass_shift                           (8)
#define DISP2TVE_CC_H_0_sel_uv_off_shift                              (7)
#define DISP2TVE_CC_H_0_set_uv_out_offset_shift                       (6)
#define DISP2TVE_CC_H_0_set_r_in_offset_shift                         (5)
#define DISP2TVE_CC_H_0_sel_rgb_shift                                 (4)
#define DISP2TVE_CC_H_0_sel_sign_shift                                (3)
#define DISP2TVE_CC_H_0_en_rgb2yuv_shift                              (0)
#define DISP2TVE_CC_H_0_repeat_lsb_mask                               (0x00000800)
#define DISP2TVE_CC_H_0_sel_2x_gain_mask                              (0x00000400)
#define DISP2TVE_CC_H_0_sel_y_gain_mask                               (0x00000200)
#define DISP2TVE_CC_H_0_matrix_bypass_mask                            (0x00000100)
#define DISP2TVE_CC_H_0_sel_uv_off_mask                               (0x00000080)
#define DISP2TVE_CC_H_0_set_uv_out_offset_mask                        (0x00000040)
#define DISP2TVE_CC_H_0_set_r_in_offset_mask                          (0x00000020)
#define DISP2TVE_CC_H_0_sel_rgb_mask                                  (0x00000010)
#define DISP2TVE_CC_H_0_sel_sign_mask                                 (0x00000008)
#define DISP2TVE_CC_H_0_en_rgb2yuv_mask                               (0x00000003)
#define DISP2TVE_CC_H_0_repeat_lsb(data)                              (0x00000800&((data)<<11))
#define DISP2TVE_CC_H_0_sel_2x_gain(data)                             (0x00000400&((data)<<10))
#define DISP2TVE_CC_H_0_sel_y_gain(data)                              (0x00000200&((data)<<9))
#define DISP2TVE_CC_H_0_matrix_bypass(data)                           (0x00000100&((data)<<8))
#define DISP2TVE_CC_H_0_sel_uv_off(data)                              (0x00000080&((data)<<7))
#define DISP2TVE_CC_H_0_set_uv_out_offset(data)                       (0x00000040&((data)<<6))
#define DISP2TVE_CC_H_0_set_r_in_offset(data)                         (0x00000020&((data)<<5))
#define DISP2TVE_CC_H_0_sel_rgb(data)                                 (0x00000010&((data)<<4))
#define DISP2TVE_CC_H_0_sel_sign(data)                                (0x00000008&((data)<<3))
#define DISP2TVE_CC_H_0_en_rgb2yuv(data)                              (0x00000003&(data))
#define DISP2TVE_CC_H_0_get_repeat_lsb(data)                          ((0x00000800&(data))>>11)
#define DISP2TVE_CC_H_0_get_sel_2x_gain(data)                         ((0x00000400&(data))>>10)
#define DISP2TVE_CC_H_0_get_sel_y_gain(data)                          ((0x00000200&(data))>>9)
#define DISP2TVE_CC_H_0_get_matrix_bypass(data)                       ((0x00000100&(data))>>8)
#define DISP2TVE_CC_H_0_get_sel_uv_off(data)                          ((0x00000080&(data))>>7)
#define DISP2TVE_CC_H_0_get_set_uv_out_offset(data)                   ((0x00000040&(data))>>6)
#define DISP2TVE_CC_H_0_get_set_r_in_offset(data)                     ((0x00000020&(data))>>5)
#define DISP2TVE_CC_H_0_get_sel_rgb(data)                             ((0x00000010&(data))>>4)
#define DISP2TVE_CC_H_0_get_sel_sign(data)                            ((0x00000008&(data))>>3)
#define DISP2TVE_CC_H_0_get_en_rgb2yuv(data)                          (0x00000003&(data))


#define DISP2TVE_CC_H_1                                               0x18026014
#define DISP2TVE_CC_H_1_reg_addr                                      "0xb8026014"
#define DISP2TVE_CC_H_1_reg                                           0xb8026014
#define DISP2TVE_CC_H_1_inst_addr                                     "0x0005"
#define DISP2TVE_CC_H_1_inst                                          0x0005
#define set_DISP2TVE_CC_H_1_reg(data)                                 (*((volatile unsigned int*)DISP2TVE_CC_H_1_reg)=data)
#define get_DISP2TVE_CC_H_1_reg                                       (*((volatile unsigned int*)DISP2TVE_CC_H_1_reg))
#define DISP2TVE_CC_H_1_m13_shift                                     (21)
#define DISP2TVE_CC_H_1_m12_shift                                     (11)
#define DISP2TVE_CC_H_1_m11_shift                                     (0)
#define DISP2TVE_CC_H_1_m13_mask                                      (0xFFE00000)
#define DISP2TVE_CC_H_1_m12_mask                                      (0x001FF800)
#define DISP2TVE_CC_H_1_m11_mask                                      (0x000007FF)
#define DISP2TVE_CC_H_1_m13(data)                                     (0xFFE00000&((data)<<21))
#define DISP2TVE_CC_H_1_m12(data)                                     (0x001FF800&((data)<<11))
#define DISP2TVE_CC_H_1_m11(data)                                     (0x000007FF&(data))
#define DISP2TVE_CC_H_1_get_m13(data)                                 ((0xFFE00000&(data))>>21)
#define DISP2TVE_CC_H_1_get_m12(data)                                 ((0x001FF800&(data))>>11)
#define DISP2TVE_CC_H_1_get_m11(data)                                 (0x000007FF&(data))


#define DISP2TVE_CC_H_2                                               0x18026018
#define DISP2TVE_CC_H_2_reg_addr                                      "0xb8026018"
#define DISP2TVE_CC_H_2_reg                                           0xb8026018
#define DISP2TVE_CC_H_2_inst_addr                                     "0x0006"
#define DISP2TVE_CC_H_2_inst                                          0x0006
#define set_DISP2TVE_CC_H_2_reg(data)                                 (*((volatile unsigned int*)DISP2TVE_CC_H_2_reg)=data)
#define get_DISP2TVE_CC_H_2_reg                                       (*((volatile unsigned int*)DISP2TVE_CC_H_2_reg))
#define DISP2TVE_CC_H_2_m23_shift                                     (20)
#define DISP2TVE_CC_H_2_m22_shift                                     (10)
#define DISP2TVE_CC_H_2_m21_shift                                     (0)
#define DISP2TVE_CC_H_2_m23_mask                                      (0x1FF00000)
#define DISP2TVE_CC_H_2_m22_mask                                      (0x000FFC00)
#define DISP2TVE_CC_H_2_m21_mask                                      (0x000003FF)
#define DISP2TVE_CC_H_2_m23(data)                                     (0x1FF00000&((data)<<20))
#define DISP2TVE_CC_H_2_m22(data)                                     (0x000FFC00&((data)<<10))
#define DISP2TVE_CC_H_2_m21(data)                                     (0x000003FF&(data))
#define DISP2TVE_CC_H_2_get_m23(data)                                 ((0x1FF00000&(data))>>20)
#define DISP2TVE_CC_H_2_get_m22(data)                                 ((0x000FFC00&(data))>>10)
#define DISP2TVE_CC_H_2_get_m21(data)                                 (0x000003FF&(data))


#define DISP2TVE_CC_H_3                                               0x1802601c
#define DISP2TVE_CC_H_3_reg_addr                                      "0xb802601c"
#define DISP2TVE_CC_H_3_reg                                           0xb802601c
#define DISP2TVE_CC_H_3_inst_addr                                     "0x0007"
#define DISP2TVE_CC_H_3_inst                                          0x0007
#define set_DISP2TVE_CC_H_3_reg(data)                                 (*((volatile unsigned int*)DISP2TVE_CC_H_3_reg)=data)
#define get_DISP2TVE_CC_H_3_reg                                       (*((volatile unsigned int*)DISP2TVE_CC_H_3_reg))
#define DISP2TVE_CC_H_3_m33_shift                                     (21)
#define DISP2TVE_CC_H_3_m32_shift                                     (10)
#define DISP2TVE_CC_H_3_m31_shift                                     (0)
#define DISP2TVE_CC_H_3_m33_mask                                      (0x7FE00000)
#define DISP2TVE_CC_H_3_m32_mask                                      (0x001FFC00)
#define DISP2TVE_CC_H_3_m31_mask                                      (0x000003FF)
#define DISP2TVE_CC_H_3_m33(data)                                     (0x7FE00000&((data)<<21))
#define DISP2TVE_CC_H_3_m32(data)                                     (0x001FFC00&((data)<<10))
#define DISP2TVE_CC_H_3_m31(data)                                     (0x000003FF&(data))
#define DISP2TVE_CC_H_3_get_m33(data)                                 ((0x7FE00000&(data))>>21)
#define DISP2TVE_CC_H_3_get_m32(data)                                 ((0x001FFC00&(data))>>10)
#define DISP2TVE_CC_H_3_get_m31(data)                                 (0x000003FF&(data))


#define DISP2TVE_CC_H_4                                               0x18026020
#define DISP2TVE_CC_H_4_reg_addr                                      "0xb8026020"
#define DISP2TVE_CC_H_4_reg                                           0xb8026020
#define DISP2TVE_CC_H_4_inst_addr                                     "0x0008"
#define DISP2TVE_CC_H_4_inst                                          0x0008
#define set_DISP2TVE_CC_H_4_reg(data)                                 (*((volatile unsigned int*)DISP2TVE_CC_H_4_reg)=data)
#define get_DISP2TVE_CC_H_4_reg                                       (*((volatile unsigned int*)DISP2TVE_CC_H_4_reg))
#define DISP2TVE_CC_H_4_y_gain_shift                                  (22)
#define DISP2TVE_CC_H_4_yo_odd_shift                                  (11)
#define DISP2TVE_CC_H_4_yo_even_shift                                 (0)
#define DISP2TVE_CC_H_4_y_gain_mask                                   (0x7FC00000)
#define DISP2TVE_CC_H_4_yo_odd_mask                                   (0x003FF800)
#define DISP2TVE_CC_H_4_yo_even_mask                                  (0x000007FF)
#define DISP2TVE_CC_H_4_y_gain(data)                                  (0x7FC00000&((data)<<22))
#define DISP2TVE_CC_H_4_yo_odd(data)                                  (0x003FF800&((data)<<11))
#define DISP2TVE_CC_H_4_yo_even(data)                                 (0x000007FF&(data))
#define DISP2TVE_CC_H_4_get_y_gain(data)                              ((0x7FC00000&(data))>>22)
#define DISP2TVE_CC_H_4_get_yo_odd(data)                              ((0x003FF800&(data))>>11)
#define DISP2TVE_CC_H_4_get_yo_even(data)                             (0x000007FF&(data))


#define DISP2TVE_CC_P_0                                               0x18026028
#define DISP2TVE_CC_P_0_reg_addr                                      "0xb8026028"
#define DISP2TVE_CC_P_0_reg                                           0xb8026028
#define DISP2TVE_CC_P_0_inst_addr                                     "0x000A"
#define DISP2TVE_CC_P_0_inst                                          0x000A
#define set_DISP2TVE_CC_P_0_reg(data)                                 (*((volatile unsigned int*)DISP2TVE_CC_P_0_reg)=data)
#define get_DISP2TVE_CC_P_0_reg                                       (*((volatile unsigned int*)DISP2TVE_CC_P_0_reg))
#define DISP2TVE_CC_P_0_sel_2x_gain_shift                             (10)
#define DISP2TVE_CC_P_0_sel_y_gain_shift                              (9)
#define DISP2TVE_CC_P_0_matrix_bypass_shift                           (8)
#define DISP2TVE_CC_P_0_sel_uv_off_shift                              (7)
#define DISP2TVE_CC_P_0_set_uv_out_offset_shift                       (6)
#define DISP2TVE_CC_P_0_set_r_in_offset_shift                         (5)
#define DISP2TVE_CC_P_0_sel_rgb_shift                                 (4)
#define DISP2TVE_CC_P_0_sel_sign_shift                                (3)
#define DISP2TVE_CC_P_0_en_rgb2yuv_shift                              (0)
#define DISP2TVE_CC_P_0_sel_2x_gain_mask                              (0x00000400)
#define DISP2TVE_CC_P_0_sel_y_gain_mask                               (0x00000200)
#define DISP2TVE_CC_P_0_matrix_bypass_mask                            (0x00000100)
#define DISP2TVE_CC_P_0_sel_uv_off_mask                               (0x00000080)
#define DISP2TVE_CC_P_0_set_uv_out_offset_mask                        (0x00000040)
#define DISP2TVE_CC_P_0_set_r_in_offset_mask                          (0x00000020)
#define DISP2TVE_CC_P_0_sel_rgb_mask                                  (0x00000010)
#define DISP2TVE_CC_P_0_sel_sign_mask                                 (0x00000008)
#define DISP2TVE_CC_P_0_en_rgb2yuv_mask                               (0x00000003)
#define DISP2TVE_CC_P_0_sel_2x_gain(data)                             (0x00000400&((data)<<10))
#define DISP2TVE_CC_P_0_sel_y_gain(data)                              (0x00000200&((data)<<9))
#define DISP2TVE_CC_P_0_matrix_bypass(data)                           (0x00000100&((data)<<8))
#define DISP2TVE_CC_P_0_sel_uv_off(data)                              (0x00000080&((data)<<7))
#define DISP2TVE_CC_P_0_set_uv_out_offset(data)                       (0x00000040&((data)<<6))
#define DISP2TVE_CC_P_0_set_r_in_offset(data)                         (0x00000020&((data)<<5))
#define DISP2TVE_CC_P_0_sel_rgb(data)                                 (0x00000010&((data)<<4))
#define DISP2TVE_CC_P_0_sel_sign(data)                                (0x00000008&((data)<<3))
#define DISP2TVE_CC_P_0_en_rgb2yuv(data)                              (0x00000003&(data))
#define DISP2TVE_CC_P_0_get_sel_2x_gain(data)                         ((0x00000400&(data))>>10)
#define DISP2TVE_CC_P_0_get_sel_y_gain(data)                          ((0x00000200&(data))>>9)
#define DISP2TVE_CC_P_0_get_matrix_bypass(data)                       ((0x00000100&(data))>>8)
#define DISP2TVE_CC_P_0_get_sel_uv_off(data)                          ((0x00000080&(data))>>7)
#define DISP2TVE_CC_P_0_get_set_uv_out_offset(data)                   ((0x00000040&(data))>>6)
#define DISP2TVE_CC_P_0_get_set_r_in_offset(data)                     ((0x00000020&(data))>>5)
#define DISP2TVE_CC_P_0_get_sel_rgb(data)                             ((0x00000010&(data))>>4)
#define DISP2TVE_CC_P_0_get_sel_sign(data)                            ((0x00000008&(data))>>3)
#define DISP2TVE_CC_P_0_get_en_rgb2yuv(data)                          (0x00000003&(data))


#define DISP2TVE_CC_P_1                                               0x1802602c
#define DISP2TVE_CC_P_1_reg_addr                                      "0xb802602c"
#define DISP2TVE_CC_P_1_reg                                           0xb802602c
#define DISP2TVE_CC_P_1_inst_addr                                     "0x000B"
#define DISP2TVE_CC_P_1_inst                                          0x000B
#define set_DISP2TVE_CC_P_1_reg(data)                                 (*((volatile unsigned int*)DISP2TVE_CC_P_1_reg)=data)
#define get_DISP2TVE_CC_P_1_reg                                       (*((volatile unsigned int*)DISP2TVE_CC_P_1_reg))
#define DISP2TVE_CC_P_1_m13_shift                                     (21)
#define DISP2TVE_CC_P_1_m12_shift                                     (11)
#define DISP2TVE_CC_P_1_m11_shift                                     (0)
#define DISP2TVE_CC_P_1_m13_mask                                      (0xFFE00000)
#define DISP2TVE_CC_P_1_m12_mask                                      (0x001FF800)
#define DISP2TVE_CC_P_1_m11_mask                                      (0x000007FF)
#define DISP2TVE_CC_P_1_m13(data)                                     (0xFFE00000&((data)<<21))
#define DISP2TVE_CC_P_1_m12(data)                                     (0x001FF800&((data)<<11))
#define DISP2TVE_CC_P_1_m11(data)                                     (0x000007FF&(data))
#define DISP2TVE_CC_P_1_get_m13(data)                                 ((0xFFE00000&(data))>>21)
#define DISP2TVE_CC_P_1_get_m12(data)                                 ((0x001FF800&(data))>>11)
#define DISP2TVE_CC_P_1_get_m11(data)                                 (0x000007FF&(data))


#define DISP2TVE_CC_P_2                                               0x18026030
#define DISP2TVE_CC_P_2_reg_addr                                      "0xb8026030"
#define DISP2TVE_CC_P_2_reg                                           0xb8026030
#define DISP2TVE_CC_P_2_inst_addr                                     "0x000C"
#define DISP2TVE_CC_P_2_inst                                          0x000C
#define set_DISP2TVE_CC_P_2_reg(data)                                 (*((volatile unsigned int*)DISP2TVE_CC_P_2_reg)=data)
#define get_DISP2TVE_CC_P_2_reg                                       (*((volatile unsigned int*)DISP2TVE_CC_P_2_reg))
#define DISP2TVE_CC_P_2_m23_shift                                     (20)
#define DISP2TVE_CC_P_2_m22_shift                                     (10)
#define DISP2TVE_CC_P_2_m21_shift                                     (0)
#define DISP2TVE_CC_P_2_m23_mask                                      (0x1FF00000)
#define DISP2TVE_CC_P_2_m22_mask                                      (0x000FFC00)
#define DISP2TVE_CC_P_2_m21_mask                                      (0x000003FF)
#define DISP2TVE_CC_P_2_m23(data)                                     (0x1FF00000&((data)<<20))
#define DISP2TVE_CC_P_2_m22(data)                                     (0x000FFC00&((data)<<10))
#define DISP2TVE_CC_P_2_m21(data)                                     (0x000003FF&(data))
#define DISP2TVE_CC_P_2_get_m23(data)                                 ((0x1FF00000&(data))>>20)
#define DISP2TVE_CC_P_2_get_m22(data)                                 ((0x000FFC00&(data))>>10)
#define DISP2TVE_CC_P_2_get_m21(data)                                 (0x000003FF&(data))


#define DISP2TVE_CC_P_3                                               0x18026034
#define DISP2TVE_CC_P_3_reg_addr                                      "0xb8026034"
#define DISP2TVE_CC_P_3_reg                                           0xb8026034
#define DISP2TVE_CC_P_3_inst_addr                                     "0x000D"
#define DISP2TVE_CC_P_3_inst                                          0x000D
#define set_DISP2TVE_CC_P_3_reg(data)                                 (*((volatile unsigned int*)DISP2TVE_CC_P_3_reg)=data)
#define get_DISP2TVE_CC_P_3_reg                                       (*((volatile unsigned int*)DISP2TVE_CC_P_3_reg))
#define DISP2TVE_CC_P_3_m33_shift                                     (21)
#define DISP2TVE_CC_P_3_m32_shift                                     (10)
#define DISP2TVE_CC_P_3_m31_shift                                     (0)
#define DISP2TVE_CC_P_3_m33_mask                                      (0x7FE00000)
#define DISP2TVE_CC_P_3_m32_mask                                      (0x001FFC00)
#define DISP2TVE_CC_P_3_m31_mask                                      (0x000003FF)
#define DISP2TVE_CC_P_3_m33(data)                                     (0x7FE00000&((data)<<21))
#define DISP2TVE_CC_P_3_m32(data)                                     (0x001FFC00&((data)<<10))
#define DISP2TVE_CC_P_3_m31(data)                                     (0x000003FF&(data))
#define DISP2TVE_CC_P_3_get_m33(data)                                 ((0x7FE00000&(data))>>21)
#define DISP2TVE_CC_P_3_get_m32(data)                                 ((0x001FFC00&(data))>>10)
#define DISP2TVE_CC_P_3_get_m31(data)                                 (0x000003FF&(data))


#define DISP2TVE_CC_P_4                                               0x18026038
#define DISP2TVE_CC_P_4_reg_addr                                      "0xb8026038"
#define DISP2TVE_CC_P_4_reg                                           0xb8026038
#define DISP2TVE_CC_P_4_inst_addr                                     "0x000E"
#define DISP2TVE_CC_P_4_inst                                          0x000E
#define set_DISP2TVE_CC_P_4_reg(data)                                 (*((volatile unsigned int*)DISP2TVE_CC_P_4_reg)=data)
#define get_DISP2TVE_CC_P_4_reg                                       (*((volatile unsigned int*)DISP2TVE_CC_P_4_reg))
#define DISP2TVE_CC_P_4_y_gain_shift                                  (22)
#define DISP2TVE_CC_P_4_yo_odd_shift                                  (11)
#define DISP2TVE_CC_P_4_yo_even_shift                                 (0)
#define DISP2TVE_CC_P_4_y_gain_mask                                   (0x7FC00000)
#define DISP2TVE_CC_P_4_yo_odd_mask                                   (0x003FF800)
#define DISP2TVE_CC_P_4_yo_even_mask                                  (0x000007FF)
#define DISP2TVE_CC_P_4_y_gain(data)                                  (0x7FC00000&((data)<<22))
#define DISP2TVE_CC_P_4_yo_odd(data)                                  (0x003FF800&((data)<<11))
#define DISP2TVE_CC_P_4_yo_even(data)                                 (0x000007FF&(data))
#define DISP2TVE_CC_P_4_get_y_gain(data)                              ((0x7FC00000&(data))>>22)
#define DISP2TVE_CC_P_4_get_yo_odd(data)                              ((0x003FF800&(data))>>11)
#define DISP2TVE_CC_P_4_get_yo_even(data)                             (0x000007FF&(data))


#define DISP2TVE_CC_I_0                                               0x18026040
#define DISP2TVE_CC_I_0_reg_addr                                      "0xb8026040"
#define DISP2TVE_CC_I_0_reg                                           0xb8026040
#define DISP2TVE_CC_I_0_inst_addr                                     "0x0010"
#define DISP2TVE_CC_I_0_inst                                          0x0010
#define set_DISP2TVE_CC_I_0_reg(data)                                 (*((volatile unsigned int*)DISP2TVE_CC_I_0_reg)=data)
#define get_DISP2TVE_CC_I_0_reg                                       (*((volatile unsigned int*)DISP2TVE_CC_I_0_reg))
#define DISP2TVE_CC_I_0_en_rbswap_shift                               (14)
#define DISP2TVE_CC_I_0_en_444to422_drop_shift                        (13)
#define DISP2TVE_CC_I_0_en_121_lpf_shift                              (12)
#define DISP2TVE_CC_I_0_sel_2x_gain_shift                             (10)
#define DISP2TVE_CC_I_0_sel_y_gain_shift                              (9)
#define DISP2TVE_CC_I_0_matrix_bypass_shift                           (8)
#define DISP2TVE_CC_I_0_sel_uv_off_shift                              (7)
#define DISP2TVE_CC_I_0_set_uv_out_offset_shift                       (6)
#define DISP2TVE_CC_I_0_set_r_in_offset_shift                         (5)
#define DISP2TVE_CC_I_0_sel_rgb_shift                                 (4)
#define DISP2TVE_CC_I_0_sel_sign_shift                                (3)
#define DISP2TVE_CC_I_0_en_rgb2yuv_shift                              (0)
#define DISP2TVE_CC_I_0_en_rbswap_mask                                (0x0000C000)
#define DISP2TVE_CC_I_0_en_444to422_drop_mask                         (0x00002000)
#define DISP2TVE_CC_I_0_en_121_lpf_mask                               (0x00001000)
#define DISP2TVE_CC_I_0_sel_2x_gain_mask                              (0x00000400)
#define DISP2TVE_CC_I_0_sel_y_gain_mask                               (0x00000200)
#define DISP2TVE_CC_I_0_matrix_bypass_mask                            (0x00000100)
#define DISP2TVE_CC_I_0_sel_uv_off_mask                               (0x00000080)
#define DISP2TVE_CC_I_0_set_uv_out_offset_mask                        (0x00000040)
#define DISP2TVE_CC_I_0_set_r_in_offset_mask                          (0x00000020)
#define DISP2TVE_CC_I_0_sel_rgb_mask                                  (0x00000010)
#define DISP2TVE_CC_I_0_sel_sign_mask                                 (0x00000008)
#define DISP2TVE_CC_I_0_en_rgb2yuv_mask                               (0x00000003)
#define DISP2TVE_CC_I_0_en_rbswap(data)                               (0x0000C000&((data)<<14))
#define DISP2TVE_CC_I_0_en_444to422_drop(data)                        (0x00002000&((data)<<13))
#define DISP2TVE_CC_I_0_en_121_lpf(data)                              (0x00001000&((data)<<12))
#define DISP2TVE_CC_I_0_sel_2x_gain(data)                             (0x00000400&((data)<<10))
#define DISP2TVE_CC_I_0_sel_y_gain(data)                              (0x00000200&((data)<<9))
#define DISP2TVE_CC_I_0_matrix_bypass(data)                           (0x00000100&((data)<<8))
#define DISP2TVE_CC_I_0_sel_uv_off(data)                              (0x00000080&((data)<<7))
#define DISP2TVE_CC_I_0_set_uv_out_offset(data)                       (0x00000040&((data)<<6))
#define DISP2TVE_CC_I_0_set_r_in_offset(data)                         (0x00000020&((data)<<5))
#define DISP2TVE_CC_I_0_sel_rgb(data)                                 (0x00000010&((data)<<4))
#define DISP2TVE_CC_I_0_sel_sign(data)                                (0x00000008&((data)<<3))
#define DISP2TVE_CC_I_0_en_rgb2yuv(data)                              (0x00000003&(data))
#define DISP2TVE_CC_I_0_get_en_rbswap(data)                           ((0x0000C000&(data))>>14)
#define DISP2TVE_CC_I_0_get_en_444to422_drop(data)                    ((0x00002000&(data))>>13)
#define DISP2TVE_CC_I_0_get_en_121_lpf(data)                          ((0x00001000&(data))>>12)
#define DISP2TVE_CC_I_0_get_sel_2x_gain(data)                         ((0x00000400&(data))>>10)
#define DISP2TVE_CC_I_0_get_sel_y_gain(data)                          ((0x00000200&(data))>>9)
#define DISP2TVE_CC_I_0_get_matrix_bypass(data)                       ((0x00000100&(data))>>8)
#define DISP2TVE_CC_I_0_get_sel_uv_off(data)                          ((0x00000080&(data))>>7)
#define DISP2TVE_CC_I_0_get_set_uv_out_offset(data)                   ((0x00000040&(data))>>6)
#define DISP2TVE_CC_I_0_get_set_r_in_offset(data)                     ((0x00000020&(data))>>5)
#define DISP2TVE_CC_I_0_get_sel_rgb(data)                             ((0x00000010&(data))>>4)
#define DISP2TVE_CC_I_0_get_sel_sign(data)                            ((0x00000008&(data))>>3)
#define DISP2TVE_CC_I_0_get_en_rgb2yuv(data)                          (0x00000003&(data))


#define DISP2TVE_CC_I_1                                               0x18026044
#define DISP2TVE_CC_I_1_reg_addr                                      "0xb8026044"
#define DISP2TVE_CC_I_1_reg                                           0xb8026044
#define DISP2TVE_CC_I_1_inst_addr                                     "0x0011"
#define DISP2TVE_CC_I_1_inst                                          0x0011
#define set_DISP2TVE_CC_I_1_reg(data)                                 (*((volatile unsigned int*)DISP2TVE_CC_I_1_reg)=data)
#define get_DISP2TVE_CC_I_1_reg                                       (*((volatile unsigned int*)DISP2TVE_CC_I_1_reg))
#define DISP2TVE_CC_I_1_m13_shift                                     (21)
#define DISP2TVE_CC_I_1_m12_shift                                     (11)
#define DISP2TVE_CC_I_1_m11_shift                                     (0)
#define DISP2TVE_CC_I_1_m13_mask                                      (0xFFE00000)
#define DISP2TVE_CC_I_1_m12_mask                                      (0x001FF800)
#define DISP2TVE_CC_I_1_m11_mask                                      (0x000007FF)
#define DISP2TVE_CC_I_1_m13(data)                                     (0xFFE00000&((data)<<21))
#define DISP2TVE_CC_I_1_m12(data)                                     (0x001FF800&((data)<<11))
#define DISP2TVE_CC_I_1_m11(data)                                     (0x000007FF&(data))
#define DISP2TVE_CC_I_1_get_m13(data)                                 ((0xFFE00000&(data))>>21)
#define DISP2TVE_CC_I_1_get_m12(data)                                 ((0x001FF800&(data))>>11)
#define DISP2TVE_CC_I_1_get_m11(data)                                 (0x000007FF&(data))


#define DISP2TVE_CC_I_2                                               0x18026048
#define DISP2TVE_CC_I_2_reg_addr                                      "0xb8026048"
#define DISP2TVE_CC_I_2_reg                                           0xb8026048
#define DISP2TVE_CC_I_2_inst_addr                                     "0x0012"
#define DISP2TVE_CC_I_2_inst                                          0x0012
#define set_DISP2TVE_CC_I_2_reg(data)                                 (*((volatile unsigned int*)DISP2TVE_CC_I_2_reg)=data)
#define get_DISP2TVE_CC_I_2_reg                                       (*((volatile unsigned int*)DISP2TVE_CC_I_2_reg))
#define DISP2TVE_CC_I_2_m23_shift                                     (20)
#define DISP2TVE_CC_I_2_m22_shift                                     (10)
#define DISP2TVE_CC_I_2_m21_shift                                     (0)
#define DISP2TVE_CC_I_2_m23_mask                                      (0x1FF00000)
#define DISP2TVE_CC_I_2_m22_mask                                      (0x000FFC00)
#define DISP2TVE_CC_I_2_m21_mask                                      (0x000003FF)
#define DISP2TVE_CC_I_2_m23(data)                                     (0x1FF00000&((data)<<20))
#define DISP2TVE_CC_I_2_m22(data)                                     (0x000FFC00&((data)<<10))
#define DISP2TVE_CC_I_2_m21(data)                                     (0x000003FF&(data))
#define DISP2TVE_CC_I_2_get_m23(data)                                 ((0x1FF00000&(data))>>20)
#define DISP2TVE_CC_I_2_get_m22(data)                                 ((0x000FFC00&(data))>>10)
#define DISP2TVE_CC_I_2_get_m21(data)                                 (0x000003FF&(data))


#define DISP2TVE_CC_I_3                                               0x1802604c
#define DISP2TVE_CC_I_3_reg_addr                                      "0xb802604c"
#define DISP2TVE_CC_I_3_reg                                           0xb802604c
#define DISP2TVE_CC_I_3_inst_addr                                     "0x0013"
#define DISP2TVE_CC_I_3_inst                                          0x0013
#define set_DISP2TVE_CC_I_3_reg(data)                                 (*((volatile unsigned int*)DISP2TVE_CC_I_3_reg)=data)
#define get_DISP2TVE_CC_I_3_reg                                       (*((volatile unsigned int*)DISP2TVE_CC_I_3_reg))
#define DISP2TVE_CC_I_3_m33_shift                                     (21)
#define DISP2TVE_CC_I_3_m32_shift                                     (10)
#define DISP2TVE_CC_I_3_m31_shift                                     (0)
#define DISP2TVE_CC_I_3_m33_mask                                      (0x7FE00000)
#define DISP2TVE_CC_I_3_m32_mask                                      (0x001FFC00)
#define DISP2TVE_CC_I_3_m31_mask                                      (0x000003FF)
#define DISP2TVE_CC_I_3_m33(data)                                     (0x7FE00000&((data)<<21))
#define DISP2TVE_CC_I_3_m32(data)                                     (0x001FFC00&((data)<<10))
#define DISP2TVE_CC_I_3_m31(data)                                     (0x000003FF&(data))
#define DISP2TVE_CC_I_3_get_m33(data)                                 ((0x7FE00000&(data))>>21)
#define DISP2TVE_CC_I_3_get_m32(data)                                 ((0x001FFC00&(data))>>10)
#define DISP2TVE_CC_I_3_get_m31(data)                                 (0x000003FF&(data))


#define DISP2TVE_CC_I_4                                               0x18026050
#define DISP2TVE_CC_I_4_reg_addr                                      "0xb8026050"
#define DISP2TVE_CC_I_4_reg                                           0xb8026050
#define DISP2TVE_CC_I_4_inst_addr                                     "0x0014"
#define DISP2TVE_CC_I_4_inst                                          0x0014
#define set_DISP2TVE_CC_I_4_reg(data)                                 (*((volatile unsigned int*)DISP2TVE_CC_I_4_reg)=data)
#define get_DISP2TVE_CC_I_4_reg                                       (*((volatile unsigned int*)DISP2TVE_CC_I_4_reg))
#define DISP2TVE_CC_I_4_y_gain_shift                                  (22)
#define DISP2TVE_CC_I_4_yo_odd_shift                                  (11)
#define DISP2TVE_CC_I_4_yo_even_shift                                 (0)
#define DISP2TVE_CC_I_4_y_gain_mask                                   (0x7FC00000)
#define DISP2TVE_CC_I_4_yo_odd_mask                                   (0x003FF800)
#define DISP2TVE_CC_I_4_yo_even_mask                                  (0x000007FF)
#define DISP2TVE_CC_I_4_y_gain(data)                                  (0x7FC00000&((data)<<22))
#define DISP2TVE_CC_I_4_yo_odd(data)                                  (0x003FF800&((data)<<11))
#define DISP2TVE_CC_I_4_yo_even(data)                                 (0x000007FF&(data))
#define DISP2TVE_CC_I_4_get_y_gain(data)                              ((0x7FC00000&(data))>>22)
#define DISP2TVE_CC_I_4_get_yo_odd(data)                              ((0x003FF800&(data))>>11)
#define DISP2TVE_CC_I_4_get_yo_even(data)                             (0x000007FF&(data))


#define DISP2TVE_DD_SIZE                                              0x18026060
#define DISP2TVE_DD_SIZE_reg_addr                                     "0xb8026060"
#define DISP2TVE_DD_SIZE_reg                                          0xb8026060
#define DISP2TVE_DD_SIZE_inst_addr                                    "0x0018"
#define DISP2TVE_DD_SIZE_inst                                         0x0018
#define set_DISP2TVE_DD_SIZE_reg(data)                                (*((volatile unsigned int*)DISP2TVE_DD_SIZE_reg)=data)
#define get_DISP2TVE_DD_SIZE_reg                                      (*((volatile unsigned int*)DISP2TVE_DD_SIZE_reg))
#define DISP2TVE_DD_SIZE_dummy18026060_31_28_shift                    (28)
#define DISP2TVE_DD_SIZE_dd_y_size_shift                              (16)
#define DISP2TVE_DD_SIZE_dummy18026060_15_12_shift                    (12)
#define DISP2TVE_DD_SIZE_dd_x_size_shift                              (0)
#define DISP2TVE_DD_SIZE_dummy18026060_31_28_mask                     (0xF0000000)
#define DISP2TVE_DD_SIZE_dd_y_size_mask                               (0x0FFF0000)
#define DISP2TVE_DD_SIZE_dummy18026060_15_12_mask                     (0x0000F000)
#define DISP2TVE_DD_SIZE_dd_x_size_mask                               (0x00000FFF)
#define DISP2TVE_DD_SIZE_dummy18026060_31_28(data)                    (0xF0000000&((data)<<28))
#define DISP2TVE_DD_SIZE_dd_y_size(data)                              (0x0FFF0000&((data)<<16))
#define DISP2TVE_DD_SIZE_dummy18026060_15_12(data)                    (0x0000F000&((data)<<12))
#define DISP2TVE_DD_SIZE_dd_x_size(data)                              (0x00000FFF&(data))
#define DISP2TVE_DD_SIZE_get_dummy18026060_31_28(data)                ((0xF0000000&(data))>>28)
#define DISP2TVE_DD_SIZE_get_dd_y_size(data)                          ((0x0FFF0000&(data))>>16)
#define DISP2TVE_DD_SIZE_get_dummy18026060_15_12(data)                ((0x0000F000&(data))>>12)
#define DISP2TVE_DD_SIZE_get_dd_x_size(data)                          (0x00000FFF&(data))


#define DISP2TVE_DD_VO_INIT0                                          0x18026064
#define DISP2TVE_DD_VO_INIT0_reg_addr                                 "0xb8026064"
#define DISP2TVE_DD_VO_INIT0_reg                                      0xb8026064
#define DISP2TVE_DD_VO_INIT0_inst_addr                                "0x0019"
#define DISP2TVE_DD_VO_INIT0_inst                                     0x0019
#define set_DISP2TVE_DD_VO_INIT0_reg(data)                            (*((volatile unsigned int*)DISP2TVE_DD_VO_INIT0_reg)=data)
#define get_DISP2TVE_DD_VO_INIT0_reg                                  (*((volatile unsigned int*)DISP2TVE_DD_VO_INIT0_reg))
#define DISP2TVE_DD_VO_INIT0_dummy18026064_31_28_shift                (28)
#define DISP2TVE_DD_VO_INIT0_act_y_start_shift                        (16)
#define DISP2TVE_DD_VO_INIT0_dummy18026064_15_12_shift                (12)
#define DISP2TVE_DD_VO_INIT0_act_x_start_shift                        (0)
#define DISP2TVE_DD_VO_INIT0_dummy18026064_31_28_mask                 (0xF0000000)
#define DISP2TVE_DD_VO_INIT0_act_y_start_mask                         (0x0FFF0000)
#define DISP2TVE_DD_VO_INIT0_dummy18026064_15_12_mask                 (0x0000F000)
#define DISP2TVE_DD_VO_INIT0_act_x_start_mask                         (0x00000FFF)
#define DISP2TVE_DD_VO_INIT0_dummy18026064_31_28(data)                (0xF0000000&((data)<<28))
#define DISP2TVE_DD_VO_INIT0_act_y_start(data)                        (0x0FFF0000&((data)<<16))
#define DISP2TVE_DD_VO_INIT0_dummy18026064_15_12(data)                (0x0000F000&((data)<<12))
#define DISP2TVE_DD_VO_INIT0_act_x_start(data)                        (0x00000FFF&(data))
#define DISP2TVE_DD_VO_INIT0_get_dummy18026064_31_28(data)            ((0xF0000000&(data))>>28)
#define DISP2TVE_DD_VO_INIT0_get_act_y_start(data)                    ((0x0FFF0000&(data))>>16)
#define DISP2TVE_DD_VO_INIT0_get_dummy18026064_15_12(data)            ((0x0000F000&(data))>>12)
#define DISP2TVE_DD_VO_INIT0_get_act_x_start(data)                    (0x00000FFF&(data))


#define DISP2TVE_DD_VO_INIT1                                          0x18026068
#define DISP2TVE_DD_VO_INIT1_reg_addr                                 "0xb8026068"
#define DISP2TVE_DD_VO_INIT1_reg                                      0xb8026068
#define DISP2TVE_DD_VO_INIT1_inst_addr                                "0x001A"
#define DISP2TVE_DD_VO_INIT1_inst                                     0x001A
#define set_DISP2TVE_DD_VO_INIT1_reg(data)                            (*((volatile unsigned int*)DISP2TVE_DD_VO_INIT1_reg)=data)
#define get_DISP2TVE_DD_VO_INIT1_reg                                  (*((volatile unsigned int*)DISP2TVE_DD_VO_INIT1_reg))
#define DISP2TVE_DD_VO_INIT1_dummy18026068_31_28_shift                (28)
#define DISP2TVE_DD_VO_INIT1_act_y_end_shift                          (16)
#define DISP2TVE_DD_VO_INIT1_dummy18026068_15_12_shift                (12)
#define DISP2TVE_DD_VO_INIT1_act_x_end_shift                          (0)
#define DISP2TVE_DD_VO_INIT1_dummy18026068_31_28_mask                 (0xF0000000)
#define DISP2TVE_DD_VO_INIT1_act_y_end_mask                           (0x0FFF0000)
#define DISP2TVE_DD_VO_INIT1_dummy18026068_15_12_mask                 (0x0000F000)
#define DISP2TVE_DD_VO_INIT1_act_x_end_mask                           (0x00000FFF)
#define DISP2TVE_DD_VO_INIT1_dummy18026068_31_28(data)                (0xF0000000&((data)<<28))
#define DISP2TVE_DD_VO_INIT1_act_y_end(data)                          (0x0FFF0000&((data)<<16))
#define DISP2TVE_DD_VO_INIT1_dummy18026068_15_12(data)                (0x0000F000&((data)<<12))
#define DISP2TVE_DD_VO_INIT1_act_x_end(data)                          (0x00000FFF&(data))
#define DISP2TVE_DD_VO_INIT1_get_dummy18026068_31_28(data)            ((0xF0000000&(data))>>28)
#define DISP2TVE_DD_VO_INIT1_get_act_y_end(data)                      ((0x0FFF0000&(data))>>16)
#define DISP2TVE_DD_VO_INIT1_get_dummy18026068_15_12(data)            ((0x0000F000&(data))>>12)
#define DISP2TVE_DD_VO_INIT1_get_act_x_end(data)                      (0x00000FFF&(data))


#define DISP2TVE_DD_BKG                                               0x1802606c
#define DISP2TVE_DD_BKG_reg_addr                                      "0xb802606c"
#define DISP2TVE_DD_BKG_reg                                           0xb802606c
#define DISP2TVE_DD_BKG_inst_addr                                     "0x001B"
#define DISP2TVE_DD_BKG_inst                                          0x001B
#define set_DISP2TVE_DD_BKG_reg(data)                                 (*((volatile unsigned int*)DISP2TVE_DD_BKG_reg)=data)
#define get_DISP2TVE_DD_BKG_reg                                       (*((volatile unsigned int*)DISP2TVE_DD_BKG_reg))
#define DISP2TVE_DD_BKG_dummy1802606c_31_24_shift                     (24)
#define DISP2TVE_DD_BKG_dd_bkg_r_shift                                (16)
#define DISP2TVE_DD_BKG_dd_bkg_g_shift                                (8)
#define DISP2TVE_DD_BKG_dd_bkg_b_shift                                (0)
#define DISP2TVE_DD_BKG_dummy1802606c_31_24_mask                      (0xFF000000)
#define DISP2TVE_DD_BKG_dd_bkg_r_mask                                 (0x00FF0000)
#define DISP2TVE_DD_BKG_dd_bkg_g_mask                                 (0x0000FF00)
#define DISP2TVE_DD_BKG_dd_bkg_b_mask                                 (0x000000FF)
#define DISP2TVE_DD_BKG_dummy1802606c_31_24(data)                     (0xFF000000&((data)<<24))
#define DISP2TVE_DD_BKG_dd_bkg_r(data)                                (0x00FF0000&((data)<<16))
#define DISP2TVE_DD_BKG_dd_bkg_g(data)                                (0x0000FF00&((data)<<8))
#define DISP2TVE_DD_BKG_dd_bkg_b(data)                                (0x000000FF&(data))
#define DISP2TVE_DD_BKG_get_dummy1802606c_31_24(data)                 ((0xFF000000&(data))>>24)
#define DISP2TVE_DD_BKG_get_dd_bkg_r(data)                            ((0x00FF0000&(data))>>16)
#define DISP2TVE_DD_BKG_get_dd_bkg_g(data)                            ((0x0000FF00&(data))>>8)
#define DISP2TVE_DD_BKG_get_dd_bkg_b(data)                            (0x000000FF&(data))


#define STATUS_FIFO_REINT_HD                                          0x18026080
#define STATUS_FIFO_REINT_HD_reg_addr                                 "0xb8026080"
#define STATUS_FIFO_REINT_HD_reg                                      0xb8026080
#define STATUS_FIFO_REINT_HD_inst_addr                                "0x0020"
#define STATUS_FIFO_REINT_HD_inst                                     0x0020
#define set_STATUS_FIFO_REINT_HD_reg(data)                            (*((volatile unsigned int*)STATUS_FIFO_REINT_HD_reg)=data)
#define get_STATUS_FIFO_REINT_HD_reg                                  (*((volatile unsigned int*)STATUS_FIFO_REINT_HD_reg))
#define STATUS_FIFO_REINT_HD_dummy18026080_31_28_shift                (28)
#define STATUS_FIFO_REINT_HD_reint_hd_wptr_shift                      (16)
#define STATUS_FIFO_REINT_HD_dummy18026080_15_12_shift                (12)
#define STATUS_FIFO_REINT_HD_reint_hd_rptr_shift                      (0)
#define STATUS_FIFO_REINT_HD_dummy18026080_31_28_mask                 (0xF0000000)
#define STATUS_FIFO_REINT_HD_reint_hd_wptr_mask                       (0x0FFF0000)
#define STATUS_FIFO_REINT_HD_dummy18026080_15_12_mask                 (0x0000F000)
#define STATUS_FIFO_REINT_HD_reint_hd_rptr_mask                       (0x00000FFF)
#define STATUS_FIFO_REINT_HD_dummy18026080_31_28(data)                (0xF0000000&((data)<<28))
#define STATUS_FIFO_REINT_HD_reint_hd_wptr(data)                      (0x0FFF0000&((data)<<16))
#define STATUS_FIFO_REINT_HD_dummy18026080_15_12(data)                (0x0000F000&((data)<<12))
#define STATUS_FIFO_REINT_HD_reint_hd_rptr(data)                      (0x00000FFF&(data))
#define STATUS_FIFO_REINT_HD_get_dummy18026080_31_28(data)            ((0xF0000000&(data))>>28)
#define STATUS_FIFO_REINT_HD_get_reint_hd_wptr(data)                  ((0x0FFF0000&(data))>>16)
#define STATUS_FIFO_REINT_HD_get_dummy18026080_15_12(data)            ((0x0000F000&(data))>>12)
#define STATUS_FIFO_REINT_HD_get_reint_hd_rptr(data)                  (0x00000FFF&(data))


#define STATUS_FIFO_REINT_SD                                          0x18026084
#define STATUS_FIFO_REINT_SD_reg_addr                                 "0xb8026084"
#define STATUS_FIFO_REINT_SD_reg                                      0xb8026084
#define STATUS_FIFO_REINT_SD_inst_addr                                "0x0021"
#define STATUS_FIFO_REINT_SD_inst                                     0x0021
#define set_STATUS_FIFO_REINT_SD_reg(data)                            (*((volatile unsigned int*)STATUS_FIFO_REINT_SD_reg)=data)
#define get_STATUS_FIFO_REINT_SD_reg                                  (*((volatile unsigned int*)STATUS_FIFO_REINT_SD_reg))
#define STATUS_FIFO_REINT_SD_dummy18026084_31_28_shift                (28)
#define STATUS_FIFO_REINT_SD_reint_sd_wptr_shift                      (16)
#define STATUS_FIFO_REINT_SD_dummy18026084_15_12_shift                (12)
#define STATUS_FIFO_REINT_SD_reint_sd_rptr_shift                      (0)
#define STATUS_FIFO_REINT_SD_dummy18026084_31_28_mask                 (0xF0000000)
#define STATUS_FIFO_REINT_SD_reint_sd_wptr_mask                       (0x0FFF0000)
#define STATUS_FIFO_REINT_SD_dummy18026084_15_12_mask                 (0x0000F000)
#define STATUS_FIFO_REINT_SD_reint_sd_rptr_mask                       (0x00000FFF)
#define STATUS_FIFO_REINT_SD_dummy18026084_31_28(data)                (0xF0000000&((data)<<28))
#define STATUS_FIFO_REINT_SD_reint_sd_wptr(data)                      (0x0FFF0000&((data)<<16))
#define STATUS_FIFO_REINT_SD_dummy18026084_15_12(data)                (0x0000F000&((data)<<12))
#define STATUS_FIFO_REINT_SD_reint_sd_rptr(data)                      (0x00000FFF&(data))
#define STATUS_FIFO_REINT_SD_get_dummy18026084_31_28(data)            ((0xF0000000&(data))>>28)
#define STATUS_FIFO_REINT_SD_get_reint_sd_wptr(data)                  ((0x0FFF0000&(data))>>16)
#define STATUS_FIFO_REINT_SD_get_dummy18026084_15_12(data)            ((0x0000F000&(data))>>12)
#define STATUS_FIFO_REINT_SD_get_reint_sd_rptr(data)                  (0x00000FFF&(data))


#define STATUS_FIFO_VODISP_BUF                                        0x18026088
#define STATUS_FIFO_VODISP_BUF_reg_addr                               "0xb8026088"
#define STATUS_FIFO_VODISP_BUF_reg                                    0xb8026088
#define STATUS_FIFO_VODISP_BUF_inst_addr                              "0x0022"
#define STATUS_FIFO_VODISP_BUF_inst                                   0x0022
#define set_STATUS_FIFO_VODISP_BUF_reg(data)                          (*((volatile unsigned int*)STATUS_FIFO_VODISP_BUF_reg)=data)
#define get_STATUS_FIFO_VODISP_BUF_reg                                (*((volatile unsigned int*)STATUS_FIFO_VODISP_BUF_reg))
#define STATUS_FIFO_VODISP_BUF_dummy18026088_31_28_shift              (28)
#define STATUS_FIFO_VODISP_BUF_vodisp_buf_wptr_shift                  (16)
#define STATUS_FIFO_VODISP_BUF_dummy18026088_15_12_shift              (12)
#define STATUS_FIFO_VODISP_BUF_vodisp_buf_rptr_shift                  (0)
#define STATUS_FIFO_VODISP_BUF_dummy18026088_31_28_mask               (0xF0000000)
#define STATUS_FIFO_VODISP_BUF_vodisp_buf_wptr_mask                   (0x0FFF0000)
#define STATUS_FIFO_VODISP_BUF_dummy18026088_15_12_mask               (0x0000F000)
#define STATUS_FIFO_VODISP_BUF_vodisp_buf_rptr_mask                   (0x00000FFF)
#define STATUS_FIFO_VODISP_BUF_dummy18026088_31_28(data)              (0xF0000000&((data)<<28))
#define STATUS_FIFO_VODISP_BUF_vodisp_buf_wptr(data)                  (0x0FFF0000&((data)<<16))
#define STATUS_FIFO_VODISP_BUF_dummy18026088_15_12(data)              (0x0000F000&((data)<<12))
#define STATUS_FIFO_VODISP_BUF_vodisp_buf_rptr(data)                  (0x00000FFF&(data))
#define STATUS_FIFO_VODISP_BUF_get_dummy18026088_31_28(data)          ((0xF0000000&(data))>>28)
#define STATUS_FIFO_VODISP_BUF_get_vodisp_buf_wptr(data)              ((0x0FFF0000&(data))>>16)
#define STATUS_FIFO_VODISP_BUF_get_dummy18026088_15_12(data)          ((0x0000F000&(data))>>12)
#define STATUS_FIFO_VODISP_BUF_get_vodisp_buf_rptr(data)              (0x00000FFF&(data))


#define STATUS_FIFO_COMM                                              0x1802608c
#define STATUS_FIFO_COMM_reg_addr                                     "0xb802608c"
#define STATUS_FIFO_COMM_reg                                          0xb802608c
#define STATUS_FIFO_COMM_inst_addr                                    "0x0023"
#define STATUS_FIFO_COMM_inst                                         0x0023
#define set_STATUS_FIFO_COMM_reg(data)                                (*((volatile unsigned int*)STATUS_FIFO_COMM_reg)=data)
#define get_STATUS_FIFO_COMM_reg                                      (*((volatile unsigned int*)STATUS_FIFO_COMM_reg))
#define STATUS_FIFO_COMM_dummy1802608c_31_24_shift                    (24)
#define STATUS_FIFO_COMM_full_gated_dispd_shift                       (23)
#define STATUS_FIFO_COMM_full_gated_vodma3_shift                      (22)
#define STATUS_FIFO_COMM_reint_hd_fifo_full_shift                     (21)
#define STATUS_FIFO_COMM_reint_sd_fifo_full_shift                     (20)
#define STATUS_FIFO_COMM_vodisp_buf_fifo_full_shift                   (19)
#define STATUS_FIFO_COMM_h_unfl_shift                                 (18)
#define STATUS_FIFO_COMM_p_unfl_shift                                 (17)
#define STATUS_FIFO_COMM_i_unfl_shift                                 (16)
#define STATUS_FIFO_COMM_status_en_shift                              (8)
#define STATUS_FIFO_COMM_irq_en_shift                                 (0)
#define STATUS_FIFO_COMM_dummy1802608c_31_24_mask                     (0xFF000000)
#define STATUS_FIFO_COMM_full_gated_dispd_mask                        (0x00800000)
#define STATUS_FIFO_COMM_full_gated_vodma3_mask                       (0x00400000)
#define STATUS_FIFO_COMM_reint_hd_fifo_full_mask                      (0x00200000)
#define STATUS_FIFO_COMM_reint_sd_fifo_full_mask                      (0x00100000)
#define STATUS_FIFO_COMM_vodisp_buf_fifo_full_mask                    (0x00080000)
#define STATUS_FIFO_COMM_h_unfl_mask                                  (0x00040000)
#define STATUS_FIFO_COMM_p_unfl_mask                                  (0x00020000)
#define STATUS_FIFO_COMM_i_unfl_mask                                  (0x00010000)
#define STATUS_FIFO_COMM_status_en_mask                               (0x0000FF00)
#define STATUS_FIFO_COMM_irq_en_mask                                  (0x000000FF)
#define STATUS_FIFO_COMM_dummy1802608c_31_24(data)                    (0xFF000000&((data)<<24))
#define STATUS_FIFO_COMM_full_gated_dispd(data)                       (0x00800000&((data)<<23))
#define STATUS_FIFO_COMM_full_gated_vodma3(data)                      (0x00400000&((data)<<22))
#define STATUS_FIFO_COMM_reint_hd_fifo_full(data)                     (0x00200000&((data)<<21))
#define STATUS_FIFO_COMM_reint_sd_fifo_full(data)                     (0x00100000&((data)<<20))
#define STATUS_FIFO_COMM_vodisp_buf_fifo_full(data)                   (0x00080000&((data)<<19))
#define STATUS_FIFO_COMM_h_unfl(data)                                 (0x00040000&((data)<<18))
#define STATUS_FIFO_COMM_p_unfl(data)                                 (0x00020000&((data)<<17))
#define STATUS_FIFO_COMM_i_unfl(data)                                 (0x00010000&((data)<<16))
#define STATUS_FIFO_COMM_status_en(data)                              (0x0000FF00&((data)<<8))
#define STATUS_FIFO_COMM_irq_en(data)                                 (0x000000FF&(data))
#define STATUS_FIFO_COMM_get_dummy1802608c_31_24(data)                ((0xFF000000&(data))>>24)
#define STATUS_FIFO_COMM_get_full_gated_dispd(data)                   ((0x00800000&(data))>>23)
#define STATUS_FIFO_COMM_get_full_gated_vodma3(data)                  ((0x00400000&(data))>>22)
#define STATUS_FIFO_COMM_get_reint_hd_fifo_full(data)                 ((0x00200000&(data))>>21)
#define STATUS_FIFO_COMM_get_reint_sd_fifo_full(data)                 ((0x00100000&(data))>>20)
#define STATUS_FIFO_COMM_get_vodisp_buf_fifo_full(data)               ((0x00080000&(data))>>19)
#define STATUS_FIFO_COMM_get_h_unfl(data)                             ((0x00040000&(data))>>18)
#define STATUS_FIFO_COMM_get_p_unfl(data)                             ((0x00020000&(data))>>17)
#define STATUS_FIFO_COMM_get_i_unfl(data)                             ((0x00010000&(data))>>16)
#define STATUS_FIFO_COMM_get_status_en(data)                          ((0x0000FF00&(data))>>8)
#define STATUS_FIFO_COMM_get_irq_en(data)                             (0x000000FF&(data))


#define DISP2TVE_DB_CTRL                                              0x18026090
#define DISP2TVE_DB_CTRL_reg_addr                                     "0xb8026090"
#define DISP2TVE_DB_CTRL_reg                                          0xb8026090
#define DISP2TVE_DB_CTRL_inst_addr                                    "0x0024"
#define DISP2TVE_DB_CTRL_inst                                         0x0024
#define set_DISP2TVE_DB_CTRL_reg(data)                                (*((volatile unsigned int*)DISP2TVE_DB_CTRL_reg)=data)
#define get_DISP2TVE_DB_CTRL_reg                                      (*((volatile unsigned int*)DISP2TVE_DB_CTRL_reg))
#define DISP2TVE_DB_CTRL_vodisp_buf_db_en_shift                       (18)
#define DISP2TVE_DB_CTRL_vodisp_buf_db_read_sel_shift                 (17)
#define DISP2TVE_DB_CTRL_vodisp_buf_db_apply_shift                    (16)
#define DISP2TVE_DB_CTRL_reint_sd_db_en_shift                         (14)
#define DISP2TVE_DB_CTRL_reint_sd_db_read_sel_shift                   (13)
#define DISP2TVE_DB_CTRL_reint_sd_db_apply_shift                      (12)
#define DISP2TVE_DB_CTRL_reint_hd_db_en_shift                         (10)
#define DISP2TVE_DB_CTRL_reint_hd_db_read_sel_shift                   (9)
#define DISP2TVE_DB_CTRL_reint_hd_db_apply_shift                      (8)
#define DISP2TVE_DB_CTRL_tve_p_vbi_db_en_shift                        (6)
#define DISP2TVE_DB_CTRL_tve_p_vbi_db_read_sel_shift                  (5)
#define DISP2TVE_DB_CTRL_tve_p_vbi_db_apply_shift                     (4)
#define DISP2TVE_DB_CTRL_tve_i_vbi_db_en_shift                        (2)
#define DISP2TVE_DB_CTRL_tve_i_vbi_db_read_sel_shift                  (1)
#define DISP2TVE_DB_CTRL_tve_i_vbi_db_apply_shift                     (0)
#define DISP2TVE_DB_CTRL_vodisp_buf_db_en_mask                        (0x00040000)
#define DISP2TVE_DB_CTRL_vodisp_buf_db_read_sel_mask                  (0x00020000)
#define DISP2TVE_DB_CTRL_vodisp_buf_db_apply_mask                     (0x00010000)
#define DISP2TVE_DB_CTRL_reint_sd_db_en_mask                          (0x00004000)
#define DISP2TVE_DB_CTRL_reint_sd_db_read_sel_mask                    (0x00002000)
#define DISP2TVE_DB_CTRL_reint_sd_db_apply_mask                       (0x00001000)
#define DISP2TVE_DB_CTRL_reint_hd_db_en_mask                          (0x00000400)
#define DISP2TVE_DB_CTRL_reint_hd_db_read_sel_mask                    (0x00000200)
#define DISP2TVE_DB_CTRL_reint_hd_db_apply_mask                       (0x00000100)
#define DISP2TVE_DB_CTRL_tve_p_vbi_db_en_mask                         (0x00000040)
#define DISP2TVE_DB_CTRL_tve_p_vbi_db_read_sel_mask                   (0x00000020)
#define DISP2TVE_DB_CTRL_tve_p_vbi_db_apply_mask                      (0x00000010)
#define DISP2TVE_DB_CTRL_tve_i_vbi_db_en_mask                         (0x00000004)
#define DISP2TVE_DB_CTRL_tve_i_vbi_db_read_sel_mask                   (0x00000002)
#define DISP2TVE_DB_CTRL_tve_i_vbi_db_apply_mask                      (0x00000001)
#define DISP2TVE_DB_CTRL_vodisp_buf_db_en(data)                       (0x00040000&((data)<<18))
#define DISP2TVE_DB_CTRL_vodisp_buf_db_read_sel(data)                 (0x00020000&((data)<<17))
#define DISP2TVE_DB_CTRL_vodisp_buf_db_apply(data)                    (0x00010000&((data)<<16))
#define DISP2TVE_DB_CTRL_reint_sd_db_en(data)                         (0x00004000&((data)<<14))
#define DISP2TVE_DB_CTRL_reint_sd_db_read_sel(data)                   (0x00002000&((data)<<13))
#define DISP2TVE_DB_CTRL_reint_sd_db_apply(data)                      (0x00001000&((data)<<12))
#define DISP2TVE_DB_CTRL_reint_hd_db_en(data)                         (0x00000400&((data)<<10))
#define DISP2TVE_DB_CTRL_reint_hd_db_read_sel(data)                   (0x00000200&((data)<<9))
#define DISP2TVE_DB_CTRL_reint_hd_db_apply(data)                      (0x00000100&((data)<<8))
#define DISP2TVE_DB_CTRL_tve_p_vbi_db_en(data)                        (0x00000040&((data)<<6))
#define DISP2TVE_DB_CTRL_tve_p_vbi_db_read_sel(data)                  (0x00000020&((data)<<5))
#define DISP2TVE_DB_CTRL_tve_p_vbi_db_apply(data)                     (0x00000010&((data)<<4))
#define DISP2TVE_DB_CTRL_tve_i_vbi_db_en(data)                        (0x00000004&((data)<<2))
#define DISP2TVE_DB_CTRL_tve_i_vbi_db_read_sel(data)                  (0x00000002&((data)<<1))
#define DISP2TVE_DB_CTRL_tve_i_vbi_db_apply(data)                     (0x00000001&(data))
#define DISP2TVE_DB_CTRL_get_vodisp_buf_db_en(data)                   ((0x00040000&(data))>>18)
#define DISP2TVE_DB_CTRL_get_vodisp_buf_db_read_sel(data)             ((0x00020000&(data))>>17)
#define DISP2TVE_DB_CTRL_get_vodisp_buf_db_apply(data)                ((0x00010000&(data))>>16)
#define DISP2TVE_DB_CTRL_get_reint_sd_db_en(data)                     ((0x00004000&(data))>>14)
#define DISP2TVE_DB_CTRL_get_reint_sd_db_read_sel(data)               ((0x00002000&(data))>>13)
#define DISP2TVE_DB_CTRL_get_reint_sd_db_apply(data)                  ((0x00001000&(data))>>12)
#define DISP2TVE_DB_CTRL_get_reint_hd_db_en(data)                     ((0x00000400&(data))>>10)
#define DISP2TVE_DB_CTRL_get_reint_hd_db_read_sel(data)               ((0x00000200&(data))>>9)
#define DISP2TVE_DB_CTRL_get_reint_hd_db_apply(data)                  ((0x00000100&(data))>>8)
#define DISP2TVE_DB_CTRL_get_tve_p_vbi_db_en(data)                    ((0x00000040&(data))>>6)
#define DISP2TVE_DB_CTRL_get_tve_p_vbi_db_read_sel(data)              ((0x00000020&(data))>>5)
#define DISP2TVE_DB_CTRL_get_tve_p_vbi_db_apply(data)                 ((0x00000010&(data))>>4)
#define DISP2TVE_DB_CTRL_get_tve_i_vbi_db_en(data)                    ((0x00000004&(data))>>2)
#define DISP2TVE_DB_CTRL_get_tve_i_vbi_db_read_sel(data)              ((0x00000002&(data))>>1)
#define DISP2TVE_DB_CTRL_get_tve_i_vbi_db_apply(data)                 (0x00000001&(data))


#define STATUS_TIMING_REINT_SD                                        0x18026094
#define STATUS_TIMING_REINT_SD_reg_addr                               "0xb8026094"
#define STATUS_TIMING_REINT_SD_reg                                    0xb8026094
#define STATUS_TIMING_REINT_SD_inst_addr                              "0x0025"
#define STATUS_TIMING_REINT_SD_inst                                   0x0025
#define set_STATUS_TIMING_REINT_SD_reg(data)                          (*((volatile unsigned int*)STATUS_TIMING_REINT_SD_reg)=data)
#define get_STATUS_TIMING_REINT_SD_reg                                (*((volatile unsigned int*)STATUS_TIMING_REINT_SD_reg))
#define STATUS_TIMING_REINT_SD_dummy18026094_31_16_shift              (16)
#define STATUS_TIMING_REINT_SD_real_dum3_shift                        (0)
#define STATUS_TIMING_REINT_SD_dummy18026094_31_16_mask               (0xFFFF0000)
#define STATUS_TIMING_REINT_SD_real_dum3_mask                         (0x0000FFFF)
#define STATUS_TIMING_REINT_SD_dummy18026094_31_16(data)              (0xFFFF0000&((data)<<16))
#define STATUS_TIMING_REINT_SD_real_dum3(data)                        (0x0000FFFF&(data))
#define STATUS_TIMING_REINT_SD_get_dummy18026094_31_16(data)          ((0xFFFF0000&(data))>>16)
#define STATUS_TIMING_REINT_SD_get_real_dum3(data)                    (0x0000FFFF&(data))


#define STATUS_TIMING_VODISP_BUF                                      0x18026098
#define STATUS_TIMING_VODISP_BUF_reg_addr                             "0xb8026098"
#define STATUS_TIMING_VODISP_BUF_reg                                  0xb8026098
#define STATUS_TIMING_VODISP_BUF_inst_addr                            "0x0026"
#define STATUS_TIMING_VODISP_BUF_inst                                 0x0026
#define set_STATUS_TIMING_VODISP_BUF_reg(data)                        (*((volatile unsigned int*)STATUS_TIMING_VODISP_BUF_reg)=data)
#define get_STATUS_TIMING_VODISP_BUF_reg                              (*((volatile unsigned int*)STATUS_TIMING_VODISP_BUF_reg))
#define STATUS_TIMING_VODISP_BUF_dummy18026098_31_16_shift            (16)
#define STATUS_TIMING_VODISP_BUF_real_dum4_shift                      (0)
#define STATUS_TIMING_VODISP_BUF_dummy18026098_31_16_mask             (0xFFFF0000)
#define STATUS_TIMING_VODISP_BUF_real_dum4_mask                       (0x0000FFFF)
#define STATUS_TIMING_VODISP_BUF_dummy18026098_31_16(data)            (0xFFFF0000&((data)<<16))
#define STATUS_TIMING_VODISP_BUF_real_dum4(data)                      (0x0000FFFF&(data))
#define STATUS_TIMING_VODISP_BUF_get_dummy18026098_31_16(data)        ((0xFFFF0000&(data))>>16)
#define STATUS_TIMING_VODISP_BUF_get_real_dum4(data)                  (0x0000FFFF&(data))


#define REINT_HD_BIST                                                 0x180260a0
#define REINT_HD_BIST_reg_addr                                        "0xb80260a0"
#define REINT_HD_BIST_reg                                             0xb80260a0
#define REINT_HD_BIST_inst_addr                                       "0x0028"
#define REINT_HD_BIST_inst                                            0x0028
#define set_REINT_HD_BIST_reg(data)                                   (*((volatile unsigned int*)REINT_HD_BIST_reg)=data)
#define get_REINT_HD_BIST_reg                                         (*((volatile unsigned int*)REINT_HD_BIST_reg))
#define REINT_HD_BIST_ls_shift                                        (17)
#define REINT_HD_BIST_rm_shift                                        (13)
#define REINT_HD_BIST_rme_shift                                       (12)
#define REINT_HD_BIST_drf_bist_fail_shift                             (8)
#define REINT_HD_BIST_drf_bist_done_shift                             (7)
#define REINT_HD_BIST_drf_pause_shift                                 (6)
#define REINT_HD_BIST_drf_resume_shift                                (5)
#define REINT_HD_BIST_drf_bist_mode_shift                             (4)
#define REINT_HD_BIST_bist_fail_shift                                 (2)
#define REINT_HD_BIST_bist_done_shift                                 (1)
#define REINT_HD_BIST_bist_mode_shift                                 (0)
#define REINT_HD_BIST_ls_mask                                         (0x00020000)
#define REINT_HD_BIST_rm_mask                                         (0x0001E000)
#define REINT_HD_BIST_rme_mask                                        (0x00001000)
#define REINT_HD_BIST_drf_bist_fail_mask                              (0x00000100)
#define REINT_HD_BIST_drf_bist_done_mask                              (0x00000080)
#define REINT_HD_BIST_drf_pause_mask                                  (0x00000040)
#define REINT_HD_BIST_drf_resume_mask                                 (0x00000020)
#define REINT_HD_BIST_drf_bist_mode_mask                              (0x00000010)
#define REINT_HD_BIST_bist_fail_mask                                  (0x00000004)
#define REINT_HD_BIST_bist_done_mask                                  (0x00000002)
#define REINT_HD_BIST_bist_mode_mask                                  (0x00000001)
#define REINT_HD_BIST_ls(data)                                        (0x00020000&((data)<<17))
#define REINT_HD_BIST_rm(data)                                        (0x0001E000&((data)<<13))
#define REINT_HD_BIST_rme(data)                                       (0x00001000&((data)<<12))
#define REINT_HD_BIST_drf_bist_fail(data)                             (0x00000100&((data)<<8))
#define REINT_HD_BIST_drf_bist_done(data)                             (0x00000080&((data)<<7))
#define REINT_HD_BIST_drf_pause(data)                                 (0x00000040&((data)<<6))
#define REINT_HD_BIST_drf_resume(data)                                (0x00000020&((data)<<5))
#define REINT_HD_BIST_drf_bist_mode(data)                             (0x00000010&((data)<<4))
#define REINT_HD_BIST_bist_fail(data)                                 (0x00000004&((data)<<2))
#define REINT_HD_BIST_bist_done(data)                                 (0x00000002&((data)<<1))
#define REINT_HD_BIST_bist_mode(data)                                 (0x00000001&(data))
#define REINT_HD_BIST_get_ls(data)                                    ((0x00020000&(data))>>17)
#define REINT_HD_BIST_get_rm(data)                                    ((0x0001E000&(data))>>13)
#define REINT_HD_BIST_get_rme(data)                                   ((0x00001000&(data))>>12)
#define REINT_HD_BIST_get_drf_bist_fail(data)                         ((0x00000100&(data))>>8)
#define REINT_HD_BIST_get_drf_bist_done(data)                         ((0x00000080&(data))>>7)
#define REINT_HD_BIST_get_drf_pause(data)                             ((0x00000040&(data))>>6)
#define REINT_HD_BIST_get_drf_resume(data)                            ((0x00000020&(data))>>5)
#define REINT_HD_BIST_get_drf_bist_mode(data)                         ((0x00000010&(data))>>4)
#define REINT_HD_BIST_get_bist_fail(data)                             ((0x00000004&(data))>>2)
#define REINT_HD_BIST_get_bist_done(data)                             ((0x00000002&(data))>>1)
#define REINT_HD_BIST_get_bist_mode(data)                             (0x00000001&(data))


#define REINT_SD_BIST                                                 0x180260a4
#define REINT_SD_BIST_reg_addr                                        "0xb80260a4"
#define REINT_SD_BIST_reg                                             0xb80260a4
#define REINT_SD_BIST_inst_addr                                       "0x0029"
#define REINT_SD_BIST_inst                                            0x0029
#define set_REINT_SD_BIST_reg(data)                                   (*((volatile unsigned int*)REINT_SD_BIST_reg)=data)
#define get_REINT_SD_BIST_reg                                         (*((volatile unsigned int*)REINT_SD_BIST_reg))
#define REINT_SD_BIST_ls_shift                                        (17)
#define REINT_SD_BIST_rm_shift                                        (13)
#define REINT_SD_BIST_rme_shift                                       (12)
#define REINT_SD_BIST_drf_bist_fail_shift                             (8)
#define REINT_SD_BIST_drf_bist_done_shift                             (7)
#define REINT_SD_BIST_drf_pause_shift                                 (6)
#define REINT_SD_BIST_drf_resume_shift                                (5)
#define REINT_SD_BIST_drf_bist_mode_shift                             (4)
#define REINT_SD_BIST_bist_fail_shift                                 (2)
#define REINT_SD_BIST_bist_done_shift                                 (1)
#define REINT_SD_BIST_bist_mode_shift                                 (0)
#define REINT_SD_BIST_ls_mask                                         (0x00020000)
#define REINT_SD_BIST_rm_mask                                         (0x0001E000)
#define REINT_SD_BIST_rme_mask                                        (0x00001000)
#define REINT_SD_BIST_drf_bist_fail_mask                              (0x00000100)
#define REINT_SD_BIST_drf_bist_done_mask                              (0x00000080)
#define REINT_SD_BIST_drf_pause_mask                                  (0x00000040)
#define REINT_SD_BIST_drf_resume_mask                                 (0x00000020)
#define REINT_SD_BIST_drf_bist_mode_mask                              (0x00000010)
#define REINT_SD_BIST_bist_fail_mask                                  (0x00000004)
#define REINT_SD_BIST_bist_done_mask                                  (0x00000002)
#define REINT_SD_BIST_bist_mode_mask                                  (0x00000001)
#define REINT_SD_BIST_ls(data)                                        (0x00020000&((data)<<17))
#define REINT_SD_BIST_rm(data)                                        (0x0001E000&((data)<<13))
#define REINT_SD_BIST_rme(data)                                       (0x00001000&((data)<<12))
#define REINT_SD_BIST_drf_bist_fail(data)                             (0x00000100&((data)<<8))
#define REINT_SD_BIST_drf_bist_done(data)                             (0x00000080&((data)<<7))
#define REINT_SD_BIST_drf_pause(data)                                 (0x00000040&((data)<<6))
#define REINT_SD_BIST_drf_resume(data)                                (0x00000020&((data)<<5))
#define REINT_SD_BIST_drf_bist_mode(data)                             (0x00000010&((data)<<4))
#define REINT_SD_BIST_bist_fail(data)                                 (0x00000004&((data)<<2))
#define REINT_SD_BIST_bist_done(data)                                 (0x00000002&((data)<<1))
#define REINT_SD_BIST_bist_mode(data)                                 (0x00000001&(data))
#define REINT_SD_BIST_get_ls(data)                                    ((0x00020000&(data))>>17)
#define REINT_SD_BIST_get_rm(data)                                    ((0x0001E000&(data))>>13)
#define REINT_SD_BIST_get_rme(data)                                   ((0x00001000&(data))>>12)
#define REINT_SD_BIST_get_drf_bist_fail(data)                         ((0x00000100&(data))>>8)
#define REINT_SD_BIST_get_drf_bist_done(data)                         ((0x00000080&(data))>>7)
#define REINT_SD_BIST_get_drf_pause(data)                             ((0x00000040&(data))>>6)
#define REINT_SD_BIST_get_drf_resume(data)                            ((0x00000020&(data))>>5)
#define REINT_SD_BIST_get_drf_bist_mode(data)                         ((0x00000010&(data))>>4)
#define REINT_SD_BIST_get_bist_fail(data)                             ((0x00000004&(data))>>2)
#define REINT_SD_BIST_get_bist_done(data)                             ((0x00000002&(data))>>1)
#define REINT_SD_BIST_get_bist_mode(data)                             (0x00000001&(data))


#define VO_BUF_BIST                                                   0x180260a8
#define VO_BUF_BIST_reg_addr                                          "0xb80260a8"
#define VO_BUF_BIST_reg                                               0xb80260a8
#define VO_BUF_BIST_inst_addr                                         "0x002A"
#define VO_BUF_BIST_inst                                              0x002A
#define set_VO_BUF_BIST_reg(data)                                     (*((volatile unsigned int*)VO_BUF_BIST_reg)=data)
#define get_VO_BUF_BIST_reg                                           (*((volatile unsigned int*)VO_BUF_BIST_reg))
#define VO_BUF_BIST_ls_shift                                          (17)
#define VO_BUF_BIST_rm_shift                                          (13)
#define VO_BUF_BIST_rme_shift                                         (12)
#define VO_BUF_BIST_drf_bist_fail_shift                               (8)
#define VO_BUF_BIST_drf_bist_done_shift                               (7)
#define VO_BUF_BIST_drf_pause_shift                                   (6)
#define VO_BUF_BIST_drf_resume_shift                                  (5)
#define VO_BUF_BIST_drf_bist_mode_shift                               (4)
#define VO_BUF_BIST_bist_fail_shift                                   (2)
#define VO_BUF_BIST_bist_done_shift                                   (1)
#define VO_BUF_BIST_bist_mode_shift                                   (0)
#define VO_BUF_BIST_ls_mask                                           (0x00020000)
#define VO_BUF_BIST_rm_mask                                           (0x0001E000)
#define VO_BUF_BIST_rme_mask                                          (0x00001000)
#define VO_BUF_BIST_drf_bist_fail_mask                                (0x00000100)
#define VO_BUF_BIST_drf_bist_done_mask                                (0x00000080)
#define VO_BUF_BIST_drf_pause_mask                                    (0x00000040)
#define VO_BUF_BIST_drf_resume_mask                                   (0x00000020)
#define VO_BUF_BIST_drf_bist_mode_mask                                (0x00000010)
#define VO_BUF_BIST_bist_fail_mask                                    (0x00000004)
#define VO_BUF_BIST_bist_done_mask                                    (0x00000002)
#define VO_BUF_BIST_bist_mode_mask                                    (0x00000001)
#define VO_BUF_BIST_ls(data)                                          (0x00020000&((data)<<17))
#define VO_BUF_BIST_rm(data)                                          (0x0001E000&((data)<<13))
#define VO_BUF_BIST_rme(data)                                         (0x00001000&((data)<<12))
#define VO_BUF_BIST_drf_bist_fail(data)                               (0x00000100&((data)<<8))
#define VO_BUF_BIST_drf_bist_done(data)                               (0x00000080&((data)<<7))
#define VO_BUF_BIST_drf_pause(data)                                   (0x00000040&((data)<<6))
#define VO_BUF_BIST_drf_resume(data)                                  (0x00000020&((data)<<5))
#define VO_BUF_BIST_drf_bist_mode(data)                               (0x00000010&((data)<<4))
#define VO_BUF_BIST_bist_fail(data)                                   (0x00000004&((data)<<2))
#define VO_BUF_BIST_bist_done(data)                                   (0x00000002&((data)<<1))
#define VO_BUF_BIST_bist_mode(data)                                   (0x00000001&(data))
#define VO_BUF_BIST_get_ls(data)                                      ((0x00020000&(data))>>17)
#define VO_BUF_BIST_get_rm(data)                                      ((0x0001E000&(data))>>13)
#define VO_BUF_BIST_get_rme(data)                                     ((0x00001000&(data))>>12)
#define VO_BUF_BIST_get_drf_bist_fail(data)                           ((0x00000100&(data))>>8)
#define VO_BUF_BIST_get_drf_bist_done(data)                           ((0x00000080&(data))>>7)
#define VO_BUF_BIST_get_drf_pause(data)                               ((0x00000040&(data))>>6)
#define VO_BUF_BIST_get_drf_resume(data)                              ((0x00000020&(data))>>5)
#define VO_BUF_BIST_get_drf_bist_mode(data)                           ((0x00000010&(data))>>4)
#define VO_BUF_BIST_get_bist_fail(data)                               ((0x00000004&(data))>>2)
#define VO_BUF_BIST_get_bist_done(data)                               ((0x00000002&(data))>>1)
#define VO_BUF_BIST_get_bist_mode(data)                               (0x00000001&(data))


#define TVE_MP_PTG                                                    0x180260c0
#define TVE_MP_PTG_reg_addr                                           "0xb80260c0"
#define TVE_MP_PTG_reg                                                0xb80260c0
#define TVE_MP_PTG_inst_addr                                          "0x0030"
#define TVE_MP_PTG_inst                                               0x0030
#define set_TVE_MP_PTG_reg(data)                                      (*((volatile unsigned int*)TVE_MP_PTG_reg)=data)
#define get_TVE_MP_PTG_reg                                            (*((volatile unsigned int*)TVE_MP_PTG_reg))
#define TVE_MP_PTG_dummy180260c0_31_24_shift                          (24)
#define TVE_MP_PTG_dummy180260c0_23_14_shift                          (14)
#define TVE_MP_PTG_real_dum_shift                                     (6)
#define TVE_MP_PTG_ramp_tvep_mode_shift                               (5)
#define TVE_MP_PTG_ramp_tvep_en_shift                                 (4)
#define TVE_MP_PTG_ramp_tvep_step_shift                               (2)
#define TVE_MP_PTG_ramp_tvep_pol_shift                                (1)
#define TVE_MP_PTG_ramp_test_go_shift                                 (0)
#define TVE_MP_PTG_dummy180260c0_31_24_mask                           (0xFF000000)
#define TVE_MP_PTG_dummy180260c0_23_14_mask                           (0x00FFC000)
#define TVE_MP_PTG_real_dum_mask                                      (0x00003FC0)
#define TVE_MP_PTG_ramp_tvep_mode_mask                                (0x00000020)
#define TVE_MP_PTG_ramp_tvep_en_mask                                  (0x00000010)
#define TVE_MP_PTG_ramp_tvep_step_mask                                (0x0000000C)
#define TVE_MP_PTG_ramp_tvep_pol_mask                                 (0x00000002)
#define TVE_MP_PTG_ramp_test_go_mask                                  (0x00000001)
#define TVE_MP_PTG_dummy180260c0_31_24(data)                          (0xFF000000&((data)<<24))
#define TVE_MP_PTG_dummy180260c0_23_14(data)                          (0x00FFC000&((data)<<14))
#define TVE_MP_PTG_real_dum(data)                                     (0x00003FC0&((data)<<6))
#define TVE_MP_PTG_ramp_tvep_mode(data)                               (0x00000020&((data)<<5))
#define TVE_MP_PTG_ramp_tvep_en(data)                                 (0x00000010&((data)<<4))
#define TVE_MP_PTG_ramp_tvep_step(data)                               (0x0000000C&((data)<<2))
#define TVE_MP_PTG_ramp_tvep_pol(data)                                (0x00000002&((data)<<1))
#define TVE_MP_PTG_ramp_test_go(data)                                 (0x00000001&(data))
#define TVE_MP_PTG_get_dummy180260c0_31_24(data)                      ((0xFF000000&(data))>>24)
#define TVE_MP_PTG_get_dummy180260c0_23_14(data)                      ((0x00FFC000&(data))>>14)
#define TVE_MP_PTG_get_real_dum(data)                                 ((0x00003FC0&(data))>>6)
#define TVE_MP_PTG_get_ramp_tvep_mode(data)                           ((0x00000020&(data))>>5)
#define TVE_MP_PTG_get_ramp_tvep_en(data)                             ((0x00000010&(data))>>4)
#define TVE_MP_PTG_get_ramp_tvep_step(data)                           ((0x0000000C&(data))>>2)
#define TVE_MP_PTG_get_ramp_tvep_pol(data)                            ((0x00000002&(data))>>1)
#define TVE_MP_PTG_get_ramp_test_go(data)                             (0x00000001&(data))


#define MP_SRAM_SET                                                   0x180260c4
#define MP_SRAM_SET_reg_addr                                          "0xb80260c4"
#define MP_SRAM_SET_reg                                               0xb80260c4
#define MP_SRAM_SET_inst_addr                                         "0x0031"
#define MP_SRAM_SET_inst                                              0x0031
#define set_MP_SRAM_SET_reg(data)                                     (*((volatile unsigned int*)MP_SRAM_SET_reg)=data)
#define get_MP_SRAM_SET_reg                                           (*((volatile unsigned int*)MP_SRAM_SET_reg))
#define MP_SRAM_SET_dummy180260c4_31_15_shift                         (15)
#define MP_SRAM_SET_sram_data_length_shift                            (4)
#define MP_SRAM_SET_sram_acc_mode_shift                               (2)
#define MP_SRAM_SET_sram_pat_go_shift                                 (1)
#define MP_SRAM_SET_sram_test_en_shift                                (0)
#define MP_SRAM_SET_dummy180260c4_31_15_mask                          (0xFFFF8000)
#define MP_SRAM_SET_sram_data_length_mask                             (0x00007FF0)
#define MP_SRAM_SET_sram_acc_mode_mask                                (0x0000000C)
#define MP_SRAM_SET_sram_pat_go_mask                                  (0x00000002)
#define MP_SRAM_SET_sram_test_en_mask                                 (0x00000001)
#define MP_SRAM_SET_dummy180260c4_31_15(data)                         (0xFFFF8000&((data)<<15))
#define MP_SRAM_SET_sram_data_length(data)                            (0x00007FF0&((data)<<4))
#define MP_SRAM_SET_sram_acc_mode(data)                               (0x0000000C&((data)<<2))
#define MP_SRAM_SET_sram_pat_go(data)                                 (0x00000002&((data)<<1))
#define MP_SRAM_SET_sram_test_en(data)                                (0x00000001&(data))
#define MP_SRAM_SET_get_dummy180260c4_31_15(data)                     ((0xFFFF8000&(data))>>15)
#define MP_SRAM_SET_get_sram_data_length(data)                        ((0x00007FF0&(data))>>4)
#define MP_SRAM_SET_get_sram_acc_mode(data)                           ((0x0000000C&(data))>>2)
#define MP_SRAM_SET_get_sram_pat_go(data)                             ((0x00000002&(data))>>1)
#define MP_SRAM_SET_get_sram_test_en(data)                            (0x00000001&(data))


#define MP_SRAM_ADDR                                                  0x180260c8
#define MP_SRAM_ADDR_reg_addr                                         "0xb80260c8"
#define MP_SRAM_ADDR_reg                                              0xb80260c8
#define MP_SRAM_ADDR_inst_addr                                        "0x0032"
#define MP_SRAM_ADDR_inst                                             0x0032
#define set_MP_SRAM_ADDR_reg(data)                                    (*((volatile unsigned int*)MP_SRAM_ADDR_reg)=data)
#define get_MP_SRAM_ADDR_reg                                          (*((volatile unsigned int*)MP_SRAM_ADDR_reg))
#define MP_SRAM_ADDR_sram_acc_addr_shift                              (0)
#define MP_SRAM_ADDR_sram_acc_addr_mask                               (0x000003FF)
#define MP_SRAM_ADDR_sram_acc_addr(data)                              (0x000003FF&(data))
#define MP_SRAM_ADDR_get_sram_acc_addr(data)                          (0x000003FF&(data))


#define MP_SRAM_LSB                                                   0x180260cc
#define MP_SRAM_LSB_reg_addr                                          "0xb80260cc"
#define MP_SRAM_LSB_reg                                               0xb80260cc
#define MP_SRAM_LSB_inst_addr                                         "0x0033"
#define MP_SRAM_LSB_inst                                              0x0033
#define set_MP_SRAM_LSB_reg(data)                                     (*((volatile unsigned int*)MP_SRAM_LSB_reg)=data)
#define get_MP_SRAM_LSB_reg                                           (*((volatile unsigned int*)MP_SRAM_LSB_reg))
#define MP_SRAM_LSB_sram_acc_lsb_shift                                (0)
#define MP_SRAM_LSB_sram_acc_lsb_mask                                 (0x00FFFFFF)
#define MP_SRAM_LSB_sram_acc_lsb(data)                                (0x00FFFFFF&(data))
#define MP_SRAM_LSB_get_sram_acc_lsb(data)                            (0x00FFFFFF&(data))


#define DISP2TVE_CRC_CTRL                                             0x180260d0
#define DISP2TVE_CRC_CTRL_reg_addr                                    "0xb80260d0"
#define DISP2TVE_CRC_CTRL_reg                                         0xb80260d0
#define DISP2TVE_CRC_CTRL_inst_addr                                   "0x0034"
#define DISP2TVE_CRC_CTRL_inst                                        0x0034
#define set_DISP2TVE_CRC_CTRL_reg(data)                               (*((volatile unsigned int*)DISP2TVE_CRC_CTRL_reg)=data)
#define get_DISP2TVE_CRC_CTRL_reg                                     (*((volatile unsigned int*)DISP2TVE_CRC_CTRL_reg))
#define DISP2TVE_CRC_CTRL_tve_i_crc_start_shift                       (9)
#define DISP2TVE_CRC_CTRL_tve_i_crc_conti_shift                       (8)
#define DISP2TVE_CRC_CTRL_tve_p_crc_start_shift                       (7)
#define DISP2TVE_CRC_CTRL_tve_p_crc_conti_shift                       (6)
#define DISP2TVE_CRC_CTRL_tve_h_crc_start_shift                       (5)
#define DISP2TVE_CRC_CTRL_tve_h_crc_conti_shift                       (4)
#define DISP2TVE_CRC_CTRL_vodma3_crc_start_shift                      (3)
#define DISP2TVE_CRC_CTRL_vodma3_crc_conti_shift                      (2)
#define DISP2TVE_CRC_CTRL_dispd_crc_start_shift                       (1)
#define DISP2TVE_CRC_CTRL_dispd_crc_conti_shift                       (0)
#define DISP2TVE_CRC_CTRL_tve_i_crc_start_mask                        (0x00000200)
#define DISP2TVE_CRC_CTRL_tve_i_crc_conti_mask                        (0x00000100)
#define DISP2TVE_CRC_CTRL_tve_p_crc_start_mask                        (0x00000080)
#define DISP2TVE_CRC_CTRL_tve_p_crc_conti_mask                        (0x00000040)
#define DISP2TVE_CRC_CTRL_tve_h_crc_start_mask                        (0x00000020)
#define DISP2TVE_CRC_CTRL_tve_h_crc_conti_mask                        (0x00000010)
#define DISP2TVE_CRC_CTRL_vodma3_crc_start_mask                       (0x00000008)
#define DISP2TVE_CRC_CTRL_vodma3_crc_conti_mask                       (0x00000004)
#define DISP2TVE_CRC_CTRL_dispd_crc_start_mask                        (0x00000002)
#define DISP2TVE_CRC_CTRL_dispd_crc_conti_mask                        (0x00000001)
#define DISP2TVE_CRC_CTRL_tve_i_crc_start(data)                       (0x00000200&((data)<<9))
#define DISP2TVE_CRC_CTRL_tve_i_crc_conti(data)                       (0x00000100&((data)<<8))
#define DISP2TVE_CRC_CTRL_tve_p_crc_start(data)                       (0x00000080&((data)<<7))
#define DISP2TVE_CRC_CTRL_tve_p_crc_conti(data)                       (0x00000040&((data)<<6))
#define DISP2TVE_CRC_CTRL_tve_h_crc_start(data)                       (0x00000020&((data)<<5))
#define DISP2TVE_CRC_CTRL_tve_h_crc_conti(data)                       (0x00000010&((data)<<4))
#define DISP2TVE_CRC_CTRL_vodma3_crc_start(data)                      (0x00000008&((data)<<3))
#define DISP2TVE_CRC_CTRL_vodma3_crc_conti(data)                      (0x00000004&((data)<<2))
#define DISP2TVE_CRC_CTRL_dispd_crc_start(data)                       (0x00000002&((data)<<1))
#define DISP2TVE_CRC_CTRL_dispd_crc_conti(data)                       (0x00000001&(data))
#define DISP2TVE_CRC_CTRL_get_tve_i_crc_start(data)                   ((0x00000200&(data))>>9)
#define DISP2TVE_CRC_CTRL_get_tve_i_crc_conti(data)                   ((0x00000100&(data))>>8)
#define DISP2TVE_CRC_CTRL_get_tve_p_crc_start(data)                   ((0x00000080&(data))>>7)
#define DISP2TVE_CRC_CTRL_get_tve_p_crc_conti(data)                   ((0x00000040&(data))>>6)
#define DISP2TVE_CRC_CTRL_get_tve_h_crc_start(data)                   ((0x00000020&(data))>>5)
#define DISP2TVE_CRC_CTRL_get_tve_h_crc_conti(data)                   ((0x00000010&(data))>>4)
#define DISP2TVE_CRC_CTRL_get_vodma3_crc_start(data)                  ((0x00000008&(data))>>3)
#define DISP2TVE_CRC_CTRL_get_vodma3_crc_conti(data)                  ((0x00000004&(data))>>2)
#define DISP2TVE_CRC_CTRL_get_dispd_crc_start(data)                   ((0x00000002&(data))>>1)
#define DISP2TVE_CRC_CTRL_get_dispd_crc_conti(data)                   (0x00000001&(data))


#define DISPD_CRC_RESULT                                              0x180260d4
#define DISPD_CRC_RESULT_reg_addr                                     "0xb80260d4"
#define DISPD_CRC_RESULT_reg                                          0xb80260d4
#define DISPD_CRC_RESULT_inst_addr                                    "0x0035"
#define DISPD_CRC_RESULT_inst                                         0x0035
#define set_DISPD_CRC_RESULT_reg(data)                                (*((volatile unsigned int*)DISPD_CRC_RESULT_reg)=data)
#define get_DISPD_CRC_RESULT_reg                                      (*((volatile unsigned int*)DISPD_CRC_RESULT_reg))
#define DISPD_CRC_RESULT_dispd_crc_result_shift                       (0)
#define DISPD_CRC_RESULT_dispd_crc_result_mask                        (0xFFFFFFFF)
#define DISPD_CRC_RESULT_dispd_crc_result(data)                       (0xFFFFFFFF&(data))
#define DISPD_CRC_RESULT_get_dispd_crc_result(data)                   (0xFFFFFFFF&(data))


#define VODMA3_CRC_RESULT                                             0x180260d8
#define VODMA3_CRC_RESULT_reg_addr                                    "0xb80260d8"
#define VODMA3_CRC_RESULT_reg                                         0xb80260d8
#define VODMA3_CRC_RESULT_inst_addr                                   "0x0036"
#define VODMA3_CRC_RESULT_inst                                        0x0036
#define set_VODMA3_CRC_RESULT_reg(data)                               (*((volatile unsigned int*)VODMA3_CRC_RESULT_reg)=data)
#define get_VODMA3_CRC_RESULT_reg                                     (*((volatile unsigned int*)VODMA3_CRC_RESULT_reg))
#define VODMA3_CRC_RESULT_vodma3_crc_result_shift                     (0)
#define VODMA3_CRC_RESULT_vodma3_crc_result_mask                      (0xFFFFFFFF)
#define VODMA3_CRC_RESULT_vodma3_crc_result(data)                     (0xFFFFFFFF&(data))
#define VODMA3_CRC_RESULT_get_vodma3_crc_result(data)                 (0xFFFFFFFF&(data))


#define TVE_H_CRC_RESULT                                              0x180260dc
#define TVE_H_CRC_RESULT_reg_addr                                     "0xb80260dc"
#define TVE_H_CRC_RESULT_reg                                          0xb80260dc
#define TVE_H_CRC_RESULT_inst_addr                                    "0x0037"
#define TVE_H_CRC_RESULT_inst                                         0x0037
#define set_TVE_H_CRC_RESULT_reg(data)                                (*((volatile unsigned int*)TVE_H_CRC_RESULT_reg)=data)
#define get_TVE_H_CRC_RESULT_reg                                      (*((volatile unsigned int*)TVE_H_CRC_RESULT_reg))
#define TVE_H_CRC_RESULT_tve_h_crc_result_shift                       (0)
#define TVE_H_CRC_RESULT_tve_h_crc_result_mask                        (0xFFFFFFFF)
#define TVE_H_CRC_RESULT_tve_h_crc_result(data)                       (0xFFFFFFFF&(data))
#define TVE_H_CRC_RESULT_get_tve_h_crc_result(data)                   (0xFFFFFFFF&(data))


#define TVE_P_CRC_RESULT                                              0x180260e0
#define TVE_P_CRC_RESULT_reg_addr                                     "0xb80260e0"
#define TVE_P_CRC_RESULT_reg                                          0xb80260e0
#define TVE_P_CRC_RESULT_inst_addr                                    "0x0038"
#define TVE_P_CRC_RESULT_inst                                         0x0038
#define set_TVE_P_CRC_RESULT_reg(data)                                (*((volatile unsigned int*)TVE_P_CRC_RESULT_reg)=data)
#define get_TVE_P_CRC_RESULT_reg                                      (*((volatile unsigned int*)TVE_P_CRC_RESULT_reg))
#define TVE_P_CRC_RESULT_tve_p_crc_result_shift                       (0)
#define TVE_P_CRC_RESULT_tve_p_crc_result_mask                        (0xFFFFFFFF)
#define TVE_P_CRC_RESULT_tve_p_crc_result(data)                       (0xFFFFFFFF&(data))
#define TVE_P_CRC_RESULT_get_tve_p_crc_result(data)                   (0xFFFFFFFF&(data))


#define TVE_I_CRC_RESULT                                              0x180260e4
#define TVE_I_CRC_RESULT_reg_addr                                     "0xb80260e4"
#define TVE_I_CRC_RESULT_reg                                          0xb80260e4
#define TVE_I_CRC_RESULT_inst_addr                                    "0x0039"
#define TVE_I_CRC_RESULT_inst                                         0x0039
#define set_TVE_I_CRC_RESULT_reg(data)                                (*((volatile unsigned int*)TVE_I_CRC_RESULT_reg)=data)
#define get_TVE_I_CRC_RESULT_reg                                      (*((volatile unsigned int*)TVE_I_CRC_RESULT_reg))
#define TVE_I_CRC_RESULT_tve_i_crc_result_shift                       (0)
#define TVE_I_CRC_RESULT_tve_i_crc_result_mask                        (0xFFFFFFFF)
#define TVE_I_CRC_RESULT_tve_i_crc_result(data)                       (0xFFFFFFFF&(data))
#define TVE_I_CRC_RESULT_get_tve_i_crc_result(data)                   (0xFFFFFFFF&(data))


#define TVE_P_VBI                                                     0x180260e8
#define TVE_P_VBI_reg_addr                                            "0xb80260e8"
#define TVE_P_VBI_reg                                                 0xb80260e8
#define TVE_P_VBI_inst_addr                                           "0x003A"
#define TVE_P_VBI_inst                                                0x003A
#define set_TVE_P_VBI_reg(data)                                       (*((volatile unsigned int*)TVE_P_VBI_reg)=data)
#define get_TVE_P_VBI_reg                                             (*((volatile unsigned int*)TVE_P_VBI_reg))
#define TVE_P_VBI_tve_p_vbi_len_shift                                 (0)
#define TVE_P_VBI_tve_p_vbi_len_mask                                  (0x0003FFFF)
#define TVE_P_VBI_tve_p_vbi_len(data)                                 (0x0003FFFF&(data))
#define TVE_P_VBI_get_tve_p_vbi_len(data)                             (0x0003FFFF&(data))


#define TVE_I_VBI                                                     0x180260ec
#define TVE_I_VBI_reg_addr                                            "0xb80260ec"
#define TVE_I_VBI_reg                                                 0xb80260ec
#define TVE_I_VBI_inst_addr                                           "0x003B"
#define TVE_I_VBI_inst                                                0x003B
#define set_TVE_I_VBI_reg(data)                                       (*((volatile unsigned int*)TVE_I_VBI_reg)=data)
#define get_TVE_I_VBI_reg                                             (*((volatile unsigned int*)TVE_I_VBI_reg))
#define TVE_I_VBI_tve_i_vbi_len_shift                                 (0)
#define TVE_I_VBI_tve_i_vbi_len_mask                                  (0x0003FFFF)
#define TVE_I_VBI_tve_i_vbi_len(data)                                 (0x0003FFFF&(data))
#define TVE_I_VBI_get_tve_i_vbi_len(data)                             (0x0003FFFF&(data))


#define D2T_MB_PEAKING_CTRL                                           0x180260f0
#define D2T_MB_PEAKING_CTRL_reg_addr                                  "0xb80260f0"
#define D2T_MB_PEAKING_CTRL_reg                                       0xb80260f0
#define D2T_MB_PEAKING_CTRL_inst_addr                                 "0x003C"
#define D2T_MB_PEAKING_CTRL_inst                                      0x003C
#define set_D2T_MB_PEAKING_CTRL_reg(data)                             (*((volatile unsigned int*)D2T_MB_PEAKING_CTRL_reg)=data)
#define get_D2T_MB_PEAKING_CTRL_reg                                   (*((volatile unsigned int*)D2T_MB_PEAKING_CTRL_reg))
#define D2T_MB_PEAKING_CTRL_mb_peaking_en_shift                       (0)
#define D2T_MB_PEAKING_CTRL_mb_peaking_en_mask                        (0x00000001)
#define D2T_MB_PEAKING_CTRL_mb_peaking_en(data)                       (0x00000001&(data))
#define D2T_MB_PEAKING_CTRL_get_mb_peaking_en(data)                   (0x00000001&(data))


#define D2T_MB_PEAKING_FILTER_0                                       0x180260f4
#define D2T_MB_PEAKING_FILTER_0_reg_addr                              "0xb80260f4"
#define D2T_MB_PEAKING_FILTER_0_reg                                   0xb80260f4
#define D2T_MB_PEAKING_FILTER_0_inst_addr                             "0x003D"
#define D2T_MB_PEAKING_FILTER_0_inst                                  0x003D
#define set_D2T_MB_PEAKING_FILTER_0_reg(data)                         (*((volatile unsigned int*)D2T_MB_PEAKING_FILTER_0_reg)=data)
#define get_D2T_MB_PEAKING_FILTER_0_reg                               (*((volatile unsigned int*)D2T_MB_PEAKING_FILTER_0_reg))
#define D2T_MB_PEAKING_FILTER_0_sh_b0_shift                           (30)
#define D2T_MB_PEAKING_FILTER_0_sh_b1_shift                           (28)
#define D2T_MB_PEAKING_FILTER_0_c0_shift                              (16)
#define D2T_MB_PEAKING_FILTER_0_c1_shift                              (0)
#define D2T_MB_PEAKING_FILTER_0_sh_b0_mask                            (0xC0000000)
#define D2T_MB_PEAKING_FILTER_0_sh_b1_mask                            (0x30000000)
#define D2T_MB_PEAKING_FILTER_0_c0_mask                               (0x01FF0000)
#define D2T_MB_PEAKING_FILTER_0_c1_mask                               (0x000001FF)
#define D2T_MB_PEAKING_FILTER_0_sh_b0(data)                           (0xC0000000&((data)<<30))
#define D2T_MB_PEAKING_FILTER_0_sh_b1(data)                           (0x30000000&((data)<<28))
#define D2T_MB_PEAKING_FILTER_0_c0(data)                              (0x01FF0000&((data)<<16))
#define D2T_MB_PEAKING_FILTER_0_c1(data)                              (0x000001FF&(data))
#define D2T_MB_PEAKING_FILTER_0_get_sh_b0(data)                       ((0xC0000000&(data))>>30)
#define D2T_MB_PEAKING_FILTER_0_get_sh_b1(data)                       ((0x30000000&(data))>>28)
#define D2T_MB_PEAKING_FILTER_0_get_c0(data)                          ((0x01FF0000&(data))>>16)
#define D2T_MB_PEAKING_FILTER_0_get_c1(data)                          (0x000001FF&(data))


#define D2T_MB_PEAKING_FILTER_1                                       0x180260f8
#define D2T_MB_PEAKING_FILTER_1_reg_addr                              "0xb80260f8"
#define D2T_MB_PEAKING_FILTER_1_reg                                   0xb80260f8
#define D2T_MB_PEAKING_FILTER_1_inst_addr                             "0x003E"
#define D2T_MB_PEAKING_FILTER_1_inst                                  0x003E
#define set_D2T_MB_PEAKING_FILTER_1_reg(data)                         (*((volatile unsigned int*)D2T_MB_PEAKING_FILTER_1_reg)=data)
#define get_D2T_MB_PEAKING_FILTER_1_reg                               (*((volatile unsigned int*)D2T_MB_PEAKING_FILTER_1_reg))
#define D2T_MB_PEAKING_FILTER_1_c2_shift                              (24)
#define D2T_MB_PEAKING_FILTER_1_c3_shift                              (16)
#define D2T_MB_PEAKING_FILTER_1_c4_shift                              (8)
#define D2T_MB_PEAKING_FILTER_1_c5_shift                              (0)
#define D2T_MB_PEAKING_FILTER_1_c2_mask                               (0xFF000000)
#define D2T_MB_PEAKING_FILTER_1_c3_mask                               (0x007F0000)
#define D2T_MB_PEAKING_FILTER_1_c4_mask                               (0x00007F00)
#define D2T_MB_PEAKING_FILTER_1_c5_mask                               (0x0000003F)
#define D2T_MB_PEAKING_FILTER_1_c2(data)                              (0xFF000000&((data)<<24))
#define D2T_MB_PEAKING_FILTER_1_c3(data)                              (0x007F0000&((data)<<16))
#define D2T_MB_PEAKING_FILTER_1_c4(data)                              (0x00007F00&((data)<<8))
#define D2T_MB_PEAKING_FILTER_1_c5(data)                              (0x0000003F&(data))
#define D2T_MB_PEAKING_FILTER_1_get_c2(data)                          ((0xFF000000&(data))>>24)
#define D2T_MB_PEAKING_FILTER_1_get_c3(data)                          ((0x007F0000&(data))>>16)
#define D2T_MB_PEAKING_FILTER_1_get_c4(data)                          ((0x00007F00&(data))>>8)
#define D2T_MB_PEAKING_FILTER_1_get_c5(data)                          (0x0000003F&(data))


#define D2T_MB_PEAKING_FILTER_2                                       0x180260fc
#define D2T_MB_PEAKING_FILTER_2_reg_addr                              "0xb80260fc"
#define D2T_MB_PEAKING_FILTER_2_reg                                   0xb80260fc
#define D2T_MB_PEAKING_FILTER_2_inst_addr                             "0x003F"
#define D2T_MB_PEAKING_FILTER_2_inst                                  0x003F
#define set_D2T_MB_PEAKING_FILTER_2_reg(data)                         (*((volatile unsigned int*)D2T_MB_PEAKING_FILTER_2_reg)=data)
#define get_D2T_MB_PEAKING_FILTER_2_reg                               (*((volatile unsigned int*)D2T_MB_PEAKING_FILTER_2_reg))
#define D2T_MB_PEAKING_FILTER_2_c6_shift                              (0)
#define D2T_MB_PEAKING_FILTER_2_c6_mask                               (0x0000003F)
#define D2T_MB_PEAKING_FILTER_2_c6(data)                              (0x0000003F&(data))
#define D2T_MB_PEAKING_FILTER_2_get_c6(data)                          (0x0000003F&(data))


#define D2T_MB_PEAKING_GAIN                                           0x18026100
#define D2T_MB_PEAKING_GAIN_reg_addr                                  "0xb8026100"
#define D2T_MB_PEAKING_GAIN_reg                                       0xb8026100
#define D2T_MB_PEAKING_GAIN_inst_addr                                 "0x0040"
#define D2T_MB_PEAKING_GAIN_inst                                      0x0040
#define set_D2T_MB_PEAKING_GAIN_reg(data)                             (*((volatile unsigned int*)D2T_MB_PEAKING_GAIN_reg)=data)
#define get_D2T_MB_PEAKING_GAIN_reg                                   (*((volatile unsigned int*)D2T_MB_PEAKING_GAIN_reg))
#define D2T_MB_PEAKING_GAIN_lv_shift                                  (24)
#define D2T_MB_PEAKING_GAIN_gain_blr_shift                            (16)
#define D2T_MB_PEAKING_GAIN_gain_pos_shift                            (8)
#define D2T_MB_PEAKING_GAIN_gain_neg_shift                            (0)
#define D2T_MB_PEAKING_GAIN_lv_mask                                   (0xFF000000)
#define D2T_MB_PEAKING_GAIN_gain_blr_mask                             (0x00FF0000)
#define D2T_MB_PEAKING_GAIN_gain_pos_mask                             (0x0000FF00)
#define D2T_MB_PEAKING_GAIN_gain_neg_mask                             (0x000000FF)
#define D2T_MB_PEAKING_GAIN_lv(data)                                  (0xFF000000&((data)<<24))
#define D2T_MB_PEAKING_GAIN_gain_blr(data)                            (0x00FF0000&((data)<<16))
#define D2T_MB_PEAKING_GAIN_gain_pos(data)                            (0x0000FF00&((data)<<8))
#define D2T_MB_PEAKING_GAIN_gain_neg(data)                            (0x000000FF&(data))
#define D2T_MB_PEAKING_GAIN_get_lv(data)                              ((0xFF000000&(data))>>24)
#define D2T_MB_PEAKING_GAIN_get_gain_blr(data)                        ((0x00FF0000&(data))>>16)
#define D2T_MB_PEAKING_GAIN_get_gain_pos(data)                        ((0x0000FF00&(data))>>8)
#define D2T_MB_PEAKING_GAIN_get_gain_neg(data)                        (0x000000FF&(data))


#define D2T_MB_PEAKING_BOUND                                          0x18026104
#define D2T_MB_PEAKING_BOUND_reg_addr                                 "0xb8026104"
#define D2T_MB_PEAKING_BOUND_reg                                      0xb8026104
#define D2T_MB_PEAKING_BOUND_inst_addr                                "0x0041"
#define D2T_MB_PEAKING_BOUND_inst                                     0x0041
#define set_D2T_MB_PEAKING_BOUND_reg(data)                            (*((volatile unsigned int*)D2T_MB_PEAKING_BOUND_reg)=data)
#define get_D2T_MB_PEAKING_BOUND_reg                                  (*((volatile unsigned int*)D2T_MB_PEAKING_BOUND_reg))
#define D2T_MB_PEAKING_BOUND_hv_pos_shift                             (16)
#define D2T_MB_PEAKING_BOUND_hv_neg_shift                             (0)
#define D2T_MB_PEAKING_BOUND_hv_pos_mask                              (0x03FF0000)
#define D2T_MB_PEAKING_BOUND_hv_neg_mask                              (0x000003FF)
#define D2T_MB_PEAKING_BOUND_hv_pos(data)                             (0x03FF0000&((data)<<16))
#define D2T_MB_PEAKING_BOUND_hv_neg(data)                             (0x000003FF&(data))
#define D2T_MB_PEAKING_BOUND_get_hv_pos(data)                         ((0x03FF0000&(data))>>16)
#define D2T_MB_PEAKING_BOUND_get_hv_neg(data)                         (0x000003FF&(data))


#define D2T_MB_DOUBLE_BUFFER_CTRL                                     0x18026108
#define D2T_MB_DOUBLE_BUFFER_CTRL_reg_addr                            "0xb8026108"
#define D2T_MB_DOUBLE_BUFFER_CTRL_reg                                 0xb8026108
#define D2T_MB_DOUBLE_BUFFER_CTRL_inst_addr                           "0x0042"
#define D2T_MB_DOUBLE_BUFFER_CTRL_inst                                0x0042
#define set_D2T_MB_DOUBLE_BUFFER_CTRL_reg(data)                       (*((volatile unsigned int*)D2T_MB_DOUBLE_BUFFER_CTRL_reg)=data)
#define get_D2T_MB_DOUBLE_BUFFER_CTRL_reg                             (*((volatile unsigned int*)D2T_MB_DOUBLE_BUFFER_CTRL_reg))
#define D2T_MB_DOUBLE_BUFFER_CTRL_mb_db_en_shift                      (2)
#define D2T_MB_DOUBLE_BUFFER_CTRL_mb_db_read_sel_shift                (1)
#define D2T_MB_DOUBLE_BUFFER_CTRL_mb_db_apply_shift                   (0)
#define D2T_MB_DOUBLE_BUFFER_CTRL_mb_db_en_mask                       (0x00000004)
#define D2T_MB_DOUBLE_BUFFER_CTRL_mb_db_read_sel_mask                 (0x00000002)
#define D2T_MB_DOUBLE_BUFFER_CTRL_mb_db_apply_mask                    (0x00000001)
#define D2T_MB_DOUBLE_BUFFER_CTRL_mb_db_en(data)                      (0x00000004&((data)<<2))
#define D2T_MB_DOUBLE_BUFFER_CTRL_mb_db_read_sel(data)                (0x00000002&((data)<<1))
#define D2T_MB_DOUBLE_BUFFER_CTRL_mb_db_apply(data)                   (0x00000001&(data))
#define D2T_MB_DOUBLE_BUFFER_CTRL_get_mb_db_en(data)                  ((0x00000004&(data))>>2)
#define D2T_MB_DOUBLE_BUFFER_CTRL_get_mb_db_read_sel(data)            ((0x00000002&(data))>>1)
#define D2T_MB_DOUBLE_BUFFER_CTRL_get_mb_db_apply(data)               (0x00000001&(data))


#define D2T_MB_DUMMY                                                  0x1802610c
#define D2T_MB_DUMMY_reg_addr                                         "0xb802610c"
#define D2T_MB_DUMMY_reg                                              0xb802610c
#define D2T_MB_DUMMY_inst_addr                                        "0x0043"
#define D2T_MB_DUMMY_inst                                             0x0043
#define set_D2T_MB_DUMMY_reg(data)                                    (*((volatile unsigned int*)D2T_MB_DUMMY_reg)=data)
#define get_D2T_MB_DUMMY_reg                                          (*((volatile unsigned int*)D2T_MB_DUMMY_reg))
#define D2T_MB_DUMMY_dummy1802610c_7_0_shift                          (0)
#define D2T_MB_DUMMY_dummy1802610c_7_0_mask                           (0x000000FF)
#define D2T_MB_DUMMY_dummy1802610c_7_0(data)                          (0x000000FF&(data))
#define D2T_MB_DUMMY_get_dummy1802610c_7_0(data)                      (0x000000FF&(data))
#endif
