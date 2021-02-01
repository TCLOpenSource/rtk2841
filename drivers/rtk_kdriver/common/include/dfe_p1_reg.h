/**
* @file rbusDFE_P1Reg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2016/6/7
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_DFE_P1_REG_H_
#define _RBUS_DFE_P1_REG_H_

#include "rbus_types.h"



//  DFE_P1 Register Address
#define  DFE_P1_REG_DFE_EN_L0_P1                                                 0x1800DE50
#define  DFE_P1_REG_DFE_EN_L0_P1_reg_addr                                        "0xB800DE50"
#define  DFE_P1_REG_DFE_EN_L0_P1_reg                                             0xB800DE50
#define  DFE_P1_REG_DFE_EN_L0_P1_inst_addr                                       "0x0000"
#define  set_DFE_P1_REG_DFE_EN_L0_P1_reg(data)                                   (*((volatile unsigned int*)DFE_P1_REG_DFE_EN_L0_P1_reg)=data)
#define  get_DFE_P1_REG_DFE_EN_L0_P1_reg                                         (*((volatile unsigned int*)DFE_P1_REG_DFE_EN_L0_P1_reg))
#define  DFE_P1_REG_DFE_EN_L0_P1_clk_inv_lane0_p1_shift                          (31)
#define  DFE_P1_REG_DFE_EN_L0_P1_timer_ctrl_en_lane0_p1_shift                    (30)
#define  DFE_P1_REG_DFE_EN_L0_P1_reduce_adapt_gain_lane0_p1_shift                (28)
#define  DFE_P1_REG_DFE_EN_L0_P1_rl_det_en_lane0_p1_shift                        (27)
#define  DFE_P1_REG_DFE_EN_L0_P1_rl_det_mode_lane0_p1_shift                      (26)
#define  DFE_P1_REG_DFE_EN_L0_P1_rl_threshold_lane0_p1_shift                     (24)
#define  DFE_P1_REG_DFE_EN_L0_P1_dfe_adapt_en_lane0_p1_shift                     (16)
#define  DFE_P1_REG_DFE_EN_L0_P1_le_min_lane0_p1_shift                           (11)
#define  DFE_P1_REG_DFE_EN_L0_P1_le_init_lane0_p1_shift                          (6)
#define  DFE_P1_REG_DFE_EN_L0_P1_tap4_init_lane0_p1_shift                        (0)
#define  DFE_P1_REG_DFE_EN_L0_P1_clk_inv_lane0_p1_mask                           (0x80000000)
#define  DFE_P1_REG_DFE_EN_L0_P1_timer_ctrl_en_lane0_p1_mask                     (0x40000000)
#define  DFE_P1_REG_DFE_EN_L0_P1_reduce_adapt_gain_lane0_p1_mask                 (0x30000000)
#define  DFE_P1_REG_DFE_EN_L0_P1_rl_det_en_lane0_p1_mask                         (0x08000000)
#define  DFE_P1_REG_DFE_EN_L0_P1_rl_det_mode_lane0_p1_mask                       (0x04000000)
#define  DFE_P1_REG_DFE_EN_L0_P1_rl_threshold_lane0_p1_mask                      (0x03000000)
#define  DFE_P1_REG_DFE_EN_L0_P1_dfe_adapt_en_lane0_p1_mask                      (0x00FF0000)
#define  DFE_P1_REG_DFE_EN_L0_P1_le_min_lane0_p1_mask                            (0x0000F800)
#define  DFE_P1_REG_DFE_EN_L0_P1_le_init_lane0_p1_mask                           (0x000007C0)
#define  DFE_P1_REG_DFE_EN_L0_P1_tap4_init_lane0_p1_mask                         (0x0000003F)
#define  DFE_P1_REG_DFE_EN_L0_P1_clk_inv_lane0_p1(data)                          (0x80000000&((data)<<31))
#define  DFE_P1_REG_DFE_EN_L0_P1_timer_ctrl_en_lane0_p1(data)                    (0x40000000&((data)<<30))
#define  DFE_P1_REG_DFE_EN_L0_P1_reduce_adapt_gain_lane0_p1(data)                (0x30000000&((data)<<28))
#define  DFE_P1_REG_DFE_EN_L0_P1_rl_det_en_lane0_p1(data)                        (0x08000000&((data)<<27))
#define  DFE_P1_REG_DFE_EN_L0_P1_rl_det_mode_lane0_p1(data)                      (0x04000000&((data)<<26))
#define  DFE_P1_REG_DFE_EN_L0_P1_rl_threshold_lane0_p1(data)                     (0x03000000&((data)<<24))
#define  DFE_P1_REG_DFE_EN_L0_P1_dfe_adapt_en_lane0_p1(data)                     (0x00FF0000&((data)<<16))
#define  DFE_P1_REG_DFE_EN_L0_P1_le_min_lane0_p1(data)                           (0x0000F800&((data)<<11))
#define  DFE_P1_REG_DFE_EN_L0_P1_le_init_lane0_p1(data)                          (0x000007C0&((data)<<6))
#define  DFE_P1_REG_DFE_EN_L0_P1_tap4_init_lane0_p1(data)                        (0x0000003F&(data))
#define  DFE_P1_REG_DFE_EN_L0_P1_get_clk_inv_lane0_p1(data)                      ((0x80000000&(data))>>31)
#define  DFE_P1_REG_DFE_EN_L0_P1_get_timer_ctrl_en_lane0_p1(data)                ((0x40000000&(data))>>30)
#define  DFE_P1_REG_DFE_EN_L0_P1_get_reduce_adapt_gain_lane0_p1(data)            ((0x30000000&(data))>>28)
#define  DFE_P1_REG_DFE_EN_L0_P1_get_rl_det_en_lane0_p1(data)                    ((0x08000000&(data))>>27)
#define  DFE_P1_REG_DFE_EN_L0_P1_get_rl_det_mode_lane0_p1(data)                  ((0x04000000&(data))>>26)
#define  DFE_P1_REG_DFE_EN_L0_P1_get_rl_threshold_lane0_p1(data)                 ((0x03000000&(data))>>24)
#define  DFE_P1_REG_DFE_EN_L0_P1_get_dfe_adapt_en_lane0_p1(data)                 ((0x00FF0000&(data))>>16)
#define  DFE_P1_REG_DFE_EN_L0_P1_get_le_min_lane0_p1(data)                       ((0x0000F800&(data))>>11)
#define  DFE_P1_REG_DFE_EN_L0_P1_get_le_init_lane0_p1(data)                      ((0x000007C0&(data))>>6)
#define  DFE_P1_REG_DFE_EN_L0_P1_get_tap4_init_lane0_p1(data)                    (0x0000003F&(data))

#define  DFE_P1_REG_DFE_INIT0_L0_P1                                              0x1800DE54
#define  DFE_P1_REG_DFE_INIT0_L0_P1_reg_addr                                     "0xB800DE54"
#define  DFE_P1_REG_DFE_INIT0_L0_P1_reg                                          0xB800DE54
#define  DFE_P1_REG_DFE_INIT0_L0_P1_inst_addr                                    "0x0001"
#define  set_DFE_P1_REG_DFE_INIT0_L0_P1_reg(data)                                (*((volatile unsigned int*)DFE_P1_REG_DFE_INIT0_L0_P1_reg)=data)
#define  get_DFE_P1_REG_DFE_INIT0_L0_P1_reg                                      (*((volatile unsigned int*)DFE_P1_REG_DFE_INIT0_L0_P1_reg))
#define  DFE_P1_REG_DFE_INIT0_L0_P1_tap3_init_lane0_p1_shift                     (26)
#define  DFE_P1_REG_DFE_INIT0_L0_P1_tap2_init_lane0_p1_shift                     (20)
#define  DFE_P1_REG_DFE_INIT0_L0_P1_tap1_init_lane0_p1_shift                     (14)
#define  DFE_P1_REG_DFE_INIT0_L0_P1_tap0_init_lane0_p1_shift                     (7)
#define  DFE_P1_REG_DFE_INIT0_L0_P1_init1_rev0_lane0_p1_shift                    (4)
#define  DFE_P1_REG_DFE_INIT0_L0_P1_vth_init_lane0_p1_shift                      (0)
#define  DFE_P1_REG_DFE_INIT0_L0_P1_tap3_init_lane0_p1_mask                      (0xFC000000)
#define  DFE_P1_REG_DFE_INIT0_L0_P1_tap2_init_lane0_p1_mask                      (0x03F00000)
#define  DFE_P1_REG_DFE_INIT0_L0_P1_tap1_init_lane0_p1_mask                      (0x000FC000)
#define  DFE_P1_REG_DFE_INIT0_L0_P1_tap0_init_lane0_p1_mask                      (0x00003F80)
#define  DFE_P1_REG_DFE_INIT0_L0_P1_init1_rev0_lane0_p1_mask                     (0x00000070)
#define  DFE_P1_REG_DFE_INIT0_L0_P1_vth_init_lane0_p1_mask                       (0x0000000F)
#define  DFE_P1_REG_DFE_INIT0_L0_P1_tap3_init_lane0_p1(data)                     (0xFC000000&((data)<<26))
#define  DFE_P1_REG_DFE_INIT0_L0_P1_tap2_init_lane0_p1(data)                     (0x03F00000&((data)<<20))
#define  DFE_P1_REG_DFE_INIT0_L0_P1_tap1_init_lane0_p1(data)                     (0x000FC000&((data)<<14))
#define  DFE_P1_REG_DFE_INIT0_L0_P1_tap0_init_lane0_p1(data)                     (0x00003F80&((data)<<7))
#define  DFE_P1_REG_DFE_INIT0_L0_P1_init1_rev0_lane0_p1(data)                    (0x00000070&((data)<<4))
#define  DFE_P1_REG_DFE_INIT0_L0_P1_vth_init_lane0_p1(data)                      (0x0000000F&(data))
#define  DFE_P1_REG_DFE_INIT0_L0_P1_get_tap3_init_lane0_p1(data)                 ((0xFC000000&(data))>>26)
#define  DFE_P1_REG_DFE_INIT0_L0_P1_get_tap2_init_lane0_p1(data)                 ((0x03F00000&(data))>>20)
#define  DFE_P1_REG_DFE_INIT0_L0_P1_get_tap1_init_lane0_p1(data)                 ((0x000FC000&(data))>>14)
#define  DFE_P1_REG_DFE_INIT0_L0_P1_get_tap0_init_lane0_p1(data)                 ((0x00003F80&(data))>>7)
#define  DFE_P1_REG_DFE_INIT0_L0_P1_get_init1_rev0_lane0_p1(data)                ((0x00000070&(data))>>4)
#define  DFE_P1_REG_DFE_INIT0_L0_P1_get_vth_init_lane0_p1(data)                  (0x0000000F&(data))

#define  DFE_P1_REG_DFE_INIT1_L0_P1                                              0x1800DE58
#define  DFE_P1_REG_DFE_INIT1_L0_P1_reg_addr                                     "0xB800DE58"
#define  DFE_P1_REG_DFE_INIT1_L0_P1_reg                                          0xB800DE58
#define  DFE_P1_REG_DFE_INIT1_L0_P1_inst_addr                                    "0x0002"
#define  set_DFE_P1_REG_DFE_INIT1_L0_P1_reg(data)                                (*((volatile unsigned int*)DFE_P1_REG_DFE_INIT1_L0_P1_reg)=data)
#define  get_DFE_P1_REG_DFE_INIT1_L0_P1_reg                                      (*((volatile unsigned int*)DFE_P1_REG_DFE_INIT1_L0_P1_reg))
#define  DFE_P1_REG_DFE_INIT1_L0_P1_load_in_init_lane0_p1_shift                  (24)
#define  DFE_P1_REG_DFE_INIT1_L0_P1_init1_rev1_lane0_p1_shift                    (18)
#define  DFE_P1_REG_DFE_INIT1_L0_P1_de_video_inv_lane0_p1_shift                  (17)
#define  DFE_P1_REG_DFE_INIT1_L0_P1_de_packet_inv_lane0_p1_shift                 (16)
#define  DFE_P1_REG_DFE_INIT1_L0_P1_de_video_en_lane0_p1_shift                   (15)
#define  DFE_P1_REG_DFE_INIT1_L0_P1_de_packet_en_lane0_p1_shift                  (14)
#define  DFE_P1_REG_DFE_INIT1_L0_P1_servo_init_lane0_p1_shift                    (9)
#define  DFE_P1_REG_DFE_INIT1_L0_P1_init1_rev2_lane0_p1_shift                    (0)
#define  DFE_P1_REG_DFE_INIT1_L0_P1_load_in_init_lane0_p1_mask                   (0xFF000000)
#define  DFE_P1_REG_DFE_INIT1_L0_P1_init1_rev1_lane0_p1_mask                     (0x00FC0000)
#define  DFE_P1_REG_DFE_INIT1_L0_P1_de_video_inv_lane0_p1_mask                   (0x00020000)
#define  DFE_P1_REG_DFE_INIT1_L0_P1_de_packet_inv_lane0_p1_mask                  (0x00010000)
#define  DFE_P1_REG_DFE_INIT1_L0_P1_de_video_en_lane0_p1_mask                    (0x00008000)
#define  DFE_P1_REG_DFE_INIT1_L0_P1_de_packet_en_lane0_p1_mask                   (0x00004000)
#define  DFE_P1_REG_DFE_INIT1_L0_P1_servo_init_lane0_p1_mask                     (0x00003E00)
#define  DFE_P1_REG_DFE_INIT1_L0_P1_init1_rev2_lane0_p1_mask                     (0x000001FF)
#define  DFE_P1_REG_DFE_INIT1_L0_P1_load_in_init_lane0_p1(data)                  (0xFF000000&((data)<<24))
#define  DFE_P1_REG_DFE_INIT1_L0_P1_init1_rev1_lane0_p1(data)                    (0x00FC0000&((data)<<18))
#define  DFE_P1_REG_DFE_INIT1_L0_P1_de_video_inv_lane0_p1(data)                  (0x00020000&((data)<<17))
#define  DFE_P1_REG_DFE_INIT1_L0_P1_de_packet_inv_lane0_p1(data)                 (0x00010000&((data)<<16))
#define  DFE_P1_REG_DFE_INIT1_L0_P1_de_video_en_lane0_p1(data)                   (0x00008000&((data)<<15))
#define  DFE_P1_REG_DFE_INIT1_L0_P1_de_packet_en_lane0_p1(data)                  (0x00004000&((data)<<14))
#define  DFE_P1_REG_DFE_INIT1_L0_P1_servo_init_lane0_p1(data)                    (0x00003E00&((data)<<9))
#define  DFE_P1_REG_DFE_INIT1_L0_P1_init1_rev2_lane0_p1(data)                    (0x000001FF&(data))
#define  DFE_P1_REG_DFE_INIT1_L0_P1_get_load_in_init_lane0_p1(data)              ((0xFF000000&(data))>>24)
#define  DFE_P1_REG_DFE_INIT1_L0_P1_get_init1_rev1_lane0_p1(data)                ((0x00FC0000&(data))>>18)
#define  DFE_P1_REG_DFE_INIT1_L0_P1_get_de_video_inv_lane0_p1(data)              ((0x00020000&(data))>>17)
#define  DFE_P1_REG_DFE_INIT1_L0_P1_get_de_packet_inv_lane0_p1(data)             ((0x00010000&(data))>>16)
#define  DFE_P1_REG_DFE_INIT1_L0_P1_get_de_video_en_lane0_p1(data)               ((0x00008000&(data))>>15)
#define  DFE_P1_REG_DFE_INIT1_L0_P1_get_de_packet_en_lane0_p1(data)              ((0x00004000&(data))>>14)
#define  DFE_P1_REG_DFE_INIT1_L0_P1_get_servo_init_lane0_p1(data)                ((0x00003E00&(data))>>9)
#define  DFE_P1_REG_DFE_INIT1_L0_P1_get_init1_rev2_lane0_p1(data)                (0x000001FF&(data))

#define  DFE_P1_REG_DFE_EN_L1_P1                                                 0x1800DE60
#define  DFE_P1_REG_DFE_EN_L1_P1_reg_addr                                        "0xB800DE60"
#define  DFE_P1_REG_DFE_EN_L1_P1_reg                                             0xB800DE60
#define  DFE_P1_REG_DFE_EN_L1_P1_inst_addr                                       "0x0003"
#define  set_DFE_P1_REG_DFE_EN_L1_P1_reg(data)                                   (*((volatile unsigned int*)DFE_P1_REG_DFE_EN_L1_P1_reg)=data)
#define  get_DFE_P1_REG_DFE_EN_L1_P1_reg                                         (*((volatile unsigned int*)DFE_P1_REG_DFE_EN_L1_P1_reg))
#define  DFE_P1_REG_DFE_EN_L1_P1_clk_inv_lane1_p1_shift                          (31)
#define  DFE_P1_REG_DFE_EN_L1_P1_timer_ctrl_en_lane1_p1_shift                    (30)
#define  DFE_P1_REG_DFE_EN_L1_P1_reduce_adapt_gain_lane1_p1_shift                (28)
#define  DFE_P1_REG_DFE_EN_L1_P1_rl_det_en_lane1_p1_shift                        (27)
#define  DFE_P1_REG_DFE_EN_L1_P1_rl_det_mode_lane1_p1_shift                      (26)
#define  DFE_P1_REG_DFE_EN_L1_P1_rl_threshold_lane1_p1_shift                     (24)
#define  DFE_P1_REG_DFE_EN_L1_P1_dfe_adapt_en_lane1_p1_shift                     (16)
#define  DFE_P1_REG_DFE_EN_L1_P1_le_min_lane1_p1_shift                           (11)
#define  DFE_P1_REG_DFE_EN_L1_P1_le_init_lane1_p1_shift                          (6)
#define  DFE_P1_REG_DFE_EN_L1_P1_tap4_init_lane1_p1_shift                        (0)
#define  DFE_P1_REG_DFE_EN_L1_P1_clk_inv_lane1_p1_mask                           (0x80000000)
#define  DFE_P1_REG_DFE_EN_L1_P1_timer_ctrl_en_lane1_p1_mask                     (0x40000000)
#define  DFE_P1_REG_DFE_EN_L1_P1_reduce_adapt_gain_lane1_p1_mask                 (0x30000000)
#define  DFE_P1_REG_DFE_EN_L1_P1_rl_det_en_lane1_p1_mask                         (0x08000000)
#define  DFE_P1_REG_DFE_EN_L1_P1_rl_det_mode_lane1_p1_mask                       (0x04000000)
#define  DFE_P1_REG_DFE_EN_L1_P1_rl_threshold_lane1_p1_mask                      (0x03000000)
#define  DFE_P1_REG_DFE_EN_L1_P1_dfe_adapt_en_lane1_p1_mask                      (0x00FF0000)
#define  DFE_P1_REG_DFE_EN_L1_P1_le_min_lane1_p1_mask                            (0x0000F800)
#define  DFE_P1_REG_DFE_EN_L1_P1_le_init_lane1_p1_mask                           (0x000007C0)
#define  DFE_P1_REG_DFE_EN_L1_P1_tap4_init_lane1_p1_mask                         (0x0000003F)
#define  DFE_P1_REG_DFE_EN_L1_P1_clk_inv_lane1_p1(data)                          (0x80000000&((data)<<31))
#define  DFE_P1_REG_DFE_EN_L1_P1_timer_ctrl_en_lane1_p1(data)                    (0x40000000&((data)<<30))
#define  DFE_P1_REG_DFE_EN_L1_P1_reduce_adapt_gain_lane1_p1(data)                (0x30000000&((data)<<28))
#define  DFE_P1_REG_DFE_EN_L1_P1_rl_det_en_lane1_p1(data)                        (0x08000000&((data)<<27))
#define  DFE_P1_REG_DFE_EN_L1_P1_rl_det_mode_lane1_p1(data)                      (0x04000000&((data)<<26))
#define  DFE_P1_REG_DFE_EN_L1_P1_rl_threshold_lane1_p1(data)                     (0x03000000&((data)<<24))
#define  DFE_P1_REG_DFE_EN_L1_P1_dfe_adapt_en_lane1_p1(data)                     (0x00FF0000&((data)<<16))
#define  DFE_P1_REG_DFE_EN_L1_P1_le_min_lane1_p1(data)                           (0x0000F800&((data)<<11))
#define  DFE_P1_REG_DFE_EN_L1_P1_le_init_lane1_p1(data)                          (0x000007C0&((data)<<6))
#define  DFE_P1_REG_DFE_EN_L1_P1_tap4_init_lane1_p1(data)                        (0x0000003F&(data))
#define  DFE_P1_REG_DFE_EN_L1_P1_get_clk_inv_lane1_p1(data)                      ((0x80000000&(data))>>31)
#define  DFE_P1_REG_DFE_EN_L1_P1_get_timer_ctrl_en_lane1_p1(data)                ((0x40000000&(data))>>30)
#define  DFE_P1_REG_DFE_EN_L1_P1_get_reduce_adapt_gain_lane1_p1(data)            ((0x30000000&(data))>>28)
#define  DFE_P1_REG_DFE_EN_L1_P1_get_rl_det_en_lane1_p1(data)                    ((0x08000000&(data))>>27)
#define  DFE_P1_REG_DFE_EN_L1_P1_get_rl_det_mode_lane1_p1(data)                  ((0x04000000&(data))>>26)
#define  DFE_P1_REG_DFE_EN_L1_P1_get_rl_threshold_lane1_p1(data)                 ((0x03000000&(data))>>24)
#define  DFE_P1_REG_DFE_EN_L1_P1_get_dfe_adapt_en_lane1_p1(data)                 ((0x00FF0000&(data))>>16)
#define  DFE_P1_REG_DFE_EN_L1_P1_get_le_min_lane1_p1(data)                       ((0x0000F800&(data))>>11)
#define  DFE_P1_REG_DFE_EN_L1_P1_get_le_init_lane1_p1(data)                      ((0x000007C0&(data))>>6)
#define  DFE_P1_REG_DFE_EN_L1_P1_get_tap4_init_lane1_p1(data)                    (0x0000003F&(data))

#define  DFE_P1_REG_DFE_INIT0_L1_P1                                              0x1800DE64
#define  DFE_P1_REG_DFE_INIT0_L1_P1_reg_addr                                     "0xB800DE64"
#define  DFE_P1_REG_DFE_INIT0_L1_P1_reg                                          0xB800DE64
#define  DFE_P1_REG_DFE_INIT0_L1_P1_inst_addr                                    "0x0004"
#define  set_DFE_P1_REG_DFE_INIT0_L1_P1_reg(data)                                (*((volatile unsigned int*)DFE_P1_REG_DFE_INIT0_L1_P1_reg)=data)
#define  get_DFE_P1_REG_DFE_INIT0_L1_P1_reg                                      (*((volatile unsigned int*)DFE_P1_REG_DFE_INIT0_L1_P1_reg))
#define  DFE_P1_REG_DFE_INIT0_L1_P1_tap3_init_lane1_p1_shift                     (26)
#define  DFE_P1_REG_DFE_INIT0_L1_P1_tap2_init_lane1_p1_shift                     (20)
#define  DFE_P1_REG_DFE_INIT0_L1_P1_tap1_init_lane1_p1_shift                     (14)
#define  DFE_P1_REG_DFE_INIT0_L1_P1_tap0_init_lane1_p1_shift                     (7)
#define  DFE_P1_REG_DFE_INIT0_L1_P1_init1_rev0_lane1_p1_shift                    (4)
#define  DFE_P1_REG_DFE_INIT0_L1_P1_vth_init_lane1_p1_shift                      (0)
#define  DFE_P1_REG_DFE_INIT0_L1_P1_tap3_init_lane1_p1_mask                      (0xFC000000)
#define  DFE_P1_REG_DFE_INIT0_L1_P1_tap2_init_lane1_p1_mask                      (0x03F00000)
#define  DFE_P1_REG_DFE_INIT0_L1_P1_tap1_init_lane1_p1_mask                      (0x000FC000)
#define  DFE_P1_REG_DFE_INIT0_L1_P1_tap0_init_lane1_p1_mask                      (0x00003F80)
#define  DFE_P1_REG_DFE_INIT0_L1_P1_init1_rev0_lane1_p1_mask                     (0x00000070)
#define  DFE_P1_REG_DFE_INIT0_L1_P1_vth_init_lane1_p1_mask                       (0x0000000F)
#define  DFE_P1_REG_DFE_INIT0_L1_P1_tap3_init_lane1_p1(data)                     (0xFC000000&((data)<<26))
#define  DFE_P1_REG_DFE_INIT0_L1_P1_tap2_init_lane1_p1(data)                     (0x03F00000&((data)<<20))
#define  DFE_P1_REG_DFE_INIT0_L1_P1_tap1_init_lane1_p1(data)                     (0x000FC000&((data)<<14))
#define  DFE_P1_REG_DFE_INIT0_L1_P1_tap0_init_lane1_p1(data)                     (0x00003F80&((data)<<7))
#define  DFE_P1_REG_DFE_INIT0_L1_P1_init1_rev0_lane1_p1(data)                    (0x00000070&((data)<<4))
#define  DFE_P1_REG_DFE_INIT0_L1_P1_vth_init_lane1_p1(data)                      (0x0000000F&(data))
#define  DFE_P1_REG_DFE_INIT0_L1_P1_get_tap3_init_lane1_p1(data)                 ((0xFC000000&(data))>>26)
#define  DFE_P1_REG_DFE_INIT0_L1_P1_get_tap2_init_lane1_p1(data)                 ((0x03F00000&(data))>>20)
#define  DFE_P1_REG_DFE_INIT0_L1_P1_get_tap1_init_lane1_p1(data)                 ((0x000FC000&(data))>>14)
#define  DFE_P1_REG_DFE_INIT0_L1_P1_get_tap0_init_lane1_p1(data)                 ((0x00003F80&(data))>>7)
#define  DFE_P1_REG_DFE_INIT0_L1_P1_get_init1_rev0_lane1_p1(data)                ((0x00000070&(data))>>4)
#define  DFE_P1_REG_DFE_INIT0_L1_P1_get_vth_init_lane1_p1(data)                  (0x0000000F&(data))

#define  DFE_P1_REG_DFE_INIT1_L1_P1                                              0x1800DE68
#define  DFE_P1_REG_DFE_INIT1_L1_P1_reg_addr                                     "0xB800DE68"
#define  DFE_P1_REG_DFE_INIT1_L1_P1_reg                                          0xB800DE68
#define  DFE_P1_REG_DFE_INIT1_L1_P1_inst_addr                                    "0x0005"
#define  set_DFE_P1_REG_DFE_INIT1_L1_P1_reg(data)                                (*((volatile unsigned int*)DFE_P1_REG_DFE_INIT1_L1_P1_reg)=data)
#define  get_DFE_P1_REG_DFE_INIT1_L1_P1_reg                                      (*((volatile unsigned int*)DFE_P1_REG_DFE_INIT1_L1_P1_reg))
#define  DFE_P1_REG_DFE_INIT1_L1_P1_load_in_init_lane1_p1_shift                  (24)
#define  DFE_P1_REG_DFE_INIT1_L1_P1_init1_rev1_lane1_p1_shift                    (18)
#define  DFE_P1_REG_DFE_INIT1_L1_P1_de_video_inv_lane1_p1_shift                  (17)
#define  DFE_P1_REG_DFE_INIT1_L1_P1_de_packet_inv_lane1_p1_shift                 (16)
#define  DFE_P1_REG_DFE_INIT1_L1_P1_de_video_en_lane1_p1_shift                   (15)
#define  DFE_P1_REG_DFE_INIT1_L1_P1_de_packet_en_lane1_p1_shift                  (14)
#define  DFE_P1_REG_DFE_INIT1_L1_P1_servo_init_lane1_p1_shift                    (9)
#define  DFE_P1_REG_DFE_INIT1_L1_P1_init1_rev2_lane1_p1_shift                    (0)
#define  DFE_P1_REG_DFE_INIT1_L1_P1_load_in_init_lane1_p1_mask                   (0xFF000000)
#define  DFE_P1_REG_DFE_INIT1_L1_P1_init1_rev1_lane1_p1_mask                     (0x00FC0000)
#define  DFE_P1_REG_DFE_INIT1_L1_P1_de_video_inv_lane1_p1_mask                   (0x00020000)
#define  DFE_P1_REG_DFE_INIT1_L1_P1_de_packet_inv_lane1_p1_mask                  (0x00010000)
#define  DFE_P1_REG_DFE_INIT1_L1_P1_de_video_en_lane1_p1_mask                    (0x00008000)
#define  DFE_P1_REG_DFE_INIT1_L1_P1_de_packet_en_lane1_p1_mask                   (0x00004000)
#define  DFE_P1_REG_DFE_INIT1_L1_P1_servo_init_lane1_p1_mask                     (0x00003E00)
#define  DFE_P1_REG_DFE_INIT1_L1_P1_init1_rev2_lane1_p1_mask                     (0x000001FF)
#define  DFE_P1_REG_DFE_INIT1_L1_P1_load_in_init_lane1_p1(data)                  (0xFF000000&((data)<<24))
#define  DFE_P1_REG_DFE_INIT1_L1_P1_init1_rev1_lane1_p1(data)                    (0x00FC0000&((data)<<18))
#define  DFE_P1_REG_DFE_INIT1_L1_P1_de_video_inv_lane1_p1(data)                  (0x00020000&((data)<<17))
#define  DFE_P1_REG_DFE_INIT1_L1_P1_de_packet_inv_lane1_p1(data)                 (0x00010000&((data)<<16))
#define  DFE_P1_REG_DFE_INIT1_L1_P1_de_video_en_lane1_p1(data)                   (0x00008000&((data)<<15))
#define  DFE_P1_REG_DFE_INIT1_L1_P1_de_packet_en_lane1_p1(data)                  (0x00004000&((data)<<14))
#define  DFE_P1_REG_DFE_INIT1_L1_P1_servo_init_lane1_p1(data)                    (0x00003E00&((data)<<9))
#define  DFE_P1_REG_DFE_INIT1_L1_P1_init1_rev2_lane1_p1(data)                    (0x000001FF&(data))
#define  DFE_P1_REG_DFE_INIT1_L1_P1_get_load_in_init_lane1_p1(data)              ((0xFF000000&(data))>>24)
#define  DFE_P1_REG_DFE_INIT1_L1_P1_get_init1_rev1_lane1_p1(data)                ((0x00FC0000&(data))>>18)
#define  DFE_P1_REG_DFE_INIT1_L1_P1_get_de_video_inv_lane1_p1(data)              ((0x00020000&(data))>>17)
#define  DFE_P1_REG_DFE_INIT1_L1_P1_get_de_packet_inv_lane1_p1(data)             ((0x00010000&(data))>>16)
#define  DFE_P1_REG_DFE_INIT1_L1_P1_get_de_video_en_lane1_p1(data)               ((0x00008000&(data))>>15)
#define  DFE_P1_REG_DFE_INIT1_L1_P1_get_de_packet_en_lane1_p1(data)              ((0x00004000&(data))>>14)
#define  DFE_P1_REG_DFE_INIT1_L1_P1_get_servo_init_lane1_p1(data)                ((0x00003E00&(data))>>9)
#define  DFE_P1_REG_DFE_INIT1_L1_P1_get_init1_rev2_lane1_p1(data)                (0x000001FF&(data))

#define  DFE_P1_REG_DFE_EN_L2_P1                                                 0x1800DE70
#define  DFE_P1_REG_DFE_EN_L2_P1_reg_addr                                        "0xB800DE70"
#define  DFE_P1_REG_DFE_EN_L2_P1_reg                                             0xB800DE70
#define  DFE_P1_REG_DFE_EN_L2_P1_inst_addr                                       "0x0006"
#define  set_DFE_P1_REG_DFE_EN_L2_P1_reg(data)                                   (*((volatile unsigned int*)DFE_P1_REG_DFE_EN_L2_P1_reg)=data)
#define  get_DFE_P1_REG_DFE_EN_L2_P1_reg                                         (*((volatile unsigned int*)DFE_P1_REG_DFE_EN_L2_P1_reg))
#define  DFE_P1_REG_DFE_EN_L2_P1_clk_inv_lane2_p1_shift                          (31)
#define  DFE_P1_REG_DFE_EN_L2_P1_timer_ctrl_en_lane2_p1_shift                    (30)
#define  DFE_P1_REG_DFE_EN_L2_P1_reduce_adapt_gain_lane2_p1_shift                (28)
#define  DFE_P1_REG_DFE_EN_L2_P1_rl_det_en_lane2_p1_shift                        (27)
#define  DFE_P1_REG_DFE_EN_L2_P1_rl_det_mode_lane2_p1_shift                      (26)
#define  DFE_P1_REG_DFE_EN_L2_P1_rl_threshold_lane2_p1_shift                     (24)
#define  DFE_P1_REG_DFE_EN_L2_P1_dfe_adapt_en_lane2_p1_shift                     (16)
#define  DFE_P1_REG_DFE_EN_L2_P1_le_min_lane2_p1_shift                           (11)
#define  DFE_P1_REG_DFE_EN_L2_P1_le_init_lane2_p1_shift                          (6)
#define  DFE_P1_REG_DFE_EN_L2_P1_tap4_init_lane2_p1_shift                        (0)
#define  DFE_P1_REG_DFE_EN_L2_P1_clk_inv_lane2_p1_mask                           (0x80000000)
#define  DFE_P1_REG_DFE_EN_L2_P1_timer_ctrl_en_lane2_p1_mask                     (0x40000000)
#define  DFE_P1_REG_DFE_EN_L2_P1_reduce_adapt_gain_lane2_p1_mask                 (0x30000000)
#define  DFE_P1_REG_DFE_EN_L2_P1_rl_det_en_lane2_p1_mask                         (0x08000000)
#define  DFE_P1_REG_DFE_EN_L2_P1_rl_det_mode_lane2_p1_mask                       (0x04000000)
#define  DFE_P1_REG_DFE_EN_L2_P1_rl_threshold_lane2_p1_mask                      (0x03000000)
#define  DFE_P1_REG_DFE_EN_L2_P1_dfe_adapt_en_lane2_p1_mask                      (0x00FF0000)
#define  DFE_P1_REG_DFE_EN_L2_P1_le_min_lane2_p1_mask                            (0x0000F800)
#define  DFE_P1_REG_DFE_EN_L2_P1_le_init_lane2_p1_mask                           (0x000007C0)
#define  DFE_P1_REG_DFE_EN_L2_P1_tap4_init_lane2_p1_mask                         (0x0000003F)
#define  DFE_P1_REG_DFE_EN_L2_P1_clk_inv_lane2_p1(data)                          (0x80000000&((data)<<31))
#define  DFE_P1_REG_DFE_EN_L2_P1_timer_ctrl_en_lane2_p1(data)                    (0x40000000&((data)<<30))
#define  DFE_P1_REG_DFE_EN_L2_P1_reduce_adapt_gain_lane2_p1(data)                (0x30000000&((data)<<28))
#define  DFE_P1_REG_DFE_EN_L2_P1_rl_det_en_lane2_p1(data)                        (0x08000000&((data)<<27))
#define  DFE_P1_REG_DFE_EN_L2_P1_rl_det_mode_lane2_p1(data)                      (0x04000000&((data)<<26))
#define  DFE_P1_REG_DFE_EN_L2_P1_rl_threshold_lane2_p1(data)                     (0x03000000&((data)<<24))
#define  DFE_P1_REG_DFE_EN_L2_P1_dfe_adapt_en_lane2_p1(data)                     (0x00FF0000&((data)<<16))
#define  DFE_P1_REG_DFE_EN_L2_P1_le_min_lane2_p1(data)                           (0x0000F800&((data)<<11))
#define  DFE_P1_REG_DFE_EN_L2_P1_le_init_lane2_p1(data)                          (0x000007C0&((data)<<6))
#define  DFE_P1_REG_DFE_EN_L2_P1_tap4_init_lane2_p1(data)                        (0x0000003F&(data))
#define  DFE_P1_REG_DFE_EN_L2_P1_get_clk_inv_lane2_p1(data)                      ((0x80000000&(data))>>31)
#define  DFE_P1_REG_DFE_EN_L2_P1_get_timer_ctrl_en_lane2_p1(data)                ((0x40000000&(data))>>30)
#define  DFE_P1_REG_DFE_EN_L2_P1_get_reduce_adapt_gain_lane2_p1(data)            ((0x30000000&(data))>>28)
#define  DFE_P1_REG_DFE_EN_L2_P1_get_rl_det_en_lane2_p1(data)                    ((0x08000000&(data))>>27)
#define  DFE_P1_REG_DFE_EN_L2_P1_get_rl_det_mode_lane2_p1(data)                  ((0x04000000&(data))>>26)
#define  DFE_P1_REG_DFE_EN_L2_P1_get_rl_threshold_lane2_p1(data)                 ((0x03000000&(data))>>24)
#define  DFE_P1_REG_DFE_EN_L2_P1_get_dfe_adapt_en_lane2_p1(data)                 ((0x00FF0000&(data))>>16)
#define  DFE_P1_REG_DFE_EN_L2_P1_get_le_min_lane2_p1(data)                       ((0x0000F800&(data))>>11)
#define  DFE_P1_REG_DFE_EN_L2_P1_get_le_init_lane2_p1(data)                      ((0x000007C0&(data))>>6)
#define  DFE_P1_REG_DFE_EN_L2_P1_get_tap4_init_lane2_p1(data)                    (0x0000003F&(data))

#define  DFE_P1_REG_DFE_INIT0_L2_P1                                              0x1800DE74
#define  DFE_P1_REG_DFE_INIT0_L2_P1_reg_addr                                     "0xB800DE74"
#define  DFE_P1_REG_DFE_INIT0_L2_P1_reg                                          0xB800DE74
#define  DFE_P1_REG_DFE_INIT0_L2_P1_inst_addr                                    "0x0007"
#define  set_DFE_P1_REG_DFE_INIT0_L2_P1_reg(data)                                (*((volatile unsigned int*)DFE_P1_REG_DFE_INIT0_L2_P1_reg)=data)
#define  get_DFE_P1_REG_DFE_INIT0_L2_P1_reg                                      (*((volatile unsigned int*)DFE_P1_REG_DFE_INIT0_L2_P1_reg))
#define  DFE_P1_REG_DFE_INIT0_L2_P1_tap3_init_lane2_p1_shift                     (26)
#define  DFE_P1_REG_DFE_INIT0_L2_P1_tap2_init_lane2_p1_shift                     (20)
#define  DFE_P1_REG_DFE_INIT0_L2_P1_tap1_init_lane2_p1_shift                     (14)
#define  DFE_P1_REG_DFE_INIT0_L2_P1_tap0_init_lane2_p1_shift                     (7)
#define  DFE_P1_REG_DFE_INIT0_L2_P1_init1_rev0_lane2_p1_shift                    (4)
#define  DFE_P1_REG_DFE_INIT0_L2_P1_vth_init_lane2_p1_shift                      (0)
#define  DFE_P1_REG_DFE_INIT0_L2_P1_tap3_init_lane2_p1_mask                      (0xFC000000)
#define  DFE_P1_REG_DFE_INIT0_L2_P1_tap2_init_lane2_p1_mask                      (0x03F00000)
#define  DFE_P1_REG_DFE_INIT0_L2_P1_tap1_init_lane2_p1_mask                      (0x000FC000)
#define  DFE_P1_REG_DFE_INIT0_L2_P1_tap0_init_lane2_p1_mask                      (0x00003F80)
#define  DFE_P1_REG_DFE_INIT0_L2_P1_init1_rev0_lane2_p1_mask                     (0x00000070)
#define  DFE_P1_REG_DFE_INIT0_L2_P1_vth_init_lane2_p1_mask                       (0x0000000F)
#define  DFE_P1_REG_DFE_INIT0_L2_P1_tap3_init_lane2_p1(data)                     (0xFC000000&((data)<<26))
#define  DFE_P1_REG_DFE_INIT0_L2_P1_tap2_init_lane2_p1(data)                     (0x03F00000&((data)<<20))
#define  DFE_P1_REG_DFE_INIT0_L2_P1_tap1_init_lane2_p1(data)                     (0x000FC000&((data)<<14))
#define  DFE_P1_REG_DFE_INIT0_L2_P1_tap0_init_lane2_p1(data)                     (0x00003F80&((data)<<7))
#define  DFE_P1_REG_DFE_INIT0_L2_P1_init1_rev0_lane2_p1(data)                    (0x00000070&((data)<<4))
#define  DFE_P1_REG_DFE_INIT0_L2_P1_vth_init_lane2_p1(data)                      (0x0000000F&(data))
#define  DFE_P1_REG_DFE_INIT0_L2_P1_get_tap3_init_lane2_p1(data)                 ((0xFC000000&(data))>>26)
#define  DFE_P1_REG_DFE_INIT0_L2_P1_get_tap2_init_lane2_p1(data)                 ((0x03F00000&(data))>>20)
#define  DFE_P1_REG_DFE_INIT0_L2_P1_get_tap1_init_lane2_p1(data)                 ((0x000FC000&(data))>>14)
#define  DFE_P1_REG_DFE_INIT0_L2_P1_get_tap0_init_lane2_p1(data)                 ((0x00003F80&(data))>>7)
#define  DFE_P1_REG_DFE_INIT0_L2_P1_get_init1_rev0_lane2_p1(data)                ((0x00000070&(data))>>4)
#define  DFE_P1_REG_DFE_INIT0_L2_P1_get_vth_init_lane2_p1(data)                  (0x0000000F&(data))

#define  DFE_P1_REG_DFE_INIT1_L2_P1                                              0x1800DE78
#define  DFE_P1_REG_DFE_INIT1_L2_P1_reg_addr                                     "0xB800DE78"
#define  DFE_P1_REG_DFE_INIT1_L2_P1_reg                                          0xB800DE78
#define  DFE_P1_REG_DFE_INIT1_L2_P1_inst_addr                                    "0x0008"
#define  set_DFE_P1_REG_DFE_INIT1_L2_P1_reg(data)                                (*((volatile unsigned int*)DFE_P1_REG_DFE_INIT1_L2_P1_reg)=data)
#define  get_DFE_P1_REG_DFE_INIT1_L2_P1_reg                                      (*((volatile unsigned int*)DFE_P1_REG_DFE_INIT1_L2_P1_reg))
#define  DFE_P1_REG_DFE_INIT1_L2_P1_load_in_init_lane2_p1_shift                  (24)
#define  DFE_P1_REG_DFE_INIT1_L2_P1_init1_rev1_lane2_p1_shift                    (18)
#define  DFE_P1_REG_DFE_INIT1_L2_P1_de_video_inv_lane2_p1_shift                  (17)
#define  DFE_P1_REG_DFE_INIT1_L2_P1_de_packet_inv_lane2_p1_shift                 (16)
#define  DFE_P1_REG_DFE_INIT1_L2_P1_de_video_en_lane2_p1_shift                   (15)
#define  DFE_P1_REG_DFE_INIT1_L2_P1_de_packet_en_lane2_p1_shift                  (14)
#define  DFE_P1_REG_DFE_INIT1_L2_P1_servo_init_lane2_p1_shift                    (9)
#define  DFE_P1_REG_DFE_INIT1_L2_P1_init1_rev2_lane2_p1_shift                    (0)
#define  DFE_P1_REG_DFE_INIT1_L2_P1_load_in_init_lane2_p1_mask                   (0xFF000000)
#define  DFE_P1_REG_DFE_INIT1_L2_P1_init1_rev1_lane2_p1_mask                     (0x00FC0000)
#define  DFE_P1_REG_DFE_INIT1_L2_P1_de_video_inv_lane2_p1_mask                   (0x00020000)
#define  DFE_P1_REG_DFE_INIT1_L2_P1_de_packet_inv_lane2_p1_mask                  (0x00010000)
#define  DFE_P1_REG_DFE_INIT1_L2_P1_de_video_en_lane2_p1_mask                    (0x00008000)
#define  DFE_P1_REG_DFE_INIT1_L2_P1_de_packet_en_lane2_p1_mask                   (0x00004000)
#define  DFE_P1_REG_DFE_INIT1_L2_P1_servo_init_lane2_p1_mask                     (0x00003E00)
#define  DFE_P1_REG_DFE_INIT1_L2_P1_init1_rev2_lane2_p1_mask                     (0x000001FF)
#define  DFE_P1_REG_DFE_INIT1_L2_P1_load_in_init_lane2_p1(data)                  (0xFF000000&((data)<<24))
#define  DFE_P1_REG_DFE_INIT1_L2_P1_init1_rev1_lane2_p1(data)                    (0x00FC0000&((data)<<18))
#define  DFE_P1_REG_DFE_INIT1_L2_P1_de_video_inv_lane2_p1(data)                  (0x00020000&((data)<<17))
#define  DFE_P1_REG_DFE_INIT1_L2_P1_de_packet_inv_lane2_p1(data)                 (0x00010000&((data)<<16))
#define  DFE_P1_REG_DFE_INIT1_L2_P1_de_video_en_lane2_p1(data)                   (0x00008000&((data)<<15))
#define  DFE_P1_REG_DFE_INIT1_L2_P1_de_packet_en_lane2_p1(data)                  (0x00004000&((data)<<14))
#define  DFE_P1_REG_DFE_INIT1_L2_P1_servo_init_lane2_p1(data)                    (0x00003E00&((data)<<9))
#define  DFE_P1_REG_DFE_INIT1_L2_P1_init1_rev2_lane2_p1(data)                    (0x000001FF&(data))
#define  DFE_P1_REG_DFE_INIT1_L2_P1_get_load_in_init_lane2_p1(data)              ((0xFF000000&(data))>>24)
#define  DFE_P1_REG_DFE_INIT1_L2_P1_get_init1_rev1_lane2_p1(data)                ((0x00FC0000&(data))>>18)
#define  DFE_P1_REG_DFE_INIT1_L2_P1_get_de_video_inv_lane2_p1(data)              ((0x00020000&(data))>>17)
#define  DFE_P1_REG_DFE_INIT1_L2_P1_get_de_packet_inv_lane2_p1(data)             ((0x00010000&(data))>>16)
#define  DFE_P1_REG_DFE_INIT1_L2_P1_get_de_video_en_lane2_p1(data)               ((0x00008000&(data))>>15)
#define  DFE_P1_REG_DFE_INIT1_L2_P1_get_de_packet_en_lane2_p1(data)              ((0x00004000&(data))>>14)
#define  DFE_P1_REG_DFE_INIT1_L2_P1_get_servo_init_lane2_p1(data)                ((0x00003E00&(data))>>9)
#define  DFE_P1_REG_DFE_INIT1_L2_P1_get_init1_rev2_lane2_p1(data)                (0x000001FF&(data))

#define  DFE_P1_REG_DFE_MODE_P1                                                  0x1800DE80
#define  DFE_P1_REG_DFE_MODE_P1_reg_addr                                         "0xB800DE80"
#define  DFE_P1_REG_DFE_MODE_P1_reg                                              0xB800DE80
#define  DFE_P1_REG_DFE_MODE_P1_inst_addr                                        "0x0009"
#define  set_DFE_P1_REG_DFE_MODE_P1_reg(data)                                    (*((volatile unsigned int*)DFE_P1_REG_DFE_MODE_P1_reg)=data)
#define  get_DFE_P1_REG_DFE_MODE_P1_reg                                          (*((volatile unsigned int*)DFE_P1_REG_DFE_MODE_P1_reg))
#define  DFE_P1_REG_DFE_MODE_P1_adapt_mode_p1_shift                              (30)
#define  DFE_P1_REG_DFE_MODE_P1_edge_det_mode_p1_shift                           (29)
#define  DFE_P1_REG_DFE_MODE_P1_transition_only_p1_shift                         (28)
#define  DFE_P1_REG_DFE_MODE_P1_le_auto_reload_p1_shift                          (27)
#define  DFE_P1_REG_DFE_MODE_P1_tap1_delay_p1_shift                              (24)
#define  DFE_P1_REG_DFE_MODE_P1_tap24_delay_p1_shift                             (21)
#define  DFE_P1_REG_DFE_MODE_P1_le_delay_p1_shift                                (18)
#define  DFE_P1_REG_DFE_MODE_P1_servo_delay_p1_shift                             (16)
#define  DFE_P1_REG_DFE_MODE_P1_gray_en_p1_shift                                 (8)
#define  DFE_P1_REG_DFE_MODE_P1_dfe_adapt_rstb_p1_shift                          (4)
#define  DFE_P1_REG_DFE_MODE_P1_tap0_trans_p1_shift                              (3)
#define  DFE_P1_REG_DFE_MODE_P1_tap0_notrans_p1_shift                            (2)
#define  DFE_P1_REG_DFE_MODE_P1_servo_notrans_p1_shift                           (1)
#define  DFE_P1_REG_DFE_MODE_P1_servo_trans_p1_shift                             (0)
#define  DFE_P1_REG_DFE_MODE_P1_adapt_mode_p1_mask                               (0xC0000000)
#define  DFE_P1_REG_DFE_MODE_P1_edge_det_mode_p1_mask                            (0x20000000)
#define  DFE_P1_REG_DFE_MODE_P1_transition_only_p1_mask                          (0x10000000)
#define  DFE_P1_REG_DFE_MODE_P1_le_auto_reload_p1_mask                           (0x08000000)
#define  DFE_P1_REG_DFE_MODE_P1_tap1_delay_p1_mask                               (0x07000000)
#define  DFE_P1_REG_DFE_MODE_P1_tap24_delay_p1_mask                              (0x00E00000)
#define  DFE_P1_REG_DFE_MODE_P1_le_delay_p1_mask                                 (0x001C0000)
#define  DFE_P1_REG_DFE_MODE_P1_servo_delay_p1_mask                              (0x00030000)
#define  DFE_P1_REG_DFE_MODE_P1_gray_en_p1_mask                                  (0x0000FF00)
#define  DFE_P1_REG_DFE_MODE_P1_dfe_adapt_rstb_p1_mask                           (0x000000F0)
#define  DFE_P1_REG_DFE_MODE_P1_tap0_trans_p1_mask                               (0x00000008)
#define  DFE_P1_REG_DFE_MODE_P1_tap0_notrans_p1_mask                             (0x00000004)
#define  DFE_P1_REG_DFE_MODE_P1_servo_notrans_p1_mask                            (0x00000002)
#define  DFE_P1_REG_DFE_MODE_P1_servo_trans_p1_mask                              (0x00000001)
#define  DFE_P1_REG_DFE_MODE_P1_adapt_mode_p1(data)                              (0xC0000000&((data)<<30))
#define  DFE_P1_REG_DFE_MODE_P1_edge_det_mode_p1(data)                           (0x20000000&((data)<<29))
#define  DFE_P1_REG_DFE_MODE_P1_transition_only_p1(data)                         (0x10000000&((data)<<28))
#define  DFE_P1_REG_DFE_MODE_P1_le_auto_reload_p1(data)                          (0x08000000&((data)<<27))
#define  DFE_P1_REG_DFE_MODE_P1_tap1_delay_p1(data)                              (0x07000000&((data)<<24))
#define  DFE_P1_REG_DFE_MODE_P1_tap24_delay_p1(data)                             (0x00E00000&((data)<<21))
#define  DFE_P1_REG_DFE_MODE_P1_le_delay_p1(data)                                (0x001C0000&((data)<<18))
#define  DFE_P1_REG_DFE_MODE_P1_servo_delay_p1(data)                             (0x00030000&((data)<<16))
#define  DFE_P1_REG_DFE_MODE_P1_gray_en_p1(data)                                 (0x0000FF00&((data)<<8))
#define  DFE_P1_REG_DFE_MODE_P1_dfe_adapt_rstb_p1(data)                          (0x000000F0&((data)<<4))
#define  DFE_P1_REG_DFE_MODE_P1_tap0_trans_p1(data)                              (0x00000008&((data)<<3))
#define  DFE_P1_REG_DFE_MODE_P1_tap0_notrans_p1(data)                            (0x00000004&((data)<<2))
#define  DFE_P1_REG_DFE_MODE_P1_servo_notrans_p1(data)                           (0x00000002&((data)<<1))
#define  DFE_P1_REG_DFE_MODE_P1_servo_trans_p1(data)                             (0x00000001&(data))
#define  DFE_P1_REG_DFE_MODE_P1_get_adapt_mode_p1(data)                          ((0xC0000000&(data))>>30)
#define  DFE_P1_REG_DFE_MODE_P1_get_edge_det_mode_p1(data)                       ((0x20000000&(data))>>29)
#define  DFE_P1_REG_DFE_MODE_P1_get_transition_only_p1(data)                     ((0x10000000&(data))>>28)
#define  DFE_P1_REG_DFE_MODE_P1_get_le_auto_reload_p1(data)                      ((0x08000000&(data))>>27)
#define  DFE_P1_REG_DFE_MODE_P1_get_tap1_delay_p1(data)                          ((0x07000000&(data))>>24)
#define  DFE_P1_REG_DFE_MODE_P1_get_tap24_delay_p1(data)                         ((0x00E00000&(data))>>21)
#define  DFE_P1_REG_DFE_MODE_P1_get_le_delay_p1(data)                            ((0x001C0000&(data))>>18)
#define  DFE_P1_REG_DFE_MODE_P1_get_servo_delay_p1(data)                         ((0x00030000&(data))>>16)
#define  DFE_P1_REG_DFE_MODE_P1_get_gray_en_p1(data)                             ((0x0000FF00&(data))>>8)
#define  DFE_P1_REG_DFE_MODE_P1_get_dfe_adapt_rstb_p1(data)                      ((0x000000F0&(data))>>4)
#define  DFE_P1_REG_DFE_MODE_P1_get_tap0_trans_p1(data)                          ((0x00000008&(data))>>3)
#define  DFE_P1_REG_DFE_MODE_P1_get_tap0_notrans_p1(data)                        ((0x00000004&(data))>>2)
#define  DFE_P1_REG_DFE_MODE_P1_get_servo_notrans_p1(data)                       ((0x00000002&(data))>>1)
#define  DFE_P1_REG_DFE_MODE_P1_get_servo_trans_p1(data)                         (0x00000001&(data))

#define  DFE_P1_REG_DFE_GAIN_P1                                                  0x1800DE84
#define  DFE_P1_REG_DFE_GAIN_P1_reg_addr                                         "0xB800DE84"
#define  DFE_P1_REG_DFE_GAIN_P1_reg                                              0xB800DE84
#define  DFE_P1_REG_DFE_GAIN_P1_inst_addr                                        "0x000A"
#define  set_DFE_P1_REG_DFE_GAIN_P1_reg(data)                                    (*((volatile unsigned int*)DFE_P1_REG_DFE_GAIN_P1_reg)=data)
#define  get_DFE_P1_REG_DFE_GAIN_P1_reg                                          (*((volatile unsigned int*)DFE_P1_REG_DFE_GAIN_P1_reg))
#define  DFE_P1_REG_DFE_GAIN_P1_tap0_gain_p1_shift                               (29)
#define  DFE_P1_REG_DFE_GAIN_P1_tap1_gain_p1_shift                               (26)
#define  DFE_P1_REG_DFE_GAIN_P1_tap2_gain_p1_shift                               (23)
#define  DFE_P1_REG_DFE_GAIN_P1_tap3_gain_p1_shift                               (20)
#define  DFE_P1_REG_DFE_GAIN_P1_tap4_gain_p1_shift                               (17)
#define  DFE_P1_REG_DFE_GAIN_P1_servo_gain_p1_shift                              (14)
#define  DFE_P1_REG_DFE_GAIN_P1_le_gain1_p1_shift                                (11)
#define  DFE_P1_REG_DFE_GAIN_P1_le_gain2_p1_shift                                (8)
#define  DFE_P1_REG_DFE_GAIN_P1_le2_sign_p1_shift                                (7)
#define  DFE_P1_REG_DFE_GAIN_P1_le_gain_prec_p1_shift                            (4)
#define  DFE_P1_REG_DFE_GAIN_P1_le_prec_sign_p1_shift                            (3)
#define  DFE_P1_REG_DFE_GAIN_P1_trans_rlength_p1_shift                           (0)
#define  DFE_P1_REG_DFE_GAIN_P1_tap0_gain_p1_mask                                (0xE0000000)
#define  DFE_P1_REG_DFE_GAIN_P1_tap1_gain_p1_mask                                (0x1C000000)
#define  DFE_P1_REG_DFE_GAIN_P1_tap2_gain_p1_mask                                (0x03800000)
#define  DFE_P1_REG_DFE_GAIN_P1_tap3_gain_p1_mask                                (0x00700000)
#define  DFE_P1_REG_DFE_GAIN_P1_tap4_gain_p1_mask                                (0x000E0000)
#define  DFE_P1_REG_DFE_GAIN_P1_servo_gain_p1_mask                               (0x0001C000)
#define  DFE_P1_REG_DFE_GAIN_P1_le_gain1_p1_mask                                 (0x00003800)
#define  DFE_P1_REG_DFE_GAIN_P1_le_gain2_p1_mask                                 (0x00000700)
#define  DFE_P1_REG_DFE_GAIN_P1_le2_sign_p1_mask                                 (0x00000080)
#define  DFE_P1_REG_DFE_GAIN_P1_le_gain_prec_p1_mask                             (0x00000070)
#define  DFE_P1_REG_DFE_GAIN_P1_le_prec_sign_p1_mask                             (0x00000008)
#define  DFE_P1_REG_DFE_GAIN_P1_trans_rlength_p1_mask                            (0x00000007)
#define  DFE_P1_REG_DFE_GAIN_P1_tap0_gain_p1(data)                               (0xE0000000&((data)<<29))
#define  DFE_P1_REG_DFE_GAIN_P1_tap1_gain_p1(data)                               (0x1C000000&((data)<<26))
#define  DFE_P1_REG_DFE_GAIN_P1_tap2_gain_p1(data)                               (0x03800000&((data)<<23))
#define  DFE_P1_REG_DFE_GAIN_P1_tap3_gain_p1(data)                               (0x00700000&((data)<<20))
#define  DFE_P1_REG_DFE_GAIN_P1_tap4_gain_p1(data)                               (0x000E0000&((data)<<17))
#define  DFE_P1_REG_DFE_GAIN_P1_servo_gain_p1(data)                              (0x0001C000&((data)<<14))
#define  DFE_P1_REG_DFE_GAIN_P1_le_gain1_p1(data)                                (0x00003800&((data)<<11))
#define  DFE_P1_REG_DFE_GAIN_P1_le_gain2_p1(data)                                (0x00000700&((data)<<8))
#define  DFE_P1_REG_DFE_GAIN_P1_le2_sign_p1(data)                                (0x00000080&((data)<<7))
#define  DFE_P1_REG_DFE_GAIN_P1_le_gain_prec_p1(data)                            (0x00000070&((data)<<4))
#define  DFE_P1_REG_DFE_GAIN_P1_le_prec_sign_p1(data)                            (0x00000008&((data)<<3))
#define  DFE_P1_REG_DFE_GAIN_P1_trans_rlength_p1(data)                           (0x00000007&(data))
#define  DFE_P1_REG_DFE_GAIN_P1_get_tap0_gain_p1(data)                           ((0xE0000000&(data))>>29)
#define  DFE_P1_REG_DFE_GAIN_P1_get_tap1_gain_p1(data)                           ((0x1C000000&(data))>>26)
#define  DFE_P1_REG_DFE_GAIN_P1_get_tap2_gain_p1(data)                           ((0x03800000&(data))>>23)
#define  DFE_P1_REG_DFE_GAIN_P1_get_tap3_gain_p1(data)                           ((0x00700000&(data))>>20)
#define  DFE_P1_REG_DFE_GAIN_P1_get_tap4_gain_p1(data)                           ((0x000E0000&(data))>>17)
#define  DFE_P1_REG_DFE_GAIN_P1_get_servo_gain_p1(data)                          ((0x0001C000&(data))>>14)
#define  DFE_P1_REG_DFE_GAIN_P1_get_le_gain1_p1(data)                            ((0x00003800&(data))>>11)
#define  DFE_P1_REG_DFE_GAIN_P1_get_le_gain2_p1(data)                            ((0x00000700&(data))>>8)
#define  DFE_P1_REG_DFE_GAIN_P1_get_le2_sign_p1(data)                            ((0x00000080&(data))>>7)
#define  DFE_P1_REG_DFE_GAIN_P1_get_le_gain_prec_p1(data)                        ((0x00000070&(data))>>4)
#define  DFE_P1_REG_DFE_GAIN_P1_get_le_prec_sign_p1(data)                        ((0x00000008&(data))>>3)
#define  DFE_P1_REG_DFE_GAIN_P1_get_trans_rlength_p1(data)                       (0x00000007&(data))

#define  DFE_P1_REG_DFE_LIMIT0_P1                                                0x1800DE88
#define  DFE_P1_REG_DFE_LIMIT0_P1_reg_addr                                       "0xB800DE88"
#define  DFE_P1_REG_DFE_LIMIT0_P1_reg                                            0xB800DE88
#define  DFE_P1_REG_DFE_LIMIT0_P1_inst_addr                                      "0x000B"
#define  set_DFE_P1_REG_DFE_LIMIT0_P1_reg(data)                                  (*((volatile unsigned int*)DFE_P1_REG_DFE_LIMIT0_P1_reg)=data)
#define  get_DFE_P1_REG_DFE_LIMIT0_P1_reg                                        (*((volatile unsigned int*)DFE_P1_REG_DFE_LIMIT0_P1_reg))
#define  DFE_P1_REG_DFE_LIMIT0_P1_limit0_rev_p1_shift                            (26)
#define  DFE_P1_REG_DFE_LIMIT0_P1_tap1_min_p1_shift                              (20)
#define  DFE_P1_REG_DFE_LIMIT0_P1_tap2_max_p1_shift                              (15)
#define  DFE_P1_REG_DFE_LIMIT0_P1_tap2_min_p1_shift                              (10)
#define  DFE_P1_REG_DFE_LIMIT0_P1_tap3_max_p1_shift                              (5)
#define  DFE_P1_REG_DFE_LIMIT0_P1_tap3_min_p1_shift                              (0)
#define  DFE_P1_REG_DFE_LIMIT0_P1_limit0_rev_p1_mask                             (0xFC000000)
#define  DFE_P1_REG_DFE_LIMIT0_P1_tap1_min_p1_mask                               (0x03F00000)
#define  DFE_P1_REG_DFE_LIMIT0_P1_tap2_max_p1_mask                               (0x000F8000)
#define  DFE_P1_REG_DFE_LIMIT0_P1_tap2_min_p1_mask                               (0x00007C00)
#define  DFE_P1_REG_DFE_LIMIT0_P1_tap3_max_p1_mask                               (0x000003E0)
#define  DFE_P1_REG_DFE_LIMIT0_P1_tap3_min_p1_mask                               (0x0000001F)
#define  DFE_P1_REG_DFE_LIMIT0_P1_limit0_rev_p1(data)                            (0xFC000000&((data)<<26))
#define  DFE_P1_REG_DFE_LIMIT0_P1_tap1_min_p1(data)                              (0x03F00000&((data)<<20))
#define  DFE_P1_REG_DFE_LIMIT0_P1_tap2_max_p1(data)                              (0x000F8000&((data)<<15))
#define  DFE_P1_REG_DFE_LIMIT0_P1_tap2_min_p1(data)                              (0x00007C00&((data)<<10))
#define  DFE_P1_REG_DFE_LIMIT0_P1_tap3_max_p1(data)                              (0x000003E0&((data)<<5))
#define  DFE_P1_REG_DFE_LIMIT0_P1_tap3_min_p1(data)                              (0x0000001F&(data))
#define  DFE_P1_REG_DFE_LIMIT0_P1_get_limit0_rev_p1(data)                        ((0xFC000000&(data))>>26)
#define  DFE_P1_REG_DFE_LIMIT0_P1_get_tap1_min_p1(data)                          ((0x03F00000&(data))>>20)
#define  DFE_P1_REG_DFE_LIMIT0_P1_get_tap2_max_p1(data)                          ((0x000F8000&(data))>>15)
#define  DFE_P1_REG_DFE_LIMIT0_P1_get_tap2_min_p1(data)                          ((0x00007C00&(data))>>10)
#define  DFE_P1_REG_DFE_LIMIT0_P1_get_tap3_max_p1(data)                          ((0x000003E0&(data))>>5)
#define  DFE_P1_REG_DFE_LIMIT0_P1_get_tap3_min_p1(data)                          (0x0000001F&(data))

#define  DFE_P1_REG_DFE_LIMIT1_P1                                                0x1800DE8C
#define  DFE_P1_REG_DFE_LIMIT1_P1_reg_addr                                       "0xB800DE8C"
#define  DFE_P1_REG_DFE_LIMIT1_P1_reg                                            0xB800DE8C
#define  DFE_P1_REG_DFE_LIMIT1_P1_inst_addr                                      "0x000C"
#define  set_DFE_P1_REG_DFE_LIMIT1_P1_reg(data)                                  (*((volatile unsigned int*)DFE_P1_REG_DFE_LIMIT1_P1_reg)=data)
#define  get_DFE_P1_REG_DFE_LIMIT1_P1_reg                                        (*((volatile unsigned int*)DFE_P1_REG_DFE_LIMIT1_P1_reg))
#define  DFE_P1_REG_DFE_LIMIT1_P1_tap4_max_p1_shift                              (27)
#define  DFE_P1_REG_DFE_LIMIT1_P1_tap4_min_p1_shift                              (22)
#define  DFE_P1_REG_DFE_LIMIT1_P1_vth_min_p1_shift                               (19)
#define  DFE_P1_REG_DFE_LIMIT1_P1_vth_max_p1_shift                               (15)
#define  DFE_P1_REG_DFE_LIMIT1_P1_vth_threshold_p1_shift                         (12)
#define  DFE_P1_REG_DFE_LIMIT1_P1_tap0_threshold_p1_shift                        (8)
#define  DFE_P1_REG_DFE_LIMIT1_P1_tap0_adjust_p1_shift                           (6)
#define  DFE_P1_REG_DFE_LIMIT1_P1_tap1_trans_p1_shift                            (5)
#define  DFE_P1_REG_DFE_LIMIT1_P1_edge_last_notrans_p1_shift                     (4)
#define  DFE_P1_REG_DFE_LIMIT1_P1_limit1_rev_p1_shift                            (0)
#define  DFE_P1_REG_DFE_LIMIT1_P1_tap4_max_p1_mask                               (0xF8000000)
#define  DFE_P1_REG_DFE_LIMIT1_P1_tap4_min_p1_mask                               (0x07C00000)
#define  DFE_P1_REG_DFE_LIMIT1_P1_vth_min_p1_mask                                (0x00380000)
#define  DFE_P1_REG_DFE_LIMIT1_P1_vth_max_p1_mask                                (0x00078000)
#define  DFE_P1_REG_DFE_LIMIT1_P1_vth_threshold_p1_mask                          (0x00007000)
#define  DFE_P1_REG_DFE_LIMIT1_P1_tap0_threshold_p1_mask                         (0x00000F00)
#define  DFE_P1_REG_DFE_LIMIT1_P1_tap0_adjust_p1_mask                            (0x000000C0)
#define  DFE_P1_REG_DFE_LIMIT1_P1_tap1_trans_p1_mask                             (0x00000020)
#define  DFE_P1_REG_DFE_LIMIT1_P1_edge_last_notrans_p1_mask                      (0x00000010)
#define  DFE_P1_REG_DFE_LIMIT1_P1_limit1_rev_p1_mask                             (0x0000000F)
#define  DFE_P1_REG_DFE_LIMIT1_P1_tap4_max_p1(data)                              (0xF8000000&((data)<<27))
#define  DFE_P1_REG_DFE_LIMIT1_P1_tap4_min_p1(data)                              (0x07C00000&((data)<<22))
#define  DFE_P1_REG_DFE_LIMIT1_P1_vth_min_p1(data)                               (0x00380000&((data)<<19))
#define  DFE_P1_REG_DFE_LIMIT1_P1_vth_max_p1(data)                               (0x00078000&((data)<<15))
#define  DFE_P1_REG_DFE_LIMIT1_P1_vth_threshold_p1(data)                         (0x00007000&((data)<<12))
#define  DFE_P1_REG_DFE_LIMIT1_P1_tap0_threshold_p1(data)                        (0x00000F00&((data)<<8))
#define  DFE_P1_REG_DFE_LIMIT1_P1_tap0_adjust_p1(data)                           (0x000000C0&((data)<<6))
#define  DFE_P1_REG_DFE_LIMIT1_P1_tap1_trans_p1(data)                            (0x00000020&((data)<<5))
#define  DFE_P1_REG_DFE_LIMIT1_P1_edge_last_notrans_p1(data)                     (0x00000010&((data)<<4))
#define  DFE_P1_REG_DFE_LIMIT1_P1_limit1_rev_p1(data)                            (0x0000000F&(data))
#define  DFE_P1_REG_DFE_LIMIT1_P1_get_tap4_max_p1(data)                          ((0xF8000000&(data))>>27)
#define  DFE_P1_REG_DFE_LIMIT1_P1_get_tap4_min_p1(data)                          ((0x07C00000&(data))>>22)
#define  DFE_P1_REG_DFE_LIMIT1_P1_get_vth_min_p1(data)                           ((0x00380000&(data))>>19)
#define  DFE_P1_REG_DFE_LIMIT1_P1_get_vth_max_p1(data)                           ((0x00078000&(data))>>15)
#define  DFE_P1_REG_DFE_LIMIT1_P1_get_vth_threshold_p1(data)                     ((0x00007000&(data))>>12)
#define  DFE_P1_REG_DFE_LIMIT1_P1_get_tap0_threshold_p1(data)                    ((0x00000F00&(data))>>8)
#define  DFE_P1_REG_DFE_LIMIT1_P1_get_tap0_adjust_p1(data)                       ((0x000000C0&(data))>>6)
#define  DFE_P1_REG_DFE_LIMIT1_P1_get_tap1_trans_p1(data)                        ((0x00000020&(data))>>5)
#define  DFE_P1_REG_DFE_LIMIT1_P1_get_edge_last_notrans_p1(data)                 ((0x00000010&(data))>>4)
#define  DFE_P1_REG_DFE_LIMIT1_P1_get_limit1_rev_p1(data)                        (0x0000000F&(data))

#define  DFE_P1_REG_DFE_LIMIT2_P1                                                0x1800DE90
#define  DFE_P1_REG_DFE_LIMIT2_P1_reg_addr                                       "0xB800DE90"
#define  DFE_P1_REG_DFE_LIMIT2_P1_reg                                            0xB800DE90
#define  DFE_P1_REG_DFE_LIMIT2_P1_inst_addr                                      "0x000D"
#define  set_DFE_P1_REG_DFE_LIMIT2_P1_reg(data)                                  (*((volatile unsigned int*)DFE_P1_REG_DFE_LIMIT2_P1_reg)=data)
#define  get_DFE_P1_REG_DFE_LIMIT2_P1_reg                                        (*((volatile unsigned int*)DFE_P1_REG_DFE_LIMIT2_P1_reg))
#define  DFE_P1_REG_DFE_LIMIT2_P1_servo_divisor_p1_shift                         (26)
#define  DFE_P1_REG_DFE_LIMIT2_P1_tap_divisor_p1_shift                           (20)
#define  DFE_P1_REG_DFE_LIMIT2_P1_vth_divisor_p1_shift                           (16)
#define  DFE_P1_REG_DFE_LIMIT2_P1_tap0_max_p1_shift                              (9)
#define  DFE_P1_REG_DFE_LIMIT2_P1_limit2_rev_p1_shift                            (0)
#define  DFE_P1_REG_DFE_LIMIT2_P1_servo_divisor_p1_mask                          (0xFC000000)
#define  DFE_P1_REG_DFE_LIMIT2_P1_tap_divisor_p1_mask                            (0x03F00000)
#define  DFE_P1_REG_DFE_LIMIT2_P1_vth_divisor_p1_mask                            (0x000F0000)
#define  DFE_P1_REG_DFE_LIMIT2_P1_tap0_max_p1_mask                               (0x0000FE00)
#define  DFE_P1_REG_DFE_LIMIT2_P1_limit2_rev_p1_mask                             (0x000001FF)
#define  DFE_P1_REG_DFE_LIMIT2_P1_servo_divisor_p1(data)                         (0xFC000000&((data)<<26))
#define  DFE_P1_REG_DFE_LIMIT2_P1_tap_divisor_p1(data)                           (0x03F00000&((data)<<20))
#define  DFE_P1_REG_DFE_LIMIT2_P1_vth_divisor_p1(data)                           (0x000F0000&((data)<<16))
#define  DFE_P1_REG_DFE_LIMIT2_P1_tap0_max_p1(data)                              (0x0000FE00&((data)<<9))
#define  DFE_P1_REG_DFE_LIMIT2_P1_limit2_rev_p1(data)                            (0x000001FF&(data))
#define  DFE_P1_REG_DFE_LIMIT2_P1_get_servo_divisor_p1(data)                     ((0xFC000000&(data))>>26)
#define  DFE_P1_REG_DFE_LIMIT2_P1_get_tap_divisor_p1(data)                       ((0x03F00000&(data))>>20)
#define  DFE_P1_REG_DFE_LIMIT2_P1_get_vth_divisor_p1(data)                       ((0x000F0000&(data))>>16)
#define  DFE_P1_REG_DFE_LIMIT2_P1_get_tap0_max_p1(data)                          ((0x0000FE00&(data))>>9)
#define  DFE_P1_REG_DFE_LIMIT2_P1_get_limit2_rev_p1(data)                        (0x000001FF&(data))

#define  DFE_P1_REG_DFE_READBACK_P1                                              0x1800DE94
#define  DFE_P1_REG_DFE_READBACK_P1_reg_addr                                     "0xB800DE94"
#define  DFE_P1_REG_DFE_READBACK_P1_reg                                          0xB800DE94
#define  DFE_P1_REG_DFE_READBACK_P1_inst_addr                                    "0x000E"
#define  set_DFE_P1_REG_DFE_READBACK_P1_reg(data)                                (*((volatile unsigned int*)DFE_P1_REG_DFE_READBACK_P1_reg)=data)
#define  get_DFE_P1_REG_DFE_READBACK_P1_reg                                      (*((volatile unsigned int*)DFE_P1_REG_DFE_READBACK_P1_reg))
#define  DFE_P1_REG_DFE_READBACK_P1_record_limit_en_p1_shift                     (31)
#define  DFE_P1_REG_DFE_READBACK_P1_lane_sel_p1_shift                            (29)
#define  DFE_P1_REG_DFE_READBACK_P1_limit_sel_p1_shift                           (24)
#define  DFE_P1_REG_DFE_READBACK_P1_limit_data_p1_shift                          (16)
#define  DFE_P1_REG_DFE_READBACK_P1_coef_sel_p1_shift                            (8)
#define  DFE_P1_REG_DFE_READBACK_P1_coef_data_p1_shift                           (0)
#define  DFE_P1_REG_DFE_READBACK_P1_record_limit_en_p1_mask                      (0x80000000)
#define  DFE_P1_REG_DFE_READBACK_P1_lane_sel_p1_mask                             (0x60000000)
#define  DFE_P1_REG_DFE_READBACK_P1_limit_sel_p1_mask                            (0x1F000000)
#define  DFE_P1_REG_DFE_READBACK_P1_limit_data_p1_mask                           (0x00FF0000)
#define  DFE_P1_REG_DFE_READBACK_P1_coef_sel_p1_mask                             (0x0000FF00)
#define  DFE_P1_REG_DFE_READBACK_P1_coef_data_p1_mask                            (0x000000FF)
#define  DFE_P1_REG_DFE_READBACK_P1_record_limit_en_p1(data)                     (0x80000000&((data)<<31))
#define  DFE_P1_REG_DFE_READBACK_P1_lane_sel_p1(data)                            (0x60000000&((data)<<29))
#define  DFE_P1_REG_DFE_READBACK_P1_limit_sel_p1(data)                           (0x1F000000&((data)<<24))
#define  DFE_P1_REG_DFE_READBACK_P1_limit_data_p1(data)                          (0x00FF0000&((data)<<16))
#define  DFE_P1_REG_DFE_READBACK_P1_coef_sel_p1(data)                            (0x0000FF00&((data)<<8))
#define  DFE_P1_REG_DFE_READBACK_P1_coef_data_p1(data)                           (0x000000FF&(data))
#define  DFE_P1_REG_DFE_READBACK_P1_get_record_limit_en_p1(data)                 ((0x80000000&(data))>>31)
#define  DFE_P1_REG_DFE_READBACK_P1_get_lane_sel_p1(data)                        ((0x60000000&(data))>>29)
#define  DFE_P1_REG_DFE_READBACK_P1_get_limit_sel_p1(data)                       ((0x1F000000&(data))>>24)
#define  DFE_P1_REG_DFE_READBACK_P1_get_limit_data_p1(data)                      ((0x00FF0000&(data))>>16)
#define  DFE_P1_REG_DFE_READBACK_P1_get_coef_sel_p1(data)                        ((0x0000FF00&(data))>>8)
#define  DFE_P1_REG_DFE_READBACK_P1_get_coef_data_p1(data)                       (0x000000FF&(data))

#define  DFE_P1_REG_DFE_FLAG_P1                                                  0x1800DE98
#define  DFE_P1_REG_DFE_FLAG_P1_reg_addr                                         "0xB800DE98"
#define  DFE_P1_REG_DFE_FLAG_P1_reg                                              0xB800DE98
#define  DFE_P1_REG_DFE_FLAG_P1_inst_addr                                        "0x000F"
#define  set_DFE_P1_REG_DFE_FLAG_P1_reg(data)                                    (*((volatile unsigned int*)DFE_P1_REG_DFE_FLAG_P1_reg)=data)
#define  get_DFE_P1_REG_DFE_FLAG_P1_reg                                          (*((volatile unsigned int*)DFE_P1_REG_DFE_FLAG_P1_reg))
#define  DFE_P1_REG_DFE_FLAG_P1_adapt_fail_flag_p1_shift                         (28)
#define  DFE_P1_REG_DFE_FLAG_P1_adapt_swing_max_flag_p1_shift                    (24)
#define  DFE_P1_REG_DFE_FLAG_P1_flag_rev1_p1_shift                               (12)
#define  DFE_P1_REG_DFE_FLAG_P1_flag_rev2_p1_shift                               (0)
#define  DFE_P1_REG_DFE_FLAG_P1_adapt_fail_flag_p1_mask                          (0xF0000000)
#define  DFE_P1_REG_DFE_FLAG_P1_adapt_swing_max_flag_p1_mask                     (0x0F000000)
#define  DFE_P1_REG_DFE_FLAG_P1_flag_rev1_p1_mask                                (0x00FFF000)
#define  DFE_P1_REG_DFE_FLAG_P1_flag_rev2_p1_mask                                (0x00000FFF)
#define  DFE_P1_REG_DFE_FLAG_P1_adapt_fail_flag_p1(data)                         (0xF0000000&((data)<<28))
#define  DFE_P1_REG_DFE_FLAG_P1_adapt_swing_max_flag_p1(data)                    (0x0F000000&((data)<<24))
#define  DFE_P1_REG_DFE_FLAG_P1_flag_rev1_p1(data)                               (0x00FFF000&((data)<<12))
#define  DFE_P1_REG_DFE_FLAG_P1_flag_rev2_p1(data)                               (0x00000FFF&(data))
#define  DFE_P1_REG_DFE_FLAG_P1_get_adapt_fail_flag_p1(data)                     ((0xF0000000&(data))>>28)
#define  DFE_P1_REG_DFE_FLAG_P1_get_adapt_swing_max_flag_p1(data)                ((0x0F000000&(data))>>24)
#define  DFE_P1_REG_DFE_FLAG_P1_get_flag_rev1_p1(data)                           ((0x00FFF000&(data))>>12)
#define  DFE_P1_REG_DFE_FLAG_P1_get_flag_rev2_p1(data)                           (0x00000FFF&(data))

#define  DFE_P1_REG_DFE_DEBUG_P1                                                 0x1800DE9C
#define  DFE_P1_REG_DFE_DEBUG_P1_reg_addr                                        "0xB800DE9C"
#define  DFE_P1_REG_DFE_DEBUG_P1_reg                                             0xB800DE9C
#define  DFE_P1_REG_DFE_DEBUG_P1_inst_addr                                       "0x0010"
#define  set_DFE_P1_REG_DFE_DEBUG_P1_reg(data)                                   (*((volatile unsigned int*)DFE_P1_REG_DFE_DEBUG_P1_reg)=data)
#define  get_DFE_P1_REG_DFE_DEBUG_P1_reg                                         (*((volatile unsigned int*)DFE_P1_REG_DFE_DEBUG_P1_reg))
#define  DFE_P1_REG_DFE_DEBUG_P1_debug_rev_p1_shift                              (5)
#define  DFE_P1_REG_DFE_DEBUG_P1_debug_sel_p1_shift                              (0)
#define  DFE_P1_REG_DFE_DEBUG_P1_debug_rev_p1_mask                               (0xFFFFFFE0)
#define  DFE_P1_REG_DFE_DEBUG_P1_debug_sel_p1_mask                               (0x0000001F)
#define  DFE_P1_REG_DFE_DEBUG_P1_debug_rev_p1(data)                              (0xFFFFFFE0&((data)<<5))
#define  DFE_P1_REG_DFE_DEBUG_P1_debug_sel_p1(data)                              (0x0000001F&(data))
#define  DFE_P1_REG_DFE_DEBUG_P1_get_debug_rev_p1(data)                          ((0xFFFFFFE0&(data))>>5)
#define  DFE_P1_REG_DFE_DEBUG_P1_get_debug_sel_p1(data)                          (0x0000001F&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======DFE_P1 register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  clk_inv_lane0_p1:1;
        RBus_UInt32  timer_ctrl_en_lane0_p1:1;
        RBus_UInt32  reduce_adapt_gain_lane0_p1:2;
        RBus_UInt32  rl_det_en_lane0_p1:1;
        RBus_UInt32  rl_det_mode_lane0_p1:1;
        RBus_UInt32  rl_threshold_lane0_p1:2;
        RBus_UInt32  dfe_adapt_en_lane0_p1:8;
        RBus_UInt32  le_min_lane0_p1:5;
        RBus_UInt32  le_init_lane0_p1:5;
        RBus_UInt32  tap4_init_lane0_p1:6;
    };
}dfe_p1_reg_dfe_en_l0_p1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tap3_init_lane0_p1:6;
        RBus_UInt32  tap2_init_lane0_p1:6;
        RBus_UInt32  tap1_init_lane0_p1:6;
        RBus_UInt32  tap0_init_lane0_p1:7;
        RBus_UInt32  init1_rev0_lane0_p1:3;
        RBus_UInt32  vth_init_lane0_p1:4;
    };
}dfe_p1_reg_dfe_init0_l0_p1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  load_in_init_lane0_p1:8;
        RBus_UInt32  init1_rev1_lane0_p1:6;
        RBus_UInt32  de_video_inv_lane0_p1:1;
        RBus_UInt32  de_packet_inv_lane0_p1:1;
        RBus_UInt32  de_video_en_lane0_p1:1;
        RBus_UInt32  de_packet_en_lane0_p1:1;
        RBus_UInt32  servo_init_lane0_p1:5;
        RBus_UInt32  init1_rev2_lane0_p1:9;
    };
}dfe_p1_reg_dfe_init1_l0_p1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  clk_inv_lane1_p1:1;
        RBus_UInt32  timer_ctrl_en_lane1_p1:1;
        RBus_UInt32  reduce_adapt_gain_lane1_p1:2;
        RBus_UInt32  rl_det_en_lane1_p1:1;
        RBus_UInt32  rl_det_mode_lane1_p1:1;
        RBus_UInt32  rl_threshold_lane1_p1:2;
        RBus_UInt32  dfe_adapt_en_lane1_p1:8;
        RBus_UInt32  le_min_lane1_p1:5;
        RBus_UInt32  le_init_lane1_p1:5;
        RBus_UInt32  tap4_init_lane1_p1:6;
    };
}dfe_p1_reg_dfe_en_l1_p1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tap3_init_lane1_p1:6;
        RBus_UInt32  tap2_init_lane1_p1:6;
        RBus_UInt32  tap1_init_lane1_p1:6;
        RBus_UInt32  tap0_init_lane1_p1:7;
        RBus_UInt32  init1_rev0_lane1_p1:3;
        RBus_UInt32  vth_init_lane1_p1:4;
    };
}dfe_p1_reg_dfe_init0_l1_p1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  load_in_init_lane1_p1:8;
        RBus_UInt32  init1_rev1_lane1_p1:6;
        RBus_UInt32  de_video_inv_lane1_p1:1;
        RBus_UInt32  de_packet_inv_lane1_p1:1;
        RBus_UInt32  de_video_en_lane1_p1:1;
        RBus_UInt32  de_packet_en_lane1_p1:1;
        RBus_UInt32  servo_init_lane1_p1:5;
        RBus_UInt32  init1_rev2_lane1_p1:9;
    };
}dfe_p1_reg_dfe_init1_l1_p1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  clk_inv_lane2_p1:1;
        RBus_UInt32  timer_ctrl_en_lane2_p1:1;
        RBus_UInt32  reduce_adapt_gain_lane2_p1:2;
        RBus_UInt32  rl_det_en_lane2_p1:1;
        RBus_UInt32  rl_det_mode_lane2_p1:1;
        RBus_UInt32  rl_threshold_lane2_p1:2;
        RBus_UInt32  dfe_adapt_en_lane2_p1:8;
        RBus_UInt32  le_min_lane2_p1:5;
        RBus_UInt32  le_init_lane2_p1:5;
        RBus_UInt32  tap4_init_lane2_p1:6;
    };
}dfe_p1_reg_dfe_en_l2_p1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tap3_init_lane2_p1:6;
        RBus_UInt32  tap2_init_lane2_p1:6;
        RBus_UInt32  tap1_init_lane2_p1:6;
        RBus_UInt32  tap0_init_lane2_p1:7;
        RBus_UInt32  init1_rev0_lane2_p1:3;
        RBus_UInt32  vth_init_lane2_p1:4;
    };
}dfe_p1_reg_dfe_init0_l2_p1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  load_in_init_lane2_p1:8;
        RBus_UInt32  init1_rev1_lane2_p1:6;
        RBus_UInt32  de_video_inv_lane2_p1:1;
        RBus_UInt32  de_packet_inv_lane2_p1:1;
        RBus_UInt32  de_video_en_lane2_p1:1;
        RBus_UInt32  de_packet_en_lane2_p1:1;
        RBus_UInt32  servo_init_lane2_p1:5;
        RBus_UInt32  init1_rev2_lane2_p1:9;
    };
}dfe_p1_reg_dfe_init1_l2_p1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  adapt_mode_p1:2;
        RBus_UInt32  edge_det_mode_p1:1;
        RBus_UInt32  transition_only_p1:1;
        RBus_UInt32  le_auto_reload_p1:1;
        RBus_UInt32  tap1_delay_p1:3;
        RBus_UInt32  tap24_delay_p1:3;
        RBus_UInt32  le_delay_p1:3;
        RBus_UInt32  servo_delay_p1:2;
        RBus_UInt32  gray_en_p1:8;
        RBus_UInt32  dfe_adapt_rstb_p1:4;
        RBus_UInt32  tap0_trans_p1:1;
        RBus_UInt32  tap0_notrans_p1:1;
        RBus_UInt32  servo_notrans_p1:1;
        RBus_UInt32  servo_trans_p1:1;
    };
}dfe_p1_reg_dfe_mode_p1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tap0_gain_p1:3;
        RBus_UInt32  tap1_gain_p1:3;
        RBus_UInt32  tap2_gain_p1:3;
        RBus_UInt32  tap3_gain_p1:3;
        RBus_UInt32  tap4_gain_p1:3;
        RBus_UInt32  servo_gain_p1:3;
        RBus_UInt32  le_gain1_p1:3;
        RBus_UInt32  le_gain2_p1:3;
        RBus_UInt32  le2_sign_p1:1;
        RBus_UInt32  le_gain_prec_p1:3;
        RBus_UInt32  le_prec_sign_p1:1;
        RBus_UInt32  trans_rlength_p1:3;
    };
}dfe_p1_reg_dfe_gain_p1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  limit0_rev_p1:6;
        RBus_UInt32  tap1_min_p1:6;
        RBus_UInt32  tap2_max_p1:5;
        RBus_UInt32  tap2_min_p1:5;
        RBus_UInt32  tap3_max_p1:5;
        RBus_UInt32  tap3_min_p1:5;
    };
}dfe_p1_reg_dfe_limit0_p1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tap4_max_p1:5;
        RBus_UInt32  tap4_min_p1:5;
        RBus_UInt32  vth_min_p1:3;
        RBus_UInt32  vth_max_p1:4;
        RBus_UInt32  vth_threshold_p1:3;
        RBus_UInt32  tap0_threshold_p1:4;
        RBus_UInt32  tap0_adjust_p1:2;
        RBus_UInt32  tap1_trans_p1:1;
        RBus_UInt32  edge_last_notrans_p1:1;
        RBus_UInt32  limit1_rev_p1:4;
    };
}dfe_p1_reg_dfe_limit1_p1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  servo_divisor_p1:6;
        RBus_UInt32  tap_divisor_p1:6;
        RBus_UInt32  vth_divisor_p1:4;
        RBus_UInt32  tap0_max_p1:7;
        RBus_UInt32  limit2_rev_p1:9;
    };
}dfe_p1_reg_dfe_limit2_p1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  record_limit_en_p1:1;
        RBus_UInt32  lane_sel_p1:2;
        RBus_UInt32  limit_sel_p1:5;
        RBus_UInt32  limit_data_p1:8;
        RBus_UInt32  coef_sel_p1:8;
        RBus_UInt32  coef_data_p1:8;
    };
}dfe_p1_reg_dfe_readback_p1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  adapt_fail_flag_p1:4;
        RBus_UInt32  adapt_swing_max_flag_p1:4;
        RBus_UInt32  flag_rev1_p1:12;
        RBus_UInt32  flag_rev2_p1:12;
    };
}dfe_p1_reg_dfe_flag_p1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  debug_rev_p1:27;
        RBus_UInt32  debug_sel_p1:5;
    };
}dfe_p1_reg_dfe_debug_p1_RBUS;

#else //apply LITTLE_ENDIAN

//======DFE_P1 register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tap4_init_lane0_p1:6;
        RBus_UInt32  le_init_lane0_p1:5;
        RBus_UInt32  le_min_lane0_p1:5;
        RBus_UInt32  dfe_adapt_en_lane0_p1:8;
        RBus_UInt32  rl_threshold_lane0_p1:2;
        RBus_UInt32  rl_det_mode_lane0_p1:1;
        RBus_UInt32  rl_det_en_lane0_p1:1;
        RBus_UInt32  reduce_adapt_gain_lane0_p1:2;
        RBus_UInt32  timer_ctrl_en_lane0_p1:1;
        RBus_UInt32  clk_inv_lane0_p1:1;
    };
}dfe_p1_reg_dfe_en_l0_p1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vth_init_lane0_p1:4;
        RBus_UInt32  init1_rev0_lane0_p1:3;
        RBus_UInt32  tap0_init_lane0_p1:7;
        RBus_UInt32  tap1_init_lane0_p1:6;
        RBus_UInt32  tap2_init_lane0_p1:6;
        RBus_UInt32  tap3_init_lane0_p1:6;
    };
}dfe_p1_reg_dfe_init0_l0_p1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  init1_rev2_lane0_p1:9;
        RBus_UInt32  servo_init_lane0_p1:5;
        RBus_UInt32  de_packet_en_lane0_p1:1;
        RBus_UInt32  de_video_en_lane0_p1:1;
        RBus_UInt32  de_packet_inv_lane0_p1:1;
        RBus_UInt32  de_video_inv_lane0_p1:1;
        RBus_UInt32  init1_rev1_lane0_p1:6;
        RBus_UInt32  load_in_init_lane0_p1:8;
    };
}dfe_p1_reg_dfe_init1_l0_p1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tap4_init_lane1_p1:6;
        RBus_UInt32  le_init_lane1_p1:5;
        RBus_UInt32  le_min_lane1_p1:5;
        RBus_UInt32  dfe_adapt_en_lane1_p1:8;
        RBus_UInt32  rl_threshold_lane1_p1:2;
        RBus_UInt32  rl_det_mode_lane1_p1:1;
        RBus_UInt32  rl_det_en_lane1_p1:1;
        RBus_UInt32  reduce_adapt_gain_lane1_p1:2;
        RBus_UInt32  timer_ctrl_en_lane1_p1:1;
        RBus_UInt32  clk_inv_lane1_p1:1;
    };
}dfe_p1_reg_dfe_en_l1_p1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vth_init_lane1_p1:4;
        RBus_UInt32  init1_rev0_lane1_p1:3;
        RBus_UInt32  tap0_init_lane1_p1:7;
        RBus_UInt32  tap1_init_lane1_p1:6;
        RBus_UInt32  tap2_init_lane1_p1:6;
        RBus_UInt32  tap3_init_lane1_p1:6;
    };
}dfe_p1_reg_dfe_init0_l1_p1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  init1_rev2_lane1_p1:9;
        RBus_UInt32  servo_init_lane1_p1:5;
        RBus_UInt32  de_packet_en_lane1_p1:1;
        RBus_UInt32  de_video_en_lane1_p1:1;
        RBus_UInt32  de_packet_inv_lane1_p1:1;
        RBus_UInt32  de_video_inv_lane1_p1:1;
        RBus_UInt32  init1_rev1_lane1_p1:6;
        RBus_UInt32  load_in_init_lane1_p1:8;
    };
}dfe_p1_reg_dfe_init1_l1_p1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tap4_init_lane2_p1:6;
        RBus_UInt32  le_init_lane2_p1:5;
        RBus_UInt32  le_min_lane2_p1:5;
        RBus_UInt32  dfe_adapt_en_lane2_p1:8;
        RBus_UInt32  rl_threshold_lane2_p1:2;
        RBus_UInt32  rl_det_mode_lane2_p1:1;
        RBus_UInt32  rl_det_en_lane2_p1:1;
        RBus_UInt32  reduce_adapt_gain_lane2_p1:2;
        RBus_UInt32  timer_ctrl_en_lane2_p1:1;
        RBus_UInt32  clk_inv_lane2_p1:1;
    };
}dfe_p1_reg_dfe_en_l2_p1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vth_init_lane2_p1:4;
        RBus_UInt32  init1_rev0_lane2_p1:3;
        RBus_UInt32  tap0_init_lane2_p1:7;
        RBus_UInt32  tap1_init_lane2_p1:6;
        RBus_UInt32  tap2_init_lane2_p1:6;
        RBus_UInt32  tap3_init_lane2_p1:6;
    };
}dfe_p1_reg_dfe_init0_l2_p1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  init1_rev2_lane2_p1:9;
        RBus_UInt32  servo_init_lane2_p1:5;
        RBus_UInt32  de_packet_en_lane2_p1:1;
        RBus_UInt32  de_video_en_lane2_p1:1;
        RBus_UInt32  de_packet_inv_lane2_p1:1;
        RBus_UInt32  de_video_inv_lane2_p1:1;
        RBus_UInt32  init1_rev1_lane2_p1:6;
        RBus_UInt32  load_in_init_lane2_p1:8;
    };
}dfe_p1_reg_dfe_init1_l2_p1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  servo_trans_p1:1;
        RBus_UInt32  servo_notrans_p1:1;
        RBus_UInt32  tap0_notrans_p1:1;
        RBus_UInt32  tap0_trans_p1:1;
        RBus_UInt32  dfe_adapt_rstb_p1:4;
        RBus_UInt32  gray_en_p1:8;
        RBus_UInt32  servo_delay_p1:2;
        RBus_UInt32  le_delay_p1:3;
        RBus_UInt32  tap24_delay_p1:3;
        RBus_UInt32  tap1_delay_p1:3;
        RBus_UInt32  le_auto_reload_p1:1;
        RBus_UInt32  transition_only_p1:1;
        RBus_UInt32  edge_det_mode_p1:1;
        RBus_UInt32  adapt_mode_p1:2;
    };
}dfe_p1_reg_dfe_mode_p1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  trans_rlength_p1:3;
        RBus_UInt32  le_prec_sign_p1:1;
        RBus_UInt32  le_gain_prec_p1:3;
        RBus_UInt32  le2_sign_p1:1;
        RBus_UInt32  le_gain2_p1:3;
        RBus_UInt32  le_gain1_p1:3;
        RBus_UInt32  servo_gain_p1:3;
        RBus_UInt32  tap4_gain_p1:3;
        RBus_UInt32  tap3_gain_p1:3;
        RBus_UInt32  tap2_gain_p1:3;
        RBus_UInt32  tap1_gain_p1:3;
        RBus_UInt32  tap0_gain_p1:3;
    };
}dfe_p1_reg_dfe_gain_p1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tap3_min_p1:5;
        RBus_UInt32  tap3_max_p1:5;
        RBus_UInt32  tap2_min_p1:5;
        RBus_UInt32  tap2_max_p1:5;
        RBus_UInt32  tap1_min_p1:6;
        RBus_UInt32  limit0_rev_p1:6;
    };
}dfe_p1_reg_dfe_limit0_p1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  limit1_rev_p1:4;
        RBus_UInt32  edge_last_notrans_p1:1;
        RBus_UInt32  tap1_trans_p1:1;
        RBus_UInt32  tap0_adjust_p1:2;
        RBus_UInt32  tap0_threshold_p1:4;
        RBus_UInt32  vth_threshold_p1:3;
        RBus_UInt32  vth_max_p1:4;
        RBus_UInt32  vth_min_p1:3;
        RBus_UInt32  tap4_min_p1:5;
        RBus_UInt32  tap4_max_p1:5;
    };
}dfe_p1_reg_dfe_limit1_p1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  limit2_rev_p1:9;
        RBus_UInt32  tap0_max_p1:7;
        RBus_UInt32  vth_divisor_p1:4;
        RBus_UInt32  tap_divisor_p1:6;
        RBus_UInt32  servo_divisor_p1:6;
    };
}dfe_p1_reg_dfe_limit2_p1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  coef_data_p1:8;
        RBus_UInt32  coef_sel_p1:8;
        RBus_UInt32  limit_data_p1:8;
        RBus_UInt32  limit_sel_p1:5;
        RBus_UInt32  lane_sel_p1:2;
        RBus_UInt32  record_limit_en_p1:1;
    };
}dfe_p1_reg_dfe_readback_p1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  flag_rev2_p1:12;
        RBus_UInt32  flag_rev1_p1:12;
        RBus_UInt32  adapt_swing_max_flag_p1:4;
        RBus_UInt32  adapt_fail_flag_p1:4;
    };
}dfe_p1_reg_dfe_flag_p1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  debug_sel_p1:5;
        RBus_UInt32  debug_rev_p1:27;
    };
}dfe_p1_reg_dfe_debug_p1_RBUS;




#endif 


#endif 
