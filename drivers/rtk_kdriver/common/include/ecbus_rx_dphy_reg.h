/**
* @file rbusECBUS_RX_DPHYReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2016/6/7
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_ECBUS_RX_DPHY_REG_H_
#define _RBUS_ECBUS_RX_DPHY_REG_H_

#include "rbus_types.h"



//  ECBUS_RX_DPHY Register Address
#define  ECBUS_RX_DPHY_ECBUS_DPHY_CTRL                                           0x18062F00
#define  ECBUS_RX_DPHY_ECBUS_DPHY_CTRL_reg_addr                                  "0xB8062F00"
#define  ECBUS_RX_DPHY_ECBUS_DPHY_CTRL_reg                                       0xB8062F00
#define  ECBUS_RX_DPHY_ECBUS_DPHY_CTRL_inst_addr                                 "0x0000"
#define  set_ECBUS_RX_DPHY_ECBUS_DPHY_CTRL_reg(data)                             (*((volatile unsigned int*)ECBUS_RX_DPHY_ECBUS_DPHY_CTRL_reg)=data)
#define  get_ECBUS_RX_DPHY_ECBUS_DPHY_CTRL_reg                                   (*((volatile unsigned int*)ECBUS_RX_DPHY_ECBUS_DPHY_CTRL_reg))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_CTRL_ecbus_dphy_rstn_shift                     (7)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_CTRL_ecbus_dphy_en_shift                       (6)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_CTRL_ecbus_clk_rx_inv_shift                    (5)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_CTRL_bub_remove_shift                          (4)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_CTRL_bub_2stage_shift                          (3)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_CTRL_ecbus_clk_tx_inv_shift                    (2)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_CTRL_ecbus_rx_tail_mask_shift                  (0)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_CTRL_ecbus_dphy_rstn_mask                      (0x00000080)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_CTRL_ecbus_dphy_en_mask                        (0x00000040)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_CTRL_ecbus_clk_rx_inv_mask                     (0x00000020)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_CTRL_bub_remove_mask                           (0x00000010)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_CTRL_bub_2stage_mask                           (0x00000008)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_CTRL_ecbus_clk_tx_inv_mask                     (0x00000004)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_CTRL_ecbus_rx_tail_mask_mask                   (0x00000003)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_CTRL_ecbus_dphy_rstn(data)                     (0x00000080&((data)<<7))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_CTRL_ecbus_dphy_en(data)                       (0x00000040&((data)<<6))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_CTRL_ecbus_clk_rx_inv(data)                    (0x00000020&((data)<<5))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_CTRL_bub_remove(data)                          (0x00000010&((data)<<4))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_CTRL_bub_2stage(data)                          (0x00000008&((data)<<3))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_CTRL_ecbus_clk_tx_inv(data)                    (0x00000004&((data)<<2))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_CTRL_ecbus_rx_tail_mask(data)                  (0x00000003&(data))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_CTRL_get_ecbus_dphy_rstn(data)                 ((0x00000080&(data))>>7)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_CTRL_get_ecbus_dphy_en(data)                   ((0x00000040&(data))>>6)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_CTRL_get_ecbus_clk_rx_inv(data)                ((0x00000020&(data))>>5)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_CTRL_get_bub_remove(data)                      ((0x00000010&(data))>>4)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_CTRL_get_bub_2stage(data)                      ((0x00000008&(data))>>3)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_CTRL_get_ecbus_clk_tx_inv(data)                ((0x00000004&(data))>>2)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_CTRL_get_ecbus_rx_tail_mask(data)              (0x00000003&(data))

#define  ECBUS_RX_DPHY_ECBUS_DPHY_EDGE_CTRL                                      0x18062F04
#define  ECBUS_RX_DPHY_ECBUS_DPHY_EDGE_CTRL_reg_addr                             "0xB8062F04"
#define  ECBUS_RX_DPHY_ECBUS_DPHY_EDGE_CTRL_reg                                  0xB8062F04
#define  ECBUS_RX_DPHY_ECBUS_DPHY_EDGE_CTRL_inst_addr                            "0x0001"
#define  set_ECBUS_RX_DPHY_ECBUS_DPHY_EDGE_CTRL_reg(data)                        (*((volatile unsigned int*)ECBUS_RX_DPHY_ECBUS_DPHY_EDGE_CTRL_reg)=data)
#define  get_ECBUS_RX_DPHY_ECBUS_DPHY_EDGE_CTRL_reg                              (*((volatile unsigned int*)ECBUS_RX_DPHY_ECBUS_DPHY_EDGE_CTRL_reg))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_EDGE_CTRL_edge_pos_manual_shift                (7)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_EDGE_CTRL_edge_position_m_5_0_shift            (1)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_EDGE_CTRL_edge_calib_en_shift                  (0)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_EDGE_CTRL_edge_pos_manual_mask                 (0x00000080)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_EDGE_CTRL_edge_position_m_5_0_mask             (0x0000007E)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_EDGE_CTRL_edge_calib_en_mask                   (0x00000001)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_EDGE_CTRL_edge_pos_manual(data)                (0x00000080&((data)<<7))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_EDGE_CTRL_edge_position_m_5_0(data)            (0x0000007E&((data)<<1))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_EDGE_CTRL_edge_calib_en(data)                  (0x00000001&(data))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_EDGE_CTRL_get_edge_pos_manual(data)            ((0x00000080&(data))>>7)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_EDGE_CTRL_get_edge_position_m_5_0(data)        ((0x0000007E&(data))>>1)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_EDGE_CTRL_get_edge_calib_en(data)              (0x00000001&(data))

#define  ECBUS_RX_DPHY_ECBUS_DPHY_EDGE_RESULT                                    0x18062F08
#define  ECBUS_RX_DPHY_ECBUS_DPHY_EDGE_RESULT_reg_addr                           "0xB8062F08"
#define  ECBUS_RX_DPHY_ECBUS_DPHY_EDGE_RESULT_reg                                0xB8062F08
#define  ECBUS_RX_DPHY_ECBUS_DPHY_EDGE_RESULT_inst_addr                          "0x0002"
#define  set_ECBUS_RX_DPHY_ECBUS_DPHY_EDGE_RESULT_reg(data)                      (*((volatile unsigned int*)ECBUS_RX_DPHY_ECBUS_DPHY_EDGE_RESULT_reg)=data)
#define  get_ECBUS_RX_DPHY_ECBUS_DPHY_EDGE_RESULT_reg                            (*((volatile unsigned int*)ECBUS_RX_DPHY_ECBUS_DPHY_EDGE_RESULT_reg))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_EDGE_RESULT_dummy_7_6_shift                    (6)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_EDGE_RESULT_edge_calib_position_5_0_shift      (0)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_EDGE_RESULT_dummy_7_6_mask                     (0x000000C0)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_EDGE_RESULT_edge_calib_position_5_0_mask       (0x0000003F)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_EDGE_RESULT_dummy_7_6(data)                    (0x000000C0&((data)<<6))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_EDGE_RESULT_edge_calib_position_5_0(data)      (0x0000003F&(data))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_EDGE_RESULT_get_dummy_7_6(data)                ((0x000000C0&(data))>>6)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_EDGE_RESULT_get_edge_calib_position_5_0(data)  (0x0000003F&(data))

#define  ECBUS_RX_DPHY_ECBUS_DPHY_STAT_CTRL                                      0x18062F0C
#define  ECBUS_RX_DPHY_ECBUS_DPHY_STAT_CTRL_reg_addr                             "0xB8062F0C"
#define  ECBUS_RX_DPHY_ECBUS_DPHY_STAT_CTRL_reg                                  0xB8062F0C
#define  ECBUS_RX_DPHY_ECBUS_DPHY_STAT_CTRL_inst_addr                            "0x0003"
#define  set_ECBUS_RX_DPHY_ECBUS_DPHY_STAT_CTRL_reg(data)                        (*((volatile unsigned int*)ECBUS_RX_DPHY_ECBUS_DPHY_STAT_CTRL_reg)=data)
#define  get_ECBUS_RX_DPHY_ECBUS_DPHY_STAT_CTRL_reg                              (*((volatile unsigned int*)ECBUS_RX_DPHY_ECBUS_DPHY_STAT_CTRL_reg))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_STAT_CTRL_stat_en_shift                        (7)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_STAT_CTRL_stat_manual_shift                    (6)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_STAT_CTRL_stat_ok_shift                        (5)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_STAT_CTRL_stat_safe_shift                      (4)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_STAT_CTRL_comma2_detect_shift                  (3)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_STAT_CTRL_no_disparity_shift                   (2)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_STAT_CTRL_dummy_1_0_shift                      (0)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_STAT_CTRL_stat_en_mask                         (0x00000080)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_STAT_CTRL_stat_manual_mask                     (0x00000040)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_STAT_CTRL_stat_ok_mask                         (0x00000020)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_STAT_CTRL_stat_safe_mask                       (0x00000010)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_STAT_CTRL_comma2_detect_mask                   (0x00000008)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_STAT_CTRL_no_disparity_mask                    (0x00000004)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_STAT_CTRL_dummy_1_0_mask                       (0x00000003)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_STAT_CTRL_stat_en(data)                        (0x00000080&((data)<<7))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_STAT_CTRL_stat_manual(data)                    (0x00000040&((data)<<6))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_STAT_CTRL_stat_ok(data)                        (0x00000020&((data)<<5))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_STAT_CTRL_stat_safe(data)                      (0x00000010&((data)<<4))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_STAT_CTRL_comma2_detect(data)                  (0x00000008&((data)<<3))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_STAT_CTRL_no_disparity(data)                   (0x00000004&((data)<<2))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_STAT_CTRL_dummy_1_0(data)                      (0x00000003&(data))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_STAT_CTRL_get_stat_en(data)                    ((0x00000080&(data))>>7)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_STAT_CTRL_get_stat_manual(data)                ((0x00000040&(data))>>6)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_STAT_CTRL_get_stat_ok(data)                    ((0x00000020&(data))>>5)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_STAT_CTRL_get_stat_safe(data)                  ((0x00000010&(data))>>4)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_STAT_CTRL_get_comma2_detect(data)              ((0x00000008&(data))>>3)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_STAT_CTRL_get_no_disparity(data)               ((0x00000004&(data))>>2)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_STAT_CTRL_get_dummy_1_0(data)                  (0x00000003&(data))

#define  ECBUS_RX_DPHY_ECBUS_DPHY_STAT_CONFIG_1                                  0x18062F10
#define  ECBUS_RX_DPHY_ECBUS_DPHY_STAT_CONFIG_1_reg_addr                         "0xB8062F10"
#define  ECBUS_RX_DPHY_ECBUS_DPHY_STAT_CONFIG_1_reg                              0xB8062F10
#define  ECBUS_RX_DPHY_ECBUS_DPHY_STAT_CONFIG_1_inst_addr                        "0x0004"
#define  set_ECBUS_RX_DPHY_ECBUS_DPHY_STAT_CONFIG_1_reg(data)                    (*((volatile unsigned int*)ECBUS_RX_DPHY_ECBUS_DPHY_STAT_CONFIG_1_reg)=data)
#define  get_ECBUS_RX_DPHY_ECBUS_DPHY_STAT_CONFIG_1_reg                          (*((volatile unsigned int*)ECBUS_RX_DPHY_ECBUS_DPHY_STAT_CONFIG_1_reg))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_STAT_CONFIG_1_stat_timeout_7_0_shift           (0)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_STAT_CONFIG_1_stat_timeout_7_0_mask            (0x000000FF)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_STAT_CONFIG_1_stat_timeout_7_0(data)           (0x000000FF&(data))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_STAT_CONFIG_1_get_stat_timeout_7_0(data)       (0x000000FF&(data))

#define  ECBUS_RX_DPHY_ECBUS_DPHY_STAT_CONFIG_2                                  0x18062F14
#define  ECBUS_RX_DPHY_ECBUS_DPHY_STAT_CONFIG_2_reg_addr                         "0xB8062F14"
#define  ECBUS_RX_DPHY_ECBUS_DPHY_STAT_CONFIG_2_reg                              0xB8062F14
#define  ECBUS_RX_DPHY_ECBUS_DPHY_STAT_CONFIG_2_inst_addr                        "0x0005"
#define  set_ECBUS_RX_DPHY_ECBUS_DPHY_STAT_CONFIG_2_reg(data)                    (*((volatile unsigned int*)ECBUS_RX_DPHY_ECBUS_DPHY_STAT_CONFIG_2_reg)=data)
#define  get_ECBUS_RX_DPHY_ECBUS_DPHY_STAT_CONFIG_2_reg                          (*((volatile unsigned int*)ECBUS_RX_DPHY_ECBUS_DPHY_STAT_CONFIG_2_reg))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_STAT_CONFIG_2_dummy_7_6_shift                  (6)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_STAT_CONFIG_2_stat_diff_th_5_0_shift           (0)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_STAT_CONFIG_2_dummy_7_6_mask                   (0x000000C0)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_STAT_CONFIG_2_stat_diff_th_5_0_mask            (0x0000003F)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_STAT_CONFIG_2_dummy_7_6(data)                  (0x000000C0&((data)<<6))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_STAT_CONFIG_2_stat_diff_th_5_0(data)           (0x0000003F&(data))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_STAT_CONFIG_2_get_dummy_7_6(data)              ((0x000000C0&(data))>>6)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_STAT_CONFIG_2_get_stat_diff_th_5_0(data)       (0x0000003F&(data))

#define  ECBUS_RX_DPHY_ECBUS_DPHY_STAT_RESULT_1                                  0x18062F18
#define  ECBUS_RX_DPHY_ECBUS_DPHY_STAT_RESULT_1_reg_addr                         "0xB8062F18"
#define  ECBUS_RX_DPHY_ECBUS_DPHY_STAT_RESULT_1_reg                              0xB8062F18
#define  ECBUS_RX_DPHY_ECBUS_DPHY_STAT_RESULT_1_inst_addr                        "0x0006"
#define  set_ECBUS_RX_DPHY_ECBUS_DPHY_STAT_RESULT_1_reg(data)                    (*((volatile unsigned int*)ECBUS_RX_DPHY_ECBUS_DPHY_STAT_RESULT_1_reg)=data)
#define  get_ECBUS_RX_DPHY_ECBUS_DPHY_STAT_RESULT_1_reg                          (*((volatile unsigned int*)ECBUS_RX_DPHY_ECBUS_DPHY_STAT_RESULT_1_reg))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_STAT_RESULT_1_dummy_7_6_shift                  (6)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_STAT_RESULT_1_stat_max_5_0_shift               (0)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_STAT_RESULT_1_dummy_7_6_mask                   (0x000000C0)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_STAT_RESULT_1_stat_max_5_0_mask                (0x0000003F)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_STAT_RESULT_1_dummy_7_6(data)                  (0x000000C0&((data)<<6))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_STAT_RESULT_1_stat_max_5_0(data)               (0x0000003F&(data))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_STAT_RESULT_1_get_dummy_7_6(data)              ((0x000000C0&(data))>>6)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_STAT_RESULT_1_get_stat_max_5_0(data)           (0x0000003F&(data))

#define  ECBUS_RX_DPHY_ECBUS_DPHY_STAT_RESULT_2                                  0x18062F1C
#define  ECBUS_RX_DPHY_ECBUS_DPHY_STAT_RESULT_2_reg_addr                         "0xB8062F1C"
#define  ECBUS_RX_DPHY_ECBUS_DPHY_STAT_RESULT_2_reg                              0xB8062F1C
#define  ECBUS_RX_DPHY_ECBUS_DPHY_STAT_RESULT_2_inst_addr                        "0x0007"
#define  set_ECBUS_RX_DPHY_ECBUS_DPHY_STAT_RESULT_2_reg(data)                    (*((volatile unsigned int*)ECBUS_RX_DPHY_ECBUS_DPHY_STAT_RESULT_2_reg)=data)
#define  get_ECBUS_RX_DPHY_ECBUS_DPHY_STAT_RESULT_2_reg                          (*((volatile unsigned int*)ECBUS_RX_DPHY_ECBUS_DPHY_STAT_RESULT_2_reg))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_STAT_RESULT_2_dummy_7_6_shift                  (6)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_STAT_RESULT_2_stat_min_5_0_shift               (0)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_STAT_RESULT_2_dummy_7_6_mask                   (0x000000C0)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_STAT_RESULT_2_stat_min_5_0_mask                (0x0000003F)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_STAT_RESULT_2_dummy_7_6(data)                  (0x000000C0&((data)<<6))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_STAT_RESULT_2_stat_min_5_0(data)               (0x0000003F&(data))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_STAT_RESULT_2_get_dummy_7_6(data)              ((0x000000C0&(data))>>6)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_STAT_RESULT_2_get_stat_min_5_0(data)           (0x0000003F&(data))

#define  ECBUS_RX_DPHY_ECBUS_DPHY_STAT_RESULT_3                                  0x18062F20
#define  ECBUS_RX_DPHY_ECBUS_DPHY_STAT_RESULT_3_reg_addr                         "0xB8062F20"
#define  ECBUS_RX_DPHY_ECBUS_DPHY_STAT_RESULT_3_reg                              0xB8062F20
#define  ECBUS_RX_DPHY_ECBUS_DPHY_STAT_RESULT_3_inst_addr                        "0x0008"
#define  set_ECBUS_RX_DPHY_ECBUS_DPHY_STAT_RESULT_3_reg(data)                    (*((volatile unsigned int*)ECBUS_RX_DPHY_ECBUS_DPHY_STAT_RESULT_3_reg)=data)
#define  get_ECBUS_RX_DPHY_ECBUS_DPHY_STAT_RESULT_3_reg                          (*((volatile unsigned int*)ECBUS_RX_DPHY_ECBUS_DPHY_STAT_RESULT_3_reg))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_STAT_RESULT_3_dummy_7_4_shift                  (4)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_STAT_RESULT_3_stat_timeout_flag_shift          (3)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_STAT_RESULT_3_stat_st_2_0_shift                (0)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_STAT_RESULT_3_dummy_7_4_mask                   (0x000000F0)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_STAT_RESULT_3_stat_timeout_flag_mask           (0x00000008)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_STAT_RESULT_3_stat_st_2_0_mask                 (0x00000007)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_STAT_RESULT_3_dummy_7_4(data)                  (0x000000F0&((data)<<4))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_STAT_RESULT_3_stat_timeout_flag(data)          (0x00000008&((data)<<3))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_STAT_RESULT_3_stat_st_2_0(data)                (0x00000007&(data))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_STAT_RESULT_3_get_dummy_7_4(data)              ((0x000000F0&(data))>>4)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_STAT_RESULT_3_get_stat_timeout_flag(data)      ((0x00000008&(data))>>3)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_STAT_RESULT_3_get_stat_st_2_0(data)            (0x00000007&(data))

#define  ECBUS_RX_DPHY_ECBUS_DPHY_CALIB_CTRL                                     0x18062F24
#define  ECBUS_RX_DPHY_ECBUS_DPHY_CALIB_CTRL_reg_addr                            "0xB8062F24"
#define  ECBUS_RX_DPHY_ECBUS_DPHY_CALIB_CTRL_reg                                 0xB8062F24
#define  ECBUS_RX_DPHY_ECBUS_DPHY_CALIB_CTRL_inst_addr                           "0x0009"
#define  set_ECBUS_RX_DPHY_ECBUS_DPHY_CALIB_CTRL_reg(data)                       (*((volatile unsigned int*)ECBUS_RX_DPHY_ECBUS_DPHY_CALIB_CTRL_reg)=data)
#define  get_ECBUS_RX_DPHY_ECBUS_DPHY_CALIB_CTRL_reg                             (*((volatile unsigned int*)ECBUS_RX_DPHY_ECBUS_DPHY_CALIB_CTRL_reg))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_CALIB_CTRL_ini_bound_en_shift                  (7)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_CALIB_CTRL_tx_calib_en_shift                   (6)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_CALIB_CTRL_adapt_nth_en_shift                  (5)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_CALIB_CTRL_nth_manual_shift                    (4)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_CALIB_CTRL_adapt_nth_end_shift                 (3)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_CALIB_CTRL_rxvalid_reload_shift                (2)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_CALIB_CTRL_raw_data_en_shift                   (1)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_CALIB_CTRL_dummy_0_shift                       (0)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_CALIB_CTRL_ini_bound_en_mask                   (0x00000080)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_CALIB_CTRL_tx_calib_en_mask                    (0x00000040)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_CALIB_CTRL_adapt_nth_en_mask                   (0x00000020)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_CALIB_CTRL_nth_manual_mask                     (0x00000010)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_CALIB_CTRL_adapt_nth_end_mask                  (0x00000008)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_CALIB_CTRL_rxvalid_reload_mask                 (0x00000004)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_CALIB_CTRL_raw_data_en_mask                    (0x00000002)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_CALIB_CTRL_dummy_0_mask                        (0x00000001)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_CALIB_CTRL_ini_bound_en(data)                  (0x00000080&((data)<<7))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_CALIB_CTRL_tx_calib_en(data)                   (0x00000040&((data)<<6))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_CALIB_CTRL_adapt_nth_en(data)                  (0x00000020&((data)<<5))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_CALIB_CTRL_nth_manual(data)                    (0x00000010&((data)<<4))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_CALIB_CTRL_adapt_nth_end(data)                 (0x00000008&((data)<<3))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_CALIB_CTRL_rxvalid_reload(data)                (0x00000004&((data)<<2))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_CALIB_CTRL_raw_data_en(data)                   (0x00000002&((data)<<1))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_CALIB_CTRL_dummy_0(data)                       (0x00000001&(data))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_CALIB_CTRL_get_ini_bound_en(data)              ((0x00000080&(data))>>7)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_CALIB_CTRL_get_tx_calib_en(data)               ((0x00000040&(data))>>6)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_CALIB_CTRL_get_adapt_nth_en(data)              ((0x00000020&(data))>>5)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_CALIB_CTRL_get_nth_manual(data)                ((0x00000010&(data))>>4)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_CALIB_CTRL_get_adapt_nth_end(data)             ((0x00000008&(data))>>3)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_CALIB_CTRL_get_rxvalid_reload(data)            ((0x00000004&(data))>>2)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_CALIB_CTRL_get_raw_data_en(data)               ((0x00000002&(data))>>1)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_CALIB_CTRL_get_dummy_0(data)                   (0x00000001&(data))

#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_CONFIG_1                                   0x18062F28
#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_CONFIG_1_reg_addr                          "0xB8062F28"
#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_CONFIG_1_reg                               0xB8062F28
#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_CONFIG_1_inst_addr                         "0x000A"
#define  set_ECBUS_RX_DPHY_ECBUS_DPHY_INI_CONFIG_1_reg(data)                     (*((volatile unsigned int*)ECBUS_RX_DPHY_ECBUS_DPHY_INI_CONFIG_1_reg)=data)
#define  get_ECBUS_RX_DPHY_ECBUS_DPHY_INI_CONFIG_1_reg                           (*((volatile unsigned int*)ECBUS_RX_DPHY_ECBUS_DPHY_INI_CONFIG_1_reg))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_CONFIG_1_ini_timeout_7_0_shift             (0)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_CONFIG_1_ini_timeout_7_0_mask              (0x000000FF)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_CONFIG_1_ini_timeout_7_0(data)             (0x000000FF&(data))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_CONFIG_1_get_ini_timeout_7_0(data)         (0x000000FF&(data))

#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_CONFIG_2                                   0x18062F2C
#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_CONFIG_2_reg_addr                          "0xB8062F2C"
#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_CONFIG_2_reg                               0xB8062F2C
#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_CONFIG_2_inst_addr                         "0x000B"
#define  set_ECBUS_RX_DPHY_ECBUS_DPHY_INI_CONFIG_2_reg(data)                     (*((volatile unsigned int*)ECBUS_RX_DPHY_ECBUS_DPHY_INI_CONFIG_2_reg)=data)
#define  get_ECBUS_RX_DPHY_ECBUS_DPHY_INI_CONFIG_2_reg                           (*((volatile unsigned int*)ECBUS_RX_DPHY_ECBUS_DPHY_INI_CONFIG_2_reg))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_CONFIG_2_ini_wait_cnt_7_0_shift            (0)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_CONFIG_2_ini_wait_cnt_7_0_mask             (0x000000FF)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_CONFIG_2_ini_wait_cnt_7_0(data)            (0x000000FF&(data))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_CONFIG_2_get_ini_wait_cnt_7_0(data)        (0x000000FF&(data))

#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_CONFIG_3                                   0x18062F30
#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_CONFIG_3_reg_addr                          "0xB8062F30"
#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_CONFIG_3_reg                               0xB8062F30
#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_CONFIG_3_inst_addr                         "0x000C"
#define  set_ECBUS_RX_DPHY_ECBUS_DPHY_INI_CONFIG_3_reg(data)                     (*((volatile unsigned int*)ECBUS_RX_DPHY_ECBUS_DPHY_INI_CONFIG_3_reg)=data)
#define  get_ECBUS_RX_DPHY_ECBUS_DPHY_INI_CONFIG_3_reg                           (*((volatile unsigned int*)ECBUS_RX_DPHY_ECBUS_DPHY_INI_CONFIG_3_reg))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_CONFIG_3_dummy_7_6_shift                   (6)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_CONFIG_3_nth_ini_5_0_shift                 (0)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_CONFIG_3_dummy_7_6_mask                    (0x000000C0)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_CONFIG_3_nth_ini_5_0_mask                  (0x0000003F)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_CONFIG_3_dummy_7_6(data)                   (0x000000C0&((data)<<6))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_CONFIG_3_nth_ini_5_0(data)                 (0x0000003F&(data))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_CONFIG_3_get_dummy_7_6(data)               ((0x000000C0&(data))>>6)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_CONFIG_3_get_nth_ini_5_0(data)             (0x0000003F&(data))

#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_CONFIG_4                                   0x18062F34
#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_CONFIG_4_reg_addr                          "0xB8062F34"
#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_CONFIG_4_reg                               0xB8062F34
#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_CONFIG_4_inst_addr                         "0x000D"
#define  set_ECBUS_RX_DPHY_ECBUS_DPHY_INI_CONFIG_4_reg(data)                     (*((volatile unsigned int*)ECBUS_RX_DPHY_ECBUS_DPHY_INI_CONFIG_4_reg)=data)
#define  get_ECBUS_RX_DPHY_ECBUS_DPHY_INI_CONFIG_4_reg                           (*((volatile unsigned int*)ECBUS_RX_DPHY_ECBUS_DPHY_INI_CONFIG_4_reg))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_CONFIG_4_dummy_7_4_shift                   (4)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_CONFIG_4_ini_cnt_2_0_shift                 (1)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_CONFIG_4_ini_eq_th_8_shift                 (0)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_CONFIG_4_dummy_7_4_mask                    (0x000000F0)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_CONFIG_4_ini_cnt_2_0_mask                  (0x0000000E)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_CONFIG_4_ini_eq_th_8_mask                  (0x00000001)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_CONFIG_4_dummy_7_4(data)                   (0x000000F0&((data)<<4))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_CONFIG_4_ini_cnt_2_0(data)                 (0x0000000E&((data)<<1))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_CONFIG_4_ini_eq_th_8(data)                 (0x00000001&(data))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_CONFIG_4_get_dummy_7_4(data)               ((0x000000F0&(data))>>4)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_CONFIG_4_get_ini_cnt_2_0(data)             ((0x0000000E&(data))>>1)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_CONFIG_4_get_ini_eq_th_8(data)             (0x00000001&(data))

#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_CONFIG_5                                   0x18062F38
#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_CONFIG_5_reg_addr                          "0xB8062F38"
#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_CONFIG_5_reg                               0xB8062F38
#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_CONFIG_5_inst_addr                         "0x000E"
#define  set_ECBUS_RX_DPHY_ECBUS_DPHY_INI_CONFIG_5_reg(data)                     (*((volatile unsigned int*)ECBUS_RX_DPHY_ECBUS_DPHY_INI_CONFIG_5_reg)=data)
#define  get_ECBUS_RX_DPHY_ECBUS_DPHY_INI_CONFIG_5_reg                           (*((volatile unsigned int*)ECBUS_RX_DPHY_ECBUS_DPHY_INI_CONFIG_5_reg))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_CONFIG_5_ini_eq_th_7_0_shift               (0)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_CONFIG_5_ini_eq_th_7_0_mask                (0x000000FF)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_CONFIG_5_ini_eq_th_7_0(data)               (0x000000FF&(data))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_CONFIG_5_get_ini_eq_th_7_0(data)           (0x000000FF&(data))

#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_RESULT_1                                   0x18062F3C
#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_RESULT_1_reg_addr                          "0xB8062F3C"
#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_RESULT_1_reg                               0xB8062F3C
#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_RESULT_1_inst_addr                         "0x000F"
#define  set_ECBUS_RX_DPHY_ECBUS_DPHY_INI_RESULT_1_reg(data)                     (*((volatile unsigned int*)ECBUS_RX_DPHY_ECBUS_DPHY_INI_RESULT_1_reg)=data)
#define  get_ECBUS_RX_DPHY_ECBUS_DPHY_INI_RESULT_1_reg                           (*((volatile unsigned int*)ECBUS_RX_DPHY_ECBUS_DPHY_INI_RESULT_1_reg))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_RESULT_1_dummy_7_6_shift                   (6)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_RESULT_1_calib_nth_5_0_shift               (0)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_RESULT_1_dummy_7_6_mask                    (0x000000C0)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_RESULT_1_calib_nth_5_0_mask                (0x0000003F)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_RESULT_1_dummy_7_6(data)                   (0x000000C0&((data)<<6))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_RESULT_1_calib_nth_5_0(data)               (0x0000003F&(data))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_RESULT_1_get_dummy_7_6(data)               ((0x000000C0&(data))>>6)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_RESULT_1_get_calib_nth_5_0(data)           (0x0000003F&(data))

#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_RESULT_2                                   0x18062F40
#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_RESULT_2_reg_addr                          "0xB8062F40"
#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_RESULT_2_reg                               0xB8062F40
#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_RESULT_2_inst_addr                         "0x0010"
#define  set_ECBUS_RX_DPHY_ECBUS_DPHY_INI_RESULT_2_reg(data)                     (*((volatile unsigned int*)ECBUS_RX_DPHY_ECBUS_DPHY_INI_RESULT_2_reg)=data)
#define  get_ECBUS_RX_DPHY_ECBUS_DPHY_INI_RESULT_2_reg                           (*((volatile unsigned int*)ECBUS_RX_DPHY_ECBUS_DPHY_INI_RESULT_2_reg))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_RESULT_2_dummy_7_6_shift                   (6)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_RESULT_2_calib_nth_max_5_0_shift           (0)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_RESULT_2_dummy_7_6_mask                    (0x000000C0)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_RESULT_2_calib_nth_max_5_0_mask            (0x0000003F)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_RESULT_2_dummy_7_6(data)                   (0x000000C0&((data)<<6))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_RESULT_2_calib_nth_max_5_0(data)           (0x0000003F&(data))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_RESULT_2_get_dummy_7_6(data)               ((0x000000C0&(data))>>6)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_RESULT_2_get_calib_nth_max_5_0(data)       (0x0000003F&(data))

#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_RESULT_3                                   0x18062F44
#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_RESULT_3_reg_addr                          "0xB8062F44"
#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_RESULT_3_reg                               0xB8062F44
#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_RESULT_3_inst_addr                         "0x0011"
#define  set_ECBUS_RX_DPHY_ECBUS_DPHY_INI_RESULT_3_reg(data)                     (*((volatile unsigned int*)ECBUS_RX_DPHY_ECBUS_DPHY_INI_RESULT_3_reg)=data)
#define  get_ECBUS_RX_DPHY_ECBUS_DPHY_INI_RESULT_3_reg                           (*((volatile unsigned int*)ECBUS_RX_DPHY_ECBUS_DPHY_INI_RESULT_3_reg))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_RESULT_3_dummy_7_6_shift                   (6)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_RESULT_3_calib_nth_min_5_0_shift           (0)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_RESULT_3_dummy_7_6_mask                    (0x000000C0)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_RESULT_3_calib_nth_min_5_0_mask            (0x0000003F)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_RESULT_3_dummy_7_6(data)                   (0x000000C0&((data)<<6))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_RESULT_3_calib_nth_min_5_0(data)           (0x0000003F&(data))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_RESULT_3_get_dummy_7_6(data)               ((0x000000C0&(data))>>6)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_RESULT_3_get_calib_nth_min_5_0(data)       (0x0000003F&(data))

#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_RESULT_4                                   0x18062F48
#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_RESULT_4_reg_addr                          "0xB8062F48"
#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_RESULT_4_reg                               0xB8062F48
#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_RESULT_4_inst_addr                         "0x0012"
#define  set_ECBUS_RX_DPHY_ECBUS_DPHY_INI_RESULT_4_reg(data)                     (*((volatile unsigned int*)ECBUS_RX_DPHY_ECBUS_DPHY_INI_RESULT_4_reg)=data)
#define  get_ECBUS_RX_DPHY_ECBUS_DPHY_INI_RESULT_4_reg                           (*((volatile unsigned int*)ECBUS_RX_DPHY_ECBUS_DPHY_INI_RESULT_4_reg))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_RESULT_4_dummy_7_4_shift                   (4)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_RESULT_4_ini_st_3_0_shift                  (0)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_RESULT_4_dummy_7_4_mask                    (0x000000F0)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_RESULT_4_ini_st_3_0_mask                   (0x0000000F)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_RESULT_4_dummy_7_4(data)                   (0x000000F0&((data)<<4))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_RESULT_4_ini_st_3_0(data)                  (0x0000000F&(data))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_RESULT_4_get_dummy_7_4(data)               ((0x000000F0&(data))>>4)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_INI_RESULT_4_get_ini_st_3_0(data)              (0x0000000F&(data))

#define  ECBUS_RX_DPHY_ECBUS_DPHY_TX_PHASE_CONFIG_1                              0x18062F4C
#define  ECBUS_RX_DPHY_ECBUS_DPHY_TX_PHASE_CONFIG_1_reg_addr                     "0xB8062F4C"
#define  ECBUS_RX_DPHY_ECBUS_DPHY_TX_PHASE_CONFIG_1_reg                          0xB8062F4C
#define  ECBUS_RX_DPHY_ECBUS_DPHY_TX_PHASE_CONFIG_1_inst_addr                    "0x0013"
#define  set_ECBUS_RX_DPHY_ECBUS_DPHY_TX_PHASE_CONFIG_1_reg(data)                (*((volatile unsigned int*)ECBUS_RX_DPHY_ECBUS_DPHY_TX_PHASE_CONFIG_1_reg)=data)
#define  get_ECBUS_RX_DPHY_ECBUS_DPHY_TX_PHASE_CONFIG_1_reg                      (*((volatile unsigned int*)ECBUS_RX_DPHY_ECBUS_DPHY_TX_PHASE_CONFIG_1_reg))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_TX_PHASE_CONFIG_1_txdata_high_wid_1_0_shift    (6)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_TX_PHASE_CONFIG_1_txdata_mode_1_0_shift        (4)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_TX_PHASE_CONFIG_1_txdata_delay_3_0_shift       (0)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_TX_PHASE_CONFIG_1_txdata_high_wid_1_0_mask     (0x000000C0)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_TX_PHASE_CONFIG_1_txdata_mode_1_0_mask         (0x00000030)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_TX_PHASE_CONFIG_1_txdata_delay_3_0_mask        (0x0000000F)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_TX_PHASE_CONFIG_1_txdata_high_wid_1_0(data)    (0x000000C0&((data)<<6))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_TX_PHASE_CONFIG_1_txdata_mode_1_0(data)        (0x00000030&((data)<<4))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_TX_PHASE_CONFIG_1_txdata_delay_3_0(data)       (0x0000000F&(data))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_TX_PHASE_CONFIG_1_get_txdata_high_wid_1_0(data) ((0x000000C0&(data))>>6)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_TX_PHASE_CONFIG_1_get_txdata_mode_1_0(data)    ((0x00000030&(data))>>4)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_TX_PHASE_CONFIG_1_get_txdata_delay_3_0(data)   (0x0000000F&(data))

#define  ECBUS_RX_DPHY_ECBUS_DPHY_TX_PHASE_CONFIG_2                              0x18062F50
#define  ECBUS_RX_DPHY_ECBUS_DPHY_TX_PHASE_CONFIG_2_reg_addr                     "0xB8062F50"
#define  ECBUS_RX_DPHY_ECBUS_DPHY_TX_PHASE_CONFIG_2_reg                          0xB8062F50
#define  ECBUS_RX_DPHY_ECBUS_DPHY_TX_PHASE_CONFIG_2_inst_addr                    "0x0014"
#define  set_ECBUS_RX_DPHY_ECBUS_DPHY_TX_PHASE_CONFIG_2_reg(data)                (*((volatile unsigned int*)ECBUS_RX_DPHY_ECBUS_DPHY_TX_PHASE_CONFIG_2_reg)=data)
#define  get_ECBUS_RX_DPHY_ECBUS_DPHY_TX_PHASE_CONFIG_2_reg                      (*((volatile unsigned int*)ECBUS_RX_DPHY_ECBUS_DPHY_TX_PHASE_CONFIG_2_reg))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_TX_PHASE_CONFIG_2_dummy_7_6_shift              (6)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_TX_PHASE_CONFIG_2_tx_phase_ini_5_0_shift       (0)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_TX_PHASE_CONFIG_2_dummy_7_6_mask               (0x000000C0)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_TX_PHASE_CONFIG_2_tx_phase_ini_5_0_mask        (0x0000003F)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_TX_PHASE_CONFIG_2_dummy_7_6(data)              (0x000000C0&((data)<<6))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_TX_PHASE_CONFIG_2_tx_phase_ini_5_0(data)       (0x0000003F&(data))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_TX_PHASE_CONFIG_2_get_dummy_7_6(data)          ((0x000000C0&(data))>>6)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_TX_PHASE_CONFIG_2_get_tx_phase_ini_5_0(data)   (0x0000003F&(data))

#define  ECBUS_RX_DPHY_ECBUS_DPHY_TX_PHASE_CONFIG_3                              0x18062F54
#define  ECBUS_RX_DPHY_ECBUS_DPHY_TX_PHASE_CONFIG_3_reg_addr                     "0xB8062F54"
#define  ECBUS_RX_DPHY_ECBUS_DPHY_TX_PHASE_CONFIG_3_reg                          0xB8062F54
#define  ECBUS_RX_DPHY_ECBUS_DPHY_TX_PHASE_CONFIG_3_inst_addr                    "0x0015"
#define  set_ECBUS_RX_DPHY_ECBUS_DPHY_TX_PHASE_CONFIG_3_reg(data)                (*((volatile unsigned int*)ECBUS_RX_DPHY_ECBUS_DPHY_TX_PHASE_CONFIG_3_reg)=data)
#define  get_ECBUS_RX_DPHY_ECBUS_DPHY_TX_PHASE_CONFIG_3_reg                      (*((volatile unsigned int*)ECBUS_RX_DPHY_ECBUS_DPHY_TX_PHASE_CONFIG_3_reg))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_TX_PHASE_CONFIG_3_dummy_7_6_shift              (6)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_TX_PHASE_CONFIG_3_tx_phase_max_shift           (0)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_TX_PHASE_CONFIG_3_dummy_7_6_mask               (0x000000C0)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_TX_PHASE_CONFIG_3_tx_phase_max_mask            (0x0000003F)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_TX_PHASE_CONFIG_3_dummy_7_6(data)              (0x000000C0&((data)<<6))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_TX_PHASE_CONFIG_3_tx_phase_max(data)           (0x0000003F&(data))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_TX_PHASE_CONFIG_3_get_dummy_7_6(data)          ((0x000000C0&(data))>>6)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_TX_PHASE_CONFIG_3_get_tx_phase_max(data)       (0x0000003F&(data))

#define  ECBUS_RX_DPHY_ECBUS_DPHY_TX_PHASE_CONFIG_4                              0x18062F58
#define  ECBUS_RX_DPHY_ECBUS_DPHY_TX_PHASE_CONFIG_4_reg_addr                     "0xB8062F58"
#define  ECBUS_RX_DPHY_ECBUS_DPHY_TX_PHASE_CONFIG_4_reg                          0xB8062F58
#define  ECBUS_RX_DPHY_ECBUS_DPHY_TX_PHASE_CONFIG_4_inst_addr                    "0x0016"
#define  set_ECBUS_RX_DPHY_ECBUS_DPHY_TX_PHASE_CONFIG_4_reg(data)                (*((volatile unsigned int*)ECBUS_RX_DPHY_ECBUS_DPHY_TX_PHASE_CONFIG_4_reg)=data)
#define  get_ECBUS_RX_DPHY_ECBUS_DPHY_TX_PHASE_CONFIG_4_reg                      (*((volatile unsigned int*)ECBUS_RX_DPHY_ECBUS_DPHY_TX_PHASE_CONFIG_4_reg))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_TX_PHASE_CONFIG_4_dummy_7_6_shift              (6)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_TX_PHASE_CONFIG_4_tx_phase_min_shift           (0)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_TX_PHASE_CONFIG_4_dummy_7_6_mask               (0x000000C0)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_TX_PHASE_CONFIG_4_tx_phase_min_mask            (0x0000003F)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_TX_PHASE_CONFIG_4_dummy_7_6(data)              (0x000000C0&((data)<<6))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_TX_PHASE_CONFIG_4_tx_phase_min(data)           (0x0000003F&(data))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_TX_PHASE_CONFIG_4_get_dummy_7_6(data)          ((0x000000C0&(data))>>6)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_TX_PHASE_CONFIG_4_get_tx_phase_min(data)       (0x0000003F&(data))

#define  ECBUS_RX_DPHY_ECBUS_DPHY_TX_PHASE_RESULT                                0x18062F5C
#define  ECBUS_RX_DPHY_ECBUS_DPHY_TX_PHASE_RESULT_reg_addr                       "0xB8062F5C"
#define  ECBUS_RX_DPHY_ECBUS_DPHY_TX_PHASE_RESULT_reg                            0xB8062F5C
#define  ECBUS_RX_DPHY_ECBUS_DPHY_TX_PHASE_RESULT_inst_addr                      "0x0017"
#define  set_ECBUS_RX_DPHY_ECBUS_DPHY_TX_PHASE_RESULT_reg(data)                  (*((volatile unsigned int*)ECBUS_RX_DPHY_ECBUS_DPHY_TX_PHASE_RESULT_reg)=data)
#define  get_ECBUS_RX_DPHY_ECBUS_DPHY_TX_PHASE_RESULT_reg                        (*((volatile unsigned int*)ECBUS_RX_DPHY_ECBUS_DPHY_TX_PHASE_RESULT_reg))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_TX_PHASE_RESULT_dummy_7_6_shift                (6)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_TX_PHASE_RESULT_calib_tx_phase_5_0_shift       (0)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_TX_PHASE_RESULT_dummy_7_6_mask                 (0x000000C0)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_TX_PHASE_RESULT_calib_tx_phase_5_0_mask        (0x0000003F)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_TX_PHASE_RESULT_dummy_7_6(data)                (0x000000C0&((data)<<6))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_TX_PHASE_RESULT_calib_tx_phase_5_0(data)       (0x0000003F&(data))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_TX_PHASE_RESULT_get_dummy_7_6(data)            ((0x000000C0&(data))>>6)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_TX_PHASE_RESULT_get_calib_tx_phase_5_0(data)   (0x0000003F&(data))

#define  ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_CTRL                                     0x18062F60
#define  ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_CTRL_reg_addr                            "0xB8062F60"
#define  ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_CTRL_reg                                 0xB8062F60
#define  ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_CTRL_inst_addr                           "0x0018"
#define  set_ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_CTRL_reg(data)                       (*((volatile unsigned int*)ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_CTRL_reg)=data)
#define  get_ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_CTRL_reg                             (*((volatile unsigned int*)ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_CTRL_reg))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_CTRL_dummy_7_2_shift                     (2)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_CTRL_adapt_mode_1_0_shift                (0)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_CTRL_dummy_7_2_mask                      (0x000000FC)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_CTRL_adapt_mode_1_0_mask                 (0x00000003)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_CTRL_dummy_7_2(data)                     (0x000000FC&((data)<<2))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_CTRL_adapt_mode_1_0(data)                (0x00000003&(data))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_CTRL_get_dummy_7_2(data)                 ((0x000000FC&(data))>>2)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_CTRL_get_adapt_mode_1_0(data)            (0x00000003&(data))

#define  ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_CONFIG_1                                 0x18062F64
#define  ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_CONFIG_1_reg_addr                        "0xB8062F64"
#define  ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_CONFIG_1_reg                             0xB8062F64
#define  ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_CONFIG_1_inst_addr                       "0x0019"
#define  set_ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_CONFIG_1_reg(data)                   (*((volatile unsigned int*)ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_CONFIG_1_reg)=data)
#define  get_ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_CONFIG_1_reg                         (*((volatile unsigned int*)ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_CONFIG_1_reg))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_CONFIG_1_adapt_timer_7_0_shift           (0)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_CONFIG_1_adapt_timer_7_0_mask            (0x000000FF)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_CONFIG_1_adapt_timer_7_0(data)           (0x000000FF&(data))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_CONFIG_1_get_adapt_timer_7_0(data)       (0x000000FF&(data))

#define  ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_CONFIG_2                                 0x18062F68
#define  ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_CONFIG_2_reg_addr                        "0xB8062F68"
#define  ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_CONFIG_2_reg                             0xB8062F68
#define  ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_CONFIG_2_inst_addr                       "0x001A"
#define  set_ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_CONFIG_2_reg(data)                   (*((volatile unsigned int*)ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_CONFIG_2_reg)=data)
#define  get_ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_CONFIG_2_reg                         (*((volatile unsigned int*)ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_CONFIG_2_reg))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_CONFIG_2_dummy_7_6_shift                 (6)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_CONFIG_2_nth_one_m_5_0_shift             (0)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_CONFIG_2_dummy_7_6_mask                  (0x000000C0)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_CONFIG_2_nth_one_m_5_0_mask              (0x0000003F)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_CONFIG_2_dummy_7_6(data)                 (0x000000C0&((data)<<6))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_CONFIG_2_nth_one_m_5_0(data)             (0x0000003F&(data))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_CONFIG_2_get_dummy_7_6(data)             ((0x000000C0&(data))>>6)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_CONFIG_2_get_nth_one_m_5_0(data)         (0x0000003F&(data))

#define  ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_CONFIG_3                                 0x18062F6C
#define  ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_CONFIG_3_reg_addr                        "0xB8062F6C"
#define  ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_CONFIG_3_reg                             0xB8062F6C
#define  ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_CONFIG_3_inst_addr                       "0x001B"
#define  set_ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_CONFIG_3_reg(data)                   (*((volatile unsigned int*)ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_CONFIG_3_reg)=data)
#define  get_ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_CONFIG_3_reg                         (*((volatile unsigned int*)ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_CONFIG_3_reg))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_CONFIG_3_dummy_7_6_shift                 (6)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_CONFIG_3_nth_zero_m_5_0_shift            (0)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_CONFIG_3_dummy_7_6_mask                  (0x000000C0)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_CONFIG_3_nth_zero_m_5_0_mask             (0x0000003F)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_CONFIG_3_dummy_7_6(data)                 (0x000000C0&((data)<<6))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_CONFIG_3_nth_zero_m_5_0(data)            (0x0000003F&(data))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_CONFIG_3_get_dummy_7_6(data)             ((0x000000C0&(data))>>6)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_CONFIG_3_get_nth_zero_m_5_0(data)        (0x0000003F&(data))

#define  ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_RESULT_1                                 0x18062F70
#define  ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_RESULT_1_reg_addr                        "0xB8062F70"
#define  ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_RESULT_1_reg                             0xB8062F70
#define  ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_RESULT_1_inst_addr                       "0x001C"
#define  set_ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_RESULT_1_reg(data)                   (*((volatile unsigned int*)ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_RESULT_1_reg)=data)
#define  get_ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_RESULT_1_reg                         (*((volatile unsigned int*)ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_RESULT_1_reg))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_RESULT_1_dummy_7_6_shift                 (6)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_RESULT_1_adapt_nth_one_5_0_shift         (0)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_RESULT_1_dummy_7_6_mask                  (0x000000C0)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_RESULT_1_adapt_nth_one_5_0_mask          (0x0000003F)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_RESULT_1_dummy_7_6(data)                 (0x000000C0&((data)<<6))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_RESULT_1_adapt_nth_one_5_0(data)         (0x0000003F&(data))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_RESULT_1_get_dummy_7_6(data)             ((0x000000C0&(data))>>6)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_RESULT_1_get_adapt_nth_one_5_0(data)     (0x0000003F&(data))

#define  ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_RESULT_2                                 0x18062F74
#define  ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_RESULT_2_reg_addr                        "0xB8062F74"
#define  ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_RESULT_2_reg                             0xB8062F74
#define  ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_RESULT_2_inst_addr                       "0x001D"
#define  set_ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_RESULT_2_reg(data)                   (*((volatile unsigned int*)ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_RESULT_2_reg)=data)
#define  get_ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_RESULT_2_reg                         (*((volatile unsigned int*)ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_RESULT_2_reg))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_RESULT_2_dummy_7_6_shift                 (6)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_RESULT_2_adapt_nth_zero_5_0_shift        (0)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_RESULT_2_dummy_7_6_mask                  (0x000000C0)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_RESULT_2_adapt_nth_zero_5_0_mask         (0x0000003F)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_RESULT_2_dummy_7_6(data)                 (0x000000C0&((data)<<6))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_RESULT_2_adapt_nth_zero_5_0(data)        (0x0000003F&(data))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_RESULT_2_get_dummy_7_6(data)             ((0x000000C0&(data))>>6)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_RESULT_2_get_adapt_nth_zero_5_0(data)    (0x0000003F&(data))

#define  ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_RESULT_3                                 0x18062F78
#define  ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_RESULT_3_reg_addr                        "0xB8062F78"
#define  ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_RESULT_3_reg                             0xB8062F78
#define  ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_RESULT_3_inst_addr                       "0x001E"
#define  set_ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_RESULT_3_reg(data)                   (*((volatile unsigned int*)ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_RESULT_3_reg)=data)
#define  get_ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_RESULT_3_reg                         (*((volatile unsigned int*)ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_RESULT_3_reg))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_RESULT_3_dummy_7_4_shift                 (4)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_RESULT_3_adapt_0_st_1_0_shift            (2)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_RESULT_3_adapt_1_st_1_0_shift            (0)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_RESULT_3_dummy_7_4_mask                  (0x000000F0)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_RESULT_3_adapt_0_st_1_0_mask             (0x0000000C)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_RESULT_3_adapt_1_st_1_0_mask             (0x00000003)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_RESULT_3_dummy_7_4(data)                 (0x000000F0&((data)<<4))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_RESULT_3_adapt_0_st_1_0(data)            (0x0000000C&((data)<<2))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_RESULT_3_adapt_1_st_1_0(data)            (0x00000003&(data))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_RESULT_3_get_dummy_7_4(data)             ((0x000000F0&(data))>>4)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_RESULT_3_get_adapt_0_st_1_0(data)        ((0x0000000C&(data))>>2)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_ADAPT_RESULT_3_get_adapt_1_st_1_0(data)        (0x00000003&(data))

#define  ECBUS_RX_DPHY_ECBUS_DPHY_CALIB_RESULT                                   0x18062F7C
#define  ECBUS_RX_DPHY_ECBUS_DPHY_CALIB_RESULT_reg_addr                          "0xB8062F7C"
#define  ECBUS_RX_DPHY_ECBUS_DPHY_CALIB_RESULT_reg                               0xB8062F7C
#define  ECBUS_RX_DPHY_ECBUS_DPHY_CALIB_RESULT_inst_addr                         "0x001F"
#define  set_ECBUS_RX_DPHY_ECBUS_DPHY_CALIB_RESULT_reg(data)                     (*((volatile unsigned int*)ECBUS_RX_DPHY_ECBUS_DPHY_CALIB_RESULT_reg)=data)
#define  get_ECBUS_RX_DPHY_ECBUS_DPHY_CALIB_RESULT_reg                           (*((volatile unsigned int*)ECBUS_RX_DPHY_ECBUS_DPHY_CALIB_RESULT_reg))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_CALIB_RESULT_dummy_7_3_shift                   (3)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_CALIB_RESULT_calib_st_2_0_shift                (0)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_CALIB_RESULT_dummy_7_3_mask                    (0x000000F8)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_CALIB_RESULT_calib_st_2_0_mask                 (0x00000007)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_CALIB_RESULT_dummy_7_3(data)                   (0x000000F8&((data)<<3))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_CALIB_RESULT_calib_st_2_0(data)                (0x00000007&(data))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_CALIB_RESULT_get_dummy_7_3(data)               ((0x000000F8&(data))>>3)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_CALIB_RESULT_get_calib_st_2_0(data)            (0x00000007&(data))

#define  ECBUS_RX_DPHY_ECBUS_DPHY_CONFIG                                         0x18062F80
#define  ECBUS_RX_DPHY_ECBUS_DPHY_CONFIG_reg_addr                                "0xB8062F80"
#define  ECBUS_RX_DPHY_ECBUS_DPHY_CONFIG_reg                                     0xB8062F80
#define  ECBUS_RX_DPHY_ECBUS_DPHY_CONFIG_inst_addr                               "0x0020"
#define  set_ECBUS_RX_DPHY_ECBUS_DPHY_CONFIG_reg(data)                           (*((volatile unsigned int*)ECBUS_RX_DPHY_ECBUS_DPHY_CONFIG_reg)=data)
#define  get_ECBUS_RX_DPHY_ECBUS_DPHY_CONFIG_reg                                 (*((volatile unsigned int*)ECBUS_RX_DPHY_ECBUS_DPHY_CONFIG_reg))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_CONFIG_rx_timeout_7_0_shift                    (0)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_CONFIG_rx_timeout_7_0_mask                     (0x000000FF)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_CONFIG_rx_timeout_7_0(data)                    (0x000000FF&(data))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_CONFIG_get_rx_timeout_7_0(data)                (0x000000FF&(data))

#define  ECBUS_RX_DPHY_ECBUS_DPHY_PATTERN_1                                      0x18062F84
#define  ECBUS_RX_DPHY_ECBUS_DPHY_PATTERN_1_reg_addr                             "0xB8062F84"
#define  ECBUS_RX_DPHY_ECBUS_DPHY_PATTERN_1_reg                                  0xB8062F84
#define  ECBUS_RX_DPHY_ECBUS_DPHY_PATTERN_1_inst_addr                            "0x0021"
#define  set_ECBUS_RX_DPHY_ECBUS_DPHY_PATTERN_1_reg(data)                        (*((volatile unsigned int*)ECBUS_RX_DPHY_ECBUS_DPHY_PATTERN_1_reg)=data)
#define  get_ECBUS_RX_DPHY_ECBUS_DPHY_PATTERN_1_reg                              (*((volatile unsigned int*)ECBUS_RX_DPHY_ECBUS_DPHY_PATTERN_1_reg))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_PATTERN_1_dummy_7_2_shift                      (2)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_PATTERN_1_comma2_pattern_9_8_shift             (0)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_PATTERN_1_dummy_7_2_mask                       (0x000000FC)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_PATTERN_1_comma2_pattern_9_8_mask              (0x00000003)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_PATTERN_1_dummy_7_2(data)                      (0x000000FC&((data)<<2))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_PATTERN_1_comma2_pattern_9_8(data)             (0x00000003&(data))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_PATTERN_1_get_dummy_7_2(data)                  ((0x000000FC&(data))>>2)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_PATTERN_1_get_comma2_pattern_9_8(data)         (0x00000003&(data))

#define  ECBUS_RX_DPHY_ECBUS_DPHY_PATTERN_2                                      0x18062F88
#define  ECBUS_RX_DPHY_ECBUS_DPHY_PATTERN_2_reg_addr                             "0xB8062F88"
#define  ECBUS_RX_DPHY_ECBUS_DPHY_PATTERN_2_reg                                  0xB8062F88
#define  ECBUS_RX_DPHY_ECBUS_DPHY_PATTERN_2_inst_addr                            "0x0022"
#define  set_ECBUS_RX_DPHY_ECBUS_DPHY_PATTERN_2_reg(data)                        (*((volatile unsigned int*)ECBUS_RX_DPHY_ECBUS_DPHY_PATTERN_2_reg)=data)
#define  get_ECBUS_RX_DPHY_ECBUS_DPHY_PATTERN_2_reg                              (*((volatile unsigned int*)ECBUS_RX_DPHY_ECBUS_DPHY_PATTERN_2_reg))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_PATTERN_2_comma2_pattern_7_0_shift             (0)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_PATTERN_2_comma2_pattern_7_0_mask              (0x000000FF)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_PATTERN_2_comma2_pattern_7_0(data)             (0x000000FF&(data))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_PATTERN_2_get_comma2_pattern_7_0(data)         (0x000000FF&(data))

#define  ECBUS_RX_DPHY_ECBUS_DPHY_FLAG                                           0x18062F8C
#define  ECBUS_RX_DPHY_ECBUS_DPHY_FLAG_reg_addr                                  "0xB8062F8C"
#define  ECBUS_RX_DPHY_ECBUS_DPHY_FLAG_reg                                       0xB8062F8C
#define  ECBUS_RX_DPHY_ECBUS_DPHY_FLAG_inst_addr                                 "0x0023"
#define  set_ECBUS_RX_DPHY_ECBUS_DPHY_FLAG_reg(data)                             (*((volatile unsigned int*)ECBUS_RX_DPHY_ECBUS_DPHY_FLAG_reg)=data)
#define  get_ECBUS_RX_DPHY_ECBUS_DPHY_FLAG_reg                                   (*((volatile unsigned int*)ECBUS_RX_DPHY_ECBUS_DPHY_FLAG_reg))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_FLAG_calib_nth_timeout_shift                   (7)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_FLAG_calib_nth_error_shift                     (6)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_FLAG_edge_error_shift                          (5)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_FLAG_rx_valid_shift                            (4)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_FLAG_rx_data_all_1_shift                       (3)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_FLAG_rx_data_all_0_shift                       (2)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_FLAG_dummy_1_0_shift                           (0)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_FLAG_calib_nth_timeout_mask                    (0x00000080)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_FLAG_calib_nth_error_mask                      (0x00000040)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_FLAG_edge_error_mask                           (0x00000020)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_FLAG_rx_valid_mask                             (0x00000010)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_FLAG_rx_data_all_1_mask                        (0x00000008)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_FLAG_rx_data_all_0_mask                        (0x00000004)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_FLAG_dummy_1_0_mask                            (0x00000003)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_FLAG_calib_nth_timeout(data)                   (0x00000080&((data)<<7))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_FLAG_calib_nth_error(data)                     (0x00000040&((data)<<6))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_FLAG_edge_error(data)                          (0x00000020&((data)<<5))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_FLAG_rx_valid(data)                            (0x00000010&((data)<<4))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_FLAG_rx_data_all_1(data)                       (0x00000008&((data)<<3))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_FLAG_rx_data_all_0(data)                       (0x00000004&((data)<<2))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_FLAG_dummy_1_0(data)                           (0x00000003&(data))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_FLAG_get_calib_nth_timeout(data)               ((0x00000080&(data))>>7)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_FLAG_get_calib_nth_error(data)                 ((0x00000040&(data))>>6)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_FLAG_get_edge_error(data)                      ((0x00000020&(data))>>5)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_FLAG_get_rx_valid(data)                        ((0x00000010&(data))>>4)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_FLAG_get_rx_data_all_1(data)                   ((0x00000008&(data))>>3)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_FLAG_get_rx_data_all_0(data)                   ((0x00000004&(data))>>2)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_FLAG_get_dummy_1_0(data)                       (0x00000003&(data))

#define  ECBUS_RX_DPHY_ECBUS_DPHY_IRQ                                            0x18062F90
#define  ECBUS_RX_DPHY_ECBUS_DPHY_IRQ_reg_addr                                   "0xB8062F90"
#define  ECBUS_RX_DPHY_ECBUS_DPHY_IRQ_reg                                        0xB8062F90
#define  ECBUS_RX_DPHY_ECBUS_DPHY_IRQ_inst_addr                                  "0x0024"
#define  set_ECBUS_RX_DPHY_ECBUS_DPHY_IRQ_reg(data)                              (*((volatile unsigned int*)ECBUS_RX_DPHY_ECBUS_DPHY_IRQ_reg)=data)
#define  get_ECBUS_RX_DPHY_ECBUS_DPHY_IRQ_reg                                    (*((volatile unsigned int*)ECBUS_RX_DPHY_ECBUS_DPHY_IRQ_reg))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_IRQ_dummy_7_6_shift                            (6)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_IRQ_rx_timeout_irq_en_shift                    (5)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_IRQ_rx_timeout_irq_shift                       (4)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_IRQ_dummy_3_2_shift                            (2)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_IRQ_stat_ok_irq_en_shift                       (1)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_IRQ_stat_ok_irq_shift                          (0)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_IRQ_dummy_7_6_mask                             (0x000000C0)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_IRQ_rx_timeout_irq_en_mask                     (0x00000020)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_IRQ_rx_timeout_irq_mask                        (0x00000010)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_IRQ_dummy_3_2_mask                             (0x0000000C)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_IRQ_stat_ok_irq_en_mask                        (0x00000002)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_IRQ_stat_ok_irq_mask                           (0x00000001)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_IRQ_dummy_7_6(data)                            (0x000000C0&((data)<<6))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_IRQ_rx_timeout_irq_en(data)                    (0x00000020&((data)<<5))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_IRQ_rx_timeout_irq(data)                       (0x00000010&((data)<<4))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_IRQ_dummy_3_2(data)                            (0x0000000C&((data)<<2))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_IRQ_stat_ok_irq_en(data)                       (0x00000002&((data)<<1))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_IRQ_stat_ok_irq(data)                          (0x00000001&(data))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_IRQ_get_dummy_7_6(data)                        ((0x000000C0&(data))>>6)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_IRQ_get_rx_timeout_irq_en(data)                ((0x00000020&(data))>>5)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_IRQ_get_rx_timeout_irq(data)                   ((0x00000010&(data))>>4)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_IRQ_get_dummy_3_2(data)                        ((0x0000000C&(data))>>2)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_IRQ_get_stat_ok_irq_en(data)                   ((0x00000002&(data))>>1)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_IRQ_get_stat_ok_irq(data)                      (0x00000001&(data))

#define  ECBUS_RX_DPHY_ECBUS_DPHY_DEBUG                                          0x18062F94
#define  ECBUS_RX_DPHY_ECBUS_DPHY_DEBUG_reg_addr                                 "0xB8062F94"
#define  ECBUS_RX_DPHY_ECBUS_DPHY_DEBUG_reg                                      0xB8062F94
#define  ECBUS_RX_DPHY_ECBUS_DPHY_DEBUG_inst_addr                                "0x0025"
#define  set_ECBUS_RX_DPHY_ECBUS_DPHY_DEBUG_reg(data)                            (*((volatile unsigned int*)ECBUS_RX_DPHY_ECBUS_DPHY_DEBUG_reg)=data)
#define  get_ECBUS_RX_DPHY_ECBUS_DPHY_DEBUG_reg                                  (*((volatile unsigned int*)ECBUS_RX_DPHY_ECBUS_DPHY_DEBUG_reg))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_DEBUG_dphy_debug_sel_7_0_shift                 (0)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_DEBUG_dphy_debug_sel_7_0_mask                  (0x000000FF)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_DEBUG_dphy_debug_sel_7_0(data)                 (0x000000FF&(data))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_DEBUG_get_dphy_debug_sel_7_0(data)             (0x000000FF&(data))

#define  ECBUS_RX_DPHY_ECBUS_DPHY_RESERVE                                        0x18062F98
#define  ECBUS_RX_DPHY_ECBUS_DPHY_RESERVE_reg_addr                               "0xB8062F98"
#define  ECBUS_RX_DPHY_ECBUS_DPHY_RESERVE_reg                                    0xB8062F98
#define  ECBUS_RX_DPHY_ECBUS_DPHY_RESERVE_inst_addr                              "0x0026"
#define  set_ECBUS_RX_DPHY_ECBUS_DPHY_RESERVE_reg(data)                          (*((volatile unsigned int*)ECBUS_RX_DPHY_ECBUS_DPHY_RESERVE_reg)=data)
#define  get_ECBUS_RX_DPHY_ECBUS_DPHY_RESERVE_reg                                (*((volatile unsigned int*)ECBUS_RX_DPHY_ECBUS_DPHY_RESERVE_reg))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_RESERVE_tx_data_duty_inv_shift                 (0)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_RESERVE_tx_data_duty_inv_mask                  (0x00000001)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_RESERVE_tx_data_duty_inv(data)                 (0x00000001&(data))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_RESERVE_get_tx_data_duty_inv(data)             (0x00000001&(data))

#define  ECBUS_RX_DPHY_ECBUS_DPHY_DEBUG_EN                                       0x18062F9C
#define  ECBUS_RX_DPHY_ECBUS_DPHY_DEBUG_EN_reg_addr                              "0xB8062F9C"
#define  ECBUS_RX_DPHY_ECBUS_DPHY_DEBUG_EN_reg                                   0xB8062F9C
#define  ECBUS_RX_DPHY_ECBUS_DPHY_DEBUG_EN_inst_addr                             "0x0027"
#define  set_ECBUS_RX_DPHY_ECBUS_DPHY_DEBUG_EN_reg(data)                         (*((volatile unsigned int*)ECBUS_RX_DPHY_ECBUS_DPHY_DEBUG_EN_reg)=data)
#define  get_ECBUS_RX_DPHY_ECBUS_DPHY_DEBUG_EN_reg                               (*((volatile unsigned int*)ECBUS_RX_DPHY_ECBUS_DPHY_DEBUG_EN_reg))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_DEBUG_EN_dummy_7_1_shift                       (1)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_DEBUG_EN_ecbus_dbg_en_shift                    (0)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_DEBUG_EN_dummy_7_1_mask                        (0x000000FE)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_DEBUG_EN_ecbus_dbg_en_mask                     (0x00000001)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_DEBUG_EN_dummy_7_1(data)                       (0x000000FE&((data)<<1))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_DEBUG_EN_ecbus_dbg_en(data)                    (0x00000001&(data))
#define  ECBUS_RX_DPHY_ECBUS_DPHY_DEBUG_EN_get_dummy_7_1(data)                   ((0x000000FE&(data))>>1)
#define  ECBUS_RX_DPHY_ECBUS_DPHY_DEBUG_EN_get_ecbus_dbg_en(data)                (0x00000001&(data))

#define  ECBUS_RX_DPHY_ECBUS_CAP_LEN                                             0x18062FA0
#define  ECBUS_RX_DPHY_ECBUS_CAP_LEN_reg_addr                                    "0xB8062FA0"
#define  ECBUS_RX_DPHY_ECBUS_CAP_LEN_reg                                         0xB8062FA0
#define  ECBUS_RX_DPHY_ECBUS_CAP_LEN_inst_addr                                   "0x0028"
#define  set_ECBUS_RX_DPHY_ECBUS_CAP_LEN_reg(data)                               (*((volatile unsigned int*)ECBUS_RX_DPHY_ECBUS_CAP_LEN_reg)=data)
#define  get_ECBUS_RX_DPHY_ECBUS_CAP_LEN_reg                                     (*((volatile unsigned int*)ECBUS_RX_DPHY_ECBUS_CAP_LEN_reg))
#define  ECBUS_RX_DPHY_ECBUS_CAP_LEN_cap_len_shift                               (0)
#define  ECBUS_RX_DPHY_ECBUS_CAP_LEN_cap_len_mask                                (0x000000FF)
#define  ECBUS_RX_DPHY_ECBUS_CAP_LEN_cap_len(data)                               (0x000000FF&(data))
#define  ECBUS_RX_DPHY_ECBUS_CAP_LEN_get_cap_len(data)                           (0x000000FF&(data))

#define  ECBUS_RX_DPHY_ECBUS_TX_DATA_MASK_0                                      0x18062FA4
#define  ECBUS_RX_DPHY_ECBUS_TX_DATA_MASK_0_reg_addr                             "0xB8062FA4"
#define  ECBUS_RX_DPHY_ECBUS_TX_DATA_MASK_0_reg                                  0xB8062FA4
#define  ECBUS_RX_DPHY_ECBUS_TX_DATA_MASK_0_inst_addr                            "0x0029"
#define  set_ECBUS_RX_DPHY_ECBUS_TX_DATA_MASK_0_reg(data)                        (*((volatile unsigned int*)ECBUS_RX_DPHY_ECBUS_TX_DATA_MASK_0_reg)=data)
#define  get_ECBUS_RX_DPHY_ECBUS_TX_DATA_MASK_0_reg                              (*((volatile unsigned int*)ECBUS_RX_DPHY_ECBUS_TX_DATA_MASK_0_reg))
#define  ECBUS_RX_DPHY_ECBUS_TX_DATA_MASK_0_tx_data_mask_39_32_shift             (0)
#define  ECBUS_RX_DPHY_ECBUS_TX_DATA_MASK_0_tx_data_mask_39_32_mask              (0x000000FF)
#define  ECBUS_RX_DPHY_ECBUS_TX_DATA_MASK_0_tx_data_mask_39_32(data)             (0x000000FF&(data))
#define  ECBUS_RX_DPHY_ECBUS_TX_DATA_MASK_0_get_tx_data_mask_39_32(data)         (0x000000FF&(data))

#define  ECBUS_RX_DPHY_ECBUS_TX_DATA_MASK_1                                      0x18062FA8
#define  ECBUS_RX_DPHY_ECBUS_TX_DATA_MASK_1_reg_addr                             "0xB8062FA8"
#define  ECBUS_RX_DPHY_ECBUS_TX_DATA_MASK_1_reg                                  0xB8062FA8
#define  ECBUS_RX_DPHY_ECBUS_TX_DATA_MASK_1_inst_addr                            "0x002A"
#define  set_ECBUS_RX_DPHY_ECBUS_TX_DATA_MASK_1_reg(data)                        (*((volatile unsigned int*)ECBUS_RX_DPHY_ECBUS_TX_DATA_MASK_1_reg)=data)
#define  get_ECBUS_RX_DPHY_ECBUS_TX_DATA_MASK_1_reg                              (*((volatile unsigned int*)ECBUS_RX_DPHY_ECBUS_TX_DATA_MASK_1_reg))
#define  ECBUS_RX_DPHY_ECBUS_TX_DATA_MASK_1_tx_data_mask_31_0_shift              (0)
#define  ECBUS_RX_DPHY_ECBUS_TX_DATA_MASK_1_tx_data_mask_31_0_mask               (0xFFFFFFFF)
#define  ECBUS_RX_DPHY_ECBUS_TX_DATA_MASK_1_tx_data_mask_31_0(data)              (0xFFFFFFFF&(data))
#define  ECBUS_RX_DPHY_ECBUS_TX_DATA_MASK_1_get_tx_data_mask_31_0(data)          (0xFFFFFFFF&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======ECBUS_RX_DPHY register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  ecbus_dphy_rstn:1;
        RBus_UInt32  ecbus_dphy_en:1;
        RBus_UInt32  ecbus_clk_rx_inv:1;
        RBus_UInt32  bub_remove:1;
        RBus_UInt32  bub_2stage:1;
        RBus_UInt32  ecbus_clk_tx_inv:1;
        RBus_UInt32  ecbus_rx_tail_mask:2;
    };
}ecbus_rx_dphy_ecbus_dphy_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  edge_pos_manual:1;
        RBus_UInt32  edge_position_m_5_0:6;
        RBus_UInt32  edge_calib_en:1;
    };
}ecbus_rx_dphy_ecbus_dphy_edge_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dummy18062f08_7_6:2;
        RBus_UInt32  edge_calib_position_5_0:6;
    };
}ecbus_rx_dphy_ecbus_dphy_edge_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  stat_en:1;
        RBus_UInt32  stat_manual:1;
        RBus_UInt32  stat_ok:1;
        RBus_UInt32  stat_safe:1;
        RBus_UInt32  comma2_detect:1;
        RBus_UInt32  no_disparity:1;
        RBus_UInt32  dummy18062f0c_1_0:2;
    };
}ecbus_rx_dphy_ecbus_dphy_stat_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  stat_timeout_7_0:8;
    };
}ecbus_rx_dphy_ecbus_dphy_stat_config_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dummy18062f14_7_6:2;
        RBus_UInt32  stat_diff_th_5_0:6;
    };
}ecbus_rx_dphy_ecbus_dphy_stat_config_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dummy18062f18_7_6:2;
        RBus_UInt32  stat_max_5_0:6;
    };
}ecbus_rx_dphy_ecbus_dphy_stat_result_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dummy18062f1c_7_6:2;
        RBus_UInt32  stat_min_5_0:6;
    };
}ecbus_rx_dphy_ecbus_dphy_stat_result_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dummy18062f20_7_4:4;
        RBus_UInt32  stat_timeout_flag:1;
        RBus_UInt32  stat_st_2_0:3;
    };
}ecbus_rx_dphy_ecbus_dphy_stat_result_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  ini_bound_en:1;
        RBus_UInt32  tx_calib_en:1;
        RBus_UInt32  adapt_nth_en:1;
        RBus_UInt32  nth_manual:1;
        RBus_UInt32  adapt_nth_end:1;
        RBus_UInt32  rxvalid_reload:1;
        RBus_UInt32  raw_data_en:1;
        RBus_UInt32  dummy18062f24_0:1;
    };
}ecbus_rx_dphy_ecbus_dphy_calib_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  ini_timeout_7_0:8;
    };
}ecbus_rx_dphy_ecbus_dphy_ini_config_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  ini_wait_cnt_7_0:8;
    };
}ecbus_rx_dphy_ecbus_dphy_ini_config_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dummy18062f30_7_6:2;
        RBus_UInt32  nth_ini_5_0:6;
    };
}ecbus_rx_dphy_ecbus_dphy_ini_config_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dummy18062f34_7_4:4;
        RBus_UInt32  ini_cnt_2_0:3;
        RBus_UInt32  ini_eq_th_8:1;
    };
}ecbus_rx_dphy_ecbus_dphy_ini_config_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  ini_eq_th_7_0:8;
    };
}ecbus_rx_dphy_ecbus_dphy_ini_config_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dummy18062f3c_7_6:2;
        RBus_UInt32  calib_nth_5_0:6;
    };
}ecbus_rx_dphy_ecbus_dphy_ini_result_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dummy18062f40_7_6:2;
        RBus_UInt32  calib_nth_max_5_0:6;
    };
}ecbus_rx_dphy_ecbus_dphy_ini_result_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dummy18062f44_7_6:2;
        RBus_UInt32  calib_nth_min_5_0:6;
    };
}ecbus_rx_dphy_ecbus_dphy_ini_result_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dummy18062f48_7_4:4;
        RBus_UInt32  ini_st_3_0:4;
    };
}ecbus_rx_dphy_ecbus_dphy_ini_result_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  txdata_high_wid_1_0:2;
        RBus_UInt32  txdata_mode_1_0:2;
        RBus_UInt32  txdata_delay_3_0:4;
    };
}ecbus_rx_dphy_ecbus_dphy_tx_phase_config_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dummy18062f50_7_6:2;
        RBus_UInt32  tx_phase_ini_5_0:6;
    };
}ecbus_rx_dphy_ecbus_dphy_tx_phase_config_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dummy18062f54_7_6:2;
        RBus_UInt32  tx_phase_max:6;
    };
}ecbus_rx_dphy_ecbus_dphy_tx_phase_config_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dummy18062f58_7_6:2;
        RBus_UInt32  tx_phase_min:6;
    };
}ecbus_rx_dphy_ecbus_dphy_tx_phase_config_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dummy18062f5c_7_6:2;
        RBus_UInt32  calib_tx_phase_5_0:6;
    };
}ecbus_rx_dphy_ecbus_dphy_tx_phase_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dummy18062f60_7_2:6;
        RBus_UInt32  adapt_mode_1_0:2;
    };
}ecbus_rx_dphy_ecbus_dphy_adapt_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  adapt_timer_7_0:8;
    };
}ecbus_rx_dphy_ecbus_dphy_adapt_config_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dummy18062f68_7_6:2;
        RBus_UInt32  nth_one_m_5_0:6;
    };
}ecbus_rx_dphy_ecbus_dphy_adapt_config_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dummy18062f6c_7_6:2;
        RBus_UInt32  nth_zero_m_5_0:6;
    };
}ecbus_rx_dphy_ecbus_dphy_adapt_config_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dummy18062f70_7_6:2;
        RBus_UInt32  adapt_nth_one_5_0:6;
    };
}ecbus_rx_dphy_ecbus_dphy_adapt_result_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dummy18062f74_7_6:2;
        RBus_UInt32  adapt_nth_zero_5_0:6;
    };
}ecbus_rx_dphy_ecbus_dphy_adapt_result_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dummy18062f78_7_4:4;
        RBus_UInt32  adapt_0_st_1_0:2;
        RBus_UInt32  adapt_1_st_1_0:2;
    };
}ecbus_rx_dphy_ecbus_dphy_adapt_result_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dummy18062f7c_7_3:5;
        RBus_UInt32  calib_st_2_0:3;
    };
}ecbus_rx_dphy_ecbus_dphy_calib_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  rx_timeout_7_0:8;
    };
}ecbus_rx_dphy_ecbus_dphy_config_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dummy18062f84_7_2:6;
        RBus_UInt32  comma2_pattern_9_8:2;
    };
}ecbus_rx_dphy_ecbus_dphy_pattern_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  comma2_pattern_7_0:8;
    };
}ecbus_rx_dphy_ecbus_dphy_pattern_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  calib_nth_timeout:1;
        RBus_UInt32  calib_nth_error:1;
        RBus_UInt32  edge_error:1;
        RBus_UInt32  rx_valid:1;
        RBus_UInt32  rx_data_all_1:1;
        RBus_UInt32  rx_data_all_0:1;
        RBus_UInt32  dummy18062f8c_1_0:2;
    };
}ecbus_rx_dphy_ecbus_dphy_flag_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dummy18062f90_7_6:2;
        RBus_UInt32  rx_timeout_irq_en:1;
        RBus_UInt32  rx_timeout_irq:1;
        RBus_UInt32  dummy18062f90_3_2:2;
        RBus_UInt32  stat_ok_irq_en:1;
        RBus_UInt32  stat_ok_irq:1;
    };
}ecbus_rx_dphy_ecbus_dphy_irq_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dphy_debug_sel_7_0:8;
    };
}ecbus_rx_dphy_ecbus_dphy_debug_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  tx_data_duty_inv:1;
    };
}ecbus_rx_dphy_ecbus_dphy_reserve_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dummy18062f9c_7_1:7;
        RBus_UInt32  ecbus_dbg_en:1;
    };
}ecbus_rx_dphy_ecbus_dphy_debug_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  cap_len:8;
    };
}ecbus_rx_dphy_ecbus_cap_len_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  tx_data_mask_39_32:8;
    };
}ecbus_rx_dphy_ecbus_tx_data_mask_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tx_data_mask_31_0:32;
    };
}ecbus_rx_dphy_ecbus_tx_data_mask_1_RBUS;

#else //apply LITTLE_ENDIAN

//======ECBUS_RX_DPHY register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ecbus_rx_tail_mask:2;
        RBus_UInt32  ecbus_clk_tx_inv:1;
        RBus_UInt32  bub_2stage:1;
        RBus_UInt32  bub_remove:1;
        RBus_UInt32  ecbus_clk_rx_inv:1;
        RBus_UInt32  ecbus_dphy_en:1;
        RBus_UInt32  ecbus_dphy_rstn:1;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_dphy_ecbus_dphy_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  edge_calib_en:1;
        RBus_UInt32  edge_position_m_5_0:6;
        RBus_UInt32  edge_pos_manual:1;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_dphy_ecbus_dphy_edge_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  edge_calib_position_5_0:6;
        RBus_UInt32  dummy18062f08_7_6:2;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_dphy_ecbus_dphy_edge_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18062f0c_1_0:2;
        RBus_UInt32  no_disparity:1;
        RBus_UInt32  comma2_detect:1;
        RBus_UInt32  stat_safe:1;
        RBus_UInt32  stat_ok:1;
        RBus_UInt32  stat_manual:1;
        RBus_UInt32  stat_en:1;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_dphy_ecbus_dphy_stat_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  stat_timeout_7_0:8;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_dphy_ecbus_dphy_stat_config_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  stat_diff_th_5_0:6;
        RBus_UInt32  dummy18062f14_7_6:2;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_dphy_ecbus_dphy_stat_config_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  stat_max_5_0:6;
        RBus_UInt32  dummy18062f18_7_6:2;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_dphy_ecbus_dphy_stat_result_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  stat_min_5_0:6;
        RBus_UInt32  dummy18062f1c_7_6:2;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_dphy_ecbus_dphy_stat_result_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  stat_st_2_0:3;
        RBus_UInt32  stat_timeout_flag:1;
        RBus_UInt32  dummy18062f20_7_4:4;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_dphy_ecbus_dphy_stat_result_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18062f24_0:1;
        RBus_UInt32  raw_data_en:1;
        RBus_UInt32  rxvalid_reload:1;
        RBus_UInt32  adapt_nth_end:1;
        RBus_UInt32  nth_manual:1;
        RBus_UInt32  adapt_nth_en:1;
        RBus_UInt32  tx_calib_en:1;
        RBus_UInt32  ini_bound_en:1;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_dphy_ecbus_dphy_calib_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ini_timeout_7_0:8;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_dphy_ecbus_dphy_ini_config_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ini_wait_cnt_7_0:8;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_dphy_ecbus_dphy_ini_config_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  nth_ini_5_0:6;
        RBus_UInt32  dummy18062f30_7_6:2;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_dphy_ecbus_dphy_ini_config_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ini_eq_th_8:1;
        RBus_UInt32  ini_cnt_2_0:3;
        RBus_UInt32  dummy18062f34_7:4;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_dphy_ecbus_dphy_ini_config_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ini_eq_th_7_0:8;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_dphy_ecbus_dphy_ini_config_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  calib_nth_5_0:6;
        RBus_UInt32  dummy18062f3c_7_6:2;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_dphy_ecbus_dphy_ini_result_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  calib_nth_max_5_0:6;
        RBus_UInt32  dummy18062f40_7_6:2;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_dphy_ecbus_dphy_ini_result_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  calib_nth_min_5_0:6;
        RBus_UInt32  dummy18062f44_7_6:2;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_dphy_ecbus_dphy_ini_result_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ini_st_3_0:4;
        RBus_UInt32  dummy18062f48_7_4:4;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_dphy_ecbus_dphy_ini_result_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  txdata_delay_3_0:4;
        RBus_UInt32  txdata_mode_1_0:2;
        RBus_UInt32  txdata_high_wid_1_0:2;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_dphy_ecbus_dphy_tx_phase_config_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tx_phase_ini_5_0:6;
        RBus_UInt32  dummy18062f50_7_6:2;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_dphy_ecbus_dphy_tx_phase_config_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tx_phase_max:6;
        RBus_UInt32  dummy18062f54_7_6:2;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_dphy_ecbus_dphy_tx_phase_config_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tx_phase_min:6;
        RBus_UInt32  dummy18062f58_7_6:2;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_dphy_ecbus_dphy_tx_phase_config_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  calib_tx_phase_5_0:6;
        RBus_UInt32  dummy18062f5c_7_6:2;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_dphy_ecbus_dphy_tx_phase_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  adapt_mode_1_0:2;
        RBus_UInt32  dummy18062f60_7_2:6;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_dphy_ecbus_dphy_adapt_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  adapt_timer_7_0:8;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_dphy_ecbus_dphy_adapt_config_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  nth_one_m_5_0:6;
        RBus_UInt32  dummy18062f68_7_6:2;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_dphy_ecbus_dphy_adapt_config_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  nth_zero_m_5_0:6;
        RBus_UInt32  dummy18062f6c_7_6:2;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_dphy_ecbus_dphy_adapt_config_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  adapt_nth_one_5_0:6;
        RBus_UInt32  dummy18062f70_7_6:2;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_dphy_ecbus_dphy_adapt_result_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  adapt_nth_zero_5_0:6;
        RBus_UInt32  dummy18062f74_7_6:2;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_dphy_ecbus_dphy_adapt_result_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  adapt_1_st_1_0:2;
        RBus_UInt32  adapt_0_st_1_0:2;
        RBus_UInt32  dummy18062f78_7_4:4;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_dphy_ecbus_dphy_adapt_result_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  calib_st_2_0:3;
        RBus_UInt32  dummy18062f7c_7_3:5;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_dphy_ecbus_dphy_calib_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rx_timeout_7_0:8;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_dphy_ecbus_dphy_config_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  comma2_pattern_9_8:2;
        RBus_UInt32  dummy18062f84_7_2:6;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_dphy_ecbus_dphy_pattern_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  comma2_pattern_7_0:8;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_dphy_ecbus_dphy_pattern_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18062f8c_1_0:2;
        RBus_UInt32  rx_data_all_0:1;
        RBus_UInt32  rx_data_all_1:1;
        RBus_UInt32  rx_valid:1;
        RBus_UInt32  edge_error:1;
        RBus_UInt32  calib_nth_error:1;
        RBus_UInt32  calib_nth_timeout:1;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_dphy_ecbus_dphy_flag_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  stat_ok_irq:1;
        RBus_UInt32  stat_ok_irq_en:1;
        RBus_UInt32  dummy18062f90_3:2;
        RBus_UInt32  rx_timeout_irq:1;
        RBus_UInt32  rx_timeout_irq_en:1;
        RBus_UInt32  dummy18062f90_7:2;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_dphy_ecbus_dphy_irq_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dphy_debug_sel_7_0:8;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_dphy_ecbus_dphy_debug_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tx_data_duty_inv:1;
        RBus_UInt32  res1:31;
    };
}ecbus_rx_dphy_ecbus_dphy_reserve_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ecbus_dbg_en:1;
        RBus_UInt32  dummy18062f9c_7:7;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_dphy_ecbus_dphy_debug_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_len:8;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_dphy_ecbus_cap_len_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tx_data_mask_39_32:8;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_dphy_ecbus_tx_data_mask_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tx_data_mask_31_0:32;
    };
}ecbus_rx_dphy_ecbus_tx_data_mask_1_RBUS;




#endif 


#endif 
