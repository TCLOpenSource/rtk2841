/**
* @file Mac5-DesignSpec-D-Domain_Panel_Compensation
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_GAMMA_REG_H_
#define _RBUS_GAMMA_REG_H_

#include "rbus_types.h"



//  GAMMA Register Address
#define  GAMMA_GAMMA_PORT                                                        0x1802C100
#define  GAMMA_GAMMA_PORT_reg_addr                                               "0xB802C100"
#define  GAMMA_GAMMA_PORT_reg                                                    0xB802C100
#define  GAMMA_GAMMA_PORT_inst_addr                                              "0x0000"
#define  set_GAMMA_GAMMA_PORT_reg(data)                                          (*((volatile unsigned int*)GAMMA_GAMMA_PORT_reg)=data)
#define  get_GAMMA_GAMMA_PORT_reg                                                (*((volatile unsigned int*)GAMMA_GAMMA_PORT_reg))
#define  GAMMA_GAMMA_PORT_gamma_tab_index_shift                                  (16)
#define  GAMMA_GAMMA_PORT_gamma_tab_d0_shift                                     (8)
#define  GAMMA_GAMMA_PORT_gamma_tab_d1_shift                                     (0)
#define  GAMMA_GAMMA_PORT_gamma_tab_index_mask                                   (0x0FFF0000)
#define  GAMMA_GAMMA_PORT_gamma_tab_d0_mask                                      (0x0000FF00)
#define  GAMMA_GAMMA_PORT_gamma_tab_d1_mask                                      (0x000000FF)
#define  GAMMA_GAMMA_PORT_gamma_tab_index(data)                                  (0x0FFF0000&((data)<<16))
#define  GAMMA_GAMMA_PORT_gamma_tab_d0(data)                                     (0x0000FF00&((data)<<8))
#define  GAMMA_GAMMA_PORT_gamma_tab_d1(data)                                     (0x000000FF&(data))
#define  GAMMA_GAMMA_PORT_get_gamma_tab_index(data)                              ((0x0FFF0000&(data))>>16)
#define  GAMMA_GAMMA_PORT_get_gamma_tab_d0(data)                                 ((0x0000FF00&(data))>>8)
#define  GAMMA_GAMMA_PORT_get_gamma_tab_d1(data)                                 (0x000000FF&(data))

#define  GAMMA_GAMMA_CTRL_1                                                      0x1802C104
#define  GAMMA_GAMMA_CTRL_1_reg_addr                                             "0xB802C104"
#define  GAMMA_GAMMA_CTRL_1_reg                                                  0xB802C104
#define  GAMMA_GAMMA_CTRL_1_inst_addr                                            "0x0001"
#define  set_GAMMA_GAMMA_CTRL_1_reg(data)                                        (*((volatile unsigned int*)GAMMA_GAMMA_CTRL_1_reg)=data)
#define  get_GAMMA_GAMMA_CTRL_1_reg                                              (*((volatile unsigned int*)GAMMA_GAMMA_CTRL_1_reg))
#define  GAMMA_GAMMA_CTRL_1_gamma_tab_addr_shift                                 (16)
#define  GAMMA_GAMMA_CTRL_1_gamma_ax_rw_sel_shift                                (7)
#define  GAMMA_GAMMA_CTRL_1_gamma_ax_ch_sel_shift                                (4)
#define  GAMMA_GAMMA_CTRL_1_gamma_fifo_empty_shift                               (3)
#define  GAMMA_GAMMA_CTRL_1_gamma_fifo_full_shift                                (2)
#define  GAMMA_GAMMA_CTRL_1_gamma_wr_error_shift                                 (1)
#define  GAMMA_GAMMA_CTRL_1_dummy_0_shift                                        (0)
#define  GAMMA_GAMMA_CTRL_1_gamma_tab_addr_mask                                  (0x01FF0000)
#define  GAMMA_GAMMA_CTRL_1_gamma_ax_rw_sel_mask                                 (0x00000180)
#define  GAMMA_GAMMA_CTRL_1_gamma_ax_ch_sel_mask                                 (0x00000030)
#define  GAMMA_GAMMA_CTRL_1_gamma_fifo_empty_mask                                (0x00000008)
#define  GAMMA_GAMMA_CTRL_1_gamma_fifo_full_mask                                 (0x00000004)
#define  GAMMA_GAMMA_CTRL_1_gamma_wr_error_mask                                  (0x00000002)
#define  GAMMA_GAMMA_CTRL_1_dummy_0_mask                                         (0x00000001)
#define  GAMMA_GAMMA_CTRL_1_gamma_tab_addr(data)                                 (0x01FF0000&((data)<<16))
#define  GAMMA_GAMMA_CTRL_1_gamma_ax_rw_sel(data)                                (0x00000180&((data)<<7))
#define  GAMMA_GAMMA_CTRL_1_gamma_ax_ch_sel(data)                                (0x00000030&((data)<<4))
#define  GAMMA_GAMMA_CTRL_1_gamma_fifo_empty(data)                               (0x00000008&((data)<<3))
#define  GAMMA_GAMMA_CTRL_1_gamma_fifo_full(data)                                (0x00000004&((data)<<2))
#define  GAMMA_GAMMA_CTRL_1_gamma_wr_error(data)                                 (0x00000002&((data)<<1))
#define  GAMMA_GAMMA_CTRL_1_dummy_0(data)                                        (0x00000001&(data))
#define  GAMMA_GAMMA_CTRL_1_get_gamma_tab_addr(data)                             ((0x01FF0000&(data))>>16)
#define  GAMMA_GAMMA_CTRL_1_get_gamma_ax_rw_sel(data)                            ((0x00000180&(data))>>7)
#define  GAMMA_GAMMA_CTRL_1_get_gamma_ax_ch_sel(data)                            ((0x00000030&(data))>>4)
#define  GAMMA_GAMMA_CTRL_1_get_gamma_fifo_empty(data)                           ((0x00000008&(data))>>3)
#define  GAMMA_GAMMA_CTRL_1_get_gamma_fifo_full(data)                            ((0x00000004&(data))>>2)
#define  GAMMA_GAMMA_CTRL_1_get_gamma_wr_error(data)                             ((0x00000002&(data))>>1)
#define  GAMMA_GAMMA_CTRL_1_get_dummy_0(data)                                    (0x00000001&(data))

#define  GAMMA_GAMMA_CTRL_2                                                      0x1802C108
#define  GAMMA_GAMMA_CTRL_2_reg_addr                                             "0xB802C108"
#define  GAMMA_GAMMA_CTRL_2_reg                                                  0xB802C108
#define  GAMMA_GAMMA_CTRL_2_inst_addr                                            "0x0002"
#define  set_GAMMA_GAMMA_CTRL_2_reg(data)                                        (*((volatile unsigned int*)GAMMA_GAMMA_CTRL_2_reg)=data)
#define  get_GAMMA_GAMMA_CTRL_2_reg                                              (*((volatile unsigned int*)GAMMA_GAMMA_CTRL_2_reg))
#define  GAMMA_GAMMA_CTRL_2_gamma_m_tab_sel_shift                                (6)
#define  GAMMA_GAMMA_CTRL_2_dummy_5_0_shift                                      (0)
#define  GAMMA_GAMMA_CTRL_2_gamma_m_tab_sel_mask                                 (0x000000C0)
#define  GAMMA_GAMMA_CTRL_2_dummy_5_0_mask                                       (0x0000003F)
#define  GAMMA_GAMMA_CTRL_2_gamma_m_tab_sel(data)                                (0x000000C0&((data)<<6))
#define  GAMMA_GAMMA_CTRL_2_dummy_5_0(data)                                      (0x0000003F&(data))
#define  GAMMA_GAMMA_CTRL_2_get_gamma_m_tab_sel(data)                            ((0x000000C0&(data))>>6)
#define  GAMMA_GAMMA_CTRL_2_get_dummy_5_0(data)                                  (0x0000003F&(data))

#define  GAMMA_GAMMA_CTRL_3                                                      0x1802C10C
#define  GAMMA_GAMMA_CTRL_3_reg_addr                                             "0xB802C10C"
#define  GAMMA_GAMMA_CTRL_3_reg                                                  0xB802C10C
#define  GAMMA_GAMMA_CTRL_3_inst_addr                                            "0x0003"
#define  set_GAMMA_GAMMA_CTRL_3_reg(data)                                        (*((volatile unsigned int*)GAMMA_GAMMA_CTRL_3_reg)=data)
#define  get_GAMMA_GAMMA_CTRL_3_reg                                              (*((volatile unsigned int*)GAMMA_GAMMA_CTRL_3_reg))
#define  GAMMA_GAMMA_CTRL_3_gamma_msb_d0_r_shift                                 (16)
#define  GAMMA_GAMMA_CTRL_3_gamma_msb_d0_g_shift                                 (8)
#define  GAMMA_GAMMA_CTRL_3_gamma_msb_d0_b_shift                                 (0)
#define  GAMMA_GAMMA_CTRL_3_gamma_msb_d0_r_mask                                  (0x00070000)
#define  GAMMA_GAMMA_CTRL_3_gamma_msb_d0_g_mask                                  (0x00000700)
#define  GAMMA_GAMMA_CTRL_3_gamma_msb_d0_b_mask                                  (0x00000007)
#define  GAMMA_GAMMA_CTRL_3_gamma_msb_d0_r(data)                                 (0x00070000&((data)<<16))
#define  GAMMA_GAMMA_CTRL_3_gamma_msb_d0_g(data)                                 (0x00000700&((data)<<8))
#define  GAMMA_GAMMA_CTRL_3_gamma_msb_d0_b(data)                                 (0x00000007&(data))
#define  GAMMA_GAMMA_CTRL_3_get_gamma_msb_d0_r(data)                             ((0x00070000&(data))>>16)
#define  GAMMA_GAMMA_CTRL_3_get_gamma_msb_d0_g(data)                             ((0x00000700&(data))>>8)
#define  GAMMA_GAMMA_CTRL_3_get_gamma_msb_d0_b(data)                             (0x00000007&(data))

#define  GAMMA_GAMMA_SRGB_BIST_CTRL_1                                            0x1802C110
#define  GAMMA_GAMMA_SRGB_BIST_CTRL_1_reg_addr                                   "0xB802C110"
#define  GAMMA_GAMMA_SRGB_BIST_CTRL_1_reg                                        0xB802C110
#define  GAMMA_GAMMA_SRGB_BIST_CTRL_1_inst_addr                                  "0x0004"
#define  set_GAMMA_GAMMA_SRGB_BIST_CTRL_1_reg(data)                              (*((volatile unsigned int*)GAMMA_GAMMA_SRGB_BIST_CTRL_1_reg)=data)
#define  get_GAMMA_GAMMA_SRGB_BIST_CTRL_1_reg                                    (*((volatile unsigned int*)GAMMA_GAMMA_SRGB_BIST_CTRL_1_reg))
#define  GAMMA_GAMMA_SRGB_BIST_CTRL_1_ls_shift                                   (5)
#define  GAMMA_GAMMA_SRGB_BIST_CTRL_1_rme_shift                                  (4)
#define  GAMMA_GAMMA_SRGB_BIST_CTRL_1_rm_shift                                   (0)
#define  GAMMA_GAMMA_SRGB_BIST_CTRL_1_ls_mask                                    (0x00000020)
#define  GAMMA_GAMMA_SRGB_BIST_CTRL_1_rme_mask                                   (0x00000010)
#define  GAMMA_GAMMA_SRGB_BIST_CTRL_1_rm_mask                                    (0x0000000F)
#define  GAMMA_GAMMA_SRGB_BIST_CTRL_1_ls(data)                                   (0x00000020&((data)<<5))
#define  GAMMA_GAMMA_SRGB_BIST_CTRL_1_rme(data)                                  (0x00000010&((data)<<4))
#define  GAMMA_GAMMA_SRGB_BIST_CTRL_1_rm(data)                                   (0x0000000F&(data))
#define  GAMMA_GAMMA_SRGB_BIST_CTRL_1_get_ls(data)                               ((0x00000020&(data))>>5)
#define  GAMMA_GAMMA_SRGB_BIST_CTRL_1_get_rme(data)                              ((0x00000010&(data))>>4)
#define  GAMMA_GAMMA_SRGB_BIST_CTRL_1_get_rm(data)                               (0x0000000F&(data))

#define  GAMMA_GAMMA_SRGB_BIST_CTRL_3                                            0x1802C114
#define  GAMMA_GAMMA_SRGB_BIST_CTRL_3_reg_addr                                   "0xB802C114"
#define  GAMMA_GAMMA_SRGB_BIST_CTRL_3_reg                                        0xB802C114
#define  GAMMA_GAMMA_SRGB_BIST_CTRL_3_inst_addr                                  "0x0005"
#define  set_GAMMA_GAMMA_SRGB_BIST_CTRL_3_reg(data)                              (*((volatile unsigned int*)GAMMA_GAMMA_SRGB_BIST_CTRL_3_reg)=data)
#define  get_GAMMA_GAMMA_SRGB_BIST_CTRL_3_reg                                    (*((volatile unsigned int*)GAMMA_GAMMA_SRGB_BIST_CTRL_3_reg))
#define  GAMMA_GAMMA_SRGB_BIST_CTRL_3_inv_gamma_r_drf_bist_fail_shift            (17)
#define  GAMMA_GAMMA_SRGB_BIST_CTRL_3_inv_gamma_g_drf_bist_fail_shift            (16)
#define  GAMMA_GAMMA_SRGB_BIST_CTRL_3_inv_gamma_b_drf_bist_fail_shift            (15)
#define  GAMMA_GAMMA_SRGB_BIST_CTRL_3_srgb_r_drf_bist_fail_shift                 (14)
#define  GAMMA_GAMMA_SRGB_BIST_CTRL_3_srgb_g_drf_bist_fail_shift                 (13)
#define  GAMMA_GAMMA_SRGB_BIST_CTRL_3_srgb_b_drf_bist_fail_shift                 (12)
#define  GAMMA_GAMMA_SRGB_BIST_CTRL_3_gamma_r_drf_bist_fail_shift                (11)
#define  GAMMA_GAMMA_SRGB_BIST_CTRL_3_gamma_g_drf_bist_fail_shift                (10)
#define  GAMMA_GAMMA_SRGB_BIST_CTRL_3_gamma_b_drf_bist_fail_shift                (9)
#define  GAMMA_GAMMA_SRGB_BIST_CTRL_3_inv_gamma_r_bist_fail_shift                (8)
#define  GAMMA_GAMMA_SRGB_BIST_CTRL_3_inv_gamma_g_bist_fail_shift                (7)
#define  GAMMA_GAMMA_SRGB_BIST_CTRL_3_inv_gamma_b_bist_fail_shift                (6)
#define  GAMMA_GAMMA_SRGB_BIST_CTRL_3_srgb_r_bist_fail_shift                     (5)
#define  GAMMA_GAMMA_SRGB_BIST_CTRL_3_srgb_g_bist_fail_shift                     (4)
#define  GAMMA_GAMMA_SRGB_BIST_CTRL_3_srgb_b_bist_fail_shift                     (3)
#define  GAMMA_GAMMA_SRGB_BIST_CTRL_3_gamma_r_bist_fail_shift                    (2)
#define  GAMMA_GAMMA_SRGB_BIST_CTRL_3_gamma_g_bist_fail_shift                    (1)
#define  GAMMA_GAMMA_SRGB_BIST_CTRL_3_gamma_b_bist_fail_shift                    (0)
#define  GAMMA_GAMMA_SRGB_BIST_CTRL_3_inv_gamma_r_drf_bist_fail_mask             (0x00020000)
#define  GAMMA_GAMMA_SRGB_BIST_CTRL_3_inv_gamma_g_drf_bist_fail_mask             (0x00010000)
#define  GAMMA_GAMMA_SRGB_BIST_CTRL_3_inv_gamma_b_drf_bist_fail_mask             (0x00008000)
#define  GAMMA_GAMMA_SRGB_BIST_CTRL_3_srgb_r_drf_bist_fail_mask                  (0x00004000)
#define  GAMMA_GAMMA_SRGB_BIST_CTRL_3_srgb_g_drf_bist_fail_mask                  (0x00002000)
#define  GAMMA_GAMMA_SRGB_BIST_CTRL_3_srgb_b_drf_bist_fail_mask                  (0x00001000)
#define  GAMMA_GAMMA_SRGB_BIST_CTRL_3_gamma_r_drf_bist_fail_mask                 (0x00000800)
#define  GAMMA_GAMMA_SRGB_BIST_CTRL_3_gamma_g_drf_bist_fail_mask                 (0x00000400)
#define  GAMMA_GAMMA_SRGB_BIST_CTRL_3_gamma_b_drf_bist_fail_mask                 (0x00000200)
#define  GAMMA_GAMMA_SRGB_BIST_CTRL_3_inv_gamma_r_bist_fail_mask                 (0x00000100)
#define  GAMMA_GAMMA_SRGB_BIST_CTRL_3_inv_gamma_g_bist_fail_mask                 (0x00000080)
#define  GAMMA_GAMMA_SRGB_BIST_CTRL_3_inv_gamma_b_bist_fail_mask                 (0x00000040)
#define  GAMMA_GAMMA_SRGB_BIST_CTRL_3_srgb_r_bist_fail_mask                      (0x00000020)
#define  GAMMA_GAMMA_SRGB_BIST_CTRL_3_srgb_g_bist_fail_mask                      (0x00000010)
#define  GAMMA_GAMMA_SRGB_BIST_CTRL_3_srgb_b_bist_fail_mask                      (0x00000008)
#define  GAMMA_GAMMA_SRGB_BIST_CTRL_3_gamma_r_bist_fail_mask                     (0x00000004)
#define  GAMMA_GAMMA_SRGB_BIST_CTRL_3_gamma_g_bist_fail_mask                     (0x00000002)
#define  GAMMA_GAMMA_SRGB_BIST_CTRL_3_gamma_b_bist_fail_mask                     (0x00000001)
#define  GAMMA_GAMMA_SRGB_BIST_CTRL_3_inv_gamma_r_drf_bist_fail(data)            (0x00020000&((data)<<17))
#define  GAMMA_GAMMA_SRGB_BIST_CTRL_3_inv_gamma_g_drf_bist_fail(data)            (0x00010000&((data)<<16))
#define  GAMMA_GAMMA_SRGB_BIST_CTRL_3_inv_gamma_b_drf_bist_fail(data)            (0x00008000&((data)<<15))
#define  GAMMA_GAMMA_SRGB_BIST_CTRL_3_srgb_r_drf_bist_fail(data)                 (0x00004000&((data)<<14))
#define  GAMMA_GAMMA_SRGB_BIST_CTRL_3_srgb_g_drf_bist_fail(data)                 (0x00002000&((data)<<13))
#define  GAMMA_GAMMA_SRGB_BIST_CTRL_3_srgb_b_drf_bist_fail(data)                 (0x00001000&((data)<<12))
#define  GAMMA_GAMMA_SRGB_BIST_CTRL_3_gamma_r_drf_bist_fail(data)                (0x00000800&((data)<<11))
#define  GAMMA_GAMMA_SRGB_BIST_CTRL_3_gamma_g_drf_bist_fail(data)                (0x00000400&((data)<<10))
#define  GAMMA_GAMMA_SRGB_BIST_CTRL_3_gamma_b_drf_bist_fail(data)                (0x00000200&((data)<<9))
#define  GAMMA_GAMMA_SRGB_BIST_CTRL_3_inv_gamma_r_bist_fail(data)                (0x00000100&((data)<<8))
#define  GAMMA_GAMMA_SRGB_BIST_CTRL_3_inv_gamma_g_bist_fail(data)                (0x00000080&((data)<<7))
#define  GAMMA_GAMMA_SRGB_BIST_CTRL_3_inv_gamma_b_bist_fail(data)                (0x00000040&((data)<<6))
#define  GAMMA_GAMMA_SRGB_BIST_CTRL_3_srgb_r_bist_fail(data)                     (0x00000020&((data)<<5))
#define  GAMMA_GAMMA_SRGB_BIST_CTRL_3_srgb_g_bist_fail(data)                     (0x00000010&((data)<<4))
#define  GAMMA_GAMMA_SRGB_BIST_CTRL_3_srgb_b_bist_fail(data)                     (0x00000008&((data)<<3))
#define  GAMMA_GAMMA_SRGB_BIST_CTRL_3_gamma_r_bist_fail(data)                    (0x00000004&((data)<<2))
#define  GAMMA_GAMMA_SRGB_BIST_CTRL_3_gamma_g_bist_fail(data)                    (0x00000002&((data)<<1))
#define  GAMMA_GAMMA_SRGB_BIST_CTRL_3_gamma_b_bist_fail(data)                    (0x00000001&(data))
#define  GAMMA_GAMMA_SRGB_BIST_CTRL_3_get_inv_gamma_r_drf_bist_fail(data)        ((0x00020000&(data))>>17)
#define  GAMMA_GAMMA_SRGB_BIST_CTRL_3_get_inv_gamma_g_drf_bist_fail(data)        ((0x00010000&(data))>>16)
#define  GAMMA_GAMMA_SRGB_BIST_CTRL_3_get_inv_gamma_b_drf_bist_fail(data)        ((0x00008000&(data))>>15)
#define  GAMMA_GAMMA_SRGB_BIST_CTRL_3_get_srgb_r_drf_bist_fail(data)             ((0x00004000&(data))>>14)
#define  GAMMA_GAMMA_SRGB_BIST_CTRL_3_get_srgb_g_drf_bist_fail(data)             ((0x00002000&(data))>>13)
#define  GAMMA_GAMMA_SRGB_BIST_CTRL_3_get_srgb_b_drf_bist_fail(data)             ((0x00001000&(data))>>12)
#define  GAMMA_GAMMA_SRGB_BIST_CTRL_3_get_gamma_r_drf_bist_fail(data)            ((0x00000800&(data))>>11)
#define  GAMMA_GAMMA_SRGB_BIST_CTRL_3_get_gamma_g_drf_bist_fail(data)            ((0x00000400&(data))>>10)
#define  GAMMA_GAMMA_SRGB_BIST_CTRL_3_get_gamma_b_drf_bist_fail(data)            ((0x00000200&(data))>>9)
#define  GAMMA_GAMMA_SRGB_BIST_CTRL_3_get_inv_gamma_r_bist_fail(data)            ((0x00000100&(data))>>8)
#define  GAMMA_GAMMA_SRGB_BIST_CTRL_3_get_inv_gamma_g_bist_fail(data)            ((0x00000080&(data))>>7)
#define  GAMMA_GAMMA_SRGB_BIST_CTRL_3_get_inv_gamma_b_bist_fail(data)            ((0x00000040&(data))>>6)
#define  GAMMA_GAMMA_SRGB_BIST_CTRL_3_get_srgb_r_bist_fail(data)                 ((0x00000020&(data))>>5)
#define  GAMMA_GAMMA_SRGB_BIST_CTRL_3_get_srgb_g_bist_fail(data)                 ((0x00000010&(data))>>4)
#define  GAMMA_GAMMA_SRGB_BIST_CTRL_3_get_srgb_b_bist_fail(data)                 ((0x00000008&(data))>>3)
#define  GAMMA_GAMMA_SRGB_BIST_CTRL_3_get_gamma_r_bist_fail(data)                ((0x00000004&(data))>>2)
#define  GAMMA_GAMMA_SRGB_BIST_CTRL_3_get_gamma_g_bist_fail(data)                ((0x00000002&(data))>>1)
#define  GAMMA_GAMMA_SRGB_BIST_CTRL_3_get_gamma_b_bist_fail(data)                (0x00000001&(data))

#define  GAMMA_ADAPT_GAMMA                                                       0x1802C120
#define  GAMMA_ADAPT_GAMMA_reg_addr                                              "0xB802C120"
#define  GAMMA_ADAPT_GAMMA_reg                                                   0xB802C120
#define  GAMMA_ADAPT_GAMMA_inst_addr                                             "0x0006"
#define  set_GAMMA_ADAPT_GAMMA_reg(data)                                         (*((volatile unsigned int*)GAMMA_ADAPT_GAMMA_reg)=data)
#define  get_GAMMA_ADAPT_GAMMA_reg                                               (*((volatile unsigned int*)GAMMA_ADAPT_GAMMA_reg))
#define  GAMMA_ADAPT_GAMMA_gamma_adapt_en_shift                                  (31)
#define  GAMMA_ADAPT_GAMMA_sat_thl_shift                                         (16)
#define  GAMMA_ADAPT_GAMMA_sat_thl_mul_shift                                     (0)
#define  GAMMA_ADAPT_GAMMA_gamma_adapt_en_mask                                   (0x80000000)
#define  GAMMA_ADAPT_GAMMA_sat_thl_mask                                          (0x0FFF0000)
#define  GAMMA_ADAPT_GAMMA_sat_thl_mul_mask                                      (0x00000FFF)
#define  GAMMA_ADAPT_GAMMA_gamma_adapt_en(data)                                  (0x80000000&((data)<<31))
#define  GAMMA_ADAPT_GAMMA_sat_thl(data)                                         (0x0FFF0000&((data)<<16))
#define  GAMMA_ADAPT_GAMMA_sat_thl_mul(data)                                     (0x00000FFF&(data))
#define  GAMMA_ADAPT_GAMMA_get_gamma_adapt_en(data)                              ((0x80000000&(data))>>31)
#define  GAMMA_ADAPT_GAMMA_get_sat_thl(data)                                     ((0x0FFF0000&(data))>>16)
#define  GAMMA_ADAPT_GAMMA_get_sat_thl_mul(data)                                 (0x00000FFF&(data))

#define  GAMMA_GAMMA_BS_CONTROL                                                  0x1802C130
#define  GAMMA_GAMMA_BS_CONTROL_reg_addr                                         "0xB802C130"
#define  GAMMA_GAMMA_BS_CONTROL_reg                                              0xB802C130
#define  GAMMA_GAMMA_BS_CONTROL_inst_addr                                        "0x0007"
#define  set_GAMMA_GAMMA_BS_CONTROL_reg(data)                                    (*((volatile unsigned int*)GAMMA_GAMMA_BS_CONTROL_reg)=data)
#define  get_GAMMA_GAMMA_BS_CONTROL_reg                                          (*((volatile unsigned int*)GAMMA_GAMMA_BS_CONTROL_reg))
#define  GAMMA_GAMMA_BS_CONTROL_dummy_31_22_shift                                (22)
#define  GAMMA_GAMMA_BS_CONTROL_gamma_bs_r_gain_shift                            (20)
#define  GAMMA_GAMMA_BS_CONTROL_gamma_bs_g_gain_shift                            (18)
#define  GAMMA_GAMMA_BS_CONTROL_gamma_bs_b_gain_shift                            (16)
#define  GAMMA_GAMMA_BS_CONTROL_gamma_bs_sat_thd_shift                           (8)
#define  GAMMA_GAMMA_BS_CONTROL_gamma_m_bs_en_shift                              (1)
#define  GAMMA_GAMMA_BS_CONTROL_dummy_31_22_mask                                 (0xFFC00000)
#define  GAMMA_GAMMA_BS_CONTROL_gamma_bs_r_gain_mask                             (0x00300000)
#define  GAMMA_GAMMA_BS_CONTROL_gamma_bs_g_gain_mask                             (0x000C0000)
#define  GAMMA_GAMMA_BS_CONTROL_gamma_bs_b_gain_mask                             (0x00030000)
#define  GAMMA_GAMMA_BS_CONTROL_gamma_bs_sat_thd_mask                            (0x0000FF00)
#define  GAMMA_GAMMA_BS_CONTROL_gamma_m_bs_en_mask                               (0x00000002)
#define  GAMMA_GAMMA_BS_CONTROL_dummy_31_22(data)                                (0xFFC00000&((data)<<22))
#define  GAMMA_GAMMA_BS_CONTROL_gamma_bs_r_gain(data)                            (0x00300000&((data)<<20))
#define  GAMMA_GAMMA_BS_CONTROL_gamma_bs_g_gain(data)                            (0x000C0000&((data)<<18))
#define  GAMMA_GAMMA_BS_CONTROL_gamma_bs_b_gain(data)                            (0x00030000&((data)<<16))
#define  GAMMA_GAMMA_BS_CONTROL_gamma_bs_sat_thd(data)                           (0x0000FF00&((data)<<8))
#define  GAMMA_GAMMA_BS_CONTROL_gamma_m_bs_en(data)                              (0x00000002&((data)<<1))
#define  GAMMA_GAMMA_BS_CONTROL_get_dummy_31_22(data)                            ((0xFFC00000&(data))>>22)
#define  GAMMA_GAMMA_BS_CONTROL_get_gamma_bs_r_gain(data)                        ((0x00300000&(data))>>20)
#define  GAMMA_GAMMA_BS_CONTROL_get_gamma_bs_g_gain(data)                        ((0x000C0000&(data))>>18)
#define  GAMMA_GAMMA_BS_CONTROL_get_gamma_bs_b_gain(data)                        ((0x00030000&(data))>>16)
#define  GAMMA_GAMMA_BS_CONTROL_get_gamma_bs_sat_thd(data)                       ((0x0000FF00&(data))>>8)
#define  GAMMA_GAMMA_BS_CONTROL_get_gamma_m_bs_en(data)                          ((0x00000002&(data))>>1)

#define  GAMMA_GAMMA_BS_Y_INDEX_1                                                0x1802C134
#define  GAMMA_GAMMA_BS_Y_INDEX_1_reg_addr                                       "0xB802C134"
#define  GAMMA_GAMMA_BS_Y_INDEX_1_reg                                            0xB802C134
#define  GAMMA_GAMMA_BS_Y_INDEX_1_inst_addr                                      "0x0008"
#define  set_GAMMA_GAMMA_BS_Y_INDEX_1_reg(data)                                  (*((volatile unsigned int*)GAMMA_GAMMA_BS_Y_INDEX_1_reg)=data)
#define  get_GAMMA_GAMMA_BS_Y_INDEX_1_reg                                        (*((volatile unsigned int*)GAMMA_GAMMA_BS_Y_INDEX_1_reg))
#define  GAMMA_GAMMA_BS_Y_INDEX_1_gamma_bs_y3_shift                              (24)
#define  GAMMA_GAMMA_BS_Y_INDEX_1_gamma_bs_y2_shift                              (16)
#define  GAMMA_GAMMA_BS_Y_INDEX_1_gamma_bs_y1_shift                              (8)
#define  GAMMA_GAMMA_BS_Y_INDEX_1_gamma_bs_y0_shift                              (0)
#define  GAMMA_GAMMA_BS_Y_INDEX_1_gamma_bs_y3_mask                               (0xFF000000)
#define  GAMMA_GAMMA_BS_Y_INDEX_1_gamma_bs_y2_mask                               (0x00FF0000)
#define  GAMMA_GAMMA_BS_Y_INDEX_1_gamma_bs_y1_mask                               (0x0000FF00)
#define  GAMMA_GAMMA_BS_Y_INDEX_1_gamma_bs_y0_mask                               (0x000000FF)
#define  GAMMA_GAMMA_BS_Y_INDEX_1_gamma_bs_y3(data)                              (0xFF000000&((data)<<24))
#define  GAMMA_GAMMA_BS_Y_INDEX_1_gamma_bs_y2(data)                              (0x00FF0000&((data)<<16))
#define  GAMMA_GAMMA_BS_Y_INDEX_1_gamma_bs_y1(data)                              (0x0000FF00&((data)<<8))
#define  GAMMA_GAMMA_BS_Y_INDEX_1_gamma_bs_y0(data)                              (0x000000FF&(data))
#define  GAMMA_GAMMA_BS_Y_INDEX_1_get_gamma_bs_y3(data)                          ((0xFF000000&(data))>>24)
#define  GAMMA_GAMMA_BS_Y_INDEX_1_get_gamma_bs_y2(data)                          ((0x00FF0000&(data))>>16)
#define  GAMMA_GAMMA_BS_Y_INDEX_1_get_gamma_bs_y1(data)                          ((0x0000FF00&(data))>>8)
#define  GAMMA_GAMMA_BS_Y_INDEX_1_get_gamma_bs_y0(data)                          (0x000000FF&(data))

#define  GAMMA_GAMMA_BS_Y_INDEX_2                                                0x1802C138
#define  GAMMA_GAMMA_BS_Y_INDEX_2_reg_addr                                       "0xB802C138"
#define  GAMMA_GAMMA_BS_Y_INDEX_2_reg                                            0xB802C138
#define  GAMMA_GAMMA_BS_Y_INDEX_2_inst_addr                                      "0x0009"
#define  set_GAMMA_GAMMA_BS_Y_INDEX_2_reg(data)                                  (*((volatile unsigned int*)GAMMA_GAMMA_BS_Y_INDEX_2_reg)=data)
#define  get_GAMMA_GAMMA_BS_Y_INDEX_2_reg                                        (*((volatile unsigned int*)GAMMA_GAMMA_BS_Y_INDEX_2_reg))
#define  GAMMA_GAMMA_BS_Y_INDEX_2_gamma_bs_y7_shift                              (24)
#define  GAMMA_GAMMA_BS_Y_INDEX_2_gamma_bs_y6_shift                              (16)
#define  GAMMA_GAMMA_BS_Y_INDEX_2_gamma_bs_y5_shift                              (8)
#define  GAMMA_GAMMA_BS_Y_INDEX_2_gamma_bs_y4_shift                              (0)
#define  GAMMA_GAMMA_BS_Y_INDEX_2_gamma_bs_y7_mask                               (0xFF000000)
#define  GAMMA_GAMMA_BS_Y_INDEX_2_gamma_bs_y6_mask                               (0x00FF0000)
#define  GAMMA_GAMMA_BS_Y_INDEX_2_gamma_bs_y5_mask                               (0x0000FF00)
#define  GAMMA_GAMMA_BS_Y_INDEX_2_gamma_bs_y4_mask                               (0x000000FF)
#define  GAMMA_GAMMA_BS_Y_INDEX_2_gamma_bs_y7(data)                              (0xFF000000&((data)<<24))
#define  GAMMA_GAMMA_BS_Y_INDEX_2_gamma_bs_y6(data)                              (0x00FF0000&((data)<<16))
#define  GAMMA_GAMMA_BS_Y_INDEX_2_gamma_bs_y5(data)                              (0x0000FF00&((data)<<8))
#define  GAMMA_GAMMA_BS_Y_INDEX_2_gamma_bs_y4(data)                              (0x000000FF&(data))
#define  GAMMA_GAMMA_BS_Y_INDEX_2_get_gamma_bs_y7(data)                          ((0xFF000000&(data))>>24)
#define  GAMMA_GAMMA_BS_Y_INDEX_2_get_gamma_bs_y6(data)                          ((0x00FF0000&(data))>>16)
#define  GAMMA_GAMMA_BS_Y_INDEX_2_get_gamma_bs_y5(data)                          ((0x0000FF00&(data))>>8)
#define  GAMMA_GAMMA_BS_Y_INDEX_2_get_gamma_bs_y4(data)                          (0x000000FF&(data))

#define  GAMMA_GAMMA_BS_R_OFFSET_1                                               0x1802C13C
#define  GAMMA_GAMMA_BS_R_OFFSET_1_reg_addr                                      "0xB802C13C"
#define  GAMMA_GAMMA_BS_R_OFFSET_1_reg                                           0xB802C13C
#define  GAMMA_GAMMA_BS_R_OFFSET_1_inst_addr                                     "0x000A"
#define  set_GAMMA_GAMMA_BS_R_OFFSET_1_reg(data)                                 (*((volatile unsigned int*)GAMMA_GAMMA_BS_R_OFFSET_1_reg)=data)
#define  get_GAMMA_GAMMA_BS_R_OFFSET_1_reg                                       (*((volatile unsigned int*)GAMMA_GAMMA_BS_R_OFFSET_1_reg))
#define  GAMMA_GAMMA_BS_R_OFFSET_1_gamma_bs_r_ofst_2_shift                       (18)
#define  GAMMA_GAMMA_BS_R_OFFSET_1_gamma_bs_r_ofst_1_shift                       (9)
#define  GAMMA_GAMMA_BS_R_OFFSET_1_gamma_bs_r_ofst_0_shift                       (0)
#define  GAMMA_GAMMA_BS_R_OFFSET_1_gamma_bs_r_ofst_2_mask                        (0x07FC0000)
#define  GAMMA_GAMMA_BS_R_OFFSET_1_gamma_bs_r_ofst_1_mask                        (0x0003FE00)
#define  GAMMA_GAMMA_BS_R_OFFSET_1_gamma_bs_r_ofst_0_mask                        (0x000001FF)
#define  GAMMA_GAMMA_BS_R_OFFSET_1_gamma_bs_r_ofst_2(data)                       (0x07FC0000&((data)<<18))
#define  GAMMA_GAMMA_BS_R_OFFSET_1_gamma_bs_r_ofst_1(data)                       (0x0003FE00&((data)<<9))
#define  GAMMA_GAMMA_BS_R_OFFSET_1_gamma_bs_r_ofst_0(data)                       (0x000001FF&(data))
#define  GAMMA_GAMMA_BS_R_OFFSET_1_get_gamma_bs_r_ofst_2(data)                   ((0x07FC0000&(data))>>18)
#define  GAMMA_GAMMA_BS_R_OFFSET_1_get_gamma_bs_r_ofst_1(data)                   ((0x0003FE00&(data))>>9)
#define  GAMMA_GAMMA_BS_R_OFFSET_1_get_gamma_bs_r_ofst_0(data)                   (0x000001FF&(data))

#define  GAMMA_GAMMA_BS_R_OFFSET_2                                               0x1802C140
#define  GAMMA_GAMMA_BS_R_OFFSET_2_reg_addr                                      "0xB802C140"
#define  GAMMA_GAMMA_BS_R_OFFSET_2_reg                                           0xB802C140
#define  GAMMA_GAMMA_BS_R_OFFSET_2_inst_addr                                     "0x000B"
#define  set_GAMMA_GAMMA_BS_R_OFFSET_2_reg(data)                                 (*((volatile unsigned int*)GAMMA_GAMMA_BS_R_OFFSET_2_reg)=data)
#define  get_GAMMA_GAMMA_BS_R_OFFSET_2_reg                                       (*((volatile unsigned int*)GAMMA_GAMMA_BS_R_OFFSET_2_reg))
#define  GAMMA_GAMMA_BS_R_OFFSET_2_gamma_bs_r_ofst_5_shift                       (18)
#define  GAMMA_GAMMA_BS_R_OFFSET_2_gamma_bs_r_ofst_4_shift                       (9)
#define  GAMMA_GAMMA_BS_R_OFFSET_2_gamma_bs_r_ofst_3_shift                       (0)
#define  GAMMA_GAMMA_BS_R_OFFSET_2_gamma_bs_r_ofst_5_mask                        (0x07FC0000)
#define  GAMMA_GAMMA_BS_R_OFFSET_2_gamma_bs_r_ofst_4_mask                        (0x0003FE00)
#define  GAMMA_GAMMA_BS_R_OFFSET_2_gamma_bs_r_ofst_3_mask                        (0x000001FF)
#define  GAMMA_GAMMA_BS_R_OFFSET_2_gamma_bs_r_ofst_5(data)                       (0x07FC0000&((data)<<18))
#define  GAMMA_GAMMA_BS_R_OFFSET_2_gamma_bs_r_ofst_4(data)                       (0x0003FE00&((data)<<9))
#define  GAMMA_GAMMA_BS_R_OFFSET_2_gamma_bs_r_ofst_3(data)                       (0x000001FF&(data))
#define  GAMMA_GAMMA_BS_R_OFFSET_2_get_gamma_bs_r_ofst_5(data)                   ((0x07FC0000&(data))>>18)
#define  GAMMA_GAMMA_BS_R_OFFSET_2_get_gamma_bs_r_ofst_4(data)                   ((0x0003FE00&(data))>>9)
#define  GAMMA_GAMMA_BS_R_OFFSET_2_get_gamma_bs_r_ofst_3(data)                   (0x000001FF&(data))

#define  GAMMA_GAMMA_BS_R_OFFSET_3                                               0x1802C144
#define  GAMMA_GAMMA_BS_R_OFFSET_3_reg_addr                                      "0xB802C144"
#define  GAMMA_GAMMA_BS_R_OFFSET_3_reg                                           0xB802C144
#define  GAMMA_GAMMA_BS_R_OFFSET_3_inst_addr                                     "0x000C"
#define  set_GAMMA_GAMMA_BS_R_OFFSET_3_reg(data)                                 (*((volatile unsigned int*)GAMMA_GAMMA_BS_R_OFFSET_3_reg)=data)
#define  get_GAMMA_GAMMA_BS_R_OFFSET_3_reg                                       (*((volatile unsigned int*)GAMMA_GAMMA_BS_R_OFFSET_3_reg))
#define  GAMMA_GAMMA_BS_R_OFFSET_3_gamma_bs_r_ofst_7_shift                       (9)
#define  GAMMA_GAMMA_BS_R_OFFSET_3_gamma_bs_r_ofst_6_shift                       (0)
#define  GAMMA_GAMMA_BS_R_OFFSET_3_gamma_bs_r_ofst_7_mask                        (0x0003FE00)
#define  GAMMA_GAMMA_BS_R_OFFSET_3_gamma_bs_r_ofst_6_mask                        (0x000001FF)
#define  GAMMA_GAMMA_BS_R_OFFSET_3_gamma_bs_r_ofst_7(data)                       (0x0003FE00&((data)<<9))
#define  GAMMA_GAMMA_BS_R_OFFSET_3_gamma_bs_r_ofst_6(data)                       (0x000001FF&(data))
#define  GAMMA_GAMMA_BS_R_OFFSET_3_get_gamma_bs_r_ofst_7(data)                   ((0x0003FE00&(data))>>9)
#define  GAMMA_GAMMA_BS_R_OFFSET_3_get_gamma_bs_r_ofst_6(data)                   (0x000001FF&(data))

#define  GAMMA_GAMMA_BS_G_OFFSET_1                                               0x1802C148
#define  GAMMA_GAMMA_BS_G_OFFSET_1_reg_addr                                      "0xB802C148"
#define  GAMMA_GAMMA_BS_G_OFFSET_1_reg                                           0xB802C148
#define  GAMMA_GAMMA_BS_G_OFFSET_1_inst_addr                                     "0x000D"
#define  set_GAMMA_GAMMA_BS_G_OFFSET_1_reg(data)                                 (*((volatile unsigned int*)GAMMA_GAMMA_BS_G_OFFSET_1_reg)=data)
#define  get_GAMMA_GAMMA_BS_G_OFFSET_1_reg                                       (*((volatile unsigned int*)GAMMA_GAMMA_BS_G_OFFSET_1_reg))
#define  GAMMA_GAMMA_BS_G_OFFSET_1_gamma_bs_g_ofst_2_shift                       (18)
#define  GAMMA_GAMMA_BS_G_OFFSET_1_gamma_bs_g_ofst_1_shift                       (9)
#define  GAMMA_GAMMA_BS_G_OFFSET_1_gamma_bs_g_ofst_0_shift                       (0)
#define  GAMMA_GAMMA_BS_G_OFFSET_1_gamma_bs_g_ofst_2_mask                        (0x07FC0000)
#define  GAMMA_GAMMA_BS_G_OFFSET_1_gamma_bs_g_ofst_1_mask                        (0x0003FE00)
#define  GAMMA_GAMMA_BS_G_OFFSET_1_gamma_bs_g_ofst_0_mask                        (0x000001FF)
#define  GAMMA_GAMMA_BS_G_OFFSET_1_gamma_bs_g_ofst_2(data)                       (0x07FC0000&((data)<<18))
#define  GAMMA_GAMMA_BS_G_OFFSET_1_gamma_bs_g_ofst_1(data)                       (0x0003FE00&((data)<<9))
#define  GAMMA_GAMMA_BS_G_OFFSET_1_gamma_bs_g_ofst_0(data)                       (0x000001FF&(data))
#define  GAMMA_GAMMA_BS_G_OFFSET_1_get_gamma_bs_g_ofst_2(data)                   ((0x07FC0000&(data))>>18)
#define  GAMMA_GAMMA_BS_G_OFFSET_1_get_gamma_bs_g_ofst_1(data)                   ((0x0003FE00&(data))>>9)
#define  GAMMA_GAMMA_BS_G_OFFSET_1_get_gamma_bs_g_ofst_0(data)                   (0x000001FF&(data))

#define  GAMMA_GAMMA_BS_G_OFFSET_2                                               0x1802C14C
#define  GAMMA_GAMMA_BS_G_OFFSET_2_reg_addr                                      "0xB802C14C"
#define  GAMMA_GAMMA_BS_G_OFFSET_2_reg                                           0xB802C14C
#define  GAMMA_GAMMA_BS_G_OFFSET_2_inst_addr                                     "0x000E"
#define  set_GAMMA_GAMMA_BS_G_OFFSET_2_reg(data)                                 (*((volatile unsigned int*)GAMMA_GAMMA_BS_G_OFFSET_2_reg)=data)
#define  get_GAMMA_GAMMA_BS_G_OFFSET_2_reg                                       (*((volatile unsigned int*)GAMMA_GAMMA_BS_G_OFFSET_2_reg))
#define  GAMMA_GAMMA_BS_G_OFFSET_2_gamma_bs_g_ofst_5_shift                       (18)
#define  GAMMA_GAMMA_BS_G_OFFSET_2_gamma_bs_g_ofst_4_shift                       (9)
#define  GAMMA_GAMMA_BS_G_OFFSET_2_gamma_bs_g_ofst_3_shift                       (0)
#define  GAMMA_GAMMA_BS_G_OFFSET_2_gamma_bs_g_ofst_5_mask                        (0x07FC0000)
#define  GAMMA_GAMMA_BS_G_OFFSET_2_gamma_bs_g_ofst_4_mask                        (0x0003FE00)
#define  GAMMA_GAMMA_BS_G_OFFSET_2_gamma_bs_g_ofst_3_mask                        (0x000001FF)
#define  GAMMA_GAMMA_BS_G_OFFSET_2_gamma_bs_g_ofst_5(data)                       (0x07FC0000&((data)<<18))
#define  GAMMA_GAMMA_BS_G_OFFSET_2_gamma_bs_g_ofst_4(data)                       (0x0003FE00&((data)<<9))
#define  GAMMA_GAMMA_BS_G_OFFSET_2_gamma_bs_g_ofst_3(data)                       (0x000001FF&(data))
#define  GAMMA_GAMMA_BS_G_OFFSET_2_get_gamma_bs_g_ofst_5(data)                   ((0x07FC0000&(data))>>18)
#define  GAMMA_GAMMA_BS_G_OFFSET_2_get_gamma_bs_g_ofst_4(data)                   ((0x0003FE00&(data))>>9)
#define  GAMMA_GAMMA_BS_G_OFFSET_2_get_gamma_bs_g_ofst_3(data)                   (0x000001FF&(data))

#define  GAMMA_GAMMA_BS_G_OFFSET_3                                               0x1802C150
#define  GAMMA_GAMMA_BS_G_OFFSET_3_reg_addr                                      "0xB802C150"
#define  GAMMA_GAMMA_BS_G_OFFSET_3_reg                                           0xB802C150
#define  GAMMA_GAMMA_BS_G_OFFSET_3_inst_addr                                     "0x000F"
#define  set_GAMMA_GAMMA_BS_G_OFFSET_3_reg(data)                                 (*((volatile unsigned int*)GAMMA_GAMMA_BS_G_OFFSET_3_reg)=data)
#define  get_GAMMA_GAMMA_BS_G_OFFSET_3_reg                                       (*((volatile unsigned int*)GAMMA_GAMMA_BS_G_OFFSET_3_reg))
#define  GAMMA_GAMMA_BS_G_OFFSET_3_gamma_bs_g_ofst_7_shift                       (9)
#define  GAMMA_GAMMA_BS_G_OFFSET_3_gamma_bs_g_ofst_6_shift                       (0)
#define  GAMMA_GAMMA_BS_G_OFFSET_3_gamma_bs_g_ofst_7_mask                        (0x0003FE00)
#define  GAMMA_GAMMA_BS_G_OFFSET_3_gamma_bs_g_ofst_6_mask                        (0x000001FF)
#define  GAMMA_GAMMA_BS_G_OFFSET_3_gamma_bs_g_ofst_7(data)                       (0x0003FE00&((data)<<9))
#define  GAMMA_GAMMA_BS_G_OFFSET_3_gamma_bs_g_ofst_6(data)                       (0x000001FF&(data))
#define  GAMMA_GAMMA_BS_G_OFFSET_3_get_gamma_bs_g_ofst_7(data)                   ((0x0003FE00&(data))>>9)
#define  GAMMA_GAMMA_BS_G_OFFSET_3_get_gamma_bs_g_ofst_6(data)                   (0x000001FF&(data))

#define  GAMMA_GAMMA_BS_B_OFFSET_1                                               0x1802C154
#define  GAMMA_GAMMA_BS_B_OFFSET_1_reg_addr                                      "0xB802C154"
#define  GAMMA_GAMMA_BS_B_OFFSET_1_reg                                           0xB802C154
#define  GAMMA_GAMMA_BS_B_OFFSET_1_inst_addr                                     "0x0010"
#define  set_GAMMA_GAMMA_BS_B_OFFSET_1_reg(data)                                 (*((volatile unsigned int*)GAMMA_GAMMA_BS_B_OFFSET_1_reg)=data)
#define  get_GAMMA_GAMMA_BS_B_OFFSET_1_reg                                       (*((volatile unsigned int*)GAMMA_GAMMA_BS_B_OFFSET_1_reg))
#define  GAMMA_GAMMA_BS_B_OFFSET_1_gamma_bs_b_ofst_2_shift                       (18)
#define  GAMMA_GAMMA_BS_B_OFFSET_1_gamma_bs_b_ofst_1_shift                       (9)
#define  GAMMA_GAMMA_BS_B_OFFSET_1_gamma_bs_b_ofst_0_shift                       (0)
#define  GAMMA_GAMMA_BS_B_OFFSET_1_gamma_bs_b_ofst_2_mask                        (0x07FC0000)
#define  GAMMA_GAMMA_BS_B_OFFSET_1_gamma_bs_b_ofst_1_mask                        (0x0003FE00)
#define  GAMMA_GAMMA_BS_B_OFFSET_1_gamma_bs_b_ofst_0_mask                        (0x000001FF)
#define  GAMMA_GAMMA_BS_B_OFFSET_1_gamma_bs_b_ofst_2(data)                       (0x07FC0000&((data)<<18))
#define  GAMMA_GAMMA_BS_B_OFFSET_1_gamma_bs_b_ofst_1(data)                       (0x0003FE00&((data)<<9))
#define  GAMMA_GAMMA_BS_B_OFFSET_1_gamma_bs_b_ofst_0(data)                       (0x000001FF&(data))
#define  GAMMA_GAMMA_BS_B_OFFSET_1_get_gamma_bs_b_ofst_2(data)                   ((0x07FC0000&(data))>>18)
#define  GAMMA_GAMMA_BS_B_OFFSET_1_get_gamma_bs_b_ofst_1(data)                   ((0x0003FE00&(data))>>9)
#define  GAMMA_GAMMA_BS_B_OFFSET_1_get_gamma_bs_b_ofst_0(data)                   (0x000001FF&(data))

#define  GAMMA_GAMMA_BS_B_OFFSET_2                                               0x1802C158
#define  GAMMA_GAMMA_BS_B_OFFSET_2_reg_addr                                      "0xB802C158"
#define  GAMMA_GAMMA_BS_B_OFFSET_2_reg                                           0xB802C158
#define  GAMMA_GAMMA_BS_B_OFFSET_2_inst_addr                                     "0x0011"
#define  set_GAMMA_GAMMA_BS_B_OFFSET_2_reg(data)                                 (*((volatile unsigned int*)GAMMA_GAMMA_BS_B_OFFSET_2_reg)=data)
#define  get_GAMMA_GAMMA_BS_B_OFFSET_2_reg                                       (*((volatile unsigned int*)GAMMA_GAMMA_BS_B_OFFSET_2_reg))
#define  GAMMA_GAMMA_BS_B_OFFSET_2_gamma_bs_b_ofst_5_shift                       (18)
#define  GAMMA_GAMMA_BS_B_OFFSET_2_gamma_bs_b_ofst_4_shift                       (9)
#define  GAMMA_GAMMA_BS_B_OFFSET_2_gamma_bs_b_ofst_3_shift                       (0)
#define  GAMMA_GAMMA_BS_B_OFFSET_2_gamma_bs_b_ofst_5_mask                        (0x07FC0000)
#define  GAMMA_GAMMA_BS_B_OFFSET_2_gamma_bs_b_ofst_4_mask                        (0x0003FE00)
#define  GAMMA_GAMMA_BS_B_OFFSET_2_gamma_bs_b_ofst_3_mask                        (0x000001FF)
#define  GAMMA_GAMMA_BS_B_OFFSET_2_gamma_bs_b_ofst_5(data)                       (0x07FC0000&((data)<<18))
#define  GAMMA_GAMMA_BS_B_OFFSET_2_gamma_bs_b_ofst_4(data)                       (0x0003FE00&((data)<<9))
#define  GAMMA_GAMMA_BS_B_OFFSET_2_gamma_bs_b_ofst_3(data)                       (0x000001FF&(data))
#define  GAMMA_GAMMA_BS_B_OFFSET_2_get_gamma_bs_b_ofst_5(data)                   ((0x07FC0000&(data))>>18)
#define  GAMMA_GAMMA_BS_B_OFFSET_2_get_gamma_bs_b_ofst_4(data)                   ((0x0003FE00&(data))>>9)
#define  GAMMA_GAMMA_BS_B_OFFSET_2_get_gamma_bs_b_ofst_3(data)                   (0x000001FF&(data))

#define  GAMMA_GAMMA_BS_B_OFFSET_3                                               0x1802C15C
#define  GAMMA_GAMMA_BS_B_OFFSET_3_reg_addr                                      "0xB802C15C"
#define  GAMMA_GAMMA_BS_B_OFFSET_3_reg                                           0xB802C15C
#define  GAMMA_GAMMA_BS_B_OFFSET_3_inst_addr                                     "0x0012"
#define  set_GAMMA_GAMMA_BS_B_OFFSET_3_reg(data)                                 (*((volatile unsigned int*)GAMMA_GAMMA_BS_B_OFFSET_3_reg)=data)
#define  get_GAMMA_GAMMA_BS_B_OFFSET_3_reg                                       (*((volatile unsigned int*)GAMMA_GAMMA_BS_B_OFFSET_3_reg))
#define  GAMMA_GAMMA_BS_B_OFFSET_3_gamma_bs_b_ofst_7_shift                       (9)
#define  GAMMA_GAMMA_BS_B_OFFSET_3_gamma_bs_b_ofst_6_shift                       (0)
#define  GAMMA_GAMMA_BS_B_OFFSET_3_gamma_bs_b_ofst_7_mask                        (0x0003FE00)
#define  GAMMA_GAMMA_BS_B_OFFSET_3_gamma_bs_b_ofst_6_mask                        (0x000001FF)
#define  GAMMA_GAMMA_BS_B_OFFSET_3_gamma_bs_b_ofst_7(data)                       (0x0003FE00&((data)<<9))
#define  GAMMA_GAMMA_BS_B_OFFSET_3_gamma_bs_b_ofst_6(data)                       (0x000001FF&(data))
#define  GAMMA_GAMMA_BS_B_OFFSET_3_get_gamma_bs_b_ofst_7(data)                   ((0x0003FE00&(data))>>9)
#define  GAMMA_GAMMA_BS_B_OFFSET_3_get_gamma_bs_b_ofst_6(data)                   (0x000001FF&(data))

#define  GAMMA_GAMMA_BS_R_STEP_1                                                 0x1802C160
#define  GAMMA_GAMMA_BS_R_STEP_1_reg_addr                                        "0xB802C160"
#define  GAMMA_GAMMA_BS_R_STEP_1_reg                                             0xB802C160
#define  GAMMA_GAMMA_BS_R_STEP_1_inst_addr                                       "0x0013"
#define  set_GAMMA_GAMMA_BS_R_STEP_1_reg(data)                                   (*((volatile unsigned int*)GAMMA_GAMMA_BS_R_STEP_1_reg)=data)
#define  get_GAMMA_GAMMA_BS_R_STEP_1_reg                                         (*((volatile unsigned int*)GAMMA_GAMMA_BS_R_STEP_1_reg))
#define  GAMMA_GAMMA_BS_R_STEP_1_gamma_bs_r_step_3_shift                         (24)
#define  GAMMA_GAMMA_BS_R_STEP_1_gamma_bs_r_step_2_shift                         (16)
#define  GAMMA_GAMMA_BS_R_STEP_1_gamma_bs_r_step_1_shift                         (8)
#define  GAMMA_GAMMA_BS_R_STEP_1_gamma_bs_r_step_0_shift                         (0)
#define  GAMMA_GAMMA_BS_R_STEP_1_gamma_bs_r_step_3_mask                          (0x7F000000)
#define  GAMMA_GAMMA_BS_R_STEP_1_gamma_bs_r_step_2_mask                          (0x007F0000)
#define  GAMMA_GAMMA_BS_R_STEP_1_gamma_bs_r_step_1_mask                          (0x00007F00)
#define  GAMMA_GAMMA_BS_R_STEP_1_gamma_bs_r_step_0_mask                          (0x0000007F)
#define  GAMMA_GAMMA_BS_R_STEP_1_gamma_bs_r_step_3(data)                         (0x7F000000&((data)<<24))
#define  GAMMA_GAMMA_BS_R_STEP_1_gamma_bs_r_step_2(data)                         (0x007F0000&((data)<<16))
#define  GAMMA_GAMMA_BS_R_STEP_1_gamma_bs_r_step_1(data)                         (0x00007F00&((data)<<8))
#define  GAMMA_GAMMA_BS_R_STEP_1_gamma_bs_r_step_0(data)                         (0x0000007F&(data))
#define  GAMMA_GAMMA_BS_R_STEP_1_get_gamma_bs_r_step_3(data)                     ((0x7F000000&(data))>>24)
#define  GAMMA_GAMMA_BS_R_STEP_1_get_gamma_bs_r_step_2(data)                     ((0x007F0000&(data))>>16)
#define  GAMMA_GAMMA_BS_R_STEP_1_get_gamma_bs_r_step_1(data)                     ((0x00007F00&(data))>>8)
#define  GAMMA_GAMMA_BS_R_STEP_1_get_gamma_bs_r_step_0(data)                     (0x0000007F&(data))

#define  GAMMA_GAMMA_BS_R_STEP_2                                                 0x1802C164
#define  GAMMA_GAMMA_BS_R_STEP_2_reg_addr                                        "0xB802C164"
#define  GAMMA_GAMMA_BS_R_STEP_2_reg                                             0xB802C164
#define  GAMMA_GAMMA_BS_R_STEP_2_inst_addr                                       "0x0014"
#define  set_GAMMA_GAMMA_BS_R_STEP_2_reg(data)                                   (*((volatile unsigned int*)GAMMA_GAMMA_BS_R_STEP_2_reg)=data)
#define  get_GAMMA_GAMMA_BS_R_STEP_2_reg                                         (*((volatile unsigned int*)GAMMA_GAMMA_BS_R_STEP_2_reg))
#define  GAMMA_GAMMA_BS_R_STEP_2_gamma_bs_r_step_7_shift                         (24)
#define  GAMMA_GAMMA_BS_R_STEP_2_gamma_bs_r_step_6_shift                         (16)
#define  GAMMA_GAMMA_BS_R_STEP_2_gamma_bs_r_step_5_shift                         (8)
#define  GAMMA_GAMMA_BS_R_STEP_2_gamma_bs_r_step_4_shift                         (0)
#define  GAMMA_GAMMA_BS_R_STEP_2_gamma_bs_r_step_7_mask                          (0x7F000000)
#define  GAMMA_GAMMA_BS_R_STEP_2_gamma_bs_r_step_6_mask                          (0x007F0000)
#define  GAMMA_GAMMA_BS_R_STEP_2_gamma_bs_r_step_5_mask                          (0x00007F00)
#define  GAMMA_GAMMA_BS_R_STEP_2_gamma_bs_r_step_4_mask                          (0x0000007F)
#define  GAMMA_GAMMA_BS_R_STEP_2_gamma_bs_r_step_7(data)                         (0x7F000000&((data)<<24))
#define  GAMMA_GAMMA_BS_R_STEP_2_gamma_bs_r_step_6(data)                         (0x007F0000&((data)<<16))
#define  GAMMA_GAMMA_BS_R_STEP_2_gamma_bs_r_step_5(data)                         (0x00007F00&((data)<<8))
#define  GAMMA_GAMMA_BS_R_STEP_2_gamma_bs_r_step_4(data)                         (0x0000007F&(data))
#define  GAMMA_GAMMA_BS_R_STEP_2_get_gamma_bs_r_step_7(data)                     ((0x7F000000&(data))>>24)
#define  GAMMA_GAMMA_BS_R_STEP_2_get_gamma_bs_r_step_6(data)                     ((0x007F0000&(data))>>16)
#define  GAMMA_GAMMA_BS_R_STEP_2_get_gamma_bs_r_step_5(data)                     ((0x00007F00&(data))>>8)
#define  GAMMA_GAMMA_BS_R_STEP_2_get_gamma_bs_r_step_4(data)                     (0x0000007F&(data))

#define  GAMMA_GAMMA_BS_G_STEP_1                                                 0x1802C168
#define  GAMMA_GAMMA_BS_G_STEP_1_reg_addr                                        "0xB802C168"
#define  GAMMA_GAMMA_BS_G_STEP_1_reg                                             0xB802C168
#define  GAMMA_GAMMA_BS_G_STEP_1_inst_addr                                       "0x0015"
#define  set_GAMMA_GAMMA_BS_G_STEP_1_reg(data)                                   (*((volatile unsigned int*)GAMMA_GAMMA_BS_G_STEP_1_reg)=data)
#define  get_GAMMA_GAMMA_BS_G_STEP_1_reg                                         (*((volatile unsigned int*)GAMMA_GAMMA_BS_G_STEP_1_reg))
#define  GAMMA_GAMMA_BS_G_STEP_1_gamma_bs_g_step_3_shift                         (24)
#define  GAMMA_GAMMA_BS_G_STEP_1_gamma_bs_g_step_2_shift                         (16)
#define  GAMMA_GAMMA_BS_G_STEP_1_gamma_bs_g_step_1_shift                         (8)
#define  GAMMA_GAMMA_BS_G_STEP_1_gamma_bs_g_step_0_shift                         (0)
#define  GAMMA_GAMMA_BS_G_STEP_1_gamma_bs_g_step_3_mask                          (0x7F000000)
#define  GAMMA_GAMMA_BS_G_STEP_1_gamma_bs_g_step_2_mask                          (0x007F0000)
#define  GAMMA_GAMMA_BS_G_STEP_1_gamma_bs_g_step_1_mask                          (0x00007F00)
#define  GAMMA_GAMMA_BS_G_STEP_1_gamma_bs_g_step_0_mask                          (0x0000007F)
#define  GAMMA_GAMMA_BS_G_STEP_1_gamma_bs_g_step_3(data)                         (0x7F000000&((data)<<24))
#define  GAMMA_GAMMA_BS_G_STEP_1_gamma_bs_g_step_2(data)                         (0x007F0000&((data)<<16))
#define  GAMMA_GAMMA_BS_G_STEP_1_gamma_bs_g_step_1(data)                         (0x00007F00&((data)<<8))
#define  GAMMA_GAMMA_BS_G_STEP_1_gamma_bs_g_step_0(data)                         (0x0000007F&(data))
#define  GAMMA_GAMMA_BS_G_STEP_1_get_gamma_bs_g_step_3(data)                     ((0x7F000000&(data))>>24)
#define  GAMMA_GAMMA_BS_G_STEP_1_get_gamma_bs_g_step_2(data)                     ((0x007F0000&(data))>>16)
#define  GAMMA_GAMMA_BS_G_STEP_1_get_gamma_bs_g_step_1(data)                     ((0x00007F00&(data))>>8)
#define  GAMMA_GAMMA_BS_G_STEP_1_get_gamma_bs_g_step_0(data)                     (0x0000007F&(data))

#define  GAMMA_GAMMA_BS_G_STEP_2                                                 0x1802C16C
#define  GAMMA_GAMMA_BS_G_STEP_2_reg_addr                                        "0xB802C16C"
#define  GAMMA_GAMMA_BS_G_STEP_2_reg                                             0xB802C16C
#define  GAMMA_GAMMA_BS_G_STEP_2_inst_addr                                       "0x0016"
#define  set_GAMMA_GAMMA_BS_G_STEP_2_reg(data)                                   (*((volatile unsigned int*)GAMMA_GAMMA_BS_G_STEP_2_reg)=data)
#define  get_GAMMA_GAMMA_BS_G_STEP_2_reg                                         (*((volatile unsigned int*)GAMMA_GAMMA_BS_G_STEP_2_reg))
#define  GAMMA_GAMMA_BS_G_STEP_2_gamma_bs_g_step_7_shift                         (24)
#define  GAMMA_GAMMA_BS_G_STEP_2_gamma_bs_g_step_6_shift                         (16)
#define  GAMMA_GAMMA_BS_G_STEP_2_gamma_bs_g_step_5_shift                         (8)
#define  GAMMA_GAMMA_BS_G_STEP_2_gamma_bs_g_step_4_shift                         (0)
#define  GAMMA_GAMMA_BS_G_STEP_2_gamma_bs_g_step_7_mask                          (0x7F000000)
#define  GAMMA_GAMMA_BS_G_STEP_2_gamma_bs_g_step_6_mask                          (0x007F0000)
#define  GAMMA_GAMMA_BS_G_STEP_2_gamma_bs_g_step_5_mask                          (0x00007F00)
#define  GAMMA_GAMMA_BS_G_STEP_2_gamma_bs_g_step_4_mask                          (0x0000007F)
#define  GAMMA_GAMMA_BS_G_STEP_2_gamma_bs_g_step_7(data)                         (0x7F000000&((data)<<24))
#define  GAMMA_GAMMA_BS_G_STEP_2_gamma_bs_g_step_6(data)                         (0x007F0000&((data)<<16))
#define  GAMMA_GAMMA_BS_G_STEP_2_gamma_bs_g_step_5(data)                         (0x00007F00&((data)<<8))
#define  GAMMA_GAMMA_BS_G_STEP_2_gamma_bs_g_step_4(data)                         (0x0000007F&(data))
#define  GAMMA_GAMMA_BS_G_STEP_2_get_gamma_bs_g_step_7(data)                     ((0x7F000000&(data))>>24)
#define  GAMMA_GAMMA_BS_G_STEP_2_get_gamma_bs_g_step_6(data)                     ((0x007F0000&(data))>>16)
#define  GAMMA_GAMMA_BS_G_STEP_2_get_gamma_bs_g_step_5(data)                     ((0x00007F00&(data))>>8)
#define  GAMMA_GAMMA_BS_G_STEP_2_get_gamma_bs_g_step_4(data)                     (0x0000007F&(data))

#define  GAMMA_GAMMA_BS_B_STEP_1                                                 0x1802C170
#define  GAMMA_GAMMA_BS_B_STEP_1_reg_addr                                        "0xB802C170"
#define  GAMMA_GAMMA_BS_B_STEP_1_reg                                             0xB802C170
#define  GAMMA_GAMMA_BS_B_STEP_1_inst_addr                                       "0x0017"
#define  set_GAMMA_GAMMA_BS_B_STEP_1_reg(data)                                   (*((volatile unsigned int*)GAMMA_GAMMA_BS_B_STEP_1_reg)=data)
#define  get_GAMMA_GAMMA_BS_B_STEP_1_reg                                         (*((volatile unsigned int*)GAMMA_GAMMA_BS_B_STEP_1_reg))
#define  GAMMA_GAMMA_BS_B_STEP_1_gamma_bs_b_step_3_shift                         (24)
#define  GAMMA_GAMMA_BS_B_STEP_1_gamma_bs_b_step_2_shift                         (16)
#define  GAMMA_GAMMA_BS_B_STEP_1_gamma_bs_b_step_1_shift                         (8)
#define  GAMMA_GAMMA_BS_B_STEP_1_gamma_bs_b_step_0_shift                         (0)
#define  GAMMA_GAMMA_BS_B_STEP_1_gamma_bs_b_step_3_mask                          (0x7F000000)
#define  GAMMA_GAMMA_BS_B_STEP_1_gamma_bs_b_step_2_mask                          (0x007F0000)
#define  GAMMA_GAMMA_BS_B_STEP_1_gamma_bs_b_step_1_mask                          (0x00007F00)
#define  GAMMA_GAMMA_BS_B_STEP_1_gamma_bs_b_step_0_mask                          (0x0000007F)
#define  GAMMA_GAMMA_BS_B_STEP_1_gamma_bs_b_step_3(data)                         (0x7F000000&((data)<<24))
#define  GAMMA_GAMMA_BS_B_STEP_1_gamma_bs_b_step_2(data)                         (0x007F0000&((data)<<16))
#define  GAMMA_GAMMA_BS_B_STEP_1_gamma_bs_b_step_1(data)                         (0x00007F00&((data)<<8))
#define  GAMMA_GAMMA_BS_B_STEP_1_gamma_bs_b_step_0(data)                         (0x0000007F&(data))
#define  GAMMA_GAMMA_BS_B_STEP_1_get_gamma_bs_b_step_3(data)                     ((0x7F000000&(data))>>24)
#define  GAMMA_GAMMA_BS_B_STEP_1_get_gamma_bs_b_step_2(data)                     ((0x007F0000&(data))>>16)
#define  GAMMA_GAMMA_BS_B_STEP_1_get_gamma_bs_b_step_1(data)                     ((0x00007F00&(data))>>8)
#define  GAMMA_GAMMA_BS_B_STEP_1_get_gamma_bs_b_step_0(data)                     (0x0000007F&(data))

#define  GAMMA_GAMMA_BS_B_STEP_2                                                 0x1802C174
#define  GAMMA_GAMMA_BS_B_STEP_2_reg_addr                                        "0xB802C174"
#define  GAMMA_GAMMA_BS_B_STEP_2_reg                                             0xB802C174
#define  GAMMA_GAMMA_BS_B_STEP_2_inst_addr                                       "0x0018"
#define  set_GAMMA_GAMMA_BS_B_STEP_2_reg(data)                                   (*((volatile unsigned int*)GAMMA_GAMMA_BS_B_STEP_2_reg)=data)
#define  get_GAMMA_GAMMA_BS_B_STEP_2_reg                                         (*((volatile unsigned int*)GAMMA_GAMMA_BS_B_STEP_2_reg))
#define  GAMMA_GAMMA_BS_B_STEP_2_gamma_bs_b_step_7_shift                         (24)
#define  GAMMA_GAMMA_BS_B_STEP_2_gamma_bs_b_step_6_shift                         (16)
#define  GAMMA_GAMMA_BS_B_STEP_2_gamma_bs_b_step_5_shift                         (8)
#define  GAMMA_GAMMA_BS_B_STEP_2_gamma_bs_b_step_4_shift                         (0)
#define  GAMMA_GAMMA_BS_B_STEP_2_gamma_bs_b_step_7_mask                          (0x7F000000)
#define  GAMMA_GAMMA_BS_B_STEP_2_gamma_bs_b_step_6_mask                          (0x007F0000)
#define  GAMMA_GAMMA_BS_B_STEP_2_gamma_bs_b_step_5_mask                          (0x00007F00)
#define  GAMMA_GAMMA_BS_B_STEP_2_gamma_bs_b_step_4_mask                          (0x0000007F)
#define  GAMMA_GAMMA_BS_B_STEP_2_gamma_bs_b_step_7(data)                         (0x7F000000&((data)<<24))
#define  GAMMA_GAMMA_BS_B_STEP_2_gamma_bs_b_step_6(data)                         (0x007F0000&((data)<<16))
#define  GAMMA_GAMMA_BS_B_STEP_2_gamma_bs_b_step_5(data)                         (0x00007F00&((data)<<8))
#define  GAMMA_GAMMA_BS_B_STEP_2_gamma_bs_b_step_4(data)                         (0x0000007F&(data))
#define  GAMMA_GAMMA_BS_B_STEP_2_get_gamma_bs_b_step_7(data)                     ((0x7F000000&(data))>>24)
#define  GAMMA_GAMMA_BS_B_STEP_2_get_gamma_bs_b_step_6(data)                     ((0x007F0000&(data))>>16)
#define  GAMMA_GAMMA_BS_B_STEP_2_get_gamma_bs_b_step_5(data)                     ((0x00007F00&(data))>>8)
#define  GAMMA_GAMMA_BS_B_STEP_2_get_gamma_bs_b_step_4(data)                     (0x0000007F&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======GAMMA register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  gamma_tab_index:12;
        RBus_UInt32  gamma_tab_d0:8;
        RBus_UInt32  gamma_tab_d1:8;
    };
}gamma_gamma_port_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  gamma_tab_addr:9;
        RBus_UInt32  res2:7;
        RBus_UInt32  gamma_ax_rw_sel:2;
        RBus_UInt32  res3:1;
        RBus_UInt32  gamma_ax_ch_sel:2;
        RBus_UInt32  gamma_fifo_empty:1;
        RBus_UInt32  gamma_fifo_full:1;
        RBus_UInt32  gamma_wr_error:1;
        RBus_UInt32  dummy1802c104_0:1;
    };
}gamma_gamma_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  gamma_m_tab_sel:2;
        RBus_UInt32  dummy1802c108_5_0:6;
    };
}gamma_gamma_ctrl_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  gamma_msb_d0_r:3;
        RBus_UInt32  res2:5;
        RBus_UInt32  gamma_msb_d0_g:3;
        RBus_UInt32  res3:5;
        RBus_UInt32  gamma_msb_d0_b:3;
    };
}gamma_gamma_ctrl_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  ls:1;
        RBus_UInt32  rme:1;
        RBus_UInt32  rm:4;
    };
}gamma_gamma_srgb_bist_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  inv_gamma_r_drf_bist_fail:1;
        RBus_UInt32  inv_gamma_g_drf_bist_fail:1;
        RBus_UInt32  inv_gamma_b_drf_bist_fail:1;
        RBus_UInt32  srgb_r_drf_bist_fail:1;
        RBus_UInt32  srgb_g_drf_bist_fail:1;
        RBus_UInt32  srgb_b_drf_bist_fail:1;
        RBus_UInt32  gamma_r_drf_bist_fail:1;
        RBus_UInt32  gamma_g_drf_bist_fail:1;
        RBus_UInt32  gamma_b_drf_bist_fail:1;
        RBus_UInt32  inv_gamma_r_bist_fail:1;
        RBus_UInt32  inv_gamma_g_bist_fail:1;
        RBus_UInt32  inv_gamma_b_bist_fail:1;
        RBus_UInt32  srgb_r_bist_fail:1;
        RBus_UInt32  srgb_g_bist_fail:1;
        RBus_UInt32  srgb_b_bist_fail:1;
        RBus_UInt32  gamma_r_bist_fail:1;
        RBus_UInt32  gamma_g_bist_fail:1;
        RBus_UInt32  gamma_b_bist_fail:1;
    };
}gamma_gamma_srgb_bist_ctrl_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gamma_adapt_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  sat_thl:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  sat_thl_mul:12;
    };
}gamma_adapt_gamma_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802c130_31_22:10;
        RBus_UInt32  gamma_bs_r_gain:2;
        RBus_UInt32  gamma_bs_g_gain:2;
        RBus_UInt32  gamma_bs_b_gain:2;
        RBus_UInt32  gamma_bs_sat_thd:8;
        RBus_UInt32  res1:6;
        RBus_UInt32  gamma_m_bs_en:1;
        RBus_UInt32  res2:1;
    };
}gamma_gamma_bs_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gamma_bs_y3:8;
        RBus_UInt32  gamma_bs_y2:8;
        RBus_UInt32  gamma_bs_y1:8;
        RBus_UInt32  gamma_bs_y0:8;
    };
}gamma_gamma_bs_y_index_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gamma_bs_y7:8;
        RBus_UInt32  gamma_bs_y6:8;
        RBus_UInt32  gamma_bs_y5:8;
        RBus_UInt32  gamma_bs_y4:8;
    };
}gamma_gamma_bs_y_index_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  gamma_bs_r_ofst_2:9;
        RBus_UInt32  gamma_bs_r_ofst_1:9;
        RBus_UInt32  gamma_bs_r_ofst_0:9;
    };
}gamma_gamma_bs_r_offset_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  gamma_bs_r_ofst_5:9;
        RBus_UInt32  gamma_bs_r_ofst_4:9;
        RBus_UInt32  gamma_bs_r_ofst_3:9;
    };
}gamma_gamma_bs_r_offset_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  gamma_bs_r_ofst_7:9;
        RBus_UInt32  gamma_bs_r_ofst_6:9;
    };
}gamma_gamma_bs_r_offset_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  gamma_bs_g_ofst_2:9;
        RBus_UInt32  gamma_bs_g_ofst_1:9;
        RBus_UInt32  gamma_bs_g_ofst_0:9;
    };
}gamma_gamma_bs_g_offset_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  gamma_bs_g_ofst_5:9;
        RBus_UInt32  gamma_bs_g_ofst_4:9;
        RBus_UInt32  gamma_bs_g_ofst_3:9;
    };
}gamma_gamma_bs_g_offset_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  gamma_bs_g_ofst_7:9;
        RBus_UInt32  gamma_bs_g_ofst_6:9;
    };
}gamma_gamma_bs_g_offset_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  gamma_bs_b_ofst_2:9;
        RBus_UInt32  gamma_bs_b_ofst_1:9;
        RBus_UInt32  gamma_bs_b_ofst_0:9;
    };
}gamma_gamma_bs_b_offset_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  gamma_bs_b_ofst_5:9;
        RBus_UInt32  gamma_bs_b_ofst_4:9;
        RBus_UInt32  gamma_bs_b_ofst_3:9;
    };
}gamma_gamma_bs_b_offset_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  gamma_bs_b_ofst_7:9;
        RBus_UInt32  gamma_bs_b_ofst_6:9;
    };
}gamma_gamma_bs_b_offset_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  gamma_bs_r_step_3:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  gamma_bs_r_step_2:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  gamma_bs_r_step_1:7;
        RBus_UInt32  res4:1;
        RBus_UInt32  gamma_bs_r_step_0:7;
    };
}gamma_gamma_bs_r_step_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  gamma_bs_r_step_7:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  gamma_bs_r_step_6:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  gamma_bs_r_step_5:7;
        RBus_UInt32  res4:1;
        RBus_UInt32  gamma_bs_r_step_4:7;
    };
}gamma_gamma_bs_r_step_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  gamma_bs_g_step_3:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  gamma_bs_g_step_2:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  gamma_bs_g_step_1:7;
        RBus_UInt32  res4:1;
        RBus_UInt32  gamma_bs_g_step_0:7;
    };
}gamma_gamma_bs_g_step_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  gamma_bs_g_step_7:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  gamma_bs_g_step_6:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  gamma_bs_g_step_5:7;
        RBus_UInt32  res4:1;
        RBus_UInt32  gamma_bs_g_step_4:7;
    };
}gamma_gamma_bs_g_step_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  gamma_bs_b_step_3:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  gamma_bs_b_step_2:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  gamma_bs_b_step_1:7;
        RBus_UInt32  res4:1;
        RBus_UInt32  gamma_bs_b_step_0:7;
    };
}gamma_gamma_bs_b_step_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  gamma_bs_b_step_7:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  gamma_bs_b_step_6:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  gamma_bs_b_step_5:7;
        RBus_UInt32  res4:1;
        RBus_UInt32  gamma_bs_b_step_4:7;
    };
}gamma_gamma_bs_b_step_2_RBUS;

#else //apply LITTLE_ENDIAN

//======GAMMA register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gamma_tab_d1:8;
        RBus_UInt32  gamma_tab_d0:8;
        RBus_UInt32  gamma_tab_index:12;
        RBus_UInt32  res1:4;
    };
}gamma_gamma_port_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802c104_0:1;
        RBus_UInt32  gamma_wr_error:1;
        RBus_UInt32  gamma_fifo_full:1;
        RBus_UInt32  gamma_fifo_empty:1;
        RBus_UInt32  gamma_ax_ch_sel:2;
        RBus_UInt32  res1:1;
        RBus_UInt32  gamma_ax_rw_sel:2;
        RBus_UInt32  res2:7;
        RBus_UInt32  gamma_tab_addr:9;
        RBus_UInt32  res3:7;
    };
}gamma_gamma_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802c108_5_0:6;
        RBus_UInt32  gamma_m_tab_sel:2;
        RBus_UInt32  res1:24;
    };
}gamma_gamma_ctrl_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gamma_msb_d0_b:3;
        RBus_UInt32  res1:5;
        RBus_UInt32  gamma_msb_d0_g:3;
        RBus_UInt32  res2:5;
        RBus_UInt32  gamma_msb_d0_r:3;
        RBus_UInt32  res3:13;
    };
}gamma_gamma_ctrl_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rm:4;
        RBus_UInt32  rme:1;
        RBus_UInt32  ls:1;
        RBus_UInt32  res1:26;
    };
}gamma_gamma_srgb_bist_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gamma_b_bist_fail:1;
        RBus_UInt32  gamma_g_bist_fail:1;
        RBus_UInt32  gamma_r_bist_fail:1;
        RBus_UInt32  srgb_b_bist_fail:1;
        RBus_UInt32  srgb_g_bist_fail:1;
        RBus_UInt32  srgb_r_bist_fail:1;
        RBus_UInt32  inv_gamma_b_bist_fail:1;
        RBus_UInt32  inv_gamma_g_bist_fail:1;
        RBus_UInt32  inv_gamma_r_bist_fail:1;
        RBus_UInt32  gamma_b_drf_bist_fail:1;
        RBus_UInt32  gamma_g_drf_bist_fail:1;
        RBus_UInt32  gamma_r_drf_bist_fail:1;
        RBus_UInt32  srgb_b_drf_bist_fail:1;
        RBus_UInt32  srgb_g_drf_bist_fail:1;
        RBus_UInt32  srgb_r_drf_bist_fail:1;
        RBus_UInt32  inv_gamma_b_drf_bist_fail:1;
        RBus_UInt32  inv_gamma_g_drf_bist_fail:1;
        RBus_UInt32  inv_gamma_r_drf_bist_fail:1;
        RBus_UInt32  res1:14;
    };
}gamma_gamma_srgb_bist_ctrl_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sat_thl_mul:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  sat_thl:12;
        RBus_UInt32  res2:3;
        RBus_UInt32  gamma_adapt_en:1;
    };
}gamma_adapt_gamma_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  gamma_m_bs_en:1;
        RBus_UInt32  res2:6;
        RBus_UInt32  gamma_bs_sat_thd:8;
        RBus_UInt32  gamma_bs_b_gain:2;
        RBus_UInt32  gamma_bs_g_gain:2;
        RBus_UInt32  gamma_bs_r_gain:2;
        RBus_UInt32  dummy1802c130_31_22:10;
    };
}gamma_gamma_bs_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gamma_bs_y0:8;
        RBus_UInt32  gamma_bs_y1:8;
        RBus_UInt32  gamma_bs_y2:8;
        RBus_UInt32  gamma_bs_y3:8;
    };
}gamma_gamma_bs_y_index_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gamma_bs_y4:8;
        RBus_UInt32  gamma_bs_y5:8;
        RBus_UInt32  gamma_bs_y6:8;
        RBus_UInt32  gamma_bs_y7:8;
    };
}gamma_gamma_bs_y_index_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gamma_bs_r_ofst_0:9;
        RBus_UInt32  gamma_bs_r_ofst_1:9;
        RBus_UInt32  gamma_bs_r_ofst_2:9;
        RBus_UInt32  res1:5;
    };
}gamma_gamma_bs_r_offset_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gamma_bs_r_ofst_3:9;
        RBus_UInt32  gamma_bs_r_ofst_4:9;
        RBus_UInt32  gamma_bs_r_ofst_5:9;
        RBus_UInt32  res1:5;
    };
}gamma_gamma_bs_r_offset_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gamma_bs_r_ofst_6:9;
        RBus_UInt32  gamma_bs_r_ofst_7:9;
        RBus_UInt32  res1:14;
    };
}gamma_gamma_bs_r_offset_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gamma_bs_g_ofst_0:9;
        RBus_UInt32  gamma_bs_g_ofst_1:9;
        RBus_UInt32  gamma_bs_g_ofst_2:9;
        RBus_UInt32  res1:5;
    };
}gamma_gamma_bs_g_offset_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gamma_bs_g_ofst_3:9;
        RBus_UInt32  gamma_bs_g_ofst_4:9;
        RBus_UInt32  gamma_bs_g_ofst_5:9;
        RBus_UInt32  res1:5;
    };
}gamma_gamma_bs_g_offset_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gamma_bs_g_ofst_6:9;
        RBus_UInt32  gamma_bs_g_ofst_7:9;
        RBus_UInt32  res1:14;
    };
}gamma_gamma_bs_g_offset_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gamma_bs_b_ofst_0:9;
        RBus_UInt32  gamma_bs_b_ofst_1:9;
        RBus_UInt32  gamma_bs_b_ofst_2:9;
        RBus_UInt32  res1:5;
    };
}gamma_gamma_bs_b_offset_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gamma_bs_b_ofst_3:9;
        RBus_UInt32  gamma_bs_b_ofst_4:9;
        RBus_UInt32  gamma_bs_b_ofst_5:9;
        RBus_UInt32  res1:5;
    };
}gamma_gamma_bs_b_offset_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gamma_bs_b_ofst_6:9;
        RBus_UInt32  gamma_bs_b_ofst_7:9;
        RBus_UInt32  res1:14;
    };
}gamma_gamma_bs_b_offset_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gamma_bs_r_step_0:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  gamma_bs_r_step_1:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  gamma_bs_r_step_2:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  gamma_bs_r_step_3:7;
        RBus_UInt32  res4:1;
    };
}gamma_gamma_bs_r_step_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gamma_bs_r_step_4:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  gamma_bs_r_step_5:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  gamma_bs_r_step_6:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  gamma_bs_r_step_7:7;
        RBus_UInt32  res4:1;
    };
}gamma_gamma_bs_r_step_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gamma_bs_g_step_0:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  gamma_bs_g_step_1:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  gamma_bs_g_step_2:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  gamma_bs_g_step_3:7;
        RBus_UInt32  res4:1;
    };
}gamma_gamma_bs_g_step_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gamma_bs_g_step_4:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  gamma_bs_g_step_5:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  gamma_bs_g_step_6:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  gamma_bs_g_step_7:7;
        RBus_UInt32  res4:1;
    };
}gamma_gamma_bs_g_step_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gamma_bs_b_step_0:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  gamma_bs_b_step_1:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  gamma_bs_b_step_2:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  gamma_bs_b_step_3:7;
        RBus_UInt32  res4:1;
    };
}gamma_gamma_bs_b_step_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gamma_bs_b_step_4:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  gamma_bs_b_step_5:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  gamma_bs_b_step_6:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  gamma_bs_b_step_7:7;
        RBus_UInt32  res4:1;
    };
}gamma_gamma_bs_b_step_2_RBUS;




#endif 


#endif 
