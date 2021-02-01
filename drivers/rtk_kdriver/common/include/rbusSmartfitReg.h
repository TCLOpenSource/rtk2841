/**
* @file rbusSmartfitReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2015-2-16
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_SMARTFIT_REG_H_
#define _RBUS_SMARTFIT_REG_H_

#include "rbusTypes.h"



//  SMARTFIT Register Address
#define  SMARTFIT_AUTO_FIELD                                                     0x18022000
#define  SMARTFIT_AUTO_FIELD_reg_addr                                            "0xB8022000"
#define  SMARTFIT_AUTO_FIELD_reg                                                 0xB8022000
#define  SMARTFIT_AUTO_FIELD_inst_addr                                           "0x0000"
#define  set_SMARTFIT_AUTO_FIELD_reg(data)                                       (*((volatile unsigned int*)SMARTFIT_AUTO_FIELD_reg)=data)
#define  get_SMARTFIT_AUTO_FIELD_reg                                             (*((volatile unsigned int*)SMARTFIT_AUTO_FIELD_reg))
#define  SMARTFIT_AUTO_FIELD_smartfit_src_sel_shift                              (31)
#define  SMARTFIT_AUTO_FIELD_auto_balance_rgb_shift                              (30)
#define  SMARTFIT_AUTO_FIELD_smfit_en_n_shift                                    (29)
#define  SMARTFIT_AUTO_FIELD_adj_source_shift                                    (10)
#define  SMARTFIT_AUTO_FIELD_rl_sel_en_shift                                     (9)
#define  SMARTFIT_AUTO_FIELD_rl_sel_shift                                        (8)
#define  SMARTFIT_AUTO_FIELD_odd_sel_en_shift                                    (7)
#define  SMARTFIT_AUTO_FIELD_odd_sel_shift                                       (6)
#define  SMARTFIT_AUTO_FIELD_rgb_in_one_en_shift                                 (4)
#define  SMARTFIT_AUTO_FIELD_square_en_shift                                     (3)
#define  SMARTFIT_AUTO_FIELD_sum_pixel_num_shift                                 (2)
#define  SMARTFIT_AUTO_FIELD_filter_sel_shift                                    (0)
#define  SMARTFIT_AUTO_FIELD_smartfit_src_sel_mask                               (0x80000000)
#define  SMARTFIT_AUTO_FIELD_auto_balance_rgb_mask                               (0x40000000)
#define  SMARTFIT_AUTO_FIELD_smfit_en_n_mask                                     (0x20000000)
#define  SMARTFIT_AUTO_FIELD_adj_source_mask                                     (0x00000C00)
#define  SMARTFIT_AUTO_FIELD_rl_sel_en_mask                                      (0x00000200)
#define  SMARTFIT_AUTO_FIELD_rl_sel_mask                                         (0x00000100)
#define  SMARTFIT_AUTO_FIELD_odd_sel_en_mask                                     (0x00000080)
#define  SMARTFIT_AUTO_FIELD_odd_sel_mask                                        (0x00000040)
#define  SMARTFIT_AUTO_FIELD_rgb_in_one_en_mask                                  (0x00000010)
#define  SMARTFIT_AUTO_FIELD_square_en_mask                                      (0x00000008)
#define  SMARTFIT_AUTO_FIELD_sum_pixel_num_mask                                  (0x00000004)
#define  SMARTFIT_AUTO_FIELD_filter_sel_mask                                     (0x00000003)
#define  SMARTFIT_AUTO_FIELD_smartfit_src_sel(data)                              (0x80000000&((data)<<31))
#define  SMARTFIT_AUTO_FIELD_auto_balance_rgb(data)                              (0x40000000&((data)<<30))
#define  SMARTFIT_AUTO_FIELD_smfit_en_n(data)                                    (0x20000000&((data)<<29))
#define  SMARTFIT_AUTO_FIELD_adj_source(data)                                    (0x00000C00&((data)<<10))
#define  SMARTFIT_AUTO_FIELD_rl_sel_en(data)                                     (0x00000200&((data)<<9))
#define  SMARTFIT_AUTO_FIELD_rl_sel(data)                                        (0x00000100&((data)<<8))
#define  SMARTFIT_AUTO_FIELD_odd_sel_en(data)                                    (0x00000080&((data)<<7))
#define  SMARTFIT_AUTO_FIELD_odd_sel(data)                                       (0x00000040&((data)<<6))
#define  SMARTFIT_AUTO_FIELD_rgb_in_one_en(data)                                 (0x00000010&((data)<<4))
#define  SMARTFIT_AUTO_FIELD_square_en(data)                                     (0x00000008&((data)<<3))
#define  SMARTFIT_AUTO_FIELD_sum_pixel_num(data)                                 (0x00000004&((data)<<2))
#define  SMARTFIT_AUTO_FIELD_filter_sel(data)                                    (0x00000003&(data))
#define  SMARTFIT_AUTO_FIELD_get_smartfit_src_sel(data)                          ((0x80000000&(data))>>31)
#define  SMARTFIT_AUTO_FIELD_get_auto_balance_rgb(data)                          ((0x40000000&(data))>>30)
#define  SMARTFIT_AUTO_FIELD_get_smfit_en_n(data)                                ((0x20000000&(data))>>29)
#define  SMARTFIT_AUTO_FIELD_get_adj_source(data)                                ((0x00000C00&(data))>>10)
#define  SMARTFIT_AUTO_FIELD_get_rl_sel_en(data)                                 ((0x00000200&(data))>>9)
#define  SMARTFIT_AUTO_FIELD_get_rl_sel(data)                                    ((0x00000100&(data))>>8)
#define  SMARTFIT_AUTO_FIELD_get_odd_sel_en(data)                                ((0x00000080&(data))>>7)
#define  SMARTFIT_AUTO_FIELD_get_odd_sel(data)                                   ((0x00000040&(data))>>6)
#define  SMARTFIT_AUTO_FIELD_get_rgb_in_one_en(data)                             ((0x00000010&(data))>>4)
#define  SMARTFIT_AUTO_FIELD_get_square_en(data)                                 ((0x00000008&(data))>>3)
#define  SMARTFIT_AUTO_FIELD_get_sum_pixel_num(data)                             ((0x00000004&(data))>>2)
#define  SMARTFIT_AUTO_FIELD_get_filter_sel(data)                                (0x00000003&(data))

#define  SMARTFIT_AUTO_H_BOUNDARY                                                0x18022004
#define  SMARTFIT_AUTO_H_BOUNDARY_reg_addr                                       "0xB8022004"
#define  SMARTFIT_AUTO_H_BOUNDARY_reg                                            0xB8022004
#define  SMARTFIT_AUTO_H_BOUNDARY_inst_addr                                      "0x0001"
#define  set_SMARTFIT_AUTO_H_BOUNDARY_reg(data)                                  (*((volatile unsigned int*)SMARTFIT_AUTO_H_BOUNDARY_reg)=data)
#define  get_SMARTFIT_AUTO_H_BOUNDARY_reg                                        (*((volatile unsigned int*)SMARTFIT_AUTO_H_BOUNDARY_reg))
#define  SMARTFIT_AUTO_H_BOUNDARY_hb_sta_shift                                   (16)
#define  SMARTFIT_AUTO_H_BOUNDARY_hb_end_shift                                   (0)
#define  SMARTFIT_AUTO_H_BOUNDARY_hb_sta_mask                                    (0x3FFF0000)
#define  SMARTFIT_AUTO_H_BOUNDARY_hb_end_mask                                    (0x00003FFF)
#define  SMARTFIT_AUTO_H_BOUNDARY_hb_sta(data)                                   (0x3FFF0000&((data)<<16))
#define  SMARTFIT_AUTO_H_BOUNDARY_hb_end(data)                                   (0x00003FFF&(data))
#define  SMARTFIT_AUTO_H_BOUNDARY_get_hb_sta(data)                               ((0x3FFF0000&(data))>>16)
#define  SMARTFIT_AUTO_H_BOUNDARY_get_hb_end(data)                               (0x00003FFF&(data))

#define  SMARTFIT_AUTO_V_BOUNDARY                                                0x18022008
#define  SMARTFIT_AUTO_V_BOUNDARY_reg_addr                                       "0xB8022008"
#define  SMARTFIT_AUTO_V_BOUNDARY_reg                                            0xB8022008
#define  SMARTFIT_AUTO_V_BOUNDARY_inst_addr                                      "0x0002"
#define  set_SMARTFIT_AUTO_V_BOUNDARY_reg(data)                                  (*((volatile unsigned int*)SMARTFIT_AUTO_V_BOUNDARY_reg)=data)
#define  get_SMARTFIT_AUTO_V_BOUNDARY_reg                                        (*((volatile unsigned int*)SMARTFIT_AUTO_V_BOUNDARY_reg))
#define  SMARTFIT_AUTO_V_BOUNDARY_vb_sta_shift                                   (16)
#define  SMARTFIT_AUTO_V_BOUNDARY_vb_end_shift                                   (0)
#define  SMARTFIT_AUTO_V_BOUNDARY_vb_sta_mask                                    (0x1FFF0000)
#define  SMARTFIT_AUTO_V_BOUNDARY_vb_end_mask                                    (0x00001FFF)
#define  SMARTFIT_AUTO_V_BOUNDARY_vb_sta(data)                                   (0x1FFF0000&((data)<<16))
#define  SMARTFIT_AUTO_V_BOUNDARY_vb_end(data)                                   (0x00001FFF&(data))
#define  SMARTFIT_AUTO_V_BOUNDARY_get_vb_sta(data)                               ((0x1FFF0000&(data))>>16)
#define  SMARTFIT_AUTO_V_BOUNDARY_get_vb_end(data)                               (0x00001FFF&(data))

#define  SMARTFIT_AUTO_R_G_B_MARGIN                                              0x1802200C
#define  SMARTFIT_AUTO_R_G_B_MARGIN_reg_addr                                     "0xB802200C"
#define  SMARTFIT_AUTO_R_G_B_MARGIN_reg                                          0xB802200C
#define  SMARTFIT_AUTO_R_G_B_MARGIN_inst_addr                                    "0x0003"
#define  set_SMARTFIT_AUTO_R_G_B_MARGIN_reg(data)                                (*((volatile unsigned int*)SMARTFIT_AUTO_R_G_B_MARGIN_reg)=data)
#define  get_SMARTFIT_AUTO_R_G_B_MARGIN_reg                                      (*((volatile unsigned int*)SMARTFIT_AUTO_R_G_B_MARGIN_reg))
#define  SMARTFIT_AUTO_R_G_B_MARGIN_red_nm_shift                                 (26)
#define  SMARTFIT_AUTO_R_G_B_MARGIN_adj_even_odd_shift                           (25)
#define  SMARTFIT_AUTO_R_G_B_MARGIN_adj_even_odd_en_shift                        (24)
#define  SMARTFIT_AUTO_R_G_B_MARGIN_grn_nm_shift                                 (18)
#define  SMARTFIT_AUTO_R_G_B_MARGIN_vb_th_shift                                  (16)
#define  SMARTFIT_AUTO_R_G_B_MARGIN_blu_nm_shift                                 (10)
#define  SMARTFIT_AUTO_R_G_B_MARGIN_color_sel_shift                              (8)
#define  SMARTFIT_AUTO_R_G_B_MARGIN_diff_th_shift                                (0)
#define  SMARTFIT_AUTO_R_G_B_MARGIN_red_nm_mask                                  (0xFC000000)
#define  SMARTFIT_AUTO_R_G_B_MARGIN_adj_even_odd_mask                            (0x02000000)
#define  SMARTFIT_AUTO_R_G_B_MARGIN_adj_even_odd_en_mask                         (0x01000000)
#define  SMARTFIT_AUTO_R_G_B_MARGIN_grn_nm_mask                                  (0x00FC0000)
#define  SMARTFIT_AUTO_R_G_B_MARGIN_vb_th_mask                                   (0x00030000)
#define  SMARTFIT_AUTO_R_G_B_MARGIN_blu_nm_mask                                  (0x0000FC00)
#define  SMARTFIT_AUTO_R_G_B_MARGIN_color_sel_mask                               (0x00000300)
#define  SMARTFIT_AUTO_R_G_B_MARGIN_diff_th_mask                                 (0x000000FF)
#define  SMARTFIT_AUTO_R_G_B_MARGIN_red_nm(data)                                 (0xFC000000&((data)<<26))
#define  SMARTFIT_AUTO_R_G_B_MARGIN_adj_even_odd(data)                           (0x02000000&((data)<<25))
#define  SMARTFIT_AUTO_R_G_B_MARGIN_adj_even_odd_en(data)                        (0x01000000&((data)<<24))
#define  SMARTFIT_AUTO_R_G_B_MARGIN_grn_nm(data)                                 (0x00FC0000&((data)<<18))
#define  SMARTFIT_AUTO_R_G_B_MARGIN_vb_th(data)                                  (0x00030000&((data)<<16))
#define  SMARTFIT_AUTO_R_G_B_MARGIN_blu_nm(data)                                 (0x0000FC00&((data)<<10))
#define  SMARTFIT_AUTO_R_G_B_MARGIN_color_sel(data)                              (0x00000300&((data)<<8))
#define  SMARTFIT_AUTO_R_G_B_MARGIN_diff_th(data)                                (0x000000FF&(data))
#define  SMARTFIT_AUTO_R_G_B_MARGIN_get_red_nm(data)                             ((0xFC000000&(data))>>26)
#define  SMARTFIT_AUTO_R_G_B_MARGIN_get_adj_even_odd(data)                       ((0x02000000&(data))>>25)
#define  SMARTFIT_AUTO_R_G_B_MARGIN_get_adj_even_odd_en(data)                    ((0x01000000&(data))>>24)
#define  SMARTFIT_AUTO_R_G_B_MARGIN_get_grn_nm(data)                             ((0x00FC0000&(data))>>18)
#define  SMARTFIT_AUTO_R_G_B_MARGIN_get_vb_th(data)                              ((0x00030000&(data))>>16)
#define  SMARTFIT_AUTO_R_G_B_MARGIN_get_blu_nm(data)                             ((0x0000FC00&(data))>>10)
#define  SMARTFIT_AUTO_R_G_B_MARGIN_get_color_sel(data)                          ((0x00000300&(data))>>8)
#define  SMARTFIT_AUTO_R_G_B_MARGIN_get_diff_th(data)                            (0x000000FF&(data))

#define  SMARTFIT_AUTO_ADJ                                                       0x18022010
#define  SMARTFIT_AUTO_ADJ_reg_addr                                              "0xB8022010"
#define  SMARTFIT_AUTO_ADJ_reg                                                   0xB8022010
#define  SMARTFIT_AUTO_ADJ_inst_addr                                             "0x0004"
#define  set_SMARTFIT_AUTO_ADJ_reg(data)                                         (*((volatile unsigned int*)SMARTFIT_AUTO_ADJ_reg)=data)
#define  get_SMARTFIT_AUTO_ADJ_reg                                               (*((volatile unsigned int*)SMARTFIT_AUTO_ADJ_reg))
#define  SMARTFIT_AUTO_ADJ_m_vgen_en_shift                                       (7)
#define  SMARTFIT_AUTO_ADJ_diff_pixel_sel_shift                                  (6)
#define  SMARTFIT_AUTO_ADJ_force_flip__shift                                     (5)
#define  SMARTFIT_AUTO_ADJ_sum_max_shift                                         (4)
#define  SMARTFIT_AUTO_ADJ_pulse_det_en_shift                                    (3)
#define  SMARTFIT_AUTO_ADJ_autophase_sel_tri_shift                               (2)
#define  SMARTFIT_AUTO_ADJ_diff_en_shift                                         (1)
#define  SMARTFIT_AUTO_ADJ_now_af_shift                                          (0)
#define  SMARTFIT_AUTO_ADJ_m_vgen_en_mask                                        (0x00000080)
#define  SMARTFIT_AUTO_ADJ_diff_pixel_sel_mask                                   (0x00000040)
#define  SMARTFIT_AUTO_ADJ_force_flip__mask                                      (0x00000020)
#define  SMARTFIT_AUTO_ADJ_sum_max_mask                                          (0x00000010)
#define  SMARTFIT_AUTO_ADJ_pulse_det_en_mask                                     (0x00000008)
#define  SMARTFIT_AUTO_ADJ_autophase_sel_tri_mask                                (0x00000004)
#define  SMARTFIT_AUTO_ADJ_diff_en_mask                                          (0x00000002)
#define  SMARTFIT_AUTO_ADJ_now_af_mask                                           (0x00000001)
#define  SMARTFIT_AUTO_ADJ_m_vgen_en(data)                                       (0x00000080&((data)<<7))
#define  SMARTFIT_AUTO_ADJ_diff_pixel_sel(data)                                  (0x00000040&((data)<<6))
#define  SMARTFIT_AUTO_ADJ_force_flip_(data)                                     (0x00000020&((data)<<5))
#define  SMARTFIT_AUTO_ADJ_sum_max(data)                                         (0x00000010&((data)<<4))
#define  SMARTFIT_AUTO_ADJ_pulse_det_en(data)                                    (0x00000008&((data)<<3))
#define  SMARTFIT_AUTO_ADJ_autophase_sel_tri(data)                               (0x00000004&((data)<<2))
#define  SMARTFIT_AUTO_ADJ_diff_en(data)                                         (0x00000002&((data)<<1))
#define  SMARTFIT_AUTO_ADJ_now_af(data)                                          (0x00000001&(data))
#define  SMARTFIT_AUTO_ADJ_get_m_vgen_en(data)                                   ((0x00000080&(data))>>7)
#define  SMARTFIT_AUTO_ADJ_get_diff_pixel_sel(data)                              ((0x00000040&(data))>>6)
#define  SMARTFIT_AUTO_ADJ_get_force_flip_(data)                                 ((0x00000020&(data))>>5)
#define  SMARTFIT_AUTO_ADJ_get_sum_max(data)                                     ((0x00000010&(data))>>4)
#define  SMARTFIT_AUTO_ADJ_get_pulse_det_en(data)                                ((0x00000008&(data))>>3)
#define  SMARTFIT_AUTO_ADJ_get_autophase_sel_tri(data)                           ((0x00000004&(data))>>2)
#define  SMARTFIT_AUTO_ADJ_get_diff_en(data)                                     ((0x00000002&(data))>>1)
#define  SMARTFIT_AUTO_ADJ_get_now_af(data)                                      (0x00000001&(data))

#define  SMARTFIT_AUTO_RESULT_VSTA_END                                           0x18022014
#define  SMARTFIT_AUTO_RESULT_VSTA_END_reg_addr                                  "0xB8022014"
#define  SMARTFIT_AUTO_RESULT_VSTA_END_reg                                       0xB8022014
#define  SMARTFIT_AUTO_RESULT_VSTA_END_inst_addr                                 "0x0005"
#define  set_SMARTFIT_AUTO_RESULT_VSTA_END_reg(data)                             (*((volatile unsigned int*)SMARTFIT_AUTO_RESULT_VSTA_END_reg)=data)
#define  get_SMARTFIT_AUTO_RESULT_VSTA_END_reg                                   (*((volatile unsigned int*)SMARTFIT_AUTO_RESULT_VSTA_END_reg))
#define  SMARTFIT_AUTO_RESULT_VSTA_END_vx_sta_shift                              (16)
#define  SMARTFIT_AUTO_RESULT_VSTA_END_vx_end_shift                              (0)
#define  SMARTFIT_AUTO_RESULT_VSTA_END_vx_sta_mask                               (0x1FFF0000)
#define  SMARTFIT_AUTO_RESULT_VSTA_END_vx_end_mask                               (0x00001FFF)
#define  SMARTFIT_AUTO_RESULT_VSTA_END_vx_sta(data)                              (0x1FFF0000&((data)<<16))
#define  SMARTFIT_AUTO_RESULT_VSTA_END_vx_end(data)                              (0x00001FFF&(data))
#define  SMARTFIT_AUTO_RESULT_VSTA_END_get_vx_sta(data)                          ((0x1FFF0000&(data))>>16)
#define  SMARTFIT_AUTO_RESULT_VSTA_END_get_vx_end(data)                          (0x00001FFF&(data))

#define  SMARTFIT_AUTO_RESULT_HSTA_END                                           0x18022018
#define  SMARTFIT_AUTO_RESULT_HSTA_END_reg_addr                                  "0xB8022018"
#define  SMARTFIT_AUTO_RESULT_HSTA_END_reg                                       0xB8022018
#define  SMARTFIT_AUTO_RESULT_HSTA_END_inst_addr                                 "0x0006"
#define  set_SMARTFIT_AUTO_RESULT_HSTA_END_reg(data)                             (*((volatile unsigned int*)SMARTFIT_AUTO_RESULT_HSTA_END_reg)=data)
#define  get_SMARTFIT_AUTO_RESULT_HSTA_END_reg                                   (*((volatile unsigned int*)SMARTFIT_AUTO_RESULT_HSTA_END_reg))
#define  SMARTFIT_AUTO_RESULT_HSTA_END_hx_sta_shift                              (16)
#define  SMARTFIT_AUTO_RESULT_HSTA_END_hx_end_shift                              (0)
#define  SMARTFIT_AUTO_RESULT_HSTA_END_hx_sta_mask                               (0x3FFF0000)
#define  SMARTFIT_AUTO_RESULT_HSTA_END_hx_end_mask                               (0x00003FFF)
#define  SMARTFIT_AUTO_RESULT_HSTA_END_hx_sta(data)                              (0x3FFF0000&((data)<<16))
#define  SMARTFIT_AUTO_RESULT_HSTA_END_hx_end(data)                              (0x00003FFF&(data))
#define  SMARTFIT_AUTO_RESULT_HSTA_END_get_hx_sta(data)                          ((0x3FFF0000&(data))>>16)
#define  SMARTFIT_AUTO_RESULT_HSTA_END_get_hx_end(data)                          (0x00003FFF&(data))

#define  SMARTFIT_AUTO_RESULT_PHASE_M                                            0x1802201C
#define  SMARTFIT_AUTO_RESULT_PHASE_M_reg_addr                                   "0xB802201C"
#define  SMARTFIT_AUTO_RESULT_PHASE_M_reg                                        0xB802201C
#define  SMARTFIT_AUTO_RESULT_PHASE_M_inst_addr                                  "0x0007"
#define  set_SMARTFIT_AUTO_RESULT_PHASE_M_reg(data)                              (*((volatile unsigned int*)SMARTFIT_AUTO_RESULT_PHASE_M_reg)=data)
#define  get_SMARTFIT_AUTO_RESULT_PHASE_M_reg                                    (*((volatile unsigned int*)SMARTFIT_AUTO_RESULT_PHASE_M_reg))
#define  SMARTFIT_AUTO_RESULT_PHASE_M_acc_41_32_shift                            (0)
#define  SMARTFIT_AUTO_RESULT_PHASE_M_acc_41_32_mask                             (0x000003FF)
#define  SMARTFIT_AUTO_RESULT_PHASE_M_acc_41_32(data)                            (0x000003FF&(data))
#define  SMARTFIT_AUTO_RESULT_PHASE_M_get_acc_41_32(data)                        (0x000003FF&(data))

#define  SMARTFIT_AUTO_RESULT_PHASE_L                                            0x18022020
#define  SMARTFIT_AUTO_RESULT_PHASE_L_reg_addr                                   "0xB8022020"
#define  SMARTFIT_AUTO_RESULT_PHASE_L_reg                                        0xB8022020
#define  SMARTFIT_AUTO_RESULT_PHASE_L_inst_addr                                  "0x0008"
#define  set_SMARTFIT_AUTO_RESULT_PHASE_L_reg(data)                              (*((volatile unsigned int*)SMARTFIT_AUTO_RESULT_PHASE_L_reg)=data)
#define  get_SMARTFIT_AUTO_RESULT_PHASE_L_reg                                    (*((volatile unsigned int*)SMARTFIT_AUTO_RESULT_PHASE_L_reg))
#define  SMARTFIT_AUTO_RESULT_PHASE_L_acc_31_0_shift                             (0)
#define  SMARTFIT_AUTO_RESULT_PHASE_L_acc_31_0_mask                              (0xFFFFFFFF)
#define  SMARTFIT_AUTO_RESULT_PHASE_L_acc_31_0(data)                             (0xFFFFFFFF&(data))
#define  SMARTFIT_AUTO_RESULT_PHASE_L_get_acc_31_0(data)                         (0xFFFFFFFF&(data))

#define  SMARTFIT_AUTO_PHASE_CTRL0                                               0x18022024
#define  SMARTFIT_AUTO_PHASE_CTRL0_reg_addr                                      "0xB8022024"
#define  SMARTFIT_AUTO_PHASE_CTRL0_reg                                           0xB8022024
#define  SMARTFIT_AUTO_PHASE_CTRL0_inst_addr                                     "0x0009"
#define  set_SMARTFIT_AUTO_PHASE_CTRL0_reg(data)                                 (*((volatile unsigned int*)SMARTFIT_AUTO_PHASE_CTRL0_reg)=data)
#define  get_SMARTFIT_AUTO_PHASE_CTRL0_reg                                       (*((volatile unsigned int*)SMARTFIT_AUTO_PHASE_CTRL0_reg))
#define  SMARTFIT_AUTO_PHASE_CTRL0_autophase_en_shift                            (31)
#define  SMARTFIT_AUTO_PHASE_CTRL0_autophase_step_shift                          (22)
#define  SMARTFIT_AUTO_PHASE_CTRL0_init_phase_shift                              (16)
#define  SMARTFIT_AUTO_PHASE_CTRL0_autophase_max_step_shift                      (8)
#define  SMARTFIT_AUTO_PHASE_CTRL0_autophase_flg_shift                           (7)
#define  SMARTFIT_AUTO_PHASE_CTRL0_autosod_step_num_shift                        (0)
#define  SMARTFIT_AUTO_PHASE_CTRL0_autophase_en_mask                             (0x80000000)
#define  SMARTFIT_AUTO_PHASE_CTRL0_autophase_step_mask                           (0x01C00000)
#define  SMARTFIT_AUTO_PHASE_CTRL0_init_phase_mask                               (0x003F0000)
#define  SMARTFIT_AUTO_PHASE_CTRL0_autophase_max_step_mask                       (0x00007F00)
#define  SMARTFIT_AUTO_PHASE_CTRL0_autophase_flg_mask                            (0x00000080)
#define  SMARTFIT_AUTO_PHASE_CTRL0_autosod_step_num_mask                         (0x0000007F)
#define  SMARTFIT_AUTO_PHASE_CTRL0_autophase_en(data)                            (0x80000000&((data)<<31))
#define  SMARTFIT_AUTO_PHASE_CTRL0_autophase_step(data)                          (0x01C00000&((data)<<22))
#define  SMARTFIT_AUTO_PHASE_CTRL0_init_phase(data)                              (0x003F0000&((data)<<16))
#define  SMARTFIT_AUTO_PHASE_CTRL0_autophase_max_step(data)                      (0x00007F00&((data)<<8))
#define  SMARTFIT_AUTO_PHASE_CTRL0_autophase_flg(data)                           (0x00000080&((data)<<7))
#define  SMARTFIT_AUTO_PHASE_CTRL0_autosod_step_num(data)                        (0x0000007F&(data))
#define  SMARTFIT_AUTO_PHASE_CTRL0_get_autophase_en(data)                        ((0x80000000&(data))>>31)
#define  SMARTFIT_AUTO_PHASE_CTRL0_get_autophase_step(data)                      ((0x01C00000&(data))>>22)
#define  SMARTFIT_AUTO_PHASE_CTRL0_get_init_phase(data)                          ((0x003F0000&(data))>>16)
#define  SMARTFIT_AUTO_PHASE_CTRL0_get_autophase_max_step(data)                  ((0x00007F00&(data))>>8)
#define  SMARTFIT_AUTO_PHASE_CTRL0_get_autophase_flg(data)                       ((0x00000080&(data))>>7)
#define  SMARTFIT_AUTO_PHASE_CTRL0_get_autosod_step_num(data)                    (0x0000007F&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======SMARTFIT register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smartfit_src_sel:1;
        RBus_UInt32  auto_balance_rgb:1;
        RBus_UInt32  smfit_en_n:1;
        RBus_UInt32  res1:17;
        RBus_UInt32  adj_source:2;
        RBus_UInt32  rl_sel_en:1;
        RBus_UInt32  rl_sel:1;
        RBus_UInt32  odd_sel_en:1;
        RBus_UInt32  odd_sel:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  rgb_in_one_en:1;
        RBus_UInt32  square_en:1;
        RBus_UInt32  sum_pixel_num:1;
        RBus_UInt32  filter_sel:2;
    };
}smartfit_auto_field_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  hb_sta:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  hb_end:14;
    };
}smartfit_auto_h_boundary_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  vb_sta:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  vb_end:13;
    };
}smartfit_auto_v_boundary_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  red_nm:6;
        RBus_UInt32  adj_even_odd:1;
        RBus_UInt32  adj_even_odd_en:1;
        RBus_UInt32  grn_nm:6;
        RBus_UInt32  vb_th:2;
        RBus_UInt32  blu_nm:6;
        RBus_UInt32  color_sel:2;
        RBus_UInt32  diff_th:8;
    };
}smartfit_auto_r_g_b_margin_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  m_vgen_en:1;
        RBus_UInt32  diff_pixel_sel:1;
        RBus_UInt32  force_flip:1;
        RBus_UInt32  sum_max:1;
        RBus_UInt32  pulse_det_en:1;
        RBus_UInt32  autophase_sel_tri:1;
        RBus_UInt32  diff_en:1;
        RBus_UInt32  now_af:1;
    };
}smartfit_auto_adj_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  vx_sta:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  vx_end:13;
    };
}smartfit_auto_result_vsta_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  hx_sta:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  hx_end:14;
    };
}smartfit_auto_result_hsta_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  acc_41_32:10;
    };
}smartfit_auto_result_phase_m_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  acc_31_0:32;
    };
}smartfit_auto_result_phase_l_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  autophase_en:1;
        RBus_UInt32  res1:6;
        RBus_UInt32  autophase_step:3;
        RBus_UInt32  init_phase:6;
        RBus_UInt32  res2:1;
        RBus_UInt32  autophase_max_step:7;
        RBus_UInt32  autophase_flg:1;
        RBus_UInt32  autosod_step_num:7;
    };
}smartfit_auto_phase_ctrl0_RBUS;

#else //apply LITTLE_ENDIAN

//======SMARTFIT register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  filter_sel:2;
        RBus_UInt32  sum_pixel_num:1;
        RBus_UInt32  square_en:1;
        RBus_UInt32  rgb_in_one_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  odd_sel:1;
        RBus_UInt32  odd_sel_en:1;
        RBus_UInt32  rl_sel:1;
        RBus_UInt32  rl_sel_en:1;
        RBus_UInt32  adj_source:2;
        RBus_UInt32  res2:17;
        RBus_UInt32  smfit_en_n:1;
        RBus_UInt32  auto_balance_rgb:1;
        RBus_UInt32  smartfit_src_sel:1;
    };
}smartfit_auto_field_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hb_end:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  hb_sta:14;
        RBus_UInt32  res2:2;
    };
}smartfit_auto_h_boundary_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vb_end:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  vb_sta:13;
        RBus_UInt32  res2:3;
    };
}smartfit_auto_v_boundary_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  diff_th:8;
        RBus_UInt32  color_sel:2;
        RBus_UInt32  blu_nm:6;
        RBus_UInt32  vb_th:2;
        RBus_UInt32  grn_nm:6;
        RBus_UInt32  adj_even_odd_en:1;
        RBus_UInt32  adj_even_odd:1;
        RBus_UInt32  red_nm:6;
    };
}smartfit_auto_r_g_b_margin_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  now_af:1;
        RBus_UInt32  diff_en:1;
        RBus_UInt32  autophase_sel_tri:1;
        RBus_UInt32  pulse_det_en:1;
        RBus_UInt32  sum_max:1;
        RBus_UInt32  force_flip:1;
        RBus_UInt32  diff_pixel_sel:1;
        RBus_UInt32  m_vgen_en:1;
        RBus_UInt32  res1:24;
    };
}smartfit_auto_adj_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vx_end:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  vx_sta:13;
        RBus_UInt32  res2:3;
    };
}smartfit_auto_result_vsta_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hx_end:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  hx_sta:14;
        RBus_UInt32  res2:2;
    };
}smartfit_auto_result_hsta_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  acc_41_32:10;
        RBus_UInt32  res1:22;
    };
}smartfit_auto_result_phase_m_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  acc_31_0:32;
    };
}smartfit_auto_result_phase_l_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  autosod_step_num:7;
        RBus_UInt32  autophase_flg:1;
        RBus_UInt32  autophase_max_step:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  init_phase:6;
        RBus_UInt32  autophase_step:3;
        RBus_UInt32  res2:6;
        RBus_UInt32  autophase_en:1;
    };
}smartfit_auto_phase_ctrl0_RBUS;




#endif 


#endif 
