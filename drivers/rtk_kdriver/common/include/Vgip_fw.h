// This file is generated using the spec version 1.39, firmware template version 1.39and SRIF Parser                                                                                source code SVN rev:802                    Version flow no.:1.1.68
#ifndef _VGIP_REG_H_INCLUDED_
#define _VGIP_REG_H_INCLUDED_

//#define  _VGIP_USE_STRUCT
#ifdef _VGIP_USE_STRUCT

typedef struct
{
    unsigned int    reserved_0:29;
    unsigned int    imd_smooth_toggle_style:2;
    unsigned int    imd_smooth_toggle_apply:1;
}SMOOTH_tog_ctrl;

typedef struct
{
    unsigned int    reserved_0:27;
    unsigned int    vo_reg_is_db:1;
    unsigned int    vgip_reg_is_db:1;
    unsigned int    di_reg_is_db:1;
    unsigned int    i_edge_smooth_is_db:1;
    unsigned int    uzd_reg_is_db:1;
}SMOOTH_tog_status;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    v8_dummy:8;
    unsigned int    dummy18022208_7_1:7;
    unsigned int    ch1_select_duplicate_lsb:1;
}V8_ctrl;

typedef struct
{
    unsigned int    auto_l_flag_delay_en:1;
    unsigned int    reserved_0:2;
    unsigned int    auto_l_flag_delay_num:13;
    unsigned int    l_flag_delay_en:1;
    unsigned int    reserved_1:2;
    unsigned int    l_flag_delay_num:13;
}VGIP_global_ctrl;

typedef struct
{
    unsigned int    ch1_ivrun:1;
    unsigned int    ch1_in_sel:3;
    unsigned int    ch1_random_en:1;
    unsigned int    ch1_fdrop_en:1;
    unsigned int    ch1_vact_end_ie:1;
    unsigned int    ch1_vact_start_ie:1;
    unsigned int    ch1_field_hs_inv:1;
    unsigned int    ch1_odd_vd_inv:1;
    unsigned int    ch1_odd_vd_en:1;
    unsigned int    ch1_3dleft_inv:1;
    unsigned int    ch1_3dleft_sync_edge:1;
    unsigned int    ch1_odd_inv:1;
    unsigned int    ch1_odd_sync_edge:1;
    unsigned int    ch1_odd_det_en:1;
    unsigned int    ch1_hpact_is_hact:1;
    unsigned int    ch1_fcap_str_odd:1;
    unsigned int    ch1_mask_den_inv:1;
    unsigned int    ch1_mask_den_1l:1;
    unsigned int    ch1_3d_mode_en:1;
    unsigned int    ch1_safe_odd_inv:1;
    unsigned int    ch1_force_tog:1;
    unsigned int    ch1_safe_mode:1;
    unsigned int    ch1_3d_right_act_en:1;
    unsigned int    ch1_hs_syncedge:1;
    unsigned int    ch1_vs_syncedge:1;
    unsigned int    ch1_vs_by_hs_en_n:1;
    unsigned int    ch1_vs_inv:1;
    unsigned int    ch1_hs_inv:1;
    unsigned int    ch1_digital_mode:1;
    unsigned int    ch1_in_clk_en:1;
}VGIP_chn1_ctrl;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    ch1_vs_end:1;
    unsigned int    ch1_vs_start:1;
    unsigned int    ch1_vact_end:1;
    unsigned int    ch1_vact_start:1;
    unsigned int    dummy18022214_23_18:6;
    unsigned int    reserved_1:1;
    unsigned int    ch1_vlc_status:1;
    unsigned int    ch1_rl_err:1;
    unsigned int    ch1_vs_err:1;
    unsigned int    ch1_hs_err:1;
    unsigned int    ch1_field_err:1;
    unsigned int    ch1_rl_tog:1;
    unsigned int    ch1_l_flag_pol:1;
    unsigned int    ch1_vs_tog:1;
    unsigned int    ch1_hs_tog:1;
    unsigned int    ch1_field_pol:1;
    unsigned int    ch1_field_tog:1;
    unsigned int    ch1_field_vs_lsb:2;
    unsigned int    ch1_more_1line_field:1;
    unsigned int    ch1_bounce_status_2:1;
    unsigned int    ch1_bounce_status_1:1;
    unsigned int    ch1_bounce_status_0:1;
}VGIP_chn1_status;

typedef struct
{
    unsigned int    ch1_db_rdy:1;
    unsigned int    ch1_db_en:1;
    unsigned int    ch1_ih_act_sta:14;
    unsigned int    reserved_0:2;
    unsigned int    ch1_ih_act_wid:14;
}VGIP_chn1_act_hsta_width;

typedef struct
{
    unsigned int    reserved_0:3;
    unsigned int    ch1_iv_act_sta:13;
    unsigned int    reserved_1:3;
    unsigned int    ch1_iv_act_len:13;
}VGIP_chn1_act_vsta_length;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    ch1_ihs_dly:14;
    unsigned int    reserved_1:3;
    unsigned int    ch1_ivs_dly:13;
}VGIP_chn1_delay;

typedef struct
{
    unsigned int    ch1_de_mask_en:1;
    unsigned int    reserved_0:9;
    unsigned int    l_flag_force_tog:1;
    unsigned int    ch1_hporch_num:13;
    unsigned int    ch1_auto_ihs_dly:2;
    unsigned int    ch1_auto_ivs_dly:2;
    unsigned int    ch1_hdly_one:1;
    unsigned int    ch1_v1_v2_swap:1;
    unsigned int    ch1_v2_v3_swap:1;
    unsigned int    ch1_v1_v3_swap:1;
}VGIP_chn1_misc;

typedef struct
{
    unsigned int    ch1_captst_en:1;
    unsigned int    ch1_captst_mode:1;
    unsigned int    reserved_0:1;
    unsigned int    ch1_vcaptst_num:13;
    unsigned int    reserved_1:2;
    unsigned int    ch1_hcaptst_num:14;
}VGIP_chn1_ptn_h_vi;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    ch1_captst_r_data:12;
    unsigned int    reserved_1:4;
    unsigned int    ch1_captst_g_data:12;
}VGIP_chn1_ptn0;

typedef struct
{
    unsigned int    reserved_0:20;
    unsigned int    ch1_captst_b_data:12;
}VGIP_chn1_ptn1;

typedef struct
{
    unsigned int    ch1_vlcen:1;
    unsigned int    ch1_vlc_mode:1;
    unsigned int    ch1_vlc_ie:1;
    unsigned int    den_crc_sel:1;
    unsigned int    reserved_0:4;
    unsigned int    ch1_line_cnt:12;
    unsigned int    ch1_vln:12;
}VGIP_chn1_lc;

typedef struct
{
    unsigned int    reserved_0:26;
    unsigned int    ch1_crc_region:1;
    unsigned int    ch1_crc_ctrl_in:1;
    unsigned int    ch1_crc_field_edge_sel:1;
    unsigned int    ch1_crc_field:1;
    unsigned int    ch1_crc_conti:1;
    unsigned int    ch1_crc_start:1;
}ICH1_vgip_crc_ctrl;

typedef struct
{
    unsigned int    ch1_crc_result:32;
}ICH1_vgip_crc_result;

typedef struct
{
    unsigned int    ch1_wd_to_main:1;
    unsigned int    ch1_wd_to_sub:1;
    unsigned int    dummy18022240_29_19:11;
    unsigned int    ch1_vs_err_wde:1;
    unsigned int    ch1_hs_err_wde:1;
    unsigned int    ch1_field_err_wde:1;
    unsigned int    ch1_rl_err_wde:1;
    unsigned int    dummy18022240_14_4:11;
    unsigned int    ch1_rl_err_ie:1;
    unsigned int    ch1_vs_err_ie:1;
    unsigned int    ch1_hs_err_ie:1;
    unsigned int    ch1_field_err_ie:1;
}VGIP_chn1_wde;

typedef struct
{
    unsigned int    adc_test_dma_count:28;
    unsigned int    reserved_0:1;
    unsigned int    force_den:1;
    unsigned int    force_vsync:1;
    unsigned int    adc_test_dma_mode:1;
}ADC_raw_data_dma;

typedef struct
{
    unsigned int    reserved_0:3;
    unsigned int    vs_width:13;
    unsigned int    reserved_1:2;
    unsigned int    frame_packing_en:1;
    unsigned int    vs_position:13;
}FRAMEPACKING_ctrl1;

typedef struct
{
    unsigned int    reserved_0:3;
    unsigned int    den_mask_start:13;
    unsigned int    reserved_1:3;
    unsigned int    den_mask_end:13;
}FRAMEPACKING_ctrl2;

typedef struct
{
    unsigned int    reserved_0:26;
    unsigned int    fsync_ch_sel:1;
    unsigned int    adc_ch_sel:1;
    unsigned int    xcdi_clk_en:1;
    unsigned int    uzd1_in_sel:1;
    unsigned int    uzd2_in_sel:1;
    unsigned int    xcdi_in_sel:1;
}DATA_path_select;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    vbisli_in_sel:1;
    unsigned int    vbisli_ivs_dly:13;
    unsigned int    reserved_1:2;
    unsigned int    vbisli_ihs_dly:14;
}VGIP_vbisli;

typedef struct
{
    unsigned int    reserved_0:22;
    unsigned int    onms3_int_ie:1;
    unsigned int    offms_int_ie:1;
    unsigned int    onms2_int_ie:1;
    unsigned int    onms1_int_ie:1;
    unsigned int    hist_ch1_int_ie:1;
    unsigned int    hist_ch2_int_ie:1;
    unsigned int    vgip_int_ie:1;
    unsigned int    reserved_1:1;
    unsigned int    reserved_2:1;
    unsigned int    dispi_int_ie:1;
}INT_ctl;

typedef struct
{
    unsigned int    reserved_0:20;
    unsigned int    dummy_ctsfifo_sdnr:1;
    unsigned int    force_ctsfifo_rstn_sdnr:1;
    unsigned int    en_ctsfifo_vsrst_sdnr:1;
    unsigned int    en_ctsfifo_bypass_sdnr:1;
    unsigned int    reserved_1:4;
    unsigned int    dummy_ctsfifo_vgip:1;
    unsigned int    force_ctsfifo_rstn_vgip:1;
    unsigned int    en_ctsfifo_vsrst_vgip:1;
    unsigned int    en_ctsfifo_bypass_vgip:1;
}CTS_fifo_ctl;

typedef struct
{
    unsigned int    reserved_0:26;
    unsigned int    disp_testpinsel:6;
}DISPI_test_sel;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    ch1_3d_right_ih_act_sta:14;
    unsigned int    reserved_1:2;
    unsigned int    ch1_3d_right_ih_act_wid:14;
}VGIP_chn1_3d_right_act_hsta_width;

typedef struct
{
    unsigned int    reserved_0:3;
    unsigned int    ch1_3d_right_iv_act_sta:13;
    unsigned int    reserved_1:3;
    unsigned int    ch1_3d_right_iv_act_len:13;
}VGIP_chn1_3d_right_act_vsta_length;

typedef struct
{
    unsigned int    reserved_0:3;
    unsigned int    vs_width_r_odd:13;
    unsigned int    reserved_1:2;
    unsigned int    frame_packing_field_en:1;
    unsigned int    vs_position_r_odd:13;
}FRAMEPACKING_interlace_ctrl1;

typedef struct
{
    unsigned int    reserved_0:3;
    unsigned int    den_mask_start_r_odd:13;
    unsigned int    reserved_1:3;
    unsigned int    den_mask_end_r_odd:13;
}FRAMEPACKING_interlace_ctrl2;

typedef struct
{
    unsigned int    reserved_0:3;
    unsigned int    vs_width_r_even:13;
    unsigned int    reserved_1:3;
    unsigned int    vs_position_r_even:13;
}FRAMEPACKING_interlace_ctrl3;

typedef struct
{
    unsigned int    reserved_0:3;
    unsigned int    den_mask_start_r_even:13;
    unsigned int    reserved_1:3;
    unsigned int    den_mask_end_r_even:13;
}FRAMEPACKING_interlace_ctrl4;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    end_l:14;
    unsigned int    reserved_1:2;
    unsigned int    sta_l:14;
}L_r_active_enable_ctrl1;

typedef struct
{
    unsigned int    l_r_act_en:1;
    unsigned int    h_v_mode:1;
    unsigned int    end_r:14;
    unsigned int    reserved_0:2;
    unsigned int    sta_r:14;
}L_r_active_enable_ctrl2;
#endif


#define SMOOTH_TOG_CTRL                                               0x18022200
#define SMOOTH_TOG_CTRL_reg_addr                                      "0xb8022200"
#define SMOOTH_TOG_CTRL_reg                                           0xb8022200
#define SMOOTH_TOG_CTRL_inst_addr                                     "0x0080"
#define SMOOTH_TOG_CTRL_inst                                          0x0080
#define SMOOTH_TOG_CTRL_imd_smooth_toggle_style_shift                 (1)
#define SMOOTH_TOG_CTRL_imd_smooth_toggle_apply_shift                 (0)
#define SMOOTH_TOG_CTRL_imd_smooth_toggle_style_mask                  (0x00000006)
#define SMOOTH_TOG_CTRL_imd_smooth_toggle_apply_mask                  (0x00000001)
#define SMOOTH_TOG_CTRL_imd_smooth_toggle_style(data)                 (0x00000006&((data)<<1))
#define SMOOTH_TOG_CTRL_imd_smooth_toggle_apply(data)                 (0x00000001&(data))
#define SMOOTH_TOG_CTRL_get_imd_smooth_toggle_style(data)             ((0x00000006&(data))>>1)
#define SMOOTH_TOG_CTRL_get_imd_smooth_toggle_apply(data)             (0x00000001&(data))


#define SMOOTH_TOG_STATUS                                             0x18022204
#define SMOOTH_TOG_STATUS_reg_addr                                    "0xb8022204"
#define SMOOTH_TOG_STATUS_reg                                         0xb8022204
#define SMOOTH_TOG_STATUS_inst_addr                                   "0x0081"
#define SMOOTH_TOG_STATUS_inst                                        0x0081
#define SMOOTH_TOG_STATUS_vo_reg_is_db_shift                          (4)
#define SMOOTH_TOG_STATUS_vgip_reg_is_db_shift                        (3)
#define SMOOTH_TOG_STATUS_di_reg_is_db_shift                          (2)
#define SMOOTH_TOG_STATUS_i_edge_smooth_is_db_shift                   (1)
#define SMOOTH_TOG_STATUS_uzd_reg_is_db_shift                         (0)
#define SMOOTH_TOG_STATUS_vo_reg_is_db_mask                           (0x00000010)
#define SMOOTH_TOG_STATUS_vgip_reg_is_db_mask                         (0x00000008)
#define SMOOTH_TOG_STATUS_di_reg_is_db_mask                           (0x00000004)
#define SMOOTH_TOG_STATUS_i_edge_smooth_is_db_mask                    (0x00000002)
#define SMOOTH_TOG_STATUS_uzd_reg_is_db_mask                          (0x00000001)
#define SMOOTH_TOG_STATUS_vo_reg_is_db(data)                          (0x00000010&((data)<<4))
#define SMOOTH_TOG_STATUS_vgip_reg_is_db(data)                        (0x00000008&((data)<<3))
#define SMOOTH_TOG_STATUS_di_reg_is_db(data)                          (0x00000004&((data)<<2))
#define SMOOTH_TOG_STATUS_i_edge_smooth_is_db(data)                   (0x00000002&((data)<<1))
#define SMOOTH_TOG_STATUS_uzd_reg_is_db(data)                         (0x00000001&(data))
#define SMOOTH_TOG_STATUS_get_vo_reg_is_db(data)                      ((0x00000010&(data))>>4)
#define SMOOTH_TOG_STATUS_get_vgip_reg_is_db(data)                    ((0x00000008&(data))>>3)
#define SMOOTH_TOG_STATUS_get_di_reg_is_db(data)                      ((0x00000004&(data))>>2)
#define SMOOTH_TOG_STATUS_get_i_edge_smooth_is_db(data)               ((0x00000002&(data))>>1)
#define SMOOTH_TOG_STATUS_get_uzd_reg_is_db(data)                     (0x00000001&(data))


#define V8_CTRL                                                       0x18022208
#define V8_CTRL_reg_addr                                              "0xb8022208"
#define V8_CTRL_reg                                                   0xb8022208
#define V8_CTRL_inst_addr                                             "0x0082"
#define V8_CTRL_inst                                                  0x0082
#define V8_CTRL_v8_dummy_shift                                        (8)
#define V8_CTRL_dummy18022208_7_1_shift                               (1)
#define V8_CTRL_ch1_select_duplicate_lsb_shift                        (0)
#define V8_CTRL_v8_dummy_mask                                         (0x0000FF00)
#define V8_CTRL_dummy18022208_7_1_mask                                (0x000000FE)
#define V8_CTRL_ch1_select_duplicate_lsb_mask                         (0x00000001)
#define V8_CTRL_v8_dummy(data)                                        (0x0000FF00&((data)<<8))
#define V8_CTRL_dummy18022208_7_1(data)                               (0x000000FE&((data)<<1))
#define V8_CTRL_ch1_select_duplicate_lsb(data)                        (0x00000001&(data))
#define V8_CTRL_get_v8_dummy(data)                                    ((0x0000FF00&(data))>>8)
#define V8_CTRL_get_dummy18022208_7_1(data)                           ((0x000000FE&(data))>>1)
#define V8_CTRL_get_ch1_select_duplicate_lsb(data)                    (0x00000001&(data))


#define VGIP_GLOBAL_CTRL                                              0x1802220c
#define VGIP_GLOBAL_CTRL_reg_addr                                     "0xb802220c"
#define VGIP_GLOBAL_CTRL_reg                                          0xb802220c
#define VGIP_GLOBAL_CTRL_inst_addr                                    "0x0083"
#define VGIP_GLOBAL_CTRL_inst                                         0x0083
#define VGIP_GLOBAL_CTRL_auto_l_flag_delay_en_shift                   (31)
#define VGIP_GLOBAL_CTRL_auto_l_flag_delay_num_shift                  (16)
#define VGIP_GLOBAL_CTRL_l_flag_delay_en_shift                        (15)
#define VGIP_GLOBAL_CTRL_l_flag_delay_num_shift                       (0)
#define VGIP_GLOBAL_CTRL_auto_l_flag_delay_en_mask                    (0x80000000)
#define VGIP_GLOBAL_CTRL_auto_l_flag_delay_num_mask                   (0x1FFF0000)
#define VGIP_GLOBAL_CTRL_l_flag_delay_en_mask                         (0x00008000)
#define VGIP_GLOBAL_CTRL_l_flag_delay_num_mask                        (0x00001FFF)
#define VGIP_GLOBAL_CTRL_auto_l_flag_delay_en(data)                   (0x80000000&((data)<<31))
#define VGIP_GLOBAL_CTRL_auto_l_flag_delay_num(data)                  (0x1FFF0000&((data)<<16))
#define VGIP_GLOBAL_CTRL_l_flag_delay_en(data)                        (0x00008000&((data)<<15))
#define VGIP_GLOBAL_CTRL_l_flag_delay_num(data)                       (0x00001FFF&(data))
#define VGIP_GLOBAL_CTRL_get_auto_l_flag_delay_en(data)               ((0x80000000&(data))>>31)
#define VGIP_GLOBAL_CTRL_get_auto_l_flag_delay_num(data)              ((0x1FFF0000&(data))>>16)
#define VGIP_GLOBAL_CTRL_get_l_flag_delay_en(data)                    ((0x00008000&(data))>>15)
#define VGIP_GLOBAL_CTRL_get_l_flag_delay_num(data)                   (0x00001FFF&(data))


#define VGIP_CHN1_CTRL                                                0x18022210
#define VGIP_CHN1_CTRL_reg_addr                                       "0xb8022210"
#define VGIP_CHN1_CTRL_reg                                            0xb8022210
#define VGIP_CHN1_CTRL_inst_addr                                      "0x0084"
#define VGIP_CHN1_CTRL_inst                                           0x0084
#define VGIP_CHN1_CTRL_ch1_ivrun_shift                                (31)
#define VGIP_CHN1_CTRL_ch1_in_sel_shift                               (28)
#define VGIP_CHN1_CTRL_ch1_random_en_shift                            (27)
#define VGIP_CHN1_CTRL_ch1_fdrop_en_shift                             (26)
#define VGIP_CHN1_CTRL_ch1_vact_end_ie_shift                          (25)
#define VGIP_CHN1_CTRL_ch1_vact_start_ie_shift                        (24)
#define VGIP_CHN1_CTRL_ch1_field_hs_inv_shift                         (23)
#define VGIP_CHN1_CTRL_ch1_odd_vd_inv_shift                           (22)
#define VGIP_CHN1_CTRL_ch1_odd_vd_en_shift                            (21)
#define VGIP_CHN1_CTRL_ch1_3dleft_inv_shift                           (20)
#define VGIP_CHN1_CTRL_ch1_3dleft_sync_edge_shift                     (19)
#define VGIP_CHN1_CTRL_ch1_odd_inv_shift                              (18)
#define VGIP_CHN1_CTRL_ch1_odd_sync_edge_shift                        (17)
#define VGIP_CHN1_CTRL_ch1_odd_det_en_shift                           (16)
#define VGIP_CHN1_CTRL_ch1_hpact_is_hact_shift                        (15)
#define VGIP_CHN1_CTRL_ch1_fcap_str_odd_shift                         (14)
#define VGIP_CHN1_CTRL_ch1_mask_den_inv_shift                         (13)
#define VGIP_CHN1_CTRL_ch1_mask_den_1l_shift                          (12)
#define VGIP_CHN1_CTRL_ch1_3d_mode_en_shift                           (11)
#define VGIP_CHN1_CTRL_ch1_safe_odd_inv_shift                         (10)
#define VGIP_CHN1_CTRL_ch1_force_tog_shift                            (9)
#define VGIP_CHN1_CTRL_ch1_safe_mode_shift                            (8)
#define VGIP_CHN1_CTRL_ch1_3d_right_act_en_shift                      (7)
#define VGIP_CHN1_CTRL_ch1_hs_syncedge_shift                          (6)
#define VGIP_CHN1_CTRL_ch1_vs_syncedge_shift                          (5)
#define VGIP_CHN1_CTRL_ch1_vs_by_hs_en_n_shift                        (4)
#define VGIP_CHN1_CTRL_ch1_vs_inv_shift                               (3)
#define VGIP_CHN1_CTRL_ch1_hs_inv_shift                               (2)
#define VGIP_CHN1_CTRL_ch1_digital_mode_shift                         (1)
#define VGIP_CHN1_CTRL_ch1_in_clk_en_shift                            (0)
#define VGIP_CHN1_CTRL_ch1_ivrun_mask                                 (0x80000000)
#define VGIP_CHN1_CTRL_ch1_in_sel_mask                                (0x70000000)
#define VGIP_CHN1_CTRL_ch1_random_en_mask                             (0x08000000)
#define VGIP_CHN1_CTRL_ch1_fdrop_en_mask                              (0x04000000)
#define VGIP_CHN1_CTRL_ch1_vact_end_ie_mask                           (0x02000000)
#define VGIP_CHN1_CTRL_ch1_vact_start_ie_mask                         (0x01000000)
#define VGIP_CHN1_CTRL_ch1_field_hs_inv_mask                          (0x00800000)
#define VGIP_CHN1_CTRL_ch1_odd_vd_inv_mask                            (0x00400000)
#define VGIP_CHN1_CTRL_ch1_odd_vd_en_mask                             (0x00200000)
#define VGIP_CHN1_CTRL_ch1_3dleft_inv_mask                            (0x00100000)
#define VGIP_CHN1_CTRL_ch1_3dleft_sync_edge_mask                      (0x00080000)
#define VGIP_CHN1_CTRL_ch1_odd_inv_mask                               (0x00040000)
#define VGIP_CHN1_CTRL_ch1_odd_sync_edge_mask                         (0x00020000)
#define VGIP_CHN1_CTRL_ch1_odd_det_en_mask                            (0x00010000)
#define VGIP_CHN1_CTRL_ch1_hpact_is_hact_mask                         (0x00008000)
#define VGIP_CHN1_CTRL_ch1_fcap_str_odd_mask                          (0x00004000)
#define VGIP_CHN1_CTRL_ch1_mask_den_inv_mask                          (0x00002000)
#define VGIP_CHN1_CTRL_ch1_mask_den_1l_mask                           (0x00001000)
#define VGIP_CHN1_CTRL_ch1_3d_mode_en_mask                            (0x00000800)
#define VGIP_CHN1_CTRL_ch1_safe_odd_inv_mask                          (0x00000400)
#define VGIP_CHN1_CTRL_ch1_force_tog_mask                             (0x00000200)
#define VGIP_CHN1_CTRL_ch1_safe_mode_mask                             (0x00000100)
#define VGIP_CHN1_CTRL_ch1_3d_right_act_en_mask                       (0x00000080)
#define VGIP_CHN1_CTRL_ch1_hs_syncedge_mask                           (0x00000040)
#define VGIP_CHN1_CTRL_ch1_vs_syncedge_mask                           (0x00000020)
#define VGIP_CHN1_CTRL_ch1_vs_by_hs_en_n_mask                         (0x00000010)
#define VGIP_CHN1_CTRL_ch1_vs_inv_mask                                (0x00000008)
#define VGIP_CHN1_CTRL_ch1_hs_inv_mask                                (0x00000004)
#define VGIP_CHN1_CTRL_ch1_digital_mode_mask                          (0x00000002)
#define VGIP_CHN1_CTRL_ch1_in_clk_en_mask                             (0x00000001)
#define VGIP_CHN1_CTRL_ch1_ivrun(data)                                (0x80000000&((data)<<31))
#define VGIP_CHN1_CTRL_ch1_in_sel(data)                               (0x70000000&((data)<<28))
#define VGIP_CHN1_CTRL_ch1_random_en(data)                            (0x08000000&((data)<<27))
#define VGIP_CHN1_CTRL_ch1_fdrop_en(data)                             (0x04000000&((data)<<26))
#define VGIP_CHN1_CTRL_ch1_vact_end_ie(data)                          (0x02000000&((data)<<25))
#define VGIP_CHN1_CTRL_ch1_vact_start_ie(data)                        (0x01000000&((data)<<24))
#define VGIP_CHN1_CTRL_ch1_field_hs_inv(data)                         (0x00800000&((data)<<23))
#define VGIP_CHN1_CTRL_ch1_odd_vd_inv(data)                           (0x00400000&((data)<<22))
#define VGIP_CHN1_CTRL_ch1_odd_vd_en(data)                            (0x00200000&((data)<<21))
#define VGIP_CHN1_CTRL_ch1_3dleft_inv(data)                           (0x00100000&((data)<<20))
#define VGIP_CHN1_CTRL_ch1_3dleft_sync_edge(data)                     (0x00080000&((data)<<19))
#define VGIP_CHN1_CTRL_ch1_odd_inv(data)                              (0x00040000&((data)<<18))
#define VGIP_CHN1_CTRL_ch1_odd_sync_edge(data)                        (0x00020000&((data)<<17))
#define VGIP_CHN1_CTRL_ch1_odd_det_en(data)                           (0x00010000&((data)<<16))
#define VGIP_CHN1_CTRL_ch1_hpact_is_hact(data)                        (0x00008000&((data)<<15))
#define VGIP_CHN1_CTRL_ch1_fcap_str_odd(data)                         (0x00004000&((data)<<14))
#define VGIP_CHN1_CTRL_ch1_mask_den_inv(data)                         (0x00002000&((data)<<13))
#define VGIP_CHN1_CTRL_ch1_mask_den_1l(data)                          (0x00001000&((data)<<12))
#define VGIP_CHN1_CTRL_ch1_3d_mode_en(data)                           (0x00000800&((data)<<11))
#define VGIP_CHN1_CTRL_ch1_safe_odd_inv(data)                         (0x00000400&((data)<<10))
#define VGIP_CHN1_CTRL_ch1_force_tog(data)                            (0x00000200&((data)<<9))
#define VGIP_CHN1_CTRL_ch1_safe_mode(data)                            (0x00000100&((data)<<8))
#define VGIP_CHN1_CTRL_ch1_3d_right_act_en(data)                      (0x00000080&((data)<<7))
#define VGIP_CHN1_CTRL_ch1_hs_syncedge(data)                          (0x00000040&((data)<<6))
#define VGIP_CHN1_CTRL_ch1_vs_syncedge(data)                          (0x00000020&((data)<<5))
#define VGIP_CHN1_CTRL_ch1_vs_by_hs_en_n(data)                        (0x00000010&((data)<<4))
#define VGIP_CHN1_CTRL_ch1_vs_inv(data)                               (0x00000008&((data)<<3))
#define VGIP_CHN1_CTRL_ch1_hs_inv(data)                               (0x00000004&((data)<<2))
#define VGIP_CHN1_CTRL_ch1_digital_mode(data)                         (0x00000002&((data)<<1))
#define VGIP_CHN1_CTRL_ch1_in_clk_en(data)                            (0x00000001&(data))
#define VGIP_CHN1_CTRL_get_ch1_ivrun(data)                            ((0x80000000&(data))>>31)
#define VGIP_CHN1_CTRL_get_ch1_in_sel(data)                           ((0x70000000&(data))>>28)
#define VGIP_CHN1_CTRL_get_ch1_random_en(data)                        ((0x08000000&(data))>>27)
#define VGIP_CHN1_CTRL_get_ch1_fdrop_en(data)                         ((0x04000000&(data))>>26)
#define VGIP_CHN1_CTRL_get_ch1_vact_end_ie(data)                      ((0x02000000&(data))>>25)
#define VGIP_CHN1_CTRL_get_ch1_vact_start_ie(data)                    ((0x01000000&(data))>>24)
#define VGIP_CHN1_CTRL_get_ch1_field_hs_inv(data)                     ((0x00800000&(data))>>23)
#define VGIP_CHN1_CTRL_get_ch1_odd_vd_inv(data)                       ((0x00400000&(data))>>22)
#define VGIP_CHN1_CTRL_get_ch1_odd_vd_en(data)                        ((0x00200000&(data))>>21)
#define VGIP_CHN1_CTRL_get_ch1_3dleft_inv(data)                       ((0x00100000&(data))>>20)
#define VGIP_CHN1_CTRL_get_ch1_3dleft_sync_edge(data)                 ((0x00080000&(data))>>19)
#define VGIP_CHN1_CTRL_get_ch1_odd_inv(data)                          ((0x00040000&(data))>>18)
#define VGIP_CHN1_CTRL_get_ch1_odd_sync_edge(data)                    ((0x00020000&(data))>>17)
#define VGIP_CHN1_CTRL_get_ch1_odd_det_en(data)                       ((0x00010000&(data))>>16)
#define VGIP_CHN1_CTRL_get_ch1_hpact_is_hact(data)                    ((0x00008000&(data))>>15)
#define VGIP_CHN1_CTRL_get_ch1_fcap_str_odd(data)                     ((0x00004000&(data))>>14)
#define VGIP_CHN1_CTRL_get_ch1_mask_den_inv(data)                     ((0x00002000&(data))>>13)
#define VGIP_CHN1_CTRL_get_ch1_mask_den_1l(data)                      ((0x00001000&(data))>>12)
#define VGIP_CHN1_CTRL_get_ch1_3d_mode_en(data)                       ((0x00000800&(data))>>11)
#define VGIP_CHN1_CTRL_get_ch1_safe_odd_inv(data)                     ((0x00000400&(data))>>10)
#define VGIP_CHN1_CTRL_get_ch1_force_tog(data)                        ((0x00000200&(data))>>9)
#define VGIP_CHN1_CTRL_get_ch1_safe_mode(data)                        ((0x00000100&(data))>>8)
#define VGIP_CHN1_CTRL_get_ch1_3d_right_act_en(data)                  ((0x00000080&(data))>>7)
#define VGIP_CHN1_CTRL_get_ch1_hs_syncedge(data)                      ((0x00000040&(data))>>6)
#define VGIP_CHN1_CTRL_get_ch1_vs_syncedge(data)                      ((0x00000020&(data))>>5)
#define VGIP_CHN1_CTRL_get_ch1_vs_by_hs_en_n(data)                    ((0x00000010&(data))>>4)
#define VGIP_CHN1_CTRL_get_ch1_vs_inv(data)                           ((0x00000008&(data))>>3)
#define VGIP_CHN1_CTRL_get_ch1_hs_inv(data)                           ((0x00000004&(data))>>2)
#define VGIP_CHN1_CTRL_get_ch1_digital_mode(data)                     ((0x00000002&(data))>>1)
#define VGIP_CHN1_CTRL_get_ch1_in_clk_en(data)                        (0x00000001&(data))


#define VGIP_CHN1_STATUS                                              0x18022214
#define VGIP_CHN1_STATUS_reg_addr                                     "0xb8022214"
#define VGIP_CHN1_STATUS_reg                                          0xb8022214
#define VGIP_CHN1_STATUS_inst_addr                                    "0x0085"
#define VGIP_CHN1_STATUS_inst                                         0x0085
#define VGIP_CHN1_STATUS_ch1_vs_end_shift                             (27)
#define VGIP_CHN1_STATUS_ch1_vs_start_shift                           (26)
#define VGIP_CHN1_STATUS_ch1_vact_end_shift                           (25)
#define VGIP_CHN1_STATUS_ch1_vact_start_shift                         (24)
#define VGIP_CHN1_STATUS_dummy18022214_23_18_shift                    (18)
#define VGIP_CHN1_STATUS_ch1_vlc_status_shift                         (16)
#define VGIP_CHN1_STATUS_ch1_rl_err_shift                             (15)
#define VGIP_CHN1_STATUS_ch1_vs_err_shift                             (14)
#define VGIP_CHN1_STATUS_ch1_hs_err_shift                             (13)
#define VGIP_CHN1_STATUS_ch1_field_err_shift                          (12)
#define VGIP_CHN1_STATUS_ch1_rl_tog_shift                             (11)
#define VGIP_CHN1_STATUS_ch1_l_flag_pol_shift                         (10)
#define VGIP_CHN1_STATUS_ch1_vs_tog_shift                             (9)
#define VGIP_CHN1_STATUS_ch1_hs_tog_shift                             (8)
#define VGIP_CHN1_STATUS_ch1_field_pol_shift                          (7)
#define VGIP_CHN1_STATUS_ch1_field_tog_shift                          (6)
#define VGIP_CHN1_STATUS_ch1_field_vs_lsb_shift                       (4)
#define VGIP_CHN1_STATUS_ch1_more_1line_field_shift                   (3)
#define VGIP_CHN1_STATUS_ch1_bounce_status_2_shift                    (2)
#define VGIP_CHN1_STATUS_ch1_bounce_status_1_shift                    (1)
#define VGIP_CHN1_STATUS_ch1_bounce_status_0_shift                    (0)
#define VGIP_CHN1_STATUS_ch1_vs_end_mask                              (0x08000000)
#define VGIP_CHN1_STATUS_ch1_vs_start_mask                            (0x04000000)
#define VGIP_CHN1_STATUS_ch1_vact_end_mask                            (0x02000000)
#define VGIP_CHN1_STATUS_ch1_vact_start_mask                          (0x01000000)
#define VGIP_CHN1_STATUS_dummy18022214_23_18_mask                     (0x00FC0000)
#define VGIP_CHN1_STATUS_ch1_vlc_status_mask                          (0x00010000)
#define VGIP_CHN1_STATUS_ch1_rl_err_mask                              (0x00008000)
#define VGIP_CHN1_STATUS_ch1_vs_err_mask                              (0x00004000)
#define VGIP_CHN1_STATUS_ch1_hs_err_mask                              (0x00002000)
#define VGIP_CHN1_STATUS_ch1_field_err_mask                           (0x00001000)
#define VGIP_CHN1_STATUS_ch1_rl_tog_mask                              (0x00000800)
#define VGIP_CHN1_STATUS_ch1_l_flag_pol_mask                          (0x00000400)
#define VGIP_CHN1_STATUS_ch1_vs_tog_mask                              (0x00000200)
#define VGIP_CHN1_STATUS_ch1_hs_tog_mask                              (0x00000100)
#define VGIP_CHN1_STATUS_ch1_field_pol_mask                           (0x00000080)
#define VGIP_CHN1_STATUS_ch1_field_tog_mask                           (0x00000040)
#define VGIP_CHN1_STATUS_ch1_field_vs_lsb_mask                        (0x00000030)
#define VGIP_CHN1_STATUS_ch1_more_1line_field_mask                    (0x00000008)
#define VGIP_CHN1_STATUS_ch1_bounce_status_2_mask                     (0x00000004)
#define VGIP_CHN1_STATUS_ch1_bounce_status_1_mask                     (0x00000002)
#define VGIP_CHN1_STATUS_ch1_bounce_status_0_mask                     (0x00000001)
#define VGIP_CHN1_STATUS_ch1_vs_end(data)                             (0x08000000&((data)<<27))
#define VGIP_CHN1_STATUS_ch1_vs_start(data)                           (0x04000000&((data)<<26))
#define VGIP_CHN1_STATUS_ch1_vact_end(data)                           (0x02000000&((data)<<25))
#define VGIP_CHN1_STATUS_ch1_vact_start(data)                         (0x01000000&((data)<<24))
#define VGIP_CHN1_STATUS_dummy18022214_23_18(data)                    (0x00FC0000&((data)<<18))
#define VGIP_CHN1_STATUS_ch1_vlc_status(data)                         (0x00010000&((data)<<16))
#define VGIP_CHN1_STATUS_ch1_rl_err(data)                             (0x00008000&((data)<<15))
#define VGIP_CHN1_STATUS_ch1_vs_err(data)                             (0x00004000&((data)<<14))
#define VGIP_CHN1_STATUS_ch1_hs_err(data)                             (0x00002000&((data)<<13))
#define VGIP_CHN1_STATUS_ch1_field_err(data)                          (0x00001000&((data)<<12))
#define VGIP_CHN1_STATUS_ch1_rl_tog(data)                             (0x00000800&((data)<<11))
#define VGIP_CHN1_STATUS_ch1_l_flag_pol(data)                         (0x00000400&((data)<<10))
#define VGIP_CHN1_STATUS_ch1_vs_tog(data)                             (0x00000200&((data)<<9))
#define VGIP_CHN1_STATUS_ch1_hs_tog(data)                             (0x00000100&((data)<<8))
#define VGIP_CHN1_STATUS_ch1_field_pol(data)                          (0x00000080&((data)<<7))
#define VGIP_CHN1_STATUS_ch1_field_tog(data)                          (0x00000040&((data)<<6))
#define VGIP_CHN1_STATUS_ch1_field_vs_lsb(data)                       (0x00000030&((data)<<4))
#define VGIP_CHN1_STATUS_ch1_more_1line_field(data)                   (0x00000008&((data)<<3))
#define VGIP_CHN1_STATUS_ch1_bounce_status_2(data)                    (0x00000004&((data)<<2))
#define VGIP_CHN1_STATUS_ch1_bounce_status_1(data)                    (0x00000002&((data)<<1))
#define VGIP_CHN1_STATUS_ch1_bounce_status_0(data)                    (0x00000001&(data))
#define VGIP_CHN1_STATUS_get_ch1_vs_end(data)                         ((0x08000000&(data))>>27)
#define VGIP_CHN1_STATUS_get_ch1_vs_start(data)                       ((0x04000000&(data))>>26)
#define VGIP_CHN1_STATUS_get_ch1_vact_end(data)                       ((0x02000000&(data))>>25)
#define VGIP_CHN1_STATUS_get_ch1_vact_start(data)                     ((0x01000000&(data))>>24)
#define VGIP_CHN1_STATUS_get_dummy18022214_23_18(data)                ((0x00FC0000&(data))>>18)
#define VGIP_CHN1_STATUS_get_ch1_vlc_status(data)                     ((0x00010000&(data))>>16)
#define VGIP_CHN1_STATUS_get_ch1_rl_err(data)                         ((0x00008000&(data))>>15)
#define VGIP_CHN1_STATUS_get_ch1_vs_err(data)                         ((0x00004000&(data))>>14)
#define VGIP_CHN1_STATUS_get_ch1_hs_err(data)                         ((0x00002000&(data))>>13)
#define VGIP_CHN1_STATUS_get_ch1_field_err(data)                      ((0x00001000&(data))>>12)
#define VGIP_CHN1_STATUS_get_ch1_rl_tog(data)                         ((0x00000800&(data))>>11)
#define VGIP_CHN1_STATUS_get_ch1_l_flag_pol(data)                     ((0x00000400&(data))>>10)
#define VGIP_CHN1_STATUS_get_ch1_vs_tog(data)                         ((0x00000200&(data))>>9)
#define VGIP_CHN1_STATUS_get_ch1_hs_tog(data)                         ((0x00000100&(data))>>8)
#define VGIP_CHN1_STATUS_get_ch1_field_pol(data)                      ((0x00000080&(data))>>7)
#define VGIP_CHN1_STATUS_get_ch1_field_tog(data)                      ((0x00000040&(data))>>6)
#define VGIP_CHN1_STATUS_get_ch1_field_vs_lsb(data)                   ((0x00000030&(data))>>4)
#define VGIP_CHN1_STATUS_get_ch1_more_1line_field(data)               ((0x00000008&(data))>>3)
#define VGIP_CHN1_STATUS_get_ch1_bounce_status_2(data)                ((0x00000004&(data))>>2)
#define VGIP_CHN1_STATUS_get_ch1_bounce_status_1(data)                ((0x00000002&(data))>>1)
#define VGIP_CHN1_STATUS_get_ch1_bounce_status_0(data)                (0x00000001&(data))


#define VGIP_CHN1_ACT_HSTA_WIDTH                                      0x18022218
#define VGIP_CHN1_ACT_HSTA_WIDTH_reg_addr                             "0xb8022218"
#define VGIP_CHN1_ACT_HSTA_WIDTH_reg                                  0xb8022218
#define VGIP_CHN1_ACT_HSTA_WIDTH_inst_addr                            "0x0086"
#define VGIP_CHN1_ACT_HSTA_WIDTH_inst                                 0x0086
#define VGIP_CHN1_ACT_HSTA_WIDTH_ch1_db_rdy_shift                     (31)
#define VGIP_CHN1_ACT_HSTA_WIDTH_ch1_db_en_shift                      (30)
#define VGIP_CHN1_ACT_HSTA_WIDTH_ch1_ih_act_sta_shift                 (16)
#define VGIP_CHN1_ACT_HSTA_WIDTH_ch1_ih_act_wid_shift                 (0)
#define VGIP_CHN1_ACT_HSTA_WIDTH_ch1_db_rdy_mask                      (0x80000000)
#define VGIP_CHN1_ACT_HSTA_WIDTH_ch1_db_en_mask                       (0x40000000)
#define VGIP_CHN1_ACT_HSTA_WIDTH_ch1_ih_act_sta_mask                  (0x3FFF0000)
#define VGIP_CHN1_ACT_HSTA_WIDTH_ch1_ih_act_wid_mask                  (0x00003FFF)
#define VGIP_CHN1_ACT_HSTA_WIDTH_ch1_db_rdy(data)                     (0x80000000&((data)<<31))
#define VGIP_CHN1_ACT_HSTA_WIDTH_ch1_db_en(data)                      (0x40000000&((data)<<30))
#define VGIP_CHN1_ACT_HSTA_WIDTH_ch1_ih_act_sta(data)                 (0x3FFF0000&((data)<<16))
#define VGIP_CHN1_ACT_HSTA_WIDTH_ch1_ih_act_wid(data)                 (0x00003FFF&(data))
#define VGIP_CHN1_ACT_HSTA_WIDTH_get_ch1_db_rdy(data)                 ((0x80000000&(data))>>31)
#define VGIP_CHN1_ACT_HSTA_WIDTH_get_ch1_db_en(data)                  ((0x40000000&(data))>>30)
#define VGIP_CHN1_ACT_HSTA_WIDTH_get_ch1_ih_act_sta(data)             ((0x3FFF0000&(data))>>16)
#define VGIP_CHN1_ACT_HSTA_WIDTH_get_ch1_ih_act_wid(data)             (0x00003FFF&(data))


#define VGIP_CHN1_ACT_VSTA_LENGTH                                     0x1802221c
#define VGIP_CHN1_ACT_VSTA_LENGTH_reg_addr                            "0xb802221c"
#define VGIP_CHN1_ACT_VSTA_LENGTH_reg                                 0xb802221c
#define VGIP_CHN1_ACT_VSTA_LENGTH_inst_addr                           "0x0087"
#define VGIP_CHN1_ACT_VSTA_LENGTH_inst                                0x0087
#define VGIP_CHN1_ACT_VSTA_LENGTH_ch1_iv_act_sta_shift                (16)
#define VGIP_CHN1_ACT_VSTA_LENGTH_ch1_iv_act_len_shift                (0)
#define VGIP_CHN1_ACT_VSTA_LENGTH_ch1_iv_act_sta_mask                 (0x1FFF0000)
#define VGIP_CHN1_ACT_VSTA_LENGTH_ch1_iv_act_len_mask                 (0x00001FFF)
#define VGIP_CHN1_ACT_VSTA_LENGTH_ch1_iv_act_sta(data)                (0x1FFF0000&((data)<<16))
#define VGIP_CHN1_ACT_VSTA_LENGTH_ch1_iv_act_len(data)                (0x00001FFF&(data))
#define VGIP_CHN1_ACT_VSTA_LENGTH_get_ch1_iv_act_sta(data)            ((0x1FFF0000&(data))>>16)
#define VGIP_CHN1_ACT_VSTA_LENGTH_get_ch1_iv_act_len(data)            (0x00001FFF&(data))


#define VGIP_CHN1_DELAY                                               0x18022220
#define VGIP_CHN1_DELAY_reg_addr                                      "0xb8022220"
#define VGIP_CHN1_DELAY_reg                                           0xb8022220
#define VGIP_CHN1_DELAY_inst_addr                                     "0x0088"
#define VGIP_CHN1_DELAY_inst                                          0x0088
#define VGIP_CHN1_DELAY_ch1_ihs_dly_shift                             (16)
#define VGIP_CHN1_DELAY_ch1_ivs_dly_shift                             (0)
#define VGIP_CHN1_DELAY_ch1_ihs_dly_mask                              (0x3FFF0000)
#define VGIP_CHN1_DELAY_ch1_ivs_dly_mask                              (0x00001FFF)
#define VGIP_CHN1_DELAY_ch1_ihs_dly(data)                             (0x3FFF0000&((data)<<16))
#define VGIP_CHN1_DELAY_ch1_ivs_dly(data)                             (0x00001FFF&(data))
#define VGIP_CHN1_DELAY_get_ch1_ihs_dly(data)                         ((0x3FFF0000&(data))>>16)
#define VGIP_CHN1_DELAY_get_ch1_ivs_dly(data)                         (0x00001FFF&(data))


#define VGIP_CHN1_MISC                                                0x18022224
#define VGIP_CHN1_MISC_reg_addr                                       "0xb8022224"
#define VGIP_CHN1_MISC_reg                                            0xb8022224
#define VGIP_CHN1_MISC_inst_addr                                      "0x0089"
#define VGIP_CHN1_MISC_inst                                           0x0089
#define VGIP_CHN1_MISC_ch1_de_mask_en_shift                           (31)
#define VGIP_CHN1_MISC_l_flag_force_tog_shift                         (21)
#define VGIP_CHN1_MISC_ch1_hporch_num_shift                           (8)
#define VGIP_CHN1_MISC_ch1_auto_ihs_dly_shift                         (6)
#define VGIP_CHN1_MISC_ch1_auto_ivs_dly_shift                         (4)
#define VGIP_CHN1_MISC_ch1_hdly_one_shift                             (3)
#define VGIP_CHN1_MISC_ch1_v1_v2_swap_shift                           (2)
#define VGIP_CHN1_MISC_ch1_v2_v3_swap_shift                           (1)
#define VGIP_CHN1_MISC_ch1_v1_v3_swap_shift                           (0)
#define VGIP_CHN1_MISC_ch1_de_mask_en_mask                            (0x80000000)
#define VGIP_CHN1_MISC_l_flag_force_tog_mask                          (0x00200000)
#define VGIP_CHN1_MISC_ch1_hporch_num_mask                            (0x001FFF00)
#define VGIP_CHN1_MISC_ch1_auto_ihs_dly_mask                          (0x000000C0)
#define VGIP_CHN1_MISC_ch1_auto_ivs_dly_mask                          (0x00000030)
#define VGIP_CHN1_MISC_ch1_hdly_one_mask                              (0x00000008)
#define VGIP_CHN1_MISC_ch1_v1_v2_swap_mask                            (0x00000004)
#define VGIP_CHN1_MISC_ch1_v2_v3_swap_mask                            (0x00000002)
#define VGIP_CHN1_MISC_ch1_v1_v3_swap_mask                            (0x00000001)
#define VGIP_CHN1_MISC_ch1_de_mask_en(data)                           (0x80000000&((data)<<31))
#define VGIP_CHN1_MISC_l_flag_force_tog(data)                         (0x00200000&((data)<<21))
#define VGIP_CHN1_MISC_ch1_hporch_num(data)                           (0x001FFF00&((data)<<8))
#define VGIP_CHN1_MISC_ch1_auto_ihs_dly(data)                         (0x000000C0&((data)<<6))
#define VGIP_CHN1_MISC_ch1_auto_ivs_dly(data)                         (0x00000030&((data)<<4))
#define VGIP_CHN1_MISC_ch1_hdly_one(data)                             (0x00000008&((data)<<3))
#define VGIP_CHN1_MISC_ch1_v1_v2_swap(data)                           (0x00000004&((data)<<2))
#define VGIP_CHN1_MISC_ch1_v2_v3_swap(data)                           (0x00000002&((data)<<1))
#define VGIP_CHN1_MISC_ch1_v1_v3_swap(data)                           (0x00000001&(data))
#define VGIP_CHN1_MISC_get_ch1_de_mask_en(data)                       ((0x80000000&(data))>>31)
#define VGIP_CHN1_MISC_get_l_flag_force_tog(data)                     ((0x00200000&(data))>>21)
#define VGIP_CHN1_MISC_get_ch1_hporch_num(data)                       ((0x001FFF00&(data))>>8)
#define VGIP_CHN1_MISC_get_ch1_auto_ihs_dly(data)                     ((0x000000C0&(data))>>6)
#define VGIP_CHN1_MISC_get_ch1_auto_ivs_dly(data)                     ((0x00000030&(data))>>4)
#define VGIP_CHN1_MISC_get_ch1_hdly_one(data)                         ((0x00000008&(data))>>3)
#define VGIP_CHN1_MISC_get_ch1_v1_v2_swap(data)                       ((0x00000004&(data))>>2)
#define VGIP_CHN1_MISC_get_ch1_v2_v3_swap(data)                       ((0x00000002&(data))>>1)
#define VGIP_CHN1_MISC_get_ch1_v1_v3_swap(data)                       (0x00000001&(data))


#define VGIP_CHN1_PTN_H_VI                                            0x18022228
#define VGIP_CHN1_PTN_H_VI_reg_addr                                   "0xb8022228"
#define VGIP_CHN1_PTN_H_VI_reg                                        0xb8022228
#define VGIP_CHN1_PTN_H_VI_inst_addr                                  "0x008A"
#define VGIP_CHN1_PTN_H_VI_inst                                       0x008A
#define VGIP_CHN1_PTN_H_VI_ch1_captst_en_shift                        (31)
#define VGIP_CHN1_PTN_H_VI_ch1_captst_mode_shift                      (30)
#define VGIP_CHN1_PTN_H_VI_ch1_vcaptst_num_shift                      (16)
#define VGIP_CHN1_PTN_H_VI_ch1_hcaptst_num_shift                      (0)
#define VGIP_CHN1_PTN_H_VI_ch1_captst_en_mask                         (0x80000000)
#define VGIP_CHN1_PTN_H_VI_ch1_captst_mode_mask                       (0x40000000)
#define VGIP_CHN1_PTN_H_VI_ch1_vcaptst_num_mask                       (0x1FFF0000)
#define VGIP_CHN1_PTN_H_VI_ch1_hcaptst_num_mask                       (0x00003FFF)
#define VGIP_CHN1_PTN_H_VI_ch1_captst_en(data)                        (0x80000000&((data)<<31))
#define VGIP_CHN1_PTN_H_VI_ch1_captst_mode(data)                      (0x40000000&((data)<<30))
#define VGIP_CHN1_PTN_H_VI_ch1_vcaptst_num(data)                      (0x1FFF0000&((data)<<16))
#define VGIP_CHN1_PTN_H_VI_ch1_hcaptst_num(data)                      (0x00003FFF&(data))
#define VGIP_CHN1_PTN_H_VI_get_ch1_captst_en(data)                    ((0x80000000&(data))>>31)
#define VGIP_CHN1_PTN_H_VI_get_ch1_captst_mode(data)                  ((0x40000000&(data))>>30)
#define VGIP_CHN1_PTN_H_VI_get_ch1_vcaptst_num(data)                  ((0x1FFF0000&(data))>>16)
#define VGIP_CHN1_PTN_H_VI_get_ch1_hcaptst_num(data)                  (0x00003FFF&(data))


#define VGIP_CHN1_PTN0                                                0x1802222c
#define VGIP_CHN1_PTN0_reg_addr                                       "0xb802222c"
#define VGIP_CHN1_PTN0_reg                                            0xb802222c
#define VGIP_CHN1_PTN0_inst_addr                                      "0x008B"
#define VGIP_CHN1_PTN0_inst                                           0x008B
#define VGIP_CHN1_PTN0_ch1_captst_r_data_shift                        (16)
#define VGIP_CHN1_PTN0_ch1_captst_g_data_shift                        (0)
#define VGIP_CHN1_PTN0_ch1_captst_r_data_mask                         (0x0FFF0000)
#define VGIP_CHN1_PTN0_ch1_captst_g_data_mask                         (0x00000FFF)
#define VGIP_CHN1_PTN0_ch1_captst_r_data(data)                        (0x0FFF0000&((data)<<16))
#define VGIP_CHN1_PTN0_ch1_captst_g_data(data)                        (0x00000FFF&(data))
#define VGIP_CHN1_PTN0_get_ch1_captst_r_data(data)                    ((0x0FFF0000&(data))>>16)
#define VGIP_CHN1_PTN0_get_ch1_captst_g_data(data)                    (0x00000FFF&(data))


#define VGIP_CHN1_PTN1                                                0x18022230
#define VGIP_CHN1_PTN1_reg_addr                                       "0xb8022230"
#define VGIP_CHN1_PTN1_reg                                            0xb8022230
#define VGIP_CHN1_PTN1_inst_addr                                      "0x008C"
#define VGIP_CHN1_PTN1_inst                                           0x008C
#define VGIP_CHN1_PTN1_ch1_captst_b_data_shift                        (0)
#define VGIP_CHN1_PTN1_ch1_captst_b_data_mask                         (0x00000FFF)
#define VGIP_CHN1_PTN1_ch1_captst_b_data(data)                        (0x00000FFF&(data))
#define VGIP_CHN1_PTN1_get_ch1_captst_b_data(data)                    (0x00000FFF&(data))


#define VGIP_CHN1_LC                                                  0x18022234
#define VGIP_CHN1_LC_reg_addr                                         "0xb8022234"
#define VGIP_CHN1_LC_reg                                              0xb8022234
#define VGIP_CHN1_LC_inst_addr                                        "0x008D"
#define VGIP_CHN1_LC_inst                                             0x008D
#define VGIP_CHN1_LC_ch1_vlcen_shift                                  (31)
#define VGIP_CHN1_LC_ch1_vlc_mode_shift                               (30)
#define VGIP_CHN1_LC_ch1_vlc_ie_shift                                 (29)
#define VGIP_CHN1_LC_den_crc_sel_shift                                (28)
#define VGIP_CHN1_LC_ch1_line_cnt_shift                               (12)
#define VGIP_CHN1_LC_ch1_vln_shift                                    (0)
#define VGIP_CHN1_LC_ch1_vlcen_mask                                   (0x80000000)
#define VGIP_CHN1_LC_ch1_vlc_mode_mask                                (0x40000000)
#define VGIP_CHN1_LC_ch1_vlc_ie_mask                                  (0x20000000)
#define VGIP_CHN1_LC_den_crc_sel_mask                                 (0x10000000)
#define VGIP_CHN1_LC_ch1_line_cnt_mask                                (0x00FFF000)
#define VGIP_CHN1_LC_ch1_vln_mask                                     (0x00000FFF)
#define VGIP_CHN1_LC_ch1_vlcen(data)                                  (0x80000000&((data)<<31))
#define VGIP_CHN1_LC_ch1_vlc_mode(data)                               (0x40000000&((data)<<30))
#define VGIP_CHN1_LC_ch1_vlc_ie(data)                                 (0x20000000&((data)<<29))
#define VGIP_CHN1_LC_den_crc_sel(data)                                (0x10000000&((data)<<28))
#define VGIP_CHN1_LC_ch1_line_cnt(data)                               (0x00FFF000&((data)<<12))
#define VGIP_CHN1_LC_ch1_vln(data)                                    (0x00000FFF&(data))
#define VGIP_CHN1_LC_get_ch1_vlcen(data)                              ((0x80000000&(data))>>31)
#define VGIP_CHN1_LC_get_ch1_vlc_mode(data)                           ((0x40000000&(data))>>30)
#define VGIP_CHN1_LC_get_ch1_vlc_ie(data)                             ((0x20000000&(data))>>29)
#define VGIP_CHN1_LC_get_den_crc_sel(data)                            ((0x10000000&(data))>>28)
#define VGIP_CHN1_LC_get_ch1_line_cnt(data)                           ((0x00FFF000&(data))>>12)
#define VGIP_CHN1_LC_get_ch1_vln(data)                                (0x00000FFF&(data))


#define ICH1_VGIP_CRC_CTRL                                            0x18022238
#define ICH1_VGIP_CRC_CTRL_reg_addr                                   "0xb8022238"
#define ICH1_VGIP_CRC_CTRL_reg                                        0xb8022238
#define ICH1_VGIP_CRC_CTRL_inst_addr                                  "0x008E"
#define ICH1_VGIP_CRC_CTRL_inst                                       0x008E
#define ICH1_VGIP_CRC_CTRL_ch1_crc_region_shift                       (5)
#define ICH1_VGIP_CRC_CTRL_ch1_crc_ctrl_in_shift                      (4)
#define ICH1_VGIP_CRC_CTRL_ch1_crc_field_edge_sel_shift               (3)
#define ICH1_VGIP_CRC_CTRL_ch1_crc_field_shift                        (2)
#define ICH1_VGIP_CRC_CTRL_ch1_crc_conti_shift                        (1)
#define ICH1_VGIP_CRC_CTRL_ch1_crc_start_shift                        (0)
#define ICH1_VGIP_CRC_CTRL_ch1_crc_region_mask                        (0x00000020)
#define ICH1_VGIP_CRC_CTRL_ch1_crc_ctrl_in_mask                       (0x00000010)
#define ICH1_VGIP_CRC_CTRL_ch1_crc_field_edge_sel_mask                (0x00000008)
#define ICH1_VGIP_CRC_CTRL_ch1_crc_field_mask                         (0x00000004)
#define ICH1_VGIP_CRC_CTRL_ch1_crc_conti_mask                         (0x00000002)
#define ICH1_VGIP_CRC_CTRL_ch1_crc_start_mask                         (0x00000001)
#define ICH1_VGIP_CRC_CTRL_ch1_crc_region(data)                       (0x00000020&((data)<<5))
#define ICH1_VGIP_CRC_CTRL_ch1_crc_ctrl_in(data)                      (0x00000010&((data)<<4))
#define ICH1_VGIP_CRC_CTRL_ch1_crc_field_edge_sel(data)               (0x00000008&((data)<<3))
#define ICH1_VGIP_CRC_CTRL_ch1_crc_field(data)                        (0x00000004&((data)<<2))
#define ICH1_VGIP_CRC_CTRL_ch1_crc_conti(data)                        (0x00000002&((data)<<1))
#define ICH1_VGIP_CRC_CTRL_ch1_crc_start(data)                        (0x00000001&(data))
#define ICH1_VGIP_CRC_CTRL_get_ch1_crc_region(data)                   ((0x00000020&(data))>>5)
#define ICH1_VGIP_CRC_CTRL_get_ch1_crc_ctrl_in(data)                  ((0x00000010&(data))>>4)
#define ICH1_VGIP_CRC_CTRL_get_ch1_crc_field_edge_sel(data)           ((0x00000008&(data))>>3)
#define ICH1_VGIP_CRC_CTRL_get_ch1_crc_field(data)                    ((0x00000004&(data))>>2)
#define ICH1_VGIP_CRC_CTRL_get_ch1_crc_conti(data)                    ((0x00000002&(data))>>1)
#define ICH1_VGIP_CRC_CTRL_get_ch1_crc_start(data)                    (0x00000001&(data))


#define ICH1_VGIP_CRC_RESULT                                          0x1802223c
#define ICH1_VGIP_CRC_RESULT_reg_addr                                 "0xb802223c"
#define ICH1_VGIP_CRC_RESULT_reg                                      0xb802223c
#define ICH1_VGIP_CRC_RESULT_inst_addr                                "0x008F"
#define ICH1_VGIP_CRC_RESULT_inst                                     0x008F
#define ICH1_VGIP_CRC_RESULT_ch1_crc_result_shift                     (0)
#define ICH1_VGIP_CRC_RESULT_ch1_crc_result_mask                      (0xFFFFFFFF)
#define ICH1_VGIP_CRC_RESULT_ch1_crc_result(data)                     (0xFFFFFFFF&(data))
#define ICH1_VGIP_CRC_RESULT_get_ch1_crc_result(data)                 (0xFFFFFFFF&(data))


#define VGIP_CHN1_WDE                                                 0x18022240
#define VGIP_CHN1_WDE_reg_addr                                        "0xb8022240"
#define VGIP_CHN1_WDE_reg                                             0xb8022240
#define VGIP_CHN1_WDE_inst_addr                                       "0x0090"
#define VGIP_CHN1_WDE_inst                                            0x0090
#define VGIP_CHN1_WDE_ch1_wd_to_main_shift                            (31)
#define VGIP_CHN1_WDE_ch1_wd_to_sub_shift                             (30)
#define VGIP_CHN1_WDE_dummy18022240_29_19_shift                       (19)
#define VGIP_CHN1_WDE_ch1_vs_err_wde_shift                            (18)
#define VGIP_CHN1_WDE_ch1_hs_err_wde_shift                            (17)
#define VGIP_CHN1_WDE_ch1_field_err_wde_shift                         (16)
#define VGIP_CHN1_WDE_ch1_rl_err_wde_shift                            (15)
#define VGIP_CHN1_WDE_dummy18022240_14_4_shift                        (4)
#define VGIP_CHN1_WDE_ch1_rl_err_ie_shift                             (3)
#define VGIP_CHN1_WDE_ch1_vs_err_ie_shift                             (2)
#define VGIP_CHN1_WDE_ch1_hs_err_ie_shift                             (1)
#define VGIP_CHN1_WDE_ch1_field_err_ie_shift                          (0)
#define VGIP_CHN1_WDE_ch1_wd_to_main_mask                             (0x80000000)
#define VGIP_CHN1_WDE_ch1_wd_to_sub_mask                              (0x40000000)
#define VGIP_CHN1_WDE_dummy18022240_29_19_mask                        (0x3FF80000)
#define VGIP_CHN1_WDE_ch1_vs_err_wde_mask                             (0x00040000)
#define VGIP_CHN1_WDE_ch1_hs_err_wde_mask                             (0x00020000)
#define VGIP_CHN1_WDE_ch1_field_err_wde_mask                          (0x00010000)
#define VGIP_CHN1_WDE_ch1_rl_err_wde_mask                             (0x00008000)
#define VGIP_CHN1_WDE_dummy18022240_14_4_mask                         (0x00007FF0)
#define VGIP_CHN1_WDE_ch1_rl_err_ie_mask                              (0x00000008)
#define VGIP_CHN1_WDE_ch1_vs_err_ie_mask                              (0x00000004)
#define VGIP_CHN1_WDE_ch1_hs_err_ie_mask                              (0x00000002)
#define VGIP_CHN1_WDE_ch1_field_err_ie_mask                           (0x00000001)
#define VGIP_CHN1_WDE_ch1_wd_to_main(data)                            (0x80000000&((data)<<31))
#define VGIP_CHN1_WDE_ch1_wd_to_sub(data)                             (0x40000000&((data)<<30))
#define VGIP_CHN1_WDE_dummy18022240_29_19(data)                       (0x3FF80000&((data)<<19))
#define VGIP_CHN1_WDE_ch1_vs_err_wde(data)                            (0x00040000&((data)<<18))
#define VGIP_CHN1_WDE_ch1_hs_err_wde(data)                            (0x00020000&((data)<<17))
#define VGIP_CHN1_WDE_ch1_field_err_wde(data)                         (0x00010000&((data)<<16))
#define VGIP_CHN1_WDE_ch1_rl_err_wde(data)                            (0x00008000&((data)<<15))
#define VGIP_CHN1_WDE_dummy18022240_14_4(data)                        (0x00007FF0&((data)<<4))
#define VGIP_CHN1_WDE_ch1_rl_err_ie(data)                             (0x00000008&((data)<<3))
#define VGIP_CHN1_WDE_ch1_vs_err_ie(data)                             (0x00000004&((data)<<2))
#define VGIP_CHN1_WDE_ch1_hs_err_ie(data)                             (0x00000002&((data)<<1))
#define VGIP_CHN1_WDE_ch1_field_err_ie(data)                          (0x00000001&(data))
#define VGIP_CHN1_WDE_get_ch1_wd_to_main(data)                        ((0x80000000&(data))>>31)
#define VGIP_CHN1_WDE_get_ch1_wd_to_sub(data)                         ((0x40000000&(data))>>30)
#define VGIP_CHN1_WDE_get_dummy18022240_29_19(data)                   ((0x3FF80000&(data))>>19)
#define VGIP_CHN1_WDE_get_ch1_vs_err_wde(data)                        ((0x00040000&(data))>>18)
#define VGIP_CHN1_WDE_get_ch1_hs_err_wde(data)                        ((0x00020000&(data))>>17)
#define VGIP_CHN1_WDE_get_ch1_field_err_wde(data)                     ((0x00010000&(data))>>16)
#define VGIP_CHN1_WDE_get_ch1_rl_err_wde(data)                        ((0x00008000&(data))>>15)
#define VGIP_CHN1_WDE_get_dummy18022240_14_4(data)                    ((0x00007FF0&(data))>>4)
#define VGIP_CHN1_WDE_get_ch1_rl_err_ie(data)                         ((0x00000008&(data))>>3)
#define VGIP_CHN1_WDE_get_ch1_vs_err_ie(data)                         ((0x00000004&(data))>>2)
#define VGIP_CHN1_WDE_get_ch1_hs_err_ie(data)                         ((0x00000002&(data))>>1)
#define VGIP_CHN1_WDE_get_ch1_field_err_ie(data)                      (0x00000001&(data))


#define ADC_RAW_DATA_DMA                                              0x18022278
#define ADC_RAW_DATA_DMA_reg_addr                                     "0xb8022278"
#define ADC_RAW_DATA_DMA_reg                                          0xb8022278
#define ADC_RAW_DATA_DMA_inst_addr                                    "0x009E"
#define ADC_RAW_DATA_DMA_inst                                         0x009E
#define ADC_RAW_DATA_DMA_adc_test_dma_count_shift                     (4)
#define ADC_RAW_DATA_DMA_force_den_shift                              (2)
#define ADC_RAW_DATA_DMA_force_vsync_shift                            (1)
#define ADC_RAW_DATA_DMA_adc_test_dma_mode_shift                      (0)
#define ADC_RAW_DATA_DMA_adc_test_dma_count_mask                      (0xFFFFFFF0)
#define ADC_RAW_DATA_DMA_force_den_mask                               (0x00000004)
#define ADC_RAW_DATA_DMA_force_vsync_mask                             (0x00000002)
#define ADC_RAW_DATA_DMA_adc_test_dma_mode_mask                       (0x00000001)
#define ADC_RAW_DATA_DMA_adc_test_dma_count(data)                     (0xFFFFFFF0&((data)<<4))
#define ADC_RAW_DATA_DMA_force_den(data)                              (0x00000004&((data)<<2))
#define ADC_RAW_DATA_DMA_force_vsync(data)                            (0x00000002&((data)<<1))
#define ADC_RAW_DATA_DMA_adc_test_dma_mode(data)                      (0x00000001&(data))
#define ADC_RAW_DATA_DMA_get_adc_test_dma_count(data)                 ((0xFFFFFFF0&(data))>>4)
#define ADC_RAW_DATA_DMA_get_force_den(data)                          ((0x00000004&(data))>>2)
#define ADC_RAW_DATA_DMA_get_force_vsync(data)                        ((0x00000002&(data))>>1)
#define ADC_RAW_DATA_DMA_get_adc_test_dma_mode(data)                  (0x00000001&(data))


#define FRAMEPACKING_CTRL1                                            0x1802227c
#define FRAMEPACKING_CTRL1_reg_addr                                   "0xb802227c"
#define FRAMEPACKING_CTRL1_reg                                        0xb802227c
#define FRAMEPACKING_CTRL1_inst_addr                                  "0x009F"
#define FRAMEPACKING_CTRL1_inst                                       0x009F
#define FRAMEPACKING_CTRL1_vs_width_shift                             (16)
#define FRAMEPACKING_CTRL1_frame_packing_en_shift                     (13)
#define FRAMEPACKING_CTRL1_vs_position_shift                          (0)
#define FRAMEPACKING_CTRL1_vs_width_mask                              (0x1FFF0000)
#define FRAMEPACKING_CTRL1_frame_packing_en_mask                      (0x00002000)
#define FRAMEPACKING_CTRL1_vs_position_mask                           (0x00001FFF)
#define FRAMEPACKING_CTRL1_vs_width(data)                             (0x1FFF0000&((data)<<16))
#define FRAMEPACKING_CTRL1_frame_packing_en(data)                     (0x00002000&((data)<<13))
#define FRAMEPACKING_CTRL1_vs_position(data)                          (0x00001FFF&(data))
#define FRAMEPACKING_CTRL1_get_vs_width(data)                         ((0x1FFF0000&(data))>>16)
#define FRAMEPACKING_CTRL1_get_frame_packing_en(data)                 ((0x00002000&(data))>>13)
#define FRAMEPACKING_CTRL1_get_vs_position(data)                      (0x00001FFF&(data))


#define FRAMEPACKING_CTRL2                                            0x18022280
#define FRAMEPACKING_CTRL2_reg_addr                                   "0xb8022280"
#define FRAMEPACKING_CTRL2_reg                                        0xb8022280
#define FRAMEPACKING_CTRL2_inst_addr                                  "0x00A0"
#define FRAMEPACKING_CTRL2_inst                                       0x00A0
#define FRAMEPACKING_CTRL2_den_mask_start_shift                       (16)
#define FRAMEPACKING_CTRL2_den_mask_end_shift                         (0)
#define FRAMEPACKING_CTRL2_den_mask_start_mask                        (0x1FFF0000)
#define FRAMEPACKING_CTRL2_den_mask_end_mask                          (0x00001FFF)
#define FRAMEPACKING_CTRL2_den_mask_start(data)                       (0x1FFF0000&((data)<<16))
#define FRAMEPACKING_CTRL2_den_mask_end(data)                         (0x00001FFF&(data))
#define FRAMEPACKING_CTRL2_get_den_mask_start(data)                   ((0x1FFF0000&(data))>>16)
#define FRAMEPACKING_CTRL2_get_den_mask_end(data)                     (0x00001FFF&(data))


#define DATA_PATH_SELECT                                              0x18022284
#define DATA_PATH_SELECT_reg_addr                                     "0xb8022284"
#define DATA_PATH_SELECT_reg                                          0xb8022284
#define DATA_PATH_SELECT_inst_addr                                    "0x00A1"
#define DATA_PATH_SELECT_inst                                         0x00A1
#define DATA_PATH_SELECT_fsync_ch_sel_shift                           (5)
#define DATA_PATH_SELECT_adc_ch_sel_shift                             (4)
#define DATA_PATH_SELECT_xcdi_clk_en_shift                            (3)
#define DATA_PATH_SELECT_uzd1_in_sel_shift                            (2)
#define DATA_PATH_SELECT_uzd2_in_sel_shift                            (1)
#define DATA_PATH_SELECT_xcdi_in_sel_shift                            (0)
#define DATA_PATH_SELECT_fsync_ch_sel_mask                            (0x00000020)
#define DATA_PATH_SELECT_adc_ch_sel_mask                              (0x00000010)
#define DATA_PATH_SELECT_xcdi_clk_en_mask                             (0x00000008)
#define DATA_PATH_SELECT_uzd1_in_sel_mask                             (0x00000004)
#define DATA_PATH_SELECT_uzd2_in_sel_mask                             (0x00000002)
#define DATA_PATH_SELECT_xcdi_in_sel_mask                             (0x00000001)
#define DATA_PATH_SELECT_fsync_ch_sel(data)                           (0x00000020&((data)<<5))
#define DATA_PATH_SELECT_adc_ch_sel(data)                             (0x00000010&((data)<<4))
#define DATA_PATH_SELECT_xcdi_clk_en(data)                            (0x00000008&((data)<<3))
#define DATA_PATH_SELECT_uzd1_in_sel(data)                            (0x00000004&((data)<<2))
#define DATA_PATH_SELECT_uzd2_in_sel(data)                            (0x00000002&((data)<<1))
#define DATA_PATH_SELECT_xcdi_in_sel(data)                            (0x00000001&(data))
#define DATA_PATH_SELECT_get_fsync_ch_sel(data)                       ((0x00000020&(data))>>5)
#define DATA_PATH_SELECT_get_adc_ch_sel(data)                         ((0x00000010&(data))>>4)
#define DATA_PATH_SELECT_get_xcdi_clk_en(data)                        ((0x00000008&(data))>>3)
#define DATA_PATH_SELECT_get_uzd1_in_sel(data)                        ((0x00000004&(data))>>2)
#define DATA_PATH_SELECT_get_uzd2_in_sel(data)                        ((0x00000002&(data))>>1)
#define DATA_PATH_SELECT_get_xcdi_in_sel(data)                        (0x00000001&(data))


#define VGIP_VBISLI                                                   0x18022288
#define VGIP_VBISLI_reg_addr                                          "0xb8022288"
#define VGIP_VBISLI_reg                                               0xb8022288
#define VGIP_VBISLI_inst_addr                                         "0x00A2"
#define VGIP_VBISLI_inst                                              0x00A2
#define VGIP_VBISLI_vbisli_in_sel_shift                               (29)
#define VGIP_VBISLI_vbisli_ivs_dly_shift                              (16)
#define VGIP_VBISLI_vbisli_ihs_dly_shift                              (0)
#define VGIP_VBISLI_vbisli_in_sel_mask                                (0x20000000)
#define VGIP_VBISLI_vbisli_ivs_dly_mask                               (0x1FFF0000)
#define VGIP_VBISLI_vbisli_ihs_dly_mask                               (0x00003FFF)
#define VGIP_VBISLI_vbisli_in_sel(data)                               (0x20000000&((data)<<29))
#define VGIP_VBISLI_vbisli_ivs_dly(data)                              (0x1FFF0000&((data)<<16))
#define VGIP_VBISLI_vbisli_ihs_dly(data)                              (0x00003FFF&(data))
#define VGIP_VBISLI_get_vbisli_in_sel(data)                           ((0x20000000&(data))>>29)
#define VGIP_VBISLI_get_vbisli_ivs_dly(data)                          ((0x1FFF0000&(data))>>16)
#define VGIP_VBISLI_get_vbisli_ihs_dly(data)                          (0x00003FFF&(data))


#define INT_CTL                                                       0x1802228c
#define INT_CTL_reg_addr                                              "0xb802228c"
#define INT_CTL_reg                                                   0xb802228c
#define INT_CTL_inst_addr                                             "0x00A3"
#define INT_CTL_inst                                                  0x00A3
#define INT_CTL_onms3_int_ie_shift                                    (9)
#define INT_CTL_offms_int_ie_shift                                    (8)
#define INT_CTL_onms2_int_ie_shift                                    (7)
#define INT_CTL_onms1_int_ie_shift                                    (6)
#define INT_CTL_hist_ch1_int_ie_shift                                 (5)
#define INT_CTL_hist_ch2_int_ie_shift                                 (4)
#define INT_CTL_vgip_int_ie_shift                                     (3)
#define INT_CTL_dispi_int_ie_shift                                    (0)
#define INT_CTL_onms3_int_ie_mask                                     (0x00000200)
#define INT_CTL_offms_int_ie_mask                                     (0x00000100)
#define INT_CTL_onms2_int_ie_mask                                     (0x00000080)
#define INT_CTL_onms1_int_ie_mask                                     (0x00000040)
#define INT_CTL_hist_ch1_int_ie_mask                                  (0x00000020)
#define INT_CTL_hist_ch2_int_ie_mask                                  (0x00000010)
#define INT_CTL_vgip_int_ie_mask                                      (0x00000008)
#define INT_CTL_dispi_int_ie_mask                                     (0x00000001)
#define INT_CTL_onms3_int_ie(data)                                    (0x00000200&((data)<<9))
#define INT_CTL_offms_int_ie(data)                                    (0x00000100&((data)<<8))
#define INT_CTL_onms2_int_ie(data)                                    (0x00000080&((data)<<7))
#define INT_CTL_onms1_int_ie(data)                                    (0x00000040&((data)<<6))
#define INT_CTL_hist_ch1_int_ie(data)                                 (0x00000020&((data)<<5))
#define INT_CTL_hist_ch2_int_ie(data)                                 (0x00000010&((data)<<4))
#define INT_CTL_vgip_int_ie(data)                                     (0x00000008&((data)<<3))
#define INT_CTL_dispi_int_ie(data)                                    (0x00000001&(data))
#define INT_CTL_get_onms3_int_ie(data)                                ((0x00000200&(data))>>9)
#define INT_CTL_get_offms_int_ie(data)                                ((0x00000100&(data))>>8)
#define INT_CTL_get_onms2_int_ie(data)                                ((0x00000080&(data))>>7)
#define INT_CTL_get_onms1_int_ie(data)                                ((0x00000040&(data))>>6)
#define INT_CTL_get_hist_ch1_int_ie(data)                             ((0x00000020&(data))>>5)
#define INT_CTL_get_hist_ch2_int_ie(data)                             ((0x00000010&(data))>>4)
#define INT_CTL_get_vgip_int_ie(data)                                 ((0x00000008&(data))>>3)
#define INT_CTL_get_dispi_int_ie(data)                                (0x00000001&(data))


#define CTS_FIFO_CTL                                                  0x18022290
#define CTS_FIFO_CTL_reg_addr                                         "0xb8022290"
#define CTS_FIFO_CTL_reg                                              0xb8022290
#define CTS_FIFO_CTL_inst_addr                                        "0x00A4"
#define CTS_FIFO_CTL_inst                                             0x00A4
#define CTS_FIFO_CTL_dummy_ctsfifo_sdnr_shift                         (11)
#define CTS_FIFO_CTL_force_ctsfifo_rstn_sdnr_shift                    (10)
#define CTS_FIFO_CTL_en_ctsfifo_vsrst_sdnr_shift                      (9)
#define CTS_FIFO_CTL_en_ctsfifo_bypass_sdnr_shift                     (8)
#define CTS_FIFO_CTL_dummy_ctsfifo_vgip_shift                         (3)
#define CTS_FIFO_CTL_force_ctsfifo_rstn_vgip_shift                    (2)
#define CTS_FIFO_CTL_en_ctsfifo_vsrst_vgip_shift                      (1)
#define CTS_FIFO_CTL_en_ctsfifo_bypass_vgip_shift                     (0)
#define CTS_FIFO_CTL_dummy_ctsfifo_sdnr_mask                          (0x00000800)
#define CTS_FIFO_CTL_force_ctsfifo_rstn_sdnr_mask                     (0x00000400)
#define CTS_FIFO_CTL_en_ctsfifo_vsrst_sdnr_mask                       (0x00000200)
#define CTS_FIFO_CTL_en_ctsfifo_bypass_sdnr_mask                      (0x00000100)
#define CTS_FIFO_CTL_dummy_ctsfifo_vgip_mask                          (0x00000008)
#define CTS_FIFO_CTL_force_ctsfifo_rstn_vgip_mask                     (0x00000004)
#define CTS_FIFO_CTL_en_ctsfifo_vsrst_vgip_mask                       (0x00000002)
#define CTS_FIFO_CTL_en_ctsfifo_bypass_vgip_mask                      (0x00000001)
#define CTS_FIFO_CTL_dummy_ctsfifo_sdnr(data)                         (0x00000800&((data)<<11))
#define CTS_FIFO_CTL_force_ctsfifo_rstn_sdnr(data)                    (0x00000400&((data)<<10))
#define CTS_FIFO_CTL_en_ctsfifo_vsrst_sdnr(data)                      (0x00000200&((data)<<9))
#define CTS_FIFO_CTL_en_ctsfifo_bypass_sdnr(data)                     (0x00000100&((data)<<8))
#define CTS_FIFO_CTL_dummy_ctsfifo_vgip(data)                         (0x00000008&((data)<<3))
#define CTS_FIFO_CTL_force_ctsfifo_rstn_vgip(data)                    (0x00000004&((data)<<2))
#define CTS_FIFO_CTL_en_ctsfifo_vsrst_vgip(data)                      (0x00000002&((data)<<1))
#define CTS_FIFO_CTL_en_ctsfifo_bypass_vgip(data)                     (0x00000001&(data))
#define CTS_FIFO_CTL_get_dummy_ctsfifo_sdnr(data)                     ((0x00000800&(data))>>11)
#define CTS_FIFO_CTL_get_force_ctsfifo_rstn_sdnr(data)                ((0x00000400&(data))>>10)
#define CTS_FIFO_CTL_get_en_ctsfifo_vsrst_sdnr(data)                  ((0x00000200&(data))>>9)
#define CTS_FIFO_CTL_get_en_ctsfifo_bypass_sdnr(data)                 ((0x00000100&(data))>>8)
#define CTS_FIFO_CTL_get_dummy_ctsfifo_vgip(data)                     ((0x00000008&(data))>>3)
#define CTS_FIFO_CTL_get_force_ctsfifo_rstn_vgip(data)                ((0x00000004&(data))>>2)
#define CTS_FIFO_CTL_get_en_ctsfifo_vsrst_vgip(data)                  ((0x00000002&(data))>>1)
#define CTS_FIFO_CTL_get_en_ctsfifo_bypass_vgip(data)                 (0x00000001&(data))


#define DISPI_TEST_SEL                                                0x18022294
#define DISPI_TEST_SEL_reg_addr                                       "0xb8022294"
#define DISPI_TEST_SEL_reg                                            0xb8022294
#define DISPI_TEST_SEL_inst_addr                                      "0x00A5"
#define DISPI_TEST_SEL_inst                                           0x00A5
#define DISPI_TEST_SEL_disp_testpinsel_shift                          (0)
#define DISPI_TEST_SEL_disp_testpinsel_mask                           (0x0000003F)
#define DISPI_TEST_SEL_disp_testpinsel(data)                          (0x0000003F&(data))
#define DISPI_TEST_SEL_get_disp_testpinsel(data)                      (0x0000003F&(data))


#define VGIP_CHN1_3D_RIGHT_ACT_HSTA_WIDTH                             0x18022298
#define VGIP_CHN1_3D_RIGHT_ACT_HSTA_WIDTH_reg_addr                    "0xb8022298"
#define VGIP_CHN1_3D_RIGHT_ACT_HSTA_WIDTH_reg                         0xb8022298
#define VGIP_CHN1_3D_RIGHT_ACT_HSTA_WIDTH_inst_addr                   "0x00A6"
#define VGIP_CHN1_3D_RIGHT_ACT_HSTA_WIDTH_inst                        0x00A6
#define VGIP_CHN1_3D_RIGHT_ACT_HSTA_WIDTH_ch1_3d_right_ih_act_sta_shift  (16)
#define VGIP_CHN1_3D_RIGHT_ACT_HSTA_WIDTH_ch1_3d_right_ih_act_wid_shift  (0)
#define VGIP_CHN1_3D_RIGHT_ACT_HSTA_WIDTH_ch1_3d_right_ih_act_sta_mask  (0x3FFF0000)
#define VGIP_CHN1_3D_RIGHT_ACT_HSTA_WIDTH_ch1_3d_right_ih_act_wid_mask  (0x00003FFF)
#define VGIP_CHN1_3D_RIGHT_ACT_HSTA_WIDTH_ch1_3d_right_ih_act_sta(data)  (0x3FFF0000&((data)<<16))
#define VGIP_CHN1_3D_RIGHT_ACT_HSTA_WIDTH_ch1_3d_right_ih_act_wid(data)  (0x00003FFF&(data))
#define VGIP_CHN1_3D_RIGHT_ACT_HSTA_WIDTH_get_ch1_3d_right_ih_act_sta(data)  ((0x3FFF0000&(data))>>16)
#define VGIP_CHN1_3D_RIGHT_ACT_HSTA_WIDTH_get_ch1_3d_right_ih_act_wid(data)  (0x00003FFF&(data))


#define VGIP_CHN1_3D_RIGHT_ACT_VSTA_LENGTH                            0x1802229c
#define VGIP_CHN1_3D_RIGHT_ACT_VSTA_LENGTH_reg_addr                   "0xb802229c"
#define VGIP_CHN1_3D_RIGHT_ACT_VSTA_LENGTH_reg                        0xb802229c
#define VGIP_CHN1_3D_RIGHT_ACT_VSTA_LENGTH_inst_addr                  "0x00A7"
#define VGIP_CHN1_3D_RIGHT_ACT_VSTA_LENGTH_inst                       0x00A7
#define VGIP_CHN1_3D_RIGHT_ACT_VSTA_LENGTH_ch1_3d_right_iv_act_sta_shift  (16)
#define VGIP_CHN1_3D_RIGHT_ACT_VSTA_LENGTH_ch1_3d_right_iv_act_len_shift  (0)
#define VGIP_CHN1_3D_RIGHT_ACT_VSTA_LENGTH_ch1_3d_right_iv_act_sta_mask  (0x1FFF0000)
#define VGIP_CHN1_3D_RIGHT_ACT_VSTA_LENGTH_ch1_3d_right_iv_act_len_mask  (0x00001FFF)
#define VGIP_CHN1_3D_RIGHT_ACT_VSTA_LENGTH_ch1_3d_right_iv_act_sta(data)  (0x1FFF0000&((data)<<16))
#define VGIP_CHN1_3D_RIGHT_ACT_VSTA_LENGTH_ch1_3d_right_iv_act_len(data)  (0x00001FFF&(data))
#define VGIP_CHN1_3D_RIGHT_ACT_VSTA_LENGTH_get_ch1_3d_right_iv_act_sta(data)  ((0x1FFF0000&(data))>>16)
#define VGIP_CHN1_3D_RIGHT_ACT_VSTA_LENGTH_get_ch1_3d_right_iv_act_len(data)  (0x00001FFF&(data))


#define FRAMEPACKING_INTERLACE_CTRL1                                  0x180222a8
#define FRAMEPACKING_INTERLACE_CTRL1_reg_addr                         "0xb80222a8"
#define FRAMEPACKING_INTERLACE_CTRL1_reg                              0xb80222a8
#define FRAMEPACKING_INTERLACE_CTRL1_inst_addr                        "0x00AA"
#define FRAMEPACKING_INTERLACE_CTRL1_inst                             0x00AA
#define FRAMEPACKING_INTERLACE_CTRL1_vs_width_r_odd_shift             (16)
#define FRAMEPACKING_INTERLACE_CTRL1_frame_packing_field_en_shift     (13)
#define FRAMEPACKING_INTERLACE_CTRL1_vs_position_r_odd_shift          (0)
#define FRAMEPACKING_INTERLACE_CTRL1_vs_width_r_odd_mask              (0x1FFF0000)
#define FRAMEPACKING_INTERLACE_CTRL1_frame_packing_field_en_mask      (0x00002000)
#define FRAMEPACKING_INTERLACE_CTRL1_vs_position_r_odd_mask           (0x00001FFF)
#define FRAMEPACKING_INTERLACE_CTRL1_vs_width_r_odd(data)             (0x1FFF0000&((data)<<16))
#define FRAMEPACKING_INTERLACE_CTRL1_frame_packing_field_en(data)     (0x00002000&((data)<<13))
#define FRAMEPACKING_INTERLACE_CTRL1_vs_position_r_odd(data)          (0x00001FFF&(data))
#define FRAMEPACKING_INTERLACE_CTRL1_get_vs_width_r_odd(data)         ((0x1FFF0000&(data))>>16)
#define FRAMEPACKING_INTERLACE_CTRL1_get_frame_packing_field_en(data) ((0x00002000&(data))>>13)
#define FRAMEPACKING_INTERLACE_CTRL1_get_vs_position_r_odd(data)      (0x00001FFF&(data))


#define FRAMEPACKING_INTERLACE_CTRL2                                  0x180222ac
#define FRAMEPACKING_INTERLACE_CTRL2_reg_addr                         "0xb80222ac"
#define FRAMEPACKING_INTERLACE_CTRL2_reg                              0xb80222ac
#define FRAMEPACKING_INTERLACE_CTRL2_inst_addr                        "0x00AB"
#define FRAMEPACKING_INTERLACE_CTRL2_inst                             0x00AB
#define FRAMEPACKING_INTERLACE_CTRL2_den_mask_start_r_odd_shift       (16)
#define FRAMEPACKING_INTERLACE_CTRL2_den_mask_end_r_odd_shift         (0)
#define FRAMEPACKING_INTERLACE_CTRL2_den_mask_start_r_odd_mask        (0x1FFF0000)
#define FRAMEPACKING_INTERLACE_CTRL2_den_mask_end_r_odd_mask          (0x00001FFF)
#define FRAMEPACKING_INTERLACE_CTRL2_den_mask_start_r_odd(data)       (0x1FFF0000&((data)<<16))
#define FRAMEPACKING_INTERLACE_CTRL2_den_mask_end_r_odd(data)         (0x00001FFF&(data))
#define FRAMEPACKING_INTERLACE_CTRL2_get_den_mask_start_r_odd(data)   ((0x1FFF0000&(data))>>16)
#define FRAMEPACKING_INTERLACE_CTRL2_get_den_mask_end_r_odd(data)     (0x00001FFF&(data))


#define FRAMEPACKING_INTERLACE_CTRL3                                  0x180222b0
#define FRAMEPACKING_INTERLACE_CTRL3_reg_addr                         "0xb80222b0"
#define FRAMEPACKING_INTERLACE_CTRL3_reg                              0xb80222b0
#define FRAMEPACKING_INTERLACE_CTRL3_inst_addr                        "0x00AC"
#define FRAMEPACKING_INTERLACE_CTRL3_inst                             0x00AC
#define FRAMEPACKING_INTERLACE_CTRL3_vs_width_r_even_shift            (16)
#define FRAMEPACKING_INTERLACE_CTRL3_vs_position_r_even_shift         (0)
#define FRAMEPACKING_INTERLACE_CTRL3_vs_width_r_even_mask             (0x1FFF0000)
#define FRAMEPACKING_INTERLACE_CTRL3_vs_position_r_even_mask          (0x00001FFF)
#define FRAMEPACKING_INTERLACE_CTRL3_vs_width_r_even(data)            (0x1FFF0000&((data)<<16))
#define FRAMEPACKING_INTERLACE_CTRL3_vs_position_r_even(data)         (0x00001FFF&(data))
#define FRAMEPACKING_INTERLACE_CTRL3_get_vs_width_r_even(data)        ((0x1FFF0000&(data))>>16)
#define FRAMEPACKING_INTERLACE_CTRL3_get_vs_position_r_even(data)     (0x00001FFF&(data))


#define FRAMEPACKING_INTERLACE_CTRL4                                  0x180222b4
#define FRAMEPACKING_INTERLACE_CTRL4_reg_addr                         "0xb80222b4"
#define FRAMEPACKING_INTERLACE_CTRL4_reg                              0xb80222b4
#define FRAMEPACKING_INTERLACE_CTRL4_inst_addr                        "0x00AD"
#define FRAMEPACKING_INTERLACE_CTRL4_inst                             0x00AD
#define FRAMEPACKING_INTERLACE_CTRL4_den_mask_start_r_even_shift      (16)
#define FRAMEPACKING_INTERLACE_CTRL4_den_mask_end_r_even_shift        (0)
#define FRAMEPACKING_INTERLACE_CTRL4_den_mask_start_r_even_mask       (0x1FFF0000)
#define FRAMEPACKING_INTERLACE_CTRL4_den_mask_end_r_even_mask         (0x00001FFF)
#define FRAMEPACKING_INTERLACE_CTRL4_den_mask_start_r_even(data)      (0x1FFF0000&((data)<<16))
#define FRAMEPACKING_INTERLACE_CTRL4_den_mask_end_r_even(data)        (0x00001FFF&(data))
#define FRAMEPACKING_INTERLACE_CTRL4_get_den_mask_start_r_even(data)  ((0x1FFF0000&(data))>>16)
#define FRAMEPACKING_INTERLACE_CTRL4_get_den_mask_end_r_even(data)    (0x00001FFF&(data))


#define L_R_ACTIVE_ENABLE_CTRL1                                       0x180222b8
#define L_R_ACTIVE_ENABLE_CTRL1_reg_addr                              "0xb80222b8"
#define L_R_ACTIVE_ENABLE_CTRL1_reg                                   0xb80222b8
#define L_R_ACTIVE_ENABLE_CTRL1_inst_addr                             "0x00AE"
#define L_R_ACTIVE_ENABLE_CTRL1_inst                                  0x00AE
#define L_R_ACTIVE_ENABLE_CTRL1_end_l_shift                           (16)
#define L_R_ACTIVE_ENABLE_CTRL1_sta_l_shift                           (0)
#define L_R_ACTIVE_ENABLE_CTRL1_end_l_mask                            (0x3FFF0000)
#define L_R_ACTIVE_ENABLE_CTRL1_sta_l_mask                            (0x00003FFF)
#define L_R_ACTIVE_ENABLE_CTRL1_end_l(data)                           (0x3FFF0000&((data)<<16))
#define L_R_ACTIVE_ENABLE_CTRL1_sta_l(data)                           (0x00003FFF&(data))
#define L_R_ACTIVE_ENABLE_CTRL1_get_end_l(data)                       ((0x3FFF0000&(data))>>16)
#define L_R_ACTIVE_ENABLE_CTRL1_get_sta_l(data)                       (0x00003FFF&(data))


#define L_R_ACTIVE_ENABLE_CTRL2                                       0x180222bc
#define L_R_ACTIVE_ENABLE_CTRL2_reg_addr                              "0xb80222bc"
#define L_R_ACTIVE_ENABLE_CTRL2_reg                                   0xb80222bc
#define L_R_ACTIVE_ENABLE_CTRL2_inst_addr                             "0x00AF"
#define L_R_ACTIVE_ENABLE_CTRL2_inst                                  0x00AF
#define L_R_ACTIVE_ENABLE_CTRL2_l_r_act_en_shift                      (31)
#define L_R_ACTIVE_ENABLE_CTRL2_h_v_mode_shift                        (30)
#define L_R_ACTIVE_ENABLE_CTRL2_end_r_shift                           (16)
#define L_R_ACTIVE_ENABLE_CTRL2_sta_r_shift                           (0)
#define L_R_ACTIVE_ENABLE_CTRL2_l_r_act_en_mask                       (0x80000000)
#define L_R_ACTIVE_ENABLE_CTRL2_h_v_mode_mask                         (0x40000000)
#define L_R_ACTIVE_ENABLE_CTRL2_end_r_mask                            (0x3FFF0000)
#define L_R_ACTIVE_ENABLE_CTRL2_sta_r_mask                            (0x00003FFF)
#define L_R_ACTIVE_ENABLE_CTRL2_l_r_act_en(data)                      (0x80000000&((data)<<31))
#define L_R_ACTIVE_ENABLE_CTRL2_h_v_mode(data)                        (0x40000000&((data)<<30))
#define L_R_ACTIVE_ENABLE_CTRL2_end_r(data)                           (0x3FFF0000&((data)<<16))
#define L_R_ACTIVE_ENABLE_CTRL2_sta_r(data)                           (0x00003FFF&(data))
#define L_R_ACTIVE_ENABLE_CTRL2_get_l_r_act_en(data)                  ((0x80000000&(data))>>31)
#define L_R_ACTIVE_ENABLE_CTRL2_get_h_v_mode(data)                    ((0x40000000&(data))>>30)
#define L_R_ACTIVE_ENABLE_CTRL2_get_end_r(data)                       ((0x3FFF0000&(data))>>16)
#define L_R_ACTIVE_ENABLE_CTRL2_get_sta_r(data)                       (0x00003FFF&(data))
#endif
