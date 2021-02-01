/**
* @file rbusDma_vgipReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2016/6/7
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_DMA_VGIP_REG_H_
#define _RBUS_DMA_VGIP_REG_H_

#include "rbus_types.h"



//  DMA_VGIP Register Address
#define  DMA_VGIP_DMA_VGIP_VCLK_CTRL                                             0x18022400
#define  DMA_VGIP_DMA_VGIP_VCLK_CTRL_reg_addr                                    "0xB8022400"
#define  DMA_VGIP_DMA_VGIP_VCLK_CTRL_reg                                         0xB8022400
#define  DMA_VGIP_DMA_VGIP_VCLK_CTRL_inst_addr                                   "0x0000"
#define  set_DMA_VGIP_DMA_VGIP_VCLK_CTRL_reg(data)                               (*((volatile unsigned int*)DMA_VGIP_DMA_VGIP_VCLK_CTRL_reg)=data)
#define  get_DMA_VGIP_DMA_VGIP_VCLK_CTRL_reg                                     (*((volatile unsigned int*)DMA_VGIP_DMA_VGIP_VCLK_CTRL_reg))
#define  DMA_VGIP_DMA_VGIP_VCLK_CTRL_dma_v8_dummy_shift                          (0)
#define  DMA_VGIP_DMA_VGIP_VCLK_CTRL_dma_v8_dummy_mask                           (0x000000FF)
#define  DMA_VGIP_DMA_VGIP_VCLK_CTRL_dma_v8_dummy(data)                          (0x000000FF&(data))
#define  DMA_VGIP_DMA_VGIP_VCLK_CTRL_get_dma_v8_dummy(data)                      (0x000000FF&(data))

#define  DMA_VGIP_DMA_VGIP_V8_1_CTRL                                             0x18022404
#define  DMA_VGIP_DMA_VGIP_V8_1_CTRL_reg_addr                                    "0xB8022404"
#define  DMA_VGIP_DMA_VGIP_V8_1_CTRL_reg                                         0xB8022404
#define  DMA_VGIP_DMA_VGIP_V8_1_CTRL_inst_addr                                   "0x0001"
#define  set_DMA_VGIP_DMA_VGIP_V8_1_CTRL_reg(data)                               (*((volatile unsigned int*)DMA_VGIP_DMA_VGIP_V8_1_CTRL_reg)=data)
#define  get_DMA_VGIP_DMA_VGIP_V8_1_CTRL_reg                                     (*((volatile unsigned int*)DMA_VGIP_DMA_VGIP_V8_1_CTRL_reg))
#define  DMA_VGIP_DMA_VGIP_V8_1_CTRL_dummy_7_0_shift                             (0)
#define  DMA_VGIP_DMA_VGIP_V8_1_CTRL_dummy_7_0_mask                              (0x000000FF)
#define  DMA_VGIP_DMA_VGIP_V8_1_CTRL_dummy_7_0(data)                             (0x000000FF&(data))
#define  DMA_VGIP_DMA_VGIP_V8_1_CTRL_get_dummy_7_0(data)                         (0x000000FF&(data))

#define  DMA_VGIP_DMA_VGIP_V8_2_CTRL                                             0x18022408
#define  DMA_VGIP_DMA_VGIP_V8_2_CTRL_reg_addr                                    "0xB8022408"
#define  DMA_VGIP_DMA_VGIP_V8_2_CTRL_reg                                         0xB8022408
#define  DMA_VGIP_DMA_VGIP_V8_2_CTRL_inst_addr                                   "0x0002"
#define  set_DMA_VGIP_DMA_VGIP_V8_2_CTRL_reg(data)                               (*((volatile unsigned int*)DMA_VGIP_DMA_VGIP_V8_2_CTRL_reg)=data)
#define  get_DMA_VGIP_DMA_VGIP_V8_2_CTRL_reg                                     (*((volatile unsigned int*)DMA_VGIP_DMA_VGIP_V8_2_CTRL_reg))
#define  DMA_VGIP_DMA_VGIP_V8_2_CTRL_dummy_1_shift                               (1)
#define  DMA_VGIP_DMA_VGIP_V8_2_CTRL_dma_select_duplicate_lsb_shift              (0)
#define  DMA_VGIP_DMA_VGIP_V8_2_CTRL_dummy_1_mask                                (0x00000002)
#define  DMA_VGIP_DMA_VGIP_V8_2_CTRL_dma_select_duplicate_lsb_mask               (0x00000001)
#define  DMA_VGIP_DMA_VGIP_V8_2_CTRL_dummy_1(data)                               (0x00000002&((data)<<1))
#define  DMA_VGIP_DMA_VGIP_V8_2_CTRL_dma_select_duplicate_lsb(data)              (0x00000001&(data))
#define  DMA_VGIP_DMA_VGIP_V8_2_CTRL_get_dummy_1(data)                           ((0x00000002&(data))>>1)
#define  DMA_VGIP_DMA_VGIP_V8_2_CTRL_get_dma_select_duplicate_lsb(data)          (0x00000001&(data))

#define  DMA_VGIP_DMA_VGIP_GLOBAL_CTRL                                           0x1802240C
#define  DMA_VGIP_DMA_VGIP_GLOBAL_CTRL_reg_addr                                  "0xB802240C"
#define  DMA_VGIP_DMA_VGIP_GLOBAL_CTRL_reg                                       0xB802240C
#define  DMA_VGIP_DMA_VGIP_GLOBAL_CTRL_inst_addr                                 "0x0003"
#define  set_DMA_VGIP_DMA_VGIP_GLOBAL_CTRL_reg(data)                             (*((volatile unsigned int*)DMA_VGIP_DMA_VGIP_GLOBAL_CTRL_reg)=data)
#define  get_DMA_VGIP_DMA_VGIP_GLOBAL_CTRL_reg                                   (*((volatile unsigned int*)DMA_VGIP_DMA_VGIP_GLOBAL_CTRL_reg))
#define  DMA_VGIP_DMA_VGIP_GLOBAL_CTRL_dma_auto_l_flag_delay_en_shift            (31)
#define  DMA_VGIP_DMA_VGIP_GLOBAL_CTRL_dma_auto_l_flag_delay_num_shift           (16)
#define  DMA_VGIP_DMA_VGIP_GLOBAL_CTRL_dma_l_flag_delay_en_shift                 (15)
#define  DMA_VGIP_DMA_VGIP_GLOBAL_CTRL_dma_l_flag_sample_delay_shift             (13)
#define  DMA_VGIP_DMA_VGIP_GLOBAL_CTRL_dma_l_flag_delay_num_shift                (0)
#define  DMA_VGIP_DMA_VGIP_GLOBAL_CTRL_dma_auto_l_flag_delay_en_mask             (0x80000000)
#define  DMA_VGIP_DMA_VGIP_GLOBAL_CTRL_dma_auto_l_flag_delay_num_mask            (0x1FFF0000)
#define  DMA_VGIP_DMA_VGIP_GLOBAL_CTRL_dma_l_flag_delay_en_mask                  (0x00008000)
#define  DMA_VGIP_DMA_VGIP_GLOBAL_CTRL_dma_l_flag_sample_delay_mask              (0x00006000)
#define  DMA_VGIP_DMA_VGIP_GLOBAL_CTRL_dma_l_flag_delay_num_mask                 (0x00001FFF)
#define  DMA_VGIP_DMA_VGIP_GLOBAL_CTRL_dma_auto_l_flag_delay_en(data)            (0x80000000&((data)<<31))
#define  DMA_VGIP_DMA_VGIP_GLOBAL_CTRL_dma_auto_l_flag_delay_num(data)           (0x1FFF0000&((data)<<16))
#define  DMA_VGIP_DMA_VGIP_GLOBAL_CTRL_dma_l_flag_delay_en(data)                 (0x00008000&((data)<<15))
#define  DMA_VGIP_DMA_VGIP_GLOBAL_CTRL_dma_l_flag_sample_delay(data)             (0x00006000&((data)<<13))
#define  DMA_VGIP_DMA_VGIP_GLOBAL_CTRL_dma_l_flag_delay_num(data)                (0x00001FFF&(data))
#define  DMA_VGIP_DMA_VGIP_GLOBAL_CTRL_get_dma_auto_l_flag_delay_en(data)        ((0x80000000&(data))>>31)
#define  DMA_VGIP_DMA_VGIP_GLOBAL_CTRL_get_dma_auto_l_flag_delay_num(data)       ((0x1FFF0000&(data))>>16)
#define  DMA_VGIP_DMA_VGIP_GLOBAL_CTRL_get_dma_l_flag_delay_en(data)             ((0x00008000&(data))>>15)
#define  DMA_VGIP_DMA_VGIP_GLOBAL_CTRL_get_dma_l_flag_sample_delay(data)         ((0x00006000&(data))>>13)
#define  DMA_VGIP_DMA_VGIP_GLOBAL_CTRL_get_dma_l_flag_delay_num(data)            (0x00001FFF&(data))

#define  DMA_VGIP_DMA_VGIP_CTRL                                                  0x18022410
#define  DMA_VGIP_DMA_VGIP_CTRL_reg_addr                                         "0xB8022410"
#define  DMA_VGIP_DMA_VGIP_CTRL_reg                                              0xB8022410
#define  DMA_VGIP_DMA_VGIP_CTRL_inst_addr                                        "0x0004"
#define  set_DMA_VGIP_DMA_VGIP_CTRL_reg(data)                                    (*((volatile unsigned int*)DMA_VGIP_DMA_VGIP_CTRL_reg)=data)
#define  get_DMA_VGIP_DMA_VGIP_CTRL_reg                                          (*((volatile unsigned int*)DMA_VGIP_DMA_VGIP_CTRL_reg))
#define  DMA_VGIP_DMA_VGIP_CTRL_dma_ivrun_shift                                  (31)
#define  DMA_VGIP_DMA_VGIP_CTRL_dma_in_sel_shift                                 (28)
#define  DMA_VGIP_DMA_VGIP_CTRL_dma_random_en_shift                              (27)
#define  DMA_VGIP_DMA_VGIP_CTRL_dma_fdrop_en_shift                               (26)
#define  DMA_VGIP_DMA_VGIP_CTRL_dma_vact_end_ie_shift                            (25)
#define  DMA_VGIP_DMA_VGIP_CTRL_dma_vact_start_ie_shift                          (24)
#define  DMA_VGIP_DMA_VGIP_CTRL_dma_field_hs_inv_shift                           (23)
#define  DMA_VGIP_DMA_VGIP_CTRL_dma_field_vd_inv_shift                           (22)
#define  DMA_VGIP_DMA_VGIP_CTRL_dma_field_vd_en_shift                            (21)
#define  DMA_VGIP_DMA_VGIP_CTRL_dma_3dleft_inv_shift                             (20)
#define  DMA_VGIP_DMA_VGIP_CTRL_dma_3dleft_sync_edge_shift                       (19)
#define  DMA_VGIP_DMA_VGIP_CTRL_dma_field_inv_shift                              (18)
#define  DMA_VGIP_DMA_VGIP_CTRL_dma_field_sync_edge_shift                        (17)
#define  DMA_VGIP_DMA_VGIP_CTRL_dma_field_det_en_shift                           (16)
#define  DMA_VGIP_DMA_VGIP_CTRL_dma_hpact_is_hact_shift                          (15)
#define  DMA_VGIP_DMA_VGIP_CTRL_dma_fcap_str_odd_shift                           (14)
#define  DMA_VGIP_DMA_VGIP_CTRL_dma_mask_den_inv_shift                           (13)
#define  DMA_VGIP_DMA_VGIP_CTRL_dma_mask_den_1l_shift                            (12)
#define  DMA_VGIP_DMA_VGIP_CTRL_dma_3d_mode_en_shift                             (11)
#define  DMA_VGIP_DMA_VGIP_CTRL_dma_safe_field_inv_shift                         (10)
#define  DMA_VGIP_DMA_VGIP_CTRL_dma_force_tog_shift                              (9)
#define  DMA_VGIP_DMA_VGIP_CTRL_dma_safe_mode_shift                              (8)
#define  DMA_VGIP_DMA_VGIP_CTRL_dma_3d_right_act_en_shift                        (7)
#define  DMA_VGIP_DMA_VGIP_CTRL_dma_hs_syncedge_shift                            (6)
#define  DMA_VGIP_DMA_VGIP_CTRL_dma_vs_syncedge_shift                            (5)
#define  DMA_VGIP_DMA_VGIP_CTRL_dma_vs_by_hs_en_n_shift                          (4)
#define  DMA_VGIP_DMA_VGIP_CTRL_dma_vs_inv_shift                                 (3)
#define  DMA_VGIP_DMA_VGIP_CTRL_dma_hs_inv_shift                                 (2)
#define  DMA_VGIP_DMA_VGIP_CTRL_dma_digital_mode_shift                           (1)
#define  DMA_VGIP_DMA_VGIP_CTRL_dma_in_clk_en_shift                              (0)
#define  DMA_VGIP_DMA_VGIP_CTRL_dma_ivrun_mask                                   (0x80000000)
#define  DMA_VGIP_DMA_VGIP_CTRL_dma_in_sel_mask                                  (0x70000000)
#define  DMA_VGIP_DMA_VGIP_CTRL_dma_random_en_mask                               (0x08000000)
#define  DMA_VGIP_DMA_VGIP_CTRL_dma_fdrop_en_mask                                (0x04000000)
#define  DMA_VGIP_DMA_VGIP_CTRL_dma_vact_end_ie_mask                             (0x02000000)
#define  DMA_VGIP_DMA_VGIP_CTRL_dma_vact_start_ie_mask                           (0x01000000)
#define  DMA_VGIP_DMA_VGIP_CTRL_dma_field_hs_inv_mask                            (0x00800000)
#define  DMA_VGIP_DMA_VGIP_CTRL_dma_field_vd_inv_mask                            (0x00400000)
#define  DMA_VGIP_DMA_VGIP_CTRL_dma_field_vd_en_mask                             (0x00200000)
#define  DMA_VGIP_DMA_VGIP_CTRL_dma_3dleft_inv_mask                              (0x00100000)
#define  DMA_VGIP_DMA_VGIP_CTRL_dma_3dleft_sync_edge_mask                        (0x00080000)
#define  DMA_VGIP_DMA_VGIP_CTRL_dma_field_inv_mask                               (0x00040000)
#define  DMA_VGIP_DMA_VGIP_CTRL_dma_field_sync_edge_mask                         (0x00020000)
#define  DMA_VGIP_DMA_VGIP_CTRL_dma_field_det_en_mask                            (0x00010000)
#define  DMA_VGIP_DMA_VGIP_CTRL_dma_hpact_is_hact_mask                           (0x00008000)
#define  DMA_VGIP_DMA_VGIP_CTRL_dma_fcap_str_odd_mask                            (0x00004000)
#define  DMA_VGIP_DMA_VGIP_CTRL_dma_mask_den_inv_mask                            (0x00002000)
#define  DMA_VGIP_DMA_VGIP_CTRL_dma_mask_den_1l_mask                             (0x00001000)
#define  DMA_VGIP_DMA_VGIP_CTRL_dma_3d_mode_en_mask                              (0x00000800)
#define  DMA_VGIP_DMA_VGIP_CTRL_dma_safe_field_inv_mask                          (0x00000400)
#define  DMA_VGIP_DMA_VGIP_CTRL_dma_force_tog_mask                               (0x00000200)
#define  DMA_VGIP_DMA_VGIP_CTRL_dma_safe_mode_mask                               (0x00000100)
#define  DMA_VGIP_DMA_VGIP_CTRL_dma_3d_right_act_en_mask                         (0x00000080)
#define  DMA_VGIP_DMA_VGIP_CTRL_dma_hs_syncedge_mask                             (0x00000040)
#define  DMA_VGIP_DMA_VGIP_CTRL_dma_vs_syncedge_mask                             (0x00000020)
#define  DMA_VGIP_DMA_VGIP_CTRL_dma_vs_by_hs_en_n_mask                           (0x00000010)
#define  DMA_VGIP_DMA_VGIP_CTRL_dma_vs_inv_mask                                  (0x00000008)
#define  DMA_VGIP_DMA_VGIP_CTRL_dma_hs_inv_mask                                  (0x00000004)
#define  DMA_VGIP_DMA_VGIP_CTRL_dma_digital_mode_mask                            (0x00000002)
#define  DMA_VGIP_DMA_VGIP_CTRL_dma_in_clk_en_mask                               (0x00000001)
#define  DMA_VGIP_DMA_VGIP_CTRL_dma_ivrun(data)                                  (0x80000000&((data)<<31))
#define  DMA_VGIP_DMA_VGIP_CTRL_dma_in_sel(data)                                 (0x70000000&((data)<<28))
#define  DMA_VGIP_DMA_VGIP_CTRL_dma_random_en(data)                              (0x08000000&((data)<<27))
#define  DMA_VGIP_DMA_VGIP_CTRL_dma_fdrop_en(data)                               (0x04000000&((data)<<26))
#define  DMA_VGIP_DMA_VGIP_CTRL_dma_vact_end_ie(data)                            (0x02000000&((data)<<25))
#define  DMA_VGIP_DMA_VGIP_CTRL_dma_vact_start_ie(data)                          (0x01000000&((data)<<24))
#define  DMA_VGIP_DMA_VGIP_CTRL_dma_field_hs_inv(data)                           (0x00800000&((data)<<23))
#define  DMA_VGIP_DMA_VGIP_CTRL_dma_field_vd_inv(data)                           (0x00400000&((data)<<22))
#define  DMA_VGIP_DMA_VGIP_CTRL_dma_field_vd_en(data)                            (0x00200000&((data)<<21))
#define  DMA_VGIP_DMA_VGIP_CTRL_dma_3dleft_inv(data)                             (0x00100000&((data)<<20))
#define  DMA_VGIP_DMA_VGIP_CTRL_dma_3dleft_sync_edge(data)                       (0x00080000&((data)<<19))
#define  DMA_VGIP_DMA_VGIP_CTRL_dma_field_inv(data)                              (0x00040000&((data)<<18))
#define  DMA_VGIP_DMA_VGIP_CTRL_dma_field_sync_edge(data)                        (0x00020000&((data)<<17))
#define  DMA_VGIP_DMA_VGIP_CTRL_dma_field_det_en(data)                           (0x00010000&((data)<<16))
#define  DMA_VGIP_DMA_VGIP_CTRL_dma_hpact_is_hact(data)                          (0x00008000&((data)<<15))
#define  DMA_VGIP_DMA_VGIP_CTRL_dma_fcap_str_odd(data)                           (0x00004000&((data)<<14))
#define  DMA_VGIP_DMA_VGIP_CTRL_dma_mask_den_inv(data)                           (0x00002000&((data)<<13))
#define  DMA_VGIP_DMA_VGIP_CTRL_dma_mask_den_1l(data)                            (0x00001000&((data)<<12))
#define  DMA_VGIP_DMA_VGIP_CTRL_dma_3d_mode_en(data)                             (0x00000800&((data)<<11))
#define  DMA_VGIP_DMA_VGIP_CTRL_dma_safe_field_inv(data)                         (0x00000400&((data)<<10))
#define  DMA_VGIP_DMA_VGIP_CTRL_dma_force_tog(data)                              (0x00000200&((data)<<9))
#define  DMA_VGIP_DMA_VGIP_CTRL_dma_safe_mode(data)                              (0x00000100&((data)<<8))
#define  DMA_VGIP_DMA_VGIP_CTRL_dma_3d_right_act_en(data)                        (0x00000080&((data)<<7))
#define  DMA_VGIP_DMA_VGIP_CTRL_dma_hs_syncedge(data)                            (0x00000040&((data)<<6))
#define  DMA_VGIP_DMA_VGIP_CTRL_dma_vs_syncedge(data)                            (0x00000020&((data)<<5))
#define  DMA_VGIP_DMA_VGIP_CTRL_dma_vs_by_hs_en_n(data)                          (0x00000010&((data)<<4))
#define  DMA_VGIP_DMA_VGIP_CTRL_dma_vs_inv(data)                                 (0x00000008&((data)<<3))
#define  DMA_VGIP_DMA_VGIP_CTRL_dma_hs_inv(data)                                 (0x00000004&((data)<<2))
#define  DMA_VGIP_DMA_VGIP_CTRL_dma_digital_mode(data)                           (0x00000002&((data)<<1))
#define  DMA_VGIP_DMA_VGIP_CTRL_dma_in_clk_en(data)                              (0x00000001&(data))
#define  DMA_VGIP_DMA_VGIP_CTRL_get_dma_ivrun(data)                              ((0x80000000&(data))>>31)
#define  DMA_VGIP_DMA_VGIP_CTRL_get_dma_in_sel(data)                             ((0x70000000&(data))>>28)
#define  DMA_VGIP_DMA_VGIP_CTRL_get_dma_random_en(data)                          ((0x08000000&(data))>>27)
#define  DMA_VGIP_DMA_VGIP_CTRL_get_dma_fdrop_en(data)                           ((0x04000000&(data))>>26)
#define  DMA_VGIP_DMA_VGIP_CTRL_get_dma_vact_end_ie(data)                        ((0x02000000&(data))>>25)
#define  DMA_VGIP_DMA_VGIP_CTRL_get_dma_vact_start_ie(data)                      ((0x01000000&(data))>>24)
#define  DMA_VGIP_DMA_VGIP_CTRL_get_dma_field_hs_inv(data)                       ((0x00800000&(data))>>23)
#define  DMA_VGIP_DMA_VGIP_CTRL_get_dma_field_vd_inv(data)                       ((0x00400000&(data))>>22)
#define  DMA_VGIP_DMA_VGIP_CTRL_get_dma_field_vd_en(data)                        ((0x00200000&(data))>>21)
#define  DMA_VGIP_DMA_VGIP_CTRL_get_dma_3dleft_inv(data)                         ((0x00100000&(data))>>20)
#define  DMA_VGIP_DMA_VGIP_CTRL_get_dma_3dleft_sync_edge(data)                   ((0x00080000&(data))>>19)
#define  DMA_VGIP_DMA_VGIP_CTRL_get_dma_field_inv(data)                          ((0x00040000&(data))>>18)
#define  DMA_VGIP_DMA_VGIP_CTRL_get_dma_field_sync_edge(data)                    ((0x00020000&(data))>>17)
#define  DMA_VGIP_DMA_VGIP_CTRL_get_dma_field_det_en(data)                       ((0x00010000&(data))>>16)
#define  DMA_VGIP_DMA_VGIP_CTRL_get_dma_hpact_is_hact(data)                      ((0x00008000&(data))>>15)
#define  DMA_VGIP_DMA_VGIP_CTRL_get_dma_fcap_str_odd(data)                       ((0x00004000&(data))>>14)
#define  DMA_VGIP_DMA_VGIP_CTRL_get_dma_mask_den_inv(data)                       ((0x00002000&(data))>>13)
#define  DMA_VGIP_DMA_VGIP_CTRL_get_dma_mask_den_1l(data)                        ((0x00001000&(data))>>12)
#define  DMA_VGIP_DMA_VGIP_CTRL_get_dma_3d_mode_en(data)                         ((0x00000800&(data))>>11)
#define  DMA_VGIP_DMA_VGIP_CTRL_get_dma_safe_field_inv(data)                     ((0x00000400&(data))>>10)
#define  DMA_VGIP_DMA_VGIP_CTRL_get_dma_force_tog(data)                          ((0x00000200&(data))>>9)
#define  DMA_VGIP_DMA_VGIP_CTRL_get_dma_safe_mode(data)                          ((0x00000100&(data))>>8)
#define  DMA_VGIP_DMA_VGIP_CTRL_get_dma_3d_right_act_en(data)                    ((0x00000080&(data))>>7)
#define  DMA_VGIP_DMA_VGIP_CTRL_get_dma_hs_syncedge(data)                        ((0x00000040&(data))>>6)
#define  DMA_VGIP_DMA_VGIP_CTRL_get_dma_vs_syncedge(data)                        ((0x00000020&(data))>>5)
#define  DMA_VGIP_DMA_VGIP_CTRL_get_dma_vs_by_hs_en_n(data)                      ((0x00000010&(data))>>4)
#define  DMA_VGIP_DMA_VGIP_CTRL_get_dma_vs_inv(data)                             ((0x00000008&(data))>>3)
#define  DMA_VGIP_DMA_VGIP_CTRL_get_dma_hs_inv(data)                             ((0x00000004&(data))>>2)
#define  DMA_VGIP_DMA_VGIP_CTRL_get_dma_digital_mode(data)                       ((0x00000002&(data))>>1)
#define  DMA_VGIP_DMA_VGIP_CTRL_get_dma_in_clk_en(data)                          (0x00000001&(data))

#define  DMA_VGIP_DMA_VGIP_STATUS                                                0x18022414
#define  DMA_VGIP_DMA_VGIP_STATUS_reg_addr                                       "0xB8022414"
#define  DMA_VGIP_DMA_VGIP_STATUS_reg                                            0xB8022414
#define  DMA_VGIP_DMA_VGIP_STATUS_inst_addr                                      "0x0005"
#define  set_DMA_VGIP_DMA_VGIP_STATUS_reg(data)                                  (*((volatile unsigned int*)DMA_VGIP_DMA_VGIP_STATUS_reg)=data)
#define  get_DMA_VGIP_DMA_VGIP_STATUS_reg                                        (*((volatile unsigned int*)DMA_VGIP_DMA_VGIP_STATUS_reg))
#define  DMA_VGIP_DMA_VGIP_STATUS_dma_vs_end_shift                               (27)
#define  DMA_VGIP_DMA_VGIP_STATUS_dma_vs_start_shift                             (26)
#define  DMA_VGIP_DMA_VGIP_STATUS_dma_vact_end_shift                             (25)
#define  DMA_VGIP_DMA_VGIP_STATUS_dma_vact_start_shift                           (24)
#define  DMA_VGIP_DMA_VGIP_STATUS_dummy_23_17_shift                              (17)
#define  DMA_VGIP_DMA_VGIP_STATUS_dma_vlc_status_shift                           (16)
#define  DMA_VGIP_DMA_VGIP_STATUS_dma_rl_err_shift                               (15)
#define  DMA_VGIP_DMA_VGIP_STATUS_dma_vs_err_shift                               (14)
#define  DMA_VGIP_DMA_VGIP_STATUS_dma_hs_err_shift                               (13)
#define  DMA_VGIP_DMA_VGIP_STATUS_dma_field_err_shift                            (12)
#define  DMA_VGIP_DMA_VGIP_STATUS_dma_rl_tog_shift                               (11)
#define  DMA_VGIP_DMA_VGIP_STATUS_dma_l_flag_pol_shift                           (10)
#define  DMA_VGIP_DMA_VGIP_STATUS_dma_vs_tog_shift                               (9)
#define  DMA_VGIP_DMA_VGIP_STATUS_dma_hs_tog_shift                               (8)
#define  DMA_VGIP_DMA_VGIP_STATUS_dma_field_pol_shift                            (7)
#define  DMA_VGIP_DMA_VGIP_STATUS_dma_field_tog_shift                            (6)
#define  DMA_VGIP_DMA_VGIP_STATUS_dma_field_vs_lsb_shift                         (4)
#define  DMA_VGIP_DMA_VGIP_STATUS_dma_more_1line_field_shift                     (3)
#define  DMA_VGIP_DMA_VGIP_STATUS_dma_bounce_status_2_shift                      (2)
#define  DMA_VGIP_DMA_VGIP_STATUS_dma_bounce_status_1_shift                      (1)
#define  DMA_VGIP_DMA_VGIP_STATUS_dma_bounce_status_0_shift                      (0)
#define  DMA_VGIP_DMA_VGIP_STATUS_dma_vs_end_mask                                (0x08000000)
#define  DMA_VGIP_DMA_VGIP_STATUS_dma_vs_start_mask                              (0x04000000)
#define  DMA_VGIP_DMA_VGIP_STATUS_dma_vact_end_mask                              (0x02000000)
#define  DMA_VGIP_DMA_VGIP_STATUS_dma_vact_start_mask                            (0x01000000)
#define  DMA_VGIP_DMA_VGIP_STATUS_dummy_23_17_mask                               (0x00FE0000)
#define  DMA_VGIP_DMA_VGIP_STATUS_dma_vlc_status_mask                            (0x00010000)
#define  DMA_VGIP_DMA_VGIP_STATUS_dma_rl_err_mask                                (0x00008000)
#define  DMA_VGIP_DMA_VGIP_STATUS_dma_vs_err_mask                                (0x00004000)
#define  DMA_VGIP_DMA_VGIP_STATUS_dma_hs_err_mask                                (0x00002000)
#define  DMA_VGIP_DMA_VGIP_STATUS_dma_field_err_mask                             (0x00001000)
#define  DMA_VGIP_DMA_VGIP_STATUS_dma_rl_tog_mask                                (0x00000800)
#define  DMA_VGIP_DMA_VGIP_STATUS_dma_l_flag_pol_mask                            (0x00000400)
#define  DMA_VGIP_DMA_VGIP_STATUS_dma_vs_tog_mask                                (0x00000200)
#define  DMA_VGIP_DMA_VGIP_STATUS_dma_hs_tog_mask                                (0x00000100)
#define  DMA_VGIP_DMA_VGIP_STATUS_dma_field_pol_mask                             (0x00000080)
#define  DMA_VGIP_DMA_VGIP_STATUS_dma_field_tog_mask                             (0x00000040)
#define  DMA_VGIP_DMA_VGIP_STATUS_dma_field_vs_lsb_mask                          (0x00000030)
#define  DMA_VGIP_DMA_VGIP_STATUS_dma_more_1line_field_mask                      (0x00000008)
#define  DMA_VGIP_DMA_VGIP_STATUS_dma_bounce_status_2_mask                       (0x00000004)
#define  DMA_VGIP_DMA_VGIP_STATUS_dma_bounce_status_1_mask                       (0x00000002)
#define  DMA_VGIP_DMA_VGIP_STATUS_dma_bounce_status_0_mask                       (0x00000001)
#define  DMA_VGIP_DMA_VGIP_STATUS_dma_vs_end(data)                               (0x08000000&((data)<<27))
#define  DMA_VGIP_DMA_VGIP_STATUS_dma_vs_start(data)                             (0x04000000&((data)<<26))
#define  DMA_VGIP_DMA_VGIP_STATUS_dma_vact_end(data)                             (0x02000000&((data)<<25))
#define  DMA_VGIP_DMA_VGIP_STATUS_dma_vact_start(data)                           (0x01000000&((data)<<24))
#define  DMA_VGIP_DMA_VGIP_STATUS_dummy_23_17(data)                              (0x00FE0000&((data)<<17))
#define  DMA_VGIP_DMA_VGIP_STATUS_dma_vlc_status(data)                           (0x00010000&((data)<<16))
#define  DMA_VGIP_DMA_VGIP_STATUS_dma_rl_err(data)                               (0x00008000&((data)<<15))
#define  DMA_VGIP_DMA_VGIP_STATUS_dma_vs_err(data)                               (0x00004000&((data)<<14))
#define  DMA_VGIP_DMA_VGIP_STATUS_dma_hs_err(data)                               (0x00002000&((data)<<13))
#define  DMA_VGIP_DMA_VGIP_STATUS_dma_field_err(data)                            (0x00001000&((data)<<12))
#define  DMA_VGIP_DMA_VGIP_STATUS_dma_rl_tog(data)                               (0x00000800&((data)<<11))
#define  DMA_VGIP_DMA_VGIP_STATUS_dma_l_flag_pol(data)                           (0x00000400&((data)<<10))
#define  DMA_VGIP_DMA_VGIP_STATUS_dma_vs_tog(data)                               (0x00000200&((data)<<9))
#define  DMA_VGIP_DMA_VGIP_STATUS_dma_hs_tog(data)                               (0x00000100&((data)<<8))
#define  DMA_VGIP_DMA_VGIP_STATUS_dma_field_pol(data)                            (0x00000080&((data)<<7))
#define  DMA_VGIP_DMA_VGIP_STATUS_dma_field_tog(data)                            (0x00000040&((data)<<6))
#define  DMA_VGIP_DMA_VGIP_STATUS_dma_field_vs_lsb(data)                         (0x00000030&((data)<<4))
#define  DMA_VGIP_DMA_VGIP_STATUS_dma_more_1line_field(data)                     (0x00000008&((data)<<3))
#define  DMA_VGIP_DMA_VGIP_STATUS_dma_bounce_status_2(data)                      (0x00000004&((data)<<2))
#define  DMA_VGIP_DMA_VGIP_STATUS_dma_bounce_status_1(data)                      (0x00000002&((data)<<1))
#define  DMA_VGIP_DMA_VGIP_STATUS_dma_bounce_status_0(data)                      (0x00000001&(data))
#define  DMA_VGIP_DMA_VGIP_STATUS_get_dma_vs_end(data)                           ((0x08000000&(data))>>27)
#define  DMA_VGIP_DMA_VGIP_STATUS_get_dma_vs_start(data)                         ((0x04000000&(data))>>26)
#define  DMA_VGIP_DMA_VGIP_STATUS_get_dma_vact_end(data)                         ((0x02000000&(data))>>25)
#define  DMA_VGIP_DMA_VGIP_STATUS_get_dma_vact_start(data)                       ((0x01000000&(data))>>24)
#define  DMA_VGIP_DMA_VGIP_STATUS_get_dummy_23_17(data)                          ((0x00FE0000&(data))>>17)
#define  DMA_VGIP_DMA_VGIP_STATUS_get_dma_vlc_status(data)                       ((0x00010000&(data))>>16)
#define  DMA_VGIP_DMA_VGIP_STATUS_get_dma_rl_err(data)                           ((0x00008000&(data))>>15)
#define  DMA_VGIP_DMA_VGIP_STATUS_get_dma_vs_err(data)                           ((0x00004000&(data))>>14)
#define  DMA_VGIP_DMA_VGIP_STATUS_get_dma_hs_err(data)                           ((0x00002000&(data))>>13)
#define  DMA_VGIP_DMA_VGIP_STATUS_get_dma_field_err(data)                        ((0x00001000&(data))>>12)
#define  DMA_VGIP_DMA_VGIP_STATUS_get_dma_rl_tog(data)                           ((0x00000800&(data))>>11)
#define  DMA_VGIP_DMA_VGIP_STATUS_get_dma_l_flag_pol(data)                       ((0x00000400&(data))>>10)
#define  DMA_VGIP_DMA_VGIP_STATUS_get_dma_vs_tog(data)                           ((0x00000200&(data))>>9)
#define  DMA_VGIP_DMA_VGIP_STATUS_get_dma_hs_tog(data)                           ((0x00000100&(data))>>8)
#define  DMA_VGIP_DMA_VGIP_STATUS_get_dma_field_pol(data)                        ((0x00000080&(data))>>7)
#define  DMA_VGIP_DMA_VGIP_STATUS_get_dma_field_tog(data)                        ((0x00000040&(data))>>6)
#define  DMA_VGIP_DMA_VGIP_STATUS_get_dma_field_vs_lsb(data)                     ((0x00000030&(data))>>4)
#define  DMA_VGIP_DMA_VGIP_STATUS_get_dma_more_1line_field(data)                 ((0x00000008&(data))>>3)
#define  DMA_VGIP_DMA_VGIP_STATUS_get_dma_bounce_status_2(data)                  ((0x00000004&(data))>>2)
#define  DMA_VGIP_DMA_VGIP_STATUS_get_dma_bounce_status_1(data)                  ((0x00000002&(data))>>1)
#define  DMA_VGIP_DMA_VGIP_STATUS_get_dma_bounce_status_0(data)                  (0x00000001&(data))

#define  DMA_VGIP_DMA_VGIP_ACT_HSTA_Width                                        0x18022418
#define  DMA_VGIP_DMA_VGIP_ACT_HSTA_Width_reg_addr                               "0xB8022418"
#define  DMA_VGIP_DMA_VGIP_ACT_HSTA_Width_reg                                    0xB8022418
#define  DMA_VGIP_DMA_VGIP_ACT_HSTA_Width_inst_addr                              "0x0006"
#define  set_DMA_VGIP_DMA_VGIP_ACT_HSTA_Width_reg(data)                          (*((volatile unsigned int*)DMA_VGIP_DMA_VGIP_ACT_HSTA_Width_reg)=data)
#define  get_DMA_VGIP_DMA_VGIP_ACT_HSTA_Width_reg                                (*((volatile unsigned int*)DMA_VGIP_DMA_VGIP_ACT_HSTA_Width_reg))
#define  DMA_VGIP_DMA_VGIP_ACT_HSTA_Width_dma_db_rdy_shift                       (31)
#define  DMA_VGIP_DMA_VGIP_ACT_HSTA_Width_dma_db_en_shift                        (30)
#define  DMA_VGIP_DMA_VGIP_ACT_HSTA_Width_dma_ih_act_sta_shift                   (16)
#define  DMA_VGIP_DMA_VGIP_ACT_HSTA_Width_dma_db_read_sel_shift                  (15)
#define  DMA_VGIP_DMA_VGIP_ACT_HSTA_Width_dma_bypass_den_shift                   (14)
#define  DMA_VGIP_DMA_VGIP_ACT_HSTA_Width_dma_ih_act_wid_shift                   (0)
#define  DMA_VGIP_DMA_VGIP_ACT_HSTA_Width_dma_db_rdy_mask                        (0x80000000)
#define  DMA_VGIP_DMA_VGIP_ACT_HSTA_Width_dma_db_en_mask                         (0x40000000)
#define  DMA_VGIP_DMA_VGIP_ACT_HSTA_Width_dma_ih_act_sta_mask                    (0x3FFF0000)
#define  DMA_VGIP_DMA_VGIP_ACT_HSTA_Width_dma_db_read_sel_mask                   (0x00008000)
#define  DMA_VGIP_DMA_VGIP_ACT_HSTA_Width_dma_bypass_den_mask                    (0x00004000)
#define  DMA_VGIP_DMA_VGIP_ACT_HSTA_Width_dma_ih_act_wid_mask                    (0x00003FFF)
#define  DMA_VGIP_DMA_VGIP_ACT_HSTA_Width_dma_db_rdy(data)                       (0x80000000&((data)<<31))
#define  DMA_VGIP_DMA_VGIP_ACT_HSTA_Width_dma_db_en(data)                        (0x40000000&((data)<<30))
#define  DMA_VGIP_DMA_VGIP_ACT_HSTA_Width_dma_ih_act_sta(data)                   (0x3FFF0000&((data)<<16))
#define  DMA_VGIP_DMA_VGIP_ACT_HSTA_Width_dma_db_read_sel(data)                  (0x00008000&((data)<<15))
#define  DMA_VGIP_DMA_VGIP_ACT_HSTA_Width_dma_bypass_den(data)                   (0x00004000&((data)<<14))
#define  DMA_VGIP_DMA_VGIP_ACT_HSTA_Width_dma_ih_act_wid(data)                   (0x00003FFF&(data))
#define  DMA_VGIP_DMA_VGIP_ACT_HSTA_Width_get_dma_db_rdy(data)                   ((0x80000000&(data))>>31)
#define  DMA_VGIP_DMA_VGIP_ACT_HSTA_Width_get_dma_db_en(data)                    ((0x40000000&(data))>>30)
#define  DMA_VGIP_DMA_VGIP_ACT_HSTA_Width_get_dma_ih_act_sta(data)               ((0x3FFF0000&(data))>>16)
#define  DMA_VGIP_DMA_VGIP_ACT_HSTA_Width_get_dma_db_read_sel(data)              ((0x00008000&(data))>>15)
#define  DMA_VGIP_DMA_VGIP_ACT_HSTA_Width_get_dma_bypass_den(data)               ((0x00004000&(data))>>14)
#define  DMA_VGIP_DMA_VGIP_ACT_HSTA_Width_get_dma_ih_act_wid(data)               (0x00003FFF&(data))

#define  DMA_VGIP_DMA_VGIP_ACT_VSTA_Length                                       0x1802241C
#define  DMA_VGIP_DMA_VGIP_ACT_VSTA_Length_reg_addr                              "0xB802241C"
#define  DMA_VGIP_DMA_VGIP_ACT_VSTA_Length_reg                                   0xB802241C
#define  DMA_VGIP_DMA_VGIP_ACT_VSTA_Length_inst_addr                             "0x0007"
#define  set_DMA_VGIP_DMA_VGIP_ACT_VSTA_Length_reg(data)                         (*((volatile unsigned int*)DMA_VGIP_DMA_VGIP_ACT_VSTA_Length_reg)=data)
#define  get_DMA_VGIP_DMA_VGIP_ACT_VSTA_Length_reg                               (*((volatile unsigned int*)DMA_VGIP_DMA_VGIP_ACT_VSTA_Length_reg))
#define  DMA_VGIP_DMA_VGIP_ACT_VSTA_Length_dma_iv_act_sta_shift                  (16)
#define  DMA_VGIP_DMA_VGIP_ACT_VSTA_Length_dma_iv_act_len_shift                  (0)
#define  DMA_VGIP_DMA_VGIP_ACT_VSTA_Length_dma_iv_act_sta_mask                   (0x1FFF0000)
#define  DMA_VGIP_DMA_VGIP_ACT_VSTA_Length_dma_iv_act_len_mask                   (0x00001FFF)
#define  DMA_VGIP_DMA_VGIP_ACT_VSTA_Length_dma_iv_act_sta(data)                  (0x1FFF0000&((data)<<16))
#define  DMA_VGIP_DMA_VGIP_ACT_VSTA_Length_dma_iv_act_len(data)                  (0x00001FFF&(data))
#define  DMA_VGIP_DMA_VGIP_ACT_VSTA_Length_get_dma_iv_act_sta(data)              ((0x1FFF0000&(data))>>16)
#define  DMA_VGIP_DMA_VGIP_ACT_VSTA_Length_get_dma_iv_act_len(data)              (0x00001FFF&(data))

#define  DMA_VGIP_DMA_VGIP_DELAY                                                 0x18022420
#define  DMA_VGIP_DMA_VGIP_DELAY_reg_addr                                        "0xB8022420"
#define  DMA_VGIP_DMA_VGIP_DELAY_reg                                             0xB8022420
#define  DMA_VGIP_DMA_VGIP_DELAY_inst_addr                                       "0x0008"
#define  set_DMA_VGIP_DMA_VGIP_DELAY_reg(data)                                   (*((volatile unsigned int*)DMA_VGIP_DMA_VGIP_DELAY_reg)=data)
#define  get_DMA_VGIP_DMA_VGIP_DELAY_reg                                         (*((volatile unsigned int*)DMA_VGIP_DMA_VGIP_DELAY_reg))
#define  DMA_VGIP_DMA_VGIP_DELAY_dma_hs_width_shift                              (30)
#define  DMA_VGIP_DMA_VGIP_DELAY_dma_ihs_dly_shift                               (16)
#define  DMA_VGIP_DMA_VGIP_DELAY_dma_ivs_dly_shift                               (0)
#define  DMA_VGIP_DMA_VGIP_DELAY_dma_hs_width_mask                               (0xC0000000)
#define  DMA_VGIP_DMA_VGIP_DELAY_dma_ihs_dly_mask                                (0x3FFF0000)
#define  DMA_VGIP_DMA_VGIP_DELAY_dma_ivs_dly_mask                                (0x00001FFF)
#define  DMA_VGIP_DMA_VGIP_DELAY_dma_hs_width(data)                              (0xC0000000&((data)<<30))
#define  DMA_VGIP_DMA_VGIP_DELAY_dma_ihs_dly(data)                               (0x3FFF0000&((data)<<16))
#define  DMA_VGIP_DMA_VGIP_DELAY_dma_ivs_dly(data)                               (0x00001FFF&(data))
#define  DMA_VGIP_DMA_VGIP_DELAY_get_dma_hs_width(data)                          ((0xC0000000&(data))>>30)
#define  DMA_VGIP_DMA_VGIP_DELAY_get_dma_ihs_dly(data)                           ((0x3FFF0000&(data))>>16)
#define  DMA_VGIP_DMA_VGIP_DELAY_get_dma_ivs_dly(data)                           (0x00001FFF&(data))

#define  DMA_VGIP_DMA_VGIP_MISC                                                  0x18022424
#define  DMA_VGIP_DMA_VGIP_MISC_reg_addr                                         "0xB8022424"
#define  DMA_VGIP_DMA_VGIP_MISC_reg                                              0xB8022424
#define  DMA_VGIP_DMA_VGIP_MISC_inst_addr                                        "0x0009"
#define  set_DMA_VGIP_DMA_VGIP_MISC_reg(data)                                    (*((volatile unsigned int*)DMA_VGIP_DMA_VGIP_MISC_reg)=data)
#define  get_DMA_VGIP_DMA_VGIP_MISC_reg                                          (*((volatile unsigned int*)DMA_VGIP_DMA_VGIP_MISC_reg))
#define  DMA_VGIP_DMA_VGIP_MISC_dma_de_mask_en_shift                             (31)
#define  DMA_VGIP_DMA_VGIP_MISC_dma_hporch_num_sel_shift                         (24)
#define  DMA_VGIP_DMA_VGIP_MISC_dma_l_flag_force_tog_shift                       (21)
#define  DMA_VGIP_DMA_VGIP_MISC_dma_hporch_num_shift                             (8)
#define  DMA_VGIP_DMA_VGIP_MISC_dma_auto_ihs_dly_shift                           (6)
#define  DMA_VGIP_DMA_VGIP_MISC_dma_auto_ivs_dly_shift                           (4)
#define  DMA_VGIP_DMA_VGIP_MISC_dma_hdly_one_shift                               (3)
#define  DMA_VGIP_DMA_VGIP_MISC_dma_v1_v2_swap_shift                             (2)
#define  DMA_VGIP_DMA_VGIP_MISC_dma_v2_v3_swap_shift                             (1)
#define  DMA_VGIP_DMA_VGIP_MISC_dma_v1_v3_swap_shift                             (0)
#define  DMA_VGIP_DMA_VGIP_MISC_dma_de_mask_en_mask                              (0x80000000)
#define  DMA_VGIP_DMA_VGIP_MISC_dma_hporch_num_sel_mask                          (0x01000000)
#define  DMA_VGIP_DMA_VGIP_MISC_dma_l_flag_force_tog_mask                        (0x00200000)
#define  DMA_VGIP_DMA_VGIP_MISC_dma_hporch_num_mask                              (0x001FFF00)
#define  DMA_VGIP_DMA_VGIP_MISC_dma_auto_ihs_dly_mask                            (0x000000C0)
#define  DMA_VGIP_DMA_VGIP_MISC_dma_auto_ivs_dly_mask                            (0x00000030)
#define  DMA_VGIP_DMA_VGIP_MISC_dma_hdly_one_mask                                (0x00000008)
#define  DMA_VGIP_DMA_VGIP_MISC_dma_v1_v2_swap_mask                              (0x00000004)
#define  DMA_VGIP_DMA_VGIP_MISC_dma_v2_v3_swap_mask                              (0x00000002)
#define  DMA_VGIP_DMA_VGIP_MISC_dma_v1_v3_swap_mask                              (0x00000001)
#define  DMA_VGIP_DMA_VGIP_MISC_dma_de_mask_en(data)                             (0x80000000&((data)<<31))
#define  DMA_VGIP_DMA_VGIP_MISC_dma_hporch_num_sel(data)                         (0x01000000&((data)<<24))
#define  DMA_VGIP_DMA_VGIP_MISC_dma_l_flag_force_tog(data)                       (0x00200000&((data)<<21))
#define  DMA_VGIP_DMA_VGIP_MISC_dma_hporch_num(data)                             (0x001FFF00&((data)<<8))
#define  DMA_VGIP_DMA_VGIP_MISC_dma_auto_ihs_dly(data)                           (0x000000C0&((data)<<6))
#define  DMA_VGIP_DMA_VGIP_MISC_dma_auto_ivs_dly(data)                           (0x00000030&((data)<<4))
#define  DMA_VGIP_DMA_VGIP_MISC_dma_hdly_one(data)                               (0x00000008&((data)<<3))
#define  DMA_VGIP_DMA_VGIP_MISC_dma_v1_v2_swap(data)                             (0x00000004&((data)<<2))
#define  DMA_VGIP_DMA_VGIP_MISC_dma_v2_v3_swap(data)                             (0x00000002&((data)<<1))
#define  DMA_VGIP_DMA_VGIP_MISC_dma_v1_v3_swap(data)                             (0x00000001&(data))
#define  DMA_VGIP_DMA_VGIP_MISC_get_dma_de_mask_en(data)                         ((0x80000000&(data))>>31)
#define  DMA_VGIP_DMA_VGIP_MISC_get_dma_hporch_num_sel(data)                     ((0x01000000&(data))>>24)
#define  DMA_VGIP_DMA_VGIP_MISC_get_dma_l_flag_force_tog(data)                   ((0x00200000&(data))>>21)
#define  DMA_VGIP_DMA_VGIP_MISC_get_dma_hporch_num(data)                         ((0x001FFF00&(data))>>8)
#define  DMA_VGIP_DMA_VGIP_MISC_get_dma_auto_ihs_dly(data)                       ((0x000000C0&(data))>>6)
#define  DMA_VGIP_DMA_VGIP_MISC_get_dma_auto_ivs_dly(data)                       ((0x00000030&(data))>>4)
#define  DMA_VGIP_DMA_VGIP_MISC_get_dma_hdly_one(data)                           ((0x00000008&(data))>>3)
#define  DMA_VGIP_DMA_VGIP_MISC_get_dma_v1_v2_swap(data)                         ((0x00000004&(data))>>2)
#define  DMA_VGIP_DMA_VGIP_MISC_get_dma_v2_v3_swap(data)                         ((0x00000002&(data))>>1)
#define  DMA_VGIP_DMA_VGIP_MISC_get_dma_v1_v3_swap(data)                         (0x00000001&(data))

#define  DMA_VGIP_DMA_VGIP_PTN_H_VI                                              0x18022428
#define  DMA_VGIP_DMA_VGIP_PTN_H_VI_reg_addr                                     "0xB8022428"
#define  DMA_VGIP_DMA_VGIP_PTN_H_VI_reg                                          0xB8022428
#define  DMA_VGIP_DMA_VGIP_PTN_H_VI_inst_addr                                    "0x000A"
#define  set_DMA_VGIP_DMA_VGIP_PTN_H_VI_reg(data)                                (*((volatile unsigned int*)DMA_VGIP_DMA_VGIP_PTN_H_VI_reg)=data)
#define  get_DMA_VGIP_DMA_VGIP_PTN_H_VI_reg                                      (*((volatile unsigned int*)DMA_VGIP_DMA_VGIP_PTN_H_VI_reg))
#define  DMA_VGIP_DMA_VGIP_PTN_H_VI_dma_captst_en_shift                          (31)
#define  DMA_VGIP_DMA_VGIP_PTN_H_VI_dma_captst_mode_shift                        (29)
#define  DMA_VGIP_DMA_VGIP_PTN_H_VI_dma_vcaptst_num_shift                        (16)
#define  DMA_VGIP_DMA_VGIP_PTN_H_VI_dma_captst_field_sel_shift                   (15)
#define  DMA_VGIP_DMA_VGIP_PTN_H_VI_dma_hcaptst_num_shift                        (0)
#define  DMA_VGIP_DMA_VGIP_PTN_H_VI_dma_captst_en_mask                           (0x80000000)
#define  DMA_VGIP_DMA_VGIP_PTN_H_VI_dma_captst_mode_mask                         (0x60000000)
#define  DMA_VGIP_DMA_VGIP_PTN_H_VI_dma_vcaptst_num_mask                         (0x1FFF0000)
#define  DMA_VGIP_DMA_VGIP_PTN_H_VI_dma_captst_field_sel_mask                    (0x00008000)
#define  DMA_VGIP_DMA_VGIP_PTN_H_VI_dma_hcaptst_num_mask                         (0x00003FFF)
#define  DMA_VGIP_DMA_VGIP_PTN_H_VI_dma_captst_en(data)                          (0x80000000&((data)<<31))
#define  DMA_VGIP_DMA_VGIP_PTN_H_VI_dma_captst_mode(data)                        (0x60000000&((data)<<29))
#define  DMA_VGIP_DMA_VGIP_PTN_H_VI_dma_vcaptst_num(data)                        (0x1FFF0000&((data)<<16))
#define  DMA_VGIP_DMA_VGIP_PTN_H_VI_dma_captst_field_sel(data)                   (0x00008000&((data)<<15))
#define  DMA_VGIP_DMA_VGIP_PTN_H_VI_dma_hcaptst_num(data)                        (0x00003FFF&(data))
#define  DMA_VGIP_DMA_VGIP_PTN_H_VI_get_dma_captst_en(data)                      ((0x80000000&(data))>>31)
#define  DMA_VGIP_DMA_VGIP_PTN_H_VI_get_dma_captst_mode(data)                    ((0x60000000&(data))>>29)
#define  DMA_VGIP_DMA_VGIP_PTN_H_VI_get_dma_vcaptst_num(data)                    ((0x1FFF0000&(data))>>16)
#define  DMA_VGIP_DMA_VGIP_PTN_H_VI_get_dma_captst_field_sel(data)               ((0x00008000&(data))>>15)
#define  DMA_VGIP_DMA_VGIP_PTN_H_VI_get_dma_hcaptst_num(data)                    (0x00003FFF&(data))

#define  DMA_VGIP_DMA_VGIP_PTN0                                                  0x1802242C
#define  DMA_VGIP_DMA_VGIP_PTN0_reg_addr                                         "0xB802242C"
#define  DMA_VGIP_DMA_VGIP_PTN0_reg                                              0xB802242C
#define  DMA_VGIP_DMA_VGIP_PTN0_inst_addr                                        "0x000B"
#define  set_DMA_VGIP_DMA_VGIP_PTN0_reg(data)                                    (*((volatile unsigned int*)DMA_VGIP_DMA_VGIP_PTN0_reg)=data)
#define  get_DMA_VGIP_DMA_VGIP_PTN0_reg                                          (*((volatile unsigned int*)DMA_VGIP_DMA_VGIP_PTN0_reg))
#define  DMA_VGIP_DMA_VGIP_PTN0_dma_captst_r_data_shift                          (16)
#define  DMA_VGIP_DMA_VGIP_PTN0_dma_captst_g_data_shift                          (0)
#define  DMA_VGIP_DMA_VGIP_PTN0_dma_captst_r_data_mask                           (0x0FFF0000)
#define  DMA_VGIP_DMA_VGIP_PTN0_dma_captst_g_data_mask                           (0x00000FFF)
#define  DMA_VGIP_DMA_VGIP_PTN0_dma_captst_r_data(data)                          (0x0FFF0000&((data)<<16))
#define  DMA_VGIP_DMA_VGIP_PTN0_dma_captst_g_data(data)                          (0x00000FFF&(data))
#define  DMA_VGIP_DMA_VGIP_PTN0_get_dma_captst_r_data(data)                      ((0x0FFF0000&(data))>>16)
#define  DMA_VGIP_DMA_VGIP_PTN0_get_dma_captst_g_data(data)                      (0x00000FFF&(data))

#define  DMA_VGIP_DMA_VGIP_PTN1                                                  0x18022430
#define  DMA_VGIP_DMA_VGIP_PTN1_reg_addr                                         "0xB8022430"
#define  DMA_VGIP_DMA_VGIP_PTN1_reg                                              0xB8022430
#define  DMA_VGIP_DMA_VGIP_PTN1_inst_addr                                        "0x000C"
#define  set_DMA_VGIP_DMA_VGIP_PTN1_reg(data)                                    (*((volatile unsigned int*)DMA_VGIP_DMA_VGIP_PTN1_reg)=data)
#define  get_DMA_VGIP_DMA_VGIP_PTN1_reg                                          (*((volatile unsigned int*)DMA_VGIP_DMA_VGIP_PTN1_reg))
#define  DMA_VGIP_DMA_VGIP_PTN1_dma_hporch_num_sel_shift                         (16)
#define  DMA_VGIP_DMA_VGIP_PTN1_dma_captst_b_data_shift                          (0)
#define  DMA_VGIP_DMA_VGIP_PTN1_dma_hporch_num_sel_mask                          (0x3FFF0000)
#define  DMA_VGIP_DMA_VGIP_PTN1_dma_captst_b_data_mask                           (0x00000FFF)
#define  DMA_VGIP_DMA_VGIP_PTN1_dma_hporch_num_sel(data)                         (0x3FFF0000&((data)<<16))
#define  DMA_VGIP_DMA_VGIP_PTN1_dma_captst_b_data(data)                          (0x00000FFF&(data))
#define  DMA_VGIP_DMA_VGIP_PTN1_get_dma_hporch_num_sel(data)                     ((0x3FFF0000&(data))>>16)
#define  DMA_VGIP_DMA_VGIP_PTN1_get_dma_captst_b_data(data)                      (0x00000FFF&(data))

#define  DMA_VGIP_DMA_VGIP_LC                                                    0x18022434
#define  DMA_VGIP_DMA_VGIP_LC_reg_addr                                           "0xB8022434"
#define  DMA_VGIP_DMA_VGIP_LC_reg                                                0xB8022434
#define  DMA_VGIP_DMA_VGIP_LC_inst_addr                                          "0x000D"
#define  set_DMA_VGIP_DMA_VGIP_LC_reg(data)                                      (*((volatile unsigned int*)DMA_VGIP_DMA_VGIP_LC_reg)=data)
#define  get_DMA_VGIP_DMA_VGIP_LC_reg                                            (*((volatile unsigned int*)DMA_VGIP_DMA_VGIP_LC_reg))
#define  DMA_VGIP_DMA_VGIP_LC_dma_vlcen_shift                                    (31)
#define  DMA_VGIP_DMA_VGIP_LC_dma_vlc_mode_shift                                 (30)
#define  DMA_VGIP_DMA_VGIP_LC_dma_vlc_ie_shift                                   (29)
#define  DMA_VGIP_DMA_VGIP_LC_dma_den_crc_sel_shift                              (28)
#define  DMA_VGIP_DMA_VGIP_LC_dma_line_cnt_shift                                 (12)
#define  DMA_VGIP_DMA_VGIP_LC_dma_vln_shift                                      (0)
#define  DMA_VGIP_DMA_VGIP_LC_dma_vlcen_mask                                     (0x80000000)
#define  DMA_VGIP_DMA_VGIP_LC_dma_vlc_mode_mask                                  (0x40000000)
#define  DMA_VGIP_DMA_VGIP_LC_dma_vlc_ie_mask                                    (0x20000000)
#define  DMA_VGIP_DMA_VGIP_LC_dma_den_crc_sel_mask                               (0x10000000)
#define  DMA_VGIP_DMA_VGIP_LC_dma_line_cnt_mask                                  (0x00FFF000)
#define  DMA_VGIP_DMA_VGIP_LC_dma_vln_mask                                       (0x00000FFF)
#define  DMA_VGIP_DMA_VGIP_LC_dma_vlcen(data)                                    (0x80000000&((data)<<31))
#define  DMA_VGIP_DMA_VGIP_LC_dma_vlc_mode(data)                                 (0x40000000&((data)<<30))
#define  DMA_VGIP_DMA_VGIP_LC_dma_vlc_ie(data)                                   (0x20000000&((data)<<29))
#define  DMA_VGIP_DMA_VGIP_LC_dma_den_crc_sel(data)                              (0x10000000&((data)<<28))
#define  DMA_VGIP_DMA_VGIP_LC_dma_line_cnt(data)                                 (0x00FFF000&((data)<<12))
#define  DMA_VGIP_DMA_VGIP_LC_dma_vln(data)                                      (0x00000FFF&(data))
#define  DMA_VGIP_DMA_VGIP_LC_get_dma_vlcen(data)                                ((0x80000000&(data))>>31)
#define  DMA_VGIP_DMA_VGIP_LC_get_dma_vlc_mode(data)                             ((0x40000000&(data))>>30)
#define  DMA_VGIP_DMA_VGIP_LC_get_dma_vlc_ie(data)                               ((0x20000000&(data))>>29)
#define  DMA_VGIP_DMA_VGIP_LC_get_dma_den_crc_sel(data)                          ((0x10000000&(data))>>28)
#define  DMA_VGIP_DMA_VGIP_LC_get_dma_line_cnt(data)                             ((0x00FFF000&(data))>>12)
#define  DMA_VGIP_DMA_VGIP_LC_get_dma_vln(data)                                  (0x00000FFF&(data))

#define  DMA_VGIP_DMA_VGIP_CRC_CTRL                                              0x18022438
#define  DMA_VGIP_DMA_VGIP_CRC_CTRL_reg_addr                                     "0xB8022438"
#define  DMA_VGIP_DMA_VGIP_CRC_CTRL_reg                                          0xB8022438
#define  DMA_VGIP_DMA_VGIP_CRC_CTRL_inst_addr                                    "0x000E"
#define  set_DMA_VGIP_DMA_VGIP_CRC_CTRL_reg(data)                                (*((volatile unsigned int*)DMA_VGIP_DMA_VGIP_CRC_CTRL_reg)=data)
#define  get_DMA_VGIP_DMA_VGIP_CRC_CTRL_reg                                      (*((volatile unsigned int*)DMA_VGIP_DMA_VGIP_CRC_CTRL_reg))
#define  DMA_VGIP_DMA_VGIP_CRC_CTRL_dma_crc_mode_shift                           (6)
#define  DMA_VGIP_DMA_VGIP_CRC_CTRL_dma_crc_region_shift                         (5)
#define  DMA_VGIP_DMA_VGIP_CRC_CTRL_dma_crc_ctrl_in_shift                        (4)
#define  DMA_VGIP_DMA_VGIP_CRC_CTRL_dma_crc_field_edge_sel_shift                 (3)
#define  DMA_VGIP_DMA_VGIP_CRC_CTRL_dma_crc_field_shift                          (2)
#define  DMA_VGIP_DMA_VGIP_CRC_CTRL_dma_crc_conti_shift                          (1)
#define  DMA_VGIP_DMA_VGIP_CRC_CTRL_dma_crc_start_shift                          (0)
#define  DMA_VGIP_DMA_VGIP_CRC_CTRL_dma_crc_mode_mask                            (0x00000040)
#define  DMA_VGIP_DMA_VGIP_CRC_CTRL_dma_crc_region_mask                          (0x00000020)
#define  DMA_VGIP_DMA_VGIP_CRC_CTRL_dma_crc_ctrl_in_mask                         (0x00000010)
#define  DMA_VGIP_DMA_VGIP_CRC_CTRL_dma_crc_field_edge_sel_mask                  (0x00000008)
#define  DMA_VGIP_DMA_VGIP_CRC_CTRL_dma_crc_field_mask                           (0x00000004)
#define  DMA_VGIP_DMA_VGIP_CRC_CTRL_dma_crc_conti_mask                           (0x00000002)
#define  DMA_VGIP_DMA_VGIP_CRC_CTRL_dma_crc_start_mask                           (0x00000001)
#define  DMA_VGIP_DMA_VGIP_CRC_CTRL_dma_crc_mode(data)                           (0x00000040&((data)<<6))
#define  DMA_VGIP_DMA_VGIP_CRC_CTRL_dma_crc_region(data)                         (0x00000020&((data)<<5))
#define  DMA_VGIP_DMA_VGIP_CRC_CTRL_dma_crc_ctrl_in(data)                        (0x00000010&((data)<<4))
#define  DMA_VGIP_DMA_VGIP_CRC_CTRL_dma_crc_field_edge_sel(data)                 (0x00000008&((data)<<3))
#define  DMA_VGIP_DMA_VGIP_CRC_CTRL_dma_crc_field(data)                          (0x00000004&((data)<<2))
#define  DMA_VGIP_DMA_VGIP_CRC_CTRL_dma_crc_conti(data)                          (0x00000002&((data)<<1))
#define  DMA_VGIP_DMA_VGIP_CRC_CTRL_dma_crc_start(data)                          (0x00000001&(data))
#define  DMA_VGIP_DMA_VGIP_CRC_CTRL_get_dma_crc_mode(data)                       ((0x00000040&(data))>>6)
#define  DMA_VGIP_DMA_VGIP_CRC_CTRL_get_dma_crc_region(data)                     ((0x00000020&(data))>>5)
#define  DMA_VGIP_DMA_VGIP_CRC_CTRL_get_dma_crc_ctrl_in(data)                    ((0x00000010&(data))>>4)
#define  DMA_VGIP_DMA_VGIP_CRC_CTRL_get_dma_crc_field_edge_sel(data)             ((0x00000008&(data))>>3)
#define  DMA_VGIP_DMA_VGIP_CRC_CTRL_get_dma_crc_field(data)                      ((0x00000004&(data))>>2)
#define  DMA_VGIP_DMA_VGIP_CRC_CTRL_get_dma_crc_conti(data)                      ((0x00000002&(data))>>1)
#define  DMA_VGIP_DMA_VGIP_CRC_CTRL_get_dma_crc_start(data)                      (0x00000001&(data))

#define  DMA_VGIP_DMA_VGIP_CRC_Result                                            0x1802243C
#define  DMA_VGIP_DMA_VGIP_CRC_Result_reg_addr                                   "0xB802243C"
#define  DMA_VGIP_DMA_VGIP_CRC_Result_reg                                        0xB802243C
#define  DMA_VGIP_DMA_VGIP_CRC_Result_inst_addr                                  "0x000F"
#define  set_DMA_VGIP_DMA_VGIP_CRC_Result_reg(data)                              (*((volatile unsigned int*)DMA_VGIP_DMA_VGIP_CRC_Result_reg)=data)
#define  get_DMA_VGIP_DMA_VGIP_CRC_Result_reg                                    (*((volatile unsigned int*)DMA_VGIP_DMA_VGIP_CRC_Result_reg))
#define  DMA_VGIP_DMA_VGIP_CRC_Result_dma_crc_result_shift                       (0)
#define  DMA_VGIP_DMA_VGIP_CRC_Result_dma_crc_result_mask                        (0xFFFFFFFF)
#define  DMA_VGIP_DMA_VGIP_CRC_Result_dma_crc_result(data)                       (0xFFFFFFFF&(data))
#define  DMA_VGIP_DMA_VGIP_CRC_Result_get_dma_crc_result(data)                   (0xFFFFFFFF&(data))

#define  DMA_VGIP_DMA_VGIP_WDE                                                   0x18022440
#define  DMA_VGIP_DMA_VGIP_WDE_reg_addr                                          "0xB8022440"
#define  DMA_VGIP_DMA_VGIP_WDE_reg                                               0xB8022440
#define  DMA_VGIP_DMA_VGIP_WDE_inst_addr                                         "0x0010"
#define  set_DMA_VGIP_DMA_VGIP_WDE_reg(data)                                     (*((volatile unsigned int*)DMA_VGIP_DMA_VGIP_WDE_reg)=data)
#define  get_DMA_VGIP_DMA_VGIP_WDE_reg                                           (*((volatile unsigned int*)DMA_VGIP_DMA_VGIP_WDE_reg))
#define  DMA_VGIP_DMA_VGIP_WDE_dma_wd_to_main_shift                              (31)
#define  DMA_VGIP_DMA_VGIP_WDE_dma_wd_to_sub_shift                               (30)
#define  DMA_VGIP_DMA_VGIP_WDE_dummy_29_19_shift                                 (19)
#define  DMA_VGIP_DMA_VGIP_WDE_dma_vs_err_wde_shift                              (18)
#define  DMA_VGIP_DMA_VGIP_WDE_dma_hs_err_wde_shift                              (17)
#define  DMA_VGIP_DMA_VGIP_WDE_dma_field_err_wde_shift                           (16)
#define  DMA_VGIP_DMA_VGIP_WDE_dma_rl_err_wde_shift                              (15)
#define  DMA_VGIP_DMA_VGIP_WDE_dummy_14_4_shift                                  (4)
#define  DMA_VGIP_DMA_VGIP_WDE_dma_rl_err_ie_shift                               (3)
#define  DMA_VGIP_DMA_VGIP_WDE_dma_vs_err_ie_shift                               (2)
#define  DMA_VGIP_DMA_VGIP_WDE_dma_hs_err_ie_shift                               (1)
#define  DMA_VGIP_DMA_VGIP_WDE_dma_field_err_ie_shift                            (0)
#define  DMA_VGIP_DMA_VGIP_WDE_dma_wd_to_main_mask                               (0x80000000)
#define  DMA_VGIP_DMA_VGIP_WDE_dma_wd_to_sub_mask                                (0x40000000)
#define  DMA_VGIP_DMA_VGIP_WDE_dummy_29_19_mask                                  (0x3FF80000)
#define  DMA_VGIP_DMA_VGIP_WDE_dma_vs_err_wde_mask                               (0x00040000)
#define  DMA_VGIP_DMA_VGIP_WDE_dma_hs_err_wde_mask                               (0x00020000)
#define  DMA_VGIP_DMA_VGIP_WDE_dma_field_err_wde_mask                            (0x00010000)
#define  DMA_VGIP_DMA_VGIP_WDE_dma_rl_err_wde_mask                               (0x00008000)
#define  DMA_VGIP_DMA_VGIP_WDE_dummy_14_4_mask                                   (0x00007FF0)
#define  DMA_VGIP_DMA_VGIP_WDE_dma_rl_err_ie_mask                                (0x00000008)
#define  DMA_VGIP_DMA_VGIP_WDE_dma_vs_err_ie_mask                                (0x00000004)
#define  DMA_VGIP_DMA_VGIP_WDE_dma_hs_err_ie_mask                                (0x00000002)
#define  DMA_VGIP_DMA_VGIP_WDE_dma_field_err_ie_mask                             (0x00000001)
#define  DMA_VGIP_DMA_VGIP_WDE_dma_wd_to_main(data)                              (0x80000000&((data)<<31))
#define  DMA_VGIP_DMA_VGIP_WDE_dma_wd_to_sub(data)                               (0x40000000&((data)<<30))
#define  DMA_VGIP_DMA_VGIP_WDE_dummy_29_19(data)                                 (0x3FF80000&((data)<<19))
#define  DMA_VGIP_DMA_VGIP_WDE_dma_vs_err_wde(data)                              (0x00040000&((data)<<18))
#define  DMA_VGIP_DMA_VGIP_WDE_dma_hs_err_wde(data)                              (0x00020000&((data)<<17))
#define  DMA_VGIP_DMA_VGIP_WDE_dma_field_err_wde(data)                           (0x00010000&((data)<<16))
#define  DMA_VGIP_DMA_VGIP_WDE_dma_rl_err_wde(data)                              (0x00008000&((data)<<15))
#define  DMA_VGIP_DMA_VGIP_WDE_dummy_14_4(data)                                  (0x00007FF0&((data)<<4))
#define  DMA_VGIP_DMA_VGIP_WDE_dma_rl_err_ie(data)                               (0x00000008&((data)<<3))
#define  DMA_VGIP_DMA_VGIP_WDE_dma_vs_err_ie(data)                               (0x00000004&((data)<<2))
#define  DMA_VGIP_DMA_VGIP_WDE_dma_hs_err_ie(data)                               (0x00000002&((data)<<1))
#define  DMA_VGIP_DMA_VGIP_WDE_dma_field_err_ie(data)                            (0x00000001&(data))
#define  DMA_VGIP_DMA_VGIP_WDE_get_dma_wd_to_main(data)                          ((0x80000000&(data))>>31)
#define  DMA_VGIP_DMA_VGIP_WDE_get_dma_wd_to_sub(data)                           ((0x40000000&(data))>>30)
#define  DMA_VGIP_DMA_VGIP_WDE_get_dummy_29_19(data)                             ((0x3FF80000&(data))>>19)
#define  DMA_VGIP_DMA_VGIP_WDE_get_dma_vs_err_wde(data)                          ((0x00040000&(data))>>18)
#define  DMA_VGIP_DMA_VGIP_WDE_get_dma_hs_err_wde(data)                          ((0x00020000&(data))>>17)
#define  DMA_VGIP_DMA_VGIP_WDE_get_dma_field_err_wde(data)                       ((0x00010000&(data))>>16)
#define  DMA_VGIP_DMA_VGIP_WDE_get_dma_rl_err_wde(data)                          ((0x00008000&(data))>>15)
#define  DMA_VGIP_DMA_VGIP_WDE_get_dummy_14_4(data)                              ((0x00007FF0&(data))>>4)
#define  DMA_VGIP_DMA_VGIP_WDE_get_dma_rl_err_ie(data)                           ((0x00000008&(data))>>3)
#define  DMA_VGIP_DMA_VGIP_WDE_get_dma_vs_err_ie(data)                           ((0x00000004&(data))>>2)
#define  DMA_VGIP_DMA_VGIP_WDE_get_dma_hs_err_ie(data)                           ((0x00000002&(data))>>1)
#define  DMA_VGIP_DMA_VGIP_WDE_get_dma_field_err_ie(data)                        (0x00000001&(data))

#define  DMA_VGIP_DMA_VGIP_PR_L_R_ONLY_CTRL                                      0x18022450
#define  DMA_VGIP_DMA_VGIP_PR_L_R_ONLY_CTRL_reg_addr                             "0xB8022450"
#define  DMA_VGIP_DMA_VGIP_PR_L_R_ONLY_CTRL_reg                                  0xB8022450
#define  DMA_VGIP_DMA_VGIP_PR_L_R_ONLY_CTRL_inst_addr                            "0x0011"
#define  set_DMA_VGIP_DMA_VGIP_PR_L_R_ONLY_CTRL_reg(data)                        (*((volatile unsigned int*)DMA_VGIP_DMA_VGIP_PR_L_R_ONLY_CTRL_reg)=data)
#define  get_DMA_VGIP_DMA_VGIP_PR_L_R_ONLY_CTRL_reg                              (*((volatile unsigned int*)DMA_VGIP_DMA_VGIP_PR_L_R_ONLY_CTRL_reg))
#define  DMA_VGIP_DMA_VGIP_PR_L_R_ONLY_CTRL_dma_pr_l_r_only_mask_hs_shift        (2)
#define  DMA_VGIP_DMA_VGIP_PR_L_R_ONLY_CTRL_dma_pr_l_r_only_rm_den_shift         (1)
#define  DMA_VGIP_DMA_VGIP_PR_L_R_ONLY_CTRL_dma_pr_l_r_only_en_shift             (0)
#define  DMA_VGIP_DMA_VGIP_PR_L_R_ONLY_CTRL_dma_pr_l_r_only_mask_hs_mask         (0x00000004)
#define  DMA_VGIP_DMA_VGIP_PR_L_R_ONLY_CTRL_dma_pr_l_r_only_rm_den_mask          (0x00000002)
#define  DMA_VGIP_DMA_VGIP_PR_L_R_ONLY_CTRL_dma_pr_l_r_only_en_mask              (0x00000001)
#define  DMA_VGIP_DMA_VGIP_PR_L_R_ONLY_CTRL_dma_pr_l_r_only_mask_hs(data)        (0x00000004&((data)<<2))
#define  DMA_VGIP_DMA_VGIP_PR_L_R_ONLY_CTRL_dma_pr_l_r_only_rm_den(data)         (0x00000002&((data)<<1))
#define  DMA_VGIP_DMA_VGIP_PR_L_R_ONLY_CTRL_dma_pr_l_r_only_en(data)             (0x00000001&(data))
#define  DMA_VGIP_DMA_VGIP_PR_L_R_ONLY_CTRL_get_dma_pr_l_r_only_mask_hs(data)    ((0x00000004&(data))>>2)
#define  DMA_VGIP_DMA_VGIP_PR_L_R_ONLY_CTRL_get_dma_pr_l_r_only_rm_den(data)     ((0x00000002&(data))>>1)
#define  DMA_VGIP_DMA_VGIP_PR_L_R_ONLY_CTRL_get_dma_pr_l_r_only_en(data)         (0x00000001&(data))

#define  DMA_VGIP_DMA_VGIP_PTN2                                                  0x18022460
#define  DMA_VGIP_DMA_VGIP_PTN2_reg_addr                                         "0xB8022460"
#define  DMA_VGIP_DMA_VGIP_PTN2_reg                                              0xB8022460
#define  DMA_VGIP_DMA_VGIP_PTN2_inst_addr                                        "0x0012"
#define  set_DMA_VGIP_DMA_VGIP_PTN2_reg(data)                                    (*((volatile unsigned int*)DMA_VGIP_DMA_VGIP_PTN2_reg)=data)
#define  get_DMA_VGIP_DMA_VGIP_PTN2_reg                                          (*((volatile unsigned int*)DMA_VGIP_DMA_VGIP_PTN2_reg))
#define  DMA_VGIP_DMA_VGIP_PTN2_dma_captst_r_data_2_shift                        (16)
#define  DMA_VGIP_DMA_VGIP_PTN2_dma_captst_g_data_2_shift                        (0)
#define  DMA_VGIP_DMA_VGIP_PTN2_dma_captst_r_data_2_mask                         (0x0FFF0000)
#define  DMA_VGIP_DMA_VGIP_PTN2_dma_captst_g_data_2_mask                         (0x00000FFF)
#define  DMA_VGIP_DMA_VGIP_PTN2_dma_captst_r_data_2(data)                        (0x0FFF0000&((data)<<16))
#define  DMA_VGIP_DMA_VGIP_PTN2_dma_captst_g_data_2(data)                        (0x00000FFF&(data))
#define  DMA_VGIP_DMA_VGIP_PTN2_get_dma_captst_r_data_2(data)                    ((0x0FFF0000&(data))>>16)
#define  DMA_VGIP_DMA_VGIP_PTN2_get_dma_captst_g_data_2(data)                    (0x00000FFF&(data))

#define  DMA_VGIP_DMA_VGIP_PTN3                                                  0x18022464
#define  DMA_VGIP_DMA_VGIP_PTN3_reg_addr                                         "0xB8022464"
#define  DMA_VGIP_DMA_VGIP_PTN3_reg                                              0xB8022464
#define  DMA_VGIP_DMA_VGIP_PTN3_inst_addr                                        "0x0013"
#define  set_DMA_VGIP_DMA_VGIP_PTN3_reg(data)                                    (*((volatile unsigned int*)DMA_VGIP_DMA_VGIP_PTN3_reg)=data)
#define  get_DMA_VGIP_DMA_VGIP_PTN3_reg                                          (*((volatile unsigned int*)DMA_VGIP_DMA_VGIP_PTN3_reg))
#define  DMA_VGIP_DMA_VGIP_PTN3_dma_captst_b_data_3_shift                        (16)
#define  DMA_VGIP_DMA_VGIP_PTN3_dma_captst_b_data_2_shift                        (0)
#define  DMA_VGIP_DMA_VGIP_PTN3_dma_captst_b_data_3_mask                         (0x0FFF0000)
#define  DMA_VGIP_DMA_VGIP_PTN3_dma_captst_b_data_2_mask                         (0x00000FFF)
#define  DMA_VGIP_DMA_VGIP_PTN3_dma_captst_b_data_3(data)                        (0x0FFF0000&((data)<<16))
#define  DMA_VGIP_DMA_VGIP_PTN3_dma_captst_b_data_2(data)                        (0x00000FFF&(data))
#define  DMA_VGIP_DMA_VGIP_PTN3_get_dma_captst_b_data_3(data)                    ((0x0FFF0000&(data))>>16)
#define  DMA_VGIP_DMA_VGIP_PTN3_get_dma_captst_b_data_2(data)                    (0x00000FFF&(data))

#define  DMA_VGIP_DMA_VGIP_PTN4                                                  0x18022468
#define  DMA_VGIP_DMA_VGIP_PTN4_reg_addr                                         "0xB8022468"
#define  DMA_VGIP_DMA_VGIP_PTN4_reg                                              0xB8022468
#define  DMA_VGIP_DMA_VGIP_PTN4_inst_addr                                        "0x0014"
#define  set_DMA_VGIP_DMA_VGIP_PTN4_reg(data)                                    (*((volatile unsigned int*)DMA_VGIP_DMA_VGIP_PTN4_reg)=data)
#define  get_DMA_VGIP_DMA_VGIP_PTN4_reg                                          (*((volatile unsigned int*)DMA_VGIP_DMA_VGIP_PTN4_reg))
#define  DMA_VGIP_DMA_VGIP_PTN4_dma_captst_r_data_3_shift                        (16)
#define  DMA_VGIP_DMA_VGIP_PTN4_dma_captst_g_data_3_shift                        (0)
#define  DMA_VGIP_DMA_VGIP_PTN4_dma_captst_r_data_3_mask                         (0x0FFF0000)
#define  DMA_VGIP_DMA_VGIP_PTN4_dma_captst_g_data_3_mask                         (0x00000FFF)
#define  DMA_VGIP_DMA_VGIP_PTN4_dma_captst_r_data_3(data)                        (0x0FFF0000&((data)<<16))
#define  DMA_VGIP_DMA_VGIP_PTN4_dma_captst_g_data_3(data)                        (0x00000FFF&(data))
#define  DMA_VGIP_DMA_VGIP_PTN4_get_dma_captst_r_data_3(data)                    ((0x0FFF0000&(data))>>16)
#define  DMA_VGIP_DMA_VGIP_PTN4_get_dma_captst_g_data_3(data)                    (0x00000FFF&(data))

#define  DMA_VGIP_DMA_VGIP_PTN5                                                  0x1802246C
#define  DMA_VGIP_DMA_VGIP_PTN5_reg_addr                                         "0xB802246C"
#define  DMA_VGIP_DMA_VGIP_PTN5_reg                                              0xB802246C
#define  DMA_VGIP_DMA_VGIP_PTN5_inst_addr                                        "0x0015"
#define  set_DMA_VGIP_DMA_VGIP_PTN5_reg(data)                                    (*((volatile unsigned int*)DMA_VGIP_DMA_VGIP_PTN5_reg)=data)
#define  get_DMA_VGIP_DMA_VGIP_PTN5_reg                                          (*((volatile unsigned int*)DMA_VGIP_DMA_VGIP_PTN5_reg))
#define  DMA_VGIP_DMA_VGIP_PTN5_dma_captst_r_data_4_shift                        (16)
#define  DMA_VGIP_DMA_VGIP_PTN5_dma_captst_g_data_4_shift                        (0)
#define  DMA_VGIP_DMA_VGIP_PTN5_dma_captst_r_data_4_mask                         (0x0FFF0000)
#define  DMA_VGIP_DMA_VGIP_PTN5_dma_captst_g_data_4_mask                         (0x00000FFF)
#define  DMA_VGIP_DMA_VGIP_PTN5_dma_captst_r_data_4(data)                        (0x0FFF0000&((data)<<16))
#define  DMA_VGIP_DMA_VGIP_PTN5_dma_captst_g_data_4(data)                        (0x00000FFF&(data))
#define  DMA_VGIP_DMA_VGIP_PTN5_get_dma_captst_r_data_4(data)                    ((0x0FFF0000&(data))>>16)
#define  DMA_VGIP_DMA_VGIP_PTN5_get_dma_captst_g_data_4(data)                    (0x00000FFF&(data))

#define  DMA_VGIP_DMA_VGIP_PTN6                                                  0x18022470
#define  DMA_VGIP_DMA_VGIP_PTN6_reg_addr                                         "0xB8022470"
#define  DMA_VGIP_DMA_VGIP_PTN6_reg                                              0xB8022470
#define  DMA_VGIP_DMA_VGIP_PTN6_inst_addr                                        "0x0016"
#define  set_DMA_VGIP_DMA_VGIP_PTN6_reg(data)                                    (*((volatile unsigned int*)DMA_VGIP_DMA_VGIP_PTN6_reg)=data)
#define  get_DMA_VGIP_DMA_VGIP_PTN6_reg                                          (*((volatile unsigned int*)DMA_VGIP_DMA_VGIP_PTN6_reg))
#define  DMA_VGIP_DMA_VGIP_PTN6_dma_captst_b_data_4_shift                        (0)
#define  DMA_VGIP_DMA_VGIP_PTN6_dma_captst_b_data_4_mask                         (0x00000FFF)
#define  DMA_VGIP_DMA_VGIP_PTN6_dma_captst_b_data_4(data)                        (0x00000FFF&(data))
#define  DMA_VGIP_DMA_VGIP_PTN6_get_dma_captst_b_data_4(data)                    (0x00000FFF&(data))

#define  DMA_VGIP_DMA_VGIP_ADC_raw_data_DMA                                      0x18022478
#define  DMA_VGIP_DMA_VGIP_ADC_raw_data_DMA_reg_addr                             "0xB8022478"
#define  DMA_VGIP_DMA_VGIP_ADC_raw_data_DMA_reg                                  0xB8022478
#define  DMA_VGIP_DMA_VGIP_ADC_raw_data_DMA_inst_addr                            "0x0017"
#define  set_DMA_VGIP_DMA_VGIP_ADC_raw_data_DMA_reg(data)                        (*((volatile unsigned int*)DMA_VGIP_DMA_VGIP_ADC_raw_data_DMA_reg)=data)
#define  get_DMA_VGIP_DMA_VGIP_ADC_raw_data_DMA_reg                              (*((volatile unsigned int*)DMA_VGIP_DMA_VGIP_ADC_raw_data_DMA_reg))
#define  DMA_VGIP_DMA_VGIP_ADC_raw_data_DMA_dma_adc_test_dma_count_shift         (4)
#define  DMA_VGIP_DMA_VGIP_ADC_raw_data_DMA_dma_force_den_shift                  (2)
#define  DMA_VGIP_DMA_VGIP_ADC_raw_data_DMA_dma_force_vsync_shift                (1)
#define  DMA_VGIP_DMA_VGIP_ADC_raw_data_DMA_dma_adc_test_dma_mode_shift          (0)
#define  DMA_VGIP_DMA_VGIP_ADC_raw_data_DMA_dma_adc_test_dma_count_mask          (0xFFFFFFF0)
#define  DMA_VGIP_DMA_VGIP_ADC_raw_data_DMA_dma_force_den_mask                   (0x00000004)
#define  DMA_VGIP_DMA_VGIP_ADC_raw_data_DMA_dma_force_vsync_mask                 (0x00000002)
#define  DMA_VGIP_DMA_VGIP_ADC_raw_data_DMA_dma_adc_test_dma_mode_mask           (0x00000001)
#define  DMA_VGIP_DMA_VGIP_ADC_raw_data_DMA_dma_adc_test_dma_count(data)         (0xFFFFFFF0&((data)<<4))
#define  DMA_VGIP_DMA_VGIP_ADC_raw_data_DMA_dma_force_den(data)                  (0x00000004&((data)<<2))
#define  DMA_VGIP_DMA_VGIP_ADC_raw_data_DMA_dma_force_vsync(data)                (0x00000002&((data)<<1))
#define  DMA_VGIP_DMA_VGIP_ADC_raw_data_DMA_dma_adc_test_dma_mode(data)          (0x00000001&(data))
#define  DMA_VGIP_DMA_VGIP_ADC_raw_data_DMA_get_dma_adc_test_dma_count(data)     ((0xFFFFFFF0&(data))>>4)
#define  DMA_VGIP_DMA_VGIP_ADC_raw_data_DMA_get_dma_force_den(data)              ((0x00000004&(data))>>2)
#define  DMA_VGIP_DMA_VGIP_ADC_raw_data_DMA_get_dma_force_vsync(data)            ((0x00000002&(data))>>1)
#define  DMA_VGIP_DMA_VGIP_ADC_raw_data_DMA_get_dma_adc_test_dma_mode(data)      (0x00000001&(data))

#define  DMA_VGIP_DMA_VGIP_FRAMEPACKING_CTRL1                                    0x1802247C
#define  DMA_VGIP_DMA_VGIP_FRAMEPACKING_CTRL1_reg_addr                           "0xB802247C"
#define  DMA_VGIP_DMA_VGIP_FRAMEPACKING_CTRL1_reg                                0xB802247C
#define  DMA_VGIP_DMA_VGIP_FRAMEPACKING_CTRL1_inst_addr                          "0x0018"
#define  set_DMA_VGIP_DMA_VGIP_FRAMEPACKING_CTRL1_reg(data)                      (*((volatile unsigned int*)DMA_VGIP_DMA_VGIP_FRAMEPACKING_CTRL1_reg)=data)
#define  get_DMA_VGIP_DMA_VGIP_FRAMEPACKING_CTRL1_reg                            (*((volatile unsigned int*)DMA_VGIP_DMA_VGIP_FRAMEPACKING_CTRL1_reg))
#define  DMA_VGIP_DMA_VGIP_FRAMEPACKING_CTRL1_dma_vs_width_shift                 (16)
#define  DMA_VGIP_DMA_VGIP_FRAMEPACKING_CTRL1_dma_field_alternative_en_shift     (15)
#define  DMA_VGIP_DMA_VGIP_FRAMEPACKING_CTRL1_dma_frame_packing_en_shift         (13)
#define  DMA_VGIP_DMA_VGIP_FRAMEPACKING_CTRL1_dma_vs_position_shift              (0)
#define  DMA_VGIP_DMA_VGIP_FRAMEPACKING_CTRL1_dma_vs_width_mask                  (0x1FFF0000)
#define  DMA_VGIP_DMA_VGIP_FRAMEPACKING_CTRL1_dma_field_alternative_en_mask      (0x00008000)
#define  DMA_VGIP_DMA_VGIP_FRAMEPACKING_CTRL1_dma_frame_packing_en_mask          (0x00002000)
#define  DMA_VGIP_DMA_VGIP_FRAMEPACKING_CTRL1_dma_vs_position_mask               (0x00001FFF)
#define  DMA_VGIP_DMA_VGIP_FRAMEPACKING_CTRL1_dma_vs_width(data)                 (0x1FFF0000&((data)<<16))
#define  DMA_VGIP_DMA_VGIP_FRAMEPACKING_CTRL1_dma_field_alternative_en(data)     (0x00008000&((data)<<15))
#define  DMA_VGIP_DMA_VGIP_FRAMEPACKING_CTRL1_dma_frame_packing_en(data)         (0x00002000&((data)<<13))
#define  DMA_VGIP_DMA_VGIP_FRAMEPACKING_CTRL1_dma_vs_position(data)              (0x00001FFF&(data))
#define  DMA_VGIP_DMA_VGIP_FRAMEPACKING_CTRL1_get_dma_vs_width(data)             ((0x1FFF0000&(data))>>16)
#define  DMA_VGIP_DMA_VGIP_FRAMEPACKING_CTRL1_get_dma_field_alternative_en(data) ((0x00008000&(data))>>15)
#define  DMA_VGIP_DMA_VGIP_FRAMEPACKING_CTRL1_get_dma_frame_packing_en(data)     ((0x00002000&(data))>>13)
#define  DMA_VGIP_DMA_VGIP_FRAMEPACKING_CTRL1_get_dma_vs_position(data)          (0x00001FFF&(data))

#define  DMA_VGIP_DMA_VGIP_FRAMEPACKING_CTRL2                                    0x18022480
#define  DMA_VGIP_DMA_VGIP_FRAMEPACKING_CTRL2_reg_addr                           "0xB8022480"
#define  DMA_VGIP_DMA_VGIP_FRAMEPACKING_CTRL2_reg                                0xB8022480
#define  DMA_VGIP_DMA_VGIP_FRAMEPACKING_CTRL2_inst_addr                          "0x0019"
#define  set_DMA_VGIP_DMA_VGIP_FRAMEPACKING_CTRL2_reg(data)                      (*((volatile unsigned int*)DMA_VGIP_DMA_VGIP_FRAMEPACKING_CTRL2_reg)=data)
#define  get_DMA_VGIP_DMA_VGIP_FRAMEPACKING_CTRL2_reg                            (*((volatile unsigned int*)DMA_VGIP_DMA_VGIP_FRAMEPACKING_CTRL2_reg))
#define  DMA_VGIP_DMA_VGIP_FRAMEPACKING_CTRL2_dma_den_mask_start_shift           (16)
#define  DMA_VGIP_DMA_VGIP_FRAMEPACKING_CTRL2_dma_den_mask_end_shift             (0)
#define  DMA_VGIP_DMA_VGIP_FRAMEPACKING_CTRL2_dma_den_mask_start_mask            (0x1FFF0000)
#define  DMA_VGIP_DMA_VGIP_FRAMEPACKING_CTRL2_dma_den_mask_end_mask              (0x00001FFF)
#define  DMA_VGIP_DMA_VGIP_FRAMEPACKING_CTRL2_dma_den_mask_start(data)           (0x1FFF0000&((data)<<16))
#define  DMA_VGIP_DMA_VGIP_FRAMEPACKING_CTRL2_dma_den_mask_end(data)             (0x00001FFF&(data))
#define  DMA_VGIP_DMA_VGIP_FRAMEPACKING_CTRL2_get_dma_den_mask_start(data)       ((0x1FFF0000&(data))>>16)
#define  DMA_VGIP_DMA_VGIP_FRAMEPACKING_CTRL2_get_dma_den_mask_end(data)         (0x00001FFF&(data))

#define  DMA_VGIP_DMA_VGIP_CTS_FIFO_CTL                                          0x18022490
#define  DMA_VGIP_DMA_VGIP_CTS_FIFO_CTL_reg_addr                                 "0xB8022490"
#define  DMA_VGIP_DMA_VGIP_CTS_FIFO_CTL_reg                                      0xB8022490
#define  DMA_VGIP_DMA_VGIP_CTS_FIFO_CTL_inst_addr                                "0x001A"
#define  set_DMA_VGIP_DMA_VGIP_CTS_FIFO_CTL_reg(data)                            (*((volatile unsigned int*)DMA_VGIP_DMA_VGIP_CTS_FIFO_CTL_reg)=data)
#define  get_DMA_VGIP_DMA_VGIP_CTS_FIFO_CTL_reg                                  (*((volatile unsigned int*)DMA_VGIP_DMA_VGIP_CTS_FIFO_CTL_reg))
#define  DMA_VGIP_DMA_VGIP_CTS_FIFO_CTL_dma_dummy_ctsfifo_sdnr_shift             (11)
#define  DMA_VGIP_DMA_VGIP_CTS_FIFO_CTL_dma_force_ctsfifo_rstn_sdnr_shift        (10)
#define  DMA_VGIP_DMA_VGIP_CTS_FIFO_CTL_dma_en_ctsfifo_vsrst_sdnr_shift          (9)
#define  DMA_VGIP_DMA_VGIP_CTS_FIFO_CTL_dma_en_ctsfifo_bypass_sdnr_shift         (8)
#define  DMA_VGIP_DMA_VGIP_CTS_FIFO_CTL_dma_dummy_ctsfifo_vgip_shift             (3)
#define  DMA_VGIP_DMA_VGIP_CTS_FIFO_CTL_dma_force_ctsfifo_rstn_vgip_shift        (2)
#define  DMA_VGIP_DMA_VGIP_CTS_FIFO_CTL_dma_en_ctsfifo_vsrst_vgip_shift          (1)
#define  DMA_VGIP_DMA_VGIP_CTS_FIFO_CTL_dma_en_ctsfifo_bypass_vgip_shift         (0)
#define  DMA_VGIP_DMA_VGIP_CTS_FIFO_CTL_dma_dummy_ctsfifo_sdnr_mask              (0x00000800)
#define  DMA_VGIP_DMA_VGIP_CTS_FIFO_CTL_dma_force_ctsfifo_rstn_sdnr_mask         (0x00000400)
#define  DMA_VGIP_DMA_VGIP_CTS_FIFO_CTL_dma_en_ctsfifo_vsrst_sdnr_mask           (0x00000200)
#define  DMA_VGIP_DMA_VGIP_CTS_FIFO_CTL_dma_en_ctsfifo_bypass_sdnr_mask          (0x00000100)
#define  DMA_VGIP_DMA_VGIP_CTS_FIFO_CTL_dma_dummy_ctsfifo_vgip_mask              (0x00000008)
#define  DMA_VGIP_DMA_VGIP_CTS_FIFO_CTL_dma_force_ctsfifo_rstn_vgip_mask         (0x00000004)
#define  DMA_VGIP_DMA_VGIP_CTS_FIFO_CTL_dma_en_ctsfifo_vsrst_vgip_mask           (0x00000002)
#define  DMA_VGIP_DMA_VGIP_CTS_FIFO_CTL_dma_en_ctsfifo_bypass_vgip_mask          (0x00000001)
#define  DMA_VGIP_DMA_VGIP_CTS_FIFO_CTL_dma_dummy_ctsfifo_sdnr(data)             (0x00000800&((data)<<11))
#define  DMA_VGIP_DMA_VGIP_CTS_FIFO_CTL_dma_force_ctsfifo_rstn_sdnr(data)        (0x00000400&((data)<<10))
#define  DMA_VGIP_DMA_VGIP_CTS_FIFO_CTL_dma_en_ctsfifo_vsrst_sdnr(data)          (0x00000200&((data)<<9))
#define  DMA_VGIP_DMA_VGIP_CTS_FIFO_CTL_dma_en_ctsfifo_bypass_sdnr(data)         (0x00000100&((data)<<8))
#define  DMA_VGIP_DMA_VGIP_CTS_FIFO_CTL_dma_dummy_ctsfifo_vgip(data)             (0x00000008&((data)<<3))
#define  DMA_VGIP_DMA_VGIP_CTS_FIFO_CTL_dma_force_ctsfifo_rstn_vgip(data)        (0x00000004&((data)<<2))
#define  DMA_VGIP_DMA_VGIP_CTS_FIFO_CTL_dma_en_ctsfifo_vsrst_vgip(data)          (0x00000002&((data)<<1))
#define  DMA_VGIP_DMA_VGIP_CTS_FIFO_CTL_dma_en_ctsfifo_bypass_vgip(data)         (0x00000001&(data))
#define  DMA_VGIP_DMA_VGIP_CTS_FIFO_CTL_get_dma_dummy_ctsfifo_sdnr(data)         ((0x00000800&(data))>>11)
#define  DMA_VGIP_DMA_VGIP_CTS_FIFO_CTL_get_dma_force_ctsfifo_rstn_sdnr(data)    ((0x00000400&(data))>>10)
#define  DMA_VGIP_DMA_VGIP_CTS_FIFO_CTL_get_dma_en_ctsfifo_vsrst_sdnr(data)      ((0x00000200&(data))>>9)
#define  DMA_VGIP_DMA_VGIP_CTS_FIFO_CTL_get_dma_en_ctsfifo_bypass_sdnr(data)     ((0x00000100&(data))>>8)
#define  DMA_VGIP_DMA_VGIP_CTS_FIFO_CTL_get_dma_dummy_ctsfifo_vgip(data)         ((0x00000008&(data))>>3)
#define  DMA_VGIP_DMA_VGIP_CTS_FIFO_CTL_get_dma_force_ctsfifo_rstn_vgip(data)    ((0x00000004&(data))>>2)
#define  DMA_VGIP_DMA_VGIP_CTS_FIFO_CTL_get_dma_en_ctsfifo_vsrst_vgip(data)      ((0x00000002&(data))>>1)
#define  DMA_VGIP_DMA_VGIP_CTS_FIFO_CTL_get_dma_en_ctsfifo_bypass_vgip(data)     (0x00000001&(data))

#define  DMA_VGIP_DMA_VGIP_3D_RIGHT_ACT_HSTA_Width                               0x18022498
#define  DMA_VGIP_DMA_VGIP_3D_RIGHT_ACT_HSTA_Width_reg_addr                      "0xB8022498"
#define  DMA_VGIP_DMA_VGIP_3D_RIGHT_ACT_HSTA_Width_reg                           0xB8022498
#define  DMA_VGIP_DMA_VGIP_3D_RIGHT_ACT_HSTA_Width_inst_addr                     "0x001B"
#define  set_DMA_VGIP_DMA_VGIP_3D_RIGHT_ACT_HSTA_Width_reg(data)                 (*((volatile unsigned int*)DMA_VGIP_DMA_VGIP_3D_RIGHT_ACT_HSTA_Width_reg)=data)
#define  get_DMA_VGIP_DMA_VGIP_3D_RIGHT_ACT_HSTA_Width_reg                       (*((volatile unsigned int*)DMA_VGIP_DMA_VGIP_3D_RIGHT_ACT_HSTA_Width_reg))
#define  DMA_VGIP_DMA_VGIP_3D_RIGHT_ACT_HSTA_Width_dma_3d_right_ih_act_sta_shift (16)
#define  DMA_VGIP_DMA_VGIP_3D_RIGHT_ACT_HSTA_Width_dma_3d_right_ih_act_wid_shift (0)
#define  DMA_VGIP_DMA_VGIP_3D_RIGHT_ACT_HSTA_Width_dma_3d_right_ih_act_sta_mask  (0x3FFF0000)
#define  DMA_VGIP_DMA_VGIP_3D_RIGHT_ACT_HSTA_Width_dma_3d_right_ih_act_wid_mask  (0x00003FFF)
#define  DMA_VGIP_DMA_VGIP_3D_RIGHT_ACT_HSTA_Width_dma_3d_right_ih_act_sta(data) (0x3FFF0000&((data)<<16))
#define  DMA_VGIP_DMA_VGIP_3D_RIGHT_ACT_HSTA_Width_dma_3d_right_ih_act_wid(data) (0x00003FFF&(data))
#define  DMA_VGIP_DMA_VGIP_3D_RIGHT_ACT_HSTA_Width_get_dma_3d_right_ih_act_sta(data) ((0x3FFF0000&(data))>>16)
#define  DMA_VGIP_DMA_VGIP_3D_RIGHT_ACT_HSTA_Width_get_dma_3d_right_ih_act_wid(data) (0x00003FFF&(data))

#define  DMA_VGIP_DMA_VGIP_3D_RIGHT_ACT_VSTA_Length                              0x1802249C
#define  DMA_VGIP_DMA_VGIP_3D_RIGHT_ACT_VSTA_Length_reg_addr                     "0xB802249C"
#define  DMA_VGIP_DMA_VGIP_3D_RIGHT_ACT_VSTA_Length_reg                          0xB802249C
#define  DMA_VGIP_DMA_VGIP_3D_RIGHT_ACT_VSTA_Length_inst_addr                    "0x001C"
#define  set_DMA_VGIP_DMA_VGIP_3D_RIGHT_ACT_VSTA_Length_reg(data)                (*((volatile unsigned int*)DMA_VGIP_DMA_VGIP_3D_RIGHT_ACT_VSTA_Length_reg)=data)
#define  get_DMA_VGIP_DMA_VGIP_3D_RIGHT_ACT_VSTA_Length_reg                      (*((volatile unsigned int*)DMA_VGIP_DMA_VGIP_3D_RIGHT_ACT_VSTA_Length_reg))
#define  DMA_VGIP_DMA_VGIP_3D_RIGHT_ACT_VSTA_Length_dma_3d_right_iv_act_sta_shift (16)
#define  DMA_VGIP_DMA_VGIP_3D_RIGHT_ACT_VSTA_Length_dma_3d_right_iv_act_len_shift (0)
#define  DMA_VGIP_DMA_VGIP_3D_RIGHT_ACT_VSTA_Length_dma_3d_right_iv_act_sta_mask (0x1FFF0000)
#define  DMA_VGIP_DMA_VGIP_3D_RIGHT_ACT_VSTA_Length_dma_3d_right_iv_act_len_mask (0x00001FFF)
#define  DMA_VGIP_DMA_VGIP_3D_RIGHT_ACT_VSTA_Length_dma_3d_right_iv_act_sta(data) (0x1FFF0000&((data)<<16))
#define  DMA_VGIP_DMA_VGIP_3D_RIGHT_ACT_VSTA_Length_dma_3d_right_iv_act_len(data) (0x00001FFF&(data))
#define  DMA_VGIP_DMA_VGIP_3D_RIGHT_ACT_VSTA_Length_get_dma_3d_right_iv_act_sta(data) ((0x1FFF0000&(data))>>16)
#define  DMA_VGIP_DMA_VGIP_3D_RIGHT_ACT_VSTA_Length_get_dma_3d_right_iv_act_len(data) (0x00001FFF&(data))

#define  DMA_VGIP_DMA_VGIP_FRAMEPACKING_INTERLACE_CTRL1                          0x180224A8
#define  DMA_VGIP_DMA_VGIP_FRAMEPACKING_INTERLACE_CTRL1_reg_addr                 "0xB80224A8"
#define  DMA_VGIP_DMA_VGIP_FRAMEPACKING_INTERLACE_CTRL1_reg                      0xB80224A8
#define  DMA_VGIP_DMA_VGIP_FRAMEPACKING_INTERLACE_CTRL1_inst_addr                "0x001D"
#define  set_DMA_VGIP_DMA_VGIP_FRAMEPACKING_INTERLACE_CTRL1_reg(data)            (*((volatile unsigned int*)DMA_VGIP_DMA_VGIP_FRAMEPACKING_INTERLACE_CTRL1_reg)=data)
#define  get_DMA_VGIP_DMA_VGIP_FRAMEPACKING_INTERLACE_CTRL1_reg                  (*((volatile unsigned int*)DMA_VGIP_DMA_VGIP_FRAMEPACKING_INTERLACE_CTRL1_reg))
#define  DMA_VGIP_DMA_VGIP_FRAMEPACKING_INTERLACE_CTRL1_dma_vs_width_r_odd_shift (16)
#define  DMA_VGIP_DMA_VGIP_FRAMEPACKING_INTERLACE_CTRL1_dma_frame_packing_field_en_shift (13)
#define  DMA_VGIP_DMA_VGIP_FRAMEPACKING_INTERLACE_CTRL1_dma_vs_position_r_odd_shift (0)
#define  DMA_VGIP_DMA_VGIP_FRAMEPACKING_INTERLACE_CTRL1_dma_vs_width_r_odd_mask  (0x1FFF0000)
#define  DMA_VGIP_DMA_VGIP_FRAMEPACKING_INTERLACE_CTRL1_dma_frame_packing_field_en_mask (0x00002000)
#define  DMA_VGIP_DMA_VGIP_FRAMEPACKING_INTERLACE_CTRL1_dma_vs_position_r_odd_mask (0x00001FFF)
#define  DMA_VGIP_DMA_VGIP_FRAMEPACKING_INTERLACE_CTRL1_dma_vs_width_r_odd(data) (0x1FFF0000&((data)<<16))
#define  DMA_VGIP_DMA_VGIP_FRAMEPACKING_INTERLACE_CTRL1_dma_frame_packing_field_en(data) (0x00002000&((data)<<13))
#define  DMA_VGIP_DMA_VGIP_FRAMEPACKING_INTERLACE_CTRL1_dma_vs_position_r_odd(data) (0x00001FFF&(data))
#define  DMA_VGIP_DMA_VGIP_FRAMEPACKING_INTERLACE_CTRL1_get_dma_vs_width_r_odd(data) ((0x1FFF0000&(data))>>16)
#define  DMA_VGIP_DMA_VGIP_FRAMEPACKING_INTERLACE_CTRL1_get_dma_frame_packing_field_en(data) ((0x00002000&(data))>>13)
#define  DMA_VGIP_DMA_VGIP_FRAMEPACKING_INTERLACE_CTRL1_get_dma_vs_position_r_odd(data) (0x00001FFF&(data))

#define  DMA_VGIP_DMA_VGIP_FRAMEPACKING_INTERLACE_CTRL2                          0x180224AC
#define  DMA_VGIP_DMA_VGIP_FRAMEPACKING_INTERLACE_CTRL2_reg_addr                 "0xB80224AC"
#define  DMA_VGIP_DMA_VGIP_FRAMEPACKING_INTERLACE_CTRL2_reg                      0xB80224AC
#define  DMA_VGIP_DMA_VGIP_FRAMEPACKING_INTERLACE_CTRL2_inst_addr                "0x001E"
#define  set_DMA_VGIP_DMA_VGIP_FRAMEPACKING_INTERLACE_CTRL2_reg(data)            (*((volatile unsigned int*)DMA_VGIP_DMA_VGIP_FRAMEPACKING_INTERLACE_CTRL2_reg)=data)
#define  get_DMA_VGIP_DMA_VGIP_FRAMEPACKING_INTERLACE_CTRL2_reg                  (*((volatile unsigned int*)DMA_VGIP_DMA_VGIP_FRAMEPACKING_INTERLACE_CTRL2_reg))
#define  DMA_VGIP_DMA_VGIP_FRAMEPACKING_INTERLACE_CTRL2_dma_den_mask_start_r_odd_shift (16)
#define  DMA_VGIP_DMA_VGIP_FRAMEPACKING_INTERLACE_CTRL2_dma_den_mask_end_r_odd_shift (0)
#define  DMA_VGIP_DMA_VGIP_FRAMEPACKING_INTERLACE_CTRL2_dma_den_mask_start_r_odd_mask (0x1FFF0000)
#define  DMA_VGIP_DMA_VGIP_FRAMEPACKING_INTERLACE_CTRL2_dma_den_mask_end_r_odd_mask (0x00001FFF)
#define  DMA_VGIP_DMA_VGIP_FRAMEPACKING_INTERLACE_CTRL2_dma_den_mask_start_r_odd(data) (0x1FFF0000&((data)<<16))
#define  DMA_VGIP_DMA_VGIP_FRAMEPACKING_INTERLACE_CTRL2_dma_den_mask_end_r_odd(data) (0x00001FFF&(data))
#define  DMA_VGIP_DMA_VGIP_FRAMEPACKING_INTERLACE_CTRL2_get_dma_den_mask_start_r_odd(data) ((0x1FFF0000&(data))>>16)
#define  DMA_VGIP_DMA_VGIP_FRAMEPACKING_INTERLACE_CTRL2_get_dma_den_mask_end_r_odd(data) (0x00001FFF&(data))

#define  DMA_VGIP_DMA_VGIP_FRAMEPACKING_INTERLACE_CTRL3                          0x180224B0
#define  DMA_VGIP_DMA_VGIP_FRAMEPACKING_INTERLACE_CTRL3_reg_addr                 "0xB80224B0"
#define  DMA_VGIP_DMA_VGIP_FRAMEPACKING_INTERLACE_CTRL3_reg                      0xB80224B0
#define  DMA_VGIP_DMA_VGIP_FRAMEPACKING_INTERLACE_CTRL3_inst_addr                "0x001F"
#define  set_DMA_VGIP_DMA_VGIP_FRAMEPACKING_INTERLACE_CTRL3_reg(data)            (*((volatile unsigned int*)DMA_VGIP_DMA_VGIP_FRAMEPACKING_INTERLACE_CTRL3_reg)=data)
#define  get_DMA_VGIP_DMA_VGIP_FRAMEPACKING_INTERLACE_CTRL3_reg                  (*((volatile unsigned int*)DMA_VGIP_DMA_VGIP_FRAMEPACKING_INTERLACE_CTRL3_reg))
#define  DMA_VGIP_DMA_VGIP_FRAMEPACKING_INTERLACE_CTRL3_dma_vs_width_r_even_shift (16)
#define  DMA_VGIP_DMA_VGIP_FRAMEPACKING_INTERLACE_CTRL3_dma_vs_position_r_even_shift (0)
#define  DMA_VGIP_DMA_VGIP_FRAMEPACKING_INTERLACE_CTRL3_dma_vs_width_r_even_mask (0x1FFF0000)
#define  DMA_VGIP_DMA_VGIP_FRAMEPACKING_INTERLACE_CTRL3_dma_vs_position_r_even_mask (0x00001FFF)
#define  DMA_VGIP_DMA_VGIP_FRAMEPACKING_INTERLACE_CTRL3_dma_vs_width_r_even(data) (0x1FFF0000&((data)<<16))
#define  DMA_VGIP_DMA_VGIP_FRAMEPACKING_INTERLACE_CTRL3_dma_vs_position_r_even(data) (0x00001FFF&(data))
#define  DMA_VGIP_DMA_VGIP_FRAMEPACKING_INTERLACE_CTRL3_get_dma_vs_width_r_even(data) ((0x1FFF0000&(data))>>16)
#define  DMA_VGIP_DMA_VGIP_FRAMEPACKING_INTERLACE_CTRL3_get_dma_vs_position_r_even(data) (0x00001FFF&(data))

#define  DMA_VGIP_DMA_VGIP_FRAMEPACKING_INTERLACE_CTRL4                          0x180224B4
#define  DMA_VGIP_DMA_VGIP_FRAMEPACKING_INTERLACE_CTRL4_reg_addr                 "0xB80224B4"
#define  DMA_VGIP_DMA_VGIP_FRAMEPACKING_INTERLACE_CTRL4_reg                      0xB80224B4
#define  DMA_VGIP_DMA_VGIP_FRAMEPACKING_INTERLACE_CTRL4_inst_addr                "0x0020"
#define  set_DMA_VGIP_DMA_VGIP_FRAMEPACKING_INTERLACE_CTRL4_reg(data)            (*((volatile unsigned int*)DMA_VGIP_DMA_VGIP_FRAMEPACKING_INTERLACE_CTRL4_reg)=data)
#define  get_DMA_VGIP_DMA_VGIP_FRAMEPACKING_INTERLACE_CTRL4_reg                  (*((volatile unsigned int*)DMA_VGIP_DMA_VGIP_FRAMEPACKING_INTERLACE_CTRL4_reg))
#define  DMA_VGIP_DMA_VGIP_FRAMEPACKING_INTERLACE_CTRL4_dma_den_mask_start_r_even_shift (16)
#define  DMA_VGIP_DMA_VGIP_FRAMEPACKING_INTERLACE_CTRL4_dma_den_mask_end_r_even_shift (0)
#define  DMA_VGIP_DMA_VGIP_FRAMEPACKING_INTERLACE_CTRL4_dma_den_mask_start_r_even_mask (0x1FFF0000)
#define  DMA_VGIP_DMA_VGIP_FRAMEPACKING_INTERLACE_CTRL4_dma_den_mask_end_r_even_mask (0x00001FFF)
#define  DMA_VGIP_DMA_VGIP_FRAMEPACKING_INTERLACE_CTRL4_dma_den_mask_start_r_even(data) (0x1FFF0000&((data)<<16))
#define  DMA_VGIP_DMA_VGIP_FRAMEPACKING_INTERLACE_CTRL4_dma_den_mask_end_r_even(data) (0x00001FFF&(data))
#define  DMA_VGIP_DMA_VGIP_FRAMEPACKING_INTERLACE_CTRL4_get_dma_den_mask_start_r_even(data) ((0x1FFF0000&(data))>>16)
#define  DMA_VGIP_DMA_VGIP_FRAMEPACKING_INTERLACE_CTRL4_get_dma_den_mask_end_r_even(data) (0x00001FFF&(data))

#define  DMA_VGIP_DMA_VGIP_L_R_ACTIVE_ENABLE_CTRL1                               0x180224B8
#define  DMA_VGIP_DMA_VGIP_L_R_ACTIVE_ENABLE_CTRL1_reg_addr                      "0xB80224B8"
#define  DMA_VGIP_DMA_VGIP_L_R_ACTIVE_ENABLE_CTRL1_reg                           0xB80224B8
#define  DMA_VGIP_DMA_VGIP_L_R_ACTIVE_ENABLE_CTRL1_inst_addr                     "0x0021"
#define  set_DMA_VGIP_DMA_VGIP_L_R_ACTIVE_ENABLE_CTRL1_reg(data)                 (*((volatile unsigned int*)DMA_VGIP_DMA_VGIP_L_R_ACTIVE_ENABLE_CTRL1_reg)=data)
#define  get_DMA_VGIP_DMA_VGIP_L_R_ACTIVE_ENABLE_CTRL1_reg                       (*((volatile unsigned int*)DMA_VGIP_DMA_VGIP_L_R_ACTIVE_ENABLE_CTRL1_reg))
#define  DMA_VGIP_DMA_VGIP_L_R_ACTIVE_ENABLE_CTRL1_dma_end_l_shift               (16)
#define  DMA_VGIP_DMA_VGIP_L_R_ACTIVE_ENABLE_CTRL1_dma_sta_l_shift               (0)
#define  DMA_VGIP_DMA_VGIP_L_R_ACTIVE_ENABLE_CTRL1_dma_end_l_mask                (0x3FFF0000)
#define  DMA_VGIP_DMA_VGIP_L_R_ACTIVE_ENABLE_CTRL1_dma_sta_l_mask                (0x00003FFF)
#define  DMA_VGIP_DMA_VGIP_L_R_ACTIVE_ENABLE_CTRL1_dma_end_l(data)               (0x3FFF0000&((data)<<16))
#define  DMA_VGIP_DMA_VGIP_L_R_ACTIVE_ENABLE_CTRL1_dma_sta_l(data)               (0x00003FFF&(data))
#define  DMA_VGIP_DMA_VGIP_L_R_ACTIVE_ENABLE_CTRL1_get_dma_end_l(data)           ((0x3FFF0000&(data))>>16)
#define  DMA_VGIP_DMA_VGIP_L_R_ACTIVE_ENABLE_CTRL1_get_dma_sta_l(data)           (0x00003FFF&(data))

#define  DMA_VGIP_DMA_VGIP_L_R_ACTIVE_ENABLE_CTRL2                               0x180224BC
#define  DMA_VGIP_DMA_VGIP_L_R_ACTIVE_ENABLE_CTRL2_reg_addr                      "0xB80224BC"
#define  DMA_VGIP_DMA_VGIP_L_R_ACTIVE_ENABLE_CTRL2_reg                           0xB80224BC
#define  DMA_VGIP_DMA_VGIP_L_R_ACTIVE_ENABLE_CTRL2_inst_addr                     "0x0022"
#define  set_DMA_VGIP_DMA_VGIP_L_R_ACTIVE_ENABLE_CTRL2_reg(data)                 (*((volatile unsigned int*)DMA_VGIP_DMA_VGIP_L_R_ACTIVE_ENABLE_CTRL2_reg)=data)
#define  get_DMA_VGIP_DMA_VGIP_L_R_ACTIVE_ENABLE_CTRL2_reg                       (*((volatile unsigned int*)DMA_VGIP_DMA_VGIP_L_R_ACTIVE_ENABLE_CTRL2_reg))
#define  DMA_VGIP_DMA_VGIP_L_R_ACTIVE_ENABLE_CTRL2_dma_l_r_act_en_shift          (31)
#define  DMA_VGIP_DMA_VGIP_L_R_ACTIVE_ENABLE_CTRL2_dma_h_v_mode_shift            (30)
#define  DMA_VGIP_DMA_VGIP_L_R_ACTIVE_ENABLE_CTRL2_dma_end_r_shift               (16)
#define  DMA_VGIP_DMA_VGIP_L_R_ACTIVE_ENABLE_CTRL2_dma_sta_r_shift               (0)
#define  DMA_VGIP_DMA_VGIP_L_R_ACTIVE_ENABLE_CTRL2_dma_l_r_act_en_mask           (0x80000000)
#define  DMA_VGIP_DMA_VGIP_L_R_ACTIVE_ENABLE_CTRL2_dma_h_v_mode_mask             (0x40000000)
#define  DMA_VGIP_DMA_VGIP_L_R_ACTIVE_ENABLE_CTRL2_dma_end_r_mask                (0x3FFF0000)
#define  DMA_VGIP_DMA_VGIP_L_R_ACTIVE_ENABLE_CTRL2_dma_sta_r_mask                (0x00003FFF)
#define  DMA_VGIP_DMA_VGIP_L_R_ACTIVE_ENABLE_CTRL2_dma_l_r_act_en(data)          (0x80000000&((data)<<31))
#define  DMA_VGIP_DMA_VGIP_L_R_ACTIVE_ENABLE_CTRL2_dma_h_v_mode(data)            (0x40000000&((data)<<30))
#define  DMA_VGIP_DMA_VGIP_L_R_ACTIVE_ENABLE_CTRL2_dma_end_r(data)               (0x3FFF0000&((data)<<16))
#define  DMA_VGIP_DMA_VGIP_L_R_ACTIVE_ENABLE_CTRL2_dma_sta_r(data)               (0x00003FFF&(data))
#define  DMA_VGIP_DMA_VGIP_L_R_ACTIVE_ENABLE_CTRL2_get_dma_l_r_act_en(data)      ((0x80000000&(data))>>31)
#define  DMA_VGIP_DMA_VGIP_L_R_ACTIVE_ENABLE_CTRL2_get_dma_h_v_mode(data)        ((0x40000000&(data))>>30)
#define  DMA_VGIP_DMA_VGIP_L_R_ACTIVE_ENABLE_CTRL2_get_dma_end_r(data)           ((0x3FFF0000&(data))>>16)
#define  DMA_VGIP_DMA_VGIP_L_R_ACTIVE_ENABLE_CTRL2_get_dma_sta_r(data)           (0x00003FFF&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======DMA_VGIP register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dma_v8_dummy:8;
    };
}dma_vgip_dma_vgip_vclk_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dummy18022404_7_0:8;
    };
}dma_vgip_dma_vgip_v8_1_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  dummy18022408_1:1;
        RBus_UInt32  dma_select_duplicate_lsb:1;
    };
}dma_vgip_dma_vgip_v8_2_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_auto_l_flag_delay_en:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  dma_auto_l_flag_delay_num:13;
        RBus_UInt32  dma_l_flag_delay_en:1;
        RBus_UInt32  dma_l_flag_sample_delay:2;
        RBus_UInt32  dma_l_flag_delay_num:13;
    };
}dma_vgip_dma_vgip_global_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_ivrun:1;
        RBus_UInt32  dma_in_sel:3;
        RBus_UInt32  dma_random_en:1;
        RBus_UInt32  dma_fdrop_en:1;
        RBus_UInt32  dma_vact_end_ie:1;
        RBus_UInt32  dma_vact_start_ie:1;
        RBus_UInt32  dma_field_hs_inv:1;
        RBus_UInt32  dma_field_vd_inv:1;
        RBus_UInt32  dma_field_vd_en:1;
        RBus_UInt32  dma_3dleft_inv:1;
        RBus_UInt32  dma_3dleft_sync_edge:1;
        RBus_UInt32  dma_field_inv:1;
        RBus_UInt32  dma_field_sync_edge:1;
        RBus_UInt32  dma_field_det_en:1;
        RBus_UInt32  dma_hpact_is_hact:1;
        RBus_UInt32  dma_fcap_str_odd:1;
        RBus_UInt32  dma_mask_den_inv:1;
        RBus_UInt32  dma_mask_den_1l:1;
        RBus_UInt32  dma_3d_mode_en:1;
        RBus_UInt32  dma_safe_field_inv:1;
        RBus_UInt32  dma_force_tog:1;
        RBus_UInt32  dma_safe_mode:1;
        RBus_UInt32  dma_3d_right_act_en:1;
        RBus_UInt32  dma_hs_syncedge:1;
        RBus_UInt32  dma_vs_syncedge:1;
        RBus_UInt32  dma_vs_by_hs_en_n:1;
        RBus_UInt32  dma_vs_inv:1;
        RBus_UInt32  dma_hs_inv:1;
        RBus_UInt32  dma_digital_mode:1;
        RBus_UInt32  dma_in_clk_en:1;
    };
}dma_vgip_dma_vgip_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  dma_vs_end:1;
        RBus_UInt32  dma_vs_start:1;
        RBus_UInt32  dma_vact_end:1;
        RBus_UInt32  dma_vact_start:1;
        RBus_UInt32  dummy18022414_23_17:7;
        RBus_UInt32  dma_vlc_status:1;
        RBus_UInt32  dma_rl_err:1;
        RBus_UInt32  dma_vs_err:1;
        RBus_UInt32  dma_hs_err:1;
        RBus_UInt32  dma_field_err:1;
        RBus_UInt32  dma_rl_tog:1;
        RBus_UInt32  dma_l_flag_pol:1;
        RBus_UInt32  dma_vs_tog:1;
        RBus_UInt32  dma_hs_tog:1;
        RBus_UInt32  dma_field_pol:1;
        RBus_UInt32  dma_field_tog:1;
        RBus_UInt32  dma_field_vs_lsb:2;
        RBus_UInt32  dma_more_1line_field:1;
        RBus_UInt32  dma_bounce_status_2:1;
        RBus_UInt32  dma_bounce_status_1:1;
        RBus_UInt32  dma_bounce_status_0:1;
    };
}dma_vgip_dma_vgip_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_db_rdy:1;
        RBus_UInt32  dma_db_en:1;
        RBus_UInt32  dma_ih_act_sta:14;
        RBus_UInt32  dma_db_read_sel:1;
        RBus_UInt32  dma_bypass_den:1;
        RBus_UInt32  dma_ih_act_wid:14;
    };
}dma_vgip_dma_vgip_act_hsta_width_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dma_iv_act_sta:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  dma_iv_act_len:13;
    };
}dma_vgip_dma_vgip_act_vsta_length_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_hs_width:2;
        RBus_UInt32  dma_ihs_dly:14;
        RBus_UInt32  res1:3;
        RBus_UInt32  dma_ivs_dly:13;
    };
}dma_vgip_dma_vgip_delay_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_de_mask_en:1;
        RBus_UInt32  res1:6;
        RBus_UInt32  dma_hporch_num_sel:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  dma_l_flag_force_tog:1;
        RBus_UInt32  dma_hporch_num:13;
        RBus_UInt32  dma_auto_ihs_dly:2;
        RBus_UInt32  dma_auto_ivs_dly:2;
        RBus_UInt32  dma_hdly_one:1;
        RBus_UInt32  dma_v1_v2_swap:1;
        RBus_UInt32  dma_v2_v3_swap:1;
        RBus_UInt32  dma_v1_v3_swap:1;
    };
}dma_vgip_dma_vgip_misc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_captst_en:1;
        RBus_UInt32  dma_captst_mode:2;
        RBus_UInt32  dma_vcaptst_num:13;
        RBus_UInt32  dma_captst_field_sel:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  dma_hcaptst_num:14;
    };
}dma_vgip_dma_vgip_ptn_h_vi_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  dma_captst_r_data:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dma_captst_g_data:12;
    };
}dma_vgip_dma_vgip_ptn0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  dma_hporch_num_sel:14;
        RBus_UInt32  res2:4;
        RBus_UInt32  dma_captst_b_data:12;
    };
}dma_vgip_dma_vgip_ptn1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_vlcen:1;
        RBus_UInt32  dma_vlc_mode:1;
        RBus_UInt32  dma_vlc_ie:1;
        RBus_UInt32  dma_den_crc_sel:1;
        RBus_UInt32  res1:4;
        RBus_UInt32  dma_line_cnt:12;
        RBus_UInt32  dma_vln:12;
    };
}dma_vgip_dma_vgip_lc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  dma_crc_mode:1;
        RBus_UInt32  dma_crc_region:1;
        RBus_UInt32  dma_crc_ctrl_in:1;
        RBus_UInt32  dma_crc_field_edge_sel:1;
        RBus_UInt32  dma_crc_field:1;
        RBus_UInt32  dma_crc_conti:1;
        RBus_UInt32  dma_crc_start:1;
    };
}dma_vgip_dma_vgip_crc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_crc_result:32;
    };
}dma_vgip_dma_vgip_crc_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_wd_to_main:1;
        RBus_UInt32  dma_wd_to_sub:1;
        RBus_UInt32  dummy18022440_29_19:11;
        RBus_UInt32  dma_vs_err_wde:1;
        RBus_UInt32  dma_hs_err_wde:1;
        RBus_UInt32  dma_field_err_wde:1;
        RBus_UInt32  dma_rl_err_wde:1;
        RBus_UInt32  dummy18022440_14_4:11;
        RBus_UInt32  dma_rl_err_ie:1;
        RBus_UInt32  dma_vs_err_ie:1;
        RBus_UInt32  dma_hs_err_ie:1;
        RBus_UInt32  dma_field_err_ie:1;
    };
}dma_vgip_dma_vgip_wde_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  dma_pr_l_r_only_mask_hs:1;
        RBus_UInt32  dma_pr_l_r_only_rm_den:1;
        RBus_UInt32  dma_pr_l_r_only_en:1;
    };
}dma_vgip_dma_vgip_pr_l_r_only_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  dma_captst_r_data_2:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dma_captst_g_data_2:12;
    };
}dma_vgip_dma_vgip_ptn2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  dma_captst_b_data_3:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dma_captst_b_data_2:12;
    };
}dma_vgip_dma_vgip_ptn3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  dma_captst_r_data_3:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dma_captst_g_data_3:12;
    };
}dma_vgip_dma_vgip_ptn4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  dma_captst_r_data_4:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dma_captst_g_data_4:12;
    };
}dma_vgip_dma_vgip_ptn5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  dma_captst_b_data_4:12;
    };
}dma_vgip_dma_vgip_ptn6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_adc_test_dma_count:28;
        RBus_UInt32  res1:1;
        RBus_UInt32  dma_force_den:1;
        RBus_UInt32  dma_force_vsync:1;
        RBus_UInt32  dma_adc_test_dma_mode:1;
    };
}dma_vgip_dma_vgip_adc_raw_data_dma_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dma_vs_width:13;
        RBus_UInt32  dma_field_alternative_en:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  dma_frame_packing_en:1;
        RBus_UInt32  dma_vs_position:13;
    };
}dma_vgip_dma_vgip_framepacking_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dma_den_mask_start:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  dma_den_mask_end:13;
    };
}dma_vgip_dma_vgip_framepacking_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  dma_dummy_ctsfifo_sdnr:1;
        RBus_UInt32  dma_force_ctsfifo_rstn_sdnr:1;
        RBus_UInt32  dma_en_ctsfifo_vsrst_sdnr:1;
        RBus_UInt32  dma_en_ctsfifo_bypass_sdnr:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  dma_dummy_ctsfifo_vgip:1;
        RBus_UInt32  dma_force_ctsfifo_rstn_vgip:1;
        RBus_UInt32  dma_en_ctsfifo_vsrst_vgip:1;
        RBus_UInt32  dma_en_ctsfifo_bypass_vgip:1;
    };
}dma_vgip_dma_vgip_cts_fifo_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}dma_vgip_dma_vgip_dispi_test_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  dma_3d_right_ih_act_sta:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  dma_3d_right_ih_act_wid:14;
    };
}dma_vgip_dma_vgip_3d_right_act_hsta_width_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dma_3d_right_iv_act_sta:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  dma_3d_right_iv_act_len:13;
    };
}dma_vgip_dma_vgip_3d_right_act_vsta_length_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dma_vs_width_r_odd:13;
        RBus_UInt32  res2:2;
        RBus_UInt32  dma_frame_packing_field_en:1;
        RBus_UInt32  dma_vs_position_r_odd:13;
    };
}dma_vgip_dma_vgip_framepacking_interlace_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dma_den_mask_start_r_odd:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  dma_den_mask_end_r_odd:13;
    };
}dma_vgip_dma_vgip_framepacking_interlace_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dma_vs_width_r_even:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  dma_vs_position_r_even:13;
    };
}dma_vgip_dma_vgip_framepacking_interlace_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dma_den_mask_start_r_even:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  dma_den_mask_end_r_even:13;
    };
}dma_vgip_dma_vgip_framepacking_interlace_ctrl4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  dma_end_l:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  dma_sta_l:14;
    };
}dma_vgip_dma_vgip_l_r_active_enable_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_l_r_act_en:1;
        RBus_UInt32  dma_h_v_mode:1;
        RBus_UInt32  dma_end_r:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  dma_sta_r:14;
    };
}dma_vgip_dma_vgip_l_r_active_enable_ctrl2_RBUS;

#else //apply LITTLE_ENDIAN

//======DMA_VGIP register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_v8_dummy:8;
        RBus_UInt32  res1:24;
    };
}dma_vgip_dma_vgip_vclk_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18022404_7_0:8;
        RBus_UInt32  res1:24;
    };
}dma_vgip_dma_vgip_v8_1_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_select_duplicate_lsb:1;
        RBus_UInt32  dummy18022408_1:1;
        RBus_UInt32  res1:30;
    };
}dma_vgip_dma_vgip_v8_2_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_l_flag_delay_num:13;
        RBus_UInt32  dma_l_flag_sample_delay:2;
        RBus_UInt32  dma_l_flag_delay_en:1;
        RBus_UInt32  dma_auto_l_flag_delay_num:13;
        RBus_UInt32  res1:2;
        RBus_UInt32  dma_auto_l_flag_delay_en:1;
    };
}dma_vgip_dma_vgip_global_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_in_clk_en:1;
        RBus_UInt32  dma_digital_mode:1;
        RBus_UInt32  dma_hs_inv:1;
        RBus_UInt32  dma_vs_inv:1;
        RBus_UInt32  dma_vs_by_hs_en_n:1;
        RBus_UInt32  dma_vs_syncedge:1;
        RBus_UInt32  dma_hs_syncedge:1;
        RBus_UInt32  dma_3d_right_act_en:1;
        RBus_UInt32  dma_safe_mode:1;
        RBus_UInt32  dma_force_tog:1;
        RBus_UInt32  dma_safe_field_inv:1;
        RBus_UInt32  dma_3d_mode_en:1;
        RBus_UInt32  dma_mask_den_1l:1;
        RBus_UInt32  dma_mask_den_inv:1;
        RBus_UInt32  dma_fcap_str_odd:1;
        RBus_UInt32  dma_hpact_is_hact:1;
        RBus_UInt32  dma_field_det_en:1;
        RBus_UInt32  dma_field_sync_edge:1;
        RBus_UInt32  dma_field_inv:1;
        RBus_UInt32  dma_3dleft_sync_edge:1;
        RBus_UInt32  dma_3dleft_inv:1;
        RBus_UInt32  dma_field_vd_en:1;
        RBus_UInt32  dma_field_vd_inv:1;
        RBus_UInt32  dma_field_hs_inv:1;
        RBus_UInt32  dma_vact_start_ie:1;
        RBus_UInt32  dma_vact_end_ie:1;
        RBus_UInt32  dma_fdrop_en:1;
        RBus_UInt32  dma_random_en:1;
        RBus_UInt32  dma_in_sel:3;
        RBus_UInt32  dma_ivrun:1;
    };
}dma_vgip_dma_vgip_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_bounce_status_0:1;
        RBus_UInt32  dma_bounce_status_1:1;
        RBus_UInt32  dma_bounce_status_2:1;
        RBus_UInt32  dma_more_1line_field:1;
        RBus_UInt32  dma_field_vs_lsb:2;
        RBus_UInt32  dma_field_tog:1;
        RBus_UInt32  dma_field_pol:1;
        RBus_UInt32  dma_hs_tog:1;
        RBus_UInt32  dma_vs_tog:1;
        RBus_UInt32  dma_l_flag_pol:1;
        RBus_UInt32  dma_rl_tog:1;
        RBus_UInt32  dma_field_err:1;
        RBus_UInt32  dma_hs_err:1;
        RBus_UInt32  dma_vs_err:1;
        RBus_UInt32  dma_rl_err:1;
        RBus_UInt32  dma_vlc_status:1;
        RBus_UInt32  dummy18022414_23:7;
        RBus_UInt32  dma_vact_start:1;
        RBus_UInt32  dma_vact_end:1;
        RBus_UInt32  dma_vs_start:1;
        RBus_UInt32  dma_vs_end:1;
        RBus_UInt32  res1:4;
    };
}dma_vgip_dma_vgip_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_ih_act_wid:14;
        RBus_UInt32  dma_bypass_den:1;
        RBus_UInt32  dma_db_read_sel:1;
        RBus_UInt32  dma_ih_act_sta:14;
        RBus_UInt32  dma_db_en:1;
        RBus_UInt32  dma_db_rdy:1;
    };
}dma_vgip_dma_vgip_act_hsta_width_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_iv_act_len:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  dma_iv_act_sta:13;
        RBus_UInt32  res2:3;
    };
}dma_vgip_dma_vgip_act_vsta_length_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_ivs_dly:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  dma_ihs_dly:14;
        RBus_UInt32  dma_hs_width:2;
    };
}dma_vgip_dma_vgip_delay_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_v1_v3_swap:1;
        RBus_UInt32  dma_v2_v3_swap:1;
        RBus_UInt32  dma_v1_v2_swap:1;
        RBus_UInt32  dma_hdly_one:1;
        RBus_UInt32  dma_auto_ivs_dly:2;
        RBus_UInt32  dma_auto_ihs_dly:2;
        RBus_UInt32  dma_hporch_num:13;
        RBus_UInt32  dma_l_flag_force_tog:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  dma_hporch_num_sel:1;
        RBus_UInt32  res2:6;
        RBus_UInt32  dma_de_mask_en:1;
    };
}dma_vgip_dma_vgip_misc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_hcaptst_num:14;
        RBus_UInt32  res1:1;
        RBus_UInt32  dma_captst_field_sel:1;
        RBus_UInt32  dma_vcaptst_num:13;
        RBus_UInt32  dma_captst_mode:2;
        RBus_UInt32  dma_captst_en:1;
    };
}dma_vgip_dma_vgip_ptn_h_vi_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_captst_g_data:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  dma_captst_r_data:12;
        RBus_UInt32  res2:4;
    };
}dma_vgip_dma_vgip_ptn0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_captst_b_data:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  dma_hporch_num_sel:14;
        RBus_UInt32  res2:2;
    };
}dma_vgip_dma_vgip_ptn1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_vln:12;
        RBus_UInt32  dma_line_cnt:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  dma_den_crc_sel:1;
        RBus_UInt32  dma_vlc_ie:1;
        RBus_UInt32  dma_vlc_mode:1;
        RBus_UInt32  dma_vlcen:1;
    };
}dma_vgip_dma_vgip_lc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_crc_start:1;
        RBus_UInt32  dma_crc_conti:1;
        RBus_UInt32  dma_crc_field:1;
        RBus_UInt32  dma_crc_field_edge_sel:1;
        RBus_UInt32  dma_crc_ctrl_in:1;
        RBus_UInt32  dma_crc_region:1;
        RBus_UInt32  dma_crc_mode:1;
        RBus_UInt32  res1:25;
    };
}dma_vgip_dma_vgip_crc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_crc_result:32;
    };
}dma_vgip_dma_vgip_crc_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_field_err_ie:1;
        RBus_UInt32  dma_hs_err_ie:1;
        RBus_UInt32  dma_vs_err_ie:1;
        RBus_UInt32  dma_rl_err_ie:1;
        RBus_UInt32  dummy18022440_14:11;
        RBus_UInt32  dma_rl_err_wde:1;
        RBus_UInt32  dma_field_err_wde:1;
        RBus_UInt32  dma_hs_err_wde:1;
        RBus_UInt32  dma_vs_err_wde:1;
        RBus_UInt32  dummy18022440_29:11;
        RBus_UInt32  dma_wd_to_sub:1;
        RBus_UInt32  dma_wd_to_main:1;
    };
}dma_vgip_dma_vgip_wde_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_pr_l_r_only_en:1;
        RBus_UInt32  dma_pr_l_r_only_rm_den:1;
        RBus_UInt32  dma_pr_l_r_only_mask_hs:1;
        RBus_UInt32  res1:29;
    };
}dma_vgip_dma_vgip_pr_l_r_only_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_captst_g_data_2:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  dma_captst_r_data_2:12;
        RBus_UInt32  res2:4;
    };
}dma_vgip_dma_vgip_ptn2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_captst_b_data_2:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  dma_captst_b_data_3:12;
        RBus_UInt32  res2:4;
    };
}dma_vgip_dma_vgip_ptn3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_captst_g_data_3:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  dma_captst_r_data_3:12;
        RBus_UInt32  res2:4;
    };
}dma_vgip_dma_vgip_ptn4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_captst_g_data_4:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  dma_captst_r_data_4:12;
        RBus_UInt32  res2:4;
    };
}dma_vgip_dma_vgip_ptn5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_captst_b_data_4:12;
        RBus_UInt32  res1:20;
    };
}dma_vgip_dma_vgip_ptn6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_adc_test_dma_mode:1;
        RBus_UInt32  dma_force_vsync:1;
        RBus_UInt32  dma_force_den:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  dma_adc_test_dma_count:28;
    };
}dma_vgip_dma_vgip_adc_raw_data_dma_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_vs_position:13;
        RBus_UInt32  dma_frame_packing_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  dma_field_alternative_en:1;
        RBus_UInt32  dma_vs_width:13;
        RBus_UInt32  res2:3;
    };
}dma_vgip_dma_vgip_framepacking_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_den_mask_end:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  dma_den_mask_start:13;
        RBus_UInt32  res2:3;
    };
}dma_vgip_dma_vgip_framepacking_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_en_ctsfifo_bypass_vgip:1;
        RBus_UInt32  dma_en_ctsfifo_vsrst_vgip:1;
        RBus_UInt32  dma_force_ctsfifo_rstn_vgip:1;
        RBus_UInt32  dma_dummy_ctsfifo_vgip:1;
        RBus_UInt32  res1:4;
        RBus_UInt32  dma_en_ctsfifo_bypass_sdnr:1;
        RBus_UInt32  dma_en_ctsfifo_vsrst_sdnr:1;
        RBus_UInt32  dma_force_ctsfifo_rstn_sdnr:1;
        RBus_UInt32  dma_dummy_ctsfifo_sdnr:1;
        RBus_UInt32  res2:20;
    };
}dma_vgip_dma_vgip_cts_fifo_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}dma_vgip_dma_vgip_dispi_test_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_3d_right_ih_act_wid:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  dma_3d_right_ih_act_sta:14;
        RBus_UInt32  res2:2;
    };
}dma_vgip_dma_vgip_3d_right_act_hsta_width_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_3d_right_iv_act_len:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  dma_3d_right_iv_act_sta:13;
        RBus_UInt32  res2:3;
    };
}dma_vgip_dma_vgip_3d_right_act_vsta_length_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_vs_position_r_odd:13;
        RBus_UInt32  dma_frame_packing_field_en:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  dma_vs_width_r_odd:13;
        RBus_UInt32  res2:3;
    };
}dma_vgip_dma_vgip_framepacking_interlace_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_den_mask_end_r_odd:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  dma_den_mask_start_r_odd:13;
        RBus_UInt32  res2:3;
    };
}dma_vgip_dma_vgip_framepacking_interlace_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_vs_position_r_even:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  dma_vs_width_r_even:13;
        RBus_UInt32  res2:3;
    };
}dma_vgip_dma_vgip_framepacking_interlace_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_den_mask_end_r_even:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  dma_den_mask_start_r_even:13;
        RBus_UInt32  res2:3;
    };
}dma_vgip_dma_vgip_framepacking_interlace_ctrl4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_sta_l:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  dma_end_l:14;
        RBus_UInt32  res2:2;
    };
}dma_vgip_dma_vgip_l_r_active_enable_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_sta_r:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  dma_end_r:14;
        RBus_UInt32  dma_h_v_mode:1;
        RBus_UInt32  dma_l_r_act_en:1;
    };
}dma_vgip_dma_vgip_l_r_active_enable_ctrl2_RBUS;




#endif 


#endif 
