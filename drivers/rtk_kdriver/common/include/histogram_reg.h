/**
* @file MarArthur5-DesignSpec-I-Domain_histogram
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_HISTOGRAM_REG_H_
#define _RBUS_HISTOGRAM_REG_H_

#include "rbus_types.h"



//  HISTOGRAM Register Address
#define  HISTOGRAM_ICH1_Hist_IN_CSELECT                                          0x18023200
#define  HISTOGRAM_ICH1_Hist_IN_CSELECT_reg_addr                                 "0xB8023200"
#define  HISTOGRAM_ICH1_Hist_IN_CSELECT_reg                                      0xB8023200
#define  HISTOGRAM_ICH1_Hist_IN_CSELECT_inst_addr                                "0x0000"
#define  set_HISTOGRAM_ICH1_Hist_IN_CSELECT_reg(data)                            (*((volatile unsigned int*)HISTOGRAM_ICH1_Hist_IN_CSELECT_reg)=data)
#define  get_HISTOGRAM_ICH1_Hist_IN_CSELECT_reg                                  (*((volatile unsigned int*)HISTOGRAM_ICH1_Hist_IN_CSELECT_reg))
#define  HISTOGRAM_ICH1_Hist_IN_CSELECT_i2rnd_histogram_sel_shift                (28)
#define  HISTOGRAM_ICH1_Hist_IN_CSELECT_bin_mode_shift                           (27)
#define  HISTOGRAM_ICH1_Hist_IN_CSELECT_lr_select_shift                          (26)
#define  HISTOGRAM_ICH1_Hist_IN_CSELECT_ch1_3d_en_shift                          (25)
#define  HISTOGRAM_ICH1_Hist_IN_CSELECT_ch1_his_updatelockmode_en_shift          (24)
#define  HISTOGRAM_ICH1_Hist_IN_CSELECT_ch1_his_enable_histog_shift              (22)
#define  HISTOGRAM_ICH1_Hist_IN_CSELECT_ch1_his_irq_en_shift                     (21)
#define  HISTOGRAM_ICH1_Hist_IN_CSELECT_ch1_his_yuv_sel_shift                    (19)
#define  HISTOGRAM_ICH1_Hist_IN_CSELECT_ch1_his_num_flds_shift                   (15)
#define  HISTOGRAM_ICH1_Hist_IN_CSELECT_ch1_his_shift_sel_shift                  (12)
#define  HISTOGRAM_ICH1_Hist_IN_CSELECT_ch1_his_offset_shift                     (8)
#define  HISTOGRAM_ICH1_Hist_IN_CSELECT_ch1_his_mode_sel_shift                   (6)
#define  HISTOGRAM_ICH1_Hist_IN_CSELECT_ch1_his_even_odd_pos_en_shift            (5)
#define  HISTOGRAM_ICH1_Hist_IN_CSELECT_ch1_his_even_odd_pos_sel_shift           (4)
#define  HISTOGRAM_ICH1_Hist_IN_CSELECT_ch1_his_even_odd_fld_en_shift            (3)
#define  HISTOGRAM_ICH1_Hist_IN_CSELECT_ch1_his_even_odd_fld_sel_shift           (2)
#define  HISTOGRAM_ICH1_Hist_IN_CSELECT_i2rnd_histogram_sel_mask                 (0x30000000)
#define  HISTOGRAM_ICH1_Hist_IN_CSELECT_bin_mode_mask                            (0x08000000)
#define  HISTOGRAM_ICH1_Hist_IN_CSELECT_lr_select_mask                           (0x04000000)
#define  HISTOGRAM_ICH1_Hist_IN_CSELECT_ch1_3d_en_mask                           (0x02000000)
#define  HISTOGRAM_ICH1_Hist_IN_CSELECT_ch1_his_updatelockmode_en_mask           (0x01000000)
#define  HISTOGRAM_ICH1_Hist_IN_CSELECT_ch1_his_enable_histog_mask               (0x00400000)
#define  HISTOGRAM_ICH1_Hist_IN_CSELECT_ch1_his_irq_en_mask                      (0x00200000)
#define  HISTOGRAM_ICH1_Hist_IN_CSELECT_ch1_his_yuv_sel_mask                     (0x00180000)
#define  HISTOGRAM_ICH1_Hist_IN_CSELECT_ch1_his_num_flds_mask                    (0x00078000)
#define  HISTOGRAM_ICH1_Hist_IN_CSELECT_ch1_his_shift_sel_mask                   (0x00007000)
#define  HISTOGRAM_ICH1_Hist_IN_CSELECT_ch1_his_offset_mask                      (0x00000F00)
#define  HISTOGRAM_ICH1_Hist_IN_CSELECT_ch1_his_mode_sel_mask                    (0x00000040)
#define  HISTOGRAM_ICH1_Hist_IN_CSELECT_ch1_his_even_odd_pos_en_mask             (0x00000020)
#define  HISTOGRAM_ICH1_Hist_IN_CSELECT_ch1_his_even_odd_pos_sel_mask            (0x00000010)
#define  HISTOGRAM_ICH1_Hist_IN_CSELECT_ch1_his_even_odd_fld_en_mask             (0x00000008)
#define  HISTOGRAM_ICH1_Hist_IN_CSELECT_ch1_his_even_odd_fld_sel_mask            (0x00000004)
#define  HISTOGRAM_ICH1_Hist_IN_CSELECT_i2rnd_histogram_sel(data)                (0x30000000&((data)<<28))
#define  HISTOGRAM_ICH1_Hist_IN_CSELECT_bin_mode(data)                           (0x08000000&((data)<<27))
#define  HISTOGRAM_ICH1_Hist_IN_CSELECT_lr_select(data)                          (0x04000000&((data)<<26))
#define  HISTOGRAM_ICH1_Hist_IN_CSELECT_ch1_3d_en(data)                          (0x02000000&((data)<<25))
#define  HISTOGRAM_ICH1_Hist_IN_CSELECT_ch1_his_updatelockmode_en(data)          (0x01000000&((data)<<24))
#define  HISTOGRAM_ICH1_Hist_IN_CSELECT_ch1_his_enable_histog(data)              (0x00400000&((data)<<22))
#define  HISTOGRAM_ICH1_Hist_IN_CSELECT_ch1_his_irq_en(data)                     (0x00200000&((data)<<21))
#define  HISTOGRAM_ICH1_Hist_IN_CSELECT_ch1_his_yuv_sel(data)                    (0x00180000&((data)<<19))
#define  HISTOGRAM_ICH1_Hist_IN_CSELECT_ch1_his_num_flds(data)                   (0x00078000&((data)<<15))
#define  HISTOGRAM_ICH1_Hist_IN_CSELECT_ch1_his_shift_sel(data)                  (0x00007000&((data)<<12))
#define  HISTOGRAM_ICH1_Hist_IN_CSELECT_ch1_his_offset(data)                     (0x00000F00&((data)<<8))
#define  HISTOGRAM_ICH1_Hist_IN_CSELECT_ch1_his_mode_sel(data)                   (0x00000040&((data)<<6))
#define  HISTOGRAM_ICH1_Hist_IN_CSELECT_ch1_his_even_odd_pos_en(data)            (0x00000020&((data)<<5))
#define  HISTOGRAM_ICH1_Hist_IN_CSELECT_ch1_his_even_odd_pos_sel(data)           (0x00000010&((data)<<4))
#define  HISTOGRAM_ICH1_Hist_IN_CSELECT_ch1_his_even_odd_fld_en(data)            (0x00000008&((data)<<3))
#define  HISTOGRAM_ICH1_Hist_IN_CSELECT_ch1_his_even_odd_fld_sel(data)           (0x00000004&((data)<<2))
#define  HISTOGRAM_ICH1_Hist_IN_CSELECT_get_i2rnd_histogram_sel(data)            ((0x30000000&(data))>>28)
#define  HISTOGRAM_ICH1_Hist_IN_CSELECT_get_bin_mode(data)                       ((0x08000000&(data))>>27)
#define  HISTOGRAM_ICH1_Hist_IN_CSELECT_get_lr_select(data)                      ((0x04000000&(data))>>26)
#define  HISTOGRAM_ICH1_Hist_IN_CSELECT_get_ch1_3d_en(data)                      ((0x02000000&(data))>>25)
#define  HISTOGRAM_ICH1_Hist_IN_CSELECT_get_ch1_his_updatelockmode_en(data)      ((0x01000000&(data))>>24)
#define  HISTOGRAM_ICH1_Hist_IN_CSELECT_get_ch1_his_enable_histog(data)          ((0x00400000&(data))>>22)
#define  HISTOGRAM_ICH1_Hist_IN_CSELECT_get_ch1_his_irq_en(data)                 ((0x00200000&(data))>>21)
#define  HISTOGRAM_ICH1_Hist_IN_CSELECT_get_ch1_his_yuv_sel(data)                ((0x00180000&(data))>>19)
#define  HISTOGRAM_ICH1_Hist_IN_CSELECT_get_ch1_his_num_flds(data)               ((0x00078000&(data))>>15)
#define  HISTOGRAM_ICH1_Hist_IN_CSELECT_get_ch1_his_shift_sel(data)              ((0x00007000&(data))>>12)
#define  HISTOGRAM_ICH1_Hist_IN_CSELECT_get_ch1_his_offset(data)                 ((0x00000F00&(data))>>8)
#define  HISTOGRAM_ICH1_Hist_IN_CSELECT_get_ch1_his_mode_sel(data)               ((0x00000040&(data))>>6)
#define  HISTOGRAM_ICH1_Hist_IN_CSELECT_get_ch1_his_even_odd_pos_en(data)        ((0x00000020&(data))>>5)
#define  HISTOGRAM_ICH1_Hist_IN_CSELECT_get_ch1_his_even_odd_pos_sel(data)       ((0x00000010&(data))>>4)
#define  HISTOGRAM_ICH1_Hist_IN_CSELECT_get_ch1_his_even_odd_fld_en(data)        ((0x00000008&(data))>>3)
#define  HISTOGRAM_ICH1_Hist_IN_CSELECT_get_ch1_his_even_odd_fld_sel(data)       ((0x00000004&(data))>>2)

#define  HISTOGRAM_ICH1_Hist_IN_Range_Hor                                        0x18023204
#define  HISTOGRAM_ICH1_Hist_IN_Range_Hor_reg_addr                               "0xB8023204"
#define  HISTOGRAM_ICH1_Hist_IN_Range_Hor_reg                                    0xB8023204
#define  HISTOGRAM_ICH1_Hist_IN_Range_Hor_inst_addr                              "0x0001"
#define  set_HISTOGRAM_ICH1_Hist_IN_Range_Hor_reg(data)                          (*((volatile unsigned int*)HISTOGRAM_ICH1_Hist_IN_Range_Hor_reg)=data)
#define  get_HISTOGRAM_ICH1_Hist_IN_Range_Hor_reg                                (*((volatile unsigned int*)HISTOGRAM_ICH1_Hist_IN_Range_Hor_reg))
#define  HISTOGRAM_ICH1_Hist_IN_Range_Hor_ch1_his_horend_shift                   (16)
#define  HISTOGRAM_ICH1_Hist_IN_Range_Hor_ch1_his_horstart_shift                 (0)
#define  HISTOGRAM_ICH1_Hist_IN_Range_Hor_ch1_his_horend_mask                    (0x1FFF0000)
#define  HISTOGRAM_ICH1_Hist_IN_Range_Hor_ch1_his_horstart_mask                  (0x00001FFF)
#define  HISTOGRAM_ICH1_Hist_IN_Range_Hor_ch1_his_horend(data)                   (0x1FFF0000&((data)<<16))
#define  HISTOGRAM_ICH1_Hist_IN_Range_Hor_ch1_his_horstart(data)                 (0x00001FFF&(data))
#define  HISTOGRAM_ICH1_Hist_IN_Range_Hor_get_ch1_his_horend(data)               ((0x1FFF0000&(data))>>16)
#define  HISTOGRAM_ICH1_Hist_IN_Range_Hor_get_ch1_his_horstart(data)             (0x00001FFF&(data))

#define  HISTOGRAM_ICH1_Hist_IN_Range_Ver                                        0x18023208
#define  HISTOGRAM_ICH1_Hist_IN_Range_Ver_reg_addr                               "0xB8023208"
#define  HISTOGRAM_ICH1_Hist_IN_Range_Ver_reg                                    0xB8023208
#define  HISTOGRAM_ICH1_Hist_IN_Range_Ver_inst_addr                              "0x0002"
#define  set_HISTOGRAM_ICH1_Hist_IN_Range_Ver_reg(data)                          (*((volatile unsigned int*)HISTOGRAM_ICH1_Hist_IN_Range_Ver_reg)=data)
#define  get_HISTOGRAM_ICH1_Hist_IN_Range_Ver_reg                                (*((volatile unsigned int*)HISTOGRAM_ICH1_Hist_IN_Range_Ver_reg))
#define  HISTOGRAM_ICH1_Hist_IN_Range_Ver_ch1_his_verend_shift                   (16)
#define  HISTOGRAM_ICH1_Hist_IN_Range_Ver_ch1_his_verstart_shift                 (0)
#define  HISTOGRAM_ICH1_Hist_IN_Range_Ver_ch1_his_verend_mask                    (0x1FFF0000)
#define  HISTOGRAM_ICH1_Hist_IN_Range_Ver_ch1_his_verstart_mask                  (0x00001FFF)
#define  HISTOGRAM_ICH1_Hist_IN_Range_Ver_ch1_his_verend(data)                   (0x1FFF0000&((data)<<16))
#define  HISTOGRAM_ICH1_Hist_IN_Range_Ver_ch1_his_verstart(data)                 (0x00001FFF&(data))
#define  HISTOGRAM_ICH1_Hist_IN_Range_Ver_get_ch1_his_verend(data)               ((0x1FFF0000&(data))>>16)
#define  HISTOGRAM_ICH1_Hist_IN_Range_Ver_get_ch1_his_verstart(data)             (0x00001FFF&(data))

#define  HISTOGRAM_ICH1_Hist_Status                                              0x1802320C
#define  HISTOGRAM_ICH1_Hist_Status_reg_addr                                     "0xB802320C"
#define  HISTOGRAM_ICH1_Hist_Status_reg                                          0xB802320C
#define  HISTOGRAM_ICH1_Hist_Status_inst_addr                                    "0x0003"
#define  set_HISTOGRAM_ICH1_Hist_Status_reg(data)                                (*((volatile unsigned int*)HISTOGRAM_ICH1_Hist_Status_reg)=data)
#define  get_HISTOGRAM_ICH1_Hist_Status_reg                                      (*((volatile unsigned int*)HISTOGRAM_ICH1_Hist_Status_reg))
#define  HISTOGRAM_ICH1_Hist_Status_i2rnd_histogram_sel_shift                    (2)
#define  HISTOGRAM_ICH1_Hist_Status_ch1_his_dcc_invalid_shift                    (1)
#define  HISTOGRAM_ICH1_Hist_Status_ch1_his_his_irq_shift                        (0)
#define  HISTOGRAM_ICH1_Hist_Status_i2rnd_histogram_sel_mask                     (0x00000004)
#define  HISTOGRAM_ICH1_Hist_Status_ch1_his_dcc_invalid_mask                     (0x00000002)
#define  HISTOGRAM_ICH1_Hist_Status_ch1_his_his_irq_mask                         (0x00000001)
#define  HISTOGRAM_ICH1_Hist_Status_i2rnd_histogram_sel(data)                    (0x00000004&((data)<<2))
#define  HISTOGRAM_ICH1_Hist_Status_ch1_his_dcc_invalid(data)                    (0x00000002&((data)<<1))
#define  HISTOGRAM_ICH1_Hist_Status_ch1_his_his_irq(data)                        (0x00000001&(data))
#define  HISTOGRAM_ICH1_Hist_Status_get_i2rnd_histogram_sel(data)                ((0x00000004&(data))>>2)
#define  HISTOGRAM_ICH1_Hist_Status_get_ch1_his_dcc_invalid(data)                ((0x00000002&(data))>>1)
#define  HISTOGRAM_ICH1_Hist_Status_get_ch1_his_his_irq(data)                    (0x00000001&(data))

#define  HISTOGRAM_ICH1_Hist_Max_Min                                             0x18023210
#define  HISTOGRAM_ICH1_Hist_Max_Min_reg_addr                                    "0xB8023210"
#define  HISTOGRAM_ICH1_Hist_Max_Min_reg                                         0xB8023210
#define  HISTOGRAM_ICH1_Hist_Max_Min_inst_addr                                   "0x0004"
#define  set_HISTOGRAM_ICH1_Hist_Max_Min_reg(data)                               (*((volatile unsigned int*)HISTOGRAM_ICH1_Hist_Max_Min_reg)=data)
#define  get_HISTOGRAM_ICH1_Hist_Max_Min_reg                                     (*((volatile unsigned int*)HISTOGRAM_ICH1_Hist_Max_Min_reg))
#define  HISTOGRAM_ICH1_Hist_Max_Min_ch1_his_max_val_shift                       (16)
#define  HISTOGRAM_ICH1_Hist_Max_Min_ch1_his_min_val_shift                       (0)
#define  HISTOGRAM_ICH1_Hist_Max_Min_ch1_his_max_val_mask                        (0x03FF0000)
#define  HISTOGRAM_ICH1_Hist_Max_Min_ch1_his_min_val_mask                        (0x000003FF)
#define  HISTOGRAM_ICH1_Hist_Max_Min_ch1_his_max_val(data)                       (0x03FF0000&((data)<<16))
#define  HISTOGRAM_ICH1_Hist_Max_Min_ch1_his_min_val(data)                       (0x000003FF&(data))
#define  HISTOGRAM_ICH1_Hist_Max_Min_get_ch1_his_max_val(data)                   ((0x03FF0000&(data))>>16)
#define  HISTOGRAM_ICH1_Hist_Max_Min_get_ch1_his_min_val(data)                   (0x000003FF&(data))

#define  HISTOGRAM_ICH1_Bycolor_Debug                                            0x18023214
#define  HISTOGRAM_ICH1_Bycolor_Debug_reg_addr                                   "0xB8023214"
#define  HISTOGRAM_ICH1_Bycolor_Debug_reg                                        0xB8023214
#define  HISTOGRAM_ICH1_Bycolor_Debug_inst_addr                                  "0x0005"
#define  set_HISTOGRAM_ICH1_Bycolor_Debug_reg(data)                              (*((volatile unsigned int*)HISTOGRAM_ICH1_Bycolor_Debug_reg)=data)
#define  get_HISTOGRAM_ICH1_Bycolor_Debug_reg                                    (*((volatile unsigned int*)HISTOGRAM_ICH1_Bycolor_Debug_reg))
#define  HISTOGRAM_ICH1_Bycolor_Debug_bycolor_debug_mode_shift                   (0)
#define  HISTOGRAM_ICH1_Bycolor_Debug_bycolor_debug_mode_mask                    (0x00000003)
#define  HISTOGRAM_ICH1_Bycolor_Debug_bycolor_debug_mode(data)                   (0x00000003&(data))
#define  HISTOGRAM_ICH1_Bycolor_Debug_get_bycolor_debug_mode(data)               (0x00000003&(data))

#define  HISTOGRAM_ICH1_Hist_SumVal_High                                         0x18023218
#define  HISTOGRAM_ICH1_Hist_SumVal_High_reg_addr                                "0xB8023218"
#define  HISTOGRAM_ICH1_Hist_SumVal_High_reg                                     0xB8023218
#define  HISTOGRAM_ICH1_Hist_SumVal_High_inst_addr                               "0x0006"
#define  set_HISTOGRAM_ICH1_Hist_SumVal_High_reg(data)                           (*((volatile unsigned int*)HISTOGRAM_ICH1_Hist_SumVal_High_reg)=data)
#define  get_HISTOGRAM_ICH1_Hist_SumVal_High_reg                                 (*((volatile unsigned int*)HISTOGRAM_ICH1_Hist_SumVal_High_reg))
#define  HISTOGRAM_ICH1_Hist_SumVal_High_ch1_his_sumval_high_shift               (0)
#define  HISTOGRAM_ICH1_Hist_SumVal_High_ch1_his_sumval_high_mask                (0x000001FF)
#define  HISTOGRAM_ICH1_Hist_SumVal_High_ch1_his_sumval_high(data)               (0x000001FF&(data))
#define  HISTOGRAM_ICH1_Hist_SumVal_High_get_ch1_his_sumval_high(data)           (0x000001FF&(data))

#define  HISTOGRAM_ICH1_Hist_SumVal_Low                                          0x1802321C
#define  HISTOGRAM_ICH1_Hist_SumVal_Low_reg_addr                                 "0xB802321C"
#define  HISTOGRAM_ICH1_Hist_SumVal_Low_reg                                      0xB802321C
#define  HISTOGRAM_ICH1_Hist_SumVal_Low_inst_addr                                "0x0007"
#define  set_HISTOGRAM_ICH1_Hist_SumVal_Low_reg(data)                            (*((volatile unsigned int*)HISTOGRAM_ICH1_Hist_SumVal_Low_reg)=data)
#define  get_HISTOGRAM_ICH1_Hist_SumVal_Low_reg                                  (*((volatile unsigned int*)HISTOGRAM_ICH1_Hist_SumVal_Low_reg))
#define  HISTOGRAM_ICH1_Hist_SumVal_Low_ch1_his_sumval_low_shift                 (0)
#define  HISTOGRAM_ICH1_Hist_SumVal_Low_ch1_his_sumval_low_mask                  (0x00FFFFFF)
#define  HISTOGRAM_ICH1_Hist_SumVal_Low_ch1_his_sumval_low(data)                 (0x00FFFFFF&(data))
#define  HISTOGRAM_ICH1_Hist_SumVal_Low_get_ch1_his_sumval_low(data)             (0x00FFFFFF&(data))

#define  HISTOGRAM_ICH1_C0_Hist_Bound                                            0x18023220
#define  HISTOGRAM_ICH1_C0_Hist_Bound_reg_addr                                   "0xB8023220"
#define  HISTOGRAM_ICH1_C0_Hist_Bound_reg                                        0xB8023220
#define  HISTOGRAM_ICH1_C0_Hist_Bound_inst_addr                                  "0x0008"
#define  set_HISTOGRAM_ICH1_C0_Hist_Bound_reg(data)                              (*((volatile unsigned int*)HISTOGRAM_ICH1_C0_Hist_Bound_reg)=data)
#define  get_HISTOGRAM_ICH1_C0_Hist_Bound_reg                                    (*((volatile unsigned int*)HISTOGRAM_ICH1_C0_Hist_Bound_reg))
#define  HISTOGRAM_ICH1_C0_Hist_Bound_ch1_c0_upper_bound_shift                   (16)
#define  HISTOGRAM_ICH1_C0_Hist_Bound_ch1_c0_lower_bound_shift                   (0)
#define  HISTOGRAM_ICH1_C0_Hist_Bound_ch1_c0_upper_bound_mask                    (0x03FF0000)
#define  HISTOGRAM_ICH1_C0_Hist_Bound_ch1_c0_lower_bound_mask                    (0x000003FF)
#define  HISTOGRAM_ICH1_C0_Hist_Bound_ch1_c0_upper_bound(data)                   (0x03FF0000&((data)<<16))
#define  HISTOGRAM_ICH1_C0_Hist_Bound_ch1_c0_lower_bound(data)                   (0x000003FF&(data))
#define  HISTOGRAM_ICH1_C0_Hist_Bound_get_ch1_c0_upper_bound(data)               ((0x03FF0000&(data))>>16)
#define  HISTOGRAM_ICH1_C0_Hist_Bound_get_ch1_c0_lower_bound(data)               (0x000003FF&(data))

#define  HISTOGRAM_ICH1_C0_Hist_Bound_U                                          0x18023224
#define  HISTOGRAM_ICH1_C0_Hist_Bound_U_reg_addr                                 "0xB8023224"
#define  HISTOGRAM_ICH1_C0_Hist_Bound_U_reg                                      0xB8023224
#define  HISTOGRAM_ICH1_C0_Hist_Bound_U_inst_addr                                "0x0009"
#define  set_HISTOGRAM_ICH1_C0_Hist_Bound_U_reg(data)                            (*((volatile unsigned int*)HISTOGRAM_ICH1_C0_Hist_Bound_U_reg)=data)
#define  get_HISTOGRAM_ICH1_C0_Hist_Bound_U_reg                                  (*((volatile unsigned int*)HISTOGRAM_ICH1_C0_Hist_Bound_U_reg))
#define  HISTOGRAM_ICH1_C0_Hist_Bound_U_ch1_c0_upper_bound_u_shift               (16)
#define  HISTOGRAM_ICH1_C0_Hist_Bound_U_ch1_c0_lower_bound_u_shift               (0)
#define  HISTOGRAM_ICH1_C0_Hist_Bound_U_ch1_c0_upper_bound_u_mask                (0x03FF0000)
#define  HISTOGRAM_ICH1_C0_Hist_Bound_U_ch1_c0_lower_bound_u_mask                (0x000003FF)
#define  HISTOGRAM_ICH1_C0_Hist_Bound_U_ch1_c0_upper_bound_u(data)               (0x03FF0000&((data)<<16))
#define  HISTOGRAM_ICH1_C0_Hist_Bound_U_ch1_c0_lower_bound_u(data)               (0x000003FF&(data))
#define  HISTOGRAM_ICH1_C0_Hist_Bound_U_get_ch1_c0_upper_bound_u(data)           ((0x03FF0000&(data))>>16)
#define  HISTOGRAM_ICH1_C0_Hist_Bound_U_get_ch1_c0_lower_bound_u(data)           (0x000003FF&(data))

#define  HISTOGRAM_ICH1_C0_Hist_Bound_V                                          0x18023228
#define  HISTOGRAM_ICH1_C0_Hist_Bound_V_reg_addr                                 "0xB8023228"
#define  HISTOGRAM_ICH1_C0_Hist_Bound_V_reg                                      0xB8023228
#define  HISTOGRAM_ICH1_C0_Hist_Bound_V_inst_addr                                "0x000A"
#define  set_HISTOGRAM_ICH1_C0_Hist_Bound_V_reg(data)                            (*((volatile unsigned int*)HISTOGRAM_ICH1_C0_Hist_Bound_V_reg)=data)
#define  get_HISTOGRAM_ICH1_C0_Hist_Bound_V_reg                                  (*((volatile unsigned int*)HISTOGRAM_ICH1_C0_Hist_Bound_V_reg))
#define  HISTOGRAM_ICH1_C0_Hist_Bound_V_ch1_c0_upper_bound_v_shift               (16)
#define  HISTOGRAM_ICH1_C0_Hist_Bound_V_ch1_c0_lower_bound_v_shift               (0)
#define  HISTOGRAM_ICH1_C0_Hist_Bound_V_ch1_c0_upper_bound_v_mask                (0x03FF0000)
#define  HISTOGRAM_ICH1_C0_Hist_Bound_V_ch1_c0_lower_bound_v_mask                (0x000003FF)
#define  HISTOGRAM_ICH1_C0_Hist_Bound_V_ch1_c0_upper_bound_v(data)               (0x03FF0000&((data)<<16))
#define  HISTOGRAM_ICH1_C0_Hist_Bound_V_ch1_c0_lower_bound_v(data)               (0x000003FF&(data))
#define  HISTOGRAM_ICH1_C0_Hist_Bound_V_get_ch1_c0_upper_bound_v(data)           ((0x03FF0000&(data))>>16)
#define  HISTOGRAM_ICH1_C0_Hist_Bound_V_get_ch1_c0_lower_bound_v(data)           (0x000003FF&(data))

#define  HISTOGRAM_ICH1_Hist_READ_CTR                                            0x1802322C
#define  HISTOGRAM_ICH1_Hist_READ_CTR_reg_addr                                   "0xB802322C"
#define  HISTOGRAM_ICH1_Hist_READ_CTR_reg                                        0xB802322C
#define  HISTOGRAM_ICH1_Hist_READ_CTR_inst_addr                                  "0x000B"
#define  set_HISTOGRAM_ICH1_Hist_READ_CTR_reg(data)                              (*((volatile unsigned int*)HISTOGRAM_ICH1_Hist_READ_CTR_reg)=data)
#define  get_HISTOGRAM_ICH1_Hist_READ_CTR_reg                                    (*((volatile unsigned int*)HISTOGRAM_ICH1_Hist_READ_CTR_reg))
#define  HISTOGRAM_ICH1_Hist_READ_CTR_ch1_sram_read_shift                        (3)
#define  HISTOGRAM_ICH1_Hist_READ_CTR_ch1_sram_block_shift                       (1)
#define  HISTOGRAM_ICH1_Hist_READ_CTR_ch1_sram_read_consistent_flag_shift        (0)
#define  HISTOGRAM_ICH1_Hist_READ_CTR_ch1_sram_read_mask                         (0x00000008)
#define  HISTOGRAM_ICH1_Hist_READ_CTR_ch1_sram_block_mask                        (0x00000006)
#define  HISTOGRAM_ICH1_Hist_READ_CTR_ch1_sram_read_consistent_flag_mask         (0x00000001)
#define  HISTOGRAM_ICH1_Hist_READ_CTR_ch1_sram_read(data)                        (0x00000008&((data)<<3))
#define  HISTOGRAM_ICH1_Hist_READ_CTR_ch1_sram_block(data)                       (0x00000006&((data)<<1))
#define  HISTOGRAM_ICH1_Hist_READ_CTR_ch1_sram_read_consistent_flag(data)        (0x00000001&(data))
#define  HISTOGRAM_ICH1_Hist_READ_CTR_get_ch1_sram_read(data)                    ((0x00000008&(data))>>3)
#define  HISTOGRAM_ICH1_Hist_READ_CTR_get_ch1_sram_block(data)                   ((0x00000006&(data))>>1)
#define  HISTOGRAM_ICH1_Hist_READ_CTR_get_ch1_sram_read_consistent_flag(data)    (0x00000001&(data))

#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_01_00                                    0x18023230
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_01_00_reg_addr                           "0xB8023230"
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_01_00_reg                                0xB8023230
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_01_00_inst_addr                          "0x000C"
#define  set_HISTOGRAM_ICH1_C0_Hist_IN_Data_01_00_reg(data)                      (*((volatile unsigned int*)HISTOGRAM_ICH1_C0_Hist_IN_Data_01_00_reg)=data)
#define  get_HISTOGRAM_ICH1_C0_Hist_IN_Data_01_00_reg                            (*((volatile unsigned int*)HISTOGRAM_ICH1_C0_Hist_IN_Data_01_00_reg))
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_01_00_ch1_c0_hist01_shift                (16)
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_01_00_ch1_c0_hist00_shift                (0)
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_01_00_ch1_c0_hist01_mask                 (0xFFFF0000)
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_01_00_ch1_c0_hist00_mask                 (0x0000FFFF)
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_01_00_ch1_c0_hist01(data)                (0xFFFF0000&((data)<<16))
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_01_00_ch1_c0_hist00(data)                (0x0000FFFF&(data))
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_01_00_get_ch1_c0_hist01(data)            ((0xFFFF0000&(data))>>16)
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_01_00_get_ch1_c0_hist00(data)            (0x0000FFFF&(data))

#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_03_02                                    0x18023234
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_03_02_reg_addr                           "0xB8023234"
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_03_02_reg                                0xB8023234
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_03_02_inst_addr                          "0x000D"
#define  set_HISTOGRAM_ICH1_C0_Hist_IN_Data_03_02_reg(data)                      (*((volatile unsigned int*)HISTOGRAM_ICH1_C0_Hist_IN_Data_03_02_reg)=data)
#define  get_HISTOGRAM_ICH1_C0_Hist_IN_Data_03_02_reg                            (*((volatile unsigned int*)HISTOGRAM_ICH1_C0_Hist_IN_Data_03_02_reg))
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_03_02_ch1_c0_hist03_shift                (16)
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_03_02_ch1_c0_hist02_shift                (0)
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_03_02_ch1_c0_hist03_mask                 (0xFFFF0000)
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_03_02_ch1_c0_hist02_mask                 (0x0000FFFF)
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_03_02_ch1_c0_hist03(data)                (0xFFFF0000&((data)<<16))
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_03_02_ch1_c0_hist02(data)                (0x0000FFFF&(data))
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_03_02_get_ch1_c0_hist03(data)            ((0xFFFF0000&(data))>>16)
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_03_02_get_ch1_c0_hist02(data)            (0x0000FFFF&(data))

#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_05_04                                    0x18023238
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_05_04_reg_addr                           "0xB8023238"
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_05_04_reg                                0xB8023238
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_05_04_inst_addr                          "0x000E"
#define  set_HISTOGRAM_ICH1_C0_Hist_IN_Data_05_04_reg(data)                      (*((volatile unsigned int*)HISTOGRAM_ICH1_C0_Hist_IN_Data_05_04_reg)=data)
#define  get_HISTOGRAM_ICH1_C0_Hist_IN_Data_05_04_reg                            (*((volatile unsigned int*)HISTOGRAM_ICH1_C0_Hist_IN_Data_05_04_reg))
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_05_04_ch1_c0_hist05_shift                (16)
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_05_04_ch1_c0_hist04_shift                (0)
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_05_04_ch1_c0_hist05_mask                 (0xFFFF0000)
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_05_04_ch1_c0_hist04_mask                 (0x0000FFFF)
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_05_04_ch1_c0_hist05(data)                (0xFFFF0000&((data)<<16))
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_05_04_ch1_c0_hist04(data)                (0x0000FFFF&(data))
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_05_04_get_ch1_c0_hist05(data)            ((0xFFFF0000&(data))>>16)
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_05_04_get_ch1_c0_hist04(data)            (0x0000FFFF&(data))

#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_07_06                                    0x1802323C
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_07_06_reg_addr                           "0xB802323C"
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_07_06_reg                                0xB802323C
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_07_06_inst_addr                          "0x000F"
#define  set_HISTOGRAM_ICH1_C0_Hist_IN_Data_07_06_reg(data)                      (*((volatile unsigned int*)HISTOGRAM_ICH1_C0_Hist_IN_Data_07_06_reg)=data)
#define  get_HISTOGRAM_ICH1_C0_Hist_IN_Data_07_06_reg                            (*((volatile unsigned int*)HISTOGRAM_ICH1_C0_Hist_IN_Data_07_06_reg))
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_07_06_ch1_c0_hist07_shift                (16)
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_07_06_ch1_c0_hist06_shift                (0)
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_07_06_ch1_c0_hist07_mask                 (0xFFFF0000)
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_07_06_ch1_c0_hist06_mask                 (0x0000FFFF)
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_07_06_ch1_c0_hist07(data)                (0xFFFF0000&((data)<<16))
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_07_06_ch1_c0_hist06(data)                (0x0000FFFF&(data))
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_07_06_get_ch1_c0_hist07(data)            ((0xFFFF0000&(data))>>16)
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_07_06_get_ch1_c0_hist06(data)            (0x0000FFFF&(data))

#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_09_08                                    0x18023240
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_09_08_reg_addr                           "0xB8023240"
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_09_08_reg                                0xB8023240
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_09_08_inst_addr                          "0x0010"
#define  set_HISTOGRAM_ICH1_C0_Hist_IN_Data_09_08_reg(data)                      (*((volatile unsigned int*)HISTOGRAM_ICH1_C0_Hist_IN_Data_09_08_reg)=data)
#define  get_HISTOGRAM_ICH1_C0_Hist_IN_Data_09_08_reg                            (*((volatile unsigned int*)HISTOGRAM_ICH1_C0_Hist_IN_Data_09_08_reg))
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_09_08_ch1_c0_hist09_shift                (16)
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_09_08_ch1_c0_hist08_shift                (0)
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_09_08_ch1_c0_hist09_mask                 (0xFFFF0000)
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_09_08_ch1_c0_hist08_mask                 (0x0000FFFF)
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_09_08_ch1_c0_hist09(data)                (0xFFFF0000&((data)<<16))
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_09_08_ch1_c0_hist08(data)                (0x0000FFFF&(data))
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_09_08_get_ch1_c0_hist09(data)            ((0xFFFF0000&(data))>>16)
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_09_08_get_ch1_c0_hist08(data)            (0x0000FFFF&(data))

#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_11_10                                    0x18023244
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_11_10_reg_addr                           "0xB8023244"
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_11_10_reg                                0xB8023244
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_11_10_inst_addr                          "0x0011"
#define  set_HISTOGRAM_ICH1_C0_Hist_IN_Data_11_10_reg(data)                      (*((volatile unsigned int*)HISTOGRAM_ICH1_C0_Hist_IN_Data_11_10_reg)=data)
#define  get_HISTOGRAM_ICH1_C0_Hist_IN_Data_11_10_reg                            (*((volatile unsigned int*)HISTOGRAM_ICH1_C0_Hist_IN_Data_11_10_reg))
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_11_10_ch1_c0_hist11_shift                (16)
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_11_10_ch1_c0_hist10_shift                (0)
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_11_10_ch1_c0_hist11_mask                 (0xFFFF0000)
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_11_10_ch1_c0_hist10_mask                 (0x0000FFFF)
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_11_10_ch1_c0_hist11(data)                (0xFFFF0000&((data)<<16))
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_11_10_ch1_c0_hist10(data)                (0x0000FFFF&(data))
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_11_10_get_ch1_c0_hist11(data)            ((0xFFFF0000&(data))>>16)
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_11_10_get_ch1_c0_hist10(data)            (0x0000FFFF&(data))

#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_13_12                                    0x18023248
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_13_12_reg_addr                           "0xB8023248"
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_13_12_reg                                0xB8023248
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_13_12_inst_addr                          "0x0012"
#define  set_HISTOGRAM_ICH1_C0_Hist_IN_Data_13_12_reg(data)                      (*((volatile unsigned int*)HISTOGRAM_ICH1_C0_Hist_IN_Data_13_12_reg)=data)
#define  get_HISTOGRAM_ICH1_C0_Hist_IN_Data_13_12_reg                            (*((volatile unsigned int*)HISTOGRAM_ICH1_C0_Hist_IN_Data_13_12_reg))
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_13_12_ch1_c0_hist13_shift                (16)
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_13_12_ch1_c0_hist12_shift                (0)
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_13_12_ch1_c0_hist13_mask                 (0xFFFF0000)
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_13_12_ch1_c0_hist12_mask                 (0x0000FFFF)
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_13_12_ch1_c0_hist13(data)                (0xFFFF0000&((data)<<16))
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_13_12_ch1_c0_hist12(data)                (0x0000FFFF&(data))
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_13_12_get_ch1_c0_hist13(data)            ((0xFFFF0000&(data))>>16)
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_13_12_get_ch1_c0_hist12(data)            (0x0000FFFF&(data))

#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_15_14                                    0x1802324C
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_15_14_reg_addr                           "0xB802324C"
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_15_14_reg                                0xB802324C
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_15_14_inst_addr                          "0x0013"
#define  set_HISTOGRAM_ICH1_C0_Hist_IN_Data_15_14_reg(data)                      (*((volatile unsigned int*)HISTOGRAM_ICH1_C0_Hist_IN_Data_15_14_reg)=data)
#define  get_HISTOGRAM_ICH1_C0_Hist_IN_Data_15_14_reg                            (*((volatile unsigned int*)HISTOGRAM_ICH1_C0_Hist_IN_Data_15_14_reg))
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_15_14_ch1_c0_hist15_shift                (16)
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_15_14_ch1_c0_hist14_shift                (0)
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_15_14_ch1_c0_hist15_mask                 (0xFFFF0000)
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_15_14_ch1_c0_hist14_mask                 (0x0000FFFF)
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_15_14_ch1_c0_hist15(data)                (0xFFFF0000&((data)<<16))
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_15_14_ch1_c0_hist14(data)                (0x0000FFFF&(data))
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_15_14_get_ch1_c0_hist15(data)            ((0xFFFF0000&(data))>>16)
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_15_14_get_ch1_c0_hist14(data)            (0x0000FFFF&(data))

#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_17_16                                    0x18023250
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_17_16_reg_addr                           "0xB8023250"
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_17_16_reg                                0xB8023250
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_17_16_inst_addr                          "0x0014"
#define  set_HISTOGRAM_ICH1_C0_Hist_IN_Data_17_16_reg(data)                      (*((volatile unsigned int*)HISTOGRAM_ICH1_C0_Hist_IN_Data_17_16_reg)=data)
#define  get_HISTOGRAM_ICH1_C0_Hist_IN_Data_17_16_reg                            (*((volatile unsigned int*)HISTOGRAM_ICH1_C0_Hist_IN_Data_17_16_reg))
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_17_16_ch1_c0_hist17_shift                (16)
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_17_16_ch1_c0_hist16_shift                (0)
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_17_16_ch1_c0_hist17_mask                 (0xFFFF0000)
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_17_16_ch1_c0_hist16_mask                 (0x0000FFFF)
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_17_16_ch1_c0_hist17(data)                (0xFFFF0000&((data)<<16))
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_17_16_ch1_c0_hist16(data)                (0x0000FFFF&(data))
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_17_16_get_ch1_c0_hist17(data)            ((0xFFFF0000&(data))>>16)
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_17_16_get_ch1_c0_hist16(data)            (0x0000FFFF&(data))

#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_19_18                                    0x18023254
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_19_18_reg_addr                           "0xB8023254"
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_19_18_reg                                0xB8023254
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_19_18_inst_addr                          "0x0015"
#define  set_HISTOGRAM_ICH1_C0_Hist_IN_Data_19_18_reg(data)                      (*((volatile unsigned int*)HISTOGRAM_ICH1_C0_Hist_IN_Data_19_18_reg)=data)
#define  get_HISTOGRAM_ICH1_C0_Hist_IN_Data_19_18_reg                            (*((volatile unsigned int*)HISTOGRAM_ICH1_C0_Hist_IN_Data_19_18_reg))
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_19_18_ch1_c0_hist19_shift                (16)
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_19_18_ch1_c0_hist18_shift                (0)
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_19_18_ch1_c0_hist19_mask                 (0xFFFF0000)
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_19_18_ch1_c0_hist18_mask                 (0x0000FFFF)
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_19_18_ch1_c0_hist19(data)                (0xFFFF0000&((data)<<16))
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_19_18_ch1_c0_hist18(data)                (0x0000FFFF&(data))
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_19_18_get_ch1_c0_hist19(data)            ((0xFFFF0000&(data))>>16)
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_19_18_get_ch1_c0_hist18(data)            (0x0000FFFF&(data))

#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_21_20                                    0x18023258
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_21_20_reg_addr                           "0xB8023258"
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_21_20_reg                                0xB8023258
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_21_20_inst_addr                          "0x0016"
#define  set_HISTOGRAM_ICH1_C0_Hist_IN_Data_21_20_reg(data)                      (*((volatile unsigned int*)HISTOGRAM_ICH1_C0_Hist_IN_Data_21_20_reg)=data)
#define  get_HISTOGRAM_ICH1_C0_Hist_IN_Data_21_20_reg                            (*((volatile unsigned int*)HISTOGRAM_ICH1_C0_Hist_IN_Data_21_20_reg))
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_21_20_ch1_c0_hist21_shift                (16)
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_21_20_ch1_c0_hist20_shift                (0)
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_21_20_ch1_c0_hist21_mask                 (0xFFFF0000)
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_21_20_ch1_c0_hist20_mask                 (0x0000FFFF)
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_21_20_ch1_c0_hist21(data)                (0xFFFF0000&((data)<<16))
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_21_20_ch1_c0_hist20(data)                (0x0000FFFF&(data))
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_21_20_get_ch1_c0_hist21(data)            ((0xFFFF0000&(data))>>16)
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_21_20_get_ch1_c0_hist20(data)            (0x0000FFFF&(data))

#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_23_22                                    0x1802325C
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_23_22_reg_addr                           "0xB802325C"
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_23_22_reg                                0xB802325C
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_23_22_inst_addr                          "0x0017"
#define  set_HISTOGRAM_ICH1_C0_Hist_IN_Data_23_22_reg(data)                      (*((volatile unsigned int*)HISTOGRAM_ICH1_C0_Hist_IN_Data_23_22_reg)=data)
#define  get_HISTOGRAM_ICH1_C0_Hist_IN_Data_23_22_reg                            (*((volatile unsigned int*)HISTOGRAM_ICH1_C0_Hist_IN_Data_23_22_reg))
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_23_22_ch1_c0_hist23_shift                (16)
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_23_22_ch1_c0_hist22_shift                (0)
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_23_22_ch1_c0_hist23_mask                 (0xFFFF0000)
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_23_22_ch1_c0_hist22_mask                 (0x0000FFFF)
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_23_22_ch1_c0_hist23(data)                (0xFFFF0000&((data)<<16))
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_23_22_ch1_c0_hist22(data)                (0x0000FFFF&(data))
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_23_22_get_ch1_c0_hist23(data)            ((0xFFFF0000&(data))>>16)
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_23_22_get_ch1_c0_hist22(data)            (0x0000FFFF&(data))

#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_25_24                                    0x18023260
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_25_24_reg_addr                           "0xB8023260"
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_25_24_reg                                0xB8023260
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_25_24_inst_addr                          "0x0018"
#define  set_HISTOGRAM_ICH1_C0_Hist_IN_Data_25_24_reg(data)                      (*((volatile unsigned int*)HISTOGRAM_ICH1_C0_Hist_IN_Data_25_24_reg)=data)
#define  get_HISTOGRAM_ICH1_C0_Hist_IN_Data_25_24_reg                            (*((volatile unsigned int*)HISTOGRAM_ICH1_C0_Hist_IN_Data_25_24_reg))
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_25_24_ch1_c0_hist25_shift                (16)
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_25_24_ch1_c0_hist24_shift                (0)
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_25_24_ch1_c0_hist25_mask                 (0xFFFF0000)
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_25_24_ch1_c0_hist24_mask                 (0x0000FFFF)
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_25_24_ch1_c0_hist25(data)                (0xFFFF0000&((data)<<16))
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_25_24_ch1_c0_hist24(data)                (0x0000FFFF&(data))
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_25_24_get_ch1_c0_hist25(data)            ((0xFFFF0000&(data))>>16)
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_25_24_get_ch1_c0_hist24(data)            (0x0000FFFF&(data))

#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_27_26                                    0x18023264
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_27_26_reg_addr                           "0xB8023264"
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_27_26_reg                                0xB8023264
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_27_26_inst_addr                          "0x0019"
#define  set_HISTOGRAM_ICH1_C0_Hist_IN_Data_27_26_reg(data)                      (*((volatile unsigned int*)HISTOGRAM_ICH1_C0_Hist_IN_Data_27_26_reg)=data)
#define  get_HISTOGRAM_ICH1_C0_Hist_IN_Data_27_26_reg                            (*((volatile unsigned int*)HISTOGRAM_ICH1_C0_Hist_IN_Data_27_26_reg))
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_27_26_ch1_c0_hist27_shift                (16)
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_27_26_ch1_c0_hist26_shift                (0)
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_27_26_ch1_c0_hist27_mask                 (0xFFFF0000)
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_27_26_ch1_c0_hist26_mask                 (0x0000FFFF)
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_27_26_ch1_c0_hist27(data)                (0xFFFF0000&((data)<<16))
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_27_26_ch1_c0_hist26(data)                (0x0000FFFF&(data))
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_27_26_get_ch1_c0_hist27(data)            ((0xFFFF0000&(data))>>16)
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_27_26_get_ch1_c0_hist26(data)            (0x0000FFFF&(data))

#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_29_28                                    0x18023268
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_29_28_reg_addr                           "0xB8023268"
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_29_28_reg                                0xB8023268
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_29_28_inst_addr                          "0x001A"
#define  set_HISTOGRAM_ICH1_C0_Hist_IN_Data_29_28_reg(data)                      (*((volatile unsigned int*)HISTOGRAM_ICH1_C0_Hist_IN_Data_29_28_reg)=data)
#define  get_HISTOGRAM_ICH1_C0_Hist_IN_Data_29_28_reg                            (*((volatile unsigned int*)HISTOGRAM_ICH1_C0_Hist_IN_Data_29_28_reg))
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_29_28_ch1_c0_hist29_shift                (16)
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_29_28_ch1_c0_hist28_shift                (0)
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_29_28_ch1_c0_hist29_mask                 (0xFFFF0000)
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_29_28_ch1_c0_hist28_mask                 (0x0000FFFF)
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_29_28_ch1_c0_hist29(data)                (0xFFFF0000&((data)<<16))
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_29_28_ch1_c0_hist28(data)                (0x0000FFFF&(data))
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_29_28_get_ch1_c0_hist29(data)            ((0xFFFF0000&(data))>>16)
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_29_28_get_ch1_c0_hist28(data)            (0x0000FFFF&(data))

#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_31_30                                    0x1802326C
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_31_30_reg_addr                           "0xB802326C"
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_31_30_reg                                0xB802326C
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_31_30_inst_addr                          "0x001B"
#define  set_HISTOGRAM_ICH1_C0_Hist_IN_Data_31_30_reg(data)                      (*((volatile unsigned int*)HISTOGRAM_ICH1_C0_Hist_IN_Data_31_30_reg)=data)
#define  get_HISTOGRAM_ICH1_C0_Hist_IN_Data_31_30_reg                            (*((volatile unsigned int*)HISTOGRAM_ICH1_C0_Hist_IN_Data_31_30_reg))
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_31_30_ch1_c0_hist31_shift                (16)
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_31_30_ch1_c0_hist30_shift                (0)
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_31_30_ch1_c0_hist31_mask                 (0xFFFF0000)
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_31_30_ch1_c0_hist30_mask                 (0x0000FFFF)
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_31_30_ch1_c0_hist31(data)                (0xFFFF0000&((data)<<16))
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_31_30_ch1_c0_hist30(data)                (0x0000FFFF&(data))
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_31_30_get_ch1_c0_hist31(data)            ((0xFFFF0000&(data))>>16)
#define  HISTOGRAM_ICH1_C0_Hist_IN_Data_31_30_get_ch1_c0_hist30(data)            (0x0000FFFF&(data))

#define  HISTOGRAM_ICH1_C0_SectionHist_IN_CSELECT                                0x18023270
#define  HISTOGRAM_ICH1_C0_SectionHist_IN_CSELECT_reg_addr                       "0xB8023270"
#define  HISTOGRAM_ICH1_C0_SectionHist_IN_CSELECT_reg                            0xB8023270
#define  HISTOGRAM_ICH1_C0_SectionHist_IN_CSELECT_inst_addr                      "0x001C"
#define  set_HISTOGRAM_ICH1_C0_SectionHist_IN_CSELECT_reg(data)                  (*((volatile unsigned int*)HISTOGRAM_ICH1_C0_SectionHist_IN_CSELECT_reg)=data)
#define  get_HISTOGRAM_ICH1_C0_SectionHist_IN_CSELECT_reg                        (*((volatile unsigned int*)HISTOGRAM_ICH1_C0_SectionHist_IN_CSELECT_reg))
#define  HISTOGRAM_ICH1_C0_SectionHist_IN_CSELECT_ch1_c0_section1_bin_sel_shift  (16)
#define  HISTOGRAM_ICH1_C0_SectionHist_IN_CSELECT_ch1_c0_section0_bin_sel_shift  (0)
#define  HISTOGRAM_ICH1_C0_SectionHist_IN_CSELECT_ch1_c0_section1_bin_sel_mask   (0x007F0000)
#define  HISTOGRAM_ICH1_C0_SectionHist_IN_CSELECT_ch1_c0_section0_bin_sel_mask   (0x0000007F)
#define  HISTOGRAM_ICH1_C0_SectionHist_IN_CSELECT_ch1_c0_section1_bin_sel(data)  (0x007F0000&((data)<<16))
#define  HISTOGRAM_ICH1_C0_SectionHist_IN_CSELECT_ch1_c0_section0_bin_sel(data)  (0x0000007F&(data))
#define  HISTOGRAM_ICH1_C0_SectionHist_IN_CSELECT_get_ch1_c0_section1_bin_sel(data) ((0x007F0000&(data))>>16)
#define  HISTOGRAM_ICH1_C0_SectionHist_IN_CSELECT_get_ch1_c0_section0_bin_sel(data) (0x0000007F&(data))

#define  HISTOGRAM_ICH1_C0_Section0_Data_01_00                                   0x18023274
#define  HISTOGRAM_ICH1_C0_Section0_Data_01_00_reg_addr                          "0xB8023274"
#define  HISTOGRAM_ICH1_C0_Section0_Data_01_00_reg                               0xB8023274
#define  HISTOGRAM_ICH1_C0_Section0_Data_01_00_inst_addr                         "0x001D"
#define  set_HISTOGRAM_ICH1_C0_Section0_Data_01_00_reg(data)                     (*((volatile unsigned int*)HISTOGRAM_ICH1_C0_Section0_Data_01_00_reg)=data)
#define  get_HISTOGRAM_ICH1_C0_Section0_Data_01_00_reg                           (*((volatile unsigned int*)HISTOGRAM_ICH1_C0_Section0_Data_01_00_reg))
#define  HISTOGRAM_ICH1_C0_Section0_Data_01_00_ch1_c0_section_his0_hist01_shift  (16)
#define  HISTOGRAM_ICH1_C0_Section0_Data_01_00_ch1_c0_section_his0_hist00_shift  (0)
#define  HISTOGRAM_ICH1_C0_Section0_Data_01_00_ch1_c0_section_his0_hist01_mask   (0xFFFF0000)
#define  HISTOGRAM_ICH1_C0_Section0_Data_01_00_ch1_c0_section_his0_hist00_mask   (0x0000FFFF)
#define  HISTOGRAM_ICH1_C0_Section0_Data_01_00_ch1_c0_section_his0_hist01(data)  (0xFFFF0000&((data)<<16))
#define  HISTOGRAM_ICH1_C0_Section0_Data_01_00_ch1_c0_section_his0_hist00(data)  (0x0000FFFF&(data))
#define  HISTOGRAM_ICH1_C0_Section0_Data_01_00_get_ch1_c0_section_his0_hist01(data) ((0xFFFF0000&(data))>>16)
#define  HISTOGRAM_ICH1_C0_Section0_Data_01_00_get_ch1_c0_section_his0_hist00(data) (0x0000FFFF&(data))

#define  HISTOGRAM_ICH1_C0_Section0_Data_03_02                                   0x18023278
#define  HISTOGRAM_ICH1_C0_Section0_Data_03_02_reg_addr                          "0xB8023278"
#define  HISTOGRAM_ICH1_C0_Section0_Data_03_02_reg                               0xB8023278
#define  HISTOGRAM_ICH1_C0_Section0_Data_03_02_inst_addr                         "0x001E"
#define  set_HISTOGRAM_ICH1_C0_Section0_Data_03_02_reg(data)                     (*((volatile unsigned int*)HISTOGRAM_ICH1_C0_Section0_Data_03_02_reg)=data)
#define  get_HISTOGRAM_ICH1_C0_Section0_Data_03_02_reg                           (*((volatile unsigned int*)HISTOGRAM_ICH1_C0_Section0_Data_03_02_reg))
#define  HISTOGRAM_ICH1_C0_Section0_Data_03_02_ch1_c0_section_his0_hist03_shift  (16)
#define  HISTOGRAM_ICH1_C0_Section0_Data_03_02_ch1_c0_section_his0_hist02_shift  (0)
#define  HISTOGRAM_ICH1_C0_Section0_Data_03_02_ch1_c0_section_his0_hist03_mask   (0xFFFF0000)
#define  HISTOGRAM_ICH1_C0_Section0_Data_03_02_ch1_c0_section_his0_hist02_mask   (0x0000FFFF)
#define  HISTOGRAM_ICH1_C0_Section0_Data_03_02_ch1_c0_section_his0_hist03(data)  (0xFFFF0000&((data)<<16))
#define  HISTOGRAM_ICH1_C0_Section0_Data_03_02_ch1_c0_section_his0_hist02(data)  (0x0000FFFF&(data))
#define  HISTOGRAM_ICH1_C0_Section0_Data_03_02_get_ch1_c0_section_his0_hist03(data) ((0xFFFF0000&(data))>>16)
#define  HISTOGRAM_ICH1_C0_Section0_Data_03_02_get_ch1_c0_section_his0_hist02(data) (0x0000FFFF&(data))

#define  HISTOGRAM_ICH1_C0_Section0_Data_05_04                                   0x1802327C
#define  HISTOGRAM_ICH1_C0_Section0_Data_05_04_reg_addr                          "0xB802327C"
#define  HISTOGRAM_ICH1_C0_Section0_Data_05_04_reg                               0xB802327C
#define  HISTOGRAM_ICH1_C0_Section0_Data_05_04_inst_addr                         "0x001F"
#define  set_HISTOGRAM_ICH1_C0_Section0_Data_05_04_reg(data)                     (*((volatile unsigned int*)HISTOGRAM_ICH1_C0_Section0_Data_05_04_reg)=data)
#define  get_HISTOGRAM_ICH1_C0_Section0_Data_05_04_reg                           (*((volatile unsigned int*)HISTOGRAM_ICH1_C0_Section0_Data_05_04_reg))
#define  HISTOGRAM_ICH1_C0_Section0_Data_05_04_ch1_c0_section_his0_hist05_shift  (16)
#define  HISTOGRAM_ICH1_C0_Section0_Data_05_04_ch1_c0_section_his0_hist04_shift  (0)
#define  HISTOGRAM_ICH1_C0_Section0_Data_05_04_ch1_c0_section_his0_hist05_mask   (0xFFFF0000)
#define  HISTOGRAM_ICH1_C0_Section0_Data_05_04_ch1_c0_section_his0_hist04_mask   (0x0000FFFF)
#define  HISTOGRAM_ICH1_C0_Section0_Data_05_04_ch1_c0_section_his0_hist05(data)  (0xFFFF0000&((data)<<16))
#define  HISTOGRAM_ICH1_C0_Section0_Data_05_04_ch1_c0_section_his0_hist04(data)  (0x0000FFFF&(data))
#define  HISTOGRAM_ICH1_C0_Section0_Data_05_04_get_ch1_c0_section_his0_hist05(data) ((0xFFFF0000&(data))>>16)
#define  HISTOGRAM_ICH1_C0_Section0_Data_05_04_get_ch1_c0_section_his0_hist04(data) (0x0000FFFF&(data))

#define  HISTOGRAM_ICH1_C0_Section0_Data_07_06                                   0x18023280
#define  HISTOGRAM_ICH1_C0_Section0_Data_07_06_reg_addr                          "0xB8023280"
#define  HISTOGRAM_ICH1_C0_Section0_Data_07_06_reg                               0xB8023280
#define  HISTOGRAM_ICH1_C0_Section0_Data_07_06_inst_addr                         "0x0020"
#define  set_HISTOGRAM_ICH1_C0_Section0_Data_07_06_reg(data)                     (*((volatile unsigned int*)HISTOGRAM_ICH1_C0_Section0_Data_07_06_reg)=data)
#define  get_HISTOGRAM_ICH1_C0_Section0_Data_07_06_reg                           (*((volatile unsigned int*)HISTOGRAM_ICH1_C0_Section0_Data_07_06_reg))
#define  HISTOGRAM_ICH1_C0_Section0_Data_07_06_ch1_c0_section_his0_hist07_shift  (16)
#define  HISTOGRAM_ICH1_C0_Section0_Data_07_06_ch1_c0_section_his0_hist06_shift  (0)
#define  HISTOGRAM_ICH1_C0_Section0_Data_07_06_ch1_c0_section_his0_hist07_mask   (0xFFFF0000)
#define  HISTOGRAM_ICH1_C0_Section0_Data_07_06_ch1_c0_section_his0_hist06_mask   (0x0000FFFF)
#define  HISTOGRAM_ICH1_C0_Section0_Data_07_06_ch1_c0_section_his0_hist07(data)  (0xFFFF0000&((data)<<16))
#define  HISTOGRAM_ICH1_C0_Section0_Data_07_06_ch1_c0_section_his0_hist06(data)  (0x0000FFFF&(data))
#define  HISTOGRAM_ICH1_C0_Section0_Data_07_06_get_ch1_c0_section_his0_hist07(data) ((0xFFFF0000&(data))>>16)
#define  HISTOGRAM_ICH1_C0_Section0_Data_07_06_get_ch1_c0_section_his0_hist06(data) (0x0000FFFF&(data))

#define  HISTOGRAM_ICH1_C0_Section1_Data_01_00                                   0x18023284
#define  HISTOGRAM_ICH1_C0_Section1_Data_01_00_reg_addr                          "0xB8023284"
#define  HISTOGRAM_ICH1_C0_Section1_Data_01_00_reg                               0xB8023284
#define  HISTOGRAM_ICH1_C0_Section1_Data_01_00_inst_addr                         "0x0021"
#define  set_HISTOGRAM_ICH1_C0_Section1_Data_01_00_reg(data)                     (*((volatile unsigned int*)HISTOGRAM_ICH1_C0_Section1_Data_01_00_reg)=data)
#define  get_HISTOGRAM_ICH1_C0_Section1_Data_01_00_reg                           (*((volatile unsigned int*)HISTOGRAM_ICH1_C0_Section1_Data_01_00_reg))
#define  HISTOGRAM_ICH1_C0_Section1_Data_01_00_ch1_c0_section_his1_hist01_shift  (16)
#define  HISTOGRAM_ICH1_C0_Section1_Data_01_00_ch1_c0_section_his1_hist00_shift  (0)
#define  HISTOGRAM_ICH1_C0_Section1_Data_01_00_ch1_c0_section_his1_hist01_mask   (0xFFFF0000)
#define  HISTOGRAM_ICH1_C0_Section1_Data_01_00_ch1_c0_section_his1_hist00_mask   (0x0000FFFF)
#define  HISTOGRAM_ICH1_C0_Section1_Data_01_00_ch1_c0_section_his1_hist01(data)  (0xFFFF0000&((data)<<16))
#define  HISTOGRAM_ICH1_C0_Section1_Data_01_00_ch1_c0_section_his1_hist00(data)  (0x0000FFFF&(data))
#define  HISTOGRAM_ICH1_C0_Section1_Data_01_00_get_ch1_c0_section_his1_hist01(data) ((0xFFFF0000&(data))>>16)
#define  HISTOGRAM_ICH1_C0_Section1_Data_01_00_get_ch1_c0_section_his1_hist00(data) (0x0000FFFF&(data))

#define  HISTOGRAM_ICH1_C0_Section1_Data_03_02                                   0x18023288
#define  HISTOGRAM_ICH1_C0_Section1_Data_03_02_reg_addr                          "0xB8023288"
#define  HISTOGRAM_ICH1_C0_Section1_Data_03_02_reg                               0xB8023288
#define  HISTOGRAM_ICH1_C0_Section1_Data_03_02_inst_addr                         "0x0022"
#define  set_HISTOGRAM_ICH1_C0_Section1_Data_03_02_reg(data)                     (*((volatile unsigned int*)HISTOGRAM_ICH1_C0_Section1_Data_03_02_reg)=data)
#define  get_HISTOGRAM_ICH1_C0_Section1_Data_03_02_reg                           (*((volatile unsigned int*)HISTOGRAM_ICH1_C0_Section1_Data_03_02_reg))
#define  HISTOGRAM_ICH1_C0_Section1_Data_03_02_ch1_c0_section_his1_hist03_shift  (16)
#define  HISTOGRAM_ICH1_C0_Section1_Data_03_02_ch1_c0_section_his1_hist02_shift  (0)
#define  HISTOGRAM_ICH1_C0_Section1_Data_03_02_ch1_c0_section_his1_hist03_mask   (0xFFFF0000)
#define  HISTOGRAM_ICH1_C0_Section1_Data_03_02_ch1_c0_section_his1_hist02_mask   (0x0000FFFF)
#define  HISTOGRAM_ICH1_C0_Section1_Data_03_02_ch1_c0_section_his1_hist03(data)  (0xFFFF0000&((data)<<16))
#define  HISTOGRAM_ICH1_C0_Section1_Data_03_02_ch1_c0_section_his1_hist02(data)  (0x0000FFFF&(data))
#define  HISTOGRAM_ICH1_C0_Section1_Data_03_02_get_ch1_c0_section_his1_hist03(data) ((0xFFFF0000&(data))>>16)
#define  HISTOGRAM_ICH1_C0_Section1_Data_03_02_get_ch1_c0_section_his1_hist02(data) (0x0000FFFF&(data))

#define  HISTOGRAM_ICH1_C0_Section1_Data_05_04                                   0x1802328C
#define  HISTOGRAM_ICH1_C0_Section1_Data_05_04_reg_addr                          "0xB802328C"
#define  HISTOGRAM_ICH1_C0_Section1_Data_05_04_reg                               0xB802328C
#define  HISTOGRAM_ICH1_C0_Section1_Data_05_04_inst_addr                         "0x0023"
#define  set_HISTOGRAM_ICH1_C0_Section1_Data_05_04_reg(data)                     (*((volatile unsigned int*)HISTOGRAM_ICH1_C0_Section1_Data_05_04_reg)=data)
#define  get_HISTOGRAM_ICH1_C0_Section1_Data_05_04_reg                           (*((volatile unsigned int*)HISTOGRAM_ICH1_C0_Section1_Data_05_04_reg))
#define  HISTOGRAM_ICH1_C0_Section1_Data_05_04_ch1_c0_section_his1_hist05_shift  (16)
#define  HISTOGRAM_ICH1_C0_Section1_Data_05_04_ch1_c0_section_his1_hist04_shift  (0)
#define  HISTOGRAM_ICH1_C0_Section1_Data_05_04_ch1_c0_section_his1_hist05_mask   (0xFFFF0000)
#define  HISTOGRAM_ICH1_C0_Section1_Data_05_04_ch1_c0_section_his1_hist04_mask   (0x0000FFFF)
#define  HISTOGRAM_ICH1_C0_Section1_Data_05_04_ch1_c0_section_his1_hist05(data)  (0xFFFF0000&((data)<<16))
#define  HISTOGRAM_ICH1_C0_Section1_Data_05_04_ch1_c0_section_his1_hist04(data)  (0x0000FFFF&(data))
#define  HISTOGRAM_ICH1_C0_Section1_Data_05_04_get_ch1_c0_section_his1_hist05(data) ((0xFFFF0000&(data))>>16)
#define  HISTOGRAM_ICH1_C0_Section1_Data_05_04_get_ch1_c0_section_his1_hist04(data) (0x0000FFFF&(data))

#define  HISTOGRAM_ICH1_C0_Section1_Data_07_06                                   0x18023290
#define  HISTOGRAM_ICH1_C0_Section1_Data_07_06_reg_addr                          "0xB8023290"
#define  HISTOGRAM_ICH1_C0_Section1_Data_07_06_reg                               0xB8023290
#define  HISTOGRAM_ICH1_C0_Section1_Data_07_06_inst_addr                         "0x0024"
#define  set_HISTOGRAM_ICH1_C0_Section1_Data_07_06_reg(data)                     (*((volatile unsigned int*)HISTOGRAM_ICH1_C0_Section1_Data_07_06_reg)=data)
#define  get_HISTOGRAM_ICH1_C0_Section1_Data_07_06_reg                           (*((volatile unsigned int*)HISTOGRAM_ICH1_C0_Section1_Data_07_06_reg))
#define  HISTOGRAM_ICH1_C0_Section1_Data_07_06_ch1_c0_section_his1_hist07_shift  (16)
#define  HISTOGRAM_ICH1_C0_Section1_Data_07_06_ch1_c0_section_his1_hist06_shift  (0)
#define  HISTOGRAM_ICH1_C0_Section1_Data_07_06_ch1_c0_section_his1_hist07_mask   (0xFFFF0000)
#define  HISTOGRAM_ICH1_C0_Section1_Data_07_06_ch1_c0_section_his1_hist06_mask   (0x0000FFFF)
#define  HISTOGRAM_ICH1_C0_Section1_Data_07_06_ch1_c0_section_his1_hist07(data)  (0xFFFF0000&((data)<<16))
#define  HISTOGRAM_ICH1_C0_Section1_Data_07_06_ch1_c0_section_his1_hist06(data)  (0x0000FFFF&(data))
#define  HISTOGRAM_ICH1_C0_Section1_Data_07_06_get_ch1_c0_section_his1_hist07(data) ((0xFFFF0000&(data))>>16)
#define  HISTOGRAM_ICH1_C0_Section1_Data_07_06_get_ch1_c0_section_his1_hist06(data) (0x0000FFFF&(data))

#define  HISTOGRAM_ICH1_C1_Hist_Bound                                            0x180232A0
#define  HISTOGRAM_ICH1_C1_Hist_Bound_reg_addr                                   "0xB80232A0"
#define  HISTOGRAM_ICH1_C1_Hist_Bound_reg                                        0xB80232A0
#define  HISTOGRAM_ICH1_C1_Hist_Bound_inst_addr                                  "0x0025"
#define  set_HISTOGRAM_ICH1_C1_Hist_Bound_reg(data)                              (*((volatile unsigned int*)HISTOGRAM_ICH1_C1_Hist_Bound_reg)=data)
#define  get_HISTOGRAM_ICH1_C1_Hist_Bound_reg                                    (*((volatile unsigned int*)HISTOGRAM_ICH1_C1_Hist_Bound_reg))
#define  HISTOGRAM_ICH1_C1_Hist_Bound_ch1_c1_upper_bound_shift                   (16)
#define  HISTOGRAM_ICH1_C1_Hist_Bound_ch1_c1_lower_bound_shift                   (0)
#define  HISTOGRAM_ICH1_C1_Hist_Bound_ch1_c1_upper_bound_mask                    (0x03FF0000)
#define  HISTOGRAM_ICH1_C1_Hist_Bound_ch1_c1_lower_bound_mask                    (0x000003FF)
#define  HISTOGRAM_ICH1_C1_Hist_Bound_ch1_c1_upper_bound(data)                   (0x03FF0000&((data)<<16))
#define  HISTOGRAM_ICH1_C1_Hist_Bound_ch1_c1_lower_bound(data)                   (0x000003FF&(data))
#define  HISTOGRAM_ICH1_C1_Hist_Bound_get_ch1_c1_upper_bound(data)               ((0x03FF0000&(data))>>16)
#define  HISTOGRAM_ICH1_C1_Hist_Bound_get_ch1_c1_lower_bound(data)               (0x000003FF&(data))

#define  HISTOGRAM_ICH1_C1_Hist_Bound_U                                          0x180232A4
#define  HISTOGRAM_ICH1_C1_Hist_Bound_U_reg_addr                                 "0xB80232A4"
#define  HISTOGRAM_ICH1_C1_Hist_Bound_U_reg                                      0xB80232A4
#define  HISTOGRAM_ICH1_C1_Hist_Bound_U_inst_addr                                "0x0026"
#define  set_HISTOGRAM_ICH1_C1_Hist_Bound_U_reg(data)                            (*((volatile unsigned int*)HISTOGRAM_ICH1_C1_Hist_Bound_U_reg)=data)
#define  get_HISTOGRAM_ICH1_C1_Hist_Bound_U_reg                                  (*((volatile unsigned int*)HISTOGRAM_ICH1_C1_Hist_Bound_U_reg))
#define  HISTOGRAM_ICH1_C1_Hist_Bound_U_ch1_c1_upper_bound_u_shift               (16)
#define  HISTOGRAM_ICH1_C1_Hist_Bound_U_ch1_c1_lower_bound_u_shift               (0)
#define  HISTOGRAM_ICH1_C1_Hist_Bound_U_ch1_c1_upper_bound_u_mask                (0x03FF0000)
#define  HISTOGRAM_ICH1_C1_Hist_Bound_U_ch1_c1_lower_bound_u_mask                (0x000003FF)
#define  HISTOGRAM_ICH1_C1_Hist_Bound_U_ch1_c1_upper_bound_u(data)               (0x03FF0000&((data)<<16))
#define  HISTOGRAM_ICH1_C1_Hist_Bound_U_ch1_c1_lower_bound_u(data)               (0x000003FF&(data))
#define  HISTOGRAM_ICH1_C1_Hist_Bound_U_get_ch1_c1_upper_bound_u(data)           ((0x03FF0000&(data))>>16)
#define  HISTOGRAM_ICH1_C1_Hist_Bound_U_get_ch1_c1_lower_bound_u(data)           (0x000003FF&(data))

#define  HISTOGRAM_ICH1_C1_Hist_Bound_V                                          0x180232A8
#define  HISTOGRAM_ICH1_C1_Hist_Bound_V_reg_addr                                 "0xB80232A8"
#define  HISTOGRAM_ICH1_C1_Hist_Bound_V_reg                                      0xB80232A8
#define  HISTOGRAM_ICH1_C1_Hist_Bound_V_inst_addr                                "0x0027"
#define  set_HISTOGRAM_ICH1_C1_Hist_Bound_V_reg(data)                            (*((volatile unsigned int*)HISTOGRAM_ICH1_C1_Hist_Bound_V_reg)=data)
#define  get_HISTOGRAM_ICH1_C1_Hist_Bound_V_reg                                  (*((volatile unsigned int*)HISTOGRAM_ICH1_C1_Hist_Bound_V_reg))
#define  HISTOGRAM_ICH1_C1_Hist_Bound_V_ch1_c1_upper_bound_v_shift               (16)
#define  HISTOGRAM_ICH1_C1_Hist_Bound_V_ch1_c1_lower_bound_v_shift               (0)
#define  HISTOGRAM_ICH1_C1_Hist_Bound_V_ch1_c1_upper_bound_v_mask                (0x03FF0000)
#define  HISTOGRAM_ICH1_C1_Hist_Bound_V_ch1_c1_lower_bound_v_mask                (0x000003FF)
#define  HISTOGRAM_ICH1_C1_Hist_Bound_V_ch1_c1_upper_bound_v(data)               (0x03FF0000&((data)<<16))
#define  HISTOGRAM_ICH1_C1_Hist_Bound_V_ch1_c1_lower_bound_v(data)               (0x000003FF&(data))
#define  HISTOGRAM_ICH1_C1_Hist_Bound_V_get_ch1_c1_upper_bound_v(data)           ((0x03FF0000&(data))>>16)
#define  HISTOGRAM_ICH1_C1_Hist_Bound_V_get_ch1_c1_lower_bound_v(data)           (0x000003FF&(data))

#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_01_00                                    0x180232B0
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_01_00_reg_addr                           "0xB80232B0"
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_01_00_reg                                0xB80232B0
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_01_00_inst_addr                          "0x0028"
#define  set_HISTOGRAM_ICH1_C1_Hist_IN_Data_01_00_reg(data)                      (*((volatile unsigned int*)HISTOGRAM_ICH1_C1_Hist_IN_Data_01_00_reg)=data)
#define  get_HISTOGRAM_ICH1_C1_Hist_IN_Data_01_00_reg                            (*((volatile unsigned int*)HISTOGRAM_ICH1_C1_Hist_IN_Data_01_00_reg))
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_01_00_ch1_c1_hist01_shift                (16)
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_01_00_ch1_c1_hist00_shift                (0)
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_01_00_ch1_c1_hist01_mask                 (0xFFFF0000)
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_01_00_ch1_c1_hist00_mask                 (0x0000FFFF)
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_01_00_ch1_c1_hist01(data)                (0xFFFF0000&((data)<<16))
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_01_00_ch1_c1_hist00(data)                (0x0000FFFF&(data))
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_01_00_get_ch1_c1_hist01(data)            ((0xFFFF0000&(data))>>16)
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_01_00_get_ch1_c1_hist00(data)            (0x0000FFFF&(data))

#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_03_02                                    0x180232B4
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_03_02_reg_addr                           "0xB80232B4"
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_03_02_reg                                0xB80232B4
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_03_02_inst_addr                          "0x0029"
#define  set_HISTOGRAM_ICH1_C1_Hist_IN_Data_03_02_reg(data)                      (*((volatile unsigned int*)HISTOGRAM_ICH1_C1_Hist_IN_Data_03_02_reg)=data)
#define  get_HISTOGRAM_ICH1_C1_Hist_IN_Data_03_02_reg                            (*((volatile unsigned int*)HISTOGRAM_ICH1_C1_Hist_IN_Data_03_02_reg))
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_03_02_ch1_c1_hist03_shift                (16)
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_03_02_ch1_c1_hist02_shift                (0)
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_03_02_ch1_c1_hist03_mask                 (0xFFFF0000)
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_03_02_ch1_c1_hist02_mask                 (0x0000FFFF)
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_03_02_ch1_c1_hist03(data)                (0xFFFF0000&((data)<<16))
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_03_02_ch1_c1_hist02(data)                (0x0000FFFF&(data))
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_03_02_get_ch1_c1_hist03(data)            ((0xFFFF0000&(data))>>16)
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_03_02_get_ch1_c1_hist02(data)            (0x0000FFFF&(data))

#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_05_04                                    0x180232B8
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_05_04_reg_addr                           "0xB80232B8"
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_05_04_reg                                0xB80232B8
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_05_04_inst_addr                          "0x002A"
#define  set_HISTOGRAM_ICH1_C1_Hist_IN_Data_05_04_reg(data)                      (*((volatile unsigned int*)HISTOGRAM_ICH1_C1_Hist_IN_Data_05_04_reg)=data)
#define  get_HISTOGRAM_ICH1_C1_Hist_IN_Data_05_04_reg                            (*((volatile unsigned int*)HISTOGRAM_ICH1_C1_Hist_IN_Data_05_04_reg))
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_05_04_ch1_c1_hist05_shift                (16)
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_05_04_ch1_c1_hist04_shift                (0)
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_05_04_ch1_c1_hist05_mask                 (0xFFFF0000)
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_05_04_ch1_c1_hist04_mask                 (0x0000FFFF)
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_05_04_ch1_c1_hist05(data)                (0xFFFF0000&((data)<<16))
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_05_04_ch1_c1_hist04(data)                (0x0000FFFF&(data))
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_05_04_get_ch1_c1_hist05(data)            ((0xFFFF0000&(data))>>16)
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_05_04_get_ch1_c1_hist04(data)            (0x0000FFFF&(data))

#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_07_06                                    0x180232BC
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_07_06_reg_addr                           "0xB80232BC"
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_07_06_reg                                0xB80232BC
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_07_06_inst_addr                          "0x002B"
#define  set_HISTOGRAM_ICH1_C1_Hist_IN_Data_07_06_reg(data)                      (*((volatile unsigned int*)HISTOGRAM_ICH1_C1_Hist_IN_Data_07_06_reg)=data)
#define  get_HISTOGRAM_ICH1_C1_Hist_IN_Data_07_06_reg                            (*((volatile unsigned int*)HISTOGRAM_ICH1_C1_Hist_IN_Data_07_06_reg))
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_07_06_ch1_c1_hist07_shift                (16)
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_07_06_ch1_c1_hist06_shift                (0)
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_07_06_ch1_c1_hist07_mask                 (0xFFFF0000)
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_07_06_ch1_c1_hist06_mask                 (0x0000FFFF)
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_07_06_ch1_c1_hist07(data)                (0xFFFF0000&((data)<<16))
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_07_06_ch1_c1_hist06(data)                (0x0000FFFF&(data))
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_07_06_get_ch1_c1_hist07(data)            ((0xFFFF0000&(data))>>16)
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_07_06_get_ch1_c1_hist06(data)            (0x0000FFFF&(data))

#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_09_08                                    0x180232C0
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_09_08_reg_addr                           "0xB80232C0"
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_09_08_reg                                0xB80232C0
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_09_08_inst_addr                          "0x002C"
#define  set_HISTOGRAM_ICH1_C1_Hist_IN_Data_09_08_reg(data)                      (*((volatile unsigned int*)HISTOGRAM_ICH1_C1_Hist_IN_Data_09_08_reg)=data)
#define  get_HISTOGRAM_ICH1_C1_Hist_IN_Data_09_08_reg                            (*((volatile unsigned int*)HISTOGRAM_ICH1_C1_Hist_IN_Data_09_08_reg))
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_09_08_ch1_c1_hist09_shift                (16)
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_09_08_ch1_c1_hist08_shift                (0)
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_09_08_ch1_c1_hist09_mask                 (0xFFFF0000)
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_09_08_ch1_c1_hist08_mask                 (0x0000FFFF)
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_09_08_ch1_c1_hist09(data)                (0xFFFF0000&((data)<<16))
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_09_08_ch1_c1_hist08(data)                (0x0000FFFF&(data))
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_09_08_get_ch1_c1_hist09(data)            ((0xFFFF0000&(data))>>16)
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_09_08_get_ch1_c1_hist08(data)            (0x0000FFFF&(data))

#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_11_10                                    0x180232C4
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_11_10_reg_addr                           "0xB80232C4"
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_11_10_reg                                0xB80232C4
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_11_10_inst_addr                          "0x002D"
#define  set_HISTOGRAM_ICH1_C1_Hist_IN_Data_11_10_reg(data)                      (*((volatile unsigned int*)HISTOGRAM_ICH1_C1_Hist_IN_Data_11_10_reg)=data)
#define  get_HISTOGRAM_ICH1_C1_Hist_IN_Data_11_10_reg                            (*((volatile unsigned int*)HISTOGRAM_ICH1_C1_Hist_IN_Data_11_10_reg))
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_11_10_ch1_c1_hist11_shift                (16)
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_11_10_ch1_c1_hist10_shift                (0)
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_11_10_ch1_c1_hist11_mask                 (0xFFFF0000)
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_11_10_ch1_c1_hist10_mask                 (0x0000FFFF)
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_11_10_ch1_c1_hist11(data)                (0xFFFF0000&((data)<<16))
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_11_10_ch1_c1_hist10(data)                (0x0000FFFF&(data))
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_11_10_get_ch1_c1_hist11(data)            ((0xFFFF0000&(data))>>16)
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_11_10_get_ch1_c1_hist10(data)            (0x0000FFFF&(data))

#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_13_12                                    0x180232C8
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_13_12_reg_addr                           "0xB80232C8"
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_13_12_reg                                0xB80232C8
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_13_12_inst_addr                          "0x002E"
#define  set_HISTOGRAM_ICH1_C1_Hist_IN_Data_13_12_reg(data)                      (*((volatile unsigned int*)HISTOGRAM_ICH1_C1_Hist_IN_Data_13_12_reg)=data)
#define  get_HISTOGRAM_ICH1_C1_Hist_IN_Data_13_12_reg                            (*((volatile unsigned int*)HISTOGRAM_ICH1_C1_Hist_IN_Data_13_12_reg))
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_13_12_ch1_c1_hist13_shift                (16)
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_13_12_ch1_c1_hist12_shift                (0)
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_13_12_ch1_c1_hist13_mask                 (0xFFFF0000)
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_13_12_ch1_c1_hist12_mask                 (0x0000FFFF)
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_13_12_ch1_c1_hist13(data)                (0xFFFF0000&((data)<<16))
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_13_12_ch1_c1_hist12(data)                (0x0000FFFF&(data))
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_13_12_get_ch1_c1_hist13(data)            ((0xFFFF0000&(data))>>16)
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_13_12_get_ch1_c1_hist12(data)            (0x0000FFFF&(data))

#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_15_14                                    0x180232CC
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_15_14_reg_addr                           "0xB80232CC"
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_15_14_reg                                0xB80232CC
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_15_14_inst_addr                          "0x002F"
#define  set_HISTOGRAM_ICH1_C1_Hist_IN_Data_15_14_reg(data)                      (*((volatile unsigned int*)HISTOGRAM_ICH1_C1_Hist_IN_Data_15_14_reg)=data)
#define  get_HISTOGRAM_ICH1_C1_Hist_IN_Data_15_14_reg                            (*((volatile unsigned int*)HISTOGRAM_ICH1_C1_Hist_IN_Data_15_14_reg))
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_15_14_ch1_c1_hist15_shift                (16)
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_15_14_ch1_c1_hist14_shift                (0)
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_15_14_ch1_c1_hist15_mask                 (0xFFFF0000)
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_15_14_ch1_c1_hist14_mask                 (0x0000FFFF)
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_15_14_ch1_c1_hist15(data)                (0xFFFF0000&((data)<<16))
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_15_14_ch1_c1_hist14(data)                (0x0000FFFF&(data))
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_15_14_get_ch1_c1_hist15(data)            ((0xFFFF0000&(data))>>16)
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_15_14_get_ch1_c1_hist14(data)            (0x0000FFFF&(data))

#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_17_16                                    0x180232D0
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_17_16_reg_addr                           "0xB80232D0"
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_17_16_reg                                0xB80232D0
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_17_16_inst_addr                          "0x0030"
#define  set_HISTOGRAM_ICH1_C1_Hist_IN_Data_17_16_reg(data)                      (*((volatile unsigned int*)HISTOGRAM_ICH1_C1_Hist_IN_Data_17_16_reg)=data)
#define  get_HISTOGRAM_ICH1_C1_Hist_IN_Data_17_16_reg                            (*((volatile unsigned int*)HISTOGRAM_ICH1_C1_Hist_IN_Data_17_16_reg))
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_17_16_ch1_c1_hist17_shift                (16)
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_17_16_ch1_c1_hist16_shift                (0)
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_17_16_ch1_c1_hist17_mask                 (0xFFFF0000)
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_17_16_ch1_c1_hist16_mask                 (0x0000FFFF)
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_17_16_ch1_c1_hist17(data)                (0xFFFF0000&((data)<<16))
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_17_16_ch1_c1_hist16(data)                (0x0000FFFF&(data))
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_17_16_get_ch1_c1_hist17(data)            ((0xFFFF0000&(data))>>16)
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_17_16_get_ch1_c1_hist16(data)            (0x0000FFFF&(data))

#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_19_18                                    0x180232D4
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_19_18_reg_addr                           "0xB80232D4"
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_19_18_reg                                0xB80232D4
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_19_18_inst_addr                          "0x0031"
#define  set_HISTOGRAM_ICH1_C1_Hist_IN_Data_19_18_reg(data)                      (*((volatile unsigned int*)HISTOGRAM_ICH1_C1_Hist_IN_Data_19_18_reg)=data)
#define  get_HISTOGRAM_ICH1_C1_Hist_IN_Data_19_18_reg                            (*((volatile unsigned int*)HISTOGRAM_ICH1_C1_Hist_IN_Data_19_18_reg))
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_19_18_ch1_c1_hist19_shift                (16)
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_19_18_ch1_c1_hist18_shift                (0)
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_19_18_ch1_c1_hist19_mask                 (0xFFFF0000)
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_19_18_ch1_c1_hist18_mask                 (0x0000FFFF)
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_19_18_ch1_c1_hist19(data)                (0xFFFF0000&((data)<<16))
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_19_18_ch1_c1_hist18(data)                (0x0000FFFF&(data))
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_19_18_get_ch1_c1_hist19(data)            ((0xFFFF0000&(data))>>16)
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_19_18_get_ch1_c1_hist18(data)            (0x0000FFFF&(data))

#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_21_20                                    0x180232D8
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_21_20_reg_addr                           "0xB80232D8"
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_21_20_reg                                0xB80232D8
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_21_20_inst_addr                          "0x0032"
#define  set_HISTOGRAM_ICH1_C1_Hist_IN_Data_21_20_reg(data)                      (*((volatile unsigned int*)HISTOGRAM_ICH1_C1_Hist_IN_Data_21_20_reg)=data)
#define  get_HISTOGRAM_ICH1_C1_Hist_IN_Data_21_20_reg                            (*((volatile unsigned int*)HISTOGRAM_ICH1_C1_Hist_IN_Data_21_20_reg))
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_21_20_ch1_c1_hist21_shift                (16)
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_21_20_ch1_c1_hist20_shift                (0)
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_21_20_ch1_c1_hist21_mask                 (0xFFFF0000)
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_21_20_ch1_c1_hist20_mask                 (0x0000FFFF)
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_21_20_ch1_c1_hist21(data)                (0xFFFF0000&((data)<<16))
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_21_20_ch1_c1_hist20(data)                (0x0000FFFF&(data))
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_21_20_get_ch1_c1_hist21(data)            ((0xFFFF0000&(data))>>16)
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_21_20_get_ch1_c1_hist20(data)            (0x0000FFFF&(data))

#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_23_22                                    0x180232DC
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_23_22_reg_addr                           "0xB80232DC"
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_23_22_reg                                0xB80232DC
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_23_22_inst_addr                          "0x0033"
#define  set_HISTOGRAM_ICH1_C1_Hist_IN_Data_23_22_reg(data)                      (*((volatile unsigned int*)HISTOGRAM_ICH1_C1_Hist_IN_Data_23_22_reg)=data)
#define  get_HISTOGRAM_ICH1_C1_Hist_IN_Data_23_22_reg                            (*((volatile unsigned int*)HISTOGRAM_ICH1_C1_Hist_IN_Data_23_22_reg))
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_23_22_ch1_c1_hist23_shift                (16)
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_23_22_ch1_c1_hist22_shift                (0)
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_23_22_ch1_c1_hist23_mask                 (0xFFFF0000)
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_23_22_ch1_c1_hist22_mask                 (0x0000FFFF)
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_23_22_ch1_c1_hist23(data)                (0xFFFF0000&((data)<<16))
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_23_22_ch1_c1_hist22(data)                (0x0000FFFF&(data))
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_23_22_get_ch1_c1_hist23(data)            ((0xFFFF0000&(data))>>16)
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_23_22_get_ch1_c1_hist22(data)            (0x0000FFFF&(data))

#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_25_24                                    0x180232E0
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_25_24_reg_addr                           "0xB80232E0"
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_25_24_reg                                0xB80232E0
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_25_24_inst_addr                          "0x0034"
#define  set_HISTOGRAM_ICH1_C1_Hist_IN_Data_25_24_reg(data)                      (*((volatile unsigned int*)HISTOGRAM_ICH1_C1_Hist_IN_Data_25_24_reg)=data)
#define  get_HISTOGRAM_ICH1_C1_Hist_IN_Data_25_24_reg                            (*((volatile unsigned int*)HISTOGRAM_ICH1_C1_Hist_IN_Data_25_24_reg))
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_25_24_ch1_c1_hist25_shift                (16)
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_25_24_ch1_c1_hist24_shift                (0)
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_25_24_ch1_c1_hist25_mask                 (0xFFFF0000)
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_25_24_ch1_c1_hist24_mask                 (0x0000FFFF)
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_25_24_ch1_c1_hist25(data)                (0xFFFF0000&((data)<<16))
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_25_24_ch1_c1_hist24(data)                (0x0000FFFF&(data))
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_25_24_get_ch1_c1_hist25(data)            ((0xFFFF0000&(data))>>16)
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_25_24_get_ch1_c1_hist24(data)            (0x0000FFFF&(data))

#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_27_26                                    0x180232E4
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_27_26_reg_addr                           "0xB80232E4"
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_27_26_reg                                0xB80232E4
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_27_26_inst_addr                          "0x0035"
#define  set_HISTOGRAM_ICH1_C1_Hist_IN_Data_27_26_reg(data)                      (*((volatile unsigned int*)HISTOGRAM_ICH1_C1_Hist_IN_Data_27_26_reg)=data)
#define  get_HISTOGRAM_ICH1_C1_Hist_IN_Data_27_26_reg                            (*((volatile unsigned int*)HISTOGRAM_ICH1_C1_Hist_IN_Data_27_26_reg))
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_27_26_ch1_c1_hist27_shift                (16)
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_27_26_ch1_c1_hist26_shift                (0)
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_27_26_ch1_c1_hist27_mask                 (0xFFFF0000)
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_27_26_ch1_c1_hist26_mask                 (0x0000FFFF)
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_27_26_ch1_c1_hist27(data)                (0xFFFF0000&((data)<<16))
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_27_26_ch1_c1_hist26(data)                (0x0000FFFF&(data))
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_27_26_get_ch1_c1_hist27(data)            ((0xFFFF0000&(data))>>16)
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_27_26_get_ch1_c1_hist26(data)            (0x0000FFFF&(data))

#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_29_28                                    0x180232E8
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_29_28_reg_addr                           "0xB80232E8"
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_29_28_reg                                0xB80232E8
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_29_28_inst_addr                          "0x0036"
#define  set_HISTOGRAM_ICH1_C1_Hist_IN_Data_29_28_reg(data)                      (*((volatile unsigned int*)HISTOGRAM_ICH1_C1_Hist_IN_Data_29_28_reg)=data)
#define  get_HISTOGRAM_ICH1_C1_Hist_IN_Data_29_28_reg                            (*((volatile unsigned int*)HISTOGRAM_ICH1_C1_Hist_IN_Data_29_28_reg))
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_29_28_ch1_c1_hist29_shift                (16)
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_29_28_ch1_c1_hist28_shift                (0)
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_29_28_ch1_c1_hist29_mask                 (0xFFFF0000)
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_29_28_ch1_c1_hist28_mask                 (0x0000FFFF)
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_29_28_ch1_c1_hist29(data)                (0xFFFF0000&((data)<<16))
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_29_28_ch1_c1_hist28(data)                (0x0000FFFF&(data))
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_29_28_get_ch1_c1_hist29(data)            ((0xFFFF0000&(data))>>16)
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_29_28_get_ch1_c1_hist28(data)            (0x0000FFFF&(data))

#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_31_30                                    0x180232EC
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_31_30_reg_addr                           "0xB80232EC"
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_31_30_reg                                0xB80232EC
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_31_30_inst_addr                          "0x0037"
#define  set_HISTOGRAM_ICH1_C1_Hist_IN_Data_31_30_reg(data)                      (*((volatile unsigned int*)HISTOGRAM_ICH1_C1_Hist_IN_Data_31_30_reg)=data)
#define  get_HISTOGRAM_ICH1_C1_Hist_IN_Data_31_30_reg                            (*((volatile unsigned int*)HISTOGRAM_ICH1_C1_Hist_IN_Data_31_30_reg))
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_31_30_ch1_c1_hist31_shift                (16)
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_31_30_ch1_c1_hist30_shift                (0)
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_31_30_ch1_c1_hist31_mask                 (0xFFFF0000)
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_31_30_ch1_c1_hist30_mask                 (0x0000FFFF)
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_31_30_ch1_c1_hist31(data)                (0xFFFF0000&((data)<<16))
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_31_30_ch1_c1_hist30(data)                (0x0000FFFF&(data))
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_31_30_get_ch1_c1_hist31(data)            ((0xFFFF0000&(data))>>16)
#define  HISTOGRAM_ICH1_C1_Hist_IN_Data_31_30_get_ch1_c1_hist30(data)            (0x0000FFFF&(data))

#define  HISTOGRAM_ICH1_C1_SectionHist_IN_CSELECT                                0x180232F0
#define  HISTOGRAM_ICH1_C1_SectionHist_IN_CSELECT_reg_addr                       "0xB80232F0"
#define  HISTOGRAM_ICH1_C1_SectionHist_IN_CSELECT_reg                            0xB80232F0
#define  HISTOGRAM_ICH1_C1_SectionHist_IN_CSELECT_inst_addr                      "0x0038"
#define  set_HISTOGRAM_ICH1_C1_SectionHist_IN_CSELECT_reg(data)                  (*((volatile unsigned int*)HISTOGRAM_ICH1_C1_SectionHist_IN_CSELECT_reg)=data)
#define  get_HISTOGRAM_ICH1_C1_SectionHist_IN_CSELECT_reg                        (*((volatile unsigned int*)HISTOGRAM_ICH1_C1_SectionHist_IN_CSELECT_reg))
#define  HISTOGRAM_ICH1_C1_SectionHist_IN_CSELECT_ch1_c1_section1_bin_sel_shift  (16)
#define  HISTOGRAM_ICH1_C1_SectionHist_IN_CSELECT_ch1_c1_section0_bin_sel_shift  (0)
#define  HISTOGRAM_ICH1_C1_SectionHist_IN_CSELECT_ch1_c1_section1_bin_sel_mask   (0x007F0000)
#define  HISTOGRAM_ICH1_C1_SectionHist_IN_CSELECT_ch1_c1_section0_bin_sel_mask   (0x0000007F)
#define  HISTOGRAM_ICH1_C1_SectionHist_IN_CSELECT_ch1_c1_section1_bin_sel(data)  (0x007F0000&((data)<<16))
#define  HISTOGRAM_ICH1_C1_SectionHist_IN_CSELECT_ch1_c1_section0_bin_sel(data)  (0x0000007F&(data))
#define  HISTOGRAM_ICH1_C1_SectionHist_IN_CSELECT_get_ch1_c1_section1_bin_sel(data) ((0x007F0000&(data))>>16)
#define  HISTOGRAM_ICH1_C1_SectionHist_IN_CSELECT_get_ch1_c1_section0_bin_sel(data) (0x0000007F&(data))

#define  HISTOGRAM_ICH1_C1_Section0_Data_01_00                                   0x180232F4
#define  HISTOGRAM_ICH1_C1_Section0_Data_01_00_reg_addr                          "0xB80232F4"
#define  HISTOGRAM_ICH1_C1_Section0_Data_01_00_reg                               0xB80232F4
#define  HISTOGRAM_ICH1_C1_Section0_Data_01_00_inst_addr                         "0x0039"
#define  set_HISTOGRAM_ICH1_C1_Section0_Data_01_00_reg(data)                     (*((volatile unsigned int*)HISTOGRAM_ICH1_C1_Section0_Data_01_00_reg)=data)
#define  get_HISTOGRAM_ICH1_C1_Section0_Data_01_00_reg                           (*((volatile unsigned int*)HISTOGRAM_ICH1_C1_Section0_Data_01_00_reg))
#define  HISTOGRAM_ICH1_C1_Section0_Data_01_00_ch1_c1_section_his0_hist01_shift  (16)
#define  HISTOGRAM_ICH1_C1_Section0_Data_01_00_ch1_c1_section_his0_hist00_shift  (0)
#define  HISTOGRAM_ICH1_C1_Section0_Data_01_00_ch1_c1_section_his0_hist01_mask   (0xFFFF0000)
#define  HISTOGRAM_ICH1_C1_Section0_Data_01_00_ch1_c1_section_his0_hist00_mask   (0x0000FFFF)
#define  HISTOGRAM_ICH1_C1_Section0_Data_01_00_ch1_c1_section_his0_hist01(data)  (0xFFFF0000&((data)<<16))
#define  HISTOGRAM_ICH1_C1_Section0_Data_01_00_ch1_c1_section_his0_hist00(data)  (0x0000FFFF&(data))
#define  HISTOGRAM_ICH1_C1_Section0_Data_01_00_get_ch1_c1_section_his0_hist01(data) ((0xFFFF0000&(data))>>16)
#define  HISTOGRAM_ICH1_C1_Section0_Data_01_00_get_ch1_c1_section_his0_hist00(data) (0x0000FFFF&(data))

#define  HISTOGRAM_ICH1_C1_Section0_Data_03_02                                   0x180232F8
#define  HISTOGRAM_ICH1_C1_Section0_Data_03_02_reg_addr                          "0xB80232F8"
#define  HISTOGRAM_ICH1_C1_Section0_Data_03_02_reg                               0xB80232F8
#define  HISTOGRAM_ICH1_C1_Section0_Data_03_02_inst_addr                         "0x003A"
#define  set_HISTOGRAM_ICH1_C1_Section0_Data_03_02_reg(data)                     (*((volatile unsigned int*)HISTOGRAM_ICH1_C1_Section0_Data_03_02_reg)=data)
#define  get_HISTOGRAM_ICH1_C1_Section0_Data_03_02_reg                           (*((volatile unsigned int*)HISTOGRAM_ICH1_C1_Section0_Data_03_02_reg))
#define  HISTOGRAM_ICH1_C1_Section0_Data_03_02_ch1_c1_section_his0_hist03_shift  (16)
#define  HISTOGRAM_ICH1_C1_Section0_Data_03_02_ch1_c1_section_his0_hist02_shift  (0)
#define  HISTOGRAM_ICH1_C1_Section0_Data_03_02_ch1_c1_section_his0_hist03_mask   (0xFFFF0000)
#define  HISTOGRAM_ICH1_C1_Section0_Data_03_02_ch1_c1_section_his0_hist02_mask   (0x0000FFFF)
#define  HISTOGRAM_ICH1_C1_Section0_Data_03_02_ch1_c1_section_his0_hist03(data)  (0xFFFF0000&((data)<<16))
#define  HISTOGRAM_ICH1_C1_Section0_Data_03_02_ch1_c1_section_his0_hist02(data)  (0x0000FFFF&(data))
#define  HISTOGRAM_ICH1_C1_Section0_Data_03_02_get_ch1_c1_section_his0_hist03(data) ((0xFFFF0000&(data))>>16)
#define  HISTOGRAM_ICH1_C1_Section0_Data_03_02_get_ch1_c1_section_his0_hist02(data) (0x0000FFFF&(data))

#define  HISTOGRAM_ICH1_C1_Section0_Data_05_04                                   0x180232FC
#define  HISTOGRAM_ICH1_C1_Section0_Data_05_04_reg_addr                          "0xB80232FC"
#define  HISTOGRAM_ICH1_C1_Section0_Data_05_04_reg                               0xB80232FC
#define  HISTOGRAM_ICH1_C1_Section0_Data_05_04_inst_addr                         "0x003B"
#define  set_HISTOGRAM_ICH1_C1_Section0_Data_05_04_reg(data)                     (*((volatile unsigned int*)HISTOGRAM_ICH1_C1_Section0_Data_05_04_reg)=data)
#define  get_HISTOGRAM_ICH1_C1_Section0_Data_05_04_reg                           (*((volatile unsigned int*)HISTOGRAM_ICH1_C1_Section0_Data_05_04_reg))
#define  HISTOGRAM_ICH1_C1_Section0_Data_05_04_ch1_c1_section_his0_hist05_shift  (16)
#define  HISTOGRAM_ICH1_C1_Section0_Data_05_04_ch1_c1_section_his0_hist04_shift  (0)
#define  HISTOGRAM_ICH1_C1_Section0_Data_05_04_ch1_c1_section_his0_hist05_mask   (0xFFFF0000)
#define  HISTOGRAM_ICH1_C1_Section0_Data_05_04_ch1_c1_section_his0_hist04_mask   (0x0000FFFF)
#define  HISTOGRAM_ICH1_C1_Section0_Data_05_04_ch1_c1_section_his0_hist05(data)  (0xFFFF0000&((data)<<16))
#define  HISTOGRAM_ICH1_C1_Section0_Data_05_04_ch1_c1_section_his0_hist04(data)  (0x0000FFFF&(data))
#define  HISTOGRAM_ICH1_C1_Section0_Data_05_04_get_ch1_c1_section_his0_hist05(data) ((0xFFFF0000&(data))>>16)
#define  HISTOGRAM_ICH1_C1_Section0_Data_05_04_get_ch1_c1_section_his0_hist04(data) (0x0000FFFF&(data))

#define  HISTOGRAM_ICH1_C1_Section0_Data_07_06                                   0x18023300
#define  HISTOGRAM_ICH1_C1_Section0_Data_07_06_reg_addr                          "0xB8023300"
#define  HISTOGRAM_ICH1_C1_Section0_Data_07_06_reg                               0xB8023300
#define  HISTOGRAM_ICH1_C1_Section0_Data_07_06_inst_addr                         "0x003C"
#define  set_HISTOGRAM_ICH1_C1_Section0_Data_07_06_reg(data)                     (*((volatile unsigned int*)HISTOGRAM_ICH1_C1_Section0_Data_07_06_reg)=data)
#define  get_HISTOGRAM_ICH1_C1_Section0_Data_07_06_reg                           (*((volatile unsigned int*)HISTOGRAM_ICH1_C1_Section0_Data_07_06_reg))
#define  HISTOGRAM_ICH1_C1_Section0_Data_07_06_ch1_c1_section_his0_hist07_shift  (16)
#define  HISTOGRAM_ICH1_C1_Section0_Data_07_06_ch1_c1_section_his0_hist06_shift  (0)
#define  HISTOGRAM_ICH1_C1_Section0_Data_07_06_ch1_c1_section_his0_hist07_mask   (0xFFFF0000)
#define  HISTOGRAM_ICH1_C1_Section0_Data_07_06_ch1_c1_section_his0_hist06_mask   (0x0000FFFF)
#define  HISTOGRAM_ICH1_C1_Section0_Data_07_06_ch1_c1_section_his0_hist07(data)  (0xFFFF0000&((data)<<16))
#define  HISTOGRAM_ICH1_C1_Section0_Data_07_06_ch1_c1_section_his0_hist06(data)  (0x0000FFFF&(data))
#define  HISTOGRAM_ICH1_C1_Section0_Data_07_06_get_ch1_c1_section_his0_hist07(data) ((0xFFFF0000&(data))>>16)
#define  HISTOGRAM_ICH1_C1_Section0_Data_07_06_get_ch1_c1_section_his0_hist06(data) (0x0000FFFF&(data))

#define  HISTOGRAM_ICH1_C1_Section1_Data_01_00                                   0x18023304
#define  HISTOGRAM_ICH1_C1_Section1_Data_01_00_reg_addr                          "0xB8023304"
#define  HISTOGRAM_ICH1_C1_Section1_Data_01_00_reg                               0xB8023304
#define  HISTOGRAM_ICH1_C1_Section1_Data_01_00_inst_addr                         "0x003D"
#define  set_HISTOGRAM_ICH1_C1_Section1_Data_01_00_reg(data)                     (*((volatile unsigned int*)HISTOGRAM_ICH1_C1_Section1_Data_01_00_reg)=data)
#define  get_HISTOGRAM_ICH1_C1_Section1_Data_01_00_reg                           (*((volatile unsigned int*)HISTOGRAM_ICH1_C1_Section1_Data_01_00_reg))
#define  HISTOGRAM_ICH1_C1_Section1_Data_01_00_ch1_c1_section_his1_hist01_shift  (16)
#define  HISTOGRAM_ICH1_C1_Section1_Data_01_00_ch1_c1_section_his1_hist00_shift  (0)
#define  HISTOGRAM_ICH1_C1_Section1_Data_01_00_ch1_c1_section_his1_hist01_mask   (0xFFFF0000)
#define  HISTOGRAM_ICH1_C1_Section1_Data_01_00_ch1_c1_section_his1_hist00_mask   (0x0000FFFF)
#define  HISTOGRAM_ICH1_C1_Section1_Data_01_00_ch1_c1_section_his1_hist01(data)  (0xFFFF0000&((data)<<16))
#define  HISTOGRAM_ICH1_C1_Section1_Data_01_00_ch1_c1_section_his1_hist00(data)  (0x0000FFFF&(data))
#define  HISTOGRAM_ICH1_C1_Section1_Data_01_00_get_ch1_c1_section_his1_hist01(data) ((0xFFFF0000&(data))>>16)
#define  HISTOGRAM_ICH1_C1_Section1_Data_01_00_get_ch1_c1_section_his1_hist00(data) (0x0000FFFF&(data))

#define  HISTOGRAM_ICH1_C1_Section1_Data_03_02                                   0x18023308
#define  HISTOGRAM_ICH1_C1_Section1_Data_03_02_reg_addr                          "0xB8023308"
#define  HISTOGRAM_ICH1_C1_Section1_Data_03_02_reg                               0xB8023308
#define  HISTOGRAM_ICH1_C1_Section1_Data_03_02_inst_addr                         "0x003E"
#define  set_HISTOGRAM_ICH1_C1_Section1_Data_03_02_reg(data)                     (*((volatile unsigned int*)HISTOGRAM_ICH1_C1_Section1_Data_03_02_reg)=data)
#define  get_HISTOGRAM_ICH1_C1_Section1_Data_03_02_reg                           (*((volatile unsigned int*)HISTOGRAM_ICH1_C1_Section1_Data_03_02_reg))
#define  HISTOGRAM_ICH1_C1_Section1_Data_03_02_ch1_c1_section_his1_hist03_shift  (16)
#define  HISTOGRAM_ICH1_C1_Section1_Data_03_02_ch1_c1_section_his1_hist02_shift  (0)
#define  HISTOGRAM_ICH1_C1_Section1_Data_03_02_ch1_c1_section_his1_hist03_mask   (0xFFFF0000)
#define  HISTOGRAM_ICH1_C1_Section1_Data_03_02_ch1_c1_section_his1_hist02_mask   (0x0000FFFF)
#define  HISTOGRAM_ICH1_C1_Section1_Data_03_02_ch1_c1_section_his1_hist03(data)  (0xFFFF0000&((data)<<16))
#define  HISTOGRAM_ICH1_C1_Section1_Data_03_02_ch1_c1_section_his1_hist02(data)  (0x0000FFFF&(data))
#define  HISTOGRAM_ICH1_C1_Section1_Data_03_02_get_ch1_c1_section_his1_hist03(data) ((0xFFFF0000&(data))>>16)
#define  HISTOGRAM_ICH1_C1_Section1_Data_03_02_get_ch1_c1_section_his1_hist02(data) (0x0000FFFF&(data))

#define  HISTOGRAM_ICH1_C1_Section1_Data_05_04                                   0x1802330C
#define  HISTOGRAM_ICH1_C1_Section1_Data_05_04_reg_addr                          "0xB802330C"
#define  HISTOGRAM_ICH1_C1_Section1_Data_05_04_reg                               0xB802330C
#define  HISTOGRAM_ICH1_C1_Section1_Data_05_04_inst_addr                         "0x003F"
#define  set_HISTOGRAM_ICH1_C1_Section1_Data_05_04_reg(data)                     (*((volatile unsigned int*)HISTOGRAM_ICH1_C1_Section1_Data_05_04_reg)=data)
#define  get_HISTOGRAM_ICH1_C1_Section1_Data_05_04_reg                           (*((volatile unsigned int*)HISTOGRAM_ICH1_C1_Section1_Data_05_04_reg))
#define  HISTOGRAM_ICH1_C1_Section1_Data_05_04_ch1_c1_section_his1_hist05_shift  (16)
#define  HISTOGRAM_ICH1_C1_Section1_Data_05_04_ch1_c1_section_his1_hist04_shift  (0)
#define  HISTOGRAM_ICH1_C1_Section1_Data_05_04_ch1_c1_section_his1_hist05_mask   (0xFFFF0000)
#define  HISTOGRAM_ICH1_C1_Section1_Data_05_04_ch1_c1_section_his1_hist04_mask   (0x0000FFFF)
#define  HISTOGRAM_ICH1_C1_Section1_Data_05_04_ch1_c1_section_his1_hist05(data)  (0xFFFF0000&((data)<<16))
#define  HISTOGRAM_ICH1_C1_Section1_Data_05_04_ch1_c1_section_his1_hist04(data)  (0x0000FFFF&(data))
#define  HISTOGRAM_ICH1_C1_Section1_Data_05_04_get_ch1_c1_section_his1_hist05(data) ((0xFFFF0000&(data))>>16)
#define  HISTOGRAM_ICH1_C1_Section1_Data_05_04_get_ch1_c1_section_his1_hist04(data) (0x0000FFFF&(data))

#define  HISTOGRAM_ICH1_C1_Section1_Data_07_06                                   0x18023310
#define  HISTOGRAM_ICH1_C1_Section1_Data_07_06_reg_addr                          "0xB8023310"
#define  HISTOGRAM_ICH1_C1_Section1_Data_07_06_reg                               0xB8023310
#define  HISTOGRAM_ICH1_C1_Section1_Data_07_06_inst_addr                         "0x0040"
#define  set_HISTOGRAM_ICH1_C1_Section1_Data_07_06_reg(data)                     (*((volatile unsigned int*)HISTOGRAM_ICH1_C1_Section1_Data_07_06_reg)=data)
#define  get_HISTOGRAM_ICH1_C1_Section1_Data_07_06_reg                           (*((volatile unsigned int*)HISTOGRAM_ICH1_C1_Section1_Data_07_06_reg))
#define  HISTOGRAM_ICH1_C1_Section1_Data_07_06_ch1_c1_section_his1_hist07_shift  (16)
#define  HISTOGRAM_ICH1_C1_Section1_Data_07_06_ch1_c1_section_his1_hist06_shift  (0)
#define  HISTOGRAM_ICH1_C1_Section1_Data_07_06_ch1_c1_section_his1_hist07_mask   (0xFFFF0000)
#define  HISTOGRAM_ICH1_C1_Section1_Data_07_06_ch1_c1_section_his1_hist06_mask   (0x0000FFFF)
#define  HISTOGRAM_ICH1_C1_Section1_Data_07_06_ch1_c1_section_his1_hist07(data)  (0xFFFF0000&((data)<<16))
#define  HISTOGRAM_ICH1_C1_Section1_Data_07_06_ch1_c1_section_his1_hist06(data)  (0x0000FFFF&(data))
#define  HISTOGRAM_ICH1_C1_Section1_Data_07_06_get_ch1_c1_section_his1_hist07(data) ((0xFFFF0000&(data))>>16)
#define  HISTOGRAM_ICH1_C1_Section1_Data_07_06_get_ch1_c1_section_his1_hist06(data) (0x0000FFFF&(data))

#define  HISTOGRAM_ICH1_MBIST_HIST_2P_BIST_FAIL                                  0x1802331C
#define  HISTOGRAM_ICH1_MBIST_HIST_2P_BIST_FAIL_reg_addr                         "0xB802331C"
#define  HISTOGRAM_ICH1_MBIST_HIST_2P_BIST_FAIL_reg                              0xB802331C
#define  HISTOGRAM_ICH1_MBIST_HIST_2P_BIST_FAIL_inst_addr                        "0x0041"
#define  set_HISTOGRAM_ICH1_MBIST_HIST_2P_BIST_FAIL_reg(data)                    (*((volatile unsigned int*)HISTOGRAM_ICH1_MBIST_HIST_2P_BIST_FAIL_reg)=data)
#define  get_HISTOGRAM_ICH1_MBIST_HIST_2P_BIST_FAIL_reg                          (*((volatile unsigned int*)HISTOGRAM_ICH1_MBIST_HIST_2P_BIST_FAIL_reg))
#define  HISTOGRAM_ICH1_MBIST_HIST_2P_BIST_FAIL_ich1_c0_mbist_hist_2p_bist_fail_shift (3)
#define  HISTOGRAM_ICH1_MBIST_HIST_2P_BIST_FAIL_ich1_c1_mbist_hist_2p_bist_fail_shift (2)
#define  HISTOGRAM_ICH1_MBIST_HIST_2P_BIST_FAIL_ich1_c0_mbist_hist_2p_bist_fail_mask (0x00000008)
#define  HISTOGRAM_ICH1_MBIST_HIST_2P_BIST_FAIL_ich1_c1_mbist_hist_2p_bist_fail_mask (0x00000004)
#define  HISTOGRAM_ICH1_MBIST_HIST_2P_BIST_FAIL_ich1_c0_mbist_hist_2p_bist_fail(data) (0x00000008&((data)<<3))
#define  HISTOGRAM_ICH1_MBIST_HIST_2P_BIST_FAIL_ich1_c1_mbist_hist_2p_bist_fail(data) (0x00000004&((data)<<2))
#define  HISTOGRAM_ICH1_MBIST_HIST_2P_BIST_FAIL_get_ich1_c0_mbist_hist_2p_bist_fail(data) ((0x00000008&(data))>>3)
#define  HISTOGRAM_ICH1_MBIST_HIST_2P_BIST_FAIL_get_ich1_c1_mbist_hist_2p_bist_fail(data) ((0x00000004&(data))>>2)

#define  HISTOGRAM_ICH1_MBIST_HIST_1P_BIST_FAIL                                  0x18023320
#define  HISTOGRAM_ICH1_MBIST_HIST_1P_BIST_FAIL_reg_addr                         "0xB8023320"
#define  HISTOGRAM_ICH1_MBIST_HIST_1P_BIST_FAIL_reg                              0xB8023320
#define  HISTOGRAM_ICH1_MBIST_HIST_1P_BIST_FAIL_inst_addr                        "0x0042"
#define  set_HISTOGRAM_ICH1_MBIST_HIST_1P_BIST_FAIL_reg(data)                    (*((volatile unsigned int*)HISTOGRAM_ICH1_MBIST_HIST_1P_BIST_FAIL_reg)=data)
#define  get_HISTOGRAM_ICH1_MBIST_HIST_1P_BIST_FAIL_reg                          (*((volatile unsigned int*)HISTOGRAM_ICH1_MBIST_HIST_1P_BIST_FAIL_reg))
#define  HISTOGRAM_ICH1_MBIST_HIST_1P_BIST_FAIL_ich1_c0_mbist_hist_1p_bist_fail_shift (3)
#define  HISTOGRAM_ICH1_MBIST_HIST_1P_BIST_FAIL_ich1_c1_mbist_hist_1p_bist_fail_shift (2)
#define  HISTOGRAM_ICH1_MBIST_HIST_1P_BIST_FAIL_ich1_c0_mbist_hist_1p_bist_fail_mask (0x00000008)
#define  HISTOGRAM_ICH1_MBIST_HIST_1P_BIST_FAIL_ich1_c1_mbist_hist_1p_bist_fail_mask (0x00000004)
#define  HISTOGRAM_ICH1_MBIST_HIST_1P_BIST_FAIL_ich1_c0_mbist_hist_1p_bist_fail(data) (0x00000008&((data)<<3))
#define  HISTOGRAM_ICH1_MBIST_HIST_1P_BIST_FAIL_ich1_c1_mbist_hist_1p_bist_fail(data) (0x00000004&((data)<<2))
#define  HISTOGRAM_ICH1_MBIST_HIST_1P_BIST_FAIL_get_ich1_c0_mbist_hist_1p_bist_fail(data) ((0x00000008&(data))>>3)
#define  HISTOGRAM_ICH1_MBIST_HIST_1P_BIST_FAIL_get_ich1_c1_mbist_hist_1p_bist_fail(data) ((0x00000004&(data))>>2)

#define  HISTOGRAM_ICH1_MBIST_HIST_2P_DRF_FAIL                                   0x18023324
#define  HISTOGRAM_ICH1_MBIST_HIST_2P_DRF_FAIL_reg_addr                          "0xB8023324"
#define  HISTOGRAM_ICH1_MBIST_HIST_2P_DRF_FAIL_reg                               0xB8023324
#define  HISTOGRAM_ICH1_MBIST_HIST_2P_DRF_FAIL_inst_addr                         "0x0043"
#define  set_HISTOGRAM_ICH1_MBIST_HIST_2P_DRF_FAIL_reg(data)                     (*((volatile unsigned int*)HISTOGRAM_ICH1_MBIST_HIST_2P_DRF_FAIL_reg)=data)
#define  get_HISTOGRAM_ICH1_MBIST_HIST_2P_DRF_FAIL_reg                           (*((volatile unsigned int*)HISTOGRAM_ICH1_MBIST_HIST_2P_DRF_FAIL_reg))
#define  HISTOGRAM_ICH1_MBIST_HIST_2P_DRF_FAIL_ich1_c0_mbist_hist_2p_drf_fail_shift (3)
#define  HISTOGRAM_ICH1_MBIST_HIST_2P_DRF_FAIL_ich1_c1_mbist_hist_2p_drf_fail_shift (2)
#define  HISTOGRAM_ICH1_MBIST_HIST_2P_DRF_FAIL_ich1_c0_mbist_hist_2p_drf_fail_mask (0x00000008)
#define  HISTOGRAM_ICH1_MBIST_HIST_2P_DRF_FAIL_ich1_c1_mbist_hist_2p_drf_fail_mask (0x00000004)
#define  HISTOGRAM_ICH1_MBIST_HIST_2P_DRF_FAIL_ich1_c0_mbist_hist_2p_drf_fail(data) (0x00000008&((data)<<3))
#define  HISTOGRAM_ICH1_MBIST_HIST_2P_DRF_FAIL_ich1_c1_mbist_hist_2p_drf_fail(data) (0x00000004&((data)<<2))
#define  HISTOGRAM_ICH1_MBIST_HIST_2P_DRF_FAIL_get_ich1_c0_mbist_hist_2p_drf_fail(data) ((0x00000008&(data))>>3)
#define  HISTOGRAM_ICH1_MBIST_HIST_2P_DRF_FAIL_get_ich1_c1_mbist_hist_2p_drf_fail(data) ((0x00000004&(data))>>2)

#define  HISTOGRAM_ICH1_MBIST_HIST_1P_DRF_FAIL                                   0x18023328
#define  HISTOGRAM_ICH1_MBIST_HIST_1P_DRF_FAIL_reg_addr                          "0xB8023328"
#define  HISTOGRAM_ICH1_MBIST_HIST_1P_DRF_FAIL_reg                               0xB8023328
#define  HISTOGRAM_ICH1_MBIST_HIST_1P_DRF_FAIL_inst_addr                         "0x0044"
#define  set_HISTOGRAM_ICH1_MBIST_HIST_1P_DRF_FAIL_reg(data)                     (*((volatile unsigned int*)HISTOGRAM_ICH1_MBIST_HIST_1P_DRF_FAIL_reg)=data)
#define  get_HISTOGRAM_ICH1_MBIST_HIST_1P_DRF_FAIL_reg                           (*((volatile unsigned int*)HISTOGRAM_ICH1_MBIST_HIST_1P_DRF_FAIL_reg))
#define  HISTOGRAM_ICH1_MBIST_HIST_1P_DRF_FAIL_ich1_c0_mbist_hist_1p_drf_fail_shift (3)
#define  HISTOGRAM_ICH1_MBIST_HIST_1P_DRF_FAIL_ich1_c1_mbist_hist_1p_drf_fail_shift (2)
#define  HISTOGRAM_ICH1_MBIST_HIST_1P_DRF_FAIL_ich1_c0_mbist_hist_1p_drf_fail_mask (0x00000008)
#define  HISTOGRAM_ICH1_MBIST_HIST_1P_DRF_FAIL_ich1_c1_mbist_hist_1p_drf_fail_mask (0x00000004)
#define  HISTOGRAM_ICH1_MBIST_HIST_1P_DRF_FAIL_ich1_c0_mbist_hist_1p_drf_fail(data) (0x00000008&((data)<<3))
#define  HISTOGRAM_ICH1_MBIST_HIST_1P_DRF_FAIL_ich1_c1_mbist_hist_1p_drf_fail(data) (0x00000004&((data)<<2))
#define  HISTOGRAM_ICH1_MBIST_HIST_1P_DRF_FAIL_get_ich1_c0_mbist_hist_1p_drf_fail(data) ((0x00000008&(data))>>3)
#define  HISTOGRAM_ICH1_MBIST_HIST_1P_DRF_FAIL_get_ich1_c1_mbist_hist_1p_drf_fail(data) ((0x00000004&(data))>>2)

#define  HISTOGRAM_ICH1_MBIST_HIST_2P_BIST_DVSE                                  0x1802332C
#define  HISTOGRAM_ICH1_MBIST_HIST_2P_BIST_DVSE_reg_addr                         "0xB802332C"
#define  HISTOGRAM_ICH1_MBIST_HIST_2P_BIST_DVSE_reg                              0xB802332C
#define  HISTOGRAM_ICH1_MBIST_HIST_2P_BIST_DVSE_inst_addr                        "0x0045"
#define  set_HISTOGRAM_ICH1_MBIST_HIST_2P_BIST_DVSE_reg(data)                    (*((volatile unsigned int*)HISTOGRAM_ICH1_MBIST_HIST_2P_BIST_DVSE_reg)=data)
#define  get_HISTOGRAM_ICH1_MBIST_HIST_2P_BIST_DVSE_reg                          (*((volatile unsigned int*)HISTOGRAM_ICH1_MBIST_HIST_2P_BIST_DVSE_reg))
#define  HISTOGRAM_ICH1_MBIST_HIST_2P_BIST_DVSE_ich1_c0_mbist_hist_2p_bist_ls_shift (6)
#define  HISTOGRAM_ICH1_MBIST_HIST_2P_BIST_DVSE_ich1_c1_mbist_hist_2p_bist_ls_shift (5)
#define  HISTOGRAM_ICH1_MBIST_HIST_2P_BIST_DVSE_ich1_mbist_hist_2p_bist_testrwm_shift (4)
#define  HISTOGRAM_ICH1_MBIST_HIST_2P_BIST_DVSE_ich1_c0_mbist_hist_2p_bist_dvse_shift (3)
#define  HISTOGRAM_ICH1_MBIST_HIST_2P_BIST_DVSE_ich1_c1_mbist_hist_2p_bist_dvse_shift (2)
#define  HISTOGRAM_ICH1_MBIST_HIST_2P_BIST_DVSE_ich1_c0_mbist_hist_2p_bist_ls_mask (0x00000040)
#define  HISTOGRAM_ICH1_MBIST_HIST_2P_BIST_DVSE_ich1_c1_mbist_hist_2p_bist_ls_mask (0x00000020)
#define  HISTOGRAM_ICH1_MBIST_HIST_2P_BIST_DVSE_ich1_mbist_hist_2p_bist_testrwm_mask (0x00000010)
#define  HISTOGRAM_ICH1_MBIST_HIST_2P_BIST_DVSE_ich1_c0_mbist_hist_2p_bist_dvse_mask (0x00000008)
#define  HISTOGRAM_ICH1_MBIST_HIST_2P_BIST_DVSE_ich1_c1_mbist_hist_2p_bist_dvse_mask (0x00000004)
#define  HISTOGRAM_ICH1_MBIST_HIST_2P_BIST_DVSE_ich1_c0_mbist_hist_2p_bist_ls(data) (0x00000040&((data)<<6))
#define  HISTOGRAM_ICH1_MBIST_HIST_2P_BIST_DVSE_ich1_c1_mbist_hist_2p_bist_ls(data) (0x00000020&((data)<<5))
#define  HISTOGRAM_ICH1_MBIST_HIST_2P_BIST_DVSE_ich1_mbist_hist_2p_bist_testrwm(data) (0x00000010&((data)<<4))
#define  HISTOGRAM_ICH1_MBIST_HIST_2P_BIST_DVSE_ich1_c0_mbist_hist_2p_bist_dvse(data) (0x00000008&((data)<<3))
#define  HISTOGRAM_ICH1_MBIST_HIST_2P_BIST_DVSE_ich1_c1_mbist_hist_2p_bist_dvse(data) (0x00000004&((data)<<2))
#define  HISTOGRAM_ICH1_MBIST_HIST_2P_BIST_DVSE_get_ich1_c0_mbist_hist_2p_bist_ls(data) ((0x00000040&(data))>>6)
#define  HISTOGRAM_ICH1_MBIST_HIST_2P_BIST_DVSE_get_ich1_c1_mbist_hist_2p_bist_ls(data) ((0x00000020&(data))>>5)
#define  HISTOGRAM_ICH1_MBIST_HIST_2P_BIST_DVSE_get_ich1_mbist_hist_2p_bist_testrwm(data) ((0x00000010&(data))>>4)
#define  HISTOGRAM_ICH1_MBIST_HIST_2P_BIST_DVSE_get_ich1_c0_mbist_hist_2p_bist_dvse(data) ((0x00000008&(data))>>3)
#define  HISTOGRAM_ICH1_MBIST_HIST_2P_BIST_DVSE_get_ich1_c1_mbist_hist_2p_bist_dvse(data) ((0x00000004&(data))>>2)

#define  HISTOGRAM_ICH1_MBIST_HIST_1P_BIST_DVSE                                  0x18023330
#define  HISTOGRAM_ICH1_MBIST_HIST_1P_BIST_DVSE_reg_addr                         "0xB8023330"
#define  HISTOGRAM_ICH1_MBIST_HIST_1P_BIST_DVSE_reg                              0xB8023330
#define  HISTOGRAM_ICH1_MBIST_HIST_1P_BIST_DVSE_inst_addr                        "0x0046"
#define  set_HISTOGRAM_ICH1_MBIST_HIST_1P_BIST_DVSE_reg(data)                    (*((volatile unsigned int*)HISTOGRAM_ICH1_MBIST_HIST_1P_BIST_DVSE_reg)=data)
#define  get_HISTOGRAM_ICH1_MBIST_HIST_1P_BIST_DVSE_reg                          (*((volatile unsigned int*)HISTOGRAM_ICH1_MBIST_HIST_1P_BIST_DVSE_reg))
#define  HISTOGRAM_ICH1_MBIST_HIST_1P_BIST_DVSE_ich1_c0_mbist_hist_1p_bist_ls_shift (5)
#define  HISTOGRAM_ICH1_MBIST_HIST_1P_BIST_DVSE_ich1_c1_mbist_hist_1p_bist_ls_shift (4)
#define  HISTOGRAM_ICH1_MBIST_HIST_1P_BIST_DVSE_ich1_c0_mbist_hist_1p_bist_dvse_shift (3)
#define  HISTOGRAM_ICH1_MBIST_HIST_1P_BIST_DVSE_ich1_c1_mbist_hist_1p_bist_dvse_shift (2)
#define  HISTOGRAM_ICH1_MBIST_HIST_1P_BIST_DVSE_ich1_c0_mbist_hist_1p_bist_ls_mask (0x00000020)
#define  HISTOGRAM_ICH1_MBIST_HIST_1P_BIST_DVSE_ich1_c1_mbist_hist_1p_bist_ls_mask (0x00000010)
#define  HISTOGRAM_ICH1_MBIST_HIST_1P_BIST_DVSE_ich1_c0_mbist_hist_1p_bist_dvse_mask (0x00000008)
#define  HISTOGRAM_ICH1_MBIST_HIST_1P_BIST_DVSE_ich1_c1_mbist_hist_1p_bist_dvse_mask (0x00000004)
#define  HISTOGRAM_ICH1_MBIST_HIST_1P_BIST_DVSE_ich1_c0_mbist_hist_1p_bist_ls(data) (0x00000020&((data)<<5))
#define  HISTOGRAM_ICH1_MBIST_HIST_1P_BIST_DVSE_ich1_c1_mbist_hist_1p_bist_ls(data) (0x00000010&((data)<<4))
#define  HISTOGRAM_ICH1_MBIST_HIST_1P_BIST_DVSE_ich1_c0_mbist_hist_1p_bist_dvse(data) (0x00000008&((data)<<3))
#define  HISTOGRAM_ICH1_MBIST_HIST_1P_BIST_DVSE_ich1_c1_mbist_hist_1p_bist_dvse(data) (0x00000004&((data)<<2))
#define  HISTOGRAM_ICH1_MBIST_HIST_1P_BIST_DVSE_get_ich1_c0_mbist_hist_1p_bist_ls(data) ((0x00000020&(data))>>5)
#define  HISTOGRAM_ICH1_MBIST_HIST_1P_BIST_DVSE_get_ich1_c1_mbist_hist_1p_bist_ls(data) ((0x00000010&(data))>>4)
#define  HISTOGRAM_ICH1_MBIST_HIST_1P_BIST_DVSE_get_ich1_c0_mbist_hist_1p_bist_dvse(data) ((0x00000008&(data))>>3)
#define  HISTOGRAM_ICH1_MBIST_HIST_1P_BIST_DVSE_get_ich1_c1_mbist_hist_1p_bist_dvse(data) ((0x00000004&(data))>>2)

#define  HISTOGRAM_ICH1_MBIST_HIST_2P_BIST_DVS                                   0x18023334
#define  HISTOGRAM_ICH1_MBIST_HIST_2P_BIST_DVS_reg_addr                          "0xB8023334"
#define  HISTOGRAM_ICH1_MBIST_HIST_2P_BIST_DVS_reg                               0xB8023334
#define  HISTOGRAM_ICH1_MBIST_HIST_2P_BIST_DVS_inst_addr                         "0x0047"
#define  set_HISTOGRAM_ICH1_MBIST_HIST_2P_BIST_DVS_reg(data)                     (*((volatile unsigned int*)HISTOGRAM_ICH1_MBIST_HIST_2P_BIST_DVS_reg)=data)
#define  get_HISTOGRAM_ICH1_MBIST_HIST_2P_BIST_DVS_reg                           (*((volatile unsigned int*)HISTOGRAM_ICH1_MBIST_HIST_2P_BIST_DVS_reg))
#define  HISTOGRAM_ICH1_MBIST_HIST_2P_BIST_DVS_ich1_c0_mbist_hist_2p_bist_dvs_shift (12)
#define  HISTOGRAM_ICH1_MBIST_HIST_2P_BIST_DVS_ich1_c1_mbist_hist_2p_bist_dvs_shift (8)
#define  HISTOGRAM_ICH1_MBIST_HIST_2P_BIST_DVS_ich1_c0_mbist_hist_2p_bist_dvs_mask (0x0000F000)
#define  HISTOGRAM_ICH1_MBIST_HIST_2P_BIST_DVS_ich1_c1_mbist_hist_2p_bist_dvs_mask (0x00000F00)
#define  HISTOGRAM_ICH1_MBIST_HIST_2P_BIST_DVS_ich1_c0_mbist_hist_2p_bist_dvs(data) (0x0000F000&((data)<<12))
#define  HISTOGRAM_ICH1_MBIST_HIST_2P_BIST_DVS_ich1_c1_mbist_hist_2p_bist_dvs(data) (0x00000F00&((data)<<8))
#define  HISTOGRAM_ICH1_MBIST_HIST_2P_BIST_DVS_get_ich1_c0_mbist_hist_2p_bist_dvs(data) ((0x0000F000&(data))>>12)
#define  HISTOGRAM_ICH1_MBIST_HIST_2P_BIST_DVS_get_ich1_c1_mbist_hist_2p_bist_dvs(data) ((0x00000F00&(data))>>8)

#define  HISTOGRAM_ICH1_MBIST_HIST_1P_BIST_DVS                                   0x18023338
#define  HISTOGRAM_ICH1_MBIST_HIST_1P_BIST_DVS_reg_addr                          "0xB8023338"
#define  HISTOGRAM_ICH1_MBIST_HIST_1P_BIST_DVS_reg                               0xB8023338
#define  HISTOGRAM_ICH1_MBIST_HIST_1P_BIST_DVS_inst_addr                         "0x0048"
#define  set_HISTOGRAM_ICH1_MBIST_HIST_1P_BIST_DVS_reg(data)                     (*((volatile unsigned int*)HISTOGRAM_ICH1_MBIST_HIST_1P_BIST_DVS_reg)=data)
#define  get_HISTOGRAM_ICH1_MBIST_HIST_1P_BIST_DVS_reg                           (*((volatile unsigned int*)HISTOGRAM_ICH1_MBIST_HIST_1P_BIST_DVS_reg))
#define  HISTOGRAM_ICH1_MBIST_HIST_1P_BIST_DVS_ich1_c0_mbist_hist_1p_bist_dvs_shift (12)
#define  HISTOGRAM_ICH1_MBIST_HIST_1P_BIST_DVS_ich1_c1_mbist_hist_1p_bist_dvs_shift (8)
#define  HISTOGRAM_ICH1_MBIST_HIST_1P_BIST_DVS_ich1_c0_mbist_hist_1p_bist_dvs_mask (0x0000F000)
#define  HISTOGRAM_ICH1_MBIST_HIST_1P_BIST_DVS_ich1_c1_mbist_hist_1p_bist_dvs_mask (0x00000F00)
#define  HISTOGRAM_ICH1_MBIST_HIST_1P_BIST_DVS_ich1_c0_mbist_hist_1p_bist_dvs(data) (0x0000F000&((data)<<12))
#define  HISTOGRAM_ICH1_MBIST_HIST_1P_BIST_DVS_ich1_c1_mbist_hist_1p_bist_dvs(data) (0x00000F00&((data)<<8))
#define  HISTOGRAM_ICH1_MBIST_HIST_1P_BIST_DVS_get_ich1_c0_mbist_hist_1p_bist_dvs(data) ((0x0000F000&(data))>>12)
#define  HISTOGRAM_ICH1_MBIST_HIST_1P_BIST_DVS_get_ich1_c1_mbist_hist_1p_bist_dvs(data) ((0x00000F00&(data))>>8)

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======HISTOGRAM register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  i2rnd_histogram_sel:2;
        RBus_UInt32  bin_mode:1;
        RBus_UInt32  lr_select:1;
        RBus_UInt32  ch1_3d_en:1;
        RBus_UInt32  ch1_his_updatelockmode_en:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  ch1_his_enable_histog:1;
        RBus_UInt32  ch1_his_irq_en:1;
        RBus_UInt32  ch1_his_yuv_sel:2;
        RBus_UInt32  ch1_his_num_flds:4;
        RBus_UInt32  ch1_his_shift_sel:3;
        RBus_UInt32  ch1_his_offset:4;
        RBus_UInt32  res3:1;
        RBus_UInt32  ch1_his_mode_sel:1;
        RBus_UInt32  ch1_his_even_odd_pos_en:1;
        RBus_UInt32  ch1_his_even_odd_pos_sel:1;
        RBus_UInt32  ch1_his_even_odd_fld_en:1;
        RBus_UInt32  ch1_his_even_odd_fld_sel:1;
        RBus_UInt32  res4:2;
    };
}histogram_ich1_hist_in_cselect_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  ch1_his_horend:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  ch1_his_horstart:13;
    };
}histogram_ich1_hist_in_range_hor_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  ch1_his_verend:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  ch1_his_verstart:13;
    };
}histogram_ich1_hist_in_range_ver_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  i2rnd_histogram_sel:1;
        RBus_UInt32  ch1_his_dcc_invalid:1;
        RBus_UInt32  ch1_his_his_irq:1;
    };
}histogram_ich1_hist_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  ch1_his_max_val:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  ch1_his_min_val:10;
    };
}histogram_ich1_hist_max_min_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  bycolor_debug_mode:2;
    };
}histogram_ich1_bycolor_debug_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  ch1_his_sumval_high:9;
    };
}histogram_ich1_hist_sumval_high_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  ch1_his_sumval_low:24;
    };
}histogram_ich1_hist_sumval_low_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  ch1_c0_upper_bound:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  ch1_c0_lower_bound:10;
    };
}histogram_ich1_c0_hist_bound_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  ch1_c0_upper_bound_u:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  ch1_c0_lower_bound_u:10;
    };
}histogram_ich1_c0_hist_bound_u_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  ch1_c0_upper_bound_v:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  ch1_c0_lower_bound_v:10;
    };
}histogram_ich1_c0_hist_bound_v_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  ch1_sram_read:1;
        RBus_UInt32  ch1_sram_block:2;
        RBus_UInt32  ch1_sram_read_consistent_flag:1;
    };
}histogram_ich1_hist_read_ctr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_hist01:16;
        RBus_UInt32  ch1_c0_hist00:16;
    };
}histogram_ich1_c0_hist_in_data_01_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_hist03:16;
        RBus_UInt32  ch1_c0_hist02:16;
    };
}histogram_ich1_c0_hist_in_data_03_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_hist05:16;
        RBus_UInt32  ch1_c0_hist04:16;
    };
}histogram_ich1_c0_hist_in_data_05_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_hist07:16;
        RBus_UInt32  ch1_c0_hist06:16;
    };
}histogram_ich1_c0_hist_in_data_07_06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_hist09:16;
        RBus_UInt32  ch1_c0_hist08:16;
    };
}histogram_ich1_c0_hist_in_data_09_08_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_hist11:16;
        RBus_UInt32  ch1_c0_hist10:16;
    };
}histogram_ich1_c0_hist_in_data_11_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_hist13:16;
        RBus_UInt32  ch1_c0_hist12:16;
    };
}histogram_ich1_c0_hist_in_data_13_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_hist15:16;
        RBus_UInt32  ch1_c0_hist14:16;
    };
}histogram_ich1_c0_hist_in_data_15_14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_hist17:16;
        RBus_UInt32  ch1_c0_hist16:16;
    };
}histogram_ich1_c0_hist_in_data_17_16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_hist19:16;
        RBus_UInt32  ch1_c0_hist18:16;
    };
}histogram_ich1_c0_hist_in_data_19_18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_hist21:16;
        RBus_UInt32  ch1_c0_hist20:16;
    };
}histogram_ich1_c0_hist_in_data_21_20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_hist23:16;
        RBus_UInt32  ch1_c0_hist22:16;
    };
}histogram_ich1_c0_hist_in_data_23_22_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_hist25:16;
        RBus_UInt32  ch1_c0_hist24:16;
    };
}histogram_ich1_c0_hist_in_data_25_24_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_hist27:16;
        RBus_UInt32  ch1_c0_hist26:16;
    };
}histogram_ich1_c0_hist_in_data_27_26_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_hist29:16;
        RBus_UInt32  ch1_c0_hist28:16;
    };
}histogram_ich1_c0_hist_in_data_29_28_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_hist31:16;
        RBus_UInt32  ch1_c0_hist30:16;
    };
}histogram_ich1_c0_hist_in_data_31_30_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  ch1_c0_section1_bin_sel:7;
        RBus_UInt32  res2:9;
        RBus_UInt32  ch1_c0_section0_bin_sel:7;
    };
}histogram_ich1_c0_sectionhist_in_cselect_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_section_his0_hist01:16;
        RBus_UInt32  ch1_c0_section_his0_hist00:16;
    };
}histogram_ich1_c0_section0_data_01_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_section_his0_hist03:16;
        RBus_UInt32  ch1_c0_section_his0_hist02:16;
    };
}histogram_ich1_c0_section0_data_03_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_section_his0_hist05:16;
        RBus_UInt32  ch1_c0_section_his0_hist04:16;
    };
}histogram_ich1_c0_section0_data_05_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_section_his0_hist07:16;
        RBus_UInt32  ch1_c0_section_his0_hist06:16;
    };
}histogram_ich1_c0_section0_data_07_06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_section_his1_hist01:16;
        RBus_UInt32  ch1_c0_section_his1_hist00:16;
    };
}histogram_ich1_c0_section1_data_01_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_section_his1_hist03:16;
        RBus_UInt32  ch1_c0_section_his1_hist02:16;
    };
}histogram_ich1_c0_section1_data_03_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_section_his1_hist05:16;
        RBus_UInt32  ch1_c0_section_his1_hist04:16;
    };
}histogram_ich1_c0_section1_data_05_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_section_his1_hist07:16;
        RBus_UInt32  ch1_c0_section_his1_hist06:16;
    };
}histogram_ich1_c0_section1_data_07_06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  ch1_c1_upper_bound:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  ch1_c1_lower_bound:10;
    };
}histogram_ich1_c1_hist_bound_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  ch1_c1_upper_bound_u:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  ch1_c1_lower_bound_u:10;
    };
}histogram_ich1_c1_hist_bound_u_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  ch1_c1_upper_bound_v:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  ch1_c1_lower_bound_v:10;
    };
}histogram_ich1_c1_hist_bound_v_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_hist01:16;
        RBus_UInt32  ch1_c1_hist00:16;
    };
}histogram_ich1_c1_hist_in_data_01_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_hist03:16;
        RBus_UInt32  ch1_c1_hist02:16;
    };
}histogram_ich1_c1_hist_in_data_03_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_hist05:16;
        RBus_UInt32  ch1_c1_hist04:16;
    };
}histogram_ich1_c1_hist_in_data_05_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_hist07:16;
        RBus_UInt32  ch1_c1_hist06:16;
    };
}histogram_ich1_c1_hist_in_data_07_06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_hist09:16;
        RBus_UInt32  ch1_c1_hist08:16;
    };
}histogram_ich1_c1_hist_in_data_09_08_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_hist11:16;
        RBus_UInt32  ch1_c1_hist10:16;
    };
}histogram_ich1_c1_hist_in_data_11_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_hist13:16;
        RBus_UInt32  ch1_c1_hist12:16;
    };
}histogram_ich1_c1_hist_in_data_13_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_hist15:16;
        RBus_UInt32  ch1_c1_hist14:16;
    };
}histogram_ich1_c1_hist_in_data_15_14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_hist17:16;
        RBus_UInt32  ch1_c1_hist16:16;
    };
}histogram_ich1_c1_hist_in_data_17_16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_hist19:16;
        RBus_UInt32  ch1_c1_hist18:16;
    };
}histogram_ich1_c1_hist_in_data_19_18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_hist21:16;
        RBus_UInt32  ch1_c1_hist20:16;
    };
}histogram_ich1_c1_hist_in_data_21_20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_hist23:16;
        RBus_UInt32  ch1_c1_hist22:16;
    };
}histogram_ich1_c1_hist_in_data_23_22_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_hist25:16;
        RBus_UInt32  ch1_c1_hist24:16;
    };
}histogram_ich1_c1_hist_in_data_25_24_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_hist27:16;
        RBus_UInt32  ch1_c1_hist26:16;
    };
}histogram_ich1_c1_hist_in_data_27_26_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_hist29:16;
        RBus_UInt32  ch1_c1_hist28:16;
    };
}histogram_ich1_c1_hist_in_data_29_28_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_hist31:16;
        RBus_UInt32  ch1_c1_hist30:16;
    };
}histogram_ich1_c1_hist_in_data_31_30_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  ch1_c1_section1_bin_sel:7;
        RBus_UInt32  res2:9;
        RBus_UInt32  ch1_c1_section0_bin_sel:7;
    };
}histogram_ich1_c1_sectionhist_in_cselect_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_section_his0_hist01:16;
        RBus_UInt32  ch1_c1_section_his0_hist00:16;
    };
}histogram_ich1_c1_section0_data_01_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_section_his0_hist03:16;
        RBus_UInt32  ch1_c1_section_his0_hist02:16;
    };
}histogram_ich1_c1_section0_data_03_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_section_his0_hist05:16;
        RBus_UInt32  ch1_c1_section_his0_hist04:16;
    };
}histogram_ich1_c1_section0_data_05_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_section_his0_hist07:16;
        RBus_UInt32  ch1_c1_section_his0_hist06:16;
    };
}histogram_ich1_c1_section0_data_07_06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_section_his1_hist01:16;
        RBus_UInt32  ch1_c1_section_his1_hist00:16;
    };
}histogram_ich1_c1_section1_data_01_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_section_his1_hist03:16;
        RBus_UInt32  ch1_c1_section_his1_hist02:16;
    };
}histogram_ich1_c1_section1_data_03_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_section_his1_hist05:16;
        RBus_UInt32  ch1_c1_section_his1_hist04:16;
    };
}histogram_ich1_c1_section1_data_05_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_section_his1_hist07:16;
        RBus_UInt32  ch1_c1_section_his1_hist06:16;
    };
}histogram_ich1_c1_section1_data_07_06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  ich1_c0_mbist_hist_2p_bist_fail:1;
        RBus_UInt32  ich1_c1_mbist_hist_2p_bist_fail:1;
        RBus_UInt32  res2:2;
    };
}histogram_ich1_mbist_hist_2p_bist_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  ich1_c0_mbist_hist_1p_bist_fail:1;
        RBus_UInt32  ich1_c1_mbist_hist_1p_bist_fail:1;
        RBus_UInt32  res2:2;
    };
}histogram_ich1_mbist_hist_1p_bist_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  ich1_c0_mbist_hist_2p_drf_fail:1;
        RBus_UInt32  ich1_c1_mbist_hist_2p_drf_fail:1;
        RBus_UInt32  res2:2;
    };
}histogram_ich1_mbist_hist_2p_drf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  ich1_c0_mbist_hist_1p_drf_fail:1;
        RBus_UInt32  ich1_c1_mbist_hist_1p_drf_fail:1;
        RBus_UInt32  res2:2;
    };
}histogram_ich1_mbist_hist_1p_drf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  ich1_c0_mbist_hist_2p_bist_ls:1;
        RBus_UInt32  ich1_c1_mbist_hist_2p_bist_ls:1;
        RBus_UInt32  ich1_mbist_hist_2p_bist_testrwm:1;
        RBus_UInt32  ich1_c0_mbist_hist_2p_bist_dvse:1;
        RBus_UInt32  ich1_c1_mbist_hist_2p_bist_dvse:1;
        RBus_UInt32  res2:2;
    };
}histogram_ich1_mbist_hist_2p_bist_dvse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  ich1_c0_mbist_hist_1p_bist_ls:1;
        RBus_UInt32  ich1_c1_mbist_hist_1p_bist_ls:1;
        RBus_UInt32  ich1_c0_mbist_hist_1p_bist_dvse:1;
        RBus_UInt32  ich1_c1_mbist_hist_1p_bist_dvse:1;
        RBus_UInt32  res2:2;
    };
}histogram_ich1_mbist_hist_1p_bist_dvse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  ich1_c0_mbist_hist_2p_bist_dvs:4;
        RBus_UInt32  ich1_c1_mbist_hist_2p_bist_dvs:4;
        RBus_UInt32  res2:8;
    };
}histogram_ich1_mbist_hist_2p_bist_dvs_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  ich1_c0_mbist_hist_1p_bist_dvs:4;
        RBus_UInt32  ich1_c1_mbist_hist_1p_bist_dvs:4;
        RBus_UInt32  res2:8;
    };
}histogram_ich1_mbist_hist_1p_bist_dvs_RBUS;

#else //apply LITTLE_ENDIAN

//======HISTOGRAM register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ch1_his_even_odd_fld_sel:1;
        RBus_UInt32  ch1_his_even_odd_fld_en:1;
        RBus_UInt32  ch1_his_even_odd_pos_sel:1;
        RBus_UInt32  ch1_his_even_odd_pos_en:1;
        RBus_UInt32  ch1_his_mode_sel:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  ch1_his_offset:4;
        RBus_UInt32  ch1_his_shift_sel:3;
        RBus_UInt32  ch1_his_num_flds:4;
        RBus_UInt32  ch1_his_yuv_sel:2;
        RBus_UInt32  ch1_his_irq_en:1;
        RBus_UInt32  ch1_his_enable_histog:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  ch1_his_updatelockmode_en:1;
        RBus_UInt32  ch1_3d_en:1;
        RBus_UInt32  lr_select:1;
        RBus_UInt32  bin_mode:1;
        RBus_UInt32  i2rnd_histogram_sel:2;
        RBus_UInt32  res4:2;
    };
}histogram_ich1_hist_in_cselect_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_his_horstart:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  ch1_his_horend:13;
        RBus_UInt32  res2:3;
    };
}histogram_ich1_hist_in_range_hor_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_his_verstart:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  ch1_his_verend:13;
        RBus_UInt32  res2:3;
    };
}histogram_ich1_hist_in_range_ver_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_his_his_irq:1;
        RBus_UInt32  ch1_his_dcc_invalid:1;
        RBus_UInt32  i2rnd_histogram_sel:1;
        RBus_UInt32  res1:29;
    };
}histogram_ich1_hist_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_his_min_val:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  ch1_his_max_val:10;
        RBus_UInt32  res2:6;
    };
}histogram_ich1_hist_max_min_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bycolor_debug_mode:2;
        RBus_UInt32  res1:30;
    };
}histogram_ich1_bycolor_debug_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_his_sumval_high:9;
        RBus_UInt32  res1:23;
    };
}histogram_ich1_hist_sumval_high_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_his_sumval_low:24;
        RBus_UInt32  res1:8;
    };
}histogram_ich1_hist_sumval_low_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_lower_bound:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  ch1_c0_upper_bound:10;
        RBus_UInt32  res2:6;
    };
}histogram_ich1_c0_hist_bound_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_lower_bound_u:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  ch1_c0_upper_bound_u:10;
        RBus_UInt32  res2:6;
    };
}histogram_ich1_c0_hist_bound_u_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_lower_bound_v:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  ch1_c0_upper_bound_v:10;
        RBus_UInt32  res2:6;
    };
}histogram_ich1_c0_hist_bound_v_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_sram_read_consistent_flag:1;
        RBus_UInt32  ch1_sram_block:2;
        RBus_UInt32  ch1_sram_read:1;
        RBus_UInt32  res1:28;
    };
}histogram_ich1_hist_read_ctr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_hist00:16;
        RBus_UInt32  ch1_c0_hist01:16;
    };
}histogram_ich1_c0_hist_in_data_01_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_hist02:16;
        RBus_UInt32  ch1_c0_hist03:16;
    };
}histogram_ich1_c0_hist_in_data_03_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_hist04:16;
        RBus_UInt32  ch1_c0_hist05:16;
    };
}histogram_ich1_c0_hist_in_data_05_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_hist06:16;
        RBus_UInt32  ch1_c0_hist07:16;
    };
}histogram_ich1_c0_hist_in_data_07_06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_hist08:16;
        RBus_UInt32  ch1_c0_hist09:16;
    };
}histogram_ich1_c0_hist_in_data_09_08_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_hist10:16;
        RBus_UInt32  ch1_c0_hist11:16;
    };
}histogram_ich1_c0_hist_in_data_11_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_hist12:16;
        RBus_UInt32  ch1_c0_hist13:16;
    };
}histogram_ich1_c0_hist_in_data_13_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_hist14:16;
        RBus_UInt32  ch1_c0_hist15:16;
    };
}histogram_ich1_c0_hist_in_data_15_14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_hist16:16;
        RBus_UInt32  ch1_c0_hist17:16;
    };
}histogram_ich1_c0_hist_in_data_17_16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_hist18:16;
        RBus_UInt32  ch1_c0_hist19:16;
    };
}histogram_ich1_c0_hist_in_data_19_18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_hist20:16;
        RBus_UInt32  ch1_c0_hist21:16;
    };
}histogram_ich1_c0_hist_in_data_21_20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_hist22:16;
        RBus_UInt32  ch1_c0_hist23:16;
    };
}histogram_ich1_c0_hist_in_data_23_22_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_hist24:16;
        RBus_UInt32  ch1_c0_hist25:16;
    };
}histogram_ich1_c0_hist_in_data_25_24_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_hist26:16;
        RBus_UInt32  ch1_c0_hist27:16;
    };
}histogram_ich1_c0_hist_in_data_27_26_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_hist28:16;
        RBus_UInt32  ch1_c0_hist29:16;
    };
}histogram_ich1_c0_hist_in_data_29_28_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_hist30:16;
        RBus_UInt32  ch1_c0_hist31:16;
    };
}histogram_ich1_c0_hist_in_data_31_30_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_section0_bin_sel:7;
        RBus_UInt32  res1:9;
        RBus_UInt32  ch1_c0_section1_bin_sel:7;
        RBus_UInt32  res2:9;
    };
}histogram_ich1_c0_sectionhist_in_cselect_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_section_his0_hist00:16;
        RBus_UInt32  ch1_c0_section_his0_hist01:16;
    };
}histogram_ich1_c0_section0_data_01_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_section_his0_hist02:16;
        RBus_UInt32  ch1_c0_section_his0_hist03:16;
    };
}histogram_ich1_c0_section0_data_03_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_section_his0_hist04:16;
        RBus_UInt32  ch1_c0_section_his0_hist05:16;
    };
}histogram_ich1_c0_section0_data_05_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_section_his0_hist06:16;
        RBus_UInt32  ch1_c0_section_his0_hist07:16;
    };
}histogram_ich1_c0_section0_data_07_06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_section_his1_hist00:16;
        RBus_UInt32  ch1_c0_section_his1_hist01:16;
    };
}histogram_ich1_c0_section1_data_01_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_section_his1_hist02:16;
        RBus_UInt32  ch1_c0_section_his1_hist03:16;
    };
}histogram_ich1_c0_section1_data_03_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_section_his1_hist04:16;
        RBus_UInt32  ch1_c0_section_his1_hist05:16;
    };
}histogram_ich1_c0_section1_data_05_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c0_section_his1_hist06:16;
        RBus_UInt32  ch1_c0_section_his1_hist07:16;
    };
}histogram_ich1_c0_section1_data_07_06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_lower_bound:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  ch1_c1_upper_bound:10;
        RBus_UInt32  res2:6;
    };
}histogram_ich1_c1_hist_bound_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_lower_bound_u:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  ch1_c1_upper_bound_u:10;
        RBus_UInt32  res2:6;
    };
}histogram_ich1_c1_hist_bound_u_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_lower_bound_v:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  ch1_c1_upper_bound_v:10;
        RBus_UInt32  res2:6;
    };
}histogram_ich1_c1_hist_bound_v_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_hist00:16;
        RBus_UInt32  ch1_c1_hist01:16;
    };
}histogram_ich1_c1_hist_in_data_01_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_hist02:16;
        RBus_UInt32  ch1_c1_hist03:16;
    };
}histogram_ich1_c1_hist_in_data_03_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_hist04:16;
        RBus_UInt32  ch1_c1_hist05:16;
    };
}histogram_ich1_c1_hist_in_data_05_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_hist06:16;
        RBus_UInt32  ch1_c1_hist07:16;
    };
}histogram_ich1_c1_hist_in_data_07_06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_hist08:16;
        RBus_UInt32  ch1_c1_hist09:16;
    };
}histogram_ich1_c1_hist_in_data_09_08_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_hist10:16;
        RBus_UInt32  ch1_c1_hist11:16;
    };
}histogram_ich1_c1_hist_in_data_11_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_hist12:16;
        RBus_UInt32  ch1_c1_hist13:16;
    };
}histogram_ich1_c1_hist_in_data_13_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_hist14:16;
        RBus_UInt32  ch1_c1_hist15:16;
    };
}histogram_ich1_c1_hist_in_data_15_14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_hist16:16;
        RBus_UInt32  ch1_c1_hist17:16;
    };
}histogram_ich1_c1_hist_in_data_17_16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_hist18:16;
        RBus_UInt32  ch1_c1_hist19:16;
    };
}histogram_ich1_c1_hist_in_data_19_18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_hist20:16;
        RBus_UInt32  ch1_c1_hist21:16;
    };
}histogram_ich1_c1_hist_in_data_21_20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_hist22:16;
        RBus_UInt32  ch1_c1_hist23:16;
    };
}histogram_ich1_c1_hist_in_data_23_22_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_hist24:16;
        RBus_UInt32  ch1_c1_hist25:16;
    };
}histogram_ich1_c1_hist_in_data_25_24_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_hist26:16;
        RBus_UInt32  ch1_c1_hist27:16;
    };
}histogram_ich1_c1_hist_in_data_27_26_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_hist28:16;
        RBus_UInt32  ch1_c1_hist29:16;
    };
}histogram_ich1_c1_hist_in_data_29_28_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_hist30:16;
        RBus_UInt32  ch1_c1_hist31:16;
    };
}histogram_ich1_c1_hist_in_data_31_30_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_section0_bin_sel:7;
        RBus_UInt32  res1:9;
        RBus_UInt32  ch1_c1_section1_bin_sel:7;
        RBus_UInt32  res2:9;
    };
}histogram_ich1_c1_sectionhist_in_cselect_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_section_his0_hist00:16;
        RBus_UInt32  ch1_c1_section_his0_hist01:16;
    };
}histogram_ich1_c1_section0_data_01_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_section_his0_hist02:16;
        RBus_UInt32  ch1_c1_section_his0_hist03:16;
    };
}histogram_ich1_c1_section0_data_03_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_section_his0_hist04:16;
        RBus_UInt32  ch1_c1_section_his0_hist05:16;
    };
}histogram_ich1_c1_section0_data_05_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_section_his0_hist06:16;
        RBus_UInt32  ch1_c1_section_his0_hist07:16;
    };
}histogram_ich1_c1_section0_data_07_06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_section_his1_hist00:16;
        RBus_UInt32  ch1_c1_section_his1_hist01:16;
    };
}histogram_ich1_c1_section1_data_01_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_section_his1_hist02:16;
        RBus_UInt32  ch1_c1_section_his1_hist03:16;
    };
}histogram_ich1_c1_section1_data_03_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_section_his1_hist04:16;
        RBus_UInt32  ch1_c1_section_his1_hist05:16;
    };
}histogram_ich1_c1_section1_data_05_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_c1_section_his1_hist06:16;
        RBus_UInt32  ch1_c1_section_his1_hist07:16;
    };
}histogram_ich1_c1_section1_data_07_06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ich1_c1_mbist_hist_2p_bist_fail:1;
        RBus_UInt32  ich1_c0_mbist_hist_2p_bist_fail:1;
        RBus_UInt32  res2:28;
    };
}histogram_ich1_mbist_hist_2p_bist_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ich1_c1_mbist_hist_1p_bist_fail:1;
        RBus_UInt32  ich1_c0_mbist_hist_1p_bist_fail:1;
        RBus_UInt32  res2:28;
    };
}histogram_ich1_mbist_hist_1p_bist_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ich1_c1_mbist_hist_2p_drf_fail:1;
        RBus_UInt32  ich1_c0_mbist_hist_2p_drf_fail:1;
        RBus_UInt32  res2:28;
    };
}histogram_ich1_mbist_hist_2p_drf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ich1_c1_mbist_hist_1p_drf_fail:1;
        RBus_UInt32  ich1_c0_mbist_hist_1p_drf_fail:1;
        RBus_UInt32  res2:28;
    };
}histogram_ich1_mbist_hist_1p_drf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ich1_c1_mbist_hist_2p_bist_dvse:1;
        RBus_UInt32  ich1_c0_mbist_hist_2p_bist_dvse:1;
        RBus_UInt32  ich1_mbist_hist_2p_bist_testrwm:1;
        RBus_UInt32  ich1_c1_mbist_hist_2p_bist_ls:1;
        RBus_UInt32  ich1_c0_mbist_hist_2p_bist_ls:1;
        RBus_UInt32  res2:25;
    };
}histogram_ich1_mbist_hist_2p_bist_dvse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ich1_c1_mbist_hist_1p_bist_dvse:1;
        RBus_UInt32  ich1_c0_mbist_hist_1p_bist_dvse:1;
        RBus_UInt32  ich1_c1_mbist_hist_1p_bist_ls:1;
        RBus_UInt32  ich1_c0_mbist_hist_1p_bist_ls:1;
        RBus_UInt32  res2:26;
    };
}histogram_ich1_mbist_hist_1p_bist_dvse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  ich1_c1_mbist_hist_2p_bist_dvs:4;
        RBus_UInt32  ich1_c0_mbist_hist_2p_bist_dvs:4;
        RBus_UInt32  res2:16;
    };
}histogram_ich1_mbist_hist_2p_bist_dvs_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  ich1_c1_mbist_hist_1p_bist_dvs:4;
        RBus_UInt32  ich1_c0_mbist_hist_1p_bist_dvs:4;
        RBus_UInt32  res2:16;
    };
}histogram_ich1_mbist_hist_1p_bist_dvs_RBUS;




#endif 


#endif 
