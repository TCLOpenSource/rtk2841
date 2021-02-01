// This file is generated using the spec version 1.39, firmware template version 1.39and SRIF Parser                                                                                source code SVN rev:748                    Version flow no.:1.0.204
#ifndef _RGB2YUV_REG_H_INCLUDED_
#define _RGB2YUV_REG_H_INCLUDED_

//#define  _RGB2YUV_USE_STRUCT
#ifdef _RGB2YUV_USE_STRUCT

typedef struct
{
    unsigned int    reserved_0:22;
    unsigned int    sel_2x_gain:1;
    unsigned int    sel_y_gain:1;
    unsigned int    matrix_bypass:1;
    unsigned int    sel_uv_off:1;
    unsigned int    set_uv_out_offset:1;
    unsigned int    set_r_in_offset:1;
    unsigned int    sel_rgb:1;
    unsigned int    sel_sign:1;
    unsigned int    sel_table:1;
    unsigned int    en_rgb2yuv:1;
}ICH1;

typedef struct
{
    unsigned int    reserved_0:21;
    unsigned int    truncationctrl_en:1;
    unsigned int    sel_2x_gain:1;
    unsigned int    sel_y_gain:1;
    unsigned int    matrix_bypass:1;
    unsigned int    sel_uv_off:1;
    unsigned int    set_uv_out_offset:1;
    unsigned int    set_r_in_offset:1;
    unsigned int    sel_rgb:1;
    unsigned int    sel_sign:1;
    unsigned int    sel_table:1;
    unsigned int    en_rgb2yuv:1;
}ICH2;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    m13:10;
    unsigned int    m12:10;
    unsigned int    m11:11;
}TAB1;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    m23:9;
    unsigned int    m22:10;
    unsigned int    m21:9;
}TAB1;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    m33:10;
    unsigned int    m32:9;
    unsigned int    m31:9;
}TAB1;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    y_gain:9;
    unsigned int    yo_odd:11;
    unsigned int    yo_even:11;
}TAB1;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    m13:10;
    unsigned int    m12:10;
    unsigned int    m11:11;
}TAB2;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    m23:9;
    unsigned int    m22:10;
    unsigned int    m21:9;
}TAB2;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    m33:10;
    unsigned int    m32:9;
    unsigned int    m31:9;
}TAB2;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    y_gain:9;
    unsigned int    yo_odd:11;
    unsigned int    yo_even:11;
}TAB2;

typedef struct
{
    unsigned int    reserved_0:29;
    unsigned int    cr_dly_cb:1;
    unsigned int    dup:1;
    unsigned int    en_422to444:1;
}ICH1;

typedef struct
{
    unsigned int    reserved_0:29;
    unsigned int    cr_dly_cb:1;
    unsigned int    dup:1;
    unsigned int    en_422to444:1;
}ICH2;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    i_m_mapping:10;
    unsigned int    i_m_boundary:10;
    unsigned int    i_m_threashold:10;
    unsigned int    i_m_enable:1;
}C_coring_data_1;

typedef struct
{
    unsigned int    reserved_0:19;
    unsigned int    i_m_slope1:7;
    unsigned int    i_m_slope0:5;
    unsigned int    i_m_condition_mode:1;
}C_coring_data_2;

typedef struct
{
    unsigned int    reserved_0:7;
    unsigned int    i_s_mapping:8;
    unsigned int    i_s_boundary:8;
    unsigned int    i_s_threashold:8;
    unsigned int    i_s_enable:1;
}C_coring_data_3;

typedef struct
{
    unsigned int    reserved_0:19;
    unsigned int    i_s_slope1:7;
    unsigned int    i_s_slope0:5;
    unsigned int    i_s_condition_mode:1;
}C_coring_data_4;
#endif


#define ICH1_RGB2YUV_CTRL                                             0x18023000
#define ICH1_RGB2YUV_CTRL_reg_addr                                    "0xB8023000"
#define ICH1_RGB2YUV_CTRL_reg                                         0xB8023000
#define ICH1_RGB2YUV_CTRL_inst_addr                                   "0x0000"
#define ICH1_RGB2YUV_CTRL_inst                                        0x0000
#define ICH1_RGB2YUV_CTRL_sel_2x_gain_shift                           (9)
#define ICH1_RGB2YUV_CTRL_sel_y_gain_shift                            (8)
#define ICH1_RGB2YUV_CTRL_matrix_bypass_shift                         (7)
#define ICH1_RGB2YUV_CTRL_sel_uv_off_shift                            (6)
#define ICH1_RGB2YUV_CTRL_set_uv_out_offset_shift                     (5)
#define ICH1_RGB2YUV_CTRL_set_r_in_offset_shift                       (4)
#define ICH1_RGB2YUV_CTRL_sel_rgb_shift                               (3)
#define ICH1_RGB2YUV_CTRL_sel_sign_shift                              (2)
#define ICH1_RGB2YUV_CTRL_sel_table_shift                             (1)
#define ICH1_RGB2YUV_CTRL_en_rgb2yuv_shift                            (0)
#define ICH1_RGB2YUV_CTRL_sel_2x_gain_mask                            (0x00000200)
#define ICH1_RGB2YUV_CTRL_sel_y_gain_mask                             (0x00000100)
#define ICH1_RGB2YUV_CTRL_matrix_bypass_mask                          (0x00000080)
#define ICH1_RGB2YUV_CTRL_sel_uv_off_mask                             (0x00000040)
#define ICH1_RGB2YUV_CTRL_set_uv_out_offset_mask                      (0x00000020)
#define ICH1_RGB2YUV_CTRL_set_r_in_offset_mask                        (0x00000010)
#define ICH1_RGB2YUV_CTRL_sel_rgb_mask                                (0x00000008)
#define ICH1_RGB2YUV_CTRL_sel_sign_mask                               (0x00000004)
#define ICH1_RGB2YUV_CTRL_sel_table_mask                              (0x00000002)
#define ICH1_RGB2YUV_CTRL_en_rgb2yuv_mask                             (0x00000001)
#define ICH1_RGB2YUV_CTRL_sel_2x_gain(data)                           (0x00000200&((data)<<9))
#define ICH1_RGB2YUV_CTRL_sel_y_gain(data)                            (0x00000100&((data)<<8))
#define ICH1_RGB2YUV_CTRL_matrix_bypass(data)                         (0x00000080&((data)<<7))
#define ICH1_RGB2YUV_CTRL_sel_uv_off(data)                            (0x00000040&((data)<<6))
#define ICH1_RGB2YUV_CTRL_set_uv_out_offset(data)                     (0x00000020&((data)<<5))
#define ICH1_RGB2YUV_CTRL_set_r_in_offset(data)                       (0x00000010&((data)<<4))
#define ICH1_RGB2YUV_CTRL_sel_rgb(data)                               (0x00000008&((data)<<3))
#define ICH1_RGB2YUV_CTRL_sel_sign(data)                              (0x00000004&((data)<<2))
#define ICH1_RGB2YUV_CTRL_sel_table(data)                             (0x00000002&((data)<<1))
#define ICH1_RGB2YUV_CTRL_en_rgb2yuv(data)                            (0x00000001&(data))
#define ICH1_RGB2YUV_CTRL_get_sel_2x_gain(data)                       ((0x00000200&(data))>>9)
#define ICH1_RGB2YUV_CTRL_get_sel_y_gain(data)                        ((0x00000100&(data))>>8)
#define ICH1_RGB2YUV_CTRL_get_matrix_bypass(data)                     ((0x00000080&(data))>>7)
#define ICH1_RGB2YUV_CTRL_get_sel_uv_off(data)                        ((0x00000040&(data))>>6)
#define ICH1_RGB2YUV_CTRL_get_set_uv_out_offset(data)                 ((0x00000020&(data))>>5)
#define ICH1_RGB2YUV_CTRL_get_set_r_in_offset(data)                   ((0x00000010&(data))>>4)
#define ICH1_RGB2YUV_CTRL_get_sel_rgb(data)                           ((0x00000008&(data))>>3)
#define ICH1_RGB2YUV_CTRL_get_sel_sign(data)                          ((0x00000004&(data))>>2)
#define ICH1_RGB2YUV_CTRL_get_sel_table(data)                         ((0x00000002&(data))>>1)
#define ICH1_RGB2YUV_CTRL_get_en_rgb2yuv(data)                        (0x00000001&(data))


#define ICH2_RGB2YUV_CTRL                                             0x18023004
#define ICH2_RGB2YUV_CTRL_reg_addr                                    "0xB8023004"
#define ICH2_RGB2YUV_CTRL_reg                                         0xB8023004
#define ICH2_RGB2YUV_CTRL_inst_addr                                   "0x0001"
#define ICH2_RGB2YUV_CTRL_inst                                        0x0001
#define ICH2_RGB2YUV_CTRL_truncationctrl_en_shift                     (10)
#define ICH2_RGB2YUV_CTRL_sel_2x_gain_shift                           (9)
#define ICH2_RGB2YUV_CTRL_sel_y_gain_shift                            (8)
#define ICH2_RGB2YUV_CTRL_matrix_bypass_shift                         (7)
#define ICH2_RGB2YUV_CTRL_sel_uv_off_shift                            (6)
#define ICH2_RGB2YUV_CTRL_set_uv_out_offset_shift                     (5)
#define ICH2_RGB2YUV_CTRL_set_r_in_offset_shift                       (4)
#define ICH2_RGB2YUV_CTRL_sel_rgb_shift                               (3)
#define ICH2_RGB2YUV_CTRL_sel_sign_shift                              (2)
#define ICH2_RGB2YUV_CTRL_sel_table_shift                             (1)
#define ICH2_RGB2YUV_CTRL_en_rgb2yuv_shift                            (0)
#define ICH2_RGB2YUV_CTRL_truncationctrl_en_mask                      (0x00000400)
#define ICH2_RGB2YUV_CTRL_sel_2x_gain_mask                            (0x00000200)
#define ICH2_RGB2YUV_CTRL_sel_y_gain_mask                             (0x00000100)
#define ICH2_RGB2YUV_CTRL_matrix_bypass_mask                          (0x00000080)
#define ICH2_RGB2YUV_CTRL_sel_uv_off_mask                             (0x00000040)
#define ICH2_RGB2YUV_CTRL_set_uv_out_offset_mask                      (0x00000020)
#define ICH2_RGB2YUV_CTRL_set_r_in_offset_mask                        (0x00000010)
#define ICH2_RGB2YUV_CTRL_sel_rgb_mask                                (0x00000008)
#define ICH2_RGB2YUV_CTRL_sel_sign_mask                               (0x00000004)
#define ICH2_RGB2YUV_CTRL_sel_table_mask                              (0x00000002)
#define ICH2_RGB2YUV_CTRL_en_rgb2yuv_mask                             (0x00000001)
#define ICH2_RGB2YUV_CTRL_truncationctrl_en(data)                     (0x00000400&((data)<<10))
#define ICH2_RGB2YUV_CTRL_sel_2x_gain(data)                           (0x00000200&((data)<<9))
#define ICH2_RGB2YUV_CTRL_sel_y_gain(data)                            (0x00000100&((data)<<8))
#define ICH2_RGB2YUV_CTRL_matrix_bypass(data)                         (0x00000080&((data)<<7))
#define ICH2_RGB2YUV_CTRL_sel_uv_off(data)                            (0x00000040&((data)<<6))
#define ICH2_RGB2YUV_CTRL_set_uv_out_offset(data)                     (0x00000020&((data)<<5))
#define ICH2_RGB2YUV_CTRL_set_r_in_offset(data)                       (0x00000010&((data)<<4))
#define ICH2_RGB2YUV_CTRL_sel_rgb(data)                               (0x00000008&((data)<<3))
#define ICH2_RGB2YUV_CTRL_sel_sign(data)                              (0x00000004&((data)<<2))
#define ICH2_RGB2YUV_CTRL_sel_table(data)                             (0x00000002&((data)<<1))
#define ICH2_RGB2YUV_CTRL_en_rgb2yuv(data)                            (0x00000001&(data))
#define ICH2_RGB2YUV_CTRL_get_truncationctrl_en(data)                 ((0x00000400&(data))>>10)
#define ICH2_RGB2YUV_CTRL_get_sel_2x_gain(data)                       ((0x00000200&(data))>>9)
#define ICH2_RGB2YUV_CTRL_get_sel_y_gain(data)                        ((0x00000100&(data))>>8)
#define ICH2_RGB2YUV_CTRL_get_matrix_bypass(data)                     ((0x00000080&(data))>>7)
#define ICH2_RGB2YUV_CTRL_get_sel_uv_off(data)                        ((0x00000040&(data))>>6)
#define ICH2_RGB2YUV_CTRL_get_set_uv_out_offset(data)                 ((0x00000020&(data))>>5)
#define ICH2_RGB2YUV_CTRL_get_set_r_in_offset(data)                   ((0x00000010&(data))>>4)
#define ICH2_RGB2YUV_CTRL_get_sel_rgb(data)                           ((0x00000008&(data))>>3)
#define ICH2_RGB2YUV_CTRL_get_sel_sign(data)                          ((0x00000004&(data))>>2)
#define ICH2_RGB2YUV_CTRL_get_sel_table(data)                         ((0x00000002&(data))>>1)
#define ICH2_RGB2YUV_CTRL_get_en_rgb2yuv(data)                        (0x00000001&(data))


#define TAB1_M1                                                       0x18023008
#define TAB1_M1_reg_addr                                              "0xB8023008"
#define TAB1_M1_reg                                                   0xB8023008
#define TAB1_M1_inst_addr                                             "0x0002"
#define TAB1_M1_inst                                                  0x0002
#define TAB1_M1_m13_shift                                             (21)
#define TAB1_M1_m12_shift                                             (11)
#define TAB1_M1_m11_shift                                             (0)
#define TAB1_M1_m13_mask                                              (0x7FE00000)
#define TAB1_M1_m12_mask                                              (0x001FF800)
#define TAB1_M1_m11_mask                                              (0x000007FF)
#define TAB1_M1_m13(data)                                             (0x7FE00000&((data)<<21))
#define TAB1_M1_m12(data)                                             (0x001FF800&((data)<<11))
#define TAB1_M1_m11(data)                                             (0x000007FF&(data))
#define TAB1_M1_get_m13(data)                                         ((0x7FE00000&(data))>>21)
#define TAB1_M1_get_m12(data)                                         ((0x001FF800&(data))>>11)
#define TAB1_M1_get_m11(data)                                         (0x000007FF&(data))


#define TAB1_M2                                                       0x1802300c
#define TAB1_M2_reg_addr                                              "0xB802300C"
#define TAB1_M2_reg                                                   0xB802300C
#define TAB1_M2_inst_addr                                             "0x0003"
#define TAB1_M2_inst                                                  0x0003
#define TAB1_M2_m23_shift                                             (19)
#define TAB1_M2_m22_shift                                             (9)
#define TAB1_M2_m21_shift                                             (0)
#define TAB1_M2_m23_mask                                              (0x0FF80000)
#define TAB1_M2_m22_mask                                              (0x0007FE00)
#define TAB1_M2_m21_mask                                              (0x000001FF)
#define TAB1_M2_m23(data)                                             (0x0FF80000&((data)<<19))
#define TAB1_M2_m22(data)                                             (0x0007FE00&((data)<<9))
#define TAB1_M2_m21(data)                                             (0x000001FF&(data))
#define TAB1_M2_get_m23(data)                                         ((0x0FF80000&(data))>>19)
#define TAB1_M2_get_m22(data)                                         ((0x0007FE00&(data))>>9)
#define TAB1_M2_get_m21(data)                                         (0x000001FF&(data))


#define TAB1_M3                                                       0x18023010
#define TAB1_M3_reg_addr                                              "0xB8023010"
#define TAB1_M3_reg                                                   0xB8023010
#define TAB1_M3_inst_addr                                             "0x0004"
#define TAB1_M3_inst                                                  0x0004
#define TAB1_M3_m33_shift                                             (18)
#define TAB1_M3_m32_shift                                             (9)
#define TAB1_M3_m31_shift                                             (0)
#define TAB1_M3_m33_mask                                              (0x0FFC0000)
#define TAB1_M3_m32_mask                                              (0x0003FE00)
#define TAB1_M3_m31_mask                                              (0x000001FF)
#define TAB1_M3_m33(data)                                             (0x0FFC0000&((data)<<18))
#define TAB1_M3_m32(data)                                             (0x0003FE00&((data)<<9))
#define TAB1_M3_m31(data)                                             (0x000001FF&(data))
#define TAB1_M3_get_m33(data)                                         ((0x0FFC0000&(data))>>18)
#define TAB1_M3_get_m32(data)                                         ((0x0003FE00&(data))>>9)
#define TAB1_M3_get_m31(data)                                         (0x000001FF&(data))


#define TAB1_YO_AND_Y_GAIN                                            0x18023014
#define TAB1_YO_AND_Y_GAIN_reg_addr                                   "0xB8023014"
#define TAB1_YO_AND_Y_GAIN_reg                                        0xB8023014
#define TAB1_YO_AND_Y_GAIN_inst_addr                                  "0x0005"
#define TAB1_YO_AND_Y_GAIN_inst                                       0x0005
#define TAB1_YO_AND_Y_GAIN_y_gain_shift                               (22)
#define TAB1_YO_AND_Y_GAIN_yo_odd_shift                               (11)
#define TAB1_YO_AND_Y_GAIN_yo_even_shift                              (0)
#define TAB1_YO_AND_Y_GAIN_y_gain_mask                                (0x7FC00000)
#define TAB1_YO_AND_Y_GAIN_yo_odd_mask                                (0x003FF800)
#define TAB1_YO_AND_Y_GAIN_yo_even_mask                               (0x000007FF)
#define TAB1_YO_AND_Y_GAIN_y_gain(data)                               (0x7FC00000&((data)<<22))
#define TAB1_YO_AND_Y_GAIN_yo_odd(data)                               (0x003FF800&((data)<<11))
#define TAB1_YO_AND_Y_GAIN_yo_even(data)                              (0x000007FF&(data))
#define TAB1_YO_AND_Y_GAIN_get_y_gain(data)                           ((0x7FC00000&(data))>>22)
#define TAB1_YO_AND_Y_GAIN_get_yo_odd(data)                           ((0x003FF800&(data))>>11)
#define TAB1_YO_AND_Y_GAIN_get_yo_even(data)                          (0x000007FF&(data))


#define TAB2_M1                                                       0x18023018
#define TAB2_M1_reg_addr                                              "0xB8023018"
#define TAB2_M1_reg                                                   0xB8023018
#define TAB2_M1_inst_addr                                             "0x0006"
#define TAB2_M1_inst                                                  0x0006
#define TAB2_M1_m13_shift                                             (21)
#define TAB2_M1_m12_shift                                             (11)
#define TAB2_M1_m11_shift                                             (0)
#define TAB2_M1_m13_mask                                              (0x7FE00000)
#define TAB2_M1_m12_mask                                              (0x001FF800)
#define TAB2_M1_m11_mask                                              (0x000007FF)
#define TAB2_M1_m13(data)                                             (0x7FE00000&((data)<<21))
#define TAB2_M1_m12(data)                                             (0x001FF800&((data)<<11))
#define TAB2_M1_m11(data)                                             (0x000007FF&(data))
#define TAB2_M1_get_m13(data)                                         ((0x7FE00000&(data))>>21)
#define TAB2_M1_get_m12(data)                                         ((0x001FF800&(data))>>11)
#define TAB2_M1_get_m11(data)                                         (0x000007FF&(data))


#define TAB2_M2                                                       0x1802301c
#define TAB2_M2_reg_addr                                              "0xB802301C"
#define TAB2_M2_reg                                                   0xB802301C
#define TAB2_M2_inst_addr                                             "0x0007"
#define TAB2_M2_inst                                                  0x0007
#define TAB2_M2_m23_shift                                             (19)
#define TAB2_M2_m22_shift                                             (9)
#define TAB2_M2_m21_shift                                             (0)
#define TAB2_M2_m23_mask                                              (0x0FF80000)
#define TAB2_M2_m22_mask                                              (0x0007FE00)
#define TAB2_M2_m21_mask                                              (0x000001FF)
#define TAB2_M2_m23(data)                                             (0x0FF80000&((data)<<19))
#define TAB2_M2_m22(data)                                             (0x0007FE00&((data)<<9))
#define TAB2_M2_m21(data)                                             (0x000001FF&(data))
#define TAB2_M2_get_m23(data)                                         ((0x0FF80000&(data))>>19)
#define TAB2_M2_get_m22(data)                                         ((0x0007FE00&(data))>>9)
#define TAB2_M2_get_m21(data)                                         (0x000001FF&(data))


#define TAB2_M3                                                       0x18023020
#define TAB2_M3_reg_addr                                              "0xB8023020"
#define TAB2_M3_reg                                                   0xB8023020
#define TAB2_M3_inst_addr                                             "0x0008"
#define TAB2_M3_inst                                                  0x0008
#define TAB2_M3_m33_shift                                             (18)
#define TAB2_M3_m32_shift                                             (9)
#define TAB2_M3_m31_shift                                             (0)
#define TAB2_M3_m33_mask                                              (0x0FFC0000)
#define TAB2_M3_m32_mask                                              (0x0003FE00)
#define TAB2_M3_m31_mask                                              (0x000001FF)
#define TAB2_M3_m33(data)                                             (0x0FFC0000&((data)<<18))
#define TAB2_M3_m32(data)                                             (0x0003FE00&((data)<<9))
#define TAB2_M3_m31(data)                                             (0x000001FF&(data))
#define TAB2_M3_get_m33(data)                                         ((0x0FFC0000&(data))>>18)
#define TAB2_M3_get_m32(data)                                         ((0x0003FE00&(data))>>9)
#define TAB2_M3_get_m31(data)                                         (0x000001FF&(data))


#define TAB2_YO_AND_Y_GAIN                                            0x18023024
#define TAB2_YO_AND_Y_GAIN_reg_addr                                   "0xB8023024"
#define TAB2_YO_AND_Y_GAIN_reg                                        0xB8023024
#define TAB2_YO_AND_Y_GAIN_inst_addr                                  "0x0009"
#define TAB2_YO_AND_Y_GAIN_inst                                       0x0009
#define TAB2_YO_AND_Y_GAIN_y_gain_shift                               (22)
#define TAB2_YO_AND_Y_GAIN_yo_odd_shift                               (11)
#define TAB2_YO_AND_Y_GAIN_yo_even_shift                              (0)
#define TAB2_YO_AND_Y_GAIN_y_gain_mask                                (0x7FC00000)
#define TAB2_YO_AND_Y_GAIN_yo_odd_mask                                (0x003FF800)
#define TAB2_YO_AND_Y_GAIN_yo_even_mask                               (0x000007FF)
#define TAB2_YO_AND_Y_GAIN_y_gain(data)                               (0x7FC00000&((data)<<22))
#define TAB2_YO_AND_Y_GAIN_yo_odd(data)                               (0x003FF800&((data)<<11))
#define TAB2_YO_AND_Y_GAIN_yo_even(data)                              (0x000007FF&(data))
#define TAB2_YO_AND_Y_GAIN_get_y_gain(data)                           ((0x7FC00000&(data))>>22)
#define TAB2_YO_AND_Y_GAIN_get_yo_odd(data)                           ((0x003FF800&(data))>>11)
#define TAB2_YO_AND_Y_GAIN_get_yo_even(data)                          (0x000007FF&(data))


#define ICH1_422TO444_CTRL                                            0x18023028
#define ICH1_422TO444_CTRL_reg_addr                                   "0xB8023028"
#define ICH1_422TO444_CTRL_reg                                        0xB8023028
#define ICH1_422TO444_CTRL_inst_addr                                  "0x000A"
#define ICH1_422TO444_CTRL_inst                                       0x000A
#define ICH1_422TO444_CTRL_cr_dly_cb_shift                            (2)
#define ICH1_422TO444_CTRL_dup_shift                                  (1)
#define ICH1_422TO444_CTRL_en_422to444_shift                          (0)
#define ICH1_422TO444_CTRL_cr_dly_cb_mask                             (0x00000004)
#define ICH1_422TO444_CTRL_dup_mask                                   (0x00000002)
#define ICH1_422TO444_CTRL_en_422to444_mask                           (0x00000001)
#define ICH1_422TO444_CTRL_cr_dly_cb(data)                            (0x00000004&((data)<<2))
#define ICH1_422TO444_CTRL_dup(data)                                  (0x00000002&((data)<<1))
#define ICH1_422TO444_CTRL_en_422to444(data)                          (0x00000001&(data))
#define ICH1_422TO444_CTRL_get_cr_dly_cb(data)                        ((0x00000004&(data))>>2)
#define ICH1_422TO444_CTRL_get_dup(data)                              ((0x00000002&(data))>>1)
#define ICH1_422TO444_CTRL_get_en_422to444(data)                      (0x00000001&(data))


#define ICH2_422TO444_CTRL                                            0x1802302c
#define ICH2_422TO444_CTRL_reg_addr                                   "0xB802302C"
#define ICH2_422TO444_CTRL_reg                                        0xB802302C
#define ICH2_422TO444_CTRL_inst_addr                                  "0x000B"
#define ICH2_422TO444_CTRL_inst                                       0x000B
#define ICH2_422TO444_CTRL_cr_dly_cb_shift                            (2)
#define ICH2_422TO444_CTRL_dup_shift                                  (1)
#define ICH2_422TO444_CTRL_en_422to444_shift                          (0)
#define ICH2_422TO444_CTRL_cr_dly_cb_mask                             (0x00000004)
#define ICH2_422TO444_CTRL_dup_mask                                   (0x00000002)
#define ICH2_422TO444_CTRL_en_422to444_mask                           (0x00000001)
#define ICH2_422TO444_CTRL_cr_dly_cb(data)                            (0x00000004&((data)<<2))
#define ICH2_422TO444_CTRL_dup(data)                                  (0x00000002&((data)<<1))
#define ICH2_422TO444_CTRL_en_422to444(data)                          (0x00000001&(data))
#define ICH2_422TO444_CTRL_get_cr_dly_cb(data)                        ((0x00000004&(data))>>2)
#define ICH2_422TO444_CTRL_get_dup(data)                              ((0x00000002&(data))>>1)
#define ICH2_422TO444_CTRL_get_en_422to444(data)                      (0x00000001&(data))


#define C_CORING_DATA_1                                               0x18023030
#define C_CORING_DATA_1_reg_addr                                      "0xB8023030"
#define C_CORING_DATA_1_reg                                           0xB8023030
#define C_CORING_DATA_1_inst_addr                                     "0x000C"
#define C_CORING_DATA_1_inst                                          0x000C
#define C_CORING_DATA_1_i_m_mapping_shift                             (21)
#define C_CORING_DATA_1_i_m_boundary_shift                            (11)
#define C_CORING_DATA_1_i_m_threashold_shift                          (1)
#define C_CORING_DATA_1_i_m_enable_shift                              (0)
#define C_CORING_DATA_1_i_m_mapping_mask                              (0x7FE00000)
#define C_CORING_DATA_1_i_m_boundary_mask                             (0x001FF800)
#define C_CORING_DATA_1_i_m_threashold_mask                           (0x000007FE)
#define C_CORING_DATA_1_i_m_enable_mask                               (0x00000001)
#define C_CORING_DATA_1_i_m_mapping(data)                             (0x7FE00000&((data)<<21))
#define C_CORING_DATA_1_i_m_boundary(data)                            (0x001FF800&((data)<<11))
#define C_CORING_DATA_1_i_m_threashold(data)                          (0x000007FE&((data)<<1))
#define C_CORING_DATA_1_i_m_enable(data)                              (0x00000001&(data))
#define C_CORING_DATA_1_get_i_m_mapping(data)                         ((0x7FE00000&(data))>>21)
#define C_CORING_DATA_1_get_i_m_boundary(data)                        ((0x001FF800&(data))>>11)
#define C_CORING_DATA_1_get_i_m_threashold(data)                      ((0x000007FE&(data))>>1)
#define C_CORING_DATA_1_get_i_m_enable(data)                          (0x00000001&(data))


#define C_CORING_DATA_2                                               0x18023034
#define C_CORING_DATA_2_reg_addr                                      "0xB8023034"
#define C_CORING_DATA_2_reg                                           0xB8023034
#define C_CORING_DATA_2_inst_addr                                     "0x000D"
#define C_CORING_DATA_2_inst                                          0x000D
#define C_CORING_DATA_2_i_m_slope1_shift                              (6)
#define C_CORING_DATA_2_i_m_slope0_shift                              (1)
#define C_CORING_DATA_2_i_m_condition_mode_shift                      (0)
#define C_CORING_DATA_2_i_m_slope1_mask                               (0x00001FC0)
#define C_CORING_DATA_2_i_m_slope0_mask                               (0x0000003E)
#define C_CORING_DATA_2_i_m_condition_mode_mask                       (0x00000001)
#define C_CORING_DATA_2_i_m_slope1(data)                              (0x00001FC0&((data)<<6))
#define C_CORING_DATA_2_i_m_slope0(data)                              (0x0000003E&((data)<<1))
#define C_CORING_DATA_2_i_m_condition_mode(data)                      (0x00000001&(data))
#define C_CORING_DATA_2_get_i_m_slope1(data)                          ((0x00001FC0&(data))>>6)
#define C_CORING_DATA_2_get_i_m_slope0(data)                          ((0x0000003E&(data))>>1)
#define C_CORING_DATA_2_get_i_m_condition_mode(data)                  (0x00000001&(data))


#define C_CORING_DATA_3                                               0x18023038
#define C_CORING_DATA_3_reg_addr                                      "0xB8023038"
#define C_CORING_DATA_3_reg                                           0xB8023038
#define C_CORING_DATA_3_inst_addr                                     "0x000E"
#define C_CORING_DATA_3_inst                                          0x000E
#define C_CORING_DATA_3_i_s_mapping_shift                             (17)
#define C_CORING_DATA_3_i_s_boundary_shift                            (9)
#define C_CORING_DATA_3_i_s_threashold_shift                          (1)
#define C_CORING_DATA_3_i_s_enable_shift                              (0)
#define C_CORING_DATA_3_i_s_mapping_mask                              (0x01FE0000)
#define C_CORING_DATA_3_i_s_boundary_mask                             (0x0001FE00)
#define C_CORING_DATA_3_i_s_threashold_mask                           (0x000001FE)
#define C_CORING_DATA_3_i_s_enable_mask                               (0x00000001)
#define C_CORING_DATA_3_i_s_mapping(data)                             (0x01FE0000&((data)<<17))
#define C_CORING_DATA_3_i_s_boundary(data)                            (0x0001FE00&((data)<<9))
#define C_CORING_DATA_3_i_s_threashold(data)                          (0x000001FE&((data)<<1))
#define C_CORING_DATA_3_i_s_enable(data)                              (0x00000001&(data))
#define C_CORING_DATA_3_get_i_s_mapping(data)                         ((0x01FE0000&(data))>>17)
#define C_CORING_DATA_3_get_i_s_boundary(data)                        ((0x0001FE00&(data))>>9)
#define C_CORING_DATA_3_get_i_s_threashold(data)                      ((0x000001FE&(data))>>1)
#define C_CORING_DATA_3_get_i_s_enable(data)                          (0x00000001&(data))


#define C_CORING_DATA_4                                               0x1802303c
#define C_CORING_DATA_4_reg_addr                                      "0xB802303C"
#define C_CORING_DATA_4_reg                                           0xB802303C
#define C_CORING_DATA_4_inst_addr                                     "0x000F"
#define C_CORING_DATA_4_inst                                          0x000F
#define C_CORING_DATA_4_i_s_slope1_shift                              (6)
#define C_CORING_DATA_4_i_s_slope0_shift                              (1)
#define C_CORING_DATA_4_i_s_condition_mode_shift                      (0)
#define C_CORING_DATA_4_i_s_slope1_mask                               (0x00001FC0)
#define C_CORING_DATA_4_i_s_slope0_mask                               (0x0000003E)
#define C_CORING_DATA_4_i_s_condition_mode_mask                       (0x00000001)
#define C_CORING_DATA_4_i_s_slope1(data)                              (0x00001FC0&((data)<<6))
#define C_CORING_DATA_4_i_s_slope0(data)                              (0x0000003E&((data)<<1))
#define C_CORING_DATA_4_i_s_condition_mode(data)                      (0x00000001&(data))
#define C_CORING_DATA_4_get_i_s_slope1(data)                          ((0x00001FC0&(data))>>6)
#define C_CORING_DATA_4_get_i_s_slope0(data)                          ((0x0000003E&(data))>>1)
#define C_CORING_DATA_4_get_i_s_condition_mode(data)                  (0x00000001&(data))
#endif
