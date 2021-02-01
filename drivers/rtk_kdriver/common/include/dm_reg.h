/**
* @file rbusDMReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2016/6/7
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_DM_REG_H_
#define _RBUS_DM_REG_H_

#include "rbus/rbusTypes.h"



//  DM Register Address
#define  DM_dm_submodule_enable                                                  0x1806B500
#define  DM_dm_submodule_enable_reg_addr                                         "0xB806B500"
#define  DM_dm_submodule_enable_reg                                              0xB806B500
#define  DM_dm_submodule_enable_inst_addr                                        "0x0000"
#define  set_DM_dm_submodule_enable_reg(data)                                    (*((volatile unsigned int*)DM_dm_submodule_enable_reg)=data)
#define  get_DM_dm_submodule_enable_reg                                          (*((volatile unsigned int*)DM_dm_submodule_enable_reg))
#define  DM_dm_submodule_enable_dither_en_shift                                  (12)
#define  DM_dm_submodule_enable_format_444to422_dis_shift                        (11)
#define  DM_dm_submodule_enable_b05_enable_shift                                 (10)
#define  DM_dm_submodule_enable_b04_enable_shift                                 (9)
#define  DM_dm_submodule_enable_b03_enable_shift                                 (8)
#define  DM_dm_submodule_enable_b01_07_enable_shift                              (7)
#define  DM_dm_submodule_enable_b01_06_enable_shift                              (6)
#define  DM_dm_submodule_enable_b01_05_enable_shift                              (5)
#define  DM_dm_submodule_enable_b01_04_enable_shift                              (4)
#define  DM_dm_submodule_enable_b01_03_enable_shift                              (3)
#define  DM_dm_submodule_enable_b01_02_enable_shift                              (2)
#define  DM_dm_submodule_enable_b01_01_422to444_enable_shift                     (1)
#define  DM_dm_submodule_enable_b01_01_420to422_enable_shift                     (0)
#define  DM_dm_submodule_enable_dither_en_mask                                   (0x00001000)
#define  DM_dm_submodule_enable_format_444to422_dis_mask                         (0x00000800)
#define  DM_dm_submodule_enable_b05_enable_mask                                  (0x00000400)
#define  DM_dm_submodule_enable_b04_enable_mask                                  (0x00000200)
#define  DM_dm_submodule_enable_b03_enable_mask                                  (0x00000100)
#define  DM_dm_submodule_enable_b01_07_enable_mask                               (0x00000080)
#define  DM_dm_submodule_enable_b01_06_enable_mask                               (0x00000040)
#define  DM_dm_submodule_enable_b01_05_enable_mask                               (0x00000020)
#define  DM_dm_submodule_enable_b01_04_enable_mask                               (0x00000010)
#define  DM_dm_submodule_enable_b01_03_enable_mask                               (0x00000008)
#define  DM_dm_submodule_enable_b01_02_enable_mask                               (0x00000004)
#define  DM_dm_submodule_enable_b01_01_422to444_enable_mask                      (0x00000002)
#define  DM_dm_submodule_enable_b01_01_420to422_enable_mask                      (0x00000001)
#define  DM_dm_submodule_enable_dither_en(data)                                  (0x00001000&((data)<<12))
#define  DM_dm_submodule_enable_format_444to422_dis(data)                        (0x00000800&((data)<<11))
#define  DM_dm_submodule_enable_b05_enable(data)                                 (0x00000400&((data)<<10))
#define  DM_dm_submodule_enable_b04_enable(data)                                 (0x00000200&((data)<<9))
#define  DM_dm_submodule_enable_b03_enable(data)                                 (0x00000100&((data)<<8))
#define  DM_dm_submodule_enable_b01_07_enable(data)                              (0x00000080&((data)<<7))
#define  DM_dm_submodule_enable_b01_06_enable(data)                              (0x00000040&((data)<<6))
#define  DM_dm_submodule_enable_b01_05_enable(data)                              (0x00000020&((data)<<5))
#define  DM_dm_submodule_enable_b01_04_enable(data)                              (0x00000010&((data)<<4))
#define  DM_dm_submodule_enable_b01_03_enable(data)                              (0x00000008&((data)<<3))
#define  DM_dm_submodule_enable_b01_02_enable(data)                              (0x00000004&((data)<<2))
#define  DM_dm_submodule_enable_b01_01_422to444_enable(data)                     (0x00000002&((data)<<1))
#define  DM_dm_submodule_enable_b01_01_420to422_enable(data)                     (0x00000001&(data))
#define  DM_dm_submodule_enable_get_dither_en(data)                              ((0x00001000&(data))>>12)
#define  DM_dm_submodule_enable_get_format_444to422_dis(data)                    ((0x00000800&(data))>>11)
#define  DM_dm_submodule_enable_get_b05_enable(data)                             ((0x00000400&(data))>>10)
#define  DM_dm_submodule_enable_get_b04_enable(data)                             ((0x00000200&(data))>>9)
#define  DM_dm_submodule_enable_get_b03_enable(data)                             ((0x00000100&(data))>>8)
#define  DM_dm_submodule_enable_get_b01_07_enable(data)                          ((0x00000080&(data))>>7)
#define  DM_dm_submodule_enable_get_b01_06_enable(data)                          ((0x00000040&(data))>>6)
#define  DM_dm_submodule_enable_get_b01_05_enable(data)                          ((0x00000020&(data))>>5)
#define  DM_dm_submodule_enable_get_b01_04_enable(data)                          ((0x00000010&(data))>>4)
#define  DM_dm_submodule_enable_get_b01_03_enable(data)                          ((0x00000008&(data))>>3)
#define  DM_dm_submodule_enable_get_b01_02_enable(data)                          ((0x00000004&(data))>>2)
#define  DM_dm_submodule_enable_get_b01_01_422to444_enable(data)                 ((0x00000002&(data))>>1)
#define  DM_dm_submodule_enable_get_b01_01_420to422_enable(data)                 (0x00000001&(data))

#define  DM_Input_Format                                                         0x1806B504
#define  DM_Input_Format_reg_addr                                                "0xB806B504"
#define  DM_Input_Format_reg                                                     0xB806B504
#define  DM_Input_Format_inst_addr                                               "0x0001"
#define  set_DM_Input_Format_reg(data)                                           (*((volatile unsigned int*)DM_Input_Format_reg)=data)
#define  get_DM_Input_Format_reg                                                 (*((volatile unsigned int*)DM_Input_Format_reg))
#define  DM_Input_Format_dm_inbits_sel_shift                                     (2)
#define  DM_Input_Format_debug_enable_shift                                      (1)
#define  DM_Input_Format_runmode_shift                                           (0)
#define  DM_Input_Format_dm_inbits_sel_mask                                      (0x00000004)
#define  DM_Input_Format_debug_enable_mask                                       (0x00000002)
#define  DM_Input_Format_runmode_mask                                            (0x00000001)
#define  DM_Input_Format_dm_inbits_sel(data)                                     (0x00000004&((data)<<2))
#define  DM_Input_Format_debug_enable(data)                                      (0x00000002&((data)<<1))
#define  DM_Input_Format_runmode(data)                                           (0x00000001&(data))
#define  DM_Input_Format_get_dm_inbits_sel(data)                                 ((0x00000004&(data))>>2)
#define  DM_Input_Format_get_debug_enable(data)                                  ((0x00000002&(data))>>1)
#define  DM_Input_Format_get_runmode(data)                                       (0x00000001&(data))

#define  DM_YCCtoRGB_coef0                                                       0x1806B508
#define  DM_YCCtoRGB_coef0_reg_addr                                              "0xB806B508"
#define  DM_YCCtoRGB_coef0_reg                                                   0xB806B508
#define  DM_YCCtoRGB_coef0_inst_addr                                             "0x0002"
#define  set_DM_YCCtoRGB_coef0_reg(data)                                         (*((volatile unsigned int*)DM_YCCtoRGB_coef0_reg)=data)
#define  get_DM_YCCtoRGB_coef0_reg                                               (*((volatile unsigned int*)DM_YCCtoRGB_coef0_reg))
#define  DM_YCCtoRGB_coef0_m33yuv2rgb01_shift                                    (16)
#define  DM_YCCtoRGB_coef0_m33yuv2rgb00_shift                                    (0)
#define  DM_YCCtoRGB_coef0_m33yuv2rgb01_mask                                     (0xFFFF0000)
#define  DM_YCCtoRGB_coef0_m33yuv2rgb00_mask                                     (0x0000FFFF)
#define  DM_YCCtoRGB_coef0_m33yuv2rgb01(data)                                    (0xFFFF0000&((data)<<16))
#define  DM_YCCtoRGB_coef0_m33yuv2rgb00(data)                                    (0x0000FFFF&(data))
#define  DM_YCCtoRGB_coef0_get_m33yuv2rgb01(data)                                ((0xFFFF0000&(data))>>16)
#define  DM_YCCtoRGB_coef0_get_m33yuv2rgb00(data)                                (0x0000FFFF&(data))

#define  DM_YCCtoRGB_coef1                                                       0x1806B50C
#define  DM_YCCtoRGB_coef1_reg_addr                                              "0xB806B50C"
#define  DM_YCCtoRGB_coef1_reg                                                   0xB806B50C
#define  DM_YCCtoRGB_coef1_inst_addr                                             "0x0003"
#define  set_DM_YCCtoRGB_coef1_reg(data)                                         (*((volatile unsigned int*)DM_YCCtoRGB_coef1_reg)=data)
#define  get_DM_YCCtoRGB_coef1_reg                                               (*((volatile unsigned int*)DM_YCCtoRGB_coef1_reg))
#define  DM_YCCtoRGB_coef1_m33yuv2rgb02_shift                                    (0)
#define  DM_YCCtoRGB_coef1_m33yuv2rgb02_mask                                     (0x0000FFFF)
#define  DM_YCCtoRGB_coef1_m33yuv2rgb02(data)                                    (0x0000FFFF&(data))
#define  DM_YCCtoRGB_coef1_get_m33yuv2rgb02(data)                                (0x0000FFFF&(data))

#define  DM_YCCtoRGB_coef2                                                       0x1806B510
#define  DM_YCCtoRGB_coef2_reg_addr                                              "0xB806B510"
#define  DM_YCCtoRGB_coef2_reg                                                   0xB806B510
#define  DM_YCCtoRGB_coef2_inst_addr                                             "0x0004"
#define  set_DM_YCCtoRGB_coef2_reg(data)                                         (*((volatile unsigned int*)DM_YCCtoRGB_coef2_reg)=data)
#define  get_DM_YCCtoRGB_coef2_reg                                               (*((volatile unsigned int*)DM_YCCtoRGB_coef2_reg))
#define  DM_YCCtoRGB_coef2_m33yuv2rgb11_shift                                    (16)
#define  DM_YCCtoRGB_coef2_m33yuv2rgb10_shift                                    (0)
#define  DM_YCCtoRGB_coef2_m33yuv2rgb11_mask                                     (0xFFFF0000)
#define  DM_YCCtoRGB_coef2_m33yuv2rgb10_mask                                     (0x0000FFFF)
#define  DM_YCCtoRGB_coef2_m33yuv2rgb11(data)                                    (0xFFFF0000&((data)<<16))
#define  DM_YCCtoRGB_coef2_m33yuv2rgb10(data)                                    (0x0000FFFF&(data))
#define  DM_YCCtoRGB_coef2_get_m33yuv2rgb11(data)                                ((0xFFFF0000&(data))>>16)
#define  DM_YCCtoRGB_coef2_get_m33yuv2rgb10(data)                                (0x0000FFFF&(data))

#define  DM_YCCtoRGB_coef3                                                       0x1806B514
#define  DM_YCCtoRGB_coef3_reg_addr                                              "0xB806B514"
#define  DM_YCCtoRGB_coef3_reg                                                   0xB806B514
#define  DM_YCCtoRGB_coef3_inst_addr                                             "0x0005"
#define  set_DM_YCCtoRGB_coef3_reg(data)                                         (*((volatile unsigned int*)DM_YCCtoRGB_coef3_reg)=data)
#define  get_DM_YCCtoRGB_coef3_reg                                               (*((volatile unsigned int*)DM_YCCtoRGB_coef3_reg))
#define  DM_YCCtoRGB_coef3_m33yuv2rgb12_shift                                    (0)
#define  DM_YCCtoRGB_coef3_m33yuv2rgb12_mask                                     (0x0000FFFF)
#define  DM_YCCtoRGB_coef3_m33yuv2rgb12(data)                                    (0x0000FFFF&(data))
#define  DM_YCCtoRGB_coef3_get_m33yuv2rgb12(data)                                (0x0000FFFF&(data))

#define  DM_YCCtoRGB_coef4                                                       0x1806B518
#define  DM_YCCtoRGB_coef4_reg_addr                                              "0xB806B518"
#define  DM_YCCtoRGB_coef4_reg                                                   0xB806B518
#define  DM_YCCtoRGB_coef4_inst_addr                                             "0x0006"
#define  set_DM_YCCtoRGB_coef4_reg(data)                                         (*((volatile unsigned int*)DM_YCCtoRGB_coef4_reg)=data)
#define  get_DM_YCCtoRGB_coef4_reg                                               (*((volatile unsigned int*)DM_YCCtoRGB_coef4_reg))
#define  DM_YCCtoRGB_coef4_m33yuv2rgb21_shift                                    (16)
#define  DM_YCCtoRGB_coef4_m33yuv2rgb20_shift                                    (0)
#define  DM_YCCtoRGB_coef4_m33yuv2rgb21_mask                                     (0xFFFF0000)
#define  DM_YCCtoRGB_coef4_m33yuv2rgb20_mask                                     (0x0000FFFF)
#define  DM_YCCtoRGB_coef4_m33yuv2rgb21(data)                                    (0xFFFF0000&((data)<<16))
#define  DM_YCCtoRGB_coef4_m33yuv2rgb20(data)                                    (0x0000FFFF&(data))
#define  DM_YCCtoRGB_coef4_get_m33yuv2rgb21(data)                                ((0xFFFF0000&(data))>>16)
#define  DM_YCCtoRGB_coef4_get_m33yuv2rgb20(data)                                (0x0000FFFF&(data))

#define  DM_YCCtoRGB_coef5                                                       0x1806B51C
#define  DM_YCCtoRGB_coef5_reg_addr                                              "0xB806B51C"
#define  DM_YCCtoRGB_coef5_reg                                                   0xB806B51C
#define  DM_YCCtoRGB_coef5_inst_addr                                             "0x0007"
#define  set_DM_YCCtoRGB_coef5_reg(data)                                         (*((volatile unsigned int*)DM_YCCtoRGB_coef5_reg)=data)
#define  get_DM_YCCtoRGB_coef5_reg                                               (*((volatile unsigned int*)DM_YCCtoRGB_coef5_reg))
#define  DM_YCCtoRGB_coef5_m33yuv2rgb22_shift                                    (0)
#define  DM_YCCtoRGB_coef5_m33yuv2rgb22_mask                                     (0x0000FFFF)
#define  DM_YCCtoRGB_coef5_m33yuv2rgb22(data)                                    (0x0000FFFF&(data))
#define  DM_YCCtoRGB_coef5_get_m33yuv2rgb22(data)                                (0x0000FFFF&(data))

#define  DM_YCCtoRGB_offset0                                                     0x1806B520
#define  DM_YCCtoRGB_offset0_reg_addr                                            "0xB806B520"
#define  DM_YCCtoRGB_offset0_reg                                                 0xB806B520
#define  DM_YCCtoRGB_offset0_inst_addr                                           "0x0008"
#define  set_DM_YCCtoRGB_offset0_reg(data)                                       (*((volatile unsigned int*)DM_YCCtoRGB_offset0_reg)=data)
#define  get_DM_YCCtoRGB_offset0_reg                                             (*((volatile unsigned int*)DM_YCCtoRGB_offset0_reg))
#define  DM_YCCtoRGB_offset0_v3yuv2rgboffinrgb0_shift                            (0)
#define  DM_YCCtoRGB_offset0_v3yuv2rgboffinrgb0_mask                             (0xFFFFFFFF)
#define  DM_YCCtoRGB_offset0_v3yuv2rgboffinrgb0(data)                            (0xFFFFFFFF&(data))
#define  DM_YCCtoRGB_offset0_get_v3yuv2rgboffinrgb0(data)                        (0xFFFFFFFF&(data))

#define  DM_YCCtoRGB_offset1                                                     0x1806B524
#define  DM_YCCtoRGB_offset1_reg_addr                                            "0xB806B524"
#define  DM_YCCtoRGB_offset1_reg                                                 0xB806B524
#define  DM_YCCtoRGB_offset1_inst_addr                                           "0x0009"
#define  set_DM_YCCtoRGB_offset1_reg(data)                                       (*((volatile unsigned int*)DM_YCCtoRGB_offset1_reg)=data)
#define  get_DM_YCCtoRGB_offset1_reg                                             (*((volatile unsigned int*)DM_YCCtoRGB_offset1_reg))
#define  DM_YCCtoRGB_offset1_v3yuv2rgboffinrgb1_shift                            (0)
#define  DM_YCCtoRGB_offset1_v3yuv2rgboffinrgb1_mask                             (0xFFFFFFFF)
#define  DM_YCCtoRGB_offset1_v3yuv2rgboffinrgb1(data)                            (0xFFFFFFFF&(data))
#define  DM_YCCtoRGB_offset1_get_v3yuv2rgboffinrgb1(data)                        (0xFFFFFFFF&(data))

#define  DM_YCCtoRGB_offset2                                                     0x1806B528
#define  DM_YCCtoRGB_offset2_reg_addr                                            "0xB806B528"
#define  DM_YCCtoRGB_offset2_reg                                                 0xB806B528
#define  DM_YCCtoRGB_offset2_inst_addr                                           "0x000A"
#define  set_DM_YCCtoRGB_offset2_reg(data)                                       (*((volatile unsigned int*)DM_YCCtoRGB_offset2_reg)=data)
#define  get_DM_YCCtoRGB_offset2_reg                                             (*((volatile unsigned int*)DM_YCCtoRGB_offset2_reg))
#define  DM_YCCtoRGB_offset2_v3yuv2rgboffinrgb2_shift                            (0)
#define  DM_YCCtoRGB_offset2_v3yuv2rgboffinrgb2_mask                             (0xFFFFFFFF)
#define  DM_YCCtoRGB_offset2_v3yuv2rgboffinrgb2(data)                            (0xFFFFFFFF&(data))
#define  DM_YCCtoRGB_offset2_get_v3yuv2rgboffinrgb2(data)                        (0xFFFFFFFF&(data))

#define  DM_YCCtoRGB_Scale                                                       0x1806B52C
#define  DM_YCCtoRGB_Scale_reg_addr                                              "0xB806B52C"
#define  DM_YCCtoRGB_Scale_reg                                                   0xB806B52C
#define  DM_YCCtoRGB_Scale_inst_addr                                             "0x000B"
#define  set_DM_YCCtoRGB_Scale_reg(data)                                         (*((volatile unsigned int*)DM_YCCtoRGB_Scale_reg)=data)
#define  get_DM_YCCtoRGB_Scale_reg                                               (*((volatile unsigned int*)DM_YCCtoRGB_Scale_reg))
#define  DM_YCCtoRGB_Scale_bt2020_enable_shift                                   (5)
#define  DM_YCCtoRGB_Scale_ycctorgb_scale_shift                                  (0)
#define  DM_YCCtoRGB_Scale_bt2020_enable_mask                                    (0x00000020)
#define  DM_YCCtoRGB_Scale_ycctorgb_scale_mask                                   (0x0000001F)
#define  DM_YCCtoRGB_Scale_bt2020_enable(data)                                   (0x00000020&((data)<<5))
#define  DM_YCCtoRGB_Scale_ycctorgb_scale(data)                                  (0x0000001F&(data))
#define  DM_YCCtoRGB_Scale_get_bt2020_enable(data)                               ((0x00000020&(data))>>5)
#define  DM_YCCtoRGB_Scale_get_ycctorgb_scale(data)                              (0x0000001F&(data))

#define  DM_Signal_range                                                         0x1806B530
#define  DM_Signal_range_reg_addr                                                "0xB806B530"
#define  DM_Signal_range_reg                                                     0xB806B530
#define  DM_Signal_range_inst_addr                                               "0x000C"
#define  set_DM_Signal_range_reg(data)                                           (*((volatile unsigned int*)DM_Signal_range_reg)=data)
#define  get_DM_Signal_range_reg                                                 (*((volatile unsigned int*)DM_Signal_range_reg))
#define  DM_Signal_range_rangemax_shift                                          (16)
#define  DM_Signal_range_rangemin_shift                                          (0)
#define  DM_Signal_range_rangemax_mask                                           (0xFFFF0000)
#define  DM_Signal_range_rangemin_mask                                           (0x0000FFFF)
#define  DM_Signal_range_rangemax(data)                                          (0xFFFF0000&((data)<<16))
#define  DM_Signal_range_rangemin(data)                                          (0x0000FFFF&(data))
#define  DM_Signal_range_get_rangemax(data)                                      ((0xFFFF0000&(data))>>16)
#define  DM_Signal_range_get_rangemin(data)                                      (0x0000FFFF&(data))

#define  DM_sRangeInv                                                            0x1806B534
#define  DM_sRangeInv_reg_addr                                                   "0xB806B534"
#define  DM_sRangeInv_reg                                                        0xB806B534
#define  DM_sRangeInv_inst_addr                                                  "0x000D"
#define  set_DM_sRangeInv_reg(data)                                              (*((volatile unsigned int*)DM_sRangeInv_reg)=data)
#define  get_DM_sRangeInv_reg                                                    (*((volatile unsigned int*)DM_sRangeInv_reg))
#define  DM_sRangeInv_srangeinv_shift                                            (0)
#define  DM_sRangeInv_srangeinv_mask                                             (0xFFFFFFFF)
#define  DM_sRangeInv_srangeinv(data)                                            (0xFFFFFFFF&(data))
#define  DM_sRangeInv_get_srangeinv(data)                                        (0xFFFFFFFF&(data))

#define  DM_EOTF_para0                                                           0x1806B538
#define  DM_EOTF_para0_reg_addr                                                  "0xB806B538"
#define  DM_EOTF_para0_reg                                                       0xB806B538
#define  DM_EOTF_para0_inst_addr                                                 "0x000E"
#define  set_DM_EOTF_para0_reg(data)                                             (*((volatile unsigned int*)DM_EOTF_para0_reg)=data)
#define  get_DM_EOTF_para0_reg                                                   (*((volatile unsigned int*)DM_EOTF_para0_reg))
#define  DM_EOTF_para0_signal_eotf_param1_shift                                  (16)
#define  DM_EOTF_para0_signal_eotf_param0_shift                                  (0)
#define  DM_EOTF_para0_signal_eotf_param1_mask                                   (0xFFFF0000)
#define  DM_EOTF_para0_signal_eotf_param0_mask                                   (0x0000FFFF)
#define  DM_EOTF_para0_signal_eotf_param1(data)                                  (0xFFFF0000&((data)<<16))
#define  DM_EOTF_para0_signal_eotf_param0(data)                                  (0x0000FFFF&(data))
#define  DM_EOTF_para0_get_signal_eotf_param1(data)                              ((0xFFFF0000&(data))>>16)
#define  DM_EOTF_para0_get_signal_eotf_param0(data)                              (0x0000FFFF&(data))

#define  DM_EOTF_para1                                                           0x1806B53C
#define  DM_EOTF_para1_reg_addr                                                  "0xB806B53C"
#define  DM_EOTF_para1_reg                                                       0xB806B53C
#define  DM_EOTF_para1_inst_addr                                                 "0x000F"
#define  set_DM_EOTF_para1_reg(data)                                             (*((volatile unsigned int*)DM_EOTF_para1_reg)=data)
#define  get_DM_EOTF_para1_reg                                                   (*((volatile unsigned int*)DM_EOTF_para1_reg))
#define  DM_EOTF_para1_seotf_shift                                               (16)
#define  DM_EOTF_para1_signal_eotf_shift                                         (0)
#define  DM_EOTF_para1_seotf_mask                                                (0x00030000)
#define  DM_EOTF_para1_signal_eotf_mask                                          (0x0000FFFF)
#define  DM_EOTF_para1_seotf(data)                                               (0x00030000&((data)<<16))
#define  DM_EOTF_para1_signal_eotf(data)                                         (0x0000FFFF&(data))
#define  DM_EOTF_para1_get_seotf(data)                                           ((0x00030000&(data))>>16)
#define  DM_EOTF_para1_get_signal_eotf(data)                                     (0x0000FFFF&(data))

#define  DM_EOTF_para2                                                           0x1806B540
#define  DM_EOTF_para2_reg_addr                                                  "0xB806B540"
#define  DM_EOTF_para2_reg                                                       0xB806B540
#define  DM_EOTF_para2_inst_addr                                                 "0x0010"
#define  set_DM_EOTF_para2_reg(data)                                             (*((volatile unsigned int*)DM_EOTF_para2_reg)=data)
#define  get_DM_EOTF_para2_reg                                                   (*((volatile unsigned int*)DM_EOTF_para2_reg))
#define  DM_EOTF_para2_signal_eotf_param2_shift                                  (0)
#define  DM_EOTF_para2_signal_eotf_param2_mask                                   (0x001FFFFF)
#define  DM_EOTF_para2_signal_eotf_param2(data)                                  (0x001FFFFF&(data))
#define  DM_EOTF_para2_get_signal_eotf_param2(data)                              (0x001FFFFF&(data))

#define  DM_RGBtoOPT_coef0                                                       0x1806B544
#define  DM_RGBtoOPT_coef0_reg_addr                                              "0xB806B544"
#define  DM_RGBtoOPT_coef0_reg                                                   0xB806B544
#define  DM_RGBtoOPT_coef0_inst_addr                                             "0x0011"
#define  set_DM_RGBtoOPT_coef0_reg(data)                                         (*((volatile unsigned int*)DM_RGBtoOPT_coef0_reg)=data)
#define  get_DM_RGBtoOPT_coef0_reg                                               (*((volatile unsigned int*)DM_RGBtoOPT_coef0_reg))
#define  DM_RGBtoOPT_coef0_m33rgb2opt01_shift                                    (16)
#define  DM_RGBtoOPT_coef0_m33rgb2opt00_shift                                    (0)
#define  DM_RGBtoOPT_coef0_m33rgb2opt01_mask                                     (0xFFFF0000)
#define  DM_RGBtoOPT_coef0_m33rgb2opt00_mask                                     (0x0000FFFF)
#define  DM_RGBtoOPT_coef0_m33rgb2opt01(data)                                    (0xFFFF0000&((data)<<16))
#define  DM_RGBtoOPT_coef0_m33rgb2opt00(data)                                    (0x0000FFFF&(data))
#define  DM_RGBtoOPT_coef0_get_m33rgb2opt01(data)                                ((0xFFFF0000&(data))>>16)
#define  DM_RGBtoOPT_coef0_get_m33rgb2opt00(data)                                (0x0000FFFF&(data))

#define  DM_RGBtoOPT_coef1                                                       0x1806B548
#define  DM_RGBtoOPT_coef1_reg_addr                                              "0xB806B548"
#define  DM_RGBtoOPT_coef1_reg                                                   0xB806B548
#define  DM_RGBtoOPT_coef1_inst_addr                                             "0x0012"
#define  set_DM_RGBtoOPT_coef1_reg(data)                                         (*((volatile unsigned int*)DM_RGBtoOPT_coef1_reg)=data)
#define  get_DM_RGBtoOPT_coef1_reg                                               (*((volatile unsigned int*)DM_RGBtoOPT_coef1_reg))
#define  DM_RGBtoOPT_coef1_m33rgb2opt02_shift                                    (0)
#define  DM_RGBtoOPT_coef1_m33rgb2opt02_mask                                     (0x0000FFFF)
#define  DM_RGBtoOPT_coef1_m33rgb2opt02(data)                                    (0x0000FFFF&(data))
#define  DM_RGBtoOPT_coef1_get_m33rgb2opt02(data)                                (0x0000FFFF&(data))

#define  DM_RGBtoOPT_coef2                                                       0x1806B54C
#define  DM_RGBtoOPT_coef2_reg_addr                                              "0xB806B54C"
#define  DM_RGBtoOPT_coef2_reg                                                   0xB806B54C
#define  DM_RGBtoOPT_coef2_inst_addr                                             "0x0013"
#define  set_DM_RGBtoOPT_coef2_reg(data)                                         (*((volatile unsigned int*)DM_RGBtoOPT_coef2_reg)=data)
#define  get_DM_RGBtoOPT_coef2_reg                                               (*((volatile unsigned int*)DM_RGBtoOPT_coef2_reg))
#define  DM_RGBtoOPT_coef2_m33rgb2opt11_shift                                    (16)
#define  DM_RGBtoOPT_coef2_m33rgb2opt10_shift                                    (0)
#define  DM_RGBtoOPT_coef2_m33rgb2opt11_mask                                     (0xFFFF0000)
#define  DM_RGBtoOPT_coef2_m33rgb2opt10_mask                                     (0x0000FFFF)
#define  DM_RGBtoOPT_coef2_m33rgb2opt11(data)                                    (0xFFFF0000&((data)<<16))
#define  DM_RGBtoOPT_coef2_m33rgb2opt10(data)                                    (0x0000FFFF&(data))
#define  DM_RGBtoOPT_coef2_get_m33rgb2opt11(data)                                ((0xFFFF0000&(data))>>16)
#define  DM_RGBtoOPT_coef2_get_m33rgb2opt10(data)                                (0x0000FFFF&(data))

#define  DM_RGBtoOPT_coef3                                                       0x1806B550
#define  DM_RGBtoOPT_coef3_reg_addr                                              "0xB806B550"
#define  DM_RGBtoOPT_coef3_reg                                                   0xB806B550
#define  DM_RGBtoOPT_coef3_inst_addr                                             "0x0014"
#define  set_DM_RGBtoOPT_coef3_reg(data)                                         (*((volatile unsigned int*)DM_RGBtoOPT_coef3_reg)=data)
#define  get_DM_RGBtoOPT_coef3_reg                                               (*((volatile unsigned int*)DM_RGBtoOPT_coef3_reg))
#define  DM_RGBtoOPT_coef3_m33rgb2opt12_shift                                    (0)
#define  DM_RGBtoOPT_coef3_m33rgb2opt12_mask                                     (0x0000FFFF)
#define  DM_RGBtoOPT_coef3_m33rgb2opt12(data)                                    (0x0000FFFF&(data))
#define  DM_RGBtoOPT_coef3_get_m33rgb2opt12(data)                                (0x0000FFFF&(data))

#define  DM_RGBtoOPT_coef4                                                       0x1806B554
#define  DM_RGBtoOPT_coef4_reg_addr                                              "0xB806B554"
#define  DM_RGBtoOPT_coef4_reg                                                   0xB806B554
#define  DM_RGBtoOPT_coef4_inst_addr                                             "0x0015"
#define  set_DM_RGBtoOPT_coef4_reg(data)                                         (*((volatile unsigned int*)DM_RGBtoOPT_coef4_reg)=data)
#define  get_DM_RGBtoOPT_coef4_reg                                               (*((volatile unsigned int*)DM_RGBtoOPT_coef4_reg))
#define  DM_RGBtoOPT_coef4_m33rgb2opt21_shift                                    (16)
#define  DM_RGBtoOPT_coef4_m33rgb2opt20_shift                                    (0)
#define  DM_RGBtoOPT_coef4_m33rgb2opt21_mask                                     (0xFFFF0000)
#define  DM_RGBtoOPT_coef4_m33rgb2opt20_mask                                     (0x0000FFFF)
#define  DM_RGBtoOPT_coef4_m33rgb2opt21(data)                                    (0xFFFF0000&((data)<<16))
#define  DM_RGBtoOPT_coef4_m33rgb2opt20(data)                                    (0x0000FFFF&(data))
#define  DM_RGBtoOPT_coef4_get_m33rgb2opt21(data)                                ((0xFFFF0000&(data))>>16)
#define  DM_RGBtoOPT_coef4_get_m33rgb2opt20(data)                                (0x0000FFFF&(data))

#define  DM_RGBtoOPT_coef5                                                       0x1806B558
#define  DM_RGBtoOPT_coef5_reg_addr                                              "0xB806B558"
#define  DM_RGBtoOPT_coef5_reg                                                   0xB806B558
#define  DM_RGBtoOPT_coef5_inst_addr                                             "0x0016"
#define  set_DM_RGBtoOPT_coef5_reg(data)                                         (*((volatile unsigned int*)DM_RGBtoOPT_coef5_reg)=data)
#define  get_DM_RGBtoOPT_coef5_reg                                               (*((volatile unsigned int*)DM_RGBtoOPT_coef5_reg))
#define  DM_RGBtoOPT_coef5_m33rgb2opt22_shift                                    (0)
#define  DM_RGBtoOPT_coef5_m33rgb2opt22_mask                                     (0x0000FFFF)
#define  DM_RGBtoOPT_coef5_m33rgb2opt22(data)                                    (0x0000FFFF&(data))
#define  DM_RGBtoOPT_coef5_get_m33rgb2opt22(data)                                (0x0000FFFF&(data))

#define  DM_RGBtoOPT_Scale                                                       0x1806B55C
#define  DM_RGBtoOPT_Scale_reg_addr                                              "0xB806B55C"
#define  DM_RGBtoOPT_Scale_reg                                                   0xB806B55C
#define  DM_RGBtoOPT_Scale_inst_addr                                             "0x0017"
#define  set_DM_RGBtoOPT_Scale_reg(data)                                         (*((volatile unsigned int*)DM_RGBtoOPT_Scale_reg)=data)
#define  get_DM_RGBtoOPT_Scale_reg                                               (*((volatile unsigned int*)DM_RGBtoOPT_Scale_reg))
#define  DM_RGBtoOPT_Scale_b0104_max_val_sel_shift                               (31)
#define  DM_RGBtoOPT_Scale_rgb2optscale_shift                                    (0)
#define  DM_RGBtoOPT_Scale_b0104_max_val_sel_mask                                (0x80000000)
#define  DM_RGBtoOPT_Scale_rgb2optscale_mask                                     (0x0000000F)
#define  DM_RGBtoOPT_Scale_b0104_max_val_sel(data)                               (0x80000000&((data)<<31))
#define  DM_RGBtoOPT_Scale_rgb2optscale(data)                                    (0x0000000F&(data))
#define  DM_RGBtoOPT_Scale_get_b0104_max_val_sel(data)                           ((0x80000000&(data))>>31)
#define  DM_RGBtoOPT_Scale_get_rgb2optscale(data)                                (0x0000000F&(data))

#define  DM_RGBtoOPT_Offset0                                                     0x1806B738
#define  DM_RGBtoOPT_Offset0_reg_addr                                            "0xB806B738"
#define  DM_RGBtoOPT_Offset0_reg                                                 0xB806B738
#define  DM_RGBtoOPT_Offset0_inst_addr                                           "0x0018"
#define  set_DM_RGBtoOPT_Offset0_reg(data)                                       (*((volatile unsigned int*)DM_RGBtoOPT_Offset0_reg)=data)
#define  get_DM_RGBtoOPT_Offset0_reg                                             (*((volatile unsigned int*)DM_RGBtoOPT_Offset0_reg))
#define  DM_RGBtoOPT_Offset0_rgb2optoffset0_shift                                (0)
#define  DM_RGBtoOPT_Offset0_rgb2optoffset0_mask                                 (0xFFFFFFFF)
#define  DM_RGBtoOPT_Offset0_rgb2optoffset0(data)                                (0xFFFFFFFF&(data))
#define  DM_RGBtoOPT_Offset0_get_rgb2optoffset0(data)                            (0xFFFFFFFF&(data))

#define  DM_RGBtoOPT_Offset1                                                     0x1806B7C8
#define  DM_RGBtoOPT_Offset1_reg_addr                                            "0xB806B7C8"
#define  DM_RGBtoOPT_Offset1_reg                                                 0xB806B7C8
#define  DM_RGBtoOPT_Offset1_inst_addr                                           "0x0019"
#define  set_DM_RGBtoOPT_Offset1_reg(data)                                       (*((volatile unsigned int*)DM_RGBtoOPT_Offset1_reg)=data)
#define  get_DM_RGBtoOPT_Offset1_reg                                             (*((volatile unsigned int*)DM_RGBtoOPT_Offset1_reg))
#define  DM_RGBtoOPT_Offset1_rgb2optoffset1_shift                                (0)
#define  DM_RGBtoOPT_Offset1_rgb2optoffset1_mask                                 (0xFFFFFFFF)
#define  DM_RGBtoOPT_Offset1_rgb2optoffset1(data)                                (0xFFFFFFFF&(data))
#define  DM_RGBtoOPT_Offset1_get_rgb2optoffset1(data)                            (0xFFFFFFFF&(data))

#define  DM_RGBtoOPT_Offset2                                                     0x1806B7CC
#define  DM_RGBtoOPT_Offset2_reg_addr                                            "0xB806B7CC"
#define  DM_RGBtoOPT_Offset2_reg                                                 0xB806B7CC
#define  DM_RGBtoOPT_Offset2_inst_addr                                           "0x001A"
#define  set_DM_RGBtoOPT_Offset2_reg(data)                                       (*((volatile unsigned int*)DM_RGBtoOPT_Offset2_reg)=data)
#define  get_DM_RGBtoOPT_Offset2_reg                                             (*((volatile unsigned int*)DM_RGBtoOPT_Offset2_reg))
#define  DM_RGBtoOPT_Offset2_rgb2optoffset2_shift                                (0)
#define  DM_RGBtoOPT_Offset2_rgb2optoffset2_mask                                 (0xFFFFFFFF)
#define  DM_RGBtoOPT_Offset2_rgb2optoffset2(data)                                (0xFFFFFFFF&(data))
#define  DM_RGBtoOPT_Offset2_get_rgb2optoffset2(data)                            (0xFFFFFFFF&(data))

#define  DM_OPTtoOPT_coef0                                                       0x1806B560
#define  DM_OPTtoOPT_coef0_reg_addr                                              "0xB806B560"
#define  DM_OPTtoOPT_coef0_reg                                                   0xB806B560
#define  DM_OPTtoOPT_coef0_inst_addr                                             "0x001B"
#define  set_DM_OPTtoOPT_coef0_reg(data)                                         (*((volatile unsigned int*)DM_OPTtoOPT_coef0_reg)=data)
#define  get_DM_OPTtoOPT_coef0_reg                                               (*((volatile unsigned int*)DM_OPTtoOPT_coef0_reg))
#define  DM_OPTtoOPT_coef0_m33opt2opt01_shift                                    (16)
#define  DM_OPTtoOPT_coef0_m33opt2opt00_shift                                    (0)
#define  DM_OPTtoOPT_coef0_m33opt2opt01_mask                                     (0xFFFF0000)
#define  DM_OPTtoOPT_coef0_m33opt2opt00_mask                                     (0x0000FFFF)
#define  DM_OPTtoOPT_coef0_m33opt2opt01(data)                                    (0xFFFF0000&((data)<<16))
#define  DM_OPTtoOPT_coef0_m33opt2opt00(data)                                    (0x0000FFFF&(data))
#define  DM_OPTtoOPT_coef0_get_m33opt2opt01(data)                                ((0xFFFF0000&(data))>>16)
#define  DM_OPTtoOPT_coef0_get_m33opt2opt00(data)                                (0x0000FFFF&(data))

#define  DM_OPTtoOPT_coef1                                                       0x1806B564
#define  DM_OPTtoOPT_coef1_reg_addr                                              "0xB806B564"
#define  DM_OPTtoOPT_coef1_reg                                                   0xB806B564
#define  DM_OPTtoOPT_coef1_inst_addr                                             "0x001C"
#define  set_DM_OPTtoOPT_coef1_reg(data)                                         (*((volatile unsigned int*)DM_OPTtoOPT_coef1_reg)=data)
#define  get_DM_OPTtoOPT_coef1_reg                                               (*((volatile unsigned int*)DM_OPTtoOPT_coef1_reg))
#define  DM_OPTtoOPT_coef1_m33opt2opt02_shift                                    (0)
#define  DM_OPTtoOPT_coef1_m33opt2opt02_mask                                     (0x0000FFFF)
#define  DM_OPTtoOPT_coef1_m33opt2opt02(data)                                    (0x0000FFFF&(data))
#define  DM_OPTtoOPT_coef1_get_m33opt2opt02(data)                                (0x0000FFFF&(data))

#define  DM_OPTtoOPT_coef2                                                       0x1806B568
#define  DM_OPTtoOPT_coef2_reg_addr                                              "0xB806B568"
#define  DM_OPTtoOPT_coef2_reg                                                   0xB806B568
#define  DM_OPTtoOPT_coef2_inst_addr                                             "0x001D"
#define  set_DM_OPTtoOPT_coef2_reg(data)                                         (*((volatile unsigned int*)DM_OPTtoOPT_coef2_reg)=data)
#define  get_DM_OPTtoOPT_coef2_reg                                               (*((volatile unsigned int*)DM_OPTtoOPT_coef2_reg))
#define  DM_OPTtoOPT_coef2_m33opt2opt11_shift                                    (16)
#define  DM_OPTtoOPT_coef2_m33opt2opt10_shift                                    (0)
#define  DM_OPTtoOPT_coef2_m33opt2opt11_mask                                     (0xFFFF0000)
#define  DM_OPTtoOPT_coef2_m33opt2opt10_mask                                     (0x0000FFFF)
#define  DM_OPTtoOPT_coef2_m33opt2opt11(data)                                    (0xFFFF0000&((data)<<16))
#define  DM_OPTtoOPT_coef2_m33opt2opt10(data)                                    (0x0000FFFF&(data))
#define  DM_OPTtoOPT_coef2_get_m33opt2opt11(data)                                ((0xFFFF0000&(data))>>16)
#define  DM_OPTtoOPT_coef2_get_m33opt2opt10(data)                                (0x0000FFFF&(data))

#define  DM_OPTtoOPT_coef3                                                       0x1806B56C
#define  DM_OPTtoOPT_coef3_reg_addr                                              "0xB806B56C"
#define  DM_OPTtoOPT_coef3_reg                                                   0xB806B56C
#define  DM_OPTtoOPT_coef3_inst_addr                                             "0x001E"
#define  set_DM_OPTtoOPT_coef3_reg(data)                                         (*((volatile unsigned int*)DM_OPTtoOPT_coef3_reg)=data)
#define  get_DM_OPTtoOPT_coef3_reg                                               (*((volatile unsigned int*)DM_OPTtoOPT_coef3_reg))
#define  DM_OPTtoOPT_coef3_m33opt2opt12_shift                                    (0)
#define  DM_OPTtoOPT_coef3_m33opt2opt12_mask                                     (0x0000FFFF)
#define  DM_OPTtoOPT_coef3_m33opt2opt12(data)                                    (0x0000FFFF&(data))
#define  DM_OPTtoOPT_coef3_get_m33opt2opt12(data)                                (0x0000FFFF&(data))

#define  DM_OPTtoOPT_coef4                                                       0x1806B570
#define  DM_OPTtoOPT_coef4_reg_addr                                              "0xB806B570"
#define  DM_OPTtoOPT_coef4_reg                                                   0xB806B570
#define  DM_OPTtoOPT_coef4_inst_addr                                             "0x001F"
#define  set_DM_OPTtoOPT_coef4_reg(data)                                         (*((volatile unsigned int*)DM_OPTtoOPT_coef4_reg)=data)
#define  get_DM_OPTtoOPT_coef4_reg                                               (*((volatile unsigned int*)DM_OPTtoOPT_coef4_reg))
#define  DM_OPTtoOPT_coef4_m33opt2opt21_shift                                    (16)
#define  DM_OPTtoOPT_coef4_m33opt2opt20_shift                                    (0)
#define  DM_OPTtoOPT_coef4_m33opt2opt21_mask                                     (0xFFFF0000)
#define  DM_OPTtoOPT_coef4_m33opt2opt20_mask                                     (0x0000FFFF)
#define  DM_OPTtoOPT_coef4_m33opt2opt21(data)                                    (0xFFFF0000&((data)<<16))
#define  DM_OPTtoOPT_coef4_m33opt2opt20(data)                                    (0x0000FFFF&(data))
#define  DM_OPTtoOPT_coef4_get_m33opt2opt21(data)                                ((0xFFFF0000&(data))>>16)
#define  DM_OPTtoOPT_coef4_get_m33opt2opt20(data)                                (0x0000FFFF&(data))

#define  DM_OPTtoOPT_coef5                                                       0x1806B574
#define  DM_OPTtoOPT_coef5_reg_addr                                              "0xB806B574"
#define  DM_OPTtoOPT_coef5_reg                                                   0xB806B574
#define  DM_OPTtoOPT_coef5_inst_addr                                             "0x0020"
#define  set_DM_OPTtoOPT_coef5_reg(data)                                         (*((volatile unsigned int*)DM_OPTtoOPT_coef5_reg)=data)
#define  get_DM_OPTtoOPT_coef5_reg                                               (*((volatile unsigned int*)DM_OPTtoOPT_coef5_reg))
#define  DM_OPTtoOPT_coef5_m33opt2opt22_shift                                    (0)
#define  DM_OPTtoOPT_coef5_m33opt2opt22_mask                                     (0x0000FFFF)
#define  DM_OPTtoOPT_coef5_m33opt2opt22(data)                                    (0x0000FFFF&(data))
#define  DM_OPTtoOPT_coef5_get_m33opt2opt22(data)                                (0x0000FFFF&(data))

#define  DM_OPTtoOPT_Offset                                                      0x1806B578
#define  DM_OPTtoOPT_Offset_reg_addr                                             "0xB806B578"
#define  DM_OPTtoOPT_Offset_reg                                                  0xB806B578
#define  DM_OPTtoOPT_Offset_inst_addr                                            "0x0021"
#define  set_DM_OPTtoOPT_Offset_reg(data)                                        (*((volatile unsigned int*)DM_OPTtoOPT_Offset_reg)=data)
#define  get_DM_OPTtoOPT_Offset_reg                                              (*((volatile unsigned int*)DM_OPTtoOPT_Offset_reg))
#define  DM_OPTtoOPT_Offset_opt2optoffset_shift                                  (0)
#define  DM_OPTtoOPT_Offset_opt2optoffset_mask                                   (0x0000FFFF)
#define  DM_OPTtoOPT_Offset_opt2optoffset(data)                                  (0x0000FFFF&(data))
#define  DM_OPTtoOPT_Offset_get_opt2optoffset(data)                              (0x0000FFFF&(data))

#define  DM_OPTtoOPT_Scale                                                       0x1806B57C
#define  DM_OPTtoOPT_Scale_reg_addr                                              "0xB806B57C"
#define  DM_OPTtoOPT_Scale_reg                                                   0xB806B57C
#define  DM_OPTtoOPT_Scale_inst_addr                                             "0x0022"
#define  set_DM_OPTtoOPT_Scale_reg(data)                                         (*((volatile unsigned int*)DM_OPTtoOPT_Scale_reg)=data)
#define  get_DM_OPTtoOPT_Scale_reg                                               (*((volatile unsigned int*)DM_OPTtoOPT_Scale_reg))
#define  DM_OPTtoOPT_Scale_opt2optscale_shift                                    (0)
#define  DM_OPTtoOPT_Scale_opt2optscale_mask                                     (0x0000000F)
#define  DM_OPTtoOPT_Scale_opt2optscale(data)                                    (0x0000000F&(data))
#define  DM_OPTtoOPT_Scale_get_opt2optscale(data)                                (0x0000000F&(data))

#define  DM_LumaAdj_chromaWeight                                                 0x1806B580
#define  DM_LumaAdj_chromaWeight_reg_addr                                        "0xB806B580"
#define  DM_LumaAdj_chromaWeight_reg                                             0xB806B580
#define  DM_LumaAdj_chromaWeight_inst_addr                                       "0x0023"
#define  set_DM_LumaAdj_chromaWeight_reg(data)                                   (*((volatile unsigned int*)DM_LumaAdj_chromaWeight_reg)=data)
#define  get_DM_LumaAdj_chromaWeight_reg                                         (*((volatile unsigned int*)DM_LumaAdj_chromaWeight_reg))
#define  DM_LumaAdj_chromaWeight_chromaweight_shift                              (0)
#define  DM_LumaAdj_chromaWeight_chromaweight_mask                               (0x0000FFFF)
#define  DM_LumaAdj_chromaWeight_chromaweight(data)                              (0x0000FFFF&(data))
#define  DM_LumaAdj_chromaWeight_get_chromaweight(data)                          (0x0000FFFF&(data))

#define  DM_DM_B02_LUT_CTRL0                                                     0x1806B584
#define  DM_DM_B02_LUT_CTRL0_reg_addr                                            "0xB806B584"
#define  DM_DM_B02_LUT_CTRL0_reg                                                 0xB806B584
#define  DM_DM_B02_LUT_CTRL0_inst_addr                                           "0x0024"
#define  set_DM_DM_B02_LUT_CTRL0_reg(data)                                       (*((volatile unsigned int*)DM_DM_B02_LUT_CTRL0_reg)=data)
#define  get_DM_DM_B02_LUT_CTRL0_reg                                             (*((volatile unsigned int*)DM_DM_B02_LUT_CTRL0_reg))
#define  DM_DM_B02_LUT_CTRL0_lut_enable_shift                                    (31)
#define  DM_DM_B02_LUT_CTRL0_lut_acc_sel_shift                                   (30)
#define  DM_DM_B02_LUT_CTRL0_lut_rw_sel_shift                                    (28)
#define  DM_DM_B02_LUT_CTRL0_lut_acc_start_index_shift                           (0)
#define  DM_DM_B02_LUT_CTRL0_lut_enable_mask                                     (0x80000000)
#define  DM_DM_B02_LUT_CTRL0_lut_acc_sel_mask                                    (0x40000000)
#define  DM_DM_B02_LUT_CTRL0_lut_rw_sel_mask                                     (0x30000000)
#define  DM_DM_B02_LUT_CTRL0_lut_acc_start_index_mask                            (0x000001FF)
#define  DM_DM_B02_LUT_CTRL0_lut_enable(data)                                    (0x80000000&((data)<<31))
#define  DM_DM_B02_LUT_CTRL0_lut_acc_sel(data)                                   (0x40000000&((data)<<30))
#define  DM_DM_B02_LUT_CTRL0_lut_rw_sel(data)                                    (0x30000000&((data)<<28))
#define  DM_DM_B02_LUT_CTRL0_lut_acc_start_index(data)                           (0x000001FF&(data))
#define  DM_DM_B02_LUT_CTRL0_get_lut_enable(data)                                ((0x80000000&(data))>>31)
#define  DM_DM_B02_LUT_CTRL0_get_lut_acc_sel(data)                               ((0x40000000&(data))>>30)
#define  DM_DM_B02_LUT_CTRL0_get_lut_rw_sel(data)                                ((0x30000000&(data))>>28)
#define  DM_DM_B02_LUT_CTRL0_get_lut_acc_start_index(data)                       (0x000001FF&(data))

#define  DM_DM_B02_LUT_CTRL1                                                     0x1806B588
#define  DM_DM_B02_LUT_CTRL1_reg_addr                                            "0xB806B588"
#define  DM_DM_B02_LUT_CTRL1_reg                                                 0xB806B588
#define  DM_DM_B02_LUT_CTRL1_inst_addr                                           "0x0025"
#define  set_DM_DM_B02_LUT_CTRL1_reg(data)                                       (*((volatile unsigned int*)DM_DM_B02_LUT_CTRL1_reg)=data)
#define  get_DM_DM_B02_LUT_CTRL1_reg                                             (*((volatile unsigned int*)DM_DM_B02_LUT_CTRL1_reg))
#define  DM_DM_B02_LUT_CTRL1_write_en_shift                                      (1)
#define  DM_DM_B02_LUT_CTRL1_read_en_shift                                       (0)
#define  DM_DM_B02_LUT_CTRL1_write_en_mask                                       (0x00000002)
#define  DM_DM_B02_LUT_CTRL1_read_en_mask                                        (0x00000001)
#define  DM_DM_B02_LUT_CTRL1_write_en(data)                                      (0x00000002&((data)<<1))
#define  DM_DM_B02_LUT_CTRL1_read_en(data)                                       (0x00000001&(data))
#define  DM_DM_B02_LUT_CTRL1_get_write_en(data)                                  ((0x00000002&(data))>>1)
#define  DM_DM_B02_LUT_CTRL1_get_read_en(data)                                   (0x00000001&(data))

#define  DM_DM_B02_LUT_CTRL2                                                     0x1806B58C
#define  DM_DM_B02_LUT_CTRL2_reg_addr                                            "0xB806B58C"
#define  DM_DM_B02_LUT_CTRL2_reg                                                 0xB806B58C
#define  DM_DM_B02_LUT_CTRL2_inst_addr                                           "0x0026"
#define  set_DM_DM_B02_LUT_CTRL2_reg(data)                                       (*((volatile unsigned int*)DM_DM_B02_LUT_CTRL2_reg)=data)
#define  get_DM_DM_B02_LUT_CTRL2_reg                                             (*((volatile unsigned int*)DM_DM_B02_LUT_CTRL2_reg))
#define  DM_DM_B02_LUT_CTRL2_lut_data0_shift                                     (16)
#define  DM_DM_B02_LUT_CTRL2_lut_data1_shift                                     (0)
#define  DM_DM_B02_LUT_CTRL2_lut_data0_mask                                      (0x0FFF0000)
#define  DM_DM_B02_LUT_CTRL2_lut_data1_mask                                      (0x00000FFF)
#define  DM_DM_B02_LUT_CTRL2_lut_data0(data)                                     (0x0FFF0000&((data)<<16))
#define  DM_DM_B02_LUT_CTRL2_lut_data1(data)                                     (0x00000FFF&(data))
#define  DM_DM_B02_LUT_CTRL2_get_lut_data0(data)                                 ((0x0FFF0000&(data))>>16)
#define  DM_DM_B02_LUT_CTRL2_get_lut_data1(data)                                 (0x00000FFF&(data))

#define  DM_DM_B02_LUT_CTRL3                                                     0x1806B590
#define  DM_DM_B02_LUT_CTRL3_reg_addr                                            "0xB806B590"
#define  DM_DM_B02_LUT_CTRL3_reg                                                 0xB806B590
#define  DM_DM_B02_LUT_CTRL3_inst_addr                                           "0x0027"
#define  set_DM_DM_B02_LUT_CTRL3_reg(data)                                       (*((volatile unsigned int*)DM_DM_B02_LUT_CTRL3_reg)=data)
#define  get_DM_DM_B02_LUT_CTRL3_reg                                             (*((volatile unsigned int*)DM_DM_B02_LUT_CTRL3_reg))
#define  DM_DM_B02_LUT_CTRL3_lut_data2_shift                                     (16)
#define  DM_DM_B02_LUT_CTRL3_lut_data3_shift                                     (0)
#define  DM_DM_B02_LUT_CTRL3_lut_data2_mask                                      (0x0FFF0000)
#define  DM_DM_B02_LUT_CTRL3_lut_data3_mask                                      (0x00000FFF)
#define  DM_DM_B02_LUT_CTRL3_lut_data2(data)                                     (0x0FFF0000&((data)<<16))
#define  DM_DM_B02_LUT_CTRL3_lut_data3(data)                                     (0x00000FFF&(data))
#define  DM_DM_B02_LUT_CTRL3_get_lut_data2(data)                                 ((0x0FFF0000&(data))>>16)
#define  DM_DM_B02_LUT_CTRL3_get_lut_data3(data)                                 (0x00000FFF&(data))

#define  DM_DM_B02_LUT_CTRL4                                                     0x1806B594
#define  DM_DM_B02_LUT_CTRL4_reg_addr                                            "0xB806B594"
#define  DM_DM_B02_LUT_CTRL4_reg                                                 0xB806B594
#define  DM_DM_B02_LUT_CTRL4_inst_addr                                           "0x0028"
#define  set_DM_DM_B02_LUT_CTRL4_reg(data)                                       (*((volatile unsigned int*)DM_DM_B02_LUT_CTRL4_reg)=data)
#define  get_DM_DM_B02_LUT_CTRL4_reg                                             (*((volatile unsigned int*)DM_DM_B02_LUT_CTRL4_reg))
#define  DM_DM_B02_LUT_CTRL4_lut_data4_shift                                     (16)
#define  DM_DM_B02_LUT_CTRL4_lut_data5_shift                                     (0)
#define  DM_DM_B02_LUT_CTRL4_lut_data4_mask                                      (0x0FFF0000)
#define  DM_DM_B02_LUT_CTRL4_lut_data5_mask                                      (0x00000FFF)
#define  DM_DM_B02_LUT_CTRL4_lut_data4(data)                                     (0x0FFF0000&((data)<<16))
#define  DM_DM_B02_LUT_CTRL4_lut_data5(data)                                     (0x00000FFF&(data))
#define  DM_DM_B02_LUT_CTRL4_get_lut_data4(data)                                 ((0x0FFF0000&(data))>>16)
#define  DM_DM_B02_LUT_CTRL4_get_lut_data5(data)                                 (0x00000FFF&(data))

#define  DM_DM_B02_LUT_CTRL5                                                     0x1806B598
#define  DM_DM_B02_LUT_CTRL5_reg_addr                                            "0xB806B598"
#define  DM_DM_B02_LUT_CTRL5_reg                                                 0xB806B598
#define  DM_DM_B02_LUT_CTRL5_inst_addr                                           "0x0029"
#define  set_DM_DM_B02_LUT_CTRL5_reg(data)                                       (*((volatile unsigned int*)DM_DM_B02_LUT_CTRL5_reg)=data)
#define  get_DM_DM_B02_LUT_CTRL5_reg                                             (*((volatile unsigned int*)DM_DM_B02_LUT_CTRL5_reg))
#define  DM_DM_B02_LUT_CTRL5_lut_data6_shift                                     (16)
#define  DM_DM_B02_LUT_CTRL5_lut_data7_shift                                     (0)
#define  DM_DM_B02_LUT_CTRL5_lut_data6_mask                                      (0x0FFF0000)
#define  DM_DM_B02_LUT_CTRL5_lut_data7_mask                                      (0x00000FFF)
#define  DM_DM_B02_LUT_CTRL5_lut_data6(data)                                     (0x0FFF0000&((data)<<16))
#define  DM_DM_B02_LUT_CTRL5_lut_data7(data)                                     (0x00000FFF&(data))
#define  DM_DM_B02_LUT_CTRL5_get_lut_data6(data)                                 ((0x0FFF0000&(data))>>16)
#define  DM_DM_B02_LUT_CTRL5_get_lut_data7(data)                                 (0x00000FFF&(data))

#define  DM_DM_B02_LUT_STATUS0                                                   0x1806B59C
#define  DM_DM_B02_LUT_STATUS0_reg_addr                                          "0xB806B59C"
#define  DM_DM_B02_LUT_STATUS0_reg                                               0xB806B59C
#define  DM_DM_B02_LUT_STATUS0_inst_addr                                         "0x002A"
#define  set_DM_DM_B02_LUT_STATUS0_reg(data)                                     (*((volatile unsigned int*)DM_DM_B02_LUT_STATUS0_reg)=data)
#define  get_DM_DM_B02_LUT_STATUS0_reg                                           (*((volatile unsigned int*)DM_DM_B02_LUT_STATUS0_reg))
#define  DM_DM_B02_LUT_STATUS0_lut_acc_ready_shift                               (31)
#define  DM_DM_B02_LUT_STATUS0_lut_acc_index_cur_shift                           (0)
#define  DM_DM_B02_LUT_STATUS0_lut_acc_ready_mask                                (0x80000000)
#define  DM_DM_B02_LUT_STATUS0_lut_acc_index_cur_mask                            (0x000001FF)
#define  DM_DM_B02_LUT_STATUS0_lut_acc_ready(data)                               (0x80000000&((data)<<31))
#define  DM_DM_B02_LUT_STATUS0_lut_acc_index_cur(data)                           (0x000001FF&(data))
#define  DM_DM_B02_LUT_STATUS0_get_lut_acc_ready(data)                           ((0x80000000&(data))>>31)
#define  DM_DM_B02_LUT_STATUS0_get_lut_acc_index_cur(data)                       (0x000001FF&(data))

#define  DM_DM_B02_LUT_STATUS1                                                   0x1806B5A0
#define  DM_DM_B02_LUT_STATUS1_reg_addr                                          "0xB806B5A0"
#define  DM_DM_B02_LUT_STATUS1_reg                                               0xB806B5A0
#define  DM_DM_B02_LUT_STATUS1_inst_addr                                         "0x002B"
#define  set_DM_DM_B02_LUT_STATUS1_reg(data)                                     (*((volatile unsigned int*)DM_DM_B02_LUT_STATUS1_reg)=data)
#define  get_DM_DM_B02_LUT_STATUS1_reg                                           (*((volatile unsigned int*)DM_DM_B02_LUT_STATUS1_reg))
#define  DM_DM_B02_LUT_STATUS1_lut_data0_out_shift                               (16)
#define  DM_DM_B02_LUT_STATUS1_lut_data1_out_shift                               (0)
#define  DM_DM_B02_LUT_STATUS1_lut_data0_out_mask                                (0x0FFF0000)
#define  DM_DM_B02_LUT_STATUS1_lut_data1_out_mask                                (0x00000FFF)
#define  DM_DM_B02_LUT_STATUS1_lut_data0_out(data)                               (0x0FFF0000&((data)<<16))
#define  DM_DM_B02_LUT_STATUS1_lut_data1_out(data)                               (0x00000FFF&(data))
#define  DM_DM_B02_LUT_STATUS1_get_lut_data0_out(data)                           ((0x0FFF0000&(data))>>16)
#define  DM_DM_B02_LUT_STATUS1_get_lut_data1_out(data)                           (0x00000FFF&(data))

#define  DM_DM_B02_LUT_STATUS2                                                   0x1806B5A4
#define  DM_DM_B02_LUT_STATUS2_reg_addr                                          "0xB806B5A4"
#define  DM_DM_B02_LUT_STATUS2_reg                                               0xB806B5A4
#define  DM_DM_B02_LUT_STATUS2_inst_addr                                         "0x002C"
#define  set_DM_DM_B02_LUT_STATUS2_reg(data)                                     (*((volatile unsigned int*)DM_DM_B02_LUT_STATUS2_reg)=data)
#define  get_DM_DM_B02_LUT_STATUS2_reg                                           (*((volatile unsigned int*)DM_DM_B02_LUT_STATUS2_reg))
#define  DM_DM_B02_LUT_STATUS2_lut_data2_out_shift                               (16)
#define  DM_DM_B02_LUT_STATUS2_lut_data3_out_shift                               (0)
#define  DM_DM_B02_LUT_STATUS2_lut_data2_out_mask                                (0x0FFF0000)
#define  DM_DM_B02_LUT_STATUS2_lut_data3_out_mask                                (0x00000FFF)
#define  DM_DM_B02_LUT_STATUS2_lut_data2_out(data)                               (0x0FFF0000&((data)<<16))
#define  DM_DM_B02_LUT_STATUS2_lut_data3_out(data)                               (0x00000FFF&(data))
#define  DM_DM_B02_LUT_STATUS2_get_lut_data2_out(data)                           ((0x0FFF0000&(data))>>16)
#define  DM_DM_B02_LUT_STATUS2_get_lut_data3_out(data)                           (0x00000FFF&(data))

#define  DM_DM_B02_LUT_STATUS3                                                   0x1806B5A8
#define  DM_DM_B02_LUT_STATUS3_reg_addr                                          "0xB806B5A8"
#define  DM_DM_B02_LUT_STATUS3_reg                                               0xB806B5A8
#define  DM_DM_B02_LUT_STATUS3_inst_addr                                         "0x002D"
#define  set_DM_DM_B02_LUT_STATUS3_reg(data)                                     (*((volatile unsigned int*)DM_DM_B02_LUT_STATUS3_reg)=data)
#define  get_DM_DM_B02_LUT_STATUS3_reg                                           (*((volatile unsigned int*)DM_DM_B02_LUT_STATUS3_reg))
#define  DM_DM_B02_LUT_STATUS3_lut_data4_out_shift                               (16)
#define  DM_DM_B02_LUT_STATUS3_lut_data5_out_shift                               (0)
#define  DM_DM_B02_LUT_STATUS3_lut_data4_out_mask                                (0x0FFF0000)
#define  DM_DM_B02_LUT_STATUS3_lut_data5_out_mask                                (0x00000FFF)
#define  DM_DM_B02_LUT_STATUS3_lut_data4_out(data)                               (0x0FFF0000&((data)<<16))
#define  DM_DM_B02_LUT_STATUS3_lut_data5_out(data)                               (0x00000FFF&(data))
#define  DM_DM_B02_LUT_STATUS3_get_lut_data4_out(data)                           ((0x0FFF0000&(data))>>16)
#define  DM_DM_B02_LUT_STATUS3_get_lut_data5_out(data)                           (0x00000FFF&(data))

#define  DM_DM_B02_LUT_STATUS4                                                   0x1806B5AC
#define  DM_DM_B02_LUT_STATUS4_reg_addr                                          "0xB806B5AC"
#define  DM_DM_B02_LUT_STATUS4_reg                                               0xB806B5AC
#define  DM_DM_B02_LUT_STATUS4_inst_addr                                         "0x002E"
#define  set_DM_DM_B02_LUT_STATUS4_reg(data)                                     (*((volatile unsigned int*)DM_DM_B02_LUT_STATUS4_reg)=data)
#define  get_DM_DM_B02_LUT_STATUS4_reg                                           (*((volatile unsigned int*)DM_DM_B02_LUT_STATUS4_reg))
#define  DM_DM_B02_LUT_STATUS4_lut_data6_out_shift                               (16)
#define  DM_DM_B02_LUT_STATUS4_lut_data7_out_shift                               (0)
#define  DM_DM_B02_LUT_STATUS4_lut_data6_out_mask                                (0x0FFF0000)
#define  DM_DM_B02_LUT_STATUS4_lut_data7_out_mask                                (0x00000FFF)
#define  DM_DM_B02_LUT_STATUS4_lut_data6_out(data)                               (0x0FFF0000&((data)<<16))
#define  DM_DM_B02_LUT_STATUS4_lut_data7_out(data)                               (0x00000FFF&(data))
#define  DM_DM_B02_LUT_STATUS4_get_lut_data6_out(data)                           ((0x0FFF0000&(data))>>16)
#define  DM_DM_B02_LUT_STATUS4_get_lut_data7_out(data)                           (0x00000FFF&(data))

#define  DM_DM_B02_LUT_STATUS5                                                   0x1806B5B0
#define  DM_DM_B02_LUT_STATUS5_reg_addr                                          "0xB806B5B0"
#define  DM_DM_B02_LUT_STATUS5_reg                                               0xB806B5B0
#define  DM_DM_B02_LUT_STATUS5_inst_addr                                         "0x002F"
#define  set_DM_DM_B02_LUT_STATUS5_reg(data)                                     (*((volatile unsigned int*)DM_DM_B02_LUT_STATUS5_reg)=data)
#define  get_DM_DM_B02_LUT_STATUS5_reg                                           (*((volatile unsigned int*)DM_DM_B02_LUT_STATUS5_reg))
#define  DM_DM_B02_LUT_STATUS5_fw_lut0_rd_acc_shift                              (5)
#define  DM_DM_B02_LUT_STATUS5_fw_lut0_wr_acc_shift                              (4)
#define  DM_DM_B02_LUT_STATUS5_hw_lut0_rd_acc_shift                              (3)
#define  DM_DM_B02_LUT_STATUS5_fw_lut1_rd_acc_shift                              (2)
#define  DM_DM_B02_LUT_STATUS5_fw_lut1_wr_acc_shift                              (1)
#define  DM_DM_B02_LUT_STATUS5_hw_lut1_rd_acc_shift                              (0)
#define  DM_DM_B02_LUT_STATUS5_fw_lut0_rd_acc_mask                               (0x00000020)
#define  DM_DM_B02_LUT_STATUS5_fw_lut0_wr_acc_mask                               (0x00000010)
#define  DM_DM_B02_LUT_STATUS5_hw_lut0_rd_acc_mask                               (0x00000008)
#define  DM_DM_B02_LUT_STATUS5_fw_lut1_rd_acc_mask                               (0x00000004)
#define  DM_DM_B02_LUT_STATUS5_fw_lut1_wr_acc_mask                               (0x00000002)
#define  DM_DM_B02_LUT_STATUS5_hw_lut1_rd_acc_mask                               (0x00000001)
#define  DM_DM_B02_LUT_STATUS5_fw_lut0_rd_acc(data)                              (0x00000020&((data)<<5))
#define  DM_DM_B02_LUT_STATUS5_fw_lut0_wr_acc(data)                              (0x00000010&((data)<<4))
#define  DM_DM_B02_LUT_STATUS5_hw_lut0_rd_acc(data)                              (0x00000008&((data)<<3))
#define  DM_DM_B02_LUT_STATUS5_fw_lut1_rd_acc(data)                              (0x00000004&((data)<<2))
#define  DM_DM_B02_LUT_STATUS5_fw_lut1_wr_acc(data)                              (0x00000002&((data)<<1))
#define  DM_DM_B02_LUT_STATUS5_hw_lut1_rd_acc(data)                              (0x00000001&(data))
#define  DM_DM_B02_LUT_STATUS5_get_fw_lut0_rd_acc(data)                          ((0x00000020&(data))>>5)
#define  DM_DM_B02_LUT_STATUS5_get_fw_lut0_wr_acc(data)                          ((0x00000010&(data))>>4)
#define  DM_DM_B02_LUT_STATUS5_get_hw_lut0_rd_acc(data)                          ((0x00000008&(data))>>3)
#define  DM_DM_B02_LUT_STATUS5_get_fw_lut1_rd_acc(data)                          ((0x00000004&(data))>>2)
#define  DM_DM_B02_LUT_STATUS5_get_fw_lut1_wr_acc(data)                          ((0x00000002&(data))>>1)
#define  DM_DM_B02_LUT_STATUS5_get_hw_lut1_rd_acc(data)                          (0x00000001&(data))

#define  DM_BlendDbEdge                                                          0x1806B5B4
#define  DM_BlendDbEdge_reg_addr                                                 "0xB806B5B4"
#define  DM_BlendDbEdge_reg                                                      0xB806B5B4
#define  DM_BlendDbEdge_inst_addr                                                "0x0030"
#define  set_DM_BlendDbEdge_reg(data)                                            (*((volatile unsigned int*)DM_BlendDbEdge_reg)=data)
#define  get_DM_BlendDbEdge_reg                                                  (*((volatile unsigned int*)DM_BlendDbEdge_reg))
#define  DM_BlendDbEdge_weight_shift                                             (16)
#define  DM_BlendDbEdge_weight_edge_shift                                        (0)
#define  DM_BlendDbEdge_weight_mask                                              (0xFFFF0000)
#define  DM_BlendDbEdge_weight_edge_mask                                         (0x0000FFFF)
#define  DM_BlendDbEdge_weight(data)                                             (0xFFFF0000&((data)<<16))
#define  DM_BlendDbEdge_weight_edge(data)                                        (0x0000FFFF&(data))
#define  DM_BlendDbEdge_get_weight(data)                                         ((0xFFFF0000&(data))>>16)
#define  DM_BlendDbEdge_get_weight_edge(data)                                    (0x0000FFFF&(data))

#define  DM_FilterRow0                                                           0x1806B5B8
#define  DM_FilterRow0_reg_addr                                                  "0xB806B5B8"
#define  DM_FilterRow0_reg                                                       0xB806B5B8
#define  DM_FilterRow0_inst_addr                                                 "0x0031"
#define  set_DM_FilterRow0_reg(data)                                             (*((volatile unsigned int*)DM_FilterRow0_reg)=data)
#define  get_DM_FilterRow0_reg                                                   (*((volatile unsigned int*)DM_FilterRow0_reg))
#define  DM_FilterRow0_filter_row_c01_shift                                      (16)
#define  DM_FilterRow0_filter_row_c00_shift                                      (0)
#define  DM_FilterRow0_filter_row_c01_mask                                       (0x0FFF0000)
#define  DM_FilterRow0_filter_row_c00_mask                                       (0x00000FFF)
#define  DM_FilterRow0_filter_row_c01(data)                                      (0x0FFF0000&((data)<<16))
#define  DM_FilterRow0_filter_row_c00(data)                                      (0x00000FFF&(data))
#define  DM_FilterRow0_get_filter_row_c01(data)                                  ((0x0FFF0000&(data))>>16)
#define  DM_FilterRow0_get_filter_row_c00(data)                                  (0x00000FFF&(data))

#define  DM_FilterRow1                                                           0x1806B5BC
#define  DM_FilterRow1_reg_addr                                                  "0xB806B5BC"
#define  DM_FilterRow1_reg                                                       0xB806B5BC
#define  DM_FilterRow1_inst_addr                                                 "0x0032"
#define  set_DM_FilterRow1_reg(data)                                             (*((volatile unsigned int*)DM_FilterRow1_reg)=data)
#define  get_DM_FilterRow1_reg                                                   (*((volatile unsigned int*)DM_FilterRow1_reg))
#define  DM_FilterRow1_filter_row_c03_shift                                      (16)
#define  DM_FilterRow1_filter_row_c02_shift                                      (0)
#define  DM_FilterRow1_filter_row_c03_mask                                       (0x0FFF0000)
#define  DM_FilterRow1_filter_row_c02_mask                                       (0x00000FFF)
#define  DM_FilterRow1_filter_row_c03(data)                                      (0x0FFF0000&((data)<<16))
#define  DM_FilterRow1_filter_row_c02(data)                                      (0x00000FFF&(data))
#define  DM_FilterRow1_get_filter_row_c03(data)                                  ((0x0FFF0000&(data))>>16)
#define  DM_FilterRow1_get_filter_row_c02(data)                                  (0x00000FFF&(data))

#define  DM_FilterRow2                                                           0x1806B5C0
#define  DM_FilterRow2_reg_addr                                                  "0xB806B5C0"
#define  DM_FilterRow2_reg                                                       0xB806B5C0
#define  DM_FilterRow2_inst_addr                                                 "0x0033"
#define  set_DM_FilterRow2_reg(data)                                             (*((volatile unsigned int*)DM_FilterRow2_reg)=data)
#define  get_DM_FilterRow2_reg                                                   (*((volatile unsigned int*)DM_FilterRow2_reg))
#define  DM_FilterRow2_filter_row_c05_shift                                      (16)
#define  DM_FilterRow2_filter_row_c04_shift                                      (0)
#define  DM_FilterRow2_filter_row_c05_mask                                       (0x1FFF0000)
#define  DM_FilterRow2_filter_row_c04_mask                                       (0x00000FFF)
#define  DM_FilterRow2_filter_row_c05(data)                                      (0x1FFF0000&((data)<<16))
#define  DM_FilterRow2_filter_row_c04(data)                                      (0x00000FFF&(data))
#define  DM_FilterRow2_get_filter_row_c05(data)                                  ((0x1FFF0000&(data))>>16)
#define  DM_FilterRow2_get_filter_row_c04(data)                                  (0x00000FFF&(data))

#define  DM_FilterCol0                                                           0x1806B5C4
#define  DM_FilterCol0_reg_addr                                                  "0xB806B5C4"
#define  DM_FilterCol0_reg                                                       0xB806B5C4
#define  DM_FilterCol0_inst_addr                                                 "0x0034"
#define  set_DM_FilterCol0_reg(data)                                             (*((volatile unsigned int*)DM_FilterCol0_reg)=data)
#define  get_DM_FilterCol0_reg                                                   (*((volatile unsigned int*)DM_FilterCol0_reg))
#define  DM_FilterCol0_filter_col_c01_shift                                      (16)
#define  DM_FilterCol0_filter_col_c00_shift                                      (0)
#define  DM_FilterCol0_filter_col_c01_mask                                       (0x0FFF0000)
#define  DM_FilterCol0_filter_col_c00_mask                                       (0x00000FFF)
#define  DM_FilterCol0_filter_col_c01(data)                                      (0x0FFF0000&((data)<<16))
#define  DM_FilterCol0_filter_col_c00(data)                                      (0x00000FFF&(data))
#define  DM_FilterCol0_get_filter_col_c01(data)                                  ((0x0FFF0000&(data))>>16)
#define  DM_FilterCol0_get_filter_col_c00(data)                                  (0x00000FFF&(data))

#define  DM_FilterCol1                                                           0x1806B5C8
#define  DM_FilterCol1_reg_addr                                                  "0xB806B5C8"
#define  DM_FilterCol1_reg                                                       0xB806B5C8
#define  DM_FilterCol1_inst_addr                                                 "0x0035"
#define  set_DM_FilterCol1_reg(data)                                             (*((volatile unsigned int*)DM_FilterCol1_reg)=data)
#define  get_DM_FilterCol1_reg                                                   (*((volatile unsigned int*)DM_FilterCol1_reg))
#define  DM_FilterCol1_filter_col_c02_shift                                      (0)
#define  DM_FilterCol1_filter_col_c02_mask                                       (0x00001FFF)
#define  DM_FilterCol1_filter_col_c02(data)                                      (0x00001FFF&(data))
#define  DM_FilterCol1_get_filter_col_c02(data)                                  (0x00001FFF&(data))

#define  DM_FilterEdgeRow0                                                       0x1806B5CC
#define  DM_FilterEdgeRow0_reg_addr                                              "0xB806B5CC"
#define  DM_FilterEdgeRow0_reg                                                   0xB806B5CC
#define  DM_FilterEdgeRow0_inst_addr                                             "0x0036"
#define  set_DM_FilterEdgeRow0_reg(data)                                         (*((volatile unsigned int*)DM_FilterEdgeRow0_reg)=data)
#define  get_DM_FilterEdgeRow0_reg                                               (*((volatile unsigned int*)DM_FilterEdgeRow0_reg))
#define  DM_FilterEdgeRow0_filter_edge_row_c01_shift                             (16)
#define  DM_FilterEdgeRow0_filter_edge_row_c00_shift                             (0)
#define  DM_FilterEdgeRow0_filter_edge_row_c01_mask                              (0x0FFF0000)
#define  DM_FilterEdgeRow0_filter_edge_row_c00_mask                              (0x00000FFF)
#define  DM_FilterEdgeRow0_filter_edge_row_c01(data)                             (0x0FFF0000&((data)<<16))
#define  DM_FilterEdgeRow0_filter_edge_row_c00(data)                             (0x00000FFF&(data))
#define  DM_FilterEdgeRow0_get_filter_edge_row_c01(data)                         ((0x0FFF0000&(data))>>16)
#define  DM_FilterEdgeRow0_get_filter_edge_row_c00(data)                         (0x00000FFF&(data))

#define  DM_FilterEdgeRow1                                                       0x1806B5D0
#define  DM_FilterEdgeRow1_reg_addr                                              "0xB806B5D0"
#define  DM_FilterEdgeRow1_reg                                                   0xB806B5D0
#define  DM_FilterEdgeRow1_inst_addr                                             "0x0037"
#define  set_DM_FilterEdgeRow1_reg(data)                                         (*((volatile unsigned int*)DM_FilterEdgeRow1_reg)=data)
#define  get_DM_FilterEdgeRow1_reg                                               (*((volatile unsigned int*)DM_FilterEdgeRow1_reg))
#define  DM_FilterEdgeRow1_filter_edge_row_c03_shift                             (16)
#define  DM_FilterEdgeRow1_filter_edge_row_c02_shift                             (0)
#define  DM_FilterEdgeRow1_filter_edge_row_c03_mask                              (0x0FFF0000)
#define  DM_FilterEdgeRow1_filter_edge_row_c02_mask                              (0x00000FFF)
#define  DM_FilterEdgeRow1_filter_edge_row_c03(data)                             (0x0FFF0000&((data)<<16))
#define  DM_FilterEdgeRow1_filter_edge_row_c02(data)                             (0x00000FFF&(data))
#define  DM_FilterEdgeRow1_get_filter_edge_row_c03(data)                         ((0x0FFF0000&(data))>>16)
#define  DM_FilterEdgeRow1_get_filter_edge_row_c02(data)                         (0x00000FFF&(data))

#define  DM_FilterEdgeRow2                                                       0x1806B5D4
#define  DM_FilterEdgeRow2_reg_addr                                              "0xB806B5D4"
#define  DM_FilterEdgeRow2_reg                                                   0xB806B5D4
#define  DM_FilterEdgeRow2_inst_addr                                             "0x0038"
#define  set_DM_FilterEdgeRow2_reg(data)                                         (*((volatile unsigned int*)DM_FilterEdgeRow2_reg)=data)
#define  get_DM_FilterEdgeRow2_reg                                               (*((volatile unsigned int*)DM_FilterEdgeRow2_reg))
#define  DM_FilterEdgeRow2_filter_edge_row_c04_shift                             (0)
#define  DM_FilterEdgeRow2_filter_edge_row_c04_mask                              (0x00000FFF)
#define  DM_FilterEdgeRow2_filter_edge_row_c04(data)                             (0x00000FFF&(data))
#define  DM_FilterEdgeRow2_get_filter_edge_row_c04(data)                         (0x00000FFF&(data))

#define  DM_FilterEdgeCol0                                                       0x1806B5D8
#define  DM_FilterEdgeCol0_reg_addr                                              "0xB806B5D8"
#define  DM_FilterEdgeCol0_reg                                                   0xB806B5D8
#define  DM_FilterEdgeCol0_inst_addr                                             "0x0039"
#define  set_DM_FilterEdgeCol0_reg(data)                                         (*((volatile unsigned int*)DM_FilterEdgeCol0_reg)=data)
#define  get_DM_FilterEdgeCol0_reg                                               (*((volatile unsigned int*)DM_FilterEdgeCol0_reg))
#define  DM_FilterEdgeCol0_filter_edge_col_c01_shift                             (16)
#define  DM_FilterEdgeCol0_filter_edge_col_c00_shift                             (0)
#define  DM_FilterEdgeCol0_filter_edge_col_c01_mask                              (0x0FFF0000)
#define  DM_FilterEdgeCol0_filter_edge_col_c00_mask                              (0x00000FFF)
#define  DM_FilterEdgeCol0_filter_edge_col_c01(data)                             (0x0FFF0000&((data)<<16))
#define  DM_FilterEdgeCol0_filter_edge_col_c00(data)                             (0x00000FFF&(data))
#define  DM_FilterEdgeCol0_get_filter_edge_col_c01(data)                         ((0x0FFF0000&(data))>>16)
#define  DM_FilterEdgeCol0_get_filter_edge_col_c00(data)                         (0x00000FFF&(data))

#define  DM_SaturationAdj                                                        0x1806B5DC
#define  DM_SaturationAdj_reg_addr                                               "0xB806B5DC"
#define  DM_SaturationAdj_reg                                                    0xB806B5DC
#define  DM_SaturationAdj_inst_addr                                              "0x003A"
#define  set_DM_SaturationAdj_reg(data)                                          (*((volatile unsigned int*)DM_SaturationAdj_reg)=data)
#define  get_DM_SaturationAdj_reg                                                (*((volatile unsigned int*)DM_SaturationAdj_reg))
#define  DM_SaturationAdj_bypass_unsigned_en_shift                               (31)
#define  DM_SaturationAdj_saturationadj_offset_shift                             (16)
#define  DM_SaturationAdj_saturationadj_gain_shift                               (0)
#define  DM_SaturationAdj_bypass_unsigned_en_mask                                (0x80000000)
#define  DM_SaturationAdj_saturationadj_offset_mask                              (0x0FFF0000)
#define  DM_SaturationAdj_saturationadj_gain_mask                                (0x00000FFF)
#define  DM_SaturationAdj_bypass_unsigned_en(data)                               (0x80000000&((data)<<31))
#define  DM_SaturationAdj_saturationadj_offset(data)                             (0x0FFF0000&((data)<<16))
#define  DM_SaturationAdj_saturationadj_gain(data)                               (0x00000FFF&(data))
#define  DM_SaturationAdj_get_bypass_unsigned_en(data)                           ((0x80000000&(data))>>31)
#define  DM_SaturationAdj_get_saturationadj_offset(data)                         ((0x0FFF0000&(data))>>16)
#define  DM_SaturationAdj_get_saturationadj_gain(data)                           (0x00000FFF&(data))

#define  DM_SaturationGain                                                       0x1806B5E0
#define  DM_SaturationGain_reg_addr                                              "0xB806B5E0"
#define  DM_SaturationGain_reg                                                   0xB806B5E0
#define  DM_SaturationGain_inst_addr                                             "0x003B"
#define  set_DM_SaturationGain_reg(data)                                         (*((volatile unsigned int*)DM_SaturationGain_reg)=data)
#define  get_DM_SaturationGain_reg                                               (*((volatile unsigned int*)DM_SaturationGain_reg))
#define  DM_SaturationGain_saturationgain_shift                                  (0)
#define  DM_SaturationGain_saturationgain_mask                                   (0x0000FFFF)
#define  DM_SaturationGain_saturationgain(data)                                  (0x0000FFFF&(data))
#define  DM_SaturationGain_get_saturationgain(data)                              (0x0000FFFF&(data))

#define  DM_ThreeDLUT_MinMaxC1                                                   0x1806B5E4
#define  DM_ThreeDLUT_MinMaxC1_reg_addr                                          "0xB806B5E4"
#define  DM_ThreeDLUT_MinMaxC1_reg                                               0xB806B5E4
#define  DM_ThreeDLUT_MinMaxC1_inst_addr                                         "0x003C"
#define  set_DM_ThreeDLUT_MinMaxC1_reg(data)                                     (*((volatile unsigned int*)DM_ThreeDLUT_MinMaxC1_reg)=data)
#define  get_DM_ThreeDLUT_MinMaxC1_reg                                           (*((volatile unsigned int*)DM_ThreeDLUT_MinMaxC1_reg))
#define  DM_ThreeDLUT_MinMaxC1_maxc1_shift                                       (16)
#define  DM_ThreeDLUT_MinMaxC1_minc1_shift                                       (0)
#define  DM_ThreeDLUT_MinMaxC1_maxc1_mask                                        (0xFFFF0000)
#define  DM_ThreeDLUT_MinMaxC1_minc1_mask                                        (0x0000FFFF)
#define  DM_ThreeDLUT_MinMaxC1_maxc1(data)                                       (0xFFFF0000&((data)<<16))
#define  DM_ThreeDLUT_MinMaxC1_minc1(data)                                       (0x0000FFFF&(data))
#define  DM_ThreeDLUT_MinMaxC1_get_maxc1(data)                                   ((0xFFFF0000&(data))>>16)
#define  DM_ThreeDLUT_MinMaxC1_get_minc1(data)                                   (0x0000FFFF&(data))

#define  DM_ThreeDLUT_MinMaxC2                                                   0x1806B5E8
#define  DM_ThreeDLUT_MinMaxC2_reg_addr                                          "0xB806B5E8"
#define  DM_ThreeDLUT_MinMaxC2_reg                                               0xB806B5E8
#define  DM_ThreeDLUT_MinMaxC2_inst_addr                                         "0x003D"
#define  set_DM_ThreeDLUT_MinMaxC2_reg(data)                                     (*((volatile unsigned int*)DM_ThreeDLUT_MinMaxC2_reg)=data)
#define  get_DM_ThreeDLUT_MinMaxC2_reg                                           (*((volatile unsigned int*)DM_ThreeDLUT_MinMaxC2_reg))
#define  DM_ThreeDLUT_MinMaxC2_maxc2_shift                                       (16)
#define  DM_ThreeDLUT_MinMaxC2_minc2_shift                                       (0)
#define  DM_ThreeDLUT_MinMaxC2_maxc2_mask                                        (0xFFFF0000)
#define  DM_ThreeDLUT_MinMaxC2_minc2_mask                                        (0x0000FFFF)
#define  DM_ThreeDLUT_MinMaxC2_maxc2(data)                                       (0xFFFF0000&((data)<<16))
#define  DM_ThreeDLUT_MinMaxC2_minc2(data)                                       (0x0000FFFF&(data))
#define  DM_ThreeDLUT_MinMaxC2_get_maxc2(data)                                   ((0xFFFF0000&(data))>>16)
#define  DM_ThreeDLUT_MinMaxC2_get_minc2(data)                                   (0x0000FFFF&(data))

#define  DM_ThreeDLUT_MinMaxC3                                                   0x1806B5EC
#define  DM_ThreeDLUT_MinMaxC3_reg_addr                                          "0xB806B5EC"
#define  DM_ThreeDLUT_MinMaxC3_reg                                               0xB806B5EC
#define  DM_ThreeDLUT_MinMaxC3_inst_addr                                         "0x003E"
#define  set_DM_ThreeDLUT_MinMaxC3_reg(data)                                     (*((volatile unsigned int*)DM_ThreeDLUT_MinMaxC3_reg)=data)
#define  get_DM_ThreeDLUT_MinMaxC3_reg                                           (*((volatile unsigned int*)DM_ThreeDLUT_MinMaxC3_reg))
#define  DM_ThreeDLUT_MinMaxC3_default_max_sel_shift                             (31)
#define  DM_ThreeDLUT_MinMaxC3_minc3_shift                                       (0)
#define  DM_ThreeDLUT_MinMaxC3_default_max_sel_mask                              (0x80000000)
#define  DM_ThreeDLUT_MinMaxC3_minc3_mask                                        (0x0000FFFF)
#define  DM_ThreeDLUT_MinMaxC3_default_max_sel(data)                             (0x80000000&((data)<<31))
#define  DM_ThreeDLUT_MinMaxC3_minc3(data)                                       (0x0000FFFF&(data))
#define  DM_ThreeDLUT_MinMaxC3_get_default_max_sel(data)                         ((0x80000000&(data))>>31)
#define  DM_ThreeDLUT_MinMaxC3_get_minc3(data)                                   (0x0000FFFF&(data))

#define  DM_ThreeDLUT_MinMaxInv1                                                 0x1806B5F0
#define  DM_ThreeDLUT_MinMaxInv1_reg_addr                                        "0xB806B5F0"
#define  DM_ThreeDLUT_MinMaxInv1_reg                                             0xB806B5F0
#define  DM_ThreeDLUT_MinMaxInv1_inst_addr                                       "0x003F"
#define  set_DM_ThreeDLUT_MinMaxInv1_reg(data)                                   (*((volatile unsigned int*)DM_ThreeDLUT_MinMaxInv1_reg)=data)
#define  get_DM_ThreeDLUT_MinMaxInv1_reg                                         (*((volatile unsigned int*)DM_ThreeDLUT_MinMaxInv1_reg))
#define  DM_ThreeDLUT_MinMaxInv1_idistc1inv_shift                                (0)
#define  DM_ThreeDLUT_MinMaxInv1_idistc1inv_mask                                 (0x000FFFFF)
#define  DM_ThreeDLUT_MinMaxInv1_idistc1inv(data)                                (0x000FFFFF&(data))
#define  DM_ThreeDLUT_MinMaxInv1_get_idistc1inv(data)                            (0x000FFFFF&(data))

#define  DM_ThreeDLUT_MinMaxInv2                                                 0x1806B5F4
#define  DM_ThreeDLUT_MinMaxInv2_reg_addr                                        "0xB806B5F4"
#define  DM_ThreeDLUT_MinMaxInv2_reg                                             0xB806B5F4
#define  DM_ThreeDLUT_MinMaxInv2_inst_addr                                       "0x0040"
#define  set_DM_ThreeDLUT_MinMaxInv2_reg(data)                                   (*((volatile unsigned int*)DM_ThreeDLUT_MinMaxInv2_reg)=data)
#define  get_DM_ThreeDLUT_MinMaxInv2_reg                                         (*((volatile unsigned int*)DM_ThreeDLUT_MinMaxInv2_reg))
#define  DM_ThreeDLUT_MinMaxInv2_idistc2inv_shift                                (0)
#define  DM_ThreeDLUT_MinMaxInv2_idistc2inv_mask                                 (0x000FFFFF)
#define  DM_ThreeDLUT_MinMaxInv2_idistc2inv(data)                                (0x000FFFFF&(data))
#define  DM_ThreeDLUT_MinMaxInv2_get_idistc2inv(data)                            (0x000FFFFF&(data))

#define  DM_ThreeDLUT_MinMaxInv3                                                 0x1806B5F8
#define  DM_ThreeDLUT_MinMaxInv3_reg_addr                                        "0xB806B5F8"
#define  DM_ThreeDLUT_MinMaxInv3_reg                                             0xB806B5F8
#define  DM_ThreeDLUT_MinMaxInv3_inst_addr                                       "0x0041"
#define  set_DM_ThreeDLUT_MinMaxInv3_reg(data)                                   (*((volatile unsigned int*)DM_ThreeDLUT_MinMaxInv3_reg)=data)
#define  get_DM_ThreeDLUT_MinMaxInv3_reg                                         (*((volatile unsigned int*)DM_ThreeDLUT_MinMaxInv3_reg))
#define  DM_ThreeDLUT_MinMaxInv3_idistc3inv_shift                                (0)
#define  DM_ThreeDLUT_MinMaxInv3_idistc3inv_mask                                 (0x000FFFFF)
#define  DM_ThreeDLUT_MinMaxInv3_idistc3inv(data)                                (0x000FFFFF&(data))
#define  DM_ThreeDLUT_MinMaxInv3_get_idistc3inv(data)                            (0x000FFFFF&(data))

#define  DM_DM_B05_LUT_CTRL0                                                     0x1806B5FC
#define  DM_DM_B05_LUT_CTRL0_reg_addr                                            "0xB806B5FC"
#define  DM_DM_B05_LUT_CTRL0_reg                                                 0xB806B5FC
#define  DM_DM_B05_LUT_CTRL0_inst_addr                                           "0x0042"
#define  set_DM_DM_B05_LUT_CTRL0_reg(data)                                       (*((volatile unsigned int*)DM_DM_B05_LUT_CTRL0_reg)=data)
#define  get_DM_DM_B05_LUT_CTRL0_reg                                             (*((volatile unsigned int*)DM_DM_B05_LUT_CTRL0_reg))
#define  DM_DM_B05_LUT_CTRL0_lut_b05_rw_sel_shift                                (29)
#define  DM_DM_B05_LUT_CTRL0_lut_b05_write_en_shift                              (28)
#define  DM_DM_B05_LUT_CTRL0_lut_b05_read_en_shift                               (27)
#define  DM_DM_B05_LUT_CTRL0_lut_b05_rw_adr_shift                                (0)
#define  DM_DM_B05_LUT_CTRL0_lut_b05_rw_sel_mask                                 (0x60000000)
#define  DM_DM_B05_LUT_CTRL0_lut_b05_write_en_mask                               (0x10000000)
#define  DM_DM_B05_LUT_CTRL0_lut_b05_read_en_mask                                (0x08000000)
#define  DM_DM_B05_LUT_CTRL0_lut_b05_rw_adr_mask                                 (0x000003FF)
#define  DM_DM_B05_LUT_CTRL0_lut_b05_rw_sel(data)                                (0x60000000&((data)<<29))
#define  DM_DM_B05_LUT_CTRL0_lut_b05_write_en(data)                              (0x10000000&((data)<<28))
#define  DM_DM_B05_LUT_CTRL0_lut_b05_read_en(data)                               (0x08000000&((data)<<27))
#define  DM_DM_B05_LUT_CTRL0_lut_b05_rw_adr(data)                                (0x000003FF&(data))
#define  DM_DM_B05_LUT_CTRL0_get_lut_b05_rw_sel(data)                            ((0x60000000&(data))>>29)
#define  DM_DM_B05_LUT_CTRL0_get_lut_b05_write_en(data)                          ((0x10000000&(data))>>28)
#define  DM_DM_B05_LUT_CTRL0_get_lut_b05_read_en(data)                           ((0x08000000&(data))>>27)
#define  DM_DM_B05_LUT_CTRL0_get_lut_b05_rw_adr(data)                            (0x000003FF&(data))

#define  DM_DM_B05_LUT_WR_DATA_1                                                 0x1806B600
#define  DM_DM_B05_LUT_WR_DATA_1_reg_addr                                        "0xB806B600"
#define  DM_DM_B05_LUT_WR_DATA_1_reg                                             0xB806B600
#define  DM_DM_B05_LUT_WR_DATA_1_inst_addr                                       "0x0043"
#define  set_DM_DM_B05_LUT_WR_DATA_1_reg(data)                                   (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_1_reg)=data)
#define  get_DM_DM_B05_LUT_WR_DATA_1_reg                                         (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_1_reg))
#define  DM_DM_B05_LUT_WR_DATA_1_lut_wr_data_d0_1_shift                          (16)
#define  DM_DM_B05_LUT_WR_DATA_1_lut_wr_data_d1_1_shift                          (0)
#define  DM_DM_B05_LUT_WR_DATA_1_lut_wr_data_d0_1_mask                           (0xFFFF0000)
#define  DM_DM_B05_LUT_WR_DATA_1_lut_wr_data_d1_1_mask                           (0x0000FFFF)
#define  DM_DM_B05_LUT_WR_DATA_1_lut_wr_data_d0_1(data)                          (0xFFFF0000&((data)<<16))
#define  DM_DM_B05_LUT_WR_DATA_1_lut_wr_data_d1_1(data)                          (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_WR_DATA_1_get_lut_wr_data_d0_1(data)                      ((0xFFFF0000&(data))>>16)
#define  DM_DM_B05_LUT_WR_DATA_1_get_lut_wr_data_d1_1(data)                      (0x0000FFFF&(data))

#define  DM_DM_B05_LUT_WR_DATA_2                                                 0x1806B604
#define  DM_DM_B05_LUT_WR_DATA_2_reg_addr                                        "0xB806B604"
#define  DM_DM_B05_LUT_WR_DATA_2_reg                                             0xB806B604
#define  DM_DM_B05_LUT_WR_DATA_2_inst_addr                                       "0x0044"
#define  set_DM_DM_B05_LUT_WR_DATA_2_reg(data)                                   (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_2_reg)=data)
#define  get_DM_DM_B05_LUT_WR_DATA_2_reg                                         (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_2_reg))
#define  DM_DM_B05_LUT_WR_DATA_2_lut_wr_data_d2_1_shift                          (0)
#define  DM_DM_B05_LUT_WR_DATA_2_lut_wr_data_d2_1_mask                           (0x0000FFFF)
#define  DM_DM_B05_LUT_WR_DATA_2_lut_wr_data_d2_1(data)                          (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_WR_DATA_2_get_lut_wr_data_d2_1(data)                      (0x0000FFFF&(data))

#define  DM_DM_B05_LUT_WR_DATA_3                                                 0x1806B608
#define  DM_DM_B05_LUT_WR_DATA_3_reg_addr                                        "0xB806B608"
#define  DM_DM_B05_LUT_WR_DATA_3_reg                                             0xB806B608
#define  DM_DM_B05_LUT_WR_DATA_3_inst_addr                                       "0x0045"
#define  set_DM_DM_B05_LUT_WR_DATA_3_reg(data)                                   (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_3_reg)=data)
#define  get_DM_DM_B05_LUT_WR_DATA_3_reg                                         (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_3_reg))
#define  DM_DM_B05_LUT_WR_DATA_3_lut_wr_data_d0_2_shift                          (16)
#define  DM_DM_B05_LUT_WR_DATA_3_lut_wr_data_d1_2_shift                          (0)
#define  DM_DM_B05_LUT_WR_DATA_3_lut_wr_data_d0_2_mask                           (0xFFFF0000)
#define  DM_DM_B05_LUT_WR_DATA_3_lut_wr_data_d1_2_mask                           (0x0000FFFF)
#define  DM_DM_B05_LUT_WR_DATA_3_lut_wr_data_d0_2(data)                          (0xFFFF0000&((data)<<16))
#define  DM_DM_B05_LUT_WR_DATA_3_lut_wr_data_d1_2(data)                          (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_WR_DATA_3_get_lut_wr_data_d0_2(data)                      ((0xFFFF0000&(data))>>16)
#define  DM_DM_B05_LUT_WR_DATA_3_get_lut_wr_data_d1_2(data)                      (0x0000FFFF&(data))

#define  DM_DM_B05_LUT_WR_DATA_4                                                 0x1806B60C
#define  DM_DM_B05_LUT_WR_DATA_4_reg_addr                                        "0xB806B60C"
#define  DM_DM_B05_LUT_WR_DATA_4_reg                                             0xB806B60C
#define  DM_DM_B05_LUT_WR_DATA_4_inst_addr                                       "0x0046"
#define  set_DM_DM_B05_LUT_WR_DATA_4_reg(data)                                   (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_4_reg)=data)
#define  get_DM_DM_B05_LUT_WR_DATA_4_reg                                         (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_4_reg))
#define  DM_DM_B05_LUT_WR_DATA_4_lut_wr_data_d2_2_shift                          (0)
#define  DM_DM_B05_LUT_WR_DATA_4_lut_wr_data_d2_2_mask                           (0x0000FFFF)
#define  DM_DM_B05_LUT_WR_DATA_4_lut_wr_data_d2_2(data)                          (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_WR_DATA_4_get_lut_wr_data_d2_2(data)                      (0x0000FFFF&(data))

#define  DM_DM_B05_LUT_WR_DATA_5                                                 0x1806B610
#define  DM_DM_B05_LUT_WR_DATA_5_reg_addr                                        "0xB806B610"
#define  DM_DM_B05_LUT_WR_DATA_5_reg                                             0xB806B610
#define  DM_DM_B05_LUT_WR_DATA_5_inst_addr                                       "0x0047"
#define  set_DM_DM_B05_LUT_WR_DATA_5_reg(data)                                   (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_5_reg)=data)
#define  get_DM_DM_B05_LUT_WR_DATA_5_reg                                         (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_5_reg))
#define  DM_DM_B05_LUT_WR_DATA_5_lut_wr_data_d0_3_shift                          (16)
#define  DM_DM_B05_LUT_WR_DATA_5_lut_wr_data_d1_3_shift                          (0)
#define  DM_DM_B05_LUT_WR_DATA_5_lut_wr_data_d0_3_mask                           (0xFFFF0000)
#define  DM_DM_B05_LUT_WR_DATA_5_lut_wr_data_d1_3_mask                           (0x0000FFFF)
#define  DM_DM_B05_LUT_WR_DATA_5_lut_wr_data_d0_3(data)                          (0xFFFF0000&((data)<<16))
#define  DM_DM_B05_LUT_WR_DATA_5_lut_wr_data_d1_3(data)                          (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_WR_DATA_5_get_lut_wr_data_d0_3(data)                      ((0xFFFF0000&(data))>>16)
#define  DM_DM_B05_LUT_WR_DATA_5_get_lut_wr_data_d1_3(data)                      (0x0000FFFF&(data))

#define  DM_DM_B05_LUT_WR_DATA_6                                                 0x1806B614
#define  DM_DM_B05_LUT_WR_DATA_6_reg_addr                                        "0xB806B614"
#define  DM_DM_B05_LUT_WR_DATA_6_reg                                             0xB806B614
#define  DM_DM_B05_LUT_WR_DATA_6_inst_addr                                       "0x0048"
#define  set_DM_DM_B05_LUT_WR_DATA_6_reg(data)                                   (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_6_reg)=data)
#define  get_DM_DM_B05_LUT_WR_DATA_6_reg                                         (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_6_reg))
#define  DM_DM_B05_LUT_WR_DATA_6_lut_wr_data_d2_3_shift                          (0)
#define  DM_DM_B05_LUT_WR_DATA_6_lut_wr_data_d2_3_mask                           (0x0000FFFF)
#define  DM_DM_B05_LUT_WR_DATA_6_lut_wr_data_d2_3(data)                          (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_WR_DATA_6_get_lut_wr_data_d2_3(data)                      (0x0000FFFF&(data))

#define  DM_DM_B05_LUT_WR_DATA_7                                                 0x1806B618
#define  DM_DM_B05_LUT_WR_DATA_7_reg_addr                                        "0xB806B618"
#define  DM_DM_B05_LUT_WR_DATA_7_reg                                             0xB806B618
#define  DM_DM_B05_LUT_WR_DATA_7_inst_addr                                       "0x0049"
#define  set_DM_DM_B05_LUT_WR_DATA_7_reg(data)                                   (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_7_reg)=data)
#define  get_DM_DM_B05_LUT_WR_DATA_7_reg                                         (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_7_reg))
#define  DM_DM_B05_LUT_WR_DATA_7_lut_wr_data_d0_4_shift                          (16)
#define  DM_DM_B05_LUT_WR_DATA_7_lut_wr_data_d1_4_shift                          (0)
#define  DM_DM_B05_LUT_WR_DATA_7_lut_wr_data_d0_4_mask                           (0xFFFF0000)
#define  DM_DM_B05_LUT_WR_DATA_7_lut_wr_data_d1_4_mask                           (0x0000FFFF)
#define  DM_DM_B05_LUT_WR_DATA_7_lut_wr_data_d0_4(data)                          (0xFFFF0000&((data)<<16))
#define  DM_DM_B05_LUT_WR_DATA_7_lut_wr_data_d1_4(data)                          (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_WR_DATA_7_get_lut_wr_data_d0_4(data)                      ((0xFFFF0000&(data))>>16)
#define  DM_DM_B05_LUT_WR_DATA_7_get_lut_wr_data_d1_4(data)                      (0x0000FFFF&(data))

#define  DM_DM_B05_LUT_WR_DATA_8                                                 0x1806B61C
#define  DM_DM_B05_LUT_WR_DATA_8_reg_addr                                        "0xB806B61C"
#define  DM_DM_B05_LUT_WR_DATA_8_reg                                             0xB806B61C
#define  DM_DM_B05_LUT_WR_DATA_8_inst_addr                                       "0x004A"
#define  set_DM_DM_B05_LUT_WR_DATA_8_reg(data)                                   (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_8_reg)=data)
#define  get_DM_DM_B05_LUT_WR_DATA_8_reg                                         (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_8_reg))
#define  DM_DM_B05_LUT_WR_DATA_8_lut_wr_data_d2_4_shift                          (0)
#define  DM_DM_B05_LUT_WR_DATA_8_lut_wr_data_d2_4_mask                           (0x0000FFFF)
#define  DM_DM_B05_LUT_WR_DATA_8_lut_wr_data_d2_4(data)                          (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_WR_DATA_8_get_lut_wr_data_d2_4(data)                      (0x0000FFFF&(data))

#define  DM_DM_B05_LUT_WR_DATA_9                                                 0x1806B620
#define  DM_DM_B05_LUT_WR_DATA_9_reg_addr                                        "0xB806B620"
#define  DM_DM_B05_LUT_WR_DATA_9_reg                                             0xB806B620
#define  DM_DM_B05_LUT_WR_DATA_9_inst_addr                                       "0x004B"
#define  set_DM_DM_B05_LUT_WR_DATA_9_reg(data)                                   (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_9_reg)=data)
#define  get_DM_DM_B05_LUT_WR_DATA_9_reg                                         (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_9_reg))
#define  DM_DM_B05_LUT_WR_DATA_9_lut_wr_data_d0_5_shift                          (16)
#define  DM_DM_B05_LUT_WR_DATA_9_lut_wr_data_d1_5_shift                          (0)
#define  DM_DM_B05_LUT_WR_DATA_9_lut_wr_data_d0_5_mask                           (0xFFFF0000)
#define  DM_DM_B05_LUT_WR_DATA_9_lut_wr_data_d1_5_mask                           (0x0000FFFF)
#define  DM_DM_B05_LUT_WR_DATA_9_lut_wr_data_d0_5(data)                          (0xFFFF0000&((data)<<16))
#define  DM_DM_B05_LUT_WR_DATA_9_lut_wr_data_d1_5(data)                          (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_WR_DATA_9_get_lut_wr_data_d0_5(data)                      ((0xFFFF0000&(data))>>16)
#define  DM_DM_B05_LUT_WR_DATA_9_get_lut_wr_data_d1_5(data)                      (0x0000FFFF&(data))

#define  DM_DM_B05_LUT_WR_DATA_10                                                0x1806B624
#define  DM_DM_B05_LUT_WR_DATA_10_reg_addr                                       "0xB806B624"
#define  DM_DM_B05_LUT_WR_DATA_10_reg                                            0xB806B624
#define  DM_DM_B05_LUT_WR_DATA_10_inst_addr                                      "0x004C"
#define  set_DM_DM_B05_LUT_WR_DATA_10_reg(data)                                  (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_10_reg)=data)
#define  get_DM_DM_B05_LUT_WR_DATA_10_reg                                        (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_10_reg))
#define  DM_DM_B05_LUT_WR_DATA_10_lut_wr_data_d2_5_shift                         (0)
#define  DM_DM_B05_LUT_WR_DATA_10_lut_wr_data_d2_5_mask                          (0x0000FFFF)
#define  DM_DM_B05_LUT_WR_DATA_10_lut_wr_data_d2_5(data)                         (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_WR_DATA_10_get_lut_wr_data_d2_5(data)                     (0x0000FFFF&(data))

#define  DM_DM_B05_LUT_WR_DATA_11                                                0x1806B628
#define  DM_DM_B05_LUT_WR_DATA_11_reg_addr                                       "0xB806B628"
#define  DM_DM_B05_LUT_WR_DATA_11_reg                                            0xB806B628
#define  DM_DM_B05_LUT_WR_DATA_11_inst_addr                                      "0x004D"
#define  set_DM_DM_B05_LUT_WR_DATA_11_reg(data)                                  (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_11_reg)=data)
#define  get_DM_DM_B05_LUT_WR_DATA_11_reg                                        (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_11_reg))
#define  DM_DM_B05_LUT_WR_DATA_11_lut_wr_data_d0_6_shift                         (16)
#define  DM_DM_B05_LUT_WR_DATA_11_lut_wr_data_d1_6_shift                         (0)
#define  DM_DM_B05_LUT_WR_DATA_11_lut_wr_data_d0_6_mask                          (0xFFFF0000)
#define  DM_DM_B05_LUT_WR_DATA_11_lut_wr_data_d1_6_mask                          (0x0000FFFF)
#define  DM_DM_B05_LUT_WR_DATA_11_lut_wr_data_d0_6(data)                         (0xFFFF0000&((data)<<16))
#define  DM_DM_B05_LUT_WR_DATA_11_lut_wr_data_d1_6(data)                         (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_WR_DATA_11_get_lut_wr_data_d0_6(data)                     ((0xFFFF0000&(data))>>16)
#define  DM_DM_B05_LUT_WR_DATA_11_get_lut_wr_data_d1_6(data)                     (0x0000FFFF&(data))

#define  DM_DM_B05_LUT_WR_DATA_12                                                0x1806B62C
#define  DM_DM_B05_LUT_WR_DATA_12_reg_addr                                       "0xB806B62C"
#define  DM_DM_B05_LUT_WR_DATA_12_reg                                            0xB806B62C
#define  DM_DM_B05_LUT_WR_DATA_12_inst_addr                                      "0x004E"
#define  set_DM_DM_B05_LUT_WR_DATA_12_reg(data)                                  (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_12_reg)=data)
#define  get_DM_DM_B05_LUT_WR_DATA_12_reg                                        (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_12_reg))
#define  DM_DM_B05_LUT_WR_DATA_12_lut_wr_data_d2_6_shift                         (0)
#define  DM_DM_B05_LUT_WR_DATA_12_lut_wr_data_d2_6_mask                          (0x0000FFFF)
#define  DM_DM_B05_LUT_WR_DATA_12_lut_wr_data_d2_6(data)                         (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_WR_DATA_12_get_lut_wr_data_d2_6(data)                     (0x0000FFFF&(data))

#define  DM_DM_B05_LUT_WR_DATA_13                                                0x1806B630
#define  DM_DM_B05_LUT_WR_DATA_13_reg_addr                                       "0xB806B630"
#define  DM_DM_B05_LUT_WR_DATA_13_reg                                            0xB806B630
#define  DM_DM_B05_LUT_WR_DATA_13_inst_addr                                      "0x004F"
#define  set_DM_DM_B05_LUT_WR_DATA_13_reg(data)                                  (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_13_reg)=data)
#define  get_DM_DM_B05_LUT_WR_DATA_13_reg                                        (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_13_reg))
#define  DM_DM_B05_LUT_WR_DATA_13_lut_wr_data_d0_7_shift                         (16)
#define  DM_DM_B05_LUT_WR_DATA_13_lut_wr_data_d1_7_shift                         (0)
#define  DM_DM_B05_LUT_WR_DATA_13_lut_wr_data_d0_7_mask                          (0xFFFF0000)
#define  DM_DM_B05_LUT_WR_DATA_13_lut_wr_data_d1_7_mask                          (0x0000FFFF)
#define  DM_DM_B05_LUT_WR_DATA_13_lut_wr_data_d0_7(data)                         (0xFFFF0000&((data)<<16))
#define  DM_DM_B05_LUT_WR_DATA_13_lut_wr_data_d1_7(data)                         (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_WR_DATA_13_get_lut_wr_data_d0_7(data)                     ((0xFFFF0000&(data))>>16)
#define  DM_DM_B05_LUT_WR_DATA_13_get_lut_wr_data_d1_7(data)                     (0x0000FFFF&(data))

#define  DM_DM_B05_LUT_WR_DATA_14                                                0x1806B634
#define  DM_DM_B05_LUT_WR_DATA_14_reg_addr                                       "0xB806B634"
#define  DM_DM_B05_LUT_WR_DATA_14_reg                                            0xB806B634
#define  DM_DM_B05_LUT_WR_DATA_14_inst_addr                                      "0x0050"
#define  set_DM_DM_B05_LUT_WR_DATA_14_reg(data)                                  (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_14_reg)=data)
#define  get_DM_DM_B05_LUT_WR_DATA_14_reg                                        (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_14_reg))
#define  DM_DM_B05_LUT_WR_DATA_14_lut_wr_data_d2_7_shift                         (0)
#define  DM_DM_B05_LUT_WR_DATA_14_lut_wr_data_d2_7_mask                          (0x0000FFFF)
#define  DM_DM_B05_LUT_WR_DATA_14_lut_wr_data_d2_7(data)                         (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_WR_DATA_14_get_lut_wr_data_d2_7(data)                     (0x0000FFFF&(data))

#define  DM_DM_B05_LUT_WR_DATA_15                                                0x1806B638
#define  DM_DM_B05_LUT_WR_DATA_15_reg_addr                                       "0xB806B638"
#define  DM_DM_B05_LUT_WR_DATA_15_reg                                            0xB806B638
#define  DM_DM_B05_LUT_WR_DATA_15_inst_addr                                      "0x0051"
#define  set_DM_DM_B05_LUT_WR_DATA_15_reg(data)                                  (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_15_reg)=data)
#define  get_DM_DM_B05_LUT_WR_DATA_15_reg                                        (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_15_reg))
#define  DM_DM_B05_LUT_WR_DATA_15_lut_wr_data_d0_8_shift                         (16)
#define  DM_DM_B05_LUT_WR_DATA_15_lut_wr_data_d1_8_shift                         (0)
#define  DM_DM_B05_LUT_WR_DATA_15_lut_wr_data_d0_8_mask                          (0xFFFF0000)
#define  DM_DM_B05_LUT_WR_DATA_15_lut_wr_data_d1_8_mask                          (0x0000FFFF)
#define  DM_DM_B05_LUT_WR_DATA_15_lut_wr_data_d0_8(data)                         (0xFFFF0000&((data)<<16))
#define  DM_DM_B05_LUT_WR_DATA_15_lut_wr_data_d1_8(data)                         (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_WR_DATA_15_get_lut_wr_data_d0_8(data)                     ((0xFFFF0000&(data))>>16)
#define  DM_DM_B05_LUT_WR_DATA_15_get_lut_wr_data_d1_8(data)                     (0x0000FFFF&(data))

#define  DM_DM_B05_LUT_WR_DATA_16                                                0x1806B63C
#define  DM_DM_B05_LUT_WR_DATA_16_reg_addr                                       "0xB806B63C"
#define  DM_DM_B05_LUT_WR_DATA_16_reg                                            0xB806B63C
#define  DM_DM_B05_LUT_WR_DATA_16_inst_addr                                      "0x0052"
#define  set_DM_DM_B05_LUT_WR_DATA_16_reg(data)                                  (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_16_reg)=data)
#define  get_DM_DM_B05_LUT_WR_DATA_16_reg                                        (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_16_reg))
#define  DM_DM_B05_LUT_WR_DATA_16_lut_wr_data_d2_8_shift                         (0)
#define  DM_DM_B05_LUT_WR_DATA_16_lut_wr_data_d2_8_mask                          (0x0000FFFF)
#define  DM_DM_B05_LUT_WR_DATA_16_lut_wr_data_d2_8(data)                         (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_WR_DATA_16_get_lut_wr_data_d2_8(data)                     (0x0000FFFF&(data))

#define  DM_DM_B05_LUT_WR_DATA_17                                                0x1806B640
#define  DM_DM_B05_LUT_WR_DATA_17_reg_addr                                       "0xB806B640"
#define  DM_DM_B05_LUT_WR_DATA_17_reg                                            0xB806B640
#define  DM_DM_B05_LUT_WR_DATA_17_inst_addr                                      "0x0053"
#define  set_DM_DM_B05_LUT_WR_DATA_17_reg(data)                                  (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_17_reg)=data)
#define  get_DM_DM_B05_LUT_WR_DATA_17_reg                                        (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_17_reg))
#define  DM_DM_B05_LUT_WR_DATA_17_lut_wr_data_d0_9_shift                         (16)
#define  DM_DM_B05_LUT_WR_DATA_17_lut_wr_data_d1_9_shift                         (0)
#define  DM_DM_B05_LUT_WR_DATA_17_lut_wr_data_d0_9_mask                          (0xFFFF0000)
#define  DM_DM_B05_LUT_WR_DATA_17_lut_wr_data_d1_9_mask                          (0x0000FFFF)
#define  DM_DM_B05_LUT_WR_DATA_17_lut_wr_data_d0_9(data)                         (0xFFFF0000&((data)<<16))
#define  DM_DM_B05_LUT_WR_DATA_17_lut_wr_data_d1_9(data)                         (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_WR_DATA_17_get_lut_wr_data_d0_9(data)                     ((0xFFFF0000&(data))>>16)
#define  DM_DM_B05_LUT_WR_DATA_17_get_lut_wr_data_d1_9(data)                     (0x0000FFFF&(data))

#define  DM_DM_B05_LUT_WR_DATA_18                                                0x1806B644
#define  DM_DM_B05_LUT_WR_DATA_18_reg_addr                                       "0xB806B644"
#define  DM_DM_B05_LUT_WR_DATA_18_reg                                            0xB806B644
#define  DM_DM_B05_LUT_WR_DATA_18_inst_addr                                      "0x0054"
#define  set_DM_DM_B05_LUT_WR_DATA_18_reg(data)                                  (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_18_reg)=data)
#define  get_DM_DM_B05_LUT_WR_DATA_18_reg                                        (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_18_reg))
#define  DM_DM_B05_LUT_WR_DATA_18_lut_wr_data_d2_9_shift                         (0)
#define  DM_DM_B05_LUT_WR_DATA_18_lut_wr_data_d2_9_mask                          (0x0000FFFF)
#define  DM_DM_B05_LUT_WR_DATA_18_lut_wr_data_d2_9(data)                         (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_WR_DATA_18_get_lut_wr_data_d2_9(data)                     (0x0000FFFF&(data))

#define  DM_DM_B05_LUT_WR_DATA_19                                                0x1806B648
#define  DM_DM_B05_LUT_WR_DATA_19_reg_addr                                       "0xB806B648"
#define  DM_DM_B05_LUT_WR_DATA_19_reg                                            0xB806B648
#define  DM_DM_B05_LUT_WR_DATA_19_inst_addr                                      "0x0055"
#define  set_DM_DM_B05_LUT_WR_DATA_19_reg(data)                                  (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_19_reg)=data)
#define  get_DM_DM_B05_LUT_WR_DATA_19_reg                                        (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_19_reg))
#define  DM_DM_B05_LUT_WR_DATA_19_lut_wr_data_d0_10_shift                        (16)
#define  DM_DM_B05_LUT_WR_DATA_19_lut_wr_data_d1_10_shift                        (0)
#define  DM_DM_B05_LUT_WR_DATA_19_lut_wr_data_d0_10_mask                         (0xFFFF0000)
#define  DM_DM_B05_LUT_WR_DATA_19_lut_wr_data_d1_10_mask                         (0x0000FFFF)
#define  DM_DM_B05_LUT_WR_DATA_19_lut_wr_data_d0_10(data)                        (0xFFFF0000&((data)<<16))
#define  DM_DM_B05_LUT_WR_DATA_19_lut_wr_data_d1_10(data)                        (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_WR_DATA_19_get_lut_wr_data_d0_10(data)                    ((0xFFFF0000&(data))>>16)
#define  DM_DM_B05_LUT_WR_DATA_19_get_lut_wr_data_d1_10(data)                    (0x0000FFFF&(data))

#define  DM_DM_B05_LUT_WR_DATA_20                                                0x1806B64C
#define  DM_DM_B05_LUT_WR_DATA_20_reg_addr                                       "0xB806B64C"
#define  DM_DM_B05_LUT_WR_DATA_20_reg                                            0xB806B64C
#define  DM_DM_B05_LUT_WR_DATA_20_inst_addr                                      "0x0056"
#define  set_DM_DM_B05_LUT_WR_DATA_20_reg(data)                                  (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_20_reg)=data)
#define  get_DM_DM_B05_LUT_WR_DATA_20_reg                                        (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_20_reg))
#define  DM_DM_B05_LUT_WR_DATA_20_lut_wr_data_d2_10_shift                        (0)
#define  DM_DM_B05_LUT_WR_DATA_20_lut_wr_data_d2_10_mask                         (0x0000FFFF)
#define  DM_DM_B05_LUT_WR_DATA_20_lut_wr_data_d2_10(data)                        (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_WR_DATA_20_get_lut_wr_data_d2_10(data)                    (0x0000FFFF&(data))

#define  DM_DM_B05_LUT_WR_DATA_21                                                0x1806B650
#define  DM_DM_B05_LUT_WR_DATA_21_reg_addr                                       "0xB806B650"
#define  DM_DM_B05_LUT_WR_DATA_21_reg                                            0xB806B650
#define  DM_DM_B05_LUT_WR_DATA_21_inst_addr                                      "0x0057"
#define  set_DM_DM_B05_LUT_WR_DATA_21_reg(data)                                  (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_21_reg)=data)
#define  get_DM_DM_B05_LUT_WR_DATA_21_reg                                        (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_21_reg))
#define  DM_DM_B05_LUT_WR_DATA_21_lut_wr_data_d0_11_shift                        (16)
#define  DM_DM_B05_LUT_WR_DATA_21_lut_wr_data_d1_11_shift                        (0)
#define  DM_DM_B05_LUT_WR_DATA_21_lut_wr_data_d0_11_mask                         (0xFFFF0000)
#define  DM_DM_B05_LUT_WR_DATA_21_lut_wr_data_d1_11_mask                         (0x0000FFFF)
#define  DM_DM_B05_LUT_WR_DATA_21_lut_wr_data_d0_11(data)                        (0xFFFF0000&((data)<<16))
#define  DM_DM_B05_LUT_WR_DATA_21_lut_wr_data_d1_11(data)                        (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_WR_DATA_21_get_lut_wr_data_d0_11(data)                    ((0xFFFF0000&(data))>>16)
#define  DM_DM_B05_LUT_WR_DATA_21_get_lut_wr_data_d1_11(data)                    (0x0000FFFF&(data))

#define  DM_DM_B05_LUT_WR_DATA_22                                                0x1806B654
#define  DM_DM_B05_LUT_WR_DATA_22_reg_addr                                       "0xB806B654"
#define  DM_DM_B05_LUT_WR_DATA_22_reg                                            0xB806B654
#define  DM_DM_B05_LUT_WR_DATA_22_inst_addr                                      "0x0058"
#define  set_DM_DM_B05_LUT_WR_DATA_22_reg(data)                                  (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_22_reg)=data)
#define  get_DM_DM_B05_LUT_WR_DATA_22_reg                                        (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_22_reg))
#define  DM_DM_B05_LUT_WR_DATA_22_lut_wr_data_d2_11_shift                        (0)
#define  DM_DM_B05_LUT_WR_DATA_22_lut_wr_data_d2_11_mask                         (0x0000FFFF)
#define  DM_DM_B05_LUT_WR_DATA_22_lut_wr_data_d2_11(data)                        (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_WR_DATA_22_get_lut_wr_data_d2_11(data)                    (0x0000FFFF&(data))

#define  DM_DM_B05_LUT_WR_DATA_23                                                0x1806B658
#define  DM_DM_B05_LUT_WR_DATA_23_reg_addr                                       "0xB806B658"
#define  DM_DM_B05_LUT_WR_DATA_23_reg                                            0xB806B658
#define  DM_DM_B05_LUT_WR_DATA_23_inst_addr                                      "0x0059"
#define  set_DM_DM_B05_LUT_WR_DATA_23_reg(data)                                  (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_23_reg)=data)
#define  get_DM_DM_B05_LUT_WR_DATA_23_reg                                        (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_23_reg))
#define  DM_DM_B05_LUT_WR_DATA_23_lut_wr_data_d0_12_shift                        (16)
#define  DM_DM_B05_LUT_WR_DATA_23_lut_wr_data_d1_12_shift                        (0)
#define  DM_DM_B05_LUT_WR_DATA_23_lut_wr_data_d0_12_mask                         (0xFFFF0000)
#define  DM_DM_B05_LUT_WR_DATA_23_lut_wr_data_d1_12_mask                         (0x0000FFFF)
#define  DM_DM_B05_LUT_WR_DATA_23_lut_wr_data_d0_12(data)                        (0xFFFF0000&((data)<<16))
#define  DM_DM_B05_LUT_WR_DATA_23_lut_wr_data_d1_12(data)                        (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_WR_DATA_23_get_lut_wr_data_d0_12(data)                    ((0xFFFF0000&(data))>>16)
#define  DM_DM_B05_LUT_WR_DATA_23_get_lut_wr_data_d1_12(data)                    (0x0000FFFF&(data))

#define  DM_DM_B05_LUT_WR_DATA_24                                                0x1806B65C
#define  DM_DM_B05_LUT_WR_DATA_24_reg_addr                                       "0xB806B65C"
#define  DM_DM_B05_LUT_WR_DATA_24_reg                                            0xB806B65C
#define  DM_DM_B05_LUT_WR_DATA_24_inst_addr                                      "0x005A"
#define  set_DM_DM_B05_LUT_WR_DATA_24_reg(data)                                  (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_24_reg)=data)
#define  get_DM_DM_B05_LUT_WR_DATA_24_reg                                        (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_24_reg))
#define  DM_DM_B05_LUT_WR_DATA_24_lut_wr_data_d2_12_shift                        (0)
#define  DM_DM_B05_LUT_WR_DATA_24_lut_wr_data_d2_12_mask                         (0x0000FFFF)
#define  DM_DM_B05_LUT_WR_DATA_24_lut_wr_data_d2_12(data)                        (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_WR_DATA_24_get_lut_wr_data_d2_12(data)                    (0x0000FFFF&(data))

#define  DM_DM_B05_LUT_WR_DATA_25                                                0x1806B660
#define  DM_DM_B05_LUT_WR_DATA_25_reg_addr                                       "0xB806B660"
#define  DM_DM_B05_LUT_WR_DATA_25_reg                                            0xB806B660
#define  DM_DM_B05_LUT_WR_DATA_25_inst_addr                                      "0x005B"
#define  set_DM_DM_B05_LUT_WR_DATA_25_reg(data)                                  (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_25_reg)=data)
#define  get_DM_DM_B05_LUT_WR_DATA_25_reg                                        (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_25_reg))
#define  DM_DM_B05_LUT_WR_DATA_25_lut_wr_data_d0_13_shift                        (16)
#define  DM_DM_B05_LUT_WR_DATA_25_lut_wr_data_d1_13_shift                        (0)
#define  DM_DM_B05_LUT_WR_DATA_25_lut_wr_data_d0_13_mask                         (0xFFFF0000)
#define  DM_DM_B05_LUT_WR_DATA_25_lut_wr_data_d1_13_mask                         (0x0000FFFF)
#define  DM_DM_B05_LUT_WR_DATA_25_lut_wr_data_d0_13(data)                        (0xFFFF0000&((data)<<16))
#define  DM_DM_B05_LUT_WR_DATA_25_lut_wr_data_d1_13(data)                        (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_WR_DATA_25_get_lut_wr_data_d0_13(data)                    ((0xFFFF0000&(data))>>16)
#define  DM_DM_B05_LUT_WR_DATA_25_get_lut_wr_data_d1_13(data)                    (0x0000FFFF&(data))

#define  DM_DM_B05_LUT_WR_DATA_26                                                0x1806B664
#define  DM_DM_B05_LUT_WR_DATA_26_reg_addr                                       "0xB806B664"
#define  DM_DM_B05_LUT_WR_DATA_26_reg                                            0xB806B664
#define  DM_DM_B05_LUT_WR_DATA_26_inst_addr                                      "0x005C"
#define  set_DM_DM_B05_LUT_WR_DATA_26_reg(data)                                  (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_26_reg)=data)
#define  get_DM_DM_B05_LUT_WR_DATA_26_reg                                        (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_26_reg))
#define  DM_DM_B05_LUT_WR_DATA_26_lut_wr_data_d2_13_shift                        (0)
#define  DM_DM_B05_LUT_WR_DATA_26_lut_wr_data_d2_13_mask                         (0x0000FFFF)
#define  DM_DM_B05_LUT_WR_DATA_26_lut_wr_data_d2_13(data)                        (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_WR_DATA_26_get_lut_wr_data_d2_13(data)                    (0x0000FFFF&(data))

#define  DM_DM_B05_LUT_WR_DATA_27                                                0x1806B668
#define  DM_DM_B05_LUT_WR_DATA_27_reg_addr                                       "0xB806B668"
#define  DM_DM_B05_LUT_WR_DATA_27_reg                                            0xB806B668
#define  DM_DM_B05_LUT_WR_DATA_27_inst_addr                                      "0x005D"
#define  set_DM_DM_B05_LUT_WR_DATA_27_reg(data)                                  (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_27_reg)=data)
#define  get_DM_DM_B05_LUT_WR_DATA_27_reg                                        (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_27_reg))
#define  DM_DM_B05_LUT_WR_DATA_27_lut_wr_data_d0_14_shift                        (16)
#define  DM_DM_B05_LUT_WR_DATA_27_lut_wr_data_d1_14_shift                        (0)
#define  DM_DM_B05_LUT_WR_DATA_27_lut_wr_data_d0_14_mask                         (0xFFFF0000)
#define  DM_DM_B05_LUT_WR_DATA_27_lut_wr_data_d1_14_mask                         (0x0000FFFF)
#define  DM_DM_B05_LUT_WR_DATA_27_lut_wr_data_d0_14(data)                        (0xFFFF0000&((data)<<16))
#define  DM_DM_B05_LUT_WR_DATA_27_lut_wr_data_d1_14(data)                        (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_WR_DATA_27_get_lut_wr_data_d0_14(data)                    ((0xFFFF0000&(data))>>16)
#define  DM_DM_B05_LUT_WR_DATA_27_get_lut_wr_data_d1_14(data)                    (0x0000FFFF&(data))

#define  DM_DM_B05_LUT_WR_DATA_28                                                0x1806B66C
#define  DM_DM_B05_LUT_WR_DATA_28_reg_addr                                       "0xB806B66C"
#define  DM_DM_B05_LUT_WR_DATA_28_reg                                            0xB806B66C
#define  DM_DM_B05_LUT_WR_DATA_28_inst_addr                                      "0x005E"
#define  set_DM_DM_B05_LUT_WR_DATA_28_reg(data)                                  (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_28_reg)=data)
#define  get_DM_DM_B05_LUT_WR_DATA_28_reg                                        (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_28_reg))
#define  DM_DM_B05_LUT_WR_DATA_28_lut_wr_data_d2_14_shift                        (0)
#define  DM_DM_B05_LUT_WR_DATA_28_lut_wr_data_d2_14_mask                         (0x0000FFFF)
#define  DM_DM_B05_LUT_WR_DATA_28_lut_wr_data_d2_14(data)                        (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_WR_DATA_28_get_lut_wr_data_d2_14(data)                    (0x0000FFFF&(data))

#define  DM_DM_B05_LUT_WR_DATA_29                                                0x1806B670
#define  DM_DM_B05_LUT_WR_DATA_29_reg_addr                                       "0xB806B670"
#define  DM_DM_B05_LUT_WR_DATA_29_reg                                            0xB806B670
#define  DM_DM_B05_LUT_WR_DATA_29_inst_addr                                      "0x005F"
#define  set_DM_DM_B05_LUT_WR_DATA_29_reg(data)                                  (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_29_reg)=data)
#define  get_DM_DM_B05_LUT_WR_DATA_29_reg                                        (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_29_reg))
#define  DM_DM_B05_LUT_WR_DATA_29_lut_wr_data_d0_15_shift                        (16)
#define  DM_DM_B05_LUT_WR_DATA_29_lut_wr_data_d1_15_shift                        (0)
#define  DM_DM_B05_LUT_WR_DATA_29_lut_wr_data_d0_15_mask                         (0xFFFF0000)
#define  DM_DM_B05_LUT_WR_DATA_29_lut_wr_data_d1_15_mask                         (0x0000FFFF)
#define  DM_DM_B05_LUT_WR_DATA_29_lut_wr_data_d0_15(data)                        (0xFFFF0000&((data)<<16))
#define  DM_DM_B05_LUT_WR_DATA_29_lut_wr_data_d1_15(data)                        (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_WR_DATA_29_get_lut_wr_data_d0_15(data)                    ((0xFFFF0000&(data))>>16)
#define  DM_DM_B05_LUT_WR_DATA_29_get_lut_wr_data_d1_15(data)                    (0x0000FFFF&(data))

#define  DM_DM_B05_LUT_WR_DATA_30                                                0x1806B674
#define  DM_DM_B05_LUT_WR_DATA_30_reg_addr                                       "0xB806B674"
#define  DM_DM_B05_LUT_WR_DATA_30_reg                                            0xB806B674
#define  DM_DM_B05_LUT_WR_DATA_30_inst_addr                                      "0x0060"
#define  set_DM_DM_B05_LUT_WR_DATA_30_reg(data)                                  (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_30_reg)=data)
#define  get_DM_DM_B05_LUT_WR_DATA_30_reg                                        (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_30_reg))
#define  DM_DM_B05_LUT_WR_DATA_30_lut_wr_data_d2_15_shift                        (0)
#define  DM_DM_B05_LUT_WR_DATA_30_lut_wr_data_d2_15_mask                         (0x0000FFFF)
#define  DM_DM_B05_LUT_WR_DATA_30_lut_wr_data_d2_15(data)                        (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_WR_DATA_30_get_lut_wr_data_d2_15(data)                    (0x0000FFFF&(data))

#define  DM_DM_B05_LUT_WR_DATA_31                                                0x1806B678
#define  DM_DM_B05_LUT_WR_DATA_31_reg_addr                                       "0xB806B678"
#define  DM_DM_B05_LUT_WR_DATA_31_reg                                            0xB806B678
#define  DM_DM_B05_LUT_WR_DATA_31_inst_addr                                      "0x0061"
#define  set_DM_DM_B05_LUT_WR_DATA_31_reg(data)                                  (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_31_reg)=data)
#define  get_DM_DM_B05_LUT_WR_DATA_31_reg                                        (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_31_reg))
#define  DM_DM_B05_LUT_WR_DATA_31_lut_wr_data_d0_16_shift                        (16)
#define  DM_DM_B05_LUT_WR_DATA_31_lut_wr_data_d1_16_shift                        (0)
#define  DM_DM_B05_LUT_WR_DATA_31_lut_wr_data_d0_16_mask                         (0xFFFF0000)
#define  DM_DM_B05_LUT_WR_DATA_31_lut_wr_data_d1_16_mask                         (0x0000FFFF)
#define  DM_DM_B05_LUT_WR_DATA_31_lut_wr_data_d0_16(data)                        (0xFFFF0000&((data)<<16))
#define  DM_DM_B05_LUT_WR_DATA_31_lut_wr_data_d1_16(data)                        (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_WR_DATA_31_get_lut_wr_data_d0_16(data)                    ((0xFFFF0000&(data))>>16)
#define  DM_DM_B05_LUT_WR_DATA_31_get_lut_wr_data_d1_16(data)                    (0x0000FFFF&(data))

#define  DM_DM_B05_LUT_WR_DATA_32                                                0x1806B67C
#define  DM_DM_B05_LUT_WR_DATA_32_reg_addr                                       "0xB806B67C"
#define  DM_DM_B05_LUT_WR_DATA_32_reg                                            0xB806B67C
#define  DM_DM_B05_LUT_WR_DATA_32_inst_addr                                      "0x0062"
#define  set_DM_DM_B05_LUT_WR_DATA_32_reg(data)                                  (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_32_reg)=data)
#define  get_DM_DM_B05_LUT_WR_DATA_32_reg                                        (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_32_reg))
#define  DM_DM_B05_LUT_WR_DATA_32_lut_wr_data_d2_16_shift                        (0)
#define  DM_DM_B05_LUT_WR_DATA_32_lut_wr_data_d2_16_mask                         (0x0000FFFF)
#define  DM_DM_B05_LUT_WR_DATA_32_lut_wr_data_d2_16(data)                        (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_WR_DATA_32_get_lut_wr_data_d2_16(data)                    (0x0000FFFF&(data))

#define  DM_DM_B05_LUT_WR_DATA_33                                                0x1806B680
#define  DM_DM_B05_LUT_WR_DATA_33_reg_addr                                       "0xB806B680"
#define  DM_DM_B05_LUT_WR_DATA_33_reg                                            0xB806B680
#define  DM_DM_B05_LUT_WR_DATA_33_inst_addr                                      "0x0063"
#define  set_DM_DM_B05_LUT_WR_DATA_33_reg(data)                                  (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_33_reg)=data)
#define  get_DM_DM_B05_LUT_WR_DATA_33_reg                                        (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_33_reg))
#define  DM_DM_B05_LUT_WR_DATA_33_lut_wr_data_d0_17_shift                        (16)
#define  DM_DM_B05_LUT_WR_DATA_33_lut_wr_data_d1_17_shift                        (0)
#define  DM_DM_B05_LUT_WR_DATA_33_lut_wr_data_d0_17_mask                         (0xFFFF0000)
#define  DM_DM_B05_LUT_WR_DATA_33_lut_wr_data_d1_17_mask                         (0x0000FFFF)
#define  DM_DM_B05_LUT_WR_DATA_33_lut_wr_data_d0_17(data)                        (0xFFFF0000&((data)<<16))
#define  DM_DM_B05_LUT_WR_DATA_33_lut_wr_data_d1_17(data)                        (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_WR_DATA_33_get_lut_wr_data_d0_17(data)                    ((0xFFFF0000&(data))>>16)
#define  DM_DM_B05_LUT_WR_DATA_33_get_lut_wr_data_d1_17(data)                    (0x0000FFFF&(data))

#define  DM_DM_B05_LUT_WR_DATA_34                                                0x1806B684
#define  DM_DM_B05_LUT_WR_DATA_34_reg_addr                                       "0xB806B684"
#define  DM_DM_B05_LUT_WR_DATA_34_reg                                            0xB806B684
#define  DM_DM_B05_LUT_WR_DATA_34_inst_addr                                      "0x0064"
#define  set_DM_DM_B05_LUT_WR_DATA_34_reg(data)                                  (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_34_reg)=data)
#define  get_DM_DM_B05_LUT_WR_DATA_34_reg                                        (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_34_reg))
#define  DM_DM_B05_LUT_WR_DATA_34_lut_wr_data_d2_17_shift                        (0)
#define  DM_DM_B05_LUT_WR_DATA_34_lut_wr_data_d2_17_mask                         (0x0000FFFF)
#define  DM_DM_B05_LUT_WR_DATA_34_lut_wr_data_d2_17(data)                        (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_WR_DATA_34_get_lut_wr_data_d2_17(data)                    (0x0000FFFF&(data))

#define  DM_DM_B05_LUT_RD_DATA_1                                                 0x1806B688
#define  DM_DM_B05_LUT_RD_DATA_1_reg_addr                                        "0xB806B688"
#define  DM_DM_B05_LUT_RD_DATA_1_reg                                             0xB806B688
#define  DM_DM_B05_LUT_RD_DATA_1_inst_addr                                       "0x0065"
#define  set_DM_DM_B05_LUT_RD_DATA_1_reg(data)                                   (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_1_reg)=data)
#define  get_DM_DM_B05_LUT_RD_DATA_1_reg                                         (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_1_reg))
#define  DM_DM_B05_LUT_RD_DATA_1_lut_rd_data_d0_1_shift                          (16)
#define  DM_DM_B05_LUT_RD_DATA_1_lut_rd_data_d1_1_shift                          (0)
#define  DM_DM_B05_LUT_RD_DATA_1_lut_rd_data_d0_1_mask                           (0xFFFF0000)
#define  DM_DM_B05_LUT_RD_DATA_1_lut_rd_data_d1_1_mask                           (0x0000FFFF)
#define  DM_DM_B05_LUT_RD_DATA_1_lut_rd_data_d0_1(data)                          (0xFFFF0000&((data)<<16))
#define  DM_DM_B05_LUT_RD_DATA_1_lut_rd_data_d1_1(data)                          (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_RD_DATA_1_get_lut_rd_data_d0_1(data)                      ((0xFFFF0000&(data))>>16)
#define  DM_DM_B05_LUT_RD_DATA_1_get_lut_rd_data_d1_1(data)                      (0x0000FFFF&(data))

#define  DM_DM_B05_LUT_RD_DATA_2                                                 0x1806B68C
#define  DM_DM_B05_LUT_RD_DATA_2_reg_addr                                        "0xB806B68C"
#define  DM_DM_B05_LUT_RD_DATA_2_reg                                             0xB806B68C
#define  DM_DM_B05_LUT_RD_DATA_2_inst_addr                                       "0x0066"
#define  set_DM_DM_B05_LUT_RD_DATA_2_reg(data)                                   (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_2_reg)=data)
#define  get_DM_DM_B05_LUT_RD_DATA_2_reg                                         (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_2_reg))
#define  DM_DM_B05_LUT_RD_DATA_2_lut_rd_data_d2_1_shift                          (0)
#define  DM_DM_B05_LUT_RD_DATA_2_lut_rd_data_d2_1_mask                           (0x0000FFFF)
#define  DM_DM_B05_LUT_RD_DATA_2_lut_rd_data_d2_1(data)                          (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_RD_DATA_2_get_lut_rd_data_d2_1(data)                      (0x0000FFFF&(data))

#define  DM_DM_B05_LUT_RD_DATA_3                                                 0x1806B690
#define  DM_DM_B05_LUT_RD_DATA_3_reg_addr                                        "0xB806B690"
#define  DM_DM_B05_LUT_RD_DATA_3_reg                                             0xB806B690
#define  DM_DM_B05_LUT_RD_DATA_3_inst_addr                                       "0x0067"
#define  set_DM_DM_B05_LUT_RD_DATA_3_reg(data)                                   (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_3_reg)=data)
#define  get_DM_DM_B05_LUT_RD_DATA_3_reg                                         (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_3_reg))
#define  DM_DM_B05_LUT_RD_DATA_3_lut_rd_data_d0_2_shift                          (16)
#define  DM_DM_B05_LUT_RD_DATA_3_lut_rd_data_d1_2_shift                          (0)
#define  DM_DM_B05_LUT_RD_DATA_3_lut_rd_data_d0_2_mask                           (0xFFFF0000)
#define  DM_DM_B05_LUT_RD_DATA_3_lut_rd_data_d1_2_mask                           (0x0000FFFF)
#define  DM_DM_B05_LUT_RD_DATA_3_lut_rd_data_d0_2(data)                          (0xFFFF0000&((data)<<16))
#define  DM_DM_B05_LUT_RD_DATA_3_lut_rd_data_d1_2(data)                          (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_RD_DATA_3_get_lut_rd_data_d0_2(data)                      ((0xFFFF0000&(data))>>16)
#define  DM_DM_B05_LUT_RD_DATA_3_get_lut_rd_data_d1_2(data)                      (0x0000FFFF&(data))

#define  DM_DM_B05_LUT_RD_DATA_4                                                 0x1806B694
#define  DM_DM_B05_LUT_RD_DATA_4_reg_addr                                        "0xB806B694"
#define  DM_DM_B05_LUT_RD_DATA_4_reg                                             0xB806B694
#define  DM_DM_B05_LUT_RD_DATA_4_inst_addr                                       "0x0068"
#define  set_DM_DM_B05_LUT_RD_DATA_4_reg(data)                                   (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_4_reg)=data)
#define  get_DM_DM_B05_LUT_RD_DATA_4_reg                                         (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_4_reg))
#define  DM_DM_B05_LUT_RD_DATA_4_lut_rd_data_d2_2_shift                          (0)
#define  DM_DM_B05_LUT_RD_DATA_4_lut_rd_data_d2_2_mask                           (0x0000FFFF)
#define  DM_DM_B05_LUT_RD_DATA_4_lut_rd_data_d2_2(data)                          (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_RD_DATA_4_get_lut_rd_data_d2_2(data)                      (0x0000FFFF&(data))

#define  DM_DM_B05_LUT_RD_DATA_5                                                 0x1806B698
#define  DM_DM_B05_LUT_RD_DATA_5_reg_addr                                        "0xB806B698"
#define  DM_DM_B05_LUT_RD_DATA_5_reg                                             0xB806B698
#define  DM_DM_B05_LUT_RD_DATA_5_inst_addr                                       "0x0069"
#define  set_DM_DM_B05_LUT_RD_DATA_5_reg(data)                                   (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_5_reg)=data)
#define  get_DM_DM_B05_LUT_RD_DATA_5_reg                                         (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_5_reg))
#define  DM_DM_B05_LUT_RD_DATA_5_lut_rd_data_d0_3_shift                          (16)
#define  DM_DM_B05_LUT_RD_DATA_5_lut_rd_data_d1_3_shift                          (0)
#define  DM_DM_B05_LUT_RD_DATA_5_lut_rd_data_d0_3_mask                           (0xFFFF0000)
#define  DM_DM_B05_LUT_RD_DATA_5_lut_rd_data_d1_3_mask                           (0x0000FFFF)
#define  DM_DM_B05_LUT_RD_DATA_5_lut_rd_data_d0_3(data)                          (0xFFFF0000&((data)<<16))
#define  DM_DM_B05_LUT_RD_DATA_5_lut_rd_data_d1_3(data)                          (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_RD_DATA_5_get_lut_rd_data_d0_3(data)                      ((0xFFFF0000&(data))>>16)
#define  DM_DM_B05_LUT_RD_DATA_5_get_lut_rd_data_d1_3(data)                      (0x0000FFFF&(data))

#define  DM_DM_B05_LUT_RD_DATA_6                                                 0x1806B69C
#define  DM_DM_B05_LUT_RD_DATA_6_reg_addr                                        "0xB806B69C"
#define  DM_DM_B05_LUT_RD_DATA_6_reg                                             0xB806B69C
#define  DM_DM_B05_LUT_RD_DATA_6_inst_addr                                       "0x006A"
#define  set_DM_DM_B05_LUT_RD_DATA_6_reg(data)                                   (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_6_reg)=data)
#define  get_DM_DM_B05_LUT_RD_DATA_6_reg                                         (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_6_reg))
#define  DM_DM_B05_LUT_RD_DATA_6_lut_rd_data_d2_3_shift                          (0)
#define  DM_DM_B05_LUT_RD_DATA_6_lut_rd_data_d2_3_mask                           (0x0000FFFF)
#define  DM_DM_B05_LUT_RD_DATA_6_lut_rd_data_d2_3(data)                          (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_RD_DATA_6_get_lut_rd_data_d2_3(data)                      (0x0000FFFF&(data))

#define  DM_DM_B05_LUT_RD_DATA_7                                                 0x1806B6A0
#define  DM_DM_B05_LUT_RD_DATA_7_reg_addr                                        "0xB806B6A0"
#define  DM_DM_B05_LUT_RD_DATA_7_reg                                             0xB806B6A0
#define  DM_DM_B05_LUT_RD_DATA_7_inst_addr                                       "0x006B"
#define  set_DM_DM_B05_LUT_RD_DATA_7_reg(data)                                   (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_7_reg)=data)
#define  get_DM_DM_B05_LUT_RD_DATA_7_reg                                         (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_7_reg))
#define  DM_DM_B05_LUT_RD_DATA_7_lut_rd_data_d0_4_shift                          (16)
#define  DM_DM_B05_LUT_RD_DATA_7_lut_rd_data_d1_4_shift                          (0)
#define  DM_DM_B05_LUT_RD_DATA_7_lut_rd_data_d0_4_mask                           (0xFFFF0000)
#define  DM_DM_B05_LUT_RD_DATA_7_lut_rd_data_d1_4_mask                           (0x0000FFFF)
#define  DM_DM_B05_LUT_RD_DATA_7_lut_rd_data_d0_4(data)                          (0xFFFF0000&((data)<<16))
#define  DM_DM_B05_LUT_RD_DATA_7_lut_rd_data_d1_4(data)                          (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_RD_DATA_7_get_lut_rd_data_d0_4(data)                      ((0xFFFF0000&(data))>>16)
#define  DM_DM_B05_LUT_RD_DATA_7_get_lut_rd_data_d1_4(data)                      (0x0000FFFF&(data))

#define  DM_DM_B05_LUT_RD_DATA_8                                                 0x1806B6A4
#define  DM_DM_B05_LUT_RD_DATA_8_reg_addr                                        "0xB806B6A4"
#define  DM_DM_B05_LUT_RD_DATA_8_reg                                             0xB806B6A4
#define  DM_DM_B05_LUT_RD_DATA_8_inst_addr                                       "0x006C"
#define  set_DM_DM_B05_LUT_RD_DATA_8_reg(data)                                   (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_8_reg)=data)
#define  get_DM_DM_B05_LUT_RD_DATA_8_reg                                         (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_8_reg))
#define  DM_DM_B05_LUT_RD_DATA_8_lut_rd_data_d2_4_shift                          (0)
#define  DM_DM_B05_LUT_RD_DATA_8_lut_rd_data_d2_4_mask                           (0x0000FFFF)
#define  DM_DM_B05_LUT_RD_DATA_8_lut_rd_data_d2_4(data)                          (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_RD_DATA_8_get_lut_rd_data_d2_4(data)                      (0x0000FFFF&(data))

#define  DM_DM_B05_LUT_RD_DATA_9                                                 0x1806B6A8
#define  DM_DM_B05_LUT_RD_DATA_9_reg_addr                                        "0xB806B6A8"
#define  DM_DM_B05_LUT_RD_DATA_9_reg                                             0xB806B6A8
#define  DM_DM_B05_LUT_RD_DATA_9_inst_addr                                       "0x006D"
#define  set_DM_DM_B05_LUT_RD_DATA_9_reg(data)                                   (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_9_reg)=data)
#define  get_DM_DM_B05_LUT_RD_DATA_9_reg                                         (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_9_reg))
#define  DM_DM_B05_LUT_RD_DATA_9_lut_rd_data_d0_5_shift                          (16)
#define  DM_DM_B05_LUT_RD_DATA_9_lut_rd_data_d1_5_shift                          (0)
#define  DM_DM_B05_LUT_RD_DATA_9_lut_rd_data_d0_5_mask                           (0xFFFF0000)
#define  DM_DM_B05_LUT_RD_DATA_9_lut_rd_data_d1_5_mask                           (0x0000FFFF)
#define  DM_DM_B05_LUT_RD_DATA_9_lut_rd_data_d0_5(data)                          (0xFFFF0000&((data)<<16))
#define  DM_DM_B05_LUT_RD_DATA_9_lut_rd_data_d1_5(data)                          (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_RD_DATA_9_get_lut_rd_data_d0_5(data)                      ((0xFFFF0000&(data))>>16)
#define  DM_DM_B05_LUT_RD_DATA_9_get_lut_rd_data_d1_5(data)                      (0x0000FFFF&(data))

#define  DM_DM_B05_LUT_RD_DATA_10                                                0x1806B6AC
#define  DM_DM_B05_LUT_RD_DATA_10_reg_addr                                       "0xB806B6AC"
#define  DM_DM_B05_LUT_RD_DATA_10_reg                                            0xB806B6AC
#define  DM_DM_B05_LUT_RD_DATA_10_inst_addr                                      "0x006E"
#define  set_DM_DM_B05_LUT_RD_DATA_10_reg(data)                                  (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_10_reg)=data)
#define  get_DM_DM_B05_LUT_RD_DATA_10_reg                                        (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_10_reg))
#define  DM_DM_B05_LUT_RD_DATA_10_lut_rd_data_d2_5_shift                         (0)
#define  DM_DM_B05_LUT_RD_DATA_10_lut_rd_data_d2_5_mask                          (0x0000FFFF)
#define  DM_DM_B05_LUT_RD_DATA_10_lut_rd_data_d2_5(data)                         (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_RD_DATA_10_get_lut_rd_data_d2_5(data)                     (0x0000FFFF&(data))

#define  DM_DM_B05_LUT_RD_DATA_11                                                0x1806B6B0
#define  DM_DM_B05_LUT_RD_DATA_11_reg_addr                                       "0xB806B6B0"
#define  DM_DM_B05_LUT_RD_DATA_11_reg                                            0xB806B6B0
#define  DM_DM_B05_LUT_RD_DATA_11_inst_addr                                      "0x006F"
#define  set_DM_DM_B05_LUT_RD_DATA_11_reg(data)                                  (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_11_reg)=data)
#define  get_DM_DM_B05_LUT_RD_DATA_11_reg                                        (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_11_reg))
#define  DM_DM_B05_LUT_RD_DATA_11_lut_rd_data_d0_6_shift                         (16)
#define  DM_DM_B05_LUT_RD_DATA_11_lut_rd_data_d1_6_shift                         (0)
#define  DM_DM_B05_LUT_RD_DATA_11_lut_rd_data_d0_6_mask                          (0xFFFF0000)
#define  DM_DM_B05_LUT_RD_DATA_11_lut_rd_data_d1_6_mask                          (0x0000FFFF)
#define  DM_DM_B05_LUT_RD_DATA_11_lut_rd_data_d0_6(data)                         (0xFFFF0000&((data)<<16))
#define  DM_DM_B05_LUT_RD_DATA_11_lut_rd_data_d1_6(data)                         (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_RD_DATA_11_get_lut_rd_data_d0_6(data)                     ((0xFFFF0000&(data))>>16)
#define  DM_DM_B05_LUT_RD_DATA_11_get_lut_rd_data_d1_6(data)                     (0x0000FFFF&(data))

#define  DM_DM_B05_LUT_RD_DATA_12                                                0x1806B6B4
#define  DM_DM_B05_LUT_RD_DATA_12_reg_addr                                       "0xB806B6B4"
#define  DM_DM_B05_LUT_RD_DATA_12_reg                                            0xB806B6B4
#define  DM_DM_B05_LUT_RD_DATA_12_inst_addr                                      "0x0070"
#define  set_DM_DM_B05_LUT_RD_DATA_12_reg(data)                                  (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_12_reg)=data)
#define  get_DM_DM_B05_LUT_RD_DATA_12_reg                                        (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_12_reg))
#define  DM_DM_B05_LUT_RD_DATA_12_lut_rd_data_d2_6_shift                         (0)
#define  DM_DM_B05_LUT_RD_DATA_12_lut_rd_data_d2_6_mask                          (0x0000FFFF)
#define  DM_DM_B05_LUT_RD_DATA_12_lut_rd_data_d2_6(data)                         (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_RD_DATA_12_get_lut_rd_data_d2_6(data)                     (0x0000FFFF&(data))

#define  DM_DM_B05_LUT_RD_DATA_13                                                0x1806B6B8
#define  DM_DM_B05_LUT_RD_DATA_13_reg_addr                                       "0xB806B6B8"
#define  DM_DM_B05_LUT_RD_DATA_13_reg                                            0xB806B6B8
#define  DM_DM_B05_LUT_RD_DATA_13_inst_addr                                      "0x0071"
#define  set_DM_DM_B05_LUT_RD_DATA_13_reg(data)                                  (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_13_reg)=data)
#define  get_DM_DM_B05_LUT_RD_DATA_13_reg                                        (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_13_reg))
#define  DM_DM_B05_LUT_RD_DATA_13_lut_rd_data_d0_7_shift                         (16)
#define  DM_DM_B05_LUT_RD_DATA_13_lut_rd_data_d1_7_shift                         (0)
#define  DM_DM_B05_LUT_RD_DATA_13_lut_rd_data_d0_7_mask                          (0xFFFF0000)
#define  DM_DM_B05_LUT_RD_DATA_13_lut_rd_data_d1_7_mask                          (0x0000FFFF)
#define  DM_DM_B05_LUT_RD_DATA_13_lut_rd_data_d0_7(data)                         (0xFFFF0000&((data)<<16))
#define  DM_DM_B05_LUT_RD_DATA_13_lut_rd_data_d1_7(data)                         (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_RD_DATA_13_get_lut_rd_data_d0_7(data)                     ((0xFFFF0000&(data))>>16)
#define  DM_DM_B05_LUT_RD_DATA_13_get_lut_rd_data_d1_7(data)                     (0x0000FFFF&(data))

#define  DM_DM_B05_LUT_RD_DATA_14                                                0x1806B6BC
#define  DM_DM_B05_LUT_RD_DATA_14_reg_addr                                       "0xB806B6BC"
#define  DM_DM_B05_LUT_RD_DATA_14_reg                                            0xB806B6BC
#define  DM_DM_B05_LUT_RD_DATA_14_inst_addr                                      "0x0072"
#define  set_DM_DM_B05_LUT_RD_DATA_14_reg(data)                                  (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_14_reg)=data)
#define  get_DM_DM_B05_LUT_RD_DATA_14_reg                                        (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_14_reg))
#define  DM_DM_B05_LUT_RD_DATA_14_lut_rd_data_d2_7_shift                         (0)
#define  DM_DM_B05_LUT_RD_DATA_14_lut_rd_data_d2_7_mask                          (0x0000FFFF)
#define  DM_DM_B05_LUT_RD_DATA_14_lut_rd_data_d2_7(data)                         (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_RD_DATA_14_get_lut_rd_data_d2_7(data)                     (0x0000FFFF&(data))

#define  DM_DM_B05_LUT_RD_DATA_15                                                0x1806B6C0
#define  DM_DM_B05_LUT_RD_DATA_15_reg_addr                                       "0xB806B6C0"
#define  DM_DM_B05_LUT_RD_DATA_15_reg                                            0xB806B6C0
#define  DM_DM_B05_LUT_RD_DATA_15_inst_addr                                      "0x0073"
#define  set_DM_DM_B05_LUT_RD_DATA_15_reg(data)                                  (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_15_reg)=data)
#define  get_DM_DM_B05_LUT_RD_DATA_15_reg                                        (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_15_reg))
#define  DM_DM_B05_LUT_RD_DATA_15_lut_rd_data_d0_8_shift                         (16)
#define  DM_DM_B05_LUT_RD_DATA_15_lut_rd_data_d1_8_shift                         (0)
#define  DM_DM_B05_LUT_RD_DATA_15_lut_rd_data_d0_8_mask                          (0xFFFF0000)
#define  DM_DM_B05_LUT_RD_DATA_15_lut_rd_data_d1_8_mask                          (0x0000FFFF)
#define  DM_DM_B05_LUT_RD_DATA_15_lut_rd_data_d0_8(data)                         (0xFFFF0000&((data)<<16))
#define  DM_DM_B05_LUT_RD_DATA_15_lut_rd_data_d1_8(data)                         (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_RD_DATA_15_get_lut_rd_data_d0_8(data)                     ((0xFFFF0000&(data))>>16)
#define  DM_DM_B05_LUT_RD_DATA_15_get_lut_rd_data_d1_8(data)                     (0x0000FFFF&(data))

#define  DM_DM_B05_LUT_RD_DATA_16                                                0x1806B6C4
#define  DM_DM_B05_LUT_RD_DATA_16_reg_addr                                       "0xB806B6C4"
#define  DM_DM_B05_LUT_RD_DATA_16_reg                                            0xB806B6C4
#define  DM_DM_B05_LUT_RD_DATA_16_inst_addr                                      "0x0074"
#define  set_DM_DM_B05_LUT_RD_DATA_16_reg(data)                                  (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_16_reg)=data)
#define  get_DM_DM_B05_LUT_RD_DATA_16_reg                                        (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_16_reg))
#define  DM_DM_B05_LUT_RD_DATA_16_lut_rd_data_d2_8_shift                         (0)
#define  DM_DM_B05_LUT_RD_DATA_16_lut_rd_data_d2_8_mask                          (0x0000FFFF)
#define  DM_DM_B05_LUT_RD_DATA_16_lut_rd_data_d2_8(data)                         (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_RD_DATA_16_get_lut_rd_data_d2_8(data)                     (0x0000FFFF&(data))

#define  DM_DM_B05_LUT_RD_DATA_17                                                0x1806B6C8
#define  DM_DM_B05_LUT_RD_DATA_17_reg_addr                                       "0xB806B6C8"
#define  DM_DM_B05_LUT_RD_DATA_17_reg                                            0xB806B6C8
#define  DM_DM_B05_LUT_RD_DATA_17_inst_addr                                      "0x0075"
#define  set_DM_DM_B05_LUT_RD_DATA_17_reg(data)                                  (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_17_reg)=data)
#define  get_DM_DM_B05_LUT_RD_DATA_17_reg                                        (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_17_reg))
#define  DM_DM_B05_LUT_RD_DATA_17_lut_rd_data_d0_9_shift                         (16)
#define  DM_DM_B05_LUT_RD_DATA_17_lut_rd_data_d1_9_shift                         (0)
#define  DM_DM_B05_LUT_RD_DATA_17_lut_rd_data_d0_9_mask                          (0xFFFF0000)
#define  DM_DM_B05_LUT_RD_DATA_17_lut_rd_data_d1_9_mask                          (0x0000FFFF)
#define  DM_DM_B05_LUT_RD_DATA_17_lut_rd_data_d0_9(data)                         (0xFFFF0000&((data)<<16))
#define  DM_DM_B05_LUT_RD_DATA_17_lut_rd_data_d1_9(data)                         (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_RD_DATA_17_get_lut_rd_data_d0_9(data)                     ((0xFFFF0000&(data))>>16)
#define  DM_DM_B05_LUT_RD_DATA_17_get_lut_rd_data_d1_9(data)                     (0x0000FFFF&(data))

#define  DM_DM_B05_LUT_RD_DATA_18                                                0x1806B6CC
#define  DM_DM_B05_LUT_RD_DATA_18_reg_addr                                       "0xB806B6CC"
#define  DM_DM_B05_LUT_RD_DATA_18_reg                                            0xB806B6CC
#define  DM_DM_B05_LUT_RD_DATA_18_inst_addr                                      "0x0076"
#define  set_DM_DM_B05_LUT_RD_DATA_18_reg(data)                                  (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_18_reg)=data)
#define  get_DM_DM_B05_LUT_RD_DATA_18_reg                                        (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_18_reg))
#define  DM_DM_B05_LUT_RD_DATA_18_lut_rd_data_d2_9_shift                         (0)
#define  DM_DM_B05_LUT_RD_DATA_18_lut_rd_data_d2_9_mask                          (0x0000FFFF)
#define  DM_DM_B05_LUT_RD_DATA_18_lut_rd_data_d2_9(data)                         (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_RD_DATA_18_get_lut_rd_data_d2_9(data)                     (0x0000FFFF&(data))

#define  DM_DM_B05_LUT_RD_DATA_19                                                0x1806B6D0
#define  DM_DM_B05_LUT_RD_DATA_19_reg_addr                                       "0xB806B6D0"
#define  DM_DM_B05_LUT_RD_DATA_19_reg                                            0xB806B6D0
#define  DM_DM_B05_LUT_RD_DATA_19_inst_addr                                      "0x0077"
#define  set_DM_DM_B05_LUT_RD_DATA_19_reg(data)                                  (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_19_reg)=data)
#define  get_DM_DM_B05_LUT_RD_DATA_19_reg                                        (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_19_reg))
#define  DM_DM_B05_LUT_RD_DATA_19_lut_rd_data_d0_10_shift                        (16)
#define  DM_DM_B05_LUT_RD_DATA_19_lut_rd_data_d1_10_shift                        (0)
#define  DM_DM_B05_LUT_RD_DATA_19_lut_rd_data_d0_10_mask                         (0xFFFF0000)
#define  DM_DM_B05_LUT_RD_DATA_19_lut_rd_data_d1_10_mask                         (0x0000FFFF)
#define  DM_DM_B05_LUT_RD_DATA_19_lut_rd_data_d0_10(data)                        (0xFFFF0000&((data)<<16))
#define  DM_DM_B05_LUT_RD_DATA_19_lut_rd_data_d1_10(data)                        (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_RD_DATA_19_get_lut_rd_data_d0_10(data)                    ((0xFFFF0000&(data))>>16)
#define  DM_DM_B05_LUT_RD_DATA_19_get_lut_rd_data_d1_10(data)                    (0x0000FFFF&(data))

#define  DM_DM_B05_LUT_RD_DATA_20                                                0x1806B6D4
#define  DM_DM_B05_LUT_RD_DATA_20_reg_addr                                       "0xB806B6D4"
#define  DM_DM_B05_LUT_RD_DATA_20_reg                                            0xB806B6D4
#define  DM_DM_B05_LUT_RD_DATA_20_inst_addr                                      "0x0078"
#define  set_DM_DM_B05_LUT_RD_DATA_20_reg(data)                                  (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_20_reg)=data)
#define  get_DM_DM_B05_LUT_RD_DATA_20_reg                                        (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_20_reg))
#define  DM_DM_B05_LUT_RD_DATA_20_lut_rd_data_d2_10_shift                        (0)
#define  DM_DM_B05_LUT_RD_DATA_20_lut_rd_data_d2_10_mask                         (0x0000FFFF)
#define  DM_DM_B05_LUT_RD_DATA_20_lut_rd_data_d2_10(data)                        (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_RD_DATA_20_get_lut_rd_data_d2_10(data)                    (0x0000FFFF&(data))

#define  DM_DM_B05_LUT_RD_DATA_21                                                0x1806B6D8
#define  DM_DM_B05_LUT_RD_DATA_21_reg_addr                                       "0xB806B6D8"
#define  DM_DM_B05_LUT_RD_DATA_21_reg                                            0xB806B6D8
#define  DM_DM_B05_LUT_RD_DATA_21_inst_addr                                      "0x0079"
#define  set_DM_DM_B05_LUT_RD_DATA_21_reg(data)                                  (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_21_reg)=data)
#define  get_DM_DM_B05_LUT_RD_DATA_21_reg                                        (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_21_reg))
#define  DM_DM_B05_LUT_RD_DATA_21_lut_rd_data_d0_11_shift                        (16)
#define  DM_DM_B05_LUT_RD_DATA_21_lut_rd_data_d1_11_shift                        (0)
#define  DM_DM_B05_LUT_RD_DATA_21_lut_rd_data_d0_11_mask                         (0xFFFF0000)
#define  DM_DM_B05_LUT_RD_DATA_21_lut_rd_data_d1_11_mask                         (0x0000FFFF)
#define  DM_DM_B05_LUT_RD_DATA_21_lut_rd_data_d0_11(data)                        (0xFFFF0000&((data)<<16))
#define  DM_DM_B05_LUT_RD_DATA_21_lut_rd_data_d1_11(data)                        (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_RD_DATA_21_get_lut_rd_data_d0_11(data)                    ((0xFFFF0000&(data))>>16)
#define  DM_DM_B05_LUT_RD_DATA_21_get_lut_rd_data_d1_11(data)                    (0x0000FFFF&(data))

#define  DM_DM_B05_LUT_RD_DATA_22                                                0x1806B6DC
#define  DM_DM_B05_LUT_RD_DATA_22_reg_addr                                       "0xB806B6DC"
#define  DM_DM_B05_LUT_RD_DATA_22_reg                                            0xB806B6DC
#define  DM_DM_B05_LUT_RD_DATA_22_inst_addr                                      "0x007A"
#define  set_DM_DM_B05_LUT_RD_DATA_22_reg(data)                                  (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_22_reg)=data)
#define  get_DM_DM_B05_LUT_RD_DATA_22_reg                                        (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_22_reg))
#define  DM_DM_B05_LUT_RD_DATA_22_lut_rd_data_d2_11_shift                        (0)
#define  DM_DM_B05_LUT_RD_DATA_22_lut_rd_data_d2_11_mask                         (0x0000FFFF)
#define  DM_DM_B05_LUT_RD_DATA_22_lut_rd_data_d2_11(data)                        (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_RD_DATA_22_get_lut_rd_data_d2_11(data)                    (0x0000FFFF&(data))

#define  DM_DM_B05_LUT_RD_DATA_23                                                0x1806B6E0
#define  DM_DM_B05_LUT_RD_DATA_23_reg_addr                                       "0xB806B6E0"
#define  DM_DM_B05_LUT_RD_DATA_23_reg                                            0xB806B6E0
#define  DM_DM_B05_LUT_RD_DATA_23_inst_addr                                      "0x007B"
#define  set_DM_DM_B05_LUT_RD_DATA_23_reg(data)                                  (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_23_reg)=data)
#define  get_DM_DM_B05_LUT_RD_DATA_23_reg                                        (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_23_reg))
#define  DM_DM_B05_LUT_RD_DATA_23_lut_rd_data_d0_12_shift                        (16)
#define  DM_DM_B05_LUT_RD_DATA_23_lut_rd_data_d1_12_shift                        (0)
#define  DM_DM_B05_LUT_RD_DATA_23_lut_rd_data_d0_12_mask                         (0xFFFF0000)
#define  DM_DM_B05_LUT_RD_DATA_23_lut_rd_data_d1_12_mask                         (0x0000FFFF)
#define  DM_DM_B05_LUT_RD_DATA_23_lut_rd_data_d0_12(data)                        (0xFFFF0000&((data)<<16))
#define  DM_DM_B05_LUT_RD_DATA_23_lut_rd_data_d1_12(data)                        (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_RD_DATA_23_get_lut_rd_data_d0_12(data)                    ((0xFFFF0000&(data))>>16)
#define  DM_DM_B05_LUT_RD_DATA_23_get_lut_rd_data_d1_12(data)                    (0x0000FFFF&(data))

#define  DM_DM_B05_LUT_RD_DATA_24                                                0x1806B6E4
#define  DM_DM_B05_LUT_RD_DATA_24_reg_addr                                       "0xB806B6E4"
#define  DM_DM_B05_LUT_RD_DATA_24_reg                                            0xB806B6E4
#define  DM_DM_B05_LUT_RD_DATA_24_inst_addr                                      "0x007C"
#define  set_DM_DM_B05_LUT_RD_DATA_24_reg(data)                                  (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_24_reg)=data)
#define  get_DM_DM_B05_LUT_RD_DATA_24_reg                                        (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_24_reg))
#define  DM_DM_B05_LUT_RD_DATA_24_lut_rd_data_d2_12_shift                        (0)
#define  DM_DM_B05_LUT_RD_DATA_24_lut_rd_data_d2_12_mask                         (0x0000FFFF)
#define  DM_DM_B05_LUT_RD_DATA_24_lut_rd_data_d2_12(data)                        (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_RD_DATA_24_get_lut_rd_data_d2_12(data)                    (0x0000FFFF&(data))

#define  DM_DM_B05_LUT_RD_DATA_25                                                0x1806B6E8
#define  DM_DM_B05_LUT_RD_DATA_25_reg_addr                                       "0xB806B6E8"
#define  DM_DM_B05_LUT_RD_DATA_25_reg                                            0xB806B6E8
#define  DM_DM_B05_LUT_RD_DATA_25_inst_addr                                      "0x007D"
#define  set_DM_DM_B05_LUT_RD_DATA_25_reg(data)                                  (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_25_reg)=data)
#define  get_DM_DM_B05_LUT_RD_DATA_25_reg                                        (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_25_reg))
#define  DM_DM_B05_LUT_RD_DATA_25_lut_rd_data_d0_13_shift                        (16)
#define  DM_DM_B05_LUT_RD_DATA_25_lut_rd_data_d1_13_shift                        (0)
#define  DM_DM_B05_LUT_RD_DATA_25_lut_rd_data_d0_13_mask                         (0xFFFF0000)
#define  DM_DM_B05_LUT_RD_DATA_25_lut_rd_data_d1_13_mask                         (0x0000FFFF)
#define  DM_DM_B05_LUT_RD_DATA_25_lut_rd_data_d0_13(data)                        (0xFFFF0000&((data)<<16))
#define  DM_DM_B05_LUT_RD_DATA_25_lut_rd_data_d1_13(data)                        (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_RD_DATA_25_get_lut_rd_data_d0_13(data)                    ((0xFFFF0000&(data))>>16)
#define  DM_DM_B05_LUT_RD_DATA_25_get_lut_rd_data_d1_13(data)                    (0x0000FFFF&(data))

#define  DM_DM_B05_LUT_RD_DATA_26                                                0x1806B6EC
#define  DM_DM_B05_LUT_RD_DATA_26_reg_addr                                       "0xB806B6EC"
#define  DM_DM_B05_LUT_RD_DATA_26_reg                                            0xB806B6EC
#define  DM_DM_B05_LUT_RD_DATA_26_inst_addr                                      "0x007E"
#define  set_DM_DM_B05_LUT_RD_DATA_26_reg(data)                                  (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_26_reg)=data)
#define  get_DM_DM_B05_LUT_RD_DATA_26_reg                                        (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_26_reg))
#define  DM_DM_B05_LUT_RD_DATA_26_lut_rd_data_d2_13_shift                        (0)
#define  DM_DM_B05_LUT_RD_DATA_26_lut_rd_data_d2_13_mask                         (0x0000FFFF)
#define  DM_DM_B05_LUT_RD_DATA_26_lut_rd_data_d2_13(data)                        (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_RD_DATA_26_get_lut_rd_data_d2_13(data)                    (0x0000FFFF&(data))

#define  DM_DM_B05_LUT_RD_DATA_27                                                0x1806B6F0
#define  DM_DM_B05_LUT_RD_DATA_27_reg_addr                                       "0xB806B6F0"
#define  DM_DM_B05_LUT_RD_DATA_27_reg                                            0xB806B6F0
#define  DM_DM_B05_LUT_RD_DATA_27_inst_addr                                      "0x007F"
#define  set_DM_DM_B05_LUT_RD_DATA_27_reg(data)                                  (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_27_reg)=data)
#define  get_DM_DM_B05_LUT_RD_DATA_27_reg                                        (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_27_reg))
#define  DM_DM_B05_LUT_RD_DATA_27_lut_rd_data_d0_14_shift                        (16)
#define  DM_DM_B05_LUT_RD_DATA_27_lut_rd_data_d1_14_shift                        (0)
#define  DM_DM_B05_LUT_RD_DATA_27_lut_rd_data_d0_14_mask                         (0xFFFF0000)
#define  DM_DM_B05_LUT_RD_DATA_27_lut_rd_data_d1_14_mask                         (0x0000FFFF)
#define  DM_DM_B05_LUT_RD_DATA_27_lut_rd_data_d0_14(data)                        (0xFFFF0000&((data)<<16))
#define  DM_DM_B05_LUT_RD_DATA_27_lut_rd_data_d1_14(data)                        (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_RD_DATA_27_get_lut_rd_data_d0_14(data)                    ((0xFFFF0000&(data))>>16)
#define  DM_DM_B05_LUT_RD_DATA_27_get_lut_rd_data_d1_14(data)                    (0x0000FFFF&(data))

#define  DM_DM_B05_LUT_RD_DATA_28                                                0x1806B6F4
#define  DM_DM_B05_LUT_RD_DATA_28_reg_addr                                       "0xB806B6F4"
#define  DM_DM_B05_LUT_RD_DATA_28_reg                                            0xB806B6F4
#define  DM_DM_B05_LUT_RD_DATA_28_inst_addr                                      "0x0080"
#define  set_DM_DM_B05_LUT_RD_DATA_28_reg(data)                                  (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_28_reg)=data)
#define  get_DM_DM_B05_LUT_RD_DATA_28_reg                                        (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_28_reg))
#define  DM_DM_B05_LUT_RD_DATA_28_lut_rd_data_d2_14_shift                        (0)
#define  DM_DM_B05_LUT_RD_DATA_28_lut_rd_data_d2_14_mask                         (0x0000FFFF)
#define  DM_DM_B05_LUT_RD_DATA_28_lut_rd_data_d2_14(data)                        (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_RD_DATA_28_get_lut_rd_data_d2_14(data)                    (0x0000FFFF&(data))

#define  DM_DM_B05_LUT_RD_DATA_29                                                0x1806B6F8
#define  DM_DM_B05_LUT_RD_DATA_29_reg_addr                                       "0xB806B6F8"
#define  DM_DM_B05_LUT_RD_DATA_29_reg                                            0xB806B6F8
#define  DM_DM_B05_LUT_RD_DATA_29_inst_addr                                      "0x0081"
#define  set_DM_DM_B05_LUT_RD_DATA_29_reg(data)                                  (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_29_reg)=data)
#define  get_DM_DM_B05_LUT_RD_DATA_29_reg                                        (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_29_reg))
#define  DM_DM_B05_LUT_RD_DATA_29_lut_rd_data_d0_15_shift                        (16)
#define  DM_DM_B05_LUT_RD_DATA_29_lut_rd_data_d1_15_shift                        (0)
#define  DM_DM_B05_LUT_RD_DATA_29_lut_rd_data_d0_15_mask                         (0xFFFF0000)
#define  DM_DM_B05_LUT_RD_DATA_29_lut_rd_data_d1_15_mask                         (0x0000FFFF)
#define  DM_DM_B05_LUT_RD_DATA_29_lut_rd_data_d0_15(data)                        (0xFFFF0000&((data)<<16))
#define  DM_DM_B05_LUT_RD_DATA_29_lut_rd_data_d1_15(data)                        (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_RD_DATA_29_get_lut_rd_data_d0_15(data)                    ((0xFFFF0000&(data))>>16)
#define  DM_DM_B05_LUT_RD_DATA_29_get_lut_rd_data_d1_15(data)                    (0x0000FFFF&(data))

#define  DM_DM_B05_LUT_RD_DATA_30                                                0x1806B6FC
#define  DM_DM_B05_LUT_RD_DATA_30_reg_addr                                       "0xB806B6FC"
#define  DM_DM_B05_LUT_RD_DATA_30_reg                                            0xB806B6FC
#define  DM_DM_B05_LUT_RD_DATA_30_inst_addr                                      "0x0082"
#define  set_DM_DM_B05_LUT_RD_DATA_30_reg(data)                                  (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_30_reg)=data)
#define  get_DM_DM_B05_LUT_RD_DATA_30_reg                                        (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_30_reg))
#define  DM_DM_B05_LUT_RD_DATA_30_lut_rd_data_d2_15_shift                        (0)
#define  DM_DM_B05_LUT_RD_DATA_30_lut_rd_data_d2_15_mask                         (0x0000FFFF)
#define  DM_DM_B05_LUT_RD_DATA_30_lut_rd_data_d2_15(data)                        (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_RD_DATA_30_get_lut_rd_data_d2_15(data)                    (0x0000FFFF&(data))

#define  DM_DM_B05_LUT_RD_DATA_31                                                0x1806B700
#define  DM_DM_B05_LUT_RD_DATA_31_reg_addr                                       "0xB806B700"
#define  DM_DM_B05_LUT_RD_DATA_31_reg                                            0xB806B700
#define  DM_DM_B05_LUT_RD_DATA_31_inst_addr                                      "0x0083"
#define  set_DM_DM_B05_LUT_RD_DATA_31_reg(data)                                  (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_31_reg)=data)
#define  get_DM_DM_B05_LUT_RD_DATA_31_reg                                        (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_31_reg))
#define  DM_DM_B05_LUT_RD_DATA_31_lut_rd_data_d0_16_shift                        (16)
#define  DM_DM_B05_LUT_RD_DATA_31_lut_rd_data_d1_16_shift                        (0)
#define  DM_DM_B05_LUT_RD_DATA_31_lut_rd_data_d0_16_mask                         (0xFFFF0000)
#define  DM_DM_B05_LUT_RD_DATA_31_lut_rd_data_d1_16_mask                         (0x0000FFFF)
#define  DM_DM_B05_LUT_RD_DATA_31_lut_rd_data_d0_16(data)                        (0xFFFF0000&((data)<<16))
#define  DM_DM_B05_LUT_RD_DATA_31_lut_rd_data_d1_16(data)                        (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_RD_DATA_31_get_lut_rd_data_d0_16(data)                    ((0xFFFF0000&(data))>>16)
#define  DM_DM_B05_LUT_RD_DATA_31_get_lut_rd_data_d1_16(data)                    (0x0000FFFF&(data))

#define  DM_DM_B05_LUT_RD_DATA_32                                                0x1806B704
#define  DM_DM_B05_LUT_RD_DATA_32_reg_addr                                       "0xB806B704"
#define  DM_DM_B05_LUT_RD_DATA_32_reg                                            0xB806B704
#define  DM_DM_B05_LUT_RD_DATA_32_inst_addr                                      "0x0084"
#define  set_DM_DM_B05_LUT_RD_DATA_32_reg(data)                                  (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_32_reg)=data)
#define  get_DM_DM_B05_LUT_RD_DATA_32_reg                                        (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_32_reg))
#define  DM_DM_B05_LUT_RD_DATA_32_lut_rd_data_d2_16_shift                        (0)
#define  DM_DM_B05_LUT_RD_DATA_32_lut_rd_data_d2_16_mask                         (0x0000FFFF)
#define  DM_DM_B05_LUT_RD_DATA_32_lut_rd_data_d2_16(data)                        (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_RD_DATA_32_get_lut_rd_data_d2_16(data)                    (0x0000FFFF&(data))

#define  DM_DM_B05_LUT_RD_DATA_33                                                0x1806B708
#define  DM_DM_B05_LUT_RD_DATA_33_reg_addr                                       "0xB806B708"
#define  DM_DM_B05_LUT_RD_DATA_33_reg                                            0xB806B708
#define  DM_DM_B05_LUT_RD_DATA_33_inst_addr                                      "0x0085"
#define  set_DM_DM_B05_LUT_RD_DATA_33_reg(data)                                  (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_33_reg)=data)
#define  get_DM_DM_B05_LUT_RD_DATA_33_reg                                        (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_33_reg))
#define  DM_DM_B05_LUT_RD_DATA_33_lut_rd_data_d0_17_shift                        (16)
#define  DM_DM_B05_LUT_RD_DATA_33_lut_rd_data_d1_17_shift                        (0)
#define  DM_DM_B05_LUT_RD_DATA_33_lut_rd_data_d0_17_mask                         (0xFFFF0000)
#define  DM_DM_B05_LUT_RD_DATA_33_lut_rd_data_d1_17_mask                         (0x0000FFFF)
#define  DM_DM_B05_LUT_RD_DATA_33_lut_rd_data_d0_17(data)                        (0xFFFF0000&((data)<<16))
#define  DM_DM_B05_LUT_RD_DATA_33_lut_rd_data_d1_17(data)                        (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_RD_DATA_33_get_lut_rd_data_d0_17(data)                    ((0xFFFF0000&(data))>>16)
#define  DM_DM_B05_LUT_RD_DATA_33_get_lut_rd_data_d1_17(data)                    (0x0000FFFF&(data))

#define  DM_DM_B05_LUT_RD_DATA_34                                                0x1806B70C
#define  DM_DM_B05_LUT_RD_DATA_34_reg_addr                                       "0xB806B70C"
#define  DM_DM_B05_LUT_RD_DATA_34_reg                                            0xB806B70C
#define  DM_DM_B05_LUT_RD_DATA_34_inst_addr                                      "0x0086"
#define  set_DM_DM_B05_LUT_RD_DATA_34_reg(data)                                  (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_34_reg)=data)
#define  get_DM_DM_B05_LUT_RD_DATA_34_reg                                        (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_34_reg))
#define  DM_DM_B05_LUT_RD_DATA_34_lut_rd_data_d2_17_shift                        (0)
#define  DM_DM_B05_LUT_RD_DATA_34_lut_rd_data_d2_17_mask                         (0x0000FFFF)
#define  DM_DM_B05_LUT_RD_DATA_34_lut_rd_data_d2_17(data)                        (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_RD_DATA_34_get_lut_rd_data_d2_17(data)                    (0x0000FFFF&(data))

#define  DM_DM_B05_LUT_CTRL1                                                     0x1806B748
#define  DM_DM_B05_LUT_CTRL1_reg_addr                                            "0xB806B748"
#define  DM_DM_B05_LUT_CTRL1_reg                                                 0xB806B748
#define  DM_DM_B05_LUT_CTRL1_inst_addr                                           "0x0087"
#define  set_DM_DM_B05_LUT_CTRL1_reg(data)                                       (*((volatile unsigned int*)DM_DM_B05_LUT_CTRL1_reg)=data)
#define  get_DM_DM_B05_LUT_CTRL1_reg                                             (*((volatile unsigned int*)DM_DM_B05_LUT_CTRL1_reg))
#define  DM_DM_B05_LUT_CTRL1_lut24_b05_rw_sel_shift                              (29)
#define  DM_DM_B05_LUT_CTRL1_lut24_b05_write_en_shift                            (28)
#define  DM_DM_B05_LUT_CTRL1_lut24_b05_read_en_shift                             (27)
#define  DM_DM_B05_LUT_CTRL1_lut24_b05_rw_adr_shift                              (0)
#define  DM_DM_B05_LUT_CTRL1_lut24_b05_rw_sel_mask                               (0x60000000)
#define  DM_DM_B05_LUT_CTRL1_lut24_b05_write_en_mask                             (0x10000000)
#define  DM_DM_B05_LUT_CTRL1_lut24_b05_read_en_mask                              (0x08000000)
#define  DM_DM_B05_LUT_CTRL1_lut24_b05_rw_adr_mask                               (0x000003FF)
#define  DM_DM_B05_LUT_CTRL1_lut24_b05_rw_sel(data)                              (0x60000000&((data)<<29))
#define  DM_DM_B05_LUT_CTRL1_lut24_b05_write_en(data)                            (0x10000000&((data)<<28))
#define  DM_DM_B05_LUT_CTRL1_lut24_b05_read_en(data)                             (0x08000000&((data)<<27))
#define  DM_DM_B05_LUT_CTRL1_lut24_b05_rw_adr(data)                              (0x000003FF&(data))
#define  DM_DM_B05_LUT_CTRL1_get_lut24_b05_rw_sel(data)                          ((0x60000000&(data))>>29)
#define  DM_DM_B05_LUT_CTRL1_get_lut24_b05_write_en(data)                        ((0x10000000&(data))>>28)
#define  DM_DM_B05_LUT_CTRL1_get_lut24_b05_read_en(data)                         ((0x08000000&(data))>>27)
#define  DM_DM_B05_LUT_CTRL1_get_lut24_b05_rw_adr(data)                          (0x000003FF&(data))

#define  DM_DM_B05_LUT_CTRL2                                                     0x1806B74C
#define  DM_DM_B05_LUT_CTRL2_reg_addr                                            "0xB806B74C"
#define  DM_DM_B05_LUT_CTRL2_reg                                                 0xB806B74C
#define  DM_DM_B05_LUT_CTRL2_inst_addr                                           "0x0088"
#define  set_DM_DM_B05_LUT_CTRL2_reg(data)                                       (*((volatile unsigned int*)DM_DM_B05_LUT_CTRL2_reg)=data)
#define  get_DM_DM_B05_LUT_CTRL2_reg                                             (*((volatile unsigned int*)DM_DM_B05_LUT_CTRL2_reg))
#define  DM_DM_B05_LUT_CTRL2_lut24_b05_acc_ready_shift                           (31)
#define  DM_DM_B05_LUT_CTRL2_lut24_b05_acc_sel_shift                             (8)
#define  DM_DM_B05_LUT_CTRL2_dm_b05_input_ctrl_shift                             (1)
#define  DM_DM_B05_LUT_CTRL2_dm_b05_dimension_shift                              (0)
#define  DM_DM_B05_LUT_CTRL2_lut24_b05_acc_ready_mask                            (0x80000000)
#define  DM_DM_B05_LUT_CTRL2_lut24_b05_acc_sel_mask                              (0x00000100)
#define  DM_DM_B05_LUT_CTRL2_dm_b05_input_ctrl_mask                              (0x00000002)
#define  DM_DM_B05_LUT_CTRL2_dm_b05_dimension_mask                               (0x00000001)
#define  DM_DM_B05_LUT_CTRL2_lut24_b05_acc_ready(data)                           (0x80000000&((data)<<31))
#define  DM_DM_B05_LUT_CTRL2_lut24_b05_acc_sel(data)                             (0x00000100&((data)<<8))
#define  DM_DM_B05_LUT_CTRL2_dm_b05_input_ctrl(data)                             (0x00000002&((data)<<1))
#define  DM_DM_B05_LUT_CTRL2_dm_b05_dimension(data)                              (0x00000001&(data))
#define  DM_DM_B05_LUT_CTRL2_get_lut24_b05_acc_ready(data)                       ((0x80000000&(data))>>31)
#define  DM_DM_B05_LUT_CTRL2_get_lut24_b05_acc_sel(data)                         ((0x00000100&(data))>>8)
#define  DM_DM_B05_LUT_CTRL2_get_dm_b05_input_ctrl(data)                         ((0x00000002&(data))>>1)
#define  DM_DM_B05_LUT_CTRL2_get_dm_b05_dimension(data)                          (0x00000001&(data))

#define  DM_DM_B05_LUT_CTRL3                                                     0x1806B750
#define  DM_DM_B05_LUT_CTRL3_reg_addr                                            "0xB806B750"
#define  DM_DM_B05_LUT_CTRL3_reg                                                 0xB806B750
#define  DM_DM_B05_LUT_CTRL3_inst_addr                                           "0x0089"
#define  set_DM_DM_B05_LUT_CTRL3_reg(data)                                       (*((volatile unsigned int*)DM_DM_B05_LUT_CTRL3_reg)=data)
#define  get_DM_DM_B05_LUT_CTRL3_reg                                             (*((volatile unsigned int*)DM_DM_B05_LUT_CTRL3_reg))
#define  DM_DM_B05_LUT_CTRL3_lut24_b05_fw_lut0_rd_acc_shift                      (5)
#define  DM_DM_B05_LUT_CTRL3_lut24_b05_fw_lut0_wr_acc_shift                      (4)
#define  DM_DM_B05_LUT_CTRL3_lut24_b05_hw_lut0_rd_acc_shift                      (3)
#define  DM_DM_B05_LUT_CTRL3_lut24_b05_fw_lut1_rd_acc_shift                      (2)
#define  DM_DM_B05_LUT_CTRL3_lut24_b05_fw_lut1_wr_acc_shift                      (1)
#define  DM_DM_B05_LUT_CTRL3_lut24_b05_hw_lut1_rd_acc_shift                      (0)
#define  DM_DM_B05_LUT_CTRL3_lut24_b05_fw_lut0_rd_acc_mask                       (0x00000020)
#define  DM_DM_B05_LUT_CTRL3_lut24_b05_fw_lut0_wr_acc_mask                       (0x00000010)
#define  DM_DM_B05_LUT_CTRL3_lut24_b05_hw_lut0_rd_acc_mask                       (0x00000008)
#define  DM_DM_B05_LUT_CTRL3_lut24_b05_fw_lut1_rd_acc_mask                       (0x00000004)
#define  DM_DM_B05_LUT_CTRL3_lut24_b05_fw_lut1_wr_acc_mask                       (0x00000002)
#define  DM_DM_B05_LUT_CTRL3_lut24_b05_hw_lut1_rd_acc_mask                       (0x00000001)
#define  DM_DM_B05_LUT_CTRL3_lut24_b05_fw_lut0_rd_acc(data)                      (0x00000020&((data)<<5))
#define  DM_DM_B05_LUT_CTRL3_lut24_b05_fw_lut0_wr_acc(data)                      (0x00000010&((data)<<4))
#define  DM_DM_B05_LUT_CTRL3_lut24_b05_hw_lut0_rd_acc(data)                      (0x00000008&((data)<<3))
#define  DM_DM_B05_LUT_CTRL3_lut24_b05_fw_lut1_rd_acc(data)                      (0x00000004&((data)<<2))
#define  DM_DM_B05_LUT_CTRL3_lut24_b05_fw_lut1_wr_acc(data)                      (0x00000002&((data)<<1))
#define  DM_DM_B05_LUT_CTRL3_lut24_b05_hw_lut1_rd_acc(data)                      (0x00000001&(data))
#define  DM_DM_B05_LUT_CTRL3_get_lut24_b05_fw_lut0_rd_acc(data)                  ((0x00000020&(data))>>5)
#define  DM_DM_B05_LUT_CTRL3_get_lut24_b05_fw_lut0_wr_acc(data)                  ((0x00000010&(data))>>4)
#define  DM_DM_B05_LUT_CTRL3_get_lut24_b05_hw_lut0_rd_acc(data)                  ((0x00000008&(data))>>3)
#define  DM_DM_B05_LUT_CTRL3_get_lut24_b05_fw_lut1_rd_acc(data)                  ((0x00000004&(data))>>2)
#define  DM_DM_B05_LUT_CTRL3_get_lut24_b05_fw_lut1_wr_acc(data)                  ((0x00000002&(data))>>1)
#define  DM_DM_B05_LUT_CTRL3_get_lut24_b05_hw_lut1_rd_acc(data)                  (0x00000001&(data))

#define  DM_DM_B05_LUT_WR_DATA_35                                                0x1806B754
#define  DM_DM_B05_LUT_WR_DATA_35_reg_addr                                       "0xB806B754"
#define  DM_DM_B05_LUT_WR_DATA_35_reg                                            0xB806B754
#define  DM_DM_B05_LUT_WR_DATA_35_inst_addr                                      "0x008A"
#define  set_DM_DM_B05_LUT_WR_DATA_35_reg(data)                                  (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_35_reg)=data)
#define  get_DM_DM_B05_LUT_WR_DATA_35_reg                                        (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_35_reg))
#define  DM_DM_B05_LUT_WR_DATA_35_lut_wr_data_d0_18_shift                        (16)
#define  DM_DM_B05_LUT_WR_DATA_35_lut_wr_data_d1_18_shift                        (0)
#define  DM_DM_B05_LUT_WR_DATA_35_lut_wr_data_d0_18_mask                         (0xFFFF0000)
#define  DM_DM_B05_LUT_WR_DATA_35_lut_wr_data_d1_18_mask                         (0x0000FFFF)
#define  DM_DM_B05_LUT_WR_DATA_35_lut_wr_data_d0_18(data)                        (0xFFFF0000&((data)<<16))
#define  DM_DM_B05_LUT_WR_DATA_35_lut_wr_data_d1_18(data)                        (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_WR_DATA_35_get_lut_wr_data_d0_18(data)                    ((0xFFFF0000&(data))>>16)
#define  DM_DM_B05_LUT_WR_DATA_35_get_lut_wr_data_d1_18(data)                    (0x0000FFFF&(data))

#define  DM_DM_B05_LUT_WR_DATA_36                                                0x1806B758
#define  DM_DM_B05_LUT_WR_DATA_36_reg_addr                                       "0xB806B758"
#define  DM_DM_B05_LUT_WR_DATA_36_reg                                            0xB806B758
#define  DM_DM_B05_LUT_WR_DATA_36_inst_addr                                      "0x008B"
#define  set_DM_DM_B05_LUT_WR_DATA_36_reg(data)                                  (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_36_reg)=data)
#define  get_DM_DM_B05_LUT_WR_DATA_36_reg                                        (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_36_reg))
#define  DM_DM_B05_LUT_WR_DATA_36_lut_wr_data_d2_18_shift                        (0)
#define  DM_DM_B05_LUT_WR_DATA_36_lut_wr_data_d2_18_mask                         (0x0000FFFF)
#define  DM_DM_B05_LUT_WR_DATA_36_lut_wr_data_d2_18(data)                        (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_WR_DATA_36_get_lut_wr_data_d2_18(data)                    (0x0000FFFF&(data))

#define  DM_DM_B05_LUT_WR_DATA_37                                                0x1806B75C
#define  DM_DM_B05_LUT_WR_DATA_37_reg_addr                                       "0xB806B75C"
#define  DM_DM_B05_LUT_WR_DATA_37_reg                                            0xB806B75C
#define  DM_DM_B05_LUT_WR_DATA_37_inst_addr                                      "0x008C"
#define  set_DM_DM_B05_LUT_WR_DATA_37_reg(data)                                  (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_37_reg)=data)
#define  get_DM_DM_B05_LUT_WR_DATA_37_reg                                        (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_37_reg))
#define  DM_DM_B05_LUT_WR_DATA_37_lut_wr_data_d0_19_shift                        (16)
#define  DM_DM_B05_LUT_WR_DATA_37_lut_wr_data_d1_19_shift                        (0)
#define  DM_DM_B05_LUT_WR_DATA_37_lut_wr_data_d0_19_mask                         (0xFFFF0000)
#define  DM_DM_B05_LUT_WR_DATA_37_lut_wr_data_d1_19_mask                         (0x0000FFFF)
#define  DM_DM_B05_LUT_WR_DATA_37_lut_wr_data_d0_19(data)                        (0xFFFF0000&((data)<<16))
#define  DM_DM_B05_LUT_WR_DATA_37_lut_wr_data_d1_19(data)                        (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_WR_DATA_37_get_lut_wr_data_d0_19(data)                    ((0xFFFF0000&(data))>>16)
#define  DM_DM_B05_LUT_WR_DATA_37_get_lut_wr_data_d1_19(data)                    (0x0000FFFF&(data))

#define  DM_DM_B05_LUT_WR_DATA_38                                                0x1806B764
#define  DM_DM_B05_LUT_WR_DATA_38_reg_addr                                       "0xB806B764"
#define  DM_DM_B05_LUT_WR_DATA_38_reg                                            0xB806B764
#define  DM_DM_B05_LUT_WR_DATA_38_inst_addr                                      "0x008D"
#define  set_DM_DM_B05_LUT_WR_DATA_38_reg(data)                                  (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_38_reg)=data)
#define  get_DM_DM_B05_LUT_WR_DATA_38_reg                                        (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_38_reg))
#define  DM_DM_B05_LUT_WR_DATA_38_lut_wr_data_d2_19_shift                        (0)
#define  DM_DM_B05_LUT_WR_DATA_38_lut_wr_data_d2_19_mask                         (0x0000FFFF)
#define  DM_DM_B05_LUT_WR_DATA_38_lut_wr_data_d2_19(data)                        (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_WR_DATA_38_get_lut_wr_data_d2_19(data)                    (0x0000FFFF&(data))

#define  DM_DM_B05_LUT_WR_DATA_39                                                0x1806B768
#define  DM_DM_B05_LUT_WR_DATA_39_reg_addr                                       "0xB806B768"
#define  DM_DM_B05_LUT_WR_DATA_39_reg                                            0xB806B768
#define  DM_DM_B05_LUT_WR_DATA_39_inst_addr                                      "0x008E"
#define  set_DM_DM_B05_LUT_WR_DATA_39_reg(data)                                  (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_39_reg)=data)
#define  get_DM_DM_B05_LUT_WR_DATA_39_reg                                        (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_39_reg))
#define  DM_DM_B05_LUT_WR_DATA_39_lut_wr_data_d0_20_shift                        (16)
#define  DM_DM_B05_LUT_WR_DATA_39_lut_wr_data_d1_20_shift                        (0)
#define  DM_DM_B05_LUT_WR_DATA_39_lut_wr_data_d0_20_mask                         (0xFFFF0000)
#define  DM_DM_B05_LUT_WR_DATA_39_lut_wr_data_d1_20_mask                         (0x0000FFFF)
#define  DM_DM_B05_LUT_WR_DATA_39_lut_wr_data_d0_20(data)                        (0xFFFF0000&((data)<<16))
#define  DM_DM_B05_LUT_WR_DATA_39_lut_wr_data_d1_20(data)                        (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_WR_DATA_39_get_lut_wr_data_d0_20(data)                    ((0xFFFF0000&(data))>>16)
#define  DM_DM_B05_LUT_WR_DATA_39_get_lut_wr_data_d1_20(data)                    (0x0000FFFF&(data))

#define  DM_DM_B05_LUT_WR_DATA_40                                                0x1806B76C
#define  DM_DM_B05_LUT_WR_DATA_40_reg_addr                                       "0xB806B76C"
#define  DM_DM_B05_LUT_WR_DATA_40_reg                                            0xB806B76C
#define  DM_DM_B05_LUT_WR_DATA_40_inst_addr                                      "0x008F"
#define  set_DM_DM_B05_LUT_WR_DATA_40_reg(data)                                  (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_40_reg)=data)
#define  get_DM_DM_B05_LUT_WR_DATA_40_reg                                        (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_40_reg))
#define  DM_DM_B05_LUT_WR_DATA_40_lut_wr_data_d2_20_shift                        (0)
#define  DM_DM_B05_LUT_WR_DATA_40_lut_wr_data_d2_20_mask                         (0x0000FFFF)
#define  DM_DM_B05_LUT_WR_DATA_40_lut_wr_data_d2_20(data)                        (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_WR_DATA_40_get_lut_wr_data_d2_20(data)                    (0x0000FFFF&(data))

#define  DM_DM_B05_LUT_WR_DATA_41                                                0x1806B770
#define  DM_DM_B05_LUT_WR_DATA_41_reg_addr                                       "0xB806B770"
#define  DM_DM_B05_LUT_WR_DATA_41_reg                                            0xB806B770
#define  DM_DM_B05_LUT_WR_DATA_41_inst_addr                                      "0x0090"
#define  set_DM_DM_B05_LUT_WR_DATA_41_reg(data)                                  (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_41_reg)=data)
#define  get_DM_DM_B05_LUT_WR_DATA_41_reg                                        (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_41_reg))
#define  DM_DM_B05_LUT_WR_DATA_41_lut_wr_data_d0_21_shift                        (16)
#define  DM_DM_B05_LUT_WR_DATA_41_lut_wr_data_d1_21_shift                        (0)
#define  DM_DM_B05_LUT_WR_DATA_41_lut_wr_data_d0_21_mask                         (0xFFFF0000)
#define  DM_DM_B05_LUT_WR_DATA_41_lut_wr_data_d1_21_mask                         (0x0000FFFF)
#define  DM_DM_B05_LUT_WR_DATA_41_lut_wr_data_d0_21(data)                        (0xFFFF0000&((data)<<16))
#define  DM_DM_B05_LUT_WR_DATA_41_lut_wr_data_d1_21(data)                        (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_WR_DATA_41_get_lut_wr_data_d0_21(data)                    ((0xFFFF0000&(data))>>16)
#define  DM_DM_B05_LUT_WR_DATA_41_get_lut_wr_data_d1_21(data)                    (0x0000FFFF&(data))

#define  DM_DM_B05_LUT_WR_DATA_42                                                0x1806B774
#define  DM_DM_B05_LUT_WR_DATA_42_reg_addr                                       "0xB806B774"
#define  DM_DM_B05_LUT_WR_DATA_42_reg                                            0xB806B774
#define  DM_DM_B05_LUT_WR_DATA_42_inst_addr                                      "0x0091"
#define  set_DM_DM_B05_LUT_WR_DATA_42_reg(data)                                  (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_42_reg)=data)
#define  get_DM_DM_B05_LUT_WR_DATA_42_reg                                        (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_42_reg))
#define  DM_DM_B05_LUT_WR_DATA_42_lut_wr_data_d2_21_shift                        (0)
#define  DM_DM_B05_LUT_WR_DATA_42_lut_wr_data_d2_21_mask                         (0x0000FFFF)
#define  DM_DM_B05_LUT_WR_DATA_42_lut_wr_data_d2_21(data)                        (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_WR_DATA_42_get_lut_wr_data_d2_21(data)                    (0x0000FFFF&(data))

#define  DM_DM_B05_LUT_WR_DATA_43                                                0x1806B778
#define  DM_DM_B05_LUT_WR_DATA_43_reg_addr                                       "0xB806B778"
#define  DM_DM_B05_LUT_WR_DATA_43_reg                                            0xB806B778
#define  DM_DM_B05_LUT_WR_DATA_43_inst_addr                                      "0x0092"
#define  set_DM_DM_B05_LUT_WR_DATA_43_reg(data)                                  (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_43_reg)=data)
#define  get_DM_DM_B05_LUT_WR_DATA_43_reg                                        (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_43_reg))
#define  DM_DM_B05_LUT_WR_DATA_43_lut_wr_data_d0_22_shift                        (16)
#define  DM_DM_B05_LUT_WR_DATA_43_lut_wr_data_d1_22_shift                        (0)
#define  DM_DM_B05_LUT_WR_DATA_43_lut_wr_data_d0_22_mask                         (0xFFFF0000)
#define  DM_DM_B05_LUT_WR_DATA_43_lut_wr_data_d1_22_mask                         (0x0000FFFF)
#define  DM_DM_B05_LUT_WR_DATA_43_lut_wr_data_d0_22(data)                        (0xFFFF0000&((data)<<16))
#define  DM_DM_B05_LUT_WR_DATA_43_lut_wr_data_d1_22(data)                        (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_WR_DATA_43_get_lut_wr_data_d0_22(data)                    ((0xFFFF0000&(data))>>16)
#define  DM_DM_B05_LUT_WR_DATA_43_get_lut_wr_data_d1_22(data)                    (0x0000FFFF&(data))

#define  DM_DM_B05_LUT_WR_DATA_44                                                0x1806B77C
#define  DM_DM_B05_LUT_WR_DATA_44_reg_addr                                       "0xB806B77C"
#define  DM_DM_B05_LUT_WR_DATA_44_reg                                            0xB806B77C
#define  DM_DM_B05_LUT_WR_DATA_44_inst_addr                                      "0x0093"
#define  set_DM_DM_B05_LUT_WR_DATA_44_reg(data)                                  (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_44_reg)=data)
#define  get_DM_DM_B05_LUT_WR_DATA_44_reg                                        (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_44_reg))
#define  DM_DM_B05_LUT_WR_DATA_44_lut_wr_data_d2_22_shift                        (0)
#define  DM_DM_B05_LUT_WR_DATA_44_lut_wr_data_d2_22_mask                         (0x0000FFFF)
#define  DM_DM_B05_LUT_WR_DATA_44_lut_wr_data_d2_22(data)                        (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_WR_DATA_44_get_lut_wr_data_d2_22(data)                    (0x0000FFFF&(data))

#define  DM_DM_B05_LUT_WR_DATA_45                                                0x1806B780
#define  DM_DM_B05_LUT_WR_DATA_45_reg_addr                                       "0xB806B780"
#define  DM_DM_B05_LUT_WR_DATA_45_reg                                            0xB806B780
#define  DM_DM_B05_LUT_WR_DATA_45_inst_addr                                      "0x0094"
#define  set_DM_DM_B05_LUT_WR_DATA_45_reg(data)                                  (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_45_reg)=data)
#define  get_DM_DM_B05_LUT_WR_DATA_45_reg                                        (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_45_reg))
#define  DM_DM_B05_LUT_WR_DATA_45_lut_wr_data_d0_23_shift                        (16)
#define  DM_DM_B05_LUT_WR_DATA_45_lut_wr_data_d1_23_shift                        (0)
#define  DM_DM_B05_LUT_WR_DATA_45_lut_wr_data_d0_23_mask                         (0xFFFF0000)
#define  DM_DM_B05_LUT_WR_DATA_45_lut_wr_data_d1_23_mask                         (0x0000FFFF)
#define  DM_DM_B05_LUT_WR_DATA_45_lut_wr_data_d0_23(data)                        (0xFFFF0000&((data)<<16))
#define  DM_DM_B05_LUT_WR_DATA_45_lut_wr_data_d1_23(data)                        (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_WR_DATA_45_get_lut_wr_data_d0_23(data)                    ((0xFFFF0000&(data))>>16)
#define  DM_DM_B05_LUT_WR_DATA_45_get_lut_wr_data_d1_23(data)                    (0x0000FFFF&(data))

#define  DM_DM_B05_LUT_WR_DATA_46                                                0x1806B784
#define  DM_DM_B05_LUT_WR_DATA_46_reg_addr                                       "0xB806B784"
#define  DM_DM_B05_LUT_WR_DATA_46_reg                                            0xB806B784
#define  DM_DM_B05_LUT_WR_DATA_46_inst_addr                                      "0x0095"
#define  set_DM_DM_B05_LUT_WR_DATA_46_reg(data)                                  (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_46_reg)=data)
#define  get_DM_DM_B05_LUT_WR_DATA_46_reg                                        (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_46_reg))
#define  DM_DM_B05_LUT_WR_DATA_46_lut_wr_data_d2_23_shift                        (0)
#define  DM_DM_B05_LUT_WR_DATA_46_lut_wr_data_d2_23_mask                         (0x0000FFFF)
#define  DM_DM_B05_LUT_WR_DATA_46_lut_wr_data_d2_23(data)                        (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_WR_DATA_46_get_lut_wr_data_d2_23(data)                    (0x0000FFFF&(data))

#define  DM_DM_B05_LUT_WR_DATA_47                                                0x1806B788
#define  DM_DM_B05_LUT_WR_DATA_47_reg_addr                                       "0xB806B788"
#define  DM_DM_B05_LUT_WR_DATA_47_reg                                            0xB806B788
#define  DM_DM_B05_LUT_WR_DATA_47_inst_addr                                      "0x0096"
#define  set_DM_DM_B05_LUT_WR_DATA_47_reg(data)                                  (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_47_reg)=data)
#define  get_DM_DM_B05_LUT_WR_DATA_47_reg                                        (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_47_reg))
#define  DM_DM_B05_LUT_WR_DATA_47_lut_wr_data_d0_24_shift                        (16)
#define  DM_DM_B05_LUT_WR_DATA_47_lut_wr_data_d1_24_shift                        (0)
#define  DM_DM_B05_LUT_WR_DATA_47_lut_wr_data_d0_24_mask                         (0xFFFF0000)
#define  DM_DM_B05_LUT_WR_DATA_47_lut_wr_data_d1_24_mask                         (0x0000FFFF)
#define  DM_DM_B05_LUT_WR_DATA_47_lut_wr_data_d0_24(data)                        (0xFFFF0000&((data)<<16))
#define  DM_DM_B05_LUT_WR_DATA_47_lut_wr_data_d1_24(data)                        (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_WR_DATA_47_get_lut_wr_data_d0_24(data)                    ((0xFFFF0000&(data))>>16)
#define  DM_DM_B05_LUT_WR_DATA_47_get_lut_wr_data_d1_24(data)                    (0x0000FFFF&(data))

#define  DM_DM_B05_LUT_WR_DATA_48                                                0x1806B78C
#define  DM_DM_B05_LUT_WR_DATA_48_reg_addr                                       "0xB806B78C"
#define  DM_DM_B05_LUT_WR_DATA_48_reg                                            0xB806B78C
#define  DM_DM_B05_LUT_WR_DATA_48_inst_addr                                      "0x0097"
#define  set_DM_DM_B05_LUT_WR_DATA_48_reg(data)                                  (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_48_reg)=data)
#define  get_DM_DM_B05_LUT_WR_DATA_48_reg                                        (*((volatile unsigned int*)DM_DM_B05_LUT_WR_DATA_48_reg))
#define  DM_DM_B05_LUT_WR_DATA_48_lut_wr_data_d2_24_shift                        (0)
#define  DM_DM_B05_LUT_WR_DATA_48_lut_wr_data_d2_24_mask                         (0x0000FFFF)
#define  DM_DM_B05_LUT_WR_DATA_48_lut_wr_data_d2_24(data)                        (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_WR_DATA_48_get_lut_wr_data_d2_24(data)                    (0x0000FFFF&(data))

#define  DM_DM_B05_LUT_RD_DATA_35                                                0x1806B790
#define  DM_DM_B05_LUT_RD_DATA_35_reg_addr                                       "0xB806B790"
#define  DM_DM_B05_LUT_RD_DATA_35_reg                                            0xB806B790
#define  DM_DM_B05_LUT_RD_DATA_35_inst_addr                                      "0x0098"
#define  set_DM_DM_B05_LUT_RD_DATA_35_reg(data)                                  (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_35_reg)=data)
#define  get_DM_DM_B05_LUT_RD_DATA_35_reg                                        (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_35_reg))
#define  DM_DM_B05_LUT_RD_DATA_35_lut_rd_data_d0_18_shift                        (16)
#define  DM_DM_B05_LUT_RD_DATA_35_lut_rd_data_d1_18_shift                        (0)
#define  DM_DM_B05_LUT_RD_DATA_35_lut_rd_data_d0_18_mask                         (0xFFFF0000)
#define  DM_DM_B05_LUT_RD_DATA_35_lut_rd_data_d1_18_mask                         (0x0000FFFF)
#define  DM_DM_B05_LUT_RD_DATA_35_lut_rd_data_d0_18(data)                        (0xFFFF0000&((data)<<16))
#define  DM_DM_B05_LUT_RD_DATA_35_lut_rd_data_d1_18(data)                        (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_RD_DATA_35_get_lut_rd_data_d0_18(data)                    ((0xFFFF0000&(data))>>16)
#define  DM_DM_B05_LUT_RD_DATA_35_get_lut_rd_data_d1_18(data)                    (0x0000FFFF&(data))

#define  DM_DM_B05_LUT_RD_DATA_36                                                0x1806B794
#define  DM_DM_B05_LUT_RD_DATA_36_reg_addr                                       "0xB806B794"
#define  DM_DM_B05_LUT_RD_DATA_36_reg                                            0xB806B794
#define  DM_DM_B05_LUT_RD_DATA_36_inst_addr                                      "0x0099"
#define  set_DM_DM_B05_LUT_RD_DATA_36_reg(data)                                  (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_36_reg)=data)
#define  get_DM_DM_B05_LUT_RD_DATA_36_reg                                        (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_36_reg))
#define  DM_DM_B05_LUT_RD_DATA_36_lut_rd_data_d2_18_shift                        (0)
#define  DM_DM_B05_LUT_RD_DATA_36_lut_rd_data_d2_18_mask                         (0x0000FFFF)
#define  DM_DM_B05_LUT_RD_DATA_36_lut_rd_data_d2_18(data)                        (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_RD_DATA_36_get_lut_rd_data_d2_18(data)                    (0x0000FFFF&(data))

#define  DM_DM_B05_LUT_RD_DATA_37                                                0x1806B798
#define  DM_DM_B05_LUT_RD_DATA_37_reg_addr                                       "0xB806B798"
#define  DM_DM_B05_LUT_RD_DATA_37_reg                                            0xB806B798
#define  DM_DM_B05_LUT_RD_DATA_37_inst_addr                                      "0x009A"
#define  set_DM_DM_B05_LUT_RD_DATA_37_reg(data)                                  (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_37_reg)=data)
#define  get_DM_DM_B05_LUT_RD_DATA_37_reg                                        (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_37_reg))
#define  DM_DM_B05_LUT_RD_DATA_37_lut_rd_data_d0_19_shift                        (16)
#define  DM_DM_B05_LUT_RD_DATA_37_lut_rd_data_d1_19_shift                        (0)
#define  DM_DM_B05_LUT_RD_DATA_37_lut_rd_data_d0_19_mask                         (0xFFFF0000)
#define  DM_DM_B05_LUT_RD_DATA_37_lut_rd_data_d1_19_mask                         (0x0000FFFF)
#define  DM_DM_B05_LUT_RD_DATA_37_lut_rd_data_d0_19(data)                        (0xFFFF0000&((data)<<16))
#define  DM_DM_B05_LUT_RD_DATA_37_lut_rd_data_d1_19(data)                        (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_RD_DATA_37_get_lut_rd_data_d0_19(data)                    ((0xFFFF0000&(data))>>16)
#define  DM_DM_B05_LUT_RD_DATA_37_get_lut_rd_data_d1_19(data)                    (0x0000FFFF&(data))

#define  DM_DM_B05_LUT_RD_DATA_38                                                0x1806B79C
#define  DM_DM_B05_LUT_RD_DATA_38_reg_addr                                       "0xB806B79C"
#define  DM_DM_B05_LUT_RD_DATA_38_reg                                            0xB806B79C
#define  DM_DM_B05_LUT_RD_DATA_38_inst_addr                                      "0x009B"
#define  set_DM_DM_B05_LUT_RD_DATA_38_reg(data)                                  (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_38_reg)=data)
#define  get_DM_DM_B05_LUT_RD_DATA_38_reg                                        (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_38_reg))
#define  DM_DM_B05_LUT_RD_DATA_38_lut_rd_data_d2_19_shift                        (0)
#define  DM_DM_B05_LUT_RD_DATA_38_lut_rd_data_d2_19_mask                         (0x0000FFFF)
#define  DM_DM_B05_LUT_RD_DATA_38_lut_rd_data_d2_19(data)                        (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_RD_DATA_38_get_lut_rd_data_d2_19(data)                    (0x0000FFFF&(data))

#define  DM_DM_B05_LUT_RD_DATA_39                                                0x1806B7A0
#define  DM_DM_B05_LUT_RD_DATA_39_reg_addr                                       "0xB806B7A0"
#define  DM_DM_B05_LUT_RD_DATA_39_reg                                            0xB806B7A0
#define  DM_DM_B05_LUT_RD_DATA_39_inst_addr                                      "0x009C"
#define  set_DM_DM_B05_LUT_RD_DATA_39_reg(data)                                  (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_39_reg)=data)
#define  get_DM_DM_B05_LUT_RD_DATA_39_reg                                        (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_39_reg))
#define  DM_DM_B05_LUT_RD_DATA_39_lut_rd_data_d0_20_shift                        (16)
#define  DM_DM_B05_LUT_RD_DATA_39_lut_rd_data_d1_20_shift                        (0)
#define  DM_DM_B05_LUT_RD_DATA_39_lut_rd_data_d0_20_mask                         (0xFFFF0000)
#define  DM_DM_B05_LUT_RD_DATA_39_lut_rd_data_d1_20_mask                         (0x0000FFFF)
#define  DM_DM_B05_LUT_RD_DATA_39_lut_rd_data_d0_20(data)                        (0xFFFF0000&((data)<<16))
#define  DM_DM_B05_LUT_RD_DATA_39_lut_rd_data_d1_20(data)                        (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_RD_DATA_39_get_lut_rd_data_d0_20(data)                    ((0xFFFF0000&(data))>>16)
#define  DM_DM_B05_LUT_RD_DATA_39_get_lut_rd_data_d1_20(data)                    (0x0000FFFF&(data))

#define  DM_DM_B05_LUT_RD_DATA_40                                                0x1806B7A4
#define  DM_DM_B05_LUT_RD_DATA_40_reg_addr                                       "0xB806B7A4"
#define  DM_DM_B05_LUT_RD_DATA_40_reg                                            0xB806B7A4
#define  DM_DM_B05_LUT_RD_DATA_40_inst_addr                                      "0x009D"
#define  set_DM_DM_B05_LUT_RD_DATA_40_reg(data)                                  (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_40_reg)=data)
#define  get_DM_DM_B05_LUT_RD_DATA_40_reg                                        (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_40_reg))
#define  DM_DM_B05_LUT_RD_DATA_40_lut_rd_data_d2_20_shift                        (0)
#define  DM_DM_B05_LUT_RD_DATA_40_lut_rd_data_d2_20_mask                         (0x0000FFFF)
#define  DM_DM_B05_LUT_RD_DATA_40_lut_rd_data_d2_20(data)                        (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_RD_DATA_40_get_lut_rd_data_d2_20(data)                    (0x0000FFFF&(data))

#define  DM_DM_B05_LUT_RD_DATA_41                                                0x1806B7A8
#define  DM_DM_B05_LUT_RD_DATA_41_reg_addr                                       "0xB806B7A8"
#define  DM_DM_B05_LUT_RD_DATA_41_reg                                            0xB806B7A8
#define  DM_DM_B05_LUT_RD_DATA_41_inst_addr                                      "0x009E"
#define  set_DM_DM_B05_LUT_RD_DATA_41_reg(data)                                  (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_41_reg)=data)
#define  get_DM_DM_B05_LUT_RD_DATA_41_reg                                        (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_41_reg))
#define  DM_DM_B05_LUT_RD_DATA_41_lut_rd_data_d0_21_shift                        (16)
#define  DM_DM_B05_LUT_RD_DATA_41_lut_rd_data_d1_21_shift                        (0)
#define  DM_DM_B05_LUT_RD_DATA_41_lut_rd_data_d0_21_mask                         (0xFFFF0000)
#define  DM_DM_B05_LUT_RD_DATA_41_lut_rd_data_d1_21_mask                         (0x0000FFFF)
#define  DM_DM_B05_LUT_RD_DATA_41_lut_rd_data_d0_21(data)                        (0xFFFF0000&((data)<<16))
#define  DM_DM_B05_LUT_RD_DATA_41_lut_rd_data_d1_21(data)                        (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_RD_DATA_41_get_lut_rd_data_d0_21(data)                    ((0xFFFF0000&(data))>>16)
#define  DM_DM_B05_LUT_RD_DATA_41_get_lut_rd_data_d1_21(data)                    (0x0000FFFF&(data))

#define  DM_DM_B05_LUT_RD_DATA_42                                                0x1806B7AC
#define  DM_DM_B05_LUT_RD_DATA_42_reg_addr                                       "0xB806B7AC"
#define  DM_DM_B05_LUT_RD_DATA_42_reg                                            0xB806B7AC
#define  DM_DM_B05_LUT_RD_DATA_42_inst_addr                                      "0x009F"
#define  set_DM_DM_B05_LUT_RD_DATA_42_reg(data)                                  (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_42_reg)=data)
#define  get_DM_DM_B05_LUT_RD_DATA_42_reg                                        (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_42_reg))
#define  DM_DM_B05_LUT_RD_DATA_42_lut_rd_data_d2_21_shift                        (0)
#define  DM_DM_B05_LUT_RD_DATA_42_lut_rd_data_d2_21_mask                         (0x0000FFFF)
#define  DM_DM_B05_LUT_RD_DATA_42_lut_rd_data_d2_21(data)                        (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_RD_DATA_42_get_lut_rd_data_d2_21(data)                    (0x0000FFFF&(data))

#define  DM_DM_B05_LUT_RD_DATA_43                                                0x1806B7B0
#define  DM_DM_B05_LUT_RD_DATA_43_reg_addr                                       "0xB806B7B0"
#define  DM_DM_B05_LUT_RD_DATA_43_reg                                            0xB806B7B0
#define  DM_DM_B05_LUT_RD_DATA_43_inst_addr                                      "0x00A0"
#define  set_DM_DM_B05_LUT_RD_DATA_43_reg(data)                                  (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_43_reg)=data)
#define  get_DM_DM_B05_LUT_RD_DATA_43_reg                                        (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_43_reg))
#define  DM_DM_B05_LUT_RD_DATA_43_lut_rd_data_d0_22_shift                        (16)
#define  DM_DM_B05_LUT_RD_DATA_43_lut_rd_data_d1_22_shift                        (0)
#define  DM_DM_B05_LUT_RD_DATA_43_lut_rd_data_d0_22_mask                         (0xFFFF0000)
#define  DM_DM_B05_LUT_RD_DATA_43_lut_rd_data_d1_22_mask                         (0x0000FFFF)
#define  DM_DM_B05_LUT_RD_DATA_43_lut_rd_data_d0_22(data)                        (0xFFFF0000&((data)<<16))
#define  DM_DM_B05_LUT_RD_DATA_43_lut_rd_data_d1_22(data)                        (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_RD_DATA_43_get_lut_rd_data_d0_22(data)                    ((0xFFFF0000&(data))>>16)
#define  DM_DM_B05_LUT_RD_DATA_43_get_lut_rd_data_d1_22(data)                    (0x0000FFFF&(data))

#define  DM_DM_B05_LUT_RD_DATA_44                                                0x1806B7B4
#define  DM_DM_B05_LUT_RD_DATA_44_reg_addr                                       "0xB806B7B4"
#define  DM_DM_B05_LUT_RD_DATA_44_reg                                            0xB806B7B4
#define  DM_DM_B05_LUT_RD_DATA_44_inst_addr                                      "0x00A1"
#define  set_DM_DM_B05_LUT_RD_DATA_44_reg(data)                                  (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_44_reg)=data)
#define  get_DM_DM_B05_LUT_RD_DATA_44_reg                                        (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_44_reg))
#define  DM_DM_B05_LUT_RD_DATA_44_lut_rd_data_d2_22_shift                        (0)
#define  DM_DM_B05_LUT_RD_DATA_44_lut_rd_data_d2_22_mask                         (0x0000FFFF)
#define  DM_DM_B05_LUT_RD_DATA_44_lut_rd_data_d2_22(data)                        (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_RD_DATA_44_get_lut_rd_data_d2_22(data)                    (0x0000FFFF&(data))

#define  DM_DM_B05_LUT_RD_DATA_45                                                0x1806B7B8
#define  DM_DM_B05_LUT_RD_DATA_45_reg_addr                                       "0xB806B7B8"
#define  DM_DM_B05_LUT_RD_DATA_45_reg                                            0xB806B7B8
#define  DM_DM_B05_LUT_RD_DATA_45_inst_addr                                      "0x00A2"
#define  set_DM_DM_B05_LUT_RD_DATA_45_reg(data)                                  (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_45_reg)=data)
#define  get_DM_DM_B05_LUT_RD_DATA_45_reg                                        (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_45_reg))
#define  DM_DM_B05_LUT_RD_DATA_45_lut_rd_data_d0_23_shift                        (16)
#define  DM_DM_B05_LUT_RD_DATA_45_lut_rd_data_d1_23_shift                        (0)
#define  DM_DM_B05_LUT_RD_DATA_45_lut_rd_data_d0_23_mask                         (0xFFFF0000)
#define  DM_DM_B05_LUT_RD_DATA_45_lut_rd_data_d1_23_mask                         (0x0000FFFF)
#define  DM_DM_B05_LUT_RD_DATA_45_lut_rd_data_d0_23(data)                        (0xFFFF0000&((data)<<16))
#define  DM_DM_B05_LUT_RD_DATA_45_lut_rd_data_d1_23(data)                        (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_RD_DATA_45_get_lut_rd_data_d0_23(data)                    ((0xFFFF0000&(data))>>16)
#define  DM_DM_B05_LUT_RD_DATA_45_get_lut_rd_data_d1_23(data)                    (0x0000FFFF&(data))

#define  DM_DM_B05_LUT_RD_DATA_46                                                0x1806B7BC
#define  DM_DM_B05_LUT_RD_DATA_46_reg_addr                                       "0xB806B7BC"
#define  DM_DM_B05_LUT_RD_DATA_46_reg                                            0xB806B7BC
#define  DM_DM_B05_LUT_RD_DATA_46_inst_addr                                      "0x00A3"
#define  set_DM_DM_B05_LUT_RD_DATA_46_reg(data)                                  (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_46_reg)=data)
#define  get_DM_DM_B05_LUT_RD_DATA_46_reg                                        (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_46_reg))
#define  DM_DM_B05_LUT_RD_DATA_46_lut_rd_data_d2_23_shift                        (0)
#define  DM_DM_B05_LUT_RD_DATA_46_lut_rd_data_d2_23_mask                         (0x0000FFFF)
#define  DM_DM_B05_LUT_RD_DATA_46_lut_rd_data_d2_23(data)                        (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_RD_DATA_46_get_lut_rd_data_d2_23(data)                    (0x0000FFFF&(data))

#define  DM_DM_B05_LUT_RD_DATA_47                                                0x1806B7C0
#define  DM_DM_B05_LUT_RD_DATA_47_reg_addr                                       "0xB806B7C0"
#define  DM_DM_B05_LUT_RD_DATA_47_reg                                            0xB806B7C0
#define  DM_DM_B05_LUT_RD_DATA_47_inst_addr                                      "0x00A4"
#define  set_DM_DM_B05_LUT_RD_DATA_47_reg(data)                                  (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_47_reg)=data)
#define  get_DM_DM_B05_LUT_RD_DATA_47_reg                                        (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_47_reg))
#define  DM_DM_B05_LUT_RD_DATA_47_lut_rd_data_d0_24_shift                        (16)
#define  DM_DM_B05_LUT_RD_DATA_47_lut_rd_data_d1_24_shift                        (0)
#define  DM_DM_B05_LUT_RD_DATA_47_lut_rd_data_d0_24_mask                         (0xFFFF0000)
#define  DM_DM_B05_LUT_RD_DATA_47_lut_rd_data_d1_24_mask                         (0x0000FFFF)
#define  DM_DM_B05_LUT_RD_DATA_47_lut_rd_data_d0_24(data)                        (0xFFFF0000&((data)<<16))
#define  DM_DM_B05_LUT_RD_DATA_47_lut_rd_data_d1_24(data)                        (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_RD_DATA_47_get_lut_rd_data_d0_24(data)                    ((0xFFFF0000&(data))>>16)
#define  DM_DM_B05_LUT_RD_DATA_47_get_lut_rd_data_d1_24(data)                    (0x0000FFFF&(data))

#define  DM_DM_B05_LUT_RD_DATA_48                                                0x1806B7C4
#define  DM_DM_B05_LUT_RD_DATA_48_reg_addr                                       "0xB806B7C4"
#define  DM_DM_B05_LUT_RD_DATA_48_reg                                            0xB806B7C4
#define  DM_DM_B05_LUT_RD_DATA_48_inst_addr                                      "0x00A5"
#define  set_DM_DM_B05_LUT_RD_DATA_48_reg(data)                                  (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_48_reg)=data)
#define  get_DM_DM_B05_LUT_RD_DATA_48_reg                                        (*((volatile unsigned int*)DM_DM_B05_LUT_RD_DATA_48_reg))
#define  DM_DM_B05_LUT_RD_DATA_48_lut_rd_data_d2_24_shift                        (0)
#define  DM_DM_B05_LUT_RD_DATA_48_lut_rd_data_d2_24_mask                         (0x0000FFFF)
#define  DM_DM_B05_LUT_RD_DATA_48_lut_rd_data_d2_24(data)                        (0x0000FFFF&(data))
#define  DM_DM_B05_LUT_RD_DATA_48_get_lut_rd_data_d2_24(data)                    (0x0000FFFF&(data))

#define  DM_HDR_DM_Double_Buffer_CTRL                                            0x1806B714
#define  DM_HDR_DM_Double_Buffer_CTRL_reg_addr                                   "0xB806B714"
#define  DM_HDR_DM_Double_Buffer_CTRL_reg                                        0xB806B714
#define  DM_HDR_DM_Double_Buffer_CTRL_inst_addr                                  "0x00A6"
#define  set_DM_HDR_DM_Double_Buffer_CTRL_reg(data)                              (*((volatile unsigned int*)DM_HDR_DM_Double_Buffer_CTRL_reg)=data)
#define  get_DM_HDR_DM_Double_Buffer_CTRL_reg                                    (*((volatile unsigned int*)DM_HDR_DM_Double_Buffer_CTRL_reg))
#define  DM_HDR_DM_Double_Buffer_CTRL_dm_db_en_shift                             (2)
#define  DM_HDR_DM_Double_Buffer_CTRL_dm_db_read_sel_shift                       (1)
#define  DM_HDR_DM_Double_Buffer_CTRL_dm_db_apply_shift                          (0)
#define  DM_HDR_DM_Double_Buffer_CTRL_dm_db_en_mask                              (0x00000004)
#define  DM_HDR_DM_Double_Buffer_CTRL_dm_db_read_sel_mask                        (0x00000002)
#define  DM_HDR_DM_Double_Buffer_CTRL_dm_db_apply_mask                           (0x00000001)
#define  DM_HDR_DM_Double_Buffer_CTRL_dm_db_en(data)                             (0x00000004&((data)<<2))
#define  DM_HDR_DM_Double_Buffer_CTRL_dm_db_read_sel(data)                       (0x00000002&((data)<<1))
#define  DM_HDR_DM_Double_Buffer_CTRL_dm_db_apply(data)                          (0x00000001&(data))
#define  DM_HDR_DM_Double_Buffer_CTRL_get_dm_db_en(data)                         ((0x00000004&(data))>>2)
#define  DM_HDR_DM_Double_Buffer_CTRL_get_dm_db_read_sel(data)                   ((0x00000002&(data))>>1)
#define  DM_HDR_DM_Double_Buffer_CTRL_get_dm_db_apply(data)                      (0x00000001&(data))

#define  DM_DM_B01_1_MBIST                                                       0x1806B718
#define  DM_DM_B01_1_MBIST_reg_addr                                              "0xB806B718"
#define  DM_DM_B01_1_MBIST_reg                                                   0xB806B718
#define  DM_DM_B01_1_MBIST_inst_addr                                             "0x00A7"
#define  set_DM_DM_B01_1_MBIST_reg(data)                                         (*((volatile unsigned int*)DM_DM_B01_1_MBIST_reg)=data)
#define  get_DM_DM_B01_1_MBIST_reg                                               (*((volatile unsigned int*)DM_DM_B01_1_MBIST_reg))
#define  DM_DM_B01_1_MBIST_dm_b01_1_ls_shift                                     (31)
#define  DM_DM_B01_1_MBIST_dm_b01_1_rme_shift                                    (30)
#define  DM_DM_B01_1_MBIST_dm_b01_1_rm_shift                                     (26)
#define  DM_DM_B01_1_MBIST_dm_b01_1_bist_fail_4_shift                            (12)
#define  DM_DM_B01_1_MBIST_dm_b01_1_bist_fail_3_shift                            (11)
#define  DM_DM_B01_1_MBIST_dm_b01_1_bist_fail_2_shift                            (10)
#define  DM_DM_B01_1_MBIST_dm_b01_1_bist_fail_1_shift                            (9)
#define  DM_DM_B01_1_MBIST_dm_b01_1_bist_fail_0_shift                            (8)
#define  DM_DM_B01_1_MBIST_dm_b01_1_drf_bist_fail_4_shift                        (4)
#define  DM_DM_B01_1_MBIST_dm_b01_1_drf_bist_fail_3_shift                        (3)
#define  DM_DM_B01_1_MBIST_dm_b01_1_drf_bist_fail_2_shift                        (2)
#define  DM_DM_B01_1_MBIST_dm_b01_1_drf_bist_fail_1_shift                        (1)
#define  DM_DM_B01_1_MBIST_dm_b01_1_drf_bist_fail_0_shift                        (0)
#define  DM_DM_B01_1_MBIST_dm_b01_1_ls_mask                                      (0x80000000)
#define  DM_DM_B01_1_MBIST_dm_b01_1_rme_mask                                     (0x40000000)
#define  DM_DM_B01_1_MBIST_dm_b01_1_rm_mask                                      (0x3C000000)
#define  DM_DM_B01_1_MBIST_dm_b01_1_bist_fail_4_mask                             (0x00001000)
#define  DM_DM_B01_1_MBIST_dm_b01_1_bist_fail_3_mask                             (0x00000800)
#define  DM_DM_B01_1_MBIST_dm_b01_1_bist_fail_2_mask                             (0x00000400)
#define  DM_DM_B01_1_MBIST_dm_b01_1_bist_fail_1_mask                             (0x00000200)
#define  DM_DM_B01_1_MBIST_dm_b01_1_bist_fail_0_mask                             (0x00000100)
#define  DM_DM_B01_1_MBIST_dm_b01_1_drf_bist_fail_4_mask                         (0x00000010)
#define  DM_DM_B01_1_MBIST_dm_b01_1_drf_bist_fail_3_mask                         (0x00000008)
#define  DM_DM_B01_1_MBIST_dm_b01_1_drf_bist_fail_2_mask                         (0x00000004)
#define  DM_DM_B01_1_MBIST_dm_b01_1_drf_bist_fail_1_mask                         (0x00000002)
#define  DM_DM_B01_1_MBIST_dm_b01_1_drf_bist_fail_0_mask                         (0x00000001)
#define  DM_DM_B01_1_MBIST_dm_b01_1_ls(data)                                     (0x80000000&((data)<<31))
#define  DM_DM_B01_1_MBIST_dm_b01_1_rme(data)                                    (0x40000000&((data)<<30))
#define  DM_DM_B01_1_MBIST_dm_b01_1_rm(data)                                     (0x3C000000&((data)<<26))
#define  DM_DM_B01_1_MBIST_dm_b01_1_bist_fail_4(data)                            (0x00001000&((data)<<12))
#define  DM_DM_B01_1_MBIST_dm_b01_1_bist_fail_3(data)                            (0x00000800&((data)<<11))
#define  DM_DM_B01_1_MBIST_dm_b01_1_bist_fail_2(data)                            (0x00000400&((data)<<10))
#define  DM_DM_B01_1_MBIST_dm_b01_1_bist_fail_1(data)                            (0x00000200&((data)<<9))
#define  DM_DM_B01_1_MBIST_dm_b01_1_bist_fail_0(data)                            (0x00000100&((data)<<8))
#define  DM_DM_B01_1_MBIST_dm_b01_1_drf_bist_fail_4(data)                        (0x00000010&((data)<<4))
#define  DM_DM_B01_1_MBIST_dm_b01_1_drf_bist_fail_3(data)                        (0x00000008&((data)<<3))
#define  DM_DM_B01_1_MBIST_dm_b01_1_drf_bist_fail_2(data)                        (0x00000004&((data)<<2))
#define  DM_DM_B01_1_MBIST_dm_b01_1_drf_bist_fail_1(data)                        (0x00000002&((data)<<1))
#define  DM_DM_B01_1_MBIST_dm_b01_1_drf_bist_fail_0(data)                        (0x00000001&(data))
#define  DM_DM_B01_1_MBIST_get_dm_b01_1_ls(data)                                 ((0x80000000&(data))>>31)
#define  DM_DM_B01_1_MBIST_get_dm_b01_1_rme(data)                                ((0x40000000&(data))>>30)
#define  DM_DM_B01_1_MBIST_get_dm_b01_1_rm(data)                                 ((0x3C000000&(data))>>26)
#define  DM_DM_B01_1_MBIST_get_dm_b01_1_bist_fail_4(data)                        ((0x00001000&(data))>>12)
#define  DM_DM_B01_1_MBIST_get_dm_b01_1_bist_fail_3(data)                        ((0x00000800&(data))>>11)
#define  DM_DM_B01_1_MBIST_get_dm_b01_1_bist_fail_2(data)                        ((0x00000400&(data))>>10)
#define  DM_DM_B01_1_MBIST_get_dm_b01_1_bist_fail_1(data)                        ((0x00000200&(data))>>9)
#define  DM_DM_B01_1_MBIST_get_dm_b01_1_bist_fail_0(data)                        ((0x00000100&(data))>>8)
#define  DM_DM_B01_1_MBIST_get_dm_b01_1_drf_bist_fail_4(data)                    ((0x00000010&(data))>>4)
#define  DM_DM_B01_1_MBIST_get_dm_b01_1_drf_bist_fail_3(data)                    ((0x00000008&(data))>>3)
#define  DM_DM_B01_1_MBIST_get_dm_b01_1_drf_bist_fail_2(data)                    ((0x00000004&(data))>>2)
#define  DM_DM_B01_1_MBIST_get_dm_b01_1_drf_bist_fail_1(data)                    ((0x00000002&(data))>>1)
#define  DM_DM_B01_1_MBIST_get_dm_b01_1_drf_bist_fail_0(data)                    (0x00000001&(data))

#define  DM_DM_B01_2_0_MBIST                                                     0x1806B710
#define  DM_DM_B01_2_0_MBIST_reg_addr                                            "0xB806B710"
#define  DM_DM_B01_2_0_MBIST_reg                                                 0xB806B710
#define  DM_DM_B01_2_0_MBIST_inst_addr                                           "0x00A8"
#define  set_DM_DM_B01_2_0_MBIST_reg(data)                                       (*((volatile unsigned int*)DM_DM_B01_2_0_MBIST_reg)=data)
#define  get_DM_DM_B01_2_0_MBIST_reg                                             (*((volatile unsigned int*)DM_DM_B01_2_0_MBIST_reg))
#define  DM_DM_B01_2_0_MBIST_dm_b01_2_0_ls_shift                                 (31)
#define  DM_DM_B01_2_0_MBIST_dm_b01_2_0_rme_shift                                (30)
#define  DM_DM_B01_2_0_MBIST_dm_b01_2_0_rm_shift                                 (26)
#define  DM_DM_B01_2_0_MBIST_dm_b01_2_0_bist_fail_5_shift                        (13)
#define  DM_DM_B01_2_0_MBIST_dm_b01_2_0_bist_fail_4_shift                        (12)
#define  DM_DM_B01_2_0_MBIST_dm_b01_2_0_bist_fail_3_shift                        (11)
#define  DM_DM_B01_2_0_MBIST_dm_b01_2_0_bist_fail_2_shift                        (10)
#define  DM_DM_B01_2_0_MBIST_dm_b01_2_0_bist_fail_1_shift                        (9)
#define  DM_DM_B01_2_0_MBIST_dm_b01_2_0_bist_fail_0_shift                        (8)
#define  DM_DM_B01_2_0_MBIST_dm_b01_2_0_drf_bist_fail_5_shift                    (5)
#define  DM_DM_B01_2_0_MBIST_dm_b01_2_0_drf_bist_fail_4_shift                    (4)
#define  DM_DM_B01_2_0_MBIST_dm_b01_2_0_drf_bist_fail_3_shift                    (3)
#define  DM_DM_B01_2_0_MBIST_dm_b01_2_0_drf_bist_fail_2_shift                    (2)
#define  DM_DM_B01_2_0_MBIST_dm_b01_2_0_drf_bist_fail_1_shift                    (1)
#define  DM_DM_B01_2_0_MBIST_dm_b01_2_0_drf_bist_fail_0_shift                    (0)
#define  DM_DM_B01_2_0_MBIST_dm_b01_2_0_ls_mask                                  (0x80000000)
#define  DM_DM_B01_2_0_MBIST_dm_b01_2_0_rme_mask                                 (0x40000000)
#define  DM_DM_B01_2_0_MBIST_dm_b01_2_0_rm_mask                                  (0x3C000000)
#define  DM_DM_B01_2_0_MBIST_dm_b01_2_0_bist_fail_5_mask                         (0x00002000)
#define  DM_DM_B01_2_0_MBIST_dm_b01_2_0_bist_fail_4_mask                         (0x00001000)
#define  DM_DM_B01_2_0_MBIST_dm_b01_2_0_bist_fail_3_mask                         (0x00000800)
#define  DM_DM_B01_2_0_MBIST_dm_b01_2_0_bist_fail_2_mask                         (0x00000400)
#define  DM_DM_B01_2_0_MBIST_dm_b01_2_0_bist_fail_1_mask                         (0x00000200)
#define  DM_DM_B01_2_0_MBIST_dm_b01_2_0_bist_fail_0_mask                         (0x00000100)
#define  DM_DM_B01_2_0_MBIST_dm_b01_2_0_drf_bist_fail_5_mask                     (0x00000020)
#define  DM_DM_B01_2_0_MBIST_dm_b01_2_0_drf_bist_fail_4_mask                     (0x00000010)
#define  DM_DM_B01_2_0_MBIST_dm_b01_2_0_drf_bist_fail_3_mask                     (0x00000008)
#define  DM_DM_B01_2_0_MBIST_dm_b01_2_0_drf_bist_fail_2_mask                     (0x00000004)
#define  DM_DM_B01_2_0_MBIST_dm_b01_2_0_drf_bist_fail_1_mask                     (0x00000002)
#define  DM_DM_B01_2_0_MBIST_dm_b01_2_0_drf_bist_fail_0_mask                     (0x00000001)
#define  DM_DM_B01_2_0_MBIST_dm_b01_2_0_ls(data)                                 (0x80000000&((data)<<31))
#define  DM_DM_B01_2_0_MBIST_dm_b01_2_0_rme(data)                                (0x40000000&((data)<<30))
#define  DM_DM_B01_2_0_MBIST_dm_b01_2_0_rm(data)                                 (0x3C000000&((data)<<26))
#define  DM_DM_B01_2_0_MBIST_dm_b01_2_0_bist_fail_5(data)                        (0x00002000&((data)<<13))
#define  DM_DM_B01_2_0_MBIST_dm_b01_2_0_bist_fail_4(data)                        (0x00001000&((data)<<12))
#define  DM_DM_B01_2_0_MBIST_dm_b01_2_0_bist_fail_3(data)                        (0x00000800&((data)<<11))
#define  DM_DM_B01_2_0_MBIST_dm_b01_2_0_bist_fail_2(data)                        (0x00000400&((data)<<10))
#define  DM_DM_B01_2_0_MBIST_dm_b01_2_0_bist_fail_1(data)                        (0x00000200&((data)<<9))
#define  DM_DM_B01_2_0_MBIST_dm_b01_2_0_bist_fail_0(data)                        (0x00000100&((data)<<8))
#define  DM_DM_B01_2_0_MBIST_dm_b01_2_0_drf_bist_fail_5(data)                    (0x00000020&((data)<<5))
#define  DM_DM_B01_2_0_MBIST_dm_b01_2_0_drf_bist_fail_4(data)                    (0x00000010&((data)<<4))
#define  DM_DM_B01_2_0_MBIST_dm_b01_2_0_drf_bist_fail_3(data)                    (0x00000008&((data)<<3))
#define  DM_DM_B01_2_0_MBIST_dm_b01_2_0_drf_bist_fail_2(data)                    (0x00000004&((data)<<2))
#define  DM_DM_B01_2_0_MBIST_dm_b01_2_0_drf_bist_fail_1(data)                    (0x00000002&((data)<<1))
#define  DM_DM_B01_2_0_MBIST_dm_b01_2_0_drf_bist_fail_0(data)                    (0x00000001&(data))
#define  DM_DM_B01_2_0_MBIST_get_dm_b01_2_0_ls(data)                             ((0x80000000&(data))>>31)
#define  DM_DM_B01_2_0_MBIST_get_dm_b01_2_0_rme(data)                            ((0x40000000&(data))>>30)
#define  DM_DM_B01_2_0_MBIST_get_dm_b01_2_0_rm(data)                             ((0x3C000000&(data))>>26)
#define  DM_DM_B01_2_0_MBIST_get_dm_b01_2_0_bist_fail_5(data)                    ((0x00002000&(data))>>13)
#define  DM_DM_B01_2_0_MBIST_get_dm_b01_2_0_bist_fail_4(data)                    ((0x00001000&(data))>>12)
#define  DM_DM_B01_2_0_MBIST_get_dm_b01_2_0_bist_fail_3(data)                    ((0x00000800&(data))>>11)
#define  DM_DM_B01_2_0_MBIST_get_dm_b01_2_0_bist_fail_2(data)                    ((0x00000400&(data))>>10)
#define  DM_DM_B01_2_0_MBIST_get_dm_b01_2_0_bist_fail_1(data)                    ((0x00000200&(data))>>9)
#define  DM_DM_B01_2_0_MBIST_get_dm_b01_2_0_bist_fail_0(data)                    ((0x00000100&(data))>>8)
#define  DM_DM_B01_2_0_MBIST_get_dm_b01_2_0_drf_bist_fail_5(data)                ((0x00000020&(data))>>5)
#define  DM_DM_B01_2_0_MBIST_get_dm_b01_2_0_drf_bist_fail_4(data)                ((0x00000010&(data))>>4)
#define  DM_DM_B01_2_0_MBIST_get_dm_b01_2_0_drf_bist_fail_3(data)                ((0x00000008&(data))>>3)
#define  DM_DM_B01_2_0_MBIST_get_dm_b01_2_0_drf_bist_fail_2(data)                ((0x00000004&(data))>>2)
#define  DM_DM_B01_2_0_MBIST_get_dm_b01_2_0_drf_bist_fail_1(data)                ((0x00000002&(data))>>1)
#define  DM_DM_B01_2_0_MBIST_get_dm_b01_2_0_drf_bist_fail_0(data)                (0x00000001&(data))

#define  DM_DM_B01_2_1_MBIST                                                     0x1806B71C
#define  DM_DM_B01_2_1_MBIST_reg_addr                                            "0xB806B71C"
#define  DM_DM_B01_2_1_MBIST_reg                                                 0xB806B71C
#define  DM_DM_B01_2_1_MBIST_inst_addr                                           "0x00A9"
#define  set_DM_DM_B01_2_1_MBIST_reg(data)                                       (*((volatile unsigned int*)DM_DM_B01_2_1_MBIST_reg)=data)
#define  get_DM_DM_B01_2_1_MBIST_reg                                             (*((volatile unsigned int*)DM_DM_B01_2_1_MBIST_reg))
#define  DM_DM_B01_2_1_MBIST_dm_b01_2_1_ls_shift                                 (31)
#define  DM_DM_B01_2_1_MBIST_dm_b01_2_1_rme_shift                                (30)
#define  DM_DM_B01_2_1_MBIST_dm_b01_2_1_rm_shift                                 (26)
#define  DM_DM_B01_2_1_MBIST_dm_b01_2_1_bist_fail_5_shift                        (13)
#define  DM_DM_B01_2_1_MBIST_dm_b01_2_1_bist_fail_4_shift                        (12)
#define  DM_DM_B01_2_1_MBIST_dm_b01_2_1_bist_fail_3_shift                        (11)
#define  DM_DM_B01_2_1_MBIST_dm_b01_2_1_bist_fail_2_shift                        (10)
#define  DM_DM_B01_2_1_MBIST_dm_b01_2_1_bist_fail_1_shift                        (9)
#define  DM_DM_B01_2_1_MBIST_dm_b01_2_1_bist_fail_0_shift                        (8)
#define  DM_DM_B01_2_1_MBIST_dm_b01_2_1_drf_bist_fail_5_shift                    (5)
#define  DM_DM_B01_2_1_MBIST_dm_b01_2_1_drf_bist_fail_4_shift                    (4)
#define  DM_DM_B01_2_1_MBIST_dm_b01_2_1_drf_bist_fail_3_shift                    (3)
#define  DM_DM_B01_2_1_MBIST_dm_b01_2_1_drf_bist_fail_2_shift                    (2)
#define  DM_DM_B01_2_1_MBIST_dm_b01_2_1_drf_bist_fail_1_shift                    (1)
#define  DM_DM_B01_2_1_MBIST_dm_b01_2_1_drf_bist_fail_0_shift                    (0)
#define  DM_DM_B01_2_1_MBIST_dm_b01_2_1_ls_mask                                  (0x80000000)
#define  DM_DM_B01_2_1_MBIST_dm_b01_2_1_rme_mask                                 (0x40000000)
#define  DM_DM_B01_2_1_MBIST_dm_b01_2_1_rm_mask                                  (0x3C000000)
#define  DM_DM_B01_2_1_MBIST_dm_b01_2_1_bist_fail_5_mask                         (0x00002000)
#define  DM_DM_B01_2_1_MBIST_dm_b01_2_1_bist_fail_4_mask                         (0x00001000)
#define  DM_DM_B01_2_1_MBIST_dm_b01_2_1_bist_fail_3_mask                         (0x00000800)
#define  DM_DM_B01_2_1_MBIST_dm_b01_2_1_bist_fail_2_mask                         (0x00000400)
#define  DM_DM_B01_2_1_MBIST_dm_b01_2_1_bist_fail_1_mask                         (0x00000200)
#define  DM_DM_B01_2_1_MBIST_dm_b01_2_1_bist_fail_0_mask                         (0x00000100)
#define  DM_DM_B01_2_1_MBIST_dm_b01_2_1_drf_bist_fail_5_mask                     (0x00000020)
#define  DM_DM_B01_2_1_MBIST_dm_b01_2_1_drf_bist_fail_4_mask                     (0x00000010)
#define  DM_DM_B01_2_1_MBIST_dm_b01_2_1_drf_bist_fail_3_mask                     (0x00000008)
#define  DM_DM_B01_2_1_MBIST_dm_b01_2_1_drf_bist_fail_2_mask                     (0x00000004)
#define  DM_DM_B01_2_1_MBIST_dm_b01_2_1_drf_bist_fail_1_mask                     (0x00000002)
#define  DM_DM_B01_2_1_MBIST_dm_b01_2_1_drf_bist_fail_0_mask                     (0x00000001)
#define  DM_DM_B01_2_1_MBIST_dm_b01_2_1_ls(data)                                 (0x80000000&((data)<<31))
#define  DM_DM_B01_2_1_MBIST_dm_b01_2_1_rme(data)                                (0x40000000&((data)<<30))
#define  DM_DM_B01_2_1_MBIST_dm_b01_2_1_rm(data)                                 (0x3C000000&((data)<<26))
#define  DM_DM_B01_2_1_MBIST_dm_b01_2_1_bist_fail_5(data)                        (0x00002000&((data)<<13))
#define  DM_DM_B01_2_1_MBIST_dm_b01_2_1_bist_fail_4(data)                        (0x00001000&((data)<<12))
#define  DM_DM_B01_2_1_MBIST_dm_b01_2_1_bist_fail_3(data)                        (0x00000800&((data)<<11))
#define  DM_DM_B01_2_1_MBIST_dm_b01_2_1_bist_fail_2(data)                        (0x00000400&((data)<<10))
#define  DM_DM_B01_2_1_MBIST_dm_b01_2_1_bist_fail_1(data)                        (0x00000200&((data)<<9))
#define  DM_DM_B01_2_1_MBIST_dm_b01_2_1_bist_fail_0(data)                        (0x00000100&((data)<<8))
#define  DM_DM_B01_2_1_MBIST_dm_b01_2_1_drf_bist_fail_5(data)                    (0x00000020&((data)<<5))
#define  DM_DM_B01_2_1_MBIST_dm_b01_2_1_drf_bist_fail_4(data)                    (0x00000010&((data)<<4))
#define  DM_DM_B01_2_1_MBIST_dm_b01_2_1_drf_bist_fail_3(data)                    (0x00000008&((data)<<3))
#define  DM_DM_B01_2_1_MBIST_dm_b01_2_1_drf_bist_fail_2(data)                    (0x00000004&((data)<<2))
#define  DM_DM_B01_2_1_MBIST_dm_b01_2_1_drf_bist_fail_1(data)                    (0x00000002&((data)<<1))
#define  DM_DM_B01_2_1_MBIST_dm_b01_2_1_drf_bist_fail_0(data)                    (0x00000001&(data))
#define  DM_DM_B01_2_1_MBIST_get_dm_b01_2_1_ls(data)                             ((0x80000000&(data))>>31)
#define  DM_DM_B01_2_1_MBIST_get_dm_b01_2_1_rme(data)                            ((0x40000000&(data))>>30)
#define  DM_DM_B01_2_1_MBIST_get_dm_b01_2_1_rm(data)                             ((0x3C000000&(data))>>26)
#define  DM_DM_B01_2_1_MBIST_get_dm_b01_2_1_bist_fail_5(data)                    ((0x00002000&(data))>>13)
#define  DM_DM_B01_2_1_MBIST_get_dm_b01_2_1_bist_fail_4(data)                    ((0x00001000&(data))>>12)
#define  DM_DM_B01_2_1_MBIST_get_dm_b01_2_1_bist_fail_3(data)                    ((0x00000800&(data))>>11)
#define  DM_DM_B01_2_1_MBIST_get_dm_b01_2_1_bist_fail_2(data)                    ((0x00000400&(data))>>10)
#define  DM_DM_B01_2_1_MBIST_get_dm_b01_2_1_bist_fail_1(data)                    ((0x00000200&(data))>>9)
#define  DM_DM_B01_2_1_MBIST_get_dm_b01_2_1_bist_fail_0(data)                    ((0x00000100&(data))>>8)
#define  DM_DM_B01_2_1_MBIST_get_dm_b01_2_1_drf_bist_fail_5(data)                ((0x00000020&(data))>>5)
#define  DM_DM_B01_2_1_MBIST_get_dm_b01_2_1_drf_bist_fail_4(data)                ((0x00000010&(data))>>4)
#define  DM_DM_B01_2_1_MBIST_get_dm_b01_2_1_drf_bist_fail_3(data)                ((0x00000008&(data))>>3)
#define  DM_DM_B01_2_1_MBIST_get_dm_b01_2_1_drf_bist_fail_2(data)                ((0x00000004&(data))>>2)
#define  DM_DM_B01_2_1_MBIST_get_dm_b01_2_1_drf_bist_fail_1(data)                ((0x00000002&(data))>>1)
#define  DM_DM_B01_2_1_MBIST_get_dm_b01_2_1_drf_bist_fail_0(data)                (0x00000001&(data))

#define  DM_DM_B02_1_MBIST                                                       0x1806B720
#define  DM_DM_B02_1_MBIST_reg_addr                                              "0xB806B720"
#define  DM_DM_B02_1_MBIST_reg                                                   0xB806B720
#define  DM_DM_B02_1_MBIST_inst_addr                                             "0x00AA"
#define  set_DM_DM_B02_1_MBIST_reg(data)                                         (*((volatile unsigned int*)DM_DM_B02_1_MBIST_reg)=data)
#define  get_DM_DM_B02_1_MBIST_reg                                               (*((volatile unsigned int*)DM_DM_B02_1_MBIST_reg))
#define  DM_DM_B02_1_MBIST_dm_b02_1_ls_shift                                     (31)
#define  DM_DM_B02_1_MBIST_dm_b02_1_rme_shift                                    (30)
#define  DM_DM_B02_1_MBIST_dm_b02_1_rm_shift                                     (26)
#define  DM_DM_B02_1_MBIST_dm_b02_1_bist_fail_11_shift                           (24)
#define  DM_DM_B02_1_MBIST_dm_b02_1_bist_fail_10_shift                           (23)
#define  DM_DM_B02_1_MBIST_dm_b02_1_bist_fail_9_shift                            (22)
#define  DM_DM_B02_1_MBIST_dm_b02_1_bist_fail_8_shift                            (21)
#define  DM_DM_B02_1_MBIST_dm_b02_1_bist_fail_7_shift                            (20)
#define  DM_DM_B02_1_MBIST_dm_b02_1_bist_fail_6_shift                            (19)
#define  DM_DM_B02_1_MBIST_dm_b02_1_bist_fail_5_shift                            (18)
#define  DM_DM_B02_1_MBIST_dm_b02_1_bist_fail_4_shift                            (17)
#define  DM_DM_B02_1_MBIST_dm_b02_1_bist_fail_3_shift                            (16)
#define  DM_DM_B02_1_MBIST_dm_b02_1_bist_fail_2_shift                            (15)
#define  DM_DM_B02_1_MBIST_dm_b02_1_bist_fail_1_shift                            (14)
#define  DM_DM_B02_1_MBIST_dm_b02_1_bist_fail_0_shift                            (13)
#define  DM_DM_B02_1_MBIST_dm_b02_1_drf_bist_fail_11_shift                       (11)
#define  DM_DM_B02_1_MBIST_dm_b02_1_drf_bist_fail_10_shift                       (10)
#define  DM_DM_B02_1_MBIST_dm_b02_1_drf_bist_fail_9_shift                        (9)
#define  DM_DM_B02_1_MBIST_dm_b02_1_drf_bist_fail_8_shift                        (8)
#define  DM_DM_B02_1_MBIST_dm_b02_1_drf_bist_fail_7_shift                        (7)
#define  DM_DM_B02_1_MBIST_dm_b02_1_drf_bist_fail_6_shift                        (6)
#define  DM_DM_B02_1_MBIST_dm_b02_1_drf_bist_fail_5_shift                        (5)
#define  DM_DM_B02_1_MBIST_dm_b02_1_drf_bist_fail_4_shift                        (4)
#define  DM_DM_B02_1_MBIST_dm_b02_1_drf_bist_fail_3_shift                        (3)
#define  DM_DM_B02_1_MBIST_dm_b02_1_drf_bist_fail_2_shift                        (2)
#define  DM_DM_B02_1_MBIST_dm_b02_1_drf_bist_fail_1_shift                        (1)
#define  DM_DM_B02_1_MBIST_dm_b02_1_drf_bist_fail_0_shift                        (0)
#define  DM_DM_B02_1_MBIST_dm_b02_1_ls_mask                                      (0x80000000)
#define  DM_DM_B02_1_MBIST_dm_b02_1_rme_mask                                     (0x40000000)
#define  DM_DM_B02_1_MBIST_dm_b02_1_rm_mask                                      (0x3C000000)
#define  DM_DM_B02_1_MBIST_dm_b02_1_bist_fail_11_mask                            (0x01000000)
#define  DM_DM_B02_1_MBIST_dm_b02_1_bist_fail_10_mask                            (0x00800000)
#define  DM_DM_B02_1_MBIST_dm_b02_1_bist_fail_9_mask                             (0x00400000)
#define  DM_DM_B02_1_MBIST_dm_b02_1_bist_fail_8_mask                             (0x00200000)
#define  DM_DM_B02_1_MBIST_dm_b02_1_bist_fail_7_mask                             (0x00100000)
#define  DM_DM_B02_1_MBIST_dm_b02_1_bist_fail_6_mask                             (0x00080000)
#define  DM_DM_B02_1_MBIST_dm_b02_1_bist_fail_5_mask                             (0x00040000)
#define  DM_DM_B02_1_MBIST_dm_b02_1_bist_fail_4_mask                             (0x00020000)
#define  DM_DM_B02_1_MBIST_dm_b02_1_bist_fail_3_mask                             (0x00010000)
#define  DM_DM_B02_1_MBIST_dm_b02_1_bist_fail_2_mask                             (0x00008000)
#define  DM_DM_B02_1_MBIST_dm_b02_1_bist_fail_1_mask                             (0x00004000)
#define  DM_DM_B02_1_MBIST_dm_b02_1_bist_fail_0_mask                             (0x00002000)
#define  DM_DM_B02_1_MBIST_dm_b02_1_drf_bist_fail_11_mask                        (0x00000800)
#define  DM_DM_B02_1_MBIST_dm_b02_1_drf_bist_fail_10_mask                        (0x00000400)
#define  DM_DM_B02_1_MBIST_dm_b02_1_drf_bist_fail_9_mask                         (0x00000200)
#define  DM_DM_B02_1_MBIST_dm_b02_1_drf_bist_fail_8_mask                         (0x00000100)
#define  DM_DM_B02_1_MBIST_dm_b02_1_drf_bist_fail_7_mask                         (0x00000080)
#define  DM_DM_B02_1_MBIST_dm_b02_1_drf_bist_fail_6_mask                         (0x00000040)
#define  DM_DM_B02_1_MBIST_dm_b02_1_drf_bist_fail_5_mask                         (0x00000020)
#define  DM_DM_B02_1_MBIST_dm_b02_1_drf_bist_fail_4_mask                         (0x00000010)
#define  DM_DM_B02_1_MBIST_dm_b02_1_drf_bist_fail_3_mask                         (0x00000008)
#define  DM_DM_B02_1_MBIST_dm_b02_1_drf_bist_fail_2_mask                         (0x00000004)
#define  DM_DM_B02_1_MBIST_dm_b02_1_drf_bist_fail_1_mask                         (0x00000002)
#define  DM_DM_B02_1_MBIST_dm_b02_1_drf_bist_fail_0_mask                         (0x00000001)
#define  DM_DM_B02_1_MBIST_dm_b02_1_ls(data)                                     (0x80000000&((data)<<31))
#define  DM_DM_B02_1_MBIST_dm_b02_1_rme(data)                                    (0x40000000&((data)<<30))
#define  DM_DM_B02_1_MBIST_dm_b02_1_rm(data)                                     (0x3C000000&((data)<<26))
#define  DM_DM_B02_1_MBIST_dm_b02_1_bist_fail_11(data)                           (0x01000000&((data)<<24))
#define  DM_DM_B02_1_MBIST_dm_b02_1_bist_fail_10(data)                           (0x00800000&((data)<<23))
#define  DM_DM_B02_1_MBIST_dm_b02_1_bist_fail_9(data)                            (0x00400000&((data)<<22))
#define  DM_DM_B02_1_MBIST_dm_b02_1_bist_fail_8(data)                            (0x00200000&((data)<<21))
#define  DM_DM_B02_1_MBIST_dm_b02_1_bist_fail_7(data)                            (0x00100000&((data)<<20))
#define  DM_DM_B02_1_MBIST_dm_b02_1_bist_fail_6(data)                            (0x00080000&((data)<<19))
#define  DM_DM_B02_1_MBIST_dm_b02_1_bist_fail_5(data)                            (0x00040000&((data)<<18))
#define  DM_DM_B02_1_MBIST_dm_b02_1_bist_fail_4(data)                            (0x00020000&((data)<<17))
#define  DM_DM_B02_1_MBIST_dm_b02_1_bist_fail_3(data)                            (0x00010000&((data)<<16))
#define  DM_DM_B02_1_MBIST_dm_b02_1_bist_fail_2(data)                            (0x00008000&((data)<<15))
#define  DM_DM_B02_1_MBIST_dm_b02_1_bist_fail_1(data)                            (0x00004000&((data)<<14))
#define  DM_DM_B02_1_MBIST_dm_b02_1_bist_fail_0(data)                            (0x00002000&((data)<<13))
#define  DM_DM_B02_1_MBIST_dm_b02_1_drf_bist_fail_11(data)                       (0x00000800&((data)<<11))
#define  DM_DM_B02_1_MBIST_dm_b02_1_drf_bist_fail_10(data)                       (0x00000400&((data)<<10))
#define  DM_DM_B02_1_MBIST_dm_b02_1_drf_bist_fail_9(data)                        (0x00000200&((data)<<9))
#define  DM_DM_B02_1_MBIST_dm_b02_1_drf_bist_fail_8(data)                        (0x00000100&((data)<<8))
#define  DM_DM_B02_1_MBIST_dm_b02_1_drf_bist_fail_7(data)                        (0x00000080&((data)<<7))
#define  DM_DM_B02_1_MBIST_dm_b02_1_drf_bist_fail_6(data)                        (0x00000040&((data)<<6))
#define  DM_DM_B02_1_MBIST_dm_b02_1_drf_bist_fail_5(data)                        (0x00000020&((data)<<5))
#define  DM_DM_B02_1_MBIST_dm_b02_1_drf_bist_fail_4(data)                        (0x00000010&((data)<<4))
#define  DM_DM_B02_1_MBIST_dm_b02_1_drf_bist_fail_3(data)                        (0x00000008&((data)<<3))
#define  DM_DM_B02_1_MBIST_dm_b02_1_drf_bist_fail_2(data)                        (0x00000004&((data)<<2))
#define  DM_DM_B02_1_MBIST_dm_b02_1_drf_bist_fail_1(data)                        (0x00000002&((data)<<1))
#define  DM_DM_B02_1_MBIST_dm_b02_1_drf_bist_fail_0(data)                        (0x00000001&(data))
#define  DM_DM_B02_1_MBIST_get_dm_b02_1_ls(data)                                 ((0x80000000&(data))>>31)
#define  DM_DM_B02_1_MBIST_get_dm_b02_1_rme(data)                                ((0x40000000&(data))>>30)
#define  DM_DM_B02_1_MBIST_get_dm_b02_1_rm(data)                                 ((0x3C000000&(data))>>26)
#define  DM_DM_B02_1_MBIST_get_dm_b02_1_bist_fail_11(data)                       ((0x01000000&(data))>>24)
#define  DM_DM_B02_1_MBIST_get_dm_b02_1_bist_fail_10(data)                       ((0x00800000&(data))>>23)
#define  DM_DM_B02_1_MBIST_get_dm_b02_1_bist_fail_9(data)                        ((0x00400000&(data))>>22)
#define  DM_DM_B02_1_MBIST_get_dm_b02_1_bist_fail_8(data)                        ((0x00200000&(data))>>21)
#define  DM_DM_B02_1_MBIST_get_dm_b02_1_bist_fail_7(data)                        ((0x00100000&(data))>>20)
#define  DM_DM_B02_1_MBIST_get_dm_b02_1_bist_fail_6(data)                        ((0x00080000&(data))>>19)
#define  DM_DM_B02_1_MBIST_get_dm_b02_1_bist_fail_5(data)                        ((0x00040000&(data))>>18)
#define  DM_DM_B02_1_MBIST_get_dm_b02_1_bist_fail_4(data)                        ((0x00020000&(data))>>17)
#define  DM_DM_B02_1_MBIST_get_dm_b02_1_bist_fail_3(data)                        ((0x00010000&(data))>>16)
#define  DM_DM_B02_1_MBIST_get_dm_b02_1_bist_fail_2(data)                        ((0x00008000&(data))>>15)
#define  DM_DM_B02_1_MBIST_get_dm_b02_1_bist_fail_1(data)                        ((0x00004000&(data))>>14)
#define  DM_DM_B02_1_MBIST_get_dm_b02_1_bist_fail_0(data)                        ((0x00002000&(data))>>13)
#define  DM_DM_B02_1_MBIST_get_dm_b02_1_drf_bist_fail_11(data)                   ((0x00000800&(data))>>11)
#define  DM_DM_B02_1_MBIST_get_dm_b02_1_drf_bist_fail_10(data)                   ((0x00000400&(data))>>10)
#define  DM_DM_B02_1_MBIST_get_dm_b02_1_drf_bist_fail_9(data)                    ((0x00000200&(data))>>9)
#define  DM_DM_B02_1_MBIST_get_dm_b02_1_drf_bist_fail_8(data)                    ((0x00000100&(data))>>8)
#define  DM_DM_B02_1_MBIST_get_dm_b02_1_drf_bist_fail_7(data)                    ((0x00000080&(data))>>7)
#define  DM_DM_B02_1_MBIST_get_dm_b02_1_drf_bist_fail_6(data)                    ((0x00000040&(data))>>6)
#define  DM_DM_B02_1_MBIST_get_dm_b02_1_drf_bist_fail_5(data)                    ((0x00000020&(data))>>5)
#define  DM_DM_B02_1_MBIST_get_dm_b02_1_drf_bist_fail_4(data)                    ((0x00000010&(data))>>4)
#define  DM_DM_B02_1_MBIST_get_dm_b02_1_drf_bist_fail_3(data)                    ((0x00000008&(data))>>3)
#define  DM_DM_B02_1_MBIST_get_dm_b02_1_drf_bist_fail_2(data)                    ((0x00000004&(data))>>2)
#define  DM_DM_B02_1_MBIST_get_dm_b02_1_drf_bist_fail_1(data)                    ((0x00000002&(data))>>1)
#define  DM_DM_B02_1_MBIST_get_dm_b02_1_drf_bist_fail_0(data)                    (0x00000001&(data))

#define  DM_DM_B02_2_MBIST                                                       0x1806B724
#define  DM_DM_B02_2_MBIST_reg_addr                                              "0xB806B724"
#define  DM_DM_B02_2_MBIST_reg                                                   0xB806B724
#define  DM_DM_B02_2_MBIST_inst_addr                                             "0x00AB"
#define  set_DM_DM_B02_2_MBIST_reg(data)                                         (*((volatile unsigned int*)DM_DM_B02_2_MBIST_reg)=data)
#define  get_DM_DM_B02_2_MBIST_reg                                               (*((volatile unsigned int*)DM_DM_B02_2_MBIST_reg))
#define  DM_DM_B02_2_MBIST_dm_b02_2_ls_shift                                     (31)
#define  DM_DM_B02_2_MBIST_dm_b02_2_rme_shift                                    (30)
#define  DM_DM_B02_2_MBIST_dm_b02_2_rm_shift                                     (26)
#define  DM_DM_B02_2_MBIST_dm_b02_2_bist_fail_0_shift                            (8)
#define  DM_DM_B02_2_MBIST_dm_b02_2_drf_bist_fail_0_shift                        (0)
#define  DM_DM_B02_2_MBIST_dm_b02_2_ls_mask                                      (0x80000000)
#define  DM_DM_B02_2_MBIST_dm_b02_2_rme_mask                                     (0x40000000)
#define  DM_DM_B02_2_MBIST_dm_b02_2_rm_mask                                      (0x3C000000)
#define  DM_DM_B02_2_MBIST_dm_b02_2_bist_fail_0_mask                             (0x00000100)
#define  DM_DM_B02_2_MBIST_dm_b02_2_drf_bist_fail_0_mask                         (0x00000001)
#define  DM_DM_B02_2_MBIST_dm_b02_2_ls(data)                                     (0x80000000&((data)<<31))
#define  DM_DM_B02_2_MBIST_dm_b02_2_rme(data)                                    (0x40000000&((data)<<30))
#define  DM_DM_B02_2_MBIST_dm_b02_2_rm(data)                                     (0x3C000000&((data)<<26))
#define  DM_DM_B02_2_MBIST_dm_b02_2_bist_fail_0(data)                            (0x00000100&((data)<<8))
#define  DM_DM_B02_2_MBIST_dm_b02_2_drf_bist_fail_0(data)                        (0x00000001&(data))
#define  DM_DM_B02_2_MBIST_get_dm_b02_2_ls(data)                                 ((0x80000000&(data))>>31)
#define  DM_DM_B02_2_MBIST_get_dm_b02_2_rme(data)                                ((0x40000000&(data))>>30)
#define  DM_DM_B02_2_MBIST_get_dm_b02_2_rm(data)                                 ((0x3C000000&(data))>>26)
#define  DM_DM_B02_2_MBIST_get_dm_b02_2_bist_fail_0(data)                        ((0x00000100&(data))>>8)
#define  DM_DM_B02_2_MBIST_get_dm_b02_2_drf_bist_fail_0(data)                    (0x00000001&(data))

#define  DM_DM_HIST_MBIST                                                        0x1806B728
#define  DM_DM_HIST_MBIST_reg_addr                                               "0xB806B728"
#define  DM_DM_HIST_MBIST_reg                                                    0xB806B728
#define  DM_DM_HIST_MBIST_inst_addr                                              "0x00AC"
#define  set_DM_DM_HIST_MBIST_reg(data)                                          (*((volatile unsigned int*)DM_DM_HIST_MBIST_reg)=data)
#define  get_DM_DM_HIST_MBIST_reg                                                (*((volatile unsigned int*)DM_DM_HIST_MBIST_reg))
#define  DM_DM_HIST_MBIST_dm_hist_ls_shift                                       (31)
#define  DM_DM_HIST_MBIST_dm_hist_rme_shift                                      (30)
#define  DM_DM_HIST_MBIST_dm_hist_rm_shift                                       (26)
#define  DM_DM_HIST_MBIST_dm_hist_testrwm_0_shift                                (17)
#define  DM_DM_HIST_MBIST_dm_hist_testrwm_1_shift                                (16)
#define  DM_DM_HIST_MBIST_dm_hist_bist_fail_1_shift                              (9)
#define  DM_DM_HIST_MBIST_dm_hist_bist_fail_0_shift                              (8)
#define  DM_DM_HIST_MBIST_dm_hist_drf_bist_fail_1_shift                          (1)
#define  DM_DM_HIST_MBIST_dm_hist_drf_bist_fail_0_shift                          (0)
#define  DM_DM_HIST_MBIST_dm_hist_ls_mask                                        (0x80000000)
#define  DM_DM_HIST_MBIST_dm_hist_rme_mask                                       (0x40000000)
#define  DM_DM_HIST_MBIST_dm_hist_rm_mask                                        (0x3C000000)
#define  DM_DM_HIST_MBIST_dm_hist_testrwm_0_mask                                 (0x00020000)
#define  DM_DM_HIST_MBIST_dm_hist_testrwm_1_mask                                 (0x00010000)
#define  DM_DM_HIST_MBIST_dm_hist_bist_fail_1_mask                               (0x00000200)
#define  DM_DM_HIST_MBIST_dm_hist_bist_fail_0_mask                               (0x00000100)
#define  DM_DM_HIST_MBIST_dm_hist_drf_bist_fail_1_mask                           (0x00000002)
#define  DM_DM_HIST_MBIST_dm_hist_drf_bist_fail_0_mask                           (0x00000001)
#define  DM_DM_HIST_MBIST_dm_hist_ls(data)                                       (0x80000000&((data)<<31))
#define  DM_DM_HIST_MBIST_dm_hist_rme(data)                                      (0x40000000&((data)<<30))
#define  DM_DM_HIST_MBIST_dm_hist_rm(data)                                       (0x3C000000&((data)<<26))
#define  DM_DM_HIST_MBIST_dm_hist_testrwm_0(data)                                (0x00020000&((data)<<17))
#define  DM_DM_HIST_MBIST_dm_hist_testrwm_1(data)                                (0x00010000&((data)<<16))
#define  DM_DM_HIST_MBIST_dm_hist_bist_fail_1(data)                              (0x00000200&((data)<<9))
#define  DM_DM_HIST_MBIST_dm_hist_bist_fail_0(data)                              (0x00000100&((data)<<8))
#define  DM_DM_HIST_MBIST_dm_hist_drf_bist_fail_1(data)                          (0x00000002&((data)<<1))
#define  DM_DM_HIST_MBIST_dm_hist_drf_bist_fail_0(data)                          (0x00000001&(data))
#define  DM_DM_HIST_MBIST_get_dm_hist_ls(data)                                   ((0x80000000&(data))>>31)
#define  DM_DM_HIST_MBIST_get_dm_hist_rme(data)                                  ((0x40000000&(data))>>30)
#define  DM_DM_HIST_MBIST_get_dm_hist_rm(data)                                   ((0x3C000000&(data))>>26)
#define  DM_DM_HIST_MBIST_get_dm_hist_testrwm_0(data)                            ((0x00020000&(data))>>17)
#define  DM_DM_HIST_MBIST_get_dm_hist_testrwm_1(data)                            ((0x00010000&(data))>>16)
#define  DM_DM_HIST_MBIST_get_dm_hist_bist_fail_1(data)                          ((0x00000200&(data))>>9)
#define  DM_DM_HIST_MBIST_get_dm_hist_bist_fail_0(data)                          ((0x00000100&(data))>>8)
#define  DM_DM_HIST_MBIST_get_dm_hist_drf_bist_fail_1(data)                      ((0x00000002&(data))>>1)
#define  DM_DM_HIST_MBIST_get_dm_hist_drf_bist_fail_0(data)                      (0x00000001&(data))

#define  DM_DM_B03_1_MBIST                                                       0x1806B72C
#define  DM_DM_B03_1_MBIST_reg_addr                                              "0xB806B72C"
#define  DM_DM_B03_1_MBIST_reg                                                   0xB806B72C
#define  DM_DM_B03_1_MBIST_inst_addr                                             "0x00AD"
#define  set_DM_DM_B03_1_MBIST_reg(data)                                         (*((volatile unsigned int*)DM_DM_B03_1_MBIST_reg)=data)
#define  get_DM_DM_B03_1_MBIST_reg                                               (*((volatile unsigned int*)DM_DM_B03_1_MBIST_reg))
#define  DM_DM_B03_1_MBIST_dm_b03_1_ls_shift                                     (31)
#define  DM_DM_B03_1_MBIST_dm_b03_1_rme_shift                                    (30)
#define  DM_DM_B03_1_MBIST_dm_b03_1_rm_shift                                     (26)
#define  DM_DM_B03_1_MBIST_dm_b03_1_bist_fail_11_shift                           (24)
#define  DM_DM_B03_1_MBIST_dm_b03_1_bist_fail_10_shift                           (23)
#define  DM_DM_B03_1_MBIST_dm_b03_1_bist_fail_9_shift                            (22)
#define  DM_DM_B03_1_MBIST_dm_b03_1_bist_fail_8_shift                            (21)
#define  DM_DM_B03_1_MBIST_dm_b03_1_bist_fail_7_shift                            (20)
#define  DM_DM_B03_1_MBIST_dm_b03_1_bist_fail_6_shift                            (19)
#define  DM_DM_B03_1_MBIST_dm_b03_1_bist_fail_5_shift                            (18)
#define  DM_DM_B03_1_MBIST_dm_b03_1_bist_fail_4_shift                            (17)
#define  DM_DM_B03_1_MBIST_dm_b03_1_bist_fail_3_shift                            (16)
#define  DM_DM_B03_1_MBIST_dm_b03_1_bist_fail_2_shift                            (15)
#define  DM_DM_B03_1_MBIST_dm_b03_1_bist_fail_1_shift                            (14)
#define  DM_DM_B03_1_MBIST_dm_b03_1_bist_fail_0_shift                            (13)
#define  DM_DM_B03_1_MBIST_dm_b03_1_drf_bist_fail_11_shift                       (11)
#define  DM_DM_B03_1_MBIST_dm_b03_1_drf_bist_fail_10_shift                       (10)
#define  DM_DM_B03_1_MBIST_dm_b03_1_drf_bist_fail_9_shift                        (9)
#define  DM_DM_B03_1_MBIST_dm_b03_1_drf_bist_fail_8_shift                        (8)
#define  DM_DM_B03_1_MBIST_dm_b03_1_drf_bist_fail_7_shift                        (7)
#define  DM_DM_B03_1_MBIST_dm_b03_1_drf_bist_fail_6_shift                        (6)
#define  DM_DM_B03_1_MBIST_dm_b03_1_drf_bist_fail_5_shift                        (5)
#define  DM_DM_B03_1_MBIST_dm_b03_1_drf_bist_fail_4_shift                        (4)
#define  DM_DM_B03_1_MBIST_dm_b03_1_drf_bist_fail_3_shift                        (3)
#define  DM_DM_B03_1_MBIST_dm_b03_1_drf_bist_fail_2_shift                        (2)
#define  DM_DM_B03_1_MBIST_dm_b03_1_drf_bist_fail_1_shift                        (1)
#define  DM_DM_B03_1_MBIST_dm_b03_1_drf_bist_fail_0_shift                        (0)
#define  DM_DM_B03_1_MBIST_dm_b03_1_ls_mask                                      (0x80000000)
#define  DM_DM_B03_1_MBIST_dm_b03_1_rme_mask                                     (0x40000000)
#define  DM_DM_B03_1_MBIST_dm_b03_1_rm_mask                                      (0x3C000000)
#define  DM_DM_B03_1_MBIST_dm_b03_1_bist_fail_11_mask                            (0x01000000)
#define  DM_DM_B03_1_MBIST_dm_b03_1_bist_fail_10_mask                            (0x00800000)
#define  DM_DM_B03_1_MBIST_dm_b03_1_bist_fail_9_mask                             (0x00400000)
#define  DM_DM_B03_1_MBIST_dm_b03_1_bist_fail_8_mask                             (0x00200000)
#define  DM_DM_B03_1_MBIST_dm_b03_1_bist_fail_7_mask                             (0x00100000)
#define  DM_DM_B03_1_MBIST_dm_b03_1_bist_fail_6_mask                             (0x00080000)
#define  DM_DM_B03_1_MBIST_dm_b03_1_bist_fail_5_mask                             (0x00040000)
#define  DM_DM_B03_1_MBIST_dm_b03_1_bist_fail_4_mask                             (0x00020000)
#define  DM_DM_B03_1_MBIST_dm_b03_1_bist_fail_3_mask                             (0x00010000)
#define  DM_DM_B03_1_MBIST_dm_b03_1_bist_fail_2_mask                             (0x00008000)
#define  DM_DM_B03_1_MBIST_dm_b03_1_bist_fail_1_mask                             (0x00004000)
#define  DM_DM_B03_1_MBIST_dm_b03_1_bist_fail_0_mask                             (0x00002000)
#define  DM_DM_B03_1_MBIST_dm_b03_1_drf_bist_fail_11_mask                        (0x00000800)
#define  DM_DM_B03_1_MBIST_dm_b03_1_drf_bist_fail_10_mask                        (0x00000400)
#define  DM_DM_B03_1_MBIST_dm_b03_1_drf_bist_fail_9_mask                         (0x00000200)
#define  DM_DM_B03_1_MBIST_dm_b03_1_drf_bist_fail_8_mask                         (0x00000100)
#define  DM_DM_B03_1_MBIST_dm_b03_1_drf_bist_fail_7_mask                         (0x00000080)
#define  DM_DM_B03_1_MBIST_dm_b03_1_drf_bist_fail_6_mask                         (0x00000040)
#define  DM_DM_B03_1_MBIST_dm_b03_1_drf_bist_fail_5_mask                         (0x00000020)
#define  DM_DM_B03_1_MBIST_dm_b03_1_drf_bist_fail_4_mask                         (0x00000010)
#define  DM_DM_B03_1_MBIST_dm_b03_1_drf_bist_fail_3_mask                         (0x00000008)
#define  DM_DM_B03_1_MBIST_dm_b03_1_drf_bist_fail_2_mask                         (0x00000004)
#define  DM_DM_B03_1_MBIST_dm_b03_1_drf_bist_fail_1_mask                         (0x00000002)
#define  DM_DM_B03_1_MBIST_dm_b03_1_drf_bist_fail_0_mask                         (0x00000001)
#define  DM_DM_B03_1_MBIST_dm_b03_1_ls(data)                                     (0x80000000&((data)<<31))
#define  DM_DM_B03_1_MBIST_dm_b03_1_rme(data)                                    (0x40000000&((data)<<30))
#define  DM_DM_B03_1_MBIST_dm_b03_1_rm(data)                                     (0x3C000000&((data)<<26))
#define  DM_DM_B03_1_MBIST_dm_b03_1_bist_fail_11(data)                           (0x01000000&((data)<<24))
#define  DM_DM_B03_1_MBIST_dm_b03_1_bist_fail_10(data)                           (0x00800000&((data)<<23))
#define  DM_DM_B03_1_MBIST_dm_b03_1_bist_fail_9(data)                            (0x00400000&((data)<<22))
#define  DM_DM_B03_1_MBIST_dm_b03_1_bist_fail_8(data)                            (0x00200000&((data)<<21))
#define  DM_DM_B03_1_MBIST_dm_b03_1_bist_fail_7(data)                            (0x00100000&((data)<<20))
#define  DM_DM_B03_1_MBIST_dm_b03_1_bist_fail_6(data)                            (0x00080000&((data)<<19))
#define  DM_DM_B03_1_MBIST_dm_b03_1_bist_fail_5(data)                            (0x00040000&((data)<<18))
#define  DM_DM_B03_1_MBIST_dm_b03_1_bist_fail_4(data)                            (0x00020000&((data)<<17))
#define  DM_DM_B03_1_MBIST_dm_b03_1_bist_fail_3(data)                            (0x00010000&((data)<<16))
#define  DM_DM_B03_1_MBIST_dm_b03_1_bist_fail_2(data)                            (0x00008000&((data)<<15))
#define  DM_DM_B03_1_MBIST_dm_b03_1_bist_fail_1(data)                            (0x00004000&((data)<<14))
#define  DM_DM_B03_1_MBIST_dm_b03_1_bist_fail_0(data)                            (0x00002000&((data)<<13))
#define  DM_DM_B03_1_MBIST_dm_b03_1_drf_bist_fail_11(data)                       (0x00000800&((data)<<11))
#define  DM_DM_B03_1_MBIST_dm_b03_1_drf_bist_fail_10(data)                       (0x00000400&((data)<<10))
#define  DM_DM_B03_1_MBIST_dm_b03_1_drf_bist_fail_9(data)                        (0x00000200&((data)<<9))
#define  DM_DM_B03_1_MBIST_dm_b03_1_drf_bist_fail_8(data)                        (0x00000100&((data)<<8))
#define  DM_DM_B03_1_MBIST_dm_b03_1_drf_bist_fail_7(data)                        (0x00000080&((data)<<7))
#define  DM_DM_B03_1_MBIST_dm_b03_1_drf_bist_fail_6(data)                        (0x00000040&((data)<<6))
#define  DM_DM_B03_1_MBIST_dm_b03_1_drf_bist_fail_5(data)                        (0x00000020&((data)<<5))
#define  DM_DM_B03_1_MBIST_dm_b03_1_drf_bist_fail_4(data)                        (0x00000010&((data)<<4))
#define  DM_DM_B03_1_MBIST_dm_b03_1_drf_bist_fail_3(data)                        (0x00000008&((data)<<3))
#define  DM_DM_B03_1_MBIST_dm_b03_1_drf_bist_fail_2(data)                        (0x00000004&((data)<<2))
#define  DM_DM_B03_1_MBIST_dm_b03_1_drf_bist_fail_1(data)                        (0x00000002&((data)<<1))
#define  DM_DM_B03_1_MBIST_dm_b03_1_drf_bist_fail_0(data)                        (0x00000001&(data))
#define  DM_DM_B03_1_MBIST_get_dm_b03_1_ls(data)                                 ((0x80000000&(data))>>31)
#define  DM_DM_B03_1_MBIST_get_dm_b03_1_rme(data)                                ((0x40000000&(data))>>30)
#define  DM_DM_B03_1_MBIST_get_dm_b03_1_rm(data)                                 ((0x3C000000&(data))>>26)
#define  DM_DM_B03_1_MBIST_get_dm_b03_1_bist_fail_11(data)                       ((0x01000000&(data))>>24)
#define  DM_DM_B03_1_MBIST_get_dm_b03_1_bist_fail_10(data)                       ((0x00800000&(data))>>23)
#define  DM_DM_B03_1_MBIST_get_dm_b03_1_bist_fail_9(data)                        ((0x00400000&(data))>>22)
#define  DM_DM_B03_1_MBIST_get_dm_b03_1_bist_fail_8(data)                        ((0x00200000&(data))>>21)
#define  DM_DM_B03_1_MBIST_get_dm_b03_1_bist_fail_7(data)                        ((0x00100000&(data))>>20)
#define  DM_DM_B03_1_MBIST_get_dm_b03_1_bist_fail_6(data)                        ((0x00080000&(data))>>19)
#define  DM_DM_B03_1_MBIST_get_dm_b03_1_bist_fail_5(data)                        ((0x00040000&(data))>>18)
#define  DM_DM_B03_1_MBIST_get_dm_b03_1_bist_fail_4(data)                        ((0x00020000&(data))>>17)
#define  DM_DM_B03_1_MBIST_get_dm_b03_1_bist_fail_3(data)                        ((0x00010000&(data))>>16)
#define  DM_DM_B03_1_MBIST_get_dm_b03_1_bist_fail_2(data)                        ((0x00008000&(data))>>15)
#define  DM_DM_B03_1_MBIST_get_dm_b03_1_bist_fail_1(data)                        ((0x00004000&(data))>>14)
#define  DM_DM_B03_1_MBIST_get_dm_b03_1_bist_fail_0(data)                        ((0x00002000&(data))>>13)
#define  DM_DM_B03_1_MBIST_get_dm_b03_1_drf_bist_fail_11(data)                   ((0x00000800&(data))>>11)
#define  DM_DM_B03_1_MBIST_get_dm_b03_1_drf_bist_fail_10(data)                   ((0x00000400&(data))>>10)
#define  DM_DM_B03_1_MBIST_get_dm_b03_1_drf_bist_fail_9(data)                    ((0x00000200&(data))>>9)
#define  DM_DM_B03_1_MBIST_get_dm_b03_1_drf_bist_fail_8(data)                    ((0x00000100&(data))>>8)
#define  DM_DM_B03_1_MBIST_get_dm_b03_1_drf_bist_fail_7(data)                    ((0x00000080&(data))>>7)
#define  DM_DM_B03_1_MBIST_get_dm_b03_1_drf_bist_fail_6(data)                    ((0x00000040&(data))>>6)
#define  DM_DM_B03_1_MBIST_get_dm_b03_1_drf_bist_fail_5(data)                    ((0x00000020&(data))>>5)
#define  DM_DM_B03_1_MBIST_get_dm_b03_1_drf_bist_fail_4(data)                    ((0x00000010&(data))>>4)
#define  DM_DM_B03_1_MBIST_get_dm_b03_1_drf_bist_fail_3(data)                    ((0x00000008&(data))>>3)
#define  DM_DM_B03_1_MBIST_get_dm_b03_1_drf_bist_fail_2(data)                    ((0x00000004&(data))>>2)
#define  DM_DM_B03_1_MBIST_get_dm_b03_1_drf_bist_fail_1(data)                    ((0x00000002&(data))>>1)
#define  DM_DM_B03_1_MBIST_get_dm_b03_1_drf_bist_fail_0(data)                    (0x00000001&(data))

#define  DM_DM_B03_2_MBIST                                                       0x1806B730
#define  DM_DM_B03_2_MBIST_reg_addr                                              "0xB806B730"
#define  DM_DM_B03_2_MBIST_reg                                                   0xB806B730
#define  DM_DM_B03_2_MBIST_inst_addr                                             "0x00AE"
#define  set_DM_DM_B03_2_MBIST_reg(data)                                         (*((volatile unsigned int*)DM_DM_B03_2_MBIST_reg)=data)
#define  get_DM_DM_B03_2_MBIST_reg                                               (*((volatile unsigned int*)DM_DM_B03_2_MBIST_reg))
#define  DM_DM_B03_2_MBIST_dm_b03_2_ls_shift                                     (31)
#define  DM_DM_B03_2_MBIST_dm_b03_2_rme_shift                                    (30)
#define  DM_DM_B03_2_MBIST_dm_b03_2_rm_shift                                     (26)
#define  DM_DM_B03_2_MBIST_dm_b03_2_bist_fail_3_shift                            (11)
#define  DM_DM_B03_2_MBIST_dm_b03_2_bist_fail_2_shift                            (10)
#define  DM_DM_B03_2_MBIST_dm_b03_2_bist_fail_1_shift                            (9)
#define  DM_DM_B03_2_MBIST_dm_b03_2_bist_fail_0_shift                            (8)
#define  DM_DM_B03_2_MBIST_dm_b03_2_drf_bist_fail_3_shift                        (3)
#define  DM_DM_B03_2_MBIST_dm_b03_2_drf_bist_fail_2_shift                        (2)
#define  DM_DM_B03_2_MBIST_dm_b03_2_drf_bist_fail_1_shift                        (1)
#define  DM_DM_B03_2_MBIST_dm_b03_2_drf_bist_fail_0_shift                        (0)
#define  DM_DM_B03_2_MBIST_dm_b03_2_ls_mask                                      (0x80000000)
#define  DM_DM_B03_2_MBIST_dm_b03_2_rme_mask                                     (0x40000000)
#define  DM_DM_B03_2_MBIST_dm_b03_2_rm_mask                                      (0x3C000000)
#define  DM_DM_B03_2_MBIST_dm_b03_2_bist_fail_3_mask                             (0x00000800)
#define  DM_DM_B03_2_MBIST_dm_b03_2_bist_fail_2_mask                             (0x00000400)
#define  DM_DM_B03_2_MBIST_dm_b03_2_bist_fail_1_mask                             (0x00000200)
#define  DM_DM_B03_2_MBIST_dm_b03_2_bist_fail_0_mask                             (0x00000100)
#define  DM_DM_B03_2_MBIST_dm_b03_2_drf_bist_fail_3_mask                         (0x00000008)
#define  DM_DM_B03_2_MBIST_dm_b03_2_drf_bist_fail_2_mask                         (0x00000004)
#define  DM_DM_B03_2_MBIST_dm_b03_2_drf_bist_fail_1_mask                         (0x00000002)
#define  DM_DM_B03_2_MBIST_dm_b03_2_drf_bist_fail_0_mask                         (0x00000001)
#define  DM_DM_B03_2_MBIST_dm_b03_2_ls(data)                                     (0x80000000&((data)<<31))
#define  DM_DM_B03_2_MBIST_dm_b03_2_rme(data)                                    (0x40000000&((data)<<30))
#define  DM_DM_B03_2_MBIST_dm_b03_2_rm(data)                                     (0x3C000000&((data)<<26))
#define  DM_DM_B03_2_MBIST_dm_b03_2_bist_fail_3(data)                            (0x00000800&((data)<<11))
#define  DM_DM_B03_2_MBIST_dm_b03_2_bist_fail_2(data)                            (0x00000400&((data)<<10))
#define  DM_DM_B03_2_MBIST_dm_b03_2_bist_fail_1(data)                            (0x00000200&((data)<<9))
#define  DM_DM_B03_2_MBIST_dm_b03_2_bist_fail_0(data)                            (0x00000100&((data)<<8))
#define  DM_DM_B03_2_MBIST_dm_b03_2_drf_bist_fail_3(data)                        (0x00000008&((data)<<3))
#define  DM_DM_B03_2_MBIST_dm_b03_2_drf_bist_fail_2(data)                        (0x00000004&((data)<<2))
#define  DM_DM_B03_2_MBIST_dm_b03_2_drf_bist_fail_1(data)                        (0x00000002&((data)<<1))
#define  DM_DM_B03_2_MBIST_dm_b03_2_drf_bist_fail_0(data)                        (0x00000001&(data))
#define  DM_DM_B03_2_MBIST_get_dm_b03_2_ls(data)                                 ((0x80000000&(data))>>31)
#define  DM_DM_B03_2_MBIST_get_dm_b03_2_rme(data)                                ((0x40000000&(data))>>30)
#define  DM_DM_B03_2_MBIST_get_dm_b03_2_rm(data)                                 ((0x3C000000&(data))>>26)
#define  DM_DM_B03_2_MBIST_get_dm_b03_2_bist_fail_3(data)                        ((0x00000800&(data))>>11)
#define  DM_DM_B03_2_MBIST_get_dm_b03_2_bist_fail_2(data)                        ((0x00000400&(data))>>10)
#define  DM_DM_B03_2_MBIST_get_dm_b03_2_bist_fail_1(data)                        ((0x00000200&(data))>>9)
#define  DM_DM_B03_2_MBIST_get_dm_b03_2_bist_fail_0(data)                        ((0x00000100&(data))>>8)
#define  DM_DM_B03_2_MBIST_get_dm_b03_2_drf_bist_fail_3(data)                    ((0x00000008&(data))>>3)
#define  DM_DM_B03_2_MBIST_get_dm_b03_2_drf_bist_fail_2(data)                    ((0x00000004&(data))>>2)
#define  DM_DM_B03_2_MBIST_get_dm_b03_2_drf_bist_fail_1(data)                    ((0x00000002&(data))>>1)
#define  DM_DM_B03_2_MBIST_get_dm_b03_2_drf_bist_fail_0(data)                    (0x00000001&(data))

#define  DM_DM_B05_MBIST                                                         0x1806B734
#define  DM_DM_B05_MBIST_reg_addr                                                "0xB806B734"
#define  DM_DM_B05_MBIST_reg                                                     0xB806B734
#define  DM_DM_B05_MBIST_inst_addr                                               "0x00AF"
#define  set_DM_DM_B05_MBIST_reg(data)                                           (*((volatile unsigned int*)DM_DM_B05_MBIST_reg)=data)
#define  get_DM_DM_B05_MBIST_reg                                                 (*((volatile unsigned int*)DM_DM_B05_MBIST_reg))
#define  DM_DM_B05_MBIST_dm_b05_ls_shift                                         (31)
#define  DM_DM_B05_MBIST_dm_b05_rme_shift                                        (30)
#define  DM_DM_B05_MBIST_dm_b05_rm_shift                                         (26)
#define  DM_DM_B05_MBIST_dm_b05_bist_fail_7_shift                                (15)
#define  DM_DM_B05_MBIST_dm_b05_bist_fail_6_shift                                (14)
#define  DM_DM_B05_MBIST_dm_b05_bist_fail_5_shift                                (13)
#define  DM_DM_B05_MBIST_dm_b05_bist_fail_4_shift                                (12)
#define  DM_DM_B05_MBIST_dm_b05_bist_fail_3_shift                                (11)
#define  DM_DM_B05_MBIST_dm_b05_bist_fail_2_shift                                (10)
#define  DM_DM_B05_MBIST_dm_b05_bist_fail_1_shift                                (9)
#define  DM_DM_B05_MBIST_dm_b05_bist_fail_0_shift                                (8)
#define  DM_DM_B05_MBIST_dm_b05_drf_bist_fail_7_shift                            (7)
#define  DM_DM_B05_MBIST_dm_b05_drf_bist_fail_6_shift                            (6)
#define  DM_DM_B05_MBIST_dm_b05_drf_bist_fail_5_shift                            (5)
#define  DM_DM_B05_MBIST_dm_b05_drf_bist_fail_4_shift                            (4)
#define  DM_DM_B05_MBIST_dm_b05_drf_bist_fail_3_shift                            (3)
#define  DM_DM_B05_MBIST_dm_b05_drf_bist_fail_2_shift                            (2)
#define  DM_DM_B05_MBIST_dm_b05_drf_bist_fail_1_shift                            (1)
#define  DM_DM_B05_MBIST_dm_b05_drf_bist_fail_0_shift                            (0)
#define  DM_DM_B05_MBIST_dm_b05_ls_mask                                          (0x80000000)
#define  DM_DM_B05_MBIST_dm_b05_rme_mask                                         (0x40000000)
#define  DM_DM_B05_MBIST_dm_b05_rm_mask                                          (0x3C000000)
#define  DM_DM_B05_MBIST_dm_b05_bist_fail_7_mask                                 (0x00008000)
#define  DM_DM_B05_MBIST_dm_b05_bist_fail_6_mask                                 (0x00004000)
#define  DM_DM_B05_MBIST_dm_b05_bist_fail_5_mask                                 (0x00002000)
#define  DM_DM_B05_MBIST_dm_b05_bist_fail_4_mask                                 (0x00001000)
#define  DM_DM_B05_MBIST_dm_b05_bist_fail_3_mask                                 (0x00000800)
#define  DM_DM_B05_MBIST_dm_b05_bist_fail_2_mask                                 (0x00000400)
#define  DM_DM_B05_MBIST_dm_b05_bist_fail_1_mask                                 (0x00000200)
#define  DM_DM_B05_MBIST_dm_b05_bist_fail_0_mask                                 (0x00000100)
#define  DM_DM_B05_MBIST_dm_b05_drf_bist_fail_7_mask                             (0x00000080)
#define  DM_DM_B05_MBIST_dm_b05_drf_bist_fail_6_mask                             (0x00000040)
#define  DM_DM_B05_MBIST_dm_b05_drf_bist_fail_5_mask                             (0x00000020)
#define  DM_DM_B05_MBIST_dm_b05_drf_bist_fail_4_mask                             (0x00000010)
#define  DM_DM_B05_MBIST_dm_b05_drf_bist_fail_3_mask                             (0x00000008)
#define  DM_DM_B05_MBIST_dm_b05_drf_bist_fail_2_mask                             (0x00000004)
#define  DM_DM_B05_MBIST_dm_b05_drf_bist_fail_1_mask                             (0x00000002)
#define  DM_DM_B05_MBIST_dm_b05_drf_bist_fail_0_mask                             (0x00000001)
#define  DM_DM_B05_MBIST_dm_b05_ls(data)                                         (0x80000000&((data)<<31))
#define  DM_DM_B05_MBIST_dm_b05_rme(data)                                        (0x40000000&((data)<<30))
#define  DM_DM_B05_MBIST_dm_b05_rm(data)                                         (0x3C000000&((data)<<26))
#define  DM_DM_B05_MBIST_dm_b05_bist_fail_7(data)                                (0x00008000&((data)<<15))
#define  DM_DM_B05_MBIST_dm_b05_bist_fail_6(data)                                (0x00004000&((data)<<14))
#define  DM_DM_B05_MBIST_dm_b05_bist_fail_5(data)                                (0x00002000&((data)<<13))
#define  DM_DM_B05_MBIST_dm_b05_bist_fail_4(data)                                (0x00001000&((data)<<12))
#define  DM_DM_B05_MBIST_dm_b05_bist_fail_3(data)                                (0x00000800&((data)<<11))
#define  DM_DM_B05_MBIST_dm_b05_bist_fail_2(data)                                (0x00000400&((data)<<10))
#define  DM_DM_B05_MBIST_dm_b05_bist_fail_1(data)                                (0x00000200&((data)<<9))
#define  DM_DM_B05_MBIST_dm_b05_bist_fail_0(data)                                (0x00000100&((data)<<8))
#define  DM_DM_B05_MBIST_dm_b05_drf_bist_fail_7(data)                            (0x00000080&((data)<<7))
#define  DM_DM_B05_MBIST_dm_b05_drf_bist_fail_6(data)                            (0x00000040&((data)<<6))
#define  DM_DM_B05_MBIST_dm_b05_drf_bist_fail_5(data)                            (0x00000020&((data)<<5))
#define  DM_DM_B05_MBIST_dm_b05_drf_bist_fail_4(data)                            (0x00000010&((data)<<4))
#define  DM_DM_B05_MBIST_dm_b05_drf_bist_fail_3(data)                            (0x00000008&((data)<<3))
#define  DM_DM_B05_MBIST_dm_b05_drf_bist_fail_2(data)                            (0x00000004&((data)<<2))
#define  DM_DM_B05_MBIST_dm_b05_drf_bist_fail_1(data)                            (0x00000002&((data)<<1))
#define  DM_DM_B05_MBIST_dm_b05_drf_bist_fail_0(data)                            (0x00000001&(data))
#define  DM_DM_B05_MBIST_get_dm_b05_ls(data)                                     ((0x80000000&(data))>>31)
#define  DM_DM_B05_MBIST_get_dm_b05_rme(data)                                    ((0x40000000&(data))>>30)
#define  DM_DM_B05_MBIST_get_dm_b05_rm(data)                                     ((0x3C000000&(data))>>26)
#define  DM_DM_B05_MBIST_get_dm_b05_bist_fail_7(data)                            ((0x00008000&(data))>>15)
#define  DM_DM_B05_MBIST_get_dm_b05_bist_fail_6(data)                            ((0x00004000&(data))>>14)
#define  DM_DM_B05_MBIST_get_dm_b05_bist_fail_5(data)                            ((0x00002000&(data))>>13)
#define  DM_DM_B05_MBIST_get_dm_b05_bist_fail_4(data)                            ((0x00001000&(data))>>12)
#define  DM_DM_B05_MBIST_get_dm_b05_bist_fail_3(data)                            ((0x00000800&(data))>>11)
#define  DM_DM_B05_MBIST_get_dm_b05_bist_fail_2(data)                            ((0x00000400&(data))>>10)
#define  DM_DM_B05_MBIST_get_dm_b05_bist_fail_1(data)                            ((0x00000200&(data))>>9)
#define  DM_DM_B05_MBIST_get_dm_b05_bist_fail_0(data)                            ((0x00000100&(data))>>8)
#define  DM_DM_B05_MBIST_get_dm_b05_drf_bist_fail_7(data)                        ((0x00000080&(data))>>7)
#define  DM_DM_B05_MBIST_get_dm_b05_drf_bist_fail_6(data)                        ((0x00000040&(data))>>6)
#define  DM_DM_B05_MBIST_get_dm_b05_drf_bist_fail_5(data)                        ((0x00000020&(data))>>5)
#define  DM_DM_B05_MBIST_get_dm_b05_drf_bist_fail_4(data)                        ((0x00000010&(data))>>4)
#define  DM_DM_B05_MBIST_get_dm_b05_drf_bist_fail_3(data)                        ((0x00000008&(data))>>3)
#define  DM_DM_B05_MBIST_get_dm_b05_drf_bist_fail_2(data)                        ((0x00000004&(data))>>2)
#define  DM_DM_B05_MBIST_get_dm_b05_drf_bist_fail_1(data)                        ((0x00000002&(data))>>1)
#define  DM_DM_B05_MBIST_get_dm_b05_drf_bist_fail_0(data)                        (0x00000001&(data))

#define  DM_DEBUG_SET0                                                           0x1806B73C
#define  DM_DEBUG_SET0_reg_addr                                                  "0xB806B73C"
#define  DM_DEBUG_SET0_reg                                                       0xB806B73C
#define  DM_DEBUG_SET0_inst_addr                                                 "0x00B0"
#define  set_DM_DEBUG_SET0_reg(data)                                             (*((volatile unsigned int*)DM_DEBUG_SET0_reg)=data)
#define  get_DM_DEBUG_SET0_reg                                                   (*((volatile unsigned int*)DM_DEBUG_SET0_reg))
#define  DM_DEBUG_SET0_debug_cb_shift                                            (16)
#define  DM_DEBUG_SET0_debug_cr_shift                                            (0)
#define  DM_DEBUG_SET0_debug_cb_mask                                             (0x3FFF0000)
#define  DM_DEBUG_SET0_debug_cr_mask                                             (0x00003FFF)
#define  DM_DEBUG_SET0_debug_cb(data)                                            (0x3FFF0000&((data)<<16))
#define  DM_DEBUG_SET0_debug_cr(data)                                            (0x00003FFF&(data))
#define  DM_DEBUG_SET0_get_debug_cb(data)                                        ((0x3FFF0000&(data))>>16)
#define  DM_DEBUG_SET0_get_debug_cr(data)                                        (0x00003FFF&(data))

#define  DM_DEBUG_SET1                                                           0x1806B740
#define  DM_DEBUG_SET1_reg_addr                                                  "0xB806B740"
#define  DM_DEBUG_SET1_reg                                                       0xB806B740
#define  DM_DEBUG_SET1_inst_addr                                                 "0x00B1"
#define  set_DM_DEBUG_SET1_reg(data)                                             (*((volatile unsigned int*)DM_DEBUG_SET1_reg)=data)
#define  get_DM_DEBUG_SET1_reg                                                   (*((volatile unsigned int*)DM_DEBUG_SET1_reg))
#define  DM_DEBUG_SET1_debug_y_shift                                             (0)
#define  DM_DEBUG_SET1_debug_y_mask                                              (0x00003FFF)
#define  DM_DEBUG_SET1_debug_y(data)                                             (0x00003FFF&(data))
#define  DM_DEBUG_SET1_get_debug_y(data)                                         (0x00003FFF&(data))

#define  DM_DITHER_SET                                                           0x1806B744
#define  DM_DITHER_SET_reg_addr                                                  "0xB806B744"
#define  DM_DITHER_SET_reg                                                       0xB806B744
#define  DM_DITHER_SET_inst_addr                                                 "0x00B2"
#define  set_DM_DITHER_SET_reg(data)                                             (*((volatile unsigned int*)DM_DITHER_SET_reg)=data)
#define  get_DM_DITHER_SET_reg                                                   (*((volatile unsigned int*)DM_DITHER_SET_reg))
#define  DM_DITHER_SET_dither_fix_pattern_en_shift                               (8)
#define  DM_DITHER_SET_dither_fix_pattern_num_shift                              (0)
#define  DM_DITHER_SET_dither_fix_pattern_en_mask                                (0x00000100)
#define  DM_DITHER_SET_dither_fix_pattern_num_mask                               (0x00000007)
#define  DM_DITHER_SET_dither_fix_pattern_en(data)                               (0x00000100&((data)<<8))
#define  DM_DITHER_SET_dither_fix_pattern_num(data)                              (0x00000007&(data))
#define  DM_DITHER_SET_get_dither_fix_pattern_en(data)                           ((0x00000100&(data))>>8)
#define  DM_DITHER_SET_get_dither_fix_pattern_num(data)                          (0x00000007&(data))

#define  DM_HDR_PATH_SEL                                                         0x1806B760
#define  DM_HDR_PATH_SEL_reg_addr                                                "0xB806B760"
#define  DM_HDR_PATH_SEL_reg                                                     0xB806B760
#define  DM_HDR_PATH_SEL_inst_addr                                               "0x00B3"
#define  set_DM_HDR_PATH_SEL_reg(data)                                           (*((volatile unsigned int*)DM_HDR_PATH_SEL_reg)=data)
#define  get_DM_HDR_PATH_SEL_reg                                                 (*((volatile unsigned int*)DM_HDR_PATH_SEL_reg))
#define  DM_HDR_PATH_SEL_b0107_or_tone_shift                                     (2)
#define  DM_HDR_PATH_SEL_b0105_or_oetf_shift                                     (1)
#define  DM_HDR_PATH_SEL_b0103_or_eotf_shift                                     (0)
#define  DM_HDR_PATH_SEL_b0107_or_tone_mask                                      (0x00000004)
#define  DM_HDR_PATH_SEL_b0105_or_oetf_mask                                      (0x00000002)
#define  DM_HDR_PATH_SEL_b0103_or_eotf_mask                                      (0x00000001)
#define  DM_HDR_PATH_SEL_b0107_or_tone(data)                                     (0x00000004&((data)<<2))
#define  DM_HDR_PATH_SEL_b0105_or_oetf(data)                                     (0x00000002&((data)<<1))
#define  DM_HDR_PATH_SEL_b0103_or_eotf(data)                                     (0x00000001&(data))
#define  DM_HDR_PATH_SEL_get_b0107_or_tone(data)                                 ((0x00000004&(data))>>2)
#define  DM_HDR_PATH_SEL_get_b0105_or_oetf(data)                                 ((0x00000002&(data))>>1)
#define  DM_HDR_PATH_SEL_get_b0103_or_eotf(data)                                 (0x00000001&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======DM register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  dither_en:1;
        RBus_UInt32  format_444to422_dis:1;
        RBus_UInt32  b05_enable:1;
        RBus_UInt32  b04_enable:1;
        RBus_UInt32  b03_enable:1;
        RBus_UInt32  b01_07_enable:1;
        RBus_UInt32  b01_06_enable:1;
        RBus_UInt32  b01_05_enable:1;
        RBus_UInt32  b01_04_enable:1;
        RBus_UInt32  b01_03_enable:1;
        RBus_UInt32  b01_02_enable:1;
        RBus_UInt32  b01_01_422to444_enable:1;
        RBus_UInt32  b01_01_420to422_enable:1;
    };
}dm_dm_submodule_enable_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  dm_inbits_sel:1;
        RBus_UInt32  debug_enable:1;
        RBus_UInt32  runmode:1;
    };
}dm_input_format_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m33yuv2rgb01:16;
        RBus_UInt32  m33yuv2rgb00:16;
    };
}dm_ycctorgb_coef0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  m33yuv2rgb02:16;
    };
}dm_ycctorgb_coef1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m33yuv2rgb11:16;
        RBus_UInt32  m33yuv2rgb10:16;
    };
}dm_ycctorgb_coef2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  m33yuv2rgb12:16;
    };
}dm_ycctorgb_coef3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m33yuv2rgb21:16;
        RBus_UInt32  m33yuv2rgb20:16;
    };
}dm_ycctorgb_coef4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  m33yuv2rgb22:16;
    };
}dm_ycctorgb_coef5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  v3yuv2rgboffinrgb0:32;
    };
}dm_ycctorgb_offset0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  v3yuv2rgboffinrgb1:32;
    };
}dm_ycctorgb_offset1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  v3yuv2rgboffinrgb2:32;
    };
}dm_ycctorgb_offset2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  bt2020_enable:1;
        RBus_UInt32  ycctorgb_scale:5;
    };
}dm_ycctorgb_scale_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rangemax:16;
        RBus_UInt32  rangemin:16;
    };
}dm_signal_range_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  srangeinv:32;
    };
}dm_srangeinv_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  signal_eotf_param1:16;
        RBus_UInt32  signal_eotf_param0:16;
    };
}dm_eotf_para0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  seotf:2;
        RBus_UInt32  signal_eotf:16;
    };
}dm_eotf_para1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  signal_eotf_param2:21;
    };
}dm_eotf_para2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m33rgb2opt01:16;
        RBus_UInt32  m33rgb2opt00:16;
    };
}dm_rgbtoopt_coef0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  m33rgb2opt02:16;
    };
}dm_rgbtoopt_coef1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m33rgb2opt11:16;
        RBus_UInt32  m33rgb2opt10:16;
    };
}dm_rgbtoopt_coef2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  m33rgb2opt12:16;
    };
}dm_rgbtoopt_coef3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m33rgb2opt21:16;
        RBus_UInt32  m33rgb2opt20:16;
    };
}dm_rgbtoopt_coef4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  m33rgb2opt22:16;
    };
}dm_rgbtoopt_coef5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  b0104_max_val_sel:1;
        RBus_UInt32  res1:27;
        RBus_UInt32  rgb2optscale:4;
    };
}dm_rgbtoopt_scale_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rgb2optoffset0:32;
    };
}dm_rgbtoopt_offset0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rgb2optoffset1:32;
    };
}dm_rgbtoopt_offset1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rgb2optoffset2:32;
    };
}dm_rgbtoopt_offset2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m33opt2opt01:16;
        RBus_UInt32  m33opt2opt00:16;
    };
}dm_opttoopt_coef0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  m33opt2opt02:16;
    };
}dm_opttoopt_coef1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m33opt2opt11:16;
        RBus_UInt32  m33opt2opt10:16;
    };
}dm_opttoopt_coef2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  m33opt2opt12:16;
    };
}dm_opttoopt_coef3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m33opt2opt21:16;
        RBus_UInt32  m33opt2opt20:16;
    };
}dm_opttoopt_coef4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  m33opt2opt22:16;
    };
}dm_opttoopt_coef5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  opt2optoffset:16;
    };
}dm_opttoopt_offset_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  opt2optscale:4;
    };
}dm_opttoopt_scale_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  chromaweight:16;
    };
}dm_lumaadj_chromaweight_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_enable:1;
        RBus_UInt32  lut_acc_sel:1;
        RBus_UInt32  lut_rw_sel:2;
        RBus_UInt32  res1:19;
        RBus_UInt32  lut_acc_start_index:9;
    };
}dm_dm_b02_lut_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  write_en:1;
        RBus_UInt32  read_en:1;
    };
}dm_dm_b02_lut_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  lut_data0:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  lut_data1:12;
    };
}dm_dm_b02_lut_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  lut_data2:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  lut_data3:12;
    };
}dm_dm_b02_lut_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  lut_data4:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  lut_data5:12;
    };
}dm_dm_b02_lut_ctrl4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  lut_data6:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  lut_data7:12;
    };
}dm_dm_b02_lut_ctrl5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_acc_ready:1;
        RBus_UInt32  res1:22;
        RBus_UInt32  lut_acc_index_cur:9;
    };
}dm_dm_b02_lut_status0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  lut_data0_out:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  lut_data1_out:12;
    };
}dm_dm_b02_lut_status1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  lut_data2_out:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  lut_data3_out:12;
    };
}dm_dm_b02_lut_status2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  lut_data4_out:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  lut_data5_out:12;
    };
}dm_dm_b02_lut_status3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  lut_data6_out:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  lut_data7_out:12;
    };
}dm_dm_b02_lut_status4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  fw_lut0_rd_acc:1;
        RBus_UInt32  fw_lut0_wr_acc:1;
        RBus_UInt32  hw_lut0_rd_acc:1;
        RBus_UInt32  fw_lut1_rd_acc:1;
        RBus_UInt32  fw_lut1_wr_acc:1;
        RBus_UInt32  hw_lut1_rd_acc:1;
    };
}dm_dm_b02_lut_status5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  weight:16;
        RBus_UInt32  weight_edge:16;
    };
}dm_blenddbedge_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  filter_row_c01:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  filter_row_c00:12;
    };
}dm_filterrow0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  filter_row_c03:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  filter_row_c02:12;
    };
}dm_filterrow1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  filter_row_c05:13;
        RBus_UInt32  res2:4;
        RBus_UInt32  filter_row_c04:12;
    };
}dm_filterrow2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  filter_col_c01:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  filter_col_c00:12;
    };
}dm_filtercol0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  filter_col_c02:13;
    };
}dm_filtercol1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  filter_edge_row_c01:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  filter_edge_row_c00:12;
    };
}dm_filteredgerow0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  filter_edge_row_c03:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  filter_edge_row_c02:12;
    };
}dm_filteredgerow1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  filter_edge_row_c04:12;
    };
}dm_filteredgerow2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  filter_edge_col_c01:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  filter_edge_col_c00:12;
    };
}dm_filteredgecol0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bypass_unsigned_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  saturationadj_offset:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  saturationadj_gain:12;
    };
}dm_saturationadj_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  saturationgain:16;
    };
}dm_saturationgain_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  maxc1:16;
        RBus_UInt32  minc1:16;
    };
}dm_threedlut_minmaxc1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  maxc2:16;
        RBus_UInt32  minc2:16;
    };
}dm_threedlut_minmaxc2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  default_max_sel:1;
        RBus_UInt32  res1:15;
        RBus_UInt32  minc3:16;
    };
}dm_threedlut_minmaxc3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  idistc1inv:20;
    };
}dm_threedlut_minmaxinv1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  idistc2inv:20;
    };
}dm_threedlut_minmaxinv2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  idistc3inv:20;
    };
}dm_threedlut_minmaxinv3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  lut_b05_rw_sel:2;
        RBus_UInt32  lut_b05_write_en:1;
        RBus_UInt32  lut_b05_read_en:1;
        RBus_UInt32  res2:17;
        RBus_UInt32  lut_b05_rw_adr:10;
    };
}dm_dm_b05_lut_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d0_1:16;
        RBus_UInt32  lut_wr_data_d1_1:16;
    };
}dm_dm_b05_lut_wr_data_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  lut_wr_data_d2_1:16;
    };
}dm_dm_b05_lut_wr_data_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d0_2:16;
        RBus_UInt32  lut_wr_data_d1_2:16;
    };
}dm_dm_b05_lut_wr_data_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  lut_wr_data_d2_2:16;
    };
}dm_dm_b05_lut_wr_data_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d0_3:16;
        RBus_UInt32  lut_wr_data_d1_3:16;
    };
}dm_dm_b05_lut_wr_data_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  lut_wr_data_d2_3:16;
    };
}dm_dm_b05_lut_wr_data_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d0_4:16;
        RBus_UInt32  lut_wr_data_d1_4:16;
    };
}dm_dm_b05_lut_wr_data_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  lut_wr_data_d2_4:16;
    };
}dm_dm_b05_lut_wr_data_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d0_5:16;
        RBus_UInt32  lut_wr_data_d1_5:16;
    };
}dm_dm_b05_lut_wr_data_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  lut_wr_data_d2_5:16;
    };
}dm_dm_b05_lut_wr_data_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d0_6:16;
        RBus_UInt32  lut_wr_data_d1_6:16;
    };
}dm_dm_b05_lut_wr_data_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  lut_wr_data_d2_6:16;
    };
}dm_dm_b05_lut_wr_data_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d0_7:16;
        RBus_UInt32  lut_wr_data_d1_7:16;
    };
}dm_dm_b05_lut_wr_data_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  lut_wr_data_d2_7:16;
    };
}dm_dm_b05_lut_wr_data_14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d0_8:16;
        RBus_UInt32  lut_wr_data_d1_8:16;
    };
}dm_dm_b05_lut_wr_data_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  lut_wr_data_d2_8:16;
    };
}dm_dm_b05_lut_wr_data_16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d0_9:16;
        RBus_UInt32  lut_wr_data_d1_9:16;
    };
}dm_dm_b05_lut_wr_data_17_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  lut_wr_data_d2_9:16;
    };
}dm_dm_b05_lut_wr_data_18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d0_10:16;
        RBus_UInt32  lut_wr_data_d1_10:16;
    };
}dm_dm_b05_lut_wr_data_19_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  lut_wr_data_d2_10:16;
    };
}dm_dm_b05_lut_wr_data_20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d0_11:16;
        RBus_UInt32  lut_wr_data_d1_11:16;
    };
}dm_dm_b05_lut_wr_data_21_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  lut_wr_data_d2_11:16;
    };
}dm_dm_b05_lut_wr_data_22_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d0_12:16;
        RBus_UInt32  lut_wr_data_d1_12:16;
    };
}dm_dm_b05_lut_wr_data_23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  lut_wr_data_d2_12:16;
    };
}dm_dm_b05_lut_wr_data_24_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d0_13:16;
        RBus_UInt32  lut_wr_data_d1_13:16;
    };
}dm_dm_b05_lut_wr_data_25_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  lut_wr_data_d2_13:16;
    };
}dm_dm_b05_lut_wr_data_26_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d0_14:16;
        RBus_UInt32  lut_wr_data_d1_14:16;
    };
}dm_dm_b05_lut_wr_data_27_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  lut_wr_data_d2_14:16;
    };
}dm_dm_b05_lut_wr_data_28_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d0_15:16;
        RBus_UInt32  lut_wr_data_d1_15:16;
    };
}dm_dm_b05_lut_wr_data_29_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  lut_wr_data_d2_15:16;
    };
}dm_dm_b05_lut_wr_data_30_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d0_16:16;
        RBus_UInt32  lut_wr_data_d1_16:16;
    };
}dm_dm_b05_lut_wr_data_31_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  lut_wr_data_d2_16:16;
    };
}dm_dm_b05_lut_wr_data_32_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d0_17:16;
        RBus_UInt32  lut_wr_data_d1_17:16;
    };
}dm_dm_b05_lut_wr_data_33_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  lut_wr_data_d2_17:16;
    };
}dm_dm_b05_lut_wr_data_34_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d0_1:16;
        RBus_UInt32  lut_rd_data_d1_1:16;
    };
}dm_dm_b05_lut_rd_data_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  lut_rd_data_d2_1:16;
    };
}dm_dm_b05_lut_rd_data_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d0_2:16;
        RBus_UInt32  lut_rd_data_d1_2:16;
    };
}dm_dm_b05_lut_rd_data_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  lut_rd_data_d2_2:16;
    };
}dm_dm_b05_lut_rd_data_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d0_3:16;
        RBus_UInt32  lut_rd_data_d1_3:16;
    };
}dm_dm_b05_lut_rd_data_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  lut_rd_data_d2_3:16;
    };
}dm_dm_b05_lut_rd_data_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d0_4:16;
        RBus_UInt32  lut_rd_data_d1_4:16;
    };
}dm_dm_b05_lut_rd_data_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  lut_rd_data_d2_4:16;
    };
}dm_dm_b05_lut_rd_data_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d0_5:16;
        RBus_UInt32  lut_rd_data_d1_5:16;
    };
}dm_dm_b05_lut_rd_data_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  lut_rd_data_d2_5:16;
    };
}dm_dm_b05_lut_rd_data_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d0_6:16;
        RBus_UInt32  lut_rd_data_d1_6:16;
    };
}dm_dm_b05_lut_rd_data_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  lut_rd_data_d2_6:16;
    };
}dm_dm_b05_lut_rd_data_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d0_7:16;
        RBus_UInt32  lut_rd_data_d1_7:16;
    };
}dm_dm_b05_lut_rd_data_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  lut_rd_data_d2_7:16;
    };
}dm_dm_b05_lut_rd_data_14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d0_8:16;
        RBus_UInt32  lut_rd_data_d1_8:16;
    };
}dm_dm_b05_lut_rd_data_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  lut_rd_data_d2_8:16;
    };
}dm_dm_b05_lut_rd_data_16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d0_9:16;
        RBus_UInt32  lut_rd_data_d1_9:16;
    };
}dm_dm_b05_lut_rd_data_17_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  lut_rd_data_d2_9:16;
    };
}dm_dm_b05_lut_rd_data_18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d0_10:16;
        RBus_UInt32  lut_rd_data_d1_10:16;
    };
}dm_dm_b05_lut_rd_data_19_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  lut_rd_data_d2_10:16;
    };
}dm_dm_b05_lut_rd_data_20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d0_11:16;
        RBus_UInt32  lut_rd_data_d1_11:16;
    };
}dm_dm_b05_lut_rd_data_21_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  lut_rd_data_d2_11:16;
    };
}dm_dm_b05_lut_rd_data_22_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d0_12:16;
        RBus_UInt32  lut_rd_data_d1_12:16;
    };
}dm_dm_b05_lut_rd_data_23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  lut_rd_data_d2_12:16;
    };
}dm_dm_b05_lut_rd_data_24_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d0_13:16;
        RBus_UInt32  lut_rd_data_d1_13:16;
    };
}dm_dm_b05_lut_rd_data_25_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  lut_rd_data_d2_13:16;
    };
}dm_dm_b05_lut_rd_data_26_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d0_14:16;
        RBus_UInt32  lut_rd_data_d1_14:16;
    };
}dm_dm_b05_lut_rd_data_27_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  lut_rd_data_d2_14:16;
    };
}dm_dm_b05_lut_rd_data_28_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d0_15:16;
        RBus_UInt32  lut_rd_data_d1_15:16;
    };
}dm_dm_b05_lut_rd_data_29_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  lut_rd_data_d2_15:16;
    };
}dm_dm_b05_lut_rd_data_30_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d0_16:16;
        RBus_UInt32  lut_rd_data_d1_16:16;
    };
}dm_dm_b05_lut_rd_data_31_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  lut_rd_data_d2_16:16;
    };
}dm_dm_b05_lut_rd_data_32_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d0_17:16;
        RBus_UInt32  lut_rd_data_d1_17:16;
    };
}dm_dm_b05_lut_rd_data_33_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  lut_rd_data_d2_17:16;
    };
}dm_dm_b05_lut_rd_data_34_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  lut24_b05_rw_sel:2;
        RBus_UInt32  lut24_b05_write_en:1;
        RBus_UInt32  lut24_b05_read_en:1;
        RBus_UInt32  res2:17;
        RBus_UInt32  lut24_b05_rw_adr:10;
    };
}dm_dm_b05_lut_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut24_b05_acc_ready:1;
        RBus_UInt32  res1:22;
        RBus_UInt32  lut24_b05_acc_sel:1;
        RBus_UInt32  res2:6;
        RBus_UInt32  dm_b05_input_ctrl:1;
        RBus_UInt32  dm_b05_dimension:1;
    };
}dm_dm_b05_lut_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  lut24_b05_fw_lut0_rd_acc:1;
        RBus_UInt32  lut24_b05_fw_lut0_wr_acc:1;
        RBus_UInt32  lut24_b05_hw_lut0_rd_acc:1;
        RBus_UInt32  lut24_b05_fw_lut1_rd_acc:1;
        RBus_UInt32  lut24_b05_fw_lut1_wr_acc:1;
        RBus_UInt32  lut24_b05_hw_lut1_rd_acc:1;
    };
}dm_dm_b05_lut_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d0_18:16;
        RBus_UInt32  lut_wr_data_d1_18:16;
    };
}dm_dm_b05_lut_wr_data_35_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  lut_wr_data_d2_18:16;
    };
}dm_dm_b05_lut_wr_data_36_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d0_19:16;
        RBus_UInt32  lut_wr_data_d1_19:16;
    };
}dm_dm_b05_lut_wr_data_37_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  lut_wr_data_d2_19:16;
    };
}dm_dm_b05_lut_wr_data_38_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d0_20:16;
        RBus_UInt32  lut_wr_data_d1_20:16;
    };
}dm_dm_b05_lut_wr_data_39_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  lut_wr_data_d2_20:16;
    };
}dm_dm_b05_lut_wr_data_40_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d0_21:16;
        RBus_UInt32  lut_wr_data_d1_21:16;
    };
}dm_dm_b05_lut_wr_data_41_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  lut_wr_data_d2_21:16;
    };
}dm_dm_b05_lut_wr_data_42_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d0_22:16;
        RBus_UInt32  lut_wr_data_d1_22:16;
    };
}dm_dm_b05_lut_wr_data_43_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  lut_wr_data_d2_22:16;
    };
}dm_dm_b05_lut_wr_data_44_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d0_23:16;
        RBus_UInt32  lut_wr_data_d1_23:16;
    };
}dm_dm_b05_lut_wr_data_45_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  lut_wr_data_d2_23:16;
    };
}dm_dm_b05_lut_wr_data_46_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d0_24:16;
        RBus_UInt32  lut_wr_data_d1_24:16;
    };
}dm_dm_b05_lut_wr_data_47_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  lut_wr_data_d2_24:16;
    };
}dm_dm_b05_lut_wr_data_48_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d0_18:16;
        RBus_UInt32  lut_rd_data_d1_18:16;
    };
}dm_dm_b05_lut_rd_data_35_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  lut_rd_data_d2_18:16;
    };
}dm_dm_b05_lut_rd_data_36_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d0_19:16;
        RBus_UInt32  lut_rd_data_d1_19:16;
    };
}dm_dm_b05_lut_rd_data_37_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  lut_rd_data_d2_19:16;
    };
}dm_dm_b05_lut_rd_data_38_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d0_20:16;
        RBus_UInt32  lut_rd_data_d1_20:16;
    };
}dm_dm_b05_lut_rd_data_39_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  lut_rd_data_d2_20:16;
    };
}dm_dm_b05_lut_rd_data_40_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d0_21:16;
        RBus_UInt32  lut_rd_data_d1_21:16;
    };
}dm_dm_b05_lut_rd_data_41_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  lut_rd_data_d2_21:16;
    };
}dm_dm_b05_lut_rd_data_42_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d0_22:16;
        RBus_UInt32  lut_rd_data_d1_22:16;
    };
}dm_dm_b05_lut_rd_data_43_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  lut_rd_data_d2_22:16;
    };
}dm_dm_b05_lut_rd_data_44_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d0_23:16;
        RBus_UInt32  lut_rd_data_d1_23:16;
    };
}dm_dm_b05_lut_rd_data_45_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  lut_rd_data_d2_23:16;
    };
}dm_dm_b05_lut_rd_data_46_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d0_24:16;
        RBus_UInt32  lut_rd_data_d1_24:16;
    };
}dm_dm_b05_lut_rd_data_47_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  lut_rd_data_d2_24:16;
    };
}dm_dm_b05_lut_rd_data_48_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  dm_db_en:1;
        RBus_UInt32  dm_db_read_sel:1;
        RBus_UInt32  dm_db_apply:1;
    };
}dm_hdr_dm_double_buffer_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dm_b01_1_ls:1;
        RBus_UInt32  dm_b01_1_rme:1;
        RBus_UInt32  dm_b01_1_rm:4;
        RBus_UInt32  res1:13;
        RBus_UInt32  dm_b01_1_bist_fail_4:1;
        RBus_UInt32  dm_b01_1_bist_fail_3:1;
        RBus_UInt32  dm_b01_1_bist_fail_2:1;
        RBus_UInt32  dm_b01_1_bist_fail_1:1;
        RBus_UInt32  dm_b01_1_bist_fail_0:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  dm_b01_1_drf_bist_fail_4:1;
        RBus_UInt32  dm_b01_1_drf_bist_fail_3:1;
        RBus_UInt32  dm_b01_1_drf_bist_fail_2:1;
        RBus_UInt32  dm_b01_1_drf_bist_fail_1:1;
        RBus_UInt32  dm_b01_1_drf_bist_fail_0:1;
    };
}dm_dm_b01_1_mbist_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dm_b01_2_0_ls:1;
        RBus_UInt32  dm_b01_2_0_rme:1;
        RBus_UInt32  dm_b01_2_0_rm:4;
        RBus_UInt32  res1:12;
        RBus_UInt32  dm_b01_2_0_bist_fail_5:1;
        RBus_UInt32  dm_b01_2_0_bist_fail_4:1;
        RBus_UInt32  dm_b01_2_0_bist_fail_3:1;
        RBus_UInt32  dm_b01_2_0_bist_fail_2:1;
        RBus_UInt32  dm_b01_2_0_bist_fail_1:1;
        RBus_UInt32  dm_b01_2_0_bist_fail_0:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  dm_b01_2_0_drf_bist_fail_5:1;
        RBus_UInt32  dm_b01_2_0_drf_bist_fail_4:1;
        RBus_UInt32  dm_b01_2_0_drf_bist_fail_3:1;
        RBus_UInt32  dm_b01_2_0_drf_bist_fail_2:1;
        RBus_UInt32  dm_b01_2_0_drf_bist_fail_1:1;
        RBus_UInt32  dm_b01_2_0_drf_bist_fail_0:1;
    };
}dm_dm_b01_2_0_mbist_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dm_b01_2_1_ls:1;
        RBus_UInt32  dm_b01_2_1_rme:1;
        RBus_UInt32  dm_b01_2_1_rm:4;
        RBus_UInt32  res1:12;
        RBus_UInt32  dm_b01_2_1_bist_fail_5:1;
        RBus_UInt32  dm_b01_2_1_bist_fail_4:1;
        RBus_UInt32  dm_b01_2_1_bist_fail_3:1;
        RBus_UInt32  dm_b01_2_1_bist_fail_2:1;
        RBus_UInt32  dm_b01_2_1_bist_fail_1:1;
        RBus_UInt32  dm_b01_2_1_bist_fail_0:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  dm_b01_2_1_drf_bist_fail_5:1;
        RBus_UInt32  dm_b01_2_1_drf_bist_fail_4:1;
        RBus_UInt32  dm_b01_2_1_drf_bist_fail_3:1;
        RBus_UInt32  dm_b01_2_1_drf_bist_fail_2:1;
        RBus_UInt32  dm_b01_2_1_drf_bist_fail_1:1;
        RBus_UInt32  dm_b01_2_1_drf_bist_fail_0:1;
    };
}dm_dm_b01_2_1_mbist_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dm_b02_1_ls:1;
        RBus_UInt32  dm_b02_1_rme:1;
        RBus_UInt32  dm_b02_1_rm:4;
        RBus_UInt32  res1:1;
        RBus_UInt32  dm_b02_1_bist_fail_11:1;
        RBus_UInt32  dm_b02_1_bist_fail_10:1;
        RBus_UInt32  dm_b02_1_bist_fail_9:1;
        RBus_UInt32  dm_b02_1_bist_fail_8:1;
        RBus_UInt32  dm_b02_1_bist_fail_7:1;
        RBus_UInt32  dm_b02_1_bist_fail_6:1;
        RBus_UInt32  dm_b02_1_bist_fail_5:1;
        RBus_UInt32  dm_b02_1_bist_fail_4:1;
        RBus_UInt32  dm_b02_1_bist_fail_3:1;
        RBus_UInt32  dm_b02_1_bist_fail_2:1;
        RBus_UInt32  dm_b02_1_bist_fail_1:1;
        RBus_UInt32  dm_b02_1_bist_fail_0:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  dm_b02_1_drf_bist_fail_11:1;
        RBus_UInt32  dm_b02_1_drf_bist_fail_10:1;
        RBus_UInt32  dm_b02_1_drf_bist_fail_9:1;
        RBus_UInt32  dm_b02_1_drf_bist_fail_8:1;
        RBus_UInt32  dm_b02_1_drf_bist_fail_7:1;
        RBus_UInt32  dm_b02_1_drf_bist_fail_6:1;
        RBus_UInt32  dm_b02_1_drf_bist_fail_5:1;
        RBus_UInt32  dm_b02_1_drf_bist_fail_4:1;
        RBus_UInt32  dm_b02_1_drf_bist_fail_3:1;
        RBus_UInt32  dm_b02_1_drf_bist_fail_2:1;
        RBus_UInt32  dm_b02_1_drf_bist_fail_1:1;
        RBus_UInt32  dm_b02_1_drf_bist_fail_0:1;
    };
}dm_dm_b02_1_mbist_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dm_b02_2_ls:1;
        RBus_UInt32  dm_b02_2_rme:1;
        RBus_UInt32  dm_b02_2_rm:4;
        RBus_UInt32  res1:17;
        RBus_UInt32  dm_b02_2_bist_fail_0:1;
        RBus_UInt32  res2:7;
        RBus_UInt32  dm_b02_2_drf_bist_fail_0:1;
    };
}dm_dm_b02_2_mbist_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dm_hist_ls:1;
        RBus_UInt32  dm_hist_rme:1;
        RBus_UInt32  dm_hist_rm:4;
        RBus_UInt32  res1:8;
        RBus_UInt32  dm_hist_testrwm_0:1;
        RBus_UInt32  dm_hist_testrwm_1:1;
        RBus_UInt32  res2:6;
        RBus_UInt32  dm_hist_bist_fail_1:1;
        RBus_UInt32  dm_hist_bist_fail_0:1;
        RBus_UInt32  res3:6;
        RBus_UInt32  dm_hist_drf_bist_fail_1:1;
        RBus_UInt32  dm_hist_drf_bist_fail_0:1;
    };
}dm_dm_hist_mbist_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dm_b03_1_ls:1;
        RBus_UInt32  dm_b03_1_rme:1;
        RBus_UInt32  dm_b03_1_rm:4;
        RBus_UInt32  res1:1;
        RBus_UInt32  dm_b03_1_bist_fail_11:1;
        RBus_UInt32  dm_b03_1_bist_fail_10:1;
        RBus_UInt32  dm_b03_1_bist_fail_9:1;
        RBus_UInt32  dm_b03_1_bist_fail_8:1;
        RBus_UInt32  dm_b03_1_bist_fail_7:1;
        RBus_UInt32  dm_b03_1_bist_fail_6:1;
        RBus_UInt32  dm_b03_1_bist_fail_5:1;
        RBus_UInt32  dm_b03_1_bist_fail_4:1;
        RBus_UInt32  dm_b03_1_bist_fail_3:1;
        RBus_UInt32  dm_b03_1_bist_fail_2:1;
        RBus_UInt32  dm_b03_1_bist_fail_1:1;
        RBus_UInt32  dm_b03_1_bist_fail_0:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  dm_b03_1_drf_bist_fail_11:1;
        RBus_UInt32  dm_b03_1_drf_bist_fail_10:1;
        RBus_UInt32  dm_b03_1_drf_bist_fail_9:1;
        RBus_UInt32  dm_b03_1_drf_bist_fail_8:1;
        RBus_UInt32  dm_b03_1_drf_bist_fail_7:1;
        RBus_UInt32  dm_b03_1_drf_bist_fail_6:1;
        RBus_UInt32  dm_b03_1_drf_bist_fail_5:1;
        RBus_UInt32  dm_b03_1_drf_bist_fail_4:1;
        RBus_UInt32  dm_b03_1_drf_bist_fail_3:1;
        RBus_UInt32  dm_b03_1_drf_bist_fail_2:1;
        RBus_UInt32  dm_b03_1_drf_bist_fail_1:1;
        RBus_UInt32  dm_b03_1_drf_bist_fail_0:1;
    };
}dm_dm_b03_1_mbist_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dm_b03_2_ls:1;
        RBus_UInt32  dm_b03_2_rme:1;
        RBus_UInt32  dm_b03_2_rm:4;
        RBus_UInt32  res1:14;
        RBus_UInt32  dm_b03_2_bist_fail_3:1;
        RBus_UInt32  dm_b03_2_bist_fail_2:1;
        RBus_UInt32  dm_b03_2_bist_fail_1:1;
        RBus_UInt32  dm_b03_2_bist_fail_0:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  dm_b03_2_drf_bist_fail_3:1;
        RBus_UInt32  dm_b03_2_drf_bist_fail_2:1;
        RBus_UInt32  dm_b03_2_drf_bist_fail_1:1;
        RBus_UInt32  dm_b03_2_drf_bist_fail_0:1;
    };
}dm_dm_b03_2_mbist_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dm_b05_ls:1;
        RBus_UInt32  dm_b05_rme:1;
        RBus_UInt32  dm_b05_rm:4;
        RBus_UInt32  res1:10;
        RBus_UInt32  dm_b05_bist_fail_7:1;
        RBus_UInt32  dm_b05_bist_fail_6:1;
        RBus_UInt32  dm_b05_bist_fail_5:1;
        RBus_UInt32  dm_b05_bist_fail_4:1;
        RBus_UInt32  dm_b05_bist_fail_3:1;
        RBus_UInt32  dm_b05_bist_fail_2:1;
        RBus_UInt32  dm_b05_bist_fail_1:1;
        RBus_UInt32  dm_b05_bist_fail_0:1;
        RBus_UInt32  dm_b05_drf_bist_fail_7:1;
        RBus_UInt32  dm_b05_drf_bist_fail_6:1;
        RBus_UInt32  dm_b05_drf_bist_fail_5:1;
        RBus_UInt32  dm_b05_drf_bist_fail_4:1;
        RBus_UInt32  dm_b05_drf_bist_fail_3:1;
        RBus_UInt32  dm_b05_drf_bist_fail_2:1;
        RBus_UInt32  dm_b05_drf_bist_fail_1:1;
        RBus_UInt32  dm_b05_drf_bist_fail_0:1;
    };
}dm_dm_b05_mbist_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  debug_cb:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  debug_cr:14;
    };
}dm_debug_set0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  debug_y:14;
    };
}dm_debug_set1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  dither_fix_pattern_en:1;
        RBus_UInt32  res2:5;
        RBus_UInt32  dither_fix_pattern_num:3;
    };
}dm_dither_set_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  b0107_or_tone:1;
        RBus_UInt32  b0105_or_oetf:1;
        RBus_UInt32  b0103_or_eotf:1;
    };
}dm_hdr_path_sel_RBUS;

#else //apply LITTLE_ENDIAN

//======DM register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  b01_01_420to422_enable:1;
        RBus_UInt32  b01_01_422to444_enable:1;
        RBus_UInt32  b01_02_enable:1;
        RBus_UInt32  b01_03_enable:1;
        RBus_UInt32  b01_04_enable:1;
        RBus_UInt32  b01_05_enable:1;
        RBus_UInt32  b01_06_enable:1;
        RBus_UInt32  b01_07_enable:1;
        RBus_UInt32  b03_enable:1;
        RBus_UInt32  b04_enable:1;
        RBus_UInt32  b05_enable:1;
        RBus_UInt32  format_444to422_dis:1;
        RBus_UInt32  dither_en:1;
        RBus_UInt32  res1:19;
    };
}dm_dm_submodule_enable_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  runmode:1;
        RBus_UInt32  debug_enable:1;
        RBus_UInt32  dm_inbits_sel:1;
        RBus_UInt32  res1:29;
    };
}dm_input_format_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m33yuv2rgb00:16;
        RBus_UInt32  m33yuv2rgb01:16;
    };
}dm_ycctorgb_coef0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m33yuv2rgb02:16;
        RBus_UInt32  res1:16;
    };
}dm_ycctorgb_coef1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m33yuv2rgb10:16;
        RBus_UInt32  m33yuv2rgb11:16;
    };
}dm_ycctorgb_coef2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m33yuv2rgb12:16;
        RBus_UInt32  res1:16;
    };
}dm_ycctorgb_coef3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m33yuv2rgb20:16;
        RBus_UInt32  m33yuv2rgb21:16;
    };
}dm_ycctorgb_coef4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m33yuv2rgb22:16;
        RBus_UInt32  res1:16;
    };
}dm_ycctorgb_coef5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  v3yuv2rgboffinrgb0:32;
    };
}dm_ycctorgb_offset0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  v3yuv2rgboffinrgb1:32;
    };
}dm_ycctorgb_offset1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  v3yuv2rgboffinrgb2:32;
    };
}dm_ycctorgb_offset2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ycctorgb_scale:5;
        RBus_UInt32  bt2020_enable:1;
        RBus_UInt32  res1:26;
    };
}dm_ycctorgb_scale_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rangemin:16;
        RBus_UInt32  rangemax:16;
    };
}dm_signal_range_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  srangeinv:32;
    };
}dm_srangeinv_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  signal_eotf_param0:16;
        RBus_UInt32  signal_eotf_param1:16;
    };
}dm_eotf_para0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  signal_eotf:16;
        RBus_UInt32  seotf:2;
        RBus_UInt32  res1:14;
    };
}dm_eotf_para1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  signal_eotf_param2:21;
        RBus_UInt32  res1:11;
    };
}dm_eotf_para2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m33rgb2opt00:16;
        RBus_UInt32  m33rgb2opt01:16;
    };
}dm_rgbtoopt_coef0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m33rgb2opt02:16;
        RBus_UInt32  res1:16;
    };
}dm_rgbtoopt_coef1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m33rgb2opt10:16;
        RBus_UInt32  m33rgb2opt11:16;
    };
}dm_rgbtoopt_coef2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m33rgb2opt12:16;
        RBus_UInt32  res1:16;
    };
}dm_rgbtoopt_coef3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m33rgb2opt20:16;
        RBus_UInt32  m33rgb2opt21:16;
    };
}dm_rgbtoopt_coef4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m33rgb2opt22:16;
        RBus_UInt32  res1:16;
    };
}dm_rgbtoopt_coef5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rgb2optscale:4;
        RBus_UInt32  res1:27;
        RBus_UInt32  b0104_max_val_sel:1;
    };
}dm_rgbtoopt_scale_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rgb2optoffset0:32;
    };
}dm_rgbtoopt_offset0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rgb2optoffset1:32;
    };
}dm_rgbtoopt_offset1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rgb2optoffset2:32;
    };
}dm_rgbtoopt_offset2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m33opt2opt00:16;
        RBus_UInt32  m33opt2opt01:16;
    };
}dm_opttoopt_coef0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m33opt2opt02:16;
        RBus_UInt32  res1:16;
    };
}dm_opttoopt_coef1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m33opt2opt10:16;
        RBus_UInt32  m33opt2opt11:16;
    };
}dm_opttoopt_coef2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m33opt2opt12:16;
        RBus_UInt32  res1:16;
    };
}dm_opttoopt_coef3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m33opt2opt20:16;
        RBus_UInt32  m33opt2opt21:16;
    };
}dm_opttoopt_coef4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m33opt2opt22:16;
        RBus_UInt32  res1:16;
    };
}dm_opttoopt_coef5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt2optoffset:16;
        RBus_UInt32  res1:16;
    };
}dm_opttoopt_offset_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt2optscale:4;
        RBus_UInt32  res1:28;
    };
}dm_opttoopt_scale_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  chromaweight:16;
        RBus_UInt32  res1:16;
    };
}dm_lumaadj_chromaweight_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_acc_start_index:9;
        RBus_UInt32  res1:19;
        RBus_UInt32  lut_rw_sel:2;
        RBus_UInt32  lut_acc_sel:1;
        RBus_UInt32  lut_enable:1;
    };
}dm_dm_b02_lut_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  read_en:1;
        RBus_UInt32  write_en:1;
        RBus_UInt32  res1:30;
    };
}dm_dm_b02_lut_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_data1:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  lut_data0:12;
        RBus_UInt32  res2:4;
    };
}dm_dm_b02_lut_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_data3:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  lut_data2:12;
        RBus_UInt32  res2:4;
    };
}dm_dm_b02_lut_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_data5:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  lut_data4:12;
        RBus_UInt32  res2:4;
    };
}dm_dm_b02_lut_ctrl4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_data7:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  lut_data6:12;
        RBus_UInt32  res2:4;
    };
}dm_dm_b02_lut_ctrl5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_acc_index_cur:9;
        RBus_UInt32  res1:22;
        RBus_UInt32  lut_acc_ready:1;
    };
}dm_dm_b02_lut_status0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_data1_out:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  lut_data0_out:12;
        RBus_UInt32  res2:4;
    };
}dm_dm_b02_lut_status1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_data3_out:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  lut_data2_out:12;
        RBus_UInt32  res2:4;
    };
}dm_dm_b02_lut_status2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_data5_out:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  lut_data4_out:12;
        RBus_UInt32  res2:4;
    };
}dm_dm_b02_lut_status3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_data7_out:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  lut_data6_out:12;
        RBus_UInt32  res2:4;
    };
}dm_dm_b02_lut_status4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hw_lut1_rd_acc:1;
        RBus_UInt32  fw_lut1_wr_acc:1;
        RBus_UInt32  fw_lut1_rd_acc:1;
        RBus_UInt32  hw_lut0_rd_acc:1;
        RBus_UInt32  fw_lut0_wr_acc:1;
        RBus_UInt32  fw_lut0_rd_acc:1;
        RBus_UInt32  res1:26;
    };
}dm_dm_b02_lut_status5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  weight_edge:16;
        RBus_UInt32  weight:16;
    };
}dm_blenddbedge_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  filter_row_c00:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  filter_row_c01:12;
        RBus_UInt32  res2:4;
    };
}dm_filterrow0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  filter_row_c02:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  filter_row_c03:12;
        RBus_UInt32  res2:4;
    };
}dm_filterrow1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  filter_row_c04:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  filter_row_c05:13;
        RBus_UInt32  res2:3;
    };
}dm_filterrow2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  filter_col_c00:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  filter_col_c01:12;
        RBus_UInt32  res2:4;
    };
}dm_filtercol0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  filter_col_c02:13;
        RBus_UInt32  res1:19;
    };
}dm_filtercol1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  filter_edge_row_c00:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  filter_edge_row_c01:12;
        RBus_UInt32  res2:4;
    };
}dm_filteredgerow0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  filter_edge_row_c02:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  filter_edge_row_c03:12;
        RBus_UInt32  res2:4;
    };
}dm_filteredgerow1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  filter_edge_row_c04:12;
        RBus_UInt32  res1:20;
    };
}dm_filteredgerow2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  filter_edge_col_c00:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  filter_edge_col_c01:12;
        RBus_UInt32  res2:4;
    };
}dm_filteredgecol0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  saturationadj_gain:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  saturationadj_offset:12;
        RBus_UInt32  res2:3;
        RBus_UInt32  bypass_unsigned_en:1;
    };
}dm_saturationadj_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  saturationgain:16;
        RBus_UInt32  res1:16;
    };
}dm_saturationgain_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  minc1:16;
        RBus_UInt32  maxc1:16;
    };
}dm_threedlut_minmaxc1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  minc2:16;
        RBus_UInt32  maxc2:16;
    };
}dm_threedlut_minmaxc2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  minc3:16;
        RBus_UInt32  res1:15;
        RBus_UInt32  default_max_sel:1;
    };
}dm_threedlut_minmaxc3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  idistc1inv:20;
        RBus_UInt32  res1:12;
    };
}dm_threedlut_minmaxinv1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  idistc2inv:20;
        RBus_UInt32  res1:12;
    };
}dm_threedlut_minmaxinv2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  idistc3inv:20;
        RBus_UInt32  res1:12;
    };
}dm_threedlut_minmaxinv3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_b05_rw_adr:10;
        RBus_UInt32  res1:17;
        RBus_UInt32  lut_b05_read_en:1;
        RBus_UInt32  lut_b05_write_en:1;
        RBus_UInt32  lut_b05_rw_sel:2;
        RBus_UInt32  res2:1;
    };
}dm_dm_b05_lut_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d1_1:16;
        RBus_UInt32  lut_wr_data_d0_1:16;
    };
}dm_dm_b05_lut_wr_data_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d2_1:16;
        RBus_UInt32  res1:16;
    };
}dm_dm_b05_lut_wr_data_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d1_2:16;
        RBus_UInt32  lut_wr_data_d0_2:16;
    };
}dm_dm_b05_lut_wr_data_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d2_2:16;
        RBus_UInt32  res1:16;
    };
}dm_dm_b05_lut_wr_data_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d1_3:16;
        RBus_UInt32  lut_wr_data_d0_3:16;
    };
}dm_dm_b05_lut_wr_data_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d2_3:16;
        RBus_UInt32  res1:16;
    };
}dm_dm_b05_lut_wr_data_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d1_4:16;
        RBus_UInt32  lut_wr_data_d0_4:16;
    };
}dm_dm_b05_lut_wr_data_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d2_4:16;
        RBus_UInt32  res1:16;
    };
}dm_dm_b05_lut_wr_data_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d1_5:16;
        RBus_UInt32  lut_wr_data_d0_5:16;
    };
}dm_dm_b05_lut_wr_data_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d2_5:16;
        RBus_UInt32  res1:16;
    };
}dm_dm_b05_lut_wr_data_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d1_6:16;
        RBus_UInt32  lut_wr_data_d0_6:16;
    };
}dm_dm_b05_lut_wr_data_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d2_6:16;
        RBus_UInt32  res1:16;
    };
}dm_dm_b05_lut_wr_data_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d1_7:16;
        RBus_UInt32  lut_wr_data_d0_7:16;
    };
}dm_dm_b05_lut_wr_data_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d2_7:16;
        RBus_UInt32  res1:16;
    };
}dm_dm_b05_lut_wr_data_14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d1_8:16;
        RBus_UInt32  lut_wr_data_d0_8:16;
    };
}dm_dm_b05_lut_wr_data_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d2_8:16;
        RBus_UInt32  res1:16;
    };
}dm_dm_b05_lut_wr_data_16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d1_9:16;
        RBus_UInt32  lut_wr_data_d0_9:16;
    };
}dm_dm_b05_lut_wr_data_17_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d2_9:16;
        RBus_UInt32  res1:16;
    };
}dm_dm_b05_lut_wr_data_18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d1_10:16;
        RBus_UInt32  lut_wr_data_d0_10:16;
    };
}dm_dm_b05_lut_wr_data_19_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d2_10:16;
        RBus_UInt32  res1:16;
    };
}dm_dm_b05_lut_wr_data_20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d1_11:16;
        RBus_UInt32  lut_wr_data_d0_11:16;
    };
}dm_dm_b05_lut_wr_data_21_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d2_11:16;
        RBus_UInt32  res1:16;
    };
}dm_dm_b05_lut_wr_data_22_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d1_12:16;
        RBus_UInt32  lut_wr_data_d0_12:16;
    };
}dm_dm_b05_lut_wr_data_23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d2_12:16;
        RBus_UInt32  res1:16;
    };
}dm_dm_b05_lut_wr_data_24_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d1_13:16;
        RBus_UInt32  lut_wr_data_d0_13:16;
    };
}dm_dm_b05_lut_wr_data_25_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d2_13:16;
        RBus_UInt32  res1:16;
    };
}dm_dm_b05_lut_wr_data_26_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d1_14:16;
        RBus_UInt32  lut_wr_data_d0_14:16;
    };
}dm_dm_b05_lut_wr_data_27_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d2_14:16;
        RBus_UInt32  res1:16;
    };
}dm_dm_b05_lut_wr_data_28_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d1_15:16;
        RBus_UInt32  lut_wr_data_d0_15:16;
    };
}dm_dm_b05_lut_wr_data_29_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d2_15:16;
        RBus_UInt32  res1:16;
    };
}dm_dm_b05_lut_wr_data_30_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d1_16:16;
        RBus_UInt32  lut_wr_data_d0_16:16;
    };
}dm_dm_b05_lut_wr_data_31_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d2_16:16;
        RBus_UInt32  res1:16;
    };
}dm_dm_b05_lut_wr_data_32_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d1_17:16;
        RBus_UInt32  lut_wr_data_d0_17:16;
    };
}dm_dm_b05_lut_wr_data_33_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d2_17:16;
        RBus_UInt32  res1:16;
    };
}dm_dm_b05_lut_wr_data_34_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d1_1:16;
        RBus_UInt32  lut_rd_data_d0_1:16;
    };
}dm_dm_b05_lut_rd_data_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d2_1:16;
        RBus_UInt32  res1:16;
    };
}dm_dm_b05_lut_rd_data_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d1_2:16;
        RBus_UInt32  lut_rd_data_d0_2:16;
    };
}dm_dm_b05_lut_rd_data_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d2_2:16;
        RBus_UInt32  res1:16;
    };
}dm_dm_b05_lut_rd_data_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d1_3:16;
        RBus_UInt32  lut_rd_data_d0_3:16;
    };
}dm_dm_b05_lut_rd_data_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d2_3:16;
        RBus_UInt32  res1:16;
    };
}dm_dm_b05_lut_rd_data_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d1_4:16;
        RBus_UInt32  lut_rd_data_d0_4:16;
    };
}dm_dm_b05_lut_rd_data_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d2_4:16;
        RBus_UInt32  res1:16;
    };
}dm_dm_b05_lut_rd_data_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d1_5:16;
        RBus_UInt32  lut_rd_data_d0_5:16;
    };
}dm_dm_b05_lut_rd_data_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d2_5:16;
        RBus_UInt32  res1:16;
    };
}dm_dm_b05_lut_rd_data_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d1_6:16;
        RBus_UInt32  lut_rd_data_d0_6:16;
    };
}dm_dm_b05_lut_rd_data_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d2_6:16;
        RBus_UInt32  res1:16;
    };
}dm_dm_b05_lut_rd_data_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d1_7:16;
        RBus_UInt32  lut_rd_data_d0_7:16;
    };
}dm_dm_b05_lut_rd_data_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d2_7:16;
        RBus_UInt32  res1:16;
    };
}dm_dm_b05_lut_rd_data_14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d1_8:16;
        RBus_UInt32  lut_rd_data_d0_8:16;
    };
}dm_dm_b05_lut_rd_data_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d2_8:16;
        RBus_UInt32  res1:16;
    };
}dm_dm_b05_lut_rd_data_16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d1_9:16;
        RBus_UInt32  lut_rd_data_d0_9:16;
    };
}dm_dm_b05_lut_rd_data_17_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d2_9:16;
        RBus_UInt32  res1:16;
    };
}dm_dm_b05_lut_rd_data_18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d1_10:16;
        RBus_UInt32  lut_rd_data_d0_10:16;
    };
}dm_dm_b05_lut_rd_data_19_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d2_10:16;
        RBus_UInt32  res1:16;
    };
}dm_dm_b05_lut_rd_data_20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d1_11:16;
        RBus_UInt32  lut_rd_data_d0_11:16;
    };
}dm_dm_b05_lut_rd_data_21_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d2_11:16;
        RBus_UInt32  res1:16;
    };
}dm_dm_b05_lut_rd_data_22_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d1_12:16;
        RBus_UInt32  lut_rd_data_d0_12:16;
    };
}dm_dm_b05_lut_rd_data_23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d2_12:16;
        RBus_UInt32  res1:16;
    };
}dm_dm_b05_lut_rd_data_24_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d1_13:16;
        RBus_UInt32  lut_rd_data_d0_13:16;
    };
}dm_dm_b05_lut_rd_data_25_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d2_13:16;
        RBus_UInt32  res1:16;
    };
}dm_dm_b05_lut_rd_data_26_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d1_14:16;
        RBus_UInt32  lut_rd_data_d0_14:16;
    };
}dm_dm_b05_lut_rd_data_27_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d2_14:16;
        RBus_UInt32  res1:16;
    };
}dm_dm_b05_lut_rd_data_28_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d1_15:16;
        RBus_UInt32  lut_rd_data_d0_15:16;
    };
}dm_dm_b05_lut_rd_data_29_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d2_15:16;
        RBus_UInt32  res1:16;
    };
}dm_dm_b05_lut_rd_data_30_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d1_16:16;
        RBus_UInt32  lut_rd_data_d0_16:16;
    };
}dm_dm_b05_lut_rd_data_31_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d2_16:16;
        RBus_UInt32  res1:16;
    };
}dm_dm_b05_lut_rd_data_32_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d1_17:16;
        RBus_UInt32  lut_rd_data_d0_17:16;
    };
}dm_dm_b05_lut_rd_data_33_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d2_17:16;
        RBus_UInt32  res1:16;
    };
}dm_dm_b05_lut_rd_data_34_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut24_b05_rw_adr:10;
        RBus_UInt32  res1:17;
        RBus_UInt32  lut24_b05_read_en:1;
        RBus_UInt32  lut24_b05_write_en:1;
        RBus_UInt32  lut24_b05_rw_sel:2;
        RBus_UInt32  res2:1;
    };
}dm_dm_b05_lut_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dm_b05_dimension:1;
        RBus_UInt32  dm_b05_input_ctrl:1;
        RBus_UInt32  res1:6;
        RBus_UInt32  lut24_b05_acc_sel:1;
        RBus_UInt32  res2:22;
        RBus_UInt32  lut24_b05_acc_ready:1;
    };
}dm_dm_b05_lut_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut24_b05_hw_lut1_rd_acc:1;
        RBus_UInt32  lut24_b05_fw_lut1_wr_acc:1;
        RBus_UInt32  lut24_b05_fw_lut1_rd_acc:1;
        RBus_UInt32  lut24_b05_hw_lut0_rd_acc:1;
        RBus_UInt32  lut24_b05_fw_lut0_wr_acc:1;
        RBus_UInt32  lut24_b05_fw_lut0_rd_acc:1;
        RBus_UInt32  res1:26;
    };
}dm_dm_b05_lut_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d1_18:16;
        RBus_UInt32  lut_wr_data_d0_18:16;
    };
}dm_dm_b05_lut_wr_data_35_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d2_18:16;
        RBus_UInt32  res1:16;
    };
}dm_dm_b05_lut_wr_data_36_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d1_19:16;
        RBus_UInt32  lut_wr_data_d0_19:16;
    };
}dm_dm_b05_lut_wr_data_37_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d2_19:16;
        RBus_UInt32  res1:16;
    };
}dm_dm_b05_lut_wr_data_38_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d1_20:16;
        RBus_UInt32  lut_wr_data_d0_20:16;
    };
}dm_dm_b05_lut_wr_data_39_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d2_20:16;
        RBus_UInt32  res1:16;
    };
}dm_dm_b05_lut_wr_data_40_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d1_21:16;
        RBus_UInt32  lut_wr_data_d0_21:16;
    };
}dm_dm_b05_lut_wr_data_41_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d2_21:16;
        RBus_UInt32  res1:16;
    };
}dm_dm_b05_lut_wr_data_42_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d1_22:16;
        RBus_UInt32  lut_wr_data_d0_22:16;
    };
}dm_dm_b05_lut_wr_data_43_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d2_22:16;
        RBus_UInt32  res1:16;
    };
}dm_dm_b05_lut_wr_data_44_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d1_23:16;
        RBus_UInt32  lut_wr_data_d0_23:16;
    };
}dm_dm_b05_lut_wr_data_45_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d2_23:16;
        RBus_UInt32  res1:16;
    };
}dm_dm_b05_lut_wr_data_46_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d1_24:16;
        RBus_UInt32  lut_wr_data_d0_24:16;
    };
}dm_dm_b05_lut_wr_data_47_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d2_24:16;
        RBus_UInt32  res1:16;
    };
}dm_dm_b05_lut_wr_data_48_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d1_18:16;
        RBus_UInt32  lut_rd_data_d0_18:16;
    };
}dm_dm_b05_lut_rd_data_35_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d2_18:16;
        RBus_UInt32  res1:16;
    };
}dm_dm_b05_lut_rd_data_36_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d1_19:16;
        RBus_UInt32  lut_rd_data_d0_19:16;
    };
}dm_dm_b05_lut_rd_data_37_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d2_19:16;
        RBus_UInt32  res1:16;
    };
}dm_dm_b05_lut_rd_data_38_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d1_20:16;
        RBus_UInt32  lut_rd_data_d0_20:16;
    };
}dm_dm_b05_lut_rd_data_39_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d2_20:16;
        RBus_UInt32  res1:16;
    };
}dm_dm_b05_lut_rd_data_40_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d1_21:16;
        RBus_UInt32  lut_rd_data_d0_21:16;
    };
}dm_dm_b05_lut_rd_data_41_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d2_21:16;
        RBus_UInt32  res1:16;
    };
}dm_dm_b05_lut_rd_data_42_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d1_22:16;
        RBus_UInt32  lut_rd_data_d0_22:16;
    };
}dm_dm_b05_lut_rd_data_43_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d2_22:16;
        RBus_UInt32  res1:16;
    };
}dm_dm_b05_lut_rd_data_44_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d1_23:16;
        RBus_UInt32  lut_rd_data_d0_23:16;
    };
}dm_dm_b05_lut_rd_data_45_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d2_23:16;
        RBus_UInt32  res1:16;
    };
}dm_dm_b05_lut_rd_data_46_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d1_24:16;
        RBus_UInt32  lut_rd_data_d0_24:16;
    };
}dm_dm_b05_lut_rd_data_47_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d2_24:16;
        RBus_UInt32  res1:16;
    };
}dm_dm_b05_lut_rd_data_48_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dm_db_apply:1;
        RBus_UInt32  dm_db_read_sel:1;
        RBus_UInt32  dm_db_en:1;
        RBus_UInt32  res1:29;
    };
}dm_hdr_dm_double_buffer_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dm_b01_1_drf_bist_fail_0:1;
        RBus_UInt32  dm_b01_1_drf_bist_fail_1:1;
        RBus_UInt32  dm_b01_1_drf_bist_fail_2:1;
        RBus_UInt32  dm_b01_1_drf_bist_fail_3:1;
        RBus_UInt32  dm_b01_1_drf_bist_fail_4:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  dm_b01_1_bist_fail_0:1;
        RBus_UInt32  dm_b01_1_bist_fail_1:1;
        RBus_UInt32  dm_b01_1_bist_fail_2:1;
        RBus_UInt32  dm_b01_1_bist_fail_3:1;
        RBus_UInt32  dm_b01_1_bist_fail_4:1;
        RBus_UInt32  res2:13;
        RBus_UInt32  dm_b01_1_rm:4;
        RBus_UInt32  dm_b01_1_rme:1;
        RBus_UInt32  dm_b01_1_ls:1;
    };
}dm_dm_b01_1_mbist_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dm_b01_2_0_drf_bist_fail_0:1;
        RBus_UInt32  dm_b01_2_0_drf_bist_fail_1:1;
        RBus_UInt32  dm_b01_2_0_drf_bist_fail_2:1;
        RBus_UInt32  dm_b01_2_0_drf_bist_fail_3:1;
        RBus_UInt32  dm_b01_2_0_drf_bist_fail_4:1;
        RBus_UInt32  dm_b01_2_0_drf_bist_fail_5:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  dm_b01_2_0_bist_fail_0:1;
        RBus_UInt32  dm_b01_2_0_bist_fail_1:1;
        RBus_UInt32  dm_b01_2_0_bist_fail_2:1;
        RBus_UInt32  dm_b01_2_0_bist_fail_3:1;
        RBus_UInt32  dm_b01_2_0_bist_fail_4:1;
        RBus_UInt32  dm_b01_2_0_bist_fail_5:1;
        RBus_UInt32  res2:12;
        RBus_UInt32  dm_b01_2_0_rm:4;
        RBus_UInt32  dm_b01_2_0_rme:1;
        RBus_UInt32  dm_b01_2_0_ls:1;
    };
}dm_dm_b01_2_0_mbist_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dm_b01_2_1_drf_bist_fail_0:1;
        RBus_UInt32  dm_b01_2_1_drf_bist_fail_1:1;
        RBus_UInt32  dm_b01_2_1_drf_bist_fail_2:1;
        RBus_UInt32  dm_b01_2_1_drf_bist_fail_3:1;
        RBus_UInt32  dm_b01_2_1_drf_bist_fail_4:1;
        RBus_UInt32  dm_b01_2_1_drf_bist_fail_5:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  dm_b01_2_1_bist_fail_0:1;
        RBus_UInt32  dm_b01_2_1_bist_fail_1:1;
        RBus_UInt32  dm_b01_2_1_bist_fail_2:1;
        RBus_UInt32  dm_b01_2_1_bist_fail_3:1;
        RBus_UInt32  dm_b01_2_1_bist_fail_4:1;
        RBus_UInt32  dm_b01_2_1_bist_fail_5:1;
        RBus_UInt32  res2:12;
        RBus_UInt32  dm_b01_2_1_rm:4;
        RBus_UInt32  dm_b01_2_1_rme:1;
        RBus_UInt32  dm_b01_2_1_ls:1;
    };
}dm_dm_b01_2_1_mbist_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dm_b02_1_drf_bist_fail_0:1;
        RBus_UInt32  dm_b02_1_drf_bist_fail_1:1;
        RBus_UInt32  dm_b02_1_drf_bist_fail_2:1;
        RBus_UInt32  dm_b02_1_drf_bist_fail_3:1;
        RBus_UInt32  dm_b02_1_drf_bist_fail_4:1;
        RBus_UInt32  dm_b02_1_drf_bist_fail_5:1;
        RBus_UInt32  dm_b02_1_drf_bist_fail_6:1;
        RBus_UInt32  dm_b02_1_drf_bist_fail_7:1;
        RBus_UInt32  dm_b02_1_drf_bist_fail_8:1;
        RBus_UInt32  dm_b02_1_drf_bist_fail_9:1;
        RBus_UInt32  dm_b02_1_drf_bist_fail_10:1;
        RBus_UInt32  dm_b02_1_drf_bist_fail_11:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  dm_b02_1_bist_fail_0:1;
        RBus_UInt32  dm_b02_1_bist_fail_1:1;
        RBus_UInt32  dm_b02_1_bist_fail_2:1;
        RBus_UInt32  dm_b02_1_bist_fail_3:1;
        RBus_UInt32  dm_b02_1_bist_fail_4:1;
        RBus_UInt32  dm_b02_1_bist_fail_5:1;
        RBus_UInt32  dm_b02_1_bist_fail_6:1;
        RBus_UInt32  dm_b02_1_bist_fail_7:1;
        RBus_UInt32  dm_b02_1_bist_fail_8:1;
        RBus_UInt32  dm_b02_1_bist_fail_9:1;
        RBus_UInt32  dm_b02_1_bist_fail_10:1;
        RBus_UInt32  dm_b02_1_bist_fail_11:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  dm_b02_1_rm:4;
        RBus_UInt32  dm_b02_1_rme:1;
        RBus_UInt32  dm_b02_1_ls:1;
    };
}dm_dm_b02_1_mbist_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dm_b02_2_drf_bist_fail_0:1;
        RBus_UInt32  res1:7;
        RBus_UInt32  dm_b02_2_bist_fail_0:1;
        RBus_UInt32  res2:17;
        RBus_UInt32  dm_b02_2_rm:4;
        RBus_UInt32  dm_b02_2_rme:1;
        RBus_UInt32  dm_b02_2_ls:1;
    };
}dm_dm_b02_2_mbist_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dm_hist_drf_bist_fail_0:1;
        RBus_UInt32  dm_hist_drf_bist_fail_1:1;
        RBus_UInt32  res1:6;
        RBus_UInt32  dm_hist_bist_fail_0:1;
        RBus_UInt32  dm_hist_bist_fail_1:1;
        RBus_UInt32  res2:6;
        RBus_UInt32  dm_hist_testrwm_1:1;
        RBus_UInt32  dm_hist_testrwm_0:1;
        RBus_UInt32  res3:8;
        RBus_UInt32  dm_hist_rm:4;
        RBus_UInt32  dm_hist_rme:1;
        RBus_UInt32  dm_hist_ls:1;
    };
}dm_dm_hist_mbist_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dm_b03_1_drf_bist_fail_0:1;
        RBus_UInt32  dm_b03_1_drf_bist_fail_1:1;
        RBus_UInt32  dm_b03_1_drf_bist_fail_2:1;
        RBus_UInt32  dm_b03_1_drf_bist_fail_3:1;
        RBus_UInt32  dm_b03_1_drf_bist_fail_4:1;
        RBus_UInt32  dm_b03_1_drf_bist_fail_5:1;
        RBus_UInt32  dm_b03_1_drf_bist_fail_6:1;
        RBus_UInt32  dm_b03_1_drf_bist_fail_7:1;
        RBus_UInt32  dm_b03_1_drf_bist_fail_8:1;
        RBus_UInt32  dm_b03_1_drf_bist_fail_9:1;
        RBus_UInt32  dm_b03_1_drf_bist_fail_10:1;
        RBus_UInt32  dm_b03_1_drf_bist_fail_11:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  dm_b03_1_bist_fail_0:1;
        RBus_UInt32  dm_b03_1_bist_fail_1:1;
        RBus_UInt32  dm_b03_1_bist_fail_2:1;
        RBus_UInt32  dm_b03_1_bist_fail_3:1;
        RBus_UInt32  dm_b03_1_bist_fail_4:1;
        RBus_UInt32  dm_b03_1_bist_fail_5:1;
        RBus_UInt32  dm_b03_1_bist_fail_6:1;
        RBus_UInt32  dm_b03_1_bist_fail_7:1;
        RBus_UInt32  dm_b03_1_bist_fail_8:1;
        RBus_UInt32  dm_b03_1_bist_fail_9:1;
        RBus_UInt32  dm_b03_1_bist_fail_10:1;
        RBus_UInt32  dm_b03_1_bist_fail_11:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  dm_b03_1_rm:4;
        RBus_UInt32  dm_b03_1_rme:1;
        RBus_UInt32  dm_b03_1_ls:1;
    };
}dm_dm_b03_1_mbist_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dm_b03_2_drf_bist_fail_0:1;
        RBus_UInt32  dm_b03_2_drf_bist_fail_1:1;
        RBus_UInt32  dm_b03_2_drf_bist_fail_2:1;
        RBus_UInt32  dm_b03_2_drf_bist_fail_3:1;
        RBus_UInt32  res1:4;
        RBus_UInt32  dm_b03_2_bist_fail_0:1;
        RBus_UInt32  dm_b03_2_bist_fail_1:1;
        RBus_UInt32  dm_b03_2_bist_fail_2:1;
        RBus_UInt32  dm_b03_2_bist_fail_3:1;
        RBus_UInt32  res2:14;
        RBus_UInt32  dm_b03_2_rm:4;
        RBus_UInt32  dm_b03_2_rme:1;
        RBus_UInt32  dm_b03_2_ls:1;
    };
}dm_dm_b03_2_mbist_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dm_b05_drf_bist_fail_0:1;
        RBus_UInt32  dm_b05_drf_bist_fail_1:1;
        RBus_UInt32  dm_b05_drf_bist_fail_2:1;
        RBus_UInt32  dm_b05_drf_bist_fail_3:1;
        RBus_UInt32  dm_b05_drf_bist_fail_4:1;
        RBus_UInt32  dm_b05_drf_bist_fail_5:1;
        RBus_UInt32  dm_b05_drf_bist_fail_6:1;
        RBus_UInt32  dm_b05_drf_bist_fail_7:1;
        RBus_UInt32  dm_b05_bist_fail_0:1;
        RBus_UInt32  dm_b05_bist_fail_1:1;
        RBus_UInt32  dm_b05_bist_fail_2:1;
        RBus_UInt32  dm_b05_bist_fail_3:1;
        RBus_UInt32  dm_b05_bist_fail_4:1;
        RBus_UInt32  dm_b05_bist_fail_5:1;
        RBus_UInt32  dm_b05_bist_fail_6:1;
        RBus_UInt32  dm_b05_bist_fail_7:1;
        RBus_UInt32  res1:10;
        RBus_UInt32  dm_b05_rm:4;
        RBus_UInt32  dm_b05_rme:1;
        RBus_UInt32  dm_b05_ls:1;
    };
}dm_dm_b05_mbist_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  debug_cr:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  debug_cb:14;
        RBus_UInt32  res2:2;
    };
}dm_debug_set0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  debug_y:14;
        RBus_UInt32  res1:18;
    };
}dm_debug_set1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dither_fix_pattern_num:3;
        RBus_UInt32  res1:5;
        RBus_UInt32  dither_fix_pattern_en:1;
        RBus_UInt32  res2:23;
    };
}dm_dither_set_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  b0103_or_eotf:1;
        RBus_UInt32  b0105_or_oetf:1;
        RBus_UInt32  b0107_or_tone:1;
        RBus_UInt32  res1:29;
    };
}dm_hdr_path_sel_RBUS;




#endif 


#endif 
