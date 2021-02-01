/**
* @file rbusOnmsReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2016/6/7
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_ONMS_REG_H_
#define _RBUS_ONMS_REG_H_

#include "rbus_types.h"



//  ONMS Register Address
#define  ONMS_onms1_ctrl                                                         0x18021200
#define  ONMS_onms1_ctrl_reg_addr                                                "0xB8021200"
#define  ONMS_onms1_ctrl_reg                                                     0xB8021200
#define  ONMS_onms1_ctrl_inst_addr                                               "0x0000"
#define  set_ONMS_onms1_ctrl_reg(data)                                           (*((volatile unsigned int*)ONMS_onms1_ctrl_reg)=data)
#define  get_ONMS_onms1_ctrl_reg                                                 (*((volatile unsigned int*)ONMS_onms1_ctrl_reg))
#define  ONMS_onms1_ctrl_on1_4k2k_mode_shift                                     (30)
#define  ONMS_onms1_ctrl_on1_ms_src_sel_shift                                    (29)
#define  ONMS_onms1_ctrl_on1_blk_2frame_en_shift                                 (28)
#define  ONMS_onms1_ctrl_on1_pixel_get_en_shift                                  (27)
#define  ONMS_onms1_ctrl_on1_pixel_get_sel_shift                                 (25)
#define  ONMS_onms1_ctrl_on1_progressive_shift                                   (24)
#define  ONMS_onms1_ctrl_on1_vtotal_max_delta_shift                              (20)
#define  ONMS_onms1_ctrl_on1_htotal_max_delta_shift                              (16)
#define  ONMS_onms1_ctrl_dummy_15_shift                                          (15)
#define  ONMS_onms1_ctrl_dummy_14_shift                                          (14)
#define  ONMS_onms1_ctrl_dummy_13_shift                                          (13)
#define  ONMS_onms1_ctrl_on1_pixel_encoding_shift                                (12)
#define  ONMS_onms1_ctrl_on1_vact_space_threshold_shift                          (8)
#define  ONMS_onms1_ctrl_on1_vact_space_meas_en_shift                            (7)
#define  ONMS_onms1_ctrl_on1_meas_to_sel_shift                                   (6)
#define  ONMS_onms1_ctrl_on1_sycms_clk_shift                                     (5)
#define  ONMS_onms1_ctrl_on1_vs_meas_inv_shift                                   (4)
#define  ONMS_onms1_ctrl_on1_hs_meas_inv_shift                                   (3)
#define  ONMS_onms1_ctrl_on1_popup_meas_shift                                    (2)
#define  ONMS_onms1_ctrl_on1_ms_conti_shift                                      (1)
#define  ONMS_onms1_ctrl_on1_start_ms_shift                                      (0)
#define  ONMS_onms1_ctrl_on1_4k2k_mode_mask                                      (0xC0000000)
#define  ONMS_onms1_ctrl_on1_ms_src_sel_mask                                     (0x20000000)
#define  ONMS_onms1_ctrl_on1_blk_2frame_en_mask                                  (0x10000000)
#define  ONMS_onms1_ctrl_on1_pixel_get_en_mask                                   (0x08000000)
#define  ONMS_onms1_ctrl_on1_pixel_get_sel_mask                                  (0x06000000)
#define  ONMS_onms1_ctrl_on1_progressive_mask                                    (0x01000000)
#define  ONMS_onms1_ctrl_on1_vtotal_max_delta_mask                               (0x00F00000)
#define  ONMS_onms1_ctrl_on1_htotal_max_delta_mask                               (0x000F0000)
#define  ONMS_onms1_ctrl_dummy_15_mask                                           (0x00008000)
#define  ONMS_onms1_ctrl_dummy_14_mask                                           (0x00004000)
#define  ONMS_onms1_ctrl_dummy_13_mask                                           (0x00002000)
#define  ONMS_onms1_ctrl_on1_pixel_encoding_mask                                 (0x00001000)
#define  ONMS_onms1_ctrl_on1_vact_space_threshold_mask                           (0x00000F00)
#define  ONMS_onms1_ctrl_on1_vact_space_meas_en_mask                             (0x00000080)
#define  ONMS_onms1_ctrl_on1_meas_to_sel_mask                                    (0x00000040)
#define  ONMS_onms1_ctrl_on1_sycms_clk_mask                                      (0x00000020)
#define  ONMS_onms1_ctrl_on1_vs_meas_inv_mask                                    (0x00000010)
#define  ONMS_onms1_ctrl_on1_hs_meas_inv_mask                                    (0x00000008)
#define  ONMS_onms1_ctrl_on1_popup_meas_mask                                     (0x00000004)
#define  ONMS_onms1_ctrl_on1_ms_conti_mask                                       (0x00000002)
#define  ONMS_onms1_ctrl_on1_start_ms_mask                                       (0x00000001)
#define  ONMS_onms1_ctrl_on1_4k2k_mode(data)                                     (0xC0000000&((data)<<30))
#define  ONMS_onms1_ctrl_on1_ms_src_sel(data)                                    (0x20000000&((data)<<29))
#define  ONMS_onms1_ctrl_on1_blk_2frame_en(data)                                 (0x10000000&((data)<<28))
#define  ONMS_onms1_ctrl_on1_pixel_get_en(data)                                  (0x08000000&((data)<<27))
#define  ONMS_onms1_ctrl_on1_pixel_get_sel(data)                                 (0x06000000&((data)<<25))
#define  ONMS_onms1_ctrl_on1_progressive(data)                                   (0x01000000&((data)<<24))
#define  ONMS_onms1_ctrl_on1_vtotal_max_delta(data)                              (0x00F00000&((data)<<20))
#define  ONMS_onms1_ctrl_on1_htotal_max_delta(data)                              (0x000F0000&((data)<<16))
#define  ONMS_onms1_ctrl_dummy_15(data)                                          (0x00008000&((data)<<15))
#define  ONMS_onms1_ctrl_dummy_14(data)                                          (0x00004000&((data)<<14))
#define  ONMS_onms1_ctrl_dummy_13(data)                                          (0x00002000&((data)<<13))
#define  ONMS_onms1_ctrl_on1_pixel_encoding(data)                                (0x00001000&((data)<<12))
#define  ONMS_onms1_ctrl_on1_vact_space_threshold(data)                          (0x00000F00&((data)<<8))
#define  ONMS_onms1_ctrl_on1_vact_space_meas_en(data)                            (0x00000080&((data)<<7))
#define  ONMS_onms1_ctrl_on1_meas_to_sel(data)                                   (0x00000040&((data)<<6))
#define  ONMS_onms1_ctrl_on1_sycms_clk(data)                                     (0x00000020&((data)<<5))
#define  ONMS_onms1_ctrl_on1_vs_meas_inv(data)                                   (0x00000010&((data)<<4))
#define  ONMS_onms1_ctrl_on1_hs_meas_inv(data)                                   (0x00000008&((data)<<3))
#define  ONMS_onms1_ctrl_on1_popup_meas(data)                                    (0x00000004&((data)<<2))
#define  ONMS_onms1_ctrl_on1_ms_conti(data)                                      (0x00000002&((data)<<1))
#define  ONMS_onms1_ctrl_on1_start_ms(data)                                      (0x00000001&(data))
#define  ONMS_onms1_ctrl_get_on1_4k2k_mode(data)                                 ((0xC0000000&(data))>>30)
#define  ONMS_onms1_ctrl_get_on1_ms_src_sel(data)                                ((0x20000000&(data))>>29)
#define  ONMS_onms1_ctrl_get_on1_blk_2frame_en(data)                             ((0x10000000&(data))>>28)
#define  ONMS_onms1_ctrl_get_on1_pixel_get_en(data)                              ((0x08000000&(data))>>27)
#define  ONMS_onms1_ctrl_get_on1_pixel_get_sel(data)                             ((0x06000000&(data))>>25)
#define  ONMS_onms1_ctrl_get_on1_progressive(data)                               ((0x01000000&(data))>>24)
#define  ONMS_onms1_ctrl_get_on1_vtotal_max_delta(data)                          ((0x00F00000&(data))>>20)
#define  ONMS_onms1_ctrl_get_on1_htotal_max_delta(data)                          ((0x000F0000&(data))>>16)
#define  ONMS_onms1_ctrl_get_dummy_15(data)                                      ((0x00008000&(data))>>15)
#define  ONMS_onms1_ctrl_get_dummy_14(data)                                      ((0x00004000&(data))>>14)
#define  ONMS_onms1_ctrl_get_dummy_13(data)                                      ((0x00002000&(data))>>13)
#define  ONMS_onms1_ctrl_get_on1_pixel_encoding(data)                            ((0x00001000&(data))>>12)
#define  ONMS_onms1_ctrl_get_on1_vact_space_threshold(data)                      ((0x00000F00&(data))>>8)
#define  ONMS_onms1_ctrl_get_on1_vact_space_meas_en(data)                        ((0x00000080&(data))>>7)
#define  ONMS_onms1_ctrl_get_on1_meas_to_sel(data)                               ((0x00000040&(data))>>6)
#define  ONMS_onms1_ctrl_get_on1_sycms_clk(data)                                 ((0x00000020&(data))>>5)
#define  ONMS_onms1_ctrl_get_on1_vs_meas_inv(data)                               ((0x00000010&(data))>>4)
#define  ONMS_onms1_ctrl_get_on1_hs_meas_inv(data)                               ((0x00000008&(data))>>3)
#define  ONMS_onms1_ctrl_get_on1_popup_meas(data)                                ((0x00000004&(data))>>2)
#define  ONMS_onms1_ctrl_get_on1_ms_conti(data)                                  ((0x00000002&(data))>>1)
#define  ONMS_onms1_ctrl_get_on1_start_ms(data)                                  (0x00000001&(data))

#define  ONMS_onms1_blank_pixel_value_get_0                                      0x18021204
#define  ONMS_onms1_blank_pixel_value_get_0_reg_addr                             "0xB8021204"
#define  ONMS_onms1_blank_pixel_value_get_0_reg                                  0xB8021204
#define  ONMS_onms1_blank_pixel_value_get_0_inst_addr                            "0x0001"
#define  set_ONMS_onms1_blank_pixel_value_get_0_reg(data)                        (*((volatile unsigned int*)ONMS_onms1_blank_pixel_value_get_0_reg)=data)
#define  get_ONMS_onms1_blank_pixel_value_get_0_reg                              (*((volatile unsigned int*)ONMS_onms1_blank_pixel_value_get_0_reg))
#define  ONMS_onms1_blank_pixel_value_get_0_on1_pixel_ok_shift                   (24)
#define  ONMS_onms1_blank_pixel_value_get_0_on1_get_r_value_shift                (12)
#define  ONMS_onms1_blank_pixel_value_get_0_on1_get_g_value_shift                (0)
#define  ONMS_onms1_blank_pixel_value_get_0_on1_pixel_ok_mask                    (0x01000000)
#define  ONMS_onms1_blank_pixel_value_get_0_on1_get_r_value_mask                 (0x00FFF000)
#define  ONMS_onms1_blank_pixel_value_get_0_on1_get_g_value_mask                 (0x00000FFF)
#define  ONMS_onms1_blank_pixel_value_get_0_on1_pixel_ok(data)                   (0x01000000&((data)<<24))
#define  ONMS_onms1_blank_pixel_value_get_0_on1_get_r_value(data)                (0x00FFF000&((data)<<12))
#define  ONMS_onms1_blank_pixel_value_get_0_on1_get_g_value(data)                (0x00000FFF&(data))
#define  ONMS_onms1_blank_pixel_value_get_0_get_on1_pixel_ok(data)               ((0x01000000&(data))>>24)
#define  ONMS_onms1_blank_pixel_value_get_0_get_on1_get_r_value(data)            ((0x00FFF000&(data))>>12)
#define  ONMS_onms1_blank_pixel_value_get_0_get_on1_get_g_value(data)            (0x00000FFF&(data))

#define  ONMS_onms1_blank_pixel_value_get_1                                      0x18021208
#define  ONMS_onms1_blank_pixel_value_get_1_reg_addr                             "0xB8021208"
#define  ONMS_onms1_blank_pixel_value_get_1_reg                                  0xB8021208
#define  ONMS_onms1_blank_pixel_value_get_1_inst_addr                            "0x0002"
#define  set_ONMS_onms1_blank_pixel_value_get_1_reg(data)                        (*((volatile unsigned int*)ONMS_onms1_blank_pixel_value_get_1_reg)=data)
#define  get_ONMS_onms1_blank_pixel_value_get_1_reg                              (*((volatile unsigned int*)ONMS_onms1_blank_pixel_value_get_1_reg))
#define  ONMS_onms1_blank_pixel_value_get_1_on1_get_b_value_shift                (0)
#define  ONMS_onms1_blank_pixel_value_get_1_on1_get_b_value_mask                 (0x00000FFF)
#define  ONMS_onms1_blank_pixel_value_get_1_on1_get_b_value(data)                (0x00000FFF&(data))
#define  ONMS_onms1_blank_pixel_value_get_1_get_on1_get_b_value(data)            (0x00000FFF&(data))

#define  ONMS_onms1_blank_pixel_value_0                                          0x1802120C
#define  ONMS_onms1_blank_pixel_value_0_reg_addr                                 "0xB802120C"
#define  ONMS_onms1_blank_pixel_value_0_reg                                      0xB802120C
#define  ONMS_onms1_blank_pixel_value_0_inst_addr                                "0x0003"
#define  set_ONMS_onms1_blank_pixel_value_0_reg(data)                            (*((volatile unsigned int*)ONMS_onms1_blank_pixel_value_0_reg)=data)
#define  get_ONMS_onms1_blank_pixel_value_0_reg                                  (*((volatile unsigned int*)ONMS_onms1_blank_pixel_value_0_reg))
#define  ONMS_onms1_blank_pixel_value_0_on1_active_r_value_shift                 (12)
#define  ONMS_onms1_blank_pixel_value_0_on1_active_g_value_shift                 (0)
#define  ONMS_onms1_blank_pixel_value_0_on1_active_r_value_mask                  (0x00FFF000)
#define  ONMS_onms1_blank_pixel_value_0_on1_active_g_value_mask                  (0x00000FFF)
#define  ONMS_onms1_blank_pixel_value_0_on1_active_r_value(data)                 (0x00FFF000&((data)<<12))
#define  ONMS_onms1_blank_pixel_value_0_on1_active_g_value(data)                 (0x00000FFF&(data))
#define  ONMS_onms1_blank_pixel_value_0_get_on1_active_r_value(data)             ((0x00FFF000&(data))>>12)
#define  ONMS_onms1_blank_pixel_value_0_get_on1_active_g_value(data)             (0x00000FFF&(data))

#define  ONMS_onms1_blank_pixel_value_1                                          0x18021210
#define  ONMS_onms1_blank_pixel_value_1_reg_addr                                 "0xB8021210"
#define  ONMS_onms1_blank_pixel_value_1_reg                                      0xB8021210
#define  ONMS_onms1_blank_pixel_value_1_inst_addr                                "0x0004"
#define  set_ONMS_onms1_blank_pixel_value_1_reg(data)                            (*((volatile unsigned int*)ONMS_onms1_blank_pixel_value_1_reg)=data)
#define  get_ONMS_onms1_blank_pixel_value_1_reg                                  (*((volatile unsigned int*)ONMS_onms1_blank_pixel_value_1_reg))
#define  ONMS_onms1_blank_pixel_value_1_on1_active_b_value_shift                 (0)
#define  ONMS_onms1_blank_pixel_value_1_on1_active_b_value_mask                  (0x00000FFF)
#define  ONMS_onms1_blank_pixel_value_1_on1_active_b_value(data)                 (0x00000FFF&(data))
#define  ONMS_onms1_blank_pixel_value_1_get_on1_active_b_value(data)             (0x00000FFF&(data))

#define  ONMS_onms1_fp_vact12                                                    0x18021214
#define  ONMS_onms1_fp_vact12_reg_addr                                           "0xB8021214"
#define  ONMS_onms1_fp_vact12_reg                                                0xB8021214
#define  ONMS_onms1_fp_vact12_inst_addr                                          "0x0005"
#define  set_ONMS_onms1_fp_vact12_reg(data)                                      (*((volatile unsigned int*)ONMS_onms1_fp_vact12_reg)=data)
#define  get_ONMS_onms1_fp_vact12_reg                                            (*((volatile unsigned int*)ONMS_onms1_fp_vact12_reg))
#define  ONMS_onms1_fp_vact12_on1_vact2_shift                                    (16)
#define  ONMS_onms1_fp_vact12_on1_vact1_shift                                    (0)
#define  ONMS_onms1_fp_vact12_on1_vact2_mask                                     (0x07FF0000)
#define  ONMS_onms1_fp_vact12_on1_vact1_mask                                     (0x000007FF)
#define  ONMS_onms1_fp_vact12_on1_vact2(data)                                    (0x07FF0000&((data)<<16))
#define  ONMS_onms1_fp_vact12_on1_vact1(data)                                    (0x000007FF&(data))
#define  ONMS_onms1_fp_vact12_get_on1_vact2(data)                                ((0x07FF0000&(data))>>16)
#define  ONMS_onms1_fp_vact12_get_on1_vact1(data)                                (0x000007FF&(data))

#define  ONMS_onms1_fp_vact34                                                    0x18021218
#define  ONMS_onms1_fp_vact34_reg_addr                                           "0xB8021218"
#define  ONMS_onms1_fp_vact34_reg                                                0xB8021218
#define  ONMS_onms1_fp_vact34_inst_addr                                          "0x0006"
#define  set_ONMS_onms1_fp_vact34_reg(data)                                      (*((volatile unsigned int*)ONMS_onms1_fp_vact34_reg)=data)
#define  get_ONMS_onms1_fp_vact34_reg                                            (*((volatile unsigned int*)ONMS_onms1_fp_vact34_reg))
#define  ONMS_onms1_fp_vact34_on1_vact4_shift                                    (16)
#define  ONMS_onms1_fp_vact34_on1_vact3_shift                                    (0)
#define  ONMS_onms1_fp_vact34_on1_vact4_mask                                     (0x07FF0000)
#define  ONMS_onms1_fp_vact34_on1_vact3_mask                                     (0x000007FF)
#define  ONMS_onms1_fp_vact34_on1_vact4(data)                                    (0x07FF0000&((data)<<16))
#define  ONMS_onms1_fp_vact34_on1_vact3(data)                                    (0x000007FF&(data))
#define  ONMS_onms1_fp_vact34_get_on1_vact4(data)                                ((0x07FF0000&(data))>>16)
#define  ONMS_onms1_fp_vact34_get_on1_vact3(data)                                (0x000007FF&(data))

#define  ONMS_onms1_fp_vact_space                                                0x1802121C
#define  ONMS_onms1_fp_vact_space_reg_addr                                       "0xB802121C"
#define  ONMS_onms1_fp_vact_space_reg                                            0xB802121C
#define  ONMS_onms1_fp_vact_space_inst_addr                                      "0x0007"
#define  set_ONMS_onms1_fp_vact_space_reg(data)                                  (*((volatile unsigned int*)ONMS_onms1_fp_vact_space_reg)=data)
#define  get_ONMS_onms1_fp_vact_space_reg                                        (*((volatile unsigned int*)ONMS_onms1_fp_vact_space_reg))
#define  ONMS_onms1_fp_vact_space_on1_fp_vact_space1_shift                       (20)
#define  ONMS_onms1_fp_vact_space_on1_fp_vact_space2_shift                       (10)
#define  ONMS_onms1_fp_vact_space_on1_fp_vact_space3_shift                       (0)
#define  ONMS_onms1_fp_vact_space_on1_fp_vact_space1_mask                        (0x3FF00000)
#define  ONMS_onms1_fp_vact_space_on1_fp_vact_space2_mask                        (0x000FFC00)
#define  ONMS_onms1_fp_vact_space_on1_fp_vact_space3_mask                        (0x000003FF)
#define  ONMS_onms1_fp_vact_space_on1_fp_vact_space1(data)                       (0x3FF00000&((data)<<20))
#define  ONMS_onms1_fp_vact_space_on1_fp_vact_space2(data)                       (0x000FFC00&((data)<<10))
#define  ONMS_onms1_fp_vact_space_on1_fp_vact_space3(data)                       (0x000003FF&(data))
#define  ONMS_onms1_fp_vact_space_get_on1_fp_vact_space1(data)                   ((0x3FF00000&(data))>>20)
#define  ONMS_onms1_fp_vact_space_get_on1_fp_vact_space2(data)                   ((0x000FFC00&(data))>>10)
#define  ONMS_onms1_fp_vact_space_get_on1_fp_vact_space3(data)                   (0x000003FF&(data))

#define  ONMS_onms1_blank_line                                                   0x18021220
#define  ONMS_onms1_blank_line_reg_addr                                          "0xB8021220"
#define  ONMS_onms1_blank_line_reg                                               0xB8021220
#define  ONMS_onms1_blank_line_inst_addr                                         "0x0008"
#define  set_ONMS_onms1_blank_line_reg(data)                                     (*((volatile unsigned int*)ONMS_onms1_blank_line_reg)=data)
#define  get_ONMS_onms1_blank_line_reg                                           (*((volatile unsigned int*)ONMS_onms1_blank_line_reg))
#define  ONMS_onms1_blank_line_on1_r_blank_line_start_shift                      (16)
#define  ONMS_onms1_blank_line_on1_l_blank_line_end_shift                        (0)
#define  ONMS_onms1_blank_line_on1_r_blank_line_start_mask                       (0x07FF0000)
#define  ONMS_onms1_blank_line_on1_l_blank_line_end_mask                         (0x000007FF)
#define  ONMS_onms1_blank_line_on1_r_blank_line_start(data)                      (0x07FF0000&((data)<<16))
#define  ONMS_onms1_blank_line_on1_l_blank_line_end(data)                        (0x000007FF&(data))
#define  ONMS_onms1_blank_line_get_on1_r_blank_line_start(data)                  ((0x07FF0000&(data))>>16)
#define  ONMS_onms1_blank_line_get_on1_l_blank_line_end(data)                    (0x000007FF&(data))

#define  ONMS_onms1_active_space1_line_number                                    0x18021224
#define  ONMS_onms1_active_space1_line_number_reg_addr                           "0xB8021224"
#define  ONMS_onms1_active_space1_line_number_reg                                0xB8021224
#define  ONMS_onms1_active_space1_line_number_inst_addr                          "0x0009"
#define  set_ONMS_onms1_active_space1_line_number_reg(data)                      (*((volatile unsigned int*)ONMS_onms1_active_space1_line_number_reg)=data)
#define  get_ONMS_onms1_active_space1_line_number_reg                            (*((volatile unsigned int*)ONMS_onms1_active_space1_line_number_reg))
#define  ONMS_onms1_active_space1_line_number_on1_vact_space1_end_shift          (16)
#define  ONMS_onms1_active_space1_line_number_on1_vact_space1_start_shift        (0)
#define  ONMS_onms1_active_space1_line_number_on1_vact_space1_end_mask           (0x03FF0000)
#define  ONMS_onms1_active_space1_line_number_on1_vact_space1_start_mask         (0x000003FF)
#define  ONMS_onms1_active_space1_line_number_on1_vact_space1_end(data)          (0x03FF0000&((data)<<16))
#define  ONMS_onms1_active_space1_line_number_on1_vact_space1_start(data)        (0x000003FF&(data))
#define  ONMS_onms1_active_space1_line_number_get_on1_vact_space1_end(data)      ((0x03FF0000&(data))>>16)
#define  ONMS_onms1_active_space1_line_number_get_on1_vact_space1_start(data)    (0x000003FF&(data))

#define  ONMS_onms1_active_space2_line_number                                    0x18021228
#define  ONMS_onms1_active_space2_line_number_reg_addr                           "0xB8021228"
#define  ONMS_onms1_active_space2_line_number_reg                                0xB8021228
#define  ONMS_onms1_active_space2_line_number_inst_addr                          "0x000A"
#define  set_ONMS_onms1_active_space2_line_number_reg(data)                      (*((volatile unsigned int*)ONMS_onms1_active_space2_line_number_reg)=data)
#define  get_ONMS_onms1_active_space2_line_number_reg                            (*((volatile unsigned int*)ONMS_onms1_active_space2_line_number_reg))
#define  ONMS_onms1_active_space2_line_number_on1_vact_space2_end_shift          (16)
#define  ONMS_onms1_active_space2_line_number_on1_vact_space2_start_shift        (0)
#define  ONMS_onms1_active_space2_line_number_on1_vact_space2_end_mask           (0x03FF0000)
#define  ONMS_onms1_active_space2_line_number_on1_vact_space2_start_mask         (0x000003FF)
#define  ONMS_onms1_active_space2_line_number_on1_vact_space2_end(data)          (0x03FF0000&((data)<<16))
#define  ONMS_onms1_active_space2_line_number_on1_vact_space2_start(data)        (0x000003FF&(data))
#define  ONMS_onms1_active_space2_line_number_get_on1_vact_space2_end(data)      ((0x03FF0000&(data))>>16)
#define  ONMS_onms1_active_space2_line_number_get_on1_vact_space2_start(data)    (0x000003FF&(data))

#define  ONMS_onms1_active_space3_line_number                                    0x1802122C
#define  ONMS_onms1_active_space3_line_number_reg_addr                           "0xB802122C"
#define  ONMS_onms1_active_space3_line_number_reg                                0xB802122C
#define  ONMS_onms1_active_space3_line_number_inst_addr                          "0x000B"
#define  set_ONMS_onms1_active_space3_line_number_reg(data)                      (*((volatile unsigned int*)ONMS_onms1_active_space3_line_number_reg)=data)
#define  get_ONMS_onms1_active_space3_line_number_reg                            (*((volatile unsigned int*)ONMS_onms1_active_space3_line_number_reg))
#define  ONMS_onms1_active_space3_line_number_on1_vact_space3_end_shift          (16)
#define  ONMS_onms1_active_space3_line_number_on1_vact_space3_start_shift        (0)
#define  ONMS_onms1_active_space3_line_number_on1_vact_space3_end_mask           (0x03FF0000)
#define  ONMS_onms1_active_space3_line_number_on1_vact_space3_start_mask         (0x000003FF)
#define  ONMS_onms1_active_space3_line_number_on1_vact_space3_end(data)          (0x03FF0000&((data)<<16))
#define  ONMS_onms1_active_space3_line_number_on1_vact_space3_start(data)        (0x000003FF&(data))
#define  ONMS_onms1_active_space3_line_number_get_on1_vact_space3_end(data)      ((0x03FF0000&(data))>>16)
#define  ONMS_onms1_active_space3_line_number_get_on1_vact_space3_start(data)    (0x000003FF&(data))

#define  ONMS_onms1_vs_period                                                    0x18021230
#define  ONMS_onms1_vs_period_reg_addr                                           "0xB8021230"
#define  ONMS_onms1_vs_period_reg                                                0xB8021230
#define  ONMS_onms1_vs_period_inst_addr                                          "0x000C"
#define  set_ONMS_onms1_vs_period_reg(data)                                      (*((volatile unsigned int*)ONMS_onms1_vs_period_reg)=data)
#define  get_ONMS_onms1_vs_period_reg                                            (*((volatile unsigned int*)ONMS_onms1_vs_period_reg))
#define  ONMS_onms1_vs_period_on1_vtotalde_shift                                 (16)
#define  ONMS_onms1_vs_period_on1_vtotal_shift                                   (0)
#define  ONMS_onms1_vs_period_on1_vtotalde_mask                                  (0x1FFF0000)
#define  ONMS_onms1_vs_period_on1_vtotal_mask                                    (0x00003FFF)
#define  ONMS_onms1_vs_period_on1_vtotalde(data)                                 (0x1FFF0000&((data)<<16))
#define  ONMS_onms1_vs_period_on1_vtotal(data)                                   (0x00003FFF&(data))
#define  ONMS_onms1_vs_period_get_on1_vtotalde(data)                             ((0x1FFF0000&(data))>>16)
#define  ONMS_onms1_vs_period_get_on1_vtotal(data)                               (0x00003FFF&(data))

#define  ONMS_onms1_vshs_high_period                                             0x18021234
#define  ONMS_onms1_vshs_high_period_reg_addr                                    "0xB8021234"
#define  ONMS_onms1_vshs_high_period_reg                                         0xB8021234
#define  ONMS_onms1_vshs_high_period_inst_addr                                   "0x000D"
#define  set_ONMS_onms1_vshs_high_period_reg(data)                               (*((volatile unsigned int*)ONMS_onms1_vshs_high_period_reg)=data)
#define  get_ONMS_onms1_vshs_high_period_reg                                     (*((volatile unsigned int*)ONMS_onms1_vshs_high_period_reg))
#define  ONMS_onms1_vshs_high_period_on1_vs_high_period_shift                    (16)
#define  ONMS_onms1_vshs_high_period_on1_hs_high_period_shift                    (0)
#define  ONMS_onms1_vshs_high_period_on1_vs_high_period_mask                     (0x0FFF0000)
#define  ONMS_onms1_vshs_high_period_on1_hs_high_period_mask                     (0x00003FFF)
#define  ONMS_onms1_vshs_high_period_on1_vs_high_period(data)                    (0x0FFF0000&((data)<<16))
#define  ONMS_onms1_vshs_high_period_on1_hs_high_period(data)                    (0x00003FFF&(data))
#define  ONMS_onms1_vshs_high_period_get_on1_vs_high_period(data)                ((0x0FFF0000&(data))>>16)
#define  ONMS_onms1_vshs_high_period_get_on1_hs_high_period(data)                (0x00003FFF&(data))

#define  ONMS_onms1_hs_period                                                    0x18021238
#define  ONMS_onms1_hs_period_reg_addr                                           "0xB8021238"
#define  ONMS_onms1_hs_period_reg                                                0xB8021238
#define  ONMS_onms1_hs_period_inst_addr                                          "0x000E"
#define  set_ONMS_onms1_hs_period_reg(data)                                      (*((volatile unsigned int*)ONMS_onms1_hs_period_reg)=data)
#define  get_ONMS_onms1_hs_period_reg                                            (*((volatile unsigned int*)ONMS_onms1_hs_period_reg))
#define  ONMS_onms1_hs_period_on1_htotal_h12b_shift                              (4)
#define  ONMS_onms1_hs_period_on1_htotal_f4b_shift                               (0)
#define  ONMS_onms1_hs_period_on1_htotal_h12b_mask                               (0x0003FFF0)
#define  ONMS_onms1_hs_period_on1_htotal_f4b_mask                                (0x0000000F)
#define  ONMS_onms1_hs_period_on1_htotal_h12b(data)                              (0x0003FFF0&((data)<<4))
#define  ONMS_onms1_hs_period_on1_htotal_f4b(data)                               (0x0000000F&(data))
#define  ONMS_onms1_hs_period_get_on1_htotal_h12b(data)                          ((0x0003FFF0&(data))>>4)
#define  ONMS_onms1_hs_period_get_on1_htotal_f4b(data)                           (0x0000000F&(data))

#define  ONMS_onms1_vact_sta                                                     0x1802123C
#define  ONMS_onms1_vact_sta_reg_addr                                            "0xB802123C"
#define  ONMS_onms1_vact_sta_reg                                                 0xB802123C
#define  ONMS_onms1_vact_sta_inst_addr                                           "0x000F"
#define  set_ONMS_onms1_vact_sta_reg(data)                                       (*((volatile unsigned int*)ONMS_onms1_vact_sta_reg)=data)
#define  get_ONMS_onms1_vact_sta_reg                                             (*((volatile unsigned int*)ONMS_onms1_vact_sta_reg))
#define  ONMS_onms1_vact_sta_on1_vblank_len_shift                                (16)
#define  ONMS_onms1_vact_sta_on1_vact_start_shift                                (0)
#define  ONMS_onms1_vact_sta_on1_vblank_len_mask                                 (0x00FF0000)
#define  ONMS_onms1_vact_sta_on1_vact_start_mask                                 (0x00000FFF)
#define  ONMS_onms1_vact_sta_on1_vblank_len(data)                                (0x00FF0000&((data)<<16))
#define  ONMS_onms1_vact_sta_on1_vact_start(data)                                (0x00000FFF&(data))
#define  ONMS_onms1_vact_sta_get_on1_vblank_len(data)                            ((0x00FF0000&(data))>>16)
#define  ONMS_onms1_vact_sta_get_on1_vact_start(data)                            (0x00000FFF&(data))

#define  ONMS_onms1_hact_sta                                                     0x18021240
#define  ONMS_onms1_hact_sta_reg_addr                                            "0xB8021240"
#define  ONMS_onms1_hact_sta_reg                                                 0xB8021240
#define  ONMS_onms1_hact_sta_inst_addr                                           "0x0010"
#define  set_ONMS_onms1_hact_sta_reg(data)                                       (*((volatile unsigned int*)ONMS_onms1_hact_sta_reg)=data)
#define  get_ONMS_onms1_hact_sta_reg                                             (*((volatile unsigned int*)ONMS_onms1_hact_sta_reg))
#define  ONMS_onms1_hact_sta_on1_hact_start_shift                                (0)
#define  ONMS_onms1_hact_sta_on1_hact_start_mask                                 (0x00003FFF)
#define  ONMS_onms1_hact_sta_on1_hact_start(data)                                (0x00003FFF&(data))
#define  ONMS_onms1_hact_sta_get_on1_hact_start(data)                            (0x00003FFF&(data))

#define  ONMS_onms1_hact                                                         0x18021244
#define  ONMS_onms1_hact_reg_addr                                                "0xB8021244"
#define  ONMS_onms1_hact_reg                                                     0xB8021244
#define  ONMS_onms1_hact_inst_addr                                               "0x0011"
#define  set_ONMS_onms1_hact_reg(data)                                           (*((volatile unsigned int*)ONMS_onms1_hact_reg)=data)
#define  get_ONMS_onms1_hact_reg                                                 (*((volatile unsigned int*)ONMS_onms1_hact_reg))
#define  ONMS_onms1_hact_on1_hact_shift                                          (4)
#define  ONMS_onms1_hact_on1_hact_fract_shift                                    (0)
#define  ONMS_onms1_hact_on1_hact_mask                                           (0x0003FFF0)
#define  ONMS_onms1_hact_on1_hact_fract_mask                                     (0x0000000F)
#define  ONMS_onms1_hact_on1_hact(data)                                          (0x0003FFF0&((data)<<4))
#define  ONMS_onms1_hact_on1_hact_fract(data)                                    (0x0000000F&(data))
#define  ONMS_onms1_hact_get_on1_hact(data)                                      ((0x0003FFF0&(data))>>4)
#define  ONMS_onms1_hact_get_on1_hact_fract(data)                                (0x0000000F&(data))

#define  ONMS_onms1_l_flag_period                                                0x18021248
#define  ONMS_onms1_l_flag_period_reg_addr                                       "0xB8021248"
#define  ONMS_onms1_l_flag_period_reg                                            0xB8021248
#define  ONMS_onms1_l_flag_period_inst_addr                                      "0x0012"
#define  set_ONMS_onms1_l_flag_period_reg(data)                                  (*((volatile unsigned int*)ONMS_onms1_l_flag_period_reg)=data)
#define  get_ONMS_onms1_l_flag_period_reg                                        (*((volatile unsigned int*)ONMS_onms1_l_flag_period_reg))
#define  ONMS_onms1_l_flag_period_on1_ltotal_shift                               (0)
#define  ONMS_onms1_l_flag_period_on1_ltotal_mask                                (0x00FFFFFF)
#define  ONMS_onms1_l_flag_period_on1_ltotal(data)                               (0x00FFFFFF&(data))
#define  ONMS_onms1_l_flag_period_get_on1_ltotal(data)                           (0x00FFFFFF&(data))

#define  ONMS_onms1_l_flag_high_period                                           0x1802124C
#define  ONMS_onms1_l_flag_high_period_reg_addr                                  "0xB802124C"
#define  ONMS_onms1_l_flag_high_period_reg                                       0xB802124C
#define  ONMS_onms1_l_flag_high_period_inst_addr                                 "0x0013"
#define  set_ONMS_onms1_l_flag_high_period_reg(data)                             (*((volatile unsigned int*)ONMS_onms1_l_flag_high_period_reg)=data)
#define  get_ONMS_onms1_l_flag_high_period_reg                                   (*((volatile unsigned int*)ONMS_onms1_l_flag_high_period_reg))
#define  ONMS_onms1_l_flag_high_period_on1_l_flag_high_period_shift              (0)
#define  ONMS_onms1_l_flag_high_period_on1_l_flag_high_period_mask               (0x00FFFFFF)
#define  ONMS_onms1_l_flag_high_period_on1_l_flag_high_period(data)              (0x00FFFFFF&(data))
#define  ONMS_onms1_l_flag_high_period_get_on1_l_flag_high_period(data)          (0x00FFFFFF&(data))

#define  ONMS_onms1_field_period                                                 0x18021250
#define  ONMS_onms1_field_period_reg_addr                                        "0xB8021250"
#define  ONMS_onms1_field_period_reg                                             0xB8021250
#define  ONMS_onms1_field_period_inst_addr                                       "0x0014"
#define  set_ONMS_onms1_field_period_reg(data)                                   (*((volatile unsigned int*)ONMS_onms1_field_period_reg)=data)
#define  get_ONMS_onms1_field_period_reg                                         (*((volatile unsigned int*)ONMS_onms1_field_period_reg))
#define  ONMS_onms1_field_period_on1_ftotal_shift                                (0)
#define  ONMS_onms1_field_period_on1_ftotal_mask                                 (0x00FFFFFF)
#define  ONMS_onms1_field_period_on1_ftotal(data)                                (0x00FFFFFF&(data))
#define  ONMS_onms1_field_period_get_on1_ftotal(data)                            (0x00FFFFFF&(data))

#define  ONMS_onms1_field_high_period                                            0x18021254
#define  ONMS_onms1_field_high_period_reg_addr                                   "0xB8021254"
#define  ONMS_onms1_field_high_period_reg                                        0xB8021254
#define  ONMS_onms1_field_high_period_inst_addr                                  "0x0015"
#define  set_ONMS_onms1_field_high_period_reg(data)                              (*((volatile unsigned int*)ONMS_onms1_field_high_period_reg)=data)
#define  get_ONMS_onms1_field_high_period_reg                                    (*((volatile unsigned int*)ONMS_onms1_field_high_period_reg))
#define  ONMS_onms1_field_high_period_on1_field_high_period_shift                (0)
#define  ONMS_onms1_field_high_period_on1_field_high_period_mask                 (0x00FFFFFF)
#define  ONMS_onms1_field_high_period_on1_field_high_period(data)                (0x00FFFFFF&(data))
#define  ONMS_onms1_field_high_period_get_on1_field_high_period(data)            (0x00FFFFFF&(data))

#define  ONMS_onms1_status_2                                                     0x18021258
#define  ONMS_onms1_status_2_reg_addr                                            "0xB8021258"
#define  ONMS_onms1_status_2_reg                                                 0xB8021258
#define  ONMS_onms1_status_2_inst_addr                                           "0x0016"
#define  set_ONMS_onms1_status_2_reg(data)                                       (*((volatile unsigned int*)ONMS_onms1_status_2_reg)=data)
#define  get_ONMS_onms1_status_2_reg                                             (*((volatile unsigned int*)ONMS_onms1_status_2_reg))
#define  ONMS_onms1_status_2_on1_ltotal_chg_shift                                (1)
#define  ONMS_onms1_status_2_on1_ftotal_chg_shift                                (0)
#define  ONMS_onms1_status_2_on1_ltotal_chg_mask                                 (0x00000002)
#define  ONMS_onms1_status_2_on1_ftotal_chg_mask                                 (0x00000001)
#define  ONMS_onms1_status_2_on1_ltotal_chg(data)                                (0x00000002&((data)<<1))
#define  ONMS_onms1_status_2_on1_ftotal_chg(data)                                (0x00000001&(data))
#define  ONMS_onms1_status_2_get_on1_ltotal_chg(data)                            ((0x00000002&(data))>>1)
#define  ONMS_onms1_status_2_get_on1_ftotal_chg(data)                            (0x00000001&(data))

#define  ONMS_onms1_hsync_meas_ctrl                                              0x1802125C
#define  ONMS_onms1_hsync_meas_ctrl_reg_addr                                     "0xB802125C"
#define  ONMS_onms1_hsync_meas_ctrl_reg                                          0xB802125C
#define  ONMS_onms1_hsync_meas_ctrl_inst_addr                                    "0x0017"
#define  set_ONMS_onms1_hsync_meas_ctrl_reg(data)                                (*((volatile unsigned int*)ONMS_onms1_hsync_meas_ctrl_reg)=data)
#define  get_ONMS_onms1_hsync_meas_ctrl_reg                                      (*((volatile unsigned int*)ONMS_onms1_hsync_meas_ctrl_reg))
#define  ONMS_onms1_hsync_meas_ctrl_on1_htotal_max_delta_new_shift               (24)
#define  ONMS_onms1_hsync_meas_ctrl_on1_average_line_shift                       (16)
#define  ONMS_onms1_hsync_meas_ctrl_on1_target_measure_shift                     (0)
#define  ONMS_onms1_hsync_meas_ctrl_on1_htotal_max_delta_new_mask                (0x7F000000)
#define  ONMS_onms1_hsync_meas_ctrl_on1_average_line_mask                        (0x000F0000)
#define  ONMS_onms1_hsync_meas_ctrl_on1_target_measure_mask                      (0x00003FFF)
#define  ONMS_onms1_hsync_meas_ctrl_on1_htotal_max_delta_new(data)               (0x7F000000&((data)<<24))
#define  ONMS_onms1_hsync_meas_ctrl_on1_average_line(data)                       (0x000F0000&((data)<<16))
#define  ONMS_onms1_hsync_meas_ctrl_on1_target_measure(data)                     (0x00003FFF&(data))
#define  ONMS_onms1_hsync_meas_ctrl_get_on1_htotal_max_delta_new(data)           ((0x7F000000&(data))>>24)
#define  ONMS_onms1_hsync_meas_ctrl_get_on1_average_line(data)                   ((0x000F0000&(data))>>16)
#define  ONMS_onms1_hsync_meas_ctrl_get_on1_target_measure(data)                 (0x00003FFF&(data))

#define  ONMS_onms1_hsync_meas_ctrl_2                                            0x18021260
#define  ONMS_onms1_hsync_meas_ctrl_2_reg_addr                                   "0xB8021260"
#define  ONMS_onms1_hsync_meas_ctrl_2_reg                                        0xB8021260
#define  ONMS_onms1_hsync_meas_ctrl_2_inst_addr                                  "0x0018"
#define  set_ONMS_onms1_hsync_meas_ctrl_2_reg(data)                              (*((volatile unsigned int*)ONMS_onms1_hsync_meas_ctrl_2_reg)=data)
#define  get_ONMS_onms1_hsync_meas_ctrl_2_reg                                    (*((volatile unsigned int*)ONMS_onms1_hsync_meas_ctrl_2_reg))
#define  ONMS_onms1_hsync_meas_ctrl_2_on1_vmeas_end_shift                        (16)
#define  ONMS_onms1_hsync_meas_ctrl_2_on1_vmeas_start_shift                      (0)
#define  ONMS_onms1_hsync_meas_ctrl_2_on1_vmeas_end_mask                         (0x0FFF0000)
#define  ONMS_onms1_hsync_meas_ctrl_2_on1_vmeas_start_mask                       (0x00000FFF)
#define  ONMS_onms1_hsync_meas_ctrl_2_on1_vmeas_end(data)                        (0x0FFF0000&((data)<<16))
#define  ONMS_onms1_hsync_meas_ctrl_2_on1_vmeas_start(data)                      (0x00000FFF&(data))
#define  ONMS_onms1_hsync_meas_ctrl_2_get_on1_vmeas_end(data)                    ((0x0FFF0000&(data))>>16)
#define  ONMS_onms1_hsync_meas_ctrl_2_get_on1_vmeas_start(data)                  (0x00000FFF&(data))

#define  ONMS_onms1_hsync_meas_result                                            0x18021264
#define  ONMS_onms1_hsync_meas_result_reg_addr                                   "0xB8021264"
#define  ONMS_onms1_hsync_meas_result_reg                                        0xB8021264
#define  ONMS_onms1_hsync_meas_result_inst_addr                                  "0x0019"
#define  set_ONMS_onms1_hsync_meas_result_reg(data)                              (*((volatile unsigned int*)ONMS_onms1_hsync_meas_result_reg)=data)
#define  get_ONMS_onms1_hsync_meas_result_reg                                    (*((volatile unsigned int*)ONMS_onms1_hsync_meas_result_reg))
#define  ONMS_onms1_hsync_meas_result_on1_hmax_delta_total_shift                 (0)
#define  ONMS_onms1_hsync_meas_result_on1_hmax_delta_total_mask                  (0x00003FFF)
#define  ONMS_onms1_hsync_meas_result_on1_hmax_delta_total(data)                 (0x00003FFF&(data))
#define  ONMS_onms1_hsync_meas_result_get_on1_hmax_delta_total(data)             (0x00003FFF&(data))

#define  ONMS_onms1_status                                                       0x18021268
#define  ONMS_onms1_status_reg_addr                                              "0xB8021268"
#define  ONMS_onms1_status_reg                                                   0xB8021268
#define  ONMS_onms1_status_inst_addr                                             "0x001A"
#define  set_ONMS_onms1_status_reg(data)                                         (*((volatile unsigned int*)ONMS_onms1_status_reg)=data)
#define  get_ONMS_onms1_status_reg                                               (*((volatile unsigned int*)ONMS_onms1_status_reg))
#define  ONMS_onms1_status_on1_hs_meas_over_range_shift                          (21)
#define  ONMS_onms1_status_on1_vs_per_to_long_shift                              (20)
#define  ONMS_onms1_status_on1_vs_pol_out_shift                                  (17)
#define  ONMS_onms1_status_on1_hs_pol_out_shift                                  (16)
#define  ONMS_onms1_status_on1_vs_per_over_range_shift                           (15)
#define  ONMS_onms1_status_on1_hs_per_over_range_shift                           (14)
#define  ONMS_onms1_status_on1_vs_per_timeout_shift                              (13)
#define  ONMS_onms1_status_on1_vs_high_timeout_shift                             (12)
#define  ONMS_onms1_status_on1_vs_per_overflow_shift                             (11)
#define  ONMS_onms1_status_on1_hs_per_overflow_shift                             (10)
#define  ONMS_onms1_status_on1_vs_pol_chg_shift                                  (9)
#define  ONMS_onms1_status_on1_hs_pol_chg_shift                                  (8)
#define  ONMS_onms1_status_on1_vtotalde_chg_shift                                (7)
#define  ONMS_onms1_status_on1_vtotal_chg_shift                                  (6)
#define  ONMS_onms1_status_on1_hact_chg_shift                                    (5)
#define  ONMS_onms1_status_on1_htotal_chg_shift                                  (4)
#define  ONMS_onms1_status_on1_hs_active_pixel_var_shift                         (3)
#define  ONMS_onms1_status_on1_hs_meas_over_range_mask                           (0x00200000)
#define  ONMS_onms1_status_on1_vs_per_to_long_mask                               (0x00100000)
#define  ONMS_onms1_status_on1_vs_pol_out_mask                                   (0x00020000)
#define  ONMS_onms1_status_on1_hs_pol_out_mask                                   (0x00010000)
#define  ONMS_onms1_status_on1_vs_per_over_range_mask                            (0x00008000)
#define  ONMS_onms1_status_on1_hs_per_over_range_mask                            (0x00004000)
#define  ONMS_onms1_status_on1_vs_per_timeout_mask                               (0x00002000)
#define  ONMS_onms1_status_on1_vs_high_timeout_mask                              (0x00001000)
#define  ONMS_onms1_status_on1_vs_per_overflow_mask                              (0x00000800)
#define  ONMS_onms1_status_on1_hs_per_overflow_mask                              (0x00000400)
#define  ONMS_onms1_status_on1_vs_pol_chg_mask                                   (0x00000200)
#define  ONMS_onms1_status_on1_hs_pol_chg_mask                                   (0x00000100)
#define  ONMS_onms1_status_on1_vtotalde_chg_mask                                 (0x00000080)
#define  ONMS_onms1_status_on1_vtotal_chg_mask                                   (0x00000040)
#define  ONMS_onms1_status_on1_hact_chg_mask                                     (0x00000020)
#define  ONMS_onms1_status_on1_htotal_chg_mask                                   (0x00000010)
#define  ONMS_onms1_status_on1_hs_active_pixel_var_mask                          (0x00000008)
#define  ONMS_onms1_status_on1_hs_meas_over_range(data)                          (0x00200000&((data)<<21))
#define  ONMS_onms1_status_on1_vs_per_to_long(data)                              (0x00100000&((data)<<20))
#define  ONMS_onms1_status_on1_vs_pol_out(data)                                  (0x00020000&((data)<<17))
#define  ONMS_onms1_status_on1_hs_pol_out(data)                                  (0x00010000&((data)<<16))
#define  ONMS_onms1_status_on1_vs_per_over_range(data)                           (0x00008000&((data)<<15))
#define  ONMS_onms1_status_on1_hs_per_over_range(data)                           (0x00004000&((data)<<14))
#define  ONMS_onms1_status_on1_vs_per_timeout(data)                              (0x00002000&((data)<<13))
#define  ONMS_onms1_status_on1_vs_high_timeout(data)                             (0x00001000&((data)<<12))
#define  ONMS_onms1_status_on1_vs_per_overflow(data)                             (0x00000800&((data)<<11))
#define  ONMS_onms1_status_on1_hs_per_overflow(data)                             (0x00000400&((data)<<10))
#define  ONMS_onms1_status_on1_vs_pol_chg(data)                                  (0x00000200&((data)<<9))
#define  ONMS_onms1_status_on1_hs_pol_chg(data)                                  (0x00000100&((data)<<8))
#define  ONMS_onms1_status_on1_vtotalde_chg(data)                                (0x00000080&((data)<<7))
#define  ONMS_onms1_status_on1_vtotal_chg(data)                                  (0x00000040&((data)<<6))
#define  ONMS_onms1_status_on1_hact_chg(data)                                    (0x00000020&((data)<<5))
#define  ONMS_onms1_status_on1_htotal_chg(data)                                  (0x00000010&((data)<<4))
#define  ONMS_onms1_status_on1_hs_active_pixel_var(data)                         (0x00000008&((data)<<3))
#define  ONMS_onms1_status_get_on1_hs_meas_over_range(data)                      ((0x00200000&(data))>>21)
#define  ONMS_onms1_status_get_on1_vs_per_to_long(data)                          ((0x00100000&(data))>>20)
#define  ONMS_onms1_status_get_on1_vs_pol_out(data)                              ((0x00020000&(data))>>17)
#define  ONMS_onms1_status_get_on1_hs_pol_out(data)                              ((0x00010000&(data))>>16)
#define  ONMS_onms1_status_get_on1_vs_per_over_range(data)                       ((0x00008000&(data))>>15)
#define  ONMS_onms1_status_get_on1_hs_per_over_range(data)                       ((0x00004000&(data))>>14)
#define  ONMS_onms1_status_get_on1_vs_per_timeout(data)                          ((0x00002000&(data))>>13)
#define  ONMS_onms1_status_get_on1_vs_high_timeout(data)                         ((0x00001000&(data))>>12)
#define  ONMS_onms1_status_get_on1_vs_per_overflow(data)                         ((0x00000800&(data))>>11)
#define  ONMS_onms1_status_get_on1_hs_per_overflow(data)                         ((0x00000400&(data))>>10)
#define  ONMS_onms1_status_get_on1_vs_pol_chg(data)                              ((0x00000200&(data))>>9)
#define  ONMS_onms1_status_get_on1_hs_pol_chg(data)                              ((0x00000100&(data))>>8)
#define  ONMS_onms1_status_get_on1_vtotalde_chg(data)                            ((0x00000080&(data))>>7)
#define  ONMS_onms1_status_get_on1_vtotal_chg(data)                              ((0x00000040&(data))>>6)
#define  ONMS_onms1_status_get_on1_hact_chg(data)                                ((0x00000020&(data))>>5)
#define  ONMS_onms1_status_get_on1_htotal_chg(data)                              ((0x00000010&(data))>>4)
#define  ONMS_onms1_status_get_on1_hs_active_pixel_var(data)                     ((0x00000008&(data))>>3)

#define  ONMS_onms1_watchdog_en                                                  0x1802126C
#define  ONMS_onms1_watchdog_en_reg_addr                                         "0xB802126C"
#define  ONMS_onms1_watchdog_en_reg                                              0xB802126C
#define  ONMS_onms1_watchdog_en_inst_addr                                        "0x001B"
#define  set_ONMS_onms1_watchdog_en_reg(data)                                    (*((volatile unsigned int*)ONMS_onms1_watchdog_en_reg)=data)
#define  get_ONMS_onms1_watchdog_en_reg                                          (*((volatile unsigned int*)ONMS_onms1_watchdog_en_reg))
#define  ONMS_onms1_watchdog_en_on1_wd_to_main_shift                             (31)
#define  ONMS_onms1_watchdog_en_on1_wd_to_sub_shift                              (30)
#define  ONMS_onms1_watchdog_en_on1_wd_hs_meas_over_range_shift                  (21)
#define  ONMS_onms1_watchdog_en_on1_wd_vs_per_over_range_shift                   (15)
#define  ONMS_onms1_watchdog_en_on1_wd_hs_per_over_range_shift                   (14)
#define  ONMS_onms1_watchdog_en_on1_wd_vs_per_timeout_shift                      (13)
#define  ONMS_onms1_watchdog_en_on1_wd_vs_high_timeout_shift                     (12)
#define  ONMS_onms1_watchdog_en_on1_wd_vs_per_overflow_shift                     (11)
#define  ONMS_onms1_watchdog_en_on1_wd_hs_per_overflow_shift                     (10)
#define  ONMS_onms1_watchdog_en_on1_wd_vs_pol_chg_shift                          (9)
#define  ONMS_onms1_watchdog_en_on1_wd_hs_pol_chg_shift                          (8)
#define  ONMS_onms1_watchdog_en_on1_wd_vtotalde_chg_shift                        (7)
#define  ONMS_onms1_watchdog_en_on1_wd_vtotal_chg_shift                          (6)
#define  ONMS_onms1_watchdog_en_on1_wd_hact_chg_shift                            (5)
#define  ONMS_onms1_watchdog_en_on1_wd_htotal_chg_shift                          (4)
#define  ONMS_onms1_watchdog_en_on1_wd_hs_active_pixel_var_shift                 (3)
#define  ONMS_onms1_watchdog_en_on1_wd_to_main_mask                              (0x80000000)
#define  ONMS_onms1_watchdog_en_on1_wd_to_sub_mask                               (0x40000000)
#define  ONMS_onms1_watchdog_en_on1_wd_hs_meas_over_range_mask                   (0x00200000)
#define  ONMS_onms1_watchdog_en_on1_wd_vs_per_over_range_mask                    (0x00008000)
#define  ONMS_onms1_watchdog_en_on1_wd_hs_per_over_range_mask                    (0x00004000)
#define  ONMS_onms1_watchdog_en_on1_wd_vs_per_timeout_mask                       (0x00002000)
#define  ONMS_onms1_watchdog_en_on1_wd_vs_high_timeout_mask                      (0x00001000)
#define  ONMS_onms1_watchdog_en_on1_wd_vs_per_overflow_mask                      (0x00000800)
#define  ONMS_onms1_watchdog_en_on1_wd_hs_per_overflow_mask                      (0x00000400)
#define  ONMS_onms1_watchdog_en_on1_wd_vs_pol_chg_mask                           (0x00000200)
#define  ONMS_onms1_watchdog_en_on1_wd_hs_pol_chg_mask                           (0x00000100)
#define  ONMS_onms1_watchdog_en_on1_wd_vtotalde_chg_mask                         (0x00000080)
#define  ONMS_onms1_watchdog_en_on1_wd_vtotal_chg_mask                           (0x00000040)
#define  ONMS_onms1_watchdog_en_on1_wd_hact_chg_mask                             (0x00000020)
#define  ONMS_onms1_watchdog_en_on1_wd_htotal_chg_mask                           (0x00000010)
#define  ONMS_onms1_watchdog_en_on1_wd_hs_active_pixel_var_mask                  (0x00000008)
#define  ONMS_onms1_watchdog_en_on1_wd_to_main(data)                             (0x80000000&((data)<<31))
#define  ONMS_onms1_watchdog_en_on1_wd_to_sub(data)                              (0x40000000&((data)<<30))
#define  ONMS_onms1_watchdog_en_on1_wd_hs_meas_over_range(data)                  (0x00200000&((data)<<21))
#define  ONMS_onms1_watchdog_en_on1_wd_vs_per_over_range(data)                   (0x00008000&((data)<<15))
#define  ONMS_onms1_watchdog_en_on1_wd_hs_per_over_range(data)                   (0x00004000&((data)<<14))
#define  ONMS_onms1_watchdog_en_on1_wd_vs_per_timeout(data)                      (0x00002000&((data)<<13))
#define  ONMS_onms1_watchdog_en_on1_wd_vs_high_timeout(data)                     (0x00001000&((data)<<12))
#define  ONMS_onms1_watchdog_en_on1_wd_vs_per_overflow(data)                     (0x00000800&((data)<<11))
#define  ONMS_onms1_watchdog_en_on1_wd_hs_per_overflow(data)                     (0x00000400&((data)<<10))
#define  ONMS_onms1_watchdog_en_on1_wd_vs_pol_chg(data)                          (0x00000200&((data)<<9))
#define  ONMS_onms1_watchdog_en_on1_wd_hs_pol_chg(data)                          (0x00000100&((data)<<8))
#define  ONMS_onms1_watchdog_en_on1_wd_vtotalde_chg(data)                        (0x00000080&((data)<<7))
#define  ONMS_onms1_watchdog_en_on1_wd_vtotal_chg(data)                          (0x00000040&((data)<<6))
#define  ONMS_onms1_watchdog_en_on1_wd_hact_chg(data)                            (0x00000020&((data)<<5))
#define  ONMS_onms1_watchdog_en_on1_wd_htotal_chg(data)                          (0x00000010&((data)<<4))
#define  ONMS_onms1_watchdog_en_on1_wd_hs_active_pixel_var(data)                 (0x00000008&((data)<<3))
#define  ONMS_onms1_watchdog_en_get_on1_wd_to_main(data)                         ((0x80000000&(data))>>31)
#define  ONMS_onms1_watchdog_en_get_on1_wd_to_sub(data)                          ((0x40000000&(data))>>30)
#define  ONMS_onms1_watchdog_en_get_on1_wd_hs_meas_over_range(data)              ((0x00200000&(data))>>21)
#define  ONMS_onms1_watchdog_en_get_on1_wd_vs_per_over_range(data)               ((0x00008000&(data))>>15)
#define  ONMS_onms1_watchdog_en_get_on1_wd_hs_per_over_range(data)               ((0x00004000&(data))>>14)
#define  ONMS_onms1_watchdog_en_get_on1_wd_vs_per_timeout(data)                  ((0x00002000&(data))>>13)
#define  ONMS_onms1_watchdog_en_get_on1_wd_vs_high_timeout(data)                 ((0x00001000&(data))>>12)
#define  ONMS_onms1_watchdog_en_get_on1_wd_vs_per_overflow(data)                 ((0x00000800&(data))>>11)
#define  ONMS_onms1_watchdog_en_get_on1_wd_hs_per_overflow(data)                 ((0x00000400&(data))>>10)
#define  ONMS_onms1_watchdog_en_get_on1_wd_vs_pol_chg(data)                      ((0x00000200&(data))>>9)
#define  ONMS_onms1_watchdog_en_get_on1_wd_hs_pol_chg(data)                      ((0x00000100&(data))>>8)
#define  ONMS_onms1_watchdog_en_get_on1_wd_vtotalde_chg(data)                    ((0x00000080&(data))>>7)
#define  ONMS_onms1_watchdog_en_get_on1_wd_vtotal_chg(data)                      ((0x00000040&(data))>>6)
#define  ONMS_onms1_watchdog_en_get_on1_wd_hact_chg(data)                        ((0x00000020&(data))>>5)
#define  ONMS_onms1_watchdog_en_get_on1_wd_htotal_chg(data)                      ((0x00000010&(data))>>4)
#define  ONMS_onms1_watchdog_en_get_on1_wd_hs_active_pixel_var(data)             ((0x00000008&(data))>>3)

#define  ONMS_onms1_interrupt_en                                                 0x18021270
#define  ONMS_onms1_interrupt_en_reg_addr                                        "0xB8021270"
#define  ONMS_onms1_interrupt_en_reg                                             0xB8021270
#define  ONMS_onms1_interrupt_en_inst_addr                                       "0x001C"
#define  set_ONMS_onms1_interrupt_en_reg(data)                                   (*((volatile unsigned int*)ONMS_onms1_interrupt_en_reg)=data)
#define  get_ONMS_onms1_interrupt_en_reg                                         (*((volatile unsigned int*)ONMS_onms1_interrupt_en_reg))
#define  ONMS_onms1_interrupt_en_on1_ie_to_main_shift                            (31)
#define  ONMS_onms1_interrupt_en_on1_ie_hs_meas_over_range_shift                 (21)
#define  ONMS_onms1_interrupt_en_on1_ie_vs_per_over_range_shift                  (15)
#define  ONMS_onms1_interrupt_en_on1_ie_hs_per_over_range_shift                  (14)
#define  ONMS_onms1_interrupt_en_on1_ie_vs_per_timeout_shift                     (13)
#define  ONMS_onms1_interrupt_en_on1_ie_vs_high_timeout_shift                    (12)
#define  ONMS_onms1_interrupt_en_on1_ie_vs_per_overflow_shift                    (11)
#define  ONMS_onms1_interrupt_en_on1_ie_hs_per_overflow_shift                    (10)
#define  ONMS_onms1_interrupt_en_on1_ie_vs_pol_chg_shift                         (9)
#define  ONMS_onms1_interrupt_en_on1_ie_hs_pol_chg_shift                         (8)
#define  ONMS_onms1_interrupt_en_on1_ie_vtotalde_chg_shift                       (7)
#define  ONMS_onms1_interrupt_en_on1_ie_vtotal_chg_shift                         (6)
#define  ONMS_onms1_interrupt_en_on1_ie_hact_chg_shift                           (5)
#define  ONMS_onms1_interrupt_en_on1_ie_htotal_chg_shift                         (4)
#define  ONMS_onms1_interrupt_en_on1_ie_hs_active_pixel_var_shift                (3)
#define  ONMS_onms1_interrupt_en_on1_ie_to_main_mask                             (0x80000000)
#define  ONMS_onms1_interrupt_en_on1_ie_hs_meas_over_range_mask                  (0x00200000)
#define  ONMS_onms1_interrupt_en_on1_ie_vs_per_over_range_mask                   (0x00008000)
#define  ONMS_onms1_interrupt_en_on1_ie_hs_per_over_range_mask                   (0x00004000)
#define  ONMS_onms1_interrupt_en_on1_ie_vs_per_timeout_mask                      (0x00002000)
#define  ONMS_onms1_interrupt_en_on1_ie_vs_high_timeout_mask                     (0x00001000)
#define  ONMS_onms1_interrupt_en_on1_ie_vs_per_overflow_mask                     (0x00000800)
#define  ONMS_onms1_interrupt_en_on1_ie_hs_per_overflow_mask                     (0x00000400)
#define  ONMS_onms1_interrupt_en_on1_ie_vs_pol_chg_mask                          (0x00000200)
#define  ONMS_onms1_interrupt_en_on1_ie_hs_pol_chg_mask                          (0x00000100)
#define  ONMS_onms1_interrupt_en_on1_ie_vtotalde_chg_mask                        (0x00000080)
#define  ONMS_onms1_interrupt_en_on1_ie_vtotal_chg_mask                          (0x00000040)
#define  ONMS_onms1_interrupt_en_on1_ie_hact_chg_mask                            (0x00000020)
#define  ONMS_onms1_interrupt_en_on1_ie_htotal_chg_mask                          (0x00000010)
#define  ONMS_onms1_interrupt_en_on1_ie_hs_active_pixel_var_mask                 (0x00000008)
#define  ONMS_onms1_interrupt_en_on1_ie_to_main(data)                            (0x80000000&((data)<<31))
#define  ONMS_onms1_interrupt_en_on1_ie_hs_meas_over_range(data)                 (0x00200000&((data)<<21))
#define  ONMS_onms1_interrupt_en_on1_ie_vs_per_over_range(data)                  (0x00008000&((data)<<15))
#define  ONMS_onms1_interrupt_en_on1_ie_hs_per_over_range(data)                  (0x00004000&((data)<<14))
#define  ONMS_onms1_interrupt_en_on1_ie_vs_per_timeout(data)                     (0x00002000&((data)<<13))
#define  ONMS_onms1_interrupt_en_on1_ie_vs_high_timeout(data)                    (0x00001000&((data)<<12))
#define  ONMS_onms1_interrupt_en_on1_ie_vs_per_overflow(data)                    (0x00000800&((data)<<11))
#define  ONMS_onms1_interrupt_en_on1_ie_hs_per_overflow(data)                    (0x00000400&((data)<<10))
#define  ONMS_onms1_interrupt_en_on1_ie_vs_pol_chg(data)                         (0x00000200&((data)<<9))
#define  ONMS_onms1_interrupt_en_on1_ie_hs_pol_chg(data)                         (0x00000100&((data)<<8))
#define  ONMS_onms1_interrupt_en_on1_ie_vtotalde_chg(data)                       (0x00000080&((data)<<7))
#define  ONMS_onms1_interrupt_en_on1_ie_vtotal_chg(data)                         (0x00000040&((data)<<6))
#define  ONMS_onms1_interrupt_en_on1_ie_hact_chg(data)                           (0x00000020&((data)<<5))
#define  ONMS_onms1_interrupt_en_on1_ie_htotal_chg(data)                         (0x00000010&((data)<<4))
#define  ONMS_onms1_interrupt_en_on1_ie_hs_active_pixel_var(data)                (0x00000008&((data)<<3))
#define  ONMS_onms1_interrupt_en_get_on1_ie_to_main(data)                        ((0x80000000&(data))>>31)
#define  ONMS_onms1_interrupt_en_get_on1_ie_hs_meas_over_range(data)             ((0x00200000&(data))>>21)
#define  ONMS_onms1_interrupt_en_get_on1_ie_vs_per_over_range(data)              ((0x00008000&(data))>>15)
#define  ONMS_onms1_interrupt_en_get_on1_ie_hs_per_over_range(data)              ((0x00004000&(data))>>14)
#define  ONMS_onms1_interrupt_en_get_on1_ie_vs_per_timeout(data)                 ((0x00002000&(data))>>13)
#define  ONMS_onms1_interrupt_en_get_on1_ie_vs_high_timeout(data)                ((0x00001000&(data))>>12)
#define  ONMS_onms1_interrupt_en_get_on1_ie_vs_per_overflow(data)                ((0x00000800&(data))>>11)
#define  ONMS_onms1_interrupt_en_get_on1_ie_hs_per_overflow(data)                ((0x00000400&(data))>>10)
#define  ONMS_onms1_interrupt_en_get_on1_ie_vs_pol_chg(data)                     ((0x00000200&(data))>>9)
#define  ONMS_onms1_interrupt_en_get_on1_ie_hs_pol_chg(data)                     ((0x00000100&(data))>>8)
#define  ONMS_onms1_interrupt_en_get_on1_ie_vtotalde_chg(data)                   ((0x00000080&(data))>>7)
#define  ONMS_onms1_interrupt_en_get_on1_ie_vtotal_chg(data)                     ((0x00000040&(data))>>6)
#define  ONMS_onms1_interrupt_en_get_on1_ie_hact_chg(data)                       ((0x00000020&(data))>>5)
#define  ONMS_onms1_interrupt_en_get_on1_ie_htotal_chg(data)                     ((0x00000010&(data))>>4)
#define  ONMS_onms1_interrupt_en_get_on1_ie_hs_active_pixel_var(data)            ((0x00000008&(data))>>3)

#define  ONMS_onms2_ctrl                                                         0x18021300
#define  ONMS_onms2_ctrl_reg_addr                                                "0xB8021300"
#define  ONMS_onms2_ctrl_reg                                                     0xB8021300
#define  ONMS_onms2_ctrl_inst_addr                                               "0x001D"
#define  set_ONMS_onms2_ctrl_reg(data)                                           (*((volatile unsigned int*)ONMS_onms2_ctrl_reg)=data)
#define  get_ONMS_onms2_ctrl_reg                                                 (*((volatile unsigned int*)ONMS_onms2_ctrl_reg))
#define  ONMS_onms2_ctrl_on2_4k2k_mode_shift                                     (30)
#define  ONMS_onms2_ctrl_on2_ms_src_sel_shift                                    (29)
#define  ONMS_onms2_ctrl_on2_blk_2frame_en_shift                                 (28)
#define  ONMS_onms2_ctrl_on2_pixel_get_en_shift                                  (27)
#define  ONMS_onms2_ctrl_on2_pixel_get_sel_shift                                 (25)
#define  ONMS_onms2_ctrl_on2_progressive_shift                                   (24)
#define  ONMS_onms2_ctrl_on2_vtotal_max_delta_shift                              (20)
#define  ONMS_onms2_ctrl_on2_htotal_max_delta_shift                              (16)
#define  ONMS_onms2_ctrl_dummy_15_shift                                          (15)
#define  ONMS_onms2_ctrl_dummy_14_shift                                          (14)
#define  ONMS_onms2_ctrl_dummy_13_shift                                          (13)
#define  ONMS_onms2_ctrl_on2_pixel_encoding_shift                                (12)
#define  ONMS_onms2_ctrl_on2_vact_space_threshold_shift                          (8)
#define  ONMS_onms2_ctrl_on2_vact_space_meas_en_shift                            (7)
#define  ONMS_onms2_ctrl_on2_meas_to_sel_shift                                   (6)
#define  ONMS_onms2_ctrl_on2_sycms_clk_shift                                     (5)
#define  ONMS_onms2_ctrl_on2_vs_meas_inv_shift                                   (4)
#define  ONMS_onms2_ctrl_on2_hs_meas_inv_shift                                   (3)
#define  ONMS_onms2_ctrl_on2_popup_meas_shift                                    (2)
#define  ONMS_onms2_ctrl_on2_ms_conti_shift                                      (1)
#define  ONMS_onms2_ctrl_on2_start_ms_shift                                      (0)
#define  ONMS_onms2_ctrl_on2_4k2k_mode_mask                                      (0xC0000000)
#define  ONMS_onms2_ctrl_on2_ms_src_sel_mask                                     (0x20000000)
#define  ONMS_onms2_ctrl_on2_blk_2frame_en_mask                                  (0x10000000)
#define  ONMS_onms2_ctrl_on2_pixel_get_en_mask                                   (0x08000000)
#define  ONMS_onms2_ctrl_on2_pixel_get_sel_mask                                  (0x06000000)
#define  ONMS_onms2_ctrl_on2_progressive_mask                                    (0x01000000)
#define  ONMS_onms2_ctrl_on2_vtotal_max_delta_mask                               (0x00F00000)
#define  ONMS_onms2_ctrl_on2_htotal_max_delta_mask                               (0x000F0000)
#define  ONMS_onms2_ctrl_dummy_15_mask                                           (0x00008000)
#define  ONMS_onms2_ctrl_dummy_14_mask                                           (0x00004000)
#define  ONMS_onms2_ctrl_dummy_13_mask                                           (0x00002000)
#define  ONMS_onms2_ctrl_on2_pixel_encoding_mask                                 (0x00001000)
#define  ONMS_onms2_ctrl_on2_vact_space_threshold_mask                           (0x00000F00)
#define  ONMS_onms2_ctrl_on2_vact_space_meas_en_mask                             (0x00000080)
#define  ONMS_onms2_ctrl_on2_meas_to_sel_mask                                    (0x00000040)
#define  ONMS_onms2_ctrl_on2_sycms_clk_mask                                      (0x00000020)
#define  ONMS_onms2_ctrl_on2_vs_meas_inv_mask                                    (0x00000010)
#define  ONMS_onms2_ctrl_on2_hs_meas_inv_mask                                    (0x00000008)
#define  ONMS_onms2_ctrl_on2_popup_meas_mask                                     (0x00000004)
#define  ONMS_onms2_ctrl_on2_ms_conti_mask                                       (0x00000002)
#define  ONMS_onms2_ctrl_on2_start_ms_mask                                       (0x00000001)
#define  ONMS_onms2_ctrl_on2_4k2k_mode(data)                                     (0xC0000000&((data)<<30))
#define  ONMS_onms2_ctrl_on2_ms_src_sel(data)                                    (0x20000000&((data)<<29))
#define  ONMS_onms2_ctrl_on2_blk_2frame_en(data)                                 (0x10000000&((data)<<28))
#define  ONMS_onms2_ctrl_on2_pixel_get_en(data)                                  (0x08000000&((data)<<27))
#define  ONMS_onms2_ctrl_on2_pixel_get_sel(data)                                 (0x06000000&((data)<<25))
#define  ONMS_onms2_ctrl_on2_progressive(data)                                   (0x01000000&((data)<<24))
#define  ONMS_onms2_ctrl_on2_vtotal_max_delta(data)                              (0x00F00000&((data)<<20))
#define  ONMS_onms2_ctrl_on2_htotal_max_delta(data)                              (0x000F0000&((data)<<16))
#define  ONMS_onms2_ctrl_dummy_15(data)                                          (0x00008000&((data)<<15))
#define  ONMS_onms2_ctrl_dummy_14(data)                                          (0x00004000&((data)<<14))
#define  ONMS_onms2_ctrl_dummy_13(data)                                          (0x00002000&((data)<<13))
#define  ONMS_onms2_ctrl_on2_pixel_encoding(data)                                (0x00001000&((data)<<12))
#define  ONMS_onms2_ctrl_on2_vact_space_threshold(data)                          (0x00000F00&((data)<<8))
#define  ONMS_onms2_ctrl_on2_vact_space_meas_en(data)                            (0x00000080&((data)<<7))
#define  ONMS_onms2_ctrl_on2_meas_to_sel(data)                                   (0x00000040&((data)<<6))
#define  ONMS_onms2_ctrl_on2_sycms_clk(data)                                     (0x00000020&((data)<<5))
#define  ONMS_onms2_ctrl_on2_vs_meas_inv(data)                                   (0x00000010&((data)<<4))
#define  ONMS_onms2_ctrl_on2_hs_meas_inv(data)                                   (0x00000008&((data)<<3))
#define  ONMS_onms2_ctrl_on2_popup_meas(data)                                    (0x00000004&((data)<<2))
#define  ONMS_onms2_ctrl_on2_ms_conti(data)                                      (0x00000002&((data)<<1))
#define  ONMS_onms2_ctrl_on2_start_ms(data)                                      (0x00000001&(data))
#define  ONMS_onms2_ctrl_get_on2_4k2k_mode(data)                                 ((0xC0000000&(data))>>30)
#define  ONMS_onms2_ctrl_get_on2_ms_src_sel(data)                                ((0x20000000&(data))>>29)
#define  ONMS_onms2_ctrl_get_on2_blk_2frame_en(data)                             ((0x10000000&(data))>>28)
#define  ONMS_onms2_ctrl_get_on2_pixel_get_en(data)                              ((0x08000000&(data))>>27)
#define  ONMS_onms2_ctrl_get_on2_pixel_get_sel(data)                             ((0x06000000&(data))>>25)
#define  ONMS_onms2_ctrl_get_on2_progressive(data)                               ((0x01000000&(data))>>24)
#define  ONMS_onms2_ctrl_get_on2_vtotal_max_delta(data)                          ((0x00F00000&(data))>>20)
#define  ONMS_onms2_ctrl_get_on2_htotal_max_delta(data)                          ((0x000F0000&(data))>>16)
#define  ONMS_onms2_ctrl_get_dummy_15(data)                                      ((0x00008000&(data))>>15)
#define  ONMS_onms2_ctrl_get_dummy_14(data)                                      ((0x00004000&(data))>>14)
#define  ONMS_onms2_ctrl_get_dummy_13(data)                                      ((0x00002000&(data))>>13)
#define  ONMS_onms2_ctrl_get_on2_pixel_encoding(data)                            ((0x00001000&(data))>>12)
#define  ONMS_onms2_ctrl_get_on2_vact_space_threshold(data)                      ((0x00000F00&(data))>>8)
#define  ONMS_onms2_ctrl_get_on2_vact_space_meas_en(data)                        ((0x00000080&(data))>>7)
#define  ONMS_onms2_ctrl_get_on2_meas_to_sel(data)                               ((0x00000040&(data))>>6)
#define  ONMS_onms2_ctrl_get_on2_sycms_clk(data)                                 ((0x00000020&(data))>>5)
#define  ONMS_onms2_ctrl_get_on2_vs_meas_inv(data)                               ((0x00000010&(data))>>4)
#define  ONMS_onms2_ctrl_get_on2_hs_meas_inv(data)                               ((0x00000008&(data))>>3)
#define  ONMS_onms2_ctrl_get_on2_popup_meas(data)                                ((0x00000004&(data))>>2)
#define  ONMS_onms2_ctrl_get_on2_ms_conti(data)                                  ((0x00000002&(data))>>1)
#define  ONMS_onms2_ctrl_get_on2_start_ms(data)                                  (0x00000001&(data))

#define  ONMS_onms2_blank_pixel_value_get_0                                      0x18021304
#define  ONMS_onms2_blank_pixel_value_get_0_reg_addr                             "0xB8021304"
#define  ONMS_onms2_blank_pixel_value_get_0_reg                                  0xB8021304
#define  ONMS_onms2_blank_pixel_value_get_0_inst_addr                            "0x001E"
#define  set_ONMS_onms2_blank_pixel_value_get_0_reg(data)                        (*((volatile unsigned int*)ONMS_onms2_blank_pixel_value_get_0_reg)=data)
#define  get_ONMS_onms2_blank_pixel_value_get_0_reg                              (*((volatile unsigned int*)ONMS_onms2_blank_pixel_value_get_0_reg))
#define  ONMS_onms2_blank_pixel_value_get_0_on2_pixel_ok_shift                   (24)
#define  ONMS_onms2_blank_pixel_value_get_0_on2_get_r_value_shift                (12)
#define  ONMS_onms2_blank_pixel_value_get_0_on2_get_g_value_shift                (0)
#define  ONMS_onms2_blank_pixel_value_get_0_on2_pixel_ok_mask                    (0x01000000)
#define  ONMS_onms2_blank_pixel_value_get_0_on2_get_r_value_mask                 (0x00FFF000)
#define  ONMS_onms2_blank_pixel_value_get_0_on2_get_g_value_mask                 (0x00000FFF)
#define  ONMS_onms2_blank_pixel_value_get_0_on2_pixel_ok(data)                   (0x01000000&((data)<<24))
#define  ONMS_onms2_blank_pixel_value_get_0_on2_get_r_value(data)                (0x00FFF000&((data)<<12))
#define  ONMS_onms2_blank_pixel_value_get_0_on2_get_g_value(data)                (0x00000FFF&(data))
#define  ONMS_onms2_blank_pixel_value_get_0_get_on2_pixel_ok(data)               ((0x01000000&(data))>>24)
#define  ONMS_onms2_blank_pixel_value_get_0_get_on2_get_r_value(data)            ((0x00FFF000&(data))>>12)
#define  ONMS_onms2_blank_pixel_value_get_0_get_on2_get_g_value(data)            (0x00000FFF&(data))

#define  ONMS_onms2_blank_pixel_value_get_1                                      0x18021308
#define  ONMS_onms2_blank_pixel_value_get_1_reg_addr                             "0xB8021308"
#define  ONMS_onms2_blank_pixel_value_get_1_reg                                  0xB8021308
#define  ONMS_onms2_blank_pixel_value_get_1_inst_addr                            "0x001F"
#define  set_ONMS_onms2_blank_pixel_value_get_1_reg(data)                        (*((volatile unsigned int*)ONMS_onms2_blank_pixel_value_get_1_reg)=data)
#define  get_ONMS_onms2_blank_pixel_value_get_1_reg                              (*((volatile unsigned int*)ONMS_onms2_blank_pixel_value_get_1_reg))
#define  ONMS_onms2_blank_pixel_value_get_1_on2_get_b_value_shift                (0)
#define  ONMS_onms2_blank_pixel_value_get_1_on2_get_b_value_mask                 (0x00000FFF)
#define  ONMS_onms2_blank_pixel_value_get_1_on2_get_b_value(data)                (0x00000FFF&(data))
#define  ONMS_onms2_blank_pixel_value_get_1_get_on2_get_b_value(data)            (0x00000FFF&(data))

#define  ONMS_onms2_blank_pixel_value_0                                          0x1802130C
#define  ONMS_onms2_blank_pixel_value_0_reg_addr                                 "0xB802130C"
#define  ONMS_onms2_blank_pixel_value_0_reg                                      0xB802130C
#define  ONMS_onms2_blank_pixel_value_0_inst_addr                                "0x0020"
#define  set_ONMS_onms2_blank_pixel_value_0_reg(data)                            (*((volatile unsigned int*)ONMS_onms2_blank_pixel_value_0_reg)=data)
#define  get_ONMS_onms2_blank_pixel_value_0_reg                                  (*((volatile unsigned int*)ONMS_onms2_blank_pixel_value_0_reg))
#define  ONMS_onms2_blank_pixel_value_0_on2_active_r_value_shift                 (12)
#define  ONMS_onms2_blank_pixel_value_0_on2_active_g_value_shift                 (0)
#define  ONMS_onms2_blank_pixel_value_0_on2_active_r_value_mask                  (0x00FFF000)
#define  ONMS_onms2_blank_pixel_value_0_on2_active_g_value_mask                  (0x00000FFF)
#define  ONMS_onms2_blank_pixel_value_0_on2_active_r_value(data)                 (0x00FFF000&((data)<<12))
#define  ONMS_onms2_blank_pixel_value_0_on2_active_g_value(data)                 (0x00000FFF&(data))
#define  ONMS_onms2_blank_pixel_value_0_get_on2_active_r_value(data)             ((0x00FFF000&(data))>>12)
#define  ONMS_onms2_blank_pixel_value_0_get_on2_active_g_value(data)             (0x00000FFF&(data))

#define  ONMS_onms2_blank_pixel_value_1                                          0x18021310
#define  ONMS_onms2_blank_pixel_value_1_reg_addr                                 "0xB8021310"
#define  ONMS_onms2_blank_pixel_value_1_reg                                      0xB8021310
#define  ONMS_onms2_blank_pixel_value_1_inst_addr                                "0x0021"
#define  set_ONMS_onms2_blank_pixel_value_1_reg(data)                            (*((volatile unsigned int*)ONMS_onms2_blank_pixel_value_1_reg)=data)
#define  get_ONMS_onms2_blank_pixel_value_1_reg                                  (*((volatile unsigned int*)ONMS_onms2_blank_pixel_value_1_reg))
#define  ONMS_onms2_blank_pixel_value_1_on2_active_b_value_shift                 (0)
#define  ONMS_onms2_blank_pixel_value_1_on2_active_b_value_mask                  (0x00000FFF)
#define  ONMS_onms2_blank_pixel_value_1_on2_active_b_value(data)                 (0x00000FFF&(data))
#define  ONMS_onms2_blank_pixel_value_1_get_on2_active_b_value(data)             (0x00000FFF&(data))

#define  ONMS_onms2_fp_vact12                                                    0x18021314
#define  ONMS_onms2_fp_vact12_reg_addr                                           "0xB8021314"
#define  ONMS_onms2_fp_vact12_reg                                                0xB8021314
#define  ONMS_onms2_fp_vact12_inst_addr                                          "0x0022"
#define  set_ONMS_onms2_fp_vact12_reg(data)                                      (*((volatile unsigned int*)ONMS_onms2_fp_vact12_reg)=data)
#define  get_ONMS_onms2_fp_vact12_reg                                            (*((volatile unsigned int*)ONMS_onms2_fp_vact12_reg))
#define  ONMS_onms2_fp_vact12_on2_vact2_shift                                    (16)
#define  ONMS_onms2_fp_vact12_on2_vact1_shift                                    (0)
#define  ONMS_onms2_fp_vact12_on2_vact2_mask                                     (0x07FF0000)
#define  ONMS_onms2_fp_vact12_on2_vact1_mask                                     (0x000007FF)
#define  ONMS_onms2_fp_vact12_on2_vact2(data)                                    (0x07FF0000&((data)<<16))
#define  ONMS_onms2_fp_vact12_on2_vact1(data)                                    (0x000007FF&(data))
#define  ONMS_onms2_fp_vact12_get_on2_vact2(data)                                ((0x07FF0000&(data))>>16)
#define  ONMS_onms2_fp_vact12_get_on2_vact1(data)                                (0x000007FF&(data))

#define  ONMS_onms2_fp_vact34                                                    0x18021318
#define  ONMS_onms2_fp_vact34_reg_addr                                           "0xB8021318"
#define  ONMS_onms2_fp_vact34_reg                                                0xB8021318
#define  ONMS_onms2_fp_vact34_inst_addr                                          "0x0023"
#define  set_ONMS_onms2_fp_vact34_reg(data)                                      (*((volatile unsigned int*)ONMS_onms2_fp_vact34_reg)=data)
#define  get_ONMS_onms2_fp_vact34_reg                                            (*((volatile unsigned int*)ONMS_onms2_fp_vact34_reg))
#define  ONMS_onms2_fp_vact34_on2_vact4_shift                                    (16)
#define  ONMS_onms2_fp_vact34_on2_vact3_shift                                    (0)
#define  ONMS_onms2_fp_vact34_on2_vact4_mask                                     (0x07FF0000)
#define  ONMS_onms2_fp_vact34_on2_vact3_mask                                     (0x000007FF)
#define  ONMS_onms2_fp_vact34_on2_vact4(data)                                    (0x07FF0000&((data)<<16))
#define  ONMS_onms2_fp_vact34_on2_vact3(data)                                    (0x000007FF&(data))
#define  ONMS_onms2_fp_vact34_get_on2_vact4(data)                                ((0x07FF0000&(data))>>16)
#define  ONMS_onms2_fp_vact34_get_on2_vact3(data)                                (0x000007FF&(data))

#define  ONMS_onms2_fp_vact_space                                                0x1802131C
#define  ONMS_onms2_fp_vact_space_reg_addr                                       "0xB802131C"
#define  ONMS_onms2_fp_vact_space_reg                                            0xB802131C
#define  ONMS_onms2_fp_vact_space_inst_addr                                      "0x0024"
#define  set_ONMS_onms2_fp_vact_space_reg(data)                                  (*((volatile unsigned int*)ONMS_onms2_fp_vact_space_reg)=data)
#define  get_ONMS_onms2_fp_vact_space_reg                                        (*((volatile unsigned int*)ONMS_onms2_fp_vact_space_reg))
#define  ONMS_onms2_fp_vact_space_on2_fp_vact_space1_shift                       (20)
#define  ONMS_onms2_fp_vact_space_on2_fp_vact_space2_shift                       (10)
#define  ONMS_onms2_fp_vact_space_on2_fp_vact_space3_shift                       (0)
#define  ONMS_onms2_fp_vact_space_on2_fp_vact_space1_mask                        (0x3FF00000)
#define  ONMS_onms2_fp_vact_space_on2_fp_vact_space2_mask                        (0x000FFC00)
#define  ONMS_onms2_fp_vact_space_on2_fp_vact_space3_mask                        (0x000003FF)
#define  ONMS_onms2_fp_vact_space_on2_fp_vact_space1(data)                       (0x3FF00000&((data)<<20))
#define  ONMS_onms2_fp_vact_space_on2_fp_vact_space2(data)                       (0x000FFC00&((data)<<10))
#define  ONMS_onms2_fp_vact_space_on2_fp_vact_space3(data)                       (0x000003FF&(data))
#define  ONMS_onms2_fp_vact_space_get_on2_fp_vact_space1(data)                   ((0x3FF00000&(data))>>20)
#define  ONMS_onms2_fp_vact_space_get_on2_fp_vact_space2(data)                   ((0x000FFC00&(data))>>10)
#define  ONMS_onms2_fp_vact_space_get_on2_fp_vact_space3(data)                   (0x000003FF&(data))

#define  ONMS_onms2_blank_line                                                   0x18021320
#define  ONMS_onms2_blank_line_reg_addr                                          "0xB8021320"
#define  ONMS_onms2_blank_line_reg                                               0xB8021320
#define  ONMS_onms2_blank_line_inst_addr                                         "0x0025"
#define  set_ONMS_onms2_blank_line_reg(data)                                     (*((volatile unsigned int*)ONMS_onms2_blank_line_reg)=data)
#define  get_ONMS_onms2_blank_line_reg                                           (*((volatile unsigned int*)ONMS_onms2_blank_line_reg))
#define  ONMS_onms2_blank_line_on2_r_blank_line_start_shift                      (16)
#define  ONMS_onms2_blank_line_on2_l_blank_line_end_shift                        (0)
#define  ONMS_onms2_blank_line_on2_r_blank_line_start_mask                       (0x07FF0000)
#define  ONMS_onms2_blank_line_on2_l_blank_line_end_mask                         (0x000007FF)
#define  ONMS_onms2_blank_line_on2_r_blank_line_start(data)                      (0x07FF0000&((data)<<16))
#define  ONMS_onms2_blank_line_on2_l_blank_line_end(data)                        (0x000007FF&(data))
#define  ONMS_onms2_blank_line_get_on2_r_blank_line_start(data)                  ((0x07FF0000&(data))>>16)
#define  ONMS_onms2_blank_line_get_on2_l_blank_line_end(data)                    (0x000007FF&(data))

#define  ONMS_onms2_active_space1_line_number                                    0x18021324
#define  ONMS_onms2_active_space1_line_number_reg_addr                           "0xB8021324"
#define  ONMS_onms2_active_space1_line_number_reg                                0xB8021324
#define  ONMS_onms2_active_space1_line_number_inst_addr                          "0x0026"
#define  set_ONMS_onms2_active_space1_line_number_reg(data)                      (*((volatile unsigned int*)ONMS_onms2_active_space1_line_number_reg)=data)
#define  get_ONMS_onms2_active_space1_line_number_reg                            (*((volatile unsigned int*)ONMS_onms2_active_space1_line_number_reg))
#define  ONMS_onms2_active_space1_line_number_on2_vact_space1_end_shift          (16)
#define  ONMS_onms2_active_space1_line_number_on2_vact_space1_start_shift        (0)
#define  ONMS_onms2_active_space1_line_number_on2_vact_space1_end_mask           (0x03FF0000)
#define  ONMS_onms2_active_space1_line_number_on2_vact_space1_start_mask         (0x000003FF)
#define  ONMS_onms2_active_space1_line_number_on2_vact_space1_end(data)          (0x03FF0000&((data)<<16))
#define  ONMS_onms2_active_space1_line_number_on2_vact_space1_start(data)        (0x000003FF&(data))
#define  ONMS_onms2_active_space1_line_number_get_on2_vact_space1_end(data)      ((0x03FF0000&(data))>>16)
#define  ONMS_onms2_active_space1_line_number_get_on2_vact_space1_start(data)    (0x000003FF&(data))

#define  ONMS_onms2_active_space2_line_number                                    0x18021328
#define  ONMS_onms2_active_space2_line_number_reg_addr                           "0xB8021328"
#define  ONMS_onms2_active_space2_line_number_reg                                0xB8021328
#define  ONMS_onms2_active_space2_line_number_inst_addr                          "0x0027"
#define  set_ONMS_onms2_active_space2_line_number_reg(data)                      (*((volatile unsigned int*)ONMS_onms2_active_space2_line_number_reg)=data)
#define  get_ONMS_onms2_active_space2_line_number_reg                            (*((volatile unsigned int*)ONMS_onms2_active_space2_line_number_reg))
#define  ONMS_onms2_active_space2_line_number_on2_vact_space2_end_shift          (16)
#define  ONMS_onms2_active_space2_line_number_on2_vact_space2_start_shift        (0)
#define  ONMS_onms2_active_space2_line_number_on2_vact_space2_end_mask           (0x03FF0000)
#define  ONMS_onms2_active_space2_line_number_on2_vact_space2_start_mask         (0x000003FF)
#define  ONMS_onms2_active_space2_line_number_on2_vact_space2_end(data)          (0x03FF0000&((data)<<16))
#define  ONMS_onms2_active_space2_line_number_on2_vact_space2_start(data)        (0x000003FF&(data))
#define  ONMS_onms2_active_space2_line_number_get_on2_vact_space2_end(data)      ((0x03FF0000&(data))>>16)
#define  ONMS_onms2_active_space2_line_number_get_on2_vact_space2_start(data)    (0x000003FF&(data))

#define  ONMS_onms2_active_space3_line_number                                    0x1802132C
#define  ONMS_onms2_active_space3_line_number_reg_addr                           "0xB802132C"
#define  ONMS_onms2_active_space3_line_number_reg                                0xB802132C
#define  ONMS_onms2_active_space3_line_number_inst_addr                          "0x0028"
#define  set_ONMS_onms2_active_space3_line_number_reg(data)                      (*((volatile unsigned int*)ONMS_onms2_active_space3_line_number_reg)=data)
#define  get_ONMS_onms2_active_space3_line_number_reg                            (*((volatile unsigned int*)ONMS_onms2_active_space3_line_number_reg))
#define  ONMS_onms2_active_space3_line_number_on2_vact_space3_end_shift          (16)
#define  ONMS_onms2_active_space3_line_number_on2_vact_space3_start_shift        (0)
#define  ONMS_onms2_active_space3_line_number_on2_vact_space3_end_mask           (0x03FF0000)
#define  ONMS_onms2_active_space3_line_number_on2_vact_space3_start_mask         (0x000003FF)
#define  ONMS_onms2_active_space3_line_number_on2_vact_space3_end(data)          (0x03FF0000&((data)<<16))
#define  ONMS_onms2_active_space3_line_number_on2_vact_space3_start(data)        (0x000003FF&(data))
#define  ONMS_onms2_active_space3_line_number_get_on2_vact_space3_end(data)      ((0x03FF0000&(data))>>16)
#define  ONMS_onms2_active_space3_line_number_get_on2_vact_space3_start(data)    (0x000003FF&(data))

#define  ONMS_onms2_vs_period                                                    0x18021330
#define  ONMS_onms2_vs_period_reg_addr                                           "0xB8021330"
#define  ONMS_onms2_vs_period_reg                                                0xB8021330
#define  ONMS_onms2_vs_period_inst_addr                                          "0x0029"
#define  set_ONMS_onms2_vs_period_reg(data)                                      (*((volatile unsigned int*)ONMS_onms2_vs_period_reg)=data)
#define  get_ONMS_onms2_vs_period_reg                                            (*((volatile unsigned int*)ONMS_onms2_vs_period_reg))
#define  ONMS_onms2_vs_period_on2_vtotalde_shift                                 (16)
#define  ONMS_onms2_vs_period_on2_vtotal_shift                                   (0)
#define  ONMS_onms2_vs_period_on2_vtotalde_mask                                  (0x1FFF0000)
#define  ONMS_onms2_vs_period_on2_vtotal_mask                                    (0x00003FFF)
#define  ONMS_onms2_vs_period_on2_vtotalde(data)                                 (0x1FFF0000&((data)<<16))
#define  ONMS_onms2_vs_period_on2_vtotal(data)                                   (0x00003FFF&(data))
#define  ONMS_onms2_vs_period_get_on2_vtotalde(data)                             ((0x1FFF0000&(data))>>16)
#define  ONMS_onms2_vs_period_get_on2_vtotal(data)                               (0x00003FFF&(data))

#define  ONMS_onms2_vshs_high_period                                             0x18021334
#define  ONMS_onms2_vshs_high_period_reg_addr                                    "0xB8021334"
#define  ONMS_onms2_vshs_high_period_reg                                         0xB8021334
#define  ONMS_onms2_vshs_high_period_inst_addr                                   "0x002A"
#define  set_ONMS_onms2_vshs_high_period_reg(data)                               (*((volatile unsigned int*)ONMS_onms2_vshs_high_period_reg)=data)
#define  get_ONMS_onms2_vshs_high_period_reg                                     (*((volatile unsigned int*)ONMS_onms2_vshs_high_period_reg))
#define  ONMS_onms2_vshs_high_period_on2_vs_high_period_shift                    (16)
#define  ONMS_onms2_vshs_high_period_on2_hs_high_period_shift                    (0)
#define  ONMS_onms2_vshs_high_period_on2_vs_high_period_mask                     (0x0FFF0000)
#define  ONMS_onms2_vshs_high_period_on2_hs_high_period_mask                     (0x00003FFF)
#define  ONMS_onms2_vshs_high_period_on2_vs_high_period(data)                    (0x0FFF0000&((data)<<16))
#define  ONMS_onms2_vshs_high_period_on2_hs_high_period(data)                    (0x00003FFF&(data))
#define  ONMS_onms2_vshs_high_period_get_on2_vs_high_period(data)                ((0x0FFF0000&(data))>>16)
#define  ONMS_onms2_vshs_high_period_get_on2_hs_high_period(data)                (0x00003FFF&(data))

#define  ONMS_onms2_hs_period                                                    0x18021338
#define  ONMS_onms2_hs_period_reg_addr                                           "0xB8021338"
#define  ONMS_onms2_hs_period_reg                                                0xB8021338
#define  ONMS_onms2_hs_period_inst_addr                                          "0x002B"
#define  set_ONMS_onms2_hs_period_reg(data)                                      (*((volatile unsigned int*)ONMS_onms2_hs_period_reg)=data)
#define  get_ONMS_onms2_hs_period_reg                                            (*((volatile unsigned int*)ONMS_onms2_hs_period_reg))
#define  ONMS_onms2_hs_period_on2_htotal_h12b_shift                              (4)
#define  ONMS_onms2_hs_period_on2_htotal_f4b_shift                               (0)
#define  ONMS_onms2_hs_period_on2_htotal_h12b_mask                               (0x0003FFF0)
#define  ONMS_onms2_hs_period_on2_htotal_f4b_mask                                (0x0000000F)
#define  ONMS_onms2_hs_period_on2_htotal_h12b(data)                              (0x0003FFF0&((data)<<4))
#define  ONMS_onms2_hs_period_on2_htotal_f4b(data)                               (0x0000000F&(data))
#define  ONMS_onms2_hs_period_get_on2_htotal_h12b(data)                          ((0x0003FFF0&(data))>>4)
#define  ONMS_onms2_hs_period_get_on2_htotal_f4b(data)                           (0x0000000F&(data))

#define  ONMS_onms2_vact_sta                                                     0x1802133C
#define  ONMS_onms2_vact_sta_reg_addr                                            "0xB802133C"
#define  ONMS_onms2_vact_sta_reg                                                 0xB802133C
#define  ONMS_onms2_vact_sta_inst_addr                                           "0x002C"
#define  set_ONMS_onms2_vact_sta_reg(data)                                       (*((volatile unsigned int*)ONMS_onms2_vact_sta_reg)=data)
#define  get_ONMS_onms2_vact_sta_reg                                             (*((volatile unsigned int*)ONMS_onms2_vact_sta_reg))
#define  ONMS_onms2_vact_sta_on2_vblank_len_shift                                (16)
#define  ONMS_onms2_vact_sta_on2_vact_start_shift                                (0)
#define  ONMS_onms2_vact_sta_on2_vblank_len_mask                                 (0x00FF0000)
#define  ONMS_onms2_vact_sta_on2_vact_start_mask                                 (0x00000FFF)
#define  ONMS_onms2_vact_sta_on2_vblank_len(data)                                (0x00FF0000&((data)<<16))
#define  ONMS_onms2_vact_sta_on2_vact_start(data)                                (0x00000FFF&(data))
#define  ONMS_onms2_vact_sta_get_on2_vblank_len(data)                            ((0x00FF0000&(data))>>16)
#define  ONMS_onms2_vact_sta_get_on2_vact_start(data)                            (0x00000FFF&(data))

#define  ONMS_onms2_hact_sta                                                     0x18021340
#define  ONMS_onms2_hact_sta_reg_addr                                            "0xB8021340"
#define  ONMS_onms2_hact_sta_reg                                                 0xB8021340
#define  ONMS_onms2_hact_sta_inst_addr                                           "0x002D"
#define  set_ONMS_onms2_hact_sta_reg(data)                                       (*((volatile unsigned int*)ONMS_onms2_hact_sta_reg)=data)
#define  get_ONMS_onms2_hact_sta_reg                                             (*((volatile unsigned int*)ONMS_onms2_hact_sta_reg))
#define  ONMS_onms2_hact_sta_on2_hact_start_shift                                (0)
#define  ONMS_onms2_hact_sta_on2_hact_start_mask                                 (0x00003FFF)
#define  ONMS_onms2_hact_sta_on2_hact_start(data)                                (0x00003FFF&(data))
#define  ONMS_onms2_hact_sta_get_on2_hact_start(data)                            (0x00003FFF&(data))

#define  ONMS_onms2_hact                                                         0x18021344
#define  ONMS_onms2_hact_reg_addr                                                "0xB8021344"
#define  ONMS_onms2_hact_reg                                                     0xB8021344
#define  ONMS_onms2_hact_inst_addr                                               "0x002E"
#define  set_ONMS_onms2_hact_reg(data)                                           (*((volatile unsigned int*)ONMS_onms2_hact_reg)=data)
#define  get_ONMS_onms2_hact_reg                                                 (*((volatile unsigned int*)ONMS_onms2_hact_reg))
#define  ONMS_onms2_hact_on2_hact_shift                                          (4)
#define  ONMS_onms2_hact_on2_hact_fract_shift                                    (0)
#define  ONMS_onms2_hact_on2_hact_mask                                           (0x0003FFF0)
#define  ONMS_onms2_hact_on2_hact_fract_mask                                     (0x0000000F)
#define  ONMS_onms2_hact_on2_hact(data)                                          (0x0003FFF0&((data)<<4))
#define  ONMS_onms2_hact_on2_hact_fract(data)                                    (0x0000000F&(data))
#define  ONMS_onms2_hact_get_on2_hact(data)                                      ((0x0003FFF0&(data))>>4)
#define  ONMS_onms2_hact_get_on2_hact_fract(data)                                (0x0000000F&(data))

#define  ONMS_onms2_hsync_meas_ctrl                                              0x1802135C
#define  ONMS_onms2_hsync_meas_ctrl_reg_addr                                     "0xB802135C"
#define  ONMS_onms2_hsync_meas_ctrl_reg                                          0xB802135C
#define  ONMS_onms2_hsync_meas_ctrl_inst_addr                                    "0x002F"
#define  set_ONMS_onms2_hsync_meas_ctrl_reg(data)                                (*((volatile unsigned int*)ONMS_onms2_hsync_meas_ctrl_reg)=data)
#define  get_ONMS_onms2_hsync_meas_ctrl_reg                                      (*((volatile unsigned int*)ONMS_onms2_hsync_meas_ctrl_reg))
#define  ONMS_onms2_hsync_meas_ctrl_on2_htotal_max_delta_new_shift               (24)
#define  ONMS_onms2_hsync_meas_ctrl_on2_average_line_shift                       (16)
#define  ONMS_onms2_hsync_meas_ctrl_on2_target_measure_shift                     (0)
#define  ONMS_onms2_hsync_meas_ctrl_on2_htotal_max_delta_new_mask                (0x7F000000)
#define  ONMS_onms2_hsync_meas_ctrl_on2_average_line_mask                        (0x000F0000)
#define  ONMS_onms2_hsync_meas_ctrl_on2_target_measure_mask                      (0x00003FFF)
#define  ONMS_onms2_hsync_meas_ctrl_on2_htotal_max_delta_new(data)               (0x7F000000&((data)<<24))
#define  ONMS_onms2_hsync_meas_ctrl_on2_average_line(data)                       (0x000F0000&((data)<<16))
#define  ONMS_onms2_hsync_meas_ctrl_on2_target_measure(data)                     (0x00003FFF&(data))
#define  ONMS_onms2_hsync_meas_ctrl_get_on2_htotal_max_delta_new(data)           ((0x7F000000&(data))>>24)
#define  ONMS_onms2_hsync_meas_ctrl_get_on2_average_line(data)                   ((0x000F0000&(data))>>16)
#define  ONMS_onms2_hsync_meas_ctrl_get_on2_target_measure(data)                 (0x00003FFF&(data))

#define  ONMS_onms2_hsync_meas_ctrl_2                                            0x18021360
#define  ONMS_onms2_hsync_meas_ctrl_2_reg_addr                                   "0xB8021360"
#define  ONMS_onms2_hsync_meas_ctrl_2_reg                                        0xB8021360
#define  ONMS_onms2_hsync_meas_ctrl_2_inst_addr                                  "0x0030"
#define  set_ONMS_onms2_hsync_meas_ctrl_2_reg(data)                              (*((volatile unsigned int*)ONMS_onms2_hsync_meas_ctrl_2_reg)=data)
#define  get_ONMS_onms2_hsync_meas_ctrl_2_reg                                    (*((volatile unsigned int*)ONMS_onms2_hsync_meas_ctrl_2_reg))
#define  ONMS_onms2_hsync_meas_ctrl_2_on2_vmeas_end_shift                        (16)
#define  ONMS_onms2_hsync_meas_ctrl_2_on2_vmeas_start_shift                      (0)
#define  ONMS_onms2_hsync_meas_ctrl_2_on2_vmeas_end_mask                         (0x0FFF0000)
#define  ONMS_onms2_hsync_meas_ctrl_2_on2_vmeas_start_mask                       (0x00000FFF)
#define  ONMS_onms2_hsync_meas_ctrl_2_on2_vmeas_end(data)                        (0x0FFF0000&((data)<<16))
#define  ONMS_onms2_hsync_meas_ctrl_2_on2_vmeas_start(data)                      (0x00000FFF&(data))
#define  ONMS_onms2_hsync_meas_ctrl_2_get_on2_vmeas_end(data)                    ((0x0FFF0000&(data))>>16)
#define  ONMS_onms2_hsync_meas_ctrl_2_get_on2_vmeas_start(data)                  (0x00000FFF&(data))

#define  ONMS_onms2_hsync_meas_result                                            0x18021364
#define  ONMS_onms2_hsync_meas_result_reg_addr                                   "0xB8021364"
#define  ONMS_onms2_hsync_meas_result_reg                                        0xB8021364
#define  ONMS_onms2_hsync_meas_result_inst_addr                                  "0x0031"
#define  set_ONMS_onms2_hsync_meas_result_reg(data)                              (*((volatile unsigned int*)ONMS_onms2_hsync_meas_result_reg)=data)
#define  get_ONMS_onms2_hsync_meas_result_reg                                    (*((volatile unsigned int*)ONMS_onms2_hsync_meas_result_reg))
#define  ONMS_onms2_hsync_meas_result_on2_hmax_delta_total_shift                 (0)
#define  ONMS_onms2_hsync_meas_result_on2_hmax_delta_total_mask                  (0x00003FFF)
#define  ONMS_onms2_hsync_meas_result_on2_hmax_delta_total(data)                 (0x00003FFF&(data))
#define  ONMS_onms2_hsync_meas_result_get_on2_hmax_delta_total(data)             (0x00003FFF&(data))

#define  ONMS_onms2_status                                                       0x18021368
#define  ONMS_onms2_status_reg_addr                                              "0xB8021368"
#define  ONMS_onms2_status_reg                                                   0xB8021368
#define  ONMS_onms2_status_inst_addr                                             "0x0032"
#define  set_ONMS_onms2_status_reg(data)                                         (*((volatile unsigned int*)ONMS_onms2_status_reg)=data)
#define  get_ONMS_onms2_status_reg                                               (*((volatile unsigned int*)ONMS_onms2_status_reg))
#define  ONMS_onms2_status_on2_hs_meas_over_range_shift                          (21)
#define  ONMS_onms2_status_on2_vs_per_to_long_shift                              (20)
#define  ONMS_onms2_status_on2_vs_pol_out_shift                                  (17)
#define  ONMS_onms2_status_on2_hs_pol_out_shift                                  (16)
#define  ONMS_onms2_status_on2_vs_per_over_range_shift                           (15)
#define  ONMS_onms2_status_on2_hs_per_over_range_shift                           (14)
#define  ONMS_onms2_status_on2_vs_per_timeout_shift                              (13)
#define  ONMS_onms2_status_on2_vs_high_timeout_shift                             (12)
#define  ONMS_onms2_status_on2_vs_per_overflow_shift                             (11)
#define  ONMS_onms2_status_on2_hs_per_overflow_shift                             (10)
#define  ONMS_onms2_status_on2_vs_pol_chg_shift                                  (9)
#define  ONMS_onms2_status_on2_hs_pol_chg_shift                                  (8)
#define  ONMS_onms2_status_on2_vtotalde_chg_shift                                (7)
#define  ONMS_onms2_status_on2_vtotal_chg_shift                                  (6)
#define  ONMS_onms2_status_on2_hact_chg_shift                                    (5)
#define  ONMS_onms2_status_on2_htotal_chg_shift                                  (4)
#define  ONMS_onms2_status_on2_hs_active_pixel_var_shift                         (3)
#define  ONMS_onms2_status_on2_hs_meas_over_range_mask                           (0x00200000)
#define  ONMS_onms2_status_on2_vs_per_to_long_mask                               (0x00100000)
#define  ONMS_onms2_status_on2_vs_pol_out_mask                                   (0x00020000)
#define  ONMS_onms2_status_on2_hs_pol_out_mask                                   (0x00010000)
#define  ONMS_onms2_status_on2_vs_per_over_range_mask                            (0x00008000)
#define  ONMS_onms2_status_on2_hs_per_over_range_mask                            (0x00004000)
#define  ONMS_onms2_status_on2_vs_per_timeout_mask                               (0x00002000)
#define  ONMS_onms2_status_on2_vs_high_timeout_mask                              (0x00001000)
#define  ONMS_onms2_status_on2_vs_per_overflow_mask                              (0x00000800)
#define  ONMS_onms2_status_on2_hs_per_overflow_mask                              (0x00000400)
#define  ONMS_onms2_status_on2_vs_pol_chg_mask                                   (0x00000200)
#define  ONMS_onms2_status_on2_hs_pol_chg_mask                                   (0x00000100)
#define  ONMS_onms2_status_on2_vtotalde_chg_mask                                 (0x00000080)
#define  ONMS_onms2_status_on2_vtotal_chg_mask                                   (0x00000040)
#define  ONMS_onms2_status_on2_hact_chg_mask                                     (0x00000020)
#define  ONMS_onms2_status_on2_htotal_chg_mask                                   (0x00000010)
#define  ONMS_onms2_status_on2_hs_active_pixel_var_mask                          (0x00000008)
#define  ONMS_onms2_status_on2_hs_meas_over_range(data)                          (0x00200000&((data)<<21))
#define  ONMS_onms2_status_on2_vs_per_to_long(data)                              (0x00100000&((data)<<20))
#define  ONMS_onms2_status_on2_vs_pol_out(data)                                  (0x00020000&((data)<<17))
#define  ONMS_onms2_status_on2_hs_pol_out(data)                                  (0x00010000&((data)<<16))
#define  ONMS_onms2_status_on2_vs_per_over_range(data)                           (0x00008000&((data)<<15))
#define  ONMS_onms2_status_on2_hs_per_over_range(data)                           (0x00004000&((data)<<14))
#define  ONMS_onms2_status_on2_vs_per_timeout(data)                              (0x00002000&((data)<<13))
#define  ONMS_onms2_status_on2_vs_high_timeout(data)                             (0x00001000&((data)<<12))
#define  ONMS_onms2_status_on2_vs_per_overflow(data)                             (0x00000800&((data)<<11))
#define  ONMS_onms2_status_on2_hs_per_overflow(data)                             (0x00000400&((data)<<10))
#define  ONMS_onms2_status_on2_vs_pol_chg(data)                                  (0x00000200&((data)<<9))
#define  ONMS_onms2_status_on2_hs_pol_chg(data)                                  (0x00000100&((data)<<8))
#define  ONMS_onms2_status_on2_vtotalde_chg(data)                                (0x00000080&((data)<<7))
#define  ONMS_onms2_status_on2_vtotal_chg(data)                                  (0x00000040&((data)<<6))
#define  ONMS_onms2_status_on2_hact_chg(data)                                    (0x00000020&((data)<<5))
#define  ONMS_onms2_status_on2_htotal_chg(data)                                  (0x00000010&((data)<<4))
#define  ONMS_onms2_status_on2_hs_active_pixel_var(data)                         (0x00000008&((data)<<3))
#define  ONMS_onms2_status_get_on2_hs_meas_over_range(data)                      ((0x00200000&(data))>>21)
#define  ONMS_onms2_status_get_on2_vs_per_to_long(data)                          ((0x00100000&(data))>>20)
#define  ONMS_onms2_status_get_on2_vs_pol_out(data)                              ((0x00020000&(data))>>17)
#define  ONMS_onms2_status_get_on2_hs_pol_out(data)                              ((0x00010000&(data))>>16)
#define  ONMS_onms2_status_get_on2_vs_per_over_range(data)                       ((0x00008000&(data))>>15)
#define  ONMS_onms2_status_get_on2_hs_per_over_range(data)                       ((0x00004000&(data))>>14)
#define  ONMS_onms2_status_get_on2_vs_per_timeout(data)                          ((0x00002000&(data))>>13)
#define  ONMS_onms2_status_get_on2_vs_high_timeout(data)                         ((0x00001000&(data))>>12)
#define  ONMS_onms2_status_get_on2_vs_per_overflow(data)                         ((0x00000800&(data))>>11)
#define  ONMS_onms2_status_get_on2_hs_per_overflow(data)                         ((0x00000400&(data))>>10)
#define  ONMS_onms2_status_get_on2_vs_pol_chg(data)                              ((0x00000200&(data))>>9)
#define  ONMS_onms2_status_get_on2_hs_pol_chg(data)                              ((0x00000100&(data))>>8)
#define  ONMS_onms2_status_get_on2_vtotalde_chg(data)                            ((0x00000080&(data))>>7)
#define  ONMS_onms2_status_get_on2_vtotal_chg(data)                              ((0x00000040&(data))>>6)
#define  ONMS_onms2_status_get_on2_hact_chg(data)                                ((0x00000020&(data))>>5)
#define  ONMS_onms2_status_get_on2_htotal_chg(data)                              ((0x00000010&(data))>>4)
#define  ONMS_onms2_status_get_on2_hs_active_pixel_var(data)                     ((0x00000008&(data))>>3)

#define  ONMS_onms2_watchdog_en                                                  0x1802136C
#define  ONMS_onms2_watchdog_en_reg_addr                                         "0xB802136C"
#define  ONMS_onms2_watchdog_en_reg                                              0xB802136C
#define  ONMS_onms2_watchdog_en_inst_addr                                        "0x0033"
#define  set_ONMS_onms2_watchdog_en_reg(data)                                    (*((volatile unsigned int*)ONMS_onms2_watchdog_en_reg)=data)
#define  get_ONMS_onms2_watchdog_en_reg                                          (*((volatile unsigned int*)ONMS_onms2_watchdog_en_reg))
#define  ONMS_onms2_watchdog_en_on2_wd_to_main_shift                             (31)
#define  ONMS_onms2_watchdog_en_on2_wd_to_sub_shift                              (30)
#define  ONMS_onms2_watchdog_en_on2_wd_hs_meas_over_range_shift                  (21)
#define  ONMS_onms2_watchdog_en_on2_wd_vs_per_over_range_shift                   (15)
#define  ONMS_onms2_watchdog_en_on2_wd_hs_per_over_range_shift                   (14)
#define  ONMS_onms2_watchdog_en_on2_wd_vs_per_timeout_shift                      (13)
#define  ONMS_onms2_watchdog_en_on2_wd_vs_high_timeout_shift                     (12)
#define  ONMS_onms2_watchdog_en_on2_wd_vs_per_overflow_shift                     (11)
#define  ONMS_onms2_watchdog_en_on2_wd_hs_per_overflow_shift                     (10)
#define  ONMS_onms2_watchdog_en_on2_wd_vs_pol_chg_shift                          (9)
#define  ONMS_onms2_watchdog_en_on2_wd_hs_pol_chg_shift                          (8)
#define  ONMS_onms2_watchdog_en_on2_wd_vtotalde_chg_shift                        (7)
#define  ONMS_onms2_watchdog_en_on2_wd_vtotal_chg_shift                          (6)
#define  ONMS_onms2_watchdog_en_on2_wd_hact_chg_shift                            (5)
#define  ONMS_onms2_watchdog_en_on2_wd_htotal_chg_shift                          (4)
#define  ONMS_onms2_watchdog_en_on2_wd_hs_active_pixel_var_shift                 (3)
#define  ONMS_onms2_watchdog_en_on2_wd_to_main_mask                              (0x80000000)
#define  ONMS_onms2_watchdog_en_on2_wd_to_sub_mask                               (0x40000000)
#define  ONMS_onms2_watchdog_en_on2_wd_hs_meas_over_range_mask                   (0x00200000)
#define  ONMS_onms2_watchdog_en_on2_wd_vs_per_over_range_mask                    (0x00008000)
#define  ONMS_onms2_watchdog_en_on2_wd_hs_per_over_range_mask                    (0x00004000)
#define  ONMS_onms2_watchdog_en_on2_wd_vs_per_timeout_mask                       (0x00002000)
#define  ONMS_onms2_watchdog_en_on2_wd_vs_high_timeout_mask                      (0x00001000)
#define  ONMS_onms2_watchdog_en_on2_wd_vs_per_overflow_mask                      (0x00000800)
#define  ONMS_onms2_watchdog_en_on2_wd_hs_per_overflow_mask                      (0x00000400)
#define  ONMS_onms2_watchdog_en_on2_wd_vs_pol_chg_mask                           (0x00000200)
#define  ONMS_onms2_watchdog_en_on2_wd_hs_pol_chg_mask                           (0x00000100)
#define  ONMS_onms2_watchdog_en_on2_wd_vtotalde_chg_mask                         (0x00000080)
#define  ONMS_onms2_watchdog_en_on2_wd_vtotal_chg_mask                           (0x00000040)
#define  ONMS_onms2_watchdog_en_on2_wd_hact_chg_mask                             (0x00000020)
#define  ONMS_onms2_watchdog_en_on2_wd_htotal_chg_mask                           (0x00000010)
#define  ONMS_onms2_watchdog_en_on2_wd_hs_active_pixel_var_mask                  (0x00000008)
#define  ONMS_onms2_watchdog_en_on2_wd_to_main(data)                             (0x80000000&((data)<<31))
#define  ONMS_onms2_watchdog_en_on2_wd_to_sub(data)                              (0x40000000&((data)<<30))
#define  ONMS_onms2_watchdog_en_on2_wd_hs_meas_over_range(data)                  (0x00200000&((data)<<21))
#define  ONMS_onms2_watchdog_en_on2_wd_vs_per_over_range(data)                   (0x00008000&((data)<<15))
#define  ONMS_onms2_watchdog_en_on2_wd_hs_per_over_range(data)                   (0x00004000&((data)<<14))
#define  ONMS_onms2_watchdog_en_on2_wd_vs_per_timeout(data)                      (0x00002000&((data)<<13))
#define  ONMS_onms2_watchdog_en_on2_wd_vs_high_timeout(data)                     (0x00001000&((data)<<12))
#define  ONMS_onms2_watchdog_en_on2_wd_vs_per_overflow(data)                     (0x00000800&((data)<<11))
#define  ONMS_onms2_watchdog_en_on2_wd_hs_per_overflow(data)                     (0x00000400&((data)<<10))
#define  ONMS_onms2_watchdog_en_on2_wd_vs_pol_chg(data)                          (0x00000200&((data)<<9))
#define  ONMS_onms2_watchdog_en_on2_wd_hs_pol_chg(data)                          (0x00000100&((data)<<8))
#define  ONMS_onms2_watchdog_en_on2_wd_vtotalde_chg(data)                        (0x00000080&((data)<<7))
#define  ONMS_onms2_watchdog_en_on2_wd_vtotal_chg(data)                          (0x00000040&((data)<<6))
#define  ONMS_onms2_watchdog_en_on2_wd_hact_chg(data)                            (0x00000020&((data)<<5))
#define  ONMS_onms2_watchdog_en_on2_wd_htotal_chg(data)                          (0x00000010&((data)<<4))
#define  ONMS_onms2_watchdog_en_on2_wd_hs_active_pixel_var(data)                 (0x00000008&((data)<<3))
#define  ONMS_onms2_watchdog_en_get_on2_wd_to_main(data)                         ((0x80000000&(data))>>31)
#define  ONMS_onms2_watchdog_en_get_on2_wd_to_sub(data)                          ((0x40000000&(data))>>30)
#define  ONMS_onms2_watchdog_en_get_on2_wd_hs_meas_over_range(data)              ((0x00200000&(data))>>21)
#define  ONMS_onms2_watchdog_en_get_on2_wd_vs_per_over_range(data)               ((0x00008000&(data))>>15)
#define  ONMS_onms2_watchdog_en_get_on2_wd_hs_per_over_range(data)               ((0x00004000&(data))>>14)
#define  ONMS_onms2_watchdog_en_get_on2_wd_vs_per_timeout(data)                  ((0x00002000&(data))>>13)
#define  ONMS_onms2_watchdog_en_get_on2_wd_vs_high_timeout(data)                 ((0x00001000&(data))>>12)
#define  ONMS_onms2_watchdog_en_get_on2_wd_vs_per_overflow(data)                 ((0x00000800&(data))>>11)
#define  ONMS_onms2_watchdog_en_get_on2_wd_hs_per_overflow(data)                 ((0x00000400&(data))>>10)
#define  ONMS_onms2_watchdog_en_get_on2_wd_vs_pol_chg(data)                      ((0x00000200&(data))>>9)
#define  ONMS_onms2_watchdog_en_get_on2_wd_hs_pol_chg(data)                      ((0x00000100&(data))>>8)
#define  ONMS_onms2_watchdog_en_get_on2_wd_vtotalde_chg(data)                    ((0x00000080&(data))>>7)
#define  ONMS_onms2_watchdog_en_get_on2_wd_vtotal_chg(data)                      ((0x00000040&(data))>>6)
#define  ONMS_onms2_watchdog_en_get_on2_wd_hact_chg(data)                        ((0x00000020&(data))>>5)
#define  ONMS_onms2_watchdog_en_get_on2_wd_htotal_chg(data)                      ((0x00000010&(data))>>4)
#define  ONMS_onms2_watchdog_en_get_on2_wd_hs_active_pixel_var(data)             ((0x00000008&(data))>>3)

#define  ONMS_onms2_interrupt_en                                                 0x18021370
#define  ONMS_onms2_interrupt_en_reg_addr                                        "0xB8021370"
#define  ONMS_onms2_interrupt_en_reg                                             0xB8021370
#define  ONMS_onms2_interrupt_en_inst_addr                                       "0x0034"
#define  set_ONMS_onms2_interrupt_en_reg(data)                                   (*((volatile unsigned int*)ONMS_onms2_interrupt_en_reg)=data)
#define  get_ONMS_onms2_interrupt_en_reg                                         (*((volatile unsigned int*)ONMS_onms2_interrupt_en_reg))
#define  ONMS_onms2_interrupt_en_on2_ie_to_main_shift                            (31)
#define  ONMS_onms2_interrupt_en_on2_ie_hs_meas_over_range_shift                 (21)
#define  ONMS_onms2_interrupt_en_on2_ie_vs_per_over_range_shift                  (15)
#define  ONMS_onms2_interrupt_en_on2_ie_hs_per_over_range_shift                  (14)
#define  ONMS_onms2_interrupt_en_on2_ie_vs_per_timeout_shift                     (13)
#define  ONMS_onms2_interrupt_en_on2_ie_vs_high_timeout_shift                    (12)
#define  ONMS_onms2_interrupt_en_on2_ie_vs_per_overflow_shift                    (11)
#define  ONMS_onms2_interrupt_en_on2_ie_hs_per_overflow_shift                    (10)
#define  ONMS_onms2_interrupt_en_on2_ie_vs_pol_chg_shift                         (9)
#define  ONMS_onms2_interrupt_en_on2_ie_hs_pol_chg_shift                         (8)
#define  ONMS_onms2_interrupt_en_on2_ie_vtotalde_chg_shift                       (7)
#define  ONMS_onms2_interrupt_en_on2_ie_vtotal_chg_shift                         (6)
#define  ONMS_onms2_interrupt_en_on2_ie_hact_chg_shift                           (5)
#define  ONMS_onms2_interrupt_en_on2_ie_htotal_chg_shift                         (4)
#define  ONMS_onms2_interrupt_en_on2_ie_hs_active_pixel_var_shift                (3)
#define  ONMS_onms2_interrupt_en_on2_ie_to_main_mask                             (0x80000000)
#define  ONMS_onms2_interrupt_en_on2_ie_hs_meas_over_range_mask                  (0x00200000)
#define  ONMS_onms2_interrupt_en_on2_ie_vs_per_over_range_mask                   (0x00008000)
#define  ONMS_onms2_interrupt_en_on2_ie_hs_per_over_range_mask                   (0x00004000)
#define  ONMS_onms2_interrupt_en_on2_ie_vs_per_timeout_mask                      (0x00002000)
#define  ONMS_onms2_interrupt_en_on2_ie_vs_high_timeout_mask                     (0x00001000)
#define  ONMS_onms2_interrupt_en_on2_ie_vs_per_overflow_mask                     (0x00000800)
#define  ONMS_onms2_interrupt_en_on2_ie_hs_per_overflow_mask                     (0x00000400)
#define  ONMS_onms2_interrupt_en_on2_ie_vs_pol_chg_mask                          (0x00000200)
#define  ONMS_onms2_interrupt_en_on2_ie_hs_pol_chg_mask                          (0x00000100)
#define  ONMS_onms2_interrupt_en_on2_ie_vtotalde_chg_mask                        (0x00000080)
#define  ONMS_onms2_interrupt_en_on2_ie_vtotal_chg_mask                          (0x00000040)
#define  ONMS_onms2_interrupt_en_on2_ie_hact_chg_mask                            (0x00000020)
#define  ONMS_onms2_interrupt_en_on2_ie_htotal_chg_mask                          (0x00000010)
#define  ONMS_onms2_interrupt_en_on2_ie_hs_active_pixel_var_mask                 (0x00000008)
#define  ONMS_onms2_interrupt_en_on2_ie_to_main(data)                            (0x80000000&((data)<<31))
#define  ONMS_onms2_interrupt_en_on2_ie_hs_meas_over_range(data)                 (0x00200000&((data)<<21))
#define  ONMS_onms2_interrupt_en_on2_ie_vs_per_over_range(data)                  (0x00008000&((data)<<15))
#define  ONMS_onms2_interrupt_en_on2_ie_hs_per_over_range(data)                  (0x00004000&((data)<<14))
#define  ONMS_onms2_interrupt_en_on2_ie_vs_per_timeout(data)                     (0x00002000&((data)<<13))
#define  ONMS_onms2_interrupt_en_on2_ie_vs_high_timeout(data)                    (0x00001000&((data)<<12))
#define  ONMS_onms2_interrupt_en_on2_ie_vs_per_overflow(data)                    (0x00000800&((data)<<11))
#define  ONMS_onms2_interrupt_en_on2_ie_hs_per_overflow(data)                    (0x00000400&((data)<<10))
#define  ONMS_onms2_interrupt_en_on2_ie_vs_pol_chg(data)                         (0x00000200&((data)<<9))
#define  ONMS_onms2_interrupt_en_on2_ie_hs_pol_chg(data)                         (0x00000100&((data)<<8))
#define  ONMS_onms2_interrupt_en_on2_ie_vtotalde_chg(data)                       (0x00000080&((data)<<7))
#define  ONMS_onms2_interrupt_en_on2_ie_vtotal_chg(data)                         (0x00000040&((data)<<6))
#define  ONMS_onms2_interrupt_en_on2_ie_hact_chg(data)                           (0x00000020&((data)<<5))
#define  ONMS_onms2_interrupt_en_on2_ie_htotal_chg(data)                         (0x00000010&((data)<<4))
#define  ONMS_onms2_interrupt_en_on2_ie_hs_active_pixel_var(data)                (0x00000008&((data)<<3))
#define  ONMS_onms2_interrupt_en_get_on2_ie_to_main(data)                        ((0x80000000&(data))>>31)
#define  ONMS_onms2_interrupt_en_get_on2_ie_hs_meas_over_range(data)             ((0x00200000&(data))>>21)
#define  ONMS_onms2_interrupt_en_get_on2_ie_vs_per_over_range(data)              ((0x00008000&(data))>>15)
#define  ONMS_onms2_interrupt_en_get_on2_ie_hs_per_over_range(data)              ((0x00004000&(data))>>14)
#define  ONMS_onms2_interrupt_en_get_on2_ie_vs_per_timeout(data)                 ((0x00002000&(data))>>13)
#define  ONMS_onms2_interrupt_en_get_on2_ie_vs_high_timeout(data)                ((0x00001000&(data))>>12)
#define  ONMS_onms2_interrupt_en_get_on2_ie_vs_per_overflow(data)                ((0x00000800&(data))>>11)
#define  ONMS_onms2_interrupt_en_get_on2_ie_hs_per_overflow(data)                ((0x00000400&(data))>>10)
#define  ONMS_onms2_interrupt_en_get_on2_ie_vs_pol_chg(data)                     ((0x00000200&(data))>>9)
#define  ONMS_onms2_interrupt_en_get_on2_ie_hs_pol_chg(data)                     ((0x00000100&(data))>>8)
#define  ONMS_onms2_interrupt_en_get_on2_ie_vtotalde_chg(data)                   ((0x00000080&(data))>>7)
#define  ONMS_onms2_interrupt_en_get_on2_ie_vtotal_chg(data)                     ((0x00000040&(data))>>6)
#define  ONMS_onms2_interrupt_en_get_on2_ie_hact_chg(data)                       ((0x00000020&(data))>>5)
#define  ONMS_onms2_interrupt_en_get_on2_ie_htotal_chg(data)                     ((0x00000010&(data))>>4)
#define  ONMS_onms2_interrupt_en_get_on2_ie_hs_active_pixel_var(data)            ((0x00000008&(data))>>3)

#define  ONMS_onms3_ctrl                                                         0x18021400
#define  ONMS_onms3_ctrl_reg_addr                                                "0xB8021400"
#define  ONMS_onms3_ctrl_reg                                                     0xB8021400
#define  ONMS_onms3_ctrl_inst_addr                                               "0x0035"
#define  set_ONMS_onms3_ctrl_reg(data)                                           (*((volatile unsigned int*)ONMS_onms3_ctrl_reg)=data)
#define  get_ONMS_onms3_ctrl_reg                                                 (*((volatile unsigned int*)ONMS_onms3_ctrl_reg))
#define  ONMS_onms3_ctrl_on3_4k2k_mode_shift                                     (30)
#define  ONMS_onms3_ctrl_on3_ms_src_sel_shift                                    (29)
#define  ONMS_onms3_ctrl_on3_blk_2frame_en_shift                                 (28)
#define  ONMS_onms3_ctrl_on3_pixel_get_en_shift                                  (27)
#define  ONMS_onms3_ctrl_on3_pixel_get_sel_shift                                 (25)
#define  ONMS_onms3_ctrl_on3_progressive_shift                                   (24)
#define  ONMS_onms3_ctrl_on3_vtotal_max_delta_shift                              (20)
#define  ONMS_onms3_ctrl_on3_htotal_max_delta_shift                              (16)
#define  ONMS_onms3_ctrl_dummy_15_shift                                          (15)
#define  ONMS_onms3_ctrl_dummy_14_shift                                          (14)
#define  ONMS_onms3_ctrl_dummy_13_shift                                          (13)
#define  ONMS_onms3_ctrl_on3_pixel_encoding_shift                                (12)
#define  ONMS_onms3_ctrl_on3_vact_space_threshold_shift                          (8)
#define  ONMS_onms3_ctrl_on3_vact_space_meas_en_shift                            (7)
#define  ONMS_onms3_ctrl_on3_meas_to_sel_shift                                   (6)
#define  ONMS_onms3_ctrl_on3_sycms_clk_shift                                     (5)
#define  ONMS_onms3_ctrl_on3_vs_meas_inv_shift                                   (4)
#define  ONMS_onms3_ctrl_on3_hs_meas_inv_shift                                   (3)
#define  ONMS_onms3_ctrl_on3_popup_meas_shift                                    (2)
#define  ONMS_onms3_ctrl_on3_ms_conti_shift                                      (1)
#define  ONMS_onms3_ctrl_on3_start_ms_shift                                      (0)
#define  ONMS_onms3_ctrl_on3_4k2k_mode_mask                                      (0xC0000000)
#define  ONMS_onms3_ctrl_on3_ms_src_sel_mask                                     (0x20000000)
#define  ONMS_onms3_ctrl_on3_blk_2frame_en_mask                                  (0x10000000)
#define  ONMS_onms3_ctrl_on3_pixel_get_en_mask                                   (0x08000000)
#define  ONMS_onms3_ctrl_on3_pixel_get_sel_mask                                  (0x06000000)
#define  ONMS_onms3_ctrl_on3_progressive_mask                                    (0x01000000)
#define  ONMS_onms3_ctrl_on3_vtotal_max_delta_mask                               (0x00F00000)
#define  ONMS_onms3_ctrl_on3_htotal_max_delta_mask                               (0x000F0000)
#define  ONMS_onms3_ctrl_dummy_15_mask                                           (0x00008000)
#define  ONMS_onms3_ctrl_dummy_14_mask                                           (0x00004000)
#define  ONMS_onms3_ctrl_dummy_13_mask                                           (0x00002000)
#define  ONMS_onms3_ctrl_on3_pixel_encoding_mask                                 (0x00001000)
#define  ONMS_onms3_ctrl_on3_vact_space_threshold_mask                           (0x00000F00)
#define  ONMS_onms3_ctrl_on3_vact_space_meas_en_mask                             (0x00000080)
#define  ONMS_onms3_ctrl_on3_meas_to_sel_mask                                    (0x00000040)
#define  ONMS_onms3_ctrl_on3_sycms_clk_mask                                      (0x00000020)
#define  ONMS_onms3_ctrl_on3_vs_meas_inv_mask                                    (0x00000010)
#define  ONMS_onms3_ctrl_on3_hs_meas_inv_mask                                    (0x00000008)
#define  ONMS_onms3_ctrl_on3_popup_meas_mask                                     (0x00000004)
#define  ONMS_onms3_ctrl_on3_ms_conti_mask                                       (0x00000002)
#define  ONMS_onms3_ctrl_on3_start_ms_mask                                       (0x00000001)
#define  ONMS_onms3_ctrl_on3_4k2k_mode(data)                                     (0xC0000000&((data)<<30))
#define  ONMS_onms3_ctrl_on3_ms_src_sel(data)                                    (0x20000000&((data)<<29))
#define  ONMS_onms3_ctrl_on3_blk_2frame_en(data)                                 (0x10000000&((data)<<28))
#define  ONMS_onms3_ctrl_on3_pixel_get_en(data)                                  (0x08000000&((data)<<27))
#define  ONMS_onms3_ctrl_on3_pixel_get_sel(data)                                 (0x06000000&((data)<<25))
#define  ONMS_onms3_ctrl_on3_progressive(data)                                   (0x01000000&((data)<<24))
#define  ONMS_onms3_ctrl_on3_vtotal_max_delta(data)                              (0x00F00000&((data)<<20))
#define  ONMS_onms3_ctrl_on3_htotal_max_delta(data)                              (0x000F0000&((data)<<16))
#define  ONMS_onms3_ctrl_dummy_15(data)                                          (0x00008000&((data)<<15))
#define  ONMS_onms3_ctrl_dummy_14(data)                                          (0x00004000&((data)<<14))
#define  ONMS_onms3_ctrl_dummy_13(data)                                          (0x00002000&((data)<<13))
#define  ONMS_onms3_ctrl_on3_pixel_encoding(data)                                (0x00001000&((data)<<12))
#define  ONMS_onms3_ctrl_on3_vact_space_threshold(data)                          (0x00000F00&((data)<<8))
#define  ONMS_onms3_ctrl_on3_vact_space_meas_en(data)                            (0x00000080&((data)<<7))
#define  ONMS_onms3_ctrl_on3_meas_to_sel(data)                                   (0x00000040&((data)<<6))
#define  ONMS_onms3_ctrl_on3_sycms_clk(data)                                     (0x00000020&((data)<<5))
#define  ONMS_onms3_ctrl_on3_vs_meas_inv(data)                                   (0x00000010&((data)<<4))
#define  ONMS_onms3_ctrl_on3_hs_meas_inv(data)                                   (0x00000008&((data)<<3))
#define  ONMS_onms3_ctrl_on3_popup_meas(data)                                    (0x00000004&((data)<<2))
#define  ONMS_onms3_ctrl_on3_ms_conti(data)                                      (0x00000002&((data)<<1))
#define  ONMS_onms3_ctrl_on3_start_ms(data)                                      (0x00000001&(data))
#define  ONMS_onms3_ctrl_get_on3_4k2k_mode(data)                                 ((0xC0000000&(data))>>30)
#define  ONMS_onms3_ctrl_get_on3_ms_src_sel(data)                                ((0x20000000&(data))>>29)
#define  ONMS_onms3_ctrl_get_on3_blk_2frame_en(data)                             ((0x10000000&(data))>>28)
#define  ONMS_onms3_ctrl_get_on3_pixel_get_en(data)                              ((0x08000000&(data))>>27)
#define  ONMS_onms3_ctrl_get_on3_pixel_get_sel(data)                             ((0x06000000&(data))>>25)
#define  ONMS_onms3_ctrl_get_on3_progressive(data)                               ((0x01000000&(data))>>24)
#define  ONMS_onms3_ctrl_get_on3_vtotal_max_delta(data)                          ((0x00F00000&(data))>>20)
#define  ONMS_onms3_ctrl_get_on3_htotal_max_delta(data)                          ((0x000F0000&(data))>>16)
#define  ONMS_onms3_ctrl_get_dummy_15(data)                                      ((0x00008000&(data))>>15)
#define  ONMS_onms3_ctrl_get_dummy_14(data)                                      ((0x00004000&(data))>>14)
#define  ONMS_onms3_ctrl_get_dummy_13(data)                                      ((0x00002000&(data))>>13)
#define  ONMS_onms3_ctrl_get_on3_pixel_encoding(data)                            ((0x00001000&(data))>>12)
#define  ONMS_onms3_ctrl_get_on3_vact_space_threshold(data)                      ((0x00000F00&(data))>>8)
#define  ONMS_onms3_ctrl_get_on3_vact_space_meas_en(data)                        ((0x00000080&(data))>>7)
#define  ONMS_onms3_ctrl_get_on3_meas_to_sel(data)                               ((0x00000040&(data))>>6)
#define  ONMS_onms3_ctrl_get_on3_sycms_clk(data)                                 ((0x00000020&(data))>>5)
#define  ONMS_onms3_ctrl_get_on3_vs_meas_inv(data)                               ((0x00000010&(data))>>4)
#define  ONMS_onms3_ctrl_get_on3_hs_meas_inv(data)                               ((0x00000008&(data))>>3)
#define  ONMS_onms3_ctrl_get_on3_popup_meas(data)                                ((0x00000004&(data))>>2)
#define  ONMS_onms3_ctrl_get_on3_ms_conti(data)                                  ((0x00000002&(data))>>1)
#define  ONMS_onms3_ctrl_get_on3_start_ms(data)                                  (0x00000001&(data))

#define  ONMS_onms3_blank_pixel_value_get_0                                      0x18021404
#define  ONMS_onms3_blank_pixel_value_get_0_reg_addr                             "0xB8021404"
#define  ONMS_onms3_blank_pixel_value_get_0_reg                                  0xB8021404
#define  ONMS_onms3_blank_pixel_value_get_0_inst_addr                            "0x0036"
#define  set_ONMS_onms3_blank_pixel_value_get_0_reg(data)                        (*((volatile unsigned int*)ONMS_onms3_blank_pixel_value_get_0_reg)=data)
#define  get_ONMS_onms3_blank_pixel_value_get_0_reg                              (*((volatile unsigned int*)ONMS_onms3_blank_pixel_value_get_0_reg))
#define  ONMS_onms3_blank_pixel_value_get_0_on3_pixel_ok_shift                   (24)
#define  ONMS_onms3_blank_pixel_value_get_0_on3_get_r_value_shift                (12)
#define  ONMS_onms3_blank_pixel_value_get_0_on3_get_g_value_shift                (0)
#define  ONMS_onms3_blank_pixel_value_get_0_on3_pixel_ok_mask                    (0x01000000)
#define  ONMS_onms3_blank_pixel_value_get_0_on3_get_r_value_mask                 (0x00FFF000)
#define  ONMS_onms3_blank_pixel_value_get_0_on3_get_g_value_mask                 (0x00000FFF)
#define  ONMS_onms3_blank_pixel_value_get_0_on3_pixel_ok(data)                   (0x01000000&((data)<<24))
#define  ONMS_onms3_blank_pixel_value_get_0_on3_get_r_value(data)                (0x00FFF000&((data)<<12))
#define  ONMS_onms3_blank_pixel_value_get_0_on3_get_g_value(data)                (0x00000FFF&(data))
#define  ONMS_onms3_blank_pixel_value_get_0_get_on3_pixel_ok(data)               ((0x01000000&(data))>>24)
#define  ONMS_onms3_blank_pixel_value_get_0_get_on3_get_r_value(data)            ((0x00FFF000&(data))>>12)
#define  ONMS_onms3_blank_pixel_value_get_0_get_on3_get_g_value(data)            (0x00000FFF&(data))

#define  ONMS_onms3_blank_pixel_value_get_1                                      0x18021408
#define  ONMS_onms3_blank_pixel_value_get_1_reg_addr                             "0xB8021408"
#define  ONMS_onms3_blank_pixel_value_get_1_reg                                  0xB8021408
#define  ONMS_onms3_blank_pixel_value_get_1_inst_addr                            "0x0037"
#define  set_ONMS_onms3_blank_pixel_value_get_1_reg(data)                        (*((volatile unsigned int*)ONMS_onms3_blank_pixel_value_get_1_reg)=data)
#define  get_ONMS_onms3_blank_pixel_value_get_1_reg                              (*((volatile unsigned int*)ONMS_onms3_blank_pixel_value_get_1_reg))
#define  ONMS_onms3_blank_pixel_value_get_1_on3_get_b_value_shift                (0)
#define  ONMS_onms3_blank_pixel_value_get_1_on3_get_b_value_mask                 (0x00000FFF)
#define  ONMS_onms3_blank_pixel_value_get_1_on3_get_b_value(data)                (0x00000FFF&(data))
#define  ONMS_onms3_blank_pixel_value_get_1_get_on3_get_b_value(data)            (0x00000FFF&(data))

#define  ONMS_onms3_blank_pixel_value_0                                          0x1802140C
#define  ONMS_onms3_blank_pixel_value_0_reg_addr                                 "0xB802140C"
#define  ONMS_onms3_blank_pixel_value_0_reg                                      0xB802140C
#define  ONMS_onms3_blank_pixel_value_0_inst_addr                                "0x0038"
#define  set_ONMS_onms3_blank_pixel_value_0_reg(data)                            (*((volatile unsigned int*)ONMS_onms3_blank_pixel_value_0_reg)=data)
#define  get_ONMS_onms3_blank_pixel_value_0_reg                                  (*((volatile unsigned int*)ONMS_onms3_blank_pixel_value_0_reg))
#define  ONMS_onms3_blank_pixel_value_0_on3_active_r_value_shift                 (12)
#define  ONMS_onms3_blank_pixel_value_0_on3_active_g_value_shift                 (0)
#define  ONMS_onms3_blank_pixel_value_0_on3_active_r_value_mask                  (0x00FFF000)
#define  ONMS_onms3_blank_pixel_value_0_on3_active_g_value_mask                  (0x00000FFF)
#define  ONMS_onms3_blank_pixel_value_0_on3_active_r_value(data)                 (0x00FFF000&((data)<<12))
#define  ONMS_onms3_blank_pixel_value_0_on3_active_g_value(data)                 (0x00000FFF&(data))
#define  ONMS_onms3_blank_pixel_value_0_get_on3_active_r_value(data)             ((0x00FFF000&(data))>>12)
#define  ONMS_onms3_blank_pixel_value_0_get_on3_active_g_value(data)             (0x00000FFF&(data))

#define  ONMS_onms3_blank_pixel_value_1                                          0x18021410
#define  ONMS_onms3_blank_pixel_value_1_reg_addr                                 "0xB8021410"
#define  ONMS_onms3_blank_pixel_value_1_reg                                      0xB8021410
#define  ONMS_onms3_blank_pixel_value_1_inst_addr                                "0x0039"
#define  set_ONMS_onms3_blank_pixel_value_1_reg(data)                            (*((volatile unsigned int*)ONMS_onms3_blank_pixel_value_1_reg)=data)
#define  get_ONMS_onms3_blank_pixel_value_1_reg                                  (*((volatile unsigned int*)ONMS_onms3_blank_pixel_value_1_reg))
#define  ONMS_onms3_blank_pixel_value_1_on3_active_b_value_shift                 (0)
#define  ONMS_onms3_blank_pixel_value_1_on3_active_b_value_mask                  (0x00000FFF)
#define  ONMS_onms3_blank_pixel_value_1_on3_active_b_value(data)                 (0x00000FFF&(data))
#define  ONMS_onms3_blank_pixel_value_1_get_on3_active_b_value(data)             (0x00000FFF&(data))

#define  ONMS_onms3_fp_vact12                                                    0x18021414
#define  ONMS_onms3_fp_vact12_reg_addr                                           "0xB8021414"
#define  ONMS_onms3_fp_vact12_reg                                                0xB8021414
#define  ONMS_onms3_fp_vact12_inst_addr                                          "0x003A"
#define  set_ONMS_onms3_fp_vact12_reg(data)                                      (*((volatile unsigned int*)ONMS_onms3_fp_vact12_reg)=data)
#define  get_ONMS_onms3_fp_vact12_reg                                            (*((volatile unsigned int*)ONMS_onms3_fp_vact12_reg))
#define  ONMS_onms3_fp_vact12_on3_vact2_shift                                    (16)
#define  ONMS_onms3_fp_vact12_on3_vact1_shift                                    (0)
#define  ONMS_onms3_fp_vact12_on3_vact2_mask                                     (0x07FF0000)
#define  ONMS_onms3_fp_vact12_on3_vact1_mask                                     (0x000007FF)
#define  ONMS_onms3_fp_vact12_on3_vact2(data)                                    (0x07FF0000&((data)<<16))
#define  ONMS_onms3_fp_vact12_on3_vact1(data)                                    (0x000007FF&(data))
#define  ONMS_onms3_fp_vact12_get_on3_vact2(data)                                ((0x07FF0000&(data))>>16)
#define  ONMS_onms3_fp_vact12_get_on3_vact1(data)                                (0x000007FF&(data))

#define  ONMS_onms3_fp_vact34                                                    0x18021418
#define  ONMS_onms3_fp_vact34_reg_addr                                           "0xB8021418"
#define  ONMS_onms3_fp_vact34_reg                                                0xB8021418
#define  ONMS_onms3_fp_vact34_inst_addr                                          "0x003B"
#define  set_ONMS_onms3_fp_vact34_reg(data)                                      (*((volatile unsigned int*)ONMS_onms3_fp_vact34_reg)=data)
#define  get_ONMS_onms3_fp_vact34_reg                                            (*((volatile unsigned int*)ONMS_onms3_fp_vact34_reg))
#define  ONMS_onms3_fp_vact34_on3_vact4_shift                                    (16)
#define  ONMS_onms3_fp_vact34_on3_vact3_shift                                    (0)
#define  ONMS_onms3_fp_vact34_on3_vact4_mask                                     (0x07FF0000)
#define  ONMS_onms3_fp_vact34_on3_vact3_mask                                     (0x000007FF)
#define  ONMS_onms3_fp_vact34_on3_vact4(data)                                    (0x07FF0000&((data)<<16))
#define  ONMS_onms3_fp_vact34_on3_vact3(data)                                    (0x000007FF&(data))
#define  ONMS_onms3_fp_vact34_get_on3_vact4(data)                                ((0x07FF0000&(data))>>16)
#define  ONMS_onms3_fp_vact34_get_on3_vact3(data)                                (0x000007FF&(data))

#define  ONMS_onms3_fp_vact_space                                                0x1802141C
#define  ONMS_onms3_fp_vact_space_reg_addr                                       "0xB802141C"
#define  ONMS_onms3_fp_vact_space_reg                                            0xB802141C
#define  ONMS_onms3_fp_vact_space_inst_addr                                      "0x003C"
#define  set_ONMS_onms3_fp_vact_space_reg(data)                                  (*((volatile unsigned int*)ONMS_onms3_fp_vact_space_reg)=data)
#define  get_ONMS_onms3_fp_vact_space_reg                                        (*((volatile unsigned int*)ONMS_onms3_fp_vact_space_reg))
#define  ONMS_onms3_fp_vact_space_on3_fp_vact_space1_shift                       (20)
#define  ONMS_onms3_fp_vact_space_on3_fp_vact_space2_shift                       (10)
#define  ONMS_onms3_fp_vact_space_on3_fp_vact_space3_shift                       (0)
#define  ONMS_onms3_fp_vact_space_on3_fp_vact_space1_mask                        (0x3FF00000)
#define  ONMS_onms3_fp_vact_space_on3_fp_vact_space2_mask                        (0x000FFC00)
#define  ONMS_onms3_fp_vact_space_on3_fp_vact_space3_mask                        (0x000003FF)
#define  ONMS_onms3_fp_vact_space_on3_fp_vact_space1(data)                       (0x3FF00000&((data)<<20))
#define  ONMS_onms3_fp_vact_space_on3_fp_vact_space2(data)                       (0x000FFC00&((data)<<10))
#define  ONMS_onms3_fp_vact_space_on3_fp_vact_space3(data)                       (0x000003FF&(data))
#define  ONMS_onms3_fp_vact_space_get_on3_fp_vact_space1(data)                   ((0x3FF00000&(data))>>20)
#define  ONMS_onms3_fp_vact_space_get_on3_fp_vact_space2(data)                   ((0x000FFC00&(data))>>10)
#define  ONMS_onms3_fp_vact_space_get_on3_fp_vact_space3(data)                   (0x000003FF&(data))

#define  ONMS_onms3_blank_line                                                   0x18021420
#define  ONMS_onms3_blank_line_reg_addr                                          "0xB8021420"
#define  ONMS_onms3_blank_line_reg                                               0xB8021420
#define  ONMS_onms3_blank_line_inst_addr                                         "0x003D"
#define  set_ONMS_onms3_blank_line_reg(data)                                     (*((volatile unsigned int*)ONMS_onms3_blank_line_reg)=data)
#define  get_ONMS_onms3_blank_line_reg                                           (*((volatile unsigned int*)ONMS_onms3_blank_line_reg))
#define  ONMS_onms3_blank_line_on3_r_blank_line_start_shift                      (16)
#define  ONMS_onms3_blank_line_on3_l_blank_line_end_shift                        (0)
#define  ONMS_onms3_blank_line_on3_r_blank_line_start_mask                       (0x07FF0000)
#define  ONMS_onms3_blank_line_on3_l_blank_line_end_mask                         (0x000007FF)
#define  ONMS_onms3_blank_line_on3_r_blank_line_start(data)                      (0x07FF0000&((data)<<16))
#define  ONMS_onms3_blank_line_on3_l_blank_line_end(data)                        (0x000007FF&(data))
#define  ONMS_onms3_blank_line_get_on3_r_blank_line_start(data)                  ((0x07FF0000&(data))>>16)
#define  ONMS_onms3_blank_line_get_on3_l_blank_line_end(data)                    (0x000007FF&(data))

#define  ONMS_onms3_active_space1_line_number                                    0x18021424
#define  ONMS_onms3_active_space1_line_number_reg_addr                           "0xB8021424"
#define  ONMS_onms3_active_space1_line_number_reg                                0xB8021424
#define  ONMS_onms3_active_space1_line_number_inst_addr                          "0x003E"
#define  set_ONMS_onms3_active_space1_line_number_reg(data)                      (*((volatile unsigned int*)ONMS_onms3_active_space1_line_number_reg)=data)
#define  get_ONMS_onms3_active_space1_line_number_reg                            (*((volatile unsigned int*)ONMS_onms3_active_space1_line_number_reg))
#define  ONMS_onms3_active_space1_line_number_on3_vact_space1_end_shift          (16)
#define  ONMS_onms3_active_space1_line_number_on3_vact_space1_start_shift        (0)
#define  ONMS_onms3_active_space1_line_number_on3_vact_space1_end_mask           (0x03FF0000)
#define  ONMS_onms3_active_space1_line_number_on3_vact_space1_start_mask         (0x000003FF)
#define  ONMS_onms3_active_space1_line_number_on3_vact_space1_end(data)          (0x03FF0000&((data)<<16))
#define  ONMS_onms3_active_space1_line_number_on3_vact_space1_start(data)        (0x000003FF&(data))
#define  ONMS_onms3_active_space1_line_number_get_on3_vact_space1_end(data)      ((0x03FF0000&(data))>>16)
#define  ONMS_onms3_active_space1_line_number_get_on3_vact_space1_start(data)    (0x000003FF&(data))

#define  ONMS_onms3_active_space2_line_number                                    0x18021428
#define  ONMS_onms3_active_space2_line_number_reg_addr                           "0xB8021428"
#define  ONMS_onms3_active_space2_line_number_reg                                0xB8021428
#define  ONMS_onms3_active_space2_line_number_inst_addr                          "0x003F"
#define  set_ONMS_onms3_active_space2_line_number_reg(data)                      (*((volatile unsigned int*)ONMS_onms3_active_space2_line_number_reg)=data)
#define  get_ONMS_onms3_active_space2_line_number_reg                            (*((volatile unsigned int*)ONMS_onms3_active_space2_line_number_reg))
#define  ONMS_onms3_active_space2_line_number_on3_vact_space2_end_shift          (16)
#define  ONMS_onms3_active_space2_line_number_on3_vact_space2_start_shift        (0)
#define  ONMS_onms3_active_space2_line_number_on3_vact_space2_end_mask           (0x03FF0000)
#define  ONMS_onms3_active_space2_line_number_on3_vact_space2_start_mask         (0x000003FF)
#define  ONMS_onms3_active_space2_line_number_on3_vact_space2_end(data)          (0x03FF0000&((data)<<16))
#define  ONMS_onms3_active_space2_line_number_on3_vact_space2_start(data)        (0x000003FF&(data))
#define  ONMS_onms3_active_space2_line_number_get_on3_vact_space2_end(data)      ((0x03FF0000&(data))>>16)
#define  ONMS_onms3_active_space2_line_number_get_on3_vact_space2_start(data)    (0x000003FF&(data))

#define  ONMS_onms3_active_space3_line_number                                    0x1802142C
#define  ONMS_onms3_active_space3_line_number_reg_addr                           "0xB802142C"
#define  ONMS_onms3_active_space3_line_number_reg                                0xB802142C
#define  ONMS_onms3_active_space3_line_number_inst_addr                          "0x0040"
#define  set_ONMS_onms3_active_space3_line_number_reg(data)                      (*((volatile unsigned int*)ONMS_onms3_active_space3_line_number_reg)=data)
#define  get_ONMS_onms3_active_space3_line_number_reg                            (*((volatile unsigned int*)ONMS_onms3_active_space3_line_number_reg))
#define  ONMS_onms3_active_space3_line_number_on3_vact_space3_end_shift          (16)
#define  ONMS_onms3_active_space3_line_number_on3_vact_space3_start_shift        (0)
#define  ONMS_onms3_active_space3_line_number_on3_vact_space3_end_mask           (0x03FF0000)
#define  ONMS_onms3_active_space3_line_number_on3_vact_space3_start_mask         (0x000003FF)
#define  ONMS_onms3_active_space3_line_number_on3_vact_space3_end(data)          (0x03FF0000&((data)<<16))
#define  ONMS_onms3_active_space3_line_number_on3_vact_space3_start(data)        (0x000003FF&(data))
#define  ONMS_onms3_active_space3_line_number_get_on3_vact_space3_end(data)      ((0x03FF0000&(data))>>16)
#define  ONMS_onms3_active_space3_line_number_get_on3_vact_space3_start(data)    (0x000003FF&(data))

#define  ONMS_onms3_vs_period                                                    0x18021430
#define  ONMS_onms3_vs_period_reg_addr                                           "0xB8021430"
#define  ONMS_onms3_vs_period_reg                                                0xB8021430
#define  ONMS_onms3_vs_period_inst_addr                                          "0x0041"
#define  set_ONMS_onms3_vs_period_reg(data)                                      (*((volatile unsigned int*)ONMS_onms3_vs_period_reg)=data)
#define  get_ONMS_onms3_vs_period_reg                                            (*((volatile unsigned int*)ONMS_onms3_vs_period_reg))
#define  ONMS_onms3_vs_period_on3_vtotalde_shift                                 (16)
#define  ONMS_onms3_vs_period_on3_vtotal_shift                                   (0)
#define  ONMS_onms3_vs_period_on3_vtotalde_mask                                  (0x1FFF0000)
#define  ONMS_onms3_vs_period_on3_vtotal_mask                                    (0x00003FFF)
#define  ONMS_onms3_vs_period_on3_vtotalde(data)                                 (0x1FFF0000&((data)<<16))
#define  ONMS_onms3_vs_period_on3_vtotal(data)                                   (0x00003FFF&(data))
#define  ONMS_onms3_vs_period_get_on3_vtotalde(data)                             ((0x1FFF0000&(data))>>16)
#define  ONMS_onms3_vs_period_get_on3_vtotal(data)                               (0x00003FFF&(data))

#define  ONMS_onms3_vshs_high_period                                             0x18021434
#define  ONMS_onms3_vshs_high_period_reg_addr                                    "0xB8021434"
#define  ONMS_onms3_vshs_high_period_reg                                         0xB8021434
#define  ONMS_onms3_vshs_high_period_inst_addr                                   "0x0042"
#define  set_ONMS_onms3_vshs_high_period_reg(data)                               (*((volatile unsigned int*)ONMS_onms3_vshs_high_period_reg)=data)
#define  get_ONMS_onms3_vshs_high_period_reg                                     (*((volatile unsigned int*)ONMS_onms3_vshs_high_period_reg))
#define  ONMS_onms3_vshs_high_period_on3_vs_high_period_shift                    (16)
#define  ONMS_onms3_vshs_high_period_on3_hs_high_period_shift                    (0)
#define  ONMS_onms3_vshs_high_period_on3_vs_high_period_mask                     (0x0FFF0000)
#define  ONMS_onms3_vshs_high_period_on3_hs_high_period_mask                     (0x00003FFF)
#define  ONMS_onms3_vshs_high_period_on3_vs_high_period(data)                    (0x0FFF0000&((data)<<16))
#define  ONMS_onms3_vshs_high_period_on3_hs_high_period(data)                    (0x00003FFF&(data))
#define  ONMS_onms3_vshs_high_period_get_on3_vs_high_period(data)                ((0x0FFF0000&(data))>>16)
#define  ONMS_onms3_vshs_high_period_get_on3_hs_high_period(data)                (0x00003FFF&(data))

#define  ONMS_onms3_hs_period                                                    0x18021438
#define  ONMS_onms3_hs_period_reg_addr                                           "0xB8021438"
#define  ONMS_onms3_hs_period_reg                                                0xB8021438
#define  ONMS_onms3_hs_period_inst_addr                                          "0x0043"
#define  set_ONMS_onms3_hs_period_reg(data)                                      (*((volatile unsigned int*)ONMS_onms3_hs_period_reg)=data)
#define  get_ONMS_onms3_hs_period_reg                                            (*((volatile unsigned int*)ONMS_onms3_hs_period_reg))
#define  ONMS_onms3_hs_period_on3_htotal_h12b_shift                              (4)
#define  ONMS_onms3_hs_period_on3_htotal_f4b_shift                               (0)
#define  ONMS_onms3_hs_period_on3_htotal_h12b_mask                               (0x0003FFF0)
#define  ONMS_onms3_hs_period_on3_htotal_f4b_mask                                (0x0000000F)
#define  ONMS_onms3_hs_period_on3_htotal_h12b(data)                              (0x0003FFF0&((data)<<4))
#define  ONMS_onms3_hs_period_on3_htotal_f4b(data)                               (0x0000000F&(data))
#define  ONMS_onms3_hs_period_get_on3_htotal_h12b(data)                          ((0x0003FFF0&(data))>>4)
#define  ONMS_onms3_hs_period_get_on3_htotal_f4b(data)                           (0x0000000F&(data))

#define  ONMS_onms3_vact_sta                                                     0x1802143C
#define  ONMS_onms3_vact_sta_reg_addr                                            "0xB802143C"
#define  ONMS_onms3_vact_sta_reg                                                 0xB802143C
#define  ONMS_onms3_vact_sta_inst_addr                                           "0x0044"
#define  set_ONMS_onms3_vact_sta_reg(data)                                       (*((volatile unsigned int*)ONMS_onms3_vact_sta_reg)=data)
#define  get_ONMS_onms3_vact_sta_reg                                             (*((volatile unsigned int*)ONMS_onms3_vact_sta_reg))
#define  ONMS_onms3_vact_sta_on3_vblank_len_shift                                (16)
#define  ONMS_onms3_vact_sta_on3_vact_start_shift                                (0)
#define  ONMS_onms3_vact_sta_on3_vblank_len_mask                                 (0x00FF0000)
#define  ONMS_onms3_vact_sta_on3_vact_start_mask                                 (0x00000FFF)
#define  ONMS_onms3_vact_sta_on3_vblank_len(data)                                (0x00FF0000&((data)<<16))
#define  ONMS_onms3_vact_sta_on3_vact_start(data)                                (0x00000FFF&(data))
#define  ONMS_onms3_vact_sta_get_on3_vblank_len(data)                            ((0x00FF0000&(data))>>16)
#define  ONMS_onms3_vact_sta_get_on3_vact_start(data)                            (0x00000FFF&(data))

#define  ONMS_onms3_hact_sta                                                     0x18021440
#define  ONMS_onms3_hact_sta_reg_addr                                            "0xB8021440"
#define  ONMS_onms3_hact_sta_reg                                                 0xB8021440
#define  ONMS_onms3_hact_sta_inst_addr                                           "0x0045"
#define  set_ONMS_onms3_hact_sta_reg(data)                                       (*((volatile unsigned int*)ONMS_onms3_hact_sta_reg)=data)
#define  get_ONMS_onms3_hact_sta_reg                                             (*((volatile unsigned int*)ONMS_onms3_hact_sta_reg))
#define  ONMS_onms3_hact_sta_on3_hact_start_shift                                (0)
#define  ONMS_onms3_hact_sta_on3_hact_start_mask                                 (0x00003FFF)
#define  ONMS_onms3_hact_sta_on3_hact_start(data)                                (0x00003FFF&(data))
#define  ONMS_onms3_hact_sta_get_on3_hact_start(data)                            (0x00003FFF&(data))

#define  ONMS_onms3_hact                                                         0x18021444
#define  ONMS_onms3_hact_reg_addr                                                "0xB8021444"
#define  ONMS_onms3_hact_reg                                                     0xB8021444
#define  ONMS_onms3_hact_inst_addr                                               "0x0046"
#define  set_ONMS_onms3_hact_reg(data)                                           (*((volatile unsigned int*)ONMS_onms3_hact_reg)=data)
#define  get_ONMS_onms3_hact_reg                                                 (*((volatile unsigned int*)ONMS_onms3_hact_reg))
#define  ONMS_onms3_hact_on3_hact_shift                                          (4)
#define  ONMS_onms3_hact_on3_hact_fract_shift                                    (0)
#define  ONMS_onms3_hact_on3_hact_mask                                           (0x0003FFF0)
#define  ONMS_onms3_hact_on3_hact_fract_mask                                     (0x0000000F)
#define  ONMS_onms3_hact_on3_hact(data)                                          (0x0003FFF0&((data)<<4))
#define  ONMS_onms3_hact_on3_hact_fract(data)                                    (0x0000000F&(data))
#define  ONMS_onms3_hact_get_on3_hact(data)                                      ((0x0003FFF0&(data))>>4)
#define  ONMS_onms3_hact_get_on3_hact_fract(data)                                (0x0000000F&(data))

#define  ONMS_onms3_hsync_meas_ctrl                                              0x1802145C
#define  ONMS_onms3_hsync_meas_ctrl_reg_addr                                     "0xB802145C"
#define  ONMS_onms3_hsync_meas_ctrl_reg                                          0xB802145C
#define  ONMS_onms3_hsync_meas_ctrl_inst_addr                                    "0x0047"
#define  set_ONMS_onms3_hsync_meas_ctrl_reg(data)                                (*((volatile unsigned int*)ONMS_onms3_hsync_meas_ctrl_reg)=data)
#define  get_ONMS_onms3_hsync_meas_ctrl_reg                                      (*((volatile unsigned int*)ONMS_onms3_hsync_meas_ctrl_reg))
#define  ONMS_onms3_hsync_meas_ctrl_on3_htotal_max_delta_new_shift               (24)
#define  ONMS_onms3_hsync_meas_ctrl_on3_average_line_shift                       (16)
#define  ONMS_onms3_hsync_meas_ctrl_on3_target_measure_shift                     (0)
#define  ONMS_onms3_hsync_meas_ctrl_on3_htotal_max_delta_new_mask                (0x7F000000)
#define  ONMS_onms3_hsync_meas_ctrl_on3_average_line_mask                        (0x000F0000)
#define  ONMS_onms3_hsync_meas_ctrl_on3_target_measure_mask                      (0x00003FFF)
#define  ONMS_onms3_hsync_meas_ctrl_on3_htotal_max_delta_new(data)               (0x7F000000&((data)<<24))
#define  ONMS_onms3_hsync_meas_ctrl_on3_average_line(data)                       (0x000F0000&((data)<<16))
#define  ONMS_onms3_hsync_meas_ctrl_on3_target_measure(data)                     (0x00003FFF&(data))
#define  ONMS_onms3_hsync_meas_ctrl_get_on3_htotal_max_delta_new(data)           ((0x7F000000&(data))>>24)
#define  ONMS_onms3_hsync_meas_ctrl_get_on3_average_line(data)                   ((0x000F0000&(data))>>16)
#define  ONMS_onms3_hsync_meas_ctrl_get_on3_target_measure(data)                 (0x00003FFF&(data))

#define  ONMS_onms3_hsync_meas_ctrl_2                                            0x18021460
#define  ONMS_onms3_hsync_meas_ctrl_2_reg_addr                                   "0xB8021460"
#define  ONMS_onms3_hsync_meas_ctrl_2_reg                                        0xB8021460
#define  ONMS_onms3_hsync_meas_ctrl_2_inst_addr                                  "0x0048"
#define  set_ONMS_onms3_hsync_meas_ctrl_2_reg(data)                              (*((volatile unsigned int*)ONMS_onms3_hsync_meas_ctrl_2_reg)=data)
#define  get_ONMS_onms3_hsync_meas_ctrl_2_reg                                    (*((volatile unsigned int*)ONMS_onms3_hsync_meas_ctrl_2_reg))
#define  ONMS_onms3_hsync_meas_ctrl_2_on3_vmeas_end_shift                        (16)
#define  ONMS_onms3_hsync_meas_ctrl_2_on3_vmeas_start_shift                      (0)
#define  ONMS_onms3_hsync_meas_ctrl_2_on3_vmeas_end_mask                         (0x0FFF0000)
#define  ONMS_onms3_hsync_meas_ctrl_2_on3_vmeas_start_mask                       (0x00000FFF)
#define  ONMS_onms3_hsync_meas_ctrl_2_on3_vmeas_end(data)                        (0x0FFF0000&((data)<<16))
#define  ONMS_onms3_hsync_meas_ctrl_2_on3_vmeas_start(data)                      (0x00000FFF&(data))
#define  ONMS_onms3_hsync_meas_ctrl_2_get_on3_vmeas_end(data)                    ((0x0FFF0000&(data))>>16)
#define  ONMS_onms3_hsync_meas_ctrl_2_get_on3_vmeas_start(data)                  (0x00000FFF&(data))

#define  ONMS_onms3_hsync_meas_result                                            0x18021464
#define  ONMS_onms3_hsync_meas_result_reg_addr                                   "0xB8021464"
#define  ONMS_onms3_hsync_meas_result_reg                                        0xB8021464
#define  ONMS_onms3_hsync_meas_result_inst_addr                                  "0x0049"
#define  set_ONMS_onms3_hsync_meas_result_reg(data)                              (*((volatile unsigned int*)ONMS_onms3_hsync_meas_result_reg)=data)
#define  get_ONMS_onms3_hsync_meas_result_reg                                    (*((volatile unsigned int*)ONMS_onms3_hsync_meas_result_reg))
#define  ONMS_onms3_hsync_meas_result_on3_hmax_delta_total_shift                 (0)
#define  ONMS_onms3_hsync_meas_result_on3_hmax_delta_total_mask                  (0x00003FFF)
#define  ONMS_onms3_hsync_meas_result_on3_hmax_delta_total(data)                 (0x00003FFF&(data))
#define  ONMS_onms3_hsync_meas_result_get_on3_hmax_delta_total(data)             (0x00003FFF&(data))

#define  ONMS_onms3_status                                                       0x18021468
#define  ONMS_onms3_status_reg_addr                                              "0xB8021468"
#define  ONMS_onms3_status_reg                                                   0xB8021468
#define  ONMS_onms3_status_inst_addr                                             "0x004A"
#define  set_ONMS_onms3_status_reg(data)                                         (*((volatile unsigned int*)ONMS_onms3_status_reg)=data)
#define  get_ONMS_onms3_status_reg                                               (*((volatile unsigned int*)ONMS_onms3_status_reg))
#define  ONMS_onms3_status_on3_hs_meas_over_range_shift                          (21)
#define  ONMS_onms3_status_on3_vs_per_to_long_shift                              (20)
#define  ONMS_onms3_status_on3_vs_pol_out_shift                                  (17)
#define  ONMS_onms3_status_on3_hs_pol_out_shift                                  (16)
#define  ONMS_onms3_status_on3_vs_per_over_range_shift                           (15)
#define  ONMS_onms3_status_on3_hs_per_over_range_shift                           (14)
#define  ONMS_onms3_status_on3_vs_per_timeout_shift                              (13)
#define  ONMS_onms3_status_on3_vs_high_timeout_shift                             (12)
#define  ONMS_onms3_status_on3_vs_per_overflow_shift                             (11)
#define  ONMS_onms3_status_on3_hs_per_overflow_shift                             (10)
#define  ONMS_onms3_status_on3_vs_pol_chg_shift                                  (9)
#define  ONMS_onms3_status_on3_hs_pol_chg_shift                                  (8)
#define  ONMS_onms3_status_on3_vtotalde_chg_shift                                (7)
#define  ONMS_onms3_status_on3_vtotal_chg_shift                                  (6)
#define  ONMS_onms3_status_on3_hact_chg_shift                                    (5)
#define  ONMS_onms3_status_on3_htotal_chg_shift                                  (4)
#define  ONMS_onms3_status_on3_hs_active_pixel_var_shift                         (3)
#define  ONMS_onms3_status_on3_hs_meas_over_range_mask                           (0x00200000)
#define  ONMS_onms3_status_on3_vs_per_to_long_mask                               (0x00100000)
#define  ONMS_onms3_status_on3_vs_pol_out_mask                                   (0x00020000)
#define  ONMS_onms3_status_on3_hs_pol_out_mask                                   (0x00010000)
#define  ONMS_onms3_status_on3_vs_per_over_range_mask                            (0x00008000)
#define  ONMS_onms3_status_on3_hs_per_over_range_mask                            (0x00004000)
#define  ONMS_onms3_status_on3_vs_per_timeout_mask                               (0x00002000)
#define  ONMS_onms3_status_on3_vs_high_timeout_mask                              (0x00001000)
#define  ONMS_onms3_status_on3_vs_per_overflow_mask                              (0x00000800)
#define  ONMS_onms3_status_on3_hs_per_overflow_mask                              (0x00000400)
#define  ONMS_onms3_status_on3_vs_pol_chg_mask                                   (0x00000200)
#define  ONMS_onms3_status_on3_hs_pol_chg_mask                                   (0x00000100)
#define  ONMS_onms3_status_on3_vtotalde_chg_mask                                 (0x00000080)
#define  ONMS_onms3_status_on3_vtotal_chg_mask                                   (0x00000040)
#define  ONMS_onms3_status_on3_hact_chg_mask                                     (0x00000020)
#define  ONMS_onms3_status_on3_htotal_chg_mask                                   (0x00000010)
#define  ONMS_onms3_status_on3_hs_active_pixel_var_mask                          (0x00000008)
#define  ONMS_onms3_status_on3_hs_meas_over_range(data)                          (0x00200000&((data)<<21))
#define  ONMS_onms3_status_on3_vs_per_to_long(data)                              (0x00100000&((data)<<20))
#define  ONMS_onms3_status_on3_vs_pol_out(data)                                  (0x00020000&((data)<<17))
#define  ONMS_onms3_status_on3_hs_pol_out(data)                                  (0x00010000&((data)<<16))
#define  ONMS_onms3_status_on3_vs_per_over_range(data)                           (0x00008000&((data)<<15))
#define  ONMS_onms3_status_on3_hs_per_over_range(data)                           (0x00004000&((data)<<14))
#define  ONMS_onms3_status_on3_vs_per_timeout(data)                              (0x00002000&((data)<<13))
#define  ONMS_onms3_status_on3_vs_high_timeout(data)                             (0x00001000&((data)<<12))
#define  ONMS_onms3_status_on3_vs_per_overflow(data)                             (0x00000800&((data)<<11))
#define  ONMS_onms3_status_on3_hs_per_overflow(data)                             (0x00000400&((data)<<10))
#define  ONMS_onms3_status_on3_vs_pol_chg(data)                                  (0x00000200&((data)<<9))
#define  ONMS_onms3_status_on3_hs_pol_chg(data)                                  (0x00000100&((data)<<8))
#define  ONMS_onms3_status_on3_vtotalde_chg(data)                                (0x00000080&((data)<<7))
#define  ONMS_onms3_status_on3_vtotal_chg(data)                                  (0x00000040&((data)<<6))
#define  ONMS_onms3_status_on3_hact_chg(data)                                    (0x00000020&((data)<<5))
#define  ONMS_onms3_status_on3_htotal_chg(data)                                  (0x00000010&((data)<<4))
#define  ONMS_onms3_status_on3_hs_active_pixel_var(data)                         (0x00000008&((data)<<3))
#define  ONMS_onms3_status_get_on3_hs_meas_over_range(data)                      ((0x00200000&(data))>>21)
#define  ONMS_onms3_status_get_on3_vs_per_to_long(data)                          ((0x00100000&(data))>>20)
#define  ONMS_onms3_status_get_on3_vs_pol_out(data)                              ((0x00020000&(data))>>17)
#define  ONMS_onms3_status_get_on3_hs_pol_out(data)                              ((0x00010000&(data))>>16)
#define  ONMS_onms3_status_get_on3_vs_per_over_range(data)                       ((0x00008000&(data))>>15)
#define  ONMS_onms3_status_get_on3_hs_per_over_range(data)                       ((0x00004000&(data))>>14)
#define  ONMS_onms3_status_get_on3_vs_per_timeout(data)                          ((0x00002000&(data))>>13)
#define  ONMS_onms3_status_get_on3_vs_high_timeout(data)                         ((0x00001000&(data))>>12)
#define  ONMS_onms3_status_get_on3_vs_per_overflow(data)                         ((0x00000800&(data))>>11)
#define  ONMS_onms3_status_get_on3_hs_per_overflow(data)                         ((0x00000400&(data))>>10)
#define  ONMS_onms3_status_get_on3_vs_pol_chg(data)                              ((0x00000200&(data))>>9)
#define  ONMS_onms3_status_get_on3_hs_pol_chg(data)                              ((0x00000100&(data))>>8)
#define  ONMS_onms3_status_get_on3_vtotalde_chg(data)                            ((0x00000080&(data))>>7)
#define  ONMS_onms3_status_get_on3_vtotal_chg(data)                              ((0x00000040&(data))>>6)
#define  ONMS_onms3_status_get_on3_hact_chg(data)                                ((0x00000020&(data))>>5)
#define  ONMS_onms3_status_get_on3_htotal_chg(data)                              ((0x00000010&(data))>>4)
#define  ONMS_onms3_status_get_on3_hs_active_pixel_var(data)                     ((0x00000008&(data))>>3)

#define  ONMS_onms3_watchdog_en                                                  0x1802146C
#define  ONMS_onms3_watchdog_en_reg_addr                                         "0xB802146C"
#define  ONMS_onms3_watchdog_en_reg                                              0xB802146C
#define  ONMS_onms3_watchdog_en_inst_addr                                        "0x004B"
#define  set_ONMS_onms3_watchdog_en_reg(data)                                    (*((volatile unsigned int*)ONMS_onms3_watchdog_en_reg)=data)
#define  get_ONMS_onms3_watchdog_en_reg                                          (*((volatile unsigned int*)ONMS_onms3_watchdog_en_reg))
#define  ONMS_onms3_watchdog_en_on3_wd_to_main_shift                             (31)
#define  ONMS_onms3_watchdog_en_on3_wd_to_sub_shift                              (30)
#define  ONMS_onms3_watchdog_en_on3_wd_hs_meas_over_range_shift                  (21)
#define  ONMS_onms3_watchdog_en_on3_wd_vs_per_over_range_shift                   (15)
#define  ONMS_onms3_watchdog_en_on3_wd_hs_per_over_range_shift                   (14)
#define  ONMS_onms3_watchdog_en_on3_wd_vs_per_timeout_shift                      (13)
#define  ONMS_onms3_watchdog_en_on3_wd_vs_high_timeout_shift                     (12)
#define  ONMS_onms3_watchdog_en_on3_wd_vs_per_overflow_shift                     (11)
#define  ONMS_onms3_watchdog_en_on3_wd_hs_per_overflow_shift                     (10)
#define  ONMS_onms3_watchdog_en_on3_wd_vs_pol_chg_shift                          (9)
#define  ONMS_onms3_watchdog_en_on3_wd_hs_pol_chg_shift                          (8)
#define  ONMS_onms3_watchdog_en_on3_wd_vtotalde_chg_shift                        (7)
#define  ONMS_onms3_watchdog_en_on3_wd_vtotal_chg_shift                          (6)
#define  ONMS_onms3_watchdog_en_on3_wd_hact_chg_shift                            (5)
#define  ONMS_onms3_watchdog_en_on3_wd_htotal_chg_shift                          (4)
#define  ONMS_onms3_watchdog_en_on3_wd_hs_active_pixel_var_shift                 (3)
#define  ONMS_onms3_watchdog_en_on3_wd_to_main_mask                              (0x80000000)
#define  ONMS_onms3_watchdog_en_on3_wd_to_sub_mask                               (0x40000000)
#define  ONMS_onms3_watchdog_en_on3_wd_hs_meas_over_range_mask                   (0x00200000)
#define  ONMS_onms3_watchdog_en_on3_wd_vs_per_over_range_mask                    (0x00008000)
#define  ONMS_onms3_watchdog_en_on3_wd_hs_per_over_range_mask                    (0x00004000)
#define  ONMS_onms3_watchdog_en_on3_wd_vs_per_timeout_mask                       (0x00002000)
#define  ONMS_onms3_watchdog_en_on3_wd_vs_high_timeout_mask                      (0x00001000)
#define  ONMS_onms3_watchdog_en_on3_wd_vs_per_overflow_mask                      (0x00000800)
#define  ONMS_onms3_watchdog_en_on3_wd_hs_per_overflow_mask                      (0x00000400)
#define  ONMS_onms3_watchdog_en_on3_wd_vs_pol_chg_mask                           (0x00000200)
#define  ONMS_onms3_watchdog_en_on3_wd_hs_pol_chg_mask                           (0x00000100)
#define  ONMS_onms3_watchdog_en_on3_wd_vtotalde_chg_mask                         (0x00000080)
#define  ONMS_onms3_watchdog_en_on3_wd_vtotal_chg_mask                           (0x00000040)
#define  ONMS_onms3_watchdog_en_on3_wd_hact_chg_mask                             (0x00000020)
#define  ONMS_onms3_watchdog_en_on3_wd_htotal_chg_mask                           (0x00000010)
#define  ONMS_onms3_watchdog_en_on3_wd_hs_active_pixel_var_mask                  (0x00000008)
#define  ONMS_onms3_watchdog_en_on3_wd_to_main(data)                             (0x80000000&((data)<<31))
#define  ONMS_onms3_watchdog_en_on3_wd_to_sub(data)                              (0x40000000&((data)<<30))
#define  ONMS_onms3_watchdog_en_on3_wd_hs_meas_over_range(data)                  (0x00200000&((data)<<21))
#define  ONMS_onms3_watchdog_en_on3_wd_vs_per_over_range(data)                   (0x00008000&((data)<<15))
#define  ONMS_onms3_watchdog_en_on3_wd_hs_per_over_range(data)                   (0x00004000&((data)<<14))
#define  ONMS_onms3_watchdog_en_on3_wd_vs_per_timeout(data)                      (0x00002000&((data)<<13))
#define  ONMS_onms3_watchdog_en_on3_wd_vs_high_timeout(data)                     (0x00001000&((data)<<12))
#define  ONMS_onms3_watchdog_en_on3_wd_vs_per_overflow(data)                     (0x00000800&((data)<<11))
#define  ONMS_onms3_watchdog_en_on3_wd_hs_per_overflow(data)                     (0x00000400&((data)<<10))
#define  ONMS_onms3_watchdog_en_on3_wd_vs_pol_chg(data)                          (0x00000200&((data)<<9))
#define  ONMS_onms3_watchdog_en_on3_wd_hs_pol_chg(data)                          (0x00000100&((data)<<8))
#define  ONMS_onms3_watchdog_en_on3_wd_vtotalde_chg(data)                        (0x00000080&((data)<<7))
#define  ONMS_onms3_watchdog_en_on3_wd_vtotal_chg(data)                          (0x00000040&((data)<<6))
#define  ONMS_onms3_watchdog_en_on3_wd_hact_chg(data)                            (0x00000020&((data)<<5))
#define  ONMS_onms3_watchdog_en_on3_wd_htotal_chg(data)                          (0x00000010&((data)<<4))
#define  ONMS_onms3_watchdog_en_on3_wd_hs_active_pixel_var(data)                 (0x00000008&((data)<<3))
#define  ONMS_onms3_watchdog_en_get_on3_wd_to_main(data)                         ((0x80000000&(data))>>31)
#define  ONMS_onms3_watchdog_en_get_on3_wd_to_sub(data)                          ((0x40000000&(data))>>30)
#define  ONMS_onms3_watchdog_en_get_on3_wd_hs_meas_over_range(data)              ((0x00200000&(data))>>21)
#define  ONMS_onms3_watchdog_en_get_on3_wd_vs_per_over_range(data)               ((0x00008000&(data))>>15)
#define  ONMS_onms3_watchdog_en_get_on3_wd_hs_per_over_range(data)               ((0x00004000&(data))>>14)
#define  ONMS_onms3_watchdog_en_get_on3_wd_vs_per_timeout(data)                  ((0x00002000&(data))>>13)
#define  ONMS_onms3_watchdog_en_get_on3_wd_vs_high_timeout(data)                 ((0x00001000&(data))>>12)
#define  ONMS_onms3_watchdog_en_get_on3_wd_vs_per_overflow(data)                 ((0x00000800&(data))>>11)
#define  ONMS_onms3_watchdog_en_get_on3_wd_hs_per_overflow(data)                 ((0x00000400&(data))>>10)
#define  ONMS_onms3_watchdog_en_get_on3_wd_vs_pol_chg(data)                      ((0x00000200&(data))>>9)
#define  ONMS_onms3_watchdog_en_get_on3_wd_hs_pol_chg(data)                      ((0x00000100&(data))>>8)
#define  ONMS_onms3_watchdog_en_get_on3_wd_vtotalde_chg(data)                    ((0x00000080&(data))>>7)
#define  ONMS_onms3_watchdog_en_get_on3_wd_vtotal_chg(data)                      ((0x00000040&(data))>>6)
#define  ONMS_onms3_watchdog_en_get_on3_wd_hact_chg(data)                        ((0x00000020&(data))>>5)
#define  ONMS_onms3_watchdog_en_get_on3_wd_htotal_chg(data)                      ((0x00000010&(data))>>4)
#define  ONMS_onms3_watchdog_en_get_on3_wd_hs_active_pixel_var(data)             ((0x00000008&(data))>>3)

#define  ONMS_onms3_interrupt_en                                                 0x18021470
#define  ONMS_onms3_interrupt_en_reg_addr                                        "0xB8021470"
#define  ONMS_onms3_interrupt_en_reg                                             0xB8021470
#define  ONMS_onms3_interrupt_en_inst_addr                                       "0x004C"
#define  set_ONMS_onms3_interrupt_en_reg(data)                                   (*((volatile unsigned int*)ONMS_onms3_interrupt_en_reg)=data)
#define  get_ONMS_onms3_interrupt_en_reg                                         (*((volatile unsigned int*)ONMS_onms3_interrupt_en_reg))
#define  ONMS_onms3_interrupt_en_on3_ie_to_main_shift                            (31)
#define  ONMS_onms3_interrupt_en_on3_ie_hs_meas_over_range_shift                 (21)
#define  ONMS_onms3_interrupt_en_on3_ie_vs_per_over_range_shift                  (15)
#define  ONMS_onms3_interrupt_en_on3_ie_hs_per_over_range_shift                  (14)
#define  ONMS_onms3_interrupt_en_on3_ie_vs_per_timeout_shift                     (13)
#define  ONMS_onms3_interrupt_en_on3_ie_vs_high_timeout_shift                    (12)
#define  ONMS_onms3_interrupt_en_on3_ie_vs_per_overflow_shift                    (11)
#define  ONMS_onms3_interrupt_en_on3_ie_hs_per_overflow_shift                    (10)
#define  ONMS_onms3_interrupt_en_on3_ie_vs_pol_chg_shift                         (9)
#define  ONMS_onms3_interrupt_en_on3_ie_hs_pol_chg_shift                         (8)
#define  ONMS_onms3_interrupt_en_on3_ie_vtotalde_chg_shift                       (7)
#define  ONMS_onms3_interrupt_en_on3_ie_vtotal_chg_shift                         (6)
#define  ONMS_onms3_interrupt_en_on3_ie_hact_chg_shift                           (5)
#define  ONMS_onms3_interrupt_en_on3_ie_htotal_chg_shift                         (4)
#define  ONMS_onms3_interrupt_en_on3_ie_hs_active_pixel_var_shift                (3)
#define  ONMS_onms3_interrupt_en_on3_ie_to_main_mask                             (0x80000000)
#define  ONMS_onms3_interrupt_en_on3_ie_hs_meas_over_range_mask                  (0x00200000)
#define  ONMS_onms3_interrupt_en_on3_ie_vs_per_over_range_mask                   (0x00008000)
#define  ONMS_onms3_interrupt_en_on3_ie_hs_per_over_range_mask                   (0x00004000)
#define  ONMS_onms3_interrupt_en_on3_ie_vs_per_timeout_mask                      (0x00002000)
#define  ONMS_onms3_interrupt_en_on3_ie_vs_high_timeout_mask                     (0x00001000)
#define  ONMS_onms3_interrupt_en_on3_ie_vs_per_overflow_mask                     (0x00000800)
#define  ONMS_onms3_interrupt_en_on3_ie_hs_per_overflow_mask                     (0x00000400)
#define  ONMS_onms3_interrupt_en_on3_ie_vs_pol_chg_mask                          (0x00000200)
#define  ONMS_onms3_interrupt_en_on3_ie_hs_pol_chg_mask                          (0x00000100)
#define  ONMS_onms3_interrupt_en_on3_ie_vtotalde_chg_mask                        (0x00000080)
#define  ONMS_onms3_interrupt_en_on3_ie_vtotal_chg_mask                          (0x00000040)
#define  ONMS_onms3_interrupt_en_on3_ie_hact_chg_mask                            (0x00000020)
#define  ONMS_onms3_interrupt_en_on3_ie_htotal_chg_mask                          (0x00000010)
#define  ONMS_onms3_interrupt_en_on3_ie_hs_active_pixel_var_mask                 (0x00000008)
#define  ONMS_onms3_interrupt_en_on3_ie_to_main(data)                            (0x80000000&((data)<<31))
#define  ONMS_onms3_interrupt_en_on3_ie_hs_meas_over_range(data)                 (0x00200000&((data)<<21))
#define  ONMS_onms3_interrupt_en_on3_ie_vs_per_over_range(data)                  (0x00008000&((data)<<15))
#define  ONMS_onms3_interrupt_en_on3_ie_hs_per_over_range(data)                  (0x00004000&((data)<<14))
#define  ONMS_onms3_interrupt_en_on3_ie_vs_per_timeout(data)                     (0x00002000&((data)<<13))
#define  ONMS_onms3_interrupt_en_on3_ie_vs_high_timeout(data)                    (0x00001000&((data)<<12))
#define  ONMS_onms3_interrupt_en_on3_ie_vs_per_overflow(data)                    (0x00000800&((data)<<11))
#define  ONMS_onms3_interrupt_en_on3_ie_hs_per_overflow(data)                    (0x00000400&((data)<<10))
#define  ONMS_onms3_interrupt_en_on3_ie_vs_pol_chg(data)                         (0x00000200&((data)<<9))
#define  ONMS_onms3_interrupt_en_on3_ie_hs_pol_chg(data)                         (0x00000100&((data)<<8))
#define  ONMS_onms3_interrupt_en_on3_ie_vtotalde_chg(data)                       (0x00000080&((data)<<7))
#define  ONMS_onms3_interrupt_en_on3_ie_vtotal_chg(data)                         (0x00000040&((data)<<6))
#define  ONMS_onms3_interrupt_en_on3_ie_hact_chg(data)                           (0x00000020&((data)<<5))
#define  ONMS_onms3_interrupt_en_on3_ie_htotal_chg(data)                         (0x00000010&((data)<<4))
#define  ONMS_onms3_interrupt_en_on3_ie_hs_active_pixel_var(data)                (0x00000008&((data)<<3))
#define  ONMS_onms3_interrupt_en_get_on3_ie_to_main(data)                        ((0x80000000&(data))>>31)
#define  ONMS_onms3_interrupt_en_get_on3_ie_hs_meas_over_range(data)             ((0x00200000&(data))>>21)
#define  ONMS_onms3_interrupt_en_get_on3_ie_vs_per_over_range(data)              ((0x00008000&(data))>>15)
#define  ONMS_onms3_interrupt_en_get_on3_ie_hs_per_over_range(data)              ((0x00004000&(data))>>14)
#define  ONMS_onms3_interrupt_en_get_on3_ie_vs_per_timeout(data)                 ((0x00002000&(data))>>13)
#define  ONMS_onms3_interrupt_en_get_on3_ie_vs_high_timeout(data)                ((0x00001000&(data))>>12)
#define  ONMS_onms3_interrupt_en_get_on3_ie_vs_per_overflow(data)                ((0x00000800&(data))>>11)
#define  ONMS_onms3_interrupt_en_get_on3_ie_hs_per_overflow(data)                ((0x00000400&(data))>>10)
#define  ONMS_onms3_interrupt_en_get_on3_ie_vs_pol_chg(data)                     ((0x00000200&(data))>>9)
#define  ONMS_onms3_interrupt_en_get_on3_ie_hs_pol_chg(data)                     ((0x00000100&(data))>>8)
#define  ONMS_onms3_interrupt_en_get_on3_ie_vtotalde_chg(data)                   ((0x00000080&(data))>>7)
#define  ONMS_onms3_interrupt_en_get_on3_ie_vtotal_chg(data)                     ((0x00000040&(data))>>6)
#define  ONMS_onms3_interrupt_en_get_on3_ie_hact_chg(data)                       ((0x00000020&(data))>>5)
#define  ONMS_onms3_interrupt_en_get_on3_ie_htotal_chg(data)                     ((0x00000010&(data))>>4)
#define  ONMS_onms3_interrupt_en_get_on3_ie_hs_active_pixel_var(data)            ((0x00000008&(data))>>3)

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======ONMS register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  on1_4k2k_mode:2;
        RBus_UInt32  on1_ms_src_sel:1;
        RBus_UInt32  on1_blk_2frame_en:1;
        RBus_UInt32  on1_pixel_get_en:1;
        RBus_UInt32  on1_pixel_get_sel:2;
        RBus_UInt32  on1_progressive:1;
        RBus_UInt32  on1_vtotal_max_delta:4;
        RBus_UInt32  on1_htotal_max_delta:4;
        RBus_UInt32  dummy18021200_15:1;
        RBus_UInt32  dummy18021200_14:1;
        RBus_UInt32  dummy18021200_13:1;
        RBus_UInt32  on1_pixel_encoding:1;
        RBus_UInt32  on1_vact_space_threshold:4;
        RBus_UInt32  on1_vact_space_meas_en:1;
        RBus_UInt32  on1_meas_to_sel:1;
        RBus_UInt32  on1_sycms_clk:1;
        RBus_UInt32  on1_vs_meas_inv:1;
        RBus_UInt32  on1_hs_meas_inv:1;
        RBus_UInt32  on1_popup_meas:1;
        RBus_UInt32  on1_ms_conti:1;
        RBus_UInt32  on1_start_ms:1;
    };
}onms_onms1_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  on1_pixel_ok:1;
        RBus_UInt32  on1_get_r_value:12;
        RBus_UInt32  on1_get_g_value:12;
    };
}onms_onms1_blank_pixel_value_get_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  on1_get_b_value:12;
    };
}onms_onms1_blank_pixel_value_get_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  on1_active_r_value:12;
        RBus_UInt32  on1_active_g_value:12;
    };
}onms_onms1_blank_pixel_value_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  on1_active_b_value:12;
    };
}onms_onms1_blank_pixel_value_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  on1_vact2:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  on1_vact1:11;
    };
}onms_onms1_fp_vact12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  on1_vact4:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  on1_vact3:11;
    };
}onms_onms1_fp_vact34_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  on1_fp_vact_space1:10;
        RBus_UInt32  on1_fp_vact_space2:10;
        RBus_UInt32  on1_fp_vact_space3:10;
    };
}onms_onms1_fp_vact_space_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  on1_r_blank_line_start:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  on1_l_blank_line_end:11;
    };
}onms_onms1_blank_line_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  on1_vact_space1_end:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  on1_vact_space1_start:10;
    };
}onms_onms1_active_space1_line_number_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  on1_vact_space2_end:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  on1_vact_space2_start:10;
    };
}onms_onms1_active_space2_line_number_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  on1_vact_space3_end:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  on1_vact_space3_start:10;
    };
}onms_onms1_active_space3_line_number_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  on1_vtotalde:13;
        RBus_UInt32  res2:2;
        RBus_UInt32  on1_vtotal:14;
    };
}onms_onms1_vs_period_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  on1_vs_high_period:12;
        RBus_UInt32  res2:2;
        RBus_UInt32  on1_hs_high_period:14;
    };
}onms_onms1_vshs_high_period_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  on1_htotal_h12b:14;
        RBus_UInt32  on1_htotal_f4b:4;
    };
}onms_onms1_hs_period_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  on1_vblank_len:8;
        RBus_UInt32  res2:4;
        RBus_UInt32  on1_vact_start:12;
    };
}onms_onms1_vact_sta_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  on1_hact_start:14;
    };
}onms_onms1_hact_sta_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  on1_hact:14;
        RBus_UInt32  on1_hact_fract:4;
    };
}onms_onms1_hact_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  on1_ltotal:24;
    };
}onms_onms1_l_flag_period_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  on1_l_flag_high_period:24;
    };
}onms_onms1_l_flag_high_period_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  on1_ftotal:24;
    };
}onms_onms1_field_period_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  on1_field_high_period:24;
    };
}onms_onms1_field_high_period_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  on1_ltotal_chg:1;
        RBus_UInt32  on1_ftotal_chg:1;
    };
}onms_onms1_status_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  on1_htotal_max_delta_new:7;
        RBus_UInt32  res2:4;
        RBus_UInt32  on1_average_line:4;
        RBus_UInt32  res3:2;
        RBus_UInt32  on1_target_measure:14;
    };
}onms_onms1_hsync_meas_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  on1_vmeas_end:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  on1_vmeas_start:12;
    };
}onms_onms1_hsync_meas_ctrl_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  on1_hmax_delta_total:14;
    };
}onms_onms1_hsync_meas_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  on1_hs_meas_over_range:1;
        RBus_UInt32  on1_vs_per_to_long:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  on1_vs_pol_out:1;
        RBus_UInt32  on1_hs_pol_out:1;
        RBus_UInt32  on1_vs_per_over_range:1;
        RBus_UInt32  on1_hs_per_over_range:1;
        RBus_UInt32  on1_vs_per_timeout:1;
        RBus_UInt32  on1_vs_high_timeout:1;
        RBus_UInt32  on1_vs_per_overflow:1;
        RBus_UInt32  on1_hs_per_overflow:1;
        RBus_UInt32  on1_vs_pol_chg:1;
        RBus_UInt32  on1_hs_pol_chg:1;
        RBus_UInt32  on1_vtotalde_chg:1;
        RBus_UInt32  on1_vtotal_chg:1;
        RBus_UInt32  on1_hact_chg:1;
        RBus_UInt32  on1_htotal_chg:1;
        RBus_UInt32  on1_hs_active_pixel_var:1;
        RBus_UInt32  res3:3;
    };
}onms_onms1_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  on1_wd_to_main:1;
        RBus_UInt32  on1_wd_to_sub:1;
        RBus_UInt32  res1:8;
        RBus_UInt32  on1_wd_hs_meas_over_range:1;
        RBus_UInt32  res2:5;
        RBus_UInt32  on1_wd_vs_per_over_range:1;
        RBus_UInt32  on1_wd_hs_per_over_range:1;
        RBus_UInt32  on1_wd_vs_per_timeout:1;
        RBus_UInt32  on1_wd_vs_high_timeout:1;
        RBus_UInt32  on1_wd_vs_per_overflow:1;
        RBus_UInt32  on1_wd_hs_per_overflow:1;
        RBus_UInt32  on1_wd_vs_pol_chg:1;
        RBus_UInt32  on1_wd_hs_pol_chg:1;
        RBus_UInt32  on1_wd_vtotalde_chg:1;
        RBus_UInt32  on1_wd_vtotal_chg:1;
        RBus_UInt32  on1_wd_hact_chg:1;
        RBus_UInt32  on1_wd_htotal_chg:1;
        RBus_UInt32  on1_wd_hs_active_pixel_var:1;
        RBus_UInt32  res3:3;
    };
}onms_onms1_watchdog_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  on1_ie_to_main:1;
        RBus_UInt32  res1:9;
        RBus_UInt32  on1_ie_hs_meas_over_range:1;
        RBus_UInt32  res2:5;
        RBus_UInt32  on1_ie_vs_per_over_range:1;
        RBus_UInt32  on1_ie_hs_per_over_range:1;
        RBus_UInt32  on1_ie_vs_per_timeout:1;
        RBus_UInt32  on1_ie_vs_high_timeout:1;
        RBus_UInt32  on1_ie_vs_per_overflow:1;
        RBus_UInt32  on1_ie_hs_per_overflow:1;
        RBus_UInt32  on1_ie_vs_pol_chg:1;
        RBus_UInt32  on1_ie_hs_pol_chg:1;
        RBus_UInt32  on1_ie_vtotalde_chg:1;
        RBus_UInt32  on1_ie_vtotal_chg:1;
        RBus_UInt32  on1_ie_hact_chg:1;
        RBus_UInt32  on1_ie_htotal_chg:1;
        RBus_UInt32  on1_ie_hs_active_pixel_var:1;
        RBus_UInt32  res3:3;
    };
}onms_onms1_interrupt_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  on2_4k2k_mode:2;
        RBus_UInt32  on2_ms_src_sel:1;
        RBus_UInt32  on2_blk_2frame_en:1;
        RBus_UInt32  on2_pixel_get_en:1;
        RBus_UInt32  on2_pixel_get_sel:2;
        RBus_UInt32  on2_progressive:1;
        RBus_UInt32  on2_vtotal_max_delta:4;
        RBus_UInt32  on2_htotal_max_delta:4;
        RBus_UInt32  dummy18021300_15:1;
        RBus_UInt32  dummy18021300_14:1;
        RBus_UInt32  dummy18021300_13:1;
        RBus_UInt32  on2_pixel_encoding:1;
        RBus_UInt32  on2_vact_space_threshold:4;
        RBus_UInt32  on2_vact_space_meas_en:1;
        RBus_UInt32  on2_meas_to_sel:1;
        RBus_UInt32  on2_sycms_clk:1;
        RBus_UInt32  on2_vs_meas_inv:1;
        RBus_UInt32  on2_hs_meas_inv:1;
        RBus_UInt32  on2_popup_meas:1;
        RBus_UInt32  on2_ms_conti:1;
        RBus_UInt32  on2_start_ms:1;
    };
}onms_onms2_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  on2_pixel_ok:1;
        RBus_UInt32  on2_get_r_value:12;
        RBus_UInt32  on2_get_g_value:12;
    };
}onms_onms2_blank_pixel_value_get_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  on2_get_b_value:12;
    };
}onms_onms2_blank_pixel_value_get_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  on2_active_r_value:12;
        RBus_UInt32  on2_active_g_value:12;
    };
}onms_onms2_blank_pixel_value_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  on2_active_b_value:12;
    };
}onms_onms2_blank_pixel_value_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  on2_vact2:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  on2_vact1:11;
    };
}onms_onms2_fp_vact12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  on2_vact4:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  on2_vact3:11;
    };
}onms_onms2_fp_vact34_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  on2_fp_vact_space1:10;
        RBus_UInt32  on2_fp_vact_space2:10;
        RBus_UInt32  on2_fp_vact_space3:10;
    };
}onms_onms2_fp_vact_space_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  on2_r_blank_line_start:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  on2_l_blank_line_end:11;
    };
}onms_onms2_blank_line_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  on2_vact_space1_end:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  on2_vact_space1_start:10;
    };
}onms_onms2_active_space1_line_number_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  on2_vact_space2_end:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  on2_vact_space2_start:10;
    };
}onms_onms2_active_space2_line_number_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  on2_vact_space3_end:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  on2_vact_space3_start:10;
    };
}onms_onms2_active_space3_line_number_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  on2_vtotalde:13;
        RBus_UInt32  res2:2;
        RBus_UInt32  on2_vtotal:14;
    };
}onms_onms2_vs_period_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  on2_vs_high_period:12;
        RBus_UInt32  res2:2;
        RBus_UInt32  on2_hs_high_period:14;
    };
}onms_onms2_vshs_high_period_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  on2_htotal_h12b:14;
        RBus_UInt32  on2_htotal_f4b:4;
    };
}onms_onms2_hs_period_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  on2_vblank_len:8;
        RBus_UInt32  res2:4;
        RBus_UInt32  on2_vact_start:12;
    };
}onms_onms2_vact_sta_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  on2_hact_start:14;
    };
}onms_onms2_hact_sta_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  on2_hact:14;
        RBus_UInt32  on2_hact_fract:4;
    };
}onms_onms2_hact_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  on2_htotal_max_delta_new:7;
        RBus_UInt32  res2:4;
        RBus_UInt32  on2_average_line:4;
        RBus_UInt32  res3:2;
        RBus_UInt32  on2_target_measure:14;
    };
}onms_onms2_hsync_meas_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  on2_vmeas_end:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  on2_vmeas_start:12;
    };
}onms_onms2_hsync_meas_ctrl_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  on2_hmax_delta_total:14;
    };
}onms_onms2_hsync_meas_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  on2_hs_meas_over_range:1;
        RBus_UInt32  on2_vs_per_to_long:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  on2_vs_pol_out:1;
        RBus_UInt32  on2_hs_pol_out:1;
        RBus_UInt32  on2_vs_per_over_range:1;
        RBus_UInt32  on2_hs_per_over_range:1;
        RBus_UInt32  on2_vs_per_timeout:1;
        RBus_UInt32  on2_vs_high_timeout:1;
        RBus_UInt32  on2_vs_per_overflow:1;
        RBus_UInt32  on2_hs_per_overflow:1;
        RBus_UInt32  on2_vs_pol_chg:1;
        RBus_UInt32  on2_hs_pol_chg:1;
        RBus_UInt32  on2_vtotalde_chg:1;
        RBus_UInt32  on2_vtotal_chg:1;
        RBus_UInt32  on2_hact_chg:1;
        RBus_UInt32  on2_htotal_chg:1;
        RBus_UInt32  on2_hs_active_pixel_var:1;
        RBus_UInt32  res3:3;
    };
}onms_onms2_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  on2_wd_to_main:1;
        RBus_UInt32  on2_wd_to_sub:1;
        RBus_UInt32  res1:8;
        RBus_UInt32  on2_wd_hs_meas_over_range:1;
        RBus_UInt32  res2:5;
        RBus_UInt32  on2_wd_vs_per_over_range:1;
        RBus_UInt32  on2_wd_hs_per_over_range:1;
        RBus_UInt32  on2_wd_vs_per_timeout:1;
        RBus_UInt32  on2_wd_vs_high_timeout:1;
        RBus_UInt32  on2_wd_vs_per_overflow:1;
        RBus_UInt32  on2_wd_hs_per_overflow:1;
        RBus_UInt32  on2_wd_vs_pol_chg:1;
        RBus_UInt32  on2_wd_hs_pol_chg:1;
        RBus_UInt32  on2_wd_vtotalde_chg:1;
        RBus_UInt32  on2_wd_vtotal_chg:1;
        RBus_UInt32  on2_wd_hact_chg:1;
        RBus_UInt32  on2_wd_htotal_chg:1;
        RBus_UInt32  on2_wd_hs_active_pixel_var:1;
        RBus_UInt32  res3:3;
    };
}onms_onms2_watchdog_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  on2_ie_to_main:1;
        RBus_UInt32  res1:9;
        RBus_UInt32  on2_ie_hs_meas_over_range:1;
        RBus_UInt32  res2:5;
        RBus_UInt32  on2_ie_vs_per_over_range:1;
        RBus_UInt32  on2_ie_hs_per_over_range:1;
        RBus_UInt32  on2_ie_vs_per_timeout:1;
        RBus_UInt32  on2_ie_vs_high_timeout:1;
        RBus_UInt32  on2_ie_vs_per_overflow:1;
        RBus_UInt32  on2_ie_hs_per_overflow:1;
        RBus_UInt32  on2_ie_vs_pol_chg:1;
        RBus_UInt32  on2_ie_hs_pol_chg:1;
        RBus_UInt32  on2_ie_vtotalde_chg:1;
        RBus_UInt32  on2_ie_vtotal_chg:1;
        RBus_UInt32  on2_ie_hact_chg:1;
        RBus_UInt32  on2_ie_htotal_chg:1;
        RBus_UInt32  on2_ie_hs_active_pixel_var:1;
        RBus_UInt32  res3:3;
    };
}onms_onms2_interrupt_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  on3_4k2k_mode:2;
        RBus_UInt32  on3_ms_src_sel:1;
        RBus_UInt32  on3_blk_2frame_en:1;
        RBus_UInt32  on3_pixel_get_en:1;
        RBus_UInt32  on3_pixel_get_sel:2;
        RBus_UInt32  on3_progressive:1;
        RBus_UInt32  on3_vtotal_max_delta:4;
        RBus_UInt32  on3_htotal_max_delta:4;
        RBus_UInt32  dummy18021400_15:1;
        RBus_UInt32  dummy18021400_14:1;
        RBus_UInt32  dummy18021400_13:1;
        RBus_UInt32  on3_pixel_encoding:1;
        RBus_UInt32  on3_vact_space_threshold:4;
        RBus_UInt32  on3_vact_space_meas_en:1;
        RBus_UInt32  on3_meas_to_sel:1;
        RBus_UInt32  on3_sycms_clk:1;
        RBus_UInt32  on3_vs_meas_inv:1;
        RBus_UInt32  on3_hs_meas_inv:1;
        RBus_UInt32  on3_popup_meas:1;
        RBus_UInt32  on3_ms_conti:1;
        RBus_UInt32  on3_start_ms:1;
    };
}onms_onms3_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  on3_pixel_ok:1;
        RBus_UInt32  on3_get_r_value:12;
        RBus_UInt32  on3_get_g_value:12;
    };
}onms_onms3_blank_pixel_value_get_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  on3_get_b_value:12;
    };
}onms_onms3_blank_pixel_value_get_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  on3_active_r_value:12;
        RBus_UInt32  on3_active_g_value:12;
    };
}onms_onms3_blank_pixel_value_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  on3_active_b_value:12;
    };
}onms_onms3_blank_pixel_value_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  on3_vact2:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  on3_vact1:11;
    };
}onms_onms3_fp_vact12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  on3_vact4:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  on3_vact3:11;
    };
}onms_onms3_fp_vact34_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  on3_fp_vact_space1:10;
        RBus_UInt32  on3_fp_vact_space2:10;
        RBus_UInt32  on3_fp_vact_space3:10;
    };
}onms_onms3_fp_vact_space_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  on3_r_blank_line_start:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  on3_l_blank_line_end:11;
    };
}onms_onms3_blank_line_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  on3_vact_space1_end:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  on3_vact_space1_start:10;
    };
}onms_onms3_active_space1_line_number_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  on3_vact_space2_end:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  on3_vact_space2_start:10;
    };
}onms_onms3_active_space2_line_number_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  on3_vact_space3_end:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  on3_vact_space3_start:10;
    };
}onms_onms3_active_space3_line_number_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  on3_vtotalde:13;
        RBus_UInt32  res2:2;
        RBus_UInt32  on3_vtotal:14;
    };
}onms_onms3_vs_period_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  on3_vs_high_period:12;
        RBus_UInt32  res2:2;
        RBus_UInt32  on3_hs_high_period:14;
    };
}onms_onms3_vshs_high_period_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  on3_htotal_h12b:14;
        RBus_UInt32  on3_htotal_f4b:4;
    };
}onms_onms3_hs_period_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  on3_vblank_len:8;
        RBus_UInt32  res2:4;
        RBus_UInt32  on3_vact_start:12;
    };
}onms_onms3_vact_sta_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  on3_hact_start:14;
    };
}onms_onms3_hact_sta_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  on3_hact:14;
        RBus_UInt32  on3_hact_fract:4;
    };
}onms_onms3_hact_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  on3_htotal_max_delta_new:7;
        RBus_UInt32  res2:4;
        RBus_UInt32  on3_average_line:4;
        RBus_UInt32  res3:2;
        RBus_UInt32  on3_target_measure:14;
    };
}onms_onms3_hsync_meas_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  on3_vmeas_end:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  on3_vmeas_start:12;
    };
}onms_onms3_hsync_meas_ctrl_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  on3_hmax_delta_total:14;
    };
}onms_onms3_hsync_meas_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  on3_hs_meas_over_range:1;
        RBus_UInt32  on3_vs_per_to_long:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  on3_vs_pol_out:1;
        RBus_UInt32  on3_hs_pol_out:1;
        RBus_UInt32  on3_vs_per_over_range:1;
        RBus_UInt32  on3_hs_per_over_range:1;
        RBus_UInt32  on3_vs_per_timeout:1;
        RBus_UInt32  on3_vs_high_timeout:1;
        RBus_UInt32  on3_vs_per_overflow:1;
        RBus_UInt32  on3_hs_per_overflow:1;
        RBus_UInt32  on3_vs_pol_chg:1;
        RBus_UInt32  on3_hs_pol_chg:1;
        RBus_UInt32  on3_vtotalde_chg:1;
        RBus_UInt32  on3_vtotal_chg:1;
        RBus_UInt32  on3_hact_chg:1;
        RBus_UInt32  on3_htotal_chg:1;
        RBus_UInt32  on3_hs_active_pixel_var:1;
        RBus_UInt32  res3:3;
    };
}onms_onms3_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  on3_wd_to_main:1;
        RBus_UInt32  on3_wd_to_sub:1;
        RBus_UInt32  res1:8;
        RBus_UInt32  on3_wd_hs_meas_over_range:1;
        RBus_UInt32  res2:5;
        RBus_UInt32  on3_wd_vs_per_over_range:1;
        RBus_UInt32  on3_wd_hs_per_over_range:1;
        RBus_UInt32  on3_wd_vs_per_timeout:1;
        RBus_UInt32  on3_wd_vs_high_timeout:1;
        RBus_UInt32  on3_wd_vs_per_overflow:1;
        RBus_UInt32  on3_wd_hs_per_overflow:1;
        RBus_UInt32  on3_wd_vs_pol_chg:1;
        RBus_UInt32  on3_wd_hs_pol_chg:1;
        RBus_UInt32  on3_wd_vtotalde_chg:1;
        RBus_UInt32  on3_wd_vtotal_chg:1;
        RBus_UInt32  on3_wd_hact_chg:1;
        RBus_UInt32  on3_wd_htotal_chg:1;
        RBus_UInt32  on3_wd_hs_active_pixel_var:1;
        RBus_UInt32  res3:3;
    };
}onms_onms3_watchdog_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  on3_ie_to_main:1;
        RBus_UInt32  res1:9;
        RBus_UInt32  on3_ie_hs_meas_over_range:1;
        RBus_UInt32  res2:5;
        RBus_UInt32  on3_ie_vs_per_over_range:1;
        RBus_UInt32  on3_ie_hs_per_over_range:1;
        RBus_UInt32  on3_ie_vs_per_timeout:1;
        RBus_UInt32  on3_ie_vs_high_timeout:1;
        RBus_UInt32  on3_ie_vs_per_overflow:1;
        RBus_UInt32  on3_ie_hs_per_overflow:1;
        RBus_UInt32  on3_ie_vs_pol_chg:1;
        RBus_UInt32  on3_ie_hs_pol_chg:1;
        RBus_UInt32  on3_ie_vtotalde_chg:1;
        RBus_UInt32  on3_ie_vtotal_chg:1;
        RBus_UInt32  on3_ie_hact_chg:1;
        RBus_UInt32  on3_ie_htotal_chg:1;
        RBus_UInt32  on3_ie_hs_active_pixel_var:1;
        RBus_UInt32  res3:3;
    };
}onms_onms3_interrupt_en_RBUS;

#else //apply LITTLE_ENDIAN

//======ONMS register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  on1_start_ms:1;
        RBus_UInt32  on1_ms_conti:1;
        RBus_UInt32  on1_popup_meas:1;
        RBus_UInt32  on1_hs_meas_inv:1;
        RBus_UInt32  on1_vs_meas_inv:1;
        RBus_UInt32  on1_sycms_clk:1;
        RBus_UInt32  on1_meas_to_sel:1;
        RBus_UInt32  on1_vact_space_meas_en:1;
        RBus_UInt32  on1_vact_space_threshold:4;
        RBus_UInt32  on1_pixel_encoding:1;
        RBus_UInt32  dummy18021200_13:1;
        RBus_UInt32  dummy18021200_14:1;
        RBus_UInt32  dummy18021200_15:1;
        RBus_UInt32  on1_htotal_max_delta:4;
        RBus_UInt32  on1_vtotal_max_delta:4;
        RBus_UInt32  on1_progressive:1;
        RBus_UInt32  on1_pixel_get_sel:2;
        RBus_UInt32  on1_pixel_get_en:1;
        RBus_UInt32  on1_blk_2frame_en:1;
        RBus_UInt32  on1_ms_src_sel:1;
        RBus_UInt32  on1_4k2k_mode:2;
    };
}onms_onms1_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  on1_get_g_value:12;
        RBus_UInt32  on1_get_r_value:12;
        RBus_UInt32  on1_pixel_ok:1;
        RBus_UInt32  res1:7;
    };
}onms_onms1_blank_pixel_value_get_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  on1_get_b_value:12;
        RBus_UInt32  res1:20;
    };
}onms_onms1_blank_pixel_value_get_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  on1_active_g_value:12;
        RBus_UInt32  on1_active_r_value:12;
        RBus_UInt32  res1:8;
    };
}onms_onms1_blank_pixel_value_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  on1_active_b_value:12;
        RBus_UInt32  res1:20;
    };
}onms_onms1_blank_pixel_value_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  on1_vact1:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  on1_vact2:11;
        RBus_UInt32  res2:5;
    };
}onms_onms1_fp_vact12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  on1_vact3:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  on1_vact4:11;
        RBus_UInt32  res2:5;
    };
}onms_onms1_fp_vact34_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  on1_fp_vact_space3:10;
        RBus_UInt32  on1_fp_vact_space2:10;
        RBus_UInt32  on1_fp_vact_space1:10;
        RBus_UInt32  res1:2;
    };
}onms_onms1_fp_vact_space_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  on1_l_blank_line_end:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  on1_r_blank_line_start:11;
        RBus_UInt32  res2:5;
    };
}onms_onms1_blank_line_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  on1_vact_space1_start:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  on1_vact_space1_end:10;
        RBus_UInt32  res2:6;
    };
}onms_onms1_active_space1_line_number_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  on1_vact_space2_start:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  on1_vact_space2_end:10;
        RBus_UInt32  res2:6;
    };
}onms_onms1_active_space2_line_number_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  on1_vact_space3_start:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  on1_vact_space3_end:10;
        RBus_UInt32  res2:6;
    };
}onms_onms1_active_space3_line_number_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  on1_vtotal:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  on1_vtotalde:13;
        RBus_UInt32  res2:3;
    };
}onms_onms1_vs_period_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  on1_hs_high_period:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  on1_vs_high_period:12;
        RBus_UInt32  res2:4;
    };
}onms_onms1_vshs_high_period_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  on1_htotal_f4b:4;
        RBus_UInt32  on1_htotal_h12b:14;
        RBus_UInt32  res1:14;
    };
}onms_onms1_hs_period_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  on1_vact_start:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  on1_vblank_len:8;
        RBus_UInt32  res2:8;
    };
}onms_onms1_vact_sta_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  on1_hact_start:14;
        RBus_UInt32  res1:18;
    };
}onms_onms1_hact_sta_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  on1_hact_fract:4;
        RBus_UInt32  on1_hact:14;
        RBus_UInt32  res1:14;
    };
}onms_onms1_hact_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  on1_ltotal:24;
        RBus_UInt32  res1:8;
    };
}onms_onms1_l_flag_period_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  on1_l_flag_high_period:24;
        RBus_UInt32  res1:8;
    };
}onms_onms1_l_flag_high_period_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  on1_ftotal:24;
        RBus_UInt32  res1:8;
    };
}onms_onms1_field_period_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  on1_field_high_period:24;
        RBus_UInt32  res1:8;
    };
}onms_onms1_field_high_period_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  on1_ftotal_chg:1;
        RBus_UInt32  on1_ltotal_chg:1;
        RBus_UInt32  res1:30;
    };
}onms_onms1_status_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  on1_target_measure:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  on1_average_line:4;
        RBus_UInt32  res2:4;
        RBus_UInt32  on1_htotal_max_delta_new:7;
        RBus_UInt32  res3:1;
    };
}onms_onms1_hsync_meas_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  on1_vmeas_start:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  on1_vmeas_end:12;
        RBus_UInt32  res2:4;
    };
}onms_onms1_hsync_meas_ctrl_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  on1_hmax_delta_total:14;
        RBus_UInt32  res1:18;
    };
}onms_onms1_hsync_meas_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  on1_hs_active_pixel_var:1;
        RBus_UInt32  on1_htotal_chg:1;
        RBus_UInt32  on1_hact_chg:1;
        RBus_UInt32  on1_vtotal_chg:1;
        RBus_UInt32  on1_vtotalde_chg:1;
        RBus_UInt32  on1_hs_pol_chg:1;
        RBus_UInt32  on1_vs_pol_chg:1;
        RBus_UInt32  on1_hs_per_overflow:1;
        RBus_UInt32  on1_vs_per_overflow:1;
        RBus_UInt32  on1_vs_high_timeout:1;
        RBus_UInt32  on1_vs_per_timeout:1;
        RBus_UInt32  on1_hs_per_over_range:1;
        RBus_UInt32  on1_vs_per_over_range:1;
        RBus_UInt32  on1_hs_pol_out:1;
        RBus_UInt32  on1_vs_pol_out:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  on1_vs_per_to_long:1;
        RBus_UInt32  on1_hs_meas_over_range:1;
        RBus_UInt32  res3:10;
    };
}onms_onms1_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  on1_wd_hs_active_pixel_var:1;
        RBus_UInt32  on1_wd_htotal_chg:1;
        RBus_UInt32  on1_wd_hact_chg:1;
        RBus_UInt32  on1_wd_vtotal_chg:1;
        RBus_UInt32  on1_wd_vtotalde_chg:1;
        RBus_UInt32  on1_wd_hs_pol_chg:1;
        RBus_UInt32  on1_wd_vs_pol_chg:1;
        RBus_UInt32  on1_wd_hs_per_overflow:1;
        RBus_UInt32  on1_wd_vs_per_overflow:1;
        RBus_UInt32  on1_wd_vs_high_timeout:1;
        RBus_UInt32  on1_wd_vs_per_timeout:1;
        RBus_UInt32  on1_wd_hs_per_over_range:1;
        RBus_UInt32  on1_wd_vs_per_over_range:1;
        RBus_UInt32  res2:5;
        RBus_UInt32  on1_wd_hs_meas_over_range:1;
        RBus_UInt32  res3:8;
        RBus_UInt32  on1_wd_to_sub:1;
        RBus_UInt32  on1_wd_to_main:1;
    };
}onms_onms1_watchdog_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  on1_ie_hs_active_pixel_var:1;
        RBus_UInt32  on1_ie_htotal_chg:1;
        RBus_UInt32  on1_ie_hact_chg:1;
        RBus_UInt32  on1_ie_vtotal_chg:1;
        RBus_UInt32  on1_ie_vtotalde_chg:1;
        RBus_UInt32  on1_ie_hs_pol_chg:1;
        RBus_UInt32  on1_ie_vs_pol_chg:1;
        RBus_UInt32  on1_ie_hs_per_overflow:1;
        RBus_UInt32  on1_ie_vs_per_overflow:1;
        RBus_UInt32  on1_ie_vs_high_timeout:1;
        RBus_UInt32  on1_ie_vs_per_timeout:1;
        RBus_UInt32  on1_ie_hs_per_over_range:1;
        RBus_UInt32  on1_ie_vs_per_over_range:1;
        RBus_UInt32  res2:5;
        RBus_UInt32  on1_ie_hs_meas_over_range:1;
        RBus_UInt32  res3:9;
        RBus_UInt32  on1_ie_to_main:1;
    };
}onms_onms1_interrupt_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  on2_start_ms:1;
        RBus_UInt32  on2_ms_conti:1;
        RBus_UInt32  on2_popup_meas:1;
        RBus_UInt32  on2_hs_meas_inv:1;
        RBus_UInt32  on2_vs_meas_inv:1;
        RBus_UInt32  on2_sycms_clk:1;
        RBus_UInt32  on2_meas_to_sel:1;
        RBus_UInt32  on2_vact_space_meas_en:1;
        RBus_UInt32  on2_vact_space_threshold:4;
        RBus_UInt32  on2_pixel_encoding:1;
        RBus_UInt32  dummy18021300_13:1;
        RBus_UInt32  dummy18021300_14:1;
        RBus_UInt32  dummy18021300_15:1;
        RBus_UInt32  on2_htotal_max_delta:4;
        RBus_UInt32  on2_vtotal_max_delta:4;
        RBus_UInt32  on2_progressive:1;
        RBus_UInt32  on2_pixel_get_sel:2;
        RBus_UInt32  on2_pixel_get_en:1;
        RBus_UInt32  on2_blk_2frame_en:1;
        RBus_UInt32  on2_ms_src_sel:1;
        RBus_UInt32  on2_4k2k_mode:2;
    };
}onms_onms2_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  on2_get_g_value:12;
        RBus_UInt32  on2_get_r_value:12;
        RBus_UInt32  on2_pixel_ok:1;
        RBus_UInt32  res1:7;
    };
}onms_onms2_blank_pixel_value_get_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  on2_get_b_value:12;
        RBus_UInt32  res1:20;
    };
}onms_onms2_blank_pixel_value_get_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  on2_active_g_value:12;
        RBus_UInt32  on2_active_r_value:12;
        RBus_UInt32  res1:8;
    };
}onms_onms2_blank_pixel_value_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  on2_active_b_value:12;
        RBus_UInt32  res1:20;
    };
}onms_onms2_blank_pixel_value_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  on2_vact1:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  on2_vact2:11;
        RBus_UInt32  res2:5;
    };
}onms_onms2_fp_vact12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  on2_vact3:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  on2_vact4:11;
        RBus_UInt32  res2:5;
    };
}onms_onms2_fp_vact34_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  on2_fp_vact_space3:10;
        RBus_UInt32  on2_fp_vact_space2:10;
        RBus_UInt32  on2_fp_vact_space1:10;
        RBus_UInt32  res1:2;
    };
}onms_onms2_fp_vact_space_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  on2_l_blank_line_end:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  on2_r_blank_line_start:11;
        RBus_UInt32  res2:5;
    };
}onms_onms2_blank_line_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  on2_vact_space1_start:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  on2_vact_space1_end:10;
        RBus_UInt32  res2:6;
    };
}onms_onms2_active_space1_line_number_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  on2_vact_space2_start:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  on2_vact_space2_end:10;
        RBus_UInt32  res2:6;
    };
}onms_onms2_active_space2_line_number_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  on2_vact_space3_start:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  on2_vact_space3_end:10;
        RBus_UInt32  res2:6;
    };
}onms_onms2_active_space3_line_number_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  on2_vtotal:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  on2_vtotalde:13;
        RBus_UInt32  res2:3;
    };
}onms_onms2_vs_period_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  on2_hs_high_period:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  on2_vs_high_period:12;
        RBus_UInt32  res2:4;
    };
}onms_onms2_vshs_high_period_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  on2_htotal_f4b:4;
        RBus_UInt32  on2_htotal_h12b:14;
        RBus_UInt32  res1:14;
    };
}onms_onms2_hs_period_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  on2_vact_start:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  on2_vblank_len:8;
        RBus_UInt32  res2:8;
    };
}onms_onms2_vact_sta_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  on2_hact_start:14;
        RBus_UInt32  res1:18;
    };
}onms_onms2_hact_sta_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  on2_hact_fract:4;
        RBus_UInt32  on2_hact:14;
        RBus_UInt32  res1:14;
    };
}onms_onms2_hact_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  on2_target_measure:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  on2_average_line:4;
        RBus_UInt32  res2:4;
        RBus_UInt32  on2_htotal_max_delta_new:7;
        RBus_UInt32  res3:1;
    };
}onms_onms2_hsync_meas_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  on2_vmeas_start:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  on2_vmeas_end:12;
        RBus_UInt32  res2:4;
    };
}onms_onms2_hsync_meas_ctrl_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  on2_hmax_delta_total:14;
        RBus_UInt32  res1:18;
    };
}onms_onms2_hsync_meas_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  on2_hs_active_pixel_var:1;
        RBus_UInt32  on2_htotal_chg:1;
        RBus_UInt32  on2_hact_chg:1;
        RBus_UInt32  on2_vtotal_chg:1;
        RBus_UInt32  on2_vtotalde_chg:1;
        RBus_UInt32  on2_hs_pol_chg:1;
        RBus_UInt32  on2_vs_pol_chg:1;
        RBus_UInt32  on2_hs_per_overflow:1;
        RBus_UInt32  on2_vs_per_overflow:1;
        RBus_UInt32  on2_vs_high_timeout:1;
        RBus_UInt32  on2_vs_per_timeout:1;
        RBus_UInt32  on2_hs_per_over_range:1;
        RBus_UInt32  on2_vs_per_over_range:1;
        RBus_UInt32  on2_hs_pol_out:1;
        RBus_UInt32  on2_vs_pol_out:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  on2_vs_per_to_long:1;
        RBus_UInt32  on2_hs_meas_over_range:1;
        RBus_UInt32  res3:10;
    };
}onms_onms2_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  on2_wd_hs_active_pixel_var:1;
        RBus_UInt32  on2_wd_htotal_chg:1;
        RBus_UInt32  on2_wd_hact_chg:1;
        RBus_UInt32  on2_wd_vtotal_chg:1;
        RBus_UInt32  on2_wd_vtotalde_chg:1;
        RBus_UInt32  on2_wd_hs_pol_chg:1;
        RBus_UInt32  on2_wd_vs_pol_chg:1;
        RBus_UInt32  on2_wd_hs_per_overflow:1;
        RBus_UInt32  on2_wd_vs_per_overflow:1;
        RBus_UInt32  on2_wd_vs_high_timeout:1;
        RBus_UInt32  on2_wd_vs_per_timeout:1;
        RBus_UInt32  on2_wd_hs_per_over_range:1;
        RBus_UInt32  on2_wd_vs_per_over_range:1;
        RBus_UInt32  res2:5;
        RBus_UInt32  on2_wd_hs_meas_over_range:1;
        RBus_UInt32  res3:8;
        RBus_UInt32  on2_wd_to_sub:1;
        RBus_UInt32  on2_wd_to_main:1;
    };
}onms_onms2_watchdog_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  on2_ie_hs_active_pixel_var:1;
        RBus_UInt32  on2_ie_htotal_chg:1;
        RBus_UInt32  on2_ie_hact_chg:1;
        RBus_UInt32  on2_ie_vtotal_chg:1;
        RBus_UInt32  on2_ie_vtotalde_chg:1;
        RBus_UInt32  on2_ie_hs_pol_chg:1;
        RBus_UInt32  on2_ie_vs_pol_chg:1;
        RBus_UInt32  on2_ie_hs_per_overflow:1;
        RBus_UInt32  on2_ie_vs_per_overflow:1;
        RBus_UInt32  on2_ie_vs_high_timeout:1;
        RBus_UInt32  on2_ie_vs_per_timeout:1;
        RBus_UInt32  on2_ie_hs_per_over_range:1;
        RBus_UInt32  on2_ie_vs_per_over_range:1;
        RBus_UInt32  res2:5;
        RBus_UInt32  on2_ie_hs_meas_over_range:1;
        RBus_UInt32  res3:9;
        RBus_UInt32  on2_ie_to_main:1;
    };
}onms_onms2_interrupt_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  on3_start_ms:1;
        RBus_UInt32  on3_ms_conti:1;
        RBus_UInt32  on3_popup_meas:1;
        RBus_UInt32  on3_hs_meas_inv:1;
        RBus_UInt32  on3_vs_meas_inv:1;
        RBus_UInt32  on3_sycms_clk:1;
        RBus_UInt32  on3_meas_to_sel:1;
        RBus_UInt32  on3_vact_space_meas_en:1;
        RBus_UInt32  on3_vact_space_threshold:4;
        RBus_UInt32  on3_pixel_encoding:1;
        RBus_UInt32  dummy18021400_13:1;
        RBus_UInt32  dummy18021400_14:1;
        RBus_UInt32  dummy18021400_15:1;
        RBus_UInt32  on3_htotal_max_delta:4;
        RBus_UInt32  on3_vtotal_max_delta:4;
        RBus_UInt32  on3_progressive:1;
        RBus_UInt32  on3_pixel_get_sel:2;
        RBus_UInt32  on3_pixel_get_en:1;
        RBus_UInt32  on3_blk_2frame_en:1;
        RBus_UInt32  on3_ms_src_sel:1;
        RBus_UInt32  on3_4k2k_mode:2;
    };
}onms_onms3_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  on3_get_g_value:12;
        RBus_UInt32  on3_get_r_value:12;
        RBus_UInt32  on3_pixel_ok:1;
        RBus_UInt32  res1:7;
    };
}onms_onms3_blank_pixel_value_get_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  on3_get_b_value:12;
        RBus_UInt32  res1:20;
    };
}onms_onms3_blank_pixel_value_get_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  on3_active_g_value:12;
        RBus_UInt32  on3_active_r_value:12;
        RBus_UInt32  res1:8;
    };
}onms_onms3_blank_pixel_value_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  on3_active_b_value:12;
        RBus_UInt32  res1:20;
    };
}onms_onms3_blank_pixel_value_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  on3_vact1:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  on3_vact2:11;
        RBus_UInt32  res2:5;
    };
}onms_onms3_fp_vact12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  on3_vact3:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  on3_vact4:11;
        RBus_UInt32  res2:5;
    };
}onms_onms3_fp_vact34_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  on3_fp_vact_space3:10;
        RBus_UInt32  on3_fp_vact_space2:10;
        RBus_UInt32  on3_fp_vact_space1:10;
        RBus_UInt32  res1:2;
    };
}onms_onms3_fp_vact_space_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  on3_l_blank_line_end:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  on3_r_blank_line_start:11;
        RBus_UInt32  res2:5;
    };
}onms_onms3_blank_line_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  on3_vact_space1_start:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  on3_vact_space1_end:10;
        RBus_UInt32  res2:6;
    };
}onms_onms3_active_space1_line_number_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  on3_vact_space2_start:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  on3_vact_space2_end:10;
        RBus_UInt32  res2:6;
    };
}onms_onms3_active_space2_line_number_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  on3_vact_space3_start:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  on3_vact_space3_end:10;
        RBus_UInt32  res2:6;
    };
}onms_onms3_active_space3_line_number_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  on3_vtotal:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  on3_vtotalde:13;
        RBus_UInt32  res2:3;
    };
}onms_onms3_vs_period_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  on3_hs_high_period:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  on3_vs_high_period:12;
        RBus_UInt32  res2:4;
    };
}onms_onms3_vshs_high_period_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  on3_htotal_f4b:4;
        RBus_UInt32  on3_htotal_h12b:14;
        RBus_UInt32  res1:14;
    };
}onms_onms3_hs_period_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  on3_vact_start:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  on3_vblank_len:8;
        RBus_UInt32  res2:8;
    };
}onms_onms3_vact_sta_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  on3_hact_start:14;
        RBus_UInt32  res1:18;
    };
}onms_onms3_hact_sta_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  on3_hact_fract:4;
        RBus_UInt32  on3_hact:14;
        RBus_UInt32  res1:14;
    };
}onms_onms3_hact_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  on3_target_measure:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  on3_average_line:4;
        RBus_UInt32  res2:4;
        RBus_UInt32  on3_htotal_max_delta_new:7;
        RBus_UInt32  res3:1;
    };
}onms_onms3_hsync_meas_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  on3_vmeas_start:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  on3_vmeas_end:12;
        RBus_UInt32  res2:4;
    };
}onms_onms3_hsync_meas_ctrl_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  on3_hmax_delta_total:14;
        RBus_UInt32  res1:18;
    };
}onms_onms3_hsync_meas_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  on3_hs_active_pixel_var:1;
        RBus_UInt32  on3_htotal_chg:1;
        RBus_UInt32  on3_hact_chg:1;
        RBus_UInt32  on3_vtotal_chg:1;
        RBus_UInt32  on3_vtotalde_chg:1;
        RBus_UInt32  on3_hs_pol_chg:1;
        RBus_UInt32  on3_vs_pol_chg:1;
        RBus_UInt32  on3_hs_per_overflow:1;
        RBus_UInt32  on3_vs_per_overflow:1;
        RBus_UInt32  on3_vs_high_timeout:1;
        RBus_UInt32  on3_vs_per_timeout:1;
        RBus_UInt32  on3_hs_per_over_range:1;
        RBus_UInt32  on3_vs_per_over_range:1;
        RBus_UInt32  on3_hs_pol_out:1;
        RBus_UInt32  on3_vs_pol_out:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  on3_vs_per_to_long:1;
        RBus_UInt32  on3_hs_meas_over_range:1;
        RBus_UInt32  res3:10;
    };
}onms_onms3_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  on3_wd_hs_active_pixel_var:1;
        RBus_UInt32  on3_wd_htotal_chg:1;
        RBus_UInt32  on3_wd_hact_chg:1;
        RBus_UInt32  on3_wd_vtotal_chg:1;
        RBus_UInt32  on3_wd_vtotalde_chg:1;
        RBus_UInt32  on3_wd_hs_pol_chg:1;
        RBus_UInt32  on3_wd_vs_pol_chg:1;
        RBus_UInt32  on3_wd_hs_per_overflow:1;
        RBus_UInt32  on3_wd_vs_per_overflow:1;
        RBus_UInt32  on3_wd_vs_high_timeout:1;
        RBus_UInt32  on3_wd_vs_per_timeout:1;
        RBus_UInt32  on3_wd_hs_per_over_range:1;
        RBus_UInt32  on3_wd_vs_per_over_range:1;
        RBus_UInt32  res2:5;
        RBus_UInt32  on3_wd_hs_meas_over_range:1;
        RBus_UInt32  res3:8;
        RBus_UInt32  on3_wd_to_sub:1;
        RBus_UInt32  on3_wd_to_main:1;
    };
}onms_onms3_watchdog_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  on3_ie_hs_active_pixel_var:1;
        RBus_UInt32  on3_ie_htotal_chg:1;
        RBus_UInt32  on3_ie_hact_chg:1;
        RBus_UInt32  on3_ie_vtotal_chg:1;
        RBus_UInt32  on3_ie_vtotalde_chg:1;
        RBus_UInt32  on3_ie_hs_pol_chg:1;
        RBus_UInt32  on3_ie_vs_pol_chg:1;
        RBus_UInt32  on3_ie_hs_per_overflow:1;
        RBus_UInt32  on3_ie_vs_per_overflow:1;
        RBus_UInt32  on3_ie_vs_high_timeout:1;
        RBus_UInt32  on3_ie_vs_per_timeout:1;
        RBus_UInt32  on3_ie_hs_per_over_range:1;
        RBus_UInt32  on3_ie_vs_per_over_range:1;
        RBus_UInt32  res2:5;
        RBus_UInt32  on3_ie_hs_meas_over_range:1;
        RBus_UInt32  res3:9;
        RBus_UInt32  on3_ie_to_main:1;
    };
}onms_onms3_interrupt_en_RBUS;




#endif 


#endif 
