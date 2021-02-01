/**
* @file MacArthur5-DesignSpec-I-Domain_Edge_Smooth
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_IEDGE_SMOOTH_REG_H_
#define _RBUS_IEDGE_SMOOTH_REG_H_

#include "rbus_types.h"



//  IEDGE_SMOOTH Register Address
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL                                         0x18025100
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL_reg_addr                                "0xB8025100"
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL_reg                                     0xB8025100
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL_inst_addr                               "0x0000"
#define  set_IEDGE_SMOOTH_EdgeSmooth_EX_CTRL_reg(data)                           (*((volatile unsigned int*)IEDGE_SMOOTH_EdgeSmooth_EX_CTRL_reg)=data)
#define  get_IEDGE_SMOOTH_EdgeSmooth_EX_CTRL_reg                                 (*((volatile unsigned int*)IEDGE_SMOOTH_EdgeSmooth_EX_CTRL_reg))
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL_dummy_25_18_shift                       (18)
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL_tst_en_shift                            (17)
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL_lbuf_disable_shift                      (16)
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL_debug_mode_shift                        (12)
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL_edgemode_shift                          (11)
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL_lbuf_linemode_shift                     (9)
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL_debug_en_shift                          (8)
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL_crct_5linemode_shift                    (7)
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL_chaos_5linemode_shift                   (6)
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL_lpf_5tapmode_shift                      (5)
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL_edge_en_shift                           (4)
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL_chaos_en_shift                          (3)
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL_crct_en_shift                           (2)
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL_t2df_en_shift                           (1)
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL_edgesmoothex_en_shift                   (0)
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL_dummy_25_18_mask                        (0x03FC0000)
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL_tst_en_mask                             (0x00020000)
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL_lbuf_disable_mask                       (0x00010000)
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL_debug_mode_mask                         (0x0000F000)
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL_edgemode_mask                           (0x00000800)
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL_lbuf_linemode_mask                      (0x00000600)
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL_debug_en_mask                           (0x00000100)
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL_crct_5linemode_mask                     (0x00000080)
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL_chaos_5linemode_mask                    (0x00000040)
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL_lpf_5tapmode_mask                       (0x00000020)
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL_edge_en_mask                            (0x00000010)
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL_chaos_en_mask                           (0x00000008)
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL_crct_en_mask                            (0x00000004)
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL_t2df_en_mask                            (0x00000002)
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL_edgesmoothex_en_mask                    (0x00000001)
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL_dummy_25_18(data)                       (0x03FC0000&((data)<<18))
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL_tst_en(data)                            (0x00020000&((data)<<17))
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL_lbuf_disable(data)                      (0x00010000&((data)<<16))
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL_debug_mode(data)                        (0x0000F000&((data)<<12))
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL_edgemode(data)                          (0x00000800&((data)<<11))
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL_lbuf_linemode(data)                     (0x00000600&((data)<<9))
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL_debug_en(data)                          (0x00000100&((data)<<8))
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL_crct_5linemode(data)                    (0x00000080&((data)<<7))
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL_chaos_5linemode(data)                   (0x00000040&((data)<<6))
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL_lpf_5tapmode(data)                      (0x00000020&((data)<<5))
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL_edge_en(data)                           (0x00000010&((data)<<4))
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL_chaos_en(data)                          (0x00000008&((data)<<3))
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL_crct_en(data)                           (0x00000004&((data)<<2))
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL_t2df_en(data)                           (0x00000002&((data)<<1))
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL_edgesmoothex_en(data)                   (0x00000001&(data))
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL_get_dummy_25_18(data)                   ((0x03FC0000&(data))>>18)
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL_get_tst_en(data)                        ((0x00020000&(data))>>17)
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL_get_lbuf_disable(data)                  ((0x00010000&(data))>>16)
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL_get_debug_mode(data)                    ((0x0000F000&(data))>>12)
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL_get_edgemode(data)                      ((0x00000800&(data))>>11)
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL_get_lbuf_linemode(data)                 ((0x00000600&(data))>>9)
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL_get_debug_en(data)                      ((0x00000100&(data))>>8)
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL_get_crct_5linemode(data)                ((0x00000080&(data))>>7)
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL_get_chaos_5linemode(data)               ((0x00000040&(data))>>6)
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL_get_lpf_5tapmode(data)                  ((0x00000020&(data))>>5)
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL_get_edge_en(data)                       ((0x00000010&(data))>>4)
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL_get_chaos_en(data)                      ((0x00000008&(data))>>3)
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL_get_crct_en(data)                       ((0x00000004&(data))>>2)
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL_get_t2df_en(data)                       ((0x00000002&(data))>>1)
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL_get_edgesmoothex_en(data)               (0x00000001&(data))

#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL2                                        0x18025104
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL2_reg_addr                               "0xB8025104"
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL2_reg                                    0xB8025104
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL2_inst_addr                              "0x0001"
#define  set_IEDGE_SMOOTH_EdgeSmooth_EX_CTRL2_reg(data)                          (*((volatile unsigned int*)IEDGE_SMOOTH_EdgeSmooth_EX_CTRL2_reg)=data)
#define  get_IEDGE_SMOOTH_EdgeSmooth_EX_CTRL2_reg                                (*((volatile unsigned int*)IEDGE_SMOOTH_EdgeSmooth_EX_CTRL2_reg))
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL2_chaos_diffth_shift                     (24)
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL2_chaos_mode_shift                       (16)
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL2_t2df_stepbit_shift                     (12)
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL2_t2df_upbnd_shift                       (0)
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL2_chaos_diffth_mask                      (0xFF000000)
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL2_chaos_mode_mask                        (0x00030000)
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL2_t2df_stepbit_mask                      (0x0000F000)
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL2_t2df_upbnd_mask                        (0x000003FF)
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL2_chaos_diffth(data)                     (0xFF000000&((data)<<24))
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL2_chaos_mode(data)                       (0x00030000&((data)<<16))
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL2_t2df_stepbit(data)                     (0x0000F000&((data)<<12))
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL2_t2df_upbnd(data)                       (0x000003FF&(data))
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL2_get_chaos_diffth(data)                 ((0xFF000000&(data))>>24)
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL2_get_chaos_mode(data)                   ((0x00030000&(data))>>16)
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL2_get_t2df_stepbit(data)                 ((0x0000F000&(data))>>12)
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL2_get_t2df_upbnd(data)                   (0x000003FF&(data))

#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL3                                        0x18025108
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL3_reg_addr                               "0xB8025108"
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL3_reg                                    0xB8025108
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL3_inst_addr                              "0x0002"
#define  set_IEDGE_SMOOTH_EdgeSmooth_EX_CTRL3_reg(data)                          (*((volatile unsigned int*)IEDGE_SMOOTH_EdgeSmooth_EX_CTRL3_reg)=data)
#define  get_IEDGE_SMOOTH_EdgeSmooth_EX_CTRL3_reg                                (*((volatile unsigned int*)IEDGE_SMOOTH_EdgeSmooth_EX_CTRL3_reg))
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL3_chaos_lwbnd_shift                      (16)
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL3_edge_stepbit_shift                     (12)
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL3_edge_upbnd_shift                       (0)
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL3_chaos_lwbnd_mask                       (0x001F0000)
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL3_edge_stepbit_mask                      (0x0000F000)
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL3_edge_upbnd_mask                        (0x000003FF)
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL3_chaos_lwbnd(data)                      (0x001F0000&((data)<<16))
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL3_edge_stepbit(data)                     (0x0000F000&((data)<<12))
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL3_edge_upbnd(data)                       (0x000003FF&(data))
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL3_get_chaos_lwbnd(data)                  ((0x001F0000&(data))>>16)
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL3_get_edge_stepbit(data)                 ((0x0000F000&(data))>>12)
#define  IEDGE_SMOOTH_EdgeSmooth_EX_CTRL3_get_edge_upbnd(data)                   (0x000003FF&(data))

#define  IEDGE_SMOOTH_MIXer_ctrl                                                 0x1802510C
#define  IEDGE_SMOOTH_MIXer_ctrl_reg_addr                                        "0xB802510C"
#define  IEDGE_SMOOTH_MIXer_ctrl_reg                                             0xB802510C
#define  IEDGE_SMOOTH_MIXer_ctrl_inst_addr                                       "0x0003"
#define  set_IEDGE_SMOOTH_MIXer_ctrl_reg(data)                                   (*((volatile unsigned int*)IEDGE_SMOOTH_MIXer_ctrl_reg)=data)
#define  get_IEDGE_SMOOTH_MIXer_ctrl_reg                                         (*((volatile unsigned int*)IEDGE_SMOOTH_MIXer_ctrl_reg))
#define  IEDGE_SMOOTH_MIXer_ctrl_iedge_nr_sel_shift                              (8)
#define  IEDGE_SMOOTH_MIXer_ctrl_iedge_mixer_weight_shift                        (4)
#define  IEDGE_SMOOTH_MIXer_ctrl_iedge_nr_sel_mask                               (0x00000100)
#define  IEDGE_SMOOTH_MIXer_ctrl_iedge_mixer_weight_mask                         (0x000000F0)
#define  IEDGE_SMOOTH_MIXer_ctrl_iedge_nr_sel(data)                              (0x00000100&((data)<<8))
#define  IEDGE_SMOOTH_MIXer_ctrl_iedge_mixer_weight(data)                        (0x000000F0&((data)<<4))
#define  IEDGE_SMOOTH_MIXer_ctrl_get_iedge_nr_sel(data)                          ((0x00000100&(data))>>8)
#define  IEDGE_SMOOTH_MIXer_ctrl_get_iedge_mixer_weight(data)                    ((0x000000F0&(data))>>4)

#define  IEDGE_SMOOTH_EdgeSmooth_Extension                                       0x18025110
#define  IEDGE_SMOOTH_EdgeSmooth_Extension_reg_addr                              "0xB8025110"
#define  IEDGE_SMOOTH_EdgeSmooth_Extension_reg                                   0xB8025110
#define  IEDGE_SMOOTH_EdgeSmooth_Extension_inst_addr                             "0x0004"
#define  set_IEDGE_SMOOTH_EdgeSmooth_Extension_reg(data)                         (*((volatile unsigned int*)IEDGE_SMOOTH_EdgeSmooth_Extension_reg)=data)
#define  get_IEDGE_SMOOTH_EdgeSmooth_Extension_reg                               (*((volatile unsigned int*)IEDGE_SMOOTH_EdgeSmooth_Extension_reg))
#define  IEDGE_SMOOTH_EdgeSmooth_Extension_ext_range_en_shift                    (31)
#define  IEDGE_SMOOTH_EdgeSmooth_Extension_ext_uvrange_shift                     (18)
#define  IEDGE_SMOOTH_EdgeSmooth_Extension_ext_range_shift                       (16)
#define  IEDGE_SMOOTH_EdgeSmooth_Extension_ext_uvdiff_stepbit_shift              (12)
#define  IEDGE_SMOOTH_EdgeSmooth_Extension_ext_uvdiff_upbnd_shift                (0)
#define  IEDGE_SMOOTH_EdgeSmooth_Extension_ext_range_en_mask                     (0x80000000)
#define  IEDGE_SMOOTH_EdgeSmooth_Extension_ext_uvrange_mask                      (0x000C0000)
#define  IEDGE_SMOOTH_EdgeSmooth_Extension_ext_range_mask                        (0x00030000)
#define  IEDGE_SMOOTH_EdgeSmooth_Extension_ext_uvdiff_stepbit_mask               (0x0000F000)
#define  IEDGE_SMOOTH_EdgeSmooth_Extension_ext_uvdiff_upbnd_mask                 (0x000003FF)
#define  IEDGE_SMOOTH_EdgeSmooth_Extension_ext_range_en(data)                    (0x80000000&((data)<<31))
#define  IEDGE_SMOOTH_EdgeSmooth_Extension_ext_uvrange(data)                     (0x000C0000&((data)<<18))
#define  IEDGE_SMOOTH_EdgeSmooth_Extension_ext_range(data)                       (0x00030000&((data)<<16))
#define  IEDGE_SMOOTH_EdgeSmooth_Extension_ext_uvdiff_stepbit(data)              (0x0000F000&((data)<<12))
#define  IEDGE_SMOOTH_EdgeSmooth_Extension_ext_uvdiff_upbnd(data)                (0x000003FF&(data))
#define  IEDGE_SMOOTH_EdgeSmooth_Extension_get_ext_range_en(data)                ((0x80000000&(data))>>31)
#define  IEDGE_SMOOTH_EdgeSmooth_Extension_get_ext_uvrange(data)                 ((0x000C0000&(data))>>18)
#define  IEDGE_SMOOTH_EdgeSmooth_Extension_get_ext_range(data)                   ((0x00030000&(data))>>16)
#define  IEDGE_SMOOTH_EdgeSmooth_Extension_get_ext_uvdiff_stepbit(data)          ((0x0000F000&(data))>>12)
#define  IEDGE_SMOOTH_EdgeSmooth_Extension_get_ext_uvdiff_upbnd(data)            (0x000003FF&(data))

#define  IEDGE_SMOOTH_EdgeSmooth_Ext_angle                                       0x1802511C
#define  IEDGE_SMOOTH_EdgeSmooth_Ext_angle_reg_addr                              "0xB802511C"
#define  IEDGE_SMOOTH_EdgeSmooth_Ext_angle_reg                                   0xB802511C
#define  IEDGE_SMOOTH_EdgeSmooth_Ext_angle_inst_addr                             "0x0005"
#define  set_IEDGE_SMOOTH_EdgeSmooth_Ext_angle_reg(data)                         (*((volatile unsigned int*)IEDGE_SMOOTH_EdgeSmooth_Ext_angle_reg)=data)
#define  get_IEDGE_SMOOTH_EdgeSmooth_Ext_angle_reg                               (*((volatile unsigned int*)IEDGE_SMOOTH_EdgeSmooth_Ext_angle_reg))
#define  IEDGE_SMOOTH_EdgeSmooth_Ext_angle_ext_angle_crc_en_shift                (31)
#define  IEDGE_SMOOTH_EdgeSmooth_Ext_angle_ext_angle_en_shift                    (30)
#define  IEDGE_SMOOTH_EdgeSmooth_Ext_angle_ext_angle_rl_thd_shift                (12)
#define  IEDGE_SMOOTH_EdgeSmooth_Ext_angle_ext_angle_maxdiff_thd_shift           (0)
#define  IEDGE_SMOOTH_EdgeSmooth_Ext_angle_ext_angle_crc_en_mask                 (0x80000000)
#define  IEDGE_SMOOTH_EdgeSmooth_Ext_angle_ext_angle_en_mask                     (0x40000000)
#define  IEDGE_SMOOTH_EdgeSmooth_Ext_angle_ext_angle_rl_thd_mask                 (0x0003F000)
#define  IEDGE_SMOOTH_EdgeSmooth_Ext_angle_ext_angle_maxdiff_thd_mask            (0x000003FF)
#define  IEDGE_SMOOTH_EdgeSmooth_Ext_angle_ext_angle_crc_en(data)                (0x80000000&((data)<<31))
#define  IEDGE_SMOOTH_EdgeSmooth_Ext_angle_ext_angle_en(data)                    (0x40000000&((data)<<30))
#define  IEDGE_SMOOTH_EdgeSmooth_Ext_angle_ext_angle_rl_thd(data)                (0x0003F000&((data)<<12))
#define  IEDGE_SMOOTH_EdgeSmooth_Ext_angle_ext_angle_maxdiff_thd(data)           (0x000003FF&(data))
#define  IEDGE_SMOOTH_EdgeSmooth_Ext_angle_get_ext_angle_crc_en(data)            ((0x80000000&(data))>>31)
#define  IEDGE_SMOOTH_EdgeSmooth_Ext_angle_get_ext_angle_en(data)                ((0x40000000&(data))>>30)
#define  IEDGE_SMOOTH_EdgeSmooth_Ext_angle_get_ext_angle_rl_thd(data)            ((0x0003F000&(data))>>12)
#define  IEDGE_SMOOTH_EdgeSmooth_Ext_angle_get_ext_angle_maxdiff_thd(data)       (0x000003FF&(data))

#define  IEDGE_SMOOTH_demo_window_ctrl0                                          0x18025120
#define  IEDGE_SMOOTH_demo_window_ctrl0_reg_addr                                 "0xB8025120"
#define  IEDGE_SMOOTH_demo_window_ctrl0_reg                                      0xB8025120
#define  IEDGE_SMOOTH_demo_window_ctrl0_inst_addr                                "0x0006"
#define  set_IEDGE_SMOOTH_demo_window_ctrl0_reg(data)                            (*((volatile unsigned int*)IEDGE_SMOOTH_demo_window_ctrl0_reg)=data)
#define  get_IEDGE_SMOOTH_demo_window_ctrl0_reg                                  (*((volatile unsigned int*)IEDGE_SMOOTH_demo_window_ctrl0_reg))
#define  IEDGE_SMOOTH_demo_window_ctrl0_reg_demo_en_shift                        (31)
#define  IEDGE_SMOOTH_demo_window_ctrl0_reg_demo_inv_shift                       (30)
#define  IEDGE_SMOOTH_demo_window_ctrl0_reg_h_end_shift                          (12)
#define  IEDGE_SMOOTH_demo_window_ctrl0_reg_h_start_shift                        (0)
#define  IEDGE_SMOOTH_demo_window_ctrl0_reg_demo_en_mask                         (0x80000000)
#define  IEDGE_SMOOTH_demo_window_ctrl0_reg_demo_inv_mask                        (0x40000000)
#define  IEDGE_SMOOTH_demo_window_ctrl0_reg_h_end_mask                           (0x00FFF000)
#define  IEDGE_SMOOTH_demo_window_ctrl0_reg_h_start_mask                         (0x00000FFF)
#define  IEDGE_SMOOTH_demo_window_ctrl0_reg_demo_en(data)                        (0x80000000&((data)<<31))
#define  IEDGE_SMOOTH_demo_window_ctrl0_reg_demo_inv(data)                       (0x40000000&((data)<<30))
#define  IEDGE_SMOOTH_demo_window_ctrl0_reg_h_end(data)                          (0x00FFF000&((data)<<12))
#define  IEDGE_SMOOTH_demo_window_ctrl0_reg_h_start(data)                        (0x00000FFF&(data))
#define  IEDGE_SMOOTH_demo_window_ctrl0_get_reg_demo_en(data)                    ((0x80000000&(data))>>31)
#define  IEDGE_SMOOTH_demo_window_ctrl0_get_reg_demo_inv(data)                   ((0x40000000&(data))>>30)
#define  IEDGE_SMOOTH_demo_window_ctrl0_get_reg_h_end(data)                      ((0x00FFF000&(data))>>12)
#define  IEDGE_SMOOTH_demo_window_ctrl0_get_reg_h_start(data)                    (0x00000FFF&(data))

#define  IEDGE_SMOOTH_demo_window_ctrl1                                          0x18025124
#define  IEDGE_SMOOTH_demo_window_ctrl1_reg_addr                                 "0xB8025124"
#define  IEDGE_SMOOTH_demo_window_ctrl1_reg                                      0xB8025124
#define  IEDGE_SMOOTH_demo_window_ctrl1_inst_addr                                "0x0007"
#define  set_IEDGE_SMOOTH_demo_window_ctrl1_reg(data)                            (*((volatile unsigned int*)IEDGE_SMOOTH_demo_window_ctrl1_reg)=data)
#define  get_IEDGE_SMOOTH_demo_window_ctrl1_reg                                  (*((volatile unsigned int*)IEDGE_SMOOTH_demo_window_ctrl1_reg))
#define  IEDGE_SMOOTH_demo_window_ctrl1_reg_v_end_shift                          (12)
#define  IEDGE_SMOOTH_demo_window_ctrl1_reg_v_start_shift                        (0)
#define  IEDGE_SMOOTH_demo_window_ctrl1_reg_v_end_mask                           (0x00FFF000)
#define  IEDGE_SMOOTH_demo_window_ctrl1_reg_v_start_mask                         (0x00000FFF)
#define  IEDGE_SMOOTH_demo_window_ctrl1_reg_v_end(data)                          (0x00FFF000&((data)<<12))
#define  IEDGE_SMOOTH_demo_window_ctrl1_reg_v_start(data)                        (0x00000FFF&(data))
#define  IEDGE_SMOOTH_demo_window_ctrl1_get_reg_v_end(data)                      ((0x00FFF000&(data))>>12)
#define  IEDGE_SMOOTH_demo_window_ctrl1_get_reg_v_start(data)                    (0x00000FFF&(data))

#define  IEDGE_SMOOTH_prelpf_ctrl                                                0x18025128
#define  IEDGE_SMOOTH_prelpf_ctrl_reg_addr                                       "0xB8025128"
#define  IEDGE_SMOOTH_prelpf_ctrl_reg                                            0xB8025128
#define  IEDGE_SMOOTH_prelpf_ctrl_inst_addr                                      "0x0008"
#define  set_IEDGE_SMOOTH_prelpf_ctrl_reg(data)                                  (*((volatile unsigned int*)IEDGE_SMOOTH_prelpf_ctrl_reg)=data)
#define  get_IEDGE_SMOOTH_prelpf_ctrl_reg                                        (*((volatile unsigned int*)IEDGE_SMOOTH_prelpf_ctrl_reg))
#define  IEDGE_SMOOTH_prelpf_ctrl_prelpf_iedge2_sel_shift                        (31)
#define  IEDGE_SMOOTH_prelpf_ctrl_dummy_30_28_shift                              (28)
#define  IEDGE_SMOOTH_prelpf_ctrl_prelpf_iedge1_sel_shift                        (16)
#define  IEDGE_SMOOTH_prelpf_ctrl_prelpf_snr_sel_shift                           (0)
#define  IEDGE_SMOOTH_prelpf_ctrl_prelpf_iedge2_sel_mask                         (0x80000000)
#define  IEDGE_SMOOTH_prelpf_ctrl_dummy_30_28_mask                               (0x70000000)
#define  IEDGE_SMOOTH_prelpf_ctrl_prelpf_iedge1_sel_mask                         (0x000F0000)
#define  IEDGE_SMOOTH_prelpf_ctrl_prelpf_snr_sel_mask                            (0x0000000F)
#define  IEDGE_SMOOTH_prelpf_ctrl_prelpf_iedge2_sel(data)                        (0x80000000&((data)<<31))
#define  IEDGE_SMOOTH_prelpf_ctrl_dummy_30_28(data)                              (0x70000000&((data)<<28))
#define  IEDGE_SMOOTH_prelpf_ctrl_prelpf_iedge1_sel(data)                        (0x000F0000&((data)<<16))
#define  IEDGE_SMOOTH_prelpf_ctrl_prelpf_snr_sel(data)                           (0x0000000F&(data))
#define  IEDGE_SMOOTH_prelpf_ctrl_get_prelpf_iedge2_sel(data)                    ((0x80000000&(data))>>31)
#define  IEDGE_SMOOTH_prelpf_ctrl_get_dummy_30_28(data)                          ((0x70000000&(data))>>28)
#define  IEDGE_SMOOTH_prelpf_ctrl_get_prelpf_iedge1_sel(data)                    ((0x000F0000&(data))>>16)
#define  IEDGE_SMOOTH_prelpf_ctrl_get_prelpf_snr_sel(data)                       (0x0000000F&(data))

#define  IEDGE_SMOOTH_DLTI2D_CTRL                                                0x1802512C
#define  IEDGE_SMOOTH_DLTI2D_CTRL_reg_addr                                       "0xB802512C"
#define  IEDGE_SMOOTH_DLTI2D_CTRL_reg                                            0xB802512C
#define  IEDGE_SMOOTH_DLTI2D_CTRL_inst_addr                                      "0x0009"
#define  set_IEDGE_SMOOTH_DLTI2D_CTRL_reg(data)                                  (*((volatile unsigned int*)IEDGE_SMOOTH_DLTI2D_CTRL_reg)=data)
#define  get_IEDGE_SMOOTH_DLTI2D_CTRL_reg                                        (*((volatile unsigned int*)IEDGE_SMOOTH_DLTI2D_CTRL_reg))
#define  IEDGE_SMOOTH_DLTI2D_CTRL_dlti2d_hlpf_type_shift                         (20)
#define  IEDGE_SMOOTH_DLTI2D_CTRL_dlti2d_vlpf_type_shift                         (16)
#define  IEDGE_SMOOTH_DLTI2D_CTRL_edsm_dlti_en_shift                             (15)
#define  IEDGE_SMOOTH_DLTI2D_CTRL_dlti2d_chaos_gain_shift                        (12)
#define  IEDGE_SMOOTH_DLTI2D_CTRL_dlti2d_maxmin_en_shift                         (8)
#define  IEDGE_SMOOTH_DLTI2D_CTRL_dlti2d_gain_shift                              (0)
#define  IEDGE_SMOOTH_DLTI2D_CTRL_dlti2d_hlpf_type_mask                          (0x00300000)
#define  IEDGE_SMOOTH_DLTI2D_CTRL_dlti2d_vlpf_type_mask                          (0x00030000)
#define  IEDGE_SMOOTH_DLTI2D_CTRL_edsm_dlti_en_mask                              (0x00008000)
#define  IEDGE_SMOOTH_DLTI2D_CTRL_dlti2d_chaos_gain_mask                         (0x00007000)
#define  IEDGE_SMOOTH_DLTI2D_CTRL_dlti2d_maxmin_en_mask                          (0x00000100)
#define  IEDGE_SMOOTH_DLTI2D_CTRL_dlti2d_gain_mask                               (0x0000003F)
#define  IEDGE_SMOOTH_DLTI2D_CTRL_dlti2d_hlpf_type(data)                         (0x00300000&((data)<<20))
#define  IEDGE_SMOOTH_DLTI2D_CTRL_dlti2d_vlpf_type(data)                         (0x00030000&((data)<<16))
#define  IEDGE_SMOOTH_DLTI2D_CTRL_edsm_dlti_en(data)                             (0x00008000&((data)<<15))
#define  IEDGE_SMOOTH_DLTI2D_CTRL_dlti2d_chaos_gain(data)                        (0x00007000&((data)<<12))
#define  IEDGE_SMOOTH_DLTI2D_CTRL_dlti2d_maxmin_en(data)                         (0x00000100&((data)<<8))
#define  IEDGE_SMOOTH_DLTI2D_CTRL_dlti2d_gain(data)                              (0x0000003F&(data))
#define  IEDGE_SMOOTH_DLTI2D_CTRL_get_dlti2d_hlpf_type(data)                     ((0x00300000&(data))>>20)
#define  IEDGE_SMOOTH_DLTI2D_CTRL_get_dlti2d_vlpf_type(data)                     ((0x00030000&(data))>>16)
#define  IEDGE_SMOOTH_DLTI2D_CTRL_get_edsm_dlti_en(data)                         ((0x00008000&(data))>>15)
#define  IEDGE_SMOOTH_DLTI2D_CTRL_get_dlti2d_chaos_gain(data)                    ((0x00007000&(data))>>12)
#define  IEDGE_SMOOTH_DLTI2D_CTRL_get_dlti2d_maxmin_en(data)                     ((0x00000100&(data))>>8)
#define  IEDGE_SMOOTH_DLTI2D_CTRL_get_dlti2d_gain(data)                          (0x0000003F&(data))

#define  IEDGE_SMOOTH_EdgeSmooth_Mess_Direction1                                 0x18025130
#define  IEDGE_SMOOTH_EdgeSmooth_Mess_Direction1_reg_addr                        "0xB8025130"
#define  IEDGE_SMOOTH_EdgeSmooth_Mess_Direction1_reg                             0xB8025130
#define  IEDGE_SMOOTH_EdgeSmooth_Mess_Direction1_inst_addr                       "0x000A"
#define  set_IEDGE_SMOOTH_EdgeSmooth_Mess_Direction1_reg(data)                   (*((volatile unsigned int*)IEDGE_SMOOTH_EdgeSmooth_Mess_Direction1_reg)=data)
#define  get_IEDGE_SMOOTH_EdgeSmooth_Mess_Direction1_reg                         (*((volatile unsigned int*)IEDGE_SMOOTH_EdgeSmooth_Mess_Direction1_reg))
#define  IEDGE_SMOOTH_EdgeSmooth_Mess_Direction1_mess_direction_en_shift         (31)
#define  IEDGE_SMOOTH_EdgeSmooth_Mess_Direction1_mess_4direction_thd_shift       (16)
#define  IEDGE_SMOOTH_EdgeSmooth_Mess_Direction1_mess_4direction_step_shift      (12)
#define  IEDGE_SMOOTH_EdgeSmooth_Mess_Direction1_mess_4direction_w0_shift        (8)
#define  IEDGE_SMOOTH_EdgeSmooth_Mess_Direction1_mess_4direction_w1_shift        (4)
#define  IEDGE_SMOOTH_EdgeSmooth_Mess_Direction1_mess_4direction_w2_shift        (0)
#define  IEDGE_SMOOTH_EdgeSmooth_Mess_Direction1_mess_direction_en_mask          (0x80000000)
#define  IEDGE_SMOOTH_EdgeSmooth_Mess_Direction1_mess_4direction_thd_mask        (0x000F0000)
#define  IEDGE_SMOOTH_EdgeSmooth_Mess_Direction1_mess_4direction_step_mask       (0x0000F000)
#define  IEDGE_SMOOTH_EdgeSmooth_Mess_Direction1_mess_4direction_w0_mask         (0x00000F00)
#define  IEDGE_SMOOTH_EdgeSmooth_Mess_Direction1_mess_4direction_w1_mask         (0x000000F0)
#define  IEDGE_SMOOTH_EdgeSmooth_Mess_Direction1_mess_4direction_w2_mask         (0x0000000F)
#define  IEDGE_SMOOTH_EdgeSmooth_Mess_Direction1_mess_direction_en(data)         (0x80000000&((data)<<31))
#define  IEDGE_SMOOTH_EdgeSmooth_Mess_Direction1_mess_4direction_thd(data)       (0x000F0000&((data)<<16))
#define  IEDGE_SMOOTH_EdgeSmooth_Mess_Direction1_mess_4direction_step(data)      (0x0000F000&((data)<<12))
#define  IEDGE_SMOOTH_EdgeSmooth_Mess_Direction1_mess_4direction_w0(data)        (0x00000F00&((data)<<8))
#define  IEDGE_SMOOTH_EdgeSmooth_Mess_Direction1_mess_4direction_w1(data)        (0x000000F0&((data)<<4))
#define  IEDGE_SMOOTH_EdgeSmooth_Mess_Direction1_mess_4direction_w2(data)        (0x0000000F&(data))
#define  IEDGE_SMOOTH_EdgeSmooth_Mess_Direction1_get_mess_direction_en(data)     ((0x80000000&(data))>>31)
#define  IEDGE_SMOOTH_EdgeSmooth_Mess_Direction1_get_mess_4direction_thd(data)   ((0x000F0000&(data))>>16)
#define  IEDGE_SMOOTH_EdgeSmooth_Mess_Direction1_get_mess_4direction_step(data)  ((0x0000F000&(data))>>12)
#define  IEDGE_SMOOTH_EdgeSmooth_Mess_Direction1_get_mess_4direction_w0(data)    ((0x00000F00&(data))>>8)
#define  IEDGE_SMOOTH_EdgeSmooth_Mess_Direction1_get_mess_4direction_w1(data)    ((0x000000F0&(data))>>4)
#define  IEDGE_SMOOTH_EdgeSmooth_Mess_Direction1_get_mess_4direction_w2(data)    (0x0000000F&(data))

#define  IEDGE_SMOOTH_EdgeSmooth_Mess_Direction2                                 0x18025134
#define  IEDGE_SMOOTH_EdgeSmooth_Mess_Direction2_reg_addr                        "0xB8025134"
#define  IEDGE_SMOOTH_EdgeSmooth_Mess_Direction2_reg                             0xB8025134
#define  IEDGE_SMOOTH_EdgeSmooth_Mess_Direction2_inst_addr                       "0x000B"
#define  set_IEDGE_SMOOTH_EdgeSmooth_Mess_Direction2_reg(data)                   (*((volatile unsigned int*)IEDGE_SMOOTH_EdgeSmooth_Mess_Direction2_reg)=data)
#define  get_IEDGE_SMOOTH_EdgeSmooth_Mess_Direction2_reg                         (*((volatile unsigned int*)IEDGE_SMOOTH_EdgeSmooth_Mess_Direction2_reg))
#define  IEDGE_SMOOTH_EdgeSmooth_Mess_Direction2_mess_8direction_thd_shift       (16)
#define  IEDGE_SMOOTH_EdgeSmooth_Mess_Direction2_mess_8direction_step_shift      (12)
#define  IEDGE_SMOOTH_EdgeSmooth_Mess_Direction2_mess_8direction_w0_shift        (8)
#define  IEDGE_SMOOTH_EdgeSmooth_Mess_Direction2_mess_8direction_w1_shift        (4)
#define  IEDGE_SMOOTH_EdgeSmooth_Mess_Direction2_mess_8direction_w2_shift        (0)
#define  IEDGE_SMOOTH_EdgeSmooth_Mess_Direction2_mess_8direction_thd_mask        (0x000F0000)
#define  IEDGE_SMOOTH_EdgeSmooth_Mess_Direction2_mess_8direction_step_mask       (0x0000F000)
#define  IEDGE_SMOOTH_EdgeSmooth_Mess_Direction2_mess_8direction_w0_mask         (0x00000F00)
#define  IEDGE_SMOOTH_EdgeSmooth_Mess_Direction2_mess_8direction_w1_mask         (0x000000F0)
#define  IEDGE_SMOOTH_EdgeSmooth_Mess_Direction2_mess_8direction_w2_mask         (0x0000000F)
#define  IEDGE_SMOOTH_EdgeSmooth_Mess_Direction2_mess_8direction_thd(data)       (0x000F0000&((data)<<16))
#define  IEDGE_SMOOTH_EdgeSmooth_Mess_Direction2_mess_8direction_step(data)      (0x0000F000&((data)<<12))
#define  IEDGE_SMOOTH_EdgeSmooth_Mess_Direction2_mess_8direction_w0(data)        (0x00000F00&((data)<<8))
#define  IEDGE_SMOOTH_EdgeSmooth_Mess_Direction2_mess_8direction_w1(data)        (0x000000F0&((data)<<4))
#define  IEDGE_SMOOTH_EdgeSmooth_Mess_Direction2_mess_8direction_w2(data)        (0x0000000F&(data))
#define  IEDGE_SMOOTH_EdgeSmooth_Mess_Direction2_get_mess_8direction_thd(data)   ((0x000F0000&(data))>>16)
#define  IEDGE_SMOOTH_EdgeSmooth_Mess_Direction2_get_mess_8direction_step(data)  ((0x0000F000&(data))>>12)
#define  IEDGE_SMOOTH_EdgeSmooth_Mess_Direction2_get_mess_8direction_w0(data)    ((0x00000F00&(data))>>8)
#define  IEDGE_SMOOTH_EdgeSmooth_Mess_Direction2_get_mess_8direction_w1(data)    ((0x000000F0&(data))>>4)
#define  IEDGE_SMOOTH_EdgeSmooth_Mess_Direction2_get_mess_8direction_w2(data)    (0x0000000F&(data))

#define  IEDGE_SMOOTH_EdgeSmooth_Blend_Weight_LPF                                0x18025138
#define  IEDGE_SMOOTH_EdgeSmooth_Blend_Weight_LPF_reg_addr                       "0xB8025138"
#define  IEDGE_SMOOTH_EdgeSmooth_Blend_Weight_LPF_reg                            0xB8025138
#define  IEDGE_SMOOTH_EdgeSmooth_Blend_Weight_LPF_inst_addr                      "0x000C"
#define  set_IEDGE_SMOOTH_EdgeSmooth_Blend_Weight_LPF_reg(data)                  (*((volatile unsigned int*)IEDGE_SMOOTH_EdgeSmooth_Blend_Weight_LPF_reg)=data)
#define  get_IEDGE_SMOOTH_EdgeSmooth_Blend_Weight_LPF_reg                        (*((volatile unsigned int*)IEDGE_SMOOTH_EdgeSmooth_Blend_Weight_LPF_reg))
#define  IEDGE_SMOOTH_EdgeSmooth_Blend_Weight_LPF_blend_weight_lpf_en_shift      (31)
#define  IEDGE_SMOOTH_EdgeSmooth_Blend_Weight_LPF_blend_weight_lpf_en_mask       (0x80000000)
#define  IEDGE_SMOOTH_EdgeSmooth_Blend_Weight_LPF_blend_weight_lpf_en(data)      (0x80000000&((data)<<31))
#define  IEDGE_SMOOTH_EdgeSmooth_Blend_Weight_LPF_get_blend_weight_lpf_en(data)  ((0x80000000&(data))>>31)

#define  IEDGE_SMOOTH_EdgeSmooth_Unstable_area                                   0x1802513C
#define  IEDGE_SMOOTH_EdgeSmooth_Unstable_area_reg_addr                          "0xB802513C"
#define  IEDGE_SMOOTH_EdgeSmooth_Unstable_area_reg                               0xB802513C
#define  IEDGE_SMOOTH_EdgeSmooth_Unstable_area_inst_addr                         "0x000D"
#define  set_IEDGE_SMOOTH_EdgeSmooth_Unstable_area_reg(data)                     (*((volatile unsigned int*)IEDGE_SMOOTH_EdgeSmooth_Unstable_area_reg)=data)
#define  get_IEDGE_SMOOTH_EdgeSmooth_Unstable_area_reg                           (*((volatile unsigned int*)IEDGE_SMOOTH_EdgeSmooth_Unstable_area_reg))
#define  IEDGE_SMOOTH_EdgeSmooth_Unstable_area_unstable_area_en_shift            (31)
#define  IEDGE_SMOOTH_EdgeSmooth_Unstable_area_unstable_area_thd_shift           (0)
#define  IEDGE_SMOOTH_EdgeSmooth_Unstable_area_unstable_area_en_mask             (0x80000000)
#define  IEDGE_SMOOTH_EdgeSmooth_Unstable_area_unstable_area_thd_mask            (0x0000001F)
#define  IEDGE_SMOOTH_EdgeSmooth_Unstable_area_unstable_area_en(data)            (0x80000000&((data)<<31))
#define  IEDGE_SMOOTH_EdgeSmooth_Unstable_area_unstable_area_thd(data)           (0x0000001F&(data))
#define  IEDGE_SMOOTH_EdgeSmooth_Unstable_area_get_unstable_area_en(data)        ((0x80000000&(data))>>31)
#define  IEDGE_SMOOTH_EdgeSmooth_Unstable_area_get_unstable_area_thd(data)       (0x0000001F&(data))

#define  IEDGE_SMOOTH_SPNR_PORCH_MEAS                                            0x18025144
#define  IEDGE_SMOOTH_SPNR_PORCH_MEAS_reg_addr                                   "0xB8025144"
#define  IEDGE_SMOOTH_SPNR_PORCH_MEAS_reg                                        0xB8025144
#define  IEDGE_SMOOTH_SPNR_PORCH_MEAS_inst_addr                                  "0x000E"
#define  set_IEDGE_SMOOTH_SPNR_PORCH_MEAS_reg(data)                              (*((volatile unsigned int*)IEDGE_SMOOTH_SPNR_PORCH_MEAS_reg)=data)
#define  get_IEDGE_SMOOTH_SPNR_PORCH_MEAS_reg                                    (*((volatile unsigned int*)IEDGE_SMOOTH_SPNR_PORCH_MEAS_reg))
#define  IEDGE_SMOOTH_SPNR_PORCH_MEAS_vsync_line_delay_shift                     (24)
#define  IEDGE_SMOOTH_SPNR_PORCH_MEAS_back_porch_meas_shift                      (8)
#define  IEDGE_SMOOTH_SPNR_PORCH_MEAS_front_porch_meas_shift                     (0)
#define  IEDGE_SMOOTH_SPNR_PORCH_MEAS_vsync_line_delay_mask                      (0x3F000000)
#define  IEDGE_SMOOTH_SPNR_PORCH_MEAS_back_porch_meas_mask                       (0x0000FF00)
#define  IEDGE_SMOOTH_SPNR_PORCH_MEAS_front_porch_meas_mask                      (0x000000FF)
#define  IEDGE_SMOOTH_SPNR_PORCH_MEAS_vsync_line_delay(data)                     (0x3F000000&((data)<<24))
#define  IEDGE_SMOOTH_SPNR_PORCH_MEAS_back_porch_meas(data)                      (0x0000FF00&((data)<<8))
#define  IEDGE_SMOOTH_SPNR_PORCH_MEAS_front_porch_meas(data)                     (0x000000FF&(data))
#define  IEDGE_SMOOTH_SPNR_PORCH_MEAS_get_vsync_line_delay(data)                 ((0x3F000000&(data))>>24)
#define  IEDGE_SMOOTH_SPNR_PORCH_MEAS_get_back_porch_meas(data)                  ((0x0000FF00&(data))>>8)
#define  IEDGE_SMOOTH_SPNR_PORCH_MEAS_get_front_porch_meas(data)                 (0x000000FF&(data))

#define  IEDGE_SMOOTH_SPNR_BISR_STATUS                                           0x18025148
#define  IEDGE_SMOOTH_SPNR_BISR_STATUS_reg_addr                                  "0xB8025148"
#define  IEDGE_SMOOTH_SPNR_BISR_STATUS_reg                                       0xB8025148
#define  IEDGE_SMOOTH_SPNR_BISR_STATUS_inst_addr                                 "0x000F"
#define  set_IEDGE_SMOOTH_SPNR_BISR_STATUS_reg(data)                             (*((volatile unsigned int*)IEDGE_SMOOTH_SPNR_BISR_STATUS_reg)=data)
#define  get_IEDGE_SMOOTH_SPNR_BISR_STATUS_reg                                   (*((volatile unsigned int*)IEDGE_SMOOTH_SPNR_BISR_STATUS_reg))
#define  IEDGE_SMOOTH_SPNR_BISR_STATUS_bisr_spnr_repaired_shift                  (31)
#define  IEDGE_SMOOTH_SPNR_BISR_STATUS_bisr_spnr_fail_1_shift                    (1)
#define  IEDGE_SMOOTH_SPNR_BISR_STATUS_bisr_spnr_fail_0_shift                    (0)
#define  IEDGE_SMOOTH_SPNR_BISR_STATUS_bisr_spnr_repaired_mask                   (0x80000000)
#define  IEDGE_SMOOTH_SPNR_BISR_STATUS_bisr_spnr_fail_1_mask                     (0x00000002)
#define  IEDGE_SMOOTH_SPNR_BISR_STATUS_bisr_spnr_fail_0_mask                     (0x00000001)
#define  IEDGE_SMOOTH_SPNR_BISR_STATUS_bisr_spnr_repaired(data)                  (0x80000000&((data)<<31))
#define  IEDGE_SMOOTH_SPNR_BISR_STATUS_bisr_spnr_fail_1(data)                    (0x00000002&((data)<<1))
#define  IEDGE_SMOOTH_SPNR_BISR_STATUS_bisr_spnr_fail_0(data)                    (0x00000001&(data))
#define  IEDGE_SMOOTH_SPNR_BISR_STATUS_get_bisr_spnr_repaired(data)              ((0x80000000&(data))>>31)
#define  IEDGE_SMOOTH_SPNR_BISR_STATUS_get_bisr_spnr_fail_1(data)                ((0x00000002&(data))>>1)
#define  IEDGE_SMOOTH_SPNR_BISR_STATUS_get_bisr_spnr_fail_0(data)                (0x00000001&(data))

#define  IEDGE_SMOOTH_SPNR_DRF_FAIL                                              0x1802514C
#define  IEDGE_SMOOTH_SPNR_DRF_FAIL_reg_addr                                     "0xB802514C"
#define  IEDGE_SMOOTH_SPNR_DRF_FAIL_reg                                          0xB802514C
#define  IEDGE_SMOOTH_SPNR_DRF_FAIL_inst_addr                                    "0x0010"
#define  set_IEDGE_SMOOTH_SPNR_DRF_FAIL_reg(data)                                (*((volatile unsigned int*)IEDGE_SMOOTH_SPNR_DRF_FAIL_reg)=data)
#define  get_IEDGE_SMOOTH_SPNR_DRF_FAIL_reg                                      (*((volatile unsigned int*)IEDGE_SMOOTH_SPNR_DRF_FAIL_reg))
#define  IEDGE_SMOOTH_SPNR_DRF_FAIL_spnr_drf_fail_1_shift                        (1)
#define  IEDGE_SMOOTH_SPNR_DRF_FAIL_spnr_drf_fail_0_shift                        (0)
#define  IEDGE_SMOOTH_SPNR_DRF_FAIL_spnr_drf_fail_1_mask                         (0x00000002)
#define  IEDGE_SMOOTH_SPNR_DRF_FAIL_spnr_drf_fail_0_mask                         (0x00000001)
#define  IEDGE_SMOOTH_SPNR_DRF_FAIL_spnr_drf_fail_1(data)                        (0x00000002&((data)<<1))
#define  IEDGE_SMOOTH_SPNR_DRF_FAIL_spnr_drf_fail_0(data)                        (0x00000001&(data))
#define  IEDGE_SMOOTH_SPNR_DRF_FAIL_get_spnr_drf_fail_1(data)                    ((0x00000002&(data))>>1)
#define  IEDGE_SMOOTH_SPNR_DRF_FAIL_get_spnr_drf_fail_0(data)                    (0x00000001&(data))

#define  IEDGE_SMOOTH_SPNR_DVS0                                                  0x18025150
#define  IEDGE_SMOOTH_SPNR_DVS0_reg_addr                                         "0xB8025150"
#define  IEDGE_SMOOTH_SPNR_DVS0_reg                                              0xB8025150
#define  IEDGE_SMOOTH_SPNR_DVS0_inst_addr                                        "0x0011"
#define  set_IEDGE_SMOOTH_SPNR_DVS0_reg(data)                                    (*((volatile unsigned int*)IEDGE_SMOOTH_SPNR_DVS0_reg)=data)
#define  get_IEDGE_SMOOTH_SPNR_DVS0_reg                                          (*((volatile unsigned int*)IEDGE_SMOOTH_SPNR_DVS0_reg))
#define  IEDGE_SMOOTH_SPNR_DVS0_spnr_ls_en_shift                                 (5)
#define  IEDGE_SMOOTH_SPNR_DVS0_spnr_dvse0_shift                                 (4)
#define  IEDGE_SMOOTH_SPNR_DVS0_spnr_dvs0_shift                                  (0)
#define  IEDGE_SMOOTH_SPNR_DVS0_spnr_ls_en_mask                                  (0x00000020)
#define  IEDGE_SMOOTH_SPNR_DVS0_spnr_dvse0_mask                                  (0x00000010)
#define  IEDGE_SMOOTH_SPNR_DVS0_spnr_dvs0_mask                                   (0x0000000F)
#define  IEDGE_SMOOTH_SPNR_DVS0_spnr_ls_en(data)                                 (0x00000020&((data)<<5))
#define  IEDGE_SMOOTH_SPNR_DVS0_spnr_dvse0(data)                                 (0x00000010&((data)<<4))
#define  IEDGE_SMOOTH_SPNR_DVS0_spnr_dvs0(data)                                  (0x0000000F&(data))
#define  IEDGE_SMOOTH_SPNR_DVS0_get_spnr_ls_en(data)                             ((0x00000020&(data))>>5)
#define  IEDGE_SMOOTH_SPNR_DVS0_get_spnr_dvse0(data)                             ((0x00000010&(data))>>4)
#define  IEDGE_SMOOTH_SPNR_DVS0_get_spnr_dvs0(data)                              (0x0000000F&(data))

#define  IEDGE_SMOOTH_VFILTER_0                                                  0x18025154
#define  IEDGE_SMOOTH_VFILTER_0_reg_addr                                         "0xB8025154"
#define  IEDGE_SMOOTH_VFILTER_0_reg                                              0xB8025154
#define  IEDGE_SMOOTH_VFILTER_0_inst_addr                                        "0x0012"
#define  set_IEDGE_SMOOTH_VFILTER_0_reg(data)                                    (*((volatile unsigned int*)IEDGE_SMOOTH_VFILTER_0_reg)=data)
#define  get_IEDGE_SMOOTH_VFILTER_0_reg                                          (*((volatile unsigned int*)IEDGE_SMOOTH_VFILTER_0_reg))
#define  IEDGE_SMOOTH_VFILTER_0_vfir_weight_shift                                (24)
#define  IEDGE_SMOOTH_VFILTER_0_avlpf_mindiff_th_start_shift                     (20)
#define  IEDGE_SMOOTH_VFILTER_0_avlpf_mindiff_curve_rate_start_shift             (16)
#define  IEDGE_SMOOTH_VFILTER_0_avlpf_mindiff_th_finish_shift                    (8)
#define  IEDGE_SMOOTH_VFILTER_0_avlpf_mindiff_curve_rate_finish_shift            (4)
#define  IEDGE_SMOOTH_VFILTER_0_avlpf_en_shift                                   (2)
#define  IEDGE_SMOOTH_VFILTER_0_avlpf_correct_en_shift                           (1)
#define  IEDGE_SMOOTH_VFILTER_0_avlpf_bw_pattern_en_shift                        (0)
#define  IEDGE_SMOOTH_VFILTER_0_vfir_weight_mask                                 (0x3F000000)
#define  IEDGE_SMOOTH_VFILTER_0_avlpf_mindiff_th_start_mask                      (0x00F00000)
#define  IEDGE_SMOOTH_VFILTER_0_avlpf_mindiff_curve_rate_start_mask              (0x00070000)
#define  IEDGE_SMOOTH_VFILTER_0_avlpf_mindiff_th_finish_mask                     (0x0000FF00)
#define  IEDGE_SMOOTH_VFILTER_0_avlpf_mindiff_curve_rate_finish_mask             (0x00000070)
#define  IEDGE_SMOOTH_VFILTER_0_avlpf_en_mask                                    (0x00000004)
#define  IEDGE_SMOOTH_VFILTER_0_avlpf_correct_en_mask                            (0x00000002)
#define  IEDGE_SMOOTH_VFILTER_0_avlpf_bw_pattern_en_mask                         (0x00000001)
#define  IEDGE_SMOOTH_VFILTER_0_vfir_weight(data)                                (0x3F000000&((data)<<24))
#define  IEDGE_SMOOTH_VFILTER_0_avlpf_mindiff_th_start(data)                     (0x00F00000&((data)<<20))
#define  IEDGE_SMOOTH_VFILTER_0_avlpf_mindiff_curve_rate_start(data)             (0x00070000&((data)<<16))
#define  IEDGE_SMOOTH_VFILTER_0_avlpf_mindiff_th_finish(data)                    (0x0000FF00&((data)<<8))
#define  IEDGE_SMOOTH_VFILTER_0_avlpf_mindiff_curve_rate_finish(data)            (0x00000070&((data)<<4))
#define  IEDGE_SMOOTH_VFILTER_0_avlpf_en(data)                                   (0x00000004&((data)<<2))
#define  IEDGE_SMOOTH_VFILTER_0_avlpf_correct_en(data)                           (0x00000002&((data)<<1))
#define  IEDGE_SMOOTH_VFILTER_0_avlpf_bw_pattern_en(data)                        (0x00000001&(data))
#define  IEDGE_SMOOTH_VFILTER_0_get_vfir_weight(data)                            ((0x3F000000&(data))>>24)
#define  IEDGE_SMOOTH_VFILTER_0_get_avlpf_mindiff_th_start(data)                 ((0x00F00000&(data))>>20)
#define  IEDGE_SMOOTH_VFILTER_0_get_avlpf_mindiff_curve_rate_start(data)         ((0x00070000&(data))>>16)
#define  IEDGE_SMOOTH_VFILTER_0_get_avlpf_mindiff_th_finish(data)                ((0x0000FF00&(data))>>8)
#define  IEDGE_SMOOTH_VFILTER_0_get_avlpf_mindiff_curve_rate_finish(data)        ((0x00000070&(data))>>4)
#define  IEDGE_SMOOTH_VFILTER_0_get_avlpf_en(data)                               ((0x00000004&(data))>>2)
#define  IEDGE_SMOOTH_VFILTER_0_get_avlpf_correct_en(data)                       ((0x00000002&(data))>>1)
#define  IEDGE_SMOOTH_VFILTER_0_get_avlpf_bw_pattern_en(data)                    (0x00000001&(data))

#define  IEDGE_SMOOTH_VFILTER_1                                                  0x18025158
#define  IEDGE_SMOOTH_VFILTER_1_reg_addr                                         "0xB8025158"
#define  IEDGE_SMOOTH_VFILTER_1_reg                                              0xB8025158
#define  IEDGE_SMOOTH_VFILTER_1_inst_addr                                        "0x0013"
#define  set_IEDGE_SMOOTH_VFILTER_1_reg(data)                                    (*((volatile unsigned int*)IEDGE_SMOOTH_VFILTER_1_reg)=data)
#define  get_IEDGE_SMOOTH_VFILTER_1_reg                                          (*((volatile unsigned int*)IEDGE_SMOOTH_VFILTER_1_reg))
#define  IEDGE_SMOOTH_VFILTER_1_avlpf_maxmindiff_th_shift                        (24)
#define  IEDGE_SMOOTH_VFILTER_1_avlpf_maxmindiff_curve_rate_shift                (16)
#define  IEDGE_SMOOTH_VFILTER_1_avlpf_max_weight_shift                           (8)
#define  IEDGE_SMOOTH_VFILTER_1_avlpf_min_weight_shift                           (0)
#define  IEDGE_SMOOTH_VFILTER_1_avlpf_maxmindiff_th_mask                         (0xFF000000)
#define  IEDGE_SMOOTH_VFILTER_1_avlpf_maxmindiff_curve_rate_mask                 (0x00070000)
#define  IEDGE_SMOOTH_VFILTER_1_avlpf_max_weight_mask                            (0x00003F00)
#define  IEDGE_SMOOTH_VFILTER_1_avlpf_min_weight_mask                            (0x0000003F)
#define  IEDGE_SMOOTH_VFILTER_1_avlpf_maxmindiff_th(data)                        (0xFF000000&((data)<<24))
#define  IEDGE_SMOOTH_VFILTER_1_avlpf_maxmindiff_curve_rate(data)                (0x00070000&((data)<<16))
#define  IEDGE_SMOOTH_VFILTER_1_avlpf_max_weight(data)                           (0x00003F00&((data)<<8))
#define  IEDGE_SMOOTH_VFILTER_1_avlpf_min_weight(data)                           (0x0000003F&(data))
#define  IEDGE_SMOOTH_VFILTER_1_get_avlpf_maxmindiff_th(data)                    ((0xFF000000&(data))>>24)
#define  IEDGE_SMOOTH_VFILTER_1_get_avlpf_maxmindiff_curve_rate(data)            ((0x00070000&(data))>>16)
#define  IEDGE_SMOOTH_VFILTER_1_get_avlpf_max_weight(data)                       ((0x00003F00&(data))>>8)
#define  IEDGE_SMOOTH_VFILTER_1_get_avlpf_min_weight(data)                       (0x0000003F&(data))

#define  IEDGE_SMOOTH_VFILTER_2                                                  0x1802515C
#define  IEDGE_SMOOTH_VFILTER_2_reg_addr                                         "0xB802515C"
#define  IEDGE_SMOOTH_VFILTER_2_reg                                              0xB802515C
#define  IEDGE_SMOOTH_VFILTER_2_inst_addr                                        "0x0014"
#define  set_IEDGE_SMOOTH_VFILTER_2_reg(data)                                    (*((volatile unsigned int*)IEDGE_SMOOTH_VFILTER_2_reg)=data)
#define  get_IEDGE_SMOOTH_VFILTER_2_reg                                          (*((volatile unsigned int*)IEDGE_SMOOTH_VFILTER_2_reg))
#define  IEDGE_SMOOTH_VFILTER_2_avlpf_bw_th_shift                                (24)
#define  IEDGE_SMOOTH_VFILTER_2_avlpf_bw_margin_shift                            (16)
#define  IEDGE_SMOOTH_VFILTER_2_avlpf_bw_curve_rate_shift                        (12)
#define  IEDGE_SMOOTH_VFILTER_2_avlpf_c_en_shift                                 (8)
#define  IEDGE_SMOOTH_VFILTER_2_vfir_c_weight_shift                              (0)
#define  IEDGE_SMOOTH_VFILTER_2_avlpf_bw_th_mask                                 (0xFF000000)
#define  IEDGE_SMOOTH_VFILTER_2_avlpf_bw_margin_mask                             (0x007F0000)
#define  IEDGE_SMOOTH_VFILTER_2_avlpf_bw_curve_rate_mask                         (0x00007000)
#define  IEDGE_SMOOTH_VFILTER_2_avlpf_c_en_mask                                  (0x00000100)
#define  IEDGE_SMOOTH_VFILTER_2_vfir_c_weight_mask                               (0x0000003F)
#define  IEDGE_SMOOTH_VFILTER_2_avlpf_bw_th(data)                                (0xFF000000&((data)<<24))
#define  IEDGE_SMOOTH_VFILTER_2_avlpf_bw_margin(data)                            (0x007F0000&((data)<<16))
#define  IEDGE_SMOOTH_VFILTER_2_avlpf_bw_curve_rate(data)                        (0x00007000&((data)<<12))
#define  IEDGE_SMOOTH_VFILTER_2_avlpf_c_en(data)                                 (0x00000100&((data)<<8))
#define  IEDGE_SMOOTH_VFILTER_2_vfir_c_weight(data)                              (0x0000003F&(data))
#define  IEDGE_SMOOTH_VFILTER_2_get_avlpf_bw_th(data)                            ((0xFF000000&(data))>>24)
#define  IEDGE_SMOOTH_VFILTER_2_get_avlpf_bw_margin(data)                        ((0x007F0000&(data))>>16)
#define  IEDGE_SMOOTH_VFILTER_2_get_avlpf_bw_curve_rate(data)                    ((0x00007000&(data))>>12)
#define  IEDGE_SMOOTH_VFILTER_2_get_avlpf_c_en(data)                             ((0x00000100&(data))>>8)
#define  IEDGE_SMOOTH_VFILTER_2_get_vfir_c_weight(data)                          (0x0000003F&(data))

#define  IEDGE_SMOOTH_VFILTER_3                                                  0x18025160
#define  IEDGE_SMOOTH_VFILTER_3_reg_addr                                         "0xB8025160"
#define  IEDGE_SMOOTH_VFILTER_3_reg                                              0xB8025160
#define  IEDGE_SMOOTH_VFILTER_3_inst_addr                                        "0x0015"
#define  set_IEDGE_SMOOTH_VFILTER_3_reg(data)                                    (*((volatile unsigned int*)IEDGE_SMOOTH_VFILTER_3_reg)=data)
#define  get_IEDGE_SMOOTH_VFILTER_3_reg                                          (*((volatile unsigned int*)IEDGE_SMOOTH_VFILTER_3_reg))
#define  IEDGE_SMOOTH_VFILTER_3_vfir_debug_shift                                 (0)
#define  IEDGE_SMOOTH_VFILTER_3_vfir_debug_mask                                  (0x0000000F)
#define  IEDGE_SMOOTH_VFILTER_3_vfir_debug(data)                                 (0x0000000F&(data))
#define  IEDGE_SMOOTH_VFILTER_3_get_vfir_debug(data)                             (0x0000000F&(data))

#define  IEDGE_SMOOTH_EDSM_DB_CTRL                                               0x18025170
#define  IEDGE_SMOOTH_EDSM_DB_CTRL_reg_addr                                      "0xB8025170"
#define  IEDGE_SMOOTH_EDSM_DB_CTRL_reg                                           0xB8025170
#define  IEDGE_SMOOTH_EDSM_DB_CTRL_inst_addr                                     "0x0016"
#define  set_IEDGE_SMOOTH_EDSM_DB_CTRL_reg(data)                                 (*((volatile unsigned int*)IEDGE_SMOOTH_EDSM_DB_CTRL_reg)=data)
#define  get_IEDGE_SMOOTH_EDSM_DB_CTRL_reg                                       (*((volatile unsigned int*)IEDGE_SMOOTH_EDSM_DB_CTRL_reg))
#define  IEDGE_SMOOTH_EDSM_DB_CTRL_edsm_db_apply_shift                           (2)
#define  IEDGE_SMOOTH_EDSM_DB_CTRL_edsm_db_rd_sel_shift                          (1)
#define  IEDGE_SMOOTH_EDSM_DB_CTRL_edsm_db_en_shift                              (0)
#define  IEDGE_SMOOTH_EDSM_DB_CTRL_edsm_db_apply_mask                            (0x00000004)
#define  IEDGE_SMOOTH_EDSM_DB_CTRL_edsm_db_rd_sel_mask                           (0x00000002)
#define  IEDGE_SMOOTH_EDSM_DB_CTRL_edsm_db_en_mask                               (0x00000001)
#define  IEDGE_SMOOTH_EDSM_DB_CTRL_edsm_db_apply(data)                           (0x00000004&((data)<<2))
#define  IEDGE_SMOOTH_EDSM_DB_CTRL_edsm_db_rd_sel(data)                          (0x00000002&((data)<<1))
#define  IEDGE_SMOOTH_EDSM_DB_CTRL_edsm_db_en(data)                              (0x00000001&(data))
#define  IEDGE_SMOOTH_EDSM_DB_CTRL_get_edsm_db_apply(data)                       ((0x00000004&(data))>>2)
#define  IEDGE_SMOOTH_EDSM_DB_CTRL_get_edsm_db_rd_sel(data)                      ((0x00000002&(data))>>1)
#define  IEDGE_SMOOTH_EDSM_DB_CTRL_get_edsm_db_en(data)                          (0x00000001&(data))

#define  IEDGE_SMOOTH_FORMAT_CONVERT                                             0x18025180
#define  IEDGE_SMOOTH_FORMAT_CONVERT_reg_addr                                    "0xB8025180"
#define  IEDGE_SMOOTH_FORMAT_CONVERT_reg                                         0xB8025180
#define  IEDGE_SMOOTH_FORMAT_CONVERT_inst_addr                                   "0x0017"
#define  set_IEDGE_SMOOTH_FORMAT_CONVERT_reg(data)                               (*((volatile unsigned int*)IEDGE_SMOOTH_FORMAT_CONVERT_reg)=data)
#define  get_IEDGE_SMOOTH_FORMAT_CONVERT_reg                                     (*((volatile unsigned int*)IEDGE_SMOOTH_FORMAT_CONVERT_reg))
#define  IEDGE_SMOOTH_FORMAT_CONVERT_main_422_to_444_en_shift                    (31)
#define  IEDGE_SMOOTH_FORMAT_CONVERT_main_422_to_444_type_shift                  (30)
#define  IEDGE_SMOOTH_FORMAT_CONVERT_main_422_to_444_dup_shift                   (29)
#define  IEDGE_SMOOTH_FORMAT_CONVERT_main_422_to_444_en_mask                     (0x80000000)
#define  IEDGE_SMOOTH_FORMAT_CONVERT_main_422_to_444_type_mask                   (0x40000000)
#define  IEDGE_SMOOTH_FORMAT_CONVERT_main_422_to_444_dup_mask                    (0x20000000)
#define  IEDGE_SMOOTH_FORMAT_CONVERT_main_422_to_444_en(data)                    (0x80000000&((data)<<31))
#define  IEDGE_SMOOTH_FORMAT_CONVERT_main_422_to_444_type(data)                  (0x40000000&((data)<<30))
#define  IEDGE_SMOOTH_FORMAT_CONVERT_main_422_to_444_dup(data)                   (0x20000000&((data)<<29))
#define  IEDGE_SMOOTH_FORMAT_CONVERT_get_main_422_to_444_en(data)                ((0x80000000&(data))>>31)
#define  IEDGE_SMOOTH_FORMAT_CONVERT_get_main_422_to_444_type(data)              ((0x40000000&(data))>>30)
#define  IEDGE_SMOOTH_FORMAT_CONVERT_get_main_422_to_444_dup(data)               ((0x20000000&(data))>>29)

#define  IEDGE_SMOOTH_OUT_CLAMP                                                  0x18025184
#define  IEDGE_SMOOTH_OUT_CLAMP_reg_addr                                         "0xB8025184"
#define  IEDGE_SMOOTH_OUT_CLAMP_reg                                              0xB8025184
#define  IEDGE_SMOOTH_OUT_CLAMP_inst_addr                                        "0x0018"
#define  set_IEDGE_SMOOTH_OUT_CLAMP_reg(data)                                    (*((volatile unsigned int*)IEDGE_SMOOTH_OUT_CLAMP_reg)=data)
#define  get_IEDGE_SMOOTH_OUT_CLAMP_reg                                          (*((volatile unsigned int*)IEDGE_SMOOTH_OUT_CLAMP_reg))
#define  IEDGE_SMOOTH_OUT_CLAMP_iedsm_outclamp_thd_shift                         (1)
#define  IEDGE_SMOOTH_OUT_CLAMP_iedsm_outclamp_en_shift                          (0)
#define  IEDGE_SMOOTH_OUT_CLAMP_iedsm_outclamp_thd_mask                          (0x000000FE)
#define  IEDGE_SMOOTH_OUT_CLAMP_iedsm_outclamp_en_mask                           (0x00000001)
#define  IEDGE_SMOOTH_OUT_CLAMP_iedsm_outclamp_thd(data)                         (0x000000FE&((data)<<1))
#define  IEDGE_SMOOTH_OUT_CLAMP_iedsm_outclamp_en(data)                          (0x00000001&(data))
#define  IEDGE_SMOOTH_OUT_CLAMP_get_iedsm_outclamp_thd(data)                     ((0x000000FE&(data))>>1)
#define  IEDGE_SMOOTH_OUT_CLAMP_get_iedsm_outclamp_en(data)                      (0x00000001&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======IEDGE_SMOOTH register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  dummy18025100_25_18:8;
        RBus_UInt32  tst_en:1;
        RBus_UInt32  lbuf_disable:1;
        RBus_UInt32  debug_mode:4;
        RBus_UInt32  edgemode:1;
        RBus_UInt32  lbuf_linemode:2;
        RBus_UInt32  debug_en:1;
        RBus_UInt32  crct_5linemode:1;
        RBus_UInt32  chaos_5linemode:1;
        RBus_UInt32  lpf_5tapmode:1;
        RBus_UInt32  edge_en:1;
        RBus_UInt32  chaos_en:1;
        RBus_UInt32  crct_en:1;
        RBus_UInt32  t2df_en:1;
        RBus_UInt32  edgesmoothex_en:1;
    };
}iedge_smooth_edgesmooth_ex_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  chaos_diffth:8;
        RBus_UInt32  res1:6;
        RBus_UInt32  chaos_mode:2;
        RBus_UInt32  t2df_stepbit:4;
        RBus_UInt32  res2:2;
        RBus_UInt32  t2df_upbnd:10;
    };
}iedge_smooth_edgesmooth_ex_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  chaos_lwbnd:5;
        RBus_UInt32  edge_stepbit:4;
        RBus_UInt32  res2:2;
        RBus_UInt32  edge_upbnd:10;
    };
}iedge_smooth_edgesmooth_ex_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  iedge_nr_sel:1;
        RBus_UInt32  iedge_mixer_weight:4;
        RBus_UInt32  res2:4;
    };
}iedge_smooth_mixer_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ext_range_en:1;
        RBus_UInt32  res1:11;
        RBus_UInt32  ext_uvrange:2;
        RBus_UInt32  ext_range:2;
        RBus_UInt32  ext_uvdiff_stepbit:4;
        RBus_UInt32  res2:2;
        RBus_UInt32  ext_uvdiff_upbnd:10;
    };
}iedge_smooth_edgesmooth_extension_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ext_angle_crc_en:1;
        RBus_UInt32  ext_angle_en:1;
        RBus_UInt32  res1:12;
        RBus_UInt32  ext_angle_rl_thd:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ext_angle_maxdiff_thd:10;
    };
}iedge_smooth_edgesmooth_ext_angle_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_demo_en:1;
        RBus_UInt32  reg_demo_inv:1;
        RBus_UInt32  res1:6;
        RBus_UInt32  reg_h_end:12;
        RBus_UInt32  reg_h_start:12;
    };
}iedge_smooth_demo_window_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  reg_v_end:12;
        RBus_UInt32  reg_v_start:12;
    };
}iedge_smooth_demo_window_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  prelpf_iedge2_sel:1;
        RBus_UInt32  dummy18025128_30_28:3;
        RBus_UInt32  res1:8;
        RBus_UInt32  prelpf_iedge1_sel:4;
        RBus_UInt32  res2:12;
        RBus_UInt32  prelpf_snr_sel:4;
    };
}iedge_smooth_prelpf_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  dlti2d_hlpf_type:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  dlti2d_vlpf_type:2;
        RBus_UInt32  edsm_dlti_en:1;
        RBus_UInt32  dlti2d_chaos_gain:3;
        RBus_UInt32  res3:3;
        RBus_UInt32  dlti2d_maxmin_en:1;
        RBus_UInt32  res4:2;
        RBus_UInt32  dlti2d_gain:6;
    };
}iedge_smooth_dlti2d_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mess_direction_en:1;
        RBus_UInt32  res1:11;
        RBus_UInt32  mess_4direction_thd:4;
        RBus_UInt32  mess_4direction_step:4;
        RBus_UInt32  mess_4direction_w0:4;
        RBus_UInt32  mess_4direction_w1:4;
        RBus_UInt32  mess_4direction_w2:4;
    };
}iedge_smooth_edgesmooth_mess_direction1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  mess_8direction_thd:4;
        RBus_UInt32  mess_8direction_step:4;
        RBus_UInt32  mess_8direction_w0:4;
        RBus_UInt32  mess_8direction_w1:4;
        RBus_UInt32  mess_8direction_w2:4;
    };
}iedge_smooth_edgesmooth_mess_direction2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  blend_weight_lpf_en:1;
        RBus_UInt32  res1:31;
    };
}iedge_smooth_edgesmooth_blend_weight_lpf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  unstable_area_en:1;
        RBus_UInt32  res1:26;
        RBus_UInt32  unstable_area_thd:5;
    };
}iedge_smooth_edgesmooth_unstable_area_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  vsync_line_delay:6;
        RBus_UInt32  res2:8;
        RBus_UInt32  back_porch_meas:8;
        RBus_UInt32  front_porch_meas:8;
    };
}iedge_smooth_spnr_porch_meas_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bisr_spnr_repaired:1;
        RBus_UInt32  res1:29;
        RBus_UInt32  bisr_spnr_fail_1:1;
        RBus_UInt32  bisr_spnr_fail_0:1;
    };
}iedge_smooth_spnr_bisr_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  spnr_drf_fail_1:1;
        RBus_UInt32  spnr_drf_fail_0:1;
    };
}iedge_smooth_spnr_drf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  spnr_ls_en:1;
        RBus_UInt32  spnr_dvse0:1;
        RBus_UInt32  spnr_dvs0:4;
    };
}iedge_smooth_spnr_dvs0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  vfir_weight:6;
        RBus_UInt32  avlpf_mindiff_th_start:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  avlpf_mindiff_curve_rate_start:3;
        RBus_UInt32  avlpf_mindiff_th_finish:8;
        RBus_UInt32  res3:1;
        RBus_UInt32  avlpf_mindiff_curve_rate_finish:3;
        RBus_UInt32  res4:1;
        RBus_UInt32  avlpf_en:1;
        RBus_UInt32  avlpf_correct_en:1;
        RBus_UInt32  avlpf_bw_pattern_en:1;
    };
}iedge_smooth_vfilter_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  avlpf_maxmindiff_th:8;
        RBus_UInt32  res1:5;
        RBus_UInt32  avlpf_maxmindiff_curve_rate:3;
        RBus_UInt32  res2:2;
        RBus_UInt32  avlpf_max_weight:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  avlpf_min_weight:6;
    };
}iedge_smooth_vfilter_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  avlpf_bw_th:8;
        RBus_UInt32  res1:1;
        RBus_UInt32  avlpf_bw_margin:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  avlpf_bw_curve_rate:3;
        RBus_UInt32  res3:3;
        RBus_UInt32  avlpf_c_en:1;
        RBus_UInt32  res4:2;
        RBus_UInt32  vfir_c_weight:6;
    };
}iedge_smooth_vfilter_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  vfir_debug:4;
    };
}iedge_smooth_vfilter_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  edsm_db_apply:1;
        RBus_UInt32  edsm_db_rd_sel:1;
        RBus_UInt32  edsm_db_en:1;
    };
}iedge_smooth_edsm_db_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  main_422_to_444_en:1;
        RBus_UInt32  main_422_to_444_type:1;
        RBus_UInt32  main_422_to_444_dup:1;
        RBus_UInt32  res1:16;
        RBus_UInt32  res2:13;
    };
}iedge_smooth_format_convert_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  iedsm_outclamp_thd:7;
        RBus_UInt32  iedsm_outclamp_en:1;
    };
}iedge_smooth_out_clamp_RBUS;

#else //apply LITTLE_ENDIAN

//======IEDGE_SMOOTH register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  edgesmoothex_en:1;
        RBus_UInt32  t2df_en:1;
        RBus_UInt32  crct_en:1;
        RBus_UInt32  chaos_en:1;
        RBus_UInt32  edge_en:1;
        RBus_UInt32  lpf_5tapmode:1;
        RBus_UInt32  chaos_5linemode:1;
        RBus_UInt32  crct_5linemode:1;
        RBus_UInt32  debug_en:1;
        RBus_UInt32  lbuf_linemode:2;
        RBus_UInt32  edgemode:1;
        RBus_UInt32  debug_mode:4;
        RBus_UInt32  lbuf_disable:1;
        RBus_UInt32  tst_en:1;
        RBus_UInt32  dummy18025100_25_18:8;
        RBus_UInt32  res1:6;
    };
}iedge_smooth_edgesmooth_ex_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  t2df_upbnd:10;
        RBus_UInt32  res1:2;
        RBus_UInt32  t2df_stepbit:4;
        RBus_UInt32  chaos_mode:2;
        RBus_UInt32  res2:6;
        RBus_UInt32  chaos_diffth:8;
    };
}iedge_smooth_edgesmooth_ex_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  edge_upbnd:10;
        RBus_UInt32  res1:2;
        RBus_UInt32  edge_stepbit:4;
        RBus_UInt32  chaos_lwbnd:5;
        RBus_UInt32  res2:11;
    };
}iedge_smooth_edgesmooth_ex_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  iedge_mixer_weight:4;
        RBus_UInt32  iedge_nr_sel:1;
        RBus_UInt32  res2:23;
    };
}iedge_smooth_mixer_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ext_uvdiff_upbnd:10;
        RBus_UInt32  res1:2;
        RBus_UInt32  ext_uvdiff_stepbit:4;
        RBus_UInt32  ext_range:2;
        RBus_UInt32  ext_uvrange:2;
        RBus_UInt32  res2:11;
        RBus_UInt32  ext_range_en:1;
    };
}iedge_smooth_edgesmooth_extension_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ext_angle_maxdiff_thd:10;
        RBus_UInt32  res1:2;
        RBus_UInt32  ext_angle_rl_thd:6;
        RBus_UInt32  res2:12;
        RBus_UInt32  ext_angle_en:1;
        RBus_UInt32  ext_angle_crc_en:1;
    };
}iedge_smooth_edgesmooth_ext_angle_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_h_start:12;
        RBus_UInt32  reg_h_end:12;
        RBus_UInt32  res1:6;
        RBus_UInt32  reg_demo_inv:1;
        RBus_UInt32  reg_demo_en:1;
    };
}iedge_smooth_demo_window_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_v_start:12;
        RBus_UInt32  reg_v_end:12;
        RBus_UInt32  res1:8;
    };
}iedge_smooth_demo_window_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  prelpf_snr_sel:4;
        RBus_UInt32  res1:12;
        RBus_UInt32  prelpf_iedge1_sel:4;
        RBus_UInt32  res2:8;
        RBus_UInt32  dummy18025128_30_28:3;
        RBus_UInt32  prelpf_iedge2_sel:1;
    };
}iedge_smooth_prelpf_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dlti2d_gain:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  dlti2d_maxmin_en:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  dlti2d_chaos_gain:3;
        RBus_UInt32  edsm_dlti_en:1;
        RBus_UInt32  dlti2d_vlpf_type:2;
        RBus_UInt32  res3:2;
        RBus_UInt32  dlti2d_hlpf_type:2;
        RBus_UInt32  res4:10;
    };
}iedge_smooth_dlti2d_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mess_4direction_w2:4;
        RBus_UInt32  mess_4direction_w1:4;
        RBus_UInt32  mess_4direction_w0:4;
        RBus_UInt32  mess_4direction_step:4;
        RBus_UInt32  mess_4direction_thd:4;
        RBus_UInt32  res1:11;
        RBus_UInt32  mess_direction_en:1;
    };
}iedge_smooth_edgesmooth_mess_direction1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mess_8direction_w2:4;
        RBus_UInt32  mess_8direction_w1:4;
        RBus_UInt32  mess_8direction_w0:4;
        RBus_UInt32  mess_8direction_step:4;
        RBus_UInt32  mess_8direction_thd:4;
        RBus_UInt32  res1:12;
    };
}iedge_smooth_edgesmooth_mess_direction2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  blend_weight_lpf_en:1;
    };
}iedge_smooth_edgesmooth_blend_weight_lpf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  unstable_area_thd:5;
        RBus_UInt32  res1:26;
        RBus_UInt32  unstable_area_en:1;
    };
}iedge_smooth_edgesmooth_unstable_area_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  front_porch_meas:8;
        RBus_UInt32  back_porch_meas:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  vsync_line_delay:6;
        RBus_UInt32  res2:2;
    };
}iedge_smooth_spnr_porch_meas_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bisr_spnr_fail_0:1;
        RBus_UInt32  bisr_spnr_fail_1:1;
        RBus_UInt32  res1:29;
        RBus_UInt32  bisr_spnr_repaired:1;
    };
}iedge_smooth_spnr_bisr_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  spnr_drf_fail_0:1;
        RBus_UInt32  spnr_drf_fail_1:1;
        RBus_UInt32  res1:30;
    };
}iedge_smooth_spnr_drf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  spnr_dvs0:4;
        RBus_UInt32  spnr_dvse0:1;
        RBus_UInt32  spnr_ls_en:1;
        RBus_UInt32  res1:26;
    };
}iedge_smooth_spnr_dvs0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  avlpf_bw_pattern_en:1;
        RBus_UInt32  avlpf_correct_en:1;
        RBus_UInt32  avlpf_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  avlpf_mindiff_curve_rate_finish:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  avlpf_mindiff_th_finish:8;
        RBus_UInt32  avlpf_mindiff_curve_rate_start:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  avlpf_mindiff_th_start:4;
        RBus_UInt32  vfir_weight:6;
        RBus_UInt32  res4:2;
    };
}iedge_smooth_vfilter_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  avlpf_min_weight:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  avlpf_max_weight:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  avlpf_maxmindiff_curve_rate:3;
        RBus_UInt32  res3:5;
        RBus_UInt32  avlpf_maxmindiff_th:8;
    };
}iedge_smooth_vfilter_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vfir_c_weight:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  avlpf_c_en:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  avlpf_bw_curve_rate:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  avlpf_bw_margin:7;
        RBus_UInt32  res4:1;
        RBus_UInt32  avlpf_bw_th:8;
    };
}iedge_smooth_vfilter_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vfir_debug:4;
        RBus_UInt32  res1:28;
    };
}iedge_smooth_vfilter_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  edsm_db_en:1;
        RBus_UInt32  edsm_db_rd_sel:1;
        RBus_UInt32  edsm_db_apply:1;
        RBus_UInt32  res1:29;
    };
}iedge_smooth_edsm_db_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  res2:16;
        RBus_UInt32  main_422_to_444_dup:1;
        RBus_UInt32  main_422_to_444_type:1;
        RBus_UInt32  main_422_to_444_en:1;
    };
}iedge_smooth_format_convert_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  iedsm_outclamp_en:1;
        RBus_UInt32  iedsm_outclamp_thd:7;
        RBus_UInt32  res1:24;
    };
}iedge_smooth_out_clamp_RBUS;




#endif 


#endif 
