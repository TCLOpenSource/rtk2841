// This file is generated using the spec version 1.39, firmware template version 1.39and SRIF Parser                                                                                source code SVN rev:802                    Version flow no.:1.1.68
#ifndef _PATTERNGEN_REG_H_INCLUDED_
#define _PATTERNGEN_REG_H_INCLUDED_

//#define  _PATTERNGEN_USE_STRUCT
#ifdef _PATTERNGEN_USE_STRUCT

typedef struct
{
    unsigned int    reserved_0:3;
    unsigned int    totalh_pixel:13;
    unsigned int    dummy18022100_15_13:3;
    unsigned int    totalv_line:13;
}PTG_totalhv;

typedef struct
{
    unsigned int    reserved_0:3;
    unsigned int    act_h_sta:13;
    unsigned int    dummy18022104_15_13:3;
    unsigned int    act_wid:13;
}PTG_act_h_start_width;

typedef struct
{
    unsigned int    reserved_0:3;
    unsigned int    act_v_sta:13;
    unsigned int    dummy18022108_15_13:3;
    unsigned int    act_len:13;
}PTG_act_v_start_length;

typedef struct
{
    unsigned int    reserved_0:18;
    unsigned int    demo_4k2k_en:1;
    unsigned int    sync_timing_sel:1;
    unsigned int    pat_cover_en:1;
    unsigned int    pat_cover:1;
    unsigned int    hs_highpulse_wid:2;
    unsigned int    dummy1802210c_7:1;
    unsigned int    fix_l_flag:1;
    unsigned int    fix_l_flag_en:1;
    unsigned int    active_space_fix_en:1;
    unsigned int    tg_mode_sel:2;
    unsigned int    tg_en_field:1;
    unsigned int    tg_enable:1;
}PTG_tg;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    popup_linecnt:1;
    unsigned int    cur_l_flag_out:1;
    unsigned int    cur_field_out:1;
    unsigned int    cur_linecnt_out:13;
}PTG_tg_line;

typedef struct
{
    unsigned int    reserved_0:3;
    unsigned int    pat_h_sta_l:13;
    unsigned int    dummy18022114_15_13:3;
    unsigned int    pat_wid_l:13;
}PTG_l_pat_hsta_width;

typedef struct
{
    unsigned int    reserved_0:3;
    unsigned int    pat_v_sta_l:13;
    unsigned int    dummy18022118_15_13:3;
    unsigned int    pat_len_l:13;
}PTG_l_pat_vsta_length;

typedef struct
{
    unsigned int    reserved_0:21;
    unsigned int    ptg_db_rdy:1;
    unsigned int    ptg_db_en:1;
    unsigned int    en_rdm_bkg_l:1;
    unsigned int    xc_seq_l:3;
    unsigned int    en_xc_l:1;
    unsigned int    pat_mode_l:4;
}PTG_l_ctrl;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    auto_state_l:2;
    unsigned int    hold_state_l:2;
    unsigned int    hold_state_rdy_l:1;
    unsigned int    barw_l:11;
}PTG_l_barw;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    i_c0y_92b_l:8;
    unsigned int    i_c0cr_92b_l:8;
    unsigned int    i_c0cb_92b_l:8;
}PTG_l_c0y_cb_cr;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    i_c1y_92b_l:8;
    unsigned int    i_c1cr_92b_l:8;
    unsigned int    i_c1cb_92b_l:8;
}PTG_l_c1y_cb_cr;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    i_c2y_92b_l:8;
    unsigned int    i_c2cr_92b_l:8;
    unsigned int    i_c2cb_92b_l:8;
}PTG_l_c2y_cb_cr;

typedef struct
{
    unsigned int    i_c3y_98b_l:2;
    unsigned int    i_c3y_72b_grady_l:6;
    unsigned int    i_c3cr_98b_l:2;
    unsigned int    i_c3cr_72b_gradcr_l:6;
    unsigned int    i_c3cb_98b_l:2;
    unsigned int    i_c3cb_72b_gradcb_l:6;
    unsigned int    dummy18022130_7_0:8;
}PTG_l_c3y_cb_cr;

typedef struct
{
    unsigned int    i_c4y_96b_l:4;
    unsigned int    i_c4y_52b_step_hv_l:4;
    unsigned int    i_c4cr_92b_l:8;
    unsigned int    i_c4cb_9b_l:1;
    unsigned int    i_c4cb_86b_bmp_w_l:3;
    unsigned int    i_c4cb_5b_l:1;
    unsigned int    i_c4cb_42b_bmp_h_l:3;
    unsigned int    reserved_0:8;
}PTG_l_c4y_cb_cr;

typedef struct
{
    unsigned int    i_c5y_92b_bmptp_l:8;
    unsigned int    i_c5cr_92b_bmp0_l:8;
    unsigned int    i_c5cb_92b_bmp1_l:8;
    unsigned int    dummy18022138_7_0:8;
}PTG_l_c5y_cr_cb;

typedef struct
{
    unsigned int    i_c6y_92b_bmp2_l:8;
    unsigned int    i_c6cr_92b_bmp3_l:8;
    unsigned int    i_c6cb_92b_bmp4_l:8;
    unsigned int    nonactive_color_def_l:8;
}PTG_l_c6y_cb_cr;

typedef struct
{
    unsigned int    i_c7y_92b_bmp5_l:8;
    unsigned int    i_c7cr_92b_bmp6_l:8;
    unsigned int    i_c7cb_92b_bmp7_l:8;
    unsigned int    dummy18022140_7_3:5;
    unsigned int    max_color_l:3;
}PTG_l_c7y_cb_cr;

typedef struct
{
    unsigned int    mv_h_l:8;
    unsigned int    mv_v_l:8;
    unsigned int    mv_seq_type_l:1;
    unsigned int    rdm_period_l:3;
    unsigned int    mv_vs_num_l:4;
    unsigned int    mp_adj_num_l:8;
}PTG_l_max_color_ctrl;

typedef struct
{
    unsigned int    reserved_0:3;
    unsigned int    pat_h_sta_r:13;
    unsigned int    dummy18022148_15_13:3;
    unsigned int    pat_wid_r:13;
}PTG_r_pat_hsta_width;

typedef struct
{
    unsigned int    reserved_0:3;
    unsigned int    pat_v_sta_r:13;
    unsigned int    dummy1802214c_15_13:3;
    unsigned int    pat_len_r:13;
}PTG_r_pat_vsta_length;

typedef struct
{
    unsigned int    reserved_0:23;
    unsigned int    en_rdm_bkg_r:1;
    unsigned int    xc_seq_r:3;
    unsigned int    en_xc_r:1;
    unsigned int    pat_mode_r:4;
}PTG_r_ctrl;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    auto_state_r:2;
    unsigned int    hold_state_r:2;
    unsigned int    hold_state_rdy_r:1;
    unsigned int    barw_r:11;
}PTG_r_barw;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    i_c0y_92b_r:8;
    unsigned int    i_c0cr_92b_r:8;
    unsigned int    i_c0cb_92b_r:8;
}PTG_r_c0y_cb_cr;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    i_c1y_92b_r:8;
    unsigned int    i_c1cr_92b_r:8;
    unsigned int    i_c1cb_92b_r:8;
}PTG_r_c1y_cb_cr;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    i_c2y_92b_r:8;
    unsigned int    i_c2cr_92b_r:8;
    unsigned int    i_c2cb_92b_r:8;
}PTG_r_c2y_cb_cr;

typedef struct
{
    unsigned int    i_c3y_98b_r:2;
    unsigned int    i_c3y_72b_grady_r:6;
    unsigned int    i_c3cr_98b_r:2;
    unsigned int    i_c3cr_72b_gradcr_r:6;
    unsigned int    i_c3cb_98b_r:2;
    unsigned int    i_c3cb_72b_gradcb_r:6;
    unsigned int    dummy18022164_7_0:8;
}PTG_r_c3y_cb_cr;

typedef struct
{
    unsigned int    i_c4y_96b_r:4;
    unsigned int    i_c4y_52b_step_hv_r:4;
    unsigned int    i_c4cr_92b_r:8;
    unsigned int    i_c4cb_9b_r:1;
    unsigned int    i_c4cb_86b_bmp_w_r:3;
    unsigned int    i_c4cb_5b_r:1;
    unsigned int    i_c4cb_42b_bmp_h_r:3;
    unsigned int    reserved_0:8;
}PTG_r_c4y_cb_cr;

typedef struct
{
    unsigned int    i_c5y_92b_bmptp_r:8;
    unsigned int    i_c5cr_92b_bmp0_r:8;
    unsigned int    i_c5cb_92b_bmp1_r:8;
    unsigned int    dummy1802216c_7_0:8;
}PTG_r_c5y_cr_cb;

typedef struct
{
    unsigned int    i_c6y_92b_bmp2_r:8;
    unsigned int    i_c6cr_92b_bmp3_r:8;
    unsigned int    i_c6cb_92b_bmp4_r:8;
    unsigned int    nonactive_color_def_r:8;
}PTG_r_c6y_cb_cr;

typedef struct
{
    unsigned int    i_c7y_92b_bmp5_r:8;
    unsigned int    i_c7cr_92b_bmp6_r:8;
    unsigned int    i_c7cb_92b_bmp7_r:8;
    unsigned int    dummy18022174_7_3:5;
    unsigned int    max_color_r:3;
}PTG_r_c7y_cb_cr;

typedef struct
{
    unsigned int    mv_h_r:8;
    unsigned int    mv_v_r:8;
    unsigned int    mv_seq_type_r:1;
    unsigned int    rdm_period_r:3;
    unsigned int    mv_vs_num_r:4;
    unsigned int    mp_adj_num_r:8;
}PTG_r_max_color_ctrl;

typedef struct
{
    unsigned int    reserved_0:5;
    unsigned int    chess_v_size:11;
    unsigned int    reserved_1:2;
    unsigned int    grad_sub_pix_en:1;
    unsigned int    grad_cbar_en:1;
    unsigned int    reserved_2:4;
    unsigned int    grad_cbar_pos:1;
    unsigned int    grad_sub_pix_on_mask:3;
    unsigned int    grad_cbar_step_hv:4;
}PTG_cmi_ctrl1;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    y_bright_en:8;
    unsigned int    cb_bright_en:8;
    unsigned int    cr_bright_en:8;
}PTG_cmi_ctrl2;

typedef struct
{
    unsigned int    reserved_0:20;
    unsigned int    bmp_sub_pix_en:1;
    unsigned int    reserved_1:1;
    unsigned int    bright:10;
}PTG_cmi_ctrl3;

typedef struct
{
    unsigned int    reserved_0:7;
    unsigned int    color_ext_en:1;
    unsigned int    i_c3y_ext:2;
    unsigned int    i_c3cb_ext:2;
    unsigned int    i_c3cr_ext:2;
    unsigned int    i_c2y_ext:2;
    unsigned int    i_c2cr_ext:2;
    unsigned int    i_c2cb_ext:2;
    unsigned int    i_c1y_ext:2;
    unsigned int    i_c1cr_ext:2;
    unsigned int    i_c1cb_ext:2;
    unsigned int    i_c0y_ext:2;
    unsigned int    i_c0cr_ext:2;
    unsigned int    i_c0cb_ext:2;
}PTG_color_extend1;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    i_c7y_ext:2;
    unsigned int    i_c7cb_ext:2;
    unsigned int    i_c7cr_ext:2;
    unsigned int    i_c6y_ext:2;
    unsigned int    i_c6cr_ext:2;
    unsigned int    i_c6cb_ext:2;
    unsigned int    i_c5y_ext:2;
    unsigned int    i_c5cr_ext:2;
    unsigned int    i_c5cb_ext:2;
    unsigned int    i_c4y_ext:2;
    unsigned int    i_c4cr_ext:2;
    unsigned int    i_c4cb_ext:2;
}PTG_color_extend2;
#endif


#define PTG_TOTALHV                                                   0x18022100
#define PTG_TOTALHV_reg_addr                                          "0xb8022100"
#define PTG_TOTALHV_reg                                               0xb8022100
#define PTG_TOTALHV_inst_addr                                         "0x0040"
#define PTG_TOTALHV_inst                                              0x0040
#define PTG_TOTALHV_totalh_pixel_shift                                (16)
#define PTG_TOTALHV_dummy18022100_15_13_shift                         (13)
#define PTG_TOTALHV_totalv_line_shift                                 (0)
#define PTG_TOTALHV_totalh_pixel_mask                                 (0x1FFF0000)
#define PTG_TOTALHV_dummy18022100_15_13_mask                          (0x0000E000)
#define PTG_TOTALHV_totalv_line_mask                                  (0x00001FFF)
#define PTG_TOTALHV_totalh_pixel(data)                                (0x1FFF0000&((data)<<16))
#define PTG_TOTALHV_dummy18022100_15_13(data)                         (0x0000E000&((data)<<13))
#define PTG_TOTALHV_totalv_line(data)                                 (0x00001FFF&(data))
#define PTG_TOTALHV_get_totalh_pixel(data)                            ((0x1FFF0000&(data))>>16)
#define PTG_TOTALHV_get_dummy18022100_15_13(data)                     ((0x0000E000&(data))>>13)
#define PTG_TOTALHV_get_totalv_line(data)                             (0x00001FFF&(data))


#define PTG_ACT_H_START_WIDTH                                         0x18022104
#define PTG_ACT_H_START_WIDTH_reg_addr                                "0xb8022104"
#define PTG_ACT_H_START_WIDTH_reg                                     0xb8022104
#define PTG_ACT_H_START_WIDTH_inst_addr                               "0x0041"
#define PTG_ACT_H_START_WIDTH_inst                                    0x0041
#define PTG_ACT_H_START_WIDTH_act_h_sta_shift                         (16)
#define PTG_ACT_H_START_WIDTH_dummy18022104_15_13_shift               (13)
#define PTG_ACT_H_START_WIDTH_act_wid_shift                           (0)
#define PTG_ACT_H_START_WIDTH_act_h_sta_mask                          (0x1FFF0000)
#define PTG_ACT_H_START_WIDTH_dummy18022104_15_13_mask                (0x0000E000)
#define PTG_ACT_H_START_WIDTH_act_wid_mask                            (0x00001FFF)
#define PTG_ACT_H_START_WIDTH_act_h_sta(data)                         (0x1FFF0000&((data)<<16))
#define PTG_ACT_H_START_WIDTH_dummy18022104_15_13(data)               (0x0000E000&((data)<<13))
#define PTG_ACT_H_START_WIDTH_act_wid(data)                           (0x00001FFF&(data))
#define PTG_ACT_H_START_WIDTH_get_act_h_sta(data)                     ((0x1FFF0000&(data))>>16)
#define PTG_ACT_H_START_WIDTH_get_dummy18022104_15_13(data)           ((0x0000E000&(data))>>13)
#define PTG_ACT_H_START_WIDTH_get_act_wid(data)                       (0x00001FFF&(data))


#define PTG_ACT_V_START_LENGTH                                        0x18022108
#define PTG_ACT_V_START_LENGTH_reg_addr                               "0xb8022108"
#define PTG_ACT_V_START_LENGTH_reg                                    0xb8022108
#define PTG_ACT_V_START_LENGTH_inst_addr                              "0x0042"
#define PTG_ACT_V_START_LENGTH_inst                                   0x0042
#define PTG_ACT_V_START_LENGTH_act_v_sta_shift                        (16)
#define PTG_ACT_V_START_LENGTH_dummy18022108_15_13_shift              (13)
#define PTG_ACT_V_START_LENGTH_act_len_shift                          (0)
#define PTG_ACT_V_START_LENGTH_act_v_sta_mask                         (0x1FFF0000)
#define PTG_ACT_V_START_LENGTH_dummy18022108_15_13_mask               (0x0000E000)
#define PTG_ACT_V_START_LENGTH_act_len_mask                           (0x00001FFF)
#define PTG_ACT_V_START_LENGTH_act_v_sta(data)                        (0x1FFF0000&((data)<<16))
#define PTG_ACT_V_START_LENGTH_dummy18022108_15_13(data)              (0x0000E000&((data)<<13))
#define PTG_ACT_V_START_LENGTH_act_len(data)                          (0x00001FFF&(data))
#define PTG_ACT_V_START_LENGTH_get_act_v_sta(data)                    ((0x1FFF0000&(data))>>16)
#define PTG_ACT_V_START_LENGTH_get_dummy18022108_15_13(data)          ((0x0000E000&(data))>>13)
#define PTG_ACT_V_START_LENGTH_get_act_len(data)                      (0x00001FFF&(data))


#define PTG_TG                                                        0x1802210c
#define PTG_TG_reg_addr                                               "0xb802210c"
#define PTG_TG_reg                                                    0xb802210c
#define PTG_TG_inst_addr                                              "0x0043"
#define PTG_TG_inst                                                   0x0043
#define PTG_TG_demo_4k2k_en_shift                                     (13)
#define PTG_TG_sync_timing_sel_shift                                  (12)
#define PTG_TG_pat_cover_en_shift                                     (11)
#define PTG_TG_pat_cover_shift                                        (10)
#define PTG_TG_hs_highpulse_wid_shift                                 (8)
#define PTG_TG_dummy1802210c_7_shift                                  (7)
#define PTG_TG_fix_l_flag_shift                                       (6)
#define PTG_TG_fix_l_flag_en_shift                                    (5)
#define PTG_TG_active_space_fix_en_shift                              (4)
#define PTG_TG_tg_mode_sel_shift                                      (2)
#define PTG_TG_tg_en_field_shift                                      (1)
#define PTG_TG_tg_enable_shift                                        (0)
#define PTG_TG_demo_4k2k_en_mask                                      (0x00002000)
#define PTG_TG_sync_timing_sel_mask                                   (0x00001000)
#define PTG_TG_pat_cover_en_mask                                      (0x00000800)
#define PTG_TG_pat_cover_mask                                         (0x00000400)
#define PTG_TG_hs_highpulse_wid_mask                                  (0x00000300)
#define PTG_TG_dummy1802210c_7_mask                                   (0x00000080)
#define PTG_TG_fix_l_flag_mask                                        (0x00000040)
#define PTG_TG_fix_l_flag_en_mask                                     (0x00000020)
#define PTG_TG_active_space_fix_en_mask                               (0x00000010)
#define PTG_TG_tg_mode_sel_mask                                       (0x0000000C)
#define PTG_TG_tg_en_field_mask                                       (0x00000002)
#define PTG_TG_tg_enable_mask                                         (0x00000001)
#define PTG_TG_demo_4k2k_en(data)                                     (0x00002000&((data)<<13))
#define PTG_TG_sync_timing_sel(data)                                  (0x00001000&((data)<<12))
#define PTG_TG_pat_cover_en(data)                                     (0x00000800&((data)<<11))
#define PTG_TG_pat_cover(data)                                        (0x00000400&((data)<<10))
#define PTG_TG_hs_highpulse_wid(data)                                 (0x00000300&((data)<<8))
#define PTG_TG_dummy1802210c_7(data)                                  (0x00000080&((data)<<7))
#define PTG_TG_fix_l_flag(data)                                       (0x00000040&((data)<<6))
#define PTG_TG_fix_l_flag_en(data)                                    (0x00000020&((data)<<5))
#define PTG_TG_active_space_fix_en(data)                              (0x00000010&((data)<<4))
#define PTG_TG_tg_mode_sel(data)                                      (0x0000000C&((data)<<2))
#define PTG_TG_tg_en_field(data)                                      (0x00000002&((data)<<1))
#define PTG_TG_tg_enable(data)                                        (0x00000001&(data))
#define PTG_TG_get_demo_4k2k_en(data)                                 ((0x00002000&(data))>>13)
#define PTG_TG_get_sync_timing_sel(data)                              ((0x00001000&(data))>>12)
#define PTG_TG_get_pat_cover_en(data)                                 ((0x00000800&(data))>>11)
#define PTG_TG_get_pat_cover(data)                                    ((0x00000400&(data))>>10)
#define PTG_TG_get_hs_highpulse_wid(data)                             ((0x00000300&(data))>>8)
#define PTG_TG_get_dummy1802210c_7(data)                              ((0x00000080&(data))>>7)
#define PTG_TG_get_fix_l_flag(data)                                   ((0x00000040&(data))>>6)
#define PTG_TG_get_fix_l_flag_en(data)                                ((0x00000020&(data))>>5)
#define PTG_TG_get_active_space_fix_en(data)                          ((0x00000010&(data))>>4)
#define PTG_TG_get_tg_mode_sel(data)                                  ((0x0000000C&(data))>>2)
#define PTG_TG_get_tg_en_field(data)                                  ((0x00000002&(data))>>1)
#define PTG_TG_get_tg_enable(data)                                    (0x00000001&(data))


#define PTG_TG_LINE                                                   0x18022110
#define PTG_TG_LINE_reg_addr                                          "0xb8022110"
#define PTG_TG_LINE_reg                                               0xb8022110
#define PTG_TG_LINE_inst_addr                                         "0x0044"
#define PTG_TG_LINE_inst                                              0x0044
#define PTG_TG_LINE_popup_linecnt_shift                               (15)
#define PTG_TG_LINE_cur_l_flag_out_shift                              (14)
#define PTG_TG_LINE_cur_field_out_shift                               (13)
#define PTG_TG_LINE_cur_linecnt_out_shift                             (0)
#define PTG_TG_LINE_popup_linecnt_mask                                (0x00008000)
#define PTG_TG_LINE_cur_l_flag_out_mask                               (0x00004000)
#define PTG_TG_LINE_cur_field_out_mask                                (0x00002000)
#define PTG_TG_LINE_cur_linecnt_out_mask                              (0x00001FFF)
#define PTG_TG_LINE_popup_linecnt(data)                               (0x00008000&((data)<<15))
#define PTG_TG_LINE_cur_l_flag_out(data)                              (0x00004000&((data)<<14))
#define PTG_TG_LINE_cur_field_out(data)                               (0x00002000&((data)<<13))
#define PTG_TG_LINE_cur_linecnt_out(data)                             (0x00001FFF&(data))
#define PTG_TG_LINE_get_popup_linecnt(data)                           ((0x00008000&(data))>>15)
#define PTG_TG_LINE_get_cur_l_flag_out(data)                          ((0x00004000&(data))>>14)
#define PTG_TG_LINE_get_cur_field_out(data)                           ((0x00002000&(data))>>13)
#define PTG_TG_LINE_get_cur_linecnt_out(data)                         (0x00001FFF&(data))


#define PTG_L_PAT_HSTA_WIDTH                                          0x18022114
#define PTG_L_PAT_HSTA_WIDTH_reg_addr                                 "0xb8022114"
#define PTG_L_PAT_HSTA_WIDTH_reg                                      0xb8022114
#define PTG_L_PAT_HSTA_WIDTH_inst_addr                                "0x0045"
#define PTG_L_PAT_HSTA_WIDTH_inst                                     0x0045
#define PTG_L_PAT_HSTA_WIDTH_pat_h_sta_l_shift                        (16)
#define PTG_L_PAT_HSTA_WIDTH_dummy18022114_15_13_shift                (13)
#define PTG_L_PAT_HSTA_WIDTH_pat_wid_l_shift                          (0)
#define PTG_L_PAT_HSTA_WIDTH_pat_h_sta_l_mask                         (0x1FFF0000)
#define PTG_L_PAT_HSTA_WIDTH_dummy18022114_15_13_mask                 (0x0000E000)
#define PTG_L_PAT_HSTA_WIDTH_pat_wid_l_mask                           (0x00001FFF)
#define PTG_L_PAT_HSTA_WIDTH_pat_h_sta_l(data)                        (0x1FFF0000&((data)<<16))
#define PTG_L_PAT_HSTA_WIDTH_dummy18022114_15_13(data)                (0x0000E000&((data)<<13))
#define PTG_L_PAT_HSTA_WIDTH_pat_wid_l(data)                          (0x00001FFF&(data))
#define PTG_L_PAT_HSTA_WIDTH_get_pat_h_sta_l(data)                    ((0x1FFF0000&(data))>>16)
#define PTG_L_PAT_HSTA_WIDTH_get_dummy18022114_15_13(data)            ((0x0000E000&(data))>>13)
#define PTG_L_PAT_HSTA_WIDTH_get_pat_wid_l(data)                      (0x00001FFF&(data))


#define PTG_L_PAT_VSTA_LENGTH                                         0x18022118
#define PTG_L_PAT_VSTA_LENGTH_reg_addr                                "0xb8022118"
#define PTG_L_PAT_VSTA_LENGTH_reg                                     0xb8022118
#define PTG_L_PAT_VSTA_LENGTH_inst_addr                               "0x0046"
#define PTG_L_PAT_VSTA_LENGTH_inst                                    0x0046
#define PTG_L_PAT_VSTA_LENGTH_pat_v_sta_l_shift                       (16)
#define PTG_L_PAT_VSTA_LENGTH_dummy18022118_15_13_shift               (13)
#define PTG_L_PAT_VSTA_LENGTH_pat_len_l_shift                         (0)
#define PTG_L_PAT_VSTA_LENGTH_pat_v_sta_l_mask                        (0x1FFF0000)
#define PTG_L_PAT_VSTA_LENGTH_dummy18022118_15_13_mask                (0x0000E000)
#define PTG_L_PAT_VSTA_LENGTH_pat_len_l_mask                          (0x00001FFF)
#define PTG_L_PAT_VSTA_LENGTH_pat_v_sta_l(data)                       (0x1FFF0000&((data)<<16))
#define PTG_L_PAT_VSTA_LENGTH_dummy18022118_15_13(data)               (0x0000E000&((data)<<13))
#define PTG_L_PAT_VSTA_LENGTH_pat_len_l(data)                         (0x00001FFF&(data))
#define PTG_L_PAT_VSTA_LENGTH_get_pat_v_sta_l(data)                   ((0x1FFF0000&(data))>>16)
#define PTG_L_PAT_VSTA_LENGTH_get_dummy18022118_15_13(data)           ((0x0000E000&(data))>>13)
#define PTG_L_PAT_VSTA_LENGTH_get_pat_len_l(data)                     (0x00001FFF&(data))


#define PTG_L_CTRL                                                    0x1802211c
#define PTG_L_CTRL_reg_addr                                           "0xb802211c"
#define PTG_L_CTRL_reg                                                0xb802211c
#define PTG_L_CTRL_inst_addr                                          "0x0047"
#define PTG_L_CTRL_inst                                               0x0047
#define PTG_L_CTRL_ptg_db_rdy_shift                                   (10)
#define PTG_L_CTRL_ptg_db_en_shift                                    (9)
#define PTG_L_CTRL_en_rdm_bkg_l_shift                                 (8)
#define PTG_L_CTRL_xc_seq_l_shift                                     (5)
#define PTG_L_CTRL_en_xc_l_shift                                      (4)
#define PTG_L_CTRL_pat_mode_l_shift                                   (0)
#define PTG_L_CTRL_ptg_db_rdy_mask                                    (0x00000400)
#define PTG_L_CTRL_ptg_db_en_mask                                     (0x00000200)
#define PTG_L_CTRL_en_rdm_bkg_l_mask                                  (0x00000100)
#define PTG_L_CTRL_xc_seq_l_mask                                      (0x000000E0)
#define PTG_L_CTRL_en_xc_l_mask                                       (0x00000010)
#define PTG_L_CTRL_pat_mode_l_mask                                    (0x0000000F)
#define PTG_L_CTRL_ptg_db_rdy(data)                                   (0x00000400&((data)<<10))
#define PTG_L_CTRL_ptg_db_en(data)                                    (0x00000200&((data)<<9))
#define PTG_L_CTRL_en_rdm_bkg_l(data)                                 (0x00000100&((data)<<8))
#define PTG_L_CTRL_xc_seq_l(data)                                     (0x000000E0&((data)<<5))
#define PTG_L_CTRL_en_xc_l(data)                                      (0x00000010&((data)<<4))
#define PTG_L_CTRL_pat_mode_l(data)                                   (0x0000000F&(data))
#define PTG_L_CTRL_get_ptg_db_rdy(data)                               ((0x00000400&(data))>>10)
#define PTG_L_CTRL_get_ptg_db_en(data)                                ((0x00000200&(data))>>9)
#define PTG_L_CTRL_get_en_rdm_bkg_l(data)                             ((0x00000100&(data))>>8)
#define PTG_L_CTRL_get_xc_seq_l(data)                                 ((0x000000E0&(data))>>5)
#define PTG_L_CTRL_get_en_xc_l(data)                                  ((0x00000010&(data))>>4)
#define PTG_L_CTRL_get_pat_mode_l(data)                               (0x0000000F&(data))


#define PTG_L_BARW                                                    0x18022120
#define PTG_L_BARW_reg_addr                                           "0xb8022120"
#define PTG_L_BARW_reg                                                0xb8022120
#define PTG_L_BARW_inst_addr                                          "0x0048"
#define PTG_L_BARW_inst                                               0x0048
#define PTG_L_BARW_auto_state_l_shift                                 (14)
#define PTG_L_BARW_hold_state_l_shift                                 (12)
#define PTG_L_BARW_hold_state_rdy_l_shift                             (11)
#define PTG_L_BARW_barw_l_shift                                       (0)
#define PTG_L_BARW_auto_state_l_mask                                  (0x0000C000)
#define PTG_L_BARW_hold_state_l_mask                                  (0x00003000)
#define PTG_L_BARW_hold_state_rdy_l_mask                              (0x00000800)
#define PTG_L_BARW_barw_l_mask                                        (0x000007FF)
#define PTG_L_BARW_auto_state_l(data)                                 (0x0000C000&((data)<<14))
#define PTG_L_BARW_hold_state_l(data)                                 (0x00003000&((data)<<12))
#define PTG_L_BARW_hold_state_rdy_l(data)                             (0x00000800&((data)<<11))
#define PTG_L_BARW_barw_l(data)                                       (0x000007FF&(data))
#define PTG_L_BARW_get_auto_state_l(data)                             ((0x0000C000&(data))>>14)
#define PTG_L_BARW_get_hold_state_l(data)                             ((0x00003000&(data))>>12)
#define PTG_L_BARW_get_hold_state_rdy_l(data)                         ((0x00000800&(data))>>11)
#define PTG_L_BARW_get_barw_l(data)                                   (0x000007FF&(data))


#define PTG_L_C0Y_CB_CR                                               0x18022124
#define PTG_L_C0Y_CB_CR_reg_addr                                      "0xb8022124"
#define PTG_L_C0Y_CB_CR_reg                                           0xb8022124
#define PTG_L_C0Y_CB_CR_inst_addr                                     "0x0049"
#define PTG_L_C0Y_CB_CR_inst                                          0x0049
#define PTG_L_C0Y_CB_CR_i_c0y_92b_l_shift                             (16)
#define PTG_L_C0Y_CB_CR_i_c0cr_92b_l_shift                            (8)
#define PTG_L_C0Y_CB_CR_i_c0cb_92b_l_shift                            (0)
#define PTG_L_C0Y_CB_CR_i_c0y_92b_l_mask                              (0x00FF0000)
#define PTG_L_C0Y_CB_CR_i_c0cr_92b_l_mask                             (0x0000FF00)
#define PTG_L_C0Y_CB_CR_i_c0cb_92b_l_mask                             (0x000000FF)
#define PTG_L_C0Y_CB_CR_i_c0y_92b_l(data)                             (0x00FF0000&((data)<<16))
#define PTG_L_C0Y_CB_CR_i_c0cr_92b_l(data)                            (0x0000FF00&((data)<<8))
#define PTG_L_C0Y_CB_CR_i_c0cb_92b_l(data)                            (0x000000FF&(data))
#define PTG_L_C0Y_CB_CR_get_i_c0y_92b_l(data)                         ((0x00FF0000&(data))>>16)
#define PTG_L_C0Y_CB_CR_get_i_c0cr_92b_l(data)                        ((0x0000FF00&(data))>>8)
#define PTG_L_C0Y_CB_CR_get_i_c0cb_92b_l(data)                        (0x000000FF&(data))


#define PTG_L_C1Y_CB_CR                                               0x18022128
#define PTG_L_C1Y_CB_CR_reg_addr                                      "0xb8022128"
#define PTG_L_C1Y_CB_CR_reg                                           0xb8022128
#define PTG_L_C1Y_CB_CR_inst_addr                                     "0x004A"
#define PTG_L_C1Y_CB_CR_inst                                          0x004A
#define PTG_L_C1Y_CB_CR_i_c1y_92b_l_shift                             (16)
#define PTG_L_C1Y_CB_CR_i_c1cr_92b_l_shift                            (8)
#define PTG_L_C1Y_CB_CR_i_c1cb_92b_l_shift                            (0)
#define PTG_L_C1Y_CB_CR_i_c1y_92b_l_mask                              (0x00FF0000)
#define PTG_L_C1Y_CB_CR_i_c1cr_92b_l_mask                             (0x0000FF00)
#define PTG_L_C1Y_CB_CR_i_c1cb_92b_l_mask                             (0x000000FF)
#define PTG_L_C1Y_CB_CR_i_c1y_92b_l(data)                             (0x00FF0000&((data)<<16))
#define PTG_L_C1Y_CB_CR_i_c1cr_92b_l(data)                            (0x0000FF00&((data)<<8))
#define PTG_L_C1Y_CB_CR_i_c1cb_92b_l(data)                            (0x000000FF&(data))
#define PTG_L_C1Y_CB_CR_get_i_c1y_92b_l(data)                         ((0x00FF0000&(data))>>16)
#define PTG_L_C1Y_CB_CR_get_i_c1cr_92b_l(data)                        ((0x0000FF00&(data))>>8)
#define PTG_L_C1Y_CB_CR_get_i_c1cb_92b_l(data)                        (0x000000FF&(data))


#define PTG_L_C2Y_CB_CR                                               0x1802212c
#define PTG_L_C2Y_CB_CR_reg_addr                                      "0xb802212c"
#define PTG_L_C2Y_CB_CR_reg                                           0xb802212c
#define PTG_L_C2Y_CB_CR_inst_addr                                     "0x004B"
#define PTG_L_C2Y_CB_CR_inst                                          0x004B
#define PTG_L_C2Y_CB_CR_i_c2y_92b_l_shift                             (16)
#define PTG_L_C2Y_CB_CR_i_c2cr_92b_l_shift                            (8)
#define PTG_L_C2Y_CB_CR_i_c2cb_92b_l_shift                            (0)
#define PTG_L_C2Y_CB_CR_i_c2y_92b_l_mask                              (0x00FF0000)
#define PTG_L_C2Y_CB_CR_i_c2cr_92b_l_mask                             (0x0000FF00)
#define PTG_L_C2Y_CB_CR_i_c2cb_92b_l_mask                             (0x000000FF)
#define PTG_L_C2Y_CB_CR_i_c2y_92b_l(data)                             (0x00FF0000&((data)<<16))
#define PTG_L_C2Y_CB_CR_i_c2cr_92b_l(data)                            (0x0000FF00&((data)<<8))
#define PTG_L_C2Y_CB_CR_i_c2cb_92b_l(data)                            (0x000000FF&(data))
#define PTG_L_C2Y_CB_CR_get_i_c2y_92b_l(data)                         ((0x00FF0000&(data))>>16)
#define PTG_L_C2Y_CB_CR_get_i_c2cr_92b_l(data)                        ((0x0000FF00&(data))>>8)
#define PTG_L_C2Y_CB_CR_get_i_c2cb_92b_l(data)                        (0x000000FF&(data))


#define PTG_L_C3Y_CB_CR                                               0x18022130
#define PTG_L_C3Y_CB_CR_reg_addr                                      "0xb8022130"
#define PTG_L_C3Y_CB_CR_reg                                           0xb8022130
#define PTG_L_C3Y_CB_CR_inst_addr                                     "0x004C"
#define PTG_L_C3Y_CB_CR_inst                                          0x004C
#define PTG_L_C3Y_CB_CR_i_c3y_98b_l_shift                             (30)
#define PTG_L_C3Y_CB_CR_i_c3y_72b_grady_l_shift                       (24)
#define PTG_L_C3Y_CB_CR_i_c3cr_98b_l_shift                            (22)
#define PTG_L_C3Y_CB_CR_i_c3cr_72b_gradcr_l_shift                     (16)
#define PTG_L_C3Y_CB_CR_i_c3cb_98b_l_shift                            (14)
#define PTG_L_C3Y_CB_CR_i_c3cb_72b_gradcb_l_shift                     (8)
#define PTG_L_C3Y_CB_CR_dummy18022130_7_0_shift                       (0)
#define PTG_L_C3Y_CB_CR_i_c3y_98b_l_mask                              (0xC0000000)
#define PTG_L_C3Y_CB_CR_i_c3y_72b_grady_l_mask                        (0x3F000000)
#define PTG_L_C3Y_CB_CR_i_c3cr_98b_l_mask                             (0x00C00000)
#define PTG_L_C3Y_CB_CR_i_c3cr_72b_gradcr_l_mask                      (0x003F0000)
#define PTG_L_C3Y_CB_CR_i_c3cb_98b_l_mask                             (0x0000C000)
#define PTG_L_C3Y_CB_CR_i_c3cb_72b_gradcb_l_mask                      (0x00003F00)
#define PTG_L_C3Y_CB_CR_dummy18022130_7_0_mask                        (0x000000FF)
#define PTG_L_C3Y_CB_CR_i_c3y_98b_l(data)                             (0xC0000000&((data)<<30))
#define PTG_L_C3Y_CB_CR_i_c3y_72b_grady_l(data)                       (0x3F000000&((data)<<24))
#define PTG_L_C3Y_CB_CR_i_c3cr_98b_l(data)                            (0x00C00000&((data)<<22))
#define PTG_L_C3Y_CB_CR_i_c3cr_72b_gradcr_l(data)                     (0x003F0000&((data)<<16))
#define PTG_L_C3Y_CB_CR_i_c3cb_98b_l(data)                            (0x0000C000&((data)<<14))
#define PTG_L_C3Y_CB_CR_i_c3cb_72b_gradcb_l(data)                     (0x00003F00&((data)<<8))
#define PTG_L_C3Y_CB_CR_dummy18022130_7_0(data)                       (0x000000FF&(data))
#define PTG_L_C3Y_CB_CR_get_i_c3y_98b_l(data)                         ((0xC0000000&(data))>>30)
#define PTG_L_C3Y_CB_CR_get_i_c3y_72b_grady_l(data)                   ((0x3F000000&(data))>>24)
#define PTG_L_C3Y_CB_CR_get_i_c3cr_98b_l(data)                        ((0x00C00000&(data))>>22)
#define PTG_L_C3Y_CB_CR_get_i_c3cr_72b_gradcr_l(data)                 ((0x003F0000&(data))>>16)
#define PTG_L_C3Y_CB_CR_get_i_c3cb_98b_l(data)                        ((0x0000C000&(data))>>14)
#define PTG_L_C3Y_CB_CR_get_i_c3cb_72b_gradcb_l(data)                 ((0x00003F00&(data))>>8)
#define PTG_L_C3Y_CB_CR_get_dummy18022130_7_0(data)                   (0x000000FF&(data))


#define PTG_L_C4Y_CB_CR                                               0x18022134
#define PTG_L_C4Y_CB_CR_reg_addr                                      "0xb8022134"
#define PTG_L_C4Y_CB_CR_reg                                           0xb8022134
#define PTG_L_C4Y_CB_CR_inst_addr                                     "0x004D"
#define PTG_L_C4Y_CB_CR_inst                                          0x004D
#define PTG_L_C4Y_CB_CR_i_c4y_96b_l_shift                             (28)
#define PTG_L_C4Y_CB_CR_i_c4y_52b_step_hv_l_shift                     (24)
#define PTG_L_C4Y_CB_CR_i_c4cr_92b_l_shift                            (16)
#define PTG_L_C4Y_CB_CR_i_c4cb_9b_l_shift                             (15)
#define PTG_L_C4Y_CB_CR_i_c4cb_86b_bmp_w_l_shift                      (12)
#define PTG_L_C4Y_CB_CR_i_c4cb_5b_l_shift                             (11)
#define PTG_L_C4Y_CB_CR_i_c4cb_42b_bmp_h_l_shift                      (8)
#define PTG_L_C4Y_CB_CR_i_c4y_96b_l_mask                              (0xF0000000)
#define PTG_L_C4Y_CB_CR_i_c4y_52b_step_hv_l_mask                      (0x0F000000)
#define PTG_L_C4Y_CB_CR_i_c4cr_92b_l_mask                             (0x00FF0000)
#define PTG_L_C4Y_CB_CR_i_c4cb_9b_l_mask                              (0x00008000)
#define PTG_L_C4Y_CB_CR_i_c4cb_86b_bmp_w_l_mask                       (0x00007000)
#define PTG_L_C4Y_CB_CR_i_c4cb_5b_l_mask                              (0x00000800)
#define PTG_L_C4Y_CB_CR_i_c4cb_42b_bmp_h_l_mask                       (0x00000700)
#define PTG_L_C4Y_CB_CR_i_c4y_96b_l(data)                             (0xF0000000&((data)<<28))
#define PTG_L_C4Y_CB_CR_i_c4y_52b_step_hv_l(data)                     (0x0F000000&((data)<<24))
#define PTG_L_C4Y_CB_CR_i_c4cr_92b_l(data)                            (0x00FF0000&((data)<<16))
#define PTG_L_C4Y_CB_CR_i_c4cb_9b_l(data)                             (0x00008000&((data)<<15))
#define PTG_L_C4Y_CB_CR_i_c4cb_86b_bmp_w_l(data)                      (0x00007000&((data)<<12))
#define PTG_L_C4Y_CB_CR_i_c4cb_5b_l(data)                             (0x00000800&((data)<<11))
#define PTG_L_C4Y_CB_CR_i_c4cb_42b_bmp_h_l(data)                      (0x00000700&((data)<<8))
#define PTG_L_C4Y_CB_CR_get_i_c4y_96b_l(data)                         ((0xF0000000&(data))>>28)
#define PTG_L_C4Y_CB_CR_get_i_c4y_52b_step_hv_l(data)                 ((0x0F000000&(data))>>24)
#define PTG_L_C4Y_CB_CR_get_i_c4cr_92b_l(data)                        ((0x00FF0000&(data))>>16)
#define PTG_L_C4Y_CB_CR_get_i_c4cb_9b_l(data)                         ((0x00008000&(data))>>15)
#define PTG_L_C4Y_CB_CR_get_i_c4cb_86b_bmp_w_l(data)                  ((0x00007000&(data))>>12)
#define PTG_L_C4Y_CB_CR_get_i_c4cb_5b_l(data)                         ((0x00000800&(data))>>11)
#define PTG_L_C4Y_CB_CR_get_i_c4cb_42b_bmp_h_l(data)                  ((0x00000700&(data))>>8)


#define PTG_L_C5Y_CR_CB                                               0x18022138
#define PTG_L_C5Y_CR_CB_reg_addr                                      "0xb8022138"
#define PTG_L_C5Y_CR_CB_reg                                           0xb8022138
#define PTG_L_C5Y_CR_CB_inst_addr                                     "0x004E"
#define PTG_L_C5Y_CR_CB_inst                                          0x004E
#define PTG_L_C5Y_CR_CB_i_c5y_92b_bmptp_l_shift                       (24)
#define PTG_L_C5Y_CR_CB_i_c5cr_92b_bmp0_l_shift                       (16)
#define PTG_L_C5Y_CR_CB_i_c5cb_92b_bmp1_l_shift                       (8)
#define PTG_L_C5Y_CR_CB_dummy18022138_7_0_shift                       (0)
#define PTG_L_C5Y_CR_CB_i_c5y_92b_bmptp_l_mask                        (0xFF000000)
#define PTG_L_C5Y_CR_CB_i_c5cr_92b_bmp0_l_mask                        (0x00FF0000)
#define PTG_L_C5Y_CR_CB_i_c5cb_92b_bmp1_l_mask                        (0x0000FF00)
#define PTG_L_C5Y_CR_CB_dummy18022138_7_0_mask                        (0x000000FF)
#define PTG_L_C5Y_CR_CB_i_c5y_92b_bmptp_l(data)                       (0xFF000000&((data)<<24))
#define PTG_L_C5Y_CR_CB_i_c5cr_92b_bmp0_l(data)                       (0x00FF0000&((data)<<16))
#define PTG_L_C5Y_CR_CB_i_c5cb_92b_bmp1_l(data)                       (0x0000FF00&((data)<<8))
#define PTG_L_C5Y_CR_CB_dummy18022138_7_0(data)                       (0x000000FF&(data))
#define PTG_L_C5Y_CR_CB_get_i_c5y_92b_bmptp_l(data)                   ((0xFF000000&(data))>>24)
#define PTG_L_C5Y_CR_CB_get_i_c5cr_92b_bmp0_l(data)                   ((0x00FF0000&(data))>>16)
#define PTG_L_C5Y_CR_CB_get_i_c5cb_92b_bmp1_l(data)                   ((0x0000FF00&(data))>>8)
#define PTG_L_C5Y_CR_CB_get_dummy18022138_7_0(data)                   (0x000000FF&(data))


#define PTG_L_C6Y_CB_CR                                               0x1802213c
#define PTG_L_C6Y_CB_CR_reg_addr                                      "0xb802213c"
#define PTG_L_C6Y_CB_CR_reg                                           0xb802213c
#define PTG_L_C6Y_CB_CR_inst_addr                                     "0x004F"
#define PTG_L_C6Y_CB_CR_inst                                          0x004F
#define PTG_L_C6Y_CB_CR_i_c6y_92b_bmp2_l_shift                        (24)
#define PTG_L_C6Y_CB_CR_i_c6cr_92b_bmp3_l_shift                       (16)
#define PTG_L_C6Y_CB_CR_i_c6cb_92b_bmp4_l_shift                       (8)
#define PTG_L_C6Y_CB_CR_nonactive_color_def_l_shift                   (0)
#define PTG_L_C6Y_CB_CR_i_c6y_92b_bmp2_l_mask                         (0xFF000000)
#define PTG_L_C6Y_CB_CR_i_c6cr_92b_bmp3_l_mask                        (0x00FF0000)
#define PTG_L_C6Y_CB_CR_i_c6cb_92b_bmp4_l_mask                        (0x0000FF00)
#define PTG_L_C6Y_CB_CR_nonactive_color_def_l_mask                    (0x000000FF)
#define PTG_L_C6Y_CB_CR_i_c6y_92b_bmp2_l(data)                        (0xFF000000&((data)<<24))
#define PTG_L_C6Y_CB_CR_i_c6cr_92b_bmp3_l(data)                       (0x00FF0000&((data)<<16))
#define PTG_L_C6Y_CB_CR_i_c6cb_92b_bmp4_l(data)                       (0x0000FF00&((data)<<8))
#define PTG_L_C6Y_CB_CR_nonactive_color_def_l(data)                   (0x000000FF&(data))
#define PTG_L_C6Y_CB_CR_get_i_c6y_92b_bmp2_l(data)                    ((0xFF000000&(data))>>24)
#define PTG_L_C6Y_CB_CR_get_i_c6cr_92b_bmp3_l(data)                   ((0x00FF0000&(data))>>16)
#define PTG_L_C6Y_CB_CR_get_i_c6cb_92b_bmp4_l(data)                   ((0x0000FF00&(data))>>8)
#define PTG_L_C6Y_CB_CR_get_nonactive_color_def_l(data)               (0x000000FF&(data))


#define PTG_L_C7Y_CB_CR                                               0x18022140
#define PTG_L_C7Y_CB_CR_reg_addr                                      "0xb8022140"
#define PTG_L_C7Y_CB_CR_reg                                           0xb8022140
#define PTG_L_C7Y_CB_CR_inst_addr                                     "0x0050"
#define PTG_L_C7Y_CB_CR_inst                                          0x0050
#define PTG_L_C7Y_CB_CR_i_c7y_92b_bmp5_l_shift                        (24)
#define PTG_L_C7Y_CB_CR_i_c7cr_92b_bmp6_l_shift                       (16)
#define PTG_L_C7Y_CB_CR_i_c7cb_92b_bmp7_l_shift                       (8)
#define PTG_L_C7Y_CB_CR_dummy18022140_7_3_shift                       (3)
#define PTG_L_C7Y_CB_CR_max_color_l_shift                             (0)
#define PTG_L_C7Y_CB_CR_i_c7y_92b_bmp5_l_mask                         (0xFF000000)
#define PTG_L_C7Y_CB_CR_i_c7cr_92b_bmp6_l_mask                        (0x00FF0000)
#define PTG_L_C7Y_CB_CR_i_c7cb_92b_bmp7_l_mask                        (0x0000FF00)
#define PTG_L_C7Y_CB_CR_dummy18022140_7_3_mask                        (0x000000F8)
#define PTG_L_C7Y_CB_CR_max_color_l_mask                              (0x00000007)
#define PTG_L_C7Y_CB_CR_i_c7y_92b_bmp5_l(data)                        (0xFF000000&((data)<<24))
#define PTG_L_C7Y_CB_CR_i_c7cr_92b_bmp6_l(data)                       (0x00FF0000&((data)<<16))
#define PTG_L_C7Y_CB_CR_i_c7cb_92b_bmp7_l(data)                       (0x0000FF00&((data)<<8))
#define PTG_L_C7Y_CB_CR_dummy18022140_7_3(data)                       (0x000000F8&((data)<<3))
#define PTG_L_C7Y_CB_CR_max_color_l(data)                             (0x00000007&(data))
#define PTG_L_C7Y_CB_CR_get_i_c7y_92b_bmp5_l(data)                    ((0xFF000000&(data))>>24)
#define PTG_L_C7Y_CB_CR_get_i_c7cr_92b_bmp6_l(data)                   ((0x00FF0000&(data))>>16)
#define PTG_L_C7Y_CB_CR_get_i_c7cb_92b_bmp7_l(data)                   ((0x0000FF00&(data))>>8)
#define PTG_L_C7Y_CB_CR_get_dummy18022140_7_3(data)                   ((0x000000F8&(data))>>3)
#define PTG_L_C7Y_CB_CR_get_max_color_l(data)                         (0x00000007&(data))


#define PTG_L_MAX_COLOR_CTRL                                          0x18022144
#define PTG_L_MAX_COLOR_CTRL_reg_addr                                 "0xb8022144"
#define PTG_L_MAX_COLOR_CTRL_reg                                      0xb8022144
#define PTG_L_MAX_COLOR_CTRL_inst_addr                                "0x0051"
#define PTG_L_MAX_COLOR_CTRL_inst                                     0x0051
#define PTG_L_MAX_COLOR_CTRL_mv_h_l_shift                             (24)
#define PTG_L_MAX_COLOR_CTRL_mv_v_l_shift                             (16)
#define PTG_L_MAX_COLOR_CTRL_mv_seq_type_l_shift                      (15)
#define PTG_L_MAX_COLOR_CTRL_rdm_period_l_shift                       (12)
#define PTG_L_MAX_COLOR_CTRL_mv_vs_num_l_shift                        (8)
#define PTG_L_MAX_COLOR_CTRL_mp_adj_num_l_shift                       (0)
#define PTG_L_MAX_COLOR_CTRL_mv_h_l_mask                              (0xFF000000)
#define PTG_L_MAX_COLOR_CTRL_mv_v_l_mask                              (0x00FF0000)
#define PTG_L_MAX_COLOR_CTRL_mv_seq_type_l_mask                       (0x00008000)
#define PTG_L_MAX_COLOR_CTRL_rdm_period_l_mask                        (0x00007000)
#define PTG_L_MAX_COLOR_CTRL_mv_vs_num_l_mask                         (0x00000F00)
#define PTG_L_MAX_COLOR_CTRL_mp_adj_num_l_mask                        (0x000000FF)
#define PTG_L_MAX_COLOR_CTRL_mv_h_l(data)                             (0xFF000000&((data)<<24))
#define PTG_L_MAX_COLOR_CTRL_mv_v_l(data)                             (0x00FF0000&((data)<<16))
#define PTG_L_MAX_COLOR_CTRL_mv_seq_type_l(data)                      (0x00008000&((data)<<15))
#define PTG_L_MAX_COLOR_CTRL_rdm_period_l(data)                       (0x00007000&((data)<<12))
#define PTG_L_MAX_COLOR_CTRL_mv_vs_num_l(data)                        (0x00000F00&((data)<<8))
#define PTG_L_MAX_COLOR_CTRL_mp_adj_num_l(data)                       (0x000000FF&(data))
#define PTG_L_MAX_COLOR_CTRL_get_mv_h_l(data)                         ((0xFF000000&(data))>>24)
#define PTG_L_MAX_COLOR_CTRL_get_mv_v_l(data)                         ((0x00FF0000&(data))>>16)
#define PTG_L_MAX_COLOR_CTRL_get_mv_seq_type_l(data)                  ((0x00008000&(data))>>15)
#define PTG_L_MAX_COLOR_CTRL_get_rdm_period_l(data)                   ((0x00007000&(data))>>12)
#define PTG_L_MAX_COLOR_CTRL_get_mv_vs_num_l(data)                    ((0x00000F00&(data))>>8)
#define PTG_L_MAX_COLOR_CTRL_get_mp_adj_num_l(data)                   (0x000000FF&(data))


#define PTG_R_PAT_HSTA_WIDTH                                          0x18022148
#define PTG_R_PAT_HSTA_WIDTH_reg_addr                                 "0xb8022148"
#define PTG_R_PAT_HSTA_WIDTH_reg                                      0xb8022148
#define PTG_R_PAT_HSTA_WIDTH_inst_addr                                "0x0052"
#define PTG_R_PAT_HSTA_WIDTH_inst                                     0x0052
#define PTG_R_PAT_HSTA_WIDTH_pat_h_sta_r_shift                        (16)
#define PTG_R_PAT_HSTA_WIDTH_dummy18022148_15_13_shift                (13)
#define PTG_R_PAT_HSTA_WIDTH_pat_wid_r_shift                          (0)
#define PTG_R_PAT_HSTA_WIDTH_pat_h_sta_r_mask                         (0x1FFF0000)
#define PTG_R_PAT_HSTA_WIDTH_dummy18022148_15_13_mask                 (0x0000E000)
#define PTG_R_PAT_HSTA_WIDTH_pat_wid_r_mask                           (0x00001FFF)
#define PTG_R_PAT_HSTA_WIDTH_pat_h_sta_r(data)                        (0x1FFF0000&((data)<<16))
#define PTG_R_PAT_HSTA_WIDTH_dummy18022148_15_13(data)                (0x0000E000&((data)<<13))
#define PTG_R_PAT_HSTA_WIDTH_pat_wid_r(data)                          (0x00001FFF&(data))
#define PTG_R_PAT_HSTA_WIDTH_get_pat_h_sta_r(data)                    ((0x1FFF0000&(data))>>16)
#define PTG_R_PAT_HSTA_WIDTH_get_dummy18022148_15_13(data)            ((0x0000E000&(data))>>13)
#define PTG_R_PAT_HSTA_WIDTH_get_pat_wid_r(data)                      (0x00001FFF&(data))


#define PTG_R_PAT_VSTA_LENGTH                                         0x1802214c
#define PTG_R_PAT_VSTA_LENGTH_reg_addr                                "0xb802214c"
#define PTG_R_PAT_VSTA_LENGTH_reg                                     0xb802214c
#define PTG_R_PAT_VSTA_LENGTH_inst_addr                               "0x0053"
#define PTG_R_PAT_VSTA_LENGTH_inst                                    0x0053
#define PTG_R_PAT_VSTA_LENGTH_pat_v_sta_r_shift                       (16)
#define PTG_R_PAT_VSTA_LENGTH_dummy1802214c_15_13_shift               (13)
#define PTG_R_PAT_VSTA_LENGTH_pat_len_r_shift                         (0)
#define PTG_R_PAT_VSTA_LENGTH_pat_v_sta_r_mask                        (0x1FFF0000)
#define PTG_R_PAT_VSTA_LENGTH_dummy1802214c_15_13_mask                (0x0000E000)
#define PTG_R_PAT_VSTA_LENGTH_pat_len_r_mask                          (0x00001FFF)
#define PTG_R_PAT_VSTA_LENGTH_pat_v_sta_r(data)                       (0x1FFF0000&((data)<<16))
#define PTG_R_PAT_VSTA_LENGTH_dummy1802214c_15_13(data)               (0x0000E000&((data)<<13))
#define PTG_R_PAT_VSTA_LENGTH_pat_len_r(data)                         (0x00001FFF&(data))
#define PTG_R_PAT_VSTA_LENGTH_get_pat_v_sta_r(data)                   ((0x1FFF0000&(data))>>16)
#define PTG_R_PAT_VSTA_LENGTH_get_dummy1802214c_15_13(data)           ((0x0000E000&(data))>>13)
#define PTG_R_PAT_VSTA_LENGTH_get_pat_len_r(data)                     (0x00001FFF&(data))


#define PTG_R_CTRL                                                    0x18022150
#define PTG_R_CTRL_reg_addr                                           "0xb8022150"
#define PTG_R_CTRL_reg                                                0xb8022150
#define PTG_R_CTRL_inst_addr                                          "0x0054"
#define PTG_R_CTRL_inst                                               0x0054
#define PTG_R_CTRL_en_rdm_bkg_r_shift                                 (8)
#define PTG_R_CTRL_xc_seq_r_shift                                     (5)
#define PTG_R_CTRL_en_xc_r_shift                                      (4)
#define PTG_R_CTRL_pat_mode_r_shift                                   (0)
#define PTG_R_CTRL_en_rdm_bkg_r_mask                                  (0x00000100)
#define PTG_R_CTRL_xc_seq_r_mask                                      (0x000000E0)
#define PTG_R_CTRL_en_xc_r_mask                                       (0x00000010)
#define PTG_R_CTRL_pat_mode_r_mask                                    (0x0000000F)
#define PTG_R_CTRL_en_rdm_bkg_r(data)                                 (0x00000100&((data)<<8))
#define PTG_R_CTRL_xc_seq_r(data)                                     (0x000000E0&((data)<<5))
#define PTG_R_CTRL_en_xc_r(data)                                      (0x00000010&((data)<<4))
#define PTG_R_CTRL_pat_mode_r(data)                                   (0x0000000F&(data))
#define PTG_R_CTRL_get_en_rdm_bkg_r(data)                             ((0x00000100&(data))>>8)
#define PTG_R_CTRL_get_xc_seq_r(data)                                 ((0x000000E0&(data))>>5)
#define PTG_R_CTRL_get_en_xc_r(data)                                  ((0x00000010&(data))>>4)
#define PTG_R_CTRL_get_pat_mode_r(data)                               (0x0000000F&(data))


#define PTG_R_BARW                                                    0x18022154
#define PTG_R_BARW_reg_addr                                           "0xb8022154"
#define PTG_R_BARW_reg                                                0xb8022154
#define PTG_R_BARW_inst_addr                                          "0x0055"
#define PTG_R_BARW_inst                                               0x0055
#define PTG_R_BARW_auto_state_r_shift                                 (14)
#define PTG_R_BARW_hold_state_r_shift                                 (12)
#define PTG_R_BARW_hold_state_rdy_r_shift                             (11)
#define PTG_R_BARW_barw_r_shift                                       (0)
#define PTG_R_BARW_auto_state_r_mask                                  (0x0000C000)
#define PTG_R_BARW_hold_state_r_mask                                  (0x00003000)
#define PTG_R_BARW_hold_state_rdy_r_mask                              (0x00000800)
#define PTG_R_BARW_barw_r_mask                                        (0x000007FF)
#define PTG_R_BARW_auto_state_r(data)                                 (0x0000C000&((data)<<14))
#define PTG_R_BARW_hold_state_r(data)                                 (0x00003000&((data)<<12))
#define PTG_R_BARW_hold_state_rdy_r(data)                             (0x00000800&((data)<<11))
#define PTG_R_BARW_barw_r(data)                                       (0x000007FF&(data))
#define PTG_R_BARW_get_auto_state_r(data)                             ((0x0000C000&(data))>>14)
#define PTG_R_BARW_get_hold_state_r(data)                             ((0x00003000&(data))>>12)
#define PTG_R_BARW_get_hold_state_rdy_r(data)                         ((0x00000800&(data))>>11)
#define PTG_R_BARW_get_barw_r(data)                                   (0x000007FF&(data))


#define PTG_R_C0Y_CB_CR                                               0x18022158
#define PTG_R_C0Y_CB_CR_reg_addr                                      "0xb8022158"
#define PTG_R_C0Y_CB_CR_reg                                           0xb8022158
#define PTG_R_C0Y_CB_CR_inst_addr                                     "0x0056"
#define PTG_R_C0Y_CB_CR_inst                                          0x0056
#define PTG_R_C0Y_CB_CR_i_c0y_92b_r_shift                             (16)
#define PTG_R_C0Y_CB_CR_i_c0cr_92b_r_shift                            (8)
#define PTG_R_C0Y_CB_CR_i_c0cb_92b_r_shift                            (0)
#define PTG_R_C0Y_CB_CR_i_c0y_92b_r_mask                              (0x00FF0000)
#define PTG_R_C0Y_CB_CR_i_c0cr_92b_r_mask                             (0x0000FF00)
#define PTG_R_C0Y_CB_CR_i_c0cb_92b_r_mask                             (0x000000FF)
#define PTG_R_C0Y_CB_CR_i_c0y_92b_r(data)                             (0x00FF0000&((data)<<16))
#define PTG_R_C0Y_CB_CR_i_c0cr_92b_r(data)                            (0x0000FF00&((data)<<8))
#define PTG_R_C0Y_CB_CR_i_c0cb_92b_r(data)                            (0x000000FF&(data))
#define PTG_R_C0Y_CB_CR_get_i_c0y_92b_r(data)                         ((0x00FF0000&(data))>>16)
#define PTG_R_C0Y_CB_CR_get_i_c0cr_92b_r(data)                        ((0x0000FF00&(data))>>8)
#define PTG_R_C0Y_CB_CR_get_i_c0cb_92b_r(data)                        (0x000000FF&(data))


#define PTG_R_C1Y_CB_CR                                               0x1802215c
#define PTG_R_C1Y_CB_CR_reg_addr                                      "0xb802215c"
#define PTG_R_C1Y_CB_CR_reg                                           0xb802215c
#define PTG_R_C1Y_CB_CR_inst_addr                                     "0x0057"
#define PTG_R_C1Y_CB_CR_inst                                          0x0057
#define PTG_R_C1Y_CB_CR_i_c1y_92b_r_shift                             (16)
#define PTG_R_C1Y_CB_CR_i_c1cr_92b_r_shift                            (8)
#define PTG_R_C1Y_CB_CR_i_c1cb_92b_r_shift                            (0)
#define PTG_R_C1Y_CB_CR_i_c1y_92b_r_mask                              (0x00FF0000)
#define PTG_R_C1Y_CB_CR_i_c1cr_92b_r_mask                             (0x0000FF00)
#define PTG_R_C1Y_CB_CR_i_c1cb_92b_r_mask                             (0x000000FF)
#define PTG_R_C1Y_CB_CR_i_c1y_92b_r(data)                             (0x00FF0000&((data)<<16))
#define PTG_R_C1Y_CB_CR_i_c1cr_92b_r(data)                            (0x0000FF00&((data)<<8))
#define PTG_R_C1Y_CB_CR_i_c1cb_92b_r(data)                            (0x000000FF&(data))
#define PTG_R_C1Y_CB_CR_get_i_c1y_92b_r(data)                         ((0x00FF0000&(data))>>16)
#define PTG_R_C1Y_CB_CR_get_i_c1cr_92b_r(data)                        ((0x0000FF00&(data))>>8)
#define PTG_R_C1Y_CB_CR_get_i_c1cb_92b_r(data)                        (0x000000FF&(data))


#define PTG_R_C2Y_CB_CR                                               0x18022160
#define PTG_R_C2Y_CB_CR_reg_addr                                      "0xb8022160"
#define PTG_R_C2Y_CB_CR_reg                                           0xb8022160
#define PTG_R_C2Y_CB_CR_inst_addr                                     "0x0058"
#define PTG_R_C2Y_CB_CR_inst                                          0x0058
#define PTG_R_C2Y_CB_CR_i_c2y_92b_r_shift                             (16)
#define PTG_R_C2Y_CB_CR_i_c2cr_92b_r_shift                            (8)
#define PTG_R_C2Y_CB_CR_i_c2cb_92b_r_shift                            (0)
#define PTG_R_C2Y_CB_CR_i_c2y_92b_r_mask                              (0x00FF0000)
#define PTG_R_C2Y_CB_CR_i_c2cr_92b_r_mask                             (0x0000FF00)
#define PTG_R_C2Y_CB_CR_i_c2cb_92b_r_mask                             (0x000000FF)
#define PTG_R_C2Y_CB_CR_i_c2y_92b_r(data)                             (0x00FF0000&((data)<<16))
#define PTG_R_C2Y_CB_CR_i_c2cr_92b_r(data)                            (0x0000FF00&((data)<<8))
#define PTG_R_C2Y_CB_CR_i_c2cb_92b_r(data)                            (0x000000FF&(data))
#define PTG_R_C2Y_CB_CR_get_i_c2y_92b_r(data)                         ((0x00FF0000&(data))>>16)
#define PTG_R_C2Y_CB_CR_get_i_c2cr_92b_r(data)                        ((0x0000FF00&(data))>>8)
#define PTG_R_C2Y_CB_CR_get_i_c2cb_92b_r(data)                        (0x000000FF&(data))


#define PTG_R_C3Y_CB_CR                                               0x18022164
#define PTG_R_C3Y_CB_CR_reg_addr                                      "0xb8022164"
#define PTG_R_C3Y_CB_CR_reg                                           0xb8022164
#define PTG_R_C3Y_CB_CR_inst_addr                                     "0x0059"
#define PTG_R_C3Y_CB_CR_inst                                          0x0059
#define PTG_R_C3Y_CB_CR_i_c3y_98b_r_shift                             (30)
#define PTG_R_C3Y_CB_CR_i_c3y_72b_grady_r_shift                       (24)
#define PTG_R_C3Y_CB_CR_i_c3cr_98b_r_shift                            (22)
#define PTG_R_C3Y_CB_CR_i_c3cr_72b_gradcr_r_shift                     (16)
#define PTG_R_C3Y_CB_CR_i_c3cb_98b_r_shift                            (14)
#define PTG_R_C3Y_CB_CR_i_c3cb_72b_gradcb_r_shift                     (8)
#define PTG_R_C3Y_CB_CR_dummy18022164_7_0_shift                       (0)
#define PTG_R_C3Y_CB_CR_i_c3y_98b_r_mask                              (0xC0000000)
#define PTG_R_C3Y_CB_CR_i_c3y_72b_grady_r_mask                        (0x3F000000)
#define PTG_R_C3Y_CB_CR_i_c3cr_98b_r_mask                             (0x00C00000)
#define PTG_R_C3Y_CB_CR_i_c3cr_72b_gradcr_r_mask                      (0x003F0000)
#define PTG_R_C3Y_CB_CR_i_c3cb_98b_r_mask                             (0x0000C000)
#define PTG_R_C3Y_CB_CR_i_c3cb_72b_gradcb_r_mask                      (0x00003F00)
#define PTG_R_C3Y_CB_CR_dummy18022164_7_0_mask                        (0x000000FF)
#define PTG_R_C3Y_CB_CR_i_c3y_98b_r(data)                             (0xC0000000&((data)<<30))
#define PTG_R_C3Y_CB_CR_i_c3y_72b_grady_r(data)                       (0x3F000000&((data)<<24))
#define PTG_R_C3Y_CB_CR_i_c3cr_98b_r(data)                            (0x00C00000&((data)<<22))
#define PTG_R_C3Y_CB_CR_i_c3cr_72b_gradcr_r(data)                     (0x003F0000&((data)<<16))
#define PTG_R_C3Y_CB_CR_i_c3cb_98b_r(data)                            (0x0000C000&((data)<<14))
#define PTG_R_C3Y_CB_CR_i_c3cb_72b_gradcb_r(data)                     (0x00003F00&((data)<<8))
#define PTG_R_C3Y_CB_CR_dummy18022164_7_0(data)                       (0x000000FF&(data))
#define PTG_R_C3Y_CB_CR_get_i_c3y_98b_r(data)                         ((0xC0000000&(data))>>30)
#define PTG_R_C3Y_CB_CR_get_i_c3y_72b_grady_r(data)                   ((0x3F000000&(data))>>24)
#define PTG_R_C3Y_CB_CR_get_i_c3cr_98b_r(data)                        ((0x00C00000&(data))>>22)
#define PTG_R_C3Y_CB_CR_get_i_c3cr_72b_gradcr_r(data)                 ((0x003F0000&(data))>>16)
#define PTG_R_C3Y_CB_CR_get_i_c3cb_98b_r(data)                        ((0x0000C000&(data))>>14)
#define PTG_R_C3Y_CB_CR_get_i_c3cb_72b_gradcb_r(data)                 ((0x00003F00&(data))>>8)
#define PTG_R_C3Y_CB_CR_get_dummy18022164_7_0(data)                   (0x000000FF&(data))


#define PTG_R_C4Y_CB_CR                                               0x18022168
#define PTG_R_C4Y_CB_CR_reg_addr                                      "0xb8022168"
#define PTG_R_C4Y_CB_CR_reg                                           0xb8022168
#define PTG_R_C4Y_CB_CR_inst_addr                                     "0x005A"
#define PTG_R_C4Y_CB_CR_inst                                          0x005A
#define PTG_R_C4Y_CB_CR_i_c4y_96b_r_shift                             (28)
#define PTG_R_C4Y_CB_CR_i_c4y_52b_step_hv_r_shift                     (24)
#define PTG_R_C4Y_CB_CR_i_c4cr_92b_r_shift                            (16)
#define PTG_R_C4Y_CB_CR_i_c4cb_9b_r_shift                             (15)
#define PTG_R_C4Y_CB_CR_i_c4cb_86b_bmp_w_r_shift                      (12)
#define PTG_R_C4Y_CB_CR_i_c4cb_5b_r_shift                             (11)
#define PTG_R_C4Y_CB_CR_i_c4cb_42b_bmp_h_r_shift                      (8)
#define PTG_R_C4Y_CB_CR_i_c4y_96b_r_mask                              (0xF0000000)
#define PTG_R_C4Y_CB_CR_i_c4y_52b_step_hv_r_mask                      (0x0F000000)
#define PTG_R_C4Y_CB_CR_i_c4cr_92b_r_mask                             (0x00FF0000)
#define PTG_R_C4Y_CB_CR_i_c4cb_9b_r_mask                              (0x00008000)
#define PTG_R_C4Y_CB_CR_i_c4cb_86b_bmp_w_r_mask                       (0x00007000)
#define PTG_R_C4Y_CB_CR_i_c4cb_5b_r_mask                              (0x00000800)
#define PTG_R_C4Y_CB_CR_i_c4cb_42b_bmp_h_r_mask                       (0x00000700)
#define PTG_R_C4Y_CB_CR_i_c4y_96b_r(data)                             (0xF0000000&((data)<<28))
#define PTG_R_C4Y_CB_CR_i_c4y_52b_step_hv_r(data)                     (0x0F000000&((data)<<24))
#define PTG_R_C4Y_CB_CR_i_c4cr_92b_r(data)                            (0x00FF0000&((data)<<16))
#define PTG_R_C4Y_CB_CR_i_c4cb_9b_r(data)                             (0x00008000&((data)<<15))
#define PTG_R_C4Y_CB_CR_i_c4cb_86b_bmp_w_r(data)                      (0x00007000&((data)<<12))
#define PTG_R_C4Y_CB_CR_i_c4cb_5b_r(data)                             (0x00000800&((data)<<11))
#define PTG_R_C4Y_CB_CR_i_c4cb_42b_bmp_h_r(data)                      (0x00000700&((data)<<8))
#define PTG_R_C4Y_CB_CR_get_i_c4y_96b_r(data)                         ((0xF0000000&(data))>>28)
#define PTG_R_C4Y_CB_CR_get_i_c4y_52b_step_hv_r(data)                 ((0x0F000000&(data))>>24)
#define PTG_R_C4Y_CB_CR_get_i_c4cr_92b_r(data)                        ((0x00FF0000&(data))>>16)
#define PTG_R_C4Y_CB_CR_get_i_c4cb_9b_r(data)                         ((0x00008000&(data))>>15)
#define PTG_R_C4Y_CB_CR_get_i_c4cb_86b_bmp_w_r(data)                  ((0x00007000&(data))>>12)
#define PTG_R_C4Y_CB_CR_get_i_c4cb_5b_r(data)                         ((0x00000800&(data))>>11)
#define PTG_R_C4Y_CB_CR_get_i_c4cb_42b_bmp_h_r(data)                  ((0x00000700&(data))>>8)


#define PTG_R_C5Y_CR_CB                                               0x1802216c
#define PTG_R_C5Y_CR_CB_reg_addr                                      "0xb802216c"
#define PTG_R_C5Y_CR_CB_reg                                           0xb802216c
#define PTG_R_C5Y_CR_CB_inst_addr                                     "0x005B"
#define PTG_R_C5Y_CR_CB_inst                                          0x005B
#define PTG_R_C5Y_CR_CB_i_c5y_92b_bmptp_r_shift                       (24)
#define PTG_R_C5Y_CR_CB_i_c5cr_92b_bmp0_r_shift                       (16)
#define PTG_R_C5Y_CR_CB_i_c5cb_92b_bmp1_r_shift                       (8)
#define PTG_R_C5Y_CR_CB_dummy1802216c_7_0_shift                       (0)
#define PTG_R_C5Y_CR_CB_i_c5y_92b_bmptp_r_mask                        (0xFF000000)
#define PTG_R_C5Y_CR_CB_i_c5cr_92b_bmp0_r_mask                        (0x00FF0000)
#define PTG_R_C5Y_CR_CB_i_c5cb_92b_bmp1_r_mask                        (0x0000FF00)
#define PTG_R_C5Y_CR_CB_dummy1802216c_7_0_mask                        (0x000000FF)
#define PTG_R_C5Y_CR_CB_i_c5y_92b_bmptp_r(data)                       (0xFF000000&((data)<<24))
#define PTG_R_C5Y_CR_CB_i_c5cr_92b_bmp0_r(data)                       (0x00FF0000&((data)<<16))
#define PTG_R_C5Y_CR_CB_i_c5cb_92b_bmp1_r(data)                       (0x0000FF00&((data)<<8))
#define PTG_R_C5Y_CR_CB_dummy1802216c_7_0(data)                       (0x000000FF&(data))
#define PTG_R_C5Y_CR_CB_get_i_c5y_92b_bmptp_r(data)                   ((0xFF000000&(data))>>24)
#define PTG_R_C5Y_CR_CB_get_i_c5cr_92b_bmp0_r(data)                   ((0x00FF0000&(data))>>16)
#define PTG_R_C5Y_CR_CB_get_i_c5cb_92b_bmp1_r(data)                   ((0x0000FF00&(data))>>8)
#define PTG_R_C5Y_CR_CB_get_dummy1802216c_7_0(data)                   (0x000000FF&(data))


#define PTG_R_C6Y_CB_CR                                               0x18022170
#define PTG_R_C6Y_CB_CR_reg_addr                                      "0xb8022170"
#define PTG_R_C6Y_CB_CR_reg                                           0xb8022170
#define PTG_R_C6Y_CB_CR_inst_addr                                     "0x005C"
#define PTG_R_C6Y_CB_CR_inst                                          0x005C
#define PTG_R_C6Y_CB_CR_i_c6y_92b_bmp2_r_shift                        (24)
#define PTG_R_C6Y_CB_CR_i_c6cr_92b_bmp3_r_shift                       (16)
#define PTG_R_C6Y_CB_CR_i_c6cb_92b_bmp4_r_shift                       (8)
#define PTG_R_C6Y_CB_CR_nonactive_color_def_r_shift                   (0)
#define PTG_R_C6Y_CB_CR_i_c6y_92b_bmp2_r_mask                         (0xFF000000)
#define PTG_R_C6Y_CB_CR_i_c6cr_92b_bmp3_r_mask                        (0x00FF0000)
#define PTG_R_C6Y_CB_CR_i_c6cb_92b_bmp4_r_mask                        (0x0000FF00)
#define PTG_R_C6Y_CB_CR_nonactive_color_def_r_mask                    (0x000000FF)
#define PTG_R_C6Y_CB_CR_i_c6y_92b_bmp2_r(data)                        (0xFF000000&((data)<<24))
#define PTG_R_C6Y_CB_CR_i_c6cr_92b_bmp3_r(data)                       (0x00FF0000&((data)<<16))
#define PTG_R_C6Y_CB_CR_i_c6cb_92b_bmp4_r(data)                       (0x0000FF00&((data)<<8))
#define PTG_R_C6Y_CB_CR_nonactive_color_def_r(data)                   (0x000000FF&(data))
#define PTG_R_C6Y_CB_CR_get_i_c6y_92b_bmp2_r(data)                    ((0xFF000000&(data))>>24)
#define PTG_R_C6Y_CB_CR_get_i_c6cr_92b_bmp3_r(data)                   ((0x00FF0000&(data))>>16)
#define PTG_R_C6Y_CB_CR_get_i_c6cb_92b_bmp4_r(data)                   ((0x0000FF00&(data))>>8)
#define PTG_R_C6Y_CB_CR_get_nonactive_color_def_r(data)               (0x000000FF&(data))


#define PTG_R_C7Y_CB_CR                                               0x18022174
#define PTG_R_C7Y_CB_CR_reg_addr                                      "0xb8022174"
#define PTG_R_C7Y_CB_CR_reg                                           0xb8022174
#define PTG_R_C7Y_CB_CR_inst_addr                                     "0x005D"
#define PTG_R_C7Y_CB_CR_inst                                          0x005D
#define PTG_R_C7Y_CB_CR_i_c7y_92b_bmp5_r_shift                        (24)
#define PTG_R_C7Y_CB_CR_i_c7cr_92b_bmp6_r_shift                       (16)
#define PTG_R_C7Y_CB_CR_i_c7cb_92b_bmp7_r_shift                       (8)
#define PTG_R_C7Y_CB_CR_dummy18022174_7_3_shift                       (3)
#define PTG_R_C7Y_CB_CR_max_color_r_shift                             (0)
#define PTG_R_C7Y_CB_CR_i_c7y_92b_bmp5_r_mask                         (0xFF000000)
#define PTG_R_C7Y_CB_CR_i_c7cr_92b_bmp6_r_mask                        (0x00FF0000)
#define PTG_R_C7Y_CB_CR_i_c7cb_92b_bmp7_r_mask                        (0x0000FF00)
#define PTG_R_C7Y_CB_CR_dummy18022174_7_3_mask                        (0x000000F8)
#define PTG_R_C7Y_CB_CR_max_color_r_mask                              (0x00000007)
#define PTG_R_C7Y_CB_CR_i_c7y_92b_bmp5_r(data)                        (0xFF000000&((data)<<24))
#define PTG_R_C7Y_CB_CR_i_c7cr_92b_bmp6_r(data)                       (0x00FF0000&((data)<<16))
#define PTG_R_C7Y_CB_CR_i_c7cb_92b_bmp7_r(data)                       (0x0000FF00&((data)<<8))
#define PTG_R_C7Y_CB_CR_dummy18022174_7_3(data)                       (0x000000F8&((data)<<3))
#define PTG_R_C7Y_CB_CR_max_color_r(data)                             (0x00000007&(data))
#define PTG_R_C7Y_CB_CR_get_i_c7y_92b_bmp5_r(data)                    ((0xFF000000&(data))>>24)
#define PTG_R_C7Y_CB_CR_get_i_c7cr_92b_bmp6_r(data)                   ((0x00FF0000&(data))>>16)
#define PTG_R_C7Y_CB_CR_get_i_c7cb_92b_bmp7_r(data)                   ((0x0000FF00&(data))>>8)
#define PTG_R_C7Y_CB_CR_get_dummy18022174_7_3(data)                   ((0x000000F8&(data))>>3)
#define PTG_R_C7Y_CB_CR_get_max_color_r(data)                         (0x00000007&(data))


#define PTG_R_MAX_COLOR_CTRL                                          0x18022178
#define PTG_R_MAX_COLOR_CTRL_reg_addr                                 "0xb8022178"
#define PTG_R_MAX_COLOR_CTRL_reg                                      0xb8022178
#define PTG_R_MAX_COLOR_CTRL_inst_addr                                "0x005E"
#define PTG_R_MAX_COLOR_CTRL_inst                                     0x005E
#define PTG_R_MAX_COLOR_CTRL_mv_h_r_shift                             (24)
#define PTG_R_MAX_COLOR_CTRL_mv_v_r_shift                             (16)
#define PTG_R_MAX_COLOR_CTRL_mv_seq_type_r_shift                      (15)
#define PTG_R_MAX_COLOR_CTRL_rdm_period_r_shift                       (12)
#define PTG_R_MAX_COLOR_CTRL_mv_vs_num_r_shift                        (8)
#define PTG_R_MAX_COLOR_CTRL_mp_adj_num_r_shift                       (0)
#define PTG_R_MAX_COLOR_CTRL_mv_h_r_mask                              (0xFF000000)
#define PTG_R_MAX_COLOR_CTRL_mv_v_r_mask                              (0x00FF0000)
#define PTG_R_MAX_COLOR_CTRL_mv_seq_type_r_mask                       (0x00008000)
#define PTG_R_MAX_COLOR_CTRL_rdm_period_r_mask                        (0x00007000)
#define PTG_R_MAX_COLOR_CTRL_mv_vs_num_r_mask                         (0x00000F00)
#define PTG_R_MAX_COLOR_CTRL_mp_adj_num_r_mask                        (0x000000FF)
#define PTG_R_MAX_COLOR_CTRL_mv_h_r(data)                             (0xFF000000&((data)<<24))
#define PTG_R_MAX_COLOR_CTRL_mv_v_r(data)                             (0x00FF0000&((data)<<16))
#define PTG_R_MAX_COLOR_CTRL_mv_seq_type_r(data)                      (0x00008000&((data)<<15))
#define PTG_R_MAX_COLOR_CTRL_rdm_period_r(data)                       (0x00007000&((data)<<12))
#define PTG_R_MAX_COLOR_CTRL_mv_vs_num_r(data)                        (0x00000F00&((data)<<8))
#define PTG_R_MAX_COLOR_CTRL_mp_adj_num_r(data)                       (0x000000FF&(data))
#define PTG_R_MAX_COLOR_CTRL_get_mv_h_r(data)                         ((0xFF000000&(data))>>24)
#define PTG_R_MAX_COLOR_CTRL_get_mv_v_r(data)                         ((0x00FF0000&(data))>>16)
#define PTG_R_MAX_COLOR_CTRL_get_mv_seq_type_r(data)                  ((0x00008000&(data))>>15)
#define PTG_R_MAX_COLOR_CTRL_get_rdm_period_r(data)                   ((0x00007000&(data))>>12)
#define PTG_R_MAX_COLOR_CTRL_get_mv_vs_num_r(data)                    ((0x00000F00&(data))>>8)
#define PTG_R_MAX_COLOR_CTRL_get_mp_adj_num_r(data)                   (0x000000FF&(data))


#define PTG_CMI_CTRL1                                                 0x1802217c
#define PTG_CMI_CTRL1_reg_addr                                        "0xb802217c"
#define PTG_CMI_CTRL1_reg                                             0xb802217c
#define PTG_CMI_CTRL1_inst_addr                                       "0x005F"
#define PTG_CMI_CTRL1_inst                                            0x005F
#define PTG_CMI_CTRL1_chess_v_size_shift                              (16)
#define PTG_CMI_CTRL1_grad_sub_pix_en_shift                           (13)
#define PTG_CMI_CTRL1_grad_cbar_en_shift                              (12)
#define PTG_CMI_CTRL1_grad_cbar_pos_shift                             (7)
#define PTG_CMI_CTRL1_grad_sub_pix_on_mask_shift                      (4)
#define PTG_CMI_CTRL1_grad_cbar_step_hv_shift                         (0)
#define PTG_CMI_CTRL1_chess_v_size_mask                               (0x07FF0000)
#define PTG_CMI_CTRL1_grad_sub_pix_en_mask                            (0x00002000)
#define PTG_CMI_CTRL1_grad_cbar_en_mask                               (0x00001000)
#define PTG_CMI_CTRL1_grad_cbar_pos_mask                              (0x00000080)
#define PTG_CMI_CTRL1_grad_sub_pix_on_mask_mask                       (0x00000070)
#define PTG_CMI_CTRL1_grad_cbar_step_hv_mask                          (0x0000000F)
#define PTG_CMI_CTRL1_chess_v_size(data)                              (0x07FF0000&((data)<<16))
#define PTG_CMI_CTRL1_grad_sub_pix_en(data)                           (0x00002000&((data)<<13))
#define PTG_CMI_CTRL1_grad_cbar_en(data)                              (0x00001000&((data)<<12))
#define PTG_CMI_CTRL1_grad_cbar_pos(data)                             (0x00000080&((data)<<7))
#define PTG_CMI_CTRL1_grad_sub_pix_on_mask(data)                      (0x00000070&((data)<<4))
#define PTG_CMI_CTRL1_grad_cbar_step_hv(data)                         (0x0000000F&(data))
#define PTG_CMI_CTRL1_get_chess_v_size(data)                          ((0x07FF0000&(data))>>16)
#define PTG_CMI_CTRL1_get_grad_sub_pix_en(data)                       ((0x00002000&(data))>>13)
#define PTG_CMI_CTRL1_get_grad_cbar_en(data)                          ((0x00001000&(data))>>12)
#define PTG_CMI_CTRL1_get_grad_cbar_pos(data)                         ((0x00000080&(data))>>7)
#define PTG_CMI_CTRL1_get_grad_sub_pix_on_mask(data)                  ((0x00000070&(data))>>4)
#define PTG_CMI_CTRL1_get_grad_cbar_step_hv(data)                     (0x0000000F&(data))


#define PTG_CMI_CTRL2                                                 0x18022180
#define PTG_CMI_CTRL2_reg_addr                                        "0xb8022180"
#define PTG_CMI_CTRL2_reg                                             0xb8022180
#define PTG_CMI_CTRL2_inst_addr                                       "0x0060"
#define PTG_CMI_CTRL2_inst                                            0x0060
#define PTG_CMI_CTRL2_y_bright_en_shift                               (16)
#define PTG_CMI_CTRL2_cb_bright_en_shift                              (8)
#define PTG_CMI_CTRL2_cr_bright_en_shift                              (0)
#define PTG_CMI_CTRL2_y_bright_en_mask                                (0x00FF0000)
#define PTG_CMI_CTRL2_cb_bright_en_mask                               (0x0000FF00)
#define PTG_CMI_CTRL2_cr_bright_en_mask                               (0x000000FF)
#define PTG_CMI_CTRL2_y_bright_en(data)                               (0x00FF0000&((data)<<16))
#define PTG_CMI_CTRL2_cb_bright_en(data)                              (0x0000FF00&((data)<<8))
#define PTG_CMI_CTRL2_cr_bright_en(data)                              (0x000000FF&(data))
#define PTG_CMI_CTRL2_get_y_bright_en(data)                           ((0x00FF0000&(data))>>16)
#define PTG_CMI_CTRL2_get_cb_bright_en(data)                          ((0x0000FF00&(data))>>8)
#define PTG_CMI_CTRL2_get_cr_bright_en(data)                          (0x000000FF&(data))


#define PTG_CMI_CTRL3                                                 0x18022184
#define PTG_CMI_CTRL3_reg_addr                                        "0xb8022184"
#define PTG_CMI_CTRL3_reg                                             0xb8022184
#define PTG_CMI_CTRL3_inst_addr                                       "0x0061"
#define PTG_CMI_CTRL3_inst                                            0x0061
#define PTG_CMI_CTRL3_bmp_sub_pix_en_shift                            (11)
#define PTG_CMI_CTRL3_bright_shift                                    (0)
#define PTG_CMI_CTRL3_bmp_sub_pix_en_mask                             (0x00000800)
#define PTG_CMI_CTRL3_bright_mask                                     (0x000003FF)
#define PTG_CMI_CTRL3_bmp_sub_pix_en(data)                            (0x00000800&((data)<<11))
#define PTG_CMI_CTRL3_bright(data)                                    (0x000003FF&(data))
#define PTG_CMI_CTRL3_get_bmp_sub_pix_en(data)                        ((0x00000800&(data))>>11)
#define PTG_CMI_CTRL3_get_bright(data)                                (0x000003FF&(data))


#define PTG_COLOR_EXTEND1                                             0x18022188
#define PTG_COLOR_EXTEND1_reg_addr                                    "0xb8022188"
#define PTG_COLOR_EXTEND1_reg                                         0xb8022188
#define PTG_COLOR_EXTEND1_inst_addr                                   "0x0062"
#define PTG_COLOR_EXTEND1_inst                                        0x0062
#define PTG_COLOR_EXTEND1_color_ext_en_shift                          (24)
#define PTG_COLOR_EXTEND1_i_c3y_ext_shift                             (22)
#define PTG_COLOR_EXTEND1_i_c3cb_ext_shift                            (20)
#define PTG_COLOR_EXTEND1_i_c3cr_ext_shift                            (18)
#define PTG_COLOR_EXTEND1_i_c2y_ext_shift                             (16)
#define PTG_COLOR_EXTEND1_i_c2cr_ext_shift                            (14)
#define PTG_COLOR_EXTEND1_i_c2cb_ext_shift                            (12)
#define PTG_COLOR_EXTEND1_i_c1y_ext_shift                             (10)
#define PTG_COLOR_EXTEND1_i_c1cr_ext_shift                            (8)
#define PTG_COLOR_EXTEND1_i_c1cb_ext_shift                            (6)
#define PTG_COLOR_EXTEND1_i_c0y_ext_shift                             (4)
#define PTG_COLOR_EXTEND1_i_c0cr_ext_shift                            (2)
#define PTG_COLOR_EXTEND1_i_c0cb_ext_shift                            (0)
#define PTG_COLOR_EXTEND1_color_ext_en_mask                           (0x01000000)
#define PTG_COLOR_EXTEND1_i_c3y_ext_mask                              (0x00C00000)
#define PTG_COLOR_EXTEND1_i_c3cb_ext_mask                             (0x00300000)
#define PTG_COLOR_EXTEND1_i_c3cr_ext_mask                             (0x000C0000)
#define PTG_COLOR_EXTEND1_i_c2y_ext_mask                              (0x00030000)
#define PTG_COLOR_EXTEND1_i_c2cr_ext_mask                             (0x0000C000)
#define PTG_COLOR_EXTEND1_i_c2cb_ext_mask                             (0x00003000)
#define PTG_COLOR_EXTEND1_i_c1y_ext_mask                              (0x00000C00)
#define PTG_COLOR_EXTEND1_i_c1cr_ext_mask                             (0x00000300)
#define PTG_COLOR_EXTEND1_i_c1cb_ext_mask                             (0x000000C0)
#define PTG_COLOR_EXTEND1_i_c0y_ext_mask                              (0x00000030)
#define PTG_COLOR_EXTEND1_i_c0cr_ext_mask                             (0x0000000C)
#define PTG_COLOR_EXTEND1_i_c0cb_ext_mask                             (0x00000003)
#define PTG_COLOR_EXTEND1_color_ext_en(data)                          (0x01000000&((data)<<24))
#define PTG_COLOR_EXTEND1_i_c3y_ext(data)                             (0x00C00000&((data)<<22))
#define PTG_COLOR_EXTEND1_i_c3cb_ext(data)                            (0x00300000&((data)<<20))
#define PTG_COLOR_EXTEND1_i_c3cr_ext(data)                            (0x000C0000&((data)<<18))
#define PTG_COLOR_EXTEND1_i_c2y_ext(data)                             (0x00030000&((data)<<16))
#define PTG_COLOR_EXTEND1_i_c2cr_ext(data)                            (0x0000C000&((data)<<14))
#define PTG_COLOR_EXTEND1_i_c2cb_ext(data)                            (0x00003000&((data)<<12))
#define PTG_COLOR_EXTEND1_i_c1y_ext(data)                             (0x00000C00&((data)<<10))
#define PTG_COLOR_EXTEND1_i_c1cr_ext(data)                            (0x00000300&((data)<<8))
#define PTG_COLOR_EXTEND1_i_c1cb_ext(data)                            (0x000000C0&((data)<<6))
#define PTG_COLOR_EXTEND1_i_c0y_ext(data)                             (0x00000030&((data)<<4))
#define PTG_COLOR_EXTEND1_i_c0cr_ext(data)                            (0x0000000C&((data)<<2))
#define PTG_COLOR_EXTEND1_i_c0cb_ext(data)                            (0x00000003&(data))
#define PTG_COLOR_EXTEND1_get_color_ext_en(data)                      ((0x01000000&(data))>>24)
#define PTG_COLOR_EXTEND1_get_i_c3y_ext(data)                         ((0x00C00000&(data))>>22)
#define PTG_COLOR_EXTEND1_get_i_c3cb_ext(data)                        ((0x00300000&(data))>>20)
#define PTG_COLOR_EXTEND1_get_i_c3cr_ext(data)                        ((0x000C0000&(data))>>18)
#define PTG_COLOR_EXTEND1_get_i_c2y_ext(data)                         ((0x00030000&(data))>>16)
#define PTG_COLOR_EXTEND1_get_i_c2cr_ext(data)                        ((0x0000C000&(data))>>14)
#define PTG_COLOR_EXTEND1_get_i_c2cb_ext(data)                        ((0x00003000&(data))>>12)
#define PTG_COLOR_EXTEND1_get_i_c1y_ext(data)                         ((0x00000C00&(data))>>10)
#define PTG_COLOR_EXTEND1_get_i_c1cr_ext(data)                        ((0x00000300&(data))>>8)
#define PTG_COLOR_EXTEND1_get_i_c1cb_ext(data)                        ((0x000000C0&(data))>>6)
#define PTG_COLOR_EXTEND1_get_i_c0y_ext(data)                         ((0x00000030&(data))>>4)
#define PTG_COLOR_EXTEND1_get_i_c0cr_ext(data)                        ((0x0000000C&(data))>>2)
#define PTG_COLOR_EXTEND1_get_i_c0cb_ext(data)                        (0x00000003&(data))


#define PTG_COLOR_EXTEND2                                             0x1802218c
#define PTG_COLOR_EXTEND2_reg_addr                                    "0xb802218c"
#define PTG_COLOR_EXTEND2_reg                                         0xb802218c
#define PTG_COLOR_EXTEND2_inst_addr                                   "0x0063"
#define PTG_COLOR_EXTEND2_inst                                        0x0063
#define PTG_COLOR_EXTEND2_i_c7y_ext_shift                             (22)
#define PTG_COLOR_EXTEND2_i_c7cb_ext_shift                            (20)
#define PTG_COLOR_EXTEND2_i_c7cr_ext_shift                            (18)
#define PTG_COLOR_EXTEND2_i_c6y_ext_shift                             (16)
#define PTG_COLOR_EXTEND2_i_c6cr_ext_shift                            (14)
#define PTG_COLOR_EXTEND2_i_c6cb_ext_shift                            (12)
#define PTG_COLOR_EXTEND2_i_c5y_ext_shift                             (10)
#define PTG_COLOR_EXTEND2_i_c5cr_ext_shift                            (8)
#define PTG_COLOR_EXTEND2_i_c5cb_ext_shift                            (6)
#define PTG_COLOR_EXTEND2_i_c4y_ext_shift                             (4)
#define PTG_COLOR_EXTEND2_i_c4cr_ext_shift                            (2)
#define PTG_COLOR_EXTEND2_i_c4cb_ext_shift                            (0)
#define PTG_COLOR_EXTEND2_i_c7y_ext_mask                              (0x00C00000)
#define PTG_COLOR_EXTEND2_i_c7cb_ext_mask                             (0x00300000)
#define PTG_COLOR_EXTEND2_i_c7cr_ext_mask                             (0x000C0000)
#define PTG_COLOR_EXTEND2_i_c6y_ext_mask                              (0x00030000)
#define PTG_COLOR_EXTEND2_i_c6cr_ext_mask                             (0x0000C000)
#define PTG_COLOR_EXTEND2_i_c6cb_ext_mask                             (0x00003000)
#define PTG_COLOR_EXTEND2_i_c5y_ext_mask                              (0x00000C00)
#define PTG_COLOR_EXTEND2_i_c5cr_ext_mask                             (0x00000300)
#define PTG_COLOR_EXTEND2_i_c5cb_ext_mask                             (0x000000C0)
#define PTG_COLOR_EXTEND2_i_c4y_ext_mask                              (0x00000030)
#define PTG_COLOR_EXTEND2_i_c4cr_ext_mask                             (0x0000000C)
#define PTG_COLOR_EXTEND2_i_c4cb_ext_mask                             (0x00000003)
#define PTG_COLOR_EXTEND2_i_c7y_ext(data)                             (0x00C00000&((data)<<22))
#define PTG_COLOR_EXTEND2_i_c7cb_ext(data)                            (0x00300000&((data)<<20))
#define PTG_COLOR_EXTEND2_i_c7cr_ext(data)                            (0x000C0000&((data)<<18))
#define PTG_COLOR_EXTEND2_i_c6y_ext(data)                             (0x00030000&((data)<<16))
#define PTG_COLOR_EXTEND2_i_c6cr_ext(data)                            (0x0000C000&((data)<<14))
#define PTG_COLOR_EXTEND2_i_c6cb_ext(data)                            (0x00003000&((data)<<12))
#define PTG_COLOR_EXTEND2_i_c5y_ext(data)                             (0x00000C00&((data)<<10))
#define PTG_COLOR_EXTEND2_i_c5cr_ext(data)                            (0x00000300&((data)<<8))
#define PTG_COLOR_EXTEND2_i_c5cb_ext(data)                            (0x000000C0&((data)<<6))
#define PTG_COLOR_EXTEND2_i_c4y_ext(data)                             (0x00000030&((data)<<4))
#define PTG_COLOR_EXTEND2_i_c4cr_ext(data)                            (0x0000000C&((data)<<2))
#define PTG_COLOR_EXTEND2_i_c4cb_ext(data)                            (0x00000003&(data))
#define PTG_COLOR_EXTEND2_get_i_c7y_ext(data)                         ((0x00C00000&(data))>>22)
#define PTG_COLOR_EXTEND2_get_i_c7cb_ext(data)                        ((0x00300000&(data))>>20)
#define PTG_COLOR_EXTEND2_get_i_c7cr_ext(data)                        ((0x000C0000&(data))>>18)
#define PTG_COLOR_EXTEND2_get_i_c6y_ext(data)                         ((0x00030000&(data))>>16)
#define PTG_COLOR_EXTEND2_get_i_c6cr_ext(data)                        ((0x0000C000&(data))>>14)
#define PTG_COLOR_EXTEND2_get_i_c6cb_ext(data)                        ((0x00003000&(data))>>12)
#define PTG_COLOR_EXTEND2_get_i_c5y_ext(data)                         ((0x00000C00&(data))>>10)
#define PTG_COLOR_EXTEND2_get_i_c5cr_ext(data)                        ((0x00000300&(data))>>8)
#define PTG_COLOR_EXTEND2_get_i_c5cb_ext(data)                        ((0x000000C0&(data))>>6)
#define PTG_COLOR_EXTEND2_get_i_c4y_ext(data)                         ((0x00000030&(data))>>4)
#define PTG_COLOR_EXTEND2_get_i_c4cr_ext(data)                        ((0x0000000C&(data))>>2)
#define PTG_COLOR_EXTEND2_get_i_c4cb_ext(data)                        (0x00000003&(data))
#endif
