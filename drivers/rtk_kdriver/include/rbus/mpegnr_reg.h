/**
* @file MacArthur5-DesignSpec-I-Domain_Mpegnr
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_MPEGNR_REG_H_
#define _RBUS_MPEGNR_REG_H_

#include "rbus_types.h"



//  MPEGNR Register Address
#define  MPEGNR_ICH1_blend_NR_Hor_step                                           0x18023820
#define  MPEGNR_ICH1_blend_NR_Hor_step_reg_addr                                  "0xB8023820"
#define  MPEGNR_ICH1_blend_NR_Hor_step_reg                                       0xB8023820
#define  MPEGNR_ICH1_blend_NR_Hor_step_inst_addr                                 "0x0000"
#define  set_MPEGNR_ICH1_blend_NR_Hor_step_reg(data)                             (*((volatile unsigned int*)MPEGNR_ICH1_blend_NR_Hor_step_reg)=data)
#define  get_MPEGNR_ICH1_blend_NR_Hor_step_reg                                   (*((volatile unsigned int*)MPEGNR_ICH1_blend_NR_Hor_step_reg))
#define  MPEGNR_ICH1_blend_NR_Hor_step_cp_mpghor_blend_range_shift               (30)
#define  MPEGNR_ICH1_blend_NR_Hor_step_cp_mpghor_blend_xini_shift                (16)
#define  MPEGNR_ICH1_blend_NR_Hor_step_cp_mpghor_blend_xstep_shift               (0)
#define  MPEGNR_ICH1_blend_NR_Hor_step_cp_mpghor_blend_range_mask                (0xC0000000)
#define  MPEGNR_ICH1_blend_NR_Hor_step_cp_mpghor_blend_xini_mask                 (0x00070000)
#define  MPEGNR_ICH1_blend_NR_Hor_step_cp_mpghor_blend_xstep_mask                (0x00007FFF)
#define  MPEGNR_ICH1_blend_NR_Hor_step_cp_mpghor_blend_range(data)               (0xC0000000&((data)<<30))
#define  MPEGNR_ICH1_blend_NR_Hor_step_cp_mpghor_blend_xini(data)                (0x00070000&((data)<<16))
#define  MPEGNR_ICH1_blend_NR_Hor_step_cp_mpghor_blend_xstep(data)               (0x00007FFF&(data))
#define  MPEGNR_ICH1_blend_NR_Hor_step_get_cp_mpghor_blend_range(data)           ((0xC0000000&(data))>>30)
#define  MPEGNR_ICH1_blend_NR_Hor_step_get_cp_mpghor_blend_xini(data)            ((0x00070000&(data))>>16)
#define  MPEGNR_ICH1_blend_NR_Hor_step_get_cp_mpghor_blend_xstep(data)           (0x00007FFF&(data))

#define  MPEGNR_ICH1_MPEGNR1                                                     0x18023824
#define  MPEGNR_ICH1_MPEGNR1_reg_addr                                            "0xB8023824"
#define  MPEGNR_ICH1_MPEGNR1_reg                                                 0xB8023824
#define  MPEGNR_ICH1_MPEGNR1_inst_addr                                           "0x0001"
#define  set_MPEGNR_ICH1_MPEGNR1_reg(data)                                       (*((volatile unsigned int*)MPEGNR_ICH1_MPEGNR1_reg)=data)
#define  get_MPEGNR_ICH1_MPEGNR1_reg                                             (*((volatile unsigned int*)MPEGNR_ICH1_MPEGNR1_reg))
#define  MPEGNR_ICH1_MPEGNR1_cp_mpgub_dec_sel_shift                              (31)
#define  MPEGNR_ICH1_MPEGNR1_cp_mpgub_difcmp_en_shift                            (28)
#define  MPEGNR_ICH1_MPEGNR1_cp_mpgub_difcen_en_shift                            (24)
#define  MPEGNR_ICH1_MPEGNR1_cp_mpgupperbound_x_shift                            (14)
#define  MPEGNR_ICH1_MPEGNR1_cp_mpgupperbound_offset_shift                       (6)
#define  MPEGNR_ICH1_MPEGNR1_cp_mpgupperbound_gain_shift                         (4)
#define  MPEGNR_ICH1_MPEGNR1_cp_mpgnr_filter_sel_shift                           (0)
#define  MPEGNR_ICH1_MPEGNR1_cp_mpgub_dec_sel_mask                               (0x80000000)
#define  MPEGNR_ICH1_MPEGNR1_cp_mpgub_difcmp_en_mask                             (0x70000000)
#define  MPEGNR_ICH1_MPEGNR1_cp_mpgub_difcen_en_mask                             (0x0F000000)
#define  MPEGNR_ICH1_MPEGNR1_cp_mpgupperbound_x_mask                             (0x00FFC000)
#define  MPEGNR_ICH1_MPEGNR1_cp_mpgupperbound_offset_mask                        (0x00003FC0)
#define  MPEGNR_ICH1_MPEGNR1_cp_mpgupperbound_gain_mask                          (0x00000030)
#define  MPEGNR_ICH1_MPEGNR1_cp_mpgnr_filter_sel_mask                            (0x00000007)
#define  MPEGNR_ICH1_MPEGNR1_cp_mpgub_dec_sel(data)                              (0x80000000&((data)<<31))
#define  MPEGNR_ICH1_MPEGNR1_cp_mpgub_difcmp_en(data)                            (0x70000000&((data)<<28))
#define  MPEGNR_ICH1_MPEGNR1_cp_mpgub_difcen_en(data)                            (0x0F000000&((data)<<24))
#define  MPEGNR_ICH1_MPEGNR1_cp_mpgupperbound_x(data)                            (0x00FFC000&((data)<<14))
#define  MPEGNR_ICH1_MPEGNR1_cp_mpgupperbound_offset(data)                       (0x00003FC0&((data)<<6))
#define  MPEGNR_ICH1_MPEGNR1_cp_mpgupperbound_gain(data)                         (0x00000030&((data)<<4))
#define  MPEGNR_ICH1_MPEGNR1_cp_mpgnr_filter_sel(data)                           (0x00000007&(data))
#define  MPEGNR_ICH1_MPEGNR1_get_cp_mpgub_dec_sel(data)                          ((0x80000000&(data))>>31)
#define  MPEGNR_ICH1_MPEGNR1_get_cp_mpgub_difcmp_en(data)                        ((0x70000000&(data))>>28)
#define  MPEGNR_ICH1_MPEGNR1_get_cp_mpgub_difcen_en(data)                        ((0x0F000000&(data))>>24)
#define  MPEGNR_ICH1_MPEGNR1_get_cp_mpgupperbound_x(data)                        ((0x00FFC000&(data))>>14)
#define  MPEGNR_ICH1_MPEGNR1_get_cp_mpgupperbound_offset(data)                   ((0x00003FC0&(data))>>6)
#define  MPEGNR_ICH1_MPEGNR1_get_cp_mpgupperbound_gain(data)                     ((0x00000030&(data))>>4)
#define  MPEGNR_ICH1_MPEGNR1_get_cp_mpgnr_filter_sel(data)                       (0x00000007&(data))

#define  MPEGNR_ICH1_MPEGNR_UB_delta1                                            0x18023828
#define  MPEGNR_ICH1_MPEGNR_UB_delta1_reg_addr                                   "0xB8023828"
#define  MPEGNR_ICH1_MPEGNR_UB_delta1_reg                                        0xB8023828
#define  MPEGNR_ICH1_MPEGNR_UB_delta1_inst_addr                                  "0x0002"
#define  set_MPEGNR_ICH1_MPEGNR_UB_delta1_reg(data)                              (*((volatile unsigned int*)MPEGNR_ICH1_MPEGNR_UB_delta1_reg)=data)
#define  get_MPEGNR_ICH1_MPEGNR_UB_delta1_reg                                    (*((volatile unsigned int*)MPEGNR_ICH1_MPEGNR_UB_delta1_reg))
#define  MPEGNR_ICH1_MPEGNR_UB_delta1_cp_mpgub_delta2_shift                      (16)
#define  MPEGNR_ICH1_MPEGNR_UB_delta1_cp_mpgub_delta1_shift                      (0)
#define  MPEGNR_ICH1_MPEGNR_UB_delta1_cp_mpgub_delta2_mask                       (0x03FF0000)
#define  MPEGNR_ICH1_MPEGNR_UB_delta1_cp_mpgub_delta1_mask                       (0x000003FF)
#define  MPEGNR_ICH1_MPEGNR_UB_delta1_cp_mpgub_delta2(data)                      (0x03FF0000&((data)<<16))
#define  MPEGNR_ICH1_MPEGNR_UB_delta1_cp_mpgub_delta1(data)                      (0x000003FF&(data))
#define  MPEGNR_ICH1_MPEGNR_UB_delta1_get_cp_mpgub_delta2(data)                  ((0x03FF0000&(data))>>16)
#define  MPEGNR_ICH1_MPEGNR_UB_delta1_get_cp_mpgub_delta1(data)                  (0x000003FF&(data))

#define  MPEGNR_ICH1_MPEGNR_UB_delta2                                            0x1802382C
#define  MPEGNR_ICH1_MPEGNR_UB_delta2_reg_addr                                   "0xB802382C"
#define  MPEGNR_ICH1_MPEGNR_UB_delta2_reg                                        0xB802382C
#define  MPEGNR_ICH1_MPEGNR_UB_delta2_inst_addr                                  "0x0003"
#define  set_MPEGNR_ICH1_MPEGNR_UB_delta2_reg(data)                              (*((volatile unsigned int*)MPEGNR_ICH1_MPEGNR_UB_delta2_reg)=data)
#define  get_MPEGNR_ICH1_MPEGNR_UB_delta2_reg                                    (*((volatile unsigned int*)MPEGNR_ICH1_MPEGNR_UB_delta2_reg))
#define  MPEGNR_ICH1_MPEGNR_UB_delta2_cp_mpgub_delta3_shift                      (0)
#define  MPEGNR_ICH1_MPEGNR_UB_delta2_cp_mpgub_delta3_mask                       (0x000003FF)
#define  MPEGNR_ICH1_MPEGNR_UB_delta2_cp_mpgub_delta3(data)                      (0x000003FF&(data))
#define  MPEGNR_ICH1_MPEGNR_UB_delta2_get_cp_mpgub_delta3(data)                  (0x000003FF&(data))

#define  MPEGNR_ICH1_MPEGNR_UB_Cen_Th                                            0x18023830
#define  MPEGNR_ICH1_MPEGNR_UB_Cen_Th_reg_addr                                   "0xB8023830"
#define  MPEGNR_ICH1_MPEGNR_UB_Cen_Th_reg                                        0xB8023830
#define  MPEGNR_ICH1_MPEGNR_UB_Cen_Th_inst_addr                                  "0x0004"
#define  set_MPEGNR_ICH1_MPEGNR_UB_Cen_Th_reg(data)                              (*((volatile unsigned int*)MPEGNR_ICH1_MPEGNR_UB_Cen_Th_reg)=data)
#define  get_MPEGNR_ICH1_MPEGNR_UB_Cen_Th_reg                                    (*((volatile unsigned int*)MPEGNR_ICH1_MPEGNR_UB_Cen_Th_reg))
#define  MPEGNR_ICH1_MPEGNR_UB_Cen_Th_cp_mpghor_diff_th_high_shift               (16)
#define  MPEGNR_ICH1_MPEGNR_UB_Cen_Th_cp_mpghor_diff_th_low_shift                (0)
#define  MPEGNR_ICH1_MPEGNR_UB_Cen_Th_cp_mpghor_diff_th_high_mask                (0x03FF0000)
#define  MPEGNR_ICH1_MPEGNR_UB_Cen_Th_cp_mpghor_diff_th_low_mask                 (0x000003FF)
#define  MPEGNR_ICH1_MPEGNR_UB_Cen_Th_cp_mpghor_diff_th_high(data)               (0x03FF0000&((data)<<16))
#define  MPEGNR_ICH1_MPEGNR_UB_Cen_Th_cp_mpghor_diff_th_low(data)                (0x000003FF&(data))
#define  MPEGNR_ICH1_MPEGNR_UB_Cen_Th_get_cp_mpghor_diff_th_high(data)           ((0x03FF0000&(data))>>16)
#define  MPEGNR_ICH1_MPEGNR_UB_Cen_Th_get_cp_mpghor_diff_th_low(data)            (0x000003FF&(data))

#define  MPEGNR_ICH1_MPEGNR2                                                     0x18023834
#define  MPEGNR_ICH1_MPEGNR2_reg_addr                                            "0xB8023834"
#define  MPEGNR_ICH1_MPEGNR2_reg                                                 0xB8023834
#define  MPEGNR_ICH1_MPEGNR2_inst_addr                                           "0x0005"
#define  set_MPEGNR_ICH1_MPEGNR2_reg(data)                                       (*((volatile unsigned int*)MPEGNR_ICH1_MPEGNR2_reg)=data)
#define  get_MPEGNR_ICH1_MPEGNR2_reg                                             (*((volatile unsigned int*)MPEGNR_ICH1_MPEGNR2_reg))
#define  MPEGNR_ICH1_MPEGNR2_cp_mpgdcgain_shift                                  (28)
#define  MPEGNR_ICH1_MPEGNR2_cp_mpgdcqp_shift                                    (16)
#define  MPEGNR_ICH1_MPEGNR2_cp_mpgfiltersel1_shift                              (9)
#define  MPEGNR_ICH1_MPEGNR2_cp_mpgidxmode_x_shift                               (7)
#define  MPEGNR_ICH1_MPEGNR2_cp_mpgidx_x_shift                                   (4)
#define  MPEGNR_ICH1_MPEGNR2_cp_mpegresultweight_x_shift                         (1)
#define  MPEGNR_ICH1_MPEGNR2_cp_mpegenable_x_shift                               (0)
#define  MPEGNR_ICH1_MPEGNR2_cp_mpgdcgain_mask                                   (0xF0000000)
#define  MPEGNR_ICH1_MPEGNR2_cp_mpgdcqp_mask                                     (0x00FF0000)
#define  MPEGNR_ICH1_MPEGNR2_cp_mpgfiltersel1_mask                               (0x00000200)
#define  MPEGNR_ICH1_MPEGNR2_cp_mpgidxmode_x_mask                                (0x00000080)
#define  MPEGNR_ICH1_MPEGNR2_cp_mpgidx_x_mask                                    (0x00000070)
#define  MPEGNR_ICH1_MPEGNR2_cp_mpegresultweight_x_mask                          (0x0000000E)
#define  MPEGNR_ICH1_MPEGNR2_cp_mpegenable_x_mask                                (0x00000001)
#define  MPEGNR_ICH1_MPEGNR2_cp_mpgdcgain(data)                                  (0xF0000000&((data)<<28))
#define  MPEGNR_ICH1_MPEGNR2_cp_mpgdcqp(data)                                    (0x00FF0000&((data)<<16))
#define  MPEGNR_ICH1_MPEGNR2_cp_mpgfiltersel1(data)                              (0x00000200&((data)<<9))
#define  MPEGNR_ICH1_MPEGNR2_cp_mpgidxmode_x(data)                               (0x00000080&((data)<<7))
#define  MPEGNR_ICH1_MPEGNR2_cp_mpgidx_x(data)                                   (0x00000070&((data)<<4))
#define  MPEGNR_ICH1_MPEGNR2_cp_mpegresultweight_x(data)                         (0x0000000E&((data)<<1))
#define  MPEGNR_ICH1_MPEGNR2_cp_mpegenable_x(data)                               (0x00000001&(data))
#define  MPEGNR_ICH1_MPEGNR2_get_cp_mpgdcgain(data)                              ((0xF0000000&(data))>>28)
#define  MPEGNR_ICH1_MPEGNR2_get_cp_mpgdcqp(data)                                ((0x00FF0000&(data))>>16)
#define  MPEGNR_ICH1_MPEGNR2_get_cp_mpgfiltersel1(data)                          ((0x00000200&(data))>>9)
#define  MPEGNR_ICH1_MPEGNR2_get_cp_mpgidxmode_x(data)                           ((0x00000080&(data))>>7)
#define  MPEGNR_ICH1_MPEGNR2_get_cp_mpgidx_x(data)                               ((0x00000070&(data))>>4)
#define  MPEGNR_ICH1_MPEGNR2_get_cp_mpegresultweight_x(data)                     ((0x0000000E&(data))>>1)
#define  MPEGNR_ICH1_MPEGNR2_get_cp_mpegenable_x(data)                           (0x00000001&(data))

#define  MPEGNR_ICH1_MPEGNR_UB_Cen_Gain                                          0x18023838
#define  MPEGNR_ICH1_MPEGNR_UB_Cen_Gain_reg_addr                                 "0xB8023838"
#define  MPEGNR_ICH1_MPEGNR_UB_Cen_Gain_reg                                      0xB8023838
#define  MPEGNR_ICH1_MPEGNR_UB_Cen_Gain_inst_addr                                "0x0006"
#define  set_MPEGNR_ICH1_MPEGNR_UB_Cen_Gain_reg(data)                            (*((volatile unsigned int*)MPEGNR_ICH1_MPEGNR_UB_Cen_Gain_reg)=data)
#define  get_MPEGNR_ICH1_MPEGNR_UB_Cen_Gain_reg                                  (*((volatile unsigned int*)MPEGNR_ICH1_MPEGNR_UB_Cen_Gain_reg))
#define  MPEGNR_ICH1_MPEGNR_UB_Cen_Gain_cp_mpghor_diff_gain_high_shift           (16)
#define  MPEGNR_ICH1_MPEGNR_UB_Cen_Gain_cp_mpghor_diff_gain_low_shift            (0)
#define  MPEGNR_ICH1_MPEGNR_UB_Cen_Gain_cp_mpghor_diff_gain_high_mask            (0x03FF0000)
#define  MPEGNR_ICH1_MPEGNR_UB_Cen_Gain_cp_mpghor_diff_gain_low_mask             (0x000003FF)
#define  MPEGNR_ICH1_MPEGNR_UB_Cen_Gain_cp_mpghor_diff_gain_high(data)           (0x03FF0000&((data)<<16))
#define  MPEGNR_ICH1_MPEGNR_UB_Cen_Gain_cp_mpghor_diff_gain_low(data)            (0x000003FF&(data))
#define  MPEGNR_ICH1_MPEGNR_UB_Cen_Gain_get_cp_mpghor_diff_gain_high(data)       ((0x03FF0000&(data))>>16)
#define  MPEGNR_ICH1_MPEGNR_UB_Cen_Gain_get_cp_mpghor_diff_gain_low(data)        (0x000003FF&(data))

#define  MPEGNR_ICH1_MPEGNR_UB_Dif_Cmp                                           0x1802383C
#define  MPEGNR_ICH1_MPEGNR_UB_Dif_Cmp_reg_addr                                  "0xB802383C"
#define  MPEGNR_ICH1_MPEGNR_UB_Dif_Cmp_reg                                       0xB802383C
#define  MPEGNR_ICH1_MPEGNR_UB_Dif_Cmp_inst_addr                                 "0x0007"
#define  set_MPEGNR_ICH1_MPEGNR_UB_Dif_Cmp_reg(data)                             (*((volatile unsigned int*)MPEGNR_ICH1_MPEGNR_UB_Dif_Cmp_reg)=data)
#define  get_MPEGNR_ICH1_MPEGNR_UB_Dif_Cmp_reg                                   (*((volatile unsigned int*)MPEGNR_ICH1_MPEGNR_UB_Dif_Cmp_reg))
#define  MPEGNR_ICH1_MPEGNR_UB_Dif_Cmp_cp_mpgtex_range_shift                     (30)
#define  MPEGNR_ICH1_MPEGNR_UB_Dif_Cmp_cp_mpgub_difcmp_offset_shift              (16)
#define  MPEGNR_ICH1_MPEGNR_UB_Dif_Cmp_cp_mpgub_difcmp_gain_shift                (0)
#define  MPEGNR_ICH1_MPEGNR_UB_Dif_Cmp_cp_mpgtex_range_mask                      (0xC0000000)
#define  MPEGNR_ICH1_MPEGNR_UB_Dif_Cmp_cp_mpgub_difcmp_offset_mask               (0x00FF0000)
#define  MPEGNR_ICH1_MPEGNR_UB_Dif_Cmp_cp_mpgub_difcmp_gain_mask                 (0x000003FF)
#define  MPEGNR_ICH1_MPEGNR_UB_Dif_Cmp_cp_mpgtex_range(data)                     (0xC0000000&((data)<<30))
#define  MPEGNR_ICH1_MPEGNR_UB_Dif_Cmp_cp_mpgub_difcmp_offset(data)              (0x00FF0000&((data)<<16))
#define  MPEGNR_ICH1_MPEGNR_UB_Dif_Cmp_cp_mpgub_difcmp_gain(data)                (0x000003FF&(data))
#define  MPEGNR_ICH1_MPEGNR_UB_Dif_Cmp_get_cp_mpgtex_range(data)                 ((0xC0000000&(data))>>30)
#define  MPEGNR_ICH1_MPEGNR_UB_Dif_Cmp_get_cp_mpgub_difcmp_offset(data)          ((0x00FF0000&(data))>>16)
#define  MPEGNR_ICH1_MPEGNR_UB_Dif_Cmp_get_cp_mpgub_difcmp_gain(data)            (0x000003FF&(data))

#define  MPEGNR_ICH1_Hist_Blking_Hor_Range                                       0x18023840
#define  MPEGNR_ICH1_Hist_Blking_Hor_Range_reg_addr                              "0xB8023840"
#define  MPEGNR_ICH1_Hist_Blking_Hor_Range_reg                                   0xB8023840
#define  MPEGNR_ICH1_Hist_Blking_Hor_Range_inst_addr                             "0x0008"
#define  set_MPEGNR_ICH1_Hist_Blking_Hor_Range_reg(data)                         (*((volatile unsigned int*)MPEGNR_ICH1_Hist_Blking_Hor_Range_reg)=data)
#define  get_MPEGNR_ICH1_Hist_Blking_Hor_Range_reg                               (*((volatile unsigned int*)MPEGNR_ICH1_Hist_Blking_Hor_Range_reg))
#define  MPEGNR_ICH1_Hist_Blking_Hor_Range_cp_histhorend_shift                   (16)
#define  MPEGNR_ICH1_Hist_Blking_Hor_Range_cp_histhorstart_shift                 (0)
#define  MPEGNR_ICH1_Hist_Blking_Hor_Range_cp_histhorend_mask                    (0x3FFF0000)
#define  MPEGNR_ICH1_Hist_Blking_Hor_Range_cp_histhorstart_mask                  (0x00003FFF)
#define  MPEGNR_ICH1_Hist_Blking_Hor_Range_cp_histhorend(data)                   (0x3FFF0000&((data)<<16))
#define  MPEGNR_ICH1_Hist_Blking_Hor_Range_cp_histhorstart(data)                 (0x00003FFF&(data))
#define  MPEGNR_ICH1_Hist_Blking_Hor_Range_get_cp_histhorend(data)               ((0x3FFF0000&(data))>>16)
#define  MPEGNR_ICH1_Hist_Blking_Hor_Range_get_cp_histhorstart(data)             (0x00003FFF&(data))

#define  MPEGNR_ICH1_Hist_Blking_Ver_Range                                       0x18023844
#define  MPEGNR_ICH1_Hist_Blking_Ver_Range_reg_addr                              "0xB8023844"
#define  MPEGNR_ICH1_Hist_Blking_Ver_Range_reg                                   0xB8023844
#define  MPEGNR_ICH1_Hist_Blking_Ver_Range_inst_addr                             "0x0009"
#define  set_MPEGNR_ICH1_Hist_Blking_Ver_Range_reg(data)                         (*((volatile unsigned int*)MPEGNR_ICH1_Hist_Blking_Ver_Range_reg)=data)
#define  get_MPEGNR_ICH1_Hist_Blking_Ver_Range_reg                               (*((volatile unsigned int*)MPEGNR_ICH1_Hist_Blking_Ver_Range_reg))
#define  MPEGNR_ICH1_Hist_Blking_Ver_Range_cp_histverend_shift                   (16)
#define  MPEGNR_ICH1_Hist_Blking_Ver_Range_cp_histverstart_shift                 (0)
#define  MPEGNR_ICH1_Hist_Blking_Ver_Range_cp_histverend_mask                    (0x3FFF0000)
#define  MPEGNR_ICH1_Hist_Blking_Ver_Range_cp_histverstart_mask                  (0x00003FFF)
#define  MPEGNR_ICH1_Hist_Blking_Ver_Range_cp_histverend(data)                   (0x3FFF0000&((data)<<16))
#define  MPEGNR_ICH1_Hist_Blking_Ver_Range_cp_histverstart(data)                 (0x00003FFF&(data))
#define  MPEGNR_ICH1_Hist_Blking_Ver_Range_get_cp_histverend(data)               ((0x3FFF0000&(data))>>16)
#define  MPEGNR_ICH1_Hist_Blking_Ver_Range_get_cp_histverstart(data)             (0x00003FFF&(data))

#define  MPEGNR_ICH1_MPEGStart                                                   0x18023848
#define  MPEGNR_ICH1_MPEGStart_reg_addr                                          "0xB8023848"
#define  MPEGNR_ICH1_MPEGStart_reg                                               0xB8023848
#define  MPEGNR_ICH1_MPEGStart_inst_addr                                         "0x000A"
#define  set_MPEGNR_ICH1_MPEGStart_reg(data)                                     (*((volatile unsigned int*)MPEGNR_ICH1_MPEGStart_reg)=data)
#define  get_MPEGNR_ICH1_MPEGStart_reg                                           (*((volatile unsigned int*)MPEGNR_ICH1_MPEGStart_reg))
#define  MPEGNR_ICH1_MPEGStart_cp_histhoren_shift                                (0)
#define  MPEGNR_ICH1_MPEGStart_cp_histhoren_mask                                 (0x00000001)
#define  MPEGNR_ICH1_MPEGStart_cp_histhoren(data)                                (0x00000001&(data))
#define  MPEGNR_ICH1_MPEGStart_get_cp_histhoren(data)                            (0x00000001&(data))

#define  MPEGNR_ICH1_det_Hist_Hor_step                                           0x1802385C
#define  MPEGNR_ICH1_det_Hist_Hor_step_reg_addr                                  "0xB802385C"
#define  MPEGNR_ICH1_det_Hist_Hor_step_reg                                       0xB802385C
#define  MPEGNR_ICH1_det_Hist_Hor_step_inst_addr                                 "0x000B"
#define  set_MPEGNR_ICH1_det_Hist_Hor_step_reg(data)                             (*((volatile unsigned int*)MPEGNR_ICH1_det_Hist_Hor_step_reg)=data)
#define  get_MPEGNR_ICH1_det_Hist_Hor_step_reg                                   (*((volatile unsigned int*)MPEGNR_ICH1_det_Hist_Hor_step_reg))
#define  MPEGNR_ICH1_det_Hist_Hor_step_cp_histhor_det_xini_shift                 (16)
#define  MPEGNR_ICH1_det_Hist_Hor_step_cp_histhor_det_xstep_shift                (0)
#define  MPEGNR_ICH1_det_Hist_Hor_step_cp_histhor_det_xini_mask                  (0x00070000)
#define  MPEGNR_ICH1_det_Hist_Hor_step_cp_histhor_det_xstep_mask                 (0x00007FFF)
#define  MPEGNR_ICH1_det_Hist_Hor_step_cp_histhor_det_xini(data)                 (0x00070000&((data)<<16))
#define  MPEGNR_ICH1_det_Hist_Hor_step_cp_histhor_det_xstep(data)                (0x00007FFF&(data))
#define  MPEGNR_ICH1_det_Hist_Hor_step_get_cp_histhor_det_xini(data)             ((0x00070000&(data))>>16)
#define  MPEGNR_ICH1_det_Hist_Hor_step_get_cp_histhor_det_xstep(data)            (0x00007FFF&(data))

#define  MPEGNR_ICH1_det_Hist_Hor_thd                                            0x18023860
#define  MPEGNR_ICH1_det_Hist_Hor_thd_reg_addr                                   "0xB8023860"
#define  MPEGNR_ICH1_det_Hist_Hor_thd_reg                                        0xB8023860
#define  MPEGNR_ICH1_det_Hist_Hor_thd_inst_addr                                  "0x000C"
#define  set_MPEGNR_ICH1_det_Hist_Hor_thd_reg(data)                              (*((volatile unsigned int*)MPEGNR_ICH1_det_Hist_Hor_thd_reg)=data)
#define  get_MPEGNR_ICH1_det_Hist_Hor_thd_reg                                    (*((volatile unsigned int*)MPEGNR_ICH1_det_Hist_Hor_thd_reg))
#define  MPEGNR_ICH1_det_Hist_Hor_thd_cp_histhor_diff_th_high_shift              (16)
#define  MPEGNR_ICH1_det_Hist_Hor_thd_cp_histhor_diff_th_low_shift               (0)
#define  MPEGNR_ICH1_det_Hist_Hor_thd_cp_histhor_diff_th_high_mask               (0x00FF0000)
#define  MPEGNR_ICH1_det_Hist_Hor_thd_cp_histhor_diff_th_low_mask                (0x000000FF)
#define  MPEGNR_ICH1_det_Hist_Hor_thd_cp_histhor_diff_th_high(data)              (0x00FF0000&((data)<<16))
#define  MPEGNR_ICH1_det_Hist_Hor_thd_cp_histhor_diff_th_low(data)               (0x000000FF&(data))
#define  MPEGNR_ICH1_det_Hist_Hor_thd_get_cp_histhor_diff_th_high(data)          ((0x00FF0000&(data))>>16)
#define  MPEGNR_ICH1_det_Hist_Hor_thd_get_cp_histhor_diff_th_low(data)           (0x000000FF&(data))

#define  MPEGNR_ICH1_det_Hist_Hor_dbg                                            0x18023864
#define  MPEGNR_ICH1_det_Hist_Hor_dbg_reg_addr                                   "0xB8023864"
#define  MPEGNR_ICH1_det_Hist_Hor_dbg_reg                                        0xB8023864
#define  MPEGNR_ICH1_det_Hist_Hor_dbg_inst_addr                                  "0x000D"
#define  set_MPEGNR_ICH1_det_Hist_Hor_dbg_reg(data)                              (*((volatile unsigned int*)MPEGNR_ICH1_det_Hist_Hor_dbg_reg)=data)
#define  get_MPEGNR_ICH1_det_Hist_Hor_dbg_reg                                    (*((volatile unsigned int*)MPEGNR_ICH1_det_Hist_Hor_dbg_reg))
#define  MPEGNR_ICH1_det_Hist_Hor_dbg_cp_histhor_debug_en_shift                  (4)
#define  MPEGNR_ICH1_det_Hist_Hor_dbg_cp_histhor_dbg_mpgidx_shift                (0)
#define  MPEGNR_ICH1_det_Hist_Hor_dbg_cp_histhor_debug_en_mask                   (0x00000010)
#define  MPEGNR_ICH1_det_Hist_Hor_dbg_cp_histhor_dbg_mpgidx_mask                 (0x00000007)
#define  MPEGNR_ICH1_det_Hist_Hor_dbg_cp_histhor_debug_en(data)                  (0x00000010&((data)<<4))
#define  MPEGNR_ICH1_det_Hist_Hor_dbg_cp_histhor_dbg_mpgidx(data)                (0x00000007&(data))
#define  MPEGNR_ICH1_det_Hist_Hor_dbg_get_cp_histhor_debug_en(data)              ((0x00000010&(data))>>4)
#define  MPEGNR_ICH1_det_Hist_Hor_dbg_get_cp_histhor_dbg_mpgidx(data)            (0x00000007&(data))

#define  MPEGNR_FSYNC_GENERAL_CTRL1                                              0x180238A0
#define  MPEGNR_FSYNC_GENERAL_CTRL1_reg_addr                                     "0xB80238A0"
#define  MPEGNR_FSYNC_GENERAL_CTRL1_reg                                          0xB80238A0
#define  MPEGNR_FSYNC_GENERAL_CTRL1_inst_addr                                    "0x000E"
#define  set_MPEGNR_FSYNC_GENERAL_CTRL1_reg(data)                                (*((volatile unsigned int*)MPEGNR_FSYNC_GENERAL_CTRL1_reg)=data)
#define  get_MPEGNR_FSYNC_GENERAL_CTRL1_reg                                      (*((volatile unsigned int*)MPEGNR_FSYNC_GENERAL_CTRL1_reg))
#define  MPEGNR_FSYNC_GENERAL_CTRL1_fsync_general_standard_num_shift             (12)
#define  MPEGNR_FSYNC_GENERAL_CTRL1_fsync_general_en_shift                       (5)
#define  MPEGNR_FSYNC_GENERAL_CTRL1_fsync_general_line_num_shift                 (0)
#define  MPEGNR_FSYNC_GENERAL_CTRL1_fsync_general_standard_num_mask              (0x1FFFF000)
#define  MPEGNR_FSYNC_GENERAL_CTRL1_fsync_general_en_mask                        (0x00000020)
#define  MPEGNR_FSYNC_GENERAL_CTRL1_fsync_general_line_num_mask                  (0x0000001F)
#define  MPEGNR_FSYNC_GENERAL_CTRL1_fsync_general_standard_num(data)             (0x1FFFF000&((data)<<12))
#define  MPEGNR_FSYNC_GENERAL_CTRL1_fsync_general_en(data)                       (0x00000020&((data)<<5))
#define  MPEGNR_FSYNC_GENERAL_CTRL1_fsync_general_line_num(data)                 (0x0000001F&(data))
#define  MPEGNR_FSYNC_GENERAL_CTRL1_get_fsync_general_standard_num(data)         ((0x1FFFF000&(data))>>12)
#define  MPEGNR_FSYNC_GENERAL_CTRL1_get_fsync_general_en(data)                   ((0x00000020&(data))>>5)
#define  MPEGNR_FSYNC_GENERAL_CTRL1_get_fsync_general_line_num(data)             (0x0000001F&(data))

#define  MPEGNR_FSYNC_GENERAL_CTRL2                                              0x180238A4
#define  MPEGNR_FSYNC_GENERAL_CTRL2_reg_addr                                     "0xB80238A4"
#define  MPEGNR_FSYNC_GENERAL_CTRL2_reg                                          0xB80238A4
#define  MPEGNR_FSYNC_GENERAL_CTRL2_inst_addr                                    "0x000F"
#define  set_MPEGNR_FSYNC_GENERAL_CTRL2_reg(data)                                (*((volatile unsigned int*)MPEGNR_FSYNC_GENERAL_CTRL2_reg)=data)
#define  get_MPEGNR_FSYNC_GENERAL_CTRL2_reg                                      (*((volatile unsigned int*)MPEGNR_FSYNC_GENERAL_CTRL2_reg))
#define  MPEGNR_FSYNC_GENERAL_CTRL2_fsync_debug_en_shift                         (31)
#define  MPEGNR_FSYNC_GENERAL_CTRL2_fsync_general_delta_ratio_shift              (0)
#define  MPEGNR_FSYNC_GENERAL_CTRL2_fsync_debug_en_mask                          (0x80000000)
#define  MPEGNR_FSYNC_GENERAL_CTRL2_fsync_general_delta_ratio_mask               (0x00001FFF)
#define  MPEGNR_FSYNC_GENERAL_CTRL2_fsync_debug_en(data)                         (0x80000000&((data)<<31))
#define  MPEGNR_FSYNC_GENERAL_CTRL2_fsync_general_delta_ratio(data)              (0x00001FFF&(data))
#define  MPEGNR_FSYNC_GENERAL_CTRL2_get_fsync_debug_en(data)                     ((0x80000000&(data))>>31)
#define  MPEGNR_FSYNC_GENERAL_CTRL2_get_fsync_general_delta_ratio(data)          (0x00001FFF&(data))

#define  MPEGNR_FSYNC_GENERAL_CTRL3                                              0x180238A8
#define  MPEGNR_FSYNC_GENERAL_CTRL3_reg_addr                                     "0xB80238A8"
#define  MPEGNR_FSYNC_GENERAL_CTRL3_reg                                          0xB80238A8
#define  MPEGNR_FSYNC_GENERAL_CTRL3_inst_addr                                    "0x0010"
#define  set_MPEGNR_FSYNC_GENERAL_CTRL3_reg(data)                                (*((volatile unsigned int*)MPEGNR_FSYNC_GENERAL_CTRL3_reg)=data)
#define  get_MPEGNR_FSYNC_GENERAL_CTRL3_reg                                      (*((volatile unsigned int*)MPEGNR_FSYNC_GENERAL_CTRL3_reg))
#define  MPEGNR_FSYNC_GENERAL_CTRL3_measure_result_tmp_shift                     (15)
#define  MPEGNR_FSYNC_GENERAL_CTRL3_delta_trunc_shift                            (0)
#define  MPEGNR_FSYNC_GENERAL_CTRL3_measure_result_tmp_mask                      (0xFFFF8000)
#define  MPEGNR_FSYNC_GENERAL_CTRL3_delta_trunc_mask                             (0x00007FFF)
#define  MPEGNR_FSYNC_GENERAL_CTRL3_measure_result_tmp(data)                     (0xFFFF8000&((data)<<15))
#define  MPEGNR_FSYNC_GENERAL_CTRL3_delta_trunc(data)                            (0x00007FFF&(data))
#define  MPEGNR_FSYNC_GENERAL_CTRL3_get_measure_result_tmp(data)                 ((0xFFFF8000&(data))>>15)
#define  MPEGNR_FSYNC_GENERAL_CTRL3_get_delta_trunc(data)                        (0x00007FFF&(data))

#define  MPEGNR_FSYNC_GENERAL_CTRL4                                              0x180238AC
#define  MPEGNR_FSYNC_GENERAL_CTRL4_reg_addr                                     "0xB80238AC"
#define  MPEGNR_FSYNC_GENERAL_CTRL4_reg                                          0xB80238AC
#define  MPEGNR_FSYNC_GENERAL_CTRL4_inst_addr                                    "0x0011"
#define  set_MPEGNR_FSYNC_GENERAL_CTRL4_reg(data)                                (*((volatile unsigned int*)MPEGNR_FSYNC_GENERAL_CTRL4_reg)=data)
#define  get_MPEGNR_FSYNC_GENERAL_CTRL4_reg                                      (*((volatile unsigned int*)MPEGNR_FSYNC_GENERAL_CTRL4_reg))
#define  MPEGNR_FSYNC_GENERAL_CTRL4_measult_result_shift                         (0)
#define  MPEGNR_FSYNC_GENERAL_CTRL4_measult_result_mask                          (0xFFFFFFFF)
#define  MPEGNR_FSYNC_GENERAL_CTRL4_measult_result(data)                         (0xFFFFFFFF&(data))
#define  MPEGNR_FSYNC_GENERAL_CTRL4_get_measult_result(data)                     (0xFFFFFFFF&(data))

#define  MPEGNR_ICH1_AccessData_CTRL_PK                                          0x180238B0
#define  MPEGNR_ICH1_AccessData_CTRL_PK_reg_addr                                 "0xB80238B0"
#define  MPEGNR_ICH1_AccessData_CTRL_PK_reg                                      0xB80238B0
#define  MPEGNR_ICH1_AccessData_CTRL_PK_inst_addr                                "0x0012"
#define  set_MPEGNR_ICH1_AccessData_CTRL_PK_reg(data)                            (*((volatile unsigned int*)MPEGNR_ICH1_AccessData_CTRL_PK_reg)=data)
#define  get_MPEGNR_ICH1_AccessData_CTRL_PK_reg                                  (*((volatile unsigned int*)MPEGNR_ICH1_AccessData_CTRL_PK_reg))
#define  MPEGNR_ICH1_AccessData_CTRL_PK_write_en_shift                           (1)
#define  MPEGNR_ICH1_AccessData_CTRL_PK_read_en_shift                            (0)
#define  MPEGNR_ICH1_AccessData_CTRL_PK_write_en_mask                            (0x00000002)
#define  MPEGNR_ICH1_AccessData_CTRL_PK_read_en_mask                             (0x00000001)
#define  MPEGNR_ICH1_AccessData_CTRL_PK_write_en(data)                           (0x00000002&((data)<<1))
#define  MPEGNR_ICH1_AccessData_CTRL_PK_read_en(data)                            (0x00000001&(data))
#define  MPEGNR_ICH1_AccessData_CTRL_PK_get_write_en(data)                       ((0x00000002&(data))>>1)
#define  MPEGNR_ICH1_AccessData_CTRL_PK_get_read_en(data)                        (0x00000001&(data))

#define  MPEGNR_ICH1_AccessData_PosCtrl_PK                                       0x180238B4
#define  MPEGNR_ICH1_AccessData_PosCtrl_PK_reg_addr                              "0xB80238B4"
#define  MPEGNR_ICH1_AccessData_PosCtrl_PK_reg                                   0xB80238B4
#define  MPEGNR_ICH1_AccessData_PosCtrl_PK_inst_addr                             "0x0013"
#define  set_MPEGNR_ICH1_AccessData_PosCtrl_PK_reg(data)                         (*((volatile unsigned int*)MPEGNR_ICH1_AccessData_PosCtrl_PK_reg)=data)
#define  get_MPEGNR_ICH1_AccessData_PosCtrl_PK_reg                               (*((volatile unsigned int*)MPEGNR_ICH1_AccessData_PosCtrl_PK_reg))
#define  MPEGNR_ICH1_AccessData_PosCtrl_PK_starty_shift                          (16)
#define  MPEGNR_ICH1_AccessData_PosCtrl_PK_startx_shift                          (0)
#define  MPEGNR_ICH1_AccessData_PosCtrl_PK_starty_mask                           (0x3FFF0000)
#define  MPEGNR_ICH1_AccessData_PosCtrl_PK_startx_mask                           (0x00003FFF)
#define  MPEGNR_ICH1_AccessData_PosCtrl_PK_starty(data)                          (0x3FFF0000&((data)<<16))
#define  MPEGNR_ICH1_AccessData_PosCtrl_PK_startx(data)                          (0x00003FFF&(data))
#define  MPEGNR_ICH1_AccessData_PosCtrl_PK_get_starty(data)                      ((0x3FFF0000&(data))>>16)
#define  MPEGNR_ICH1_AccessData_PosCtrl_PK_get_startx(data)                      (0x00003FFF&(data))

#define  MPEGNR_ICH1_ReadData_DATA_Y1_PK                                         0x180238B8
#define  MPEGNR_ICH1_ReadData_DATA_Y1_PK_reg_addr                                "0xB80238B8"
#define  MPEGNR_ICH1_ReadData_DATA_Y1_PK_reg                                     0xB80238B8
#define  MPEGNR_ICH1_ReadData_DATA_Y1_PK_inst_addr                               "0x0014"
#define  set_MPEGNR_ICH1_ReadData_DATA_Y1_PK_reg(data)                           (*((volatile unsigned int*)MPEGNR_ICH1_ReadData_DATA_Y1_PK_reg)=data)
#define  get_MPEGNR_ICH1_ReadData_DATA_Y1_PK_reg                                 (*((volatile unsigned int*)MPEGNR_ICH1_ReadData_DATA_Y1_PK_reg))
#define  MPEGNR_ICH1_ReadData_DATA_Y1_PK_y01_shift                               (16)
#define  MPEGNR_ICH1_ReadData_DATA_Y1_PK_y00_shift                               (0)
#define  MPEGNR_ICH1_ReadData_DATA_Y1_PK_y01_mask                                (0x03FF0000)
#define  MPEGNR_ICH1_ReadData_DATA_Y1_PK_y00_mask                                (0x000003FF)
#define  MPEGNR_ICH1_ReadData_DATA_Y1_PK_y01(data)                               (0x03FF0000&((data)<<16))
#define  MPEGNR_ICH1_ReadData_DATA_Y1_PK_y00(data)                               (0x000003FF&(data))
#define  MPEGNR_ICH1_ReadData_DATA_Y1_PK_get_y01(data)                           ((0x03FF0000&(data))>>16)
#define  MPEGNR_ICH1_ReadData_DATA_Y1_PK_get_y00(data)                           (0x000003FF&(data))

#define  MPEGNR_ICH1_ReadData_DATA_Y2_PK                                         0x180238BC
#define  MPEGNR_ICH1_ReadData_DATA_Y2_PK_reg_addr                                "0xB80238BC"
#define  MPEGNR_ICH1_ReadData_DATA_Y2_PK_reg                                     0xB80238BC
#define  MPEGNR_ICH1_ReadData_DATA_Y2_PK_inst_addr                               "0x0015"
#define  set_MPEGNR_ICH1_ReadData_DATA_Y2_PK_reg(data)                           (*((volatile unsigned int*)MPEGNR_ICH1_ReadData_DATA_Y2_PK_reg)=data)
#define  get_MPEGNR_ICH1_ReadData_DATA_Y2_PK_reg                                 (*((volatile unsigned int*)MPEGNR_ICH1_ReadData_DATA_Y2_PK_reg))
#define  MPEGNR_ICH1_ReadData_DATA_Y2_PK_y11_shift                               (16)
#define  MPEGNR_ICH1_ReadData_DATA_Y2_PK_y10_shift                               (0)
#define  MPEGNR_ICH1_ReadData_DATA_Y2_PK_y11_mask                                (0x03FF0000)
#define  MPEGNR_ICH1_ReadData_DATA_Y2_PK_y10_mask                                (0x000003FF)
#define  MPEGNR_ICH1_ReadData_DATA_Y2_PK_y11(data)                               (0x03FF0000&((data)<<16))
#define  MPEGNR_ICH1_ReadData_DATA_Y2_PK_y10(data)                               (0x000003FF&(data))
#define  MPEGNR_ICH1_ReadData_DATA_Y2_PK_get_y11(data)                           ((0x03FF0000&(data))>>16)
#define  MPEGNR_ICH1_ReadData_DATA_Y2_PK_get_y10(data)                           (0x000003FF&(data))

#define  MPEGNR_ICH1_ReadData_DATA_C1_PK                                         0x180238C0
#define  MPEGNR_ICH1_ReadData_DATA_C1_PK_reg_addr                                "0xB80238C0"
#define  MPEGNR_ICH1_ReadData_DATA_C1_PK_reg                                     0xB80238C0
#define  MPEGNR_ICH1_ReadData_DATA_C1_PK_inst_addr                               "0x0016"
#define  set_MPEGNR_ICH1_ReadData_DATA_C1_PK_reg(data)                           (*((volatile unsigned int*)MPEGNR_ICH1_ReadData_DATA_C1_PK_reg)=data)
#define  get_MPEGNR_ICH1_ReadData_DATA_C1_PK_reg                                 (*((volatile unsigned int*)MPEGNR_ICH1_ReadData_DATA_C1_PK_reg))
#define  MPEGNR_ICH1_ReadData_DATA_C1_PK_v00_shift                               (16)
#define  MPEGNR_ICH1_ReadData_DATA_C1_PK_u00_shift                               (0)
#define  MPEGNR_ICH1_ReadData_DATA_C1_PK_v00_mask                                (0x03FF0000)
#define  MPEGNR_ICH1_ReadData_DATA_C1_PK_u00_mask                                (0x000003FF)
#define  MPEGNR_ICH1_ReadData_DATA_C1_PK_v00(data)                               (0x03FF0000&((data)<<16))
#define  MPEGNR_ICH1_ReadData_DATA_C1_PK_u00(data)                               (0x000003FF&(data))
#define  MPEGNR_ICH1_ReadData_DATA_C1_PK_get_v00(data)                           ((0x03FF0000&(data))>>16)
#define  MPEGNR_ICH1_ReadData_DATA_C1_PK_get_u00(data)                           (0x000003FF&(data))

#define  MPEGNR_ICH1_ReadData_DATA_C2_PK                                         0x180238C4
#define  MPEGNR_ICH1_ReadData_DATA_C2_PK_reg_addr                                "0xB80238C4"
#define  MPEGNR_ICH1_ReadData_DATA_C2_PK_reg                                     0xB80238C4
#define  MPEGNR_ICH1_ReadData_DATA_C2_PK_inst_addr                               "0x0017"
#define  set_MPEGNR_ICH1_ReadData_DATA_C2_PK_reg(data)                           (*((volatile unsigned int*)MPEGNR_ICH1_ReadData_DATA_C2_PK_reg)=data)
#define  get_MPEGNR_ICH1_ReadData_DATA_C2_PK_reg                                 (*((volatile unsigned int*)MPEGNR_ICH1_ReadData_DATA_C2_PK_reg))
#define  MPEGNR_ICH1_ReadData_DATA_C2_PK_v01_shift                               (16)
#define  MPEGNR_ICH1_ReadData_DATA_C2_PK_u01_shift                               (0)
#define  MPEGNR_ICH1_ReadData_DATA_C2_PK_v01_mask                                (0x03FF0000)
#define  MPEGNR_ICH1_ReadData_DATA_C2_PK_u01_mask                                (0x000003FF)
#define  MPEGNR_ICH1_ReadData_DATA_C2_PK_v01(data)                               (0x03FF0000&((data)<<16))
#define  MPEGNR_ICH1_ReadData_DATA_C2_PK_u01(data)                               (0x000003FF&(data))
#define  MPEGNR_ICH1_ReadData_DATA_C2_PK_get_v01(data)                           ((0x03FF0000&(data))>>16)
#define  MPEGNR_ICH1_ReadData_DATA_C2_PK_get_u01(data)                           (0x000003FF&(data))

#define  MPEGNR_ICH1_ReadData_DATA_C3_PK                                         0x180238C8
#define  MPEGNR_ICH1_ReadData_DATA_C3_PK_reg_addr                                "0xB80238C8"
#define  MPEGNR_ICH1_ReadData_DATA_C3_PK_reg                                     0xB80238C8
#define  MPEGNR_ICH1_ReadData_DATA_C3_PK_inst_addr                               "0x0018"
#define  set_MPEGNR_ICH1_ReadData_DATA_C3_PK_reg(data)                           (*((volatile unsigned int*)MPEGNR_ICH1_ReadData_DATA_C3_PK_reg)=data)
#define  get_MPEGNR_ICH1_ReadData_DATA_C3_PK_reg                                 (*((volatile unsigned int*)MPEGNR_ICH1_ReadData_DATA_C3_PK_reg))
#define  MPEGNR_ICH1_ReadData_DATA_C3_PK_v10_shift                               (16)
#define  MPEGNR_ICH1_ReadData_DATA_C3_PK_u10_shift                               (0)
#define  MPEGNR_ICH1_ReadData_DATA_C3_PK_v10_mask                                (0x03FF0000)
#define  MPEGNR_ICH1_ReadData_DATA_C3_PK_u10_mask                                (0x000003FF)
#define  MPEGNR_ICH1_ReadData_DATA_C3_PK_v10(data)                               (0x03FF0000&((data)<<16))
#define  MPEGNR_ICH1_ReadData_DATA_C3_PK_u10(data)                               (0x000003FF&(data))
#define  MPEGNR_ICH1_ReadData_DATA_C3_PK_get_v10(data)                           ((0x03FF0000&(data))>>16)
#define  MPEGNR_ICH1_ReadData_DATA_C3_PK_get_u10(data)                           (0x000003FF&(data))

#define  MPEGNR_ICH1_ReadData_DATA_C4_PK                                         0x180238CC
#define  MPEGNR_ICH1_ReadData_DATA_C4_PK_reg_addr                                "0xB80238CC"
#define  MPEGNR_ICH1_ReadData_DATA_C4_PK_reg                                     0xB80238CC
#define  MPEGNR_ICH1_ReadData_DATA_C4_PK_inst_addr                               "0x0019"
#define  set_MPEGNR_ICH1_ReadData_DATA_C4_PK_reg(data)                           (*((volatile unsigned int*)MPEGNR_ICH1_ReadData_DATA_C4_PK_reg)=data)
#define  get_MPEGNR_ICH1_ReadData_DATA_C4_PK_reg                                 (*((volatile unsigned int*)MPEGNR_ICH1_ReadData_DATA_C4_PK_reg))
#define  MPEGNR_ICH1_ReadData_DATA_C4_PK_v11_shift                               (16)
#define  MPEGNR_ICH1_ReadData_DATA_C4_PK_u11_shift                               (0)
#define  MPEGNR_ICH1_ReadData_DATA_C4_PK_v11_mask                                (0x03FF0000)
#define  MPEGNR_ICH1_ReadData_DATA_C4_PK_u11_mask                                (0x000003FF)
#define  MPEGNR_ICH1_ReadData_DATA_C4_PK_v11(data)                               (0x03FF0000&((data)<<16))
#define  MPEGNR_ICH1_ReadData_DATA_C4_PK_u11(data)                               (0x000003FF&(data))
#define  MPEGNR_ICH1_ReadData_DATA_C4_PK_get_v11(data)                           ((0x03FF0000&(data))>>16)
#define  MPEGNR_ICH1_ReadData_DATA_C4_PK_get_u11(data)                           (0x000003FF&(data))

#define  MPEGNR_ICH1_WriteData_DATA_PK                                           0x180238D0
#define  MPEGNR_ICH1_WriteData_DATA_PK_reg_addr                                  "0xB80238D0"
#define  MPEGNR_ICH1_WriteData_DATA_PK_reg                                       0xB80238D0
#define  MPEGNR_ICH1_WriteData_DATA_PK_inst_addr                                 "0x001A"
#define  set_MPEGNR_ICH1_WriteData_DATA_PK_reg(data)                             (*((volatile unsigned int*)MPEGNR_ICH1_WriteData_DATA_PK_reg)=data)
#define  get_MPEGNR_ICH1_WriteData_DATA_PK_reg                                   (*((volatile unsigned int*)MPEGNR_ICH1_WriteData_DATA_PK_reg))
#define  MPEGNR_ICH1_WriteData_DATA_PK_v_shift                                   (8)
#define  MPEGNR_ICH1_WriteData_DATA_PK_u_shift                                   (4)
#define  MPEGNR_ICH1_WriteData_DATA_PK_y_shift                                   (0)
#define  MPEGNR_ICH1_WriteData_DATA_PK_v_mask                                    (0x00000F00)
#define  MPEGNR_ICH1_WriteData_DATA_PK_u_mask                                    (0x000000F0)
#define  MPEGNR_ICH1_WriteData_DATA_PK_y_mask                                    (0x0000000F)
#define  MPEGNR_ICH1_WriteData_DATA_PK_v(data)                                   (0x00000F00&((data)<<8))
#define  MPEGNR_ICH1_WriteData_DATA_PK_u(data)                                   (0x000000F0&((data)<<4))
#define  MPEGNR_ICH1_WriteData_DATA_PK_y(data)                                   (0x0000000F&(data))
#define  MPEGNR_ICH1_WriteData_DATA_PK_get_v(data)                               ((0x00000F00&(data))>>8)
#define  MPEGNR_ICH1_WriteData_DATA_PK_get_u(data)                               ((0x000000F0&(data))>>4)
#define  MPEGNR_ICH1_WriteData_DATA_PK_get_y(data)                               (0x0000000F&(data))

#define  MPEGNR_ICH1_CntHor0                                                     0x180238DC
#define  MPEGNR_ICH1_CntHor0_reg_addr                                            "0xB80238DC"
#define  MPEGNR_ICH1_CntHor0_reg                                                 0xB80238DC
#define  MPEGNR_ICH1_CntHor0_inst_addr                                           "0x001B"
#define  set_MPEGNR_ICH1_CntHor0_reg(data)                                       (*((volatile unsigned int*)MPEGNR_ICH1_CntHor0_reg)=data)
#define  get_MPEGNR_ICH1_CntHor0_reg                                             (*((volatile unsigned int*)MPEGNR_ICH1_CntHor0_reg))
#define  MPEGNR_ICH1_CntHor0_cp_cnthor0_shift                                    (0)
#define  MPEGNR_ICH1_CntHor0_cp_cnthor0_mask                                     (0x000FFFFF)
#define  MPEGNR_ICH1_CntHor0_cp_cnthor0(data)                                    (0x000FFFFF&(data))
#define  MPEGNR_ICH1_CntHor0_get_cp_cnthor0(data)                                (0x000FFFFF&(data))

#define  MPEGNR_ICH1_CntHor1                                                     0x180238E0
#define  MPEGNR_ICH1_CntHor1_reg_addr                                            "0xB80238E0"
#define  MPEGNR_ICH1_CntHor1_reg                                                 0xB80238E0
#define  MPEGNR_ICH1_CntHor1_inst_addr                                           "0x001C"
#define  set_MPEGNR_ICH1_CntHor1_reg(data)                                       (*((volatile unsigned int*)MPEGNR_ICH1_CntHor1_reg)=data)
#define  get_MPEGNR_ICH1_CntHor1_reg                                             (*((volatile unsigned int*)MPEGNR_ICH1_CntHor1_reg))
#define  MPEGNR_ICH1_CntHor1_cp_cnthor1_shift                                    (0)
#define  MPEGNR_ICH1_CntHor1_cp_cnthor1_mask                                     (0x000FFFFF)
#define  MPEGNR_ICH1_CntHor1_cp_cnthor1(data)                                    (0x000FFFFF&(data))
#define  MPEGNR_ICH1_CntHor1_get_cp_cnthor1(data)                                (0x000FFFFF&(data))

#define  MPEGNR_ICH1_CntHor2                                                     0x180238E4
#define  MPEGNR_ICH1_CntHor2_reg_addr                                            "0xB80238E4"
#define  MPEGNR_ICH1_CntHor2_reg                                                 0xB80238E4
#define  MPEGNR_ICH1_CntHor2_inst_addr                                           "0x001D"
#define  set_MPEGNR_ICH1_CntHor2_reg(data)                                       (*((volatile unsigned int*)MPEGNR_ICH1_CntHor2_reg)=data)
#define  get_MPEGNR_ICH1_CntHor2_reg                                             (*((volatile unsigned int*)MPEGNR_ICH1_CntHor2_reg))
#define  MPEGNR_ICH1_CntHor2_cp_cnthor2_shift                                    (0)
#define  MPEGNR_ICH1_CntHor2_cp_cnthor2_mask                                     (0x000FFFFF)
#define  MPEGNR_ICH1_CntHor2_cp_cnthor2(data)                                    (0x000FFFFF&(data))
#define  MPEGNR_ICH1_CntHor2_get_cp_cnthor2(data)                                (0x000FFFFF&(data))

#define  MPEGNR_ICH1_CntHor3                                                     0x180238E8
#define  MPEGNR_ICH1_CntHor3_reg_addr                                            "0xB80238E8"
#define  MPEGNR_ICH1_CntHor3_reg                                                 0xB80238E8
#define  MPEGNR_ICH1_CntHor3_inst_addr                                           "0x001E"
#define  set_MPEGNR_ICH1_CntHor3_reg(data)                                       (*((volatile unsigned int*)MPEGNR_ICH1_CntHor3_reg)=data)
#define  get_MPEGNR_ICH1_CntHor3_reg                                             (*((volatile unsigned int*)MPEGNR_ICH1_CntHor3_reg))
#define  MPEGNR_ICH1_CntHor3_cp_cnthor3_shift                                    (0)
#define  MPEGNR_ICH1_CntHor3_cp_cnthor3_mask                                     (0x000FFFFF)
#define  MPEGNR_ICH1_CntHor3_cp_cnthor3(data)                                    (0x000FFFFF&(data))
#define  MPEGNR_ICH1_CntHor3_get_cp_cnthor3(data)                                (0x000FFFFF&(data))

#define  MPEGNR_ICH1_CntHor4                                                     0x180238EC
#define  MPEGNR_ICH1_CntHor4_reg_addr                                            "0xB80238EC"
#define  MPEGNR_ICH1_CntHor4_reg                                                 0xB80238EC
#define  MPEGNR_ICH1_CntHor4_inst_addr                                           "0x001F"
#define  set_MPEGNR_ICH1_CntHor4_reg(data)                                       (*((volatile unsigned int*)MPEGNR_ICH1_CntHor4_reg)=data)
#define  get_MPEGNR_ICH1_CntHor4_reg                                             (*((volatile unsigned int*)MPEGNR_ICH1_CntHor4_reg))
#define  MPEGNR_ICH1_CntHor4_cp_cnthor4_shift                                    (0)
#define  MPEGNR_ICH1_CntHor4_cp_cnthor4_mask                                     (0x000FFFFF)
#define  MPEGNR_ICH1_CntHor4_cp_cnthor4(data)                                    (0x000FFFFF&(data))
#define  MPEGNR_ICH1_CntHor4_get_cp_cnthor4(data)                                (0x000FFFFF&(data))

#define  MPEGNR_ICH1_CntHor5                                                     0x180238F0
#define  MPEGNR_ICH1_CntHor5_reg_addr                                            "0xB80238F0"
#define  MPEGNR_ICH1_CntHor5_reg                                                 0xB80238F0
#define  MPEGNR_ICH1_CntHor5_inst_addr                                           "0x0020"
#define  set_MPEGNR_ICH1_CntHor5_reg(data)                                       (*((volatile unsigned int*)MPEGNR_ICH1_CntHor5_reg)=data)
#define  get_MPEGNR_ICH1_CntHor5_reg                                             (*((volatile unsigned int*)MPEGNR_ICH1_CntHor5_reg))
#define  MPEGNR_ICH1_CntHor5_cp_cnthor5_shift                                    (0)
#define  MPEGNR_ICH1_CntHor5_cp_cnthor5_mask                                     (0x000FFFFF)
#define  MPEGNR_ICH1_CntHor5_cp_cnthor5(data)                                    (0x000FFFFF&(data))
#define  MPEGNR_ICH1_CntHor5_get_cp_cnthor5(data)                                (0x000FFFFF&(data))

#define  MPEGNR_ICH1_CntHor6                                                     0x180238F4
#define  MPEGNR_ICH1_CntHor6_reg_addr                                            "0xB80238F4"
#define  MPEGNR_ICH1_CntHor6_reg                                                 0xB80238F4
#define  MPEGNR_ICH1_CntHor6_inst_addr                                           "0x0021"
#define  set_MPEGNR_ICH1_CntHor6_reg(data)                                       (*((volatile unsigned int*)MPEGNR_ICH1_CntHor6_reg)=data)
#define  get_MPEGNR_ICH1_CntHor6_reg                                             (*((volatile unsigned int*)MPEGNR_ICH1_CntHor6_reg))
#define  MPEGNR_ICH1_CntHor6_cp_cnthor6_shift                                    (0)
#define  MPEGNR_ICH1_CntHor6_cp_cnthor6_mask                                     (0x000FFFFF)
#define  MPEGNR_ICH1_CntHor6_cp_cnthor6(data)                                    (0x000FFFFF&(data))
#define  MPEGNR_ICH1_CntHor6_get_cp_cnthor6(data)                                (0x000FFFFF&(data))

#define  MPEGNR_ICH1_CntHor7                                                     0x180238F8
#define  MPEGNR_ICH1_CntHor7_reg_addr                                            "0xB80238F8"
#define  MPEGNR_ICH1_CntHor7_reg                                                 0xB80238F8
#define  MPEGNR_ICH1_CntHor7_inst_addr                                           "0x0022"
#define  set_MPEGNR_ICH1_CntHor7_reg(data)                                       (*((volatile unsigned int*)MPEGNR_ICH1_CntHor7_reg)=data)
#define  get_MPEGNR_ICH1_CntHor7_reg                                             (*((volatile unsigned int*)MPEGNR_ICH1_CntHor7_reg))
#define  MPEGNR_ICH1_CntHor7_cp_cnthor7_shift                                    (0)
#define  MPEGNR_ICH1_CntHor7_cp_cnthor7_mask                                     (0x000FFFFF)
#define  MPEGNR_ICH1_CntHor7_cp_cnthor7(data)                                    (0x000FFFFF&(data))
#define  MPEGNR_ICH1_CntHor7_get_cp_cnthor7(data)                                (0x000FFFFF&(data))

#define  MPEGNR_ICH1_GENERAL_DB_CTRL                                             0x180238FC
#define  MPEGNR_ICH1_GENERAL_DB_CTRL_reg_addr                                    "0xB80238FC"
#define  MPEGNR_ICH1_GENERAL_DB_CTRL_reg                                         0xB80238FC
#define  MPEGNR_ICH1_GENERAL_DB_CTRL_inst_addr                                   "0x0023"
#define  set_MPEGNR_ICH1_GENERAL_DB_CTRL_reg(data)                               (*((volatile unsigned int*)MPEGNR_ICH1_GENERAL_DB_CTRL_reg)=data)
#define  get_MPEGNR_ICH1_GENERAL_DB_CTRL_reg                                     (*((volatile unsigned int*)MPEGNR_ICH1_GENERAL_DB_CTRL_reg))
#define  MPEGNR_ICH1_GENERAL_DB_CTRL_general_db_apply_shift                      (2)
#define  MPEGNR_ICH1_GENERAL_DB_CTRL_general_db_rd_sel_shift                     (1)
#define  MPEGNR_ICH1_GENERAL_DB_CTRL_general_db_en_shift                         (0)
#define  MPEGNR_ICH1_GENERAL_DB_CTRL_general_db_apply_mask                       (0x00000004)
#define  MPEGNR_ICH1_GENERAL_DB_CTRL_general_db_rd_sel_mask                      (0x00000002)
#define  MPEGNR_ICH1_GENERAL_DB_CTRL_general_db_en_mask                          (0x00000001)
#define  MPEGNR_ICH1_GENERAL_DB_CTRL_general_db_apply(data)                      (0x00000004&((data)<<2))
#define  MPEGNR_ICH1_GENERAL_DB_CTRL_general_db_rd_sel(data)                     (0x00000002&((data)<<1))
#define  MPEGNR_ICH1_GENERAL_DB_CTRL_general_db_en(data)                         (0x00000001&(data))
#define  MPEGNR_ICH1_GENERAL_DB_CTRL_get_general_db_apply(data)                  ((0x00000004&(data))>>2)
#define  MPEGNR_ICH1_GENERAL_DB_CTRL_get_general_db_rd_sel(data)                 ((0x00000002&(data))>>1)
#define  MPEGNR_ICH1_GENERAL_DB_CTRL_get_general_db_en(data)                     (0x00000001&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======MPEGNR register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_mpghor_blend_range:2;
        RBus_UInt32  res1:11;
        RBus_UInt32  cp_mpghor_blend_xini:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  cp_mpghor_blend_xstep:15;
    };
}mpegnr_ich1_blend_nr_hor_step_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_mpgub_dec_sel:1;
        RBus_UInt32  cp_mpgub_difcmp_en:3;
        RBus_UInt32  cp_mpgub_difcen_en:4;
        RBus_UInt32  cp_mpgupperbound_x:10;
        RBus_UInt32  cp_mpgupperbound_offset:8;
        RBus_UInt32  cp_mpgupperbound_gain:2;
        RBus_UInt32  res1:1;
        RBus_UInt32  cp_mpgnr_filter_sel:3;
    };
}mpegnr_ich1_mpegnr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  cp_mpgub_delta2:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  cp_mpgub_delta1:10;
    };
}mpegnr_ich1_mpegnr_ub_delta1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  cp_mpgub_delta3:10;
    };
}mpegnr_ich1_mpegnr_ub_delta2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  cp_mpghor_diff_th_high:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  cp_mpghor_diff_th_low:10;
    };
}mpegnr_ich1_mpegnr_ub_cen_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_mpgdcgain:4;
        RBus_UInt32  res1:4;
        RBus_UInt32  cp_mpgdcqp:8;
        RBus_UInt32  res2:6;
        RBus_UInt32  cp_mpgfiltersel1:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  cp_mpgidxmode_x:1;
        RBus_UInt32  cp_mpgidx_x:3;
        RBus_UInt32  cp_mpegresultweight_x:3;
        RBus_UInt32  cp_mpegenable_x:1;
    };
}mpegnr_ich1_mpegnr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  cp_mpghor_diff_gain_high:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  cp_mpghor_diff_gain_low:10;
    };
}mpegnr_ich1_mpegnr_ub_cen_gain_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_mpgtex_range:2;
        RBus_UInt32  res1:6;
        RBus_UInt32  cp_mpgub_difcmp_offset:8;
        RBus_UInt32  res2:6;
        RBus_UInt32  cp_mpgub_difcmp_gain:10;
    };
}mpegnr_ich1_mpegnr_ub_dif_cmp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  cp_histhorend:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  cp_histhorstart:14;
    };
}mpegnr_ich1_hist_blking_hor_range_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  cp_histverend:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  cp_histverstart:14;
    };
}mpegnr_ich1_hist_blking_ver_range_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  cp_histhoren:1;
    };
}mpegnr_ich1_mpegstart_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}mpegnr_ich1_cnthor_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}mpegnr_ich1_cnthor_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}mpegnr_ich1_cnthor_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}mpegnr_ich1_cnthor_03_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  cp_histhor_det_xini:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  cp_histhor_det_xstep:15;
    };
}mpegnr_ich1_det_hist_hor_step_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  cp_histhor_diff_th_high:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  cp_histhor_diff_th_low:8;
    };
}mpegnr_ich1_det_hist_hor_thd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  cp_histhor_debug_en:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  cp_histhor_dbg_mpgidx:3;
    };
}mpegnr_ich1_det_hist_hor_dbg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  fsync_general_standard_num:17;
        RBus_UInt32  res2:6;
        RBus_UInt32  fsync_general_en:1;
        RBus_UInt32  fsync_general_line_num:5;
    };
}mpegnr_fsync_general_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fsync_debug_en:1;
        RBus_UInt32  res1:18;
        RBus_UInt32  fsync_general_delta_ratio:13;
    };
}mpegnr_fsync_general_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  measure_result_tmp:17;
        RBus_UInt32  delta_trunc:15;
    };
}mpegnr_fsync_general_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  measult_result:32;
    };
}mpegnr_fsync_general_ctrl4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  write_en:1;
        RBus_UInt32  read_en:1;
    };
}mpegnr_ich1_accessdata_ctrl_pk_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  starty:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  startx:14;
    };
}mpegnr_ich1_accessdata_posctrl_pk_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  y01:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  y00:10;
    };
}mpegnr_ich1_readdata_data_y1_pk_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  y11:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  y10:10;
    };
}mpegnr_ich1_readdata_data_y2_pk_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  v00:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  u00:10;
    };
}mpegnr_ich1_readdata_data_c1_pk_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  v01:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  u01:10;
    };
}mpegnr_ich1_readdata_data_c2_pk_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  v10:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  u10:10;
    };
}mpegnr_ich1_readdata_data_c3_pk_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  v11:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  u11:10;
    };
}mpegnr_ich1_readdata_data_c4_pk_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  v:4;
        RBus_UInt32  u:4;
        RBus_UInt32  y:4;
    };
}mpegnr_ich1_writedata_data_pk_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  cp_cnthor0:20;
    };
}mpegnr_ich1_cnthor0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  cp_cnthor1:20;
    };
}mpegnr_ich1_cnthor1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  cp_cnthor2:20;
    };
}mpegnr_ich1_cnthor2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  cp_cnthor3:20;
    };
}mpegnr_ich1_cnthor3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  cp_cnthor4:20;
    };
}mpegnr_ich1_cnthor4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  cp_cnthor5:20;
    };
}mpegnr_ich1_cnthor5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  cp_cnthor6:20;
    };
}mpegnr_ich1_cnthor6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  cp_cnthor7:20;
    };
}mpegnr_ich1_cnthor7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  general_db_apply:1;
        RBus_UInt32  general_db_rd_sel:1;
        RBus_UInt32  general_db_en:1;
    };
}mpegnr_ich1_general_db_ctrl_RBUS;

#else //apply LITTLE_ENDIAN

//======MPEGNR register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_mpghor_blend_xstep:15;
        RBus_UInt32  res1:1;
        RBus_UInt32  cp_mpghor_blend_xini:3;
        RBus_UInt32  res2:11;
        RBus_UInt32  cp_mpghor_blend_range:2;
    };
}mpegnr_ich1_blend_nr_hor_step_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_mpgnr_filter_sel:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  cp_mpgupperbound_gain:2;
        RBus_UInt32  cp_mpgupperbound_offset:8;
        RBus_UInt32  cp_mpgupperbound_x:10;
        RBus_UInt32  cp_mpgub_difcen_en:4;
        RBus_UInt32  cp_mpgub_difcmp_en:3;
        RBus_UInt32  cp_mpgub_dec_sel:1;
    };
}mpegnr_ich1_mpegnr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_mpgub_delta1:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  cp_mpgub_delta2:10;
        RBus_UInt32  res2:6;
    };
}mpegnr_ich1_mpegnr_ub_delta1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_mpgub_delta3:10;
        RBus_UInt32  res1:22;
    };
}mpegnr_ich1_mpegnr_ub_delta2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_mpghor_diff_th_low:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  cp_mpghor_diff_th_high:10;
        RBus_UInt32  res2:6;
    };
}mpegnr_ich1_mpegnr_ub_cen_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_mpegenable_x:1;
        RBus_UInt32  cp_mpegresultweight_x:3;
        RBus_UInt32  cp_mpgidx_x:3;
        RBus_UInt32  cp_mpgidxmode_x:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  cp_mpgfiltersel1:1;
        RBus_UInt32  res2:6;
        RBus_UInt32  cp_mpgdcqp:8;
        RBus_UInt32  res3:4;
        RBus_UInt32  cp_mpgdcgain:4;
    };
}mpegnr_ich1_mpegnr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_mpghor_diff_gain_low:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  cp_mpghor_diff_gain_high:10;
        RBus_UInt32  res2:6;
    };
}mpegnr_ich1_mpegnr_ub_cen_gain_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_mpgub_difcmp_gain:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  cp_mpgub_difcmp_offset:8;
        RBus_UInt32  res2:6;
        RBus_UInt32  cp_mpgtex_range:2;
    };
}mpegnr_ich1_mpegnr_ub_dif_cmp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_histhorstart:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  cp_histhorend:14;
        RBus_UInt32  res2:2;
    };
}mpegnr_ich1_hist_blking_hor_range_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_histverstart:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  cp_histverend:14;
        RBus_UInt32  res2:2;
    };
}mpegnr_ich1_hist_blking_ver_range_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_histhoren:1;
        RBus_UInt32  res1:31;
    };
}mpegnr_ich1_mpegstart_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}mpegnr_ich1_cnthor_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}mpegnr_ich1_cnthor_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}mpegnr_ich1_cnthor_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}mpegnr_ich1_cnthor_03_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_histhor_det_xstep:15;
        RBus_UInt32  res1:1;
        RBus_UInt32  cp_histhor_det_xini:3;
        RBus_UInt32  res2:13;
    };
}mpegnr_ich1_det_hist_hor_step_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_histhor_diff_th_low:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  cp_histhor_diff_th_high:8;
        RBus_UInt32  res2:8;
    };
}mpegnr_ich1_det_hist_hor_thd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_histhor_dbg_mpgidx:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  cp_histhor_debug_en:1;
        RBus_UInt32  res2:27;
    };
}mpegnr_ich1_det_hist_hor_dbg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fsync_general_line_num:5;
        RBus_UInt32  fsync_general_en:1;
        RBus_UInt32  res1:6;
        RBus_UInt32  fsync_general_standard_num:17;
        RBus_UInt32  res2:3;
    };
}mpegnr_fsync_general_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fsync_general_delta_ratio:13;
        RBus_UInt32  res1:18;
        RBus_UInt32  fsync_debug_en:1;
    };
}mpegnr_fsync_general_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  delta_trunc:15;
        RBus_UInt32  measure_result_tmp:17;
    };
}mpegnr_fsync_general_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  measult_result:32;
    };
}mpegnr_fsync_general_ctrl4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  read_en:1;
        RBus_UInt32  write_en:1;
        RBus_UInt32  res1:30;
    };
}mpegnr_ich1_accessdata_ctrl_pk_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  startx:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  starty:14;
        RBus_UInt32  res2:2;
    };
}mpegnr_ich1_accessdata_posctrl_pk_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y00:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  y01:10;
        RBus_UInt32  res2:6;
    };
}mpegnr_ich1_readdata_data_y1_pk_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y10:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  y11:10;
        RBus_UInt32  res2:6;
    };
}mpegnr_ich1_readdata_data_y2_pk_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  u00:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  v00:10;
        RBus_UInt32  res2:6;
    };
}mpegnr_ich1_readdata_data_c1_pk_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  u01:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  v01:10;
        RBus_UInt32  res2:6;
    };
}mpegnr_ich1_readdata_data_c2_pk_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  u10:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  v10:10;
        RBus_UInt32  res2:6;
    };
}mpegnr_ich1_readdata_data_c3_pk_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  u11:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  v11:10;
        RBus_UInt32  res2:6;
    };
}mpegnr_ich1_readdata_data_c4_pk_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y:4;
        RBus_UInt32  u:4;
        RBus_UInt32  v:4;
        RBus_UInt32  res1:20;
    };
}mpegnr_ich1_writedata_data_pk_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_cnthor0:20;
        RBus_UInt32  res1:12;
    };
}mpegnr_ich1_cnthor0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_cnthor1:20;
        RBus_UInt32  res1:12;
    };
}mpegnr_ich1_cnthor1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_cnthor2:20;
        RBus_UInt32  res1:12;
    };
}mpegnr_ich1_cnthor2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_cnthor3:20;
        RBus_UInt32  res1:12;
    };
}mpegnr_ich1_cnthor3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_cnthor4:20;
        RBus_UInt32  res1:12;
    };
}mpegnr_ich1_cnthor4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_cnthor5:20;
        RBus_UInt32  res1:12;
    };
}mpegnr_ich1_cnthor5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_cnthor6:20;
        RBus_UInt32  res1:12;
    };
}mpegnr_ich1_cnthor6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_cnthor7:20;
        RBus_UInt32  res1:12;
    };
}mpegnr_ich1_cnthor7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  general_db_en:1;
        RBus_UInt32  general_db_rd_sel:1;
        RBus_UInt32  general_db_apply:1;
        RBus_UInt32  res1:29;
    };
}mpegnr_ich1_general_db_ctrl_RBUS;




#endif 


#endif 
