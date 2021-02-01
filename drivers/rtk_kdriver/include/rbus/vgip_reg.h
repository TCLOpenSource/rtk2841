/**
* @file MacArthur5-DesignSpec-I-Domain_VGIP
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_VGIP_REG_H_
#define _RBUS_VGIP_REG_H_

#include "rbus_types.h"



//  VGIP Register Address
#define  VGIP_Smooth_tog_ctrl                                                    0x18022200
#define  VGIP_Smooth_tog_ctrl_reg_addr                                           "0xB8022200"
#define  VGIP_Smooth_tog_ctrl_reg                                                0xB8022200
#define  VGIP_Smooth_tog_ctrl_inst_addr                                          "0x0000"
#define  set_VGIP_Smooth_tog_ctrl_reg(data)                                      (*((volatile unsigned int*)VGIP_Smooth_tog_ctrl_reg)=data)
#define  get_VGIP_Smooth_tog_ctrl_reg                                            (*((volatile unsigned int*)VGIP_Smooth_tog_ctrl_reg))
#define  VGIP_Smooth_tog_ctrl_ip_switch_no_eco_shift                             (12)
#define  VGIP_Smooth_tog_ctrl_main_imd_sm_to_gdma_shift                          (11)
#define  VGIP_Smooth_tog_ctrl_main_iv2dv_sm_apply_auto_sel_shift                 (4)
#define  VGIP_Smooth_tog_ctrl_main_imd_smooth_toggle_clk_time2switch_en_shift    (3)
#define  VGIP_Smooth_tog_ctrl_main_imd_smooth_toggle_style_shift                 (1)
#define  VGIP_Smooth_tog_ctrl_main_imd_smooth_toggle_apply_shift                 (0)
#define  VGIP_Smooth_tog_ctrl_ip_switch_no_eco_mask                              (0x00001000)
#define  VGIP_Smooth_tog_ctrl_main_imd_sm_to_gdma_mask                           (0x00000800)
#define  VGIP_Smooth_tog_ctrl_main_iv2dv_sm_apply_auto_sel_mask                  (0x00000010)
#define  VGIP_Smooth_tog_ctrl_main_imd_smooth_toggle_clk_time2switch_en_mask     (0x00000008)
#define  VGIP_Smooth_tog_ctrl_main_imd_smooth_toggle_style_mask                  (0x00000006)
#define  VGIP_Smooth_tog_ctrl_main_imd_smooth_toggle_apply_mask                  (0x00000001)
#define  VGIP_Smooth_tog_ctrl_ip_switch_no_eco(data)                             (0x00001000&((data)<<12))
#define  VGIP_Smooth_tog_ctrl_main_imd_sm_to_gdma(data)                          (0x00000800&((data)<<11))
#define  VGIP_Smooth_tog_ctrl_main_iv2dv_sm_apply_auto_sel(data)                 (0x00000010&((data)<<4))
#define  VGIP_Smooth_tog_ctrl_main_imd_smooth_toggle_clk_time2switch_en(data)    (0x00000008&((data)<<3))
#define  VGIP_Smooth_tog_ctrl_main_imd_smooth_toggle_style(data)                 (0x00000006&((data)<<1))
#define  VGIP_Smooth_tog_ctrl_main_imd_smooth_toggle_apply(data)                 (0x00000001&(data))
#define  VGIP_Smooth_tog_ctrl_get_ip_switch_no_eco(data)                         ((0x00001000&(data))>>12)
#define  VGIP_Smooth_tog_ctrl_get_main_imd_sm_to_gdma(data)                      ((0x00000800&(data))>>11)
#define  VGIP_Smooth_tog_ctrl_get_main_iv2dv_sm_apply_auto_sel(data)             ((0x00000010&(data))>>4)
#define  VGIP_Smooth_tog_ctrl_get_main_imd_smooth_toggle_clk_time2switch_en(data) ((0x00000008&(data))>>3)
#define  VGIP_Smooth_tog_ctrl_get_main_imd_smooth_toggle_style(data)             ((0x00000006&(data))>>1)
#define  VGIP_Smooth_tog_ctrl_get_main_imd_smooth_toggle_apply(data)             (0x00000001&(data))

#define  VGIP_Smooth_tog_status                                                  0x18022204
#define  VGIP_Smooth_tog_status_reg_addr                                         "0xB8022204"
#define  VGIP_Smooth_tog_status_reg                                              0xB8022204
#define  VGIP_Smooth_tog_status_inst_addr                                        "0x0001"
#define  set_VGIP_Smooth_tog_status_reg(data)                                    (*((volatile unsigned int*)VGIP_Smooth_tog_status_reg)=data)
#define  get_VGIP_Smooth_tog_status_reg                                          (*((volatile unsigned int*)VGIP_Smooth_tog_status_reg))
#define  VGIP_Smooth_tog_status_cp_rtnr_progressive_clk_mux_shift                (31)
#define  VGIP_Smooth_tog_status_vo1_reg_is_db_shift                              (4)
#define  VGIP_Smooth_tog_status_main_vgip_reg_is_db_shift                        (3)
#define  VGIP_Smooth_tog_status_di_reg_is_db_shift                               (2)
#define  VGIP_Smooth_tog_status_i_edge_smooth_reg_is_db_shift                    (1)
#define  VGIP_Smooth_tog_status_main_uzd_reg_is_db_shift                         (0)
#define  VGIP_Smooth_tog_status_cp_rtnr_progressive_clk_mux_mask                 (0x80000000)
#define  VGIP_Smooth_tog_status_vo1_reg_is_db_mask                               (0x00000010)
#define  VGIP_Smooth_tog_status_main_vgip_reg_is_db_mask                         (0x00000008)
#define  VGIP_Smooth_tog_status_di_reg_is_db_mask                                (0x00000004)
#define  VGIP_Smooth_tog_status_i_edge_smooth_reg_is_db_mask                     (0x00000002)
#define  VGIP_Smooth_tog_status_main_uzd_reg_is_db_mask                          (0x00000001)
#define  VGIP_Smooth_tog_status_cp_rtnr_progressive_clk_mux(data)                (0x80000000&((data)<<31))
#define  VGIP_Smooth_tog_status_vo1_reg_is_db(data)                              (0x00000010&((data)<<4))
#define  VGIP_Smooth_tog_status_main_vgip_reg_is_db(data)                        (0x00000008&((data)<<3))
#define  VGIP_Smooth_tog_status_di_reg_is_db(data)                               (0x00000004&((data)<<2))
#define  VGIP_Smooth_tog_status_i_edge_smooth_reg_is_db(data)                    (0x00000002&((data)<<1))
#define  VGIP_Smooth_tog_status_main_uzd_reg_is_db(data)                         (0x00000001&(data))
#define  VGIP_Smooth_tog_status_get_cp_rtnr_progressive_clk_mux(data)            ((0x80000000&(data))>>31)
#define  VGIP_Smooth_tog_status_get_vo1_reg_is_db(data)                          ((0x00000010&(data))>>4)
#define  VGIP_Smooth_tog_status_get_main_vgip_reg_is_db(data)                    ((0x00000008&(data))>>3)
#define  VGIP_Smooth_tog_status_get_di_reg_is_db(data)                           ((0x00000004&(data))>>2)
#define  VGIP_Smooth_tog_status_get_i_edge_smooth_reg_is_db(data)                ((0x00000002&(data))>>1)
#define  VGIP_Smooth_tog_status_get_main_uzd_reg_is_db(data)                     (0x00000001&(data))

#define  VGIP_V8_CTRL                                                            0x18022208
#define  VGIP_V8_CTRL_reg_addr                                                   "0xB8022208"
#define  VGIP_V8_CTRL_reg                                                        0xB8022208
#define  VGIP_V8_CTRL_inst_addr                                                  "0x0002"
#define  set_VGIP_V8_CTRL_reg(data)                                              (*((volatile unsigned int*)VGIP_V8_CTRL_reg)=data)
#define  get_VGIP_V8_CTRL_reg                                                    (*((volatile unsigned int*)VGIP_V8_CTRL_reg))
#define  VGIP_V8_CTRL_v8_dummy_shift                                             (8)
#define  VGIP_V8_CTRL_ch1_select_duplicate_lsb_shift                             (0)
#define  VGIP_V8_CTRL_v8_dummy_mask                                              (0x0000FF00)
#define  VGIP_V8_CTRL_ch1_select_duplicate_lsb_mask                              (0x00000001)
#define  VGIP_V8_CTRL_v8_dummy(data)                                             (0x0000FF00&((data)<<8))
#define  VGIP_V8_CTRL_ch1_select_duplicate_lsb(data)                             (0x00000001&(data))
#define  VGIP_V8_CTRL_get_v8_dummy(data)                                         ((0x0000FF00&(data))>>8)
#define  VGIP_V8_CTRL_get_ch1_select_duplicate_lsb(data)                         (0x00000001&(data))

#define  VGIP_VGIP_GLOBAL_CTRL                                                   0x1802220C
#define  VGIP_VGIP_GLOBAL_CTRL_reg_addr                                          "0xB802220C"
#define  VGIP_VGIP_GLOBAL_CTRL_reg                                               0xB802220C
#define  VGIP_VGIP_GLOBAL_CTRL_inst_addr                                         "0x0003"
#define  set_VGIP_VGIP_GLOBAL_CTRL_reg(data)                                     (*((volatile unsigned int*)VGIP_VGIP_GLOBAL_CTRL_reg)=data)
#define  get_VGIP_VGIP_GLOBAL_CTRL_reg                                           (*((volatile unsigned int*)VGIP_VGIP_GLOBAL_CTRL_reg))
#define  VGIP_VGIP_GLOBAL_CTRL_auto_l_flag_delay_en_shift                        (31)
#define  VGIP_VGIP_GLOBAL_CTRL_vs_rise_sample_delay_sel_shift                    (29)
#define  VGIP_VGIP_GLOBAL_CTRL_auto_l_flag_delay_num_shift                       (16)
#define  VGIP_VGIP_GLOBAL_CTRL_l_flag_delay_en_shift                             (15)
#define  VGIP_VGIP_GLOBAL_CTRL_l_flag_field_sample_delay_shift                   (13)
#define  VGIP_VGIP_GLOBAL_CTRL_l_flag_delay_num_shift                            (0)
#define  VGIP_VGIP_GLOBAL_CTRL_auto_l_flag_delay_en_mask                         (0x80000000)
#define  VGIP_VGIP_GLOBAL_CTRL_vs_rise_sample_delay_sel_mask                     (0x20000000)
#define  VGIP_VGIP_GLOBAL_CTRL_auto_l_flag_delay_num_mask                        (0x1FFF0000)
#define  VGIP_VGIP_GLOBAL_CTRL_l_flag_delay_en_mask                              (0x00008000)
#define  VGIP_VGIP_GLOBAL_CTRL_l_flag_field_sample_delay_mask                    (0x00006000)
#define  VGIP_VGIP_GLOBAL_CTRL_l_flag_delay_num_mask                             (0x00001FFF)
#define  VGIP_VGIP_GLOBAL_CTRL_auto_l_flag_delay_en(data)                        (0x80000000&((data)<<31))
#define  VGIP_VGIP_GLOBAL_CTRL_vs_rise_sample_delay_sel(data)                    (0x20000000&((data)<<29))
#define  VGIP_VGIP_GLOBAL_CTRL_auto_l_flag_delay_num(data)                       (0x1FFF0000&((data)<<16))
#define  VGIP_VGIP_GLOBAL_CTRL_l_flag_delay_en(data)                             (0x00008000&((data)<<15))
#define  VGIP_VGIP_GLOBAL_CTRL_l_flag_field_sample_delay(data)                   (0x00006000&((data)<<13))
#define  VGIP_VGIP_GLOBAL_CTRL_l_flag_delay_num(data)                            (0x00001FFF&(data))
#define  VGIP_VGIP_GLOBAL_CTRL_get_auto_l_flag_delay_en(data)                    ((0x80000000&(data))>>31)
#define  VGIP_VGIP_GLOBAL_CTRL_get_vs_rise_sample_delay_sel(data)                ((0x20000000&(data))>>29)
#define  VGIP_VGIP_GLOBAL_CTRL_get_auto_l_flag_delay_num(data)                   ((0x1FFF0000&(data))>>16)
#define  VGIP_VGIP_GLOBAL_CTRL_get_l_flag_delay_en(data)                         ((0x00008000&(data))>>15)
#define  VGIP_VGIP_GLOBAL_CTRL_get_l_flag_field_sample_delay(data)               ((0x00006000&(data))>>13)
#define  VGIP_VGIP_GLOBAL_CTRL_get_l_flag_delay_num(data)                        (0x00001FFF&(data))

#define  VGIP_VGIP_CHN1_CTRL                                                     0x18022210
#define  VGIP_VGIP_CHN1_CTRL_reg_addr                                            "0xB8022210"
#define  VGIP_VGIP_CHN1_CTRL_reg                                                 0xB8022210
#define  VGIP_VGIP_CHN1_CTRL_inst_addr                                           "0x0004"
#define  set_VGIP_VGIP_CHN1_CTRL_reg(data)                                       (*((volatile unsigned int*)VGIP_VGIP_CHN1_CTRL_reg)=data)
#define  get_VGIP_VGIP_CHN1_CTRL_reg                                             (*((volatile unsigned int*)VGIP_VGIP_CHN1_CTRL_reg))
#define  VGIP_VGIP_CHN1_CTRL_ch1_ivrun_shift                                     (31)
#define  VGIP_VGIP_CHN1_CTRL_ch1_in_sel_shift                                    (28)
#define  VGIP_VGIP_CHN1_CTRL_ch1_random_en_shift                                 (27)
#define  VGIP_VGIP_CHN1_CTRL_ch1_fdrop_en_shift                                  (26)
#define  VGIP_VGIP_CHN1_CTRL_ch1_vact_end_ie_shift                               (25)
#define  VGIP_VGIP_CHN1_CTRL_ch1_vact_start_ie_shift                             (24)
#define  VGIP_VGIP_CHN1_CTRL_ch1_field_hs_inv_shift                              (23)
#define  VGIP_VGIP_CHN1_CTRL_ch1_field_vd_inv_shift                              (22)
#define  VGIP_VGIP_CHN1_CTRL_ch1_field_vd_en_shift                               (21)
#define  VGIP_VGIP_CHN1_CTRL_ch1_3dleft_inv_shift                                (20)
#define  VGIP_VGIP_CHN1_CTRL_ch1_3dleft_sync_edge_shift                          (19)
#define  VGIP_VGIP_CHN1_CTRL_ch1_field_inv_shift                                 (18)
#define  VGIP_VGIP_CHN1_CTRL_ch1_field_sync_edge_shift                           (17)
#define  VGIP_VGIP_CHN1_CTRL_ch1_field_det_en_shift                              (16)
#define  VGIP_VGIP_CHN1_CTRL_ch1_hpact_is_hact_shift                             (15)
#define  VGIP_VGIP_CHN1_CTRL_ch1_fcap_str_odd_shift                              (14)
#define  VGIP_VGIP_CHN1_CTRL_ch1_mask_den_inv_shift                              (13)
#define  VGIP_VGIP_CHN1_CTRL_ch1_mask_den_1l_shift                               (12)
#define  VGIP_VGIP_CHN1_CTRL_ch1_3d_mode_en_shift                                (11)
#define  VGIP_VGIP_CHN1_CTRL_ch1_safe_field_inv_shift                            (10)
#define  VGIP_VGIP_CHN1_CTRL_ch1_force_tog_shift                                 (9)
#define  VGIP_VGIP_CHN1_CTRL_ch1_safe_mode_shift                                 (8)
#define  VGIP_VGIP_CHN1_CTRL_ch1_3d_right_act_en_shift                           (7)
#define  VGIP_VGIP_CHN1_CTRL_ch1_hs_syncedge_shift                               (6)
#define  VGIP_VGIP_CHN1_CTRL_ch1_vs_syncedge_shift                               (5)
#define  VGIP_VGIP_CHN1_CTRL_ch1_vs_by_hs_en_n_shift                             (4)
#define  VGIP_VGIP_CHN1_CTRL_ch1_vs_inv_shift                                    (3)
#define  VGIP_VGIP_CHN1_CTRL_ch1_hs_inv_shift                                    (2)
#define  VGIP_VGIP_CHN1_CTRL_ch1_digital_mode_shift                              (1)
#define  VGIP_VGIP_CHN1_CTRL_ch1_in_clk_en_shift                                 (0)
#define  VGIP_VGIP_CHN1_CTRL_ch1_ivrun_mask                                      (0x80000000)
#define  VGIP_VGIP_CHN1_CTRL_ch1_in_sel_mask                                     (0x70000000)
#define  VGIP_VGIP_CHN1_CTRL_ch1_random_en_mask                                  (0x08000000)
#define  VGIP_VGIP_CHN1_CTRL_ch1_fdrop_en_mask                                   (0x04000000)
#define  VGIP_VGIP_CHN1_CTRL_ch1_vact_end_ie_mask                                (0x02000000)
#define  VGIP_VGIP_CHN1_CTRL_ch1_vact_start_ie_mask                              (0x01000000)
#define  VGIP_VGIP_CHN1_CTRL_ch1_field_hs_inv_mask                               (0x00800000)
#define  VGIP_VGIP_CHN1_CTRL_ch1_field_vd_inv_mask                               (0x00400000)
#define  VGIP_VGIP_CHN1_CTRL_ch1_field_vd_en_mask                                (0x00200000)
#define  VGIP_VGIP_CHN1_CTRL_ch1_3dleft_inv_mask                                 (0x00100000)
#define  VGIP_VGIP_CHN1_CTRL_ch1_3dleft_sync_edge_mask                           (0x00080000)
#define  VGIP_VGIP_CHN1_CTRL_ch1_field_inv_mask                                  (0x00040000)
#define  VGIP_VGIP_CHN1_CTRL_ch1_field_sync_edge_mask                            (0x00020000)
#define  VGIP_VGIP_CHN1_CTRL_ch1_field_det_en_mask                               (0x00010000)
#define  VGIP_VGIP_CHN1_CTRL_ch1_hpact_is_hact_mask                              (0x00008000)
#define  VGIP_VGIP_CHN1_CTRL_ch1_fcap_str_odd_mask                               (0x00004000)
#define  VGIP_VGIP_CHN1_CTRL_ch1_mask_den_inv_mask                               (0x00002000)
#define  VGIP_VGIP_CHN1_CTRL_ch1_mask_den_1l_mask                                (0x00001000)
#define  VGIP_VGIP_CHN1_CTRL_ch1_3d_mode_en_mask                                 (0x00000800)
#define  VGIP_VGIP_CHN1_CTRL_ch1_safe_field_inv_mask                             (0x00000400)
#define  VGIP_VGIP_CHN1_CTRL_ch1_force_tog_mask                                  (0x00000200)
#define  VGIP_VGIP_CHN1_CTRL_ch1_safe_mode_mask                                  (0x00000100)
#define  VGIP_VGIP_CHN1_CTRL_ch1_3d_right_act_en_mask                            (0x00000080)
#define  VGIP_VGIP_CHN1_CTRL_ch1_hs_syncedge_mask                                (0x00000040)
#define  VGIP_VGIP_CHN1_CTRL_ch1_vs_syncedge_mask                                (0x00000020)
#define  VGIP_VGIP_CHN1_CTRL_ch1_vs_by_hs_en_n_mask                              (0x00000010)
#define  VGIP_VGIP_CHN1_CTRL_ch1_vs_inv_mask                                     (0x00000008)
#define  VGIP_VGIP_CHN1_CTRL_ch1_hs_inv_mask                                     (0x00000004)
#define  VGIP_VGIP_CHN1_CTRL_ch1_digital_mode_mask                               (0x00000002)
#define  VGIP_VGIP_CHN1_CTRL_ch1_in_clk_en_mask                                  (0x00000001)
#define  VGIP_VGIP_CHN1_CTRL_ch1_ivrun(data)                                     (0x80000000&((data)<<31))
#define  VGIP_VGIP_CHN1_CTRL_ch1_in_sel(data)                                    (0x70000000&((data)<<28))
#define  VGIP_VGIP_CHN1_CTRL_ch1_random_en(data)                                 (0x08000000&((data)<<27))
#define  VGIP_VGIP_CHN1_CTRL_ch1_fdrop_en(data)                                  (0x04000000&((data)<<26))
#define  VGIP_VGIP_CHN1_CTRL_ch1_vact_end_ie(data)                               (0x02000000&((data)<<25))
#define  VGIP_VGIP_CHN1_CTRL_ch1_vact_start_ie(data)                             (0x01000000&((data)<<24))
#define  VGIP_VGIP_CHN1_CTRL_ch1_field_hs_inv(data)                              (0x00800000&((data)<<23))
#define  VGIP_VGIP_CHN1_CTRL_ch1_field_vd_inv(data)                              (0x00400000&((data)<<22))
#define  VGIP_VGIP_CHN1_CTRL_ch1_field_vd_en(data)                               (0x00200000&((data)<<21))
#define  VGIP_VGIP_CHN1_CTRL_ch1_3dleft_inv(data)                                (0x00100000&((data)<<20))
#define  VGIP_VGIP_CHN1_CTRL_ch1_3dleft_sync_edge(data)                          (0x00080000&((data)<<19))
#define  VGIP_VGIP_CHN1_CTRL_ch1_field_inv(data)                                 (0x00040000&((data)<<18))
#define  VGIP_VGIP_CHN1_CTRL_ch1_field_sync_edge(data)                           (0x00020000&((data)<<17))
#define  VGIP_VGIP_CHN1_CTRL_ch1_field_det_en(data)                              (0x00010000&((data)<<16))
#define  VGIP_VGIP_CHN1_CTRL_ch1_hpact_is_hact(data)                             (0x00008000&((data)<<15))
#define  VGIP_VGIP_CHN1_CTRL_ch1_fcap_str_odd(data)                              (0x00004000&((data)<<14))
#define  VGIP_VGIP_CHN1_CTRL_ch1_mask_den_inv(data)                              (0x00002000&((data)<<13))
#define  VGIP_VGIP_CHN1_CTRL_ch1_mask_den_1l(data)                               (0x00001000&((data)<<12))
#define  VGIP_VGIP_CHN1_CTRL_ch1_3d_mode_en(data)                                (0x00000800&((data)<<11))
#define  VGIP_VGIP_CHN1_CTRL_ch1_safe_field_inv(data)                            (0x00000400&((data)<<10))
#define  VGIP_VGIP_CHN1_CTRL_ch1_force_tog(data)                                 (0x00000200&((data)<<9))
#define  VGIP_VGIP_CHN1_CTRL_ch1_safe_mode(data)                                 (0x00000100&((data)<<8))
#define  VGIP_VGIP_CHN1_CTRL_ch1_3d_right_act_en(data)                           (0x00000080&((data)<<7))
#define  VGIP_VGIP_CHN1_CTRL_ch1_hs_syncedge(data)                               (0x00000040&((data)<<6))
#define  VGIP_VGIP_CHN1_CTRL_ch1_vs_syncedge(data)                               (0x00000020&((data)<<5))
#define  VGIP_VGIP_CHN1_CTRL_ch1_vs_by_hs_en_n(data)                             (0x00000010&((data)<<4))
#define  VGIP_VGIP_CHN1_CTRL_ch1_vs_inv(data)                                    (0x00000008&((data)<<3))
#define  VGIP_VGIP_CHN1_CTRL_ch1_hs_inv(data)                                    (0x00000004&((data)<<2))
#define  VGIP_VGIP_CHN1_CTRL_ch1_digital_mode(data)                              (0x00000002&((data)<<1))
#define  VGIP_VGIP_CHN1_CTRL_ch1_in_clk_en(data)                                 (0x00000001&(data))
#define  VGIP_VGIP_CHN1_CTRL_get_ch1_ivrun(data)                                 ((0x80000000&(data))>>31)
#define  VGIP_VGIP_CHN1_CTRL_get_ch1_in_sel(data)                                ((0x70000000&(data))>>28)
#define  VGIP_VGIP_CHN1_CTRL_get_ch1_random_en(data)                             ((0x08000000&(data))>>27)
#define  VGIP_VGIP_CHN1_CTRL_get_ch1_fdrop_en(data)                              ((0x04000000&(data))>>26)
#define  VGIP_VGIP_CHN1_CTRL_get_ch1_vact_end_ie(data)                           ((0x02000000&(data))>>25)
#define  VGIP_VGIP_CHN1_CTRL_get_ch1_vact_start_ie(data)                         ((0x01000000&(data))>>24)
#define  VGIP_VGIP_CHN1_CTRL_get_ch1_field_hs_inv(data)                          ((0x00800000&(data))>>23)
#define  VGIP_VGIP_CHN1_CTRL_get_ch1_field_vd_inv(data)                          ((0x00400000&(data))>>22)
#define  VGIP_VGIP_CHN1_CTRL_get_ch1_field_vd_en(data)                           ((0x00200000&(data))>>21)
#define  VGIP_VGIP_CHN1_CTRL_get_ch1_3dleft_inv(data)                            ((0x00100000&(data))>>20)
#define  VGIP_VGIP_CHN1_CTRL_get_ch1_3dleft_sync_edge(data)                      ((0x00080000&(data))>>19)
#define  VGIP_VGIP_CHN1_CTRL_get_ch1_field_inv(data)                             ((0x00040000&(data))>>18)
#define  VGIP_VGIP_CHN1_CTRL_get_ch1_field_sync_edge(data)                       ((0x00020000&(data))>>17)
#define  VGIP_VGIP_CHN1_CTRL_get_ch1_field_det_en(data)                          ((0x00010000&(data))>>16)
#define  VGIP_VGIP_CHN1_CTRL_get_ch1_hpact_is_hact(data)                         ((0x00008000&(data))>>15)
#define  VGIP_VGIP_CHN1_CTRL_get_ch1_fcap_str_odd(data)                          ((0x00004000&(data))>>14)
#define  VGIP_VGIP_CHN1_CTRL_get_ch1_mask_den_inv(data)                          ((0x00002000&(data))>>13)
#define  VGIP_VGIP_CHN1_CTRL_get_ch1_mask_den_1l(data)                           ((0x00001000&(data))>>12)
#define  VGIP_VGIP_CHN1_CTRL_get_ch1_3d_mode_en(data)                            ((0x00000800&(data))>>11)
#define  VGIP_VGIP_CHN1_CTRL_get_ch1_safe_field_inv(data)                        ((0x00000400&(data))>>10)
#define  VGIP_VGIP_CHN1_CTRL_get_ch1_force_tog(data)                             ((0x00000200&(data))>>9)
#define  VGIP_VGIP_CHN1_CTRL_get_ch1_safe_mode(data)                             ((0x00000100&(data))>>8)
#define  VGIP_VGIP_CHN1_CTRL_get_ch1_3d_right_act_en(data)                       ((0x00000080&(data))>>7)
#define  VGIP_VGIP_CHN1_CTRL_get_ch1_hs_syncedge(data)                           ((0x00000040&(data))>>6)
#define  VGIP_VGIP_CHN1_CTRL_get_ch1_vs_syncedge(data)                           ((0x00000020&(data))>>5)
#define  VGIP_VGIP_CHN1_CTRL_get_ch1_vs_by_hs_en_n(data)                         ((0x00000010&(data))>>4)
#define  VGIP_VGIP_CHN1_CTRL_get_ch1_vs_inv(data)                                ((0x00000008&(data))>>3)
#define  VGIP_VGIP_CHN1_CTRL_get_ch1_hs_inv(data)                                ((0x00000004&(data))>>2)
#define  VGIP_VGIP_CHN1_CTRL_get_ch1_digital_mode(data)                          ((0x00000002&(data))>>1)
#define  VGIP_VGIP_CHN1_CTRL_get_ch1_in_clk_en(data)                             (0x00000001&(data))

#define  VGIP_VGIP_CHN1_STATUS                                                   0x18022214
#define  VGIP_VGIP_CHN1_STATUS_reg_addr                                          "0xB8022214"
#define  VGIP_VGIP_CHN1_STATUS_reg                                               0xB8022214
#define  VGIP_VGIP_CHN1_STATUS_inst_addr                                         "0x0005"
#define  set_VGIP_VGIP_CHN1_STATUS_reg(data)                                     (*((volatile unsigned int*)VGIP_VGIP_CHN1_STATUS_reg)=data)
#define  get_VGIP_VGIP_CHN1_STATUS_reg                                           (*((volatile unsigned int*)VGIP_VGIP_CHN1_STATUS_reg))
#define  VGIP_VGIP_CHN1_STATUS_ch1_vs_end_shift                                  (27)
#define  VGIP_VGIP_CHN1_STATUS_ch1_vs_start_shift                                (26)
#define  VGIP_VGIP_CHN1_STATUS_ch1_vact_end_shift                                (25)
#define  VGIP_VGIP_CHN1_STATUS_ch1_vact_start_shift                              (24)
#define  VGIP_VGIP_CHN1_STATUS_dummy_23_17_shift                                 (17)
#define  VGIP_VGIP_CHN1_STATUS_ch1_vlc_status_shift                              (16)
#define  VGIP_VGIP_CHN1_STATUS_ch1_rl_err_shift                                  (15)
#define  VGIP_VGIP_CHN1_STATUS_ch1_vs_err_shift                                  (14)
#define  VGIP_VGIP_CHN1_STATUS_ch1_hs_err_shift                                  (13)
#define  VGIP_VGIP_CHN1_STATUS_ch1_field_err_shift                               (12)
#define  VGIP_VGIP_CHN1_STATUS_ch1_rl_tog_shift                                  (11)
#define  VGIP_VGIP_CHN1_STATUS_ch1_l_flag_pol_shift                              (10)
#define  VGIP_VGIP_CHN1_STATUS_ch1_vs_tog_shift                                  (9)
#define  VGIP_VGIP_CHN1_STATUS_ch1_hs_tog_shift                                  (8)
#define  VGIP_VGIP_CHN1_STATUS_ch1_field_pol_shift                               (7)
#define  VGIP_VGIP_CHN1_STATUS_ch1_field_tog_shift                               (6)
#define  VGIP_VGIP_CHN1_STATUS_ch1_field_vs_lsb_shift                            (4)
#define  VGIP_VGIP_CHN1_STATUS_ch1_more_1line_field_shift                        (3)
#define  VGIP_VGIP_CHN1_STATUS_ch1_bounce_status_2_shift                         (2)
#define  VGIP_VGIP_CHN1_STATUS_ch1_bounce_status_1_shift                         (1)
#define  VGIP_VGIP_CHN1_STATUS_ch1_bounce_status_0_shift                         (0)
#define  VGIP_VGIP_CHN1_STATUS_ch1_vs_end_mask                                   (0x08000000)
#define  VGIP_VGIP_CHN1_STATUS_ch1_vs_start_mask                                 (0x04000000)
#define  VGIP_VGIP_CHN1_STATUS_ch1_vact_end_mask                                 (0x02000000)
#define  VGIP_VGIP_CHN1_STATUS_ch1_vact_start_mask                               (0x01000000)
#define  VGIP_VGIP_CHN1_STATUS_dummy_23_17_mask                                  (0x00FE0000)
#define  VGIP_VGIP_CHN1_STATUS_ch1_vlc_status_mask                               (0x00010000)
#define  VGIP_VGIP_CHN1_STATUS_ch1_rl_err_mask                                   (0x00008000)
#define  VGIP_VGIP_CHN1_STATUS_ch1_vs_err_mask                                   (0x00004000)
#define  VGIP_VGIP_CHN1_STATUS_ch1_hs_err_mask                                   (0x00002000)
#define  VGIP_VGIP_CHN1_STATUS_ch1_field_err_mask                                (0x00001000)
#define  VGIP_VGIP_CHN1_STATUS_ch1_rl_tog_mask                                   (0x00000800)
#define  VGIP_VGIP_CHN1_STATUS_ch1_l_flag_pol_mask                               (0x00000400)
#define  VGIP_VGIP_CHN1_STATUS_ch1_vs_tog_mask                                   (0x00000200)
#define  VGIP_VGIP_CHN1_STATUS_ch1_hs_tog_mask                                   (0x00000100)
#define  VGIP_VGIP_CHN1_STATUS_ch1_field_pol_mask                                (0x00000080)
#define  VGIP_VGIP_CHN1_STATUS_ch1_field_tog_mask                                (0x00000040)
#define  VGIP_VGIP_CHN1_STATUS_ch1_field_vs_lsb_mask                             (0x00000030)
#define  VGIP_VGIP_CHN1_STATUS_ch1_more_1line_field_mask                         (0x00000008)
#define  VGIP_VGIP_CHN1_STATUS_ch1_bounce_status_2_mask                          (0x00000004)
#define  VGIP_VGIP_CHN1_STATUS_ch1_bounce_status_1_mask                          (0x00000002)
#define  VGIP_VGIP_CHN1_STATUS_ch1_bounce_status_0_mask                          (0x00000001)
#define  VGIP_VGIP_CHN1_STATUS_ch1_vs_end(data)                                  (0x08000000&((data)<<27))
#define  VGIP_VGIP_CHN1_STATUS_ch1_vs_start(data)                                (0x04000000&((data)<<26))
#define  VGIP_VGIP_CHN1_STATUS_ch1_vact_end(data)                                (0x02000000&((data)<<25))
#define  VGIP_VGIP_CHN1_STATUS_ch1_vact_start(data)                              (0x01000000&((data)<<24))
#define  VGIP_VGIP_CHN1_STATUS_dummy_23_17(data)                                 (0x00FE0000&((data)<<17))
#define  VGIP_VGIP_CHN1_STATUS_ch1_vlc_status(data)                              (0x00010000&((data)<<16))
#define  VGIP_VGIP_CHN1_STATUS_ch1_rl_err(data)                                  (0x00008000&((data)<<15))
#define  VGIP_VGIP_CHN1_STATUS_ch1_vs_err(data)                                  (0x00004000&((data)<<14))
#define  VGIP_VGIP_CHN1_STATUS_ch1_hs_err(data)                                  (0x00002000&((data)<<13))
#define  VGIP_VGIP_CHN1_STATUS_ch1_field_err(data)                               (0x00001000&((data)<<12))
#define  VGIP_VGIP_CHN1_STATUS_ch1_rl_tog(data)                                  (0x00000800&((data)<<11))
#define  VGIP_VGIP_CHN1_STATUS_ch1_l_flag_pol(data)                              (0x00000400&((data)<<10))
#define  VGIP_VGIP_CHN1_STATUS_ch1_vs_tog(data)                                  (0x00000200&((data)<<9))
#define  VGIP_VGIP_CHN1_STATUS_ch1_hs_tog(data)                                  (0x00000100&((data)<<8))
#define  VGIP_VGIP_CHN1_STATUS_ch1_field_pol(data)                               (0x00000080&((data)<<7))
#define  VGIP_VGIP_CHN1_STATUS_ch1_field_tog(data)                               (0x00000040&((data)<<6))
#define  VGIP_VGIP_CHN1_STATUS_ch1_field_vs_lsb(data)                            (0x00000030&((data)<<4))
#define  VGIP_VGIP_CHN1_STATUS_ch1_more_1line_field(data)                        (0x00000008&((data)<<3))
#define  VGIP_VGIP_CHN1_STATUS_ch1_bounce_status_2(data)                         (0x00000004&((data)<<2))
#define  VGIP_VGIP_CHN1_STATUS_ch1_bounce_status_1(data)                         (0x00000002&((data)<<1))
#define  VGIP_VGIP_CHN1_STATUS_ch1_bounce_status_0(data)                         (0x00000001&(data))
#define  VGIP_VGIP_CHN1_STATUS_get_ch1_vs_end(data)                              ((0x08000000&(data))>>27)
#define  VGIP_VGIP_CHN1_STATUS_get_ch1_vs_start(data)                            ((0x04000000&(data))>>26)
#define  VGIP_VGIP_CHN1_STATUS_get_ch1_vact_end(data)                            ((0x02000000&(data))>>25)
#define  VGIP_VGIP_CHN1_STATUS_get_ch1_vact_start(data)                          ((0x01000000&(data))>>24)
#define  VGIP_VGIP_CHN1_STATUS_get_dummy_23_17(data)                             ((0x00FE0000&(data))>>17)
#define  VGIP_VGIP_CHN1_STATUS_get_ch1_vlc_status(data)                          ((0x00010000&(data))>>16)
#define  VGIP_VGIP_CHN1_STATUS_get_ch1_rl_err(data)                              ((0x00008000&(data))>>15)
#define  VGIP_VGIP_CHN1_STATUS_get_ch1_vs_err(data)                              ((0x00004000&(data))>>14)
#define  VGIP_VGIP_CHN1_STATUS_get_ch1_hs_err(data)                              ((0x00002000&(data))>>13)
#define  VGIP_VGIP_CHN1_STATUS_get_ch1_field_err(data)                           ((0x00001000&(data))>>12)
#define  VGIP_VGIP_CHN1_STATUS_get_ch1_rl_tog(data)                              ((0x00000800&(data))>>11)
#define  VGIP_VGIP_CHN1_STATUS_get_ch1_l_flag_pol(data)                          ((0x00000400&(data))>>10)
#define  VGIP_VGIP_CHN1_STATUS_get_ch1_vs_tog(data)                              ((0x00000200&(data))>>9)
#define  VGIP_VGIP_CHN1_STATUS_get_ch1_hs_tog(data)                              ((0x00000100&(data))>>8)
#define  VGIP_VGIP_CHN1_STATUS_get_ch1_field_pol(data)                           ((0x00000080&(data))>>7)
#define  VGIP_VGIP_CHN1_STATUS_get_ch1_field_tog(data)                           ((0x00000040&(data))>>6)
#define  VGIP_VGIP_CHN1_STATUS_get_ch1_field_vs_lsb(data)                        ((0x00000030&(data))>>4)
#define  VGIP_VGIP_CHN1_STATUS_get_ch1_more_1line_field(data)                    ((0x00000008&(data))>>3)
#define  VGIP_VGIP_CHN1_STATUS_get_ch1_bounce_status_2(data)                     ((0x00000004&(data))>>2)
#define  VGIP_VGIP_CHN1_STATUS_get_ch1_bounce_status_1(data)                     ((0x00000002&(data))>>1)
#define  VGIP_VGIP_CHN1_STATUS_get_ch1_bounce_status_0(data)                     (0x00000001&(data))

#define  VGIP_VGIP_CHN1_DOUBLE_BUFFER_CTRL                                       0x180222E4
#define  VGIP_VGIP_CHN1_DOUBLE_BUFFER_CTRL_reg_addr                              "0xB80222E4"
#define  VGIP_VGIP_CHN1_DOUBLE_BUFFER_CTRL_reg                                   0xB80222E4
#define  VGIP_VGIP_CHN1_DOUBLE_BUFFER_CTRL_inst_addr                             "0x0006"
#define  set_VGIP_VGIP_CHN1_DOUBLE_BUFFER_CTRL_reg(data)                         (*((volatile unsigned int*)VGIP_VGIP_CHN1_DOUBLE_BUFFER_CTRL_reg)=data)
#define  get_VGIP_VGIP_CHN1_DOUBLE_BUFFER_CTRL_reg                               (*((volatile unsigned int*)VGIP_VGIP_CHN1_DOUBLE_BUFFER_CTRL_reg))
#define  VGIP_VGIP_CHN1_DOUBLE_BUFFER_CTRL_ch1_db_rdy_shift                      (31)
#define  VGIP_VGIP_CHN1_DOUBLE_BUFFER_CTRL_ch1_db_en_shift                       (30)
#define  VGIP_VGIP_CHN1_DOUBLE_BUFFER_CTRL_ch1_db_read_sel_shift                 (15)
#define  VGIP_VGIP_CHN1_DOUBLE_BUFFER_CTRL_ch1_db_rdy_mask                       (0x80000000)
#define  VGIP_VGIP_CHN1_DOUBLE_BUFFER_CTRL_ch1_db_en_mask                        (0x40000000)
#define  VGIP_VGIP_CHN1_DOUBLE_BUFFER_CTRL_ch1_db_read_sel_mask                  (0x00008000)
#define  VGIP_VGIP_CHN1_DOUBLE_BUFFER_CTRL_ch1_db_rdy(data)                      (0x80000000&((data)<<31))
#define  VGIP_VGIP_CHN1_DOUBLE_BUFFER_CTRL_ch1_db_en(data)                       (0x40000000&((data)<<30))
#define  VGIP_VGIP_CHN1_DOUBLE_BUFFER_CTRL_ch1_db_read_sel(data)                 (0x00008000&((data)<<15))
#define  VGIP_VGIP_CHN1_DOUBLE_BUFFER_CTRL_get_ch1_db_rdy(data)                  ((0x80000000&(data))>>31)
#define  VGIP_VGIP_CHN1_DOUBLE_BUFFER_CTRL_get_ch1_db_en(data)                   ((0x40000000&(data))>>30)
#define  VGIP_VGIP_CHN1_DOUBLE_BUFFER_CTRL_get_ch1_db_read_sel(data)             ((0x00008000&(data))>>15)

#define  VGIP_VGIP_CHN1_ACT_HSTA_Width                                           0x18022218
#define  VGIP_VGIP_CHN1_ACT_HSTA_Width_reg_addr                                  "0xB8022218"
#define  VGIP_VGIP_CHN1_ACT_HSTA_Width_reg                                       0xB8022218
#define  VGIP_VGIP_CHN1_ACT_HSTA_Width_inst_addr                                 "0x0007"
#define  set_VGIP_VGIP_CHN1_ACT_HSTA_Width_reg(data)                             (*((volatile unsigned int*)VGIP_VGIP_CHN1_ACT_HSTA_Width_reg)=data)
#define  get_VGIP_VGIP_CHN1_ACT_HSTA_Width_reg                                   (*((volatile unsigned int*)VGIP_VGIP_CHN1_ACT_HSTA_Width_reg))
#define  VGIP_VGIP_CHN1_ACT_HSTA_Width_ch1_ih_act_sta_shift                      (16)
#define  VGIP_VGIP_CHN1_ACT_HSTA_Width_ch1_bypass_den_shift                      (14)
#define  VGIP_VGIP_CHN1_ACT_HSTA_Width_ch1_ih_act_wid_shift                      (0)
#define  VGIP_VGIP_CHN1_ACT_HSTA_Width_ch1_ih_act_sta_mask                       (0x3FFF0000)
#define  VGIP_VGIP_CHN1_ACT_HSTA_Width_ch1_bypass_den_mask                       (0x00004000)
#define  VGIP_VGIP_CHN1_ACT_HSTA_Width_ch1_ih_act_wid_mask                       (0x00003FFF)
#define  VGIP_VGIP_CHN1_ACT_HSTA_Width_ch1_ih_act_sta(data)                      (0x3FFF0000&((data)<<16))
#define  VGIP_VGIP_CHN1_ACT_HSTA_Width_ch1_bypass_den(data)                      (0x00004000&((data)<<14))
#define  VGIP_VGIP_CHN1_ACT_HSTA_Width_ch1_ih_act_wid(data)                      (0x00003FFF&(data))
#define  VGIP_VGIP_CHN1_ACT_HSTA_Width_get_ch1_ih_act_sta(data)                  ((0x3FFF0000&(data))>>16)
#define  VGIP_VGIP_CHN1_ACT_HSTA_Width_get_ch1_bypass_den(data)                  ((0x00004000&(data))>>14)
#define  VGIP_VGIP_CHN1_ACT_HSTA_Width_get_ch1_ih_act_wid(data)                  (0x00003FFF&(data))

#define  VGIP_VGIP_CHN1_ACT_VSTA_Length                                          0x1802221C
#define  VGIP_VGIP_CHN1_ACT_VSTA_Length_reg_addr                                 "0xB802221C"
#define  VGIP_VGIP_CHN1_ACT_VSTA_Length_reg                                      0xB802221C
#define  VGIP_VGIP_CHN1_ACT_VSTA_Length_inst_addr                                "0x0008"
#define  set_VGIP_VGIP_CHN1_ACT_VSTA_Length_reg(data)                            (*((volatile unsigned int*)VGIP_VGIP_CHN1_ACT_VSTA_Length_reg)=data)
#define  get_VGIP_VGIP_CHN1_ACT_VSTA_Length_reg                                  (*((volatile unsigned int*)VGIP_VGIP_CHN1_ACT_VSTA_Length_reg))
#define  VGIP_VGIP_CHN1_ACT_VSTA_Length_ch1_iv_act_sta_shift                     (16)
#define  VGIP_VGIP_CHN1_ACT_VSTA_Length_ch1_iv_act_len_shift                     (0)
#define  VGIP_VGIP_CHN1_ACT_VSTA_Length_ch1_iv_act_sta_mask                      (0x1FFF0000)
#define  VGIP_VGIP_CHN1_ACT_VSTA_Length_ch1_iv_act_len_mask                      (0x00001FFF)
#define  VGIP_VGIP_CHN1_ACT_VSTA_Length_ch1_iv_act_sta(data)                     (0x1FFF0000&((data)<<16))
#define  VGIP_VGIP_CHN1_ACT_VSTA_Length_ch1_iv_act_len(data)                     (0x00001FFF&(data))
#define  VGIP_VGIP_CHN1_ACT_VSTA_Length_get_ch1_iv_act_sta(data)                 ((0x1FFF0000&(data))>>16)
#define  VGIP_VGIP_CHN1_ACT_VSTA_Length_get_ch1_iv_act_len(data)                 (0x00001FFF&(data))

#define  VGIP_VGIP_CHN1_DELAY                                                    0x18022220
#define  VGIP_VGIP_CHN1_DELAY_reg_addr                                           "0xB8022220"
#define  VGIP_VGIP_CHN1_DELAY_reg                                                0xB8022220
#define  VGIP_VGIP_CHN1_DELAY_inst_addr                                          "0x0009"
#define  set_VGIP_VGIP_CHN1_DELAY_reg(data)                                      (*((volatile unsigned int*)VGIP_VGIP_CHN1_DELAY_reg)=data)
#define  get_VGIP_VGIP_CHN1_DELAY_reg                                            (*((volatile unsigned int*)VGIP_VGIP_CHN1_DELAY_reg))
#define  VGIP_VGIP_CHN1_DELAY_ch1_hs_width_shift                                 (30)
#define  VGIP_VGIP_CHN1_DELAY_ch1_ihs_dly_shift                                  (16)
#define  VGIP_VGIP_CHN1_DELAY_ch1_ivs_dly_shift                                  (0)
#define  VGIP_VGIP_CHN1_DELAY_ch1_hs_width_mask                                  (0xC0000000)
#define  VGIP_VGIP_CHN1_DELAY_ch1_ihs_dly_mask                                   (0x3FFF0000)
#define  VGIP_VGIP_CHN1_DELAY_ch1_ivs_dly_mask                                   (0x00001FFF)
#define  VGIP_VGIP_CHN1_DELAY_ch1_hs_width(data)                                 (0xC0000000&((data)<<30))
#define  VGIP_VGIP_CHN1_DELAY_ch1_ihs_dly(data)                                  (0x3FFF0000&((data)<<16))
#define  VGIP_VGIP_CHN1_DELAY_ch1_ivs_dly(data)                                  (0x00001FFF&(data))
#define  VGIP_VGIP_CHN1_DELAY_get_ch1_hs_width(data)                             ((0xC0000000&(data))>>30)
#define  VGIP_VGIP_CHN1_DELAY_get_ch1_ihs_dly(data)                              ((0x3FFF0000&(data))>>16)
#define  VGIP_VGIP_CHN1_DELAY_get_ch1_ivs_dly(data)                              (0x00001FFF&(data))

#define  VGIP_VGIP_CHN1_MISC                                                     0x18022224
#define  VGIP_VGIP_CHN1_MISC_reg_addr                                            "0xB8022224"
#define  VGIP_VGIP_CHN1_MISC_reg                                                 0xB8022224
#define  VGIP_VGIP_CHN1_MISC_inst_addr                                           "0x000A"
#define  set_VGIP_VGIP_CHN1_MISC_reg(data)                                       (*((volatile unsigned int*)VGIP_VGIP_CHN1_MISC_reg)=data)
#define  get_VGIP_VGIP_CHN1_MISC_reg                                             (*((volatile unsigned int*)VGIP_VGIP_CHN1_MISC_reg))
#define  VGIP_VGIP_CHN1_MISC_ch1_de_mask_en_shift                                (31)
#define  VGIP_VGIP_CHN1_MISC_ch1_vs_dly_1hs_shift                                (28)
#define  VGIP_VGIP_CHN1_MISC_ch1_hporch_num_sel_shift                            (24)
#define  VGIP_VGIP_CHN1_MISC_l_flag_force_tog_shift                              (21)
#define  VGIP_VGIP_CHN1_MISC_ch1_hporch_num_shift                                (8)
#define  VGIP_VGIP_CHN1_MISC_ch1_auto_ihs_dly_shift                              (6)
#define  VGIP_VGIP_CHN1_MISC_ch1_auto_ivs_dly_shift                              (4)
#define  VGIP_VGIP_CHN1_MISC_ch1_hdly_one_shift                                  (3)
#define  VGIP_VGIP_CHN1_MISC_ch1_v1_v2_swap_shift                                (2)
#define  VGIP_VGIP_CHN1_MISC_ch1_v2_v3_swap_shift                                (1)
#define  VGIP_VGIP_CHN1_MISC_ch1_v1_v3_swap_shift                                (0)
#define  VGIP_VGIP_CHN1_MISC_ch1_de_mask_en_mask                                 (0x80000000)
#define  VGIP_VGIP_CHN1_MISC_ch1_vs_dly_1hs_mask                                 (0x10000000)
#define  VGIP_VGIP_CHN1_MISC_ch1_hporch_num_sel_mask                             (0x01000000)
#define  VGIP_VGIP_CHN1_MISC_l_flag_force_tog_mask                               (0x00200000)
#define  VGIP_VGIP_CHN1_MISC_ch1_hporch_num_mask                                 (0x001FFF00)
#define  VGIP_VGIP_CHN1_MISC_ch1_auto_ihs_dly_mask                               (0x000000C0)
#define  VGIP_VGIP_CHN1_MISC_ch1_auto_ivs_dly_mask                               (0x00000030)
#define  VGIP_VGIP_CHN1_MISC_ch1_hdly_one_mask                                   (0x00000008)
#define  VGIP_VGIP_CHN1_MISC_ch1_v1_v2_swap_mask                                 (0x00000004)
#define  VGIP_VGIP_CHN1_MISC_ch1_v2_v3_swap_mask                                 (0x00000002)
#define  VGIP_VGIP_CHN1_MISC_ch1_v1_v3_swap_mask                                 (0x00000001)
#define  VGIP_VGIP_CHN1_MISC_ch1_de_mask_en(data)                                (0x80000000&((data)<<31))
#define  VGIP_VGIP_CHN1_MISC_ch1_vs_dly_1hs(data)                                (0x10000000&((data)<<28))
#define  VGIP_VGIP_CHN1_MISC_ch1_hporch_num_sel(data)                            (0x01000000&((data)<<24))
#define  VGIP_VGIP_CHN1_MISC_l_flag_force_tog(data)                              (0x00200000&((data)<<21))
#define  VGIP_VGIP_CHN1_MISC_ch1_hporch_num(data)                                (0x001FFF00&((data)<<8))
#define  VGIP_VGIP_CHN1_MISC_ch1_auto_ihs_dly(data)                              (0x000000C0&((data)<<6))
#define  VGIP_VGIP_CHN1_MISC_ch1_auto_ivs_dly(data)                              (0x00000030&((data)<<4))
#define  VGIP_VGIP_CHN1_MISC_ch1_hdly_one(data)                                  (0x00000008&((data)<<3))
#define  VGIP_VGIP_CHN1_MISC_ch1_v1_v2_swap(data)                                (0x00000004&((data)<<2))
#define  VGIP_VGIP_CHN1_MISC_ch1_v2_v3_swap(data)                                (0x00000002&((data)<<1))
#define  VGIP_VGIP_CHN1_MISC_ch1_v1_v3_swap(data)                                (0x00000001&(data))
#define  VGIP_VGIP_CHN1_MISC_get_ch1_de_mask_en(data)                            ((0x80000000&(data))>>31)
#define  VGIP_VGIP_CHN1_MISC_get_ch1_vs_dly_1hs(data)                            ((0x10000000&(data))>>28)
#define  VGIP_VGIP_CHN1_MISC_get_ch1_hporch_num_sel(data)                        ((0x01000000&(data))>>24)
#define  VGIP_VGIP_CHN1_MISC_get_l_flag_force_tog(data)                          ((0x00200000&(data))>>21)
#define  VGIP_VGIP_CHN1_MISC_get_ch1_hporch_num(data)                            ((0x001FFF00&(data))>>8)
#define  VGIP_VGIP_CHN1_MISC_get_ch1_auto_ihs_dly(data)                          ((0x000000C0&(data))>>6)
#define  VGIP_VGIP_CHN1_MISC_get_ch1_auto_ivs_dly(data)                          ((0x00000030&(data))>>4)
#define  VGIP_VGIP_CHN1_MISC_get_ch1_hdly_one(data)                              ((0x00000008&(data))>>3)
#define  VGIP_VGIP_CHN1_MISC_get_ch1_v1_v2_swap(data)                            ((0x00000004&(data))>>2)
#define  VGIP_VGIP_CHN1_MISC_get_ch1_v2_v3_swap(data)                            ((0x00000002&(data))>>1)
#define  VGIP_VGIP_CHN1_MISC_get_ch1_v1_v3_swap(data)                            (0x00000001&(data))

#define  VGIP_VGIP_CHN1_PTN_H_VI                                                 0x18022228
#define  VGIP_VGIP_CHN1_PTN_H_VI_reg_addr                                        "0xB8022228"
#define  VGIP_VGIP_CHN1_PTN_H_VI_reg                                             0xB8022228
#define  VGIP_VGIP_CHN1_PTN_H_VI_inst_addr                                       "0x000B"
#define  set_VGIP_VGIP_CHN1_PTN_H_VI_reg(data)                                   (*((volatile unsigned int*)VGIP_VGIP_CHN1_PTN_H_VI_reg)=data)
#define  get_VGIP_VGIP_CHN1_PTN_H_VI_reg                                         (*((volatile unsigned int*)VGIP_VGIP_CHN1_PTN_H_VI_reg))
#define  VGIP_VGIP_CHN1_PTN_H_VI_ch1_captst_en_shift                             (31)
#define  VGIP_VGIP_CHN1_PTN_H_VI_ch1_captst_mode_shift                           (29)
#define  VGIP_VGIP_CHN1_PTN_H_VI_ch1_vcaptst_num_shift                           (16)
#define  VGIP_VGIP_CHN1_PTN_H_VI_ch1_captst_field_sel_shift                      (15)
#define  VGIP_VGIP_CHN1_PTN_H_VI_ch1_hcaptst_num_shift                           (0)
#define  VGIP_VGIP_CHN1_PTN_H_VI_ch1_captst_en_mask                              (0x80000000)
#define  VGIP_VGIP_CHN1_PTN_H_VI_ch1_captst_mode_mask                            (0x60000000)
#define  VGIP_VGIP_CHN1_PTN_H_VI_ch1_vcaptst_num_mask                            (0x1FFF0000)
#define  VGIP_VGIP_CHN1_PTN_H_VI_ch1_captst_field_sel_mask                       (0x00008000)
#define  VGIP_VGIP_CHN1_PTN_H_VI_ch1_hcaptst_num_mask                            (0x00003FFF)
#define  VGIP_VGIP_CHN1_PTN_H_VI_ch1_captst_en(data)                             (0x80000000&((data)<<31))
#define  VGIP_VGIP_CHN1_PTN_H_VI_ch1_captst_mode(data)                           (0x60000000&((data)<<29))
#define  VGIP_VGIP_CHN1_PTN_H_VI_ch1_vcaptst_num(data)                           (0x1FFF0000&((data)<<16))
#define  VGIP_VGIP_CHN1_PTN_H_VI_ch1_captst_field_sel(data)                      (0x00008000&((data)<<15))
#define  VGIP_VGIP_CHN1_PTN_H_VI_ch1_hcaptst_num(data)                           (0x00003FFF&(data))
#define  VGIP_VGIP_CHN1_PTN_H_VI_get_ch1_captst_en(data)                         ((0x80000000&(data))>>31)
#define  VGIP_VGIP_CHN1_PTN_H_VI_get_ch1_captst_mode(data)                       ((0x60000000&(data))>>29)
#define  VGIP_VGIP_CHN1_PTN_H_VI_get_ch1_vcaptst_num(data)                       ((0x1FFF0000&(data))>>16)
#define  VGIP_VGIP_CHN1_PTN_H_VI_get_ch1_captst_field_sel(data)                  ((0x00008000&(data))>>15)
#define  VGIP_VGIP_CHN1_PTN_H_VI_get_ch1_hcaptst_num(data)                       (0x00003FFF&(data))

#define  VGIP_VGIP_CHN1_PTN0                                                     0x1802222C
#define  VGIP_VGIP_CHN1_PTN0_reg_addr                                            "0xB802222C"
#define  VGIP_VGIP_CHN1_PTN0_reg                                                 0xB802222C
#define  VGIP_VGIP_CHN1_PTN0_inst_addr                                           "0x000C"
#define  set_VGIP_VGIP_CHN1_PTN0_reg(data)                                       (*((volatile unsigned int*)VGIP_VGIP_CHN1_PTN0_reg)=data)
#define  get_VGIP_VGIP_CHN1_PTN0_reg                                             (*((volatile unsigned int*)VGIP_VGIP_CHN1_PTN0_reg))
#define  VGIP_VGIP_CHN1_PTN0_ch1_captst_r_data_shift                             (16)
#define  VGIP_VGIP_CHN1_PTN0_ch1_captst_g_data_shift                             (0)
#define  VGIP_VGIP_CHN1_PTN0_ch1_captst_r_data_mask                              (0x0FFF0000)
#define  VGIP_VGIP_CHN1_PTN0_ch1_captst_g_data_mask                              (0x00000FFF)
#define  VGIP_VGIP_CHN1_PTN0_ch1_captst_r_data(data)                             (0x0FFF0000&((data)<<16))
#define  VGIP_VGIP_CHN1_PTN0_ch1_captst_g_data(data)                             (0x00000FFF&(data))
#define  VGIP_VGIP_CHN1_PTN0_get_ch1_captst_r_data(data)                         ((0x0FFF0000&(data))>>16)
#define  VGIP_VGIP_CHN1_PTN0_get_ch1_captst_g_data(data)                         (0x00000FFF&(data))

#define  VGIP_VGIP_CHN1_PTN1                                                     0x18022230
#define  VGIP_VGIP_CHN1_PTN1_reg_addr                                            "0xB8022230"
#define  VGIP_VGIP_CHN1_PTN1_reg                                                 0xB8022230
#define  VGIP_VGIP_CHN1_PTN1_inst_addr                                           "0x000D"
#define  set_VGIP_VGIP_CHN1_PTN1_reg(data)                                       (*((volatile unsigned int*)VGIP_VGIP_CHN1_PTN1_reg)=data)
#define  get_VGIP_VGIP_CHN1_PTN1_reg                                             (*((volatile unsigned int*)VGIP_VGIP_CHN1_PTN1_reg))
#define  VGIP_VGIP_CHN1_PTN1_ch1_hporch_num_sel_shift                            (16)
#define  VGIP_VGIP_CHN1_PTN1_ch1_captst_b_data_shift                             (0)
#define  VGIP_VGIP_CHN1_PTN1_ch1_hporch_num_sel_mask                             (0x3FFF0000)
#define  VGIP_VGIP_CHN1_PTN1_ch1_captst_b_data_mask                              (0x00000FFF)
#define  VGIP_VGIP_CHN1_PTN1_ch1_hporch_num_sel(data)                            (0x3FFF0000&((data)<<16))
#define  VGIP_VGIP_CHN1_PTN1_ch1_captst_b_data(data)                             (0x00000FFF&(data))
#define  VGIP_VGIP_CHN1_PTN1_get_ch1_hporch_num_sel(data)                        ((0x3FFF0000&(data))>>16)
#define  VGIP_VGIP_CHN1_PTN1_get_ch1_captst_b_data(data)                         (0x00000FFF&(data))

#define  VGIP_VGIP_CHN1_LC                                                       0x18022234
#define  VGIP_VGIP_CHN1_LC_reg_addr                                              "0xB8022234"
#define  VGIP_VGIP_CHN1_LC_reg                                                   0xB8022234
#define  VGIP_VGIP_CHN1_LC_inst_addr                                             "0x000E"
#define  set_VGIP_VGIP_CHN1_LC_reg(data)                                         (*((volatile unsigned int*)VGIP_VGIP_CHN1_LC_reg)=data)
#define  get_VGIP_VGIP_CHN1_LC_reg                                               (*((volatile unsigned int*)VGIP_VGIP_CHN1_LC_reg))
#define  VGIP_VGIP_CHN1_LC_ch1_vlcen_shift                                       (31)
#define  VGIP_VGIP_CHN1_LC_ch1_vlc_mode_shift                                    (30)
#define  VGIP_VGIP_CHN1_LC_ch1_vlc_ie_shift                                      (29)
#define  VGIP_VGIP_CHN1_LC_den_crc_sel_shift                                     (28)
#define  VGIP_VGIP_CHN1_LC_ch1_line_cnt_shift                                    (12)
#define  VGIP_VGIP_CHN1_LC_ch1_vln_shift                                         (0)
#define  VGIP_VGIP_CHN1_LC_ch1_vlcen_mask                                        (0x80000000)
#define  VGIP_VGIP_CHN1_LC_ch1_vlc_mode_mask                                     (0x40000000)
#define  VGIP_VGIP_CHN1_LC_ch1_vlc_ie_mask                                       (0x20000000)
#define  VGIP_VGIP_CHN1_LC_den_crc_sel_mask                                      (0x10000000)
#define  VGIP_VGIP_CHN1_LC_ch1_line_cnt_mask                                     (0x00FFF000)
#define  VGIP_VGIP_CHN1_LC_ch1_vln_mask                                          (0x00000FFF)
#define  VGIP_VGIP_CHN1_LC_ch1_vlcen(data)                                       (0x80000000&((data)<<31))
#define  VGIP_VGIP_CHN1_LC_ch1_vlc_mode(data)                                    (0x40000000&((data)<<30))
#define  VGIP_VGIP_CHN1_LC_ch1_vlc_ie(data)                                      (0x20000000&((data)<<29))
#define  VGIP_VGIP_CHN1_LC_den_crc_sel(data)                                     (0x10000000&((data)<<28))
#define  VGIP_VGIP_CHN1_LC_ch1_line_cnt(data)                                    (0x00FFF000&((data)<<12))
#define  VGIP_VGIP_CHN1_LC_ch1_vln(data)                                         (0x00000FFF&(data))
#define  VGIP_VGIP_CHN1_LC_get_ch1_vlcen(data)                                   ((0x80000000&(data))>>31)
#define  VGIP_VGIP_CHN1_LC_get_ch1_vlc_mode(data)                                ((0x40000000&(data))>>30)
#define  VGIP_VGIP_CHN1_LC_get_ch1_vlc_ie(data)                                  ((0x20000000&(data))>>29)
#define  VGIP_VGIP_CHN1_LC_get_den_crc_sel(data)                                 ((0x10000000&(data))>>28)
#define  VGIP_VGIP_CHN1_LC_get_ch1_line_cnt(data)                                ((0x00FFF000&(data))>>12)
#define  VGIP_VGIP_CHN1_LC_get_ch1_vln(data)                                     (0x00000FFF&(data))

#define  VGIP_ICH1_VGIP_CRC_CTRL                                                 0x18022238
#define  VGIP_ICH1_VGIP_CRC_CTRL_reg_addr                                        "0xB8022238"
#define  VGIP_ICH1_VGIP_CRC_CTRL_reg                                             0xB8022238
#define  VGIP_ICH1_VGIP_CRC_CTRL_inst_addr                                       "0x000F"
#define  set_VGIP_ICH1_VGIP_CRC_CTRL_reg(data)                                   (*((volatile unsigned int*)VGIP_ICH1_VGIP_CRC_CTRL_reg)=data)
#define  get_VGIP_ICH1_VGIP_CRC_CTRL_reg                                         (*((volatile unsigned int*)VGIP_ICH1_VGIP_CRC_CTRL_reg))
#define  VGIP_ICH1_VGIP_CRC_CTRL_ch1_crc_mode_shift                              (6)
#define  VGIP_ICH1_VGIP_CRC_CTRL_ch1_crc_region_shift                            (5)
#define  VGIP_ICH1_VGIP_CRC_CTRL_ch1_crc_ctrl_in_shift                           (4)
#define  VGIP_ICH1_VGIP_CRC_CTRL_ch1_crc_field_edge_sel_shift                    (3)
#define  VGIP_ICH1_VGIP_CRC_CTRL_ch1_crc_field_shift                             (2)
#define  VGIP_ICH1_VGIP_CRC_CTRL_ch1_crc_conti_shift                             (1)
#define  VGIP_ICH1_VGIP_CRC_CTRL_ch1_crc_start_shift                             (0)
#define  VGIP_ICH1_VGIP_CRC_CTRL_ch1_crc_mode_mask                               (0x00000040)
#define  VGIP_ICH1_VGIP_CRC_CTRL_ch1_crc_region_mask                             (0x00000020)
#define  VGIP_ICH1_VGIP_CRC_CTRL_ch1_crc_ctrl_in_mask                            (0x00000010)
#define  VGIP_ICH1_VGIP_CRC_CTRL_ch1_crc_field_edge_sel_mask                     (0x00000008)
#define  VGIP_ICH1_VGIP_CRC_CTRL_ch1_crc_field_mask                              (0x00000004)
#define  VGIP_ICH1_VGIP_CRC_CTRL_ch1_crc_conti_mask                              (0x00000002)
#define  VGIP_ICH1_VGIP_CRC_CTRL_ch1_crc_start_mask                              (0x00000001)
#define  VGIP_ICH1_VGIP_CRC_CTRL_ch1_crc_mode(data)                              (0x00000040&((data)<<6))
#define  VGIP_ICH1_VGIP_CRC_CTRL_ch1_crc_region(data)                            (0x00000020&((data)<<5))
#define  VGIP_ICH1_VGIP_CRC_CTRL_ch1_crc_ctrl_in(data)                           (0x00000010&((data)<<4))
#define  VGIP_ICH1_VGIP_CRC_CTRL_ch1_crc_field_edge_sel(data)                    (0x00000008&((data)<<3))
#define  VGIP_ICH1_VGIP_CRC_CTRL_ch1_crc_field(data)                             (0x00000004&((data)<<2))
#define  VGIP_ICH1_VGIP_CRC_CTRL_ch1_crc_conti(data)                             (0x00000002&((data)<<1))
#define  VGIP_ICH1_VGIP_CRC_CTRL_ch1_crc_start(data)                             (0x00000001&(data))
#define  VGIP_ICH1_VGIP_CRC_CTRL_get_ch1_crc_mode(data)                          ((0x00000040&(data))>>6)
#define  VGIP_ICH1_VGIP_CRC_CTRL_get_ch1_crc_region(data)                        ((0x00000020&(data))>>5)
#define  VGIP_ICH1_VGIP_CRC_CTRL_get_ch1_crc_ctrl_in(data)                       ((0x00000010&(data))>>4)
#define  VGIP_ICH1_VGIP_CRC_CTRL_get_ch1_crc_field_edge_sel(data)                ((0x00000008&(data))>>3)
#define  VGIP_ICH1_VGIP_CRC_CTRL_get_ch1_crc_field(data)                         ((0x00000004&(data))>>2)
#define  VGIP_ICH1_VGIP_CRC_CTRL_get_ch1_crc_conti(data)                         ((0x00000002&(data))>>1)
#define  VGIP_ICH1_VGIP_CRC_CTRL_get_ch1_crc_start(data)                         (0x00000001&(data))

#define  VGIP_ICH1_VGIP_CRC_Result                                               0x1802223C
#define  VGIP_ICH1_VGIP_CRC_Result_reg_addr                                      "0xB802223C"
#define  VGIP_ICH1_VGIP_CRC_Result_reg                                           0xB802223C
#define  VGIP_ICH1_VGIP_CRC_Result_inst_addr                                     "0x0010"
#define  set_VGIP_ICH1_VGIP_CRC_Result_reg(data)                                 (*((volatile unsigned int*)VGIP_ICH1_VGIP_CRC_Result_reg)=data)
#define  get_VGIP_ICH1_VGIP_CRC_Result_reg                                       (*((volatile unsigned int*)VGIP_ICH1_VGIP_CRC_Result_reg))
#define  VGIP_ICH1_VGIP_CRC_Result_ch1_crc_result_shift                          (0)
#define  VGIP_ICH1_VGIP_CRC_Result_ch1_crc_result_mask                           (0xFFFFFFFF)
#define  VGIP_ICH1_VGIP_CRC_Result_ch1_crc_result(data)                          (0xFFFFFFFF&(data))
#define  VGIP_ICH1_VGIP_CRC_Result_get_ch1_crc_result(data)                      (0xFFFFFFFF&(data))

#define  VGIP_VGIP_CHN1_WDE                                                      0x18022240
#define  VGIP_VGIP_CHN1_WDE_reg_addr                                             "0xB8022240"
#define  VGIP_VGIP_CHN1_WDE_reg                                                  0xB8022240
#define  VGIP_VGIP_CHN1_WDE_inst_addr                                            "0x0011"
#define  set_VGIP_VGIP_CHN1_WDE_reg(data)                                        (*((volatile unsigned int*)VGIP_VGIP_CHN1_WDE_reg)=data)
#define  get_VGIP_VGIP_CHN1_WDE_reg                                              (*((volatile unsigned int*)VGIP_VGIP_CHN1_WDE_reg))
#define  VGIP_VGIP_CHN1_WDE_ch1_wd_to_main_shift                                 (31)
#define  VGIP_VGIP_CHN1_WDE_dummy3_shift                                         (19)
#define  VGIP_VGIP_CHN1_WDE_ch1_vs_err_wde_shift                                 (18)
#define  VGIP_VGIP_CHN1_WDE_ch1_hs_err_wde_shift                                 (17)
#define  VGIP_VGIP_CHN1_WDE_ch1_field_err_wde_shift                              (16)
#define  VGIP_VGIP_CHN1_WDE_ch1_rl_err_wde_shift                                 (15)
#define  VGIP_VGIP_CHN1_WDE_dummy4_shift                                         (4)
#define  VGIP_VGIP_CHN1_WDE_ch1_rl_err_ie_shift                                  (3)
#define  VGIP_VGIP_CHN1_WDE_ch1_vs_err_ie_shift                                  (2)
#define  VGIP_VGIP_CHN1_WDE_ch1_hs_err_ie_shift                                  (1)
#define  VGIP_VGIP_CHN1_WDE_ch1_field_err_ie_shift                               (0)
#define  VGIP_VGIP_CHN1_WDE_ch1_wd_to_main_mask                                  (0x80000000)
#define  VGIP_VGIP_CHN1_WDE_dummy3_mask                                          (0x7FF80000)
#define  VGIP_VGIP_CHN1_WDE_ch1_vs_err_wde_mask                                  (0x00040000)
#define  VGIP_VGIP_CHN1_WDE_ch1_hs_err_wde_mask                                  (0x00020000)
#define  VGIP_VGIP_CHN1_WDE_ch1_field_err_wde_mask                               (0x00010000)
#define  VGIP_VGIP_CHN1_WDE_ch1_rl_err_wde_mask                                  (0x00008000)
#define  VGIP_VGIP_CHN1_WDE_dummy4_mask                                          (0x00007FF0)
#define  VGIP_VGIP_CHN1_WDE_ch1_rl_err_ie_mask                                   (0x00000008)
#define  VGIP_VGIP_CHN1_WDE_ch1_vs_err_ie_mask                                   (0x00000004)
#define  VGIP_VGIP_CHN1_WDE_ch1_hs_err_ie_mask                                   (0x00000002)
#define  VGIP_VGIP_CHN1_WDE_ch1_field_err_ie_mask                                (0x00000001)
#define  VGIP_VGIP_CHN1_WDE_ch1_wd_to_main(data)                                 (0x80000000&((data)<<31))
#define  VGIP_VGIP_CHN1_WDE_dummy3(data)                                         (0x7FF80000&((data)<<19))
#define  VGIP_VGIP_CHN1_WDE_ch1_vs_err_wde(data)                                 (0x00040000&((data)<<18))
#define  VGIP_VGIP_CHN1_WDE_ch1_hs_err_wde(data)                                 (0x00020000&((data)<<17))
#define  VGIP_VGIP_CHN1_WDE_ch1_field_err_wde(data)                              (0x00010000&((data)<<16))
#define  VGIP_VGIP_CHN1_WDE_ch1_rl_err_wde(data)                                 (0x00008000&((data)<<15))
#define  VGIP_VGIP_CHN1_WDE_dummy4(data)                                         (0x00007FF0&((data)<<4))
#define  VGIP_VGIP_CHN1_WDE_ch1_rl_err_ie(data)                                  (0x00000008&((data)<<3))
#define  VGIP_VGIP_CHN1_WDE_ch1_vs_err_ie(data)                                  (0x00000004&((data)<<2))
#define  VGIP_VGIP_CHN1_WDE_ch1_hs_err_ie(data)                                  (0x00000002&((data)<<1))
#define  VGIP_VGIP_CHN1_WDE_ch1_field_err_ie(data)                               (0x00000001&(data))
#define  VGIP_VGIP_CHN1_WDE_get_ch1_wd_to_main(data)                             ((0x80000000&(data))>>31)
#define  VGIP_VGIP_CHN1_WDE_get_dummy3(data)                                     ((0x7FF80000&(data))>>19)
#define  VGIP_VGIP_CHN1_WDE_get_ch1_vs_err_wde(data)                             ((0x00040000&(data))>>18)
#define  VGIP_VGIP_CHN1_WDE_get_ch1_hs_err_wde(data)                             ((0x00020000&(data))>>17)
#define  VGIP_VGIP_CHN1_WDE_get_ch1_field_err_wde(data)                          ((0x00010000&(data))>>16)
#define  VGIP_VGIP_CHN1_WDE_get_ch1_rl_err_wde(data)                             ((0x00008000&(data))>>15)
#define  VGIP_VGIP_CHN1_WDE_get_dummy4(data)                                     ((0x00007FF0&(data))>>4)
#define  VGIP_VGIP_CHN1_WDE_get_ch1_rl_err_ie(data)                              ((0x00000008&(data))>>3)
#define  VGIP_VGIP_CHN1_WDE_get_ch1_vs_err_ie(data)                              ((0x00000004&(data))>>2)
#define  VGIP_VGIP_CHN1_WDE_get_ch1_hs_err_ie(data)                              ((0x00000002&(data))>>1)
#define  VGIP_VGIP_CHN1_WDE_get_ch1_field_err_ie(data)                           (0x00000001&(data))

#define  VGIP_PR_L_R_ONLY_CTRL_CH1                                               0x18022250
#define  VGIP_PR_L_R_ONLY_CTRL_CH1_reg_addr                                      "0xB8022250"
#define  VGIP_PR_L_R_ONLY_CTRL_CH1_reg                                           0xB8022250
#define  VGIP_PR_L_R_ONLY_CTRL_CH1_inst_addr                                     "0x0012"
#define  set_VGIP_PR_L_R_ONLY_CTRL_CH1_reg(data)                                 (*((volatile unsigned int*)VGIP_PR_L_R_ONLY_CTRL_CH1_reg)=data)
#define  get_VGIP_PR_L_R_ONLY_CTRL_CH1_reg                                       (*((volatile unsigned int*)VGIP_PR_L_R_ONLY_CTRL_CH1_reg))
#define  VGIP_PR_L_R_ONLY_CTRL_CH1_ch1_pr_l_r_only_mask_hs_shift                 (2)
#define  VGIP_PR_L_R_ONLY_CTRL_CH1_ch1_pr_l_r_only_rm_den_shift                  (1)
#define  VGIP_PR_L_R_ONLY_CTRL_CH1_ch1_pr_l_r_only_en_shift                      (0)
#define  VGIP_PR_L_R_ONLY_CTRL_CH1_ch1_pr_l_r_only_mask_hs_mask                  (0x00000004)
#define  VGIP_PR_L_R_ONLY_CTRL_CH1_ch1_pr_l_r_only_rm_den_mask                   (0x00000002)
#define  VGIP_PR_L_R_ONLY_CTRL_CH1_ch1_pr_l_r_only_en_mask                       (0x00000001)
#define  VGIP_PR_L_R_ONLY_CTRL_CH1_ch1_pr_l_r_only_mask_hs(data)                 (0x00000004&((data)<<2))
#define  VGIP_PR_L_R_ONLY_CTRL_CH1_ch1_pr_l_r_only_rm_den(data)                  (0x00000002&((data)<<1))
#define  VGIP_PR_L_R_ONLY_CTRL_CH1_ch1_pr_l_r_only_en(data)                      (0x00000001&(data))
#define  VGIP_PR_L_R_ONLY_CTRL_CH1_get_ch1_pr_l_r_only_mask_hs(data)             ((0x00000004&(data))>>2)
#define  VGIP_PR_L_R_ONLY_CTRL_CH1_get_ch1_pr_l_r_only_rm_den(data)              ((0x00000002&(data))>>1)
#define  VGIP_PR_L_R_ONLY_CTRL_CH1_get_ch1_pr_l_r_only_en(data)                  (0x00000001&(data))

#define  VGIP_VGIP_CHN1_PTN2                                                     0x18022260
#define  VGIP_VGIP_CHN1_PTN2_reg_addr                                            "0xB8022260"
#define  VGIP_VGIP_CHN1_PTN2_reg                                                 0xB8022260
#define  VGIP_VGIP_CHN1_PTN2_inst_addr                                           "0x0013"
#define  set_VGIP_VGIP_CHN1_PTN2_reg(data)                                       (*((volatile unsigned int*)VGIP_VGIP_CHN1_PTN2_reg)=data)
#define  get_VGIP_VGIP_CHN1_PTN2_reg                                             (*((volatile unsigned int*)VGIP_VGIP_CHN1_PTN2_reg))
#define  VGIP_VGIP_CHN1_PTN2_ch1_captst_r_data_2_shift                           (16)
#define  VGIP_VGIP_CHN1_PTN2_ch1_captst_g_data_2_shift                           (0)
#define  VGIP_VGIP_CHN1_PTN2_ch1_captst_r_data_2_mask                            (0x0FFF0000)
#define  VGIP_VGIP_CHN1_PTN2_ch1_captst_g_data_2_mask                            (0x00000FFF)
#define  VGIP_VGIP_CHN1_PTN2_ch1_captst_r_data_2(data)                           (0x0FFF0000&((data)<<16))
#define  VGIP_VGIP_CHN1_PTN2_ch1_captst_g_data_2(data)                           (0x00000FFF&(data))
#define  VGIP_VGIP_CHN1_PTN2_get_ch1_captst_r_data_2(data)                       ((0x0FFF0000&(data))>>16)
#define  VGIP_VGIP_CHN1_PTN2_get_ch1_captst_g_data_2(data)                       (0x00000FFF&(data))

#define  VGIP_VGIP_CHN1_PTN3                                                     0x18022264
#define  VGIP_VGIP_CHN1_PTN3_reg_addr                                            "0xB8022264"
#define  VGIP_VGIP_CHN1_PTN3_reg                                                 0xB8022264
#define  VGIP_VGIP_CHN1_PTN3_inst_addr                                           "0x0014"
#define  set_VGIP_VGIP_CHN1_PTN3_reg(data)                                       (*((volatile unsigned int*)VGIP_VGIP_CHN1_PTN3_reg)=data)
#define  get_VGIP_VGIP_CHN1_PTN3_reg                                             (*((volatile unsigned int*)VGIP_VGIP_CHN1_PTN3_reg))
#define  VGIP_VGIP_CHN1_PTN3_ch1_captst_b_data_3_shift                           (16)
#define  VGIP_VGIP_CHN1_PTN3_ch1_captst_b_data_2_shift                           (0)
#define  VGIP_VGIP_CHN1_PTN3_ch1_captst_b_data_3_mask                            (0x0FFF0000)
#define  VGIP_VGIP_CHN1_PTN3_ch1_captst_b_data_2_mask                            (0x00000FFF)
#define  VGIP_VGIP_CHN1_PTN3_ch1_captst_b_data_3(data)                           (0x0FFF0000&((data)<<16))
#define  VGIP_VGIP_CHN1_PTN3_ch1_captst_b_data_2(data)                           (0x00000FFF&(data))
#define  VGIP_VGIP_CHN1_PTN3_get_ch1_captst_b_data_3(data)                       ((0x0FFF0000&(data))>>16)
#define  VGIP_VGIP_CHN1_PTN3_get_ch1_captst_b_data_2(data)                       (0x00000FFF&(data))

#define  VGIP_VGIP_CHN1_PTN4                                                     0x18022268
#define  VGIP_VGIP_CHN1_PTN4_reg_addr                                            "0xB8022268"
#define  VGIP_VGIP_CHN1_PTN4_reg                                                 0xB8022268
#define  VGIP_VGIP_CHN1_PTN4_inst_addr                                           "0x0015"
#define  set_VGIP_VGIP_CHN1_PTN4_reg(data)                                       (*((volatile unsigned int*)VGIP_VGIP_CHN1_PTN4_reg)=data)
#define  get_VGIP_VGIP_CHN1_PTN4_reg                                             (*((volatile unsigned int*)VGIP_VGIP_CHN1_PTN4_reg))
#define  VGIP_VGIP_CHN1_PTN4_ch1_captst_r_data_3_shift                           (16)
#define  VGIP_VGIP_CHN1_PTN4_ch1_captst_g_data_3_shift                           (0)
#define  VGIP_VGIP_CHN1_PTN4_ch1_captst_r_data_3_mask                            (0x0FFF0000)
#define  VGIP_VGIP_CHN1_PTN4_ch1_captst_g_data_3_mask                            (0x00000FFF)
#define  VGIP_VGIP_CHN1_PTN4_ch1_captst_r_data_3(data)                           (0x0FFF0000&((data)<<16))
#define  VGIP_VGIP_CHN1_PTN4_ch1_captst_g_data_3(data)                           (0x00000FFF&(data))
#define  VGIP_VGIP_CHN1_PTN4_get_ch1_captst_r_data_3(data)                       ((0x0FFF0000&(data))>>16)
#define  VGIP_VGIP_CHN1_PTN4_get_ch1_captst_g_data_3(data)                       (0x00000FFF&(data))

#define  VGIP_VGIP_CHN1_PTN5                                                     0x1802226C
#define  VGIP_VGIP_CHN1_PTN5_reg_addr                                            "0xB802226C"
#define  VGIP_VGIP_CHN1_PTN5_reg                                                 0xB802226C
#define  VGIP_VGIP_CHN1_PTN5_inst_addr                                           "0x0016"
#define  set_VGIP_VGIP_CHN1_PTN5_reg(data)                                       (*((volatile unsigned int*)VGIP_VGIP_CHN1_PTN5_reg)=data)
#define  get_VGIP_VGIP_CHN1_PTN5_reg                                             (*((volatile unsigned int*)VGIP_VGIP_CHN1_PTN5_reg))
#define  VGIP_VGIP_CHN1_PTN5_ch1_captst_r_data_4_shift                           (16)
#define  VGIP_VGIP_CHN1_PTN5_ch1_captst_g_data_4_shift                           (0)
#define  VGIP_VGIP_CHN1_PTN5_ch1_captst_r_data_4_mask                            (0x0FFF0000)
#define  VGIP_VGIP_CHN1_PTN5_ch1_captst_g_data_4_mask                            (0x00000FFF)
#define  VGIP_VGIP_CHN1_PTN5_ch1_captst_r_data_4(data)                           (0x0FFF0000&((data)<<16))
#define  VGIP_VGIP_CHN1_PTN5_ch1_captst_g_data_4(data)                           (0x00000FFF&(data))
#define  VGIP_VGIP_CHN1_PTN5_get_ch1_captst_r_data_4(data)                       ((0x0FFF0000&(data))>>16)
#define  VGIP_VGIP_CHN1_PTN5_get_ch1_captst_g_data_4(data)                       (0x00000FFF&(data))

#define  VGIP_VGIP_CHN1_PTN6                                                     0x18022270
#define  VGIP_VGIP_CHN1_PTN6_reg_addr                                            "0xB8022270"
#define  VGIP_VGIP_CHN1_PTN6_reg                                                 0xB8022270
#define  VGIP_VGIP_CHN1_PTN6_inst_addr                                           "0x0017"
#define  set_VGIP_VGIP_CHN1_PTN6_reg(data)                                       (*((volatile unsigned int*)VGIP_VGIP_CHN1_PTN6_reg)=data)
#define  get_VGIP_VGIP_CHN1_PTN6_reg                                             (*((volatile unsigned int*)VGIP_VGIP_CHN1_PTN6_reg))
#define  VGIP_VGIP_CHN1_PTN6_ch1_captst_b_data_4_shift                           (0)
#define  VGIP_VGIP_CHN1_PTN6_ch1_captst_b_data_4_mask                            (0x00000FFF)
#define  VGIP_VGIP_CHN1_PTN6_ch1_captst_b_data_4(data)                           (0x00000FFF&(data))
#define  VGIP_VGIP_CHN1_PTN6_get_ch1_captst_b_data_4(data)                       (0x00000FFF&(data))

#define  VGIP_ADC_raw_data_DMA                                                   0x18022278
#define  VGIP_ADC_raw_data_DMA_reg_addr                                          "0xB8022278"
#define  VGIP_ADC_raw_data_DMA_reg                                               0xB8022278
#define  VGIP_ADC_raw_data_DMA_inst_addr                                         "0x0018"
#define  set_VGIP_ADC_raw_data_DMA_reg(data)                                     (*((volatile unsigned int*)VGIP_ADC_raw_data_DMA_reg)=data)
#define  get_VGIP_ADC_raw_data_DMA_reg                                           (*((volatile unsigned int*)VGIP_ADC_raw_data_DMA_reg))
#define  VGIP_ADC_raw_data_DMA_adc_test_dma_count_shift                          (4)
#define  VGIP_ADC_raw_data_DMA_force_den_shift                                   (2)
#define  VGIP_ADC_raw_data_DMA_force_vsync_shift                                 (1)
#define  VGIP_ADC_raw_data_DMA_adc_test_dma_mode_shift                           (0)
#define  VGIP_ADC_raw_data_DMA_adc_test_dma_count_mask                           (0xFFFFFFF0)
#define  VGIP_ADC_raw_data_DMA_force_den_mask                                    (0x00000004)
#define  VGIP_ADC_raw_data_DMA_force_vsync_mask                                  (0x00000002)
#define  VGIP_ADC_raw_data_DMA_adc_test_dma_mode_mask                            (0x00000001)
#define  VGIP_ADC_raw_data_DMA_adc_test_dma_count(data)                          (0xFFFFFFF0&((data)<<4))
#define  VGIP_ADC_raw_data_DMA_force_den(data)                                   (0x00000004&((data)<<2))
#define  VGIP_ADC_raw_data_DMA_force_vsync(data)                                 (0x00000002&((data)<<1))
#define  VGIP_ADC_raw_data_DMA_adc_test_dma_mode(data)                           (0x00000001&(data))
#define  VGIP_ADC_raw_data_DMA_get_adc_test_dma_count(data)                      ((0xFFFFFFF0&(data))>>4)
#define  VGIP_ADC_raw_data_DMA_get_force_den(data)                               ((0x00000004&(data))>>2)
#define  VGIP_ADC_raw_data_DMA_get_force_vsync(data)                             ((0x00000002&(data))>>1)
#define  VGIP_ADC_raw_data_DMA_get_adc_test_dma_mode(data)                       (0x00000001&(data))

#define  VGIP_FRAMEPACKING_CTRL1                                                 0x1802227C
#define  VGIP_FRAMEPACKING_CTRL1_reg_addr                                        "0xB802227C"
#define  VGIP_FRAMEPACKING_CTRL1_reg                                             0xB802227C
#define  VGIP_FRAMEPACKING_CTRL1_inst_addr                                       "0x0019"
#define  set_VGIP_FRAMEPACKING_CTRL1_reg(data)                                   (*((volatile unsigned int*)VGIP_FRAMEPACKING_CTRL1_reg)=data)
#define  get_VGIP_FRAMEPACKING_CTRL1_reg                                         (*((volatile unsigned int*)VGIP_FRAMEPACKING_CTRL1_reg))
#define  VGIP_FRAMEPACKING_CTRL1_vs_width_shift                                  (16)
#define  VGIP_FRAMEPACKING_CTRL1_field_alternative_en_shift                      (15)
#define  VGIP_FRAMEPACKING_CTRL1_frame_packing_en_shift                          (13)
#define  VGIP_FRAMEPACKING_CTRL1_vs_position_shift                               (0)
#define  VGIP_FRAMEPACKING_CTRL1_vs_width_mask                                   (0x1FFF0000)
#define  VGIP_FRAMEPACKING_CTRL1_field_alternative_en_mask                       (0x00008000)
#define  VGIP_FRAMEPACKING_CTRL1_frame_packing_en_mask                           (0x00002000)
#define  VGIP_FRAMEPACKING_CTRL1_vs_position_mask                                (0x00001FFF)
#define  VGIP_FRAMEPACKING_CTRL1_vs_width(data)                                  (0x1FFF0000&((data)<<16))
#define  VGIP_FRAMEPACKING_CTRL1_field_alternative_en(data)                      (0x00008000&((data)<<15))
#define  VGIP_FRAMEPACKING_CTRL1_frame_packing_en(data)                          (0x00002000&((data)<<13))
#define  VGIP_FRAMEPACKING_CTRL1_vs_position(data)                               (0x00001FFF&(data))
#define  VGIP_FRAMEPACKING_CTRL1_get_vs_width(data)                              ((0x1FFF0000&(data))>>16)
#define  VGIP_FRAMEPACKING_CTRL1_get_field_alternative_en(data)                  ((0x00008000&(data))>>15)
#define  VGIP_FRAMEPACKING_CTRL1_get_frame_packing_en(data)                      ((0x00002000&(data))>>13)
#define  VGIP_FRAMEPACKING_CTRL1_get_vs_position(data)                           (0x00001FFF&(data))

#define  VGIP_FRAMEPACKING_CTRL2                                                 0x18022280
#define  VGIP_FRAMEPACKING_CTRL2_reg_addr                                        "0xB8022280"
#define  VGIP_FRAMEPACKING_CTRL2_reg                                             0xB8022280
#define  VGIP_FRAMEPACKING_CTRL2_inst_addr                                       "0x001A"
#define  set_VGIP_FRAMEPACKING_CTRL2_reg(data)                                   (*((volatile unsigned int*)VGIP_FRAMEPACKING_CTRL2_reg)=data)
#define  get_VGIP_FRAMEPACKING_CTRL2_reg                                         (*((volatile unsigned int*)VGIP_FRAMEPACKING_CTRL2_reg))
#define  VGIP_FRAMEPACKING_CTRL2_den_mask_start_shift                            (16)
#define  VGIP_FRAMEPACKING_CTRL2_den_mask_end_shift                              (0)
#define  VGIP_FRAMEPACKING_CTRL2_den_mask_start_mask                             (0x1FFF0000)
#define  VGIP_FRAMEPACKING_CTRL2_den_mask_end_mask                               (0x00001FFF)
#define  VGIP_FRAMEPACKING_CTRL2_den_mask_start(data)                            (0x1FFF0000&((data)<<16))
#define  VGIP_FRAMEPACKING_CTRL2_den_mask_end(data)                              (0x00001FFF&(data))
#define  VGIP_FRAMEPACKING_CTRL2_get_den_mask_start(data)                        ((0x1FFF0000&(data))>>16)
#define  VGIP_FRAMEPACKING_CTRL2_get_den_mask_end(data)                          (0x00001FFF&(data))

#define  VGIP_Data_Path_Select                                                   0x18022284
#define  VGIP_Data_Path_Select_reg_addr                                          "0xB8022284"
#define  VGIP_Data_Path_Select_reg                                               0xB8022284
#define  VGIP_Data_Path_Select_inst_addr                                         "0x001B"
#define  set_VGIP_Data_Path_Select_reg(data)                                     (*((volatile unsigned int*)VGIP_Data_Path_Select_reg)=data)
#define  get_VGIP_Data_Path_Select_reg                                           (*((volatile unsigned int*)VGIP_Data_Path_Select_reg))
#define  VGIP_Data_Path_Select_s1_clk_en_shift                                   (13)
#define  VGIP_Data_Path_Select_uzd1_in_sel_shift                                 (10)
#define  VGIP_Data_Path_Select_dummy_1_shift                                     (5)
#define  VGIP_Data_Path_Select_adc_ch_sel_shift                                  (4)
#define  VGIP_Data_Path_Select_xcdi_clk_en_shift                                 (3)
#define  VGIP_Data_Path_Select_di_i_clk_en_shift                                 (2)
#define  VGIP_Data_Path_Select_dummy_2_shift                                     (0)
#define  VGIP_Data_Path_Select_s1_clk_en_mask                                    (0x00002000)
#define  VGIP_Data_Path_Select_uzd1_in_sel_mask                                  (0x00000400)
#define  VGIP_Data_Path_Select_dummy_1_mask                                      (0x000003E0)
#define  VGIP_Data_Path_Select_adc_ch_sel_mask                                   (0x00000010)
#define  VGIP_Data_Path_Select_xcdi_clk_en_mask                                  (0x00000008)
#define  VGIP_Data_Path_Select_di_i_clk_en_mask                                  (0x00000004)
#define  VGIP_Data_Path_Select_dummy_2_mask                                      (0x00000003)
#define  VGIP_Data_Path_Select_s1_clk_en(data)                                   (0x00002000&((data)<<13))
#define  VGIP_Data_Path_Select_uzd1_in_sel(data)                                 (0x00000400&((data)<<10))
#define  VGIP_Data_Path_Select_dummy_1(data)                                     (0x000003E0&((data)<<5))
#define  VGIP_Data_Path_Select_adc_ch_sel(data)                                  (0x00000010&((data)<<4))
#define  VGIP_Data_Path_Select_xcdi_clk_en(data)                                 (0x00000008&((data)<<3))
#define  VGIP_Data_Path_Select_di_i_clk_en(data)                                 (0x00000004&((data)<<2))
#define  VGIP_Data_Path_Select_dummy_2(data)                                     (0x00000003&(data))
#define  VGIP_Data_Path_Select_get_s1_clk_en(data)                               ((0x00002000&(data))>>13)
#define  VGIP_Data_Path_Select_get_uzd1_in_sel(data)                             ((0x00000400&(data))>>10)
#define  VGIP_Data_Path_Select_get_dummy_1(data)                                 ((0x000003E0&(data))>>5)
#define  VGIP_Data_Path_Select_get_adc_ch_sel(data)                              ((0x00000010&(data))>>4)
#define  VGIP_Data_Path_Select_get_xcdi_clk_en(data)                             ((0x00000008&(data))>>3)
#define  VGIP_Data_Path_Select_get_di_i_clk_en(data)                             ((0x00000004&(data))>>2)
#define  VGIP_Data_Path_Select_get_dummy_2(data)                                 (0x00000003&(data))

#define  VGIP_VGIP_VBISLI                                                        0x18022288
#define  VGIP_VGIP_VBISLI_reg_addr                                               "0xB8022288"
#define  VGIP_VGIP_VBISLI_reg                                                    0xB8022288
#define  VGIP_VGIP_VBISLI_inst_addr                                              "0x001C"
#define  set_VGIP_VGIP_VBISLI_reg(data)                                          (*((volatile unsigned int*)VGIP_VGIP_VBISLI_reg)=data)
#define  get_VGIP_VGIP_VBISLI_reg                                                (*((volatile unsigned int*)VGIP_VGIP_VBISLI_reg))
#define  VGIP_VGIP_VBISLI_vbisli_in_sel_shift                                    (29)
#define  VGIP_VGIP_VBISLI_vbisli_ivs_dly_shift                                   (16)
#define  VGIP_VGIP_VBISLI_vbisli_ihs_dly_shift                                   (0)
#define  VGIP_VGIP_VBISLI_vbisli_in_sel_mask                                     (0x60000000)
#define  VGIP_VGIP_VBISLI_vbisli_ivs_dly_mask                                    (0x1FFF0000)
#define  VGIP_VGIP_VBISLI_vbisli_ihs_dly_mask                                    (0x00003FFF)
#define  VGIP_VGIP_VBISLI_vbisli_in_sel(data)                                    (0x60000000&((data)<<29))
#define  VGIP_VGIP_VBISLI_vbisli_ivs_dly(data)                                   (0x1FFF0000&((data)<<16))
#define  VGIP_VGIP_VBISLI_vbisli_ihs_dly(data)                                   (0x00003FFF&(data))
#define  VGIP_VGIP_VBISLI_get_vbisli_in_sel(data)                                ((0x60000000&(data))>>29)
#define  VGIP_VGIP_VBISLI_get_vbisli_ivs_dly(data)                               ((0x1FFF0000&(data))>>16)
#define  VGIP_VGIP_VBISLI_get_vbisli_ihs_dly(data)                               (0x00003FFF&(data))

#define  VGIP_INT_CTL                                                            0x1802228C
#define  VGIP_INT_CTL_reg_addr                                                   "0xB802228C"
#define  VGIP_INT_CTL_reg                                                        0xB802228C
#define  VGIP_INT_CTL_inst_addr                                                  "0x001D"
#define  set_VGIP_INT_CTL_reg(data)                                              (*((volatile unsigned int*)VGIP_INT_CTL_reg)=data)
#define  get_VGIP_INT_CTL_reg                                                    (*((volatile unsigned int*)VGIP_INT_CTL_reg))
#define  VGIP_INT_CTL_onms3_int_ie_shift                                         (9)
#define  VGIP_INT_CTL_offms_int_ie_shift                                         (8)
#define  VGIP_INT_CTL_onms2_int_ie_shift                                         (7)
#define  VGIP_INT_CTL_onms1_int_ie_shift                                         (6)
#define  VGIP_INT_CTL_hist_ch1_int_ie_shift                                      (5)
#define  VGIP_INT_CTL_vgip_int_ie_shift                                          (3)
#define  VGIP_INT_CTL_dispi_int_ie_shift                                         (0)
#define  VGIP_INT_CTL_onms3_int_ie_mask                                          (0x00000200)
#define  VGIP_INT_CTL_offms_int_ie_mask                                          (0x00000100)
#define  VGIP_INT_CTL_onms2_int_ie_mask                                          (0x00000080)
#define  VGIP_INT_CTL_onms1_int_ie_mask                                          (0x00000040)
#define  VGIP_INT_CTL_hist_ch1_int_ie_mask                                       (0x00000020)
#define  VGIP_INT_CTL_vgip_int_ie_mask                                           (0x00000008)
#define  VGIP_INT_CTL_dispi_int_ie_mask                                          (0x00000001)
#define  VGIP_INT_CTL_onms3_int_ie(data)                                         (0x00000200&((data)<<9))
#define  VGIP_INT_CTL_offms_int_ie(data)                                         (0x00000100&((data)<<8))
#define  VGIP_INT_CTL_onms2_int_ie(data)                                         (0x00000080&((data)<<7))
#define  VGIP_INT_CTL_onms1_int_ie(data)                                         (0x00000040&((data)<<6))
#define  VGIP_INT_CTL_hist_ch1_int_ie(data)                                      (0x00000020&((data)<<5))
#define  VGIP_INT_CTL_vgip_int_ie(data)                                          (0x00000008&((data)<<3))
#define  VGIP_INT_CTL_dispi_int_ie(data)                                         (0x00000001&(data))
#define  VGIP_INT_CTL_get_onms3_int_ie(data)                                     ((0x00000200&(data))>>9)
#define  VGIP_INT_CTL_get_offms_int_ie(data)                                     ((0x00000100&(data))>>8)
#define  VGIP_INT_CTL_get_onms2_int_ie(data)                                     ((0x00000080&(data))>>7)
#define  VGIP_INT_CTL_get_onms1_int_ie(data)                                     ((0x00000040&(data))>>6)
#define  VGIP_INT_CTL_get_hist_ch1_int_ie(data)                                  ((0x00000020&(data))>>5)
#define  VGIP_INT_CTL_get_vgip_int_ie(data)                                      ((0x00000008&(data))>>3)
#define  VGIP_INT_CTL_get_dispi_int_ie(data)                                     (0x00000001&(data))

#define  VGIP_CTS_FIFO_CTL                                                       0x18022290
#define  VGIP_CTS_FIFO_CTL_reg_addr                                              "0xB8022290"
#define  VGIP_CTS_FIFO_CTL_reg                                                   0xB8022290
#define  VGIP_CTS_FIFO_CTL_inst_addr                                             "0x001E"
#define  set_VGIP_CTS_FIFO_CTL_reg(data)                                         (*((volatile unsigned int*)VGIP_CTS_FIFO_CTL_reg)=data)
#define  get_VGIP_CTS_FIFO_CTL_reg                                               (*((volatile unsigned int*)VGIP_CTS_FIFO_CTL_reg))
#define  VGIP_CTS_FIFO_CTL_dummy_ctsfifo_sdnr_shift                              (11)
#define  VGIP_CTS_FIFO_CTL_force_ctsfifo_rstn_sdnr_shift                         (10)
#define  VGIP_CTS_FIFO_CTL_en_ctsfifo_vsrst_sdnr_shift                           (9)
#define  VGIP_CTS_FIFO_CTL_en_ctsfifo_bypass_sdnr_shift                          (8)
#define  VGIP_CTS_FIFO_CTL_dummy_ctsfifo_vgip_shift                              (3)
#define  VGIP_CTS_FIFO_CTL_force_ctsfifo_rstn_vgip_shift                         (2)
#define  VGIP_CTS_FIFO_CTL_en_ctsfifo_vsrst_vgip_shift                           (1)
#define  VGIP_CTS_FIFO_CTL_en_ctsfifo_bypass_vgip_shift                          (0)
#define  VGIP_CTS_FIFO_CTL_dummy_ctsfifo_sdnr_mask                               (0x00000800)
#define  VGIP_CTS_FIFO_CTL_force_ctsfifo_rstn_sdnr_mask                          (0x00000400)
#define  VGIP_CTS_FIFO_CTL_en_ctsfifo_vsrst_sdnr_mask                            (0x00000200)
#define  VGIP_CTS_FIFO_CTL_en_ctsfifo_bypass_sdnr_mask                           (0x00000100)
#define  VGIP_CTS_FIFO_CTL_dummy_ctsfifo_vgip_mask                               (0x00000008)
#define  VGIP_CTS_FIFO_CTL_force_ctsfifo_rstn_vgip_mask                          (0x00000004)
#define  VGIP_CTS_FIFO_CTL_en_ctsfifo_vsrst_vgip_mask                            (0x00000002)
#define  VGIP_CTS_FIFO_CTL_en_ctsfifo_bypass_vgip_mask                           (0x00000001)
#define  VGIP_CTS_FIFO_CTL_dummy_ctsfifo_sdnr(data)                              (0x00000800&((data)<<11))
#define  VGIP_CTS_FIFO_CTL_force_ctsfifo_rstn_sdnr(data)                         (0x00000400&((data)<<10))
#define  VGIP_CTS_FIFO_CTL_en_ctsfifo_vsrst_sdnr(data)                           (0x00000200&((data)<<9))
#define  VGIP_CTS_FIFO_CTL_en_ctsfifo_bypass_sdnr(data)                          (0x00000100&((data)<<8))
#define  VGIP_CTS_FIFO_CTL_dummy_ctsfifo_vgip(data)                              (0x00000008&((data)<<3))
#define  VGIP_CTS_FIFO_CTL_force_ctsfifo_rstn_vgip(data)                         (0x00000004&((data)<<2))
#define  VGIP_CTS_FIFO_CTL_en_ctsfifo_vsrst_vgip(data)                           (0x00000002&((data)<<1))
#define  VGIP_CTS_FIFO_CTL_en_ctsfifo_bypass_vgip(data)                          (0x00000001&(data))
#define  VGIP_CTS_FIFO_CTL_get_dummy_ctsfifo_sdnr(data)                          ((0x00000800&(data))>>11)
#define  VGIP_CTS_FIFO_CTL_get_force_ctsfifo_rstn_sdnr(data)                     ((0x00000400&(data))>>10)
#define  VGIP_CTS_FIFO_CTL_get_en_ctsfifo_vsrst_sdnr(data)                       ((0x00000200&(data))>>9)
#define  VGIP_CTS_FIFO_CTL_get_en_ctsfifo_bypass_sdnr(data)                      ((0x00000100&(data))>>8)
#define  VGIP_CTS_FIFO_CTL_get_dummy_ctsfifo_vgip(data)                          ((0x00000008&(data))>>3)
#define  VGIP_CTS_FIFO_CTL_get_force_ctsfifo_rstn_vgip(data)                     ((0x00000004&(data))>>2)
#define  VGIP_CTS_FIFO_CTL_get_en_ctsfifo_vsrst_vgip(data)                       ((0x00000002&(data))>>1)
#define  VGIP_CTS_FIFO_CTL_get_en_ctsfifo_bypass_vgip(data)                      (0x00000001&(data))

#define  VGIP_dispi_test_sel                                                     0x18022294
#define  VGIP_dispi_test_sel_reg_addr                                            "0xB8022294"
#define  VGIP_dispi_test_sel_reg                                                 0xB8022294
#define  VGIP_dispi_test_sel_inst_addr                                           "0x001F"
#define  set_VGIP_dispi_test_sel_reg(data)                                       (*((volatile unsigned int*)VGIP_dispi_test_sel_reg)=data)
#define  get_VGIP_dispi_test_sel_reg                                             (*((volatile unsigned int*)VGIP_dispi_test_sel_reg))
#define  VGIP_dispi_test_sel_disp_testpinsel_shift                               (0)
#define  VGIP_dispi_test_sel_disp_testpinsel_mask                                (0x0000003F)
#define  VGIP_dispi_test_sel_disp_testpinsel(data)                               (0x0000003F&(data))
#define  VGIP_dispi_test_sel_get_disp_testpinsel(data)                           (0x0000003F&(data))

#define  VGIP_VGIP_CHN1_3D_RIGHT_ACT_HSTA_Width                                  0x18022298
#define  VGIP_VGIP_CHN1_3D_RIGHT_ACT_HSTA_Width_reg_addr                         "0xB8022298"
#define  VGIP_VGIP_CHN1_3D_RIGHT_ACT_HSTA_Width_reg                              0xB8022298
#define  VGIP_VGIP_CHN1_3D_RIGHT_ACT_HSTA_Width_inst_addr                        "0x0020"
#define  set_VGIP_VGIP_CHN1_3D_RIGHT_ACT_HSTA_Width_reg(data)                    (*((volatile unsigned int*)VGIP_VGIP_CHN1_3D_RIGHT_ACT_HSTA_Width_reg)=data)
#define  get_VGIP_VGIP_CHN1_3D_RIGHT_ACT_HSTA_Width_reg                          (*((volatile unsigned int*)VGIP_VGIP_CHN1_3D_RIGHT_ACT_HSTA_Width_reg))
#define  VGIP_VGIP_CHN1_3D_RIGHT_ACT_HSTA_Width_ch1_3d_right_ih_act_sta_shift    (16)
#define  VGIP_VGIP_CHN1_3D_RIGHT_ACT_HSTA_Width_ch1_3d_right_ih_act_wid_shift    (0)
#define  VGIP_VGIP_CHN1_3D_RIGHT_ACT_HSTA_Width_ch1_3d_right_ih_act_sta_mask     (0x3FFF0000)
#define  VGIP_VGIP_CHN1_3D_RIGHT_ACT_HSTA_Width_ch1_3d_right_ih_act_wid_mask     (0x00003FFF)
#define  VGIP_VGIP_CHN1_3D_RIGHT_ACT_HSTA_Width_ch1_3d_right_ih_act_sta(data)    (0x3FFF0000&((data)<<16))
#define  VGIP_VGIP_CHN1_3D_RIGHT_ACT_HSTA_Width_ch1_3d_right_ih_act_wid(data)    (0x00003FFF&(data))
#define  VGIP_VGIP_CHN1_3D_RIGHT_ACT_HSTA_Width_get_ch1_3d_right_ih_act_sta(data) ((0x3FFF0000&(data))>>16)
#define  VGIP_VGIP_CHN1_3D_RIGHT_ACT_HSTA_Width_get_ch1_3d_right_ih_act_wid(data) (0x00003FFF&(data))

#define  VGIP_VGIP_CHN1_3D_RIGHT_ACT_VSTA_Length                                 0x1802229C
#define  VGIP_VGIP_CHN1_3D_RIGHT_ACT_VSTA_Length_reg_addr                        "0xB802229C"
#define  VGIP_VGIP_CHN1_3D_RIGHT_ACT_VSTA_Length_reg                             0xB802229C
#define  VGIP_VGIP_CHN1_3D_RIGHT_ACT_VSTA_Length_inst_addr                       "0x0021"
#define  set_VGIP_VGIP_CHN1_3D_RIGHT_ACT_VSTA_Length_reg(data)                   (*((volatile unsigned int*)VGIP_VGIP_CHN1_3D_RIGHT_ACT_VSTA_Length_reg)=data)
#define  get_VGIP_VGIP_CHN1_3D_RIGHT_ACT_VSTA_Length_reg                         (*((volatile unsigned int*)VGIP_VGIP_CHN1_3D_RIGHT_ACT_VSTA_Length_reg))
#define  VGIP_VGIP_CHN1_3D_RIGHT_ACT_VSTA_Length_ch1_3d_right_iv_act_sta_shift   (16)
#define  VGIP_VGIP_CHN1_3D_RIGHT_ACT_VSTA_Length_ch1_3d_right_iv_act_len_shift   (0)
#define  VGIP_VGIP_CHN1_3D_RIGHT_ACT_VSTA_Length_ch1_3d_right_iv_act_sta_mask    (0x1FFF0000)
#define  VGIP_VGIP_CHN1_3D_RIGHT_ACT_VSTA_Length_ch1_3d_right_iv_act_len_mask    (0x00001FFF)
#define  VGIP_VGIP_CHN1_3D_RIGHT_ACT_VSTA_Length_ch1_3d_right_iv_act_sta(data)   (0x1FFF0000&((data)<<16))
#define  VGIP_VGIP_CHN1_3D_RIGHT_ACT_VSTA_Length_ch1_3d_right_iv_act_len(data)   (0x00001FFF&(data))
#define  VGIP_VGIP_CHN1_3D_RIGHT_ACT_VSTA_Length_get_ch1_3d_right_iv_act_sta(data) ((0x1FFF0000&(data))>>16)
#define  VGIP_VGIP_CHN1_3D_RIGHT_ACT_VSTA_Length_get_ch1_3d_right_iv_act_len(data) (0x00001FFF&(data))

#define  VGIP_FRAMEPACKING_INTERLACE_CTRL1                                       0x180222A8
#define  VGIP_FRAMEPACKING_INTERLACE_CTRL1_reg_addr                              "0xB80222A8"
#define  VGIP_FRAMEPACKING_INTERLACE_CTRL1_reg                                   0xB80222A8
#define  VGIP_FRAMEPACKING_INTERLACE_CTRL1_inst_addr                             "0x0022"
#define  set_VGIP_FRAMEPACKING_INTERLACE_CTRL1_reg(data)                         (*((volatile unsigned int*)VGIP_FRAMEPACKING_INTERLACE_CTRL1_reg)=data)
#define  get_VGIP_FRAMEPACKING_INTERLACE_CTRL1_reg                               (*((volatile unsigned int*)VGIP_FRAMEPACKING_INTERLACE_CTRL1_reg))
#define  VGIP_FRAMEPACKING_INTERLACE_CTRL1_vs_width_r_odd_shift                  (16)
#define  VGIP_FRAMEPACKING_INTERLACE_CTRL1_frame_packing_field_en_shift          (13)
#define  VGIP_FRAMEPACKING_INTERLACE_CTRL1_vs_position_r_odd_shift               (0)
#define  VGIP_FRAMEPACKING_INTERLACE_CTRL1_vs_width_r_odd_mask                   (0x1FFF0000)
#define  VGIP_FRAMEPACKING_INTERLACE_CTRL1_frame_packing_field_en_mask           (0x00002000)
#define  VGIP_FRAMEPACKING_INTERLACE_CTRL1_vs_position_r_odd_mask                (0x00001FFF)
#define  VGIP_FRAMEPACKING_INTERLACE_CTRL1_vs_width_r_odd(data)                  (0x1FFF0000&((data)<<16))
#define  VGIP_FRAMEPACKING_INTERLACE_CTRL1_frame_packing_field_en(data)          (0x00002000&((data)<<13))
#define  VGIP_FRAMEPACKING_INTERLACE_CTRL1_vs_position_r_odd(data)               (0x00001FFF&(data))
#define  VGIP_FRAMEPACKING_INTERLACE_CTRL1_get_vs_width_r_odd(data)              ((0x1FFF0000&(data))>>16)
#define  VGIP_FRAMEPACKING_INTERLACE_CTRL1_get_frame_packing_field_en(data)      ((0x00002000&(data))>>13)
#define  VGIP_FRAMEPACKING_INTERLACE_CTRL1_get_vs_position_r_odd(data)           (0x00001FFF&(data))

#define  VGIP_FRAMEPACKING_INTERLACE_CTRL2                                       0x180222AC
#define  VGIP_FRAMEPACKING_INTERLACE_CTRL2_reg_addr                              "0xB80222AC"
#define  VGIP_FRAMEPACKING_INTERLACE_CTRL2_reg                                   0xB80222AC
#define  VGIP_FRAMEPACKING_INTERLACE_CTRL2_inst_addr                             "0x0023"
#define  set_VGIP_FRAMEPACKING_INTERLACE_CTRL2_reg(data)                         (*((volatile unsigned int*)VGIP_FRAMEPACKING_INTERLACE_CTRL2_reg)=data)
#define  get_VGIP_FRAMEPACKING_INTERLACE_CTRL2_reg                               (*((volatile unsigned int*)VGIP_FRAMEPACKING_INTERLACE_CTRL2_reg))
#define  VGIP_FRAMEPACKING_INTERLACE_CTRL2_den_mask_start_r_odd_shift            (16)
#define  VGIP_FRAMEPACKING_INTERLACE_CTRL2_den_mask_end_r_odd_shift              (0)
#define  VGIP_FRAMEPACKING_INTERLACE_CTRL2_den_mask_start_r_odd_mask             (0x1FFF0000)
#define  VGIP_FRAMEPACKING_INTERLACE_CTRL2_den_mask_end_r_odd_mask               (0x00001FFF)
#define  VGIP_FRAMEPACKING_INTERLACE_CTRL2_den_mask_start_r_odd(data)            (0x1FFF0000&((data)<<16))
#define  VGIP_FRAMEPACKING_INTERLACE_CTRL2_den_mask_end_r_odd(data)              (0x00001FFF&(data))
#define  VGIP_FRAMEPACKING_INTERLACE_CTRL2_get_den_mask_start_r_odd(data)        ((0x1FFF0000&(data))>>16)
#define  VGIP_FRAMEPACKING_INTERLACE_CTRL2_get_den_mask_end_r_odd(data)          (0x00001FFF&(data))

#define  VGIP_FRAMEPACKING_INTERLACE_CTRL3                                       0x180222B0
#define  VGIP_FRAMEPACKING_INTERLACE_CTRL3_reg_addr                              "0xB80222B0"
#define  VGIP_FRAMEPACKING_INTERLACE_CTRL3_reg                                   0xB80222B0
#define  VGIP_FRAMEPACKING_INTERLACE_CTRL3_inst_addr                             "0x0024"
#define  set_VGIP_FRAMEPACKING_INTERLACE_CTRL3_reg(data)                         (*((volatile unsigned int*)VGIP_FRAMEPACKING_INTERLACE_CTRL3_reg)=data)
#define  get_VGIP_FRAMEPACKING_INTERLACE_CTRL3_reg                               (*((volatile unsigned int*)VGIP_FRAMEPACKING_INTERLACE_CTRL3_reg))
#define  VGIP_FRAMEPACKING_INTERLACE_CTRL3_vs_width_r_even_shift                 (16)
#define  VGIP_FRAMEPACKING_INTERLACE_CTRL3_vs_position_r_even_shift              (0)
#define  VGIP_FRAMEPACKING_INTERLACE_CTRL3_vs_width_r_even_mask                  (0x1FFF0000)
#define  VGIP_FRAMEPACKING_INTERLACE_CTRL3_vs_position_r_even_mask               (0x00001FFF)
#define  VGIP_FRAMEPACKING_INTERLACE_CTRL3_vs_width_r_even(data)                 (0x1FFF0000&((data)<<16))
#define  VGIP_FRAMEPACKING_INTERLACE_CTRL3_vs_position_r_even(data)              (0x00001FFF&(data))
#define  VGIP_FRAMEPACKING_INTERLACE_CTRL3_get_vs_width_r_even(data)             ((0x1FFF0000&(data))>>16)
#define  VGIP_FRAMEPACKING_INTERLACE_CTRL3_get_vs_position_r_even(data)          (0x00001FFF&(data))

#define  VGIP_FRAMEPACKING_INTERLACE_CTRL4                                       0x180222B4
#define  VGIP_FRAMEPACKING_INTERLACE_CTRL4_reg_addr                              "0xB80222B4"
#define  VGIP_FRAMEPACKING_INTERLACE_CTRL4_reg                                   0xB80222B4
#define  VGIP_FRAMEPACKING_INTERLACE_CTRL4_inst_addr                             "0x0025"
#define  set_VGIP_FRAMEPACKING_INTERLACE_CTRL4_reg(data)                         (*((volatile unsigned int*)VGIP_FRAMEPACKING_INTERLACE_CTRL4_reg)=data)
#define  get_VGIP_FRAMEPACKING_INTERLACE_CTRL4_reg                               (*((volatile unsigned int*)VGIP_FRAMEPACKING_INTERLACE_CTRL4_reg))
#define  VGIP_FRAMEPACKING_INTERLACE_CTRL4_den_mask_start_r_even_shift           (16)
#define  VGIP_FRAMEPACKING_INTERLACE_CTRL4_den_mask_end_r_even_shift             (0)
#define  VGIP_FRAMEPACKING_INTERLACE_CTRL4_den_mask_start_r_even_mask            (0x1FFF0000)
#define  VGIP_FRAMEPACKING_INTERLACE_CTRL4_den_mask_end_r_even_mask              (0x00001FFF)
#define  VGIP_FRAMEPACKING_INTERLACE_CTRL4_den_mask_start_r_even(data)           (0x1FFF0000&((data)<<16))
#define  VGIP_FRAMEPACKING_INTERLACE_CTRL4_den_mask_end_r_even(data)             (0x00001FFF&(data))
#define  VGIP_FRAMEPACKING_INTERLACE_CTRL4_get_den_mask_start_r_even(data)       ((0x1FFF0000&(data))>>16)
#define  VGIP_FRAMEPACKING_INTERLACE_CTRL4_get_den_mask_end_r_even(data)         (0x00001FFF&(data))

#define  VGIP_L_R_ACTIVE_ENABLE_CTRL1                                            0x180222B8
#define  VGIP_L_R_ACTIVE_ENABLE_CTRL1_reg_addr                                   "0xB80222B8"
#define  VGIP_L_R_ACTIVE_ENABLE_CTRL1_reg                                        0xB80222B8
#define  VGIP_L_R_ACTIVE_ENABLE_CTRL1_inst_addr                                  "0x0026"
#define  set_VGIP_L_R_ACTIVE_ENABLE_CTRL1_reg(data)                              (*((volatile unsigned int*)VGIP_L_R_ACTIVE_ENABLE_CTRL1_reg)=data)
#define  get_VGIP_L_R_ACTIVE_ENABLE_CTRL1_reg                                    (*((volatile unsigned int*)VGIP_L_R_ACTIVE_ENABLE_CTRL1_reg))
#define  VGIP_L_R_ACTIVE_ENABLE_CTRL1_end_l_shift                                (16)
#define  VGIP_L_R_ACTIVE_ENABLE_CTRL1_sta_l_shift                                (0)
#define  VGIP_L_R_ACTIVE_ENABLE_CTRL1_end_l_mask                                 (0x3FFF0000)
#define  VGIP_L_R_ACTIVE_ENABLE_CTRL1_sta_l_mask                                 (0x00003FFF)
#define  VGIP_L_R_ACTIVE_ENABLE_CTRL1_end_l(data)                                (0x3FFF0000&((data)<<16))
#define  VGIP_L_R_ACTIVE_ENABLE_CTRL1_sta_l(data)                                (0x00003FFF&(data))
#define  VGIP_L_R_ACTIVE_ENABLE_CTRL1_get_end_l(data)                            ((0x3FFF0000&(data))>>16)
#define  VGIP_L_R_ACTIVE_ENABLE_CTRL1_get_sta_l(data)                            (0x00003FFF&(data))

#define  VGIP_L_R_ACTIVE_ENABLE_CTRL2                                            0x180222BC
#define  VGIP_L_R_ACTIVE_ENABLE_CTRL2_reg_addr                                   "0xB80222BC"
#define  VGIP_L_R_ACTIVE_ENABLE_CTRL2_reg                                        0xB80222BC
#define  VGIP_L_R_ACTIVE_ENABLE_CTRL2_inst_addr                                  "0x0027"
#define  set_VGIP_L_R_ACTIVE_ENABLE_CTRL2_reg(data)                              (*((volatile unsigned int*)VGIP_L_R_ACTIVE_ENABLE_CTRL2_reg)=data)
#define  get_VGIP_L_R_ACTIVE_ENABLE_CTRL2_reg                                    (*((volatile unsigned int*)VGIP_L_R_ACTIVE_ENABLE_CTRL2_reg))
#define  VGIP_L_R_ACTIVE_ENABLE_CTRL2_l_r_act_en_shift                           (31)
#define  VGIP_L_R_ACTIVE_ENABLE_CTRL2_h_v_mode_shift                             (30)
#define  VGIP_L_R_ACTIVE_ENABLE_CTRL2_end_r_shift                                (16)
#define  VGIP_L_R_ACTIVE_ENABLE_CTRL2_sta_r_shift                                (0)
#define  VGIP_L_R_ACTIVE_ENABLE_CTRL2_l_r_act_en_mask                            (0x80000000)
#define  VGIP_L_R_ACTIVE_ENABLE_CTRL2_h_v_mode_mask                              (0x40000000)
#define  VGIP_L_R_ACTIVE_ENABLE_CTRL2_end_r_mask                                 (0x3FFF0000)
#define  VGIP_L_R_ACTIVE_ENABLE_CTRL2_sta_r_mask                                 (0x00003FFF)
#define  VGIP_L_R_ACTIVE_ENABLE_CTRL2_l_r_act_en(data)                           (0x80000000&((data)<<31))
#define  VGIP_L_R_ACTIVE_ENABLE_CTRL2_h_v_mode(data)                             (0x40000000&((data)<<30))
#define  VGIP_L_R_ACTIVE_ENABLE_CTRL2_end_r(data)                                (0x3FFF0000&((data)<<16))
#define  VGIP_L_R_ACTIVE_ENABLE_CTRL2_sta_r(data)                                (0x00003FFF&(data))
#define  VGIP_L_R_ACTIVE_ENABLE_CTRL2_get_l_r_act_en(data)                       ((0x80000000&(data))>>31)
#define  VGIP_L_R_ACTIVE_ENABLE_CTRL2_get_h_v_mode(data)                         ((0x40000000&(data))>>30)
#define  VGIP_L_R_ACTIVE_ENABLE_CTRL2_get_end_r(data)                            ((0x3FFF0000&(data))>>16)
#define  VGIP_L_R_ACTIVE_ENABLE_CTRL2_get_sta_r(data)                            (0x00003FFF&(data))

#define  VGIP_DISPI_IRQ_RECORD                                                   0x180222F0
#define  VGIP_DISPI_IRQ_RECORD_reg_addr                                          "0xB80222F0"
#define  VGIP_DISPI_IRQ_RECORD_reg                                               0xB80222F0
#define  VGIP_DISPI_IRQ_RECORD_inst_addr                                         "0x0028"
#define  set_VGIP_DISPI_IRQ_RECORD_reg(data)                                     (*((volatile unsigned int*)VGIP_DISPI_IRQ_RECORD_reg)=data)
#define  get_VGIP_DISPI_IRQ_RECORD_reg                                           (*((volatile unsigned int*)VGIP_DISPI_IRQ_RECORD_reg))
#define  VGIP_DISPI_IRQ_RECORD_onms_3_irq_record_shift                           (13)
#define  VGIP_DISPI_IRQ_RECORD_dexc_irq_record_shift                             (11)
#define  VGIP_DISPI_IRQ_RECORD_adc_irq_record_shift                              (10)
#define  VGIP_DISPI_IRQ_RECORD_sync_auto_2_irq_record_shift                      (9)
#define  VGIP_DISPI_IRQ_RECORD_sync_auto_1_irq_record_shift                      (8)
#define  VGIP_DISPI_IRQ_RECORD_sync_processor_irq_record_shift                   (7)
#define  VGIP_DISPI_IRQ_RECORD_hist_irq_record_shift                             (6)
#define  VGIP_DISPI_IRQ_RECORD_vgip_irq_record_shift                             (5)
#define  VGIP_DISPI_IRQ_RECORD_offms_irq_record_shift                            (4)
#define  VGIP_DISPI_IRQ_RECORD_onms_2_irq_record_shift                           (3)
#define  VGIP_DISPI_IRQ_RECORD_onms_1_irq_record_shift                           (2)
#define  VGIP_DISPI_IRQ_RECORD_i3ddma_irq_record_shift                           (1)
#define  VGIP_DISPI_IRQ_RECORD_ccdinr_irq_record_shift                           (0)
#define  VGIP_DISPI_IRQ_RECORD_onms_3_irq_record_mask                            (0x00002000)
#define  VGIP_DISPI_IRQ_RECORD_dexc_irq_record_mask                              (0x00000800)
#define  VGIP_DISPI_IRQ_RECORD_adc_irq_record_mask                               (0x00000400)
#define  VGIP_DISPI_IRQ_RECORD_sync_auto_2_irq_record_mask                       (0x00000200)
#define  VGIP_DISPI_IRQ_RECORD_sync_auto_1_irq_record_mask                       (0x00000100)
#define  VGIP_DISPI_IRQ_RECORD_sync_processor_irq_record_mask                    (0x00000080)
#define  VGIP_DISPI_IRQ_RECORD_hist_irq_record_mask                              (0x00000040)
#define  VGIP_DISPI_IRQ_RECORD_vgip_irq_record_mask                              (0x00000020)
#define  VGIP_DISPI_IRQ_RECORD_offms_irq_record_mask                             (0x00000010)
#define  VGIP_DISPI_IRQ_RECORD_onms_2_irq_record_mask                            (0x00000008)
#define  VGIP_DISPI_IRQ_RECORD_onms_1_irq_record_mask                            (0x00000004)
#define  VGIP_DISPI_IRQ_RECORD_i3ddma_irq_record_mask                            (0x00000002)
#define  VGIP_DISPI_IRQ_RECORD_ccdinr_irq_record_mask                            (0x00000001)
#define  VGIP_DISPI_IRQ_RECORD_onms_3_irq_record(data)                           (0x00002000&((data)<<13))
#define  VGIP_DISPI_IRQ_RECORD_dexc_irq_record(data)                             (0x00000800&((data)<<11))
#define  VGIP_DISPI_IRQ_RECORD_adc_irq_record(data)                              (0x00000400&((data)<<10))
#define  VGIP_DISPI_IRQ_RECORD_sync_auto_2_irq_record(data)                      (0x00000200&((data)<<9))
#define  VGIP_DISPI_IRQ_RECORD_sync_auto_1_irq_record(data)                      (0x00000100&((data)<<8))
#define  VGIP_DISPI_IRQ_RECORD_sync_processor_irq_record(data)                   (0x00000080&((data)<<7))
#define  VGIP_DISPI_IRQ_RECORD_hist_irq_record(data)                             (0x00000040&((data)<<6))
#define  VGIP_DISPI_IRQ_RECORD_vgip_irq_record(data)                             (0x00000020&((data)<<5))
#define  VGIP_DISPI_IRQ_RECORD_offms_irq_record(data)                            (0x00000010&((data)<<4))
#define  VGIP_DISPI_IRQ_RECORD_onms_2_irq_record(data)                           (0x00000008&((data)<<3))
#define  VGIP_DISPI_IRQ_RECORD_onms_1_irq_record(data)                           (0x00000004&((data)<<2))
#define  VGIP_DISPI_IRQ_RECORD_i3ddma_irq_record(data)                           (0x00000002&((data)<<1))
#define  VGIP_DISPI_IRQ_RECORD_ccdinr_irq_record(data)                           (0x00000001&(data))
#define  VGIP_DISPI_IRQ_RECORD_get_onms_3_irq_record(data)                       ((0x00002000&(data))>>13)
#define  VGIP_DISPI_IRQ_RECORD_get_dexc_irq_record(data)                         ((0x00000800&(data))>>11)
#define  VGIP_DISPI_IRQ_RECORD_get_adc_irq_record(data)                          ((0x00000400&(data))>>10)
#define  VGIP_DISPI_IRQ_RECORD_get_sync_auto_2_irq_record(data)                  ((0x00000200&(data))>>9)
#define  VGIP_DISPI_IRQ_RECORD_get_sync_auto_1_irq_record(data)                  ((0x00000100&(data))>>8)
#define  VGIP_DISPI_IRQ_RECORD_get_sync_processor_irq_record(data)               ((0x00000080&(data))>>7)
#define  VGIP_DISPI_IRQ_RECORD_get_hist_irq_record(data)                         ((0x00000040&(data))>>6)
#define  VGIP_DISPI_IRQ_RECORD_get_vgip_irq_record(data)                         ((0x00000020&(data))>>5)
#define  VGIP_DISPI_IRQ_RECORD_get_offms_irq_record(data)                        ((0x00000010&(data))>>4)
#define  VGIP_DISPI_IRQ_RECORD_get_onms_2_irq_record(data)                       ((0x00000008&(data))>>3)
#define  VGIP_DISPI_IRQ_RECORD_get_onms_1_irq_record(data)                       ((0x00000004&(data))>>2)
#define  VGIP_DISPI_IRQ_RECORD_get_i3ddma_irq_record(data)                       ((0x00000002&(data))>>1)
#define  VGIP_DISPI_IRQ_RECORD_get_ccdinr_irq_record(data)                       (0x00000001&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======VGIP register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  ip_switch_no_eco:1;
        RBus_UInt32  main_imd_sm_to_gdma:1;
        RBus_UInt32  res2:6;
        RBus_UInt32  main_iv2dv_sm_apply_auto_sel:1;
        RBus_UInt32  main_imd_smooth_toggle_clk_time2switch_en:1;
        RBus_UInt32  main_imd_smooth_toggle_style:2;
        RBus_UInt32  main_imd_smooth_toggle_apply:1;
    };
}vgip_smooth_tog_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_rtnr_progressive_clk_mux:1;
        RBus_UInt32  res1:26;
        RBus_UInt32  vo1_reg_is_db:1;
        RBus_UInt32  main_vgip_reg_is_db:1;
        RBus_UInt32  di_reg_is_db:1;
        RBus_UInt32  i_edge_smooth_reg_is_db:1;
        RBus_UInt32  main_uzd_reg_is_db:1;
    };
}vgip_smooth_tog_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  v8_dummy:8;
        RBus_UInt32  res2:7;
        RBus_UInt32  ch1_select_duplicate_lsb:1;
    };
}vgip_v8_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  auto_l_flag_delay_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  vs_rise_sample_delay_sel:1;
        RBus_UInt32  auto_l_flag_delay_num:13;
        RBus_UInt32  l_flag_delay_en:1;
        RBus_UInt32  l_flag_field_sample_delay:2;
        RBus_UInt32  l_flag_delay_num:13;
    };
}vgip_vgip_global_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_ivrun:1;
        RBus_UInt32  ch1_in_sel:3;
        RBus_UInt32  ch1_random_en:1;
        RBus_UInt32  ch1_fdrop_en:1;
        RBus_UInt32  ch1_vact_end_ie:1;
        RBus_UInt32  ch1_vact_start_ie:1;
        RBus_UInt32  ch1_field_hs_inv:1;
        RBus_UInt32  ch1_field_vd_inv:1;
        RBus_UInt32  ch1_field_vd_en:1;
        RBus_UInt32  ch1_3dleft_inv:1;
        RBus_UInt32  ch1_3dleft_sync_edge:1;
        RBus_UInt32  ch1_field_inv:1;
        RBus_UInt32  ch1_field_sync_edge:1;
        RBus_UInt32  ch1_field_det_en:1;
        RBus_UInt32  ch1_hpact_is_hact:1;
        RBus_UInt32  ch1_fcap_str_odd:1;
        RBus_UInt32  ch1_mask_den_inv:1;
        RBus_UInt32  ch1_mask_den_1l:1;
        RBus_UInt32  ch1_3d_mode_en:1;
        RBus_UInt32  ch1_safe_field_inv:1;
        RBus_UInt32  ch1_force_tog:1;
        RBus_UInt32  ch1_safe_mode:1;
        RBus_UInt32  ch1_3d_right_act_en:1;
        RBus_UInt32  ch1_hs_syncedge:1;
        RBus_UInt32  ch1_vs_syncedge:1;
        RBus_UInt32  ch1_vs_by_hs_en_n:1;
        RBus_UInt32  ch1_vs_inv:1;
        RBus_UInt32  ch1_hs_inv:1;
        RBus_UInt32  ch1_digital_mode:1;
        RBus_UInt32  ch1_in_clk_en:1;
    };
}vgip_vgip_chn1_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  ch1_vs_end:1;
        RBus_UInt32  ch1_vs_start:1;
        RBus_UInt32  ch1_vact_end:1;
        RBus_UInt32  ch1_vact_start:1;
        RBus_UInt32  dummy18022214_23_17:7;
        RBus_UInt32  ch1_vlc_status:1;
        RBus_UInt32  ch1_rl_err:1;
        RBus_UInt32  ch1_vs_err:1;
        RBus_UInt32  ch1_hs_err:1;
        RBus_UInt32  ch1_field_err:1;
        RBus_UInt32  ch1_rl_tog:1;
        RBus_UInt32  ch1_l_flag_pol:1;
        RBus_UInt32  ch1_vs_tog:1;
        RBus_UInt32  ch1_hs_tog:1;
        RBus_UInt32  ch1_field_pol:1;
        RBus_UInt32  ch1_field_tog:1;
        RBus_UInt32  ch1_field_vs_lsb:2;
        RBus_UInt32  ch1_more_1line_field:1;
        RBus_UInt32  ch1_bounce_status_2:1;
        RBus_UInt32  ch1_bounce_status_1:1;
        RBus_UInt32  ch1_bounce_status_0:1;
    };
}vgip_vgip_chn1_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_db_rdy:1;
        RBus_UInt32  ch1_db_en:1;
        RBus_UInt32  res1:14;
        RBus_UInt32  ch1_db_read_sel:1;
        RBus_UInt32  res2:15;
    };
}vgip_vgip_chn1_double_buffer_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ch1_ih_act_sta:14;
        RBus_UInt32  res2:1;
        RBus_UInt32  ch1_bypass_den:1;
        RBus_UInt32  ch1_ih_act_wid:14;
    };
}vgip_vgip_chn1_act_hsta_width_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  ch1_iv_act_sta:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  ch1_iv_act_len:13;
    };
}vgip_vgip_chn1_act_vsta_length_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_hs_width:2;
        RBus_UInt32  ch1_ihs_dly:14;
        RBus_UInt32  res1:3;
        RBus_UInt32  ch1_ivs_dly:13;
    };
}vgip_vgip_chn1_delay_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_de_mask_en:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  ch1_vs_dly_1hs:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  ch1_hporch_num_sel:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  l_flag_force_tog:1;
        RBus_UInt32  ch1_hporch_num:13;
        RBus_UInt32  ch1_auto_ihs_dly:2;
        RBus_UInt32  ch1_auto_ivs_dly:2;
        RBus_UInt32  ch1_hdly_one:1;
        RBus_UInt32  ch1_v1_v2_swap:1;
        RBus_UInt32  ch1_v2_v3_swap:1;
        RBus_UInt32  ch1_v1_v3_swap:1;
    };
}vgip_vgip_chn1_misc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_captst_en:1;
        RBus_UInt32  ch1_captst_mode:2;
        RBus_UInt32  ch1_vcaptst_num:13;
        RBus_UInt32  ch1_captst_field_sel:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  ch1_hcaptst_num:14;
    };
}vgip_vgip_chn1_ptn_h_vi_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  ch1_captst_r_data:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  ch1_captst_g_data:12;
    };
}vgip_vgip_chn1_ptn0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ch1_hporch_num_sel:14;
        RBus_UInt32  res2:4;
        RBus_UInt32  ch1_captst_b_data:12;
    };
}vgip_vgip_chn1_ptn1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_vlcen:1;
        RBus_UInt32  ch1_vlc_mode:1;
        RBus_UInt32  ch1_vlc_ie:1;
        RBus_UInt32  den_crc_sel:1;
        RBus_UInt32  res1:4;
        RBus_UInt32  ch1_line_cnt:12;
        RBus_UInt32  ch1_vln:12;
    };
}vgip_vgip_chn1_lc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  ch1_crc_mode:1;
        RBus_UInt32  ch1_crc_region:1;
        RBus_UInt32  ch1_crc_ctrl_in:1;
        RBus_UInt32  ch1_crc_field_edge_sel:1;
        RBus_UInt32  ch1_crc_field:1;
        RBus_UInt32  ch1_crc_conti:1;
        RBus_UInt32  ch1_crc_start:1;
    };
}vgip_ich1_vgip_crc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_crc_result:32;
    };
}vgip_ich1_vgip_crc_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_wd_to_main:1;
        RBus_UInt32  dummy3:12;
        RBus_UInt32  ch1_vs_err_wde:1;
        RBus_UInt32  ch1_hs_err_wde:1;
        RBus_UInt32  ch1_field_err_wde:1;
        RBus_UInt32  ch1_rl_err_wde:1;
        RBus_UInt32  dummy4:11;
        RBus_UInt32  ch1_rl_err_ie:1;
        RBus_UInt32  ch1_vs_err_ie:1;
        RBus_UInt32  ch1_hs_err_ie:1;
        RBus_UInt32  ch1_field_err_ie:1;
    };
}vgip_vgip_chn1_wde_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  ch1_pr_l_r_only_mask_hs:1;
        RBus_UInt32  ch1_pr_l_r_only_rm_den:1;
        RBus_UInt32  ch1_pr_l_r_only_en:1;
    };
}vgip_pr_l_r_only_ctrl_ch1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  ch1_captst_r_data_2:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  ch1_captst_g_data_2:12;
    };
}vgip_vgip_chn1_ptn2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  ch1_captst_b_data_3:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  ch1_captst_b_data_2:12;
    };
}vgip_vgip_chn1_ptn3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  ch1_captst_r_data_3:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  ch1_captst_g_data_3:12;
    };
}vgip_vgip_chn1_ptn4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  ch1_captst_r_data_4:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  ch1_captst_g_data_4:12;
    };
}vgip_vgip_chn1_ptn5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  ch1_captst_b_data_4:12;
    };
}vgip_vgip_chn1_ptn6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  adc_test_dma_count:28;
        RBus_UInt32  res1:1;
        RBus_UInt32  force_den:1;
        RBus_UInt32  force_vsync:1;
        RBus_UInt32  adc_test_dma_mode:1;
    };
}vgip_adc_raw_data_dma_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  vs_width:13;
        RBus_UInt32  field_alternative_en:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  frame_packing_en:1;
        RBus_UInt32  vs_position:13;
    };
}vgip_framepacking_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  den_mask_start:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  den_mask_end:13;
    };
}vgip_framepacking_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  s1_clk_en:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  uzd1_in_sel:1;
        RBus_UInt32  dummy_1:5;
        RBus_UInt32  adc_ch_sel:1;
        RBus_UInt32  xcdi_clk_en:1;
        RBus_UInt32  di_i_clk_en:1;
        RBus_UInt32  dummy_2:2;
    };
}vgip_data_path_select_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  vbisli_in_sel:2;
        RBus_UInt32  vbisli_ivs_dly:13;
        RBus_UInt32  res2:2;
        RBus_UInt32  vbisli_ihs_dly:14;
    };
}vgip_vgip_vbisli_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  onms3_int_ie:1;
        RBus_UInt32  offms_int_ie:1;
        RBus_UInt32  onms2_int_ie:1;
        RBus_UInt32  onms1_int_ie:1;
        RBus_UInt32  hist_ch1_int_ie:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  vgip_int_ie:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  dispi_int_ie:1;
    };
}vgip_int_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  dummy_ctsfifo_sdnr:1;
        RBus_UInt32  force_ctsfifo_rstn_sdnr:1;
        RBus_UInt32  en_ctsfifo_vsrst_sdnr:1;
        RBus_UInt32  en_ctsfifo_bypass_sdnr:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  dummy_ctsfifo_vgip:1;
        RBus_UInt32  force_ctsfifo_rstn_vgip:1;
        RBus_UInt32  en_ctsfifo_vsrst_vgip:1;
        RBus_UInt32  en_ctsfifo_bypass_vgip:1;
    };
}vgip_cts_fifo_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  disp_testpinsel:6;
    };
}vgip_dispi_test_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ch1_3d_right_ih_act_sta:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  ch1_3d_right_ih_act_wid:14;
    };
}vgip_vgip_chn1_3d_right_act_hsta_width_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  ch1_3d_right_iv_act_sta:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  ch1_3d_right_iv_act_len:13;
    };
}vgip_vgip_chn1_3d_right_act_vsta_length_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  vs_width_r_odd:13;
        RBus_UInt32  res2:2;
        RBus_UInt32  frame_packing_field_en:1;
        RBus_UInt32  vs_position_r_odd:13;
    };
}vgip_framepacking_interlace_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  den_mask_start_r_odd:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  den_mask_end_r_odd:13;
    };
}vgip_framepacking_interlace_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  vs_width_r_even:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  vs_position_r_even:13;
    };
}vgip_framepacking_interlace_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  den_mask_start_r_even:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  den_mask_end_r_even:13;
    };
}vgip_framepacking_interlace_ctrl4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  end_l:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  sta_l:14;
    };
}vgip_l_r_active_enable_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  l_r_act_en:1;
        RBus_UInt32  h_v_mode:1;
        RBus_UInt32  end_r:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  sta_r:14;
    };
}vgip_l_r_active_enable_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  onms_3_irq_record:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  dexc_irq_record:1;
        RBus_UInt32  adc_irq_record:1;
        RBus_UInt32  sync_auto_2_irq_record:1;
        RBus_UInt32  sync_auto_1_irq_record:1;
        RBus_UInt32  sync_processor_irq_record:1;
        RBus_UInt32  hist_irq_record:1;
        RBus_UInt32  vgip_irq_record:1;
        RBus_UInt32  offms_irq_record:1;
        RBus_UInt32  onms_2_irq_record:1;
        RBus_UInt32  onms_1_irq_record:1;
        RBus_UInt32  i3ddma_irq_record:1;
        RBus_UInt32  ccdinr_irq_record:1;
    };
}vgip_dispi_irq_record_RBUS;

#else //apply LITTLE_ENDIAN

//======VGIP register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  main_imd_smooth_toggle_apply:1;
        RBus_UInt32  main_imd_smooth_toggle_style:2;
        RBus_UInt32  main_imd_smooth_toggle_clk_time2switch_en:1;
        RBus_UInt32  main_iv2dv_sm_apply_auto_sel:1;
        RBus_UInt32  res1:6;
        RBus_UInt32  main_imd_sm_to_gdma:1;
        RBus_UInt32  ip_switch_no_eco:1;
        RBus_UInt32  res2:19;
    };
}vgip_smooth_tog_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  main_uzd_reg_is_db:1;
        RBus_UInt32  i_edge_smooth_reg_is_db:1;
        RBus_UInt32  di_reg_is_db:1;
        RBus_UInt32  main_vgip_reg_is_db:1;
        RBus_UInt32  vo1_reg_is_db:1;
        RBus_UInt32  res1:26;
        RBus_UInt32  cp_rtnr_progressive_clk_mux:1;
    };
}vgip_smooth_tog_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_select_duplicate_lsb:1;
        RBus_UInt32  res1:7;
        RBus_UInt32  v8_dummy:8;
        RBus_UInt32  res2:16;
    };
}vgip_v8_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  l_flag_delay_num:13;
        RBus_UInt32  l_flag_field_sample_delay:2;
        RBus_UInt32  l_flag_delay_en:1;
        RBus_UInt32  auto_l_flag_delay_num:13;
        RBus_UInt32  vs_rise_sample_delay_sel:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  auto_l_flag_delay_en:1;
    };
}vgip_vgip_global_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_in_clk_en:1;
        RBus_UInt32  ch1_digital_mode:1;
        RBus_UInt32  ch1_hs_inv:1;
        RBus_UInt32  ch1_vs_inv:1;
        RBus_UInt32  ch1_vs_by_hs_en_n:1;
        RBus_UInt32  ch1_vs_syncedge:1;
        RBus_UInt32  ch1_hs_syncedge:1;
        RBus_UInt32  ch1_3d_right_act_en:1;
        RBus_UInt32  ch1_safe_mode:1;
        RBus_UInt32  ch1_force_tog:1;
        RBus_UInt32  ch1_safe_field_inv:1;
        RBus_UInt32  ch1_3d_mode_en:1;
        RBus_UInt32  ch1_mask_den_1l:1;
        RBus_UInt32  ch1_mask_den_inv:1;
        RBus_UInt32  ch1_fcap_str_odd:1;
        RBus_UInt32  ch1_hpact_is_hact:1;
        RBus_UInt32  ch1_field_det_en:1;
        RBus_UInt32  ch1_field_sync_edge:1;
        RBus_UInt32  ch1_field_inv:1;
        RBus_UInt32  ch1_3dleft_sync_edge:1;
        RBus_UInt32  ch1_3dleft_inv:1;
        RBus_UInt32  ch1_field_vd_en:1;
        RBus_UInt32  ch1_field_vd_inv:1;
        RBus_UInt32  ch1_field_hs_inv:1;
        RBus_UInt32  ch1_vact_start_ie:1;
        RBus_UInt32  ch1_vact_end_ie:1;
        RBus_UInt32  ch1_fdrop_en:1;
        RBus_UInt32  ch1_random_en:1;
        RBus_UInt32  ch1_in_sel:3;
        RBus_UInt32  ch1_ivrun:1;
    };
}vgip_vgip_chn1_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_bounce_status_0:1;
        RBus_UInt32  ch1_bounce_status_1:1;
        RBus_UInt32  ch1_bounce_status_2:1;
        RBus_UInt32  ch1_more_1line_field:1;
        RBus_UInt32  ch1_field_vs_lsb:2;
        RBus_UInt32  ch1_field_tog:1;
        RBus_UInt32  ch1_field_pol:1;
        RBus_UInt32  ch1_hs_tog:1;
        RBus_UInt32  ch1_vs_tog:1;
        RBus_UInt32  ch1_l_flag_pol:1;
        RBus_UInt32  ch1_rl_tog:1;
        RBus_UInt32  ch1_field_err:1;
        RBus_UInt32  ch1_hs_err:1;
        RBus_UInt32  ch1_vs_err:1;
        RBus_UInt32  ch1_rl_err:1;
        RBus_UInt32  ch1_vlc_status:1;
        RBus_UInt32  dummy18022214_23_17:7;
        RBus_UInt32  ch1_vact_start:1;
        RBus_UInt32  ch1_vact_end:1;
        RBus_UInt32  ch1_vs_start:1;
        RBus_UInt32  ch1_vs_end:1;
        RBus_UInt32  res1:4;
    };
}vgip_vgip_chn1_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  ch1_db_read_sel:1;
        RBus_UInt32  res2:14;
        RBus_UInt32  ch1_db_en:1;
        RBus_UInt32  ch1_db_rdy:1;
    };
}vgip_vgip_chn1_double_buffer_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_ih_act_wid:14;
        RBus_UInt32  ch1_bypass_den:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  ch1_ih_act_sta:14;
        RBus_UInt32  res2:2;
    };
}vgip_vgip_chn1_act_hsta_width_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_iv_act_len:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  ch1_iv_act_sta:13;
        RBus_UInt32  res2:3;
    };
}vgip_vgip_chn1_act_vsta_length_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_ivs_dly:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  ch1_ihs_dly:14;
        RBus_UInt32  ch1_hs_width:2;
    };
}vgip_vgip_chn1_delay_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_v1_v3_swap:1;
        RBus_UInt32  ch1_v2_v3_swap:1;
        RBus_UInt32  ch1_v1_v2_swap:1;
        RBus_UInt32  ch1_hdly_one:1;
        RBus_UInt32  ch1_auto_ivs_dly:2;
        RBus_UInt32  ch1_auto_ihs_dly:2;
        RBus_UInt32  ch1_hporch_num:13;
        RBus_UInt32  l_flag_force_tog:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  ch1_hporch_num_sel:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  ch1_vs_dly_1hs:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  ch1_de_mask_en:1;
    };
}vgip_vgip_chn1_misc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_hcaptst_num:14;
        RBus_UInt32  res1:1;
        RBus_UInt32  ch1_captst_field_sel:1;
        RBus_UInt32  ch1_vcaptst_num:13;
        RBus_UInt32  ch1_captst_mode:2;
        RBus_UInt32  ch1_captst_en:1;
    };
}vgip_vgip_chn1_ptn_h_vi_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_captst_g_data:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  ch1_captst_r_data:12;
        RBus_UInt32  res2:4;
    };
}vgip_vgip_chn1_ptn0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_captst_b_data:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  ch1_hporch_num_sel:14;
        RBus_UInt32  res2:2;
    };
}vgip_vgip_chn1_ptn1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_vln:12;
        RBus_UInt32  ch1_line_cnt:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  den_crc_sel:1;
        RBus_UInt32  ch1_vlc_ie:1;
        RBus_UInt32  ch1_vlc_mode:1;
        RBus_UInt32  ch1_vlcen:1;
    };
}vgip_vgip_chn1_lc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_crc_start:1;
        RBus_UInt32  ch1_crc_conti:1;
        RBus_UInt32  ch1_crc_field:1;
        RBus_UInt32  ch1_crc_field_edge_sel:1;
        RBus_UInt32  ch1_crc_ctrl_in:1;
        RBus_UInt32  ch1_crc_region:1;
        RBus_UInt32  ch1_crc_mode:1;
        RBus_UInt32  res1:25;
    };
}vgip_ich1_vgip_crc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_crc_result:32;
    };
}vgip_ich1_vgip_crc_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_field_err_ie:1;
        RBus_UInt32  ch1_hs_err_ie:1;
        RBus_UInt32  ch1_vs_err_ie:1;
        RBus_UInt32  ch1_rl_err_ie:1;
        RBus_UInt32  dummy4:11;
        RBus_UInt32  ch1_rl_err_wde:1;
        RBus_UInt32  ch1_field_err_wde:1;
        RBus_UInt32  ch1_hs_err_wde:1;
        RBus_UInt32  ch1_vs_err_wde:1;
        RBus_UInt32  dummy3:12;
        RBus_UInt32  ch1_wd_to_main:1;
    };
}vgip_vgip_chn1_wde_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pr_l_r_only_en:1;
        RBus_UInt32  ch1_pr_l_r_only_rm_den:1;
        RBus_UInt32  ch1_pr_l_r_only_mask_hs:1;
        RBus_UInt32  res1:29;
    };
}vgip_pr_l_r_only_ctrl_ch1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_captst_g_data_2:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  ch1_captst_r_data_2:12;
        RBus_UInt32  res2:4;
    };
}vgip_vgip_chn1_ptn2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_captst_b_data_2:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  ch1_captst_b_data_3:12;
        RBus_UInt32  res2:4;
    };
}vgip_vgip_chn1_ptn3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_captst_g_data_3:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  ch1_captst_r_data_3:12;
        RBus_UInt32  res2:4;
    };
}vgip_vgip_chn1_ptn4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_captst_g_data_4:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  ch1_captst_r_data_4:12;
        RBus_UInt32  res2:4;
    };
}vgip_vgip_chn1_ptn5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_captst_b_data_4:12;
        RBus_UInt32  res1:20;
    };
}vgip_vgip_chn1_ptn6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  adc_test_dma_mode:1;
        RBus_UInt32  force_vsync:1;
        RBus_UInt32  force_den:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  adc_test_dma_count:28;
    };
}vgip_adc_raw_data_dma_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vs_position:13;
        RBus_UInt32  frame_packing_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  field_alternative_en:1;
        RBus_UInt32  vs_width:13;
        RBus_UInt32  res2:3;
    };
}vgip_framepacking_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  den_mask_end:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  den_mask_start:13;
        RBus_UInt32  res2:3;
    };
}vgip_framepacking_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_2:2;
        RBus_UInt32  di_i_clk_en:1;
        RBus_UInt32  xcdi_clk_en:1;
        RBus_UInt32  adc_ch_sel:1;
        RBus_UInt32  dummy_1:5;
        RBus_UInt32  uzd1_in_sel:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  s1_clk_en:1;
        RBus_UInt32  res2:18;
    };
}vgip_data_path_select_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vbisli_ihs_dly:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  vbisli_ivs_dly:13;
        RBus_UInt32  vbisli_in_sel:2;
        RBus_UInt32  res2:1;
    };
}vgip_vgip_vbisli_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dispi_int_ie:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  vgip_int_ie:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  hist_ch1_int_ie:1;
        RBus_UInt32  onms1_int_ie:1;
        RBus_UInt32  onms2_int_ie:1;
        RBus_UInt32  offms_int_ie:1;
        RBus_UInt32  onms3_int_ie:1;
        RBus_UInt32  res4:22;
    };
}vgip_int_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  en_ctsfifo_bypass_vgip:1;
        RBus_UInt32  en_ctsfifo_vsrst_vgip:1;
        RBus_UInt32  force_ctsfifo_rstn_vgip:1;
        RBus_UInt32  dummy_ctsfifo_vgip:1;
        RBus_UInt32  res1:4;
        RBus_UInt32  en_ctsfifo_bypass_sdnr:1;
        RBus_UInt32  en_ctsfifo_vsrst_sdnr:1;
        RBus_UInt32  force_ctsfifo_rstn_sdnr:1;
        RBus_UInt32  dummy_ctsfifo_sdnr:1;
        RBus_UInt32  res2:20;
    };
}vgip_cts_fifo_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  disp_testpinsel:6;
        RBus_UInt32  res1:26;
    };
}vgip_dispi_test_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_3d_right_ih_act_wid:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  ch1_3d_right_ih_act_sta:14;
        RBus_UInt32  res2:2;
    };
}vgip_vgip_chn1_3d_right_act_hsta_width_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_3d_right_iv_act_len:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  ch1_3d_right_iv_act_sta:13;
        RBus_UInt32  res2:3;
    };
}vgip_vgip_chn1_3d_right_act_vsta_length_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vs_position_r_odd:13;
        RBus_UInt32  frame_packing_field_en:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  vs_width_r_odd:13;
        RBus_UInt32  res2:3;
    };
}vgip_framepacking_interlace_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  den_mask_end_r_odd:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  den_mask_start_r_odd:13;
        RBus_UInt32  res2:3;
    };
}vgip_framepacking_interlace_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vs_position_r_even:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  vs_width_r_even:13;
        RBus_UInt32  res2:3;
    };
}vgip_framepacking_interlace_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  den_mask_end_r_even:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  den_mask_start_r_even:13;
        RBus_UInt32  res2:3;
    };
}vgip_framepacking_interlace_ctrl4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sta_l:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  end_l:14;
        RBus_UInt32  res2:2;
    };
}vgip_l_r_active_enable_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sta_r:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  end_r:14;
        RBus_UInt32  h_v_mode:1;
        RBus_UInt32  l_r_act_en:1;
    };
}vgip_l_r_active_enable_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ccdinr_irq_record:1;
        RBus_UInt32  i3ddma_irq_record:1;
        RBus_UInt32  onms_1_irq_record:1;
        RBus_UInt32  onms_2_irq_record:1;
        RBus_UInt32  offms_irq_record:1;
        RBus_UInt32  vgip_irq_record:1;
        RBus_UInt32  hist_irq_record:1;
        RBus_UInt32  sync_processor_irq_record:1;
        RBus_UInt32  sync_auto_1_irq_record:1;
        RBus_UInt32  sync_auto_2_irq_record:1;
        RBus_UInt32  adc_irq_record:1;
        RBus_UInt32  dexc_irq_record:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  onms_3_irq_record:1;
        RBus_UInt32  res2:18;
    };
}vgip_dispi_irq_record_RBUS;




#endif 


#endif 
