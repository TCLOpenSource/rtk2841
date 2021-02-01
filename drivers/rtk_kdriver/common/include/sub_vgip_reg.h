/**
* @file rbusSub_vgipReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2016/12/21
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_SUB_VGIP_REG_H_
#define _RBUS_SUB_VGIP_REG_H_

#include "rbus_types.h"



//  SUB_VGIP Register Address
#define  SUB_VGIP_SUB_VCLK_CTRL                                                  0x18022700
#define  SUB_VGIP_SUB_VCLK_CTRL_reg_addr                                         "0xB8022700"
#define  SUB_VGIP_SUB_VCLK_CTRL_reg                                              0xB8022700
#define  SUB_VGIP_SUB_VCLK_CTRL_inst_addr                                        "0x0000"
#define  set_SUB_VGIP_SUB_VCLK_CTRL_reg(data)                                    (*((volatile unsigned int*)SUB_VGIP_SUB_VCLK_CTRL_reg)=data)
#define  get_SUB_VGIP_SUB_VCLK_CTRL_reg                                          (*((volatile unsigned int*)SUB_VGIP_SUB_VCLK_CTRL_reg))
#define  SUB_VGIP_SUB_VCLK_CTRL_ch2_v8_dummy_shift                               (0)
#define  SUB_VGIP_SUB_VCLK_CTRL_ch2_v8_dummy_mask                                (0x000000FF)
#define  SUB_VGIP_SUB_VCLK_CTRL_ch2_v8_dummy(data)                               (0x000000FF&(data))
#define  SUB_VGIP_SUB_VCLK_CTRL_get_ch2_v8_dummy(data)                           (0x000000FF&(data))

#define  SUB_VGIP_SUB_V8_1_CTRL                                                  0x18022704
#define  SUB_VGIP_SUB_V8_1_CTRL_reg_addr                                         "0xB8022704"
#define  SUB_VGIP_SUB_V8_1_CTRL_reg                                              0xB8022704
#define  SUB_VGIP_SUB_V8_1_CTRL_inst_addr                                        "0x0001"
#define  set_SUB_VGIP_SUB_V8_1_CTRL_reg(data)                                    (*((volatile unsigned int*)SUB_VGIP_SUB_V8_1_CTRL_reg)=data)
#define  get_SUB_VGIP_SUB_V8_1_CTRL_reg                                          (*((volatile unsigned int*)SUB_VGIP_SUB_V8_1_CTRL_reg))
#define  SUB_VGIP_SUB_V8_1_CTRL_dummy_7_0_shift                                  (0)
#define  SUB_VGIP_SUB_V8_1_CTRL_dummy_7_0_mask                                   (0x000000FF)
#define  SUB_VGIP_SUB_V8_1_CTRL_dummy_7_0(data)                                  (0x000000FF&(data))
#define  SUB_VGIP_SUB_V8_1_CTRL_get_dummy_7_0(data)                              (0x000000FF&(data))

#define  SUB_VGIP_SUB_V8_2_CTRL                                                  0x18022708
#define  SUB_VGIP_SUB_V8_2_CTRL_reg_addr                                         "0xB8022708"
#define  SUB_VGIP_SUB_V8_2_CTRL_reg                                              0xB8022708
#define  SUB_VGIP_SUB_V8_2_CTRL_inst_addr                                        "0x0002"
#define  set_SUB_VGIP_SUB_V8_2_CTRL_reg(data)                                    (*((volatile unsigned int*)SUB_VGIP_SUB_V8_2_CTRL_reg)=data)
#define  get_SUB_VGIP_SUB_V8_2_CTRL_reg                                          (*((volatile unsigned int*)SUB_VGIP_SUB_V8_2_CTRL_reg))
#define  SUB_VGIP_SUB_V8_2_CTRL_ch2_select_duplicate_lsb_shift                   (0)
#define  SUB_VGIP_SUB_V8_2_CTRL_ch2_select_duplicate_lsb_mask                    (0x00000001)
#define  SUB_VGIP_SUB_V8_2_CTRL_ch2_select_duplicate_lsb(data)                   (0x00000001&(data))
#define  SUB_VGIP_SUB_V8_2_CTRL_get_ch2_select_duplicate_lsb(data)               (0x00000001&(data))

#define  SUB_VGIP_SUB_VGIP_GLOBAL_CTRL                                           0x1802270C
#define  SUB_VGIP_SUB_VGIP_GLOBAL_CTRL_reg_addr                                  "0xB802270C"
#define  SUB_VGIP_SUB_VGIP_GLOBAL_CTRL_reg                                       0xB802270C
#define  SUB_VGIP_SUB_VGIP_GLOBAL_CTRL_inst_addr                                 "0x0003"
#define  set_SUB_VGIP_SUB_VGIP_GLOBAL_CTRL_reg(data)                             (*((volatile unsigned int*)SUB_VGIP_SUB_VGIP_GLOBAL_CTRL_reg)=data)
#define  get_SUB_VGIP_SUB_VGIP_GLOBAL_CTRL_reg                                   (*((volatile unsigned int*)SUB_VGIP_SUB_VGIP_GLOBAL_CTRL_reg))
#define  SUB_VGIP_SUB_VGIP_GLOBAL_CTRL_ch2_auto_l_flag_delay_en_shift            (31)
#define  SUB_VGIP_SUB_VGIP_GLOBAL_CTRL_ch2_vs_rise_sample_delay_sel_shift        (29)
#define  SUB_VGIP_SUB_VGIP_GLOBAL_CTRL_ch2_auto_l_flag_delay_num_shift           (16)
#define  SUB_VGIP_SUB_VGIP_GLOBAL_CTRL_ch2_l_flag_delay_en_shift                 (15)
#define  SUB_VGIP_SUB_VGIP_GLOBAL_CTRL_ch2_l_flag_field_sample_delay_shift       (13)
#define  SUB_VGIP_SUB_VGIP_GLOBAL_CTRL_ch2_l_flag_delay_num_shift                (0)
#define  SUB_VGIP_SUB_VGIP_GLOBAL_CTRL_ch2_auto_l_flag_delay_en_mask             (0x80000000)
#define  SUB_VGIP_SUB_VGIP_GLOBAL_CTRL_ch2_vs_rise_sample_delay_sel_mask         (0x20000000)
#define  SUB_VGIP_SUB_VGIP_GLOBAL_CTRL_ch2_auto_l_flag_delay_num_mask            (0x1FFF0000)
#define  SUB_VGIP_SUB_VGIP_GLOBAL_CTRL_ch2_l_flag_delay_en_mask                  (0x00008000)
#define  SUB_VGIP_SUB_VGIP_GLOBAL_CTRL_ch2_l_flag_field_sample_delay_mask        (0x00006000)
#define  SUB_VGIP_SUB_VGIP_GLOBAL_CTRL_ch2_l_flag_delay_num_mask                 (0x00001FFF)
#define  SUB_VGIP_SUB_VGIP_GLOBAL_CTRL_ch2_auto_l_flag_delay_en(data)            (0x80000000&((data)<<31))
#define  SUB_VGIP_SUB_VGIP_GLOBAL_CTRL_ch2_vs_rise_sample_delay_sel(data)        (0x20000000&((data)<<29))
#define  SUB_VGIP_SUB_VGIP_GLOBAL_CTRL_ch2_auto_l_flag_delay_num(data)           (0x1FFF0000&((data)<<16))
#define  SUB_VGIP_SUB_VGIP_GLOBAL_CTRL_ch2_l_flag_delay_en(data)                 (0x00008000&((data)<<15))
#define  SUB_VGIP_SUB_VGIP_GLOBAL_CTRL_ch2_l_flag_field_sample_delay(data)       (0x00006000&((data)<<13))
#define  SUB_VGIP_SUB_VGIP_GLOBAL_CTRL_ch2_l_flag_delay_num(data)                (0x00001FFF&(data))
#define  SUB_VGIP_SUB_VGIP_GLOBAL_CTRL_get_ch2_auto_l_flag_delay_en(data)        ((0x80000000&(data))>>31)
#define  SUB_VGIP_SUB_VGIP_GLOBAL_CTRL_get_ch2_vs_rise_sample_delay_sel(data)    ((0x20000000&(data))>>29)
#define  SUB_VGIP_SUB_VGIP_GLOBAL_CTRL_get_ch2_auto_l_flag_delay_num(data)       ((0x1FFF0000&(data))>>16)
#define  SUB_VGIP_SUB_VGIP_GLOBAL_CTRL_get_ch2_l_flag_delay_en(data)             ((0x00008000&(data))>>15)
#define  SUB_VGIP_SUB_VGIP_GLOBAL_CTRL_get_ch2_l_flag_field_sample_delay(data)   ((0x00006000&(data))>>13)
#define  SUB_VGIP_SUB_VGIP_GLOBAL_CTRL_get_ch2_l_flag_delay_num(data)            (0x00001FFF&(data))

#define  SUB_VGIP_VGIP_CHN2_CTRL                                                 0x18022710
#define  SUB_VGIP_VGIP_CHN2_CTRL_reg_addr                                        "0xB8022710"
#define  SUB_VGIP_VGIP_CHN2_CTRL_reg                                             0xB8022710
#define  SUB_VGIP_VGIP_CHN2_CTRL_inst_addr                                       "0x0004"
#define  set_SUB_VGIP_VGIP_CHN2_CTRL_reg(data)                                   (*((volatile unsigned int*)SUB_VGIP_VGIP_CHN2_CTRL_reg)=data)
#define  get_SUB_VGIP_VGIP_CHN2_CTRL_reg                                         (*((volatile unsigned int*)SUB_VGIP_VGIP_CHN2_CTRL_reg))
#define  SUB_VGIP_VGIP_CHN2_CTRL_ch2_ivrun_shift                                 (31)
#define  SUB_VGIP_VGIP_CHN2_CTRL_ch2_in_sel_shift                                (28)
#define  SUB_VGIP_VGIP_CHN2_CTRL_ch2_random_en_shift                             (27)
#define  SUB_VGIP_VGIP_CHN2_CTRL_ch2_fdrop_en_shift                              (26)
#define  SUB_VGIP_VGIP_CHN2_CTRL_ch2_vact_end_ie_shift                           (25)
#define  SUB_VGIP_VGIP_CHN2_CTRL_ch2_vact_start_ie_shift                         (24)
#define  SUB_VGIP_VGIP_CHN2_CTRL_ch2_field_hs_inv_shift                          (23)
#define  SUB_VGIP_VGIP_CHN2_CTRL_ch2_field_vd_inv_shift                          (22)
#define  SUB_VGIP_VGIP_CHN2_CTRL_ch2_field_vd_en_shift                           (21)
#define  SUB_VGIP_VGIP_CHN2_CTRL_ch2_3dleft_inv_shift                            (20)
#define  SUB_VGIP_VGIP_CHN2_CTRL_ch2_3dleft_sync_edge_shift                      (19)
#define  SUB_VGIP_VGIP_CHN2_CTRL_ch2_field_inv_shift                             (18)
#define  SUB_VGIP_VGIP_CHN2_CTRL_ch2_field_sync_edge_shift                       (17)
#define  SUB_VGIP_VGIP_CHN2_CTRL_ch2_field_det_en_shift                          (16)
#define  SUB_VGIP_VGIP_CHN2_CTRL_ch2_hpact_is_hact_shift                         (15)
#define  SUB_VGIP_VGIP_CHN2_CTRL_ch2_fcap_str_odd_shift                          (14)
#define  SUB_VGIP_VGIP_CHN2_CTRL_ch2_mask_den_inv_shift                          (13)
#define  SUB_VGIP_VGIP_CHN2_CTRL_ch2_mask_den_1l_shift                           (12)
#define  SUB_VGIP_VGIP_CHN2_CTRL_ch2_3d_mode_en_shift                            (11)
#define  SUB_VGIP_VGIP_CHN2_CTRL_ch2_safe_field_inv_shift                        (10)
#define  SUB_VGIP_VGIP_CHN2_CTRL_ch2_force_tog_shift                             (9)
#define  SUB_VGIP_VGIP_CHN2_CTRL_ch2_safe_mode_shift                             (8)
#define  SUB_VGIP_VGIP_CHN2_CTRL_ch2_hs_syncedge_shift                           (6)
#define  SUB_VGIP_VGIP_CHN2_CTRL_ch2_vs_syncedge_shift                           (5)
#define  SUB_VGIP_VGIP_CHN2_CTRL_ch2_vs_by_hs_en_n_shift                         (4)
#define  SUB_VGIP_VGIP_CHN2_CTRL_ch2_vs_inv_shift                                (3)
#define  SUB_VGIP_VGIP_CHN2_CTRL_ch2_hs_inv_shift                                (2)
#define  SUB_VGIP_VGIP_CHN2_CTRL_ch2_digital_mode_shift                          (1)
#define  SUB_VGIP_VGIP_CHN2_CTRL_ch2_in_clk_en_shift                             (0)
#define  SUB_VGIP_VGIP_CHN2_CTRL_ch2_ivrun_mask                                  (0x80000000)
#define  SUB_VGIP_VGIP_CHN2_CTRL_ch2_in_sel_mask                                 (0x10000000)
#define  SUB_VGIP_VGIP_CHN2_CTRL_ch2_random_en_mask                              (0x08000000)
#define  SUB_VGIP_VGIP_CHN2_CTRL_ch2_fdrop_en_mask                               (0x04000000)
#define  SUB_VGIP_VGIP_CHN2_CTRL_ch2_vact_end_ie_mask                            (0x02000000)
#define  SUB_VGIP_VGIP_CHN2_CTRL_ch2_vact_start_ie_mask                          (0x01000000)
#define  SUB_VGIP_VGIP_CHN2_CTRL_ch2_field_hs_inv_mask                           (0x00800000)
#define  SUB_VGIP_VGIP_CHN2_CTRL_ch2_field_vd_inv_mask                           (0x00400000)
#define  SUB_VGIP_VGIP_CHN2_CTRL_ch2_field_vd_en_mask                            (0x00200000)
#define  SUB_VGIP_VGIP_CHN2_CTRL_ch2_3dleft_inv_mask                             (0x00100000)
#define  SUB_VGIP_VGIP_CHN2_CTRL_ch2_3dleft_sync_edge_mask                       (0x00080000)
#define  SUB_VGIP_VGIP_CHN2_CTRL_ch2_field_inv_mask                              (0x00040000)
#define  SUB_VGIP_VGIP_CHN2_CTRL_ch2_field_sync_edge_mask                        (0x00020000)
#define  SUB_VGIP_VGIP_CHN2_CTRL_ch2_field_det_en_mask                           (0x00010000)
#define  SUB_VGIP_VGIP_CHN2_CTRL_ch2_hpact_is_hact_mask                          (0x00008000)
#define  SUB_VGIP_VGIP_CHN2_CTRL_ch2_fcap_str_odd_mask                           (0x00004000)
#define  SUB_VGIP_VGIP_CHN2_CTRL_ch2_mask_den_inv_mask                           (0x00002000)
#define  SUB_VGIP_VGIP_CHN2_CTRL_ch2_mask_den_1l_mask                            (0x00001000)
#define  SUB_VGIP_VGIP_CHN2_CTRL_ch2_3d_mode_en_mask                             (0x00000800)
#define  SUB_VGIP_VGIP_CHN2_CTRL_ch2_safe_field_inv_mask                         (0x00000400)
#define  SUB_VGIP_VGIP_CHN2_CTRL_ch2_force_tog_mask                              (0x00000200)
#define  SUB_VGIP_VGIP_CHN2_CTRL_ch2_safe_mode_mask                              (0x00000100)
#define  SUB_VGIP_VGIP_CHN2_CTRL_ch2_hs_syncedge_mask                            (0x00000040)
#define  SUB_VGIP_VGIP_CHN2_CTRL_ch2_vs_syncedge_mask                            (0x00000020)
#define  SUB_VGIP_VGIP_CHN2_CTRL_ch2_vs_by_hs_en_n_mask                          (0x00000010)
#define  SUB_VGIP_VGIP_CHN2_CTRL_ch2_vs_inv_mask                                 (0x00000008)
#define  SUB_VGIP_VGIP_CHN2_CTRL_ch2_hs_inv_mask                                 (0x00000004)
#define  SUB_VGIP_VGIP_CHN2_CTRL_ch2_digital_mode_mask                           (0x00000002)
#define  SUB_VGIP_VGIP_CHN2_CTRL_ch2_in_clk_en_mask                              (0x00000001)
#define  SUB_VGIP_VGIP_CHN2_CTRL_ch2_ivrun(data)                                 (0x80000000&((data)<<31))
#define  SUB_VGIP_VGIP_CHN2_CTRL_ch2_in_sel(data)                                (0x10000000&((data)<<28))
#define  SUB_VGIP_VGIP_CHN2_CTRL_ch2_random_en(data)                             (0x08000000&((data)<<27))
#define  SUB_VGIP_VGIP_CHN2_CTRL_ch2_fdrop_en(data)                              (0x04000000&((data)<<26))
#define  SUB_VGIP_VGIP_CHN2_CTRL_ch2_vact_end_ie(data)                           (0x02000000&((data)<<25))
#define  SUB_VGIP_VGIP_CHN2_CTRL_ch2_vact_start_ie(data)                         (0x01000000&((data)<<24))
#define  SUB_VGIP_VGIP_CHN2_CTRL_ch2_field_hs_inv(data)                          (0x00800000&((data)<<23))
#define  SUB_VGIP_VGIP_CHN2_CTRL_ch2_field_vd_inv(data)                          (0x00400000&((data)<<22))
#define  SUB_VGIP_VGIP_CHN2_CTRL_ch2_field_vd_en(data)                           (0x00200000&((data)<<21))
#define  SUB_VGIP_VGIP_CHN2_CTRL_ch2_3dleft_inv(data)                            (0x00100000&((data)<<20))
#define  SUB_VGIP_VGIP_CHN2_CTRL_ch2_3dleft_sync_edge(data)                      (0x00080000&((data)<<19))
#define  SUB_VGIP_VGIP_CHN2_CTRL_ch2_field_inv(data)                             (0x00040000&((data)<<18))
#define  SUB_VGIP_VGIP_CHN2_CTRL_ch2_field_sync_edge(data)                       (0x00020000&((data)<<17))
#define  SUB_VGIP_VGIP_CHN2_CTRL_ch2_field_det_en(data)                          (0x00010000&((data)<<16))
#define  SUB_VGIP_VGIP_CHN2_CTRL_ch2_hpact_is_hact(data)                         (0x00008000&((data)<<15))
#define  SUB_VGIP_VGIP_CHN2_CTRL_ch2_fcap_str_odd(data)                          (0x00004000&((data)<<14))
#define  SUB_VGIP_VGIP_CHN2_CTRL_ch2_mask_den_inv(data)                          (0x00002000&((data)<<13))
#define  SUB_VGIP_VGIP_CHN2_CTRL_ch2_mask_den_1l(data)                           (0x00001000&((data)<<12))
#define  SUB_VGIP_VGIP_CHN2_CTRL_ch2_3d_mode_en(data)                            (0x00000800&((data)<<11))
#define  SUB_VGIP_VGIP_CHN2_CTRL_ch2_safe_field_inv(data)                        (0x00000400&((data)<<10))
#define  SUB_VGIP_VGIP_CHN2_CTRL_ch2_force_tog(data)                             (0x00000200&((data)<<9))
#define  SUB_VGIP_VGIP_CHN2_CTRL_ch2_safe_mode(data)                             (0x00000100&((data)<<8))
#define  SUB_VGIP_VGIP_CHN2_CTRL_ch2_hs_syncedge(data)                           (0x00000040&((data)<<6))
#define  SUB_VGIP_VGIP_CHN2_CTRL_ch2_vs_syncedge(data)                           (0x00000020&((data)<<5))
#define  SUB_VGIP_VGIP_CHN2_CTRL_ch2_vs_by_hs_en_n(data)                         (0x00000010&((data)<<4))
#define  SUB_VGIP_VGIP_CHN2_CTRL_ch2_vs_inv(data)                                (0x00000008&((data)<<3))
#define  SUB_VGIP_VGIP_CHN2_CTRL_ch2_hs_inv(data)                                (0x00000004&((data)<<2))
#define  SUB_VGIP_VGIP_CHN2_CTRL_ch2_digital_mode(data)                          (0x00000002&((data)<<1))
#define  SUB_VGIP_VGIP_CHN2_CTRL_ch2_in_clk_en(data)                             (0x00000001&(data))
#define  SUB_VGIP_VGIP_CHN2_CTRL_get_ch2_ivrun(data)                             ((0x80000000&(data))>>31)
#define  SUB_VGIP_VGIP_CHN2_CTRL_get_ch2_in_sel(data)                            ((0x10000000&(data))>>28)
#define  SUB_VGIP_VGIP_CHN2_CTRL_get_ch2_random_en(data)                         ((0x08000000&(data))>>27)
#define  SUB_VGIP_VGIP_CHN2_CTRL_get_ch2_fdrop_en(data)                          ((0x04000000&(data))>>26)
#define  SUB_VGIP_VGIP_CHN2_CTRL_get_ch2_vact_end_ie(data)                       ((0x02000000&(data))>>25)
#define  SUB_VGIP_VGIP_CHN2_CTRL_get_ch2_vact_start_ie(data)                     ((0x01000000&(data))>>24)
#define  SUB_VGIP_VGIP_CHN2_CTRL_get_ch2_field_hs_inv(data)                      ((0x00800000&(data))>>23)
#define  SUB_VGIP_VGIP_CHN2_CTRL_get_ch2_field_vd_inv(data)                      ((0x00400000&(data))>>22)
#define  SUB_VGIP_VGIP_CHN2_CTRL_get_ch2_field_vd_en(data)                       ((0x00200000&(data))>>21)
#define  SUB_VGIP_VGIP_CHN2_CTRL_get_ch2_3dleft_inv(data)                        ((0x00100000&(data))>>20)
#define  SUB_VGIP_VGIP_CHN2_CTRL_get_ch2_3dleft_sync_edge(data)                  ((0x00080000&(data))>>19)
#define  SUB_VGIP_VGIP_CHN2_CTRL_get_ch2_field_inv(data)                         ((0x00040000&(data))>>18)
#define  SUB_VGIP_VGIP_CHN2_CTRL_get_ch2_field_sync_edge(data)                   ((0x00020000&(data))>>17)
#define  SUB_VGIP_VGIP_CHN2_CTRL_get_ch2_field_det_en(data)                      ((0x00010000&(data))>>16)
#define  SUB_VGIP_VGIP_CHN2_CTRL_get_ch2_hpact_is_hact(data)                     ((0x00008000&(data))>>15)
#define  SUB_VGIP_VGIP_CHN2_CTRL_get_ch2_fcap_str_odd(data)                      ((0x00004000&(data))>>14)
#define  SUB_VGIP_VGIP_CHN2_CTRL_get_ch2_mask_den_inv(data)                      ((0x00002000&(data))>>13)
#define  SUB_VGIP_VGIP_CHN2_CTRL_get_ch2_mask_den_1l(data)                       ((0x00001000&(data))>>12)
#define  SUB_VGIP_VGIP_CHN2_CTRL_get_ch2_3d_mode_en(data)                        ((0x00000800&(data))>>11)
#define  SUB_VGIP_VGIP_CHN2_CTRL_get_ch2_safe_field_inv(data)                    ((0x00000400&(data))>>10)
#define  SUB_VGIP_VGIP_CHN2_CTRL_get_ch2_force_tog(data)                         ((0x00000200&(data))>>9)
#define  SUB_VGIP_VGIP_CHN2_CTRL_get_ch2_safe_mode(data)                         ((0x00000100&(data))>>8)
#define  SUB_VGIP_VGIP_CHN2_CTRL_get_ch2_hs_syncedge(data)                       ((0x00000040&(data))>>6)
#define  SUB_VGIP_VGIP_CHN2_CTRL_get_ch2_vs_syncedge(data)                       ((0x00000020&(data))>>5)
#define  SUB_VGIP_VGIP_CHN2_CTRL_get_ch2_vs_by_hs_en_n(data)                     ((0x00000010&(data))>>4)
#define  SUB_VGIP_VGIP_CHN2_CTRL_get_ch2_vs_inv(data)                            ((0x00000008&(data))>>3)
#define  SUB_VGIP_VGIP_CHN2_CTRL_get_ch2_hs_inv(data)                            ((0x00000004&(data))>>2)
#define  SUB_VGIP_VGIP_CHN2_CTRL_get_ch2_digital_mode(data)                      ((0x00000002&(data))>>1)
#define  SUB_VGIP_VGIP_CHN2_CTRL_get_ch2_in_clk_en(data)                         (0x00000001&(data))

#define  SUB_VGIP_VGIP_CHN2_STATUS                                               0x18022714
#define  SUB_VGIP_VGIP_CHN2_STATUS_reg_addr                                      "0xB8022714"
#define  SUB_VGIP_VGIP_CHN2_STATUS_reg                                           0xB8022714
#define  SUB_VGIP_VGIP_CHN2_STATUS_inst_addr                                     "0x0005"
#define  set_SUB_VGIP_VGIP_CHN2_STATUS_reg(data)                                 (*((volatile unsigned int*)SUB_VGIP_VGIP_CHN2_STATUS_reg)=data)
#define  get_SUB_VGIP_VGIP_CHN2_STATUS_reg                                       (*((volatile unsigned int*)SUB_VGIP_VGIP_CHN2_STATUS_reg))
#define  SUB_VGIP_VGIP_CHN2_STATUS_ch2_vs_end_shift                              (27)
#define  SUB_VGIP_VGIP_CHN2_STATUS_ch2_vs_start_shift                            (26)
#define  SUB_VGIP_VGIP_CHN2_STATUS_ch2_vact_end_shift                            (25)
#define  SUB_VGIP_VGIP_CHN2_STATUS_ch2_vact_start_shift                          (24)
#define  SUB_VGIP_VGIP_CHN2_STATUS_dummy_23_17_shift                             (17)
#define  SUB_VGIP_VGIP_CHN2_STATUS_ch2_vlc_status_shift                          (16)
#define  SUB_VGIP_VGIP_CHN2_STATUS_ch2_rl_err_shift                              (15)
#define  SUB_VGIP_VGIP_CHN2_STATUS_ch2_vs_err_shift                              (14)
#define  SUB_VGIP_VGIP_CHN2_STATUS_ch2_hs_err_shift                              (13)
#define  SUB_VGIP_VGIP_CHN2_STATUS_ch2_field_err_shift                           (12)
#define  SUB_VGIP_VGIP_CHN2_STATUS_ch2_rl_tog_shift                              (11)
#define  SUB_VGIP_VGIP_CHN2_STATUS_ch2_l_flag_pol_shift                          (10)
#define  SUB_VGIP_VGIP_CHN2_STATUS_ch2_vs_tog_shift                              (9)
#define  SUB_VGIP_VGIP_CHN2_STATUS_ch2_hs_tog_shift                              (8)
#define  SUB_VGIP_VGIP_CHN2_STATUS_ch2_field_pol_shift                           (7)
#define  SUB_VGIP_VGIP_CHN2_STATUS_ch2_field_tog_shift                           (6)
#define  SUB_VGIP_VGIP_CHN2_STATUS_ch2_field_vs_lsb_shift                        (4)
#define  SUB_VGIP_VGIP_CHN2_STATUS_ch2_more_1line_field_shift                    (3)
#define  SUB_VGIP_VGIP_CHN2_STATUS_ch2_bounce_status_2_shift                     (2)
#define  SUB_VGIP_VGIP_CHN2_STATUS_ch2_bounce_status_1_shift                     (1)
#define  SUB_VGIP_VGIP_CHN2_STATUS_ch2_bounce_status_0_shift                     (0)
#define  SUB_VGIP_VGIP_CHN2_STATUS_ch2_vs_end_mask                               (0x08000000)
#define  SUB_VGIP_VGIP_CHN2_STATUS_ch2_vs_start_mask                             (0x04000000)
#define  SUB_VGIP_VGIP_CHN2_STATUS_ch2_vact_end_mask                             (0x02000000)
#define  SUB_VGIP_VGIP_CHN2_STATUS_ch2_vact_start_mask                           (0x01000000)
#define  SUB_VGIP_VGIP_CHN2_STATUS_dummy_23_17_mask                              (0x00FE0000)
#define  SUB_VGIP_VGIP_CHN2_STATUS_ch2_vlc_status_mask                           (0x00010000)
#define  SUB_VGIP_VGIP_CHN2_STATUS_ch2_rl_err_mask                               (0x00008000)
#define  SUB_VGIP_VGIP_CHN2_STATUS_ch2_vs_err_mask                               (0x00004000)
#define  SUB_VGIP_VGIP_CHN2_STATUS_ch2_hs_err_mask                               (0x00002000)
#define  SUB_VGIP_VGIP_CHN2_STATUS_ch2_field_err_mask                            (0x00001000)
#define  SUB_VGIP_VGIP_CHN2_STATUS_ch2_rl_tog_mask                               (0x00000800)
#define  SUB_VGIP_VGIP_CHN2_STATUS_ch2_l_flag_pol_mask                           (0x00000400)
#define  SUB_VGIP_VGIP_CHN2_STATUS_ch2_vs_tog_mask                               (0x00000200)
#define  SUB_VGIP_VGIP_CHN2_STATUS_ch2_hs_tog_mask                               (0x00000100)
#define  SUB_VGIP_VGIP_CHN2_STATUS_ch2_field_pol_mask                            (0x00000080)
#define  SUB_VGIP_VGIP_CHN2_STATUS_ch2_field_tog_mask                            (0x00000040)
#define  SUB_VGIP_VGIP_CHN2_STATUS_ch2_field_vs_lsb_mask                         (0x00000030)
#define  SUB_VGIP_VGIP_CHN2_STATUS_ch2_more_1line_field_mask                     (0x00000008)
#define  SUB_VGIP_VGIP_CHN2_STATUS_ch2_bounce_status_2_mask                      (0x00000004)
#define  SUB_VGIP_VGIP_CHN2_STATUS_ch2_bounce_status_1_mask                      (0x00000002)
#define  SUB_VGIP_VGIP_CHN2_STATUS_ch2_bounce_status_0_mask                      (0x00000001)
#define  SUB_VGIP_VGIP_CHN2_STATUS_ch2_vs_end(data)                              (0x08000000&((data)<<27))
#define  SUB_VGIP_VGIP_CHN2_STATUS_ch2_vs_start(data)                            (0x04000000&((data)<<26))
#define  SUB_VGIP_VGIP_CHN2_STATUS_ch2_vact_end(data)                            (0x02000000&((data)<<25))
#define  SUB_VGIP_VGIP_CHN2_STATUS_ch2_vact_start(data)                          (0x01000000&((data)<<24))
#define  SUB_VGIP_VGIP_CHN2_STATUS_dummy_23_17(data)                             (0x00FE0000&((data)<<17))
#define  SUB_VGIP_VGIP_CHN2_STATUS_ch2_vlc_status(data)                          (0x00010000&((data)<<16))
#define  SUB_VGIP_VGIP_CHN2_STATUS_ch2_rl_err(data)                              (0x00008000&((data)<<15))
#define  SUB_VGIP_VGIP_CHN2_STATUS_ch2_vs_err(data)                              (0x00004000&((data)<<14))
#define  SUB_VGIP_VGIP_CHN2_STATUS_ch2_hs_err(data)                              (0x00002000&((data)<<13))
#define  SUB_VGIP_VGIP_CHN2_STATUS_ch2_field_err(data)                           (0x00001000&((data)<<12))
#define  SUB_VGIP_VGIP_CHN2_STATUS_ch2_rl_tog(data)                              (0x00000800&((data)<<11))
#define  SUB_VGIP_VGIP_CHN2_STATUS_ch2_l_flag_pol(data)                          (0x00000400&((data)<<10))
#define  SUB_VGIP_VGIP_CHN2_STATUS_ch2_vs_tog(data)                              (0x00000200&((data)<<9))
#define  SUB_VGIP_VGIP_CHN2_STATUS_ch2_hs_tog(data)                              (0x00000100&((data)<<8))
#define  SUB_VGIP_VGIP_CHN2_STATUS_ch2_field_pol(data)                           (0x00000080&((data)<<7))
#define  SUB_VGIP_VGIP_CHN2_STATUS_ch2_field_tog(data)                           (0x00000040&((data)<<6))
#define  SUB_VGIP_VGIP_CHN2_STATUS_ch2_field_vs_lsb(data)                        (0x00000030&((data)<<4))
#define  SUB_VGIP_VGIP_CHN2_STATUS_ch2_more_1line_field(data)                    (0x00000008&((data)<<3))
#define  SUB_VGIP_VGIP_CHN2_STATUS_ch2_bounce_status_2(data)                     (0x00000004&((data)<<2))
#define  SUB_VGIP_VGIP_CHN2_STATUS_ch2_bounce_status_1(data)                     (0x00000002&((data)<<1))
#define  SUB_VGIP_VGIP_CHN2_STATUS_ch2_bounce_status_0(data)                     (0x00000001&(data))
#define  SUB_VGIP_VGIP_CHN2_STATUS_get_ch2_vs_end(data)                          ((0x08000000&(data))>>27)
#define  SUB_VGIP_VGIP_CHN2_STATUS_get_ch2_vs_start(data)                        ((0x04000000&(data))>>26)
#define  SUB_VGIP_VGIP_CHN2_STATUS_get_ch2_vact_end(data)                        ((0x02000000&(data))>>25)
#define  SUB_VGIP_VGIP_CHN2_STATUS_get_ch2_vact_start(data)                      ((0x01000000&(data))>>24)
#define  SUB_VGIP_VGIP_CHN2_STATUS_get_dummy_23_17(data)                         ((0x00FE0000&(data))>>17)
#define  SUB_VGIP_VGIP_CHN2_STATUS_get_ch2_vlc_status(data)                      ((0x00010000&(data))>>16)
#define  SUB_VGIP_VGIP_CHN2_STATUS_get_ch2_rl_err(data)                          ((0x00008000&(data))>>15)
#define  SUB_VGIP_VGIP_CHN2_STATUS_get_ch2_vs_err(data)                          ((0x00004000&(data))>>14)
#define  SUB_VGIP_VGIP_CHN2_STATUS_get_ch2_hs_err(data)                          ((0x00002000&(data))>>13)
#define  SUB_VGIP_VGIP_CHN2_STATUS_get_ch2_field_err(data)                       ((0x00001000&(data))>>12)
#define  SUB_VGIP_VGIP_CHN2_STATUS_get_ch2_rl_tog(data)                          ((0x00000800&(data))>>11)
#define  SUB_VGIP_VGIP_CHN2_STATUS_get_ch2_l_flag_pol(data)                      ((0x00000400&(data))>>10)
#define  SUB_VGIP_VGIP_CHN2_STATUS_get_ch2_vs_tog(data)                          ((0x00000200&(data))>>9)
#define  SUB_VGIP_VGIP_CHN2_STATUS_get_ch2_hs_tog(data)                          ((0x00000100&(data))>>8)
#define  SUB_VGIP_VGIP_CHN2_STATUS_get_ch2_field_pol(data)                       ((0x00000080&(data))>>7)
#define  SUB_VGIP_VGIP_CHN2_STATUS_get_ch2_field_tog(data)                       ((0x00000040&(data))>>6)
#define  SUB_VGIP_VGIP_CHN2_STATUS_get_ch2_field_vs_lsb(data)                    ((0x00000030&(data))>>4)
#define  SUB_VGIP_VGIP_CHN2_STATUS_get_ch2_more_1line_field(data)                ((0x00000008&(data))>>3)
#define  SUB_VGIP_VGIP_CHN2_STATUS_get_ch2_bounce_status_2(data)                 ((0x00000004&(data))>>2)
#define  SUB_VGIP_VGIP_CHN2_STATUS_get_ch2_bounce_status_1(data)                 ((0x00000002&(data))>>1)
#define  SUB_VGIP_VGIP_CHN2_STATUS_get_ch2_bounce_status_0(data)                 (0x00000001&(data))

#define  SUB_VGIP_VGIP_CHN2_DOUBLE_BUFFER_CTRL                                   0x180227E4
#define  SUB_VGIP_VGIP_CHN2_DOUBLE_BUFFER_CTRL_reg_addr                          "0xB80227E4"
#define  SUB_VGIP_VGIP_CHN2_DOUBLE_BUFFER_CTRL_reg                               0xB80227E4
#define  SUB_VGIP_VGIP_CHN2_DOUBLE_BUFFER_CTRL_inst_addr                         "0x0006"
#define  set_SUB_VGIP_VGIP_CHN2_DOUBLE_BUFFER_CTRL_reg(data)                     (*((volatile unsigned int*)SUB_VGIP_VGIP_CHN2_DOUBLE_BUFFER_CTRL_reg)=data)
#define  get_SUB_VGIP_VGIP_CHN2_DOUBLE_BUFFER_CTRL_reg                           (*((volatile unsigned int*)SUB_VGIP_VGIP_CHN2_DOUBLE_BUFFER_CTRL_reg))
#define  SUB_VGIP_VGIP_CHN2_DOUBLE_BUFFER_CTRL_ch2_db_rdy_shift                  (31)
#define  SUB_VGIP_VGIP_CHN2_DOUBLE_BUFFER_CTRL_ch2_db_en_shift                   (30)
#define  SUB_VGIP_VGIP_CHN2_DOUBLE_BUFFER_CTRL_ch2_db_read_sel_shift             (15)
#define  SUB_VGIP_VGIP_CHN2_DOUBLE_BUFFER_CTRL_ch2_db_rdy_mask                   (0x80000000)
#define  SUB_VGIP_VGIP_CHN2_DOUBLE_BUFFER_CTRL_ch2_db_en_mask                    (0x40000000)
#define  SUB_VGIP_VGIP_CHN2_DOUBLE_BUFFER_CTRL_ch2_db_read_sel_mask              (0x00008000)
#define  SUB_VGIP_VGIP_CHN2_DOUBLE_BUFFER_CTRL_ch2_db_rdy(data)                  (0x80000000&((data)<<31))
#define  SUB_VGIP_VGIP_CHN2_DOUBLE_BUFFER_CTRL_ch2_db_en(data)                   (0x40000000&((data)<<30))
#define  SUB_VGIP_VGIP_CHN2_DOUBLE_BUFFER_CTRL_ch2_db_read_sel(data)             (0x00008000&((data)<<15))
#define  SUB_VGIP_VGIP_CHN2_DOUBLE_BUFFER_CTRL_get_ch2_db_rdy(data)              ((0x80000000&(data))>>31)
#define  SUB_VGIP_VGIP_CHN2_DOUBLE_BUFFER_CTRL_get_ch2_db_en(data)               ((0x40000000&(data))>>30)
#define  SUB_VGIP_VGIP_CHN2_DOUBLE_BUFFER_CTRL_get_ch2_db_read_sel(data)         ((0x00008000&(data))>>15)

#define  SUB_VGIP_VGIP_CHN2_ACT_HSTA_Width                                       0x18022718
#define  SUB_VGIP_VGIP_CHN2_ACT_HSTA_Width_reg_addr                              "0xB8022718"
#define  SUB_VGIP_VGIP_CHN2_ACT_HSTA_Width_reg                                   0xB8022718
#define  SUB_VGIP_VGIP_CHN2_ACT_HSTA_Width_inst_addr                             "0x0007"
#define  set_SUB_VGIP_VGIP_CHN2_ACT_HSTA_Width_reg(data)                         (*((volatile unsigned int*)SUB_VGIP_VGIP_CHN2_ACT_HSTA_Width_reg)=data)
#define  get_SUB_VGIP_VGIP_CHN2_ACT_HSTA_Width_reg                               (*((volatile unsigned int*)SUB_VGIP_VGIP_CHN2_ACT_HSTA_Width_reg))
#define  SUB_VGIP_VGIP_CHN2_ACT_HSTA_Width_ch2_ih_act_sta_shift                  (16)
#define  SUB_VGIP_VGIP_CHN2_ACT_HSTA_Width_ch2_bypass_den_shift                  (14)
#define  SUB_VGIP_VGIP_CHN2_ACT_HSTA_Width_ch2_ih_act_wid_shift                  (0)
#define  SUB_VGIP_VGIP_CHN2_ACT_HSTA_Width_ch2_ih_act_sta_mask                   (0x3FFF0000)
#define  SUB_VGIP_VGIP_CHN2_ACT_HSTA_Width_ch2_bypass_den_mask                   (0x00004000)
#define  SUB_VGIP_VGIP_CHN2_ACT_HSTA_Width_ch2_ih_act_wid_mask                   (0x00003FFF)
#define  SUB_VGIP_VGIP_CHN2_ACT_HSTA_Width_ch2_ih_act_sta(data)                  (0x3FFF0000&((data)<<16))
#define  SUB_VGIP_VGIP_CHN2_ACT_HSTA_Width_ch2_bypass_den(data)                  (0x00004000&((data)<<14))
#define  SUB_VGIP_VGIP_CHN2_ACT_HSTA_Width_ch2_ih_act_wid(data)                  (0x00003FFF&(data))
#define  SUB_VGIP_VGIP_CHN2_ACT_HSTA_Width_get_ch2_ih_act_sta(data)              ((0x3FFF0000&(data))>>16)
#define  SUB_VGIP_VGIP_CHN2_ACT_HSTA_Width_get_ch2_bypass_den(data)              ((0x00004000&(data))>>14)
#define  SUB_VGIP_VGIP_CHN2_ACT_HSTA_Width_get_ch2_ih_act_wid(data)              (0x00003FFF&(data))

#define  SUB_VGIP_VGIP_CHN2_ACT_VSTA_Length                                      0x1802271C
#define  SUB_VGIP_VGIP_CHN2_ACT_VSTA_Length_reg_addr                             "0xB802271C"
#define  SUB_VGIP_VGIP_CHN2_ACT_VSTA_Length_reg                                  0xB802271C
#define  SUB_VGIP_VGIP_CHN2_ACT_VSTA_Length_inst_addr                            "0x0008"
#define  set_SUB_VGIP_VGIP_CHN2_ACT_VSTA_Length_reg(data)                        (*((volatile unsigned int*)SUB_VGIP_VGIP_CHN2_ACT_VSTA_Length_reg)=data)
#define  get_SUB_VGIP_VGIP_CHN2_ACT_VSTA_Length_reg                              (*((volatile unsigned int*)SUB_VGIP_VGIP_CHN2_ACT_VSTA_Length_reg))
#define  SUB_VGIP_VGIP_CHN2_ACT_VSTA_Length_ch2_iv_act_sta_shift                 (16)
#define  SUB_VGIP_VGIP_CHN2_ACT_VSTA_Length_ch2_iv_act_len_shift                 (0)
#define  SUB_VGIP_VGIP_CHN2_ACT_VSTA_Length_ch2_iv_act_sta_mask                  (0x1FFF0000)
#define  SUB_VGIP_VGIP_CHN2_ACT_VSTA_Length_ch2_iv_act_len_mask                  (0x00001FFF)
#define  SUB_VGIP_VGIP_CHN2_ACT_VSTA_Length_ch2_iv_act_sta(data)                 (0x1FFF0000&((data)<<16))
#define  SUB_VGIP_VGIP_CHN2_ACT_VSTA_Length_ch2_iv_act_len(data)                 (0x00001FFF&(data))
#define  SUB_VGIP_VGIP_CHN2_ACT_VSTA_Length_get_ch2_iv_act_sta(data)             ((0x1FFF0000&(data))>>16)
#define  SUB_VGIP_VGIP_CHN2_ACT_VSTA_Length_get_ch2_iv_act_len(data)             (0x00001FFF&(data))

#define  SUB_VGIP_VGIP_CHN2_DELAY                                                0x18022720
#define  SUB_VGIP_VGIP_CHN2_DELAY_reg_addr                                       "0xB8022720"
#define  SUB_VGIP_VGIP_CHN2_DELAY_reg                                            0xB8022720
#define  SUB_VGIP_VGIP_CHN2_DELAY_inst_addr                                      "0x0009"
#define  set_SUB_VGIP_VGIP_CHN2_DELAY_reg(data)                                  (*((volatile unsigned int*)SUB_VGIP_VGIP_CHN2_DELAY_reg)=data)
#define  get_SUB_VGIP_VGIP_CHN2_DELAY_reg                                        (*((volatile unsigned int*)SUB_VGIP_VGIP_CHN2_DELAY_reg))
#define  SUB_VGIP_VGIP_CHN2_DELAY_ch2_hs_width_shift                             (30)
#define  SUB_VGIP_VGIP_CHN2_DELAY_ch2_ihs_dly_shift                              (16)
#define  SUB_VGIP_VGIP_CHN2_DELAY_ch2_ivs_dly_shift                              (0)
#define  SUB_VGIP_VGIP_CHN2_DELAY_ch2_hs_width_mask                              (0xC0000000)
#define  SUB_VGIP_VGIP_CHN2_DELAY_ch2_ihs_dly_mask                               (0x3FFF0000)
#define  SUB_VGIP_VGIP_CHN2_DELAY_ch2_ivs_dly_mask                               (0x00001FFF)
#define  SUB_VGIP_VGIP_CHN2_DELAY_ch2_hs_width(data)                             (0xC0000000&((data)<<30))
#define  SUB_VGIP_VGIP_CHN2_DELAY_ch2_ihs_dly(data)                              (0x3FFF0000&((data)<<16))
#define  SUB_VGIP_VGIP_CHN2_DELAY_ch2_ivs_dly(data)                              (0x00001FFF&(data))
#define  SUB_VGIP_VGIP_CHN2_DELAY_get_ch2_hs_width(data)                         ((0xC0000000&(data))>>30)
#define  SUB_VGIP_VGIP_CHN2_DELAY_get_ch2_ihs_dly(data)                          ((0x3FFF0000&(data))>>16)
#define  SUB_VGIP_VGIP_CHN2_DELAY_get_ch2_ivs_dly(data)                          (0x00001FFF&(data))

#define  SUB_VGIP_VGIP_CHN2_MISC                                                 0x18022724
#define  SUB_VGIP_VGIP_CHN2_MISC_reg_addr                                        "0xB8022724"
#define  SUB_VGIP_VGIP_CHN2_MISC_reg                                             0xB8022724
#define  SUB_VGIP_VGIP_CHN2_MISC_inst_addr                                       "0x000A"
#define  set_SUB_VGIP_VGIP_CHN2_MISC_reg(data)                                   (*((volatile unsigned int*)SUB_VGIP_VGIP_CHN2_MISC_reg)=data)
#define  get_SUB_VGIP_VGIP_CHN2_MISC_reg                                         (*((volatile unsigned int*)SUB_VGIP_VGIP_CHN2_MISC_reg))
#define  SUB_VGIP_VGIP_CHN2_MISC_ch2_de_mask_en_shift                            (31)
#define  SUB_VGIP_VGIP_CHN2_MISC_ch2_vs_dly_1hs_shift                            (28)
#define  SUB_VGIP_VGIP_CHN2_MISC_ch2_hporch_num_sel_shift                        (24)
#define  SUB_VGIP_VGIP_CHN2_MISC_ch2_l_flag_force_tog_shift                      (21)
#define  SUB_VGIP_VGIP_CHN2_MISC_ch2_hporch_num_shift                            (8)
#define  SUB_VGIP_VGIP_CHN2_MISC_ch2_auto_ihs_dly_shift                          (6)
#define  SUB_VGIP_VGIP_CHN2_MISC_ch2_auto_ivs_dly_shift                          (4)
#define  SUB_VGIP_VGIP_CHN2_MISC_ch2_hdly_one_shift                              (3)
#define  SUB_VGIP_VGIP_CHN2_MISC_ch2_v1_v2_swap_shift                            (2)
#define  SUB_VGIP_VGIP_CHN2_MISC_ch2_v2_v3_swap_shift                            (1)
#define  SUB_VGIP_VGIP_CHN2_MISC_ch2_v1_v3_swap_shift                            (0)
#define  SUB_VGIP_VGIP_CHN2_MISC_ch2_de_mask_en_mask                             (0x80000000)
#define  SUB_VGIP_VGIP_CHN2_MISC_ch2_vs_dly_1hs_mask                             (0x10000000)
#define  SUB_VGIP_VGIP_CHN2_MISC_ch2_hporch_num_sel_mask                         (0x01000000)
#define  SUB_VGIP_VGIP_CHN2_MISC_ch2_l_flag_force_tog_mask                       (0x00200000)
#define  SUB_VGIP_VGIP_CHN2_MISC_ch2_hporch_num_mask                             (0x001FFF00)
#define  SUB_VGIP_VGIP_CHN2_MISC_ch2_auto_ihs_dly_mask                           (0x000000C0)
#define  SUB_VGIP_VGIP_CHN2_MISC_ch2_auto_ivs_dly_mask                           (0x00000030)
#define  SUB_VGIP_VGIP_CHN2_MISC_ch2_hdly_one_mask                               (0x00000008)
#define  SUB_VGIP_VGIP_CHN2_MISC_ch2_v1_v2_swap_mask                             (0x00000004)
#define  SUB_VGIP_VGIP_CHN2_MISC_ch2_v2_v3_swap_mask                             (0x00000002)
#define  SUB_VGIP_VGIP_CHN2_MISC_ch2_v1_v3_swap_mask                             (0x00000001)
#define  SUB_VGIP_VGIP_CHN2_MISC_ch2_de_mask_en(data)                            (0x80000000&((data)<<31))
#define  SUB_VGIP_VGIP_CHN2_MISC_ch2_vs_dly_1hs(data)                            (0x10000000&((data)<<28))
#define  SUB_VGIP_VGIP_CHN2_MISC_ch2_hporch_num_sel(data)                        (0x01000000&((data)<<24))
#define  SUB_VGIP_VGIP_CHN2_MISC_ch2_l_flag_force_tog(data)                      (0x00200000&((data)<<21))
#define  SUB_VGIP_VGIP_CHN2_MISC_ch2_hporch_num(data)                            (0x001FFF00&((data)<<8))
#define  SUB_VGIP_VGIP_CHN2_MISC_ch2_auto_ihs_dly(data)                          (0x000000C0&((data)<<6))
#define  SUB_VGIP_VGIP_CHN2_MISC_ch2_auto_ivs_dly(data)                          (0x00000030&((data)<<4))
#define  SUB_VGIP_VGIP_CHN2_MISC_ch2_hdly_one(data)                              (0x00000008&((data)<<3))
#define  SUB_VGIP_VGIP_CHN2_MISC_ch2_v1_v2_swap(data)                            (0x00000004&((data)<<2))
#define  SUB_VGIP_VGIP_CHN2_MISC_ch2_v2_v3_swap(data)                            (0x00000002&((data)<<1))
#define  SUB_VGIP_VGIP_CHN2_MISC_ch2_v1_v3_swap(data)                            (0x00000001&(data))
#define  SUB_VGIP_VGIP_CHN2_MISC_get_ch2_de_mask_en(data)                        ((0x80000000&(data))>>31)
#define  SUB_VGIP_VGIP_CHN2_MISC_get_ch2_vs_dly_1hs(data)                        ((0x10000000&(data))>>28)
#define  SUB_VGIP_VGIP_CHN2_MISC_get_ch2_hporch_num_sel(data)                    ((0x01000000&(data))>>24)
#define  SUB_VGIP_VGIP_CHN2_MISC_get_ch2_l_flag_force_tog(data)                  ((0x00200000&(data))>>21)
#define  SUB_VGIP_VGIP_CHN2_MISC_get_ch2_hporch_num(data)                        ((0x001FFF00&(data))>>8)
#define  SUB_VGIP_VGIP_CHN2_MISC_get_ch2_auto_ihs_dly(data)                      ((0x000000C0&(data))>>6)
#define  SUB_VGIP_VGIP_CHN2_MISC_get_ch2_auto_ivs_dly(data)                      ((0x00000030&(data))>>4)
#define  SUB_VGIP_VGIP_CHN2_MISC_get_ch2_hdly_one(data)                          ((0x00000008&(data))>>3)
#define  SUB_VGIP_VGIP_CHN2_MISC_get_ch2_v1_v2_swap(data)                        ((0x00000004&(data))>>2)
#define  SUB_VGIP_VGIP_CHN2_MISC_get_ch2_v2_v3_swap(data)                        ((0x00000002&(data))>>1)
#define  SUB_VGIP_VGIP_CHN2_MISC_get_ch2_v1_v3_swap(data)                        (0x00000001&(data))

#define  SUB_VGIP_VGIP_CHN2_PTN_H_VI                                             0x18022728
#define  SUB_VGIP_VGIP_CHN2_PTN_H_VI_reg_addr                                    "0xB8022728"
#define  SUB_VGIP_VGIP_CHN2_PTN_H_VI_reg                                         0xB8022728
#define  SUB_VGIP_VGIP_CHN2_PTN_H_VI_inst_addr                                   "0x000B"
#define  set_SUB_VGIP_VGIP_CHN2_PTN_H_VI_reg(data)                               (*((volatile unsigned int*)SUB_VGIP_VGIP_CHN2_PTN_H_VI_reg)=data)
#define  get_SUB_VGIP_VGIP_CHN2_PTN_H_VI_reg                                     (*((volatile unsigned int*)SUB_VGIP_VGIP_CHN2_PTN_H_VI_reg))
#define  SUB_VGIP_VGIP_CHN2_PTN_H_VI_ch2_captst_en_shift                         (31)
#define  SUB_VGIP_VGIP_CHN2_PTN_H_VI_ch2_captst_mode_shift                       (29)
#define  SUB_VGIP_VGIP_CHN2_PTN_H_VI_ch2_vcaptst_num_shift                       (16)
#define  SUB_VGIP_VGIP_CHN2_PTN_H_VI_ch2_captst_field_sel_shift                  (15)
#define  SUB_VGIP_VGIP_CHN2_PTN_H_VI_ch2_hcaptst_num_shift                       (0)
#define  SUB_VGIP_VGIP_CHN2_PTN_H_VI_ch2_captst_en_mask                          (0x80000000)
#define  SUB_VGIP_VGIP_CHN2_PTN_H_VI_ch2_captst_mode_mask                        (0x60000000)
#define  SUB_VGIP_VGIP_CHN2_PTN_H_VI_ch2_vcaptst_num_mask                        (0x1FFF0000)
#define  SUB_VGIP_VGIP_CHN2_PTN_H_VI_ch2_captst_field_sel_mask                   (0x00008000)
#define  SUB_VGIP_VGIP_CHN2_PTN_H_VI_ch2_hcaptst_num_mask                        (0x00003FFF)
#define  SUB_VGIP_VGIP_CHN2_PTN_H_VI_ch2_captst_en(data)                         (0x80000000&((data)<<31))
#define  SUB_VGIP_VGIP_CHN2_PTN_H_VI_ch2_captst_mode(data)                       (0x60000000&((data)<<29))
#define  SUB_VGIP_VGIP_CHN2_PTN_H_VI_ch2_vcaptst_num(data)                       (0x1FFF0000&((data)<<16))
#define  SUB_VGIP_VGIP_CHN2_PTN_H_VI_ch2_captst_field_sel(data)                  (0x00008000&((data)<<15))
#define  SUB_VGIP_VGIP_CHN2_PTN_H_VI_ch2_hcaptst_num(data)                       (0x00003FFF&(data))
#define  SUB_VGIP_VGIP_CHN2_PTN_H_VI_get_ch2_captst_en(data)                     ((0x80000000&(data))>>31)
#define  SUB_VGIP_VGIP_CHN2_PTN_H_VI_get_ch2_captst_mode(data)                   ((0x60000000&(data))>>29)
#define  SUB_VGIP_VGIP_CHN2_PTN_H_VI_get_ch2_vcaptst_num(data)                   ((0x1FFF0000&(data))>>16)
#define  SUB_VGIP_VGIP_CHN2_PTN_H_VI_get_ch2_captst_field_sel(data)              ((0x00008000&(data))>>15)
#define  SUB_VGIP_VGIP_CHN2_PTN_H_VI_get_ch2_hcaptst_num(data)                   (0x00003FFF&(data))

#define  SUB_VGIP_VGIP_CHN2_PTN0                                                 0x1802272C
#define  SUB_VGIP_VGIP_CHN2_PTN0_reg_addr                                        "0xB802272C"
#define  SUB_VGIP_VGIP_CHN2_PTN0_reg                                             0xB802272C
#define  SUB_VGIP_VGIP_CHN2_PTN0_inst_addr                                       "0x000C"
#define  set_SUB_VGIP_VGIP_CHN2_PTN0_reg(data)                                   (*((volatile unsigned int*)SUB_VGIP_VGIP_CHN2_PTN0_reg)=data)
#define  get_SUB_VGIP_VGIP_CHN2_PTN0_reg                                         (*((volatile unsigned int*)SUB_VGIP_VGIP_CHN2_PTN0_reg))
#define  SUB_VGIP_VGIP_CHN2_PTN0_ch2_captst_r_data_shift                         (16)
#define  SUB_VGIP_VGIP_CHN2_PTN0_ch2_captst_g_data_shift                         (0)
#define  SUB_VGIP_VGIP_CHN2_PTN0_ch2_captst_r_data_mask                          (0x0FFF0000)
#define  SUB_VGIP_VGIP_CHN2_PTN0_ch2_captst_g_data_mask                          (0x00000FFF)
#define  SUB_VGIP_VGIP_CHN2_PTN0_ch2_captst_r_data(data)                         (0x0FFF0000&((data)<<16))
#define  SUB_VGIP_VGIP_CHN2_PTN0_ch2_captst_g_data(data)                         (0x00000FFF&(data))
#define  SUB_VGIP_VGIP_CHN2_PTN0_get_ch2_captst_r_data(data)                     ((0x0FFF0000&(data))>>16)
#define  SUB_VGIP_VGIP_CHN2_PTN0_get_ch2_captst_g_data(data)                     (0x00000FFF&(data))

#define  SUB_VGIP_VGIP_CHN2_PTN1                                                 0x18022730
#define  SUB_VGIP_VGIP_CHN2_PTN1_reg_addr                                        "0xB8022730"
#define  SUB_VGIP_VGIP_CHN2_PTN1_reg                                             0xB8022730
#define  SUB_VGIP_VGIP_CHN2_PTN1_inst_addr                                       "0x000D"
#define  set_SUB_VGIP_VGIP_CHN2_PTN1_reg(data)                                   (*((volatile unsigned int*)SUB_VGIP_VGIP_CHN2_PTN1_reg)=data)
#define  get_SUB_VGIP_VGIP_CHN2_PTN1_reg                                         (*((volatile unsigned int*)SUB_VGIP_VGIP_CHN2_PTN1_reg))
#define  SUB_VGIP_VGIP_CHN2_PTN1_ch2_hporch_num_sel_shift                        (16)
#define  SUB_VGIP_VGIP_CHN2_PTN1_ch2_captst_b_data_shift                         (0)
#define  SUB_VGIP_VGIP_CHN2_PTN1_ch2_hporch_num_sel_mask                         (0x3FFF0000)
#define  SUB_VGIP_VGIP_CHN2_PTN1_ch2_captst_b_data_mask                          (0x00000FFF)
#define  SUB_VGIP_VGIP_CHN2_PTN1_ch2_hporch_num_sel(data)                        (0x3FFF0000&((data)<<16))
#define  SUB_VGIP_VGIP_CHN2_PTN1_ch2_captst_b_data(data)                         (0x00000FFF&(data))
#define  SUB_VGIP_VGIP_CHN2_PTN1_get_ch2_hporch_num_sel(data)                    ((0x3FFF0000&(data))>>16)
#define  SUB_VGIP_VGIP_CHN2_PTN1_get_ch2_captst_b_data(data)                     (0x00000FFF&(data))

#define  SUB_VGIP_VGIP_CHN2_LC                                                   0x18022734
#define  SUB_VGIP_VGIP_CHN2_LC_reg_addr                                          "0xB8022734"
#define  SUB_VGIP_VGIP_CHN2_LC_reg                                               0xB8022734
#define  SUB_VGIP_VGIP_CHN2_LC_inst_addr                                         "0x000E"
#define  set_SUB_VGIP_VGIP_CHN2_LC_reg(data)                                     (*((volatile unsigned int*)SUB_VGIP_VGIP_CHN2_LC_reg)=data)
#define  get_SUB_VGIP_VGIP_CHN2_LC_reg                                           (*((volatile unsigned int*)SUB_VGIP_VGIP_CHN2_LC_reg))
#define  SUB_VGIP_VGIP_CHN2_LC_ch2_vlcen_shift                                   (31)
#define  SUB_VGIP_VGIP_CHN2_LC_ch2_vlc_mode_shift                                (30)
#define  SUB_VGIP_VGIP_CHN2_LC_ch2_vlc_ie_shift                                  (29)
#define  SUB_VGIP_VGIP_CHN2_LC_ch2_den_crc_sel_shift                             (28)
#define  SUB_VGIP_VGIP_CHN2_LC_ch2_line_cnt_shift                                (12)
#define  SUB_VGIP_VGIP_CHN2_LC_ch2_vln_shift                                     (0)
#define  SUB_VGIP_VGIP_CHN2_LC_ch2_vlcen_mask                                    (0x80000000)
#define  SUB_VGIP_VGIP_CHN2_LC_ch2_vlc_mode_mask                                 (0x40000000)
#define  SUB_VGIP_VGIP_CHN2_LC_ch2_vlc_ie_mask                                   (0x20000000)
#define  SUB_VGIP_VGIP_CHN2_LC_ch2_den_crc_sel_mask                              (0x10000000)
#define  SUB_VGIP_VGIP_CHN2_LC_ch2_line_cnt_mask                                 (0x00FFF000)
#define  SUB_VGIP_VGIP_CHN2_LC_ch2_vln_mask                                      (0x00000FFF)
#define  SUB_VGIP_VGIP_CHN2_LC_ch2_vlcen(data)                                   (0x80000000&((data)<<31))
#define  SUB_VGIP_VGIP_CHN2_LC_ch2_vlc_mode(data)                                (0x40000000&((data)<<30))
#define  SUB_VGIP_VGIP_CHN2_LC_ch2_vlc_ie(data)                                  (0x20000000&((data)<<29))
#define  SUB_VGIP_VGIP_CHN2_LC_ch2_den_crc_sel(data)                             (0x10000000&((data)<<28))
#define  SUB_VGIP_VGIP_CHN2_LC_ch2_line_cnt(data)                                (0x00FFF000&((data)<<12))
#define  SUB_VGIP_VGIP_CHN2_LC_ch2_vln(data)                                     (0x00000FFF&(data))
#define  SUB_VGIP_VGIP_CHN2_LC_get_ch2_vlcen(data)                               ((0x80000000&(data))>>31)
#define  SUB_VGIP_VGIP_CHN2_LC_get_ch2_vlc_mode(data)                            ((0x40000000&(data))>>30)
#define  SUB_VGIP_VGIP_CHN2_LC_get_ch2_vlc_ie(data)                              ((0x20000000&(data))>>29)
#define  SUB_VGIP_VGIP_CHN2_LC_get_ch2_den_crc_sel(data)                         ((0x10000000&(data))>>28)
#define  SUB_VGIP_VGIP_CHN2_LC_get_ch2_line_cnt(data)                            ((0x00FFF000&(data))>>12)
#define  SUB_VGIP_VGIP_CHN2_LC_get_ch2_vln(data)                                 (0x00000FFF&(data))

#define  SUB_VGIP_ICH2_VGIP_CRC_CTRL                                             0x18022738
#define  SUB_VGIP_ICH2_VGIP_CRC_CTRL_reg_addr                                    "0xB8022738"
#define  SUB_VGIP_ICH2_VGIP_CRC_CTRL_reg                                         0xB8022738
#define  SUB_VGIP_ICH2_VGIP_CRC_CTRL_inst_addr                                   "0x000F"
#define  set_SUB_VGIP_ICH2_VGIP_CRC_CTRL_reg(data)                               (*((volatile unsigned int*)SUB_VGIP_ICH2_VGIP_CRC_CTRL_reg)=data)
#define  get_SUB_VGIP_ICH2_VGIP_CRC_CTRL_reg                                     (*((volatile unsigned int*)SUB_VGIP_ICH2_VGIP_CRC_CTRL_reg))
#define  SUB_VGIP_ICH2_VGIP_CRC_CTRL_ch2_crc_mode_shift                          (6)
#define  SUB_VGIP_ICH2_VGIP_CRC_CTRL_ch2_crc_region_shift                        (5)
#define  SUB_VGIP_ICH2_VGIP_CRC_CTRL_ch2_crc_ctrl_in_shift                       (4)
#define  SUB_VGIP_ICH2_VGIP_CRC_CTRL_ch2_crc_field_edge_sel_shift                (3)
#define  SUB_VGIP_ICH2_VGIP_CRC_CTRL_ch2_crc_field_shift                         (2)
#define  SUB_VGIP_ICH2_VGIP_CRC_CTRL_ch2_crc_conti_shift                         (1)
#define  SUB_VGIP_ICH2_VGIP_CRC_CTRL_ch2_crc_start_shift                         (0)
#define  SUB_VGIP_ICH2_VGIP_CRC_CTRL_ch2_crc_mode_mask                           (0x000000C0)
#define  SUB_VGIP_ICH2_VGIP_CRC_CTRL_ch2_crc_region_mask                         (0x00000020)
#define  SUB_VGIP_ICH2_VGIP_CRC_CTRL_ch2_crc_ctrl_in_mask                        (0x00000010)
#define  SUB_VGIP_ICH2_VGIP_CRC_CTRL_ch2_crc_field_edge_sel_mask                 (0x00000008)
#define  SUB_VGIP_ICH2_VGIP_CRC_CTRL_ch2_crc_field_mask                          (0x00000004)
#define  SUB_VGIP_ICH2_VGIP_CRC_CTRL_ch2_crc_conti_mask                          (0x00000002)
#define  SUB_VGIP_ICH2_VGIP_CRC_CTRL_ch2_crc_start_mask                          (0x00000001)
#define  SUB_VGIP_ICH2_VGIP_CRC_CTRL_ch2_crc_mode(data)                          (0x000000C0&((data)<<6))
#define  SUB_VGIP_ICH2_VGIP_CRC_CTRL_ch2_crc_region(data)                        (0x00000020&((data)<<5))
#define  SUB_VGIP_ICH2_VGIP_CRC_CTRL_ch2_crc_ctrl_in(data)                       (0x00000010&((data)<<4))
#define  SUB_VGIP_ICH2_VGIP_CRC_CTRL_ch2_crc_field_edge_sel(data)                (0x00000008&((data)<<3))
#define  SUB_VGIP_ICH2_VGIP_CRC_CTRL_ch2_crc_field(data)                         (0x00000004&((data)<<2))
#define  SUB_VGIP_ICH2_VGIP_CRC_CTRL_ch2_crc_conti(data)                         (0x00000002&((data)<<1))
#define  SUB_VGIP_ICH2_VGIP_CRC_CTRL_ch2_crc_start(data)                         (0x00000001&(data))
#define  SUB_VGIP_ICH2_VGIP_CRC_CTRL_get_ch2_crc_mode(data)                      ((0x000000C0&(data))>>6)
#define  SUB_VGIP_ICH2_VGIP_CRC_CTRL_get_ch2_crc_region(data)                    ((0x00000020&(data))>>5)
#define  SUB_VGIP_ICH2_VGIP_CRC_CTRL_get_ch2_crc_ctrl_in(data)                   ((0x00000010&(data))>>4)
#define  SUB_VGIP_ICH2_VGIP_CRC_CTRL_get_ch2_crc_field_edge_sel(data)            ((0x00000008&(data))>>3)
#define  SUB_VGIP_ICH2_VGIP_CRC_CTRL_get_ch2_crc_field(data)                     ((0x00000004&(data))>>2)
#define  SUB_VGIP_ICH2_VGIP_CRC_CTRL_get_ch2_crc_conti(data)                     ((0x00000002&(data))>>1)
#define  SUB_VGIP_ICH2_VGIP_CRC_CTRL_get_ch2_crc_start(data)                     (0x00000001&(data))

#define  SUB_VGIP_ICH2_VGIP_CRC_Result                                           0x1802273C
#define  SUB_VGIP_ICH2_VGIP_CRC_Result_reg_addr                                  "0xB802273C"
#define  SUB_VGIP_ICH2_VGIP_CRC_Result_reg                                       0xB802273C
#define  SUB_VGIP_ICH2_VGIP_CRC_Result_inst_addr                                 "0x0010"
#define  set_SUB_VGIP_ICH2_VGIP_CRC_Result_reg(data)                             (*((volatile unsigned int*)SUB_VGIP_ICH2_VGIP_CRC_Result_reg)=data)
#define  get_SUB_VGIP_ICH2_VGIP_CRC_Result_reg                                   (*((volatile unsigned int*)SUB_VGIP_ICH2_VGIP_CRC_Result_reg))
#define  SUB_VGIP_ICH2_VGIP_CRC_Result_ch2_crc_result_shift                      (0)
#define  SUB_VGIP_ICH2_VGIP_CRC_Result_ch2_crc_result_mask                       (0xFFFFFFFF)
#define  SUB_VGIP_ICH2_VGIP_CRC_Result_ch2_crc_result(data)                      (0xFFFFFFFF&(data))
#define  SUB_VGIP_ICH2_VGIP_CRC_Result_get_ch2_crc_result(data)                  (0xFFFFFFFF&(data))

#define  SUB_VGIP_VGIP_CHN2_WDE                                                  0x18022740
#define  SUB_VGIP_VGIP_CHN2_WDE_reg_addr                                         "0xB8022740"
#define  SUB_VGIP_VGIP_CHN2_WDE_reg                                              0xB8022740
#define  SUB_VGIP_VGIP_CHN2_WDE_inst_addr                                        "0x0011"
#define  set_SUB_VGIP_VGIP_CHN2_WDE_reg(data)                                    (*((volatile unsigned int*)SUB_VGIP_VGIP_CHN2_WDE_reg)=data)
#define  get_SUB_VGIP_VGIP_CHN2_WDE_reg                                          (*((volatile unsigned int*)SUB_VGIP_VGIP_CHN2_WDE_reg))
#define  SUB_VGIP_VGIP_CHN2_WDE_ch2_wd_to_main_shift                             (31)
#define  SUB_VGIP_VGIP_CHN2_WDE_dummy_30_19_shift                                (19)
#define  SUB_VGIP_VGIP_CHN2_WDE_ch2_vs_err_wde_shift                             (18)
#define  SUB_VGIP_VGIP_CHN2_WDE_ch2_hs_err_wde_shift                             (17)
#define  SUB_VGIP_VGIP_CHN2_WDE_ch2_field_err_wde_shift                          (16)
#define  SUB_VGIP_VGIP_CHN2_WDE_ch2_rl_err_wde_shift                             (15)
#define  SUB_VGIP_VGIP_CHN2_WDE_dummy_14_4_shift                                 (4)
#define  SUB_VGIP_VGIP_CHN2_WDE_ch2_rl_err_ie_shift                              (3)
#define  SUB_VGIP_VGIP_CHN2_WDE_ch2_vs_err_ie_shift                              (2)
#define  SUB_VGIP_VGIP_CHN2_WDE_ch2_hs_err_ie_shift                              (1)
#define  SUB_VGIP_VGIP_CHN2_WDE_ch2_field_err_ie_shift                           (0)
#define  SUB_VGIP_VGIP_CHN2_WDE_ch2_wd_to_main_mask                              (0x80000000)
#define  SUB_VGIP_VGIP_CHN2_WDE_dummy_30_19_mask                                 (0x7FF80000)
#define  SUB_VGIP_VGIP_CHN2_WDE_ch2_vs_err_wde_mask                              (0x00040000)
#define  SUB_VGIP_VGIP_CHN2_WDE_ch2_hs_err_wde_mask                              (0x00020000)
#define  SUB_VGIP_VGIP_CHN2_WDE_ch2_field_err_wde_mask                           (0x00010000)
#define  SUB_VGIP_VGIP_CHN2_WDE_ch2_rl_err_wde_mask                              (0x00008000)
#define  SUB_VGIP_VGIP_CHN2_WDE_dummy_14_4_mask                                  (0x00007FF0)
#define  SUB_VGIP_VGIP_CHN2_WDE_ch2_rl_err_ie_mask                               (0x00000008)
#define  SUB_VGIP_VGIP_CHN2_WDE_ch2_vs_err_ie_mask                               (0x00000004)
#define  SUB_VGIP_VGIP_CHN2_WDE_ch2_hs_err_ie_mask                               (0x00000002)
#define  SUB_VGIP_VGIP_CHN2_WDE_ch2_field_err_ie_mask                            (0x00000001)
#define  SUB_VGIP_VGIP_CHN2_WDE_ch2_wd_to_main(data)                             (0x80000000&((data)<<31))
#define  SUB_VGIP_VGIP_CHN2_WDE_dummy_30_19(data)                                (0x7FF80000&((data)<<19))
#define  SUB_VGIP_VGIP_CHN2_WDE_ch2_vs_err_wde(data)                             (0x00040000&((data)<<18))
#define  SUB_VGIP_VGIP_CHN2_WDE_ch2_hs_err_wde(data)                             (0x00020000&((data)<<17))
#define  SUB_VGIP_VGIP_CHN2_WDE_ch2_field_err_wde(data)                          (0x00010000&((data)<<16))
#define  SUB_VGIP_VGIP_CHN2_WDE_ch2_rl_err_wde(data)                             (0x00008000&((data)<<15))
#define  SUB_VGIP_VGIP_CHN2_WDE_dummy_14_4(data)                                 (0x00007FF0&((data)<<4))
#define  SUB_VGIP_VGIP_CHN2_WDE_ch2_rl_err_ie(data)                              (0x00000008&((data)<<3))
#define  SUB_VGIP_VGIP_CHN2_WDE_ch2_vs_err_ie(data)                              (0x00000004&((data)<<2))
#define  SUB_VGIP_VGIP_CHN2_WDE_ch2_hs_err_ie(data)                              (0x00000002&((data)<<1))
#define  SUB_VGIP_VGIP_CHN2_WDE_ch2_field_err_ie(data)                           (0x00000001&(data))
#define  SUB_VGIP_VGIP_CHN2_WDE_get_ch2_wd_to_main(data)                         ((0x80000000&(data))>>31)
#define  SUB_VGIP_VGIP_CHN2_WDE_get_dummy_30_19(data)                            ((0x7FF80000&(data))>>19)
#define  SUB_VGIP_VGIP_CHN2_WDE_get_ch2_vs_err_wde(data)                         ((0x00040000&(data))>>18)
#define  SUB_VGIP_VGIP_CHN2_WDE_get_ch2_hs_err_wde(data)                         ((0x00020000&(data))>>17)
#define  SUB_VGIP_VGIP_CHN2_WDE_get_ch2_field_err_wde(data)                      ((0x00010000&(data))>>16)
#define  SUB_VGIP_VGIP_CHN2_WDE_get_ch2_rl_err_wde(data)                         ((0x00008000&(data))>>15)
#define  SUB_VGIP_VGIP_CHN2_WDE_get_dummy_14_4(data)                             ((0x00007FF0&(data))>>4)
#define  SUB_VGIP_VGIP_CHN2_WDE_get_ch2_rl_err_ie(data)                          ((0x00000008&(data))>>3)
#define  SUB_VGIP_VGIP_CHN2_WDE_get_ch2_vs_err_ie(data)                          ((0x00000004&(data))>>2)
#define  SUB_VGIP_VGIP_CHN2_WDE_get_ch2_hs_err_ie(data)                          ((0x00000002&(data))>>1)
#define  SUB_VGIP_VGIP_CHN2_WDE_get_ch2_field_err_ie(data)                       (0x00000001&(data))

#define  SUB_VGIP_VGIP_CHN2_PTN2                                                 0x18022760
#define  SUB_VGIP_VGIP_CHN2_PTN2_reg_addr                                        "0xB8022760"
#define  SUB_VGIP_VGIP_CHN2_PTN2_reg                                             0xB8022760
#define  SUB_VGIP_VGIP_CHN2_PTN2_inst_addr                                       "0x0012"
#define  set_SUB_VGIP_VGIP_CHN2_PTN2_reg(data)                                   (*((volatile unsigned int*)SUB_VGIP_VGIP_CHN2_PTN2_reg)=data)
#define  get_SUB_VGIP_VGIP_CHN2_PTN2_reg                                         (*((volatile unsigned int*)SUB_VGIP_VGIP_CHN2_PTN2_reg))
#define  SUB_VGIP_VGIP_CHN2_PTN2_ch2_captst_r_data_2_shift                       (16)
#define  SUB_VGIP_VGIP_CHN2_PTN2_ch2_captst_g_data_2_shift                       (0)
#define  SUB_VGIP_VGIP_CHN2_PTN2_ch2_captst_r_data_2_mask                        (0x0FFF0000)
#define  SUB_VGIP_VGIP_CHN2_PTN2_ch2_captst_g_data_2_mask                        (0x00000FFF)
#define  SUB_VGIP_VGIP_CHN2_PTN2_ch2_captst_r_data_2(data)                       (0x0FFF0000&((data)<<16))
#define  SUB_VGIP_VGIP_CHN2_PTN2_ch2_captst_g_data_2(data)                       (0x00000FFF&(data))
#define  SUB_VGIP_VGIP_CHN2_PTN2_get_ch2_captst_r_data_2(data)                   ((0x0FFF0000&(data))>>16)
#define  SUB_VGIP_VGIP_CHN2_PTN2_get_ch2_captst_g_data_2(data)                   (0x00000FFF&(data))

#define  SUB_VGIP_VGIP_CHN2_PTN3                                                 0x18022764
#define  SUB_VGIP_VGIP_CHN2_PTN3_reg_addr                                        "0xB8022764"
#define  SUB_VGIP_VGIP_CHN2_PTN3_reg                                             0xB8022764
#define  SUB_VGIP_VGIP_CHN2_PTN3_inst_addr                                       "0x0013"
#define  set_SUB_VGIP_VGIP_CHN2_PTN3_reg(data)                                   (*((volatile unsigned int*)SUB_VGIP_VGIP_CHN2_PTN3_reg)=data)
#define  get_SUB_VGIP_VGIP_CHN2_PTN3_reg                                         (*((volatile unsigned int*)SUB_VGIP_VGIP_CHN2_PTN3_reg))
#define  SUB_VGIP_VGIP_CHN2_PTN3_ch2_captst_b_data_3_shift                       (16)
#define  SUB_VGIP_VGIP_CHN2_PTN3_ch2_captst_b_data_2_shift                       (0)
#define  SUB_VGIP_VGIP_CHN2_PTN3_ch2_captst_b_data_3_mask                        (0x0FFF0000)
#define  SUB_VGIP_VGIP_CHN2_PTN3_ch2_captst_b_data_2_mask                        (0x00000FFF)
#define  SUB_VGIP_VGIP_CHN2_PTN3_ch2_captst_b_data_3(data)                       (0x0FFF0000&((data)<<16))
#define  SUB_VGIP_VGIP_CHN2_PTN3_ch2_captst_b_data_2(data)                       (0x00000FFF&(data))
#define  SUB_VGIP_VGIP_CHN2_PTN3_get_ch2_captst_b_data_3(data)                   ((0x0FFF0000&(data))>>16)
#define  SUB_VGIP_VGIP_CHN2_PTN3_get_ch2_captst_b_data_2(data)                   (0x00000FFF&(data))

#define  SUB_VGIP_VGIP_CHN2_PTN4                                                 0x18022768
#define  SUB_VGIP_VGIP_CHN2_PTN4_reg_addr                                        "0xB8022768"
#define  SUB_VGIP_VGIP_CHN2_PTN4_reg                                             0xB8022768
#define  SUB_VGIP_VGIP_CHN2_PTN4_inst_addr                                       "0x0014"
#define  set_SUB_VGIP_VGIP_CHN2_PTN4_reg(data)                                   (*((volatile unsigned int*)SUB_VGIP_VGIP_CHN2_PTN4_reg)=data)
#define  get_SUB_VGIP_VGIP_CHN2_PTN4_reg                                         (*((volatile unsigned int*)SUB_VGIP_VGIP_CHN2_PTN4_reg))
#define  SUB_VGIP_VGIP_CHN2_PTN4_ch2_captst_r_data_3_shift                       (16)
#define  SUB_VGIP_VGIP_CHN2_PTN4_ch2_captst_g_data_3_shift                       (0)
#define  SUB_VGIP_VGIP_CHN2_PTN4_ch2_captst_r_data_3_mask                        (0x0FFF0000)
#define  SUB_VGIP_VGIP_CHN2_PTN4_ch2_captst_g_data_3_mask                        (0x00000FFF)
#define  SUB_VGIP_VGIP_CHN2_PTN4_ch2_captst_r_data_3(data)                       (0x0FFF0000&((data)<<16))
#define  SUB_VGIP_VGIP_CHN2_PTN4_ch2_captst_g_data_3(data)                       (0x00000FFF&(data))
#define  SUB_VGIP_VGIP_CHN2_PTN4_get_ch2_captst_r_data_3(data)                   ((0x0FFF0000&(data))>>16)
#define  SUB_VGIP_VGIP_CHN2_PTN4_get_ch2_captst_g_data_3(data)                   (0x00000FFF&(data))

#define  SUB_VGIP_VGIP_CHN2_PTN5                                                 0x1802276C
#define  SUB_VGIP_VGIP_CHN2_PTN5_reg_addr                                        "0xB802276C"
#define  SUB_VGIP_VGIP_CHN2_PTN5_reg                                             0xB802276C
#define  SUB_VGIP_VGIP_CHN2_PTN5_inst_addr                                       "0x0015"
#define  set_SUB_VGIP_VGIP_CHN2_PTN5_reg(data)                                   (*((volatile unsigned int*)SUB_VGIP_VGIP_CHN2_PTN5_reg)=data)
#define  get_SUB_VGIP_VGIP_CHN2_PTN5_reg                                         (*((volatile unsigned int*)SUB_VGIP_VGIP_CHN2_PTN5_reg))
#define  SUB_VGIP_VGIP_CHN2_PTN5_ch2_captst_r_data_4_shift                       (16)
#define  SUB_VGIP_VGIP_CHN2_PTN5_ch2_captst_g_data_4_shift                       (0)
#define  SUB_VGIP_VGIP_CHN2_PTN5_ch2_captst_r_data_4_mask                        (0x0FFF0000)
#define  SUB_VGIP_VGIP_CHN2_PTN5_ch2_captst_g_data_4_mask                        (0x00000FFF)
#define  SUB_VGIP_VGIP_CHN2_PTN5_ch2_captst_r_data_4(data)                       (0x0FFF0000&((data)<<16))
#define  SUB_VGIP_VGIP_CHN2_PTN5_ch2_captst_g_data_4(data)                       (0x00000FFF&(data))
#define  SUB_VGIP_VGIP_CHN2_PTN5_get_ch2_captst_r_data_4(data)                   ((0x0FFF0000&(data))>>16)
#define  SUB_VGIP_VGIP_CHN2_PTN5_get_ch2_captst_g_data_4(data)                   (0x00000FFF&(data))

#define  SUB_VGIP_VGIP_CHN2_PTN6                                                 0x18022770
#define  SUB_VGIP_VGIP_CHN2_PTN6_reg_addr                                        "0xB8022770"
#define  SUB_VGIP_VGIP_CHN2_PTN6_reg                                             0xB8022770
#define  SUB_VGIP_VGIP_CHN2_PTN6_inst_addr                                       "0x0016"
#define  set_SUB_VGIP_VGIP_CHN2_PTN6_reg(data)                                   (*((volatile unsigned int*)SUB_VGIP_VGIP_CHN2_PTN6_reg)=data)
#define  get_SUB_VGIP_VGIP_CHN2_PTN6_reg                                         (*((volatile unsigned int*)SUB_VGIP_VGIP_CHN2_PTN6_reg))
#define  SUB_VGIP_VGIP_CHN2_PTN6_ch2_captst_b_data_4_shift                       (0)
#define  SUB_VGIP_VGIP_CHN2_PTN6_ch2_captst_b_data_4_mask                        (0x00000FFF)
#define  SUB_VGIP_VGIP_CHN2_PTN6_ch2_captst_b_data_4(data)                       (0x00000FFF&(data))
#define  SUB_VGIP_VGIP_CHN2_PTN6_get_ch2_captst_b_data_4(data)                   (0x00000FFF&(data))

#define  SUB_VGIP_SUB_ADC_raw_data_DMA                                           0x18022778
#define  SUB_VGIP_SUB_ADC_raw_data_DMA_reg_addr                                  "0xB8022778"
#define  SUB_VGIP_SUB_ADC_raw_data_DMA_reg                                       0xB8022778
#define  SUB_VGIP_SUB_ADC_raw_data_DMA_inst_addr                                 "0x0017"
#define  set_SUB_VGIP_SUB_ADC_raw_data_DMA_reg(data)                             (*((volatile unsigned int*)SUB_VGIP_SUB_ADC_raw_data_DMA_reg)=data)
#define  get_SUB_VGIP_SUB_ADC_raw_data_DMA_reg                                   (*((volatile unsigned int*)SUB_VGIP_SUB_ADC_raw_data_DMA_reg))
#define  SUB_VGIP_SUB_ADC_raw_data_DMA_ch2_adc_test_dma_count_shift              (4)
#define  SUB_VGIP_SUB_ADC_raw_data_DMA_ch2_force_den_shift                       (2)
#define  SUB_VGIP_SUB_ADC_raw_data_DMA_ch2_force_vsync_shift                     (1)
#define  SUB_VGIP_SUB_ADC_raw_data_DMA_ch2_adc_test_dma_mode_shift               (0)
#define  SUB_VGIP_SUB_ADC_raw_data_DMA_ch2_adc_test_dma_count_mask               (0xFFFFFFF0)
#define  SUB_VGIP_SUB_ADC_raw_data_DMA_ch2_force_den_mask                        (0x00000004)
#define  SUB_VGIP_SUB_ADC_raw_data_DMA_ch2_force_vsync_mask                      (0x00000002)
#define  SUB_VGIP_SUB_ADC_raw_data_DMA_ch2_adc_test_dma_mode_mask                (0x00000001)
#define  SUB_VGIP_SUB_ADC_raw_data_DMA_ch2_adc_test_dma_count(data)              (0xFFFFFFF0&((data)<<4))
#define  SUB_VGIP_SUB_ADC_raw_data_DMA_ch2_force_den(data)                       (0x00000004&((data)<<2))
#define  SUB_VGIP_SUB_ADC_raw_data_DMA_ch2_force_vsync(data)                     (0x00000002&((data)<<1))
#define  SUB_VGIP_SUB_ADC_raw_data_DMA_ch2_adc_test_dma_mode(data)               (0x00000001&(data))
#define  SUB_VGIP_SUB_ADC_raw_data_DMA_get_ch2_adc_test_dma_count(data)          ((0xFFFFFFF0&(data))>>4)
#define  SUB_VGIP_SUB_ADC_raw_data_DMA_get_ch2_force_den(data)                   ((0x00000004&(data))>>2)
#define  SUB_VGIP_SUB_ADC_raw_data_DMA_get_ch2_force_vsync(data)                 ((0x00000002&(data))>>1)
#define  SUB_VGIP_SUB_ADC_raw_data_DMA_get_ch2_adc_test_dma_mode(data)           (0x00000001&(data))

#define  SUB_VGIP_S_VGIP_DITHERING_CTRL                                          0x1802277C
#define  SUB_VGIP_S_VGIP_DITHERING_CTRL_reg_addr                                 "0xB802277C"
#define  SUB_VGIP_S_VGIP_DITHERING_CTRL_reg                                      0xB802277C
#define  SUB_VGIP_S_VGIP_DITHERING_CTRL_inst_addr                                "0x0018"
#define  set_SUB_VGIP_S_VGIP_DITHERING_CTRL_reg(data)                            (*((volatile unsigned int*)SUB_VGIP_S_VGIP_DITHERING_CTRL_reg)=data)
#define  get_SUB_VGIP_S_VGIP_DITHERING_CTRL_reg                                  (*((volatile unsigned int*)SUB_VGIP_S_VGIP_DITHERING_CTRL_reg))
#define  SUB_VGIP_S_VGIP_DITHERING_CTRL_function_enable_shift                    (0)
#define  SUB_VGIP_S_VGIP_DITHERING_CTRL_function_enable_mask                     (0x00000001)
#define  SUB_VGIP_S_VGIP_DITHERING_CTRL_function_enable(data)                    (0x00000001&(data))
#define  SUB_VGIP_S_VGIP_DITHERING_CTRL_get_function_enable(data)                (0x00000001&(data))

#define  SUB_VGIP_S_VGIP_DITHERING_Dither_TABLE_Red_00                           0x18022780
#define  SUB_VGIP_S_VGIP_DITHERING_Dither_TABLE_Red_00_reg_addr                  "0xB8022780"
#define  SUB_VGIP_S_VGIP_DITHERING_Dither_TABLE_Red_00_reg                       0xB8022780
#define  SUB_VGIP_S_VGIP_DITHERING_Dither_TABLE_Red_00_inst_addr                 "0x0019"
#define  set_SUB_VGIP_S_VGIP_DITHERING_Dither_TABLE_Red_00_reg(data)             (*((volatile unsigned int*)SUB_VGIP_S_VGIP_DITHERING_Dither_TABLE_Red_00_reg)=data)
#define  get_SUB_VGIP_S_VGIP_DITHERING_Dither_TABLE_Red_00_reg                   (*((volatile unsigned int*)SUB_VGIP_S_VGIP_DITHERING_Dither_TABLE_Red_00_reg))
#define  SUB_VGIP_S_VGIP_DITHERING_Dither_TABLE_Red_00_tab_r_03_shift            (18)
#define  SUB_VGIP_S_VGIP_DITHERING_Dither_TABLE_Red_00_tab_r_02_shift            (12)
#define  SUB_VGIP_S_VGIP_DITHERING_Dither_TABLE_Red_00_tab_r_01_shift            (6)
#define  SUB_VGIP_S_VGIP_DITHERING_Dither_TABLE_Red_00_tab_r_00_shift            (0)
#define  SUB_VGIP_S_VGIP_DITHERING_Dither_TABLE_Red_00_tab_r_03_mask             (0x00FC0000)
#define  SUB_VGIP_S_VGIP_DITHERING_Dither_TABLE_Red_00_tab_r_02_mask             (0x0003F000)
#define  SUB_VGIP_S_VGIP_DITHERING_Dither_TABLE_Red_00_tab_r_01_mask             (0x00000FC0)
#define  SUB_VGIP_S_VGIP_DITHERING_Dither_TABLE_Red_00_tab_r_00_mask             (0x0000003F)
#define  SUB_VGIP_S_VGIP_DITHERING_Dither_TABLE_Red_00_tab_r_03(data)            (0x00FC0000&((data)<<18))
#define  SUB_VGIP_S_VGIP_DITHERING_Dither_TABLE_Red_00_tab_r_02(data)            (0x0003F000&((data)<<12))
#define  SUB_VGIP_S_VGIP_DITHERING_Dither_TABLE_Red_00_tab_r_01(data)            (0x00000FC0&((data)<<6))
#define  SUB_VGIP_S_VGIP_DITHERING_Dither_TABLE_Red_00_tab_r_00(data)            (0x0000003F&(data))
#define  SUB_VGIP_S_VGIP_DITHERING_Dither_TABLE_Red_00_get_tab_r_03(data)        ((0x00FC0000&(data))>>18)
#define  SUB_VGIP_S_VGIP_DITHERING_Dither_TABLE_Red_00_get_tab_r_02(data)        ((0x0003F000&(data))>>12)
#define  SUB_VGIP_S_VGIP_DITHERING_Dither_TABLE_Red_00_get_tab_r_01(data)        ((0x00000FC0&(data))>>6)
#define  SUB_VGIP_S_VGIP_DITHERING_Dither_TABLE_Red_00_get_tab_r_00(data)        (0x0000003F&(data))

#define  SUB_VGIP_S_VGIP_DITHERING_Dither_TABLE_Green_00                         0x18022784
#define  SUB_VGIP_S_VGIP_DITHERING_Dither_TABLE_Green_00_reg_addr                "0xB8022784"
#define  SUB_VGIP_S_VGIP_DITHERING_Dither_TABLE_Green_00_reg                     0xB8022784
#define  SUB_VGIP_S_VGIP_DITHERING_Dither_TABLE_Green_00_inst_addr               "0x001A"
#define  set_SUB_VGIP_S_VGIP_DITHERING_Dither_TABLE_Green_00_reg(data)           (*((volatile unsigned int*)SUB_VGIP_S_VGIP_DITHERING_Dither_TABLE_Green_00_reg)=data)
#define  get_SUB_VGIP_S_VGIP_DITHERING_Dither_TABLE_Green_00_reg                 (*((volatile unsigned int*)SUB_VGIP_S_VGIP_DITHERING_Dither_TABLE_Green_00_reg))
#define  SUB_VGIP_S_VGIP_DITHERING_Dither_TABLE_Green_00_tab_g_03_shift          (18)
#define  SUB_VGIP_S_VGIP_DITHERING_Dither_TABLE_Green_00_tab_g_02_shift          (12)
#define  SUB_VGIP_S_VGIP_DITHERING_Dither_TABLE_Green_00_tab_g_01_shift          (6)
#define  SUB_VGIP_S_VGIP_DITHERING_Dither_TABLE_Green_00_tab_g_00_shift          (0)
#define  SUB_VGIP_S_VGIP_DITHERING_Dither_TABLE_Green_00_tab_g_03_mask           (0x00FC0000)
#define  SUB_VGIP_S_VGIP_DITHERING_Dither_TABLE_Green_00_tab_g_02_mask           (0x0003F000)
#define  SUB_VGIP_S_VGIP_DITHERING_Dither_TABLE_Green_00_tab_g_01_mask           (0x00000FC0)
#define  SUB_VGIP_S_VGIP_DITHERING_Dither_TABLE_Green_00_tab_g_00_mask           (0x0000003F)
#define  SUB_VGIP_S_VGIP_DITHERING_Dither_TABLE_Green_00_tab_g_03(data)          (0x00FC0000&((data)<<18))
#define  SUB_VGIP_S_VGIP_DITHERING_Dither_TABLE_Green_00_tab_g_02(data)          (0x0003F000&((data)<<12))
#define  SUB_VGIP_S_VGIP_DITHERING_Dither_TABLE_Green_00_tab_g_01(data)          (0x00000FC0&((data)<<6))
#define  SUB_VGIP_S_VGIP_DITHERING_Dither_TABLE_Green_00_tab_g_00(data)          (0x0000003F&(data))
#define  SUB_VGIP_S_VGIP_DITHERING_Dither_TABLE_Green_00_get_tab_g_03(data)      ((0x00FC0000&(data))>>18)
#define  SUB_VGIP_S_VGIP_DITHERING_Dither_TABLE_Green_00_get_tab_g_02(data)      ((0x0003F000&(data))>>12)
#define  SUB_VGIP_S_VGIP_DITHERING_Dither_TABLE_Green_00_get_tab_g_01(data)      ((0x00000FC0&(data))>>6)
#define  SUB_VGIP_S_VGIP_DITHERING_Dither_TABLE_Green_00_get_tab_g_00(data)      (0x0000003F&(data))

#define  SUB_VGIP_S_VGIP_DITHERING_Dither_TABLE_Blue_00                          0x18022788
#define  SUB_VGIP_S_VGIP_DITHERING_Dither_TABLE_Blue_00_reg_addr                 "0xB8022788"
#define  SUB_VGIP_S_VGIP_DITHERING_Dither_TABLE_Blue_00_reg                      0xB8022788
#define  SUB_VGIP_S_VGIP_DITHERING_Dither_TABLE_Blue_00_inst_addr                "0x001B"
#define  set_SUB_VGIP_S_VGIP_DITHERING_Dither_TABLE_Blue_00_reg(data)            (*((volatile unsigned int*)SUB_VGIP_S_VGIP_DITHERING_Dither_TABLE_Blue_00_reg)=data)
#define  get_SUB_VGIP_S_VGIP_DITHERING_Dither_TABLE_Blue_00_reg                  (*((volatile unsigned int*)SUB_VGIP_S_VGIP_DITHERING_Dither_TABLE_Blue_00_reg))
#define  SUB_VGIP_S_VGIP_DITHERING_Dither_TABLE_Blue_00_tab_b_03_shift           (18)
#define  SUB_VGIP_S_VGIP_DITHERING_Dither_TABLE_Blue_00_tab_b_02_shift           (12)
#define  SUB_VGIP_S_VGIP_DITHERING_Dither_TABLE_Blue_00_tab_b_01_shift           (6)
#define  SUB_VGIP_S_VGIP_DITHERING_Dither_TABLE_Blue_00_tab_b_00_shift           (0)
#define  SUB_VGIP_S_VGIP_DITHERING_Dither_TABLE_Blue_00_tab_b_03_mask            (0x00FC0000)
#define  SUB_VGIP_S_VGIP_DITHERING_Dither_TABLE_Blue_00_tab_b_02_mask            (0x0003F000)
#define  SUB_VGIP_S_VGIP_DITHERING_Dither_TABLE_Blue_00_tab_b_01_mask            (0x00000FC0)
#define  SUB_VGIP_S_VGIP_DITHERING_Dither_TABLE_Blue_00_tab_b_00_mask            (0x0000003F)
#define  SUB_VGIP_S_VGIP_DITHERING_Dither_TABLE_Blue_00_tab_b_03(data)           (0x00FC0000&((data)<<18))
#define  SUB_VGIP_S_VGIP_DITHERING_Dither_TABLE_Blue_00_tab_b_02(data)           (0x0003F000&((data)<<12))
#define  SUB_VGIP_S_VGIP_DITHERING_Dither_TABLE_Blue_00_tab_b_01(data)           (0x00000FC0&((data)<<6))
#define  SUB_VGIP_S_VGIP_DITHERING_Dither_TABLE_Blue_00_tab_b_00(data)           (0x0000003F&(data))
#define  SUB_VGIP_S_VGIP_DITHERING_Dither_TABLE_Blue_00_get_tab_b_03(data)       ((0x00FC0000&(data))>>18)
#define  SUB_VGIP_S_VGIP_DITHERING_Dither_TABLE_Blue_00_get_tab_b_02(data)       ((0x0003F000&(data))>>12)
#define  SUB_VGIP_S_VGIP_DITHERING_Dither_TABLE_Blue_00_get_tab_b_01(data)       ((0x00000FC0&(data))>>6)
#define  SUB_VGIP_S_VGIP_DITHERING_Dither_TABLE_Blue_00_get_tab_b_00(data)       (0x0000003F&(data))

#define  SUB_VGIP_SUB_VGIP_444to422_CTRL                                         0x1802278C
#define  SUB_VGIP_SUB_VGIP_444to422_CTRL_reg_addr                                "0xB802278C"
#define  SUB_VGIP_SUB_VGIP_444to422_CTRL_reg                                     0xB802278C
#define  SUB_VGIP_SUB_VGIP_444to422_CTRL_inst_addr                               "0x001C"
#define  set_SUB_VGIP_SUB_VGIP_444to422_CTRL_reg(data)                           (*((volatile unsigned int*)SUB_VGIP_SUB_VGIP_444to422_CTRL_reg)=data)
#define  get_SUB_VGIP_SUB_VGIP_444to422_CTRL_reg                                 (*((volatile unsigned int*)SUB_VGIP_SUB_VGIP_444to422_CTRL_reg))
#define  SUB_VGIP_SUB_VGIP_444to422_CTRL_cr_dly_cb_shift                         (2)
#define  SUB_VGIP_SUB_VGIP_444to422_CTRL_drop_shift                              (1)
#define  SUB_VGIP_SUB_VGIP_444to422_CTRL_sort_fmt_shift                          (0)
#define  SUB_VGIP_SUB_VGIP_444to422_CTRL_cr_dly_cb_mask                          (0x00000004)
#define  SUB_VGIP_SUB_VGIP_444to422_CTRL_drop_mask                               (0x00000002)
#define  SUB_VGIP_SUB_VGIP_444to422_CTRL_sort_fmt_mask                           (0x00000001)
#define  SUB_VGIP_SUB_VGIP_444to422_CTRL_cr_dly_cb(data)                         (0x00000004&((data)<<2))
#define  SUB_VGIP_SUB_VGIP_444to422_CTRL_drop(data)                              (0x00000002&((data)<<1))
#define  SUB_VGIP_SUB_VGIP_444to422_CTRL_sort_fmt(data)                          (0x00000001&(data))
#define  SUB_VGIP_SUB_VGIP_444to422_CTRL_get_cr_dly_cb(data)                     ((0x00000004&(data))>>2)
#define  SUB_VGIP_SUB_VGIP_444to422_CTRL_get_drop(data)                          ((0x00000002&(data))>>1)
#define  SUB_VGIP_SUB_VGIP_444to422_CTRL_get_sort_fmt(data)                      (0x00000001&(data))

#define  SUB_VGIP_SUB_CTS_FIFO_CTL                                               0x18022790
#define  SUB_VGIP_SUB_CTS_FIFO_CTL_reg_addr                                      "0xB8022790"
#define  SUB_VGIP_SUB_CTS_FIFO_CTL_reg                                           0xB8022790
#define  SUB_VGIP_SUB_CTS_FIFO_CTL_inst_addr                                     "0x001D"
#define  set_SUB_VGIP_SUB_CTS_FIFO_CTL_reg(data)                                 (*((volatile unsigned int*)SUB_VGIP_SUB_CTS_FIFO_CTL_reg)=data)
#define  get_SUB_VGIP_SUB_CTS_FIFO_CTL_reg                                       (*((volatile unsigned int*)SUB_VGIP_SUB_CTS_FIFO_CTL_reg))
#define  SUB_VGIP_SUB_CTS_FIFO_CTL_ch2_dummy_ctsfifo_vgip_shift                  (3)
#define  SUB_VGIP_SUB_CTS_FIFO_CTL_ch2_force_ctsfifo_rstn_vgip_shift             (2)
#define  SUB_VGIP_SUB_CTS_FIFO_CTL_ch2_en_ctsfifo_vsrst_vgip_shift               (1)
#define  SUB_VGIP_SUB_CTS_FIFO_CTL_ch2_en_ctsfifo_bypass_vgip_shift              (0)
#define  SUB_VGIP_SUB_CTS_FIFO_CTL_ch2_dummy_ctsfifo_vgip_mask                   (0x00000008)
#define  SUB_VGIP_SUB_CTS_FIFO_CTL_ch2_force_ctsfifo_rstn_vgip_mask              (0x00000004)
#define  SUB_VGIP_SUB_CTS_FIFO_CTL_ch2_en_ctsfifo_vsrst_vgip_mask                (0x00000002)
#define  SUB_VGIP_SUB_CTS_FIFO_CTL_ch2_en_ctsfifo_bypass_vgip_mask               (0x00000001)
#define  SUB_VGIP_SUB_CTS_FIFO_CTL_ch2_dummy_ctsfifo_vgip(data)                  (0x00000008&((data)<<3))
#define  SUB_VGIP_SUB_CTS_FIFO_CTL_ch2_force_ctsfifo_rstn_vgip(data)             (0x00000004&((data)<<2))
#define  SUB_VGIP_SUB_CTS_FIFO_CTL_ch2_en_ctsfifo_vsrst_vgip(data)               (0x00000002&((data)<<1))
#define  SUB_VGIP_SUB_CTS_FIFO_CTL_ch2_en_ctsfifo_bypass_vgip(data)              (0x00000001&(data))
#define  SUB_VGIP_SUB_CTS_FIFO_CTL_get_ch2_dummy_ctsfifo_vgip(data)              ((0x00000008&(data))>>3)
#define  SUB_VGIP_SUB_CTS_FIFO_CTL_get_ch2_force_ctsfifo_rstn_vgip(data)         ((0x00000004&(data))>>2)
#define  SUB_VGIP_SUB_CTS_FIFO_CTL_get_ch2_en_ctsfifo_vsrst_vgip(data)           ((0x00000002&(data))>>1)
#define  SUB_VGIP_SUB_CTS_FIFO_CTL_get_ch2_en_ctsfifo_bypass_vgip(data)          (0x00000001&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======SUB_VGIP register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  ch2_v8_dummy:8;
    };
}sub_vgip_sub_vclk_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dummy18022704_7_0:8;
    };
}sub_vgip_sub_v8_1_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  ch2_select_duplicate_lsb:1;
    };
}sub_vgip_sub_v8_2_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_auto_l_flag_delay_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  ch2_vs_rise_sample_delay_sel:1;
        RBus_UInt32  ch2_auto_l_flag_delay_num:13;
        RBus_UInt32  ch2_l_flag_delay_en:1;
        RBus_UInt32  ch2_l_flag_field_sample_delay:2;
        RBus_UInt32  ch2_l_flag_delay_num:13;
    };
}sub_vgip_sub_vgip_global_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_ivrun:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  ch2_in_sel:1;
        RBus_UInt32  ch2_random_en:1;
        RBus_UInt32  ch2_fdrop_en:1;
        RBus_UInt32  ch2_vact_end_ie:1;
        RBus_UInt32  ch2_vact_start_ie:1;
        RBus_UInt32  ch2_field_hs_inv:1;
        RBus_UInt32  ch2_field_vd_inv:1;
        RBus_UInt32  ch2_field_vd_en:1;
        RBus_UInt32  ch2_3dleft_inv:1;
        RBus_UInt32  ch2_3dleft_sync_edge:1;
        RBus_UInt32  ch2_field_inv:1;
        RBus_UInt32  ch2_field_sync_edge:1;
        RBus_UInt32  ch2_field_det_en:1;
        RBus_UInt32  ch2_hpact_is_hact:1;
        RBus_UInt32  ch2_fcap_str_odd:1;
        RBus_UInt32  ch2_mask_den_inv:1;
        RBus_UInt32  ch2_mask_den_1l:1;
        RBus_UInt32  ch2_3d_mode_en:1;
        RBus_UInt32  ch2_safe_field_inv:1;
        RBus_UInt32  ch2_force_tog:1;
        RBus_UInt32  ch2_safe_mode:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  ch2_hs_syncedge:1;
        RBus_UInt32  ch2_vs_syncedge:1;
        RBus_UInt32  ch2_vs_by_hs_en_n:1;
        RBus_UInt32  ch2_vs_inv:1;
        RBus_UInt32  ch2_hs_inv:1;
        RBus_UInt32  ch2_digital_mode:1;
        RBus_UInt32  ch2_in_clk_en:1;
    };
}sub_vgip_vgip_chn2_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  ch2_vs_end:1;
        RBus_UInt32  ch2_vs_start:1;
        RBus_UInt32  ch2_vact_end:1;
        RBus_UInt32  ch2_vact_start:1;
        RBus_UInt32  dummy18022714_23_17:7;
        RBus_UInt32  ch2_vlc_status:1;
        RBus_UInt32  ch2_rl_err:1;
        RBus_UInt32  ch2_vs_err:1;
        RBus_UInt32  ch2_hs_err:1;
        RBus_UInt32  ch2_field_err:1;
        RBus_UInt32  ch2_rl_tog:1;
        RBus_UInt32  ch2_l_flag_pol:1;
        RBus_UInt32  ch2_vs_tog:1;
        RBus_UInt32  ch2_hs_tog:1;
        RBus_UInt32  ch2_field_pol:1;
        RBus_UInt32  ch2_field_tog:1;
        RBus_UInt32  ch2_field_vs_lsb:2;
        RBus_UInt32  ch2_more_1line_field:1;
        RBus_UInt32  ch2_bounce_status_2:1;
        RBus_UInt32  ch2_bounce_status_1:1;
        RBus_UInt32  ch2_bounce_status_0:1;
    };
}sub_vgip_vgip_chn2_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_db_rdy:1;
        RBus_UInt32  ch2_db_en:1;
        RBus_UInt32  res1:14;
        RBus_UInt32  ch2_db_read_sel:1;
        RBus_UInt32  res2:15;
    };
}sub_vgip_vgip_chn2_double_buffer_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ch2_ih_act_sta:14;
        RBus_UInt32  res2:1;
        RBus_UInt32  ch2_bypass_den:1;
        RBus_UInt32  ch2_ih_act_wid:14;
    };
}sub_vgip_vgip_chn2_act_hsta_width_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  ch2_iv_act_sta:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  ch2_iv_act_len:13;
    };
}sub_vgip_vgip_chn2_act_vsta_length_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_hs_width:2;
        RBus_UInt32  ch2_ihs_dly:14;
        RBus_UInt32  res1:3;
        RBus_UInt32  ch2_ivs_dly:13;
    };
}sub_vgip_vgip_chn2_delay_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_de_mask_en:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  ch2_vs_dly_1hs:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  ch2_hporch_num_sel:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  ch2_l_flag_force_tog:1;
        RBus_UInt32  ch2_hporch_num:13;
        RBus_UInt32  ch2_auto_ihs_dly:2;
        RBus_UInt32  ch2_auto_ivs_dly:2;
        RBus_UInt32  ch2_hdly_one:1;
        RBus_UInt32  ch2_v1_v2_swap:1;
        RBus_UInt32  ch2_v2_v3_swap:1;
        RBus_UInt32  ch2_v1_v3_swap:1;
    };
}sub_vgip_vgip_chn2_misc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_captst_en:1;
        RBus_UInt32  ch2_captst_mode:2;
        RBus_UInt32  ch2_vcaptst_num:13;
        RBus_UInt32  ch2_captst_field_sel:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  ch2_hcaptst_num:14;
    };
}sub_vgip_vgip_chn2_ptn_h_vi_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  ch2_captst_r_data:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  ch2_captst_g_data:12;
    };
}sub_vgip_vgip_chn2_ptn0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ch2_hporch_num_sel:14;
        RBus_UInt32  res2:4;
        RBus_UInt32  ch2_captst_b_data:12;
    };
}sub_vgip_vgip_chn2_ptn1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_vlcen:1;
        RBus_UInt32  ch2_vlc_mode:1;
        RBus_UInt32  ch2_vlc_ie:1;
        RBus_UInt32  ch2_den_crc_sel:1;
        RBus_UInt32  res1:4;
        RBus_UInt32  ch2_line_cnt:12;
        RBus_UInt32  ch2_vln:12;
    };
}sub_vgip_vgip_chn2_lc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  ch2_crc_mode:2;
        RBus_UInt32  ch2_crc_region:1;
        RBus_UInt32  ch2_crc_ctrl_in:1;
        RBus_UInt32  ch2_crc_field_edge_sel:1;
        RBus_UInt32  ch2_crc_field:1;
        RBus_UInt32  ch2_crc_conti:1;
        RBus_UInt32  ch2_crc_start:1;
    };
}sub_vgip_ich2_vgip_crc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_crc_result:32;
    };
}sub_vgip_ich2_vgip_crc_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_wd_to_main:1;
        RBus_UInt32  dummy18022740_30_19:12;
        RBus_UInt32  ch2_vs_err_wde:1;
        RBus_UInt32  ch2_hs_err_wde:1;
        RBus_UInt32  ch2_field_err_wde:1;
        RBus_UInt32  ch2_rl_err_wde:1;
        RBus_UInt32  dummy18022740_14_4:11;
        RBus_UInt32  ch2_rl_err_ie:1;
        RBus_UInt32  ch2_vs_err_ie:1;
        RBus_UInt32  ch2_hs_err_ie:1;
        RBus_UInt32  ch2_field_err_ie:1;
    };
}sub_vgip_vgip_chn2_wde_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  ch2_captst_r_data_2:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  ch2_captst_g_data_2:12;
    };
}sub_vgip_vgip_chn2_ptn2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  ch2_captst_b_data_3:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  ch2_captst_b_data_2:12;
    };
}sub_vgip_vgip_chn2_ptn3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  ch2_captst_r_data_3:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  ch2_captst_g_data_3:12;
    };
}sub_vgip_vgip_chn2_ptn4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  ch2_captst_r_data_4:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  ch2_captst_g_data_4:12;
    };
}sub_vgip_vgip_chn2_ptn5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  ch2_captst_b_data_4:12;
    };
}sub_vgip_vgip_chn2_ptn6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_adc_test_dma_count:28;
        RBus_UInt32  res1:1;
        RBus_UInt32  ch2_force_den:1;
        RBus_UInt32  ch2_force_vsync:1;
        RBus_UInt32  ch2_adc_test_dma_mode:1;
    };
}sub_vgip_sub_adc_raw_data_dma_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  function_enable:1;
    };
}sub_vgip_s_vgip_dithering_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_r_03:6;
        RBus_UInt32  tab_r_02:6;
        RBus_UInt32  tab_r_01:6;
        RBus_UInt32  tab_r_00:6;
    };
}sub_vgip_s_vgip_dithering_dither_table_red_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_g_03:6;
        RBus_UInt32  tab_g_02:6;
        RBus_UInt32  tab_g_01:6;
        RBus_UInt32  tab_g_00:6;
    };
}sub_vgip_s_vgip_dithering_dither_table_green_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_b_03:6;
        RBus_UInt32  tab_b_02:6;
        RBus_UInt32  tab_b_01:6;
        RBus_UInt32  tab_b_00:6;
    };
}sub_vgip_s_vgip_dithering_dither_table_blue_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  cr_dly_cb:1;
        RBus_UInt32  drop:1;
        RBus_UInt32  sort_fmt:1;
    };
}sub_vgip_sub_vgip_444to422_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  ch2_dummy_ctsfifo_vgip:1;
        RBus_UInt32  ch2_force_ctsfifo_rstn_vgip:1;
        RBus_UInt32  ch2_en_ctsfifo_vsrst_vgip:1;
        RBus_UInt32  ch2_en_ctsfifo_bypass_vgip:1;
    };
}sub_vgip_sub_cts_fifo_ctl_RBUS;

#else //apply LITTLE_ENDIAN

//======SUB_VGIP register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_v8_dummy:8;
        RBus_UInt32  res1:24;
    };
}sub_vgip_sub_vclk_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18022704_7_0:8;
        RBus_UInt32  res1:24;
    };
}sub_vgip_sub_v8_1_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_select_duplicate_lsb:1;
        RBus_UInt32  res1:31;
    };
}sub_vgip_sub_v8_2_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_l_flag_delay_num:13;
        RBus_UInt32  ch2_l_flag_field_sample_delay:2;
        RBus_UInt32  ch2_l_flag_delay_en:1;
        RBus_UInt32  ch2_auto_l_flag_delay_num:13;
        RBus_UInt32  ch2_vs_rise_sample_delay_sel:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  ch2_auto_l_flag_delay_en:1;
    };
}sub_vgip_sub_vgip_global_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_in_clk_en:1;
        RBus_UInt32  ch2_digital_mode:1;
        RBus_UInt32  ch2_hs_inv:1;
        RBus_UInt32  ch2_vs_inv:1;
        RBus_UInt32  ch2_vs_by_hs_en_n:1;
        RBus_UInt32  ch2_vs_syncedge:1;
        RBus_UInt32  ch2_hs_syncedge:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  ch2_safe_mode:1;
        RBus_UInt32  ch2_force_tog:1;
        RBus_UInt32  ch2_safe_field_inv:1;
        RBus_UInt32  ch2_3d_mode_en:1;
        RBus_UInt32  ch2_mask_den_1l:1;
        RBus_UInt32  ch2_mask_den_inv:1;
        RBus_UInt32  ch2_fcap_str_odd:1;
        RBus_UInt32  ch2_hpact_is_hact:1;
        RBus_UInt32  ch2_field_det_en:1;
        RBus_UInt32  ch2_field_sync_edge:1;
        RBus_UInt32  ch2_field_inv:1;
        RBus_UInt32  ch2_3dleft_sync_edge:1;
        RBus_UInt32  ch2_3dleft_inv:1;
        RBus_UInt32  ch2_field_vd_en:1;
        RBus_UInt32  ch2_field_vd_inv:1;
        RBus_UInt32  ch2_field_hs_inv:1;
        RBus_UInt32  ch2_vact_start_ie:1;
        RBus_UInt32  ch2_vact_end_ie:1;
        RBus_UInt32  ch2_fdrop_en:1;
        RBus_UInt32  ch2_random_en:1;
        RBus_UInt32  ch2_in_sel:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  ch2_ivrun:1;
    };
}sub_vgip_vgip_chn2_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_bounce_status_0:1;
        RBus_UInt32  ch2_bounce_status_1:1;
        RBus_UInt32  ch2_bounce_status_2:1;
        RBus_UInt32  ch2_more_1line_field:1;
        RBus_UInt32  ch2_field_vs_lsb:2;
        RBus_UInt32  ch2_field_tog:1;
        RBus_UInt32  ch2_field_pol:1;
        RBus_UInt32  ch2_hs_tog:1;
        RBus_UInt32  ch2_vs_tog:1;
        RBus_UInt32  ch2_l_flag_pol:1;
        RBus_UInt32  ch2_rl_tog:1;
        RBus_UInt32  ch2_field_err:1;
        RBus_UInt32  ch2_hs_err:1;
        RBus_UInt32  ch2_vs_err:1;
        RBus_UInt32  ch2_rl_err:1;
        RBus_UInt32  ch2_vlc_status:1;
        RBus_UInt32  dummy18022714_23_17:7;
        RBus_UInt32  ch2_vact_start:1;
        RBus_UInt32  ch2_vact_end:1;
        RBus_UInt32  ch2_vs_start:1;
        RBus_UInt32  ch2_vs_end:1;
        RBus_UInt32  res1:4;
    };
}sub_vgip_vgip_chn2_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  ch2_db_read_sel:1;
        RBus_UInt32  res2:14;
        RBus_UInt32  ch2_db_en:1;
        RBus_UInt32  ch2_db_rdy:1;
    };
}sub_vgip_vgip_chn2_double_buffer_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_ih_act_wid:14;
        RBus_UInt32  ch2_bypass_den:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  ch2_ih_act_sta:14;
        RBus_UInt32  res2:2;
    };
}sub_vgip_vgip_chn2_act_hsta_width_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_iv_act_len:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  ch2_iv_act_sta:13;
        RBus_UInt32  res2:3;
    };
}sub_vgip_vgip_chn2_act_vsta_length_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_ivs_dly:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  ch2_ihs_dly:14;
        RBus_UInt32  ch2_hs_width:2;
    };
}sub_vgip_vgip_chn2_delay_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_v1_v3_swap:1;
        RBus_UInt32  ch2_v2_v3_swap:1;
        RBus_UInt32  ch2_v1_v2_swap:1;
        RBus_UInt32  ch2_hdly_one:1;
        RBus_UInt32  ch2_auto_ivs_dly:2;
        RBus_UInt32  ch2_auto_ihs_dly:2;
        RBus_UInt32  ch2_hporch_num:13;
        RBus_UInt32  ch2_l_flag_force_tog:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  ch2_hporch_num_sel:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  ch2_vs_dly_1hs:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  ch2_de_mask_en:1;
    };
}sub_vgip_vgip_chn2_misc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_hcaptst_num:14;
        RBus_UInt32  res1:1;
        RBus_UInt32  ch2_captst_field_sel:1;
        RBus_UInt32  ch2_vcaptst_num:13;
        RBus_UInt32  ch2_captst_mode:2;
        RBus_UInt32  ch2_captst_en:1;
    };
}sub_vgip_vgip_chn2_ptn_h_vi_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_captst_g_data:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  ch2_captst_r_data:12;
        RBus_UInt32  res2:4;
    };
}sub_vgip_vgip_chn2_ptn0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_captst_b_data:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  ch2_hporch_num_sel:14;
        RBus_UInt32  res2:2;
    };
}sub_vgip_vgip_chn2_ptn1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_vln:12;
        RBus_UInt32  ch2_line_cnt:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  ch2_den_crc_sel:1;
        RBus_UInt32  ch2_vlc_ie:1;
        RBus_UInt32  ch2_vlc_mode:1;
        RBus_UInt32  ch2_vlcen:1;
    };
}sub_vgip_vgip_chn2_lc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_crc_start:1;
        RBus_UInt32  ch2_crc_conti:1;
        RBus_UInt32  ch2_crc_field:1;
        RBus_UInt32  ch2_crc_field_edge_sel:1;
        RBus_UInt32  ch2_crc_ctrl_in:1;
        RBus_UInt32  ch2_crc_region:1;
        RBus_UInt32  ch2_crc_mode:2;
        RBus_UInt32  res1:24;
    };
}sub_vgip_ich2_vgip_crc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_crc_result:32;
    };
}sub_vgip_ich2_vgip_crc_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_field_err_ie:1;
        RBus_UInt32  ch2_hs_err_ie:1;
        RBus_UInt32  ch2_vs_err_ie:1;
        RBus_UInt32  ch2_rl_err_ie:1;
        RBus_UInt32  dummy18022740_14_4:11;
        RBus_UInt32  ch2_rl_err_wde:1;
        RBus_UInt32  ch2_field_err_wde:1;
        RBus_UInt32  ch2_hs_err_wde:1;
        RBus_UInt32  ch2_vs_err_wde:1;
        RBus_UInt32  dummy18022740_30_19:12;
        RBus_UInt32  ch2_wd_to_main:1;
    };
}sub_vgip_vgip_chn2_wde_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_captst_g_data_2:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  ch2_captst_r_data_2:12;
        RBus_UInt32  res2:4;
    };
}sub_vgip_vgip_chn2_ptn2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_captst_b_data_2:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  ch2_captst_b_data_3:12;
        RBus_UInt32  res2:4;
    };
}sub_vgip_vgip_chn2_ptn3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_captst_g_data_3:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  ch2_captst_r_data_3:12;
        RBus_UInt32  res2:4;
    };
}sub_vgip_vgip_chn2_ptn4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_captst_g_data_4:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  ch2_captst_r_data_4:12;
        RBus_UInt32  res2:4;
    };
}sub_vgip_vgip_chn2_ptn5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_captst_b_data_4:12;
        RBus_UInt32  res1:20;
    };
}sub_vgip_vgip_chn2_ptn6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_adc_test_dma_mode:1;
        RBus_UInt32  ch2_force_vsync:1;
        RBus_UInt32  ch2_force_den:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  ch2_adc_test_dma_count:28;
    };
}sub_vgip_sub_adc_raw_data_dma_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  function_enable:1;
        RBus_UInt32  res1:31;
    };
}sub_vgip_s_vgip_dithering_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_r_00:6;
        RBus_UInt32  tab_r_01:6;
        RBus_UInt32  tab_r_02:6;
        RBus_UInt32  tab_r_03:6;
        RBus_UInt32  res1:8;
    };
}sub_vgip_s_vgip_dithering_dither_table_red_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_g_00:6;
        RBus_UInt32  tab_g_01:6;
        RBus_UInt32  tab_g_02:6;
        RBus_UInt32  tab_g_03:6;
        RBus_UInt32  res1:8;
    };
}sub_vgip_s_vgip_dithering_dither_table_green_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_b_00:6;
        RBus_UInt32  tab_b_01:6;
        RBus_UInt32  tab_b_02:6;
        RBus_UInt32  tab_b_03:6;
        RBus_UInt32  res1:8;
    };
}sub_vgip_s_vgip_dithering_dither_table_blue_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sort_fmt:1;
        RBus_UInt32  drop:1;
        RBus_UInt32  cr_dly_cb:1;
        RBus_UInt32  res1:29;
    };
}sub_vgip_sub_vgip_444to422_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_en_ctsfifo_bypass_vgip:1;
        RBus_UInt32  ch2_en_ctsfifo_vsrst_vgip:1;
        RBus_UInt32  ch2_force_ctsfifo_rstn_vgip:1;
        RBus_UInt32  ch2_dummy_ctsfifo_vgip:1;
        RBus_UInt32  res1:28;
    };
}sub_vgip_sub_cts_fifo_ctl_RBUS;




#endif 


#endif 
