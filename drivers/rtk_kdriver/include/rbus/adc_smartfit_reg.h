/**
* @file MacArthur5-DesignSpec-I-Domain_ADC_SmartFIT
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_ADC_SMARTFIT_REG_H_
#define _RBUS_ADC_SMARTFIT_REG_H_

#include "rbus_types.h"



//  ADC_SMARTFIT Register Address
#define  ADC_SMARTFIT_ADC_AUTO_FIELD                                             0x18020400
#define  ADC_SMARTFIT_ADC_AUTO_FIELD_reg_addr                                    "0xB8020400"
#define  ADC_SMARTFIT_ADC_AUTO_FIELD_reg                                         0xB8020400
#define  ADC_SMARTFIT_ADC_AUTO_FIELD_inst_addr                                   "0x0000"
#define  set_ADC_SMARTFIT_ADC_AUTO_FIELD_reg(data)                               (*((volatile unsigned int*)ADC_SMARTFIT_ADC_AUTO_FIELD_reg)=data)
#define  get_ADC_SMARTFIT_ADC_AUTO_FIELD_reg                                     (*((volatile unsigned int*)ADC_SMARTFIT_ADC_AUTO_FIELD_reg))
#define  ADC_SMARTFIT_ADC_AUTO_FIELD_auto_balance_rgb_shift                      (30)
#define  ADC_SMARTFIT_ADC_AUTO_FIELD_smfit_en_n_shift                            (29)
#define  ADC_SMARTFIT_ADC_AUTO_FIELD_smfit_vs_delay_sel_shift                    (13)
#define  ADC_SMARTFIT_ADC_AUTO_FIELD_vgip_db_disable_shift                       (12)
#define  ADC_SMARTFIT_ADC_AUTO_FIELD_adj_source_shift                            (10)
#define  ADC_SMARTFIT_ADC_AUTO_FIELD_odd_sel_en_shift                            (7)
#define  ADC_SMARTFIT_ADC_AUTO_FIELD_odd_sel_shift                               (6)
#define  ADC_SMARTFIT_ADC_AUTO_FIELD_rgb_in_one_en_shift                         (4)
#define  ADC_SMARTFIT_ADC_AUTO_FIELD_square_en_shift                             (3)
#define  ADC_SMARTFIT_ADC_AUTO_FIELD_sum_pixel_num_shift                         (2)
#define  ADC_SMARTFIT_ADC_AUTO_FIELD_filter_sel_shift                            (0)
#define  ADC_SMARTFIT_ADC_AUTO_FIELD_auto_balance_rgb_mask                       (0xC0000000)
#define  ADC_SMARTFIT_ADC_AUTO_FIELD_smfit_en_n_mask                             (0x20000000)
#define  ADC_SMARTFIT_ADC_AUTO_FIELD_smfit_vs_delay_sel_mask                     (0x00002000)
#define  ADC_SMARTFIT_ADC_AUTO_FIELD_vgip_db_disable_mask                        (0x00001000)
#define  ADC_SMARTFIT_ADC_AUTO_FIELD_adj_source_mask                             (0x00000C00)
#define  ADC_SMARTFIT_ADC_AUTO_FIELD_odd_sel_en_mask                             (0x00000080)
#define  ADC_SMARTFIT_ADC_AUTO_FIELD_odd_sel_mask                                (0x00000040)
#define  ADC_SMARTFIT_ADC_AUTO_FIELD_rgb_in_one_en_mask                          (0x00000010)
#define  ADC_SMARTFIT_ADC_AUTO_FIELD_square_en_mask                              (0x00000008)
#define  ADC_SMARTFIT_ADC_AUTO_FIELD_sum_pixel_num_mask                          (0x00000004)
#define  ADC_SMARTFIT_ADC_AUTO_FIELD_filter_sel_mask                             (0x00000003)
#define  ADC_SMARTFIT_ADC_AUTO_FIELD_auto_balance_rgb(data)                      (0xC0000000&((data)<<30))
#define  ADC_SMARTFIT_ADC_AUTO_FIELD_smfit_en_n(data)                            (0x20000000&((data)<<29))
#define  ADC_SMARTFIT_ADC_AUTO_FIELD_smfit_vs_delay_sel(data)                    (0x00002000&((data)<<13))
#define  ADC_SMARTFIT_ADC_AUTO_FIELD_vgip_db_disable(data)                       (0x00001000&((data)<<12))
#define  ADC_SMARTFIT_ADC_AUTO_FIELD_adj_source(data)                            (0x00000C00&((data)<<10))
#define  ADC_SMARTFIT_ADC_AUTO_FIELD_odd_sel_en(data)                            (0x00000080&((data)<<7))
#define  ADC_SMARTFIT_ADC_AUTO_FIELD_odd_sel(data)                               (0x00000040&((data)<<6))
#define  ADC_SMARTFIT_ADC_AUTO_FIELD_rgb_in_one_en(data)                         (0x00000010&((data)<<4))
#define  ADC_SMARTFIT_ADC_AUTO_FIELD_square_en(data)                             (0x00000008&((data)<<3))
#define  ADC_SMARTFIT_ADC_AUTO_FIELD_sum_pixel_num(data)                         (0x00000004&((data)<<2))
#define  ADC_SMARTFIT_ADC_AUTO_FIELD_filter_sel(data)                            (0x00000003&(data))
#define  ADC_SMARTFIT_ADC_AUTO_FIELD_get_auto_balance_rgb(data)                  ((0xC0000000&(data))>>30)
#define  ADC_SMARTFIT_ADC_AUTO_FIELD_get_smfit_en_n(data)                        ((0x20000000&(data))>>29)
#define  ADC_SMARTFIT_ADC_AUTO_FIELD_get_smfit_vs_delay_sel(data)                ((0x00002000&(data))>>13)
#define  ADC_SMARTFIT_ADC_AUTO_FIELD_get_vgip_db_disable(data)                   ((0x00001000&(data))>>12)
#define  ADC_SMARTFIT_ADC_AUTO_FIELD_get_adj_source(data)                        ((0x00000C00&(data))>>10)
#define  ADC_SMARTFIT_ADC_AUTO_FIELD_get_odd_sel_en(data)                        ((0x00000080&(data))>>7)
#define  ADC_SMARTFIT_ADC_AUTO_FIELD_get_odd_sel(data)                           ((0x00000040&(data))>>6)
#define  ADC_SMARTFIT_ADC_AUTO_FIELD_get_rgb_in_one_en(data)                     ((0x00000010&(data))>>4)
#define  ADC_SMARTFIT_ADC_AUTO_FIELD_get_square_en(data)                         ((0x00000008&(data))>>3)
#define  ADC_SMARTFIT_ADC_AUTO_FIELD_get_sum_pixel_num(data)                     ((0x00000004&(data))>>2)
#define  ADC_SMARTFIT_ADC_AUTO_FIELD_get_filter_sel(data)                        (0x00000003&(data))

#define  ADC_SMARTFIT_ADC_AUTO_H_BOUNDARY                                        0x18020404
#define  ADC_SMARTFIT_ADC_AUTO_H_BOUNDARY_reg_addr                               "0xB8020404"
#define  ADC_SMARTFIT_ADC_AUTO_H_BOUNDARY_reg                                    0xB8020404
#define  ADC_SMARTFIT_ADC_AUTO_H_BOUNDARY_inst_addr                              "0x0001"
#define  set_ADC_SMARTFIT_ADC_AUTO_H_BOUNDARY_reg(data)                          (*((volatile unsigned int*)ADC_SMARTFIT_ADC_AUTO_H_BOUNDARY_reg)=data)
#define  get_ADC_SMARTFIT_ADC_AUTO_H_BOUNDARY_reg                                (*((volatile unsigned int*)ADC_SMARTFIT_ADC_AUTO_H_BOUNDARY_reg))
#define  ADC_SMARTFIT_ADC_AUTO_H_BOUNDARY_hb_sta_shift                           (16)
#define  ADC_SMARTFIT_ADC_AUTO_H_BOUNDARY_hb_end_shift                           (0)
#define  ADC_SMARTFIT_ADC_AUTO_H_BOUNDARY_hb_sta_mask                            (0x3FFF0000)
#define  ADC_SMARTFIT_ADC_AUTO_H_BOUNDARY_hb_end_mask                            (0x00003FFF)
#define  ADC_SMARTFIT_ADC_AUTO_H_BOUNDARY_hb_sta(data)                           (0x3FFF0000&((data)<<16))
#define  ADC_SMARTFIT_ADC_AUTO_H_BOUNDARY_hb_end(data)                           (0x00003FFF&(data))
#define  ADC_SMARTFIT_ADC_AUTO_H_BOUNDARY_get_hb_sta(data)                       ((0x3FFF0000&(data))>>16)
#define  ADC_SMARTFIT_ADC_AUTO_H_BOUNDARY_get_hb_end(data)                       (0x00003FFF&(data))

#define  ADC_SMARTFIT_ADC_AUTO_V_BOUNDARY                                        0x18020408
#define  ADC_SMARTFIT_ADC_AUTO_V_BOUNDARY_reg_addr                               "0xB8020408"
#define  ADC_SMARTFIT_ADC_AUTO_V_BOUNDARY_reg                                    0xB8020408
#define  ADC_SMARTFIT_ADC_AUTO_V_BOUNDARY_inst_addr                              "0x0002"
#define  set_ADC_SMARTFIT_ADC_AUTO_V_BOUNDARY_reg(data)                          (*((volatile unsigned int*)ADC_SMARTFIT_ADC_AUTO_V_BOUNDARY_reg)=data)
#define  get_ADC_SMARTFIT_ADC_AUTO_V_BOUNDARY_reg                                (*((volatile unsigned int*)ADC_SMARTFIT_ADC_AUTO_V_BOUNDARY_reg))
#define  ADC_SMARTFIT_ADC_AUTO_V_BOUNDARY_vb_sta_shift                           (16)
#define  ADC_SMARTFIT_ADC_AUTO_V_BOUNDARY_vb_end_shift                           (0)
#define  ADC_SMARTFIT_ADC_AUTO_V_BOUNDARY_vb_sta_mask                            (0x1FFF0000)
#define  ADC_SMARTFIT_ADC_AUTO_V_BOUNDARY_vb_end_mask                            (0x00001FFF)
#define  ADC_SMARTFIT_ADC_AUTO_V_BOUNDARY_vb_sta(data)                           (0x1FFF0000&((data)<<16))
#define  ADC_SMARTFIT_ADC_AUTO_V_BOUNDARY_vb_end(data)                           (0x00001FFF&(data))
#define  ADC_SMARTFIT_ADC_AUTO_V_BOUNDARY_get_vb_sta(data)                       ((0x1FFF0000&(data))>>16)
#define  ADC_SMARTFIT_ADC_AUTO_V_BOUNDARY_get_vb_end(data)                       (0x00001FFF&(data))

#define  ADC_SMARTFIT_ADC_AUTO_R_G_B_MARGIN                                      0x1802040C
#define  ADC_SMARTFIT_ADC_AUTO_R_G_B_MARGIN_reg_addr                             "0xB802040C"
#define  ADC_SMARTFIT_ADC_AUTO_R_G_B_MARGIN_reg                                  0xB802040C
#define  ADC_SMARTFIT_ADC_AUTO_R_G_B_MARGIN_inst_addr                            "0x0003"
#define  set_ADC_SMARTFIT_ADC_AUTO_R_G_B_MARGIN_reg(data)                        (*((volatile unsigned int*)ADC_SMARTFIT_ADC_AUTO_R_G_B_MARGIN_reg)=data)
#define  get_ADC_SMARTFIT_ADC_AUTO_R_G_B_MARGIN_reg                              (*((volatile unsigned int*)ADC_SMARTFIT_ADC_AUTO_R_G_B_MARGIN_reg))
#define  ADC_SMARTFIT_ADC_AUTO_R_G_B_MARGIN_red_nm_shift                         (26)
#define  ADC_SMARTFIT_ADC_AUTO_R_G_B_MARGIN_adj_even_odd_shift                   (25)
#define  ADC_SMARTFIT_ADC_AUTO_R_G_B_MARGIN_adj_even_odd_en_shift                (24)
#define  ADC_SMARTFIT_ADC_AUTO_R_G_B_MARGIN_grn_nm_shift                         (18)
#define  ADC_SMARTFIT_ADC_AUTO_R_G_B_MARGIN_vb_th_shift                          (16)
#define  ADC_SMARTFIT_ADC_AUTO_R_G_B_MARGIN_blu_nm_shift                         (10)
#define  ADC_SMARTFIT_ADC_AUTO_R_G_B_MARGIN_color_sel_shift                      (8)
#define  ADC_SMARTFIT_ADC_AUTO_R_G_B_MARGIN_diff_th_shift                        (0)
#define  ADC_SMARTFIT_ADC_AUTO_R_G_B_MARGIN_red_nm_mask                          (0xFC000000)
#define  ADC_SMARTFIT_ADC_AUTO_R_G_B_MARGIN_adj_even_odd_mask                    (0x02000000)
#define  ADC_SMARTFIT_ADC_AUTO_R_G_B_MARGIN_adj_even_odd_en_mask                 (0x01000000)
#define  ADC_SMARTFIT_ADC_AUTO_R_G_B_MARGIN_grn_nm_mask                          (0x00FC0000)
#define  ADC_SMARTFIT_ADC_AUTO_R_G_B_MARGIN_vb_th_mask                           (0x00030000)
#define  ADC_SMARTFIT_ADC_AUTO_R_G_B_MARGIN_blu_nm_mask                          (0x0000FC00)
#define  ADC_SMARTFIT_ADC_AUTO_R_G_B_MARGIN_color_sel_mask                       (0x00000300)
#define  ADC_SMARTFIT_ADC_AUTO_R_G_B_MARGIN_diff_th_mask                         (0x000000FF)
#define  ADC_SMARTFIT_ADC_AUTO_R_G_B_MARGIN_red_nm(data)                         (0xFC000000&((data)<<26))
#define  ADC_SMARTFIT_ADC_AUTO_R_G_B_MARGIN_adj_even_odd(data)                   (0x02000000&((data)<<25))
#define  ADC_SMARTFIT_ADC_AUTO_R_G_B_MARGIN_adj_even_odd_en(data)                (0x01000000&((data)<<24))
#define  ADC_SMARTFIT_ADC_AUTO_R_G_B_MARGIN_grn_nm(data)                         (0x00FC0000&((data)<<18))
#define  ADC_SMARTFIT_ADC_AUTO_R_G_B_MARGIN_vb_th(data)                          (0x00030000&((data)<<16))
#define  ADC_SMARTFIT_ADC_AUTO_R_G_B_MARGIN_blu_nm(data)                         (0x0000FC00&((data)<<10))
#define  ADC_SMARTFIT_ADC_AUTO_R_G_B_MARGIN_color_sel(data)                      (0x00000300&((data)<<8))
#define  ADC_SMARTFIT_ADC_AUTO_R_G_B_MARGIN_diff_th(data)                        (0x000000FF&(data))
#define  ADC_SMARTFIT_ADC_AUTO_R_G_B_MARGIN_get_red_nm(data)                     ((0xFC000000&(data))>>26)
#define  ADC_SMARTFIT_ADC_AUTO_R_G_B_MARGIN_get_adj_even_odd(data)               ((0x02000000&(data))>>25)
#define  ADC_SMARTFIT_ADC_AUTO_R_G_B_MARGIN_get_adj_even_odd_en(data)            ((0x01000000&(data))>>24)
#define  ADC_SMARTFIT_ADC_AUTO_R_G_B_MARGIN_get_grn_nm(data)                     ((0x00FC0000&(data))>>18)
#define  ADC_SMARTFIT_ADC_AUTO_R_G_B_MARGIN_get_vb_th(data)                      ((0x00030000&(data))>>16)
#define  ADC_SMARTFIT_ADC_AUTO_R_G_B_MARGIN_get_blu_nm(data)                     ((0x0000FC00&(data))>>10)
#define  ADC_SMARTFIT_ADC_AUTO_R_G_B_MARGIN_get_color_sel(data)                  ((0x00000300&(data))>>8)
#define  ADC_SMARTFIT_ADC_AUTO_R_G_B_MARGIN_get_diff_th(data)                    (0x000000FF&(data))

#define  ADC_SMARTFIT_ADC_AUTO_ADJ                                               0x18020410
#define  ADC_SMARTFIT_ADC_AUTO_ADJ_reg_addr                                      "0xB8020410"
#define  ADC_SMARTFIT_ADC_AUTO_ADJ_reg                                           0xB8020410
#define  ADC_SMARTFIT_ADC_AUTO_ADJ_inst_addr                                     "0x0004"
#define  set_ADC_SMARTFIT_ADC_AUTO_ADJ_reg(data)                                 (*((volatile unsigned int*)ADC_SMARTFIT_ADC_AUTO_ADJ_reg)=data)
#define  get_ADC_SMARTFIT_ADC_AUTO_ADJ_reg                                       (*((volatile unsigned int*)ADC_SMARTFIT_ADC_AUTO_ADJ_reg))
#define  ADC_SMARTFIT_ADC_AUTO_ADJ_m_vgen_en_shift                               (7)
#define  ADC_SMARTFIT_ADC_AUTO_ADJ_diff_pixel_sel_shift                          (6)
#define  ADC_SMARTFIT_ADC_AUTO_ADJ_force_flip__shift                             (5)
#define  ADC_SMARTFIT_ADC_AUTO_ADJ_sum_max_shift                                 (4)
#define  ADC_SMARTFIT_ADC_AUTO_ADJ_pulse_det_en_shift                            (3)
#define  ADC_SMARTFIT_ADC_AUTO_ADJ_autophase_sel_tri_shift                       (2)
#define  ADC_SMARTFIT_ADC_AUTO_ADJ_diff_en_shift                                 (1)
#define  ADC_SMARTFIT_ADC_AUTO_ADJ_now_af_shift                                  (0)
#define  ADC_SMARTFIT_ADC_AUTO_ADJ_m_vgen_en_mask                                (0x00000080)
#define  ADC_SMARTFIT_ADC_AUTO_ADJ_diff_pixel_sel_mask                           (0x00000040)
#define  ADC_SMARTFIT_ADC_AUTO_ADJ_force_flip__mask                              (0x00000020)
#define  ADC_SMARTFIT_ADC_AUTO_ADJ_sum_max_mask                                  (0x00000010)
#define  ADC_SMARTFIT_ADC_AUTO_ADJ_pulse_det_en_mask                             (0x00000008)
#define  ADC_SMARTFIT_ADC_AUTO_ADJ_autophase_sel_tri_mask                        (0x00000004)
#define  ADC_SMARTFIT_ADC_AUTO_ADJ_diff_en_mask                                  (0x00000002)
#define  ADC_SMARTFIT_ADC_AUTO_ADJ_now_af_mask                                   (0x00000001)
#define  ADC_SMARTFIT_ADC_AUTO_ADJ_m_vgen_en(data)                               (0x00000080&((data)<<7))
#define  ADC_SMARTFIT_ADC_AUTO_ADJ_diff_pixel_sel(data)                          (0x00000040&((data)<<6))
#define  ADC_SMARTFIT_ADC_AUTO_ADJ_force_flip_(data)                             (0x00000020&((data)<<5))
#define  ADC_SMARTFIT_ADC_AUTO_ADJ_sum_max(data)                                 (0x00000010&((data)<<4))
#define  ADC_SMARTFIT_ADC_AUTO_ADJ_pulse_det_en(data)                            (0x00000008&((data)<<3))
#define  ADC_SMARTFIT_ADC_AUTO_ADJ_autophase_sel_tri(data)                       (0x00000004&((data)<<2))
#define  ADC_SMARTFIT_ADC_AUTO_ADJ_diff_en(data)                                 (0x00000002&((data)<<1))
#define  ADC_SMARTFIT_ADC_AUTO_ADJ_now_af(data)                                  (0x00000001&(data))
#define  ADC_SMARTFIT_ADC_AUTO_ADJ_get_m_vgen_en(data)                           ((0x00000080&(data))>>7)
#define  ADC_SMARTFIT_ADC_AUTO_ADJ_get_diff_pixel_sel(data)                      ((0x00000040&(data))>>6)
#define  ADC_SMARTFIT_ADC_AUTO_ADJ_get_force_flip_(data)                         ((0x00000020&(data))>>5)
#define  ADC_SMARTFIT_ADC_AUTO_ADJ_get_sum_max(data)                             ((0x00000010&(data))>>4)
#define  ADC_SMARTFIT_ADC_AUTO_ADJ_get_pulse_det_en(data)                        ((0x00000008&(data))>>3)
#define  ADC_SMARTFIT_ADC_AUTO_ADJ_get_autophase_sel_tri(data)                   ((0x00000004&(data))>>2)
#define  ADC_SMARTFIT_ADC_AUTO_ADJ_get_diff_en(data)                             ((0x00000002&(data))>>1)
#define  ADC_SMARTFIT_ADC_AUTO_ADJ_get_now_af(data)                              (0x00000001&(data))

#define  ADC_SMARTFIT_ADC_AUTO_RESULT_VSTA_END                                   0x18020414
#define  ADC_SMARTFIT_ADC_AUTO_RESULT_VSTA_END_reg_addr                          "0xB8020414"
#define  ADC_SMARTFIT_ADC_AUTO_RESULT_VSTA_END_reg                               0xB8020414
#define  ADC_SMARTFIT_ADC_AUTO_RESULT_VSTA_END_inst_addr                         "0x0005"
#define  set_ADC_SMARTFIT_ADC_AUTO_RESULT_VSTA_END_reg(data)                     (*((volatile unsigned int*)ADC_SMARTFIT_ADC_AUTO_RESULT_VSTA_END_reg)=data)
#define  get_ADC_SMARTFIT_ADC_AUTO_RESULT_VSTA_END_reg                           (*((volatile unsigned int*)ADC_SMARTFIT_ADC_AUTO_RESULT_VSTA_END_reg))
#define  ADC_SMARTFIT_ADC_AUTO_RESULT_VSTA_END_vx_sta_shift                      (16)
#define  ADC_SMARTFIT_ADC_AUTO_RESULT_VSTA_END_vx_end_shift                      (0)
#define  ADC_SMARTFIT_ADC_AUTO_RESULT_VSTA_END_vx_sta_mask                       (0x1FFF0000)
#define  ADC_SMARTFIT_ADC_AUTO_RESULT_VSTA_END_vx_end_mask                       (0x00001FFF)
#define  ADC_SMARTFIT_ADC_AUTO_RESULT_VSTA_END_vx_sta(data)                      (0x1FFF0000&((data)<<16))
#define  ADC_SMARTFIT_ADC_AUTO_RESULT_VSTA_END_vx_end(data)                      (0x00001FFF&(data))
#define  ADC_SMARTFIT_ADC_AUTO_RESULT_VSTA_END_get_vx_sta(data)                  ((0x1FFF0000&(data))>>16)
#define  ADC_SMARTFIT_ADC_AUTO_RESULT_VSTA_END_get_vx_end(data)                  (0x00001FFF&(data))

#define  ADC_SMARTFIT_ADC_AUTO_RESULT_HSTA_END                                   0x18020418
#define  ADC_SMARTFIT_ADC_AUTO_RESULT_HSTA_END_reg_addr                          "0xB8020418"
#define  ADC_SMARTFIT_ADC_AUTO_RESULT_HSTA_END_reg                               0xB8020418
#define  ADC_SMARTFIT_ADC_AUTO_RESULT_HSTA_END_inst_addr                         "0x0006"
#define  set_ADC_SMARTFIT_ADC_AUTO_RESULT_HSTA_END_reg(data)                     (*((volatile unsigned int*)ADC_SMARTFIT_ADC_AUTO_RESULT_HSTA_END_reg)=data)
#define  get_ADC_SMARTFIT_ADC_AUTO_RESULT_HSTA_END_reg                           (*((volatile unsigned int*)ADC_SMARTFIT_ADC_AUTO_RESULT_HSTA_END_reg))
#define  ADC_SMARTFIT_ADC_AUTO_RESULT_HSTA_END_hx_sta_shift                      (16)
#define  ADC_SMARTFIT_ADC_AUTO_RESULT_HSTA_END_hx_end_shift                      (0)
#define  ADC_SMARTFIT_ADC_AUTO_RESULT_HSTA_END_hx_sta_mask                       (0x3FFF0000)
#define  ADC_SMARTFIT_ADC_AUTO_RESULT_HSTA_END_hx_end_mask                       (0x00003FFF)
#define  ADC_SMARTFIT_ADC_AUTO_RESULT_HSTA_END_hx_sta(data)                      (0x3FFF0000&((data)<<16))
#define  ADC_SMARTFIT_ADC_AUTO_RESULT_HSTA_END_hx_end(data)                      (0x00003FFF&(data))
#define  ADC_SMARTFIT_ADC_AUTO_RESULT_HSTA_END_get_hx_sta(data)                  ((0x3FFF0000&(data))>>16)
#define  ADC_SMARTFIT_ADC_AUTO_RESULT_HSTA_END_get_hx_end(data)                  (0x00003FFF&(data))

#define  ADC_SMARTFIT_ADC_AUTO_RESULT_PHASE_M                                    0x1802041C
#define  ADC_SMARTFIT_ADC_AUTO_RESULT_PHASE_M_reg_addr                           "0xB802041C"
#define  ADC_SMARTFIT_ADC_AUTO_RESULT_PHASE_M_reg                                0xB802041C
#define  ADC_SMARTFIT_ADC_AUTO_RESULT_PHASE_M_inst_addr                          "0x0007"
#define  set_ADC_SMARTFIT_ADC_AUTO_RESULT_PHASE_M_reg(data)                      (*((volatile unsigned int*)ADC_SMARTFIT_ADC_AUTO_RESULT_PHASE_M_reg)=data)
#define  get_ADC_SMARTFIT_ADC_AUTO_RESULT_PHASE_M_reg                            (*((volatile unsigned int*)ADC_SMARTFIT_ADC_AUTO_RESULT_PHASE_M_reg))
#define  ADC_SMARTFIT_ADC_AUTO_RESULT_PHASE_M_acc_41_32_shift                    (0)
#define  ADC_SMARTFIT_ADC_AUTO_RESULT_PHASE_M_acc_41_32_mask                     (0x000003FF)
#define  ADC_SMARTFIT_ADC_AUTO_RESULT_PHASE_M_acc_41_32(data)                    (0x000003FF&(data))
#define  ADC_SMARTFIT_ADC_AUTO_RESULT_PHASE_M_get_acc_41_32(data)                (0x000003FF&(data))

#define  ADC_SMARTFIT_ADC_AUTO_RESULT_PHASE_L                                    0x18020420
#define  ADC_SMARTFIT_ADC_AUTO_RESULT_PHASE_L_reg_addr                           "0xB8020420"
#define  ADC_SMARTFIT_ADC_AUTO_RESULT_PHASE_L_reg                                0xB8020420
#define  ADC_SMARTFIT_ADC_AUTO_RESULT_PHASE_L_inst_addr                          "0x0008"
#define  set_ADC_SMARTFIT_ADC_AUTO_RESULT_PHASE_L_reg(data)                      (*((volatile unsigned int*)ADC_SMARTFIT_ADC_AUTO_RESULT_PHASE_L_reg)=data)
#define  get_ADC_SMARTFIT_ADC_AUTO_RESULT_PHASE_L_reg                            (*((volatile unsigned int*)ADC_SMARTFIT_ADC_AUTO_RESULT_PHASE_L_reg))
#define  ADC_SMARTFIT_ADC_AUTO_RESULT_PHASE_L_acc31_0_shift                      (0)
#define  ADC_SMARTFIT_ADC_AUTO_RESULT_PHASE_L_acc31_0_mask                       (0xFFFFFFFF)
#define  ADC_SMARTFIT_ADC_AUTO_RESULT_PHASE_L_acc31_0(data)                      (0xFFFFFFFF&(data))
#define  ADC_SMARTFIT_ADC_AUTO_RESULT_PHASE_L_get_acc31_0(data)                  (0xFFFFFFFF&(data))

#define  ADC_SMARTFIT_ADC_AUTO_PHASE_CTRL0                                       0x18020424
#define  ADC_SMARTFIT_ADC_AUTO_PHASE_CTRL0_reg_addr                              "0xB8020424"
#define  ADC_SMARTFIT_ADC_AUTO_PHASE_CTRL0_reg                                   0xB8020424
#define  ADC_SMARTFIT_ADC_AUTO_PHASE_CTRL0_inst_addr                             "0x0009"
#define  set_ADC_SMARTFIT_ADC_AUTO_PHASE_CTRL0_reg(data)                         (*((volatile unsigned int*)ADC_SMARTFIT_ADC_AUTO_PHASE_CTRL0_reg)=data)
#define  get_ADC_SMARTFIT_ADC_AUTO_PHASE_CTRL0_reg                               (*((volatile unsigned int*)ADC_SMARTFIT_ADC_AUTO_PHASE_CTRL0_reg))
#define  ADC_SMARTFIT_ADC_AUTO_PHASE_CTRL0_autophase_en_shift                    (31)
#define  ADC_SMARTFIT_ADC_AUTO_PHASE_CTRL0_new_ap_en_shift                       (30)
#define  ADC_SMARTFIT_ADC_AUTO_PHASE_CTRL0_autophase_step_shift                  (22)
#define  ADC_SMARTFIT_ADC_AUTO_PHASE_CTRL0_init_phase_shift                      (16)
#define  ADC_SMARTFIT_ADC_AUTO_PHASE_CTRL0_autophase_max_step_shift              (8)
#define  ADC_SMARTFIT_ADC_AUTO_PHASE_CTRL0_autophase_flg_shift                   (7)
#define  ADC_SMARTFIT_ADC_AUTO_PHASE_CTRL0_autosod_step_num_shift                (0)
#define  ADC_SMARTFIT_ADC_AUTO_PHASE_CTRL0_autophase_en_mask                     (0x80000000)
#define  ADC_SMARTFIT_ADC_AUTO_PHASE_CTRL0_new_ap_en_mask                        (0x40000000)
#define  ADC_SMARTFIT_ADC_AUTO_PHASE_CTRL0_autophase_step_mask                   (0x01C00000)
#define  ADC_SMARTFIT_ADC_AUTO_PHASE_CTRL0_init_phase_mask                       (0x003F0000)
#define  ADC_SMARTFIT_ADC_AUTO_PHASE_CTRL0_autophase_max_step_mask               (0x00007F00)
#define  ADC_SMARTFIT_ADC_AUTO_PHASE_CTRL0_autophase_flg_mask                    (0x00000080)
#define  ADC_SMARTFIT_ADC_AUTO_PHASE_CTRL0_autosod_step_num_mask                 (0x0000007F)
#define  ADC_SMARTFIT_ADC_AUTO_PHASE_CTRL0_autophase_en(data)                    (0x80000000&((data)<<31))
#define  ADC_SMARTFIT_ADC_AUTO_PHASE_CTRL0_new_ap_en(data)                       (0x40000000&((data)<<30))
#define  ADC_SMARTFIT_ADC_AUTO_PHASE_CTRL0_autophase_step(data)                  (0x01C00000&((data)<<22))
#define  ADC_SMARTFIT_ADC_AUTO_PHASE_CTRL0_init_phase(data)                      (0x003F0000&((data)<<16))
#define  ADC_SMARTFIT_ADC_AUTO_PHASE_CTRL0_autophase_max_step(data)              (0x00007F00&((data)<<8))
#define  ADC_SMARTFIT_ADC_AUTO_PHASE_CTRL0_autophase_flg(data)                   (0x00000080&((data)<<7))
#define  ADC_SMARTFIT_ADC_AUTO_PHASE_CTRL0_autosod_step_num(data)                (0x0000007F&(data))
#define  ADC_SMARTFIT_ADC_AUTO_PHASE_CTRL0_get_autophase_en(data)                ((0x80000000&(data))>>31)
#define  ADC_SMARTFIT_ADC_AUTO_PHASE_CTRL0_get_new_ap_en(data)                   ((0x40000000&(data))>>30)
#define  ADC_SMARTFIT_ADC_AUTO_PHASE_CTRL0_get_autophase_step(data)              ((0x01C00000&(data))>>22)
#define  ADC_SMARTFIT_ADC_AUTO_PHASE_CTRL0_get_init_phase(data)                  ((0x003F0000&(data))>>16)
#define  ADC_SMARTFIT_ADC_AUTO_PHASE_CTRL0_get_autophase_max_step(data)          ((0x00007F00&(data))>>8)
#define  ADC_SMARTFIT_ADC_AUTO_PHASE_CTRL0_get_autophase_flg(data)               ((0x00000080&(data))>>7)
#define  ADC_SMARTFIT_ADC_AUTO_PHASE_CTRL0_get_autosod_step_num(data)            (0x0000007F&(data))

#define  ADC_SMARTFIT_ADC_PLLPHASE_CTRL                                          0x18020428
#define  ADC_SMARTFIT_ADC_PLLPHASE_CTRL_reg_addr                                 "0xB8020428"
#define  ADC_SMARTFIT_ADC_PLLPHASE_CTRL_reg                                      0xB8020428
#define  ADC_SMARTFIT_ADC_PLLPHASE_CTRL_inst_addr                                "0x000A"
#define  set_ADC_SMARTFIT_ADC_PLLPHASE_CTRL_reg(data)                            (*((volatile unsigned int*)ADC_SMARTFIT_ADC_PLLPHASE_CTRL_reg)=data)
#define  get_ADC_SMARTFIT_ADC_PLLPHASE_CTRL_reg                                  (*((volatile unsigned int*)ADC_SMARTFIT_ADC_PLLPHASE_CTRL_reg))
#define  ADC_SMARTFIT_ADC_PLLPHASE_CTRL_pll2_ph_lut_shift                        (22)
#define  ADC_SMARTFIT_ADC_PLLPHASE_CTRL_pll2d2_shift                             (20)
#define  ADC_SMARTFIT_ADC_PLLPHASE_CTRL_pll2_d2x_shift                           (19)
#define  ADC_SMARTFIT_ADC_PLLPHASE_CTRL_pll2_d2y_shift                           (18)
#define  ADC_SMARTFIT_ADC_PLLPHASE_CTRL_pll2x_shift                              (17)
#define  ADC_SMARTFIT_ADC_PLLPHASE_CTRL_pll2y_shift                              (16)
#define  ADC_SMARTFIT_ADC_PLLPHASE_CTRL_pll2_psel_shift                          (8)
#define  ADC_SMARTFIT_ADC_PLLPHASE_CTRL_pll2_ph_lut_index_msb_shift              (6)
#define  ADC_SMARTFIT_ADC_PLLPHASE_CTRL_pll2_ph_lut_index_shift                  (0)
#define  ADC_SMARTFIT_ADC_PLLPHASE_CTRL_pll2_ph_lut_mask                         (0x00400000)
#define  ADC_SMARTFIT_ADC_PLLPHASE_CTRL_pll2d2_mask                              (0x00100000)
#define  ADC_SMARTFIT_ADC_PLLPHASE_CTRL_pll2_d2x_mask                            (0x00080000)
#define  ADC_SMARTFIT_ADC_PLLPHASE_CTRL_pll2_d2y_mask                            (0x00040000)
#define  ADC_SMARTFIT_ADC_PLLPHASE_CTRL_pll2x_mask                               (0x00020000)
#define  ADC_SMARTFIT_ADC_PLLPHASE_CTRL_pll2y_mask                               (0x00010000)
#define  ADC_SMARTFIT_ADC_PLLPHASE_CTRL_pll2_psel_mask                           (0x00001F00)
#define  ADC_SMARTFIT_ADC_PLLPHASE_CTRL_pll2_ph_lut_index_msb_mask               (0x00000040)
#define  ADC_SMARTFIT_ADC_PLLPHASE_CTRL_pll2_ph_lut_index_mask                   (0x0000003F)
#define  ADC_SMARTFIT_ADC_PLLPHASE_CTRL_pll2_ph_lut(data)                        (0x00400000&((data)<<22))
#define  ADC_SMARTFIT_ADC_PLLPHASE_CTRL_pll2d2(data)                             (0x00100000&((data)<<20))
#define  ADC_SMARTFIT_ADC_PLLPHASE_CTRL_pll2_d2x(data)                           (0x00080000&((data)<<19))
#define  ADC_SMARTFIT_ADC_PLLPHASE_CTRL_pll2_d2y(data)                           (0x00040000&((data)<<18))
#define  ADC_SMARTFIT_ADC_PLLPHASE_CTRL_pll2x(data)                              (0x00020000&((data)<<17))
#define  ADC_SMARTFIT_ADC_PLLPHASE_CTRL_pll2y(data)                              (0x00010000&((data)<<16))
#define  ADC_SMARTFIT_ADC_PLLPHASE_CTRL_pll2_psel(data)                          (0x00001F00&((data)<<8))
#define  ADC_SMARTFIT_ADC_PLLPHASE_CTRL_pll2_ph_lut_index_msb(data)              (0x00000040&((data)<<6))
#define  ADC_SMARTFIT_ADC_PLLPHASE_CTRL_pll2_ph_lut_index(data)                  (0x0000003F&(data))
#define  ADC_SMARTFIT_ADC_PLLPHASE_CTRL_get_pll2_ph_lut(data)                    ((0x00400000&(data))>>22)
#define  ADC_SMARTFIT_ADC_PLLPHASE_CTRL_get_pll2d2(data)                         ((0x00100000&(data))>>20)
#define  ADC_SMARTFIT_ADC_PLLPHASE_CTRL_get_pll2_d2x(data)                       ((0x00080000&(data))>>19)
#define  ADC_SMARTFIT_ADC_PLLPHASE_CTRL_get_pll2_d2y(data)                       ((0x00040000&(data))>>18)
#define  ADC_SMARTFIT_ADC_PLLPHASE_CTRL_get_pll2x(data)                          ((0x00020000&(data))>>17)
#define  ADC_SMARTFIT_ADC_PLLPHASE_CTRL_get_pll2y(data)                          ((0x00010000&(data))>>16)
#define  ADC_SMARTFIT_ADC_PLLPHASE_CTRL_get_pll2_psel(data)                      ((0x00001F00&(data))>>8)
#define  ADC_SMARTFIT_ADC_PLLPHASE_CTRL_get_pll2_ph_lut_index_msb(data)          ((0x00000040&(data))>>6)
#define  ADC_SMARTFIT_ADC_PLLPHASE_CTRL_get_pll2_ph_lut_index(data)              (0x0000003F&(data))

#define  ADC_SMARTFIT_ADC_AUTO_RESULT_PHASE_2_M                                  0x1802042C
#define  ADC_SMARTFIT_ADC_AUTO_RESULT_PHASE_2_M_reg_addr                         "0xB802042C"
#define  ADC_SMARTFIT_ADC_AUTO_RESULT_PHASE_2_M_reg                              0xB802042C
#define  ADC_SMARTFIT_ADC_AUTO_RESULT_PHASE_2_M_inst_addr                        "0x000B"
#define  set_ADC_SMARTFIT_ADC_AUTO_RESULT_PHASE_2_M_reg(data)                    (*((volatile unsigned int*)ADC_SMARTFIT_ADC_AUTO_RESULT_PHASE_2_M_reg)=data)
#define  get_ADC_SMARTFIT_ADC_AUTO_RESULT_PHASE_2_M_reg                          (*((volatile unsigned int*)ADC_SMARTFIT_ADC_AUTO_RESULT_PHASE_2_M_reg))
#define  ADC_SMARTFIT_ADC_AUTO_RESULT_PHASE_2_M_max_2nd_ph_shift                 (10)
#define  ADC_SMARTFIT_ADC_AUTO_RESULT_PHASE_2_M_acc_2nd_41_32_shift              (0)
#define  ADC_SMARTFIT_ADC_AUTO_RESULT_PHASE_2_M_max_2nd_ph_mask                  (0x0001FC00)
#define  ADC_SMARTFIT_ADC_AUTO_RESULT_PHASE_2_M_acc_2nd_41_32_mask               (0x000003FF)
#define  ADC_SMARTFIT_ADC_AUTO_RESULT_PHASE_2_M_max_2nd_ph(data)                 (0x0001FC00&((data)<<10))
#define  ADC_SMARTFIT_ADC_AUTO_RESULT_PHASE_2_M_acc_2nd_41_32(data)              (0x000003FF&(data))
#define  ADC_SMARTFIT_ADC_AUTO_RESULT_PHASE_2_M_get_max_2nd_ph(data)             ((0x0001FC00&(data))>>10)
#define  ADC_SMARTFIT_ADC_AUTO_RESULT_PHASE_2_M_get_acc_2nd_41_32(data)          (0x000003FF&(data))

#define  ADC_SMARTFIT_ADC_AUTO_RESULT_PHASE_2_L                                  0x18020430
#define  ADC_SMARTFIT_ADC_AUTO_RESULT_PHASE_2_L_reg_addr                         "0xB8020430"
#define  ADC_SMARTFIT_ADC_AUTO_RESULT_PHASE_2_L_reg                              0xB8020430
#define  ADC_SMARTFIT_ADC_AUTO_RESULT_PHASE_2_L_inst_addr                        "0x000C"
#define  set_ADC_SMARTFIT_ADC_AUTO_RESULT_PHASE_2_L_reg(data)                    (*((volatile unsigned int*)ADC_SMARTFIT_ADC_AUTO_RESULT_PHASE_2_L_reg)=data)
#define  get_ADC_SMARTFIT_ADC_AUTO_RESULT_PHASE_2_L_reg                          (*((volatile unsigned int*)ADC_SMARTFIT_ADC_AUTO_RESULT_PHASE_2_L_reg))
#define  ADC_SMARTFIT_ADC_AUTO_RESULT_PHASE_2_L_acc_2nd_31_0_shift               (0)
#define  ADC_SMARTFIT_ADC_AUTO_RESULT_PHASE_2_L_acc_2nd_31_0_mask                (0xFFFFFFFF)
#define  ADC_SMARTFIT_ADC_AUTO_RESULT_PHASE_2_L_acc_2nd_31_0(data)               (0xFFFFFFFF&(data))
#define  ADC_SMARTFIT_ADC_AUTO_RESULT_PHASE_2_L_get_acc_2nd_31_0(data)           (0xFFFFFFFF&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======ADC_SMARTFIT register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  auto_balance_rgb:2;
        RBus_UInt32  smfit_en_n:1;
        RBus_UInt32  res1:15;
        RBus_UInt32  smfit_vs_delay_sel:1;
        RBus_UInt32  vgip_db_disable:1;
        RBus_UInt32  adj_source:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  odd_sel_en:1;
        RBus_UInt32  odd_sel:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  rgb_in_one_en:1;
        RBus_UInt32  square_en:1;
        RBus_UInt32  sum_pixel_num:1;
        RBus_UInt32  filter_sel:2;
    };
}adc_smartfit_adc_auto_field_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  hb_sta:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  hb_end:14;
    };
}adc_smartfit_adc_auto_h_boundary_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  vb_sta:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  vb_end:13;
    };
}adc_smartfit_adc_auto_v_boundary_RBUS;

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
}adc_smartfit_adc_auto_r_g_b_margin_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  m_vgen_en:1;
        RBus_UInt32  diff_pixel_sel:1;
        RBus_UInt32  force_flip_:1;
        RBus_UInt32  sum_max:1;
        RBus_UInt32  pulse_det_en:1;
        RBus_UInt32  autophase_sel_tri:1;
        RBus_UInt32  diff_en:1;
        RBus_UInt32  now_af:1;
    };
}adc_smartfit_adc_auto_adj_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  vx_sta:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  vx_end:13;
    };
}adc_smartfit_adc_auto_result_vsta_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  hx_sta:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  hx_end:14;
    };
}adc_smartfit_adc_auto_result_hsta_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  acc_41_32:10;
    };
}adc_smartfit_adc_auto_result_phase_m_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  acc31_0:32;
    };
}adc_smartfit_adc_auto_result_phase_l_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  autophase_en:1;
        RBus_UInt32  new_ap_en:1;
        RBus_UInt32  res1:5;
        RBus_UInt32  autophase_step:3;
        RBus_UInt32  init_phase:6;
        RBus_UInt32  res2:1;
        RBus_UInt32  autophase_max_step:7;
        RBus_UInt32  autophase_flg:1;
        RBus_UInt32  autosod_step_num:7;
    };
}adc_smartfit_adc_auto_phase_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  pll2_ph_lut:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  pll2d2:1;
        RBus_UInt32  pll2_d2x:1;
        RBus_UInt32  pll2_d2y:1;
        RBus_UInt32  pll2x:1;
        RBus_UInt32  pll2y:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  pll2_psel:5;
        RBus_UInt32  res4:1;
        RBus_UInt32  pll2_ph_lut_index_msb:1;
        RBus_UInt32  pll2_ph_lut_index:6;
    };
}adc_smartfit_adc_pllphase_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  max_2nd_ph:7;
        RBus_UInt32  acc_2nd_41_32:10;
    };
}adc_smartfit_adc_auto_result_phase_2_m_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  acc_2nd_31_0:32;
    };
}adc_smartfit_adc_auto_result_phase_2_l_RBUS;

#else //apply LITTLE_ENDIAN

//======ADC_SMARTFIT register structure define==========

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
        RBus_UInt32  res2:2;
        RBus_UInt32  adj_source:2;
        RBus_UInt32  vgip_db_disable:1;
        RBus_UInt32  smfit_vs_delay_sel:1;
        RBus_UInt32  res3:15;
        RBus_UInt32  smfit_en_n:1;
        RBus_UInt32  auto_balance_rgb:2;
    };
}adc_smartfit_adc_auto_field_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hb_end:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  hb_sta:14;
        RBus_UInt32  res2:2;
    };
}adc_smartfit_adc_auto_h_boundary_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vb_end:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  vb_sta:13;
        RBus_UInt32  res2:3;
    };
}adc_smartfit_adc_auto_v_boundary_RBUS;

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
}adc_smartfit_adc_auto_r_g_b_margin_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  now_af:1;
        RBus_UInt32  diff_en:1;
        RBus_UInt32  autophase_sel_tri:1;
        RBus_UInt32  pulse_det_en:1;
        RBus_UInt32  sum_max:1;
        RBus_UInt32  force_flip_:1;
        RBus_UInt32  diff_pixel_sel:1;
        RBus_UInt32  m_vgen_en:1;
        RBus_UInt32  res1:24;
    };
}adc_smartfit_adc_auto_adj_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vx_end:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  vx_sta:13;
        RBus_UInt32  res2:3;
    };
}adc_smartfit_adc_auto_result_vsta_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hx_end:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  hx_sta:14;
        RBus_UInt32  res2:2;
    };
}adc_smartfit_adc_auto_result_hsta_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  acc_41_32:10;
        RBus_UInt32  res1:22;
    };
}adc_smartfit_adc_auto_result_phase_m_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  acc31_0:32;
    };
}adc_smartfit_adc_auto_result_phase_l_RBUS;

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
        RBus_UInt32  res2:5;
        RBus_UInt32  new_ap_en:1;
        RBus_UInt32  autophase_en:1;
    };
}adc_smartfit_adc_auto_phase_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pll2_ph_lut_index:6;
        RBus_UInt32  pll2_ph_lut_index_msb:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  pll2_psel:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  pll2y:1;
        RBus_UInt32  pll2x:1;
        RBus_UInt32  pll2_d2y:1;
        RBus_UInt32  pll2_d2x:1;
        RBus_UInt32  pll2d2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  pll2_ph_lut:1;
        RBus_UInt32  res4:9;
    };
}adc_smartfit_adc_pllphase_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  acc_2nd_41_32:10;
        RBus_UInt32  max_2nd_ph:7;
        RBus_UInt32  res1:15;
    };
}adc_smartfit_adc_auto_result_phase_2_m_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  acc_2nd_31_0:32;
    };
}adc_smartfit_adc_auto_result_phase_2_l_RBUS;




#endif 


#endif 
