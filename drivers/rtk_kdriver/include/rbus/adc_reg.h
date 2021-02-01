/**
* @file MacArthur5-DesignSpec-I-Domain_YPP&VDCADC
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_ADC_REG_H_
#define _RBUS_ADC_REG_H_

#include "rbus_types.h"



//  ADC Register Address
#define  ADC_ADC_POWER                                                           0x18020000
#define  ADC_ADC_POWER_reg_addr                                                  "0xB8020000"
#define  ADC_ADC_POWER_reg                                                       0xB8020000
#define  ADC_ADC_POWER_inst_addr                                                 "0x0000"
#define  set_ADC_ADC_POWER_reg(data)                                             (*((volatile unsigned int*)ADC_ADC_POWER_reg)=data)
#define  get_ADC_ADC_POWER_reg                                                   (*((volatile unsigned int*)ADC_ADC_POWER_reg))
#define  ADC_ADC_POWER_dummy_31_16_shift                                         (16)
#define  ADC_ADC_POWER_adc_power_9_shift                                         (9)
#define  ADC_ADC_POWER_adc_power_8_shift                                         (8)
#define  ADC_ADC_POWER_adc_power_7_shift                                         (7)
#define  ADC_ADC_POWER_adc_power_6_shift                                         (6)
#define  ADC_ADC_POWER_adc_power_5_shift                                         (5)
#define  ADC_ADC_POWER_adc_power_4_shift                                         (4)
#define  ADC_ADC_POWER_adc_power_3_shift                                         (3)
#define  ADC_ADC_POWER_adc_power_2_shift                                         (2)
#define  ADC_ADC_POWER_adc_power_1_shift                                         (1)
#define  ADC_ADC_POWER_adc_power_0_shift                                         (0)
#define  ADC_ADC_POWER_dummy_31_16_mask                                          (0xFFFF0000)
#define  ADC_ADC_POWER_adc_power_9_mask                                          (0x00000200)
#define  ADC_ADC_POWER_adc_power_8_mask                                          (0x00000100)
#define  ADC_ADC_POWER_adc_power_7_mask                                          (0x00000080)
#define  ADC_ADC_POWER_adc_power_6_mask                                          (0x00000040)
#define  ADC_ADC_POWER_adc_power_5_mask                                          (0x00000020)
#define  ADC_ADC_POWER_adc_power_4_mask                                          (0x00000010)
#define  ADC_ADC_POWER_adc_power_3_mask                                          (0x00000008)
#define  ADC_ADC_POWER_adc_power_2_mask                                          (0x00000004)
#define  ADC_ADC_POWER_adc_power_1_mask                                          (0x00000002)
#define  ADC_ADC_POWER_adc_power_0_mask                                          (0x00000001)
#define  ADC_ADC_POWER_dummy_31_16(data)                                         (0xFFFF0000&((data)<<16))
#define  ADC_ADC_POWER_adc_power_9(data)                                         (0x00000200&((data)<<9))
#define  ADC_ADC_POWER_adc_power_8(data)                                         (0x00000100&((data)<<8))
#define  ADC_ADC_POWER_adc_power_7(data)                                         (0x00000080&((data)<<7))
#define  ADC_ADC_POWER_adc_power_6(data)                                         (0x00000040&((data)<<6))
#define  ADC_ADC_POWER_adc_power_5(data)                                         (0x00000020&((data)<<5))
#define  ADC_ADC_POWER_adc_power_4(data)                                         (0x00000010&((data)<<4))
#define  ADC_ADC_POWER_adc_power_3(data)                                         (0x00000008&((data)<<3))
#define  ADC_ADC_POWER_adc_power_2(data)                                         (0x00000004&((data)<<2))
#define  ADC_ADC_POWER_adc_power_1(data)                                         (0x00000002&((data)<<1))
#define  ADC_ADC_POWER_adc_power_0(data)                                         (0x00000001&(data))
#define  ADC_ADC_POWER_get_dummy_31_16(data)                                     ((0xFFFF0000&(data))>>16)
#define  ADC_ADC_POWER_get_adc_power_9(data)                                     ((0x00000200&(data))>>9)
#define  ADC_ADC_POWER_get_adc_power_8(data)                                     ((0x00000100&(data))>>8)
#define  ADC_ADC_POWER_get_adc_power_7(data)                                     ((0x00000080&(data))>>7)
#define  ADC_ADC_POWER_get_adc_power_6(data)                                     ((0x00000040&(data))>>6)
#define  ADC_ADC_POWER_get_adc_power_5(data)                                     ((0x00000020&(data))>>5)
#define  ADC_ADC_POWER_get_adc_power_4(data)                                     ((0x00000010&(data))>>4)
#define  ADC_ADC_POWER_get_adc_power_3(data)                                     ((0x00000008&(data))>>3)
#define  ADC_ADC_POWER_get_adc_power_2(data)                                     ((0x00000004&(data))>>2)
#define  ADC_ADC_POWER_get_adc_power_1(data)                                     ((0x00000002&(data))>>1)
#define  ADC_ADC_POWER_get_adc_power_0(data)                                     (0x00000001&(data))

#define  ADC_ADC_IBIAS0123                                                       0x18020004
#define  ADC_ADC_IBIAS0123_reg_addr                                              "0xB8020004"
#define  ADC_ADC_IBIAS0123_reg                                                   0xB8020004
#define  ADC_ADC_IBIAS0123_inst_addr                                             "0x0001"
#define  set_ADC_ADC_IBIAS0123_reg(data)                                         (*((volatile unsigned int*)ADC_ADC_IBIAS0123_reg)=data)
#define  get_ADC_ADC_IBIAS0123_reg                                               (*((volatile unsigned int*)ADC_ADC_IBIAS0123_reg))
#define  ADC_ADC_IBIAS0123_adc_ibias1_7_shift                                    (15)
#define  ADC_ADC_IBIAS0123_adc_ibias1_6_shift                                    (14)
#define  ADC_ADC_IBIAS0123_adc_ibias1_5_shift                                    (13)
#define  ADC_ADC_IBIAS0123_adc_ibias1_4_1_shift                                  (9)
#define  ADC_ADC_IBIAS0123_adc_ibias1_0_shift                                    (8)
#define  ADC_ADC_IBIAS0123_adc_ibias0_shift                                      (0)
#define  ADC_ADC_IBIAS0123_adc_ibias1_7_mask                                     (0x00008000)
#define  ADC_ADC_IBIAS0123_adc_ibias1_6_mask                                     (0x00004000)
#define  ADC_ADC_IBIAS0123_adc_ibias1_5_mask                                     (0x00002000)
#define  ADC_ADC_IBIAS0123_adc_ibias1_4_1_mask                                   (0x00001E00)
#define  ADC_ADC_IBIAS0123_adc_ibias1_0_mask                                     (0x00000100)
#define  ADC_ADC_IBIAS0123_adc_ibias0_mask                                       (0x000000FF)
#define  ADC_ADC_IBIAS0123_adc_ibias1_7(data)                                    (0x00008000&((data)<<15))
#define  ADC_ADC_IBIAS0123_adc_ibias1_6(data)                                    (0x00004000&((data)<<14))
#define  ADC_ADC_IBIAS0123_adc_ibias1_5(data)                                    (0x00002000&((data)<<13))
#define  ADC_ADC_IBIAS0123_adc_ibias1_4_1(data)                                  (0x00001E00&((data)<<9))
#define  ADC_ADC_IBIAS0123_adc_ibias1_0(data)                                    (0x00000100&((data)<<8))
#define  ADC_ADC_IBIAS0123_adc_ibias0(data)                                      (0x000000FF&(data))
#define  ADC_ADC_IBIAS0123_get_adc_ibias1_7(data)                                ((0x00008000&(data))>>15)
#define  ADC_ADC_IBIAS0123_get_adc_ibias1_6(data)                                ((0x00004000&(data))>>14)
#define  ADC_ADC_IBIAS0123_get_adc_ibias1_5(data)                                ((0x00002000&(data))>>13)
#define  ADC_ADC_IBIAS0123_get_adc_ibias1_4_1(data)                              ((0x00001E00&(data))>>9)
#define  ADC_ADC_IBIAS0123_get_adc_ibias1_0(data)                                ((0x00000100&(data))>>8)
#define  ADC_ADC_IBIAS0123_get_adc_ibias0(data)                                  (0x000000FF&(data))

#define  ADC_ADC_CTL_RGB12                                                       0x18020008
#define  ADC_ADC_CTL_RGB12_reg_addr                                              "0xB8020008"
#define  ADC_ADC_CTL_RGB12_reg                                                   0xB8020008
#define  ADC_ADC_CTL_RGB12_inst_addr                                             "0x0002"
#define  set_ADC_ADC_CTL_RGB12_reg(data)                                         (*((volatile unsigned int*)ADC_ADC_CTL_RGB12_reg)=data)
#define  get_ADC_ADC_CTL_RGB12_reg                                               (*((volatile unsigned int*)ADC_ADC_CTL_RGB12_reg))
#define  ADC_ADC_CTL_RGB12_adc_ctl_rgb2_11_10_shift                              (26)
#define  ADC_ADC_CTL_RGB12_adc_ctl_rgb2_9_shift                                  (25)
#define  ADC_ADC_CTL_RGB12_adc_ctl_rgb2_8_shift                                  (24)
#define  ADC_ADC_CTL_RGB12_adc_ctl_rgb2_7_shift                                  (23)
#define  ADC_ADC_CTL_RGB12_adc_ctl_rgb2_6_shift                                  (22)
#define  ADC_ADC_CTL_RGB12_adc_ctl_rgb2_5_4_shift                                (20)
#define  ADC_ADC_CTL_RGB12_adc_ctl_rgb2_3_2_shift                                (18)
#define  ADC_ADC_CTL_RGB12_adc_ctl_rgb2_1_0_shift                                (16)
#define  ADC_ADC_CTL_RGB12_adc_ctl_rgb1_11_10_shift                              (10)
#define  ADC_ADC_CTL_RGB12_adc_ctl_rgb1_9_shift                                  (9)
#define  ADC_ADC_CTL_RGB12_adc_ctl_rgb1_8_shift                                  (8)
#define  ADC_ADC_CTL_RGB12_adc_ctl_rgb1_7_shift                                  (7)
#define  ADC_ADC_CTL_RGB12_adc_ctl_rgb1_6_shift                                  (6)
#define  ADC_ADC_CTL_RGB12_adc_ctl_rgb1_5_4_shift                                (4)
#define  ADC_ADC_CTL_RGB12_adc_ctl_rgb1_3_2_shift                                (2)
#define  ADC_ADC_CTL_RGB12_adc_ctl_rgb1_1_0_shift                                (0)
#define  ADC_ADC_CTL_RGB12_adc_ctl_rgb2_11_10_mask                               (0x0C000000)
#define  ADC_ADC_CTL_RGB12_adc_ctl_rgb2_9_mask                                   (0x02000000)
#define  ADC_ADC_CTL_RGB12_adc_ctl_rgb2_8_mask                                   (0x01000000)
#define  ADC_ADC_CTL_RGB12_adc_ctl_rgb2_7_mask                                   (0x00800000)
#define  ADC_ADC_CTL_RGB12_adc_ctl_rgb2_6_mask                                   (0x00400000)
#define  ADC_ADC_CTL_RGB12_adc_ctl_rgb2_5_4_mask                                 (0x00300000)
#define  ADC_ADC_CTL_RGB12_adc_ctl_rgb2_3_2_mask                                 (0x000C0000)
#define  ADC_ADC_CTL_RGB12_adc_ctl_rgb2_1_0_mask                                 (0x00030000)
#define  ADC_ADC_CTL_RGB12_adc_ctl_rgb1_11_10_mask                               (0x00000C00)
#define  ADC_ADC_CTL_RGB12_adc_ctl_rgb1_9_mask                                   (0x00000200)
#define  ADC_ADC_CTL_RGB12_adc_ctl_rgb1_8_mask                                   (0x00000100)
#define  ADC_ADC_CTL_RGB12_adc_ctl_rgb1_7_mask                                   (0x00000080)
#define  ADC_ADC_CTL_RGB12_adc_ctl_rgb1_6_mask                                   (0x00000040)
#define  ADC_ADC_CTL_RGB12_adc_ctl_rgb1_5_4_mask                                 (0x00000030)
#define  ADC_ADC_CTL_RGB12_adc_ctl_rgb1_3_2_mask                                 (0x0000000C)
#define  ADC_ADC_CTL_RGB12_adc_ctl_rgb1_1_0_mask                                 (0x00000003)
#define  ADC_ADC_CTL_RGB12_adc_ctl_rgb2_11_10(data)                              (0x0C000000&((data)<<26))
#define  ADC_ADC_CTL_RGB12_adc_ctl_rgb2_9(data)                                  (0x02000000&((data)<<25))
#define  ADC_ADC_CTL_RGB12_adc_ctl_rgb2_8(data)                                  (0x01000000&((data)<<24))
#define  ADC_ADC_CTL_RGB12_adc_ctl_rgb2_7(data)                                  (0x00800000&((data)<<23))
#define  ADC_ADC_CTL_RGB12_adc_ctl_rgb2_6(data)                                  (0x00400000&((data)<<22))
#define  ADC_ADC_CTL_RGB12_adc_ctl_rgb2_5_4(data)                                (0x00300000&((data)<<20))
#define  ADC_ADC_CTL_RGB12_adc_ctl_rgb2_3_2(data)                                (0x000C0000&((data)<<18))
#define  ADC_ADC_CTL_RGB12_adc_ctl_rgb2_1_0(data)                                (0x00030000&((data)<<16))
#define  ADC_ADC_CTL_RGB12_adc_ctl_rgb1_11_10(data)                              (0x00000C00&((data)<<10))
#define  ADC_ADC_CTL_RGB12_adc_ctl_rgb1_9(data)                                  (0x00000200&((data)<<9))
#define  ADC_ADC_CTL_RGB12_adc_ctl_rgb1_8(data)                                  (0x00000100&((data)<<8))
#define  ADC_ADC_CTL_RGB12_adc_ctl_rgb1_7(data)                                  (0x00000080&((data)<<7))
#define  ADC_ADC_CTL_RGB12_adc_ctl_rgb1_6(data)                                  (0x00000040&((data)<<6))
#define  ADC_ADC_CTL_RGB12_adc_ctl_rgb1_5_4(data)                                (0x00000030&((data)<<4))
#define  ADC_ADC_CTL_RGB12_adc_ctl_rgb1_3_2(data)                                (0x0000000C&((data)<<2))
#define  ADC_ADC_CTL_RGB12_adc_ctl_rgb1_1_0(data)                                (0x00000003&(data))
#define  ADC_ADC_CTL_RGB12_get_adc_ctl_rgb2_11_10(data)                          ((0x0C000000&(data))>>26)
#define  ADC_ADC_CTL_RGB12_get_adc_ctl_rgb2_9(data)                              ((0x02000000&(data))>>25)
#define  ADC_ADC_CTL_RGB12_get_adc_ctl_rgb2_8(data)                              ((0x01000000&(data))>>24)
#define  ADC_ADC_CTL_RGB12_get_adc_ctl_rgb2_7(data)                              ((0x00800000&(data))>>23)
#define  ADC_ADC_CTL_RGB12_get_adc_ctl_rgb2_6(data)                              ((0x00400000&(data))>>22)
#define  ADC_ADC_CTL_RGB12_get_adc_ctl_rgb2_5_4(data)                            ((0x00300000&(data))>>20)
#define  ADC_ADC_CTL_RGB12_get_adc_ctl_rgb2_3_2(data)                            ((0x000C0000&(data))>>18)
#define  ADC_ADC_CTL_RGB12_get_adc_ctl_rgb2_1_0(data)                            ((0x00030000&(data))>>16)
#define  ADC_ADC_CTL_RGB12_get_adc_ctl_rgb1_11_10(data)                          ((0x00000C00&(data))>>10)
#define  ADC_ADC_CTL_RGB12_get_adc_ctl_rgb1_9(data)                              ((0x00000200&(data))>>9)
#define  ADC_ADC_CTL_RGB12_get_adc_ctl_rgb1_8(data)                              ((0x00000100&(data))>>8)
#define  ADC_ADC_CTL_RGB12_get_adc_ctl_rgb1_7(data)                              ((0x00000080&(data))>>7)
#define  ADC_ADC_CTL_RGB12_get_adc_ctl_rgb1_6(data)                              ((0x00000040&(data))>>6)
#define  ADC_ADC_CTL_RGB12_get_adc_ctl_rgb1_5_4(data)                            ((0x00000030&(data))>>4)
#define  ADC_ADC_CTL_RGB12_get_adc_ctl_rgb1_3_2(data)                            ((0x0000000C&(data))>>2)
#define  ADC_ADC_CTL_RGB12_get_adc_ctl_rgb1_1_0(data)                            (0x00000003&(data))

#define  ADC_ADC_VBIAS                                                           0x1802000C
#define  ADC_ADC_VBIAS_reg_addr                                                  "0xB802000C"
#define  ADC_ADC_VBIAS_reg                                                       0xB802000C
#define  ADC_ADC_VBIAS_inst_addr                                                 "0x0003"
#define  set_ADC_ADC_VBIAS_reg(data)                                             (*((volatile unsigned int*)ADC_ADC_VBIAS_reg)=data)
#define  get_ADC_ADC_VBIAS_reg                                                   (*((volatile unsigned int*)ADC_ADC_VBIAS_reg))
#define  ADC_ADC_VBIAS_adc_vbias3_7_shift                                        (31)
#define  ADC_ADC_VBIAS_adc_vbias3_6_shift                                        (30)
#define  ADC_ADC_VBIAS_adc_vbias3_5_shift                                        (29)
#define  ADC_ADC_VBIAS_adc_vbias3_4_shift                                        (28)
#define  ADC_ADC_VBIAS_adc_vbias3_3_shift                                        (27)
#define  ADC_ADC_VBIAS_adc_vbias3_2_shift                                        (26)
#define  ADC_ADC_VBIAS_adc_vbias3_1_0_shift                                      (24)
#define  ADC_ADC_VBIAS_adc_vbias2_7_shift                                        (23)
#define  ADC_ADC_VBIAS_adc_vbias2_6_shift                                        (22)
#define  ADC_ADC_VBIAS_adc_vbias2_5_shift                                        (21)
#define  ADC_ADC_VBIAS_adc_vbias2_4_shift                                        (20)
#define  ADC_ADC_VBIAS_adc_vbias2_3_shift                                        (19)
#define  ADC_ADC_VBIAS_adc_vbias2_2_0_shift                                      (16)
#define  ADC_ADC_VBIAS_adc_vbias1_7_shift                                        (15)
#define  ADC_ADC_VBIAS_adc_vbias1_6_shift                                        (14)
#define  ADC_ADC_VBIAS_adc_vbias1_5_4_shift                                      (12)
#define  ADC_ADC_VBIAS_adc_vbias1_3_2_shift                                      (10)
#define  ADC_ADC_VBIAS_adc_vbias1_1_shift                                        (9)
#define  ADC_ADC_VBIAS_adc_vbias1_0_shift                                        (8)
#define  ADC_ADC_VBIAS_adc_vbias0_7_5_shift                                      (5)
#define  ADC_ADC_VBIAS_adc_vbias0_4_2_shift                                      (2)
#define  ADC_ADC_VBIAS_adc_vbias0_1_shift                                        (1)
#define  ADC_ADC_VBIAS_adc_vbias0_0_shift                                        (0)
#define  ADC_ADC_VBIAS_adc_vbias3_7_mask                                         (0x80000000)
#define  ADC_ADC_VBIAS_adc_vbias3_6_mask                                         (0x40000000)
#define  ADC_ADC_VBIAS_adc_vbias3_5_mask                                         (0x20000000)
#define  ADC_ADC_VBIAS_adc_vbias3_4_mask                                         (0x10000000)
#define  ADC_ADC_VBIAS_adc_vbias3_3_mask                                         (0x08000000)
#define  ADC_ADC_VBIAS_adc_vbias3_2_mask                                         (0x04000000)
#define  ADC_ADC_VBIAS_adc_vbias3_1_0_mask                                       (0x03000000)
#define  ADC_ADC_VBIAS_adc_vbias2_7_mask                                         (0x00800000)
#define  ADC_ADC_VBIAS_adc_vbias2_6_mask                                         (0x00400000)
#define  ADC_ADC_VBIAS_adc_vbias2_5_mask                                         (0x00200000)
#define  ADC_ADC_VBIAS_adc_vbias2_4_mask                                         (0x00100000)
#define  ADC_ADC_VBIAS_adc_vbias2_3_mask                                         (0x00080000)
#define  ADC_ADC_VBIAS_adc_vbias2_2_0_mask                                       (0x00070000)
#define  ADC_ADC_VBIAS_adc_vbias1_7_mask                                         (0x00008000)
#define  ADC_ADC_VBIAS_adc_vbias1_6_mask                                         (0x00004000)
#define  ADC_ADC_VBIAS_adc_vbias1_5_4_mask                                       (0x00003000)
#define  ADC_ADC_VBIAS_adc_vbias1_3_2_mask                                       (0x00000C00)
#define  ADC_ADC_VBIAS_adc_vbias1_1_mask                                         (0x00000200)
#define  ADC_ADC_VBIAS_adc_vbias1_0_mask                                         (0x00000100)
#define  ADC_ADC_VBIAS_adc_vbias0_7_5_mask                                       (0x000000E0)
#define  ADC_ADC_VBIAS_adc_vbias0_4_2_mask                                       (0x0000001C)
#define  ADC_ADC_VBIAS_adc_vbias0_1_mask                                         (0x00000002)
#define  ADC_ADC_VBIAS_adc_vbias0_0_mask                                         (0x00000001)
#define  ADC_ADC_VBIAS_adc_vbias3_7(data)                                        (0x80000000&((data)<<31))
#define  ADC_ADC_VBIAS_adc_vbias3_6(data)                                        (0x40000000&((data)<<30))
#define  ADC_ADC_VBIAS_adc_vbias3_5(data)                                        (0x20000000&((data)<<29))
#define  ADC_ADC_VBIAS_adc_vbias3_4(data)                                        (0x10000000&((data)<<28))
#define  ADC_ADC_VBIAS_adc_vbias3_3(data)                                        (0x08000000&((data)<<27))
#define  ADC_ADC_VBIAS_adc_vbias3_2(data)                                        (0x04000000&((data)<<26))
#define  ADC_ADC_VBIAS_adc_vbias3_1_0(data)                                      (0x03000000&((data)<<24))
#define  ADC_ADC_VBIAS_adc_vbias2_7(data)                                        (0x00800000&((data)<<23))
#define  ADC_ADC_VBIAS_adc_vbias2_6(data)                                        (0x00400000&((data)<<22))
#define  ADC_ADC_VBIAS_adc_vbias2_5(data)                                        (0x00200000&((data)<<21))
#define  ADC_ADC_VBIAS_adc_vbias2_4(data)                                        (0x00100000&((data)<<20))
#define  ADC_ADC_VBIAS_adc_vbias2_3(data)                                        (0x00080000&((data)<<19))
#define  ADC_ADC_VBIAS_adc_vbias2_2_0(data)                                      (0x00070000&((data)<<16))
#define  ADC_ADC_VBIAS_adc_vbias1_7(data)                                        (0x00008000&((data)<<15))
#define  ADC_ADC_VBIAS_adc_vbias1_6(data)                                        (0x00004000&((data)<<14))
#define  ADC_ADC_VBIAS_adc_vbias1_5_4(data)                                      (0x00003000&((data)<<12))
#define  ADC_ADC_VBIAS_adc_vbias1_3_2(data)                                      (0x00000C00&((data)<<10))
#define  ADC_ADC_VBIAS_adc_vbias1_1(data)                                        (0x00000200&((data)<<9))
#define  ADC_ADC_VBIAS_adc_vbias1_0(data)                                        (0x00000100&((data)<<8))
#define  ADC_ADC_VBIAS_adc_vbias0_7_5(data)                                      (0x000000E0&((data)<<5))
#define  ADC_ADC_VBIAS_adc_vbias0_4_2(data)                                      (0x0000001C&((data)<<2))
#define  ADC_ADC_VBIAS_adc_vbias0_1(data)                                        (0x00000002&((data)<<1))
#define  ADC_ADC_VBIAS_adc_vbias0_0(data)                                        (0x00000001&(data))
#define  ADC_ADC_VBIAS_get_adc_vbias3_7(data)                                    ((0x80000000&(data))>>31)
#define  ADC_ADC_VBIAS_get_adc_vbias3_6(data)                                    ((0x40000000&(data))>>30)
#define  ADC_ADC_VBIAS_get_adc_vbias3_5(data)                                    ((0x20000000&(data))>>29)
#define  ADC_ADC_VBIAS_get_adc_vbias3_4(data)                                    ((0x10000000&(data))>>28)
#define  ADC_ADC_VBIAS_get_adc_vbias3_3(data)                                    ((0x08000000&(data))>>27)
#define  ADC_ADC_VBIAS_get_adc_vbias3_2(data)                                    ((0x04000000&(data))>>26)
#define  ADC_ADC_VBIAS_get_adc_vbias3_1_0(data)                                  ((0x03000000&(data))>>24)
#define  ADC_ADC_VBIAS_get_adc_vbias2_7(data)                                    ((0x00800000&(data))>>23)
#define  ADC_ADC_VBIAS_get_adc_vbias2_6(data)                                    ((0x00400000&(data))>>22)
#define  ADC_ADC_VBIAS_get_adc_vbias2_5(data)                                    ((0x00200000&(data))>>21)
#define  ADC_ADC_VBIAS_get_adc_vbias2_4(data)                                    ((0x00100000&(data))>>20)
#define  ADC_ADC_VBIAS_get_adc_vbias2_3(data)                                    ((0x00080000&(data))>>19)
#define  ADC_ADC_VBIAS_get_adc_vbias2_2_0(data)                                  ((0x00070000&(data))>>16)
#define  ADC_ADC_VBIAS_get_adc_vbias1_7(data)                                    ((0x00008000&(data))>>15)
#define  ADC_ADC_VBIAS_get_adc_vbias1_6(data)                                    ((0x00004000&(data))>>14)
#define  ADC_ADC_VBIAS_get_adc_vbias1_5_4(data)                                  ((0x00003000&(data))>>12)
#define  ADC_ADC_VBIAS_get_adc_vbias1_3_2(data)                                  ((0x00000C00&(data))>>10)
#define  ADC_ADC_VBIAS_get_adc_vbias1_1(data)                                    ((0x00000200&(data))>>9)
#define  ADC_ADC_VBIAS_get_adc_vbias1_0(data)                                    ((0x00000100&(data))>>8)
#define  ADC_ADC_VBIAS_get_adc_vbias0_7_5(data)                                  ((0x000000E0&(data))>>5)
#define  ADC_ADC_VBIAS_get_adc_vbias0_4_2(data)                                  ((0x0000001C&(data))>>2)
#define  ADC_ADC_VBIAS_get_adc_vbias0_1(data)                                    ((0x00000002&(data))>>1)
#define  ADC_ADC_VBIAS_get_adc_vbias0_0(data)                                    (0x00000001&(data))

#define  ADC_ADC_CLOCK                                                           0x18020010
#define  ADC_ADC_CLOCK_reg_addr                                                  "0xB8020010"
#define  ADC_ADC_CLOCK_reg                                                       0xB8020010
#define  ADC_ADC_CLOCK_inst_addr                                                 "0x0004"
#define  set_ADC_ADC_CLOCK_reg(data)                                             (*((volatile unsigned int*)ADC_ADC_CLOCK_reg)=data)
#define  get_ADC_ADC_CLOCK_reg                                                   (*((volatile unsigned int*)ADC_ADC_CLOCK_reg))
#define  ADC_ADC_CLOCK_adc_2x_sample_7_shift                                     (23)
#define  ADC_ADC_CLOCK_adc_2x_sample_6_shift                                     (22)
#define  ADC_ADC_CLOCK_adc_2x_sample_5_shift                                     (21)
#define  ADC_ADC_CLOCK_adc_2x_sample_4_3_shift                                   (19)
#define  ADC_ADC_CLOCK_adc_2x_sample_2_shift                                     (18)
#define  ADC_ADC_CLOCK_adc_2x_sample_1_shift                                     (17)
#define  ADC_ADC_CLOCK_adc_2x_sample_0_shift                                     (16)
#define  ADC_ADC_CLOCK_adc_clock_11_shift                                        (11)
#define  ADC_ADC_CLOCK_adc_clock_10_shift                                        (10)
#define  ADC_ADC_CLOCK_adc_clock_9_8_shift                                       (8)
#define  ADC_ADC_CLOCK_adc_clock_7_shift                                         (7)
#define  ADC_ADC_CLOCK_adc_clock_6_shift                                         (6)
#define  ADC_ADC_CLOCK_adc_clock_5_4_shift                                       (4)
#define  ADC_ADC_CLOCK_adc_clock_3_shift                                         (3)
#define  ADC_ADC_CLOCK_adc_clock_2_shift                                         (2)
#define  ADC_ADC_CLOCK_adc_clock_1_0_shift                                       (0)
#define  ADC_ADC_CLOCK_adc_2x_sample_7_mask                                      (0x00800000)
#define  ADC_ADC_CLOCK_adc_2x_sample_6_mask                                      (0x00400000)
#define  ADC_ADC_CLOCK_adc_2x_sample_5_mask                                      (0x00200000)
#define  ADC_ADC_CLOCK_adc_2x_sample_4_3_mask                                    (0x00180000)
#define  ADC_ADC_CLOCK_adc_2x_sample_2_mask                                      (0x00040000)
#define  ADC_ADC_CLOCK_adc_2x_sample_1_mask                                      (0x00020000)
#define  ADC_ADC_CLOCK_adc_2x_sample_0_mask                                      (0x00010000)
#define  ADC_ADC_CLOCK_adc_clock_11_mask                                         (0x00000800)
#define  ADC_ADC_CLOCK_adc_clock_10_mask                                         (0x00000400)
#define  ADC_ADC_CLOCK_adc_clock_9_8_mask                                        (0x00000300)
#define  ADC_ADC_CLOCK_adc_clock_7_mask                                          (0x00000080)
#define  ADC_ADC_CLOCK_adc_clock_6_mask                                          (0x00000040)
#define  ADC_ADC_CLOCK_adc_clock_5_4_mask                                        (0x00000030)
#define  ADC_ADC_CLOCK_adc_clock_3_mask                                          (0x00000008)
#define  ADC_ADC_CLOCK_adc_clock_2_mask                                          (0x00000004)
#define  ADC_ADC_CLOCK_adc_clock_1_0_mask                                        (0x00000003)
#define  ADC_ADC_CLOCK_adc_2x_sample_7(data)                                     (0x00800000&((data)<<23))
#define  ADC_ADC_CLOCK_adc_2x_sample_6(data)                                     (0x00400000&((data)<<22))
#define  ADC_ADC_CLOCK_adc_2x_sample_5(data)                                     (0x00200000&((data)<<21))
#define  ADC_ADC_CLOCK_adc_2x_sample_4_3(data)                                   (0x00180000&((data)<<19))
#define  ADC_ADC_CLOCK_adc_2x_sample_2(data)                                     (0x00040000&((data)<<18))
#define  ADC_ADC_CLOCK_adc_2x_sample_1(data)                                     (0x00020000&((data)<<17))
#define  ADC_ADC_CLOCK_adc_2x_sample_0(data)                                     (0x00010000&((data)<<16))
#define  ADC_ADC_CLOCK_adc_clock_11(data)                                        (0x00000800&((data)<<11))
#define  ADC_ADC_CLOCK_adc_clock_10(data)                                        (0x00000400&((data)<<10))
#define  ADC_ADC_CLOCK_adc_clock_9_8(data)                                       (0x00000300&((data)<<8))
#define  ADC_ADC_CLOCK_adc_clock_7(data)                                         (0x00000080&((data)<<7))
#define  ADC_ADC_CLOCK_adc_clock_6(data)                                         (0x00000040&((data)<<6))
#define  ADC_ADC_CLOCK_adc_clock_5_4(data)                                       (0x00000030&((data)<<4))
#define  ADC_ADC_CLOCK_adc_clock_3(data)                                         (0x00000008&((data)<<3))
#define  ADC_ADC_CLOCK_adc_clock_2(data)                                         (0x00000004&((data)<<2))
#define  ADC_ADC_CLOCK_adc_clock_1_0(data)                                       (0x00000003&(data))
#define  ADC_ADC_CLOCK_get_adc_2x_sample_7(data)                                 ((0x00800000&(data))>>23)
#define  ADC_ADC_CLOCK_get_adc_2x_sample_6(data)                                 ((0x00400000&(data))>>22)
#define  ADC_ADC_CLOCK_get_adc_2x_sample_5(data)                                 ((0x00200000&(data))>>21)
#define  ADC_ADC_CLOCK_get_adc_2x_sample_4_3(data)                               ((0x00180000&(data))>>19)
#define  ADC_ADC_CLOCK_get_adc_2x_sample_2(data)                                 ((0x00040000&(data))>>18)
#define  ADC_ADC_CLOCK_get_adc_2x_sample_1(data)                                 ((0x00020000&(data))>>17)
#define  ADC_ADC_CLOCK_get_adc_2x_sample_0(data)                                 ((0x00010000&(data))>>16)
#define  ADC_ADC_CLOCK_get_adc_clock_11(data)                                    ((0x00000800&(data))>>11)
#define  ADC_ADC_CLOCK_get_adc_clock_10(data)                                    ((0x00000400&(data))>>10)
#define  ADC_ADC_CLOCK_get_adc_clock_9_8(data)                                   ((0x00000300&(data))>>8)
#define  ADC_ADC_CLOCK_get_adc_clock_7(data)                                     ((0x00000080&(data))>>7)
#define  ADC_ADC_CLOCK_get_adc_clock_6(data)                                     ((0x00000040&(data))>>6)
#define  ADC_ADC_CLOCK_get_adc_clock_5_4(data)                                   ((0x00000030&(data))>>4)
#define  ADC_ADC_CLOCK_get_adc_clock_3(data)                                     ((0x00000008&(data))>>3)
#define  ADC_ADC_CLOCK_get_adc_clock_2(data)                                     ((0x00000004&(data))>>2)
#define  ADC_ADC_CLOCK_get_adc_clock_1_0(data)                                   (0x00000003&(data))

#define  ADC_ADC_DCRESTORE_CTRL                                                  0x18020018
#define  ADC_ADC_DCRESTORE_CTRL_reg_addr                                         "0xB8020018"
#define  ADC_ADC_DCRESTORE_CTRL_reg                                              0xB8020018
#define  ADC_ADC_DCRESTORE_CTRL_inst_addr                                        "0x0005"
#define  set_ADC_ADC_DCRESTORE_CTRL_reg(data)                                    (*((volatile unsigned int*)ADC_ADC_DCRESTORE_CTRL_reg)=data)
#define  get_ADC_ADC_DCRESTORE_CTRL_reg                                          (*((volatile unsigned int*)ADC_ADC_DCRESTORE_CTRL_reg))
#define  ADC_ADC_DCRESTORE_CTRL_adc_ctl_rgb_7_shift                              (23)
#define  ADC_ADC_DCRESTORE_CTRL_adc_ctl_rgb_6_shift                              (22)
#define  ADC_ADC_DCRESTORE_CTRL_adc_ctl_rgb_5_shift                              (21)
#define  ADC_ADC_DCRESTORE_CTRL_adc_ctl_rgb_4_shift                              (20)
#define  ADC_ADC_DCRESTORE_CTRL_adc_ctl_rgb_3_0_shift                            (16)
#define  ADC_ADC_DCRESTORE_CTRL_adc_dcrestore_ctrl_8_shift                       (8)
#define  ADC_ADC_DCRESTORE_CTRL_adc_dcrestore_ctrl_7_6_shift                     (6)
#define  ADC_ADC_DCRESTORE_CTRL_adc_dcrestore_ctrl_5_shift                       (5)
#define  ADC_ADC_DCRESTORE_CTRL_adc_dcrestore_ctrl_4_3_shift                     (3)
#define  ADC_ADC_DCRESTORE_CTRL_adc_dcrestore_ctrl_2_shift                       (2)
#define  ADC_ADC_DCRESTORE_CTRL_adc_dcrestore_ctrl_1_0_shift                     (0)
#define  ADC_ADC_DCRESTORE_CTRL_adc_ctl_rgb_7_mask                               (0x00800000)
#define  ADC_ADC_DCRESTORE_CTRL_adc_ctl_rgb_6_mask                               (0x00400000)
#define  ADC_ADC_DCRESTORE_CTRL_adc_ctl_rgb_5_mask                               (0x00200000)
#define  ADC_ADC_DCRESTORE_CTRL_adc_ctl_rgb_4_mask                               (0x00100000)
#define  ADC_ADC_DCRESTORE_CTRL_adc_ctl_rgb_3_0_mask                             (0x000F0000)
#define  ADC_ADC_DCRESTORE_CTRL_adc_dcrestore_ctrl_8_mask                        (0x00000100)
#define  ADC_ADC_DCRESTORE_CTRL_adc_dcrestore_ctrl_7_6_mask                      (0x000000C0)
#define  ADC_ADC_DCRESTORE_CTRL_adc_dcrestore_ctrl_5_mask                        (0x00000020)
#define  ADC_ADC_DCRESTORE_CTRL_adc_dcrestore_ctrl_4_3_mask                      (0x00000018)
#define  ADC_ADC_DCRESTORE_CTRL_adc_dcrestore_ctrl_2_mask                        (0x00000004)
#define  ADC_ADC_DCRESTORE_CTRL_adc_dcrestore_ctrl_1_0_mask                      (0x00000003)
#define  ADC_ADC_DCRESTORE_CTRL_adc_ctl_rgb_7(data)                              (0x00800000&((data)<<23))
#define  ADC_ADC_DCRESTORE_CTRL_adc_ctl_rgb_6(data)                              (0x00400000&((data)<<22))
#define  ADC_ADC_DCRESTORE_CTRL_adc_ctl_rgb_5(data)                              (0x00200000&((data)<<21))
#define  ADC_ADC_DCRESTORE_CTRL_adc_ctl_rgb_4(data)                              (0x00100000&((data)<<20))
#define  ADC_ADC_DCRESTORE_CTRL_adc_ctl_rgb_3_0(data)                            (0x000F0000&((data)<<16))
#define  ADC_ADC_DCRESTORE_CTRL_adc_dcrestore_ctrl_8(data)                       (0x00000100&((data)<<8))
#define  ADC_ADC_DCRESTORE_CTRL_adc_dcrestore_ctrl_7_6(data)                     (0x000000C0&((data)<<6))
#define  ADC_ADC_DCRESTORE_CTRL_adc_dcrestore_ctrl_5(data)                       (0x00000020&((data)<<5))
#define  ADC_ADC_DCRESTORE_CTRL_adc_dcrestore_ctrl_4_3(data)                     (0x00000018&((data)<<3))
#define  ADC_ADC_DCRESTORE_CTRL_adc_dcrestore_ctrl_2(data)                       (0x00000004&((data)<<2))
#define  ADC_ADC_DCRESTORE_CTRL_adc_dcrestore_ctrl_1_0(data)                     (0x00000003&(data))
#define  ADC_ADC_DCRESTORE_CTRL_get_adc_ctl_rgb_7(data)                          ((0x00800000&(data))>>23)
#define  ADC_ADC_DCRESTORE_CTRL_get_adc_ctl_rgb_6(data)                          ((0x00400000&(data))>>22)
#define  ADC_ADC_DCRESTORE_CTRL_get_adc_ctl_rgb_5(data)                          ((0x00200000&(data))>>21)
#define  ADC_ADC_DCRESTORE_CTRL_get_adc_ctl_rgb_4(data)                          ((0x00100000&(data))>>20)
#define  ADC_ADC_DCRESTORE_CTRL_get_adc_ctl_rgb_3_0(data)                        ((0x000F0000&(data))>>16)
#define  ADC_ADC_DCRESTORE_CTRL_get_adc_dcrestore_ctrl_8(data)                   ((0x00000100&(data))>>8)
#define  ADC_ADC_DCRESTORE_CTRL_get_adc_dcrestore_ctrl_7_6(data)                 ((0x000000C0&(data))>>6)
#define  ADC_ADC_DCRESTORE_CTRL_get_adc_dcrestore_ctrl_5(data)                   ((0x00000020&(data))>>5)
#define  ADC_ADC_DCRESTORE_CTRL_get_adc_dcrestore_ctrl_4_3(data)                 ((0x00000018&(data))>>3)
#define  ADC_ADC_DCRESTORE_CTRL_get_adc_dcrestore_ctrl_2(data)                   ((0x00000004&(data))>>2)
#define  ADC_ADC_DCRESTORE_CTRL_get_adc_dcrestore_ctrl_1_0(data)                 (0x00000003&(data))

#define  ADC_ADC_CLAMP_CTRL0                                                     0x1802001C
#define  ADC_ADC_CLAMP_CTRL0_reg_addr                                            "0xB802001C"
#define  ADC_ADC_CLAMP_CTRL0_reg                                                 0xB802001C
#define  ADC_ADC_CLAMP_CTRL0_inst_addr                                           "0x0006"
#define  set_ADC_ADC_CLAMP_CTRL0_reg(data)                                       (*((volatile unsigned int*)ADC_ADC_CLAMP_CTRL0_reg)=data)
#define  get_ADC_ADC_CLAMP_CTRL0_reg                                             (*((volatile unsigned int*)ADC_ADC_CLAMP_CTRL0_reg))
#define  ADC_ADC_CLAMP_CTRL0_adc_clamp_ctrl2_11_shift                            (27)
#define  ADC_ADC_CLAMP_CTRL0_adc_clamp_ctrl2_10_9_shift                          (25)
#define  ADC_ADC_CLAMP_CTRL0_adc_clamp_ctrl2_8_shift                             (24)
#define  ADC_ADC_CLAMP_CTRL0_adc_clamp_ctrl2_7_6_shift                           (22)
#define  ADC_ADC_CLAMP_CTRL0_adc_clamp_ctrl2_5_shift                             (21)
#define  ADC_ADC_CLAMP_CTRL0_adc_clamp_ctrl2_4_3_shift                           (19)
#define  ADC_ADC_CLAMP_CTRL0_adc_clamp_ctrl2_2_shift                             (18)
#define  ADC_ADC_CLAMP_CTRL0_adc_clamp_ctrl2_1_shift                             (17)
#define  ADC_ADC_CLAMP_CTRL0_adc_clamp_ctrl2_0_shift                             (16)
#define  ADC_ADC_CLAMP_CTRL0_adc_clamp_ctrl1_8_shift                             (8)
#define  ADC_ADC_CLAMP_CTRL0_adc_clamp_ctrl1_7_6_shift                           (6)
#define  ADC_ADC_CLAMP_CTRL0_adc_clamp_ctrl1_5_shift                             (5)
#define  ADC_ADC_CLAMP_CTRL0_adc_clamp_ctrl1_4_3_shift                           (3)
#define  ADC_ADC_CLAMP_CTRL0_adc_clamp_ctrl1_2_shift                             (2)
#define  ADC_ADC_CLAMP_CTRL0_adc_clamp_ctrl1_1_0_shift                           (0)
#define  ADC_ADC_CLAMP_CTRL0_adc_clamp_ctrl2_11_mask                             (0x08000000)
#define  ADC_ADC_CLAMP_CTRL0_adc_clamp_ctrl2_10_9_mask                           (0x06000000)
#define  ADC_ADC_CLAMP_CTRL0_adc_clamp_ctrl2_8_mask                              (0x01000000)
#define  ADC_ADC_CLAMP_CTRL0_adc_clamp_ctrl2_7_6_mask                            (0x00C00000)
#define  ADC_ADC_CLAMP_CTRL0_adc_clamp_ctrl2_5_mask                              (0x00200000)
#define  ADC_ADC_CLAMP_CTRL0_adc_clamp_ctrl2_4_3_mask                            (0x00180000)
#define  ADC_ADC_CLAMP_CTRL0_adc_clamp_ctrl2_2_mask                              (0x00040000)
#define  ADC_ADC_CLAMP_CTRL0_adc_clamp_ctrl2_1_mask                              (0x00020000)
#define  ADC_ADC_CLAMP_CTRL0_adc_clamp_ctrl2_0_mask                              (0x00010000)
#define  ADC_ADC_CLAMP_CTRL0_adc_clamp_ctrl1_8_mask                              (0x00000100)
#define  ADC_ADC_CLAMP_CTRL0_adc_clamp_ctrl1_7_6_mask                            (0x000000C0)
#define  ADC_ADC_CLAMP_CTRL0_adc_clamp_ctrl1_5_mask                              (0x00000020)
#define  ADC_ADC_CLAMP_CTRL0_adc_clamp_ctrl1_4_3_mask                            (0x00000018)
#define  ADC_ADC_CLAMP_CTRL0_adc_clamp_ctrl1_2_mask                              (0x00000004)
#define  ADC_ADC_CLAMP_CTRL0_adc_clamp_ctrl1_1_0_mask                            (0x00000003)
#define  ADC_ADC_CLAMP_CTRL0_adc_clamp_ctrl2_11(data)                            (0x08000000&((data)<<27))
#define  ADC_ADC_CLAMP_CTRL0_adc_clamp_ctrl2_10_9(data)                          (0x06000000&((data)<<25))
#define  ADC_ADC_CLAMP_CTRL0_adc_clamp_ctrl2_8(data)                             (0x01000000&((data)<<24))
#define  ADC_ADC_CLAMP_CTRL0_adc_clamp_ctrl2_7_6(data)                           (0x00C00000&((data)<<22))
#define  ADC_ADC_CLAMP_CTRL0_adc_clamp_ctrl2_5(data)                             (0x00200000&((data)<<21))
#define  ADC_ADC_CLAMP_CTRL0_adc_clamp_ctrl2_4_3(data)                           (0x00180000&((data)<<19))
#define  ADC_ADC_CLAMP_CTRL0_adc_clamp_ctrl2_2(data)                             (0x00040000&((data)<<18))
#define  ADC_ADC_CLAMP_CTRL0_adc_clamp_ctrl2_1(data)                             (0x00020000&((data)<<17))
#define  ADC_ADC_CLAMP_CTRL0_adc_clamp_ctrl2_0(data)                             (0x00010000&((data)<<16))
#define  ADC_ADC_CLAMP_CTRL0_adc_clamp_ctrl1_8(data)                             (0x00000100&((data)<<8))
#define  ADC_ADC_CLAMP_CTRL0_adc_clamp_ctrl1_7_6(data)                           (0x000000C0&((data)<<6))
#define  ADC_ADC_CLAMP_CTRL0_adc_clamp_ctrl1_5(data)                             (0x00000020&((data)<<5))
#define  ADC_ADC_CLAMP_CTRL0_adc_clamp_ctrl1_4_3(data)                           (0x00000018&((data)<<3))
#define  ADC_ADC_CLAMP_CTRL0_adc_clamp_ctrl1_2(data)                             (0x00000004&((data)<<2))
#define  ADC_ADC_CLAMP_CTRL0_adc_clamp_ctrl1_1_0(data)                           (0x00000003&(data))
#define  ADC_ADC_CLAMP_CTRL0_get_adc_clamp_ctrl2_11(data)                        ((0x08000000&(data))>>27)
#define  ADC_ADC_CLAMP_CTRL0_get_adc_clamp_ctrl2_10_9(data)                      ((0x06000000&(data))>>25)
#define  ADC_ADC_CLAMP_CTRL0_get_adc_clamp_ctrl2_8(data)                         ((0x01000000&(data))>>24)
#define  ADC_ADC_CLAMP_CTRL0_get_adc_clamp_ctrl2_7_6(data)                       ((0x00C00000&(data))>>22)
#define  ADC_ADC_CLAMP_CTRL0_get_adc_clamp_ctrl2_5(data)                         ((0x00200000&(data))>>21)
#define  ADC_ADC_CLAMP_CTRL0_get_adc_clamp_ctrl2_4_3(data)                       ((0x00180000&(data))>>19)
#define  ADC_ADC_CLAMP_CTRL0_get_adc_clamp_ctrl2_2(data)                         ((0x00040000&(data))>>18)
#define  ADC_ADC_CLAMP_CTRL0_get_adc_clamp_ctrl2_1(data)                         ((0x00020000&(data))>>17)
#define  ADC_ADC_CLAMP_CTRL0_get_adc_clamp_ctrl2_0(data)                         ((0x00010000&(data))>>16)
#define  ADC_ADC_CLAMP_CTRL0_get_adc_clamp_ctrl1_8(data)                         ((0x00000100&(data))>>8)
#define  ADC_ADC_CLAMP_CTRL0_get_adc_clamp_ctrl1_7_6(data)                       ((0x000000C0&(data))>>6)
#define  ADC_ADC_CLAMP_CTRL0_get_adc_clamp_ctrl1_5(data)                         ((0x00000020&(data))>>5)
#define  ADC_ADC_CLAMP_CTRL0_get_adc_clamp_ctrl1_4_3(data)                       ((0x00000018&(data))>>3)
#define  ADC_ADC_CLAMP_CTRL0_get_adc_clamp_ctrl1_2(data)                         ((0x00000004&(data))>>2)
#define  ADC_ADC_CLAMP_CTRL0_get_adc_clamp_ctrl1_1_0(data)                       (0x00000003&(data))

#define  ADC_ADC_CLAMP_CTRL1                                                     0x18020020
#define  ADC_ADC_CLAMP_CTRL1_reg_addr                                            "0xB8020020"
#define  ADC_ADC_CLAMP_CTRL1_reg                                                 0xB8020020
#define  ADC_ADC_CLAMP_CTRL1_inst_addr                                           "0x0007"
#define  set_ADC_ADC_CLAMP_CTRL1_reg(data)                                       (*((volatile unsigned int*)ADC_ADC_CLAMP_CTRL1_reg)=data)
#define  get_ADC_ADC_CLAMP_CTRL1_reg                                             (*((volatile unsigned int*)ADC_ADC_CLAMP_CTRL1_reg))
#define  ADC_ADC_CLAMP_CTRL1_adc_clamp_ctrl4_7_shift                             (23)
#define  ADC_ADC_CLAMP_CTRL1_adc_clamp_ctrl4_6_shift                             (22)
#define  ADC_ADC_CLAMP_CTRL1_adc_clamp_ctrl4_5_shift                             (21)
#define  ADC_ADC_CLAMP_CTRL1_adc_clamp_ctrl4_4_0_shift                           (16)
#define  ADC_ADC_CLAMP_CTRL1_adc_clamp_ctrl0_8_shift                             (8)
#define  ADC_ADC_CLAMP_CTRL1_adc_clamp_ctrl0_7_6_shift                           (6)
#define  ADC_ADC_CLAMP_CTRL1_adc_clamp_ctrl0_5_shift                             (5)
#define  ADC_ADC_CLAMP_CTRL1_adc_clamp_ctrl0_4_3_shift                           (3)
#define  ADC_ADC_CLAMP_CTRL1_adc_clamp_ctrl0_2_shift                             (2)
#define  ADC_ADC_CLAMP_CTRL1_adc_clamp_ctrl0_1_0_shift                           (0)
#define  ADC_ADC_CLAMP_CTRL1_adc_clamp_ctrl4_7_mask                              (0x00800000)
#define  ADC_ADC_CLAMP_CTRL1_adc_clamp_ctrl4_6_mask                              (0x00400000)
#define  ADC_ADC_CLAMP_CTRL1_adc_clamp_ctrl4_5_mask                              (0x00200000)
#define  ADC_ADC_CLAMP_CTRL1_adc_clamp_ctrl4_4_0_mask                            (0x001F0000)
#define  ADC_ADC_CLAMP_CTRL1_adc_clamp_ctrl0_8_mask                              (0x00000100)
#define  ADC_ADC_CLAMP_CTRL1_adc_clamp_ctrl0_7_6_mask                            (0x000000C0)
#define  ADC_ADC_CLAMP_CTRL1_adc_clamp_ctrl0_5_mask                              (0x00000020)
#define  ADC_ADC_CLAMP_CTRL1_adc_clamp_ctrl0_4_3_mask                            (0x00000018)
#define  ADC_ADC_CLAMP_CTRL1_adc_clamp_ctrl0_2_mask                              (0x00000004)
#define  ADC_ADC_CLAMP_CTRL1_adc_clamp_ctrl0_1_0_mask                            (0x00000003)
#define  ADC_ADC_CLAMP_CTRL1_adc_clamp_ctrl4_7(data)                             (0x00800000&((data)<<23))
#define  ADC_ADC_CLAMP_CTRL1_adc_clamp_ctrl4_6(data)                             (0x00400000&((data)<<22))
#define  ADC_ADC_CLAMP_CTRL1_adc_clamp_ctrl4_5(data)                             (0x00200000&((data)<<21))
#define  ADC_ADC_CLAMP_CTRL1_adc_clamp_ctrl4_4_0(data)                           (0x001F0000&((data)<<16))
#define  ADC_ADC_CLAMP_CTRL1_adc_clamp_ctrl0_8(data)                             (0x00000100&((data)<<8))
#define  ADC_ADC_CLAMP_CTRL1_adc_clamp_ctrl0_7_6(data)                           (0x000000C0&((data)<<6))
#define  ADC_ADC_CLAMP_CTRL1_adc_clamp_ctrl0_5(data)                             (0x00000020&((data)<<5))
#define  ADC_ADC_CLAMP_CTRL1_adc_clamp_ctrl0_4_3(data)                           (0x00000018&((data)<<3))
#define  ADC_ADC_CLAMP_CTRL1_adc_clamp_ctrl0_2(data)                             (0x00000004&((data)<<2))
#define  ADC_ADC_CLAMP_CTRL1_adc_clamp_ctrl0_1_0(data)                           (0x00000003&(data))
#define  ADC_ADC_CLAMP_CTRL1_get_adc_clamp_ctrl4_7(data)                         ((0x00800000&(data))>>23)
#define  ADC_ADC_CLAMP_CTRL1_get_adc_clamp_ctrl4_6(data)                         ((0x00400000&(data))>>22)
#define  ADC_ADC_CLAMP_CTRL1_get_adc_clamp_ctrl4_5(data)                         ((0x00200000&(data))>>21)
#define  ADC_ADC_CLAMP_CTRL1_get_adc_clamp_ctrl4_4_0(data)                       ((0x001F0000&(data))>>16)
#define  ADC_ADC_CLAMP_CTRL1_get_adc_clamp_ctrl0_8(data)                         ((0x00000100&(data))>>8)
#define  ADC_ADC_CLAMP_CTRL1_get_adc_clamp_ctrl0_7_6(data)                       ((0x000000C0&(data))>>6)
#define  ADC_ADC_CLAMP_CTRL1_get_adc_clamp_ctrl0_5(data)                         ((0x00000020&(data))>>5)
#define  ADC_ADC_CLAMP_CTRL1_get_adc_clamp_ctrl0_4_3(data)                       ((0x00000018&(data))>>3)
#define  ADC_ADC_CLAMP_CTRL1_get_adc_clamp_ctrl0_2(data)                         ((0x00000004&(data))>>2)
#define  ADC_ADC_CLAMP_CTRL1_get_adc_clamp_ctrl0_1_0(data)                       (0x00000003&(data))

#define  ADC_ADC_CLAMP_CTRL2                                                     0x18020024
#define  ADC_ADC_CLAMP_CTRL2_reg_addr                                            "0xB8020024"
#define  ADC_ADC_CLAMP_CTRL2_reg                                                 0xB8020024
#define  ADC_ADC_CLAMP_CTRL2_inst_addr                                           "0x0008"
#define  set_ADC_ADC_CLAMP_CTRL2_reg(data)                                       (*((volatile unsigned int*)ADC_ADC_CLAMP_CTRL2_reg)=data)
#define  get_ADC_ADC_CLAMP_CTRL2_reg                                             (*((volatile unsigned int*)ADC_ADC_CLAMP_CTRL2_reg))
#define  ADC_ADC_CLAMP_CTRL2_adc_sog_cmp_7_4_shift                               (28)
#define  ADC_ADC_CLAMP_CTRL2_adc_sog_cmp_3_0_shift                               (24)
#define  ADC_ADC_CLAMP_CTRL2_adc_sog_cmp1_7_shift                                (23)
#define  ADC_ADC_CLAMP_CTRL2_adc_sog_cmp1_6_shift                                (22)
#define  ADC_ADC_CLAMP_CTRL2_adc_sog_cmp1_5_0_shift                              (16)
#define  ADC_ADC_CLAMP_CTRL2_adc_clamp_ctrl3_8_shift                             (8)
#define  ADC_ADC_CLAMP_CTRL2_adc_clamp_ctrl3_7_6_shift                           (6)
#define  ADC_ADC_CLAMP_CTRL2_adc_clamp_ctrl3_5_shift                             (5)
#define  ADC_ADC_CLAMP_CTRL2_adc_clamp_ctrl3_4_3_shift                           (3)
#define  ADC_ADC_CLAMP_CTRL2_adc_clamp_ctrl3_2_shift                             (2)
#define  ADC_ADC_CLAMP_CTRL2_adc_clamp_ctrl3_1_0_shift                           (0)
#define  ADC_ADC_CLAMP_CTRL2_adc_sog_cmp_7_4_mask                                (0xF0000000)
#define  ADC_ADC_CLAMP_CTRL2_adc_sog_cmp_3_0_mask                                (0x0F000000)
#define  ADC_ADC_CLAMP_CTRL2_adc_sog_cmp1_7_mask                                 (0x00800000)
#define  ADC_ADC_CLAMP_CTRL2_adc_sog_cmp1_6_mask                                 (0x00400000)
#define  ADC_ADC_CLAMP_CTRL2_adc_sog_cmp1_5_0_mask                               (0x003F0000)
#define  ADC_ADC_CLAMP_CTRL2_adc_clamp_ctrl3_8_mask                              (0x00000100)
#define  ADC_ADC_CLAMP_CTRL2_adc_clamp_ctrl3_7_6_mask                            (0x000000C0)
#define  ADC_ADC_CLAMP_CTRL2_adc_clamp_ctrl3_5_mask                              (0x00000020)
#define  ADC_ADC_CLAMP_CTRL2_adc_clamp_ctrl3_4_3_mask                            (0x00000018)
#define  ADC_ADC_CLAMP_CTRL2_adc_clamp_ctrl3_2_mask                              (0x00000004)
#define  ADC_ADC_CLAMP_CTRL2_adc_clamp_ctrl3_1_0_mask                            (0x00000003)
#define  ADC_ADC_CLAMP_CTRL2_adc_sog_cmp_7_4(data)                               (0xF0000000&((data)<<28))
#define  ADC_ADC_CLAMP_CTRL2_adc_sog_cmp_3_0(data)                               (0x0F000000&((data)<<24))
#define  ADC_ADC_CLAMP_CTRL2_adc_sog_cmp1_7(data)                                (0x00800000&((data)<<23))
#define  ADC_ADC_CLAMP_CTRL2_adc_sog_cmp1_6(data)                                (0x00400000&((data)<<22))
#define  ADC_ADC_CLAMP_CTRL2_adc_sog_cmp1_5_0(data)                              (0x003F0000&((data)<<16))
#define  ADC_ADC_CLAMP_CTRL2_adc_clamp_ctrl3_8(data)                             (0x00000100&((data)<<8))
#define  ADC_ADC_CLAMP_CTRL2_adc_clamp_ctrl3_7_6(data)                           (0x000000C0&((data)<<6))
#define  ADC_ADC_CLAMP_CTRL2_adc_clamp_ctrl3_5(data)                             (0x00000020&((data)<<5))
#define  ADC_ADC_CLAMP_CTRL2_adc_clamp_ctrl3_4_3(data)                           (0x00000018&((data)<<3))
#define  ADC_ADC_CLAMP_CTRL2_adc_clamp_ctrl3_2(data)                             (0x00000004&((data)<<2))
#define  ADC_ADC_CLAMP_CTRL2_adc_clamp_ctrl3_1_0(data)                           (0x00000003&(data))
#define  ADC_ADC_CLAMP_CTRL2_get_adc_sog_cmp_7_4(data)                           ((0xF0000000&(data))>>28)
#define  ADC_ADC_CLAMP_CTRL2_get_adc_sog_cmp_3_0(data)                           ((0x0F000000&(data))>>24)
#define  ADC_ADC_CLAMP_CTRL2_get_adc_sog_cmp1_7(data)                            ((0x00800000&(data))>>23)
#define  ADC_ADC_CLAMP_CTRL2_get_adc_sog_cmp1_6(data)                            ((0x00400000&(data))>>22)
#define  ADC_ADC_CLAMP_CTRL2_get_adc_sog_cmp1_5_0(data)                          ((0x003F0000&(data))>>16)
#define  ADC_ADC_CLAMP_CTRL2_get_adc_clamp_ctrl3_8(data)                         ((0x00000100&(data))>>8)
#define  ADC_ADC_CLAMP_CTRL2_get_adc_clamp_ctrl3_7_6(data)                       ((0x000000C0&(data))>>6)
#define  ADC_ADC_CLAMP_CTRL2_get_adc_clamp_ctrl3_5(data)                         ((0x00000020&(data))>>5)
#define  ADC_ADC_CLAMP_CTRL2_get_adc_clamp_ctrl3_4_3(data)                       ((0x00000018&(data))>>3)
#define  ADC_ADC_CLAMP_CTRL2_get_adc_clamp_ctrl3_2(data)                         ((0x00000004&(data))>>2)
#define  ADC_ADC_CLAMP_CTRL2_get_adc_clamp_ctrl3_1_0(data)                       (0x00000003&(data))

#define  ADC_ADC_CLAMP_CTRL3                                                     0x18020028
#define  ADC_ADC_CLAMP_CTRL3_reg_addr                                            "0xB8020028"
#define  ADC_ADC_CLAMP_CTRL3_reg                                                 0xB8020028
#define  ADC_ADC_CLAMP_CTRL3_inst_addr                                           "0x0009"
#define  set_ADC_ADC_CLAMP_CTRL3_reg(data)                                       (*((volatile unsigned int*)ADC_ADC_CLAMP_CTRL3_reg)=data)
#define  get_ADC_ADC_CLAMP_CTRL3_reg                                             (*((volatile unsigned int*)ADC_ADC_CLAMP_CTRL3_reg))
#define  ADC_ADC_CLAMP_CTRL3_adc_clamp_ctrl6_7_shift                             (23)
#define  ADC_ADC_CLAMP_CTRL3_adc_clamp_ctrl6_6_shift                             (22)
#define  ADC_ADC_CLAMP_CTRL3_adc_clamp_ctrl6_5_shift                             (21)
#define  ADC_ADC_CLAMP_CTRL3_adc_clamp_ctrl6_4_shift                             (20)
#define  ADC_ADC_CLAMP_CTRL3_adc_clamp_ctrl6_3_shift                             (19)
#define  ADC_ADC_CLAMP_CTRL3_adc_clamp_ctrl6_2_shift                             (18)
#define  ADC_ADC_CLAMP_CTRL3_adc_clamp_ctrl6_1_shift                             (17)
#define  ADC_ADC_CLAMP_CTRL3_adc_clamp_ctrl6_0_shift                             (16)
#define  ADC_ADC_CLAMP_CTRL3_adc_clamp_ctrl5_15_shift                            (15)
#define  ADC_ADC_CLAMP_CTRL3_adc_clamp_ctrl5_14_13_shift                         (13)
#define  ADC_ADC_CLAMP_CTRL3_adc_clamp_ctrl5_12_shift                            (12)
#define  ADC_ADC_CLAMP_CTRL3_adc_clamp_ctrl5_11_10_shift                         (10)
#define  ADC_ADC_CLAMP_CTRL3_adc_clamp_ctrl5_9_7_shift                           (7)
#define  ADC_ADC_CLAMP_CTRL3_adc_clamp_ctrl5_6_shift                             (6)
#define  ADC_ADC_CLAMP_CTRL3_adc_clamp_ctrl5_5_shift                             (5)
#define  ADC_ADC_CLAMP_CTRL3_adc_clamp_ctrl5_4_shift                             (4)
#define  ADC_ADC_CLAMP_CTRL3_adc_clamp_ctrl5_3_shift                             (3)
#define  ADC_ADC_CLAMP_CTRL3_adc_clamp_ctrl5_2_1_shift                           (1)
#define  ADC_ADC_CLAMP_CTRL3_adc_clamp_ctrl5_0_shift                             (0)
#define  ADC_ADC_CLAMP_CTRL3_adc_clamp_ctrl6_7_mask                              (0x00800000)
#define  ADC_ADC_CLAMP_CTRL3_adc_clamp_ctrl6_6_mask                              (0x00400000)
#define  ADC_ADC_CLAMP_CTRL3_adc_clamp_ctrl6_5_mask                              (0x00200000)
#define  ADC_ADC_CLAMP_CTRL3_adc_clamp_ctrl6_4_mask                              (0x00100000)
#define  ADC_ADC_CLAMP_CTRL3_adc_clamp_ctrl6_3_mask                              (0x00080000)
#define  ADC_ADC_CLAMP_CTRL3_adc_clamp_ctrl6_2_mask                              (0x00040000)
#define  ADC_ADC_CLAMP_CTRL3_adc_clamp_ctrl6_1_mask                              (0x00020000)
#define  ADC_ADC_CLAMP_CTRL3_adc_clamp_ctrl6_0_mask                              (0x00010000)
#define  ADC_ADC_CLAMP_CTRL3_adc_clamp_ctrl5_15_mask                             (0x00008000)
#define  ADC_ADC_CLAMP_CTRL3_adc_clamp_ctrl5_14_13_mask                          (0x00006000)
#define  ADC_ADC_CLAMP_CTRL3_adc_clamp_ctrl5_12_mask                             (0x00001000)
#define  ADC_ADC_CLAMP_CTRL3_adc_clamp_ctrl5_11_10_mask                          (0x00000C00)
#define  ADC_ADC_CLAMP_CTRL3_adc_clamp_ctrl5_9_7_mask                            (0x00000380)
#define  ADC_ADC_CLAMP_CTRL3_adc_clamp_ctrl5_6_mask                              (0x00000040)
#define  ADC_ADC_CLAMP_CTRL3_adc_clamp_ctrl5_5_mask                              (0x00000020)
#define  ADC_ADC_CLAMP_CTRL3_adc_clamp_ctrl5_4_mask                              (0x00000010)
#define  ADC_ADC_CLAMP_CTRL3_adc_clamp_ctrl5_3_mask                              (0x00000008)
#define  ADC_ADC_CLAMP_CTRL3_adc_clamp_ctrl5_2_1_mask                            (0x00000006)
#define  ADC_ADC_CLAMP_CTRL3_adc_clamp_ctrl5_0_mask                              (0x00000001)
#define  ADC_ADC_CLAMP_CTRL3_adc_clamp_ctrl6_7(data)                             (0x00800000&((data)<<23))
#define  ADC_ADC_CLAMP_CTRL3_adc_clamp_ctrl6_6(data)                             (0x00400000&((data)<<22))
#define  ADC_ADC_CLAMP_CTRL3_adc_clamp_ctrl6_5(data)                             (0x00200000&((data)<<21))
#define  ADC_ADC_CLAMP_CTRL3_adc_clamp_ctrl6_4(data)                             (0x00100000&((data)<<20))
#define  ADC_ADC_CLAMP_CTRL3_adc_clamp_ctrl6_3(data)                             (0x00080000&((data)<<19))
#define  ADC_ADC_CLAMP_CTRL3_adc_clamp_ctrl6_2(data)                             (0x00040000&((data)<<18))
#define  ADC_ADC_CLAMP_CTRL3_adc_clamp_ctrl6_1(data)                             (0x00020000&((data)<<17))
#define  ADC_ADC_CLAMP_CTRL3_adc_clamp_ctrl6_0(data)                             (0x00010000&((data)<<16))
#define  ADC_ADC_CLAMP_CTRL3_adc_clamp_ctrl5_15(data)                            (0x00008000&((data)<<15))
#define  ADC_ADC_CLAMP_CTRL3_adc_clamp_ctrl5_14_13(data)                         (0x00006000&((data)<<13))
#define  ADC_ADC_CLAMP_CTRL3_adc_clamp_ctrl5_12(data)                            (0x00001000&((data)<<12))
#define  ADC_ADC_CLAMP_CTRL3_adc_clamp_ctrl5_11_10(data)                         (0x00000C00&((data)<<10))
#define  ADC_ADC_CLAMP_CTRL3_adc_clamp_ctrl5_9_7(data)                           (0x00000380&((data)<<7))
#define  ADC_ADC_CLAMP_CTRL3_adc_clamp_ctrl5_6(data)                             (0x00000040&((data)<<6))
#define  ADC_ADC_CLAMP_CTRL3_adc_clamp_ctrl5_5(data)                             (0x00000020&((data)<<5))
#define  ADC_ADC_CLAMP_CTRL3_adc_clamp_ctrl5_4(data)                             (0x00000010&((data)<<4))
#define  ADC_ADC_CLAMP_CTRL3_adc_clamp_ctrl5_3(data)                             (0x00000008&((data)<<3))
#define  ADC_ADC_CLAMP_CTRL3_adc_clamp_ctrl5_2_1(data)                           (0x00000006&((data)<<1))
#define  ADC_ADC_CLAMP_CTRL3_adc_clamp_ctrl5_0(data)                             (0x00000001&(data))
#define  ADC_ADC_CLAMP_CTRL3_get_adc_clamp_ctrl6_7(data)                         ((0x00800000&(data))>>23)
#define  ADC_ADC_CLAMP_CTRL3_get_adc_clamp_ctrl6_6(data)                         ((0x00400000&(data))>>22)
#define  ADC_ADC_CLAMP_CTRL3_get_adc_clamp_ctrl6_5(data)                         ((0x00200000&(data))>>21)
#define  ADC_ADC_CLAMP_CTRL3_get_adc_clamp_ctrl6_4(data)                         ((0x00100000&(data))>>20)
#define  ADC_ADC_CLAMP_CTRL3_get_adc_clamp_ctrl6_3(data)                         ((0x00080000&(data))>>19)
#define  ADC_ADC_CLAMP_CTRL3_get_adc_clamp_ctrl6_2(data)                         ((0x00040000&(data))>>18)
#define  ADC_ADC_CLAMP_CTRL3_get_adc_clamp_ctrl6_1(data)                         ((0x00020000&(data))>>17)
#define  ADC_ADC_CLAMP_CTRL3_get_adc_clamp_ctrl6_0(data)                         ((0x00010000&(data))>>16)
#define  ADC_ADC_CLAMP_CTRL3_get_adc_clamp_ctrl5_15(data)                        ((0x00008000&(data))>>15)
#define  ADC_ADC_CLAMP_CTRL3_get_adc_clamp_ctrl5_14_13(data)                     ((0x00006000&(data))>>13)
#define  ADC_ADC_CLAMP_CTRL3_get_adc_clamp_ctrl5_12(data)                        ((0x00001000&(data))>>12)
#define  ADC_ADC_CLAMP_CTRL3_get_adc_clamp_ctrl5_11_10(data)                     ((0x00000C00&(data))>>10)
#define  ADC_ADC_CLAMP_CTRL3_get_adc_clamp_ctrl5_9_7(data)                       ((0x00000380&(data))>>7)
#define  ADC_ADC_CLAMP_CTRL3_get_adc_clamp_ctrl5_6(data)                         ((0x00000040&(data))>>6)
#define  ADC_ADC_CLAMP_CTRL3_get_adc_clamp_ctrl5_5(data)                         ((0x00000020&(data))>>5)
#define  ADC_ADC_CLAMP_CTRL3_get_adc_clamp_ctrl5_4(data)                         ((0x00000010&(data))>>4)
#define  ADC_ADC_CLAMP_CTRL3_get_adc_clamp_ctrl5_3(data)                         ((0x00000008&(data))>>3)
#define  ADC_ADC_CLAMP_CTRL3_get_adc_clamp_ctrl5_2_1(data)                       ((0x00000006&(data))>>1)
#define  ADC_ADC_CLAMP_CTRL3_get_adc_clamp_ctrl5_0(data)                         (0x00000001&(data))

#define  ADC_ADC_GAIN0                                                           0x18020030
#define  ADC_ADC_GAIN0_reg_addr                                                  "0xB8020030"
#define  ADC_ADC_GAIN0_reg                                                       0xB8020030
#define  ADC_ADC_GAIN0_inst_addr                                                 "0x000A"
#define  set_ADC_ADC_GAIN0_reg(data)                                             (*((volatile unsigned int*)ADC_ADC_GAIN0_reg)=data)
#define  get_ADC_ADC_GAIN0_reg                                                   (*((volatile unsigned int*)ADC_ADC_GAIN0_reg))
#define  ADC_ADC_GAIN0_adc_gain_grn_shift                                        (16)
#define  ADC_ADC_GAIN0_dummy_15_9_shift                                          (9)
#define  ADC_ADC_GAIN0_adc_gain_red_shift                                        (0)
#define  ADC_ADC_GAIN0_adc_gain_grn_mask                                         (0x01FF0000)
#define  ADC_ADC_GAIN0_dummy_15_9_mask                                           (0x0000FE00)
#define  ADC_ADC_GAIN0_adc_gain_red_mask                                         (0x000001FF)
#define  ADC_ADC_GAIN0_adc_gain_grn(data)                                        (0x01FF0000&((data)<<16))
#define  ADC_ADC_GAIN0_dummy_15_9(data)                                          (0x0000FE00&((data)<<9))
#define  ADC_ADC_GAIN0_adc_gain_red(data)                                        (0x000001FF&(data))
#define  ADC_ADC_GAIN0_get_adc_gain_grn(data)                                    ((0x01FF0000&(data))>>16)
#define  ADC_ADC_GAIN0_get_dummy_15_9(data)                                      ((0x0000FE00&(data))>>9)
#define  ADC_ADC_GAIN0_get_adc_gain_red(data)                                    (0x000001FF&(data))

#define  ADC_ADC_GAIN1                                                           0x18020034
#define  ADC_ADC_GAIN1_reg_addr                                                  "0xB8020034"
#define  ADC_ADC_GAIN1_reg                                                       0xB8020034
#define  ADC_ADC_GAIN1_inst_addr                                                 "0x000B"
#define  set_ADC_ADC_GAIN1_reg(data)                                             (*((volatile unsigned int*)ADC_ADC_GAIN1_reg)=data)
#define  get_ADC_ADC_GAIN1_reg                                                   (*((volatile unsigned int*)ADC_ADC_GAIN1_reg))
#define  ADC_ADC_GAIN1_adc_gain_blu_shift                                        (0)
#define  ADC_ADC_GAIN1_adc_gain_blu_mask                                         (0x000001FF)
#define  ADC_ADC_GAIN1_adc_gain_blu(data)                                        (0x000001FF&(data))
#define  ADC_ADC_GAIN1_get_adc_gain_blu(data)                                    (0x000001FF&(data))

#define  ADC_ADC_OFFSET0                                                         0x18020038
#define  ADC_ADC_OFFSET0_reg_addr                                                "0xB8020038"
#define  ADC_ADC_OFFSET0_reg                                                     0xB8020038
#define  ADC_ADC_OFFSET0_inst_addr                                               "0x000C"
#define  set_ADC_ADC_OFFSET0_reg(data)                                           (*((volatile unsigned int*)ADC_ADC_OFFSET0_reg)=data)
#define  get_ADC_ADC_OFFSET0_reg                                                 (*((volatile unsigned int*)ADC_ADC_OFFSET0_reg))
#define  ADC_ADC_OFFSET0_adc_off_grn_shift                                       (16)
#define  ADC_ADC_OFFSET0_dummy_15_10_shift                                       (10)
#define  ADC_ADC_OFFSET0_adc_off_red_shift                                       (0)
#define  ADC_ADC_OFFSET0_adc_off_grn_mask                                        (0x03FF0000)
#define  ADC_ADC_OFFSET0_dummy_15_10_mask                                        (0x0000FC00)
#define  ADC_ADC_OFFSET0_adc_off_red_mask                                        (0x000003FF)
#define  ADC_ADC_OFFSET0_adc_off_grn(data)                                       (0x03FF0000&((data)<<16))
#define  ADC_ADC_OFFSET0_dummy_15_10(data)                                       (0x0000FC00&((data)<<10))
#define  ADC_ADC_OFFSET0_adc_off_red(data)                                       (0x000003FF&(data))
#define  ADC_ADC_OFFSET0_get_adc_off_grn(data)                                   ((0x03FF0000&(data))>>16)
#define  ADC_ADC_OFFSET0_get_dummy_15_10(data)                                   ((0x0000FC00&(data))>>10)
#define  ADC_ADC_OFFSET0_get_adc_off_red(data)                                   (0x000003FF&(data))

#define  ADC_ADC_OFFSET1                                                         0x1802003C
#define  ADC_ADC_OFFSET1_reg_addr                                                "0xB802003C"
#define  ADC_ADC_OFFSET1_reg                                                     0xB802003C
#define  ADC_ADC_OFFSET1_inst_addr                                               "0x000D"
#define  set_ADC_ADC_OFFSET1_reg(data)                                           (*((volatile unsigned int*)ADC_ADC_OFFSET1_reg)=data)
#define  get_ADC_ADC_OFFSET1_reg                                                 (*((volatile unsigned int*)ADC_ADC_OFFSET1_reg))
#define  ADC_ADC_OFFSET1_adc_off_blu_shift                                       (0)
#define  ADC_ADC_OFFSET1_adc_off_blu_mask                                        (0x000003FF)
#define  ADC_ADC_OFFSET1_adc_off_blu(data)                                       (0x000003FF&(data))
#define  ADC_ADC_OFFSET1_get_adc_off_blu(data)                                   (0x000003FF&(data))

#define  ADC_ADC_CTL_1                                                           0x18020040
#define  ADC_ADC_CTL_1_reg_addr                                                  "0xB8020040"
#define  ADC_ADC_CTL_1_reg                                                       0xB8020040
#define  ADC_ADC_CTL_1_inst_addr                                                 "0x000E"
#define  set_ADC_ADC_CTL_1_reg(data)                                             (*((volatile unsigned int*)ADC_ADC_CTL_1_reg)=data)
#define  get_ADC_ADC_CTL_1_reg                                                   (*((volatile unsigned int*)ADC_ADC_CTL_1_reg))
#define  ADC_ADC_CTL_1_adc_ctl_red_10_9_shift                                    (25)
#define  ADC_ADC_CTL_1_adc_ctl_red_8_6_shift                                     (22)
#define  ADC_ADC_CTL_1_adc_ctl_red_5_3_shift                                     (19)
#define  ADC_ADC_CTL_1_adc_ctl_red_2_0_shift                                     (16)
#define  ADC_ADC_CTL_1_adc_ctl_grn_10_9_shift                                    (9)
#define  ADC_ADC_CTL_1_adc_ctl_grn_8_6_shift                                     (6)
#define  ADC_ADC_CTL_1_adc_ctl_grn_5_3_shift                                     (3)
#define  ADC_ADC_CTL_1_adc_ctl_grn_2_0_shift                                     (0)
#define  ADC_ADC_CTL_1_adc_ctl_red_10_9_mask                                     (0x06000000)
#define  ADC_ADC_CTL_1_adc_ctl_red_8_6_mask                                      (0x01C00000)
#define  ADC_ADC_CTL_1_adc_ctl_red_5_3_mask                                      (0x00380000)
#define  ADC_ADC_CTL_1_adc_ctl_red_2_0_mask                                      (0x00070000)
#define  ADC_ADC_CTL_1_adc_ctl_grn_10_9_mask                                     (0x00000600)
#define  ADC_ADC_CTL_1_adc_ctl_grn_8_6_mask                                      (0x000001C0)
#define  ADC_ADC_CTL_1_adc_ctl_grn_5_3_mask                                      (0x00000038)
#define  ADC_ADC_CTL_1_adc_ctl_grn_2_0_mask                                      (0x00000007)
#define  ADC_ADC_CTL_1_adc_ctl_red_10_9(data)                                    (0x06000000&((data)<<25))
#define  ADC_ADC_CTL_1_adc_ctl_red_8_6(data)                                     (0x01C00000&((data)<<22))
#define  ADC_ADC_CTL_1_adc_ctl_red_5_3(data)                                     (0x00380000&((data)<<19))
#define  ADC_ADC_CTL_1_adc_ctl_red_2_0(data)                                     (0x00070000&((data)<<16))
#define  ADC_ADC_CTL_1_adc_ctl_grn_10_9(data)                                    (0x00000600&((data)<<9))
#define  ADC_ADC_CTL_1_adc_ctl_grn_8_6(data)                                     (0x000001C0&((data)<<6))
#define  ADC_ADC_CTL_1_adc_ctl_grn_5_3(data)                                     (0x00000038&((data)<<3))
#define  ADC_ADC_CTL_1_adc_ctl_grn_2_0(data)                                     (0x00000007&(data))
#define  ADC_ADC_CTL_1_get_adc_ctl_red_10_9(data)                                ((0x06000000&(data))>>25)
#define  ADC_ADC_CTL_1_get_adc_ctl_red_8_6(data)                                 ((0x01C00000&(data))>>22)
#define  ADC_ADC_CTL_1_get_adc_ctl_red_5_3(data)                                 ((0x00380000&(data))>>19)
#define  ADC_ADC_CTL_1_get_adc_ctl_red_2_0(data)                                 ((0x00070000&(data))>>16)
#define  ADC_ADC_CTL_1_get_adc_ctl_grn_10_9(data)                                ((0x00000600&(data))>>9)
#define  ADC_ADC_CTL_1_get_adc_ctl_grn_8_6(data)                                 ((0x000001C0&(data))>>6)
#define  ADC_ADC_CTL_1_get_adc_ctl_grn_5_3(data)                                 ((0x00000038&(data))>>3)
#define  ADC_ADC_CTL_1_get_adc_ctl_grn_2_0(data)                                 (0x00000007&(data))

#define  ADC_ADC_CTL_2                                                           0x18020044
#define  ADC_ADC_CTL_2_reg_addr                                                  "0xB8020044"
#define  ADC_ADC_CTL_2_reg                                                       0xB8020044
#define  ADC_ADC_CTL_2_inst_addr                                                 "0x000F"
#define  set_ADC_ADC_CTL_2_reg(data)                                             (*((volatile unsigned int*)ADC_ADC_CTL_2_reg)=data)
#define  get_ADC_ADC_CTL_2_reg                                                   (*((volatile unsigned int*)ADC_ADC_CTL_2_reg))
#define  ADC_ADC_CTL_2_adc_ctl_blu_10_9_shift                                    (9)
#define  ADC_ADC_CTL_2_adc_ctl_blu_8_6_shift                                     (6)
#define  ADC_ADC_CTL_2_adc_ctl_blu_5_3_shift                                     (3)
#define  ADC_ADC_CTL_2_adc_ctl_blu_2_0_shift                                     (0)
#define  ADC_ADC_CTL_2_adc_ctl_blu_10_9_mask                                     (0x00000600)
#define  ADC_ADC_CTL_2_adc_ctl_blu_8_6_mask                                      (0x000001C0)
#define  ADC_ADC_CTL_2_adc_ctl_blu_5_3_mask                                      (0x00000038)
#define  ADC_ADC_CTL_2_adc_ctl_blu_2_0_mask                                      (0x00000007)
#define  ADC_ADC_CTL_2_adc_ctl_blu_10_9(data)                                    (0x00000600&((data)<<9))
#define  ADC_ADC_CTL_2_adc_ctl_blu_8_6(data)                                     (0x000001C0&((data)<<6))
#define  ADC_ADC_CTL_2_adc_ctl_blu_5_3(data)                                     (0x00000038&((data)<<3))
#define  ADC_ADC_CTL_2_adc_ctl_blu_2_0(data)                                     (0x00000007&(data))
#define  ADC_ADC_CTL_2_get_adc_ctl_blu_10_9(data)                                ((0x00000600&(data))>>9)
#define  ADC_ADC_CTL_2_get_adc_ctl_blu_8_6(data)                                 ((0x000001C0&(data))>>6)
#define  ADC_ADC_CTL_2_get_adc_ctl_blu_5_3(data)                                 ((0x00000038&(data))>>3)
#define  ADC_ADC_CTL_2_get_adc_ctl_blu_2_0(data)                                 (0x00000007&(data))

#define  ADC_VD_ADC_CLAMP_CTL_1                                                  0x18020048
#define  ADC_VD_ADC_CLAMP_CTL_1_reg_addr                                         "0xB8020048"
#define  ADC_VD_ADC_CLAMP_CTL_1_reg                                              0xB8020048
#define  ADC_VD_ADC_CLAMP_CTL_1_inst_addr                                        "0x0010"
#define  set_ADC_VD_ADC_CLAMP_CTL_1_reg(data)                                    (*((volatile unsigned int*)ADC_VD_ADC_CLAMP_CTL_1_reg)=data)
#define  get_ADC_VD_ADC_CLAMP_CTL_1_reg                                          (*((volatile unsigned int*)ADC_VD_ADC_CLAMP_CTL_1_reg))
#define  ADC_VD_ADC_CLAMP_CTL_1_vdadc_clamp_ctrl0_15_14_shift                    (30)
#define  ADC_VD_ADC_CLAMP_CTL_1_vdadc_clamp_ctrl0_13_shift                       (29)
#define  ADC_VD_ADC_CLAMP_CTL_1_vdadc_clamp_ctrl0_12_shift                       (28)
#define  ADC_VD_ADC_CLAMP_CTL_1_vdadc_clamp_ctrl0_11_10_shift                    (26)
#define  ADC_VD_ADC_CLAMP_CTL_1_vdadc_clamp_ctrl0_9_8_shift                      (24)
#define  ADC_VD_ADC_CLAMP_CTL_1_vdadc_clamp_ctrl0_7_4_shift                      (20)
#define  ADC_VD_ADC_CLAMP_CTL_1_vdadc_clamp_ctrl0_3_0_shift                      (16)
#define  ADC_VD_ADC_CLAMP_CTL_1_vdadc_clamp_ctrl1_15_shift                       (15)
#define  ADC_VD_ADC_CLAMP_CTL_1_vdadc_clamp_ctrl1_14_13_shift                    (13)
#define  ADC_VD_ADC_CLAMP_CTL_1_vdadc_clamp_ctrl1_12_shift                       (12)
#define  ADC_VD_ADC_CLAMP_CTL_1_vdadc_clamp_ctrl1_11_shift                       (11)
#define  ADC_VD_ADC_CLAMP_CTL_1_vdadc_clamp_ctrl1_10_9_shift                     (9)
#define  ADC_VD_ADC_CLAMP_CTL_1_vdadc_clamp_ctrl1_8_shift                        (8)
#define  ADC_VD_ADC_CLAMP_CTL_1_vdadc_clamp_ctrl1_7_shift                        (7)
#define  ADC_VD_ADC_CLAMP_CTL_1_vdadc_clamp_ctrl1_6_5_shift                      (5)
#define  ADC_VD_ADC_CLAMP_CTL_1_vdadc_clamp_ctrl1_4_shift                        (4)
#define  ADC_VD_ADC_CLAMP_CTL_1_vdadc_clamp_ctrl1_3_2_shift                      (2)
#define  ADC_VD_ADC_CLAMP_CTL_1_vdadc_clamp_ctrl1_1_0_shift                      (0)
#define  ADC_VD_ADC_CLAMP_CTL_1_vdadc_clamp_ctrl0_15_14_mask                     (0xC0000000)
#define  ADC_VD_ADC_CLAMP_CTL_1_vdadc_clamp_ctrl0_13_mask                        (0x20000000)
#define  ADC_VD_ADC_CLAMP_CTL_1_vdadc_clamp_ctrl0_12_mask                        (0x10000000)
#define  ADC_VD_ADC_CLAMP_CTL_1_vdadc_clamp_ctrl0_11_10_mask                     (0x0C000000)
#define  ADC_VD_ADC_CLAMP_CTL_1_vdadc_clamp_ctrl0_9_8_mask                       (0x03000000)
#define  ADC_VD_ADC_CLAMP_CTL_1_vdadc_clamp_ctrl0_7_4_mask                       (0x00F00000)
#define  ADC_VD_ADC_CLAMP_CTL_1_vdadc_clamp_ctrl0_3_0_mask                       (0x000F0000)
#define  ADC_VD_ADC_CLAMP_CTL_1_vdadc_clamp_ctrl1_15_mask                        (0x00008000)
#define  ADC_VD_ADC_CLAMP_CTL_1_vdadc_clamp_ctrl1_14_13_mask                     (0x00006000)
#define  ADC_VD_ADC_CLAMP_CTL_1_vdadc_clamp_ctrl1_12_mask                        (0x00001000)
#define  ADC_VD_ADC_CLAMP_CTL_1_vdadc_clamp_ctrl1_11_mask                        (0x00000800)
#define  ADC_VD_ADC_CLAMP_CTL_1_vdadc_clamp_ctrl1_10_9_mask                      (0x00000600)
#define  ADC_VD_ADC_CLAMP_CTL_1_vdadc_clamp_ctrl1_8_mask                         (0x00000100)
#define  ADC_VD_ADC_CLAMP_CTL_1_vdadc_clamp_ctrl1_7_mask                         (0x00000080)
#define  ADC_VD_ADC_CLAMP_CTL_1_vdadc_clamp_ctrl1_6_5_mask                       (0x00000060)
#define  ADC_VD_ADC_CLAMP_CTL_1_vdadc_clamp_ctrl1_4_mask                         (0x00000010)
#define  ADC_VD_ADC_CLAMP_CTL_1_vdadc_clamp_ctrl1_3_2_mask                       (0x0000000C)
#define  ADC_VD_ADC_CLAMP_CTL_1_vdadc_clamp_ctrl1_1_0_mask                       (0x00000003)
#define  ADC_VD_ADC_CLAMP_CTL_1_vdadc_clamp_ctrl0_15_14(data)                    (0xC0000000&((data)<<30))
#define  ADC_VD_ADC_CLAMP_CTL_1_vdadc_clamp_ctrl0_13(data)                       (0x20000000&((data)<<29))
#define  ADC_VD_ADC_CLAMP_CTL_1_vdadc_clamp_ctrl0_12(data)                       (0x10000000&((data)<<28))
#define  ADC_VD_ADC_CLAMP_CTL_1_vdadc_clamp_ctrl0_11_10(data)                    (0x0C000000&((data)<<26))
#define  ADC_VD_ADC_CLAMP_CTL_1_vdadc_clamp_ctrl0_9_8(data)                      (0x03000000&((data)<<24))
#define  ADC_VD_ADC_CLAMP_CTL_1_vdadc_clamp_ctrl0_7_4(data)                      (0x00F00000&((data)<<20))
#define  ADC_VD_ADC_CLAMP_CTL_1_vdadc_clamp_ctrl0_3_0(data)                      (0x000F0000&((data)<<16))
#define  ADC_VD_ADC_CLAMP_CTL_1_vdadc_clamp_ctrl1_15(data)                       (0x00008000&((data)<<15))
#define  ADC_VD_ADC_CLAMP_CTL_1_vdadc_clamp_ctrl1_14_13(data)                    (0x00006000&((data)<<13))
#define  ADC_VD_ADC_CLAMP_CTL_1_vdadc_clamp_ctrl1_12(data)                       (0x00001000&((data)<<12))
#define  ADC_VD_ADC_CLAMP_CTL_1_vdadc_clamp_ctrl1_11(data)                       (0x00000800&((data)<<11))
#define  ADC_VD_ADC_CLAMP_CTL_1_vdadc_clamp_ctrl1_10_9(data)                     (0x00000600&((data)<<9))
#define  ADC_VD_ADC_CLAMP_CTL_1_vdadc_clamp_ctrl1_8(data)                        (0x00000100&((data)<<8))
#define  ADC_VD_ADC_CLAMP_CTL_1_vdadc_clamp_ctrl1_7(data)                        (0x00000080&((data)<<7))
#define  ADC_VD_ADC_CLAMP_CTL_1_vdadc_clamp_ctrl1_6_5(data)                      (0x00000060&((data)<<5))
#define  ADC_VD_ADC_CLAMP_CTL_1_vdadc_clamp_ctrl1_4(data)                        (0x00000010&((data)<<4))
#define  ADC_VD_ADC_CLAMP_CTL_1_vdadc_clamp_ctrl1_3_2(data)                      (0x0000000C&((data)<<2))
#define  ADC_VD_ADC_CLAMP_CTL_1_vdadc_clamp_ctrl1_1_0(data)                      (0x00000003&(data))
#define  ADC_VD_ADC_CLAMP_CTL_1_get_vdadc_clamp_ctrl0_15_14(data)                ((0xC0000000&(data))>>30)
#define  ADC_VD_ADC_CLAMP_CTL_1_get_vdadc_clamp_ctrl0_13(data)                   ((0x20000000&(data))>>29)
#define  ADC_VD_ADC_CLAMP_CTL_1_get_vdadc_clamp_ctrl0_12(data)                   ((0x10000000&(data))>>28)
#define  ADC_VD_ADC_CLAMP_CTL_1_get_vdadc_clamp_ctrl0_11_10(data)                ((0x0C000000&(data))>>26)
#define  ADC_VD_ADC_CLAMP_CTL_1_get_vdadc_clamp_ctrl0_9_8(data)                  ((0x03000000&(data))>>24)
#define  ADC_VD_ADC_CLAMP_CTL_1_get_vdadc_clamp_ctrl0_7_4(data)                  ((0x00F00000&(data))>>20)
#define  ADC_VD_ADC_CLAMP_CTL_1_get_vdadc_clamp_ctrl0_3_0(data)                  ((0x000F0000&(data))>>16)
#define  ADC_VD_ADC_CLAMP_CTL_1_get_vdadc_clamp_ctrl1_15(data)                   ((0x00008000&(data))>>15)
#define  ADC_VD_ADC_CLAMP_CTL_1_get_vdadc_clamp_ctrl1_14_13(data)                ((0x00006000&(data))>>13)
#define  ADC_VD_ADC_CLAMP_CTL_1_get_vdadc_clamp_ctrl1_12(data)                   ((0x00001000&(data))>>12)
#define  ADC_VD_ADC_CLAMP_CTL_1_get_vdadc_clamp_ctrl1_11(data)                   ((0x00000800&(data))>>11)
#define  ADC_VD_ADC_CLAMP_CTL_1_get_vdadc_clamp_ctrl1_10_9(data)                 ((0x00000600&(data))>>9)
#define  ADC_VD_ADC_CLAMP_CTL_1_get_vdadc_clamp_ctrl1_8(data)                    ((0x00000100&(data))>>8)
#define  ADC_VD_ADC_CLAMP_CTL_1_get_vdadc_clamp_ctrl1_7(data)                    ((0x00000080&(data))>>7)
#define  ADC_VD_ADC_CLAMP_CTL_1_get_vdadc_clamp_ctrl1_6_5(data)                  ((0x00000060&(data))>>5)
#define  ADC_VD_ADC_CLAMP_CTL_1_get_vdadc_clamp_ctrl1_4(data)                    ((0x00000010&(data))>>4)
#define  ADC_VD_ADC_CLAMP_CTL_1_get_vdadc_clamp_ctrl1_3_2(data)                  ((0x0000000C&(data))>>2)
#define  ADC_VD_ADC_CLAMP_CTL_1_get_vdadc_clamp_ctrl1_1_0(data)                  (0x00000003&(data))

#define  ADC_VD_ADC_CLAMP_CTL_2                                                  0x1802004C
#define  ADC_VD_ADC_CLAMP_CTL_2_reg_addr                                         "0xB802004C"
#define  ADC_VD_ADC_CLAMP_CTL_2_reg                                              0xB802004C
#define  ADC_VD_ADC_CLAMP_CTL_2_inst_addr                                        "0x0011"
#define  set_ADC_VD_ADC_CLAMP_CTL_2_reg(data)                                    (*((volatile unsigned int*)ADC_VD_ADC_CLAMP_CTL_2_reg)=data)
#define  get_ADC_VD_ADC_CLAMP_CTL_2_reg                                          (*((volatile unsigned int*)ADC_VD_ADC_CLAMP_CTL_2_reg))
#define  ADC_VD_ADC_CLAMP_CTL_2_vdadc_clamp_ctrl2_15_shift                       (15)
#define  ADC_VD_ADC_CLAMP_CTL_2_vdadc_clamp_ctrl2_14_12_shift                    (12)
#define  ADC_VD_ADC_CLAMP_CTL_2_vdadc_clamp_ctrl2_11_shift                       (11)
#define  ADC_VD_ADC_CLAMP_CTL_2_vdadc_clamp_ctrl2_10_shift                       (10)
#define  ADC_VD_ADC_CLAMP_CTL_2_vdadc_clamp_ctrl2_9_8_shift                      (8)
#define  ADC_VD_ADC_CLAMP_CTL_2_vdadc_clamp_ctrl2_7_shift                        (7)
#define  ADC_VD_ADC_CLAMP_CTL_2_vdadc_clamp_ctrl2_6_shift                        (6)
#define  ADC_VD_ADC_CLAMP_CTL_2_vdadc_clamp_ctrl2_5_shift                        (5)
#define  ADC_VD_ADC_CLAMP_CTL_2_vdadc_clamp_ctrl2_4_2_shift                      (2)
#define  ADC_VD_ADC_CLAMP_CTL_2_vdadc_clamp_ctrl2_1_0_shift                      (0)
#define  ADC_VD_ADC_CLAMP_CTL_2_vdadc_clamp_ctrl2_15_mask                        (0x00008000)
#define  ADC_VD_ADC_CLAMP_CTL_2_vdadc_clamp_ctrl2_14_12_mask                     (0x00007000)
#define  ADC_VD_ADC_CLAMP_CTL_2_vdadc_clamp_ctrl2_11_mask                        (0x00000800)
#define  ADC_VD_ADC_CLAMP_CTL_2_vdadc_clamp_ctrl2_10_mask                        (0x00000400)
#define  ADC_VD_ADC_CLAMP_CTL_2_vdadc_clamp_ctrl2_9_8_mask                       (0x00000300)
#define  ADC_VD_ADC_CLAMP_CTL_2_vdadc_clamp_ctrl2_7_mask                         (0x00000080)
#define  ADC_VD_ADC_CLAMP_CTL_2_vdadc_clamp_ctrl2_6_mask                         (0x00000040)
#define  ADC_VD_ADC_CLAMP_CTL_2_vdadc_clamp_ctrl2_5_mask                         (0x00000020)
#define  ADC_VD_ADC_CLAMP_CTL_2_vdadc_clamp_ctrl2_4_2_mask                       (0x0000001C)
#define  ADC_VD_ADC_CLAMP_CTL_2_vdadc_clamp_ctrl2_1_0_mask                       (0x00000003)
#define  ADC_VD_ADC_CLAMP_CTL_2_vdadc_clamp_ctrl2_15(data)                       (0x00008000&((data)<<15))
#define  ADC_VD_ADC_CLAMP_CTL_2_vdadc_clamp_ctrl2_14_12(data)                    (0x00007000&((data)<<12))
#define  ADC_VD_ADC_CLAMP_CTL_2_vdadc_clamp_ctrl2_11(data)                       (0x00000800&((data)<<11))
#define  ADC_VD_ADC_CLAMP_CTL_2_vdadc_clamp_ctrl2_10(data)                       (0x00000400&((data)<<10))
#define  ADC_VD_ADC_CLAMP_CTL_2_vdadc_clamp_ctrl2_9_8(data)                      (0x00000300&((data)<<8))
#define  ADC_VD_ADC_CLAMP_CTL_2_vdadc_clamp_ctrl2_7(data)                        (0x00000080&((data)<<7))
#define  ADC_VD_ADC_CLAMP_CTL_2_vdadc_clamp_ctrl2_6(data)                        (0x00000040&((data)<<6))
#define  ADC_VD_ADC_CLAMP_CTL_2_vdadc_clamp_ctrl2_5(data)                        (0x00000020&((data)<<5))
#define  ADC_VD_ADC_CLAMP_CTL_2_vdadc_clamp_ctrl2_4_2(data)                      (0x0000001C&((data)<<2))
#define  ADC_VD_ADC_CLAMP_CTL_2_vdadc_clamp_ctrl2_1_0(data)                      (0x00000003&(data))
#define  ADC_VD_ADC_CLAMP_CTL_2_get_vdadc_clamp_ctrl2_15(data)                   ((0x00008000&(data))>>15)
#define  ADC_VD_ADC_CLAMP_CTL_2_get_vdadc_clamp_ctrl2_14_12(data)                ((0x00007000&(data))>>12)
#define  ADC_VD_ADC_CLAMP_CTL_2_get_vdadc_clamp_ctrl2_11(data)                   ((0x00000800&(data))>>11)
#define  ADC_VD_ADC_CLAMP_CTL_2_get_vdadc_clamp_ctrl2_10(data)                   ((0x00000400&(data))>>10)
#define  ADC_VD_ADC_CLAMP_CTL_2_get_vdadc_clamp_ctrl2_9_8(data)                  ((0x00000300&(data))>>8)
#define  ADC_VD_ADC_CLAMP_CTL_2_get_vdadc_clamp_ctrl2_7(data)                    ((0x00000080&(data))>>7)
#define  ADC_VD_ADC_CLAMP_CTL_2_get_vdadc_clamp_ctrl2_6(data)                    ((0x00000040&(data))>>6)
#define  ADC_VD_ADC_CLAMP_CTL_2_get_vdadc_clamp_ctrl2_5(data)                    ((0x00000020&(data))>>5)
#define  ADC_VD_ADC_CLAMP_CTL_2_get_vdadc_clamp_ctrl2_4_2(data)                  ((0x0000001C&(data))>>2)
#define  ADC_VD_ADC_CLAMP_CTL_2_get_vdadc_clamp_ctrl2_1_0(data)                  (0x00000003&(data))

#define  ADC_VD_ADC_UPDN_CTL                                                     0x18020050
#define  ADC_VD_ADC_UPDN_CTL_reg_addr                                            "0xB8020050"
#define  ADC_VD_ADC_UPDN_CTL_reg                                                 0xB8020050
#define  ADC_VD_ADC_UPDN_CTL_inst_addr                                           "0x0012"
#define  set_ADC_VD_ADC_UPDN_CTL_reg(data)                                       (*((volatile unsigned int*)ADC_VD_ADC_UPDN_CTL_reg)=data)
#define  get_ADC_VD_ADC_UPDN_CTL_reg                                             (*((volatile unsigned int*)ADC_VD_ADC_UPDN_CTL_reg))
#define  ADC_VD_ADC_UPDN_CTL_vdadc_updn_ctrl0_15_14_shift                        (14)
#define  ADC_VD_ADC_UPDN_CTL_vdadc_updn_ctrl0_13_11_shift                        (11)
#define  ADC_VD_ADC_UPDN_CTL_vdadc_updn_ctrl0_10_8_shift                         (8)
#define  ADC_VD_ADC_UPDN_CTL_vdadc_updn_ctrl0_7_3_shift                          (3)
#define  ADC_VD_ADC_UPDN_CTL_vdadc_updn_ctrl0_2_shift                            (2)
#define  ADC_VD_ADC_UPDN_CTL_vdadc_updn_ctrl0_1_0_shift                          (0)
#define  ADC_VD_ADC_UPDN_CTL_vdadc_updn_ctrl0_15_14_mask                         (0x0000C000)
#define  ADC_VD_ADC_UPDN_CTL_vdadc_updn_ctrl0_13_11_mask                         (0x00003800)
#define  ADC_VD_ADC_UPDN_CTL_vdadc_updn_ctrl0_10_8_mask                          (0x00000700)
#define  ADC_VD_ADC_UPDN_CTL_vdadc_updn_ctrl0_7_3_mask                           (0x000000F8)
#define  ADC_VD_ADC_UPDN_CTL_vdadc_updn_ctrl0_2_mask                             (0x00000004)
#define  ADC_VD_ADC_UPDN_CTL_vdadc_updn_ctrl0_1_0_mask                           (0x00000003)
#define  ADC_VD_ADC_UPDN_CTL_vdadc_updn_ctrl0_15_14(data)                        (0x0000C000&((data)<<14))
#define  ADC_VD_ADC_UPDN_CTL_vdadc_updn_ctrl0_13_11(data)                        (0x00003800&((data)<<11))
#define  ADC_VD_ADC_UPDN_CTL_vdadc_updn_ctrl0_10_8(data)                         (0x00000700&((data)<<8))
#define  ADC_VD_ADC_UPDN_CTL_vdadc_updn_ctrl0_7_3(data)                          (0x000000F8&((data)<<3))
#define  ADC_VD_ADC_UPDN_CTL_vdadc_updn_ctrl0_2(data)                            (0x00000004&((data)<<2))
#define  ADC_VD_ADC_UPDN_CTL_vdadc_updn_ctrl0_1_0(data)                          (0x00000003&(data))
#define  ADC_VD_ADC_UPDN_CTL_get_vdadc_updn_ctrl0_15_14(data)                    ((0x0000C000&(data))>>14)
#define  ADC_VD_ADC_UPDN_CTL_get_vdadc_updn_ctrl0_13_11(data)                    ((0x00003800&(data))>>11)
#define  ADC_VD_ADC_UPDN_CTL_get_vdadc_updn_ctrl0_10_8(data)                     ((0x00000700&(data))>>8)
#define  ADC_VD_ADC_UPDN_CTL_get_vdadc_updn_ctrl0_7_3(data)                      ((0x000000F8&(data))>>3)
#define  ADC_VD_ADC_UPDN_CTL_get_vdadc_updn_ctrl0_2(data)                        ((0x00000004&(data))>>2)
#define  ADC_VD_ADC_UPDN_CTL_get_vdadc_updn_ctrl0_1_0(data)                      (0x00000003&(data))

#define  ADC_VDADC_CORE_LPF_CTRL                                                 0x18020054
#define  ADC_VDADC_CORE_LPF_CTRL_reg_addr                                        "0xB8020054"
#define  ADC_VDADC_CORE_LPF_CTRL_reg                                             0xB8020054
#define  ADC_VDADC_CORE_LPF_CTRL_inst_addr                                       "0x0013"
#define  set_ADC_VDADC_CORE_LPF_CTRL_reg(data)                                   (*((volatile unsigned int*)ADC_VDADC_CORE_LPF_CTRL_reg)=data)
#define  get_ADC_VDADC_CORE_LPF_CTRL_reg                                         (*((volatile unsigned int*)ADC_VDADC_CORE_LPF_CTRL_reg))
#define  ADC_VDADC_CORE_LPF_CTRL_vdadc_adc_ctrl_15_13_shift                      (29)
#define  ADC_VDADC_CORE_LPF_CTRL_vdadc_adc_ctrl_12_10_shift                      (26)
#define  ADC_VDADC_CORE_LPF_CTRL_vdadc_adc_ctrl_9_8_shift                        (24)
#define  ADC_VDADC_CORE_LPF_CTRL_vdadc_adc_ctrl_7_shift                          (23)
#define  ADC_VDADC_CORE_LPF_CTRL_vdadc_adc_ctrl_6_shift                          (22)
#define  ADC_VDADC_CORE_LPF_CTRL_vdadc_adc_ctrl_5_3_shift                        (19)
#define  ADC_VDADC_CORE_LPF_CTRL_vdadc_adc_ctrl_2_shift                          (18)
#define  ADC_VDADC_CORE_LPF_CTRL_vdadc_adc_ctrl_1_shift                          (17)
#define  ADC_VDADC_CORE_LPF_CTRL_vdadc_adc_ctrl_0_shift                          (16)
#define  ADC_VDADC_CORE_LPF_CTRL_vdadc_lpf_ctrl_7_2_shift                        (2)
#define  ADC_VDADC_CORE_LPF_CTRL_vdadc_lpf_ctrl_1_0_shift                        (0)
#define  ADC_VDADC_CORE_LPF_CTRL_vdadc_adc_ctrl_15_13_mask                       (0xE0000000)
#define  ADC_VDADC_CORE_LPF_CTRL_vdadc_adc_ctrl_12_10_mask                       (0x1C000000)
#define  ADC_VDADC_CORE_LPF_CTRL_vdadc_adc_ctrl_9_8_mask                         (0x03000000)
#define  ADC_VDADC_CORE_LPF_CTRL_vdadc_adc_ctrl_7_mask                           (0x00800000)
#define  ADC_VDADC_CORE_LPF_CTRL_vdadc_adc_ctrl_6_mask                           (0x00400000)
#define  ADC_VDADC_CORE_LPF_CTRL_vdadc_adc_ctrl_5_3_mask                         (0x00380000)
#define  ADC_VDADC_CORE_LPF_CTRL_vdadc_adc_ctrl_2_mask                           (0x00040000)
#define  ADC_VDADC_CORE_LPF_CTRL_vdadc_adc_ctrl_1_mask                           (0x00020000)
#define  ADC_VDADC_CORE_LPF_CTRL_vdadc_adc_ctrl_0_mask                           (0x00010000)
#define  ADC_VDADC_CORE_LPF_CTRL_vdadc_lpf_ctrl_7_2_mask                         (0x000000FC)
#define  ADC_VDADC_CORE_LPF_CTRL_vdadc_lpf_ctrl_1_0_mask                         (0x00000003)
#define  ADC_VDADC_CORE_LPF_CTRL_vdadc_adc_ctrl_15_13(data)                      (0xE0000000&((data)<<29))
#define  ADC_VDADC_CORE_LPF_CTRL_vdadc_adc_ctrl_12_10(data)                      (0x1C000000&((data)<<26))
#define  ADC_VDADC_CORE_LPF_CTRL_vdadc_adc_ctrl_9_8(data)                        (0x03000000&((data)<<24))
#define  ADC_VDADC_CORE_LPF_CTRL_vdadc_adc_ctrl_7(data)                          (0x00800000&((data)<<23))
#define  ADC_VDADC_CORE_LPF_CTRL_vdadc_adc_ctrl_6(data)                          (0x00400000&((data)<<22))
#define  ADC_VDADC_CORE_LPF_CTRL_vdadc_adc_ctrl_5_3(data)                        (0x00380000&((data)<<19))
#define  ADC_VDADC_CORE_LPF_CTRL_vdadc_adc_ctrl_2(data)                          (0x00040000&((data)<<18))
#define  ADC_VDADC_CORE_LPF_CTRL_vdadc_adc_ctrl_1(data)                          (0x00020000&((data)<<17))
#define  ADC_VDADC_CORE_LPF_CTRL_vdadc_adc_ctrl_0(data)                          (0x00010000&((data)<<16))
#define  ADC_VDADC_CORE_LPF_CTRL_vdadc_lpf_ctrl_7_2(data)                        (0x000000FC&((data)<<2))
#define  ADC_VDADC_CORE_LPF_CTRL_vdadc_lpf_ctrl_1_0(data)                        (0x00000003&(data))
#define  ADC_VDADC_CORE_LPF_CTRL_get_vdadc_adc_ctrl_15_13(data)                  ((0xE0000000&(data))>>29)
#define  ADC_VDADC_CORE_LPF_CTRL_get_vdadc_adc_ctrl_12_10(data)                  ((0x1C000000&(data))>>26)
#define  ADC_VDADC_CORE_LPF_CTRL_get_vdadc_adc_ctrl_9_8(data)                    ((0x03000000&(data))>>24)
#define  ADC_VDADC_CORE_LPF_CTRL_get_vdadc_adc_ctrl_7(data)                      ((0x00800000&(data))>>23)
#define  ADC_VDADC_CORE_LPF_CTRL_get_vdadc_adc_ctrl_6(data)                      ((0x00400000&(data))>>22)
#define  ADC_VDADC_CORE_LPF_CTRL_get_vdadc_adc_ctrl_5_3(data)                    ((0x00380000&(data))>>19)
#define  ADC_VDADC_CORE_LPF_CTRL_get_vdadc_adc_ctrl_2(data)                      ((0x00040000&(data))>>18)
#define  ADC_VDADC_CORE_LPF_CTRL_get_vdadc_adc_ctrl_1(data)                      ((0x00020000&(data))>>17)
#define  ADC_VDADC_CORE_LPF_CTRL_get_vdadc_adc_ctrl_0(data)                      ((0x00010000&(data))>>16)
#define  ADC_VDADC_CORE_LPF_CTRL_get_vdadc_lpf_ctrl_7_2(data)                    ((0x000000FC&(data))>>2)
#define  ADC_VDADC_CORE_LPF_CTRL_get_vdadc_lpf_ctrl_1_0(data)                    (0x00000003&(data))

#define  ADC_VDADC_CK_CTL                                                        0x18020058
#define  ADC_VDADC_CK_CTL_reg_addr                                               "0xB8020058"
#define  ADC_VDADC_CK_CTL_reg                                                    0xB8020058
#define  ADC_VDADC_CK_CTL_inst_addr                                              "0x0014"
#define  set_ADC_VDADC_CK_CTL_reg(data)                                          (*((volatile unsigned int*)ADC_VDADC_CK_CTL_reg)=data)
#define  get_ADC_VDADC_CK_CTL_reg                                                (*((volatile unsigned int*)ADC_VDADC_CK_CTL_reg))
#define  ADC_VDADC_CK_CTL_vdadc_ckin_sel_7_shift                                 (15)
#define  ADC_VDADC_CK_CTL_vdadc_ckin_sel_6_shift                                 (14)
#define  ADC_VDADC_CK_CTL_vdadc_ckin_sel_5_shift                                 (13)
#define  ADC_VDADC_CK_CTL_vdadc_ckin_sel_4_2_shift                               (10)
#define  ADC_VDADC_CK_CTL_vdadc_ckin_sel_1_0_shift                               (8)
#define  ADC_VDADC_CK_CTL_vdadc_ckout_sel_7_shift                                (7)
#define  ADC_VDADC_CK_CTL_vdadc_ckout_sel_6_shift                                (6)
#define  ADC_VDADC_CK_CTL_vdadc_ckout_sel_5_shift                                (5)
#define  ADC_VDADC_CK_CTL_vdadc_ckout_sel_4_shift                                (4)
#define  ADC_VDADC_CK_CTL_vdadc_ckout_sel_3_2_shift                              (2)
#define  ADC_VDADC_CK_CTL_vdadc_ckout_sel_1_0_shift                              (0)
#define  ADC_VDADC_CK_CTL_vdadc_ckin_sel_7_mask                                  (0x00008000)
#define  ADC_VDADC_CK_CTL_vdadc_ckin_sel_6_mask                                  (0x00004000)
#define  ADC_VDADC_CK_CTL_vdadc_ckin_sel_5_mask                                  (0x00002000)
#define  ADC_VDADC_CK_CTL_vdadc_ckin_sel_4_2_mask                                (0x00001C00)
#define  ADC_VDADC_CK_CTL_vdadc_ckin_sel_1_0_mask                                (0x00000300)
#define  ADC_VDADC_CK_CTL_vdadc_ckout_sel_7_mask                                 (0x00000080)
#define  ADC_VDADC_CK_CTL_vdadc_ckout_sel_6_mask                                 (0x00000040)
#define  ADC_VDADC_CK_CTL_vdadc_ckout_sel_5_mask                                 (0x00000020)
#define  ADC_VDADC_CK_CTL_vdadc_ckout_sel_4_mask                                 (0x00000010)
#define  ADC_VDADC_CK_CTL_vdadc_ckout_sel_3_2_mask                               (0x0000000C)
#define  ADC_VDADC_CK_CTL_vdadc_ckout_sel_1_0_mask                               (0x00000003)
#define  ADC_VDADC_CK_CTL_vdadc_ckin_sel_7(data)                                 (0x00008000&((data)<<15))
#define  ADC_VDADC_CK_CTL_vdadc_ckin_sel_6(data)                                 (0x00004000&((data)<<14))
#define  ADC_VDADC_CK_CTL_vdadc_ckin_sel_5(data)                                 (0x00002000&((data)<<13))
#define  ADC_VDADC_CK_CTL_vdadc_ckin_sel_4_2(data)                               (0x00001C00&((data)<<10))
#define  ADC_VDADC_CK_CTL_vdadc_ckin_sel_1_0(data)                               (0x00000300&((data)<<8))
#define  ADC_VDADC_CK_CTL_vdadc_ckout_sel_7(data)                                (0x00000080&((data)<<7))
#define  ADC_VDADC_CK_CTL_vdadc_ckout_sel_6(data)                                (0x00000040&((data)<<6))
#define  ADC_VDADC_CK_CTL_vdadc_ckout_sel_5(data)                                (0x00000020&((data)<<5))
#define  ADC_VDADC_CK_CTL_vdadc_ckout_sel_4(data)                                (0x00000010&((data)<<4))
#define  ADC_VDADC_CK_CTL_vdadc_ckout_sel_3_2(data)                              (0x0000000C&((data)<<2))
#define  ADC_VDADC_CK_CTL_vdadc_ckout_sel_1_0(data)                              (0x00000003&(data))
#define  ADC_VDADC_CK_CTL_get_vdadc_ckin_sel_7(data)                             ((0x00008000&(data))>>15)
#define  ADC_VDADC_CK_CTL_get_vdadc_ckin_sel_6(data)                             ((0x00004000&(data))>>14)
#define  ADC_VDADC_CK_CTL_get_vdadc_ckin_sel_5(data)                             ((0x00002000&(data))>>13)
#define  ADC_VDADC_CK_CTL_get_vdadc_ckin_sel_4_2(data)                           ((0x00001C00&(data))>>10)
#define  ADC_VDADC_CK_CTL_get_vdadc_ckin_sel_1_0(data)                           ((0x00000300&(data))>>8)
#define  ADC_VDADC_CK_CTL_get_vdadc_ckout_sel_7(data)                            ((0x00000080&(data))>>7)
#define  ADC_VDADC_CK_CTL_get_vdadc_ckout_sel_6(data)                            ((0x00000040&(data))>>6)
#define  ADC_VDADC_CK_CTL_get_vdadc_ckout_sel_5(data)                            ((0x00000020&(data))>>5)
#define  ADC_VDADC_CK_CTL_get_vdadc_ckout_sel_4(data)                            ((0x00000010&(data))>>4)
#define  ADC_VDADC_CK_CTL_get_vdadc_ckout_sel_3_2(data)                          ((0x0000000C&(data))>>2)
#define  ADC_VDADC_CK_CTL_get_vdadc_ckout_sel_1_0(data)                          (0x00000003&(data))

#define  ADC_VDADC_POW_CTL                                                       0x1802005C
#define  ADC_VDADC_POW_CTL_reg_addr                                              "0xB802005C"
#define  ADC_VDADC_POW_CTL_reg                                                   0xB802005C
#define  ADC_VDADC_POW_CTL_inst_addr                                             "0x0015"
#define  set_ADC_VDADC_POW_CTL_reg(data)                                         (*((volatile unsigned int*)ADC_VDADC_POW_CTL_reg)=data)
#define  get_ADC_VDADC_POW_CTL_reg                                               (*((volatile unsigned int*)ADC_VDADC_POW_CTL_reg))
#define  ADC_VDADC_POW_CTL_vdadc_reserve_shift                                   (16)
#define  ADC_VDADC_POW_CTL_ldo100ma_pow_shift                                    (1)
#define  ADC_VDADC_POW_CTL_vdadc_pow_shift                                       (0)
#define  ADC_VDADC_POW_CTL_vdadc_reserve_mask                                    (0xFFFF0000)
#define  ADC_VDADC_POW_CTL_ldo100ma_pow_mask                                     (0x00000002)
#define  ADC_VDADC_POW_CTL_vdadc_pow_mask                                        (0x00000001)
#define  ADC_VDADC_POW_CTL_vdadc_reserve(data)                                   (0xFFFF0000&((data)<<16))
#define  ADC_VDADC_POW_CTL_ldo100ma_pow(data)                                    (0x00000002&((data)<<1))
#define  ADC_VDADC_POW_CTL_vdadc_pow(data)                                       (0x00000001&(data))
#define  ADC_VDADC_POW_CTL_get_vdadc_reserve(data)                               ((0xFFFF0000&(data))>>16)
#define  ADC_VDADC_POW_CTL_get_ldo100ma_pow(data)                                ((0x00000002&(data))>>1)
#define  ADC_VDADC_POW_CTL_get_vdadc_pow(data)                                   (0x00000001&(data))

#define  ADC_AHS_SMT_CTRL                                                        0x18020064
#define  ADC_AHS_SMT_CTRL_reg_addr                                               "0xB8020064"
#define  ADC_AHS_SMT_CTRL_reg                                                    0xB8020064
#define  ADC_AHS_SMT_CTRL_inst_addr                                              "0x0016"
#define  set_ADC_AHS_SMT_CTRL_reg(data)                                          (*((volatile unsigned int*)ADC_AHS_SMT_CTRL_reg)=data)
#define  get_ADC_AHS_SMT_CTRL_reg                                                (*((volatile unsigned int*)ADC_AHS_SMT_CTRL_reg))
#define  ADC_AHS_SMT_CTRL_vsync_e2_shift                                         (13)
#define  ADC_AHS_SMT_CTRL_vsync_pd_shift                                         (12)
#define  ADC_AHS_SMT_CTRL_vsync_pu_shift                                         (11)
#define  ADC_AHS_SMT_CTRL_vsync_sr_shift                                         (10)
#define  ADC_AHS_SMT_CTRL_hsync0_pwdn_shift                                      (9)
#define  ADC_AHS_SMT_CTRL_hsync0_pd_latch_shift                                  (8)
#define  ADC_AHS_SMT_CTRL_hsync0_3ven_shift                                      (7)
#define  ADC_AHS_SMT_CTRL_hsync0_pol_shift                                       (6)
#define  ADC_AHS_SMT_CTRL_hsync0_mode_shift                                      (5)
#define  ADC_AHS_SMT_CTRL_hsync0_vos_shift                                       (4)
#define  ADC_AHS_SMT_CTRL_hsync0_vtp_1_0_shift                                   (2)
#define  ADC_AHS_SMT_CTRL_hsync0_vtn_1_0_shift                                   (0)
#define  ADC_AHS_SMT_CTRL_vsync_e2_mask                                          (0x00002000)
#define  ADC_AHS_SMT_CTRL_vsync_pd_mask                                          (0x00001000)
#define  ADC_AHS_SMT_CTRL_vsync_pu_mask                                          (0x00000800)
#define  ADC_AHS_SMT_CTRL_vsync_sr_mask                                          (0x00000400)
#define  ADC_AHS_SMT_CTRL_hsync0_pwdn_mask                                       (0x00000200)
#define  ADC_AHS_SMT_CTRL_hsync0_pd_latch_mask                                   (0x00000100)
#define  ADC_AHS_SMT_CTRL_hsync0_3ven_mask                                       (0x00000080)
#define  ADC_AHS_SMT_CTRL_hsync0_pol_mask                                        (0x00000040)
#define  ADC_AHS_SMT_CTRL_hsync0_mode_mask                                       (0x00000020)
#define  ADC_AHS_SMT_CTRL_hsync0_vos_mask                                        (0x00000010)
#define  ADC_AHS_SMT_CTRL_hsync0_vtp_1_0_mask                                    (0x0000000C)
#define  ADC_AHS_SMT_CTRL_hsync0_vtn_1_0_mask                                    (0x00000003)
#define  ADC_AHS_SMT_CTRL_vsync_e2(data)                                         (0x00002000&((data)<<13))
#define  ADC_AHS_SMT_CTRL_vsync_pd(data)                                         (0x00001000&((data)<<12))
#define  ADC_AHS_SMT_CTRL_vsync_pu(data)                                         (0x00000800&((data)<<11))
#define  ADC_AHS_SMT_CTRL_vsync_sr(data)                                         (0x00000400&((data)<<10))
#define  ADC_AHS_SMT_CTRL_hsync0_pwdn(data)                                      (0x00000200&((data)<<9))
#define  ADC_AHS_SMT_CTRL_hsync0_pd_latch(data)                                  (0x00000100&((data)<<8))
#define  ADC_AHS_SMT_CTRL_hsync0_3ven(data)                                      (0x00000080&((data)<<7))
#define  ADC_AHS_SMT_CTRL_hsync0_pol(data)                                       (0x00000040&((data)<<6))
#define  ADC_AHS_SMT_CTRL_hsync0_mode(data)                                      (0x00000020&((data)<<5))
#define  ADC_AHS_SMT_CTRL_hsync0_vos(data)                                       (0x00000010&((data)<<4))
#define  ADC_AHS_SMT_CTRL_hsync0_vtp_1_0(data)                                   (0x0000000C&((data)<<2))
#define  ADC_AHS_SMT_CTRL_hsync0_vtn_1_0(data)                                   (0x00000003&(data))
#define  ADC_AHS_SMT_CTRL_get_vsync_e2(data)                                     ((0x00002000&(data))>>13)
#define  ADC_AHS_SMT_CTRL_get_vsync_pd(data)                                     ((0x00001000&(data))>>12)
#define  ADC_AHS_SMT_CTRL_get_vsync_pu(data)                                     ((0x00000800&(data))>>11)
#define  ADC_AHS_SMT_CTRL_get_vsync_sr(data)                                     ((0x00000400&(data))>>10)
#define  ADC_AHS_SMT_CTRL_get_hsync0_pwdn(data)                                  ((0x00000200&(data))>>9)
#define  ADC_AHS_SMT_CTRL_get_hsync0_pd_latch(data)                              ((0x00000100&(data))>>8)
#define  ADC_AHS_SMT_CTRL_get_hsync0_3ven(data)                                  ((0x00000080&(data))>>7)
#define  ADC_AHS_SMT_CTRL_get_hsync0_pol(data)                                   ((0x00000040&(data))>>6)
#define  ADC_AHS_SMT_CTRL_get_hsync0_mode(data)                                  ((0x00000020&(data))>>5)
#define  ADC_AHS_SMT_CTRL_get_hsync0_vos(data)                                   ((0x00000010&(data))>>4)
#define  ADC_AHS_SMT_CTRL_get_hsync0_vtp_1_0(data)                               ((0x0000000C&(data))>>2)
#define  ADC_AHS_SMT_CTRL_get_hsync0_vtn_1_0(data)                               (0x00000003&(data))

#define  ADC_ADC_TEST                                                            0x18020068
#define  ADC_ADC_TEST_reg_addr                                                   "0xB8020068"
#define  ADC_ADC_TEST_reg                                                        0xB8020068
#define  ADC_ADC_TEST_inst_addr                                                  "0x0017"
#define  set_ADC_ADC_TEST_reg(data)                                              (*((volatile unsigned int*)ADC_ADC_TEST_reg)=data)
#define  get_ADC_ADC_TEST_reg                                                    (*((volatile unsigned int*)ADC_ADC_TEST_reg))
#define  ADC_ADC_TEST_adc_test_7_shift                                           (7)
#define  ADC_ADC_TEST_adc_test_6_4_shift                                         (4)
#define  ADC_ADC_TEST_adc_test_3_shift                                           (3)
#define  ADC_ADC_TEST_adc_test_2_shift                                           (2)
#define  ADC_ADC_TEST_adc_test_1_0_shift                                         (0)
#define  ADC_ADC_TEST_adc_test_7_mask                                            (0x00000080)
#define  ADC_ADC_TEST_adc_test_6_4_mask                                          (0x00000070)
#define  ADC_ADC_TEST_adc_test_3_mask                                            (0x00000008)
#define  ADC_ADC_TEST_adc_test_2_mask                                            (0x00000004)
#define  ADC_ADC_TEST_adc_test_1_0_mask                                          (0x00000003)
#define  ADC_ADC_TEST_adc_test_7(data)                                           (0x00000080&((data)<<7))
#define  ADC_ADC_TEST_adc_test_6_4(data)                                         (0x00000070&((data)<<4))
#define  ADC_ADC_TEST_adc_test_3(data)                                           (0x00000008&((data)<<3))
#define  ADC_ADC_TEST_adc_test_2(data)                                           (0x00000004&((data)<<2))
#define  ADC_ADC_TEST_adc_test_1_0(data)                                         (0x00000003&(data))
#define  ADC_ADC_TEST_get_adc_test_7(data)                                       ((0x00000080&(data))>>7)
#define  ADC_ADC_TEST_get_adc_test_6_4(data)                                     ((0x00000070&(data))>>4)
#define  ADC_ADC_TEST_get_adc_test_3(data)                                       ((0x00000008&(data))>>3)
#define  ADC_ADC_TEST_get_adc_test_2(data)                                       ((0x00000004&(data))>>2)
#define  ADC_ADC_TEST_get_adc_test_1_0(data)                                     (0x00000003&(data))

#define  ADC_SCART_CTRL1                                                         0x1802006C
#define  ADC_SCART_CTRL1_reg_addr                                                "0xB802006C"
#define  ADC_SCART_CTRL1_reg                                                     0xB802006C
#define  ADC_SCART_CTRL1_inst_addr                                               "0x0018"
#define  set_ADC_SCART_CTRL1_reg(data)                                           (*((volatile unsigned int*)ADC_SCART_CTRL1_reg)=data)
#define  get_ADC_SCART_CTRL1_reg                                                 (*((volatile unsigned int*)ADC_SCART_CTRL1_reg))
#define  ADC_SCART_CTRL1_vdadc_sct_ctrl_shift                                    (0)
#define  ADC_SCART_CTRL1_vdadc_sct_ctrl_mask                                     (0x000000FF)
#define  ADC_SCART_CTRL1_vdadc_sct_ctrl(data)                                    (0x000000FF&(data))
#define  ADC_SCART_CTRL1_get_vdadc_sct_ctrl(data)                                (0x000000FF&(data))

#define  ADC_ADC_CLKGEN_RGB_Capture                                              0x18020080
#define  ADC_ADC_CLKGEN_RGB_Capture_reg_addr                                     "0xB8020080"
#define  ADC_ADC_CLKGEN_RGB_Capture_reg                                          0xB8020080
#define  ADC_ADC_CLKGEN_RGB_Capture_inst_addr                                    "0x0019"
#define  set_ADC_ADC_CLKGEN_RGB_Capture_reg(data)                                (*((volatile unsigned int*)ADC_ADC_CLKGEN_RGB_Capture_reg)=data)
#define  get_ADC_ADC_CLKGEN_RGB_Capture_reg                                      (*((volatile unsigned int*)ADC_ADC_CLKGEN_RGB_Capture_reg))
#define  ADC_ADC_CLKGEN_RGB_Capture_hs_hsfb_err_judge_sel_shift                  (31)
#define  ADC_ADC_CLKGEN_RGB_Capture_flag_hs_catch_err_r_shift                    (30)
#define  ADC_ADC_CLKGEN_RGB_Capture_hs_err_judge_en_shift                        (29)
#define  ADC_ADC_CLKGEN_RGB_Capture_hs_catch_edge_shift                          (28)
#define  ADC_ADC_CLKGEN_RGB_Capture_flag_hs_catch_err_ie_shift                   (27)
#define  ADC_ADC_CLKGEN_RGB_Capture_vbick_div_phsel_shift                        (26)
#define  ADC_ADC_CLKGEN_RGB_Capture_vbick_div_inv_shift                          (25)
#define  ADC_ADC_CLKGEN_RGB_Capture_adck_div_inv_shift                           (24)
#define  ADC_ADC_CLKGEN_RGB_Capture_adck_div_phsel_shift                         (22)
#define  ADC_ADC_CLKGEN_RGB_Capture_adck_div_sel_shift                           (21)
#define  ADC_ADC_CLKGEN_RGB_Capture_adck_div_en_shift                            (20)
#define  ADC_ADC_CLKGEN_RGB_Capture_ablagc_cpsel_shift                           (19)
#define  ADC_ADC_CLKGEN_RGB_Capture_vbi_swap_shift                               (16)
#define  ADC_ADC_CLKGEN_RGB_Capture_rgb_from_hsptg_shift                         (15)
#define  ADC_ADC_CLKGEN_RGB_Capture_adc_swap_shift                               (12)
#define  ADC_ADC_CLKGEN_RGB_Capture_vbi_clk_inv_shift                            (11)
#define  ADC_ADC_CLKGEN_RGB_Capture_adc_clkx2_inv_shift                          (10)
#define  ADC_ADC_CLKGEN_RGB_Capture_adc_clk_inv_shift                            (9)
#define  ADC_ADC_CLKGEN_RGB_Capture_soy0_clk_inv_shift                           (8)
#define  ADC_ADC_CLKGEN_RGB_Capture_adc_clk_inv_en_shift                         (7)
#define  ADC_ADC_CLKGEN_RGB_Capture_vbi_clk_en_shift                             (6)
#define  ADC_ADC_CLKGEN_RGB_Capture_adc_clkx2_en_shift                           (5)
#define  ADC_ADC_CLKGEN_RGB_Capture_soy0_clk_en_shift                            (4)
#define  ADC_ADC_CLKGEN_RGB_Capture_st_latch_en_shift                            (3)
#define  ADC_ADC_CLKGEN_RGB_Capture_vbi_clkx2_sel_shift                          (2)
#define  ADC_ADC_CLKGEN_RGB_Capture_adck_test_shift                              (1)
#define  ADC_ADC_CLKGEN_RGB_Capture_soy_test_en_shift                            (0)
#define  ADC_ADC_CLKGEN_RGB_Capture_hs_hsfb_err_judge_sel_mask                   (0x80000000)
#define  ADC_ADC_CLKGEN_RGB_Capture_flag_hs_catch_err_r_mask                     (0x40000000)
#define  ADC_ADC_CLKGEN_RGB_Capture_hs_err_judge_en_mask                         (0x20000000)
#define  ADC_ADC_CLKGEN_RGB_Capture_hs_catch_edge_mask                           (0x10000000)
#define  ADC_ADC_CLKGEN_RGB_Capture_flag_hs_catch_err_ie_mask                    (0x08000000)
#define  ADC_ADC_CLKGEN_RGB_Capture_vbick_div_phsel_mask                         (0x04000000)
#define  ADC_ADC_CLKGEN_RGB_Capture_vbick_div_inv_mask                           (0x02000000)
#define  ADC_ADC_CLKGEN_RGB_Capture_adck_div_inv_mask                            (0x01000000)
#define  ADC_ADC_CLKGEN_RGB_Capture_adck_div_phsel_mask                          (0x00C00000)
#define  ADC_ADC_CLKGEN_RGB_Capture_adck_div_sel_mask                            (0x00200000)
#define  ADC_ADC_CLKGEN_RGB_Capture_adck_div_en_mask                             (0x00100000)
#define  ADC_ADC_CLKGEN_RGB_Capture_ablagc_cpsel_mask                            (0x00080000)
#define  ADC_ADC_CLKGEN_RGB_Capture_vbi_swap_mask                                (0x00070000)
#define  ADC_ADC_CLKGEN_RGB_Capture_rgb_from_hsptg_mask                          (0x00008000)
#define  ADC_ADC_CLKGEN_RGB_Capture_adc_swap_mask                                (0x00007000)
#define  ADC_ADC_CLKGEN_RGB_Capture_vbi_clk_inv_mask                             (0x00000800)
#define  ADC_ADC_CLKGEN_RGB_Capture_adc_clkx2_inv_mask                           (0x00000400)
#define  ADC_ADC_CLKGEN_RGB_Capture_adc_clk_inv_mask                             (0x00000200)
#define  ADC_ADC_CLKGEN_RGB_Capture_soy0_clk_inv_mask                            (0x00000100)
#define  ADC_ADC_CLKGEN_RGB_Capture_adc_clk_inv_en_mask                          (0x00000080)
#define  ADC_ADC_CLKGEN_RGB_Capture_vbi_clk_en_mask                              (0x00000040)
#define  ADC_ADC_CLKGEN_RGB_Capture_adc_clkx2_en_mask                            (0x00000020)
#define  ADC_ADC_CLKGEN_RGB_Capture_soy0_clk_en_mask                             (0x00000010)
#define  ADC_ADC_CLKGEN_RGB_Capture_st_latch_en_mask                             (0x00000008)
#define  ADC_ADC_CLKGEN_RGB_Capture_vbi_clkx2_sel_mask                           (0x00000004)
#define  ADC_ADC_CLKGEN_RGB_Capture_adck_test_mask                               (0x00000002)
#define  ADC_ADC_CLKGEN_RGB_Capture_soy_test_en_mask                             (0x00000001)
#define  ADC_ADC_CLKGEN_RGB_Capture_hs_hsfb_err_judge_sel(data)                  (0x80000000&((data)<<31))
#define  ADC_ADC_CLKGEN_RGB_Capture_flag_hs_catch_err_r(data)                    (0x40000000&((data)<<30))
#define  ADC_ADC_CLKGEN_RGB_Capture_hs_err_judge_en(data)                        (0x20000000&((data)<<29))
#define  ADC_ADC_CLKGEN_RGB_Capture_hs_catch_edge(data)                          (0x10000000&((data)<<28))
#define  ADC_ADC_CLKGEN_RGB_Capture_flag_hs_catch_err_ie(data)                   (0x08000000&((data)<<27))
#define  ADC_ADC_CLKGEN_RGB_Capture_vbick_div_phsel(data)                        (0x04000000&((data)<<26))
#define  ADC_ADC_CLKGEN_RGB_Capture_vbick_div_inv(data)                          (0x02000000&((data)<<25))
#define  ADC_ADC_CLKGEN_RGB_Capture_adck_div_inv(data)                           (0x01000000&((data)<<24))
#define  ADC_ADC_CLKGEN_RGB_Capture_adck_div_phsel(data)                         (0x00C00000&((data)<<22))
#define  ADC_ADC_CLKGEN_RGB_Capture_adck_div_sel(data)                           (0x00200000&((data)<<21))
#define  ADC_ADC_CLKGEN_RGB_Capture_adck_div_en(data)                            (0x00100000&((data)<<20))
#define  ADC_ADC_CLKGEN_RGB_Capture_ablagc_cpsel(data)                           (0x00080000&((data)<<19))
#define  ADC_ADC_CLKGEN_RGB_Capture_vbi_swap(data)                               (0x00070000&((data)<<16))
#define  ADC_ADC_CLKGEN_RGB_Capture_rgb_from_hsptg(data)                         (0x00008000&((data)<<15))
#define  ADC_ADC_CLKGEN_RGB_Capture_adc_swap(data)                               (0x00007000&((data)<<12))
#define  ADC_ADC_CLKGEN_RGB_Capture_vbi_clk_inv(data)                            (0x00000800&((data)<<11))
#define  ADC_ADC_CLKGEN_RGB_Capture_adc_clkx2_inv(data)                          (0x00000400&((data)<<10))
#define  ADC_ADC_CLKGEN_RGB_Capture_adc_clk_inv(data)                            (0x00000200&((data)<<9))
#define  ADC_ADC_CLKGEN_RGB_Capture_soy0_clk_inv(data)                           (0x00000100&((data)<<8))
#define  ADC_ADC_CLKGEN_RGB_Capture_adc_clk_inv_en(data)                         (0x00000080&((data)<<7))
#define  ADC_ADC_CLKGEN_RGB_Capture_vbi_clk_en(data)                             (0x00000040&((data)<<6))
#define  ADC_ADC_CLKGEN_RGB_Capture_adc_clkx2_en(data)                           (0x00000020&((data)<<5))
#define  ADC_ADC_CLKGEN_RGB_Capture_soy0_clk_en(data)                            (0x00000010&((data)<<4))
#define  ADC_ADC_CLKGEN_RGB_Capture_st_latch_en(data)                            (0x00000008&((data)<<3))
#define  ADC_ADC_CLKGEN_RGB_Capture_vbi_clkx2_sel(data)                          (0x00000004&((data)<<2))
#define  ADC_ADC_CLKGEN_RGB_Capture_adck_test(data)                              (0x00000002&((data)<<1))
#define  ADC_ADC_CLKGEN_RGB_Capture_soy_test_en(data)                            (0x00000001&(data))
#define  ADC_ADC_CLKGEN_RGB_Capture_get_hs_hsfb_err_judge_sel(data)              ((0x80000000&(data))>>31)
#define  ADC_ADC_CLKGEN_RGB_Capture_get_flag_hs_catch_err_r(data)                ((0x40000000&(data))>>30)
#define  ADC_ADC_CLKGEN_RGB_Capture_get_hs_err_judge_en(data)                    ((0x20000000&(data))>>29)
#define  ADC_ADC_CLKGEN_RGB_Capture_get_hs_catch_edge(data)                      ((0x10000000&(data))>>28)
#define  ADC_ADC_CLKGEN_RGB_Capture_get_flag_hs_catch_err_ie(data)               ((0x08000000&(data))>>27)
#define  ADC_ADC_CLKGEN_RGB_Capture_get_vbick_div_phsel(data)                    ((0x04000000&(data))>>26)
#define  ADC_ADC_CLKGEN_RGB_Capture_get_vbick_div_inv(data)                      ((0x02000000&(data))>>25)
#define  ADC_ADC_CLKGEN_RGB_Capture_get_adck_div_inv(data)                       ((0x01000000&(data))>>24)
#define  ADC_ADC_CLKGEN_RGB_Capture_get_adck_div_phsel(data)                     ((0x00C00000&(data))>>22)
#define  ADC_ADC_CLKGEN_RGB_Capture_get_adck_div_sel(data)                       ((0x00200000&(data))>>21)
#define  ADC_ADC_CLKGEN_RGB_Capture_get_adck_div_en(data)                        ((0x00100000&(data))>>20)
#define  ADC_ADC_CLKGEN_RGB_Capture_get_ablagc_cpsel(data)                       ((0x00080000&(data))>>19)
#define  ADC_ADC_CLKGEN_RGB_Capture_get_vbi_swap(data)                           ((0x00070000&(data))>>16)
#define  ADC_ADC_CLKGEN_RGB_Capture_get_rgb_from_hsptg(data)                     ((0x00008000&(data))>>15)
#define  ADC_ADC_CLKGEN_RGB_Capture_get_adc_swap(data)                           ((0x00007000&(data))>>12)
#define  ADC_ADC_CLKGEN_RGB_Capture_get_vbi_clk_inv(data)                        ((0x00000800&(data))>>11)
#define  ADC_ADC_CLKGEN_RGB_Capture_get_adc_clkx2_inv(data)                      ((0x00000400&(data))>>10)
#define  ADC_ADC_CLKGEN_RGB_Capture_get_adc_clk_inv(data)                        ((0x00000200&(data))>>9)
#define  ADC_ADC_CLKGEN_RGB_Capture_get_soy0_clk_inv(data)                       ((0x00000100&(data))>>8)
#define  ADC_ADC_CLKGEN_RGB_Capture_get_adc_clk_inv_en(data)                     ((0x00000080&(data))>>7)
#define  ADC_ADC_CLKGEN_RGB_Capture_get_vbi_clk_en(data)                         ((0x00000040&(data))>>6)
#define  ADC_ADC_CLKGEN_RGB_Capture_get_adc_clkx2_en(data)                       ((0x00000020&(data))>>5)
#define  ADC_ADC_CLKGEN_RGB_Capture_get_soy0_clk_en(data)                        ((0x00000010&(data))>>4)
#define  ADC_ADC_CLKGEN_RGB_Capture_get_st_latch_en(data)                        ((0x00000008&(data))>>3)
#define  ADC_ADC_CLKGEN_RGB_Capture_get_vbi_clkx2_sel(data)                      ((0x00000004&(data))>>2)
#define  ADC_ADC_CLKGEN_RGB_Capture_get_adck_test(data)                          ((0x00000002&(data))>>1)
#define  ADC_ADC_CLKGEN_RGB_Capture_get_soy_test_en(data)                        (0x00000001&(data))

#define  ADC_ADC_APLL_ADC_TESTOUT_MUX                                            0x18020084
#define  ADC_ADC_APLL_ADC_TESTOUT_MUX_reg_addr                                   "0xB8020084"
#define  ADC_ADC_APLL_ADC_TESTOUT_MUX_reg                                        0xB8020084
#define  ADC_ADC_APLL_ADC_TESTOUT_MUX_inst_addr                                  "0x001A"
#define  set_ADC_ADC_APLL_ADC_TESTOUT_MUX_reg(data)                              (*((volatile unsigned int*)ADC_ADC_APLL_ADC_TESTOUT_MUX_reg)=data)
#define  get_ADC_ADC_APLL_ADC_TESTOUT_MUX_reg                                    (*((volatile unsigned int*)ADC_ADC_APLL_ADC_TESTOUT_MUX_reg))
#define  ADC_ADC_APLL_ADC_TESTOUT_MUX_dac_data_select_shift                      (30)
#define  ADC_ADC_APLL_ADC_TESTOUT_MUX_adc_data_select_shift                      (28)
#define  ADC_ADC_APLL_ADC_TESTOUT_MUX_dummy_27_9_shift                           (9)
#define  ADC_ADC_APLL_ADC_TESTOUT_MUX_dummy_7_5_shift                            (5)
#define  ADC_ADC_APLL_ADC_TESTOUT_MUX_apll_adc_tstout_mux_shift                  (2)
#define  ADC_ADC_APLL_ADC_TESTOUT_MUX_adc_tstout_mux_shift                       (0)
#define  ADC_ADC_APLL_ADC_TESTOUT_MUX_dac_data_select_mask                       (0x40000000)
#define  ADC_ADC_APLL_ADC_TESTOUT_MUX_adc_data_select_mask                       (0x30000000)
#define  ADC_ADC_APLL_ADC_TESTOUT_MUX_dummy_27_9_mask                            (0x0FFFFE00)
#define  ADC_ADC_APLL_ADC_TESTOUT_MUX_dummy_7_5_mask                             (0x000000E0)
#define  ADC_ADC_APLL_ADC_TESTOUT_MUX_apll_adc_tstout_mux_mask                   (0x0000001C)
#define  ADC_ADC_APLL_ADC_TESTOUT_MUX_adc_tstout_mux_mask                        (0x00000003)
#define  ADC_ADC_APLL_ADC_TESTOUT_MUX_dac_data_select(data)                      (0x40000000&((data)<<30))
#define  ADC_ADC_APLL_ADC_TESTOUT_MUX_adc_data_select(data)                      (0x30000000&((data)<<28))
#define  ADC_ADC_APLL_ADC_TESTOUT_MUX_dummy_27_9(data)                           (0x0FFFFE00&((data)<<9))
#define  ADC_ADC_APLL_ADC_TESTOUT_MUX_dummy_7_5(data)                            (0x000000E0&((data)<<5))
#define  ADC_ADC_APLL_ADC_TESTOUT_MUX_apll_adc_tstout_mux(data)                  (0x0000001C&((data)<<2))
#define  ADC_ADC_APLL_ADC_TESTOUT_MUX_adc_tstout_mux(data)                       (0x00000003&(data))
#define  ADC_ADC_APLL_ADC_TESTOUT_MUX_get_dac_data_select(data)                  ((0x40000000&(data))>>30)
#define  ADC_ADC_APLL_ADC_TESTOUT_MUX_get_adc_data_select(data)                  ((0x30000000&(data))>>28)
#define  ADC_ADC_APLL_ADC_TESTOUT_MUX_get_dummy_27_9(data)                       ((0x0FFFFE00&(data))>>9)
#define  ADC_ADC_APLL_ADC_TESTOUT_MUX_get_dummy_7_5(data)                        ((0x000000E0&(data))>>5)
#define  ADC_ADC_APLL_ADC_TESTOUT_MUX_get_apll_adc_tstout_mux(data)              ((0x0000001C&(data))>>2)
#define  ADC_ADC_APLL_ADC_TESTOUT_MUX_get_adc_tstout_mux(data)                   (0x00000003&(data))

#define  ADC_ADC_RGB_DATA                                                        0x18020088
#define  ADC_ADC_RGB_DATA_reg_addr                                               "0xB8020088"
#define  ADC_ADC_RGB_DATA_reg                                                    0xB8020088
#define  ADC_ADC_RGB_DATA_inst_addr                                              "0x001B"
#define  set_ADC_ADC_RGB_DATA_reg(data)                                          (*((volatile unsigned int*)ADC_ADC_RGB_DATA_reg)=data)
#define  get_ADC_ADC_RGB_DATA_reg                                                (*((volatile unsigned int*)ADC_ADC_RGB_DATA_reg))
#define  ADC_ADC_RGB_DATA_iadc_rout_shift                                        (16)
#define  ADC_ADC_RGB_DATA_iadc_gout_shift                                        (0)
#define  ADC_ADC_RGB_DATA_iadc_rout_mask                                         (0x0FFF0000)
#define  ADC_ADC_RGB_DATA_iadc_gout_mask                                         (0x00000FFF)
#define  ADC_ADC_RGB_DATA_iadc_rout(data)                                        (0x0FFF0000&((data)<<16))
#define  ADC_ADC_RGB_DATA_iadc_gout(data)                                        (0x00000FFF&(data))
#define  ADC_ADC_RGB_DATA_get_iadc_rout(data)                                    ((0x0FFF0000&(data))>>16)
#define  ADC_ADC_RGB_DATA_get_iadc_gout(data)                                    (0x00000FFF&(data))

#define  ADC_ADC_RGB_DATA2                                                       0x1802008C
#define  ADC_ADC_RGB_DATA2_reg_addr                                              "0xB802008C"
#define  ADC_ADC_RGB_DATA2_reg                                                   0xB802008C
#define  ADC_ADC_RGB_DATA2_inst_addr                                             "0x001C"
#define  set_ADC_ADC_RGB_DATA2_reg(data)                                         (*((volatile unsigned int*)ADC_ADC_RGB_DATA2_reg)=data)
#define  get_ADC_ADC_RGB_DATA2_reg                                               (*((volatile unsigned int*)ADC_ADC_RGB_DATA2_reg))
#define  ADC_ADC_RGB_DATA2_iadc_bout_shift                                       (16)
#define  ADC_ADC_RGB_DATA2_iadc_vout_shift                                       (0)
#define  ADC_ADC_RGB_DATA2_iadc_bout_mask                                        (0x0FFF0000)
#define  ADC_ADC_RGB_DATA2_iadc_vout_mask                                        (0x000003FF)
#define  ADC_ADC_RGB_DATA2_iadc_bout(data)                                       (0x0FFF0000&((data)<<16))
#define  ADC_ADC_RGB_DATA2_iadc_vout(data)                                       (0x000003FF&(data))
#define  ADC_ADC_RGB_DATA2_get_iadc_bout(data)                                   ((0x0FFF0000&(data))>>16)
#define  ADC_ADC_RGB_DATA2_get_iadc_vout(data)                                   (0x000003FF&(data))

#define  ADC_VDADC_IN_FLAG                                                       0x18020090
#define  ADC_VDADC_IN_FLAG_reg_addr                                              "0xB8020090"
#define  ADC_VDADC_IN_FLAG_reg                                                   0xB8020090
#define  ADC_VDADC_IN_FLAG_inst_addr                                             "0x001D"
#define  set_ADC_VDADC_IN_FLAG_reg(data)                                         (*((volatile unsigned int*)ADC_VDADC_IN_FLAG_reg)=data)
#define  get_ADC_VDADC_IN_FLAG_reg                                               (*((volatile unsigned int*)ADC_VDADC_IN_FLAG_reg))
#define  ADC_VDADC_IN_FLAG_vdadc_in_flag_shift                                   (2)
#define  ADC_VDADC_IN_FLAG_vdadc_ovfl_flag_shift                                 (1)
#define  ADC_VDADC_IN_FLAG_vdadc_unfl_flag_shift                                 (0)
#define  ADC_VDADC_IN_FLAG_vdadc_in_flag_mask                                    (0x00000004)
#define  ADC_VDADC_IN_FLAG_vdadc_ovfl_flag_mask                                  (0x00000002)
#define  ADC_VDADC_IN_FLAG_vdadc_unfl_flag_mask                                  (0x00000001)
#define  ADC_VDADC_IN_FLAG_vdadc_in_flag(data)                                   (0x00000004&((data)<<2))
#define  ADC_VDADC_IN_FLAG_vdadc_ovfl_flag(data)                                 (0x00000002&((data)<<1))
#define  ADC_VDADC_IN_FLAG_vdadc_unfl_flag(data)                                 (0x00000001&(data))
#define  ADC_VDADC_IN_FLAG_get_vdadc_in_flag(data)                               ((0x00000004&(data))>>2)
#define  ADC_VDADC_IN_FLAG_get_vdadc_ovfl_flag(data)                             ((0x00000002&(data))>>1)
#define  ADC_VDADC_IN_FLAG_get_vdadc_unfl_flag(data)                             (0x00000001&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======ADC register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18020000_31_16:16;
        RBus_UInt32  res1:6;
        RBus_UInt32  adc_power_9:1;
        RBus_UInt32  adc_power_8:1;
        RBus_UInt32  adc_power_7:1;
        RBus_UInt32  adc_power_6:1;
        RBus_UInt32  adc_power_5:1;
        RBus_UInt32  adc_power_4:1;
        RBus_UInt32  adc_power_3:1;
        RBus_UInt32  adc_power_2:1;
        RBus_UInt32  adc_power_1:1;
        RBus_UInt32  adc_power_0:1;
    };
}adc_adc_power_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  adc_ibias1_7:1;
        RBus_UInt32  adc_ibias1_6:1;
        RBus_UInt32  adc_ibias1_5:1;
        RBus_UInt32  adc_ibias1_4_1:4;
        RBus_UInt32  adc_ibias1_0:1;
        RBus_UInt32  adc_ibias0:8;
    };
}adc_adc_ibias0123_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  adc_ctl_rgb2_11_10:2;
        RBus_UInt32  adc_ctl_rgb2_9:1;
        RBus_UInt32  adc_ctl_rgb2_8:1;
        RBus_UInt32  adc_ctl_rgb2_7:1;
        RBus_UInt32  adc_ctl_rgb2_6:1;
        RBus_UInt32  adc_ctl_rgb2_5_4:2;
        RBus_UInt32  adc_ctl_rgb2_3_2:2;
        RBus_UInt32  adc_ctl_rgb2_1_0:2;
        RBus_UInt32  res2:4;
        RBus_UInt32  adc_ctl_rgb1_11_10:2;
        RBus_UInt32  adc_ctl_rgb1_9:1;
        RBus_UInt32  adc_ctl_rgb1_8:1;
        RBus_UInt32  adc_ctl_rgb1_7:1;
        RBus_UInt32  adc_ctl_rgb1_6:1;
        RBus_UInt32  adc_ctl_rgb1_5_4:2;
        RBus_UInt32  adc_ctl_rgb1_3_2:2;
        RBus_UInt32  adc_ctl_rgb1_1_0:2;
    };
}adc_adc_ctl_rgb12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  adc_vbias3_7:1;
        RBus_UInt32  adc_vbias3_6:1;
        RBus_UInt32  adc_vbias3_5:1;
        RBus_UInt32  adc_vbias3_4:1;
        RBus_UInt32  adc_vbias3_3:1;
        RBus_UInt32  adc_vbias3_2:1;
        RBus_UInt32  adc_vbias3_1_0:2;
        RBus_UInt32  adc_vbias2_7:1;
        RBus_UInt32  adc_vbias2_6:1;
        RBus_UInt32  adc_vbias2_5:1;
        RBus_UInt32  adc_vbias2_4:1;
        RBus_UInt32  adc_vbias2_3:1;
        RBus_UInt32  adc_vbias2_2_0:3;
        RBus_UInt32  adc_vbias1_7:1;
        RBus_UInt32  adc_vbias1_6:1;
        RBus_UInt32  adc_vbias1_5_4:2;
        RBus_UInt32  adc_vbias1_3_2:2;
        RBus_UInt32  adc_vbias1_1:1;
        RBus_UInt32  adc_vbias1_0:1;
        RBus_UInt32  adc_vbias0_7_5:3;
        RBus_UInt32  adc_vbias0_4_2:3;
        RBus_UInt32  adc_vbias0_1:1;
        RBus_UInt32  adc_vbias0_0:1;
    };
}adc_adc_vbias_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  adc_2x_sample_7:1;
        RBus_UInt32  adc_2x_sample_6:1;
        RBus_UInt32  adc_2x_sample_5:1;
        RBus_UInt32  adc_2x_sample_4_3:2;
        RBus_UInt32  adc_2x_sample_2:1;
        RBus_UInt32  adc_2x_sample_1:1;
        RBus_UInt32  adc_2x_sample_0:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  adc_clock_11:1;
        RBus_UInt32  adc_clock_10:1;
        RBus_UInt32  adc_clock_9_8:2;
        RBus_UInt32  adc_clock_7:1;
        RBus_UInt32  adc_clock_6:1;
        RBus_UInt32  adc_clock_5_4:2;
        RBus_UInt32  adc_clock_3:1;
        RBus_UInt32  adc_clock_2:1;
        RBus_UInt32  adc_clock_1_0:2;
    };
}adc_adc_clock_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}adc_adc_ctl_reserved_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  adc_ctl_rgb_7:1;
        RBus_UInt32  adc_ctl_rgb_6:1;
        RBus_UInt32  adc_ctl_rgb_5:1;
        RBus_UInt32  adc_ctl_rgb_4:1;
        RBus_UInt32  adc_ctl_rgb_3_0:4;
        RBus_UInt32  res2:7;
        RBus_UInt32  adc_dcrestore_ctrl_8:1;
        RBus_UInt32  adc_dcrestore_ctrl_7_6:2;
        RBus_UInt32  adc_dcrestore_ctrl_5:1;
        RBus_UInt32  adc_dcrestore_ctrl_4_3:2;
        RBus_UInt32  adc_dcrestore_ctrl_2:1;
        RBus_UInt32  adc_dcrestore_ctrl_1_0:2;
    };
}adc_adc_dcrestore_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  adc_clamp_ctrl2_11:1;
        RBus_UInt32  adc_clamp_ctrl2_10_9:2;
        RBus_UInt32  adc_clamp_ctrl2_8:1;
        RBus_UInt32  adc_clamp_ctrl2_7_6:2;
        RBus_UInt32  adc_clamp_ctrl2_5:1;
        RBus_UInt32  adc_clamp_ctrl2_4_3:2;
        RBus_UInt32  adc_clamp_ctrl2_2:1;
        RBus_UInt32  adc_clamp_ctrl2_1:1;
        RBus_UInt32  adc_clamp_ctrl2_0:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  res3:3;
        RBus_UInt32  adc_clamp_ctrl1_8:1;
        RBus_UInt32  adc_clamp_ctrl1_7_6:2;
        RBus_UInt32  adc_clamp_ctrl1_5:1;
        RBus_UInt32  adc_clamp_ctrl1_4_3:2;
        RBus_UInt32  adc_clamp_ctrl1_2:1;
        RBus_UInt32  adc_clamp_ctrl1_1_0:2;
    };
}adc_adc_clamp_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  adc_clamp_ctrl4_7:1;
        RBus_UInt32  adc_clamp_ctrl4_6:1;
        RBus_UInt32  adc_clamp_ctrl4_5:1;
        RBus_UInt32  adc_clamp_ctrl4_4_0:5;
        RBus_UInt32  res2:7;
        RBus_UInt32  adc_clamp_ctrl0_8:1;
        RBus_UInt32  adc_clamp_ctrl0_7_6:2;
        RBus_UInt32  adc_clamp_ctrl0_5:1;
        RBus_UInt32  adc_clamp_ctrl0_4_3:2;
        RBus_UInt32  adc_clamp_ctrl0_2:1;
        RBus_UInt32  adc_clamp_ctrl0_1_0:2;
    };
}adc_adc_clamp_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  adc_sog_cmp_7_4:4;
        RBus_UInt32  adc_sog_cmp_3_0:4;
        RBus_UInt32  adc_sog_cmp1_7:1;
        RBus_UInt32  adc_sog_cmp1_6:1;
        RBus_UInt32  adc_sog_cmp1_5_0:6;
        RBus_UInt32  res1:7;
        RBus_UInt32  adc_clamp_ctrl3_8:1;
        RBus_UInt32  adc_clamp_ctrl3_7_6:2;
        RBus_UInt32  adc_clamp_ctrl3_5:1;
        RBus_UInt32  adc_clamp_ctrl3_4_3:2;
        RBus_UInt32  adc_clamp_ctrl3_2:1;
        RBus_UInt32  adc_clamp_ctrl3_1_0:2;
    };
}adc_adc_clamp_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  adc_clamp_ctrl6_7:1;
        RBus_UInt32  adc_clamp_ctrl6_6:1;
        RBus_UInt32  adc_clamp_ctrl6_5:1;
        RBus_UInt32  adc_clamp_ctrl6_4:1;
        RBus_UInt32  adc_clamp_ctrl6_3:1;
        RBus_UInt32  adc_clamp_ctrl6_2:1;
        RBus_UInt32  adc_clamp_ctrl6_1:1;
        RBus_UInt32  adc_clamp_ctrl6_0:1;
        RBus_UInt32  adc_clamp_ctrl5_15:1;
        RBus_UInt32  adc_clamp_ctrl5_14_13:2;
        RBus_UInt32  adc_clamp_ctrl5_12:1;
        RBus_UInt32  adc_clamp_ctrl5_11_10:2;
        RBus_UInt32  adc_clamp_ctrl5_9_7:3;
        RBus_UInt32  adc_clamp_ctrl5_6:1;
        RBus_UInt32  adc_clamp_ctrl5_5:1;
        RBus_UInt32  adc_clamp_ctrl5_4:1;
        RBus_UInt32  adc_clamp_ctrl5_3:1;
        RBus_UInt32  adc_clamp_ctrl5_2_1:2;
        RBus_UInt32  adc_clamp_ctrl5_0:1;
    };
}adc_adc_clamp_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}adc_adc_ibias4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  adc_gain_grn:9;
        RBus_UInt32  dummy18020030_15_9:7;
        RBus_UInt32  adc_gain_red:9;
    };
}adc_adc_gain0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  res2:10;
        RBus_UInt32  res3:7;
        RBus_UInt32  adc_gain_blu:9;
    };
}adc_adc_gain1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  adc_off_grn:10;
        RBus_UInt32  dummy18020038_15_10:6;
        RBus_UInt32  adc_off_red:10;
    };
}adc_adc_offset0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  res2:10;
        RBus_UInt32  res3:6;
        RBus_UInt32  adc_off_blu:10;
    };
}adc_adc_offset1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  adc_ctl_red_10_9:2;
        RBus_UInt32  adc_ctl_red_8_6:3;
        RBus_UInt32  adc_ctl_red_5_3:3;
        RBus_UInt32  adc_ctl_red_2_0:3;
        RBus_UInt32  res2:5;
        RBus_UInt32  adc_ctl_grn_10_9:2;
        RBus_UInt32  adc_ctl_grn_8_6:3;
        RBus_UInt32  adc_ctl_grn_5_3:3;
        RBus_UInt32  adc_ctl_grn_2_0:3;
    };
}adc_adc_ctl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  adc_ctl_blu_10_9:2;
        RBus_UInt32  adc_ctl_blu_8_6:3;
        RBus_UInt32  adc_ctl_blu_5_3:3;
        RBus_UInt32  adc_ctl_blu_2_0:3;
    };
}adc_adc_ctl_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vdadc_clamp_ctrl0_15_14:2;
        RBus_UInt32  vdadc_clamp_ctrl0_13:1;
        RBus_UInt32  vdadc_clamp_ctrl0_12:1;
        RBus_UInt32  vdadc_clamp_ctrl0_11_10:2;
        RBus_UInt32  vdadc_clamp_ctrl0_9_8:2;
        RBus_UInt32  vdadc_clamp_ctrl0_7_4:4;
        RBus_UInt32  vdadc_clamp_ctrl0_3_0:4;
        RBus_UInt32  vdadc_clamp_ctrl1_15:1;
        RBus_UInt32  vdadc_clamp_ctrl1_14_13:2;
        RBus_UInt32  vdadc_clamp_ctrl1_12:1;
        RBus_UInt32  vdadc_clamp_ctrl1_11:1;
        RBus_UInt32  vdadc_clamp_ctrl1_10_9:2;
        RBus_UInt32  vdadc_clamp_ctrl1_8:1;
        RBus_UInt32  vdadc_clamp_ctrl1_7:1;
        RBus_UInt32  vdadc_clamp_ctrl1_6_5:2;
        RBus_UInt32  vdadc_clamp_ctrl1_4:1;
        RBus_UInt32  vdadc_clamp_ctrl1_3_2:2;
        RBus_UInt32  vdadc_clamp_ctrl1_1_0:2;
    };
}adc_vd_adc_clamp_ctl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  vdadc_clamp_ctrl2_15:1;
        RBus_UInt32  vdadc_clamp_ctrl2_14_12:3;
        RBus_UInt32  vdadc_clamp_ctrl2_11:1;
        RBus_UInt32  vdadc_clamp_ctrl2_10:1;
        RBus_UInt32  vdadc_clamp_ctrl2_9_8:2;
        RBus_UInt32  vdadc_clamp_ctrl2_7:1;
        RBus_UInt32  vdadc_clamp_ctrl2_6:1;
        RBus_UInt32  vdadc_clamp_ctrl2_5:1;
        RBus_UInt32  vdadc_clamp_ctrl2_4_2:3;
        RBus_UInt32  vdadc_clamp_ctrl2_1_0:2;
    };
}adc_vd_adc_clamp_ctl_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  vdadc_updn_ctrl0_15_14:2;
        RBus_UInt32  vdadc_updn_ctrl0_13_11:3;
        RBus_UInt32  vdadc_updn_ctrl0_10_8:3;
        RBus_UInt32  vdadc_updn_ctrl0_7_3:5;
        RBus_UInt32  vdadc_updn_ctrl0_2:1;
        RBus_UInt32  vdadc_updn_ctrl0_1_0:2;
    };
}adc_vd_adc_updn_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vdadc_adc_ctrl_15_13:3;
        RBus_UInt32  vdadc_adc_ctrl_12_10:3;
        RBus_UInt32  vdadc_adc_ctrl_9_8:2;
        RBus_UInt32  vdadc_adc_ctrl_7:1;
        RBus_UInt32  vdadc_adc_ctrl_6:1;
        RBus_UInt32  vdadc_adc_ctrl_5_3:3;
        RBus_UInt32  vdadc_adc_ctrl_2:1;
        RBus_UInt32  vdadc_adc_ctrl_1:1;
        RBus_UInt32  vdadc_adc_ctrl_0:1;
        RBus_UInt32  res1:8;
        RBus_UInt32  vdadc_lpf_ctrl_7_2:6;
        RBus_UInt32  vdadc_lpf_ctrl_1_0:2;
    };
}adc_vdadc_core_lpf_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  vdadc_ckin_sel_7:1;
        RBus_UInt32  vdadc_ckin_sel_6:1;
        RBus_UInt32  vdadc_ckin_sel_5:1;
        RBus_UInt32  vdadc_ckin_sel_4_2:3;
        RBus_UInt32  vdadc_ckin_sel_1_0:2;
        RBus_UInt32  vdadc_ckout_sel_7:1;
        RBus_UInt32  vdadc_ckout_sel_6:1;
        RBus_UInt32  vdadc_ckout_sel_5:1;
        RBus_UInt32  vdadc_ckout_sel_4:1;
        RBus_UInt32  vdadc_ckout_sel_3_2:2;
        RBus_UInt32  vdadc_ckout_sel_1_0:2;
    };
}adc_vdadc_ck_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vdadc_reserve:16;
        RBus_UInt32  res1:14;
        RBus_UInt32  ldo100ma_pow:1;
        RBus_UInt32  vdadc_pow:1;
    };
}adc_vdadc_pow_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}adc_vd_sct_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  vsync_e2:1;
        RBus_UInt32  vsync_pd:1;
        RBus_UInt32  vsync_pu:1;
        RBus_UInt32  vsync_sr:1;
        RBus_UInt32  hsync0_pwdn:1;
        RBus_UInt32  hsync0_pd_latch:1;
        RBus_UInt32  hsync0_3ven:1;
        RBus_UInt32  hsync0_pol:1;
        RBus_UInt32  hsync0_mode:1;
        RBus_UInt32  hsync0_vos:1;
        RBus_UInt32  hsync0_vtp_1_0:2;
        RBus_UInt32  hsync0_vtn_1_0:2;
    };
}adc_ahs_smt_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  adc_test_7:1;
        RBus_UInt32  adc_test_6_4:3;
        RBus_UInt32  adc_test_3:1;
        RBus_UInt32  adc_test_2:1;
        RBus_UInt32  adc_test_1_0:2;
    };
}adc_adc_test_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  vdadc_sct_ctrl:8;
    };
}adc_scart_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hs_hsfb_err_judge_sel:1;
        RBus_UInt32  flag_hs_catch_err_r:1;
        RBus_UInt32  hs_err_judge_en:1;
        RBus_UInt32  hs_catch_edge:1;
        RBus_UInt32  flag_hs_catch_err_ie:1;
        RBus_UInt32  vbick_div_phsel:1;
        RBus_UInt32  vbick_div_inv:1;
        RBus_UInt32  adck_div_inv:1;
        RBus_UInt32  adck_div_phsel:2;
        RBus_UInt32  adck_div_sel:1;
        RBus_UInt32  adck_div_en:1;
        RBus_UInt32  ablagc_cpsel:1;
        RBus_UInt32  vbi_swap:3;
        RBus_UInt32  rgb_from_hsptg:1;
        RBus_UInt32  adc_swap:3;
        RBus_UInt32  vbi_clk_inv:1;
        RBus_UInt32  adc_clkx2_inv:1;
        RBus_UInt32  adc_clk_inv:1;
        RBus_UInt32  soy0_clk_inv:1;
        RBus_UInt32  adc_clk_inv_en:1;
        RBus_UInt32  vbi_clk_en:1;
        RBus_UInt32  adc_clkx2_en:1;
        RBus_UInt32  soy0_clk_en:1;
        RBus_UInt32  st_latch_en:1;
        RBus_UInt32  vbi_clkx2_sel:1;
        RBus_UInt32  adck_test:1;
        RBus_UInt32  soy_test_en:1;
    };
}adc_adc_clkgen_rgb_capture_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  dac_data_select:1;
        RBus_UInt32  adc_data_select:2;
        RBus_UInt32  dummy18020084_27_9:19;
        RBus_UInt32  res2:1;
        RBus_UInt32  dummy18020084_7_5:3;
        RBus_UInt32  apll_adc_tstout_mux:3;
        RBus_UInt32  adc_tstout_mux:2;
    };
}adc_adc_apll_adc_testout_mux_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  iadc_rout:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  iadc_gout:12;
    };
}adc_adc_rgb_data_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  iadc_bout:12;
        RBus_UInt32  res2:6;
        RBus_UInt32  iadc_vout:10;
    };
}adc_adc_rgb_data2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  vdadc_in_flag:1;
        RBus_UInt32  vdadc_ovfl_flag:1;
        RBus_UInt32  vdadc_unfl_flag:1;
    };
}adc_vdadc_in_flag_RBUS;

#else //apply LITTLE_ENDIAN

//======ADC register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  adc_power_0:1;
        RBus_UInt32  adc_power_1:1;
        RBus_UInt32  adc_power_2:1;
        RBus_UInt32  adc_power_3:1;
        RBus_UInt32  adc_power_4:1;
        RBus_UInt32  adc_power_5:1;
        RBus_UInt32  adc_power_6:1;
        RBus_UInt32  adc_power_7:1;
        RBus_UInt32  adc_power_8:1;
        RBus_UInt32  adc_power_9:1;
        RBus_UInt32  res1:6;
        RBus_UInt32  dummy18020000_31_16:16;
    };
}adc_adc_power_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  adc_ibias0:8;
        RBus_UInt32  adc_ibias1_0:1;
        RBus_UInt32  adc_ibias1_4_1:4;
        RBus_UInt32  adc_ibias1_5:1;
        RBus_UInt32  adc_ibias1_6:1;
        RBus_UInt32  adc_ibias1_7:1;
        RBus_UInt32  res1:8;
        RBus_UInt32  res2:8;
    };
}adc_adc_ibias0123_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  adc_ctl_rgb1_1_0:2;
        RBus_UInt32  adc_ctl_rgb1_3_2:2;
        RBus_UInt32  adc_ctl_rgb1_5_4:2;
        RBus_UInt32  adc_ctl_rgb1_6:1;
        RBus_UInt32  adc_ctl_rgb1_7:1;
        RBus_UInt32  adc_ctl_rgb1_8:1;
        RBus_UInt32  adc_ctl_rgb1_9:1;
        RBus_UInt32  adc_ctl_rgb1_11_10:2;
        RBus_UInt32  res1:4;
        RBus_UInt32  adc_ctl_rgb2_1_0:2;
        RBus_UInt32  adc_ctl_rgb2_3_2:2;
        RBus_UInt32  adc_ctl_rgb2_5_4:2;
        RBus_UInt32  adc_ctl_rgb2_6:1;
        RBus_UInt32  adc_ctl_rgb2_7:1;
        RBus_UInt32  adc_ctl_rgb2_8:1;
        RBus_UInt32  adc_ctl_rgb2_9:1;
        RBus_UInt32  adc_ctl_rgb2_11_10:2;
        RBus_UInt32  res2:4;
    };
}adc_adc_ctl_rgb12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  adc_vbias0_0:1;
        RBus_UInt32  adc_vbias0_1:1;
        RBus_UInt32  adc_vbias0_4_2:3;
        RBus_UInt32  adc_vbias0_7_5:3;
        RBus_UInt32  adc_vbias1_0:1;
        RBus_UInt32  adc_vbias1_1:1;
        RBus_UInt32  adc_vbias1_3_2:2;
        RBus_UInt32  adc_vbias1_5_4:2;
        RBus_UInt32  adc_vbias1_6:1;
        RBus_UInt32  adc_vbias1_7:1;
        RBus_UInt32  adc_vbias2_2_0:3;
        RBus_UInt32  adc_vbias2_3:1;
        RBus_UInt32  adc_vbias2_4:1;
        RBus_UInt32  adc_vbias2_5:1;
        RBus_UInt32  adc_vbias2_6:1;
        RBus_UInt32  adc_vbias2_7:1;
        RBus_UInt32  adc_vbias3_1_0:2;
        RBus_UInt32  adc_vbias3_2:1;
        RBus_UInt32  adc_vbias3_3:1;
        RBus_UInt32  adc_vbias3_4:1;
        RBus_UInt32  adc_vbias3_5:1;
        RBus_UInt32  adc_vbias3_6:1;
        RBus_UInt32  adc_vbias3_7:1;
    };
}adc_adc_vbias_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  adc_clock_1_0:2;
        RBus_UInt32  adc_clock_2:1;
        RBus_UInt32  adc_clock_3:1;
        RBus_UInt32  adc_clock_5_4:2;
        RBus_UInt32  adc_clock_6:1;
        RBus_UInt32  adc_clock_7:1;
        RBus_UInt32  adc_clock_9_8:2;
        RBus_UInt32  adc_clock_10:1;
        RBus_UInt32  adc_clock_11:1;
        RBus_UInt32  res1:4;
        RBus_UInt32  adc_2x_sample_0:1;
        RBus_UInt32  adc_2x_sample_1:1;
        RBus_UInt32  adc_2x_sample_2:1;
        RBus_UInt32  adc_2x_sample_4_3:2;
        RBus_UInt32  adc_2x_sample_5:1;
        RBus_UInt32  adc_2x_sample_6:1;
        RBus_UInt32  adc_2x_sample_7:1;
        RBus_UInt32  res2:8;
    };
}adc_adc_clock_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}adc_adc_ctl_reserved_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  adc_dcrestore_ctrl_1_0:2;
        RBus_UInt32  adc_dcrestore_ctrl_2:1;
        RBus_UInt32  adc_dcrestore_ctrl_4_3:2;
        RBus_UInt32  adc_dcrestore_ctrl_5:1;
        RBus_UInt32  adc_dcrestore_ctrl_7_6:2;
        RBus_UInt32  adc_dcrestore_ctrl_8:1;
        RBus_UInt32  res1:7;
        RBus_UInt32  adc_ctl_rgb_3_0:4;
        RBus_UInt32  adc_ctl_rgb_4:1;
        RBus_UInt32  adc_ctl_rgb_5:1;
        RBus_UInt32  adc_ctl_rgb_6:1;
        RBus_UInt32  adc_ctl_rgb_7:1;
        RBus_UInt32  res2:8;
    };
}adc_adc_dcrestore_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  adc_clamp_ctrl1_1_0:2;
        RBus_UInt32  adc_clamp_ctrl1_2:1;
        RBus_UInt32  adc_clamp_ctrl1_4_3:2;
        RBus_UInt32  adc_clamp_ctrl1_5:1;
        RBus_UInt32  adc_clamp_ctrl1_7_6:2;
        RBus_UInt32  adc_clamp_ctrl1_8:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  res2:4;
        RBus_UInt32  adc_clamp_ctrl2_0:1;
        RBus_UInt32  adc_clamp_ctrl2_1:1;
        RBus_UInt32  adc_clamp_ctrl2_2:1;
        RBus_UInt32  adc_clamp_ctrl2_4_3:2;
        RBus_UInt32  adc_clamp_ctrl2_5:1;
        RBus_UInt32  adc_clamp_ctrl2_7_6:2;
        RBus_UInt32  adc_clamp_ctrl2_8:1;
        RBus_UInt32  adc_clamp_ctrl2_10_9:2;
        RBus_UInt32  adc_clamp_ctrl2_11:1;
        RBus_UInt32  res3:4;
    };
}adc_adc_clamp_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  adc_clamp_ctrl0_1_0:2;
        RBus_UInt32  adc_clamp_ctrl0_2:1;
        RBus_UInt32  adc_clamp_ctrl0_4_3:2;
        RBus_UInt32  adc_clamp_ctrl0_5:1;
        RBus_UInt32  adc_clamp_ctrl0_7_6:2;
        RBus_UInt32  adc_clamp_ctrl0_8:1;
        RBus_UInt32  res1:7;
        RBus_UInt32  adc_clamp_ctrl4_4_0:5;
        RBus_UInt32  adc_clamp_ctrl4_5:1;
        RBus_UInt32  adc_clamp_ctrl4_6:1;
        RBus_UInt32  adc_clamp_ctrl4_7:1;
        RBus_UInt32  res2:8;
    };
}adc_adc_clamp_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  adc_clamp_ctrl3_1_0:2;
        RBus_UInt32  adc_clamp_ctrl3_2:1;
        RBus_UInt32  adc_clamp_ctrl3_4_3:2;
        RBus_UInt32  adc_clamp_ctrl3_5:1;
        RBus_UInt32  adc_clamp_ctrl3_7_6:2;
        RBus_UInt32  adc_clamp_ctrl3_8:1;
        RBus_UInt32  res1:7;
        RBus_UInt32  adc_sog_cmp1_5_0:6;
        RBus_UInt32  adc_sog_cmp1_6:1;
        RBus_UInt32  adc_sog_cmp1_7:1;
        RBus_UInt32  adc_sog_cmp_3_0:4;
        RBus_UInt32  adc_sog_cmp_7_4:4;
    };
}adc_adc_clamp_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  adc_clamp_ctrl5_0:1;
        RBus_UInt32  adc_clamp_ctrl5_2_1:2;
        RBus_UInt32  adc_clamp_ctrl5_3:1;
        RBus_UInt32  adc_clamp_ctrl5_4:1;
        RBus_UInt32  adc_clamp_ctrl5_5:1;
        RBus_UInt32  adc_clamp_ctrl5_6:1;
        RBus_UInt32  adc_clamp_ctrl5_9_7:3;
        RBus_UInt32  adc_clamp_ctrl5_11_10:2;
        RBus_UInt32  adc_clamp_ctrl5_12:1;
        RBus_UInt32  adc_clamp_ctrl5_14_13:2;
        RBus_UInt32  adc_clamp_ctrl5_15:1;
        RBus_UInt32  adc_clamp_ctrl6_0:1;
        RBus_UInt32  adc_clamp_ctrl6_1:1;
        RBus_UInt32  adc_clamp_ctrl6_2:1;
        RBus_UInt32  adc_clamp_ctrl6_3:1;
        RBus_UInt32  adc_clamp_ctrl6_4:1;
        RBus_UInt32  adc_clamp_ctrl6_5:1;
        RBus_UInt32  adc_clamp_ctrl6_6:1;
        RBus_UInt32  adc_clamp_ctrl6_7:1;
        RBus_UInt32  res1:8;
    };
}adc_adc_clamp_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}adc_adc_ibias4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  adc_gain_red:9;
        RBus_UInt32  dummy18020030_15_9:7;
        RBus_UInt32  adc_gain_grn:9;
        RBus_UInt32  res1:7;
    };
}adc_adc_gain0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  adc_gain_blu:9;
        RBus_UInt32  res1:7;
        RBus_UInt32  res2:10;
        RBus_UInt32  res3:6;
    };
}adc_adc_gain1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  adc_off_red:10;
        RBus_UInt32  dummy18020038_15_10:6;
        RBus_UInt32  adc_off_grn:10;
        RBus_UInt32  res1:6;
    };
}adc_adc_offset0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  adc_off_blu:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  res2:10;
        RBus_UInt32  res3:6;
    };
}adc_adc_offset1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  adc_ctl_grn_2_0:3;
        RBus_UInt32  adc_ctl_grn_5_3:3;
        RBus_UInt32  adc_ctl_grn_8_6:3;
        RBus_UInt32  adc_ctl_grn_10_9:2;
        RBus_UInt32  res1:5;
        RBus_UInt32  adc_ctl_red_2_0:3;
        RBus_UInt32  adc_ctl_red_5_3:3;
        RBus_UInt32  adc_ctl_red_8_6:3;
        RBus_UInt32  adc_ctl_red_10_9:2;
        RBus_UInt32  res2:5;
    };
}adc_adc_ctl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  adc_ctl_blu_2_0:3;
        RBus_UInt32  adc_ctl_blu_5_3:3;
        RBus_UInt32  adc_ctl_blu_8_6:3;
        RBus_UInt32  adc_ctl_blu_10_9:2;
        RBus_UInt32  res1:21;
    };
}adc_adc_ctl_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vdadc_clamp_ctrl1_1_0:2;
        RBus_UInt32  vdadc_clamp_ctrl1_3_2:2;
        RBus_UInt32  vdadc_clamp_ctrl1_4:1;
        RBus_UInt32  vdadc_clamp_ctrl1_6_5:2;
        RBus_UInt32  vdadc_clamp_ctrl1_7:1;
        RBus_UInt32  vdadc_clamp_ctrl1_8:1;
        RBus_UInt32  vdadc_clamp_ctrl1_10_9:2;
        RBus_UInt32  vdadc_clamp_ctrl1_11:1;
        RBus_UInt32  vdadc_clamp_ctrl1_12:1;
        RBus_UInt32  vdadc_clamp_ctrl1_14_13:2;
        RBus_UInt32  vdadc_clamp_ctrl1_15:1;
        RBus_UInt32  vdadc_clamp_ctrl0_3_0:4;
        RBus_UInt32  vdadc_clamp_ctrl0_7_4:4;
        RBus_UInt32  vdadc_clamp_ctrl0_9_8:2;
        RBus_UInt32  vdadc_clamp_ctrl0_11_10:2;
        RBus_UInt32  vdadc_clamp_ctrl0_12:1;
        RBus_UInt32  vdadc_clamp_ctrl0_13:1;
        RBus_UInt32  vdadc_clamp_ctrl0_15_14:2;
    };
}adc_vd_adc_clamp_ctl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vdadc_clamp_ctrl2_1_0:2;
        RBus_UInt32  vdadc_clamp_ctrl2_4_2:3;
        RBus_UInt32  vdadc_clamp_ctrl2_5:1;
        RBus_UInt32  vdadc_clamp_ctrl2_6:1;
        RBus_UInt32  vdadc_clamp_ctrl2_7:1;
        RBus_UInt32  vdadc_clamp_ctrl2_9_8:2;
        RBus_UInt32  vdadc_clamp_ctrl2_10:1;
        RBus_UInt32  vdadc_clamp_ctrl2_11:1;
        RBus_UInt32  vdadc_clamp_ctrl2_14_12:3;
        RBus_UInt32  vdadc_clamp_ctrl2_15:1;
        RBus_UInt32  res1:16;
    };
}adc_vd_adc_clamp_ctl_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vdadc_updn_ctrl0_1_0:2;
        RBus_UInt32  vdadc_updn_ctrl0_2:1;
        RBus_UInt32  vdadc_updn_ctrl0_7_3:5;
        RBus_UInt32  vdadc_updn_ctrl0_10_8:3;
        RBus_UInt32  vdadc_updn_ctrl0_13_11:3;
        RBus_UInt32  vdadc_updn_ctrl0_15_14:2;
        RBus_UInt32  res1:16;
    };
}adc_vd_adc_updn_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vdadc_lpf_ctrl_1_0:2;
        RBus_UInt32  vdadc_lpf_ctrl_7_2:6;
        RBus_UInt32  res1:8;
        RBus_UInt32  vdadc_adc_ctrl_0:1;
        RBus_UInt32  vdadc_adc_ctrl_1:1;
        RBus_UInt32  vdadc_adc_ctrl_2:1;
        RBus_UInt32  vdadc_adc_ctrl_5_3:3;
        RBus_UInt32  vdadc_adc_ctrl_6:1;
        RBus_UInt32  vdadc_adc_ctrl_7:1;
        RBus_UInt32  vdadc_adc_ctrl_9_8:2;
        RBus_UInt32  vdadc_adc_ctrl_12_10:3;
        RBus_UInt32  vdadc_adc_ctrl_15_13:3;
    };
}adc_vdadc_core_lpf_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vdadc_ckout_sel_1_0:2;
        RBus_UInt32  vdadc_ckout_sel_3_2:2;
        RBus_UInt32  vdadc_ckout_sel_4:1;
        RBus_UInt32  vdadc_ckout_sel_5:1;
        RBus_UInt32  vdadc_ckout_sel_6:1;
        RBus_UInt32  vdadc_ckout_sel_7:1;
        RBus_UInt32  vdadc_ckin_sel_1_0:2;
        RBus_UInt32  vdadc_ckin_sel_4_2:3;
        RBus_UInt32  vdadc_ckin_sel_5:1;
        RBus_UInt32  vdadc_ckin_sel_6:1;
        RBus_UInt32  vdadc_ckin_sel_7:1;
        RBus_UInt32  res1:16;
    };
}adc_vdadc_ck_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vdadc_pow:1;
        RBus_UInt32  ldo100ma_pow:1;
        RBus_UInt32  res1:14;
        RBus_UInt32  vdadc_reserve:16;
    };
}adc_vdadc_pow_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}adc_vd_sct_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hsync0_vtn_1_0:2;
        RBus_UInt32  hsync0_vtp_1_0:2;
        RBus_UInt32  hsync0_vos:1;
        RBus_UInt32  hsync0_mode:1;
        RBus_UInt32  hsync0_pol:1;
        RBus_UInt32  hsync0_3ven:1;
        RBus_UInt32  hsync0_pd_latch:1;
        RBus_UInt32  hsync0_pwdn:1;
        RBus_UInt32  vsync_sr:1;
        RBus_UInt32  vsync_pu:1;
        RBus_UInt32  vsync_pd:1;
        RBus_UInt32  vsync_e2:1;
        RBus_UInt32  res1:18;
    };
}adc_ahs_smt_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  adc_test_1_0:2;
        RBus_UInt32  adc_test_2:1;
        RBus_UInt32  adc_test_3:1;
        RBus_UInt32  adc_test_6_4:3;
        RBus_UInt32  adc_test_7:1;
        RBus_UInt32  res1:24;
    };
}adc_adc_test_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vdadc_sct_ctrl:8;
        RBus_UInt32  res1:24;
    };
}adc_scart_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  soy_test_en:1;
        RBus_UInt32  adck_test:1;
        RBus_UInt32  vbi_clkx2_sel:1;
        RBus_UInt32  st_latch_en:1;
        RBus_UInt32  soy0_clk_en:1;
        RBus_UInt32  adc_clkx2_en:1;
        RBus_UInt32  vbi_clk_en:1;
        RBus_UInt32  adc_clk_inv_en:1;
        RBus_UInt32  soy0_clk_inv:1;
        RBus_UInt32  adc_clk_inv:1;
        RBus_UInt32  adc_clkx2_inv:1;
        RBus_UInt32  vbi_clk_inv:1;
        RBus_UInt32  adc_swap:3;
        RBus_UInt32  rgb_from_hsptg:1;
        RBus_UInt32  vbi_swap:3;
        RBus_UInt32  ablagc_cpsel:1;
        RBus_UInt32  adck_div_en:1;
        RBus_UInt32  adck_div_sel:1;
        RBus_UInt32  adck_div_phsel:2;
        RBus_UInt32  adck_div_inv:1;
        RBus_UInt32  vbick_div_inv:1;
        RBus_UInt32  vbick_div_phsel:1;
        RBus_UInt32  flag_hs_catch_err_ie:1;
        RBus_UInt32  hs_catch_edge:1;
        RBus_UInt32  hs_err_judge_en:1;
        RBus_UInt32  flag_hs_catch_err_r:1;
        RBus_UInt32  hs_hsfb_err_judge_sel:1;
    };
}adc_adc_clkgen_rgb_capture_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  adc_tstout_mux:2;
        RBus_UInt32  apll_adc_tstout_mux:3;
        RBus_UInt32  dummy18020084_7_5:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  dummy18020084_27_9:19;
        RBus_UInt32  adc_data_select:2;
        RBus_UInt32  dac_data_select:1;
        RBus_UInt32  res2:1;
    };
}adc_adc_apll_adc_testout_mux_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  iadc_gout:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  iadc_rout:12;
        RBus_UInt32  res2:4;
    };
}adc_adc_rgb_data_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  iadc_vout:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  iadc_bout:12;
        RBus_UInt32  res2:4;
    };
}adc_adc_rgb_data2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vdadc_unfl_flag:1;
        RBus_UInt32  vdadc_ovfl_flag:1;
        RBus_UInt32  vdadc_in_flag:1;
        RBus_UInt32  res1:29;
    };
}adc_vdadc_in_flag_RBUS;




#endif 


#endif 
