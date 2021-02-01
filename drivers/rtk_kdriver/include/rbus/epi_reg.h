/**
* @file Mac5-DesignSpec-EPI
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_EPI_REG_H_
#define _RBUS_EPI_REG_H_

#include "rbus_types.h"



//  EPI Register Address
#define  EPI_EPI_PACKET_CTR1_0_0                                                 0x18026000
#define  EPI_EPI_PACKET_CTR1_0_0_reg_addr                                        "0xB8026000"
#define  EPI_EPI_PACKET_CTR1_0_0_reg                                             0xB8026000
#define  EPI_EPI_PACKET_CTR1_0_0_inst_addr                                       "0x0000"
#define  set_EPI_EPI_PACKET_CTR1_0_0_reg(data)                                   (*((volatile unsigned int*)EPI_EPI_PACKET_CTR1_0_0_reg)=data)
#define  get_EPI_EPI_PACKET_CTR1_0_0_reg                                         (*((volatile unsigned int*)EPI_EPI_PACKET_CTR1_0_0_reg))
#define  EPI_EPI_PACKET_CTR1_0_0_phase2_preamble_num_0_shift                     (16)
#define  EPI_EPI_PACKET_CTR1_0_0_phase2_preamble_num_0_mask                      (0x000F0000)
#define  EPI_EPI_PACKET_CTR1_0_0_phase2_preamble_num_0(data)                     (0x000F0000&((data)<<16))
#define  EPI_EPI_PACKET_CTR1_0_0_get_phase2_preamble_num_0(data)                 ((0x000F0000&(data))>>16)

#define  EPI_EPI_PACKET_CTR1_0_1                                                 0x18026004
#define  EPI_EPI_PACKET_CTR1_0_1_reg_addr                                        "0xB8026004"
#define  EPI_EPI_PACKET_CTR1_0_1_reg                                             0xB8026004
#define  EPI_EPI_PACKET_CTR1_0_1_inst_addr                                       "0x0001"
#define  set_EPI_EPI_PACKET_CTR1_0_1_reg(data)                                   (*((volatile unsigned int*)EPI_EPI_PACKET_CTR1_0_1_reg)=data)
#define  get_EPI_EPI_PACKET_CTR1_0_1_reg                                         (*((volatile unsigned int*)EPI_EPI_PACKET_CTR1_0_1_reg))
#define  EPI_EPI_PACKET_CTR1_0_1_phase2_preamble_num_1_shift                     (16)
#define  EPI_EPI_PACKET_CTR1_0_1_phase2_preamble_num_1_mask                      (0x000F0000)
#define  EPI_EPI_PACKET_CTR1_0_1_phase2_preamble_num_1(data)                     (0x000F0000&((data)<<16))
#define  EPI_EPI_PACKET_CTR1_0_1_get_phase2_preamble_num_1(data)                 ((0x000F0000&(data))>>16)

#define  EPI_EPI_PACKET_CTR1_0_2                                                 0x18026008
#define  EPI_EPI_PACKET_CTR1_0_2_reg_addr                                        "0xB8026008"
#define  EPI_EPI_PACKET_CTR1_0_2_reg                                             0xB8026008
#define  EPI_EPI_PACKET_CTR1_0_2_inst_addr                                       "0x0002"
#define  set_EPI_EPI_PACKET_CTR1_0_2_reg(data)                                   (*((volatile unsigned int*)EPI_EPI_PACKET_CTR1_0_2_reg)=data)
#define  get_EPI_EPI_PACKET_CTR1_0_2_reg                                         (*((volatile unsigned int*)EPI_EPI_PACKET_CTR1_0_2_reg))
#define  EPI_EPI_PACKET_CTR1_0_2_phase2_preamble_num_2_shift                     (16)
#define  EPI_EPI_PACKET_CTR1_0_2_phase2_preamble_num_2_mask                      (0x000F0000)
#define  EPI_EPI_PACKET_CTR1_0_2_phase2_preamble_num_2(data)                     (0x000F0000&((data)<<16))
#define  EPI_EPI_PACKET_CTR1_0_2_get_phase2_preamble_num_2(data)                 ((0x000F0000&(data))>>16)

#define  EPI_EPI_PACKET_CTR1_0_3                                                 0x1802600C
#define  EPI_EPI_PACKET_CTR1_0_3_reg_addr                                        "0xB802600C"
#define  EPI_EPI_PACKET_CTR1_0_3_reg                                             0xB802600C
#define  EPI_EPI_PACKET_CTR1_0_3_inst_addr                                       "0x0003"
#define  set_EPI_EPI_PACKET_CTR1_0_3_reg(data)                                   (*((volatile unsigned int*)EPI_EPI_PACKET_CTR1_0_3_reg)=data)
#define  get_EPI_EPI_PACKET_CTR1_0_3_reg                                         (*((volatile unsigned int*)EPI_EPI_PACKET_CTR1_0_3_reg))
#define  EPI_EPI_PACKET_CTR1_0_3_phase2_preamble_num_3_shift                     (16)
#define  EPI_EPI_PACKET_CTR1_0_3_phase2_preamble_num_3_mask                      (0x000F0000)
#define  EPI_EPI_PACKET_CTR1_0_3_phase2_preamble_num_3(data)                     (0x000F0000&((data)<<16))
#define  EPI_EPI_PACKET_CTR1_0_3_get_phase2_preamble_num_3(data)                 ((0x000F0000&(data))>>16)

#define  EPI_EPI_PACKET_CTR1_0_4                                                 0x18026010
#define  EPI_EPI_PACKET_CTR1_0_4_reg_addr                                        "0xB8026010"
#define  EPI_EPI_PACKET_CTR1_0_4_reg                                             0xB8026010
#define  EPI_EPI_PACKET_CTR1_0_4_inst_addr                                       "0x0004"
#define  set_EPI_EPI_PACKET_CTR1_0_4_reg(data)                                   (*((volatile unsigned int*)EPI_EPI_PACKET_CTR1_0_4_reg)=data)
#define  get_EPI_EPI_PACKET_CTR1_0_4_reg                                         (*((volatile unsigned int*)EPI_EPI_PACKET_CTR1_0_4_reg))
#define  EPI_EPI_PACKET_CTR1_0_4_phase2_preamble_num_4_shift                     (16)
#define  EPI_EPI_PACKET_CTR1_0_4_phase2_preamble_num_4_mask                      (0x000F0000)
#define  EPI_EPI_PACKET_CTR1_0_4_phase2_preamble_num_4(data)                     (0x000F0000&((data)<<16))
#define  EPI_EPI_PACKET_CTR1_0_4_get_phase2_preamble_num_4(data)                 ((0x000F0000&(data))>>16)

#define  EPI_EPI_PACKET_CTR1_0_5                                                 0x18026014
#define  EPI_EPI_PACKET_CTR1_0_5_reg_addr                                        "0xB8026014"
#define  EPI_EPI_PACKET_CTR1_0_5_reg                                             0xB8026014
#define  EPI_EPI_PACKET_CTR1_0_5_inst_addr                                       "0x0005"
#define  set_EPI_EPI_PACKET_CTR1_0_5_reg(data)                                   (*((volatile unsigned int*)EPI_EPI_PACKET_CTR1_0_5_reg)=data)
#define  get_EPI_EPI_PACKET_CTR1_0_5_reg                                         (*((volatile unsigned int*)EPI_EPI_PACKET_CTR1_0_5_reg))
#define  EPI_EPI_PACKET_CTR1_0_5_phase2_preamble_num_5_shift                     (16)
#define  EPI_EPI_PACKET_CTR1_0_5_phase2_preamble_num_5_mask                      (0x000F0000)
#define  EPI_EPI_PACKET_CTR1_0_5_phase2_preamble_num_5(data)                     (0x000F0000&((data)<<16))
#define  EPI_EPI_PACKET_CTR1_0_5_get_phase2_preamble_num_5(data)                 ((0x000F0000&(data))>>16)

#define  EPI_EPI_PACKET_CTR1_0_6                                                 0x18026018
#define  EPI_EPI_PACKET_CTR1_0_6_reg_addr                                        "0xB8026018"
#define  EPI_EPI_PACKET_CTR1_0_6_reg                                             0xB8026018
#define  EPI_EPI_PACKET_CTR1_0_6_inst_addr                                       "0x0006"
#define  set_EPI_EPI_PACKET_CTR1_0_6_reg(data)                                   (*((volatile unsigned int*)EPI_EPI_PACKET_CTR1_0_6_reg)=data)
#define  get_EPI_EPI_PACKET_CTR1_0_6_reg                                         (*((volatile unsigned int*)EPI_EPI_PACKET_CTR1_0_6_reg))
#define  EPI_EPI_PACKET_CTR1_0_6_phase2_preamble_num_6_shift                     (16)
#define  EPI_EPI_PACKET_CTR1_0_6_phase2_preamble_num_6_mask                      (0x000F0000)
#define  EPI_EPI_PACKET_CTR1_0_6_phase2_preamble_num_6(data)                     (0x000F0000&((data)<<16))
#define  EPI_EPI_PACKET_CTR1_0_6_get_phase2_preamble_num_6(data)                 ((0x000F0000&(data))>>16)

#define  EPI_EPI_PACKET_CTR1_0_7                                                 0x1802601C
#define  EPI_EPI_PACKET_CTR1_0_7_reg_addr                                        "0xB802601C"
#define  EPI_EPI_PACKET_CTR1_0_7_reg                                             0xB802601C
#define  EPI_EPI_PACKET_CTR1_0_7_inst_addr                                       "0x0007"
#define  set_EPI_EPI_PACKET_CTR1_0_7_reg(data)                                   (*((volatile unsigned int*)EPI_EPI_PACKET_CTR1_0_7_reg)=data)
#define  get_EPI_EPI_PACKET_CTR1_0_7_reg                                         (*((volatile unsigned int*)EPI_EPI_PACKET_CTR1_0_7_reg))
#define  EPI_EPI_PACKET_CTR1_0_7_phase2_preamble_num_7_shift                     (16)
#define  EPI_EPI_PACKET_CTR1_0_7_phase2_preamble_num_7_mask                      (0x000F0000)
#define  EPI_EPI_PACKET_CTR1_0_7_phase2_preamble_num_7(data)                     (0x000F0000&((data)<<16))
#define  EPI_EPI_PACKET_CTR1_0_7_get_phase2_preamble_num_7(data)                 ((0x000F0000&(data))>>16)

#define  EPI_EPI_PACKET_CTRL                                                     0x18026060
#define  EPI_EPI_PACKET_CTRL_reg_addr                                            "0xB8026060"
#define  EPI_EPI_PACKET_CTRL_reg                                                 0xB8026060
#define  EPI_EPI_PACKET_CTRL_inst_addr                                           "0x0008"
#define  set_EPI_EPI_PACKET_CTRL_reg(data)                                       (*((volatile unsigned int*)EPI_EPI_PACKET_CTRL_reg)=data)
#define  get_EPI_EPI_PACKET_CTRL_reg                                             (*((volatile unsigned int*)EPI_EPI_PACKET_CTRL_reg))
#define  EPI_EPI_PACKET_CTRL_epi_data_unfl_shift                                 (31)
#define  EPI_EPI_PACKET_CTRL_epi_data_unfl_clr_shift                             (30)
#define  EPI_EPI_PACKET_CTRL_prbs7_tx_en_shift                                   (29)
#define  EPI_EPI_PACKET_CTRL_epi_bit_mode_shift                                  (27)
#define  EPI_EPI_PACKET_CTRL_bist_mode_select_shift                              (24)
#define  EPI_EPI_PACKET_CTRL_data_mode_change_shift                              (23)
#define  EPI_EPI_PACKET_CTRL_data_mode_flag_clr_shift                            (22)
#define  EPI_EPI_PACKET_CTRL_bist_pattern_0_shift                                (4)
#define  EPI_EPI_PACKET_CTRL_pn_swap_shift                                       (3)
#define  EPI_EPI_PACKET_CTRL_epi_version_shift                                   (0)
#define  EPI_EPI_PACKET_CTRL_epi_data_unfl_mask                                  (0x80000000)
#define  EPI_EPI_PACKET_CTRL_epi_data_unfl_clr_mask                              (0x40000000)
#define  EPI_EPI_PACKET_CTRL_prbs7_tx_en_mask                                    (0x20000000)
#define  EPI_EPI_PACKET_CTRL_epi_bit_mode_mask                                   (0x18000000)
#define  EPI_EPI_PACKET_CTRL_bist_mode_select_mask                               (0x07000000)
#define  EPI_EPI_PACKET_CTRL_data_mode_change_mask                               (0x00800000)
#define  EPI_EPI_PACKET_CTRL_data_mode_flag_clr_mask                             (0x00400000)
#define  EPI_EPI_PACKET_CTRL_bist_pattern_0_mask                                 (0x003FFFF0)
#define  EPI_EPI_PACKET_CTRL_pn_swap_mask                                        (0x00000008)
#define  EPI_EPI_PACKET_CTRL_epi_version_mask                                    (0x00000007)
#define  EPI_EPI_PACKET_CTRL_epi_data_unfl(data)                                 (0x80000000&((data)<<31))
#define  EPI_EPI_PACKET_CTRL_epi_data_unfl_clr(data)                             (0x40000000&((data)<<30))
#define  EPI_EPI_PACKET_CTRL_prbs7_tx_en(data)                                   (0x20000000&((data)<<29))
#define  EPI_EPI_PACKET_CTRL_epi_bit_mode(data)                                  (0x18000000&((data)<<27))
#define  EPI_EPI_PACKET_CTRL_bist_mode_select(data)                              (0x07000000&((data)<<24))
#define  EPI_EPI_PACKET_CTRL_data_mode_change(data)                              (0x00800000&((data)<<23))
#define  EPI_EPI_PACKET_CTRL_data_mode_flag_clr(data)                            (0x00400000&((data)<<22))
#define  EPI_EPI_PACKET_CTRL_bist_pattern_0(data)                                (0x003FFFF0&((data)<<4))
#define  EPI_EPI_PACKET_CTRL_pn_swap(data)                                       (0x00000008&((data)<<3))
#define  EPI_EPI_PACKET_CTRL_epi_version(data)                                   (0x00000007&(data))
#define  EPI_EPI_PACKET_CTRL_get_epi_data_unfl(data)                             ((0x80000000&(data))>>31)
#define  EPI_EPI_PACKET_CTRL_get_epi_data_unfl_clr(data)                         ((0x40000000&(data))>>30)
#define  EPI_EPI_PACKET_CTRL_get_prbs7_tx_en(data)                               ((0x20000000&(data))>>29)
#define  EPI_EPI_PACKET_CTRL_get_epi_bit_mode(data)                              ((0x18000000&(data))>>27)
#define  EPI_EPI_PACKET_CTRL_get_bist_mode_select(data)                          ((0x07000000&(data))>>24)
#define  EPI_EPI_PACKET_CTRL_get_data_mode_change(data)                          ((0x00800000&(data))>>23)
#define  EPI_EPI_PACKET_CTRL_get_data_mode_flag_clr(data)                        ((0x00400000&(data))>>22)
#define  EPI_EPI_PACKET_CTRL_get_bist_pattern_0(data)                            ((0x003FFFF0&(data))>>4)
#define  EPI_EPI_PACKET_CTRL_get_pn_swap(data)                                   ((0x00000008&(data))>>3)
#define  EPI_EPI_PACKET_CTRL_get_epi_version(data)                               (0x00000007&(data))

#define  EPI_EPI_CLOCK_CTRL0                                                     0x18026064
#define  EPI_EPI_CLOCK_CTRL0_reg_addr                                            "0xB8026064"
#define  EPI_EPI_CLOCK_CTRL0_reg                                                 0xB8026064
#define  EPI_EPI_CLOCK_CTRL0_inst_addr                                           "0x0009"
#define  set_EPI_EPI_CLOCK_CTRL0_reg(data)                                       (*((volatile unsigned int*)EPI_EPI_CLOCK_CTRL0_reg)=data)
#define  get_EPI_EPI_CLOCK_CTRL0_reg                                             (*((volatile unsigned int*)EPI_EPI_CLOCK_CTRL0_reg))
#define  EPI_EPI_CLOCK_CTRL0_force_ctsfifo_rstn_epi_shift                        (31)
#define  EPI_EPI_CLOCK_CTRL0_dummy_30_29_shift                                   (29)
#define  EPI_EPI_CLOCK_CTRL0_epi_reset_shift                                     (28)
#define  EPI_EPI_CLOCK_CTRL0_ctrl_start_en_shift                                 (26)
#define  EPI_EPI_CLOCK_CTRL0_ctrl3_en_shift                                      (25)
#define  EPI_EPI_CLOCK_CTRL0_data_start_en_shift                                 (24)
#define  EPI_EPI_CLOCK_CTRL0_bist_pattern_1_shift                                (4)
#define  EPI_EPI_CLOCK_CTRL0_hw_lock_shift                                       (3)
#define  EPI_EPI_CLOCK_CTRL0_epi_lock_shift                                      (2)
#define  EPI_EPI_CLOCK_CTRL0_epi_lock_sel_shift                                  (1)
#define  EPI_EPI_CLOCK_CTRL0_force_ctsfifo_rstn_epi_mask                         (0x80000000)
#define  EPI_EPI_CLOCK_CTRL0_dummy_30_29_mask                                    (0x60000000)
#define  EPI_EPI_CLOCK_CTRL0_epi_reset_mask                                      (0x10000000)
#define  EPI_EPI_CLOCK_CTRL0_ctrl_start_en_mask                                  (0x04000000)
#define  EPI_EPI_CLOCK_CTRL0_ctrl3_en_mask                                       (0x02000000)
#define  EPI_EPI_CLOCK_CTRL0_data_start_en_mask                                  (0x01000000)
#define  EPI_EPI_CLOCK_CTRL0_bist_pattern_1_mask                                 (0x003FFFF0)
#define  EPI_EPI_CLOCK_CTRL0_hw_lock_mask                                        (0x00000008)
#define  EPI_EPI_CLOCK_CTRL0_epi_lock_mask                                       (0x00000004)
#define  EPI_EPI_CLOCK_CTRL0_epi_lock_sel_mask                                   (0x00000002)
#define  EPI_EPI_CLOCK_CTRL0_force_ctsfifo_rstn_epi(data)                        (0x80000000&((data)<<31))
#define  EPI_EPI_CLOCK_CTRL0_dummy_30_29(data)                                   (0x60000000&((data)<<29))
#define  EPI_EPI_CLOCK_CTRL0_epi_reset(data)                                     (0x10000000&((data)<<28))
#define  EPI_EPI_CLOCK_CTRL0_ctrl_start_en(data)                                 (0x04000000&((data)<<26))
#define  EPI_EPI_CLOCK_CTRL0_ctrl3_en(data)                                      (0x02000000&((data)<<25))
#define  EPI_EPI_CLOCK_CTRL0_data_start_en(data)                                 (0x01000000&((data)<<24))
#define  EPI_EPI_CLOCK_CTRL0_bist_pattern_1(data)                                (0x003FFFF0&((data)<<4))
#define  EPI_EPI_CLOCK_CTRL0_hw_lock(data)                                       (0x00000008&((data)<<3))
#define  EPI_EPI_CLOCK_CTRL0_epi_lock(data)                                      (0x00000004&((data)<<2))
#define  EPI_EPI_CLOCK_CTRL0_epi_lock_sel(data)                                  (0x00000002&((data)<<1))
#define  EPI_EPI_CLOCK_CTRL0_get_force_ctsfifo_rstn_epi(data)                    ((0x80000000&(data))>>31)
#define  EPI_EPI_CLOCK_CTRL0_get_dummy_30_29(data)                               ((0x60000000&(data))>>29)
#define  EPI_EPI_CLOCK_CTRL0_get_epi_reset(data)                                 ((0x10000000&(data))>>28)
#define  EPI_EPI_CLOCK_CTRL0_get_ctrl_start_en(data)                             ((0x04000000&(data))>>26)
#define  EPI_EPI_CLOCK_CTRL0_get_ctrl3_en(data)                                  ((0x02000000&(data))>>25)
#define  EPI_EPI_CLOCK_CTRL0_get_data_start_en(data)                             ((0x01000000&(data))>>24)
#define  EPI_EPI_CLOCK_CTRL0_get_bist_pattern_1(data)                            ((0x003FFFF0&(data))>>4)
#define  EPI_EPI_CLOCK_CTRL0_get_hw_lock(data)                                   ((0x00000008&(data))>>3)
#define  EPI_EPI_CLOCK_CTRL0_get_epi_lock(data)                                  ((0x00000004&(data))>>2)
#define  EPI_EPI_CLOCK_CTRL0_get_epi_lock_sel(data)                              ((0x00000002&(data))>>1)

#define  EPI_EPI_PACKET_CTRL2                                                    0x18026068
#define  EPI_EPI_PACKET_CTRL2_reg_addr                                           "0xB8026068"
#define  EPI_EPI_PACKET_CTRL2_reg                                                0xB8026068
#define  EPI_EPI_PACKET_CTRL2_inst_addr                                          "0x000A"
#define  set_EPI_EPI_PACKET_CTRL2_reg(data)                                      (*((volatile unsigned int*)EPI_EPI_PACKET_CTRL2_reg)=data)
#define  get_EPI_EPI_PACKET_CTRL2_reg                                            (*((volatile unsigned int*)EPI_EPI_PACKET_CTRL2_reg))
#define  EPI_EPI_PACKET_CTRL2_epi_out_swap_shift                                 (0)
#define  EPI_EPI_PACKET_CTRL2_epi_out_swap_mask                                  (0x000000FF)
#define  EPI_EPI_PACKET_CTRL2_epi_out_swap(data)                                 (0x000000FF&(data))
#define  EPI_EPI_PACKET_CTRL2_get_epi_out_swap(data)                             (0x000000FF&(data))

#define  EPI_EPI_PORT_OPTION_CTRL                                                0x1802606C
#define  EPI_EPI_PORT_OPTION_CTRL_reg_addr                                       "0xB802606C"
#define  EPI_EPI_PORT_OPTION_CTRL_reg                                            0xB802606C
#define  EPI_EPI_PORT_OPTION_CTRL_inst_addr                                      "0x000B"
#define  set_EPI_EPI_PORT_OPTION_CTRL_reg(data)                                  (*((volatile unsigned int*)EPI_EPI_PORT_OPTION_CTRL_reg)=data)
#define  get_EPI_EPI_PORT_OPTION_CTRL_reg                                        (*((volatile unsigned int*)EPI_EPI_PORT_OPTION_CTRL_reg))
#define  EPI_EPI_PORT_OPTION_CTRL_two_pixel_mode_shift                           (31)
#define  EPI_EPI_PORT_OPTION_CTRL_ext_subpixel_mode_shift                        (30)
#define  EPI_EPI_PORT_OPTION_CTRL_port_num_shift                                 (20)
#define  EPI_EPI_PORT_OPTION_CTRL_epi_enable_shift                               (16)
#define  EPI_EPI_PORT_OPTION_CTRL_back_value_shift                               (14)
#define  EPI_EPI_PORT_OPTION_CTRL_front_value_shift                              (12)
#define  EPI_EPI_PORT_OPTION_CTRL_dummy_9_shift                                  (9)
#define  EPI_EPI_PORT_OPTION_CTRL_two_pixel_mode_mask                            (0x80000000)
#define  EPI_EPI_PORT_OPTION_CTRL_ext_subpixel_mode_mask                         (0x40000000)
#define  EPI_EPI_PORT_OPTION_CTRL_port_num_mask                                  (0x01F00000)
#define  EPI_EPI_PORT_OPTION_CTRL_epi_enable_mask                                (0x00010000)
#define  EPI_EPI_PORT_OPTION_CTRL_back_value_mask                                (0x0000C000)
#define  EPI_EPI_PORT_OPTION_CTRL_front_value_mask                               (0x00003000)
#define  EPI_EPI_PORT_OPTION_CTRL_dummy_9_mask                                   (0x00000200)
#define  EPI_EPI_PORT_OPTION_CTRL_two_pixel_mode(data)                           (0x80000000&((data)<<31))
#define  EPI_EPI_PORT_OPTION_CTRL_ext_subpixel_mode(data)                        (0x40000000&((data)<<30))
#define  EPI_EPI_PORT_OPTION_CTRL_port_num(data)                                 (0x01F00000&((data)<<20))
#define  EPI_EPI_PORT_OPTION_CTRL_epi_enable(data)                               (0x00010000&((data)<<16))
#define  EPI_EPI_PORT_OPTION_CTRL_back_value(data)                               (0x0000C000&((data)<<14))
#define  EPI_EPI_PORT_OPTION_CTRL_front_value(data)                              (0x00003000&((data)<<12))
#define  EPI_EPI_PORT_OPTION_CTRL_dummy_9(data)                                  (0x00000200&((data)<<9))
#define  EPI_EPI_PORT_OPTION_CTRL_get_two_pixel_mode(data)                       ((0x80000000&(data))>>31)
#define  EPI_EPI_PORT_OPTION_CTRL_get_ext_subpixel_mode(data)                    ((0x40000000&(data))>>30)
#define  EPI_EPI_PORT_OPTION_CTRL_get_port_num(data)                             ((0x01F00000&(data))>>20)
#define  EPI_EPI_PORT_OPTION_CTRL_get_epi_enable(data)                           ((0x00010000&(data))>>16)
#define  EPI_EPI_PORT_OPTION_CTRL_get_back_value(data)                           ((0x0000C000&(data))>>14)
#define  EPI_EPI_PORT_OPTION_CTRL_get_front_value(data)                          ((0x00003000&(data))>>12)
#define  EPI_EPI_PORT_OPTION_CTRL_get_dummy_9(data)                              ((0x00000200&(data))>>9)

#define  EPI_EPI_CMPI_FRONT                                                      0x18026070
#define  EPI_EPI_CMPI_FRONT_reg_addr                                             "0xB8026070"
#define  EPI_EPI_CMPI_FRONT_reg                                                  0xB8026070
#define  EPI_EPI_CMPI_FRONT_inst_addr                                            "0x000C"
#define  set_EPI_EPI_CMPI_FRONT_reg(data)                                        (*((volatile unsigned int*)EPI_EPI_CMPI_FRONT_reg)=data)
#define  get_EPI_EPI_CMPI_FRONT_reg                                              (*((volatile unsigned int*)EPI_EPI_CMPI_FRONT_reg))
#define  EPI_EPI_CMPI_FRONT_epi_dbg_en_shift                                     (31)
#define  EPI_EPI_CMPI_FRONT_epi_otpin_ver_sel_shift                              (28)
#define  EPI_EPI_CMPI_FRONT_dummy_24_20_shift                                    (20)
#define  EPI_EPI_CMPI_FRONT_epi_otpin_port_sel_shift                             (12)
#define  EPI_EPI_CMPI_FRONT_front_cmd_shift                                      (8)
#define  EPI_EPI_CMPI_FRONT_front_data_shift                                     (4)
#define  EPI_EPI_CMPI_FRONT_epi_dbg_en_mask                                      (0x80000000)
#define  EPI_EPI_CMPI_FRONT_epi_otpin_ver_sel_mask                               (0x10000000)
#define  EPI_EPI_CMPI_FRONT_dummy_24_20_mask                                     (0x01F00000)
#define  EPI_EPI_CMPI_FRONT_epi_otpin_port_sel_mask                              (0x0001F000)
#define  EPI_EPI_CMPI_FRONT_front_cmd_mask                                       (0x00000700)
#define  EPI_EPI_CMPI_FRONT_front_data_mask                                      (0x00000070)
#define  EPI_EPI_CMPI_FRONT_epi_dbg_en(data)                                     (0x80000000&((data)<<31))
#define  EPI_EPI_CMPI_FRONT_epi_otpin_ver_sel(data)                              (0x10000000&((data)<<28))
#define  EPI_EPI_CMPI_FRONT_dummy_24_20(data)                                    (0x01F00000&((data)<<20))
#define  EPI_EPI_CMPI_FRONT_epi_otpin_port_sel(data)                             (0x0001F000&((data)<<12))
#define  EPI_EPI_CMPI_FRONT_front_cmd(data)                                      (0x00000700&((data)<<8))
#define  EPI_EPI_CMPI_FRONT_front_data(data)                                     (0x00000070&((data)<<4))
#define  EPI_EPI_CMPI_FRONT_get_epi_dbg_en(data)                                 ((0x80000000&(data))>>31)
#define  EPI_EPI_CMPI_FRONT_get_epi_otpin_ver_sel(data)                          ((0x10000000&(data))>>28)
#define  EPI_EPI_CMPI_FRONT_get_dummy_24_20(data)                                ((0x01F00000&(data))>>20)
#define  EPI_EPI_CMPI_FRONT_get_epi_otpin_port_sel(data)                         ((0x0001F000&(data))>>12)
#define  EPI_EPI_CMPI_FRONT_get_front_cmd(data)                                  ((0x00000700&(data))>>8)
#define  EPI_EPI_CMPI_FRONT_get_front_data(data)                                 ((0x00000070&(data))>>4)

#define  EPI_EPI_DUMMY_EN_0                                                      0x18026074
#define  EPI_EPI_DUMMY_EN_0_reg_addr                                             "0xB8026074"
#define  EPI_EPI_DUMMY_EN_0_reg                                                  0xB8026074
#define  EPI_EPI_DUMMY_EN_0_inst_addr                                            "0x000D"
#define  set_EPI_EPI_DUMMY_EN_0_reg(data)                                        (*((volatile unsigned int*)EPI_EPI_DUMMY_EN_0_reg)=data)
#define  get_EPI_EPI_DUMMY_EN_0_reg                                              (*((volatile unsigned int*)EPI_EPI_DUMMY_EN_0_reg))
#define  EPI_EPI_DUMMY_EN_0_front_dummy_num_shift                                (16)
#define  EPI_EPI_DUMMY_EN_0_back_dummy_num_shift                                 (0)
#define  EPI_EPI_DUMMY_EN_0_front_dummy_num_mask                                 (0x001F0000)
#define  EPI_EPI_DUMMY_EN_0_back_dummy_num_mask                                  (0x0000001F)
#define  EPI_EPI_DUMMY_EN_0_front_dummy_num(data)                                (0x001F0000&((data)<<16))
#define  EPI_EPI_DUMMY_EN_0_back_dummy_num(data)                                 (0x0000001F&(data))
#define  EPI_EPI_DUMMY_EN_0_get_front_dummy_num(data)                            ((0x001F0000&(data))>>16)
#define  EPI_EPI_DUMMY_EN_0_get_back_dummy_num(data)                             (0x0000001F&(data))

#define  EPI_EPI_DUMMY_SEL_0                                                     0x18026078
#define  EPI_EPI_DUMMY_SEL_0_reg_addr                                            "0xB8026078"
#define  EPI_EPI_DUMMY_SEL_0_reg                                                 0xB8026078
#define  EPI_EPI_DUMMY_SEL_0_inst_addr                                           "0x000E"
#define  set_EPI_EPI_DUMMY_SEL_0_reg(data)                                       (*((volatile unsigned int*)EPI_EPI_DUMMY_SEL_0_reg)=data)
#define  get_EPI_EPI_DUMMY_SEL_0_reg                                             (*((volatile unsigned int*)EPI_EPI_DUMMY_SEL_0_reg))
#define  EPI_EPI_DUMMY_SEL_0_f15_dummy_color_sel_shift                           (30)
#define  EPI_EPI_DUMMY_SEL_0_f14_dummy_color_sel_shift                           (28)
#define  EPI_EPI_DUMMY_SEL_0_f13_dummy_color_sel_shift                           (26)
#define  EPI_EPI_DUMMY_SEL_0_f12_dummy_color_sel_shift                           (24)
#define  EPI_EPI_DUMMY_SEL_0_f11_dummy_color_sel_shift                           (22)
#define  EPI_EPI_DUMMY_SEL_0_f10_dummy_color_sel_shift                           (20)
#define  EPI_EPI_DUMMY_SEL_0_f9_dummy_color_sel_shift                            (18)
#define  EPI_EPI_DUMMY_SEL_0_f8_dummy_color_sel_shift                            (16)
#define  EPI_EPI_DUMMY_SEL_0_f7_dummy_color_sel_shift                            (14)
#define  EPI_EPI_DUMMY_SEL_0_f6_dummy_color_sel_shift                            (12)
#define  EPI_EPI_DUMMY_SEL_0_f5_dummy_color_sel_shift                            (10)
#define  EPI_EPI_DUMMY_SEL_0_f4_dummy_color_sel_shift                            (8)
#define  EPI_EPI_DUMMY_SEL_0_f3_dummy_color_sel_shift                            (6)
#define  EPI_EPI_DUMMY_SEL_0_f2_dummy_color_sel_shift                            (4)
#define  EPI_EPI_DUMMY_SEL_0_f1_dummy_color_sel_shift                            (2)
#define  EPI_EPI_DUMMY_SEL_0_f0_dummy_color_sel_shift                            (0)
#define  EPI_EPI_DUMMY_SEL_0_f15_dummy_color_sel_mask                            (0xC0000000)
#define  EPI_EPI_DUMMY_SEL_0_f14_dummy_color_sel_mask                            (0x30000000)
#define  EPI_EPI_DUMMY_SEL_0_f13_dummy_color_sel_mask                            (0x0C000000)
#define  EPI_EPI_DUMMY_SEL_0_f12_dummy_color_sel_mask                            (0x03000000)
#define  EPI_EPI_DUMMY_SEL_0_f11_dummy_color_sel_mask                            (0x00C00000)
#define  EPI_EPI_DUMMY_SEL_0_f10_dummy_color_sel_mask                            (0x00300000)
#define  EPI_EPI_DUMMY_SEL_0_f9_dummy_color_sel_mask                             (0x000C0000)
#define  EPI_EPI_DUMMY_SEL_0_f8_dummy_color_sel_mask                             (0x00030000)
#define  EPI_EPI_DUMMY_SEL_0_f7_dummy_color_sel_mask                             (0x0000C000)
#define  EPI_EPI_DUMMY_SEL_0_f6_dummy_color_sel_mask                             (0x00003000)
#define  EPI_EPI_DUMMY_SEL_0_f5_dummy_color_sel_mask                             (0x00000C00)
#define  EPI_EPI_DUMMY_SEL_0_f4_dummy_color_sel_mask                             (0x00000300)
#define  EPI_EPI_DUMMY_SEL_0_f3_dummy_color_sel_mask                             (0x000000C0)
#define  EPI_EPI_DUMMY_SEL_0_f2_dummy_color_sel_mask                             (0x00000030)
#define  EPI_EPI_DUMMY_SEL_0_f1_dummy_color_sel_mask                             (0x0000000C)
#define  EPI_EPI_DUMMY_SEL_0_f0_dummy_color_sel_mask                             (0x00000003)
#define  EPI_EPI_DUMMY_SEL_0_f15_dummy_color_sel(data)                           (0xC0000000&((data)<<30))
#define  EPI_EPI_DUMMY_SEL_0_f14_dummy_color_sel(data)                           (0x30000000&((data)<<28))
#define  EPI_EPI_DUMMY_SEL_0_f13_dummy_color_sel(data)                           (0x0C000000&((data)<<26))
#define  EPI_EPI_DUMMY_SEL_0_f12_dummy_color_sel(data)                           (0x03000000&((data)<<24))
#define  EPI_EPI_DUMMY_SEL_0_f11_dummy_color_sel(data)                           (0x00C00000&((data)<<22))
#define  EPI_EPI_DUMMY_SEL_0_f10_dummy_color_sel(data)                           (0x00300000&((data)<<20))
#define  EPI_EPI_DUMMY_SEL_0_f9_dummy_color_sel(data)                            (0x000C0000&((data)<<18))
#define  EPI_EPI_DUMMY_SEL_0_f8_dummy_color_sel(data)                            (0x00030000&((data)<<16))
#define  EPI_EPI_DUMMY_SEL_0_f7_dummy_color_sel(data)                            (0x0000C000&((data)<<14))
#define  EPI_EPI_DUMMY_SEL_0_f6_dummy_color_sel(data)                            (0x00003000&((data)<<12))
#define  EPI_EPI_DUMMY_SEL_0_f5_dummy_color_sel(data)                            (0x00000C00&((data)<<10))
#define  EPI_EPI_DUMMY_SEL_0_f4_dummy_color_sel(data)                            (0x00000300&((data)<<8))
#define  EPI_EPI_DUMMY_SEL_0_f3_dummy_color_sel(data)                            (0x000000C0&((data)<<6))
#define  EPI_EPI_DUMMY_SEL_0_f2_dummy_color_sel(data)                            (0x00000030&((data)<<4))
#define  EPI_EPI_DUMMY_SEL_0_f1_dummy_color_sel(data)                            (0x0000000C&((data)<<2))
#define  EPI_EPI_DUMMY_SEL_0_f0_dummy_color_sel(data)                            (0x00000003&(data))
#define  EPI_EPI_DUMMY_SEL_0_get_f15_dummy_color_sel(data)                       ((0xC0000000&(data))>>30)
#define  EPI_EPI_DUMMY_SEL_0_get_f14_dummy_color_sel(data)                       ((0x30000000&(data))>>28)
#define  EPI_EPI_DUMMY_SEL_0_get_f13_dummy_color_sel(data)                       ((0x0C000000&(data))>>26)
#define  EPI_EPI_DUMMY_SEL_0_get_f12_dummy_color_sel(data)                       ((0x03000000&(data))>>24)
#define  EPI_EPI_DUMMY_SEL_0_get_f11_dummy_color_sel(data)                       ((0x00C00000&(data))>>22)
#define  EPI_EPI_DUMMY_SEL_0_get_f10_dummy_color_sel(data)                       ((0x00300000&(data))>>20)
#define  EPI_EPI_DUMMY_SEL_0_get_f9_dummy_color_sel(data)                        ((0x000C0000&(data))>>18)
#define  EPI_EPI_DUMMY_SEL_0_get_f8_dummy_color_sel(data)                        ((0x00030000&(data))>>16)
#define  EPI_EPI_DUMMY_SEL_0_get_f7_dummy_color_sel(data)                        ((0x0000C000&(data))>>14)
#define  EPI_EPI_DUMMY_SEL_0_get_f6_dummy_color_sel(data)                        ((0x00003000&(data))>>12)
#define  EPI_EPI_DUMMY_SEL_0_get_f5_dummy_color_sel(data)                        ((0x00000C00&(data))>>10)
#define  EPI_EPI_DUMMY_SEL_0_get_f4_dummy_color_sel(data)                        ((0x00000300&(data))>>8)
#define  EPI_EPI_DUMMY_SEL_0_get_f3_dummy_color_sel(data)                        ((0x000000C0&(data))>>6)
#define  EPI_EPI_DUMMY_SEL_0_get_f2_dummy_color_sel(data)                        ((0x00000030&(data))>>4)
#define  EPI_EPI_DUMMY_SEL_0_get_f1_dummy_color_sel(data)                        ((0x0000000C&(data))>>2)
#define  EPI_EPI_DUMMY_SEL_0_get_f0_dummy_color_sel(data)                        (0x00000003&(data))

#define  EPI_EPI_DUMMY_SEL_1                                                     0x1802607C
#define  EPI_EPI_DUMMY_SEL_1_reg_addr                                            "0xB802607C"
#define  EPI_EPI_DUMMY_SEL_1_reg                                                 0xB802607C
#define  EPI_EPI_DUMMY_SEL_1_inst_addr                                           "0x000F"
#define  set_EPI_EPI_DUMMY_SEL_1_reg(data)                                       (*((volatile unsigned int*)EPI_EPI_DUMMY_SEL_1_reg)=data)
#define  get_EPI_EPI_DUMMY_SEL_1_reg                                             (*((volatile unsigned int*)EPI_EPI_DUMMY_SEL_1_reg))
#define  EPI_EPI_DUMMY_SEL_1_b0_dummy_color_sel_shift                            (30)
#define  EPI_EPI_DUMMY_SEL_1_b1_dummy_color_sel_shift                            (28)
#define  EPI_EPI_DUMMY_SEL_1_b2_dummy_color_sel_shift                            (26)
#define  EPI_EPI_DUMMY_SEL_1_b3_dummy_color_sel_shift                            (24)
#define  EPI_EPI_DUMMY_SEL_1_b4_dummy_color_sel_shift                            (22)
#define  EPI_EPI_DUMMY_SEL_1_b5_dummy_color_sel_shift                            (20)
#define  EPI_EPI_DUMMY_SEL_1_b6_dummy_color_sel_shift                            (18)
#define  EPI_EPI_DUMMY_SEL_1_b7_dummy_color_sel_shift                            (16)
#define  EPI_EPI_DUMMY_SEL_1_b8_dummy_color_sel_shift                            (14)
#define  EPI_EPI_DUMMY_SEL_1_b9_dummy_color_sel_shift                            (12)
#define  EPI_EPI_DUMMY_SEL_1_b10_dummy_color_sel_shift                           (10)
#define  EPI_EPI_DUMMY_SEL_1_b11_dummy_color_sel_shift                           (8)
#define  EPI_EPI_DUMMY_SEL_1_b12_dummy_color_sel_shift                           (6)
#define  EPI_EPI_DUMMY_SEL_1_b13_dummy_color_sel_shift                           (4)
#define  EPI_EPI_DUMMY_SEL_1_b14_dummy_color_sel_shift                           (2)
#define  EPI_EPI_DUMMY_SEL_1_b15_dummy_color_sel_shift                           (0)
#define  EPI_EPI_DUMMY_SEL_1_b0_dummy_color_sel_mask                             (0xC0000000)
#define  EPI_EPI_DUMMY_SEL_1_b1_dummy_color_sel_mask                             (0x30000000)
#define  EPI_EPI_DUMMY_SEL_1_b2_dummy_color_sel_mask                             (0x0C000000)
#define  EPI_EPI_DUMMY_SEL_1_b3_dummy_color_sel_mask                             (0x03000000)
#define  EPI_EPI_DUMMY_SEL_1_b4_dummy_color_sel_mask                             (0x00C00000)
#define  EPI_EPI_DUMMY_SEL_1_b5_dummy_color_sel_mask                             (0x00300000)
#define  EPI_EPI_DUMMY_SEL_1_b6_dummy_color_sel_mask                             (0x000C0000)
#define  EPI_EPI_DUMMY_SEL_1_b7_dummy_color_sel_mask                             (0x00030000)
#define  EPI_EPI_DUMMY_SEL_1_b8_dummy_color_sel_mask                             (0x0000C000)
#define  EPI_EPI_DUMMY_SEL_1_b9_dummy_color_sel_mask                             (0x00003000)
#define  EPI_EPI_DUMMY_SEL_1_b10_dummy_color_sel_mask                            (0x00000C00)
#define  EPI_EPI_DUMMY_SEL_1_b11_dummy_color_sel_mask                            (0x00000300)
#define  EPI_EPI_DUMMY_SEL_1_b12_dummy_color_sel_mask                            (0x000000C0)
#define  EPI_EPI_DUMMY_SEL_1_b13_dummy_color_sel_mask                            (0x00000030)
#define  EPI_EPI_DUMMY_SEL_1_b14_dummy_color_sel_mask                            (0x0000000C)
#define  EPI_EPI_DUMMY_SEL_1_b15_dummy_color_sel_mask                            (0x00000003)
#define  EPI_EPI_DUMMY_SEL_1_b0_dummy_color_sel(data)                            (0xC0000000&((data)<<30))
#define  EPI_EPI_DUMMY_SEL_1_b1_dummy_color_sel(data)                            (0x30000000&((data)<<28))
#define  EPI_EPI_DUMMY_SEL_1_b2_dummy_color_sel(data)                            (0x0C000000&((data)<<26))
#define  EPI_EPI_DUMMY_SEL_1_b3_dummy_color_sel(data)                            (0x03000000&((data)<<24))
#define  EPI_EPI_DUMMY_SEL_1_b4_dummy_color_sel(data)                            (0x00C00000&((data)<<22))
#define  EPI_EPI_DUMMY_SEL_1_b5_dummy_color_sel(data)                            (0x00300000&((data)<<20))
#define  EPI_EPI_DUMMY_SEL_1_b6_dummy_color_sel(data)                            (0x000C0000&((data)<<18))
#define  EPI_EPI_DUMMY_SEL_1_b7_dummy_color_sel(data)                            (0x00030000&((data)<<16))
#define  EPI_EPI_DUMMY_SEL_1_b8_dummy_color_sel(data)                            (0x0000C000&((data)<<14))
#define  EPI_EPI_DUMMY_SEL_1_b9_dummy_color_sel(data)                            (0x00003000&((data)<<12))
#define  EPI_EPI_DUMMY_SEL_1_b10_dummy_color_sel(data)                           (0x00000C00&((data)<<10))
#define  EPI_EPI_DUMMY_SEL_1_b11_dummy_color_sel(data)                           (0x00000300&((data)<<8))
#define  EPI_EPI_DUMMY_SEL_1_b12_dummy_color_sel(data)                           (0x000000C0&((data)<<6))
#define  EPI_EPI_DUMMY_SEL_1_b13_dummy_color_sel(data)                           (0x00000030&((data)<<4))
#define  EPI_EPI_DUMMY_SEL_1_b14_dummy_color_sel(data)                           (0x0000000C&((data)<<2))
#define  EPI_EPI_DUMMY_SEL_1_b15_dummy_color_sel(data)                           (0x00000003&(data))
#define  EPI_EPI_DUMMY_SEL_1_get_b0_dummy_color_sel(data)                        ((0xC0000000&(data))>>30)
#define  EPI_EPI_DUMMY_SEL_1_get_b1_dummy_color_sel(data)                        ((0x30000000&(data))>>28)
#define  EPI_EPI_DUMMY_SEL_1_get_b2_dummy_color_sel(data)                        ((0x0C000000&(data))>>26)
#define  EPI_EPI_DUMMY_SEL_1_get_b3_dummy_color_sel(data)                        ((0x03000000&(data))>>24)
#define  EPI_EPI_DUMMY_SEL_1_get_b4_dummy_color_sel(data)                        ((0x00C00000&(data))>>22)
#define  EPI_EPI_DUMMY_SEL_1_get_b5_dummy_color_sel(data)                        ((0x00300000&(data))>>20)
#define  EPI_EPI_DUMMY_SEL_1_get_b6_dummy_color_sel(data)                        ((0x000C0000&(data))>>18)
#define  EPI_EPI_DUMMY_SEL_1_get_b7_dummy_color_sel(data)                        ((0x00030000&(data))>>16)
#define  EPI_EPI_DUMMY_SEL_1_get_b8_dummy_color_sel(data)                        ((0x0000C000&(data))>>14)
#define  EPI_EPI_DUMMY_SEL_1_get_b9_dummy_color_sel(data)                        ((0x00003000&(data))>>12)
#define  EPI_EPI_DUMMY_SEL_1_get_b10_dummy_color_sel(data)                       ((0x00000C00&(data))>>10)
#define  EPI_EPI_DUMMY_SEL_1_get_b11_dummy_color_sel(data)                       ((0x00000300&(data))>>8)
#define  EPI_EPI_DUMMY_SEL_1_get_b12_dummy_color_sel(data)                       ((0x000000C0&(data))>>6)
#define  EPI_EPI_DUMMY_SEL_1_get_b13_dummy_color_sel(data)                       ((0x00000030&(data))>>4)
#define  EPI_EPI_DUMMY_SEL_1_get_b14_dummy_color_sel(data)                       ((0x0000000C&(data))>>2)
#define  EPI_EPI_DUMMY_SEL_1_get_b15_dummy_color_sel(data)                       (0x00000003&(data))

#define  EPI_EPI_DUMMY_COLOR_0                                                   0x18026080
#define  EPI_EPI_DUMMY_COLOR_0_reg_addr                                          "0xB8026080"
#define  EPI_EPI_DUMMY_COLOR_0_reg                                               0xB8026080
#define  EPI_EPI_DUMMY_COLOR_0_inst_addr                                         "0x0010"
#define  set_EPI_EPI_DUMMY_COLOR_0_reg(data)                                     (*((volatile unsigned int*)EPI_EPI_DUMMY_COLOR_0_reg)=data)
#define  get_EPI_EPI_DUMMY_COLOR_0_reg                                           (*((volatile unsigned int*)EPI_EPI_DUMMY_COLOR_0_reg))
#define  EPI_EPI_DUMMY_COLOR_0_dummy_color_0_shift                               (0)
#define  EPI_EPI_DUMMY_COLOR_0_dummy_color_0_mask                                (0x3FFFFFFF)
#define  EPI_EPI_DUMMY_COLOR_0_dummy_color_0(data)                               (0x3FFFFFFF&(data))
#define  EPI_EPI_DUMMY_COLOR_0_get_dummy_color_0(data)                           (0x3FFFFFFF&(data))

#define  EPI_EPI_DUMMY_COLOR_1                                                   0x18026084
#define  EPI_EPI_DUMMY_COLOR_1_reg_addr                                          "0xB8026084"
#define  EPI_EPI_DUMMY_COLOR_1_reg                                               0xB8026084
#define  EPI_EPI_DUMMY_COLOR_1_inst_addr                                         "0x0011"
#define  set_EPI_EPI_DUMMY_COLOR_1_reg(data)                                     (*((volatile unsigned int*)EPI_EPI_DUMMY_COLOR_1_reg)=data)
#define  get_EPI_EPI_DUMMY_COLOR_1_reg                                           (*((volatile unsigned int*)EPI_EPI_DUMMY_COLOR_1_reg))
#define  EPI_EPI_DUMMY_COLOR_1_dummy_color_1_shift                               (0)
#define  EPI_EPI_DUMMY_COLOR_1_dummy_color_1_mask                                (0x3FFFFFFF)
#define  EPI_EPI_DUMMY_COLOR_1_dummy_color_1(data)                               (0x3FFFFFFF&(data))
#define  EPI_EPI_DUMMY_COLOR_1_get_dummy_color_1(data)                           (0x3FFFFFFF&(data))

#define  EPI_EPI_DUMMY_COLOR_2                                                   0x18026088
#define  EPI_EPI_DUMMY_COLOR_2_reg_addr                                          "0xB8026088"
#define  EPI_EPI_DUMMY_COLOR_2_reg                                               0xB8026088
#define  EPI_EPI_DUMMY_COLOR_2_inst_addr                                         "0x0012"
#define  set_EPI_EPI_DUMMY_COLOR_2_reg(data)                                     (*((volatile unsigned int*)EPI_EPI_DUMMY_COLOR_2_reg)=data)
#define  get_EPI_EPI_DUMMY_COLOR_2_reg                                           (*((volatile unsigned int*)EPI_EPI_DUMMY_COLOR_2_reg))
#define  EPI_EPI_DUMMY_COLOR_2_dummy_color_2_shift                               (0)
#define  EPI_EPI_DUMMY_COLOR_2_dummy_color_2_mask                                (0x3FFFFFFF)
#define  EPI_EPI_DUMMY_COLOR_2_dummy_color_2(data)                               (0x3FFFFFFF&(data))
#define  EPI_EPI_DUMMY_COLOR_2_get_dummy_color_2(data)                           (0x3FFFFFFF&(data))

#define  EPI_EPI_DUMMY_COLOR_3                                                   0x1802608C
#define  EPI_EPI_DUMMY_COLOR_3_reg_addr                                          "0xB802608C"
#define  EPI_EPI_DUMMY_COLOR_3_reg                                               0xB802608C
#define  EPI_EPI_DUMMY_COLOR_3_inst_addr                                         "0x0013"
#define  set_EPI_EPI_DUMMY_COLOR_3_reg(data)                                     (*((volatile unsigned int*)EPI_EPI_DUMMY_COLOR_3_reg)=data)
#define  get_EPI_EPI_DUMMY_COLOR_3_reg                                           (*((volatile unsigned int*)EPI_EPI_DUMMY_COLOR_3_reg))
#define  EPI_EPI_DUMMY_COLOR_3_dummy_color_3_shift                               (0)
#define  EPI_EPI_DUMMY_COLOR_3_dummy_color_3_mask                                (0x3FFFFFFF)
#define  EPI_EPI_DUMMY_COLOR_3_dummy_color_3(data)                               (0x3FFFFFFF&(data))
#define  EPI_EPI_DUMMY_COLOR_3_get_dummy_color_3(data)                           (0x3FFFFFFF&(data))

#define  EPI_EPI_CRC_CTRL_0                                                      0x18026090
#define  EPI_EPI_CRC_CTRL_0_reg_addr                                             "0xB8026090"
#define  EPI_EPI_CRC_CTRL_0_reg                                                  0xB8026090
#define  EPI_EPI_CRC_CTRL_0_inst_addr                                            "0x0014"
#define  set_EPI_EPI_CRC_CTRL_0_reg(data)                                        (*((volatile unsigned int*)EPI_EPI_CRC_CTRL_0_reg)=data)
#define  get_EPI_EPI_CRC_CTRL_0_reg                                              (*((volatile unsigned int*)EPI_EPI_CRC_CTRL_0_reg))
#define  EPI_EPI_CRC_CTRL_0_crc_mismatch_count_shift                             (16)
#define  EPI_EPI_CRC_CTRL_0_dummy_15_9_shift                                     (9)
#define  EPI_EPI_CRC_CTRL_0_crc_port_sel_shift                                   (4)
#define  EPI_EPI_CRC_CTRL_0_dummy_3_shift                                        (3)
#define  EPI_EPI_CRC_CTRL_0_crc_mismatch_clear_shift                             (2)
#define  EPI_EPI_CRC_CTRL_0_crc_conti_shift                                      (1)
#define  EPI_EPI_CRC_CTRL_0_crc_start_shift                                      (0)
#define  EPI_EPI_CRC_CTRL_0_crc_mismatch_count_mask                              (0xFFFF0000)
#define  EPI_EPI_CRC_CTRL_0_dummy_15_9_mask                                      (0x0000FE00)
#define  EPI_EPI_CRC_CTRL_0_crc_port_sel_mask                                    (0x000001F0)
#define  EPI_EPI_CRC_CTRL_0_dummy_3_mask                                         (0x00000008)
#define  EPI_EPI_CRC_CTRL_0_crc_mismatch_clear_mask                              (0x00000004)
#define  EPI_EPI_CRC_CTRL_0_crc_conti_mask                                       (0x00000002)
#define  EPI_EPI_CRC_CTRL_0_crc_start_mask                                       (0x00000001)
#define  EPI_EPI_CRC_CTRL_0_crc_mismatch_count(data)                             (0xFFFF0000&((data)<<16))
#define  EPI_EPI_CRC_CTRL_0_dummy_15_9(data)                                     (0x0000FE00&((data)<<9))
#define  EPI_EPI_CRC_CTRL_0_crc_port_sel(data)                                   (0x000001F0&((data)<<4))
#define  EPI_EPI_CRC_CTRL_0_dummy_3(data)                                        (0x00000008&((data)<<3))
#define  EPI_EPI_CRC_CTRL_0_crc_mismatch_clear(data)                             (0x00000004&((data)<<2))
#define  EPI_EPI_CRC_CTRL_0_crc_conti(data)                                      (0x00000002&((data)<<1))
#define  EPI_EPI_CRC_CTRL_0_crc_start(data)                                      (0x00000001&(data))
#define  EPI_EPI_CRC_CTRL_0_get_crc_mismatch_count(data)                         ((0xFFFF0000&(data))>>16)
#define  EPI_EPI_CRC_CTRL_0_get_dummy_15_9(data)                                 ((0x0000FE00&(data))>>9)
#define  EPI_EPI_CRC_CTRL_0_get_crc_port_sel(data)                               ((0x000001F0&(data))>>4)
#define  EPI_EPI_CRC_CTRL_0_get_dummy_3(data)                                    ((0x00000008&(data))>>3)
#define  EPI_EPI_CRC_CTRL_0_get_crc_mismatch_clear(data)                         ((0x00000004&(data))>>2)
#define  EPI_EPI_CRC_CTRL_0_get_crc_conti(data)                                  ((0x00000002&(data))>>1)
#define  EPI_EPI_CRC_CTRL_0_get_crc_start(data)                                  (0x00000001&(data))

#define  EPI_EPI_CRC_CTRL_1                                                      0x18026094
#define  EPI_EPI_CRC_CTRL_1_reg_addr                                             "0xB8026094"
#define  EPI_EPI_CRC_CTRL_1_reg                                                  0xB8026094
#define  EPI_EPI_CRC_CTRL_1_inst_addr                                            "0x0015"
#define  set_EPI_EPI_CRC_CTRL_1_reg(data)                                        (*((volatile unsigned int*)EPI_EPI_CRC_CTRL_1_reg)=data)
#define  get_EPI_EPI_CRC_CTRL_1_reg                                              (*((volatile unsigned int*)EPI_EPI_CRC_CTRL_1_reg))
#define  EPI_EPI_CRC_CTRL_1_crc_result_shift                                     (0)
#define  EPI_EPI_CRC_CTRL_1_crc_result_mask                                      (0xFFFFFFFF)
#define  EPI_EPI_CRC_CTRL_1_crc_result(data)                                     (0xFFFFFFFF&(data))
#define  EPI_EPI_CRC_CTRL_1_get_crc_result(data)                                 (0xFFFFFFFF&(data))

#define  EPI_EPI_CRC_CTRL_2                                                      0x18026098
#define  EPI_EPI_CRC_CTRL_2_reg_addr                                             "0xB8026098"
#define  EPI_EPI_CRC_CTRL_2_reg                                                  0xB8026098
#define  EPI_EPI_CRC_CTRL_2_inst_addr                                            "0x0016"
#define  set_EPI_EPI_CRC_CTRL_2_reg(data)                                        (*((volatile unsigned int*)EPI_EPI_CRC_CTRL_2_reg)=data)
#define  get_EPI_EPI_CRC_CTRL_2_reg                                              (*((volatile unsigned int*)EPI_EPI_CRC_CTRL_2_reg))
#define  EPI_EPI_CRC_CTRL_2_crc_golden_shift                                     (0)
#define  EPI_EPI_CRC_CTRL_2_crc_golden_mask                                      (0xFFFFFFFF)
#define  EPI_EPI_CRC_CTRL_2_crc_golden(data)                                     (0xFFFFFFFF&(data))
#define  EPI_EPI_CRC_CTRL_2_get_crc_golden(data)                                 (0xFFFFFFFF&(data))

#define  EPI_EPI_DATA_SRC                                                        0x1802609C
#define  EPI_EPI_DATA_SRC_reg_addr                                               "0xB802609C"
#define  EPI_EPI_DATA_SRC_reg                                                    0xB802609C
#define  EPI_EPI_DATA_SRC_inst_addr                                              "0x0017"
#define  set_EPI_EPI_DATA_SRC_reg(data)                                          (*((volatile unsigned int*)EPI_EPI_DATA_SRC_reg)=data)
#define  get_EPI_EPI_DATA_SRC_reg                                                (*((volatile unsigned int*)EPI_EPI_DATA_SRC_reg))
#define  EPI_EPI_DATA_SRC_epi_src_sel_shift                                      (30)
#define  EPI_EPI_DATA_SRC_epi_src_data_shift                                     (0)
#define  EPI_EPI_DATA_SRC_epi_src_sel_mask                                       (0x40000000)
#define  EPI_EPI_DATA_SRC_epi_src_data_mask                                      (0x3FFFFFFF)
#define  EPI_EPI_DATA_SRC_epi_src_sel(data)                                      (0x40000000&((data)<<30))
#define  EPI_EPI_DATA_SRC_epi_src_data(data)                                     (0x3FFFFFFF&(data))
#define  EPI_EPI_DATA_SRC_get_epi_src_sel(data)                                  ((0x40000000&(data))>>30)
#define  EPI_EPI_DATA_SRC_get_epi_src_data(data)                                 (0x3FFFFFFF&(data))

#define  EPI_EPI_PACKET_CTR1_INV                                                 0x180260A4
#define  EPI_EPI_PACKET_CTR1_INV_reg_addr                                        "0xB80260A4"
#define  EPI_EPI_PACKET_CTR1_INV_reg                                             0xB80260A4
#define  EPI_EPI_PACKET_CTR1_INV_inst_addr                                       "0x0018"
#define  set_EPI_EPI_PACKET_CTR1_INV_reg(data)                                   (*((volatile unsigned int*)EPI_EPI_PACKET_CTR1_INV_reg)=data)
#define  get_EPI_EPI_PACKET_CTR1_INV_reg                                         (*((volatile unsigned int*)EPI_EPI_PACKET_CTR1_INV_reg))
#define  EPI_EPI_PACKET_CTR1_INV_inv_table_line_cycle_shift                      (4)
#define  EPI_EPI_PACKET_CTR1_INV_inv_table_line_cycle_mask                       (0x000001F0)
#define  EPI_EPI_PACKET_CTR1_INV_inv_table_line_cycle(data)                      (0x000001F0&((data)<<4))
#define  EPI_EPI_PACKET_CTR1_INV_get_inv_table_line_cycle(data)                  ((0x000001F0&(data))>>4)

#define  EPI_EPI_PACKET_CTR1_INV_TABLE_1                                         0x180260A8
#define  EPI_EPI_PACKET_CTR1_INV_TABLE_1_reg_addr                                "0xB80260A8"
#define  EPI_EPI_PACKET_CTR1_INV_TABLE_1_reg                                     0xB80260A8
#define  EPI_EPI_PACKET_CTR1_INV_TABLE_1_inst_addr                               "0x0019"
#define  set_EPI_EPI_PACKET_CTR1_INV_TABLE_1_reg(data)                           (*((volatile unsigned int*)EPI_EPI_PACKET_CTR1_INV_TABLE_1_reg)=data)
#define  get_EPI_EPI_PACKET_CTR1_INV_TABLE_1_reg                                 (*((volatile unsigned int*)EPI_EPI_PACKET_CTR1_INV_TABLE_1_reg))
#define  EPI_EPI_PACKET_CTR1_INV_TABLE_1_inv_line_1_shift                        (28)
#define  EPI_EPI_PACKET_CTR1_INV_TABLE_1_inv_line_2_shift                        (24)
#define  EPI_EPI_PACKET_CTR1_INV_TABLE_1_inv_line_3_shift                        (20)
#define  EPI_EPI_PACKET_CTR1_INV_TABLE_1_inv_line_4_shift                        (16)
#define  EPI_EPI_PACKET_CTR1_INV_TABLE_1_inv_line_5_shift                        (12)
#define  EPI_EPI_PACKET_CTR1_INV_TABLE_1_inv_line_6_shift                        (8)
#define  EPI_EPI_PACKET_CTR1_INV_TABLE_1_inv_line_7_shift                        (4)
#define  EPI_EPI_PACKET_CTR1_INV_TABLE_1_inv_line_8_shift                        (0)
#define  EPI_EPI_PACKET_CTR1_INV_TABLE_1_inv_line_1_mask                         (0xF0000000)
#define  EPI_EPI_PACKET_CTR1_INV_TABLE_1_inv_line_2_mask                         (0x0F000000)
#define  EPI_EPI_PACKET_CTR1_INV_TABLE_1_inv_line_3_mask                         (0x00F00000)
#define  EPI_EPI_PACKET_CTR1_INV_TABLE_1_inv_line_4_mask                         (0x000F0000)
#define  EPI_EPI_PACKET_CTR1_INV_TABLE_1_inv_line_5_mask                         (0x0000F000)
#define  EPI_EPI_PACKET_CTR1_INV_TABLE_1_inv_line_6_mask                         (0x00000F00)
#define  EPI_EPI_PACKET_CTR1_INV_TABLE_1_inv_line_7_mask                         (0x000000F0)
#define  EPI_EPI_PACKET_CTR1_INV_TABLE_1_inv_line_8_mask                         (0x0000000F)
#define  EPI_EPI_PACKET_CTR1_INV_TABLE_1_inv_line_1(data)                        (0xF0000000&((data)<<28))
#define  EPI_EPI_PACKET_CTR1_INV_TABLE_1_inv_line_2(data)                        (0x0F000000&((data)<<24))
#define  EPI_EPI_PACKET_CTR1_INV_TABLE_1_inv_line_3(data)                        (0x00F00000&((data)<<20))
#define  EPI_EPI_PACKET_CTR1_INV_TABLE_1_inv_line_4(data)                        (0x000F0000&((data)<<16))
#define  EPI_EPI_PACKET_CTR1_INV_TABLE_1_inv_line_5(data)                        (0x0000F000&((data)<<12))
#define  EPI_EPI_PACKET_CTR1_INV_TABLE_1_inv_line_6(data)                        (0x00000F00&((data)<<8))
#define  EPI_EPI_PACKET_CTR1_INV_TABLE_1_inv_line_7(data)                        (0x000000F0&((data)<<4))
#define  EPI_EPI_PACKET_CTR1_INV_TABLE_1_inv_line_8(data)                        (0x0000000F&(data))
#define  EPI_EPI_PACKET_CTR1_INV_TABLE_1_get_inv_line_1(data)                    ((0xF0000000&(data))>>28)
#define  EPI_EPI_PACKET_CTR1_INV_TABLE_1_get_inv_line_2(data)                    ((0x0F000000&(data))>>24)
#define  EPI_EPI_PACKET_CTR1_INV_TABLE_1_get_inv_line_3(data)                    ((0x00F00000&(data))>>20)
#define  EPI_EPI_PACKET_CTR1_INV_TABLE_1_get_inv_line_4(data)                    ((0x000F0000&(data))>>16)
#define  EPI_EPI_PACKET_CTR1_INV_TABLE_1_get_inv_line_5(data)                    ((0x0000F000&(data))>>12)
#define  EPI_EPI_PACKET_CTR1_INV_TABLE_1_get_inv_line_6(data)                    ((0x00000F00&(data))>>8)
#define  EPI_EPI_PACKET_CTR1_INV_TABLE_1_get_inv_line_7(data)                    ((0x000000F0&(data))>>4)
#define  EPI_EPI_PACKET_CTR1_INV_TABLE_1_get_inv_line_8(data)                    (0x0000000F&(data))

#define  EPI_EPI_PACKET_CTR1_INV_TABLE_2                                         0x180260AC
#define  EPI_EPI_PACKET_CTR1_INV_TABLE_2_reg_addr                                "0xB80260AC"
#define  EPI_EPI_PACKET_CTR1_INV_TABLE_2_reg                                     0xB80260AC
#define  EPI_EPI_PACKET_CTR1_INV_TABLE_2_inst_addr                               "0x001A"
#define  set_EPI_EPI_PACKET_CTR1_INV_TABLE_2_reg(data)                           (*((volatile unsigned int*)EPI_EPI_PACKET_CTR1_INV_TABLE_2_reg)=data)
#define  get_EPI_EPI_PACKET_CTR1_INV_TABLE_2_reg                                 (*((volatile unsigned int*)EPI_EPI_PACKET_CTR1_INV_TABLE_2_reg))
#define  EPI_EPI_PACKET_CTR1_INV_TABLE_2_inv_line_9_shift                        (28)
#define  EPI_EPI_PACKET_CTR1_INV_TABLE_2_inv_line_10_shift                       (24)
#define  EPI_EPI_PACKET_CTR1_INV_TABLE_2_inv_line_11_shift                       (20)
#define  EPI_EPI_PACKET_CTR1_INV_TABLE_2_inv_line_12_shift                       (16)
#define  EPI_EPI_PACKET_CTR1_INV_TABLE_2_inv_line_13_shift                       (12)
#define  EPI_EPI_PACKET_CTR1_INV_TABLE_2_inv_line_14_shift                       (8)
#define  EPI_EPI_PACKET_CTR1_INV_TABLE_2_inv_line_15_shift                       (4)
#define  EPI_EPI_PACKET_CTR1_INV_TABLE_2_inv_line_16_shift                       (0)
#define  EPI_EPI_PACKET_CTR1_INV_TABLE_2_inv_line_9_mask                         (0xF0000000)
#define  EPI_EPI_PACKET_CTR1_INV_TABLE_2_inv_line_10_mask                        (0x0F000000)
#define  EPI_EPI_PACKET_CTR1_INV_TABLE_2_inv_line_11_mask                        (0x00F00000)
#define  EPI_EPI_PACKET_CTR1_INV_TABLE_2_inv_line_12_mask                        (0x000F0000)
#define  EPI_EPI_PACKET_CTR1_INV_TABLE_2_inv_line_13_mask                        (0x0000F000)
#define  EPI_EPI_PACKET_CTR1_INV_TABLE_2_inv_line_14_mask                        (0x00000F00)
#define  EPI_EPI_PACKET_CTR1_INV_TABLE_2_inv_line_15_mask                        (0x000000F0)
#define  EPI_EPI_PACKET_CTR1_INV_TABLE_2_inv_line_16_mask                        (0x0000000F)
#define  EPI_EPI_PACKET_CTR1_INV_TABLE_2_inv_line_9(data)                        (0xF0000000&((data)<<28))
#define  EPI_EPI_PACKET_CTR1_INV_TABLE_2_inv_line_10(data)                       (0x0F000000&((data)<<24))
#define  EPI_EPI_PACKET_CTR1_INV_TABLE_2_inv_line_11(data)                       (0x00F00000&((data)<<20))
#define  EPI_EPI_PACKET_CTR1_INV_TABLE_2_inv_line_12(data)                       (0x000F0000&((data)<<16))
#define  EPI_EPI_PACKET_CTR1_INV_TABLE_2_inv_line_13(data)                       (0x0000F000&((data)<<12))
#define  EPI_EPI_PACKET_CTR1_INV_TABLE_2_inv_line_14(data)                       (0x00000F00&((data)<<8))
#define  EPI_EPI_PACKET_CTR1_INV_TABLE_2_inv_line_15(data)                       (0x000000F0&((data)<<4))
#define  EPI_EPI_PACKET_CTR1_INV_TABLE_2_inv_line_16(data)                       (0x0000000F&(data))
#define  EPI_EPI_PACKET_CTR1_INV_TABLE_2_get_inv_line_9(data)                    ((0xF0000000&(data))>>28)
#define  EPI_EPI_PACKET_CTR1_INV_TABLE_2_get_inv_line_10(data)                   ((0x0F000000&(data))>>24)
#define  EPI_EPI_PACKET_CTR1_INV_TABLE_2_get_inv_line_11(data)                   ((0x00F00000&(data))>>20)
#define  EPI_EPI_PACKET_CTR1_INV_TABLE_2_get_inv_line_12(data)                   ((0x000F0000&(data))>>16)
#define  EPI_EPI_PACKET_CTR1_INV_TABLE_2_get_inv_line_13(data)                   ((0x0000F000&(data))>>12)
#define  EPI_EPI_PACKET_CTR1_INV_TABLE_2_get_inv_line_14(data)                   ((0x00000F00&(data))>>8)
#define  EPI_EPI_PACKET_CTR1_INV_TABLE_2_get_inv_line_15(data)                   ((0x000000F0&(data))>>4)
#define  EPI_EPI_PACKET_CTR1_INV_TABLE_2_get_inv_line_16(data)                   (0x0000000F&(data))

#define  EPI_EPI_LS_PORT_EN                                                      0x180261E4
#define  EPI_EPI_LS_PORT_EN_reg_addr                                             "0xB80261E4"
#define  EPI_EPI_LS_PORT_EN_reg                                                  0xB80261E4
#define  EPI_EPI_LS_PORT_EN_inst_addr                                            "0x001B"
#define  set_EPI_EPI_LS_PORT_EN_reg(data)                                        (*((volatile unsigned int*)EPI_EPI_LS_PORT_EN_reg)=data)
#define  get_EPI_EPI_LS_PORT_EN_reg                                              (*((volatile unsigned int*)EPI_EPI_LS_PORT_EN_reg))
#define  EPI_EPI_LS_PORT_EN_ls_port_en_shift                                     (0)
#define  EPI_EPI_LS_PORT_EN_ls_port_en_mask                                      (0x000000FF)
#define  EPI_EPI_LS_PORT_EN_ls_port_en(data)                                     (0x000000FF&(data))
#define  EPI_EPI_LS_PORT_EN_get_ls_port_en(data)                                 (0x000000FF&(data))

#define  EPI_EPI_DATA_PORT_EN                                                    0x180261EC
#define  EPI_EPI_DATA_PORT_EN_reg_addr                                           "0xB80261EC"
#define  EPI_EPI_DATA_PORT_EN_reg                                                0xB80261EC
#define  EPI_EPI_DATA_PORT_EN_inst_addr                                          "0x001C"
#define  set_EPI_EPI_DATA_PORT_EN_reg(data)                                      (*((volatile unsigned int*)EPI_EPI_DATA_PORT_EN_reg)=data)
#define  get_EPI_EPI_DATA_PORT_EN_reg                                            (*((volatile unsigned int*)EPI_EPI_DATA_PORT_EN_reg))
#define  EPI_EPI_DATA_PORT_EN_constant_update_mode_shift                         (31)
#define  EPI_EPI_DATA_PORT_EN_data_port_en_shift                                 (0)
#define  EPI_EPI_DATA_PORT_EN_constant_update_mode_mask                          (0x80000000)
#define  EPI_EPI_DATA_PORT_EN_data_port_en_mask                                  (0x000000FF)
#define  EPI_EPI_DATA_PORT_EN_constant_update_mode(data)                         (0x80000000&((data)<<31))
#define  EPI_EPI_DATA_PORT_EN_data_port_en(data)                                 (0x000000FF&(data))
#define  EPI_EPI_DATA_PORT_EN_get_constant_update_mode(data)                     ((0x80000000&(data))>>31)
#define  EPI_EPI_DATA_PORT_EN_get_data_port_en(data)                             (0x000000FF&(data))

#define  EPI_EPI_DEN_FALL_LOCA                                                   0x180263F8
#define  EPI_EPI_DEN_FALL_LOCA_reg_addr                                          "0xB80263F8"
#define  EPI_EPI_DEN_FALL_LOCA_reg                                               0xB80263F8
#define  EPI_EPI_DEN_FALL_LOCA_inst_addr                                         "0x001D"
#define  set_EPI_EPI_DEN_FALL_LOCA_reg(data)                                     (*((volatile unsigned int*)EPI_EPI_DEN_FALL_LOCA_reg)=data)
#define  get_EPI_EPI_DEN_FALL_LOCA_reg                                           (*((volatile unsigned int*)EPI_EPI_DEN_FALL_LOCA_reg))
#define  EPI_EPI_DEN_FALL_LOCA_sw_cal_shift                                      (31)
#define  EPI_EPI_DEN_FALL_LOCA_sw_cal_value_shift                                (0)
#define  EPI_EPI_DEN_FALL_LOCA_sw_cal_mask                                       (0x80000000)
#define  EPI_EPI_DEN_FALL_LOCA_sw_cal_value_mask                                 (0x00003FFF)
#define  EPI_EPI_DEN_FALL_LOCA_sw_cal(data)                                      (0x80000000&((data)<<31))
#define  EPI_EPI_DEN_FALL_LOCA_sw_cal_value(data)                                (0x00003FFF&(data))
#define  EPI_EPI_DEN_FALL_LOCA_get_sw_cal(data)                                  ((0x80000000&(data))>>31)
#define  EPI_EPI_DEN_FALL_LOCA_get_sw_cal_value(data)                            (0x00003FFF&(data))

#define  EPI_EPI_LOCK_DEBOUNCE_CTL                                               0x180263FC
#define  EPI_EPI_LOCK_DEBOUNCE_CTL_reg_addr                                      "0xB80263FC"
#define  EPI_EPI_LOCK_DEBOUNCE_CTL_reg                                           0xB80263FC
#define  EPI_EPI_LOCK_DEBOUNCE_CTL_inst_addr                                     "0x001E"
#define  set_EPI_EPI_LOCK_DEBOUNCE_CTL_reg(data)                                 (*((volatile unsigned int*)EPI_EPI_LOCK_DEBOUNCE_CTL_reg)=data)
#define  get_EPI_EPI_LOCK_DEBOUNCE_CTL_reg                                       (*((volatile unsigned int*)EPI_EPI_LOCK_DEBOUNCE_CTL_reg))
#define  EPI_EPI_LOCK_DEBOUNCE_CTL_debounce_hi_window_shift                      (16)
#define  EPI_EPI_LOCK_DEBOUNCE_CTL_debounce_low_window_shift                     (1)
#define  EPI_EPI_LOCK_DEBOUNCE_CTL_debounce_en_shift                             (0)
#define  EPI_EPI_LOCK_DEBOUNCE_CTL_debounce_hi_window_mask                       (0x0FFF0000)
#define  EPI_EPI_LOCK_DEBOUNCE_CTL_debounce_low_window_mask                      (0x00001FFE)
#define  EPI_EPI_LOCK_DEBOUNCE_CTL_debounce_en_mask                              (0x00000001)
#define  EPI_EPI_LOCK_DEBOUNCE_CTL_debounce_hi_window(data)                      (0x0FFF0000&((data)<<16))
#define  EPI_EPI_LOCK_DEBOUNCE_CTL_debounce_low_window(data)                     (0x00001FFE&((data)<<1))
#define  EPI_EPI_LOCK_DEBOUNCE_CTL_debounce_en(data)                             (0x00000001&(data))
#define  EPI_EPI_LOCK_DEBOUNCE_CTL_get_debounce_hi_window(data)                  ((0x0FFF0000&(data))>>16)
#define  EPI_EPI_LOCK_DEBOUNCE_CTL_get_debounce_low_window(data)                 ((0x00001FFE&(data))>>1)
#define  EPI_EPI_LOCK_DEBOUNCE_CTL_get_debounce_en(data)                         (0x00000001&(data))

#define  EPI_EPI_DBG_REG_FLAG                                                    0x180261F0
#define  EPI_EPI_DBG_REG_FLAG_reg_addr                                           "0xB80261F0"
#define  EPI_EPI_DBG_REG_FLAG_reg                                                0xB80261F0
#define  EPI_EPI_DBG_REG_FLAG_inst_addr                                          "0x001F"
#define  set_EPI_EPI_DBG_REG_FLAG_reg(data)                                      (*((volatile unsigned int*)EPI_EPI_DBG_REG_FLAG_reg)=data)
#define  get_EPI_EPI_DBG_REG_FLAG_reg                                            (*((volatile unsigned int*)EPI_EPI_DBG_REG_FLAG_reg))
#define  EPI_EPI_DBG_REG_FLAG_hs_distance_flag_shift                             (3)
#define  EPI_EPI_DBG_REG_FLAG_hs_den_length_flag_shift                           (2)
#define  EPI_EPI_DBG_REG_FLAG_den_length_flag_shift                              (1)
#define  EPI_EPI_DBG_REG_FLAG_den_num_flag_shift                                 (0)
#define  EPI_EPI_DBG_REG_FLAG_hs_distance_flag_mask                              (0x00000008)
#define  EPI_EPI_DBG_REG_FLAG_hs_den_length_flag_mask                            (0x00000004)
#define  EPI_EPI_DBG_REG_FLAG_den_length_flag_mask                               (0x00000002)
#define  EPI_EPI_DBG_REG_FLAG_den_num_flag_mask                                  (0x00000001)
#define  EPI_EPI_DBG_REG_FLAG_hs_distance_flag(data)                             (0x00000008&((data)<<3))
#define  EPI_EPI_DBG_REG_FLAG_hs_den_length_flag(data)                           (0x00000004&((data)<<2))
#define  EPI_EPI_DBG_REG_FLAG_den_length_flag(data)                              (0x00000002&((data)<<1))
#define  EPI_EPI_DBG_REG_FLAG_den_num_flag(data)                                 (0x00000001&(data))
#define  EPI_EPI_DBG_REG_FLAG_get_hs_distance_flag(data)                         ((0x00000008&(data))>>3)
#define  EPI_EPI_DBG_REG_FLAG_get_hs_den_length_flag(data)                       ((0x00000004&(data))>>2)
#define  EPI_EPI_DBG_REG_FLAG_get_den_length_flag(data)                          ((0x00000002&(data))>>1)
#define  EPI_EPI_DBG_REG_FLAG_get_den_num_flag(data)                             (0x00000001&(data))

#define  EPI_EPI_DBG_REG_CTL                                                     0x180261F4
#define  EPI_EPI_DBG_REG_CTL_reg_addr                                            "0xB80261F4"
#define  EPI_EPI_DBG_REG_CTL_reg                                                 0xB80261F4
#define  EPI_EPI_DBG_REG_CTL_inst_addr                                           "0x0020"
#define  set_EPI_EPI_DBG_REG_CTL_reg(data)                                       (*((volatile unsigned int*)EPI_EPI_DBG_REG_CTL_reg)=data)
#define  get_EPI_EPI_DBG_REG_CTL_reg                                             (*((volatile unsigned int*)EPI_EPI_DBG_REG_CTL_reg))
#define  EPI_EPI_DBG_REG_CTL_hs_distance_det_en_shift                            (3)
#define  EPI_EPI_DBG_REG_CTL_hs_den_length_det_en_shift                          (2)
#define  EPI_EPI_DBG_REG_CTL_den_length_det_en_shift                             (1)
#define  EPI_EPI_DBG_REG_CTL_den_num_det_en_shift                                (0)
#define  EPI_EPI_DBG_REG_CTL_hs_distance_det_en_mask                             (0x00000008)
#define  EPI_EPI_DBG_REG_CTL_hs_den_length_det_en_mask                           (0x00000004)
#define  EPI_EPI_DBG_REG_CTL_den_length_det_en_mask                              (0x00000002)
#define  EPI_EPI_DBG_REG_CTL_den_num_det_en_mask                                 (0x00000001)
#define  EPI_EPI_DBG_REG_CTL_hs_distance_det_en(data)                            (0x00000008&((data)<<3))
#define  EPI_EPI_DBG_REG_CTL_hs_den_length_det_en(data)                          (0x00000004&((data)<<2))
#define  EPI_EPI_DBG_REG_CTL_den_length_det_en(data)                             (0x00000002&((data)<<1))
#define  EPI_EPI_DBG_REG_CTL_den_num_det_en(data)                                (0x00000001&(data))
#define  EPI_EPI_DBG_REG_CTL_get_hs_distance_det_en(data)                        ((0x00000008&(data))>>3)
#define  EPI_EPI_DBG_REG_CTL_get_hs_den_length_det_en(data)                      ((0x00000004&(data))>>2)
#define  EPI_EPI_DBG_REG_CTL_get_den_length_det_en(data)                         ((0x00000002&(data))>>1)
#define  EPI_EPI_DBG_REG_CTL_get_den_num_det_en(data)                            (0x00000001&(data))

#define  EPI_EPI_SOE_CONTROL                                                     0x180261FC
#define  EPI_EPI_SOE_CONTROL_reg_addr                                            "0xB80261FC"
#define  EPI_EPI_SOE_CONTROL_reg                                                 0xB80261FC
#define  EPI_EPI_SOE_CONTROL_inst_addr                                           "0x0021"
#define  set_EPI_EPI_SOE_CONTROL_reg(data)                                       (*((volatile unsigned int*)EPI_EPI_SOE_CONTROL_reg)=data)
#define  get_EPI_EPI_SOE_CONTROL_reg                                             (*((volatile unsigned int*)EPI_EPI_SOE_CONTROL_reg))
#define  EPI_EPI_SOE_CONTROL_soe_table_line_cycle_shift                          (2)
#define  EPI_EPI_SOE_CONTROL_ctr12_ref_soe_shift                                 (0)
#define  EPI_EPI_SOE_CONTROL_soe_table_line_cycle_mask                           (0x0000000C)
#define  EPI_EPI_SOE_CONTROL_ctr12_ref_soe_mask                                  (0x00000003)
#define  EPI_EPI_SOE_CONTROL_soe_table_line_cycle(data)                          (0x0000000C&((data)<<2))
#define  EPI_EPI_SOE_CONTROL_ctr12_ref_soe(data)                                 (0x00000003&(data))
#define  EPI_EPI_SOE_CONTROL_get_soe_table_line_cycle(data)                      ((0x0000000C&(data))>>2)
#define  EPI_EPI_SOE_CONTROL_get_ctr12_ref_soe(data)                             (0x00000003&(data))

#define  EPI_EPI_SOE_LINE0_LANE0                                                 0x18026200
#define  EPI_EPI_SOE_LINE0_LANE0_reg_addr                                        "0xB8026200"
#define  EPI_EPI_SOE_LINE0_LANE0_reg                                             0xB8026200
#define  EPI_EPI_SOE_LINE0_LANE0_inst_addr                                       "0x0022"
#define  set_EPI_EPI_SOE_LINE0_LANE0_reg(data)                                   (*((volatile unsigned int*)EPI_EPI_SOE_LINE0_LANE0_reg)=data)
#define  get_EPI_EPI_SOE_LINE0_LANE0_reg                                         (*((volatile unsigned int*)EPI_EPI_SOE_LINE0_LANE0_reg))
#define  EPI_EPI_SOE_LINE0_LANE0_lane0_soe0_shift                                (0)
#define  EPI_EPI_SOE_LINE0_LANE0_lane0_soe0_mask                                 (0x0003FFFF)
#define  EPI_EPI_SOE_LINE0_LANE0_lane0_soe0(data)                                (0x0003FFFF&(data))
#define  EPI_EPI_SOE_LINE0_LANE0_get_lane0_soe0(data)                            (0x0003FFFF&(data))

#define  EPI_EPI_SOE_LINE1_LANE0                                                 0x18026204
#define  EPI_EPI_SOE_LINE1_LANE0_reg_addr                                        "0xB8026204"
#define  EPI_EPI_SOE_LINE1_LANE0_reg                                             0xB8026204
#define  EPI_EPI_SOE_LINE1_LANE0_inst_addr                                       "0x0023"
#define  set_EPI_EPI_SOE_LINE1_LANE0_reg(data)                                   (*((volatile unsigned int*)EPI_EPI_SOE_LINE1_LANE0_reg)=data)
#define  get_EPI_EPI_SOE_LINE1_LANE0_reg                                         (*((volatile unsigned int*)EPI_EPI_SOE_LINE1_LANE0_reg))
#define  EPI_EPI_SOE_LINE1_LANE0_lane0_soe1_shift                                (0)
#define  EPI_EPI_SOE_LINE1_LANE0_lane0_soe1_mask                                 (0x0003FFFF)
#define  EPI_EPI_SOE_LINE1_LANE0_lane0_soe1(data)                                (0x0003FFFF&(data))
#define  EPI_EPI_SOE_LINE1_LANE0_get_lane0_soe1(data)                            (0x0003FFFF&(data))

#define  EPI_EPI_SOE_LINE2_LANE0                                                 0x18026208
#define  EPI_EPI_SOE_LINE2_LANE0_reg_addr                                        "0xB8026208"
#define  EPI_EPI_SOE_LINE2_LANE0_reg                                             0xB8026208
#define  EPI_EPI_SOE_LINE2_LANE0_inst_addr                                       "0x0024"
#define  set_EPI_EPI_SOE_LINE2_LANE0_reg(data)                                   (*((volatile unsigned int*)EPI_EPI_SOE_LINE2_LANE0_reg)=data)
#define  get_EPI_EPI_SOE_LINE2_LANE0_reg                                         (*((volatile unsigned int*)EPI_EPI_SOE_LINE2_LANE0_reg))
#define  EPI_EPI_SOE_LINE2_LANE0_lane0_soe2_shift                                (0)
#define  EPI_EPI_SOE_LINE2_LANE0_lane0_soe2_mask                                 (0x0003FFFF)
#define  EPI_EPI_SOE_LINE2_LANE0_lane0_soe2(data)                                (0x0003FFFF&(data))
#define  EPI_EPI_SOE_LINE2_LANE0_get_lane0_soe2(data)                            (0x0003FFFF&(data))

#define  EPI_EPI_SOE_LINE3_LANE0                                                 0x1802620C
#define  EPI_EPI_SOE_LINE3_LANE0_reg_addr                                        "0xB802620C"
#define  EPI_EPI_SOE_LINE3_LANE0_reg                                             0xB802620C
#define  EPI_EPI_SOE_LINE3_LANE0_inst_addr                                       "0x0025"
#define  set_EPI_EPI_SOE_LINE3_LANE0_reg(data)                                   (*((volatile unsigned int*)EPI_EPI_SOE_LINE3_LANE0_reg)=data)
#define  get_EPI_EPI_SOE_LINE3_LANE0_reg                                         (*((volatile unsigned int*)EPI_EPI_SOE_LINE3_LANE0_reg))
#define  EPI_EPI_SOE_LINE3_LANE0_lane0_soe3_shift                                (0)
#define  EPI_EPI_SOE_LINE3_LANE0_lane0_soe3_mask                                 (0x0003FFFF)
#define  EPI_EPI_SOE_LINE3_LANE0_lane0_soe3(data)                                (0x0003FFFF&(data))
#define  EPI_EPI_SOE_LINE3_LANE0_get_lane0_soe3(data)                            (0x0003FFFF&(data))

#define  EPI_EPI_SOE_LINE0_LANE1                                                 0x18026210
#define  EPI_EPI_SOE_LINE0_LANE1_reg_addr                                        "0xB8026210"
#define  EPI_EPI_SOE_LINE0_LANE1_reg                                             0xB8026210
#define  EPI_EPI_SOE_LINE0_LANE1_inst_addr                                       "0x0026"
#define  set_EPI_EPI_SOE_LINE0_LANE1_reg(data)                                   (*((volatile unsigned int*)EPI_EPI_SOE_LINE0_LANE1_reg)=data)
#define  get_EPI_EPI_SOE_LINE0_LANE1_reg                                         (*((volatile unsigned int*)EPI_EPI_SOE_LINE0_LANE1_reg))
#define  EPI_EPI_SOE_LINE0_LANE1_lane1_soe0_shift                                (0)
#define  EPI_EPI_SOE_LINE0_LANE1_lane1_soe0_mask                                 (0x0003FFFF)
#define  EPI_EPI_SOE_LINE0_LANE1_lane1_soe0(data)                                (0x0003FFFF&(data))
#define  EPI_EPI_SOE_LINE0_LANE1_get_lane1_soe0(data)                            (0x0003FFFF&(data))

#define  EPI_EPI_SOE_LINE1_LANE1                                                 0x18026214
#define  EPI_EPI_SOE_LINE1_LANE1_reg_addr                                        "0xB8026214"
#define  EPI_EPI_SOE_LINE1_LANE1_reg                                             0xB8026214
#define  EPI_EPI_SOE_LINE1_LANE1_inst_addr                                       "0x0027"
#define  set_EPI_EPI_SOE_LINE1_LANE1_reg(data)                                   (*((volatile unsigned int*)EPI_EPI_SOE_LINE1_LANE1_reg)=data)
#define  get_EPI_EPI_SOE_LINE1_LANE1_reg                                         (*((volatile unsigned int*)EPI_EPI_SOE_LINE1_LANE1_reg))
#define  EPI_EPI_SOE_LINE1_LANE1_lane1_soe1_shift                                (0)
#define  EPI_EPI_SOE_LINE1_LANE1_lane1_soe1_mask                                 (0x0003FFFF)
#define  EPI_EPI_SOE_LINE1_LANE1_lane1_soe1(data)                                (0x0003FFFF&(data))
#define  EPI_EPI_SOE_LINE1_LANE1_get_lane1_soe1(data)                            (0x0003FFFF&(data))

#define  EPI_EPI_SOE_LINE2_LANE1                                                 0x18026218
#define  EPI_EPI_SOE_LINE2_LANE1_reg_addr                                        "0xB8026218"
#define  EPI_EPI_SOE_LINE2_LANE1_reg                                             0xB8026218
#define  EPI_EPI_SOE_LINE2_LANE1_inst_addr                                       "0x0028"
#define  set_EPI_EPI_SOE_LINE2_LANE1_reg(data)                                   (*((volatile unsigned int*)EPI_EPI_SOE_LINE2_LANE1_reg)=data)
#define  get_EPI_EPI_SOE_LINE2_LANE1_reg                                         (*((volatile unsigned int*)EPI_EPI_SOE_LINE2_LANE1_reg))
#define  EPI_EPI_SOE_LINE2_LANE1_lane1_soe2_shift                                (0)
#define  EPI_EPI_SOE_LINE2_LANE1_lane1_soe2_mask                                 (0x0003FFFF)
#define  EPI_EPI_SOE_LINE2_LANE1_lane1_soe2(data)                                (0x0003FFFF&(data))
#define  EPI_EPI_SOE_LINE2_LANE1_get_lane1_soe2(data)                            (0x0003FFFF&(data))

#define  EPI_EPI_SOE_LINE3_LANE1                                                 0x1802621C
#define  EPI_EPI_SOE_LINE3_LANE1_reg_addr                                        "0xB802621C"
#define  EPI_EPI_SOE_LINE3_LANE1_reg                                             0xB802621C
#define  EPI_EPI_SOE_LINE3_LANE1_inst_addr                                       "0x0029"
#define  set_EPI_EPI_SOE_LINE3_LANE1_reg(data)                                   (*((volatile unsigned int*)EPI_EPI_SOE_LINE3_LANE1_reg)=data)
#define  get_EPI_EPI_SOE_LINE3_LANE1_reg                                         (*((volatile unsigned int*)EPI_EPI_SOE_LINE3_LANE1_reg))
#define  EPI_EPI_SOE_LINE3_LANE1_lane1_soe3_shift                                (0)
#define  EPI_EPI_SOE_LINE3_LANE1_lane1_soe3_mask                                 (0x0003FFFF)
#define  EPI_EPI_SOE_LINE3_LANE1_lane1_soe3(data)                                (0x0003FFFF&(data))
#define  EPI_EPI_SOE_LINE3_LANE1_get_lane1_soe3(data)                            (0x0003FFFF&(data))

#define  EPI_EPI_SOE_LINE0_LANE2                                                 0x18026220
#define  EPI_EPI_SOE_LINE0_LANE2_reg_addr                                        "0xB8026220"
#define  EPI_EPI_SOE_LINE0_LANE2_reg                                             0xB8026220
#define  EPI_EPI_SOE_LINE0_LANE2_inst_addr                                       "0x002A"
#define  set_EPI_EPI_SOE_LINE0_LANE2_reg(data)                                   (*((volatile unsigned int*)EPI_EPI_SOE_LINE0_LANE2_reg)=data)
#define  get_EPI_EPI_SOE_LINE0_LANE2_reg                                         (*((volatile unsigned int*)EPI_EPI_SOE_LINE0_LANE2_reg))
#define  EPI_EPI_SOE_LINE0_LANE2_lane2_soe0_shift                                (0)
#define  EPI_EPI_SOE_LINE0_LANE2_lane2_soe0_mask                                 (0x0003FFFF)
#define  EPI_EPI_SOE_LINE0_LANE2_lane2_soe0(data)                                (0x0003FFFF&(data))
#define  EPI_EPI_SOE_LINE0_LANE2_get_lane2_soe0(data)                            (0x0003FFFF&(data))

#define  EPI_EPI_SOE_LINE1_LANE2                                                 0x18026224
#define  EPI_EPI_SOE_LINE1_LANE2_reg_addr                                        "0xB8026224"
#define  EPI_EPI_SOE_LINE1_LANE2_reg                                             0xB8026224
#define  EPI_EPI_SOE_LINE1_LANE2_inst_addr                                       "0x002B"
#define  set_EPI_EPI_SOE_LINE1_LANE2_reg(data)                                   (*((volatile unsigned int*)EPI_EPI_SOE_LINE1_LANE2_reg)=data)
#define  get_EPI_EPI_SOE_LINE1_LANE2_reg                                         (*((volatile unsigned int*)EPI_EPI_SOE_LINE1_LANE2_reg))
#define  EPI_EPI_SOE_LINE1_LANE2_lane2_soe1_shift                                (0)
#define  EPI_EPI_SOE_LINE1_LANE2_lane2_soe1_mask                                 (0x0003FFFF)
#define  EPI_EPI_SOE_LINE1_LANE2_lane2_soe1(data)                                (0x0003FFFF&(data))
#define  EPI_EPI_SOE_LINE1_LANE2_get_lane2_soe1(data)                            (0x0003FFFF&(data))

#define  EPI_EPI_SOE_LINE2_LANE2                                                 0x18026228
#define  EPI_EPI_SOE_LINE2_LANE2_reg_addr                                        "0xB8026228"
#define  EPI_EPI_SOE_LINE2_LANE2_reg                                             0xB8026228
#define  EPI_EPI_SOE_LINE2_LANE2_inst_addr                                       "0x002C"
#define  set_EPI_EPI_SOE_LINE2_LANE2_reg(data)                                   (*((volatile unsigned int*)EPI_EPI_SOE_LINE2_LANE2_reg)=data)
#define  get_EPI_EPI_SOE_LINE2_LANE2_reg                                         (*((volatile unsigned int*)EPI_EPI_SOE_LINE2_LANE2_reg))
#define  EPI_EPI_SOE_LINE2_LANE2_lane2_soe2_shift                                (0)
#define  EPI_EPI_SOE_LINE2_LANE2_lane2_soe2_mask                                 (0x0003FFFF)
#define  EPI_EPI_SOE_LINE2_LANE2_lane2_soe2(data)                                (0x0003FFFF&(data))
#define  EPI_EPI_SOE_LINE2_LANE2_get_lane2_soe2(data)                            (0x0003FFFF&(data))

#define  EPI_EPI_SOE_LINE3_LANE2                                                 0x1802622C
#define  EPI_EPI_SOE_LINE3_LANE2_reg_addr                                        "0xB802622C"
#define  EPI_EPI_SOE_LINE3_LANE2_reg                                             0xB802622C
#define  EPI_EPI_SOE_LINE3_LANE2_inst_addr                                       "0x002D"
#define  set_EPI_EPI_SOE_LINE3_LANE2_reg(data)                                   (*((volatile unsigned int*)EPI_EPI_SOE_LINE3_LANE2_reg)=data)
#define  get_EPI_EPI_SOE_LINE3_LANE2_reg                                         (*((volatile unsigned int*)EPI_EPI_SOE_LINE3_LANE2_reg))
#define  EPI_EPI_SOE_LINE3_LANE2_lane2_soe3_shift                                (0)
#define  EPI_EPI_SOE_LINE3_LANE2_lane2_soe3_mask                                 (0x0003FFFF)
#define  EPI_EPI_SOE_LINE3_LANE2_lane2_soe3(data)                                (0x0003FFFF&(data))
#define  EPI_EPI_SOE_LINE3_LANE2_get_lane2_soe3(data)                            (0x0003FFFF&(data))

#define  EPI_EPI_SOE_LINE0_LANE3                                                 0x18026230
#define  EPI_EPI_SOE_LINE0_LANE3_reg_addr                                        "0xB8026230"
#define  EPI_EPI_SOE_LINE0_LANE3_reg                                             0xB8026230
#define  EPI_EPI_SOE_LINE0_LANE3_inst_addr                                       "0x002E"
#define  set_EPI_EPI_SOE_LINE0_LANE3_reg(data)                                   (*((volatile unsigned int*)EPI_EPI_SOE_LINE0_LANE3_reg)=data)
#define  get_EPI_EPI_SOE_LINE0_LANE3_reg                                         (*((volatile unsigned int*)EPI_EPI_SOE_LINE0_LANE3_reg))
#define  EPI_EPI_SOE_LINE0_LANE3_lane3_soe0_shift                                (0)
#define  EPI_EPI_SOE_LINE0_LANE3_lane3_soe0_mask                                 (0x0003FFFF)
#define  EPI_EPI_SOE_LINE0_LANE3_lane3_soe0(data)                                (0x0003FFFF&(data))
#define  EPI_EPI_SOE_LINE0_LANE3_get_lane3_soe0(data)                            (0x0003FFFF&(data))

#define  EPI_EPI_SOE_LINE1_LANE3                                                 0x18026234
#define  EPI_EPI_SOE_LINE1_LANE3_reg_addr                                        "0xB8026234"
#define  EPI_EPI_SOE_LINE1_LANE3_reg                                             0xB8026234
#define  EPI_EPI_SOE_LINE1_LANE3_inst_addr                                       "0x002F"
#define  set_EPI_EPI_SOE_LINE1_LANE3_reg(data)                                   (*((volatile unsigned int*)EPI_EPI_SOE_LINE1_LANE3_reg)=data)
#define  get_EPI_EPI_SOE_LINE1_LANE3_reg                                         (*((volatile unsigned int*)EPI_EPI_SOE_LINE1_LANE3_reg))
#define  EPI_EPI_SOE_LINE1_LANE3_lane3_soe1_shift                                (0)
#define  EPI_EPI_SOE_LINE1_LANE3_lane3_soe1_mask                                 (0x0003FFFF)
#define  EPI_EPI_SOE_LINE1_LANE3_lane3_soe1(data)                                (0x0003FFFF&(data))
#define  EPI_EPI_SOE_LINE1_LANE3_get_lane3_soe1(data)                            (0x0003FFFF&(data))

#define  EPI_EPI_SOE_LINE2_LANE3                                                 0x18026238
#define  EPI_EPI_SOE_LINE2_LANE3_reg_addr                                        "0xB8026238"
#define  EPI_EPI_SOE_LINE2_LANE3_reg                                             0xB8026238
#define  EPI_EPI_SOE_LINE2_LANE3_inst_addr                                       "0x0030"
#define  set_EPI_EPI_SOE_LINE2_LANE3_reg(data)                                   (*((volatile unsigned int*)EPI_EPI_SOE_LINE2_LANE3_reg)=data)
#define  get_EPI_EPI_SOE_LINE2_LANE3_reg                                         (*((volatile unsigned int*)EPI_EPI_SOE_LINE2_LANE3_reg))
#define  EPI_EPI_SOE_LINE2_LANE3_lane3_soe2_shift                                (0)
#define  EPI_EPI_SOE_LINE2_LANE3_lane3_soe2_mask                                 (0x0003FFFF)
#define  EPI_EPI_SOE_LINE2_LANE3_lane3_soe2(data)                                (0x0003FFFF&(data))
#define  EPI_EPI_SOE_LINE2_LANE3_get_lane3_soe2(data)                            (0x0003FFFF&(data))

#define  EPI_EPI_SOE_LINE3_LANE3                                                 0x1802623C
#define  EPI_EPI_SOE_LINE3_LANE3_reg_addr                                        "0xB802623C"
#define  EPI_EPI_SOE_LINE3_LANE3_reg                                             0xB802623C
#define  EPI_EPI_SOE_LINE3_LANE3_inst_addr                                       "0x0031"
#define  set_EPI_EPI_SOE_LINE3_LANE3_reg(data)                                   (*((volatile unsigned int*)EPI_EPI_SOE_LINE3_LANE3_reg)=data)
#define  get_EPI_EPI_SOE_LINE3_LANE3_reg                                         (*((volatile unsigned int*)EPI_EPI_SOE_LINE3_LANE3_reg))
#define  EPI_EPI_SOE_LINE3_LANE3_lane3_soe3_shift                                (0)
#define  EPI_EPI_SOE_LINE3_LANE3_lane3_soe3_mask                                 (0x0003FFFF)
#define  EPI_EPI_SOE_LINE3_LANE3_lane3_soe3(data)                                (0x0003FFFF&(data))
#define  EPI_EPI_SOE_LINE3_LANE3_get_lane3_soe3(data)                            (0x0003FFFF&(data))

#define  EPI_EPI_SOE_LINE0_LANE4                                                 0x18026240
#define  EPI_EPI_SOE_LINE0_LANE4_reg_addr                                        "0xB8026240"
#define  EPI_EPI_SOE_LINE0_LANE4_reg                                             0xB8026240
#define  EPI_EPI_SOE_LINE0_LANE4_inst_addr                                       "0x0032"
#define  set_EPI_EPI_SOE_LINE0_LANE4_reg(data)                                   (*((volatile unsigned int*)EPI_EPI_SOE_LINE0_LANE4_reg)=data)
#define  get_EPI_EPI_SOE_LINE0_LANE4_reg                                         (*((volatile unsigned int*)EPI_EPI_SOE_LINE0_LANE4_reg))
#define  EPI_EPI_SOE_LINE0_LANE4_lane4_soe0_shift                                (0)
#define  EPI_EPI_SOE_LINE0_LANE4_lane4_soe0_mask                                 (0x0003FFFF)
#define  EPI_EPI_SOE_LINE0_LANE4_lane4_soe0(data)                                (0x0003FFFF&(data))
#define  EPI_EPI_SOE_LINE0_LANE4_get_lane4_soe0(data)                            (0x0003FFFF&(data))

#define  EPI_EPI_SOE_LINE1_LANE4                                                 0x18026244
#define  EPI_EPI_SOE_LINE1_LANE4_reg_addr                                        "0xB8026244"
#define  EPI_EPI_SOE_LINE1_LANE4_reg                                             0xB8026244
#define  EPI_EPI_SOE_LINE1_LANE4_inst_addr                                       "0x0033"
#define  set_EPI_EPI_SOE_LINE1_LANE4_reg(data)                                   (*((volatile unsigned int*)EPI_EPI_SOE_LINE1_LANE4_reg)=data)
#define  get_EPI_EPI_SOE_LINE1_LANE4_reg                                         (*((volatile unsigned int*)EPI_EPI_SOE_LINE1_LANE4_reg))
#define  EPI_EPI_SOE_LINE1_LANE4_lane4_soe1_shift                                (0)
#define  EPI_EPI_SOE_LINE1_LANE4_lane4_soe1_mask                                 (0x0003FFFF)
#define  EPI_EPI_SOE_LINE1_LANE4_lane4_soe1(data)                                (0x0003FFFF&(data))
#define  EPI_EPI_SOE_LINE1_LANE4_get_lane4_soe1(data)                            (0x0003FFFF&(data))

#define  EPI_EPI_SOE_LINE2_LANE4                                                 0x18026248
#define  EPI_EPI_SOE_LINE2_LANE4_reg_addr                                        "0xB8026248"
#define  EPI_EPI_SOE_LINE2_LANE4_reg                                             0xB8026248
#define  EPI_EPI_SOE_LINE2_LANE4_inst_addr                                       "0x0034"
#define  set_EPI_EPI_SOE_LINE2_LANE4_reg(data)                                   (*((volatile unsigned int*)EPI_EPI_SOE_LINE2_LANE4_reg)=data)
#define  get_EPI_EPI_SOE_LINE2_LANE4_reg                                         (*((volatile unsigned int*)EPI_EPI_SOE_LINE2_LANE4_reg))
#define  EPI_EPI_SOE_LINE2_LANE4_lane4_soe2_shift                                (0)
#define  EPI_EPI_SOE_LINE2_LANE4_lane4_soe2_mask                                 (0x0003FFFF)
#define  EPI_EPI_SOE_LINE2_LANE4_lane4_soe2(data)                                (0x0003FFFF&(data))
#define  EPI_EPI_SOE_LINE2_LANE4_get_lane4_soe2(data)                            (0x0003FFFF&(data))

#define  EPI_EPI_SOE_LINE3_LANE4                                                 0x1802624C
#define  EPI_EPI_SOE_LINE3_LANE4_reg_addr                                        "0xB802624C"
#define  EPI_EPI_SOE_LINE3_LANE4_reg                                             0xB802624C
#define  EPI_EPI_SOE_LINE3_LANE4_inst_addr                                       "0x0035"
#define  set_EPI_EPI_SOE_LINE3_LANE4_reg(data)                                   (*((volatile unsigned int*)EPI_EPI_SOE_LINE3_LANE4_reg)=data)
#define  get_EPI_EPI_SOE_LINE3_LANE4_reg                                         (*((volatile unsigned int*)EPI_EPI_SOE_LINE3_LANE4_reg))
#define  EPI_EPI_SOE_LINE3_LANE4_lane4_soe3_shift                                (0)
#define  EPI_EPI_SOE_LINE3_LANE4_lane4_soe3_mask                                 (0x0003FFFF)
#define  EPI_EPI_SOE_LINE3_LANE4_lane4_soe3(data)                                (0x0003FFFF&(data))
#define  EPI_EPI_SOE_LINE3_LANE4_get_lane4_soe3(data)                            (0x0003FFFF&(data))

#define  EPI_EPI_SOE_LINE0_LANE5                                                 0x18026250
#define  EPI_EPI_SOE_LINE0_LANE5_reg_addr                                        "0xB8026250"
#define  EPI_EPI_SOE_LINE0_LANE5_reg                                             0xB8026250
#define  EPI_EPI_SOE_LINE0_LANE5_inst_addr                                       "0x0036"
#define  set_EPI_EPI_SOE_LINE0_LANE5_reg(data)                                   (*((volatile unsigned int*)EPI_EPI_SOE_LINE0_LANE5_reg)=data)
#define  get_EPI_EPI_SOE_LINE0_LANE5_reg                                         (*((volatile unsigned int*)EPI_EPI_SOE_LINE0_LANE5_reg))
#define  EPI_EPI_SOE_LINE0_LANE5_lane5_soe0_shift                                (0)
#define  EPI_EPI_SOE_LINE0_LANE5_lane5_soe0_mask                                 (0x0003FFFF)
#define  EPI_EPI_SOE_LINE0_LANE5_lane5_soe0(data)                                (0x0003FFFF&(data))
#define  EPI_EPI_SOE_LINE0_LANE5_get_lane5_soe0(data)                            (0x0003FFFF&(data))

#define  EPI_EPI_SOE_LINE1_LANE5                                                 0x18026254
#define  EPI_EPI_SOE_LINE1_LANE5_reg_addr                                        "0xB8026254"
#define  EPI_EPI_SOE_LINE1_LANE5_reg                                             0xB8026254
#define  EPI_EPI_SOE_LINE1_LANE5_inst_addr                                       "0x0037"
#define  set_EPI_EPI_SOE_LINE1_LANE5_reg(data)                                   (*((volatile unsigned int*)EPI_EPI_SOE_LINE1_LANE5_reg)=data)
#define  get_EPI_EPI_SOE_LINE1_LANE5_reg                                         (*((volatile unsigned int*)EPI_EPI_SOE_LINE1_LANE5_reg))
#define  EPI_EPI_SOE_LINE1_LANE5_lane5_soe1_shift                                (0)
#define  EPI_EPI_SOE_LINE1_LANE5_lane5_soe1_mask                                 (0x0003FFFF)
#define  EPI_EPI_SOE_LINE1_LANE5_lane5_soe1(data)                                (0x0003FFFF&(data))
#define  EPI_EPI_SOE_LINE1_LANE5_get_lane5_soe1(data)                            (0x0003FFFF&(data))

#define  EPI_EPI_SOE_LINE2_LANE5                                                 0x18026258
#define  EPI_EPI_SOE_LINE2_LANE5_reg_addr                                        "0xB8026258"
#define  EPI_EPI_SOE_LINE2_LANE5_reg                                             0xB8026258
#define  EPI_EPI_SOE_LINE2_LANE5_inst_addr                                       "0x0038"
#define  set_EPI_EPI_SOE_LINE2_LANE5_reg(data)                                   (*((volatile unsigned int*)EPI_EPI_SOE_LINE2_LANE5_reg)=data)
#define  get_EPI_EPI_SOE_LINE2_LANE5_reg                                         (*((volatile unsigned int*)EPI_EPI_SOE_LINE2_LANE5_reg))
#define  EPI_EPI_SOE_LINE2_LANE5_lane5_soe2_shift                                (0)
#define  EPI_EPI_SOE_LINE2_LANE5_lane5_soe2_mask                                 (0x0003FFFF)
#define  EPI_EPI_SOE_LINE2_LANE5_lane5_soe2(data)                                (0x0003FFFF&(data))
#define  EPI_EPI_SOE_LINE2_LANE5_get_lane5_soe2(data)                            (0x0003FFFF&(data))

#define  EPI_EPI_SOE_LINE3_LANE5                                                 0x1802625C
#define  EPI_EPI_SOE_LINE3_LANE5_reg_addr                                        "0xB802625C"
#define  EPI_EPI_SOE_LINE3_LANE5_reg                                             0xB802625C
#define  EPI_EPI_SOE_LINE3_LANE5_inst_addr                                       "0x0039"
#define  set_EPI_EPI_SOE_LINE3_LANE5_reg(data)                                   (*((volatile unsigned int*)EPI_EPI_SOE_LINE3_LANE5_reg)=data)
#define  get_EPI_EPI_SOE_LINE3_LANE5_reg                                         (*((volatile unsigned int*)EPI_EPI_SOE_LINE3_LANE5_reg))
#define  EPI_EPI_SOE_LINE3_LANE5_lane5_soe3_shift                                (0)
#define  EPI_EPI_SOE_LINE3_LANE5_lane5_soe3_mask                                 (0x0003FFFF)
#define  EPI_EPI_SOE_LINE3_LANE5_lane5_soe3(data)                                (0x0003FFFF&(data))
#define  EPI_EPI_SOE_LINE3_LANE5_get_lane5_soe3(data)                            (0x0003FFFF&(data))

#define  EPI_EPI_SOE_LINE0_LANE6                                                 0x18026260
#define  EPI_EPI_SOE_LINE0_LANE6_reg_addr                                        "0xB8026260"
#define  EPI_EPI_SOE_LINE0_LANE6_reg                                             0xB8026260
#define  EPI_EPI_SOE_LINE0_LANE6_inst_addr                                       "0x003A"
#define  set_EPI_EPI_SOE_LINE0_LANE6_reg(data)                                   (*((volatile unsigned int*)EPI_EPI_SOE_LINE0_LANE6_reg)=data)
#define  get_EPI_EPI_SOE_LINE0_LANE6_reg                                         (*((volatile unsigned int*)EPI_EPI_SOE_LINE0_LANE6_reg))
#define  EPI_EPI_SOE_LINE0_LANE6_lane6_soe0_shift                                (0)
#define  EPI_EPI_SOE_LINE0_LANE6_lane6_soe0_mask                                 (0x0003FFFF)
#define  EPI_EPI_SOE_LINE0_LANE6_lane6_soe0(data)                                (0x0003FFFF&(data))
#define  EPI_EPI_SOE_LINE0_LANE6_get_lane6_soe0(data)                            (0x0003FFFF&(data))

#define  EPI_EPI_SOE_LINE1_LANE6                                                 0x18026264
#define  EPI_EPI_SOE_LINE1_LANE6_reg_addr                                        "0xB8026264"
#define  EPI_EPI_SOE_LINE1_LANE6_reg                                             0xB8026264
#define  EPI_EPI_SOE_LINE1_LANE6_inst_addr                                       "0x003B"
#define  set_EPI_EPI_SOE_LINE1_LANE6_reg(data)                                   (*((volatile unsigned int*)EPI_EPI_SOE_LINE1_LANE6_reg)=data)
#define  get_EPI_EPI_SOE_LINE1_LANE6_reg                                         (*((volatile unsigned int*)EPI_EPI_SOE_LINE1_LANE6_reg))
#define  EPI_EPI_SOE_LINE1_LANE6_lane6_soe1_shift                                (0)
#define  EPI_EPI_SOE_LINE1_LANE6_lane6_soe1_mask                                 (0x0003FFFF)
#define  EPI_EPI_SOE_LINE1_LANE6_lane6_soe1(data)                                (0x0003FFFF&(data))
#define  EPI_EPI_SOE_LINE1_LANE6_get_lane6_soe1(data)                            (0x0003FFFF&(data))

#define  EPI_EPI_SOE_LINE2_LANE6                                                 0x18026268
#define  EPI_EPI_SOE_LINE2_LANE6_reg_addr                                        "0xB8026268"
#define  EPI_EPI_SOE_LINE2_LANE6_reg                                             0xB8026268
#define  EPI_EPI_SOE_LINE2_LANE6_inst_addr                                       "0x003C"
#define  set_EPI_EPI_SOE_LINE2_LANE6_reg(data)                                   (*((volatile unsigned int*)EPI_EPI_SOE_LINE2_LANE6_reg)=data)
#define  get_EPI_EPI_SOE_LINE2_LANE6_reg                                         (*((volatile unsigned int*)EPI_EPI_SOE_LINE2_LANE6_reg))
#define  EPI_EPI_SOE_LINE2_LANE6_lane6_soe2_shift                                (0)
#define  EPI_EPI_SOE_LINE2_LANE6_lane6_soe2_mask                                 (0x0003FFFF)
#define  EPI_EPI_SOE_LINE2_LANE6_lane6_soe2(data)                                (0x0003FFFF&(data))
#define  EPI_EPI_SOE_LINE2_LANE6_get_lane6_soe2(data)                            (0x0003FFFF&(data))

#define  EPI_EPI_SOE_LINE3_LANE6                                                 0x1802626C
#define  EPI_EPI_SOE_LINE3_LANE6_reg_addr                                        "0xB802626C"
#define  EPI_EPI_SOE_LINE3_LANE6_reg                                             0xB802626C
#define  EPI_EPI_SOE_LINE3_LANE6_inst_addr                                       "0x003D"
#define  set_EPI_EPI_SOE_LINE3_LANE6_reg(data)                                   (*((volatile unsigned int*)EPI_EPI_SOE_LINE3_LANE6_reg)=data)
#define  get_EPI_EPI_SOE_LINE3_LANE6_reg                                         (*((volatile unsigned int*)EPI_EPI_SOE_LINE3_LANE6_reg))
#define  EPI_EPI_SOE_LINE3_LANE6_lane6_soe3_shift                                (0)
#define  EPI_EPI_SOE_LINE3_LANE6_lane6_soe3_mask                                 (0x0003FFFF)
#define  EPI_EPI_SOE_LINE3_LANE6_lane6_soe3(data)                                (0x0003FFFF&(data))
#define  EPI_EPI_SOE_LINE3_LANE6_get_lane6_soe3(data)                            (0x0003FFFF&(data))

#define  EPI_EPI_SOE_LINE0_LANE7                                                 0x18026270
#define  EPI_EPI_SOE_LINE0_LANE7_reg_addr                                        "0xB8026270"
#define  EPI_EPI_SOE_LINE0_LANE7_reg                                             0xB8026270
#define  EPI_EPI_SOE_LINE0_LANE7_inst_addr                                       "0x003E"
#define  set_EPI_EPI_SOE_LINE0_LANE7_reg(data)                                   (*((volatile unsigned int*)EPI_EPI_SOE_LINE0_LANE7_reg)=data)
#define  get_EPI_EPI_SOE_LINE0_LANE7_reg                                         (*((volatile unsigned int*)EPI_EPI_SOE_LINE0_LANE7_reg))
#define  EPI_EPI_SOE_LINE0_LANE7_lane7_soe0_shift                                (0)
#define  EPI_EPI_SOE_LINE0_LANE7_lane7_soe0_mask                                 (0x0003FFFF)
#define  EPI_EPI_SOE_LINE0_LANE7_lane7_soe0(data)                                (0x0003FFFF&(data))
#define  EPI_EPI_SOE_LINE0_LANE7_get_lane7_soe0(data)                            (0x0003FFFF&(data))

#define  EPI_EPI_SOE_LINE1_LANE7                                                 0x18026274
#define  EPI_EPI_SOE_LINE1_LANE7_reg_addr                                        "0xB8026274"
#define  EPI_EPI_SOE_LINE1_LANE7_reg                                             0xB8026274
#define  EPI_EPI_SOE_LINE1_LANE7_inst_addr                                       "0x003F"
#define  set_EPI_EPI_SOE_LINE1_LANE7_reg(data)                                   (*((volatile unsigned int*)EPI_EPI_SOE_LINE1_LANE7_reg)=data)
#define  get_EPI_EPI_SOE_LINE1_LANE7_reg                                         (*((volatile unsigned int*)EPI_EPI_SOE_LINE1_LANE7_reg))
#define  EPI_EPI_SOE_LINE1_LANE7_lane7_soe1_shift                                (0)
#define  EPI_EPI_SOE_LINE1_LANE7_lane7_soe1_mask                                 (0x0003FFFF)
#define  EPI_EPI_SOE_LINE1_LANE7_lane7_soe1(data)                                (0x0003FFFF&(data))
#define  EPI_EPI_SOE_LINE1_LANE7_get_lane7_soe1(data)                            (0x0003FFFF&(data))

#define  EPI_EPI_SOE_LINE2_LANE7                                                 0x18026278
#define  EPI_EPI_SOE_LINE2_LANE7_reg_addr                                        "0xB8026278"
#define  EPI_EPI_SOE_LINE2_LANE7_reg                                             0xB8026278
#define  EPI_EPI_SOE_LINE2_LANE7_inst_addr                                       "0x0040"
#define  set_EPI_EPI_SOE_LINE2_LANE7_reg(data)                                   (*((volatile unsigned int*)EPI_EPI_SOE_LINE2_LANE7_reg)=data)
#define  get_EPI_EPI_SOE_LINE2_LANE7_reg                                         (*((volatile unsigned int*)EPI_EPI_SOE_LINE2_LANE7_reg))
#define  EPI_EPI_SOE_LINE2_LANE7_lane7_soe2_shift                                (0)
#define  EPI_EPI_SOE_LINE2_LANE7_lane7_soe2_mask                                 (0x0003FFFF)
#define  EPI_EPI_SOE_LINE2_LANE7_lane7_soe2(data)                                (0x0003FFFF&(data))
#define  EPI_EPI_SOE_LINE2_LANE7_get_lane7_soe2(data)                            (0x0003FFFF&(data))

#define  EPI_EPI_SOE_LINE3_LANE7                                                 0x1802627C
#define  EPI_EPI_SOE_LINE3_LANE7_reg_addr                                        "0xB802627C"
#define  EPI_EPI_SOE_LINE3_LANE7_reg                                             0xB802627C
#define  EPI_EPI_SOE_LINE3_LANE7_inst_addr                                       "0x0041"
#define  set_EPI_EPI_SOE_LINE3_LANE7_reg(data)                                   (*((volatile unsigned int*)EPI_EPI_SOE_LINE3_LANE7_reg)=data)
#define  get_EPI_EPI_SOE_LINE3_LANE7_reg                                         (*((volatile unsigned int*)EPI_EPI_SOE_LINE3_LANE7_reg))
#define  EPI_EPI_SOE_LINE3_LANE7_lane7_soe3_shift                                (0)
#define  EPI_EPI_SOE_LINE3_LANE7_lane7_soe3_mask                                 (0x0003FFFF)
#define  EPI_EPI_SOE_LINE3_LANE7_lane7_soe3(data)                                (0x0003FFFF&(data))
#define  EPI_EPI_SOE_LINE3_LANE7_get_lane7_soe3(data)                            (0x0003FFFF&(data))

#define  EPI_EPI_LANE_DST_MUX0                                                   0x18026380
#define  EPI_EPI_LANE_DST_MUX0_reg_addr                                          "0xB8026380"
#define  EPI_EPI_LANE_DST_MUX0_reg                                               0xB8026380
#define  EPI_EPI_LANE_DST_MUX0_inst_addr                                         "0x0042"
#define  set_EPI_EPI_LANE_DST_MUX0_reg(data)                                     (*((volatile unsigned int*)EPI_EPI_LANE_DST_MUX0_reg)=data)
#define  get_EPI_EPI_LANE_DST_MUX0_reg                                           (*((volatile unsigned int*)EPI_EPI_LANE_DST_MUX0_reg))
#define  EPI_EPI_LANE_DST_MUX0_lane_d_st_c4_mux_sel_shift                        (24)
#define  EPI_EPI_LANE_DST_MUX0_lane_d_st_c3_mux_sel_shift                        (18)
#define  EPI_EPI_LANE_DST_MUX0_lane_d_st_c2_mux_sel_shift                        (12)
#define  EPI_EPI_LANE_DST_MUX0_lane_d_st_c1_mux_sel_shift                        (6)
#define  EPI_EPI_LANE_DST_MUX0_lane_d_st_c0_mux_sel_shift                        (0)
#define  EPI_EPI_LANE_DST_MUX0_lane_d_st_c4_mux_sel_mask                         (0x3F000000)
#define  EPI_EPI_LANE_DST_MUX0_lane_d_st_c3_mux_sel_mask                         (0x00FC0000)
#define  EPI_EPI_LANE_DST_MUX0_lane_d_st_c2_mux_sel_mask                         (0x0003F000)
#define  EPI_EPI_LANE_DST_MUX0_lane_d_st_c1_mux_sel_mask                         (0x00000FC0)
#define  EPI_EPI_LANE_DST_MUX0_lane_d_st_c0_mux_sel_mask                         (0x0000003F)
#define  EPI_EPI_LANE_DST_MUX0_lane_d_st_c4_mux_sel(data)                        (0x3F000000&((data)<<24))
#define  EPI_EPI_LANE_DST_MUX0_lane_d_st_c3_mux_sel(data)                        (0x00FC0000&((data)<<18))
#define  EPI_EPI_LANE_DST_MUX0_lane_d_st_c2_mux_sel(data)                        (0x0003F000&((data)<<12))
#define  EPI_EPI_LANE_DST_MUX0_lane_d_st_c1_mux_sel(data)                        (0x00000FC0&((data)<<6))
#define  EPI_EPI_LANE_DST_MUX0_lane_d_st_c0_mux_sel(data)                        (0x0000003F&(data))
#define  EPI_EPI_LANE_DST_MUX0_get_lane_d_st_c4_mux_sel(data)                    ((0x3F000000&(data))>>24)
#define  EPI_EPI_LANE_DST_MUX0_get_lane_d_st_c3_mux_sel(data)                    ((0x00FC0000&(data))>>18)
#define  EPI_EPI_LANE_DST_MUX0_get_lane_d_st_c2_mux_sel(data)                    ((0x0003F000&(data))>>12)
#define  EPI_EPI_LANE_DST_MUX0_get_lane_d_st_c1_mux_sel(data)                    ((0x00000FC0&(data))>>6)
#define  EPI_EPI_LANE_DST_MUX0_get_lane_d_st_c0_mux_sel(data)                    (0x0000003F&(data))

#define  EPI_EPI_LANE_DST_MUX1                                                   0x18026384
#define  EPI_EPI_LANE_DST_MUX1_reg_addr                                          "0xB8026384"
#define  EPI_EPI_LANE_DST_MUX1_reg                                               0xB8026384
#define  EPI_EPI_LANE_DST_MUX1_inst_addr                                         "0x0043"
#define  set_EPI_EPI_LANE_DST_MUX1_reg(data)                                     (*((volatile unsigned int*)EPI_EPI_LANE_DST_MUX1_reg)=data)
#define  get_EPI_EPI_LANE_DST_MUX1_reg                                           (*((volatile unsigned int*)EPI_EPI_LANE_DST_MUX1_reg))
#define  EPI_EPI_LANE_DST_MUX1_lane_d_st_c9_mux_sel_shift                        (24)
#define  EPI_EPI_LANE_DST_MUX1_lane_d_st_c8_mux_sel_shift                        (18)
#define  EPI_EPI_LANE_DST_MUX1_lane_d_st_c7_mux_sel_shift                        (12)
#define  EPI_EPI_LANE_DST_MUX1_lane_d_st_c6_mux_sel_shift                        (6)
#define  EPI_EPI_LANE_DST_MUX1_lane_d_st_c5_mux_sel_shift                        (0)
#define  EPI_EPI_LANE_DST_MUX1_lane_d_st_c9_mux_sel_mask                         (0x3F000000)
#define  EPI_EPI_LANE_DST_MUX1_lane_d_st_c8_mux_sel_mask                         (0x00FC0000)
#define  EPI_EPI_LANE_DST_MUX1_lane_d_st_c7_mux_sel_mask                         (0x0003F000)
#define  EPI_EPI_LANE_DST_MUX1_lane_d_st_c6_mux_sel_mask                         (0x00000FC0)
#define  EPI_EPI_LANE_DST_MUX1_lane_d_st_c5_mux_sel_mask                         (0x0000003F)
#define  EPI_EPI_LANE_DST_MUX1_lane_d_st_c9_mux_sel(data)                        (0x3F000000&((data)<<24))
#define  EPI_EPI_LANE_DST_MUX1_lane_d_st_c8_mux_sel(data)                        (0x00FC0000&((data)<<18))
#define  EPI_EPI_LANE_DST_MUX1_lane_d_st_c7_mux_sel(data)                        (0x0003F000&((data)<<12))
#define  EPI_EPI_LANE_DST_MUX1_lane_d_st_c6_mux_sel(data)                        (0x00000FC0&((data)<<6))
#define  EPI_EPI_LANE_DST_MUX1_lane_d_st_c5_mux_sel(data)                        (0x0000003F&(data))
#define  EPI_EPI_LANE_DST_MUX1_get_lane_d_st_c9_mux_sel(data)                    ((0x3F000000&(data))>>24)
#define  EPI_EPI_LANE_DST_MUX1_get_lane_d_st_c8_mux_sel(data)                    ((0x00FC0000&(data))>>18)
#define  EPI_EPI_LANE_DST_MUX1_get_lane_d_st_c7_mux_sel(data)                    ((0x0003F000&(data))>>12)
#define  EPI_EPI_LANE_DST_MUX1_get_lane_d_st_c6_mux_sel(data)                    ((0x00000FC0&(data))>>6)
#define  EPI_EPI_LANE_DST_MUX1_get_lane_d_st_c5_mux_sel(data)                    (0x0000003F&(data))

#define  EPI_EPI_LANE_DST_MUX2                                                   0x18026388
#define  EPI_EPI_LANE_DST_MUX2_reg_addr                                          "0xB8026388"
#define  EPI_EPI_LANE_DST_MUX2_reg                                               0xB8026388
#define  EPI_EPI_LANE_DST_MUX2_inst_addr                                         "0x0044"
#define  set_EPI_EPI_LANE_DST_MUX2_reg(data)                                     (*((volatile unsigned int*)EPI_EPI_LANE_DST_MUX2_reg)=data)
#define  get_EPI_EPI_LANE_DST_MUX2_reg                                           (*((volatile unsigned int*)EPI_EPI_LANE_DST_MUX2_reg))
#define  EPI_EPI_LANE_DST_MUX2_lane_d_st_c14_mux_sel_shift                       (24)
#define  EPI_EPI_LANE_DST_MUX2_lane_d_st_c13_mux_sel_shift                       (18)
#define  EPI_EPI_LANE_DST_MUX2_lane_d_st_c12_mux_sel_shift                       (12)
#define  EPI_EPI_LANE_DST_MUX2_lane_d_st_c11_mux_sel_shift                       (6)
#define  EPI_EPI_LANE_DST_MUX2_lane_d_st_c10_mux_sel_shift                       (0)
#define  EPI_EPI_LANE_DST_MUX2_lane_d_st_c14_mux_sel_mask                        (0x3F000000)
#define  EPI_EPI_LANE_DST_MUX2_lane_d_st_c13_mux_sel_mask                        (0x00FC0000)
#define  EPI_EPI_LANE_DST_MUX2_lane_d_st_c12_mux_sel_mask                        (0x0003F000)
#define  EPI_EPI_LANE_DST_MUX2_lane_d_st_c11_mux_sel_mask                        (0x00000FC0)
#define  EPI_EPI_LANE_DST_MUX2_lane_d_st_c10_mux_sel_mask                        (0x0000003F)
#define  EPI_EPI_LANE_DST_MUX2_lane_d_st_c14_mux_sel(data)                       (0x3F000000&((data)<<24))
#define  EPI_EPI_LANE_DST_MUX2_lane_d_st_c13_mux_sel(data)                       (0x00FC0000&((data)<<18))
#define  EPI_EPI_LANE_DST_MUX2_lane_d_st_c12_mux_sel(data)                       (0x0003F000&((data)<<12))
#define  EPI_EPI_LANE_DST_MUX2_lane_d_st_c11_mux_sel(data)                       (0x00000FC0&((data)<<6))
#define  EPI_EPI_LANE_DST_MUX2_lane_d_st_c10_mux_sel(data)                       (0x0000003F&(data))
#define  EPI_EPI_LANE_DST_MUX2_get_lane_d_st_c14_mux_sel(data)                   ((0x3F000000&(data))>>24)
#define  EPI_EPI_LANE_DST_MUX2_get_lane_d_st_c13_mux_sel(data)                   ((0x00FC0000&(data))>>18)
#define  EPI_EPI_LANE_DST_MUX2_get_lane_d_st_c12_mux_sel(data)                   ((0x0003F000&(data))>>12)
#define  EPI_EPI_LANE_DST_MUX2_get_lane_d_st_c11_mux_sel(data)                   ((0x00000FC0&(data))>>6)
#define  EPI_EPI_LANE_DST_MUX2_get_lane_d_st_c10_mux_sel(data)                   (0x0000003F&(data))

#define  EPI_EPI_LANE_DST_MUX3                                                   0x1802638C
#define  EPI_EPI_LANE_DST_MUX3_reg_addr                                          "0xB802638C"
#define  EPI_EPI_LANE_DST_MUX3_reg                                               0xB802638C
#define  EPI_EPI_LANE_DST_MUX3_inst_addr                                         "0x0045"
#define  set_EPI_EPI_LANE_DST_MUX3_reg(data)                                     (*((volatile unsigned int*)EPI_EPI_LANE_DST_MUX3_reg)=data)
#define  get_EPI_EPI_LANE_DST_MUX3_reg                                           (*((volatile unsigned int*)EPI_EPI_LANE_DST_MUX3_reg))
#define  EPI_EPI_LANE_DST_MUX3_lane_d_st_c19_mux_sel_shift                       (24)
#define  EPI_EPI_LANE_DST_MUX3_lane_d_st_c18_mux_sel_shift                       (18)
#define  EPI_EPI_LANE_DST_MUX3_lane_d_st_c17_mux_sel_shift                       (12)
#define  EPI_EPI_LANE_DST_MUX3_lane_d_st_c16_mux_sel_shift                       (6)
#define  EPI_EPI_LANE_DST_MUX3_lane_d_st_c15_mux_sel_shift                       (0)
#define  EPI_EPI_LANE_DST_MUX3_lane_d_st_c19_mux_sel_mask                        (0x3F000000)
#define  EPI_EPI_LANE_DST_MUX3_lane_d_st_c18_mux_sel_mask                        (0x00FC0000)
#define  EPI_EPI_LANE_DST_MUX3_lane_d_st_c17_mux_sel_mask                        (0x0003F000)
#define  EPI_EPI_LANE_DST_MUX3_lane_d_st_c16_mux_sel_mask                        (0x00000FC0)
#define  EPI_EPI_LANE_DST_MUX3_lane_d_st_c15_mux_sel_mask                        (0x0000003F)
#define  EPI_EPI_LANE_DST_MUX3_lane_d_st_c19_mux_sel(data)                       (0x3F000000&((data)<<24))
#define  EPI_EPI_LANE_DST_MUX3_lane_d_st_c18_mux_sel(data)                       (0x00FC0000&((data)<<18))
#define  EPI_EPI_LANE_DST_MUX3_lane_d_st_c17_mux_sel(data)                       (0x0003F000&((data)<<12))
#define  EPI_EPI_LANE_DST_MUX3_lane_d_st_c16_mux_sel(data)                       (0x00000FC0&((data)<<6))
#define  EPI_EPI_LANE_DST_MUX3_lane_d_st_c15_mux_sel(data)                       (0x0000003F&(data))
#define  EPI_EPI_LANE_DST_MUX3_get_lane_d_st_c19_mux_sel(data)                   ((0x3F000000&(data))>>24)
#define  EPI_EPI_LANE_DST_MUX3_get_lane_d_st_c18_mux_sel(data)                   ((0x00FC0000&(data))>>18)
#define  EPI_EPI_LANE_DST_MUX3_get_lane_d_st_c17_mux_sel(data)                   ((0x0003F000&(data))>>12)
#define  EPI_EPI_LANE_DST_MUX3_get_lane_d_st_c16_mux_sel(data)                   ((0x00000FC0&(data))>>6)
#define  EPI_EPI_LANE_DST_MUX3_get_lane_d_st_c15_mux_sel(data)                   (0x0000003F&(data))

#define  EPI_EPI_LANE_DST_MUX4                                                   0x18026390
#define  EPI_EPI_LANE_DST_MUX4_reg_addr                                          "0xB8026390"
#define  EPI_EPI_LANE_DST_MUX4_reg                                               0xB8026390
#define  EPI_EPI_LANE_DST_MUX4_inst_addr                                         "0x0046"
#define  set_EPI_EPI_LANE_DST_MUX4_reg(data)                                     (*((volatile unsigned int*)EPI_EPI_LANE_DST_MUX4_reg)=data)
#define  get_EPI_EPI_LANE_DST_MUX4_reg                                           (*((volatile unsigned int*)EPI_EPI_LANE_DST_MUX4_reg))
#define  EPI_EPI_LANE_DST_MUX4_lane_d_st_c24_mux_sel_shift                       (24)
#define  EPI_EPI_LANE_DST_MUX4_lane_d_st_c23_mux_sel_shift                       (18)
#define  EPI_EPI_LANE_DST_MUX4_lane_d_st_c22_mux_sel_shift                       (12)
#define  EPI_EPI_LANE_DST_MUX4_lane_d_st_c21_mux_sel_shift                       (6)
#define  EPI_EPI_LANE_DST_MUX4_lane_d_st_c20_mux_sel_shift                       (0)
#define  EPI_EPI_LANE_DST_MUX4_lane_d_st_c24_mux_sel_mask                        (0x3F000000)
#define  EPI_EPI_LANE_DST_MUX4_lane_d_st_c23_mux_sel_mask                        (0x00FC0000)
#define  EPI_EPI_LANE_DST_MUX4_lane_d_st_c22_mux_sel_mask                        (0x0003F000)
#define  EPI_EPI_LANE_DST_MUX4_lane_d_st_c21_mux_sel_mask                        (0x00000FC0)
#define  EPI_EPI_LANE_DST_MUX4_lane_d_st_c20_mux_sel_mask                        (0x0000003F)
#define  EPI_EPI_LANE_DST_MUX4_lane_d_st_c24_mux_sel(data)                       (0x3F000000&((data)<<24))
#define  EPI_EPI_LANE_DST_MUX4_lane_d_st_c23_mux_sel(data)                       (0x00FC0000&((data)<<18))
#define  EPI_EPI_LANE_DST_MUX4_lane_d_st_c22_mux_sel(data)                       (0x0003F000&((data)<<12))
#define  EPI_EPI_LANE_DST_MUX4_lane_d_st_c21_mux_sel(data)                       (0x00000FC0&((data)<<6))
#define  EPI_EPI_LANE_DST_MUX4_lane_d_st_c20_mux_sel(data)                       (0x0000003F&(data))
#define  EPI_EPI_LANE_DST_MUX4_get_lane_d_st_c24_mux_sel(data)                   ((0x3F000000&(data))>>24)
#define  EPI_EPI_LANE_DST_MUX4_get_lane_d_st_c23_mux_sel(data)                   ((0x00FC0000&(data))>>18)
#define  EPI_EPI_LANE_DST_MUX4_get_lane_d_st_c22_mux_sel(data)                   ((0x0003F000&(data))>>12)
#define  EPI_EPI_LANE_DST_MUX4_get_lane_d_st_c21_mux_sel(data)                   ((0x00000FC0&(data))>>6)
#define  EPI_EPI_LANE_DST_MUX4_get_lane_d_st_c20_mux_sel(data)                   (0x0000003F&(data))

#define  EPI_EPI_LANE_DST_MUX5                                                   0x18026394
#define  EPI_EPI_LANE_DST_MUX5_reg_addr                                          "0xB8026394"
#define  EPI_EPI_LANE_DST_MUX5_reg                                               0xB8026394
#define  EPI_EPI_LANE_DST_MUX5_inst_addr                                         "0x0047"
#define  set_EPI_EPI_LANE_DST_MUX5_reg(data)                                     (*((volatile unsigned int*)EPI_EPI_LANE_DST_MUX5_reg)=data)
#define  get_EPI_EPI_LANE_DST_MUX5_reg                                           (*((volatile unsigned int*)EPI_EPI_LANE_DST_MUX5_reg))
#define  EPI_EPI_LANE_DST_MUX5_lane_d_st_c29_mux_sel_shift                       (24)
#define  EPI_EPI_LANE_DST_MUX5_lane_d_st_c28_mux_sel_shift                       (18)
#define  EPI_EPI_LANE_DST_MUX5_lane_d_st_c27_mux_sel_shift                       (12)
#define  EPI_EPI_LANE_DST_MUX5_lane_d_st_c26_mux_sel_shift                       (6)
#define  EPI_EPI_LANE_DST_MUX5_lane_d_st_c25_mux_sel_shift                       (0)
#define  EPI_EPI_LANE_DST_MUX5_lane_d_st_c29_mux_sel_mask                        (0x3F000000)
#define  EPI_EPI_LANE_DST_MUX5_lane_d_st_c28_mux_sel_mask                        (0x00FC0000)
#define  EPI_EPI_LANE_DST_MUX5_lane_d_st_c27_mux_sel_mask                        (0x0003F000)
#define  EPI_EPI_LANE_DST_MUX5_lane_d_st_c26_mux_sel_mask                        (0x00000FC0)
#define  EPI_EPI_LANE_DST_MUX5_lane_d_st_c25_mux_sel_mask                        (0x0000003F)
#define  EPI_EPI_LANE_DST_MUX5_lane_d_st_c29_mux_sel(data)                       (0x3F000000&((data)<<24))
#define  EPI_EPI_LANE_DST_MUX5_lane_d_st_c28_mux_sel(data)                       (0x00FC0000&((data)<<18))
#define  EPI_EPI_LANE_DST_MUX5_lane_d_st_c27_mux_sel(data)                       (0x0003F000&((data)<<12))
#define  EPI_EPI_LANE_DST_MUX5_lane_d_st_c26_mux_sel(data)                       (0x00000FC0&((data)<<6))
#define  EPI_EPI_LANE_DST_MUX5_lane_d_st_c25_mux_sel(data)                       (0x0000003F&(data))
#define  EPI_EPI_LANE_DST_MUX5_get_lane_d_st_c29_mux_sel(data)                   ((0x3F000000&(data))>>24)
#define  EPI_EPI_LANE_DST_MUX5_get_lane_d_st_c28_mux_sel(data)                   ((0x00FC0000&(data))>>18)
#define  EPI_EPI_LANE_DST_MUX5_get_lane_d_st_c27_mux_sel(data)                   ((0x0003F000&(data))>>12)
#define  EPI_EPI_LANE_DST_MUX5_get_lane_d_st_c26_mux_sel(data)                   ((0x00000FC0&(data))>>6)
#define  EPI_EPI_LANE_DST_MUX5_get_lane_d_st_c25_mux_sel(data)                   (0x0000003F&(data))

#define  EPI_EPI_LANE_CST_MUX0                                                   0x18026398
#define  EPI_EPI_LANE_CST_MUX0_reg_addr                                          "0xB8026398"
#define  EPI_EPI_LANE_CST_MUX0_reg                                               0xB8026398
#define  EPI_EPI_LANE_CST_MUX0_inst_addr                                         "0x0048"
#define  set_EPI_EPI_LANE_CST_MUX0_reg(data)                                     (*((volatile unsigned int*)EPI_EPI_LANE_CST_MUX0_reg)=data)
#define  get_EPI_EPI_LANE_CST_MUX0_reg                                           (*((volatile unsigned int*)EPI_EPI_LANE_CST_MUX0_reg))
#define  EPI_EPI_LANE_CST_MUX0_lane_c_st_c4_mux_sel_shift                        (24)
#define  EPI_EPI_LANE_CST_MUX0_lane_c_st_c3_mux_sel_shift                        (18)
#define  EPI_EPI_LANE_CST_MUX0_lane_c_st_c2_mux_sel_shift                        (12)
#define  EPI_EPI_LANE_CST_MUX0_lane_c_st_c1_mux_sel_shift                        (6)
#define  EPI_EPI_LANE_CST_MUX0_lane_c_st_c0_mux_sel_shift                        (0)
#define  EPI_EPI_LANE_CST_MUX0_lane_c_st_c4_mux_sel_mask                         (0x3F000000)
#define  EPI_EPI_LANE_CST_MUX0_lane_c_st_c3_mux_sel_mask                         (0x00FC0000)
#define  EPI_EPI_LANE_CST_MUX0_lane_c_st_c2_mux_sel_mask                         (0x0003F000)
#define  EPI_EPI_LANE_CST_MUX0_lane_c_st_c1_mux_sel_mask                         (0x00000FC0)
#define  EPI_EPI_LANE_CST_MUX0_lane_c_st_c0_mux_sel_mask                         (0x0000003F)
#define  EPI_EPI_LANE_CST_MUX0_lane_c_st_c4_mux_sel(data)                        (0x3F000000&((data)<<24))
#define  EPI_EPI_LANE_CST_MUX0_lane_c_st_c3_mux_sel(data)                        (0x00FC0000&((data)<<18))
#define  EPI_EPI_LANE_CST_MUX0_lane_c_st_c2_mux_sel(data)                        (0x0003F000&((data)<<12))
#define  EPI_EPI_LANE_CST_MUX0_lane_c_st_c1_mux_sel(data)                        (0x00000FC0&((data)<<6))
#define  EPI_EPI_LANE_CST_MUX0_lane_c_st_c0_mux_sel(data)                        (0x0000003F&(data))
#define  EPI_EPI_LANE_CST_MUX0_get_lane_c_st_c4_mux_sel(data)                    ((0x3F000000&(data))>>24)
#define  EPI_EPI_LANE_CST_MUX0_get_lane_c_st_c3_mux_sel(data)                    ((0x00FC0000&(data))>>18)
#define  EPI_EPI_LANE_CST_MUX0_get_lane_c_st_c2_mux_sel(data)                    ((0x0003F000&(data))>>12)
#define  EPI_EPI_LANE_CST_MUX0_get_lane_c_st_c1_mux_sel(data)                    ((0x00000FC0&(data))>>6)
#define  EPI_EPI_LANE_CST_MUX0_get_lane_c_st_c0_mux_sel(data)                    (0x0000003F&(data))

#define  EPI_EPI_LANE_CST_MUX1                                                   0x1802639C
#define  EPI_EPI_LANE_CST_MUX1_reg_addr                                          "0xB802639C"
#define  EPI_EPI_LANE_CST_MUX1_reg                                               0xB802639C
#define  EPI_EPI_LANE_CST_MUX1_inst_addr                                         "0x0049"
#define  set_EPI_EPI_LANE_CST_MUX1_reg(data)                                     (*((volatile unsigned int*)EPI_EPI_LANE_CST_MUX1_reg)=data)
#define  get_EPI_EPI_LANE_CST_MUX1_reg                                           (*((volatile unsigned int*)EPI_EPI_LANE_CST_MUX1_reg))
#define  EPI_EPI_LANE_CST_MUX1_lane_c_st_c9_mux_sel_shift                        (24)
#define  EPI_EPI_LANE_CST_MUX1_lane_c_st_c8_mux_sel_shift                        (18)
#define  EPI_EPI_LANE_CST_MUX1_lane_c_st_c7_mux_sel_shift                        (12)
#define  EPI_EPI_LANE_CST_MUX1_lane_c_st_c6_mux_sel_shift                        (6)
#define  EPI_EPI_LANE_CST_MUX1_lane_c_st_c5_mux_sel_shift                        (0)
#define  EPI_EPI_LANE_CST_MUX1_lane_c_st_c9_mux_sel_mask                         (0x3F000000)
#define  EPI_EPI_LANE_CST_MUX1_lane_c_st_c8_mux_sel_mask                         (0x00FC0000)
#define  EPI_EPI_LANE_CST_MUX1_lane_c_st_c7_mux_sel_mask                         (0x0003F000)
#define  EPI_EPI_LANE_CST_MUX1_lane_c_st_c6_mux_sel_mask                         (0x00000FC0)
#define  EPI_EPI_LANE_CST_MUX1_lane_c_st_c5_mux_sel_mask                         (0x0000003F)
#define  EPI_EPI_LANE_CST_MUX1_lane_c_st_c9_mux_sel(data)                        (0x3F000000&((data)<<24))
#define  EPI_EPI_LANE_CST_MUX1_lane_c_st_c8_mux_sel(data)                        (0x00FC0000&((data)<<18))
#define  EPI_EPI_LANE_CST_MUX1_lane_c_st_c7_mux_sel(data)                        (0x0003F000&((data)<<12))
#define  EPI_EPI_LANE_CST_MUX1_lane_c_st_c6_mux_sel(data)                        (0x00000FC0&((data)<<6))
#define  EPI_EPI_LANE_CST_MUX1_lane_c_st_c5_mux_sel(data)                        (0x0000003F&(data))
#define  EPI_EPI_LANE_CST_MUX1_get_lane_c_st_c9_mux_sel(data)                    ((0x3F000000&(data))>>24)
#define  EPI_EPI_LANE_CST_MUX1_get_lane_c_st_c8_mux_sel(data)                    ((0x00FC0000&(data))>>18)
#define  EPI_EPI_LANE_CST_MUX1_get_lane_c_st_c7_mux_sel(data)                    ((0x0003F000&(data))>>12)
#define  EPI_EPI_LANE_CST_MUX1_get_lane_c_st_c6_mux_sel(data)                    ((0x00000FC0&(data))>>6)
#define  EPI_EPI_LANE_CST_MUX1_get_lane_c_st_c5_mux_sel(data)                    (0x0000003F&(data))

#define  EPI_EPI_LANE_CST_MUX2                                                   0x180263A0
#define  EPI_EPI_LANE_CST_MUX2_reg_addr                                          "0xB80263A0"
#define  EPI_EPI_LANE_CST_MUX2_reg                                               0xB80263A0
#define  EPI_EPI_LANE_CST_MUX2_inst_addr                                         "0x004A"
#define  set_EPI_EPI_LANE_CST_MUX2_reg(data)                                     (*((volatile unsigned int*)EPI_EPI_LANE_CST_MUX2_reg)=data)
#define  get_EPI_EPI_LANE_CST_MUX2_reg                                           (*((volatile unsigned int*)EPI_EPI_LANE_CST_MUX2_reg))
#define  EPI_EPI_LANE_CST_MUX2_lane_c_st_c14_mux_sel_shift                       (24)
#define  EPI_EPI_LANE_CST_MUX2_lane_c_st_c13_mux_sel_shift                       (18)
#define  EPI_EPI_LANE_CST_MUX2_lane_c_st_c12_mux_sel_shift                       (12)
#define  EPI_EPI_LANE_CST_MUX2_lane_c_st_c11_mux_sel_shift                       (6)
#define  EPI_EPI_LANE_CST_MUX2_lane_c_st_c10_mux_sel_shift                       (0)
#define  EPI_EPI_LANE_CST_MUX2_lane_c_st_c14_mux_sel_mask                        (0x3F000000)
#define  EPI_EPI_LANE_CST_MUX2_lane_c_st_c13_mux_sel_mask                        (0x00FC0000)
#define  EPI_EPI_LANE_CST_MUX2_lane_c_st_c12_mux_sel_mask                        (0x0003F000)
#define  EPI_EPI_LANE_CST_MUX2_lane_c_st_c11_mux_sel_mask                        (0x00000FC0)
#define  EPI_EPI_LANE_CST_MUX2_lane_c_st_c10_mux_sel_mask                        (0x0000003F)
#define  EPI_EPI_LANE_CST_MUX2_lane_c_st_c14_mux_sel(data)                       (0x3F000000&((data)<<24))
#define  EPI_EPI_LANE_CST_MUX2_lane_c_st_c13_mux_sel(data)                       (0x00FC0000&((data)<<18))
#define  EPI_EPI_LANE_CST_MUX2_lane_c_st_c12_mux_sel(data)                       (0x0003F000&((data)<<12))
#define  EPI_EPI_LANE_CST_MUX2_lane_c_st_c11_mux_sel(data)                       (0x00000FC0&((data)<<6))
#define  EPI_EPI_LANE_CST_MUX2_lane_c_st_c10_mux_sel(data)                       (0x0000003F&(data))
#define  EPI_EPI_LANE_CST_MUX2_get_lane_c_st_c14_mux_sel(data)                   ((0x3F000000&(data))>>24)
#define  EPI_EPI_LANE_CST_MUX2_get_lane_c_st_c13_mux_sel(data)                   ((0x00FC0000&(data))>>18)
#define  EPI_EPI_LANE_CST_MUX2_get_lane_c_st_c12_mux_sel(data)                   ((0x0003F000&(data))>>12)
#define  EPI_EPI_LANE_CST_MUX2_get_lane_c_st_c11_mux_sel(data)                   ((0x00000FC0&(data))>>6)
#define  EPI_EPI_LANE_CST_MUX2_get_lane_c_st_c10_mux_sel(data)                   (0x0000003F&(data))

#define  EPI_EPI_LANE_CST_MUX3                                                   0x180263A4
#define  EPI_EPI_LANE_CST_MUX3_reg_addr                                          "0xB80263A4"
#define  EPI_EPI_LANE_CST_MUX3_reg                                               0xB80263A4
#define  EPI_EPI_LANE_CST_MUX3_inst_addr                                         "0x004B"
#define  set_EPI_EPI_LANE_CST_MUX3_reg(data)                                     (*((volatile unsigned int*)EPI_EPI_LANE_CST_MUX3_reg)=data)
#define  get_EPI_EPI_LANE_CST_MUX3_reg                                           (*((volatile unsigned int*)EPI_EPI_LANE_CST_MUX3_reg))
#define  EPI_EPI_LANE_CST_MUX3_lane_c_st_c19_mux_sel_shift                       (24)
#define  EPI_EPI_LANE_CST_MUX3_lane_c_st_c18_mux_sel_shift                       (18)
#define  EPI_EPI_LANE_CST_MUX3_lane_c_st_c17_mux_sel_shift                       (12)
#define  EPI_EPI_LANE_CST_MUX3_lane_c_st_c16_mux_sel_shift                       (6)
#define  EPI_EPI_LANE_CST_MUX3_lane_c_st_c15_mux_sel_shift                       (0)
#define  EPI_EPI_LANE_CST_MUX3_lane_c_st_c19_mux_sel_mask                        (0x3F000000)
#define  EPI_EPI_LANE_CST_MUX3_lane_c_st_c18_mux_sel_mask                        (0x00FC0000)
#define  EPI_EPI_LANE_CST_MUX3_lane_c_st_c17_mux_sel_mask                        (0x0003F000)
#define  EPI_EPI_LANE_CST_MUX3_lane_c_st_c16_mux_sel_mask                        (0x00000FC0)
#define  EPI_EPI_LANE_CST_MUX3_lane_c_st_c15_mux_sel_mask                        (0x0000003F)
#define  EPI_EPI_LANE_CST_MUX3_lane_c_st_c19_mux_sel(data)                       (0x3F000000&((data)<<24))
#define  EPI_EPI_LANE_CST_MUX3_lane_c_st_c18_mux_sel(data)                       (0x00FC0000&((data)<<18))
#define  EPI_EPI_LANE_CST_MUX3_lane_c_st_c17_mux_sel(data)                       (0x0003F000&((data)<<12))
#define  EPI_EPI_LANE_CST_MUX3_lane_c_st_c16_mux_sel(data)                       (0x00000FC0&((data)<<6))
#define  EPI_EPI_LANE_CST_MUX3_lane_c_st_c15_mux_sel(data)                       (0x0000003F&(data))
#define  EPI_EPI_LANE_CST_MUX3_get_lane_c_st_c19_mux_sel(data)                   ((0x3F000000&(data))>>24)
#define  EPI_EPI_LANE_CST_MUX3_get_lane_c_st_c18_mux_sel(data)                   ((0x00FC0000&(data))>>18)
#define  EPI_EPI_LANE_CST_MUX3_get_lane_c_st_c17_mux_sel(data)                   ((0x0003F000&(data))>>12)
#define  EPI_EPI_LANE_CST_MUX3_get_lane_c_st_c16_mux_sel(data)                   ((0x00000FC0&(data))>>6)
#define  EPI_EPI_LANE_CST_MUX3_get_lane_c_st_c15_mux_sel(data)                   (0x0000003F&(data))

#define  EPI_EPI_LANE_CST_MUX4                                                   0x180263A8
#define  EPI_EPI_LANE_CST_MUX4_reg_addr                                          "0xB80263A8"
#define  EPI_EPI_LANE_CST_MUX4_reg                                               0xB80263A8
#define  EPI_EPI_LANE_CST_MUX4_inst_addr                                         "0x004C"
#define  set_EPI_EPI_LANE_CST_MUX4_reg(data)                                     (*((volatile unsigned int*)EPI_EPI_LANE_CST_MUX4_reg)=data)
#define  get_EPI_EPI_LANE_CST_MUX4_reg                                           (*((volatile unsigned int*)EPI_EPI_LANE_CST_MUX4_reg))
#define  EPI_EPI_LANE_CST_MUX4_lane_c_st_c24_mux_sel_shift                       (24)
#define  EPI_EPI_LANE_CST_MUX4_lane_c_st_c23_mux_sel_shift                       (18)
#define  EPI_EPI_LANE_CST_MUX4_lane_c_st_c22_mux_sel_shift                       (12)
#define  EPI_EPI_LANE_CST_MUX4_lane_c_st_c21_mux_sel_shift                       (6)
#define  EPI_EPI_LANE_CST_MUX4_lane_c_st_c20_mux_sel_shift                       (0)
#define  EPI_EPI_LANE_CST_MUX4_lane_c_st_c24_mux_sel_mask                        (0x3F000000)
#define  EPI_EPI_LANE_CST_MUX4_lane_c_st_c23_mux_sel_mask                        (0x00FC0000)
#define  EPI_EPI_LANE_CST_MUX4_lane_c_st_c22_mux_sel_mask                        (0x0003F000)
#define  EPI_EPI_LANE_CST_MUX4_lane_c_st_c21_mux_sel_mask                        (0x00000FC0)
#define  EPI_EPI_LANE_CST_MUX4_lane_c_st_c20_mux_sel_mask                        (0x0000003F)
#define  EPI_EPI_LANE_CST_MUX4_lane_c_st_c24_mux_sel(data)                       (0x3F000000&((data)<<24))
#define  EPI_EPI_LANE_CST_MUX4_lane_c_st_c23_mux_sel(data)                       (0x00FC0000&((data)<<18))
#define  EPI_EPI_LANE_CST_MUX4_lane_c_st_c22_mux_sel(data)                       (0x0003F000&((data)<<12))
#define  EPI_EPI_LANE_CST_MUX4_lane_c_st_c21_mux_sel(data)                       (0x00000FC0&((data)<<6))
#define  EPI_EPI_LANE_CST_MUX4_lane_c_st_c20_mux_sel(data)                       (0x0000003F&(data))
#define  EPI_EPI_LANE_CST_MUX4_get_lane_c_st_c24_mux_sel(data)                   ((0x3F000000&(data))>>24)
#define  EPI_EPI_LANE_CST_MUX4_get_lane_c_st_c23_mux_sel(data)                   ((0x00FC0000&(data))>>18)
#define  EPI_EPI_LANE_CST_MUX4_get_lane_c_st_c22_mux_sel(data)                   ((0x0003F000&(data))>>12)
#define  EPI_EPI_LANE_CST_MUX4_get_lane_c_st_c21_mux_sel(data)                   ((0x00000FC0&(data))>>6)
#define  EPI_EPI_LANE_CST_MUX4_get_lane_c_st_c20_mux_sel(data)                   (0x0000003F&(data))

#define  EPI_EPI_LANE_CST_MUX5                                                   0x180263AC
#define  EPI_EPI_LANE_CST_MUX5_reg_addr                                          "0xB80263AC"
#define  EPI_EPI_LANE_CST_MUX5_reg                                               0xB80263AC
#define  EPI_EPI_LANE_CST_MUX5_inst_addr                                         "0x004D"
#define  set_EPI_EPI_LANE_CST_MUX5_reg(data)                                     (*((volatile unsigned int*)EPI_EPI_LANE_CST_MUX5_reg)=data)
#define  get_EPI_EPI_LANE_CST_MUX5_reg                                           (*((volatile unsigned int*)EPI_EPI_LANE_CST_MUX5_reg))
#define  EPI_EPI_LANE_CST_MUX5_lane_c_st_c29_mux_sel_shift                       (24)
#define  EPI_EPI_LANE_CST_MUX5_lane_c_st_c28_mux_sel_shift                       (18)
#define  EPI_EPI_LANE_CST_MUX5_lane_c_st_c27_mux_sel_shift                       (12)
#define  EPI_EPI_LANE_CST_MUX5_lane_c_st_c26_mux_sel_shift                       (6)
#define  EPI_EPI_LANE_CST_MUX5_lane_c_st_c25_mux_sel_shift                       (0)
#define  EPI_EPI_LANE_CST_MUX5_lane_c_st_c29_mux_sel_mask                        (0x3F000000)
#define  EPI_EPI_LANE_CST_MUX5_lane_c_st_c28_mux_sel_mask                        (0x00FC0000)
#define  EPI_EPI_LANE_CST_MUX5_lane_c_st_c27_mux_sel_mask                        (0x0003F000)
#define  EPI_EPI_LANE_CST_MUX5_lane_c_st_c26_mux_sel_mask                        (0x00000FC0)
#define  EPI_EPI_LANE_CST_MUX5_lane_c_st_c25_mux_sel_mask                        (0x0000003F)
#define  EPI_EPI_LANE_CST_MUX5_lane_c_st_c29_mux_sel(data)                       (0x3F000000&((data)<<24))
#define  EPI_EPI_LANE_CST_MUX5_lane_c_st_c28_mux_sel(data)                       (0x00FC0000&((data)<<18))
#define  EPI_EPI_LANE_CST_MUX5_lane_c_st_c27_mux_sel(data)                       (0x0003F000&((data)<<12))
#define  EPI_EPI_LANE_CST_MUX5_lane_c_st_c26_mux_sel(data)                       (0x00000FC0&((data)<<6))
#define  EPI_EPI_LANE_CST_MUX5_lane_c_st_c25_mux_sel(data)                       (0x0000003F&(data))
#define  EPI_EPI_LANE_CST_MUX5_get_lane_c_st_c29_mux_sel(data)                   ((0x3F000000&(data))>>24)
#define  EPI_EPI_LANE_CST_MUX5_get_lane_c_st_c28_mux_sel(data)                   ((0x00FC0000&(data))>>18)
#define  EPI_EPI_LANE_CST_MUX5_get_lane_c_st_c27_mux_sel(data)                   ((0x0003F000&(data))>>12)
#define  EPI_EPI_LANE_CST_MUX5_get_lane_c_st_c26_mux_sel(data)                   ((0x00000FC0&(data))>>6)
#define  EPI_EPI_LANE_CST_MUX5_get_lane_c_st_c25_mux_sel(data)                   (0x0000003F&(data))

#define  EPI_EPI_LANE_CTR1_MUX0                                                  0x180263B0
#define  EPI_EPI_LANE_CTR1_MUX0_reg_addr                                         "0xB80263B0"
#define  EPI_EPI_LANE_CTR1_MUX0_reg                                              0xB80263B0
#define  EPI_EPI_LANE_CTR1_MUX0_inst_addr                                        "0x004E"
#define  set_EPI_EPI_LANE_CTR1_MUX0_reg(data)                                    (*((volatile unsigned int*)EPI_EPI_LANE_CTR1_MUX0_reg)=data)
#define  get_EPI_EPI_LANE_CTR1_MUX0_reg                                          (*((volatile unsigned int*)EPI_EPI_LANE_CTR1_MUX0_reg))
#define  EPI_EPI_LANE_CTR1_MUX0_lane_ctr1_c4_mux_sel_shift                       (24)
#define  EPI_EPI_LANE_CTR1_MUX0_lane_ctr1_c3_mux_sel_shift                       (18)
#define  EPI_EPI_LANE_CTR1_MUX0_lane_ctr1_c2_mux_sel_shift                       (12)
#define  EPI_EPI_LANE_CTR1_MUX0_lane_ctr1_c1_mux_sel_shift                       (6)
#define  EPI_EPI_LANE_CTR1_MUX0_lane_ctr1_c0_mux_sel_shift                       (0)
#define  EPI_EPI_LANE_CTR1_MUX0_lane_ctr1_c4_mux_sel_mask                        (0x3F000000)
#define  EPI_EPI_LANE_CTR1_MUX0_lane_ctr1_c3_mux_sel_mask                        (0x00FC0000)
#define  EPI_EPI_LANE_CTR1_MUX0_lane_ctr1_c2_mux_sel_mask                        (0x0003F000)
#define  EPI_EPI_LANE_CTR1_MUX0_lane_ctr1_c1_mux_sel_mask                        (0x00000FC0)
#define  EPI_EPI_LANE_CTR1_MUX0_lane_ctr1_c0_mux_sel_mask                        (0x0000003F)
#define  EPI_EPI_LANE_CTR1_MUX0_lane_ctr1_c4_mux_sel(data)                       (0x3F000000&((data)<<24))
#define  EPI_EPI_LANE_CTR1_MUX0_lane_ctr1_c3_mux_sel(data)                       (0x00FC0000&((data)<<18))
#define  EPI_EPI_LANE_CTR1_MUX0_lane_ctr1_c2_mux_sel(data)                       (0x0003F000&((data)<<12))
#define  EPI_EPI_LANE_CTR1_MUX0_lane_ctr1_c1_mux_sel(data)                       (0x00000FC0&((data)<<6))
#define  EPI_EPI_LANE_CTR1_MUX0_lane_ctr1_c0_mux_sel(data)                       (0x0000003F&(data))
#define  EPI_EPI_LANE_CTR1_MUX0_get_lane_ctr1_c4_mux_sel(data)                   ((0x3F000000&(data))>>24)
#define  EPI_EPI_LANE_CTR1_MUX0_get_lane_ctr1_c3_mux_sel(data)                   ((0x00FC0000&(data))>>18)
#define  EPI_EPI_LANE_CTR1_MUX0_get_lane_ctr1_c2_mux_sel(data)                   ((0x0003F000&(data))>>12)
#define  EPI_EPI_LANE_CTR1_MUX0_get_lane_ctr1_c1_mux_sel(data)                   ((0x00000FC0&(data))>>6)
#define  EPI_EPI_LANE_CTR1_MUX0_get_lane_ctr1_c0_mux_sel(data)                   (0x0000003F&(data))

#define  EPI_EPI_LANE_CTR1_MUX1                                                  0x180263B4
#define  EPI_EPI_LANE_CTR1_MUX1_reg_addr                                         "0xB80263B4"
#define  EPI_EPI_LANE_CTR1_MUX1_reg                                              0xB80263B4
#define  EPI_EPI_LANE_CTR1_MUX1_inst_addr                                        "0x004F"
#define  set_EPI_EPI_LANE_CTR1_MUX1_reg(data)                                    (*((volatile unsigned int*)EPI_EPI_LANE_CTR1_MUX1_reg)=data)
#define  get_EPI_EPI_LANE_CTR1_MUX1_reg                                          (*((volatile unsigned int*)EPI_EPI_LANE_CTR1_MUX1_reg))
#define  EPI_EPI_LANE_CTR1_MUX1_lane_ctr1_c9_mux_sel_shift                       (24)
#define  EPI_EPI_LANE_CTR1_MUX1_lane_ctr1_c8_mux_sel_shift                       (18)
#define  EPI_EPI_LANE_CTR1_MUX1_lane_ctr1_c7_mux_sel_shift                       (12)
#define  EPI_EPI_LANE_CTR1_MUX1_lane_ctr1_c6_mux_sel_shift                       (6)
#define  EPI_EPI_LANE_CTR1_MUX1_lane_ctr1_c5_mux_sel_shift                       (0)
#define  EPI_EPI_LANE_CTR1_MUX1_lane_ctr1_c9_mux_sel_mask                        (0x3F000000)
#define  EPI_EPI_LANE_CTR1_MUX1_lane_ctr1_c8_mux_sel_mask                        (0x00FC0000)
#define  EPI_EPI_LANE_CTR1_MUX1_lane_ctr1_c7_mux_sel_mask                        (0x0003F000)
#define  EPI_EPI_LANE_CTR1_MUX1_lane_ctr1_c6_mux_sel_mask                        (0x00000FC0)
#define  EPI_EPI_LANE_CTR1_MUX1_lane_ctr1_c5_mux_sel_mask                        (0x0000003F)
#define  EPI_EPI_LANE_CTR1_MUX1_lane_ctr1_c9_mux_sel(data)                       (0x3F000000&((data)<<24))
#define  EPI_EPI_LANE_CTR1_MUX1_lane_ctr1_c8_mux_sel(data)                       (0x00FC0000&((data)<<18))
#define  EPI_EPI_LANE_CTR1_MUX1_lane_ctr1_c7_mux_sel(data)                       (0x0003F000&((data)<<12))
#define  EPI_EPI_LANE_CTR1_MUX1_lane_ctr1_c6_mux_sel(data)                       (0x00000FC0&((data)<<6))
#define  EPI_EPI_LANE_CTR1_MUX1_lane_ctr1_c5_mux_sel(data)                       (0x0000003F&(data))
#define  EPI_EPI_LANE_CTR1_MUX1_get_lane_ctr1_c9_mux_sel(data)                   ((0x3F000000&(data))>>24)
#define  EPI_EPI_LANE_CTR1_MUX1_get_lane_ctr1_c8_mux_sel(data)                   ((0x00FC0000&(data))>>18)
#define  EPI_EPI_LANE_CTR1_MUX1_get_lane_ctr1_c7_mux_sel(data)                   ((0x0003F000&(data))>>12)
#define  EPI_EPI_LANE_CTR1_MUX1_get_lane_ctr1_c6_mux_sel(data)                   ((0x00000FC0&(data))>>6)
#define  EPI_EPI_LANE_CTR1_MUX1_get_lane_ctr1_c5_mux_sel(data)                   (0x0000003F&(data))

#define  EPI_EPI_LANE_CTR1_MUX2                                                  0x180263B8
#define  EPI_EPI_LANE_CTR1_MUX2_reg_addr                                         "0xB80263B8"
#define  EPI_EPI_LANE_CTR1_MUX2_reg                                              0xB80263B8
#define  EPI_EPI_LANE_CTR1_MUX2_inst_addr                                        "0x0050"
#define  set_EPI_EPI_LANE_CTR1_MUX2_reg(data)                                    (*((volatile unsigned int*)EPI_EPI_LANE_CTR1_MUX2_reg)=data)
#define  get_EPI_EPI_LANE_CTR1_MUX2_reg                                          (*((volatile unsigned int*)EPI_EPI_LANE_CTR1_MUX2_reg))
#define  EPI_EPI_LANE_CTR1_MUX2_lane_ctr1_c14_mux_sel_shift                      (24)
#define  EPI_EPI_LANE_CTR1_MUX2_lane_ctr1_c13_mux_sel_shift                      (18)
#define  EPI_EPI_LANE_CTR1_MUX2_lane_ctr1_c12_mux_sel_shift                      (12)
#define  EPI_EPI_LANE_CTR1_MUX2_lane_ctr1_c11_mux_sel_shift                      (6)
#define  EPI_EPI_LANE_CTR1_MUX2_lane_ctr1_c10_mux_sel_shift                      (0)
#define  EPI_EPI_LANE_CTR1_MUX2_lane_ctr1_c14_mux_sel_mask                       (0x3F000000)
#define  EPI_EPI_LANE_CTR1_MUX2_lane_ctr1_c13_mux_sel_mask                       (0x00FC0000)
#define  EPI_EPI_LANE_CTR1_MUX2_lane_ctr1_c12_mux_sel_mask                       (0x0003F000)
#define  EPI_EPI_LANE_CTR1_MUX2_lane_ctr1_c11_mux_sel_mask                       (0x00000FC0)
#define  EPI_EPI_LANE_CTR1_MUX2_lane_ctr1_c10_mux_sel_mask                       (0x0000003F)
#define  EPI_EPI_LANE_CTR1_MUX2_lane_ctr1_c14_mux_sel(data)                      (0x3F000000&((data)<<24))
#define  EPI_EPI_LANE_CTR1_MUX2_lane_ctr1_c13_mux_sel(data)                      (0x00FC0000&((data)<<18))
#define  EPI_EPI_LANE_CTR1_MUX2_lane_ctr1_c12_mux_sel(data)                      (0x0003F000&((data)<<12))
#define  EPI_EPI_LANE_CTR1_MUX2_lane_ctr1_c11_mux_sel(data)                      (0x00000FC0&((data)<<6))
#define  EPI_EPI_LANE_CTR1_MUX2_lane_ctr1_c10_mux_sel(data)                      (0x0000003F&(data))
#define  EPI_EPI_LANE_CTR1_MUX2_get_lane_ctr1_c14_mux_sel(data)                  ((0x3F000000&(data))>>24)
#define  EPI_EPI_LANE_CTR1_MUX2_get_lane_ctr1_c13_mux_sel(data)                  ((0x00FC0000&(data))>>18)
#define  EPI_EPI_LANE_CTR1_MUX2_get_lane_ctr1_c12_mux_sel(data)                  ((0x0003F000&(data))>>12)
#define  EPI_EPI_LANE_CTR1_MUX2_get_lane_ctr1_c11_mux_sel(data)                  ((0x00000FC0&(data))>>6)
#define  EPI_EPI_LANE_CTR1_MUX2_get_lane_ctr1_c10_mux_sel(data)                  (0x0000003F&(data))

#define  EPI_EPI_LANE_CTR1_MUX3                                                  0x180263BC
#define  EPI_EPI_LANE_CTR1_MUX3_reg_addr                                         "0xB80263BC"
#define  EPI_EPI_LANE_CTR1_MUX3_reg                                              0xB80263BC
#define  EPI_EPI_LANE_CTR1_MUX3_inst_addr                                        "0x0051"
#define  set_EPI_EPI_LANE_CTR1_MUX3_reg(data)                                    (*((volatile unsigned int*)EPI_EPI_LANE_CTR1_MUX3_reg)=data)
#define  get_EPI_EPI_LANE_CTR1_MUX3_reg                                          (*((volatile unsigned int*)EPI_EPI_LANE_CTR1_MUX3_reg))
#define  EPI_EPI_LANE_CTR1_MUX3_lane_ctr1_c19_mux_sel_shift                      (24)
#define  EPI_EPI_LANE_CTR1_MUX3_lane_ctr1_c18_mux_sel_shift                      (18)
#define  EPI_EPI_LANE_CTR1_MUX3_lane_ctr1_c17_mux_sel_shift                      (12)
#define  EPI_EPI_LANE_CTR1_MUX3_lane_ctr1_c16_mux_sel_shift                      (6)
#define  EPI_EPI_LANE_CTR1_MUX3_lane_ctr1_c15_mux_sel_shift                      (0)
#define  EPI_EPI_LANE_CTR1_MUX3_lane_ctr1_c19_mux_sel_mask                       (0x3F000000)
#define  EPI_EPI_LANE_CTR1_MUX3_lane_ctr1_c18_mux_sel_mask                       (0x00FC0000)
#define  EPI_EPI_LANE_CTR1_MUX3_lane_ctr1_c17_mux_sel_mask                       (0x0003F000)
#define  EPI_EPI_LANE_CTR1_MUX3_lane_ctr1_c16_mux_sel_mask                       (0x00000FC0)
#define  EPI_EPI_LANE_CTR1_MUX3_lane_ctr1_c15_mux_sel_mask                       (0x0000003F)
#define  EPI_EPI_LANE_CTR1_MUX3_lane_ctr1_c19_mux_sel(data)                      (0x3F000000&((data)<<24))
#define  EPI_EPI_LANE_CTR1_MUX3_lane_ctr1_c18_mux_sel(data)                      (0x00FC0000&((data)<<18))
#define  EPI_EPI_LANE_CTR1_MUX3_lane_ctr1_c17_mux_sel(data)                      (0x0003F000&((data)<<12))
#define  EPI_EPI_LANE_CTR1_MUX3_lane_ctr1_c16_mux_sel(data)                      (0x00000FC0&((data)<<6))
#define  EPI_EPI_LANE_CTR1_MUX3_lane_ctr1_c15_mux_sel(data)                      (0x0000003F&(data))
#define  EPI_EPI_LANE_CTR1_MUX3_get_lane_ctr1_c19_mux_sel(data)                  ((0x3F000000&(data))>>24)
#define  EPI_EPI_LANE_CTR1_MUX3_get_lane_ctr1_c18_mux_sel(data)                  ((0x00FC0000&(data))>>18)
#define  EPI_EPI_LANE_CTR1_MUX3_get_lane_ctr1_c17_mux_sel(data)                  ((0x0003F000&(data))>>12)
#define  EPI_EPI_LANE_CTR1_MUX3_get_lane_ctr1_c16_mux_sel(data)                  ((0x00000FC0&(data))>>6)
#define  EPI_EPI_LANE_CTR1_MUX3_get_lane_ctr1_c15_mux_sel(data)                  (0x0000003F&(data))

#define  EPI_EPI_LANE_CTR1_MUX4                                                  0x180263C0
#define  EPI_EPI_LANE_CTR1_MUX4_reg_addr                                         "0xB80263C0"
#define  EPI_EPI_LANE_CTR1_MUX4_reg                                              0xB80263C0
#define  EPI_EPI_LANE_CTR1_MUX4_inst_addr                                        "0x0052"
#define  set_EPI_EPI_LANE_CTR1_MUX4_reg(data)                                    (*((volatile unsigned int*)EPI_EPI_LANE_CTR1_MUX4_reg)=data)
#define  get_EPI_EPI_LANE_CTR1_MUX4_reg                                          (*((volatile unsigned int*)EPI_EPI_LANE_CTR1_MUX4_reg))
#define  EPI_EPI_LANE_CTR1_MUX4_lane_ctr1_c24_mux_sel_shift                      (24)
#define  EPI_EPI_LANE_CTR1_MUX4_lane_ctr1_c23_mux_sel_shift                      (18)
#define  EPI_EPI_LANE_CTR1_MUX4_lane_ctr1_c22_mux_sel_shift                      (12)
#define  EPI_EPI_LANE_CTR1_MUX4_lane_ctr1_c21_mux_sel_shift                      (6)
#define  EPI_EPI_LANE_CTR1_MUX4_lane_ctr1_c20_mux_sel_shift                      (0)
#define  EPI_EPI_LANE_CTR1_MUX4_lane_ctr1_c24_mux_sel_mask                       (0x3F000000)
#define  EPI_EPI_LANE_CTR1_MUX4_lane_ctr1_c23_mux_sel_mask                       (0x00FC0000)
#define  EPI_EPI_LANE_CTR1_MUX4_lane_ctr1_c22_mux_sel_mask                       (0x0003F000)
#define  EPI_EPI_LANE_CTR1_MUX4_lane_ctr1_c21_mux_sel_mask                       (0x00000FC0)
#define  EPI_EPI_LANE_CTR1_MUX4_lane_ctr1_c20_mux_sel_mask                       (0x0000003F)
#define  EPI_EPI_LANE_CTR1_MUX4_lane_ctr1_c24_mux_sel(data)                      (0x3F000000&((data)<<24))
#define  EPI_EPI_LANE_CTR1_MUX4_lane_ctr1_c23_mux_sel(data)                      (0x00FC0000&((data)<<18))
#define  EPI_EPI_LANE_CTR1_MUX4_lane_ctr1_c22_mux_sel(data)                      (0x0003F000&((data)<<12))
#define  EPI_EPI_LANE_CTR1_MUX4_lane_ctr1_c21_mux_sel(data)                      (0x00000FC0&((data)<<6))
#define  EPI_EPI_LANE_CTR1_MUX4_lane_ctr1_c20_mux_sel(data)                      (0x0000003F&(data))
#define  EPI_EPI_LANE_CTR1_MUX4_get_lane_ctr1_c24_mux_sel(data)                  ((0x3F000000&(data))>>24)
#define  EPI_EPI_LANE_CTR1_MUX4_get_lane_ctr1_c23_mux_sel(data)                  ((0x00FC0000&(data))>>18)
#define  EPI_EPI_LANE_CTR1_MUX4_get_lane_ctr1_c22_mux_sel(data)                  ((0x0003F000&(data))>>12)
#define  EPI_EPI_LANE_CTR1_MUX4_get_lane_ctr1_c21_mux_sel(data)                  ((0x00000FC0&(data))>>6)
#define  EPI_EPI_LANE_CTR1_MUX4_get_lane_ctr1_c20_mux_sel(data)                  (0x0000003F&(data))

#define  EPI_EPI_LANE_CTR1_MUX5                                                  0x180263C4
#define  EPI_EPI_LANE_CTR1_MUX5_reg_addr                                         "0xB80263C4"
#define  EPI_EPI_LANE_CTR1_MUX5_reg                                              0xB80263C4
#define  EPI_EPI_LANE_CTR1_MUX5_inst_addr                                        "0x0053"
#define  set_EPI_EPI_LANE_CTR1_MUX5_reg(data)                                    (*((volatile unsigned int*)EPI_EPI_LANE_CTR1_MUX5_reg)=data)
#define  get_EPI_EPI_LANE_CTR1_MUX5_reg                                          (*((volatile unsigned int*)EPI_EPI_LANE_CTR1_MUX5_reg))
#define  EPI_EPI_LANE_CTR1_MUX5_lane_ctr1_c29_mux_sel_shift                      (24)
#define  EPI_EPI_LANE_CTR1_MUX5_lane_ctr1_c28_mux_sel_shift                      (18)
#define  EPI_EPI_LANE_CTR1_MUX5_lane_ctr1_c27_mux_sel_shift                      (12)
#define  EPI_EPI_LANE_CTR1_MUX5_lane_ctr1_c26_mux_sel_shift                      (6)
#define  EPI_EPI_LANE_CTR1_MUX5_lane_ctr1_c25_mux_sel_shift                      (0)
#define  EPI_EPI_LANE_CTR1_MUX5_lane_ctr1_c29_mux_sel_mask                       (0x3F000000)
#define  EPI_EPI_LANE_CTR1_MUX5_lane_ctr1_c28_mux_sel_mask                       (0x00FC0000)
#define  EPI_EPI_LANE_CTR1_MUX5_lane_ctr1_c27_mux_sel_mask                       (0x0003F000)
#define  EPI_EPI_LANE_CTR1_MUX5_lane_ctr1_c26_mux_sel_mask                       (0x00000FC0)
#define  EPI_EPI_LANE_CTR1_MUX5_lane_ctr1_c25_mux_sel_mask                       (0x0000003F)
#define  EPI_EPI_LANE_CTR1_MUX5_lane_ctr1_c29_mux_sel(data)                      (0x3F000000&((data)<<24))
#define  EPI_EPI_LANE_CTR1_MUX5_lane_ctr1_c28_mux_sel(data)                      (0x00FC0000&((data)<<18))
#define  EPI_EPI_LANE_CTR1_MUX5_lane_ctr1_c27_mux_sel(data)                      (0x0003F000&((data)<<12))
#define  EPI_EPI_LANE_CTR1_MUX5_lane_ctr1_c26_mux_sel(data)                      (0x00000FC0&((data)<<6))
#define  EPI_EPI_LANE_CTR1_MUX5_lane_ctr1_c25_mux_sel(data)                      (0x0000003F&(data))
#define  EPI_EPI_LANE_CTR1_MUX5_get_lane_ctr1_c29_mux_sel(data)                  ((0x3F000000&(data))>>24)
#define  EPI_EPI_LANE_CTR1_MUX5_get_lane_ctr1_c28_mux_sel(data)                  ((0x00FC0000&(data))>>18)
#define  EPI_EPI_LANE_CTR1_MUX5_get_lane_ctr1_c27_mux_sel(data)                  ((0x0003F000&(data))>>12)
#define  EPI_EPI_LANE_CTR1_MUX5_get_lane_ctr1_c26_mux_sel(data)                  ((0x00000FC0&(data))>>6)
#define  EPI_EPI_LANE_CTR1_MUX5_get_lane_ctr1_c25_mux_sel(data)                  (0x0000003F&(data))

#define  EPI_EPI_LANE_CTR2_MUX0                                                  0x180263C8
#define  EPI_EPI_LANE_CTR2_MUX0_reg_addr                                         "0xB80263C8"
#define  EPI_EPI_LANE_CTR2_MUX0_reg                                              0xB80263C8
#define  EPI_EPI_LANE_CTR2_MUX0_inst_addr                                        "0x0054"
#define  set_EPI_EPI_LANE_CTR2_MUX0_reg(data)                                    (*((volatile unsigned int*)EPI_EPI_LANE_CTR2_MUX0_reg)=data)
#define  get_EPI_EPI_LANE_CTR2_MUX0_reg                                          (*((volatile unsigned int*)EPI_EPI_LANE_CTR2_MUX0_reg))
#define  EPI_EPI_LANE_CTR2_MUX0_lane_ctr2_c4_mux_sel_shift                       (24)
#define  EPI_EPI_LANE_CTR2_MUX0_lane_ctr2_c3_mux_sel_shift                       (18)
#define  EPI_EPI_LANE_CTR2_MUX0_lane_ctr2_c2_mux_sel_shift                       (12)
#define  EPI_EPI_LANE_CTR2_MUX0_lane_ctr2_c1_mux_sel_shift                       (6)
#define  EPI_EPI_LANE_CTR2_MUX0_lane_ctr2_c0_mux_sel_shift                       (0)
#define  EPI_EPI_LANE_CTR2_MUX0_lane_ctr2_c4_mux_sel_mask                        (0x3F000000)
#define  EPI_EPI_LANE_CTR2_MUX0_lane_ctr2_c3_mux_sel_mask                        (0x00FC0000)
#define  EPI_EPI_LANE_CTR2_MUX0_lane_ctr2_c2_mux_sel_mask                        (0x0003F000)
#define  EPI_EPI_LANE_CTR2_MUX0_lane_ctr2_c1_mux_sel_mask                        (0x00000FC0)
#define  EPI_EPI_LANE_CTR2_MUX0_lane_ctr2_c0_mux_sel_mask                        (0x0000003F)
#define  EPI_EPI_LANE_CTR2_MUX0_lane_ctr2_c4_mux_sel(data)                       (0x3F000000&((data)<<24))
#define  EPI_EPI_LANE_CTR2_MUX0_lane_ctr2_c3_mux_sel(data)                       (0x00FC0000&((data)<<18))
#define  EPI_EPI_LANE_CTR2_MUX0_lane_ctr2_c2_mux_sel(data)                       (0x0003F000&((data)<<12))
#define  EPI_EPI_LANE_CTR2_MUX0_lane_ctr2_c1_mux_sel(data)                       (0x00000FC0&((data)<<6))
#define  EPI_EPI_LANE_CTR2_MUX0_lane_ctr2_c0_mux_sel(data)                       (0x0000003F&(data))
#define  EPI_EPI_LANE_CTR2_MUX0_get_lane_ctr2_c4_mux_sel(data)                   ((0x3F000000&(data))>>24)
#define  EPI_EPI_LANE_CTR2_MUX0_get_lane_ctr2_c3_mux_sel(data)                   ((0x00FC0000&(data))>>18)
#define  EPI_EPI_LANE_CTR2_MUX0_get_lane_ctr2_c2_mux_sel(data)                   ((0x0003F000&(data))>>12)
#define  EPI_EPI_LANE_CTR2_MUX0_get_lane_ctr2_c1_mux_sel(data)                   ((0x00000FC0&(data))>>6)
#define  EPI_EPI_LANE_CTR2_MUX0_get_lane_ctr2_c0_mux_sel(data)                   (0x0000003F&(data))

#define  EPI_EPI_LANE_CTR2_MUX1                                                  0x180263CC
#define  EPI_EPI_LANE_CTR2_MUX1_reg_addr                                         "0xB80263CC"
#define  EPI_EPI_LANE_CTR2_MUX1_reg                                              0xB80263CC
#define  EPI_EPI_LANE_CTR2_MUX1_inst_addr                                        "0x0055"
#define  set_EPI_EPI_LANE_CTR2_MUX1_reg(data)                                    (*((volatile unsigned int*)EPI_EPI_LANE_CTR2_MUX1_reg)=data)
#define  get_EPI_EPI_LANE_CTR2_MUX1_reg                                          (*((volatile unsigned int*)EPI_EPI_LANE_CTR2_MUX1_reg))
#define  EPI_EPI_LANE_CTR2_MUX1_lane_ctr2_c9_mux_sel_shift                       (24)
#define  EPI_EPI_LANE_CTR2_MUX1_lane_ctr2_c8_mux_sel_shift                       (18)
#define  EPI_EPI_LANE_CTR2_MUX1_lane_ctr2_c7_mux_sel_shift                       (12)
#define  EPI_EPI_LANE_CTR2_MUX1_lane_ctr2_c6_mux_sel_shift                       (6)
#define  EPI_EPI_LANE_CTR2_MUX1_lane_ctr2_c5_mux_sel_shift                       (0)
#define  EPI_EPI_LANE_CTR2_MUX1_lane_ctr2_c9_mux_sel_mask                        (0x3F000000)
#define  EPI_EPI_LANE_CTR2_MUX1_lane_ctr2_c8_mux_sel_mask                        (0x00FC0000)
#define  EPI_EPI_LANE_CTR2_MUX1_lane_ctr2_c7_mux_sel_mask                        (0x0003F000)
#define  EPI_EPI_LANE_CTR2_MUX1_lane_ctr2_c6_mux_sel_mask                        (0x00000FC0)
#define  EPI_EPI_LANE_CTR2_MUX1_lane_ctr2_c5_mux_sel_mask                        (0x0000003F)
#define  EPI_EPI_LANE_CTR2_MUX1_lane_ctr2_c9_mux_sel(data)                       (0x3F000000&((data)<<24))
#define  EPI_EPI_LANE_CTR2_MUX1_lane_ctr2_c8_mux_sel(data)                       (0x00FC0000&((data)<<18))
#define  EPI_EPI_LANE_CTR2_MUX1_lane_ctr2_c7_mux_sel(data)                       (0x0003F000&((data)<<12))
#define  EPI_EPI_LANE_CTR2_MUX1_lane_ctr2_c6_mux_sel(data)                       (0x00000FC0&((data)<<6))
#define  EPI_EPI_LANE_CTR2_MUX1_lane_ctr2_c5_mux_sel(data)                       (0x0000003F&(data))
#define  EPI_EPI_LANE_CTR2_MUX1_get_lane_ctr2_c9_mux_sel(data)                   ((0x3F000000&(data))>>24)
#define  EPI_EPI_LANE_CTR2_MUX1_get_lane_ctr2_c8_mux_sel(data)                   ((0x00FC0000&(data))>>18)
#define  EPI_EPI_LANE_CTR2_MUX1_get_lane_ctr2_c7_mux_sel(data)                   ((0x0003F000&(data))>>12)
#define  EPI_EPI_LANE_CTR2_MUX1_get_lane_ctr2_c6_mux_sel(data)                   ((0x00000FC0&(data))>>6)
#define  EPI_EPI_LANE_CTR2_MUX1_get_lane_ctr2_c5_mux_sel(data)                   (0x0000003F&(data))

#define  EPI_EPI_LANE_CTR2_MUX2                                                  0x180263D0
#define  EPI_EPI_LANE_CTR2_MUX2_reg_addr                                         "0xB80263D0"
#define  EPI_EPI_LANE_CTR2_MUX2_reg                                              0xB80263D0
#define  EPI_EPI_LANE_CTR2_MUX2_inst_addr                                        "0x0056"
#define  set_EPI_EPI_LANE_CTR2_MUX2_reg(data)                                    (*((volatile unsigned int*)EPI_EPI_LANE_CTR2_MUX2_reg)=data)
#define  get_EPI_EPI_LANE_CTR2_MUX2_reg                                          (*((volatile unsigned int*)EPI_EPI_LANE_CTR2_MUX2_reg))
#define  EPI_EPI_LANE_CTR2_MUX2_lane_ctr2_c14_mux_sel_shift                      (24)
#define  EPI_EPI_LANE_CTR2_MUX2_lane_ctr2_c13_mux_sel_shift                      (18)
#define  EPI_EPI_LANE_CTR2_MUX2_lane_ctr2_c12_mux_sel_shift                      (12)
#define  EPI_EPI_LANE_CTR2_MUX2_lane_ctr2_c11_mux_sel_shift                      (6)
#define  EPI_EPI_LANE_CTR2_MUX2_lane_ctr2_c10_mux_sel_shift                      (0)
#define  EPI_EPI_LANE_CTR2_MUX2_lane_ctr2_c14_mux_sel_mask                       (0x3F000000)
#define  EPI_EPI_LANE_CTR2_MUX2_lane_ctr2_c13_mux_sel_mask                       (0x00FC0000)
#define  EPI_EPI_LANE_CTR2_MUX2_lane_ctr2_c12_mux_sel_mask                       (0x0003F000)
#define  EPI_EPI_LANE_CTR2_MUX2_lane_ctr2_c11_mux_sel_mask                       (0x00000FC0)
#define  EPI_EPI_LANE_CTR2_MUX2_lane_ctr2_c10_mux_sel_mask                       (0x0000003F)
#define  EPI_EPI_LANE_CTR2_MUX2_lane_ctr2_c14_mux_sel(data)                      (0x3F000000&((data)<<24))
#define  EPI_EPI_LANE_CTR2_MUX2_lane_ctr2_c13_mux_sel(data)                      (0x00FC0000&((data)<<18))
#define  EPI_EPI_LANE_CTR2_MUX2_lane_ctr2_c12_mux_sel(data)                      (0x0003F000&((data)<<12))
#define  EPI_EPI_LANE_CTR2_MUX2_lane_ctr2_c11_mux_sel(data)                      (0x00000FC0&((data)<<6))
#define  EPI_EPI_LANE_CTR2_MUX2_lane_ctr2_c10_mux_sel(data)                      (0x0000003F&(data))
#define  EPI_EPI_LANE_CTR2_MUX2_get_lane_ctr2_c14_mux_sel(data)                  ((0x3F000000&(data))>>24)
#define  EPI_EPI_LANE_CTR2_MUX2_get_lane_ctr2_c13_mux_sel(data)                  ((0x00FC0000&(data))>>18)
#define  EPI_EPI_LANE_CTR2_MUX2_get_lane_ctr2_c12_mux_sel(data)                  ((0x0003F000&(data))>>12)
#define  EPI_EPI_LANE_CTR2_MUX2_get_lane_ctr2_c11_mux_sel(data)                  ((0x00000FC0&(data))>>6)
#define  EPI_EPI_LANE_CTR2_MUX2_get_lane_ctr2_c10_mux_sel(data)                  (0x0000003F&(data))

#define  EPI_EPI_LANE_CTR2_MUX3                                                  0x180263D4
#define  EPI_EPI_LANE_CTR2_MUX3_reg_addr                                         "0xB80263D4"
#define  EPI_EPI_LANE_CTR2_MUX3_reg                                              0xB80263D4
#define  EPI_EPI_LANE_CTR2_MUX3_inst_addr                                        "0x0057"
#define  set_EPI_EPI_LANE_CTR2_MUX3_reg(data)                                    (*((volatile unsigned int*)EPI_EPI_LANE_CTR2_MUX3_reg)=data)
#define  get_EPI_EPI_LANE_CTR2_MUX3_reg                                          (*((volatile unsigned int*)EPI_EPI_LANE_CTR2_MUX3_reg))
#define  EPI_EPI_LANE_CTR2_MUX3_lane_ctr2_c19_mux_sel_shift                      (24)
#define  EPI_EPI_LANE_CTR2_MUX3_lane_ctr2_c18_mux_sel_shift                      (18)
#define  EPI_EPI_LANE_CTR2_MUX3_lane_ctr2_c17_mux_sel_shift                      (12)
#define  EPI_EPI_LANE_CTR2_MUX3_lane_ctr2_c16_mux_sel_shift                      (6)
#define  EPI_EPI_LANE_CTR2_MUX3_lane_ctr2_c15_mux_sel_shift                      (0)
#define  EPI_EPI_LANE_CTR2_MUX3_lane_ctr2_c19_mux_sel_mask                       (0x3F000000)
#define  EPI_EPI_LANE_CTR2_MUX3_lane_ctr2_c18_mux_sel_mask                       (0x00FC0000)
#define  EPI_EPI_LANE_CTR2_MUX3_lane_ctr2_c17_mux_sel_mask                       (0x0003F000)
#define  EPI_EPI_LANE_CTR2_MUX3_lane_ctr2_c16_mux_sel_mask                       (0x00000FC0)
#define  EPI_EPI_LANE_CTR2_MUX3_lane_ctr2_c15_mux_sel_mask                       (0x0000003F)
#define  EPI_EPI_LANE_CTR2_MUX3_lane_ctr2_c19_mux_sel(data)                      (0x3F000000&((data)<<24))
#define  EPI_EPI_LANE_CTR2_MUX3_lane_ctr2_c18_mux_sel(data)                      (0x00FC0000&((data)<<18))
#define  EPI_EPI_LANE_CTR2_MUX3_lane_ctr2_c17_mux_sel(data)                      (0x0003F000&((data)<<12))
#define  EPI_EPI_LANE_CTR2_MUX3_lane_ctr2_c16_mux_sel(data)                      (0x00000FC0&((data)<<6))
#define  EPI_EPI_LANE_CTR2_MUX3_lane_ctr2_c15_mux_sel(data)                      (0x0000003F&(data))
#define  EPI_EPI_LANE_CTR2_MUX3_get_lane_ctr2_c19_mux_sel(data)                  ((0x3F000000&(data))>>24)
#define  EPI_EPI_LANE_CTR2_MUX3_get_lane_ctr2_c18_mux_sel(data)                  ((0x00FC0000&(data))>>18)
#define  EPI_EPI_LANE_CTR2_MUX3_get_lane_ctr2_c17_mux_sel(data)                  ((0x0003F000&(data))>>12)
#define  EPI_EPI_LANE_CTR2_MUX3_get_lane_ctr2_c16_mux_sel(data)                  ((0x00000FC0&(data))>>6)
#define  EPI_EPI_LANE_CTR2_MUX3_get_lane_ctr2_c15_mux_sel(data)                  (0x0000003F&(data))

#define  EPI_EPI_LANE_CTR2_MUX4                                                  0x180263D8
#define  EPI_EPI_LANE_CTR2_MUX4_reg_addr                                         "0xB80263D8"
#define  EPI_EPI_LANE_CTR2_MUX4_reg                                              0xB80263D8
#define  EPI_EPI_LANE_CTR2_MUX4_inst_addr                                        "0x0058"
#define  set_EPI_EPI_LANE_CTR2_MUX4_reg(data)                                    (*((volatile unsigned int*)EPI_EPI_LANE_CTR2_MUX4_reg)=data)
#define  get_EPI_EPI_LANE_CTR2_MUX4_reg                                          (*((volatile unsigned int*)EPI_EPI_LANE_CTR2_MUX4_reg))
#define  EPI_EPI_LANE_CTR2_MUX4_lane_ctr2_c24_mux_sel_shift                      (24)
#define  EPI_EPI_LANE_CTR2_MUX4_lane_ctr2_c23_mux_sel_shift                      (18)
#define  EPI_EPI_LANE_CTR2_MUX4_lane_ctr2_c22_mux_sel_shift                      (12)
#define  EPI_EPI_LANE_CTR2_MUX4_lane_ctr2_c21_mux_sel_shift                      (6)
#define  EPI_EPI_LANE_CTR2_MUX4_lane_ctr2_c20_mux_sel_shift                      (0)
#define  EPI_EPI_LANE_CTR2_MUX4_lane_ctr2_c24_mux_sel_mask                       (0x3F000000)
#define  EPI_EPI_LANE_CTR2_MUX4_lane_ctr2_c23_mux_sel_mask                       (0x00FC0000)
#define  EPI_EPI_LANE_CTR2_MUX4_lane_ctr2_c22_mux_sel_mask                       (0x0003F000)
#define  EPI_EPI_LANE_CTR2_MUX4_lane_ctr2_c21_mux_sel_mask                       (0x00000FC0)
#define  EPI_EPI_LANE_CTR2_MUX4_lane_ctr2_c20_mux_sel_mask                       (0x0000003F)
#define  EPI_EPI_LANE_CTR2_MUX4_lane_ctr2_c24_mux_sel(data)                      (0x3F000000&((data)<<24))
#define  EPI_EPI_LANE_CTR2_MUX4_lane_ctr2_c23_mux_sel(data)                      (0x00FC0000&((data)<<18))
#define  EPI_EPI_LANE_CTR2_MUX4_lane_ctr2_c22_mux_sel(data)                      (0x0003F000&((data)<<12))
#define  EPI_EPI_LANE_CTR2_MUX4_lane_ctr2_c21_mux_sel(data)                      (0x00000FC0&((data)<<6))
#define  EPI_EPI_LANE_CTR2_MUX4_lane_ctr2_c20_mux_sel(data)                      (0x0000003F&(data))
#define  EPI_EPI_LANE_CTR2_MUX4_get_lane_ctr2_c24_mux_sel(data)                  ((0x3F000000&(data))>>24)
#define  EPI_EPI_LANE_CTR2_MUX4_get_lane_ctr2_c23_mux_sel(data)                  ((0x00FC0000&(data))>>18)
#define  EPI_EPI_LANE_CTR2_MUX4_get_lane_ctr2_c22_mux_sel(data)                  ((0x0003F000&(data))>>12)
#define  EPI_EPI_LANE_CTR2_MUX4_get_lane_ctr2_c21_mux_sel(data)                  ((0x00000FC0&(data))>>6)
#define  EPI_EPI_LANE_CTR2_MUX4_get_lane_ctr2_c20_mux_sel(data)                  (0x0000003F&(data))

#define  EPI_EPI_LANE_CTR2_MUX5                                                  0x180263DC
#define  EPI_EPI_LANE_CTR2_MUX5_reg_addr                                         "0xB80263DC"
#define  EPI_EPI_LANE_CTR2_MUX5_reg                                              0xB80263DC
#define  EPI_EPI_LANE_CTR2_MUX5_inst_addr                                        "0x0059"
#define  set_EPI_EPI_LANE_CTR2_MUX5_reg(data)                                    (*((volatile unsigned int*)EPI_EPI_LANE_CTR2_MUX5_reg)=data)
#define  get_EPI_EPI_LANE_CTR2_MUX5_reg                                          (*((volatile unsigned int*)EPI_EPI_LANE_CTR2_MUX5_reg))
#define  EPI_EPI_LANE_CTR2_MUX5_lane_ctr2_c29_mux_sel_shift                      (24)
#define  EPI_EPI_LANE_CTR2_MUX5_lane_ctr2_c28_mux_sel_shift                      (18)
#define  EPI_EPI_LANE_CTR2_MUX5_lane_ctr2_c27_mux_sel_shift                      (12)
#define  EPI_EPI_LANE_CTR2_MUX5_lane_ctr2_c26_mux_sel_shift                      (6)
#define  EPI_EPI_LANE_CTR2_MUX5_lane_ctr2_c25_mux_sel_shift                      (0)
#define  EPI_EPI_LANE_CTR2_MUX5_lane_ctr2_c29_mux_sel_mask                       (0x3F000000)
#define  EPI_EPI_LANE_CTR2_MUX5_lane_ctr2_c28_mux_sel_mask                       (0x00FC0000)
#define  EPI_EPI_LANE_CTR2_MUX5_lane_ctr2_c27_mux_sel_mask                       (0x0003F000)
#define  EPI_EPI_LANE_CTR2_MUX5_lane_ctr2_c26_mux_sel_mask                       (0x00000FC0)
#define  EPI_EPI_LANE_CTR2_MUX5_lane_ctr2_c25_mux_sel_mask                       (0x0000003F)
#define  EPI_EPI_LANE_CTR2_MUX5_lane_ctr2_c29_mux_sel(data)                      (0x3F000000&((data)<<24))
#define  EPI_EPI_LANE_CTR2_MUX5_lane_ctr2_c28_mux_sel(data)                      (0x00FC0000&((data)<<18))
#define  EPI_EPI_LANE_CTR2_MUX5_lane_ctr2_c27_mux_sel(data)                      (0x0003F000&((data)<<12))
#define  EPI_EPI_LANE_CTR2_MUX5_lane_ctr2_c26_mux_sel(data)                      (0x00000FC0&((data)<<6))
#define  EPI_EPI_LANE_CTR2_MUX5_lane_ctr2_c25_mux_sel(data)                      (0x0000003F&(data))
#define  EPI_EPI_LANE_CTR2_MUX5_get_lane_ctr2_c29_mux_sel(data)                  ((0x3F000000&(data))>>24)
#define  EPI_EPI_LANE_CTR2_MUX5_get_lane_ctr2_c28_mux_sel(data)                  ((0x00FC0000&(data))>>18)
#define  EPI_EPI_LANE_CTR2_MUX5_get_lane_ctr2_c27_mux_sel(data)                  ((0x0003F000&(data))>>12)
#define  EPI_EPI_LANE_CTR2_MUX5_get_lane_ctr2_c26_mux_sel(data)                  ((0x00000FC0&(data))>>6)
#define  EPI_EPI_LANE_CTR2_MUX5_get_lane_ctr2_c25_mux_sel(data)                  (0x0000003F&(data))

#define  EPI_EPI_LANE_CTR3_MUX0                                                  0x180263E0
#define  EPI_EPI_LANE_CTR3_MUX0_reg_addr                                         "0xB80263E0"
#define  EPI_EPI_LANE_CTR3_MUX0_reg                                              0xB80263E0
#define  EPI_EPI_LANE_CTR3_MUX0_inst_addr                                        "0x005A"
#define  set_EPI_EPI_LANE_CTR3_MUX0_reg(data)                                    (*((volatile unsigned int*)EPI_EPI_LANE_CTR3_MUX0_reg)=data)
#define  get_EPI_EPI_LANE_CTR3_MUX0_reg                                          (*((volatile unsigned int*)EPI_EPI_LANE_CTR3_MUX0_reg))
#define  EPI_EPI_LANE_CTR3_MUX0_lane_ctr3_c4_mux_sel_shift                       (24)
#define  EPI_EPI_LANE_CTR3_MUX0_lane_ctr3_c3_mux_sel_shift                       (18)
#define  EPI_EPI_LANE_CTR3_MUX0_lane_ctr3_c2_mux_sel_shift                       (12)
#define  EPI_EPI_LANE_CTR3_MUX0_lane_ctr3_c1_mux_sel_shift                       (6)
#define  EPI_EPI_LANE_CTR3_MUX0_lane_ctr3_c0_mux_sel_shift                       (0)
#define  EPI_EPI_LANE_CTR3_MUX0_lane_ctr3_c4_mux_sel_mask                        (0x3F000000)
#define  EPI_EPI_LANE_CTR3_MUX0_lane_ctr3_c3_mux_sel_mask                        (0x00FC0000)
#define  EPI_EPI_LANE_CTR3_MUX0_lane_ctr3_c2_mux_sel_mask                        (0x0003F000)
#define  EPI_EPI_LANE_CTR3_MUX0_lane_ctr3_c1_mux_sel_mask                        (0x00000FC0)
#define  EPI_EPI_LANE_CTR3_MUX0_lane_ctr3_c0_mux_sel_mask                        (0x0000003F)
#define  EPI_EPI_LANE_CTR3_MUX0_lane_ctr3_c4_mux_sel(data)                       (0x3F000000&((data)<<24))
#define  EPI_EPI_LANE_CTR3_MUX0_lane_ctr3_c3_mux_sel(data)                       (0x00FC0000&((data)<<18))
#define  EPI_EPI_LANE_CTR3_MUX0_lane_ctr3_c2_mux_sel(data)                       (0x0003F000&((data)<<12))
#define  EPI_EPI_LANE_CTR3_MUX0_lane_ctr3_c1_mux_sel(data)                       (0x00000FC0&((data)<<6))
#define  EPI_EPI_LANE_CTR3_MUX0_lane_ctr3_c0_mux_sel(data)                       (0x0000003F&(data))
#define  EPI_EPI_LANE_CTR3_MUX0_get_lane_ctr3_c4_mux_sel(data)                   ((0x3F000000&(data))>>24)
#define  EPI_EPI_LANE_CTR3_MUX0_get_lane_ctr3_c3_mux_sel(data)                   ((0x00FC0000&(data))>>18)
#define  EPI_EPI_LANE_CTR3_MUX0_get_lane_ctr3_c2_mux_sel(data)                   ((0x0003F000&(data))>>12)
#define  EPI_EPI_LANE_CTR3_MUX0_get_lane_ctr3_c1_mux_sel(data)                   ((0x00000FC0&(data))>>6)
#define  EPI_EPI_LANE_CTR3_MUX0_get_lane_ctr3_c0_mux_sel(data)                   (0x0000003F&(data))

#define  EPI_EPI_LANE_CTR3_MUX1                                                  0x180263E4
#define  EPI_EPI_LANE_CTR3_MUX1_reg_addr                                         "0xB80263E4"
#define  EPI_EPI_LANE_CTR3_MUX1_reg                                              0xB80263E4
#define  EPI_EPI_LANE_CTR3_MUX1_inst_addr                                        "0x005B"
#define  set_EPI_EPI_LANE_CTR3_MUX1_reg(data)                                    (*((volatile unsigned int*)EPI_EPI_LANE_CTR3_MUX1_reg)=data)
#define  get_EPI_EPI_LANE_CTR3_MUX1_reg                                          (*((volatile unsigned int*)EPI_EPI_LANE_CTR3_MUX1_reg))
#define  EPI_EPI_LANE_CTR3_MUX1_lane_ctr3_c9_mux_sel_shift                       (24)
#define  EPI_EPI_LANE_CTR3_MUX1_lane_ctr3_c8_mux_sel_shift                       (18)
#define  EPI_EPI_LANE_CTR3_MUX1_lane_ctr3_c7_mux_sel_shift                       (12)
#define  EPI_EPI_LANE_CTR3_MUX1_lane_ctr3_c6_mux_sel_shift                       (6)
#define  EPI_EPI_LANE_CTR3_MUX1_lane_ctr3_c5_mux_sel_shift                       (0)
#define  EPI_EPI_LANE_CTR3_MUX1_lane_ctr3_c9_mux_sel_mask                        (0x3F000000)
#define  EPI_EPI_LANE_CTR3_MUX1_lane_ctr3_c8_mux_sel_mask                        (0x00FC0000)
#define  EPI_EPI_LANE_CTR3_MUX1_lane_ctr3_c7_mux_sel_mask                        (0x0003F000)
#define  EPI_EPI_LANE_CTR3_MUX1_lane_ctr3_c6_mux_sel_mask                        (0x00000FC0)
#define  EPI_EPI_LANE_CTR3_MUX1_lane_ctr3_c5_mux_sel_mask                        (0x0000003F)
#define  EPI_EPI_LANE_CTR3_MUX1_lane_ctr3_c9_mux_sel(data)                       (0x3F000000&((data)<<24))
#define  EPI_EPI_LANE_CTR3_MUX1_lane_ctr3_c8_mux_sel(data)                       (0x00FC0000&((data)<<18))
#define  EPI_EPI_LANE_CTR3_MUX1_lane_ctr3_c7_mux_sel(data)                       (0x0003F000&((data)<<12))
#define  EPI_EPI_LANE_CTR3_MUX1_lane_ctr3_c6_mux_sel(data)                       (0x00000FC0&((data)<<6))
#define  EPI_EPI_LANE_CTR3_MUX1_lane_ctr3_c5_mux_sel(data)                       (0x0000003F&(data))
#define  EPI_EPI_LANE_CTR3_MUX1_get_lane_ctr3_c9_mux_sel(data)                   ((0x3F000000&(data))>>24)
#define  EPI_EPI_LANE_CTR3_MUX1_get_lane_ctr3_c8_mux_sel(data)                   ((0x00FC0000&(data))>>18)
#define  EPI_EPI_LANE_CTR3_MUX1_get_lane_ctr3_c7_mux_sel(data)                   ((0x0003F000&(data))>>12)
#define  EPI_EPI_LANE_CTR3_MUX1_get_lane_ctr3_c6_mux_sel(data)                   ((0x00000FC0&(data))>>6)
#define  EPI_EPI_LANE_CTR3_MUX1_get_lane_ctr3_c5_mux_sel(data)                   (0x0000003F&(data))

#define  EPI_EPI_LANE_CTR3_MUX2                                                  0x180263E8
#define  EPI_EPI_LANE_CTR3_MUX2_reg_addr                                         "0xB80263E8"
#define  EPI_EPI_LANE_CTR3_MUX2_reg                                              0xB80263E8
#define  EPI_EPI_LANE_CTR3_MUX2_inst_addr                                        "0x005C"
#define  set_EPI_EPI_LANE_CTR3_MUX2_reg(data)                                    (*((volatile unsigned int*)EPI_EPI_LANE_CTR3_MUX2_reg)=data)
#define  get_EPI_EPI_LANE_CTR3_MUX2_reg                                          (*((volatile unsigned int*)EPI_EPI_LANE_CTR3_MUX2_reg))
#define  EPI_EPI_LANE_CTR3_MUX2_lane_ctr3_c14_mux_sel_shift                      (24)
#define  EPI_EPI_LANE_CTR3_MUX2_lane_ctr3_c13_mux_sel_shift                      (18)
#define  EPI_EPI_LANE_CTR3_MUX2_lane_ctr3_c12_mux_sel_shift                      (12)
#define  EPI_EPI_LANE_CTR3_MUX2_lane_ctr3_c11_mux_sel_shift                      (6)
#define  EPI_EPI_LANE_CTR3_MUX2_lane_ctr3_c10_mux_sel_shift                      (0)
#define  EPI_EPI_LANE_CTR3_MUX2_lane_ctr3_c14_mux_sel_mask                       (0x3F000000)
#define  EPI_EPI_LANE_CTR3_MUX2_lane_ctr3_c13_mux_sel_mask                       (0x00FC0000)
#define  EPI_EPI_LANE_CTR3_MUX2_lane_ctr3_c12_mux_sel_mask                       (0x0003F000)
#define  EPI_EPI_LANE_CTR3_MUX2_lane_ctr3_c11_mux_sel_mask                       (0x00000FC0)
#define  EPI_EPI_LANE_CTR3_MUX2_lane_ctr3_c10_mux_sel_mask                       (0x0000003F)
#define  EPI_EPI_LANE_CTR3_MUX2_lane_ctr3_c14_mux_sel(data)                      (0x3F000000&((data)<<24))
#define  EPI_EPI_LANE_CTR3_MUX2_lane_ctr3_c13_mux_sel(data)                      (0x00FC0000&((data)<<18))
#define  EPI_EPI_LANE_CTR3_MUX2_lane_ctr3_c12_mux_sel(data)                      (0x0003F000&((data)<<12))
#define  EPI_EPI_LANE_CTR3_MUX2_lane_ctr3_c11_mux_sel(data)                      (0x00000FC0&((data)<<6))
#define  EPI_EPI_LANE_CTR3_MUX2_lane_ctr3_c10_mux_sel(data)                      (0x0000003F&(data))
#define  EPI_EPI_LANE_CTR3_MUX2_get_lane_ctr3_c14_mux_sel(data)                  ((0x3F000000&(data))>>24)
#define  EPI_EPI_LANE_CTR3_MUX2_get_lane_ctr3_c13_mux_sel(data)                  ((0x00FC0000&(data))>>18)
#define  EPI_EPI_LANE_CTR3_MUX2_get_lane_ctr3_c12_mux_sel(data)                  ((0x0003F000&(data))>>12)
#define  EPI_EPI_LANE_CTR3_MUX2_get_lane_ctr3_c11_mux_sel(data)                  ((0x00000FC0&(data))>>6)
#define  EPI_EPI_LANE_CTR3_MUX2_get_lane_ctr3_c10_mux_sel(data)                  (0x0000003F&(data))

#define  EPI_EPI_LANE_CTR3_MUX3                                                  0x180263EC
#define  EPI_EPI_LANE_CTR3_MUX3_reg_addr                                         "0xB80263EC"
#define  EPI_EPI_LANE_CTR3_MUX3_reg                                              0xB80263EC
#define  EPI_EPI_LANE_CTR3_MUX3_inst_addr                                        "0x005D"
#define  set_EPI_EPI_LANE_CTR3_MUX3_reg(data)                                    (*((volatile unsigned int*)EPI_EPI_LANE_CTR3_MUX3_reg)=data)
#define  get_EPI_EPI_LANE_CTR3_MUX3_reg                                          (*((volatile unsigned int*)EPI_EPI_LANE_CTR3_MUX3_reg))
#define  EPI_EPI_LANE_CTR3_MUX3_lane_ctr3_c19_mux_sel_shift                      (24)
#define  EPI_EPI_LANE_CTR3_MUX3_lane_ctr3_c18_mux_sel_shift                      (18)
#define  EPI_EPI_LANE_CTR3_MUX3_lane_ctr3_c17_mux_sel_shift                      (12)
#define  EPI_EPI_LANE_CTR3_MUX3_lane_ctr3_c16_mux_sel_shift                      (6)
#define  EPI_EPI_LANE_CTR3_MUX3_lane_ctr3_c15_mux_sel_shift                      (0)
#define  EPI_EPI_LANE_CTR3_MUX3_lane_ctr3_c19_mux_sel_mask                       (0x3F000000)
#define  EPI_EPI_LANE_CTR3_MUX3_lane_ctr3_c18_mux_sel_mask                       (0x00FC0000)
#define  EPI_EPI_LANE_CTR3_MUX3_lane_ctr3_c17_mux_sel_mask                       (0x0003F000)
#define  EPI_EPI_LANE_CTR3_MUX3_lane_ctr3_c16_mux_sel_mask                       (0x00000FC0)
#define  EPI_EPI_LANE_CTR3_MUX3_lane_ctr3_c15_mux_sel_mask                       (0x0000003F)
#define  EPI_EPI_LANE_CTR3_MUX3_lane_ctr3_c19_mux_sel(data)                      (0x3F000000&((data)<<24))
#define  EPI_EPI_LANE_CTR3_MUX3_lane_ctr3_c18_mux_sel(data)                      (0x00FC0000&((data)<<18))
#define  EPI_EPI_LANE_CTR3_MUX3_lane_ctr3_c17_mux_sel(data)                      (0x0003F000&((data)<<12))
#define  EPI_EPI_LANE_CTR3_MUX3_lane_ctr3_c16_mux_sel(data)                      (0x00000FC0&((data)<<6))
#define  EPI_EPI_LANE_CTR3_MUX3_lane_ctr3_c15_mux_sel(data)                      (0x0000003F&(data))
#define  EPI_EPI_LANE_CTR3_MUX3_get_lane_ctr3_c19_mux_sel(data)                  ((0x3F000000&(data))>>24)
#define  EPI_EPI_LANE_CTR3_MUX3_get_lane_ctr3_c18_mux_sel(data)                  ((0x00FC0000&(data))>>18)
#define  EPI_EPI_LANE_CTR3_MUX3_get_lane_ctr3_c17_mux_sel(data)                  ((0x0003F000&(data))>>12)
#define  EPI_EPI_LANE_CTR3_MUX3_get_lane_ctr3_c16_mux_sel(data)                  ((0x00000FC0&(data))>>6)
#define  EPI_EPI_LANE_CTR3_MUX3_get_lane_ctr3_c15_mux_sel(data)                  (0x0000003F&(data))

#define  EPI_EPI_LANE_CTR3_MUX4                                                  0x180263F0
#define  EPI_EPI_LANE_CTR3_MUX4_reg_addr                                         "0xB80263F0"
#define  EPI_EPI_LANE_CTR3_MUX4_reg                                              0xB80263F0
#define  EPI_EPI_LANE_CTR3_MUX4_inst_addr                                        "0x005E"
#define  set_EPI_EPI_LANE_CTR3_MUX4_reg(data)                                    (*((volatile unsigned int*)EPI_EPI_LANE_CTR3_MUX4_reg)=data)
#define  get_EPI_EPI_LANE_CTR3_MUX4_reg                                          (*((volatile unsigned int*)EPI_EPI_LANE_CTR3_MUX4_reg))
#define  EPI_EPI_LANE_CTR3_MUX4_lane_ctr3_c24_mux_sel_shift                      (24)
#define  EPI_EPI_LANE_CTR3_MUX4_lane_ctr3_c23_mux_sel_shift                      (18)
#define  EPI_EPI_LANE_CTR3_MUX4_lane_ctr3_c22_mux_sel_shift                      (12)
#define  EPI_EPI_LANE_CTR3_MUX4_lane_ctr3_c21_mux_sel_shift                      (6)
#define  EPI_EPI_LANE_CTR3_MUX4_lane_ctr3_c20_mux_sel_shift                      (0)
#define  EPI_EPI_LANE_CTR3_MUX4_lane_ctr3_c24_mux_sel_mask                       (0x3F000000)
#define  EPI_EPI_LANE_CTR3_MUX4_lane_ctr3_c23_mux_sel_mask                       (0x00FC0000)
#define  EPI_EPI_LANE_CTR3_MUX4_lane_ctr3_c22_mux_sel_mask                       (0x0003F000)
#define  EPI_EPI_LANE_CTR3_MUX4_lane_ctr3_c21_mux_sel_mask                       (0x00000FC0)
#define  EPI_EPI_LANE_CTR3_MUX4_lane_ctr3_c20_mux_sel_mask                       (0x0000003F)
#define  EPI_EPI_LANE_CTR3_MUX4_lane_ctr3_c24_mux_sel(data)                      (0x3F000000&((data)<<24))
#define  EPI_EPI_LANE_CTR3_MUX4_lane_ctr3_c23_mux_sel(data)                      (0x00FC0000&((data)<<18))
#define  EPI_EPI_LANE_CTR3_MUX4_lane_ctr3_c22_mux_sel(data)                      (0x0003F000&((data)<<12))
#define  EPI_EPI_LANE_CTR3_MUX4_lane_ctr3_c21_mux_sel(data)                      (0x00000FC0&((data)<<6))
#define  EPI_EPI_LANE_CTR3_MUX4_lane_ctr3_c20_mux_sel(data)                      (0x0000003F&(data))
#define  EPI_EPI_LANE_CTR3_MUX4_get_lane_ctr3_c24_mux_sel(data)                  ((0x3F000000&(data))>>24)
#define  EPI_EPI_LANE_CTR3_MUX4_get_lane_ctr3_c23_mux_sel(data)                  ((0x00FC0000&(data))>>18)
#define  EPI_EPI_LANE_CTR3_MUX4_get_lane_ctr3_c22_mux_sel(data)                  ((0x0003F000&(data))>>12)
#define  EPI_EPI_LANE_CTR3_MUX4_get_lane_ctr3_c21_mux_sel(data)                  ((0x00000FC0&(data))>>6)
#define  EPI_EPI_LANE_CTR3_MUX4_get_lane_ctr3_c20_mux_sel(data)                  (0x0000003F&(data))

#define  EPI_EPI_LANE_CTR3_MUX5                                                  0x180263F4
#define  EPI_EPI_LANE_CTR3_MUX5_reg_addr                                         "0xB80263F4"
#define  EPI_EPI_LANE_CTR3_MUX5_reg                                              0xB80263F4
#define  EPI_EPI_LANE_CTR3_MUX5_inst_addr                                        "0x005F"
#define  set_EPI_EPI_LANE_CTR3_MUX5_reg(data)                                    (*((volatile unsigned int*)EPI_EPI_LANE_CTR3_MUX5_reg)=data)
#define  get_EPI_EPI_LANE_CTR3_MUX5_reg                                          (*((volatile unsigned int*)EPI_EPI_LANE_CTR3_MUX5_reg))
#define  EPI_EPI_LANE_CTR3_MUX5_lane_ctr3_c29_mux_sel_shift                      (24)
#define  EPI_EPI_LANE_CTR3_MUX5_lane_ctr3_c28_mux_sel_shift                      (18)
#define  EPI_EPI_LANE_CTR3_MUX5_lane_ctr3_c27_mux_sel_shift                      (12)
#define  EPI_EPI_LANE_CTR3_MUX5_lane_ctr3_c26_mux_sel_shift                      (6)
#define  EPI_EPI_LANE_CTR3_MUX5_lane_ctr3_c25_mux_sel_shift                      (0)
#define  EPI_EPI_LANE_CTR3_MUX5_lane_ctr3_c29_mux_sel_mask                       (0x3F000000)
#define  EPI_EPI_LANE_CTR3_MUX5_lane_ctr3_c28_mux_sel_mask                       (0x00FC0000)
#define  EPI_EPI_LANE_CTR3_MUX5_lane_ctr3_c27_mux_sel_mask                       (0x0003F000)
#define  EPI_EPI_LANE_CTR3_MUX5_lane_ctr3_c26_mux_sel_mask                       (0x00000FC0)
#define  EPI_EPI_LANE_CTR3_MUX5_lane_ctr3_c25_mux_sel_mask                       (0x0000003F)
#define  EPI_EPI_LANE_CTR3_MUX5_lane_ctr3_c29_mux_sel(data)                      (0x3F000000&((data)<<24))
#define  EPI_EPI_LANE_CTR3_MUX5_lane_ctr3_c28_mux_sel(data)                      (0x00FC0000&((data)<<18))
#define  EPI_EPI_LANE_CTR3_MUX5_lane_ctr3_c27_mux_sel(data)                      (0x0003F000&((data)<<12))
#define  EPI_EPI_LANE_CTR3_MUX5_lane_ctr3_c26_mux_sel(data)                      (0x00000FC0&((data)<<6))
#define  EPI_EPI_LANE_CTR3_MUX5_lane_ctr3_c25_mux_sel(data)                      (0x0000003F&(data))
#define  EPI_EPI_LANE_CTR3_MUX5_get_lane_ctr3_c29_mux_sel(data)                  ((0x3F000000&(data))>>24)
#define  EPI_EPI_LANE_CTR3_MUX5_get_lane_ctr3_c28_mux_sel(data)                  ((0x00FC0000&(data))>>18)
#define  EPI_EPI_LANE_CTR3_MUX5_get_lane_ctr3_c27_mux_sel(data)                  ((0x0003F000&(data))>>12)
#define  EPI_EPI_LANE_CTR3_MUX5_get_lane_ctr3_c26_mux_sel(data)                  ((0x00000FC0&(data))>>6)
#define  EPI_EPI_LANE_CTR3_MUX5_get_lane_ctr3_c25_mux_sel(data)                  (0x0000003F&(data))

#define  EPI_EPI_TCON_MUX                                                        0x18026500
#define  EPI_EPI_TCON_MUX_reg_addr                                               "0xB8026500"
#define  EPI_EPI_TCON_MUX_reg                                                    0xB8026500
#define  EPI_EPI_TCON_MUX_inst_addr                                              "0x0060"
#define  set_EPI_EPI_TCON_MUX_reg(data)                                          (*((volatile unsigned int*)EPI_EPI_TCON_MUX_reg)=data)
#define  get_EPI_EPI_TCON_MUX_reg                                                (*((volatile unsigned int*)EPI_EPI_TCON_MUX_reg))
#define  EPI_EPI_TCON_MUX_tcon_c_sel_shift                                       (16)
#define  EPI_EPI_TCON_MUX_tcon_b_sel_shift                                       (8)
#define  EPI_EPI_TCON_MUX_tcon_a_sel_shift                                       (0)
#define  EPI_EPI_TCON_MUX_tcon_c_sel_mask                                        (0x001F0000)
#define  EPI_EPI_TCON_MUX_tcon_b_sel_mask                                        (0x00001F00)
#define  EPI_EPI_TCON_MUX_tcon_a_sel_mask                                        (0x0000001F)
#define  EPI_EPI_TCON_MUX_tcon_c_sel(data)                                       (0x001F0000&((data)<<16))
#define  EPI_EPI_TCON_MUX_tcon_b_sel(data)                                       (0x00001F00&((data)<<8))
#define  EPI_EPI_TCON_MUX_tcon_a_sel(data)                                       (0x0000001F&(data))
#define  EPI_EPI_TCON_MUX_get_tcon_c_sel(data)                                   ((0x001F0000&(data))>>16)
#define  EPI_EPI_TCON_MUX_get_tcon_b_sel(data)                                   ((0x00001F00&(data))>>8)
#define  EPI_EPI_TCON_MUX_get_tcon_a_sel(data)                                   (0x0000001F&(data))

#define  EPI_EPI_TCON_MUX1                                                       0x18026504
#define  EPI_EPI_TCON_MUX1_reg_addr                                              "0xB8026504"
#define  EPI_EPI_TCON_MUX1_reg                                                   0xB8026504
#define  EPI_EPI_TCON_MUX1_inst_addr                                             "0x0061"
#define  set_EPI_EPI_TCON_MUX1_reg(data)                                         (*((volatile unsigned int*)EPI_EPI_TCON_MUX1_reg)=data)
#define  get_EPI_EPI_TCON_MUX1_reg                                               (*((volatile unsigned int*)EPI_EPI_TCON_MUX1_reg))
#define  EPI_EPI_TCON_MUX1_tcon_f_sel_shift                                      (16)
#define  EPI_EPI_TCON_MUX1_tcon_e_sel_shift                                      (8)
#define  EPI_EPI_TCON_MUX1_tcon_d_sel_shift                                      (0)
#define  EPI_EPI_TCON_MUX1_tcon_f_sel_mask                                       (0x001F0000)
#define  EPI_EPI_TCON_MUX1_tcon_e_sel_mask                                       (0x00001F00)
#define  EPI_EPI_TCON_MUX1_tcon_d_sel_mask                                       (0x0000001F)
#define  EPI_EPI_TCON_MUX1_tcon_f_sel(data)                                      (0x001F0000&((data)<<16))
#define  EPI_EPI_TCON_MUX1_tcon_e_sel(data)                                      (0x00001F00&((data)<<8))
#define  EPI_EPI_TCON_MUX1_tcon_d_sel(data)                                      (0x0000001F&(data))
#define  EPI_EPI_TCON_MUX1_get_tcon_f_sel(data)                                  ((0x001F0000&(data))>>16)
#define  EPI_EPI_TCON_MUX1_get_tcon_e_sel(data)                                  ((0x00001F00&(data))>>8)
#define  EPI_EPI_TCON_MUX1_get_tcon_d_sel(data)                                  (0x0000001F&(data))

#define  EPI_EPI_TCON_MUX2                                                       0x18026508
#define  EPI_EPI_TCON_MUX2_reg_addr                                              "0xB8026508"
#define  EPI_EPI_TCON_MUX2_reg                                                   0xB8026508
#define  EPI_EPI_TCON_MUX2_inst_addr                                             "0x0062"
#define  set_EPI_EPI_TCON_MUX2_reg(data)                                         (*((volatile unsigned int*)EPI_EPI_TCON_MUX2_reg)=data)
#define  get_EPI_EPI_TCON_MUX2_reg                                               (*((volatile unsigned int*)EPI_EPI_TCON_MUX2_reg))
#define  EPI_EPI_TCON_MUX2_tcon_i_sel_shift                                      (16)
#define  EPI_EPI_TCON_MUX2_tcon_h_sel_shift                                      (8)
#define  EPI_EPI_TCON_MUX2_tcon_g_sel_shift                                      (0)
#define  EPI_EPI_TCON_MUX2_tcon_i_sel_mask                                       (0x001F0000)
#define  EPI_EPI_TCON_MUX2_tcon_h_sel_mask                                       (0x00001F00)
#define  EPI_EPI_TCON_MUX2_tcon_g_sel_mask                                       (0x0000001F)
#define  EPI_EPI_TCON_MUX2_tcon_i_sel(data)                                      (0x001F0000&((data)<<16))
#define  EPI_EPI_TCON_MUX2_tcon_h_sel(data)                                      (0x00001F00&((data)<<8))
#define  EPI_EPI_TCON_MUX2_tcon_g_sel(data)                                      (0x0000001F&(data))
#define  EPI_EPI_TCON_MUX2_get_tcon_i_sel(data)                                  ((0x001F0000&(data))>>16)
#define  EPI_EPI_TCON_MUX2_get_tcon_h_sel(data)                                  ((0x00001F00&(data))>>8)
#define  EPI_EPI_TCON_MUX2_get_tcon_g_sel(data)                                  (0x0000001F&(data))

#define  EPI_EPI_TCON_MUX3                                                       0x1802650C
#define  EPI_EPI_TCON_MUX3_reg_addr                                              "0xB802650C"
#define  EPI_EPI_TCON_MUX3_reg                                                   0xB802650C
#define  EPI_EPI_TCON_MUX3_inst_addr                                             "0x0063"
#define  set_EPI_EPI_TCON_MUX3_reg(data)                                         (*((volatile unsigned int*)EPI_EPI_TCON_MUX3_reg)=data)
#define  get_EPI_EPI_TCON_MUX3_reg                                               (*((volatile unsigned int*)EPI_EPI_TCON_MUX3_reg))
#define  EPI_EPI_TCON_MUX3_tcon_k_sel_shift                                      (8)
#define  EPI_EPI_TCON_MUX3_tcon_j_sel_shift                                      (0)
#define  EPI_EPI_TCON_MUX3_tcon_k_sel_mask                                       (0x00001F00)
#define  EPI_EPI_TCON_MUX3_tcon_j_sel_mask                                       (0x0000001F)
#define  EPI_EPI_TCON_MUX3_tcon_k_sel(data)                                      (0x00001F00&((data)<<8))
#define  EPI_EPI_TCON_MUX3_tcon_j_sel(data)                                      (0x0000001F&(data))
#define  EPI_EPI_TCON_MUX3_get_tcon_k_sel(data)                                  ((0x00001F00&(data))>>8)
#define  EPI_EPI_TCON_MUX3_get_tcon_j_sel(data)                                  (0x0000001F&(data))

#define  EPI_EPI_DUMMY_REG                                                       0x18026510
#define  EPI_EPI_DUMMY_REG_reg_addr                                              "0xB8026510"
#define  EPI_EPI_DUMMY_REG_reg                                                   0xB8026510
#define  EPI_EPI_DUMMY_REG_inst_addr                                             "0x0064"
#define  set_EPI_EPI_DUMMY_REG_reg(data)                                         (*((volatile unsigned int*)EPI_EPI_DUMMY_REG_reg)=data)
#define  get_EPI_EPI_DUMMY_REG_reg                                               (*((volatile unsigned int*)EPI_EPI_DUMMY_REG_reg))
#define  EPI_EPI_DUMMY_REG_dummy_31_0_shift                                      (0)
#define  EPI_EPI_DUMMY_REG_dummy_31_0_mask                                       (0xFFFFFFFF)
#define  EPI_EPI_DUMMY_REG_dummy_31_0(data)                                      (0xFFFFFFFF&(data))
#define  EPI_EPI_DUMMY_REG_get_dummy_31_0(data)                                  (0xFFFFFFFF&(data))

#define  EPI_EPI_LANE_DST_DATA                                                   0x18026528
#define  EPI_EPI_LANE_DST_DATA_reg_addr                                          "0xB8026528"
#define  EPI_EPI_LANE_DST_DATA_reg                                               0xB8026528
#define  EPI_EPI_LANE_DST_DATA_inst_addr                                         "0x0065"
#define  set_EPI_EPI_LANE_DST_DATA_reg(data)                                     (*((volatile unsigned int*)EPI_EPI_LANE_DST_DATA_reg)=data)
#define  get_EPI_EPI_LANE_DST_DATA_reg                                           (*((volatile unsigned int*)EPI_EPI_LANE_DST_DATA_reg))
#define  EPI_EPI_LANE_DST_DATA_d_st_shift                                        (0)
#define  EPI_EPI_LANE_DST_DATA_d_st_mask                                         (0x3FFFFFFF)
#define  EPI_EPI_LANE_DST_DATA_d_st(data)                                        (0x3FFFFFFF&(data))
#define  EPI_EPI_LANE_DST_DATA_get_d_st(data)                                    (0x3FFFFFFF&(data))

#define  EPI_EPI_LANE_CST_DATA                                                   0x1802653C
#define  EPI_EPI_LANE_CST_DATA_reg_addr                                          "0xB802653C"
#define  EPI_EPI_LANE_CST_DATA_reg                                               0xB802653C
#define  EPI_EPI_LANE_CST_DATA_inst_addr                                         "0x0066"
#define  set_EPI_EPI_LANE_CST_DATA_reg(data)                                     (*((volatile unsigned int*)EPI_EPI_LANE_CST_DATA_reg)=data)
#define  get_EPI_EPI_LANE_CST_DATA_reg                                           (*((volatile unsigned int*)EPI_EPI_LANE_CST_DATA_reg))
#define  EPI_EPI_LANE_CST_DATA_c_st_shift                                        (0)
#define  EPI_EPI_LANE_CST_DATA_c_st_mask                                         (0x3FFFFFFF)
#define  EPI_EPI_LANE_CST_DATA_c_st(data)                                        (0x3FFFFFFF&(data))
#define  EPI_EPI_LANE_CST_DATA_get_c_st(data)                                    (0x3FFFFFFF&(data))

#define  EPI_EPI_LANE0_CTR1_EDATA                                                0x18026550
#define  EPI_EPI_LANE0_CTR1_EDATA_reg_addr                                       "0xB8026550"
#define  EPI_EPI_LANE0_CTR1_EDATA_reg                                            0xB8026550
#define  EPI_EPI_LANE0_CTR1_EDATA_inst_addr                                      "0x0067"
#define  set_EPI_EPI_LANE0_CTR1_EDATA_reg(data)                                  (*((volatile unsigned int*)EPI_EPI_LANE0_CTR1_EDATA_reg)=data)
#define  get_EPI_EPI_LANE0_CTR1_EDATA_reg                                        (*((volatile unsigned int*)EPI_EPI_LANE0_CTR1_EDATA_reg))
#define  EPI_EPI_LANE0_CTR1_EDATA_lane0_ctr1_oe_en_shift                         (30)
#define  EPI_EPI_LANE0_CTR1_EDATA_lane0_ctr1_even_shift                          (0)
#define  EPI_EPI_LANE0_CTR1_EDATA_lane0_ctr1_oe_en_mask                          (0x40000000)
#define  EPI_EPI_LANE0_CTR1_EDATA_lane0_ctr1_even_mask                           (0x3FFFFFFF)
#define  EPI_EPI_LANE0_CTR1_EDATA_lane0_ctr1_oe_en(data)                         (0x40000000&((data)<<30))
#define  EPI_EPI_LANE0_CTR1_EDATA_lane0_ctr1_even(data)                          (0x3FFFFFFF&(data))
#define  EPI_EPI_LANE0_CTR1_EDATA_get_lane0_ctr1_oe_en(data)                     ((0x40000000&(data))>>30)
#define  EPI_EPI_LANE0_CTR1_EDATA_get_lane0_ctr1_even(data)                      (0x3FFFFFFF&(data))

#define  EPI_EPI_LANE0_CTR1_ODATA                                                0x18026554
#define  EPI_EPI_LANE0_CTR1_ODATA_reg_addr                                       "0xB8026554"
#define  EPI_EPI_LANE0_CTR1_ODATA_reg                                            0xB8026554
#define  EPI_EPI_LANE0_CTR1_ODATA_inst_addr                                      "0x0068"
#define  set_EPI_EPI_LANE0_CTR1_ODATA_reg(data)                                  (*((volatile unsigned int*)EPI_EPI_LANE0_CTR1_ODATA_reg)=data)
#define  get_EPI_EPI_LANE0_CTR1_ODATA_reg                                        (*((volatile unsigned int*)EPI_EPI_LANE0_CTR1_ODATA_reg))
#define  EPI_EPI_LANE0_CTR1_ODATA_lane0_ctr1_odd_shift                           (0)
#define  EPI_EPI_LANE0_CTR1_ODATA_lane0_ctr1_odd_mask                            (0x3FFFFFFF)
#define  EPI_EPI_LANE0_CTR1_ODATA_lane0_ctr1_odd(data)                           (0x3FFFFFFF&(data))
#define  EPI_EPI_LANE0_CTR1_ODATA_get_lane0_ctr1_odd(data)                       (0x3FFFFFFF&(data))

#define  EPI_EPI_LANE1_CTR1_EDATA                                                0x18026558
#define  EPI_EPI_LANE1_CTR1_EDATA_reg_addr                                       "0xB8026558"
#define  EPI_EPI_LANE1_CTR1_EDATA_reg                                            0xB8026558
#define  EPI_EPI_LANE1_CTR1_EDATA_inst_addr                                      "0x0069"
#define  set_EPI_EPI_LANE1_CTR1_EDATA_reg(data)                                  (*((volatile unsigned int*)EPI_EPI_LANE1_CTR1_EDATA_reg)=data)
#define  get_EPI_EPI_LANE1_CTR1_EDATA_reg                                        (*((volatile unsigned int*)EPI_EPI_LANE1_CTR1_EDATA_reg))
#define  EPI_EPI_LANE1_CTR1_EDATA_lane1_ctr1_oe_en_shift                         (30)
#define  EPI_EPI_LANE1_CTR1_EDATA_lane1_ctr1_even_shift                          (0)
#define  EPI_EPI_LANE1_CTR1_EDATA_lane1_ctr1_oe_en_mask                          (0x40000000)
#define  EPI_EPI_LANE1_CTR1_EDATA_lane1_ctr1_even_mask                           (0x3FFFFFFF)
#define  EPI_EPI_LANE1_CTR1_EDATA_lane1_ctr1_oe_en(data)                         (0x40000000&((data)<<30))
#define  EPI_EPI_LANE1_CTR1_EDATA_lane1_ctr1_even(data)                          (0x3FFFFFFF&(data))
#define  EPI_EPI_LANE1_CTR1_EDATA_get_lane1_ctr1_oe_en(data)                     ((0x40000000&(data))>>30)
#define  EPI_EPI_LANE1_CTR1_EDATA_get_lane1_ctr1_even(data)                      (0x3FFFFFFF&(data))

#define  EPI_EPI_LANE1_CTR1_ODATA                                                0x1802655C
#define  EPI_EPI_LANE1_CTR1_ODATA_reg_addr                                       "0xB802655C"
#define  EPI_EPI_LANE1_CTR1_ODATA_reg                                            0xB802655C
#define  EPI_EPI_LANE1_CTR1_ODATA_inst_addr                                      "0x006A"
#define  set_EPI_EPI_LANE1_CTR1_ODATA_reg(data)                                  (*((volatile unsigned int*)EPI_EPI_LANE1_CTR1_ODATA_reg)=data)
#define  get_EPI_EPI_LANE1_CTR1_ODATA_reg                                        (*((volatile unsigned int*)EPI_EPI_LANE1_CTR1_ODATA_reg))
#define  EPI_EPI_LANE1_CTR1_ODATA_lane1_ctr1_odd_shift                           (0)
#define  EPI_EPI_LANE1_CTR1_ODATA_lane1_ctr1_odd_mask                            (0x3FFFFFFF)
#define  EPI_EPI_LANE1_CTR1_ODATA_lane1_ctr1_odd(data)                           (0x3FFFFFFF&(data))
#define  EPI_EPI_LANE1_CTR1_ODATA_get_lane1_ctr1_odd(data)                       (0x3FFFFFFF&(data))

#define  EPI_EPI_LANE2_CTR1_EDATA                                                0x18026560
#define  EPI_EPI_LANE2_CTR1_EDATA_reg_addr                                       "0xB8026560"
#define  EPI_EPI_LANE2_CTR1_EDATA_reg                                            0xB8026560
#define  EPI_EPI_LANE2_CTR1_EDATA_inst_addr                                      "0x006B"
#define  set_EPI_EPI_LANE2_CTR1_EDATA_reg(data)                                  (*((volatile unsigned int*)EPI_EPI_LANE2_CTR1_EDATA_reg)=data)
#define  get_EPI_EPI_LANE2_CTR1_EDATA_reg                                        (*((volatile unsigned int*)EPI_EPI_LANE2_CTR1_EDATA_reg))
#define  EPI_EPI_LANE2_CTR1_EDATA_lane2_ctr1_oe_en_shift                         (30)
#define  EPI_EPI_LANE2_CTR1_EDATA_lane2_ctr1_even_shift                          (0)
#define  EPI_EPI_LANE2_CTR1_EDATA_lane2_ctr1_oe_en_mask                          (0x40000000)
#define  EPI_EPI_LANE2_CTR1_EDATA_lane2_ctr1_even_mask                           (0x3FFFFFFF)
#define  EPI_EPI_LANE2_CTR1_EDATA_lane2_ctr1_oe_en(data)                         (0x40000000&((data)<<30))
#define  EPI_EPI_LANE2_CTR1_EDATA_lane2_ctr1_even(data)                          (0x3FFFFFFF&(data))
#define  EPI_EPI_LANE2_CTR1_EDATA_get_lane2_ctr1_oe_en(data)                     ((0x40000000&(data))>>30)
#define  EPI_EPI_LANE2_CTR1_EDATA_get_lane2_ctr1_even(data)                      (0x3FFFFFFF&(data))

#define  EPI_EPI_LANE2_CTR1_ODATA                                                0x18026564
#define  EPI_EPI_LANE2_CTR1_ODATA_reg_addr                                       "0xB8026564"
#define  EPI_EPI_LANE2_CTR1_ODATA_reg                                            0xB8026564
#define  EPI_EPI_LANE2_CTR1_ODATA_inst_addr                                      "0x006C"
#define  set_EPI_EPI_LANE2_CTR1_ODATA_reg(data)                                  (*((volatile unsigned int*)EPI_EPI_LANE2_CTR1_ODATA_reg)=data)
#define  get_EPI_EPI_LANE2_CTR1_ODATA_reg                                        (*((volatile unsigned int*)EPI_EPI_LANE2_CTR1_ODATA_reg))
#define  EPI_EPI_LANE2_CTR1_ODATA_lane2_ctr1_odd_shift                           (0)
#define  EPI_EPI_LANE2_CTR1_ODATA_lane2_ctr1_odd_mask                            (0x3FFFFFFF)
#define  EPI_EPI_LANE2_CTR1_ODATA_lane2_ctr1_odd(data)                           (0x3FFFFFFF&(data))
#define  EPI_EPI_LANE2_CTR1_ODATA_get_lane2_ctr1_odd(data)                       (0x3FFFFFFF&(data))

#define  EPI_EPI_LANE3_CTR1_EDATA                                                0x18026568
#define  EPI_EPI_LANE3_CTR1_EDATA_reg_addr                                       "0xB8026568"
#define  EPI_EPI_LANE3_CTR1_EDATA_reg                                            0xB8026568
#define  EPI_EPI_LANE3_CTR1_EDATA_inst_addr                                      "0x006D"
#define  set_EPI_EPI_LANE3_CTR1_EDATA_reg(data)                                  (*((volatile unsigned int*)EPI_EPI_LANE3_CTR1_EDATA_reg)=data)
#define  get_EPI_EPI_LANE3_CTR1_EDATA_reg                                        (*((volatile unsigned int*)EPI_EPI_LANE3_CTR1_EDATA_reg))
#define  EPI_EPI_LANE3_CTR1_EDATA_lane3_ctr1_oe_en_shift                         (30)
#define  EPI_EPI_LANE3_CTR1_EDATA_lane3_ctr1_even_shift                          (0)
#define  EPI_EPI_LANE3_CTR1_EDATA_lane3_ctr1_oe_en_mask                          (0x40000000)
#define  EPI_EPI_LANE3_CTR1_EDATA_lane3_ctr1_even_mask                           (0x3FFFFFFF)
#define  EPI_EPI_LANE3_CTR1_EDATA_lane3_ctr1_oe_en(data)                         (0x40000000&((data)<<30))
#define  EPI_EPI_LANE3_CTR1_EDATA_lane3_ctr1_even(data)                          (0x3FFFFFFF&(data))
#define  EPI_EPI_LANE3_CTR1_EDATA_get_lane3_ctr1_oe_en(data)                     ((0x40000000&(data))>>30)
#define  EPI_EPI_LANE3_CTR1_EDATA_get_lane3_ctr1_even(data)                      (0x3FFFFFFF&(data))

#define  EPI_EPI_LANE3_CTR1_ODATA                                                0x1802656C
#define  EPI_EPI_LANE3_CTR1_ODATA_reg_addr                                       "0xB802656C"
#define  EPI_EPI_LANE3_CTR1_ODATA_reg                                            0xB802656C
#define  EPI_EPI_LANE3_CTR1_ODATA_inst_addr                                      "0x006E"
#define  set_EPI_EPI_LANE3_CTR1_ODATA_reg(data)                                  (*((volatile unsigned int*)EPI_EPI_LANE3_CTR1_ODATA_reg)=data)
#define  get_EPI_EPI_LANE3_CTR1_ODATA_reg                                        (*((volatile unsigned int*)EPI_EPI_LANE3_CTR1_ODATA_reg))
#define  EPI_EPI_LANE3_CTR1_ODATA_lane3_ctr1_odd_shift                           (0)
#define  EPI_EPI_LANE3_CTR1_ODATA_lane3_ctr1_odd_mask                            (0x3FFFFFFF)
#define  EPI_EPI_LANE3_CTR1_ODATA_lane3_ctr1_odd(data)                           (0x3FFFFFFF&(data))
#define  EPI_EPI_LANE3_CTR1_ODATA_get_lane3_ctr1_odd(data)                       (0x3FFFFFFF&(data))

#define  EPI_EPI_LANE4_CTR1_EDATA                                                0x18026570
#define  EPI_EPI_LANE4_CTR1_EDATA_reg_addr                                       "0xB8026570"
#define  EPI_EPI_LANE4_CTR1_EDATA_reg                                            0xB8026570
#define  EPI_EPI_LANE4_CTR1_EDATA_inst_addr                                      "0x006F"
#define  set_EPI_EPI_LANE4_CTR1_EDATA_reg(data)                                  (*((volatile unsigned int*)EPI_EPI_LANE4_CTR1_EDATA_reg)=data)
#define  get_EPI_EPI_LANE4_CTR1_EDATA_reg                                        (*((volatile unsigned int*)EPI_EPI_LANE4_CTR1_EDATA_reg))
#define  EPI_EPI_LANE4_CTR1_EDATA_lane4_ctr1_oe_en_shift                         (30)
#define  EPI_EPI_LANE4_CTR1_EDATA_lane4_ctr1_even_shift                          (0)
#define  EPI_EPI_LANE4_CTR1_EDATA_lane4_ctr1_oe_en_mask                          (0x40000000)
#define  EPI_EPI_LANE4_CTR1_EDATA_lane4_ctr1_even_mask                           (0x3FFFFFFF)
#define  EPI_EPI_LANE4_CTR1_EDATA_lane4_ctr1_oe_en(data)                         (0x40000000&((data)<<30))
#define  EPI_EPI_LANE4_CTR1_EDATA_lane4_ctr1_even(data)                          (0x3FFFFFFF&(data))
#define  EPI_EPI_LANE4_CTR1_EDATA_get_lane4_ctr1_oe_en(data)                     ((0x40000000&(data))>>30)
#define  EPI_EPI_LANE4_CTR1_EDATA_get_lane4_ctr1_even(data)                      (0x3FFFFFFF&(data))

#define  EPI_EPI_LANE4_CTR1_ODATA                                                0x18026574
#define  EPI_EPI_LANE4_CTR1_ODATA_reg_addr                                       "0xB8026574"
#define  EPI_EPI_LANE4_CTR1_ODATA_reg                                            0xB8026574
#define  EPI_EPI_LANE4_CTR1_ODATA_inst_addr                                      "0x0070"
#define  set_EPI_EPI_LANE4_CTR1_ODATA_reg(data)                                  (*((volatile unsigned int*)EPI_EPI_LANE4_CTR1_ODATA_reg)=data)
#define  get_EPI_EPI_LANE4_CTR1_ODATA_reg                                        (*((volatile unsigned int*)EPI_EPI_LANE4_CTR1_ODATA_reg))
#define  EPI_EPI_LANE4_CTR1_ODATA_lane4_ctr1_odd_shift                           (0)
#define  EPI_EPI_LANE4_CTR1_ODATA_lane4_ctr1_odd_mask                            (0x3FFFFFFF)
#define  EPI_EPI_LANE4_CTR1_ODATA_lane4_ctr1_odd(data)                           (0x3FFFFFFF&(data))
#define  EPI_EPI_LANE4_CTR1_ODATA_get_lane4_ctr1_odd(data)                       (0x3FFFFFFF&(data))

#define  EPI_EPI_LANE5_CTR1_EDATA                                                0x18026578
#define  EPI_EPI_LANE5_CTR1_EDATA_reg_addr                                       "0xB8026578"
#define  EPI_EPI_LANE5_CTR1_EDATA_reg                                            0xB8026578
#define  EPI_EPI_LANE5_CTR1_EDATA_inst_addr                                      "0x0071"
#define  set_EPI_EPI_LANE5_CTR1_EDATA_reg(data)                                  (*((volatile unsigned int*)EPI_EPI_LANE5_CTR1_EDATA_reg)=data)
#define  get_EPI_EPI_LANE5_CTR1_EDATA_reg                                        (*((volatile unsigned int*)EPI_EPI_LANE5_CTR1_EDATA_reg))
#define  EPI_EPI_LANE5_CTR1_EDATA_lane5_ctr1_oe_en_shift                         (30)
#define  EPI_EPI_LANE5_CTR1_EDATA_lane5_ctr1_even_shift                          (0)
#define  EPI_EPI_LANE5_CTR1_EDATA_lane5_ctr1_oe_en_mask                          (0x40000000)
#define  EPI_EPI_LANE5_CTR1_EDATA_lane5_ctr1_even_mask                           (0x3FFFFFFF)
#define  EPI_EPI_LANE5_CTR1_EDATA_lane5_ctr1_oe_en(data)                         (0x40000000&((data)<<30))
#define  EPI_EPI_LANE5_CTR1_EDATA_lane5_ctr1_even(data)                          (0x3FFFFFFF&(data))
#define  EPI_EPI_LANE5_CTR1_EDATA_get_lane5_ctr1_oe_en(data)                     ((0x40000000&(data))>>30)
#define  EPI_EPI_LANE5_CTR1_EDATA_get_lane5_ctr1_even(data)                      (0x3FFFFFFF&(data))

#define  EPI_EPI_LANE5_CTR1_ODATA                                                0x1802657C
#define  EPI_EPI_LANE5_CTR1_ODATA_reg_addr                                       "0xB802657C"
#define  EPI_EPI_LANE5_CTR1_ODATA_reg                                            0xB802657C
#define  EPI_EPI_LANE5_CTR1_ODATA_inst_addr                                      "0x0072"
#define  set_EPI_EPI_LANE5_CTR1_ODATA_reg(data)                                  (*((volatile unsigned int*)EPI_EPI_LANE5_CTR1_ODATA_reg)=data)
#define  get_EPI_EPI_LANE5_CTR1_ODATA_reg                                        (*((volatile unsigned int*)EPI_EPI_LANE5_CTR1_ODATA_reg))
#define  EPI_EPI_LANE5_CTR1_ODATA_lane5_ctr1_odd_shift                           (0)
#define  EPI_EPI_LANE5_CTR1_ODATA_lane5_ctr1_odd_mask                            (0x3FFFFFFF)
#define  EPI_EPI_LANE5_CTR1_ODATA_lane5_ctr1_odd(data)                           (0x3FFFFFFF&(data))
#define  EPI_EPI_LANE5_CTR1_ODATA_get_lane5_ctr1_odd(data)                       (0x3FFFFFFF&(data))

#define  EPI_EPI_LANE6_CTR1_EDATA                                                0x18026580
#define  EPI_EPI_LANE6_CTR1_EDATA_reg_addr                                       "0xB8026580"
#define  EPI_EPI_LANE6_CTR1_EDATA_reg                                            0xB8026580
#define  EPI_EPI_LANE6_CTR1_EDATA_inst_addr                                      "0x0073"
#define  set_EPI_EPI_LANE6_CTR1_EDATA_reg(data)                                  (*((volatile unsigned int*)EPI_EPI_LANE6_CTR1_EDATA_reg)=data)
#define  get_EPI_EPI_LANE6_CTR1_EDATA_reg                                        (*((volatile unsigned int*)EPI_EPI_LANE6_CTR1_EDATA_reg))
#define  EPI_EPI_LANE6_CTR1_EDATA_lane6_ctr1_oe_en_shift                         (30)
#define  EPI_EPI_LANE6_CTR1_EDATA_lane6_ctr1_even_shift                          (0)
#define  EPI_EPI_LANE6_CTR1_EDATA_lane6_ctr1_oe_en_mask                          (0x40000000)
#define  EPI_EPI_LANE6_CTR1_EDATA_lane6_ctr1_even_mask                           (0x3FFFFFFF)
#define  EPI_EPI_LANE6_CTR1_EDATA_lane6_ctr1_oe_en(data)                         (0x40000000&((data)<<30))
#define  EPI_EPI_LANE6_CTR1_EDATA_lane6_ctr1_even(data)                          (0x3FFFFFFF&(data))
#define  EPI_EPI_LANE6_CTR1_EDATA_get_lane6_ctr1_oe_en(data)                     ((0x40000000&(data))>>30)
#define  EPI_EPI_LANE6_CTR1_EDATA_get_lane6_ctr1_even(data)                      (0x3FFFFFFF&(data))

#define  EPI_EPI_LANE6_CTR1_ODATA                                                0x18026584
#define  EPI_EPI_LANE6_CTR1_ODATA_reg_addr                                       "0xB8026584"
#define  EPI_EPI_LANE6_CTR1_ODATA_reg                                            0xB8026584
#define  EPI_EPI_LANE6_CTR1_ODATA_inst_addr                                      "0x0074"
#define  set_EPI_EPI_LANE6_CTR1_ODATA_reg(data)                                  (*((volatile unsigned int*)EPI_EPI_LANE6_CTR1_ODATA_reg)=data)
#define  get_EPI_EPI_LANE6_CTR1_ODATA_reg                                        (*((volatile unsigned int*)EPI_EPI_LANE6_CTR1_ODATA_reg))
#define  EPI_EPI_LANE6_CTR1_ODATA_lane6_ctr1_odd_shift                           (0)
#define  EPI_EPI_LANE6_CTR1_ODATA_lane6_ctr1_odd_mask                            (0x3FFFFFFF)
#define  EPI_EPI_LANE6_CTR1_ODATA_lane6_ctr1_odd(data)                           (0x3FFFFFFF&(data))
#define  EPI_EPI_LANE6_CTR1_ODATA_get_lane6_ctr1_odd(data)                       (0x3FFFFFFF&(data))

#define  EPI_EPI_LANE7_CTR1_EDATA                                                0x18026588
#define  EPI_EPI_LANE7_CTR1_EDATA_reg_addr                                       "0xB8026588"
#define  EPI_EPI_LANE7_CTR1_EDATA_reg                                            0xB8026588
#define  EPI_EPI_LANE7_CTR1_EDATA_inst_addr                                      "0x0075"
#define  set_EPI_EPI_LANE7_CTR1_EDATA_reg(data)                                  (*((volatile unsigned int*)EPI_EPI_LANE7_CTR1_EDATA_reg)=data)
#define  get_EPI_EPI_LANE7_CTR1_EDATA_reg                                        (*((volatile unsigned int*)EPI_EPI_LANE7_CTR1_EDATA_reg))
#define  EPI_EPI_LANE7_CTR1_EDATA_lane7_ctr1_oe_en_shift                         (30)
#define  EPI_EPI_LANE7_CTR1_EDATA_lane7_ctr1_even_shift                          (0)
#define  EPI_EPI_LANE7_CTR1_EDATA_lane7_ctr1_oe_en_mask                          (0x40000000)
#define  EPI_EPI_LANE7_CTR1_EDATA_lane7_ctr1_even_mask                           (0x3FFFFFFF)
#define  EPI_EPI_LANE7_CTR1_EDATA_lane7_ctr1_oe_en(data)                         (0x40000000&((data)<<30))
#define  EPI_EPI_LANE7_CTR1_EDATA_lane7_ctr1_even(data)                          (0x3FFFFFFF&(data))
#define  EPI_EPI_LANE7_CTR1_EDATA_get_lane7_ctr1_oe_en(data)                     ((0x40000000&(data))>>30)
#define  EPI_EPI_LANE7_CTR1_EDATA_get_lane7_ctr1_even(data)                      (0x3FFFFFFF&(data))

#define  EPI_EPI_LANE7_CTR1_ODATA                                                0x1802658C
#define  EPI_EPI_LANE7_CTR1_ODATA_reg_addr                                       "0xB802658C"
#define  EPI_EPI_LANE7_CTR1_ODATA_reg                                            0xB802658C
#define  EPI_EPI_LANE7_CTR1_ODATA_inst_addr                                      "0x0076"
#define  set_EPI_EPI_LANE7_CTR1_ODATA_reg(data)                                  (*((volatile unsigned int*)EPI_EPI_LANE7_CTR1_ODATA_reg)=data)
#define  get_EPI_EPI_LANE7_CTR1_ODATA_reg                                        (*((volatile unsigned int*)EPI_EPI_LANE7_CTR1_ODATA_reg))
#define  EPI_EPI_LANE7_CTR1_ODATA_lane7_ctr1_odd_shift                           (0)
#define  EPI_EPI_LANE7_CTR1_ODATA_lane7_ctr1_odd_mask                            (0x3FFFFFFF)
#define  EPI_EPI_LANE7_CTR1_ODATA_lane7_ctr1_odd(data)                           (0x3FFFFFFF&(data))
#define  EPI_EPI_LANE7_CTR1_ODATA_get_lane7_ctr1_odd(data)                       (0x3FFFFFFF&(data))

#define  EPI_EPI_LANE0_CTR2_EDATA                                                0x18026620
#define  EPI_EPI_LANE0_CTR2_EDATA_reg_addr                                       "0xB8026620"
#define  EPI_EPI_LANE0_CTR2_EDATA_reg                                            0xB8026620
#define  EPI_EPI_LANE0_CTR2_EDATA_inst_addr                                      "0x0077"
#define  set_EPI_EPI_LANE0_CTR2_EDATA_reg(data)                                  (*((volatile unsigned int*)EPI_EPI_LANE0_CTR2_EDATA_reg)=data)
#define  get_EPI_EPI_LANE0_CTR2_EDATA_reg                                        (*((volatile unsigned int*)EPI_EPI_LANE0_CTR2_EDATA_reg))
#define  EPI_EPI_LANE0_CTR2_EDATA_lane0_ctr2_oe_en_shift                         (30)
#define  EPI_EPI_LANE0_CTR2_EDATA_lane0_ctr2_even_shift                          (0)
#define  EPI_EPI_LANE0_CTR2_EDATA_lane0_ctr2_oe_en_mask                          (0x40000000)
#define  EPI_EPI_LANE0_CTR2_EDATA_lane0_ctr2_even_mask                           (0x3FFFFFFF)
#define  EPI_EPI_LANE0_CTR2_EDATA_lane0_ctr2_oe_en(data)                         (0x40000000&((data)<<30))
#define  EPI_EPI_LANE0_CTR2_EDATA_lane0_ctr2_even(data)                          (0x3FFFFFFF&(data))
#define  EPI_EPI_LANE0_CTR2_EDATA_get_lane0_ctr2_oe_en(data)                     ((0x40000000&(data))>>30)
#define  EPI_EPI_LANE0_CTR2_EDATA_get_lane0_ctr2_even(data)                      (0x3FFFFFFF&(data))

#define  EPI_EPI_LANE0_CTR2_ODATA                                                0x18026624
#define  EPI_EPI_LANE0_CTR2_ODATA_reg_addr                                       "0xB8026624"
#define  EPI_EPI_LANE0_CTR2_ODATA_reg                                            0xB8026624
#define  EPI_EPI_LANE0_CTR2_ODATA_inst_addr                                      "0x0078"
#define  set_EPI_EPI_LANE0_CTR2_ODATA_reg(data)                                  (*((volatile unsigned int*)EPI_EPI_LANE0_CTR2_ODATA_reg)=data)
#define  get_EPI_EPI_LANE0_CTR2_ODATA_reg                                        (*((volatile unsigned int*)EPI_EPI_LANE0_CTR2_ODATA_reg))
#define  EPI_EPI_LANE0_CTR2_ODATA_lane0_ctr2_odd_shift                           (0)
#define  EPI_EPI_LANE0_CTR2_ODATA_lane0_ctr2_odd_mask                            (0x3FFFFFFF)
#define  EPI_EPI_LANE0_CTR2_ODATA_lane0_ctr2_odd(data)                           (0x3FFFFFFF&(data))
#define  EPI_EPI_LANE0_CTR2_ODATA_get_lane0_ctr2_odd(data)                       (0x3FFFFFFF&(data))

#define  EPI_EPI_LANE1_CTR2_EDATA                                                0x18026628
#define  EPI_EPI_LANE1_CTR2_EDATA_reg_addr                                       "0xB8026628"
#define  EPI_EPI_LANE1_CTR2_EDATA_reg                                            0xB8026628
#define  EPI_EPI_LANE1_CTR2_EDATA_inst_addr                                      "0x0079"
#define  set_EPI_EPI_LANE1_CTR2_EDATA_reg(data)                                  (*((volatile unsigned int*)EPI_EPI_LANE1_CTR2_EDATA_reg)=data)
#define  get_EPI_EPI_LANE1_CTR2_EDATA_reg                                        (*((volatile unsigned int*)EPI_EPI_LANE1_CTR2_EDATA_reg))
#define  EPI_EPI_LANE1_CTR2_EDATA_lane1_ctr2_oe_en_shift                         (30)
#define  EPI_EPI_LANE1_CTR2_EDATA_lane1_ctr2_even_shift                          (0)
#define  EPI_EPI_LANE1_CTR2_EDATA_lane1_ctr2_oe_en_mask                          (0x40000000)
#define  EPI_EPI_LANE1_CTR2_EDATA_lane1_ctr2_even_mask                           (0x3FFFFFFF)
#define  EPI_EPI_LANE1_CTR2_EDATA_lane1_ctr2_oe_en(data)                         (0x40000000&((data)<<30))
#define  EPI_EPI_LANE1_CTR2_EDATA_lane1_ctr2_even(data)                          (0x3FFFFFFF&(data))
#define  EPI_EPI_LANE1_CTR2_EDATA_get_lane1_ctr2_oe_en(data)                     ((0x40000000&(data))>>30)
#define  EPI_EPI_LANE1_CTR2_EDATA_get_lane1_ctr2_even(data)                      (0x3FFFFFFF&(data))

#define  EPI_EPI_LANE1_CTR2_ODATA                                                0x1802662C
#define  EPI_EPI_LANE1_CTR2_ODATA_reg_addr                                       "0xB802662C"
#define  EPI_EPI_LANE1_CTR2_ODATA_reg                                            0xB802662C
#define  EPI_EPI_LANE1_CTR2_ODATA_inst_addr                                      "0x007A"
#define  set_EPI_EPI_LANE1_CTR2_ODATA_reg(data)                                  (*((volatile unsigned int*)EPI_EPI_LANE1_CTR2_ODATA_reg)=data)
#define  get_EPI_EPI_LANE1_CTR2_ODATA_reg                                        (*((volatile unsigned int*)EPI_EPI_LANE1_CTR2_ODATA_reg))
#define  EPI_EPI_LANE1_CTR2_ODATA_lane1_ctr2_odd_shift                           (0)
#define  EPI_EPI_LANE1_CTR2_ODATA_lane1_ctr2_odd_mask                            (0x3FFFFFFF)
#define  EPI_EPI_LANE1_CTR2_ODATA_lane1_ctr2_odd(data)                           (0x3FFFFFFF&(data))
#define  EPI_EPI_LANE1_CTR2_ODATA_get_lane1_ctr2_odd(data)                       (0x3FFFFFFF&(data))

#define  EPI_EPI_LANE2_CTR2_EDATA                                                0x18026630
#define  EPI_EPI_LANE2_CTR2_EDATA_reg_addr                                       "0xB8026630"
#define  EPI_EPI_LANE2_CTR2_EDATA_reg                                            0xB8026630
#define  EPI_EPI_LANE2_CTR2_EDATA_inst_addr                                      "0x007B"
#define  set_EPI_EPI_LANE2_CTR2_EDATA_reg(data)                                  (*((volatile unsigned int*)EPI_EPI_LANE2_CTR2_EDATA_reg)=data)
#define  get_EPI_EPI_LANE2_CTR2_EDATA_reg                                        (*((volatile unsigned int*)EPI_EPI_LANE2_CTR2_EDATA_reg))
#define  EPI_EPI_LANE2_CTR2_EDATA_lane2_ctr2_oe_en_shift                         (30)
#define  EPI_EPI_LANE2_CTR2_EDATA_lane2_ctr2_even_shift                          (0)
#define  EPI_EPI_LANE2_CTR2_EDATA_lane2_ctr2_oe_en_mask                          (0x40000000)
#define  EPI_EPI_LANE2_CTR2_EDATA_lane2_ctr2_even_mask                           (0x3FFFFFFF)
#define  EPI_EPI_LANE2_CTR2_EDATA_lane2_ctr2_oe_en(data)                         (0x40000000&((data)<<30))
#define  EPI_EPI_LANE2_CTR2_EDATA_lane2_ctr2_even(data)                          (0x3FFFFFFF&(data))
#define  EPI_EPI_LANE2_CTR2_EDATA_get_lane2_ctr2_oe_en(data)                     ((0x40000000&(data))>>30)
#define  EPI_EPI_LANE2_CTR2_EDATA_get_lane2_ctr2_even(data)                      (0x3FFFFFFF&(data))

#define  EPI_EPI_LANE2_CTR2_ODATA                                                0x18026634
#define  EPI_EPI_LANE2_CTR2_ODATA_reg_addr                                       "0xB8026634"
#define  EPI_EPI_LANE2_CTR2_ODATA_reg                                            0xB8026634
#define  EPI_EPI_LANE2_CTR2_ODATA_inst_addr                                      "0x007C"
#define  set_EPI_EPI_LANE2_CTR2_ODATA_reg(data)                                  (*((volatile unsigned int*)EPI_EPI_LANE2_CTR2_ODATA_reg)=data)
#define  get_EPI_EPI_LANE2_CTR2_ODATA_reg                                        (*((volatile unsigned int*)EPI_EPI_LANE2_CTR2_ODATA_reg))
#define  EPI_EPI_LANE2_CTR2_ODATA_lane2_ctr2_odd_shift                           (0)
#define  EPI_EPI_LANE2_CTR2_ODATA_lane2_ctr2_odd_mask                            (0x3FFFFFFF)
#define  EPI_EPI_LANE2_CTR2_ODATA_lane2_ctr2_odd(data)                           (0x3FFFFFFF&(data))
#define  EPI_EPI_LANE2_CTR2_ODATA_get_lane2_ctr2_odd(data)                       (0x3FFFFFFF&(data))

#define  EPI_EPI_LANE3_CTR2_EDATA                                                0x18026638
#define  EPI_EPI_LANE3_CTR2_EDATA_reg_addr                                       "0xB8026638"
#define  EPI_EPI_LANE3_CTR2_EDATA_reg                                            0xB8026638
#define  EPI_EPI_LANE3_CTR2_EDATA_inst_addr                                      "0x007D"
#define  set_EPI_EPI_LANE3_CTR2_EDATA_reg(data)                                  (*((volatile unsigned int*)EPI_EPI_LANE3_CTR2_EDATA_reg)=data)
#define  get_EPI_EPI_LANE3_CTR2_EDATA_reg                                        (*((volatile unsigned int*)EPI_EPI_LANE3_CTR2_EDATA_reg))
#define  EPI_EPI_LANE3_CTR2_EDATA_lane3_ctr2_oe_en_shift                         (30)
#define  EPI_EPI_LANE3_CTR2_EDATA_lane3_ctr2_even_shift                          (0)
#define  EPI_EPI_LANE3_CTR2_EDATA_lane3_ctr2_oe_en_mask                          (0x40000000)
#define  EPI_EPI_LANE3_CTR2_EDATA_lane3_ctr2_even_mask                           (0x3FFFFFFF)
#define  EPI_EPI_LANE3_CTR2_EDATA_lane3_ctr2_oe_en(data)                         (0x40000000&((data)<<30))
#define  EPI_EPI_LANE3_CTR2_EDATA_lane3_ctr2_even(data)                          (0x3FFFFFFF&(data))
#define  EPI_EPI_LANE3_CTR2_EDATA_get_lane3_ctr2_oe_en(data)                     ((0x40000000&(data))>>30)
#define  EPI_EPI_LANE3_CTR2_EDATA_get_lane3_ctr2_even(data)                      (0x3FFFFFFF&(data))

#define  EPI_EPI_LANE3_CTR2_ODATA                                                0x1802663C
#define  EPI_EPI_LANE3_CTR2_ODATA_reg_addr                                       "0xB802663C"
#define  EPI_EPI_LANE3_CTR2_ODATA_reg                                            0xB802663C
#define  EPI_EPI_LANE3_CTR2_ODATA_inst_addr                                      "0x007E"
#define  set_EPI_EPI_LANE3_CTR2_ODATA_reg(data)                                  (*((volatile unsigned int*)EPI_EPI_LANE3_CTR2_ODATA_reg)=data)
#define  get_EPI_EPI_LANE3_CTR2_ODATA_reg                                        (*((volatile unsigned int*)EPI_EPI_LANE3_CTR2_ODATA_reg))
#define  EPI_EPI_LANE3_CTR2_ODATA_lane3_ctr2_odd_shift                           (0)
#define  EPI_EPI_LANE3_CTR2_ODATA_lane3_ctr2_odd_mask                            (0x3FFFFFFF)
#define  EPI_EPI_LANE3_CTR2_ODATA_lane3_ctr2_odd(data)                           (0x3FFFFFFF&(data))
#define  EPI_EPI_LANE3_CTR2_ODATA_get_lane3_ctr2_odd(data)                       (0x3FFFFFFF&(data))

#define  EPI_EPI_LANE4_CTR2_EDATA                                                0x18026640
#define  EPI_EPI_LANE4_CTR2_EDATA_reg_addr                                       "0xB8026640"
#define  EPI_EPI_LANE4_CTR2_EDATA_reg                                            0xB8026640
#define  EPI_EPI_LANE4_CTR2_EDATA_inst_addr                                      "0x007F"
#define  set_EPI_EPI_LANE4_CTR2_EDATA_reg(data)                                  (*((volatile unsigned int*)EPI_EPI_LANE4_CTR2_EDATA_reg)=data)
#define  get_EPI_EPI_LANE4_CTR2_EDATA_reg                                        (*((volatile unsigned int*)EPI_EPI_LANE4_CTR2_EDATA_reg))
#define  EPI_EPI_LANE4_CTR2_EDATA_lane4_ctr2_oe_en_shift                         (30)
#define  EPI_EPI_LANE4_CTR2_EDATA_lane4_ctr2_even_shift                          (0)
#define  EPI_EPI_LANE4_CTR2_EDATA_lane4_ctr2_oe_en_mask                          (0x40000000)
#define  EPI_EPI_LANE4_CTR2_EDATA_lane4_ctr2_even_mask                           (0x3FFFFFFF)
#define  EPI_EPI_LANE4_CTR2_EDATA_lane4_ctr2_oe_en(data)                         (0x40000000&((data)<<30))
#define  EPI_EPI_LANE4_CTR2_EDATA_lane4_ctr2_even(data)                          (0x3FFFFFFF&(data))
#define  EPI_EPI_LANE4_CTR2_EDATA_get_lane4_ctr2_oe_en(data)                     ((0x40000000&(data))>>30)
#define  EPI_EPI_LANE4_CTR2_EDATA_get_lane4_ctr2_even(data)                      (0x3FFFFFFF&(data))

#define  EPI_EPI_LANE4_CTR2_ODATA                                                0x18026644
#define  EPI_EPI_LANE4_CTR2_ODATA_reg_addr                                       "0xB8026644"
#define  EPI_EPI_LANE4_CTR2_ODATA_reg                                            0xB8026644
#define  EPI_EPI_LANE4_CTR2_ODATA_inst_addr                                      "0x0080"
#define  set_EPI_EPI_LANE4_CTR2_ODATA_reg(data)                                  (*((volatile unsigned int*)EPI_EPI_LANE4_CTR2_ODATA_reg)=data)
#define  get_EPI_EPI_LANE4_CTR2_ODATA_reg                                        (*((volatile unsigned int*)EPI_EPI_LANE4_CTR2_ODATA_reg))
#define  EPI_EPI_LANE4_CTR2_ODATA_lane4_ctr2_odd_shift                           (0)
#define  EPI_EPI_LANE4_CTR2_ODATA_lane4_ctr2_odd_mask                            (0x3FFFFFFF)
#define  EPI_EPI_LANE4_CTR2_ODATA_lane4_ctr2_odd(data)                           (0x3FFFFFFF&(data))
#define  EPI_EPI_LANE4_CTR2_ODATA_get_lane4_ctr2_odd(data)                       (0x3FFFFFFF&(data))

#define  EPI_EPI_LANE5_CTR2_EDATA                                                0x18026648
#define  EPI_EPI_LANE5_CTR2_EDATA_reg_addr                                       "0xB8026648"
#define  EPI_EPI_LANE5_CTR2_EDATA_reg                                            0xB8026648
#define  EPI_EPI_LANE5_CTR2_EDATA_inst_addr                                      "0x0081"
#define  set_EPI_EPI_LANE5_CTR2_EDATA_reg(data)                                  (*((volatile unsigned int*)EPI_EPI_LANE5_CTR2_EDATA_reg)=data)
#define  get_EPI_EPI_LANE5_CTR2_EDATA_reg                                        (*((volatile unsigned int*)EPI_EPI_LANE5_CTR2_EDATA_reg))
#define  EPI_EPI_LANE5_CTR2_EDATA_lane5_ctr2_oe_en_shift                         (30)
#define  EPI_EPI_LANE5_CTR2_EDATA_lane5_ctr2_even_shift                          (0)
#define  EPI_EPI_LANE5_CTR2_EDATA_lane5_ctr2_oe_en_mask                          (0x40000000)
#define  EPI_EPI_LANE5_CTR2_EDATA_lane5_ctr2_even_mask                           (0x3FFFFFFF)
#define  EPI_EPI_LANE5_CTR2_EDATA_lane5_ctr2_oe_en(data)                         (0x40000000&((data)<<30))
#define  EPI_EPI_LANE5_CTR2_EDATA_lane5_ctr2_even(data)                          (0x3FFFFFFF&(data))
#define  EPI_EPI_LANE5_CTR2_EDATA_get_lane5_ctr2_oe_en(data)                     ((0x40000000&(data))>>30)
#define  EPI_EPI_LANE5_CTR2_EDATA_get_lane5_ctr2_even(data)                      (0x3FFFFFFF&(data))

#define  EPI_EPI_LANE5_CTR2_ODATA                                                0x1802664C
#define  EPI_EPI_LANE5_CTR2_ODATA_reg_addr                                       "0xB802664C"
#define  EPI_EPI_LANE5_CTR2_ODATA_reg                                            0xB802664C
#define  EPI_EPI_LANE5_CTR2_ODATA_inst_addr                                      "0x0082"
#define  set_EPI_EPI_LANE5_CTR2_ODATA_reg(data)                                  (*((volatile unsigned int*)EPI_EPI_LANE5_CTR2_ODATA_reg)=data)
#define  get_EPI_EPI_LANE5_CTR2_ODATA_reg                                        (*((volatile unsigned int*)EPI_EPI_LANE5_CTR2_ODATA_reg))
#define  EPI_EPI_LANE5_CTR2_ODATA_lane5_ctr2_odd_shift                           (0)
#define  EPI_EPI_LANE5_CTR2_ODATA_lane5_ctr2_odd_mask                            (0x3FFFFFFF)
#define  EPI_EPI_LANE5_CTR2_ODATA_lane5_ctr2_odd(data)                           (0x3FFFFFFF&(data))
#define  EPI_EPI_LANE5_CTR2_ODATA_get_lane5_ctr2_odd(data)                       (0x3FFFFFFF&(data))

#define  EPI_EPI_LANE6_CTR2_EDATA                                                0x18026650
#define  EPI_EPI_LANE6_CTR2_EDATA_reg_addr                                       "0xB8026650"
#define  EPI_EPI_LANE6_CTR2_EDATA_reg                                            0xB8026650
#define  EPI_EPI_LANE6_CTR2_EDATA_inst_addr                                      "0x0083"
#define  set_EPI_EPI_LANE6_CTR2_EDATA_reg(data)                                  (*((volatile unsigned int*)EPI_EPI_LANE6_CTR2_EDATA_reg)=data)
#define  get_EPI_EPI_LANE6_CTR2_EDATA_reg                                        (*((volatile unsigned int*)EPI_EPI_LANE6_CTR2_EDATA_reg))
#define  EPI_EPI_LANE6_CTR2_EDATA_lane6_ctr2_oe_en_shift                         (30)
#define  EPI_EPI_LANE6_CTR2_EDATA_lane6_ctr2_even_shift                          (0)
#define  EPI_EPI_LANE6_CTR2_EDATA_lane6_ctr2_oe_en_mask                          (0x40000000)
#define  EPI_EPI_LANE6_CTR2_EDATA_lane6_ctr2_even_mask                           (0x3FFFFFFF)
#define  EPI_EPI_LANE6_CTR2_EDATA_lane6_ctr2_oe_en(data)                         (0x40000000&((data)<<30))
#define  EPI_EPI_LANE6_CTR2_EDATA_lane6_ctr2_even(data)                          (0x3FFFFFFF&(data))
#define  EPI_EPI_LANE6_CTR2_EDATA_get_lane6_ctr2_oe_en(data)                     ((0x40000000&(data))>>30)
#define  EPI_EPI_LANE6_CTR2_EDATA_get_lane6_ctr2_even(data)                      (0x3FFFFFFF&(data))

#define  EPI_EPI_LANE6_CTR2_ODATA                                                0x18026654
#define  EPI_EPI_LANE6_CTR2_ODATA_reg_addr                                       "0xB8026654"
#define  EPI_EPI_LANE6_CTR2_ODATA_reg                                            0xB8026654
#define  EPI_EPI_LANE6_CTR2_ODATA_inst_addr                                      "0x0084"
#define  set_EPI_EPI_LANE6_CTR2_ODATA_reg(data)                                  (*((volatile unsigned int*)EPI_EPI_LANE6_CTR2_ODATA_reg)=data)
#define  get_EPI_EPI_LANE6_CTR2_ODATA_reg                                        (*((volatile unsigned int*)EPI_EPI_LANE6_CTR2_ODATA_reg))
#define  EPI_EPI_LANE6_CTR2_ODATA_lane6_ctr2_odd_shift                           (0)
#define  EPI_EPI_LANE6_CTR2_ODATA_lane6_ctr2_odd_mask                            (0x3FFFFFFF)
#define  EPI_EPI_LANE6_CTR2_ODATA_lane6_ctr2_odd(data)                           (0x3FFFFFFF&(data))
#define  EPI_EPI_LANE6_CTR2_ODATA_get_lane6_ctr2_odd(data)                       (0x3FFFFFFF&(data))

#define  EPI_EPI_LANE7_CTR2_EDATA                                                0x18026658
#define  EPI_EPI_LANE7_CTR2_EDATA_reg_addr                                       "0xB8026658"
#define  EPI_EPI_LANE7_CTR2_EDATA_reg                                            0xB8026658
#define  EPI_EPI_LANE7_CTR2_EDATA_inst_addr                                      "0x0085"
#define  set_EPI_EPI_LANE7_CTR2_EDATA_reg(data)                                  (*((volatile unsigned int*)EPI_EPI_LANE7_CTR2_EDATA_reg)=data)
#define  get_EPI_EPI_LANE7_CTR2_EDATA_reg                                        (*((volatile unsigned int*)EPI_EPI_LANE7_CTR2_EDATA_reg))
#define  EPI_EPI_LANE7_CTR2_EDATA_lane7_ctr2_oe_en_shift                         (30)
#define  EPI_EPI_LANE7_CTR2_EDATA_lane7_ctr2_even_shift                          (0)
#define  EPI_EPI_LANE7_CTR2_EDATA_lane7_ctr2_oe_en_mask                          (0x40000000)
#define  EPI_EPI_LANE7_CTR2_EDATA_lane7_ctr2_even_mask                           (0x3FFFFFFF)
#define  EPI_EPI_LANE7_CTR2_EDATA_lane7_ctr2_oe_en(data)                         (0x40000000&((data)<<30))
#define  EPI_EPI_LANE7_CTR2_EDATA_lane7_ctr2_even(data)                          (0x3FFFFFFF&(data))
#define  EPI_EPI_LANE7_CTR2_EDATA_get_lane7_ctr2_oe_en(data)                     ((0x40000000&(data))>>30)
#define  EPI_EPI_LANE7_CTR2_EDATA_get_lane7_ctr2_even(data)                      (0x3FFFFFFF&(data))

#define  EPI_EPI_LANE7_CTR2_ODATA                                                0x1802665C
#define  EPI_EPI_LANE7_CTR2_ODATA_reg_addr                                       "0xB802665C"
#define  EPI_EPI_LANE7_CTR2_ODATA_reg                                            0xB802665C
#define  EPI_EPI_LANE7_CTR2_ODATA_inst_addr                                      "0x0086"
#define  set_EPI_EPI_LANE7_CTR2_ODATA_reg(data)                                  (*((volatile unsigned int*)EPI_EPI_LANE7_CTR2_ODATA_reg)=data)
#define  get_EPI_EPI_LANE7_CTR2_ODATA_reg                                        (*((volatile unsigned int*)EPI_EPI_LANE7_CTR2_ODATA_reg))
#define  EPI_EPI_LANE7_CTR2_ODATA_lane7_ctr2_odd_shift                           (0)
#define  EPI_EPI_LANE7_CTR2_ODATA_lane7_ctr2_odd_mask                            (0x3FFFFFFF)
#define  EPI_EPI_LANE7_CTR2_ODATA_lane7_ctr2_odd(data)                           (0x3FFFFFFF&(data))
#define  EPI_EPI_LANE7_CTR2_ODATA_get_lane7_ctr2_odd(data)                       (0x3FFFFFFF&(data))

#define  EPI_EPI_LANE0_CTR3_EDATA                                                0x180266F0
#define  EPI_EPI_LANE0_CTR3_EDATA_reg_addr                                       "0xB80266F0"
#define  EPI_EPI_LANE0_CTR3_EDATA_reg                                            0xB80266F0
#define  EPI_EPI_LANE0_CTR3_EDATA_inst_addr                                      "0x0087"
#define  set_EPI_EPI_LANE0_CTR3_EDATA_reg(data)                                  (*((volatile unsigned int*)EPI_EPI_LANE0_CTR3_EDATA_reg)=data)
#define  get_EPI_EPI_LANE0_CTR3_EDATA_reg                                        (*((volatile unsigned int*)EPI_EPI_LANE0_CTR3_EDATA_reg))
#define  EPI_EPI_LANE0_CTR3_EDATA_lane0_ctr3_oe_en_shift                         (30)
#define  EPI_EPI_LANE0_CTR3_EDATA_lane0_ctr3_even_shift                          (0)
#define  EPI_EPI_LANE0_CTR3_EDATA_lane0_ctr3_oe_en_mask                          (0x40000000)
#define  EPI_EPI_LANE0_CTR3_EDATA_lane0_ctr3_even_mask                           (0x3FFFFFFF)
#define  EPI_EPI_LANE0_CTR3_EDATA_lane0_ctr3_oe_en(data)                         (0x40000000&((data)<<30))
#define  EPI_EPI_LANE0_CTR3_EDATA_lane0_ctr3_even(data)                          (0x3FFFFFFF&(data))
#define  EPI_EPI_LANE0_CTR3_EDATA_get_lane0_ctr3_oe_en(data)                     ((0x40000000&(data))>>30)
#define  EPI_EPI_LANE0_CTR3_EDATA_get_lane0_ctr3_even(data)                      (0x3FFFFFFF&(data))

#define  EPI_EPI_LANE0_CTR3_ODATA                                                0x180266F4
#define  EPI_EPI_LANE0_CTR3_ODATA_reg_addr                                       "0xB80266F4"
#define  EPI_EPI_LANE0_CTR3_ODATA_reg                                            0xB80266F4
#define  EPI_EPI_LANE0_CTR3_ODATA_inst_addr                                      "0x0088"
#define  set_EPI_EPI_LANE0_CTR3_ODATA_reg(data)                                  (*((volatile unsigned int*)EPI_EPI_LANE0_CTR3_ODATA_reg)=data)
#define  get_EPI_EPI_LANE0_CTR3_ODATA_reg                                        (*((volatile unsigned int*)EPI_EPI_LANE0_CTR3_ODATA_reg))
#define  EPI_EPI_LANE0_CTR3_ODATA_lane0_ctr3_odd_shift                           (0)
#define  EPI_EPI_LANE0_CTR3_ODATA_lane0_ctr3_odd_mask                            (0x3FFFFFFF)
#define  EPI_EPI_LANE0_CTR3_ODATA_lane0_ctr3_odd(data)                           (0x3FFFFFFF&(data))
#define  EPI_EPI_LANE0_CTR3_ODATA_get_lane0_ctr3_odd(data)                       (0x3FFFFFFF&(data))

#define  EPI_EPI_LANE1_CTR3_EDATA                                                0x180266F8
#define  EPI_EPI_LANE1_CTR3_EDATA_reg_addr                                       "0xB80266F8"
#define  EPI_EPI_LANE1_CTR3_EDATA_reg                                            0xB80266F8
#define  EPI_EPI_LANE1_CTR3_EDATA_inst_addr                                      "0x0089"
#define  set_EPI_EPI_LANE1_CTR3_EDATA_reg(data)                                  (*((volatile unsigned int*)EPI_EPI_LANE1_CTR3_EDATA_reg)=data)
#define  get_EPI_EPI_LANE1_CTR3_EDATA_reg                                        (*((volatile unsigned int*)EPI_EPI_LANE1_CTR3_EDATA_reg))
#define  EPI_EPI_LANE1_CTR3_EDATA_lane1_ctr3_oe_en_shift                         (30)
#define  EPI_EPI_LANE1_CTR3_EDATA_lane1_ctr3_even_shift                          (0)
#define  EPI_EPI_LANE1_CTR3_EDATA_lane1_ctr3_oe_en_mask                          (0x40000000)
#define  EPI_EPI_LANE1_CTR3_EDATA_lane1_ctr3_even_mask                           (0x3FFFFFFF)
#define  EPI_EPI_LANE1_CTR3_EDATA_lane1_ctr3_oe_en(data)                         (0x40000000&((data)<<30))
#define  EPI_EPI_LANE1_CTR3_EDATA_lane1_ctr3_even(data)                          (0x3FFFFFFF&(data))
#define  EPI_EPI_LANE1_CTR3_EDATA_get_lane1_ctr3_oe_en(data)                     ((0x40000000&(data))>>30)
#define  EPI_EPI_LANE1_CTR3_EDATA_get_lane1_ctr3_even(data)                      (0x3FFFFFFF&(data))

#define  EPI_EPI_LANE1_CTR3_ODATA                                                0x180266FC
#define  EPI_EPI_LANE1_CTR3_ODATA_reg_addr                                       "0xB80266FC"
#define  EPI_EPI_LANE1_CTR3_ODATA_reg                                            0xB80266FC
#define  EPI_EPI_LANE1_CTR3_ODATA_inst_addr                                      "0x008A"
#define  set_EPI_EPI_LANE1_CTR3_ODATA_reg(data)                                  (*((volatile unsigned int*)EPI_EPI_LANE1_CTR3_ODATA_reg)=data)
#define  get_EPI_EPI_LANE1_CTR3_ODATA_reg                                        (*((volatile unsigned int*)EPI_EPI_LANE1_CTR3_ODATA_reg))
#define  EPI_EPI_LANE1_CTR3_ODATA_lane1_ctr3_odd_shift                           (0)
#define  EPI_EPI_LANE1_CTR3_ODATA_lane1_ctr3_odd_mask                            (0x3FFFFFFF)
#define  EPI_EPI_LANE1_CTR3_ODATA_lane1_ctr3_odd(data)                           (0x3FFFFFFF&(data))
#define  EPI_EPI_LANE1_CTR3_ODATA_get_lane1_ctr3_odd(data)                       (0x3FFFFFFF&(data))

#define  EPI_EPI_LANE2_CTR3_EDATA                                                0x18026700
#define  EPI_EPI_LANE2_CTR3_EDATA_reg_addr                                       "0xB8026700"
#define  EPI_EPI_LANE2_CTR3_EDATA_reg                                            0xB8026700
#define  EPI_EPI_LANE2_CTR3_EDATA_inst_addr                                      "0x008B"
#define  set_EPI_EPI_LANE2_CTR3_EDATA_reg(data)                                  (*((volatile unsigned int*)EPI_EPI_LANE2_CTR3_EDATA_reg)=data)
#define  get_EPI_EPI_LANE2_CTR3_EDATA_reg                                        (*((volatile unsigned int*)EPI_EPI_LANE2_CTR3_EDATA_reg))
#define  EPI_EPI_LANE2_CTR3_EDATA_lane2_ctr3_oe_en_shift                         (30)
#define  EPI_EPI_LANE2_CTR3_EDATA_lane2_ctr3_even_shift                          (0)
#define  EPI_EPI_LANE2_CTR3_EDATA_lane2_ctr3_oe_en_mask                          (0x40000000)
#define  EPI_EPI_LANE2_CTR3_EDATA_lane2_ctr3_even_mask                           (0x3FFFFFFF)
#define  EPI_EPI_LANE2_CTR3_EDATA_lane2_ctr3_oe_en(data)                         (0x40000000&((data)<<30))
#define  EPI_EPI_LANE2_CTR3_EDATA_lane2_ctr3_even(data)                          (0x3FFFFFFF&(data))
#define  EPI_EPI_LANE2_CTR3_EDATA_get_lane2_ctr3_oe_en(data)                     ((0x40000000&(data))>>30)
#define  EPI_EPI_LANE2_CTR3_EDATA_get_lane2_ctr3_even(data)                      (0x3FFFFFFF&(data))

#define  EPI_EPI_LANE2_CTR3_ODATA                                                0x18026704
#define  EPI_EPI_LANE2_CTR3_ODATA_reg_addr                                       "0xB8026704"
#define  EPI_EPI_LANE2_CTR3_ODATA_reg                                            0xB8026704
#define  EPI_EPI_LANE2_CTR3_ODATA_inst_addr                                      "0x008C"
#define  set_EPI_EPI_LANE2_CTR3_ODATA_reg(data)                                  (*((volatile unsigned int*)EPI_EPI_LANE2_CTR3_ODATA_reg)=data)
#define  get_EPI_EPI_LANE2_CTR3_ODATA_reg                                        (*((volatile unsigned int*)EPI_EPI_LANE2_CTR3_ODATA_reg))
#define  EPI_EPI_LANE2_CTR3_ODATA_lane2_ctr3_odd_shift                           (0)
#define  EPI_EPI_LANE2_CTR3_ODATA_lane2_ctr3_odd_mask                            (0x3FFFFFFF)
#define  EPI_EPI_LANE2_CTR3_ODATA_lane2_ctr3_odd(data)                           (0x3FFFFFFF&(data))
#define  EPI_EPI_LANE2_CTR3_ODATA_get_lane2_ctr3_odd(data)                       (0x3FFFFFFF&(data))

#define  EPI_EPI_LANE3_CTR3_EDATA                                                0x18026708
#define  EPI_EPI_LANE3_CTR3_EDATA_reg_addr                                       "0xB8026708"
#define  EPI_EPI_LANE3_CTR3_EDATA_reg                                            0xB8026708
#define  EPI_EPI_LANE3_CTR3_EDATA_inst_addr                                      "0x008D"
#define  set_EPI_EPI_LANE3_CTR3_EDATA_reg(data)                                  (*((volatile unsigned int*)EPI_EPI_LANE3_CTR3_EDATA_reg)=data)
#define  get_EPI_EPI_LANE3_CTR3_EDATA_reg                                        (*((volatile unsigned int*)EPI_EPI_LANE3_CTR3_EDATA_reg))
#define  EPI_EPI_LANE3_CTR3_EDATA_lane3_ctr3_oe_en_shift                         (30)
#define  EPI_EPI_LANE3_CTR3_EDATA_lane3_ctr3_even_shift                          (0)
#define  EPI_EPI_LANE3_CTR3_EDATA_lane3_ctr3_oe_en_mask                          (0x40000000)
#define  EPI_EPI_LANE3_CTR3_EDATA_lane3_ctr3_even_mask                           (0x3FFFFFFF)
#define  EPI_EPI_LANE3_CTR3_EDATA_lane3_ctr3_oe_en(data)                         (0x40000000&((data)<<30))
#define  EPI_EPI_LANE3_CTR3_EDATA_lane3_ctr3_even(data)                          (0x3FFFFFFF&(data))
#define  EPI_EPI_LANE3_CTR3_EDATA_get_lane3_ctr3_oe_en(data)                     ((0x40000000&(data))>>30)
#define  EPI_EPI_LANE3_CTR3_EDATA_get_lane3_ctr3_even(data)                      (0x3FFFFFFF&(data))

#define  EPI_EPI_LANE3_CTR3_ODATA                                                0x1802670C
#define  EPI_EPI_LANE3_CTR3_ODATA_reg_addr                                       "0xB802670C"
#define  EPI_EPI_LANE3_CTR3_ODATA_reg                                            0xB802670C
#define  EPI_EPI_LANE3_CTR3_ODATA_inst_addr                                      "0x008E"
#define  set_EPI_EPI_LANE3_CTR3_ODATA_reg(data)                                  (*((volatile unsigned int*)EPI_EPI_LANE3_CTR3_ODATA_reg)=data)
#define  get_EPI_EPI_LANE3_CTR3_ODATA_reg                                        (*((volatile unsigned int*)EPI_EPI_LANE3_CTR3_ODATA_reg))
#define  EPI_EPI_LANE3_CTR3_ODATA_lane3_ctr3_odd_shift                           (0)
#define  EPI_EPI_LANE3_CTR3_ODATA_lane3_ctr3_odd_mask                            (0x3FFFFFFF)
#define  EPI_EPI_LANE3_CTR3_ODATA_lane3_ctr3_odd(data)                           (0x3FFFFFFF&(data))
#define  EPI_EPI_LANE3_CTR3_ODATA_get_lane3_ctr3_odd(data)                       (0x3FFFFFFF&(data))

#define  EPI_EPI_LANE4_CTR3_EDATA                                                0x18026710
#define  EPI_EPI_LANE4_CTR3_EDATA_reg_addr                                       "0xB8026710"
#define  EPI_EPI_LANE4_CTR3_EDATA_reg                                            0xB8026710
#define  EPI_EPI_LANE4_CTR3_EDATA_inst_addr                                      "0x008F"
#define  set_EPI_EPI_LANE4_CTR3_EDATA_reg(data)                                  (*((volatile unsigned int*)EPI_EPI_LANE4_CTR3_EDATA_reg)=data)
#define  get_EPI_EPI_LANE4_CTR3_EDATA_reg                                        (*((volatile unsigned int*)EPI_EPI_LANE4_CTR3_EDATA_reg))
#define  EPI_EPI_LANE4_CTR3_EDATA_lane4_ctr3_oe_en_shift                         (30)
#define  EPI_EPI_LANE4_CTR3_EDATA_lane4_ctr3_even_shift                          (0)
#define  EPI_EPI_LANE4_CTR3_EDATA_lane4_ctr3_oe_en_mask                          (0x40000000)
#define  EPI_EPI_LANE4_CTR3_EDATA_lane4_ctr3_even_mask                           (0x3FFFFFFF)
#define  EPI_EPI_LANE4_CTR3_EDATA_lane4_ctr3_oe_en(data)                         (0x40000000&((data)<<30))
#define  EPI_EPI_LANE4_CTR3_EDATA_lane4_ctr3_even(data)                          (0x3FFFFFFF&(data))
#define  EPI_EPI_LANE4_CTR3_EDATA_get_lane4_ctr3_oe_en(data)                     ((0x40000000&(data))>>30)
#define  EPI_EPI_LANE4_CTR3_EDATA_get_lane4_ctr3_even(data)                      (0x3FFFFFFF&(data))

#define  EPI_EPI_LANE4_CTR3_ODATA                                                0x18026714
#define  EPI_EPI_LANE4_CTR3_ODATA_reg_addr                                       "0xB8026714"
#define  EPI_EPI_LANE4_CTR3_ODATA_reg                                            0xB8026714
#define  EPI_EPI_LANE4_CTR3_ODATA_inst_addr                                      "0x0090"
#define  set_EPI_EPI_LANE4_CTR3_ODATA_reg(data)                                  (*((volatile unsigned int*)EPI_EPI_LANE4_CTR3_ODATA_reg)=data)
#define  get_EPI_EPI_LANE4_CTR3_ODATA_reg                                        (*((volatile unsigned int*)EPI_EPI_LANE4_CTR3_ODATA_reg))
#define  EPI_EPI_LANE4_CTR3_ODATA_lane4_ctr3_odd_shift                           (0)
#define  EPI_EPI_LANE4_CTR3_ODATA_lane4_ctr3_odd_mask                            (0x3FFFFFFF)
#define  EPI_EPI_LANE4_CTR3_ODATA_lane4_ctr3_odd(data)                           (0x3FFFFFFF&(data))
#define  EPI_EPI_LANE4_CTR3_ODATA_get_lane4_ctr3_odd(data)                       (0x3FFFFFFF&(data))

#define  EPI_EPI_LANE5_CTR3_EDATA                                                0x18026718
#define  EPI_EPI_LANE5_CTR3_EDATA_reg_addr                                       "0xB8026718"
#define  EPI_EPI_LANE5_CTR3_EDATA_reg                                            0xB8026718
#define  EPI_EPI_LANE5_CTR3_EDATA_inst_addr                                      "0x0091"
#define  set_EPI_EPI_LANE5_CTR3_EDATA_reg(data)                                  (*((volatile unsigned int*)EPI_EPI_LANE5_CTR3_EDATA_reg)=data)
#define  get_EPI_EPI_LANE5_CTR3_EDATA_reg                                        (*((volatile unsigned int*)EPI_EPI_LANE5_CTR3_EDATA_reg))
#define  EPI_EPI_LANE5_CTR3_EDATA_lane5_ctr3_oe_en_shift                         (30)
#define  EPI_EPI_LANE5_CTR3_EDATA_lane5_ctr3_even_shift                          (0)
#define  EPI_EPI_LANE5_CTR3_EDATA_lane5_ctr3_oe_en_mask                          (0x40000000)
#define  EPI_EPI_LANE5_CTR3_EDATA_lane5_ctr3_even_mask                           (0x3FFFFFFF)
#define  EPI_EPI_LANE5_CTR3_EDATA_lane5_ctr3_oe_en(data)                         (0x40000000&((data)<<30))
#define  EPI_EPI_LANE5_CTR3_EDATA_lane5_ctr3_even(data)                          (0x3FFFFFFF&(data))
#define  EPI_EPI_LANE5_CTR3_EDATA_get_lane5_ctr3_oe_en(data)                     ((0x40000000&(data))>>30)
#define  EPI_EPI_LANE5_CTR3_EDATA_get_lane5_ctr3_even(data)                      (0x3FFFFFFF&(data))

#define  EPI_EPI_LANE5_CTR3_ODATA                                                0x1802671C
#define  EPI_EPI_LANE5_CTR3_ODATA_reg_addr                                       "0xB802671C"
#define  EPI_EPI_LANE5_CTR3_ODATA_reg                                            0xB802671C
#define  EPI_EPI_LANE5_CTR3_ODATA_inst_addr                                      "0x0092"
#define  set_EPI_EPI_LANE5_CTR3_ODATA_reg(data)                                  (*((volatile unsigned int*)EPI_EPI_LANE5_CTR3_ODATA_reg)=data)
#define  get_EPI_EPI_LANE5_CTR3_ODATA_reg                                        (*((volatile unsigned int*)EPI_EPI_LANE5_CTR3_ODATA_reg))
#define  EPI_EPI_LANE5_CTR3_ODATA_lane5_ctr3_odd_shift                           (0)
#define  EPI_EPI_LANE5_CTR3_ODATA_lane5_ctr3_odd_mask                            (0x3FFFFFFF)
#define  EPI_EPI_LANE5_CTR3_ODATA_lane5_ctr3_odd(data)                           (0x3FFFFFFF&(data))
#define  EPI_EPI_LANE5_CTR3_ODATA_get_lane5_ctr3_odd(data)                       (0x3FFFFFFF&(data))

#define  EPI_EPI_LANE6_CTR3_EDATA                                                0x18026720
#define  EPI_EPI_LANE6_CTR3_EDATA_reg_addr                                       "0xB8026720"
#define  EPI_EPI_LANE6_CTR3_EDATA_reg                                            0xB8026720
#define  EPI_EPI_LANE6_CTR3_EDATA_inst_addr                                      "0x0093"
#define  set_EPI_EPI_LANE6_CTR3_EDATA_reg(data)                                  (*((volatile unsigned int*)EPI_EPI_LANE6_CTR3_EDATA_reg)=data)
#define  get_EPI_EPI_LANE6_CTR3_EDATA_reg                                        (*((volatile unsigned int*)EPI_EPI_LANE6_CTR3_EDATA_reg))
#define  EPI_EPI_LANE6_CTR3_EDATA_lane6_ctr3_oe_en_shift                         (30)
#define  EPI_EPI_LANE6_CTR3_EDATA_lane6_ctr3_even_shift                          (0)
#define  EPI_EPI_LANE6_CTR3_EDATA_lane6_ctr3_oe_en_mask                          (0x40000000)
#define  EPI_EPI_LANE6_CTR3_EDATA_lane6_ctr3_even_mask                           (0x3FFFFFFF)
#define  EPI_EPI_LANE6_CTR3_EDATA_lane6_ctr3_oe_en(data)                         (0x40000000&((data)<<30))
#define  EPI_EPI_LANE6_CTR3_EDATA_lane6_ctr3_even(data)                          (0x3FFFFFFF&(data))
#define  EPI_EPI_LANE6_CTR3_EDATA_get_lane6_ctr3_oe_en(data)                     ((0x40000000&(data))>>30)
#define  EPI_EPI_LANE6_CTR3_EDATA_get_lane6_ctr3_even(data)                      (0x3FFFFFFF&(data))

#define  EPI_EPI_LANE6_CTR3_ODATA                                                0x18026724
#define  EPI_EPI_LANE6_CTR3_ODATA_reg_addr                                       "0xB8026724"
#define  EPI_EPI_LANE6_CTR3_ODATA_reg                                            0xB8026724
#define  EPI_EPI_LANE6_CTR3_ODATA_inst_addr                                      "0x0094"
#define  set_EPI_EPI_LANE6_CTR3_ODATA_reg(data)                                  (*((volatile unsigned int*)EPI_EPI_LANE6_CTR3_ODATA_reg)=data)
#define  get_EPI_EPI_LANE6_CTR3_ODATA_reg                                        (*((volatile unsigned int*)EPI_EPI_LANE6_CTR3_ODATA_reg))
#define  EPI_EPI_LANE6_CTR3_ODATA_lane6_ctr3_odd_shift                           (0)
#define  EPI_EPI_LANE6_CTR3_ODATA_lane6_ctr3_odd_mask                            (0x3FFFFFFF)
#define  EPI_EPI_LANE6_CTR3_ODATA_lane6_ctr3_odd(data)                           (0x3FFFFFFF&(data))
#define  EPI_EPI_LANE6_CTR3_ODATA_get_lane6_ctr3_odd(data)                       (0x3FFFFFFF&(data))

#define  EPI_EPI_LANE7_CTR3_EDATA                                                0x18026728
#define  EPI_EPI_LANE7_CTR3_EDATA_reg_addr                                       "0xB8026728"
#define  EPI_EPI_LANE7_CTR3_EDATA_reg                                            0xB8026728
#define  EPI_EPI_LANE7_CTR3_EDATA_inst_addr                                      "0x0095"
#define  set_EPI_EPI_LANE7_CTR3_EDATA_reg(data)                                  (*((volatile unsigned int*)EPI_EPI_LANE7_CTR3_EDATA_reg)=data)
#define  get_EPI_EPI_LANE7_CTR3_EDATA_reg                                        (*((volatile unsigned int*)EPI_EPI_LANE7_CTR3_EDATA_reg))
#define  EPI_EPI_LANE7_CTR3_EDATA_lane7_ctr3_oe_en_shift                         (30)
#define  EPI_EPI_LANE7_CTR3_EDATA_lane7_ctr3_even_shift                          (0)
#define  EPI_EPI_LANE7_CTR3_EDATA_lane7_ctr3_oe_en_mask                          (0x40000000)
#define  EPI_EPI_LANE7_CTR3_EDATA_lane7_ctr3_even_mask                           (0x3FFFFFFF)
#define  EPI_EPI_LANE7_CTR3_EDATA_lane7_ctr3_oe_en(data)                         (0x40000000&((data)<<30))
#define  EPI_EPI_LANE7_CTR3_EDATA_lane7_ctr3_even(data)                          (0x3FFFFFFF&(data))
#define  EPI_EPI_LANE7_CTR3_EDATA_get_lane7_ctr3_oe_en(data)                     ((0x40000000&(data))>>30)
#define  EPI_EPI_LANE7_CTR3_EDATA_get_lane7_ctr3_even(data)                      (0x3FFFFFFF&(data))

#define  EPI_EPI_LANE7_CTR3_ODATA                                                0x1802672C
#define  EPI_EPI_LANE7_CTR3_ODATA_reg_addr                                       "0xB802672C"
#define  EPI_EPI_LANE7_CTR3_ODATA_reg                                            0xB802672C
#define  EPI_EPI_LANE7_CTR3_ODATA_inst_addr                                      "0x0096"
#define  set_EPI_EPI_LANE7_CTR3_ODATA_reg(data)                                  (*((volatile unsigned int*)EPI_EPI_LANE7_CTR3_ODATA_reg)=data)
#define  get_EPI_EPI_LANE7_CTR3_ODATA_reg                                        (*((volatile unsigned int*)EPI_EPI_LANE7_CTR3_ODATA_reg))
#define  EPI_EPI_LANE7_CTR3_ODATA_lane7_ctr3_odd_shift                           (0)
#define  EPI_EPI_LANE7_CTR3_ODATA_lane7_ctr3_odd_mask                            (0x3FFFFFFF)
#define  EPI_EPI_LANE7_CTR3_ODATA_lane7_ctr3_odd(data)                           (0x3FFFFFFF&(data))
#define  EPI_EPI_LANE7_CTR3_ODATA_get_lane7_ctr3_odd(data)                       (0x3FFFFFFF&(data))

#define  EPI_EPI_GPLUT_CONTROL                                                   0x18026450
#define  EPI_EPI_GPLUT_CONTROL_reg_addr                                          "0xB8026450"
#define  EPI_EPI_GPLUT_CONTROL_reg                                               0xB8026450
#define  EPI_EPI_GPLUT_CONTROL_inst_addr                                         "0x0097"
#define  set_EPI_EPI_GPLUT_CONTROL_reg(data)                                     (*((volatile unsigned int*)EPI_EPI_GPLUT_CONTROL_reg)=data)
#define  get_EPI_EPI_GPLUT_CONTROL_reg                                           (*((volatile unsigned int*)EPI_EPI_GPLUT_CONTROL_reg))
#define  EPI_EPI_GPLUT_CONTROL_gp_table_line_cycle_shift                         (0)
#define  EPI_EPI_GPLUT_CONTROL_gp_table_line_cycle_mask                          (0x0000000F)
#define  EPI_EPI_GPLUT_CONTROL_gp_table_line_cycle(data)                         (0x0000000F&(data))
#define  EPI_EPI_GPLUT_CONTROL_get_gp_table_line_cycle(data)                     (0x0000000F&(data))

#define  EPI_EPI_GPLUT_LINE_01                                                   0x18026454
#define  EPI_EPI_GPLUT_LINE_01_reg_addr                                          "0xB8026454"
#define  EPI_EPI_GPLUT_LINE_01_reg                                               0xB8026454
#define  EPI_EPI_GPLUT_LINE_01_inst_addr                                         "0x0098"
#define  set_EPI_EPI_GPLUT_LINE_01_reg(data)                                     (*((volatile unsigned int*)EPI_EPI_GPLUT_LINE_01_reg)=data)
#define  get_EPI_EPI_GPLUT_LINE_01_reg                                           (*((volatile unsigned int*)EPI_EPI_GPLUT_LINE_01_reg))
#define  EPI_EPI_GPLUT_LINE_01_gp_table_line_1_shift                             (16)
#define  EPI_EPI_GPLUT_LINE_01_gp_table_line_0_shift                             (0)
#define  EPI_EPI_GPLUT_LINE_01_gp_table_line_1_mask                              (0xFFFF0000)
#define  EPI_EPI_GPLUT_LINE_01_gp_table_line_0_mask                              (0x0000FFFF)
#define  EPI_EPI_GPLUT_LINE_01_gp_table_line_1(data)                             (0xFFFF0000&((data)<<16))
#define  EPI_EPI_GPLUT_LINE_01_gp_table_line_0(data)                             (0x0000FFFF&(data))
#define  EPI_EPI_GPLUT_LINE_01_get_gp_table_line_1(data)                         ((0xFFFF0000&(data))>>16)
#define  EPI_EPI_GPLUT_LINE_01_get_gp_table_line_0(data)                         (0x0000FFFF&(data))

#define  EPI_EPI_GPLUT_LINE_23                                                   0x18026458
#define  EPI_EPI_GPLUT_LINE_23_reg_addr                                          "0xB8026458"
#define  EPI_EPI_GPLUT_LINE_23_reg                                               0xB8026458
#define  EPI_EPI_GPLUT_LINE_23_inst_addr                                         "0x0099"
#define  set_EPI_EPI_GPLUT_LINE_23_reg(data)                                     (*((volatile unsigned int*)EPI_EPI_GPLUT_LINE_23_reg)=data)
#define  get_EPI_EPI_GPLUT_LINE_23_reg                                           (*((volatile unsigned int*)EPI_EPI_GPLUT_LINE_23_reg))
#define  EPI_EPI_GPLUT_LINE_23_gp_table_line_3_shift                             (16)
#define  EPI_EPI_GPLUT_LINE_23_gp_table_line_2_shift                             (0)
#define  EPI_EPI_GPLUT_LINE_23_gp_table_line_3_mask                              (0xFFFF0000)
#define  EPI_EPI_GPLUT_LINE_23_gp_table_line_2_mask                              (0x0000FFFF)
#define  EPI_EPI_GPLUT_LINE_23_gp_table_line_3(data)                             (0xFFFF0000&((data)<<16))
#define  EPI_EPI_GPLUT_LINE_23_gp_table_line_2(data)                             (0x0000FFFF&(data))
#define  EPI_EPI_GPLUT_LINE_23_get_gp_table_line_3(data)                         ((0xFFFF0000&(data))>>16)
#define  EPI_EPI_GPLUT_LINE_23_get_gp_table_line_2(data)                         (0x0000FFFF&(data))

#define  EPI_EPI_GPLUT_LINE_45                                                   0x1802645C
#define  EPI_EPI_GPLUT_LINE_45_reg_addr                                          "0xB802645C"
#define  EPI_EPI_GPLUT_LINE_45_reg                                               0xB802645C
#define  EPI_EPI_GPLUT_LINE_45_inst_addr                                         "0x009A"
#define  set_EPI_EPI_GPLUT_LINE_45_reg(data)                                     (*((volatile unsigned int*)EPI_EPI_GPLUT_LINE_45_reg)=data)
#define  get_EPI_EPI_GPLUT_LINE_45_reg                                           (*((volatile unsigned int*)EPI_EPI_GPLUT_LINE_45_reg))
#define  EPI_EPI_GPLUT_LINE_45_gp_table_line_5_shift                             (16)
#define  EPI_EPI_GPLUT_LINE_45_gp_table_line_4_shift                             (0)
#define  EPI_EPI_GPLUT_LINE_45_gp_table_line_5_mask                              (0xFFFF0000)
#define  EPI_EPI_GPLUT_LINE_45_gp_table_line_4_mask                              (0x0000FFFF)
#define  EPI_EPI_GPLUT_LINE_45_gp_table_line_5(data)                             (0xFFFF0000&((data)<<16))
#define  EPI_EPI_GPLUT_LINE_45_gp_table_line_4(data)                             (0x0000FFFF&(data))
#define  EPI_EPI_GPLUT_LINE_45_get_gp_table_line_5(data)                         ((0xFFFF0000&(data))>>16)
#define  EPI_EPI_GPLUT_LINE_45_get_gp_table_line_4(data)                         (0x0000FFFF&(data))

#define  EPI_EPI_GPLUT_LINE_67                                                   0x18026460
#define  EPI_EPI_GPLUT_LINE_67_reg_addr                                          "0xB8026460"
#define  EPI_EPI_GPLUT_LINE_67_reg                                               0xB8026460
#define  EPI_EPI_GPLUT_LINE_67_inst_addr                                         "0x009B"
#define  set_EPI_EPI_GPLUT_LINE_67_reg(data)                                     (*((volatile unsigned int*)EPI_EPI_GPLUT_LINE_67_reg)=data)
#define  get_EPI_EPI_GPLUT_LINE_67_reg                                           (*((volatile unsigned int*)EPI_EPI_GPLUT_LINE_67_reg))
#define  EPI_EPI_GPLUT_LINE_67_gp_table_line_7_shift                             (16)
#define  EPI_EPI_GPLUT_LINE_67_gp_table_line_6_shift                             (0)
#define  EPI_EPI_GPLUT_LINE_67_gp_table_line_7_mask                              (0xFFFF0000)
#define  EPI_EPI_GPLUT_LINE_67_gp_table_line_6_mask                              (0x0000FFFF)
#define  EPI_EPI_GPLUT_LINE_67_gp_table_line_7(data)                             (0xFFFF0000&((data)<<16))
#define  EPI_EPI_GPLUT_LINE_67_gp_table_line_6(data)                             (0x0000FFFF&(data))
#define  EPI_EPI_GPLUT_LINE_67_get_gp_table_line_7(data)                         ((0xFFFF0000&(data))>>16)
#define  EPI_EPI_GPLUT_LINE_67_get_gp_table_line_6(data)                         (0x0000FFFF&(data))

#define  EPI_EPI_GPLUT_LINE_89                                                   0x18026464
#define  EPI_EPI_GPLUT_LINE_89_reg_addr                                          "0xB8026464"
#define  EPI_EPI_GPLUT_LINE_89_reg                                               0xB8026464
#define  EPI_EPI_GPLUT_LINE_89_inst_addr                                         "0x009C"
#define  set_EPI_EPI_GPLUT_LINE_89_reg(data)                                     (*((volatile unsigned int*)EPI_EPI_GPLUT_LINE_89_reg)=data)
#define  get_EPI_EPI_GPLUT_LINE_89_reg                                           (*((volatile unsigned int*)EPI_EPI_GPLUT_LINE_89_reg))
#define  EPI_EPI_GPLUT_LINE_89_gp_table_line_9_shift                             (16)
#define  EPI_EPI_GPLUT_LINE_89_gp_table_line_8_shift                             (0)
#define  EPI_EPI_GPLUT_LINE_89_gp_table_line_9_mask                              (0xFFFF0000)
#define  EPI_EPI_GPLUT_LINE_89_gp_table_line_8_mask                              (0x0000FFFF)
#define  EPI_EPI_GPLUT_LINE_89_gp_table_line_9(data)                             (0xFFFF0000&((data)<<16))
#define  EPI_EPI_GPLUT_LINE_89_gp_table_line_8(data)                             (0x0000FFFF&(data))
#define  EPI_EPI_GPLUT_LINE_89_get_gp_table_line_9(data)                         ((0xFFFF0000&(data))>>16)
#define  EPI_EPI_GPLUT_LINE_89_get_gp_table_line_8(data)                         (0x0000FFFF&(data))

#define  EPI_EPI_GPLUT_LINE_AB                                                   0x18026468
#define  EPI_EPI_GPLUT_LINE_AB_reg_addr                                          "0xB8026468"
#define  EPI_EPI_GPLUT_LINE_AB_reg                                               0xB8026468
#define  EPI_EPI_GPLUT_LINE_AB_inst_addr                                         "0x009D"
#define  set_EPI_EPI_GPLUT_LINE_AB_reg(data)                                     (*((volatile unsigned int*)EPI_EPI_GPLUT_LINE_AB_reg)=data)
#define  get_EPI_EPI_GPLUT_LINE_AB_reg                                           (*((volatile unsigned int*)EPI_EPI_GPLUT_LINE_AB_reg))
#define  EPI_EPI_GPLUT_LINE_AB_gp_table_line_11_shift                            (16)
#define  EPI_EPI_GPLUT_LINE_AB_gp_table_line_10_shift                            (0)
#define  EPI_EPI_GPLUT_LINE_AB_gp_table_line_11_mask                             (0xFFFF0000)
#define  EPI_EPI_GPLUT_LINE_AB_gp_table_line_10_mask                             (0x0000FFFF)
#define  EPI_EPI_GPLUT_LINE_AB_gp_table_line_11(data)                            (0xFFFF0000&((data)<<16))
#define  EPI_EPI_GPLUT_LINE_AB_gp_table_line_10(data)                            (0x0000FFFF&(data))
#define  EPI_EPI_GPLUT_LINE_AB_get_gp_table_line_11(data)                        ((0xFFFF0000&(data))>>16)
#define  EPI_EPI_GPLUT_LINE_AB_get_gp_table_line_10(data)                        (0x0000FFFF&(data))

#define  EPI_EPI_GPLUT_LINE_CD                                                   0x1802646C
#define  EPI_EPI_GPLUT_LINE_CD_reg_addr                                          "0xB802646C"
#define  EPI_EPI_GPLUT_LINE_CD_reg                                               0xB802646C
#define  EPI_EPI_GPLUT_LINE_CD_inst_addr                                         "0x009E"
#define  set_EPI_EPI_GPLUT_LINE_CD_reg(data)                                     (*((volatile unsigned int*)EPI_EPI_GPLUT_LINE_CD_reg)=data)
#define  get_EPI_EPI_GPLUT_LINE_CD_reg                                           (*((volatile unsigned int*)EPI_EPI_GPLUT_LINE_CD_reg))
#define  EPI_EPI_GPLUT_LINE_CD_gp_table_line_13_shift                            (16)
#define  EPI_EPI_GPLUT_LINE_CD_gp_table_line_12_shift                            (0)
#define  EPI_EPI_GPLUT_LINE_CD_gp_table_line_13_mask                             (0xFFFF0000)
#define  EPI_EPI_GPLUT_LINE_CD_gp_table_line_12_mask                             (0x0000FFFF)
#define  EPI_EPI_GPLUT_LINE_CD_gp_table_line_13(data)                            (0xFFFF0000&((data)<<16))
#define  EPI_EPI_GPLUT_LINE_CD_gp_table_line_12(data)                            (0x0000FFFF&(data))
#define  EPI_EPI_GPLUT_LINE_CD_get_gp_table_line_13(data)                        ((0xFFFF0000&(data))>>16)
#define  EPI_EPI_GPLUT_LINE_CD_get_gp_table_line_12(data)                        (0x0000FFFF&(data))

#define  EPI_EPI_GPLUT_LINE_EF                                                   0x18026470
#define  EPI_EPI_GPLUT_LINE_EF_reg_addr                                          "0xB8026470"
#define  EPI_EPI_GPLUT_LINE_EF_reg                                               0xB8026470
#define  EPI_EPI_GPLUT_LINE_EF_inst_addr                                         "0x009F"
#define  set_EPI_EPI_GPLUT_LINE_EF_reg(data)                                     (*((volatile unsigned int*)EPI_EPI_GPLUT_LINE_EF_reg)=data)
#define  get_EPI_EPI_GPLUT_LINE_EF_reg                                           (*((volatile unsigned int*)EPI_EPI_GPLUT_LINE_EF_reg))
#define  EPI_EPI_GPLUT_LINE_EF_gp_table_line_15_shift                            (16)
#define  EPI_EPI_GPLUT_LINE_EF_gp_table_line_14_shift                            (0)
#define  EPI_EPI_GPLUT_LINE_EF_gp_table_line_15_mask                             (0xFFFF0000)
#define  EPI_EPI_GPLUT_LINE_EF_gp_table_line_14_mask                             (0x0000FFFF)
#define  EPI_EPI_GPLUT_LINE_EF_gp_table_line_15(data)                            (0xFFFF0000&((data)<<16))
#define  EPI_EPI_GPLUT_LINE_EF_gp_table_line_14(data)                            (0x0000FFFF&(data))
#define  EPI_EPI_GPLUT_LINE_EF_get_gp_table_line_15(data)                        ((0xFFFF0000&(data))>>16)
#define  EPI_EPI_GPLUT_LINE_EF_get_gp_table_line_14(data)                        (0x0000FFFF&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======EPI register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  phase2_preamble_num_0:4;
        RBus_UInt32  res2:16;
    };
}epi_epi_packet_ctr1_0_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  phase2_preamble_num_1:4;
        RBus_UInt32  res2:16;
    };
}epi_epi_packet_ctr1_0_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  phase2_preamble_num_2:4;
        RBus_UInt32  res2:16;
    };
}epi_epi_packet_ctr1_0_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  phase2_preamble_num_3:4;
        RBus_UInt32  res2:16;
    };
}epi_epi_packet_ctr1_0_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  phase2_preamble_num_4:4;
        RBus_UInt32  res2:16;
    };
}epi_epi_packet_ctr1_0_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  phase2_preamble_num_5:4;
        RBus_UInt32  res2:16;
    };
}epi_epi_packet_ctr1_0_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  phase2_preamble_num_6:4;
        RBus_UInt32  res2:16;
    };
}epi_epi_packet_ctr1_0_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  phase2_preamble_num_7:4;
        RBus_UInt32  res2:16;
    };
}epi_epi_packet_ctr1_0_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  epi_data_unfl:1;
        RBus_UInt32  epi_data_unfl_clr:1;
        RBus_UInt32  prbs7_tx_en:1;
        RBus_UInt32  epi_bit_mode:2;
        RBus_UInt32  bist_mode_select:3;
        RBus_UInt32  data_mode_change:1;
        RBus_UInt32  data_mode_flag_clr:1;
        RBus_UInt32  bist_pattern_0:18;
        RBus_UInt32  pn_swap:1;
        RBus_UInt32  epi_version:3;
    };
}epi_epi_packet_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  force_ctsfifo_rstn_epi:1;
        RBus_UInt32  dummy18026064_30_29:2;
        RBus_UInt32  epi_reset:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  ctrl_start_en:1;
        RBus_UInt32  ctrl3_en:1;
        RBus_UInt32  data_start_en:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  bist_pattern_1:18;
        RBus_UInt32  hw_lock:1;
        RBus_UInt32  epi_lock:1;
        RBus_UInt32  epi_lock_sel:1;
        RBus_UInt32  res3:1;
    };
}epi_epi_clock_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  epi_out_swap:8;
    };
}epi_epi_packet_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  two_pixel_mode:1;
        RBus_UInt32  ext_subpixel_mode:1;
        RBus_UInt32  res1:5;
        RBus_UInt32  port_num:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  epi_enable:1;
        RBus_UInt32  back_value:2;
        RBus_UInt32  front_value:2;
        RBus_UInt32  res3:2;
        RBus_UInt32  dummy1802606c_9:1;
        RBus_UInt32  res4:9;
    };
}epi_epi_port_option_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  epi_dbg_en:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  epi_otpin_ver_sel:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  dummy18026070_24_20:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  epi_otpin_port_sel:5;
        RBus_UInt32  res4:1;
        RBus_UInt32  front_cmd:3;
        RBus_UInt32  res5:1;
        RBus_UInt32  front_data:3;
        RBus_UInt32  res6:4;
    };
}epi_epi_cmpi_front_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  front_dummy_num:5;
        RBus_UInt32  res2:11;
        RBus_UInt32  back_dummy_num:5;
    };
}epi_epi_dummy_en_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  f15_dummy_color_sel:2;
        RBus_UInt32  f14_dummy_color_sel:2;
        RBus_UInt32  f13_dummy_color_sel:2;
        RBus_UInt32  f12_dummy_color_sel:2;
        RBus_UInt32  f11_dummy_color_sel:2;
        RBus_UInt32  f10_dummy_color_sel:2;
        RBus_UInt32  f9_dummy_color_sel:2;
        RBus_UInt32  f8_dummy_color_sel:2;
        RBus_UInt32  f7_dummy_color_sel:2;
        RBus_UInt32  f6_dummy_color_sel:2;
        RBus_UInt32  f5_dummy_color_sel:2;
        RBus_UInt32  f4_dummy_color_sel:2;
        RBus_UInt32  f3_dummy_color_sel:2;
        RBus_UInt32  f2_dummy_color_sel:2;
        RBus_UInt32  f1_dummy_color_sel:2;
        RBus_UInt32  f0_dummy_color_sel:2;
    };
}epi_epi_dummy_sel_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  b0_dummy_color_sel:2;
        RBus_UInt32  b1_dummy_color_sel:2;
        RBus_UInt32  b2_dummy_color_sel:2;
        RBus_UInt32  b3_dummy_color_sel:2;
        RBus_UInt32  b4_dummy_color_sel:2;
        RBus_UInt32  b5_dummy_color_sel:2;
        RBus_UInt32  b6_dummy_color_sel:2;
        RBus_UInt32  b7_dummy_color_sel:2;
        RBus_UInt32  b8_dummy_color_sel:2;
        RBus_UInt32  b9_dummy_color_sel:2;
        RBus_UInt32  b10_dummy_color_sel:2;
        RBus_UInt32  b11_dummy_color_sel:2;
        RBus_UInt32  b12_dummy_color_sel:2;
        RBus_UInt32  b13_dummy_color_sel:2;
        RBus_UInt32  b14_dummy_color_sel:2;
        RBus_UInt32  b15_dummy_color_sel:2;
    };
}epi_epi_dummy_sel_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  dummy_color_0:30;
    };
}epi_epi_dummy_color_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  dummy_color_1:30;
    };
}epi_epi_dummy_color_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  dummy_color_2:30;
    };
}epi_epi_dummy_color_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  dummy_color_3:30;
    };
}epi_epi_dummy_color_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_mismatch_count:16;
        RBus_UInt32  dummy18026090_15_9:7;
        RBus_UInt32  crc_port_sel:5;
        RBus_UInt32  dummy18026090_3:1;
        RBus_UInt32  crc_mismatch_clear:1;
        RBus_UInt32  crc_conti:1;
        RBus_UInt32  crc_start:1;
    };
}epi_epi_crc_ctrl_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_result:32;
    };
}epi_epi_crc_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_golden:32;
    };
}epi_epi_crc_ctrl_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  epi_src_sel:1;
        RBus_UInt32  epi_src_data:30;
    };
}epi_epi_data_src_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  inv_table_line_cycle:5;
        RBus_UInt32  res2:4;
    };
}epi_epi_packet_ctr1_inv_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  inv_line_1:4;
        RBus_UInt32  inv_line_2:4;
        RBus_UInt32  inv_line_3:4;
        RBus_UInt32  inv_line_4:4;
        RBus_UInt32  inv_line_5:4;
        RBus_UInt32  inv_line_6:4;
        RBus_UInt32  inv_line_7:4;
        RBus_UInt32  inv_line_8:4;
    };
}epi_epi_packet_ctr1_inv_table_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  inv_line_9:4;
        RBus_UInt32  inv_line_10:4;
        RBus_UInt32  inv_line_11:4;
        RBus_UInt32  inv_line_12:4;
        RBus_UInt32  inv_line_13:4;
        RBus_UInt32  inv_line_14:4;
        RBus_UInt32  inv_line_15:4;
        RBus_UInt32  inv_line_16:4;
    };
}epi_epi_packet_ctr1_inv_table_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  ls_port_en:8;
    };
}epi_epi_ls_port_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  constant_update_mode:1;
        RBus_UInt32  res1:23;
        RBus_UInt32  data_port_en:8;
    };
}epi_epi_data_port_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sw_cal:1;
        RBus_UInt32  res1:17;
        RBus_UInt32  sw_cal_value:14;
    };
}epi_epi_den_fall_loca_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  debounce_hi_window:12;
        RBus_UInt32  res2:3;
        RBus_UInt32  debounce_low_window:12;
        RBus_UInt32  debounce_en:1;
    };
}epi_epi_lock_debounce_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  hs_distance_flag:1;
        RBus_UInt32  hs_den_length_flag:1;
        RBus_UInt32  den_length_flag:1;
        RBus_UInt32  den_num_flag:1;
    };
}epi_epi_dbg_reg_flag_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  hs_distance_det_en:1;
        RBus_UInt32  hs_den_length_det_en:1;
        RBus_UInt32  den_length_det_en:1;
        RBus_UInt32  den_num_det_en:1;
    };
}epi_epi_dbg_reg_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  soe_table_line_cycle:2;
        RBus_UInt32  ctr12_ref_soe:2;
    };
}epi_epi_soe_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  lane0_soe0:18;
    };
}epi_epi_soe_line0_lane0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  lane0_soe1:18;
    };
}epi_epi_soe_line1_lane0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  lane0_soe2:18;
    };
}epi_epi_soe_line2_lane0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  lane0_soe3:18;
    };
}epi_epi_soe_line3_lane0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  lane1_soe0:18;
    };
}epi_epi_soe_line0_lane1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  lane1_soe1:18;
    };
}epi_epi_soe_line1_lane1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  lane1_soe2:18;
    };
}epi_epi_soe_line2_lane1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  lane1_soe3:18;
    };
}epi_epi_soe_line3_lane1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  lane2_soe0:18;
    };
}epi_epi_soe_line0_lane2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  lane2_soe1:18;
    };
}epi_epi_soe_line1_lane2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  lane2_soe2:18;
    };
}epi_epi_soe_line2_lane2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  lane2_soe3:18;
    };
}epi_epi_soe_line3_lane2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  lane3_soe0:18;
    };
}epi_epi_soe_line0_lane3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  lane3_soe1:18;
    };
}epi_epi_soe_line1_lane3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  lane3_soe2:18;
    };
}epi_epi_soe_line2_lane3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  lane3_soe3:18;
    };
}epi_epi_soe_line3_lane3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  lane4_soe0:18;
    };
}epi_epi_soe_line0_lane4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  lane4_soe1:18;
    };
}epi_epi_soe_line1_lane4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  lane4_soe2:18;
    };
}epi_epi_soe_line2_lane4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  lane4_soe3:18;
    };
}epi_epi_soe_line3_lane4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  lane5_soe0:18;
    };
}epi_epi_soe_line0_lane5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  lane5_soe1:18;
    };
}epi_epi_soe_line1_lane5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  lane5_soe2:18;
    };
}epi_epi_soe_line2_lane5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  lane5_soe3:18;
    };
}epi_epi_soe_line3_lane5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  lane6_soe0:18;
    };
}epi_epi_soe_line0_lane6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  lane6_soe1:18;
    };
}epi_epi_soe_line1_lane6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  lane6_soe2:18;
    };
}epi_epi_soe_line2_lane6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  lane6_soe3:18;
    };
}epi_epi_soe_line3_lane6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  lane7_soe0:18;
    };
}epi_epi_soe_line0_lane7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  lane7_soe1:18;
    };
}epi_epi_soe_line1_lane7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  lane7_soe2:18;
    };
}epi_epi_soe_line2_lane7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  lane7_soe3:18;
    };
}epi_epi_soe_line3_lane7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  lane_d_st_c4_mux_sel:6;
        RBus_UInt32  lane_d_st_c3_mux_sel:6;
        RBus_UInt32  lane_d_st_c2_mux_sel:6;
        RBus_UInt32  lane_d_st_c1_mux_sel:6;
        RBus_UInt32  lane_d_st_c0_mux_sel:6;
    };
}epi_epi_lane_dst_mux0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  lane_d_st_c9_mux_sel:6;
        RBus_UInt32  lane_d_st_c8_mux_sel:6;
        RBus_UInt32  lane_d_st_c7_mux_sel:6;
        RBus_UInt32  lane_d_st_c6_mux_sel:6;
        RBus_UInt32  lane_d_st_c5_mux_sel:6;
    };
}epi_epi_lane_dst_mux1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  lane_d_st_c14_mux_sel:6;
        RBus_UInt32  lane_d_st_c13_mux_sel:6;
        RBus_UInt32  lane_d_st_c12_mux_sel:6;
        RBus_UInt32  lane_d_st_c11_mux_sel:6;
        RBus_UInt32  lane_d_st_c10_mux_sel:6;
    };
}epi_epi_lane_dst_mux2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  lane_d_st_c19_mux_sel:6;
        RBus_UInt32  lane_d_st_c18_mux_sel:6;
        RBus_UInt32  lane_d_st_c17_mux_sel:6;
        RBus_UInt32  lane_d_st_c16_mux_sel:6;
        RBus_UInt32  lane_d_st_c15_mux_sel:6;
    };
}epi_epi_lane_dst_mux3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  lane_d_st_c24_mux_sel:6;
        RBus_UInt32  lane_d_st_c23_mux_sel:6;
        RBus_UInt32  lane_d_st_c22_mux_sel:6;
        RBus_UInt32  lane_d_st_c21_mux_sel:6;
        RBus_UInt32  lane_d_st_c20_mux_sel:6;
    };
}epi_epi_lane_dst_mux4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  lane_d_st_c29_mux_sel:6;
        RBus_UInt32  lane_d_st_c28_mux_sel:6;
        RBus_UInt32  lane_d_st_c27_mux_sel:6;
        RBus_UInt32  lane_d_st_c26_mux_sel:6;
        RBus_UInt32  lane_d_st_c25_mux_sel:6;
    };
}epi_epi_lane_dst_mux5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  lane_c_st_c4_mux_sel:6;
        RBus_UInt32  lane_c_st_c3_mux_sel:6;
        RBus_UInt32  lane_c_st_c2_mux_sel:6;
        RBus_UInt32  lane_c_st_c1_mux_sel:6;
        RBus_UInt32  lane_c_st_c0_mux_sel:6;
    };
}epi_epi_lane_cst_mux0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  lane_c_st_c9_mux_sel:6;
        RBus_UInt32  lane_c_st_c8_mux_sel:6;
        RBus_UInt32  lane_c_st_c7_mux_sel:6;
        RBus_UInt32  lane_c_st_c6_mux_sel:6;
        RBus_UInt32  lane_c_st_c5_mux_sel:6;
    };
}epi_epi_lane_cst_mux1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  lane_c_st_c14_mux_sel:6;
        RBus_UInt32  lane_c_st_c13_mux_sel:6;
        RBus_UInt32  lane_c_st_c12_mux_sel:6;
        RBus_UInt32  lane_c_st_c11_mux_sel:6;
        RBus_UInt32  lane_c_st_c10_mux_sel:6;
    };
}epi_epi_lane_cst_mux2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  lane_c_st_c19_mux_sel:6;
        RBus_UInt32  lane_c_st_c18_mux_sel:6;
        RBus_UInt32  lane_c_st_c17_mux_sel:6;
        RBus_UInt32  lane_c_st_c16_mux_sel:6;
        RBus_UInt32  lane_c_st_c15_mux_sel:6;
    };
}epi_epi_lane_cst_mux3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  lane_c_st_c24_mux_sel:6;
        RBus_UInt32  lane_c_st_c23_mux_sel:6;
        RBus_UInt32  lane_c_st_c22_mux_sel:6;
        RBus_UInt32  lane_c_st_c21_mux_sel:6;
        RBus_UInt32  lane_c_st_c20_mux_sel:6;
    };
}epi_epi_lane_cst_mux4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  lane_c_st_c29_mux_sel:6;
        RBus_UInt32  lane_c_st_c28_mux_sel:6;
        RBus_UInt32  lane_c_st_c27_mux_sel:6;
        RBus_UInt32  lane_c_st_c26_mux_sel:6;
        RBus_UInt32  lane_c_st_c25_mux_sel:6;
    };
}epi_epi_lane_cst_mux5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  lane_ctr1_c4_mux_sel:6;
        RBus_UInt32  lane_ctr1_c3_mux_sel:6;
        RBus_UInt32  lane_ctr1_c2_mux_sel:6;
        RBus_UInt32  lane_ctr1_c1_mux_sel:6;
        RBus_UInt32  lane_ctr1_c0_mux_sel:6;
    };
}epi_epi_lane_ctr1_mux0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  lane_ctr1_c9_mux_sel:6;
        RBus_UInt32  lane_ctr1_c8_mux_sel:6;
        RBus_UInt32  lane_ctr1_c7_mux_sel:6;
        RBus_UInt32  lane_ctr1_c6_mux_sel:6;
        RBus_UInt32  lane_ctr1_c5_mux_sel:6;
    };
}epi_epi_lane_ctr1_mux1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  lane_ctr1_c14_mux_sel:6;
        RBus_UInt32  lane_ctr1_c13_mux_sel:6;
        RBus_UInt32  lane_ctr1_c12_mux_sel:6;
        RBus_UInt32  lane_ctr1_c11_mux_sel:6;
        RBus_UInt32  lane_ctr1_c10_mux_sel:6;
    };
}epi_epi_lane_ctr1_mux2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  lane_ctr1_c19_mux_sel:6;
        RBus_UInt32  lane_ctr1_c18_mux_sel:6;
        RBus_UInt32  lane_ctr1_c17_mux_sel:6;
        RBus_UInt32  lane_ctr1_c16_mux_sel:6;
        RBus_UInt32  lane_ctr1_c15_mux_sel:6;
    };
}epi_epi_lane_ctr1_mux3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  lane_ctr1_c24_mux_sel:6;
        RBus_UInt32  lane_ctr1_c23_mux_sel:6;
        RBus_UInt32  lane_ctr1_c22_mux_sel:6;
        RBus_UInt32  lane_ctr1_c21_mux_sel:6;
        RBus_UInt32  lane_ctr1_c20_mux_sel:6;
    };
}epi_epi_lane_ctr1_mux4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  lane_ctr1_c29_mux_sel:6;
        RBus_UInt32  lane_ctr1_c28_mux_sel:6;
        RBus_UInt32  lane_ctr1_c27_mux_sel:6;
        RBus_UInt32  lane_ctr1_c26_mux_sel:6;
        RBus_UInt32  lane_ctr1_c25_mux_sel:6;
    };
}epi_epi_lane_ctr1_mux5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  lane_ctr2_c4_mux_sel:6;
        RBus_UInt32  lane_ctr2_c3_mux_sel:6;
        RBus_UInt32  lane_ctr2_c2_mux_sel:6;
        RBus_UInt32  lane_ctr2_c1_mux_sel:6;
        RBus_UInt32  lane_ctr2_c0_mux_sel:6;
    };
}epi_epi_lane_ctr2_mux0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  lane_ctr2_c9_mux_sel:6;
        RBus_UInt32  lane_ctr2_c8_mux_sel:6;
        RBus_UInt32  lane_ctr2_c7_mux_sel:6;
        RBus_UInt32  lane_ctr2_c6_mux_sel:6;
        RBus_UInt32  lane_ctr2_c5_mux_sel:6;
    };
}epi_epi_lane_ctr2_mux1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  lane_ctr2_c14_mux_sel:6;
        RBus_UInt32  lane_ctr2_c13_mux_sel:6;
        RBus_UInt32  lane_ctr2_c12_mux_sel:6;
        RBus_UInt32  lane_ctr2_c11_mux_sel:6;
        RBus_UInt32  lane_ctr2_c10_mux_sel:6;
    };
}epi_epi_lane_ctr2_mux2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  lane_ctr2_c19_mux_sel:6;
        RBus_UInt32  lane_ctr2_c18_mux_sel:6;
        RBus_UInt32  lane_ctr2_c17_mux_sel:6;
        RBus_UInt32  lane_ctr2_c16_mux_sel:6;
        RBus_UInt32  lane_ctr2_c15_mux_sel:6;
    };
}epi_epi_lane_ctr2_mux3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  lane_ctr2_c24_mux_sel:6;
        RBus_UInt32  lane_ctr2_c23_mux_sel:6;
        RBus_UInt32  lane_ctr2_c22_mux_sel:6;
        RBus_UInt32  lane_ctr2_c21_mux_sel:6;
        RBus_UInt32  lane_ctr2_c20_mux_sel:6;
    };
}epi_epi_lane_ctr2_mux4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  lane_ctr2_c29_mux_sel:6;
        RBus_UInt32  lane_ctr2_c28_mux_sel:6;
        RBus_UInt32  lane_ctr2_c27_mux_sel:6;
        RBus_UInt32  lane_ctr2_c26_mux_sel:6;
        RBus_UInt32  lane_ctr2_c25_mux_sel:6;
    };
}epi_epi_lane_ctr2_mux5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  lane_ctr3_c4_mux_sel:6;
        RBus_UInt32  lane_ctr3_c3_mux_sel:6;
        RBus_UInt32  lane_ctr3_c2_mux_sel:6;
        RBus_UInt32  lane_ctr3_c1_mux_sel:6;
        RBus_UInt32  lane_ctr3_c0_mux_sel:6;
    };
}epi_epi_lane_ctr3_mux0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  lane_ctr3_c9_mux_sel:6;
        RBus_UInt32  lane_ctr3_c8_mux_sel:6;
        RBus_UInt32  lane_ctr3_c7_mux_sel:6;
        RBus_UInt32  lane_ctr3_c6_mux_sel:6;
        RBus_UInt32  lane_ctr3_c5_mux_sel:6;
    };
}epi_epi_lane_ctr3_mux1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  lane_ctr3_c14_mux_sel:6;
        RBus_UInt32  lane_ctr3_c13_mux_sel:6;
        RBus_UInt32  lane_ctr3_c12_mux_sel:6;
        RBus_UInt32  lane_ctr3_c11_mux_sel:6;
        RBus_UInt32  lane_ctr3_c10_mux_sel:6;
    };
}epi_epi_lane_ctr3_mux2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  lane_ctr3_c19_mux_sel:6;
        RBus_UInt32  lane_ctr3_c18_mux_sel:6;
        RBus_UInt32  lane_ctr3_c17_mux_sel:6;
        RBus_UInt32  lane_ctr3_c16_mux_sel:6;
        RBus_UInt32  lane_ctr3_c15_mux_sel:6;
    };
}epi_epi_lane_ctr3_mux3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  lane_ctr3_c24_mux_sel:6;
        RBus_UInt32  lane_ctr3_c23_mux_sel:6;
        RBus_UInt32  lane_ctr3_c22_mux_sel:6;
        RBus_UInt32  lane_ctr3_c21_mux_sel:6;
        RBus_UInt32  lane_ctr3_c20_mux_sel:6;
    };
}epi_epi_lane_ctr3_mux4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  lane_ctr3_c29_mux_sel:6;
        RBus_UInt32  lane_ctr3_c28_mux_sel:6;
        RBus_UInt32  lane_ctr3_c27_mux_sel:6;
        RBus_UInt32  lane_ctr3_c26_mux_sel:6;
        RBus_UInt32  lane_ctr3_c25_mux_sel:6;
    };
}epi_epi_lane_ctr3_mux5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  tcon_c_sel:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  tcon_b_sel:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  tcon_a_sel:5;
    };
}epi_epi_tcon_mux_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  tcon_f_sel:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  tcon_e_sel:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  tcon_d_sel:5;
    };
}epi_epi_tcon_mux1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  tcon_i_sel:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  tcon_h_sel:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  tcon_g_sel:5;
    };
}epi_epi_tcon_mux2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  tcon_k_sel:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  tcon_j_sel:5;
    };
}epi_epi_tcon_mux3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18026510_31_0:32;
    };
}epi_epi_dummy_reg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  d_st:30;
    };
}epi_epi_lane_dst_data_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  c_st:30;
    };
}epi_epi_lane_cst_data_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  lane0_ctr1_oe_en:1;
        RBus_UInt32  lane0_ctr1_even:30;
    };
}epi_epi_lane0_ctr1_edata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  lane0_ctr1_odd:30;
    };
}epi_epi_lane0_ctr1_odata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  lane1_ctr1_oe_en:1;
        RBus_UInt32  lane1_ctr1_even:30;
    };
}epi_epi_lane1_ctr1_edata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  lane1_ctr1_odd:30;
    };
}epi_epi_lane1_ctr1_odata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  lane2_ctr1_oe_en:1;
        RBus_UInt32  lane2_ctr1_even:30;
    };
}epi_epi_lane2_ctr1_edata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  lane2_ctr1_odd:30;
    };
}epi_epi_lane2_ctr1_odata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  lane3_ctr1_oe_en:1;
        RBus_UInt32  lane3_ctr1_even:30;
    };
}epi_epi_lane3_ctr1_edata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  lane3_ctr1_odd:30;
    };
}epi_epi_lane3_ctr1_odata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  lane4_ctr1_oe_en:1;
        RBus_UInt32  lane4_ctr1_even:30;
    };
}epi_epi_lane4_ctr1_edata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  lane4_ctr1_odd:30;
    };
}epi_epi_lane4_ctr1_odata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  lane5_ctr1_oe_en:1;
        RBus_UInt32  lane5_ctr1_even:30;
    };
}epi_epi_lane5_ctr1_edata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  lane5_ctr1_odd:30;
    };
}epi_epi_lane5_ctr1_odata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  lane6_ctr1_oe_en:1;
        RBus_UInt32  lane6_ctr1_even:30;
    };
}epi_epi_lane6_ctr1_edata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  lane6_ctr1_odd:30;
    };
}epi_epi_lane6_ctr1_odata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  lane7_ctr1_oe_en:1;
        RBus_UInt32  lane7_ctr1_even:30;
    };
}epi_epi_lane7_ctr1_edata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  lane7_ctr1_odd:30;
    };
}epi_epi_lane7_ctr1_odata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  lane0_ctr2_oe_en:1;
        RBus_UInt32  lane0_ctr2_even:30;
    };
}epi_epi_lane0_ctr2_edata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  lane0_ctr2_odd:30;
    };
}epi_epi_lane0_ctr2_odata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  lane1_ctr2_oe_en:1;
        RBus_UInt32  lane1_ctr2_even:30;
    };
}epi_epi_lane1_ctr2_edata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  lane1_ctr2_odd:30;
    };
}epi_epi_lane1_ctr2_odata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  lane2_ctr2_oe_en:1;
        RBus_UInt32  lane2_ctr2_even:30;
    };
}epi_epi_lane2_ctr2_edata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  lane2_ctr2_odd:30;
    };
}epi_epi_lane2_ctr2_odata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  lane3_ctr2_oe_en:1;
        RBus_UInt32  lane3_ctr2_even:30;
    };
}epi_epi_lane3_ctr2_edata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  lane3_ctr2_odd:30;
    };
}epi_epi_lane3_ctr2_odata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  lane4_ctr2_oe_en:1;
        RBus_UInt32  lane4_ctr2_even:30;
    };
}epi_epi_lane4_ctr2_edata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  lane4_ctr2_odd:30;
    };
}epi_epi_lane4_ctr2_odata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  lane5_ctr2_oe_en:1;
        RBus_UInt32  lane5_ctr2_even:30;
    };
}epi_epi_lane5_ctr2_edata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  lane5_ctr2_odd:30;
    };
}epi_epi_lane5_ctr2_odata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  lane6_ctr2_oe_en:1;
        RBus_UInt32  lane6_ctr2_even:30;
    };
}epi_epi_lane6_ctr2_edata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  lane6_ctr2_odd:30;
    };
}epi_epi_lane6_ctr2_odata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  lane7_ctr2_oe_en:1;
        RBus_UInt32  lane7_ctr2_even:30;
    };
}epi_epi_lane7_ctr2_edata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  lane7_ctr2_odd:30;
    };
}epi_epi_lane7_ctr2_odata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  lane0_ctr3_oe_en:1;
        RBus_UInt32  lane0_ctr3_even:30;
    };
}epi_epi_lane0_ctr3_edata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  lane0_ctr3_odd:30;
    };
}epi_epi_lane0_ctr3_odata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  lane1_ctr3_oe_en:1;
        RBus_UInt32  lane1_ctr3_even:30;
    };
}epi_epi_lane1_ctr3_edata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  lane1_ctr3_odd:30;
    };
}epi_epi_lane1_ctr3_odata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  lane2_ctr3_oe_en:1;
        RBus_UInt32  lane2_ctr3_even:30;
    };
}epi_epi_lane2_ctr3_edata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  lane2_ctr3_odd:30;
    };
}epi_epi_lane2_ctr3_odata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  lane3_ctr3_oe_en:1;
        RBus_UInt32  lane3_ctr3_even:30;
    };
}epi_epi_lane3_ctr3_edata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  lane3_ctr3_odd:30;
    };
}epi_epi_lane3_ctr3_odata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  lane4_ctr3_oe_en:1;
        RBus_UInt32  lane4_ctr3_even:30;
    };
}epi_epi_lane4_ctr3_edata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  lane4_ctr3_odd:30;
    };
}epi_epi_lane4_ctr3_odata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  lane5_ctr3_oe_en:1;
        RBus_UInt32  lane5_ctr3_even:30;
    };
}epi_epi_lane5_ctr3_edata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  lane5_ctr3_odd:30;
    };
}epi_epi_lane5_ctr3_odata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  lane6_ctr3_oe_en:1;
        RBus_UInt32  lane6_ctr3_even:30;
    };
}epi_epi_lane6_ctr3_edata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  lane6_ctr3_odd:30;
    };
}epi_epi_lane6_ctr3_odata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  lane7_ctr3_oe_en:1;
        RBus_UInt32  lane7_ctr3_even:30;
    };
}epi_epi_lane7_ctr3_edata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  lane7_ctr3_odd:30;
    };
}epi_epi_lane7_ctr3_odata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  gp_table_line_cycle:4;
    };
}epi_epi_gplut_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gp_table_line_1:16;
        RBus_UInt32  gp_table_line_0:16;
    };
}epi_epi_gplut_line_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gp_table_line_3:16;
        RBus_UInt32  gp_table_line_2:16;
    };
}epi_epi_gplut_line_23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gp_table_line_5:16;
        RBus_UInt32  gp_table_line_4:16;
    };
}epi_epi_gplut_line_45_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gp_table_line_7:16;
        RBus_UInt32  gp_table_line_6:16;
    };
}epi_epi_gplut_line_67_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gp_table_line_9:16;
        RBus_UInt32  gp_table_line_8:16;
    };
}epi_epi_gplut_line_89_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gp_table_line_11:16;
        RBus_UInt32  gp_table_line_10:16;
    };
}epi_epi_gplut_line_ab_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gp_table_line_13:16;
        RBus_UInt32  gp_table_line_12:16;
    };
}epi_epi_gplut_line_cd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gp_table_line_15:16;
        RBus_UInt32  gp_table_line_14:16;
    };
}epi_epi_gplut_line_ef_RBUS;

#else //apply LITTLE_ENDIAN

//======EPI register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  phase2_preamble_num_0:4;
        RBus_UInt32  res2:12;
    };
}epi_epi_packet_ctr1_0_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  phase2_preamble_num_1:4;
        RBus_UInt32  res2:12;
    };
}epi_epi_packet_ctr1_0_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  phase2_preamble_num_2:4;
        RBus_UInt32  res2:12;
    };
}epi_epi_packet_ctr1_0_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  phase2_preamble_num_3:4;
        RBus_UInt32  res2:12;
    };
}epi_epi_packet_ctr1_0_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  phase2_preamble_num_4:4;
        RBus_UInt32  res2:12;
    };
}epi_epi_packet_ctr1_0_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  phase2_preamble_num_5:4;
        RBus_UInt32  res2:12;
    };
}epi_epi_packet_ctr1_0_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  phase2_preamble_num_6:4;
        RBus_UInt32  res2:12;
    };
}epi_epi_packet_ctr1_0_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  phase2_preamble_num_7:4;
        RBus_UInt32  res2:12;
    };
}epi_epi_packet_ctr1_0_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  epi_version:3;
        RBus_UInt32  pn_swap:1;
        RBus_UInt32  bist_pattern_0:18;
        RBus_UInt32  data_mode_flag_clr:1;
        RBus_UInt32  data_mode_change:1;
        RBus_UInt32  bist_mode_select:3;
        RBus_UInt32  epi_bit_mode:2;
        RBus_UInt32  prbs7_tx_en:1;
        RBus_UInt32  epi_data_unfl_clr:1;
        RBus_UInt32  epi_data_unfl:1;
    };
}epi_epi_packet_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  epi_lock_sel:1;
        RBus_UInt32  epi_lock:1;
        RBus_UInt32  hw_lock:1;
        RBus_UInt32  bist_pattern_1:18;
        RBus_UInt32  res2:2;
        RBus_UInt32  data_start_en:1;
        RBus_UInt32  ctrl3_en:1;
        RBus_UInt32  ctrl_start_en:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  epi_reset:1;
        RBus_UInt32  dummy18026064_30_29:2;
        RBus_UInt32  force_ctsfifo_rstn_epi:1;
    };
}epi_epi_clock_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  epi_out_swap:8;
        RBus_UInt32  res1:24;
    };
}epi_epi_packet_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  dummy1802606c_9:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  front_value:2;
        RBus_UInt32  back_value:2;
        RBus_UInt32  epi_enable:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  port_num:5;
        RBus_UInt32  res4:5;
        RBus_UInt32  ext_subpixel_mode:1;
        RBus_UInt32  two_pixel_mode:1;
    };
}epi_epi_port_option_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  front_data:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  front_cmd:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  epi_otpin_port_sel:5;
        RBus_UInt32  res4:3;
        RBus_UInt32  dummy18026070_24_20:5;
        RBus_UInt32  res5:3;
        RBus_UInt32  epi_otpin_ver_sel:1;
        RBus_UInt32  res6:2;
        RBus_UInt32  epi_dbg_en:1;
    };
}epi_epi_cmpi_front_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  back_dummy_num:5;
        RBus_UInt32  res1:11;
        RBus_UInt32  front_dummy_num:5;
        RBus_UInt32  res2:11;
    };
}epi_epi_dummy_en_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  f0_dummy_color_sel:2;
        RBus_UInt32  f1_dummy_color_sel:2;
        RBus_UInt32  f2_dummy_color_sel:2;
        RBus_UInt32  f3_dummy_color_sel:2;
        RBus_UInt32  f4_dummy_color_sel:2;
        RBus_UInt32  f5_dummy_color_sel:2;
        RBus_UInt32  f6_dummy_color_sel:2;
        RBus_UInt32  f7_dummy_color_sel:2;
        RBus_UInt32  f8_dummy_color_sel:2;
        RBus_UInt32  f9_dummy_color_sel:2;
        RBus_UInt32  f10_dummy_color_sel:2;
        RBus_UInt32  f11_dummy_color_sel:2;
        RBus_UInt32  f12_dummy_color_sel:2;
        RBus_UInt32  f13_dummy_color_sel:2;
        RBus_UInt32  f14_dummy_color_sel:2;
        RBus_UInt32  f15_dummy_color_sel:2;
    };
}epi_epi_dummy_sel_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  b15_dummy_color_sel:2;
        RBus_UInt32  b14_dummy_color_sel:2;
        RBus_UInt32  b13_dummy_color_sel:2;
        RBus_UInt32  b12_dummy_color_sel:2;
        RBus_UInt32  b11_dummy_color_sel:2;
        RBus_UInt32  b10_dummy_color_sel:2;
        RBus_UInt32  b9_dummy_color_sel:2;
        RBus_UInt32  b8_dummy_color_sel:2;
        RBus_UInt32  b7_dummy_color_sel:2;
        RBus_UInt32  b6_dummy_color_sel:2;
        RBus_UInt32  b5_dummy_color_sel:2;
        RBus_UInt32  b4_dummy_color_sel:2;
        RBus_UInt32  b3_dummy_color_sel:2;
        RBus_UInt32  b2_dummy_color_sel:2;
        RBus_UInt32  b1_dummy_color_sel:2;
        RBus_UInt32  b0_dummy_color_sel:2;
    };
}epi_epi_dummy_sel_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_color_0:30;
        RBus_UInt32  res1:2;
    };
}epi_epi_dummy_color_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_color_1:30;
        RBus_UInt32  res1:2;
    };
}epi_epi_dummy_color_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_color_2:30;
        RBus_UInt32  res1:2;
    };
}epi_epi_dummy_color_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_color_3:30;
        RBus_UInt32  res1:2;
    };
}epi_epi_dummy_color_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_start:1;
        RBus_UInt32  crc_conti:1;
        RBus_UInt32  crc_mismatch_clear:1;
        RBus_UInt32  dummy18026090_3:1;
        RBus_UInt32  crc_port_sel:5;
        RBus_UInt32  dummy18026090_15_9:7;
        RBus_UInt32  crc_mismatch_count:16;
    };
}epi_epi_crc_ctrl_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_result:32;
    };
}epi_epi_crc_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_golden:32;
    };
}epi_epi_crc_ctrl_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  epi_src_data:30;
        RBus_UInt32  epi_src_sel:1;
        RBus_UInt32  res1:1;
    };
}epi_epi_data_src_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  inv_table_line_cycle:5;
        RBus_UInt32  res2:23;
    };
}epi_epi_packet_ctr1_inv_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  inv_line_8:4;
        RBus_UInt32  inv_line_7:4;
        RBus_UInt32  inv_line_6:4;
        RBus_UInt32  inv_line_5:4;
        RBus_UInt32  inv_line_4:4;
        RBus_UInt32  inv_line_3:4;
        RBus_UInt32  inv_line_2:4;
        RBus_UInt32  inv_line_1:4;
    };
}epi_epi_packet_ctr1_inv_table_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  inv_line_16:4;
        RBus_UInt32  inv_line_15:4;
        RBus_UInt32  inv_line_14:4;
        RBus_UInt32  inv_line_13:4;
        RBus_UInt32  inv_line_12:4;
        RBus_UInt32  inv_line_11:4;
        RBus_UInt32  inv_line_10:4;
        RBus_UInt32  inv_line_9:4;
    };
}epi_epi_packet_ctr1_inv_table_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ls_port_en:8;
        RBus_UInt32  res1:24;
    };
}epi_epi_ls_port_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data_port_en:8;
        RBus_UInt32  res1:23;
        RBus_UInt32  constant_update_mode:1;
    };
}epi_epi_data_port_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sw_cal_value:14;
        RBus_UInt32  res1:17;
        RBus_UInt32  sw_cal:1;
    };
}epi_epi_den_fall_loca_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  debounce_en:1;
        RBus_UInt32  debounce_low_window:12;
        RBus_UInt32  res1:3;
        RBus_UInt32  debounce_hi_window:12;
        RBus_UInt32  res2:4;
    };
}epi_epi_lock_debounce_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  den_num_flag:1;
        RBus_UInt32  den_length_flag:1;
        RBus_UInt32  hs_den_length_flag:1;
        RBus_UInt32  hs_distance_flag:1;
        RBus_UInt32  res1:28;
    };
}epi_epi_dbg_reg_flag_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  den_num_det_en:1;
        RBus_UInt32  den_length_det_en:1;
        RBus_UInt32  hs_den_length_det_en:1;
        RBus_UInt32  hs_distance_det_en:1;
        RBus_UInt32  res1:28;
    };
}epi_epi_dbg_reg_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ctr12_ref_soe:2;
        RBus_UInt32  soe_table_line_cycle:2;
        RBus_UInt32  res1:28;
    };
}epi_epi_soe_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane0_soe0:18;
        RBus_UInt32  res1:14;
    };
}epi_epi_soe_line0_lane0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane0_soe1:18;
        RBus_UInt32  res1:14;
    };
}epi_epi_soe_line1_lane0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane0_soe2:18;
        RBus_UInt32  res1:14;
    };
}epi_epi_soe_line2_lane0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane0_soe3:18;
        RBus_UInt32  res1:14;
    };
}epi_epi_soe_line3_lane0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane1_soe0:18;
        RBus_UInt32  res1:14;
    };
}epi_epi_soe_line0_lane1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane1_soe1:18;
        RBus_UInt32  res1:14;
    };
}epi_epi_soe_line1_lane1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane1_soe2:18;
        RBus_UInt32  res1:14;
    };
}epi_epi_soe_line2_lane1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane1_soe3:18;
        RBus_UInt32  res1:14;
    };
}epi_epi_soe_line3_lane1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane2_soe0:18;
        RBus_UInt32  res1:14;
    };
}epi_epi_soe_line0_lane2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane2_soe1:18;
        RBus_UInt32  res1:14;
    };
}epi_epi_soe_line1_lane2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane2_soe2:18;
        RBus_UInt32  res1:14;
    };
}epi_epi_soe_line2_lane2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane2_soe3:18;
        RBus_UInt32  res1:14;
    };
}epi_epi_soe_line3_lane2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane3_soe0:18;
        RBus_UInt32  res1:14;
    };
}epi_epi_soe_line0_lane3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane3_soe1:18;
        RBus_UInt32  res1:14;
    };
}epi_epi_soe_line1_lane3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane3_soe2:18;
        RBus_UInt32  res1:14;
    };
}epi_epi_soe_line2_lane3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane3_soe3:18;
        RBus_UInt32  res1:14;
    };
}epi_epi_soe_line3_lane3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane4_soe0:18;
        RBus_UInt32  res1:14;
    };
}epi_epi_soe_line0_lane4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane4_soe1:18;
        RBus_UInt32  res1:14;
    };
}epi_epi_soe_line1_lane4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane4_soe2:18;
        RBus_UInt32  res1:14;
    };
}epi_epi_soe_line2_lane4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane4_soe3:18;
        RBus_UInt32  res1:14;
    };
}epi_epi_soe_line3_lane4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane5_soe0:18;
        RBus_UInt32  res1:14;
    };
}epi_epi_soe_line0_lane5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane5_soe1:18;
        RBus_UInt32  res1:14;
    };
}epi_epi_soe_line1_lane5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane5_soe2:18;
        RBus_UInt32  res1:14;
    };
}epi_epi_soe_line2_lane5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane5_soe3:18;
        RBus_UInt32  res1:14;
    };
}epi_epi_soe_line3_lane5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane6_soe0:18;
        RBus_UInt32  res1:14;
    };
}epi_epi_soe_line0_lane6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane6_soe1:18;
        RBus_UInt32  res1:14;
    };
}epi_epi_soe_line1_lane6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane6_soe2:18;
        RBus_UInt32  res1:14;
    };
}epi_epi_soe_line2_lane6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane6_soe3:18;
        RBus_UInt32  res1:14;
    };
}epi_epi_soe_line3_lane6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane7_soe0:18;
        RBus_UInt32  res1:14;
    };
}epi_epi_soe_line0_lane7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane7_soe1:18;
        RBus_UInt32  res1:14;
    };
}epi_epi_soe_line1_lane7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane7_soe2:18;
        RBus_UInt32  res1:14;
    };
}epi_epi_soe_line2_lane7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane7_soe3:18;
        RBus_UInt32  res1:14;
    };
}epi_epi_soe_line3_lane7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane_d_st_c0_mux_sel:6;
        RBus_UInt32  lane_d_st_c1_mux_sel:6;
        RBus_UInt32  lane_d_st_c2_mux_sel:6;
        RBus_UInt32  lane_d_st_c3_mux_sel:6;
        RBus_UInt32  lane_d_st_c4_mux_sel:6;
        RBus_UInt32  res1:2;
    };
}epi_epi_lane_dst_mux0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane_d_st_c5_mux_sel:6;
        RBus_UInt32  lane_d_st_c6_mux_sel:6;
        RBus_UInt32  lane_d_st_c7_mux_sel:6;
        RBus_UInt32  lane_d_st_c8_mux_sel:6;
        RBus_UInt32  lane_d_st_c9_mux_sel:6;
        RBus_UInt32  res1:2;
    };
}epi_epi_lane_dst_mux1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane_d_st_c10_mux_sel:6;
        RBus_UInt32  lane_d_st_c11_mux_sel:6;
        RBus_UInt32  lane_d_st_c12_mux_sel:6;
        RBus_UInt32  lane_d_st_c13_mux_sel:6;
        RBus_UInt32  lane_d_st_c14_mux_sel:6;
        RBus_UInt32  res1:2;
    };
}epi_epi_lane_dst_mux2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane_d_st_c15_mux_sel:6;
        RBus_UInt32  lane_d_st_c16_mux_sel:6;
        RBus_UInt32  lane_d_st_c17_mux_sel:6;
        RBus_UInt32  lane_d_st_c18_mux_sel:6;
        RBus_UInt32  lane_d_st_c19_mux_sel:6;
        RBus_UInt32  res1:2;
    };
}epi_epi_lane_dst_mux3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane_d_st_c20_mux_sel:6;
        RBus_UInt32  lane_d_st_c21_mux_sel:6;
        RBus_UInt32  lane_d_st_c22_mux_sel:6;
        RBus_UInt32  lane_d_st_c23_mux_sel:6;
        RBus_UInt32  lane_d_st_c24_mux_sel:6;
        RBus_UInt32  res1:2;
    };
}epi_epi_lane_dst_mux4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane_d_st_c25_mux_sel:6;
        RBus_UInt32  lane_d_st_c26_mux_sel:6;
        RBus_UInt32  lane_d_st_c27_mux_sel:6;
        RBus_UInt32  lane_d_st_c28_mux_sel:6;
        RBus_UInt32  lane_d_st_c29_mux_sel:6;
        RBus_UInt32  res1:2;
    };
}epi_epi_lane_dst_mux5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane_c_st_c0_mux_sel:6;
        RBus_UInt32  lane_c_st_c1_mux_sel:6;
        RBus_UInt32  lane_c_st_c2_mux_sel:6;
        RBus_UInt32  lane_c_st_c3_mux_sel:6;
        RBus_UInt32  lane_c_st_c4_mux_sel:6;
        RBus_UInt32  res1:2;
    };
}epi_epi_lane_cst_mux0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane_c_st_c5_mux_sel:6;
        RBus_UInt32  lane_c_st_c6_mux_sel:6;
        RBus_UInt32  lane_c_st_c7_mux_sel:6;
        RBus_UInt32  lane_c_st_c8_mux_sel:6;
        RBus_UInt32  lane_c_st_c9_mux_sel:6;
        RBus_UInt32  res1:2;
    };
}epi_epi_lane_cst_mux1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane_c_st_c10_mux_sel:6;
        RBus_UInt32  lane_c_st_c11_mux_sel:6;
        RBus_UInt32  lane_c_st_c12_mux_sel:6;
        RBus_UInt32  lane_c_st_c13_mux_sel:6;
        RBus_UInt32  lane_c_st_c14_mux_sel:6;
        RBus_UInt32  res1:2;
    };
}epi_epi_lane_cst_mux2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane_c_st_c15_mux_sel:6;
        RBus_UInt32  lane_c_st_c16_mux_sel:6;
        RBus_UInt32  lane_c_st_c17_mux_sel:6;
        RBus_UInt32  lane_c_st_c18_mux_sel:6;
        RBus_UInt32  lane_c_st_c19_mux_sel:6;
        RBus_UInt32  res1:2;
    };
}epi_epi_lane_cst_mux3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane_c_st_c20_mux_sel:6;
        RBus_UInt32  lane_c_st_c21_mux_sel:6;
        RBus_UInt32  lane_c_st_c22_mux_sel:6;
        RBus_UInt32  lane_c_st_c23_mux_sel:6;
        RBus_UInt32  lane_c_st_c24_mux_sel:6;
        RBus_UInt32  res1:2;
    };
}epi_epi_lane_cst_mux4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane_c_st_c25_mux_sel:6;
        RBus_UInt32  lane_c_st_c26_mux_sel:6;
        RBus_UInt32  lane_c_st_c27_mux_sel:6;
        RBus_UInt32  lane_c_st_c28_mux_sel:6;
        RBus_UInt32  lane_c_st_c29_mux_sel:6;
        RBus_UInt32  res1:2;
    };
}epi_epi_lane_cst_mux5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane_ctr1_c0_mux_sel:6;
        RBus_UInt32  lane_ctr1_c1_mux_sel:6;
        RBus_UInt32  lane_ctr1_c2_mux_sel:6;
        RBus_UInt32  lane_ctr1_c3_mux_sel:6;
        RBus_UInt32  lane_ctr1_c4_mux_sel:6;
        RBus_UInt32  res1:2;
    };
}epi_epi_lane_ctr1_mux0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane_ctr1_c5_mux_sel:6;
        RBus_UInt32  lane_ctr1_c6_mux_sel:6;
        RBus_UInt32  lane_ctr1_c7_mux_sel:6;
        RBus_UInt32  lane_ctr1_c8_mux_sel:6;
        RBus_UInt32  lane_ctr1_c9_mux_sel:6;
        RBus_UInt32  res1:2;
    };
}epi_epi_lane_ctr1_mux1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane_ctr1_c10_mux_sel:6;
        RBus_UInt32  lane_ctr1_c11_mux_sel:6;
        RBus_UInt32  lane_ctr1_c12_mux_sel:6;
        RBus_UInt32  lane_ctr1_c13_mux_sel:6;
        RBus_UInt32  lane_ctr1_c14_mux_sel:6;
        RBus_UInt32  res1:2;
    };
}epi_epi_lane_ctr1_mux2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane_ctr1_c15_mux_sel:6;
        RBus_UInt32  lane_ctr1_c16_mux_sel:6;
        RBus_UInt32  lane_ctr1_c17_mux_sel:6;
        RBus_UInt32  lane_ctr1_c18_mux_sel:6;
        RBus_UInt32  lane_ctr1_c19_mux_sel:6;
        RBus_UInt32  res1:2;
    };
}epi_epi_lane_ctr1_mux3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane_ctr1_c20_mux_sel:6;
        RBus_UInt32  lane_ctr1_c21_mux_sel:6;
        RBus_UInt32  lane_ctr1_c22_mux_sel:6;
        RBus_UInt32  lane_ctr1_c23_mux_sel:6;
        RBus_UInt32  lane_ctr1_c24_mux_sel:6;
        RBus_UInt32  res1:2;
    };
}epi_epi_lane_ctr1_mux4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane_ctr1_c25_mux_sel:6;
        RBus_UInt32  lane_ctr1_c26_mux_sel:6;
        RBus_UInt32  lane_ctr1_c27_mux_sel:6;
        RBus_UInt32  lane_ctr1_c28_mux_sel:6;
        RBus_UInt32  lane_ctr1_c29_mux_sel:6;
        RBus_UInt32  res1:2;
    };
}epi_epi_lane_ctr1_mux5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane_ctr2_c0_mux_sel:6;
        RBus_UInt32  lane_ctr2_c1_mux_sel:6;
        RBus_UInt32  lane_ctr2_c2_mux_sel:6;
        RBus_UInt32  lane_ctr2_c3_mux_sel:6;
        RBus_UInt32  lane_ctr2_c4_mux_sel:6;
        RBus_UInt32  res1:2;
    };
}epi_epi_lane_ctr2_mux0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane_ctr2_c5_mux_sel:6;
        RBus_UInt32  lane_ctr2_c6_mux_sel:6;
        RBus_UInt32  lane_ctr2_c7_mux_sel:6;
        RBus_UInt32  lane_ctr2_c8_mux_sel:6;
        RBus_UInt32  lane_ctr2_c9_mux_sel:6;
        RBus_UInt32  res1:2;
    };
}epi_epi_lane_ctr2_mux1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane_ctr2_c10_mux_sel:6;
        RBus_UInt32  lane_ctr2_c11_mux_sel:6;
        RBus_UInt32  lane_ctr2_c12_mux_sel:6;
        RBus_UInt32  lane_ctr2_c13_mux_sel:6;
        RBus_UInt32  lane_ctr2_c14_mux_sel:6;
        RBus_UInt32  res1:2;
    };
}epi_epi_lane_ctr2_mux2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane_ctr2_c15_mux_sel:6;
        RBus_UInt32  lane_ctr2_c16_mux_sel:6;
        RBus_UInt32  lane_ctr2_c17_mux_sel:6;
        RBus_UInt32  lane_ctr2_c18_mux_sel:6;
        RBus_UInt32  lane_ctr2_c19_mux_sel:6;
        RBus_UInt32  res1:2;
    };
}epi_epi_lane_ctr2_mux3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane_ctr2_c20_mux_sel:6;
        RBus_UInt32  lane_ctr2_c21_mux_sel:6;
        RBus_UInt32  lane_ctr2_c22_mux_sel:6;
        RBus_UInt32  lane_ctr2_c23_mux_sel:6;
        RBus_UInt32  lane_ctr2_c24_mux_sel:6;
        RBus_UInt32  res1:2;
    };
}epi_epi_lane_ctr2_mux4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane_ctr2_c25_mux_sel:6;
        RBus_UInt32  lane_ctr2_c26_mux_sel:6;
        RBus_UInt32  lane_ctr2_c27_mux_sel:6;
        RBus_UInt32  lane_ctr2_c28_mux_sel:6;
        RBus_UInt32  lane_ctr2_c29_mux_sel:6;
        RBus_UInt32  res1:2;
    };
}epi_epi_lane_ctr2_mux5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane_ctr3_c0_mux_sel:6;
        RBus_UInt32  lane_ctr3_c1_mux_sel:6;
        RBus_UInt32  lane_ctr3_c2_mux_sel:6;
        RBus_UInt32  lane_ctr3_c3_mux_sel:6;
        RBus_UInt32  lane_ctr3_c4_mux_sel:6;
        RBus_UInt32  res1:2;
    };
}epi_epi_lane_ctr3_mux0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane_ctr3_c5_mux_sel:6;
        RBus_UInt32  lane_ctr3_c6_mux_sel:6;
        RBus_UInt32  lane_ctr3_c7_mux_sel:6;
        RBus_UInt32  lane_ctr3_c8_mux_sel:6;
        RBus_UInt32  lane_ctr3_c9_mux_sel:6;
        RBus_UInt32  res1:2;
    };
}epi_epi_lane_ctr3_mux1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane_ctr3_c10_mux_sel:6;
        RBus_UInt32  lane_ctr3_c11_mux_sel:6;
        RBus_UInt32  lane_ctr3_c12_mux_sel:6;
        RBus_UInt32  lane_ctr3_c13_mux_sel:6;
        RBus_UInt32  lane_ctr3_c14_mux_sel:6;
        RBus_UInt32  res1:2;
    };
}epi_epi_lane_ctr3_mux2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane_ctr3_c15_mux_sel:6;
        RBus_UInt32  lane_ctr3_c16_mux_sel:6;
        RBus_UInt32  lane_ctr3_c17_mux_sel:6;
        RBus_UInt32  lane_ctr3_c18_mux_sel:6;
        RBus_UInt32  lane_ctr3_c19_mux_sel:6;
        RBus_UInt32  res1:2;
    };
}epi_epi_lane_ctr3_mux3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane_ctr3_c20_mux_sel:6;
        RBus_UInt32  lane_ctr3_c21_mux_sel:6;
        RBus_UInt32  lane_ctr3_c22_mux_sel:6;
        RBus_UInt32  lane_ctr3_c23_mux_sel:6;
        RBus_UInt32  lane_ctr3_c24_mux_sel:6;
        RBus_UInt32  res1:2;
    };
}epi_epi_lane_ctr3_mux4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane_ctr3_c25_mux_sel:6;
        RBus_UInt32  lane_ctr3_c26_mux_sel:6;
        RBus_UInt32  lane_ctr3_c27_mux_sel:6;
        RBus_UInt32  lane_ctr3_c28_mux_sel:6;
        RBus_UInt32  lane_ctr3_c29_mux_sel:6;
        RBus_UInt32  res1:2;
    };
}epi_epi_lane_ctr3_mux5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon_a_sel:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  tcon_b_sel:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  tcon_c_sel:5;
        RBus_UInt32  res3:11;
    };
}epi_epi_tcon_mux_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon_d_sel:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  tcon_e_sel:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  tcon_f_sel:5;
        RBus_UInt32  res3:11;
    };
}epi_epi_tcon_mux1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon_g_sel:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  tcon_h_sel:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  tcon_i_sel:5;
        RBus_UInt32  res3:11;
    };
}epi_epi_tcon_mux2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon_j_sel:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  tcon_k_sel:5;
        RBus_UInt32  res2:19;
    };
}epi_epi_tcon_mux3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18026510_31_0:32;
    };
}epi_epi_dummy_reg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  d_st:30;
        RBus_UInt32  res1:2;
    };
}epi_epi_lane_dst_data_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c_st:30;
        RBus_UInt32  res1:2;
    };
}epi_epi_lane_cst_data_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane0_ctr1_even:30;
        RBus_UInt32  lane0_ctr1_oe_en:1;
        RBus_UInt32  res1:1;
    };
}epi_epi_lane0_ctr1_edata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane0_ctr1_odd:30;
        RBus_UInt32  res1:2;
    };
}epi_epi_lane0_ctr1_odata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane1_ctr1_even:30;
        RBus_UInt32  lane1_ctr1_oe_en:1;
        RBus_UInt32  res1:1;
    };
}epi_epi_lane1_ctr1_edata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane1_ctr1_odd:30;
        RBus_UInt32  res1:2;
    };
}epi_epi_lane1_ctr1_odata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane2_ctr1_even:30;
        RBus_UInt32  lane2_ctr1_oe_en:1;
        RBus_UInt32  res1:1;
    };
}epi_epi_lane2_ctr1_edata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane2_ctr1_odd:30;
        RBus_UInt32  res1:2;
    };
}epi_epi_lane2_ctr1_odata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane3_ctr1_even:30;
        RBus_UInt32  lane3_ctr1_oe_en:1;
        RBus_UInt32  res1:1;
    };
}epi_epi_lane3_ctr1_edata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane3_ctr1_odd:30;
        RBus_UInt32  res1:2;
    };
}epi_epi_lane3_ctr1_odata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane4_ctr1_even:30;
        RBus_UInt32  lane4_ctr1_oe_en:1;
        RBus_UInt32  res1:1;
    };
}epi_epi_lane4_ctr1_edata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane4_ctr1_odd:30;
        RBus_UInt32  res1:2;
    };
}epi_epi_lane4_ctr1_odata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane5_ctr1_even:30;
        RBus_UInt32  lane5_ctr1_oe_en:1;
        RBus_UInt32  res1:1;
    };
}epi_epi_lane5_ctr1_edata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane5_ctr1_odd:30;
        RBus_UInt32  res1:2;
    };
}epi_epi_lane5_ctr1_odata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane6_ctr1_even:30;
        RBus_UInt32  lane6_ctr1_oe_en:1;
        RBus_UInt32  res1:1;
    };
}epi_epi_lane6_ctr1_edata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane6_ctr1_odd:30;
        RBus_UInt32  res1:2;
    };
}epi_epi_lane6_ctr1_odata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane7_ctr1_even:30;
        RBus_UInt32  lane7_ctr1_oe_en:1;
        RBus_UInt32  res1:1;
    };
}epi_epi_lane7_ctr1_edata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane7_ctr1_odd:30;
        RBus_UInt32  res1:2;
    };
}epi_epi_lane7_ctr1_odata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane0_ctr2_even:30;
        RBus_UInt32  lane0_ctr2_oe_en:1;
        RBus_UInt32  res1:1;
    };
}epi_epi_lane0_ctr2_edata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane0_ctr2_odd:30;
        RBus_UInt32  res1:2;
    };
}epi_epi_lane0_ctr2_odata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane1_ctr2_even:30;
        RBus_UInt32  lane1_ctr2_oe_en:1;
        RBus_UInt32  res1:1;
    };
}epi_epi_lane1_ctr2_edata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane1_ctr2_odd:30;
        RBus_UInt32  res1:2;
    };
}epi_epi_lane1_ctr2_odata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane2_ctr2_even:30;
        RBus_UInt32  lane2_ctr2_oe_en:1;
        RBus_UInt32  res1:1;
    };
}epi_epi_lane2_ctr2_edata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane2_ctr2_odd:30;
        RBus_UInt32  res1:2;
    };
}epi_epi_lane2_ctr2_odata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane3_ctr2_even:30;
        RBus_UInt32  lane3_ctr2_oe_en:1;
        RBus_UInt32  res1:1;
    };
}epi_epi_lane3_ctr2_edata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane3_ctr2_odd:30;
        RBus_UInt32  res1:2;
    };
}epi_epi_lane3_ctr2_odata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane4_ctr2_even:30;
        RBus_UInt32  lane4_ctr2_oe_en:1;
        RBus_UInt32  res1:1;
    };
}epi_epi_lane4_ctr2_edata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane4_ctr2_odd:30;
        RBus_UInt32  res1:2;
    };
}epi_epi_lane4_ctr2_odata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane5_ctr2_even:30;
        RBus_UInt32  lane5_ctr2_oe_en:1;
        RBus_UInt32  res1:1;
    };
}epi_epi_lane5_ctr2_edata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane5_ctr2_odd:30;
        RBus_UInt32  res1:2;
    };
}epi_epi_lane5_ctr2_odata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane6_ctr2_even:30;
        RBus_UInt32  lane6_ctr2_oe_en:1;
        RBus_UInt32  res1:1;
    };
}epi_epi_lane6_ctr2_edata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane6_ctr2_odd:30;
        RBus_UInt32  res1:2;
    };
}epi_epi_lane6_ctr2_odata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane7_ctr2_even:30;
        RBus_UInt32  lane7_ctr2_oe_en:1;
        RBus_UInt32  res1:1;
    };
}epi_epi_lane7_ctr2_edata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane7_ctr2_odd:30;
        RBus_UInt32  res1:2;
    };
}epi_epi_lane7_ctr2_odata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane0_ctr3_even:30;
        RBus_UInt32  lane0_ctr3_oe_en:1;
        RBus_UInt32  res1:1;
    };
}epi_epi_lane0_ctr3_edata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane0_ctr3_odd:30;
        RBus_UInt32  res1:2;
    };
}epi_epi_lane0_ctr3_odata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane1_ctr3_even:30;
        RBus_UInt32  lane1_ctr3_oe_en:1;
        RBus_UInt32  res1:1;
    };
}epi_epi_lane1_ctr3_edata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane1_ctr3_odd:30;
        RBus_UInt32  res1:2;
    };
}epi_epi_lane1_ctr3_odata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane2_ctr3_even:30;
        RBus_UInt32  lane2_ctr3_oe_en:1;
        RBus_UInt32  res1:1;
    };
}epi_epi_lane2_ctr3_edata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane2_ctr3_odd:30;
        RBus_UInt32  res1:2;
    };
}epi_epi_lane2_ctr3_odata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane3_ctr3_even:30;
        RBus_UInt32  lane3_ctr3_oe_en:1;
        RBus_UInt32  res1:1;
    };
}epi_epi_lane3_ctr3_edata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane3_ctr3_odd:30;
        RBus_UInt32  res1:2;
    };
}epi_epi_lane3_ctr3_odata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane4_ctr3_even:30;
        RBus_UInt32  lane4_ctr3_oe_en:1;
        RBus_UInt32  res1:1;
    };
}epi_epi_lane4_ctr3_edata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane4_ctr3_odd:30;
        RBus_UInt32  res1:2;
    };
}epi_epi_lane4_ctr3_odata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane5_ctr3_even:30;
        RBus_UInt32  lane5_ctr3_oe_en:1;
        RBus_UInt32  res1:1;
    };
}epi_epi_lane5_ctr3_edata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane5_ctr3_odd:30;
        RBus_UInt32  res1:2;
    };
}epi_epi_lane5_ctr3_odata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane6_ctr3_even:30;
        RBus_UInt32  lane6_ctr3_oe_en:1;
        RBus_UInt32  res1:1;
    };
}epi_epi_lane6_ctr3_edata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane6_ctr3_odd:30;
        RBus_UInt32  res1:2;
    };
}epi_epi_lane6_ctr3_odata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane7_ctr3_even:30;
        RBus_UInt32  lane7_ctr3_oe_en:1;
        RBus_UInt32  res1:1;
    };
}epi_epi_lane7_ctr3_edata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane7_ctr3_odd:30;
        RBus_UInt32  res1:2;
    };
}epi_epi_lane7_ctr3_odata_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gp_table_line_cycle:4;
        RBus_UInt32  res1:28;
    };
}epi_epi_gplut_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gp_table_line_0:16;
        RBus_UInt32  gp_table_line_1:16;
    };
}epi_epi_gplut_line_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gp_table_line_2:16;
        RBus_UInt32  gp_table_line_3:16;
    };
}epi_epi_gplut_line_23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gp_table_line_4:16;
        RBus_UInt32  gp_table_line_5:16;
    };
}epi_epi_gplut_line_45_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gp_table_line_6:16;
        RBus_UInt32  gp_table_line_7:16;
    };
}epi_epi_gplut_line_67_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gp_table_line_8:16;
        RBus_UInt32  gp_table_line_9:16;
    };
}epi_epi_gplut_line_89_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gp_table_line_10:16;
        RBus_UInt32  gp_table_line_11:16;
    };
}epi_epi_gplut_line_ab_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gp_table_line_12:16;
        RBus_UInt32  gp_table_line_13:16;
    };
}epi_epi_gplut_line_cd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gp_table_line_14:16;
        RBus_UInt32  gp_table_line_15:16;
    };
}epi_epi_gplut_line_ef_RBUS;




#endif 


#endif 
