// This file is generated using the spec version 1.39, firmware template version 1.39and SRIF Parser                                                                                source code SVN rev:793                    Version flow no.:1.1.44
#ifndef _H3DMS_REG_H_INCLUDED_
#define _H3DMS_REG_H_INCLUDED_

//#define  _H3DMS_USE_STRUCT
#ifdef _H3DMS_USE_STRUCT

typedef struct
{
    unsigned int    dummy_ctrl:4;
    unsigned int    pixel_get_en:1;
    unsigned int    pixel_get_sel:2;
    unsigned int    progressive:1;
    unsigned int    vtotal_max_delta:4;
    unsigned int    htotal_max_delta:4;
    unsigned int    reserved_0:3;
    unsigned int    pixel_encoding:1;
    unsigned int    vact_space_threshold:4;
    unsigned int    vact_space_meas_en:1;
    unsigned int    meas_to_sel:1;
    unsigned int    sycms_clk:1;
    unsigned int    vs_meas_inv:1;
    unsigned int    hs_meas_inv:1;
    unsigned int    popup_meas:1;
    unsigned int    ms_conti:1;
    unsigned int    start_ms:1;
}ONMS_ctrl;

typedef struct
{
    unsigned int    reserved_0:7;
    unsigned int    pixel_ok:1;
    unsigned int    get_r_value:12;
    unsigned int    get_g_value:12;
}ONMS_blank_pixel_value_get_0;

typedef struct
{
    unsigned int    reserved_0:20;
    unsigned int    get_b_value:12;
}ONMS_blank_pixel_value_get_1;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    active_r_value:12;
    unsigned int    active_g_value:12;
}ONMS_blank_pixel_value_0;

typedef struct
{
    unsigned int    reserved_0:20;
    unsigned int    active_b_value:12;
}ONMS_blank_pixel_value_1;

typedef struct
{
    unsigned int    reserved_0:5;
    unsigned int    vact2:11;
    unsigned int    reserved_1:5;
    unsigned int    vact1:11;
}ONMS_fp_vact12;

typedef struct
{
    unsigned int    reserved_0:5;
    unsigned int    vact4:11;
    unsigned int    reserved_1:5;
    unsigned int    vact3:11;
}ONMS_fp_vact34;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    fp_vact_space1:10;
    unsigned int    fp_vact_space2:10;
    unsigned int    fp_vact_space3:10;
}ONMS_fp_vact_space;

typedef struct
{
    unsigned int    reserved_0:5;
    unsigned int    r_blank_line_start:11;
    unsigned int    reserved_1:5;
    unsigned int    l_blank_line_end:11;
}ONMS_blank_line;

typedef struct
{
    unsigned int    reserved_0:6;
    unsigned int    vact_space1_end:10;
    unsigned int    reserved_1:6;
    unsigned int    vact_space1_start:10;
}ONMS_active_space1_line_number;

typedef struct
{
    unsigned int    reserved_0:6;
    unsigned int    vact_space2_end:10;
    unsigned int    reserved_1:6;
    unsigned int    vact_space2_start:10;
}ONMS_active_space2_line_number;

typedef struct
{
    unsigned int    reserved_0:6;
    unsigned int    vact_space3_end:10;
    unsigned int    reserved_1:6;
    unsigned int    vact_space3_start:10;
}ONMS_active_space3_line_number;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    vtotalde:12;
    unsigned int    reserved_1:4;
    unsigned int    vtotal:12;
}ONMS_vs_period;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    vs_high_period:12;
    unsigned int    reserved_1:3;
    unsigned int    hs_high_period:13;
}ONMS_vshs_high_period;

typedef struct
{
    unsigned int    hact:13;
    unsigned int    hact_fract:3;
    unsigned int    htotal:13;
    unsigned int    htotal_fract:3;
}ONMS_hs_period;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    vblank_len:8;
    unsigned int    reserved_1:4;
    unsigned int    vact_start:12;
}ONMS_vact_sta;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    vact_space3_min:10;
    unsigned int    vact_space2_min:10;
    unsigned int    vact_space1_min:10;
}ONMS_vact_space_min_value;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    as1_max_end:10;
    unsigned int    as1_max_start:10;
    unsigned int    as1_max_diff:10;
}ONMS_vact_space1_max_info;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    as2_max_end:10;
    unsigned int    as2_max_start:10;
    unsigned int    as2_max_diff:10;
}ONMS_vact_space2_max_info;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    as3_max_end:10;
    unsigned int    as3_max_start:10;
    unsigned int    as3_max_diff:10;
}ONMS_vact_space3_max_info;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    as1_min_end:10;
    unsigned int    as1_min_start:10;
    unsigned int    as1_min_diff:10;
}ONMS_vact_space1_min_info;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    as2_min_end:10;
    unsigned int    as2_min_start:10;
    unsigned int    as2_min_diff:10;
}ONMS_vact_space2_min_info;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    as3_min_end:10;
    unsigned int    as3_min_start:10;
    unsigned int    as3_min_diff:10;
}ONMS_vact_space3_min_info;

typedef struct
{
    unsigned int    reserved_0:13;
    unsigned int    blk_2frame_en:1;
    unsigned int    vs_pol_out:1;
    unsigned int    hs_pol_out:1;
    unsigned int    vs_per_over_range:1;
    unsigned int    hs_per_over_range:1;
    unsigned int    vs_per_timeout:1;
    unsigned int    vs_high_timeout:1;
    unsigned int    vs_per_overflow:1;
    unsigned int    hs_per_overflow:1;
    unsigned int    vs_pol_chg:1;
    unsigned int    hs_pol_chg:1;
    unsigned int    vtotalde_chg:1;
    unsigned int    vtotal_chg:1;
    unsigned int    hact_chg:1;
    unsigned int    htotal_chg:1;
    unsigned int    hs_active_pixel_var:1;
    unsigned int    vact_space3_under_min:1;
    unsigned int    vact_space2_under_min:1;
    unsigned int    vact_space1_under_min:1;
}ONMS_status;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    wd_vs_per_over_range:1;
    unsigned int    wd_hs_per_over_range:1;
    unsigned int    wd_vs_per_timeout:1;
    unsigned int    wd_vs_high_timeout:1;
    unsigned int    wd_vs_per_overflow:1;
    unsigned int    wd_hs_per_overflow:1;
    unsigned int    wd_vs_pol_chg:1;
    unsigned int    wd_hs_pol_chg:1;
    unsigned int    wd_vtotalde_chg:1;
    unsigned int    wd_vtotal_chg:1;
    unsigned int    wd_hact_chg:1;
    unsigned int    wd_htotal_chg:1;
    unsigned int    wd_hs_active_pixel_var:1;
    unsigned int    wd_vact_space3_under_min:1;
    unsigned int    wd_vact_space2_under_min:1;
    unsigned int    wd_vact_space1_under_min:1;
}ONMS_watchdog_en;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    ie_vs_per_over_range:1;
    unsigned int    ie_hs_per_over_range:1;
    unsigned int    ie_vs_per_timeout:1;
    unsigned int    ie_vs_high_timeout:1;
    unsigned int    ie_vs_per_overflow:1;
    unsigned int    ie_hs_per_overflow:1;
    unsigned int    ie_vs_pol_chg:1;
    unsigned int    ie_hs_pol_chg:1;
    unsigned int    ie_vtotalde_chg:1;
    unsigned int    ie_vtotal_chg:1;
    unsigned int    ie_hact_chg:1;
    unsigned int    ie_htotal_chg:1;
    unsigned int    ie_hs_active_pixel_var:1;
    unsigned int    ie_vact_space3_under_min:1;
    unsigned int    ie_vact_space2_under_min:1;
    unsigned int    ie_vact_space1_under_min:1;
}ONMS_interrupt_en;
#endif


#define ONMS_CTRL                                                     0x18005900
#define ONMS_CTRL_reg_addr                                            "0xb8005900"
#define ONMS_CTRL_reg                                                 0xb8005900
#define ONMS_CTRL_inst_addr                                           "0x0240"
#define ONMS_CTRL_inst                                                0x0240
#define ONMS_CTRL_dummy_ctrl_shift                                    (28)
#define ONMS_CTRL_pixel_get_en_shift                                  (27)
#define ONMS_CTRL_pixel_get_sel_shift                                 (25)
#define ONMS_CTRL_progressive_shift                                   (24)
#define ONMS_CTRL_vtotal_max_delta_shift                              (20)
#define ONMS_CTRL_htotal_max_delta_shift                              (16)
#define ONMS_CTRL_pixel_encoding_shift                                (12)
#define ONMS_CTRL_vact_space_threshold_shift                          (8)
#define ONMS_CTRL_vact_space_meas_en_shift                            (7)
#define ONMS_CTRL_meas_to_sel_shift                                   (6)
#define ONMS_CTRL_sycms_clk_shift                                     (5)
#define ONMS_CTRL_vs_meas_inv_shift                                   (4)
#define ONMS_CTRL_hs_meas_inv_shift                                   (3)
#define ONMS_CTRL_popup_meas_shift                                    (2)
#define ONMS_CTRL_ms_conti_shift                                      (1)
#define ONMS_CTRL_start_ms_shift                                      (0)
#define ONMS_CTRL_dummy_ctrl_mask                                     (0xF0000000)
#define ONMS_CTRL_pixel_get_en_mask                                   (0x08000000)
#define ONMS_CTRL_pixel_get_sel_mask                                  (0x06000000)
#define ONMS_CTRL_progressive_mask                                    (0x01000000)
#define ONMS_CTRL_vtotal_max_delta_mask                               (0x00F00000)
#define ONMS_CTRL_htotal_max_delta_mask                               (0x000F0000)
#define ONMS_CTRL_pixel_encoding_mask                                 (0x00001000)
#define ONMS_CTRL_vact_space_threshold_mask                           (0x00000F00)
#define ONMS_CTRL_vact_space_meas_en_mask                             (0x00000080)
#define ONMS_CTRL_meas_to_sel_mask                                    (0x00000040)
#define ONMS_CTRL_sycms_clk_mask                                      (0x00000020)
#define ONMS_CTRL_vs_meas_inv_mask                                    (0x00000010)
#define ONMS_CTRL_hs_meas_inv_mask                                    (0x00000008)
#define ONMS_CTRL_popup_meas_mask                                     (0x00000004)
#define ONMS_CTRL_ms_conti_mask                                       (0x00000002)
#define ONMS_CTRL_start_ms_mask                                       (0x00000001)
#define ONMS_CTRL_dummy_ctrl(data)                                    (0xF0000000&((data)<<28))
#define ONMS_CTRL_pixel_get_en(data)                                  (0x08000000&((data)<<27))
#define ONMS_CTRL_pixel_get_sel(data)                                 (0x06000000&((data)<<25))
#define ONMS_CTRL_progressive(data)                                   (0x01000000&((data)<<24))
#define ONMS_CTRL_vtotal_max_delta(data)                              (0x00F00000&((data)<<20))
#define ONMS_CTRL_htotal_max_delta(data)                              (0x000F0000&((data)<<16))
#define ONMS_CTRL_pixel_encoding(data)                                (0x00001000&((data)<<12))
#define ONMS_CTRL_vact_space_threshold(data)                          (0x00000F00&((data)<<8))
#define ONMS_CTRL_vact_space_meas_en(data)                            (0x00000080&((data)<<7))
#define ONMS_CTRL_meas_to_sel(data)                                   (0x00000040&((data)<<6))
#define ONMS_CTRL_sycms_clk(data)                                     (0x00000020&((data)<<5))
#define ONMS_CTRL_vs_meas_inv(data)                                   (0x00000010&((data)<<4))
#define ONMS_CTRL_hs_meas_inv(data)                                   (0x00000008&((data)<<3))
#define ONMS_CTRL_popup_meas(data)                                    (0x00000004&((data)<<2))
#define ONMS_CTRL_ms_conti(data)                                      (0x00000002&((data)<<1))
#define ONMS_CTRL_start_ms(data)                                      (0x00000001&(data))
#define ONMS_CTRL_get_dummy_ctrl(data)                                ((0xF0000000&(data))>>28)
#define ONMS_CTRL_get_pixel_get_en(data)                              ((0x08000000&(data))>>27)
#define ONMS_CTRL_get_pixel_get_sel(data)                             ((0x06000000&(data))>>25)
#define ONMS_CTRL_get_progressive(data)                               ((0x01000000&(data))>>24)
#define ONMS_CTRL_get_vtotal_max_delta(data)                          ((0x00F00000&(data))>>20)
#define ONMS_CTRL_get_htotal_max_delta(data)                          ((0x000F0000&(data))>>16)
#define ONMS_CTRL_get_pixel_encoding(data)                            ((0x00001000&(data))>>12)
#define ONMS_CTRL_get_vact_space_threshold(data)                      ((0x00000F00&(data))>>8)
#define ONMS_CTRL_get_vact_space_meas_en(data)                        ((0x00000080&(data))>>7)
#define ONMS_CTRL_get_meas_to_sel(data)                               ((0x00000040&(data))>>6)
#define ONMS_CTRL_get_sycms_clk(data)                                 ((0x00000020&(data))>>5)
#define ONMS_CTRL_get_vs_meas_inv(data)                               ((0x00000010&(data))>>4)
#define ONMS_CTRL_get_hs_meas_inv(data)                               ((0x00000008&(data))>>3)
#define ONMS_CTRL_get_popup_meas(data)                                ((0x00000004&(data))>>2)
#define ONMS_CTRL_get_ms_conti(data)                                  ((0x00000002&(data))>>1)
#define ONMS_CTRL_get_start_ms(data)                                  (0x00000001&(data))


#define ONMS_BLANK_PIXEL_VALUE_GET_0                                  0x18005904
#define ONMS_BLANK_PIXEL_VALUE_GET_0_reg_addr                         "0xb8005904"
#define ONMS_BLANK_PIXEL_VALUE_GET_0_reg                              0xb8005904
#define ONMS_BLANK_PIXEL_VALUE_GET_0_inst_addr                        "0x0241"
#define ONMS_BLANK_PIXEL_VALUE_GET_0_inst                             0x0241
#define ONMS_BLANK_PIXEL_VALUE_GET_0_pixel_ok_shift                   (24)
#define ONMS_BLANK_PIXEL_VALUE_GET_0_get_r_value_shift                (12)
#define ONMS_BLANK_PIXEL_VALUE_GET_0_get_g_value_shift                (0)
#define ONMS_BLANK_PIXEL_VALUE_GET_0_pixel_ok_mask                    (0x01000000)
#define ONMS_BLANK_PIXEL_VALUE_GET_0_get_r_value_mask                 (0x00FFF000)
#define ONMS_BLANK_PIXEL_VALUE_GET_0_get_g_value_mask                 (0x00000FFF)
#define ONMS_BLANK_PIXEL_VALUE_GET_0_pixel_ok(data)                   (0x01000000&((data)<<24))
#define ONMS_BLANK_PIXEL_VALUE_GET_0_get_r_value(data)                (0x00FFF000&((data)<<12))
#define ONMS_BLANK_PIXEL_VALUE_GET_0_get_g_value(data)                (0x00000FFF&(data))
#define ONMS_BLANK_PIXEL_VALUE_GET_0_get_pixel_ok(data)               ((0x01000000&(data))>>24)
#define ONMS_BLANK_PIXEL_VALUE_GET_0_get_get_r_value(data)            ((0x00FFF000&(data))>>12)
#define ONMS_BLANK_PIXEL_VALUE_GET_0_get_get_g_value(data)            (0x00000FFF&(data))


#define ONMS_BLANK_PIXEL_VALUE_GET_1                                  0x18005908
#define ONMS_BLANK_PIXEL_VALUE_GET_1_reg_addr                         "0xb8005908"
#define ONMS_BLANK_PIXEL_VALUE_GET_1_reg                              0xb8005908
#define ONMS_BLANK_PIXEL_VALUE_GET_1_inst_addr                        "0x0242"
#define ONMS_BLANK_PIXEL_VALUE_GET_1_inst                             0x0242
#define ONMS_BLANK_PIXEL_VALUE_GET_1_get_b_value_shift                (0)
#define ONMS_BLANK_PIXEL_VALUE_GET_1_get_b_value_mask                 (0x00000FFF)
#define ONMS_BLANK_PIXEL_VALUE_GET_1_get_b_value(data)                (0x00000FFF&(data))
#define ONMS_BLANK_PIXEL_VALUE_GET_1_get_get_b_value(data)            (0x00000FFF&(data))


#define ONMS_BLANK_PIXEL_VALUE_0                                      0x1800590c
#define ONMS_BLANK_PIXEL_VALUE_0_reg_addr                             "0xb800590c"
#define ONMS_BLANK_PIXEL_VALUE_0_reg                                  0xb800590c
#define ONMS_BLANK_PIXEL_VALUE_0_inst_addr                            "0x0243"
#define ONMS_BLANK_PIXEL_VALUE_0_inst                                 0x0243
#define ONMS_BLANK_PIXEL_VALUE_0_active_r_value_shift                 (12)
#define ONMS_BLANK_PIXEL_VALUE_0_active_g_value_shift                 (0)
#define ONMS_BLANK_PIXEL_VALUE_0_active_r_value_mask                  (0x00FFF000)
#define ONMS_BLANK_PIXEL_VALUE_0_active_g_value_mask                  (0x00000FFF)
#define ONMS_BLANK_PIXEL_VALUE_0_active_r_value(data)                 (0x00FFF000&((data)<<12))
#define ONMS_BLANK_PIXEL_VALUE_0_active_g_value(data)                 (0x00000FFF&(data))
#define ONMS_BLANK_PIXEL_VALUE_0_get_active_r_value(data)             ((0x00FFF000&(data))>>12)
#define ONMS_BLANK_PIXEL_VALUE_0_get_active_g_value(data)             (0x00000FFF&(data))


#define ONMS_BLANK_PIXEL_VALUE_1                                      0x18005910
#define ONMS_BLANK_PIXEL_VALUE_1_reg_addr                             "0xb8005910"
#define ONMS_BLANK_PIXEL_VALUE_1_reg                                  0xb8005910
#define ONMS_BLANK_PIXEL_VALUE_1_inst_addr                            "0x0244"
#define ONMS_BLANK_PIXEL_VALUE_1_inst                                 0x0244
#define ONMS_BLANK_PIXEL_VALUE_1_active_b_value_shift                 (0)
#define ONMS_BLANK_PIXEL_VALUE_1_active_b_value_mask                  (0x00000FFF)
#define ONMS_BLANK_PIXEL_VALUE_1_active_b_value(data)                 (0x00000FFF&(data))
#define ONMS_BLANK_PIXEL_VALUE_1_get_active_b_value(data)             (0x00000FFF&(data))


#define ONMS_FP_VACT12                                                0x18005914
#define ONMS_FP_VACT12_reg_addr                                       "0xb8005914"
#define ONMS_FP_VACT12_reg                                            0xb8005914
#define ONMS_FP_VACT12_inst_addr                                      "0x0245"
#define ONMS_FP_VACT12_inst                                           0x0245
#define ONMS_FP_VACT12_vact2_shift                                    (16)
#define ONMS_FP_VACT12_vact1_shift                                    (0)
#define ONMS_FP_VACT12_vact2_mask                                     (0x07FF0000)
#define ONMS_FP_VACT12_vact1_mask                                     (0x000007FF)
#define ONMS_FP_VACT12_vact2(data)                                    (0x07FF0000&((data)<<16))
#define ONMS_FP_VACT12_vact1(data)                                    (0x000007FF&(data))
#define ONMS_FP_VACT12_get_vact2(data)                                ((0x07FF0000&(data))>>16)
#define ONMS_FP_VACT12_get_vact1(data)                                (0x000007FF&(data))


#define ONMS_FP_VACT34                                                0x18005918
#define ONMS_FP_VACT34_reg_addr                                       "0xb8005918"
#define ONMS_FP_VACT34_reg                                            0xb8005918
#define ONMS_FP_VACT34_inst_addr                                      "0x0246"
#define ONMS_FP_VACT34_inst                                           0x0246
#define ONMS_FP_VACT34_vact4_shift                                    (16)
#define ONMS_FP_VACT34_vact3_shift                                    (0)
#define ONMS_FP_VACT34_vact4_mask                                     (0x07FF0000)
#define ONMS_FP_VACT34_vact3_mask                                     (0x000007FF)
#define ONMS_FP_VACT34_vact4(data)                                    (0x07FF0000&((data)<<16))
#define ONMS_FP_VACT34_vact3(data)                                    (0x000007FF&(data))
#define ONMS_FP_VACT34_get_vact4(data)                                ((0x07FF0000&(data))>>16)
#define ONMS_FP_VACT34_get_vact3(data)                                (0x000007FF&(data))


#define ONMS_FP_VACT_SPACE                                            0x1800591c
#define ONMS_FP_VACT_SPACE_reg_addr                                   "0xb800591c"
#define ONMS_FP_VACT_SPACE_reg                                        0xb800591c
#define ONMS_FP_VACT_SPACE_inst_addr                                  "0x0247"
#define ONMS_FP_VACT_SPACE_inst                                       0x0247
#define ONMS_FP_VACT_SPACE_fp_vact_space1_shift                       (20)
#define ONMS_FP_VACT_SPACE_fp_vact_space2_shift                       (10)
#define ONMS_FP_VACT_SPACE_fp_vact_space3_shift                       (0)
#define ONMS_FP_VACT_SPACE_fp_vact_space1_mask                        (0x3FF00000)
#define ONMS_FP_VACT_SPACE_fp_vact_space2_mask                        (0x000FFC00)
#define ONMS_FP_VACT_SPACE_fp_vact_space3_mask                        (0x000003FF)
#define ONMS_FP_VACT_SPACE_fp_vact_space1(data)                       (0x3FF00000&((data)<<20))
#define ONMS_FP_VACT_SPACE_fp_vact_space2(data)                       (0x000FFC00&((data)<<10))
#define ONMS_FP_VACT_SPACE_fp_vact_space3(data)                       (0x000003FF&(data))
#define ONMS_FP_VACT_SPACE_get_fp_vact_space1(data)                   ((0x3FF00000&(data))>>20)
#define ONMS_FP_VACT_SPACE_get_fp_vact_space2(data)                   ((0x000FFC00&(data))>>10)
#define ONMS_FP_VACT_SPACE_get_fp_vact_space3(data)                   (0x000003FF&(data))


#define ONMS_BLANK_LINE                                               0x18005920
#define ONMS_BLANK_LINE_reg_addr                                      "0xb8005920"
#define ONMS_BLANK_LINE_reg                                           0xb8005920
#define ONMS_BLANK_LINE_inst_addr                                     "0x0248"
#define ONMS_BLANK_LINE_inst                                          0x0248
#define ONMS_BLANK_LINE_r_blank_line_start_shift                      (16)
#define ONMS_BLANK_LINE_l_blank_line_end_shift                        (0)
#define ONMS_BLANK_LINE_r_blank_line_start_mask                       (0x07FF0000)
#define ONMS_BLANK_LINE_l_blank_line_end_mask                         (0x000007FF)
#define ONMS_BLANK_LINE_r_blank_line_start(data)                      (0x07FF0000&((data)<<16))
#define ONMS_BLANK_LINE_l_blank_line_end(data)                        (0x000007FF&(data))
#define ONMS_BLANK_LINE_get_r_blank_line_start(data)                  ((0x07FF0000&(data))>>16)
#define ONMS_BLANK_LINE_get_l_blank_line_end(data)                    (0x000007FF&(data))


#define ONMS_ACTIVE_SPACE1_LINE_NUMBER                                0x18005924
#define ONMS_ACTIVE_SPACE1_LINE_NUMBER_reg_addr                       "0xb8005924"
#define ONMS_ACTIVE_SPACE1_LINE_NUMBER_reg                            0xb8005924
#define ONMS_ACTIVE_SPACE1_LINE_NUMBER_inst_addr                      "0x0249"
#define ONMS_ACTIVE_SPACE1_LINE_NUMBER_inst                           0x0249
#define ONMS_ACTIVE_SPACE1_LINE_NUMBER_vact_space1_end_shift          (16)
#define ONMS_ACTIVE_SPACE1_LINE_NUMBER_vact_space1_start_shift        (0)
#define ONMS_ACTIVE_SPACE1_LINE_NUMBER_vact_space1_end_mask           (0x03FF0000)
#define ONMS_ACTIVE_SPACE1_LINE_NUMBER_vact_space1_start_mask         (0x000003FF)
#define ONMS_ACTIVE_SPACE1_LINE_NUMBER_vact_space1_end(data)          (0x03FF0000&((data)<<16))
#define ONMS_ACTIVE_SPACE1_LINE_NUMBER_vact_space1_start(data)        (0x000003FF&(data))
#define ONMS_ACTIVE_SPACE1_LINE_NUMBER_get_vact_space1_end(data)      ((0x03FF0000&(data))>>16)
#define ONMS_ACTIVE_SPACE1_LINE_NUMBER_get_vact_space1_start(data)    (0x000003FF&(data))


#define ONMS_ACTIVE_SPACE2_LINE_NUMBER                                0x18005928
#define ONMS_ACTIVE_SPACE2_LINE_NUMBER_reg_addr                       "0xb8005928"
#define ONMS_ACTIVE_SPACE2_LINE_NUMBER_reg                            0xb8005928
#define ONMS_ACTIVE_SPACE2_LINE_NUMBER_inst_addr                      "0x024A"
#define ONMS_ACTIVE_SPACE2_LINE_NUMBER_inst                           0x024A
#define ONMS_ACTIVE_SPACE2_LINE_NUMBER_vact_space2_end_shift          (16)
#define ONMS_ACTIVE_SPACE2_LINE_NUMBER_vact_space2_start_shift        (0)
#define ONMS_ACTIVE_SPACE2_LINE_NUMBER_vact_space2_end_mask           (0x03FF0000)
#define ONMS_ACTIVE_SPACE2_LINE_NUMBER_vact_space2_start_mask         (0x000003FF)
#define ONMS_ACTIVE_SPACE2_LINE_NUMBER_vact_space2_end(data)          (0x03FF0000&((data)<<16))
#define ONMS_ACTIVE_SPACE2_LINE_NUMBER_vact_space2_start(data)        (0x000003FF&(data))
#define ONMS_ACTIVE_SPACE2_LINE_NUMBER_get_vact_space2_end(data)      ((0x03FF0000&(data))>>16)
#define ONMS_ACTIVE_SPACE2_LINE_NUMBER_get_vact_space2_start(data)    (0x000003FF&(data))


#define ONMS_ACTIVE_SPACE3_LINE_NUMBER                                0x1800592c
#define ONMS_ACTIVE_SPACE3_LINE_NUMBER_reg_addr                       "0xb800592c"
#define ONMS_ACTIVE_SPACE3_LINE_NUMBER_reg                            0xb800592c
#define ONMS_ACTIVE_SPACE3_LINE_NUMBER_inst_addr                      "0x024B"
#define ONMS_ACTIVE_SPACE3_LINE_NUMBER_inst                           0x024B
#define ONMS_ACTIVE_SPACE3_LINE_NUMBER_vact_space3_end_shift          (16)
#define ONMS_ACTIVE_SPACE3_LINE_NUMBER_vact_space3_start_shift        (0)
#define ONMS_ACTIVE_SPACE3_LINE_NUMBER_vact_space3_end_mask           (0x03FF0000)
#define ONMS_ACTIVE_SPACE3_LINE_NUMBER_vact_space3_start_mask         (0x000003FF)
#define ONMS_ACTIVE_SPACE3_LINE_NUMBER_vact_space3_end(data)          (0x03FF0000&((data)<<16))
#define ONMS_ACTIVE_SPACE3_LINE_NUMBER_vact_space3_start(data)        (0x000003FF&(data))
#define ONMS_ACTIVE_SPACE3_LINE_NUMBER_get_vact_space3_end(data)      ((0x03FF0000&(data))>>16)
#define ONMS_ACTIVE_SPACE3_LINE_NUMBER_get_vact_space3_start(data)    (0x000003FF&(data))


#define ONMS_VS_PERIOD                                                0x18005930
#define ONMS_VS_PERIOD_reg_addr                                       "0xb8005930"
#define ONMS_VS_PERIOD_reg                                            0xb8005930
#define ONMS_VS_PERIOD_inst_addr                                      "0x024C"
#define ONMS_VS_PERIOD_inst                                           0x024C
#define ONMS_VS_PERIOD_vtotalde_shift                                 (16)
#define ONMS_VS_PERIOD_vtotal_shift                                   (0)
#define ONMS_VS_PERIOD_vtotalde_mask                                  (0x0FFF0000)
#define ONMS_VS_PERIOD_vtotal_mask                                    (0x00000FFF)
#define ONMS_VS_PERIOD_vtotalde(data)                                 (0x0FFF0000&((data)<<16))
#define ONMS_VS_PERIOD_vtotal(data)                                   (0x00000FFF&(data))
#define ONMS_VS_PERIOD_get_vtotalde(data)                             ((0x0FFF0000&(data))>>16)
#define ONMS_VS_PERIOD_get_vtotal(data)                               (0x00000FFF&(data))


#define ONMS_VSHS_HIGH_PERIOD                                         0x18005934
#define ONMS_VSHS_HIGH_PERIOD_reg_addr                                "0xb8005934"
#define ONMS_VSHS_HIGH_PERIOD_reg                                     0xb8005934
#define ONMS_VSHS_HIGH_PERIOD_inst_addr                               "0x024D"
#define ONMS_VSHS_HIGH_PERIOD_inst                                    0x024D
#define ONMS_VSHS_HIGH_PERIOD_vs_high_period_shift                    (16)
#define ONMS_VSHS_HIGH_PERIOD_hs_high_period_shift                    (0)
#define ONMS_VSHS_HIGH_PERIOD_vs_high_period_mask                     (0x0FFF0000)
#define ONMS_VSHS_HIGH_PERIOD_hs_high_period_mask                     (0x00001FFF)
#define ONMS_VSHS_HIGH_PERIOD_vs_high_period(data)                    (0x0FFF0000&((data)<<16))
#define ONMS_VSHS_HIGH_PERIOD_hs_high_period(data)                    (0x00001FFF&(data))
#define ONMS_VSHS_HIGH_PERIOD_get_vs_high_period(data)                ((0x0FFF0000&(data))>>16)
#define ONMS_VSHS_HIGH_PERIOD_get_hs_high_period(data)                (0x00001FFF&(data))


#define ONMS_HS_PERIOD                                                0x18005938
#define ONMS_HS_PERIOD_reg_addr                                       "0xb8005938"
#define ONMS_HS_PERIOD_reg                                            0xb8005938
#define ONMS_HS_PERIOD_inst_addr                                      "0x024E"
#define ONMS_HS_PERIOD_inst                                           0x024E
#define ONMS_HS_PERIOD_hact_shift                                     (19)
#define ONMS_HS_PERIOD_hact_fract_shift                               (16)
#define ONMS_HS_PERIOD_htotal_shift                                   (3)
#define ONMS_HS_PERIOD_htotal_fract_shift                             (0)
#define ONMS_HS_PERIOD_hact_mask                                      (0xFFF80000)
#define ONMS_HS_PERIOD_hact_fract_mask                                (0x00070000)
#define ONMS_HS_PERIOD_htotal_mask                                    (0x0000FFF8)
#define ONMS_HS_PERIOD_htotal_fract_mask                              (0x00000007)
#define ONMS_HS_PERIOD_hact(data)                                     (0xFFF80000&((data)<<19))
#define ONMS_HS_PERIOD_hact_fract(data)                               (0x00070000&((data)<<16))
#define ONMS_HS_PERIOD_htotal(data)                                   (0x0000FFF8&((data)<<3))
#define ONMS_HS_PERIOD_htotal_fract(data)                             (0x00000007&(data))
#define ONMS_HS_PERIOD_get_hact(data)                                 ((0xFFF80000&(data))>>19)
#define ONMS_HS_PERIOD_get_hact_fract(data)                           ((0x00070000&(data))>>16)
#define ONMS_HS_PERIOD_get_htotal(data)                               ((0x0000FFF8&(data))>>3)
#define ONMS_HS_PERIOD_get_htotal_fract(data)                         (0x00000007&(data))


#define ONMS_VACT_STA                                                 0x1800593c
#define ONMS_VACT_STA_reg_addr                                        "0xb800593c"
#define ONMS_VACT_STA_reg                                             0xb800593c
#define ONMS_VACT_STA_inst_addr                                       "0x024F"
#define ONMS_VACT_STA_inst                                            0x024F
#define ONMS_VACT_STA_vblank_len_shift                                (16)
#define ONMS_VACT_STA_vact_start_shift                                (0)
#define ONMS_VACT_STA_vblank_len_mask                                 (0x00FF0000)
#define ONMS_VACT_STA_vact_start_mask                                 (0x00000FFF)
#define ONMS_VACT_STA_vblank_len(data)                                (0x00FF0000&((data)<<16))
#define ONMS_VACT_STA_vact_start(data)                                (0x00000FFF&(data))
#define ONMS_VACT_STA_get_vblank_len(data)                            ((0x00FF0000&(data))>>16)
#define ONMS_VACT_STA_get_vact_start(data)                            (0x00000FFF&(data))


#define ONMS_VACT_SPACE_MIN_VALUE                                     0x18005940
#define ONMS_VACT_SPACE_MIN_VALUE_reg_addr                            "0xb8005940"
#define ONMS_VACT_SPACE_MIN_VALUE_reg                                 0xb8005940
#define ONMS_VACT_SPACE_MIN_VALUE_inst_addr                           "0x0250"
#define ONMS_VACT_SPACE_MIN_VALUE_inst                                0x0250
#define ONMS_VACT_SPACE_MIN_VALUE_vact_space3_min_shift               (20)
#define ONMS_VACT_SPACE_MIN_VALUE_vact_space2_min_shift               (10)
#define ONMS_VACT_SPACE_MIN_VALUE_vact_space1_min_shift               (0)
#define ONMS_VACT_SPACE_MIN_VALUE_vact_space3_min_mask                (0x3FF00000)
#define ONMS_VACT_SPACE_MIN_VALUE_vact_space2_min_mask                (0x000FFC00)
#define ONMS_VACT_SPACE_MIN_VALUE_vact_space1_min_mask                (0x000003FF)
#define ONMS_VACT_SPACE_MIN_VALUE_vact_space3_min(data)               (0x3FF00000&((data)<<20))
#define ONMS_VACT_SPACE_MIN_VALUE_vact_space2_min(data)               (0x000FFC00&((data)<<10))
#define ONMS_VACT_SPACE_MIN_VALUE_vact_space1_min(data)               (0x000003FF&(data))
#define ONMS_VACT_SPACE_MIN_VALUE_get_vact_space3_min(data)           ((0x3FF00000&(data))>>20)
#define ONMS_VACT_SPACE_MIN_VALUE_get_vact_space2_min(data)           ((0x000FFC00&(data))>>10)
#define ONMS_VACT_SPACE_MIN_VALUE_get_vact_space1_min(data)           (0x000003FF&(data))


#define ONMS_VACT_SPACE1_MAX_INFO                                     0x18005944
#define ONMS_VACT_SPACE1_MAX_INFO_reg_addr                            "0xb8005944"
#define ONMS_VACT_SPACE1_MAX_INFO_reg                                 0xb8005944
#define ONMS_VACT_SPACE1_MAX_INFO_inst_addr                           "0x0251"
#define ONMS_VACT_SPACE1_MAX_INFO_inst                                0x0251
#define ONMS_VACT_SPACE1_MAX_INFO_as1_max_end_shift                   (20)
#define ONMS_VACT_SPACE1_MAX_INFO_as1_max_start_shift                 (10)
#define ONMS_VACT_SPACE1_MAX_INFO_as1_max_diff_shift                  (0)
#define ONMS_VACT_SPACE1_MAX_INFO_as1_max_end_mask                    (0x3FF00000)
#define ONMS_VACT_SPACE1_MAX_INFO_as1_max_start_mask                  (0x000FFC00)
#define ONMS_VACT_SPACE1_MAX_INFO_as1_max_diff_mask                   (0x000003FF)
#define ONMS_VACT_SPACE1_MAX_INFO_as1_max_end(data)                   (0x3FF00000&((data)<<20))
#define ONMS_VACT_SPACE1_MAX_INFO_as1_max_start(data)                 (0x000FFC00&((data)<<10))
#define ONMS_VACT_SPACE1_MAX_INFO_as1_max_diff(data)                  (0x000003FF&(data))
#define ONMS_VACT_SPACE1_MAX_INFO_get_as1_max_end(data)               ((0x3FF00000&(data))>>20)
#define ONMS_VACT_SPACE1_MAX_INFO_get_as1_max_start(data)             ((0x000FFC00&(data))>>10)
#define ONMS_VACT_SPACE1_MAX_INFO_get_as1_max_diff(data)              (0x000003FF&(data))


#define ONMS_VACT_SPACE2_MAX_INFO                                     0x18005948
#define ONMS_VACT_SPACE2_MAX_INFO_reg_addr                            "0xb8005948"
#define ONMS_VACT_SPACE2_MAX_INFO_reg                                 0xb8005948
#define ONMS_VACT_SPACE2_MAX_INFO_inst_addr                           "0x0252"
#define ONMS_VACT_SPACE2_MAX_INFO_inst                                0x0252
#define ONMS_VACT_SPACE2_MAX_INFO_as2_max_end_shift                   (20)
#define ONMS_VACT_SPACE2_MAX_INFO_as2_max_start_shift                 (10)
#define ONMS_VACT_SPACE2_MAX_INFO_as2_max_diff_shift                  (0)
#define ONMS_VACT_SPACE2_MAX_INFO_as2_max_end_mask                    (0x3FF00000)
#define ONMS_VACT_SPACE2_MAX_INFO_as2_max_start_mask                  (0x000FFC00)
#define ONMS_VACT_SPACE2_MAX_INFO_as2_max_diff_mask                   (0x000003FF)
#define ONMS_VACT_SPACE2_MAX_INFO_as2_max_end(data)                   (0x3FF00000&((data)<<20))
#define ONMS_VACT_SPACE2_MAX_INFO_as2_max_start(data)                 (0x000FFC00&((data)<<10))
#define ONMS_VACT_SPACE2_MAX_INFO_as2_max_diff(data)                  (0x000003FF&(data))
#define ONMS_VACT_SPACE2_MAX_INFO_get_as2_max_end(data)               ((0x3FF00000&(data))>>20)
#define ONMS_VACT_SPACE2_MAX_INFO_get_as2_max_start(data)             ((0x000FFC00&(data))>>10)
#define ONMS_VACT_SPACE2_MAX_INFO_get_as2_max_diff(data)              (0x000003FF&(data))


#define ONMS_VACT_SPACE3_MAX_INFO                                     0x1800594c
#define ONMS_VACT_SPACE3_MAX_INFO_reg_addr                            "0xb800594c"
#define ONMS_VACT_SPACE3_MAX_INFO_reg                                 0xb800594c
#define ONMS_VACT_SPACE3_MAX_INFO_inst_addr                           "0x0253"
#define ONMS_VACT_SPACE3_MAX_INFO_inst                                0x0253
#define ONMS_VACT_SPACE3_MAX_INFO_as3_max_end_shift                   (20)
#define ONMS_VACT_SPACE3_MAX_INFO_as3_max_start_shift                 (10)
#define ONMS_VACT_SPACE3_MAX_INFO_as3_max_diff_shift                  (0)
#define ONMS_VACT_SPACE3_MAX_INFO_as3_max_end_mask                    (0x3FF00000)
#define ONMS_VACT_SPACE3_MAX_INFO_as3_max_start_mask                  (0x000FFC00)
#define ONMS_VACT_SPACE3_MAX_INFO_as3_max_diff_mask                   (0x000003FF)
#define ONMS_VACT_SPACE3_MAX_INFO_as3_max_end(data)                   (0x3FF00000&((data)<<20))
#define ONMS_VACT_SPACE3_MAX_INFO_as3_max_start(data)                 (0x000FFC00&((data)<<10))
#define ONMS_VACT_SPACE3_MAX_INFO_as3_max_diff(data)                  (0x000003FF&(data))
#define ONMS_VACT_SPACE3_MAX_INFO_get_as3_max_end(data)               ((0x3FF00000&(data))>>20)
#define ONMS_VACT_SPACE3_MAX_INFO_get_as3_max_start(data)             ((0x000FFC00&(data))>>10)
#define ONMS_VACT_SPACE3_MAX_INFO_get_as3_max_diff(data)              (0x000003FF&(data))


#define ONMS_VACT_SPACE1_MIN_INFO                                     0x18005950
#define ONMS_VACT_SPACE1_MIN_INFO_reg_addr                            "0xb8005950"
#define ONMS_VACT_SPACE1_MIN_INFO_reg                                 0xb8005950
#define ONMS_VACT_SPACE1_MIN_INFO_inst_addr                           "0x0254"
#define ONMS_VACT_SPACE1_MIN_INFO_inst                                0x0254
#define ONMS_VACT_SPACE1_MIN_INFO_as1_min_end_shift                   (20)
#define ONMS_VACT_SPACE1_MIN_INFO_as1_min_start_shift                 (10)
#define ONMS_VACT_SPACE1_MIN_INFO_as1_min_diff_shift                  (0)
#define ONMS_VACT_SPACE1_MIN_INFO_as1_min_end_mask                    (0x3FF00000)
#define ONMS_VACT_SPACE1_MIN_INFO_as1_min_start_mask                  (0x000FFC00)
#define ONMS_VACT_SPACE1_MIN_INFO_as1_min_diff_mask                   (0x000003FF)
#define ONMS_VACT_SPACE1_MIN_INFO_as1_min_end(data)                   (0x3FF00000&((data)<<20))
#define ONMS_VACT_SPACE1_MIN_INFO_as1_min_start(data)                 (0x000FFC00&((data)<<10))
#define ONMS_VACT_SPACE1_MIN_INFO_as1_min_diff(data)                  (0x000003FF&(data))
#define ONMS_VACT_SPACE1_MIN_INFO_get_as1_min_end(data)               ((0x3FF00000&(data))>>20)
#define ONMS_VACT_SPACE1_MIN_INFO_get_as1_min_start(data)             ((0x000FFC00&(data))>>10)
#define ONMS_VACT_SPACE1_MIN_INFO_get_as1_min_diff(data)              (0x000003FF&(data))


#define ONMS_VACT_SPACE2_MIN_INFO                                     0x18005954
#define ONMS_VACT_SPACE2_MIN_INFO_reg_addr                            "0xb8005954"
#define ONMS_VACT_SPACE2_MIN_INFO_reg                                 0xb8005954
#define ONMS_VACT_SPACE2_MIN_INFO_inst_addr                           "0x0255"
#define ONMS_VACT_SPACE2_MIN_INFO_inst                                0x0255
#define ONMS_VACT_SPACE2_MIN_INFO_as2_min_end_shift                   (20)
#define ONMS_VACT_SPACE2_MIN_INFO_as2_min_start_shift                 (10)
#define ONMS_VACT_SPACE2_MIN_INFO_as2_min_diff_shift                  (0)
#define ONMS_VACT_SPACE2_MIN_INFO_as2_min_end_mask                    (0x3FF00000)
#define ONMS_VACT_SPACE2_MIN_INFO_as2_min_start_mask                  (0x000FFC00)
#define ONMS_VACT_SPACE2_MIN_INFO_as2_min_diff_mask                   (0x000003FF)
#define ONMS_VACT_SPACE2_MIN_INFO_as2_min_end(data)                   (0x3FF00000&((data)<<20))
#define ONMS_VACT_SPACE2_MIN_INFO_as2_min_start(data)                 (0x000FFC00&((data)<<10))
#define ONMS_VACT_SPACE2_MIN_INFO_as2_min_diff(data)                  (0x000003FF&(data))
#define ONMS_VACT_SPACE2_MIN_INFO_get_as2_min_end(data)               ((0x3FF00000&(data))>>20)
#define ONMS_VACT_SPACE2_MIN_INFO_get_as2_min_start(data)             ((0x000FFC00&(data))>>10)
#define ONMS_VACT_SPACE2_MIN_INFO_get_as2_min_diff(data)              (0x000003FF&(data))


#define ONMS_VACT_SPACE3_MIN_INFO                                     0x18005958
#define ONMS_VACT_SPACE3_MIN_INFO_reg_addr                            "0xb8005958"
#define ONMS_VACT_SPACE3_MIN_INFO_reg                                 0xb8005958
#define ONMS_VACT_SPACE3_MIN_INFO_inst_addr                           "0x0256"
#define ONMS_VACT_SPACE3_MIN_INFO_inst                                0x0256
#define ONMS_VACT_SPACE3_MIN_INFO_as3_min_end_shift                   (20)
#define ONMS_VACT_SPACE3_MIN_INFO_as3_min_start_shift                 (10)
#define ONMS_VACT_SPACE3_MIN_INFO_as3_min_diff_shift                  (0)
#define ONMS_VACT_SPACE3_MIN_INFO_as3_min_end_mask                    (0x3FF00000)
#define ONMS_VACT_SPACE3_MIN_INFO_as3_min_start_mask                  (0x000FFC00)
#define ONMS_VACT_SPACE3_MIN_INFO_as3_min_diff_mask                   (0x000003FF)
#define ONMS_VACT_SPACE3_MIN_INFO_as3_min_end(data)                   (0x3FF00000&((data)<<20))
#define ONMS_VACT_SPACE3_MIN_INFO_as3_min_start(data)                 (0x000FFC00&((data)<<10))
#define ONMS_VACT_SPACE3_MIN_INFO_as3_min_diff(data)                  (0x000003FF&(data))
#define ONMS_VACT_SPACE3_MIN_INFO_get_as3_min_end(data)               ((0x3FF00000&(data))>>20)
#define ONMS_VACT_SPACE3_MIN_INFO_get_as3_min_start(data)             ((0x000FFC00&(data))>>10)
#define ONMS_VACT_SPACE3_MIN_INFO_get_as3_min_diff(data)              (0x000003FF&(data))


#define ONMS_STATUS                                                   0x1800595c
#define ONMS_STATUS_reg_addr                                          "0xb800595c"
#define ONMS_STATUS_reg                                               0xb800595c
#define ONMS_STATUS_inst_addr                                         "0x0257"
#define ONMS_STATUS_inst                                              0x0257
#define ONMS_STATUS_blk_2frame_en_shift                               (18)
#define ONMS_STATUS_vs_pol_out_shift                                  (17)
#define ONMS_STATUS_hs_pol_out_shift                                  (16)
#define ONMS_STATUS_vs_per_over_range_shift                           (15)
#define ONMS_STATUS_hs_per_over_range_shift                           (14)
#define ONMS_STATUS_vs_per_timeout_shift                              (13)
#define ONMS_STATUS_vs_high_timeout_shift                             (12)
#define ONMS_STATUS_vs_per_overflow_shift                             (11)
#define ONMS_STATUS_hs_per_overflow_shift                             (10)
#define ONMS_STATUS_vs_pol_chg_shift                                  (9)
#define ONMS_STATUS_hs_pol_chg_shift                                  (8)
#define ONMS_STATUS_vtotalde_chg_shift                                (7)
#define ONMS_STATUS_vtotal_chg_shift                                  (6)
#define ONMS_STATUS_hact_chg_shift                                    (5)
#define ONMS_STATUS_htotal_chg_shift                                  (4)
#define ONMS_STATUS_hs_active_pixel_var_shift                         (3)
#define ONMS_STATUS_vact_space3_under_min_shift                       (2)
#define ONMS_STATUS_vact_space2_under_min_shift                       (1)
#define ONMS_STATUS_vact_space1_under_min_shift                       (0)
#define ONMS_STATUS_blk_2frame_en_mask                                (0x00040000)
#define ONMS_STATUS_vs_pol_out_mask                                   (0x00020000)
#define ONMS_STATUS_hs_pol_out_mask                                   (0x00010000)
#define ONMS_STATUS_vs_per_over_range_mask                            (0x00008000)
#define ONMS_STATUS_hs_per_over_range_mask                            (0x00004000)
#define ONMS_STATUS_vs_per_timeout_mask                               (0x00002000)
#define ONMS_STATUS_vs_high_timeout_mask                              (0x00001000)
#define ONMS_STATUS_vs_per_overflow_mask                              (0x00000800)
#define ONMS_STATUS_hs_per_overflow_mask                              (0x00000400)
#define ONMS_STATUS_vs_pol_chg_mask                                   (0x00000200)
#define ONMS_STATUS_hs_pol_chg_mask                                   (0x00000100)
#define ONMS_STATUS_vtotalde_chg_mask                                 (0x00000080)
#define ONMS_STATUS_vtotal_chg_mask                                   (0x00000040)
#define ONMS_STATUS_hact_chg_mask                                     (0x00000020)
#define ONMS_STATUS_htotal_chg_mask                                   (0x00000010)
#define ONMS_STATUS_hs_active_pixel_var_mask                          (0x00000008)
#define ONMS_STATUS_vact_space3_under_min_mask                        (0x00000004)
#define ONMS_STATUS_vact_space2_under_min_mask                        (0x00000002)
#define ONMS_STATUS_vact_space1_under_min_mask                        (0x00000001)
#define ONMS_STATUS_blk_2frame_en(data)                               (0x00040000&((data)<<18))
#define ONMS_STATUS_vs_pol_out(data)                                  (0x00020000&((data)<<17))
#define ONMS_STATUS_hs_pol_out(data)                                  (0x00010000&((data)<<16))
#define ONMS_STATUS_vs_per_over_range(data)                           (0x00008000&((data)<<15))
#define ONMS_STATUS_hs_per_over_range(data)                           (0x00004000&((data)<<14))
#define ONMS_STATUS_vs_per_timeout(data)                              (0x00002000&((data)<<13))
#define ONMS_STATUS_vs_high_timeout(data)                             (0x00001000&((data)<<12))
#define ONMS_STATUS_vs_per_overflow(data)                             (0x00000800&((data)<<11))
#define ONMS_STATUS_hs_per_overflow(data)                             (0x00000400&((data)<<10))
#define ONMS_STATUS_vs_pol_chg(data)                                  (0x00000200&((data)<<9))
#define ONMS_STATUS_hs_pol_chg(data)                                  (0x00000100&((data)<<8))
#define ONMS_STATUS_vtotalde_chg(data)                                (0x00000080&((data)<<7))
#define ONMS_STATUS_vtotal_chg(data)                                  (0x00000040&((data)<<6))
#define ONMS_STATUS_hact_chg(data)                                    (0x00000020&((data)<<5))
#define ONMS_STATUS_htotal_chg(data)                                  (0x00000010&((data)<<4))
#define ONMS_STATUS_hs_active_pixel_var(data)                         (0x00000008&((data)<<3))
#define ONMS_STATUS_vact_space3_under_min(data)                       (0x00000004&((data)<<2))
#define ONMS_STATUS_vact_space2_under_min(data)                       (0x00000002&((data)<<1))
#define ONMS_STATUS_vact_space1_under_min(data)                       (0x00000001&(data))
#define ONMS_STATUS_get_blk_2frame_en(data)                           ((0x00040000&(data))>>18)
#define ONMS_STATUS_get_vs_pol_out(data)                              ((0x00020000&(data))>>17)
#define ONMS_STATUS_get_hs_pol_out(data)                              ((0x00010000&(data))>>16)
#define ONMS_STATUS_get_vs_per_over_range(data)                       ((0x00008000&(data))>>15)
#define ONMS_STATUS_get_hs_per_over_range(data)                       ((0x00004000&(data))>>14)
#define ONMS_STATUS_get_vs_per_timeout(data)                          ((0x00002000&(data))>>13)
#define ONMS_STATUS_get_vs_high_timeout(data)                         ((0x00001000&(data))>>12)
#define ONMS_STATUS_get_vs_per_overflow(data)                         ((0x00000800&(data))>>11)
#define ONMS_STATUS_get_hs_per_overflow(data)                         ((0x00000400&(data))>>10)
#define ONMS_STATUS_get_vs_pol_chg(data)                              ((0x00000200&(data))>>9)
#define ONMS_STATUS_get_hs_pol_chg(data)                              ((0x00000100&(data))>>8)
#define ONMS_STATUS_get_vtotalde_chg(data)                            ((0x00000080&(data))>>7)
#define ONMS_STATUS_get_vtotal_chg(data)                              ((0x00000040&(data))>>6)
#define ONMS_STATUS_get_hact_chg(data)                                ((0x00000020&(data))>>5)
#define ONMS_STATUS_get_htotal_chg(data)                              ((0x00000010&(data))>>4)
#define ONMS_STATUS_get_hs_active_pixel_var(data)                     ((0x00000008&(data))>>3)
#define ONMS_STATUS_get_vact_space3_under_min(data)                   ((0x00000004&(data))>>2)
#define ONMS_STATUS_get_vact_space2_under_min(data)                   ((0x00000002&(data))>>1)
#define ONMS_STATUS_get_vact_space1_under_min(data)                   (0x00000001&(data))


#define ONMS_WATCHDOG_EN                                              0x18005960
#define ONMS_WATCHDOG_EN_reg_addr                                     "0xb8005960"
#define ONMS_WATCHDOG_EN_reg                                          0xb8005960
#define ONMS_WATCHDOG_EN_inst_addr                                    "0x0258"
#define ONMS_WATCHDOG_EN_inst                                         0x0258
#define ONMS_WATCHDOG_EN_wd_vs_per_over_range_shift                   (15)
#define ONMS_WATCHDOG_EN_wd_hs_per_over_range_shift                   (14)
#define ONMS_WATCHDOG_EN_wd_vs_per_timeout_shift                      (13)
#define ONMS_WATCHDOG_EN_wd_vs_high_timeout_shift                     (12)
#define ONMS_WATCHDOG_EN_wd_vs_per_overflow_shift                     (11)
#define ONMS_WATCHDOG_EN_wd_hs_per_overflow_shift                     (10)
#define ONMS_WATCHDOG_EN_wd_vs_pol_chg_shift                          (9)
#define ONMS_WATCHDOG_EN_wd_hs_pol_chg_shift                          (8)
#define ONMS_WATCHDOG_EN_wd_vtotalde_chg_shift                        (7)
#define ONMS_WATCHDOG_EN_wd_vtotal_chg_shift                          (6)
#define ONMS_WATCHDOG_EN_wd_hact_chg_shift                            (5)
#define ONMS_WATCHDOG_EN_wd_htotal_chg_shift                          (4)
#define ONMS_WATCHDOG_EN_wd_hs_active_pixel_var_shift                 (3)
#define ONMS_WATCHDOG_EN_wd_vact_space3_under_min_shift               (2)
#define ONMS_WATCHDOG_EN_wd_vact_space2_under_min_shift               (1)
#define ONMS_WATCHDOG_EN_wd_vact_space1_under_min_shift               (0)
#define ONMS_WATCHDOG_EN_wd_vs_per_over_range_mask                    (0x00008000)
#define ONMS_WATCHDOG_EN_wd_hs_per_over_range_mask                    (0x00004000)
#define ONMS_WATCHDOG_EN_wd_vs_per_timeout_mask                       (0x00002000)
#define ONMS_WATCHDOG_EN_wd_vs_high_timeout_mask                      (0x00001000)
#define ONMS_WATCHDOG_EN_wd_vs_per_overflow_mask                      (0x00000800)
#define ONMS_WATCHDOG_EN_wd_hs_per_overflow_mask                      (0x00000400)
#define ONMS_WATCHDOG_EN_wd_vs_pol_chg_mask                           (0x00000200)
#define ONMS_WATCHDOG_EN_wd_hs_pol_chg_mask                           (0x00000100)
#define ONMS_WATCHDOG_EN_wd_vtotalde_chg_mask                         (0x00000080)
#define ONMS_WATCHDOG_EN_wd_vtotal_chg_mask                           (0x00000040)
#define ONMS_WATCHDOG_EN_wd_hact_chg_mask                             (0x00000020)
#define ONMS_WATCHDOG_EN_wd_htotal_chg_mask                           (0x00000010)
#define ONMS_WATCHDOG_EN_wd_hs_active_pixel_var_mask                  (0x00000008)
#define ONMS_WATCHDOG_EN_wd_vact_space3_under_min_mask                (0x00000004)
#define ONMS_WATCHDOG_EN_wd_vact_space2_under_min_mask                (0x00000002)
#define ONMS_WATCHDOG_EN_wd_vact_space1_under_min_mask                (0x00000001)
#define ONMS_WATCHDOG_EN_wd_vs_per_over_range(data)                   (0x00008000&((data)<<15))
#define ONMS_WATCHDOG_EN_wd_hs_per_over_range(data)                   (0x00004000&((data)<<14))
#define ONMS_WATCHDOG_EN_wd_vs_per_timeout(data)                      (0x00002000&((data)<<13))
#define ONMS_WATCHDOG_EN_wd_vs_high_timeout(data)                     (0x00001000&((data)<<12))
#define ONMS_WATCHDOG_EN_wd_vs_per_overflow(data)                     (0x00000800&((data)<<11))
#define ONMS_WATCHDOG_EN_wd_hs_per_overflow(data)                     (0x00000400&((data)<<10))
#define ONMS_WATCHDOG_EN_wd_vs_pol_chg(data)                          (0x00000200&((data)<<9))
#define ONMS_WATCHDOG_EN_wd_hs_pol_chg(data)                          (0x00000100&((data)<<8))
#define ONMS_WATCHDOG_EN_wd_vtotalde_chg(data)                        (0x00000080&((data)<<7))
#define ONMS_WATCHDOG_EN_wd_vtotal_chg(data)                          (0x00000040&((data)<<6))
#define ONMS_WATCHDOG_EN_wd_hact_chg(data)                            (0x00000020&((data)<<5))
#define ONMS_WATCHDOG_EN_wd_htotal_chg(data)                          (0x00000010&((data)<<4))
#define ONMS_WATCHDOG_EN_wd_hs_active_pixel_var(data)                 (0x00000008&((data)<<3))
#define ONMS_WATCHDOG_EN_wd_vact_space3_under_min(data)               (0x00000004&((data)<<2))
#define ONMS_WATCHDOG_EN_wd_vact_space2_under_min(data)               (0x00000002&((data)<<1))
#define ONMS_WATCHDOG_EN_wd_vact_space1_under_min(data)               (0x00000001&(data))
#define ONMS_WATCHDOG_EN_get_wd_vs_per_over_range(data)               ((0x00008000&(data))>>15)
#define ONMS_WATCHDOG_EN_get_wd_hs_per_over_range(data)               ((0x00004000&(data))>>14)
#define ONMS_WATCHDOG_EN_get_wd_vs_per_timeout(data)                  ((0x00002000&(data))>>13)
#define ONMS_WATCHDOG_EN_get_wd_vs_high_timeout(data)                 ((0x00001000&(data))>>12)
#define ONMS_WATCHDOG_EN_get_wd_vs_per_overflow(data)                 ((0x00000800&(data))>>11)
#define ONMS_WATCHDOG_EN_get_wd_hs_per_overflow(data)                 ((0x00000400&(data))>>10)
#define ONMS_WATCHDOG_EN_get_wd_vs_pol_chg(data)                      ((0x00000200&(data))>>9)
#define ONMS_WATCHDOG_EN_get_wd_hs_pol_chg(data)                      ((0x00000100&(data))>>8)
#define ONMS_WATCHDOG_EN_get_wd_vtotalde_chg(data)                    ((0x00000080&(data))>>7)
#define ONMS_WATCHDOG_EN_get_wd_vtotal_chg(data)                      ((0x00000040&(data))>>6)
#define ONMS_WATCHDOG_EN_get_wd_hact_chg(data)                        ((0x00000020&(data))>>5)
#define ONMS_WATCHDOG_EN_get_wd_htotal_chg(data)                      ((0x00000010&(data))>>4)
#define ONMS_WATCHDOG_EN_get_wd_hs_active_pixel_var(data)             ((0x00000008&(data))>>3)
#define ONMS_WATCHDOG_EN_get_wd_vact_space3_under_min(data)           ((0x00000004&(data))>>2)
#define ONMS_WATCHDOG_EN_get_wd_vact_space2_under_min(data)           ((0x00000002&(data))>>1)
#define ONMS_WATCHDOG_EN_get_wd_vact_space1_under_min(data)           (0x00000001&(data))


#define ONMS_INTERRUPT_EN                                             0x18005964
#define ONMS_INTERRUPT_EN_reg_addr                                    "0xb8005964"
#define ONMS_INTERRUPT_EN_reg                                         0xb8005964
#define ONMS_INTERRUPT_EN_inst_addr                                   "0x0259"
#define ONMS_INTERRUPT_EN_inst                                        0x0259
#define ONMS_INTERRUPT_EN_ie_vs_per_over_range_shift                  (15)
#define ONMS_INTERRUPT_EN_ie_hs_per_over_range_shift                  (14)
#define ONMS_INTERRUPT_EN_ie_vs_per_timeout_shift                     (13)
#define ONMS_INTERRUPT_EN_ie_vs_high_timeout_shift                    (12)
#define ONMS_INTERRUPT_EN_ie_vs_per_overflow_shift                    (11)
#define ONMS_INTERRUPT_EN_ie_hs_per_overflow_shift                    (10)
#define ONMS_INTERRUPT_EN_ie_vs_pol_chg_shift                         (9)
#define ONMS_INTERRUPT_EN_ie_hs_pol_chg_shift                         (8)
#define ONMS_INTERRUPT_EN_ie_vtotalde_chg_shift                       (7)
#define ONMS_INTERRUPT_EN_ie_vtotal_chg_shift                         (6)
#define ONMS_INTERRUPT_EN_ie_hact_chg_shift                           (5)
#define ONMS_INTERRUPT_EN_ie_htotal_chg_shift                         (4)
#define ONMS_INTERRUPT_EN_ie_hs_active_pixel_var_shift                (3)
#define ONMS_INTERRUPT_EN_ie_vact_space3_under_min_shift              (2)
#define ONMS_INTERRUPT_EN_ie_vact_space2_under_min_shift              (1)
#define ONMS_INTERRUPT_EN_ie_vact_space1_under_min_shift              (0)
#define ONMS_INTERRUPT_EN_ie_vs_per_over_range_mask                   (0x00008000)
#define ONMS_INTERRUPT_EN_ie_hs_per_over_range_mask                   (0x00004000)
#define ONMS_INTERRUPT_EN_ie_vs_per_timeout_mask                      (0x00002000)
#define ONMS_INTERRUPT_EN_ie_vs_high_timeout_mask                     (0x00001000)
#define ONMS_INTERRUPT_EN_ie_vs_per_overflow_mask                     (0x00000800)
#define ONMS_INTERRUPT_EN_ie_hs_per_overflow_mask                     (0x00000400)
#define ONMS_INTERRUPT_EN_ie_vs_pol_chg_mask                          (0x00000200)
#define ONMS_INTERRUPT_EN_ie_hs_pol_chg_mask                          (0x00000100)
#define ONMS_INTERRUPT_EN_ie_vtotalde_chg_mask                        (0x00000080)
#define ONMS_INTERRUPT_EN_ie_vtotal_chg_mask                          (0x00000040)
#define ONMS_INTERRUPT_EN_ie_hact_chg_mask                            (0x00000020)
#define ONMS_INTERRUPT_EN_ie_htotal_chg_mask                          (0x00000010)
#define ONMS_INTERRUPT_EN_ie_hs_active_pixel_var_mask                 (0x00000008)
#define ONMS_INTERRUPT_EN_ie_vact_space3_under_min_mask               (0x00000004)
#define ONMS_INTERRUPT_EN_ie_vact_space2_under_min_mask               (0x00000002)
#define ONMS_INTERRUPT_EN_ie_vact_space1_under_min_mask               (0x00000001)
#define ONMS_INTERRUPT_EN_ie_vs_per_over_range(data)                  (0x00008000&((data)<<15))
#define ONMS_INTERRUPT_EN_ie_hs_per_over_range(data)                  (0x00004000&((data)<<14))
#define ONMS_INTERRUPT_EN_ie_vs_per_timeout(data)                     (0x00002000&((data)<<13))
#define ONMS_INTERRUPT_EN_ie_vs_high_timeout(data)                    (0x00001000&((data)<<12))
#define ONMS_INTERRUPT_EN_ie_vs_per_overflow(data)                    (0x00000800&((data)<<11))
#define ONMS_INTERRUPT_EN_ie_hs_per_overflow(data)                    (0x00000400&((data)<<10))
#define ONMS_INTERRUPT_EN_ie_vs_pol_chg(data)                         (0x00000200&((data)<<9))
#define ONMS_INTERRUPT_EN_ie_hs_pol_chg(data)                         (0x00000100&((data)<<8))
#define ONMS_INTERRUPT_EN_ie_vtotalde_chg(data)                       (0x00000080&((data)<<7))
#define ONMS_INTERRUPT_EN_ie_vtotal_chg(data)                         (0x00000040&((data)<<6))
#define ONMS_INTERRUPT_EN_ie_hact_chg(data)                           (0x00000020&((data)<<5))
#define ONMS_INTERRUPT_EN_ie_htotal_chg(data)                         (0x00000010&((data)<<4))
#define ONMS_INTERRUPT_EN_ie_hs_active_pixel_var(data)                (0x00000008&((data)<<3))
#define ONMS_INTERRUPT_EN_ie_vact_space3_under_min(data)              (0x00000004&((data)<<2))
#define ONMS_INTERRUPT_EN_ie_vact_space2_under_min(data)              (0x00000002&((data)<<1))
#define ONMS_INTERRUPT_EN_ie_vact_space1_under_min(data)              (0x00000001&(data))
#define ONMS_INTERRUPT_EN_get_ie_vs_per_over_range(data)              ((0x00008000&(data))>>15)
#define ONMS_INTERRUPT_EN_get_ie_hs_per_over_range(data)              ((0x00004000&(data))>>14)
#define ONMS_INTERRUPT_EN_get_ie_vs_per_timeout(data)                 ((0x00002000&(data))>>13)
#define ONMS_INTERRUPT_EN_get_ie_vs_high_timeout(data)                ((0x00001000&(data))>>12)
#define ONMS_INTERRUPT_EN_get_ie_vs_per_overflow(data)                ((0x00000800&(data))>>11)
#define ONMS_INTERRUPT_EN_get_ie_hs_per_overflow(data)                ((0x00000400&(data))>>10)
#define ONMS_INTERRUPT_EN_get_ie_vs_pol_chg(data)                     ((0x00000200&(data))>>9)
#define ONMS_INTERRUPT_EN_get_ie_hs_pol_chg(data)                     ((0x00000100&(data))>>8)
#define ONMS_INTERRUPT_EN_get_ie_vtotalde_chg(data)                   ((0x00000080&(data))>>7)
#define ONMS_INTERRUPT_EN_get_ie_vtotal_chg(data)                     ((0x00000040&(data))>>6)
#define ONMS_INTERRUPT_EN_get_ie_hact_chg(data)                       ((0x00000020&(data))>>5)
#define ONMS_INTERRUPT_EN_get_ie_htotal_chg(data)                     ((0x00000010&(data))>>4)
#define ONMS_INTERRUPT_EN_get_ie_hs_active_pixel_var(data)            ((0x00000008&(data))>>3)
#define ONMS_INTERRUPT_EN_get_ie_vact_space3_under_min(data)          ((0x00000004&(data))>>2)
#define ONMS_INTERRUPT_EN_get_ie_vact_space2_under_min(data)          ((0x00000002&(data))>>1)
#define ONMS_INTERRUPT_EN_get_ie_vact_space1_under_min(data)          (0x00000001&(data))
#endif
