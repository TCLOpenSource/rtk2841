/**
* @file MacArthur5-DesignSpec-I-Domain_UZD
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_SCALEDOWN_REG_H_
#define _RBUS_SCALEDOWN_REG_H_

#include "rbus_types.h"



//  SCALEDOWN Register Address
#define  SCALEDOWN_ICH1_UZD_Ctrl0                                                0x18025204
#define  SCALEDOWN_ICH1_UZD_Ctrl0_reg_addr                                       "0xB8025204"
#define  SCALEDOWN_ICH1_UZD_Ctrl0_reg                                            0xB8025204
#define  SCALEDOWN_ICH1_UZD_Ctrl0_inst_addr                                      "0x0000"
#define  set_SCALEDOWN_ICH1_UZD_Ctrl0_reg(data)                                  (*((volatile unsigned int*)SCALEDOWN_ICH1_UZD_Ctrl0_reg)=data)
#define  get_SCALEDOWN_ICH1_UZD_Ctrl0_reg                                        (*((volatile unsigned int*)SCALEDOWN_ICH1_UZD_Ctrl0_reg))
#define  SCALEDOWN_ICH1_UZD_Ctrl0_acs_sel_shift                                  (29)
#define  SCALEDOWN_ICH1_UZD_Ctrl0_crc_sel_shift                                  (28)
#define  SCALEDOWN_ICH1_UZD_Ctrl0_to_m_domain_sel_shift                          (27)
#define  SCALEDOWN_ICH1_UZD_Ctrl0_cutout_en_shift                                (26)
#define  SCALEDOWN_ICH1_UZD_Ctrl0_sel_3d_en_shift                                (25)
#define  SCALEDOWN_ICH1_UZD_Ctrl0_truncationctrl_shift                           (24)
#define  SCALEDOWN_ICH1_UZD_Ctrl0_dummy_15_14_shift                              (14)
#define  SCALEDOWN_ICH1_UZD_Ctrl0_video_comp_en_shift                            (11)
#define  SCALEDOWN_ICH1_UZD_Ctrl0_odd_inv_shift                                  (10)
#define  SCALEDOWN_ICH1_UZD_Ctrl0_out_bit_shift                                  (9)
#define  SCALEDOWN_ICH1_UZD_Ctrl0_sort_fmt_shift                                 (8)
#define  SCALEDOWN_ICH1_UZD_Ctrl0_v_y_table_sel_shift                            (7)
#define  SCALEDOWN_ICH1_UZD_Ctrl0_v_c_table_sel_shift                            (6)
#define  SCALEDOWN_ICH1_UZD_Ctrl0_h_y_table_sel_shift                            (5)
#define  SCALEDOWN_ICH1_UZD_Ctrl0_h_c_table_sel_shift                            (4)
#define  SCALEDOWN_ICH1_UZD_Ctrl0_buffer_mode_shift                              (2)
#define  SCALEDOWN_ICH1_UZD_Ctrl0_v_zoom_en_shift                                (1)
#define  SCALEDOWN_ICH1_UZD_Ctrl0_h_zoom_en_shift                                (0)
#define  SCALEDOWN_ICH1_UZD_Ctrl0_acs_sel_mask                                   (0x20000000)
#define  SCALEDOWN_ICH1_UZD_Ctrl0_crc_sel_mask                                   (0x10000000)
#define  SCALEDOWN_ICH1_UZD_Ctrl0_to_m_domain_sel_mask                           (0x08000000)
#define  SCALEDOWN_ICH1_UZD_Ctrl0_cutout_en_mask                                 (0x04000000)
#define  SCALEDOWN_ICH1_UZD_Ctrl0_sel_3d_en_mask                                 (0x02000000)
#define  SCALEDOWN_ICH1_UZD_Ctrl0_truncationctrl_mask                            (0x01000000)
#define  SCALEDOWN_ICH1_UZD_Ctrl0_dummy_15_14_mask                               (0x0000C000)
#define  SCALEDOWN_ICH1_UZD_Ctrl0_video_comp_en_mask                             (0x00000800)
#define  SCALEDOWN_ICH1_UZD_Ctrl0_odd_inv_mask                                   (0x00000400)
#define  SCALEDOWN_ICH1_UZD_Ctrl0_out_bit_mask                                   (0x00000200)
#define  SCALEDOWN_ICH1_UZD_Ctrl0_sort_fmt_mask                                  (0x00000100)
#define  SCALEDOWN_ICH1_UZD_Ctrl0_v_y_table_sel_mask                             (0x00000080)
#define  SCALEDOWN_ICH1_UZD_Ctrl0_v_c_table_sel_mask                             (0x00000040)
#define  SCALEDOWN_ICH1_UZD_Ctrl0_h_y_table_sel_mask                             (0x00000020)
#define  SCALEDOWN_ICH1_UZD_Ctrl0_h_c_table_sel_mask                             (0x00000010)
#define  SCALEDOWN_ICH1_UZD_Ctrl0_buffer_mode_mask                               (0x0000000C)
#define  SCALEDOWN_ICH1_UZD_Ctrl0_v_zoom_en_mask                                 (0x00000002)
#define  SCALEDOWN_ICH1_UZD_Ctrl0_h_zoom_en_mask                                 (0x00000001)
#define  SCALEDOWN_ICH1_UZD_Ctrl0_acs_sel(data)                                  (0x20000000&((data)<<29))
#define  SCALEDOWN_ICH1_UZD_Ctrl0_crc_sel(data)                                  (0x10000000&((data)<<28))
#define  SCALEDOWN_ICH1_UZD_Ctrl0_to_m_domain_sel(data)                          (0x08000000&((data)<<27))
#define  SCALEDOWN_ICH1_UZD_Ctrl0_cutout_en(data)                                (0x04000000&((data)<<26))
#define  SCALEDOWN_ICH1_UZD_Ctrl0_sel_3d_en(data)                                (0x02000000&((data)<<25))
#define  SCALEDOWN_ICH1_UZD_Ctrl0_truncationctrl(data)                           (0x01000000&((data)<<24))
#define  SCALEDOWN_ICH1_UZD_Ctrl0_dummy_15_14(data)                              (0x0000C000&((data)<<14))
#define  SCALEDOWN_ICH1_UZD_Ctrl0_video_comp_en(data)                            (0x00000800&((data)<<11))
#define  SCALEDOWN_ICH1_UZD_Ctrl0_odd_inv(data)                                  (0x00000400&((data)<<10))
#define  SCALEDOWN_ICH1_UZD_Ctrl0_out_bit(data)                                  (0x00000200&((data)<<9))
#define  SCALEDOWN_ICH1_UZD_Ctrl0_sort_fmt(data)                                 (0x00000100&((data)<<8))
#define  SCALEDOWN_ICH1_UZD_Ctrl0_v_y_table_sel(data)                            (0x00000080&((data)<<7))
#define  SCALEDOWN_ICH1_UZD_Ctrl0_v_c_table_sel(data)                            (0x00000040&((data)<<6))
#define  SCALEDOWN_ICH1_UZD_Ctrl0_h_y_table_sel(data)                            (0x00000020&((data)<<5))
#define  SCALEDOWN_ICH1_UZD_Ctrl0_h_c_table_sel(data)                            (0x00000010&((data)<<4))
#define  SCALEDOWN_ICH1_UZD_Ctrl0_buffer_mode(data)                              (0x0000000C&((data)<<2))
#define  SCALEDOWN_ICH1_UZD_Ctrl0_v_zoom_en(data)                                (0x00000002&((data)<<1))
#define  SCALEDOWN_ICH1_UZD_Ctrl0_h_zoom_en(data)                                (0x00000001&(data))
#define  SCALEDOWN_ICH1_UZD_Ctrl0_get_acs_sel(data)                              ((0x20000000&(data))>>29)
#define  SCALEDOWN_ICH1_UZD_Ctrl0_get_crc_sel(data)                              ((0x10000000&(data))>>28)
#define  SCALEDOWN_ICH1_UZD_Ctrl0_get_to_m_domain_sel(data)                      ((0x08000000&(data))>>27)
#define  SCALEDOWN_ICH1_UZD_Ctrl0_get_cutout_en(data)                            ((0x04000000&(data))>>26)
#define  SCALEDOWN_ICH1_UZD_Ctrl0_get_sel_3d_en(data)                            ((0x02000000&(data))>>25)
#define  SCALEDOWN_ICH1_UZD_Ctrl0_get_truncationctrl(data)                       ((0x01000000&(data))>>24)
#define  SCALEDOWN_ICH1_UZD_Ctrl0_get_dummy_15_14(data)                          ((0x0000C000&(data))>>14)
#define  SCALEDOWN_ICH1_UZD_Ctrl0_get_video_comp_en(data)                        ((0x00000800&(data))>>11)
#define  SCALEDOWN_ICH1_UZD_Ctrl0_get_odd_inv(data)                              ((0x00000400&(data))>>10)
#define  SCALEDOWN_ICH1_UZD_Ctrl0_get_out_bit(data)                              ((0x00000200&(data))>>9)
#define  SCALEDOWN_ICH1_UZD_Ctrl0_get_sort_fmt(data)                             ((0x00000100&(data))>>8)
#define  SCALEDOWN_ICH1_UZD_Ctrl0_get_v_y_table_sel(data)                        ((0x00000080&(data))>>7)
#define  SCALEDOWN_ICH1_UZD_Ctrl0_get_v_c_table_sel(data)                        ((0x00000040&(data))>>6)
#define  SCALEDOWN_ICH1_UZD_Ctrl0_get_h_y_table_sel(data)                        ((0x00000020&(data))>>5)
#define  SCALEDOWN_ICH1_UZD_Ctrl0_get_h_c_table_sel(data)                        ((0x00000010&(data))>>4)
#define  SCALEDOWN_ICH1_UZD_Ctrl0_get_buffer_mode(data)                          ((0x0000000C&(data))>>2)
#define  SCALEDOWN_ICH1_UZD_Ctrl0_get_v_zoom_en(data)                            ((0x00000002&(data))>>1)
#define  SCALEDOWN_ICH1_UZD_Ctrl0_get_h_zoom_en(data)                            (0x00000001&(data))

#define  SCALEDOWN_ICH1_UZD_Ctrl1                                                0x18025208
#define  SCALEDOWN_ICH1_UZD_Ctrl1_reg_addr                                       "0xB8025208"
#define  SCALEDOWN_ICH1_UZD_Ctrl1_reg                                            0xB8025208
#define  SCALEDOWN_ICH1_UZD_Ctrl1_inst_addr                                      "0x0001"
#define  set_SCALEDOWN_ICH1_UZD_Ctrl1_reg(data)                                  (*((volatile unsigned int*)SCALEDOWN_ICH1_UZD_Ctrl1_reg)=data)
#define  get_SCALEDOWN_ICH1_UZD_Ctrl1_reg                                        (*((volatile unsigned int*)SCALEDOWN_ICH1_UZD_Ctrl1_reg))
#define  SCALEDOWN_ICH1_UZD_Ctrl1_four_tap_en_shift                              (26)
#define  SCALEDOWN_ICH1_UZD_Ctrl1_lp121_en_shift                                 (25)
#define  SCALEDOWN_ICH1_UZD_Ctrl1_vsd_3d_boundary_shift                          (3)
#define  SCALEDOWN_ICH1_UZD_Ctrl1_vsd_3d_mode_shift                              (0)
#define  SCALEDOWN_ICH1_UZD_Ctrl1_four_tap_en_mask                               (0x04000000)
#define  SCALEDOWN_ICH1_UZD_Ctrl1_lp121_en_mask                                  (0x02000000)
#define  SCALEDOWN_ICH1_UZD_Ctrl1_vsd_3d_boundary_mask                           (0x0000FFF8)
#define  SCALEDOWN_ICH1_UZD_Ctrl1_vsd_3d_mode_mask                               (0x00000003)
#define  SCALEDOWN_ICH1_UZD_Ctrl1_four_tap_en(data)                              (0x04000000&((data)<<26))
#define  SCALEDOWN_ICH1_UZD_Ctrl1_lp121_en(data)                                 (0x02000000&((data)<<25))
#define  SCALEDOWN_ICH1_UZD_Ctrl1_vsd_3d_boundary(data)                          (0x0000FFF8&((data)<<3))
#define  SCALEDOWN_ICH1_UZD_Ctrl1_vsd_3d_mode(data)                              (0x00000003&(data))
#define  SCALEDOWN_ICH1_UZD_Ctrl1_get_four_tap_en(data)                          ((0x04000000&(data))>>26)
#define  SCALEDOWN_ICH1_UZD_Ctrl1_get_lp121_en(data)                             ((0x02000000&(data))>>25)
#define  SCALEDOWN_ICH1_UZD_Ctrl1_get_vsd_3d_boundary(data)                      ((0x0000FFF8&(data))>>3)
#define  SCALEDOWN_ICH1_UZD_Ctrl1_get_vsd_3d_mode(data)                          (0x00000003&(data))

#define  SCALEDOWN_ICH1_UZD_Scale_Hor_Factor                                     0x1802520C
#define  SCALEDOWN_ICH1_UZD_Scale_Hor_Factor_reg_addr                            "0xB802520C"
#define  SCALEDOWN_ICH1_UZD_Scale_Hor_Factor_reg                                 0xB802520C
#define  SCALEDOWN_ICH1_UZD_Scale_Hor_Factor_inst_addr                           "0x0002"
#define  set_SCALEDOWN_ICH1_UZD_Scale_Hor_Factor_reg(data)                       (*((volatile unsigned int*)SCALEDOWN_ICH1_UZD_Scale_Hor_Factor_reg)=data)
#define  get_SCALEDOWN_ICH1_UZD_Scale_Hor_Factor_reg                             (*((volatile unsigned int*)SCALEDOWN_ICH1_UZD_Scale_Hor_Factor_reg))
#define  SCALEDOWN_ICH1_UZD_Scale_Hor_Factor_hor_fac_shift                       (0)
#define  SCALEDOWN_ICH1_UZD_Scale_Hor_Factor_hor_fac_mask                        (0x01FFFFFF)
#define  SCALEDOWN_ICH1_UZD_Scale_Hor_Factor_hor_fac(data)                       (0x01FFFFFF&(data))
#define  SCALEDOWN_ICH1_UZD_Scale_Hor_Factor_get_hor_fac(data)                   (0x01FFFFFF&(data))

#define  SCALEDOWN_ICH1_UZD_Scale_Ver_Factor                                     0x18025210
#define  SCALEDOWN_ICH1_UZD_Scale_Ver_Factor_reg_addr                            "0xB8025210"
#define  SCALEDOWN_ICH1_UZD_Scale_Ver_Factor_reg                                 0xB8025210
#define  SCALEDOWN_ICH1_UZD_Scale_Ver_Factor_inst_addr                           "0x0003"
#define  set_SCALEDOWN_ICH1_UZD_Scale_Ver_Factor_reg(data)                       (*((volatile unsigned int*)SCALEDOWN_ICH1_UZD_Scale_Ver_Factor_reg)=data)
#define  get_SCALEDOWN_ICH1_UZD_Scale_Ver_Factor_reg                             (*((volatile unsigned int*)SCALEDOWN_ICH1_UZD_Scale_Ver_Factor_reg))
#define  SCALEDOWN_ICH1_UZD_Scale_Ver_Factor_ver_ini_int_l_shift                 (26)
#define  SCALEDOWN_ICH1_UZD_Scale_Ver_Factor_ver_ini_int_shift                   (25)
#define  SCALEDOWN_ICH1_UZD_Scale_Ver_Factor_ver_fac_shift                       (0)
#define  SCALEDOWN_ICH1_UZD_Scale_Ver_Factor_ver_ini_int_l_mask                  (0x04000000)
#define  SCALEDOWN_ICH1_UZD_Scale_Ver_Factor_ver_ini_int_mask                    (0x02000000)
#define  SCALEDOWN_ICH1_UZD_Scale_Ver_Factor_ver_fac_mask                        (0x01FFFFFF)
#define  SCALEDOWN_ICH1_UZD_Scale_Ver_Factor_ver_ini_int_l(data)                 (0x04000000&((data)<<26))
#define  SCALEDOWN_ICH1_UZD_Scale_Ver_Factor_ver_ini_int(data)                   (0x02000000&((data)<<25))
#define  SCALEDOWN_ICH1_UZD_Scale_Ver_Factor_ver_fac(data)                       (0x01FFFFFF&(data))
#define  SCALEDOWN_ICH1_UZD_Scale_Ver_Factor_get_ver_ini_int_l(data)             ((0x04000000&(data))>>26)
#define  SCALEDOWN_ICH1_UZD_Scale_Ver_Factor_get_ver_ini_int(data)               ((0x02000000&(data))>>25)
#define  SCALEDOWN_ICH1_UZD_Scale_Ver_Factor_get_ver_fac(data)                   (0x01FFFFFF&(data))

#define  SCALEDOWN_ICH1_UZD_Initial_Value                                        0x18025214
#define  SCALEDOWN_ICH1_UZD_Initial_Value_reg_addr                               "0xB8025214"
#define  SCALEDOWN_ICH1_UZD_Initial_Value_reg                                    0xB8025214
#define  SCALEDOWN_ICH1_UZD_Initial_Value_inst_addr                              "0x0004"
#define  set_SCALEDOWN_ICH1_UZD_Initial_Value_reg(data)                          (*((volatile unsigned int*)SCALEDOWN_ICH1_UZD_Initial_Value_reg)=data)
#define  get_SCALEDOWN_ICH1_UZD_Initial_Value_reg                                (*((volatile unsigned int*)SCALEDOWN_ICH1_UZD_Initial_Value_reg))
#define  SCALEDOWN_ICH1_UZD_Initial_Value_hor_ini_l_shift                        (24)
#define  SCALEDOWN_ICH1_UZD_Initial_Value_ver_ini_l_shift                        (16)
#define  SCALEDOWN_ICH1_UZD_Initial_Value_hor_ini_shift                          (8)
#define  SCALEDOWN_ICH1_UZD_Initial_Value_ver_ini_shift                          (0)
#define  SCALEDOWN_ICH1_UZD_Initial_Value_hor_ini_l_mask                         (0xFF000000)
#define  SCALEDOWN_ICH1_UZD_Initial_Value_ver_ini_l_mask                         (0x00FF0000)
#define  SCALEDOWN_ICH1_UZD_Initial_Value_hor_ini_mask                           (0x0000FF00)
#define  SCALEDOWN_ICH1_UZD_Initial_Value_ver_ini_mask                           (0x000000FF)
#define  SCALEDOWN_ICH1_UZD_Initial_Value_hor_ini_l(data)                        (0xFF000000&((data)<<24))
#define  SCALEDOWN_ICH1_UZD_Initial_Value_ver_ini_l(data)                        (0x00FF0000&((data)<<16))
#define  SCALEDOWN_ICH1_UZD_Initial_Value_hor_ini(data)                          (0x0000FF00&((data)<<8))
#define  SCALEDOWN_ICH1_UZD_Initial_Value_ver_ini(data)                          (0x000000FF&(data))
#define  SCALEDOWN_ICH1_UZD_Initial_Value_get_hor_ini_l(data)                    ((0xFF000000&(data))>>24)
#define  SCALEDOWN_ICH1_UZD_Initial_Value_get_ver_ini_l(data)                    ((0x00FF0000&(data))>>16)
#define  SCALEDOWN_ICH1_UZD_Initial_Value_get_hor_ini(data)                      ((0x0000FF00&(data))>>8)
#define  SCALEDOWN_ICH1_UZD_Initial_Value_get_ver_ini(data)                      (0x000000FF&(data))

#define  SCALEDOWN_ICH1_UZD_Hor_Delta1                                           0x18025218
#define  SCALEDOWN_ICH1_UZD_Hor_Delta1_reg_addr                                  "0xB8025218"
#define  SCALEDOWN_ICH1_UZD_Hor_Delta1_reg                                       0xB8025218
#define  SCALEDOWN_ICH1_UZD_Hor_Delta1_inst_addr                                 "0x0005"
#define  set_SCALEDOWN_ICH1_UZD_Hor_Delta1_reg(data)                             (*((volatile unsigned int*)SCALEDOWN_ICH1_UZD_Hor_Delta1_reg)=data)
#define  get_SCALEDOWN_ICH1_UZD_Hor_Delta1_reg                                   (*((volatile unsigned int*)SCALEDOWN_ICH1_UZD_Hor_Delta1_reg))
#define  SCALEDOWN_ICH1_UZD_Hor_Delta1_nl_d1_shift                               (0)
#define  SCALEDOWN_ICH1_UZD_Hor_Delta1_nl_d1_mask                                (0x00003FFF)
#define  SCALEDOWN_ICH1_UZD_Hor_Delta1_nl_d1(data)                               (0x00003FFF&(data))
#define  SCALEDOWN_ICH1_UZD_Hor_Delta1_get_nl_d1(data)                           (0x00003FFF&(data))

#define  SCALEDOWN_ICH1_UZD_Hor_Segment                                          0x1802521C
#define  SCALEDOWN_ICH1_UZD_Hor_Segment_reg_addr                                 "0xB802521C"
#define  SCALEDOWN_ICH1_UZD_Hor_Segment_reg                                      0xB802521C
#define  SCALEDOWN_ICH1_UZD_Hor_Segment_inst_addr                                "0x0006"
#define  set_SCALEDOWN_ICH1_UZD_Hor_Segment_reg(data)                            (*((volatile unsigned int*)SCALEDOWN_ICH1_UZD_Hor_Segment_reg)=data)
#define  get_SCALEDOWN_ICH1_UZD_Hor_Segment_reg                                  (*((volatile unsigned int*)SCALEDOWN_ICH1_UZD_Hor_Segment_reg))
#define  SCALEDOWN_ICH1_UZD_Hor_Segment_nl_seg1_shift                            (16)
#define  SCALEDOWN_ICH1_UZD_Hor_Segment_nl_seg2_shift                            (0)
#define  SCALEDOWN_ICH1_UZD_Hor_Segment_nl_seg1_mask                             (0x0FFF0000)
#define  SCALEDOWN_ICH1_UZD_Hor_Segment_nl_seg2_mask                             (0x00000FFF)
#define  SCALEDOWN_ICH1_UZD_Hor_Segment_nl_seg1(data)                            (0x0FFF0000&((data)<<16))
#define  SCALEDOWN_ICH1_UZD_Hor_Segment_nl_seg2(data)                            (0x00000FFF&(data))
#define  SCALEDOWN_ICH1_UZD_Hor_Segment_get_nl_seg1(data)                        ((0x0FFF0000&(data))>>16)
#define  SCALEDOWN_ICH1_UZD_Hor_Segment_get_nl_seg2(data)                        (0x00000FFF&(data))

#define  SCALEDOWN_ICH1_UZD_CRC_CTRL                                             0x18025220
#define  SCALEDOWN_ICH1_UZD_CRC_CTRL_reg_addr                                    "0xB8025220"
#define  SCALEDOWN_ICH1_UZD_CRC_CTRL_reg                                         0xB8025220
#define  SCALEDOWN_ICH1_UZD_CRC_CTRL_inst_addr                                   "0x0007"
#define  set_SCALEDOWN_ICH1_UZD_CRC_CTRL_reg(data)                               (*((volatile unsigned int*)SCALEDOWN_ICH1_UZD_CRC_CTRL_reg)=data)
#define  get_SCALEDOWN_ICH1_UZD_CRC_CTRL_reg                                     (*((volatile unsigned int*)SCALEDOWN_ICH1_UZD_CRC_CTRL_reg))
#define  SCALEDOWN_ICH1_UZD_CRC_CTRL_crc_source_vsd_hsd_sel_shift                (5)
#define  SCALEDOWN_ICH1_UZD_CRC_CTRL_r_auto_cmp_en_shift                         (4)
#define  SCALEDOWN_ICH1_UZD_CRC_CTRL_l_auto_cmp_en_shift                         (3)
#define  SCALEDOWN_ICH1_UZD_CRC_CTRL_crc_3d_en_shift                             (2)
#define  SCALEDOWN_ICH1_UZD_CRC_CTRL_conti_shift                                 (1)
#define  SCALEDOWN_ICH1_UZD_CRC_CTRL_start_shift                                 (0)
#define  SCALEDOWN_ICH1_UZD_CRC_CTRL_crc_source_vsd_hsd_sel_mask                 (0x00000020)
#define  SCALEDOWN_ICH1_UZD_CRC_CTRL_r_auto_cmp_en_mask                          (0x00000010)
#define  SCALEDOWN_ICH1_UZD_CRC_CTRL_l_auto_cmp_en_mask                          (0x00000008)
#define  SCALEDOWN_ICH1_UZD_CRC_CTRL_crc_3d_en_mask                              (0x00000004)
#define  SCALEDOWN_ICH1_UZD_CRC_CTRL_conti_mask                                  (0x00000002)
#define  SCALEDOWN_ICH1_UZD_CRC_CTRL_start_mask                                  (0x00000001)
#define  SCALEDOWN_ICH1_UZD_CRC_CTRL_crc_source_vsd_hsd_sel(data)                (0x00000020&((data)<<5))
#define  SCALEDOWN_ICH1_UZD_CRC_CTRL_r_auto_cmp_en(data)                         (0x00000010&((data)<<4))
#define  SCALEDOWN_ICH1_UZD_CRC_CTRL_l_auto_cmp_en(data)                         (0x00000008&((data)<<3))
#define  SCALEDOWN_ICH1_UZD_CRC_CTRL_crc_3d_en(data)                             (0x00000004&((data)<<2))
#define  SCALEDOWN_ICH1_UZD_CRC_CTRL_conti(data)                                 (0x00000002&((data)<<1))
#define  SCALEDOWN_ICH1_UZD_CRC_CTRL_start(data)                                 (0x00000001&(data))
#define  SCALEDOWN_ICH1_UZD_CRC_CTRL_get_crc_source_vsd_hsd_sel(data)            ((0x00000020&(data))>>5)
#define  SCALEDOWN_ICH1_UZD_CRC_CTRL_get_r_auto_cmp_en(data)                     ((0x00000010&(data))>>4)
#define  SCALEDOWN_ICH1_UZD_CRC_CTRL_get_l_auto_cmp_en(data)                     ((0x00000008&(data))>>3)
#define  SCALEDOWN_ICH1_UZD_CRC_CTRL_get_crc_3d_en(data)                         ((0x00000004&(data))>>2)
#define  SCALEDOWN_ICH1_UZD_CRC_CTRL_get_conti(data)                             ((0x00000002&(data))>>1)
#define  SCALEDOWN_ICH1_UZD_CRC_CTRL_get_start(data)                             (0x00000001&(data))

#define  SCALEDOWN_ICH1_UZD_CRC_Result                                           0x18025224
#define  SCALEDOWN_ICH1_UZD_CRC_Result_reg_addr                                  "0xB8025224"
#define  SCALEDOWN_ICH1_UZD_CRC_Result_reg                                       0xB8025224
#define  SCALEDOWN_ICH1_UZD_CRC_Result_inst_addr                                 "0x0008"
#define  set_SCALEDOWN_ICH1_UZD_CRC_Result_reg(data)                             (*((volatile unsigned int*)SCALEDOWN_ICH1_UZD_CRC_Result_reg)=data)
#define  get_SCALEDOWN_ICH1_UZD_CRC_Result_reg                                   (*((volatile unsigned int*)SCALEDOWN_ICH1_UZD_CRC_Result_reg))
#define  SCALEDOWN_ICH1_UZD_CRC_Result_crc_l_result_shift                        (0)
#define  SCALEDOWN_ICH1_UZD_CRC_Result_crc_l_result_mask                         (0xFFFFFFFF)
#define  SCALEDOWN_ICH1_UZD_CRC_Result_crc_l_result(data)                        (0xFFFFFFFF&(data))
#define  SCALEDOWN_ICH1_UZD_CRC_Result_get_crc_l_result(data)                    (0xFFFFFFFF&(data))

#define  SCALEDOWN_ICH1_UZD_CRC_Result_right                                     0x18025228
#define  SCALEDOWN_ICH1_UZD_CRC_Result_right_reg_addr                            "0xB8025228"
#define  SCALEDOWN_ICH1_UZD_CRC_Result_right_reg                                 0xB8025228
#define  SCALEDOWN_ICH1_UZD_CRC_Result_right_inst_addr                           "0x0009"
#define  set_SCALEDOWN_ICH1_UZD_CRC_Result_right_reg(data)                       (*((volatile unsigned int*)SCALEDOWN_ICH1_UZD_CRC_Result_right_reg)=data)
#define  get_SCALEDOWN_ICH1_UZD_CRC_Result_right_reg                             (*((volatile unsigned int*)SCALEDOWN_ICH1_UZD_CRC_Result_right_reg))
#define  SCALEDOWN_ICH1_UZD_CRC_Result_right_crc_r_result_shift                  (0)
#define  SCALEDOWN_ICH1_UZD_CRC_Result_right_crc_r_result_mask                   (0xFFFFFFFF)
#define  SCALEDOWN_ICH1_UZD_CRC_Result_right_crc_r_result(data)                  (0xFFFFFFFF&(data))
#define  SCALEDOWN_ICH1_UZD_CRC_Result_right_get_crc_r_result(data)              (0xFFFFFFFF&(data))

#define  SCALEDOWN_ICH1_UZD_L_DES_CRC                                            0x1802522C
#define  SCALEDOWN_ICH1_UZD_L_DES_CRC_reg_addr                                   "0xB802522C"
#define  SCALEDOWN_ICH1_UZD_L_DES_CRC_reg                                        0xB802522C
#define  SCALEDOWN_ICH1_UZD_L_DES_CRC_inst_addr                                  "0x000A"
#define  set_SCALEDOWN_ICH1_UZD_L_DES_CRC_reg(data)                              (*((volatile unsigned int*)SCALEDOWN_ICH1_UZD_L_DES_CRC_reg)=data)
#define  get_SCALEDOWN_ICH1_UZD_L_DES_CRC_reg                                    (*((volatile unsigned int*)SCALEDOWN_ICH1_UZD_L_DES_CRC_reg))
#define  SCALEDOWN_ICH1_UZD_L_DES_CRC_l_des_crc_shift                            (0)
#define  SCALEDOWN_ICH1_UZD_L_DES_CRC_l_des_crc_mask                             (0xFFFFFFFF)
#define  SCALEDOWN_ICH1_UZD_L_DES_CRC_l_des_crc(data)                            (0xFFFFFFFF&(data))
#define  SCALEDOWN_ICH1_UZD_L_DES_CRC_get_l_des_crc(data)                        (0xFFFFFFFF&(data))

#define  SCALEDOWN_ICH1_UZD_R_DES_CRC                                            0x18025230
#define  SCALEDOWN_ICH1_UZD_R_DES_CRC_reg_addr                                   "0xB8025230"
#define  SCALEDOWN_ICH1_UZD_R_DES_CRC_reg                                        0xB8025230
#define  SCALEDOWN_ICH1_UZD_R_DES_CRC_inst_addr                                  "0x000B"
#define  set_SCALEDOWN_ICH1_UZD_R_DES_CRC_reg(data)                              (*((volatile unsigned int*)SCALEDOWN_ICH1_UZD_R_DES_CRC_reg)=data)
#define  get_SCALEDOWN_ICH1_UZD_R_DES_CRC_reg                                    (*((volatile unsigned int*)SCALEDOWN_ICH1_UZD_R_DES_CRC_reg))
#define  SCALEDOWN_ICH1_UZD_R_DES_CRC_r_des_crc_shift                            (0)
#define  SCALEDOWN_ICH1_UZD_R_DES_CRC_r_des_crc_mask                             (0xFFFFFFFF)
#define  SCALEDOWN_ICH1_UZD_R_DES_CRC_r_des_crc(data)                            (0xFFFFFFFF&(data))
#define  SCALEDOWN_ICH1_UZD_R_DES_CRC_get_r_des_crc(data)                        (0xFFFFFFFF&(data))

#define  SCALEDOWN_ICH1_UZD_CRC_ERR_CNT                                          0x18025234
#define  SCALEDOWN_ICH1_UZD_CRC_ERR_CNT_reg_addr                                 "0xB8025234"
#define  SCALEDOWN_ICH1_UZD_CRC_ERR_CNT_reg                                      0xB8025234
#define  SCALEDOWN_ICH1_UZD_CRC_ERR_CNT_inst_addr                                "0x000C"
#define  set_SCALEDOWN_ICH1_UZD_CRC_ERR_CNT_reg(data)                            (*((volatile unsigned int*)SCALEDOWN_ICH1_UZD_CRC_ERR_CNT_reg)=data)
#define  get_SCALEDOWN_ICH1_UZD_CRC_ERR_CNT_reg                                  (*((volatile unsigned int*)SCALEDOWN_ICH1_UZD_CRC_ERR_CNT_reg))
#define  SCALEDOWN_ICH1_UZD_CRC_ERR_CNT_r_crc_err_cnt_shift                      (16)
#define  SCALEDOWN_ICH1_UZD_CRC_ERR_CNT_l_crc_err_cnt_shift                      (0)
#define  SCALEDOWN_ICH1_UZD_CRC_ERR_CNT_r_crc_err_cnt_mask                       (0xFFFF0000)
#define  SCALEDOWN_ICH1_UZD_CRC_ERR_CNT_l_crc_err_cnt_mask                       (0x0000FFFF)
#define  SCALEDOWN_ICH1_UZD_CRC_ERR_CNT_r_crc_err_cnt(data)                      (0xFFFF0000&((data)<<16))
#define  SCALEDOWN_ICH1_UZD_CRC_ERR_CNT_l_crc_err_cnt(data)                      (0x0000FFFF&(data))
#define  SCALEDOWN_ICH1_UZD_CRC_ERR_CNT_get_r_crc_err_cnt(data)                  ((0xFFFF0000&(data))>>16)
#define  SCALEDOWN_ICH1_UZD_CRC_ERR_CNT_get_l_crc_err_cnt(data)                  (0x0000FFFF&(data))

#define  SCALEDOWN_ICH1_IBUFF_CTRLI_BUFF_CTRL                                    0x18025240
#define  SCALEDOWN_ICH1_IBUFF_CTRLI_BUFF_CTRL_reg_addr                           "0xB8025240"
#define  SCALEDOWN_ICH1_IBUFF_CTRLI_BUFF_CTRL_reg                                0xB8025240
#define  SCALEDOWN_ICH1_IBUFF_CTRLI_BUFF_CTRL_inst_addr                          "0x000D"
#define  set_SCALEDOWN_ICH1_IBUFF_CTRLI_BUFF_CTRL_reg(data)                      (*((volatile unsigned int*)SCALEDOWN_ICH1_IBUFF_CTRLI_BUFF_CTRL_reg)=data)
#define  get_SCALEDOWN_ICH1_IBUFF_CTRLI_BUFF_CTRL_reg                            (*((volatile unsigned int*)SCALEDOWN_ICH1_IBUFF_CTRLI_BUFF_CTRL_reg))
#define  SCALEDOWN_ICH1_IBUFF_CTRLI_BUFF_CTRL_ibuf_v_size_shift                  (16)
#define  SCALEDOWN_ICH1_IBUFF_CTRLI_BUFF_CTRL_ibuf_h_size_shift                  (0)
#define  SCALEDOWN_ICH1_IBUFF_CTRLI_BUFF_CTRL_ibuf_v_size_mask                   (0x1FFF0000)
#define  SCALEDOWN_ICH1_IBUFF_CTRLI_BUFF_CTRL_ibuf_h_size_mask                   (0x00001FFF)
#define  SCALEDOWN_ICH1_IBUFF_CTRLI_BUFF_CTRL_ibuf_v_size(data)                  (0x1FFF0000&((data)<<16))
#define  SCALEDOWN_ICH1_IBUFF_CTRLI_BUFF_CTRL_ibuf_h_size(data)                  (0x00001FFF&(data))
#define  SCALEDOWN_ICH1_IBUFF_CTRLI_BUFF_CTRL_get_ibuf_v_size(data)              ((0x1FFF0000&(data))>>16)
#define  SCALEDOWN_ICH1_IBUFF_CTRLI_BUFF_CTRL_get_ibuf_h_size(data)              (0x00001FFF&(data))

#define  SCALEDOWN_ICH1_UZD_channel_swap                                         0x18025244
#define  SCALEDOWN_ICH1_UZD_channel_swap_reg_addr                                "0xB8025244"
#define  SCALEDOWN_ICH1_UZD_channel_swap_reg                                     0xB8025244
#define  SCALEDOWN_ICH1_UZD_channel_swap_inst_addr                               "0x000E"
#define  set_SCALEDOWN_ICH1_UZD_channel_swap_reg(data)                           (*((volatile unsigned int*)SCALEDOWN_ICH1_UZD_channel_swap_reg)=data)
#define  get_SCALEDOWN_ICH1_UZD_channel_swap_reg                                 (*((volatile unsigned int*)SCALEDOWN_ICH1_UZD_channel_swap_reg))
#define  SCALEDOWN_ICH1_UZD_channel_swap_rgb_ch_swap_shift                       (0)
#define  SCALEDOWN_ICH1_UZD_channel_swap_rgb_ch_swap_mask                        (0x00000007)
#define  SCALEDOWN_ICH1_UZD_channel_swap_rgb_ch_swap(data)                       (0x00000007&(data))
#define  SCALEDOWN_ICH1_UZD_channel_swap_get_rgb_ch_swap(data)                   (0x00000007&(data))

#define  SCALEDOWN_ICH1_UZD_DB_CTRL                                              0x18025248
#define  SCALEDOWN_ICH1_UZD_DB_CTRL_reg_addr                                     "0xB8025248"
#define  SCALEDOWN_ICH1_UZD_DB_CTRL_reg                                          0xB8025248
#define  SCALEDOWN_ICH1_UZD_DB_CTRL_inst_addr                                    "0x000F"
#define  set_SCALEDOWN_ICH1_UZD_DB_CTRL_reg(data)                                (*((volatile unsigned int*)SCALEDOWN_ICH1_UZD_DB_CTRL_reg)=data)
#define  get_SCALEDOWN_ICH1_UZD_DB_CTRL_reg                                      (*((volatile unsigned int*)SCALEDOWN_ICH1_UZD_DB_CTRL_reg))
#define  SCALEDOWN_ICH1_UZD_DB_CTRL_mdom_comp_rd_sel_shift                       (9)
#define  SCALEDOWN_ICH1_UZD_DB_CTRL_mdom_comp_db_en_shift                        (8)
#define  SCALEDOWN_ICH1_UZD_DB_CTRL_h_db_apply_shift                             (6)
#define  SCALEDOWN_ICH1_UZD_DB_CTRL_h_db_rd_sel_shift                            (5)
#define  SCALEDOWN_ICH1_UZD_DB_CTRL_h_db_en_shift                                (4)
#define  SCALEDOWN_ICH1_UZD_DB_CTRL_v_db_apply_shift                             (2)
#define  SCALEDOWN_ICH1_UZD_DB_CTRL_v_db_rd_sel_shift                            (1)
#define  SCALEDOWN_ICH1_UZD_DB_CTRL_v_db_en_shift                                (0)
#define  SCALEDOWN_ICH1_UZD_DB_CTRL_mdom_comp_rd_sel_mask                        (0x00000200)
#define  SCALEDOWN_ICH1_UZD_DB_CTRL_mdom_comp_db_en_mask                         (0x00000100)
#define  SCALEDOWN_ICH1_UZD_DB_CTRL_h_db_apply_mask                              (0x00000040)
#define  SCALEDOWN_ICH1_UZD_DB_CTRL_h_db_rd_sel_mask                             (0x00000020)
#define  SCALEDOWN_ICH1_UZD_DB_CTRL_h_db_en_mask                                 (0x00000010)
#define  SCALEDOWN_ICH1_UZD_DB_CTRL_v_db_apply_mask                              (0x00000004)
#define  SCALEDOWN_ICH1_UZD_DB_CTRL_v_db_rd_sel_mask                             (0x00000002)
#define  SCALEDOWN_ICH1_UZD_DB_CTRL_v_db_en_mask                                 (0x00000001)
#define  SCALEDOWN_ICH1_UZD_DB_CTRL_mdom_comp_rd_sel(data)                       (0x00000200&((data)<<9))
#define  SCALEDOWN_ICH1_UZD_DB_CTRL_mdom_comp_db_en(data)                        (0x00000100&((data)<<8))
#define  SCALEDOWN_ICH1_UZD_DB_CTRL_h_db_apply(data)                             (0x00000040&((data)<<6))
#define  SCALEDOWN_ICH1_UZD_DB_CTRL_h_db_rd_sel(data)                            (0x00000020&((data)<<5))
#define  SCALEDOWN_ICH1_UZD_DB_CTRL_h_db_en(data)                                (0x00000010&((data)<<4))
#define  SCALEDOWN_ICH1_UZD_DB_CTRL_v_db_apply(data)                             (0x00000004&((data)<<2))
#define  SCALEDOWN_ICH1_UZD_DB_CTRL_v_db_rd_sel(data)                            (0x00000002&((data)<<1))
#define  SCALEDOWN_ICH1_UZD_DB_CTRL_v_db_en(data)                                (0x00000001&(data))
#define  SCALEDOWN_ICH1_UZD_DB_CTRL_get_mdom_comp_rd_sel(data)                   ((0x00000200&(data))>>9)
#define  SCALEDOWN_ICH1_UZD_DB_CTRL_get_mdom_comp_db_en(data)                    ((0x00000100&(data))>>8)
#define  SCALEDOWN_ICH1_UZD_DB_CTRL_get_h_db_apply(data)                         ((0x00000040&(data))>>6)
#define  SCALEDOWN_ICH1_UZD_DB_CTRL_get_h_db_rd_sel(data)                        ((0x00000020&(data))>>5)
#define  SCALEDOWN_ICH1_UZD_DB_CTRL_get_h_db_en(data)                            ((0x00000010&(data))>>4)
#define  SCALEDOWN_ICH1_UZD_DB_CTRL_get_v_db_apply(data)                         ((0x00000004&(data))>>2)
#define  SCALEDOWN_ICH1_UZD_DB_CTRL_get_v_db_rd_sel(data)                        ((0x00000002&(data))>>1)
#define  SCALEDOWN_ICH1_UZD_DB_CTRL_get_v_db_en(data)                            (0x00000001&(data))

#define  SCALEDOWN_UZD_Timing_monitor_ctrl                                       0x18025250
#define  SCALEDOWN_UZD_Timing_monitor_ctrl_reg_addr                              "0xB8025250"
#define  SCALEDOWN_UZD_Timing_monitor_ctrl_reg                                   0xB8025250
#define  SCALEDOWN_UZD_Timing_monitor_ctrl_inst_addr                             "0x0010"
#define  set_SCALEDOWN_UZD_Timing_monitor_ctrl_reg(data)                         (*((volatile unsigned int*)SCALEDOWN_UZD_Timing_monitor_ctrl_reg)=data)
#define  get_SCALEDOWN_UZD_Timing_monitor_ctrl_reg                               (*((volatile unsigned int*)SCALEDOWN_UZD_Timing_monitor_ctrl_reg))
#define  SCALEDOWN_UZD_Timing_monitor_ctrl_timing_monitor_en_shift               (31)
#define  SCALEDOWN_UZD_Timing_monitor_ctrl_timing_monitor_i2rnd_mode_shift       (29)
#define  SCALEDOWN_UZD_Timing_monitor_ctrl_timing_monitor_src_shift              (28)
#define  SCALEDOWN_UZD_Timing_monitor_ctrl_timing_monitor_unit_shift             (27)
#define  SCALEDOWN_UZD_Timing_monitor_ctrl_timing_monitor_multi_mode_shift       (26)
#define  SCALEDOWN_UZD_Timing_monitor_ctrl_timing_monitor_compare_shift          (24)
#define  SCALEDOWN_UZD_Timing_monitor_ctrl_timing_monitor_sta0_shift             (12)
#define  SCALEDOWN_UZD_Timing_monitor_ctrl_timing_monitor_end0_shift             (8)
#define  SCALEDOWN_UZD_Timing_monitor_ctrl_timing_monitor_sta1_shift             (4)
#define  SCALEDOWN_UZD_Timing_monitor_ctrl_timing_monitor_end1_shift             (0)
#define  SCALEDOWN_UZD_Timing_monitor_ctrl_timing_monitor_en_mask                (0x80000000)
#define  SCALEDOWN_UZD_Timing_monitor_ctrl_timing_monitor_i2rnd_mode_mask        (0x60000000)
#define  SCALEDOWN_UZD_Timing_monitor_ctrl_timing_monitor_src_mask               (0x10000000)
#define  SCALEDOWN_UZD_Timing_monitor_ctrl_timing_monitor_unit_mask              (0x08000000)
#define  SCALEDOWN_UZD_Timing_monitor_ctrl_timing_monitor_multi_mode_mask        (0x04000000)
#define  SCALEDOWN_UZD_Timing_monitor_ctrl_timing_monitor_compare_mask           (0x03000000)
#define  SCALEDOWN_UZD_Timing_monitor_ctrl_timing_monitor_sta0_mask              (0x0000F000)
#define  SCALEDOWN_UZD_Timing_monitor_ctrl_timing_monitor_end0_mask              (0x00000F00)
#define  SCALEDOWN_UZD_Timing_monitor_ctrl_timing_monitor_sta1_mask              (0x000000F0)
#define  SCALEDOWN_UZD_Timing_monitor_ctrl_timing_monitor_end1_mask              (0x0000000F)
#define  SCALEDOWN_UZD_Timing_monitor_ctrl_timing_monitor_en(data)               (0x80000000&((data)<<31))
#define  SCALEDOWN_UZD_Timing_monitor_ctrl_timing_monitor_i2rnd_mode(data)       (0x60000000&((data)<<29))
#define  SCALEDOWN_UZD_Timing_monitor_ctrl_timing_monitor_src(data)              (0x10000000&((data)<<28))
#define  SCALEDOWN_UZD_Timing_monitor_ctrl_timing_monitor_unit(data)             (0x08000000&((data)<<27))
#define  SCALEDOWN_UZD_Timing_monitor_ctrl_timing_monitor_multi_mode(data)       (0x04000000&((data)<<26))
#define  SCALEDOWN_UZD_Timing_monitor_ctrl_timing_monitor_compare(data)          (0x03000000&((data)<<24))
#define  SCALEDOWN_UZD_Timing_monitor_ctrl_timing_monitor_sta0(data)             (0x0000F000&((data)<<12))
#define  SCALEDOWN_UZD_Timing_monitor_ctrl_timing_monitor_end0(data)             (0x00000F00&((data)<<8))
#define  SCALEDOWN_UZD_Timing_monitor_ctrl_timing_monitor_sta1(data)             (0x000000F0&((data)<<4))
#define  SCALEDOWN_UZD_Timing_monitor_ctrl_timing_monitor_end1(data)             (0x0000000F&(data))
#define  SCALEDOWN_UZD_Timing_monitor_ctrl_get_timing_monitor_en(data)           ((0x80000000&(data))>>31)
#define  SCALEDOWN_UZD_Timing_monitor_ctrl_get_timing_monitor_i2rnd_mode(data)   ((0x60000000&(data))>>29)
#define  SCALEDOWN_UZD_Timing_monitor_ctrl_get_timing_monitor_src(data)          ((0x10000000&(data))>>28)
#define  SCALEDOWN_UZD_Timing_monitor_ctrl_get_timing_monitor_unit(data)         ((0x08000000&(data))>>27)
#define  SCALEDOWN_UZD_Timing_monitor_ctrl_get_timing_monitor_multi_mode(data)   ((0x04000000&(data))>>26)
#define  SCALEDOWN_UZD_Timing_monitor_ctrl_get_timing_monitor_compare(data)      ((0x03000000&(data))>>24)
#define  SCALEDOWN_UZD_Timing_monitor_ctrl_get_timing_monitor_sta0(data)         ((0x0000F000&(data))>>12)
#define  SCALEDOWN_UZD_Timing_monitor_ctrl_get_timing_monitor_end0(data)         ((0x00000F00&(data))>>8)
#define  SCALEDOWN_UZD_Timing_monitor_ctrl_get_timing_monitor_sta1(data)         ((0x000000F0&(data))>>4)
#define  SCALEDOWN_UZD_Timing_monitor_ctrl_get_timing_monitor_end1(data)         (0x0000000F&(data))

#define  SCALEDOWN_UZD_Timing_monitor_multi                                      0x18025254
#define  SCALEDOWN_UZD_Timing_monitor_multi_reg_addr                             "0xB8025254"
#define  SCALEDOWN_UZD_Timing_monitor_multi_reg                                  0xB8025254
#define  SCALEDOWN_UZD_Timing_monitor_multi_inst_addr                            "0x0011"
#define  set_SCALEDOWN_UZD_Timing_monitor_multi_reg(data)                        (*((volatile unsigned int*)SCALEDOWN_UZD_Timing_monitor_multi_reg)=data)
#define  get_SCALEDOWN_UZD_Timing_monitor_multi_reg                              (*((volatile unsigned int*)SCALEDOWN_UZD_Timing_monitor_multi_reg))
#define  SCALEDOWN_UZD_Timing_monitor_multi_timing_monitor_sta2_shift            (28)
#define  SCALEDOWN_UZD_Timing_monitor_multi_timing_monitor_end2_shift            (24)
#define  SCALEDOWN_UZD_Timing_monitor_multi_timing_monitor_sta3_shift            (20)
#define  SCALEDOWN_UZD_Timing_monitor_multi_timing_monitor_end3_shift            (16)
#define  SCALEDOWN_UZD_Timing_monitor_multi_timing_monitor_sta4_shift            (12)
#define  SCALEDOWN_UZD_Timing_monitor_multi_timing_monitor_end4_shift            (8)
#define  SCALEDOWN_UZD_Timing_monitor_multi_timing_monitor_sta5_shift            (4)
#define  SCALEDOWN_UZD_Timing_monitor_multi_timing_monitor_end5_shift            (0)
#define  SCALEDOWN_UZD_Timing_monitor_multi_timing_monitor_sta2_mask             (0xF0000000)
#define  SCALEDOWN_UZD_Timing_monitor_multi_timing_monitor_end2_mask             (0x0F000000)
#define  SCALEDOWN_UZD_Timing_monitor_multi_timing_monitor_sta3_mask             (0x00F00000)
#define  SCALEDOWN_UZD_Timing_monitor_multi_timing_monitor_end3_mask             (0x000F0000)
#define  SCALEDOWN_UZD_Timing_monitor_multi_timing_monitor_sta4_mask             (0x0000F000)
#define  SCALEDOWN_UZD_Timing_monitor_multi_timing_monitor_end4_mask             (0x00000F00)
#define  SCALEDOWN_UZD_Timing_monitor_multi_timing_monitor_sta5_mask             (0x000000F0)
#define  SCALEDOWN_UZD_Timing_monitor_multi_timing_monitor_end5_mask             (0x0000000F)
#define  SCALEDOWN_UZD_Timing_monitor_multi_timing_monitor_sta2(data)            (0xF0000000&((data)<<28))
#define  SCALEDOWN_UZD_Timing_monitor_multi_timing_monitor_end2(data)            (0x0F000000&((data)<<24))
#define  SCALEDOWN_UZD_Timing_monitor_multi_timing_monitor_sta3(data)            (0x00F00000&((data)<<20))
#define  SCALEDOWN_UZD_Timing_monitor_multi_timing_monitor_end3(data)            (0x000F0000&((data)<<16))
#define  SCALEDOWN_UZD_Timing_monitor_multi_timing_monitor_sta4(data)            (0x0000F000&((data)<<12))
#define  SCALEDOWN_UZD_Timing_monitor_multi_timing_monitor_end4(data)            (0x00000F00&((data)<<8))
#define  SCALEDOWN_UZD_Timing_monitor_multi_timing_monitor_sta5(data)            (0x000000F0&((data)<<4))
#define  SCALEDOWN_UZD_Timing_monitor_multi_timing_monitor_end5(data)            (0x0000000F&(data))
#define  SCALEDOWN_UZD_Timing_monitor_multi_get_timing_monitor_sta2(data)        ((0xF0000000&(data))>>28)
#define  SCALEDOWN_UZD_Timing_monitor_multi_get_timing_monitor_end2(data)        ((0x0F000000&(data))>>24)
#define  SCALEDOWN_UZD_Timing_monitor_multi_get_timing_monitor_sta3(data)        ((0x00F00000&(data))>>20)
#define  SCALEDOWN_UZD_Timing_monitor_multi_get_timing_monitor_end3(data)        ((0x000F0000&(data))>>16)
#define  SCALEDOWN_UZD_Timing_monitor_multi_get_timing_monitor_sta4(data)        ((0x0000F000&(data))>>12)
#define  SCALEDOWN_UZD_Timing_monitor_multi_get_timing_monitor_end4(data)        ((0x00000F00&(data))>>8)
#define  SCALEDOWN_UZD_Timing_monitor_multi_get_timing_monitor_sta5(data)        ((0x000000F0&(data))>>4)
#define  SCALEDOWN_UZD_Timing_monitor_multi_get_timing_monitor_end5(data)        (0x0000000F&(data))

#define  SCALEDOWN_UZD_Timing_monitor_compare_th                                 0x18025258
#define  SCALEDOWN_UZD_Timing_monitor_compare_th_reg_addr                        "0xB8025258"
#define  SCALEDOWN_UZD_Timing_monitor_compare_th_reg                             0xB8025258
#define  SCALEDOWN_UZD_Timing_monitor_compare_th_inst_addr                       "0x0012"
#define  set_SCALEDOWN_UZD_Timing_monitor_compare_th_reg(data)                   (*((volatile unsigned int*)SCALEDOWN_UZD_Timing_monitor_compare_th_reg)=data)
#define  get_SCALEDOWN_UZD_Timing_monitor_compare_th_reg                         (*((volatile unsigned int*)SCALEDOWN_UZD_Timing_monitor_compare_th_reg))
#define  SCALEDOWN_UZD_Timing_monitor_compare_th_t_m_compare_th_shift            (0)
#define  SCALEDOWN_UZD_Timing_monitor_compare_th_t_m_compare_th_mask             (0x0FFFFFFF)
#define  SCALEDOWN_UZD_Timing_monitor_compare_th_t_m_compare_th(data)            (0x0FFFFFFF&(data))
#define  SCALEDOWN_UZD_Timing_monitor_compare_th_get_t_m_compare_th(data)        (0x0FFFFFFF&(data))

#define  SCALEDOWN_UZD_Timing_monitor_golden                                     0x1802525C
#define  SCALEDOWN_UZD_Timing_monitor_golden_reg_addr                            "0xB802525C"
#define  SCALEDOWN_UZD_Timing_monitor_golden_reg                                 0xB802525C
#define  SCALEDOWN_UZD_Timing_monitor_golden_inst_addr                           "0x0013"
#define  set_SCALEDOWN_UZD_Timing_monitor_golden_reg(data)                       (*((volatile unsigned int*)SCALEDOWN_UZD_Timing_monitor_golden_reg)=data)
#define  get_SCALEDOWN_UZD_Timing_monitor_golden_reg                             (*((volatile unsigned int*)SCALEDOWN_UZD_Timing_monitor_golden_reg))
#define  SCALEDOWN_UZD_Timing_monitor_golden_t_m_golden_shift                    (0)
#define  SCALEDOWN_UZD_Timing_monitor_golden_t_m_golden_mask                     (0x0FFFFFFF)
#define  SCALEDOWN_UZD_Timing_monitor_golden_t_m_golden(data)                    (0x0FFFFFFF&(data))
#define  SCALEDOWN_UZD_Timing_monitor_golden_get_t_m_golden(data)                (0x0FFFFFFF&(data))

#define  SCALEDOWN_UZD_Timing_monitor_result1                                    0x18025260
#define  SCALEDOWN_UZD_Timing_monitor_result1_reg_addr                           "0xB8025260"
#define  SCALEDOWN_UZD_Timing_monitor_result1_reg                                0xB8025260
#define  SCALEDOWN_UZD_Timing_monitor_result1_inst_addr                          "0x0014"
#define  set_SCALEDOWN_UZD_Timing_monitor_result1_reg(data)                      (*((volatile unsigned int*)SCALEDOWN_UZD_Timing_monitor_result1_reg)=data)
#define  get_SCALEDOWN_UZD_Timing_monitor_result1_reg                            (*((volatile unsigned int*)SCALEDOWN_UZD_Timing_monitor_result1_reg))
#define  SCALEDOWN_UZD_Timing_monitor_result1_t_m_result_previous1_shift         (0)
#define  SCALEDOWN_UZD_Timing_monitor_result1_t_m_result_previous1_mask          (0x0FFFFFFF)
#define  SCALEDOWN_UZD_Timing_monitor_result1_t_m_result_previous1(data)         (0x0FFFFFFF&(data))
#define  SCALEDOWN_UZD_Timing_monitor_result1_get_t_m_result_previous1(data)     (0x0FFFFFFF&(data))

#define  SCALEDOWN_UZD_Timing_monitor_result2                                    0x18025264
#define  SCALEDOWN_UZD_Timing_monitor_result2_reg_addr                           "0xB8025264"
#define  SCALEDOWN_UZD_Timing_monitor_result2_reg                                0xB8025264
#define  SCALEDOWN_UZD_Timing_monitor_result2_inst_addr                          "0x0015"
#define  set_SCALEDOWN_UZD_Timing_monitor_result2_reg(data)                      (*((volatile unsigned int*)SCALEDOWN_UZD_Timing_monitor_result2_reg)=data)
#define  get_SCALEDOWN_UZD_Timing_monitor_result2_reg                            (*((volatile unsigned int*)SCALEDOWN_UZD_Timing_monitor_result2_reg))
#define  SCALEDOWN_UZD_Timing_monitor_result2_t_m_result_previous2_shift         (0)
#define  SCALEDOWN_UZD_Timing_monitor_result2_t_m_result_previous2_mask          (0x0FFFFFFF)
#define  SCALEDOWN_UZD_Timing_monitor_result2_t_m_result_previous2(data)         (0x0FFFFFFF&(data))
#define  SCALEDOWN_UZD_Timing_monitor_result2_get_t_m_result_previous2(data)     (0x0FFFFFFF&(data))

#define  SCALEDOWN_UZD_Timing_monitor_result3                                    0x18025268
#define  SCALEDOWN_UZD_Timing_monitor_result3_reg_addr                           "0xB8025268"
#define  SCALEDOWN_UZD_Timing_monitor_result3_reg                                0xB8025268
#define  SCALEDOWN_UZD_Timing_monitor_result3_inst_addr                          "0x0016"
#define  set_SCALEDOWN_UZD_Timing_monitor_result3_reg(data)                      (*((volatile unsigned int*)SCALEDOWN_UZD_Timing_monitor_result3_reg)=data)
#define  get_SCALEDOWN_UZD_Timing_monitor_result3_reg                            (*((volatile unsigned int*)SCALEDOWN_UZD_Timing_monitor_result3_reg))
#define  SCALEDOWN_UZD_Timing_monitor_result3_t_m_result_previous3_shift         (0)
#define  SCALEDOWN_UZD_Timing_monitor_result3_t_m_result_previous3_mask          (0x0FFFFFFF)
#define  SCALEDOWN_UZD_Timing_monitor_result3_t_m_result_previous3(data)         (0x0FFFFFFF&(data))
#define  SCALEDOWN_UZD_Timing_monitor_result3_get_t_m_result_previous3(data)     (0x0FFFFFFF&(data))

#define  SCALEDOWN_UZD_Timing_monitor_result4                                    0x1802526C
#define  SCALEDOWN_UZD_Timing_monitor_result4_reg_addr                           "0xB802526C"
#define  SCALEDOWN_UZD_Timing_monitor_result4_reg                                0xB802526C
#define  SCALEDOWN_UZD_Timing_monitor_result4_inst_addr                          "0x0017"
#define  set_SCALEDOWN_UZD_Timing_monitor_result4_reg(data)                      (*((volatile unsigned int*)SCALEDOWN_UZD_Timing_monitor_result4_reg)=data)
#define  get_SCALEDOWN_UZD_Timing_monitor_result4_reg                            (*((volatile unsigned int*)SCALEDOWN_UZD_Timing_monitor_result4_reg))
#define  SCALEDOWN_UZD_Timing_monitor_result4_t_m_result_previous4_shift         (0)
#define  SCALEDOWN_UZD_Timing_monitor_result4_t_m_result_previous4_mask          (0x0FFFFFFF)
#define  SCALEDOWN_UZD_Timing_monitor_result4_t_m_result_previous4(data)         (0x0FFFFFFF&(data))
#define  SCALEDOWN_UZD_Timing_monitor_result4_get_t_m_result_previous4(data)     (0x0FFFFFFF&(data))

#define  SCALEDOWN_UZD_Timing_monitor_max                                        0x18025270
#define  SCALEDOWN_UZD_Timing_monitor_max_reg_addr                               "0xB8025270"
#define  SCALEDOWN_UZD_Timing_monitor_max_reg                                    0xB8025270
#define  SCALEDOWN_UZD_Timing_monitor_max_inst_addr                              "0x0018"
#define  set_SCALEDOWN_UZD_Timing_monitor_max_reg(data)                          (*((volatile unsigned int*)SCALEDOWN_UZD_Timing_monitor_max_reg)=data)
#define  get_SCALEDOWN_UZD_Timing_monitor_max_reg                                (*((volatile unsigned int*)SCALEDOWN_UZD_Timing_monitor_max_reg))
#define  SCALEDOWN_UZD_Timing_monitor_max_t_m_result_max_shift                   (0)
#define  SCALEDOWN_UZD_Timing_monitor_max_t_m_result_max_mask                    (0x0FFFFFFF)
#define  SCALEDOWN_UZD_Timing_monitor_max_t_m_result_max(data)                   (0x0FFFFFFF&(data))
#define  SCALEDOWN_UZD_Timing_monitor_max_get_t_m_result_max(data)               (0x0FFFFFFF&(data))

#define  SCALEDOWN_UZD_Timing_monitor_min                                        0x18025274
#define  SCALEDOWN_UZD_Timing_monitor_min_reg_addr                               "0xB8025274"
#define  SCALEDOWN_UZD_Timing_monitor_min_reg                                    0xB8025274
#define  SCALEDOWN_UZD_Timing_monitor_min_inst_addr                              "0x0019"
#define  set_SCALEDOWN_UZD_Timing_monitor_min_reg(data)                          (*((volatile unsigned int*)SCALEDOWN_UZD_Timing_monitor_min_reg)=data)
#define  get_SCALEDOWN_UZD_Timing_monitor_min_reg                                (*((volatile unsigned int*)SCALEDOWN_UZD_Timing_monitor_min_reg))
#define  SCALEDOWN_UZD_Timing_monitor_min_t_m_result_min_shift                   (0)
#define  SCALEDOWN_UZD_Timing_monitor_min_t_m_result_min_mask                    (0x0FFFFFFF)
#define  SCALEDOWN_UZD_Timing_monitor_min_t_m_result_min(data)                   (0x0FFFFFFF&(data))
#define  SCALEDOWN_UZD_Timing_monitor_min_get_t_m_result_min(data)               (0x0FFFFFFF&(data))

#define  SCALEDOWN_UZD_Timing_monitor_st                                         0x18025278
#define  SCALEDOWN_UZD_Timing_monitor_st_reg_addr                                "0xB8025278"
#define  SCALEDOWN_UZD_Timing_monitor_st_reg                                     0xB8025278
#define  SCALEDOWN_UZD_Timing_monitor_st_inst_addr                               "0x001A"
#define  set_SCALEDOWN_UZD_Timing_monitor_st_reg(data)                           (*((volatile unsigned int*)SCALEDOWN_UZD_Timing_monitor_st_reg)=data)
#define  get_SCALEDOWN_UZD_Timing_monitor_st_reg                                 (*((volatile unsigned int*)SCALEDOWN_UZD_Timing_monitor_st_reg))
#define  SCALEDOWN_UZD_Timing_monitor_st_compare_hit_shift                       (2)
#define  SCALEDOWN_UZD_Timing_monitor_st_hsync_hit_den_error_shift               (1)
#define  SCALEDOWN_UZD_Timing_monitor_st_vsync_hit_den_error_shift               (0)
#define  SCALEDOWN_UZD_Timing_monitor_st_compare_hit_mask                        (0x00000004)
#define  SCALEDOWN_UZD_Timing_monitor_st_hsync_hit_den_error_mask                (0x00000002)
#define  SCALEDOWN_UZD_Timing_monitor_st_vsync_hit_den_error_mask                (0x00000001)
#define  SCALEDOWN_UZD_Timing_monitor_st_compare_hit(data)                       (0x00000004&((data)<<2))
#define  SCALEDOWN_UZD_Timing_monitor_st_hsync_hit_den_error(data)               (0x00000002&((data)<<1))
#define  SCALEDOWN_UZD_Timing_monitor_st_vsync_hit_den_error(data)               (0x00000001&(data))
#define  SCALEDOWN_UZD_Timing_monitor_st_get_compare_hit(data)                   ((0x00000004&(data))>>2)
#define  SCALEDOWN_UZD_Timing_monitor_st_get_hsync_hit_den_error(data)           ((0x00000002&(data))>>1)
#define  SCALEDOWN_UZD_Timing_monitor_st_get_vsync_hit_den_error(data)           (0x00000001&(data))

#define  SCALEDOWN_AccessData_CTRL_UZD                                           0x18025280
#define  SCALEDOWN_AccessData_CTRL_UZD_reg_addr                                  "0xB8025280"
#define  SCALEDOWN_AccessData_CTRL_UZD_reg                                       0xB8025280
#define  SCALEDOWN_AccessData_CTRL_UZD_inst_addr                                 "0x001B"
#define  set_SCALEDOWN_AccessData_CTRL_UZD_reg(data)                             (*((volatile unsigned int*)SCALEDOWN_AccessData_CTRL_UZD_reg)=data)
#define  get_SCALEDOWN_AccessData_CTRL_UZD_reg                                   (*((volatile unsigned int*)SCALEDOWN_AccessData_CTRL_UZD_reg))
#define  SCALEDOWN_AccessData_CTRL_UZD_write_en_shift                            (1)
#define  SCALEDOWN_AccessData_CTRL_UZD_read_en_shift                             (0)
#define  SCALEDOWN_AccessData_CTRL_UZD_write_en_mask                             (0x00000002)
#define  SCALEDOWN_AccessData_CTRL_UZD_read_en_mask                              (0x00000001)
#define  SCALEDOWN_AccessData_CTRL_UZD_write_en(data)                            (0x00000002&((data)<<1))
#define  SCALEDOWN_AccessData_CTRL_UZD_read_en(data)                             (0x00000001&(data))
#define  SCALEDOWN_AccessData_CTRL_UZD_get_write_en(data)                        ((0x00000002&(data))>>1)
#define  SCALEDOWN_AccessData_CTRL_UZD_get_read_en(data)                         (0x00000001&(data))

#define  SCALEDOWN_AccessData_PosCtrl_UZD                                        0x18025284
#define  SCALEDOWN_AccessData_PosCtrl_UZD_reg_addr                               "0xB8025284"
#define  SCALEDOWN_AccessData_PosCtrl_UZD_reg                                    0xB8025284
#define  SCALEDOWN_AccessData_PosCtrl_UZD_inst_addr                              "0x001C"
#define  set_SCALEDOWN_AccessData_PosCtrl_UZD_reg(data)                          (*((volatile unsigned int*)SCALEDOWN_AccessData_PosCtrl_UZD_reg)=data)
#define  get_SCALEDOWN_AccessData_PosCtrl_UZD_reg                                (*((volatile unsigned int*)SCALEDOWN_AccessData_PosCtrl_UZD_reg))
#define  SCALEDOWN_AccessData_PosCtrl_UZD_starty_shift                           (16)
#define  SCALEDOWN_AccessData_PosCtrl_UZD_startx_shift                           (0)
#define  SCALEDOWN_AccessData_PosCtrl_UZD_starty_mask                            (0x1FFF0000)
#define  SCALEDOWN_AccessData_PosCtrl_UZD_startx_mask                            (0x00001FFF)
#define  SCALEDOWN_AccessData_PosCtrl_UZD_starty(data)                           (0x1FFF0000&((data)<<16))
#define  SCALEDOWN_AccessData_PosCtrl_UZD_startx(data)                           (0x00001FFF&(data))
#define  SCALEDOWN_AccessData_PosCtrl_UZD_get_starty(data)                       ((0x1FFF0000&(data))>>16)
#define  SCALEDOWN_AccessData_PosCtrl_UZD_get_startx(data)                       (0x00001FFF&(data))

#define  SCALEDOWN_ReadData_DATA_Y1_UZD                                          0x18025288
#define  SCALEDOWN_ReadData_DATA_Y1_UZD_reg_addr                                 "0xB8025288"
#define  SCALEDOWN_ReadData_DATA_Y1_UZD_reg                                      0xB8025288
#define  SCALEDOWN_ReadData_DATA_Y1_UZD_inst_addr                                "0x001D"
#define  set_SCALEDOWN_ReadData_DATA_Y1_UZD_reg(data)                            (*((volatile unsigned int*)SCALEDOWN_ReadData_DATA_Y1_UZD_reg)=data)
#define  get_SCALEDOWN_ReadData_DATA_Y1_UZD_reg                                  (*((volatile unsigned int*)SCALEDOWN_ReadData_DATA_Y1_UZD_reg))
#define  SCALEDOWN_ReadData_DATA_Y1_UZD_y01_shift                                (16)
#define  SCALEDOWN_ReadData_DATA_Y1_UZD_y00_shift                                (0)
#define  SCALEDOWN_ReadData_DATA_Y1_UZD_y01_mask                                 (0x03FF0000)
#define  SCALEDOWN_ReadData_DATA_Y1_UZD_y00_mask                                 (0x000003FF)
#define  SCALEDOWN_ReadData_DATA_Y1_UZD_y01(data)                                (0x03FF0000&((data)<<16))
#define  SCALEDOWN_ReadData_DATA_Y1_UZD_y00(data)                                (0x000003FF&(data))
#define  SCALEDOWN_ReadData_DATA_Y1_UZD_get_y01(data)                            ((0x03FF0000&(data))>>16)
#define  SCALEDOWN_ReadData_DATA_Y1_UZD_get_y00(data)                            (0x000003FF&(data))

#define  SCALEDOWN_ReadData_DATA_Y2_UZD                                          0x1802528C
#define  SCALEDOWN_ReadData_DATA_Y2_UZD_reg_addr                                 "0xB802528C"
#define  SCALEDOWN_ReadData_DATA_Y2_UZD_reg                                      0xB802528C
#define  SCALEDOWN_ReadData_DATA_Y2_UZD_inst_addr                                "0x001E"
#define  set_SCALEDOWN_ReadData_DATA_Y2_UZD_reg(data)                            (*((volatile unsigned int*)SCALEDOWN_ReadData_DATA_Y2_UZD_reg)=data)
#define  get_SCALEDOWN_ReadData_DATA_Y2_UZD_reg                                  (*((volatile unsigned int*)SCALEDOWN_ReadData_DATA_Y2_UZD_reg))
#define  SCALEDOWN_ReadData_DATA_Y2_UZD_y11_shift                                (16)
#define  SCALEDOWN_ReadData_DATA_Y2_UZD_y10_shift                                (0)
#define  SCALEDOWN_ReadData_DATA_Y2_UZD_y11_mask                                 (0x03FF0000)
#define  SCALEDOWN_ReadData_DATA_Y2_UZD_y10_mask                                 (0x000003FF)
#define  SCALEDOWN_ReadData_DATA_Y2_UZD_y11(data)                                (0x03FF0000&((data)<<16))
#define  SCALEDOWN_ReadData_DATA_Y2_UZD_y10(data)                                (0x000003FF&(data))
#define  SCALEDOWN_ReadData_DATA_Y2_UZD_get_y11(data)                            ((0x03FF0000&(data))>>16)
#define  SCALEDOWN_ReadData_DATA_Y2_UZD_get_y10(data)                            (0x000003FF&(data))

#define  SCALEDOWN_ReadData_DATA_C1_UZD                                          0x18025290
#define  SCALEDOWN_ReadData_DATA_C1_UZD_reg_addr                                 "0xB8025290"
#define  SCALEDOWN_ReadData_DATA_C1_UZD_reg                                      0xB8025290
#define  SCALEDOWN_ReadData_DATA_C1_UZD_inst_addr                                "0x001F"
#define  set_SCALEDOWN_ReadData_DATA_C1_UZD_reg(data)                            (*((volatile unsigned int*)SCALEDOWN_ReadData_DATA_C1_UZD_reg)=data)
#define  get_SCALEDOWN_ReadData_DATA_C1_UZD_reg                                  (*((volatile unsigned int*)SCALEDOWN_ReadData_DATA_C1_UZD_reg))
#define  SCALEDOWN_ReadData_DATA_C1_UZD_v00_shift                                (16)
#define  SCALEDOWN_ReadData_DATA_C1_UZD_u00_shift                                (0)
#define  SCALEDOWN_ReadData_DATA_C1_UZD_v00_mask                                 (0x03FF0000)
#define  SCALEDOWN_ReadData_DATA_C1_UZD_u00_mask                                 (0x000003FF)
#define  SCALEDOWN_ReadData_DATA_C1_UZD_v00(data)                                (0x03FF0000&((data)<<16))
#define  SCALEDOWN_ReadData_DATA_C1_UZD_u00(data)                                (0x000003FF&(data))
#define  SCALEDOWN_ReadData_DATA_C1_UZD_get_v00(data)                            ((0x03FF0000&(data))>>16)
#define  SCALEDOWN_ReadData_DATA_C1_UZD_get_u00(data)                            (0x000003FF&(data))

#define  SCALEDOWN_ReadData_DATA_C2_UZD                                          0x18025294
#define  SCALEDOWN_ReadData_DATA_C2_UZD_reg_addr                                 "0xB8025294"
#define  SCALEDOWN_ReadData_DATA_C2_UZD_reg                                      0xB8025294
#define  SCALEDOWN_ReadData_DATA_C2_UZD_inst_addr                                "0x0020"
#define  set_SCALEDOWN_ReadData_DATA_C2_UZD_reg(data)                            (*((volatile unsigned int*)SCALEDOWN_ReadData_DATA_C2_UZD_reg)=data)
#define  get_SCALEDOWN_ReadData_DATA_C2_UZD_reg                                  (*((volatile unsigned int*)SCALEDOWN_ReadData_DATA_C2_UZD_reg))
#define  SCALEDOWN_ReadData_DATA_C2_UZD_v01_shift                                (16)
#define  SCALEDOWN_ReadData_DATA_C2_UZD_u01_shift                                (0)
#define  SCALEDOWN_ReadData_DATA_C2_UZD_v01_mask                                 (0x03FF0000)
#define  SCALEDOWN_ReadData_DATA_C2_UZD_u01_mask                                 (0x000003FF)
#define  SCALEDOWN_ReadData_DATA_C2_UZD_v01(data)                                (0x03FF0000&((data)<<16))
#define  SCALEDOWN_ReadData_DATA_C2_UZD_u01(data)                                (0x000003FF&(data))
#define  SCALEDOWN_ReadData_DATA_C2_UZD_get_v01(data)                            ((0x03FF0000&(data))>>16)
#define  SCALEDOWN_ReadData_DATA_C2_UZD_get_u01(data)                            (0x000003FF&(data))

#define  SCALEDOWN_ReadData_DATA_C3_UZD                                          0x18025298
#define  SCALEDOWN_ReadData_DATA_C3_UZD_reg_addr                                 "0xB8025298"
#define  SCALEDOWN_ReadData_DATA_C3_UZD_reg                                      0xB8025298
#define  SCALEDOWN_ReadData_DATA_C3_UZD_inst_addr                                "0x0021"
#define  set_SCALEDOWN_ReadData_DATA_C3_UZD_reg(data)                            (*((volatile unsigned int*)SCALEDOWN_ReadData_DATA_C3_UZD_reg)=data)
#define  get_SCALEDOWN_ReadData_DATA_C3_UZD_reg                                  (*((volatile unsigned int*)SCALEDOWN_ReadData_DATA_C3_UZD_reg))
#define  SCALEDOWN_ReadData_DATA_C3_UZD_v10_shift                                (16)
#define  SCALEDOWN_ReadData_DATA_C3_UZD_u10_shift                                (0)
#define  SCALEDOWN_ReadData_DATA_C3_UZD_v10_mask                                 (0x03FF0000)
#define  SCALEDOWN_ReadData_DATA_C3_UZD_u10_mask                                 (0x000003FF)
#define  SCALEDOWN_ReadData_DATA_C3_UZD_v10(data)                                (0x03FF0000&((data)<<16))
#define  SCALEDOWN_ReadData_DATA_C3_UZD_u10(data)                                (0x000003FF&(data))
#define  SCALEDOWN_ReadData_DATA_C3_UZD_get_v10(data)                            ((0x03FF0000&(data))>>16)
#define  SCALEDOWN_ReadData_DATA_C3_UZD_get_u10(data)                            (0x000003FF&(data))

#define  SCALEDOWN_ReadData_DATA_C4_UZD                                          0x1802529C
#define  SCALEDOWN_ReadData_DATA_C4_UZD_reg_addr                                 "0xB802529C"
#define  SCALEDOWN_ReadData_DATA_C4_UZD_reg                                      0xB802529C
#define  SCALEDOWN_ReadData_DATA_C4_UZD_inst_addr                                "0x0022"
#define  set_SCALEDOWN_ReadData_DATA_C4_UZD_reg(data)                            (*((volatile unsigned int*)SCALEDOWN_ReadData_DATA_C4_UZD_reg)=data)
#define  get_SCALEDOWN_ReadData_DATA_C4_UZD_reg                                  (*((volatile unsigned int*)SCALEDOWN_ReadData_DATA_C4_UZD_reg))
#define  SCALEDOWN_ReadData_DATA_C4_UZD_v11_shift                                (16)
#define  SCALEDOWN_ReadData_DATA_C4_UZD_u11_shift                                (0)
#define  SCALEDOWN_ReadData_DATA_C4_UZD_v11_mask                                 (0x03FF0000)
#define  SCALEDOWN_ReadData_DATA_C4_UZD_u11_mask                                 (0x000003FF)
#define  SCALEDOWN_ReadData_DATA_C4_UZD_v11(data)                                (0x03FF0000&((data)<<16))
#define  SCALEDOWN_ReadData_DATA_C4_UZD_u11(data)                                (0x000003FF&(data))
#define  SCALEDOWN_ReadData_DATA_C4_UZD_get_v11(data)                            ((0x03FF0000&(data))>>16)
#define  SCALEDOWN_ReadData_DATA_C4_UZD_get_u11(data)                            (0x000003FF&(data))

#define  SCALEDOWN_WriteData_DATA_UZD                                            0x180252A0
#define  SCALEDOWN_WriteData_DATA_UZD_reg_addr                                   "0xB80252A0"
#define  SCALEDOWN_WriteData_DATA_UZD_reg                                        0xB80252A0
#define  SCALEDOWN_WriteData_DATA_UZD_inst_addr                                  "0x0023"
#define  set_SCALEDOWN_WriteData_DATA_UZD_reg(data)                              (*((volatile unsigned int*)SCALEDOWN_WriteData_DATA_UZD_reg)=data)
#define  get_SCALEDOWN_WriteData_DATA_UZD_reg                                    (*((volatile unsigned int*)SCALEDOWN_WriteData_DATA_UZD_reg))
#define  SCALEDOWN_WriteData_DATA_UZD_v_shift                                    (8)
#define  SCALEDOWN_WriteData_DATA_UZD_u_shift                                    (4)
#define  SCALEDOWN_WriteData_DATA_UZD_y_shift                                    (0)
#define  SCALEDOWN_WriteData_DATA_UZD_v_mask                                     (0x00000F00)
#define  SCALEDOWN_WriteData_DATA_UZD_u_mask                                     (0x000000F0)
#define  SCALEDOWN_WriteData_DATA_UZD_y_mask                                     (0x0000000F)
#define  SCALEDOWN_WriteData_DATA_UZD_v(data)                                    (0x00000F00&((data)<<8))
#define  SCALEDOWN_WriteData_DATA_UZD_u(data)                                    (0x000000F0&((data)<<4))
#define  SCALEDOWN_WriteData_DATA_UZD_y(data)                                    (0x0000000F&(data))
#define  SCALEDOWN_WriteData_DATA_UZD_get_v(data)                                ((0x00000F00&(data))>>8)
#define  SCALEDOWN_WriteData_DATA_UZD_get_u(data)                                ((0x000000F0&(data))>>4)
#define  SCALEDOWN_WriteData_DATA_UZD_get_y(data)                                (0x0000000F&(data))

#define  SCALEDOWN_ich1_sdnr_bisr_linebuf_fail                                   0x180252B8
#define  SCALEDOWN_ich1_sdnr_bisr_linebuf_fail_reg_addr                          "0xB80252B8"
#define  SCALEDOWN_ich1_sdnr_bisr_linebuf_fail_reg                               0xB80252B8
#define  SCALEDOWN_ich1_sdnr_bisr_linebuf_fail_inst_addr                         "0x0024"
#define  set_SCALEDOWN_ich1_sdnr_bisr_linebuf_fail_reg(data)                     (*((volatile unsigned int*)SCALEDOWN_ich1_sdnr_bisr_linebuf_fail_reg)=data)
#define  get_SCALEDOWN_ich1_sdnr_bisr_linebuf_fail_reg                           (*((volatile unsigned int*)SCALEDOWN_ich1_sdnr_bisr_linebuf_fail_reg))
#define  SCALEDOWN_ich1_sdnr_bisr_linebuf_fail_bisr_linebuf_fail_2_shift         (2)
#define  SCALEDOWN_ich1_sdnr_bisr_linebuf_fail_bisr_linebuf_fail_1_shift         (1)
#define  SCALEDOWN_ich1_sdnr_bisr_linebuf_fail_bisr_linebuf_fail_0_shift         (0)
#define  SCALEDOWN_ich1_sdnr_bisr_linebuf_fail_bisr_linebuf_fail_2_mask          (0x00000004)
#define  SCALEDOWN_ich1_sdnr_bisr_linebuf_fail_bisr_linebuf_fail_1_mask          (0x00000002)
#define  SCALEDOWN_ich1_sdnr_bisr_linebuf_fail_bisr_linebuf_fail_0_mask          (0x00000001)
#define  SCALEDOWN_ich1_sdnr_bisr_linebuf_fail_bisr_linebuf_fail_2(data)         (0x00000004&((data)<<2))
#define  SCALEDOWN_ich1_sdnr_bisr_linebuf_fail_bisr_linebuf_fail_1(data)         (0x00000002&((data)<<1))
#define  SCALEDOWN_ich1_sdnr_bisr_linebuf_fail_bisr_linebuf_fail_0(data)         (0x00000001&(data))
#define  SCALEDOWN_ich1_sdnr_bisr_linebuf_fail_get_bisr_linebuf_fail_2(data)     ((0x00000004&(data))>>2)
#define  SCALEDOWN_ich1_sdnr_bisr_linebuf_fail_get_bisr_linebuf_fail_1(data)     ((0x00000002&(data))>>1)
#define  SCALEDOWN_ich1_sdnr_bisr_linebuf_fail_get_bisr_linebuf_fail_0(data)     (0x00000001&(data))

#define  SCALEDOWN_ich1_sdnr_drf_linebuf_fail                                    0x180252BC
#define  SCALEDOWN_ich1_sdnr_drf_linebuf_fail_reg_addr                           "0xB80252BC"
#define  SCALEDOWN_ich1_sdnr_drf_linebuf_fail_reg                                0xB80252BC
#define  SCALEDOWN_ich1_sdnr_drf_linebuf_fail_inst_addr                          "0x0025"
#define  set_SCALEDOWN_ich1_sdnr_drf_linebuf_fail_reg(data)                      (*((volatile unsigned int*)SCALEDOWN_ich1_sdnr_drf_linebuf_fail_reg)=data)
#define  get_SCALEDOWN_ich1_sdnr_drf_linebuf_fail_reg                            (*((volatile unsigned int*)SCALEDOWN_ich1_sdnr_drf_linebuf_fail_reg))
#define  SCALEDOWN_ich1_sdnr_drf_linebuf_fail_sdnr_drf_linebuf_fail_2_shift      (2)
#define  SCALEDOWN_ich1_sdnr_drf_linebuf_fail_sdnr_drf_linebuf_fail_1_shift      (1)
#define  SCALEDOWN_ich1_sdnr_drf_linebuf_fail_sdnr_drf_linebuf_fail_0_shift      (0)
#define  SCALEDOWN_ich1_sdnr_drf_linebuf_fail_sdnr_drf_linebuf_fail_2_mask       (0x00000004)
#define  SCALEDOWN_ich1_sdnr_drf_linebuf_fail_sdnr_drf_linebuf_fail_1_mask       (0x00000002)
#define  SCALEDOWN_ich1_sdnr_drf_linebuf_fail_sdnr_drf_linebuf_fail_0_mask       (0x00000001)
#define  SCALEDOWN_ich1_sdnr_drf_linebuf_fail_sdnr_drf_linebuf_fail_2(data)      (0x00000004&((data)<<2))
#define  SCALEDOWN_ich1_sdnr_drf_linebuf_fail_sdnr_drf_linebuf_fail_1(data)      (0x00000002&((data)<<1))
#define  SCALEDOWN_ich1_sdnr_drf_linebuf_fail_sdnr_drf_linebuf_fail_0(data)      (0x00000001&(data))
#define  SCALEDOWN_ich1_sdnr_drf_linebuf_fail_get_sdnr_drf_linebuf_fail_2(data)  ((0x00000004&(data))>>2)
#define  SCALEDOWN_ich1_sdnr_drf_linebuf_fail_get_sdnr_drf_linebuf_fail_1(data)  ((0x00000002&(data))>>1)
#define  SCALEDOWN_ich1_sdnr_drf_linebuf_fail_get_sdnr_drf_linebuf_fail_0(data)  (0x00000001&(data))

#define  SCALEDOWN_ich1_sdnr_linebuf_dvs                                         0x180252C0
#define  SCALEDOWN_ich1_sdnr_linebuf_dvs_reg_addr                                "0xB80252C0"
#define  SCALEDOWN_ich1_sdnr_linebuf_dvs_reg                                     0xB80252C0
#define  SCALEDOWN_ich1_sdnr_linebuf_dvs_inst_addr                               "0x0026"
#define  set_SCALEDOWN_ich1_sdnr_linebuf_dvs_reg(data)                           (*((volatile unsigned int*)SCALEDOWN_ich1_sdnr_linebuf_dvs_reg)=data)
#define  get_SCALEDOWN_ich1_sdnr_linebuf_dvs_reg                                 (*((volatile unsigned int*)SCALEDOWN_ich1_sdnr_linebuf_dvs_reg))
#define  SCALEDOWN_ich1_sdnr_linebuf_dvs_sdnr_linebuf_1_2_ls_en_shift            (29)
#define  SCALEDOWN_ich1_sdnr_linebuf_dvs_sdnr_linebuf_1_2_dvse_shift             (28)
#define  SCALEDOWN_ich1_sdnr_linebuf_dvs_sdnr_linebuf_1_2_dvs_shift              (24)
#define  SCALEDOWN_ich1_sdnr_linebuf_dvs_sdnr_linebuf_1_1_ls_en_shift            (21)
#define  SCALEDOWN_ich1_sdnr_linebuf_dvs_sdnr_linebuf_1_1_dvse_shift             (20)
#define  SCALEDOWN_ich1_sdnr_linebuf_dvs_sdnr_linebuf_1_1_dvs_shift              (16)
#define  SCALEDOWN_ich1_sdnr_linebuf_dvs_sdnr_linebuf_1_0_ls_en_shift            (13)
#define  SCALEDOWN_ich1_sdnr_linebuf_dvs_sdnr_linebuf_1_0_dvse_shift             (12)
#define  SCALEDOWN_ich1_sdnr_linebuf_dvs_sdnr_linebuf_1_0_dvs_shift              (8)
#define  SCALEDOWN_ich1_sdnr_linebuf_dvs_sdnr_linebuf_1_2_ls_en_mask             (0x20000000)
#define  SCALEDOWN_ich1_sdnr_linebuf_dvs_sdnr_linebuf_1_2_dvse_mask              (0x10000000)
#define  SCALEDOWN_ich1_sdnr_linebuf_dvs_sdnr_linebuf_1_2_dvs_mask               (0x0F000000)
#define  SCALEDOWN_ich1_sdnr_linebuf_dvs_sdnr_linebuf_1_1_ls_en_mask             (0x00200000)
#define  SCALEDOWN_ich1_sdnr_linebuf_dvs_sdnr_linebuf_1_1_dvse_mask              (0x00100000)
#define  SCALEDOWN_ich1_sdnr_linebuf_dvs_sdnr_linebuf_1_1_dvs_mask               (0x000F0000)
#define  SCALEDOWN_ich1_sdnr_linebuf_dvs_sdnr_linebuf_1_0_ls_en_mask             (0x00002000)
#define  SCALEDOWN_ich1_sdnr_linebuf_dvs_sdnr_linebuf_1_0_dvse_mask              (0x00001000)
#define  SCALEDOWN_ich1_sdnr_linebuf_dvs_sdnr_linebuf_1_0_dvs_mask               (0x00000F00)
#define  SCALEDOWN_ich1_sdnr_linebuf_dvs_sdnr_linebuf_1_2_ls_en(data)            (0x20000000&((data)<<29))
#define  SCALEDOWN_ich1_sdnr_linebuf_dvs_sdnr_linebuf_1_2_dvse(data)             (0x10000000&((data)<<28))
#define  SCALEDOWN_ich1_sdnr_linebuf_dvs_sdnr_linebuf_1_2_dvs(data)              (0x0F000000&((data)<<24))
#define  SCALEDOWN_ich1_sdnr_linebuf_dvs_sdnr_linebuf_1_1_ls_en(data)            (0x00200000&((data)<<21))
#define  SCALEDOWN_ich1_sdnr_linebuf_dvs_sdnr_linebuf_1_1_dvse(data)             (0x00100000&((data)<<20))
#define  SCALEDOWN_ich1_sdnr_linebuf_dvs_sdnr_linebuf_1_1_dvs(data)              (0x000F0000&((data)<<16))
#define  SCALEDOWN_ich1_sdnr_linebuf_dvs_sdnr_linebuf_1_0_ls_en(data)            (0x00002000&((data)<<13))
#define  SCALEDOWN_ich1_sdnr_linebuf_dvs_sdnr_linebuf_1_0_dvse(data)             (0x00001000&((data)<<12))
#define  SCALEDOWN_ich1_sdnr_linebuf_dvs_sdnr_linebuf_1_0_dvs(data)              (0x00000F00&((data)<<8))
#define  SCALEDOWN_ich1_sdnr_linebuf_dvs_get_sdnr_linebuf_1_2_ls_en(data)        ((0x20000000&(data))>>29)
#define  SCALEDOWN_ich1_sdnr_linebuf_dvs_get_sdnr_linebuf_1_2_dvse(data)         ((0x10000000&(data))>>28)
#define  SCALEDOWN_ich1_sdnr_linebuf_dvs_get_sdnr_linebuf_1_2_dvs(data)          ((0x0F000000&(data))>>24)
#define  SCALEDOWN_ich1_sdnr_linebuf_dvs_get_sdnr_linebuf_1_1_ls_en(data)        ((0x00200000&(data))>>21)
#define  SCALEDOWN_ich1_sdnr_linebuf_dvs_get_sdnr_linebuf_1_1_dvse(data)         ((0x00100000&(data))>>20)
#define  SCALEDOWN_ich1_sdnr_linebuf_dvs_get_sdnr_linebuf_1_1_dvs(data)          ((0x000F0000&(data))>>16)
#define  SCALEDOWN_ich1_sdnr_linebuf_dvs_get_sdnr_linebuf_1_0_ls_en(data)        ((0x00002000&(data))>>13)
#define  SCALEDOWN_ich1_sdnr_linebuf_dvs_get_sdnr_linebuf_1_0_dvse(data)         ((0x00001000&(data))>>12)
#define  SCALEDOWN_ich1_sdnr_linebuf_dvs_get_sdnr_linebuf_1_0_dvs(data)          ((0x00000F00&(data))>>8)

#define  SCALEDOWN_ich1_sdnr_cutout_range_hor                                    0x180252D0
#define  SCALEDOWN_ich1_sdnr_cutout_range_hor_reg_addr                           "0xB80252D0"
#define  SCALEDOWN_ich1_sdnr_cutout_range_hor_reg                                0xB80252D0
#define  SCALEDOWN_ich1_sdnr_cutout_range_hor_inst_addr                          "0x0027"
#define  set_SCALEDOWN_ich1_sdnr_cutout_range_hor_reg(data)                      (*((volatile unsigned int*)SCALEDOWN_ich1_sdnr_cutout_range_hor_reg)=data)
#define  get_SCALEDOWN_ich1_sdnr_cutout_range_hor_reg                            (*((volatile unsigned int*)SCALEDOWN_ich1_sdnr_cutout_range_hor_reg))
#define  SCALEDOWN_ich1_sdnr_cutout_range_hor_hor_front_shift                    (16)
#define  SCALEDOWN_ich1_sdnr_cutout_range_hor_hor_back_shift                     (0)
#define  SCALEDOWN_ich1_sdnr_cutout_range_hor_hor_front_mask                     (0x0FFF0000)
#define  SCALEDOWN_ich1_sdnr_cutout_range_hor_hor_back_mask                      (0x00000FFF)
#define  SCALEDOWN_ich1_sdnr_cutout_range_hor_hor_front(data)                    (0x0FFF0000&((data)<<16))
#define  SCALEDOWN_ich1_sdnr_cutout_range_hor_hor_back(data)                     (0x00000FFF&(data))
#define  SCALEDOWN_ich1_sdnr_cutout_range_hor_get_hor_front(data)                ((0x0FFF0000&(data))>>16)
#define  SCALEDOWN_ich1_sdnr_cutout_range_hor_get_hor_back(data)                 (0x00000FFF&(data))

#define  SCALEDOWN_ich1_sdnr_cutout_range_ver0                                   0x180252D4
#define  SCALEDOWN_ich1_sdnr_cutout_range_ver0_reg_addr                          "0xB80252D4"
#define  SCALEDOWN_ich1_sdnr_cutout_range_ver0_reg                               0xB80252D4
#define  SCALEDOWN_ich1_sdnr_cutout_range_ver0_inst_addr                         "0x0028"
#define  set_SCALEDOWN_ich1_sdnr_cutout_range_ver0_reg(data)                     (*((volatile unsigned int*)SCALEDOWN_ich1_sdnr_cutout_range_ver0_reg)=data)
#define  get_SCALEDOWN_ich1_sdnr_cutout_range_ver0_reg                           (*((volatile unsigned int*)SCALEDOWN_ich1_sdnr_cutout_range_ver0_reg))
#define  SCALEDOWN_ich1_sdnr_cutout_range_ver0_ver_front_shift                   (16)
#define  SCALEDOWN_ich1_sdnr_cutout_range_ver0_ver_back_shift                    (0)
#define  SCALEDOWN_ich1_sdnr_cutout_range_ver0_ver_front_mask                    (0x0FFF0000)
#define  SCALEDOWN_ich1_sdnr_cutout_range_ver0_ver_back_mask                     (0x00000FFF)
#define  SCALEDOWN_ich1_sdnr_cutout_range_ver0_ver_front(data)                   (0x0FFF0000&((data)<<16))
#define  SCALEDOWN_ich1_sdnr_cutout_range_ver0_ver_back(data)                    (0x00000FFF&(data))
#define  SCALEDOWN_ich1_sdnr_cutout_range_ver0_get_ver_front(data)               ((0x0FFF0000&(data))>>16)
#define  SCALEDOWN_ich1_sdnr_cutout_range_ver0_get_ver_back(data)                (0x00000FFF&(data))

#define  SCALEDOWN_ich1_sdnr_cutout_range_ver1                                   0x180252D8
#define  SCALEDOWN_ich1_sdnr_cutout_range_ver1_reg_addr                          "0xB80252D8"
#define  SCALEDOWN_ich1_sdnr_cutout_range_ver1_reg                               0xB80252D8
#define  SCALEDOWN_ich1_sdnr_cutout_range_ver1_inst_addr                         "0x0029"
#define  set_SCALEDOWN_ich1_sdnr_cutout_range_ver1_reg(data)                     (*((volatile unsigned int*)SCALEDOWN_ich1_sdnr_cutout_range_ver1_reg)=data)
#define  get_SCALEDOWN_ich1_sdnr_cutout_range_ver1_reg                           (*((volatile unsigned int*)SCALEDOWN_ich1_sdnr_cutout_range_ver1_reg))
#define  SCALEDOWN_ich1_sdnr_cutout_range_ver1_ver_mid_top_shift                 (16)
#define  SCALEDOWN_ich1_sdnr_cutout_range_ver1_ver_mid_bot_shift                 (0)
#define  SCALEDOWN_ich1_sdnr_cutout_range_ver1_ver_mid_top_mask                  (0x0FFF0000)
#define  SCALEDOWN_ich1_sdnr_cutout_range_ver1_ver_mid_bot_mask                  (0x00000FFF)
#define  SCALEDOWN_ich1_sdnr_cutout_range_ver1_ver_mid_top(data)                 (0x0FFF0000&((data)<<16))
#define  SCALEDOWN_ich1_sdnr_cutout_range_ver1_ver_mid_bot(data)                 (0x00000FFF&(data))
#define  SCALEDOWN_ich1_sdnr_cutout_range_ver1_get_ver_mid_top(data)             ((0x0FFF0000&(data))>>16)
#define  SCALEDOWN_ich1_sdnr_cutout_range_ver1_get_ver_mid_bot(data)             (0x00000FFF&(data))

#define  SCALEDOWN_ICH1_sdnr_444to422_CTRL                                       0x180252F0
#define  SCALEDOWN_ICH1_sdnr_444to422_CTRL_reg_addr                              "0xB80252F0"
#define  SCALEDOWN_ICH1_sdnr_444to422_CTRL_reg                                   0xB80252F0
#define  SCALEDOWN_ICH1_sdnr_444to422_CTRL_inst_addr                             "0x002A"
#define  set_SCALEDOWN_ICH1_sdnr_444to422_CTRL_reg(data)                         (*((volatile unsigned int*)SCALEDOWN_ICH1_sdnr_444to422_CTRL_reg)=data)
#define  get_SCALEDOWN_ICH1_sdnr_444to422_CTRL_reg                               (*((volatile unsigned int*)SCALEDOWN_ICH1_sdnr_444to422_CTRL_reg))
#define  SCALEDOWN_ICH1_sdnr_444to422_CTRL_cr_dly_cb_shift                       (2)
#define  SCALEDOWN_ICH1_sdnr_444to422_CTRL_drop_shift                            (1)
#define  SCALEDOWN_ICH1_sdnr_444to422_CTRL_dummy_0_shift                         (0)
#define  SCALEDOWN_ICH1_sdnr_444to422_CTRL_cr_dly_cb_mask                        (0x00000004)
#define  SCALEDOWN_ICH1_sdnr_444to422_CTRL_drop_mask                             (0x00000002)
#define  SCALEDOWN_ICH1_sdnr_444to422_CTRL_dummy_0_mask                          (0x00000001)
#define  SCALEDOWN_ICH1_sdnr_444to422_CTRL_cr_dly_cb(data)                       (0x00000004&((data)<<2))
#define  SCALEDOWN_ICH1_sdnr_444to422_CTRL_drop(data)                            (0x00000002&((data)<<1))
#define  SCALEDOWN_ICH1_sdnr_444to422_CTRL_dummy_0(data)                         (0x00000001&(data))
#define  SCALEDOWN_ICH1_sdnr_444to422_CTRL_get_cr_dly_cb(data)                   ((0x00000004&(data))>>2)
#define  SCALEDOWN_ICH1_sdnr_444to422_CTRL_get_drop(data)                        ((0x00000002&(data))>>1)
#define  SCALEDOWN_ICH1_sdnr_444to422_CTRL_get_dummy_0(data)                     (0x00000001&(data))

#define  SCALEDOWN_ICH1_hsd_3d_boundary                                          0x180252F4
#define  SCALEDOWN_ICH1_hsd_3d_boundary_reg_addr                                 "0xB80252F4"
#define  SCALEDOWN_ICH1_hsd_3d_boundary_reg                                      0xB80252F4
#define  SCALEDOWN_ICH1_hsd_3d_boundary_inst_addr                                "0x002B"
#define  set_SCALEDOWN_ICH1_hsd_3d_boundary_reg(data)                            (*((volatile unsigned int*)SCALEDOWN_ICH1_hsd_3d_boundary_reg)=data)
#define  get_SCALEDOWN_ICH1_hsd_3d_boundary_reg                                  (*((volatile unsigned int*)SCALEDOWN_ICH1_hsd_3d_boundary_reg))
#define  SCALEDOWN_ICH1_hsd_3d_boundary_hsd_3d_boundary_shift                    (0)
#define  SCALEDOWN_ICH1_hsd_3d_boundary_hsd_3d_boundary_mask                     (0x00001FFF)
#define  SCALEDOWN_ICH1_hsd_3d_boundary_hsd_3d_boundary(data)                    (0x00001FFF&(data))
#define  SCALEDOWN_ICH1_hsd_3d_boundary_get_hsd_3d_boundary(data)                (0x00001FFF&(data))

#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C0                                     0x18025300
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C0_reg_addr                            "0xB8025300"
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C0_reg                                 0xB8025300
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C0_inst_addr                           "0x002C"
#define  set_SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C0_reg(data)                       (*((volatile unsigned int*)SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C0_reg)=data)
#define  get_SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C0_reg                             (*((volatile unsigned int*)SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C0_reg))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C0_tab1_c0_shift                       (16)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C0_tab1_c1_shift                       (0)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C0_tab1_c0_mask                        (0x0FFF0000)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C0_tab1_c1_mask                        (0x00000FFF)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C0_tab1_c0(data)                       (0x0FFF0000&((data)<<16))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C0_tab1_c1(data)                       (0x00000FFF&(data))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C0_get_tab1_c0(data)                   ((0x0FFF0000&(data))>>16)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C0_get_tab1_c1(data)                   (0x00000FFF&(data))

#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C2                                     0x18025304
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C2_reg_addr                            "0xB8025304"
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C2_reg                                 0xB8025304
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C2_inst_addr                           "0x002D"
#define  set_SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C2_reg(data)                       (*((volatile unsigned int*)SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C2_reg)=data)
#define  get_SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C2_reg                             (*((volatile unsigned int*)SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C2_reg))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C2_tab1_c2_shift                       (16)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C2_tab1_c3_shift                       (0)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C2_tab1_c2_mask                        (0x0FFF0000)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C2_tab1_c3_mask                        (0x00000FFF)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C2_tab1_c2(data)                       (0x0FFF0000&((data)<<16))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C2_tab1_c3(data)                       (0x00000FFF&(data))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C2_get_tab1_c2(data)                   ((0x0FFF0000&(data))>>16)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C2_get_tab1_c3(data)                   (0x00000FFF&(data))

#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C4                                     0x18025308
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C4_reg_addr                            "0xB8025308"
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C4_reg                                 0xB8025308
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C4_inst_addr                           "0x002E"
#define  set_SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C4_reg(data)                       (*((volatile unsigned int*)SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C4_reg)=data)
#define  get_SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C4_reg                             (*((volatile unsigned int*)SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C4_reg))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C4_tab1_c4_shift                       (16)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C4_tab1_c5_shift                       (0)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C4_tab1_c4_mask                        (0x0FFF0000)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C4_tab1_c5_mask                        (0x00000FFF)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C4_tab1_c4(data)                       (0x0FFF0000&((data)<<16))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C4_tab1_c5(data)                       (0x00000FFF&(data))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C4_get_tab1_c4(data)                   ((0x0FFF0000&(data))>>16)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C4_get_tab1_c5(data)                   (0x00000FFF&(data))

#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C6                                     0x1802530C
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C6_reg_addr                            "0xB802530C"
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C6_reg                                 0xB802530C
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C6_inst_addr                           "0x002F"
#define  set_SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C6_reg(data)                       (*((volatile unsigned int*)SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C6_reg)=data)
#define  get_SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C6_reg                             (*((volatile unsigned int*)SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C6_reg))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C6_tab1_c6_shift                       (16)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C6_tab1_c7_shift                       (0)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C6_tab1_c6_mask                        (0x0FFF0000)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C6_tab1_c7_mask                        (0x00000FFF)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C6_tab1_c6(data)                       (0x0FFF0000&((data)<<16))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C6_tab1_c7(data)                       (0x00000FFF&(data))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C6_get_tab1_c6(data)                   ((0x0FFF0000&(data))>>16)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C6_get_tab1_c7(data)                   (0x00000FFF&(data))

#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C8                                     0x18025310
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C8_reg_addr                            "0xB8025310"
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C8_reg                                 0xB8025310
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C8_inst_addr                           "0x0030"
#define  set_SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C8_reg(data)                       (*((volatile unsigned int*)SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C8_reg)=data)
#define  get_SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C8_reg                             (*((volatile unsigned int*)SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C8_reg))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C8_tab1_c8_shift                       (16)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C8_tab1_c9_shift                       (0)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C8_tab1_c8_mask                        (0x0FFF0000)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C8_tab1_c9_mask                        (0x00000FFF)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C8_tab1_c8(data)                       (0x0FFF0000&((data)<<16))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C8_tab1_c9(data)                       (0x00000FFF&(data))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C8_get_tab1_c8(data)                   ((0x0FFF0000&(data))>>16)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C8_get_tab1_c9(data)                   (0x00000FFF&(data))

#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C10                                    0x18025314
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C10_reg_addr                           "0xB8025314"
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C10_reg                                0xB8025314
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C10_inst_addr                          "0x0031"
#define  set_SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C10_reg(data)                      (*((volatile unsigned int*)SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C10_reg)=data)
#define  get_SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C10_reg                            (*((volatile unsigned int*)SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C10_reg))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C10_tab1_c10_shift                     (16)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C10_tab1_c11_shift                     (0)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C10_tab1_c10_mask                      (0x0FFF0000)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C10_tab1_c11_mask                      (0x00000FFF)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C10_tab1_c10(data)                     (0x0FFF0000&((data)<<16))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C10_tab1_c11(data)                     (0x00000FFF&(data))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C10_get_tab1_c10(data)                 ((0x0FFF0000&(data))>>16)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C10_get_tab1_c11(data)                 (0x00000FFF&(data))

#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C12                                    0x18025318
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C12_reg_addr                           "0xB8025318"
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C12_reg                                0xB8025318
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C12_inst_addr                          "0x0032"
#define  set_SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C12_reg(data)                      (*((volatile unsigned int*)SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C12_reg)=data)
#define  get_SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C12_reg                            (*((volatile unsigned int*)SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C12_reg))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C12_tab1_c12_shift                     (16)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C12_tab1_c13_shift                     (0)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C12_tab1_c12_mask                      (0x0FFF0000)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C12_tab1_c13_mask                      (0x00000FFF)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C12_tab1_c12(data)                     (0x0FFF0000&((data)<<16))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C12_tab1_c13(data)                     (0x00000FFF&(data))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C12_get_tab1_c12(data)                 ((0x0FFF0000&(data))>>16)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C12_get_tab1_c13(data)                 (0x00000FFF&(data))

#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C14                                    0x1802531C
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C14_reg_addr                           "0xB802531C"
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C14_reg                                0xB802531C
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C14_inst_addr                          "0x0033"
#define  set_SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C14_reg(data)                      (*((volatile unsigned int*)SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C14_reg)=data)
#define  get_SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C14_reg                            (*((volatile unsigned int*)SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C14_reg))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C14_tab1_c14_shift                     (16)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C14_tab1_c15_shift                     (0)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C14_tab1_c14_mask                      (0x0FFF0000)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C14_tab1_c15_mask                      (0x00000FFF)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C14_tab1_c14(data)                     (0x0FFF0000&((data)<<16))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C14_tab1_c15(data)                     (0x00000FFF&(data))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C14_get_tab1_c14(data)                 ((0x0FFF0000&(data))>>16)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C14_get_tab1_c15(data)                 (0x00000FFF&(data))

#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C16                                    0x18025320
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C16_reg_addr                           "0xB8025320"
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C16_reg                                0xB8025320
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C16_inst_addr                          "0x0034"
#define  set_SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C16_reg(data)                      (*((volatile unsigned int*)SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C16_reg)=data)
#define  get_SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C16_reg                            (*((volatile unsigned int*)SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C16_reg))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C16_tab1_c16_shift                     (16)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C16_tab1_c17_shift                     (0)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C16_tab1_c16_mask                      (0x0FFF0000)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C16_tab1_c17_mask                      (0x00000FFF)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C16_tab1_c16(data)                     (0x0FFF0000&((data)<<16))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C16_tab1_c17(data)                     (0x00000FFF&(data))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C16_get_tab1_c16(data)                 ((0x0FFF0000&(data))>>16)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C16_get_tab1_c17(data)                 (0x00000FFF&(data))

#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C18                                    0x18025324
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C18_reg_addr                           "0xB8025324"
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C18_reg                                0xB8025324
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C18_inst_addr                          "0x0035"
#define  set_SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C18_reg(data)                      (*((volatile unsigned int*)SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C18_reg)=data)
#define  get_SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C18_reg                            (*((volatile unsigned int*)SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C18_reg))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C18_tab1_c18_shift                     (16)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C18_tab1_c19_shift                     (0)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C18_tab1_c18_mask                      (0x0FFF0000)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C18_tab1_c19_mask                      (0x00000FFF)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C18_tab1_c18(data)                     (0x0FFF0000&((data)<<16))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C18_tab1_c19(data)                     (0x00000FFF&(data))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C18_get_tab1_c18(data)                 ((0x0FFF0000&(data))>>16)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C18_get_tab1_c19(data)                 (0x00000FFF&(data))

#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C20                                    0x18025328
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C20_reg_addr                           "0xB8025328"
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C20_reg                                0xB8025328
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C20_inst_addr                          "0x0036"
#define  set_SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C20_reg(data)                      (*((volatile unsigned int*)SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C20_reg)=data)
#define  get_SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C20_reg                            (*((volatile unsigned int*)SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C20_reg))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C20_tab1_c20_shift                     (16)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C20_tab1_c21_shift                     (0)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C20_tab1_c20_mask                      (0x0FFF0000)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C20_tab1_c21_mask                      (0x00000FFF)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C20_tab1_c20(data)                     (0x0FFF0000&((data)<<16))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C20_tab1_c21(data)                     (0x00000FFF&(data))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C20_get_tab1_c20(data)                 ((0x0FFF0000&(data))>>16)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C20_get_tab1_c21(data)                 (0x00000FFF&(data))

#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C22                                    0x1802532C
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C22_reg_addr                           "0xB802532C"
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C22_reg                                0xB802532C
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C22_inst_addr                          "0x0037"
#define  set_SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C22_reg(data)                      (*((volatile unsigned int*)SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C22_reg)=data)
#define  get_SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C22_reg                            (*((volatile unsigned int*)SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C22_reg))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C22_tab1_c22_shift                     (16)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C22_tab1_c23_shift                     (0)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C22_tab1_c22_mask                      (0x0FFF0000)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C22_tab1_c23_mask                      (0x00000FFF)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C22_tab1_c22(data)                     (0x0FFF0000&((data)<<16))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C22_tab1_c23(data)                     (0x00000FFF&(data))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C22_get_tab1_c22(data)                 ((0x0FFF0000&(data))>>16)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C22_get_tab1_c23(data)                 (0x00000FFF&(data))

#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C24                                    0x18025330
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C24_reg_addr                           "0xB8025330"
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C24_reg                                0xB8025330
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C24_inst_addr                          "0x0038"
#define  set_SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C24_reg(data)                      (*((volatile unsigned int*)SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C24_reg)=data)
#define  get_SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C24_reg                            (*((volatile unsigned int*)SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C24_reg))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C24_tab1_c24_shift                     (16)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C24_tab1_c25_shift                     (0)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C24_tab1_c24_mask                      (0x0FFF0000)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C24_tab1_c25_mask                      (0x00000FFF)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C24_tab1_c24(data)                     (0x0FFF0000&((data)<<16))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C24_tab1_c25(data)                     (0x00000FFF&(data))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C24_get_tab1_c24(data)                 ((0x0FFF0000&(data))>>16)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C24_get_tab1_c25(data)                 (0x00000FFF&(data))

#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C26                                    0x18025334
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C26_reg_addr                           "0xB8025334"
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C26_reg                                0xB8025334
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C26_inst_addr                          "0x0039"
#define  set_SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C26_reg(data)                      (*((volatile unsigned int*)SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C26_reg)=data)
#define  get_SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C26_reg                            (*((volatile unsigned int*)SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C26_reg))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C26_tab1_c26_shift                     (16)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C26_tab1_c27_shift                     (0)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C26_tab1_c26_mask                      (0x0FFF0000)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C26_tab1_c27_mask                      (0x00000FFF)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C26_tab1_c26(data)                     (0x0FFF0000&((data)<<16))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C26_tab1_c27(data)                     (0x00000FFF&(data))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C26_get_tab1_c26(data)                 ((0x0FFF0000&(data))>>16)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C26_get_tab1_c27(data)                 (0x00000FFF&(data))

#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C28                                    0x18025338
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C28_reg_addr                           "0xB8025338"
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C28_reg                                0xB8025338
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C28_inst_addr                          "0x003A"
#define  set_SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C28_reg(data)                      (*((volatile unsigned int*)SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C28_reg)=data)
#define  get_SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C28_reg                            (*((volatile unsigned int*)SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C28_reg))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C28_tab1_c28_shift                     (16)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C28_tab1_c29_shift                     (0)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C28_tab1_c28_mask                      (0x0FFF0000)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C28_tab1_c29_mask                      (0x00000FFF)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C28_tab1_c28(data)                     (0x0FFF0000&((data)<<16))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C28_tab1_c29(data)                     (0x00000FFF&(data))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C28_get_tab1_c28(data)                 ((0x0FFF0000&(data))>>16)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C28_get_tab1_c29(data)                 (0x00000FFF&(data))

#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C30                                    0x1802533C
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C30_reg_addr                           "0xB802533C"
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C30_reg                                0xB802533C
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C30_inst_addr                          "0x003B"
#define  set_SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C30_reg(data)                      (*((volatile unsigned int*)SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C30_reg)=data)
#define  get_SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C30_reg                            (*((volatile unsigned int*)SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C30_reg))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C30_tab1_c30_shift                     (16)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C30_tab1_c31_shift                     (0)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C30_tab1_c30_mask                      (0x0FFF0000)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C30_tab1_c31_mask                      (0x00000FFF)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C30_tab1_c30(data)                     (0x0FFF0000&((data)<<16))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C30_tab1_c31(data)                     (0x00000FFF&(data))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C30_get_tab1_c30(data)                 ((0x0FFF0000&(data))>>16)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C30_get_tab1_c31(data)                 (0x00000FFF&(data))

#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C0                                     0x18025340
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C0_reg_addr                            "0xB8025340"
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C0_reg                                 0xB8025340
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C0_inst_addr                           "0x003C"
#define  set_SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C0_reg(data)                       (*((volatile unsigned int*)SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C0_reg)=data)
#define  get_SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C0_reg                             (*((volatile unsigned int*)SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C0_reg))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C0_tab2_c0_shift                       (16)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C0_tab2_c1_shift                       (0)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C0_tab2_c0_mask                        (0x0FFF0000)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C0_tab2_c1_mask                        (0x00000FFF)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C0_tab2_c0(data)                       (0x0FFF0000&((data)<<16))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C0_tab2_c1(data)                       (0x00000FFF&(data))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C0_get_tab2_c0(data)                   ((0x0FFF0000&(data))>>16)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C0_get_tab2_c1(data)                   (0x00000FFF&(data))

#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C2                                     0x18025344
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C2_reg_addr                            "0xB8025344"
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C2_reg                                 0xB8025344
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C2_inst_addr                           "0x003D"
#define  set_SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C2_reg(data)                       (*((volatile unsigned int*)SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C2_reg)=data)
#define  get_SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C2_reg                             (*((volatile unsigned int*)SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C2_reg))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C2_tab2_c2_shift                       (16)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C2_tab2_c3_shift                       (0)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C2_tab2_c2_mask                        (0x0FFF0000)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C2_tab2_c3_mask                        (0x00000FFF)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C2_tab2_c2(data)                       (0x0FFF0000&((data)<<16))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C2_tab2_c3(data)                       (0x00000FFF&(data))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C2_get_tab2_c2(data)                   ((0x0FFF0000&(data))>>16)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C2_get_tab2_c3(data)                   (0x00000FFF&(data))

#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C4                                     0x18025348
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C4_reg_addr                            "0xB8025348"
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C4_reg                                 0xB8025348
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C4_inst_addr                           "0x003E"
#define  set_SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C4_reg(data)                       (*((volatile unsigned int*)SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C4_reg)=data)
#define  get_SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C4_reg                             (*((volatile unsigned int*)SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C4_reg))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C4_tab2_c4_shift                       (16)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C4_tab2_c5_shift                       (0)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C4_tab2_c4_mask                        (0x0FFF0000)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C4_tab2_c5_mask                        (0x00000FFF)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C4_tab2_c4(data)                       (0x0FFF0000&((data)<<16))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C4_tab2_c5(data)                       (0x00000FFF&(data))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C4_get_tab2_c4(data)                   ((0x0FFF0000&(data))>>16)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C4_get_tab2_c5(data)                   (0x00000FFF&(data))

#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C6                                     0x1802534C
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C6_reg_addr                            "0xB802534C"
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C6_reg                                 0xB802534C
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C6_inst_addr                           "0x003F"
#define  set_SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C6_reg(data)                       (*((volatile unsigned int*)SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C6_reg)=data)
#define  get_SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C6_reg                             (*((volatile unsigned int*)SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C6_reg))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C6_tab2_c6_shift                       (16)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C6_tab2_c7_shift                       (0)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C6_tab2_c6_mask                        (0x0FFF0000)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C6_tab2_c7_mask                        (0x00000FFF)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C6_tab2_c6(data)                       (0x0FFF0000&((data)<<16))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C6_tab2_c7(data)                       (0x00000FFF&(data))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C6_get_tab2_c6(data)                   ((0x0FFF0000&(data))>>16)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C6_get_tab2_c7(data)                   (0x00000FFF&(data))

#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C8                                     0x18025350
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C8_reg_addr                            "0xB8025350"
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C8_reg                                 0xB8025350
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C8_inst_addr                           "0x0040"
#define  set_SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C8_reg(data)                       (*((volatile unsigned int*)SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C8_reg)=data)
#define  get_SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C8_reg                             (*((volatile unsigned int*)SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C8_reg))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C8_tab2_c8_shift                       (16)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C8_tab2_c9_shift                       (0)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C8_tab2_c8_mask                        (0x0FFF0000)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C8_tab2_c9_mask                        (0x00000FFF)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C8_tab2_c8(data)                       (0x0FFF0000&((data)<<16))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C8_tab2_c9(data)                       (0x00000FFF&(data))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C8_get_tab2_c8(data)                   ((0x0FFF0000&(data))>>16)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C8_get_tab2_c9(data)                   (0x00000FFF&(data))

#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C10                                    0x18025354
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C10_reg_addr                           "0xB8025354"
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C10_reg                                0xB8025354
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C10_inst_addr                          "0x0041"
#define  set_SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C10_reg(data)                      (*((volatile unsigned int*)SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C10_reg)=data)
#define  get_SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C10_reg                            (*((volatile unsigned int*)SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C10_reg))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C10_tab2_c10_shift                     (16)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C10_tab2_c11_shift                     (0)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C10_tab2_c10_mask                      (0x0FFF0000)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C10_tab2_c11_mask                      (0x00000FFF)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C10_tab2_c10(data)                     (0x0FFF0000&((data)<<16))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C10_tab2_c11(data)                     (0x00000FFF&(data))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C10_get_tab2_c10(data)                 ((0x0FFF0000&(data))>>16)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C10_get_tab2_c11(data)                 (0x00000FFF&(data))

#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C12                                    0x18025358
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C12_reg_addr                           "0xB8025358"
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C12_reg                                0xB8025358
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C12_inst_addr                          "0x0042"
#define  set_SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C12_reg(data)                      (*((volatile unsigned int*)SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C12_reg)=data)
#define  get_SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C12_reg                            (*((volatile unsigned int*)SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C12_reg))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C12_tab2_c12_shift                     (16)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C12_tab2_c13_shift                     (0)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C12_tab2_c12_mask                      (0x0FFF0000)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C12_tab2_c13_mask                      (0x00000FFF)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C12_tab2_c12(data)                     (0x0FFF0000&((data)<<16))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C12_tab2_c13(data)                     (0x00000FFF&(data))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C12_get_tab2_c12(data)                 ((0x0FFF0000&(data))>>16)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C12_get_tab2_c13(data)                 (0x00000FFF&(data))

#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C14                                    0x1802535C
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C14_reg_addr                           "0xB802535C"
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C14_reg                                0xB802535C
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C14_inst_addr                          "0x0043"
#define  set_SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C14_reg(data)                      (*((volatile unsigned int*)SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C14_reg)=data)
#define  get_SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C14_reg                            (*((volatile unsigned int*)SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C14_reg))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C14_tab2_c14_shift                     (16)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C14_tab2_c15_shift                     (0)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C14_tab2_c14_mask                      (0x0FFF0000)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C14_tab2_c15_mask                      (0x00000FFF)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C14_tab2_c14(data)                     (0x0FFF0000&((data)<<16))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C14_tab2_c15(data)                     (0x00000FFF&(data))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C14_get_tab2_c14(data)                 ((0x0FFF0000&(data))>>16)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C14_get_tab2_c15(data)                 (0x00000FFF&(data))

#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C16                                    0x18025360
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C16_reg_addr                           "0xB8025360"
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C16_reg                                0xB8025360
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C16_inst_addr                          "0x0044"
#define  set_SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C16_reg(data)                      (*((volatile unsigned int*)SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C16_reg)=data)
#define  get_SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C16_reg                            (*((volatile unsigned int*)SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C16_reg))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C16_tab2_c16_shift                     (16)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C16_tab2_c17_shift                     (0)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C16_tab2_c16_mask                      (0x0FFF0000)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C16_tab2_c17_mask                      (0x00000FFF)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C16_tab2_c16(data)                     (0x0FFF0000&((data)<<16))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C16_tab2_c17(data)                     (0x00000FFF&(data))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C16_get_tab2_c16(data)                 ((0x0FFF0000&(data))>>16)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C16_get_tab2_c17(data)                 (0x00000FFF&(data))

#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C18                                    0x18025364
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C18_reg_addr                           "0xB8025364"
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C18_reg                                0xB8025364
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C18_inst_addr                          "0x0045"
#define  set_SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C18_reg(data)                      (*((volatile unsigned int*)SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C18_reg)=data)
#define  get_SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C18_reg                            (*((volatile unsigned int*)SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C18_reg))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C18_tab2_c18_shift                     (16)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C18_tab2_c19_shift                     (0)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C18_tab2_c18_mask                      (0x0FFF0000)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C18_tab2_c19_mask                      (0x00000FFF)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C18_tab2_c18(data)                     (0x0FFF0000&((data)<<16))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C18_tab2_c19(data)                     (0x00000FFF&(data))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C18_get_tab2_c18(data)                 ((0x0FFF0000&(data))>>16)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C18_get_tab2_c19(data)                 (0x00000FFF&(data))

#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C20                                    0x18025368
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C20_reg_addr                           "0xB8025368"
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C20_reg                                0xB8025368
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C20_inst_addr                          "0x0046"
#define  set_SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C20_reg(data)                      (*((volatile unsigned int*)SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C20_reg)=data)
#define  get_SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C20_reg                            (*((volatile unsigned int*)SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C20_reg))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C20_tab2_c20_shift                     (16)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C20_tab2_c21_shift                     (0)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C20_tab2_c20_mask                      (0x0FFF0000)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C20_tab2_c21_mask                      (0x00000FFF)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C20_tab2_c20(data)                     (0x0FFF0000&((data)<<16))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C20_tab2_c21(data)                     (0x00000FFF&(data))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C20_get_tab2_c20(data)                 ((0x0FFF0000&(data))>>16)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C20_get_tab2_c21(data)                 (0x00000FFF&(data))

#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C22                                    0x1802536C
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C22_reg_addr                           "0xB802536C"
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C22_reg                                0xB802536C
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C22_inst_addr                          "0x0047"
#define  set_SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C22_reg(data)                      (*((volatile unsigned int*)SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C22_reg)=data)
#define  get_SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C22_reg                            (*((volatile unsigned int*)SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C22_reg))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C22_tab2_c22_shift                     (16)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C22_tab2_c23_shift                     (0)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C22_tab2_c22_mask                      (0x0FFF0000)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C22_tab2_c23_mask                      (0x00000FFF)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C22_tab2_c22(data)                     (0x0FFF0000&((data)<<16))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C22_tab2_c23(data)                     (0x00000FFF&(data))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C22_get_tab2_c22(data)                 ((0x0FFF0000&(data))>>16)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C22_get_tab2_c23(data)                 (0x00000FFF&(data))

#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C24                                    0x18025370
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C24_reg_addr                           "0xB8025370"
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C24_reg                                0xB8025370
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C24_inst_addr                          "0x0048"
#define  set_SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C24_reg(data)                      (*((volatile unsigned int*)SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C24_reg)=data)
#define  get_SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C24_reg                            (*((volatile unsigned int*)SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C24_reg))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C24_tab2_c24_shift                     (16)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C24_tab2_c25_shift                     (0)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C24_tab2_c24_mask                      (0x0FFF0000)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C24_tab2_c25_mask                      (0x00000FFF)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C24_tab2_c24(data)                     (0x0FFF0000&((data)<<16))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C24_tab2_c25(data)                     (0x00000FFF&(data))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C24_get_tab2_c24(data)                 ((0x0FFF0000&(data))>>16)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C24_get_tab2_c25(data)                 (0x00000FFF&(data))

#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C26                                    0x18025374
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C26_reg_addr                           "0xB8025374"
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C26_reg                                0xB8025374
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C26_inst_addr                          "0x0049"
#define  set_SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C26_reg(data)                      (*((volatile unsigned int*)SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C26_reg)=data)
#define  get_SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C26_reg                            (*((volatile unsigned int*)SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C26_reg))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C26_tab2_c26_shift                     (16)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C26_tab2_c27_shift                     (0)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C26_tab2_c26_mask                      (0x0FFF0000)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C26_tab2_c27_mask                      (0x00000FFF)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C26_tab2_c26(data)                     (0x0FFF0000&((data)<<16))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C26_tab2_c27(data)                     (0x00000FFF&(data))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C26_get_tab2_c26(data)                 ((0x0FFF0000&(data))>>16)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C26_get_tab2_c27(data)                 (0x00000FFF&(data))

#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C28                                    0x18025378
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C28_reg_addr                           "0xB8025378"
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C28_reg                                0xB8025378
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C28_inst_addr                          "0x004A"
#define  set_SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C28_reg(data)                      (*((volatile unsigned int*)SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C28_reg)=data)
#define  get_SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C28_reg                            (*((volatile unsigned int*)SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C28_reg))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C28_tab2_c28_shift                     (16)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C28_tab2_c29_shift                     (0)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C28_tab2_c28_mask                      (0x0FFF0000)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C28_tab2_c29_mask                      (0x00000FFF)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C28_tab2_c28(data)                     (0x0FFF0000&((data)<<16))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C28_tab2_c29(data)                     (0x00000FFF&(data))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C28_get_tab2_c28(data)                 ((0x0FFF0000&(data))>>16)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C28_get_tab2_c29(data)                 (0x00000FFF&(data))

#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C30                                    0x1802537C
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C30_reg_addr                           "0xB802537C"
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C30_reg                                0xB802537C
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C30_inst_addr                          "0x004B"
#define  set_SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C30_reg(data)                      (*((volatile unsigned int*)SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C30_reg)=data)
#define  get_SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C30_reg                            (*((volatile unsigned int*)SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C30_reg))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C30_tab2_c30_shift                     (16)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C30_tab2_c31_shift                     (0)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C30_tab2_c30_mask                      (0x0FFF0000)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C30_tab2_c31_mask                      (0x00000FFF)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C30_tab2_c30(data)                     (0x0FFF0000&((data)<<16))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C30_tab2_c31(data)                     (0x00000FFF&(data))
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C30_get_tab2_c30(data)                 ((0x0FFF0000&(data))>>16)
#define  SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C30_get_tab2_c31(data)                 (0x00000FFF&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======SCALEDOWN register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  acs_sel:1;
        RBus_UInt32  crc_sel:1;
        RBus_UInt32  to_m_domain_sel:1;
        RBus_UInt32  cutout_en:1;
        RBus_UInt32  sel_3d_en:1;
        RBus_UInt32  truncationctrl:1;
        RBus_UInt32  res2:8;
        RBus_UInt32  dummy18025204_15_14:2;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  video_comp_en:1;
        RBus_UInt32  odd_inv:1;
        RBus_UInt32  out_bit:1;
        RBus_UInt32  sort_fmt:1;
        RBus_UInt32  v_y_table_sel:1;
        RBus_UInt32  v_c_table_sel:1;
        RBus_UInt32  h_y_table_sel:1;
        RBus_UInt32  h_c_table_sel:1;
        RBus_UInt32  buffer_mode:2;
        RBus_UInt32  v_zoom_en:1;
        RBus_UInt32  h_zoom_en:1;
    };
}scaledown_ich1_uzd_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  four_tap_en:1;
        RBus_UInt32  lp121_en:1;
        RBus_UInt32  res3:9;
        RBus_UInt32  vsd_3d_boundary:13;
        RBus_UInt32  res4:1;
        RBus_UInt32  vsd_3d_mode:2;
    };
}scaledown_ich1_uzd_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  hor_fac:25;
    };
}scaledown_ich1_uzd_scale_hor_factor_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  ver_ini_int_l:1;
        RBus_UInt32  ver_ini_int:1;
        RBus_UInt32  ver_fac:25;
    };
}scaledown_ich1_uzd_scale_ver_factor_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hor_ini_l:8;
        RBus_UInt32  ver_ini_l:8;
        RBus_UInt32  hor_ini:8;
        RBus_UInt32  ver_ini:8;
    };
}scaledown_ich1_uzd_initial_value_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  nl_d1:14;
    };
}scaledown_ich1_uzd_hor_delta1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  nl_seg1:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  nl_seg2:12;
    };
}scaledown_ich1_uzd_hor_segment_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  crc_source_vsd_hsd_sel:1;
        RBus_UInt32  r_auto_cmp_en:1;
        RBus_UInt32  l_auto_cmp_en:1;
        RBus_UInt32  crc_3d_en:1;
        RBus_UInt32  conti:1;
        RBus_UInt32  start:1;
    };
}scaledown_ich1_uzd_crc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_l_result:32;
    };
}scaledown_ich1_uzd_crc_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_r_result:32;
    };
}scaledown_ich1_uzd_crc_result_right_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  l_des_crc:32;
    };
}scaledown_ich1_uzd_l_des_crc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  r_des_crc:32;
    };
}scaledown_ich1_uzd_r_des_crc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  r_crc_err_cnt:16;
        RBus_UInt32  l_crc_err_cnt:16;
    };
}scaledown_ich1_uzd_crc_err_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  ibuf_v_size:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  ibuf_h_size:13;
    };
}scaledown_ich1_ibuff_ctrli_buff_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  res2:1;
        RBus_UInt32  rgb_ch_swap:3;
    };
}scaledown_ich1_uzd_channel_swap_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  mdom_comp_rd_sel:1;
        RBus_UInt32  mdom_comp_db_en:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  h_db_apply:1;
        RBus_UInt32  h_db_rd_sel:1;
        RBus_UInt32  h_db_en:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  v_db_apply:1;
        RBus_UInt32  v_db_rd_sel:1;
        RBus_UInt32  v_db_en:1;
    };
}scaledown_ich1_uzd_db_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  timing_monitor_en:1;
        RBus_UInt32  timing_monitor_i2rnd_mode:2;
        RBus_UInt32  timing_monitor_src:1;
        RBus_UInt32  timing_monitor_unit:1;
        RBus_UInt32  timing_monitor_multi_mode:1;
        RBus_UInt32  timing_monitor_compare:2;
        RBus_UInt32  res1:8;
        RBus_UInt32  timing_monitor_sta0:4;
        RBus_UInt32  timing_monitor_end0:4;
        RBus_UInt32  timing_monitor_sta1:4;
        RBus_UInt32  timing_monitor_end1:4;
    };
}scaledown_uzd_timing_monitor_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  timing_monitor_sta2:4;
        RBus_UInt32  timing_monitor_end2:4;
        RBus_UInt32  timing_monitor_sta3:4;
        RBus_UInt32  timing_monitor_end3:4;
        RBus_UInt32  timing_monitor_sta4:4;
        RBus_UInt32  timing_monitor_end4:4;
        RBus_UInt32  timing_monitor_sta5:4;
        RBus_UInt32  timing_monitor_end5:4;
    };
}scaledown_uzd_timing_monitor_multi_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  t_m_compare_th:28;
    };
}scaledown_uzd_timing_monitor_compare_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  t_m_golden:28;
    };
}scaledown_uzd_timing_monitor_golden_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  t_m_result_previous1:28;
    };
}scaledown_uzd_timing_monitor_result1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  t_m_result_previous2:28;
    };
}scaledown_uzd_timing_monitor_result2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  t_m_result_previous3:28;
    };
}scaledown_uzd_timing_monitor_result3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  t_m_result_previous4:28;
    };
}scaledown_uzd_timing_monitor_result4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  t_m_result_max:28;
    };
}scaledown_uzd_timing_monitor_max_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  t_m_result_min:28;
    };
}scaledown_uzd_timing_monitor_min_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  compare_hit:1;
        RBus_UInt32  hsync_hit_den_error:1;
        RBus_UInt32  vsync_hit_den_error:1;
    };
}scaledown_uzd_timing_monitor_st_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  write_en:1;
        RBus_UInt32  read_en:1;
    };
}scaledown_accessdata_ctrl_uzd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  starty:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  startx:13;
    };
}scaledown_accessdata_posctrl_uzd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  y01:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  y00:10;
    };
}scaledown_readdata_data_y1_uzd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  y11:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  y10:10;
    };
}scaledown_readdata_data_y2_uzd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  v00:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  u00:10;
    };
}scaledown_readdata_data_c1_uzd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  v01:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  u01:10;
    };
}scaledown_readdata_data_c2_uzd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  v10:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  u10:10;
    };
}scaledown_readdata_data_c3_uzd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  v11:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  u11:10;
    };
}scaledown_readdata_data_c4_uzd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  v:4;
        RBus_UInt32  u:4;
        RBus_UInt32  y:4;
    };
}scaledown_writedata_data_uzd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  res5:1;
    };
}scaledown_ich1_sdnr_bist_fsbuf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  res5:1;
    };
}scaledown_ich1_sdnr_drf_fsbuf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  res2:1;
        RBus_UInt32  bisr_linebuf_fail_2:1;
        RBus_UInt32  bisr_linebuf_fail_1:1;
        RBus_UInt32  bisr_linebuf_fail_0:1;
    };
}scaledown_ich1_sdnr_bisr_linebuf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  res2:1;
        RBus_UInt32  sdnr_drf_linebuf_fail_2:1;
        RBus_UInt32  sdnr_drf_linebuf_fail_1:1;
        RBus_UInt32  sdnr_drf_linebuf_fail_0:1;
    };
}scaledown_ich1_sdnr_drf_linebuf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  sdnr_linebuf_1_2_ls_en:1;
        RBus_UInt32  sdnr_linebuf_1_2_dvse:1;
        RBus_UInt32  sdnr_linebuf_1_2_dvs:4;
        RBus_UInt32  res2:2;
        RBus_UInt32  sdnr_linebuf_1_1_ls_en:1;
        RBus_UInt32  sdnr_linebuf_1_1_dvse:1;
        RBus_UInt32  sdnr_linebuf_1_1_dvs:4;
        RBus_UInt32  res3:2;
        RBus_UInt32  sdnr_linebuf_1_0_ls_en:1;
        RBus_UInt32  sdnr_linebuf_1_0_dvse:1;
        RBus_UInt32  sdnr_linebuf_1_0_dvs:4;
        RBus_UInt32  res4:2;
        RBus_UInt32  res5:1;
        RBus_UInt32  res6:1;
        RBus_UInt32  res7:4;
    };
}scaledown_ich1_sdnr_linebuf_dvs_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:4;
        RBus_UInt32  res5:10;
        RBus_UInt32  res6:1;
        RBus_UInt32  res7:1;
        RBus_UInt32  res8:4;
    };
}scaledown_ich1_sdnr_fsbuf_dvs01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:4;
        RBus_UInt32  res5:10;
        RBus_UInt32  res6:1;
        RBus_UInt32  res7:1;
        RBus_UInt32  res8:4;
    };
}scaledown_ich1_sdnr_fsbuf_dvs23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  res2:1;
    };
}scaledown_ich1_sdnr_bisr_linebuf_repaired_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  hor_front:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  hor_back:12;
    };
}scaledown_ich1_sdnr_cutout_range_hor_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  ver_front:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  ver_back:12;
    };
}scaledown_ich1_sdnr_cutout_range_ver0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  ver_mid_top:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  ver_mid_bot:12;
    };
}scaledown_ich1_sdnr_cutout_range_ver1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  cr_dly_cb:1;
        RBus_UInt32  drop:1;
        RBus_UInt32  dummy180252f0_0:1;
    };
}scaledown_ich1_sdnr_444to422_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  hsd_3d_boundary:13;
    };
}scaledown_ich1_hsd_3d_boundary_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c0:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c1:12;
    };
}scaledown_ich1_uzd_fir_coef_tab1_c0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c2:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c3:12;
    };
}scaledown_ich1_uzd_fir_coef_tab1_c2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c4:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c5:12;
    };
}scaledown_ich1_uzd_fir_coef_tab1_c4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c6:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c7:12;
    };
}scaledown_ich1_uzd_fir_coef_tab1_c6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c8:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c9:12;
    };
}scaledown_ich1_uzd_fir_coef_tab1_c8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c10:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c11:12;
    };
}scaledown_ich1_uzd_fir_coef_tab1_c10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c12:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c13:12;
    };
}scaledown_ich1_uzd_fir_coef_tab1_c12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c14:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c15:12;
    };
}scaledown_ich1_uzd_fir_coef_tab1_c14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c16:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c17:12;
    };
}scaledown_ich1_uzd_fir_coef_tab1_c16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c18:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c19:12;
    };
}scaledown_ich1_uzd_fir_coef_tab1_c18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c20:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c21:12;
    };
}scaledown_ich1_uzd_fir_coef_tab1_c20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c22:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c23:12;
    };
}scaledown_ich1_uzd_fir_coef_tab1_c22_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c24:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c25:12;
    };
}scaledown_ich1_uzd_fir_coef_tab1_c24_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c26:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c27:12;
    };
}scaledown_ich1_uzd_fir_coef_tab1_c26_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c28:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c29:12;
    };
}scaledown_ich1_uzd_fir_coef_tab1_c28_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c30:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c31:12;
    };
}scaledown_ich1_uzd_fir_coef_tab1_c30_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c0:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c1:12;
    };
}scaledown_ich1_uzd_fir_coef_tab2_c0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c2:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c3:12;
    };
}scaledown_ich1_uzd_fir_coef_tab2_c2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c4:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c5:12;
    };
}scaledown_ich1_uzd_fir_coef_tab2_c4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c6:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c7:12;
    };
}scaledown_ich1_uzd_fir_coef_tab2_c6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c8:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c9:12;
    };
}scaledown_ich1_uzd_fir_coef_tab2_c8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c10:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c11:12;
    };
}scaledown_ich1_uzd_fir_coef_tab2_c10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c12:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c13:12;
    };
}scaledown_ich1_uzd_fir_coef_tab2_c12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c14:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c15:12;
    };
}scaledown_ich1_uzd_fir_coef_tab2_c14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c16:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c17:12;
    };
}scaledown_ich1_uzd_fir_coef_tab2_c16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c18:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c19:12;
    };
}scaledown_ich1_uzd_fir_coef_tab2_c18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c20:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c21:12;
    };
}scaledown_ich1_uzd_fir_coef_tab2_c20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c22:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c23:12;
    };
}scaledown_ich1_uzd_fir_coef_tab2_c22_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c24:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c25:12;
    };
}scaledown_ich1_uzd_fir_coef_tab2_c24_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c26:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c27:12;
    };
}scaledown_ich1_uzd_fir_coef_tab2_c26_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c28:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c29:12;
    };
}scaledown_ich1_uzd_fir_coef_tab2_c28_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c30:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c31:12;
    };
}scaledown_ich1_uzd_fir_coef_tab2_c30_RBUS;

#else //apply LITTLE_ENDIAN

//======SCALEDOWN register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  h_zoom_en:1;
        RBus_UInt32  v_zoom_en:1;
        RBus_UInt32  buffer_mode:2;
        RBus_UInt32  h_c_table_sel:1;
        RBus_UInt32  h_y_table_sel:1;
        RBus_UInt32  v_c_table_sel:1;
        RBus_UInt32  v_y_table_sel:1;
        RBus_UInt32  sort_fmt:1;
        RBus_UInt32  out_bit:1;
        RBus_UInt32  odd_inv:1;
        RBus_UInt32  video_comp_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  dummy18025204_15_14:2;
        RBus_UInt32  res3:8;
        RBus_UInt32  truncationctrl:1;
        RBus_UInt32  sel_3d_en:1;
        RBus_UInt32  cutout_en:1;
        RBus_UInt32  to_m_domain_sel:1;
        RBus_UInt32  crc_sel:1;
        RBus_UInt32  acs_sel:1;
        RBus_UInt32  res4:2;
    };
}scaledown_ich1_uzd_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vsd_3d_mode:2;
        RBus_UInt32  res1:1;
        RBus_UInt32  vsd_3d_boundary:13;
        RBus_UInt32  res2:9;
        RBus_UInt32  lp121_en:1;
        RBus_UInt32  four_tap_en:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:4;
    };
}scaledown_ich1_uzd_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hor_fac:25;
        RBus_UInt32  res1:7;
    };
}scaledown_ich1_uzd_scale_hor_factor_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ver_fac:25;
        RBus_UInt32  ver_ini_int:1;
        RBus_UInt32  ver_ini_int_l:1;
        RBus_UInt32  res1:5;
    };
}scaledown_ich1_uzd_scale_ver_factor_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ver_ini:8;
        RBus_UInt32  hor_ini:8;
        RBus_UInt32  ver_ini_l:8;
        RBus_UInt32  hor_ini_l:8;
    };
}scaledown_ich1_uzd_initial_value_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  nl_d1:14;
        RBus_UInt32  res1:18;
    };
}scaledown_ich1_uzd_hor_delta1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  nl_seg2:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  nl_seg1:12;
        RBus_UInt32  res2:4;
    };
}scaledown_ich1_uzd_hor_segment_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  start:1;
        RBus_UInt32  conti:1;
        RBus_UInt32  crc_3d_en:1;
        RBus_UInt32  l_auto_cmp_en:1;
        RBus_UInt32  r_auto_cmp_en:1;
        RBus_UInt32  crc_source_vsd_hsd_sel:1;
        RBus_UInt32  res1:26;
    };
}scaledown_ich1_uzd_crc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_l_result:32;
    };
}scaledown_ich1_uzd_crc_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_r_result:32;
    };
}scaledown_ich1_uzd_crc_result_right_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  l_des_crc:32;
    };
}scaledown_ich1_uzd_l_des_crc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  r_des_crc:32;
    };
}scaledown_ich1_uzd_r_des_crc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  l_crc_err_cnt:16;
        RBus_UInt32  r_crc_err_cnt:16;
    };
}scaledown_ich1_uzd_crc_err_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ibuf_h_size:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  ibuf_v_size:13;
        RBus_UInt32  res2:3;
    };
}scaledown_ich1_ibuff_ctrli_buff_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rgb_ch_swap:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  res2:28;
    };
}scaledown_ich1_uzd_channel_swap_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  v_db_en:1;
        RBus_UInt32  v_db_rd_sel:1;
        RBus_UInt32  v_db_apply:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  h_db_en:1;
        RBus_UInt32  h_db_rd_sel:1;
        RBus_UInt32  h_db_apply:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  mdom_comp_db_en:1;
        RBus_UInt32  mdom_comp_rd_sel:1;
        RBus_UInt32  res3:22;
    };
}scaledown_ich1_uzd_db_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  timing_monitor_end1:4;
        RBus_UInt32  timing_monitor_sta1:4;
        RBus_UInt32  timing_monitor_end0:4;
        RBus_UInt32  timing_monitor_sta0:4;
        RBus_UInt32  res1:8;
        RBus_UInt32  timing_monitor_compare:2;
        RBus_UInt32  timing_monitor_multi_mode:1;
        RBus_UInt32  timing_monitor_unit:1;
        RBus_UInt32  timing_monitor_src:1;
        RBus_UInt32  timing_monitor_i2rnd_mode:2;
        RBus_UInt32  timing_monitor_en:1;
    };
}scaledown_uzd_timing_monitor_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  timing_monitor_end5:4;
        RBus_UInt32  timing_monitor_sta5:4;
        RBus_UInt32  timing_monitor_end4:4;
        RBus_UInt32  timing_monitor_sta4:4;
        RBus_UInt32  timing_monitor_end3:4;
        RBus_UInt32  timing_monitor_sta3:4;
        RBus_UInt32  timing_monitor_end2:4;
        RBus_UInt32  timing_monitor_sta2:4;
    };
}scaledown_uzd_timing_monitor_multi_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  t_m_compare_th:28;
        RBus_UInt32  res1:4;
    };
}scaledown_uzd_timing_monitor_compare_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  t_m_golden:28;
        RBus_UInt32  res1:4;
    };
}scaledown_uzd_timing_monitor_golden_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  t_m_result_previous1:28;
        RBus_UInt32  res1:4;
    };
}scaledown_uzd_timing_monitor_result1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  t_m_result_previous2:28;
        RBus_UInt32  res1:4;
    };
}scaledown_uzd_timing_monitor_result2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  t_m_result_previous3:28;
        RBus_UInt32  res1:4;
    };
}scaledown_uzd_timing_monitor_result3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  t_m_result_previous4:28;
        RBus_UInt32  res1:4;
    };
}scaledown_uzd_timing_monitor_result4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  t_m_result_max:28;
        RBus_UInt32  res1:4;
    };
}scaledown_uzd_timing_monitor_max_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  t_m_result_min:28;
        RBus_UInt32  res1:4;
    };
}scaledown_uzd_timing_monitor_min_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vsync_hit_den_error:1;
        RBus_UInt32  hsync_hit_den_error:1;
        RBus_UInt32  compare_hit:1;
        RBus_UInt32  res1:29;
    };
}scaledown_uzd_timing_monitor_st_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  read_en:1;
        RBus_UInt32  write_en:1;
        RBus_UInt32  res1:30;
    };
}scaledown_accessdata_ctrl_uzd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  startx:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  starty:13;
        RBus_UInt32  res2:3;
    };
}scaledown_accessdata_posctrl_uzd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y00:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  y01:10;
        RBus_UInt32  res2:6;
    };
}scaledown_readdata_data_y1_uzd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y10:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  y11:10;
        RBus_UInt32  res2:6;
    };
}scaledown_readdata_data_y2_uzd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  u00:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  v00:10;
        RBus_UInt32  res2:6;
    };
}scaledown_readdata_data_c1_uzd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  u01:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  v01:10;
        RBus_UInt32  res2:6;
    };
}scaledown_readdata_data_c2_uzd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  u10:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  v10:10;
        RBus_UInt32  res2:6;
    };
}scaledown_readdata_data_c3_uzd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  u11:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  v11:10;
        RBus_UInt32  res2:6;
    };
}scaledown_readdata_data_c4_uzd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y:4;
        RBus_UInt32  u:4;
        RBus_UInt32  v:4;
        RBus_UInt32  res1:20;
    };
}scaledown_writedata_data_uzd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  res5:28;
    };
}scaledown_ich1_sdnr_bist_fsbuf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  res5:28;
    };
}scaledown_ich1_sdnr_drf_fsbuf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bisr_linebuf_fail_0:1;
        RBus_UInt32  bisr_linebuf_fail_1:1;
        RBus_UInt32  bisr_linebuf_fail_2:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  res2:28;
    };
}scaledown_ich1_sdnr_bisr_linebuf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sdnr_drf_linebuf_fail_0:1;
        RBus_UInt32  sdnr_drf_linebuf_fail_1:1;
        RBus_UInt32  sdnr_drf_linebuf_fail_2:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  res2:28;
    };
}scaledown_ich1_sdnr_drf_linebuf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:2;
        RBus_UInt32  sdnr_linebuf_1_0_dvs:4;
        RBus_UInt32  sdnr_linebuf_1_0_dvse:1;
        RBus_UInt32  sdnr_linebuf_1_0_ls_en:1;
        RBus_UInt32  res5:2;
        RBus_UInt32  sdnr_linebuf_1_1_dvs:4;
        RBus_UInt32  sdnr_linebuf_1_1_dvse:1;
        RBus_UInt32  sdnr_linebuf_1_1_ls_en:1;
        RBus_UInt32  res6:2;
        RBus_UInt32  sdnr_linebuf_1_2_dvs:4;
        RBus_UInt32  sdnr_linebuf_1_2_dvse:1;
        RBus_UInt32  sdnr_linebuf_1_2_ls_en:1;
        RBus_UInt32  res7:2;
    };
}scaledown_ich1_sdnr_linebuf_dvs_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:10;
        RBus_UInt32  res5:4;
        RBus_UInt32  res6:1;
        RBus_UInt32  res7:1;
        RBus_UInt32  res8:10;
    };
}scaledown_ich1_sdnr_fsbuf_dvs01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:10;
        RBus_UInt32  res5:4;
        RBus_UInt32  res6:1;
        RBus_UInt32  res7:1;
        RBus_UInt32  res8:10;
    };
}scaledown_ich1_sdnr_fsbuf_dvs23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  res2:31;
    };
}scaledown_ich1_sdnr_bisr_linebuf_repaired_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hor_back:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  hor_front:12;
        RBus_UInt32  res2:4;
    };
}scaledown_ich1_sdnr_cutout_range_hor_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ver_back:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  ver_front:12;
        RBus_UInt32  res2:4;
    };
}scaledown_ich1_sdnr_cutout_range_ver0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ver_mid_bot:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  ver_mid_top:12;
        RBus_UInt32  res2:4;
    };
}scaledown_ich1_sdnr_cutout_range_ver1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy180252f0_0:1;
        RBus_UInt32  drop:1;
        RBus_UInt32  cr_dly_cb:1;
        RBus_UInt32  res1:29;
    };
}scaledown_ich1_sdnr_444to422_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hsd_3d_boundary:13;
        RBus_UInt32  res1:19;
    };
}scaledown_ich1_hsd_3d_boundary_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c1:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c0:12;
        RBus_UInt32  res2:4;
    };
}scaledown_ich1_uzd_fir_coef_tab1_c0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c3:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c2:12;
        RBus_UInt32  res2:4;
    };
}scaledown_ich1_uzd_fir_coef_tab1_c2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c5:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c4:12;
        RBus_UInt32  res2:4;
    };
}scaledown_ich1_uzd_fir_coef_tab1_c4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c7:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c6:12;
        RBus_UInt32  res2:4;
    };
}scaledown_ich1_uzd_fir_coef_tab1_c6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c9:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c8:12;
        RBus_UInt32  res2:4;
    };
}scaledown_ich1_uzd_fir_coef_tab1_c8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c11:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c10:12;
        RBus_UInt32  res2:4;
    };
}scaledown_ich1_uzd_fir_coef_tab1_c10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c13:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c12:12;
        RBus_UInt32  res2:4;
    };
}scaledown_ich1_uzd_fir_coef_tab1_c12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c15:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c14:12;
        RBus_UInt32  res2:4;
    };
}scaledown_ich1_uzd_fir_coef_tab1_c14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c17:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c16:12;
        RBus_UInt32  res2:4;
    };
}scaledown_ich1_uzd_fir_coef_tab1_c16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c19:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c18:12;
        RBus_UInt32  res2:4;
    };
}scaledown_ich1_uzd_fir_coef_tab1_c18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c21:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c20:12;
        RBus_UInt32  res2:4;
    };
}scaledown_ich1_uzd_fir_coef_tab1_c20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c23:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c22:12;
        RBus_UInt32  res2:4;
    };
}scaledown_ich1_uzd_fir_coef_tab1_c22_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c25:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c24:12;
        RBus_UInt32  res2:4;
    };
}scaledown_ich1_uzd_fir_coef_tab1_c24_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c27:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c26:12;
        RBus_UInt32  res2:4;
    };
}scaledown_ich1_uzd_fir_coef_tab1_c26_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c29:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c28:12;
        RBus_UInt32  res2:4;
    };
}scaledown_ich1_uzd_fir_coef_tab1_c28_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c31:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c30:12;
        RBus_UInt32  res2:4;
    };
}scaledown_ich1_uzd_fir_coef_tab1_c30_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c1:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c0:12;
        RBus_UInt32  res2:4;
    };
}scaledown_ich1_uzd_fir_coef_tab2_c0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c3:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c2:12;
        RBus_UInt32  res2:4;
    };
}scaledown_ich1_uzd_fir_coef_tab2_c2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c5:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c4:12;
        RBus_UInt32  res2:4;
    };
}scaledown_ich1_uzd_fir_coef_tab2_c4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c7:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c6:12;
        RBus_UInt32  res2:4;
    };
}scaledown_ich1_uzd_fir_coef_tab2_c6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c9:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c8:12;
        RBus_UInt32  res2:4;
    };
}scaledown_ich1_uzd_fir_coef_tab2_c8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c11:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c10:12;
        RBus_UInt32  res2:4;
    };
}scaledown_ich1_uzd_fir_coef_tab2_c10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c13:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c12:12;
        RBus_UInt32  res2:4;
    };
}scaledown_ich1_uzd_fir_coef_tab2_c12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c15:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c14:12;
        RBus_UInt32  res2:4;
    };
}scaledown_ich1_uzd_fir_coef_tab2_c14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c17:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c16:12;
        RBus_UInt32  res2:4;
    };
}scaledown_ich1_uzd_fir_coef_tab2_c16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c19:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c18:12;
        RBus_UInt32  res2:4;
    };
}scaledown_ich1_uzd_fir_coef_tab2_c18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c21:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c20:12;
        RBus_UInt32  res2:4;
    };
}scaledown_ich1_uzd_fir_coef_tab2_c20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c23:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c22:12;
        RBus_UInt32  res2:4;
    };
}scaledown_ich1_uzd_fir_coef_tab2_c22_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c25:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c24:12;
        RBus_UInt32  res2:4;
    };
}scaledown_ich1_uzd_fir_coef_tab2_c24_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c27:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c26:12;
        RBus_UInt32  res2:4;
    };
}scaledown_ich1_uzd_fir_coef_tab2_c26_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c29:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c28:12;
        RBus_UInt32  res2:4;
    };
}scaledown_ich1_uzd_fir_coef_tab2_c28_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c31:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c30:12;
        RBus_UInt32  res2:4;
    };
}scaledown_ich1_uzd_fir_coef_tab2_c30_RBUS;




#endif 


#endif 
