// This file is generated using the spec version 1.39, firmware template version 1.39and SRIF Parser                                                                                source code SVN rev:794                    Version flow no.:1.1.45
#ifndef _HDMI_PTG_REG_H_INCLUDED_
#define _HDMI_PTG_REG_H_INCLUDED_

//#define  _HDMI_PTG_USE_STRUCT
#ifdef _HDMI_PTG_USE_STRUCT

typedef struct
{
    unsigned int    reserved_0:3;
    unsigned int    totalh_pixel:13;
    unsigned int    dummy1800d500_15_13:3;
    unsigned int    totalv_line:13;
}HDMI_ptg_totalhv;

typedef struct
{
    unsigned int    reserved_0:3;
    unsigned int    act_h_sta:13;
    unsigned int    dummy1800d504_15_13:3;
    unsigned int    act_wid:13;
}HDMI_ptg_act_h_start_width;

typedef struct
{
    unsigned int    reserved_0:3;
    unsigned int    act_v_sta:13;
    unsigned int    dummy1800d508_15_13:3;
    unsigned int    act_len:13;
}HDMI_ptg_act_v_start_length;

typedef struct
{
    unsigned int    reserved_0:19;
    unsigned int    sync_timing_sel:1;
    unsigned int    dummy1800d50c_11_10:2;
    unsigned int    hs_highpulse_wid:2;
    unsigned int    dummy1800d50c_7:1;
    unsigned int    fix_l_flag:1;
    unsigned int    fix_l_flag_en:1;
    unsigned int    active_space_fix_en:1;
    unsigned int    tg_mode_sel:2;
    unsigned int    tg_en_field:1;
    unsigned int    tg_enable:1;
}HDMI_ptg_tg;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    popup_linecnt:1;
    unsigned int    cur_l_flag_out:1;
    unsigned int    cur_field_out:1;
    unsigned int    cur_linecnt_out:13;
}HDMI_ptg_tg_line;

typedef struct
{
    unsigned int    reserved_0:3;
    unsigned int    pat_h_sta:13;
    unsigned int    dummy1800d514_15_13:3;
    unsigned int    pat_wid:13;
}HDMI_ptg_pat_hsta_width;

typedef struct
{
    unsigned int    reserved_0:3;
    unsigned int    pat_v_sta:13;
    unsigned int    dummy1800d518_15_13:3;
    unsigned int    pat_len:13;
}HDMI_ptg_pat_vsta_length;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    en_rdm_bkg_l:1;
    unsigned int    xc_seq_l:3;
    unsigned int    en_xc_l:1;
    unsigned int    pat_mode_l:3;
}HDMI_ptg_l_ctrl;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    auto_state_l:2;
    unsigned int    hold_state_l:2;
    unsigned int    hold_state_rdy_l:1;
    unsigned int    barw_l:11;
}HDMI_ptg_l_barw;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    i_c0y_92b_l:8;
    unsigned int    i_c0cr_92b_l:8;
    unsigned int    i_c0cb_92b_l:8;
}HDMI_ptg_l_c0y_cb_cr;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    i_c1y_92b_l:8;
    unsigned int    i_c1cr_92b_l:8;
    unsigned int    i_c1cb_92b_l:8;
}HDMI_ptg_l_c1y_cb_cr;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    i_c2y_92b_l:8;
    unsigned int    i_c2cr_92b_l:8;
    unsigned int    i_c2cb_92b_l:8;
}HDMI_ptg_l_c2y_cb_cr;

typedef struct
{
    unsigned int    i_c3y_98b_l:2;
    unsigned int    i_c3y_72b_grady_l:6;
    unsigned int    i_c3cr_98b_l:2;
    unsigned int    i_c3cr_72b_gradcr_l:6;
    unsigned int    i_c3cb_98b_l:2;
    unsigned int    i_c3cb_72b_gradcb_l:6;
    unsigned int    dummy1800d534_7_0:8;
}HDMI_ptg_l_c3y_cb_cr;

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
}HDMI_ptg_l_c4y_cb_cr;

typedef struct
{
    unsigned int    i_c5y_92b_bmptp_l:8;
    unsigned int    i_c5cr_92b_bmp0_l:8;
    unsigned int    i_c5cb_92b_bmp1_l:8;
    unsigned int    dummy1800d53c_7_0:8;
}HDMI_ptg_l_c5y_cr_cb;

typedef struct
{
    unsigned int    i_c6y_92b_bmp2_l:8;
    unsigned int    i_c6cr_92b_bmp3_l:8;
    unsigned int    i_c6cb_92b_bmp4_l:8;
    unsigned int    nonactive_color_def_l:8;
}HDMI_ptg_l_c6y_cb_cr;

typedef struct
{
    unsigned int    i_c7y_92b_bmp5_l:8;
    unsigned int    i_c7cr_92b_bmp6_l:8;
    unsigned int    i_c7cb_92b_bmp7_l:8;
    unsigned int    dummy1800d544_7_0:8;
}HDMI_ptg_l_c7y_cb_cr;

typedef struct
{
    unsigned int    dummy1800d548_31_27:5;
    unsigned int    max_color_l:3;
    unsigned int    mv_h_l:4;
    unsigned int    mv_v_l:4;
    unsigned int    mv_seq_type_l:1;
    unsigned int    rdm_period_l:3;
    unsigned int    mv_vs_num_l:4;
    unsigned int    mp_adj_num_l:8;
}HDMI_ptg_l_max_color_ctrl;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    en_rdm_bkg_r:1;
    unsigned int    xc_seq_r:3;
    unsigned int    en_xc_r:1;
    unsigned int    pat_mode_r:3;
}HDMI_ptg_r_ctrl;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    auto_state_r:2;
    unsigned int    hold_state_r:2;
    unsigned int    hold_state_rdy_r:1;
    unsigned int    barw_r:11;
}HDMI_ptg_r_barw;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    i_c0y_92b_r:8;
    unsigned int    i_c0cr_92b_r:8;
    unsigned int    i_c0cb_92b_r:8;
}HDMI_ptg_r_c0y_cb_cr;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    i_c1y_92b_r:8;
    unsigned int    i_c1cr_92b_r:8;
    unsigned int    i_c1cb_92b_r:8;
}HDMI_ptg_r_c1y_cb_cr;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    i_c2y_92b_r:8;
    unsigned int    i_c2cr_92b_r:8;
    unsigned int    i_c2cb_92b_r:8;
}HDMI_ptg_r_c2y_cb_cr;

typedef struct
{
    unsigned int    i_c3y_98b_r:2;
    unsigned int    i_c3y_72b_grady_r:6;
    unsigned int    i_c3cr_98b_r:2;
    unsigned int    i_c3cr_72b_gradcr_r:6;
    unsigned int    i_c3cb_98b_r:2;
    unsigned int    i_c3cb_72b_gradcb_r:6;
    unsigned int    dummy1800d564_7_0:8;
}HDMI_ptg_r_c3y_cb_cr;

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
}HDMI_ptg_r_c4y_cb_cr;

typedef struct
{
    unsigned int    i_c5y_92b_bmptp_r:8;
    unsigned int    i_c5cr_92b_bmp0_r:8;
    unsigned int    i_c5cb_92b_bmp1_r:8;
    unsigned int    dummy1800d56c_7_0:8;
}HDMI_ptg_r_c5y_cr_cb;

typedef struct
{
    unsigned int    i_c6y_92b_bmp2_r:8;
    unsigned int    i_c6cr_92b_bmp3_r:8;
    unsigned int    i_c6cb_92b_bmp4_r:8;
    unsigned int    nonactive_color_def_r:8;
}HDMI_ptg_r_c6y_cb_cr;

typedef struct
{
    unsigned int    i_c7y_92b_bmp5_r:8;
    unsigned int    i_c7cr_92b_bmp6_r:8;
    unsigned int    i_c7cb_92b_bmp7_r:8;
    unsigned int    dummy1800d574_7_0:8;
}HDMI_ptg_r_c7y_cb_cr;

typedef struct
{
    unsigned int    dummy1800d578_31_27:5;
    unsigned int    max_color_r:3;
    unsigned int    mv_h_r:4;
    unsigned int    mv_v_r:4;
    unsigned int    mv_seq_type_r:1;
    unsigned int    rdm_period_r:3;
    unsigned int    mv_vs_num_r:4;
    unsigned int    mp_adj_num_r:8;
}HDMI_ptg_r_max_color_ctrl;

typedef struct
{
    unsigned int    reserved_0:25;
    unsigned int    hdmi_test_sel:3;
    unsigned int    hdmi_out_sel:1;
    unsigned int    force_ctsfifo_rstn_hdmi:1;
    unsigned int    en_ctsfifo_vsrst_hdmi:1;
    unsigned int    en_ctsfifo_bypass_hdmi:1;
}HDMI_cts_fifo_ctl;
#endif


#define HDMI_PTG_TOTALHV                                              0x1800d500
#define HDMI_PTG_TOTALHV_reg_addr                                     "0xb800d500"
#define HDMI_PTG_TOTALHV_reg                                          0xb800d500
#define HDMI_PTG_TOTALHV_inst_addr                                    "0x0140"
#define HDMI_PTG_TOTALHV_inst                                         0x0140
#define HDMI_PTG_TOTALHV_totalh_pixel_shift                           (16)
#define HDMI_PTG_TOTALHV_dummy1800d500_15_13_shift                    (13)
#define HDMI_PTG_TOTALHV_totalv_line_shift                            (0)
#define HDMI_PTG_TOTALHV_totalh_pixel_mask                            (0x1FFF0000)
#define HDMI_PTG_TOTALHV_dummy1800d500_15_13_mask                     (0x0000E000)
#define HDMI_PTG_TOTALHV_totalv_line_mask                             (0x00001FFF)
#define HDMI_PTG_TOTALHV_totalh_pixel(data)                           (0x1FFF0000&((data)<<16))
#define HDMI_PTG_TOTALHV_dummy1800d500_15_13(data)                    (0x0000E000&((data)<<13))
#define HDMI_PTG_TOTALHV_totalv_line(data)                            (0x00001FFF&(data))
#define HDMI_PTG_TOTALHV_get_totalh_pixel(data)                       ((0x1FFF0000&(data))>>16)
#define HDMI_PTG_TOTALHV_get_dummy1800d500_15_13(data)                ((0x0000E000&(data))>>13)
#define HDMI_PTG_TOTALHV_get_totalv_line(data)                        (0x00001FFF&(data))


#define HDMI_PTG_ACT_H_START_WIDTH                                    0x1800d504
#define HDMI_PTG_ACT_H_START_WIDTH_reg_addr                           "0xb800d504"
#define HDMI_PTG_ACT_H_START_WIDTH_reg                                0xb800d504
#define HDMI_PTG_ACT_H_START_WIDTH_inst_addr                          "0x0141"
#define HDMI_PTG_ACT_H_START_WIDTH_inst                               0x0141
#define HDMI_PTG_ACT_H_START_WIDTH_act_h_sta_shift                    (16)
#define HDMI_PTG_ACT_H_START_WIDTH_dummy1800d504_15_13_shift          (13)
#define HDMI_PTG_ACT_H_START_WIDTH_act_wid_shift                      (0)
#define HDMI_PTG_ACT_H_START_WIDTH_act_h_sta_mask                     (0x1FFF0000)
#define HDMI_PTG_ACT_H_START_WIDTH_dummy1800d504_15_13_mask           (0x0000E000)
#define HDMI_PTG_ACT_H_START_WIDTH_act_wid_mask                       (0x00001FFF)
#define HDMI_PTG_ACT_H_START_WIDTH_act_h_sta(data)                    (0x1FFF0000&((data)<<16))
#define HDMI_PTG_ACT_H_START_WIDTH_dummy1800d504_15_13(data)          (0x0000E000&((data)<<13))
#define HDMI_PTG_ACT_H_START_WIDTH_act_wid(data)                      (0x00001FFF&(data))
#define HDMI_PTG_ACT_H_START_WIDTH_get_act_h_sta(data)                ((0x1FFF0000&(data))>>16)
#define HDMI_PTG_ACT_H_START_WIDTH_get_dummy1800d504_15_13(data)      ((0x0000E000&(data))>>13)
#define HDMI_PTG_ACT_H_START_WIDTH_get_act_wid(data)                  (0x00001FFF&(data))


#define HDMI_PTG_ACT_V_START_LENGTH                                   0x1800d508
#define HDMI_PTG_ACT_V_START_LENGTH_reg_addr                          "0xb800d508"
#define HDMI_PTG_ACT_V_START_LENGTH_reg                               0xb800d508
#define HDMI_PTG_ACT_V_START_LENGTH_inst_addr                         "0x0142"
#define HDMI_PTG_ACT_V_START_LENGTH_inst                              0x0142
#define HDMI_PTG_ACT_V_START_LENGTH_act_v_sta_shift                   (16)
#define HDMI_PTG_ACT_V_START_LENGTH_dummy1800d508_15_13_shift         (13)
#define HDMI_PTG_ACT_V_START_LENGTH_act_len_shift                     (0)
#define HDMI_PTG_ACT_V_START_LENGTH_act_v_sta_mask                    (0x1FFF0000)
#define HDMI_PTG_ACT_V_START_LENGTH_dummy1800d508_15_13_mask          (0x0000E000)
#define HDMI_PTG_ACT_V_START_LENGTH_act_len_mask                      (0x00001FFF)
#define HDMI_PTG_ACT_V_START_LENGTH_act_v_sta(data)                   (0x1FFF0000&((data)<<16))
#define HDMI_PTG_ACT_V_START_LENGTH_dummy1800d508_15_13(data)         (0x0000E000&((data)<<13))
#define HDMI_PTG_ACT_V_START_LENGTH_act_len(data)                     (0x00001FFF&(data))
#define HDMI_PTG_ACT_V_START_LENGTH_get_act_v_sta(data)               ((0x1FFF0000&(data))>>16)
#define HDMI_PTG_ACT_V_START_LENGTH_get_dummy1800d508_15_13(data)     ((0x0000E000&(data))>>13)
#define HDMI_PTG_ACT_V_START_LENGTH_get_act_len(data)                 (0x00001FFF&(data))


#define HDMI_PTG_TG                                                   0x1800d50c
#define HDMI_PTG_TG_reg_addr                                          "0xb800d50c"
#define HDMI_PTG_TG_reg                                               0xb800d50c
#define HDMI_PTG_TG_inst_addr                                         "0x0143"
#define HDMI_PTG_TG_inst                                              0x0143
#define HDMI_PTG_TG_sync_timing_sel_shift                             (12)
#define HDMI_PTG_TG_dummy1800d50c_11_10_shift                         (10)
#define HDMI_PTG_TG_hs_highpulse_wid_shift                            (8)
#define HDMI_PTG_TG_dummy1800d50c_7_shift                             (7)
#define HDMI_PTG_TG_fix_l_flag_shift                                  (6)
#define HDMI_PTG_TG_fix_l_flag_en_shift                               (5)
#define HDMI_PTG_TG_active_space_fix_en_shift                         (4)
#define HDMI_PTG_TG_tg_mode_sel_shift                                 (2)
#define HDMI_PTG_TG_tg_en_field_shift                                 (1)
#define HDMI_PTG_TG_tg_enable_shift                                   (0)
#define HDMI_PTG_TG_sync_timing_sel_mask                              (0x00001000)
#define HDMI_PTG_TG_dummy1800d50c_11_10_mask                          (0x00000C00)
#define HDMI_PTG_TG_hs_highpulse_wid_mask                             (0x00000300)
#define HDMI_PTG_TG_dummy1800d50c_7_mask                              (0x00000080)
#define HDMI_PTG_TG_fix_l_flag_mask                                   (0x00000040)
#define HDMI_PTG_TG_fix_l_flag_en_mask                                (0x00000020)
#define HDMI_PTG_TG_active_space_fix_en_mask                          (0x00000010)
#define HDMI_PTG_TG_tg_mode_sel_mask                                  (0x0000000C)
#define HDMI_PTG_TG_tg_en_field_mask                                  (0x00000002)
#define HDMI_PTG_TG_tg_enable_mask                                    (0x00000001)
#define HDMI_PTG_TG_sync_timing_sel(data)                             (0x00001000&((data)<<12))
#define HDMI_PTG_TG_dummy1800d50c_11_10(data)                         (0x00000C00&((data)<<10))
#define HDMI_PTG_TG_hs_highpulse_wid(data)                            (0x00000300&((data)<<8))
#define HDMI_PTG_TG_dummy1800d50c_7(data)                             (0x00000080&((data)<<7))
#define HDMI_PTG_TG_fix_l_flag(data)                                  (0x00000040&((data)<<6))
#define HDMI_PTG_TG_fix_l_flag_en(data)                               (0x00000020&((data)<<5))
#define HDMI_PTG_TG_active_space_fix_en(data)                         (0x00000010&((data)<<4))
#define HDMI_PTG_TG_tg_mode_sel(data)                                 (0x0000000C&((data)<<2))
#define HDMI_PTG_TG_tg_en_field(data)                                 (0x00000002&((data)<<1))
#define HDMI_PTG_TG_tg_enable(data)                                   (0x00000001&(data))
#define HDMI_PTG_TG_get_sync_timing_sel(data)                         ((0x00001000&(data))>>12)
#define HDMI_PTG_TG_get_dummy1800d50c_11_10(data)                     ((0x00000C00&(data))>>10)
#define HDMI_PTG_TG_get_hs_highpulse_wid(data)                        ((0x00000300&(data))>>8)
#define HDMI_PTG_TG_get_dummy1800d50c_7(data)                         ((0x00000080&(data))>>7)
#define HDMI_PTG_TG_get_fix_l_flag(data)                              ((0x00000040&(data))>>6)
#define HDMI_PTG_TG_get_fix_l_flag_en(data)                           ((0x00000020&(data))>>5)
#define HDMI_PTG_TG_get_active_space_fix_en(data)                     ((0x00000010&(data))>>4)
#define HDMI_PTG_TG_get_tg_mode_sel(data)                             ((0x0000000C&(data))>>2)
#define HDMI_PTG_TG_get_tg_en_field(data)                             ((0x00000002&(data))>>1)
#define HDMI_PTG_TG_get_tg_enable(data)                               (0x00000001&(data))


#define HDMI_PTG_TG_LINE                                              0x1800d510
#define HDMI_PTG_TG_LINE_reg_addr                                     "0xb800d510"
#define HDMI_PTG_TG_LINE_reg                                          0xb800d510
#define HDMI_PTG_TG_LINE_inst_addr                                    "0x0144"
#define HDMI_PTG_TG_LINE_inst                                         0x0144
#define HDMI_PTG_TG_LINE_popup_linecnt_shift                          (15)
#define HDMI_PTG_TG_LINE_cur_l_flag_out_shift                         (14)
#define HDMI_PTG_TG_LINE_cur_field_out_shift                          (13)
#define HDMI_PTG_TG_LINE_cur_linecnt_out_shift                        (0)
#define HDMI_PTG_TG_LINE_popup_linecnt_mask                           (0x00008000)
#define HDMI_PTG_TG_LINE_cur_l_flag_out_mask                          (0x00004000)
#define HDMI_PTG_TG_LINE_cur_field_out_mask                           (0x00002000)
#define HDMI_PTG_TG_LINE_cur_linecnt_out_mask                         (0x00001FFF)
#define HDMI_PTG_TG_LINE_popup_linecnt(data)                          (0x00008000&((data)<<15))
#define HDMI_PTG_TG_LINE_cur_l_flag_out(data)                         (0x00004000&((data)<<14))
#define HDMI_PTG_TG_LINE_cur_field_out(data)                          (0x00002000&((data)<<13))
#define HDMI_PTG_TG_LINE_cur_linecnt_out(data)                        (0x00001FFF&(data))
#define HDMI_PTG_TG_LINE_get_popup_linecnt(data)                      ((0x00008000&(data))>>15)
#define HDMI_PTG_TG_LINE_get_cur_l_flag_out(data)                     ((0x00004000&(data))>>14)
#define HDMI_PTG_TG_LINE_get_cur_field_out(data)                      ((0x00002000&(data))>>13)
#define HDMI_PTG_TG_LINE_get_cur_linecnt_out(data)                    (0x00001FFF&(data))


#define HDMI_PTG_PAT_HSTA_WIDTH                                       0x1800d514
#define HDMI_PTG_PAT_HSTA_WIDTH_reg_addr                              "0xb800d514"
#define HDMI_PTG_PAT_HSTA_WIDTH_reg                                   0xb800d514
#define HDMI_PTG_PAT_HSTA_WIDTH_inst_addr                             "0x0145"
#define HDMI_PTG_PAT_HSTA_WIDTH_inst                                  0x0145
#define HDMI_PTG_PAT_HSTA_WIDTH_pat_h_sta_shift                       (16)
#define HDMI_PTG_PAT_HSTA_WIDTH_dummy1800d514_15_13_shift             (13)
#define HDMI_PTG_PAT_HSTA_WIDTH_pat_wid_shift                         (0)
#define HDMI_PTG_PAT_HSTA_WIDTH_pat_h_sta_mask                        (0x1FFF0000)
#define HDMI_PTG_PAT_HSTA_WIDTH_dummy1800d514_15_13_mask              (0x0000E000)
#define HDMI_PTG_PAT_HSTA_WIDTH_pat_wid_mask                          (0x00001FFF)
#define HDMI_PTG_PAT_HSTA_WIDTH_pat_h_sta(data)                       (0x1FFF0000&((data)<<16))
#define HDMI_PTG_PAT_HSTA_WIDTH_dummy1800d514_15_13(data)             (0x0000E000&((data)<<13))
#define HDMI_PTG_PAT_HSTA_WIDTH_pat_wid(data)                         (0x00001FFF&(data))
#define HDMI_PTG_PAT_HSTA_WIDTH_get_pat_h_sta(data)                   ((0x1FFF0000&(data))>>16)
#define HDMI_PTG_PAT_HSTA_WIDTH_get_dummy1800d514_15_13(data)         ((0x0000E000&(data))>>13)
#define HDMI_PTG_PAT_HSTA_WIDTH_get_pat_wid(data)                     (0x00001FFF&(data))


#define HDMI_PTG_PAT_VSTA_LENGTH                                      0x1800d518
#define HDMI_PTG_PAT_VSTA_LENGTH_reg_addr                             "0xb800d518"
#define HDMI_PTG_PAT_VSTA_LENGTH_reg                                  0xb800d518
#define HDMI_PTG_PAT_VSTA_LENGTH_inst_addr                            "0x0146"
#define HDMI_PTG_PAT_VSTA_LENGTH_inst                                 0x0146
#define HDMI_PTG_PAT_VSTA_LENGTH_pat_v_sta_shift                      (16)
#define HDMI_PTG_PAT_VSTA_LENGTH_dummy1800d518_15_13_shift            (13)
#define HDMI_PTG_PAT_VSTA_LENGTH_pat_len_shift                        (0)
#define HDMI_PTG_PAT_VSTA_LENGTH_pat_v_sta_mask                       (0x1FFF0000)
#define HDMI_PTG_PAT_VSTA_LENGTH_dummy1800d518_15_13_mask             (0x0000E000)
#define HDMI_PTG_PAT_VSTA_LENGTH_pat_len_mask                         (0x00001FFF)
#define HDMI_PTG_PAT_VSTA_LENGTH_pat_v_sta(data)                      (0x1FFF0000&((data)<<16))
#define HDMI_PTG_PAT_VSTA_LENGTH_dummy1800d518_15_13(data)            (0x0000E000&((data)<<13))
#define HDMI_PTG_PAT_VSTA_LENGTH_pat_len(data)                        (0x00001FFF&(data))
#define HDMI_PTG_PAT_VSTA_LENGTH_get_pat_v_sta(data)                  ((0x1FFF0000&(data))>>16)
#define HDMI_PTG_PAT_VSTA_LENGTH_get_dummy1800d518_15_13(data)        ((0x0000E000&(data))>>13)
#define HDMI_PTG_PAT_VSTA_LENGTH_get_pat_len(data)                    (0x00001FFF&(data))


#define HDMI_PTG_L_CTRL                                               0x1800d520
#define HDMI_PTG_L_CTRL_reg_addr                                      "0xb800d520"
#define HDMI_PTG_L_CTRL_reg                                           0xb800d520
#define HDMI_PTG_L_CTRL_inst_addr                                     "0x0148"
#define HDMI_PTG_L_CTRL_inst                                          0x0148
#define HDMI_PTG_L_CTRL_en_rdm_bkg_l_shift                            (7)
#define HDMI_PTG_L_CTRL_xc_seq_l_shift                                (4)
#define HDMI_PTG_L_CTRL_en_xc_l_shift                                 (3)
#define HDMI_PTG_L_CTRL_pat_mode_l_shift                              (0)
#define HDMI_PTG_L_CTRL_en_rdm_bkg_l_mask                             (0x00000080)
#define HDMI_PTG_L_CTRL_xc_seq_l_mask                                 (0x00000070)
#define HDMI_PTG_L_CTRL_en_xc_l_mask                                  (0x00000008)
#define HDMI_PTG_L_CTRL_pat_mode_l_mask                               (0x00000007)
#define HDMI_PTG_L_CTRL_en_rdm_bkg_l(data)                            (0x00000080&((data)<<7))
#define HDMI_PTG_L_CTRL_xc_seq_l(data)                                (0x00000070&((data)<<4))
#define HDMI_PTG_L_CTRL_en_xc_l(data)                                 (0x00000008&((data)<<3))
#define HDMI_PTG_L_CTRL_pat_mode_l(data)                              (0x00000007&(data))
#define HDMI_PTG_L_CTRL_get_en_rdm_bkg_l(data)                        ((0x00000080&(data))>>7)
#define HDMI_PTG_L_CTRL_get_xc_seq_l(data)                            ((0x00000070&(data))>>4)
#define HDMI_PTG_L_CTRL_get_en_xc_l(data)                             ((0x00000008&(data))>>3)
#define HDMI_PTG_L_CTRL_get_pat_mode_l(data)                          (0x00000007&(data))


#define HDMI_PTG_L_BARW                                               0x1800d524
#define HDMI_PTG_L_BARW_reg_addr                                      "0xb800d524"
#define HDMI_PTG_L_BARW_reg                                           0xb800d524
#define HDMI_PTG_L_BARW_inst_addr                                     "0x0149"
#define HDMI_PTG_L_BARW_inst                                          0x0149
#define HDMI_PTG_L_BARW_auto_state_l_shift                            (14)
#define HDMI_PTG_L_BARW_hold_state_l_shift                            (12)
#define HDMI_PTG_L_BARW_hold_state_rdy_l_shift                        (11)
#define HDMI_PTG_L_BARW_barw_l_shift                                  (0)
#define HDMI_PTG_L_BARW_auto_state_l_mask                             (0x0000C000)
#define HDMI_PTG_L_BARW_hold_state_l_mask                             (0x00003000)
#define HDMI_PTG_L_BARW_hold_state_rdy_l_mask                         (0x00000800)
#define HDMI_PTG_L_BARW_barw_l_mask                                   (0x000007FF)
#define HDMI_PTG_L_BARW_auto_state_l(data)                            (0x0000C000&((data)<<14))
#define HDMI_PTG_L_BARW_hold_state_l(data)                            (0x00003000&((data)<<12))
#define HDMI_PTG_L_BARW_hold_state_rdy_l(data)                        (0x00000800&((data)<<11))
#define HDMI_PTG_L_BARW_barw_l(data)                                  (0x000007FF&(data))
#define HDMI_PTG_L_BARW_get_auto_state_l(data)                        ((0x0000C000&(data))>>14)
#define HDMI_PTG_L_BARW_get_hold_state_l(data)                        ((0x00003000&(data))>>12)
#define HDMI_PTG_L_BARW_get_hold_state_rdy_l(data)                    ((0x00000800&(data))>>11)
#define HDMI_PTG_L_BARW_get_barw_l(data)                              (0x000007FF&(data))


#define HDMI_PTG_L_C0Y_CB_CR                                          0x1800d528
#define HDMI_PTG_L_C0Y_CB_CR_reg_addr                                 "0xb800d528"
#define HDMI_PTG_L_C0Y_CB_CR_reg                                      0xb800d528
#define HDMI_PTG_L_C0Y_CB_CR_inst_addr                                "0x014A"
#define HDMI_PTG_L_C0Y_CB_CR_inst                                     0x014A
#define HDMI_PTG_L_C0Y_CB_CR_i_c0y_92b_l_shift                        (16)
#define HDMI_PTG_L_C0Y_CB_CR_i_c0cr_92b_l_shift                       (8)
#define HDMI_PTG_L_C0Y_CB_CR_i_c0cb_92b_l_shift                       (0)
#define HDMI_PTG_L_C0Y_CB_CR_i_c0y_92b_l_mask                         (0x00FF0000)
#define HDMI_PTG_L_C0Y_CB_CR_i_c0cr_92b_l_mask                        (0x0000FF00)
#define HDMI_PTG_L_C0Y_CB_CR_i_c0cb_92b_l_mask                        (0x000000FF)
#define HDMI_PTG_L_C0Y_CB_CR_i_c0y_92b_l(data)                        (0x00FF0000&((data)<<16))
#define HDMI_PTG_L_C0Y_CB_CR_i_c0cr_92b_l(data)                       (0x0000FF00&((data)<<8))
#define HDMI_PTG_L_C0Y_CB_CR_i_c0cb_92b_l(data)                       (0x000000FF&(data))
#define HDMI_PTG_L_C0Y_CB_CR_get_i_c0y_92b_l(data)                    ((0x00FF0000&(data))>>16)
#define HDMI_PTG_L_C0Y_CB_CR_get_i_c0cr_92b_l(data)                   ((0x0000FF00&(data))>>8)
#define HDMI_PTG_L_C0Y_CB_CR_get_i_c0cb_92b_l(data)                   (0x000000FF&(data))


#define HDMI_PTG_L_C1Y_CB_CR                                          0x1800d52c
#define HDMI_PTG_L_C1Y_CB_CR_reg_addr                                 "0xb800d52c"
#define HDMI_PTG_L_C1Y_CB_CR_reg                                      0xb800d52c
#define HDMI_PTG_L_C1Y_CB_CR_inst_addr                                "0x014B"
#define HDMI_PTG_L_C1Y_CB_CR_inst                                     0x014B
#define HDMI_PTG_L_C1Y_CB_CR_i_c1y_92b_l_shift                        (16)
#define HDMI_PTG_L_C1Y_CB_CR_i_c1cr_92b_l_shift                       (8)
#define HDMI_PTG_L_C1Y_CB_CR_i_c1cb_92b_l_shift                       (0)
#define HDMI_PTG_L_C1Y_CB_CR_i_c1y_92b_l_mask                         (0x00FF0000)
#define HDMI_PTG_L_C1Y_CB_CR_i_c1cr_92b_l_mask                        (0x0000FF00)
#define HDMI_PTG_L_C1Y_CB_CR_i_c1cb_92b_l_mask                        (0x000000FF)
#define HDMI_PTG_L_C1Y_CB_CR_i_c1y_92b_l(data)                        (0x00FF0000&((data)<<16))
#define HDMI_PTG_L_C1Y_CB_CR_i_c1cr_92b_l(data)                       (0x0000FF00&((data)<<8))
#define HDMI_PTG_L_C1Y_CB_CR_i_c1cb_92b_l(data)                       (0x000000FF&(data))
#define HDMI_PTG_L_C1Y_CB_CR_get_i_c1y_92b_l(data)                    ((0x00FF0000&(data))>>16)
#define HDMI_PTG_L_C1Y_CB_CR_get_i_c1cr_92b_l(data)                   ((0x0000FF00&(data))>>8)
#define HDMI_PTG_L_C1Y_CB_CR_get_i_c1cb_92b_l(data)                   (0x000000FF&(data))


#define HDMI_PTG_L_C2Y_CB_CR                                          0x1800d530
#define HDMI_PTG_L_C2Y_CB_CR_reg_addr                                 "0xb800d530"
#define HDMI_PTG_L_C2Y_CB_CR_reg                                      0xb800d530
#define HDMI_PTG_L_C2Y_CB_CR_inst_addr                                "0x014C"
#define HDMI_PTG_L_C2Y_CB_CR_inst                                     0x014C
#define HDMI_PTG_L_C2Y_CB_CR_i_c2y_92b_l_shift                        (16)
#define HDMI_PTG_L_C2Y_CB_CR_i_c2cr_92b_l_shift                       (8)
#define HDMI_PTG_L_C2Y_CB_CR_i_c2cb_92b_l_shift                       (0)
#define HDMI_PTG_L_C2Y_CB_CR_i_c2y_92b_l_mask                         (0x00FF0000)
#define HDMI_PTG_L_C2Y_CB_CR_i_c2cr_92b_l_mask                        (0x0000FF00)
#define HDMI_PTG_L_C2Y_CB_CR_i_c2cb_92b_l_mask                        (0x000000FF)
#define HDMI_PTG_L_C2Y_CB_CR_i_c2y_92b_l(data)                        (0x00FF0000&((data)<<16))
#define HDMI_PTG_L_C2Y_CB_CR_i_c2cr_92b_l(data)                       (0x0000FF00&((data)<<8))
#define HDMI_PTG_L_C2Y_CB_CR_i_c2cb_92b_l(data)                       (0x000000FF&(data))
#define HDMI_PTG_L_C2Y_CB_CR_get_i_c2y_92b_l(data)                    ((0x00FF0000&(data))>>16)
#define HDMI_PTG_L_C2Y_CB_CR_get_i_c2cr_92b_l(data)                   ((0x0000FF00&(data))>>8)
#define HDMI_PTG_L_C2Y_CB_CR_get_i_c2cb_92b_l(data)                   (0x000000FF&(data))


#define HDMI_PTG_L_C3Y_CB_CR                                          0x1800d534
#define HDMI_PTG_L_C3Y_CB_CR_reg_addr                                 "0xb800d534"
#define HDMI_PTG_L_C3Y_CB_CR_reg                                      0xb800d534
#define HDMI_PTG_L_C3Y_CB_CR_inst_addr                                "0x014D"
#define HDMI_PTG_L_C3Y_CB_CR_inst                                     0x014D
#define HDMI_PTG_L_C3Y_CB_CR_i_c3y_98b_l_shift                        (30)
#define HDMI_PTG_L_C3Y_CB_CR_i_c3y_72b_grady_l_shift                  (24)
#define HDMI_PTG_L_C3Y_CB_CR_i_c3cr_98b_l_shift                       (22)
#define HDMI_PTG_L_C3Y_CB_CR_i_c3cr_72b_gradcr_l_shift                (16)
#define HDMI_PTG_L_C3Y_CB_CR_i_c3cb_98b_l_shift                       (14)
#define HDMI_PTG_L_C3Y_CB_CR_i_c3cb_72b_gradcb_l_shift                (8)
#define HDMI_PTG_L_C3Y_CB_CR_dummy1800d534_7_0_shift                  (0)
#define HDMI_PTG_L_C3Y_CB_CR_i_c3y_98b_l_mask                         (0xC0000000)
#define HDMI_PTG_L_C3Y_CB_CR_i_c3y_72b_grady_l_mask                   (0x3F000000)
#define HDMI_PTG_L_C3Y_CB_CR_i_c3cr_98b_l_mask                        (0x00C00000)
#define HDMI_PTG_L_C3Y_CB_CR_i_c3cr_72b_gradcr_l_mask                 (0x003F0000)
#define HDMI_PTG_L_C3Y_CB_CR_i_c3cb_98b_l_mask                        (0x0000C000)
#define HDMI_PTG_L_C3Y_CB_CR_i_c3cb_72b_gradcb_l_mask                 (0x00003F00)
#define HDMI_PTG_L_C3Y_CB_CR_dummy1800d534_7_0_mask                   (0x000000FF)
#define HDMI_PTG_L_C3Y_CB_CR_i_c3y_98b_l(data)                        (0xC0000000&((data)<<30))
#define HDMI_PTG_L_C3Y_CB_CR_i_c3y_72b_grady_l(data)                  (0x3F000000&((data)<<24))
#define HDMI_PTG_L_C3Y_CB_CR_i_c3cr_98b_l(data)                       (0x00C00000&((data)<<22))
#define HDMI_PTG_L_C3Y_CB_CR_i_c3cr_72b_gradcr_l(data)                (0x003F0000&((data)<<16))
#define HDMI_PTG_L_C3Y_CB_CR_i_c3cb_98b_l(data)                       (0x0000C000&((data)<<14))
#define HDMI_PTG_L_C3Y_CB_CR_i_c3cb_72b_gradcb_l(data)                (0x00003F00&((data)<<8))
#define HDMI_PTG_L_C3Y_CB_CR_dummy1800d534_7_0(data)                  (0x000000FF&(data))
#define HDMI_PTG_L_C3Y_CB_CR_get_i_c3y_98b_l(data)                    ((0xC0000000&(data))>>30)
#define HDMI_PTG_L_C3Y_CB_CR_get_i_c3y_72b_grady_l(data)              ((0x3F000000&(data))>>24)
#define HDMI_PTG_L_C3Y_CB_CR_get_i_c3cr_98b_l(data)                   ((0x00C00000&(data))>>22)
#define HDMI_PTG_L_C3Y_CB_CR_get_i_c3cr_72b_gradcr_l(data)            ((0x003F0000&(data))>>16)
#define HDMI_PTG_L_C3Y_CB_CR_get_i_c3cb_98b_l(data)                   ((0x0000C000&(data))>>14)
#define HDMI_PTG_L_C3Y_CB_CR_get_i_c3cb_72b_gradcb_l(data)            ((0x00003F00&(data))>>8)
#define HDMI_PTG_L_C3Y_CB_CR_get_dummy1800d534_7_0(data)              (0x000000FF&(data))


#define HDMI_PTG_L_C4Y_CB_CR                                          0x1800d538
#define HDMI_PTG_L_C4Y_CB_CR_reg_addr                                 "0xb800d538"
#define HDMI_PTG_L_C4Y_CB_CR_reg                                      0xb800d538
#define HDMI_PTG_L_C4Y_CB_CR_inst_addr                                "0x014E"
#define HDMI_PTG_L_C4Y_CB_CR_inst                                     0x014E
#define HDMI_PTG_L_C4Y_CB_CR_i_c4y_96b_l_shift                        (28)
#define HDMI_PTG_L_C4Y_CB_CR_i_c4y_52b_step_hv_l_shift                (24)
#define HDMI_PTG_L_C4Y_CB_CR_i_c4cr_92b_l_shift                       (16)
#define HDMI_PTG_L_C4Y_CB_CR_i_c4cb_9b_l_shift                        (15)
#define HDMI_PTG_L_C4Y_CB_CR_i_c4cb_86b_bmp_w_l_shift                 (12)
#define HDMI_PTG_L_C4Y_CB_CR_i_c4cb_5b_l_shift                        (11)
#define HDMI_PTG_L_C4Y_CB_CR_i_c4cb_42b_bmp_h_l_shift                 (8)
#define HDMI_PTG_L_C4Y_CB_CR_i_c4y_96b_l_mask                         (0xF0000000)
#define HDMI_PTG_L_C4Y_CB_CR_i_c4y_52b_step_hv_l_mask                 (0x0F000000)
#define HDMI_PTG_L_C4Y_CB_CR_i_c4cr_92b_l_mask                        (0x00FF0000)
#define HDMI_PTG_L_C4Y_CB_CR_i_c4cb_9b_l_mask                         (0x00008000)
#define HDMI_PTG_L_C4Y_CB_CR_i_c4cb_86b_bmp_w_l_mask                  (0x00007000)
#define HDMI_PTG_L_C4Y_CB_CR_i_c4cb_5b_l_mask                         (0x00000800)
#define HDMI_PTG_L_C4Y_CB_CR_i_c4cb_42b_bmp_h_l_mask                  (0x00000700)
#define HDMI_PTG_L_C4Y_CB_CR_i_c4y_96b_l(data)                        (0xF0000000&((data)<<28))
#define HDMI_PTG_L_C4Y_CB_CR_i_c4y_52b_step_hv_l(data)                (0x0F000000&((data)<<24))
#define HDMI_PTG_L_C4Y_CB_CR_i_c4cr_92b_l(data)                       (0x00FF0000&((data)<<16))
#define HDMI_PTG_L_C4Y_CB_CR_i_c4cb_9b_l(data)                        (0x00008000&((data)<<15))
#define HDMI_PTG_L_C4Y_CB_CR_i_c4cb_86b_bmp_w_l(data)                 (0x00007000&((data)<<12))
#define HDMI_PTG_L_C4Y_CB_CR_i_c4cb_5b_l(data)                        (0x00000800&((data)<<11))
#define HDMI_PTG_L_C4Y_CB_CR_i_c4cb_42b_bmp_h_l(data)                 (0x00000700&((data)<<8))
#define HDMI_PTG_L_C4Y_CB_CR_get_i_c4y_96b_l(data)                    ((0xF0000000&(data))>>28)
#define HDMI_PTG_L_C4Y_CB_CR_get_i_c4y_52b_step_hv_l(data)            ((0x0F000000&(data))>>24)
#define HDMI_PTG_L_C4Y_CB_CR_get_i_c4cr_92b_l(data)                   ((0x00FF0000&(data))>>16)
#define HDMI_PTG_L_C4Y_CB_CR_get_i_c4cb_9b_l(data)                    ((0x00008000&(data))>>15)
#define HDMI_PTG_L_C4Y_CB_CR_get_i_c4cb_86b_bmp_w_l(data)             ((0x00007000&(data))>>12)
#define HDMI_PTG_L_C4Y_CB_CR_get_i_c4cb_5b_l(data)                    ((0x00000800&(data))>>11)
#define HDMI_PTG_L_C4Y_CB_CR_get_i_c4cb_42b_bmp_h_l(data)             ((0x00000700&(data))>>8)


#define HDMI_PTG_L_C5Y_CR_CB                                          0x1800d53c
#define HDMI_PTG_L_C5Y_CR_CB_reg_addr                                 "0xb800d53c"
#define HDMI_PTG_L_C5Y_CR_CB_reg                                      0xb800d53c
#define HDMI_PTG_L_C5Y_CR_CB_inst_addr                                "0x014F"
#define HDMI_PTG_L_C5Y_CR_CB_inst                                     0x014F
#define HDMI_PTG_L_C5Y_CR_CB_i_c5y_92b_bmptp_l_shift                  (24)
#define HDMI_PTG_L_C5Y_CR_CB_i_c5cr_92b_bmp0_l_shift                  (16)
#define HDMI_PTG_L_C5Y_CR_CB_i_c5cb_92b_bmp1_l_shift                  (8)
#define HDMI_PTG_L_C5Y_CR_CB_dummy1800d53c_7_0_shift                  (0)
#define HDMI_PTG_L_C5Y_CR_CB_i_c5y_92b_bmptp_l_mask                   (0xFF000000)
#define HDMI_PTG_L_C5Y_CR_CB_i_c5cr_92b_bmp0_l_mask                   (0x00FF0000)
#define HDMI_PTG_L_C5Y_CR_CB_i_c5cb_92b_bmp1_l_mask                   (0x0000FF00)
#define HDMI_PTG_L_C5Y_CR_CB_dummy1800d53c_7_0_mask                   (0x000000FF)
#define HDMI_PTG_L_C5Y_CR_CB_i_c5y_92b_bmptp_l(data)                  (0xFF000000&((data)<<24))
#define HDMI_PTG_L_C5Y_CR_CB_i_c5cr_92b_bmp0_l(data)                  (0x00FF0000&((data)<<16))
#define HDMI_PTG_L_C5Y_CR_CB_i_c5cb_92b_bmp1_l(data)                  (0x0000FF00&((data)<<8))
#define HDMI_PTG_L_C5Y_CR_CB_dummy1800d53c_7_0(data)                  (0x000000FF&(data))
#define HDMI_PTG_L_C5Y_CR_CB_get_i_c5y_92b_bmptp_l(data)              ((0xFF000000&(data))>>24)
#define HDMI_PTG_L_C5Y_CR_CB_get_i_c5cr_92b_bmp0_l(data)              ((0x00FF0000&(data))>>16)
#define HDMI_PTG_L_C5Y_CR_CB_get_i_c5cb_92b_bmp1_l(data)              ((0x0000FF00&(data))>>8)
#define HDMI_PTG_L_C5Y_CR_CB_get_dummy1800d53c_7_0(data)              (0x000000FF&(data))


#define HDMI_PTG_L_C6Y_CB_CR                                          0x1800d540
#define HDMI_PTG_L_C6Y_CB_CR_reg_addr                                 "0xb800d540"
#define HDMI_PTG_L_C6Y_CB_CR_reg                                      0xb800d540
#define HDMI_PTG_L_C6Y_CB_CR_inst_addr                                "0x0150"
#define HDMI_PTG_L_C6Y_CB_CR_inst                                     0x0150
#define HDMI_PTG_L_C6Y_CB_CR_i_c6y_92b_bmp2_l_shift                   (24)
#define HDMI_PTG_L_C6Y_CB_CR_i_c6cr_92b_bmp3_l_shift                  (16)
#define HDMI_PTG_L_C6Y_CB_CR_i_c6cb_92b_bmp4_l_shift                  (8)
#define HDMI_PTG_L_C6Y_CB_CR_nonactive_color_def_l_shift              (0)
#define HDMI_PTG_L_C6Y_CB_CR_i_c6y_92b_bmp2_l_mask                    (0xFF000000)
#define HDMI_PTG_L_C6Y_CB_CR_i_c6cr_92b_bmp3_l_mask                   (0x00FF0000)
#define HDMI_PTG_L_C6Y_CB_CR_i_c6cb_92b_bmp4_l_mask                   (0x0000FF00)
#define HDMI_PTG_L_C6Y_CB_CR_nonactive_color_def_l_mask               (0x000000FF)
#define HDMI_PTG_L_C6Y_CB_CR_i_c6y_92b_bmp2_l(data)                   (0xFF000000&((data)<<24))
#define HDMI_PTG_L_C6Y_CB_CR_i_c6cr_92b_bmp3_l(data)                  (0x00FF0000&((data)<<16))
#define HDMI_PTG_L_C6Y_CB_CR_i_c6cb_92b_bmp4_l(data)                  (0x0000FF00&((data)<<8))
#define HDMI_PTG_L_C6Y_CB_CR_nonactive_color_def_l(data)              (0x000000FF&(data))
#define HDMI_PTG_L_C6Y_CB_CR_get_i_c6y_92b_bmp2_l(data)               ((0xFF000000&(data))>>24)
#define HDMI_PTG_L_C6Y_CB_CR_get_i_c6cr_92b_bmp3_l(data)              ((0x00FF0000&(data))>>16)
#define HDMI_PTG_L_C6Y_CB_CR_get_i_c6cb_92b_bmp4_l(data)              ((0x0000FF00&(data))>>8)
#define HDMI_PTG_L_C6Y_CB_CR_get_nonactive_color_def_l(data)          (0x000000FF&(data))


#define HDMI_PTG_L_C7Y_CB_CR                                          0x1800d544
#define HDMI_PTG_L_C7Y_CB_CR_reg_addr                                 "0xb800d544"
#define HDMI_PTG_L_C7Y_CB_CR_reg                                      0xb800d544
#define HDMI_PTG_L_C7Y_CB_CR_inst_addr                                "0x0151"
#define HDMI_PTG_L_C7Y_CB_CR_inst                                     0x0151
#define HDMI_PTG_L_C7Y_CB_CR_i_c7y_92b_bmp5_l_shift                   (24)
#define HDMI_PTG_L_C7Y_CB_CR_i_c7cr_92b_bmp6_l_shift                  (16)
#define HDMI_PTG_L_C7Y_CB_CR_i_c7cb_92b_bmp7_l_shift                  (8)
#define HDMI_PTG_L_C7Y_CB_CR_dummy1800d544_7_0_shift                  (0)
#define HDMI_PTG_L_C7Y_CB_CR_i_c7y_92b_bmp5_l_mask                    (0xFF000000)
#define HDMI_PTG_L_C7Y_CB_CR_i_c7cr_92b_bmp6_l_mask                   (0x00FF0000)
#define HDMI_PTG_L_C7Y_CB_CR_i_c7cb_92b_bmp7_l_mask                   (0x0000FF00)
#define HDMI_PTG_L_C7Y_CB_CR_dummy1800d544_7_0_mask                   (0x000000FF)
#define HDMI_PTG_L_C7Y_CB_CR_i_c7y_92b_bmp5_l(data)                   (0xFF000000&((data)<<24))
#define HDMI_PTG_L_C7Y_CB_CR_i_c7cr_92b_bmp6_l(data)                  (0x00FF0000&((data)<<16))
#define HDMI_PTG_L_C7Y_CB_CR_i_c7cb_92b_bmp7_l(data)                  (0x0000FF00&((data)<<8))
#define HDMI_PTG_L_C7Y_CB_CR_dummy1800d544_7_0(data)                  (0x000000FF&(data))
#define HDMI_PTG_L_C7Y_CB_CR_get_i_c7y_92b_bmp5_l(data)               ((0xFF000000&(data))>>24)
#define HDMI_PTG_L_C7Y_CB_CR_get_i_c7cr_92b_bmp6_l(data)              ((0x00FF0000&(data))>>16)
#define HDMI_PTG_L_C7Y_CB_CR_get_i_c7cb_92b_bmp7_l(data)              ((0x0000FF00&(data))>>8)
#define HDMI_PTG_L_C7Y_CB_CR_get_dummy1800d544_7_0(data)              (0x000000FF&(data))


#define HDMI_PTG_L_MAX_COLOR_CTRL                                     0x1800d548
#define HDMI_PTG_L_MAX_COLOR_CTRL_reg_addr                            "0xb800d548"
#define HDMI_PTG_L_MAX_COLOR_CTRL_reg                                 0xb800d548
#define HDMI_PTG_L_MAX_COLOR_CTRL_inst_addr                           "0x0152"
#define HDMI_PTG_L_MAX_COLOR_CTRL_inst                                0x0152
#define HDMI_PTG_L_MAX_COLOR_CTRL_dummy1800d548_31_27_shift           (27)
#define HDMI_PTG_L_MAX_COLOR_CTRL_max_color_l_shift                   (24)
#define HDMI_PTG_L_MAX_COLOR_CTRL_mv_h_l_shift                        (20)
#define HDMI_PTG_L_MAX_COLOR_CTRL_mv_v_l_shift                        (16)
#define HDMI_PTG_L_MAX_COLOR_CTRL_mv_seq_type_l_shift                 (15)
#define HDMI_PTG_L_MAX_COLOR_CTRL_rdm_period_l_shift                  (12)
#define HDMI_PTG_L_MAX_COLOR_CTRL_mv_vs_num_l_shift                   (8)
#define HDMI_PTG_L_MAX_COLOR_CTRL_mp_adj_num_l_shift                  (0)
#define HDMI_PTG_L_MAX_COLOR_CTRL_dummy1800d548_31_27_mask            (0xF8000000)
#define HDMI_PTG_L_MAX_COLOR_CTRL_max_color_l_mask                    (0x07000000)
#define HDMI_PTG_L_MAX_COLOR_CTRL_mv_h_l_mask                         (0x00F00000)
#define HDMI_PTG_L_MAX_COLOR_CTRL_mv_v_l_mask                         (0x000F0000)
#define HDMI_PTG_L_MAX_COLOR_CTRL_mv_seq_type_l_mask                  (0x00008000)
#define HDMI_PTG_L_MAX_COLOR_CTRL_rdm_period_l_mask                   (0x00007000)
#define HDMI_PTG_L_MAX_COLOR_CTRL_mv_vs_num_l_mask                    (0x00000F00)
#define HDMI_PTG_L_MAX_COLOR_CTRL_mp_adj_num_l_mask                   (0x000000FF)
#define HDMI_PTG_L_MAX_COLOR_CTRL_dummy1800d548_31_27(data)           (0xF8000000&((data)<<27))
#define HDMI_PTG_L_MAX_COLOR_CTRL_max_color_l(data)                   (0x07000000&((data)<<24))
#define HDMI_PTG_L_MAX_COLOR_CTRL_mv_h_l(data)                        (0x00F00000&((data)<<20))
#define HDMI_PTG_L_MAX_COLOR_CTRL_mv_v_l(data)                        (0x000F0000&((data)<<16))
#define HDMI_PTG_L_MAX_COLOR_CTRL_mv_seq_type_l(data)                 (0x00008000&((data)<<15))
#define HDMI_PTG_L_MAX_COLOR_CTRL_rdm_period_l(data)                  (0x00007000&((data)<<12))
#define HDMI_PTG_L_MAX_COLOR_CTRL_mv_vs_num_l(data)                   (0x00000F00&((data)<<8))
#define HDMI_PTG_L_MAX_COLOR_CTRL_mp_adj_num_l(data)                  (0x000000FF&(data))
#define HDMI_PTG_L_MAX_COLOR_CTRL_get_dummy1800d548_31_27(data)       ((0xF8000000&(data))>>27)
#define HDMI_PTG_L_MAX_COLOR_CTRL_get_max_color_l(data)               ((0x07000000&(data))>>24)
#define HDMI_PTG_L_MAX_COLOR_CTRL_get_mv_h_l(data)                    ((0x00F00000&(data))>>20)
#define HDMI_PTG_L_MAX_COLOR_CTRL_get_mv_v_l(data)                    ((0x000F0000&(data))>>16)
#define HDMI_PTG_L_MAX_COLOR_CTRL_get_mv_seq_type_l(data)             ((0x00008000&(data))>>15)
#define HDMI_PTG_L_MAX_COLOR_CTRL_get_rdm_period_l(data)              ((0x00007000&(data))>>12)
#define HDMI_PTG_L_MAX_COLOR_CTRL_get_mv_vs_num_l(data)               ((0x00000F00&(data))>>8)
#define HDMI_PTG_L_MAX_COLOR_CTRL_get_mp_adj_num_l(data)              (0x000000FF&(data))


#define HDMI_PTG_R_CTRL                                               0x1800d550
#define HDMI_PTG_R_CTRL_reg_addr                                      "0xb800d550"
#define HDMI_PTG_R_CTRL_reg                                           0xb800d550
#define HDMI_PTG_R_CTRL_inst_addr                                     "0x0154"
#define HDMI_PTG_R_CTRL_inst                                          0x0154
#define HDMI_PTG_R_CTRL_en_rdm_bkg_r_shift                            (7)
#define HDMI_PTG_R_CTRL_xc_seq_r_shift                                (4)
#define HDMI_PTG_R_CTRL_en_xc_r_shift                                 (3)
#define HDMI_PTG_R_CTRL_pat_mode_r_shift                              (0)
#define HDMI_PTG_R_CTRL_en_rdm_bkg_r_mask                             (0x00000080)
#define HDMI_PTG_R_CTRL_xc_seq_r_mask                                 (0x00000070)
#define HDMI_PTG_R_CTRL_en_xc_r_mask                                  (0x00000008)
#define HDMI_PTG_R_CTRL_pat_mode_r_mask                               (0x00000007)
#define HDMI_PTG_R_CTRL_en_rdm_bkg_r(data)                            (0x00000080&((data)<<7))
#define HDMI_PTG_R_CTRL_xc_seq_r(data)                                (0x00000070&((data)<<4))
#define HDMI_PTG_R_CTRL_en_xc_r(data)                                 (0x00000008&((data)<<3))
#define HDMI_PTG_R_CTRL_pat_mode_r(data)                              (0x00000007&(data))
#define HDMI_PTG_R_CTRL_get_en_rdm_bkg_r(data)                        ((0x00000080&(data))>>7)
#define HDMI_PTG_R_CTRL_get_xc_seq_r(data)                            ((0x00000070&(data))>>4)
#define HDMI_PTG_R_CTRL_get_en_xc_r(data)                             ((0x00000008&(data))>>3)
#define HDMI_PTG_R_CTRL_get_pat_mode_r(data)                          (0x00000007&(data))


#define HDMI_PTG_R_BARW                                               0x1800d554
#define HDMI_PTG_R_BARW_reg_addr                                      "0xb800d554"
#define HDMI_PTG_R_BARW_reg                                           0xb800d554
#define HDMI_PTG_R_BARW_inst_addr                                     "0x0155"
#define HDMI_PTG_R_BARW_inst                                          0x0155
#define HDMI_PTG_R_BARW_auto_state_r_shift                            (14)
#define HDMI_PTG_R_BARW_hold_state_r_shift                            (12)
#define HDMI_PTG_R_BARW_hold_state_rdy_r_shift                        (11)
#define HDMI_PTG_R_BARW_barw_r_shift                                  (0)
#define HDMI_PTG_R_BARW_auto_state_r_mask                             (0x0000C000)
#define HDMI_PTG_R_BARW_hold_state_r_mask                             (0x00003000)
#define HDMI_PTG_R_BARW_hold_state_rdy_r_mask                         (0x00000800)
#define HDMI_PTG_R_BARW_barw_r_mask                                   (0x000007FF)
#define HDMI_PTG_R_BARW_auto_state_r(data)                            (0x0000C000&((data)<<14))
#define HDMI_PTG_R_BARW_hold_state_r(data)                            (0x00003000&((data)<<12))
#define HDMI_PTG_R_BARW_hold_state_rdy_r(data)                        (0x00000800&((data)<<11))
#define HDMI_PTG_R_BARW_barw_r(data)                                  (0x000007FF&(data))
#define HDMI_PTG_R_BARW_get_auto_state_r(data)                        ((0x0000C000&(data))>>14)
#define HDMI_PTG_R_BARW_get_hold_state_r(data)                        ((0x00003000&(data))>>12)
#define HDMI_PTG_R_BARW_get_hold_state_rdy_r(data)                    ((0x00000800&(data))>>11)
#define HDMI_PTG_R_BARW_get_barw_r(data)                              (0x000007FF&(data))


#define HDMI_PTG_R_C0Y_CB_CR                                          0x1800d558
#define HDMI_PTG_R_C0Y_CB_CR_reg_addr                                 "0xb800d558"
#define HDMI_PTG_R_C0Y_CB_CR_reg                                      0xb800d558
#define HDMI_PTG_R_C0Y_CB_CR_inst_addr                                "0x0156"
#define HDMI_PTG_R_C0Y_CB_CR_inst                                     0x0156
#define HDMI_PTG_R_C0Y_CB_CR_i_c0y_92b_r_shift                        (16)
#define HDMI_PTG_R_C0Y_CB_CR_i_c0cr_92b_r_shift                       (8)
#define HDMI_PTG_R_C0Y_CB_CR_i_c0cb_92b_r_shift                       (0)
#define HDMI_PTG_R_C0Y_CB_CR_i_c0y_92b_r_mask                         (0x00FF0000)
#define HDMI_PTG_R_C0Y_CB_CR_i_c0cr_92b_r_mask                        (0x0000FF00)
#define HDMI_PTG_R_C0Y_CB_CR_i_c0cb_92b_r_mask                        (0x000000FF)
#define HDMI_PTG_R_C0Y_CB_CR_i_c0y_92b_r(data)                        (0x00FF0000&((data)<<16))
#define HDMI_PTG_R_C0Y_CB_CR_i_c0cr_92b_r(data)                       (0x0000FF00&((data)<<8))
#define HDMI_PTG_R_C0Y_CB_CR_i_c0cb_92b_r(data)                       (0x000000FF&(data))
#define HDMI_PTG_R_C0Y_CB_CR_get_i_c0y_92b_r(data)                    ((0x00FF0000&(data))>>16)
#define HDMI_PTG_R_C0Y_CB_CR_get_i_c0cr_92b_r(data)                   ((0x0000FF00&(data))>>8)
#define HDMI_PTG_R_C0Y_CB_CR_get_i_c0cb_92b_r(data)                   (0x000000FF&(data))


#define HDMI_PTG_R_C1Y_CB_CR                                          0x1800d55c
#define HDMI_PTG_R_C1Y_CB_CR_reg_addr                                 "0xb800d55c"
#define HDMI_PTG_R_C1Y_CB_CR_reg                                      0xb800d55c
#define HDMI_PTG_R_C1Y_CB_CR_inst_addr                                "0x0157"
#define HDMI_PTG_R_C1Y_CB_CR_inst                                     0x0157
#define HDMI_PTG_R_C1Y_CB_CR_i_c1y_92b_r_shift                        (16)
#define HDMI_PTG_R_C1Y_CB_CR_i_c1cr_92b_r_shift                       (8)
#define HDMI_PTG_R_C1Y_CB_CR_i_c1cb_92b_r_shift                       (0)
#define HDMI_PTG_R_C1Y_CB_CR_i_c1y_92b_r_mask                         (0x00FF0000)
#define HDMI_PTG_R_C1Y_CB_CR_i_c1cr_92b_r_mask                        (0x0000FF00)
#define HDMI_PTG_R_C1Y_CB_CR_i_c1cb_92b_r_mask                        (0x000000FF)
#define HDMI_PTG_R_C1Y_CB_CR_i_c1y_92b_r(data)                        (0x00FF0000&((data)<<16))
#define HDMI_PTG_R_C1Y_CB_CR_i_c1cr_92b_r(data)                       (0x0000FF00&((data)<<8))
#define HDMI_PTG_R_C1Y_CB_CR_i_c1cb_92b_r(data)                       (0x000000FF&(data))
#define HDMI_PTG_R_C1Y_CB_CR_get_i_c1y_92b_r(data)                    ((0x00FF0000&(data))>>16)
#define HDMI_PTG_R_C1Y_CB_CR_get_i_c1cr_92b_r(data)                   ((0x0000FF00&(data))>>8)
#define HDMI_PTG_R_C1Y_CB_CR_get_i_c1cb_92b_r(data)                   (0x000000FF&(data))


#define HDMI_PTG_R_C2Y_CB_CR                                          0x1800d560
#define HDMI_PTG_R_C2Y_CB_CR_reg_addr                                 "0xb800d560"
#define HDMI_PTG_R_C2Y_CB_CR_reg                                      0xb800d560
#define HDMI_PTG_R_C2Y_CB_CR_inst_addr                                "0x0158"
#define HDMI_PTG_R_C2Y_CB_CR_inst                                     0x0158
#define HDMI_PTG_R_C2Y_CB_CR_i_c2y_92b_r_shift                        (16)
#define HDMI_PTG_R_C2Y_CB_CR_i_c2cr_92b_r_shift                       (8)
#define HDMI_PTG_R_C2Y_CB_CR_i_c2cb_92b_r_shift                       (0)
#define HDMI_PTG_R_C2Y_CB_CR_i_c2y_92b_r_mask                         (0x00FF0000)
#define HDMI_PTG_R_C2Y_CB_CR_i_c2cr_92b_r_mask                        (0x0000FF00)
#define HDMI_PTG_R_C2Y_CB_CR_i_c2cb_92b_r_mask                        (0x000000FF)
#define HDMI_PTG_R_C2Y_CB_CR_i_c2y_92b_r(data)                        (0x00FF0000&((data)<<16))
#define HDMI_PTG_R_C2Y_CB_CR_i_c2cr_92b_r(data)                       (0x0000FF00&((data)<<8))
#define HDMI_PTG_R_C2Y_CB_CR_i_c2cb_92b_r(data)                       (0x000000FF&(data))
#define HDMI_PTG_R_C2Y_CB_CR_get_i_c2y_92b_r(data)                    ((0x00FF0000&(data))>>16)
#define HDMI_PTG_R_C2Y_CB_CR_get_i_c2cr_92b_r(data)                   ((0x0000FF00&(data))>>8)
#define HDMI_PTG_R_C2Y_CB_CR_get_i_c2cb_92b_r(data)                   (0x000000FF&(data))


#define HDMI_PTG_R_C3Y_CB_CR                                          0x1800d564
#define HDMI_PTG_R_C3Y_CB_CR_reg_addr                                 "0xb800d564"
#define HDMI_PTG_R_C3Y_CB_CR_reg                                      0xb800d564
#define HDMI_PTG_R_C3Y_CB_CR_inst_addr                                "0x0159"
#define HDMI_PTG_R_C3Y_CB_CR_inst                                     0x0159
#define HDMI_PTG_R_C3Y_CB_CR_i_c3y_98b_r_shift                        (30)
#define HDMI_PTG_R_C3Y_CB_CR_i_c3y_72b_grady_r_shift                  (24)
#define HDMI_PTG_R_C3Y_CB_CR_i_c3cr_98b_r_shift                       (22)
#define HDMI_PTG_R_C3Y_CB_CR_i_c3cr_72b_gradcr_r_shift                (16)
#define HDMI_PTG_R_C3Y_CB_CR_i_c3cb_98b_r_shift                       (14)
#define HDMI_PTG_R_C3Y_CB_CR_i_c3cb_72b_gradcb_r_shift                (8)
#define HDMI_PTG_R_C3Y_CB_CR_dummy1800d564_7_0_shift                  (0)
#define HDMI_PTG_R_C3Y_CB_CR_i_c3y_98b_r_mask                         (0xC0000000)
#define HDMI_PTG_R_C3Y_CB_CR_i_c3y_72b_grady_r_mask                   (0x3F000000)
#define HDMI_PTG_R_C3Y_CB_CR_i_c3cr_98b_r_mask                        (0x00C00000)
#define HDMI_PTG_R_C3Y_CB_CR_i_c3cr_72b_gradcr_r_mask                 (0x003F0000)
#define HDMI_PTG_R_C3Y_CB_CR_i_c3cb_98b_r_mask                        (0x0000C000)
#define HDMI_PTG_R_C3Y_CB_CR_i_c3cb_72b_gradcb_r_mask                 (0x00003F00)
#define HDMI_PTG_R_C3Y_CB_CR_dummy1800d564_7_0_mask                   (0x000000FF)
#define HDMI_PTG_R_C3Y_CB_CR_i_c3y_98b_r(data)                        (0xC0000000&((data)<<30))
#define HDMI_PTG_R_C3Y_CB_CR_i_c3y_72b_grady_r(data)                  (0x3F000000&((data)<<24))
#define HDMI_PTG_R_C3Y_CB_CR_i_c3cr_98b_r(data)                       (0x00C00000&((data)<<22))
#define HDMI_PTG_R_C3Y_CB_CR_i_c3cr_72b_gradcr_r(data)                (0x003F0000&((data)<<16))
#define HDMI_PTG_R_C3Y_CB_CR_i_c3cb_98b_r(data)                       (0x0000C000&((data)<<14))
#define HDMI_PTG_R_C3Y_CB_CR_i_c3cb_72b_gradcb_r(data)                (0x00003F00&((data)<<8))
#define HDMI_PTG_R_C3Y_CB_CR_dummy1800d564_7_0(data)                  (0x000000FF&(data))
#define HDMI_PTG_R_C3Y_CB_CR_get_i_c3y_98b_r(data)                    ((0xC0000000&(data))>>30)
#define HDMI_PTG_R_C3Y_CB_CR_get_i_c3y_72b_grady_r(data)              ((0x3F000000&(data))>>24)
#define HDMI_PTG_R_C3Y_CB_CR_get_i_c3cr_98b_r(data)                   ((0x00C00000&(data))>>22)
#define HDMI_PTG_R_C3Y_CB_CR_get_i_c3cr_72b_gradcr_r(data)            ((0x003F0000&(data))>>16)
#define HDMI_PTG_R_C3Y_CB_CR_get_i_c3cb_98b_r(data)                   ((0x0000C000&(data))>>14)
#define HDMI_PTG_R_C3Y_CB_CR_get_i_c3cb_72b_gradcb_r(data)            ((0x00003F00&(data))>>8)
#define HDMI_PTG_R_C3Y_CB_CR_get_dummy1800d564_7_0(data)              (0x000000FF&(data))


#define HDMI_PTG_R_C4Y_CB_CR                                          0x1800d568
#define HDMI_PTG_R_C4Y_CB_CR_reg_addr                                 "0xb800d568"
#define HDMI_PTG_R_C4Y_CB_CR_reg                                      0xb800d568
#define HDMI_PTG_R_C4Y_CB_CR_inst_addr                                "0x015A"
#define HDMI_PTG_R_C4Y_CB_CR_inst                                     0x015A
#define HDMI_PTG_R_C4Y_CB_CR_i_c4y_96b_r_shift                        (28)
#define HDMI_PTG_R_C4Y_CB_CR_i_c4y_52b_step_hv_r_shift                (24)
#define HDMI_PTG_R_C4Y_CB_CR_i_c4cr_92b_r_shift                       (16)
#define HDMI_PTG_R_C4Y_CB_CR_i_c4cb_9b_r_shift                        (15)
#define HDMI_PTG_R_C4Y_CB_CR_i_c4cb_86b_bmp_w_r_shift                 (12)
#define HDMI_PTG_R_C4Y_CB_CR_i_c4cb_5b_r_shift                        (11)
#define HDMI_PTG_R_C4Y_CB_CR_i_c4cb_42b_bmp_h_r_shift                 (8)
#define HDMI_PTG_R_C4Y_CB_CR_i_c4y_96b_r_mask                         (0xF0000000)
#define HDMI_PTG_R_C4Y_CB_CR_i_c4y_52b_step_hv_r_mask                 (0x0F000000)
#define HDMI_PTG_R_C4Y_CB_CR_i_c4cr_92b_r_mask                        (0x00FF0000)
#define HDMI_PTG_R_C4Y_CB_CR_i_c4cb_9b_r_mask                         (0x00008000)
#define HDMI_PTG_R_C4Y_CB_CR_i_c4cb_86b_bmp_w_r_mask                  (0x00007000)
#define HDMI_PTG_R_C4Y_CB_CR_i_c4cb_5b_r_mask                         (0x00000800)
#define HDMI_PTG_R_C4Y_CB_CR_i_c4cb_42b_bmp_h_r_mask                  (0x00000700)
#define HDMI_PTG_R_C4Y_CB_CR_i_c4y_96b_r(data)                        (0xF0000000&((data)<<28))
#define HDMI_PTG_R_C4Y_CB_CR_i_c4y_52b_step_hv_r(data)                (0x0F000000&((data)<<24))
#define HDMI_PTG_R_C4Y_CB_CR_i_c4cr_92b_r(data)                       (0x00FF0000&((data)<<16))
#define HDMI_PTG_R_C4Y_CB_CR_i_c4cb_9b_r(data)                        (0x00008000&((data)<<15))
#define HDMI_PTG_R_C4Y_CB_CR_i_c4cb_86b_bmp_w_r(data)                 (0x00007000&((data)<<12))
#define HDMI_PTG_R_C4Y_CB_CR_i_c4cb_5b_r(data)                        (0x00000800&((data)<<11))
#define HDMI_PTG_R_C4Y_CB_CR_i_c4cb_42b_bmp_h_r(data)                 (0x00000700&((data)<<8))
#define HDMI_PTG_R_C4Y_CB_CR_get_i_c4y_96b_r(data)                    ((0xF0000000&(data))>>28)
#define HDMI_PTG_R_C4Y_CB_CR_get_i_c4y_52b_step_hv_r(data)            ((0x0F000000&(data))>>24)
#define HDMI_PTG_R_C4Y_CB_CR_get_i_c4cr_92b_r(data)                   ((0x00FF0000&(data))>>16)
#define HDMI_PTG_R_C4Y_CB_CR_get_i_c4cb_9b_r(data)                    ((0x00008000&(data))>>15)
#define HDMI_PTG_R_C4Y_CB_CR_get_i_c4cb_86b_bmp_w_r(data)             ((0x00007000&(data))>>12)
#define HDMI_PTG_R_C4Y_CB_CR_get_i_c4cb_5b_r(data)                    ((0x00000800&(data))>>11)
#define HDMI_PTG_R_C4Y_CB_CR_get_i_c4cb_42b_bmp_h_r(data)             ((0x00000700&(data))>>8)


#define HDMI_PTG_R_C5Y_CR_CB                                          0x1800d56c
#define HDMI_PTG_R_C5Y_CR_CB_reg_addr                                 "0xb800d56c"
#define HDMI_PTG_R_C5Y_CR_CB_reg                                      0xb800d56c
#define HDMI_PTG_R_C5Y_CR_CB_inst_addr                                "0x015B"
#define HDMI_PTG_R_C5Y_CR_CB_inst                                     0x015B
#define HDMI_PTG_R_C5Y_CR_CB_i_c5y_92b_bmptp_r_shift                  (24)
#define HDMI_PTG_R_C5Y_CR_CB_i_c5cr_92b_bmp0_r_shift                  (16)
#define HDMI_PTG_R_C5Y_CR_CB_i_c5cb_92b_bmp1_r_shift                  (8)
#define HDMI_PTG_R_C5Y_CR_CB_dummy1800d56c_7_0_shift                  (0)
#define HDMI_PTG_R_C5Y_CR_CB_i_c5y_92b_bmptp_r_mask                   (0xFF000000)
#define HDMI_PTG_R_C5Y_CR_CB_i_c5cr_92b_bmp0_r_mask                   (0x00FF0000)
#define HDMI_PTG_R_C5Y_CR_CB_i_c5cb_92b_bmp1_r_mask                   (0x0000FF00)
#define HDMI_PTG_R_C5Y_CR_CB_dummy1800d56c_7_0_mask                   (0x000000FF)
#define HDMI_PTG_R_C5Y_CR_CB_i_c5y_92b_bmptp_r(data)                  (0xFF000000&((data)<<24))
#define HDMI_PTG_R_C5Y_CR_CB_i_c5cr_92b_bmp0_r(data)                  (0x00FF0000&((data)<<16))
#define HDMI_PTG_R_C5Y_CR_CB_i_c5cb_92b_bmp1_r(data)                  (0x0000FF00&((data)<<8))
#define HDMI_PTG_R_C5Y_CR_CB_dummy1800d56c_7_0(data)                  (0x000000FF&(data))
#define HDMI_PTG_R_C5Y_CR_CB_get_i_c5y_92b_bmptp_r(data)              ((0xFF000000&(data))>>24)
#define HDMI_PTG_R_C5Y_CR_CB_get_i_c5cr_92b_bmp0_r(data)              ((0x00FF0000&(data))>>16)
#define HDMI_PTG_R_C5Y_CR_CB_get_i_c5cb_92b_bmp1_r(data)              ((0x0000FF00&(data))>>8)
#define HDMI_PTG_R_C5Y_CR_CB_get_dummy1800d56c_7_0(data)              (0x000000FF&(data))


#define HDMI_PTG_R_C6Y_CB_CR                                          0x1800d570
#define HDMI_PTG_R_C6Y_CB_CR_reg_addr                                 "0xb800d570"
#define HDMI_PTG_R_C6Y_CB_CR_reg                                      0xb800d570
#define HDMI_PTG_R_C6Y_CB_CR_inst_addr                                "0x015C"
#define HDMI_PTG_R_C6Y_CB_CR_inst                                     0x015C
#define HDMI_PTG_R_C6Y_CB_CR_i_c6y_92b_bmp2_r_shift                   (24)
#define HDMI_PTG_R_C6Y_CB_CR_i_c6cr_92b_bmp3_r_shift                  (16)
#define HDMI_PTG_R_C6Y_CB_CR_i_c6cb_92b_bmp4_r_shift                  (8)
#define HDMI_PTG_R_C6Y_CB_CR_nonactive_color_def_r_shift              (0)
#define HDMI_PTG_R_C6Y_CB_CR_i_c6y_92b_bmp2_r_mask                    (0xFF000000)
#define HDMI_PTG_R_C6Y_CB_CR_i_c6cr_92b_bmp3_r_mask                   (0x00FF0000)
#define HDMI_PTG_R_C6Y_CB_CR_i_c6cb_92b_bmp4_r_mask                   (0x0000FF00)
#define HDMI_PTG_R_C6Y_CB_CR_nonactive_color_def_r_mask               (0x000000FF)
#define HDMI_PTG_R_C6Y_CB_CR_i_c6y_92b_bmp2_r(data)                   (0xFF000000&((data)<<24))
#define HDMI_PTG_R_C6Y_CB_CR_i_c6cr_92b_bmp3_r(data)                  (0x00FF0000&((data)<<16))
#define HDMI_PTG_R_C6Y_CB_CR_i_c6cb_92b_bmp4_r(data)                  (0x0000FF00&((data)<<8))
#define HDMI_PTG_R_C6Y_CB_CR_nonactive_color_def_r(data)              (0x000000FF&(data))
#define HDMI_PTG_R_C6Y_CB_CR_get_i_c6y_92b_bmp2_r(data)               ((0xFF000000&(data))>>24)
#define HDMI_PTG_R_C6Y_CB_CR_get_i_c6cr_92b_bmp3_r(data)              ((0x00FF0000&(data))>>16)
#define HDMI_PTG_R_C6Y_CB_CR_get_i_c6cb_92b_bmp4_r(data)              ((0x0000FF00&(data))>>8)
#define HDMI_PTG_R_C6Y_CB_CR_get_nonactive_color_def_r(data)          (0x000000FF&(data))


#define HDMI_PTG_R_C7Y_CB_CR                                          0x1800d574
#define HDMI_PTG_R_C7Y_CB_CR_reg_addr                                 "0xb800d574"
#define HDMI_PTG_R_C7Y_CB_CR_reg                                      0xb800d574
#define HDMI_PTG_R_C7Y_CB_CR_inst_addr                                "0x015D"
#define HDMI_PTG_R_C7Y_CB_CR_inst                                     0x015D
#define HDMI_PTG_R_C7Y_CB_CR_i_c7y_92b_bmp5_r_shift                   (24)
#define HDMI_PTG_R_C7Y_CB_CR_i_c7cr_92b_bmp6_r_shift                  (16)
#define HDMI_PTG_R_C7Y_CB_CR_i_c7cb_92b_bmp7_r_shift                  (8)
#define HDMI_PTG_R_C7Y_CB_CR_dummy1800d574_7_0_shift                  (0)
#define HDMI_PTG_R_C7Y_CB_CR_i_c7y_92b_bmp5_r_mask                    (0xFF000000)
#define HDMI_PTG_R_C7Y_CB_CR_i_c7cr_92b_bmp6_r_mask                   (0x00FF0000)
#define HDMI_PTG_R_C7Y_CB_CR_i_c7cb_92b_bmp7_r_mask                   (0x0000FF00)
#define HDMI_PTG_R_C7Y_CB_CR_dummy1800d574_7_0_mask                   (0x000000FF)
#define HDMI_PTG_R_C7Y_CB_CR_i_c7y_92b_bmp5_r(data)                   (0xFF000000&((data)<<24))
#define HDMI_PTG_R_C7Y_CB_CR_i_c7cr_92b_bmp6_r(data)                  (0x00FF0000&((data)<<16))
#define HDMI_PTG_R_C7Y_CB_CR_i_c7cb_92b_bmp7_r(data)                  (0x0000FF00&((data)<<8))
#define HDMI_PTG_R_C7Y_CB_CR_dummy1800d574_7_0(data)                  (0x000000FF&(data))
#define HDMI_PTG_R_C7Y_CB_CR_get_i_c7y_92b_bmp5_r(data)               ((0xFF000000&(data))>>24)
#define HDMI_PTG_R_C7Y_CB_CR_get_i_c7cr_92b_bmp6_r(data)              ((0x00FF0000&(data))>>16)
#define HDMI_PTG_R_C7Y_CB_CR_get_i_c7cb_92b_bmp7_r(data)              ((0x0000FF00&(data))>>8)
#define HDMI_PTG_R_C7Y_CB_CR_get_dummy1800d574_7_0(data)              (0x000000FF&(data))


#define HDMI_PTG_R_MAX_COLOR_CTRL                                     0x1800d578
#define HDMI_PTG_R_MAX_COLOR_CTRL_reg_addr                            "0xb800d578"
#define HDMI_PTG_R_MAX_COLOR_CTRL_reg                                 0xb800d578
#define HDMI_PTG_R_MAX_COLOR_CTRL_inst_addr                           "0x015E"
#define HDMI_PTG_R_MAX_COLOR_CTRL_inst                                0x015E
#define HDMI_PTG_R_MAX_COLOR_CTRL_dummy1800d578_31_27_shift           (27)
#define HDMI_PTG_R_MAX_COLOR_CTRL_max_color_r_shift                   (24)
#define HDMI_PTG_R_MAX_COLOR_CTRL_mv_h_r_shift                        (20)
#define HDMI_PTG_R_MAX_COLOR_CTRL_mv_v_r_shift                        (16)
#define HDMI_PTG_R_MAX_COLOR_CTRL_mv_seq_type_r_shift                 (15)
#define HDMI_PTG_R_MAX_COLOR_CTRL_rdm_period_r_shift                  (12)
#define HDMI_PTG_R_MAX_COLOR_CTRL_mv_vs_num_r_shift                   (8)
#define HDMI_PTG_R_MAX_COLOR_CTRL_mp_adj_num_r_shift                  (0)
#define HDMI_PTG_R_MAX_COLOR_CTRL_dummy1800d578_31_27_mask            (0xF8000000)
#define HDMI_PTG_R_MAX_COLOR_CTRL_max_color_r_mask                    (0x07000000)
#define HDMI_PTG_R_MAX_COLOR_CTRL_mv_h_r_mask                         (0x00F00000)
#define HDMI_PTG_R_MAX_COLOR_CTRL_mv_v_r_mask                         (0x000F0000)
#define HDMI_PTG_R_MAX_COLOR_CTRL_mv_seq_type_r_mask                  (0x00008000)
#define HDMI_PTG_R_MAX_COLOR_CTRL_rdm_period_r_mask                   (0x00007000)
#define HDMI_PTG_R_MAX_COLOR_CTRL_mv_vs_num_r_mask                    (0x00000F00)
#define HDMI_PTG_R_MAX_COLOR_CTRL_mp_adj_num_r_mask                   (0x000000FF)
#define HDMI_PTG_R_MAX_COLOR_CTRL_dummy1800d578_31_27(data)           (0xF8000000&((data)<<27))
#define HDMI_PTG_R_MAX_COLOR_CTRL_max_color_r(data)                   (0x07000000&((data)<<24))
#define HDMI_PTG_R_MAX_COLOR_CTRL_mv_h_r(data)                        (0x00F00000&((data)<<20))
#define HDMI_PTG_R_MAX_COLOR_CTRL_mv_v_r(data)                        (0x000F0000&((data)<<16))
#define HDMI_PTG_R_MAX_COLOR_CTRL_mv_seq_type_r(data)                 (0x00008000&((data)<<15))
#define HDMI_PTG_R_MAX_COLOR_CTRL_rdm_period_r(data)                  (0x00007000&((data)<<12))
#define HDMI_PTG_R_MAX_COLOR_CTRL_mv_vs_num_r(data)                   (0x00000F00&((data)<<8))
#define HDMI_PTG_R_MAX_COLOR_CTRL_mp_adj_num_r(data)                  (0x000000FF&(data))
#define HDMI_PTG_R_MAX_COLOR_CTRL_get_dummy1800d578_31_27(data)       ((0xF8000000&(data))>>27)
#define HDMI_PTG_R_MAX_COLOR_CTRL_get_max_color_r(data)               ((0x07000000&(data))>>24)
#define HDMI_PTG_R_MAX_COLOR_CTRL_get_mv_h_r(data)                    ((0x00F00000&(data))>>20)
#define HDMI_PTG_R_MAX_COLOR_CTRL_get_mv_v_r(data)                    ((0x000F0000&(data))>>16)
#define HDMI_PTG_R_MAX_COLOR_CTRL_get_mv_seq_type_r(data)             ((0x00008000&(data))>>15)
#define HDMI_PTG_R_MAX_COLOR_CTRL_get_rdm_period_r(data)              ((0x00007000&(data))>>12)
#define HDMI_PTG_R_MAX_COLOR_CTRL_get_mv_vs_num_r(data)               ((0x00000F00&(data))>>8)
#define HDMI_PTG_R_MAX_COLOR_CTRL_get_mp_adj_num_r(data)              (0x000000FF&(data))


#define HDMI_CTS_FIFO_CTL                                             0x1800d580
#define HDMI_CTS_FIFO_CTL_reg_addr                                    "0xb800d580"
#define HDMI_CTS_FIFO_CTL_reg                                         0xb800d580
#define HDMI_CTS_FIFO_CTL_inst_addr                                   "0x0160"
#define HDMI_CTS_FIFO_CTL_inst                                        0x0160
#define HDMI_CTS_FIFO_CTL_hdmi_test_sel_shift                         (4)
#define HDMI_CTS_FIFO_CTL_hdmi_out_sel_shift                          (3)
#define HDMI_CTS_FIFO_CTL_force_ctsfifo_rstn_hdmi_shift               (2)
#define HDMI_CTS_FIFO_CTL_en_ctsfifo_vsrst_hdmi_shift                 (1)
#define HDMI_CTS_FIFO_CTL_en_ctsfifo_bypass_hdmi_shift                (0)
#define HDMI_CTS_FIFO_CTL_hdmi_test_sel_mask                          (0x00000070)
#define HDMI_CTS_FIFO_CTL_hdmi_out_sel_mask                           (0x00000008)
#define HDMI_CTS_FIFO_CTL_force_ctsfifo_rstn_hdmi_mask                (0x00000004)
#define HDMI_CTS_FIFO_CTL_en_ctsfifo_vsrst_hdmi_mask                  (0x00000002)
#define HDMI_CTS_FIFO_CTL_en_ctsfifo_bypass_hdmi_mask                 (0x00000001)
#define HDMI_CTS_FIFO_CTL_hdmi_test_sel(data)                         (0x00000070&((data)<<4))
#define HDMI_CTS_FIFO_CTL_hdmi_out_sel(data)                          (0x00000008&((data)<<3))
#define HDMI_CTS_FIFO_CTL_force_ctsfifo_rstn_hdmi(data)               (0x00000004&((data)<<2))
#define HDMI_CTS_FIFO_CTL_en_ctsfifo_vsrst_hdmi(data)                 (0x00000002&((data)<<1))
#define HDMI_CTS_FIFO_CTL_en_ctsfifo_bypass_hdmi(data)                (0x00000001&(data))
#define HDMI_CTS_FIFO_CTL_get_hdmi_test_sel(data)                     ((0x00000070&(data))>>4)
#define HDMI_CTS_FIFO_CTL_get_hdmi_out_sel(data)                      ((0x00000008&(data))>>3)
#define HDMI_CTS_FIFO_CTL_get_force_ctsfifo_rstn_hdmi(data)           ((0x00000004&(data))>>2)
#define HDMI_CTS_FIFO_CTL_get_en_ctsfifo_vsrst_hdmi(data)             ((0x00000002&(data))>>1)
#define HDMI_CTS_FIFO_CTL_get_en_ctsfifo_bypass_hdmi(data)            (0x00000001&(data))
#endif

