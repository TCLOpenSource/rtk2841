/**
* @file Mac5-DesignSpec-dtv_frontend
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_DTV_FRONTEND_REG_H_
#define _RBUS_DTV_FRONTEND_REG_H_

#include "rbus_types.h"



//  DTV_FRONTEND Register Address
#define  DTV_FRONTEND_DTV_INPUT_CTRL                                             0x18033800
#define  DTV_FRONTEND_DTV_INPUT_CTRL_reg_addr                                    "0xB8033800"
#define  DTV_FRONTEND_DTV_INPUT_CTRL_reg                                         0xB8033800
#define  DTV_FRONTEND_DTV_INPUT_CTRL_inst_addr                                   "0x0000"
#define  set_DTV_FRONTEND_DTV_INPUT_CTRL_reg(data)                               (*((volatile unsigned int*)DTV_FRONTEND_DTV_INPUT_CTRL_reg)=data)
#define  get_DTV_FRONTEND_DTV_INPUT_CTRL_reg                                     (*((volatile unsigned int*)DTV_FRONTEND_DTV_INPUT_CTRL_reg))
#define  DTV_FRONTEND_DTV_INPUT_CTRL_dtmb_data_valid_delay_shift                 (28)
#define  DTV_FRONTEND_DTV_INPUT_CTRL_dtv_demod_iclk_inv_shift                    (25)
#define  DTV_FRONTEND_DTV_INPUT_CTRL_dtv_demod_iqclk_inv_shift                   (24)
#define  DTV_FRONTEND_DTV_INPUT_CTRL_dtv_demod_sel_shift                         (20)
#define  DTV_FRONTEND_DTV_INPUT_CTRL_dtv_frontend_mode_shift                     (16)
#define  DTV_FRONTEND_DTV_INPUT_CTRL_dtv_dnflt_output_gain_shift                 (12)
#define  DTV_FRONTEND_DTV_INPUT_CTRL_dtv_idata_sel_shift                         (8)
#define  DTV_FRONTEND_DTV_INPUT_CTRL_dtv_dnflt_en_shift                          (4)
#define  DTV_FRONTEND_DTV_INPUT_CTRL_dtv_i_phase_rotate_shift                    (3)
#define  DTV_FRONTEND_DTV_INPUT_CTRL_dtv_q_phase_rotate_shift                    (2)
#define  DTV_FRONTEND_DTV_INPUT_CTRL_dtv_iq_swap_shift                           (1)
#define  DTV_FRONTEND_DTV_INPUT_CTRL_dtmb_data_valid_delay_mask                  (0x30000000)
#define  DTV_FRONTEND_DTV_INPUT_CTRL_dtv_demod_iclk_inv_mask                     (0x02000000)
#define  DTV_FRONTEND_DTV_INPUT_CTRL_dtv_demod_iqclk_inv_mask                    (0x01000000)
#define  DTV_FRONTEND_DTV_INPUT_CTRL_dtv_demod_sel_mask                          (0x00300000)
#define  DTV_FRONTEND_DTV_INPUT_CTRL_dtv_frontend_mode_mask                      (0x00030000)
#define  DTV_FRONTEND_DTV_INPUT_CTRL_dtv_dnflt_output_gain_mask                  (0x00003000)
#define  DTV_FRONTEND_DTV_INPUT_CTRL_dtv_idata_sel_mask                          (0x00000100)
#define  DTV_FRONTEND_DTV_INPUT_CTRL_dtv_dnflt_en_mask                           (0x00000010)
#define  DTV_FRONTEND_DTV_INPUT_CTRL_dtv_i_phase_rotate_mask                     (0x00000008)
#define  DTV_FRONTEND_DTV_INPUT_CTRL_dtv_q_phase_rotate_mask                     (0x00000004)
#define  DTV_FRONTEND_DTV_INPUT_CTRL_dtv_iq_swap_mask                            (0x00000002)
#define  DTV_FRONTEND_DTV_INPUT_CTRL_dtmb_data_valid_delay(data)                 (0x30000000&((data)<<28))
#define  DTV_FRONTEND_DTV_INPUT_CTRL_dtv_demod_iclk_inv(data)                    (0x02000000&((data)<<25))
#define  DTV_FRONTEND_DTV_INPUT_CTRL_dtv_demod_iqclk_inv(data)                   (0x01000000&((data)<<24))
#define  DTV_FRONTEND_DTV_INPUT_CTRL_dtv_demod_sel(data)                         (0x00300000&((data)<<20))
#define  DTV_FRONTEND_DTV_INPUT_CTRL_dtv_frontend_mode(data)                     (0x00030000&((data)<<16))
#define  DTV_FRONTEND_DTV_INPUT_CTRL_dtv_dnflt_output_gain(data)                 (0x00003000&((data)<<12))
#define  DTV_FRONTEND_DTV_INPUT_CTRL_dtv_idata_sel(data)                         (0x00000100&((data)<<8))
#define  DTV_FRONTEND_DTV_INPUT_CTRL_dtv_dnflt_en(data)                          (0x00000010&((data)<<4))
#define  DTV_FRONTEND_DTV_INPUT_CTRL_dtv_i_phase_rotate(data)                    (0x00000008&((data)<<3))
#define  DTV_FRONTEND_DTV_INPUT_CTRL_dtv_q_phase_rotate(data)                    (0x00000004&((data)<<2))
#define  DTV_FRONTEND_DTV_INPUT_CTRL_dtv_iq_swap(data)                           (0x00000002&((data)<<1))
#define  DTV_FRONTEND_DTV_INPUT_CTRL_get_dtmb_data_valid_delay(data)             ((0x30000000&(data))>>28)
#define  DTV_FRONTEND_DTV_INPUT_CTRL_get_dtv_demod_iclk_inv(data)                ((0x02000000&(data))>>25)
#define  DTV_FRONTEND_DTV_INPUT_CTRL_get_dtv_demod_iqclk_inv(data)               ((0x01000000&(data))>>24)
#define  DTV_FRONTEND_DTV_INPUT_CTRL_get_dtv_demod_sel(data)                     ((0x00300000&(data))>>20)
#define  DTV_FRONTEND_DTV_INPUT_CTRL_get_dtv_frontend_mode(data)                 ((0x00030000&(data))>>16)
#define  DTV_FRONTEND_DTV_INPUT_CTRL_get_dtv_dnflt_output_gain(data)             ((0x00003000&(data))>>12)
#define  DTV_FRONTEND_DTV_INPUT_CTRL_get_dtv_idata_sel(data)                     ((0x00000100&(data))>>8)
#define  DTV_FRONTEND_DTV_INPUT_CTRL_get_dtv_dnflt_en(data)                      ((0x00000010&(data))>>4)
#define  DTV_FRONTEND_DTV_INPUT_CTRL_get_dtv_i_phase_rotate(data)                ((0x00000008&(data))>>3)
#define  DTV_FRONTEND_DTV_INPUT_CTRL_get_dtv_q_phase_rotate(data)                ((0x00000004&(data))>>2)
#define  DTV_FRONTEND_DTV_INPUT_CTRL_get_dtv_iq_swap(data)                       ((0x00000002&(data))>>1)

#define  DTV_FRONTEND_DTV_FIFO_STATUS                                            0x18033804
#define  DTV_FRONTEND_DTV_FIFO_STATUS_reg_addr                                   "0xB8033804"
#define  DTV_FRONTEND_DTV_FIFO_STATUS_reg                                        0xB8033804
#define  DTV_FRONTEND_DTV_FIFO_STATUS_inst_addr                                  "0x0001"
#define  set_DTV_FRONTEND_DTV_FIFO_STATUS_reg(data)                              (*((volatile unsigned int*)DTV_FRONTEND_DTV_FIFO_STATUS_reg)=data)
#define  get_DTV_FRONTEND_DTV_FIFO_STATUS_reg                                    (*((volatile unsigned int*)DTV_FRONTEND_DTV_FIFO_STATUS_reg))
#define  DTV_FRONTEND_DTV_FIFO_STATUS_dtv_input_fifo_clr_shift                   (18)
#define  DTV_FRONTEND_DTV_FIFO_STATUS_dtv_input_fifo_full_shift                  (17)
#define  DTV_FRONTEND_DTV_FIFO_STATUS_dtv_input_fifo_empty_shift                 (16)
#define  DTV_FRONTEND_DTV_FIFO_STATUS_iqadc_fifo_clr_shift                       (10)
#define  DTV_FRONTEND_DTV_FIFO_STATUS_iqadc_fifo_full_shift                      (9)
#define  DTV_FRONTEND_DTV_FIFO_STATUS_iqadc_fifo_empty_shift                     (8)
#define  DTV_FRONTEND_DTV_FIFO_STATUS_dtv_input_fifo_clr_mask                    (0x00040000)
#define  DTV_FRONTEND_DTV_FIFO_STATUS_dtv_input_fifo_full_mask                   (0x00020000)
#define  DTV_FRONTEND_DTV_FIFO_STATUS_dtv_input_fifo_empty_mask                  (0x00010000)
#define  DTV_FRONTEND_DTV_FIFO_STATUS_iqadc_fifo_clr_mask                        (0x00000400)
#define  DTV_FRONTEND_DTV_FIFO_STATUS_iqadc_fifo_full_mask                       (0x00000200)
#define  DTV_FRONTEND_DTV_FIFO_STATUS_iqadc_fifo_empty_mask                      (0x00000100)
#define  DTV_FRONTEND_DTV_FIFO_STATUS_dtv_input_fifo_clr(data)                   (0x00040000&((data)<<18))
#define  DTV_FRONTEND_DTV_FIFO_STATUS_dtv_input_fifo_full(data)                  (0x00020000&((data)<<17))
#define  DTV_FRONTEND_DTV_FIFO_STATUS_dtv_input_fifo_empty(data)                 (0x00010000&((data)<<16))
#define  DTV_FRONTEND_DTV_FIFO_STATUS_iqadc_fifo_clr(data)                       (0x00000400&((data)<<10))
#define  DTV_FRONTEND_DTV_FIFO_STATUS_iqadc_fifo_full(data)                      (0x00000200&((data)<<9))
#define  DTV_FRONTEND_DTV_FIFO_STATUS_iqadc_fifo_empty(data)                     (0x00000100&((data)<<8))
#define  DTV_FRONTEND_DTV_FIFO_STATUS_get_dtv_input_fifo_clr(data)               ((0x00040000&(data))>>18)
#define  DTV_FRONTEND_DTV_FIFO_STATUS_get_dtv_input_fifo_full(data)              ((0x00020000&(data))>>17)
#define  DTV_FRONTEND_DTV_FIFO_STATUS_get_dtv_input_fifo_empty(data)             ((0x00010000&(data))>>16)
#define  DTV_FRONTEND_DTV_FIFO_STATUS_get_iqadc_fifo_clr(data)                   ((0x00000400&(data))>>10)
#define  DTV_FRONTEND_DTV_FIFO_STATUS_get_iqadc_fifo_full(data)                  ((0x00000200&(data))>>9)
#define  DTV_FRONTEND_DTV_FIFO_STATUS_get_iqadc_fifo_empty(data)                 ((0x00000100&(data))>>8)

#define  DTV_FRONTEND_DTV_IQ_DELAY                                               0x18033808
#define  DTV_FRONTEND_DTV_IQ_DELAY_reg_addr                                      "0xB8033808"
#define  DTV_FRONTEND_DTV_IQ_DELAY_reg                                           0xB8033808
#define  DTV_FRONTEND_DTV_IQ_DELAY_inst_addr                                     "0x0002"
#define  set_DTV_FRONTEND_DTV_IQ_DELAY_reg(data)                                 (*((volatile unsigned int*)DTV_FRONTEND_DTV_IQ_DELAY_reg)=data)
#define  get_DTV_FRONTEND_DTV_IQ_DELAY_reg                                       (*((volatile unsigned int*)DTV_FRONTEND_DTV_IQ_DELAY_reg))
#define  DTV_FRONTEND_DTV_IQ_DELAY_qadc_delay_sel_shift                          (4)
#define  DTV_FRONTEND_DTV_IQ_DELAY_iadc_delay_sel_shift                          (0)
#define  DTV_FRONTEND_DTV_IQ_DELAY_qadc_delay_sel_mask                           (0x00000030)
#define  DTV_FRONTEND_DTV_IQ_DELAY_iadc_delay_sel_mask                           (0x00000003)
#define  DTV_FRONTEND_DTV_IQ_DELAY_qadc_delay_sel(data)                          (0x00000030&((data)<<4))
#define  DTV_FRONTEND_DTV_IQ_DELAY_iadc_delay_sel(data)                          (0x00000003&(data))
#define  DTV_FRONTEND_DTV_IQ_DELAY_get_qadc_delay_sel(data)                      ((0x00000030&(data))>>4)
#define  DTV_FRONTEND_DTV_IQ_DELAY_get_iadc_delay_sel(data)                      (0x00000003&(data))

#define  DTV_FRONTEND_ADC_CAL_3_0                                                0x1803380C
#define  DTV_FRONTEND_ADC_CAL_3_0_reg_addr                                       "0xB803380C"
#define  DTV_FRONTEND_ADC_CAL_3_0_reg                                            0xB803380C
#define  DTV_FRONTEND_ADC_CAL_3_0_inst_addr                                      "0x0003"
#define  set_DTV_FRONTEND_ADC_CAL_3_0_reg(data)                                  (*((volatile unsigned int*)DTV_FRONTEND_ADC_CAL_3_0_reg)=data)
#define  get_DTV_FRONTEND_ADC_CAL_3_0_reg                                        (*((volatile unsigned int*)DTV_FRONTEND_ADC_CAL_3_0_reg))
#define  DTV_FRONTEND_ADC_CAL_3_0_adj_cmp_thd_shift                              (16)
#define  DTV_FRONTEND_ADC_CAL_3_0_adj_depth_shift                                (14)
#define  DTV_FRONTEND_ADC_CAL_3_0_adj_alpha_shift                                (11)
#define  DTV_FRONTEND_ADC_CAL_3_0_adj_beta_shift                                 (8)
#define  DTV_FRONTEND_ADC_CAL_3_0_adj_bb_update_shift                            (4)
#define  DTV_FRONTEND_ADC_CAL_3_0_adj_out_u2s_shift                              (3)
#define  DTV_FRONTEND_ADC_CAL_3_0_adj_in_u2s_shift                               (2)
#define  DTV_FRONTEND_ADC_CAL_3_0_adj_update_shift                               (1)
#define  DTV_FRONTEND_ADC_CAL_3_0_adj_enable_shift                               (0)
#define  DTV_FRONTEND_ADC_CAL_3_0_adj_cmp_thd_mask                               (0x1FFF0000)
#define  DTV_FRONTEND_ADC_CAL_3_0_adj_depth_mask                                 (0x0000C000)
#define  DTV_FRONTEND_ADC_CAL_3_0_adj_alpha_mask                                 (0x00003800)
#define  DTV_FRONTEND_ADC_CAL_3_0_adj_beta_mask                                  (0x00000700)
#define  DTV_FRONTEND_ADC_CAL_3_0_adj_bb_update_mask                             (0x00000010)
#define  DTV_FRONTEND_ADC_CAL_3_0_adj_out_u2s_mask                               (0x00000008)
#define  DTV_FRONTEND_ADC_CAL_3_0_adj_in_u2s_mask                                (0x00000004)
#define  DTV_FRONTEND_ADC_CAL_3_0_adj_update_mask                                (0x00000002)
#define  DTV_FRONTEND_ADC_CAL_3_0_adj_enable_mask                                (0x00000001)
#define  DTV_FRONTEND_ADC_CAL_3_0_adj_cmp_thd(data)                              (0x1FFF0000&((data)<<16))
#define  DTV_FRONTEND_ADC_CAL_3_0_adj_depth(data)                                (0x0000C000&((data)<<14))
#define  DTV_FRONTEND_ADC_CAL_3_0_adj_alpha(data)                                (0x00003800&((data)<<11))
#define  DTV_FRONTEND_ADC_CAL_3_0_adj_beta(data)                                 (0x00000700&((data)<<8))
#define  DTV_FRONTEND_ADC_CAL_3_0_adj_bb_update(data)                            (0x00000010&((data)<<4))
#define  DTV_FRONTEND_ADC_CAL_3_0_adj_out_u2s(data)                              (0x00000008&((data)<<3))
#define  DTV_FRONTEND_ADC_CAL_3_0_adj_in_u2s(data)                               (0x00000004&((data)<<2))
#define  DTV_FRONTEND_ADC_CAL_3_0_adj_update(data)                               (0x00000002&((data)<<1))
#define  DTV_FRONTEND_ADC_CAL_3_0_adj_enable(data)                               (0x00000001&(data))
#define  DTV_FRONTEND_ADC_CAL_3_0_get_adj_cmp_thd(data)                          ((0x1FFF0000&(data))>>16)
#define  DTV_FRONTEND_ADC_CAL_3_0_get_adj_depth(data)                            ((0x0000C000&(data))>>14)
#define  DTV_FRONTEND_ADC_CAL_3_0_get_adj_alpha(data)                            ((0x00003800&(data))>>11)
#define  DTV_FRONTEND_ADC_CAL_3_0_get_adj_beta(data)                             ((0x00000700&(data))>>8)
#define  DTV_FRONTEND_ADC_CAL_3_0_get_adj_bb_update(data)                        ((0x00000010&(data))>>4)
#define  DTV_FRONTEND_ADC_CAL_3_0_get_adj_out_u2s(data)                          ((0x00000008&(data))>>3)
#define  DTV_FRONTEND_ADC_CAL_3_0_get_adj_in_u2s(data)                           ((0x00000004&(data))>>2)
#define  DTV_FRONTEND_ADC_CAL_3_0_get_adj_update(data)                           ((0x00000002&(data))>>1)
#define  DTV_FRONTEND_ADC_CAL_3_0_get_adj_enable(data)                           (0x00000001&(data))

#define  DTV_FRONTEND_ADC_CAL_7_4                                                0x18033810
#define  DTV_FRONTEND_ADC_CAL_7_4_reg_addr                                       "0xB8033810"
#define  DTV_FRONTEND_ADC_CAL_7_4_reg                                            0xB8033810
#define  DTV_FRONTEND_ADC_CAL_7_4_inst_addr                                      "0x0004"
#define  set_DTV_FRONTEND_ADC_CAL_7_4_reg(data)                                  (*((volatile unsigned int*)DTV_FRONTEND_ADC_CAL_7_4_reg)=data)
#define  get_DTV_FRONTEND_ADC_CAL_7_4_reg                                        (*((volatile unsigned int*)DTV_FRONTEND_ADC_CAL_7_4_reg))
#define  DTV_FRONTEND_ADC_CAL_7_4_adj_manual_offset_shift                        (16)
#define  DTV_FRONTEND_ADC_CAL_7_4_adj_manual_gain_shift                          (0)
#define  DTV_FRONTEND_ADC_CAL_7_4_adj_manual_offset_mask                         (0x0FFF0000)
#define  DTV_FRONTEND_ADC_CAL_7_4_adj_manual_gain_mask                           (0x00003FFF)
#define  DTV_FRONTEND_ADC_CAL_7_4_adj_manual_offset(data)                        (0x0FFF0000&((data)<<16))
#define  DTV_FRONTEND_ADC_CAL_7_4_adj_manual_gain(data)                          (0x00003FFF&(data))
#define  DTV_FRONTEND_ADC_CAL_7_4_get_adj_manual_offset(data)                    ((0x0FFF0000&(data))>>16)
#define  DTV_FRONTEND_ADC_CAL_7_4_get_adj_manual_gain(data)                      (0x00003FFF&(data))

#define  DTV_FRONTEND_ADC_CAL_9_8                                                0x18033814
#define  DTV_FRONTEND_ADC_CAL_9_8_reg_addr                                       "0xB8033814"
#define  DTV_FRONTEND_ADC_CAL_9_8_reg                                            0xB8033814
#define  DTV_FRONTEND_ADC_CAL_9_8_inst_addr                                      "0x0005"
#define  set_DTV_FRONTEND_ADC_CAL_9_8_reg(data)                                  (*((volatile unsigned int*)DTV_FRONTEND_ADC_CAL_9_8_reg)=data)
#define  get_DTV_FRONTEND_ADC_CAL_9_8_reg                                        (*((volatile unsigned int*)DTV_FRONTEND_ADC_CAL_9_8_reg))
#define  DTV_FRONTEND_ADC_CAL_9_8_adj_update_cyc_shift                           (8)
#define  DTV_FRONTEND_ADC_CAL_9_8_adj_cmp_cyc_shift                              (4)
#define  DTV_FRONTEND_ADC_CAL_9_8_adj_en_cal_cyc_shift                           (3)
#define  DTV_FRONTEND_ADC_CAL_9_8_adj_manual_sel_shift                           (2)
#define  DTV_FRONTEND_ADC_CAL_9_8_adj_update_cyc_mask                            (0x00000300)
#define  DTV_FRONTEND_ADC_CAL_9_8_adj_cmp_cyc_mask                               (0x00000030)
#define  DTV_FRONTEND_ADC_CAL_9_8_adj_en_cal_cyc_mask                            (0x00000008)
#define  DTV_FRONTEND_ADC_CAL_9_8_adj_manual_sel_mask                            (0x00000004)
#define  DTV_FRONTEND_ADC_CAL_9_8_adj_update_cyc(data)                           (0x00000300&((data)<<8))
#define  DTV_FRONTEND_ADC_CAL_9_8_adj_cmp_cyc(data)                              (0x00000030&((data)<<4))
#define  DTV_FRONTEND_ADC_CAL_9_8_adj_en_cal_cyc(data)                           (0x00000008&((data)<<3))
#define  DTV_FRONTEND_ADC_CAL_9_8_adj_manual_sel(data)                           (0x00000004&((data)<<2))
#define  DTV_FRONTEND_ADC_CAL_9_8_get_adj_update_cyc(data)                       ((0x00000300&(data))>>8)
#define  DTV_FRONTEND_ADC_CAL_9_8_get_adj_cmp_cyc(data)                          ((0x00000030&(data))>>4)
#define  DTV_FRONTEND_ADC_CAL_9_8_get_adj_en_cal_cyc(data)                       ((0x00000008&(data))>>3)
#define  DTV_FRONTEND_ADC_CAL_9_8_get_adj_manual_sel(data)                       ((0x00000004&(data))>>2)

#define  DTV_FRONTEND_ADC_CAL_D_A                                                0x18033818
#define  DTV_FRONTEND_ADC_CAL_D_A_reg_addr                                       "0xB8033818"
#define  DTV_FRONTEND_ADC_CAL_D_A_reg                                            0xB8033818
#define  DTV_FRONTEND_ADC_CAL_D_A_inst_addr                                      "0x0006"
#define  set_DTV_FRONTEND_ADC_CAL_D_A_reg(data)                                  (*((volatile unsigned int*)DTV_FRONTEND_ADC_CAL_D_A_reg)=data)
#define  get_DTV_FRONTEND_ADC_CAL_D_A_reg                                        (*((volatile unsigned int*)DTV_FRONTEND_ADC_CAL_D_A_reg))
#define  DTV_FRONTEND_ADC_CAL_D_A_adj_debug_offset_shift                         (16)
#define  DTV_FRONTEND_ADC_CAL_D_A_adj_debug_gain_shift                           (0)
#define  DTV_FRONTEND_ADC_CAL_D_A_adj_debug_offset_mask                          (0x0FFF0000)
#define  DTV_FRONTEND_ADC_CAL_D_A_adj_debug_gain_mask                            (0x00003FFF)
#define  DTV_FRONTEND_ADC_CAL_D_A_adj_debug_offset(data)                         (0x0FFF0000&((data)<<16))
#define  DTV_FRONTEND_ADC_CAL_D_A_adj_debug_gain(data)                           (0x00003FFF&(data))
#define  DTV_FRONTEND_ADC_CAL_D_A_get_adj_debug_offset(data)                     ((0x0FFF0000&(data))>>16)
#define  DTV_FRONTEND_ADC_CAL_D_A_get_adj_debug_gain(data)                       (0x00003FFF&(data))

#define  DTV_FRONTEND_ADC_CAL_F_E                                                0x1803381C
#define  DTV_FRONTEND_ADC_CAL_F_E_reg_addr                                       "0xB803381C"
#define  DTV_FRONTEND_ADC_CAL_F_E_reg                                            0xB803381C
#define  DTV_FRONTEND_ADC_CAL_F_E_inst_addr                                      "0x0007"
#define  set_DTV_FRONTEND_ADC_CAL_F_E_reg(data)                                  (*((volatile unsigned int*)DTV_FRONTEND_ADC_CAL_F_E_reg)=data)
#define  get_DTV_FRONTEND_ADC_CAL_F_E_reg                                        (*((volatile unsigned int*)DTV_FRONTEND_ADC_CAL_F_E_reg))
#define  DTV_FRONTEND_ADC_CAL_F_E_adj_cal_done_shift                             (15)
#define  DTV_FRONTEND_ADC_CAL_F_E_adj_cal_result_shift                           (14)
#define  DTV_FRONTEND_ADC_CAL_F_E_adj_cal_error_shift                            (0)
#define  DTV_FRONTEND_ADC_CAL_F_E_adj_cal_done_mask                              (0x00008000)
#define  DTV_FRONTEND_ADC_CAL_F_E_adj_cal_result_mask                            (0x00004000)
#define  DTV_FRONTEND_ADC_CAL_F_E_adj_cal_error_mask                             (0x00003FFF)
#define  DTV_FRONTEND_ADC_CAL_F_E_adj_cal_done(data)                             (0x00008000&((data)<<15))
#define  DTV_FRONTEND_ADC_CAL_F_E_adj_cal_result(data)                           (0x00004000&((data)<<14))
#define  DTV_FRONTEND_ADC_CAL_F_E_adj_cal_error(data)                            (0x00003FFF&(data))
#define  DTV_FRONTEND_ADC_CAL_F_E_get_adj_cal_done(data)                         ((0x00008000&(data))>>15)
#define  DTV_FRONTEND_ADC_CAL_F_E_get_adj_cal_result(data)                       ((0x00004000&(data))>>14)
#define  DTV_FRONTEND_ADC_CAL_F_E_get_adj_cal_error(data)                        (0x00003FFF&(data))

#define  DTV_FRONTEND_DTV_DN5_COEF00                                             0x18033900
#define  DTV_FRONTEND_DTV_DN5_COEF00_reg_addr                                    "0xB8033900"
#define  DTV_FRONTEND_DTV_DN5_COEF00_reg                                         0xB8033900
#define  DTV_FRONTEND_DTV_DN5_COEF00_inst_addr                                   "0x0008"
#define  set_DTV_FRONTEND_DTV_DN5_COEF00_reg(data)                               (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF00_reg)=data)
#define  get_DTV_FRONTEND_DTV_DN5_COEF00_reg                                     (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF00_reg))
#define  DTV_FRONTEND_DTV_DN5_COEF00_dtv_frontend_dn5_coef001_shift              (16)
#define  DTV_FRONTEND_DTV_DN5_COEF00_dtv_frontend_dn5_coef000_shift              (0)
#define  DTV_FRONTEND_DTV_DN5_COEF00_dtv_frontend_dn5_coef001_mask               (0x1FFF0000)
#define  DTV_FRONTEND_DTV_DN5_COEF00_dtv_frontend_dn5_coef000_mask               (0x00001FFF)
#define  DTV_FRONTEND_DTV_DN5_COEF00_dtv_frontend_dn5_coef001(data)              (0x1FFF0000&((data)<<16))
#define  DTV_FRONTEND_DTV_DN5_COEF00_dtv_frontend_dn5_coef000(data)              (0x00001FFF&(data))
#define  DTV_FRONTEND_DTV_DN5_COEF00_get_dtv_frontend_dn5_coef001(data)          ((0x1FFF0000&(data))>>16)
#define  DTV_FRONTEND_DTV_DN5_COEF00_get_dtv_frontend_dn5_coef000(data)          (0x00001FFF&(data))

#define  DTV_FRONTEND_DTV_DN5_COEF01                                             0x18033904
#define  DTV_FRONTEND_DTV_DN5_COEF01_reg_addr                                    "0xB8033904"
#define  DTV_FRONTEND_DTV_DN5_COEF01_reg                                         0xB8033904
#define  DTV_FRONTEND_DTV_DN5_COEF01_inst_addr                                   "0x0009"
#define  set_DTV_FRONTEND_DTV_DN5_COEF01_reg(data)                               (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF01_reg)=data)
#define  get_DTV_FRONTEND_DTV_DN5_COEF01_reg                                     (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF01_reg))
#define  DTV_FRONTEND_DTV_DN5_COEF01_dtv_frontend_dn5_coef003_shift              (16)
#define  DTV_FRONTEND_DTV_DN5_COEF01_dtv_frontend_dn5_coef002_shift              (0)
#define  DTV_FRONTEND_DTV_DN5_COEF01_dtv_frontend_dn5_coef003_mask               (0x1FFF0000)
#define  DTV_FRONTEND_DTV_DN5_COEF01_dtv_frontend_dn5_coef002_mask               (0x00001FFF)
#define  DTV_FRONTEND_DTV_DN5_COEF01_dtv_frontend_dn5_coef003(data)              (0x1FFF0000&((data)<<16))
#define  DTV_FRONTEND_DTV_DN5_COEF01_dtv_frontend_dn5_coef002(data)              (0x00001FFF&(data))
#define  DTV_FRONTEND_DTV_DN5_COEF01_get_dtv_frontend_dn5_coef003(data)          ((0x1FFF0000&(data))>>16)
#define  DTV_FRONTEND_DTV_DN5_COEF01_get_dtv_frontend_dn5_coef002(data)          (0x00001FFF&(data))

#define  DTV_FRONTEND_DTV_DN5_COEF02                                             0x18033908
#define  DTV_FRONTEND_DTV_DN5_COEF02_reg_addr                                    "0xB8033908"
#define  DTV_FRONTEND_DTV_DN5_COEF02_reg                                         0xB8033908
#define  DTV_FRONTEND_DTV_DN5_COEF02_inst_addr                                   "0x000A"
#define  set_DTV_FRONTEND_DTV_DN5_COEF02_reg(data)                               (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF02_reg)=data)
#define  get_DTV_FRONTEND_DTV_DN5_COEF02_reg                                     (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF02_reg))
#define  DTV_FRONTEND_DTV_DN5_COEF02_dtv_frontend_dn5_coef005_shift              (16)
#define  DTV_FRONTEND_DTV_DN5_COEF02_dtv_frontend_dn5_coef004_shift              (0)
#define  DTV_FRONTEND_DTV_DN5_COEF02_dtv_frontend_dn5_coef005_mask               (0x1FFF0000)
#define  DTV_FRONTEND_DTV_DN5_COEF02_dtv_frontend_dn5_coef004_mask               (0x00001FFF)
#define  DTV_FRONTEND_DTV_DN5_COEF02_dtv_frontend_dn5_coef005(data)              (0x1FFF0000&((data)<<16))
#define  DTV_FRONTEND_DTV_DN5_COEF02_dtv_frontend_dn5_coef004(data)              (0x00001FFF&(data))
#define  DTV_FRONTEND_DTV_DN5_COEF02_get_dtv_frontend_dn5_coef005(data)          ((0x1FFF0000&(data))>>16)
#define  DTV_FRONTEND_DTV_DN5_COEF02_get_dtv_frontend_dn5_coef004(data)          (0x00001FFF&(data))

#define  DTV_FRONTEND_DTV_DN5_COEF03                                             0x1803390C
#define  DTV_FRONTEND_DTV_DN5_COEF03_reg_addr                                    "0xB803390C"
#define  DTV_FRONTEND_DTV_DN5_COEF03_reg                                         0xB803390C
#define  DTV_FRONTEND_DTV_DN5_COEF03_inst_addr                                   "0x000B"
#define  set_DTV_FRONTEND_DTV_DN5_COEF03_reg(data)                               (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF03_reg)=data)
#define  get_DTV_FRONTEND_DTV_DN5_COEF03_reg                                     (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF03_reg))
#define  DTV_FRONTEND_DTV_DN5_COEF03_dtv_frontend_dn5_coef007_shift              (16)
#define  DTV_FRONTEND_DTV_DN5_COEF03_dtv_frontend_dn5_coef006_shift              (0)
#define  DTV_FRONTEND_DTV_DN5_COEF03_dtv_frontend_dn5_coef007_mask               (0x1FFF0000)
#define  DTV_FRONTEND_DTV_DN5_COEF03_dtv_frontend_dn5_coef006_mask               (0x00001FFF)
#define  DTV_FRONTEND_DTV_DN5_COEF03_dtv_frontend_dn5_coef007(data)              (0x1FFF0000&((data)<<16))
#define  DTV_FRONTEND_DTV_DN5_COEF03_dtv_frontend_dn5_coef006(data)              (0x00001FFF&(data))
#define  DTV_FRONTEND_DTV_DN5_COEF03_get_dtv_frontend_dn5_coef007(data)          ((0x1FFF0000&(data))>>16)
#define  DTV_FRONTEND_DTV_DN5_COEF03_get_dtv_frontend_dn5_coef006(data)          (0x00001FFF&(data))

#define  DTV_FRONTEND_DTV_DN5_COEF04                                             0x18033910
#define  DTV_FRONTEND_DTV_DN5_COEF04_reg_addr                                    "0xB8033910"
#define  DTV_FRONTEND_DTV_DN5_COEF04_reg                                         0xB8033910
#define  DTV_FRONTEND_DTV_DN5_COEF04_inst_addr                                   "0x000C"
#define  set_DTV_FRONTEND_DTV_DN5_COEF04_reg(data)                               (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF04_reg)=data)
#define  get_DTV_FRONTEND_DTV_DN5_COEF04_reg                                     (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF04_reg))
#define  DTV_FRONTEND_DTV_DN5_COEF04_dtv_frontend_dn5_coef009_shift              (16)
#define  DTV_FRONTEND_DTV_DN5_COEF04_dtv_frontend_dn5_coef008_shift              (0)
#define  DTV_FRONTEND_DTV_DN5_COEF04_dtv_frontend_dn5_coef009_mask               (0x1FFF0000)
#define  DTV_FRONTEND_DTV_DN5_COEF04_dtv_frontend_dn5_coef008_mask               (0x00001FFF)
#define  DTV_FRONTEND_DTV_DN5_COEF04_dtv_frontend_dn5_coef009(data)              (0x1FFF0000&((data)<<16))
#define  DTV_FRONTEND_DTV_DN5_COEF04_dtv_frontend_dn5_coef008(data)              (0x00001FFF&(data))
#define  DTV_FRONTEND_DTV_DN5_COEF04_get_dtv_frontend_dn5_coef009(data)          ((0x1FFF0000&(data))>>16)
#define  DTV_FRONTEND_DTV_DN5_COEF04_get_dtv_frontend_dn5_coef008(data)          (0x00001FFF&(data))

#define  DTV_FRONTEND_DTV_DN5_COEF05                                             0x18033914
#define  DTV_FRONTEND_DTV_DN5_COEF05_reg_addr                                    "0xB8033914"
#define  DTV_FRONTEND_DTV_DN5_COEF05_reg                                         0xB8033914
#define  DTV_FRONTEND_DTV_DN5_COEF05_inst_addr                                   "0x000D"
#define  set_DTV_FRONTEND_DTV_DN5_COEF05_reg(data)                               (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF05_reg)=data)
#define  get_DTV_FRONTEND_DTV_DN5_COEF05_reg                                     (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF05_reg))
#define  DTV_FRONTEND_DTV_DN5_COEF05_dtv_frontend_dn5_coef011_shift              (16)
#define  DTV_FRONTEND_DTV_DN5_COEF05_dtv_frontend_dn5_coef010_shift              (0)
#define  DTV_FRONTEND_DTV_DN5_COEF05_dtv_frontend_dn5_coef011_mask               (0x1FFF0000)
#define  DTV_FRONTEND_DTV_DN5_COEF05_dtv_frontend_dn5_coef010_mask               (0x00001FFF)
#define  DTV_FRONTEND_DTV_DN5_COEF05_dtv_frontend_dn5_coef011(data)              (0x1FFF0000&((data)<<16))
#define  DTV_FRONTEND_DTV_DN5_COEF05_dtv_frontend_dn5_coef010(data)              (0x00001FFF&(data))
#define  DTV_FRONTEND_DTV_DN5_COEF05_get_dtv_frontend_dn5_coef011(data)          ((0x1FFF0000&(data))>>16)
#define  DTV_FRONTEND_DTV_DN5_COEF05_get_dtv_frontend_dn5_coef010(data)          (0x00001FFF&(data))

#define  DTV_FRONTEND_DTV_DN5_COEF06                                             0x18033918
#define  DTV_FRONTEND_DTV_DN5_COEF06_reg_addr                                    "0xB8033918"
#define  DTV_FRONTEND_DTV_DN5_COEF06_reg                                         0xB8033918
#define  DTV_FRONTEND_DTV_DN5_COEF06_inst_addr                                   "0x000E"
#define  set_DTV_FRONTEND_DTV_DN5_COEF06_reg(data)                               (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF06_reg)=data)
#define  get_DTV_FRONTEND_DTV_DN5_COEF06_reg                                     (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF06_reg))
#define  DTV_FRONTEND_DTV_DN5_COEF06_dtv_frontend_dn5_coef013_shift              (16)
#define  DTV_FRONTEND_DTV_DN5_COEF06_dtv_frontend_dn5_coef012_shift              (0)
#define  DTV_FRONTEND_DTV_DN5_COEF06_dtv_frontend_dn5_coef013_mask               (0x1FFF0000)
#define  DTV_FRONTEND_DTV_DN5_COEF06_dtv_frontend_dn5_coef012_mask               (0x00001FFF)
#define  DTV_FRONTEND_DTV_DN5_COEF06_dtv_frontend_dn5_coef013(data)              (0x1FFF0000&((data)<<16))
#define  DTV_FRONTEND_DTV_DN5_COEF06_dtv_frontend_dn5_coef012(data)              (0x00001FFF&(data))
#define  DTV_FRONTEND_DTV_DN5_COEF06_get_dtv_frontend_dn5_coef013(data)          ((0x1FFF0000&(data))>>16)
#define  DTV_FRONTEND_DTV_DN5_COEF06_get_dtv_frontend_dn5_coef012(data)          (0x00001FFF&(data))

#define  DTV_FRONTEND_DTV_DN5_COEF07                                             0x1803391C
#define  DTV_FRONTEND_DTV_DN5_COEF07_reg_addr                                    "0xB803391C"
#define  DTV_FRONTEND_DTV_DN5_COEF07_reg                                         0xB803391C
#define  DTV_FRONTEND_DTV_DN5_COEF07_inst_addr                                   "0x000F"
#define  set_DTV_FRONTEND_DTV_DN5_COEF07_reg(data)                               (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF07_reg)=data)
#define  get_DTV_FRONTEND_DTV_DN5_COEF07_reg                                     (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF07_reg))
#define  DTV_FRONTEND_DTV_DN5_COEF07_dtv_frontend_dn5_coef015_shift              (16)
#define  DTV_FRONTEND_DTV_DN5_COEF07_dtv_frontend_dn5_coef014_shift              (0)
#define  DTV_FRONTEND_DTV_DN5_COEF07_dtv_frontend_dn5_coef015_mask               (0x1FFF0000)
#define  DTV_FRONTEND_DTV_DN5_COEF07_dtv_frontend_dn5_coef014_mask               (0x00001FFF)
#define  DTV_FRONTEND_DTV_DN5_COEF07_dtv_frontend_dn5_coef015(data)              (0x1FFF0000&((data)<<16))
#define  DTV_FRONTEND_DTV_DN5_COEF07_dtv_frontend_dn5_coef014(data)              (0x00001FFF&(data))
#define  DTV_FRONTEND_DTV_DN5_COEF07_get_dtv_frontend_dn5_coef015(data)          ((0x1FFF0000&(data))>>16)
#define  DTV_FRONTEND_DTV_DN5_COEF07_get_dtv_frontend_dn5_coef014(data)          (0x00001FFF&(data))

#define  DTV_FRONTEND_DTV_DN5_COEF08                                             0x18033920
#define  DTV_FRONTEND_DTV_DN5_COEF08_reg_addr                                    "0xB8033920"
#define  DTV_FRONTEND_DTV_DN5_COEF08_reg                                         0xB8033920
#define  DTV_FRONTEND_DTV_DN5_COEF08_inst_addr                                   "0x0010"
#define  set_DTV_FRONTEND_DTV_DN5_COEF08_reg(data)                               (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF08_reg)=data)
#define  get_DTV_FRONTEND_DTV_DN5_COEF08_reg                                     (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF08_reg))
#define  DTV_FRONTEND_DTV_DN5_COEF08_dtv_frontend_dn5_coef017_shift              (16)
#define  DTV_FRONTEND_DTV_DN5_COEF08_dtv_frontend_dn5_coef016_shift              (0)
#define  DTV_FRONTEND_DTV_DN5_COEF08_dtv_frontend_dn5_coef017_mask               (0x1FFF0000)
#define  DTV_FRONTEND_DTV_DN5_COEF08_dtv_frontend_dn5_coef016_mask               (0x00001FFF)
#define  DTV_FRONTEND_DTV_DN5_COEF08_dtv_frontend_dn5_coef017(data)              (0x1FFF0000&((data)<<16))
#define  DTV_FRONTEND_DTV_DN5_COEF08_dtv_frontend_dn5_coef016(data)              (0x00001FFF&(data))
#define  DTV_FRONTEND_DTV_DN5_COEF08_get_dtv_frontend_dn5_coef017(data)          ((0x1FFF0000&(data))>>16)
#define  DTV_FRONTEND_DTV_DN5_COEF08_get_dtv_frontend_dn5_coef016(data)          (0x00001FFF&(data))

#define  DTV_FRONTEND_DTV_DN5_COEF09                                             0x18033924
#define  DTV_FRONTEND_DTV_DN5_COEF09_reg_addr                                    "0xB8033924"
#define  DTV_FRONTEND_DTV_DN5_COEF09_reg                                         0xB8033924
#define  DTV_FRONTEND_DTV_DN5_COEF09_inst_addr                                   "0x0011"
#define  set_DTV_FRONTEND_DTV_DN5_COEF09_reg(data)                               (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF09_reg)=data)
#define  get_DTV_FRONTEND_DTV_DN5_COEF09_reg                                     (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF09_reg))
#define  DTV_FRONTEND_DTV_DN5_COEF09_dtv_frontend_dn5_coef019_shift              (16)
#define  DTV_FRONTEND_DTV_DN5_COEF09_dtv_frontend_dn5_coef018_shift              (0)
#define  DTV_FRONTEND_DTV_DN5_COEF09_dtv_frontend_dn5_coef019_mask               (0x1FFF0000)
#define  DTV_FRONTEND_DTV_DN5_COEF09_dtv_frontend_dn5_coef018_mask               (0x00001FFF)
#define  DTV_FRONTEND_DTV_DN5_COEF09_dtv_frontend_dn5_coef019(data)              (0x1FFF0000&((data)<<16))
#define  DTV_FRONTEND_DTV_DN5_COEF09_dtv_frontend_dn5_coef018(data)              (0x00001FFF&(data))
#define  DTV_FRONTEND_DTV_DN5_COEF09_get_dtv_frontend_dn5_coef019(data)          ((0x1FFF0000&(data))>>16)
#define  DTV_FRONTEND_DTV_DN5_COEF09_get_dtv_frontend_dn5_coef018(data)          (0x00001FFF&(data))

#define  DTV_FRONTEND_DTV_DN5_COEF10                                             0x18033928
#define  DTV_FRONTEND_DTV_DN5_COEF10_reg_addr                                    "0xB8033928"
#define  DTV_FRONTEND_DTV_DN5_COEF10_reg                                         0xB8033928
#define  DTV_FRONTEND_DTV_DN5_COEF10_inst_addr                                   "0x0012"
#define  set_DTV_FRONTEND_DTV_DN5_COEF10_reg(data)                               (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF10_reg)=data)
#define  get_DTV_FRONTEND_DTV_DN5_COEF10_reg                                     (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF10_reg))
#define  DTV_FRONTEND_DTV_DN5_COEF10_dtv_frontend_dn5_coef021_shift              (16)
#define  DTV_FRONTEND_DTV_DN5_COEF10_dtv_frontend_dn5_coef020_shift              (0)
#define  DTV_FRONTEND_DTV_DN5_COEF10_dtv_frontend_dn5_coef021_mask               (0x1FFF0000)
#define  DTV_FRONTEND_DTV_DN5_COEF10_dtv_frontend_dn5_coef020_mask               (0x00001FFF)
#define  DTV_FRONTEND_DTV_DN5_COEF10_dtv_frontend_dn5_coef021(data)              (0x1FFF0000&((data)<<16))
#define  DTV_FRONTEND_DTV_DN5_COEF10_dtv_frontend_dn5_coef020(data)              (0x00001FFF&(data))
#define  DTV_FRONTEND_DTV_DN5_COEF10_get_dtv_frontend_dn5_coef021(data)          ((0x1FFF0000&(data))>>16)
#define  DTV_FRONTEND_DTV_DN5_COEF10_get_dtv_frontend_dn5_coef020(data)          (0x00001FFF&(data))

#define  DTV_FRONTEND_DTV_DN5_COEF11                                             0x1803392C
#define  DTV_FRONTEND_DTV_DN5_COEF11_reg_addr                                    "0xB803392C"
#define  DTV_FRONTEND_DTV_DN5_COEF11_reg                                         0xB803392C
#define  DTV_FRONTEND_DTV_DN5_COEF11_inst_addr                                   "0x0013"
#define  set_DTV_FRONTEND_DTV_DN5_COEF11_reg(data)                               (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF11_reg)=data)
#define  get_DTV_FRONTEND_DTV_DN5_COEF11_reg                                     (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF11_reg))
#define  DTV_FRONTEND_DTV_DN5_COEF11_dtv_frontend_dn5_coef023_shift              (16)
#define  DTV_FRONTEND_DTV_DN5_COEF11_dtv_frontend_dn5_coef022_shift              (0)
#define  DTV_FRONTEND_DTV_DN5_COEF11_dtv_frontend_dn5_coef023_mask               (0x1FFF0000)
#define  DTV_FRONTEND_DTV_DN5_COEF11_dtv_frontend_dn5_coef022_mask               (0x00001FFF)
#define  DTV_FRONTEND_DTV_DN5_COEF11_dtv_frontend_dn5_coef023(data)              (0x1FFF0000&((data)<<16))
#define  DTV_FRONTEND_DTV_DN5_COEF11_dtv_frontend_dn5_coef022(data)              (0x00001FFF&(data))
#define  DTV_FRONTEND_DTV_DN5_COEF11_get_dtv_frontend_dn5_coef023(data)          ((0x1FFF0000&(data))>>16)
#define  DTV_FRONTEND_DTV_DN5_COEF11_get_dtv_frontend_dn5_coef022(data)          (0x00001FFF&(data))

#define  DTV_FRONTEND_DTV_DN5_COEF12                                             0x18033930
#define  DTV_FRONTEND_DTV_DN5_COEF12_reg_addr                                    "0xB8033930"
#define  DTV_FRONTEND_DTV_DN5_COEF12_reg                                         0xB8033930
#define  DTV_FRONTEND_DTV_DN5_COEF12_inst_addr                                   "0x0014"
#define  set_DTV_FRONTEND_DTV_DN5_COEF12_reg(data)                               (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF12_reg)=data)
#define  get_DTV_FRONTEND_DTV_DN5_COEF12_reg                                     (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF12_reg))
#define  DTV_FRONTEND_DTV_DN5_COEF12_dtv_frontend_dn5_coef025_shift              (16)
#define  DTV_FRONTEND_DTV_DN5_COEF12_dtv_frontend_dn5_coef024_shift              (0)
#define  DTV_FRONTEND_DTV_DN5_COEF12_dtv_frontend_dn5_coef025_mask               (0x1FFF0000)
#define  DTV_FRONTEND_DTV_DN5_COEF12_dtv_frontend_dn5_coef024_mask               (0x00001FFF)
#define  DTV_FRONTEND_DTV_DN5_COEF12_dtv_frontend_dn5_coef025(data)              (0x1FFF0000&((data)<<16))
#define  DTV_FRONTEND_DTV_DN5_COEF12_dtv_frontend_dn5_coef024(data)              (0x00001FFF&(data))
#define  DTV_FRONTEND_DTV_DN5_COEF12_get_dtv_frontend_dn5_coef025(data)          ((0x1FFF0000&(data))>>16)
#define  DTV_FRONTEND_DTV_DN5_COEF12_get_dtv_frontend_dn5_coef024(data)          (0x00001FFF&(data))

#define  DTV_FRONTEND_DTV_DN5_COEF13                                             0x18033934
#define  DTV_FRONTEND_DTV_DN5_COEF13_reg_addr                                    "0xB8033934"
#define  DTV_FRONTEND_DTV_DN5_COEF13_reg                                         0xB8033934
#define  DTV_FRONTEND_DTV_DN5_COEF13_inst_addr                                   "0x0015"
#define  set_DTV_FRONTEND_DTV_DN5_COEF13_reg(data)                               (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF13_reg)=data)
#define  get_DTV_FRONTEND_DTV_DN5_COEF13_reg                                     (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF13_reg))
#define  DTV_FRONTEND_DTV_DN5_COEF13_dtv_frontend_dn5_coef027_shift              (16)
#define  DTV_FRONTEND_DTV_DN5_COEF13_dtv_frontend_dn5_coef026_shift              (0)
#define  DTV_FRONTEND_DTV_DN5_COEF13_dtv_frontend_dn5_coef027_mask               (0x1FFF0000)
#define  DTV_FRONTEND_DTV_DN5_COEF13_dtv_frontend_dn5_coef026_mask               (0x00001FFF)
#define  DTV_FRONTEND_DTV_DN5_COEF13_dtv_frontend_dn5_coef027(data)              (0x1FFF0000&((data)<<16))
#define  DTV_FRONTEND_DTV_DN5_COEF13_dtv_frontend_dn5_coef026(data)              (0x00001FFF&(data))
#define  DTV_FRONTEND_DTV_DN5_COEF13_get_dtv_frontend_dn5_coef027(data)          ((0x1FFF0000&(data))>>16)
#define  DTV_FRONTEND_DTV_DN5_COEF13_get_dtv_frontend_dn5_coef026(data)          (0x00001FFF&(data))

#define  DTV_FRONTEND_DTV_DN5_COEF14                                             0x18033938
#define  DTV_FRONTEND_DTV_DN5_COEF14_reg_addr                                    "0xB8033938"
#define  DTV_FRONTEND_DTV_DN5_COEF14_reg                                         0xB8033938
#define  DTV_FRONTEND_DTV_DN5_COEF14_inst_addr                                   "0x0016"
#define  set_DTV_FRONTEND_DTV_DN5_COEF14_reg(data)                               (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF14_reg)=data)
#define  get_DTV_FRONTEND_DTV_DN5_COEF14_reg                                     (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF14_reg))
#define  DTV_FRONTEND_DTV_DN5_COEF14_dtv_frontend_dn5_coef029_shift              (16)
#define  DTV_FRONTEND_DTV_DN5_COEF14_dtv_frontend_dn5_coef028_shift              (0)
#define  DTV_FRONTEND_DTV_DN5_COEF14_dtv_frontend_dn5_coef029_mask               (0x1FFF0000)
#define  DTV_FRONTEND_DTV_DN5_COEF14_dtv_frontend_dn5_coef028_mask               (0x00001FFF)
#define  DTV_FRONTEND_DTV_DN5_COEF14_dtv_frontend_dn5_coef029(data)              (0x1FFF0000&((data)<<16))
#define  DTV_FRONTEND_DTV_DN5_COEF14_dtv_frontend_dn5_coef028(data)              (0x00001FFF&(data))
#define  DTV_FRONTEND_DTV_DN5_COEF14_get_dtv_frontend_dn5_coef029(data)          ((0x1FFF0000&(data))>>16)
#define  DTV_FRONTEND_DTV_DN5_COEF14_get_dtv_frontend_dn5_coef028(data)          (0x00001FFF&(data))

#define  DTV_FRONTEND_DTV_DN5_COEF15                                             0x1803393C
#define  DTV_FRONTEND_DTV_DN5_COEF15_reg_addr                                    "0xB803393C"
#define  DTV_FRONTEND_DTV_DN5_COEF15_reg                                         0xB803393C
#define  DTV_FRONTEND_DTV_DN5_COEF15_inst_addr                                   "0x0017"
#define  set_DTV_FRONTEND_DTV_DN5_COEF15_reg(data)                               (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF15_reg)=data)
#define  get_DTV_FRONTEND_DTV_DN5_COEF15_reg                                     (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF15_reg))
#define  DTV_FRONTEND_DTV_DN5_COEF15_dtv_frontend_dn5_coef031_shift              (16)
#define  DTV_FRONTEND_DTV_DN5_COEF15_dtv_frontend_dn5_coef030_shift              (0)
#define  DTV_FRONTEND_DTV_DN5_COEF15_dtv_frontend_dn5_coef031_mask               (0x1FFF0000)
#define  DTV_FRONTEND_DTV_DN5_COEF15_dtv_frontend_dn5_coef030_mask               (0x00001FFF)
#define  DTV_FRONTEND_DTV_DN5_COEF15_dtv_frontend_dn5_coef031(data)              (0x1FFF0000&((data)<<16))
#define  DTV_FRONTEND_DTV_DN5_COEF15_dtv_frontend_dn5_coef030(data)              (0x00001FFF&(data))
#define  DTV_FRONTEND_DTV_DN5_COEF15_get_dtv_frontend_dn5_coef031(data)          ((0x1FFF0000&(data))>>16)
#define  DTV_FRONTEND_DTV_DN5_COEF15_get_dtv_frontend_dn5_coef030(data)          (0x00001FFF&(data))

#define  DTV_FRONTEND_DTV_DN5_COEF16                                             0x18033940
#define  DTV_FRONTEND_DTV_DN5_COEF16_reg_addr                                    "0xB8033940"
#define  DTV_FRONTEND_DTV_DN5_COEF16_reg                                         0xB8033940
#define  DTV_FRONTEND_DTV_DN5_COEF16_inst_addr                                   "0x0018"
#define  set_DTV_FRONTEND_DTV_DN5_COEF16_reg(data)                               (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF16_reg)=data)
#define  get_DTV_FRONTEND_DTV_DN5_COEF16_reg                                     (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF16_reg))
#define  DTV_FRONTEND_DTV_DN5_COEF16_dtv_frontend_dn5_coef033_shift              (16)
#define  DTV_FRONTEND_DTV_DN5_COEF16_dtv_frontend_dn5_coef032_shift              (0)
#define  DTV_FRONTEND_DTV_DN5_COEF16_dtv_frontend_dn5_coef033_mask               (0x1FFF0000)
#define  DTV_FRONTEND_DTV_DN5_COEF16_dtv_frontend_dn5_coef032_mask               (0x00001FFF)
#define  DTV_FRONTEND_DTV_DN5_COEF16_dtv_frontend_dn5_coef033(data)              (0x1FFF0000&((data)<<16))
#define  DTV_FRONTEND_DTV_DN5_COEF16_dtv_frontend_dn5_coef032(data)              (0x00001FFF&(data))
#define  DTV_FRONTEND_DTV_DN5_COEF16_get_dtv_frontend_dn5_coef033(data)          ((0x1FFF0000&(data))>>16)
#define  DTV_FRONTEND_DTV_DN5_COEF16_get_dtv_frontend_dn5_coef032(data)          (0x00001FFF&(data))

#define  DTV_FRONTEND_DTV_DN5_COEF17                                             0x18033944
#define  DTV_FRONTEND_DTV_DN5_COEF17_reg_addr                                    "0xB8033944"
#define  DTV_FRONTEND_DTV_DN5_COEF17_reg                                         0xB8033944
#define  DTV_FRONTEND_DTV_DN5_COEF17_inst_addr                                   "0x0019"
#define  set_DTV_FRONTEND_DTV_DN5_COEF17_reg(data)                               (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF17_reg)=data)
#define  get_DTV_FRONTEND_DTV_DN5_COEF17_reg                                     (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF17_reg))
#define  DTV_FRONTEND_DTV_DN5_COEF17_dtv_frontend_dn5_coef035_shift              (16)
#define  DTV_FRONTEND_DTV_DN5_COEF17_dtv_frontend_dn5_coef034_shift              (0)
#define  DTV_FRONTEND_DTV_DN5_COEF17_dtv_frontend_dn5_coef035_mask               (0x1FFF0000)
#define  DTV_FRONTEND_DTV_DN5_COEF17_dtv_frontend_dn5_coef034_mask               (0x00001FFF)
#define  DTV_FRONTEND_DTV_DN5_COEF17_dtv_frontend_dn5_coef035(data)              (0x1FFF0000&((data)<<16))
#define  DTV_FRONTEND_DTV_DN5_COEF17_dtv_frontend_dn5_coef034(data)              (0x00001FFF&(data))
#define  DTV_FRONTEND_DTV_DN5_COEF17_get_dtv_frontend_dn5_coef035(data)          ((0x1FFF0000&(data))>>16)
#define  DTV_FRONTEND_DTV_DN5_COEF17_get_dtv_frontend_dn5_coef034(data)          (0x00001FFF&(data))

#define  DTV_FRONTEND_DTV_DN5_COEF18                                             0x18033948
#define  DTV_FRONTEND_DTV_DN5_COEF18_reg_addr                                    "0xB8033948"
#define  DTV_FRONTEND_DTV_DN5_COEF18_reg                                         0xB8033948
#define  DTV_FRONTEND_DTV_DN5_COEF18_inst_addr                                   "0x001A"
#define  set_DTV_FRONTEND_DTV_DN5_COEF18_reg(data)                               (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF18_reg)=data)
#define  get_DTV_FRONTEND_DTV_DN5_COEF18_reg                                     (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF18_reg))
#define  DTV_FRONTEND_DTV_DN5_COEF18_dtv_frontend_dn5_coef037_shift              (16)
#define  DTV_FRONTEND_DTV_DN5_COEF18_dtv_frontend_dn5_coef036_shift              (0)
#define  DTV_FRONTEND_DTV_DN5_COEF18_dtv_frontend_dn5_coef037_mask               (0x1FFF0000)
#define  DTV_FRONTEND_DTV_DN5_COEF18_dtv_frontend_dn5_coef036_mask               (0x00001FFF)
#define  DTV_FRONTEND_DTV_DN5_COEF18_dtv_frontend_dn5_coef037(data)              (0x1FFF0000&((data)<<16))
#define  DTV_FRONTEND_DTV_DN5_COEF18_dtv_frontend_dn5_coef036(data)              (0x00001FFF&(data))
#define  DTV_FRONTEND_DTV_DN5_COEF18_get_dtv_frontend_dn5_coef037(data)          ((0x1FFF0000&(data))>>16)
#define  DTV_FRONTEND_DTV_DN5_COEF18_get_dtv_frontend_dn5_coef036(data)          (0x00001FFF&(data))

#define  DTV_FRONTEND_DTV_DN5_COEF19                                             0x1803394C
#define  DTV_FRONTEND_DTV_DN5_COEF19_reg_addr                                    "0xB803394C"
#define  DTV_FRONTEND_DTV_DN5_COEF19_reg                                         0xB803394C
#define  DTV_FRONTEND_DTV_DN5_COEF19_inst_addr                                   "0x001B"
#define  set_DTV_FRONTEND_DTV_DN5_COEF19_reg(data)                               (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF19_reg)=data)
#define  get_DTV_FRONTEND_DTV_DN5_COEF19_reg                                     (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF19_reg))
#define  DTV_FRONTEND_DTV_DN5_COEF19_dtv_frontend_dn5_coef039_shift              (16)
#define  DTV_FRONTEND_DTV_DN5_COEF19_dtv_frontend_dn5_coef038_shift              (0)
#define  DTV_FRONTEND_DTV_DN5_COEF19_dtv_frontend_dn5_coef039_mask               (0x1FFF0000)
#define  DTV_FRONTEND_DTV_DN5_COEF19_dtv_frontend_dn5_coef038_mask               (0x00001FFF)
#define  DTV_FRONTEND_DTV_DN5_COEF19_dtv_frontend_dn5_coef039(data)              (0x1FFF0000&((data)<<16))
#define  DTV_FRONTEND_DTV_DN5_COEF19_dtv_frontend_dn5_coef038(data)              (0x00001FFF&(data))
#define  DTV_FRONTEND_DTV_DN5_COEF19_get_dtv_frontend_dn5_coef039(data)          ((0x1FFF0000&(data))>>16)
#define  DTV_FRONTEND_DTV_DN5_COEF19_get_dtv_frontend_dn5_coef038(data)          (0x00001FFF&(data))

#define  DTV_FRONTEND_DTV_DN5_COEF20                                             0x18033950
#define  DTV_FRONTEND_DTV_DN5_COEF20_reg_addr                                    "0xB8033950"
#define  DTV_FRONTEND_DTV_DN5_COEF20_reg                                         0xB8033950
#define  DTV_FRONTEND_DTV_DN5_COEF20_inst_addr                                   "0x001C"
#define  set_DTV_FRONTEND_DTV_DN5_COEF20_reg(data)                               (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF20_reg)=data)
#define  get_DTV_FRONTEND_DTV_DN5_COEF20_reg                                     (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF20_reg))
#define  DTV_FRONTEND_DTV_DN5_COEF20_dtv_frontend_dn5_coef041_shift              (16)
#define  DTV_FRONTEND_DTV_DN5_COEF20_dtv_frontend_dn5_coef040_shift              (0)
#define  DTV_FRONTEND_DTV_DN5_COEF20_dtv_frontend_dn5_coef041_mask               (0x1FFF0000)
#define  DTV_FRONTEND_DTV_DN5_COEF20_dtv_frontend_dn5_coef040_mask               (0x00001FFF)
#define  DTV_FRONTEND_DTV_DN5_COEF20_dtv_frontend_dn5_coef041(data)              (0x1FFF0000&((data)<<16))
#define  DTV_FRONTEND_DTV_DN5_COEF20_dtv_frontend_dn5_coef040(data)              (0x00001FFF&(data))
#define  DTV_FRONTEND_DTV_DN5_COEF20_get_dtv_frontend_dn5_coef041(data)          ((0x1FFF0000&(data))>>16)
#define  DTV_FRONTEND_DTV_DN5_COEF20_get_dtv_frontend_dn5_coef040(data)          (0x00001FFF&(data))

#define  DTV_FRONTEND_DTV_DN5_COEF21                                             0x18033954
#define  DTV_FRONTEND_DTV_DN5_COEF21_reg_addr                                    "0xB8033954"
#define  DTV_FRONTEND_DTV_DN5_COEF21_reg                                         0xB8033954
#define  DTV_FRONTEND_DTV_DN5_COEF21_inst_addr                                   "0x001D"
#define  set_DTV_FRONTEND_DTV_DN5_COEF21_reg(data)                               (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF21_reg)=data)
#define  get_DTV_FRONTEND_DTV_DN5_COEF21_reg                                     (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF21_reg))
#define  DTV_FRONTEND_DTV_DN5_COEF21_dtv_frontend_dn5_coef043_shift              (16)
#define  DTV_FRONTEND_DTV_DN5_COEF21_dtv_frontend_dn5_coef042_shift              (0)
#define  DTV_FRONTEND_DTV_DN5_COEF21_dtv_frontend_dn5_coef043_mask               (0x1FFF0000)
#define  DTV_FRONTEND_DTV_DN5_COEF21_dtv_frontend_dn5_coef042_mask               (0x00001FFF)
#define  DTV_FRONTEND_DTV_DN5_COEF21_dtv_frontend_dn5_coef043(data)              (0x1FFF0000&((data)<<16))
#define  DTV_FRONTEND_DTV_DN5_COEF21_dtv_frontend_dn5_coef042(data)              (0x00001FFF&(data))
#define  DTV_FRONTEND_DTV_DN5_COEF21_get_dtv_frontend_dn5_coef043(data)          ((0x1FFF0000&(data))>>16)
#define  DTV_FRONTEND_DTV_DN5_COEF21_get_dtv_frontend_dn5_coef042(data)          (0x00001FFF&(data))

#define  DTV_FRONTEND_DTV_DN5_COEF22                                             0x18033958
#define  DTV_FRONTEND_DTV_DN5_COEF22_reg_addr                                    "0xB8033958"
#define  DTV_FRONTEND_DTV_DN5_COEF22_reg                                         0xB8033958
#define  DTV_FRONTEND_DTV_DN5_COEF22_inst_addr                                   "0x001E"
#define  set_DTV_FRONTEND_DTV_DN5_COEF22_reg(data)                               (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF22_reg)=data)
#define  get_DTV_FRONTEND_DTV_DN5_COEF22_reg                                     (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF22_reg))
#define  DTV_FRONTEND_DTV_DN5_COEF22_dtv_frontend_dn5_coef045_shift              (16)
#define  DTV_FRONTEND_DTV_DN5_COEF22_dtv_frontend_dn5_coef044_shift              (0)
#define  DTV_FRONTEND_DTV_DN5_COEF22_dtv_frontend_dn5_coef045_mask               (0x1FFF0000)
#define  DTV_FRONTEND_DTV_DN5_COEF22_dtv_frontend_dn5_coef044_mask               (0x00001FFF)
#define  DTV_FRONTEND_DTV_DN5_COEF22_dtv_frontend_dn5_coef045(data)              (0x1FFF0000&((data)<<16))
#define  DTV_FRONTEND_DTV_DN5_COEF22_dtv_frontend_dn5_coef044(data)              (0x00001FFF&(data))
#define  DTV_FRONTEND_DTV_DN5_COEF22_get_dtv_frontend_dn5_coef045(data)          ((0x1FFF0000&(data))>>16)
#define  DTV_FRONTEND_DTV_DN5_COEF22_get_dtv_frontend_dn5_coef044(data)          (0x00001FFF&(data))

#define  DTV_FRONTEND_DTV_DN5_COEF23                                             0x1803395C
#define  DTV_FRONTEND_DTV_DN5_COEF23_reg_addr                                    "0xB803395C"
#define  DTV_FRONTEND_DTV_DN5_COEF23_reg                                         0xB803395C
#define  DTV_FRONTEND_DTV_DN5_COEF23_inst_addr                                   "0x001F"
#define  set_DTV_FRONTEND_DTV_DN5_COEF23_reg(data)                               (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF23_reg)=data)
#define  get_DTV_FRONTEND_DTV_DN5_COEF23_reg                                     (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF23_reg))
#define  DTV_FRONTEND_DTV_DN5_COEF23_dtv_frontend_dn5_coef047_shift              (16)
#define  DTV_FRONTEND_DTV_DN5_COEF23_dtv_frontend_dn5_coef046_shift              (0)
#define  DTV_FRONTEND_DTV_DN5_COEF23_dtv_frontend_dn5_coef047_mask               (0x1FFF0000)
#define  DTV_FRONTEND_DTV_DN5_COEF23_dtv_frontend_dn5_coef046_mask               (0x00001FFF)
#define  DTV_FRONTEND_DTV_DN5_COEF23_dtv_frontend_dn5_coef047(data)              (0x1FFF0000&((data)<<16))
#define  DTV_FRONTEND_DTV_DN5_COEF23_dtv_frontend_dn5_coef046(data)              (0x00001FFF&(data))
#define  DTV_FRONTEND_DTV_DN5_COEF23_get_dtv_frontend_dn5_coef047(data)          ((0x1FFF0000&(data))>>16)
#define  DTV_FRONTEND_DTV_DN5_COEF23_get_dtv_frontend_dn5_coef046(data)          (0x00001FFF&(data))

#define  DTV_FRONTEND_DTV_DN5_COEF24                                             0x18033960
#define  DTV_FRONTEND_DTV_DN5_COEF24_reg_addr                                    "0xB8033960"
#define  DTV_FRONTEND_DTV_DN5_COEF24_reg                                         0xB8033960
#define  DTV_FRONTEND_DTV_DN5_COEF24_inst_addr                                   "0x0020"
#define  set_DTV_FRONTEND_DTV_DN5_COEF24_reg(data)                               (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF24_reg)=data)
#define  get_DTV_FRONTEND_DTV_DN5_COEF24_reg                                     (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF24_reg))
#define  DTV_FRONTEND_DTV_DN5_COEF24_dtv_frontend_dn5_coef049_shift              (16)
#define  DTV_FRONTEND_DTV_DN5_COEF24_dtv_frontend_dn5_coef048_shift              (0)
#define  DTV_FRONTEND_DTV_DN5_COEF24_dtv_frontend_dn5_coef049_mask               (0x1FFF0000)
#define  DTV_FRONTEND_DTV_DN5_COEF24_dtv_frontend_dn5_coef048_mask               (0x00001FFF)
#define  DTV_FRONTEND_DTV_DN5_COEF24_dtv_frontend_dn5_coef049(data)              (0x1FFF0000&((data)<<16))
#define  DTV_FRONTEND_DTV_DN5_COEF24_dtv_frontend_dn5_coef048(data)              (0x00001FFF&(data))
#define  DTV_FRONTEND_DTV_DN5_COEF24_get_dtv_frontend_dn5_coef049(data)          ((0x1FFF0000&(data))>>16)
#define  DTV_FRONTEND_DTV_DN5_COEF24_get_dtv_frontend_dn5_coef048(data)          (0x00001FFF&(data))

#define  DTV_FRONTEND_DTV_DN5_COEF25                                             0x18033964
#define  DTV_FRONTEND_DTV_DN5_COEF25_reg_addr                                    "0xB8033964"
#define  DTV_FRONTEND_DTV_DN5_COEF25_reg                                         0xB8033964
#define  DTV_FRONTEND_DTV_DN5_COEF25_inst_addr                                   "0x0021"
#define  set_DTV_FRONTEND_DTV_DN5_COEF25_reg(data)                               (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF25_reg)=data)
#define  get_DTV_FRONTEND_DTV_DN5_COEF25_reg                                     (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF25_reg))
#define  DTV_FRONTEND_DTV_DN5_COEF25_dtv_frontend_dn5_coef051_shift              (16)
#define  DTV_FRONTEND_DTV_DN5_COEF25_dtv_frontend_dn5_coef050_shift              (0)
#define  DTV_FRONTEND_DTV_DN5_COEF25_dtv_frontend_dn5_coef051_mask               (0x1FFF0000)
#define  DTV_FRONTEND_DTV_DN5_COEF25_dtv_frontend_dn5_coef050_mask               (0x00001FFF)
#define  DTV_FRONTEND_DTV_DN5_COEF25_dtv_frontend_dn5_coef051(data)              (0x1FFF0000&((data)<<16))
#define  DTV_FRONTEND_DTV_DN5_COEF25_dtv_frontend_dn5_coef050(data)              (0x00001FFF&(data))
#define  DTV_FRONTEND_DTV_DN5_COEF25_get_dtv_frontend_dn5_coef051(data)          ((0x1FFF0000&(data))>>16)
#define  DTV_FRONTEND_DTV_DN5_COEF25_get_dtv_frontend_dn5_coef050(data)          (0x00001FFF&(data))

#define  DTV_FRONTEND_DTV_DN5_COEF26                                             0x18033968
#define  DTV_FRONTEND_DTV_DN5_COEF26_reg_addr                                    "0xB8033968"
#define  DTV_FRONTEND_DTV_DN5_COEF26_reg                                         0xB8033968
#define  DTV_FRONTEND_DTV_DN5_COEF26_inst_addr                                   "0x0022"
#define  set_DTV_FRONTEND_DTV_DN5_COEF26_reg(data)                               (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF26_reg)=data)
#define  get_DTV_FRONTEND_DTV_DN5_COEF26_reg                                     (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF26_reg))
#define  DTV_FRONTEND_DTV_DN5_COEF26_dtv_frontend_dn5_coef053_shift              (16)
#define  DTV_FRONTEND_DTV_DN5_COEF26_dtv_frontend_dn5_coef052_shift              (0)
#define  DTV_FRONTEND_DTV_DN5_COEF26_dtv_frontend_dn5_coef053_mask               (0x1FFF0000)
#define  DTV_FRONTEND_DTV_DN5_COEF26_dtv_frontend_dn5_coef052_mask               (0x00001FFF)
#define  DTV_FRONTEND_DTV_DN5_COEF26_dtv_frontend_dn5_coef053(data)              (0x1FFF0000&((data)<<16))
#define  DTV_FRONTEND_DTV_DN5_COEF26_dtv_frontend_dn5_coef052(data)              (0x00001FFF&(data))
#define  DTV_FRONTEND_DTV_DN5_COEF26_get_dtv_frontend_dn5_coef053(data)          ((0x1FFF0000&(data))>>16)
#define  DTV_FRONTEND_DTV_DN5_COEF26_get_dtv_frontend_dn5_coef052(data)          (0x00001FFF&(data))

#define  DTV_FRONTEND_DTV_DN5_COEF27                                             0x1803396C
#define  DTV_FRONTEND_DTV_DN5_COEF27_reg_addr                                    "0xB803396C"
#define  DTV_FRONTEND_DTV_DN5_COEF27_reg                                         0xB803396C
#define  DTV_FRONTEND_DTV_DN5_COEF27_inst_addr                                   "0x0023"
#define  set_DTV_FRONTEND_DTV_DN5_COEF27_reg(data)                               (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF27_reg)=data)
#define  get_DTV_FRONTEND_DTV_DN5_COEF27_reg                                     (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF27_reg))
#define  DTV_FRONTEND_DTV_DN5_COEF27_dtv_frontend_dn5_coef055_shift              (16)
#define  DTV_FRONTEND_DTV_DN5_COEF27_dtv_frontend_dn5_coef054_shift              (0)
#define  DTV_FRONTEND_DTV_DN5_COEF27_dtv_frontend_dn5_coef055_mask               (0x1FFF0000)
#define  DTV_FRONTEND_DTV_DN5_COEF27_dtv_frontend_dn5_coef054_mask               (0x00001FFF)
#define  DTV_FRONTEND_DTV_DN5_COEF27_dtv_frontend_dn5_coef055(data)              (0x1FFF0000&((data)<<16))
#define  DTV_FRONTEND_DTV_DN5_COEF27_dtv_frontend_dn5_coef054(data)              (0x00001FFF&(data))
#define  DTV_FRONTEND_DTV_DN5_COEF27_get_dtv_frontend_dn5_coef055(data)          ((0x1FFF0000&(data))>>16)
#define  DTV_FRONTEND_DTV_DN5_COEF27_get_dtv_frontend_dn5_coef054(data)          (0x00001FFF&(data))

#define  DTV_FRONTEND_DTV_DN5_COEF28                                             0x18033970
#define  DTV_FRONTEND_DTV_DN5_COEF28_reg_addr                                    "0xB8033970"
#define  DTV_FRONTEND_DTV_DN5_COEF28_reg                                         0xB8033970
#define  DTV_FRONTEND_DTV_DN5_COEF28_inst_addr                                   "0x0024"
#define  set_DTV_FRONTEND_DTV_DN5_COEF28_reg(data)                               (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF28_reg)=data)
#define  get_DTV_FRONTEND_DTV_DN5_COEF28_reg                                     (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF28_reg))
#define  DTV_FRONTEND_DTV_DN5_COEF28_dtv_frontend_dn5_coef057_shift              (16)
#define  DTV_FRONTEND_DTV_DN5_COEF28_dtv_frontend_dn5_coef056_shift              (0)
#define  DTV_FRONTEND_DTV_DN5_COEF28_dtv_frontend_dn5_coef057_mask               (0x1FFF0000)
#define  DTV_FRONTEND_DTV_DN5_COEF28_dtv_frontend_dn5_coef056_mask               (0x00001FFF)
#define  DTV_FRONTEND_DTV_DN5_COEF28_dtv_frontend_dn5_coef057(data)              (0x1FFF0000&((data)<<16))
#define  DTV_FRONTEND_DTV_DN5_COEF28_dtv_frontend_dn5_coef056(data)              (0x00001FFF&(data))
#define  DTV_FRONTEND_DTV_DN5_COEF28_get_dtv_frontend_dn5_coef057(data)          ((0x1FFF0000&(data))>>16)
#define  DTV_FRONTEND_DTV_DN5_COEF28_get_dtv_frontend_dn5_coef056(data)          (0x00001FFF&(data))

#define  DTV_FRONTEND_DTV_DN5_COEF29                                             0x18033974
#define  DTV_FRONTEND_DTV_DN5_COEF29_reg_addr                                    "0xB8033974"
#define  DTV_FRONTEND_DTV_DN5_COEF29_reg                                         0xB8033974
#define  DTV_FRONTEND_DTV_DN5_COEF29_inst_addr                                   "0x0025"
#define  set_DTV_FRONTEND_DTV_DN5_COEF29_reg(data)                               (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF29_reg)=data)
#define  get_DTV_FRONTEND_DTV_DN5_COEF29_reg                                     (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF29_reg))
#define  DTV_FRONTEND_DTV_DN5_COEF29_dtv_frontend_dn5_coef059_shift              (16)
#define  DTV_FRONTEND_DTV_DN5_COEF29_dtv_frontend_dn5_coef058_shift              (0)
#define  DTV_FRONTEND_DTV_DN5_COEF29_dtv_frontend_dn5_coef059_mask               (0x1FFF0000)
#define  DTV_FRONTEND_DTV_DN5_COEF29_dtv_frontend_dn5_coef058_mask               (0x00001FFF)
#define  DTV_FRONTEND_DTV_DN5_COEF29_dtv_frontend_dn5_coef059(data)              (0x1FFF0000&((data)<<16))
#define  DTV_FRONTEND_DTV_DN5_COEF29_dtv_frontend_dn5_coef058(data)              (0x00001FFF&(data))
#define  DTV_FRONTEND_DTV_DN5_COEF29_get_dtv_frontend_dn5_coef059(data)          ((0x1FFF0000&(data))>>16)
#define  DTV_FRONTEND_DTV_DN5_COEF29_get_dtv_frontend_dn5_coef058(data)          (0x00001FFF&(data))

#define  DTV_FRONTEND_DTV_DN5_COEF30                                             0x18033978
#define  DTV_FRONTEND_DTV_DN5_COEF30_reg_addr                                    "0xB8033978"
#define  DTV_FRONTEND_DTV_DN5_COEF30_reg                                         0xB8033978
#define  DTV_FRONTEND_DTV_DN5_COEF30_inst_addr                                   "0x0026"
#define  set_DTV_FRONTEND_DTV_DN5_COEF30_reg(data)                               (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF30_reg)=data)
#define  get_DTV_FRONTEND_DTV_DN5_COEF30_reg                                     (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF30_reg))
#define  DTV_FRONTEND_DTV_DN5_COEF30_dtv_frontend_dn5_coef061_shift              (16)
#define  DTV_FRONTEND_DTV_DN5_COEF30_dtv_frontend_dn5_coef060_shift              (0)
#define  DTV_FRONTEND_DTV_DN5_COEF30_dtv_frontend_dn5_coef061_mask               (0x1FFF0000)
#define  DTV_FRONTEND_DTV_DN5_COEF30_dtv_frontend_dn5_coef060_mask               (0x00001FFF)
#define  DTV_FRONTEND_DTV_DN5_COEF30_dtv_frontend_dn5_coef061(data)              (0x1FFF0000&((data)<<16))
#define  DTV_FRONTEND_DTV_DN5_COEF30_dtv_frontend_dn5_coef060(data)              (0x00001FFF&(data))
#define  DTV_FRONTEND_DTV_DN5_COEF30_get_dtv_frontend_dn5_coef061(data)          ((0x1FFF0000&(data))>>16)
#define  DTV_FRONTEND_DTV_DN5_COEF30_get_dtv_frontend_dn5_coef060(data)          (0x00001FFF&(data))

#define  DTV_FRONTEND_DTV_DN5_COEF31                                             0x1803397C
#define  DTV_FRONTEND_DTV_DN5_COEF31_reg_addr                                    "0xB803397C"
#define  DTV_FRONTEND_DTV_DN5_COEF31_reg                                         0xB803397C
#define  DTV_FRONTEND_DTV_DN5_COEF31_inst_addr                                   "0x0027"
#define  set_DTV_FRONTEND_DTV_DN5_COEF31_reg(data)                               (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF31_reg)=data)
#define  get_DTV_FRONTEND_DTV_DN5_COEF31_reg                                     (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF31_reg))
#define  DTV_FRONTEND_DTV_DN5_COEF31_dtv_frontend_dn5_coef063_shift              (16)
#define  DTV_FRONTEND_DTV_DN5_COEF31_dtv_frontend_dn5_coef062_shift              (0)
#define  DTV_FRONTEND_DTV_DN5_COEF31_dtv_frontend_dn5_coef063_mask               (0x1FFF0000)
#define  DTV_FRONTEND_DTV_DN5_COEF31_dtv_frontend_dn5_coef062_mask               (0x00001FFF)
#define  DTV_FRONTEND_DTV_DN5_COEF31_dtv_frontend_dn5_coef063(data)              (0x1FFF0000&((data)<<16))
#define  DTV_FRONTEND_DTV_DN5_COEF31_dtv_frontend_dn5_coef062(data)              (0x00001FFF&(data))
#define  DTV_FRONTEND_DTV_DN5_COEF31_get_dtv_frontend_dn5_coef063(data)          ((0x1FFF0000&(data))>>16)
#define  DTV_FRONTEND_DTV_DN5_COEF31_get_dtv_frontend_dn5_coef062(data)          (0x00001FFF&(data))

#define  DTV_FRONTEND_DTV_DN5_COEF32                                             0x18033980
#define  DTV_FRONTEND_DTV_DN5_COEF32_reg_addr                                    "0xB8033980"
#define  DTV_FRONTEND_DTV_DN5_COEF32_reg                                         0xB8033980
#define  DTV_FRONTEND_DTV_DN5_COEF32_inst_addr                                   "0x0028"
#define  set_DTV_FRONTEND_DTV_DN5_COEF32_reg(data)                               (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF32_reg)=data)
#define  get_DTV_FRONTEND_DTV_DN5_COEF32_reg                                     (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF32_reg))
#define  DTV_FRONTEND_DTV_DN5_COEF32_dtv_frontend_dn5_coef065_shift              (16)
#define  DTV_FRONTEND_DTV_DN5_COEF32_dtv_frontend_dn5_coef064_shift              (0)
#define  DTV_FRONTEND_DTV_DN5_COEF32_dtv_frontend_dn5_coef065_mask               (0x1FFF0000)
#define  DTV_FRONTEND_DTV_DN5_COEF32_dtv_frontend_dn5_coef064_mask               (0x00001FFF)
#define  DTV_FRONTEND_DTV_DN5_COEF32_dtv_frontend_dn5_coef065(data)              (0x1FFF0000&((data)<<16))
#define  DTV_FRONTEND_DTV_DN5_COEF32_dtv_frontend_dn5_coef064(data)              (0x00001FFF&(data))
#define  DTV_FRONTEND_DTV_DN5_COEF32_get_dtv_frontend_dn5_coef065(data)          ((0x1FFF0000&(data))>>16)
#define  DTV_FRONTEND_DTV_DN5_COEF32_get_dtv_frontend_dn5_coef064(data)          (0x00001FFF&(data))

#define  DTV_FRONTEND_DTV_DN5_COEF33                                             0x18033984
#define  DTV_FRONTEND_DTV_DN5_COEF33_reg_addr                                    "0xB8033984"
#define  DTV_FRONTEND_DTV_DN5_COEF33_reg                                         0xB8033984
#define  DTV_FRONTEND_DTV_DN5_COEF33_inst_addr                                   "0x0029"
#define  set_DTV_FRONTEND_DTV_DN5_COEF33_reg(data)                               (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF33_reg)=data)
#define  get_DTV_FRONTEND_DTV_DN5_COEF33_reg                                     (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF33_reg))
#define  DTV_FRONTEND_DTV_DN5_COEF33_dtv_frontend_dn5_coef067_shift              (16)
#define  DTV_FRONTEND_DTV_DN5_COEF33_dtv_frontend_dn5_coef066_shift              (0)
#define  DTV_FRONTEND_DTV_DN5_COEF33_dtv_frontend_dn5_coef067_mask               (0x1FFF0000)
#define  DTV_FRONTEND_DTV_DN5_COEF33_dtv_frontend_dn5_coef066_mask               (0x00001FFF)
#define  DTV_FRONTEND_DTV_DN5_COEF33_dtv_frontend_dn5_coef067(data)              (0x1FFF0000&((data)<<16))
#define  DTV_FRONTEND_DTV_DN5_COEF33_dtv_frontend_dn5_coef066(data)              (0x00001FFF&(data))
#define  DTV_FRONTEND_DTV_DN5_COEF33_get_dtv_frontend_dn5_coef067(data)          ((0x1FFF0000&(data))>>16)
#define  DTV_FRONTEND_DTV_DN5_COEF33_get_dtv_frontend_dn5_coef066(data)          (0x00001FFF&(data))

#define  DTV_FRONTEND_DTV_DN5_COEF34                                             0x18033988
#define  DTV_FRONTEND_DTV_DN5_COEF34_reg_addr                                    "0xB8033988"
#define  DTV_FRONTEND_DTV_DN5_COEF34_reg                                         0xB8033988
#define  DTV_FRONTEND_DTV_DN5_COEF34_inst_addr                                   "0x002A"
#define  set_DTV_FRONTEND_DTV_DN5_COEF34_reg(data)                               (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF34_reg)=data)
#define  get_DTV_FRONTEND_DTV_DN5_COEF34_reg                                     (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF34_reg))
#define  DTV_FRONTEND_DTV_DN5_COEF34_dtv_frontend_dn5_coef069_shift              (16)
#define  DTV_FRONTEND_DTV_DN5_COEF34_dtv_frontend_dn5_coef068_shift              (0)
#define  DTV_FRONTEND_DTV_DN5_COEF34_dtv_frontend_dn5_coef069_mask               (0x1FFF0000)
#define  DTV_FRONTEND_DTV_DN5_COEF34_dtv_frontend_dn5_coef068_mask               (0x00001FFF)
#define  DTV_FRONTEND_DTV_DN5_COEF34_dtv_frontend_dn5_coef069(data)              (0x1FFF0000&((data)<<16))
#define  DTV_FRONTEND_DTV_DN5_COEF34_dtv_frontend_dn5_coef068(data)              (0x00001FFF&(data))
#define  DTV_FRONTEND_DTV_DN5_COEF34_get_dtv_frontend_dn5_coef069(data)          ((0x1FFF0000&(data))>>16)
#define  DTV_FRONTEND_DTV_DN5_COEF34_get_dtv_frontend_dn5_coef068(data)          (0x00001FFF&(data))

#define  DTV_FRONTEND_DTV_DN5_COEF35                                             0x1803398C
#define  DTV_FRONTEND_DTV_DN5_COEF35_reg_addr                                    "0xB803398C"
#define  DTV_FRONTEND_DTV_DN5_COEF35_reg                                         0xB803398C
#define  DTV_FRONTEND_DTV_DN5_COEF35_inst_addr                                   "0x002B"
#define  set_DTV_FRONTEND_DTV_DN5_COEF35_reg(data)                               (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF35_reg)=data)
#define  get_DTV_FRONTEND_DTV_DN5_COEF35_reg                                     (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF35_reg))
#define  DTV_FRONTEND_DTV_DN5_COEF35_dtv_frontend_dn5_coef071_shift              (16)
#define  DTV_FRONTEND_DTV_DN5_COEF35_dtv_frontend_dn5_coef070_shift              (0)
#define  DTV_FRONTEND_DTV_DN5_COEF35_dtv_frontend_dn5_coef071_mask               (0x1FFF0000)
#define  DTV_FRONTEND_DTV_DN5_COEF35_dtv_frontend_dn5_coef070_mask               (0x00001FFF)
#define  DTV_FRONTEND_DTV_DN5_COEF35_dtv_frontend_dn5_coef071(data)              (0x1FFF0000&((data)<<16))
#define  DTV_FRONTEND_DTV_DN5_COEF35_dtv_frontend_dn5_coef070(data)              (0x00001FFF&(data))
#define  DTV_FRONTEND_DTV_DN5_COEF35_get_dtv_frontend_dn5_coef071(data)          ((0x1FFF0000&(data))>>16)
#define  DTV_FRONTEND_DTV_DN5_COEF35_get_dtv_frontend_dn5_coef070(data)          (0x00001FFF&(data))

#define  DTV_FRONTEND_DTV_DN5_COEF36                                             0x18033990
#define  DTV_FRONTEND_DTV_DN5_COEF36_reg_addr                                    "0xB8033990"
#define  DTV_FRONTEND_DTV_DN5_COEF36_reg                                         0xB8033990
#define  DTV_FRONTEND_DTV_DN5_COEF36_inst_addr                                   "0x002C"
#define  set_DTV_FRONTEND_DTV_DN5_COEF36_reg(data)                               (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF36_reg)=data)
#define  get_DTV_FRONTEND_DTV_DN5_COEF36_reg                                     (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF36_reg))
#define  DTV_FRONTEND_DTV_DN5_COEF36_dtv_frontend_dn5_coef073_shift              (16)
#define  DTV_FRONTEND_DTV_DN5_COEF36_dtv_frontend_dn5_coef072_shift              (0)
#define  DTV_FRONTEND_DTV_DN5_COEF36_dtv_frontend_dn5_coef073_mask               (0x1FFF0000)
#define  DTV_FRONTEND_DTV_DN5_COEF36_dtv_frontend_dn5_coef072_mask               (0x00001FFF)
#define  DTV_FRONTEND_DTV_DN5_COEF36_dtv_frontend_dn5_coef073(data)              (0x1FFF0000&((data)<<16))
#define  DTV_FRONTEND_DTV_DN5_COEF36_dtv_frontend_dn5_coef072(data)              (0x00001FFF&(data))
#define  DTV_FRONTEND_DTV_DN5_COEF36_get_dtv_frontend_dn5_coef073(data)          ((0x1FFF0000&(data))>>16)
#define  DTV_FRONTEND_DTV_DN5_COEF36_get_dtv_frontend_dn5_coef072(data)          (0x00001FFF&(data))

#define  DTV_FRONTEND_DTV_DN5_COEF37                                             0x18033994
#define  DTV_FRONTEND_DTV_DN5_COEF37_reg_addr                                    "0xB8033994"
#define  DTV_FRONTEND_DTV_DN5_COEF37_reg                                         0xB8033994
#define  DTV_FRONTEND_DTV_DN5_COEF37_inst_addr                                   "0x002D"
#define  set_DTV_FRONTEND_DTV_DN5_COEF37_reg(data)                               (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF37_reg)=data)
#define  get_DTV_FRONTEND_DTV_DN5_COEF37_reg                                     (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF37_reg))
#define  DTV_FRONTEND_DTV_DN5_COEF37_dtv_frontend_dn5_coef075_shift              (16)
#define  DTV_FRONTEND_DTV_DN5_COEF37_dtv_frontend_dn5_coef074_shift              (0)
#define  DTV_FRONTEND_DTV_DN5_COEF37_dtv_frontend_dn5_coef075_mask               (0x1FFF0000)
#define  DTV_FRONTEND_DTV_DN5_COEF37_dtv_frontend_dn5_coef074_mask               (0x00001FFF)
#define  DTV_FRONTEND_DTV_DN5_COEF37_dtv_frontend_dn5_coef075(data)              (0x1FFF0000&((data)<<16))
#define  DTV_FRONTEND_DTV_DN5_COEF37_dtv_frontend_dn5_coef074(data)              (0x00001FFF&(data))
#define  DTV_FRONTEND_DTV_DN5_COEF37_get_dtv_frontend_dn5_coef075(data)          ((0x1FFF0000&(data))>>16)
#define  DTV_FRONTEND_DTV_DN5_COEF37_get_dtv_frontend_dn5_coef074(data)          (0x00001FFF&(data))

#define  DTV_FRONTEND_DTV_DN5_COEF38                                             0x18033998
#define  DTV_FRONTEND_DTV_DN5_COEF38_reg_addr                                    "0xB8033998"
#define  DTV_FRONTEND_DTV_DN5_COEF38_reg                                         0xB8033998
#define  DTV_FRONTEND_DTV_DN5_COEF38_inst_addr                                   "0x002E"
#define  set_DTV_FRONTEND_DTV_DN5_COEF38_reg(data)                               (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF38_reg)=data)
#define  get_DTV_FRONTEND_DTV_DN5_COEF38_reg                                     (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF38_reg))
#define  DTV_FRONTEND_DTV_DN5_COEF38_dtv_frontend_dn5_coef077_shift              (16)
#define  DTV_FRONTEND_DTV_DN5_COEF38_dtv_frontend_dn5_coef076_shift              (0)
#define  DTV_FRONTEND_DTV_DN5_COEF38_dtv_frontend_dn5_coef077_mask               (0x1FFF0000)
#define  DTV_FRONTEND_DTV_DN5_COEF38_dtv_frontend_dn5_coef076_mask               (0x00001FFF)
#define  DTV_FRONTEND_DTV_DN5_COEF38_dtv_frontend_dn5_coef077(data)              (0x1FFF0000&((data)<<16))
#define  DTV_FRONTEND_DTV_DN5_COEF38_dtv_frontend_dn5_coef076(data)              (0x00001FFF&(data))
#define  DTV_FRONTEND_DTV_DN5_COEF38_get_dtv_frontend_dn5_coef077(data)          ((0x1FFF0000&(data))>>16)
#define  DTV_FRONTEND_DTV_DN5_COEF38_get_dtv_frontend_dn5_coef076(data)          (0x00001FFF&(data))

#define  DTV_FRONTEND_DTV_DN5_COEF39                                             0x1803399C
#define  DTV_FRONTEND_DTV_DN5_COEF39_reg_addr                                    "0xB803399C"
#define  DTV_FRONTEND_DTV_DN5_COEF39_reg                                         0xB803399C
#define  DTV_FRONTEND_DTV_DN5_COEF39_inst_addr                                   "0x002F"
#define  set_DTV_FRONTEND_DTV_DN5_COEF39_reg(data)                               (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF39_reg)=data)
#define  get_DTV_FRONTEND_DTV_DN5_COEF39_reg                                     (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF39_reg))
#define  DTV_FRONTEND_DTV_DN5_COEF39_dtv_frontend_dn5_coef079_shift              (16)
#define  DTV_FRONTEND_DTV_DN5_COEF39_dtv_frontend_dn5_coef078_shift              (0)
#define  DTV_FRONTEND_DTV_DN5_COEF39_dtv_frontend_dn5_coef079_mask               (0x1FFF0000)
#define  DTV_FRONTEND_DTV_DN5_COEF39_dtv_frontend_dn5_coef078_mask               (0x00001FFF)
#define  DTV_FRONTEND_DTV_DN5_COEF39_dtv_frontend_dn5_coef079(data)              (0x1FFF0000&((data)<<16))
#define  DTV_FRONTEND_DTV_DN5_COEF39_dtv_frontend_dn5_coef078(data)              (0x00001FFF&(data))
#define  DTV_FRONTEND_DTV_DN5_COEF39_get_dtv_frontend_dn5_coef079(data)          ((0x1FFF0000&(data))>>16)
#define  DTV_FRONTEND_DTV_DN5_COEF39_get_dtv_frontend_dn5_coef078(data)          (0x00001FFF&(data))

#define  DTV_FRONTEND_DTV_DN5_COEF40                                             0x180339A0
#define  DTV_FRONTEND_DTV_DN5_COEF40_reg_addr                                    "0xB80339A0"
#define  DTV_FRONTEND_DTV_DN5_COEF40_reg                                         0xB80339A0
#define  DTV_FRONTEND_DTV_DN5_COEF40_inst_addr                                   "0x0030"
#define  set_DTV_FRONTEND_DTV_DN5_COEF40_reg(data)                               (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF40_reg)=data)
#define  get_DTV_FRONTEND_DTV_DN5_COEF40_reg                                     (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF40_reg))
#define  DTV_FRONTEND_DTV_DN5_COEF40_dtv_frontend_dn5_coef081_shift              (16)
#define  DTV_FRONTEND_DTV_DN5_COEF40_dtv_frontend_dn5_coef080_shift              (0)
#define  DTV_FRONTEND_DTV_DN5_COEF40_dtv_frontend_dn5_coef081_mask               (0x1FFF0000)
#define  DTV_FRONTEND_DTV_DN5_COEF40_dtv_frontend_dn5_coef080_mask               (0x00001FFF)
#define  DTV_FRONTEND_DTV_DN5_COEF40_dtv_frontend_dn5_coef081(data)              (0x1FFF0000&((data)<<16))
#define  DTV_FRONTEND_DTV_DN5_COEF40_dtv_frontend_dn5_coef080(data)              (0x00001FFF&(data))
#define  DTV_FRONTEND_DTV_DN5_COEF40_get_dtv_frontend_dn5_coef081(data)          ((0x1FFF0000&(data))>>16)
#define  DTV_FRONTEND_DTV_DN5_COEF40_get_dtv_frontend_dn5_coef080(data)          (0x00001FFF&(data))

#define  DTV_FRONTEND_DTV_DN5_COEF41                                             0x180339A4
#define  DTV_FRONTEND_DTV_DN5_COEF41_reg_addr                                    "0xB80339A4"
#define  DTV_FRONTEND_DTV_DN5_COEF41_reg                                         0xB80339A4
#define  DTV_FRONTEND_DTV_DN5_COEF41_inst_addr                                   "0x0031"
#define  set_DTV_FRONTEND_DTV_DN5_COEF41_reg(data)                               (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF41_reg)=data)
#define  get_DTV_FRONTEND_DTV_DN5_COEF41_reg                                     (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF41_reg))
#define  DTV_FRONTEND_DTV_DN5_COEF41_dtv_frontend_dn5_coef083_shift              (16)
#define  DTV_FRONTEND_DTV_DN5_COEF41_dtv_frontend_dn5_coef082_shift              (0)
#define  DTV_FRONTEND_DTV_DN5_COEF41_dtv_frontend_dn5_coef083_mask               (0x1FFF0000)
#define  DTV_FRONTEND_DTV_DN5_COEF41_dtv_frontend_dn5_coef082_mask               (0x00001FFF)
#define  DTV_FRONTEND_DTV_DN5_COEF41_dtv_frontend_dn5_coef083(data)              (0x1FFF0000&((data)<<16))
#define  DTV_FRONTEND_DTV_DN5_COEF41_dtv_frontend_dn5_coef082(data)              (0x00001FFF&(data))
#define  DTV_FRONTEND_DTV_DN5_COEF41_get_dtv_frontend_dn5_coef083(data)          ((0x1FFF0000&(data))>>16)
#define  DTV_FRONTEND_DTV_DN5_COEF41_get_dtv_frontend_dn5_coef082(data)          (0x00001FFF&(data))

#define  DTV_FRONTEND_DTV_DN5_COEF42                                             0x180339A8
#define  DTV_FRONTEND_DTV_DN5_COEF42_reg_addr                                    "0xB80339A8"
#define  DTV_FRONTEND_DTV_DN5_COEF42_reg                                         0xB80339A8
#define  DTV_FRONTEND_DTV_DN5_COEF42_inst_addr                                   "0x0032"
#define  set_DTV_FRONTEND_DTV_DN5_COEF42_reg(data)                               (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF42_reg)=data)
#define  get_DTV_FRONTEND_DTV_DN5_COEF42_reg                                     (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF42_reg))
#define  DTV_FRONTEND_DTV_DN5_COEF42_dtv_frontend_dn5_coef085_shift              (16)
#define  DTV_FRONTEND_DTV_DN5_COEF42_dtv_frontend_dn5_coef084_shift              (0)
#define  DTV_FRONTEND_DTV_DN5_COEF42_dtv_frontend_dn5_coef085_mask               (0x1FFF0000)
#define  DTV_FRONTEND_DTV_DN5_COEF42_dtv_frontend_dn5_coef084_mask               (0x00001FFF)
#define  DTV_FRONTEND_DTV_DN5_COEF42_dtv_frontend_dn5_coef085(data)              (0x1FFF0000&((data)<<16))
#define  DTV_FRONTEND_DTV_DN5_COEF42_dtv_frontend_dn5_coef084(data)              (0x00001FFF&(data))
#define  DTV_FRONTEND_DTV_DN5_COEF42_get_dtv_frontend_dn5_coef085(data)          ((0x1FFF0000&(data))>>16)
#define  DTV_FRONTEND_DTV_DN5_COEF42_get_dtv_frontend_dn5_coef084(data)          (0x00001FFF&(data))

#define  DTV_FRONTEND_DTV_DN5_COEF43                                             0x180339AC
#define  DTV_FRONTEND_DTV_DN5_COEF43_reg_addr                                    "0xB80339AC"
#define  DTV_FRONTEND_DTV_DN5_COEF43_reg                                         0xB80339AC
#define  DTV_FRONTEND_DTV_DN5_COEF43_inst_addr                                   "0x0033"
#define  set_DTV_FRONTEND_DTV_DN5_COEF43_reg(data)                               (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF43_reg)=data)
#define  get_DTV_FRONTEND_DTV_DN5_COEF43_reg                                     (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF43_reg))
#define  DTV_FRONTEND_DTV_DN5_COEF43_dtv_frontend_dn5_coef087_shift              (16)
#define  DTV_FRONTEND_DTV_DN5_COEF43_dtv_frontend_dn5_coef086_shift              (0)
#define  DTV_FRONTEND_DTV_DN5_COEF43_dtv_frontend_dn5_coef087_mask               (0x1FFF0000)
#define  DTV_FRONTEND_DTV_DN5_COEF43_dtv_frontend_dn5_coef086_mask               (0x00001FFF)
#define  DTV_FRONTEND_DTV_DN5_COEF43_dtv_frontend_dn5_coef087(data)              (0x1FFF0000&((data)<<16))
#define  DTV_FRONTEND_DTV_DN5_COEF43_dtv_frontend_dn5_coef086(data)              (0x00001FFF&(data))
#define  DTV_FRONTEND_DTV_DN5_COEF43_get_dtv_frontend_dn5_coef087(data)          ((0x1FFF0000&(data))>>16)
#define  DTV_FRONTEND_DTV_DN5_COEF43_get_dtv_frontend_dn5_coef086(data)          (0x00001FFF&(data))

#define  DTV_FRONTEND_DTV_DN5_COEF44                                             0x180339B0
#define  DTV_FRONTEND_DTV_DN5_COEF44_reg_addr                                    "0xB80339B0"
#define  DTV_FRONTEND_DTV_DN5_COEF44_reg                                         0xB80339B0
#define  DTV_FRONTEND_DTV_DN5_COEF44_inst_addr                                   "0x0034"
#define  set_DTV_FRONTEND_DTV_DN5_COEF44_reg(data)                               (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF44_reg)=data)
#define  get_DTV_FRONTEND_DTV_DN5_COEF44_reg                                     (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF44_reg))
#define  DTV_FRONTEND_DTV_DN5_COEF44_dtv_frontend_dn5_coef089_shift              (16)
#define  DTV_FRONTEND_DTV_DN5_COEF44_dtv_frontend_dn5_coef088_shift              (0)
#define  DTV_FRONTEND_DTV_DN5_COEF44_dtv_frontend_dn5_coef089_mask               (0x1FFF0000)
#define  DTV_FRONTEND_DTV_DN5_COEF44_dtv_frontend_dn5_coef088_mask               (0x00001FFF)
#define  DTV_FRONTEND_DTV_DN5_COEF44_dtv_frontend_dn5_coef089(data)              (0x1FFF0000&((data)<<16))
#define  DTV_FRONTEND_DTV_DN5_COEF44_dtv_frontend_dn5_coef088(data)              (0x00001FFF&(data))
#define  DTV_FRONTEND_DTV_DN5_COEF44_get_dtv_frontend_dn5_coef089(data)          ((0x1FFF0000&(data))>>16)
#define  DTV_FRONTEND_DTV_DN5_COEF44_get_dtv_frontend_dn5_coef088(data)          (0x00001FFF&(data))

#define  DTV_FRONTEND_DTV_DN5_COEF45                                             0x180339B4
#define  DTV_FRONTEND_DTV_DN5_COEF45_reg_addr                                    "0xB80339B4"
#define  DTV_FRONTEND_DTV_DN5_COEF45_reg                                         0xB80339B4
#define  DTV_FRONTEND_DTV_DN5_COEF45_inst_addr                                   "0x0035"
#define  set_DTV_FRONTEND_DTV_DN5_COEF45_reg(data)                               (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF45_reg)=data)
#define  get_DTV_FRONTEND_DTV_DN5_COEF45_reg                                     (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF45_reg))
#define  DTV_FRONTEND_DTV_DN5_COEF45_dtv_frontend_dn5_coef091_shift              (16)
#define  DTV_FRONTEND_DTV_DN5_COEF45_dtv_frontend_dn5_coef090_shift              (0)
#define  DTV_FRONTEND_DTV_DN5_COEF45_dtv_frontend_dn5_coef091_mask               (0x1FFF0000)
#define  DTV_FRONTEND_DTV_DN5_COEF45_dtv_frontend_dn5_coef090_mask               (0x00001FFF)
#define  DTV_FRONTEND_DTV_DN5_COEF45_dtv_frontend_dn5_coef091(data)              (0x1FFF0000&((data)<<16))
#define  DTV_FRONTEND_DTV_DN5_COEF45_dtv_frontend_dn5_coef090(data)              (0x00001FFF&(data))
#define  DTV_FRONTEND_DTV_DN5_COEF45_get_dtv_frontend_dn5_coef091(data)          ((0x1FFF0000&(data))>>16)
#define  DTV_FRONTEND_DTV_DN5_COEF45_get_dtv_frontend_dn5_coef090(data)          (0x00001FFF&(data))

#define  DTV_FRONTEND_DTV_DN5_COEF46                                             0x180339B8
#define  DTV_FRONTEND_DTV_DN5_COEF46_reg_addr                                    "0xB80339B8"
#define  DTV_FRONTEND_DTV_DN5_COEF46_reg                                         0xB80339B8
#define  DTV_FRONTEND_DTV_DN5_COEF46_inst_addr                                   "0x0036"
#define  set_DTV_FRONTEND_DTV_DN5_COEF46_reg(data)                               (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF46_reg)=data)
#define  get_DTV_FRONTEND_DTV_DN5_COEF46_reg                                     (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF46_reg))
#define  DTV_FRONTEND_DTV_DN5_COEF46_dtv_frontend_dn5_coef093_shift              (16)
#define  DTV_FRONTEND_DTV_DN5_COEF46_dtv_frontend_dn5_coef092_shift              (0)
#define  DTV_FRONTEND_DTV_DN5_COEF46_dtv_frontend_dn5_coef093_mask               (0x1FFF0000)
#define  DTV_FRONTEND_DTV_DN5_COEF46_dtv_frontend_dn5_coef092_mask               (0x00001FFF)
#define  DTV_FRONTEND_DTV_DN5_COEF46_dtv_frontend_dn5_coef093(data)              (0x1FFF0000&((data)<<16))
#define  DTV_FRONTEND_DTV_DN5_COEF46_dtv_frontend_dn5_coef092(data)              (0x00001FFF&(data))
#define  DTV_FRONTEND_DTV_DN5_COEF46_get_dtv_frontend_dn5_coef093(data)          ((0x1FFF0000&(data))>>16)
#define  DTV_FRONTEND_DTV_DN5_COEF46_get_dtv_frontend_dn5_coef092(data)          (0x00001FFF&(data))

#define  DTV_FRONTEND_DTV_DN5_COEF47                                             0x180339BC
#define  DTV_FRONTEND_DTV_DN5_COEF47_reg_addr                                    "0xB80339BC"
#define  DTV_FRONTEND_DTV_DN5_COEF47_reg                                         0xB80339BC
#define  DTV_FRONTEND_DTV_DN5_COEF47_inst_addr                                   "0x0037"
#define  set_DTV_FRONTEND_DTV_DN5_COEF47_reg(data)                               (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF47_reg)=data)
#define  get_DTV_FRONTEND_DTV_DN5_COEF47_reg                                     (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF47_reg))
#define  DTV_FRONTEND_DTV_DN5_COEF47_dtv_frontend_dn5_coef095_shift              (16)
#define  DTV_FRONTEND_DTV_DN5_COEF47_dtv_frontend_dn5_coef094_shift              (0)
#define  DTV_FRONTEND_DTV_DN5_COEF47_dtv_frontend_dn5_coef095_mask               (0x1FFF0000)
#define  DTV_FRONTEND_DTV_DN5_COEF47_dtv_frontend_dn5_coef094_mask               (0x00001FFF)
#define  DTV_FRONTEND_DTV_DN5_COEF47_dtv_frontend_dn5_coef095(data)              (0x1FFF0000&((data)<<16))
#define  DTV_FRONTEND_DTV_DN5_COEF47_dtv_frontend_dn5_coef094(data)              (0x00001FFF&(data))
#define  DTV_FRONTEND_DTV_DN5_COEF47_get_dtv_frontend_dn5_coef095(data)          ((0x1FFF0000&(data))>>16)
#define  DTV_FRONTEND_DTV_DN5_COEF47_get_dtv_frontend_dn5_coef094(data)          (0x00001FFF&(data))

#define  DTV_FRONTEND_DTV_DN5_COEF48                                             0x180339C0
#define  DTV_FRONTEND_DTV_DN5_COEF48_reg_addr                                    "0xB80339C0"
#define  DTV_FRONTEND_DTV_DN5_COEF48_reg                                         0xB80339C0
#define  DTV_FRONTEND_DTV_DN5_COEF48_inst_addr                                   "0x0038"
#define  set_DTV_FRONTEND_DTV_DN5_COEF48_reg(data)                               (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF48_reg)=data)
#define  get_DTV_FRONTEND_DTV_DN5_COEF48_reg                                     (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF48_reg))
#define  DTV_FRONTEND_DTV_DN5_COEF48_dtv_frontend_dn5_coef097_shift              (16)
#define  DTV_FRONTEND_DTV_DN5_COEF48_dtv_frontend_dn5_coef096_shift              (0)
#define  DTV_FRONTEND_DTV_DN5_COEF48_dtv_frontend_dn5_coef097_mask               (0x1FFF0000)
#define  DTV_FRONTEND_DTV_DN5_COEF48_dtv_frontend_dn5_coef096_mask               (0x00001FFF)
#define  DTV_FRONTEND_DTV_DN5_COEF48_dtv_frontend_dn5_coef097(data)              (0x1FFF0000&((data)<<16))
#define  DTV_FRONTEND_DTV_DN5_COEF48_dtv_frontend_dn5_coef096(data)              (0x00001FFF&(data))
#define  DTV_FRONTEND_DTV_DN5_COEF48_get_dtv_frontend_dn5_coef097(data)          ((0x1FFF0000&(data))>>16)
#define  DTV_FRONTEND_DTV_DN5_COEF48_get_dtv_frontend_dn5_coef096(data)          (0x00001FFF&(data))

#define  DTV_FRONTEND_DTV_DN5_COEF49                                             0x180339C4
#define  DTV_FRONTEND_DTV_DN5_COEF49_reg_addr                                    "0xB80339C4"
#define  DTV_FRONTEND_DTV_DN5_COEF49_reg                                         0xB80339C4
#define  DTV_FRONTEND_DTV_DN5_COEF49_inst_addr                                   "0x0039"
#define  set_DTV_FRONTEND_DTV_DN5_COEF49_reg(data)                               (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF49_reg)=data)
#define  get_DTV_FRONTEND_DTV_DN5_COEF49_reg                                     (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF49_reg))
#define  DTV_FRONTEND_DTV_DN5_COEF49_dtv_frontend_dn5_coef099_shift              (16)
#define  DTV_FRONTEND_DTV_DN5_COEF49_dtv_frontend_dn5_coef098_shift              (0)
#define  DTV_FRONTEND_DTV_DN5_COEF49_dtv_frontend_dn5_coef099_mask               (0x1FFF0000)
#define  DTV_FRONTEND_DTV_DN5_COEF49_dtv_frontend_dn5_coef098_mask               (0x00001FFF)
#define  DTV_FRONTEND_DTV_DN5_COEF49_dtv_frontend_dn5_coef099(data)              (0x1FFF0000&((data)<<16))
#define  DTV_FRONTEND_DTV_DN5_COEF49_dtv_frontend_dn5_coef098(data)              (0x00001FFF&(data))
#define  DTV_FRONTEND_DTV_DN5_COEF49_get_dtv_frontend_dn5_coef099(data)          ((0x1FFF0000&(data))>>16)
#define  DTV_FRONTEND_DTV_DN5_COEF49_get_dtv_frontend_dn5_coef098(data)          (0x00001FFF&(data))

#define  DTV_FRONTEND_DTV_DN5_COEF50                                             0x180339C8
#define  DTV_FRONTEND_DTV_DN5_COEF50_reg_addr                                    "0xB80339C8"
#define  DTV_FRONTEND_DTV_DN5_COEF50_reg                                         0xB80339C8
#define  DTV_FRONTEND_DTV_DN5_COEF50_inst_addr                                   "0x003A"
#define  set_DTV_FRONTEND_DTV_DN5_COEF50_reg(data)                               (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF50_reg)=data)
#define  get_DTV_FRONTEND_DTV_DN5_COEF50_reg                                     (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF50_reg))
#define  DTV_FRONTEND_DTV_DN5_COEF50_dtv_frontend_dn5_coef101_shift              (16)
#define  DTV_FRONTEND_DTV_DN5_COEF50_dtv_frontend_dn5_coef100_shift              (0)
#define  DTV_FRONTEND_DTV_DN5_COEF50_dtv_frontend_dn5_coef101_mask               (0x1FFF0000)
#define  DTV_FRONTEND_DTV_DN5_COEF50_dtv_frontend_dn5_coef100_mask               (0x00001FFF)
#define  DTV_FRONTEND_DTV_DN5_COEF50_dtv_frontend_dn5_coef101(data)              (0x1FFF0000&((data)<<16))
#define  DTV_FRONTEND_DTV_DN5_COEF50_dtv_frontend_dn5_coef100(data)              (0x00001FFF&(data))
#define  DTV_FRONTEND_DTV_DN5_COEF50_get_dtv_frontend_dn5_coef101(data)          ((0x1FFF0000&(data))>>16)
#define  DTV_FRONTEND_DTV_DN5_COEF50_get_dtv_frontend_dn5_coef100(data)          (0x00001FFF&(data))

#define  DTV_FRONTEND_DTV_DN5_COEF51                                             0x180339CC
#define  DTV_FRONTEND_DTV_DN5_COEF51_reg_addr                                    "0xB80339CC"
#define  DTV_FRONTEND_DTV_DN5_COEF51_reg                                         0xB80339CC
#define  DTV_FRONTEND_DTV_DN5_COEF51_inst_addr                                   "0x003B"
#define  set_DTV_FRONTEND_DTV_DN5_COEF51_reg(data)                               (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF51_reg)=data)
#define  get_DTV_FRONTEND_DTV_DN5_COEF51_reg                                     (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF51_reg))
#define  DTV_FRONTEND_DTV_DN5_COEF51_dtv_frontend_dn5_coef103_shift              (16)
#define  DTV_FRONTEND_DTV_DN5_COEF51_dtv_frontend_dn5_coef102_shift              (0)
#define  DTV_FRONTEND_DTV_DN5_COEF51_dtv_frontend_dn5_coef103_mask               (0x1FFF0000)
#define  DTV_FRONTEND_DTV_DN5_COEF51_dtv_frontend_dn5_coef102_mask               (0x00001FFF)
#define  DTV_FRONTEND_DTV_DN5_COEF51_dtv_frontend_dn5_coef103(data)              (0x1FFF0000&((data)<<16))
#define  DTV_FRONTEND_DTV_DN5_COEF51_dtv_frontend_dn5_coef102(data)              (0x00001FFF&(data))
#define  DTV_FRONTEND_DTV_DN5_COEF51_get_dtv_frontend_dn5_coef103(data)          ((0x1FFF0000&(data))>>16)
#define  DTV_FRONTEND_DTV_DN5_COEF51_get_dtv_frontend_dn5_coef102(data)          (0x00001FFF&(data))

#define  DTV_FRONTEND_DTV_DN5_COEF52                                             0x180339D0
#define  DTV_FRONTEND_DTV_DN5_COEF52_reg_addr                                    "0xB80339D0"
#define  DTV_FRONTEND_DTV_DN5_COEF52_reg                                         0xB80339D0
#define  DTV_FRONTEND_DTV_DN5_COEF52_inst_addr                                   "0x003C"
#define  set_DTV_FRONTEND_DTV_DN5_COEF52_reg(data)                               (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF52_reg)=data)
#define  get_DTV_FRONTEND_DTV_DN5_COEF52_reg                                     (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF52_reg))
#define  DTV_FRONTEND_DTV_DN5_COEF52_dtv_frontend_dn5_coef105_shift              (16)
#define  DTV_FRONTEND_DTV_DN5_COEF52_dtv_frontend_dn5_coef104_shift              (0)
#define  DTV_FRONTEND_DTV_DN5_COEF52_dtv_frontend_dn5_coef105_mask               (0x1FFF0000)
#define  DTV_FRONTEND_DTV_DN5_COEF52_dtv_frontend_dn5_coef104_mask               (0x00001FFF)
#define  DTV_FRONTEND_DTV_DN5_COEF52_dtv_frontend_dn5_coef105(data)              (0x1FFF0000&((data)<<16))
#define  DTV_FRONTEND_DTV_DN5_COEF52_dtv_frontend_dn5_coef104(data)              (0x00001FFF&(data))
#define  DTV_FRONTEND_DTV_DN5_COEF52_get_dtv_frontend_dn5_coef105(data)          ((0x1FFF0000&(data))>>16)
#define  DTV_FRONTEND_DTV_DN5_COEF52_get_dtv_frontend_dn5_coef104(data)          (0x00001FFF&(data))

#define  DTV_FRONTEND_DTV_DN5_COEF53                                             0x180339D4
#define  DTV_FRONTEND_DTV_DN5_COEF53_reg_addr                                    "0xB80339D4"
#define  DTV_FRONTEND_DTV_DN5_COEF53_reg                                         0xB80339D4
#define  DTV_FRONTEND_DTV_DN5_COEF53_inst_addr                                   "0x003D"
#define  set_DTV_FRONTEND_DTV_DN5_COEF53_reg(data)                               (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF53_reg)=data)
#define  get_DTV_FRONTEND_DTV_DN5_COEF53_reg                                     (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF53_reg))
#define  DTV_FRONTEND_DTV_DN5_COEF53_dtv_frontend_dn5_coef107_shift              (16)
#define  DTV_FRONTEND_DTV_DN5_COEF53_dtv_frontend_dn5_coef106_shift              (0)
#define  DTV_FRONTEND_DTV_DN5_COEF53_dtv_frontend_dn5_coef107_mask               (0x1FFF0000)
#define  DTV_FRONTEND_DTV_DN5_COEF53_dtv_frontend_dn5_coef106_mask               (0x00001FFF)
#define  DTV_FRONTEND_DTV_DN5_COEF53_dtv_frontend_dn5_coef107(data)              (0x1FFF0000&((data)<<16))
#define  DTV_FRONTEND_DTV_DN5_COEF53_dtv_frontend_dn5_coef106(data)              (0x00001FFF&(data))
#define  DTV_FRONTEND_DTV_DN5_COEF53_get_dtv_frontend_dn5_coef107(data)          ((0x1FFF0000&(data))>>16)
#define  DTV_FRONTEND_DTV_DN5_COEF53_get_dtv_frontend_dn5_coef106(data)          (0x00001FFF&(data))

#define  DTV_FRONTEND_DTV_DN5_COEF54                                             0x180339D8
#define  DTV_FRONTEND_DTV_DN5_COEF54_reg_addr                                    "0xB80339D8"
#define  DTV_FRONTEND_DTV_DN5_COEF54_reg                                         0xB80339D8
#define  DTV_FRONTEND_DTV_DN5_COEF54_inst_addr                                   "0x003E"
#define  set_DTV_FRONTEND_DTV_DN5_COEF54_reg(data)                               (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF54_reg)=data)
#define  get_DTV_FRONTEND_DTV_DN5_COEF54_reg                                     (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF54_reg))
#define  DTV_FRONTEND_DTV_DN5_COEF54_dtv_frontend_dn5_coef109_shift              (16)
#define  DTV_FRONTEND_DTV_DN5_COEF54_dtv_frontend_dn5_coef108_shift              (0)
#define  DTV_FRONTEND_DTV_DN5_COEF54_dtv_frontend_dn5_coef109_mask               (0x1FFF0000)
#define  DTV_FRONTEND_DTV_DN5_COEF54_dtv_frontend_dn5_coef108_mask               (0x00001FFF)
#define  DTV_FRONTEND_DTV_DN5_COEF54_dtv_frontend_dn5_coef109(data)              (0x1FFF0000&((data)<<16))
#define  DTV_FRONTEND_DTV_DN5_COEF54_dtv_frontend_dn5_coef108(data)              (0x00001FFF&(data))
#define  DTV_FRONTEND_DTV_DN5_COEF54_get_dtv_frontend_dn5_coef109(data)          ((0x1FFF0000&(data))>>16)
#define  DTV_FRONTEND_DTV_DN5_COEF54_get_dtv_frontend_dn5_coef108(data)          (0x00001FFF&(data))

#define  DTV_FRONTEND_DTV_DN5_COEF55                                             0x180339DC
#define  DTV_FRONTEND_DTV_DN5_COEF55_reg_addr                                    "0xB80339DC"
#define  DTV_FRONTEND_DTV_DN5_COEF55_reg                                         0xB80339DC
#define  DTV_FRONTEND_DTV_DN5_COEF55_inst_addr                                   "0x003F"
#define  set_DTV_FRONTEND_DTV_DN5_COEF55_reg(data)                               (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF55_reg)=data)
#define  get_DTV_FRONTEND_DTV_DN5_COEF55_reg                                     (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF55_reg))
#define  DTV_FRONTEND_DTV_DN5_COEF55_dtv_frontend_dn5_coef111_shift              (16)
#define  DTV_FRONTEND_DTV_DN5_COEF55_dtv_frontend_dn5_coef110_shift              (0)
#define  DTV_FRONTEND_DTV_DN5_COEF55_dtv_frontend_dn5_coef111_mask               (0x1FFF0000)
#define  DTV_FRONTEND_DTV_DN5_COEF55_dtv_frontend_dn5_coef110_mask               (0x00001FFF)
#define  DTV_FRONTEND_DTV_DN5_COEF55_dtv_frontend_dn5_coef111(data)              (0x1FFF0000&((data)<<16))
#define  DTV_FRONTEND_DTV_DN5_COEF55_dtv_frontend_dn5_coef110(data)              (0x00001FFF&(data))
#define  DTV_FRONTEND_DTV_DN5_COEF55_get_dtv_frontend_dn5_coef111(data)          ((0x1FFF0000&(data))>>16)
#define  DTV_FRONTEND_DTV_DN5_COEF55_get_dtv_frontend_dn5_coef110(data)          (0x00001FFF&(data))

#define  DTV_FRONTEND_DTV_DN5_COEF56                                             0x180339E0
#define  DTV_FRONTEND_DTV_DN5_COEF56_reg_addr                                    "0xB80339E0"
#define  DTV_FRONTEND_DTV_DN5_COEF56_reg                                         0xB80339E0
#define  DTV_FRONTEND_DTV_DN5_COEF56_inst_addr                                   "0x0040"
#define  set_DTV_FRONTEND_DTV_DN5_COEF56_reg(data)                               (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF56_reg)=data)
#define  get_DTV_FRONTEND_DTV_DN5_COEF56_reg                                     (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF56_reg))
#define  DTV_FRONTEND_DTV_DN5_COEF56_dtv_frontend_dn5_coef113_shift              (16)
#define  DTV_FRONTEND_DTV_DN5_COEF56_dtv_frontend_dn5_coef112_shift              (0)
#define  DTV_FRONTEND_DTV_DN5_COEF56_dtv_frontend_dn5_coef113_mask               (0x1FFF0000)
#define  DTV_FRONTEND_DTV_DN5_COEF56_dtv_frontend_dn5_coef112_mask               (0x00001FFF)
#define  DTV_FRONTEND_DTV_DN5_COEF56_dtv_frontend_dn5_coef113(data)              (0x1FFF0000&((data)<<16))
#define  DTV_FRONTEND_DTV_DN5_COEF56_dtv_frontend_dn5_coef112(data)              (0x00001FFF&(data))
#define  DTV_FRONTEND_DTV_DN5_COEF56_get_dtv_frontend_dn5_coef113(data)          ((0x1FFF0000&(data))>>16)
#define  DTV_FRONTEND_DTV_DN5_COEF56_get_dtv_frontend_dn5_coef112(data)          (0x00001FFF&(data))

#define  DTV_FRONTEND_DTV_DN5_COEF57                                             0x180339E4
#define  DTV_FRONTEND_DTV_DN5_COEF57_reg_addr                                    "0xB80339E4"
#define  DTV_FRONTEND_DTV_DN5_COEF57_reg                                         0xB80339E4
#define  DTV_FRONTEND_DTV_DN5_COEF57_inst_addr                                   "0x0041"
#define  set_DTV_FRONTEND_DTV_DN5_COEF57_reg(data)                               (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF57_reg)=data)
#define  get_DTV_FRONTEND_DTV_DN5_COEF57_reg                                     (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF57_reg))
#define  DTV_FRONTEND_DTV_DN5_COEF57_dtv_frontend_dn5_coef115_shift              (16)
#define  DTV_FRONTEND_DTV_DN5_COEF57_dtv_frontend_dn5_coef114_shift              (0)
#define  DTV_FRONTEND_DTV_DN5_COEF57_dtv_frontend_dn5_coef115_mask               (0x1FFF0000)
#define  DTV_FRONTEND_DTV_DN5_COEF57_dtv_frontend_dn5_coef114_mask               (0x00001FFF)
#define  DTV_FRONTEND_DTV_DN5_COEF57_dtv_frontend_dn5_coef115(data)              (0x1FFF0000&((data)<<16))
#define  DTV_FRONTEND_DTV_DN5_COEF57_dtv_frontend_dn5_coef114(data)              (0x00001FFF&(data))
#define  DTV_FRONTEND_DTV_DN5_COEF57_get_dtv_frontend_dn5_coef115(data)          ((0x1FFF0000&(data))>>16)
#define  DTV_FRONTEND_DTV_DN5_COEF57_get_dtv_frontend_dn5_coef114(data)          (0x00001FFF&(data))

#define  DTV_FRONTEND_DTV_DN5_COEF58                                             0x180339E8
#define  DTV_FRONTEND_DTV_DN5_COEF58_reg_addr                                    "0xB80339E8"
#define  DTV_FRONTEND_DTV_DN5_COEF58_reg                                         0xB80339E8
#define  DTV_FRONTEND_DTV_DN5_COEF58_inst_addr                                   "0x0042"
#define  set_DTV_FRONTEND_DTV_DN5_COEF58_reg(data)                               (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF58_reg)=data)
#define  get_DTV_FRONTEND_DTV_DN5_COEF58_reg                                     (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF58_reg))
#define  DTV_FRONTEND_DTV_DN5_COEF58_dtv_frontend_dn5_coef117_shift              (16)
#define  DTV_FRONTEND_DTV_DN5_COEF58_dtv_frontend_dn5_coef116_shift              (0)
#define  DTV_FRONTEND_DTV_DN5_COEF58_dtv_frontend_dn5_coef117_mask               (0x1FFF0000)
#define  DTV_FRONTEND_DTV_DN5_COEF58_dtv_frontend_dn5_coef116_mask               (0x00001FFF)
#define  DTV_FRONTEND_DTV_DN5_COEF58_dtv_frontend_dn5_coef117(data)              (0x1FFF0000&((data)<<16))
#define  DTV_FRONTEND_DTV_DN5_COEF58_dtv_frontend_dn5_coef116(data)              (0x00001FFF&(data))
#define  DTV_FRONTEND_DTV_DN5_COEF58_get_dtv_frontend_dn5_coef117(data)          ((0x1FFF0000&(data))>>16)
#define  DTV_FRONTEND_DTV_DN5_COEF58_get_dtv_frontend_dn5_coef116(data)          (0x00001FFF&(data))

#define  DTV_FRONTEND_DTV_DN5_COEF59                                             0x180339EC
#define  DTV_FRONTEND_DTV_DN5_COEF59_reg_addr                                    "0xB80339EC"
#define  DTV_FRONTEND_DTV_DN5_COEF59_reg                                         0xB80339EC
#define  DTV_FRONTEND_DTV_DN5_COEF59_inst_addr                                   "0x0043"
#define  set_DTV_FRONTEND_DTV_DN5_COEF59_reg(data)                               (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF59_reg)=data)
#define  get_DTV_FRONTEND_DTV_DN5_COEF59_reg                                     (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF59_reg))
#define  DTV_FRONTEND_DTV_DN5_COEF59_dtv_frontend_dn5_coef119_shift              (16)
#define  DTV_FRONTEND_DTV_DN5_COEF59_dtv_frontend_dn5_coef118_shift              (0)
#define  DTV_FRONTEND_DTV_DN5_COEF59_dtv_frontend_dn5_coef119_mask               (0x1FFF0000)
#define  DTV_FRONTEND_DTV_DN5_COEF59_dtv_frontend_dn5_coef118_mask               (0x00001FFF)
#define  DTV_FRONTEND_DTV_DN5_COEF59_dtv_frontend_dn5_coef119(data)              (0x1FFF0000&((data)<<16))
#define  DTV_FRONTEND_DTV_DN5_COEF59_dtv_frontend_dn5_coef118(data)              (0x00001FFF&(data))
#define  DTV_FRONTEND_DTV_DN5_COEF59_get_dtv_frontend_dn5_coef119(data)          ((0x1FFF0000&(data))>>16)
#define  DTV_FRONTEND_DTV_DN5_COEF59_get_dtv_frontend_dn5_coef118(data)          (0x00001FFF&(data))

#define  DTV_FRONTEND_DTV_DN5_COEF60                                             0x180339F0
#define  DTV_FRONTEND_DTV_DN5_COEF60_reg_addr                                    "0xB80339F0"
#define  DTV_FRONTEND_DTV_DN5_COEF60_reg                                         0xB80339F0
#define  DTV_FRONTEND_DTV_DN5_COEF60_inst_addr                                   "0x0044"
#define  set_DTV_FRONTEND_DTV_DN5_COEF60_reg(data)                               (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF60_reg)=data)
#define  get_DTV_FRONTEND_DTV_DN5_COEF60_reg                                     (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF60_reg))
#define  DTV_FRONTEND_DTV_DN5_COEF60_dtv_frontend_dn5_coef121_shift              (16)
#define  DTV_FRONTEND_DTV_DN5_COEF60_dtv_frontend_dn5_coef120_shift              (0)
#define  DTV_FRONTEND_DTV_DN5_COEF60_dtv_frontend_dn5_coef121_mask               (0x1FFF0000)
#define  DTV_FRONTEND_DTV_DN5_COEF60_dtv_frontend_dn5_coef120_mask               (0x00001FFF)
#define  DTV_FRONTEND_DTV_DN5_COEF60_dtv_frontend_dn5_coef121(data)              (0x1FFF0000&((data)<<16))
#define  DTV_FRONTEND_DTV_DN5_COEF60_dtv_frontend_dn5_coef120(data)              (0x00001FFF&(data))
#define  DTV_FRONTEND_DTV_DN5_COEF60_get_dtv_frontend_dn5_coef121(data)          ((0x1FFF0000&(data))>>16)
#define  DTV_FRONTEND_DTV_DN5_COEF60_get_dtv_frontend_dn5_coef120(data)          (0x00001FFF&(data))

#define  DTV_FRONTEND_DTV_DN5_COEF61                                             0x180339F4
#define  DTV_FRONTEND_DTV_DN5_COEF61_reg_addr                                    "0xB80339F4"
#define  DTV_FRONTEND_DTV_DN5_COEF61_reg                                         0xB80339F4
#define  DTV_FRONTEND_DTV_DN5_COEF61_inst_addr                                   "0x0045"
#define  set_DTV_FRONTEND_DTV_DN5_COEF61_reg(data)                               (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF61_reg)=data)
#define  get_DTV_FRONTEND_DTV_DN5_COEF61_reg                                     (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF61_reg))
#define  DTV_FRONTEND_DTV_DN5_COEF61_dtv_frontend_dn5_coef123_shift              (16)
#define  DTV_FRONTEND_DTV_DN5_COEF61_dtv_frontend_dn5_coef122_shift              (0)
#define  DTV_FRONTEND_DTV_DN5_COEF61_dtv_frontend_dn5_coef123_mask               (0x1FFF0000)
#define  DTV_FRONTEND_DTV_DN5_COEF61_dtv_frontend_dn5_coef122_mask               (0x00001FFF)
#define  DTV_FRONTEND_DTV_DN5_COEF61_dtv_frontend_dn5_coef123(data)              (0x1FFF0000&((data)<<16))
#define  DTV_FRONTEND_DTV_DN5_COEF61_dtv_frontend_dn5_coef122(data)              (0x00001FFF&(data))
#define  DTV_FRONTEND_DTV_DN5_COEF61_get_dtv_frontend_dn5_coef123(data)          ((0x1FFF0000&(data))>>16)
#define  DTV_FRONTEND_DTV_DN5_COEF61_get_dtv_frontend_dn5_coef122(data)          (0x00001FFF&(data))

#define  DTV_FRONTEND_DTV_DN5_COEF62                                             0x180339F8
#define  DTV_FRONTEND_DTV_DN5_COEF62_reg_addr                                    "0xB80339F8"
#define  DTV_FRONTEND_DTV_DN5_COEF62_reg                                         0xB80339F8
#define  DTV_FRONTEND_DTV_DN5_COEF62_inst_addr                                   "0x0046"
#define  set_DTV_FRONTEND_DTV_DN5_COEF62_reg(data)                               (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF62_reg)=data)
#define  get_DTV_FRONTEND_DTV_DN5_COEF62_reg                                     (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF62_reg))
#define  DTV_FRONTEND_DTV_DN5_COEF62_dtv_frontend_dn5_coef125_shift              (16)
#define  DTV_FRONTEND_DTV_DN5_COEF62_dtv_frontend_dn5_coef124_shift              (0)
#define  DTV_FRONTEND_DTV_DN5_COEF62_dtv_frontend_dn5_coef125_mask               (0x1FFF0000)
#define  DTV_FRONTEND_DTV_DN5_COEF62_dtv_frontend_dn5_coef124_mask               (0x00001FFF)
#define  DTV_FRONTEND_DTV_DN5_COEF62_dtv_frontend_dn5_coef125(data)              (0x1FFF0000&((data)<<16))
#define  DTV_FRONTEND_DTV_DN5_COEF62_dtv_frontend_dn5_coef124(data)              (0x00001FFF&(data))
#define  DTV_FRONTEND_DTV_DN5_COEF62_get_dtv_frontend_dn5_coef125(data)          ((0x1FFF0000&(data))>>16)
#define  DTV_FRONTEND_DTV_DN5_COEF62_get_dtv_frontend_dn5_coef124(data)          (0x00001FFF&(data))

#define  DTV_FRONTEND_DTV_DN5_COEF63                                             0x180339FC
#define  DTV_FRONTEND_DTV_DN5_COEF63_reg_addr                                    "0xB80339FC"
#define  DTV_FRONTEND_DTV_DN5_COEF63_reg                                         0xB80339FC
#define  DTV_FRONTEND_DTV_DN5_COEF63_inst_addr                                   "0x0047"
#define  set_DTV_FRONTEND_DTV_DN5_COEF63_reg(data)                               (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF63_reg)=data)
#define  get_DTV_FRONTEND_DTV_DN5_COEF63_reg                                     (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF63_reg))
#define  DTV_FRONTEND_DTV_DN5_COEF63_dtv_frontend_dn5_coef127_shift              (16)
#define  DTV_FRONTEND_DTV_DN5_COEF63_dtv_frontend_dn5_coef126_shift              (0)
#define  DTV_FRONTEND_DTV_DN5_COEF63_dtv_frontend_dn5_coef127_mask               (0x1FFF0000)
#define  DTV_FRONTEND_DTV_DN5_COEF63_dtv_frontend_dn5_coef126_mask               (0x00001FFF)
#define  DTV_FRONTEND_DTV_DN5_COEF63_dtv_frontend_dn5_coef127(data)              (0x1FFF0000&((data)<<16))
#define  DTV_FRONTEND_DTV_DN5_COEF63_dtv_frontend_dn5_coef126(data)              (0x00001FFF&(data))
#define  DTV_FRONTEND_DTV_DN5_COEF63_get_dtv_frontend_dn5_coef127(data)          ((0x1FFF0000&(data))>>16)
#define  DTV_FRONTEND_DTV_DN5_COEF63_get_dtv_frontend_dn5_coef126(data)          (0x00001FFF&(data))

#define  DTV_FRONTEND_DTV_DN5_COEF64                                             0x18033A00
#define  DTV_FRONTEND_DTV_DN5_COEF64_reg_addr                                    "0xB8033A00"
#define  DTV_FRONTEND_DTV_DN5_COEF64_reg                                         0xB8033A00
#define  DTV_FRONTEND_DTV_DN5_COEF64_inst_addr                                   "0x0048"
#define  set_DTV_FRONTEND_DTV_DN5_COEF64_reg(data)                               (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF64_reg)=data)
#define  get_DTV_FRONTEND_DTV_DN5_COEF64_reg                                     (*((volatile unsigned int*)DTV_FRONTEND_DTV_DN5_COEF64_reg))
#define  DTV_FRONTEND_DTV_DN5_COEF64_dtv_frontend_dn5_coef129_shift              (16)
#define  DTV_FRONTEND_DTV_DN5_COEF64_dtv_frontend_dn5_coef128_shift              (0)
#define  DTV_FRONTEND_DTV_DN5_COEF64_dtv_frontend_dn5_coef129_mask               (0x1FFF0000)
#define  DTV_FRONTEND_DTV_DN5_COEF64_dtv_frontend_dn5_coef128_mask               (0x00001FFF)
#define  DTV_FRONTEND_DTV_DN5_COEF64_dtv_frontend_dn5_coef129(data)              (0x1FFF0000&((data)<<16))
#define  DTV_FRONTEND_DTV_DN5_COEF64_dtv_frontend_dn5_coef128(data)              (0x00001FFF&(data))
#define  DTV_FRONTEND_DTV_DN5_COEF64_get_dtv_frontend_dn5_coef129(data)          ((0x1FFF0000&(data))>>16)
#define  DTV_FRONTEND_DTV_DN5_COEF64_get_dtv_frontend_dn5_coef128(data)          (0x00001FFF&(data))

#define  DTV_FRONTEND_DTV_FRONTEND_DEBUG_MODE                                    0x18033A10
#define  DTV_FRONTEND_DTV_FRONTEND_DEBUG_MODE_reg_addr                           "0xB8033A10"
#define  DTV_FRONTEND_DTV_FRONTEND_DEBUG_MODE_reg                                0xB8033A10
#define  DTV_FRONTEND_DTV_FRONTEND_DEBUG_MODE_inst_addr                          "0x0049"
#define  set_DTV_FRONTEND_DTV_FRONTEND_DEBUG_MODE_reg(data)                      (*((volatile unsigned int*)DTV_FRONTEND_DTV_FRONTEND_DEBUG_MODE_reg)=data)
#define  get_DTV_FRONTEND_DTV_FRONTEND_DEBUG_MODE_reg                            (*((volatile unsigned int*)DTV_FRONTEND_DTV_FRONTEND_DEBUG_MODE_reg))
#define  DTV_FRONTEND_DTV_FRONTEND_DEBUG_MODE_dtv_frontend_debug_sel_shift       (0)
#define  DTV_FRONTEND_DTV_FRONTEND_DEBUG_MODE_dtv_frontend_debug_sel_mask        (0x0000000F)
#define  DTV_FRONTEND_DTV_FRONTEND_DEBUG_MODE_dtv_frontend_debug_sel(data)       (0x0000000F&(data))
#define  DTV_FRONTEND_DTV_FRONTEND_DEBUG_MODE_get_dtv_frontend_debug_sel(data)   (0x0000000F&(data))

#define  DTV_FRONTEND_DTV_FRONTEND_CRC_CTRL                                      0x18033A14
#define  DTV_FRONTEND_DTV_FRONTEND_CRC_CTRL_reg_addr                             "0xB8033A14"
#define  DTV_FRONTEND_DTV_FRONTEND_CRC_CTRL_reg                                  0xB8033A14
#define  DTV_FRONTEND_DTV_FRONTEND_CRC_CTRL_inst_addr                            "0x004A"
#define  set_DTV_FRONTEND_DTV_FRONTEND_CRC_CTRL_reg(data)                        (*((volatile unsigned int*)DTV_FRONTEND_DTV_FRONTEND_CRC_CTRL_reg)=data)
#define  get_DTV_FRONTEND_DTV_FRONTEND_CRC_CTRL_reg                              (*((volatile unsigned int*)DTV_FRONTEND_DTV_FRONTEND_CRC_CTRL_reg))
#define  DTV_FRONTEND_DTV_FRONTEND_CRC_CTRL_dtv_demod_frontend_crc_add_shift     (4)
#define  DTV_FRONTEND_DTV_FRONTEND_CRC_CTRL_dtv_demod_frontend_crc_en_shift      (0)
#define  DTV_FRONTEND_DTV_FRONTEND_CRC_CTRL_dtv_demod_frontend_crc_add_mask      (0x000007F0)
#define  DTV_FRONTEND_DTV_FRONTEND_CRC_CTRL_dtv_demod_frontend_crc_en_mask       (0x00000001)
#define  DTV_FRONTEND_DTV_FRONTEND_CRC_CTRL_dtv_demod_frontend_crc_add(data)     (0x000007F0&((data)<<4))
#define  DTV_FRONTEND_DTV_FRONTEND_CRC_CTRL_dtv_demod_frontend_crc_en(data)      (0x00000001&(data))
#define  DTV_FRONTEND_DTV_FRONTEND_CRC_CTRL_get_dtv_demod_frontend_crc_add(data) ((0x000007F0&(data))>>4)
#define  DTV_FRONTEND_DTV_FRONTEND_CRC_CTRL_get_dtv_demod_frontend_crc_en(data)  (0x00000001&(data))

#define  DTV_FRONTEND_DTV_FRONTEND_CRC_RESULT                                    0x18033A18
#define  DTV_FRONTEND_DTV_FRONTEND_CRC_RESULT_reg_addr                           "0xB8033A18"
#define  DTV_FRONTEND_DTV_FRONTEND_CRC_RESULT_reg                                0xB8033A18
#define  DTV_FRONTEND_DTV_FRONTEND_CRC_RESULT_inst_addr                          "0x004B"
#define  set_DTV_FRONTEND_DTV_FRONTEND_CRC_RESULT_reg(data)                      (*((volatile unsigned int*)DTV_FRONTEND_DTV_FRONTEND_CRC_RESULT_reg)=data)
#define  get_DTV_FRONTEND_DTV_FRONTEND_CRC_RESULT_reg                            (*((volatile unsigned int*)DTV_FRONTEND_DTV_FRONTEND_CRC_RESULT_reg))
#define  DTV_FRONTEND_DTV_FRONTEND_CRC_RESULT_crc_q_result_shift                 (16)
#define  DTV_FRONTEND_DTV_FRONTEND_CRC_RESULT_crc_i_result_shift                 (0)
#define  DTV_FRONTEND_DTV_FRONTEND_CRC_RESULT_crc_q_result_mask                  (0xFFFF0000)
#define  DTV_FRONTEND_DTV_FRONTEND_CRC_RESULT_crc_i_result_mask                  (0x0000FFFF)
#define  DTV_FRONTEND_DTV_FRONTEND_CRC_RESULT_crc_q_result(data)                 (0xFFFF0000&((data)<<16))
#define  DTV_FRONTEND_DTV_FRONTEND_CRC_RESULT_crc_i_result(data)                 (0x0000FFFF&(data))
#define  DTV_FRONTEND_DTV_FRONTEND_CRC_RESULT_get_crc_q_result(data)             ((0xFFFF0000&(data))>>16)
#define  DTV_FRONTEND_DTV_FRONTEND_CRC_RESULT_get_crc_i_result(data)             (0x0000FFFF&(data))

#define  DTV_FRONTEND_DTV_FRONTEND_FIX_OUT                                       0x18033A1C
#define  DTV_FRONTEND_DTV_FRONTEND_FIX_OUT_reg_addr                              "0xB8033A1C"
#define  DTV_FRONTEND_DTV_FRONTEND_FIX_OUT_reg                                   0xB8033A1C
#define  DTV_FRONTEND_DTV_FRONTEND_FIX_OUT_inst_addr                             "0x004C"
#define  set_DTV_FRONTEND_DTV_FRONTEND_FIX_OUT_reg(data)                         (*((volatile unsigned int*)DTV_FRONTEND_DTV_FRONTEND_FIX_OUT_reg)=data)
#define  get_DTV_FRONTEND_DTV_FRONTEND_FIX_OUT_reg                               (*((volatile unsigned int*)DTV_FRONTEND_DTV_FRONTEND_FIX_OUT_reg))
#define  DTV_FRONTEND_DTV_FRONTEND_FIX_OUT_fe_out_fix_q_shift                    (20)
#define  DTV_FRONTEND_DTV_FRONTEND_FIX_OUT_fe_out_fix_i_shift                    (8)
#define  DTV_FRONTEND_DTV_FRONTEND_FIX_OUT_fe_out_fix_valid_shift                (4)
#define  DTV_FRONTEND_DTV_FRONTEND_FIX_OUT_fe_out_fix_en_shift                   (0)
#define  DTV_FRONTEND_DTV_FRONTEND_FIX_OUT_fe_out_fix_q_mask                     (0xFFF00000)
#define  DTV_FRONTEND_DTV_FRONTEND_FIX_OUT_fe_out_fix_i_mask                     (0x000FFF00)
#define  DTV_FRONTEND_DTV_FRONTEND_FIX_OUT_fe_out_fix_valid_mask                 (0x00000010)
#define  DTV_FRONTEND_DTV_FRONTEND_FIX_OUT_fe_out_fix_en_mask                    (0x00000001)
#define  DTV_FRONTEND_DTV_FRONTEND_FIX_OUT_fe_out_fix_q(data)                    (0xFFF00000&((data)<<20))
#define  DTV_FRONTEND_DTV_FRONTEND_FIX_OUT_fe_out_fix_i(data)                    (0x000FFF00&((data)<<8))
#define  DTV_FRONTEND_DTV_FRONTEND_FIX_OUT_fe_out_fix_valid(data)                (0x00000010&((data)<<4))
#define  DTV_FRONTEND_DTV_FRONTEND_FIX_OUT_fe_out_fix_en(data)                   (0x00000001&(data))
#define  DTV_FRONTEND_DTV_FRONTEND_FIX_OUT_get_fe_out_fix_q(data)                ((0xFFF00000&(data))>>20)
#define  DTV_FRONTEND_DTV_FRONTEND_FIX_OUT_get_fe_out_fix_i(data)                ((0x000FFF00&(data))>>8)
#define  DTV_FRONTEND_DTV_FRONTEND_FIX_OUT_get_fe_out_fix_valid(data)            ((0x00000010&(data))>>4)
#define  DTV_FRONTEND_DTV_FRONTEND_FIX_OUT_get_fe_out_fix_en(data)               (0x00000001&(data))

#define  DTV_FRONTEND_DTV_FRONTEND_DUMMY                                         0x18033A20
#define  DTV_FRONTEND_DTV_FRONTEND_DUMMY_reg_addr                                "0xB8033A20"
#define  DTV_FRONTEND_DTV_FRONTEND_DUMMY_reg                                     0xB8033A20
#define  DTV_FRONTEND_DTV_FRONTEND_DUMMY_inst_addr                               "0x004D"
#define  set_DTV_FRONTEND_DTV_FRONTEND_DUMMY_reg(data)                           (*((volatile unsigned int*)DTV_FRONTEND_DTV_FRONTEND_DUMMY_reg)=data)
#define  get_DTV_FRONTEND_DTV_FRONTEND_DUMMY_reg                                 (*((volatile unsigned int*)DTV_FRONTEND_DTV_FRONTEND_DUMMY_reg))
#define  DTV_FRONTEND_DTV_FRONTEND_DUMMY_dummy1_shift                            (0)
#define  DTV_FRONTEND_DTV_FRONTEND_DUMMY_dummy1_mask                             (0xFFFFFFFF)
#define  DTV_FRONTEND_DTV_FRONTEND_DUMMY_dummy1(data)                            (0xFFFFFFFF&(data))
#define  DTV_FRONTEND_DTV_FRONTEND_DUMMY_get_dummy1(data)                        (0xFFFFFFFF&(data))

#define  DTV_FRONTEND_DTV_FRONTEND_DUMMY2                                        0x18033A24
#define  DTV_FRONTEND_DTV_FRONTEND_DUMMY2_reg_addr                               "0xB8033A24"
#define  DTV_FRONTEND_DTV_FRONTEND_DUMMY2_reg                                    0xB8033A24
#define  DTV_FRONTEND_DTV_FRONTEND_DUMMY2_inst_addr                              "0x004E"
#define  set_DTV_FRONTEND_DTV_FRONTEND_DUMMY2_reg(data)                          (*((volatile unsigned int*)DTV_FRONTEND_DTV_FRONTEND_DUMMY2_reg)=data)
#define  get_DTV_FRONTEND_DTV_FRONTEND_DUMMY2_reg                                (*((volatile unsigned int*)DTV_FRONTEND_DTV_FRONTEND_DUMMY2_reg))
#define  DTV_FRONTEND_DTV_FRONTEND_DUMMY2_dummy2_shift                           (0)
#define  DTV_FRONTEND_DTV_FRONTEND_DUMMY2_dummy2_mask                            (0xFFFFFFFF)
#define  DTV_FRONTEND_DTV_FRONTEND_DUMMY2_dummy2(data)                           (0xFFFFFFFF&(data))
#define  DTV_FRONTEND_DTV_FRONTEND_DUMMY2_get_dummy2(data)                       (0xFFFFFFFF&(data))

#define  DTV_FRONTEND_DTV_FRONTEND_DUMMY3                                        0x18033A28
#define  DTV_FRONTEND_DTV_FRONTEND_DUMMY3_reg_addr                               "0xB8033A28"
#define  DTV_FRONTEND_DTV_FRONTEND_DUMMY3_reg                                    0xB8033A28
#define  DTV_FRONTEND_DTV_FRONTEND_DUMMY3_inst_addr                              "0x004F"
#define  set_DTV_FRONTEND_DTV_FRONTEND_DUMMY3_reg(data)                          (*((volatile unsigned int*)DTV_FRONTEND_DTV_FRONTEND_DUMMY3_reg)=data)
#define  get_DTV_FRONTEND_DTV_FRONTEND_DUMMY3_reg                                (*((volatile unsigned int*)DTV_FRONTEND_DTV_FRONTEND_DUMMY3_reg))
#define  DTV_FRONTEND_DTV_FRONTEND_DUMMY3_dummy3_shift                           (0)
#define  DTV_FRONTEND_DTV_FRONTEND_DUMMY3_dummy3_mask                            (0xFFFFFFFF)
#define  DTV_FRONTEND_DTV_FRONTEND_DUMMY3_dummy3(data)                           (0xFFFFFFFF&(data))
#define  DTV_FRONTEND_DTV_FRONTEND_DUMMY3_get_dummy3(data)                       (0xFFFFFFFF&(data))

#define  DTV_FRONTEND_DTV_FRONTEND_DUMMY4                                        0x18033A2C
#define  DTV_FRONTEND_DTV_FRONTEND_DUMMY4_reg_addr                               "0xB8033A2C"
#define  DTV_FRONTEND_DTV_FRONTEND_DUMMY4_reg                                    0xB8033A2C
#define  DTV_FRONTEND_DTV_FRONTEND_DUMMY4_inst_addr                              "0x0050"
#define  set_DTV_FRONTEND_DTV_FRONTEND_DUMMY4_reg(data)                          (*((volatile unsigned int*)DTV_FRONTEND_DTV_FRONTEND_DUMMY4_reg)=data)
#define  get_DTV_FRONTEND_DTV_FRONTEND_DUMMY4_reg                                (*((volatile unsigned int*)DTV_FRONTEND_DTV_FRONTEND_DUMMY4_reg))
#define  DTV_FRONTEND_DTV_FRONTEND_DUMMY4_dummy4_shift                           (0)
#define  DTV_FRONTEND_DTV_FRONTEND_DUMMY4_dummy4_mask                            (0xFFFFFFFF)
#define  DTV_FRONTEND_DTV_FRONTEND_DUMMY4_dummy4(data)                           (0xFFFFFFFF&(data))
#define  DTV_FRONTEND_DTV_FRONTEND_DUMMY4_get_dummy4(data)                       (0xFFFFFFFF&(data))

#define  DTV_FRONTEND_DTV_FRONTEND_DUMMY5                                        0x18033A30
#define  DTV_FRONTEND_DTV_FRONTEND_DUMMY5_reg_addr                               "0xB8033A30"
#define  DTV_FRONTEND_DTV_FRONTEND_DUMMY5_reg                                    0xB8033A30
#define  DTV_FRONTEND_DTV_FRONTEND_DUMMY5_inst_addr                              "0x0051"
#define  set_DTV_FRONTEND_DTV_FRONTEND_DUMMY5_reg(data)                          (*((volatile unsigned int*)DTV_FRONTEND_DTV_FRONTEND_DUMMY5_reg)=data)
#define  get_DTV_FRONTEND_DTV_FRONTEND_DUMMY5_reg                                (*((volatile unsigned int*)DTV_FRONTEND_DTV_FRONTEND_DUMMY5_reg))
#define  DTV_FRONTEND_DTV_FRONTEND_DUMMY5_dummy5_shift                           (0)
#define  DTV_FRONTEND_DTV_FRONTEND_DUMMY5_dummy5_mask                            (0xFFFFFFFF)
#define  DTV_FRONTEND_DTV_FRONTEND_DUMMY5_dummy5(data)                           (0xFFFFFFFF&(data))
#define  DTV_FRONTEND_DTV_FRONTEND_DUMMY5_get_dummy5(data)                       (0xFFFFFFFF&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======DTV_FRONTEND register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  dtmb_data_valid_delay:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  dtv_demod_iclk_inv:1;
        RBus_UInt32  dtv_demod_iqclk_inv:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  dtv_demod_sel:2;
        RBus_UInt32  res4:2;
        RBus_UInt32  dtv_frontend_mode:2;
        RBus_UInt32  res5:2;
        RBus_UInt32  dtv_dnflt_output_gain:2;
        RBus_UInt32  res6:3;
        RBus_UInt32  dtv_idata_sel:1;
        RBus_UInt32  res7:3;
        RBus_UInt32  dtv_dnflt_en:1;
        RBus_UInt32  dtv_i_phase_rotate:1;
        RBus_UInt32  dtv_q_phase_rotate:1;
        RBus_UInt32  dtv_iq_swap:1;
        RBus_UInt32  res8:1;
    };
}dtv_frontend_dtv_input_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  dtv_input_fifo_clr:1;
        RBus_UInt32  dtv_input_fifo_full:1;
        RBus_UInt32  dtv_input_fifo_empty:1;
        RBus_UInt32  res2:5;
        RBus_UInt32  iqadc_fifo_clr:1;
        RBus_UInt32  iqadc_fifo_full:1;
        RBus_UInt32  iqadc_fifo_empty:1;
        RBus_UInt32  res3:8;
    };
}dtv_frontend_dtv_fifo_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  qadc_delay_sel:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  iadc_delay_sel:2;
    };
}dtv_frontend_dtv_iq_delay_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  adj_cmp_thd:13;
        RBus_UInt32  adj_depth:2;
        RBus_UInt32  adj_alpha:3;
        RBus_UInt32  adj_beta:3;
        RBus_UInt32  res2:3;
        RBus_UInt32  adj_bb_update:1;
        RBus_UInt32  adj_out_u2s:1;
        RBus_UInt32  adj_in_u2s:1;
        RBus_UInt32  adj_update:1;
        RBus_UInt32  adj_enable:1;
    };
}dtv_frontend_adc_cal_3_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  adj_manual_offset:12;
        RBus_UInt32  res2:2;
        RBus_UInt32  adj_manual_gain:14;
    };
}dtv_frontend_adc_cal_7_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  adj_update_cyc:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  adj_cmp_cyc:2;
        RBus_UInt32  adj_en_cal_cyc:1;
        RBus_UInt32  adj_manual_sel:1;
        RBus_UInt32  res3:2;
    };
}dtv_frontend_adc_cal_9_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  adj_debug_offset:12;
        RBus_UInt32  res2:2;
        RBus_UInt32  adj_debug_gain:14;
    };
}dtv_frontend_adc_cal_d_a_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  adj_cal_done:1;
        RBus_UInt32  adj_cal_result:1;
        RBus_UInt32  adj_cal_error:14;
    };
}dtv_frontend_adc_cal_f_e_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef001:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  dtv_frontend_dn5_coef000:13;
    };
}dtv_frontend_dtv_dn5_coef00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef003:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  dtv_frontend_dn5_coef002:13;
    };
}dtv_frontend_dtv_dn5_coef01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef005:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  dtv_frontend_dn5_coef004:13;
    };
}dtv_frontend_dtv_dn5_coef02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef007:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  dtv_frontend_dn5_coef006:13;
    };
}dtv_frontend_dtv_dn5_coef03_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef009:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  dtv_frontend_dn5_coef008:13;
    };
}dtv_frontend_dtv_dn5_coef04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef011:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  dtv_frontend_dn5_coef010:13;
    };
}dtv_frontend_dtv_dn5_coef05_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef013:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  dtv_frontend_dn5_coef012:13;
    };
}dtv_frontend_dtv_dn5_coef06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef015:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  dtv_frontend_dn5_coef014:13;
    };
}dtv_frontend_dtv_dn5_coef07_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef017:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  dtv_frontend_dn5_coef016:13;
    };
}dtv_frontend_dtv_dn5_coef08_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef019:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  dtv_frontend_dn5_coef018:13;
    };
}dtv_frontend_dtv_dn5_coef09_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef021:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  dtv_frontend_dn5_coef020:13;
    };
}dtv_frontend_dtv_dn5_coef10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef023:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  dtv_frontend_dn5_coef022:13;
    };
}dtv_frontend_dtv_dn5_coef11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef025:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  dtv_frontend_dn5_coef024:13;
    };
}dtv_frontend_dtv_dn5_coef12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef027:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  dtv_frontend_dn5_coef026:13;
    };
}dtv_frontend_dtv_dn5_coef13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef029:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  dtv_frontend_dn5_coef028:13;
    };
}dtv_frontend_dtv_dn5_coef14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef031:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  dtv_frontend_dn5_coef030:13;
    };
}dtv_frontend_dtv_dn5_coef15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef033:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  dtv_frontend_dn5_coef032:13;
    };
}dtv_frontend_dtv_dn5_coef16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef035:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  dtv_frontend_dn5_coef034:13;
    };
}dtv_frontend_dtv_dn5_coef17_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef037:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  dtv_frontend_dn5_coef036:13;
    };
}dtv_frontend_dtv_dn5_coef18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef039:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  dtv_frontend_dn5_coef038:13;
    };
}dtv_frontend_dtv_dn5_coef19_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef041:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  dtv_frontend_dn5_coef040:13;
    };
}dtv_frontend_dtv_dn5_coef20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef043:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  dtv_frontend_dn5_coef042:13;
    };
}dtv_frontend_dtv_dn5_coef21_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef045:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  dtv_frontend_dn5_coef044:13;
    };
}dtv_frontend_dtv_dn5_coef22_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef047:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  dtv_frontend_dn5_coef046:13;
    };
}dtv_frontend_dtv_dn5_coef23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef049:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  dtv_frontend_dn5_coef048:13;
    };
}dtv_frontend_dtv_dn5_coef24_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef051:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  dtv_frontend_dn5_coef050:13;
    };
}dtv_frontend_dtv_dn5_coef25_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef053:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  dtv_frontend_dn5_coef052:13;
    };
}dtv_frontend_dtv_dn5_coef26_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef055:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  dtv_frontend_dn5_coef054:13;
    };
}dtv_frontend_dtv_dn5_coef27_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef057:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  dtv_frontend_dn5_coef056:13;
    };
}dtv_frontend_dtv_dn5_coef28_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef059:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  dtv_frontend_dn5_coef058:13;
    };
}dtv_frontend_dtv_dn5_coef29_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef061:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  dtv_frontend_dn5_coef060:13;
    };
}dtv_frontend_dtv_dn5_coef30_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef063:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  dtv_frontend_dn5_coef062:13;
    };
}dtv_frontend_dtv_dn5_coef31_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef065:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  dtv_frontend_dn5_coef064:13;
    };
}dtv_frontend_dtv_dn5_coef32_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef067:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  dtv_frontend_dn5_coef066:13;
    };
}dtv_frontend_dtv_dn5_coef33_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef069:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  dtv_frontend_dn5_coef068:13;
    };
}dtv_frontend_dtv_dn5_coef34_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef071:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  dtv_frontend_dn5_coef070:13;
    };
}dtv_frontend_dtv_dn5_coef35_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef073:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  dtv_frontend_dn5_coef072:13;
    };
}dtv_frontend_dtv_dn5_coef36_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef075:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  dtv_frontend_dn5_coef074:13;
    };
}dtv_frontend_dtv_dn5_coef37_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef077:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  dtv_frontend_dn5_coef076:13;
    };
}dtv_frontend_dtv_dn5_coef38_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef079:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  dtv_frontend_dn5_coef078:13;
    };
}dtv_frontend_dtv_dn5_coef39_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef081:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  dtv_frontend_dn5_coef080:13;
    };
}dtv_frontend_dtv_dn5_coef40_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef083:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  dtv_frontend_dn5_coef082:13;
    };
}dtv_frontend_dtv_dn5_coef41_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef085:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  dtv_frontend_dn5_coef084:13;
    };
}dtv_frontend_dtv_dn5_coef42_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef087:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  dtv_frontend_dn5_coef086:13;
    };
}dtv_frontend_dtv_dn5_coef43_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef089:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  dtv_frontend_dn5_coef088:13;
    };
}dtv_frontend_dtv_dn5_coef44_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef091:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  dtv_frontend_dn5_coef090:13;
    };
}dtv_frontend_dtv_dn5_coef45_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef093:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  dtv_frontend_dn5_coef092:13;
    };
}dtv_frontend_dtv_dn5_coef46_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef095:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  dtv_frontend_dn5_coef094:13;
    };
}dtv_frontend_dtv_dn5_coef47_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef097:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  dtv_frontend_dn5_coef096:13;
    };
}dtv_frontend_dtv_dn5_coef48_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef099:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  dtv_frontend_dn5_coef098:13;
    };
}dtv_frontend_dtv_dn5_coef49_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef101:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  dtv_frontend_dn5_coef100:13;
    };
}dtv_frontend_dtv_dn5_coef50_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef103:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  dtv_frontend_dn5_coef102:13;
    };
}dtv_frontend_dtv_dn5_coef51_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef105:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  dtv_frontend_dn5_coef104:13;
    };
}dtv_frontend_dtv_dn5_coef52_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef107:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  dtv_frontend_dn5_coef106:13;
    };
}dtv_frontend_dtv_dn5_coef53_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef109:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  dtv_frontend_dn5_coef108:13;
    };
}dtv_frontend_dtv_dn5_coef54_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef111:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  dtv_frontend_dn5_coef110:13;
    };
}dtv_frontend_dtv_dn5_coef55_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef113:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  dtv_frontend_dn5_coef112:13;
    };
}dtv_frontend_dtv_dn5_coef56_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef115:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  dtv_frontend_dn5_coef114:13;
    };
}dtv_frontend_dtv_dn5_coef57_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef117:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  dtv_frontend_dn5_coef116:13;
    };
}dtv_frontend_dtv_dn5_coef58_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef119:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  dtv_frontend_dn5_coef118:13;
    };
}dtv_frontend_dtv_dn5_coef59_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef121:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  dtv_frontend_dn5_coef120:13;
    };
}dtv_frontend_dtv_dn5_coef60_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef123:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  dtv_frontend_dn5_coef122:13;
    };
}dtv_frontend_dtv_dn5_coef61_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef125:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  dtv_frontend_dn5_coef124:13;
    };
}dtv_frontend_dtv_dn5_coef62_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef127:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  dtv_frontend_dn5_coef126:13;
    };
}dtv_frontend_dtv_dn5_coef63_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef129:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  dtv_frontend_dn5_coef128:13;
    };
}dtv_frontend_dtv_dn5_coef64_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  dtv_frontend_debug_sel:4;
    };
}dtv_frontend_dtv_frontend_debug_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  dtv_demod_frontend_crc_add:7;
        RBus_UInt32  res2:3;
        RBus_UInt32  dtv_demod_frontend_crc_en:1;
    };
}dtv_frontend_dtv_frontend_crc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_q_result:16;
        RBus_UInt32  crc_i_result:16;
    };
}dtv_frontend_dtv_frontend_crc_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fe_out_fix_q:12;
        RBus_UInt32  fe_out_fix_i:12;
        RBus_UInt32  res1:3;
        RBus_UInt32  fe_out_fix_valid:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  fe_out_fix_en:1;
    };
}dtv_frontend_dtv_frontend_fix_out_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1:32;
    };
}dtv_frontend_dtv_frontend_dummy_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy2:32;
    };
}dtv_frontend_dtv_frontend_dummy2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy3:32;
    };
}dtv_frontend_dtv_frontend_dummy3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy4:32;
    };
}dtv_frontend_dtv_frontend_dummy4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy5:32;
    };
}dtv_frontend_dtv_frontend_dummy5_RBUS;

#else //apply LITTLE_ENDIAN

//======DTV_FRONTEND register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  dtv_iq_swap:1;
        RBus_UInt32  dtv_q_phase_rotate:1;
        RBus_UInt32  dtv_i_phase_rotate:1;
        RBus_UInt32  dtv_dnflt_en:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  dtv_idata_sel:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  dtv_dnflt_output_gain:2;
        RBus_UInt32  res4:2;
        RBus_UInt32  dtv_frontend_mode:2;
        RBus_UInt32  res5:2;
        RBus_UInt32  dtv_demod_sel:2;
        RBus_UInt32  res6:2;
        RBus_UInt32  dtv_demod_iqclk_inv:1;
        RBus_UInt32  dtv_demod_iclk_inv:1;
        RBus_UInt32  res7:2;
        RBus_UInt32  dtmb_data_valid_delay:2;
        RBus_UInt32  res8:2;
    };
}dtv_frontend_dtv_input_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  iqadc_fifo_empty:1;
        RBus_UInt32  iqadc_fifo_full:1;
        RBus_UInt32  iqadc_fifo_clr:1;
        RBus_UInt32  res2:5;
        RBus_UInt32  dtv_input_fifo_empty:1;
        RBus_UInt32  dtv_input_fifo_full:1;
        RBus_UInt32  dtv_input_fifo_clr:1;
        RBus_UInt32  res3:13;
    };
}dtv_frontend_dtv_fifo_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  iadc_delay_sel:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  qadc_delay_sel:2;
        RBus_UInt32  res2:26;
    };
}dtv_frontend_dtv_iq_delay_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  adj_enable:1;
        RBus_UInt32  adj_update:1;
        RBus_UInt32  adj_in_u2s:1;
        RBus_UInt32  adj_out_u2s:1;
        RBus_UInt32  adj_bb_update:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  adj_beta:3;
        RBus_UInt32  adj_alpha:3;
        RBus_UInt32  adj_depth:2;
        RBus_UInt32  adj_cmp_thd:13;
        RBus_UInt32  res2:3;
    };
}dtv_frontend_adc_cal_3_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  adj_manual_gain:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  adj_manual_offset:12;
        RBus_UInt32  res2:4;
    };
}dtv_frontend_adc_cal_7_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  adj_manual_sel:1;
        RBus_UInt32  adj_en_cal_cyc:1;
        RBus_UInt32  adj_cmp_cyc:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  adj_update_cyc:2;
        RBus_UInt32  res3:22;
    };
}dtv_frontend_adc_cal_9_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  adj_debug_gain:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  adj_debug_offset:12;
        RBus_UInt32  res2:4;
    };
}dtv_frontend_adc_cal_d_a_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  adj_cal_error:14;
        RBus_UInt32  adj_cal_result:1;
        RBus_UInt32  adj_cal_done:1;
        RBus_UInt32  res1:16;
    };
}dtv_frontend_adc_cal_f_e_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dtv_frontend_dn5_coef000:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef001:13;
        RBus_UInt32  res2:3;
    };
}dtv_frontend_dtv_dn5_coef00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dtv_frontend_dn5_coef002:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef003:13;
        RBus_UInt32  res2:3;
    };
}dtv_frontend_dtv_dn5_coef01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dtv_frontend_dn5_coef004:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef005:13;
        RBus_UInt32  res2:3;
    };
}dtv_frontend_dtv_dn5_coef02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dtv_frontend_dn5_coef006:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef007:13;
        RBus_UInt32  res2:3;
    };
}dtv_frontend_dtv_dn5_coef03_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dtv_frontend_dn5_coef008:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef009:13;
        RBus_UInt32  res2:3;
    };
}dtv_frontend_dtv_dn5_coef04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dtv_frontend_dn5_coef010:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef011:13;
        RBus_UInt32  res2:3;
    };
}dtv_frontend_dtv_dn5_coef05_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dtv_frontend_dn5_coef012:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef013:13;
        RBus_UInt32  res2:3;
    };
}dtv_frontend_dtv_dn5_coef06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dtv_frontend_dn5_coef014:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef015:13;
        RBus_UInt32  res2:3;
    };
}dtv_frontend_dtv_dn5_coef07_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dtv_frontend_dn5_coef016:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef017:13;
        RBus_UInt32  res2:3;
    };
}dtv_frontend_dtv_dn5_coef08_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dtv_frontend_dn5_coef018:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef019:13;
        RBus_UInt32  res2:3;
    };
}dtv_frontend_dtv_dn5_coef09_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dtv_frontend_dn5_coef020:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef021:13;
        RBus_UInt32  res2:3;
    };
}dtv_frontend_dtv_dn5_coef10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dtv_frontend_dn5_coef022:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef023:13;
        RBus_UInt32  res2:3;
    };
}dtv_frontend_dtv_dn5_coef11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dtv_frontend_dn5_coef024:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef025:13;
        RBus_UInt32  res2:3;
    };
}dtv_frontend_dtv_dn5_coef12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dtv_frontend_dn5_coef026:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef027:13;
        RBus_UInt32  res2:3;
    };
}dtv_frontend_dtv_dn5_coef13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dtv_frontend_dn5_coef028:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef029:13;
        RBus_UInt32  res2:3;
    };
}dtv_frontend_dtv_dn5_coef14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dtv_frontend_dn5_coef030:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef031:13;
        RBus_UInt32  res2:3;
    };
}dtv_frontend_dtv_dn5_coef15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dtv_frontend_dn5_coef032:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef033:13;
        RBus_UInt32  res2:3;
    };
}dtv_frontend_dtv_dn5_coef16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dtv_frontend_dn5_coef034:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef035:13;
        RBus_UInt32  res2:3;
    };
}dtv_frontend_dtv_dn5_coef17_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dtv_frontend_dn5_coef036:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef037:13;
        RBus_UInt32  res2:3;
    };
}dtv_frontend_dtv_dn5_coef18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dtv_frontend_dn5_coef038:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef039:13;
        RBus_UInt32  res2:3;
    };
}dtv_frontend_dtv_dn5_coef19_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dtv_frontend_dn5_coef040:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef041:13;
        RBus_UInt32  res2:3;
    };
}dtv_frontend_dtv_dn5_coef20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dtv_frontend_dn5_coef042:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef043:13;
        RBus_UInt32  res2:3;
    };
}dtv_frontend_dtv_dn5_coef21_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dtv_frontend_dn5_coef044:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef045:13;
        RBus_UInt32  res2:3;
    };
}dtv_frontend_dtv_dn5_coef22_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dtv_frontend_dn5_coef046:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef047:13;
        RBus_UInt32  res2:3;
    };
}dtv_frontend_dtv_dn5_coef23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dtv_frontend_dn5_coef048:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef049:13;
        RBus_UInt32  res2:3;
    };
}dtv_frontend_dtv_dn5_coef24_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dtv_frontend_dn5_coef050:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef051:13;
        RBus_UInt32  res2:3;
    };
}dtv_frontend_dtv_dn5_coef25_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dtv_frontend_dn5_coef052:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef053:13;
        RBus_UInt32  res2:3;
    };
}dtv_frontend_dtv_dn5_coef26_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dtv_frontend_dn5_coef054:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef055:13;
        RBus_UInt32  res2:3;
    };
}dtv_frontend_dtv_dn5_coef27_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dtv_frontend_dn5_coef056:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef057:13;
        RBus_UInt32  res2:3;
    };
}dtv_frontend_dtv_dn5_coef28_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dtv_frontend_dn5_coef058:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef059:13;
        RBus_UInt32  res2:3;
    };
}dtv_frontend_dtv_dn5_coef29_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dtv_frontend_dn5_coef060:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef061:13;
        RBus_UInt32  res2:3;
    };
}dtv_frontend_dtv_dn5_coef30_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dtv_frontend_dn5_coef062:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef063:13;
        RBus_UInt32  res2:3;
    };
}dtv_frontend_dtv_dn5_coef31_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dtv_frontend_dn5_coef064:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef065:13;
        RBus_UInt32  res2:3;
    };
}dtv_frontend_dtv_dn5_coef32_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dtv_frontend_dn5_coef066:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef067:13;
        RBus_UInt32  res2:3;
    };
}dtv_frontend_dtv_dn5_coef33_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dtv_frontend_dn5_coef068:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef069:13;
        RBus_UInt32  res2:3;
    };
}dtv_frontend_dtv_dn5_coef34_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dtv_frontend_dn5_coef070:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef071:13;
        RBus_UInt32  res2:3;
    };
}dtv_frontend_dtv_dn5_coef35_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dtv_frontend_dn5_coef072:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef073:13;
        RBus_UInt32  res2:3;
    };
}dtv_frontend_dtv_dn5_coef36_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dtv_frontend_dn5_coef074:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef075:13;
        RBus_UInt32  res2:3;
    };
}dtv_frontend_dtv_dn5_coef37_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dtv_frontend_dn5_coef076:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef077:13;
        RBus_UInt32  res2:3;
    };
}dtv_frontend_dtv_dn5_coef38_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dtv_frontend_dn5_coef078:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef079:13;
        RBus_UInt32  res2:3;
    };
}dtv_frontend_dtv_dn5_coef39_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dtv_frontend_dn5_coef080:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef081:13;
        RBus_UInt32  res2:3;
    };
}dtv_frontend_dtv_dn5_coef40_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dtv_frontend_dn5_coef082:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef083:13;
        RBus_UInt32  res2:3;
    };
}dtv_frontend_dtv_dn5_coef41_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dtv_frontend_dn5_coef084:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef085:13;
        RBus_UInt32  res2:3;
    };
}dtv_frontend_dtv_dn5_coef42_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dtv_frontend_dn5_coef086:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef087:13;
        RBus_UInt32  res2:3;
    };
}dtv_frontend_dtv_dn5_coef43_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dtv_frontend_dn5_coef088:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef089:13;
        RBus_UInt32  res2:3;
    };
}dtv_frontend_dtv_dn5_coef44_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dtv_frontend_dn5_coef090:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef091:13;
        RBus_UInt32  res2:3;
    };
}dtv_frontend_dtv_dn5_coef45_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dtv_frontend_dn5_coef092:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef093:13;
        RBus_UInt32  res2:3;
    };
}dtv_frontend_dtv_dn5_coef46_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dtv_frontend_dn5_coef094:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef095:13;
        RBus_UInt32  res2:3;
    };
}dtv_frontend_dtv_dn5_coef47_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dtv_frontend_dn5_coef096:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef097:13;
        RBus_UInt32  res2:3;
    };
}dtv_frontend_dtv_dn5_coef48_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dtv_frontend_dn5_coef098:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef099:13;
        RBus_UInt32  res2:3;
    };
}dtv_frontend_dtv_dn5_coef49_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dtv_frontend_dn5_coef100:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef101:13;
        RBus_UInt32  res2:3;
    };
}dtv_frontend_dtv_dn5_coef50_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dtv_frontend_dn5_coef102:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef103:13;
        RBus_UInt32  res2:3;
    };
}dtv_frontend_dtv_dn5_coef51_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dtv_frontend_dn5_coef104:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef105:13;
        RBus_UInt32  res2:3;
    };
}dtv_frontend_dtv_dn5_coef52_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dtv_frontend_dn5_coef106:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef107:13;
        RBus_UInt32  res2:3;
    };
}dtv_frontend_dtv_dn5_coef53_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dtv_frontend_dn5_coef108:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef109:13;
        RBus_UInt32  res2:3;
    };
}dtv_frontend_dtv_dn5_coef54_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dtv_frontend_dn5_coef110:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef111:13;
        RBus_UInt32  res2:3;
    };
}dtv_frontend_dtv_dn5_coef55_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dtv_frontend_dn5_coef112:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef113:13;
        RBus_UInt32  res2:3;
    };
}dtv_frontend_dtv_dn5_coef56_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dtv_frontend_dn5_coef114:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef115:13;
        RBus_UInt32  res2:3;
    };
}dtv_frontend_dtv_dn5_coef57_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dtv_frontend_dn5_coef116:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef117:13;
        RBus_UInt32  res2:3;
    };
}dtv_frontend_dtv_dn5_coef58_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dtv_frontend_dn5_coef118:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef119:13;
        RBus_UInt32  res2:3;
    };
}dtv_frontend_dtv_dn5_coef59_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dtv_frontend_dn5_coef120:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef121:13;
        RBus_UInt32  res2:3;
    };
}dtv_frontend_dtv_dn5_coef60_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dtv_frontend_dn5_coef122:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef123:13;
        RBus_UInt32  res2:3;
    };
}dtv_frontend_dtv_dn5_coef61_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dtv_frontend_dn5_coef124:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef125:13;
        RBus_UInt32  res2:3;
    };
}dtv_frontend_dtv_dn5_coef62_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dtv_frontend_dn5_coef126:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef127:13;
        RBus_UInt32  res2:3;
    };
}dtv_frontend_dtv_dn5_coef63_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dtv_frontend_dn5_coef128:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_frontend_dn5_coef129:13;
        RBus_UInt32  res2:3;
    };
}dtv_frontend_dtv_dn5_coef64_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dtv_frontend_debug_sel:4;
        RBus_UInt32  res1:28;
    };
}dtv_frontend_dtv_frontend_debug_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dtv_demod_frontend_crc_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  dtv_demod_frontend_crc_add:7;
        RBus_UInt32  res2:21;
    };
}dtv_frontend_dtv_frontend_crc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_i_result:16;
        RBus_UInt32  crc_q_result:16;
    };
}dtv_frontend_dtv_frontend_crc_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fe_out_fix_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  fe_out_fix_valid:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  fe_out_fix_i:12;
        RBus_UInt32  fe_out_fix_q:12;
    };
}dtv_frontend_dtv_frontend_fix_out_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1:32;
    };
}dtv_frontend_dtv_frontend_dummy_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy2:32;
    };
}dtv_frontend_dtv_frontend_dummy2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy3:32;
    };
}dtv_frontend_dtv_frontend_dummy3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy4:32;
    };
}dtv_frontend_dtv_frontend_dummy4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy5:32;
    };
}dtv_frontend_dtv_frontend_dummy5_RBUS;




#endif 


#endif 
